#include "global.h"
#include "main.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_items.h"
#include "battle_ai_switch.h"
#include "battle_ai_main.h"
#include "battle_ai_record.h"
#include "battle_stat_change.h"
#include "battle_controllers.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "battle_z_move.h"
#include "battle_terastal.h"
#include "data.h"
#include "debug.h"
#include "event_data.h"
#include "item.h"
#include "math_util.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "script.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/trainers.h"

#if TESTING
#include "test/battle.h"
#endif

#define AI_ACTION_DONE          (1 << 0)
#define AI_ACTION_FLEE          (1 << 1)
#define AI_ACTION_WATCH         (1 << 2)
#define AI_ACTION_DO_NOT_ATTACK (1 << 3)

struct ChosenAction
{
    u8 moveIndex;
    enum BattlerId target;
};

static struct ChosenAction ChooseMoveOrAction(enum BattlerId battler);
static struct ChosenAction ChooseMoveOrAction_Singles(enum BattlerId battler);
static struct ChosenAction ChooseMoveOrAction_Doubles(enum BattlerId battlerAtk);
static inline void BattleAI_DoAIProcessing(struct AiThinkingStruct *aiThink, enum BattlerId battlerAtk, enum BattlerId battlerDef);
static inline void BattleAI_DoAIProcessing_PredictedSwitchin(struct AiThinkingStruct *aiThink, struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef);
static bool32 IsPinchBerryItemEffect(enum HoldEffect holdEffect);
static bool32 DoesAbilityBenefitFromSunOrRain(enum BattlerId battler, enum Ability ability, u32 weather);
static void AI_CompareDamagingMoves(enum BattlerId battlerAtk, enum BattlerId battlerDef);
static u32 GetWindAbilityScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData);

// ewram
EWRAM_DATA const u8 *gAIScriptPtr = NULL;   // Still used in contests
EWRAM_DATA AiScoreFunc sDynamicAiFunc = NULL;
EWRAM_DATA AiSwitchFunc gDynamicAiSwitchFunc = NULL;

// const rom data
static s32 AI_CheckBadMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_TryToFaint(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_CheckViability(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_ForceSetupFirstTurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_Risky(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_TryTo2HKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_AttacksPartner(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_PreferBatonPass(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_HPAware(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_Roaming(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_Safari(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_FirstBattle(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_DoubleBattle(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static bool32 ShouldTriggerPartnerAbility(enum BattlerId battlerAtk, enum Move move, enum Ability ability);
static s32 AI_PowerfulStatus(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_DynamicFunc(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_PredictSwitch(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);
static s32 AI_CheckPpStall(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score);

static s32 (*const sBattleAiFuncTable[])(enum BattlerId, enum BattlerId, enum Move, s32) =
{
    [0] = AI_CheckBadMove,           // AI_FLAG_CHECK_BAD_MOVE
    [1] = AI_TryToFaint,             // AI_FLAG_TRY_TO_FAINT
    [2] = AI_CheckViability,         // AI_FLAG_CHECK_VIABILITY
    [3] = AI_ForceSetupFirstTurn,    // AI_FLAG_FORCE_SETUP_FIRST_TURN
    [4] = AI_Risky,                  // AI_FLAG_RISKY
    [5] = AI_TryTo2HKO,              // AI_FLAG_TRY_TO_2HKO
    [6] = AI_PreferBatonPass,        // AI_FLAG_PREFER_BATON_PASS
    [7] = AI_DoubleBattle,           // AI_FLAG_DOUBLE_BATTLE
    [8] = AI_HPAware,                // AI_FLAG_HP_AWARE
    [9] = AI_PowerfulStatus,         // AI_FLAG_POWERFUL_STATUS
    [10] = NULL,                     // AI_FLAG_NEGATE_UNAWARE
    [11] = NULL,                     // AI_FLAG_WILL_SUICIDE
    [12] = NULL,                     // AI_FLAG_PREFER_STATUS_MOVES
    [13] = NULL,                     // AI_FLAG_STALL
    [14] = NULL,                     // AI_FLAG_SMART_SWITCHING
    [15] = NULL,                     // AI_FLAG_ACE_POKEMON
    [16] = NULL,                     // AI_FLAG_OMNISCIENT
    [17] = NULL,                     // AI_FLAG_SMART_MON_CHOICES
    [18] = NULL,                     // AI_FLAG_CONSERVATIVE
    [19] = NULL,                     // AI_FLAG_SEQUENCE_SWITCHING
    [20] = NULL,                     // AI_FLAG_DOUBLE_ACE_POKEMON
    [21] = NULL,                     // AI_FLAG_WEIGH_ABILITY_PREDICTION
    [22] = NULL,                     // AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE
    [23] = AI_PredictSwitch,         // AI_FLAG_PREDICT_SWITCH
    [24] = NULL,                     // AI_FLAG_PREDICT_INCOMING_MON
    [25] = AI_CheckPpStall,          // AI_FLAG_PP_STALL_PREVENTION
    [26] = NULL,                     // AI_FLAG_PREDICT_MOVE
    [27] = NULL,                     // AI_FLAG_SMART_TERA
    [28] = NULL,                     // AI_FLAG_ASSUME_STAB
    [29] = NULL,                     // AI_FLAG_ASSUME_STATUS_MOVES
    [30] = AI_AttacksPartner,        // AI_FLAG_ATTACKS_PARTNER
    [31] = NULL,                     // AI_FLAG_KNOW_OPPONENT_PARTY
    [32] = NULL,                     // AI_FLAG_RANDOMIZE_SWITCHIN
    [33] = NULL,                     // AI_FLAG_RANDOMIZE_PARTY_INDICES
    [34] = NULL,                     // AI_FLAG_ABILITY_OMNISCIENCE
    [35] = NULL,                     // AI_FLAG_ITEM_OMNISCIENCE
    [36] = NULL,                     // AI_FLAG_MOVE_OMNISCIENCE
    [37] = NULL,                     // Unused
    [38] = NULL,                     // Unused
    [39] = NULL,                     // Unused
    [40] = NULL,                     // Unused
    [41] = NULL,                     // Unused
    [42] = NULL,                     // Unused
    [43] = NULL,                     // Unused
    [44] = NULL,                     // Unused
    [45] = NULL,                     // Unused
    [46] = NULL,                     // Unused
    [47] = NULL,                     // Unused
    [48] = NULL,                     // Unused
    [49] = NULL,                     // Unused
    [50] = NULL,                     // Unused
    [51] = NULL,                     // Unused
    [52] = NULL,                     // Unused
    [53] = NULL,                     // Unused
    [54] = NULL,                     // Unused
    [55] = NULL,                     // Unused
    [56] = NULL,                     // Unused
    [57] = NULL,                     // Unused
    [58] = NULL,                     // Unused
    [59] = NULL,                     // Unused
    [60] = AI_DynamicFunc,          // AI_FLAG_DYNAMIC_FUNC
    [61] = AI_Roaming,              // AI_FLAG_ROAMING
    [62] = AI_Safari,               // AI_FLAG_SAFARI
    [63] = AI_FirstBattle,          // AI_FLAG_FIRST_BATTLE
};

// Functions
void AIDebugTimerStart()
{
    // Set delay timer to count how long it takes for AI to choose action/move
    if ((TESTING && gBattleTurnCounter == 0) || DEBUG_AI_DELAY_TIMER)
        gBattleStruct->aiDelayTimer = gMain.vblankCounter1;
    if (!TESTING && DEBUG_AI_DELAY_TIMER)
        CycleCountStart();
}

void AIDebugTimerEnd()
{
    // We add to existing to compound multiple calls
    if ((TESTING && gBattleTurnCounter == 0) || DEBUG_AI_DELAY_TIMER)
        gBattleStruct->aiDelayFrames += gMain.vblankCounter1 - gBattleStruct->aiDelayTimer;
    if (!TESTING && DEBUG_AI_DELAY_TIMER)
        gBattleStruct->aiDelayCycles += CycleCountEnd();
}

void BattleAI_SetupAIData(u8 defaultScoreMoves, enum BattlerId battler)
{
    u32 moveLimitations;
    u64 flags[MAX_BATTLERS_COUNT];

    // Clear AI data but preserve the flags.
    memcpy(&flags[0], &gAiThinkingStruct->aiFlags[0], sizeof(u64) * MAX_BATTLERS_COUNT);
    memset(gAiThinkingStruct, 0, sizeof(struct AiThinkingStruct));
    memcpy(&gAiThinkingStruct->aiFlags[0], &flags[0], sizeof(u64) * MAX_BATTLERS_COUNT);

    moveLimitations = gAiLogicData->moveLimitations[battler];

    // Conditional score reset, unlike Ruby.
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moveLimitations & (1u << moveIndex))
            SET_SCORE(battler, moveIndex, 0);
        else if (defaultScoreMoves & 1)
            SET_SCORE(battler, moveIndex, AI_SCORE_DEFAULT);
        else
            SET_SCORE(battler, moveIndex, 0);

        defaultScoreMoves >>= 1;
    }

    gAiBattleData->chosenTarget[battler] = SetRandomTarget(battler);
}

void BattleAI_SetupItems(void)
{
    u8 *data = (u8 *)gBattleHistory;
    u32 trainerId = TRAINER_BATTLE_PARAM.opponentA;
    if (IsSpecialTrainer(trainerId))
        trainerId = TRAINER_NONE;
    const enum Item *items = GetTrainerItemsFromId(trainerId);

    for (u32 i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    // Items are allowed to use in ONLY trainer battles.
    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER
                               | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_FRONTIER
                               | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_RECORDED_LINK)
            )
       )
    {
        for (u32 itemIndex = 0; itemIndex < MAX_TRAINER_ITEMS; itemIndex++)
        {
            if (items[itemIndex] != ITEM_NONE)
            {
                gBattleHistory->trainerItems[gBattleHistory->itemsNo] = items[itemIndex];
                gBattleHistory->itemsNo++;
            }
        }
    }
}

static u64 GetWildAiFlags(void)
{
    u32 avgLevel = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL);
    u64 flags = 0;

    if (IsDoubleBattle())
        avgLevel = (GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL) + GetMonData(&gParties[B_TRAINER_OPPONENT_A][1], MON_DATA_LEVEL)) / 2;

    flags |= AI_FLAG_CHECK_BAD_MOVE;
    if (avgLevel >= 20)
        flags |= AI_FLAG_CHECK_VIABILITY;
    if (avgLevel >= 60)
        flags |= AI_FLAG_TRY_TO_2HKO;
    if (avgLevel >= 80)
        flags |= AI_FLAG_HP_AWARE;

    if (B_VAR_WILD_AI_FLAGS != 0 && VarGet(B_VAR_WILD_AI_FLAGS) != 0)
        flags |= VarGet(B_VAR_WILD_AI_FLAGS);

    return flags;
}

static bool32 IsSmartBattle(void)
{
    if (IsSpecialTrainer(TRAINER_BATTLE_PARAM.opponentA))
        return FALSE; // Don't set flags for link battle unless Battle Tower link multi mode

    return gBattleTypeFlags & BATTLE_TYPE_HAS_AI || IsWildMonSmart();
}

static u64 GetAiFlags(u16 trainerId, enum BattlerId battler)
{
    u64 flags = 0;

    if (!IsSmartBattle())
    {
        return 0;
    }
    if (trainerId == 0xFFFF)
    {
        flags = GetWildAiFlags();
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            flags = GetAiScriptsInRecordedBattle(battler);
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            flags = AI_FLAG_SAFARI;
        else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
            flags = AI_FLAG_ROAMING;
        else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
            flags = AI_FLAG_FIRST_BATTLE;
        else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
            flags = GetAiScriptsInBattleFactory();
        else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE))
            flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT;
        else
            flags = GetTrainerAIFlagsFromId(trainerId);
    }

    if (IsDoubleBattle() && flags != 0)
    {
        flags |= AI_FLAG_DOUBLE_BATTLE;
    }

    // Automatically includes AI_FLAG_SMART_MON_CHOICES to improve smart switching
    if (flags & AI_FLAG_SMART_SWITCHING)
        flags |= AI_FLAG_SMART_MON_CHOICES;

    // Automatically includes AI_FLAG_PREDICT_SWITCH if AI_FLAG_PREDICT_INCOMING_MON is being used
    if (flags & AI_FLAG_PREDICT_INCOMING_MON)
        flags |= AI_FLAG_PREDICT_SWITCH;

    if (sDynamicAiFunc != NULL)
        flags |= AI_FLAG_DYNAMIC_FUNC;

    return flags;
}

void BattleAI_SetupFlags(void)
{
    if (IsAiVsAiBattle())
        gAiThinkingStruct->aiFlags[B_BATTLER_0] = GetAiFlags(gPartnerTrainerId, B_BATTLER_0);
    else
        gAiThinkingStruct->aiFlags[B_BATTLER_0] = 0; // player has no AI

    if (DEBUG_OVERWORLD_MENU && gIsDebugBattle)
    {
        gAiThinkingStruct->aiFlags[B_BATTLER_1] = gDebugAIFlags;
        gAiThinkingStruct->aiFlags[B_BATTLER_3] = gDebugAIFlags;
        return;
    }

    if (IsWildMonSmart() && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER)))
    {
        // smart wild AI
        gAiThinkingStruct->aiFlags[B_BATTLER_1] = GetAiFlags(0xFFFF, B_BATTLER_1);
        gAiThinkingStruct->aiFlags[B_BATTLER_3] = GetAiFlags(0xFFFF, B_BATTLER_3);

        // The check is here because wild natural enemies are not symmetrical.
        if (WE_WILD_NATURAL_ENEMIES && IsDoubleBattle())
        {
            enum Species speciesLeft = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
            enum Species speciesRight = GetMonData(&gParties[B_TRAINER_OPPONENT_A][1], MON_DATA_SPECIES);
            if (IsNaturalEnemy(speciesLeft, speciesRight))
                gAiThinkingStruct->aiFlags[B_BATTLER_1] |= AI_FLAG_ATTACKS_PARTNER;
            if (IsNaturalEnemy(speciesRight, speciesLeft))
                gAiThinkingStruct->aiFlags[B_BATTLER_3] |= AI_FLAG_ATTACKS_PARTNER;
        }
    }
    else
    {
        gAiThinkingStruct->aiFlags[B_BATTLER_1] = GetAiFlags(TRAINER_BATTLE_PARAM.opponentA, B_BATTLER_1);
        if ((TRAINER_BATTLE_PARAM.opponentB != 0) && (TRAINER_BATTLE_PARAM.opponentB != 0xFFFF))
            gAiThinkingStruct->aiFlags[B_BATTLER_3] = GetAiFlags(TRAINER_BATTLE_PARAM.opponentB, B_BATTLER_3);
        else
            gAiThinkingStruct->aiFlags[B_BATTLER_3] = gAiThinkingStruct->aiFlags[B_BATTLER_1];
    }

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gAiThinkingStruct->aiFlags[B_BATTLER_2] = GetAiFlags(gPartnerTrainerId, B_BATTLER_2);
    }
    else if (IsDoubleBattle() && IsAiVsAiBattle())
    {
        gAiThinkingStruct->aiFlags[B_BATTLER_2] = gAiThinkingStruct->aiFlags[B_BATTLER_0];
    }
    else // Assign ai flags for player for prediction
    {
        u64 aiFlags = GetAiFlags(TRAINER_BATTLE_PARAM.opponentA, B_BATTLER_1)
                    | GetAiFlags(TRAINER_BATTLE_PARAM.opponentB, B_BATTLER_3);
        gAiThinkingStruct->aiFlags[B_BATTLER_2] = aiFlags;
        gAiThinkingStruct->aiFlags[B_BATTLER_0] = aiFlags;
    }
}

bool32 BattlerChooseNonMoveAction(void)
{
    if (gAiThinkingStruct->aiAction & AI_ACTION_FLEE)
    {
        gAiBattleData->actionFlee = TRUE;
        return TRUE;
    }

    if (gAiThinkingStruct->aiAction & AI_ACTION_WATCH)
    {
        gAiBattleData->choiceWatch = TRUE;
        return TRUE;
    }

    return FALSE;
}

void SetupAIPredictionData(enum BattlerId battler, enum SwitchType switchType)
{
    gAiLogicData->aiPredictionInProgress = TRUE;

    // Switch prediction
    if (IsAiFlagPresent(AI_FLAG_PREDICT_SWITCH))
    {
        enum SwitchType switchType = (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_RISKY) ? SWITCH_AFTER_KO : SWITCH_MID_BATTLE_OPTIONAL; // Risky AI switches aggressively even mid battle
        gAiLogicData->mostSuitableMonId[battler] = GetMostSuitableMonToSwitchInto(battler, switchType);
        if (ShouldSwitch(battler))
            gAiLogicData->shouldSwitch |= (1u << battler);
        gBattleStruct->prevTurnSpecies[battler] = gBattleMons[battler].species;
    }

    // Move prediction
    if (IsAiFlagPresent(AI_FLAG_PREDICT_MOVE))
    {
        gAiBattleData->chosenMoveIndex[battler] = BattleAI_ChooseMoveIndex(battler);
        gAiLogicData->predictedMove[battler] = gBattleMons[battler].moves[gAiBattleData->chosenMoveIndex[battler]];
        ModifySwitchAfterMoveScoring(battler);
    }

    gAiLogicData->aiPredictionInProgress = FALSE;
}

void ComputeAiBattlerDecisions(enum BattlerId battler)
{
    gAiLogicData->aiCalcInProgress = TRUE;

        AIDebugTimerStart();

    // Setup battler data
    BattleAI_SetupAIData(0xF, battler);

    // Determine whether AI will use predictions this turn

    gAiLogicData->predictingSwitch = (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_PREDICT_SWITCH) ? RandomPercentage(RNG_AI_PREDICT_SWITCH, PREDICT_SWITCH_CHANCE) : FALSE;
    gAiLogicData->predictingMove = (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_PREDICT_MOVE) ? RandomPercentage(RNG_AI_PREDICT_MOVE, PREDICT_MOVE_CHANCE) : FALSE;

    // AI's switching data
    enum SwitchType switchType = (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_RISKY) ? SWITCH_AFTER_KO : SWITCH_MID_BATTLE_OPTIONAL; // Risky AI switches aggressively even mid battle
    gAiLogicData->mostSuitableMonId[battler] = GetMostSuitableMonToSwitchInto(battler, switchType);

    if (ShouldSwitch(battler))
        gAiLogicData->shouldSwitch |= (1u << battler);

    gBattleStruct->prevTurnSpecies[battler] = gBattleMons[battler].species;

    // AI's move scoring
    gAiBattleData->chosenMoveIndex[battler] = BattleAI_ChooseMoveIndex(battler); // Calculate score and chose move index
    BattlerChooseNonMoveAction();
    ModifySwitchAfterMoveScoring(battler);
    gAiLogicData->battlerMovesScored |= 1u << battler;

        AIDebugTimerEnd();

    gAiLogicData->aiCalcInProgress = FALSE;
}

void ReconsiderGimmick(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    // After choosing a move for battlerAtk assuming that a gimmick will be used, reconsider whether the gimmick is necessary.

    if (gBattleStruct->gimmick.usableGimmick[battlerAtk] == GIMMICK_Z_MOVE && !ShouldUseZMove(battlerAtk, battlerDef, move))
        SetAIUsingGimmick(battlerAtk, NO_GIMMICK);

    if (gBattleStruct->gimmick.usableGimmick[battlerAtk] == GIMMICK_TERA && GetMoveEffect(move) == EFFECT_PROTECT)
        SetAIUsingGimmick(battlerAtk, NO_GIMMICK);
}

static bool32 IsThinkingBeforePartner(enum BattlerId battler, enum BattlerId battlerPartner)
{
    if (!BattlerHasAi(battlerPartner))
        return TRUE;

    if (gAiLogicData->reverseBattlerLogicOrder)
        return (battlerPartner < battler);

    return (battlerPartner > battler);
}

static void SetAllyMove(u32 battler)
{
    enum BattlerId partnerBattler = GetPartnerBattler(battler);
    gAiLogicData->partnerMove = MOVE_NONE; // Make sure no garbage is stored for simulation

    if (!IsBattlerAlive(partnerBattler) || !IsAiBattlerAware(partnerBattler))
    {
        gAiLogicData->partnerMove = MOVE_NONE;
    }
    else if (IsThinkingBeforePartner(battler, partnerBattler))
    {
        // DebugPrintf("partnerBattler %d", partnerBattler );
        gAiLogicData->partnerMoveSimulation = TRUE;
        struct ChosenAction chosen = ChooseMoveOrAction_Doubles(partnerBattler);
        gAiLogicData->partnerMoveSimulation = FALSE;
        gAiLogicData->partnerMove = gBattleMons[partnerBattler].moves[chosen.moveIndex];
    }
    else
    {
        // Move for battler has already been calculated so set as partner move
        u32 moveIndex = gAiBattleData->chosenMoveIndex[partnerBattler];
        gAiLogicData->partnerMove = gBattleMons[partnerBattler].moves[moveIndex];
    }
}

static struct ChosenAction ChooseMoveOrAction(enum BattlerId battler)
{
    if (IsDoubleBattle())
    {
        SetAllyMove(battler);
        return ChooseMoveOrAction_Doubles(battler);
    }
    return ChooseMoveOrAction_Singles(battler);
}

static void SetupRandomRollsForAIMoveSelection(enum BattlerId battler)
{
    gAiLogicData->shouldConsiderExplosion = RandomPercentage(RNG_AI_CONSIDER_EXPLOSION, GetAIExplosionChanceFromHP(gAiLogicData->hpPercents[battler]));
    gAiLogicData->shouldConsiderFinalGambit = RandomPercentage(RNG_AI_FINAL_GAMBIT, FINAL_GAMBIT_CHANCE);
}

void AI_TrySwitchOrUseItem(enum BattlerId battler)
{
    struct Pokemon *party;
    enum BattlerId battlerIn1, battlerIn2;
    s32 lastId = GetAILastPartyIndex(battler); // + 1
    party = GetBattlerParty(battler);

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (gAiLogicData->shouldSwitch & (1u << battler) && IsSwitchinValid(battler))
        {
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
            SetAIUsingGimmick(battler, NO_GIMMICK);
            if (gBattleStruct->AI_monToSwitchIntoId[battler] == PARTY_SIZE)
            {
                s32 monToSwitchId = gAiLogicData->mostSuitableMonId[battler];
                if (monToSwitchId == PARTY_SIZE)
                {
                    GetActiveBattlerIds(battler, &battlerIn1, &battlerIn2);

                    for (monToSwitchId = (lastId-1); monToSwitchId >= 0; monToSwitchId--)
                    {
                        if (!IsValidForBattle(&party[monToSwitchId]))
                            continue;
                        if (IsPartyMonOnFieldOrChosenToSwitch(battler, monToSwitchId, battlerIn1, battlerIn2))
                            continue;
                        if (IsPartyMonPlannedToBeSwitchedInByPartner(monToSwitchId, battler))
                            continue;
                        if (IsAceMon(battler, monToSwitchId))
                            continue;
                        break;
                    }

                }

                if (monToSwitchId < 0)
                {
                    enum BattlerId battler1, battler2;
                    s32 lastId = GetAILastPartyIndex(battler); // + 1

                    if (!IsDoubleBattle())
                    {
                        battler2 = battler1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                    }
                    else
                    {
                        battler1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                        battler2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                    }

                    for (monToSwitchId = 0; monToSwitchId < lastId; monToSwitchId ++)
                    {
                        if (IsValidForBattle(&gParties[GetBattlerTrainer(battler)][monToSwitchId])
                         && !IsPartyMonOnFieldOrChosenToSwitch(battler, monToSwitchId, battler1, battler2))
                            break;
                    }
                }

                gBattleStruct->AI_monToSwitchIntoId[battler] = monToSwitchId;
            }

            gBattleStruct->monToSwitchIntoId[battler] = gBattleStruct->AI_monToSwitchIntoId[battler];
            gAiLogicData->monToSwitchInId[battler] = gBattleStruct->AI_monToSwitchIntoId[battler];
            return;
        }
        else if (ShouldUseItem(battler))
        {
            SetAIUsingGimmick(battler, NO_GIMMICK);
            return;
        }
    }

    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, GetOppositeBattler(battler) << 8);
}

u32 BattleAI_ChooseMoveIndex(enum BattlerId battler)
{
    SetAIUsingGimmick(battler, USE_GIMMICK);
    SetupRandomRollsForAIMoveSelection(battler);

    if (gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_TERA && (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_SMART_TERA))
        DecideTerastal(battler);

    struct ChosenAction chosen = ChooseMoveOrAction(battler);
    gAiBattleData->chosenTarget[battler] = chosen.target;

    if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_NONE)
        ReconsiderGimmick(battler, chosen.target, gBattleMons[battler].moves[chosen.moveIndex]);

    // Clear protect structures, some flags may be set during AI calcs
    // e.g. pranksterElevated from GetBattleMovePriority
    memset(&gProtectStructs, 0, MAX_BATTLERS_COUNT * sizeof(struct ProtectStruct));
    #if TESTING
    TestRunner_Battle_CheckAiMoveScores(battler);
    #endif // TESTING

    return chosen.moveIndex;
}

static void CopyBattlerDataToAIParty(u32 bPosition, enum BattleTrainer trainer)
{
    enum BattlerId battler = GetBattlerAtPosition(bPosition);
    struct AiPartyMon *aiMon = &gAiPartyData->mons[trainer][gBattlerPartyIndexes[battler]];
    struct BattlePokemon *bMon = &gBattleMons[battler];

    aiMon->species = bMon->species;
    aiMon->level = bMon->level;
    aiMon->status = bMon->status1;
    aiMon->gender = GetBattlerGender(battler);
    aiMon->isFainted = FALSE;
    aiMon->wasSentInBattle = TRUE;
    aiMon->switchInCount++;
}

void Ai_InitPartyStruct(void)
{
    bool32 isOmniscient = (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_OMNISCIENT) || (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_OMNISCIENT);
    bool32 isAbilityOmniscient = (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_ABILITY_OMNISCIENCE) || (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_ABILITY_OMNISCIENCE);
    bool32 isItemOmniscient = (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_ITEM_OMNISCIENCE) || (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_ITEM_OMNISCIENCE);
    bool32 isMoveOmniscient = (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_MOVE_OMNISCIENCE) || (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_MOVE_OMNISCIENCE);
    bool32 hasPartyKnowledge = (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_KNOW_OPPONENT_PARTY) || (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_KNOW_OPPONENT_PARTY);
    struct Pokemon *mon;

    for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
        gAiPartyData->count[trainer] = TrainerHasParty(trainer) ? CalculatePartyCount(trainer) : 0;

    // Save first 2 or 4(in doubles) mons
    CopyBattlerDataToAIParty(B_POSITION_PLAYER_LEFT, GetTrainerFromBattlePosition(B_POSITION_PLAYER_LEFT));
    if (IsDoubleBattle())
        CopyBattlerDataToAIParty(B_POSITION_PLAYER_RIGHT, GetTrainerFromBattlePosition(B_POSITION_PLAYER_RIGHT));

    // If player's partner is AI, save opponent mons
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        CopyBattlerDataToAIParty(B_POSITION_OPPONENT_LEFT, GetTrainerFromBattlePosition(B_POSITION_OPPONENT_LEFT));
        CopyBattlerDataToAIParty(B_POSITION_OPPONENT_RIGHT, GetTrainerFromBattlePosition(B_POSITION_OPPONENT_RIGHT));
    }

    // Find fainted mons
    for (enum BattleTrainer trainer = B_TRAINER_PLAYER; trainer < MAX_BATTLE_TRAINERS; trainer++)
    {
        if (!TrainerHasParty(trainer))
            continue;

        for (u32 monIndex = 0; monIndex < PARTY_SIZE; monIndex++)
        {
            mon = &gParties[trainer][monIndex];
            if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
            {
                if (GetMonData(mon, MON_DATA_HP) == 0)
                    gAiPartyData->mons[trainer][monIndex].isFainted = TRUE;

                if (isOmniscient || hasPartyKnowledge)
                    gAiPartyData->mons[trainer][monIndex].species = GetMonData(mon, MON_DATA_SPECIES);

                if (isOmniscient || isAbilityOmniscient)
                    gAiPartyData->mons[trainer][monIndex].ability = GetMonAbility(mon);

                if (isOmniscient || isItemOmniscient)
                {
                    gAiPartyData->mons[trainer][monIndex].item = GetMonData(mon, MON_DATA_HELD_ITEM);
                    gAiPartyData->mons[trainer][monIndex].heldEffect = GetItemHoldEffect(gAiPartyData->mons[trainer][monIndex].item);
                }

                if (isOmniscient || isMoveOmniscient)
                {
                    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                        gAiPartyData->mons[trainer][monIndex].moves[moveIndex] = GetMonData(mon, MON_DATA_MOVE1 + moveIndex);
                }
            }
        }
    }
}

void Ai_UpdateSwitchInData(enum BattlerId battler)
{
    enum BattleTrainer trainer = GetBattlerTrainer(battler);
    struct AiPartyMon *aiMon = &gAiPartyData->mons[trainer][gBattlerPartyIndexes[battler]];

    // See if the switched-in mon has been already in battle
    if (aiMon->wasSentInBattle)
    {
        if (aiMon->ability)
            gBattleHistory->abilities[battler] = aiMon->ability;
        if (aiMon->heldEffect)
            gBattleHistory->itemEffects[battler] = aiMon->heldEffect;
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (aiMon->moves[moveIndex])
                gBattleHistory->usedMoves[battler][moveIndex] = aiMon->moves[moveIndex];
        }
        aiMon->switchInCount++;
        aiMon->status = gBattleMons[battler].status1; // Copy status, because it could've been changed in battle.
    }
    else // If not, copy the newly switched-in mon in battle and clear battle history.
    {
        ClearBattlerMoveHistory(battler);
        ClearBattlerAbilityHistory(battler);
        ClearBattlerItemEffectHistory(battler);
        CopyBattlerDataToAIParty(GetBattlerPosition(battler), trainer);
    }
}

void Ai_UpdateFaintData(enum BattlerId battler)
{
    struct AiPartyMon *aiMon = &gAiPartyData->mons[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
    ClearBattlerMoveHistory(battler);
    ClearBattlerAbilityHistory(battler);
    ClearBattlerItemEffectHistory(battler);
    aiMon->isFainted = TRUE;
}

void RecordMovesBasedOnStab(enum BattlerId battler)
{
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move playerMove = gBattleMons[battler].moves[moveIndex];
        if (IsSpeciesOfType(gBattleMons[battler].species, GetMoveType(playerMove)) && GetMovePower(playerMove) != 0)
            RecordKnownMove(battler, playerMove);
    }
}

void RecordStatusMoves(enum BattlerId battler)
{
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move playerMove = gBattleMons[battler].moves[moveIndex];
        if (ShouldRecordStatusMove(playerMove))
            RecordKnownMove(battler, playerMove);
    }
}

void SetBattlerAiData(enum BattlerId battler, struct AiLogicData *aiData)
{
    enum Ability ability;
    enum HoldEffect holdEffect;

    ability = aiData->abilities[battler] = AI_DecideKnownAbilityForTurn(battler);
    aiData->items[battler] = gBattleMons[battler].item;
    holdEffect = aiData->holdEffects[battler] = AI_DecideHoldEffectForTurn(battler);
    aiData->lastUsedMove[battler] = (gLastMoves[battler] == MOVE_UNAVAILABLE) ? MOVE_NONE : gLastMoves[battler];
    aiData->hpPercents[battler] = GetHealthPercentage(battler);
    aiData->moveLimitations[battler] = CheckMoveLimitations(battler, 0, ~(MOVE_LIMITATION_UNUSABLE));
    aiData->speedStats[battler] = GetBattlerTotalSpeedStat(battler, ability, holdEffect);
    aiData->dragonDartsHitsBothTarget = 0;

    if (IsAiBattlerAssumingStab(battler))
        RecordMovesBasedOnStab(battler);

    if (IsAiBattlerAssumingStatusMoves(battler))
        RecordStatusMoves(battler);
}

