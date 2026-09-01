#include "global.h"
#include "battle.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_setup.h"
#include "battle_gimmick.h"
#include "battle_z_move.h"
#include "event_data.h"
#include "fieldmap.h"
#include "item_menu.h"
#include "main.h"
#include "malloc.h"
#include "party_menu.h"
#include "random.h"
#include "test/battle.h"
#include "trainer_pools.h"
#include "window.h"
#include "constants/characters.h"
#include "constants/trainers.h"
#include "constants/abilities.h"

#if defined(__INTELLISENSE__)
#undef TestRunner_Battle_RecordAbilityPopUp
#undef TestRunner_Battle_RecordAnimation
#undef TestRunner_Battle_RecordHP
#undef TestRunner_Battle_RecordSubHit
#undef TestRunner_Battle_RecordMessage
#undef TestRunner_Battle_RecordStatus1
#undef TestRunner_Battle_AfterLastTurn
#undef TestRunner_Battle_CheckBattleRecordActionType
#undef TestRunner_Battle_GetForcedAbility
#undef TestRunner_Battle_RecordEffectivenessSound
#endif

#define INVALID(fmt, ...) Test_ExitWithResult(TEST_RESULT_INVALID, sourceLine, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__)
#define INVALID_IF(c, fmt, ...) do { if (c) Test_ExitWithResult(TEST_RESULT_INVALID, sourceLine, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__); } while (0)

#define ASSUMPTION_FAIL_IF(c, fmt, ...) do { if (c) Test_ExitWithResult(TEST_RESULT_ASSUMPTION_FAIL, sourceLine, "%s:%d: " fmt, gTestRunnerState.test->filename, sourceLine, ##__VA_ARGS__); } while (0)

#define STATE gBattleTestRunnerState
#define DATA gBattleTestRunnerState->data

#define RNG_SEED_DEFAULT {0, 0, 0, 0}
static inline bool32 RngSeedNotDefault(const rng_value_t *seed)
{
    return (seed->a | seed->b | seed->c | seed->ctr) != 0;

}
#undef Q_4_12
#define Q_4_12(n) (s32)((n) * 4096)

#define TRAINER_RED_TEST    1
#define TRAINER_LEAF_TEST   2
#define PARTNER_STEVEN_TEST 1

const struct Trainer gTrainers[DIFFICULTY_COUNT][TRAINERS_COUNT] =
{
    #include "battle/trainer_control.h"
};

const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT] =
{
    #include "battle/partner_control.h"
};

// Alias sBackupMapData to avoid using heap.
struct BattleTestRunnerState *const gBattleTestRunnerState = (void *)sBackupMapData;
STATIC_ASSERT(sizeof(struct BattleTestRunnerState) <= sizeof(sBackupMapData), sBackupMapDataSpace);

static void CB2_BattleTest_NextParameter(void);
static void CB2_BattleTest_NextTrial(void);
static void PushBattlerAction(u32 sourceLine, enum BattlerId battlerId, u32 actionType, u32 byte);
static void PrintAiMoveLog(enum BattlerId battlerId, u32 moveSlot, enum Move moveId, s32 totalScore);
static void ClearAiLog(enum BattlerId battlerId);
static const char *BattlerIdentifier(enum BattlerId battlerId);

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

NAKED static void InvokeDoubleTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *playerLeft, struct BattlePokemon *opponentLeft, struct BattlePokemon *playerRight, struct BattlePokemon *opponentRight, DoubleBattleTestFunction function, void *stack)
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

NAKED static void InvokeMultiTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *playerLeft, struct BattlePokemon *opponentLeft, struct BattlePokemon *playerRight, struct BattlePokemon *opponentRight, MultiBattleTestFunction function, void *stack)
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
         ldr r6, =MultiRestoreSP + 1\n\
         mov lr, r6\n\
         bx r4\n\
    MultiRestoreSP:\n\
         add sp, #8\n\
         pop {r0}\n\
         mov sp, r0\n\
         pop {r4-r7}\n\
         pop {r0}\n\
         bx r0\n\
        .pool");
}

NAKED static void InvokeTwoVsOneTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *playerLeft, struct BattlePokemon *opponentLeft, struct BattlePokemon *playerRight, struct BattlePokemon *opponentRight, TwoVsOneBattleTestFunction function, void *stack)
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
         ldr r6, =TwoVsOneRestoreSP + 1\n\
         mov lr, r6\n\
         bx r4\n\
    TwoVsOneRestoreSP:\n\
         add sp, #8\n\
         pop {r0}\n\
         mov sp, r0\n\
         pop {r4-r7}\n\
         pop {r0}\n\
         bx r0\n\
        .pool");
}

NAKED static void InvokeOneVsTwoTestFunctionWithStack(void *results, u32 i, struct BattlePokemon *playerLeft, struct BattlePokemon *opponentLeft, struct BattlePokemon *playerRight, struct BattlePokemon *opponentRight, OneVsTwoBattleTestFunction function, void *stack)
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
         ldr r6, =OneVsTwoRestoreSP + 1\n\
         mov lr, r6\n\
         bx r4\n\
    OneVsTwoRestoreSP:\n\
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
    // 2 bits per battler; battler0/1 are always trainer0/1, respectively
    DATA.battlerTrainers = B_TRAINER_OPPONENT_A << 2;
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_GHOST:
    case BATTLE_TEST_AI_SINGLES:
        InvokeSingleTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], test->function.singles, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
        DATA.battlerTrainers |= B_TRAINER_OPPONENT_A << 6;
        InvokeDoubleTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], &gBattleMons[B_POSITION_PLAYER_RIGHT], &gBattleMons[B_POSITION_OPPONENT_RIGHT], test->function.doubles, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    case BATTLE_TEST_MULTI:
    case BATTLE_TEST_AI_MULTI:
        DATA.battlerTrainers |= (B_TRAINER_PARTNER << 4 | B_TRAINER_OPPONENT_B << 6);
        InvokeMultiTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], &gBattleMons[B_POSITION_PLAYER_RIGHT], &gBattleMons[B_POSITION_OPPONENT_RIGHT], test->function.multi, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    case BATTLE_TEST_TWO_VS_ONE:
    case BATTLE_TEST_AI_TWO_VS_ONE:
        DATA.battlerTrainers |= (B_TRAINER_PARTNER << 4 | B_TRAINER_OPPONENT_A << 6);
        InvokeTwoVsOneTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], &gBattleMons[B_POSITION_PLAYER_RIGHT], &gBattleMons[B_POSITION_OPPONENT_RIGHT], test->function.two_vs_one, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    case BATTLE_TEST_ONE_VS_TWO:
    case BATTLE_TEST_AI_ONE_VS_TWO:
        DATA.battlerTrainers |= B_TRAINER_OPPONENT_B << 6;
        InvokeOneVsTwoTestFunctionWithStack(STATE->results, STATE->runParameter, &gBattleMons[B_POSITION_PLAYER_LEFT], &gBattleMons[B_POSITION_OPPONENT_LEFT], &gBattleMons[B_POSITION_PLAYER_RIGHT], &gBattleMons[B_POSITION_OPPONENT_RIGHT], test->function.one_vs_two, &DATA.stack[BATTLE_TEST_STACK_SIZE]);
        break;
    }
}

static const struct BattleTest *GetBattleTest(void)
{
    const struct BattleTest *test = gTestRunnerState.test->data;
    return test;
}

bool32 IsAITest(void)
{
    switch (GetBattleTest()->type)
    {
    case BATTLE_TEST_AI_SINGLES:
    case BATTLE_TEST_AI_DOUBLES:
    case BATTLE_TEST_AI_MULTI:
    case BATTLE_TEST_AI_TWO_VS_ONE:
    case BATTLE_TEST_AI_ONE_VS_TWO:
        return TRUE;
    }
    return FALSE;
}

static bool32 IsAIDoublesTest(void)
{
    return (IsAITest() && (GetBattleTest()->type != BATTLE_TEST_AI_SINGLES));
}

static enum BattleTrainer Test_GetBattlerTrainer(enum BattlerId battlerId)
{
    return (gBattleTestRunnerState->data.battlerTrainers >> (2 * battlerId)) & 0x3;
}

static bool32 Test_BattlersShareParty(enum BattlerId battlerId1, enum BattlerId battlerId2)
{
    return Test_GetBattlerTrainer(battlerId1) == Test_GetBattlerTrainer(battlerId2);
}

static void InitTestBattlers(const struct BattleTest *test)
{
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_GHOST:
    case BATTLE_TEST_AI_SINGLES:
        STATE->battlersCount = 2;
        break;
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
    case BATTLE_TEST_MULTI:
    case BATTLE_TEST_AI_MULTI:
    case BATTLE_TEST_TWO_VS_ONE:
    case BATTLE_TEST_AI_TWO_VS_ONE:
    case BATTLE_TEST_ONE_VS_TWO:
    case BATTLE_TEST_AI_ONE_VS_TWO:
        STATE->battlersCount = MAX_BATTLERS_COUNT;
        break;
    }

    gBattlersCount = STATE->battlersCount;
    for (enum BattlerId battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        gBattlerPositions[battler] = battler < gBattlersCount ? battler : B_POSITION_ABSENT;
}

static u32 BattleTest_EstimateCost(void *data)
{
    u32 cost;
    const struct BattleTest *test = data;
    memset(STATE, 0, sizeof(*STATE));
    InitTestBattlers(test);
    STATE->runRandomly = TRUE;
    ResetStartingStatuses();
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
    InitTestBattlers(test);
    InvokeTestFunction(test);
    STATE->parameters = STATE->parametersCount;
    if (STATE->parametersCount == 0 && test->resultsSize > 0)
        Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "results without PARAMETRIZE");
    if (sizeof(*STATE) + test->resultsSize * STATE->parameters > sizeof(sBackupMapData))
        Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "OOM: STATE (%d) + STATE->results (%d) too big for sBackupMapData (%d)", sizeof(*STATE), test->resultsSize * STATE->parameters, sizeof(sBackupMapData));
    STATE->results = (void *)((char *)sBackupMapData + sizeof(struct BattleTestRunnerState));
    memset(STATE->results, 0, test->resultsSize * STATE->parameters);
    STATE->hasTornDownBattle = FALSE;
}

static void PrintTestName(void)
{
    if (STATE->trials && STATE->parameters)
    {
        if (STATE->trials == 1)
            Test_MgbaPrintf(":N%s %d/%d (%d/?)", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters, STATE->runTrial + 1);
        else
            Test_MgbaPrintf(":N%s %d/%d (%d/%d)", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters, STATE->runTrial + 1, STATE->trials);
    }
    else if (STATE->trials)
    {
        if (STATE->trials == 1)
            Test_MgbaPrintf(":N%s (%d/?)", gTestRunnerState.test->name, STATE->runTrial + 1);
        else
            Test_MgbaPrintf(":N%s (%d/%d)", gTestRunnerState.test->name, STATE->runTrial + 1, STATE->trials);
    }
    else if (STATE->parameters)
    {
        Test_MgbaPrintf(":N%s %d/%d", gTestRunnerState.test->name, STATE->runParameter + 1, STATE->parameters);
    }
}

// This does not take into account priority, statuses, or any other
// modifiers.
static void SetImplicitSpeeds(void)
{
    s32 i;
    u32 speed = 12;
    u32 hasSpeeds = 0;
    u32 allSpeeds = ((1 << DATA.partySizes[B_TRAINER_PLAYER]) - 1) | (((1 << DATA.partySizes[B_TRAINER_OPPONENT_A]) - 1) << 6) | (((1 << DATA.partySizes[B_TRAINER_PARTNER]) - 1) << 12) | (((1 << DATA.partySizes[B_TRAINER_OPPONENT_B]) - 1) << 18);
    bool32 madeProgress;
    while (hasSpeeds != allSpeeds)
    {
        madeProgress = FALSE;
        for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        {
            for (i = 0; i < DATA.partySizes[trainer]; i++)
            {
                if (!(hasSpeeds & ((1 << (6 * trainer)) << i))
                 && !(DATA.slowerThan[trainer][i] & ~hasSpeeds))
                {
                    SetMonData(&DATA.recordedBattle.parties[trainer][i], MON_DATA_SPEED, &speed);
                    speed--;
                    hasSpeeds |= ((1 << (6 * trainer)) << i);
                    madeProgress = TRUE;
                }
            }
        }
        if (!madeProgress)
            Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "TURNs have contradictory speeds");
    }
}

static void ResetTestInventory()
{
    ClearBag();
    for (u32 i = 0; i < TEST_ITEM_SLOTS; i++)
    {
        if (DATA.inventory[i].itemId != ITEM_NONE)
            AddBagItem(DATA.inventory[i].itemId, DATA.inventory[i].quantity);
    }
}

static void StartBattle(void)
{
    memset(&DATA.trial, 0, sizeof(DATA.trial));

    SetVariablesForRecordedBattle(&DATA.recordedBattle);
    if (STATE->trials)
        gMain.savedCallback = CB2_BattleTest_NextTrial;
    else if (STATE->parameters)
        gMain.savedCallback = CB2_BattleTest_NextParameter;
    else
        gMain.savedCallback = CB2_TestRunner;
    ResetTestInventory();
    SetMainCallback2(CB2_InitBattle);

    STATE->checkProgressParameter = 0;
    STATE->checkProgressTrial = 0;
    STATE->checkProgressTurn = 0;

    PrintTestName();
}

