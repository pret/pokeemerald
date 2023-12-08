#include "global.h"
#include "battle.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "characters.h"
#include "fieldmap.h"
#include "item_menu.h"
#include "main.h"
#include "malloc.h"
#include "random.h"
#include "test/battle.h"
#include "window.h"
#include "constants/trainers.h"

#if defined(__INTELLISENSE__)
#undef TestRunner_Battle_RecordAbilityPopUp
#undef TestRunner_Battle_RecordAnimation
#undef TestRunner_Battle_RecordHP
#undef TestRunner_Battle_RecordMessage
#undef TestRunner_Battle_RecordStatus1
#undef TestRunner_Battle_AfterLastTurn
#undef TestRunner_Battle_CheckBattleRecordActionType
#undef TestRunner_Battle_GetForcedAbility
#endif

#define INVALID(fmt, ...) Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__)
#define INVALID_IF(c, fmt, ...) do { if (c) Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__); } while (0)

#define ASSUMPTION_FAIL_IF(c, fmt, ...) do { if (c) Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__); } while (0)

#define STATE gBattleTestRunnerState
#define DATA gBattleTestRunnerState->data

#define RNG_SEED_DEFAULT 0x00000000

#undef Q_4_12
#define Q_4_12(n) (s32)((n) * 4096)

// Alias sBackupMapData to avoid using heap.
struct BattleTestRunnerState *const gBattleTestRunnerState = (void *)sBackupMapData;
STATIC_ASSERT(sizeof(struct BattleTestRunnerState) <= sizeof(sBackupMapData), sBackupMapDataSpace);

static void CB2_BattleTest_NextParameter(void);
static void CB2_BattleTest_NextTrial(void);
static void PushBattlerAction(u32 sourceLine, s32 battlerId, u32 actionType, u32 byte);
static void PrintAiMoveLog(u32 battlerId, u32 moveSlot, u32 moveId, s32 totalScore);
static void ClearAiLog(u32 battlerId);
static const char *BattlerIdentifier(s32 battlerId);

NAKED static void InvokeSingleTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *player, struct BattlePokemon *opponent, SingleBattleTestFunction function, void *stack)
{
    asm("push {r4-r6,lr}\n\
         ldr r4, [sp, #16] @ function\n\
         ldr r5, [sp, #20] @ stack\n\
         mov r6, sp\n\
         mov sp, r5\n\
         push {r6}\n\
         ldr r6, =SingleRestoreSP + 1\n\
         mov lr, r6\n\
         bx r4\n\
    SingleRestoreSP:\n\
         pop {r0}\n\
         mov sp, r0\n\
         pop {r4-r6}\n\
         pop {r0}\n\
         bx r0\n\
        .pool");
}

NAKED static void InvokeDoubleTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *playerLeft, struct BattlePokemon *opponentLeft, struct BattlePokemon *playerRight, struct BattlePokemon *opponentRight, SingleBattleTestFunction function, void *stack)
{
    asm("push {r4-r7,lr}\n\
         ldr r4, [sp, #28] @ function\n\
         ldr r5, [sp, #32] @ stack\n\
         mov r6, sp\n\
         mov sp, r5\n\
         push {r6}\n\
         add r6, #20\n\
         ldmia r6, {r6, r7} @ playerRight, opponentRight\n\
         push {r6, r7}\n\
         ldr r6, =DoubleRestoreSP + 1\n\
         mov lr, r6\n\
         bx r4\n\
    DoubleRestoreSP:\n\
         add sp, #8\n\
         pop {r0}\n\
         mov sp, r0\n\
         pop {r4-r7}\n\
         pop {r0}\n\
         bx r0\n\
        .pool");
}

// Calls test->function, but pointing its stack at DATA.stack so that
// local variables are live after the function returns (and so can be
// referenced by HP_BAR, or the next call, etc).
// NOTE: This places the stack in EWRAM which has longer waitstates than
// IWRAM so could be much slower, but a) not that much code executes,
// and b) mga-rom-test isn't meaningfully limited by the GBA frame rate.
static void InvokeTestFunction(const struct BattleTest *test)
{
    STATE->parametersCount = 0;
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_AI_SINGLES:
        InvokeSingleTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], test->function.singles, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
        InvokeDoubleTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], &gBattleMons[B_POSITION_PLAYER_RIGHT], &gBattleMons[B_POSITION_OPPONENT_RIGHT], test->function.singles, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    }
}

static const struct BattleTest *GetBattleTest(void)
{
    const struct BattleTest *test = gTestRunnerState.test->data;
    return test;
}

static bool32 IsAITest(void)
{
    switch (GetBattleTest()->type)
    {
    case BATTLE_TEST_AI_SINGLES:
    case BATTLE_TEST_AI_DOUBLES:
        return TRUE;
    }
    return FALSE;
}

static u32 SourceLine(u32 sourceLineOffset)
{
    const struct BattleTest *test = GetBattleTest();
    return test->sourceLine + sourceLineOffset;
}

static u32 SourceLineOffset(u32 sourceLine)
{
    const struct BattleTest *test = GetBattleTest();
    if (sourceLine - test->sourceLine > 0xFF)
        return 0;
    else
        return sourceLine - test->sourceLine;
}

static u32 BattleTest_EstimateCost(void *data)
{
    u32 cost;
    const struct BattleTest *test = data;
    memset(STATE, 0, sizeof(*STATE));
    STATE->runRandomly = TRUE;
    InvokeTestFunction(test);
    cost = 1;
    if (STATE->parametersCount != 0)
        cost *= STATE->parametersCount;
    if (STATE->trials == 1)
        cost *= 3;
    else if (STATE->trials > 1)
        cost *= STATE->trials;
    return cost;
}

static void BattleTest_SetUp(void *data)
{
    const struct BattleTest *test = data;
    memset(STATE, 0, sizeof(*STATE));
    InvokeTestFunction(test);
    STATE->parameters = STATE->parametersCount;
    if (STATE->parametersCount == 0 && test->resultsSize > 0)
        Test_ExitWithResult(TEST_RESULT_INVALID, "results without PARAMETRIZE");
    if (sizeof(*STATE) + test->resultsSize * STATE->parameters > sizeof(sBackupMapData))
        Test_ExitWithResult(TEST_RESULT_ERROR, "OOM: STATE (%d) + STATE->results (%d) too big for sBackupMapData (%d)", sizeof(*STATE), test->resultsSize * STATE->parameters, sizeof(sBackupMapData));
    STATE->results = (void *)((char *)sBackupMapData + sizeof(struct BattleTestRunnerState));
    memset(STATE->results, 0, test->resultsSize * STATE->parameters);
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_AI_SINGLES:
        STATE->battlersCount = 2;
        break;
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
        STATE->battlersCount = 4;
        break;
    }
}

static void PrintTestName(void)
{
    if (STATE->trials && STATE->parameters)
    {
        if (STATE->trials == 1)
            MgbaPrintf_(":N%s %d/%d (%d/?)", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters, STATE->runTrial + 1);
        else
            MgbaPrintf_(":N%s %d/%d (%d/%d)", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters, STATE->runTrial + 1, STATE->trials);
    }
    else if (STATE->trials)
    {
        if (STATE->trials == 1)
            MgbaPrintf_(":N%s (%d/?)", gTestRunnerState.test->name, STATE->runTrial + 1);
        else
            MgbaPrintf_(":N%s (%d/%d)", gTestRunnerState.test->name, STATE->runTrial + 1, STATE->trials);
    }
    else if (STATE->parameters)
    {
        MgbaPrintf_(":N%s %d/%d", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters);
    }
}

// This does not take into account priority, statuses, or any other
// modifiers.
static void SetImplicitSpeeds(void)
{
    s32 i;
    u32 speed = 12;
    u32 hasSpeeds = 0;
    u32 allSpeeds = ((1 << DATA.playerPartySize) - 1) | (((1 << DATA.opponentPartySize) - 1) << 6);
    bool32 madeProgress;
    while (hasSpeeds != allSpeeds)
    {
        madeProgress = FALSE;
        for (i = 0; i < DATA.playerPartySize; i++)
        {
            if (!(hasSpeeds & (1 << i))
             && !(DATA.slowerThan[B_SIDE_PLAYER][i] & ~hasSpeeds))
            {
                SetMonData(&DATA.recordedBattle.playerParty[i], MON_DATA_SPEED, &speed);
                speed--;
                hasSpeeds |= 1 << i;
                madeProgress = TRUE;
            }
        }
        for (i = 0; i < DATA.opponentPartySize; i++)
        {
            if (!(hasSpeeds & ((1 << 6) << i))
             && !(DATA.slowerThan[B_SIDE_OPPONENT][i] & ~hasSpeeds))
            {
                SetMonData(&DATA.recordedBattle.opponentParty[i], MON_DATA_SPEED, &speed);
                speed--;
                hasSpeeds |= (1 << 6) << i;
                madeProgress = TRUE;
            }
        }
        if (!madeProgress)
            Test_ExitWithResult(TEST_RESULT_INVALID, "TURNs have contradictory speeds");
    }
}

