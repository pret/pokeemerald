#include "global.h"
#include "battle_ai_script_commands.h"
#include "pokemon.h"
#include "battle.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "random.h"
#include "item.h"
#include "constants/battle_move_effects.h"
#include "constants/moves.h"
#include "util.h"
#include "constants/battle_ai.h"

#define AIScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define AIScriptRead16(ptr) ((ptr)[0] | (ptr)[1] << 8)
#define AIScriptReadPtr(ptr) (const u8*) AIScriptRead32(ptr)

#define AI_ACTION_DONE          0x0001
#define AI_ACTION_FLEE          0x0002
#define AI_ACTION_WATCH         0x0004
#define AI_ACTION_DO_NOT_ATTACK 0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

#define AI_THINKING_STRUCT ((struct AI_ThinkingStruct *)(gBattleResources->ai))
#define BATTLE_HISTORY ((struct BattleHistory *)(gBattleResources->battleHistory))

// AI states
enum
{
    AIState_SettingUp,
    AIState_Processing,
    AIState_FinishedProcessing,
    AIState_DoNotProcess
};

/*
gAIScriptPtr is a pointer to the next battle AI cmd command to read.
when a command finishes processing, gAIScriptPtr is incremented by
the number of bytes that the current command had reserved for arguments
in order to read the next command correctly. refer to battle_ai_scripts.s for the
AI scripts.
*/

extern u32 gBattleTypeFlags;
extern u8 gActiveBattler;
extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];
extern u16 gCurrentMove;
extern u8 gBattleMoveTarget;
extern u8 gAbsentBattlerFlags;
extern u16 gLastMoves[MAX_BATTLERS_COUNT];
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u32 gStatuses3[MAX_BATTLERS_COUNT];
extern u16 gSideStatuses[2];
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern u16 gDynamicBasePower;
extern u8 gMoveResultFlags;
extern s32 gBattleMoveDamage;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];
extern const u8 * const gBattleAI_ScriptsTable[];

extern u32 GetAiScriptsInRecordedBattle();
extern u32 GetAiScriptsInBattleFactory();

static u8 BattleAI_ChooseMoveOrAction_Singles(void);
static u8 BattleAI_ChooseMoveOrAction_Doubles(void);
static void RecordLastUsedMoveByTarget(void);
static void BattleAI_DoAIProcessing(void);
static void AIStackPushVar(const u8 *);
static bool8 AIStackPop(void);

static void BattleAICmd_if_random_less_than(void);
static void BattleAICmd_if_random_greater_than(void);
static void BattleAICmd_if_random_equal(void);
static void BattleAICmd_if_random_not_equal(void);
static void BattleAICmd_score(void);
static void BattleAICmd_if_hp_less_than(void);
static void BattleAICmd_if_hp_more_than(void);
static void BattleAICmd_if_hp_equal(void);
static void BattleAICmd_if_hp_not_equal(void);
static void BattleAICmd_if_status(void);
static void BattleAICmd_if_not_status(void);
static void BattleAICmd_if_status2(void);
static void BattleAICmd_if_not_status2(void);
static void BattleAICmd_if_status3(void);
static void BattleAICmd_if_not_status3(void);
static void BattleAICmd_if_side_affecting(void);
static void BattleAICmd_if_not_side_affecting(void);
static void BattleAICmd_if_less_than(void);
static void BattleAICmd_if_more_than(void);
static void BattleAICmd_if_equal(void);
static void BattleAICmd_if_not_equal(void);
static void BattleAICmd_if_less_than_ptr(void);
static void BattleAICmd_if_more_than_ptr(void);
static void BattleAICmd_if_equal_ptr(void);
static void BattleAICmd_if_not_equal_ptr(void);
static void BattleAICmd_if_move(void);
static void BattleAICmd_if_not_move(void);
static void BattleAICmd_if_in_bytes(void);
static void BattleAICmd_if_not_in_bytes(void);
static void BattleAICmd_if_in_hwords(void);
static void BattleAICmd_if_not_in_hwords(void);
static void BattleAICmd_if_user_has_attacking_move(void);
static void BattleAICmd_if_user_has_no_attacking_moves(void);
static void BattleAICmd_get_turn_count(void);
static void BattleAICmd_get_type(void);
static void BattleAICmd_get_considered_move_power(void);
static void BattleAICmd_get_how_powerful_move_is(void);
static void BattleAICmd_get_last_used_bank_move(void);
static void BattleAICmd_if_equal_(void);
static void BattleAICmd_if_not_equal_(void);
static void BattleAICmd_if_user_goes(void);
static void BattleAICmd_if_user_doesnt_go(void);
static void BattleAICmd_nullsub_2A(void);
static void BattleAICmd_nullsub_2B(void);
static void BattleAICmd_count_usable_party_mons(void);
static void BattleAICmd_get_considered_move(void);
static void BattleAICmd_get_considered_move_effect(void);
static void BattleAICmd_get_ability(void);
static void BattleAICmd_get_highest_type_effectiveness(void);
static void BattleAICmd_if_type_effectiveness(void);
static void BattleAICmd_nullsub_32(void);
static void BattleAICmd_nullsub_33(void);
static void BattleAICmd_if_status_in_party(void);
static void BattleAICmd_if_status_not_in_party(void);
static void BattleAICmd_get_weather(void);
static void BattleAICmd_if_effect(void);
static void BattleAICmd_if_not_effect(void);
static void BattleAICmd_if_stat_level_less_than(void);
static void BattleAICmd_if_stat_level_more_than(void);
static void BattleAICmd_if_stat_level_equal(void);
static void BattleAICmd_if_stat_level_not_equal(void);
static void BattleAICmd_if_can_faint(void);
static void BattleAICmd_if_cant_faint(void);
static void BattleAICmd_if_has_move(void);
static void BattleAICmd_if_doesnt_have_move(void);
static void BattleAICmd_if_has_move_with_effect(void);
static void BattleAICmd_if_doesnt_have_move_with_effect(void);
static void BattleAICmd_if_any_move_disabled_or_encored(void);
static void BattleAICmd_if_curr_move_disabled_or_encored(void);
static void BattleAICmd_flee(void);
static void BattleAICmd_if_random_safari_flee(void);
static void BattleAICmd_watch(void);
static void BattleAICmd_get_hold_effect(void);
static void BattleAICmd_get_gender(void);
static void BattleAICmd_is_first_turn_for(void);
static void BattleAICmd_get_stockpile_count(void);
static void BattleAICmd_is_double_battle(void);
static void BattleAICmd_get_used_held_item(void);
static void BattleAICmd_get_move_type_from_result(void);
static void BattleAICmd_get_move_power_from_result(void);
static void BattleAICmd_get_move_effect_from_result(void);
static void BattleAICmd_get_protect_count(void);
static void BattleAICmd_nullsub_52(void);
static void BattleAICmd_nullsub_53(void);
static void BattleAICmd_nullsub_54(void);
static void BattleAICmd_nullsub_55(void);
static void BattleAICmd_nullsub_56(void);
static void BattleAICmd_nullsub_57(void);
static void BattleAICmd_call(void);
static void BattleAICmd_goto(void);
static void BattleAICmd_end(void);
static void BattleAICmd_if_level_cond(void);
static void BattleAICmd_if_target_taunted(void);
static void BattleAICmd_if_target_not_taunted(void);
static void BattleAICmd_check_ability(void);
static void BattleAICmd_is_of_type(void);
static void BattleAICmd_if_target_is_ally(void);
static void BattleAICmd_if_flash_fired(void);
static void BattleAICmd_if_holds_item(void);

