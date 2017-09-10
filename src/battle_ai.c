#include "global.h"
#include "battle_ai.h"
#include "pokemon.h"
#include "battle.h"
#include "species.h"
#include "abilities.h"
#include "rng.h"
#include "item.h"
#include "battle_move_effects.h"

#define AIScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define AIScriptRead16(ptr) ((ptr)[0] | (ptr)[1] << 8)
#define AIScriptRead8(ptr) ((ptr)[0])
#define AIScriptReadPtr(ptr) (u8*) AIScriptRead32(ptr)

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

enum
{
    AI_TARGET,
    AI_USER,
    AI_TARGET_PARTNER,
    AI_USER_PARTNER
};

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
extern u8 gActiveBank;
extern struct BattlePokemon gBattleMons[4];
extern u16 gCurrentMove;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u16 gLastUsedMovesByBanks[4];
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u32 gStatuses3[4];
extern u16 gSideAffecting[2];
extern u16 gBattlePartyID[4];
extern u16 gDynamicBasePower;
extern u8 gBattleMoveFlags;
extern s32 gBattleMoveDamage;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];
extern const u32 gBitTable[];
extern u8 * const gBattleAI_ScriptsTable[];

extern u8 GetBankIdentity(u8);
extern u8 b_first_side(u8, u8, u8);
extern u8 GetBankByPlayerAI(u8);
extern void TypeCalc(u16 move, u8 bankAtk, u8 bankDef);
extern void AI_CalcDmg(u8, u8);

extern u8 CheckMoveLimitations();
extern u32 GetAiScriptsInRecordedBattle();
extern u32 GetAiScriptsInBattleFactory();

static u8 BattleAI_ChooseMoveOrAction_Singles(void);
static u8 BattleAI_ChooseMoveOrAction_Doubles(void);
static void RecordLastUsedMoveByTarget(void);
static void BattleAI_DoAIProcessing(void);
static void AIStackPushVar(u8 *);
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
static void BattleAICmd_if_less_than_32(void);
static void BattleAICmd_if_more_than_32(void);
static void BattleAICmd_if_equal_32(void);
static void BattleAICmd_if_not_equal_32(void);
static void BattleAICmd_if_move(void);
static void BattleAICmd_if_not_move(void);
static void BattleAICmd_if_in_bytes(void);
static void BattleAICmd_if_not_in_bytes(void);
static void BattleAICmd_if_in_words(void);
static void BattleAICmd_if_not_in_words(void);
static void BattleAICmd_if_user_can_damage(void);
static void BattleAICmd_if_user_cant_damage(void);
static void BattleAICmd_get_turn_count(void);
static void BattleAICmd_get_type(void);
static void BattleAICmd_get_last_used_bank_move_power(void);
static void BattleAICmd_is_most_powerful_move(void);
static void BattleAICmd_get_last_used_bank_move(void);
static void BattleAICmd_if_arg_equal(void);
static void BattleAICmd_if_arg_not_equal(void);
static void BattleAICmd_if_would_go_first(void);
static void BattleAICmd_if_would_not_go_first(void);
static void BattleAICmd_nullsub_2A(void);
static void BattleAICmd_nullsub_2B(void);
static void BattleAICmd_count_alive_pokemon(void);
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
static void BattleAICmd_if_dont_have_move(void);
static void BattleAICmd_if_move_effect(void);
static void BattleAICmd_if_not_move_effect(void);
static void BattleAICmd_if_any_move_disabled_or_encored(void);
static void BattleAICmd_if_curr_move_disabled_or_encored(void);
static void BattleAICmd_flee(void);
static void BattleAICmd_if_random_100(void);
static void BattleAICmd_watch(void);
static void BattleAICmd_get_hold_effect(void);
static void BattleAICmd_get_gender(void);
static void BattleAICmd_is_first_turn(void);
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
static void BattleAICmd_jump(void);
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