static void BattleTest_Run(void *data)
{
    s32 i;
    u32 requiredPlayerPartySize;
    u32 requiredOpponentPartySize;
    const struct BattleTest *test = data;

    memset(&DATA, 0, sizeof(DATA));

    DATA.recordedBattle.rngSeed = RNG_SEED_DEFAULT;
    DATA.recordedBattle.textSpeed = OPTIONS_TEXT_SPEED_FAST;
    // Set battle flags and opponent ids.
    switch (test->type)
    {
    case BATTLE_TEST_WILD:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER;
        break;
    case BATTLE_TEST_AI_SINGLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
        DATA.recordedBattle.opponentA = TRAINER_LEAF;
        DATA.hasAI = TRUE;
        break;
    case BATTLE_TEST_AI_DOUBLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE;
        DATA.recordedBattle.opponentA = TRAINER_LEAF;
        DATA.recordedBattle.opponentB = TRAINER_RED;
        DATA.hasAI = TRUE;
        break;
    case BATTLE_TEST_SINGLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER;
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        break;
    case BATTLE_TEST_DOUBLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE;
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        DATA.recordedBattle.opponentB = TRAINER_LINK_OPPONENT;
        break;
    }

    for (i = 0; i < STATE->battlersCount; i++)
    {
        DATA.recordedBattle.playersName[i][0] = CHAR_1 + i;
        DATA.recordedBattle.playersName[i][1] = EOS;
        DATA.recordedBattle.playersLanguage[i] = GAME_LANGUAGE;
        DATA.recordedBattle.playersBattlers[i] = i;

        DATA.currentMonIndexes[i] = (i & BIT_FLANK) == B_FLANK_LEFT ? 0 : 1;
    }

    STATE->runRandomly = TRUE;
    STATE->runGiven = TRUE;
    STATE->runWhen = TRUE;
    STATE->runScene = TRUE;
    InvokeTestFunction(test);
    STATE->runRandomly = FALSE;
    STATE->runGiven = FALSE;
    STATE->runWhen = FALSE;
    STATE->runScene = FALSE;

    requiredPlayerPartySize = 0;
    requiredOpponentPartySize = 0;
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if ((i & BIT_SIDE) == B_SIDE_PLAYER)
            requiredPlayerPartySize = DATA.currentMonIndexes[i] + 1;
        else
            requiredOpponentPartySize = DATA.currentMonIndexes[i] + 1;
    }
    if (DATA.playerPartySize < requiredPlayerPartySize)
        Test_ExitWithResult(TEST_RESULT_INVALID, "%d PLAYER Pokemon required", requiredPlayerPartySize);
    if (DATA.opponentPartySize < requiredOpponentPartySize)
        Test_ExitWithResult(TEST_RESULT_INVALID, "%d OPPONENT Pokemon required", requiredOpponentPartySize);

    for (i = 0; i < STATE->battlersCount; i++)
        PushBattlerAction(0, i, RECORDED_BYTE, 0xFF);

    if (DATA.hasExplicitSpeeds)
    {
        if (DATA.explicitSpeeds[B_SIDE_PLAYER] != (1 << DATA.playerPartySize) - 1
         && DATA.explicitSpeeds[B_SIDE_OPPONENT] != (1 << DATA.opponentPartySize) - 1)
        {
            Test_ExitWithResult(TEST_RESULT_INVALID, "Speed required for all PLAYERs and OPPONENTs");
        }
    }
    else
    {
        SetImplicitSpeeds();
    }

    SetVariablesForRecordedBattle(&DATA.recordedBattle);
    if (STATE->trials)
        gMain.savedCallback = CB2_BattleTest_NextTrial;
    else if (STATE->parameters)
        gMain.savedCallback = CB2_BattleTest_NextParameter;
    else
        gMain.savedCallback = CB2_TestRunner;
    SetMainCallback2(CB2_InitBattle);

    STATE->checkProgressParameter = 0;
    STATE->checkProgressTrial = 0;
    STATE->checkProgressTurn = 0;

    PrintTestName();
}

u32 RandomUniform(enum RandomTag tag, u32 lo, u32 hi)
{
    const struct BattlerTurn *turn = NULL;

    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        u32 battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
            return turn->rng.value;
    }

    if (tag == STATE->rngTag)
    {
        u32 n = hi - lo + 1;
        if (STATE->trials == 1)
        {
            STATE->trials = n;
            PrintTestName();
        }
        else if (STATE->trials != n)
        {
            Test_ExitWithResult(TEST_RESULT_ERROR, "RandomUniform called with inconsistent trials %d and %d", STATE->trials, n);
        }
        STATE->trialRatio = Q_4_12(1) / STATE->trials;
        return STATE->runTrial + lo;
    }

    return hi;
}

u32 RandomUniformExcept(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32))
{
    const struct BattlerTurn *turn = NULL;
    u32 default_;

    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        u32 battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
        {
            if (reject(turn->rng.value))
                Test_ExitWithResult(TEST_RESULT_INVALID, "WITH_RNG specified a rejected value (%d)", turn->rng.value);
            return turn->rng.value;
        }
    }

    if (tag == STATE->rngTag)
    {
        if (STATE->trials == 1)
        {
            u32 n = 0, i;
            for (i = lo; i < hi; i++)
                if (!reject(i))
                    n++;
            STATE->trials = n;
            PrintTestName();
        }
        STATE->trialRatio = Q_4_12(1) / STATE->trials;

        while (reject(STATE->runTrial + lo + STATE->rngTrialOffset))
        {
            if (STATE->runTrial + lo + STATE->rngTrialOffset > hi)
                Test_ExitWithResult(TEST_RESULT_INVALID, "RandomUniformExcept called with inconsistent reject");
            STATE->rngTrialOffset++;
        }

        return STATE->runTrial + lo + STATE->rngTrialOffset;
    }

    default_ = hi;
    while (reject(default_))
    {
        if (default_ == lo)
            Test_ExitWithResult(TEST_RESULT_INVALID, "RandomUniformExcept rejected all values");
        default_--;
    }
    return default_;
}

u32 RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u8 *weights)
{
    const struct BattlerTurn *turn = NULL;

    if (sum == 0)
        Test_ExitWithResult(TEST_RESULT_ERROR, "RandomWeightedArray called with zero sum");

    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        u32 battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
            return turn->rng.value;
    }

    if (tag == STATE->rngTag)
    {
        if (STATE->trials == 1)
        {
            STATE->trials = n;
            PrintTestName();
        }
        else if (STATE->trials != n)
        {
            Test_ExitWithResult(TEST_RESULT_ERROR, "RandomWeighted called with inconsistent trials %d and %d", STATE->trials, n);
        }
        // TODO: Detect inconsistent sum.
        STATE->trialRatio = Q_4_12(weights[STATE->runTrial]) / sum;
        return STATE->runTrial;
    }

    switch (tag)
    {
    case RNG_ACCURACY:
        ASSUME(n == 2);
        if (turn && turn->hit)
            return turn->hit - 1;
        else
            return TRUE;

    case RNG_CRITICAL_HIT:
        ASSUME(n == 2);
        if (turn && turn->criticalHit)
            return turn->criticalHit - 1;
        else
            return weights[FALSE] > 0 ? FALSE : TRUE;

    case RNG_SECONDARY_EFFECT:
        ASSUME(n == 2);
        if (turn && turn->secondaryEffect)
            return turn->secondaryEffect - 1;
        else
            return TRUE;

    default:
        while (weights[n-1] == 0)
        {
            if (n == 1)
                Test_ExitWithResult(TEST_RESULT_ERROR, "RandomWeightedArray called with all zero weights");
            n--;
        }
        return n-1;
    }
}

const void *RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count)
{
    const struct BattlerTurn *turn = NULL;
    u32 index = count-1;

    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        u32 battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
        {
            u32 element = 0;
            for (index = 0; index < count; index++)
            {
                memcpy(&element, (const u8 *)array + size * index, size);
                if (element == turn->rng.value)
                    return (const u8 *)array + size * index;
            }
            // TODO: Incorporate the line number.
            Test_ExitWithResult(TEST_RESULT_ERROR, "%s: RandomElement illegal value requested: %d", gTestRunnerState.test->filename, turn->rng.value);
        }
    }

    if (tag == STATE->rngTag)
    {
        if (STATE->trials == 1)
        {
            STATE->trials = count;
            PrintTestName();
        }
        else if (STATE->trials != count)
        {
            Test_ExitWithResult(TEST_RESULT_ERROR, "RandomElement called with inconsistent trials %d and %d", STATE->trials, count);
        }
        STATE->trialRatio = Q_4_12(1) / count;
        return (const u8 *)array + size * STATE->runTrial;
    }
    return (const u8 *)array + size * index;
}

static s32 TryAbilityPopUp(s32 i, s32 n, u32 battlerId, u32 ability)
{
    struct QueuedAbilityEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_ABILITY_POPUP_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.ability;

        if (event->battlerId == battlerId
         && (event->ability == ABILITY_NONE || event->ability == ability))
            return i;
    }
    return -1;
}

void TestRunner_Battle_RecordAbilityPopUp(u32 battlerId, u32 ability)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryAbilityPopUp(DATA.queuedEvent, event->groupSize, battlerId, ability) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryAbilityPopUp(queuedEvent, event->groupSize, battlerId, ability)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched ABILITY_POPUP", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryAbilityPopUp(queuedEvent, event->groupSize, battlerId, ability) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryAnimation(s32 i, s32 n, u32 animType, u32 animId)
{
    struct QueuedAnimationEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_ANIMATION_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.animation;

        if (event->type == animType
         && event->id == animId
         && (event->attacker == 0xF || event->attacker == gBattleAnimAttacker)
         && (event->target == 0xF || event->target == gBattleAnimTarget))
            return i;
    }
    return -1;
}

void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryAnimation(DATA.queuedEvent, event->groupSize, animType, animId) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryAnimation(queuedEvent, event->groupSize, animType, animId)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched ANIMATION", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryAnimation(queuedEvent, event->groupSize, animType, animId) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryHP(s32 i, s32 n, u32 battlerId, u32 oldHP, u32 newHP)
{
    struct QueuedHPEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_HP_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.hp;

        if (event->battlerId == battlerId)
        {
            if (event->address <= 0xFFFF)
            {
                switch (event->type)
                {
                case HP_EVENT_NEW_HP:
                    if (event->address == newHP)
                        return i;
                    break;
                case HP_EVENT_DELTA_HP:
                    if (event->address == 0)
                        return i;
                    else if ((s16)event->address == oldHP - newHP)
                        return i;
                    break;
                }
            }
            else
            {
                switch (event->type)
                {
                case HP_EVENT_NEW_HP:
                    *(u16 *)(u32)(event->address) = newHP;
                    break;
                case HP_EVENT_DELTA_HP:
                    *(s16 *)(u32)(event->address) = oldHP - newHP;
                    break;
                }
                return i;
            }
        }
    }
    return -1;
}

void TestRunner_Battle_RecordHP(u32 battlerId, u32 oldHP, u32 newHP)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryHP(DATA.queuedEvent, event->groupSize, battlerId, oldHP, newHP) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryHP(queuedEvent, event->groupSize, battlerId, oldHP, newHP)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched HP_BAR", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryHP(queuedEvent, event->groupSize, battlerId, oldHP, newHP) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static const char *const sBattleActionNames[] =
{
    [B_ACTION_USE_MOVE] = "MOVE",
    [B_ACTION_USE_ITEM] = "USE_ITEM",
    [B_ACTION_SWITCH] = "SWITCH",
};