#define BYPASSES_ACCURACY_CALC 101 // 101 indicates for ai that the move will always hit
static u32 Ai_SetMoveAccuracy(struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    u32 accuracy;

    struct BattleCalcValues cv = {
        .battlerAtk = battlerAtk,
        .battlerDef = battlerDef,
        .move = move,
    };

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == battlerAtk)
            cv.abilities[battler] = aiData->abilities[battler];
        else
            cv.abilities[battler] = AI_GetMoldBreakerSanitizedAbility(battlerAtk, aiData->abilities[battlerAtk], aiData->abilities[battler], aiData->holdEffects[battler], move);

        cv.holdEffects[battler] = aiData->holdEffects[battler];
    }

    u32 weather = AI_GetWeather();
    if (CanMoveSkipAccuracyCalc(&cv, weather, AI_CHECK))
    {
        accuracy = BYPASSES_ACCURACY_CALC;
    }
    else
    {
        accuracy = GetTotalAccuracy(&cv, weather);

        // Cap normal accuracy at 100 for ai calcs.
        // Done for comparison with moves that bypass accuracy checks (will be seen as 101 for ai calcs))
        accuracy = (accuracy > 100) ? 100 : accuracy;
    }

    return accuracy;
}
#undef BYPASSES_ACCURACY_CALC

void CalcBattlerAiMovesData(struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 weather, enum BattleTerrain terrain)
{
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    struct AiCalcValues aiCalc = {
        .gimmickAtk = gBattleStruct->gimmick.usableGimmick[battlerAtk],
        .gimmickDef = GIMMICK_NONE,
        .weather = weather,
        .terrain = terrain,
    };

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        struct SimulatedDamage dmg = {0};
        aiCalc.typeEffectiveness = Q_4_12(0.0);
        aiCalc.move = moves[moveIndex];

        // Move data is reused for consecutive switch-in candidates, so reset every slot before skipping unusable moves.
        aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = dmg;
        aiData->effectiveness[battlerAtk][battlerDef][moveIndex] = aiCalc.typeEffectiveness;
        aiData->moveAccuracy[battlerAtk][battlerDef][moveIndex] = 0;
        aiData->resistBerryAffected[battlerAtk][battlerDef][moveIndex] = FALSE;

        if (IsMoveUnusable(moveIndex, aiCalc.move, moveLimitations))
            continue;

        // Also get effectiveness of status moves
        dmg = AI_CalcDamage(&aiCalc, battlerAtk, battlerDef);
        aiData->moveAccuracy[battlerAtk][battlerDef][moveIndex] = Ai_SetMoveAccuracy(aiData, battlerAtk, battlerDef, aiCalc.move);

        aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = dmg;
        aiData->effectiveness[battlerAtk][battlerDef][moveIndex] = aiCalc.typeEffectiveness;
    }
}

static void SetBattlerAiMovesData(struct AiLogicData *aiData, enum BattlerId battlerAtk, u32 battlersCount, u32 weather)
{
    SaveBattlerData(battlerAtk);
    SetBattlerData(battlerAtk);

    // Simulate dmg for both ai controlled mons and for player controlled mons.
    for (enum BattlerId battlerDef = 0; battlerDef < battlersCount; battlerDef++)
    {
        if (battlerAtk == battlerDef || !IsBattlerAlive(battlerDef))
            continue;

        SaveBattlerData(battlerDef);
        SetBattlerData(battlerDef);
        CalcBattlerAiMovesData(aiData, battlerAtk, battlerDef, weather, gFieldStatuses);
        RestoreBattlerData(battlerDef);
    }
    RestoreBattlerData(battlerAtk);
}

void SetAiLogicDataForTurn(struct AiLogicData *aiData)
{
    memset(aiData, 0, sizeof(struct AiLogicData));
    gAiBattleData->aiUsingGimmick = 0;

    if (!IsSmartBattle())
        return;

    gAiLogicData->aiCalcInProgress = TRUE;
    AIDebugTimerStart();

    // get/assume all battler data and simulate AI damage
    u32 battlersCount = gBattlersCount;

    for (enum BattlerId battler = 0; battler < battlersCount; battler++)
    {
        if (!IsBattlerAlive(battler))
            continue;

        SetBattlerAiData(battler, aiData);
    }

    u32 weather = AI_GetWeather(); // Needs SetBattlerAiData

    for (enum BattlerId battler = 0; battler < battlersCount; battler++)
    {
        if (!IsBattlerAlive(battler))
            continue;

        SetBattlerAiMovesData(aiData, battler, battlersCount, weather);
    }

    for (enum BattlerId battler = 0; battler < battlersCount; battler++)
    {
        // Prediction limited to player side but can be expanded to read partners move in the future
        if (!IsOnPlayerSide(battler))
            continue;

        BattleAI_SetupAIData(0xF, battler);
        SetupAIPredictionData(battler, SWITCH_MID_BATTLE_OPTIONAL);
    }

    gBattleStruct->dynamicMoveType = TYPE_NONE;
    gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;

    AIDebugTimerEnd();
    gAiLogicData->aiCalcInProgress = FALSE;
}

static u32 PpStallReduction(enum Move move, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (move == MOVE_NONE)
        return 0;
    u32 tempBattleMonIndex = 0;
    u32 totalStallValue = 0;
    u32 returnValue = 0;
    struct Pokemon *party = GetBattlerParty(battlerDef);
    struct BattlePokemon backupBattleMon;
    struct DamageContext ctx = {0};
    ctx.battlerAtk = battlerAtk;
    ctx.abilities[ctx.battlerAtk] = gAiLogicData->abilities[battlerAtk];
    ctx.move = ctx.chosenMove = ctx.baseMove = move;
    ctx.moveType = GetBattleMoveType(move); //  Probably doesn't handle dynamic types right now
    ctx.weather = GetWeather();
    ctx.terrain = gFieldTimers.terrain;
    memcpy(&backupBattleMon, &gBattleMons[tempBattleMonIndex], sizeof(struct BattlePokemon));
    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        u32 currentStallValue = gAiBattleData->playerStallMons[partyIndex];
        if (currentStallValue == 0 || GetMonData(&party[partyIndex], MON_DATA_HP) == 0)
            continue;
        PokemonToBattleMon(&party[partyIndex], &gBattleMons[tempBattleMonIndex]);
        ctx.battlerDef = tempBattleMonIndex;
        ctx.abilities[ctx.battlerDef] = AI_DecideKnownAbilityForTurn(ctx.battlerDef);
        ctx.holdEffects[ctx.battlerDef] = AI_DecideHoldEffectForTurn(ctx.battlerDef);
        if (AI_CanMoveBeBlockedByTarget(&ctx)
         || CalcTypeEffectivenessMultiplier(&ctx) == UQ_4_12(0.0))
            totalStallValue += currentStallValue;
    }

    for (u32 i = 0; returnValue == 0 && i < totalStallValue; i++)
    {
        if (RandomPercentage(RNG_AI_PP_STALL_DISREGARD_MOVE, (100 - PP_STALL_DISREGARD_MOVE_PERCENTAGE)))
            returnValue = PP_STALL_SCORE_REDUCTION;
    }

    memcpy(&gBattleMons[tempBattleMonIndex], &backupBattleMon, sizeof(struct BattlePokemon));

    return returnValue;
}

static void DoAIScoreProcessing(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    u64 flags = gAiThinkingStruct->aiFlags[battlerAtk];
    gAiThinkingStruct->aiLogicId = 0;
    gAiThinkingStruct->movesetIndex = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        BattleAI_SetupAIData(gBattleStruct->palaceFlags >> 4, battlerAtk);
    else
        BattleAI_SetupAIData(0xF, battlerAtk);

    while (flags != 0)
    {
        if (flags & 1)
        {
            if (IsBattlerPredictedToSwitch(battlerDef) && (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_PREDICT_INCOMING_MON))
                BattleAI_DoAIProcessing_PredictedSwitchin(gAiThinkingStruct, gAiLogicData, battlerAtk, battlerDef);
            else
                BattleAI_DoAIProcessing(gAiThinkingStruct, battlerAtk, battlerDef);
        }
        flags >>= (u64)1;
        gAiThinkingStruct->aiLogicId++;
    }

    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CHECK_VIABILITY)
        AI_CompareDamagingMoves(battlerAtk, battlerDef);
}

static struct ChosenAction ChooseMoveOrAction_Singles(enum BattlerId battler)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u32 numOfBestMoves;
    enum BattlerId opposingBattler = GetOppositeBattler(battler);
    gAiLogicData->partnerMove = MOVE_NONE;   // no ally

    DoAIScoreProcessing(battler, opposingBattler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        gAiBattleData->finalScore[battler][opposingBattler][moveIndex] = gAiThinkingStruct->score[moveIndex];
    }

    numOfBestMoves = 1;
    currentMoveArray[0] = gAiThinkingStruct->score[0];
    consideredMoveArray[0] = 0;

    for (u32 moveIndex = 1; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[battler].moves[moveIndex] != MOVE_NONE)
        {
            // In ruby, the order of these if statements is reversed.
            if (currentMoveArray[0] == gAiThinkingStruct->score[moveIndex])
            {
                currentMoveArray[numOfBestMoves] = gAiThinkingStruct->score[moveIndex];
                consideredMoveArray[numOfBestMoves++] = moveIndex;
            }
            if (currentMoveArray[0] < gAiThinkingStruct->score[moveIndex])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = gAiThinkingStruct->score[moveIndex];
                consideredMoveArray[0] = moveIndex;
            }
        }
    }

    #if TESTING
    gBattleTestRunnerState->data.trial.scoreTieCount = numOfBestMoves;
    #endif

    struct ChosenAction chosen = {
        .moveIndex = consideredMoveArray[RandomUniform(RNG_AI_SCORE_TIE_SINGLES, 0, numOfBestMoves - 1)],
        .target = opposingBattler,
    };

    return chosen;
}

static struct ChosenAction ChooseMoveOrAction_Doubles(enum BattlerId battlerAtk)
{
    s32 bestMovePointsForTarget[MAX_BATTLERS_COUNT];
    u8 mostViableTargetsArray[MAX_BATTLERS_COUNT];
    u8 actionOrMoveIndex[MAX_BATTLERS_COUNT];
    s32 mostViableMovesScores[MAX_MON_MOVES];
    u8 mostViableMovesIndices[MAX_MON_MOVES];
    u32 mostViableTargetsNo;
    u32 mostViableMovesNo;
    s32 mostMovePoints;

    for (enum BattlerId battlerDef = 0; battlerDef < MAX_BATTLERS_COUNT; battlerDef++)
    {
        if (gBattleMons[battlerDef].hp == 0 || battlerAtk == battlerDef)
        {
            actionOrMoveIndex[battlerDef] = 0xFF;
            bestMovePointsForTarget[battlerDef] = -1;
        }
        else
        {
            DoAIScoreProcessing(battlerAtk, battlerDef);

            mostViableMovesScores[0] = gAiThinkingStruct->score[0];
            mostViableMovesIndices[0] = 0;
            mostViableMovesNo = 1;
            for (u32 moveIndex = 1; moveIndex < MAX_MON_MOVES; moveIndex++)
            {
                if (gBattleMons[battlerAtk].moves[moveIndex] != 0)
                {
                    if (!CanTargetBattler(battlerAtk, battlerDef, gBattleMons[battlerAtk].moves[moveIndex]))
                        continue;

                    if (mostViableMovesScores[0] == gAiThinkingStruct->score[moveIndex])
                    {
                        mostViableMovesScores[mostViableMovesNo] = gAiThinkingStruct->score[moveIndex];
                        mostViableMovesIndices[mostViableMovesNo] = moveIndex;
                        mostViableMovesNo++;
                    }
                    if (mostViableMovesScores[0] < gAiThinkingStruct->score[moveIndex])
                    {
                        mostViableMovesScores[0] = gAiThinkingStruct->score[moveIndex];
                        mostViableMovesIndices[0] = moveIndex;
                        mostViableMovesNo = 1;
                    }
                }
            }

            #if TESTING
            gBattleTestRunnerState->data.trial.scoreTieCount = mostViableMovesNo;
            #endif

            actionOrMoveIndex[battlerDef] = mostViableMovesIndices[RandomUniform(RNG_AI_SCORE_TIE_DOUBLES_MOVE, 0, mostViableMovesNo - 1)];
            bestMovePointsForTarget[battlerDef] = mostViableMovesScores[0];

            // Don't use a move against ally if it has less than 100 points.
            if (battlerDef == GetPartnerBattler(battlerAtk) && bestMovePointsForTarget[battlerDef] < AI_SCORE_DEFAULT)
            {
                bestMovePointsForTarget[battlerDef] = -1;
            }

            for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            {
                gAiBattleData->finalScore[battlerAtk][battlerDef][moveIndex] = gAiThinkingStruct->score[moveIndex];
            }
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (enum BattlerId battler = 1; battler < MAX_BATTLERS_COUNT; battler++)
    {
        if (mostMovePoints == bestMovePointsForTarget[battler])
        {
            mostViableTargetsArray[mostViableTargetsNo] = battler;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[battler])
        {
            mostMovePoints = bestMovePointsForTarget[battler];
            mostViableTargetsArray[0] = battler;
            mostViableTargetsNo = 1;
        }
    }

    #if TESTING
    gBattleTestRunnerState->data.trial.targetTieCount = mostViableTargetsNo;
    #endif

    struct ChosenAction chosen = {0};
    chosen.target = mostViableTargetsArray[RandomUniform(RNG_AI_SCORE_TIE_DOUBLES_TARGET, 0, mostViableTargetsNo - 1)];
    chosen.moveIndex = actionOrMoveIndex[chosen.target];

    return chosen;
}

static inline bool32 ShouldConsiderMoveForBattler(enum BattlerId battlerAi, enum BattlerId battlerDef, enum Move move)
{
    enum MoveTarget target = AI_GetBattlerMoveTargetType(battlerAi, move);
    if (battlerAi == GetPartnerBattler(battlerDef))
    {
        if (target == TARGET_OPPONENT
         || target == TARGET_RANDOM
         || target == TARGET_BOTH
         || target == TARGET_OPPONENTS_FIELD)
            return FALSE;
    }
    if (!IsBattlerAlly(battlerAi, battlerDef) && target == TARGET_USER_OR_ALLY)
        return FALSE;
    return TRUE;
}

static inline void BattleAI_DoAIProcessing(struct AiThinkingStruct *aiThink, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    do
    {
        if (gBattleMons[battlerAtk].pp[aiThink->movesetIndex] == 0)
            aiThink->moveConsidered = MOVE_NONE;
        else
            aiThink->moveConsidered = gBattleMons[battlerAtk].moves[aiThink->movesetIndex];

        // There is no point in calculating scores for all 3 battlers(2 opponents + 1 ally) with certain moves.
        if (aiThink->moveConsidered != MOVE_NONE
          && aiThink->score[aiThink->movesetIndex] > 0
          && ShouldConsiderMoveForBattler(battlerAtk, battlerDef, aiThink->moveConsidered))
        {
            if (aiThink->aiLogicId < ARRAY_COUNT(sBattleAiFuncTable)
              && sBattleAiFuncTable[aiThink->aiLogicId] != NULL)
            {
                // Call AI function
                aiThink->score[aiThink->movesetIndex] =
                    sBattleAiFuncTable[aiThink->aiLogicId](battlerAtk,
                      battlerDef,
                      aiThink->moveConsidered,
                      aiThink->score[aiThink->movesetIndex]);
            }
        }
        else
        {
            aiThink->score[aiThink->movesetIndex] = 0;
        }
        aiThink->movesetIndex++;
    } while (aiThink->movesetIndex < MAX_MON_MOVES && !(aiThink->aiAction & AI_ACTION_DO_NOT_ATTACK));

    aiThink->movesetIndex = 0;
}

void BattleAI_DoAIProcessing_PredictedSwitchin(struct AiThinkingStruct *aiThink, struct AiLogicData *aiData, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    struct BattlePokemon switchoutCandidate = gBattleMons[battlerDef];
    struct SimulatedDamage simulatedDamageSwitchout[MAX_MON_MOVES];
    uq4_12_t effectivenessSwitchout[MAX_MON_MOVES];
    u8 moveAccuracySwitchout[MAX_MON_MOVES];

    struct BattlePokemon switchinCandidate;
    struct SimulatedDamage simulatedDamageSwitchin[MAX_MON_MOVES];
    uq4_12_t effectivenessSwitchin[MAX_MON_MOVES];
    u8 moveAccuracySwitchin[MAX_MON_MOVES];

    struct Pokemon *party = GetBattlerParty(battlerDef);
    struct BattlePokemon *savedBattleMons = AllocSaveBattleMons();

    // Store battler moves data to save time over recalculating it
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        simulatedDamageSwitchout[moveIndex] = aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex];
        effectivenessSwitchout[moveIndex] = aiData->effectiveness[battlerAtk][battlerDef][moveIndex];
        moveAccuracySwitchout[moveIndex] = aiData->moveAccuracy[battlerAtk][battlerDef][moveIndex];
    }

    // Get battler and move data for predicted switchin
    PokemonToBattleMon(&party[aiData->mostSuitableMonId[battlerDef]], &switchinCandidate);
    gBattleMons[battlerDef] = switchinCandidate;
    gAiThinkingStruct->saved[battlerDef].saved = TRUE;
    SetBattlerAiData(battlerDef, aiData);
    CalcBattlerAiMovesData(aiData, battlerAtk, battlerDef, AI_GetWeather(), gFieldStatuses);
    gAiThinkingStruct->saved[battlerDef].saved = FALSE;

    // Regular processing with new battler
    do
    {
        if (gBattleMons[battlerAtk].pp[aiThink->movesetIndex] == 0)
            aiThink->moveConsidered = MOVE_NONE;
        else
            aiThink->moveConsidered = gBattleMons[battlerAtk].moves[aiThink->movesetIndex];

        // There is no point in calculating scores for all 3 battlers(2 opponents + 1 ally) with certain moves.
        if (aiThink->moveConsidered != MOVE_NONE
          && aiThink->score[aiThink->movesetIndex] > 0
          && ShouldConsiderMoveForBattler(battlerAtk, battlerDef, aiThink->moveConsidered))
        {
            if (IsChaseEffect(GetMoveEffect(aiThink->moveConsidered)))
            {
                // Save new switchin data
                simulatedDamageSwitchin[aiThink->movesetIndex] = aiData->simulatedDmg[battlerAtk][battlerDef][aiThink->movesetIndex];
                effectivenessSwitchin[aiThink->movesetIndex] = aiData->effectiveness[battlerAtk][battlerDef][aiThink->movesetIndex];
                moveAccuracySwitchin[aiThink->movesetIndex] = aiData->moveAccuracy[battlerAtk][battlerDef][aiThink->movesetIndex];

                // Restore old switchout data
                gBattleMons[battlerDef] = switchoutCandidate;
                SetBattlerAiData(battlerDef, aiData);
                aiData->simulatedDmg[battlerAtk][battlerDef][aiThink->movesetIndex] = simulatedDamageSwitchout[aiThink->movesetIndex];
                aiData->effectiveness[battlerAtk][battlerDef][aiThink->movesetIndex] = effectivenessSwitchout[aiThink->movesetIndex];
                aiData->moveAccuracy[battlerAtk][battlerDef][aiThink->movesetIndex] = moveAccuracySwitchout[aiThink->movesetIndex];

                if (aiThink->aiLogicId < ARRAY_COUNT(sBattleAiFuncTable)
                && sBattleAiFuncTable[aiThink->aiLogicId] != NULL)
                {
                    // Call AI function
                    aiThink->score[aiThink->movesetIndex] =
                        sBattleAiFuncTable[aiThink->aiLogicId](battlerAtk,
                        battlerDef,
                        aiThink->moveConsidered,
                        aiThink->score[aiThink->movesetIndex]);
                }

                // Restore new switchin data
                gBattleMons[battlerDef] = switchinCandidate;
                SetBattlerAiData(battlerDef, aiData);
                aiData->simulatedDmg[battlerAtk][battlerDef][aiThink->movesetIndex] = simulatedDamageSwitchin[aiThink->movesetIndex];
                aiData->effectiveness[battlerAtk][battlerDef][aiThink->movesetIndex] = effectivenessSwitchin[aiThink->movesetIndex];
                aiData->moveAccuracy[battlerAtk][battlerDef][aiThink->movesetIndex] = moveAccuracySwitchin[aiThink->movesetIndex];
            }

            else
            {
                if (aiThink->aiLogicId < ARRAY_COUNT(sBattleAiFuncTable)
                && sBattleAiFuncTable[aiThink->aiLogicId] != NULL)
                {
                    // Call AI function
                    aiThink->score[aiThink->movesetIndex] =
                        sBattleAiFuncTable[aiThink->aiLogicId](battlerAtk,
                        battlerDef,
                        aiThink->moveConsidered,
                        aiThink->score[aiThink->movesetIndex]);
                }
            }
        }
        else
        {
            aiThink->score[aiThink->movesetIndex] = 0;
        }
        aiThink->movesetIndex++;
    } while (aiThink->movesetIndex < MAX_MON_MOVES && !(aiThink->aiAction & AI_ACTION_DO_NOT_ATTACK));

    aiThink->movesetIndex = 0;

    // Restore original battler data and moves
    FreeRestoreBattleMons(savedBattleMons);
    SetBattlerAiData(battlerDef, aiData);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex] = simulatedDamageSwitchout[moveIndex];
        aiData->effectiveness[battlerAtk][battlerDef][moveIndex] = effectivenessSwitchout[moveIndex];
        aiData->moveAccuracy[battlerAtk][battlerDef][moveIndex] = moveAccuracySwitchout[moveIndex];
    }
}

// AI Score Functions
// AI_FLAG_CHECK_BAD_MOVE - decreases move scores
static s32 AI_CheckBadMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;

    // move data
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    enum MoveEffect nonVolatileStatus = GetMoveNonVolatileStatus(move);
    enum Type moveType;
    enum MoveTarget moveTarget = AI_GetBattlerMoveTargetType(battlerAtk, move);
    struct AiLogicData *aiData = gAiLogicData;
    uq4_12_t effectiveness = aiData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex];
    bool32 isBattle1v1 = IsBattle1v1();
    bool32 hasTwoOpponents = HasTwoOpponents(battlerAtk);
    bool32 hasPartner = HasPartner(battlerAtk);
    u32 weather = AI_GetWeather();
    enum Move incomingMove = GetIncomingMove(battlerAtk, battlerDef, gAiLogicData);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    enum Ability abilityAtk = aiData->abilities[battlerAtk];
    enum Ability abilityDef = aiData->abilities[battlerDef];
    s32 atkPriority = GetBattleMovePriority(battlerAtk, abilityAtk, move);

    SetTypeBeforeUsingMove(move, battlerAtk, abilityAtk, aiData->holdEffects[battlerAtk]);
    moveType = GetBattleMoveType(move);

    if (gBattleStruct->battlerState[battlerDef].commandingDondozo)
        RETURN_SCORE_MINUS(20);

    if (IsPowderMove(move) && !IsAffectedByPowderMove(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef]))
        RETURN_SCORE_MINUS(10);

    // Don't use moves that miss against already semi-invulnerable targets when we move first.
    if (!CanBreakThroughSemiInvulnerablity(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move)
     && moveEffect != EFFECT_SEMI_INVULNERABLE && AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
     && abilityAtk != ABILITY_NO_GUARD && abilityDef != ABILITY_NO_GUARD)
    {
        RETURN_SCORE_MINUS(10);
    }

    // Don't use moves that miss if a faster foe is predicted to enter a semi-invulnerable state this turn.
    if (!IsSemiInvulnerable(battlerDef, CHECK_ALL)
     && predictedMove != MOVE_NONE
     && predictedMove != MOVE_UNAVAILABLE
     && (GetMoveEffect(predictedMove) == EFFECT_SEMI_INVULNERABLE || GetMoveEffect(predictedMove) == EFFECT_SKY_DROP)
     && AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
     && moveEffect != EFFECT_SEMI_INVULNERABLE
     && aiData->holdEffects[battlerDef] != HOLD_EFFECT_POWER_HERB)
    {
        if (!BreaksThroughSemiInvulnerableState(battlerAtk, battlerDef, abilityAtk, abilityDef, move, GetTwoTurnMoveSemiInvulnerability(predictedMove)))
            RETURN_SCORE_MINUS(10);
    }

    // Don't choose slow two-turn moves or semi-invulnerable moves that fail under No Guard if the foe can KO us.
    if (CanTargetFaintAi(battlerDef, battlerAtk))
    {
        if (IsTwoTurnNotSemiInvulnerableMove(battlerAtk, move))
            RETURN_SCORE_MINUS(10);

        if (moveEffect == EFFECT_SEMI_INVULNERABLE && aiData->holdEffects[battlerAtk] != HOLD_EFFECT_POWER_HERB)
        {
            if (abilityAtk == ABILITY_NO_GUARD || abilityDef == ABILITY_NO_GUARD)
                RETURN_SCORE_MINUS(10);
        }
    }

    // Don't setup into expected Focus Punch.
    if (GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS
     && nonVolatileStatus != MOVE_EFFECT_SLEEP
     && GetMoveEffect(incomingMove) != EFFECT_FOCUS_PUNCH
     && BestDmgMoveHasEffect(battlerDef, battlerAtk, AI_DEFENDING, EFFECT_FOCUS_PUNCH)
     && RandomPercentage(RNG_AI_STATUS_FOCUS_PUNCH, STATUS_MOVE_FOCUS_PUNCH_CHANCE))
    {
        RETURN_SCORE_MINUS(20);
    }

    // Don't use anything but super effective thawing moves if target is frozen if any other attack available
    if ((CanFireMoveThawTarget(move, moveType) || CanBurnHitThaw(move) || CanMoveThawTarget(abilityAtk, move))
     && effectiveness < UQ_4_12(2.0) && (gBattleMons[battlerDef].status1 & STATUS1_ICY_ANY))
    {
        enum Move aiMove;
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            aiMove = gBattleMons[battlerAtk].moves[moveIndex];
            if (!CanFireMoveThawTarget(aiMove, CheckDynamicMoveType(GetBattlerMon(battlerAtk), aiMove, battlerAtk, MON_IN_BATTLE))
             && !CanBurnHitThaw(aiMove)
             && !CanMoveThawTarget(abilityAtk, aiMove))
            {
                ADJUST_SCORE(-1);
                break;
            }
        }
    }

    if (effectiveness == UQ_4_12(0.0))
        RETURN_SCORE_MINUS(20);

    if (DoesBattlerIgnoreAbilityChecks(battlerAtk, abilityAtk, move))
        abilityDef = ABILITY_NONE;

    // If a Pokémon can be guaranteed flinched, don't target the Pokémon that can't be flinched.
    if (hasTwoOpponents
     && !IsFlinchGuaranteed(battlerAtk, battlerDef, move) && IsFlinchGuaranteed(battlerAtk, GetPartnerBattler(battlerDef), move)
     && aiData->effectiveness[battlerAtk][GetPartnerBattler(battlerDef)][gAiThinkingStruct->movesetIndex] != UQ_4_12(0.0))
    {
        ADJUST_SCORE(-5);
    }

    // check non-user target
    if (moveTarget != TARGET_USER)
    {
        if (Ai_IsPriorityBlocked(battlerAtk, battlerDef, move, aiData))
            RETURN_SCORE_MINUS(20);

        struct DamageContext ctx = {0};
        ctx.battlerAtk = battlerAtk;
        ctx.battlerDef = battlerDef;
        ctx.move = ctx.chosenMove = ctx.baseMove = move;
        ctx.moveType = moveType;
        ctx.weather = GetWeather();
        ctx.terrain = gFieldTimers.terrain;
        ctx.abilities[ctx.battlerAtk] = abilityAtk;
        ctx.abilities[ctx.battlerDef] = abilityDef;
        ctx.holdEffects[ctx.battlerAtk] = aiData->holdEffects[battlerAtk];
        ctx.holdEffects[ctx.battlerDef] = aiData->holdEffects[battlerDef];

        if (AI_CanMoveBeBlockedByTarget(&ctx))
            RETURN_SCORE_MINUS(20);

        switch (abilityDef)
        {
        case ABILITY_MAGIC_GUARD:
            switch (moveEffect)
            {
            case EFFECT_LEECH_SEED:
                ADJUST_SCORE(-5);
                break;
            case EFFECT_CURSE:
                if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST)) // Don't use Curse if you're a ghost type vs a Magic Guard user, they'll take no damage.
                    ADJUST_SCORE(-5);
                break;
            default:
                break;
            }

            switch (nonVolatileStatus)
            {
            case MOVE_EFFECT_POISON:
            case MOVE_EFFECT_TOXIC:
            case MOVE_EFFECT_BURN:
                ADJUST_SCORE(-5);
                break;
            default:
                break;
            }
            break;
        case ABILITY_WONDER_GUARD:
            if (effectiveness < UQ_4_12(2.0))
                RETURN_SCORE_MINUS(20);
            break;
        case ABILITY_JUSTIFIED:
            if (moveType == TYPE_DARK && !IsBattleMoveStatus(move) && !IsTargetingPartner(battlerAtk, battlerDef))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_RATTLED:
            if (!IsBattleMoveStatus(move)
              && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_AROMA_VEIL:
            if (IsAromaVeilProtectedEffect(moveEffect))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_SWEET_VEIL:
            if (nonVolatileStatus == MOVE_EFFECT_SLEEP)
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_FLOWER_VEIL:
            if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS) && (IsNonVolatileStatusMove(move)))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_MAGIC_BOUNCE:
            if (MoveCanBeBouncedBack(move))
                RETURN_SCORE_MINUS(20);
            break;
        case ABILITY_CONTRARY:
            if (IsStatLoweringMove(move))
                RETURN_SCORE_MINUS(20);
            break;
        case ABILITY_COMATOSE:
            if (IsNonVolatileStatusMove(move))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_SHIELDS_DOWN:
            if (IsShieldsDownProtected(battlerAtk, aiData->abilities[battlerAtk]) && IsNonVolatileStatusMove(move))
                RETURN_SCORE_MINUS(10);
            break;
        case ABILITY_LEAF_GUARD:
            if ((AI_GetWeather() & B_WEATHER_SUN)
              && aiData->holdEffects[battlerDef] != HOLD_EFFECT_UTILITY_UMBRELLA
              && IsNonVolatileStatusMove(move))
                RETURN_SCORE_MINUS(10);
            break;
        default:
            break;
        } // def ability checks

        // target partner ability checks & not attacking partner
        if (hasTwoOpponents)
        {
            switch (aiData->abilities[GetPartnerBattler(battlerDef)])
            {
            case ABILITY_LIGHTNING_ROD:
                if (moveType == TYPE_ELECTRIC && !IsMoveRedirectionPrevented(battlerAtk, move, aiData->abilities[battlerAtk]))
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER && !IsMoveRedirectionPrevented(battlerAtk, move, aiData->abilities[battlerAtk]))
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_MAGIC_BOUNCE:
                if (CanMoveBeBouncedBack(battlerAtk, move))
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_SWEET_VEIL:
                if (nonVolatileStatus == MOVE_EFFECT_SLEEP)
                    RETURN_SCORE_MINUS(20);
                break;
            case ABILITY_FLOWER_VEIL:
                if ((IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)) && (IsNonVolatileStatusMove(move) || IsStatLoweringMove(move)))
                    RETURN_SCORE_MINUS(10);
                break;
            case ABILITY_AROMA_VEIL:
                if (IsAromaVeilProtectedEffect(moveEffect))
                    RETURN_SCORE_MINUS(10);
                break;
            default:
                break;
            }
        } // def partner ability checks

        // gen7+ dark type mons immune to priority->elevated moves from prankster
        if (GetConfig(B_PRANKSTER_DARK_TYPES) >= GEN_7 && IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK)
          && aiData->abilities[battlerAtk] == ABILITY_PRANKSTER && IsBattleMoveStatus(move)
          && moveTarget != TARGET_OPPONENTS_FIELD
          && moveTarget != TARGET_USER)
            RETURN_SCORE_MINUS(10);

        // terrain & effect checks
        if (IsElectricTerrainAffected(battlerDef, abilityDef, aiData->holdEffects[battlerDef], gFieldTimers.terrain))
        {
            if (nonVolatileStatus == MOVE_EFFECT_SLEEP)
                RETURN_SCORE_MINUS(20);
        }

        if (IsMistyTerrainAffected(battlerDef, abilityDef, aiData->holdEffects[battlerDef], gFieldTimers.terrain))
        {
            if (IsNonVolatileStatusMove(move) || IsConfusionMoveEffect(moveEffect))
                RETURN_SCORE_MINUS(20);
        }

        if (atkPriority > 0 && IsPsychicTerrainAffected(battlerAtk, abilityAtk, aiData->holdEffects[battlerAtk], gFieldTimers.terrain))
        {
            RETURN_SCORE_MINUS(20);
        }
    } // end check TARGET_USER