// ewram

EWRAM_DATA const u8 *gAIScriptPtr = NULL;
EWRAM_DATA static u8 sBank_AI = 0;

// const rom data

typedef void (*BattleAICmdFunc)(void);

static const BattleAICmdFunc sBattleAICmdTable[] =
{
    BattleAICmd_if_random_less_than,         // 0x0
    BattleAICmd_if_random_greater_than,      // 0x1
    BattleAICmd_if_random_equal,             // 0x2
    BattleAICmd_if_random_not_equal,         // 0x3
    BattleAICmd_score,                       // 0x4
    BattleAICmd_if_hp_less_than,             // 0x5
    BattleAICmd_if_hp_more_than,             // 0x6
    BattleAICmd_if_hp_equal,                 // 0x7
    BattleAICmd_if_hp_not_equal,             // 0x8
    BattleAICmd_if_status,                   // 0x9
    BattleAICmd_if_not_status,               // 0xA
    BattleAICmd_if_status2,                  // 0xB
    BattleAICmd_if_not_status2,              // 0xC
    BattleAICmd_if_status3,                  // 0xD
    BattleAICmd_if_not_status3,              // 0xE
    BattleAICmd_if_side_affecting,           // 0xF
    BattleAICmd_if_not_side_affecting,       // 0x10
    BattleAICmd_if_less_than,                // 0x11
    BattleAICmd_if_more_than,                // 0x12
    BattleAICmd_if_equal,                    // 0x13
    BattleAICmd_if_not_equal,                // 0x14
    BattleAICmd_if_less_than_ptr,             // 0x15
    BattleAICmd_if_more_than_ptr,             // 0x16
    BattleAICmd_if_equal_ptr,                 // 0x17
    BattleAICmd_if_not_equal_ptr,             // 0x18
    BattleAICmd_if_move,                     // 0x19
    BattleAICmd_if_not_move,                 // 0x1A
    BattleAICmd_if_in_bytes,                 // 0x1B
    BattleAICmd_if_not_in_bytes,             // 0x1C
    BattleAICmd_if_in_hwords,                 // 0x1D
    BattleAICmd_if_not_in_hwords,             // 0x1E
    BattleAICmd_if_user_has_attacking_move,          // 0x1F
    BattleAICmd_if_user_has_no_attacking_moves,         // 0x20
    BattleAICmd_get_turn_count,              // 0x21
    BattleAICmd_get_type,                    // 0x22
    BattleAICmd_get_considered_move_power,              // 0x23
    BattleAICmd_get_how_powerful_move_is,       // 0x24
    BattleAICmd_get_last_used_bank_move,                    // 0x25
    BattleAICmd_if_equal_,                // 0x26
    BattleAICmd_if_not_equal_,            // 0x27
    BattleAICmd_if_user_goes,           // 0x28
    BattleAICmd_if_user_doesnt_go,       // 0x29
    BattleAICmd_nullsub_2A,                  // 0x2A
    BattleAICmd_nullsub_2B,                  // 0x2B
    BattleAICmd_count_usable_party_mons,         // 0x2C
    BattleAICmd_get_considered_move,         // 0x2D
    BattleAICmd_get_considered_move_effect,  // 0x2E
    BattleAICmd_get_ability,                 // 0x2F
    BattleAICmd_get_highest_type_effectiveness, // 0x30
    BattleAICmd_if_type_effectiveness,             // 0x31
    BattleAICmd_nullsub_32,                  // 0x32
    BattleAICmd_nullsub_33,                  // 0x33
    BattleAICmd_if_status_in_party,          // 0x34
    BattleAICmd_if_status_not_in_party,      // 0x35
    BattleAICmd_get_weather,                 // 0x36
    BattleAICmd_if_effect,                   // 0x37
    BattleAICmd_if_not_effect,               // 0x38
    BattleAICmd_if_stat_level_less_than,     // 0x39
    BattleAICmd_if_stat_level_more_than,     // 0x3A
    BattleAICmd_if_stat_level_equal,         // 0x3B
    BattleAICmd_if_stat_level_not_equal,     // 0x3C
    BattleAICmd_if_can_faint,                // 0x3D
    BattleAICmd_if_cant_faint,               // 0x3E
    BattleAICmd_if_has_move,                 // 0x3F
    BattleAICmd_if_doesnt_have_move,           // 0x40
    BattleAICmd_if_has_move_with_effect,              // 0x41
    BattleAICmd_if_doesnt_have_move_with_effect,          // 0x42
    BattleAICmd_if_any_move_disabled_or_encored,            // 0x43
    BattleAICmd_if_curr_move_disabled_or_encored,           // 0x44
    BattleAICmd_flee,                        // 0x45
    BattleAICmd_if_random_safari_flee,               // 0x46
    BattleAICmd_watch,                       // 0x47
    BattleAICmd_get_hold_effect,             // 0x48
    BattleAICmd_get_gender,                  // 0x49
    BattleAICmd_is_first_turn_for,               // 0x4A
    BattleAICmd_get_stockpile_count,         // 0x4B
    BattleAICmd_is_double_battle,            // 0x4C
    BattleAICmd_get_used_held_item,          // 0x4D
    BattleAICmd_get_move_type_from_result,   // 0x4E
    BattleAICmd_get_move_power_from_result,  // 0x4F
    BattleAICmd_get_move_effect_from_result, // 0x50
    BattleAICmd_get_protect_count,           // 0x51
    BattleAICmd_nullsub_52,                  // 0x52
    BattleAICmd_nullsub_53,                  // 0x53
    BattleAICmd_nullsub_54,                  // 0x54
    BattleAICmd_nullsub_55,                  // 0x55
    BattleAICmd_nullsub_56,                  // 0x56
    BattleAICmd_nullsub_57,                  // 0x57
    BattleAICmd_call,                        // 0x58
    BattleAICmd_goto,                        // 0x59
    BattleAICmd_end,                         // 0x5A
    BattleAICmd_if_level_cond,               // 0x5B
    BattleAICmd_if_target_taunted,           // 0x5C
    BattleAICmd_if_target_not_taunted,       // 0x5D
    BattleAICmd_if_target_is_ally,           // 0x5E
    BattleAICmd_is_of_type,                  // 0x5F
    BattleAICmd_check_ability,               // 0x60
    BattleAICmd_if_flash_fired,              // 0x61
    BattleAICmd_if_holds_item,               // 0x62
};