static u32 CountAiExpectMoves(struct ExpectedAIAction *expectedAction, u32 battlerId, bool32 printLog)
{
    u32 i, countExpected = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & expectedAction->moveSlots)
        {
            if (printLog)
                PrintAiMoveLog(battlerId, i, gBattleMons[battlerId].moves[i], gBattleStruct->aiFinalScore[battlerId][expectedAction->target][i]);
            countExpected++;
        }
    }
    return countExpected;
}

void TestRunner_Battle_CheckChosenMove(u32 battlerId, u32 moveId, u32 target)
{
    const char *filename = gTestRunnerState.test->filename;
    u32 id = DATA.aiActionsPlayed[battlerId];
    struct ExpectedAIAction *expectedAction = &DATA.expectedAiActions[battlerId][id];

    if (!expectedAction->actionSet)
        return;

    if (!expectedAction->pass)
    {
        u32 i, expectedMoveId = 0, countExpected;
        bool32 movePasses = FALSE;

        if (expectedAction->type != B_ACTION_USE_MOVE)
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Expected MOVE, got %s", filename, expectedAction->sourceLine, sBattleActionNames[expectedAction->type]);

        if (expectedAction->explicitTarget && expectedAction->target != target)
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Expected target %s, got %s", filename, expectedAction->sourceLine, BattlerIdentifier(expectedAction->target), BattlerIdentifier(target));

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBitTable[i] & expectedAction->moveSlots)
            {
                expectedMoveId = gBattleMons[battlerId].moves[i];
                if (!expectedAction->notMove)
                {
                    if (moveId == expectedMoveId)
                    {
                        movePasses = TRUE;
                        break;
                    }
                }
                else
                {
                    if (moveId == expectedMoveId)
                    {
                        movePasses = FALSE;
                        break;
                    }
                    movePasses = TRUE;
                }
            }
        }

        countExpected = CountAiExpectMoves(expectedAction, battlerId, TRUE);

        if (!expectedAction->notMove && !movePasses)
        {
            u32 moveSlot = GetMoveSlot(gBattleMons[battlerId].moves, moveId);
            PrintAiMoveLog(battlerId, moveSlot, moveId, gBattleStruct->aiFinalScore[battlerId][expectedAction->target][moveSlot]);
            if (countExpected > 1)
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched EXPECT_MOVES %S, got %S", filename, expectedAction->sourceLine, gMoveNames[expectedMoveId], gMoveNames[moveId]);
            else
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched EXPECT_MOVE %S, got %S", filename, expectedAction->sourceLine, gMoveNames[expectedMoveId], gMoveNames[moveId]);
        }
        if (expectedAction->notMove && !movePasses)
        {
            if (countExpected > 1)
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched NOT_EXPECT_MOVES %S", filename, expectedAction->sourceLine, gMoveNames[expectedMoveId]);
            else
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched NOT_EXPECT_MOVE %S", filename, expectedAction->sourceLine, gMoveNames[expectedMoveId]);
        }
    }
    // Turn passed, clear logs from the turn
    ClearAiLog(battlerId);
    DATA.aiActionsPlayed[battlerId]++;
}

void TestRunner_Battle_CheckSwitch(u32 battlerId, u32 partyIndex)
{
    const char *filename = gTestRunnerState.test->filename;
    u32 id = DATA.aiActionsPlayed[battlerId];
    struct ExpectedAIAction *expectedAction = &DATA.expectedAiActions[battlerId][id];

    if (!expectedAction->actionSet)
        return;

    if (!expectedAction->pass)
    {
        if (expectedAction->type != B_ACTION_SWITCH)
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Expected SWITCH/SEND_OUT, got %s", filename, expectedAction->sourceLine, sBattleActionNames[expectedAction->type]);

        if (expectedAction->target != partyIndex)
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Expected partyIndex %d, got %d", filename, expectedAction->sourceLine, expectedAction->target, partyIndex);
    }
    DATA.aiActionsPlayed[battlerId]++;
}

static bool32 CheckComparision(s32 val1, s32 val2, u32 cmp)
{
    switch (cmp)
    {
    case CMP_EQUAL:
        return (val1 == val2);
    case CMP_NOT_EQUAL:
        return (val1 != val2);
    case CMP_GREATER_THAN:
        return (val1 > val2);
    case CMP_LESS_THAN:
        return (val1 < val2);
    }
    return FALSE;
}

static const char *const sCmpToStringTable[] =
{
    [CMP_EQUAL] = "EQ",
    [CMP_NOT_EQUAL] = "NE",
    [CMP_LESS_THAN] = "LT",
    [CMP_GREATER_THAN] = "GT",
};

static void CheckIfMaxScoreEqualExpectMove(u32 battlerId, s32 target, struct ExpectedAIAction *aiAction, const char *filename)
{
    u32 i;
    s32 *scores = gBattleStruct->aiFinalScore[battlerId][target];
    s32 bestScore = 0, bestScoreId = 0;
    u16 *moves = gBattleMons[battlerId].moves;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (scores[i] > bestScore)
        {
            bestScore = scores[i];
            bestScoreId = i;
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        // We expect move 'i', but it has the same best score as another move that we didn't expect.
        if (scores[i] == scores[bestScoreId]
            && !aiAction->notMove
            && (aiAction->moveSlots & gBitTable[i])
            && !(aiAction->moveSlots & gBitTable[bestScoreId]))
        {
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: EXPECT_MOVE %S has the same best score(%d) as not expected MOVE %S", filename,
                                aiAction->sourceLine, gMoveNames[moves[i]], scores[i], gMoveNames[moves[bestScoreId]]);
        }
        // We DO NOT expect move 'i', but it has the same best score as another move.
        if (scores[i] == scores[bestScoreId]
            && aiAction->notMove
            && (aiAction->moveSlots & gBitTable[i])
            && !(aiAction->moveSlots & gBitTable[bestScoreId]))
        {
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: NOT_EXPECT_MOVE %S has the same best score(%d) as MOVE %S", filename,
                                aiAction->sourceLine, gMoveNames[moves[i]], scores[i], gMoveNames[moves[bestScoreId]]);
        }
    }
}

static void PrintAiMoveLog(u32 battlerId, u32 moveSlot, u32 moveId, s32 totalScore)
{
    s32 i, scoreFromLogs = 0;

    if (!DATA.logAI) return;
    if (DATA.aiLogPrintedForMove[battlerId] & gBitTable[moveSlot]) return;

    DATA.aiLogPrintedForMove[battlerId] |= gBitTable[moveSlot];
    MgbaPrintf_("Score Log for move %S:\n", gMoveNames[moveId]);
    for (i = 0; i < MAX_AI_LOG_LINES; i++)
    {
        struct AILogLine *log = &DATA.aiLogLines[battlerId][moveSlot][i];
        if (log->file)
        {
            if (log->set)
            {
                scoreFromLogs = log->score;
                MgbaPrintf_("%s:%d: = %d\n", log->file, log->line, log->score);
            }
            else if (log->score > 0)
            {
                scoreFromLogs += log->score;
                MgbaPrintf_("%s:%d: +%d\n", log->file, log->line, log->score);
            }
            else
            {
                scoreFromLogs += log->score;
                MgbaPrintf_("%s:%d: %d\n", log->file, log->line, log->score);
            }
        }
        else
        {
            break;
        }
    }
    if (scoreFromLogs != totalScore)
    {
        Test_ExitWithResult(TEST_RESULT_ERROR, "Warning! Score from logs(%d) is different than actual score(%d). Make sure all of the score adjustments use the ADJUST_SCORE macro\n", scoreFromLogs, totalScore);
    }
    MgbaPrintf_("Total: %d\n", totalScore);
}

static void ClearAiLog(u32 battlerId)
{
    u32 i, j;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct AILogLine *logs = DATA.aiLogLines[battlerId][i];
        for (j = 0; j < MAX_AI_LOG_LINES; j++)
            memset(&logs[j], 0, sizeof(struct AILogLine));
    }
    DATA.aiLogPrintedForMove[battlerId] = 0;
}

void TestRunner_Battle_CheckAiMoveScores(u32 battlerId)
{
    s32 i;
    struct ExpectedAIAction *aiAction;
    const char *filename = gTestRunnerState.test->filename;
    s32 turn = gBattleResults.battleTurnCounter;

    for (i = 0; i < MAX_AI_SCORE_COMPARISION_PER_TURN; i++)
    {
        struct ExpectedAiScore *scoreCtx = &DATA.expectedAiScores[battlerId][turn][i];
        if (scoreCtx->set)
        {
            u32 moveId1 = gBattleMons[battlerId].moves[scoreCtx->moveSlot1];
            s32 target = scoreCtx->target;
            s32 *scores = gBattleStruct->aiFinalScore[battlerId][target];

            if (scoreCtx->toValue)
            {
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot1, moveId1, scores[scoreCtx->moveSlot1]);
                if (!CheckComparision(scores[scoreCtx->moveSlot1], scoreCtx->value, scoreCtx->cmp))
                {
                    Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched SCORE_%s_VAL %S %d, got %d",
                                        filename, scoreCtx->sourceLine, sCmpToStringTable[scoreCtx->cmp], gMoveNames[moveId1], scoreCtx->value, scores[scoreCtx->moveSlot1]);
                }
            }
            else
            {
                u32 moveId2 = gBattleMons[battlerId].moves[scoreCtx->moveSlot2];
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot1, moveId1, scores[scoreCtx->moveSlot1]);
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot2, moveId2, scores[scoreCtx->moveSlot2]);
                if (!CheckComparision(scores[scoreCtx->moveSlot1], scores[scoreCtx->moveSlot2], scoreCtx->cmp))
                {
                    Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched SCORE_%s, got %S: %d, %S: %d",
                                        filename, scoreCtx->sourceLine, sCmpToStringTable[scoreCtx->cmp], gMoveNames[moveId1], scores[scoreCtx->moveSlot1], gMoveNames[moveId2], scores[scoreCtx->moveSlot2]);
                }
            }
        }
    }

    // We need to make sure that the expected move has the best score. We have to rule out a situation where the expected move is used, but it has the same number of points as some other moves.
    aiAction = &DATA.expectedAiActions[battlerId][DATA.aiActionsPlayed[battlerId]];
    if (aiAction->actionSet && !aiAction->pass)
    {
        s32 target = aiAction->target;
        // AI's move targets self, but points for this move are distributed for all other battlers
        if (aiAction->target == battlerId)
        {
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                if (i != battlerId && IsBattlerAlive(i))
                    CheckIfMaxScoreEqualExpectMove(battlerId, i, aiAction, filename);
            }
        }
        else
        {
            CheckIfMaxScoreEqualExpectMove(battlerId, target, aiAction, filename);
        }
    }
}