// the following checks apply to any target (including user)

    // throat chop check
    if (gBattleMons[battlerAtk].volatiles.throatChopTimer > 0 && IsSoundMove(move))
        return 0; // Can't even select move at all
    // heal block check
    if (IsHealBlockPreventingMove(battlerAtk, move))
        return 0; // Can't even select heal blocked move

    if (IsExplosionMove(move))
    {
        if (!aiData->shouldConsiderExplosion)
            ADJUST_SCORE(-5);
        if (effectiveness == UQ_4_12(0.0))
        {
            ADJUST_SCORE(-10);
        }
        else if (IsAbilityOnField(ABILITY_DAMP) && !DoesBattlerIgnoreAbilityChecks(battlerAtk, aiData->abilities[battlerAtk], move))
        {
            ADJUST_SCORE(-10);
        }
        else if (CountUsablePartyMons(battlerAtk) == 0 && LAST_MON_PREFERS_NOT_SACRIFICE)
        {
            if (CountUsablePartyMons(battlerDef) != 0)
                ADJUST_SCORE(-10);
            else
                ADJUST_SCORE(-1);
        }
    }

    // check move effects
    switch (moveEffect)
    {
    default:
        break;
    case EFFECT_HIT: // only applies to Vital Throw - This probably should not be here
        if (GetBattleMovePriority(battlerAtk, aiData->abilities[battlerAtk], move) < 0 && AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) && aiData->hpPercents[battlerAtk] < 40)
            ADJUST_SCORE(-2);    // don't want to move last
        break;
    case EFFECT_FINAL_GAMBIT:
        if (!aiData->shouldConsiderFinalGambit)
        {
            ADJUST_SCORE(-5);
        }
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            ADJUST_SCORE(-10);
        }
        else if (CountUsablePartyMons(battlerAtk) == 0 && LAST_MON_PREFERS_NOT_SACRIFICE)
        {
            if (CountUsablePartyMons(battlerDef) != 0)
                ADJUST_SCORE(-10);
            else
                ADJUST_SCORE(-1);
        }
        break;
    case EFFECT_ROTOTILLER:
    case EFFECT_FLOWER_SHIELD:
    {
        bool32 decreaseScore = TRUE;
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            if (!IsBattlerAlly(battlerAtk, battler) || !IsBattlerAlive(battler))
                continue; // ignore foes for score decrease

            if (moveEffect == EFFECT_ROTOTILLER && !AI_IsBattlerGrounded(battler))
                continue;

            if (!IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
                continue;

            if (AI_CanAnyStatChange(battlerAtk, battler, move))
                decreaseScore = FALSE;
        }

        if (decreaseScore)
            ADJUST_SCORE(-10);
    }
        break;
    case EFFECT_STAT_CHANGE_MAGNETIC:
    {
        bool32 decreaseScore = TRUE;
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            if (!IsBattlerAlly(battlerAtk, battler) || !IsBattlerAlive(battler))
                continue; // ignore targets for score decrease

            if (gAiLogicData->abilities[battler] != ABILITY_PLUS
             && gAiLogicData->abilities[battler] != ABILITY_MINUS)
                continue;

            if (AI_CanAnyStatChange(battlerAtk, battler, move))
                decreaseScore = FALSE;
        }

        if (decreaseScore)
            ADJUST_SCORE(-10);
    }
        break;
    case EFFECT_STUFF_CHEEKS:
        if (GetItemPocket(gBattleMons[battlerAtk].item) != POCKET_BERRIES)
            return 0;   // cannot even select
        if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CHARGE:
        if (gBattleMons[battlerAtk].volatiles.chargeTimer > 0)
            ADJUST_SCORE(-20);
        else if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC))
            ADJUST_SCORE(-10);
        if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_STAT_CHANGE_ON_STATUS:
        if (!(gBattleMons[battlerDef].status1 & GetMoveStatusOnStatChange(move)))
        {
            ADJUST_SCORE(-10);
        }
        else if (!AI_CanAnyStatChange(battlerAtk, battlerDef, move))
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_TAR_SHOT:
        if (!AI_CanAnyStatChange(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_EXTREME_EVOBOOST:
    case EFFECT_GROWTH:
    case EFFECT_MINIMIZE:
    case EFFECT_DEFENSE_CURL:
    case EFFECT_TIDY_UP:
    case EFFECT_GEOMANCY:
        if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NO_RETREAT:
        if (gBattleMons[battlerAtk].volatiles.noRetreat)
            ADJUST_SCORE(-10);
        else if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TOXIC_THREAD:
        if (!AI_CanAnyStatChange(battlerAtk, battlerDef, move)
         && !AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CURSE:
        if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
        {
            if (gBattleMons[battlerDef].volatiles.cursed
             || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10);
            }
            else if (aiData->hpPercents[battlerAtk] <= 50)
            {
                ADJUST_SCORE(-10);
            }
        }
        else if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_STOCKPILE:
        if (gBattleMons[battlerAtk].volatiles.stockpileCounter >= 3)
            ADJUST_SCORE(-10);
        else if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (aiData->hpPercents[battlerAtk] <= 50)
            ADJUST_SCORE(-10);
        else if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_STAT_CHANGE_HALF_HP:
    case EFFECT_BELLY_DRUM:
        if (AI_IsAbilityOnSide(battlerDef, ABILITY_UNAWARE))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] <= 60 && !IsConsideringZMove(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-10);
        else if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_AUTOTOMIZE:
    case EFFECT_STAT_CHANGE:
        if (AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_USER)
        {
            if (!AI_CanAnyStatChange(battlerAtk, battlerAtk, move))
                ADJUST_SCORE(-10);
        }
        else
        {
            if (!AI_CanAnyStatChange(battlerAtk, battlerDef, move))
            {
                ADJUST_SCORE(-10);
            }
        }
        break;
    case EFFECT_ACUPRESSURE:
        if (DoesSubstituteBlockMove(battlerAtk, battlerDef, move) || AreBattlersStatsMaxed(battlerDef))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CAPTIVATE:
        if (!AreBattlersOfOppositeGender(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        else if (!AI_CanAnyStatChange(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HAZE:
        if (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
        {
            ADJUST_SCORE(-10);    // partner already using haze
        }
        else
        {
            for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
            {
                if (gBattleMons[battlerAtk].statStages[statId] > DEFAULT_STAT_STAGE || gBattleMons[GetPartnerBattler(battlerAtk)].statStages[statId] > DEFAULT_STAT_STAGE)
                    ADJUST_SCORE(-10);  // Don't want to reset our boosted stats
            }
            for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
            {
                if (gBattleMons[battlerDef].statStages[statId] < DEFAULT_STAT_STAGE || gBattleMons[GetPartnerBattler(battlerDef)].statStages[statId] < DEFAULT_STAT_STAGE)
                    ADJUST_SCORE(-10); //Don't want to reset enemy lowered stats
            }
        }
        break;
    case EFFECT_PRESENT:
    case EFFECT_FIXED_HP_DAMAGE:
        if (aiData->abilities[battlerDef] == ABILITY_WONDER_GUARD && effectiveness < UQ_4_12(2.0))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FOCUS_PUNCH:
        // AI_CBM_HighRiskForDamage
        if (aiData->abilities[battlerDef] == ABILITY_WONDER_GUARD && effectiveness < UQ_4_12(2.0))
            ADJUST_SCORE(-10);
        if (HasDamagingMove(battlerDef) && !(gBattleMons[battlerAtk].volatiles.substitute
         || IsBattlerIncapacitated(battlerDef, abilityDef)
         || gBattleMons[battlerDef].volatiles.infatuation
         || gBattleMons[battlerDef].volatiles.confusionTimer))
            ADJUST_SCORE(-10);
        if (HasMoveWithEffect(battlerAtk, EFFECT_SUBSTITUTE) && !gBattleMons[battlerAtk].volatiles.substitute)
            ADJUST_SCORE(-10);
        if (HasNonVolatileMoveEffect(battlerAtk, MOVE_EFFECT_SLEEP) && ! (gBattleMons[battlerDef].status1 & STATUS1_SLEEP))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REFLECT_DAMAGE:
        if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef])
        || gBattleMons[battlerDef].volatiles.infatuation
        || gBattleMons[battlerDef].volatiles.confusionTimer > 0)
            ADJUST_SCORE(-1);
        if ((incomingMove == MOVE_NONE || GetBattleMoveCategory(incomingMove) == DAMAGE_CATEGORY_STATUS
          || DoesSubstituteBlockMove(battlerAtk, GetPartnerBattler(battlerDef), incomingMove))
          && !(incomingMove == MOVE_NONE && (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY))) // Let Risky AI predict blindly based on stats
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ROAR:
        if (CountUsablePartyMons(battlerDef) == 0)
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
            ADJUST_SCORE(-10);
        else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_LIGHT_SCREEN:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & (SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)
         || (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REFLECT:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & (SIDE_STATUS_REFLECT | SIDE_STATUS_AURORA_VEIL)
         || (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_AURORA_VEIL:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL
         || (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
         || !(weather & (B_WEATHER_ICY_ANY)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_OHKO:
        if (!ShouldTryOHKO(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move))
            ADJUST_SCORE(-10);
        else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_MIST:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FOCUS_ENERGY:
        if (gBattleMons[battlerAtk].volatiles.dragonCheer || gBattleMons[battlerAtk].volatiles.focusEnergy)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NON_VOLATILE_STATUS:
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CONFUSE:
    case EFFECT_SWAGGER:
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove)
        || !AI_CanConfuse(battlerAtk, battlerDef, aiData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SUBSTITUTE:
        if (gBattleMons[battlerAtk].volatiles.substitute || aiData->abilities[battlerDef] == ABILITY_INFILTRATOR)
            ADJUST_SCORE(-8);
        else if (aiData->hpPercents[battlerAtk] <= 25)
            ADJUST_SCORE(-10);
        else if (HasMoveWithFlag(battlerDef, MoveIgnoresSubstitute))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_SHED_TAIL:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);
        if (gBattleMons[battlerAtk].volatiles.substitute || aiData->abilities[battlerDef] == ABILITY_INFILTRATOR)
            ADJUST_SCORE(-8);
        else if (aiData->hpPercents[battlerAtk] <= 50)
            ADJUST_SCORE(-10);
        else if (HasMoveWithFlag(battlerDef, MoveIgnoresSubstitute))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_LEECH_SEED:
        if (gBattleMons[battlerDef].volatiles.leechSeed
         || IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
         || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
            ADJUST_SCORE(-3);
        break;
    case EFFECT_DISABLE:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].volatiles.disableTimer == 0
            && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
            && !DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Attacker should go first
            {
                if (aiData->lastUsedMove[battlerDef] == MOVE_NONE)
                    ADJUST_SCORE(-10);    // no anticipated move to disable
            }
            else if (incomingMove == MOVE_NONE)
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_ENCORE:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].volatiles.encoreTimer == 0
            && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
            && !DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Attacker should go first
            {
                if (aiData->lastUsedMove[battlerDef] == MOVE_NONE)
                    ADJUST_SCORE(-10);    // no anticipated move to encore
            }
            else if (incomingMove == MOVE_NONE)
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_SNORE:
    case EFFECT_SLEEP_TALK:
        if (IsWakeupTurn(battlerAtk) || !IsAsleepOrComatose(battlerAtk, aiData->abilities[battlerAtk]))
            ADJUST_SCORE(-10);    // if mon will wake up, is not asleep, or is not comatose
        break;
    case EFFECT_MEAN_LOOK:
        if (AI_CanBattlerEscape(battlerDef)
            || IsBattlerTrapped(battlerAtk, battlerDef)
            || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NIGHTMARE:
        if (gBattleMons[battlerDef].volatiles.nightmare)
            ADJUST_SCORE(-10);
        else if (!IsAsleepOrComatose(battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-8);
        else if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPIKES:
        if (gSideTimers[GetBattlerSide(battlerDef)].spikesAmount >= 3)
            ADJUST_SCORE(-10);
        else if (PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove)
          && gSideTimers[GetBattlerSide(battlerDef)].spikesAmount == 2)
            ADJUST_SCORE(-10); // only one mon needs to set up the last layer of Spikes
        break;
    case EFFECT_STEALTH_ROCK:
        if (IsHazardOnSide(GetBattlerSide(battlerDef), HAZARDS_STEALTH_ROCK)
          || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove)) //Only one mon needs to set up Stealth Rocks
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TOXIC_SPIKES:
        if (gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount >= 2)
            ADJUST_SCORE(-10);
        else if (PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount == 1)
            ADJUST_SCORE(-10); // only one mon needs to set up the last layer of Toxic Spikes
        break;
    case EFFECT_STICKY_WEB:
        if (IsHazardOnSide(GetBattlerSide(battlerDef), HAZARDS_STICKY_WEB))
            ADJUST_SCORE(-10);
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10); // only one mon needs to set up Sticky Web
        break;
    case EFFECT_FORESIGHT:
        if (gBattleMons[battlerDef].volatiles.foresight)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= DEFAULT_STAT_STAGE - 2
          || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST))
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-9);
        break;
    case EFFECT_PERISH_SONG:
        if (!isBattle1v1)
        {
            if (CountUsablePartyMons(battlerAtk) == 0
              && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF
              && CountUsablePartyMons(battlerDef) >= 1
              && (aiData->abilities[GetPartnerBattler(battlerAtk)] != ABILITY_SOUNDPROOF || !IsBattlerAlive(GetPartnerBattler(battlerAtk))))
            {
                ADJUST_SCORE(-10); //Don't wipe your team if you're going to lose
            }
            else if ((!IsBattlerAlive(GetBattlerLeftFoe(battlerAtk)) || aiData->abilities[GetBattlerLeftFoe(battlerAtk)] == ABILITY_SOUNDPROOF
              || gBattleMons[GetBattlerLeftFoe(battlerAtk)].volatiles.perishSong)
              && (!IsBattlerAlive(GetBattlerRightFoe(battlerAtk)) || aiData->abilities[GetBattlerRightFoe(battlerAtk)] == ABILITY_SOUNDPROOF
              || gBattleMons[GetBattlerRightFoe(battlerAtk)].volatiles.perishSong))
            {
                ADJUST_SCORE(-10); //Both enemies are perish songed
            }
            else if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10);
            }
        }
        else
        {
            if (CountUsablePartyMons(battlerAtk) == 0 && aiData->abilities[battlerAtk] != ABILITY_SOUNDPROOF
              && CountUsablePartyMons(battlerDef) >= 1)
                ADJUST_SCORE(-10);

            if (gBattleMons[battlerDef].volatiles.perishSong || aiData->abilities[battlerDef] == ABILITY_SOUNDPROOF)
                ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_WEATHER_AND_SWITCH:
        if (CountUsablePartyMons(battlerAtk) == 0)
        {
            ADJUST_SCORE(-10);
            break;
        }
        // fallthrough
    case EFFECT_WEATHER:
        switch (GetMoveWeatherType(move))
        {
        case BATTLE_WEATHER_RAIN:
            if (weather & (B_WEATHER_RAIN | B_WEATHER_PRIMAL_ANY))
                ADJUST_SCORE(-8);
            break;
        case BATTLE_WEATHER_SUN:
            if (weather & (B_WEATHER_SUN | B_WEATHER_PRIMAL_ANY))
                ADJUST_SCORE(-8);
            break;
        case BATTLE_WEATHER_SANDSTORM:
            if (weather & (B_WEATHER_SANDSTORM | B_WEATHER_PRIMAL_ANY))
                ADJUST_SCORE(-8);
            break;
        case BATTLE_WEATHER_HAIL:
        case BATTLE_WEATHER_SNOW:
            if (weather & (B_WEATHER_ICY_ANY | B_WEATHER_PRIMAL_ANY))
                ADJUST_SCORE(-8);
            break;
        default:
            break;
        }
        if (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-8);
        break;
    case EFFECT_ATTRACT:
        if (!AI_CanBeInfatuated(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SAFEGUARD:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PARTING_SHOT:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_BATON_PASS:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].volatiles.substitute
              || gBattleMons[battlerAtk].volatiles.powerTrick
              || gBattleMons[battlerAtk].volatiles.magnetRiseTimer > 0
              || gBattleMons[battlerAtk].volatiles.aquaRing
              || gBattleMons[battlerAtk].volatiles.root
              || AnyStatIsRaised(battlerAtk))
            break;
        else
            ADJUST_SCORE(-6);
        break;
    case EFFECT_HIT_ESCAPE:
        break;
    case EFFECT_FUTURE_SIGHT:
        if (gBattleStruct->futureSight[GetBattlerLeftFoe(battlerAtk)].counter > 0
         || gBattleStruct->futureSight[GetBattlerRightFoe(battlerAtk)].counter > 0)
            ADJUST_SCORE(-12);
        else
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_TELEPORT:
        ADJUST_SCORE(-10);
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (!IsBattlersFirstTurn(battlerAtk))
            ADJUST_SCORE(-10);
        if (HasChoiceEffect(battlerAtk))
            ADJUST_SCORE(-5);
        break;
    case EFFECT_SWALLOW:
        if (gBattleMons[battlerAtk].volatiles.stockpileCounter == 0)
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            if (AI_BattlerAtMaxHp(battlerAtk))
                ADJUST_SCORE(-10);
            else if (aiData->hpPercents[battlerAtk] >= 80)
                ADJUST_SCORE(-5); // do it if nothing better
        }
        break;
    case EFFECT_TORMENT:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].volatiles.torment
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
        {
            ADJUST_SCORE(-10);
            break;
        }
        if (B_MENTAL_HERB >= GEN_5 && aiData->holdEffects[battlerDef] == HOLD_EFFECT_MENTAL_HERB)
            ADJUST_SCORE(-6);
        break;
    case EFFECT_MEMENTO:
        if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE && gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FOLLOW_ME:
        if (!hasPartner
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove)
          || (aiData->partnerMove != MOVE_NONE && IsBattleMoveStatus(aiData->partnerMove))
          || gBattleStruct->monToSwitchIntoId[GetPartnerBattler(battlerAtk)] != PARTY_SIZE)
            ADJUST_SCORE(-20);
        break;
    case EFFECT_HELPING_HAND:
        if (!hasPartner
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove)
          || aiData->abilities[GetPartnerBattler(battlerAtk)] == ABILITY_GOOD_AS_GOLD
          || (aiData->partnerMove != MOVE_NONE && IsBattleMoveStatus(aiData->partnerMove))
          || gBattleStruct->monToSwitchIntoId[GetPartnerBattler(battlerAtk)] != PARTY_SIZE) //Partner is switching out.
            ADJUST_SCORE(-20);
        break;
    case EFFECT_TRICK:
        if ((gBattleMons[battlerAtk].item == ITEM_NONE && aiData->items[battlerDef] == ITEM_NONE)
          || !CanBattlerGetOrLoseItem(battlerAtk, battlerDef, gBattleMons[battlerAtk].item)
          || !CanBattlerGetOrLoseItem(battlerAtk, battlerDef, aiData->items[battlerDef])
          || !CanBattlerGetOrLoseItem(battlerDef, battlerAtk, aiData->items[battlerDef])
          || !CanBattlerGetOrLoseItem(battlerDef, battlerAtk, gBattleMons[battlerAtk].item)
          || DoesSubstituteBlockMove(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-10);
    case EFFECT_KNOCK_OFF:
    case EFFECT_CORROSIVE_GAS:
        if (aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_INGRAIN:
        if (gBattleMons[battlerAtk].volatiles.root)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_AQUA_RING:
        if (gBattleMons[battlerAtk].volatiles.aquaRing)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_RECYCLE:
        if (GetBattlerPartyState(battlerAtk)->usedHeldItem == 0 || gBattleMons[battlerAtk].item != 0)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_IMPRISON:
        if (gBattleMons[battlerAtk].volatiles.imprison)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REFRESH:
        if (!(gBattleMons[battlerAtk].status1 & STATUS1_CAN_MOVE)
         || !ShouldCureStatus(battlerAtk, battlerAtk, aiData))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PSYCHO_SHIFT:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && !AI_CanPoison(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && !AI_CanBurn(battlerAtk, battlerDef,
          aiData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_FROSTBITE && !AI_CanGiveFrostbite(battlerAtk, battlerDef,
          aiData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_PARALYSIS && !AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_SLEEP && !AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (!(gBattleMons[battlerAtk].status1 & STATUS1_ANY))
            ADJUST_SCORE(-10);    // attacker has no status to transmit
        break;
    case EFFECT_MUD_SPORT:
        if (gFieldStatuses & STATUS_FIELD_MUDSPORT
          || gBattleMons[battlerAtk].volatiles.mudSport
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_WATER_SPORT:
        if (gFieldStatuses & STATUS_FIELD_WATERSPORT
          || gBattleMons[battlerAtk].volatiles.waterSport
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_STRENGTH_SAP:
        if (aiData->abilities[battlerDef] == ABILITY_CONTRARY)
            ADJUST_SCORE(-10);
        else if (!CanLowerStat(battlerAtk, battlerDef, aiData, STAT_ATK))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_COPYCAT:
    case EFFECT_MIRROR_MOVE:
        if (incomingMove && GetMoveEffect(incomingMove) != GetMoveEffect(move))
            return AI_CheckBadMove(battlerAtk, battlerDef, incomingMove, score);
        else
            ADJUST_SCORE(-10);
        break;
    case EFFECT_BIDE:
        if (!HasDamagingMove(battlerDef)
          || aiData->hpPercents[battlerAtk] < 30 //Close to death
          || gBattleMons[battlerDef].status1 & STATUS1_INCAPACITATED) //No point in biding if can't take damage
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HIT_SWITCH_TARGET:
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10); // don't scare away Pokémon twice
        else if (aiData->hpPercents[battlerDef] < 10 && GetBattlerSecondaryDamage(battlerDef))
            ADJUST_SCORE(-10);    // don't blow away mon that will faint soon
        else if (gBattleMons[battlerDef].volatiles.perishSong)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CONVERSION:
        //Check first move type
        if (IS_BATTLER_OF_TYPE(battlerAtk, GetMoveType(gBattleMons[battlerAtk].moves[0])))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REST:
        if (!CanBeSlept(battlerAtk, battlerAtk, aiData->abilities[battlerAtk], NOT_BLOCKED_BY_SLEEP_CLAUSE))
            ADJUST_SCORE(-10);
        //fallthrough
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
        if (AI_BattlerAtMaxHp(battlerAtk))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(-9); //No point in healing, but should at least do it if nothing better
        break;
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (AI_BattlerAtMaxHp(battlerAtk))
            ADJUST_SCORE(-10);
        else if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(-9); //No point in healing, but should at least do it if nothing better
        else if ((AI_GetWeather() & (B_WEATHER_LOW_LIGHT)))
            ADJUST_SCORE(-3);
        break;
    case EFFECT_LIFE_DEW:
        if (AI_BattlerAtMaxHp(battlerAtk))
        {
            if (hasPartner)
            {
                if (AI_BattlerAtMaxHp(GetPartnerBattler(battlerAtk)))
                    ADJUST_SCORE(-10);
            }
            else
            {
                ADJUST_SCORE(-10);
            }
        }
        break;
    case EFFECT_PURIFY:
        if (!(gBattleMons[battlerDef].status1 & STATUS1_ANY))
            ADJUST_SCORE(-10);
        else if (battlerDef == GetPartnerBattler(battlerAtk))
            break; //Always heal your ally
        else if (!ShouldCureStatus(battlerAtk, battlerDef, aiData))
        {
            if (AI_BattlerAtMaxHp(battlerAtk))
                ADJUST_SCORE(-10);
            else if (aiData->hpPercents[battlerAtk] >= 90)
                ADJUST_SCORE(-8); //No point in healing, but should at least do it if nothing better
        }
        break;
    case EFFECT_RECOIL_IF_MISS:
        if (aiData->abilities[battlerAtk] != ABILITY_MAGIC_GUARD && gAiLogicData->moveAccuracy[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] < 75
        && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY))
            ADJUST_SCORE(-6);
        break;
    case EFFECT_TRANSFORM:
        if (gBattleMons[battlerAtk].volatiles.transformed
          || gBattleMons[battlerDef].volatiles.transformed
          || gBattleMons[battlerDef].volatiles.substitute) //Leave out Illusion b/c AI is supposed to be fooled
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPITE:
    case EFFECT_MIMIC:
        if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Attacker should go first
        {
            if (aiData->lastUsedMove[battlerDef] == MOVE_NONE)
                ADJUST_SCORE(-10);
        }
        else if (incomingMove == MOVE_NONE)
        {
            // TODO predicted move separate from aiData->lastUsedMove
            ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_METRONOME:
        break;

    case EFFECT_CONVERSION_2:
        //TODO
        break;
    case EFFECT_LOCK_ON:
        if (gBattleMons[battlerAtk].volatiles.battlerWithSureHit != 0
          || aiData->abilities[battlerAtk] == ABILITY_NO_GUARD
          || aiData->abilities[battlerDef] == ABILITY_NO_GUARD
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_LASER_FOCUS:
        if (gBattleMons[battlerDef].volatiles.laserFocusTimer > 0)
            ADJUST_SCORE(-10);
        else if (aiData->abilities[battlerDef] == ABILITY_SHELL_ARMOR || aiData->abilities[battlerDef] == ABILITY_BATTLE_ARMOR)
            ADJUST_SCORE(-8);
        break;
    case EFFECT_SKETCH:
        if (aiData->lastUsedMove[battlerDef] == MOVE_NONE)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DESTINY_BOND:
        if (DoesDestinyBondFail(battlerAtk))
            ADJUST_SCORE(-10);
        if (gBattleMons[battlerAtk].volatiles.destinyBond)
            ADJUST_SCORE(-10);
        else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HEAL_BELL:
        if (!AnyPartyMemberStatused(battlerAtk, IsSoundMove(move)) || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ENDURE:
        if (gBattleMons[battlerAtk].hp == 1 || GetBattlerSecondaryDamage(battlerAtk)) //Don't use Endure if you'll die after using it
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PROTECT:
        {
            bool32 decreased = FALSE;
            enum ProtectMethod protectMethod = GetMoveProtectMethod(move);
            switch (protectMethod)
            {
            case PROTECT_QUICK_GUARD:
                if (GetMovePriority(incomingMove) <= 0)
                {
                    ADJUST_SCORE(-10);
                    decreased = TRUE;
                }
                break;
            case PROTECT_WIDE_GUARD:
            {
                enum MoveTarget predictedTargetType = AI_GetBattlerMoveTargetType(battlerDef, incomingMove);
                if (!(predictedTargetType == TARGET_BOTH || predictedTargetType == TARGET_FOES_AND_ALLY))
                {
                    ADJUST_SCORE(-10);
                    decreased = TRUE;
                }
                break;
            }
            case PROTECT_CRAFTY_SHIELD:
                if (!hasPartner)
                {
                    ADJUST_SCORE(-10);
                    decreased = TRUE;
                }
                break;
            case PROTECT_MAT_BLOCK:
                if (!IsBattlersFirstTurn(battlerAtk))
                {
                    ADJUST_SCORE(-10);
                    decreased = TRUE;
                }
                break;
            default:
                break;
            } // move check

            if (decreased)
                break;
            if (incomingMove != MOVE_NONE && incomingMove != MOVE_UNAVAILABLE)
            {
                if (MoveIgnoresProtect(incomingMove))
                {
                    ADJUST_SCORE(-10);
                    break;
                }
            }
            if (protectMethod != PROTECT_MAX_GUARD
             && AI_CanContactBypassProtect(battlerDef, battlerAtk, incomingMove))
            {
                ADJUST_SCORE(-10);
                break;
            }
            if (IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]))
            {
                ADJUST_SCORE(-10);
                break;
            }

            if (protectMethod != PROTECT_QUICK_GUARD
             && protectMethod != PROTECT_WIDE_GUARD
             && protectMethod != PROTECT_CRAFTY_SHIELD) //These moves have infinite usage
            {
                if (GetBattlerSecondaryDamage(battlerAtk) >= gBattleMons[battlerAtk].hp
                  && !(IsMoxieTypeAbility(aiData->abilities[battlerDef])))
                {
                    ADJUST_SCORE(-10); //Don't protect if you're going to faint after protecting
                }
                else if (gBattleMons[battlerAtk].volatiles.consecutiveMoveUses == 1 && Random() % 100 < 50)
                {
                    if (isBattle1v1)
                        ADJUST_SCORE(-6);
                    else
                        ADJUST_SCORE(-10); //Don't try double protecting in doubles
                }
                else if (gBattleMons[battlerAtk].volatiles.consecutiveMoveUses >= 2)
                {
                    ADJUST_SCORE(-10);
                }
            }

            /*if (gAiThinkingStruct->aiFlags[battlerAtk] == AI_SCRIPT_CHECK_BAD_MOVE //Only basic AI
            && IsDoubleBattle()) //Make the regular AI know how to use Protect minimally in Doubles
            {
                u8 shouldProtect = ShouldProtect(battlerAtk, battlerDef, move);
                if (shouldProtect == USE_PROTECT || shouldProtect == PROTECT_FROM_FOES)
                    IncreaseFoeProtectionViability(&viability, 0xFF, battlerAtk, battlerDef);
                else if (shouldProtect == PROTECT_FROM_ALLIES)
                    IncreaseAllyProtectionViability(&viability, 0xFF);
            }*/
        }
        break;
    case EFFECT_MIRACLE_EYE:
        if (gBattleMons[battlerDef].volatiles.miracleEye)
            ADJUST_SCORE(-10);

        if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= DEFAULT_STAT_STAGE - 2
          || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-9);
        break;
    case EFFECT_COURT_CHANGE:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_BAD_COURT)
            ADJUST_SCORE(BAD_EFFECT);
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_GOOD_COURT)
            ADJUST_SCORE(BAD_EFFECT);
        if (AreAnyHazardsOnSide(GetBattlerSide(battlerDef)) && CountUsablePartyMons(battlerAtk) != 0)
            ADJUST_SCORE(WORST_EFFECT);
        if (hasPartner)
        {
            if (IsHazardMove(aiData->partnerMove) // partner is going to set up hazards
              && AI_IsFaster(GetPartnerBattler(battlerAtk), battlerAtk, aiData->partnerMove, incomingMove, CONSIDER_PRIORITY)) // partner is going to set up before the Court Change
            {
                ADJUST_SCORE(-10);
                break; // Don't use Defog if partner is going to set up hazards
            }
        }
        break;
    case EFFECT_DEFOG:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & (SIDE_STATUS_SCREEN_ANY | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)
         || AreAnyHazardsOnSide(GetBattlerSide(battlerAtk)))
        {
            if (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10); //Only need one hazards removal
                break;
            }
        }

        if (AreAnyHazardsOnSide(GetBattlerSide(battlerDef)))
        {
            ADJUST_SCORE(-10); //Don't blow away opposing hazards
            break;
        }

        if (hasPartner)
        {
            if (IsHazardMove(aiData->partnerMove) // partner is going to set up hazards
              && AI_IsFaster(GetPartnerBattler(battlerAtk), battlerAtk, aiData->partnerMove, predictedMove, CONSIDER_PRIORITY)) // partner is going to set up before the potential Defog
            {
                ADJUST_SCORE(-10);
                break; // Don't use Defog if partner is going to set up hazards
            }
        }

        // evasion check
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] == MIN_STAT_STAGE
          || ((aiData->abilities[battlerDef] == ABILITY_CONTRARY) && !IsTargetingPartner(battlerAtk, battlerDef))) // don't want to raise target stats unless its your partner
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PSYCH_UP:   // haze stats check
        {
            for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
            {
                if (gBattleMons[battlerAtk].statStages[statId] > DEFAULT_STAT_STAGE || gBattleMons[GetPartnerBattler(battlerAtk)].statStages[statId] > DEFAULT_STAT_STAGE)
                    ADJUST_SCORE(-10);  // Don't want to reset our boosted stats
            }
            for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
            {
                if (gBattleMons[battlerDef].statStages[statId] < DEFAULT_STAT_STAGE || gBattleMons[GetPartnerBattler(battlerDef)].statStages[statId] < DEFAULT_STAT_STAGE)
                    ADJUST_SCORE(-10); //Don't want to copy enemy lowered stats
            }
        }
        break;
    case EFFECT_SEMI_INVULNERABLE:
        if (incomingMove != MOVE_NONE
          && AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
          && GetMoveEffect(incomingMove) == EFFECT_SEMI_INVULNERABLE)
            ADJUST_SCORE(-10); // Don't Fly/dig/etc if opponent is going to fly/dig/etc after you

        if (BattlerWillFaintFromWeather(battlerAtk, aiData->abilities[battlerAtk])
          && GetTwoTurnMoveSemiInvulnerability(move) == STATE_ON_AIR)
            ADJUST_SCORE(-10); // Attacker will faint while in the air
        break;
    case EFFECT_HEALING_WISH:   //healing wish, lunar dance
        if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        else if (IsPartyFullyHealedExceptBattler(battlerAtk))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_NATURE_POWER:
        incomingMove = GetNaturePowerMove();
        if (GetMoveEffect(incomingMove) != GetMoveEffect(move))
            return AI_CheckBadMove(battlerAtk, battlerDef, GetNaturePowerMove(), score);
        break;
    case EFFECT_TAUNT:
        if (gBattleMons[battlerDef].volatiles.tauntTimer > 0
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_BESTOW:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_NONE
          || aiData->items[battlerDef] != ITEM_NONE
          || !CanBattlerGetOrLoseItem(battlerAtk, battlerDef, gBattleMons[battlerAtk].item)    // AI knows its own item
          || !CanBattlerGetOrLoseItem(battlerDef, battlerAtk, gBattleMons[battlerAtk].item)
          || DoesSubstituteBlockMove(battlerAtk, battlerDef, move))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_WISH:
        if (gBattleStruct->wish[battlerAtk].counter > 0)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ASSIST:
        if (CountUsablePartyMons(battlerAtk) == 0)
            ADJUST_SCORE(-10);    // no teammates to assist from
        break;
    case EFFECT_MAGIC_COAT:
        if (!HasMoveWithFlag(battlerDef, MoveCanBeBouncedBack))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_YAWN:
        if (gBattleMons[battlerDef].volatiles.yawn)
            ADJUST_SCORE(-10);
        else if ((aiData->holdEffects[battlerDef] == HOLD_EFFECT_FLAME_ORB && CanBeBurned(battlerDef, battlerDef, abilityDef))
              || (aiData->holdEffects[battlerDef] == HOLD_EFFECT_TOXIC_ORB && CanBePoisoned(battlerDef, battlerDef, abilityDef, abilityDef)))
            ADJUST_SCORE(-10);
        else if (!AI_CanPutToSleep(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        if (PartnerMoveActivatesSleepClause(aiData->partnerMove))
            ADJUST_SCORE(-20);
        break;
    case EFFECT_DOODLE:
    case EFFECT_ENTRAINMENT:
    case EFFECT_GASTRO_ACID:
    case EFFECT_ROLE_PLAY:
    case EFFECT_SKILL_SWAP:
    case EFFECT_OVERWRITE_ABILITY:
        if (!CanEffectChangeAbility(battlerAtk, battlerDef, move, aiData)
         || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_AND_RETURN_SCORE(NO_DAMAGE_OR_FAILS);
        break;
    case EFFECT_SNATCH:
        if (!HasMoveWithFlag(battlerDef, MoveCanBeSnatched)
         || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_POWER_TRICK:
        if (IsTargetingPartner(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].defense >= gBattleMons[battlerAtk].attack && !HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_POWER_SWAP: // Don't use if attacker's stat stages are higher than opponents
        if (IsTargetingPartner(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= gBattleMons[battlerDef].statStages[STAT_ATK]
          && gBattleMons[battlerAtk].statStages[STAT_SPATK] >= gBattleMons[battlerDef].statStages[STAT_SPATK])
            ADJUST_SCORE(-10);
        break;
    case EFFECT_GUARD_SWAP: // Don't use if attacker's stat stages are higher than opponents
        if (IsTargetingPartner(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        else if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= gBattleMons[battlerDef].statStages[STAT_DEF]
          && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= gBattleMons[battlerDef].statStages[STAT_SPDEF])
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SPEED_SWAP:
        if (IsTargetingPartner(battlerAtk, battlerDef))
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && (gBattleMons[battlerAtk].speed <= gBattleMons[battlerDef].speed))
                ADJUST_SCORE(-10);
            else if (gBattleMons[battlerAtk].speed >= gBattleMons[battlerDef].speed)
                ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_HEART_SWAP:
        if (IsTargetingPartner(battlerAtk, battlerDef))
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            u32 atkPositiveStages = CountPositiveStatStages(battlerAtk);
            u32 atkNegativeStages = CountNegativeStatStages(battlerAtk);
            u32 defPositiveStages = CountPositiveStatStages(battlerDef);
            u32 defNegativeStages = CountNegativeStatStages(battlerDef);

            if (atkPositiveStages >= defPositiveStages && atkNegativeStages <= defNegativeStages)
                ADJUST_SCORE(-10);
            break;
        }
        break;
    case EFFECT_POWER_SPLIT:
        if (!IsTargetingPartner(battlerAtk, battlerDef))
        {
            u32 atkAttack = gBattleMons[battlerAtk].attack;
            u32 defAttack = gBattleMons[battlerDef].attack;
            u32 atkSpAttack = gBattleMons[battlerAtk].spAttack;
            u32 defSpAttack = gBattleMons[battlerDef].spAttack;

            if (atkAttack + atkSpAttack >= defAttack + defSpAttack) // Combined attacker stats are > than combined target stats
                ADJUST_SCORE(-10);
            break;
        }
        break;
    case EFFECT_GUARD_SPLIT:
        if (!IsTargetingPartner(battlerAtk, battlerDef))
        {
            u32 atkDefense = gBattleMons[battlerAtk].defense;
            u32 defDefense = gBattleMons[battlerDef].defense;
            u32 atkSpDefense = gBattleMons[battlerAtk].spDefense;
            u32 defSpDefense = gBattleMons[battlerDef].spDefense;

            if (atkDefense + atkSpDefense >= defDefense + defSpDefense) //Combined attacker stats are > than combined target stats
                ADJUST_SCORE(-10);
            break;
        }
        break;
    case EFFECT_ME_FIRST:
        if (incomingMove != MOVE_NONE)
        {
            if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
                ADJUST_SCORE(-10);    // Target is predicted to go first, Me First will fail
            else if (GetMoveEffect(incomingMove) != GetMoveEffect(move))
                return AI_CheckBadMove(battlerAtk, battlerDef, incomingMove, score);
        }
        else
        {
            ADJUST_SCORE(-10); //Target is predicted to switch most likely
        }
        break;
    case EFFECT_NATURAL_GIFT:
        if (!IsBattlerItemEnabled(battlerAtk) || GetItemPocket(gBattleMons[battlerAtk].item) != POCKET_BERRIES)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TERRAIN:
        if (gFieldTimers.terrain == GetMoveTerrainType(move)
         || (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_STEEL_ROLLER:
        if (gFieldTimers.terrain == B_TERRAIN_NONE
         || (HasPartner(battlerAtk) && AreMovesEquivalent(battlerAtk, GetPartnerBattler(battlerAtk), move, aiData->partnerMove)))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PLEDGE:
        if (hasPartner && gBattleMons[GetPartnerBattler(battlerAtk)].hp > 0)
        {
            if (aiData->partnerMove != MOVE_NONE
              && GetMoveEffect(aiData->partnerMove) == EFFECT_PLEDGE
              && move != aiData->partnerMove) // Different pledge moves
            {
                if (gBattleMons[GetPartnerBattler(battlerAtk)].status1 & STATUS1_INCAPACITATED)
                // && gBattleMons[GetPartnerBattler(battlerAtk)].status1 != 1) // Will wake up this turn - how would AI know
                    ADJUST_SCORE(-10); // Don't use combo move if your partner will cause failure
            }
        }
        break;
    case EFFECT_TRICK_ROOM:
        if (PartnerMoveEffectIs(GetPartnerBattler(battlerAtk), aiData->partnerMove, EFFECT_TRICK_ROOM))
        {
            // This only happens if the ally already rolled on double trick room on final turn.
            // Both Pokemon use Trick Room on the final turn of Trick Room to anticipate both opponents Protecting to stall out.
            if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer == 1)
                ADJUST_SCORE(PERFECT_EFFECT);
            else
                ADJUST_SCORE(-10);
        }
        else if (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
        {
            // Don't set a trick room you don't benefit from.
            if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && !ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                    ADJUST_SCORE(-10);
            // Don't unset a trick room that doesn't harm you unless it's about to expire.
            else if ((gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && gFieldTimers.trickRoomTimer > 1 && !ShouldClearFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                    ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_MAGIC_ROOM:
        if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_WONDER_ROOM:
        if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_GRAVITY:
        if ((gFieldStatuses & STATUS_FIELD_GRAVITY
          && !IS_BATTLER_OF_TYPE(battlerAtk, TYPE_FLYING)
          && aiData->holdEffects[battlerAtk] != HOLD_EFFECT_AIR_BALLOON) // Should revert Gravity in this case
          || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_ION_DELUGE:
        if (gFieldStatuses & STATUS_FIELD_ION_DELUGE
          || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FLING:
        if (!CanFling(battlerAtk, abilityAtk))
        {
            ADJUST_SCORE(-10);
        }
        else
        {
            /* TODO Fling
            u8 effect = gFlingTable[gBattleMons[battlerAtk].item].effect;
            switch (effect)
            {
            case MOVE_EFFECT_BURN:
                break;
            case MOVE_EFFECT_PARALYSIS:
                break;
            case MOVE_EFFECT_POISON:
                break;
            case MOVE_EFFECT_TOXIC:
                break;
            case MOVE_EFFECT_FREEZE:
                break;
            }*/
        }
        break;
    case EFFECT_EMBARGO:
        if (!IsBattlerItemEnabled(battlerAtk)
          || gBattleMons[battlerDef].volatiles.embargoTimer
          || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_POWDER:
        if (!HasMoveWithType(battlerDef, TYPE_FIRE)
          || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TELEKINESIS:
        if (gBattleMons[battlerDef].volatiles.telekinesis
         || gBattleMons[battlerDef].volatiles.root
         || gBattleMons[battlerDef].volatiles.smackDown
         || gFieldStatuses & STATUS_FIELD_GRAVITY
         || aiData->holdEffects[battlerDef] == HOLD_EFFECT_IRON_BALL
         || IsTelekinesisBannedSpecies(gBattleMons[battlerDef].species)
         || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HEAL_BLOCK:
        if (gBattleMons[battlerDef].volatiles.healBlockTimer
          || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SOAK:
    {
        enum Type types[3];
        enum Type typeArg = GetMoveArgType(move);

        GetBattlerTypes(battlerDef, FALSE, types);
        if (PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove)
            || (types[0] == typeArg && types[1] == typeArg && types[2] == TYPE_MYSTERY))
            ADJUST_SCORE(-10);    // target is already water-only
        break;
    }
    case EFFECT_THIRD_TYPE:
        if (IS_BATTLER_OF_TYPE(battlerDef, GetMoveArgType(move)) || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove) || GetActiveGimmick(battlerDef) == GIMMICK_TERA)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HEAL_PULSE: // and floral healing
        if (!IsTargetingPartner(battlerAtk, battlerDef)) // Don't heal enemies
        {
            ADJUST_SCORE(-10);
            break;
        }
        // fallthrough
    case EFFECT_HIT_ENEMY_HEAL_ALLY:    // pollen puff
        if (IsTargetingPartner(battlerAtk, battlerDef))
        {
            if (gBattleMons[battlerDef].volatiles.healBlockTimer)
                return 0; // cannot even select
            if (AI_BattlerAtMaxHp(battlerDef))
                ADJUST_SCORE(-10);
            else if (gBattleMons[battlerDef].hp > gBattleMons[battlerDef].maxHP / 2)
                ADJUST_SCORE(-5);
        }
        break;
    case EFFECT_ELECTRIFY:
        if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
          //|| GetMoveTypeSpecial(battlerDef, predictedMove) == TYPE_ELECTRIC // Move will already be electric type
          || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TOPSY_TURVY:
        if (!IsTargetingPartner(battlerAtk, battlerDef))
        {
            u32 targetPositiveStages = CountPositiveStatStages(battlerDef);
            u32 targetNegativeStages = CountNegativeStatStages(battlerDef);

            if (targetPositiveStages == 0 //No good stat changes to make bad
              || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
                ADJUST_SCORE(-10);

            else if (targetNegativeStages < targetPositiveStages)
                ADJUST_SCORE(-5); //More stages would be made positive than negative
        }
        break;
    case EFFECT_FAIRY_LOCK:
        if ((gFieldStatuses & STATUS_FIELD_FAIRY_LOCK) || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DO_NOTHING:
    case EFFECT_HOLD_HANDS:
    case EFFECT_CELEBRATE:
    case EFFECT_HAPPY_HOUR:
        if (IsConsideringZMove(battlerAtk, battlerDef, move))
            break;
        ADJUST_SCORE(-10);
        break;
    case EFFECT_INSTRUCT:
        {
            u32 instructedMove;
            if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
                instructedMove = incomingMove;
            else
                instructedMove = aiData->lastUsedMove[battlerDef];

            if (instructedMove == MOVE_NONE
             || IsMoveInstructBanned(instructedMove)
             || MoveHasAdditionalEffectSelf(instructedMove, MOVE_EFFECT_RECHARGE)
             || IsZMove(instructedMove)
             || (gLockedMoves[battlerDef] != MOVE_NONE && gLockedMoves[battlerDef] != MOVE_UNAVAILABLE)
             || gBattleMons[battlerDef].volatiles.multipleTurns
             || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            {
                ADJUST_SCORE(-10);
            }
            else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            {
                ADJUST_SCORE(-10);
            }
            else if (hasPartner)
            {
                if (!IsTargetingPartner(battlerAtk, battlerDef))
                    ADJUST_SCORE(-10);
            }
            else if (ShouldInstructPartner(battlerDef, instructedMove))
            {
                ADJUST_SCORE(-10); //Don't force the enemy to attack you again unless it can kill itself with Mind Blown
            }
        }
        break;
    case EFFECT_QUASH:
        if (!hasPartner
        || AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
        || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_AFTER_YOU:
        if (!IsTargetingPartner(battlerAtk, battlerDef)
          || !hasPartner
          || AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
          || PartnerMoveIsSameAsAttacker(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SUCKER_PUNCH:
        if ((HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_STATUS) && RandomPercentage(RNG_AI_SUCKER_PUNCH, SUCKER_PUNCH_CHANCE)) // Player has a status move
        || (IsBattleMoveStatus(incomingMove) && RandomPercentage(RNG_AI_SUCKER_PUNCH, SUCKER_PUNCH_PREDICTION_CHANCE) && (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_PREDICT_MOVE)) // AI actively predicting incoming status move
        || AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Opponent going first
            ADJUST_SCORE(-10);
        break;
    case EFFECT_TAILWIND:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_TAILWIND
         || PartnerMoveEffectIs(GetPartnerBattler(battlerAtk), aiData->partnerMove, EFFECT_TAILWIND)
         || (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer == 1))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_LUCKY_CHANT:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_LUCKY_CHANT
          || PartnerMoveIsSameNoTarget(GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_MAGNET_RISE:
        if (gFieldStatuses & STATUS_FIELD_GRAVITY
          || gBattleMons[battlerAtk].volatiles.magnetRiseTimer > 0
          || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_IRON_BALL
          || gBattleMons[battlerAtk].volatiles.smackDown
          || gBattleMons[battlerAtk].volatiles.root
          || !AI_IsBattlerGrounded(battlerAtk))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_CAMOUFLAGE:
        if (!CanCamouflage(battlerAtk))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_SYNCHRONOISE:
        //Check holding ring target or is of same type
        if (aiData->holdEffects[battlerDef] != HOLD_EFFECT_RING_TARGET
        && !DoBattlersShareType(battlerAtk, battlerDef))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_FLAIL:
        if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) // Opponent should go first
            || aiData->hpPercents[battlerAtk] > 50)
            ADJUST_SCORE(-4);
        break;
    //TODO
    //case EFFECT_SHELL_TRAP:
        //break;
    //case EFFECT_BEAK_BLAST:
        //break;
    case EFFECT_SKY_DROP:
        if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING))
            ADJUST_SCORE(-10);
        if (BattlerWillFaintFromWeather(battlerAtk, aiData->abilities[battlerAtk])
        ||  DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
        ||  GetBattlerWeight(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef]) >= 2000) //200.0 kg
            ADJUST_SCORE(-10);
        break;
    case EFFECT_REVIVAL_BLESSING:
        if (GetFirstFaintedPartyIndex(battlerAtk) == PARTY_SIZE)
            ADJUST_SCORE(-10);
        else if (CanAIFaintTarget(battlerAtk, battlerDef, 0))
            ADJUST_SCORE(-10);
        else if (CanTargetFaintAi(battlerDef, battlerAtk)
         && AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_JUNGLE_HEALING:
    {
        bool32 canCureSelf = (gBattleMons[battlerAtk].status1 & STATUS1_ANY) && ShouldCureStatus(battlerAtk, battlerAtk, aiData);
        bool32 canCurePartner = (gBattleMons[GetPartnerBattler(battlerAtk)].status1 & STATUS1_ANY) && ShouldCureStatus(battlerAtk, GetPartnerBattler(battlerAtk), aiData);

        if (AI_BattlerAtMaxHp(battlerAtk)
            && AI_BattlerAtMaxHp(GetPartnerBattler(battlerAtk))
            && !canCureSelf
            && !canCurePartner)
            ADJUST_SCORE(-10);
        break;
    }
    case EFFECT_TAKE_HEART:
        if ((!(gBattleMons[battlerAtk].status1 & STATUS1_ANY)
         || PartnerMoveEffectIs(GetPartnerBattler(battlerAtk), aiData->partnerMove, EFFECT_JUNGLE_HEALING)
         || PartnerMoveEffectIs(GetPartnerBattler(battlerAtk), aiData->partnerMove, EFFECT_HEAL_BELL))
         && !BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK)
         && !BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_UPPER_HAND:
        {
            u32 defPrio = GetBattleMovePriority(battlerDef, aiData->abilities[battlerDef], incomingMove);
            if (incomingMove == MOVE_NONE
             || IsBattleMoveStatus(incomingMove)
             || AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
             || defPrio < 1
             || defPrio > 3) // Opponent going first or not using priority move
                ADJUST_SCORE(-10);
        }
        break;
    case EFFECT_TEATIME:
        if (DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        break;
    case EFFECT_DARK_VOID:
        if (B_DARK_VOID_FAIL >= GEN_7 && gBattleMons[battlerAtk].species != SPECIES_DARKRAI)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_HYPERSPACE_FURY:
        if (gBattleMons[battlerAtk].species != SPECIES_HOOPA_UNBOUND)
            ADJUST_SCORE(-10);
        break;
    case EFFECT_PLACEHOLDER:
        return 0;   // cannot even select
    } // move effect checks

    // check non-volatile effects
    switch (nonVolatileStatus)
    {
    case MOVE_EFFECT_POISON:
    case MOVE_EFFECT_TOXIC:
        if (!AI_CanPoison(battlerAtk, battlerDef, abilityDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        if (!ShouldPoison(battlerAtk, battlerDef))
            ADJUST_SCORE(-5);
        break;
    case MOVE_EFFECT_SLEEP:
        if (!AI_CanPutToSleep(battlerAtk, battlerDef, abilityDef, move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        if (PartnerMoveActivatesSleepClause(aiData->partnerMove))
            ADJUST_SCORE(-20);
        break;
    case MOVE_EFFECT_PARALYSIS:
        if (!AI_CanParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef], move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        if (!ShouldParalyze(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-5);
        break;
    case MOVE_EFFECT_BURN:
        if (!AI_CanBurn(battlerAtk, battlerDef, aiData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, aiData->partnerMove))
            ADJUST_SCORE(-10);
        if (!ShouldBurn(battlerAtk, battlerDef, aiData->abilities[battlerDef]))
            ADJUST_SCORE(-5);
        break;
    default:
        break;
    }

    // Choice items
    if (IsHoldEffectChoice(aiData->holdEffects[battlerAtk]) && IsBattlerItemEnabled(battlerAtk))
    {
        // Don't use user-target moves ie. Swords Dance, with exceptions
        if ((moveTarget == TARGET_USER)
        && moveEffect != EFFECT_DESTINY_BOND && moveEffect != EFFECT_WISH && moveEffect != EFFECT_HEALING_WISH
        && !(moveEffect == EFFECT_AURORA_VEIL && (AI_GetWeather() & B_WEATHER_ICY_ANY)))
            ADJUST_SCORE(-30);
        // Don't use a status move if the mon is the last one in the party, has no good switchin, or is trapped
        else if (GetBattleMoveCategory(move) == DAMAGE_CATEGORY_STATUS
            && (CountUsablePartyMons(battlerAtk) < 1
            || gAiLogicData->mostSuitableMonId[battlerAtk] == PARTY_SIZE
            || IsBattlerTrapped(battlerDef, battlerAtk)))
            ADJUST_SCORE(-30);
    }

    if (score < 0)
        score = 0;

    return score;
}

static s32 AI_GetWhichBattlerFasterOrTies(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 ignoreChosenMoves)
{
    struct BattleCalcValues calcValues = {0};
    calcValues.battlerAtk = battlerAtk;
    calcValues.battlerDef = battlerDef;
    calcValues.abilities[battlerAtk]  = gAiLogicData->abilities[battlerAtk];
    calcValues.abilities[battlerDef]  = gAiLogicData->abilities[battlerDef];
    calcValues.holdEffects[battlerAtk] = gAiLogicData->holdEffects[battlerAtk];
    calcValues.holdEffects[battlerDef] = gAiLogicData->holdEffects[battlerDef];

    return GetWhichBattlerFasterOrTies(&calcValues, ignoreChosenMoves);
}

static s32 AI_TryToFaint(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    u32 movesetIndex = gAiThinkingStruct->movesetIndex;
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY);

    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;

    if (IsBattleMoveStatus(move))
        return score; // status moves aren't accounted here

    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, AI_ATTACKING)
        && (!IsSelfSacrificeEffect(move) || ShouldConsiderSelfSacrificeDamageEffect(battlerAtk, battlerDef, move, aiIsFaster)))
    {
        if (aiIsFaster)
            ADJUST_SCORE(FAST_KILL);
        else
            ADJUST_SCORE(SLOW_KILL);
    }
    else if (CanTargetFaintAi(battlerDef, battlerAtk)
            && AI_GetWhichBattlerFasterOrTies(battlerAtk, battlerDef, TRUE) != AI_IS_FASTER
            && GetBattleMovePriority(battlerAtk, gAiLogicData->abilities[battlerAtk], move) > 0)
    {
        if (RandomPercentage(RNG_AI_PRIORITIZE_LAST_CHANCE, PRIORITIZE_LAST_CHANCE_CHANCE) && !IsDoubleBattle()) // Last Chance behaviour is too easily abused in doubles
            ADJUST_SCORE(SLOW_KILL + 2); // Don't outscore Fast Kill (which gets a bonus point in AI_CompareDamagingMoves), but do outscore Slow Kill getting the same
        else
            ADJUST_SCORE(LAST_CHANCE);
    }

    return score;
}

static bool32 ShouldTriggerPartnerAbility(enum BattlerId battlerAtk, enum Move move, enum Ability ability)
{
    enum BattlerId partner = GetPartnerBattler(battlerAtk);
    enum BattlerId leftFoe = GetBattlerLeftFoe(battlerAtk);
    enum BattlerId rightFoe = GetBattlerRightFoe(battlerAtk);

    switch (ability)
    {
    case ABILITY_DRY_SKIN:
    case ABILITY_EARTH_EATER:
    case ABILITY_VOLT_ABSORB:
    case ABILITY_WATER_ABSORB:
        if (IsBattlerAlive(leftFoe) && ShouldRecover(partner, leftFoe, move, 25))
            return TRUE;
        if (IsBattlerAlive(rightFoe) && ShouldRecover(partner, rightFoe, move, 25))
            return TRUE;
        return FALSE;
    default:
        return ShouldTriggerAbility(battlerAtk, partner, ability);
    }
}

// double battle logic
static s32 AI_DoubleBattle(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    // move data
    enum BattleMoveEffects effect = GetMoveEffect(move);
    enum MoveTarget moveTarget = AI_GetBattlerMoveTargetType(battlerAtk, move);
    // ally data
    enum BattlerId battlerAtkPartner = GetPartnerBattler(battlerAtk);
    struct AiLogicData *aiData = gAiLogicData;
    enum Ability atkPartnerAbility = aiData->abilities[GetPartnerBattler(battlerAtk)];
    enum HoldEffect atkPartnerHoldEffect = aiData->holdEffects[GetPartnerBattler(battlerAtk)];
    enum BattleMoveEffects partnerEffect = GetMoveEffect(aiData->partnerMove);
    bool32 partnerProtecting = IsAllyProtectingFromMove(battlerAtk, move, aiData->partnerMove) && !MoveIgnoresProtect(move);
    bool32 partnerHasBadAbility = (gAbilitiesInfo[atkPartnerAbility].aiRating < 0);
    enum Move incomingMove = GetIncomingMove(battlerAtk, battlerDef, gAiLogicData);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);

    SetTypeBeforeUsingMove(move, battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk]);
    enum Type moveType = GetBattleMoveType(move);

    bool32 hasTwoOpponents = HasTwoOpponents(battlerAtk);
    bool32 hasPartner = HasPartner(battlerAtk);
    u32 friendlyFireThreshold = GetFriendlyFireKOThreshold(battlerAtk);
    u32 noOfHitsToKOPartner = GetNoOfHitsToKOBattler(battlerAtk, battlerAtkPartner, gAiThinkingStruct->movesetIndex, AI_ATTACKING_PARTNER, CONSIDER_ENDURE);
    bool32 wouldPartnerFaint = hasPartner && CanIndexMoveFaintTarget(battlerAtk, battlerAtkPartner, gAiThinkingStruct->movesetIndex, AI_ATTACKING_PARTNER) && !partnerProtecting;
    bool32 isFriendlyFireOK = !wouldPartnerFaint && (noOfHitsToKOPartner == 0 || noOfHitsToKOPartner > friendlyFireThreshold);

    // check what effect partner is using
    if (aiData->partnerMove != MOVE_NONE && hasPartner)
    {
        // This catches weather, terrain, screens, etc
        if (AreMovesEquivalent(battlerAtk, battlerAtkPartner, move, aiData->partnerMove))
            ADJUST_SCORE(-10);

        switch (partnerEffect)
        {
        case EFFECT_HELPING_HAND:
            if (IsBattleMoveStatus(move))
                ADJUST_SCORE(-7);
            break;
        case EFFECT_PERISH_SONG:
            if (!(gBattleMons[battlerDef].volatiles.escapePrevention || gBattleMons[battlerDef].volatiles.wrapped))
            {
                if (IsTrappingMove(aiData->partnerMove) || incomingMove == MOVE_INGRAIN)
                    ADJUST_SCORE(WEAK_EFFECT);
            }
            break;
        case EFFECT_AFTER_YOU:
            if (effect == EFFECT_TRICK_ROOM && !(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case EFFECT_TRICK_ROOM:
            if (effect == EFFECT_AFTER_YOU && !(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        default:
            break;
        }
    } // check partner move effect

    // Adjust for always crit moves
    if (MoveAlwaysCrits(aiData->partnerMove) && aiData->abilities[battlerAtk] == ABILITY_ANGER_POINT)
    {
        if (AI_IsSlower(battlerAtk, battlerAtkPartner, move, predictedMove, CONSIDER_PRIORITY))   // Partner moving first
        {
            // discourage raising our attack since it's about to be maxed out
            if (IsStatChangeStatusMove(move, IsAtkStatUpMove))
                ADJUST_SCORE(-3);
            // encourage moves hitting multiple opponents
            if (!IsBattleMoveStatus(move) && IsSpreadMove(moveTarget))
                ADJUST_SCORE(GOOD_EFFECT);
        }
    }

    // consider our move effect relative to partner state
    switch (effect)
    {
    case EFFECT_FUSION_COMBO:
        if (ShouldUseFusionMove(battlerAtk))
        {
            ADJUST_SCORE(BEST_EFFECT);
        }
    case EFFECT_ROUND:
        if (ShouldUseRound(battlerAtk, EFFECT_ROUND))
        {
            ADJUST_SCORE(BEST_EFFECT);
        }
        break;
    case EFFECT_PLEDGE:
        if (ShouldUsePledgeMove(battlerAtk, battlerDef, move))
        {
            ADJUST_SCORE(BEST_EFFECT);
        }
        break;
    case EFFECT_HELPING_HAND:
        if (!hasPartner
         || !HasDamagingMove(battlerAtkPartner)
         || aiData->abilities[battlerAtkPartner] == ABILITY_GOOD_AS_GOLD
         || (aiData->partnerMove != MOVE_NONE && IsBattleMoveStatus(aiData->partnerMove)))
        {
            ADJUST_SCORE(WORST_EFFECT);
        }
        else
        {
            u32 ownHitsToKOFoe1 = GetBestNoOfHitsToKO(battlerAtk, GetBattlerLeftFoe(battlerAtk), AI_ATTACKING);
            u32 partnerHitsToKOFoe1 = GetBestNoOfHitsToKO(battlerAtkPartner, GetBattlerLeftFoe(battlerAtk), AI_ATTACKING);
            u32 ownHitsToKOFoe2 = GetBestNoOfHitsToKO(battlerAtk, GetBattlerRightFoe(battlerAtk), AI_ATTACKING);
            u32 partnerHitsToKOFoe2 = GetBestNoOfHitsToKO(battlerAtkPartner, GetBattlerRightFoe(battlerAtk), AI_ATTACKING);

            if (hasTwoOpponents)
            {
                // Might be about to die
                if (CanTargetFaintAi(GetBattlerLeftFoe(battlerAtk), battlerAtk) && CanTargetFaintAi(GetBattlerRightFoe(battlerAtk), battlerAtk)
                 && AI_IsSlower(battlerAtk, GetBattlerLeftFoe(battlerAtk), move, incomingMove, DONT_CONSIDER_PRIORITY)
                 && AI_IsSlower(battlerAtk, GetBattlerRightFoe(battlerAtk), move, incomingMove, DONT_CONSIDER_PRIORITY))
                    ADJUST_SCORE(GOOD_EFFECT);

                if (ownHitsToKOFoe1 > partnerHitsToKOFoe1 && partnerHitsToKOFoe1 > 1
                 && ownHitsToKOFoe2 > partnerHitsToKOFoe2 && partnerHitsToKOFoe2 > 1)
                    ADJUST_SCORE(GOOD_EFFECT);
            }
            else if (IsBattlerAlive(GetBattlerLeftFoe(battlerAtk)))
            {
                // Might be about to die
                if (CanTargetFaintAi(GetBattlerLeftFoe(battlerAtk), battlerAtk)
                 && AI_IsSlower(battlerAtk, GetBattlerLeftFoe(battlerAtk), move, incomingMove, DONT_CONSIDER_PRIORITY))
                    ADJUST_SCORE(GOOD_EFFECT);

                if (ownHitsToKOFoe1 > partnerHitsToKOFoe1 && partnerHitsToKOFoe1 > 1)
                    ADJUST_SCORE(GOOD_EFFECT);
            }
            else if (IsBattlerAlive(GetBattlerRightFoe(battlerAtk)))
            {
                // Might be about to die
                if (CanTargetFaintAi(GetBattlerRightFoe(battlerAtk), battlerAtk)
                 && AI_IsSlower(battlerAtk, GetBattlerRightFoe(battlerAtk), move, incomingMove, DONT_CONSIDER_PRIORITY))
                    ADJUST_SCORE(GOOD_EFFECT);

                if (ownHitsToKOFoe2 > partnerHitsToKOFoe2 && partnerHitsToKOFoe2 > 1)
                    ADJUST_SCORE(GOOD_EFFECT);

            }
        }
        break;
    case EFFECT_PERISH_SONG:
        if (aiData->partnerMove != 0 && HasTrappingMoveEffect(battlerAtkPartner))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_MAGNET_RISE:
        if (AI_IsBattlerGrounded(battlerAtk)
          && (HasMoveWithEffect(battlerAtkPartner, EFFECT_EARTHQUAKE) || HasMoveWithEffect(battlerAtkPartner, EFFECT_MAGNITUDE))
          && (AI_GetMoveEffectiveness(MOVE_EARTHQUAKE, battlerAtk, battlerAtkPartner) != UQ_4_12(0.0))) // Doesn't resist ground move
        {
            RETURN_SCORE_PLUS(DECENT_EFFECT);   // partner has earthquake or magnitude -> good idea to use magnet rise
        }
        break;
    case EFFECT_DRAGON_CHEER:
        if (gBattleMons[battlerAtkPartner].volatiles.dragonCheer
         || gBattleMons[battlerAtkPartner].volatiles.focusEnergy
         || !HasDamagingMove(battlerAtkPartner))
        {
            ADJUST_SCORE(-5);
        }
        else if (!partnerProtecting
         && (atkPartnerHoldEffect == HOLD_EFFECT_SCOPE_LENS
          || IS_BATTLER_OF_TYPE(battlerAtkPartner, TYPE_DRAGON)
          || GetMoveCriticalHitStage(aiData->partnerMove) > 0
          || HasMoveWithCriticalHitChance(battlerAtkPartner)))
        {
            ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    default:
        break;
    } // our effect relative to partner

    // consider global move effects
    switch (effect)
    {
    // Both Pokemon use Trick Room on the final turn of Trick Room to anticipate both opponents Protecting to stall out.
    // This unsets Trick Room and resets it with a full timer.
    case EFFECT_TRICK_ROOM:
        if (hasPartner && gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer == 1
         && ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM)
         && HasMoveWithEffect(battlerAtkPartner, EFFECT_TRICK_ROOM)
         && RandomPercentage(RNG_AI_REFRESH_TRICK_ROOM_ON_LAST_TURN, DOUBLE_TRICK_ROOM_ON_LAST_TURN_CHANCE))
            ADJUST_SCORE(PERFECT_EFFECT);
        break;
    case EFFECT_TAILWIND:
        // Anticipate both opponents protecting to stall out Trick Room, and apply Tailwind.
        if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer == 1
         && RandomPercentage(RNG_AI_APPLY_TAILWIND_ON_LAST_TURN_OF_TRICK_ROOM, TAILWIND_IN_TRICK_ROOM_CHANCE))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    default:
        break;
    } // global move effect check

    // Specific logic for spread moves.
    if (moveTarget == TARGET_FOES_AND_ALLY)
    {
        // Don't kill your partner for no reason.
        if (wouldPartnerFaint)
        {
            // If it kills both opponents, that's a good reason.
            if (CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtk), gAiThinkingStruct->movesetIndex, AI_ATTACKING)
                && CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtkPartner), gAiThinkingStruct->movesetIndex, AI_ATTACKING))
            {
                if (IsExplosionMove(move))
                {
                    if (gAiThinkingStruct->aiFlags[battlerAtk] & (AI_FLAG_RISKY | AI_FLAG_WILL_SUICIDE))
                    {
                        RETURN_SCORE_PLUS(10);
                    }
                }
                else
                {
                    RETURN_SCORE_PLUS(10);
                }
            }
            // Both opponents can kill the partner
            else if (CanTargetFaintAi(GetOppositeBattler(battlerAtk), battlerAtkPartner)
                && (CanTargetFaintAi(GetOppositeBattler(battlerAtkPartner), battlerAtkPartner)))
            {
                // The spread move should kill an opponent.
                if (CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtk), gAiThinkingStruct->movesetIndex, AI_ATTACKING)
                    || CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtkPartner), gAiThinkingStruct->movesetIndex, AI_ATTACKING))
                {
                    ADJUST_SCORE(WEAK_EFFECT);
                }

                // Alternatively, it benefits from the ally's death, and it will probably die anyway.
                if (IsMoxieTypeAbility(aiData->abilities[battlerAtk]))
                {
                    ADJUST_SCORE(GOOD_EFFECT);
                }
                if ((aiData->abilities[battlerAtk] == ABILITY_RECEIVER) && !partnerHasBadAbility)
                {
                    ADJUST_SCORE(GOOD_EFFECT);
                }
                if (HasMove(battlerAtk, MOVE_LAST_RESPECTS))
                {
                    ADJUST_SCORE(GOOD_EFFECT);
                }
                if (ShouldTriggerSpicySprayForBurn(battlerAtk, move, noOfHitsToKOPartner, aiData))
                {
                    ADJUST_SCORE(WEAK_EFFECT);
                }
            }
            // It can kill one opponent when killing its ally, and its ally is not in extreme danger.
            // This is easy for the player to cheese.
            else if (CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtk), gAiThinkingStruct->movesetIndex, AI_ATTACKING)
                || CanIndexMoveFaintTarget(battlerAtk, GetOppositeBattler(battlerAtkPartner), gAiThinkingStruct->movesetIndex, AI_ATTACKING))
            {
                if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE)
                {
                    RETURN_SCORE_PLUS(10);
                }
                else
                {
                    ADJUST_SCORE(AWFUL_EFFECT);
                }
            }
            // No reason to kill partner has been found.
            else
            {
                RETURN_SCORE_MINUS(10);
            }
        }

        // Partner will not faint.
        else {

            // Triggering your ally's hold item should only be done deliberately with a spread move.
            switch (atkPartnerHoldEffect)
            {
            case HOLD_EFFECT_WEAKNESS_POLICY:
                if (!partnerProtecting
                 && aiData->effectiveness[battlerAtk][battlerAtkPartner][gAiThinkingStruct->movesetIndex] >= UQ_4_12(2.0)
                 && isFriendlyFireOK)
                {
                    ADJUST_SCORE(GOOD_EFFECT);
                }
                break;
            default:
                break;
            }

            if (!partnerProtecting
             && isFriendlyFireOK
             && ShouldTriggerSpicySprayForBurn(battlerAtk, move, noOfHitsToKOPartner, aiData))
                ADJUST_SCORE(DECENT_EFFECT);
        }
    }

    // check specific target
    if (IsTargetingPartner(battlerAtk, battlerDef))
    {
        bool32 isMoveAffectedByPartnerAbility = TRUE;

        if (wouldPartnerFaint)
        {
            RETURN_SCORE_MINUS(30);
        }

        // partner ability checks
        if (!partnerProtecting && moveTarget != TARGET_BOTH && !DoesBattlerIgnoreAbilityChecks(battlerAtk, aiData->abilities[battlerAtk], move))
        {
            switch (atkPartnerAbility)
            {
            case ABILITY_ANGER_POINT:
                if (MoveAlwaysCrits(move)
                    && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_ATK)
                    && AI_IsFaster(battlerAtk, battlerAtkPartner, move, predictedMove, CONSIDER_PRIORITY)
                    && isFriendlyFireOK)
                {
                    if (MoveAlwaysCrits(move))
                    {
                        if (moveTarget == TARGET_FOES_AND_ALLY)
                        {
                            ADJUST_SCORE(DECENT_EFFECT);
                        }
                        RETURN_SCORE_PLUS(GOOD_EFFECT);
                    }
                // todo: figuring out a non-guaranteed crit roll that's useful
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_LIGHTNING_ROD:
            case ABILITY_MOTOR_DRIVE:
            case ABILITY_VOLT_ABSORB:
                if (moveType == TYPE_ELECTRIC)
                {
                    if (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) < GEN_5 && atkPartnerAbility == ABILITY_LIGHTNING_ROD)
                    {
                        RETURN_SCORE_MINUS(10);
                    }

                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        if (ShouldTriggerPartnerAbility(battlerAtk, move, atkPartnerAbility))
                            ADJUST_SCORE(DECENT_EFFECT);
                    }
                    else if (ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                    {
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                    }
                    else
                    {
                        RETURN_SCORE_MINUS(10);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_EARTH_EATER:
                if (moveType == TYPE_GROUND)
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        if (ShouldTriggerPartnerAbility(battlerAtk, move, atkPartnerAbility))
                            ADJUST_SCORE(DECENT_EFFECT);
                    }
                    else if (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_HP_AWARE))
                    {
                        RETURN_SCORE_MINUS(10);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;  // handled in AI_HPAware
            case ABILITY_LEVITATE:
            case ABILITY_EELEVATE:
                if (moveType != TYPE_GROUND)
                    isMoveAffectedByPartnerAbility = FALSE;
                break;
            case ABILITY_DRY_SKIN:
            case ABILITY_WATER_ABSORB:
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER)
                {
                    if (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) < GEN_5 && atkPartnerAbility == ABILITY_STORM_DRAIN)
                    {
                        RETURN_SCORE_MINUS(10);
                    }

                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        if (ShouldTriggerPartnerAbility(battlerAtk, move, atkPartnerAbility))
                            ADJUST_SCORE(DECENT_EFFECT);
                    }
                    else if (ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                    {
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                    }
                    else
                    {
                        RETURN_SCORE_MINUS(10);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_WATER_COMPACTION:
                if (moveType == TYPE_WATER && isFriendlyFireOK
                    && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }

                    if (GetMoveStrikeCount(move) > 1 && moveTarget != TARGET_SMART)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_STEAM_ENGINE:
                if (isFriendlyFireOK && (moveType == TYPE_WATER || moveType == TYPE_FIRE)
                    && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_THERMAL_EXCHANGE:
                if (moveType == TYPE_FIRE && isFriendlyFireOK
                    && !IsBattleMoveStatus(move)
                    && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }

                    if (GetMoveStrikeCount(move) > 1 && moveTarget != TARGET_SMART)
                    {
                        ADJUST_SCORE(WEAK_EFFECT);
                    }

                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_FLASH_FIRE:
            case ABILITY_WELL_BAKED_BODY:
                if (moveType == TYPE_FIRE)
                {
                    if (ShouldTriggerPartnerAbility(battlerAtk, move, atkPartnerAbility))
                    {
                        if (moveTarget == TARGET_FOES_AND_ALLY)
                            ADJUST_SCORE(DECENT_EFFECT);
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_SAP_SIPPER:
                if (moveType == TYPE_GRASS)
                {
                    if (ShouldTriggerPartnerAbility(battlerAtk, move, atkPartnerAbility))
                    {
                        if (moveTarget == TARGET_FOES_AND_ALLY)
                            ADJUST_SCORE(DECENT_EFFECT);
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                    }
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_JUSTIFIED:
                if (moveType == TYPE_DARK && isFriendlyFireOK
                    && !IsBattleMoveStatus(move)
                    && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(GOOD_EFFECT);
                    }

                    if (GetMoveStrikeCount(move) > 1 && moveTarget != TARGET_SMART)
                    {
                        ADJUST_SCORE(WEAK_EFFECT);
                    }

                    ADJUST_SCORE(WEAK_EFFECT); // Beat Up is handled later
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_RATTLED:
                if (!IsBattleMoveStatus(move) && isFriendlyFireOK
                    && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG)
                    && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            case ABILITY_CONTRARY:
                if (IsStatLoweringMove(move) && isFriendlyFireOK && ShouldTriggerAbility(battlerAtk, battlerAtkPartner, atkPartnerAbility))
                {
                    if (moveTarget == TARGET_FOES_AND_ALLY)
                    {
                        ADJUST_SCORE(GOOD_EFFECT);
                    }
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                else
                {
                    isMoveAffectedByPartnerAbility = FALSE;
                }
                break;
            default:
                break;
            }
        } // ability checks

        // attacker move effects specifically targeting partner
        if (!partnerProtecting)
        {
            if (wouldPartnerFaint)
            {
                RETURN_SCORE_MINUS(30);
            }

            switch (effect)
            {
            case EFFECT_DOODLE:
            case EFFECT_ENTRAINMENT:
            case EFFECT_GASTRO_ACID:
            case EFFECT_ROLE_PLAY:
            case EFFECT_SKILL_SWAP:
            case EFFECT_OVERWRITE_ABILITY:
                AbilityChangeScore(battlerAtk, battlerAtkPartner, move, &score, aiData);
                return score;
            case EFFECT_STAT_CHANGE:
            case EFFECT_STAT_CHANGE_MAGNETIC:
                switch (moveTarget)
                {
                case TARGET_USER_AND_ALLY:
                case TARGET_USER_OR_ALLY:
                case TARGET_ALLY:
                case TARGET_SELECTED:
                    if (AI_CanAnyStatChange(battlerAtk, battlerAtkPartner, move))
                    {
                        ADJUST_SCORE(GetAllyStatChangeScore(battlerAtk, battlerAtkPartner, move));
                    }
                    break;
                default:
                    break;
                }
                break;
            case EFFECT_ACUPRESSURE: // probably not good AI but just kept the same
            {
                ADJUST_SCORE(IncreaseStatUpScore(battlerAtkPartner, GetOppositeBattler(battlerAtkPartner), STAT_ATK, 2));
                ADJUST_SCORE(IncreaseStatUpScore(battlerAtkPartner, GetOppositeBattler(battlerAtkPartner), STAT_SPATK, 2));
                break;
            }
            case EFFECT_PURIFY:
                if (gBattleMons[battlerAtkPartner].status1 & STATUS1_ANY)
                {
                    if (gBattleMons[battlerAtkPartner].status1 & STATUS1_CAN_MOVE)
                    {
                        if (ShouldCureStatus(battlerAtk, battlerAtkPartner, aiData))
                            ADJUST_SCORE(DECENT_EFFECT);
                    }
                    else
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }

                    if ((!IsBattlerAlive(GetBattlerLeftFoe(battlerAtk)) || ShouldRecover(battlerAtk, GetBattlerLeftFoe(battlerAtk), move, 50))
                     && (!IsBattlerAlive(GetBattlerRightFoe(battlerAtk)) || ShouldRecover(battlerAtk, GetBattlerRightFoe(battlerAtk), move, 50)))
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_SWAGGER:
                if (gBattleMons[battlerAtkPartner].statStages[STAT_ATK] < MAX_STAT_STAGE
                 && HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_PHYSICAL)
                 && (!AI_CanBeConfused(battlerAtk, battlerAtkPartner, move, atkPartnerAbility)
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_CONFUSION
                  || atkPartnerHoldEffect == HOLD_EFFECT_CURE_STATUS))
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_BEAT_UP:
                if (ShouldBeatUpForJustified(battlerAtk, battlerAtkPartner, move, moveType, wouldPartnerFaint, aiData)
                 || ShouldBeatUpForRageFist(battlerAtk, battlerAtkPartner, move, wouldPartnerFaint, aiData))
                {
                    if (isFriendlyFireOK)
                    {
                        ADJUST_SCORE(DECENT_EFFECT);
                    }
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_SOAK:
                if (atkPartnerAbility == ABILITY_WONDER_GUARD
                 && !IS_BATTLER_OF_TYPE(battlerAtkPartner, TYPE_WATER)
                 && GetActiveGimmick(battlerAtkPartner) != GIMMICK_TERA)
                {
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                }
                break;
            case EFFECT_INSTRUCT:
                {
                    enum Move instructedMove = aiData->lastUsedMove[battlerAtkPartner];
                    if (AI_IsFaster(battlerAtk, battlerAtkPartner, move, predictedMove, CONSIDER_PRIORITY))
                        instructedMove = aiData->partnerMove;

                    if (instructedMove != MOVE_NONE
                     && !IsBattleMoveStatus(instructedMove)
                     && IsSpreadMove(AI_GetBattlerMoveTargetType(battlerAtkPartner, instructedMove)))
                    {
                        RETURN_SCORE_PLUS(WEAK_EFFECT);
                    }
                }
                break;
            case EFFECT_AFTER_YOU:
                if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && HasMoveWithEffect(battlerAtkPartner, EFFECT_TRICK_ROOM))
                    ADJUST_SCORE(DECENT_EFFECT);

                if (AI_IsSlower(battlerAtkPartner, GetBattlerLeftFoe(battlerAtk), aiData->partnerMove, predictedMove, CONSIDER_PRIORITY)  // Opponent mon 1 goes before partner
                 && AI_IsSlower(battlerAtkPartner, GetBattlerRightFoe(battlerAtk), aiData->partnerMove, predictedMove, CONSIDER_PRIORITY)) // Opponent mon 2 goes before partner
                {
                    if (partnerEffect == EFFECT_REFLECT_DAMAGE)
                        break; // These moves need to go last
                    ADJUST_SCORE(WEAK_EFFECT);
                }
                break;
            case EFFECT_HEAL_PULSE:
            case EFFECT_HIT_ENEMY_HEAL_ALLY:
                if (AI_IsFaster(battlerAtk, GetBattlerLeftFoe(battlerAtk), move, predictedMove, CONSIDER_PRIORITY)
                 && AI_IsFaster(battlerAtk, GetBattlerRightFoe(battlerAtk), move, predictedMove, CONSIDER_PRIORITY)
                 && gBattleMons[battlerAtkPartner].hp < gBattleMons[battlerAtkPartner].maxHP / 2)
                    RETURN_SCORE_PLUS(WEAK_EFFECT);
                break;
            case EFFECT_SPEED_SWAP:
                break;
            case EFFECT_GUARD_SPLIT:
            {
                u32 atkDefense = gBattleMons[battlerAtk].defense;
                u32 defDefense = gBattleMons[battlerDef].defense;
                u32 atkSpDefense = gBattleMons[battlerAtk].spDefense;
                u32 defSpDefense = gBattleMons[battlerDef].spDefense;

                // It's actually * 100 and / 2
                u32 newDefense = (atkDefense + defDefense) * 50;
                u32 newSpDefense = (atkSpDefense + defSpDefense) * 50;

                // We want to massively raise our defense.
                if (newDefense > atkDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (newSpDefense > atkSpDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (newDefense > defDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (newSpDefense > defSpDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);

                ADJUST_SCORE(WORST_EFFECT);
                break;
            }
            case EFFECT_POWER_SPLIT:
            {
                u32 atkAttack = gBattleMons[battlerAtk].attack;
                u32 defAttack = gBattleMons[battlerDef].attack;
                u32 atkSpAttack = gBattleMons[battlerAtk].spAttack;
                u32 defSpAttack = gBattleMons[battlerDef].spAttack;

                // * 100 and / 2
                u32 newAttack = (atkAttack + defAttack) * 50;
                u32 newSpAtk = (atkSpAttack + defSpAttack) * 50;

                if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL) && newAttack > atkAttack * POWER_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL) && newAttack > defAttack * POWER_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL) && newSpAtk > atkSpAttack * POWER_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
                if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL) && newSpAtk > defSpAttack * POWER_SPLIT_ALLY_PERCENTAGE)
                    ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);

                ADJUST_SCORE(WORST_EFFECT);
                break;
            default:
                break;
            }
            } // attacker move effects
        } // check partner protecting

        if ((isMoveAffectedByPartnerAbility && (score <= AI_SCORE_DEFAULT)) || !isMoveAffectedByPartnerAbility)
        {
            RETURN_SCORE_MINUS(10);
        }


    }
    else // checking opponent
    {
        // these checks mostly handled in AI_CheckBadMove and AI_CheckViability
/*
        IF WE FULLY RETIRE THIS CODEBLOCK LATER, ALSO REMOVE THE IsAbilityOfRating FUNCTION

        switch (effect)
        {
        case EFFECT_SKILL_SWAP:
            if (aiData->abilities[battlerAtk] == ABILITY_TRUANT)
                ADJUST_SCORE(GOOD_EFFECT);
            else if (IsAbilityOfRating(aiData->abilities[battlerAtk], 0) || IsAbilityOfRating(aiData->abilities[battlerDef], 10))
                ADJUST_SCORE(DECENT_EFFECT); // we want to transfer our bad ability or take their awesome ability
            break;
        default:
            break;
        }
*/
        // lightning rod, flash fire against enemy handled in AI_CheckBadMove
    }

    return score;
}

static bool32 IsPinchBerryItemEffect(enum HoldEffect holdEffect)
{
    switch (holdEffect)
    {
    case HOLD_EFFECT_ATTACK_UP:
    case HOLD_EFFECT_DEFENSE_UP:
    case HOLD_EFFECT_SPEED_UP:
    case HOLD_EFFECT_SP_ATTACK_UP:
    case HOLD_EFFECT_SP_DEFENSE_UP:
    case HOLD_EFFECT_CRITICAL_UP:
    case HOLD_EFFECT_RANDOM_STAT_UP:
    case HOLD_EFFECT_CUSTAP_BERRY:
    case HOLD_EFFECT_MICLE_BERRY:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 DoesAbilityBenefitFromSunOrRain(enum BattlerId battler, enum Ability ability, u32 weather)
{
    switch (ability)
    {
    case ABILITY_DRY_SKIN:
    case ABILITY_HYDRATION:
    case ABILITY_RAIN_DISH:
    case ABILITY_SWIFT_SWIM:
        return (weather & B_WEATHER_RAIN);
    case ABILITY_HARVEST:
        if (GetItemPocket(gAiLogicData->items[battler]) != POCKET_BERRIES
            && GetItemPocket(GetBattlerPartyState(battler)->usedHeldItem) != POCKET_BERRIES)
        {
            return FALSE;
        }
    case ABILITY_CHLOROPHYLL:
    case ABILITY_FLOWER_GIFT:
    case ABILITY_LEAF_GUARD:
    case ABILITY_SOLAR_POWER:
    case ABILITY_ORICHALCUM_PULSE:
        return (weather & B_WEATHER_SUN);
    default:
        break;
    }
    return FALSE;
}

static u32 GetWindAbilityScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData)
{
    u32 score = 0;

    if (aiData->abilities[battlerAtk] == ABILITY_WIND_RIDER)
    {
        score = IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, 1);
    }
    else if (aiData->abilities[battlerAtk] == ABILITY_WIND_POWER)
    {
        if (gBattleMons[battlerAtk].volatiles.chargeTimer == 0
         && HasDamagingMoveOfType(battlerAtk, TYPE_ELECTRIC))
        {
            score = DECENT_EFFECT;
        }
    }

    return score;
}

static enum MoveComparisonResult CompareMoveAccuracies(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveSlot1, u32 moveSlot2)
{
    u32 acc1 = gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveSlot1];
    u32 acc2 = gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveSlot2];

    if (acc1 > acc2)
        return MOVE_WON_COMPARISON;
    else if (acc2 > acc1)
        return MOVE_LOST_COMPARISON;
    return MOVE_NEUTRAL_COMPARISON;
}

static enum MoveComparisonResult CompareMoveSpeeds(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 move1Faster, bool32 move2Faster)
{
    if (move1Faster && !move2Faster)
        return MOVE_WON_COMPARISON;
    if (move2Faster && !move1Faster)
        return MOVE_LOST_COMPARISON;
    return MOVE_NEUTRAL_COMPARISON;
}

static enum MoveComparisonResult CompareGuaranteeFaintTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, u16 moveSlot1, u16 moveSlot2, u16 *moves)
{
    s32 dmg1, dmg2;
    bool32 guarantee1, guarantee2;

    if (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT))
        return 0;

    // Explictly care about guaranteed KOs universally
    dmg1 = gAiLogicData->simulatedDmg[battlerAtk][battlerDef][moveSlot1].minimum;
    guarantee1 = (gBattleMons[battlerDef].hp <= dmg1 && !CanEndureHit(battlerAtk, battlerDef, moves[moveSlot1]));
    dmg2 = gAiLogicData->simulatedDmg[battlerAtk][battlerDef][moveSlot2].minimum;
    guarantee2 = (gBattleMons[battlerDef].hp <= dmg2 && !CanEndureHit(battlerAtk, battlerDef, moves[moveSlot2]));

    if (guarantee1 && !guarantee2)
        return MOVE_WON_COMPARISON;
    if (guarantee2 && !guarantee1)
        return MOVE_LOST_COMPARISON;
    return MOVE_NEUTRAL_COMPARISON;
}

static enum MoveComparisonResult CompareResistBerryEffects(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveSlot1, u32 moveSlot2)
{
    // Check for resist berries in OHKOs
    if (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_RESIST_BERRY)
    {
        if (gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveSlot2] && !gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveSlot1])
            return MOVE_WON_COMPARISON;

        if (gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveSlot1] && !gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveSlot2])
            return MOVE_LOST_COMPARISON;
    }

    return MOVE_NEUTRAL_COMPARISON;
}