EWRAM_DATA u8 *gAIScriptPtr = NULL;
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
    BattleAICmd_if_less_than_32,             // 0x15
    BattleAICmd_if_more_than_32,             // 0x16
    BattleAICmd_if_equal_32,                 // 0x17
    BattleAICmd_if_not_equal_32,             // 0x18
    BattleAICmd_if_move,                     // 0x19
    BattleAICmd_if_not_move,                 // 0x1A
    BattleAICmd_if_in_bytes,                 // 0x1B
    BattleAICmd_if_not_in_bytes,             // 0x1C
    BattleAICmd_if_in_words,                 // 0x1D
    BattleAICmd_if_not_in_words,             // 0x1E
    BattleAICmd_if_user_can_damage,          // 0x1F
    BattleAICmd_if_user_cant_damage,         // 0x20
    BattleAICmd_get_turn_count,              // 0x21
    BattleAICmd_get_type,                    // 0x22
    BattleAICmd_get_last_used_bank_move_power,              // 0x23
    BattleAICmd_is_most_powerful_move,       // 0x24
    BattleAICmd_get_last_used_bank_move,                    // 0x25
    BattleAICmd_if_arg_equal,                // 0x26
    BattleAICmd_if_arg_not_equal,            // 0x27
    BattleAICmd_if_would_go_first,           // 0x28
    BattleAICmd_if_would_not_go_first,       // 0x29
    BattleAICmd_nullsub_2A,                  // 0x2A
    BattleAICmd_nullsub_2B,                  // 0x2B
    BattleAICmd_count_alive_pokemon,         // 0x2C
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
    BattleAICmd_if_dont_have_move,           // 0x40
    BattleAICmd_if_move_effect,              // 0x41
    BattleAICmd_if_not_move_effect,          // 0x42
    BattleAICmd_if_any_move_disabled_or_encored,            // 0x43
    BattleAICmd_if_curr_move_disabled_or_encored,           // 0x44
    BattleAICmd_flee,                        // 0x45
    BattleAICmd_if_random_100,               // 0x46
    BattleAICmd_watch,                       // 0x47
    BattleAICmd_get_hold_effect,             // 0x48
    BattleAICmd_get_gender,                  // 0x49
    BattleAICmd_is_first_turn,               // 0x4A
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
    BattleAICmd_jump,                        // 0x59
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
                gBattleResources->battleHistory->TrainerItems[gBattleResources->battleHistory->itemsNo] = gTrainers[gTrainerBattleOpponent_A].items[i];
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

    moveLimitations = CheckMoveLimitations(gActiveBank, 0, 0xFF);

    // ignore moves that aren't possible to use
    for (i = 0; i < 4; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->simulatedRNG[i] = 100 - (Random() % 16);
    }
    gBattleResources->AI_ScriptsStack->size = 0;
    sBank_AI = gActiveBank;
    // decide a random target bank in doubles
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBankTarget = (Random() & 2) + (GetBankSide(gActiveBank) ^ 1);
        if (gAbsentBankFlags & gBitTable[gBankTarget])
            gBankTarget ^= 2;
    }
    // in singles there's only one choice
    else
        gBankTarget = sBank_AI ^ 1;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInRecordedBattle();
    else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        AI_THINKING_STRUCT->aiFlags = 0x40000000;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        AI_THINKING_STRUCT->aiFlags = 0x20000000;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        AI_THINKING_STRUCT->aiFlags = 0x80000000;
    else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInBattleFactory();
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_x4000000 | BATTLE_TYPE_SECRET_BASE))
        AI_THINKING_STRUCT->aiFlags = 7; // the smartest possible set
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags | gTrainers[gTrainerBattleOpponent_B].aiFlags;
    else
       AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        AI_THINKING_STRUCT->aiFlags |= 0x80; // act smart in doubles and don't attack your partner
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