static s32 TryExp(s32 i, s32 n, u32 battlerId, u32 oldExp, u32 newExp)
{
    struct QueuedExpEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_EXP_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.exp;

        if (event->battlerId == battlerId)
        {
            if (event->address <= 0xFFFF)
            {
                switch (event->type)
                {
                case EXP_EVENT_NEW_EXP:
                    if (event->address == newExp)
                        return i;
                    break;
                case EXP_EVENT_DELTA_EXP:
                    if (event->address == 0)
                        return i;
                    else if ((s16)event->address == oldExp - newExp)
                        return i;
                    break;
                }
            }
            else
            {
                switch (event->type)
                {
                case EXP_EVENT_NEW_EXP:
                    *(u32 *)(u32)(event->address) = newExp;
                    break;
                case EXP_EVENT_DELTA_EXP:
                    *(s32 *)(u32)(event->address) = oldExp - newExp;
                    break;
                }
                return i;
            }
        }
    }
    return -1;
}

void TestRunner_Battle_RecordExp(u32 battlerId, u32 oldExp, u32 newExp)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryExp(DATA.queuedEvent, event->groupSize, battlerId, oldExp, newExp) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryExp(queuedEvent, event->groupSize, battlerId, oldExp, newExp)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched EXPERIENCE_BAR", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryExp(queuedEvent, event->groupSize, battlerId, oldExp, newExp) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryMessage(s32 i, s32 n, const u8 *string)
{
    s32 j, k;
    struct QueuedMessageEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_MESSAGE_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.message;
        // MgbaPrintf_("Looking for: %S Found: %S\n", event->pattern, string); // Useful for debugging.
        for (j = k = 0; ; j++, k++)
        {
            if (event->pattern[k] == CHAR_SPACE)
            {
                switch (string[j])
                {
                case CHAR_SPACE:
                case CHAR_PROMPT_SCROLL:
                case CHAR_PROMPT_CLEAR:
                case CHAR_NEWLINE:
                    j++;
                    k++;
                    break;
                }
            }
            if (event->pattern[k] == EOS)
            {
                // Consume any trailing '\p'.
                if (string[j] == CHAR_PROMPT_CLEAR)
                    j++;
            }
            if (string[j] != event->pattern[k])
            {
                break;
            }
            else if (string[j] == EOS)
            {
                return i;
            }
        }
    }
    return -1;
}

void TestRunner_Battle_RecordMessage(const u8 *string)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryMessage(DATA.queuedEvent, event->groupSize, string) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryMessage(queuedEvent, event->groupSize, string)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched MESSAGE", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryMessage(queuedEvent, event->groupSize, string) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryStatus(s32 i, s32 n, u32 battlerId, u32 status1)
{
    struct QueuedStatusEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_STATUS_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.status;

        if (event->battlerId == battlerId)
        {
            if (event->mask == 0 && status1 == STATUS1_NONE)
                return i;
            else if (event->mask & status1)
                return i;
        }
    }
    return -1;
}

void TestRunner_Battle_RecordStatus1(u32 battlerId, u32 status1)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryStatus(DATA.queuedEvent, event->groupSize, battlerId, status1) != -1)
            DATA.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.queuedEvent;
        do
        {
            if ((match = TryStatus(queuedEvent, event->groupSize, battlerId, status1)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Matched STATUS_ICON", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryStatus(queuedEvent, event->groupSize, battlerId, status1) != -1)
                DATA.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static const char *const sEventTypeMacros[] =
{
    [QUEUED_ABILITY_POPUP_EVENT] = "ABILITY_POPUP",
    [QUEUED_ANIMATION_EVENT] = "ANIMATION",
    [QUEUED_HP_EVENT] = "HP_BAR",
    [QUEUED_EXP_EVENT] = "EXPERIENCE_BAR",
    [QUEUED_MESSAGE_EVENT] = "MESSAGE",
    [QUEUED_STATUS_EVENT] = "STATUS_ICON",
};

void TestRunner_Battle_AfterLastTurn(void)
{
    const struct BattleTest *test = GetBattleTest();

    if (DATA.turns - 1 != DATA.lastActionTurn)
    {
        const char *filename = gTestRunnerState.test->filename;
        Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: %d TURNs specified, but %d ran", filename, SourceLine(0), DATA.turns, DATA.lastActionTurn + 1);
    }

    while (DATA.queuedEvent < DATA.queuedEventsCount
        && DATA.queuedEvents[DATA.queuedEvent].groupType == QUEUE_GROUP_NONE_OF)
    {
        DATA.queuedEvent += DATA.queuedEvents[DATA.queuedEvent].groupSize;
    }
    if (DATA.queuedEvent != DATA.queuedEventsCount)
    {
        const char *filename = gTestRunnerState.test->filename;
        u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEvent].sourceLineOffset);
        const char *macro = sEventTypeMacros[DATA.queuedEvents[DATA.queuedEvent].type];
        Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: Unmatched %s", filename, line, macro);
    }

    STATE->runThen = TRUE;
    STATE->runFinally = STATE->runParameter + 1 == STATE->parameters;
    InvokeTestFunction(test);
    STATE->runThen = FALSE;
    STATE->runFinally = FALSE;
}

static void TearDownBattle(void)
{
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
    FreeAllWindowBuffers();
}

static void CB2_BattleTest_NextParameter(void)
{
    if (++STATE->runParameter >= STATE->parameters)
    {
        SetMainCallback2(CB2_TestRunner);
    }
    else
    {
        STATE->trials = 0;
        BattleTest_Run(gTestRunnerState.test->data);
    }
}

static void CB2_BattleTest_NextTrial(void)
{
    TearDownBattle();

    SetMainCallback2(CB2_BattleTest_NextParameter);

    switch (gTestRunnerState.result)
    {
    case TEST_RESULT_FAIL:
        break;
    case TEST_RESULT_PASS:
        STATE->observedRatio += STATE->trialRatio;
        break;
    default:
        return;
    }
    if (STATE->rngTag)
        STATE->trialRatio = 0;

    if (++STATE->runTrial < STATE->trials)
    {
        PrintTestName();
        gTestRunnerState.result = TEST_RESULT_PASS;
        DATA.recordedBattle.rngSeed = ISO_RANDOMIZE1(STATE->runTrial);
        DATA.queuedEvent = 0;
        DATA.lastActionTurn = 0;
        SetVariablesForRecordedBattle(&DATA.recordedBattle);
        SetMainCallback2(CB2_InitBattle);
    }
    else
    {
        // This is a tolerance of +/- ~2%.
        if (abs(STATE->observedRatio - STATE->expectedRatio) <= Q_4_12(0.02))
            gTestRunnerState.result = TEST_RESULT_PASS;
        else
            Test_ExitWithResult(TEST_RESULT_FAIL, "Expected %q passes/successes, observed %q", STATE->expectedRatio, STATE->observedRatio);
    }
}

static void BattleTest_TearDown(void *data)
{
    // Free resources that aren't cleaned up when the battle was
    // aborted unexpectedly.
    if (STATE->tearDownBattle)
        TearDownBattle();
}

static bool32 BattleTest_CheckProgress(void *data)
{
    bool32 madeProgress
         = STATE->checkProgressParameter < STATE->runParameter
        || STATE->checkProgressTrial < STATE->runTrial
        || STATE->checkProgressTurn < gBattleResults.battleTurnCounter;
    STATE->checkProgressParameter = STATE->runParameter;
    STATE->checkProgressTrial = STATE->runTrial;
    STATE->checkProgressTurn = gBattleResults.battleTurnCounter;
    return madeProgress;
}

static bool32 BattleTest_HandleExitWithResult(void *data, enum TestResult result)
{
    if (result != TEST_RESULT_ASSUMPTION_FAIL
     && result != TEST_RESULT_INVALID
     && result != TEST_RESULT_ERROR
     && result != TEST_RESULT_TIMEOUT
     && STATE->runTrial < STATE->trials)
    {
        SetMainCallback2(CB2_BattleTest_NextTrial);
        return TRUE;
    }
    else
    {
        STATE->tearDownBattle = TRUE;
        return FALSE;
    }
}

void Randomly(u32 sourceLine, u32 passes, u32 trials, struct RandomlyContext ctx)
{
    const struct BattleTest *test = GetBattleTest();
    INVALID_IF(STATE->trials != 0, "PASSES_RANDOMLY can only be used once per test");
    INVALID_IF(test->resultsSize > 0, "PASSES_RANDOMLY is incompatible with results");
    INVALID_IF(passes > trials, "%d passes specified, but only %d trials", passes, trials);
    STATE->rngTag = ctx.tag;
    STATE->rngTrialOffset = 0;
    STATE->runTrial = 0;
    STATE->expectedRatio = Q_4_12(passes) / trials;
    STATE->observedRatio = 0;
    if (STATE->rngTag)
    {
        STATE->trials = 1;
        STATE->trialRatio = Q_4_12(1);
    }
    else
    {
        INVALID_IF(DATA.recordedBattle.rngSeed != RNG_SEED_DEFAULT, "RNG seed already set");
        STATE->trials = 50;
        STATE->trialRatio = Q_4_12(1) / STATE->trials;
        DATA.recordedBattle.rngSeed = 0;
    }
}

void RNGSeed_(u32 sourceLine, u32 seed)
{
    INVALID_IF(DATA.recordedBattle.rngSeed != RNG_SEED_DEFAULT, "RNG seed already set");
    DATA.recordedBattle.rngSeed = seed;
}

void AIFlags_(u32 sourceLine, u32 flags)
{
    INVALID_IF(!IsAITest(), "AI_FLAGS is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST");
    DATA.recordedBattle.AI_scripts = flags;
    DATA.hasAI = TRUE;
}

void AILogScores(u32 sourceLine)
{
    INVALID_IF(!IsAITest(), "AI_LOG is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST");
    DATA.logAI = TRUE;
}

const struct TestRunner gBattleTestRunner =
{
    .estimateCost = BattleTest_EstimateCost,
    .setUp = BattleTest_SetUp,
    .run = BattleTest_Run,
    .tearDown = BattleTest_TearDown,
    .checkProgress = BattleTest_CheckProgress,
    .handleExitWithResult = BattleTest_HandleExitWithResult,
};

void OpenPokemon(u32 sourceLine, u32 side, u32 species)
{
    s32 i, data;
    u8 *partySize;
    struct Pokemon *party;
    INVALID_IF(species >= SPECIES_EGG, "Invalid species: %d", species);
    ASSUMPTION_FAIL_IF(!IsSpeciesEnabled(species), "Species disabled: %d", species);
    if (side == B_SIDE_PLAYER)
    {
        partySize = &DATA.playerPartySize;
        party = DATA.recordedBattle.playerParty;
    }
    else
    {
        partySize = &DATA.opponentPartySize;
        party = DATA.recordedBattle.opponentParty;
    }
    INVALID_IF(*partySize >= PARTY_SIZE, "Too many Pokemon in party");
    DATA.currentSide = side;
    DATA.currentPartyIndex = *partySize;
    DATA.currentMon = &party[DATA.currentPartyIndex];
    DATA.gender = MON_MALE;
    DATA.nature = NATURE_HARDY;
    (*partySize)++;

    CreateMon(DATA.currentMon, species, 100, 0, TRUE, 0, OT_ID_PRESET, 0);
    data = MOVE_NONE;
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonData(DATA.currentMon, MON_DATA_MOVE1 + i, &data);
}

// (sNaturePersonalities[i] % NUM_NATURES) == i
// (sNaturePersonalities[i] & 0xFF) == 0
// NOTE: Using 25 << 8 rather than 0 << 8 to prevent shiny females.
static const u16 sNaturePersonalities[NUM_NATURES] =
{
    25 << 8, 21 << 8, 17 << 8, 13 << 8,  9 << 8,
     5 << 8,  1 << 8, 22 << 8, 18 << 8, 14 << 8,
    10 << 8,  6 << 8,  2 << 8, 23 << 8, 19 << 8,
    15 << 8, 11 << 8,  7 << 8,  3 << 8, 24 << 8,
    20 << 8, 16 << 8, 12 << 8,  8 << 8,  4 << 8,
};

static u32 GenerateNature(u32 nature, u32 offset)
{
    if (offset <= nature)
        nature -= offset;
    else
        nature = nature + NUM_NATURES - offset;
    return sNaturePersonalities[nature];
}

void ClosePokemon(u32 sourceLine)
{
    s32 i;
    INVALID_IF(DATA.hasExplicitSpeeds && !(DATA.explicitSpeeds[DATA.currentSide] & (1 << DATA.currentPartyIndex)), "Speed required");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if ((i & BIT_SIDE) == DATA.currentSide
         && DATA.currentMonIndexes[i] == DATA.currentPartyIndex)
        {
            INVALID_IF(GetMonData(DATA.currentMon, MON_DATA_HP) == 0, "Battlers cannot be fainted");
        }
    }
    UpdateMonPersonality(&DATA.currentMon->box, GenerateNature(DATA.nature, DATA.gender % NUM_NATURES) | DATA.gender);
    DATA.currentMon = NULL;
}