bool32 DoesBattlerKOItselfWithRecoil(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    u32 recoilDmg = 0;
    u32 monHP = GetNonDynamaxMaxHP(battlerAtk);
    enum BattleMoveEffects effect = GetMoveEffect(move);

    // Is recoil applicable
    if (!IsRecoilDamageEffect(effect) || !AI_IsDamagedByRecoil(battlerAtk))
        return FALSE;

    // Get recoil damage
    if (effect == EFFECT_CHLOROBLAST || effect == EFFECT_MAX_HP_50_RECOIL)
        recoilDmg = (monHP + 1) / 2; // Half of max HP rounded up
    if (GetMoveEffect(move) == EFFECT_RECOIL)
        recoilDmg = monHP * GetMoveRecoil(move) / 100; // Recoil damage

    // Does recoil KO attacker
    s32 opposingMons = 0;
    if ((GetConfig(B_MULTI_BATTLE_WHITEOUT) == GEN_3) && BattlerIsPlayer(battlerDef))
        opposingMons = CountUsablePartyMons(battlerDef);
    else
        opposingMons = CountUsableSideMons(battlerDef);

    if (recoilDmg >= gBattleMons[battlerAtk].hp && opposingMons != 0)
        return TRUE;

    return FALSE;
}

static enum MoveComparisonResult CompareMoveSelfSacrifice(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move1, enum Move move2)
{
    bool32 selfSacrifice1 = IsSelfSacrificeEffect(move1) || DoesBattlerKOItselfWithRecoil(battlerAtk, battlerDef, move1);
    bool32 selfSacrifice2 = IsSelfSacrificeEffect(move2) || DoesBattlerKOItselfWithRecoil(battlerAtk, battlerDef, move2);