static const u16 sDiscouragedPowerfulMoveEffects[] =
{
    EFFECT_EXPLOSION,
    EFFECT_DREAM_EATER,
    EFFECT_RAZOR_WIND,
    EFFECT_SKY_ATTACK,
    EFFECT_RECHARGE,
    EFFECT_SKULL_BASH,
    EFFECT_SOLARBEAM,
    EFFECT_SPIT_UP,
    EFFECT_FOCUS_PUNCH,
    EFFECT_SUPERPOWER,
    EFFECT_ERUPTION,
    EFFECT_OVERHEAT,
    0xFFFF
};

void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)gBattleResources->battleHistory;

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;
    // items are allowed to use in ONLY trainer battles
    if ((gBattleTypeFlags &
         (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER |
          BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER | BATTLE_TYPE_FRONTIER
          | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_x2000000 | BATTLE_TYPE_SECRET_BASE))
        == BATTLE_TYPE_TRAINER)
    {
        for (i = 0; i < 4; i++)
        {
            if (gTrainers[gTrainerBattleOpponent_A].items[i] != 0)
            {
                gBattleResources->battleHistory->trainerItems[gBattleResources->battleHistory->itemsNo] = gTrainers[gTrainerBattleOpponent_A].items[i];
                gBattleResources->battleHistory->itemsNo++;
            }
        }
    }

    BattleAI_SetupAIData(defaultScoreMoves);
}

void BattleAI_SetupAIData(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)AI_THINKING_STRUCT;
    u8 moveLimitations;

    // clear AI data.
    for (i = 0; i < sizeof(struct AI_ThinkingStruct); i++)
        data[i] = 0;

    // conditional score reset, unlike Ruby.
    for (i = 0; i < 4; i++)
    {
        if (defaultScoreMoves & 1)
            AI_THINKING_STRUCT->score[i] = 100;
        else
            AI_THINKING_STRUCT->score[i] = 0;
        defaultScoreMoves >>= 1;
    }

    moveLimitations = CheckMoveLimitations(gActiveBattler, 0, 0xFF);

    // ignore moves that aren't possible to use
    for (i = 0; i < 4; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->simulatedRNG[i] = 100 - (Random() % 16);
    }
    gBattleResources->AI_ScriptsStack->size = 0;
    sBank_AI = gActiveBattler;
    // decide a random target bank in doubles
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBattleMoveTarget = (Random() & BIT_FLANK) + (GetBattlerSide(gActiveBattler) ^ BIT_SIDE);
        if (gAbsentBattlerFlags & gBitTable[gBattleMoveTarget])
            gBattleMoveTarget ^= BIT_FLANK;
    }
    // in singles there's only one choice
    else
    {
        gBattleMoveTarget = sBank_AI ^ BIT_SIDE;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInRecordedBattle();
    else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_SAFARI;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_ROAMING;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_FIRST_BATTLE;
    else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInBattleFactory();
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_x4000000 | BATTLE_TYPE_SECRET_BASE))
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT;
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags | gTrainers[gTrainerBattleOpponent_B].aiFlags;
    else
       AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        AI_THINKING_STRUCT->aiFlags |= AI_SCRIPT_DOUBLE_BATTLE; // act smart in doubles and don't attack your partner
}

u8 BattleAI_ChooseMoveOrAction(void)
{
    u16 savedCurrentMove = gCurrentMove;
    u8 ret;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        ret = BattleAI_ChooseMoveOrAction_Singles();
    else
        ret = BattleAI_ChooseMoveOrAction_Doubles();

    gCurrentMove = savedCurrentMove;
    return ret;
}