static void BattleTest_Run(void *data)
{
    s32 i;
    u32 requiredPartySizes[MAX_BATTLE_TRAINERS] = {0};
    const rng_value_t defaultSeed = RNG_SEED_DEFAULT;
    const struct BattleTest *test = data;

    memset(&DATA, 0, sizeof(DATA));
    InitTestBattlers(test);
    TestInitConfigData();

    DATA.queuedEventsFailIndex = MAX_QUEUED_EVENTS;
    DATA.recordedBattle.rngSeed = defaultSeed;
    DATA.recordedBattle.textSpeed = OPTIONS_TEXT_SPEED_FAST;
    // Set battle flags and opponent ids.
    switch (test->type)
    {
    case BATTLE_TEST_WILD:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_GHOST:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_GHOST;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_AI_SINGLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
        DATA.recordedBattle.opponentA = TRAINER_LEAF_TEST;
        DATA.hasAI = TRUE;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_AI_DOUBLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE;
        DATA.recordedBattle.opponentA = TRAINER_LEAF_TEST;
        DATA.recordedBattle.opponentB = TRAINER_NONE;
        DATA.hasAI = TRUE;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_AI_MULTI:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
        DATA.recordedBattle.partnerId = TRAINER_PARTNER(PARTNER_STEVEN_TEST);
        DATA.recordedBattle.opponentA = TRAINER_LEAF_TEST;
        DATA.recordedBattle.opponentB = TRAINER_RED_TEST;
        DATA.hasAI = TRUE;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent A first mon
        DATA.currentMonIndexes[2] = 0; // Player partner first mon
        DATA.currentMonIndexes[3] = 0; // Opponent B first mon
        break;
    case BATTLE_TEST_AI_TWO_VS_ONE:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI;
        DATA.recordedBattle.partnerId = TRAINER_PARTNER(PARTNER_STEVEN_TEST);
        DATA.recordedBattle.opponentA = TRAINER_LEAF_TEST;
        DATA.recordedBattle.opponentB = 0xFFFF;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent first mon
        DATA.currentMonIndexes[2] = 0; // Player partner first mon
        DATA.currentMonIndexes[3] = 1; // Opponent second mon
        DATA.hasAI = TRUE;
        break;
    case BATTLE_TEST_AI_ONE_VS_TWO:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        DATA.recordedBattle.opponentA = TRAINER_LEAF_TEST;
        DATA.recordedBattle.opponentB = TRAINER_RED_TEST;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent A first mon
        DATA.currentMonIndexes[2] = 1; // Player second mon
        DATA.currentMonIndexes[3] = 0; // Opponent B first mon
        DATA.hasAI = TRUE;
        break;
    case BATTLE_TEST_SINGLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER;
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_DOUBLES:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE;
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        DATA.recordedBattle.opponentB = TRAINER_NONE;
        for (i = 0; i < STATE->battlersCount; i++)
            DATA.currentMonIndexes[i] = i / 2;
        break;
    case BATTLE_TEST_MULTI:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
        DATA.recordedBattle.partnerId = TRAINER_PARTNER(PARTNER_STEVEN_TEST);
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        DATA.recordedBattle.opponentB = TRAINER_LINK_OPPONENT;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent A first mon
        DATA.currentMonIndexes[2] = 0; // Player partner first mon
        DATA.currentMonIndexes[3] = 0; // Opponent B first mon
        break;
    case BATTLE_TEST_TWO_VS_ONE:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI;
        DATA.recordedBattle.partnerId = TRAINER_PARTNER(PARTNER_STEVEN_TEST);
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        DATA.recordedBattle.opponentB = 0xFFFF;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent first mon
        DATA.currentMonIndexes[2] = 0; // Player partner first mon
        DATA.currentMonIndexes[3] = 1; // Opponent second mon
        break;
    case BATTLE_TEST_ONE_VS_TWO:
        DATA.recordedBattle.battleFlags = BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_RECORDED_IS_MASTER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        DATA.recordedBattle.opponentA = TRAINER_LINK_OPPONENT;
        DATA.recordedBattle.opponentB = TRAINER_LINK_OPPONENT;
        DATA.currentMonIndexes[0] = 0; // Player first mon
        DATA.currentMonIndexes[1] = 0; // Opponent A first mon
        DATA.currentMonIndexes[2] = 1; // Player second mon
        DATA.currentMonIndexes[3] = 0; // Opponent B first mon
        break;
    }

    gBattleTypeFlags = DATA.recordedBattle.battleFlags;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        DATA.recordedBattle.playersName[i][0] = CHAR_1 + i;
        DATA.recordedBattle.playersName[i][1] = EOS;
        DATA.recordedBattle.playersLanguage[i] = GAME_LANGUAGE;
        DATA.recordedBattle.playersBattlers |= (i << (2 * (i >> 1) + 4 * (i & BIT_SIDE))); // Trainer0/1 second mon occupies same bits as trainer2/3 mon
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

    for (i = 0; i < STATE->battlersCount; i++)
    {
        requiredPartySizes[Test_GetBattlerTrainer(i)] = DATA.currentMonIndexes[i] + 1;
    }
    for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
    {
        if (DATA.partySizes[trainer] < requiredPartySizes[trainer])
        {
            switch (trainer)
            {
            case B_TRAINER_PLAYER:
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d PLAYER Pokemon required", requiredPartySizes[trainer]);
                break;
            case B_TRAINER_OPPONENT_A:
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d OPPONENT_A Pokemon required", requiredPartySizes[trainer]);
                else
                    Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d OPPONENT Pokemon required", requiredPartySizes[trainer]);
                break;
            case B_TRAINER_PARTNER:
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d PARTNER Pokemon required", requiredPartySizes[trainer]);
                break;
            case B_TRAINER_OPPONENT_B:
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d OPPONENT_B Pokemon required", requiredPartySizes[trainer]);
                break;
            default:
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%d TRAINER %d Pokemon required", requiredPartySizes[trainer], trainer);
                break;
            }
        }
    }

    for (i = 0; i < STATE->battlersCount; i++)
        PushBattlerAction(0, i, RECORDED_BYTE, B_ACTION_NONE);

    if (DATA.hasExplicitSpeeds)
    {
        u8 requiredExplicitSpeeds[MAX_BATTLE_TRAINERS] = {0};

        for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        {
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if(GetMonData(&DATA.recordedBattle.parties[trainer][i], MON_DATA_SPECIES) != SPECIES_NONE)
                    requiredExplicitSpeeds[trainer] |= 1 << i;
            }

            if (DATA.explicitSpeeds[trainer] != requiredExplicitSpeeds[trainer])
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "Speed required for all PLAYERs and OPPONENTs");
        }
    }
    else
    {
        SetImplicitSpeeds();
    }

    StartBattle();
}

static bool32 IsTieBreakTag(enum RandomTag tag)
{
    switch (tag)
    {
    case RNG_AI_SCORE_TIE_SINGLES:
    case RNG_AI_SCORE_TIE_DOUBLES_MOVE:
    case RNG_AI_SCORE_TIE_DOUBLES_TARGET:
        return TRUE;
    default:
        break;
    }
    return FALSE;
}

static void SanitizeTieCounts(void)
{
    if (DATA.trial.scoreTieCount < 1)
        DATA.trial.scoreTieCount = 1;
    if (DATA.trial.scoreTieCount > MAX_MON_MOVES)
        DATA.trial.scoreTieCount = MAX_MON_MOVES;

    if (DATA.trial.targetTieCount < 1)
        DATA.trial.targetTieCount = 1;
    if (DATA.trial.targetTieCount >= gBattlersCount)
        DATA.trial.targetTieCount = (gBattlersCount - 1);
}

u32 RandomUniformTrials(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller)
{
    STATE->didRunRandomly = TRUE;
    if (STATE->trials == 1)
    {
        u32 n = 0, i;
        if (reject)
        {
            for (i = lo; i <= hi; i++)
                if (!reject(i))
                    n++;
            STATE->trials = n;
        }
        else
            STATE->trials = hi - lo + 1;
        PrintTestName();
    }
    STATE->trialRatio = Q_4_12(1) / STATE->trials;

    if (!reject)
    {
        if ((STATE->trials != (hi - lo + 1)) && !(IsTieBreakTag(tag)))
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomUniform called from %p with tag %d and inconsistent trials %d and %d", caller, tag, STATE->trials, hi - lo + 1);
        return STATE->runTrial + lo;
    }

    while (reject(STATE->runTrial + lo + STATE->rngTrialOffset))
    {
        if (STATE->runTrial + lo + STATE->rngTrialOffset > hi)
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomUniformExcept called from %p with tag %d and inconsistent reject", caller, tag);
        STATE->rngTrialOffset++;
    }

    return STATE->runTrial + lo + STATE->rngTrialOffset;

}

u32 RandomWeightedArrayTrials(enum RandomTag tag, u32 sum, u32 n, const u16 *weights, void *caller)
{
    //Detect inconsistent sum
    u32 weightSum = 0;
    if (STATE->runTrial == 0)
    {
        for (u32 i = 0; i < n; i++)
            weightSum += weights[i];
        if (weightSum != sum)
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomWeighted called from %p has weights not matching its sum", caller);
    }

    STATE->didRunRandomly = TRUE;
    if (STATE->trials == 1)
    {
        STATE->trials = n;
        PrintTestName();
    }
    else if (STATE->trials != n)
    {
        Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomWeighted called from %p with tag %d and inconsistent trials %d and %d", caller, tag, STATE->trials, n);
    }

    STATE->trialRatio = Q_4_12(weights[STATE->runTrial]) / sum;
    return STATE->runTrial;
}

const void *RandomElementArrayTrials(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller)
{
    STATE->didRunRandomly = TRUE;
    if (STATE->trials == 1)
    {
        STATE->trials = count;
        PrintTestName();
    }
    else if (STATE->trials != count)
    {
        Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "RandomElement called from %p with tag %d and inconsistent trials %d and %d", caller, tag, STATE->trials, count);
    }
    STATE->trialRatio = Q_4_12(1) / count;
    return (const u8 *)array + size * STATE->runTrial;
}

static u32 BattleTest_RandomUniform(enum RandomTag tag, u32 lo, u32 hi, bool32 (*reject)(u32), void *caller)
{
    //rigged
    const struct BattlerTurn *turn = NULL;
    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        enum BattlerId battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
        {
            if (reject && reject(turn->rng.value))
                Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "WITH_RNG specified a rejected value (%d)", turn->rng.value);
            return turn->rng.value;
        }
    }

    if (IsTieBreakTag(tag))
        SanitizeTieCounts();

    //trials
    switch (tag)
    {
    case RNG_AI_SCORE_TIE_SINGLES:
    case RNG_AI_SCORE_TIE_DOUBLES_MOVE:
        switch (DATA.scoreTieResolution)
        {
        case SCORE_TIE_HI:
            return (DATA.trial.scoreTieCount - 1);
        case SCORE_TIE_RANDOM:
            return RandomUniformTrials(tag, lo, hi, reject, caller);
        case SCORE_TIE_CHOSEN:
            if (DATA.scoreTieOverride >= DATA.trial.scoreTieCount)
                return (DATA.trial.scoreTieCount - 1);
            else
                return DATA.scoreTieOverride;
        default:
            return 0;
        }
    case RNG_AI_SCORE_TIE_DOUBLES_TARGET:
        switch (DATA.targetTieResolution)
        {
        case TARGET_TIE_HI:
            return (DATA.trial.targetTieCount - 1);
        case TARGET_TIE_RANDOM:
            return RandomUniformTrials(tag, lo, hi, reject, caller);
        case TARGET_TIE_CHOSEN:
            if (DATA.targetTieOverride >= DATA.trial.targetTieCount)
                return (DATA.trial.targetTieCount - 1);
            else
                return DATA.targetTieOverride;
        default:
            return 0;
        }
    default:
    if (tag && tag == STATE->rngTag)
        return RandomUniformTrials(tag, lo, hi, reject, caller);
    }

    //default
    return RandomUniformDefaultValue(tag, lo, hi, reject, caller);
}

static u32 BattleTest_RandomWeightedArray(enum RandomTag tag, u32 sum, u32 n, const u16 *weights, void *caller)
{
    //rigged
    const struct BattlerTurn *turn = NULL;
    if (gCurrentTurnActionNumber < gBattlersCount || tag == RNG_SHELL_SIDE_ARM)
    {
        enum BattlerId battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
            return turn->rng.value;
    }

    //trials
    if (tag && tag == STATE->rngTag)
        return RandomWeightedArrayTrials(tag, sum, n, weights, caller);

    //default
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
        return RandomWeightedArrayDefaultValue(tag, n, weights, caller);
    }
}

static const void *BattleTest_RandomElementArray(enum RandomTag tag, const void *array, size_t size, size_t count, void *caller)
{
    //rigged
    const struct BattlerTurn *turn = NULL;
    if (gCurrentTurnActionNumber < gBattlersCount)
    {
        enum BattlerId battlerId = gBattlerByTurnOrder[gCurrentTurnActionNumber];
        turn = &DATA.battleRecordTurns[gBattleResults.battleTurnCounter][battlerId];
        if (turn && turn->rng.tag == tag)
        {
            u32 element = 0;
            for (u32 index = 0; index < count; index++)
            {
                memcpy(&element, (const u8 *)array + size * index, size);
                if (element == turn->rng.value)
                    return (const u8 *)array + size * index;
            }
            Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "%s: RandomElement illegal value requested: %d", gTestRunnerState.test->filename, turn->rng.value);
        }
    }


    //trials
    if (tag && tag == STATE->rngTag)
        return RandomElementArrayTrials(tag, array, size, count, caller);

    //default
    return RandomElementArrayDefaultValue(tag, array, size, count, caller);
}

static s32 TryAbilityPopUp(s32 i, s32 n, enum BattlerId battlerId, enum Ability ability)
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

void TestRunner_Battle_RecordAbilityPopUp(enum BattlerId battlerId, enum Ability ability)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryAbilityPopUp(DATA.trial.queuedEvent, event->groupSize, battlerId, ability) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_ABILITY_POPUP_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
            if (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.ability.ability == ABILITY_NONE)
                Test_MgbaPrintf("%s:%d: Did you mean: ABILITY_POPUP(%s)", filename, line, BattlerIdentifier(battlerId));
            else
                Test_MgbaPrintf("%s:%d: Did you mean: ABILITY_POPUP(%s, ABILITY_%U)", filename, line, BattlerIdentifier(battlerId), gAbilitiesInfo[ability].name);
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryAbilityPopUp(queuedEvent, event->groupSize, battlerId, ability)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched ABILITY_POPUP", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryAbilityPopUp(queuedEvent, event->groupSize, battlerId, ability) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryItemPopUp(s32 i, s32 n, enum BattlerId battlerId, enum Item item)
{
    struct QueuedItemEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_ITEM_POPUP_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.item;

        if (event->battlerId == battlerId
         && (event->item == ITEM_NONE || event->item == item))
            return i;
    }
    return -1;
}