    if (selfSacrifice1 && !selfSacrifice2)
        return MOVE_LOST_COMPARISON;
    if (selfSacrifice2 && !selfSacrifice1)
        return MOVE_WON_COMPARISON;
    return MOVE_NEUTRAL_COMPARISON;
}

static enum MoveComparisonResult CompareMoveTwoTurnEffect(enum BattlerId battlerAtk, enum Move move1, enum Move move2)
{
    bool32 twoTurn1 = IsTwoTurnNotSemiInvulnerableMove(battlerAtk, move1);
    bool32 twoTurn2 = IsTwoTurnNotSemiInvulnerableMove(battlerAtk, move2);

    if (twoTurn1 && !twoTurn2)
        return MOVE_LOST_COMPARISON;
    if (twoTurn2 && !twoTurn1)
        return MOVE_WON_COMPARISON;
    return MOVE_NEUTRAL_COMPARISON;
}

static inline bool32 ShouldUseSpreadDamageMove(enum BattlerId battlerAtk, enum Move move, u32 moveIndex, u32 hitsToFaintOpposingBattler)
{
    enum BattlerId partnerBattler = GetPartnerBattler(battlerAtk);
    u32 noOfHitsToFaintPartner = GetNoOfHitsToKOBattler(battlerAtk, partnerBattler, moveIndex, AI_ATTACKING_PARTNER, CONSIDER_ENDURE);
    u32 friendlyFireThreshold = GetFriendlyFireKOThreshold(battlerAtk);
    return (HasPartnerIgnoreFlags(battlerAtk)
         && noOfHitsToFaintPartner != 0 // Immunity check
         && AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_FOES_AND_ALLY
         && !(noOfHitsToFaintPartner < friendlyFireThreshold && hitsToFaintOpposingBattler == 1)
         && noOfHitsToFaintPartner < (friendlyFireThreshold * 2));
}

static bool32 ShouldCompareMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum Move move)
{
    if (IsTargetingPartner(battlerAtk, battlerDef))
        return FALSE;
    if (GetMovePower(move) == 0)
        return FALSE;
    if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, moveIndex, AI_ATTACKING, DONT_CONSIDER_ENDURE) == 0)
        return FALSE;
    if (gAiThinkingStruct->aiFlags[battlerAtk] & (AI_FLAG_RISKY | AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE) && IsBestDmgMove(battlerAtk, battlerDef, AI_ATTACKING, move))
        return FALSE;
    return TRUE;
}