void Gender_(u32 sourceLine, u32 gender)
{
    const struct SpeciesInfo *info;
    INVALID_IF(!DATA.currentMon, "Gender outside of PLAYER/OPPONENT");
    info = &gSpeciesInfo[GetMonData(DATA.currentMon, MON_DATA_SPECIES)];
    switch (gender)
    {
    case MON_MALE:
        DATA.gender = 0xFF;
        INVALID_IF(info->genderRatio == MON_GENDERLESS || info->genderRatio == MON_FEMALE, "Illegal male");
        break;
    case MON_FEMALE:
        DATA.gender = 0x00;
        INVALID_IF(info->genderRatio == MON_GENDERLESS || info->genderRatio == MON_MALE, "Illegal female");
        break;
    case MON_GENDERLESS:
        INVALID_IF(info->genderRatio != gender, "Illegal genderless");
        break;
    }
}

void Nature_(u32 sourceLine, u32 nature)
{
    INVALID_IF(!DATA.currentMon, "Nature outside of PLAYER/OPPONENT");
    INVALID_IF(nature >= NUM_NATURES, "Illegal nature: %d", nature);
    DATA.nature = nature;
}

void Ability_(u32 sourceLine, u32 ability)
{
    s32 i;
    u32 species;
    const struct SpeciesInfo *info;
    INVALID_IF(!DATA.currentMon, "Ability outside of PLAYER/OPPONENT");
    species = GetMonData(DATA.currentMon, MON_DATA_SPECIES);
    info = &gSpeciesInfo[species];
    for (i = 0; i < NUM_ABILITY_SLOTS; i++)
    {
        if (info->abilities[i] == ability)
        {
            SetMonData(DATA.currentMon, MON_DATA_ABILITY_NUM, &i);
            break;
        }
    }
    // Store forced ability to be set when the battle starts if invalid.
    if (i == NUM_ABILITY_SLOTS)
    {
        DATA.forcedAbilities[DATA.currentSide][DATA.currentPartyIndex] = ability;
    }
}

void Level_(u32 sourceLine, u32 level)
{
    // TODO: Preserve any explicitly-set stats.
    u32 species = GetMonData(DATA.currentMon, MON_DATA_SPECIES);
    INVALID_IF(!DATA.currentMon, "Level outside of PLAYER/OPPONENT");
    INVALID_IF(level == 0 || level > MAX_LEVEL, "Illegal level: %d", level);
    SetMonData(DATA.currentMon, MON_DATA_LEVEL, &level);
    SetMonData(DATA.currentMon, MON_DATA_EXP, &gExperienceTables[gSpeciesInfo[species].growthRate][level]);
    CalculateMonStats(DATA.currentMon);
}

void MaxHP_(u32 sourceLine, u32 maxHP)
{
    INVALID_IF(!DATA.currentMon, "MaxHP outside of PLAYER/OPPONENT");
    INVALID_IF(maxHP == 0, "Illegal max HP: %d", maxHP);
    SetMonData(DATA.currentMon, MON_DATA_MAX_HP, &maxHP);
}

void HP_(u32 sourceLine, u32 hp)
{
    INVALID_IF(!DATA.currentMon, "HP outside of PLAYER/OPPONENT");
    if (hp > GetMonData(DATA.currentMon, MON_DATA_MAX_HP))
        SetMonData(DATA.currentMon, MON_DATA_MAX_HP, &hp);
    SetMonData(DATA.currentMon, MON_DATA_HP, &hp);
}

void Attack_(u32 sourceLine, u32 attack)
{
    INVALID_IF(!DATA.currentMon, "Attack outside of PLAYER/OPPONENT");
    INVALID_IF(attack == 0, "Illegal attack: %d", attack);
    SetMonData(DATA.currentMon, MON_DATA_ATK, &attack);
}

void Defense_(u32 sourceLine, u32 defense)
{
    INVALID_IF(!DATA.currentMon, "Defense outside of PLAYER/OPPONENT");
    INVALID_IF(defense == 0, "Illegal defense: %d", defense);
    SetMonData(DATA.currentMon, MON_DATA_DEF, &defense);
}

void SpAttack_(u32 sourceLine, u32 spAttack)
{
    INVALID_IF(!DATA.currentMon, "SpAttack outside of PLAYER/OPPONENT");
    INVALID_IF(spAttack == 0, "Illegal special attack: %d", spAttack);
    SetMonData(DATA.currentMon, MON_DATA_SPATK, &spAttack);
}

void SpDefense_(u32 sourceLine, u32 spDefense)
{
    INVALID_IF(!DATA.currentMon, "SpDefense outside of PLAYER/OPPONENT");
    INVALID_IF(spDefense == 0, "Illegal special defense: %d", spDefense);
    SetMonData(DATA.currentMon, MON_DATA_SPDEF, &spDefense);
}

void Speed_(u32 sourceLine, u32 speed)
{
    INVALID_IF(!DATA.currentMon, "Speed outside of PLAYER/OPPONENT");
    INVALID_IF(speed == 0, "Illegal speed: %d", speed);
    SetMonData(DATA.currentMon, MON_DATA_SPEED, &speed);
    DATA.hasExplicitSpeeds = TRUE;
    DATA.explicitSpeeds[DATA.currentSide] |= 1 << DATA.currentPartyIndex;
}

void Item_(u32 sourceLine, u32 item)
{
    INVALID_IF(!DATA.currentMon, "Item outside of PLAYER/OPPONENT");
    INVALID_IF(item >= ITEMS_COUNT, "Illegal item: %d", item);
    SetMonData(DATA.currentMon, MON_DATA_HELD_ITEM, &item);
}

void Moves_(u32 sourceLine, u16 moves[MAX_MON_MOVES])
{
    s32 i;
    INVALID_IF(!DATA.currentMon, "Moves outside of PLAYER/OPPONENT");
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == MOVE_NONE)
            break;
        INVALID_IF(moves[i] >= MOVES_COUNT, "Illegal move: %d", moves[i]);
        SetMonData(DATA.currentMon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(DATA.currentMon, MON_DATA_PP1 + i, &gBattleMoves[moves[i]].pp);
    }
    DATA.explicitMoves[DATA.currentSide] |= 1 << DATA.currentPartyIndex;
}

void MovesWithPP_(u32 sourceLine, struct moveWithPP moveWithPP[MAX_MON_MOVES])
{
    s32 i;
    INVALID_IF(!DATA.currentMon, "Moves outside of PLAYER/OPPONENT");
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moveWithPP[i].moveId == MOVE_NONE)
            break;
        INVALID_IF(moveWithPP[i].moveId >= MOVES_COUNT, "Illegal move: %d", &moveWithPP[i].moveId);
        SetMonData(DATA.currentMon, MON_DATA_MOVE1 + i, &moveWithPP[i].moveId);
        SetMonData(DATA.currentMon, MON_DATA_PP1 + i, &moveWithPP[i].pp);
    }
    DATA.explicitMoves[DATA.currentSide] |= 1 << DATA.currentPartyIndex;
}