#ifdef NONMATCHING
static u8 BattleAI_ChooseMoveOrAction_Doubles(void)
{
    s32 i;
    s32 j;
    s32 scriptsToRun;
    s16 mostMovePoints;
    s16 bestMovePointsForTarget[4];
    s8 mostViableTargetsArray[4];
    u8 actionOrMoveIndex[4];
    u8 mostViableMovesScores[4];
    u8 mostViableMovesIndices[4];
    s32 mostViableTargetsNo;
    s32 mostViableMovesNo;

    for (i = 0; i < 4; i++) //08130D14
    {
        if (i == sBank_AI || gBattleMons[i].hp == 0)
        {
            //_08130D2E
            actionOrMoveIndex[i] = -1;
            bestMovePointsForTarget[i] = -1;
        }
        //_08130D48
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->field_92 >> 4);
            else
                BattleAI_SetupAIData(0xF);
            //_08130D76
            gBankTarget = i;
            if ((i & 1) != (sBank_AI & 1))
                RecordLastUsedMoveByTarget();
            //_08130D90
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
            //_08130DD8
            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
                actionOrMoveIndex[i] = 4;
            else if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
                actionOrMoveIndex[i] = 5;
            else
            {
                //_08130E10
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
                if (i == (sBank_AI ^ 2) && bestMovePointsForTarget[i] < 100)
                    bestMovePointsForTarget[i] = -1;
            }
        }
        //_08130EAE
    }

    //08130EC4
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
    gBankTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    return actionOrMoveIndex[gBankTarget];
}
#else
__attribute__((naked))
static u8 BattleAI_ChooseMoveOrAction_Doubles(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x24\n\
    movs r0, 0\n\
    mov r8, r0\n\
    mov r1, sp\n\
    adds r1, 0xC\n\
    str r1, [sp, 0x1C]\n\
    mov r2, sp\n\
    adds r2, 0x8\n\
    str r2, [sp, 0x18]\n\
    str r1, [sp, 0x20]\n\
    mov r10, sp\n\
_08130D14:\n\
    ldr r0, =sBank_AI\n\
    ldrb r0, [r0]\n\
    cmp r8, r0\n\
    beq _08130D2E\n\
    movs r0, 0x58\n\
    mov r7, r8\n\
    muls r7, r0\n\
    adds r0, r7, 0\n\
    ldr r1, =gBattleMons\n\
    adds r0, r1\n\
    ldrh r0, [r0, 0x28]\n\
    cmp r0, 0\n\
    bne _08130D48\n\
_08130D2E:\n\
    movs r0, 0xFF\n\
    ldr r2, [sp, 0x20]\n\
    strb r0, [r2]\n\
    ldr r0, =0x0000ffff\n\
    mov r7, r10\n\
    strh r0, [r7]\n\
    b _08130EAE\n\
    .pool\n\
_08130D48:\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    movs r1, 0x80\n\
    lsls r1, 10\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08130D70\n\
    ldr r0, =gBattleStruct\n\
    ldr r0, [r0]\n\
    adds r0, 0x92\n\
    ldrb r0, [r0]\n\
    lsrs r0, 4\n\
    bl BattleAI_SetupAIData\n\
    b _08130D76\n\
    .pool\n\
_08130D70:\n\
    movs r0, 0xF\n\
    bl BattleAI_SetupAIData\n\
_08130D76:\n\
    ldr r0, =gBankTarget\n\
    mov r1, r8\n\
    strb r1, [r0]\n\
    movs r1, 0x1\n\
    mov r2, r8\n\
    ands r2, r1\n\
    ldr r0, =sBank_AI\n\
    ldrb r0, [r0]\n\
    ands r1, r0\n\
    cmp r2, r1\n\
    beq _08130D90\n\
    bl RecordLastUsedMoveByTarget\n\
_08130D90:\n\
    ldr r2, =gBattleResources\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    movs r1, 0\n\
    strb r1, [r0, 0x11]\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    strb r1, [r0, 0x1]\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldr r4, [r0, 0xC]\n\
    mov r9, r2\n\
    cmp r4, 0\n\
    beq _08130DD8\n\
    mov r5, r9\n\
    movs r6, 0\n\
_08130DB0:\n\
    movs r0, 0x1\n\
    ands r0, r4\n\
    cmp r0, 0\n\
    beq _08130DC2\n\
    ldr r0, [r5]\n\
    ldr r0, [r0, 0x14]\n\
    strb r6, [r0]\n\
    bl BattleAI_DoAIProcessing\n\
_08130DC2:\n\
    asrs r4, 1\n\
    ldr r0, [r5]\n\
    ldr r1, [r0, 0x14]\n\
    ldrb r0, [r1, 0x11]\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x11]\n\
    ldr r0, [r5]\n\
    ldr r0, [r0, 0x14]\n\
    strb r6, [r0, 0x1]\n\
    cmp r4, 0\n\
    bne _08130DB0\n\
_08130DD8:\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r3, [r0, 0x14]\n\
    ldrb r1, [r3, 0x10]\n\
    movs r0, 0x2\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08130DFC\n\
    movs r0, 0x4\n\
    ldr r7, [sp, 0x20]\n\
    strb r0, [r7]\n\
    b _08130EAE\n\
    .pool\n\
_08130DFC:\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0\n\
    beq _08130E10\n\
    movs r0, 0x5\n\
    ldr r1, [sp, 0x20]\n\
    strb r0, [r1]\n\
    b _08130EAE\n\
_08130E10:\n\
    add r1, sp, 0x10\n\
    ldrb r0, [r3, 0x4]\n\
    strb r0, [r1]\n\
    add r0, sp, 0x14\n\
    strb r2, [r0]\n\
    movs r5, 0x1\n\
    movs r3, 0x1\n\
    adds r6, r1, 0\n\
    ldr r0, =sBank_AI\n\
    ldrb r1, [r0]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    ldr r2, =gBattleMons + 0xC\n\
    adds r0, r2\n\
    adds r4, r0, 0x2\n\
    add r7, sp, 0x14\n\
_08130E30:\n\
    ldrh r0, [r4]\n\
    cmp r0, 0\n\
    beq _08130E72\n\
    ldrb r1, [r6]\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x4\n\
    adds r2, r0, r3\n\
    movs r0, 0\n\
    ldrsb r0, [r2, r0]\n\
    cmp r1, r0\n\
    bne _08130E56\n\
    adds r0, r6, r5\n\
    ldrb r1, [r2]\n\
    strb r1, [r0]\n\
    adds r0, r7, r5\n\
    strb r3, [r0]\n\
    adds r5, 0x1\n\
_08130E56:\n\
    ldrb r1, [r6]\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x4\n\
    adds r2, r0, r3\n\
    movs r0, 0\n\
    ldrsb r0, [r2, r0]\n\
    cmp r1, r0\n\
    bge _08130E72\n\
    ldrb r0, [r2]\n\
    strb r0, [r6]\n\
    strb r3, [r7]\n\
    movs r5, 0x1\n\