static void AI_CompareDamagingMoves(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    u32 tempMoveScores[MAX_MON_MOVES];
    u32 moveComparisonScores[MAX_MON_MOVES];
    u32 bestScore = AI_SCORE_DEFAULT;
    bool32 multipleBestMoves = FALSE;
    s32 noOfHits[MAX_MON_MOVES];
    s32 leastHits = 1000;
    enum Move *moves = GetMovesArray(battlerAtk);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 moveIsFaster[MAX_MON_MOVES];

    for (u32 currId = 0; currId < MAX_MON_MOVES; currId++)
    {
        moveComparisonScores[currId] = 0;
        if (!ShouldCompareMove(battlerAtk, battlerDef, currId, moves[currId]))
            continue;
        for (u32 compareId = 0; compareId < MAX_MON_MOVES; compareId++)
        {
            if (moves[compareId] != MOVE_NONE && GetMovePower(moves[compareId]) != 0)
            {
                noOfHits[compareId] = GetNoOfHitsToKOBattler(battlerAtk, battlerDef, compareId, AI_ATTACKING, CONSIDER_ENDURE);
                moveIsFaster[compareId] = AI_IsFaster(battlerAtk, battlerDef, moves[compareId], predictedMove, CONSIDER_PRIORITY);
                tempMoveScores[compareId] = AI_SCORE_DEFAULT;
                if (ShouldUseSpreadDamageMove(battlerAtk,moves[compareId], compareId, noOfHits[compareId]))
                {
                    noOfHits[compareId] = -1;
                }
                else if (noOfHits[compareId] < leastHits && noOfHits[compareId] != 0)
                {
                    leastHits = noOfHits[compareId];
                }
                // Decided against using self sacrifice effect this turn
                if (IsSelfSacrificeEffect(moves[compareId]) && !ShouldConsiderSelfSacrificeDamageEffect(battlerAtk, battlerDef, moves[compareId], moveIsFaster[compareId]))
                {
                    noOfHits[compareId] = gBattleMons[battlerDef].maxHP;
                    tempMoveScores[compareId] = 0;
                }
            }
            else
            {
                noOfHits[compareId] = -1;
                tempMoveScores[compareId] = 0;
            }
        }

        // Priority list:
        // 1. Lower number of hits to KO
            // 2. Move not affected by resist berry (if two moves OHKO)
        // 3. Not charging
            // 4. Priority if outsped and a OHKO (if two moves OHKO)
        // 5. Not self sacrificing
            // 6. Guaranteed KO (if two moves OHKO)
        // 7. More accuracy
        // 8. Better effect

        // Current move requires the least hits to KO. Compare with other moves.
        if (leastHits == noOfHits[currId])
        {
            for (u32 compareId = 0; compareId < MAX_MON_MOVES; compareId++)
            {
                if (compareId == currId)
                    continue;
                if (noOfHits[currId] == noOfHits[compareId])
                {
                    multipleBestMoves = TRUE;
                    // Comparing KOs
                    if (noOfHits[currId] == 1)
                    {
                        // If one move is berry-resisted, use the other one
                        switch (CompareResistBerryEffects(battlerAtk, battlerDef, currId, compareId))
                        {
                        case MOVE_WON_COMPARISON:
                            tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_RESIST_BERRY);
                            break;
                        case MOVE_LOST_COMPARISON:
                            tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_RESIST_BERRY);
                            break;
                        case MOVE_NEUTRAL_COMPARISON:
                            break;
                        }
                        // Use priority to get fast KO if outsped
                        switch (CompareMoveSpeeds(battlerAtk, battlerDef, moveIsFaster[currId], moveIsFaster[compareId]))
                        {
                        case MOVE_WON_COMPARISON:
                            tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_SPEED);
                            break;
                        case MOVE_LOST_COMPARISON:
                            tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_SPEED);
                            break;
                        case MOVE_NEUTRAL_COMPARISON:
                            break;
                        }
                        // Min roll KOs
                        switch (CompareGuaranteeFaintTarget(battlerAtk, battlerDef, currId, compareId, moves))
                        {
                        case MOVE_WON_COMPARISON:
                            tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_GUARANTEE);
                            break;
                        case MOVE_LOST_COMPARISON:
                            tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_GUARANTEE);
                            break;
                        case MOVE_NEUTRAL_COMPARISON:
                            break;
                        }
                    }
                    switch (CompareMoveTwoTurnEffect(battlerAtk, moves[currId], moves[compareId]))
                    {
                    case MOVE_WON_COMPARISON:
                        tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_NOT_CHARGING);
                        break;
                    case MOVE_LOST_COMPARISON:
                        tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_NOT_CHARGING);
                        break;
                    case MOVE_NEUTRAL_COMPARISON:
                        break;
                    }
                    switch (CompareMoveAccuracies(battlerAtk, battlerDef, currId, compareId))
                    {
                    case MOVE_WON_COMPARISON:
                        tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_ACCURACY);
                        break;
                    case MOVE_LOST_COMPARISON:
                        tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_ACCURACY);
                        break;
                    case MOVE_NEUTRAL_COMPARISON:
                        break;
                    }
                    switch (CompareMoveSelfSacrifice(battlerAtk, battlerDef, moves[currId], moves[compareId]))
                    {
                    case MOVE_WON_COMPARISON:
                        tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_AVOID_SELF_SACRIFICE);
                        break;
                    case MOVE_LOST_COMPARISON:
                        tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_AVOID_SELF_SACRIFICE);
                        break;
                    case MOVE_NEUTRAL_COMPARISON:
                        break;
                    }
                    switch (CompareMoveEffects(moves[currId], moves[compareId], battlerAtk, battlerDef, noOfHits[currId]))
                    {
                    case MOVE_WON_COMPARISON:
                        tempMoveScores[currId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_EFFECT);
                        break;
                    case MOVE_LOST_COMPARISON:
                        tempMoveScores[compareId] += MathUtil_Exponent(MAX_MON_MOVES, PRIORITY_EFFECT);
                        break;
                    case MOVE_NEUTRAL_COMPARISON:
                        break;
                    }
                }
            }
            // Turns out the current move deals the most dmg compared to the other 3.
            if (!multipleBestMoves)
                moveComparisonScores[currId] = UINT32_MAX;
            else
                moveComparisonScores[currId] = tempMoveScores[currId];
        }
    }

    // Find highest comparison score
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moveComparisonScores[moveIndex] > bestScore)
            bestScore = moveComparisonScores[moveIndex];
    }
    // Increase score for corresponding move(s), accomodating ties
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moveComparisonScores[moveIndex] == bestScore)
            gAiThinkingStruct->score[moveIndex] += BEST_DAMAGE_MOVE;
    }
}

static s32 AI_CalcHoldEffectMoveScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    enum HoldEffect holdEffect = aiData->holdEffects[battlerAtk];

    s32 score = 0;

    switch (holdEffect)
    {
    case HOLD_EFFECT_BLUNDER_POLICY:
    {
        u32 moveAcc = aiData->moveAccuracy[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex];

        if (moveAcc <= LOW_ACCURACY_THRESHOLD)
        {
            ADJUST_SCORE(GOOD_EFFECT);
        }
        else
        {
            ADJUST_SCORE(AWFUL_EFFECT);
        }
    }
    break;
    default:
        break;
    }

    return score;
}