static u8 BattleAI_ChooseMoveOrAction_Singles(void)
{
    u8 currentMoveArray[4];
    u8 consideredMoveArray[4];
    u8 numOfBestMoves;
    s32 i;

    RecordLastUsedMoveByTarget();

    while (AI_THINKING_STRUCT->aiFlags != 0)
    {
        if (AI_THINKING_STRUCT->aiFlags & 1)
        {
            AI_THINKING_STRUCT->aiState = AIState_SettingUp;
            BattleAI_DoAIProcessing();
        }
        AI_THINKING_STRUCT->aiFlags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
        AI_THINKING_STRUCT->movesetIndex = 0;
    }

    // special flags for safari
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
        return 4;
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
        return 5;

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < 4; i++)
    {
        if (gBattleMons[sBank_AI].moves[i] != 0) // emerald adds an extra move ID check for some reason.
        {
            // in ruby, the order of these if statements are reversed.
            if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
            {
                currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }
    return consideredMoveArray[Random() % numOfBestMoves];
}

static u8 BattleAI_ChooseMoveOrAction_Doubles(void)
{
    s32 i;
    s32 j;
    s32 scriptsToRun;
    s16 bestMovePointsForTarget[4];
    s8 mostViableTargetsArray[4];
    u8 actionOrMoveIndex[4];
    u8 mostViableMovesScores[4];
    u8 mostViableMovesIndices[4];
    s32 mostViableTargetsNo;
    s32 mostViableMovesNo;
    s16 mostMovePoints;

    for (i = 0; i < 4; i++)
    {
        if (i == sBank_AI || gBattleMons[i].hp == 0)
        {
            actionOrMoveIndex[i] = -1;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->field_92 >> 4);
            else
                BattleAI_SetupAIData(0xF);

            gBattleMoveTarget = i;

            if ((i & BIT_SIDE) != (sBank_AI & BIT_SIDE))
                RecordLastUsedMoveByTarget();

            AI_THINKING_STRUCT->aiLogicId = 0;
            AI_THINKING_STRUCT->movesetIndex = 0;
            scriptsToRun = AI_THINKING_STRUCT->aiFlags;
            while (scriptsToRun != 0)
            {
                if (scriptsToRun & 1)
                {
                    AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    BattleAI_DoAIProcessing();
                }
                scriptsToRun >>= 1;
                AI_THINKING_STRUCT->aiLogicId++;
                AI_THINKING_STRUCT->movesetIndex = 0;
            }
            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
                actionOrMoveIndex[i] = 4;
            else if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
                actionOrMoveIndex[i] = 5;
            else
            {
                mostViableMovesScores[0] = AI_THINKING_STRUCT->score[0];
                mostViableMovesIndices[0] = 0;
                mostViableMovesNo = 1;
                for (j = 1; j < 4; j++)
                {
                    if (gBattleMons[sBank_AI].moves[j] != 0)
                    {
                        if (mostViableMovesScores[0] == AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[mostViableMovesNo] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[mostViableMovesNo] = j;
                            mostViableMovesNo++;
                        }
                        if (mostViableMovesScores[0] < AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[0] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[0] = j;
                            mostViableMovesNo = 1;
                        }
                    }
                    //_08130E72
                }
                actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
                bestMovePointsForTarget[i] = mostViableMovesScores[0];

                // don't use a move against ally if it has less than 100 pts
                if (i == (sBank_AI ^ BIT_FLANK) && bestMovePointsForTarget[i] < 100)
                {
                    bestMovePointsForTarget[i] = -1;
                    mostViableMovesScores[0] = mostViableMovesScores[0]; // needed to match
                }

            }
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < 4; i++)
    {
        //_08130EDA
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        //_08130EEE
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattleMoveTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    return actionOrMoveIndex[gBattleMoveTarget];
}

static void BattleAI_DoAIProcessing(void)
{
    while (AI_THINKING_STRUCT->aiState != AIState_FinishedProcessing)
    {
        switch (AI_THINKING_STRUCT->aiState)
        {
            case AIState_DoNotProcess: // Needed to match.
                break;
            case AIState_SettingUp:
                gAIScriptPtr = gBattleAI_ScriptsTable[AI_THINKING_STRUCT->aiLogicId]; // set AI ptr to logic ID.
                if (gBattleMons[sBank_AI].pp[AI_THINKING_STRUCT->movesetIndex] == 0)
                {
                    AI_THINKING_STRUCT->moveConsidered = 0;
                }
                else
                {
                    AI_THINKING_STRUCT->moveConsidered = gBattleMons[sBank_AI].moves[AI_THINKING_STRUCT->movesetIndex];
                }
                AI_THINKING_STRUCT->aiState++;
                break;
            case AIState_Processing:
                if (AI_THINKING_STRUCT->moveConsidered != 0)
                    sBattleAICmdTable[*gAIScriptPtr](); // Run AI command.
                else
                {
                    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;
                    AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
                }
                if (AI_THINKING_STRUCT->aiAction & AI_ACTION_DONE)
                {
                   AI_THINKING_STRUCT->movesetIndex++;

                    if (AI_THINKING_STRUCT->movesetIndex < 4 && !(AI_THINKING_STRUCT->aiAction & AI_ACTION_DO_NOT_ATTACK))
                        AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    else
                        AI_THINKING_STRUCT->aiState++;

                    AI_THINKING_STRUCT->aiAction &= ~(AI_ACTION_DONE);
                }
                break;
        }
    }
}

static void RecordLastUsedMoveByTarget(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleResources->battleHistory->usedMoves[gBattleMoveTarget].moves[i] == gLastMoves[gBattleMoveTarget])
            break;
        if (gBattleResources->battleHistory->usedMoves[gBattleMoveTarget].moves[i] != gLastMoves[gBattleMoveTarget]  // HACK: This redundant condition is a hack to make the asm match.
         && gBattleResources->battleHistory->usedMoves[gBattleMoveTarget].moves[i] == 0)
        {
            gBattleResources->battleHistory->usedMoves[gBattleMoveTarget].moves[i] = gLastMoves[gBattleMoveTarget];
            break;
        }
    }
}