void Friendship_(u32 sourceLine, u32 friendship)
{
    INVALID_IF(!DATA.currentMon, "Friendship outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_FRIENDSHIP, &friendship);
}

void Status1_(u32 sourceLine, u32 status1)
{
    INVALID_IF(!DATA.currentMon, "Status1 outside of PLAYER/OPPONENT");
    INVALID_IF(status1 & STATUS1_TOXIC_COUNTER, "Illegal status1: has TOXIC_TURN");
    SetMonData(DATA.currentMon, MON_DATA_STATUS, &status1);
}

void OTName_(u32 sourceLine, const u8 *otName)
{
    INVALID_IF(!DATA.currentMon, "Traded outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_OT_NAME, &otName);
}

static const char *const sBattlerIdentifiersSingles[] =
{
    "player",
    "opponent",
};

static const char *const sBattlerIdentifiersDoubles[] =
{
    "playerLeft",
    "opponentLeft",
    "playerRight",
    "opponentRight",
};

static const char *BattlerIdentifier(s32 battlerId)
{
    const struct BattleTest *test = GetBattleTest();
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_AI_SINGLES:
        return sBattlerIdentifiersSingles[battlerId];
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
        return sBattlerIdentifiersDoubles[battlerId];
    }
    return "<unknown>";
}

static void PushBattlerAction(u32 sourceLine, s32 battlerId, u32 actionType, u32 byte)
{
    u32 recordIndex = DATA.recordIndexes[battlerId]++;
    if (recordIndex >= BATTLER_RECORD_SIZE)
        Test_ExitWithResult(TEST_RESULT_INVALID, "Too many actions");
    DATA.battleRecordTypes[battlerId][recordIndex] = actionType;
    DATA.battleRecordSourceLineOffsets[battlerId][recordIndex] = SourceLineOffset(sourceLine);
    DATA.recordedBattle.battleRecord[battlerId][recordIndex] = byte;
}

void TestRunner_Battle_CheckBattleRecordActionType(u32 battlerId, u32 recordIndex, u32 actionType)
{
    // An illegal move choice will cause the battle to request a new
    // move slot and target. This detects the move slot.
    if (actionType == RECORDED_MOVE_SLOT
     && recordIndex > 0
     && DATA.battleRecordTypes[battlerId][recordIndex-1] != RECORDED_ACTION_TYPE)
    {
        s32 i;
        const char *filename = gTestRunnerState.test->filename;
        for (i = recordIndex; i > 0; i--)
        {
            if (DATA.battleRecordTypes[battlerId][i-1] == RECORDED_ACTION_TYPE
             && DATA.recordedBattle.battleRecord[battlerId][i-1] == B_ACTION_USE_MOVE)
            {
                u32 line = SourceLine(DATA.battleRecordSourceLineOffsets[battlerId][i-1]);
                Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: Illegal MOVE", filename, line);
            }
        }
        Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: Illegal MOVE", filename, SourceLine(0));
    }

    if (DATA.battleRecordTypes[battlerId][recordIndex] != RECORDED_BYTE)
    {
        DATA.lastActionTurn = gBattleResults.battleTurnCounter;

        if (actionType != DATA.battleRecordTypes[battlerId][recordIndex])
        {
            const char *actualMacro = NULL;
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.battleRecordSourceLineOffsets[battlerId][recordIndex]);

            switch (DATA.battleRecordTypes[battlerId][recordIndex])
            {
            case RECORDED_ACTION_TYPE:
                actualMacro = sBattleActionNames[DATA.recordedBattle.battleRecord[battlerId][recordIndex]];
                break;
            case RECORDED_PARTY_INDEX:
                actualMacro = "SEND_OUT";
                break;
            }

            if (actualMacro)
            {
                switch (actionType)
                {
                case RECORDED_ACTION_TYPE:
                    Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: Expected MOVE/SWITCH, got %s", filename, line, actualMacro);
                case RECORDED_PARTY_INDEX:
                    Test_ExitWithResult(TEST_RESULT_INVALID, "%s:%d: Expected SEND_OUT, got %s", filename, line, actualMacro);
                }
            }

            Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: Illegal battle record", filename, line);
        }
    }
    else
    {
        if (DATA.lastActionTurn == gBattleResults.battleTurnCounter)
        {
            const char *filename = gTestRunnerState.test->filename;
            Test_ExitWithResult(TEST_RESULT_FAIL, "%s:%d: TURN %d incomplete", filename, SourceLine(0), gBattleResults.battleTurnCounter + 1);
        }
    }
}

void OpenTurn(u32 sourceLine)
{
    INVALID_IF(DATA.turnState != TURN_CLOSED, "Nested TURN");
    if (DATA.turns == MAX_TURNS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: TURN exceeds MAX_TURNS", gTestRunnerState.test->filename, sourceLine);
    DATA.turnState = TURN_OPEN;
    DATA.actionBattlers = 0x00;
    DATA.moveBattlers = 0x00;
}

static void SetSlowerThan(s32 battlerId)
{
    s32 i, slowerThan;
    slowerThan = 0;
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (i == battlerId)
            continue;
        if (DATA.moveBattlers & (1 << i))
        {
            if ((i & BIT_SIDE) == B_SIDE_PLAYER)
                slowerThan |= 1 << DATA.currentMonIndexes[i];
            else
                slowerThan |= (1 << 6) << DATA.currentMonIndexes[i];
        }
    }
    DATA.slowerThan[battlerId & BIT_SIDE][DATA.currentMonIndexes[battlerId]] |= slowerThan;
}

static void SetAiActionToPass(u32 sourceLine, s32 battlerId)
{
    DATA.expectedAiActions[battlerId][DATA.expectedAiActionIndex[battlerId]].actionSet = TRUE;
    DATA.expectedAiActions[battlerId][DATA.expectedAiActionIndex[battlerId]].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][DATA.expectedAiActionIndex[battlerId]].pass = TRUE;
    DATA.expectedAiActionIndex[battlerId]++;
}

void CloseTurn(u32 sourceLine)
{
    s32 i;
    INVALID_IF(DATA.turnState != TURN_OPEN, "Nested TURN");
    DATA.turnState = TURN_CLOSING;

    // If Move was not specified always use Celebrate. In AI Tests allow any taken action.
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (!(DATA.actionBattlers & (1 << i)))
        {
             if (IsAITest() && (i & BIT_SIDE) == B_SIDE_OPPONENT) // If Move was not specified, allow any move used.
                SetAiActionToPass(sourceLine, i);
             else
                Move(sourceLine, &gBattleMons[i], (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
        }
    }
    DATA.turnState = TURN_CLOSED;
    DATA.turns++;
}

static struct Pokemon *CurrentMon(s32 battlerId)
{
    struct Pokemon *party;
    if ((battlerId & BIT_SIDE) == B_SIDE_PLAYER)
        party = DATA.recordedBattle.playerParty;
    else
        party = DATA.recordedBattle.opponentParty;
    return &party[DATA.currentMonIndexes[battlerId]];
}

s32 MoveGetTarget(s32 battlerId, u32 moveId, struct MoveContext *ctx, u32 sourceLine)
{
    s32 target = battlerId;
    if (ctx->explicitTarget)
    {
        target = ctx->target - gBattleMons;
    }
    else
    {
        const struct BattleMove *move = &gBattleMoves[moveId];
        if (move->target == MOVE_TARGET_RANDOM
         || move->target == MOVE_TARGET_BOTH
         || move->target == MOVE_TARGET_DEPENDS
         || move->target == MOVE_TARGET_FOES_AND_ALLY
         || move->target == MOVE_TARGET_OPPONENTS_FIELD
         || move->target == MOVE_TARGET_ALL_BATTLERS)
        {
            target = BATTLE_OPPOSITE(battlerId);
        }
        else if (move->target == MOVE_TARGET_SELECTED)
        {
            // In AI Doubles not specified target allows any target for EXPECT_MOVE.
            if (GetBattleTest()->type != BATTLE_TEST_AI_DOUBLES)
            {
                INVALID_IF(STATE->battlersCount > 2, "%S requires explicit target", gMoveNames[moveId]);
            }

            target = BATTLE_OPPOSITE(battlerId);
        }
        else if (move->target == MOVE_TARGET_USER)
        {
            target = battlerId;
        }
        else if (move->target == MOVE_TARGET_ALLY)
        {
            target = BATTLE_PARTNER(battlerId);
        }
        else
        {
            // In AI Doubles not specified target allows any target for EXPECT_MOVE.
            if (GetBattleTest()->type != BATTLE_TEST_AI_DOUBLES)
            {
                INVALID("%S requires explicit target", gMoveNames[moveId]);
            }
        }
    }
    return target;
}

void MoveGetIdAndSlot(s32 battlerId, struct MoveContext *ctx, u32 *moveId, u32 *moveSlot, u32 sourceLine)
{
    u32 i;
    struct Pokemon *mon = CurrentMon(battlerId);

    if (ctx->explicitMove)
    {
        INVALID_IF(ctx->move == MOVE_NONE || ctx->move >= MOVES_COUNT, "Illegal move: %d", ctx->move);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            *moveId = GetMonData(mon, MON_DATA_MOVE1 + i);
            if (*moveId == ctx->move)
            {
                *moveSlot = i;
                break;
            }
            else if (*moveId == MOVE_NONE)
            {
                INVALID_IF(DATA.explicitMoves[battlerId & BIT_SIDE] & (1 << DATA.currentMonIndexes[battlerId]), "Missing explicit %S", gMoveNames[ctx->move]);
                SetMonData(mon, MON_DATA_MOVE1 + i, &ctx->move);
                SetMonData(DATA.currentMon, MON_DATA_PP1 + i, &gBattleMoves[ctx->move].pp);
                *moveSlot = i;
                *moveId = ctx->move;
                break;
            }
        }
        INVALID_IF(i == MAX_MON_MOVES, "Too many different moves for %s", BattlerIdentifier(battlerId));
    }
    else if (ctx->explicitMoveSlot)
    {
        *moveSlot = ctx->moveSlot;
        *moveId = GetMonData(mon, MON_DATA_MOVE1 + *moveSlot);
        INVALID_IF(moveId == MOVE_NONE, "Empty moveSlot: %d", ctx->moveSlot);
    }
    else
    {
        INVALID("No move or moveSlot");
    }

    if (ctx->explicitMegaEvolve && ctx->megaEvolve)
        *moveSlot |= RET_MEGA_EVOLUTION;

    if (ctx->explicitUltraBurst && ctx->ultraBurst)
        *moveSlot |= RET_ULTRA_BURST;

    if (ctx->explicitDynamax && ctx->dynamax)
        *moveSlot |= RET_DYNAMAX;
}