static s32 AI_CalcMoveEffectScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    // move data
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    u32 movesetIndex = gAiThinkingStruct->movesetIndex;
    uq4_12_t effectiveness = aiData->effectiveness[battlerAtk][battlerDef][movesetIndex];

    s32 score = 0;
    enum Move incomingMove = GetIncomingMove(battlerAtk, battlerDef, aiData);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, aiData);
    enum Type predictedType = GetMoveType(incomingMove);
    u32 predictedMoveSlot = GetMoveSlot(GetMovesArray(battlerDef), incomingMove);
    bool32 isBattle1v1 = IsBattle1v1();
    bool32 hasTwoOpponents = HasTwoOpponents(battlerAtk);
    bool32 hasPartner = HasPartner(battlerAtk);
    enum BattlerId battlerAtkPartner = GetPartnerBattler(battlerAtk);
    enum BattlerId battlerDefPartner = GetPartnerBattler(battlerDef);
    enum MoveTarget moveTarget = AI_GetBattlerMoveTargetType(battlerAtk, move);
    bool32 moveTargetsBothOpponents = hasTwoOpponents && (IsSpreadMove(moveTarget) || moveTarget == TARGET_ALL_BATTLERS || moveTarget == TARGET_FIELD);

    // The AI should understand that while Dynamaxed, status moves function like Protect.
    if (GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX && GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS)
    {
        move = MOVE_MAX_GUARD;
        moveEffect = EFFECT_PROTECT;
    }

    // check status move preference
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_PREFER_STATUS_MOVES && IsBattleMoveStatus(move) && effectiveness != UQ_4_12(0.0))
        ADJUST_SCORE(10);

    // don't get baited into encore
    if (gBattleMoveEffects[moveEffect].encourageEncore
     && HasBattlerSideMoveWithEffect(battlerDef, EFFECT_ENCORE)
     && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerAtk] != HOLD_EFFECT_MENTAL_HERB))
     {
        enum BattlerId partnerDef = GetPartnerBattler(battlerDef);
        if (!AI_IsAbilityOnSide(battlerAtk, ABILITY_AROMA_VEIL)
         || IsMoldBreakerTypeAbility(battlerDef, aiData->abilities[battlerDef], MOVE_NONE)
         || aiData->abilities[battlerDef] == ABILITY_MYCELIUM_MIGHT
         || IsMoldBreakerTypeAbility(partnerDef, aiData->abilities[partnerDef], MOVE_NONE)
         || aiData->abilities[partnerDef] == ABILITY_MYCELIUM_MIGHT)
            return score;
     }

    // check thawing moves
    if (gBattleMons[battlerAtk].status1 & STATUS1_ICY_ANY && MoveThawsUser(move))
        ADJUST_SCORE(10);

    // check burn / frostbite
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING && aiData->abilities[battlerAtk] == ABILITY_NATURAL_CURE)
    {
        if ((gBattleMons[battlerAtk].status1 & STATUS1_BURN && HasOnlyMovesWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL, TRUE))
        || (gBattleMons[battlerAtk].status1 & STATUS1_FROSTBITE && HasOnlyMovesWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL, TRUE)))
            ADJUST_SCORE(-20); // Force switch if all your attacking moves are physical and you have Natural Cure.
    }

    // check guaranteed flinch, a la Fake Out
    if (IsFlinchGuaranteed(battlerAtk, battlerDef, move) && !IsDoubleBattle())
        ADJUST_SCORE(BEST_EFFECT);

    if (IsExplosionMove(move) && gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE && gBattleMons[battlerDef].statStages[STAT_EVASION] <= DEFAULT_STAT_STAGE)
        ADJUST_SCORE(DECENT_EFFECT);

    // Non-volatile statuses
    switch (GetMoveNonVolatileStatus(move))
    {
    case MOVE_EFFECT_POISON:
    case MOVE_EFFECT_TOXIC:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        break;
    case MOVE_EFFECT_SLEEP:
        IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case MOVE_EFFECT_PARALYSIS:
        IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        break;
    case MOVE_EFFECT_BURN:
        IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        break;
    default:
        break;
    }
    // move effect checks
    switch (moveEffect)
    {
    case EFFECT_YAWN:
        IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_AQUA_RING:
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_STRENGTH_SAP:
    {
        u32 atkStat = gBattleMons[battlerDef].attack;
        u32 atkStage = gBattleMons[battlerDef].statStages[STAT_ATK];
        atkStat *= gStatStageRatios[atkStage][0];
        atkStat /= gStatStageRatios[atkStage][1];
        u32 healPercent = atkStat * 100 / gBattleMons[battlerAtk].maxHP;
        if (ShouldRecover(battlerAtk, battlerDef, move, healPercent))
        {
            ADJUST_SCORE(GOOD_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    }
    case EFFECT_MEMENTO:
        if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE && gBattleMons[battlerDef].statStages[STAT_EVASION] <= DEFAULT_STAT_STAGE)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_FINAL_GAMBIT:
        if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_MIRROR_MOVE:
        if (incomingMove && GetMoveEffect(incomingMove) != GetMoveEffect(move))
            return AI_CheckViability(battlerAtk, battlerDef, incomingMove, score);
        break;

    case EFFECT_STAT_CHANGE_HALF_HP: // CheckBadMove check for failure
    case EFFECT_BELLY_DRUM:
        if (HasHPForDamagingSetup(battlerAtk, battlerDef, 50))
            ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (HasHPForDamagingSetup(battlerAtk, battlerDef, 33))
            ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_STUFF_CHEEKS:
    case EFFECT_STAT_CHANGE_MAGNETIC:
    case EFFECT_MINIMIZE:
    case EFFECT_GROWTH:
    case EFFECT_AUTOTOMIZE:
    case EFFECT_STAT_CHANGE:
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_STOCKPILE:
        if (HasMoveWithEffect(battlerAtk, EFFECT_SWALLOW) || HasMoveWithEffect(battlerAtk, EFFECT_SPIT_UP))
            ADJUST_SCORE(DECENT_EFFECT);
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_CHARGE:
        if (HasDamagingMoveOfType(battlerAtk, TYPE_ELECTRIC))
            ADJUST_SCORE(DECENT_EFFECT);
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_ROTOTILLER:
    case EFFECT_FLOWER_SHIELD:
    {
        s32 totalScore = 0;
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            if (moveEffect == EFFECT_ROTOTILLER && !AI_IsBattlerGrounded(battler))
                continue;

            if (!IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
                continue;

            if (battler == battlerAtk || battler == GetPartnerBattler(battlerAtk))
                totalScore = GetStatChangeScore(battlerAtk, battler, move);
            else
                totalScore = -1 * GetStatChangeScore(battlerAtk, battler, move); // Decrease score for opposing mons
        }
        ADJUST_SCORE(totalScore);
        break;
    }
    case EFFECT_EXTREME_EVOBOOST:
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_DEFENSE_CURL:
        if (HasMoveWithEffect(battlerAtk, EFFECT_ROLLOUT) && !gBattleMons[battlerAtk].volatiles.defenseCurl)
            ADJUST_SCORE(DECENT_EFFECT);
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_NO_RETREAT:
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_TIDY_UP:
        IncreaseTidyUpScore(battlerAtk, battlerDef, move, &score);
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_TOXIC_THREAD:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_GEOMANCY:
        if (aiData->holdEffects[battlerAtk] != HOLD_EFFECT_POWER_HERB)
            break; // Don't incrase stats if no Power Herb
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_CURSE:
        if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
        {
            if (IsBattlerTrapped(battlerAtk, battlerDef))
                ADJUST_SCORE(GOOD_EFFECT);
            else
                ADJUST_SCORE(WEAK_EFFECT);
        }
        else
        {
            ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        }
        break;
    case EFFECT_STAT_CHANGE_ON_STATUS:
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_TAR_SHOT:
        // do score increase for volatile
        ADJUST_SCORE(GetStatChangeScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_SWAGGER:
        if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_FOUL_PLAY)
         || HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_PSYCH_UP)
         || HasBattlerSideMoveWithAdditionalEffect(battlerAtk, MOVE_EFFECT_STEAL_STATS))
        {
            ADJUST_SCORE(DECENT_EFFECT);
        }

        if (aiData->abilities[battlerDef] == ABILITY_CONTRARY)
            ADJUST_SCORE(GOOD_EFFECT);
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_BIDE:
        if (aiData->hpPercents[battlerAtk] < 90)
            ADJUST_SCORE(-2); // Should be either removed or turned into increasing score
        break;
    // treat as offense booster
    case EFFECT_ACUPRESSURE:
        // the old logic didn't make any sense
        break;
    case EFFECT_HAZE:
        if (AnyStatIsRaised(GetPartnerBattler(battlerAtk))
          || DoesPartnerHaveSameMoveEffect(GetPartnerBattler(battlerAtk), battlerDef, move, aiData->partnerMove))
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, moveTargetsBothOpponents);
        break;
    case EFFECT_ROAR:
        if ((IsSoundMove(move) && aiData->abilities[battlerDef] == ABILITY_SOUNDPROOF)
          || aiData->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
            break;
        else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            break;
        score += AI_TryToClearStats(battlerAtk, battlerDef, moveTargetsBothOpponents);
        break;
    case EFFECT_CONVERSION:
        if (!IS_BATTLER_OF_TYPE(battlerAtk, GetMoveType(gBattleMons[battlerAtk].moves[0])))
        {
            ADJUST_SCORE(WEAK_EFFECT);
            if (aiData->abilities[battlerAtk] == ABILITY_ADAPTABILITY)
                ADJUST_SCORE(WEAK_EFFECT);
            if (IsConsideringZMove(battlerAtk, battlerDef, move))
                ADJUST_SCORE(BEST_EFFECT);
        }
        break;
    case EFFECT_SWALLOW:
        if (gBattleMons[battlerAtk].volatiles.stockpileCounter == 0)
        {
            break;
        }
        else
        {
            u32 healPercent = 0;
            switch (gBattleMons[battlerAtk].volatiles.stockpileCounter)
            {
            case 1:
                healPercent = 25;
                break;
            case 2:
                healPercent = 50;
                break;
            case 3:
                healPercent = 100;
                break;
            default:
                break;
            }

            if (ShouldRecover(battlerAtk, battlerDef, move, healPercent))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_LIFE_DEW:
        if (ShouldRecover(battlerAtk, battlerDef, move, 25))
            ADJUST_SCORE(GOOD_EFFECT);
        if (ShouldRecover(GetPartnerBattler(battlerAtk), battlerDef, move, 25))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_AURORA_VEIL:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
        {
            ADJUST_SCORE(BEST_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_LIGHT_CLAY)
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_REST:
        if (!(CanBeSlept(battlerAtk, battlerAtk, aiData->abilities[battlerAtk], NOT_BLOCKED_BY_SLEEP_CLAUSE)))
        {
            break;
        }
        else if (ShouldRecover(battlerAtk, battlerDef, move, 100))
        {
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_SLP
             || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_CURE_STATUS
             || (AI_GetWeather() & B_WEATHER_RAIN && gBattleStruct->weatherDuration != 1 && aiData->abilities[battlerAtk] == ABILITY_HYDRATION && aiData->holdEffects[battlerAtk] != HOLD_EFFECT_UTILITY_UMBRELLA))
            {
                ADJUST_SCORE(BEST_EFFECT);
            }
            else if (HasMoveUsableWhileAsleep(battlerAtk))
            {
                ADJUST_SCORE(GOOD_EFFECT);
            }
            else if (aiData->abilities[battlerAtk] == ABILITY_SHED_SKIN
                  || aiData->abilities[battlerAtk] == ABILITY_EARLY_BIRD)
            {
                ADJUST_SCORE(DECENT_EFFECT);
            }
        }
        break;
    case EFFECT_OHKO:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            break;
        else if (gBattleMons[battlerAtk].volatiles.battlerWithSureHit == battlerDef + 1)
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_MEAN_LOOK:
        if (ShouldTrap(battlerAtk, battlerDef, move, DONT_CONSIDER_WRAP_DAMAGE))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_FOCUS_ENERGY:
    case EFFECT_LASER_FOCUS:
        if (aiData->abilities[battlerAtk] == ABILITY_SUPER_LUCK
         || aiData->abilities[battlerAtk] == ABILITY_SNIPER
         || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_SCOPE_LENS
         || HasMoveWithFlag(battlerAtk, GetMoveCriticalHitStage))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_CONFUSE:
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_SUBSTITUTE:
    case EFFECT_SHED_TAIL:
        ADJUST_SCORE(IncreaseSubstituteMoveScore(battlerAtk, battlerDef, move));
        break;
    case EFFECT_MIMIC:
        if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
        {
            if (aiData->lastUsedMove[battlerDef] != MOVE_NONE
             && (GetMoveEffect(aiData->lastUsedMove[battlerDef]) != GetMoveEffect(move)))
                return AI_CheckViability(battlerAtk, battlerDef, aiData->lastUsedMove[battlerDef], score);
        }
        break;
    case EFFECT_LEECH_SEED:
        if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
          || gBattleMons[battlerDef].volatiles.leechSeed
          || HasMoveWithEffect(battlerDef, EFFECT_RAPID_SPIN)
          || aiData->abilities[battlerDef] == ABILITY_LIQUID_OOZE
          || aiData->abilities[battlerDef] == ABILITY_MAGIC_GUARD)
            break;
        ADJUST_SCORE(GOOD_EFFECT);
        if (!HasDamagingMove(battlerDef)
            || IsBattlerTrapped(battlerAtk, battlerDef)
            || aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_DO_NOTHING:
    case EFFECT_HOLD_HANDS:
    case EFFECT_CELEBRATE:
    case EFFECT_HAPPY_HOUR:
    case EFFECT_LAST_RESORT:
        if (IsConsideringZMove(battlerAtk, battlerDef, move))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_TELEPORT:
        if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
            break;
        //fallthrough
    case EFFECT_HIT_ESCAPE:
    case EFFECT_PARTING_SHOT:
    case EFFECT_WEATHER_AND_SWITCH:
        switch (ShouldPivot(battlerAtk, battlerDef, move))
        {
        case DONT_PIVOT:
            ADJUST_SCORE(-5);    // technically should go in CheckBadMove, but this is easier/less computationally demanding
            break;
        case CAN_TRY_PIVOT:
            break;
        case SHOULD_PIVOT:
            ADJUST_SCORE(BEST_EFFECT);
            break;
        }
        break;
    case EFFECT_BATON_PASS:
        if ((aiData->shouldSwitch & (1u << battlerAtk)) && (gBattleMons[battlerAtk].volatiles.substitute
          || gBattleMons[battlerAtk].volatiles.powerTrick
          || gBattleMons[battlerAtk].volatiles.magnetRiseTimer > 0
          || gBattleMons[battlerAtk].volatiles.aquaRing
          || gBattleMons[battlerAtk].volatiles.root
          || AnyStatIsRaised(battlerAtk)))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_DISABLE:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            break;
        else if (gBattleMons[battlerDef].volatiles.disableTimer == 0
        && (aiData->lastUsedMove[battlerDef] != MOVE_NONE)
        && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
        && (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)))
        {
            if (CanTargetMoveFaintAi(aiData->lastUsedMove[battlerDef], battlerDef, battlerAtk, 1))
                ADJUST_SCORE(GOOD_EFFECT); // Disable move that can kill attacker
        }
        break;
    case EFFECT_ENCORE:
    {
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            break;

        bool32 encourage = gBattleMoveEffects[GetMoveEffect(aiData->lastUsedMove[battlerDef])].encourageEncore;

        switch (GetMoveNonVolatileStatus(aiData->lastUsedMove[battlerDef]))
        {
        case MOVE_EFFECT_POISON:
        case MOVE_EFFECT_PARALYSIS:
            encourage = TRUE;
            break;
        default:
            break;
        }
        if (gBattleMons[battlerDef].volatiles.encoreTimer == 0
         && (B_MENTAL_HERB < GEN_5 || aiData->holdEffects[battlerDef] != HOLD_EFFECT_MENTAL_HERB)
         && (encourage))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    }
    case EFFECT_SNORE:
    case EFFECT_SLEEP_TALK:
        if (!IsWakeupTurn(battlerAtk) && IsAsleepOrComatose(battlerAtk, aiData->abilities[battlerAtk]))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_LOCK_ON:
        if (HasMoveWithEffect(battlerAtk, EFFECT_OHKO))
            ADJUST_SCORE(GOOD_EFFECT);
        else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 85, TRUE))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_DESTINY_BOND:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            break;
        else if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) && CanTargetFaintAi(battlerDef, battlerAtk))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_SPITE:
        //TODO - predicted move
        break;
    case EFFECT_WISH:
    case EFFECT_HEAL_BELL:
        if (ShouldUseWishAromatherapy(battlerAtk, battlerDef, move))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PURIFY:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY)
        {
            if (ShouldCureStatus(battlerAtk, battlerDef, aiData))
                ADJUST_SCORE(GOOD_EFFECT);
            if (ShouldRecover(battlerAtk, battlerDef, move, 50))
                RETURN_SCORE_PLUS(WEAK_EFFECT);
        }
        break;
    case EFFECT_PROTECT:
        if (incomingMove == MOVE_UNAVAILABLE)
            incomingMove = MOVE_NONE;
        enum ProtectMethod protectMethod = GetMoveProtectMethod(move);
        switch (protectMethod)
        {
        case PROTECT_QUICK_GUARD:
            if (incomingMove != MOVE_NONE && GetMovePriority(incomingMove) > 0)
            {
                ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            }
            break;
        case PROTECT_WIDE_GUARD:
        {
            enum MoveTarget predictedTargetType = AI_GetBattlerMoveTargetType(battlerDef, incomingMove);
            if (incomingMove != MOVE_NONE && (predictedTargetType == TARGET_BOTH || predictedTargetType == TARGET_FOES_AND_ALLY))
            {
                ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            }
            else if (hasPartner && AI_GetBattlerMoveTargetType(GetPartnerBattler(battlerAtk), aiData->partnerMove) == TARGET_FOES_AND_ALLY)
            {
                if (aiData->abilities[battlerAtk] != ABILITY_TELEPATHY)
                  ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            }
            break;
        }
        case PROTECT_CRAFTY_SHIELD:
            if (incomingMove != MOVE_NONE && IsBattleMoveStatus(incomingMove) && AI_GetBattlerMoveTargetType(battlerDef, incomingMove) != TARGET_USER)
                ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            break;

        case PROTECT_MAT_BLOCK:
            if (IsBattlersFirstTurn(battlerAtk) && incomingMove != MOVE_NONE
              && !IsBattleMoveStatus(incomingMove) && AI_GetBattlerMoveTargetType(battlerDef, incomingMove) != TARGET_USER)
                ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            break;
        case PROTECT_KINGS_SHIELD:
            if (aiData->abilities[battlerAtk] == ABILITY_STANCE_CHANGE //Special logic for Aegislash
             && gBattleMons[battlerAtk].species == SPECIES_AEGISLASH_BLADE
             && !IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]))
            {
                ADJUST_SCORE(GOOD_EFFECT);
                break;
            }
            //fallthrough
        default: // protect
            ADJUST_SCORE(ProtectChecks(battlerAtk, battlerDef, move, incomingMove));
            break;
        }
        break;
    case EFFECT_ENDURE:
        if (CanTargetFaintAi(battlerDef, battlerAtk))
        {
            if (gBattleMons[battlerAtk].hp > gBattleMons[battlerAtk].maxHP / 4 // Pinch berry couldn't have activated yet
             && IsPinchBerryItemEffect(aiData->holdEffects[battlerAtk]))
                ADJUST_SCORE(GOOD_EFFECT);
            else if ((gBattleMons[battlerAtk].hp > 1) // Only spam endure for Flail/Reversal if you're not at Min Health
             && (HasMoveWithEffect(battlerAtk, EFFECT_FLAIL) || HasMoveWithEffect(battlerAtk, EFFECT_ENDEAVOR)))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_CEASELESS_EDGE:
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_STONE_AXE:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, move, aiData))
        {
            if (IsBattlersFirstTurn(battlerAtk))
                ADJUST_SCORE(BEST_EFFECT);
            else
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_FORESIGHT:
        if (aiData->abilities[battlerAtk] == ABILITY_SCRAPPY || aiData->abilities[battlerAtk] == ABILITY_MINDS_EYE)
            break;
        else if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
         || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST)
         && (HasMoveWithType(battlerAtk, TYPE_NORMAL)
         || HasMoveWithType(battlerAtk, TYPE_FIGHTING))))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_MIRACLE_EYE:
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
          || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK) && (HasMoveWithType(battlerAtk, TYPE_PSYCHIC))))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PERISH_SONG:
        if (IsBattlerTrapped(battlerAtk, battlerDef))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_WEATHER:
        ADJUST_SCORE(CalcWeatherScore(battlerAtk, battlerDef, move, aiData));
        break;
    case EFFECT_FELL_STINGER:
        if (gBattleMons[battlerAtk].statStages[STAT_ATK] < MAX_STAT_STAGE
        && aiData->abilities[battlerAtk] != ABILITY_CONTRARY
        && CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, AI_ATTACKING))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_PSYCH_UP:
        score += AI_ShouldCopyStatChanges(battlerAtk, battlerDef);
        break;
    case EFFECT_SEMI_INVULNERABLE:
        if (incomingMove != MOVE_NONE && isBattle1v1)
        {
            if (aiData->abilities[battlerAtk] == ABILITY_NO_GUARD || aiData->abilities[battlerDef] == ABILITY_NO_GUARD)
                break;

            enum BattleMoveEffects predictedEffect = GetMoveEffect(incomingMove);
            if ((AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
             && (IsExplosionMove(incomingMove) || predictedEffect == EFFECT_PROTECT))
                ADJUST_SCORE(GOOD_EFFECT);
            else if (predictedEffect == EFFECT_SEMI_INVULNERABLE && !IsSemiInvulnerable(battlerDef, CHECK_ALL))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (IsBattlersFirstTurn(battlerAtk) && !IsTargetingPartner(battlerAtk, battlerDef))
        {
            // Fake Out in doubles
            if (IsDoubleBattle() && IsFlinchGuaranteed(battlerAtk, battlerDef, move))
            {
                bool32 atkKoDef = CanAIFaintTarget(battlerAtk, battlerDef, 1);
                bool32 atkKoDefPartner = CanAIFaintTarget(battlerAtk, battlerDefPartner, 1);
                bool32 defKoAtkPartner = CanAIFaintTarget(battlerDef, battlerAtkPartner, 1);
                bool32 atkPartnerKoDef = CanAIFaintTarget(battlerAtkPartner, battlerDef, 1);
                bool32 atkPartnerKoDefPartner = CanAIFaintTarget(battlerAtkPartner, battlerDefPartner, 1);
                bool32 defPartnerKoAtkPartner = CanAIFaintTarget(battlerDefPartner, battlerAtkPartner, 1);
                bool32 atkPartnerDoubleFastKOd = (defKoAtkPartner && AI_WhoStrikesFirst(battlerAtkPartner, battlerDef, gBattleMons[battlerAtkPartner].moves[gAiBattleData->chosenMoveIndex[battlerAtkPartner]], predictedMove, CONSIDER_PRIORITY) == AI_IS_SLOWER)
                 && (defPartnerKoAtkPartner && AI_WhoStrikesFirst(battlerAtkPartner, battlerDefPartner, gBattleMons[battlerAtkPartner].moves[gAiBattleData->chosenMoveIndex[battlerAtkPartner]], MOVE_SCRATCH, CONSIDER_PRIORITY) == AI_IS_SLOWER);

                // If either opponent has Fake Out, it's their first turn but user is faster - incentivise Fake Out on both
                if ((HasMove(battlerDef, MOVE_FAKE_OUT) && IsBattlersFirstTurn(battlerDef)
                 && AI_WhoStrikesFirst(battlerAtk, battlerDef, MOVE_FAKE_OUT, MOVE_FAKE_OUT, CONSIDER_PRIORITY) == AI_IS_FASTER)
                 || (HasMove(battlerDefPartner, MOVE_FAKE_OUT) && IsBattlersFirstTurn(battlerDefPartner)
                 && AI_WhoStrikesFirst(battlerAtk, battlerDefPartner, MOVE_FAKE_OUT, MOVE_FAKE_OUT, CONSIDER_PRIORITY) == AI_IS_FASTER))
                {
                    ADJUST_SCORE(FAST_KILL + 2);
                }
                // If ally has KO on target's partner, but target can fast KO ally (checking move and priority combinations for everything likely gets a bit complicated)
                else if (hasPartner && atkPartnerKoDefPartner
                 && (defKoAtkPartner && AI_WhoStrikesFirst(battlerAtkPartner, battlerDef, gBattleMons[battlerAtkPartner].moves[gAiBattleData->chosenMoveIndex[battlerAtkPartner]], predictedMove, CONSIDER_PRIORITY) == AI_IS_SLOWER)
                 && !(atkKoDef && AI_WhoStrikesFirst(battlerAtk, battlerDef, move, predictedMove, DONT_CONSIDER_PRIORITY) == AI_IS_FASTER))
                {
                    if (AI_WhoStrikesFirst(battlerAtkPartner, battlerDefPartner, gBattleMons[battlerAtkPartner].moves[gAiBattleData->chosenMoveIndex[battlerAtkPartner]], predictedMove, CONSIDER_PRIORITY) == AI_IS_FASTER)
                        ADJUST_SCORE(FAST_KILL + 2); // No point fast KOing target's partner when user can save ally who will do it anyway
                    else if (atkPartnerDoubleFastKOd)
                    {
                        if (RandomPercentage(RNG_AI_FAKE_OUT_SAVE_ALLY, FAKE_OUT_SAVE_ALLY_CHANCE))
                            ADJUST_SCORE(FAST_KILL + 2); // Still Fake Out in case the ally is not double targeted
                        else
                            ADJUST_SCORE(SLOW_KILL + 2); // Prioritize fast KO
                    }
                    else
                    {
                        ADJUST_SCORE(SLOW_KILL + 2);
                    }
                }
                // If ally has slow KO with their chosen move, user sees no KOs while outspeeding (checking move and priority combinations for everything likely gets a bit complicated)
                else if (hasPartner
                 && (atkPartnerKoDef && AI_WhoStrikesFirst(battlerAtkPartner, battlerDef, gBattleMons[battlerAtkPartner].moves[gAiBattleData->chosenMoveIndex[battlerAtkPartner]], predictedMove, CONSIDER_PRIORITY) == AI_IS_SLOWER)
                 && !(atkKoDef && AI_WhoStrikesFirst(battlerAtk, battlerDef, move, predictedMove, DONT_CONSIDER_PRIORITY) == AI_IS_FASTER)
                 && !(atkKoDefPartner && AI_WhoStrikesFirst(battlerAtk, battlerDefPartner, move, MOVE_SCRATCH, DONT_CONSIDER_PRIORITY) == AI_IS_FASTER))
                {
                    ADJUST_SCORE(GOOD_EFFECT);
                }
                else
                {
                    ADJUST_SCORE(DECENT_EFFECT);
                }
            }
            else if (IsBestDmgMove(battlerAtk, battlerDef, AI_ATTACKING, move))
            {
                ADJUST_SCORE(BEST_EFFECT);
            }
        }
        break;
    case EFFECT_FURY_CUTTER:
        if (isBattle1v1 && aiData->holdEffects[battlerAtk] == HOLD_EFFECT_METRONOME)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_ATTRACT:
        if (isBattle1v1
        && (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
        && BattlerWillFaintFromSecondaryDamage(battlerDef, aiData->abilities[battlerDef]))
            break; // Don't use if the attract won't have a change to activate
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY
        || gBattleMons[battlerDef].volatiles.confusionTimer > 0
        || IsBattlerTrapped(battlerAtk, battlerDef))
            ADJUST_SCORE(GOOD_EFFECT);
        else
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_SAFEGUARD:
        if (!IsMistyTerrainAffected(battlerAtk, aiData->abilities[battlerAtk], aiData->holdEffects[battlerAtk], gFieldTimers.terrain) || !AI_IsBattlerGrounded(battlerAtk))
            ADJUST_SCORE(DECENT_EFFECT); // TODO: check if opp has status move?
        //if (CountUsablePartyMons(battlerDef) != 0)
            //ADJUST_SCORE(8);
        break;
    case EFFECT_COURT_CHANGE:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_GOOD_COURT)
            ADJUST_SCORE(WEAK_EFFECT);
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_BAD_COURT)
            ADJUST_SCORE(WEAK_EFFECT);

        if (AreAnyHazardsOnSide(GetBattlerSide(battlerAtk)) && CountUsablePartyMons(battlerAtk) != 0)
        {
            ADJUST_SCORE(DECENT_EFFECT);
        }

        if (hasPartner)
        {
            if (IsHazardMove(aiData->partnerMove) // partner is going to set up hazards
              && AI_IsFaster(GetPartnerBattler(battlerAtk), battlerAtk, aiData->partnerMove, incomingMove, CONSIDER_PRIORITY)) // partner is going to set up before the Court Change
            {
                ADJUST_SCORE(-10);
                break;
            }
        }
        break;
    case EFFECT_DEFOG:
        if ((AreAnyHazardsOnSide(GetBattlerSide(battlerAtk)) && CountUsablePartyMons(battlerAtk) != 0)
            || (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_GOOD_FOG))
        {
            ADJUST_SCORE(GOOD_EFFECT);
        }
        else if (!AreAnyHazardsOnSide(GetBattlerSide(battlerDef)) || CountUsablePartyMons(battlerDef) == 0) //Don't blow away hazards if you set them up
        {
            if (hasPartner)
            {
                if (IsHazardMove(aiData->partnerMove) // Partner is going to set up hazards
                    && AI_IsSlower(battlerAtk, GetPartnerBattler(battlerAtk), move, predictedMove, CONSIDER_PRIORITY)) // Partner going first
                    break; // Don't use Defog if partner is going to set up hazards
            }
            ADJUST_SCORE(IncreaseStatDownScore(battlerAtk, battlerDef, STAT_EVASION));
        }
        break;
    case EFFECT_TORMENT:
        break;
    case EFFECT_FOLLOW_ME:
        if (hasPartner
          && AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_USER
          && !IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef])
          && (!IsPowderMove(move) || IsAffectedByPowderMove(battlerDef, aiData->abilities[battlerDef], aiData->holdEffects[battlerDef])))
          // Rage Powder doesn't affect powder immunities
        {
            enum Move predictedMoveOnPartner = aiData->lastUsedMove[GetPartnerBattler(battlerAtk)];
            if (predictedMoveOnPartner != MOVE_NONE && !IsBattleMoveStatus(predictedMoveOnPartner))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_TAUNT:
        if (IsBattleMoveStatus(incomingMove))
            ADJUST_SCORE(GOOD_EFFECT);
        else if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_STATUS))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TRICK:
    case EFFECT_BESTOW:
        switch (aiData->holdEffects[battlerAtk])
        {
        case HOLD_EFFECT_CHOICE_SCARF:
            ADJUST_SCORE(DECENT_EFFECT); // assume its beneficial
            break;
        case HOLD_EFFECT_CHOICE_BAND:
            if (!HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_CHOICE_SPECS:
            if (!HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            if (!ShouldPoison(battlerAtk, battlerAtk)
             || (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY))
            {
                ADJUST_SCORE(DECENT_EFFECT);
            }
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!ShouldBurn(battlerAtk, battlerAtk, aiData->abilities[battlerAtk])
             || (gBattleMons[battlerAtk].status1 & STATUS1_BURN))
            {
                ADJUST_SCORE(DECENT_EFFECT);
            }
            break;
        case HOLD_EFFECT_BLACK_SLUDGE:
            if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON) && aiData->abilities[battlerDef] != ABILITY_MAGIC_GUARD)
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_IRON_BALL:
            if (!HasMoveWithEffect(battlerDef, EFFECT_FLING) || !AI_IsBattlerGrounded(battlerDef))
                ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_LAGGING_TAIL:
        case HOLD_EFFECT_STICKY_BARB:
            ADJUST_SCORE(DECENT_EFFECT);
            break;
        case HOLD_EFFECT_UTILITY_UMBRELLA:
            if (!(AI_GetWeather() & B_WEATHER_SUN && aiData->abilities[battlerAtk] == ABILITY_DRY_SKIN)
             && DoesAbilityBenefitFromSunOrRain(battlerDef, aiData->abilities[battlerDef], AI_GetWeather()))
            {
                ADJUST_SCORE(DECENT_EFFECT); // Remove their weather benefit
            }
            break;
        case HOLD_EFFECT_EJECT_BUTTON:
            //if (!IsRaidBattle() && GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX && gNewBS->dynamaxData.timer[battlerDef] > 1 &&
            if (HasDamagingMove(battlerAtk)
             || (hasPartner && HasDamagingMove(GetPartnerBattler(battlerAtk))))
            {
                ADJUST_SCORE(DECENT_EFFECT); // Force 'em out next turn
            }
            break;
        default:
            if (GetMoveEffect(move) != EFFECT_BESTOW && aiData->items[battlerAtk] == ITEM_NONE && aiData->items[battlerDef] != ITEM_NONE)
            {
                switch (aiData->holdEffects[battlerDef])
                {
                case HOLD_EFFECT_CHOICE_BAND:
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoison(battlerAtk, battlerAtk))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurn(battlerAtk, battlerAtk, aiData->abilities[battlerAtk]))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON) || aiData->abilities[battlerAtk] == ABILITY_MAGIC_GUARD)
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_IRON_BALL:
                    if (HasMoveWithEffect(battlerAtk, EFFECT_FLING))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                case HOLD_EFFECT_UTILITY_UMBRELLA:
                    if ((AI_GetWeather() & B_WEATHER_SUN) && (aiData->abilities[battlerAtk] == ABILITY_DRY_SKIN || aiData->abilities[battlerDef] == ABILITY_DRY_SKIN))
                        ADJUST_SCORE(DECENT_EFFECT);
                    else if (!DoesAbilityBenefitFromSunOrRain(battlerAtk, aiData->abilities[battlerAtk], AI_GetWeather()))
                        ADJUST_SCORE(WEAK_EFFECT);
                    break;
                default:
                    ADJUST_SCORE(WEAK_EFFECT);    //other hold effects generally universally good
                    break;
                }
            }
        }
        break;
    case EFFECT_CORROSIVE_GAS:
        if (CanKnockOffItem(battlerDef, battlerAtk, aiData->items[battlerDef]))
        {
            switch (aiData->holdEffects[battlerDef])
            {
            case HOLD_EFFECT_IRON_BALL:
                if (HasMoveWithEffect(battlerDef, EFFECT_FLING))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case HOLD_EFFECT_LAGGING_TAIL:
            case HOLD_EFFECT_STICKY_BARB:
                break;
            default:
                ADJUST_SCORE(DECENT_EFFECT);
                break;
            }
        }
        break;
    case EFFECT_INGRAIN:
        ADJUST_SCORE(WEAK_EFFECT);
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_BIG_ROOT)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_MAGIC_COAT:
        if (CanMoveBeBouncedBack(battlerDef, incomingMove))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_RECYCLE:
        if (GetBattlerPartyState(battlerAtk)->usedHeldItem != ITEM_NONE)
            ADJUST_SCORE(WEAK_EFFECT);
        if (IsRecycleEncouragedItem(GetBattlerPartyState(battlerAtk)->usedHeldItem))
            ADJUST_SCORE(WEAK_EFFECT);
        if (aiData->abilities[battlerAtk] == ABILITY_RIPEN)
        {
            enum Item item = GetBattlerPartyState(battlerAtk)->usedHeldItem;
            u32 toHeal = (GetItemHoldEffectParam(item) == 10) ? 10 : gBattleMons[battlerAtk].maxHP / GetItemHoldEffectParam(item);

            if (IsStatBoostingBerry(item) && aiData->hpPercents[battlerAtk] > 60)
                ADJUST_SCORE(WEAK_EFFECT);
            else if (ShouldRestoreHpBerry(battlerAtk, item) && !CanAIFaintTarget(battlerAtk, battlerDef, 0)
              && ((AI_GetWhichBattlerFasterOrTies(battlerAtk, battlerDef, TRUE) == 1 && CanTargetFaintAiWithMod(battlerDef, battlerAtk, 0, 0))
               || !CanTargetFaintAiWithMod(battlerDef, battlerAtk, toHeal, 0)))
                ADJUST_SCORE(WEAK_EFFECT);    // Recycle healing berry if we can't otherwise faint the target and the target won't kill us after we activate the berry
        }
        break;
    case EFFECT_DOODLE:
    case EFFECT_ENTRAINMENT:
    case EFFECT_GASTRO_ACID:
    case EFFECT_ROLE_PLAY:
    case EFFECT_SKILL_SWAP:
    case EFFECT_OVERWRITE_ABILITY:
        AbilityChangeScore(battlerAtk, battlerDef, move, &score, aiData);
        return score;
    case EFFECT_IMPRISON:
        if (incomingMove != MOVE_NONE && HasMove(battlerAtk, incomingMove))
            ADJUST_SCORE(DECENT_EFFECT);
        else if (!IsBattlersFirstTurn(battlerAtk))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_REFRESH:
        if ((gBattleMons[battlerAtk].status1 & STATUS1_CAN_MOVE)
         && ShouldCureStatus(battlerAtk, battlerAtk, aiData))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TAKE_HEART:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY
         || BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPATK)
         || BattlerStatCanRise(battlerAtk, aiData->abilities[battlerAtk], STAT_SPDEF))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PSYCHO_SHIFT:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY)
            IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_BURN)
            IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_PARALYSIS)
            IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_SLEEP)
            IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        else if (gBattleMons[battlerAtk].status1 & STATUS1_FROSTBITE)
            IncreaseFrostbiteScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_GRUDGE:
        break;
    case EFFECT_SNATCH:
        if (incomingMove != MOVE_NONE && MoveCanBeSnatched(incomingMove))
            ADJUST_SCORE(GOOD_EFFECT); // Steal move
        break;
    case EFFECT_MUD_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC) && HasMoveWithType(battlerDef, TYPE_ELECTRIC))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_WATER_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_FIRE) && (HasMoveWithType(battlerDef, TYPE_FIRE)))
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_GUARD_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_DEF] > gBattleMons[battlerAtk].statStages[STAT_DEF]
          && gBattleMons[battlerDef].statStages[STAT_SPDEF] >= gBattleMons[battlerAtk].statStages[STAT_SPDEF])
            ADJUST_SCORE(DECENT_EFFECT);
        else if (gBattleMons[battlerDef].statStages[STAT_SPDEF] > gBattleMons[battlerAtk].statStages[STAT_SPDEF]
          && gBattleMons[battlerDef].statStages[STAT_DEF] >= gBattleMons[battlerAtk].statStages[STAT_DEF])
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_POWER_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_ATK] > gBattleMons[battlerAtk].statStages[STAT_ATK]
          && gBattleMons[battlerDef].statStages[STAT_SPATK] >= gBattleMons[battlerAtk].statStages[STAT_SPATK])
            ADJUST_SCORE(DECENT_EFFECT);
        else if (gBattleMons[battlerDef].statStages[STAT_SPATK] > gBattleMons[battlerAtk].statStages[STAT_SPATK]
          && gBattleMons[battlerDef].statStages[STAT_ATK] >= gBattleMons[battlerAtk].statStages[STAT_ATK])
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_POWER_TRICK:
        if (!gBattleMons[battlerAtk].volatiles.powerTrick
         && gBattleMons[battlerAtk].defense > gBattleMons[battlerAtk].attack
         && HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_HEART_SWAP:
        {
            bool32 hasHigherStat = FALSE;
            enum Stat statId;
            //Only use if all target stats are >= attacker stats to prevent infinite loop
            for (statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
            {
                if (gBattleMons[battlerDef].statStages[statId] < gBattleMons[battlerAtk].statStages[statId])
                    break;
                if (gBattleMons[battlerDef].statStages[statId] > gBattleMons[battlerAtk].statStages[statId])
                    hasHigherStat = TRUE;
            }
            if (hasHigherStat && statId == NUM_BATTLE_STATS)
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_SPEED_SWAP:
        if (gBattleMons[battlerDef].speed > gBattleMons[battlerAtk].speed)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_GUARD_SPLIT:
    {
        u32 atkDefense = gBattleMons[battlerAtk].defense;
        u32 defDefense = gBattleMons[battlerDef].defense;
        u32 atkSpDefense = gBattleMons[battlerAtk].spDefense;
        u32 defSpDefense = gBattleMons[battlerDef].spDefense;

        // It's actually * 100 and / 2;
        u32 newDefense = (atkDefense + defDefense) * 50;
        u32 newSpDefense = (atkSpDefense + defSpDefense) * 50;

        // We want to massively raise our defense.
        if (newDefense > atkDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
        if (newSpDefense > atkSpDefense * GUARD_SPLIT_ALLY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);

        // We also want to massively lower theirs.
        if (newDefense < defDefense * GUARD_SPLIT_ENEMY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
        if (newSpDefense < defSpDefense * GUARD_SPLIT_ENEMY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);

        ADJUST_SCORE(WORST_EFFECT);
        break;
    }
    case EFFECT_POWER_SPLIT:
    {
        u32 atkAttack = gBattleMons[battlerAtk].attack;
        u32 defAttack = gBattleMons[battlerDef].attack;
        u32 atkSpAttack = gBattleMons[battlerAtk].spAttack;
        u32 defSpAttack = gBattleMons[battlerDef].spAttack;

        // It's actually * 100 and / 2
        u32 newAttack = (atkAttack + defAttack) * 50;
        u32 newSpAtk = (atkSpAttack + defSpAttack) * 50;

        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL) && newAttack > atkAttack * POWER_SPLIT_ALLY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL) && newSpAtk > atkSpAttack * POWER_SPLIT_ALLY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
        if (newAttack < defAttack * POWER_SPLIT_ENEMY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);
        if (newSpAtk < defSpAttack * POWER_SPLIT_ENEMY_PERCENTAGE)
            ADJUST_AND_RETURN_SCORE(GOOD_EFFECT);

        ADJUST_SCORE(WORST_EFFECT);
        break;
    }
    case EFFECT_TERRAIN:
        enum BattleTerrain terrain = GetMoveTerrainType(move);

        if (ShouldSetTerrain(battlerAtk, terrain))
        {
            ADJUST_SCORE(GOOD_EFFECT);
            if ((terrain == B_TERRAIN_ELECTRIC || terrain == B_TERRAIN_MISTY)
             && gBattleMons[battlerAtk].volatiles.yawn
             && AI_IsBattlerGrounded(battlerAtk))
                ADJUST_SCORE(BEST_EFFECT);
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_TERRAIN_EXTENDER || HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_TERRAIN_PULSE))
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    case EFFECT_STEEL_ROLLER:
        {
            u32 terrain = gFieldTimers.terrain;
            if (ShouldClearFieldStatus(battlerAtk, terrain))
                ADJUST_SCORE(GOOD_EFFECT);
            if (ShouldSetFieldStatus(battlerDef, terrain))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_ICE_SPINNER:
        {
            u32 terrain = gFieldTimers.terrain;
            if (ShouldClearFieldStatus(battlerAtk, terrain))
                ADJUST_SCORE(GOOD_EFFECT);
            if (ShouldSetFieldStatus(battlerDef, terrain))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_PLEDGE:
        if (hasPartner && HasMoveWithEffect(GetPartnerBattler(battlerAtk), EFFECT_PLEDGE))
            ADJUST_SCORE(GOOD_EFFECT); // Partner might use pledge move
        break;
    case EFFECT_TRICK_ROOM:
        if (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_POWERFUL_STATUS))
        {
            if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                ADJUST_SCORE(GOOD_EFFECT);
            // Set it for next Pokémon in singles.
            else if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && !hasPartner && (CountUsablePartyMons(battlerAtk) != 0))
                ADJUST_SCORE(DECENT_EFFECT);
            // Don't unset it on last turn.
            else if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 1 && ShouldClearFieldStatus(battlerAtk, STATUS_FIELD_TRICK_ROOM))
                ADJUST_SCORE(GOOD_EFFECT);
        }
        break;
    case EFFECT_MAGIC_ROOM:
        ADJUST_SCORE(WEAK_EFFECT);
        if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_NONE && aiData->holdEffects[battlerDef] != HOLD_EFFECT_NONE)
            ADJUST_SCORE(WEAK_EFFECT);
        if (!isBattle1v1 && aiData->holdEffects[GetPartnerBattler(battlerAtk)] == HOLD_EFFECT_NONE && aiData->holdEffects[GetPartnerBattler(battlerDef)] != HOLD_EFFECT_NONE)
            ADJUST_SCORE(WEAK_EFFECT);
        break;
    case EFFECT_WONDER_ROOM:
        if ((HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL) && gBattleMons[battlerAtk].defense < gBattleMons[battlerAtk].spDefense)
          || (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL) && gBattleMons[battlerAtk].spDefense < gBattleMons[battlerAtk].defense))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY || ShouldClearFieldStatus(battlerAtk, STATUS_FIELD_GRAVITY)))
        {
            // improve accuracy of Hypnosis
            if (HasSleepMoveWithLowAccuracy(battlerAtk, battlerDef)
             || HasSleepMoveWithLowAccuracy(GetPartnerBattler(battlerAtk), battlerDef))
                IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
            if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, TRUE)
             || HasMoveWithLowAccuracy(GetPartnerBattler(battlerAtk), battlerDef, 90, TRUE))
                ADJUST_SCORE(WEAK_EFFECT);
            if (ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_GRAVITY))
                ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_ION_DELUGE:
        if ((aiData->abilities[battlerAtk] == ABILITY_VOLT_ABSORB
          || aiData->abilities[battlerAtk] == ABILITY_MOTOR_DRIVE
          || (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) >= GEN_5 && aiData->abilities[battlerAtk] == ABILITY_LIGHTNING_ROD))
          && predictedType == TYPE_NORMAL)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_FLING:
        /* TODO
        switch (gFlingTable[aiData->items[battlerAtk]].effect)
        {
        case MOVE_EFFECT_BURN:
            IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_FLINCH:
            if (ShouldTryToFlinch(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move))
                score += 2;
            break;
        case MOVE_EFFECT_PARALYSIS:
            IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_POISON:
        case MOVE_EFFECT_TOXIC:
            IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_FREEZE:
            if (AI_CanFreeze(battlerAtk, battlerDef))
                ADJUST_SCORE(GOOD_EFFECT);
            break;
        }*/
        break;
    case EFFECT_EMBARGO:
        if (aiData->holdEffects[battlerDef] != HOLD_EFFECT_NONE)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_POWDER:
        if (incomingMove != MOVE_NONE && !IsBattleMoveStatus(incomingMove) && predictedType == TYPE_FIRE)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_TELEKINESIS:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE) || !AI_IsBattlerGrounded(battlerDef))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_HEAL_BLOCK:
        if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) && incomingMove != MOVE_NONE && IsHealingMove(incomingMove))
            ADJUST_SCORE(DECENT_EFFECT); // Try to cancel healing move
        else if (HasHealingEffect(battlerDef) || aiData->holdEffects[battlerDef] == HOLD_EFFECT_LEFTOVERS
          || (aiData->holdEffects[battlerDef] == HOLD_EFFECT_BLACK_SLUDGE && IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON)))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_SOAK:
        if (HasMoveWithType(battlerAtk, TYPE_ELECTRIC) || HasMoveWithType(battlerAtk, TYPE_GRASS)
        || HasMoveWithType(GetPartnerBattler(battlerAtk), TYPE_ELECTRIC) || HasMoveWithType(GetPartnerBattler(battlerAtk), TYPE_GRASS)
        || (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_SUPER_EFFECTIVE_ON_ARG) && GetMoveArgType(move) == TYPE_WATER) )
            ADJUST_SCORE(DECENT_EFFECT); // Get some super effective moves
        break;
    case EFFECT_THIRD_TYPE:
        if (aiData->abilities[battlerDef] == ABILITY_WONDER_GUARD)
            ADJUST_SCORE(DECENT_EFFECT); // Give target more weaknesses
        break;
    case EFFECT_ELECTRIFY:
        if (incomingMove != MOVE_NONE
         && (aiData->abilities[battlerAtk] == ABILITY_VOLT_ABSORB
          || aiData->abilities[battlerAtk] == ABILITY_MOTOR_DRIVE
          || (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) >= GEN_5 && aiData->abilities[battlerAtk] == ABILITY_LIGHTNING_ROD)))
        {
            ADJUST_SCORE(DECENT_EFFECT);
        }
        break;
    case EFFECT_TOPSY_TURVY:
        if (CountPositiveStatStages(battlerDef) > CountNegativeStatStages(battlerDef))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_FAIRY_LOCK:
        if (ShouldTrap(battlerAtk, battlerDef, move, DONT_CONSIDER_WRAP_DAMAGE))
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_QUASH:
        if (hasPartner && AI_IsSlower(GetPartnerBattler(battlerAtk), battlerDef, aiData->partnerMove, predictedMove, CONSIDER_PRIORITY))
            ADJUST_SCORE(DECENT_EFFECT); // Attacker partner wouldn't go before target
        break;
    case EFFECT_TAILWIND:
    {
        if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 1)
            break;

        if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_ELECTRO_BALL))
            ADJUST_SCORE(WEAK_EFFECT);

        if (isBattle1v1)
        {
            if (aiData->speedStats[battlerAtk] * 2 > aiData->speedStats[battlerDef])
                ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, 1));

            if (CountUsablePartyMons(battlerAtk) != 0)
                ADJUST_SCORE(WEAK_EFFECT);

            if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_TAILWIND))
            {
                u32 windAbilityScore = GetWindAbilityScore(battlerAtk, battlerDef, aiData);

                if (windAbilityScore > 0)
                    ADJUST_SCORE(windAbilityScore);
            }
        }
        else
        {
            u32 tailwindScore = 0;
            u32 speed = aiData->speedStats[battlerAtk];
            u32 partnerSpeed = aiData->speedStats[GetPartnerBattler(battlerAtk)];
            u32 foe1Speed = aiData->speedStats[GetBattlerLeftFoe(battlerAtk)];
            u32 foe2Speed = aiData->speedStats[GetBattlerRightFoe(battlerAtk)];

            if (speed <= foe1Speed && (speed * 2) > foe1Speed)
                tailwindScore += 1;
            if (speed <= foe2Speed && (speed * 2) > foe2Speed)
                tailwindScore += 1;
            if (partnerSpeed <= foe1Speed && (partnerSpeed * 2) > foe1Speed)
                tailwindScore += 1;
            if (partnerSpeed <= foe2Speed && (partnerSpeed * 2) > foe2Speed)
                tailwindScore += 1;

            if (tailwindScore > 0)
                tailwindScore += 1;

            ADJUST_SCORE(tailwindScore);

            if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_TAILWIND))
            {
                u32 windAbilityScore = GetWindAbilityScore(battlerAtk, battlerDef, aiData);

                if (IsBattlerAlive(GetPartnerBattler(battlerAtk)))
                    windAbilityScore += GetWindAbilityScore(GetPartnerBattler(battlerAtk), battlerDef, aiData);

                if (windAbilityScore > 0)
                    ADJUST_SCORE(windAbilityScore);
            }
        }
        break;
    }
    case EFFECT_LUCKY_CHANT:
        if (isBattle1v1 && CountUsablePartyMons(battlerDef) > 0)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_MAGNET_RISE:
        if (AI_IsBattlerGrounded(battlerAtk) && HasDamagingMoveOfType(battlerDef, TYPE_GROUND)
          && !(effectiveness == UQ_4_12(0.0))) // Doesn't resist ground move
        {
            if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Attacker goes first
           {
                if (predictedType == TYPE_GROUND)
                    ADJUST_SCORE(GOOD_EFFECT); // Cause the enemy's move to fail
                break;
            }
            else // Opponent Goes First
            {
                ADJUST_SCORE(DECENT_EFFECT);
                break;
            }
        }
        break;
    case EFFECT_CAMOUFLAGE:
        if (incomingMove != MOVE_NONE && AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) // Attacker goes first
         && !IsBattleMoveStatus(move) && effectiveness != UQ_4_12(0.0))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_REFLECT_DAMAGE:
        if ((!IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef]) && incomingMove != MOVE_NONE)
         && (GetNoOfHitsToKOBattler(battlerDef, battlerAtk, predictedMoveSlot, AI_DEFENDING, CONSIDER_ENDURE) >= 2)
         && GetMoveReflectDamage_DamageCategories(move) & (1u << GetBattleMoveCategory(incomingMove))) // Can reflect back damage
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_SHORE_UP:
        if ((AI_GetWeather() & B_WEATHER_SANDSTORM) && ShouldRecover(battlerAtk, battlerDef, move, 67))
            ADJUST_SCORE(DECENT_EFFECT);
        else if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_ENDEAVOR:
        if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY) && !CanTargetFaintAi(battlerDef, battlerAtk))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_REVIVAL_BLESSING:
        if (GetFirstFaintedPartyIndex(battlerAtk) != PARTY_SIZE)
        {
            ADJUST_SCORE(DECENT_EFFECT);
            if (aiData->shouldSwitch & (1u << battlerAtk)) // Bad matchup
                ADJUST_SCORE(WEAK_EFFECT);
            if (aiData->mostSuitableMonId[battlerAtk] != PARTY_SIZE) // Good mon to send in after
                ADJUST_SCORE(WEAK_EFFECT);
        }
        break;
    //case EFFECT_SKY_DROP
        //break;
    case EFFECT_JUNGLE_HEALING:
    {
        bool32 canCureSelf = (gBattleMons[battlerAtk].status1 & STATUS1_ANY) && ShouldCureStatus(battlerAtk, battlerAtk, aiData);
        bool32 canCurePartner = (gBattleMons[GetPartnerBattler(battlerAtk)].status1 & STATUS1_ANY) && ShouldCureStatus(battlerAtk, GetPartnerBattler(battlerAtk), aiData);

        if (ShouldRecover(battlerAtk, battlerDef, move, 25)
         || ShouldRecover(GetPartnerBattler(battlerAtk), battlerDef, move, 25)
         || canCureSelf
         || canCurePartner)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    }
    case EFFECT_RAPID_SPIN:
        if ((AreAnyHazardsOnSide(GetBattlerSide(battlerAtk)) && CountUsablePartyMons(battlerAtk) != 0)
         || (gBattleMons[battlerAtk].volatiles.leechSeed || gBattleMons[battlerAtk].volatiles.wrapped))
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_SMACK_DOWN:
        if (!AI_IsBattlerGrounded(battlerDef) && HasDamagingMoveOfType(battlerAtk, TYPE_GROUND) && !CanTargetFaintAi(battlerDef, battlerAtk))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_KNOCK_OFF:
        if (CanKnockOffItem(battlerDef, battlerAtk, aiData->items[battlerDef]))
        {
            switch (aiData->holdEffects[battlerDef])
            {
            case HOLD_EFFECT_IRON_BALL:
                if (HasMoveWithEffect(battlerDef, EFFECT_FLING))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case HOLD_EFFECT_LAGGING_TAIL:
            case HOLD_EFFECT_STICKY_BARB:
                break;
            default:
                ADJUST_SCORE(DECENT_EFFECT);
                break;
            }
        }
        break;
    case EFFECT_STEAL_ITEM:
        {
            bool32 canSteal = FALSE;

            if (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE)
                canSteal = TRUE;

            if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER || IsOnPlayerSide(battlerAtk))
                canSteal = TRUE;

            if (canSteal && aiData->items[battlerAtk] == ITEM_NONE
             && aiData->items[battlerDef] != ITEM_NONE
             && CanBattlerGetOrLoseItem(battlerDef, battlerAtk, aiData->items[battlerDef])
             && CanBattlerGetOrLoseItem(battlerAtk, battlerDef, aiData->items[battlerDef])
             && !HasMoveWithEffect(battlerAtk, EFFECT_ACROBATICS)
             && aiData->abilities[battlerDef] != ABILITY_STICKY_HOLD)
            {
                switch (aiData->holdEffects[battlerDef])
                {
                case HOLD_EFFECT_NONE:
                    break;
                case HOLD_EFFECT_CHOICE_BAND:
                case HOLD_EFFECT_CHOICE_SCARF:
                case HOLD_EFFECT_CHOICE_SPECS:
                    ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoison(battlerAtk, battlerAtk))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurn(battlerAtk, battlerAtk, aiData->abilities[battlerAtk]))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_IRON_BALL:
                    if (HasMoveWithEffect(battlerAtk, EFFECT_FLING))
                        ADJUST_SCORE(DECENT_EFFECT);
                    break;
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                default:
                    ADJUST_SCORE(WEAK_EFFECT);
                    break;
                }
            }
            break;
        }
        break;
    default:
        break;
    } // move effect checks

    return score;
}