void TestRunner_Battle_RecordItemPopUp(enum BattlerId battlerId, enum Item item)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryItemPopUp(DATA.trial.queuedEvent, event->groupSize, battlerId, item) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_ITEM_POPUP_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
            if (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.item.item == ITEM_NONE)
                Test_MgbaPrintf("%s:%d: Did you mean: ITEM_POPUP(%s)", filename, line, BattlerIdentifier(battlerId));
            else
                Test_MgbaPrintf("%s:%d: Did you mean: ITEM_POPUP(%s, ITEM_%C)", filename, line, BattlerIdentifier(battlerId), gAbilitiesInfo[item].name);
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryItemPopUp(queuedEvent, event->groupSize, battlerId, item)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched ITEM_POPUP", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryItemPopUp(queuedEvent, event->groupSize, battlerId, item) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
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

static const char *const sAnimTypeNames[] =
{
    [ANIM_TYPE_GENERAL] = "ANIM_TYPE_GENERAL",
    [ANIM_TYPE_MOVE] = "ANIM_TYPE_MOVE",
    [ANIM_TYPE_STATUS] = "ANIM_TYPE_STATUS",
    [ANIM_TYPE_SPECIAL] = "ANIM_TYPE_SPECIAL",
};

void TestRunner_Battle_RecordAnimation(u32 animType, u32 animId)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryAnimation(DATA.trial.queuedEvent, event->groupSize, animType, animId) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_ANIMATION_EVENT
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].as.animation.type == animType)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
            bool32 checkAttacker = DATA.queuedEvents[DATA.queuedEventsFailIndex].as.animation.attacker != 0xF;
            bool32 checkTarget = DATA.queuedEvents[DATA.queuedEventsFailIndex].as.animation.target != 0xF;
            if (animType == ANIM_TYPE_MOVE && animId < MOVES_COUNT_ALL)
            {
                if (animId == MOVE_CELEBRATE)
                    ; // TODO: Only if implicit. Difficult to know if it's an action or, e.g. Mirror Move.
                else if (checkAttacker && checkTarget)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, MOVE_%U, %s, target: %s)", filename, line, sAnimTypeNames[animType], gMovesInfo[animId].name, BattlerIdentifier(gBattleAnimAttacker), BattlerIdentifier(gBattleAnimTarget));
                else if (checkAttacker)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, MOVE_%U, %s)", filename, line, sAnimTypeNames[animType], gMovesInfo[animId].name, BattlerIdentifier(gBattleAnimAttacker));
                else
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, MOVE_%U)", filename, line, sAnimTypeNames[animType], gMovesInfo[animId].name);
            }
            else if (animType < ARRAY_COUNT(sAnimTypeNames))
            {
                if (checkAttacker && checkTarget)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, %d, %s, target: %s)", filename, line, sAnimTypeNames[animType], animId, BattlerIdentifier(gBattleAnimAttacker), BattlerIdentifier(gBattleAnimTarget));
                else if (checkAttacker)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, %d, %s)", filename, line, sAnimTypeNames[animType], animId, BattlerIdentifier(gBattleAnimAttacker));
                else
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%s, %d)", filename, line, sAnimTypeNames[animType], animId);
            }
            else
            {
                if (checkAttacker && checkTarget)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%d, %d, %s, target: %s)", filename, line, animType, animId, BattlerIdentifier(gBattleAnimAttacker), BattlerIdentifier(gBattleAnimTarget));
                else if (checkAttacker)
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%d, %d, %s)", filename, line, animType, animId, BattlerIdentifier(gBattleAnimAttacker));
                else
                    Test_MgbaPrintf("%s:%d: Did you mean: ANIMATION(%d, %d)", filename, line, animType, animId);
            }
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryAnimation(queuedEvent, event->groupSize, animType, animId)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched ANIMATION", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryAnimation(queuedEvent, event->groupSize, animType, animId) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryHP(s32 i, s32 n, enum BattlerId battlerId, u32 oldHP, u32 newHP)
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

void TestRunner_Battle_RecordHP(enum BattlerId battlerId, u32 oldHP, u32 newHP)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryHP(DATA.trial.queuedEvent, event->groupSize, battlerId, oldHP, newHP) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_HP_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
            switch (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.hp.type)
            {
            case HP_EVENT_NEW_HP:
                Test_MgbaPrintf("%s:%d: Did you mean: HP_BAR(%s, hp: %d)", filename, line, BattlerIdentifier(battlerId), newHP);
                break;
            case HP_EVENT_DELTA_HP:
                if (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.hp.address == 0)
                    Test_MgbaPrintf("%s:%d: Did you mean: HP_BAR(%s)", filename, line, BattlerIdentifier(battlerId));
                else
                    Test_MgbaPrintf("%s:%d: Did you mean: HP_BAR(%s, damage: %d)", filename, line, BattlerIdentifier(battlerId), oldHP - newHP);
                break;
            }
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryHP(queuedEvent, event->groupSize, battlerId, oldHP, newHP)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched HP_BAR", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryHP(queuedEvent, event->groupSize, battlerId, oldHP, newHP) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TrySubHit(s32 i, s32 n, enum BattlerId battlerId, u32 damage, bool32 broke)
{
    struct QueuedSubHitEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_SUB_HIT_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.subHit;

        if (event->battlerId == battlerId)
        {
            if (event->checkBreak)
            {
                if (event->breakSub && !broke)
                    return -1;
                else if (!event->breakSub && broke)
                    return -1;
            }

            if (event->address <= 0xFFFF)
            {
                event->address = damage;
                return i;
            }
            else
            {
                *(u16 *)(u32)(event->address) = damage;
                return i;
            }
        }
    }
    return -1;
}

static const char *const sBoolNames[] = { [FALSE] = "FALSE", [TRUE] = "TRUE" };

void TestRunner_Battle_RecordSubHit(enum BattlerId battlerId, u32 damage, bool32 broke)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TrySubHit(DATA.trial.queuedEvent, event->groupSize, battlerId, damage, broke) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_SUB_HIT_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(event->sourceLineOffset);
            bool32 checkBreak = DATA.queuedEvents[DATA.queuedEventsFailIndex].as.subHit.checkBreak;
            bool32 checkDamage = DATA.queuedEvents[DATA.queuedEventsFailIndex].as.subHit.address == 0;
            if (checkBreak && checkDamage)
                Test_MgbaPrintf("%s:%d: Did you mean: SUB_HIT(%s, subBreak: %s, damage: %d)", filename, line, BattlerIdentifier(battlerId), sBoolNames[broke], damage);
            else if (checkBreak)
                Test_MgbaPrintf("%s:%d: Did you mean: SUB_HIT(%s, subBreak: %s)", filename, line, BattlerIdentifier(battlerId), sBoolNames[broke]);
            else if (checkDamage)
                Test_MgbaPrintf("%s:%d: Did you mean: SUB_HIT(%s, damage: %d)", filename, line, BattlerIdentifier(battlerId), damage);
            else
                Test_MgbaPrintf("%s:%d: Did you mean: SUB_HIT(%s)", filename, line, BattlerIdentifier(battlerId));
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TrySubHit(queuedEvent, event->groupSize, battlerId, damage, broke)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched SUB_HIT", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TrySubHit(queuedEvent, event->groupSize, battlerId, damage, broke) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
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

static const char *const sGimmickIdentifiers[GIMMICKS_COUNT] =
{
    [GIMMICK_NONE] = "N/A",
    [GIMMICK_MEGA] = "Mega Evolution",
    [GIMMICK_ULTRA_BURST] = "Ultra Burst",
    [GIMMICK_Z_MOVE] = "Z-Move",
    [GIMMICK_DYNAMAX] = "Dynamax",
    [GIMMICK_TERA] = "Terastallize",
};

static u32 CountAiExpectMoves(struct ExpectedAIAction *expectedAction, enum BattlerId battlerId, bool32 printLog)
{
    u32 i, countExpected = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if ((1u << i) & expectedAction->moveSlots)
        {
            if (printLog)
                PrintAiMoveLog(battlerId, i, gBattleMons[battlerId].moves[i], gAiBattleData->finalScore[battlerId][expectedAction->target][i]);
            countExpected++;
        }
    }
    return countExpected;
}

void TestRunner_Battle_CheckChosenMove(enum BattlerId battlerId, enum Move moveId, u32 target, enum Gimmick gimmick)
{
    const char *filename = gTestRunnerState.test->filename;
    u32 id = DATA.trial.aiActionsPlayed[battlerId];
    struct ExpectedAIAction *expectedAction = &DATA.expectedAiActions[battlerId][id];

    if (!expectedAction->actionSet)
        return;

    DATA.trial.lastActionTurn = gBattleResults.battleTurnCounter;

    if (!expectedAction->pass)
    {
        u32 i, expectedMoveId = 0, countExpected;
        bool32 movePasses = FALSE;

        if (expectedAction->type != B_ACTION_USE_MOVE)
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected %s, got MOVE", filename, expectedAction->sourceLine, sBattleActionNames[expectedAction->type]);

        if (expectedAction->explicitTarget && expectedAction->target != target)
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected target %s, got %s", filename, expectedAction->sourceLine, BattlerIdentifier(expectedAction->target), BattlerIdentifier(target));

        if ((DATA.targetTieOverride >= DATA.trial.targetTieCount) && (DATA.targetTieResolution == TARGET_TIE_CHOSEN))
            Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%s:%d: TIE_BREAK_TARGET override %d, greater than count %d of targets with tied best score", filename, expectedAction->sourceLine, DATA.targetTieOverride, DATA.trial.targetTieCount);

        if (expectedAction->gimmick != GIMMICKS_COUNT && expectedAction->gimmick != gimmick)
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected gimmick %s, got %s", filename, expectedAction->sourceLine, sGimmickIdentifiers[expectedAction->gimmick], sGimmickIdentifiers[gimmick]);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if ((1u << i) & expectedAction->moveSlots)
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
            PrintAiMoveLog(battlerId, moveSlot, moveId, gAiBattleData->finalScore[battlerId][expectedAction->target][moveSlot]);
            if (countExpected > 1)
                Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched EXPECT_MOVES %S, got %S", filename, expectedAction->sourceLine, GetMoveName(expectedMoveId), GetMoveName(moveId));
            else
                Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched EXPECT_MOVE %S, got %S", filename, expectedAction->sourceLine, GetMoveName(expectedMoveId), GetMoveName(moveId));
        }
        if (expectedAction->notMove && !movePasses)
        {
            if (countExpected > 1)
                Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched NOT_EXPECT_MOVES %S", filename, expectedAction->sourceLine, GetMoveName(expectedMoveId));
            else
                Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched NOT_EXPECT_MOVE %S", filename, expectedAction->sourceLine, GetMoveName(expectedMoveId));
        }
    }
    // Turn passed, clear logs from the turn
    ClearAiLog(battlerId);
    DATA.trial.aiActionsPlayed[battlerId]++;
}

void TestRunner_Battle_CheckSwitch(enum BattlerId battlerId, u32 partyIndex)
{
    const char *filename = gTestRunnerState.test->filename;
    u32 id = DATA.trial.aiActionsPlayed[battlerId];
    struct ExpectedAIAction *expectedAction = &DATA.expectedAiActions[battlerId][id];

    if (!expectedAction->actionSet)
        return;

    DATA.trial.lastActionTurn = gBattleResults.battleTurnCounter;

    if (!expectedAction->pass)
    {
        if (expectedAction->type != B_ACTION_SWITCH)
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected %s, got SWITCH/SEND_OUT", filename, expectedAction->sourceLine, sBattleActionNames[expectedAction->type]);

        if (expectedAction->target != partyIndex)
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected partyIndex %d, got %d", filename, expectedAction->sourceLine, expectedAction->target, partyIndex);
    }
    DATA.trial.aiActionsPlayed[battlerId]++;
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

static void CheckIfMaxScoreEqualExpectMove(enum BattlerId battlerId, s32 target, struct ExpectedAIAction *aiAction, const char *filename)
{
    u32 i;
    s32 *scores = gAiBattleData->finalScore[battlerId][target];
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
            && (aiAction->moveSlots & (1u << i))
            && !(aiAction->moveSlots & (1u << bestScoreId))
            && (DATA.scoreTieResolution == SCORE_TIE_NONE))
        {
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: EXPECT_MOVE %S has the same best score(%d) as not expected MOVE %S. Consider using TIE_BREAK_SCORE.", filename,
                                aiAction->sourceLine, GetMoveName(moves[i]), scores[i], GetMoveName(moves[bestScoreId]));
        }
        // We DO NOT expect move 'i', but it has the same best score as another move.
        if (scores[i] == scores[bestScoreId]
            && aiAction->notMove
            && (aiAction->moveSlots & (1u << i))
            && !(aiAction->moveSlots & (1u << bestScoreId))
            && (DATA.scoreTieResolution == SCORE_TIE_NONE))
        {
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: NOT_EXPECT_MOVE %S has the same best score(%d) as MOVE %S. Consider using TIE_BREAK_SCORE.", filename,
                                aiAction->sourceLine, GetMoveName(moves[i]), scores[i], GetMoveName(moves[bestScoreId]));
        }
    }
}