_08130E72:\n\
    adds r4, 0x2\n\
    adds r3, 0x1\n\
    cmp r3, 0x3\n\
    ble _08130E30\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r1, r5, 0\n\
    bl __modsi3\n\
    add r0, sp\n\
    adds r0, 0x14\n\
    ldrb r0, [r0]\n\
    ldr r7, [sp, 0x20]\n\
    strb r0, [r7]\n\
    ldrb r2, [r6]\n\
    mov r0, r10\n\
    strh r2, [r0]\n\
    ldr r0, =sBank_AI\n\
    ldrb r1, [r0]\n\
    movs r0, 0x2\n\
    eors r0, r1\n\
    cmp r8, r0\n\
    bne _08130EAE\n\
    cmp r2, 0x63\n\
    bgt _08130EAE\n\
    ldr r0, =0x0000ffff\n\
    mov r1, r10\n\
    strh r0, [r1]\n\
_08130EAE:\n\
    ldr r2, [sp, 0x20]\n\
    adds r2, 0x1\n\
    str r2, [sp, 0x20]\n\
    movs r7, 0x2\n\
    add r10, r7\n\
    movs r0, 0x1\n\
    add r8, r0\n\
    mov r1, r8\n\
    cmp r1, 0x3\n\
    bgt _08130EC4\n\
    b _08130D14\n\
_08130EC4:\n\
    mov r0, sp\n\
    ldrh r5, [r0]\n\
    movs r0, 0\n\
    ldr r2, [sp, 0x18]\n\
    strb r0, [r2]\n\
    movs r4, 0x1\n\
    mov r8, r4\n\
    ldr r6, =gBankTarget\n\
    ldr r3, [sp, 0x18]\n\
    mov r1, sp\n\
    adds r1, 0x2\n\
_08130EDA:\n\
    lsls r0, r5, 16\n\
    asrs r2, r0, 16\n\
    movs r7, 0\n\
    ldrsh r0, [r1, r7]\n\
    cmp r2, r0\n\
    bne _08130EEE\n\
    adds r0, r3, r4\n\
    mov r7, r8\n\
    strb r7, [r0]\n\
    adds r4, 0x1\n\
_08130EEE:\n\
    movs r7, 0\n\
    ldrsh r0, [r1, r7]\n\
    cmp r2, r0\n\
    bge _08130EFE\n\
    ldrh r5, [r1]\n\
    mov r0, r8\n\
    strb r0, [r3]\n\
    movs r4, 0x1\n\
_08130EFE:\n\
    adds r1, 0x2\n\
    movs r2, 0x1\n\
    add r8, r2\n\
    mov r7, r8\n\
    cmp r7, 0x3\n\
    ble _08130EDA\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r1, r4, 0\n\
    bl __modsi3\n\
    ldr r1, [sp, 0x18]\n\
    adds r0, r1, r0\n\
    ldrb r0, [r0]\n\
    strb r0, [r6]\n\
    ldrb r0, [r6]\n\
    ldr r2, [sp, 0x1C]\n\
    adds r0, r2, r0\n\
    ldrb r0, [r0]\n\
    add sp, 0x24\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool\n\
    .syntax divided\n");
}
#endif