static s32 AI_CalcAdditionalEffectScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    // move data
    s32 score = 0;

    enum Move incomingMove = GetIncomingMove(battlerAtk, battlerDef, aiData);
    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    enum Move defBestMoves[MAX_MON_MOVES] = {MOVE_NONE};

    // Set battlerDef best dmg moves
    GetBestDmgMovesFromBattler(battlerDef, battlerAtk, AI_DEFENDING, defBestMoves);

    if (IsSheerForceAffected(move, aiData->abilities[battlerAtk])
     && !(move == MOVE_ORDER_UP && gBattleStruct->battlerState[battlerAtk].commanderSpecies != SPECIES_NONE))
    {
        return score;
    }

    // check move additional effects that are likely to happen
    for (u32 effectId = 0; effectId < additionalEffectCount; effectId++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectId);

        // Only consider effects with a guaranteed chance to happen
        if (!MoveEffectIsGuaranteed(battlerAtk, aiData->abilities[battlerAtk], additionalEffect))
            continue;

        // Consider move effects that target self
        if (additionalEffect->self)
        {
            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_STAT_PLUS:
            case MOVE_EFFECT_STAT_MINUS:
                for (enum Stat i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    enum Stat stat = sAccurateStatOrder[i];
                    s32 stage = GetStatStage(stat, additionalEffect);

                    if (stage == 0)
                        continue;

                    if (additionalEffect->moveEffect == MOVE_EFFECT_STAT_MINUS)
                        stage = -1 * stage;

                    stage = AI_GetAdjustedStatStage(battlerAtk, move, stage);

                    if (stage < 0)
                        continue;

                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, stat, stage));
                }
                break;
            case MOVE_EFFECT_ORDER_UP:
            {
                enum Stat stat = STAT_ATK;
                bool32 commanderAffected = TRUE;

                switch (gBattleStruct->battlerState[battlerAtk].commanderSpecies)
                {
                case SPECIES_TATSUGIRI_CURLY:
                    stat = STAT_ATK;
                    break;
                case SPECIES_TATSUGIRI_DROOPY:
                    stat = STAT_DEF;
                    break;
                case SPECIES_TATSUGIRI_STRETCHY:
                    stat = STAT_SPEED;
                    break;
                default:
                    commanderAffected = FALSE;
                    break;
                }

                if (commanderAffected)
                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, stat, 1));
                break;
            }
            default:
                break;
            }
        }
        else // consider move effects that hinder the target
        {
            if (IsAdditionalEffectBlocked(battlerAtk, aiData->abilities[battlerAtk], battlerDef, aiData->abilities[battlerDef], move))
                continue;

            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_ABSORB:
                if (ShouldAbsorb(battlerAtk, battlerDef, move, additionalEffect->argument.absorbPercentage))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_STAT_PLUS:
                for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
                {
                    s32 stage = GetStatStage(stat, additionalEffect);

                    if (stage == 0)
                        continue;

                    if (aiData->abilities[battlerDef] == ABILITY_CONTRARY)
                        stage = -1 * stage;

                    if (stage > 0)
                        continue;

                    ADJUST_SCORE(IncreaseStatUpScore(battlerAtk, battlerDef, stat, stage));
                }
                break;
            case MOVE_EFFECT_STAT_MINUS:
                for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
                {
                    s32 stage = -1 * GetStatStage(stat, additionalEffect);

                    if (stage == 0)
                        continue;

                    if (aiData->abilities[battlerDef] == ABILITY_CONTRARY)
                        stage = -1 * stage;

                    if (stage > 0)
                        continue;

                    ADJUST_SCORE(IncreaseStatDownScore(battlerAtk, battlerDef, stat));
                }
                break;
            case MOVE_EFFECT_FLINCH:
                if (ShouldTryToFlinch(battlerAtk, battlerDef, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], move))
                    score += 2;
                break;
            case MOVE_EFFECT_POISON:
                IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
                break;
            case MOVE_EFFECT_CLEAR_SMOG:
            {
                enum MoveTarget target = AI_GetBattlerMoveTargetType(battlerAtk, move);
                bool32 moveTargetsBothOpponents = HasTwoOpponents(battlerAtk)
                                               && (target == TARGET_FIELD || target == TARGET_ALL_BATTLERS || IsSpreadMove(target));

                score += AI_TryToClearStats(battlerAtk, battlerDef, moveTargetsBothOpponents);
                break;
            }
            case MOVE_EFFECT_BUG_BITE:   // And pluck
                if (gBattleMons[battlerDef].volatiles.substitute || aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD)
                    break;
                else if (GetItemPocket(aiData->items[battlerDef]) == POCKET_BERRIES)
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_INCINERATE:
                if (gBattleMons[battlerDef].volatiles.substitute || aiData->abilities[battlerDef] == ABILITY_STICKY_HOLD)
                    break;
                else if (GetItemPocket(aiData->items[battlerDef]) == POCKET_BERRIES || aiData->holdEffects[battlerDef] == HOLD_EFFECT_GEMS)
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_STEALTH_ROCK:
                if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, move, aiData))
                {
                    if (IsBattlersFirstTurn(battlerAtk))
                        ADJUST_SCORE(BEST_EFFECT);
                    else
                        ADJUST_SCORE(DECENT_EFFECT);
                }
                break;
            case MOVE_EFFECT_FEINT:
                if (GetMoveEffect(incomingMove) == EFFECT_PROTECT)
                    ADJUST_SCORE(GOOD_EFFECT);
                break;
            case MOVE_EFFECT_THROAT_CHOP:
                for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
                {
                    if (defBestMoves[moveIndex] == MOVE_NONE)
                    {
                        break;
                    }
                    else
                    {
                        if (IsSoundMove(defBestMoves[moveIndex]))
                        {
                            enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, aiData);

                            if (AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
                            {
                                ADJUST_SCORE(GOOD_EFFECT);
                                break;
                            }
                            else
                            {
                                ADJUST_SCORE(DECENT_EFFECT);
                                break;
                            }
                        }
                    }
                }
                break;
            case MOVE_EFFECT_WRAP:
                if (!HasMoveWithEffect(battlerDef, EFFECT_RAPID_SPIN) && ShouldTrap(battlerAtk, battlerDef, move, CONSIDER_WRAP_DAMAGE))
                    ADJUST_SCORE(BEST_EFFECT);
                break;
            case MOVE_EFFECT_SALT_CURE:
                if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_WATER) || IS_BATTLER_OF_TYPE(battlerDef, TYPE_STEEL))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_SUN:
                if (ShouldSetWeather(battlerAtk, B_WEATHER_SUN))
                    ADJUST_SCORE(DECENT_EFFECT);
                if (ShouldClearWeather(battlerAtk, B_WEATHER_SUN))
                    ADJUST_SCORE(BAD_EFFECT);
                break;
            case MOVE_EFFECT_RAIN:
                if (ShouldSetWeather(battlerAtk, B_WEATHER_RAIN))
                    ADJUST_SCORE(DECENT_EFFECT);
                if (ShouldClearWeather(battlerAtk, B_WEATHER_RAIN))
                    ADJUST_SCORE(BAD_EFFECT);
                break;
            case MOVE_EFFECT_SANDSTORM:
                if (ShouldSetWeather(battlerAtk, B_WEATHER_SANDSTORM))
                    ADJUST_SCORE(DECENT_EFFECT);
                if (ShouldClearWeather(battlerAtk, B_WEATHER_SANDSTORM))
                    ADJUST_SCORE(BAD_EFFECT);
                break;
            case MOVE_EFFECT_HAIL:
                if (ShouldSetWeather(battlerAtk, B_WEATHER_HAIL))
                    ADJUST_SCORE(DECENT_EFFECT);
                if (ShouldClearWeather(battlerAtk, B_WEATHER_HAIL))
                    ADJUST_SCORE(BAD_EFFECT);
                break;
            case MOVE_EFFECT_MISTY_TERRAIN:
                if (ShouldClearTerrain(battlerAtk, B_TERRAIN_MISTY))
                {
                    ADJUST_SCORE(BAD_EFFECT);
                    break;
                }
                if (ShouldSetTerrain(battlerAtk, B_TERRAIN_MISTY)
                 || ShouldClearTerrain(battlerAtk, gFieldTimers.terrain != B_TERRAIN_NONE))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_GRASSY_TERRAIN:
                if (ShouldClearTerrain(battlerAtk, B_TERRAIN_GRASSY))
                {
                    ADJUST_SCORE(BAD_EFFECT);
                    break;
                }
                if (ShouldSetTerrain(battlerAtk, B_TERRAIN_GRASSY)
                 || ShouldClearTerrain(battlerAtk, gFieldTimers.terrain != B_TERRAIN_NONE))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_ELECTRIC_TERRAIN:
                if (ShouldClearTerrain(battlerAtk, B_TERRAIN_ELECTRIC))
                {
                    ADJUST_SCORE(BAD_EFFECT);
                    break;
                }
                if (ShouldSetTerrain(battlerAtk, B_TERRAIN_ELECTRIC)
                 || ShouldClearTerrain(battlerAtk, gFieldTimers.terrain != B_TERRAIN_NONE))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_PSYCHIC_TERRAIN:
                if (ShouldClearTerrain(battlerAtk, B_TERRAIN_PSYCHIC))
                {
                    ADJUST_SCORE(BAD_EFFECT);
                    break;
                }
                if (ShouldSetTerrain(battlerAtk, B_TERRAIN_PSYCHIC)
                 || ShouldClearTerrain(battlerAtk, gFieldTimers.terrain != B_TERRAIN_NONE))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_GRAVITY:
                if (!(gFieldStatuses & STATUS_FIELD_GRAVITY) && ShouldSetFieldStatus(battlerAtk, STATUS_FIELD_GRAVITY))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_AURORA_VEIL:
                if (ShouldSetScreen(battlerAtk, battlerDef, EFFECT_AURORA_VEIL))
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_REMOVE_STATUS:
                if (gBattleMons[battlerDef].status1 & GetMoveEffectArg_Status(move))
                {
                    if (ShouldCureStatus(battlerAtk, battlerDef, aiData))
                        ADJUST_SCORE(DECENT_EFFECT);
                    else if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_FLAME_ORB || aiData->holdEffects[battlerDef] == HOLD_EFFECT_TOXIC_ORB)
                        ADJUST_SCORE(WEAK_EFFECT);
                    else
                        ADJUST_SCORE(BAD_EFFECT);
                }
                break;
            case MOVE_EFFECT_BREAK_SCREEN:
                if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_REFLECT)
                    ADJUST_SCORE(DECENT_EFFECT);
                if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_LIGHTSCREEN)
                    ADJUST_SCORE(DECENT_EFFECT);
                if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_AURORA_VEIL)
                    ADJUST_SCORE(DECENT_EFFECT);
                break;
            case MOVE_EFFECT_STEAL_STATS:
                ADJUST_SCORE(AI_ShouldCopyStatChanges(battlerAtk, battlerDef));
                break;
            default:
                break;
            }
        }
    }
    return score;
}

// AI_FLAG_CHECK_VIABILITY - Chooses best possible move to hit player
static s32 AI_CheckViability(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    struct AiLogicData *aiData = gAiLogicData;

    // Targeting partner, check benefits of doing that instead
    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;

    if (GetMovePower(move) != 0)
    {
        if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) == 0)
            ADJUST_AND_RETURN_SCORE(NO_DAMAGE_OR_FAILS); // No point in checking the move further so return early
        else
        {
            if (gAiThinkingStruct->aiFlags[battlerAtk] & (AI_FLAG_RISKY | AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE)
                && IsBestDmgMove(battlerAtk, battlerDef, AI_ATTACKING, move))
                ADJUST_SCORE(BEST_DAMAGE_MOVE);
        }
    }

    if (IsDoubleBattle()
     && AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_SELECTED
     && !IsBattleMoveStatus(move)
     && gBattleMons[battlerAtk].volatiles.battlerWithSureHit == battlerDef + 1)
        ADJUST_SCORE(WEAK_EFFECT);

    ADJUST_SCORE(AI_CalcMoveEffectScore(battlerAtk, battlerDef, move, aiData));
    ADJUST_SCORE(AI_CalcAdditionalEffectScore(battlerAtk, battlerDef, move, aiData));
    ADJUST_SCORE(AI_CalcHoldEffectMoveScore(battlerAtk, battlerDef, move, aiData));

    return score;
}

// Effects that are encouraged on the first turn of battle
static s32 AI_ForceSetupFirstTurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (IsTargetingPartner(battlerAtk, battlerDef)
      || gBattleResults.battleTurnCounter != 0)
        return score;

    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);

    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_SMART_SWITCHING
      && AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)
      && CanTargetFaintAi(battlerDef, battlerAtk)
      && GetBattleMovePriority(battlerAtk, gAiLogicData->abilities[battlerAtk], move) == 0)
    {
        RETURN_SCORE_MINUS(20);    // No point in setting up if you will faint. Should just switch if possible..
    }

    // check effects to prioritize first turn
    switch (GetMoveEffect(move))
    {
    case EFFECT_CONVERSION:
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_FOCUS_ENERGY:
    case EFFECT_CONFUSE:
    case EFFECT_REFLECT:
    case EFFECT_NON_VOLATILE_STATUS:
    case EFFECT_SUBSTITUTE:
    case EFFECT_LEECH_SEED:
    case EFFECT_CURSE:
    case EFFECT_SWAGGER:
    case EFFECT_CAMOUFLAGE:
    case EFFECT_YAWN:
    case EFFECT_TORMENT:
    case EFFECT_INGRAIN:
    case EFFECT_IMPRISON:
    case EFFECT_ACUPRESSURE:
    case EFFECT_TERRAIN:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_TOXIC_SPIKES:
    case EFFECT_TRICK_ROOM:
    case EFFECT_WONDER_ROOM:
    case EFFECT_MAGIC_ROOM:
    case EFFECT_TAILWIND:
    case EFFECT_TIDY_UP:
    case EFFECT_STICKY_WEB:
    case EFFECT_WEATHER:
    case EFFECT_WEATHER_AND_SWITCH:
    case EFFECT_CEASELESS_EDGE:
    case EFFECT_STONE_AXE:
        ADJUST_SCORE(DECENT_EFFECT);
        break;
    default:
        break;
    }

    return score;
}

// Adds score bonus to 'riskier' move effects and high crit moves
static s32 AI_Risky(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    struct AiLogicData *aiData = gAiLogicData;

    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;

    if (GetMoveCriticalHitStage(move) > 0)
        ADJUST_SCORE(DECENT_EFFECT);

    if (IsExplosionMove(move))
    {
        ADJUST_SCORE(STRONG_RISKY_EFFECT);
        return score;
    }

    // +3 Score
    switch (GetMoveEffect(move))
    {
    case EFFECT_REFLECT_DAMAGE:
        if (GetMoveReflectDamage_DamageCategories(move) & (1u << DAMAGE_CATEGORY_PHYSICAL) // Can reflect physical damage
         && GetSpeciesBaseAttack(gBattleMons[battlerDef].species) >= GetSpeciesBaseSpAttack(gBattleMons[battlerDef].species) + 10)
            ADJUST_SCORE(STRONG_RISKY_EFFECT);
        else if (GetMoveReflectDamage_DamageCategories(move) & (1u << DAMAGE_CATEGORY_SPECIAL) // Can reflect special damage
              && GetSpeciesBaseSpAttack(gBattleMons[battlerDef].species) >= GetSpeciesBaseAttack(gBattleMons[battlerDef].species) + 10)
            ADJUST_SCORE(STRONG_RISKY_EFFECT);
        break;

    // +2 Score
    case EFFECT_MEMENTO:
        if (aiData->hpPercents[battlerAtk] < 50 && AI_RandLessThan(128))
            ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_REVENGE:
        if (GetSpeciesBaseSpeed(gBattleMons[battlerDef].species) >= GetSpeciesBaseSpeed(gBattleMons[battlerAtk].species) + 10)
            ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_STAT_CHANGE_HALF_HP:
    case EFFECT_BELLY_DRUM:
        if (aiData->hpPercents[battlerAtk] >= 90)
            ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (aiData->hpPercents[battlerAtk] >= 70)
            ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_MAX_HP_50_RECOIL:
    case EFFECT_CHLOROBLAST:
    case EFFECT_SWAGGER:
    case EFFECT_ATTRACT:
    case EFFECT_OHKO:
        ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
        break;
    case EFFECT_HIT:
    {
        // TEMPORARY - should applied to all moves regardless of EFFECT
        // Consider move effects
        u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
        for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_STAT_PLUS:
                if (Random() & 1)
                    ADJUST_SCORE(AVERAGE_RISKY_EFFECT);
                break;
            default:
                break;
            }
        }
    }
    default:
        break;
    }

    return score;
}

// Adds score bonus to OHKOs and 2HKOs
static s32 AI_TryTo2HKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;

    if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) == 1)
        ADJUST_SCORE(BEST_EFFECT);
    else if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) == 2)
        ADJUST_SCORE(DECENT_EFFECT);

    return score;
}

// Adds score bonus to targeting "partner"
static s32 AI_AttacksPartner(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (battlerDef == GetPartnerBattler(battlerAtk)
       // natural enemies in wild battles try to kill each other
       && ((IsNaturalEnemy(gBattleMons[battlerAtk].species, gBattleMons[battlerDef].species) && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER)))
       || AI_FLAG_ATTACKS_PARTNER_FOCUSES_PARTNER))
    {
        u32 movesetIndex = gAiThinkingStruct->movesetIndex;

        if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, movesetIndex, AI_ATTACKING))
            ADJUST_SCORE(BEST_EFFECT);

        u32 hitsToKO = GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE);

        if (AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_FOES_AND_ALLY && hitsToKO > 0 &&
           (GetNoOfHitsToKOBattler(battlerAtk, GetBattlerLeftFoe(battlerAtk), gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) > 0 || GetNoOfHitsToKOBattler(battlerAtk, GetBattlerLeftFoe(battlerDef), gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) > 0))
            ADJUST_SCORE(BEST_EFFECT);

        if (hitsToKO > 0)
            ADJUST_SCORE(DECENT_EFFECT);
    }
    return score;
}

// Prefers moves that are good for baton pass
static s32 AI_PreferBatonPass(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (IsTargetingPartner(battlerAtk, battlerDef)
      || CountUsablePartyMons(battlerAtk) == 0
      || !IsBattleMoveStatus(move)
      || !HasMoveWithEffect(battlerAtk, EFFECT_BATON_PASS)
      || IsBattlerTrapped(battlerAtk, battlerDef))
        return score;

    enum BattleMoveEffects effect = GetMoveEffect(move);

    if (IsStatRaisingMove(move))
    {
        if (gBattleResults.battleTurnCounter == 0)
            ADJUST_SCORE(GOOD_EFFECT);
        else if (gAiLogicData->hpPercents[battlerAtk] < 60)
            ADJUST_SCORE(-10);
        else
            ADJUST_SCORE(WEAK_EFFECT);
    }

    // other specific checks
    switch (effect)
    {
    case EFFECT_INGRAIN:
        if (!gBattleMons[battlerAtk].volatiles.root)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_AQUA_RING:
        if (!gBattleMons[battlerAtk].volatiles.aquaRing)
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_PROTECT:
        if (GetProtectType(GetMoveProtectMethod(gAiLogicData->lastUsedMove[battlerAtk])) == PROTECT_TYPE_SINGLE)
            ADJUST_SCORE(-2);
        else
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_BATON_PASS:
        if (gBattleMons[battlerAtk].volatiles.root || gBattleMons[battlerAtk].volatiles.aquaRing)
            ADJUST_SCORE(DECENT_EFFECT);
        if (gBattleMons[battlerAtk].volatiles.leechSeed)
            ADJUST_SCORE(-3);
        ADJUST_SCORE(CountPositiveStatStages(battlerAtk) - CountNegativeStatStages(battlerAtk));
        break;
    default:
        break;
    }

    return score;
}

static s32 AI_HPAware(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    enum Type moveType = 0;

    SetTypeBeforeUsingMove(move, battlerAtk, gAiLogicData->abilities[battlerAtk], gAiLogicData->holdEffects[battlerAtk]);
    moveType = GetBattleMoveType(move);

    if (IsTargetingPartner(battlerAtk, battlerDef))
    {
        if ((effect == EFFECT_HEAL_PULSE || effect == EFFECT_HIT_ENEMY_HEAL_ALLY)
         || (moveType == TYPE_ELECTRIC && gAiLogicData->abilities[GetPartnerBattler(battlerAtk)] == ABILITY_VOLT_ABSORB)
         || (moveType == TYPE_GROUND && gAiLogicData->abilities[GetPartnerBattler(battlerAtk)] == ABILITY_EARTH_EATER)
         || (moveType == TYPE_WATER && (gAiLogicData->abilities[GetPartnerBattler(battlerAtk)] == ABILITY_DRY_SKIN || gAiLogicData->abilities[GetPartnerBattler(battlerAtk)] == ABILITY_WATER_ABSORB)))
        {
            if (gBattleMons[battlerDef].volatiles.healBlockTimer)
                return 0;

            if (CanTargetFaintAi(GetBattlerLeftFoe(battlerAtk), GetPartnerBattler(battlerAtk))
             || CanTargetFaintAi(GetBattlerRightFoe(battlerAtk), GetPartnerBattler(battlerAtk)))
                ADJUST_SCORE(-1);

            if (gAiLogicData->hpPercents[battlerDef] <= 50)
                ADJUST_SCORE(WEAK_EFFECT);
        }
    }
    else
    {
        // Consider AI HP
        if (IsExplosionMove(move) && gAiLogicData->hpPercents[battlerAtk] > 70)
        {
            ADJUST_SCORE(-2);
        }
        else if (gAiLogicData->hpPercents[battlerAtk] > 70)
        {
            // high hp
            switch (effect)
            {
            case EFFECT_RESTORE_HP:
            case EFFECT_REST:
            case EFFECT_DESTINY_BOND:
            case EFFECT_FLAIL:
            case EFFECT_ENDURE:
            case EFFECT_MORNING_SUN:
            case EFFECT_SYNTHESIS:
            case EFFECT_MOONLIGHT:
            case EFFECT_SHORE_UP:
            case EFFECT_SOFTBOILED:
            case EFFECT_ROOST:
            case EFFECT_MEMENTO:
            case EFFECT_GRUDGE:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else if (gAiLogicData->hpPercents[battlerAtk] > 30)
        {
            // med hp
            if (IsStatRaisingMove(move)
             || IsStatLoweringMove(move)
             || IsExplosionMove(move))
                ADJUST_SCORE(-2);

            switch (effect)
            {
            case EFFECT_BIDE:
            case EFFECT_CONVERSION:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_REFLECT:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_CONVERSION_2:
            case EFFECT_SAFEGUARD:
            case EFFECT_STAT_CHANGE_HALF_HP:
            case EFFECT_BELLY_DRUM:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else
        {
            // low hp
            if (IsStatRaisingMove(move) || IsStatLoweringMove(move))
                ADJUST_SCORE(-2);

            // check other discouraged low hp effects
            switch (effect)
            {
            case EFFECT_BIDE:
            case EFFECT_CONVERSION:
            case EFFECT_REFLECT:
            case EFFECT_LIGHT_SCREEN:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_CONVERSION_2:
            case EFFECT_LOCK_ON:
            case EFFECT_SAFEGUARD:
            case EFFECT_STAT_CHANGE_HALF_HP:
            case EFFECT_BELLY_DRUM:
            case EFFECT_PSYCH_UP:
            case EFFECT_REFLECT_DAMAGE:
            case EFFECT_WEATHER:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
    }

    // consider target HP
    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING))
    {
        ADJUST_SCORE(DECENT_EFFECT);
    }
    else
    {
        if (gAiLogicData->hpPercents[battlerDef] > 70)
        {
            // high HP
            ; // nothing yet
        }
        else if (gAiLogicData->hpPercents[battlerDef] > 30)
        {
            // med HP - check discouraged effects
            switch (effect)
            {
            case EFFECT_STAT_CHANGE:
            case EFFECT_MIST:
            case EFFECT_FOCUS_ENERGY:
            case EFFECT_PAIN_SPLIT:
            case EFFECT_PERISH_SONG:
            case EFFECT_SAFEGUARD:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }

            switch (GetMoveNonVolatileStatus(move))
            {
            case MOVE_EFFECT_POISON:
                ADJUST_SCORE(-2);
                break;
            default:
                break;
            }
        }
        else
        {
            // low HP
            if (IsBattleMoveStatus(move))
                ADJUST_SCORE(-2); // don't use status moves if target is at low health
        }
    }

    return score;
}

static s32 AI_PowerfulStatus(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);

    if (GetMoveCategory(move) != DAMAGE_CATEGORY_STATUS || GetMoveEffect(gAiLogicData->partnerMove) == moveEffect)
        return score;

    switch (moveEffect)
    {
    case EFFECT_TAILWIND:
        if (!gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer && !(gFieldStatuses & STATUS_FIELD_TRICK_ROOM))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_TRICK_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && !HasMoveWithEffect(battlerDef, EFFECT_TRICK_ROOM))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_MAGIC_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM) && !HasMoveWithEffect(battlerDef, EFFECT_MAGIC_ROOM))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_WONDER_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_WONDER_ROOM) && !HasMoveWithEffect(battlerDef, EFFECT_WONDER_ROOM))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_SAFEGUARD:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_MIST:
        if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_AURORA_VEIL:
        if (ShouldSetScreen(battlerAtk, battlerDef, moveEffect))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_TOXIC_SPIKES:
        if (AI_ShouldSetUpHazards(battlerAtk, battlerDef, move, gAiLogicData))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_TERRAIN:
        if (gFieldTimers.terrain != GetMoveTerrainType(move))
            ADJUST_SCORE(POWERFUL_STATUS_MOVE);
        break;
    case EFFECT_WEATHER:
        switch (GetMoveWeatherType(move))
        {
        case BATTLE_WEATHER_RAIN:
            if (IsWeatherActive(B_WEATHER_RAIN | B_WEATHER_PRIMAL_ANY) == WEATHER_INACTIVE)
                ADJUST_SCORE(POWERFUL_STATUS_MOVE);
            break;
        case BATTLE_WEATHER_SUN:
            if (IsWeatherActive(B_WEATHER_SUN | B_WEATHER_PRIMAL_ANY) == WEATHER_INACTIVE)
                ADJUST_SCORE(POWERFUL_STATUS_MOVE);
            break;
        case BATTLE_WEATHER_SANDSTORM:
            if (IsWeatherActive(B_WEATHER_SANDSTORM | B_WEATHER_PRIMAL_ANY) == WEATHER_INACTIVE)
                ADJUST_SCORE(POWERFUL_STATUS_MOVE);
            break;
        case BATTLE_WEATHER_HAIL:
        case BATTLE_WEATHER_SNOW:
            if (IsWeatherActive(B_WEATHER_ICY_ANY | B_WEATHER_PRIMAL_ANY) == WEATHER_INACTIVE)
                ADJUST_SCORE(POWERFUL_STATUS_MOVE);
            break;
        default:
            break;
        }
    default:
        break;
    }

    return score;
}

bool32 DoesSideHaveDamagingHazards(enum BattleSide side)
{
    for (enum Hazards counter = 0; counter < HAZARDS_MAX_COUNT; counter++)
    {
        switch (gBattleStruct->hazardsQueue[side][counter])
        {
        case HAZARDS_SPIKES:
        case HAZARDS_TOXIC_SPIKES:
        case HAZARDS_STEALTH_ROCK:
        case HAZARDS_STEELSURGE:
            return TRUE;
        default:
            break;
        }
    }
    return FALSE;
}

static s32 AI_PredictSwitch(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    u32 unmodifiedScore = score;
    enum Ability ability = gBattleMons[battlerAtk].ability;
    bool32 opposingHazardFlags = DoesSideHaveDamagingHazards(GetBattlerSide(battlerDef));
    bool32 aiHazardFlags = AreAnyHazardsOnSide(GetBattlerSide(battlerAtk));
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    struct AiLogicData *aiData = gAiLogicData;
    uq4_12_t effectiveness = aiData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex];
    enum Move incomingMove = GetIncomingMove(battlerAtk, battlerDef, gAiLogicData);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);

    // Switch benefit
    switch (moveEffect)
    {
    case EFFECT_PURSUIT:
    {
        u32 hitsToKO = GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE);
        if (hitsToKO == 2)
            ADJUST_SCORE(GOOD_EFFECT);
        else if (hitsToKO == 1)
            ADJUST_SCORE(BEST_EFFECT);
        else if (IsSwitchOutEffect(GetMoveEffect(incomingMove)) && AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) // Pursuit against fast U-Turn
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    }

    case EFFECT_FOCUS_PUNCH:
        ADJUST_SCORE(DECENT_EFFECT);
        if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CHECK_BAD_MOVE)
        {
            if (aiData->abilities[battlerDef] == ABILITY_WONDER_GUARD && effectiveness < UQ_4_12(2.0))
                ADJUST_SCORE(10);
            if (HasDamagingMove(battlerDef) && !(gBattleMons[battlerAtk].volatiles.substitute
             || IsBattlerIncapacitated(battlerDef, aiData->abilities[battlerDef])
             || gBattleMons[battlerDef].volatiles.infatuation
             || gBattleMons[battlerDef].volatiles.confusionTimer > 0))
                ADJUST_SCORE(10);
        }
        break;

    case EFFECT_TELEPORT:
    case EFFECT_HIT_ESCAPE:
    case EFFECT_PARTING_SHOT:
    case EFFECT_WEATHER_AND_SWITCH:
    case EFFECT_BOLT_BEAK:
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_MAGNET_RISE:
    case EFFECT_TRICK_ROOM:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_SPIKES:
    case EFFECT_TOXIC_SPIKES:
        ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_FUTURE_SIGHT:
    case EFFECT_TELEKINESIS:
    case EFFECT_GRAVITY:
    case EFFECT_WEATHER:
    case EFFECT_AQUA_RING:
    case EFFECT_TERRAIN:
        ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_HIT_SWITCH_TARGET:
        if (opposingHazardFlags)
            ADJUST_SCORE(BEST_EFFECT);
        else
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_ROAR:
        if (opposingHazardFlags)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_RAPID_SPIN:
        if (aiHazardFlags)
            ADJUST_SCORE(BEST_EFFECT);
        break;
    case EFFECT_DEFOG:
        if (aiHazardFlags)
            ADJUST_SCORE(GOOD_EFFECT);
        break;
    case EFFECT_WISH:
    case EFFECT_HEAL_BELL:
        if (ShouldUseWishAromatherapy(battlerAtk, battlerDef, move))
            ADJUST_SCORE(DECENT_EFFECT);
        break;
    case EFFECT_RESTORE_HP:
        if (gAiLogicData->hpPercents[battlerAtk] < 60)
            ADJUST_SCORE(GOOD_EFFECT);
        break;

    // Fails if opponent switches
    case EFFECT_PROTECT:
    case EFFECT_REFLECT_DAMAGE:
    case EFFECT_SHELL_TRAP:
    case EFFECT_SUCKER_PUNCH:
    case EFFECT_UPPER_HAND:
    case EFFECT_ENCORE:
    case EFFECT_FOLLOW_ME:
    case EFFECT_ME_FIRST:
    case EFFECT_DISABLE:
    case EFFECT_ELECTRIFY:
    case EFFECT_ENDURE:
    case EFFECT_HAZE:
    case EFFECT_TOPSY_TURVY:
    case EFFECT_ION_DELUGE:
    case EFFECT_MAGIC_COAT:
    case EFFECT_SNATCH:
        ADJUST_SCORE(WORST_EFFECT);
        break;

    // Get stuck in bad matchup
    case EFFECT_IMPRISON:
    case EFFECT_EMBARGO:
    case EFFECT_TAUNT:
    case EFFECT_INGRAIN:
    case EFFECT_NO_RETREAT:
    case EFFECT_MEAN_LOOK:
        ADJUST_SCORE(AWFUL_EFFECT);
        break;

    default:
        break;
    }

    // Additional effects
    for (u32 effectIndex = 0; effectIndex < GetMoveAdditionalEffectCount(move); effectIndex++)
    {
        switch (GetMoveAdditionalEffectById(move, effectIndex)->moveEffect)
        {
        case MOVE_EFFECT_WRAP:
            ADJUST_SCORE(AWFUL_EFFECT);
            break;
        case MOVE_EFFECT_FEINT:
            ADJUST_SCORE(WORST_EFFECT);
            break;
        default:
            break;
        }
    }

    // Take advantage of ability damage bonus
    if ((ability == ABILITY_STAKEOUT || ability == ABILITY_ANALYTIC) && IsBattleMoveStatus(move))
        ADJUST_SCORE(BAD_EFFECT);

    // This must be last or the player can gauge whether the AI is predicting based on how long it thinks
    if (!IsBattlerPredictedToSwitch(battlerDef))
        return unmodifiedScore;
    return score;
}

static s32 AI_CheckPpStall(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (!IsOnPlayerSide(battlerAtk))
        score -= PpStallReduction(move, battlerAtk, battlerDef);
    return score;
}

static void AI_Flee(void)
{
    gAiThinkingStruct->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void AI_Watch(void)
{
    gAiThinkingStruct->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

// Roaming Pokémon logic
static s32 AI_Roaming(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    bool32 roamerCanFlee = FALSE;

    if (AI_CanBattlerEscape(battlerAtk))
        roamerCanFlee = TRUE;
    else if (gAiLogicData->abilities[battlerAtk] == ABILITY_RUN_AWAY)
        roamerCanFlee = TRUE;
    else if (gAiLogicData->holdEffects[battlerAtk] == HOLD_EFFECT_CAN_ALWAYS_RUN)
        roamerCanFlee = TRUE;

    if (!roamerCanFlee && IsBattlerTrapped(battlerDef, battlerAtk))
        return score;

    AI_Flee();
    return score;
}

// Safari Pokémon logic
static s32 AI_Safari(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    u32 safariFleeRate = gBattleStruct->safariEscapeFactor * 5; // Safari flee rate, from 0-20.

    if ((Random() % 100) < safariFleeRate)
        AI_Flee();
    else
        AI_Watch();

    return score;
}

// First battle logic
static s32 AI_FirstBattle(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (!IS_FRLG && gAiLogicData->hpPercents[battlerDef] <= 20)
        AI_Flee();

    return score;
}

// Dynamic AI Functions
// For specific battle scenarios

// Example - prefer attacking opposite foe in a tag battle
s32 AI_TagBattlePreferFoe(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
    {
        /* not a partner battle */
        return score;
    }
    else if (!IsBattlerAlive(GetOppositeBattler(battlerAtk)) || !IsBattlerAlive(GetPartnerBattler(GetOppositeBattler(battlerAtk))))
    {
        /* partner is defeated so attack normally */
        return score;
    }
    else if (battlerDef == GetOppositeBattler(battlerAtk))
    {
        /* attacking along the diagonal */
        ADJUST_SCORE(-20);
    }

    return score;
}

static s32 AI_DynamicFunc(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 score)
{
    if (sDynamicAiFunc != NULL)
        score = sDynamicAiFunc(battlerAtk, battlerDef, move, score);
    return score;
}

void ScriptSetDynamicAiFunc(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);

    AiScoreFunc func = (AiScoreFunc)ScriptReadWord(ctx);
    sDynamicAiFunc = func;
}

void ScriptSetDynamicAiSwitchFunc(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);

    AiSwitchFunc func = (AiSwitchFunc)ScriptReadWord(ctx);
    gDynamicAiSwitchFunc = func;
}

void ResetDynamicAiFunctions(void)
{
    sDynamicAiFunc = NULL;
    gDynamicAiSwitchFunc = NULL;
}