static void PrintAiMoveLog(enum BattlerId battlerId, u32 moveSlot, enum Move moveId, s32 totalScore)
{
    s32 i, scoreFromLogs = 0;

    if (!DATA.logAI) return;
    if (DATA.aiLogPrintedForMove[battlerId] & (1u << moveSlot)) return;

    DATA.aiLogPrintedForMove[battlerId] |= 1u << moveSlot;
    Test_MgbaPrintf("Score Log for move %S:\n", GetMoveName(moveId));
    for (i = 0; i < MAX_AI_LOG_LINES; i++)
    {
        struct AILogLine *log = &DATA.aiLogLines[battlerId][moveSlot][i];
        if (log->file)
        {
            if (log->set)
            {
                scoreFromLogs = log->score;
                Test_MgbaPrintf("%s:%d: = %d\n", log->file, log->line, log->score);
            }
            else if (log->score > 0)
            {
                scoreFromLogs += log->score;
                Test_MgbaPrintf("%s:%d: +%d\n", log->file, log->line, log->score);
            }
            else
            {
                scoreFromLogs += log->score;
                Test_MgbaPrintf("%s:%d: %d\n", log->file, log->line, log->score);
            }
        }
        else
        {
            break;
        }
    }
    if (scoreFromLogs != totalScore)
    {
        Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "Warning! Score from logs(%d) is different than actual score(%d). Make sure all of the score adjustments use the ADJUST_SCORE macro\n", scoreFromLogs, totalScore);
    }
    Test_MgbaPrintf("Total: %d\n", totalScore);
}

static void ClearAiLog(enum BattlerId battlerId)
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

void TestRunner_Battle_CheckAiMoveScores(enum BattlerId battlerId)
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
            enum Move moveId1 = gBattleMons[battlerId].moves[scoreCtx->moveSlot1];
            s32 target = scoreCtx->target;
            s32 *scores = gAiBattleData->finalScore[battlerId][target];

            if (scoreCtx->toValue)
            {
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot1, moveId1, scores[scoreCtx->moveSlot1]);
                if (!CheckComparision(scores[scoreCtx->moveSlot1], scoreCtx->value, scoreCtx->cmp))
                {
                    Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched SCORE_%s_VAL %S %d, got %d",
                                        filename, scoreCtx->sourceLine, sCmpToStringTable[scoreCtx->cmp], GetMoveName(moveId1), scoreCtx->value, scores[scoreCtx->moveSlot1]);
                }
            }
            else
            {
                enum Move moveId2 = gBattleMons[battlerId].moves[scoreCtx->moveSlot2];
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot1, moveId1, scores[scoreCtx->moveSlot1]);
                PrintAiMoveLog(battlerId, scoreCtx->moveSlot2, moveId2, scores[scoreCtx->moveSlot2]);
                if (!CheckComparision(scores[scoreCtx->moveSlot1], scores[scoreCtx->moveSlot2], scoreCtx->cmp))
                {
                    Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Unmatched SCORE_%s, got %S: %d, %S: %d",
                                        filename, scoreCtx->sourceLine, sCmpToStringTable[scoreCtx->cmp], GetMoveName(moveId1), scores[scoreCtx->moveSlot1], GetMoveName(moveId2), scores[scoreCtx->moveSlot2]);
                }
            }
        }
    }

    // We need to make sure that the expected move has the best score. We have to rule out a situation where the expected move is used, but it has the same number of points as some other moves.
    aiAction = &DATA.expectedAiActions[battlerId][DATA.trial.aiActionsPlayed[battlerId]];
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

static s32 TryExp(s32 i, s32 n, enum BattlerId battlerId, u32 oldExp, u32 newExp)
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

void TestRunner_Battle_RecordExp(enum BattlerId battlerId, u32 oldExp, u32 newExp)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryExp(DATA.trial.queuedEvent, event->groupSize, battlerId, oldExp, newExp) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_EXP_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(event->sourceLineOffset);
            switch (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.exp.type)
            {
            case EXP_EVENT_NEW_EXP:
                Test_MgbaPrintf("%s:%d: Did you mean: EXPERIENCE_BAR(%s, exp: %d)", filename, line, BattlerIdentifier(battlerId), newExp);
                break;
            case EXP_EVENT_DELTA_EXP:
                if (DATA.queuedEvents[DATA.queuedEventsFailIndex].as.exp.address == 0)
                    Test_MgbaPrintf("%s:%d: Did you mean: EXPERIENCE_BAR(%s)", filename, line, BattlerIdentifier(battlerId));
                else
                    Test_MgbaPrintf("%s:%d: Did you mean: EXPERIENCE_BAR(%s, captureGainedExp: %d)", filename, line, BattlerIdentifier(battlerId), oldExp - newExp);
                break;
            }
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryExp(queuedEvent, event->groupSize, battlerId, oldExp, newExp)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched EXPERIENCE_BAR", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryExp(queuedEvent, event->groupSize, battlerId, oldExp, newExp) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
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
        // Test_MgbaPrintf("Looking for: %S Found: %S\n", event->pattern, string); // Useful for debugging.
        for (j = k = 0; ; j++, k++)
        {
            if (event->pattern[k] == CHAR_SPACE)
            {
                switch (string[j])
                {
                case CHAR_SPACE:
                case CHAR_NBSP:
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

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryMessage(DATA.trial.queuedEvent, event->groupSize, string) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_MESSAGE_EVENT)
        {
            // Print "similar" messages as computed by the Dice-Sorensen
            // coefficient, letter-wise. Bigrams would likely be more
            // accurate, but more complex to compute.
            // TODO: Compute (and cache) the pattern's counts when the test
            // is re-run, rather than on each message.
            const u8 *pattern = DATA.queuedEvents[DATA.queuedEventsFailIndex].as.message.pattern;
            u32 expectedLength = 0;
            u8 expectedCount[256] = { 0 };
            for (u32 i = 0; pattern[i] != EOS; i++)
            {
                expectedLength++;
                expectedCount[pattern[i]]++;
            }

            u32 gotLength = 0;
            u8 gotCount[256] = { 0 };
            for (u32 i = 0; string[i] != EOS; i++)
            {
                switch (string[i])
                {
                case CHAR_SPACE:
                case CHAR_NBSP:
                case CHAR_PROMPT_SCROLL:
                case CHAR_PROMPT_CLEAR:
                case CHAR_NEWLINE:
                    break;
                default:
                    gotLength++;
                    gotCount[string[i]]++;
                    break;
                }
            }

            u32 intersection = 0;
            for (u32 i = 0; i < 256; i++)
                intersection += min(expectedCount[i], gotCount[i]);

            uq4_12_t dsc = UQ_4_12(2 * intersection) / (expectedLength + gotLength);

            // NOTE: 0.7 is a totally arbitrary threshold.
            if (dsc > UQ_4_12(0.7))
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);

                Test_MgbaPrintf("%s:%d: Did you mean: MESSAGE(\"%S\")", filename, line, string);
            }
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryMessage(queuedEvent, event->groupSize, string)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched MESSAGE", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryMessage(queuedEvent, event->groupSize, string) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryStatus(s32 i, s32 n, enum BattlerId battlerId, u32 status1)
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

void TestRunner_Battle_RecordStatus1(enum BattlerId battlerId, u32 status1)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryStatus(DATA.trial.queuedEvent, event->groupSize, battlerId, status1) != -1)
        {
            DATA.trial.queuedEvent += event->groupSize;
        }
        else if (DATA.trial.queuedEvent == DATA.queuedEventsFailIndex
              && DATA.queuedEvents[DATA.queuedEventsFailIndex].type == QUEUED_STATUS_EVENT)
        {
            const char *filename = gTestRunnerState.test->filename;
            u32 line = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
            if (status1 == STATUS1_NONE)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, none: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_SLEEP)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, sleep: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_POISON)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, poison: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_BURN)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, burn: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_FREEZE)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, freeze: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_PARALYSIS)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, paralysis: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_TOXIC_POISON)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, badPoison: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else if (status1 & STATUS1_FROSTBITE)
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, frostbite: TRUE)", filename, line, BattlerIdentifier(battlerId));
            else
                Test_MgbaPrintf("%s:%d: Did you mean: STATUS_ICON(%s, status1: %d)", filename, line, BattlerIdentifier(battlerId), status1);
        }
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryStatus(queuedEvent, event->groupSize, battlerId, status1)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                    gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched STATUS_ICON", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryStatus(queuedEvent, event->groupSize, battlerId, status1) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static s32 TryCatchChance(s32 i, s32 n, u32 catchChance)
{
    struct QueuedCaptureEvent *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_CATCH_CHANCE_EVENT)
            continue;

        event = &DATA.queuedEvents[i].as.capture;
        *(u32 *)(u32)(event->address) = catchChance;
        return i;
    }
    return -1;
}

void TestRunner_Battle_RecordCatchChance(u32 catchChance)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryCatchChance(DATA.trial.queuedEvent, event->groupSize, catchChance) != -1)
            DATA.trial.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryCatchChance(DATA.trial.queuedEvent, event->groupSize, catchChance)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched CATCH CHANCE", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryCatchChance(DATA.trial.queuedEvent, event->groupSize, catchChance) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

static const char *const sEventTypeMacros[] =
{
    [QUEUED_ABILITY_POPUP_EVENT] = "ABILITY_POPUP",
    [QUEUED_ANIMATION_EVENT] = "ANIMATION",
    [QUEUED_HP_EVENT] = "HP_BAR",
    [QUEUED_SUB_HIT_EVENT] = "SUB_HIT",
    [QUEUED_EXP_EVENT] = "EXPERIENCE_BAR",
    [QUEUED_MESSAGE_EVENT] = "MESSAGE",
    [QUEUED_STATUS_EVENT] = "STATUS_ICON",
    [QUEUED_CATCH_CHANCE_EVENT] = "CATCH_CHANCE",
    [QUEUED_EFFECTIVENESS_EVENT] = "EFFECTIVENESS_SE",
    [QUEUED_ITEM_POPUP_EVENT] = "ITEM_POPUP",
};

static void TearDownBattle(void)
{
    // Zero out the parties, data in them could potentially carry over
    for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        ZeroPartyMons(gParties[trainer]);
    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);

    // Set Battle Controllers to BATTLE_CONTROLLER_NONE
    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerBattleController[i] = BATTLE_CONTROLLER_NONE;
    }

    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
    FreeAllWindowBuffers();
    gMain.inBattle = FALSE; // Necessary else some tests report incorrect results when running in same thread as an EXPECT_FAIL test
}

void TestRunner_Battle_AfterLastTurn(void)
{
    const struct BattleTest *test = GetBattleTest();

    if (DATA.turns - 1 != DATA.trial.lastActionTurn)
    {
        const char *filename = gTestRunnerState.test->filename;
        Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: %d TURNs specified, but %d ran", filename, SourceLine(0), DATA.turns, DATA.trial.lastActionTurn + 1);
    }

    while (DATA.trial.queuedEvent < DATA.queuedEventsCount
        && DATA.queuedEvents[DATA.trial.queuedEvent].groupType == QUEUE_GROUP_NONE_OF)
    {
        DATA.trial.queuedEvent += DATA.queuedEvents[DATA.trial.queuedEvent].groupSize;
    }
    if (DATA.trial.queuedEvent != DATA.queuedEventsCount)
    {
        bool32 mayRerun = gTestRunnerHeadless && !STATE->trials;
        if (mayRerun && DATA.queuedEventsFailIndex == MAX_QUEUED_EVENTS)
        {
            // First failure, re-run with logging enabled.
            // TODO: Track total battle tests and total re-runs, and
            // disable re-runs if they're too common (to fail faster).
            DATA.queuedEventsFailIndex = DATA.trial.queuedEvent;
            gMain.savedCallback = StartBattle; // Re-run once battle exits.
            return;
        }
        else if (!mayRerun || DATA.queuedEventsFailIndex == DATA.trial.queuedEvent)
        {
            const char *filename = gTestRunnerState.test->filename;
            const struct QueuedEvent *event = &DATA.queuedEvents[DATA.trial.queuedEvent];
            u32 line = SourceLine(event->sourceLineOffset);
            if (gTestRunnerState.expectedFailState == EXPECT_FAIL_SCENE_OPEN)
                gTestRunnerState.expectedFailState = EXPECT_FAIL_SUCCESS;
            DATA.queuedEventsFailIndex = MAX_QUEUED_EVENTS; // For 'handleExitWithResult'.
            const char *macro = sEventTypeMacros[event->type];
            switch (event->type)
            {
            case QUEUED_MESSAGE_EVENT:
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Unmatched MESSAGE(\"%S\")", filename, line, event->as.message.pattern);
            // TODO: Handle all queued event types explicitly.
            default:
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Unmatched %s", filename, line, macro);
            }
        }
    }
    if (DATA.queuedEventsFailIndex != MAX_QUEUED_EVENTS
     && DATA.queuedEventsFailIndex != DATA.trial.queuedEvent)
    {
        const char *filename = gTestRunnerState.test->filename;
        u32 expectedLine = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
        const char *expectedMacro = sEventTypeMacros[DATA.queuedEvents[DATA.queuedEventsFailIndex].type];
        u32 gotLine = SourceLine(DATA.queuedEvents[DATA.trial.queuedEvent].sourceLineOffset);
        const char *gotMacro = sEventTypeMacros[DATA.queuedEvents[DATA.trial.queuedEvent].type];
        DATA.queuedEventsFailIndex = MAX_QUEUED_EVENTS; // For 'handleExitWithResult'.
        Test_ExitWithResult(TEST_RESULT_FLAKY, expectedLine, "%s:%d: Expected unmatched %s, but got %s at %s:%d", filename, expectedLine, expectedMacro, gotMacro, filename, gotLine);
    }

    STATE->runThen = TRUE;
    STATE->runFinally = STATE->runParameter + 1 == STATE->parameters && STATE->runTrial + 1 >= STATE->trials;
    InvokeTestFunction(test);
    STATE->runThen = FALSE;
    STATE->runFinally = FALSE;
}

static void CB2_BattleTest_NextParameter(void)
{
    TestRunner_CheckMemory();
    if (++STATE->runParameter >= STATE->parameters)
    {
        SetMainCallback2(CB2_TestRunner);
        ClearFlagAfterTest();
        ClearVarAfterTest();
    }
    else
    {
        STATE->trials = 0;
        STATE->didRunRandomly = FALSE;
        BattleTest_Run(gTestRunnerState.test->data);
    }
}