void Move(u32 sourceLine, struct BattlePokemon *battler, struct MoveContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    u32 moveId, moveSlot;
    s32 target;

    INVALID_IF(DATA.turnState == TURN_CLOSED, "MOVE outside TURN");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "MOVE is not allowed for opponent in AI tests. Use EXPECT_MOVE instead");

    MoveGetIdAndSlot(battlerId, &ctx, &moveId, &moveSlot, sourceLine);
    target = MoveGetTarget(battlerId, moveId, &ctx, sourceLine);

    if (ctx.explicitHit)
        DATA.battleRecordTurns[DATA.turns][battlerId].hit = 1 + ctx.hit;
    if (ctx.explicitCriticalHit)
        DATA.battleRecordTurns[DATA.turns][battlerId].criticalHit = 1 + ctx.criticalHit;
    if (ctx.explicitSecondaryEffect)
        DATA.battleRecordTurns[DATA.turns][battlerId].secondaryEffect = 1 + ctx.secondaryEffect;
    if (ctx.explicitRNG)
        DATA.battleRecordTurns[DATA.turns][battlerId].rng = ctx.rng;

    if (!(DATA.actionBattlers & (1 << battlerId)))
    {
        PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_USE_MOVE);
    }

    if (!ctx.explicitAllowed || ctx.allowed)
    {
        PushBattlerAction(sourceLine, battlerId, RECORDED_MOVE_SLOT, moveSlot);
        PushBattlerAction(sourceLine, battlerId, RECORDED_MOVE_TARGET, target);
    }

    if (DATA.turnState == TURN_OPEN)
    {
        if (!DATA.hasExplicitSpeeds)
            SetSlowerThan(battlerId);

        DATA.actionBattlers |= 1 << battlerId;
        DATA.moveBattlers |= 1 << battlerId;
    }
}

void ForcedMove(u32 sourceLine, struct BattlePokemon *battler)
{
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SKIP_TURN outside TURN");
    PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_USE_MOVE);
    if (DATA.turnState == TURN_OPEN)
    {
        if (!DATA.hasExplicitSpeeds)
            SetSlowerThan(battlerId);

        DATA.actionBattlers |= 1 << battlerId;
        DATA.moveBattlers |= 1 << battlerId;
    }
}

static void TryMarkExpectMove(u32 sourceLine, struct BattlePokemon *battler, struct MoveContext *ctx)
{
    s32 battlerId = battler - gBattleMons;
    u32 moveId, moveSlot, id;
    s32 target;

    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_MOVE outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_MOVE is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST");
    MoveGetIdAndSlot(battlerId, ctx, &moveId, &moveSlot, sourceLine);
    target = MoveGetTarget(battlerId, moveId, ctx, sourceLine);

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_USE_MOVE;
    DATA.expectedAiActions[battlerId][id].moveSlots |= gBitTable[moveSlot];
    DATA.expectedAiActions[battlerId][id].target = target;
    DATA.expectedAiActions[battlerId][id].explicitTarget = ctx->explicitTarget;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    if (ctx->explicitNotExpected)
        DATA.expectedAiActions[battlerId][id].notMove = ctx->notExpected;

    DATA.actionBattlers |= 1 << battlerId;
    DATA.moveBattlers |= 1 << battlerId;
}

void ExpectMove(u32 sourceLine, struct BattlePokemon *battler, struct MoveContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    TryMarkExpectMove(sourceLine, battler, &ctx);
    DATA.expectedAiActionIndex[battlerId]++;
}

void ExpectSendOut(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i, id;
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_SEND_OUT outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_SEND_OUT is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST");
    INVALID_IF(partyIndex >= ((battlerId & BIT_SIDE) == B_SIDE_PLAYER ? DATA.playerPartySize : DATA.opponentPartySize), "EXPECT_SEND_OUT to invalid party index");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF(DATA.currentMonIndexes[i] == partyIndex, "EXPECT_SEND_OUT to battler");
    }
    if (!(DATA.actionBattlers & (1 << battlerId)))
    {
        if (IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT) // If Move was not specified, allow any move used.
            SetAiActionToPass(sourceLine, battlerId);
        else
            Move(sourceLine, battler, (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
    }

    DATA.currentMonIndexes[battlerId] = partyIndex;
    DATA.actionBattlers |= 1 << battlerId;

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_SWITCH;
    DATA.expectedAiActions[battlerId][id].target = partyIndex;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    DATA.expectedAiActionIndex[battlerId]++;
}

s32 GetAiMoveTargetForScoreCompare(u32 battlerId, u32 moveId, struct MoveContext *ctx, u32 sourceLine)
{
    s32 target;

    // In Single Battles ai always targets the opposing mon.
    if (GetBattleTest()->type == BATTLE_TEST_AI_SINGLES)
    {
        target = BATTLE_OPPOSITE(battlerId);
    }
    else
    {
        // TODO: Fix ai targeting self in double battles.
        INVALID_IF(!ctx->explicitTarget, "%S requires explicit target for score comparison in doubles", gMoveNames[moveId]);
        target = MoveGetTarget(battlerId, moveId, ctx, sourceLine);
    }
    return target;
}

void Score(u32 sourceLine, struct BattlePokemon *battler, u32 cmp, bool32 toValue, struct TestAIScoreStruct cmpCtx)
{
    u32 moveSlot1, moveSlot2;
    s32 i, target;
    struct MoveContext moveCtx = {0};
    s32 battlerId = battler - gBattleMons;
    s32 turn = DATA.turns;

    INVALID_IF(!IsAITest(), "SCORE_%s%s is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST", sCmpToStringTable[cmp], (toValue == TRUE) ? "_VAL" : "");

    for (i = 0; i < MAX_AI_SCORE_COMPARISION_PER_TURN; i++)
    {
        if (!DATA.expectedAiScores[battlerId][turn][i].set)
            break;
    }

    INVALID_IF(i == MAX_AI_SCORE_COMPARISION_PER_TURN, "Too many EXPECTs in TURN");

    moveCtx.move = cmpCtx.move1;
    moveCtx.explicitMove = cmpCtx.explicitMove1;
    moveCtx.target = cmpCtx.target;
    moveCtx.explicitTarget = cmpCtx.explicitTarget;
    MoveGetIdAndSlot(battlerId, &moveCtx, &cmpCtx.move1, &moveSlot1, sourceLine);
    // For ai moves, target is never self.
    target = GetAiMoveTargetForScoreCompare(battlerId, cmpCtx.move1, &moveCtx, sourceLine);
    DATA.expectedAiScores[battlerId][turn][i].target = target;
    DATA.expectedAiScores[battlerId][turn][i].moveSlot1 = moveSlot1;
    DATA.expectedAiScores[battlerId][turn][i].cmp = cmp;
    DATA.expectedAiScores[battlerId][turn][i].toValue = toValue;
    if (toValue)
    {
        DATA.expectedAiScores[battlerId][turn][i].value = cmpCtx.valueOrMoveId2;
    }
    else
    {
        moveCtx.move = cmpCtx.valueOrMoveId2;
        moveCtx.explicitMove = cmpCtx.explicitValueOrMoveId2;
        moveCtx.target = cmpCtx.target;
        moveCtx.explicitTarget = cmpCtx.explicitTarget;
        MoveGetIdAndSlot(battlerId, &moveCtx, &cmpCtx.valueOrMoveId2, &moveSlot2, sourceLine);
        DATA.expectedAiScores[battlerId][turn][i].moveSlot2 = moveSlot2;
    }
    DATA.expectedAiScores[battlerId][turn][i].sourceLine = sourceLine;
    DATA.expectedAiScores[battlerId][turn][i].set = TRUE;
}

void ExpectMoves(u32 sourceLine, struct BattlePokemon *battler, bool32 notExpected, struct FourMoves moves)
{
    s32 battlerId = battler - gBattleMons;
    u32 i;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (moves.moves[i] != MOVE_NONE)
        {
            struct MoveContext ctx = {0};
            ctx.move = moves.moves[i];
            ctx.explicitMove = ctx.explicitNotExpected = TRUE;
            ctx.notExpected = notExpected;
            TryMarkExpectMove(sourceLine, battler, &ctx);
        }
    }
    DATA.expectedAiActionIndex[battlerId]++;
}

void Switch(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i;
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SWITCH outside TURN");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(partyIndex >= ((battlerId & BIT_SIDE) == B_SIDE_PLAYER ? DATA.playerPartySize : DATA.opponentPartySize), "SWITCH to invalid party index");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "SWITCH is not allowed for opponent in AI tests. Use EXPECT_SWITCH instead");

    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF(DATA.currentMonIndexes[i] == partyIndex, "SWITCH to battler");
    }

    PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_SWITCH);
    PushBattlerAction(sourceLine, battlerId, RECORDED_PARTY_INDEX, partyIndex);
    DATA.currentMonIndexes[battlerId] = partyIndex;

    DATA.actionBattlers |= 1 << battlerId;
}

void ExpectSwitch(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i, id;
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_SWITCH outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_SWITCH is usable only in AI_SINGLE_BATTLE_TEST & AI_DOUBLE_BATTLE_TEST");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(partyIndex >= ((battlerId & BIT_SIDE) == B_SIDE_PLAYER ? DATA.playerPartySize : DATA.opponentPartySize), "EXPECT_SWITCH to invalid party index");

    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF(DATA.currentMonIndexes[i] == partyIndex, "EXPECT_SWITCH to battler");
    }

    DATA.currentMonIndexes[battlerId] = partyIndex;
    DATA.actionBattlers |= 1 << battlerId;

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_SWITCH;
    DATA.expectedAiActions[battlerId][id].target = partyIndex;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    DATA.expectedAiActionIndex[battlerId]++;
}

void SkipTurn(u32 sourceLine, struct BattlePokemon *battler)
{
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SKIP_TURN outside TURN");
    DATA.actionBattlers |= 1 << battlerId;
}