void ClearBankMoveHistory(u8 bank)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gBattleResources->battleHistory->usedMoves[bank].moves[i] = 0;
}

void RecordAbilityBattle(u8 bank, u8 abilityId)
{
    gBattleResources->battleHistory->abilities[bank] = abilityId;
}

void ClearBankAbilityHistory(u8 bank)
{
    gBattleResources->battleHistory->abilities[bank] = 0;
}

void RecordItemEffectBattle(u8 bank, u8 itemEffect)
{
    gBattleResources->battleHistory->itemEffects[bank] = itemEffect;
}

void ClearBankItemEffectHistory(u8 bank)
{
    gBattleResources->battleHistory->itemEffects[bank] = 0;
}

static void BattleAICmd_if_random_less_than(void)
{
    u16 random = Random();

    if (random % 256 < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_greater_than(void)
{
    u16 random = Random();

    if (random % 256 > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_equal(void)
{
    u16 random = Random();

    if (random % 256 == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_random_not_equal(void)
{
    u16 random = Random();

    if (random % 256 != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_score(void)
{
    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += gAIScriptPtr[1]; // add the result to the array of the move consider's score.

    if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0) // if the score is negative, flatten it to 0.
        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;

    gAIScriptPtr += 2; // AI return.
}

static void BattleAICmd_if_hp_less_than(void)
{
    u16 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if ((u32)(100 * gBattleMons[bank].hp / gBattleMons[bank].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_more_than(void)
{
    u16 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if ((u32)(100 * gBattleMons[bank].hp / gBattleMons[bank].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_equal(void)
{
    u16 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if ((u32)(100 * gBattleMons[bank].hp / gBattleMons[bank].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_not_equal(void)
{
    u16 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if ((u32)(100 * gBattleMons[bank].hp / gBattleMons[bank].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_status(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[bank].status1 & status) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[bank].status1 & status) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status2(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[bank].status2 & status) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status2(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[bank].status2 & status) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status3(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[bank] & status) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status3(void)
{
    u16 bank;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[bank] & status) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_side_affecting(void)
{
    u16 bank;
    u32 side, status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    side = GET_BATTLER_SIDE(bank);
    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideStatuses[side] & status) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_side_affecting(void)
{
    u16 bank;
    u32 side, status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    side = GET_BATTLER_SIDE(bank);
    status = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideStatuses[side] & status) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_less_than(void)
{
    if (AI_THINKING_STRUCT->funcResult < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_more_than(void)
{
    if (AI_THINKING_STRUCT->funcResult > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_not_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_less_than_ptr(void)
{
    const u8 *value = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *value)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_more_than_ptr(void)
{
    const u8 *value = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *value)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_equal_ptr(void)
{
    const u8 *value = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *value)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_equal_ptr(void)
{
    const u8 *value = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *value)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered == move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_not_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered != move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_in_bytes(void)
{
    const u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_in_bytes(void)
{
    const u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

static void BattleAICmd_if_in_hwords(void)
{
    const u16 *ptr = (const u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_in_hwords(void)
{
    const u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

static void BattleAICmd_if_user_has_attacking_move(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[sBank_AI].moves[i] != 0
            && gBattleMoves[gBattleMons[sBank_AI].moves[i]].power != 0)
            break;
    }
    if (i == 4)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_if_user_has_no_attacking_moves(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[sBank_AI].moves[i] != 0
         && gBattleMoves[gBattleMons[sBank_AI].moves[i]].power != 0)
            break;
    }
    if (i != 4)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_get_turn_count(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleResults.battleTurnCounter;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_type(void)
{
    u8 typeVar = gAIScriptPtr[1];

    switch (typeVar)
    {
    case AI_TYPE1_USER: // AI user primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBank_AI].type1;
        break;
    case AI_TYPE1_TARGET: // target primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattleMoveTarget].type1;
        break;
    case AI_TYPE2_USER: // AI user secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBank_AI].type2;
        break;
    case AI_TYPE2_TARGET: // target secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattleMoveTarget].type2;
        break;
    case AI_TYPE_MOVE: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

static u8 BattleAI_GetWantedBank(u8 bank)
{
    switch (bank)
    {
        case AI_USER:
            return sBank_AI;
        case AI_TARGET:
        default:
            return gBattleMoveTarget;
        case AI_USER_PARTNER:
            return sBank_AI ^ BIT_FLANK;
        case AI_TARGET_PARTNER:
            return gBattleMoveTarget ^ BIT_FLANK;
    }
}

static void BattleAICmd_is_of_type(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);

    if(gBattleMons[bank].type1 == gAIScriptPtr[2] || gBattleMons[bank].type2 == gAIScriptPtr[2])
    {
        AI_THINKING_STRUCT->funcResult = TRUE;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = FALSE;
    }

    gAIScriptPtr += 3;
}

static void BattleAICmd_get_considered_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_how_powerful_move_is(void)
{
    s32 i, checkedMove;
    s32 moveDmgs[4];

    for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
    {
        if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == sDiscouragedPowerfulMoveEffects[i])
            break;
    }

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power > 1
        && sDiscouragedPowerfulMoveEffects[i] == 0xFFFF)
    {
        gDynamicBasePower = 0;
        *(&gBattleStruct->dynamicMoveType) = 0;
        gBattleScripting.dmgMultiplier = 1;
        gMoveResultFlags = 0;
        gCritMultiplier = 1;

        for (checkedMove = 0; checkedMove < 4; checkedMove++)
        {
            for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
            {
                if (gBattleMoves[gBattleMons[sBank_AI].moves[checkedMove]].effect == sDiscouragedPowerfulMoveEffects[i])
                    break;
            }

            if (gBattleMons[sBank_AI].moves[checkedMove] != MOVE_NONE
                && sDiscouragedPowerfulMoveEffects[i] == 0xFFFF
                && gBattleMoves[gBattleMons[sBank_AI].moves[checkedMove]].power > 1)
            {
                gCurrentMove = gBattleMons[sBank_AI].moves[checkedMove];
                AI_CalcDmg(sBank_AI, gBattleMoveTarget);
                TypeCalc(gCurrentMove, sBank_AI, gBattleMoveTarget);
                moveDmgs[checkedMove] = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[checkedMove] / 100;
                if (moveDmgs[checkedMove] == 0)
                    moveDmgs[checkedMove] = 1;
            }
            else
            {
                moveDmgs[checkedMove] = 0;
            }
        }

        for (checkedMove = 0; checkedMove < 4; checkedMove++)
        {
            if (moveDmgs[checkedMove] > moveDmgs[AI_THINKING_STRUCT->movesetIndex])
                break;
        }

        if (checkedMove == 4)
            AI_THINKING_STRUCT->funcResult = MOVE_MOST_POWERFUL; // is the most powerful
        else
            AI_THINKING_STRUCT->funcResult = MOVE_NOT_MOST_POWERFUL; // not most powerful
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = MOVE_POWER_DISCOURAGED; // highly discouraged in terms of power
    }

    gAIScriptPtr++;
}

static void BattleAICmd_get_last_used_bank_move(void)
{
    if (gAIScriptPtr[1] == AI_USER)
        AI_THINKING_STRUCT->funcResult = gLastMoves[sBank_AI];
    else
        AI_THINKING_STRUCT->funcResult = gLastMoves[gBattleMoveTarget];

    gAIScriptPtr += 2;
}

static void BattleAICmd_if_equal_(void) // same as if_equal
{
    if (gAIScriptPtr[1] == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_not_equal_(void) // same as if_not_equal
{
    if (gAIScriptPtr[1] != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_user_goes(void)
{
    if (GetWhoStrikesFirst(sBank_AI, gBattleMoveTarget, TRUE) == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_user_doesnt_go(void)
{
    if (GetWhoStrikesFirst(sBank_AI, gBattleMoveTarget, TRUE) != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_nullsub_2A(void)
{
}

static void BattleAICmd_nullsub_2B(void)
{
}

static void BattleAICmd_count_usable_party_mons(void)
{
    u8 bank;
    u8 bankOnField1, bankOnField2;
    struct Pokemon *party;
    int i;

    AI_THINKING_STRUCT->funcResult = 0;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (GetBattlerSide(bank) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 position;
        bankOnField1 = gBattlerPartyIndexes[bank];
        position = GetBattlerPosition(bank) ^ BIT_FLANK;
        bankOnField2 = gBattlerPartyIndexes[GetBattlerAtPosition(position)];
    }
    else // in singles there's only one bank by side
    {
        bankOnField1 = gBattlerPartyIndexes[bank];
        bankOnField2 = gBattlerPartyIndexes[bank];
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != bankOnField1 && i != bankOnField2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            AI_THINKING_STRUCT->funcResult++;
        }
    }

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_considered_move(void)
{
    AI_THINKING_STRUCT->funcResult = AI_THINKING_STRUCT->moveConsidered;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_considered_move_effect(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;
    gAIScriptPtr += 1;
}

static void BattleAICmd_get_ability(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gActiveBattler != bank)
    {
        if (BATTLE_HISTORY->abilities[bank] != 0)
        {
            AI_THINKING_STRUCT->funcResult = BATTLE_HISTORY->abilities[bank];
            gAIScriptPtr += 2;
            return;
        }

        // abilities that prevent fleeing.
        if (gBattleMons[bank].ability == ABILITY_SHADOW_TAG
        || gBattleMons[bank].ability == ABILITY_MAGNET_PULL
        || gBattleMons[bank].ability == ABILITY_ARENA_TRAP)
        {
            AI_THINKING_STRUCT->funcResult = gBattleMons[bank].ability;
            gAIScriptPtr += 2;
            return;
        }

        if (gBaseStats[gBattleMons[bank].species].ability1 != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[bank].species].ability2 != ABILITY_NONE)
            {
                // AI has no knowledge of opponent, so it guesses which ability.
                if (Random() & 1)
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[bank].species].ability1;
                }
                else
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[bank].species].ability2;
                }
            }
            else
            {
                AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[bank].species].ability1; // it's definitely ability 1.
            }
        }
        else
        {
            AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[bank].species].ability2; // AI cant actually reach this part since every mon has at least 1 ability.
        }
    }
    else
    {
        // The AI knows its own ability.
        AI_THINKING_STRUCT->funcResult = gBattleMons[bank].ability;
    }
    gAIScriptPtr += 2;
}

static void BattleAICmd_check_ability(void)
{
    u32 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);
    u32 ability = gAIScriptPtr[2];

    if (gAIScriptPtr[1] == AI_TARGET || gAIScriptPtr[1] == AI_TARGET_PARTNER)
    {
        if (BATTLE_HISTORY->abilities[bank] != 0)
        {
            ability = BATTLE_HISTORY->abilities[bank];
            AI_THINKING_STRUCT->funcResult = ability;
        }
        // abilities that prevent fleeing.
        else if (gBattleMons[bank].ability == ABILITY_SHADOW_TAG
        || gBattleMons[bank].ability == ABILITY_MAGNET_PULL
        || gBattleMons[bank].ability == ABILITY_ARENA_TRAP)
        {
            ability = gBattleMons[bank].ability;
        }
        else if (gBaseStats[gBattleMons[bank].species].ability1 != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[bank].species].ability2 != ABILITY_NONE)
            {
                u8 abilityDummyVariable = ability; // needed to match
                if (gBaseStats[gBattleMons[bank].species].ability1 != abilityDummyVariable
                && gBaseStats[gBattleMons[bank].species].ability2 != abilityDummyVariable)
                {
                    ability = gBaseStats[gBattleMons[bank].species].ability1;
                }
                else
                    ability = 0;
            }
            else
            {
                ability = gBaseStats[gBattleMons[bank].species].ability1;
            }
        }
        else
        {
            ability = gBaseStats[gBattleMons[bank].species].ability2; // AI cant actually reach this part since every mon has at least 1 ability.
        }
    }
    else
    {
        // The AI knows its own or partner's ability.
        ability = gBattleMons[bank].ability;
    }
    if (ability == 0)
    {
        AI_THINKING_STRUCT->funcResult = 2; // unable to answer
    }
    else if (ability == gAIScriptPtr[2])
    {
        AI_THINKING_STRUCT->funcResult = 1; // pokemon has the ability we wanted to check
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0; // pokemon doesn't have the ability we wanted to check
    }
    gAIScriptPtr += 3;
}

static void BattleAICmd_get_highest_type_effectiveness(void)
{
    s32 i;
    u8* dynamicMoveType;

    gDynamicBasePower = 0;
    dynamicMoveType = &gBattleStruct->dynamicMoveType;
    *dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    AI_THINKING_STRUCT->funcResult = 0;

    for (i = 0; i < 4; i++)
    {
        gBattleMoveDamage = AI_EFFECTIVENESS_x1;
        gCurrentMove = gBattleMons[sBank_AI].moves[i];

        if (gCurrentMove)
        {
            TypeCalc(gCurrentMove, sBank_AI, gBattleMoveTarget);

            // reduce by 1/3.
            if (gBattleMoveDamage == 120)
                gBattleMoveDamage = AI_EFFECTIVENESS_x2;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = AI_EFFECTIVENESS_x4;
            if (gBattleMoveDamage == 30)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0;

            if (AI_THINKING_STRUCT->funcResult < gBattleMoveDamage)
                AI_THINKING_STRUCT->funcResult = gBattleMoveDamage;
        }
    }
    gAIScriptPtr += 1;
}

static void BattleAICmd_if_type_effectiveness(void)
{
    u8 damageVar;

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;

    gBattleMoveDamage = AI_EFFECTIVENESS_x1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;

    TypeCalc(gCurrentMove, sBank_AI, gBattleMoveTarget);

    if (gBattleMoveDamage == 120)
        gBattleMoveDamage = AI_EFFECTIVENESS_x2;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = AI_EFFECTIVENESS_x4;
    if (gBattleMoveDamage == 30)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

    if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0;

    // store gBattleMoveDamage in a u8 variable because gAIScriptPtr[1] is a u8.
    damageVar = gBattleMoveDamage;

    if (damageVar == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_nullsub_32(void)
{
}

static void BattleAICmd_nullsub_33(void)
{
}

static void BattleAICmd_if_status_in_party(void)
{
    struct Pokemon *party;
    int i;
    u32 statusToCompareTo;
    u8 bank;

    switch(gAIScriptPtr[1])
    {
        case AI_USER:
            bank = sBank_AI;
            break;
        default:
            bank = gBattleMoveTarget;
            break;
    }

    party = (GetBattlerSide(bank) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
            return;
        }
    }

    gAIScriptPtr += 10;
}

static void BattleAICmd_if_status_not_in_party(void)
{
    struct Pokemon *party;
    int i;
    u32 statusToCompareTo;
    u8 bank;

    switch(gAIScriptPtr[1])
    {
        case 1:
            bank = sBank_AI;
            break;
        default:
            bank = gBattleMoveTarget;
            break;
    }

    party = (GetBattlerSide(bank) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr += 10; // still bugged in Emerald
        }
    }

    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
}

static void BattleAICmd_get_weather(void)
{
    if (gBattleWeather & WEATHER_RAIN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_RAIN;
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SANDSTORM;
    if (gBattleWeather & WEATHER_SUN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SUN;
    if (gBattleWeather & WEATHER_HAIL_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_HAIL;

    gAIScriptPtr += 1;
}

static void BattleAICmd_if_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_not_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_stat_level_less_than(void)
{
    u32 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gBattleMons[bank].statStages[gAIScriptPtr[2]] < gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_more_than(void)
{
    u32 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gBattleMons[bank].statStages[gAIScriptPtr[2]] > gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_equal(void)
{
    u32 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gBattleMons[bank].statStages[gAIScriptPtr[2]] == gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_stat_level_not_equal(void)
{
    u32 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gBattleMons[bank].statStages[gAIScriptPtr[2]] != gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_if_can_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    AI_CalcDmg(sBank_AI, gBattleMoveTarget);
    TypeCalc(gCurrentMove, sBank_AI, gBattleMoveTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBattleMoveTarget].hp <= gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_cant_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    AI_CalcDmg(sBank_AI, gBattleMoveTarget);
    TypeCalc(gCurrentMove, sBank_AI, gBattleMoveTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // this macro is missing the damage 0 = 1 assumption.

    if (gBattleMons[gBattleMoveTarget].hp > gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_has_move(void)
{
    int i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);

    switch (gAIScriptPtr[1])
    {
        case AI_USER:
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[sBank_AI].moves[i] == *movePtr)
                    break;
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case AI_USER_PARTNER:
            if (gBattleMons[sBank_AI ^ BIT_FLANK].hp == 0)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    if (gBattleMons[sBank_AI ^ BIT_FLANK].moves[i] == *movePtr)
                        break;
                }
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case AI_TARGET:
        case AI_TARGET_PARTNER:
            for (i = 0; i < 4; i++)
            {
                if (BATTLE_HISTORY->usedMoves[gBattleMoveTarget].moves[i] == *movePtr)
                    break;
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
    }
}

static void BattleAICmd_if_doesnt_have_move(void)
{
    int i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
        case AI_USER:
        case AI_USER_PARTNER: // UB: no separate check for user partner
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[sBank_AI].moves[i] == *movePtr)
                    break;
            }
            if (i != 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case AI_TARGET:
        case AI_TARGET_PARTNER:
            for (i = 0; i < 4; i++)
            {
                if (BATTLE_HISTORY->usedMoves[gBattleMoveTarget].moves[i] == *movePtr)
                    break;
            }
            if (i != 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
    }
}

static void BattleAICmd_if_has_move_with_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[sBank_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBank_AI].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < 4; i++)
        {
            // UB: checks sBank_AI instead of gBattleMoveTarget
            if (gBattleMons[sBank_AI].moves[i] != 0 && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattleMoveTarget].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    }
}

static void BattleAICmd_if_doesnt_have_move_with_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < 4; i++)
        {
            if(gBattleMons[sBank_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBank_AI].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < 4; i++)
        {
            if (BATTLE_HISTORY->usedMoves[gBattleMoveTarget].moves[i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattleMoveTarget].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    }
}

static void BattleAICmd_if_any_move_disabled_or_encored(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gAIScriptPtr[2] == 0)
    {
        if (gDisableStructs[bank].disabledMove == 0)
        {
            gAIScriptPtr += 7;
            return;
        }
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    else if (gAIScriptPtr[2] != 1) // ignore the macro if its not 0 or 1.
    {
        gAIScriptPtr += 7;
        return;
    }
    else if (gDisableStructs[bank].encoredMove != 0)
    {
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    gAIScriptPtr += 7;
}

static void BattleAICmd_if_curr_move_disabled_or_encored(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0:
        if (gDisableStructs[gActiveBattler].disabledMove == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1:
        if (gDisableStructs[gActiveBattler].encoredMove == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    default:
        gAIScriptPtr += 6;
        return;
    }
}

static void BattleAICmd_flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void BattleAICmd_if_random_safari_flee(void)
{
    u8 safariFleeRate = gBattleStruct->field_7B * 5; // safari flee rate, from 0-20

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

static void BattleAICmd_get_hold_effect(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    if (gActiveBattler != bank)
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(BATTLE_HISTORY->itemEffects[bank]);
    else
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(gBattleMons[bank].item);

    gAIScriptPtr += 2;
}

static void BattleAICmd_if_holds_item(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);
    u16 item;
    u8 var1, var2;

    if ((bank & BIT_SIDE) == (sBank_AI & BIT_SIDE))
        item = gBattleMons[bank].item;
    else
        item = BATTLE_HISTORY->itemEffects[bank];

    // UB: doesn't properly read an unaligned u16
    var2 = gAIScriptPtr[2];
    var1 = gAIScriptPtr[3];

    if ((var1 | var2) == item)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void BattleAICmd_get_gender(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    AI_THINKING_STRUCT->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[bank].species, gBattleMons[bank].personality);

    gAIScriptPtr += 2;
}

static void BattleAICmd_is_first_turn_for(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[bank].isFirstTurn;

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_stockpile_count(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[bank].stockpileCounter;

    gAIScriptPtr += 2;
}

static void BattleAICmd_is_double_battle(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_used_held_item(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    // This is likely a leftover from Ruby's code and its ugly ewram access
    #ifdef NONMATCHING
        AI_THINKING_STRUCT->funcResult = gBattleStruct->usedHeldItems[bank];
    #else
        AI_THINKING_STRUCT->funcResult = *(u8*)((u8*)(gBattleStruct) + offsetof(struct BattleStruct, usedHeldItems) + (bank * 2));
    #endif // NONMATCHING

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_move_type_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].type;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_move_power_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].power;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_move_effect_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].effect;

    gAIScriptPtr += 1;
}

static void BattleAICmd_get_protect_count(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBattleMoveTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[bank].protectUses;

    gAIScriptPtr += 2;
}

static void BattleAICmd_nullsub_52(void)
{
}

static void BattleAICmd_nullsub_53(void)
{
}

static void BattleAICmd_nullsub_54(void)
{
}

static void BattleAICmd_nullsub_55(void)
{
}

static void BattleAICmd_nullsub_56(void)
{
}

static void BattleAICmd_nullsub_57(void)
{
}

static void BattleAICmd_call(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_goto(void)
{
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

static void BattleAICmd_end(void)
{
    if (AIStackPop() == 0)
        AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
}

static void BattleAICmd_if_level_cond(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // greater than
        if (gBattleMons[sBank_AI].level > gBattleMons[gBattleMoveTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // less than
        if (gBattleMons[sBank_AI].level < gBattleMons[gBattleMoveTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 2: // equal
        if (gBattleMons[sBank_AI].level == gBattleMons[gBattleMoveTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    }
}

static void BattleAICmd_if_target_taunted(void)
{
    if (gDisableStructs[gBattleMoveTarget].tauntTimer1 != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_target_not_taunted(void)
{
    if (gDisableStructs[gBattleMoveTarget].tauntTimer1 == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_target_is_ally(void)
{
    if ((sBank_AI & BIT_SIDE) == (gBattleMoveTarget & BIT_SIDE))
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_flash_fired(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);

    if (gBattleResources->flags->flags[bank] & UNKNOWN_FLAG_FLASH_FIRE)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void AIStackPushVar(const u8 *var)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = var;
}

static void AIStackPushVar_cursor(void)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = gAIScriptPtr;
}

static bool8 AIStackPop(void)
{
    if (gBattleResources->AI_ScriptsStack->size != 0)
    {
        --gBattleResources->AI_ScriptsStack->size;
        gAIScriptPtr = gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size];
        return TRUE;
    }
    else
        return FALSE;
}