static inline rng_value_t MakeRngValue(const u16 seed)
{
    int i;
    rng_value_t result = {0, 0, seed, 1};
    for (i = 0; i < 16; i++)
    {
            _SFC32_Next(&result);
    }
    return result;
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
        DATA.recordedBattle.rngSeed = MakeRngValue(STATE->runTrial);
        memset(&DATA.trial, 0, sizeof(DATA.trial));
        ResetTestInventory();
        SetVariablesForRecordedBattle(&DATA.recordedBattle);
        SetMainCallback2(CB2_InitBattle);
    }
    else
    {
        if (STATE->rngTag && !STATE->didRunRandomly && STATE->expectedRatio != Q_4_12(0.0) && STATE->expectedRatio != Q_4_12(1.0))
            Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%s:%d: PASSES_RANDOMLY specified but no Random* call with that tag executed", gTestRunnerState.test->filename, SourceLine(0));

        // This is a tolerance of +/- ~2%.
        if (abs(STATE->observedRatio - STATE->expectedRatio) <= Q_4_12(0.02))
            gTestRunnerState.result = TEST_RESULT_PASS;
        else
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: Expected %q passes/successes, observed %q", gTestRunnerState.test->filename, SourceLine(0), STATE->expectedRatio, STATE->observedRatio);
    }
}

static void BattleTest_TearDown(void *data)
{
    // Free resources that aren't cleaned up when the battle was
    // aborted unexpectedly.
    ClearFlagAfterTest();
    ClearVarAfterTest();
    TestFreeConfigData();
    if (!STATE->hasTornDownBattle)
    {
        TearDownBattle();
        STATE->hasTornDownBattle = TRUE;
    }
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
     && result != TEST_RESULT_FLAKY
     && STATE->runTrial < STATE->trials)
    {
        SetMainCallback2(CB2_BattleTest_NextTrial);
        return TRUE;
    }
    else if (DATA.queuedEventsFailIndex != MAX_QUEUED_EVENTS)
    {
        const char *filename = gTestRunnerState.test->filename;
        u32 expectedLine = SourceLine(DATA.queuedEvents[DATA.queuedEventsFailIndex].sourceLineOffset);
        const char *expectedMacro = sEventTypeMacros[DATA.queuedEvents[DATA.queuedEventsFailIndex].type];
        Test_MgbaPrintf("%s:%d: Expected unmatched %s, but got...", filename, expectedLine, expectedMacro);
        gTestRunnerState.result = TEST_RESULT_FLAKY;
        return FALSE;
    }
    else
    {
        return FALSE;
    }
}

void Randomly(u32 sourceLine, u32 passes, u32 trials, struct RandomlyContext ctx)
{
    const struct BattleTest *test = GetBattleTest();
    INVALID_IF(STATE->trials != 0, "PASSES_RANDOMLY can only be used once per test");
    INVALID_IF(test->resultsSize > 0 && STATE->parametersCount > 1, "PASSES_RANDOMLY is incompatible with results");
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
        const rng_value_t defaultSeed = RNG_SEED_DEFAULT;
        INVALID_IF(RngSeedNotDefault(&DATA.recordedBattle.rngSeed), "RNG seed already set");
        STATE->trials = 50;
        STATE->trialRatio = Q_4_12(1) / STATE->trials;
        DATA.recordedBattle.rngSeed = defaultSeed;
    }
}

void RNGSeed_(u32 sourceLine, rng_value_t seed)
{
    INVALID_IF(RngSeedNotDefault(&DATA.recordedBattle.rngSeed), "RNG seed already set");
    DATA.recordedBattle.rngSeed = seed;
}

void AIFlags_(u32 sourceLine, u64 flags)
{
    INVALID_IF(!IsAITest(), "AI_FLAGS is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, AI_TWELVES_BATTLE_TEST, and AI_TWO_VS_ONE_TEST");
    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        DATA.recordedBattle.AI_scripts[i] = flags;
    }
    DATA.hasAI = TRUE;
}

void BattlerAIFlags_(u32 sourceLine, struct BattlePokemon *battler, u64 flags)
{
    INVALID_IF(!IsAITest(), "AI_FLAGS is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, AI_TWELVES_BATTLE_TEST, and AI_TWO_VS_ONE_TEST");
    enum BattlerId battlerId = battler - gBattleMons;
    DATA.recordedBattle.AI_scripts[battlerId] |= flags;
    DATA.hasAI = TRUE;
}

void AILogScores(u32 sourceLine)
{
    INVALID_IF(!IsAITest(), "AI_LOG is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, AI_TWELVES_BATTLE_TEST, and AI_TWO_VS_ONE_TEST");
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
    .randomUniform = BattleTest_RandomUniform,
    .randomWeightedArray = BattleTest_RandomWeightedArray,
    .randomElementArray = BattleTest_RandomElementArray,
};

void SetFlagForTest(u32 sourceLine, u16 flagId)
{
    INVALID_IF(DATA.flagId != 0, "FLAG can only be set once per test");
    DATA.flagId = flagId;
    FlagSet(flagId);
}

void SetVarForTest(u32 sourceLine, u16 varId, u16 value)
{
    INVALID_IF(DATA.varId != 0, "VAR can only be set once per test");
    DATA.varId = varId;
    VarSet(varId, value);
}

void TestSetConfig(u32 sourceLine, enum ConfigTag configTag, u32 value)
{
    INVALID_IF(!STATE->runGiven, "WITH_CONFIG outside of GIVEN");
    SetConfig(configTag, value);
}

void TieBreakScore(u32 sourceLine, enum RandomTag rngTag, enum ScoreTieResolution scoreTieRes, u32 value)
{
    INVALID_IF((rngTag != RNG_AI_SCORE_TIE_DOUBLES_MOVE && rngTag != RNG_AI_SCORE_TIE_SINGLES), "TIE_BREAK_SCORE requires RNG_AI_SCORE_TIE_SINGLES or RNG_AI_SCORE_TIE_DOUBLES_MOVE");
    DATA.scoreTieResolution = scoreTieRes;
    DATA.scoreTieTag = rngTag;
    if (scoreTieRes == SCORE_TIE_CHOSEN)
        DATA.scoreTieOverride = value;
}

void TieBreakTarget(u32 sourceLine, enum TargetTieResolution targetTieRes, u32 value)
{
    DATA.targetTieResolution = targetTieRes;
    if (targetTieRes == TARGET_TIE_CHOSEN)
        DATA.targetTieOverride = value;
}

void ClearFlagAfterTest(void)
{
    if (DATA.flagId != 0)
    {
        FlagClear(DATA.flagId);
        DATA.flagId = 0;
    }
}

void ClearVarAfterTest(void)
{
    if (DATA.varId != 0)
    {
        VarSet(DATA.varId, 0);
        DATA.varId = 0;
    }
}

void OpenPokemon(u32 sourceLine, enum BattleTrainer trainer, enum Species species)
{
    s32 i, data;
    u8 *partySize;
    struct Pokemon *party;
    INVALID_IF(species >= SPECIES_EGG, "Invalid species: %d", species);
    ASSUMPTION_FAIL_IF(!IsSpeciesEnabled(species), "Species disabled: %d", species);

    partySize = &DATA.partySizes[trainer];
    party = DATA.recordedBattle.parties[trainer];

    INVALID_IF(*partySize >= PARTY_SIZE, "Too many Pokemon in party");
    DATA.battlerParty = trainer;
    DATA.currentPartyIndex = *partySize;
    DATA.currentMon = &party[DATA.currentPartyIndex];
    DATA.gender = 0xFF; // Male
    DATA.nature = NATURE_HARDY;
    (*partySize)++;

    CreateMon(DATA.currentMon, species, 100, 0, OTID_STRUCT_PRESET(0));
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        data = MOVE_NONE;
        SetMonData(DATA.currentMon, MON_DATA_MOVE1 + i, &data);
        data = 0x7F; // Max PP possible
        SetMonData(DATA.currentMon, MON_DATA_PP1 + i, &data);
    }
    data = 0;
    if (B_FRIENDSHIP_BOOST) // This way, we avoid the boost affecting tests unless explicitly stated.
        SetMonData(DATA.currentMon, MON_DATA_FRIENDSHIP, &data);
    CalculateMonStats(DATA.currentMon);
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
    u32 data;
    INVALID_IF(DATA.hasExplicitSpeeds && !(DATA.explicitSpeeds[DATA.battlerParty] & (1 << DATA.currentPartyIndex)), "Speed required");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (i == DATA.battlerParty
         && DATA.currentMonIndexes[i] == DATA.currentPartyIndex)
        {
            INVALID_IF(GetMonData(DATA.currentMon, MON_DATA_HP) == 0, "Battlers cannot be fainted");
        }
    }
    UpdateMonPersonality(&DATA.currentMon->box, GenerateNature(DATA.nature, DATA.gender % NUM_NATURES) | DATA.gender);
    data = DATA.isShiny;
    SetMonData(DATA.currentMon, MON_DATA_IS_SHINY, &data);
    DATA.currentMon = NULL;
}

static void SetGimmick(u32 sourceLine, enum BattleTrainer trainer, u32 partyIndex, enum Gimmick gimmick)
{
    enum Gimmick currentGimmick = DATA.chosenGimmick[trainer][partyIndex];
    if (!((currentGimmick == GIMMICK_ULTRA_BURST && gimmick == GIMMICK_Z_MOVE)
       || (currentGimmick == GIMMICK_Z_MOVE && gimmick == GIMMICK_ULTRA_BURST)))
    {
        INVALID_IF(currentGimmick != GIMMICK_NONE && currentGimmick != gimmick, "Cannot set %s because %s already set", sGimmickIdentifiers[gimmick], sGimmickIdentifiers[currentGimmick]);
    }
    DATA.chosenGimmick[trainer][partyIndex] = gimmick;
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

void Ability_(u32 sourceLine, enum Ability ability)
{
    s32 i;
    enum Species species;
    const struct SpeciesInfo *info;
    INVALID_IF(!DATA.currentMon, "Ability outside of PLAYER/OPPONENT");
    INVALID_IF(ability >= ABILITIES_COUNT, "Illegal ability id: %d", ability);
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
        DATA.forcedAbilities[DATA.battlerParty][DATA.currentPartyIndex] = ability;
    }
}

void Level_(u32 sourceLine, u32 level)
{
    // TODO: Preserve any explicitly-set stats.
    enum Species species = GetMonData(DATA.currentMon, MON_DATA_SPECIES);
    INVALID_IF(!DATA.currentMon, "Level outside of PLAYER/OPPONENT");
    INVALID_IF(level == 0 || level > MAX_LEVEL, "Illegal level: %d", level);
    SetMonData(DATA.currentMon, MON_DATA_LEVEL, &level);
    SetMonData(DATA.currentMon, MON_DATA_EXP, &gExperienceTables[gSpeciesInfo[species].growthRate][level]);
    gMain.inBattle = TRUE;
    CalculateMonStats(DATA.currentMon);
    gMain.inBattle = FALSE;
}

void MaxHP_(u32 sourceLine, u32 maxHP)
{
    INVALID_IF(!DATA.currentMon, "MaxHP outside of PLAYER/OPPONENT");
    INVALID_IF(maxHP == 0, "Illegal max HP: %d", maxHP);
    SetMonData(DATA.currentMon, MON_DATA_MAX_HP, &maxHP);
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_HP, &hyperTrainingFlag);
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
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_ATK, &hyperTrainingFlag);
}

void Defense_(u32 sourceLine, u32 defense)
{
    INVALID_IF(!DATA.currentMon, "Defense outside of PLAYER/OPPONENT");
    INVALID_IF(defense == 0, "Illegal defense: %d", defense);
    SetMonData(DATA.currentMon, MON_DATA_DEF, &defense);
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_DEF, &hyperTrainingFlag);
}

void SpAttack_(u32 sourceLine, u32 spAttack)
{
    INVALID_IF(!DATA.currentMon, "SpAttack outside of PLAYER/OPPONENT");
    INVALID_IF(spAttack == 0, "Illegal special attack: %d", spAttack);
    SetMonData(DATA.currentMon, MON_DATA_SPATK, &spAttack);
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_SPATK, &hyperTrainingFlag);
}

void SpDefense_(u32 sourceLine, u32 spDefense)
{
    INVALID_IF(!DATA.currentMon, "SpDefense outside of PLAYER/OPPONENT");
    INVALID_IF(spDefense == 0, "Illegal special defense: %d", spDefense);
    SetMonData(DATA.currentMon, MON_DATA_SPDEF, &spDefense);
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_SPDEF, &hyperTrainingFlag);
}

void Speed_(u32 sourceLine, u32 speed)
{
    INVALID_IF(!DATA.currentMon, "Speed outside of PLAYER/OPPONENT");
    INVALID_IF(speed == 0, "Illegal speed: %d", speed);
    SetMonData(DATA.currentMon, MON_DATA_SPEED, &speed);
    bool32 hyperTrainingFlag = TRUE;
    SetMonData(DATA.currentMon, MON_DATA_HYPER_TRAINED_SPEED, &hyperTrainingFlag);
    DATA.hasExplicitSpeeds = TRUE;
    DATA.explicitSpeeds[DATA.battlerParty] |= 1 << DATA.currentPartyIndex;
}

void HPIV_(u32 sourceLine, u32 hpIV)
{
    INVALID_IF(!DATA.currentMon, "HP IV outside of PLAYER/OPPONENT");
    INVALID_IF(hpIV > MAX_PER_STAT_IVS, "Illegal HP IV: %d", hpIV);
    SetMonData(DATA.currentMon, MON_DATA_HP_IV, &hpIV);
}

void AttackIV_(u32 sourceLine, u32 attackIV)
{
    INVALID_IF(!DATA.currentMon, "Attack IV outside of PLAYER/OPPONENT");
    INVALID_IF(attackIV > MAX_PER_STAT_IVS, "Illegal attack IV: %d", attackIV);
    SetMonData(DATA.currentMon, MON_DATA_ATK_IV, &attackIV);
}

void DefenseIV_(u32 sourceLine, u32 defenseIV)
{
    INVALID_IF(!DATA.currentMon, "Defense IV outside of PLAYER/OPPONENT");
    INVALID_IF(defenseIV > MAX_PER_STAT_IVS, "Illegal defense IV: %d", defenseIV);
    SetMonData(DATA.currentMon, MON_DATA_DEF_IV, &defenseIV);
}