void SendOut(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i;
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SEND_OUT outside TURN");
    INVALID_IF(partyIndex >= ((battlerId & BIT_SIDE) == B_SIDE_PLAYER ? DATA.playerPartySize : DATA.opponentPartySize), "SWITCH to invalid party index");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "SEND_OUT is not allowed for opponent in AI tests. Use EXPECT_SEND_OUT instead");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF(DATA.currentMonIndexes[i] == partyIndex, "SEND_OUT to battler");
    }
    if (!(DATA.actionBattlers & (1 << battlerId)))
        Move(sourceLine, battler, (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
    PushBattlerAction(sourceLine, battlerId, RECORDED_PARTY_INDEX, partyIndex);
    DATA.currentMonIndexes[battlerId] = partyIndex;
}

void UseItem(u32 sourceLine, struct BattlePokemon *battler, struct ItemContext ctx)
{
    s32 i;
    s32 battlerId = battler - gBattleMons;
    bool32 requirePartyIndex = ItemId_GetType(ctx.itemId) == ITEM_USE_PARTY_MENU || ItemId_GetType(ctx.itemId) == ITEM_USE_PARTY_MENU_MOVES;
    // Check general bad use.
    INVALID_IF(DATA.turnState == TURN_CLOSED, "USE_ITEM outside TURN");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(ctx.itemId >= ITEMS_COUNT, "Illegal item: %d", ctx.itemId);
    // Check party menu items.
    INVALID_IF(requirePartyIndex && !ctx.explicitPartyIndex, "%S requires explicit party index", ItemId_GetName(ctx.itemId));
    INVALID_IF(requirePartyIndex && ctx.partyIndex >= ((battlerId & BIT_SIDE) == B_SIDE_PLAYER ? DATA.playerPartySize : DATA.opponentPartySize), \
                "USE_ITEM to invalid party index");
    // Check move slot items.
    if (ItemId_GetType(ctx.itemId) == ITEM_USE_PARTY_MENU_MOVES)
    {
        INVALID_IF(!ctx.explicitMove, "%S requires an explicit move", ItemId_GetName(ctx.itemId));
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (GetMonData(CurrentMon(battlerId), MON_DATA_MOVE1 + i, NULL) == ctx.move)
                break;
        }
        INVALID_IF(i == MAX_MON_MOVES, "USE_ITEM on invalid move: %d", ctx.move);
    }
    else
    {
        i = 0;
    }
    PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_USE_ITEM);
    PushBattlerAction(sourceLine, battlerId, RECORDED_ITEM_ID, (ctx.itemId >> 8) & 0xFF);
    PushBattlerAction(sourceLine, battlerId, RECORDED_ITEM_ID, ctx.itemId & 0xFF);
    PushBattlerAction(sourceLine, battlerId, RECORDED_ITEM_TARGET, ctx.partyIndex);
    PushBattlerAction(sourceLine, battlerId, RECORDED_ITEM_MOVE, i);
    DATA.actionBattlers |= 1 << battlerId;
}

static const char *const sQueueGroupTypeMacros[] =
{
    [QUEUE_GROUP_NONE] = NULL,
    [QUEUE_GROUP_ONE_OF] = "ONE_OF",
    [QUEUE_GROUP_NONE_OF] = "NONE_OF",
};

void OpenQueueGroup(u32 sourceLine, enum QueueGroupType type)
{
    INVALID_IF(DATA.queueGroupType, "%s inside %s", sQueueGroupTypeMacros[type], sQueueGroupTypeMacros[DATA.queueGroupType]);
    if (DATA.queuedEventsCount > 0
     && DATA.queuedEvents[DATA.queueGroupStart].groupType == QUEUE_GROUP_NONE_OF
     && DATA.queuedEvents[DATA.queueGroupStart].groupSize == DATA.queuedEventsCount - DATA.queueGroupStart
     && type == QUEUE_GROUP_NONE_OF)
    {
        INVALID("'NOT x; NOT y;', did you mean 'NONE_OF { x; y; }'?");
    }
    else
    {
        DATA.queueGroupType = type;
        DATA.queueGroupStart = DATA.queuedEventsCount;
    }
}

void CloseQueueGroup(u32 sourceLine)
{
    u32 groupSize = DATA.queuedEventsCount - DATA.queueGroupStart;
    if (groupSize > 0)
    {
        DATA.queuedEvents[DATA.queueGroupStart].groupType = DATA.queueGroupType;
        DATA.queuedEvents[DATA.queueGroupStart].groupSize = groupSize;
        DATA.queueGroupType = QUEUE_GROUP_NONE;
    }
}

void QueueAbility(u32 sourceLine, struct BattlePokemon *battler, struct AbilityEventContext ctx)
{
#if B_ABILITY_POP_UP
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(!STATE->runScene, "ABILITY_POPUP outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: ABILITY exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_ABILITY_POPUP_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .ability = {
            .battlerId = battlerId,
            .ability = ctx.ability,
        }},
    };
#endif
}

void QueueAnimation(u32 sourceLine, u32 type, u32 id, struct AnimationEventContext ctx)
{
    s32 attackerId, targetId;

    INVALID_IF(!STATE->runScene, "ANIMATION outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: ANIMATION exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

    attackerId = ctx.attacker ? ctx.attacker - gBattleMons : 0xF;
    if (type == ANIM_TYPE_MOVE)
    {
        targetId = ctx.target ? ctx.target - gBattleMons : 0xF;
    }
    else
    {
        INVALID_IF(ctx.target, "ANIMATION target set for non-ANIM_TYPE_MOVE");
        targetId = 0xF;
    }

    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_ANIMATION_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .animation = {
            .type = type,
            .id = id,
            .attacker = attackerId,
            .target = targetId,
        }},
    };
}

void QueueHP(u32 sourceLine, struct BattlePokemon *battler, struct HPEventContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    u32 type;
    uintptr_t address;

    INVALID_IF(!STATE->runScene, "HP_BAR outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: HP_BAR exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

    if (ctx.explicitHP)
    {
        type = HP_EVENT_NEW_HP;
        address = (u16)ctx.hp;
    }
    else if (ctx.explicitDamage)
    {
        INVALID_IF(ctx.damage == 0, "damage is 0");
        type = HP_EVENT_DELTA_HP;
        address = (u16)ctx.damage;
    }
    else if (ctx.explicitCaptureHP)
    {
        INVALID_IF(ctx.captureHP == NULL, "captureHP is NULL");
        type = HP_EVENT_NEW_HP;
        address = (uintptr_t)ctx.captureHP;
    }
    else if (ctx.explicitCaptureDamage)
    {
        INVALID_IF(ctx.captureDamage == NULL, "captureDamage is NULL");
        type = HP_EVENT_DELTA_HP;
        *ctx.captureDamage = 0;
        address = (uintptr_t)ctx.captureDamage;
    }
    else
    {
        type = HP_EVENT_DELTA_HP;
        address = 0;
    }

    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_HP_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .hp = {
            .battlerId = battlerId,
            .type = type,
            .address = address,
        }},
    };
}

void QueueExp(u32 sourceLine, struct BattlePokemon *battler, struct ExpEventContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    u32 type;
    uintptr_t address;

    INVALID_IF(!STATE->runScene, "EXPERIENCE_BAR outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: EXPERIENCE_BAR exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

    if (ctx.explicitExp)
    {
        type = EXP_EVENT_NEW_EXP;
        address = (u32)ctx.exp;
    }
    else if (ctx.explicitCaptureGainedExp)
    {
        INVALID_IF(ctx.captureGainedExp == NULL, "captureGainedExp is NULL");
        type = EXP_EVENT_DELTA_EXP;
        *ctx.captureGainedExp = 0;
        address = (uintptr_t)ctx.captureGainedExp;
    }
    else
    {
        type = EXP_EVENT_DELTA_EXP;
        address = 0;
    }

    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_EXP_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .exp = {
            .battlerId = battlerId,
            .type = type,
            .address = address,
        }},
    };
}

void QueueMessage(u32 sourceLine, const u8 *pattern)
{
    INVALID_IF(!STATE->runScene, "MESSAGE outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: MESSAGE exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_MESSAGE_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .message = {
            .pattern = pattern,
        }},
    };
}

void QueueStatus(u32 sourceLine, struct BattlePokemon *battler, struct StatusEventContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    u32 mask;

    INVALID_IF(!STATE->runScene, "STATUS_ICON outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, "%s:%d: STATUS_ICON exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

    if (ctx.none)
        mask = 0;
    else if (ctx.sleep)
        mask = STATUS1_SLEEP;
    else if (ctx.poison)
        mask = STATUS1_POISON;
    else if (ctx.burn)
        mask = STATUS1_BURN;
    else if (ctx.freeze)
        mask = STATUS1_FREEZE;
    else if (ctx.paralysis)
        mask = STATUS1_PARALYSIS;
    else if (ctx.badPoison)
        mask = STATUS1_TOXIC_POISON;
    else if (ctx.frostbite)
        mask = STATUS1_FROSTBITE;
    else
        mask = ctx.status1;

    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_STATUS_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .status = {
            .battlerId = battlerId,
            .mask = mask,
        }},
    };
}

void ValidateFinally(u32 sourceLine)
{
    // Defer this error until after estimating the cost.
    INVALID_IF(STATE->parametersCount == 0, "FINALLY without PARAMETRIZE");
}

u32 TestRunner_Battle_GetForcedAbility(u32 side, u32 partyIndex)
{
    return DATA.forcedAbilities[side][partyIndex];
}

// TODO: Consider storing the last successful i and searching from i+1
// to improve performance.
struct AILogLine *GetLogLine(u32 battlerId, u32 moveIndex)
{
    s32 i;

    for (i = 0; i < MAX_AI_LOG_LINES; i++)
    {
        struct AILogLine *log = &DATA.aiLogLines[battlerId][moveIndex][i];
        if (log->file == NULL)
        {
            return log;
        }
    }

    Test_ExitWithResult(TEST_RESULT_ERROR, "Too many AI log lines");
    return NULL;
}

void TestRunner_Battle_AILogScore(const char *file, u32 line, u32 battlerId, u32 moveIndex, s32 score, bool32 setScore)
{
    struct AILogLine *log;

    if (!DATA.logAI) return;

    log = GetLogLine(battlerId, moveIndex);
    log->file = file;
    log->line = line;
    log->score = score;
    log->set = setScore;
}

void TestRunner_Battle_AISetScore(const char *file, u32 line, u32 battlerId, u32 moveIndex, s32 score)
{
    TestRunner_Battle_AILogScore(file, line, battlerId, moveIndex, score, TRUE);
}

void TestRunner_Battle_AIAdjustScore(const char *file, u32 line, u32 battlerId, u32 moveIndex, s32 score)
{
    TestRunner_Battle_AILogScore(file, line, battlerId, moveIndex, score, FALSE);
}