static void BattleAI_DoAIProcessing(void)
{
    while (AI_THINKING_STRUCT->aiState != AIState_FinishedProcessing)
    {
        switch (AI_THINKING_STRUCT->aiState)
        {
            case AIState_DoNotProcess: //Needed to match.
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
                    sBattleAICmdTable[*gAIScriptPtr](); // run AI command.
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
        if (gBattleResources->battleHistory->usedMoves[gBankTarget].moves[i] == gLastUsedMovesByBanks[gBankTarget])
            break;
        if (gBattleResources->battleHistory->usedMoves[gBankTarget].moves[i] != gLastUsedMovesByBanks[gBankTarget]  //HACK: This redundant condition is a hack to make the asm match.
         && gBattleResources->battleHistory->usedMoves[gBankTarget].moves[i] == 0)
        {
            gBattleResources->battleHistory->usedMoves[gBankTarget].moves[i] = gLastUsedMovesByBanks[gBankTarget];
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
    u16 index;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_more_than(void)
{
    u16 index;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_hp_not_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void BattleAICmd_if_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_side_affecting(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg1 = GetBankIdentity(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void BattleAICmd_if_not_side_affecting(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    arg1 = GetBankIdentity(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) == 0)
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

static void BattleAICmd_if_less_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_more_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void BattleAICmd_if_not_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *temp)
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
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

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
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

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

static void BattleAICmd_if_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

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

static void BattleAICmd_if_not_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

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

static void BattleAICmd_if_user_can_damage(void)
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

static void BattleAICmd_if_user_cant_damage(void)
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
    case 1: // player primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBank_AI].type1;
        break;
    case 0: // enemy primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type1;
        break;
    case 3: // player secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBank_AI].type2;
        break;
    case 2: // enemy secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type2;
        break;
    case 4: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

static u8 BattleAI_GetWantedBank(u8 index)
{
    switch (index)
    {
        case AI_USER:
            return sBank_AI;
        case AI_TARGET:
        default:
            return gBankTarget;
        case AI_USER_PARTNER:
            return sBank_AI ^ 2;
        case AI_TARGET_PARTNER:
            return gBankTarget ^ 2;
    }
}

static void BattleAICmd_is_of_type(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);

    if(gBattleMons[bank].type1 == gAIScriptPtr[2] || gBattleMons[bank].type2 == gAIScriptPtr[2])
    {
        AI_THINKING_STRUCT->funcResult = 1;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0;
    }

    gAIScriptPtr += 3;
}

static void BattleAICmd_get_last_used_bank_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}

__attribute__((naked)) // not even going to try. if it doesnt match in ruby, it wont match in emerald (yet).
static void BattleAICmd_is_most_powerful_move(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x14\n\
    movs r3, 0\n\
    ldr r0, =sDiscouragedPowerfulMoveEffects\n\
    ldrh r1, [r0]\n\
    ldr r5, =0x0000ffff\n\
    ldr r6, =gBattleMoves\n\
    ldr r2, =gBattleResources\n\
    cmp r1, r5\n\
    beq _08131F86\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrh r1, [r0, 0x2]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r4, [r0]\n\
    ldr r1, =sDiscouragedPowerfulMoveEffects\n\
_08131F76:\n\
    ldrh r0, [r1]\n\
    cmp r4, r0\n\
    beq _08131F86\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r5\n\
    bne _08131F76\n\
_08131F86:\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrh r1, [r0, 0x2]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r0, [r0, 0x1]\n\
    cmp r0, 0x1\n\
    bhi _08131F9C\n\
    b _08132126\n\
_08131F9C:\n\
    lsls r0, r3, 1\n\
    ldr r1, =sDiscouragedPowerfulMoveEffects\n\
    adds r0, r1\n\
    ldrh r3, [r0]\n\
    ldr r0, =0x0000ffff\n\
    cmp r3, r0\n\
    beq _08131FAC\n\
    b _08132126\n\
_08131FAC:\n\
    ldr r0, =gDynamicBasePower\n\
    movs r1, 0\n\
    strh r1, [r0]\n\
    ldr r0, =gBattleStruct\n\
    ldr r0, [r0]\n\
    strb r1, [r0, 0x13]\n\
    ldr r0, =gBattleScripting\n\
    movs r2, 0x1\n\
    strb r2, [r0, 0xE]\n\
    ldr r0, =gBattleMoveFlags\n\
    strb r1, [r0]\n\
    ldr r0, =gCritMultiplier\n\
    strb r2, [r0]\n\
    movs r6, 0\n\
    mov r9, r3\n\
    ldr r2, =sDiscouragedPowerfulMoveEffects\n\
    ldrh r2, [r2]\n\
    str r2, [sp, 0x10]\n\
_08131FD0:\n\
    movs r3, 0\n\
    ldr r5, =gBattleMons\n\
    lsls r4, r6, 1\n\
    ldr r7, =sBank_AI\n\
    lsls r0, r6, 2\n\
    mov r8, r0\n\
    adds r1, r6, 0x1\n\
    mov r10, r1\n\
    ldr r2, [sp, 0x10]\n\
    cmp r2, r9\n\
    beq _08132014\n\
    ldr r2, =gBattleMoves\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r0, r1\n\
    ldrh r1, [r0]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r2, [r0]\n\
    ldr r1, =sDiscouragedPowerfulMoveEffects\n\
_08132004:\n\
    ldrh r0, [r1]\n\
    cmp r2, r0\n\
    beq _08132014\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r9\n\
    bne _08132004\n\
_08132014:\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r1, r0, r1\n\
    ldrh r0, [r1]\n\
    cmp r0, 0\n\
    beq _081320C0\n\
    lsls r0, r3, 1\n\
    ldr r2, =sDiscouragedPowerfulMoveEffects\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    cmp r0, r9\n\
    bne _081320C0\n\
    ldr r0, =gBattleMoves\n\
    ldrh r2, [r1]\n\
    lsls r1, r2, 1\n\
    adds r1, r2\n\
    lsls r1, 2\n\
    adds r1, r0\n\
    ldrb r0, [r1, 0x1]\n\
    cmp r0, 0x1\n\
    bls _081320C0\n\
    ldr r5, =gCurrentMove\n\
    strh r2, [r5]\n\
    ldrb r0, [r7]\n\
    ldr r4, =gBankTarget\n\
    ldrb r1, [r4]\n\
    bl AI_CalcDmg\n\
    ldrh r0, [r5]\n\
    ldrb r1, [r7]\n\
    ldrb r2, [r4]\n\
    bl TypeCalc\n\
    mov r4, sp\n\
    add r4, r8\n\
    ldr r2, =gBattleMoveDamage\n\
    ldr r0, =gBattleResources\n\
    ldr r0, [r0]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x18\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    ldr r0, [r2]\n\
    muls r0, r1\n\
    movs r1, 0x64\n\
    bl __divsi3\n\
    str r0, [r4]\n\
    cmp r0, 0\n\
    bne _081320C8\n\
    movs r0, 0x1\n\
    str r0, [r4]\n\
    b _081320C8\n\
    .pool\n\
_081320C0:\n\
    mov r1, sp\n\
    add r1, r8\n\
    movs r0, 0\n\
    str r0, [r1]\n\
_081320C8:\n\
    mov r6, r10\n\
    cmp r6, 0x3\n\
    bgt _081320D0\n\
    b _08131FD0\n\
_081320D0:\n\
    movs r6, 0\n\
    ldr r2, =gBattleResources\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrb r0, [r0, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r1, [sp]\n\
    ldr r0, [r0]\n\
    ldr r5, =gAIScriptPtr\n\
    cmp r1, r0\n\
    bgt _08132106\n\
    adds r4, r2, 0\n\
    mov r3, sp\n\
_081320EC:\n\
    adds r3, 0x4\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    bgt _08132106\n\
    ldr r0, [r4]\n\
    ldr r0, [r0, 0x14]\n\
    ldrb r0, [r0, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r1, [r3]\n\
    ldr r0, [r0]\n\
    cmp r1, r0\n\
    ble _081320EC\n\
_08132106:\n\
    cmp r6, 0x4\n\
    bne _0813211C\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x2\n\
    str r0, [r1, 0x8]\n\
    b _08132130\n\
    .pool\n\
_0813211C:\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x1\n\
    str r0, [r1, 0x8]\n\
    b _08132130\n\
_08132126:\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0\n\
    str r0, [r1, 0x8]\n\
    ldr r5, =gAIScriptPtr\n\
_08132130:\n\
    ldr r0, [r5]\n\
    adds r0, 0x1\n\
    str r0, [r5]\n\
    add sp, 0x14\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}

static void BattleAICmd_get_last_used_bank_move(void)
{
    if (gAIScriptPtr[1] == AI_USER)
        AI_THINKING_STRUCT->funcResult = gLastUsedMovesByBanks[sBank_AI];
    else
        AI_THINKING_STRUCT->funcResult = gLastUsedMovesByBanks[gBankTarget];

    gAIScriptPtr += 2;
}

static void BattleAICmd_if_arg_equal(void)
{
    if (gAIScriptPtr[1] == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_arg_not_equal(void)
{
    if (gAIScriptPtr[1] != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_would_go_first(void)
{
    if (b_first_side(sBank_AI, gBankTarget, 1) == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void BattleAICmd_if_would_not_go_first(void)
{
    if (b_first_side(sBank_AI, gBankTarget, 1) != gAIScriptPtr[1])
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

static void BattleAICmd_count_alive_pokemon(void)
{
    u8 index;
    u8 bankOnField1, bankOnField2;
    struct Pokemon *party;
    int i;

    AI_THINKING_STRUCT->funcResult = 0;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if (GetBankSide(index) == 0)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 status;
        bankOnField1 = gBattlePartyID[index];
        status = GetBankIdentity(index) ^ 2;
        bankOnField2 = gBattlePartyID[GetBankByPlayerAI(status)];
    }
    else // in singles there's only one bank by side
    {
        bankOnField1 = gBattlePartyID[index];
        bankOnField2 = gBattlePartyID[index];
    }

    for (i = 0; i < 6; i++)
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
    u8 index;

    if (gAIScriptPtr[1] == AI_USER)
        index = sBank_AI;
    else
        index = gBankTarget;

    if(gActiveBank != index)
    {
        if(BATTLE_HISTORY->abilities[index] != 0)
        {
            AI_THINKING_STRUCT->funcResult = BATTLE_HISTORY->abilities[index];
            gAIScriptPtr += 2;
            return;
        }

        // abilities that prevent fleeing.
        if (gBattleMons[index].ability == ABILITY_SHADOW_TAG
        || gBattleMons[index].ability == ABILITY_MAGNET_PULL
        || gBattleMons[index].ability == ABILITY_ARENA_TRAP)
        {
            AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
            gAIScriptPtr += 2;
            return;
        }

        if (gBaseStats[gBattleMons[index].species].ability1 != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[index].species].ability2 != ABILITY_NONE)
            {
                // AI has no knowledge of opponent, so it guesses which ability.
                if (Random() & 1)
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1;
                }
                else
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2;
                }
            }
            else
            {
                AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1; // it's definitely ability 1.
            }
        }
        else
        {
            AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2; // AI cant actually reach this part since every mon has at least 1 ability.
        }
    }
    else
    {
        // The AI knows its own ability.
        AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
    }
    gAIScriptPtr += 2;
}

#ifdef NONMATCHING
static void BattleAICmd_check_ability(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);
    u8 ability = gAIScriptPtr[2];

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
                if (gBaseStats[gBattleMons[bank].species].ability1 != ability
                && gBaseStats[gBattleMons[bank].species].ability2 != ability)
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
#else
__attribute__((naked))
static void BattleAICmd_check_ability(void)
{
    asm(".syntax unified\n\
    push {r4-r6,lr}\n\
    ldr r4, =gAIScriptPtr\n\
    ldr r0, [r4]\n\
    ldrb r0, [r0, 0x1]\n\
    bl BattleAI_GetWantedBank\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    ldr r0, [r4]\n\
    ldrb r3, [r0, 0x2]\n\
    ldrb r0, [r0, 0x1]\n\
    cmp r0, 0\n\
    beq _0813253A\n\
    cmp r0, 0x2\n\
    bne _081325BC\n\
_0813253A:\n\
    ldr r0, =gBattleResources\n\
    ldr r4, [r0]\n\
    ldr r1, [r4, 0x18]\n\
    adds r1, 0x40\n\
    adds r2, r1, r5\n\
    ldrb r1, [r2]\n\
    adds r6, r0, 0\n\
    cmp r1, 0\n\
    beq _0813255C\n\
    adds r3, r1, 0\n\
    ldr r0, [r4, 0x14]\n\
    str r3, [r0, 0x8]\n\
    b _081325CA\n\
    .pool\n\
_0813255C:\n\
    ldr r1, =gBattleMons\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r4, r0, r1\n\
    adds r0, r4, 0\n\
    adds r0, 0x20\n\
    ldrb r0, [r0]\n\
    cmp r0, 0x17\n\
    beq _08132576\n\
    cmp r0, 0x2A\n\
    beq _08132576\n\
    cmp r0, 0x47\n\
    bne _08132588\n\
_08132576:\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r0, r1\n\
    adds r0, 0x20\n\
    ldrb r3, [r0]\n\
    b _081325CA\n\
    .pool\n\
_08132588:\n\
    ldr r2, =gBaseStats\n\
    ldrh r1, [r4]\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    lsls r0, 2\n\
    adds r1, r0, r2\n\
    ldrb r4, [r1, 0x16]\n\
    cmp r4, 0\n\
    beq _081325B8\n\
    ldrb r2, [r1, 0x17]\n\
    cmp r2, 0\n\
    beq _081325B4\n\
    adds r0, r3, 0\n\
    cmp r4, r0\n\
    beq _081325CE\n\
    cmp r2, r0\n\
    beq _081325CE\n\
    adds r3, r4, 0\n\
    b _081325CA\n\
    .pool\n\
_081325B4:\n\
    ldrb r3, [r1, 0x16]\n\
    b _081325CA\n\
_081325B8:\n\
    ldrb r3, [r1, 0x17]\n\
    b _081325CA\n\
_081325BC:\n\
    ldr r1, =gBattleMons\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r0, r1\n\
    adds r0, 0x20\n\
    ldrb r3, [r0]\n\
    ldr r6, =gBattleResources\n\
_081325CA:\n\
    cmp r3, 0\n\
    bne _081325E8\n\
_081325CE:\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x2\n\
    str r0, [r1, 0x8]\n\
    ldr r2, =gAIScriptPtr\n\
    b _08132608\n\
    .pool\n\
_081325E8:\n\
    ldr r0, =gAIScriptPtr\n\
    ldr r1, [r0]\n\
    adds r2, r0, 0\n\
    ldrb r1, [r1, 0x2]\n\
    cmp r3, r1\n\
    bne _08132600\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x1\n\
    b _08132606\n\
    .pool\n\
_08132600:\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0\n\
_08132606:\n\
    str r0, [r1, 0x8]\n\
_08132608:\n\
    ldr r0, [r2]\n\
    adds r0, 0x3\n\
    str r0, [r2]\n\
    pop {r4-r6}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif

static void BattleAICmd_get_highest_type_effectiveness(void)
{
    s32 i;
    u8* dynamicMoveType;

    gDynamicBasePower = 0;
    dynamicMoveType = &gBattleStruct->dynamicMoveType;
    *dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    AI_THINKING_STRUCT->funcResult = 0;

    for (i = 0; i < 4; i++)
    {
        gBattleMoveDamage = 40;
        gCurrentMove = gBattleMons[sBank_AI].moves[i];

        if (gCurrentMove)
        {
            TypeCalc(gCurrentMove, sBank_AI, gBankTarget);

            // reduce by 1/3.
            if (gBattleMoveDamage == 120)
                gBattleMoveDamage = 80;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = 160;
            if (gBattleMoveDamage == 30)
                gBattleMoveDamage = 20;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = 10;

            if (gBattleMoveFlags & MOVESTATUS_NOTAFFECTED)
                gBattleMoveDamage = 0;

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
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;

    gBattleMoveDamage = 40;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;

    TypeCalc(gCurrentMove, sBank_AI, gBankTarget);

    if (gBattleMoveDamage == 120)
        gBattleMoveDamage = 80;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = 160;
    if (gBattleMoveDamage == 30)
        gBattleMoveDamage = 20;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = 10;

    if (gBattleMoveFlags & MOVESTATUS_NOTAFFECTED)
        gBattleMoveDamage = 0;

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
    u8 index;

    switch(gAIScriptPtr[1])
    {
        case 1:
            index = sBank_AI;
            break;
        default:
            index = gBankTarget;
            break;
    }

    party = (GetBankSide(index) == 0) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
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
    u8 index;

    switch(gAIScriptPtr[1])
    {
        case 1:
            index = sBank_AI;
            break;
        default:
            index = gBankTarget;
            break;
    }

    party = (GetBankSide(index) == 0) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
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
        AI_THINKING_STRUCT->funcResult = 1;
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        AI_THINKING_STRUCT->funcResult = 2;
    if (gBattleWeather & WEATHER_SUN_ANY)
        AI_THINKING_STRUCT->funcResult = 0;
    if (gBattleWeather & WEATHER_HAIL_ANY)
        AI_THINKING_STRUCT->funcResult = 3;

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
        bank = gBankTarget;

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
        bank = gBankTarget;

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
        bank = gBankTarget;

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
        bank = gBankTarget;

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
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    AI_CalcDmg(sBank_AI, gBankTarget);
    TypeCalc(gCurrentMove, sBank_AI, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBankTarget].hp <= gBattleMoveDamage)
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
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    AI_CalcDmg(sBank_AI, gBankTarget);
    TypeCalc(gCurrentMove, sBank_AI, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] / 100;

    // this macro is missing the damage 0 = 1 assumption.

    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_has_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
        case AI_USER:
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[sBank_AI].moves[i] == *temp_ptr)
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
            if (gBattleMons[sBank_AI ^ 2].hp == 0)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    if (gBattleMons[sBank_AI ^ 2].moves[i] == *temp_ptr)
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
                if (BATTLE_HISTORY->usedMoves[gBankTarget].moves[i] == *temp_ptr)
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

static void BattleAICmd_if_dont_have_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
        case AI_USER:
        case AI_USER_PARTNER: // UB: no separate check for user partner
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[sBank_AI].moves[i] == *temp_ptr)
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
                if (BATTLE_HISTORY->usedMoves[gBankTarget].moves[i] == *temp_ptr)
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

static void BattleAICmd_if_move_effect(void)
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
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[sBank_AI].moves[i] != 0 && gBattleMoves[BATTLE_HISTORY->usedMoves[gBankTarget].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    }
}

static void BattleAICmd_if_not_move_effect(void)
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
            if (BATTLE_HISTORY->usedMoves[gBankTarget].moves[i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBankTarget].moves[i]].effect == gAIScriptPtr[2])
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
        bank = gBankTarget;

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
        if (gDisableStructs[gActiveBank].disabledMove == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1:
        if (gDisableStructs[gActiveBank].encoredMove == AI_THINKING_STRUCT->moveConsidered)
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
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK); // what matters is UNK2 being enabled.
}

static void BattleAICmd_if_random_100(void)
{
    u8 safariFleeRate = gBattleStruct->field_7B * 5; // safari flee rate, from 0-20

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK); // what matters is UNK3 being enabled.
}

static void BattleAICmd_get_hold_effect(void)
{
    u8 bank;
    u16 status;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBankTarget;

    if (gActiveBank != bank)
    {
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(BATTLE_HISTORY->itemEffects[bank]);
    }
    else
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(gBattleMons[bank].item);

    gAIScriptPtr += 2;
}

static void BattleAICmd_if_holds_item(void)
{
    u8 bank = BattleAI_GetWantedBank(gAIScriptPtr[1]);
    u16 item;
    u8 var1, var2;

    if ((bank & 1) == (sBank_AI & 1))
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
        bank = gBankTarget;

    AI_THINKING_STRUCT->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[bank].species, gBattleMons[bank].personality);

    gAIScriptPtr += 2;
}

static void BattleAICmd_is_first_turn(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[bank].isFirstTurn;

    gAIScriptPtr += 2;
}

static void BattleAICmd_get_stockpile_count(void)
{
    u8 bank;

    if (gAIScriptPtr[1] == AI_USER)
        bank = sBank_AI;
    else
        bank = gBankTarget;

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
        bank = gBankTarget;

    // This is likely a leftover from Ruby's code and its ugly ewram access
    #ifdef NONMATCHING
        AI_THINKING_STRUCT->funcResult = gBattleStruct->usedHeldItems[bank];
    #else
        AI_THINKING_STRUCT->funcResult = *(u8*)((u8*)(gBattleStruct) + 0xB8 + (bank * 2));
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
        bank = gBankTarget;

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

static void BattleAICmd_jump(void)
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
        if (gBattleMons[sBank_AI].level > gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // less than
        if (gBattleMons[sBank_AI].level < gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 2: // equal
        if (gBattleMons[sBank_AI].level == gBattleMons[gBankTarget].level)
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
    if (gDisableStructs[gBankTarget].tauntTimer1 != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_target_not_taunted(void)
{
    if (gDisableStructs[gBankTarget].tauntTimer1 == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_target_is_ally(void)
{
    if((sBank_AI & 1) == (gBankTarget & 1))
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void BattleAICmd_if_flash_fired(void)
{
    u8 index = BattleAI_GetWantedBank(gAIScriptPtr[1]);

    if(gBattleResources->flags->flags[index] & UNKNOWN_FLAG_FLASH_FIRE)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void AIStackPushVar(u8 *var)
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