void SpAttackIV_(u32 sourceLine, u32 spAttackIV)
{
    INVALID_IF(!DATA.currentMon, "SpAttack IV outside of PLAYER/OPPONENT");
    INVALID_IF(spAttackIV > MAX_PER_STAT_IVS, "Illegal special attack IV: %d", spAttackIV);
    SetMonData(DATA.currentMon, MON_DATA_SPATK_IV, &spAttackIV);
}

void SpDefenseIV_(u32 sourceLine, u32 spDefenseIV)
{
    INVALID_IF(!DATA.currentMon, "SpDefense IV outside of PLAYER/OPPONENT");
    INVALID_IF(spDefenseIV > MAX_PER_STAT_IVS, "Illegal special defense IV: %d", spDefenseIV);
    SetMonData(DATA.currentMon, MON_DATA_SPDEF_IV, &spDefenseIV);
}

void SpeedIV_(u32 sourceLine, u32 speedIV)
{
    INVALID_IF(!DATA.currentMon, "Speed IV outside of PLAYER/OPPONENT");
    INVALID_IF(speedIV > MAX_PER_STAT_IVS, "Illegal speed IV: %d", speedIV);
    SetMonData(DATA.currentMon, MON_DATA_SPEED_IV, &speedIV);
}

void Item_(u32 sourceLine, u32 item)
{
    INVALID_IF(!DATA.currentMon, "Item outside of PLAYER/OPPONENT");
    INVALID_IF(item >= ITEMS_COUNT, "Illegal item: %d", item);
    SetMonData(DATA.currentMon, MON_DATA_HELD_ITEM, &item);
    switch (GetItemHoldEffect(item))
    {
    case HOLD_EFFECT_MEGA_STONE:
        SetGimmick(sourceLine, DATA.battlerParty, DATA.currentPartyIndex, GIMMICK_MEGA);
        break;
    case HOLD_EFFECT_Z_CRYSTAL:
        SetGimmick(sourceLine, DATA.battlerParty, DATA.currentPartyIndex, GIMMICK_Z_MOVE);
        break;
    default:
        break;
    }
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
        u32 pp = GetMovePP(moves[i]);
        SetMonData(DATA.currentMon, MON_DATA_PP1 + i, &pp);
    }
    DATA.explicitMoves[DATA.battlerParty] |= 1 << DATA.currentPartyIndex;
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
    DATA.explicitMoves[DATA.battlerParty] |= 1 << DATA.currentPartyIndex;
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
    INVALID_IF(!DATA.currentMon, "OTName outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_OT_NAME, &otName);
}

void DynamaxLevel_(u32 sourceLine, s16 dynamaxLevel)
{
    INVALID_IF(!DATA.currentMon, "DynamaxLevel outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_DYNAMAX_LEVEL, &dynamaxLevel);
    if (dynamaxLevel >= 0)
        SetGimmick(sourceLine, DATA.battlerParty, DATA.currentPartyIndex, GIMMICK_DYNAMAX);
}

void GigantamaxFactor_(u32 sourceLine, bool32 gigantamaxFactor)
{
    INVALID_IF(!DATA.currentMon, "GigantamaxFactor outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_GIGANTAMAX_FACTOR, &gigantamaxFactor);
    SetGimmick(sourceLine, DATA.battlerParty, DATA.currentPartyIndex, GIMMICK_DYNAMAX);
}

void TeraType_(u32 sourceLine, enum Type teraType)
{
    INVALID_IF(!DATA.currentMon, "TeraType outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_TERA_TYPE, &teraType);
    SetGimmick(sourceLine, DATA.battlerParty, DATA.currentPartyIndex, GIMMICK_TERA);
}

void Shadow_(u32 sourceLine, bool32 isShadow)
{
    INVALID_IF(!DATA.currentMon, "Shadow outside of PLAYER/OPPONENT");
    SetMonData(DATA.currentMon, MON_DATA_IS_SHADOW, &isShadow);
}

void Shiny_(u32 sourceLine, bool32 isShiny)
{
    INVALID_IF(!DATA.currentMon, "Shiny outside of PLAYER/OPPONENT");
    DATA.isShiny = isShiny;
}

void Environment_(u32 sourceLine, u32 environment)
{
    INVALID_IF(DATA.forcedEnvironment, "Environment is already set");
    INVALID_IF(environment >= BATTLE_ENVIRONMENT_COUNT, "Illegal environment: %d", environment);
    DATA.forcedEnvironment = environment + 1;
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

static const char *BattlerIdentifier(enum BattlerId battlerId)
{
    const struct BattleTest *test = GetBattleTest();
    switch (test->type)
    {
    case BATTLE_TEST_SINGLES:
    case BATTLE_TEST_WILD:
    case BATTLE_TEST_GHOST:
    case BATTLE_TEST_AI_SINGLES:
        return sBattlerIdentifiersSingles[battlerId];
    case BATTLE_TEST_DOUBLES:
    case BATTLE_TEST_AI_DOUBLES:
    case BATTLE_TEST_MULTI:
    case BATTLE_TEST_AI_MULTI:
    case BATTLE_TEST_TWO_VS_ONE:
    case BATTLE_TEST_AI_TWO_VS_ONE:
    case BATTLE_TEST_ONE_VS_TWO:
    case BATTLE_TEST_AI_ONE_VS_TWO:
        return sBattlerIdentifiersDoubles[battlerId];
    }
    return "<unknown>";
}

static void PushBattlerAction(u32 sourceLine, enum BattlerId battlerId, u32 actionType, u32 byte)
{
    u32 recordIndex = DATA.recordIndexes[battlerId]++;
    if (recordIndex >= BATTLER_RECORD_SIZE)
        Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "Too many actions");
    DATA.battleRecordTypes[battlerId][recordIndex] = actionType;
    DATA.battleRecordTurnNumbers[battlerId][recordIndex] = DATA.turns;
    DATA.battleRecordSourceLineOffsets[battlerId][recordIndex] = SourceLineOffset(sourceLine);
    DATA.recordedBattle.battleRecord[battlerId][recordIndex] = byte;
}

void TestRunner_Battle_CheckBattleRecordActionType(enum BattlerId battlerId, u32 recordIndex, u32 actionType)
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
                Test_ExitWithResult(TEST_RESULT_INVALID, line, "%s:%d: Illegal MOVE", filename, line);
            }
        }
        Test_ExitWithResult(TEST_RESULT_INVALID, SourceLine(0), "%s:%d: Illegal MOVE", filename, SourceLine(0));
    }

    if (DATA.battleRecordTypes[battlerId][recordIndex] != RECORDED_BYTE)
    {
        DATA.trial.lastActionTurn = gBattleResults.battleTurnCounter;

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
                if (gBattleResults.battleTurnCounter != DATA.battleRecordTurnNumbers[battlerId][recordIndex])
                {
                    switch (DATA.battleRecordTypes[battlerId][recordIndex])
                    {
                    case RECORDED_PARTY_INDEX:
                        Test_ExitWithResult(TEST_RESULT_INVALID, line, "%s:%d: %s not required (is the send out random?)", filename, line, actualMacro);
                    default:
                        Test_ExitWithResult(TEST_RESULT_INVALID, line, "%s:%d: %s not required", filename, line, actualMacro);
                    }
                }

                switch (actionType)
                {
                case RECORDED_ACTION_TYPE:
                    Test_ExitWithResult(TEST_RESULT_INVALID, line, "%s:%d: Expected MOVE/SWITCH, got %s", filename, line, actualMacro);
                case RECORDED_PARTY_INDEX:
                    Test_ExitWithResult(TEST_RESULT_INVALID, line, "%s:%d: Expected SEND_OUT, got %s", filename, line, actualMacro);
                }
            }

            Test_ExitWithResult(TEST_RESULT_ERROR, line, "%s:%d: Illegal battle record", filename, line);
        }
    }
    else
    {
        if (DATA.trial.lastActionTurn == gBattleResults.battleTurnCounter)
        {
            const char *filename = gTestRunnerState.test->filename;
            Test_ExitWithResult(TEST_RESULT_FAIL, SourceLine(0), "%s:%d: TURN %d incomplete", filename, SourceLine(0), gBattleResults.battleTurnCounter + 1);
        }
    }
}

void OpenTurn(u32 sourceLine)
{
    INVALID_IF(DATA.turnState != TURN_CLOSED, "Nested TURN");
    if (DATA.turns == MAX_TURNS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: TURN exceeds MAX_TURNS", gTestRunnerState.test->filename, sourceLine);
    DATA.turnState = TURN_OPEN;
    DATA.actionBattlers = 0x00;
    DATA.moveBattlers = 0x00;
}

static void SetSlowerThan(enum BattlerId battlerId)
{
    s32 i;
    u32 slowerThan = 0;
    enum BattleTrainer trainer;
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (i == battlerId)
            continue;
        if (DATA.moveBattlers & (1 << i))
        {
            trainer = Test_GetBattlerTrainer(i);
            slowerThan |= (1u << ((6 * trainer) + DATA.currentMonIndexes[i]));
        }
    }
    DATA.slowerThan[Test_GetBattlerTrainer(battlerId)][DATA.currentMonIndexes[battlerId]] |= slowerThan;
}

static void SetAiActionToPass(u32 sourceLine, enum BattlerId battlerId)
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
        { // Multi test partner trainers want setting to RecordedPartner controller if no move set in this case; EXPECT_XXXX will set to PlayerPartner.
            if (IsAITest() && (i & BIT_SIDE) == B_SIDE_OPPONENT) // If Move was not specified, allow any move used.
                SetAiActionToPass(sourceLine, i);
            else
                Move(sourceLine, &gBattleMons[i], (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
        }
    }
    DATA.turnState = TURN_CLOSED;
    DATA.turns++;
}

static struct Pokemon *CurrentMon(enum BattlerId battlerId)
{
    enum BattleTrainer trainer = Test_GetBattlerTrainer(battlerId);
    struct Pokemon *party = DATA.recordedBattle.parties[trainer];

    return &party[DATA.currentMonIndexes[battlerId]];
}

s32 MoveGetTarget(enum BattlerId battlerId, enum Move moveId, struct MoveContext *ctx, u32 sourceLine)
{
    s32 target = battlerId;
    if (ctx->explicitTarget)
    {
        target = ctx->target - gBattleMons;
    }
    else
    {
        enum MoveTarget moveTarget = GetMoveTarget(moveId);
        switch (moveTarget)
        {
        case TARGET_RANDOM:
        case TARGET_BOTH:
        case TARGET_DEPENDS:
        case TARGET_FOES_AND_ALLY:
        case TARGET_OPPONENTS_FIELD:
        case TARGET_USER:
        case TARGET_ALL_BATTLERS:
        case TARGET_FIELD:
        case TARGET_USER_AND_ALLY:
        case TARGET_ALLY:
            break;
        case TARGET_SELECTED:
        case TARGET_SMART:
        case TARGET_OPPONENT:
            // In AI Doubles not specified target allows any target for EXPECT_MOVE.
            if (!IsAIDoublesTest())
            {
                INVALID_IF(STATE->battlersCount > 2, "%S requires explicit target", GetMoveName(moveId));
            }
            break;
        default:
            // In AI Doubles not specified target allows any target for EXPECT_MOVE.
            if (!IsAIDoublesTest())
            {
                INVALID("%S requires explicit target", GetMoveName(moveId));
            }
            break;
        }

        target = GetDefaultSelectionTarget(battlerId, moveTarget);
    }
    return target;
}

void MoveGetIdAndSlot(enum BattlerId battlerId, struct MoveContext *ctx, u32 *moveId, u32 *moveSlot, u32 sourceLine)
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
                // TURN {} defaults to Celebrate; allow it even when a mon has explicit moves set.
                INVALID_IF(ctx->move != MOVE_CELEBRATE
                           && (DATA.explicitMoves[Test_GetBattlerTrainer(battlerId)] & (1 << DATA.currentMonIndexes[battlerId])),
                           "Missing explicit %S", GetMoveName(ctx->move));
                SetMonData(mon, MON_DATA_MOVE1 + i, &ctx->move);
                u32 pp = GetMovePP(ctx->move);
                SetMonData(mon, MON_DATA_PP1 + i, &pp);
                *moveSlot = i;
                *moveId = ctx->move;
                INVALID_IF(GetMovePP(ctx->move) == 0, "%S has 0 PP!", GetMoveName(ctx->move));
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

    if (ctx->explicitGimmick && ctx->gimmick != GIMMICK_NONE)
    {
        enum Item item = GetMonData(mon, MON_DATA_HELD_ITEM);
        enum HoldEffect holdEffect = GetItemHoldEffect(item);
        enum Species species = GetMonData(mon, MON_DATA_SPECIES);

        // Check invalid item usage.
        INVALID_IF(ctx->gimmick == GIMMICK_MEGA && holdEffect != HOLD_EFFECT_MEGA_STONE && species != SPECIES_RAYQUAZA, "Cannot Mega Evolve without a Mega Stone");
        INVALID_IF(ctx->gimmick == GIMMICK_Z_MOVE && holdEffect != HOLD_EFFECT_Z_CRYSTAL, "Cannot use a Z-Move without a Z-Crystal");
        INVALID_IF(ctx->gimmick == GIMMICK_Z_MOVE && GetItemSecondaryId(item) != GetMoveType(*moveId)
                   && GetSignatureZMove(*moveId, species, item) == MOVE_NONE
                   && *moveId != MOVE_PHOTON_GEYSER, // exception because test won't recognize Ultra Necrozma pre-Burst
                   "Cannot turn %S into a Z-Move with %S", GetMoveName(ctx->move), GetItemName(item));
        INVALID_IF(ctx->gimmick != GIMMICK_MEGA && holdEffect == HOLD_EFFECT_MEGA_STONE, "Cannot use another gimmick while holding a Mega Stone");
        INVALID_IF(ctx->gimmick != GIMMICK_Z_MOVE && ctx->gimmick != GIMMICK_ULTRA_BURST && holdEffect == HOLD_EFFECT_Z_CRYSTAL, "Cannot use another gimmick while holding a Z-Crystal");

        // Check multiple gimmick use.
        SetGimmick(sourceLine, Test_GetBattlerTrainer(battlerId), DATA.currentMonIndexes[battlerId], ctx->gimmick);
        *moveSlot |= RET_GIMMICK;
    }
}

u32 MoveGetFirstFainted(enum BattlerId battlerId)
{
    u32 i;
    enum BattleTrainer trainer = Test_GetBattlerTrainer(battlerId);
    struct Pokemon *party = DATA.recordedBattle.parties[trainer];
    u32 partySize = DATA.partySizes[trainer];

    // Loop through to find fainted battler.
    for (i = 0; i < partySize; ++i)
    {
        enum Species species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && GetMonData(&party[i], MON_DATA_HP) == 0)
        {
            return i;
        }
    }

    // Returns PARTY_SIZE if none found.
    return PARTY_SIZE;
}

void Move(u32 sourceLine, struct BattlePokemon *battler, struct MoveContext ctx)
{
    enum BattlerId battlerId = battler - gBattleMons;
    u32 moveId;
    u32 moveSlot;
    s32 target;
    bool32 requirePartyIndex = FALSE;

    INVALID_IF(DATA.turnState == TURN_CLOSED, "MOVE outside TURN");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "MOVE is not allowed for opponent in AI tests. Use EXPECT_MOVE instead");

    MoveGetIdAndSlot(battlerId, &ctx, &moveId, &moveSlot, sourceLine);
    target = MoveGetTarget(battlerId, moveId, &ctx, sourceLine);

    if (GetMoveEffect(moveId) == EFFECT_REVIVAL_BLESSING)
        requirePartyIndex = MoveGetFirstFainted(battlerId) != PARTY_SIZE;

    // Check party menu moves.
    INVALID_IF(requirePartyIndex && !ctx.explicitPartyIndex, "%S requires explicit party index", GetMoveName(moveId));
    INVALID_IF(requirePartyIndex && ctx.partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], \
                "MOVE to invalid party index");

    if (ctx.explicitHit)
        DATA.battleRecordTurns[DATA.turns][battlerId].hit = 1 + ctx.hit;
    if (ctx.explicitCriticalHit)
        DATA.battleRecordTurns[DATA.turns][battlerId].criticalHit = 1 + ctx.criticalHit;
    if (ctx.explicitSecondaryEffect)
        DATA.battleRecordTurns[DATA.turns][battlerId].secondaryEffect = 1 + ctx.secondaryEffect;
    if (ctx.explicitRNG)
        DATA.battleRecordTurns[DATA.turns][battlerId].rng = ctx.rng;

    u32 shellSideArmCount = 0;
    for (u32 i = 0; i < STATE->battlersCount; i++)
    {
        if (DATA.battleRecordTurns[DATA.turns][i].rng.tag == RNG_SHELL_SIDE_ARM)
        {
            shellSideArmCount++;
            if (shellSideArmCount > 1)
                Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), " Tried to use fixed RNG for multiple Shell Side Arm moves in the same turn");
        }
    }

    if (!(DATA.actionBattlers & (1 << battlerId)))
    {
        PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_USE_MOVE);
    }

    if (!ctx.explicitAllowed || ctx.allowed)
    {
        PushBattlerAction(sourceLine, battlerId, RECORDED_MOVE_SLOT, moveSlot);
        PushBattlerAction(sourceLine, battlerId, RECORDED_MOVE_TARGET,
                          ctx.explicitTarget ? target : RECORDED_TARGET_DEFAULT);
    }

    if (ctx.explicitPartyIndex)
        PushBattlerAction(sourceLine, battlerId, RECORDED_PARTY_INDEX, ctx.partyIndex);

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
    enum BattlerId battlerId = battler - gBattleMons;
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
    enum BattlerId battlerId = battler - gBattleMons;
    u32 moveId;
    u32 moveSlot, id;
    s32 target;

    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_MOVE outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_MOVE is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, and AI_TWO_VS_ONE_TEST");
    MoveGetIdAndSlot(battlerId, ctx, &moveId, &moveSlot, sourceLine);
    target = MoveGetTarget(battlerId, moveId, ctx, sourceLine);

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_USE_MOVE;
    DATA.expectedAiActions[battlerId][id].moveSlots |= 1 << (moveSlot & ~RET_GIMMICK);
    DATA.expectedAiActions[battlerId][id].target = target;
    DATA.expectedAiActions[battlerId][id].explicitTarget = ctx->explicitTarget;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    DATA.expectedAiActions[battlerId][id].gimmick = ctx->explicitGimmick ? ctx->gimmick : GIMMICKS_COUNT;
    if (ctx->explicitNotExpected)
        DATA.expectedAiActions[battlerId][id].notMove = ctx->notExpected;

    DATA.actionBattlers |= 1 << battlerId;
    DATA.moveBattlers |= 1 << battlerId;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_TURN_OPEN;
}

void ExpectMove(u32 sourceLine, struct BattlePokemon *battler, struct MoveContext ctx)
{
    enum BattlerId battlerId = battler - gBattleMons;
    TryMarkExpectMove(sourceLine, battler, &ctx);
    DATA.expectedAiActionIndex[battlerId]++;
}

void ExpectSendOut(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i, id;
    enum BattlerId battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_SEND_OUT outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_SEND_OUT is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, AI_TWO_VS_ONE_TEST, and AI_ONE_VS_TWO_TEST");
    INVALID_IF(partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], "EXPECT_SEND_OUT to invalid party index");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF((DATA.currentMonIndexes[i] == partyIndex) && Test_BattlersShareParty(battlerId, i), "EXPECT_SEND_OUT to battler");
    }
    if (!(DATA.actionBattlers & (1 << battlerId)))
    { // Multi test partner trainers want setting to PlayerPartner controller even if no move set in this case.
        if (IsAITest() && (((battlerId & BIT_SIDE) == B_SIDE_OPPONENT) // If Move was not specified, allow any move used.
         || ((gBattleTypeFlags & BATTLE_TYPE_MULTI) && Test_GetBattlerTrainer(battlerId) == B_TRAINER_PARTNER)))
        {
            SetAiActionToPass(sourceLine, battlerId);
        }
        else
        {
            Move(sourceLine, battler, (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
        }
    }

    DATA.currentMonIndexes[battlerId] = partyIndex;
    DATA.actionBattlers |= 1 << battlerId;

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_SWITCH;
    DATA.expectedAiActions[battlerId][id].target = partyIndex;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    DATA.expectedAiActionIndex[battlerId]++;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_TURN_OPEN;
}

s32 GetAiMoveTargetForScoreCompare(enum BattlerId battlerId, enum Move moveId, struct MoveContext *ctx, u32 sourceLine)
{
    s32 target;

    // In Single Battles ai always targets the opposing mon.
    if (GetBattleTest()->type == BATTLE_TEST_AI_SINGLES)
    {
        target = (battlerId ^ BIT_SIDE);
    }
    else
    {
        // TODO: Fix ai targeting self in double battles.
        INVALID_IF(!ctx->explicitTarget, "%S requires explicit target for score comparison in doubles", GetMoveName(moveId));
        target = MoveGetTarget(battlerId, moveId, ctx, sourceLine);
    }
    return target;
}

void Score(u32 sourceLine, struct BattlePokemon *battler, u32 cmp, bool32 toValue, struct TestAIScoreStruct cmpCtx)
{
    u32 moveSlot1, moveSlot2;
    s32 i, target;
    struct MoveContext moveCtx = {0};
    enum BattlerId battlerId = battler - gBattleMons;
    s32 turn = DATA.turns;

    INVALID_IF(!IsAITest(), "SCORE_%s%s is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, & AI_TWO_VS_ONE_TEST", sCmpToStringTable[cmp], (toValue == TRUE) ? "_VAL" : "");

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
    enum BattlerId battlerId = battler - gBattleMons;
    u32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
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
    enum BattlerId battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SWITCH outside TURN");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], "SWITCH to invalid party index");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "SWITCH is not allowed for opponent in AI tests. Use EXPECT_SWITCH instead");

    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF((DATA.currentMonIndexes[i] == partyIndex) && Test_BattlersShareParty(battlerId, i), "SWITCH to battler");
    }

    PushBattlerAction(sourceLine, battlerId, RECORDED_ACTION_TYPE, B_ACTION_SWITCH);
    PushBattlerAction(sourceLine, battlerId, RECORDED_PARTY_INDEX, partyIndex);
    DATA.currentMonIndexes[battlerId] = partyIndex;

    DATA.actionBattlers |= 1 << battlerId;
}

void ExpectSwitch(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i, id;
    enum BattlerId battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "EXPECT_SWITCH outside TURN");
    INVALID_IF(!IsAITest(), "EXPECT_SWITCH is usable only in AI_SINGLE_BATTLE_TEST, AI_DOUBLE_BATTLE_TEST, AI_MULTI_BATTLE_TEST, AI_TWO_VS_ONE_TEST, and AI_ONE_VS_TWO_TEST");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], "EXPECT_SWITCH to invalid party index");

    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF((DATA.currentMonIndexes[i] == partyIndex) && Test_BattlersShareParty(battlerId, i), "EXPECT_SWITCH to battler");
    }

    DATA.currentMonIndexes[battlerId] = partyIndex;
    DATA.actionBattlers |= 1 << battlerId;

    id = DATA.expectedAiActionIndex[battlerId];
    DATA.expectedAiActions[battlerId][id].type = B_ACTION_SWITCH;
    DATA.expectedAiActions[battlerId][id].target = partyIndex;
    DATA.expectedAiActions[battlerId][id].sourceLine = sourceLine;
    DATA.expectedAiActions[battlerId][id].actionSet = TRUE;
    DATA.expectedAiActionIndex[battlerId]++;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_TURN_OPEN;
}

void SkipTurn(u32 sourceLine, struct BattlePokemon *battler)
{
    enum BattlerId battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SKIP_TURN outside TURN");
    DATA.actionBattlers |= 1 << battlerId;
}

void SendOut(u32 sourceLine, struct BattlePokemon *battler, u32 partyIndex)
{
    s32 i;
    enum BattlerId battlerId = battler - gBattleMons;
    INVALID_IF(DATA.turnState == TURN_CLOSED, "SEND_OUT outside TURN");
    INVALID_IF(partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], "SEND_OUT of invalid party index");
    INVALID_IF(IsAITest() && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT, "SEND_OUT is not allowed for opponent in AI tests. Use EXPECT_SEND_OUT instead");
    for (i = 0; i < STATE->battlersCount; i++)
    {
        if (battlerId != i && (battlerId & BIT_SIDE) == (i & BIT_SIDE))
            INVALID_IF((DATA.currentMonIndexes[i] == partyIndex) && Test_BattlersShareParty(battlerId, i), "SEND_OUT to battler");
    }
    if (!(DATA.actionBattlers & (1 << battlerId)))
        Move(sourceLine, battler, (struct MoveContext) { move: MOVE_CELEBRATE, explicitMove: TRUE });
    PushBattlerAction(sourceLine, battlerId, RECORDED_PARTY_INDEX, partyIndex);
    DATA.currentMonIndexes[battlerId] = partyIndex;
}

static bool32 CheckTestInventoryHasSpace(enum Item itemId, u16 count)
{
    u32 spaceForItem = 0;
    struct ItemSlot tempItem;

    for (u32 i = 0; i < TEST_ITEM_SLOTS; i++)
    {
        tempItem = DATA.inventory[i];
        if (tempItem.itemId == ITEM_NONE || tempItem.itemId == itemId)
            spaceForItem += (tempItem.itemId ? (MAX_BAG_ITEM_CAPACITY - tempItem.quantity) : MAX_BAG_ITEM_CAPACITY);
    }
    return (spaceForItem >= count);
}

static void AddToTestInventory(enum Item itemId, u16 count)
{
    struct ItemSlot tempItem;
    for (u32 i = 0; i < TEST_ITEM_SLOTS && count > 0; i++)
    {
        tempItem = DATA.inventory[i];
        if (tempItem.itemId == ITEM_NONE || tempItem.itemId == itemId)
        {
            if (tempItem.itemId == ITEM_NONE)
            {
                tempItem.quantity = 0;
                DATA.inventory[i].itemId = itemId;
            }

            // Record slot quantity in tempPocketSlotQuantities, adjust count
            DATA.inventory[i].quantity = min(MAX_BAG_ITEM_CAPACITY, count + tempItem.quantity);
            count -= min(count, MAX_BAG_ITEM_CAPACITY - tempItem.quantity);
        }
    }
}

void GivePlayerItem(u32 sourceLine, enum Item itemId, u32 quantity)
{
    INVALID_IF(!CheckBagHasSpace(itemId, quantity), "Not enough space in bag");
    INVALID_IF(!CheckTestInventoryHasSpace(itemId, quantity), "Not enough space in test inventory");

    DATA.explicitInventory = TRUE;
    AddBagItem(itemId, quantity);
    AddToTestInventory(itemId, quantity);
}

void UseItem(u32 sourceLine, struct BattlePokemon *battler, struct ItemContext ctx)
{
    s32 i;
    enum BattlerId battlerId = battler - gBattleMons;
    enum ItemType ctxItemType = GetItemType(ctx.itemId);
    bool32 requirePartyIndex = ctxItemType == ITEM_USE_PARTY_MENU
                            || ctxItemType == ITEM_USE_PARTY_MENU_MOVES
                            || (ctxItemType == ITEM_USE_BATTLER
                                 && !IsAIDoublesTest()
                                 && STATE->battlersCount > 2);
    // Check general bad use.
    INVALID_IF(DATA.turnState == TURN_CLOSED, "USE_ITEM outside TURN");
    INVALID_IF(DATA.actionBattlers & (1 << battlerId), "Multiple battler actions");
    INVALID_IF(ctx.itemId >= ITEMS_COUNT, "Illegal item: %d", ctx.itemId);
    // Check party menu items.
    INVALID_IF(requirePartyIndex && !ctx.explicitPartyIndex, "%S requires explicit party index", GetItemName(ctx.itemId));
    INVALID_IF(requirePartyIndex && ctx.partyIndex >= DATA.partySizes[Test_GetBattlerTrainer(battlerId)], \
                "USE_ITEM to invalid party index");
    // Check move slot items.
    if (ctxItemType == ITEM_USE_PARTY_MENU_MOVES)
    {
        INVALID_IF(!ctx.explicitMove, "%S requires an explicit move", GetItemName(ctx.itemId));
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (GetMonData(CurrentMon(battlerId), MON_DATA_MOVE1 + i) == ctx.move)
                break;
        }
        INVALID_IF(i == MAX_MON_MOVES, "USE_ITEM on invalid move: %d", ctx.move);
    }
    else
    {
        i = 0;
    }

    if (!DATA.explicitInventory && (battlerId & BIT_SIDE) == B_SIDE_PLAYER)
    {
        INVALID_IF(!CheckBagHasSpace(ctx.itemId, 1), "Not enough space in bag");
        INVALID_IF(!CheckTestInventoryHasSpace(ctx.itemId, 1), "Not enough space in test inventory");
        AddBagItem(ctx.itemId, 1);
        AddToTestInventory(ctx.itemId, 1);
    }
    if (ctx.explicitRNG)
        DATA.battleRecordTurns[DATA.turns][battlerId].rng = ctx.rng;
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
    enum BattlerId battlerId = battler - gBattleMons;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "ABILITY_POPUP outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: ABILITY exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
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
}

void QueueItem(u32 sourceLine, struct BattlePokemon *battler, struct ItemEventContext ctx)
{
    enum BattlerId battlerId = battler - gBattleMons;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "ITEMN_POPUP outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: ITEM exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_ITEM_POPUP_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .item = {
            .battlerId = battlerId,
            .item = ctx.item,
        }},
    };
}

void QueueAnimation(u32 sourceLine, u32 type, u32 id, struct AnimationEventContext ctx)
{
    s32 attackerId, targetId;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "ANIMATION outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: ANIMATION exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

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
    enum BattlerId battlerId = battler - gBattleMons;
    u32 type;
    uintptr_t address;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "HP_BAR outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: HP_BAR exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

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

void QueueSubHit(u32 sourceLine, struct BattlePokemon *battler, struct SubHitEventContext ctx)
{
    enum BattlerId battlerId = battler - gBattleMons;
    bool32 breakSub = FALSE;
    bool32 checkBreak = FALSE;
    uintptr_t address;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "SUB_HIT outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: SUB_HIT exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

    address = 0;
    if (ctx.explicitCaptureDamage)
    {
        INVALID_IF(ctx.captureDamage == NULL, "captureDamage is NULL");
        *ctx.captureDamage = 0;
        address = (uintptr_t)ctx.captureDamage;
    }

    if (ctx.explicitSubBreak)
    {
        checkBreak = TRUE;
        if (ctx.subBreak)
            breakSub = TRUE;
    }

    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_SUB_HIT_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .subHit = {
            .battlerId = battlerId,
            .checkBreak = checkBreak,
            .breakSub = breakSub,
            .address = address,
        }},
    };
}

void QueueExp(u32 sourceLine, struct BattlePokemon *battler, struct ExpEventContext ctx)
{
    enum BattlerId battlerId = battler - gBattleMons;
    u32 type;
    uintptr_t address;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "EXPERIENCE_BAR outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: EXPERIENCE_BAR exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

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
    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "MESSAGE outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: MESSAGE exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
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
    enum BattlerId battlerId = battler - gBattleMons;
    u32 mask;

    if (gTestRunnerState.expectedFailState == EXPECT_FAIL_OPEN)
        gTestRunnerState.expectedFailState = EXPECT_FAIL_SCENE_OPEN;

    INVALID_IF(!STATE->runScene, "STATUS_ICON outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: STATUS_ICON exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);

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

void QueueCatchingChance(u32 sourceLine, u32 *captureAddress)
{
    INVALID_IF(!STATE->runScene, "CAPTURE outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: CAPTURE exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
    u32 address = (u32)captureAddress;
    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_CATCH_CHANCE_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .capture = {
            .address = address,
        }},
    };
}

void ValidateFinally(u32 sourceLine)
{
    // Defer this error until after estimating the cost.
    INVALID_IF(STATE->parametersCount == 0, "FINALLY without PARAMETRIZE");
}

u32 TestRunner_Battle_GetForcedAbility(enum BattleTrainer trainer, u32 partyIndex)
{
    return DATA.forcedAbilities[trainer][partyIndex];
}

u32 TestRunner_Battle_GetForcedEnvironment(void)
{
    return DATA.forcedEnvironment;
}

u32 TestRunner_Battle_GetChosenGimmick(enum BattleTrainer trainer, u32 partyIndex)
{
    return DATA.chosenGimmick[trainer][partyIndex];
}

// TODO: Consider storing the last successful i and searching from i+1
// to improve performance.
struct AILogLine *GetLogLine(enum BattlerId battlerId, u32 moveIndex)
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

    Test_ExitWithResult(TEST_RESULT_ERROR, SourceLine(0), "Too many AI log lines");
    return NULL;
}

void TestRunner_Battle_AILogScore(const char *file, u32 line, enum BattlerId battlerId, u32 moveIndex, s32 score, bool32 setScore)
{
    struct AILogLine *log;

    if (!DATA.logAI) return;

    log = GetLogLine(battlerId, moveIndex);
    log->file = file;
    log->line = line;
    log->score = score;
    log->set = setScore;
}

void TestRunner_Battle_AISetScore(const char *file, u32 line, enum BattlerId battlerId, u32 moveIndex, s32 score)
{
    TestRunner_Battle_AILogScore(file, line, battlerId, moveIndex, score, TRUE);
}

void TestRunner_Battle_AIAdjustScore(const char *file, u32 line, enum BattlerId battlerId, u32 moveIndex, s32 score)
{
    TestRunner_Battle_AILogScore(file, line, battlerId, moveIndex, score, FALSE);
}

void QueueEffectivenessSound(u32 sourceLine, struct BattlePokemon *battler, struct EffectivenessEventContext ctx)
{
    s32 battlerId = battler - gBattleMons;
    INVALID_IF(!STATE->runScene, "EFFECTIVENESS_SE outside of SCENE");
    if (DATA.queuedEventsCount == MAX_QUEUED_EVENTS)
        Test_ExitWithResult(TEST_RESULT_ERROR, sourceLine, "%s:%d: EFFECTIVENESS_SE exceeds MAX_QUEUED_EVENTS", gTestRunnerState.test->filename, sourceLine);
    DATA.queuedEvents[DATA.queuedEventsCount++] = (struct QueuedEvent) {
        .type = QUEUED_EFFECTIVENESS_EVENT,
        .sourceLineOffset = SourceLineOffset(sourceLine),
        .groupType = QUEUE_GROUP_NONE,
        .groupSize = 1,
        .as = { .eff_se = {
            .battlerId = battlerId,
            .soundId = ctx.soundId,
        }},
    };
}

static s32 TryEffectivenessSound(s32 i, s32 n, u32 battlerId, u32 soundId)
{
    struct QueuedEffectiveness *event;
    s32 iMax = i + n;
    for (; i < iMax; i++)
    {
        if (DATA.queuedEvents[i].type != QUEUED_EFFECTIVENESS_EVENT) {
            continue;
        }

        event = &DATA.queuedEvents[i].as.eff_se;
        // Test_MgbaPrintf("Looking for: battler %d sound %d. Found battler %d sound %d", event->battlerId, event->soundId, battlerId, soundId);
        if (event->battlerId == battlerId && event->soundId == soundId)
            return i;
    }
    return -1;
}

void TestRunner_Battle_RecordEffectivenessSound(u32 battlerId, u32 soundId)
{
    s32 queuedEvent;
    s32 match;
    struct QueuedEvent *event;

    if (DATA.trial.queuedEvent == DATA.queuedEventsCount)
        return;

    event = &DATA.queuedEvents[DATA.trial.queuedEvent];
    switch (event->groupType)
    {
    case QUEUE_GROUP_NONE:
    case QUEUE_GROUP_ONE_OF:
        if (TryEffectivenessSound(DATA.trial.queuedEvent, event->groupSize, battlerId, soundId) != -1)
            DATA.trial.queuedEvent += event->groupSize;
        break;
    case QUEUE_GROUP_NONE_OF:
        queuedEvent = DATA.trial.queuedEvent;
        do
        {
            if ((match = TryEffectivenessSound(queuedEvent, event->groupSize, battlerId, soundId)) != -1)
            {
                const char *filename = gTestRunnerState.test->filename;
                u32 line = SourceLine(DATA.queuedEvents[match].sourceLineOffset);
                Test_ExitWithResult(TEST_RESULT_FAIL, line, "%s:%d: Matched EFFECTIVENESS_SE", filename, line);
            }

            queuedEvent += event->groupSize;
            if (queuedEvent == DATA.queuedEventsCount)
                break;

            event = &DATA.queuedEvents[queuedEvent];
            if (event->groupType == QUEUE_GROUP_NONE_OF)
                continue;

            if (TryEffectivenessSound(queuedEvent, event->groupSize, battlerId, soundId) != -1)
                DATA.trial.queuedEvent = queuedEvent + event->groupSize;
        } while (FALSE);
        break;
    }
}

void AssumeStatChange_(u32 sourceLine, u32 moveId, struct StatChangeAssumption asc)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(moveId);

    bool32 hasEffect = FALSE;
    bool32 expectPlus = asc.attack > 0 || asc.defense > 0 || asc.spAtk > 0 || asc.spDef > 0 || asc.speed > 0 || asc.accuracy > 0 || asc.evasion > 0;
    bool32 expectMinus = asc.attack < 0 || asc.defense < 0 || asc.spAtk < 0 || asc.spDef < 0 || asc.speed < 0 || asc.accuracy < 0 || asc.evasion < 0;


    for (u32 i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(moveId, i);
        if (effect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
        {
            if (!expectMinus)
              continue;

            hasEffect = TRUE;
            if (asc.attack < 0)
                ASSUME(asc.attack == (-1 * effect->attack));
            if (asc.defense < 0)
                ASSUME(asc.defense == (-1 * effect->defense));
            if (asc.spAtk < 0)
                ASSUME(asc.spAtk == (-1 * effect->spAtk));
            if (asc.spDef < 0)
                ASSUME(asc.spDef == (-1 * effect->spDef));
            if (asc.speed < 0)
                ASSUME(asc.speed == (-1 * effect->speed));
            if (asc.accuracy < 0)
                ASSUME(asc.accuracy == (-1 * effect->accuracy));
            if (asc.evasion < 0)
                ASSUME(asc.evasion == (-1 * effect->evasion));
        }
        else if (effect->moveEffect == STAT_CHANGE_EFFECT_PLUS)
        {
            if (!expectPlus)
              continue;

            hasEffect = TRUE;
            if (asc.attack > 0)
                ASSUME(asc.attack == effect->attack);
            if (asc.defense > 0)
                ASSUME(asc.defense == effect->defense);
            if (asc.spAtk > 0)
                ASSUME(asc.spAtk == effect->spAtk);
            if (asc.spDef > 0)
                ASSUME(asc.spDef == effect->spDef);
            if (asc.speed > 0)
                ASSUME(asc.speed == effect->speed);
            if (asc.accuracy > 0)
                ASSUME(asc.accuracy == effect->accuracy);
            if (asc.evasion > 0)
                ASSUME(asc.evasion == effect->evasion);
        }
    }

    ASSUME(hasEffect == TRUE);
}

void AssumeMoveEffectStatChange_(u32 sourceLine, u32 moveId, struct StatChangeAssumption asc)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(moveId);

    bool32 hasEffect = FALSE;
    bool32 expectPlus = asc.attack > 0 || asc.defense > 0 || asc.spAtk > 0 || asc.spDef > 0 || asc.speed > 0 || asc.accuracy > 0 || asc.evasion > 0;
    bool32 expectMinus = asc.attack < 0 || asc.defense < 0 || asc.spAtk < 0 || asc.spDef < 0 || asc.speed < 0 || asc.accuracy < 0 || asc.evasion < 0;

    for (u32 i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(moveId, i);
        if (effect->moveEffect == MOVE_EFFECT_STAT_MINUS)
        {
            if (!expectMinus)
              continue;

            hasEffect = TRUE;
            if (asc.attack < 0)
                ASSUME(asc.attack == (-1 * effect->attack));
            if (asc.defense < 0)
                ASSUME(asc.defense == (-1 * effect->defense));
            if (asc.spAtk < 0)
                ASSUME(asc.spAtk == (-1 * effect->spAtk));
            if (asc.spDef < 0)
                ASSUME(asc.spDef == (-1 * effect->spDef));
            if (asc.speed < 0)
                ASSUME(asc.speed == (-1 * effect->speed));
            if (asc.accuracy < 0)
                ASSUME(asc.accuracy == (-1 * effect->accuracy));
            if (asc.evasion < 0)
                ASSUME(asc.evasion == (-1 * effect->evasion));

            ASSUME(asc.self == effect->self);
        }
        else if (effect->moveEffect == MOVE_EFFECT_STAT_PLUS)
        {
            if (!expectPlus)
              continue;

            hasEffect = TRUE;
            if (asc.attack > 0)
                ASSUME(asc.attack == effect->attack);
            if (asc.defense > 0)
                ASSUME(asc.defense == effect->defense);
            if (asc.spAtk > 0)
                ASSUME(asc.spAtk == effect->spAtk);
            if (asc.spDef > 0)
                ASSUME(asc.spDef == effect->spDef);
            if (asc.speed > 0)
                ASSUME(asc.speed == effect->speed);
            if (asc.accuracy > 0)
                ASSUME(asc.accuracy == effect->accuracy);
            if (asc.evasion > 0)
                ASSUME(asc.evasion == effect->evasion);

            ASSUME(asc.self == effect->self);
        }
    }

    ASSUME(hasEffect == TRUE);
}
