#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_script_commands.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/items.h"

#define AI_ACTION_DONE          0x0001
#define AI_ACTION_FLEE          0x0002
#define AI_ACTION_WATCH         0x0004
#define AI_ACTION_DO_NOT_ATTACK 0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

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

extern const u8 *const gBattleAI_ScriptsTable[];

static u8 ChooseMoveOrAction_Singles(void);
static u8 ChooseMoveOrAction_Doubles(void);
static void BattleAI_DoAIProcessing(void);
static void AIStackPushVar(const u8 *);
static bool8 AIStackPop(void);

static void Cmd_if_random_less_than(void);
static void Cmd_if_random_greater_than(void);
static void Cmd_if_random_equal(void);
static void Cmd_if_random_not_equal(void);
static void Cmd_score(void);
static void Cmd_if_hp_less_than(void);
static void Cmd_if_hp_more_than(void);
static void Cmd_if_hp_equal(void);
static void Cmd_if_hp_not_equal(void);
static void Cmd_if_status(void);
static void Cmd_if_not_status(void);
static void Cmd_if_status2(void);
static void Cmd_if_not_status2(void);
static void Cmd_if_status3(void);
static void Cmd_if_not_status3(void);
static void Cmd_if_side_affecting(void);
static void Cmd_if_not_side_affecting(void);
static void Cmd_if_less_than(void);
static void Cmd_if_more_than(void);
static void Cmd_if_equal(void);
static void Cmd_if_not_equal(void);
static void Cmd_if_less_than_ptr(void);
static void Cmd_if_more_than_ptr(void);
static void Cmd_if_equal_ptr(void);
static void Cmd_if_not_equal_ptr(void);
static void Cmd_if_move(void);
static void Cmd_if_not_move(void);
static void Cmd_if_in_bytes(void);
static void Cmd_if_not_in_bytes(void);
static void Cmd_if_in_hwords(void);
static void Cmd_if_not_in_hwords(void);
static void Cmd_if_user_has_attacking_move(void);
static void Cmd_if_user_has_no_attacking_moves(void);
static void Cmd_get_turn_count(void);
static void Cmd_get_type(void);
static void Cmd_get_considered_move_power(void);
static void Cmd_get_how_powerful_move_is(void);
static void Cmd_get_last_used_battler_move(void);
static void Cmd_if_equal_u32(void);
static void Cmd_if_not_equal_u32(void);
static void Cmd_if_user_goes(void);
static void Cmd_if_cant_use_belch(void);
static void Cmd_nullsub_2A(void);
static void Cmd_nullsub_2B(void);
static void Cmd_count_usable_party_mons(void);
static void Cmd_get_considered_move(void);
static void Cmd_get_considered_move_effect(void);
static void Cmd_get_ability(void);
static void Cmd_get_highest_type_effectiveness(void);
static void Cmd_if_type_effectiveness(void);
static void Cmd_nullsub_32(void);
static void Cmd_nullsub_33(void);
static void Cmd_if_status_in_party(void);
static void Cmd_if_status_not_in_party(void);
static void Cmd_get_weather(void);
static void Cmd_if_effect(void);
static void Cmd_if_not_effect(void);
static void Cmd_if_stat_level_less_than(void);
static void Cmd_if_stat_level_more_than(void);
static void Cmd_if_stat_level_equal(void);
static void Cmd_if_stat_level_not_equal(void);
static void Cmd_if_can_faint(void);
static void Cmd_if_cant_faint(void);
static void Cmd_if_has_move(void);
static void Cmd_if_doesnt_have_move(void);
static void Cmd_if_has_move_with_effect(void);
static void Cmd_if_doesnt_have_move_with_effect(void);
static void Cmd_if_any_move_disabled_or_encored(void);
static void Cmd_if_curr_move_disabled_or_encored(void);
static void Cmd_flee(void);
static void Cmd_if_random_safari_flee(void);
static void Cmd_watch(void);
static void Cmd_get_hold_effect(void);
static void Cmd_get_gender(void);
static void Cmd_is_first_turn_for(void);
static void Cmd_get_stockpile_count(void);
static void Cmd_is_double_battle(void);
static void Cmd_get_used_held_item(void);
static void Cmd_get_move_type_from_result(void);
static void Cmd_get_move_power_from_result(void);
static void Cmd_get_move_effect_from_result(void);
static void Cmd_get_protect_count(void);
static void Cmd_if_move_flag(void);
static void Cmd_if_field_status(void);
static void Cmd_get_move_accuracy(void);
static void Cmd_call_if_eq(void);
static void Cmd_call_if_move_flag(void);
static void Cmd_nullsub_57(void);
static void Cmd_call(void);
static void Cmd_goto(void);
static void Cmd_end(void);
static void Cmd_if_level_cond(void);
static void Cmd_if_target_taunted(void);
static void Cmd_if_target_not_taunted(void);
static void Cmd_check_ability(void);
static void Cmd_is_of_type(void);
static void Cmd_if_target_is_ally(void);
static void Cmd_if_flash_fired(void);
static void Cmd_if_holds_item(void);
static void Cmd_get_ally_chosen_move(void);
static void Cmd_if_has_no_attacking_moves(void);
static void Cmd_get_hazards_count(void);
static void Cmd_if_doesnt_hold_berry(void);
static void Cmd_if_share_type(void);
static void Cmd_if_cant_use_last_resort(void);
static void Cmd_if_has_move_with_split(void);
static void Cmd_if_has_no_move_with_split(void);
static void Cmd_if_physical_moves_unusable(void);
static void Cmd_if_ai_can_go_down(void);
static void Cmd_if_has_move_with_type(void);
static void Cmd_if_no_move_used(void);
static void Cmd_if_has_move_with_flag(void);
static void Cmd_if_battler_absent(void);
static void Cmd_is_grounded(void);
static void Cmd_get_best_dmg_hp_percent(void);
static void Cmd_get_curr_dmg_hp_percent(void);
static void Cmd_get_move_split_from_result(void);
static void Cmd_get_considered_move_split(void);
static void Cmd_get_considered_move_target(void);
static void Cmd_compare_speeds(void);
static void Cmd_is_wakeup_turn(void);
static void Cmd_if_has_move_with_accuracy_lt(void);

// ewram
EWRAM_DATA const u8 *gAIScriptPtr = NULL;
EWRAM_DATA u8 sBattler_AI = 0;

// const rom data
typedef void (*BattleAICmdFunc)(void);

static s16 AI_CheckBadMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_TryToFaint(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_CheckGoodMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_SetupFirstTurn(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_Risky(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_PreferStrongestMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_PreferBatonPass(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_DoubleBattle(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_HPAware(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_Roaming(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_Safari(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);
static s16 AI_FirstBattle(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);

static s16 (*const sBattleAiFuncTable[])(u8, u8, u16, s16) =
{
    [0] = AI_CheckBadMove,           // AI_FLAG_CHECK_BAD_MOVE
    [1] = AI_TryToFaint,             // AI_FLAG_TRY_TO_FAINT
    [2] = AI_CheckGoodMove,          // AI_FLAG_CHECK_GOOD_MOVE
    [3] = AI_SetupFirstTurn,         // AI_FLAG_SETUP_FIRST_TURN
    [4] = AI_Risky,                  // AI_FLAG_RISKY
    [5] = AI_PreferStrongestMove,    // AI_FLAG_PREFER_STRONGEST_MOVE
    [6] = AI_PreferBatonPass,        // AI_FLAG_PREFER_BATON_PASS
    [7] = AI_DoubleBattle,           // AI_FLAG_DOUBLE_BATTLE
    [8] = AI_HPAware,                // AI_FLAG_HP_AWARE
    [9] = NULL,                      // AI_FLAG_NEGATE_AWARE
    [10] = NULL,                     // AI_FLAG_HELP_PARTNER
    [11] = NULL,                     // AI_FLAG_WILL_SUICIDE
    [12] = NULL,                     // Unused
    [13] = NULL,                     // Unused
    [14] = NULL,                     // Unused
    [15] = NULL,                     // Unused
    [16] = NULL,                     // Unused
    [17] = NULL,                     // Unused
    [18] = NULL,                     // Unused
    [19] = NULL,                     // Unused
    [20] = NULL,                     // Unused
    [21] = NULL,                     // Unused
    [22] = NULL,                     // Unused
    [23] = NULL,                     // Unused
    [24] = NULL,                     // Unused
    [25] = NULL,                     // Unused
    [26] = NULL,                     // Unused
    [27] = NULL,                     // Unused
    [28] = NULL,                     // Unused
    [29] = AI_Roaming,              // AI_FLAG_ROAMING
    [30] = AI_Safari,               // AI_FLAG_SAFARI
    [31] = AI_FirstBattle,          // AI_FLAG_FIRST_BATTLE
};

static const BattleAICmdFunc sBattleAICmdTable[] =
{
    Cmd_if_random_less_than,                        // 0x0
    Cmd_if_random_greater_than,                     // 0x1
    Cmd_if_random_equal,                            // 0x2
    Cmd_if_random_not_equal,                        // 0x3
    Cmd_score,                                      // 0x4
    Cmd_if_hp_less_than,                            // 0x5
    Cmd_if_hp_more_than,                            // 0x6
    Cmd_if_hp_equal,                                // 0x7
    Cmd_if_hp_not_equal,                            // 0x8
    Cmd_if_status,                                  // 0x9
    Cmd_if_not_status,                              // 0xA
    Cmd_if_status2,                                 // 0xB
    Cmd_if_not_status2,                             // 0xC
    Cmd_if_status3,                                 // 0xD
    Cmd_if_not_status3,                             // 0xE
    Cmd_if_side_affecting,                          // 0xF
    Cmd_if_not_side_affecting,                      // 0x10
    Cmd_if_less_than,                               // 0x11
    Cmd_if_more_than,                               // 0x12
    Cmd_if_equal,                                   // 0x13
    Cmd_if_not_equal,                               // 0x14
    Cmd_if_less_than_ptr,                           // 0x15
    Cmd_if_more_than_ptr,                           // 0x16
    Cmd_if_equal_ptr,                               // 0x17
    Cmd_if_not_equal_ptr,                           // 0x18
    Cmd_if_move,                                    // 0x19
    Cmd_if_not_move,                                // 0x1A
    Cmd_if_in_bytes,                                // 0x1B
    Cmd_if_not_in_bytes,                            // 0x1C
    Cmd_if_in_hwords,                               // 0x1D
    Cmd_if_not_in_hwords,                           // 0x1E
    Cmd_if_user_has_attacking_move,                 // 0x1F
    Cmd_if_user_has_no_attacking_moves,             // 0x20
    Cmd_get_turn_count,                             // 0x21
    Cmd_get_type,                                   // 0x22
    Cmd_get_considered_move_power,                  // 0x23
    Cmd_get_how_powerful_move_is,                   // 0x24
    Cmd_get_last_used_battler_move,                 // 0x25
    Cmd_if_equal_u32,                               // 0x26
    Cmd_if_not_equal_u32,                           // 0x27
    Cmd_if_user_goes,                               // 0x28
    Cmd_if_cant_use_belch,                          // 0x29
    Cmd_nullsub_2A,                                 // 0x2A
    Cmd_nullsub_2B,                                 // 0x2B
    Cmd_count_usable_party_mons,                    // 0x2C
    Cmd_get_considered_move,                        // 0x2D
    Cmd_get_considered_move_effect,                 // 0x2E
    Cmd_get_ability,                                // 0x2F
    Cmd_get_highest_type_effectiveness,             // 0x30
    Cmd_if_type_effectiveness,                      // 0x31
    Cmd_nullsub_32,                                 // 0x32
    Cmd_nullsub_33,                                 // 0x33
    Cmd_if_status_in_party,                         // 0x34
    Cmd_if_status_not_in_party,                     // 0x35
    Cmd_get_weather,                                // 0x36
    Cmd_if_effect,                                  // 0x37
    Cmd_if_not_effect,                              // 0x38
    Cmd_if_stat_level_less_than,                    // 0x39
    Cmd_if_stat_level_more_than,                    // 0x3A
    Cmd_if_stat_level_equal,                        // 0x3B
    Cmd_if_stat_level_not_equal,                    // 0x3C
    Cmd_if_can_faint,                               // 0x3D
    Cmd_if_cant_faint,                              // 0x3E
    Cmd_if_has_move,                                // 0x3F
    Cmd_if_doesnt_have_move,                        // 0x40
    Cmd_if_has_move_with_effect,                    // 0x41
    Cmd_if_doesnt_have_move_with_effect,            // 0x42
    Cmd_if_any_move_disabled_or_encored,            // 0x43
    Cmd_if_curr_move_disabled_or_encored,           // 0x44
    Cmd_flee,                                       // 0x45
    Cmd_if_random_safari_flee,                      // 0x46
    Cmd_watch,                                      // 0x47
    Cmd_get_hold_effect,                            // 0x48
    Cmd_get_gender,                                 // 0x49
    Cmd_is_first_turn_for,                          // 0x4A
    Cmd_get_stockpile_count,                        // 0x4B
    Cmd_is_double_battle,                           // 0x4C
    Cmd_get_used_held_item,                         // 0x4D
    Cmd_get_move_type_from_result,                  // 0x4E
    Cmd_get_move_power_from_result,                 // 0x4F
    Cmd_get_move_effect_from_result,                // 0x50
    Cmd_get_protect_count,                          // 0x51
    Cmd_if_move_flag,                               // 0x52
    Cmd_if_field_status,                            // 0x53
    Cmd_get_move_accuracy,                          // 0x54
    Cmd_call_if_eq,                                 // 0x55
    Cmd_call_if_move_flag,                          // 0x56
    Cmd_nullsub_57,                                 // 0x57
    Cmd_call,                                       // 0x58
    Cmd_goto,                                       // 0x59
    Cmd_end,                                        // 0x5A
    Cmd_if_level_cond,                              // 0x5B
    Cmd_if_target_taunted,                          // 0x5C
    Cmd_if_target_not_taunted,                      // 0x5D
    Cmd_if_target_is_ally,                          // 0x5E
    Cmd_is_of_type,                                 // 0x5F
    Cmd_check_ability,                              // 0x60
    Cmd_if_flash_fired,                             // 0x61
    Cmd_if_holds_item,                              // 0x62
    Cmd_get_ally_chosen_move,                       // 0x63
    Cmd_if_has_no_attacking_moves,                  // 0x64
    Cmd_get_hazards_count,                          // 0x65
    Cmd_if_doesnt_hold_berry,                       // 0x66
    Cmd_if_share_type,                              // 0x67
    Cmd_if_cant_use_last_resort,                    // 0x68
    Cmd_if_has_move_with_split,                     // 0x69
    Cmd_if_has_no_move_with_split,                  // 0x6A
    Cmd_if_physical_moves_unusable,                 // 0x6B
    Cmd_if_ai_can_go_down,                          // 0x6C
    Cmd_if_has_move_with_type,                      // 0x6D
    Cmd_if_no_move_used,                            // 0x6E
    Cmd_if_has_move_with_flag,                      // 0x6F
    Cmd_if_battler_absent,                          // 0x70
    Cmd_is_grounded,                                // 0x71
    Cmd_get_best_dmg_hp_percent,                    // 0x72
    Cmd_get_curr_dmg_hp_percent,                    // 0x73
    Cmd_get_move_split_from_result,                 // 0x74
    Cmd_get_considered_move_split,                  // 0x75
    Cmd_get_considered_move_target,                 // 0x76
    Cmd_compare_speeds,                             // 0x77
    Cmd_is_wakeup_turn,                             // 0x78
    Cmd_if_has_move_with_accuracy_lt,               // 0x79
};

// code
void BattleAI_SetupItems(void)
{
    s32 i;
    u8 *data = (u8 *)BATTLE_HISTORY;

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    // Items are allowed to use in ONLY trainer battles.
    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER
                               | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_FRONTIER
                               | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_x2000000)
            )
       )
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (gTrainers[gTrainerBattleOpponent_A].items[i] != 0)
            {
                BATTLE_HISTORY->trainerItems[BATTLE_HISTORY->itemsNo] = gTrainers[gTrainerBattleOpponent_A].items[i];
                BATTLE_HISTORY->itemsNo++;
            }
        }
    }
}

void BattleAI_SetupFlags(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInRecordedBattle();
    else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        AI_THINKING_STRUCT->aiFlags = AI_FLAG_SAFARI;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        AI_THINKING_STRUCT->aiFlags = AI_FLAG_ROAMING;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        AI_THINKING_STRUCT->aiFlags = AI_FLAG_FIRST_BATTLE;
    else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInBattleFactory();
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE))
        AI_THINKING_STRUCT->aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_GOOD_MOVE | AI_FLAG_TRY_TO_FAINT;
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags | gTrainers[gTrainerBattleOpponent_B].aiFlags;
    else
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags;

    if (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS) || gTrainers[gTrainerBattleOpponent_A].doubleBattle)
        AI_THINKING_STRUCT->aiFlags |= AI_FLAG_DOUBLE_BATTLE; // Act smart in doubles and don't attack your partner.
}

void BattleAI_SetupAIData(u8 defaultScoreMoves)
{
    s32 i, move, dmg;
    u8 moveLimitations;

    // Clear AI data but preserve the flags.
    u32 flags = AI_THINKING_STRUCT->aiFlags;
    memset(AI_THINKING_STRUCT, 0, sizeof(struct AI_ThinkingStruct));
    AI_THINKING_STRUCT->aiFlags = flags;

    // Conditional score reset, unlike Ruby.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (defaultScoreMoves & 1)
            AI_THINKING_STRUCT->score[i] = 100;
        else
            AI_THINKING_STRUCT->score[i] = 0;

        defaultScoreMoves >>= 1;
    }

    moveLimitations = CheckMoveLimitations(gActiveBattler, 0, 0xFF);

    // Ignore moves that aren't possible to use.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;
    }

    gBattleResources->AI_ScriptsStack->size = 0;
    sBattler_AI = gActiveBattler;

    // Simulate dmg for all AI moves against all opposing targets
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (GET_BATTLER_SIDE2(sBattler_AI) == GET_BATTLER_SIDE2(gBattlerTarget))
            continue;
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            dmg = 0;
            move = gBattleMons[sBattler_AI].moves[i];
            if (gBattleMoves[move].power != 0 && !(moveLimitations & gBitTable[i]))
            {
                dmg = AI_CalcDamage(move, sBattler_AI, gBattlerTarget) * (100 - (Random() % 10)) / 100;
                if (dmg == 0)
                    dmg = 1;
            }

            AI_THINKING_STRUCT->simulatedDmg[sBattler_AI][gBattlerTarget][i] = dmg;
        }
    }

    gBattlerTarget = SetRandomTarget(sBattler_AI);
}

u8 BattleAI_ChooseMoveOrAction(void)
{
    u32 savedCurrentMove = gCurrentMove;
    u8 ret;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        ret = ChooseMoveOrAction_Singles();
    else
        ret = ChooseMoveOrAction_Doubles();

    gCurrentMove = savedCurrentMove;
    return ret;
}

static u32 GetTotalBaseStat(u32 species)
{
    return gBaseStats[species].baseHP
        + gBaseStats[species].baseAttack
        + gBaseStats[species].baseDefense
        + gBaseStats[species].baseSpeed
        + gBaseStats[species].baseSpAttack
        + gBaseStats[species].baseSpDefense;
}

bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler)
{
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = gBattleResources->battleHistory->usedMoves[opposingBattler][i];
        if (gBattleMoves[move].effect == EFFECT_PROTECT && move != MOVE_ENDURE)
            return TRUE;
        if (gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE && GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 1)
            return TRUE;
    }
    return FALSE;
}

static void GetAiLogicData(u8 battlerAtk, u8 battlerDef)
{
    // attacker data
    AI_DATA->atkAbility = AI_GetAbility(battlerAtk);
    AI_DATA->atkItem = gBattleMons[battlerAtk].item;
    AI_DATA->atkHoldEffect = AI_GetHoldEffect(battlerAtk);
    AI_DATA->atkParam = GetBattlerHoldEffectParam(battlerAtk);
    AI_DATA->atkSpecies = gBattleMons[battlerAtk].species;
    // target data
    AI_DATA->defAbility = AI_GetAbility(battlerDef);
    AI_DATA->defItem = (AI_GetHoldEffect(battlerDef) == HOLD_EFFECT_NONE) ? ITEM_NONE : gBattleMons[battlerDef].item;
    AI_DATA->defHoldEffect = AI_GetHoldEffect(battlerDef);
    AI_DATA->defParam = GetBattlerHoldEffectParam(battlerDef);
    AI_DATA->defSpecies = gBattleMons[battlerDef].species;
    // attacker partner data
    AI_DATA->battlerAtkPartner = BATTLE_PARTNER(battlerAtk);
    AI_DATA->partnerMove = GetAllyChosenMove();
    AI_DATA->atkPartnerAbility = AI_GetAbility(AI_DATA->battlerAtkPartner);
    AI_DATA->atkPartnerHoldEffect = AI_GetHoldEffect(AI_DATA->battlerAtkPartner);
    AI_DATA->targetSameSide = IsTargetingPartner(battlerAtk, battlerDef);
    // target partner data
    AI_DATA->battlerDefPartner = BATTLE_PARTNER(battlerDef);
    AI_DATA->defPartnerAbility = AI_GetAbility(AI_DATA->battlerDefPartner);
    AI_DATA->defPartnerHoldEffect = AI_GetHoldEffect(AI_DATA->battlerDefPartner);
}

static u8 ChooseMoveOrAction_Singles(void)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u32 numOfBestMoves;
    s32 i, id;
    u32 flags = AI_THINKING_STRUCT->aiFlags;

    RecordLastUsedMoveByTarget();
    GetAiLogicData(sBattler_AI, gBattlerTarget);
    
    while (flags != 0)
    {
        if (flags & 1)
        {
            AI_THINKING_STRUCT->aiState = AIState_SettingUp;
            BattleAI_DoAIProcessing();
        }
        flags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
        AI_THINKING_STRUCT->movesetIndex = 0;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
        gBattleStruct->aiFinalScore[sBattler_AI][gBattlerTarget][i] = AI_THINKING_STRUCT->score[i];

    // Check special AI actions.
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
        return AI_CHOICE_FLEE;
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
        return AI_CHOICE_WATCH;

    gActiveBattler = sBattler_AI;
    // If can switch.
    if (CountUsablePartyMons(sBattler_AI) > 0
        && !IsAbilityPreventingEscape(sBattler_AI)
        && !(gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        && !(gStatuses3[gActiveBattler] & STATUS3_ROOTED)
        && !(gBattleTypeFlags & (BATTLE_TYPE_ARENA | BATTLE_TYPE_PALACE))
        && AI_THINKING_STRUCT->aiFlags & (AI_FLAG_CHECK_GOOD_MOVE | AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_PREFER_BATON_PASS))
    {
        // Consider switching if all moves are worthless to use.
        if (GetTotalBaseStat(gBattleMons[sBattler_AI].species) >= 310 // Mon is not weak.
            && gBattleMons[sBattler_AI].hp >= gBattleMons[sBattler_AI].maxHP / 2)
        {
            s32 cap = AI_THINKING_STRUCT->aiFlags & (AI_FLAG_CHECK_GOOD_MOVE) ? 95 : 93;
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (AI_THINKING_STRUCT->score[i] > cap)
                    break;
            }

            if (i == MAX_MON_MOVES && GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
            {
                AI_THINKING_STRUCT->switchMon = TRUE;
                return AI_CHOICE_SWITCH;
            }
        }

        // Consider switching if your mon with truant is bodied by Protect spam.
        // Or is using a double turn semi invulnerable move(such as Fly) and is faster.
        if (GetBattlerAbility(sBattler_AI) == ABILITY_TRUANT
            && IsTruantMonVulnerable(sBattler_AI, gBattlerTarget)
            && gDisableStructs[sBattler_AI].truantCounter
            && gBattleMons[sBattler_AI].hp >= gBattleMons[sBattler_AI].maxHP / 2)
        {
            if (GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
            {
                AI_THINKING_STRUCT->switchMon = TRUE;
                return AI_CHOICE_SWITCH;
            }
        }
    }

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[sBattler_AI].moves[i] != MOVE_NONE)
        {
            // In ruby, the order of these if statements is reversed.
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

static u8 ChooseMoveOrAction_Doubles(void)
{
    s32 i, j;
    u32 flags;
    s16 bestMovePointsForTarget[MAX_BATTLERS_COUNT];
    s8 mostViableTargetsArray[MAX_BATTLERS_COUNT];
    u8 actionOrMoveIndex[MAX_BATTLERS_COUNT];
    u8 mostViableMovesScores[MAX_MON_MOVES];
    u8 mostViableMovesIndices[MAX_MON_MOVES];
    s32 mostViableTargetsNo;
    s32 mostViableMovesNo;
    s16 mostMovePoints;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i == sBattler_AI || gBattleMons[i].hp == 0)
        {
            actionOrMoveIndex[i] = 0xFF;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->palaceFlags >> 4);
            else
                BattleAI_SetupAIData((1 << MAX_MON_MOVES) - 1);

            gBattlerTarget = i;

            if ((i & BIT_SIDE) != (sBattler_AI & BIT_SIDE))
                RecordLastUsedMoveByTarget();

            AI_THINKING_STRUCT->aiLogicId = 0;
            AI_THINKING_STRUCT->movesetIndex = 0;
            flags = AI_THINKING_STRUCT->aiFlags;
            while (flags != 0)
            {
                if (flags & 1)
                {
                    AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    BattleAI_DoAIProcessing();
                }
                flags >>= 1;
                AI_THINKING_STRUCT->aiLogicId++;
                AI_THINKING_STRUCT->movesetIndex = 0;
            }

            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
            {
                actionOrMoveIndex[i] = AI_CHOICE_FLEE;
            }
            else if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
            {
                actionOrMoveIndex[i] = AI_CHOICE_WATCH;
            }
            else
            {
                mostViableMovesScores[0] = AI_THINKING_STRUCT->score[0];
                mostViableMovesIndices[0] = 0;
                mostViableMovesNo = 1;
                for (j = 1; j < MAX_MON_MOVES; j++)
                {
                    if (gBattleMons[sBattler_AI].moves[j] != 0)
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
                }
                actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
                bestMovePointsForTarget[i] = mostViableMovesScores[0];

                // Don't use a move against ally if it has less than 100 points.
                if (i == (sBattler_AI ^ BIT_FLANK) && bestMovePointsForTarget[i] < 100)
                {
                    bestMovePointsForTarget[i] = -1;
                    mostViableMovesScores[0] = mostViableMovesScores[0]; // Needed to match.
                }
            }

            for (j = 0; j < MAX_MON_MOVES; j++)
                gBattleStruct->aiFinalScore[sBattler_AI][gBattlerTarget][j] = AI_THINKING_STRUCT->score[j];
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < MAX_BATTLERS_COUNT; i++)
    {
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattlerTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    return actionOrMoveIndex[gBattlerTarget];
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
                if (gBattleMons[sBattler_AI].pp[AI_THINKING_STRUCT->movesetIndex] == 0)
                {
                    AI_THINKING_STRUCT->moveConsidered = 0;
                }
                else
                {
                    AI_THINKING_STRUCT->moveConsidered = gBattleMons[sBattler_AI].moves[AI_THINKING_STRUCT->movesetIndex];
                }
                AI_THINKING_STRUCT->aiState++;
                break;
            case AIState_Processing:
                if (AI_THINKING_STRUCT->moveConsidered != MOVE_NONE)
                {
                    if (AI_THINKING_STRUCT->aiLogicId < ARRAY_COUNT(sBattleAiFuncTable) && sBattleAiFuncTable[AI_THINKING_STRUCT->aiLogicId] != NULL)
                    {
                        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += sBattleAiFuncTable[AI_THINKING_STRUCT->aiLogicId](sBattler_AI,
                          gBattlerTarget, AI_THINKING_STRUCT->moveConsidered, AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex]);
                        if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0)
                            AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;    // limit to 0
                    }
                }
                else
                {
                    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;
                    AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
                }
                
                if (AI_THINKING_STRUCT->aiAction & AI_ACTION_DONE)
                {
                   AI_THINKING_STRUCT->movesetIndex++;

                    if (AI_THINKING_STRUCT->movesetIndex < MAX_MON_MOVES && !(AI_THINKING_STRUCT->aiAction & AI_ACTION_DO_NOT_ATTACK))
                        AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    else
                        AI_THINKING_STRUCT->aiState++;

                    AI_THINKING_STRUCT->aiAction &= ~(AI_ACTION_DONE);
                }
                break;
        }
    }
}

static void Cmd_if_random_less_than(void)
{
    u16 random = Random();

    if (random % 256 < gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_greater_than(void)
{
    u16 random = Random();

    if (random % 256 > gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_equal(void)
{
    u16 random = Random();

    if (random % 256 == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_not_equal(void)
{
    u16 random = Random();

    if (random % 256 != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_score(void)
{
    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += gAIScriptPtr[1]; // Add the result to the array of the move consider's score.

    if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0) // If the score is negative, flatten it to 0.
        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;

    gAIScriptPtr += 2; // AI return.
}

static u8 BattleAI_GetWantedBattler(u8 wantedBattler)
{
    switch (wantedBattler)
    {
    case AI_USER:
        return sBattler_AI;
    case AI_TARGET:
    default:
        return gBattlerTarget;
    case AI_USER_PARTNER:
        return sBattler_AI ^ BIT_FLANK;
    case AI_TARGET_PARTNER:
        return gBattlerTarget ^ BIT_FLANK;
    }
}

static void Cmd_if_hp_less_than(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_more_than(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_equal(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_not_equal(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_status(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if (gBattleMons[battlerId].status1 & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gBattleMons[battlerId].status1 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_status2(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if ((gBattleMons[battlerId].status2 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status2(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gBattleMons[battlerId].status2 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_status3(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if (gStatuses3[battlerId] & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status3(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gStatuses3[battlerId] & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_side_affecting(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);
    u32 side = GET_BATTLER_SIDE(battlerId);

    if (gSideStatuses[side] & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_side_affecting(void)
{
    u16 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 status = T1_READ_32(gAIScriptPtr + 2);
    u32 side = GET_BATTLER_SIDE(battlerId);

    if (!(gSideStatuses[side] & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_less_than(void)
{
    if (AI_THINKING_STRUCT->funcResult < gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_more_than(void)
{
    if (AI_THINKING_STRUCT->funcResult > gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_not_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_less_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_more_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_not_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_move(void)
{
    u16 move = T1_READ_16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered == move)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_not_move(void)
{
    u16 move = T1_READ_16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered != move)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void Cmd_if_not_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
}

static void Cmd_if_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void Cmd_if_not_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
}

static void Cmd_if_user_has_attacking_move(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[sBattler_AI].moves[i] != 0
            && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].power != 0)
            break;
    }

    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_if_user_has_no_attacking_moves(void)
{
    //HasDamagingMove
}

static void Cmd_get_turn_count(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleResults.battleTurnCounter;
    gAIScriptPtr += 1;
}

static void Cmd_get_type(void)
{
    u8 typeVar = gAIScriptPtr[1];

    switch (typeVar)
    {
    case AI_TYPE1_USER: // AI user primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBattler_AI].type1;
        break;
    case AI_TYPE1_TARGET: // target primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattlerTarget].type1;
        break;
    case AI_TYPE2_USER: // AI user secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBattler_AI].type2;
        break;
    case AI_TYPE2_TARGET: // target secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattlerTarget].type2;
        break;
    case AI_TYPE_MOVE: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

static void Cmd_is_of_type(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (IS_BATTLER_OF_TYPE(battlerId, gAIScriptPtr[2]))
        AI_THINKING_STRUCT->funcResult = TRUE;
    else
        AI_THINKING_STRUCT->funcResult = FALSE;

    gAIScriptPtr += 3;
}

static void Cmd_get_considered_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}



static void Cmd_get_how_powerful_move_is(void)
{
    // GetMoveDamageResult
}

static void Cmd_get_last_used_battler_move(void)
{
    AI_THINKING_STRUCT->funcResult = gLastMoves[BattleAI_GetWantedBattler(gAIScriptPtr[1])];
    gAIScriptPtr += 2;
}

static void Cmd_if_equal_u32(void)
{
    if (T1_READ_32(&gAIScriptPtr[1]) == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_not_equal_u32(void)
{
    if (T1_READ_32(&gAIScriptPtr[1]) != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_user_goes(void)
{
    // IsAiFaster
}

static void Cmd_nullsub_2A(void)
{
}

static void Cmd_nullsub_2B(void)
{
}

static void Cmd_count_usable_party_mons(void)
{
    AI_THINKING_STRUCT->funcResult = CountUsablePartyMons(BattleAI_GetWantedBattler(gAIScriptPtr[1]));
    gAIScriptPtr += 2;
}

static void Cmd_get_considered_move(void)
{
    AI_THINKING_STRUCT->funcResult = AI_THINKING_STRUCT->moveConsidered;
    gAIScriptPtr += 1;
}

static void Cmd_get_considered_move_effect(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;
    gAIScriptPtr += 1;
}

static void Cmd_get_ability(void)
{
    //AI_THINKING_STRUCT->funcResult = AI_GetAbility(BattleAI_GetWantedBattler(gAIScriptPtr[1]), TRUE);
    gAIScriptPtr += 2;
}

static void Cmd_check_ability(void)
{
    /*u32 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 ability = AI_GetAbility(battlerId, FALSE);

    if (ability == -1)
        AI_THINKING_STRUCT->funcResult = 2; // Unable to answer.
    else if (ability == gAIScriptPtr[2])
        AI_THINKING_STRUCT->funcResult = 1; // Pokemon has the ability we wanted to check.
    else
        AI_THINKING_STRUCT->funcResult = 0; // Pokemon doesn't have the ability we wanted to check.

    gAIScriptPtr += 3;*/
}

static void Cmd_get_highest_type_effectiveness(void)
{
    s32 i;

    gMoveResultFlags = 0;
    AI_THINKING_STRUCT->funcResult = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gCurrentMove = gBattleMons[sBattler_AI].moves[i];
        if (gCurrentMove != MOVE_NONE)
        {
            u32 effectivenessMultiplier = AI_GetTypeEffectiveness(gCurrentMove, sBattler_AI, gBattlerTarget);

            switch (effectivenessMultiplier)
            {
            case UQ_4_12(0.0):
            default:
                gBattleMoveDamage = AI_EFFECTIVENESS_x0;
                break;
            case UQ_4_12(0.25):
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;
                break;
            case UQ_4_12(0.5):
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
                break;
            case UQ_4_12(1.0):
                gBattleMoveDamage = AI_EFFECTIVENESS_x1;
                break;
            case UQ_4_12(2.0):
                gBattleMoveDamage = AI_EFFECTIVENESS_x2;
                break;
            case UQ_4_12(4.0):
                gBattleMoveDamage = AI_EFFECTIVENESS_x4;
                break;
            }

            if (AI_THINKING_STRUCT->funcResult < gBattleMoveDamage)
                AI_THINKING_STRUCT->funcResult = gBattleMoveDamage;
        }
    }

    gAIScriptPtr += 1;
}

static void Cmd_if_type_effectiveness(void)
{
    // AI_GetMoveEffectiveness
}

static void Cmd_nullsub_32(void)
{
}

static void Cmd_nullsub_33(void)
{
}

static void Cmd_if_status_in_party(void)
{
    struct Pokemon *party;
    s32 i;
    u32 statusToCompareTo;
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    party = (GetBattlerSide(battlerId) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = T1_READ_32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
            return;
        }
    }

    gAIScriptPtr += 10;
}

static void Cmd_if_status_not_in_party(void)
{
    struct Pokemon *party;
    s32 i;
    u32 statusToCompareTo;
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    party = (GetBattlerSide(battlerId) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = T1_READ_32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr += 10;
            return;
        }
    }

    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
}

static void Cmd_get_weather(void)
{
    if (gBattleWeather & WEATHER_RAIN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_RAIN;
    else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SANDSTORM;
    else if (gBattleWeather & WEATHER_SUN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SUN;
    else if (gBattleWeather & WEATHER_HAIL_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_HAIL;
    else
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_NONE;

    gAIScriptPtr += 1;
}

static void Cmd_if_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == T1_READ_16(gAIScriptPtr + 1))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_not_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect != T1_READ_16(gAIScriptPtr + 1))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_stat_level_less_than(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] < gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_more_than(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] > gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_equal(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] == gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_not_equal(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] != gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_can_faint(void)
{
    s32 dmg;

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power == 0)
    {
        gAIScriptPtr += 5;
        return;
    }

    dmg = AI_THINKING_STRUCT->simulatedDmg[sBattler_AI][gBattlerTarget][AI_THINKING_STRUCT->movesetIndex];
    if (gBattleMons[gBattlerTarget].hp <= dmg)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_cant_faint(void)
{
    s32 dmg;

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    dmg = AI_THINKING_STRUCT->simulatedDmg[sBattler_AI][gBattlerTarget][AI_THINKING_STRUCT->movesetIndex];
    if (gBattleMons[gBattlerTarget].hp > dmg)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_has_move(void)
{
    s32 i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] == *movePtr)
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_USER_PARTNER:
        if (gBattleMons[sBattler_AI ^ BIT_FLANK].hp == 0)
        {
            gAIScriptPtr += 8;
            break;
        }
        else
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[sBattler_AI ^ BIT_FLANK].moves[i] == *movePtr)
                    break;
            }
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget][i] == *movePtr)
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    }
}

static void Cmd_if_doesnt_have_move(void)
{
    s32 i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER: // UB: no separate check for user partner.
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] == *movePtr)
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget][i] == *movePtr)
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    }
}

static void Cmd_if_has_move_with_effect(void)
{
    s32 i;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBattlerTarget].moves[i] != 0 && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattlerTarget][i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_doesnt_have_move_with_effect(void)
{
    s32 i;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if(gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget][i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattlerTarget][i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_any_move_disabled_or_encored(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gAIScriptPtr[2] == 0)
    {
        if (gDisableStructs[battlerId].disabledMove == MOVE_NONE)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    }
    else if (gAIScriptPtr[2] != 1)
    {
        gAIScriptPtr += 7;
    }
    else
    {
        if (gDisableStructs[battlerId].encoredMove != MOVE_NONE)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        else
            gAIScriptPtr += 7;
    }
}

static void Cmd_if_curr_move_disabled_or_encored(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0:
        if (gDisableStructs[gActiveBattler].disabledMove == AI_THINKING_STRUCT->moveConsidered)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1:
        if (gDisableStructs[gActiveBattler].encoredMove == AI_THINKING_STRUCT->moveConsidered)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    default:
        gAIScriptPtr += 6;
        break;
    }
}

static void Cmd_flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void Cmd_if_random_safari_flee(void)
{
    u8 safariFleeRate = gBattleStruct->safariEscapeFactor * 5; // Safari flee rate, from 0-20.

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

static void Cmd_get_hold_effect(void)
{
    // AI_GetHoldEffect
}

static void Cmd_if_holds_item(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u16 item;

    if ((battlerId & BIT_SIDE) == (sBattler_AI & BIT_SIDE))
        item = gBattleMons[battlerId].item;
    else
        item = BATTLE_HISTORY->itemEffects[battlerId];

    if (T1_READ_16(gAIScriptPtr + 2) == item)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_get_gender(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerId].species, gBattleMons[battlerId].personality);

    gAIScriptPtr += 2;
}

static void Cmd_is_first_turn_for(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].isFirstTurn;

    gAIScriptPtr += 2;
}

static void Cmd_get_stockpile_count(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].stockpileCounter;

    gAIScriptPtr += 2;
}

static void Cmd_is_double_battle(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;

    gAIScriptPtr += 1;
}

static void Cmd_get_used_held_item(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gBattleStruct->usedHeldItems[battlerId];

    gAIScriptPtr += 2;
}

static void Cmd_get_move_type_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].type;

    gAIScriptPtr += 1;
}

static void Cmd_get_move_power_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].power;

    gAIScriptPtr += 1;
}

static void Cmd_get_move_effect_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].effect;

    gAIScriptPtr += 1;
}

static void Cmd_get_protect_count(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].protectUses;

    gAIScriptPtr += 2;
}

static void Cmd_if_move_flag(void)
{
    u32 flag = T1_READ_32(gAIScriptPtr + 1);

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].flags & flag)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_field_status(void)
{
    u32 fieldFlags = T1_READ_32(gAIScriptPtr + 1);

    if (gFieldStatuses & fieldFlags)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_get_move_accuracy(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].accuracy;

    gAIScriptPtr++;
}

static void Cmd_call_if_eq(void)
{
    if (AI_THINKING_STRUCT->funcResult == T1_READ_16(gAIScriptPtr + 1))
    {
        AIStackPushVar(gAIScriptPtr + 7);
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    }
    else
    {
        gAIScriptPtr += 7;
    }
}

static void Cmd_call_if_move_flag(void)
{
    u32 flag = T1_READ_32(gAIScriptPtr + 1);

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].flags & flag)
    {
        AIStackPushVar(gAIScriptPtr + 9);
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    }
    else
    {
        gAIScriptPtr += 9;
    }
}

static void Cmd_nullsub_57(void)
{
}

static void Cmd_call(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_goto(void)
{
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_end(void)
{
    if (AIStackPop() == 0)
        AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
}

static void Cmd_if_level_cond(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // greater than
        if (gBattleMons[sBattler_AI].level > gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1: // less than
        if (gBattleMons[sBattler_AI].level < gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 2: // equal
        if (gBattleMons[sBattler_AI].level == gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    }
}

static void Cmd_if_target_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_target_not_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_target_is_ally(void)
{
    if ((sBattler_AI & BIT_SIDE) == (gBattlerTarget & BIT_SIDE))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_flash_fired(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (gBattleResources->flags->flags[battlerId] & RESOURCE_FLAG_FLASH_FIRE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
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
    {
        return FALSE;
    }
}

static void Cmd_get_ally_chosen_move(void)
{
    // GetAllyChosenMove
}

static void Cmd_if_has_no_attacking_moves(void)
{
    s32 i;
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    if (IsBattlerAIControlled(battlerId))
    {
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[battlerId].moves[i] != 0 && gBattleMoves[gBattleMons[battlerId].moves[i]].power != 0)
                break;
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (BATTLE_HISTORY->usedMoves[battlerId][i] != 0 && gBattleMoves[BATTLE_HISTORY->usedMoves[battlerId][i]].power != 0)
                break;
        }
    }

    if (i == 4)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_get_hazards_count(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u8 side = GetBattlerSide(battlerId);

    switch (T1_READ_16(gAIScriptPtr + 2))
    {
    case EFFECT_SPIKES:
        AI_THINKING_STRUCT->funcResult = gSideTimers[side].spikesAmount;
        break;
    case EFFECT_TOXIC_SPIKES:
        AI_THINKING_STRUCT->funcResult = gSideTimers[side].toxicSpikesAmount;
        break;
    }

    gAIScriptPtr += 4;
}

static void Cmd_if_doesnt_hold_berry(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u16 item;

    if (IsBattlerAIControlled(battlerId))
        item = gBattleMons[battlerId].item;
    else
        item = BATTLE_HISTORY->itemEffects[battlerId];

    if (ItemId_GetPocket(item) == POCKET_BERRIES)
        gAIScriptPtr += 6;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
}

static void Cmd_if_share_type(void)
{
    u8 battler1 = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u8 battler2 = BattleAI_GetWantedBattler(gAIScriptPtr[2]);

    if (DoBattlersShareType(battler1, battler2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_cant_use_last_resort(void)
{
    u8 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (CanUseLastResort(battler))
        gAIScriptPtr += 6;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
}

static void Cmd_if_has_move_with_split(void)
{
    if (HasMoveWithSplit(BattleAI_GetWantedBattler(gAIScriptPtr[1]), gAIScriptPtr[2]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_has_no_move_with_split(void)
{
    if (!HasMoveWithSplit(BattleAI_GetWantedBattler(gAIScriptPtr[1]), gAIScriptPtr[2]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_physical_moves_unusable(void)
{
    if (MovesWithSplitUnusable(BattleAI_GetWantedBattler(gAIScriptPtr[1]), BattleAI_GetWantedBattler(gAIScriptPtr[2]), SPLIT_PHYSICAL))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

// Check if target has means to faint ai mon.
static void Cmd_if_ai_can_go_down(void)
{
    // CanTargetFaintAi
}

static void Cmd_if_cant_use_belch(void)
{
    u32 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (gBattleStruct->ateBerry[battler & BIT_SIDE] & gBitTable[gBattlerPartyIndexes[battler]])
        gAIScriptPtr += 6;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
}

static void Cmd_if_has_move_with_type(void)
{
    u32 i, moveType, battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < 4; i++)
    {
        if (moves[i] == MOVE_NONE)
            continue;

        SetTypeBeforeUsingMove(moves[i], battler);
        GET_MOVE_TYPE(moves[i], moveType);
        if (moveType == gAIScriptPtr[2])
            break;
    }

    if (i == 4)
        gAIScriptPtr += 7;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
}

static void Cmd_if_has_move_with_flag(void)
{
    u32 i, flag, battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u16 *moves = GetMovesArray(battler);

    flag = T1_READ_32(gAIScriptPtr + 2);
    for (i = 0; i < 4; i++)
    {
        if (moves[i] != MOVE_NONE && gBattleMoves[moves[i]].flags & flag)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
            return;
        }
    }

    gAIScriptPtr += 10;
}

static void Cmd_if_no_move_used(void)
{
    u32 i, battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (!IsBattlerAIControlled(battler))
    {
        for (i = 0; i < 4; i++)
        {
            if (BATTLE_HISTORY->usedMoves[battler][i] != 0 && BATTLE_HISTORY->usedMoves[battler][i] != 0xFFFF)
            {
                gAIScriptPtr += 6;
                return;
            }
        }
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    }
    else
    {
        gAIScriptPtr += 6;
    }
}

static void Cmd_if_battler_absent(void)
{
    u32 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (!IsBattlerAlive(battler))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_is_grounded(void)
{
    u32 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (IsBattlerGrounded(battler))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_get_best_dmg_hp_percent(void)
{
    int i, bestDmg;

    bestDmg = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleResources->ai->simulatedDmg[sBattler_AI][gBattlerTarget][i] > bestDmg)
            bestDmg = gBattleResources->ai->simulatedDmg[sBattler_AI][gBattlerTarget][i];
    }

    gBattleResources->ai->funcResult = (bestDmg * 100) / gBattleMons[gBattlerTarget].maxHP;
    gAIScriptPtr++;
}

static void Cmd_get_curr_dmg_hp_percent(void)
{
    int bestDmg = gBattleResources->ai->simulatedDmg[sBattler_AI][gBattlerTarget][AI_THINKING_STRUCT->movesetIndex];

    gBattleResources->ai->funcResult = (bestDmg * 100) / gBattleMons[gBattlerTarget].maxHP;
    gAIScriptPtr++;
}

static void Cmd_get_move_split_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = GetBattleMoveSplit(AI_THINKING_STRUCT->funcResult);
    gAIScriptPtr += 1;
}

static void Cmd_get_considered_move_split(void)
{
    AI_THINKING_STRUCT->funcResult = GetBattleMoveSplit(AI_THINKING_STRUCT->moveConsidered);
    gAIScriptPtr += 1;
}

static void Cmd_get_considered_move_target(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].target;
    gAIScriptPtr += 1;
}

static void Cmd_compare_speeds(void)
{
    u8 battler1 = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u8 battler2 = BattleAI_GetWantedBattler(gAIScriptPtr[2]);
    AI_THINKING_STRUCT->funcResult = GetWhoStrikesFirst(battler1, battler2, TRUE);
    gAIScriptPtr += 3;
}

static void Cmd_is_wakeup_turn(void)
{
    //IsWakeupTurn
}

static void Cmd_if_has_move_with_accuracy_lt(void)
{
    u32 i;
    u32 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 toCmp = gAIScriptPtr[2];
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE
            && gBattleMoves[moves[i]].effect != EFFECT_OHKO
            && gBattleMoves[moves[i]].accuracy > 1
            && gBattleMoves[moves[i]].accuracy < toCmp)
            break;
    }

    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 7;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
}




// AI Functions
static s16 AI_CheckBadMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    // move data
    u8 atkPriority = GetMovePriority(battlerAtk, move);
    u16 moveEffect = gBattleMoves[move].effect;
    u8 moveType = gBattleMoves[move].type;
    u8 moveTarget = gBattleMoves[move].target;
    u16 accuracy = AI_GetMoveAccuracy(battlerAtk, battlerDef, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect, move);
    u8 effectiveness = AI_GetMoveEffectiveness(move);
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;
    u16 predictedMove = gLastMoves[battlerDef]; // TODO better move prediction
    
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_HELP_PARTNER) && AI_DATA->targetSameSide)
        return score;   // don't consider ally presence
    
    if (!(gBattleMoves[move].target & MOVE_TARGET_USER))
    {
        // handle negative checks on non-user target
        // check powder moves
        if (TestMoveFlags(move, FLAG_POWDER))
        {
            if (!IsAffectedByPowder(battlerDef, AI_DATA->defAbility, AI_DATA->defHoldEffect))
                score -= 10;
        }
        
        // check ground immunities
        if (moveType == TYPE_GROUND
          && !IsBattlerGrounded(battlerDef)
          && ((AI_DATA->defAbility == ABILITY_LEVITATE
          && DoesBattlerIgnoreAbilityChecks(AI_DATA->atkAbility, move))
          || AI_DATA->defHoldEffect == HOLD_EFFECT_AIR_BALLOON
          || (gStatuses3[battlerDef] & (STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS)))
          && move != MOVE_THOUSAND_ARROWS)
        {
            score -= 10;
        }
                
        // check if negates type
        if (effectiveness == AI_EFFECTIVENESS_x0)
            score -= 20;
        
        // target ability checks
        if (!DoesBattlerIgnoreAbilityChecks(battlerAtk, move))
        {
            switch (AI_DATA->defAbility)
            {
            case ABILITY_VOLT_ABSORB:
            case ABILITY_MOTOR_DRIVE:
            case ABILITY_LIGHTNING_ROD:
                if (moveType == TYPE_ELECTRIC && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 20;
                break;
            case ABILITY_WATER_ABSORB:
            case ABILITY_DRY_SKIN:
            case ABILITY_STORM_DRAIN:
                if (moveType == TYPE_WATER && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 20;
                break;
            case ABILITY_FLASH_FIRE:
                if (moveType == TYPE_FIRE && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 20;
                break;
            case ABILITY_WONDER_GUARD:
                if (effectiveness != AI_EFFECTIVENESS_x2 && effectiveness != AI_EFFECTIVENESS_x4)
                    return 0;
                break;
            case ABILITY_SAP_SIPPER:
                if (moveType == TYPE_GRASS && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 20;
                break;
            case ABILITY_JUSTIFIED:
                if (moveType == TYPE_DARK && !IS_MOVE_STATUS(move) && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 10;
                break;
            case ABILITY_RATTLED:
                if (!IS_MOVE_STATUS(move)
                  && (moveType == TYPE_DARK || moveType == TYPE_GHOST || moveType == TYPE_BUG)
                  && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 10;
                break;
            case ABILITY_SOUNDPROOF:
                if (TestMoveFlags(move, FLAG_SOUND))
                    score -= 10;
                break;
            case ABILITY_BULLETPROOF:
                if (TestMoveFlags(move, FLAG_BALLISTIC))
                    score -= 10;
                break;
            case ABILITY_DAZZLING:
            case ABILITY_QUEENLY_MAJESTY:
                if (atkPriority > 0)
                    score -= 10;
                break;
            case ABILITY_AROMA_VEIL:
                if (IsAromaVeilProtectedMove(move))
                    score -= 10;
                break;
            case ABILITY_SWEET_VEIL:
                if (moveEffect == EFFECT_SLEEP || moveEffect == EFFECT_YAWN)
                    score -= 10;
                break;
            case ABILITY_FLOWER_VEIL:
                if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS) && (IsNonVolatileStatusMoveEffect(moveEffect) || IsStatLoweringMoveEffect(moveEffect)))
                    score -= 10;
                break;
            case ABILITY_MAGIC_BOUNCE:
                if (TestMoveFlags(move, FLAG_MAGICCOAT_AFFECTED))
                    score -= 20;
                break;
            case ABILITY_CONTRARY:
                if (IsStatLoweringMoveEffect(moveEffect) && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 20;
                break;
            case ABILITY_CLEAR_BODY:
            //case ABILITY_FULL_METAL_BODY: // maybe?
            case ABILITY_WHITE_SMOKE:
                if (IsStatLoweringMoveEffect(moveEffect))
                    score -= 10;
                break;
            case ABILITY_HYPER_CUTTER:
                if ((moveEffect == EFFECT_ATTACK_DOWN ||  moveEffect == EFFECT_ATTACK_DOWN_2)
                  && move != MOVE_PLAY_NICE && move != MOVE_NOBLE_ROAR && move != MOVE_TEARFUL_LOOK && move != MOVE_VENOM_DRENCH)
                    score -= 10;
                break;
            case ABILITY_KEEN_EYE:
                if (moveEffect == EFFECT_ACCURACY_DOWN || moveEffect == EFFECT_ACCURACY_DOWN_2)
                    score -= 10;
                break;
            case ABILITY_BIG_PECKS:
                if (moveEffect == EFFECT_DEFENSE_DOWN || moveEffect == EFFECT_DEFENSE_DOWN_2)
                    score -= 10;
                break;
            case ABILITY_DEFIANT:
            case ABILITY_COMPETITIVE:
                if (IsStatLoweringMoveEffect(moveEffect) && !IsTargetingPartner(battlerAtk, battlerDef))
                    score -= 8;
                break;
            case ABILITY_COMATOSE:
                if (IsNonVolatileStatusMoveEffect(moveEffect))
                    score -= 10;
                break;
            case ABILITY_SHIELDS_DOWN:
                if (IsShieldsDownProtected(battlerAtk) && IsNonVolatileStatusMoveEffect(moveEffect))
                    score -= 10;
                break;
            case ABILITY_WONDER_SKIN:
                if (IS_MOVE_STATUS(move))
                    accuracy = 50;
                break;
            case ABILITY_LEAF_GUARD:
                if (AI_WeatherHasEffect() && (gBattleWeather & WEATHER_SUN_ANY)
                  && AI_DATA->defHoldEffect != HOLD_EFFECT_UTILITY_UMBRELLA
                  && IsNonVolatileStatusMoveEffect(moveEffect))
                    score -= 10;
                break;
            } // def ability checks
            
            // target partner ability checks
            if (isDoubleBattle && !IsTargetingPartner(battlerAtk, battlerDef))
            {
                switch (AI_DATA->defPartnerAbility)
                {
                case ABILITY_LIGHTNING_ROD:
                    if (moveType == TYPE_ELECTRIC && !IsMoveRedirectionPrevented(move, AI_DATA->atkAbility))
                        score -= 20;
                    break;
                case ABILITY_STORM_DRAIN:
                    if (moveType == TYPE_WATER && !IsMoveRedirectionPrevented(move, AI_DATA->atkAbility))
                        score -= 20;
                    break;
                case ABILITY_MAGIC_BOUNCE:
                    if (TestMoveFlags(move, FLAG_MAGICCOAT_AFFECTED) && moveTarget & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD))
                        score -= 20;
                    break;
                case ABILITY_SWEET_VEIL:
                    if (moveEffect == EFFECT_SLEEP || moveEffect == EFFECT_YAWN)
                        score -= 10;
                    break;
                case ABILITY_FLOWER_VEIL:
                    if ((IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)) && (IsNonVolatileStatusMoveEffect(moveEffect) || IsStatLoweringMoveEffect(moveEffect)))
                        score -= 10;
                    break;
                case ABILITY_AROMA_VEIL:
                    if (IsAromaVeilProtectedMove(move))
                        score -= 10;
                    break;
                case ABILITY_DAZZLING:
                case ABILITY_QUEENLY_MAJESTY:
                    if (atkPriority > 0)
                        score -= 10;
                    break;
                }
            } // def partner ability checks
        } // ignore def ability check
    
        #if B_PRANKSTER < GEN_7
        if (AI_DATA->atkAbility == ABILITY_PRANKSTER && IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK) && IS_MOVE_STATUS(move)
          && !(moveTarget & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_USER)))
            score -= 10;
        #endif
        
        // terrain effect checks
        if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        {
            if (moveEffect == EFFECT_SLEEP || moveEffect == EFFECT_YAWN)
                score -= 10;
        }
        if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        {
            if (IsNonVolatileStatusMoveEffect(moveEffect) || IsConfusionMoveEffect(moveEffect))
                score -= 10;
        }
        if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        {
            if (atkPriority > 0)
                score -= 10;
        }    
    } // end check MOVE_TARGET_USER
// the following checks apply to any target (including user)
    
    // throat chop check
    if (gDisableStructs[battlerAtk].throatChopTimer && TestMoveFlags(move, FLAG_SOUND))
        return 0; // Can't even select move at all
    // heal block check
    if (gStatuses3[battlerAtk] & STATUS3_HEAL_BLOCK && IsHealBlockPreventingMove(battlerAtk, move))
        return 0; // Can't even select heal blocked move
    // primal weather check
    //TODO
    
    // check move effects
    switch (moveEffect)
    {
        case EFFECT_HIT:
        default:
            break;
        case EFFECT_SLEEP:
            if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                score -= 10;
            else if (!AI_CanPutToSleep(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_ABSORB:
            if (AI_DATA->defAbility == ABILITY_LIQUID_OOZE)
                score -= 6;
            break;
        case EFFECT_STRENGTH_SAP:
            if (AI_DATA->defAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (!BattlerStatCanFall(battlerDef, AI_DATA->defAbility, STAT_ATK))
                score -= 10;
            break;
        case EFFECT_EXPLOSION:
            if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_WILL_SUICIDE)
            {
                if (IsAbilityOnField(ABILITY_DAMP) && !DoesBattlerIgnoreAbilityChecks(AI_DATA->atkAbility, move))
                {
                    score -= 10;
                }
                else if (CountUsablePartyMons(battlerDef) == 0 && CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
                {
                    ; // target has 1 pkmn left but you can faint it -> good to use
                }
                else if (isDoubleBattle)
                {
                    if (CountUsablePartyMons(battlerDef) != 0
                      && CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0)
                      && CanAttackerFaintTarget(AI_DATA->battlerAtkPartner, BATTLE_PARTNER(battlerDef), *(gBattleStruct->chosenMovePositions + AI_DATA->battlerAtkPartner), 0))
                    {
                        ; // good
                    }
                    else
                    {
                        score -= 4;
                    }
                }
                else
                {
                    if (CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
                    {
                        if (CountUsablePartyMons(battlerDef) == 0)
                        {
                            ; //Good to use move
                        }
                    }
                    else
                    {
                        score -= 4;
                    }
                }
            }
            else
            {
                score -= 4;
            }
            break;
        case EFFECT_DREAM_EATER:
            if (AI_DATA->defAbility != ABILITY_COMATOSE && !(gBattleMons[battlerDef].status1 & STATUS1_SLEEP))
                score -= 10;
            break;
        case EFFECT_COPYCAT:
        case EFFECT_MIRROR_MOVE:
            return AI_CheckBadMove(battlerAtk, battlerDef, predictedMove, score);
        case EFFECT_TELEPORT:
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                if (CountUsablePartyMons(battlerAtk) == 0)
                    score -= 10;
            }
            else if (GetBattlerSide(battlerAtk) == B_SIDE_OPPONENT)
            {
                if (isDoubleBattle || IsBattlerTrapped(battlerAtk, FALSE))
                    score -= 10;
            }
            break;
        case EFFECT_ATTACK_UP:
        case EFFECT_ATTACK_UP_2:
            if (AI_DATA->atkAbility != ABILITY_CONTRARY)
            {
                if (MovesWithSplitUnusable(battlerAtk, battlerDef, SPLIT_PHYSICAL))
                    score -= 8;
                else if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                    score -= 10;
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_ATTACK_ACCURACY_UP: //hone claws
            if (AI_DATA->atkAbility != ABILITY_CONTRARY)
            {
                if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE
                  && (gBattleMons[battlerAtk].statStages[STAT_ACC] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL)))
                    score -= 10;
                break;
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_DEFENSE_UP:
        case EFFECT_DEFENSE_UP_2:
        case EFFECT_DEFENSE_CURL:
            if (move == MOVE_STUFF_CHEEKS)
            {
                if (ItemId_GetPocket(gBattleMons[battlerAtk].item) != POCKET_BERRIES)    // AI knows its own item
                    score -= 10;
            }
            else
            {
                if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_DEF))
                    score -= 10;
            }
            break;
        case EFFECT_FLOWER_SHIELD:
            if (!IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GRASS)
              && !(isDoubleBattle && IS_BATTLER_OF_TYPE(AI_DATA->battlerAtkPartner, TYPE_GRASS)))
                score -= 10;
            break;
        case EFFECT_MAGNETIC_FLUX:
            if (AI_DATA->atkAbility == ABILITY_PLUS || AI_DATA->atkAbility == ABILITY_MINUS)
            {
                if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= MAX_STAT_STAGE
                  && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= MAX_STAT_STAGE)
                    score -= 10;
            }
            else if (!isDoubleBattle)
            {
                score -= 10;    // our stats wont rise from this move
            }

            if (isDoubleBattle)
            {
                if (AI_DATA->atkPartnerAbility == ABILITY_PLUS || AI_DATA->atkPartnerAbility == ABILITY_MINUS)
                {
                    if ((gBattleMons[AI_DATA->battlerAtkPartner].statStages[STAT_DEF] >= MAX_STAT_STAGE)
                      && (gBattleMons[AI_DATA->battlerAtkPartner].statStages[STAT_SPDEF] >= MAX_STAT_STAGE))
                        score -= 10;
                }
                else if (AI_DATA->atkAbility != ABILITY_PLUS && AI_DATA->atkAbility != ABILITY_MINUS)
                {
                    score -= 10;    // nor our or our partner's ability is plus/minus
                }
            }
            break;
        case EFFECT_AROMATIC_MIST:
            if (!isDoubleBattle || gBattleMons[AI_DATA->battlerAtkPartner].hp == 0 || !BattlerStatCanRise(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, STAT_SPDEF))
                score -= 10;
            break;
        case EFFECT_SPEED_UP:
        case EFFECT_SPEED_UP_2:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPEED))
                score -= 10;
            break;
        case EFFECT_SPECIAL_ATTACK_UP:
        case EFFECT_SPECIAL_ATTACK_UP_2:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY
              || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPATK)
              || !HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
                score -= 10;
            break;
        case EFFECT_GROWTH:
        case EFFECT_ATTACK_SPATK_UP:    // work up
            if (!BattlerShouldRaiseAttacks(battlerAtk, AI_DATA->atkAbility))
                score -= 10;
            break;
        case EFFECT_ROTOTILLER:
            if (isDoubleBattle)
            {
                if (!(IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GRASS)
                  && AI_IsBattlerGrounded(battlerAtk)
                  && AI_DATA->atkAbility != ABILITY_CONTRARY
                  && (BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_ATK) || BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPATK)))
                  && !(IS_BATTLER_OF_TYPE(AI_DATA->battlerAtkPartner, TYPE_GRASS)
                  && AI_IsBattlerGrounded(AI_DATA->battlerAtkPartner)
                  && AI_DATA->atkPartnerAbility != ABILITY_CONTRARY
                  && (BattlerStatCanRise(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, STAT_ATK)
                   || BattlerStatCanRise(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, STAT_SPATK))))
                {
                    score -= 10;
                }
            }
            else if (!(IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GRASS)
              && AI_IsBattlerGrounded(battlerAtk)
              && AI_DATA->atkAbility != ABILITY_CONTRARY
              && (BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_ATK) || BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPATK))))
            {
                score -= 10;
            }
            break;
        case EFFECT_GEAR_UP:
            if (AI_DATA->atkAbility == ABILITY_PLUS || AI_DATA->atkAbility == ABILITY_MINUS)
            {
                if (!BattlerShouldRaiseAttacks(battlerAtk, AI_DATA->atkAbility))
                    score -= 10;
            }
            else if (!isDoubleBattle)
            {
                score -= 10;    // no partner and our stats wont rise, so don't use
            }

            if (isDoubleBattle)
            {
                if (AI_DATA->atkPartnerAbility == ABILITY_PLUS || AI_DATA->atkPartnerAbility == ABILITY_MINUS)
                {
                    if ((!BattlerStatCanRise(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, STAT_ATK) || !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                      && (!BattlerStatCanRise(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, STAT_SPATK) || !HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL)))
                        score -= 10;
                }
                else if (AI_DATA->atkAbility != ABILITY_PLUS && AI_DATA->atkAbility != ABILITY_MINUS)
                {
                    score -= 10;    // nor our or our partner's ability is plus/minus
                }
            }
            break;
        case EFFECT_SPECIAL_DEFENSE_UP:
        case EFFECT_SPECIAL_DEFENSE_UP_2:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPDEF))
                score -= 10;
            break;
        case EFFECT_ACCURACY_UP:
        case EFFECT_ACCURACY_UP_2:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_ACC))
                score -= 10;
            break;
        case EFFECT_EVASION_UP:
        case EFFECT_EVASION_UP_2:
        case EFFECT_MINIMIZE:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_EVASION))
                score -= 10;
            break;
        case EFFECT_ACUPRESSURE:
            if (DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
             || AreBattlersStatsMaxed(battlerDef) || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide))
                score -= 10;
            break;
        case EFFECT_ATTACK_DOWN:
        case EFFECT_ATTACK_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE
              || !HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
            {
                score -= 10;
            }
            break;
        case EFFECT_VENOM_DRENCH:
            if (AI_DATA->targetSameSide)
                score -= 10;
            
            if (!(gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
            {
                score -= 10;
            }
            else if (gBattleMons[battlerDef].statStages[STAT_SPEED] == MIN_STAT_STAGE
             && (gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE || !HasMoveWithSplit(battlerDef, SPLIT_SPECIAL))
             && (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE || !HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)))
            {
                score -= 10;
            }
            break;
        case EFFECT_NOBLE_ROAR:
            if (((gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE || !HasMoveWithSplit(battlerDef, SPLIT_SPECIAL))
              && (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE || !HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)))
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
            {
                score -= 10;
            }
            break;
        case EFFECT_DEFENSE_DOWN:
        case EFFECT_DEFENSE_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_DEF] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_SPEED_DOWN:
        case EFFECT_SPEED_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_SPEED] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_SPECIAL_ATTACK_DOWN:
        case EFFECT_SPECIAL_ATTACK_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_CAPTIVATE:
            {
                u8 atkGender = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality);
                u8 defGender = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality);
                if (atkGender == MON_GENDERLESS || defGender == MON_GENDERLESS || atkGender == defGender)
                    score -= 10;
            }
            break;
        case EFFECT_SPECIAL_DEFENSE_DOWN:
        case EFFECT_SPECIAL_DEFENSE_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_SPDEF] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_ACCURACY_DOWN:
        case EFFECT_ACCURACY_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_ACC] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_EVASION_DOWN:
        case EFFECT_EVASION_DOWN_2:
            if (gBattleMons[battlerDef].statStages[STAT_EVASION] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_HAZE:
            if (PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
            {
                score -= 10;    // partner already using haze
            }
            else
            {
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerAtk].statStages[i] > DEFAULT_STAT_STAGE || gBattleMons[AI_DATA->battlerAtkPartner].statStages[i] > DEFAULT_STAT_STAGE)
                        score -= 10;  // Don't want to reset our boosted stats
                }
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerDef].statStages[i] < DEFAULT_STAT_STAGE || gBattleMons[AI_DATA->battlerDefPartner].statStages[i] < DEFAULT_STAT_STAGE)
                        score -= 10; //Don't want to reset enemy lowered stats
                }
            }
            break;
        case EFFECT_BIDE:
            if (!HasDamagingMove(battlerDef)
              || GetHealthPercentage(battlerAtk) < 30 //Close to death
              || gBattleMons[battlerDef].status1 & (STATUS1_SLEEP | STATUS1_FREEZE)) //No point in biding if can't take damage
                score -= 10;
            break;
        case EFFECT_ROAR:
            if (DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10; // don't scare away pokemon twice

            //Don't blow out a Pokemon that'll faint soon or is taking a a lot of secondary damage
            if (GetHealthPercentage(battlerDef) < 10 && GetBattlerSecondaryDamage(battlerDef))
                score -= 10;
            else if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
                score -= 10;
            
            if (CountUsablePartyMons(battlerDef) == 0
                || AI_DATA->defAbility == ABILITY_SUCTION_CUPS
                || gStatuses3[battlerDef] & STATUS3_ROOTED)
                    score -= 10;
            break;
        case EFFECT_HIT_SWITCH_TARGET:
            if (DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10; // don't scare away pokemon twice
            else if (GetHealthPercentage(battlerDef) < 10 && GetBattlerSecondaryDamage(battlerDef))
                score -= 10;    // don't blow away mon that will faint soon
            else if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
                score -= 10;
            break;
        case EFFECT_CONVERSION:
            //Check first move type
            if (IS_BATTLER_OF_TYPE(battlerAtk, gBattleMoves[gBattleMons[battlerAtk].moves[0]].type))
                score -= 10;
            break;
        case EFFECT_REST:
            if (!CanSleep(battlerAtk, AI_DATA->atkAbility))
                score -= 10;
            //fallthrough
        case EFFECT_RESTORE_HP:
        case EFFECT_SOFTBOILED:
        case EFFECT_ROOST:
            if (AtMaxHp(battlerAtk))
                score -= 10;
            else if (GetHealthPercentage(battlerAtk) >= 90)
                score -= 9; //No point in healing, but should at least do it if nothing better
            break;
        case EFFECT_MORNING_SUN:
        case EFFECT_SYNTHESIS:
        case EFFECT_MOONLIGHT:
            if (AI_WeatherHasEffect() && (gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_HAIL_ANY)))
                score -= 3;
            else if (AtMaxHp(battlerAtk))
                score -= 10;
            else if (GetHealthPercentage(battlerAtk) >= 90)
                score -= 9; //No point in healing, but should at least do it if nothing better
            break;
        case EFFECT_PURIFY:
            if (!(gBattleMons[battlerDef].status1 & STATUS1_ANY))
                score -= 10;
            else if (battlerDef == AI_DATA->battlerAtkPartner)
                break; //Always heal your ally
            else if (AtMaxHp(battlerAtk))
                score -= 10;
            else if (GetHealthPercentage(battlerAtk) >= 90)
                score -= 8; //No point in healing, but should at least do it if nothing better
            break;
        case EFFECT_TOXIC_THREAD:
            if (gBattleMons[battlerDef].statStages[STAT_SPEED] > MIN_STAT_STAGE && AI_DATA->defAbility != ABILITY_CONTRARY)
                score -= 10;
            //fallthrough
        case EFFECT_POISON:
        case EFFECT_TOXIC:
            if (!AI_CanPoison(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                score -= 10;
            break;
        case EFFECT_LIGHT_SCREEN:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_LIGHTSCREEN
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL)
                score--; //can use move, but it doesn't stack with light screen
            break;
        case EFFECT_REFLECT:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_REFLECT
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL)
                score--; // can use, but doesn't stack with reflect
            break;
        case EFFECT_AURORA_VEIL:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_AURORA_VEIL
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove)
              || !(gBattleWeather & WEATHER_HAIL_ANY))
                score -= 10;
            else if (gSideStatuses[GetBattlerSide(battlerAtk)] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN))
                score--;    // can use, but won't stack
            break;
        case EFFECT_OHKO:
            if (gMoveResultFlags & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
                score -= 10;
            if (!ShouldTryOHKO(battlerAtk, battlerDef, AI_DATA->atkAbility, AI_DATA->defAbility, accuracy, move))
                score -= 10;
            break;
        case EFFECT_SUPER_FANG:
            if (GetHealthPercentage(battlerDef) < 50)
                score -= 4;
            break;
        case EFFECT_RECOIL_IF_MISS:
            if (AI_DATA->atkAbility != ABILITY_MAGIC_GUARD && accuracy < 75)
                score -= 6;
            break;
        case EFFECT_MIST:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_MIST
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_FOCUS_ENERGY:
            if (gBattleMons[battlerAtk].status2 & STATUS2_FOCUS_ENERGY)
                score -= 10;
            break;
        case EFFECT_RECOIL_25:
            if (AI_DATA->atkAbility != ABILITY_MAGIC_GUARD && AI_DATA->atkAbility != ABILITY_ROCK_HEAD)
            {
                u32 recoilDmg = max(1, AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex] / 4);
                if (!ShouldUseRecoilMove(battlerAtk, battlerDef, recoilDmg, AI_THINKING_STRUCT->movesetIndex))
                    score -= 10;
                break;
            }
            break;
        case EFFECT_RECOIL_33:
        case EFFECT_RECOIL_33_STATUS:
            if (AI_DATA->atkAbility != ABILITY_MAGIC_GUARD && AI_DATA->atkAbility != ABILITY_ROCK_HEAD)
            {
                u32 recoilDmg = max(1, AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex] / 3);
                if (!ShouldUseRecoilMove(battlerAtk, battlerDef, recoilDmg, AI_THINKING_STRUCT->movesetIndex))
                    score -= 10;
                break;
            }
            break;
        case EFFECT_RECOIL_50:
            if (AI_DATA->atkAbility != ABILITY_MAGIC_GUARD && AI_DATA->atkAbility != ABILITY_ROCK_HEAD)
            {
                u32 recoilDmg = max(1, AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex] / 2);
                if (!ShouldUseRecoilMove(battlerAtk, battlerDef, recoilDmg, AI_THINKING_STRUCT->movesetIndex))
                    score -= 10;
                break;
            }
            break;
        case EFFECT_CONFUSE:
            if (!AI_CanConfuse(battlerAtk, battlerDef, AI_DATA->defAbility, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_TEETER_DANCE:
            if (((gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
              || (!DoesBattlerIgnoreAbilityChecks(battlerAtk, move) && AI_DATA->defAbility == ABILITY_OWN_TEMPO)
              || (IsBattlerGrounded(battlerDef) && (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
              || (DoesSubstituteBlockMove(battlerAtk, battlerDef, move)))
             && ((gBattleMons[AI_DATA->battlerDefPartner].status2 & STATUS2_CONFUSION)
              || (!DoesBattlerIgnoreAbilityChecks(battlerAtk, move) && AI_DATA->defPartnerAbility == ABILITY_OWN_TEMPO)
              || (IsBattlerGrounded(AI_DATA->battlerDefPartner) && (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
              || (DoesSubstituteBlockMove(battlerAtk, AI_DATA->battlerDefPartner, move))))
            {
               score -= 10;
            }
            break;
        case EFFECT_TRANSFORM:
            if (gBattleMons[battlerAtk].status2 & STATUS2_TRANSFORMED
              || (gBattleMons[battlerDef].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))) //Leave out Illusion b/c AI is supposed to be fooled
                score -= 10;
            break;
        case EFFECT_PARALYZE:
            if (move != MOVE_GLARE && gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                score -= 10;
            else if (!AI_CanParalyze(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_TWO_TURNS_ATTACK:
            if (AI_DATA->atkHoldEffect != HOLD_EFFECT_POWER_HERB && CanTargetFaintAi(battlerDef, battlerAtk))
                score -= 6;
            break;
        case EFFECT_SUBSTITUTE:
            if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE
              || GetHealthPercentage(battlerAtk) <= 25
              || AI_DATA->defAbility == ABILITY_INFILTRATOR)
                score -= 10;
            else if (B_SOUND_SUBSTITUTE >= GEN_6 && TestMoveFlagsInMoveset(battlerDef, FLAG_SOUND))
                score -= 10;
            break;
        case EFFECT_RECHARGE:
            if (AI_DATA->atkAbility != ABILITY_TRUANT
              && !CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
                score -= 2;
            break;
        case EFFECT_SPITE:
        case EFFECT_MIMIC:
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0) // attacker should go first
            {
                if (gLastMoves[battlerDef] == MOVE_NONE
                  || gLastMoves[battlerDef] == 0xFFFF)
                    score -= 10;
            }
            else if (predictedMove == MOVE_NONE)
            {
                // TODO predicted move separate from gLastMoves
                score -= 10;
            }
            break;
        case EFFECT_METRONOME:
            break;
        case EFFECT_LEECH_SEED:
            if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
             || gStatuses3[battlerDef] & STATUS3_LEECHSEED
             || AI_DATA->defAbility == ABILITY_LIQUID_OOZE
             || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_DISABLE:
            if (gDisableStructs[battlerDef].disableTimer == 0
              && (B_MENTAL_HERB >= GEN_5 && AI_DATA->defHoldEffect != HOLD_EFFECT_CURE_ATTRACT)
              && !PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
            {
                if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0) // attacker should go first
                {
                    if (gLastMoves[battlerDef] == MOVE_NONE || gLastMoves[battlerDef] == 0xFFFF)
                        score -= 10;
                }
                else if (predictedMove == MOVE_NONE)
                {
                    score -= 10;
                }
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_COUNTER:
        case EFFECT_MIRROR_COAT:
            if (IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility) || gBattleMons[battlerDef].status2 & (STATUS2_INFATUATION | STATUS2_CONFUSION))
                score--;
            if (predictedMove == MOVE_NONE || GetBattleMoveSplit(predictedMove) == SPLIT_STATUS
              || DoesSubstituteBlockMove(battlerAtk, AI_DATA->battlerDefPartner, predictedMove))
                score -= 10;
            break;
        case EFFECT_ENCORE:
            if (gDisableStructs[battlerDef].encoreTimer == 0
              && (B_MENTAL_HERB >= GEN_5 && AI_DATA->defHoldEffect != HOLD_EFFECT_CURE_ATTRACT)
              && !DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
            {
                if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0) // attacker should go first
                {
                    if (gLastMoves[battlerDef] == MOVE_NONE
                      || gLastMoves[battlerDef] == 0xFFFF)
                        score -= 10;
                }
                else if (predictedMove == MOVE_NONE)
                {
                    score -= 10;
                }
            }
            else
            {
                score -= 10;
            }
            break;
        case EFFECT_ENDEAVOR:
        case EFFECT_PAIN_SPLIT:
            if (gBattleMons[battlerAtk].hp > (gBattleMons[battlerAtk].hp + gBattleMons[battlerDef].hp) / 2)
                score -= 10;
            break;
        case EFFECT_SNORE:
        case EFFECT_SLEEP_TALK:
            if (IsWakeupTurn(battlerAtk) || (!(gBattleMons[battlerAtk].status1 & STATUS1_SLEEP) && AI_DATA->atkAbility != ABILITY_COMATOSE))
                score -= 10;
            break;
        case EFFECT_CONVERSION_2:
            //TODO
            break;
        case EFFECT_LOCK_ON:
            if (gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS
              || AI_DATA->atkAbility == ABILITY_NO_GUARD
              || AI_DATA->defAbility == ABILITY_NO_GUARD
              || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_LASER_FOCUS:
            if (gStatuses3[battlerAtk] & STATUS3_LASER_FOCUS)
                score -= 10;
            else if (AI_DATA->defAbility == ABILITY_SHELL_ARMOR || AI_DATA->defAbility == ABILITY_BATTLE_ARMOR)
                score -= 8;
            break;
        case EFFECT_SKETCH:
            if (gLastMoves[battlerDef] == MOVE_NONE)
                score -= 10;
            break;
        case EFFECT_DESTINY_BOND:
            if (gBattleMons[battlerDef].status2 & STATUS2_DESTINY_BOND)
                score -= 10;
            break;
        case EFFECT_FALSE_SWIPE:
            // TODO
            break;
        case EFFECT_HEAL_BELL:
            if (!AnyPartyMemberStatused(battlerAtk, TestMoveFlags(move, FLAG_SOUND)) || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_MEAN_LOOK:
            if (IsBattlerTrapped(battlerDef, TRUE)
              || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_HIT_PREVENT_ESCAPE:
            break;
        case EFFECT_NIGHTMARE:
            if (gBattleMons[battlerDef].status2 & STATUS2_NIGHTMARE
            || !(gBattleMons[battlerDef].status1 & STATUS1_SLEEP || AI_DATA->defAbility == ABILITY_COMATOSE)
            || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_CURSE:
            if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
            {
                if (gBattleMons[battlerDef].status2 & STATUS2_CURSED
                || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;
                else if (GetHealthPercentage(battlerAtk) <= 50)
                    score -= 6;
            }
            else //Regular Curse
            {
                if (!BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_ATK)
                && !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_DEF)
                && !BattlerStatCanFall(battlerAtk, AI_DATA->atkAbility, STAT_SPEED))
                    score -= 10;
            }
            break;
        case EFFECT_ENDURE:
            if (gBattleMons[battlerAtk].hp == 1 || GetBattlerSecondaryDamage(battlerAtk)) //Don't use Endure if you'll die after using it
                score -= 10;
            break;
        case EFFECT_PROTECT:
            {
                bool32 decreased = FALSE;
                switch (move)
                {
                case MOVE_QUICK_GUARD:
                case MOVE_WIDE_GUARD:
                case MOVE_CRAFTY_SHIELD:
                    if (!isDoubleBattle)
                    {
                        score -= 10;
                        decreased = TRUE;
                    }
                    break;
                case MOVE_MAT_BLOCK:
                    if (!gDisableStructs[battlerAtk].isFirstTurn)
                    {
                        score -= 10;
                        decreased = TRUE;
                    }
                    break;
                } // move check
                
                if (decreased)
                    break;
                if (gBattleMons[battlerDef].status2 & STATUS2_RECHARGE)
                {
                    score -= 10;
                    break;
                }

                if (gBattleMoves[gLastResultingMoves[battlerAtk]].effect == EFFECT_PROTECT
                  && move != MOVE_QUICK_GUARD
                  && move != MOVE_WIDE_GUARD
                  && move != MOVE_CRAFTY_SHIELD) //These moves have infinite usage
                {
                    if (GetBattlerSecondaryDamage(battlerAtk)
                      && AI_DATA->defAbility != ABILITY_MOXIE
                      && AI_DATA->defAbility != ABILITY_BEAST_BOOST)
                    {
                        score -= 10; //Don't protect if you're going to faint after protecting
                    }
                    else if (gDisableStructs[battlerAtk].protectUses == 1 && Random() % 100 < 50)
                    {
                        if (!isDoubleBattle)
                            score -= 6;
                        else
                            score -= 10; //Don't try double protecting in doubles
                    }
                    else if (gDisableStructs[battlerAtk].protectUses >= 2)
                    {
                        score -= 10;
                    }
                }

                /*if (AI_THINKING_STRUCT->aiFlags == AI_SCRIPT_CHECK_BAD_MOVE //Only basic AI
                && IS_DOUBLE_BATTLE) //Make the regular AI know how to use Protect minimally in Doubles
                {
                    u8 shouldProtect = ShouldProtect(battlerAtk, battlerDef, move);
                    if (shouldProtect == USE_PROTECT || shouldProtect == PROTECT_FROM_FOES)
                        IncreaseFoeProtectionViability(&viability, 0xFF, battlerAtk, battlerDef);
                    else if (shouldProtect == PROTECT_FROM_ALLIES)
                        IncreaseAllyProtectionViability(&viability, 0xFF);
                }*/
            }
            break;
        case EFFECT_SPIKES:
            if (gSideTimers[GetBattlerSide(battlerDef)].spikesAmount >= 3)
                score -= 10;
            else if (PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove) 
                  && gSideTimers[GetBattlerSide(battlerDef)].spikesAmount == 2)
                score -= 10; //Only one mon needs to set up the last layer of Spikes
            break;
        case EFFECT_STEALTH_ROCK:
            if (gSideTimers[GetBattlerSide(battlerDef)].stealthRockAmount > 0
                || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove)) //Only one mon needs to set up Stealth Rocks
                    score -= 10;
                break;
        case EFFECT_TOXIC_SPIKES:
            if (gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount >= 2)
                score -= 10;
            else if (PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].toxicSpikesAmount == 1)
                score -= 10; //Only one mon needs to set up the last layer of Toxic Spikes
            break;
        case EFFECT_STICKY_WEB:
            if (gSideTimers[GetBattlerSide(battlerDef)].stickyWebAmount)
                score -= 10;
            else if (PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove) && gSideTimers[GetBattlerSide(battlerDef)].stickyWebAmount)
                score -= 10; //Only one mon needs to set up Sticky Web
            break;
        case EFFECT_FORESIGHT:
            if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT)
            {
                score -= 10;
            }
            else if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= 4
                || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST))
                || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
            {
                score -= 9;
            }
            break;
        case EFFECT_MIRACLE_EYE:
            if (gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED)
                score -= 10;

            if (gBattleMons[battlerDef].statStages[STAT_EVASION] <= 4
              || !(IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
              || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 9;
            break;
        case EFFECT_PERISH_SONG:
            if (isDoubleBattle)
            {
                if (CountUsablePartyMons(battlerAtk) == 0
                  && AI_DATA->atkAbility != ABILITY_SOUNDPROOF
                  && AI_DATA->atkPartnerAbility != ABILITY_SOUNDPROOF
                  && CountUsablePartyMons(FOE(battlerAtk)) >= 1)
                {
                    score -= 10; //Don't wipe your team if you're going to lose
                }
                else if ((!IsBattlerAlive(FOE(battlerAtk)) || AI_GetAbility(FOE(battlerAtk)) == ABILITY_SOUNDPROOF
                  || gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG)
                  && (!IsBattlerAlive(BATTLE_PARTNER(FOE(battlerAtk))) || AI_GetAbility(BATTLE_PARTNER(FOE(battlerAtk))) == ABILITY_SOUNDPROOF
                  || gStatuses3[BATTLE_PARTNER(FOE(battlerAtk))] & STATUS3_PERISH_SONG))
                {
                    score -= 10; //Both enemies are perish songed
                }
                else if (DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;
            }
            else
            {
                if (CountUsablePartyMons(battlerAtk) == 0 && AI_DATA->atkAbility != ABILITY_SOUNDPROOF
                  && CountUsablePartyMons(battlerDef) >= 1)
                    score -= 10;

                if (gStatuses3[FOE(battlerAtk)] & STATUS3_PERISH_SONG || AI_GetAbility(FOE(battlerAtk)) == ABILITY_SOUNDPROOF)
                    score -= 10;
            }
            break;
        case EFFECT_SANDSTORM:
            if (gBattleWeather & WEATHER_SANDSTORM_ANY //TODO | WEATHER_PRIMAL_ANY)
              || PartnerMoveEffectIsWeather(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_SUNNY_DAY:
            if (gBattleWeather & WEATHER_SUN_ANY //TODO | WEATHER_PRIMAL_ANY)
            || PartnerMoveEffectIsWeather(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_RAIN_DANCE:
            if (gBattleWeather & WEATHER_RAIN_ANY  //TODO  | WEATHER_PRIMAL_ANY)
            || PartnerMoveEffectIsWeather(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_HAIL:
            if (gBattleWeather & WEATHER_HAIL_ANY //TODO | WEATHER_PRIMAL_ANY | WEATHER_CIRCUS)
            || PartnerMoveEffectIsWeather(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_SWAGGER:
            if (AI_DATA->targetSameSide && AI_DATA->defAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (!AI_CanConfuse(battlerAtk, battlerDef, AI_DATA->defAbility, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_ATTRACT:
            {
                u8 atkGender = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerAtk].species, gBattleMons[battlerAtk].personality);
                u8 defGender = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerDef].species, gBattleMons[battlerDef].personality);
                if (!AI_CanBeInfatuated(battlerAtk, battlerDef, AI_DATA->defAbility, atkGender, defGender)
                || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;
            }
            break;
        case EFFECT_SAFEGUARD:
            if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_SAFEGUARD
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_BURN_UP:
            if (!IS_BATTLER_OF_TYPE(battlerAtk, TYPE_FIRE))
                score -= 10;
            break;
        case EFFECT_PARTING_SHOT:
            if (CountUsablePartyMons(battlerAtk) == 0)
                score -= 10;
            break;
        case EFFECT_BATON_PASS:
            if (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE
              || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE | STATUS3_POWER_TRICK))
              || AnyStatIsRaised(battlerAtk))
                break;

            score -= 6;
            break;
        case EFFECT_HIT_ESCAPE:
            break;
        case EFFECT_RAPID_SPIN:
            if ((gBattleMons[battlerAtk].status2 & STATUS2_WRAPPED) || (gStatuses3[battlerAtk] & STATUS3_LEECHSEED))
                break;  // check damage/accuracy

            //Spin checks
            if (!(gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY))
                score -= 6;
            break;
        case EFFECT_DEFOG:
            if (gSideStatuses[GetBattlerSide(battlerDef)]
             & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST)
              || gSideTimers[GetBattlerSide(battlerDef)].auroraVeilTimer != 0
              || gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY)
            {
                if (PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                {
                    score -= 10; //Only need one hazards removal
                    break;
                }
            }

            if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_HAZARDS_ANY)
            {
                score -= 10; //Don't blow away opposing hazards
                break;
            }

            if (isDoubleBattle)
            {
                if (IsHazardMoveEffect(gBattleMoves[AI_DATA->partnerMove].effect) // partner is going to set up hazards
                  && GetWhoStrikesFirst(AI_DATA->battlerAtkPartner, battlerAtk, FALSE)) // partner is going to set up before the potential Defog
                {
                    score -= 10;
                    break; // Don't use Defog if partner is going to set up hazards
                }
            }

            // evasion check
            if (gBattleMons[battlerDef].statStages[STAT_EVASION] == MIN_STAT_STAGE
              || ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)) // don't want to raise target stats unless its your partner
                score -= 10;
            break;
        case EFFECT_BELLY_DRUM:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (GetHealthPercentage(battlerAtk) <= 60)
                score -= 10;
            break;
        case EFFECT_PSYCH_UP:   // haze stats check
            {
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerAtk].statStages[i] > DEFAULT_STAT_STAGE || gBattleMons[AI_DATA->battlerAtkPartner].statStages[i] > DEFAULT_STAT_STAGE)
                        score -= 10;  // Don't want to reset our boosted stats
                }
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battlerDef].statStages[i] < DEFAULT_STAT_STAGE || gBattleMons[AI_DATA->battlerDefPartner].statStages[i] < DEFAULT_STAT_STAGE)
                        score -= 10; //Don't want to copy enemy lowered stats
                }
            }
            break;
        case EFFECT_SPECTRAL_THIEF:
            break;
        case EFFECT_FUTURE_SIGHT:
            if (gWishFutureKnock.futureSightCounter[battlerDef] != 0)
                score -= 10;
            break;
        case EFFECT_SOLARBEAM:
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_POWER_HERB
              || (AI_WeatherHasEffect() && gBattleWeather & WEATHER_SUN_ANY && AI_DATA->atkHoldEffect != HOLD_EFFECT_UTILITY_UMBRELLA))
                break;
            if (CanTargetFaintAi(battlerDef, battlerAtk)) //Attacker can be knocked out
                score -= 4;
            break;
        case EFFECT_SEMI_INVULNERABLE:
            if (predictedMove != MOVE_NONE
              && GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1
              && gBattleMoves[predictedMove].effect == EFFECT_SEMI_INVULNERABLE)
                score -= 10; // Don't Fly/dig/etc if opponent is going to fly/dig/etc after you

            if (BattlerWillFaintFromWeather(battlerAtk, AI_DATA->atkAbility)
              && (move == MOVE_FLY || move == MOVE_BOUNCE))
                score -= 10; // Attacker will faint while in the air
            break;
        case EFFECT_FAKE_OUT:
            // first impression check
            if (!gDisableStructs[battlerAtk].isFirstTurn)
            {
                score -= 10;
            }
            else if (move == MOVE_FAKE_OUT)
            {
                if ((AI_DATA->atkHoldEffect == HOLD_EFFECT_CHOICE_BAND || AI_DATA->atkAbility == ABILITY_GORILLA_TACTICS)
                && (CountUsablePartyMons(battlerDef) > 0 || !CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0)))
                {
                    if (CountUsablePartyMons(battlerAtk) == 0)
                        score -= 10; // Don't lock the attacker into Fake Out if they can't switch out afterwards.
                }
            }
            break; //damage checks
        case EFFECT_STOCKPILE:
            if (gDisableStructs[battlerAtk].stockpileCounter >= 3)
                score -= 10;
            break;
        case EFFECT_SPIT_UP:
            if (gDisableStructs[battlerAtk].stockpileCounter == 1)
                score -= 10;
            else if (gDisableStructs[battlerAtk].stockpileCounter <= 1)
                score -= 2;
            break;
        case EFFECT_SWALLOW:
            if (gDisableStructs[battlerAtk].stockpileCounter == 0)
            {
                score -= 10;
            }
            else
            {
                if (AtMaxHp(battlerAtk))
                    score -= 10;
                else if (GetHealthPercentage(battlerAtk) >= 80)
                    score -= 5; // do it if nothing better
            }
            break;
        case EFFECT_TORMENT:
            if (gBattleMons[battlerDef].status2 & STATUS2_TORMENT
              || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
            {
                score -= 10;
                break;
            }
            
            if (B_MENTAL_HERB >= GEN_5 && AI_DATA->defHoldEffect == HOLD_EFFECT_CURE_ATTRACT)
                score -= 6;
            break;
        case EFFECT_FLATTER:
            if (AI_DATA->targetSameSide && AI_DATA->defAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (!AI_CanConfuse(battlerAtk, battlerDef, AI_DATA->defAbility, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_WILL_O_WISP:
            if (!AI_CanBurn(battlerAtk, battlerDef, AI_DATA->defAbility, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_MEMENTO:
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE && gBattleMons[battlerDef].statStages[STAT_SPATK] == MIN_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_HEALING_WISH:   //healing wish, lunar dance
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            else if (IsPartyFullyHealedExceptBattler(battlerAtk))
                score -= 10;
            break;
        case EFFECT_FINAL_GAMBIT:
            if (CountUsablePartyMons(battlerAtk) == 0 || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_FOCUS_PUNCH:
            if (predictedMove != MOVE_NONE
              && !DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
              && !IS_MOVE_STATUS(predictedMove)
              && gBattleMoves[predictedMove].power != 0)
                score -= 10; // Probably better not to use it
            break;
        case EFFECT_NATURE_POWER:
            return AI_CheckBadMove(battlerAtk, battlerDef, GetNaturePowerMove(), score);
        case EFFECT_CHARGE:
            if (gStatuses3[battlerAtk] & STATUS3_CHARGED_UP)
            {
                score -= 10;
                break;
            }
            else if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC))
            {
                if (AI_DATA->atkAbility == ABILITY_CONTRARY || !BattlerStatCanRise(battlerAtk, AI_DATA->atkAbility, STAT_SPDEF))
                    score -= 10;
            }
            break;
        case EFFECT_TAUNT:
            if (gDisableStructs[battlerDef].tauntTimer > 0
              || DoesPartnerHaveSameMoveEffect(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score--;
            break;
        case EFFECT_FOLLOW_ME:
        case EFFECT_HELPING_HAND:
            if (!isDoubleBattle
              || !IsBattlerAlive(AI_DATA->battlerAtkPartner)
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove)
              || (AI_DATA->partnerMove != MOVE_NONE && IS_MOVE_STATUS(AI_DATA->partnerMove))
              || *(gBattleStruct->monToSwitchIntoId + AI_DATA->battlerAtkPartner) != PARTY_SIZE) //Partner is switching out.
                score -= 10;
            break;
        case EFFECT_TRICK:
            if ((AI_DATA->atkHoldEffect == HOLD_EFFECT_NONE && AI_DATA->defHoldEffect == HOLD_EFFECT_NONE)
              || AI_DATA->defAbility == ABILITY_STICKY_HOLD
              || !CanBattlerGetOrLoseItem(battlerAtk, gBattleMons[battlerAtk].item)
              || !CanBattlerGetOrLoseItem(battlerAtk, gBattleMons[battlerDef].item)
              || !CanBattlerGetOrLoseItem(battlerDef, gBattleMons[battlerAtk].item)
              || !CanBattlerGetOrLoseItem(battlerDef, gBattleMons[battlerDef].item))
                score -= 10; // kinda cheating with battlerDef item check, but only item effects recorded
            break;
        case EFFECT_BESTOW:
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_NONE
              || !CanBattlerGetOrLoseItem(battlerAtk, gBattleMons[battlerAtk].item))    // AI knows its own item
                score -= 10;
            break;
        case EFFECT_ROLE_PLAY:
            if (AI_DATA->atkAbility == AI_DATA->defAbility
              || AI_DATA->defAbility == ABILITY_NONE
              || IsRolePlayBannedAbilityAtk(AI_DATA->atkAbility)
              || IsRolePlayBannedAbility(AI_DATA->defAbility))
                score -= 10;
            else if (IsAbilityOfRating(AI_DATA->atkAbility, 5))
                score -= 4;
            break;
        case EFFECT_WISH:
            if (gWishFutureKnock.wishCounter[battlerAtk] != 0)
                score -= 10;
            break;
        case EFFECT_ASSIST:
            if (CountUsablePartyMons(battlerAtk) == 0)
                score -= 10;    // no teammates to assist from
            break;
        case EFFECT_INGRAIN:
            if (gStatuses3[battlerAtk] & STATUS3_ROOTED)
                score -= 10;
            break;
        case EFFECT_AQUA_RING:
            if (gStatuses3[battlerAtk] & STATUS3_AQUA_RING)
                score -= 10;
            break;
        case EFFECT_SUPERPOWER:
            #ifdef POKEMON_EXPANSION
            if (move == MOVE_HYPERSPACE_FURY && gBattleMons[battlerAtk].species != SPECIES_HOOPA_UNBOUND)
                score -= 10;
            #endif
            if (effectiveness <= AI_EFFECTIVENESS_x0_5)
                score -= 2; // really don't waste the stat loss on a weak attack
            break;
        case EFFECT_MAGIC_COAT:
            if (!TestMoveFlagsInMoveset(battlerDef, FLAG_MAGICCOAT_AFFECTED))
                score -= 10;
            break;
        case EFFECT_RECYCLE:
            if (gBattleStruct->usedHeldItems[battlerAtk] == 0 || gBattleMons[battlerAtk].item != 0)
                score -= 10;
            break;
        case EFFECT_BELCH:
            if (ItemId_GetPocket(gBattleStruct->usedHeldItems[battlerAtk]) != POCKET_BERRIES)
                score -= 10; // attacker has not consumed a berry
            break;
        case EFFECT_YAWN:
            if (gStatuses3[battlerDef] & STATUS3_YAWN)
                score -= 10;
            else if (!AI_CanPutToSleep(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_KNOCK_OFF:
            /*if (AI_DATA->defHoldEffect == HOLD_EFFECT_ASSAULT_VEST
            || (AI_DATA->defHoldEffect == HOLD_EFFECT_CHOICE_BAND && AI_DATA->atkAbility != ABILITY_GORILLA_TACTICS && gBattleStruct->choicedMove[battlerDef]))
            {
                if (GetStrongestMove(battlerDef, battlerAtk) == MOVE_NONE
                || AI_SpecialTypeCalc(GetStrongestMove(battlerDef, battlerAtk), battlerDef, battlerAtk) & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
                    DECREASE_VIABILITY(9); //Don't use Knock Off is the enemy's only moves don't affect the AI
            }*/
            if (AI_DATA->defHoldEffect == HOLD_EFFECT_NONE)
                score -= 4;
            break;
        case EFFECT_SKILL_SWAP:
            if (AI_DATA->atkAbility == ABILITY_NONE || AI_DATA->defAbility == ABILITY_NONE
              || IsSkillSwapBannedAbility(AI_DATA->atkAbility) || IsSkillSwapBannedAbility(AI_DATA->defAbility))
                score -= 10;
            break;
        case EFFECT_WORRY_SEED:
            if (AI_DATA->defAbility == ABILITY_INSOMNIA
              || IsWorrySeedBannedAbility(AI_DATA->defAbility))
                score -= 10;
            break;
        case EFFECT_GASTRO_ACID:
            if (gStatuses3[battlerDef] & STATUS3_GASTRO_ACID
              || IsGastroAcidBannedAbility(AI_DATA->defAbility))
                score -= 10;
            break;
        case EFFECT_ENTRAINMENT:
            if (AI_DATA->atkAbility == ABILITY_NONE
              || IsEntrainmentBannedAbilityAttacker(AI_DATA->atkAbility)
              || IsEntrainmentTargetOrSimpleBeamBannedAbility(AI_DATA->defAbility))
                score -= 10;
            break;
        case EFFECT_CORE_ENFORCER:
            break;
        case EFFECT_SIMPLE_BEAM:
            if (AI_DATA->defAbility == ABILITY_SIMPLE
              || IsEntrainmentTargetOrSimpleBeamBannedAbility(AI_DATA->defAbility))
                score -= 10;
            break;
        case EFFECT_IMPRISON:
            if (gStatuses3[battlerAtk] & STATUS3_IMPRISONED_OTHERS)
                score -= 10;
            break;
        case EFFECT_REFRESH:
            if (!(gBattleMons[battlerDef].status1 & (STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_PARALYSIS)))
                score -= 10;
            break;
        case EFFECT_PSYCHO_SHIFT:
            if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && !AI_CanPoison(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && !AI_CanBurn(battlerAtk, battlerDef, AI_DATA->defAbility, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_PARALYSIS && !AI_CanParalyze(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            else if (gBattleMons[battlerAtk].status1 & STATUS1_SLEEP && !AI_CanPutToSleep(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                score -= 10;
            else
                score -= 10;
            break;
        case EFFECT_SNATCH:
            if (!TestMoveFlagsInMoveset(battlerDef, FLAG_SNATCH_AFFECTED)
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_MUD_SPORT:
            if (gFieldStatuses & STATUS_FIELD_MUDSPORT
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_WATER_SPORT:
            if (gFieldStatuses & STATUS_FIELD_WATERSPORT
              || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_TICKLE:
            if ((AI_DATA->defAbility == ABILITY_CONTRARY) && !AI_DATA->targetSameSide)
                score -= 10;
            else if ((gBattleMons[battlerDef].statStages[STAT_ATK] == MIN_STAT_STAGE || !HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL))
              && gBattleMons[battlerDef].statStages[STAT_DEF] == MIN_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_COSMIC_POWER:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= MAX_STAT_STAGE
              && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= MAX_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_BULK_UP:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if ((gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE && !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
              && gBattleMons[battlerAtk].statStages[STAT_DEF] >= MAX_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_COIL:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_ACC] >= MAX_STAT_STAGE
              && (gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE && !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
              &&  gBattleMons[battlerAtk].statStages[STAT_DEF] >= MAX_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_CALM_MIND:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if ((gBattleMons[battlerAtk].statStages[STAT_SPATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
              && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= MAX_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_QUIVER_DANCE:
        case EFFECT_GEOMANCY:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_SPEED] >= MAX_STAT_STAGE
              && (gBattleMons[battlerAtk].statStages[STAT_SPATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
              &&  gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= MAX_STAT_STAGE)
                score -= 10;
            break;
        case EFFECT_DRAGON_DANCE:
        case EFFECT_SHIFT_GEAR:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
                score -= 10;
            else if ((gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
              && (gBattleMons[battlerAtk].statStages[STAT_SPEED] >= MAX_STAT_STAGE))
                score -= 10;
            break;
        case EFFECT_SHELL_SMASH:
            if (AI_DATA->atkAbility == ABILITY_CONTRARY)
            {
                if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= MAX_STAT_STAGE
                  && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= MAX_STAT_STAGE)
                    score -= 10;
            }
            else
            {
                if ((gBattleMons[battlerAtk].statStages[STAT_SPATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
                  && (gBattleMons[battlerAtk].statStages[STAT_ATK] >= MAX_STAT_STAGE || !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                  && (gBattleMons[battlerAtk].statStages[STAT_SPEED] >= MAX_STAT_STAGE))
                    score -= 10;
            }
            break;
        
        case EFFECT_POWER_TRICK:
            if (AI_DATA->targetSameSide)
                score -= 10;
            else if (gBattleMons[battlerAtk].defense >= gBattleMons[battlerAtk].attack && !HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                score -= 10;
            break;
        case EFFECT_POWER_SWAP: // Don't use if attacker's stat stages are higher than opponents
            if (AI_DATA->targetSameSide)
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_ATK] >= gBattleMons[battlerDef].statStages[STAT_ATK]
              && gBattleMons[battlerAtk].statStages[STAT_SPATK] >= gBattleMons[battlerDef].statStages[STAT_SPATK])
                score -= 10;
            break;
        case EFFECT_GUARD_SWAP: // Don't use if attacker's stat stages are higher than opponents
            if (AI_DATA->targetSameSide)
                score -= 10;
            else if (gBattleMons[battlerAtk].statStages[STAT_DEF] >= gBattleMons[battlerDef].statStages[STAT_DEF]
              && gBattleMons[battlerAtk].statStages[STAT_SPDEF] >= gBattleMons[battlerDef].statStages[STAT_SPDEF])
                score -= 10;
            break;
        case EFFECT_SPEED_SWAP:
            if (AI_DATA->targetSameSide)
            {
                score -= 10;
            }
            else
            {
                if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && (gBattleMons[battlerAtk].speed <= gBattleMons[battlerDef].speed))
                    score -= 10;
                else if (gBattleMons[battlerAtk].speed >= gBattleMons[battlerDef].speed)
                    score -= 10;
            }
            break;
        case EFFECT_HEART_SWAP:
            if (AI_DATA->targetSameSide)
            {
                score -= 10;
            }
            else
            {
                u32 atkPositiveStages = CountPositiveStatStages(battlerAtk);
                u32 atkNegativeStages = CountNegativeStatStages(battlerAtk);
                u32 defPositiveStages = CountPositiveStatStages(battlerDef);
                u32 defNegativeStages = CountNegativeStatStages(battlerDef);
                
                if (atkPositiveStages >= defPositiveStages && atkNegativeStages <= defNegativeStages)
                    score -= 10;
                break;
            }
            break;
        case EFFECT_POWER_SPLIT:
            if (AI_DATA->targetSameSide)
            {
                score -= 10;
            }
            else
            {
                u8 atkAttack = gBattleMons[battlerAtk].attack;
                u8 defAttack = gBattleMons[battlerDef].attack;
                u8 atkSpAttack = gBattleMons[battlerAtk].spAttack;
                u8 defSpAttack = gBattleMons[battlerDef].spAttack;

                if (atkAttack + atkSpAttack >= defAttack + defSpAttack) // Combined attacker stats are > than combined target stats
                    score -= 10;
                break;
            }
            break;
        case EFFECT_GUARD_SPLIT:
            if (AI_DATA->targetSameSide)
            {
                score -= 10;
            }
            else
            {
                u8 atkDefense = gBattleMons[battlerAtk].defense;
                u8 defDefense = gBattleMons[battlerDef].defense;
                u8 atkSpDefense = gBattleMons[battlerAtk].spDefense;
                u8 defSpDefense = gBattleMons[battlerDef].spDefense;

                if (atkDefense + atkSpDefense >= defDefense + defSpDefense) //Combined attacker stats are > than combined target stats
                    score -= 10;
                break;
            }
            break;
        case EFFECT_ME_FIRST:
            if (predictedMove != MOVE_NONE)
            {
                if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1)
                    score -= 10;    // Target is predicted to go first, Me First will fail
                else
                    return AI_CheckBadMove(battlerAtk, battlerDef, predictedMove, score);
            }
            else
            {
                score -= 10; //Target is predicted to switch most likely
            }
            break;
        case EFFECT_NATURAL_GIFT:
            if (AI_DATA->atkAbility == ABILITY_KLUTZ
              || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
              || GetPocketByItemId(gBattleMons[battlerAtk].item) != POCKET_BERRIES)
                score -= 10;
            break;
        case EFFECT_GRASSY_TERRAIN:
            if (PartnerMoveEffectIsTerrain(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove) || gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
                score -= 10;
            break;
        case EFFECT_ELECTRIC_TERRAIN:
            if (PartnerMoveEffectIsTerrain(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove) || gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
                score -= 10;
            break;
        case EFFECT_PSYCHIC_TERRAIN:
            if (PartnerMoveEffectIsTerrain(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove) || gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
                score -= 10;
            break;
        case EFFECT_MISTY_TERRAIN:
            if (PartnerMoveEffectIsTerrain(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove) || gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
                score -= 10;
            break;
        case EFFECT_PLEDGE:
            if (isDoubleBattle && gBattleMons[AI_DATA->battlerAtkPartner].hp > 0)
            {
                if (AI_DATA->partnerMove != MOVE_NONE
                  && gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_PLEDGE
                  && move != AI_DATA->partnerMove) // Different pledge moves
                {
                    if (gBattleMons[AI_DATA->battlerAtkPartner].status1 & (STATUS1_SLEEP | STATUS1_FREEZE))
                    // && gBattleMons[AI_DATA->battlerAtkPartner].status1 != 1) // Will wake up this turn - how would AI know
                        score -= 10; // Don't use combo move if your partner will cause failure
                }
            }
            break;
        case EFFECT_TRICK_ROOM:
            if (PartnerMoveIs(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove, MOVE_TRICK_ROOM))
            {
                score -= 10;
            }
            else if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM) // Trick Room Up
            {
                if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef)) // Attacker side slower than target side
                    score -= 10; // Keep the Trick Room up
            }
            else
            {
                if (GetBattlerSideSpeedAverage(battlerAtk) > GetBattlerSideSpeedAverage(battlerDef)) // Attacker side faster than target side
                    score -= 10; // Keep the Trick Room down
            }
            break;
        case EFFECT_MAGIC_ROOM:
            if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_WONDER_ROOM:
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_GRAVITY:
            if ((gFieldStatuses & STATUS_FIELD_GRAVITY
              && !IS_BATTLER_OF_TYPE(battlerAtk, TYPE_FLYING)
              && AI_DATA->atkHoldEffect != HOLD_EFFECT_AIR_BALLOON) // Should revert Gravity in this case
              || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_ION_DELUGE:
            if (gFieldStatuses & STATUS_FIELD_ION_DELUGE
              || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_FLING:
            if (!CanFling(battlerAtk))
            {
                score -= 10;
            }
            else
            {
                /* TODO Fling
                u8 effect = gFlingTable[gBattleMons[battlerAtk].item].effect;
                switch (effect)
                {
                case MOVE_EFFECT_BURN:
                    if (!AI_CanBurn(battlerAtk, battlerDef, AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_PARALYSIS:
                    if (!AI_CanParalyze(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_POISON:
                    if (!AI_CanPoison(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_TOXIC:
                    if (!AI_CanPoison(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_DATA->partnerMove))
                        score -= 10;
                    break;
                case MOVE_EFFECT_FREEZE:
                    if (!CanBeFrozen(battlerDef, TRUE)
                     || MoveBlockedBySubstitute(move, battlerAtk, battlerDef))
                        score -= 10;
                    break;
                }*/
            }
            break;
        case EFFECT_EMBARGO:
            if (AI_DATA->defAbility == ABILITY_KLUTZ
              || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
              || gDisableStructs[battlerDef].embargoTimer != 0
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_POWDER:
            if (!HasMoveWithType(battlerDef, TYPE_FIRE)
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_TELEKINESIS:
            if (gStatuses3[battlerDef] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN)
              || gFieldStatuses & STATUS_FIELD_GRAVITY
              || AI_DATA->defHoldEffect == HOLD_EFFECT_IRON_BALL
              || IsTelekinesisBannedSpecies(gBattleMons[battlerDef].species)
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_THROAT_CHOP:
            break;
        case EFFECT_HEAL_BLOCK:
            if (gDisableStructs[battlerDef].healBlockTimer != 0
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_SOAK:
            if (PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove)
              || (gBattleMons[battlerDef].type1 == TYPE_WATER
              && gBattleMons[battlerDef].type2 == TYPE_WATER
              && gBattleMons[battlerDef].type3 == TYPE_MYSTERY))
                score -= 10;    // target is already water-only
            break;
        case EFFECT_THIRD_TYPE:
            switch (move)
            {
            case MOVE_TRICK_OR_TREAT:
                if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST) || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;
                break;
            case MOVE_FORESTS_CURSE:
                if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS) || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;
                break;
            }
            break;
        case EFFECT_HIT_ENEMY_HEAL_ALLY:    // pollen puff
            if (AI_DATA->targetSameSide)
            {
                if (AtMaxHp(battlerDef))
                    score -= 10;
                else if (gBattleMons[battlerDef].hp > gBattleMons[battlerDef].maxHP / 2)
                    score -= 5;
                break;
            }
            // fallthrough
        case EFFECT_HEAL_PULSE: // and floral healing
            if (!AI_DATA->targetSameSide) // Don't heal enemies
            {
                score -= 10;
            }
            else
            {
                if (AtMaxHp(battlerDef))
                    score -= 10;
                else if (gBattleMons[battlerDef].hp > gBattleMons[battlerDef].maxHP / 2)
                    score -= 5;
            }
            break;
        case EFFECT_ELECTRIFY:
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0
              //|| GetMoveTypeSpecial(battlerDef, predictedMove) == TYPE_ELECTRIC // Move will already be electric type
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_TOPSY_TURVY:
            if (!AI_DATA->targetSameSide)
            {
                u8 targetPositiveStages = CountPositiveStatStages(battlerDef);
                u8 targetNegativeStages = CountNegativeStatStages(battlerDef);

                if (targetPositiveStages == 0 //No good stat changes to make bad
                  || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                    score -= 10;

                else if (targetNegativeStages < targetPositiveStages)
                    score -= 5; //More stages would be made positive than negative
            }
            break;
        case EFFECT_FAIRY_LOCK:
            if ((gFieldStatuses & STATUS_FIELD_FAIRY_LOCK) || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_DO_NOTHING:
            score -= 10;
            break;
        case EFFECT_INSTRUCT:
            {
                u16 instructedMove;
                if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1)
                    instructedMove = predictedMove;
                else
                    instructedMove = gLastMoves[battlerDef];

                if (instructedMove == MOVE_NONE
                  || IsInstructBannedMove(instructedMove)
                  || MoveRequiresRecharging(instructedMove)
                  || MoveCallsOtherMove(instructedMove)
                  #ifdef ITEM_Z_RING
                  || (IsZMove(instructedMove))
                  #endif
                  || (gLockedMoves[battlerDef] != 0 && gLockedMoves[battlerDef] != 0xFFFF)
                  || gBattleMons[battlerDef].status2 & STATUS2_MULTIPLETURNS
                  || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                {
                    score -= 10;
                }
                else if (isDoubleBattle)
                {
                    if (!AI_DATA->targetSameSide)
                        score -= 10;
                }
                else
                {
                    if (gBattleMoves[instructedMove].target & (MOVE_TARGET_SELECTED
                                                             | MOVE_TARGET_DEPENDS
                                                             | MOVE_TARGET_RANDOM
                                                             | MOVE_TARGET_BOTH
                                                             | MOVE_TARGET_FOES_AND_ALLY
                                                             | MOVE_TARGET_OPPONENTS_FIELD)
                      && instructedMove != MOVE_MIND_BLOWN && instructedMove != MOVE_STEEL_BEAM)
                        score -= 10; //Don't force the enemy to attack you again unless it can kill itself with Mind Blown
                    else if (instructedMove != MOVE_MIND_BLOWN)
                        score -= 5; //Do something better
                }
            }
            break;
        case EFFECT_QUASH:
            if (!isDoubleBattle
            || GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1
            || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_AFTER_YOU:
            if (!AI_DATA->targetSameSide
              || !isDoubleBattle
              || GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1
              || PartnerMoveIsSameAsAttacker(AI_DATA->battlerAtkPartner, battlerDef, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_SUCKER_PUNCH:
            if (predictedMove != MOVE_NONE)
            {
                if (IS_MOVE_STATUS(predictedMove) || GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1) // opponent going first
                    score -= 10;
            }
            break;
        case EFFECT_TAILWIND:
            if (gSideTimers[GetBattlerSide(battlerAtk)].tailwindTimer != 0
              || PartnerMoveIs(AI_DATA->battlerAtkPartner, AI_DATA->partnerMove, MOVE_TAILWIND)
              || (gFieldStatuses & STATUS_FIELD_TRICK_ROOM && gFieldTimers.trickRoomTimer > 1)) // Trick Room active and not ending this turn
                score -= 10;
            break;
        case EFFECT_LUCKY_CHANT:
            if (gSideTimers[GET_BATTLER_SIDE(battlerAtk)].luckyChantTimer != 0
              || PartnerMoveIsSameNoTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
                score -= 10;
            break;
        case EFFECT_MAGNET_RISE:
            if (gFieldStatuses & STATUS_FIELD_GRAVITY
              ||  gDisableStructs[battlerAtk].magnetRiseTimer != 0
              || AI_DATA->atkHoldEffect == HOLD_EFFECT_IRON_BALL
              || gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_MAGNET_RISE | STATUS3_SMACKED_DOWN)
              || !IsBattlerGrounded(battlerAtk))
                score -= 10;
            break;
        case EFFECT_CAMOUFLAGE:
            if (!CanCamouflage(battlerAtk))
                score -= 10;
            break;
        case EFFECT_LAST_RESORT:
            if (!CanUseLastResort(battlerAtk))
                score -= 10;
            break;
        case EFFECT_SYNCHRONOISE:
            //Check holding ring target or is of same type
            if (AI_DATA->defHoldEffect == HOLD_EFFECT_RING_TARGET
              || IS_BATTLER_OF_TYPE(battlerDef, gBattleMons[battlerAtk].type1)
              || IS_BATTLER_OF_TYPE(battlerDef, gBattleMons[battlerAtk].type2)
              || IS_BATTLER_OF_TYPE(battlerDef, gBattleMons[battlerAtk].type3))
                break;
            else
                score -= 10;
            break;
        case EFFECT_ERUPTION:
            if (effectiveness <= AI_EFFECTIVENESS_x0_5)
                score--;
            if (GetHealthPercentage(battlerDef) < 50)
                score--;
            break;
        case EFFECT_VITAL_THROW:
            if (IsAiFaster(AI_CHECK_FASTER) && GetHealthPercentage(battlerAtk) < 40)
                score--;    // don't want to move last
            break;
        case EFFECT_FLAIL:
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1 // opponent should go first
              || GetHealthPercentage(battlerAtk) > 50)
                score -= 4;
            break;
        //TODO
        //case EFFECT_PLASMA_FISTS:
            //break;
        //case EFFECT_SHELL_TRAP:
            //break;
        //case EFFECT_BEAK_BLAST:
            //break;
        /*case EFFECT_SKY_DROP:
            if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING))
                score -= 10;
            if (WillFaintFromWeather(battlerAtk)
            ||  MoveBlockedBySubstitute(move, battlerAtk, battlerDef)
            ||  GetSpeciesWeight(gBattleMons[battlerDef].species, AI_DATA->defAbility, AI_DATA->defHoldEffect, battlerDef, TRUE) >= 2000) //200.0 kg
                score -= 10;
            break;
            */
        /*case EFFECT_NO_RETREAT:
            if (TrappedByNoRetreat(battlerAtk))
                score -= 10;
            break;
        case EFFECT_EXTREME_EVOBOOST:
            if (MainStatsMaxed(battlerAtk))
                score -= 10;
            break;
        case EFFECT_CLANGOROUS_SOUL:
            if (gBattleMons[battlerAtk].hp <= gBattleMons[battlerAtk].maxHP / 3)
                score -= 10;
            break;*/
    } // move effect checks
    
    // substitute check
    if (IS_MOVE_STATUS(move) && DoesSubstituteBlockMove(battlerAtk, battlerDef, move))
        score -= 10;
        
    // damage check
    if (!IS_MOVE_STATUS(move))
    {
        if (gMoveResultFlags & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
            score -= 15;
        
        if (effectiveness < AI_EFFECTIVENESS_x1 || GetMoveDamageResult(move) <= MOVE_POWER_WEAK)
            score -= 4;
    }
    
    // helping hand check
    if (isDoubleBattle && AI_DATA->partnerMove != MOVE_NONE 
      && gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_HELPING_HAND
      && IS_MOVE_STATUS(move))
        score -= 10; //Don't use a status move if partner wants to help
    
    return score;
}

static s16 AI_TryToFaint(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    s32 dmg;
    u8 result;
    
    if (IsTargetingPartner(battlerAtk, battlerDef))
        return score;   // don't try to faint your ally ever
    
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power == 0)
        return score;   // can't make anything faint with no power
    
    if (CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0) && gBattleMoves[move].effect != EFFECT_EXPLOSION)
    {
        // AI_TryToFaint_Can
        if (IsAiFaster(AI_CHECK_FASTER) || TestMoveFlags(move, FLAG_HIGH_CRIT))
            score += 4;
        else
            score += 2;
    }
    else
    {
        if (GetMoveDamageResult(move) == MOVE_POWER_DISCOURAGED)
            score--;
        
        if (AI_GetMoveEffectiveness(move) == AI_EFFECTIVENESS_x4)
        {
            // AI_TryToFaint_DoubleSuperEffective
            if ((Random() % 256) >= 80)
                score += 2;
        }
    }
    
    //AI_TryToFaint_CheckIfDanger
    if (!IsAiFaster(AI_CHECK_FASTER) && CanTargetFaintAi(battlerDef, battlerAtk))
    { // AI_TryToFaint_Danger
        if (GetMoveDamageResult(move) != MOVE_POWER_BEST)
            score--;
        else
            score++;
    }
    
    return score;
}

static s16 AI_CheckPartner(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    //TODO
    return score;
}

static s16 AI_CheckGoodMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    // move data
    u16 moveEffect = gBattleMoves[move].effect;
    u8 effectiveness = AI_GetMoveEffectiveness(move);
    u8 atkPriority = GetMovePriority(battlerAtk, move);
    u16 predictedMove = gLastMoves[battlerDef]; //for now
    bool32 isDoubleBattle = IsValidDoubleBattle(battlerAtk);
    u32 i;
    
    // targeting partner, check benefits of doing that instead
    if (isDoubleBattle && AI_DATA->targetSameSide)
        return AI_CheckPartner(battlerAtk, AI_DATA->battlerAtkPartner, move, score);
    
    // check move results
    if (gMoveResultFlags & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
        return 0;
    
    // if target goes first and can kill us, lets try to use a priority move to at least do something
    if ((gBattleMons[battlerDef].status2 & (STATUS2_RECHARGE | STATUS2_BIDE))
      && CanTargetFaintAi(battlerAtk, battlerDef)
      && IsAiFaster(AI_CHECK_SLOWER)
      && atkPriority > 0)
        score += 5;
    
    // if target is evasive (or we have low accuracy)) and this move always hits, boost its score
    if (!IS_MOVE_STATUS(move) && gBattleMoves[move].accuracy == 0)
    {
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] >= 8)
            score++;
        else if (gBattleMons[battlerAtk].statStages[STAT_ACC] <= 4)
            score++;
    }
    
    // prefer good damaging moves
    if (GetMoveDamageResult(move) == MOVE_POWER_BEST)
        score += 2;

    // check status move preference
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_PREFER_STATUS_MOVES && IS_MOVE_STATUS(move))
        score++;
    
    // check high crit
    if (TestMoveFlags(move, FLAG_HIGH_CRIT) && effectiveness >= AI_EFFECTIVENESS_x2)
        score++;
    
    // check thawing moves
    if ((gBattleMons[battlerAtk].status1 & STATUS1_FREEZE) && IsThawingMove(move))
        score += (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) ? 20 : 10;
    
    // ability checks
    switch (AI_DATA->atkAbility)
    {
    case ABILITY_MOXIE:
    case ABILITY_BEAST_BOOST:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0) // attacker should go first
        {
            if (CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
                score += 8; // prioritize killing target for stat boost
        }
        break;
    } // ability checks
    
    // move effect checks
    switch (moveEffect)
    {
    case EFFECT_HIT:
        break;
    case EFFECT_SLEEP:
    case EFFECT_YAWN:
        IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_DREAM_EATER:
        if (!(gBattleMons[battlerDef].status1 & STATUS1_SLEEP))
            break;
        score++;    // if target is asleep, dream eater is a pretty good move even without draining
        // fallthrough
    case EFFECT_ABSORB:
        if (ShouldAbsorb(battlerAtk, battlerDef, move, AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex]))
            score += 2;
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_BIG_ROOT)
            score++;
        break;
    case EFFECT_EXPLOSION:
    case EFFECT_MEMENTO:
        if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_WILL_SUICIDE && gBattleMons[battlerDef].statStages[STAT_EVASION] < 7)
        {
            if (GetHealthPercentage(battlerAtk) < 50 && (Random() % 2))
                score++;
        }
        break;
    case EFFECT_MIRROR_MOVE:
        if (gLastMoves[battlerDef] != MOVE_NONE)
            return AI_CheckGoodMove(battlerAtk, battlerDef, gLastMoves[battlerDef], score);
        break;    
    case EFFECT_ATTACK_UP:
    case EFFECT_ATTACK_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        break;
    case EFFECT_DEFENSE_UP:
    case EFFECT_DEFENSE_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_DEF, &score);
        break;
    case EFFECT_SPEED_UP:
    case EFFECT_SPEED_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);
        break;
    case EFFECT_SPECIAL_ATTACK_UP:
    case EFFECT_SPECIAL_ATTACK_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPATK, &score);
        break;
    case EFFECT_SPECIAL_DEFENSE_UP:
    case EFFECT_SPECIAL_DEFENSE_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_ACCURACY_UP:
    case EFFECT_ACCURACY_UP_2:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ACC, &score);
        break;
    case EFFECT_EVASION_UP:
    case EFFECT_EVASION_UP_2:
    case EFFECT_MINIMIZE:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_EVASION, &score);
        break;
    case EFFECT_ACUPRESSURE:
        break;
    case EFFECT_ATTACK_ACCURACY_UP: // hone claws
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ACC, &score);
        break;
    case EFFECT_GROWTH:
    case EFFECT_ATTACK_SPATK_UP:    // work up
        if (GetHealthPercentage(battlerAtk) <= 40 || AI_DATA->atkAbility == ABILITY_CONTRARY)
            break;
        
        if (HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
            IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        else if (HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
            IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPATK, &score);
        break;
    case EFFECT_ATTACK_DOWN:
    case EFFECT_ATTACK_DOWN_2:
        if (ShouldLowerAttack(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 2;
        break;
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_DEFENSE_DOWN_2:
        if (ShouldLowerDefense(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 2;
        break;
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPEED_DOWN_2:
        if (ShouldLowerSpeed(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 3;
        break;
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
        if (ShouldLowerSpAtk(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 2;
        break;
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
        if (ShouldLowerSpDef(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 2;
        break;
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_ACCURACY_DOWN_2:
        if (ShouldLowerAccuracy(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
            score += 4;
        break;
    case EFFECT_EVASION_DOWN:
    case EFFECT_EVASION_DOWN_2:
        if (ShouldLowerEvasion(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
        {
            // kinda meh effect, so let's make sure we really want to
            if (gBattleMons[battlerDef].statStages[STAT_EVASION] > 7
              || HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, TRUE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
                score += 2; // encourage lowering evasion if they are evasive or we have a move with low accuracy
            else
                score++;
        }
        break;
    case EFFECT_HAZE:
        if (AnyStatIsRaised(AI_DATA->battlerAtkPartner)
          || PartnerHasSameMoveEffectWithoutTarget(AI_DATA->battlerAtkPartner, move, AI_DATA->partnerMove))
            break;
        // fallthrough
    case EFFECT_ROAR:
    case EFFECT_CLEAR_SMOG:
        if (isDoubleBattle)
            score += min(CountPositiveStatStages(battlerDef) + CountPositiveStatStages(AI_DATA->battlerDefPartner), 7);
        else
            score += min(CountPositiveStatStages(battlerDef), 4);
        break;
    case EFFECT_BIDE:
        break;
    case EFFECT_MULTI_HIT:
    case EFFECT_DOUBLE_HIT:
    case EFFECT_TRIPLE_KICK:
        break;
    case EFFECT_CONVERSION:
        if (!IS_BATTLER_OF_TYPE(battlerAtk, gBattleMoves[gBattleMons[battlerAtk].moves[0]].type))
            score++;
        break;
    case EFFECT_FLINCH_HIT:
        score += ShouldTryToFlinch(battlerAtk, battlerDef, AI_DATA->atkAbility, AI_DATA->defAbility, move);
        break;
    case EFFECT_SWALLOW:
        if (gDisableStructs[battlerAtk].stockpileCounter == 0)
        {
            break;
        }
        else
        {
            u32 healPercent = 0;
            switch (gDisableStructs[battlerAtk].stockpileCounter)
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
                score += 2;
        }
        break;
    case EFFECT_RESTORE_HP:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
        if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            score += 3;
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_BIG_ROOT)
            score++;
        break;
    case EFFECT_TOXIC:
    case EFFECT_POISON:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_LIGHT_SCREEN:
    case EFFECT_REFLECT:
    case EFFECT_AURORA_VEIL:
        if (ShouldSetScreen(battlerAtk, battlerDef, move))
        {
            score += 5;
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_LIGHT_CLAY)
                score += 2;
            if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_SCREENER)
                score += 2;
        }
        break;
    case EFFECT_REST:
        if (!(CanSleep(battlerAtk, AI_DATA->atkAbility)))
        {
            break;
        }
        else if (ShouldRecover(battlerAtk, battlerDef, move, 100))
        {
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_CURE_SLP
              || AI_DATA->atkHoldEffect == HOLD_EFFECT_CURE_STATUS
              || HasMoveEffect(EFFECT_SLEEP_TALK, battlerAtk)
              || HasMoveEffect(EFFECT_SNORE, battlerAtk)
              || AI_DATA->atkAbility == ABILITY_SHED_SKIN
              || AI_DATA->atkAbility == ABILITY_EARLY_BIRD
              || (gBattleWeather & WEATHER_RAIN_ANY && gWishFutureKnock.weatherDuration != 1 && AI_DATA->atkAbility == ABILITY_HYDRATION && AI_DATA->atkHoldEffect != HOLD_EFFECT_UTILITY_UMBRELLA))
            {
                score += 2;
            }
            else
            {
                score++;
            }
        }
        break;
    case EFFECT_OHKO:
        if (gStatuses3[battlerAtk] & STATUS3_ALWAYS_HITS)
            score += 5;
        break;
    case EFFECT_TRAP:
    case EFFECT_MEAN_LOOK:
        if (HasMoveEffect(battlerDef, EFFECT_RAPID_SPIN)
          || IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST)
          || gBattleMons[battlerDef].status2 & STATUS2_WRAPPED)
        {
            break; // in this case its a bad attacking move
        }
        else if (ShouldTrap(battlerAtk, battlerDef, move))
        {
            score += 5;
        }
        break;
    case EFFECT_MIST:
        if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_SCREENER)
            score += 2;
        break;
    case EFFECT_FOCUS_ENERGY:
    case EFFECT_LASER_FOCUS:
        if (AI_DATA->atkAbility == ABILITY_SUPER_LUCK
          || AI_DATA->atkAbility == ABILITY_SNIPER
          || AI_DATA->atkHoldEffect == HOLD_EFFECT_SCOPE_LENS
          || TestMoveFlagsInMoveset(battlerAtk, FLAG_HIGH_CRIT))
            score += 2;
        break;
    case EFFECT_CONFUSE_HIT:
        if (AI_DATA->atkAbility == ABILITY_SERENE_GRACE)
            score++;
        //fallthrough
    case EFFECT_CONFUSE:
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_PARALYZE:
        IncreaseParalyzeScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_ATTACK_DOWN_HIT:
    case EFFECT_DEFENSE_DOWN_HIT:
    case EFFECT_SPECIAL_ATTACK_DOWN_HIT:
    case EFFECT_SPECIAL_DEFENSE_DOWN_HIT:
    case EFFECT_ACCURACY_DOWN_HIT:
    case EFFECT_EVASION_DOWN_HIT:
        if (AI_DATA->atkAbility == ABILITY_SERENE_GRACE && AI_DATA->defAbility != ABILITY_CONTRARY)
            score += 2;
        break;
    case EFFECT_SPEED_DOWN_HIT:
        if (ShouldLowerSpeed(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
        {
            if (AI_DATA->atkAbility == ABILITY_SERENE_GRACE && AI_DATA->defAbility != ABILITY_CONTRARY)
                score += 4;
            else
                score += 2;
        }
        break;
    case EFFECT_SUBSTITUTE:
        if (gStatuses3[battlerDef] & STATUS3_PERISH_SONG)
            score += 3;
        if (gBattleMons[battlerDef].status1 & (STATUS1_BURN | STATUS1_PSN_ANY))
            score++;
        if (HasMoveEffect(battlerDef, EFFECT_SLEEP)
          || HasMoveEffect(battlerDef, EFFECT_TOXIC)
          || HasMoveEffect(battlerDef, EFFECT_POISON)
          || HasMoveEffect(battlerDef, EFFECT_PARALYZE)
          || HasMoveEffect(battlerDef, EFFECT_WILL_O_WISP)
          || HasMoveEffect(battlerDef, EFFECT_CONFUSE)
          || HasMoveEffect(battlerDef, EFFECT_LEECH_SEED))
            score += 2;
        if (!gBattleMons[battlerDef].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION && GetHealthPercentage(battlerAtk) > 70))
            score++;
        break;
    case EFFECT_MIMIC:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)
        {
            if (gLastMoves[battlerDef] != MOVE_NONE && gLastMoves[battlerDef] != 0xFFFF)
                return AI_CheckGoodMove(battlerAtk, battlerDef, gLastMoves[battlerDef], score);
        }
        break;
    case EFFECT_LEECH_SEED:
        if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS)
          || gStatuses3[battlerDef] & STATUS3_LEECHSEED
          || HasMoveEffect(battlerDef, EFFECT_RAPID_SPIN)
          || AI_DATA->defAbility == ABILITY_LIQUID_OOZE
          || AI_DATA->defAbility == ABILITY_MAGIC_GUARD)
            break;
        score += 3;
        if (!HasDamagingMove(battlerDef) || IsBattlerTrapped(battlerDef, FALSE))
            score += 2;
        break;
    case EFFECT_DO_NOTHING:
        //todo - check z splash, z celebrate, z happy hour (lol)
        break;
    case EFFECT_TELEPORT:
        if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battlerAtk) != B_SIDE_PLAYER)
            break;
        //fallthrough
    case EFFECT_HIT_ESCAPE:
    case EFFECT_PARTING_SHOT:
        if (!IsDoubleBattle())
        {
            switch (ShouldPivot(battlerAtk, battlerDef, AI_DATA->defAbility, move, AI_THINKING_STRUCT->movesetIndex))
            {
            case 0: // no
                score -= 10;    // technically should go in CheckBadMove, but this is easier/less computationally demanding
                break;
            case 1: // maybe
                break;
            case 2: // yes
                score += 7;
                break;
            }
        }
        else //Double Battle
        {
            if (CountUsablePartyMons(battlerAtk) == 0)
                break; // Can't switch

            //if (switchAbility == ABILITY_INTIMIDATE && PartyHasMoveSplit(battlerDef, SPLIT_PHYSICAL))
                //score += 7;
        }
        break;
    case EFFECT_BATON_PASS:
        if (ShouldSwitch() && (gBattleMons[battlerAtk].status2 & STATUS2_SUBSTITUTE
          || (gStatuses3[battlerAtk] & (STATUS3_ROOTED | STATUS3_AQUA_RING | STATUS3_MAGNET_RISE | STATUS3_POWER_TRICK))
          || AnyStatIsRaised(battlerAtk)))
            score += 5;
        break;
    case EFFECT_DISABLE:
        if (gDisableStructs[battlerDef].disableTimer == 0
          && (B_MENTAL_HERB >= GEN_5 && AI_DATA->defHoldEffect != HOLD_EFFECT_CURE_ATTRACT))    // mental herb
        {
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)  // AI goes first
            {
                if (gLastMoves[battlerDef] != MOVE_NONE
                  && gLastMoves[battlerDef] != 0xFFFF)
                {
                    /* TODO predicted moves
                    if (gLastMoves[battlerDef] == predictedMove)
                        score += 3;
                    else */if (CanMoveFaintBattler(gLastMoves[battlerDef], battlerDef, battlerAtk, 1))
                        score += 2;; //Disable move that can kill attacker
                }
            }
            else if (predictedMove != MOVE_NONE && IS_MOVE_STATUS(predictedMove))
            {
                score++; // Disable annoying status moves
            }
        }
        break;
    case EFFECT_ENCORE:
        if (gDisableStructs[battlerDef].encoreTimer == 0
          && (B_MENTAL_HERB >= GEN_5 && AI_DATA->defHoldEffect != HOLD_EFFECT_CURE_ATTRACT))    // mental herb
        {
            if (IsEncoreEncouragedEffect(gBattleMoves[gLastMoves[battlerDef]].effect))
                score += 3;
        }
        break;
    case EFFECT_PAIN_SPLIT:
        {
            u16 newHp = (gBattleMons[battlerAtk].hp + gBattleMons[battlerDef].hp) / 2;
            u16 healthBenchmark = (gBattleMons[battlerAtk].hp * 12) / 10;
            if (newHp > healthBenchmark && ShouldAbsorb(battlerAtk, battlerDef, move, AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex]))
                score += 2;
        }
        break;    
    case EFFECT_SLEEP_TALK:
    case EFFECT_SNORE:
        if (!IsWakeupTurn(battlerAtk) && gBattleMons[battlerAtk].status1 & STATUS1_SLEEP)
            score += 10;
        break;
    case EFFECT_LOCK_ON:
        if (HasMoveEffect(battlerAtk, EFFECT_OHKO))
            score += 3;
        else if (AI_DATA->atkAbility == ABILITY_COMPOUND_EYES && HasMoveWithLowAccuracy(battlerAtk, battlerDef, 80, TRUE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
            score += 3;
        else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 85, TRUE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
            score += 3;
        else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, TRUE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
            score++;
        break;
    case EFFECT_SPEED_UP_HIT:
        if (AI_DATA->atkAbility == ABILITY_SERENE_GRACE && AI_DATA->defAbility != ABILITY_CONTRARY && IsAiFaster(AI_CHECK_SLOWER))
            score += 3;
        break;
    case EFFECT_DESTINY_BOND:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0 && CanTargetFaintAi(battlerDef, battlerAtk))
            score += 3;
        break;
    case EFFECT_SPITE:
        //TODO - predicted move
        break;
    case EFFECT_WISH:
    case EFFECT_HEAL_BELL:
        if (ShouldUseWishAromatherapy(battlerAtk, battlerDef, move))
            score += 7;
        break;
    case EFFECT_THIEF:
        {
            bool32 canSteal = FALSE;
            
            #if defined B_TRAINERS_KNOCK_OFF_ITEMS && B_TRAINERS_KNOCK_OFF_ITEMS == TRUE
                canSteal = TRUE;
            #endif
            if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER || GetBattlerSide(battlerAtk) == B_SIDE_PLAYER)
                canSteal = TRUE;
            
            if (canSteal && AI_DATA->atkItem == ITEM_NONE
              && AI_DATA->defItem != ITEM_NONE
              && CanBattlerGetOrLoseItem(battlerDef, AI_DATA->defItem)
              && CanBattlerGetOrLoseItem(battlerAtk, AI_DATA->defItem)
              && !HasMoveEffect(battlerAtk, EFFECT_ACROBATICS)
              && AI_DATA->defAbility != ABILITY_STICKY_HOLD)
            {
                switch (AI_DATA->defHoldEffect)
                {
                case HOLD_EFFECT_NONE:
                    break;
                case HOLD_EFFECT_CHOICE_BAND:
                case HOLD_EFFECT_CHOICE_SCARF:
                case HOLD_EFFECT_CHOICE_SPECS:
                    score += 2;
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoisonSelf(battlerAtk, AI_DATA->atkAbility))
                        score += 2;
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurnSelf(battlerAtk, AI_DATA->atkAbility))
                        score += 2;
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON))
                        score += 2;
                    break;
                case HOLD_EFFECT_IRON_BALL:
                    if (HasMoveEffect(battlerAtk, EFFECT_FLING))
                        score += 2;
                    break;
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                default:
                    score++;
                    break;
                }
            }
            break;
        }
        break;
    case EFFECT_NIGHTMARE:
        if (AI_DATA->defAbility != ABILITY_MAGIC_GUARD
          && !(gBattleMons[battlerDef].status2 & STATUS2_NIGHTMARE)
          && (AI_DATA->defAbility == ABILITY_COMATOSE || gBattleMons[battlerDef].status1 & STATUS1_SLEEP))
        {
            score += 5;
            if (IsBattlerTrapped(battlerDef, TRUE))
                score += 3;
        }
        break;
    case EFFECT_CURSE:
        if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
        {
            if (IsBattlerTrapped(battlerDef, TRUE))
                score += 3;
            else
                score++;
            break;
        }
        else
        {
            if (AI_DATA->atkAbility == ABILITY_CONTRARY || AI_DATA->defAbility == ABILITY_MAGIC_GUARD)
                break;
            else if (gBattleMons[battlerAtk].statStages[STAT_ATK] < 8)
                score += (8 - gBattleMons[battlerAtk].statStages[STAT_ATK]);
            else if (gBattleMons[battlerAtk].statStages[STAT_SPEED] < 3)
                break;
            else if (gBattleMons[battlerAtk].statStages[STAT_DEF] < 8)
                score += (8 - gBattleMons[battlerAtk].statStages[STAT_DEF]);
        }
        break;
    case EFFECT_PROTECT:
        if (predictedMove == 0xFFFF)
            predictedMove = MOVE_NONE;
        switch (move)
        {
        case MOVE_QUICK_GUARD:
            if (predictedMove != MOVE_NONE && gBattleMoves[predictedMove].priority > 0)
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;
        case MOVE_WIDE_GUARD:
            if (predictedMove != MOVE_NONE && gBattleMoves[predictedMove].target & (MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_BOTH))
            {
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            }
            else if (isDoubleBattle && gBattleMoves[AI_DATA->partnerMove].target & MOVE_TARGET_FOES_AND_ALLY)
            {
                if (AI_DATA->atkAbility != ABILITY_TELEPATHY)
                  ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            }
            break;
        case MOVE_CRAFTY_SHIELD:
            if (predictedMove != MOVE_NONE && IS_MOVE_STATUS(predictedMove) && !(gBattleMoves[predictedMove].target & MOVE_TARGET_USER))
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;

        case MOVE_MAT_BLOCK:
            if (gDisableStructs[battlerAtk].isFirstTurn && predictedMove != MOVE_NONE
              && !IS_MOVE_STATUS(predictedMove) && !(gBattleMoves[predictedMove].target & MOVE_TARGET_USER))
                ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;
        case MOVE_KINGS_SHIELD:
            #if (defined SPECIES_AEGISLASH && defined SPECIES_AEGISLASH_BLADE)
            if (AI_DATA->atkAbility == ABILITY_STANCE_CHANGE //Special logic for Aegislash
              && AI_DATA->atkSpecies == SPECIES_AEGISLASH_BLADE
              && !IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility))
            {
                score += 3;
                break;
            }
            #endif
            //fallthrough
        default: // protect
            ProtectChecks(battlerAtk, battlerDef, move, predictedMove, &score);
            break;
        }
        break;
    case EFFECT_ENDURE:
        if (CanTargetFaintAi(battlerDef, battlerAtk))
        {
            if (gBattleMons[battlerAtk].hp > gBattleMons[battlerAtk].maxHP / 4 // Pinch berry couldn't have activated yet
              && IsPinchBerryItemEffect(AI_DATA->atkHoldEffect))
            {
                score += 3;
            }
            else if (gBattleMons[battlerAtk].hp > 1) // Only spam endure for Flail/Reversal if you're not at Min Health
            {
                if (HasMoveEffect(battlerAtk, EFFECT_FLAIL) || HasMoveEffect(battlerAtk, EFFECT_ENDEAVOR))
                    score += 3;
            }
        }
        break;

    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_TOXIC_SPIKES:
        if (AI_DATA->defAbility == ABILITY_MAGIC_BOUNCE || CountUsablePartyMons(battlerDef) == 0)
            break;
        if (gDisableStructs[battlerAtk].isFirstTurn)
            score += 2;        
        //TODO - track entire opponent party data to determine hazard effectiveness 
        break;
    case EFFECT_FORESIGHT:
        if (AI_DATA->atkAbility == ABILITY_SCRAPPY)
            break;
        else if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
         || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GHOST)
         && (HasMoveWithType(battlerAtk, TYPE_NORMAL)
         || HasMoveWithType(battlerAtk, TYPE_FIGHTING))))
            score += 2;
        break;
    case EFFECT_MIRACLE_EYE:
        if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
          || (IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK) && (HasMoveWithType(battlerAtk, TYPE_PSYCHIC))))
            score += 2;
        break;
    case EFFECT_PERISH_SONG:
        if (IsBattlerTrapped(battlerDef, TRUE))
            score += 3;
        break;
    case EFFECT_SANDSTORM:
        if (ShouldSetSandstorm(battlerAtk, AI_DATA->atkHoldEffect, AI_DATA->atkHoldEffect))
        {
            score++;
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_SMOOTH_ROCK)
                score++;
            if (isDoubleBattle && IsBattlerAlive(AI_DATA->battlerAtkPartner)
              && ShouldSetSandstorm(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, AI_DATA->atkPartnerHoldEffect))
                score += 2;
        }
        break;
    case EFFECT_HAIL:
        if (ShouldSetHail(battlerAtk, AI_DATA->atkAbility, AI_DATA->atkHoldEffect))
        {
            if ((HasMoveEffect(battlerAtk, EFFECT_AURORA_VEIL) || HasMoveEffect(AI_DATA->battlerAtkPartner, EFFECT_AURORA_VEIL))
              && ShouldSetScreen(battlerAtk, battlerDef, EFFECT_AURORA_VEIL))
                score += 3;
            
            score++;
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_ICY_ROCK)
                score++;
            if (isDoubleBattle && IsBattlerAlive(AI_DATA->battlerAtkPartner)
              && ShouldSetHail(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, AI_DATA->atkPartnerHoldEffect))
                score += 2;
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN)
              || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS)
              || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                score += 2;
        }
        break;
    case EFFECT_RAIN_DANCE:
        if (ShouldSetRain(battlerAtk, AI_DATA->atkAbility, AI_DATA->atkHoldEffect))
        {
            score++;
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_DAMP_ROCK)
                score++;
            if (isDoubleBattle && IsBattlerAlive(AI_DATA->battlerAtkPartner)
              && ShouldSetRain(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, AI_DATA->atkPartnerHoldEffect))
                score += 2;
            if (HasMoveEffect(battlerDef, EFFECT_MORNING_SUN)
              || HasMoveEffect(battlerDef, EFFECT_SYNTHESIS)
              || HasMoveEffect(battlerDef, EFFECT_MOONLIGHT))
                score += 2;
            if (HasMoveWithType(battlerDef, TYPE_FIRE) || HasMoveWithType(AI_DATA->battlerDefPartner, TYPE_FIRE))
                score++;
        }
        break;
    case EFFECT_SUNNY_DAY:
        if (ShouldSetSun(battlerAtk, AI_DATA->atkAbility, AI_DATA->atkHoldEffect))
        {
            score++;
            if (isDoubleBattle && IsBattlerAlive(AI_DATA->battlerAtkPartner)
              && ShouldSetSun(AI_DATA->battlerAtkPartner, AI_DATA->atkPartnerAbility, AI_DATA->atkPartnerHoldEffect))
                score += 2; // partner also gets sunlight benefit
            if (AI_DATA->atkHoldEffect == HOLD_EFFECT_HEAT_ROCK)
                score++;
            if (HasMoveWithType(battlerDef, TYPE_WATER) || HasMoveWithType(AI_DATA->battlerDefPartner, TYPE_WATER))
                score++;
            if (HasMoveEffect(battlerDef, EFFECT_THUNDER) || HasMoveEffect(AI_DATA->battlerDefPartner, EFFECT_THUNDER))
                score++;
        }
        break;
    case EFFECT_ATTACK_UP_HIT:
        if (AI_DATA->atkAbility == ABILITY_SERENE_GRACE)
            IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        break;
    case EFFECT_FELL_STINGER:
        if (gBattleMons[battlerAtk].statStages[STAT_ATK] < MAX_STAT_STAGE
          && AI_DATA->atkAbility != ABILITY_CONTRARY
          && CanAttackerFaintTarget(battlerAtk, battlerDef, AI_THINKING_STRUCT->movesetIndex, 0))
        {
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)  // Attacker goes first
                score += 9;
            else
                score += 3;
        }
        break;
    case EFFECT_BELLY_DRUM:
        if (!CanTargetFaintAi(battlerDef, battlerAtk) && HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL) && AI_DATA->atkAbility != ABILITY_CONTRARY)
            score += (MAX_STAT_STAGE - gBattleMons[battlerAtk].statStages[STAT_ATK]);
        break;
    case EFFECT_PSYCH_UP:
    case EFFECT_SPECTRAL_THIEF:
        // Want to copy positive stat changes
        for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
        {            
            if (gBattleMons[battlerDef].statStages[i] > gBattleMons[battlerAtk].statStages[i])
            {
                switch (i)
                {
                case STAT_ATK:
                    if (HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                        score++;
                    break;
                case STAT_SPATK:
                    if (HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL))
                        score++;
                    break;
                case STAT_ACC:
                case STAT_EVASION:
                case STAT_SPEED:
                    score++;
                    break;
                case STAT_DEF:
                case STAT_SPDEF:
                    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_STALL)
                        score++;
                    break;
                }
            }
        }
        break;
    case EFFECT_SEMI_INVULNERABLE:
        score++;
        if (predictedMove != MOVE_NONE && !isDoubleBattle)
        {
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)  // Attacker goes first
            {
                if (gBattleMoves[predictedMove].effect == EFFECT_EXPLOSION
                  || gBattleMoves[predictedMove].effect == EFFECT_PROTECT)
                    score += 3;
            }
            else if (gBattleMoves[predictedMove].effect == EFFECT_SEMI_INVULNERABLE && !(gStatuses3[battlerDef] & STATUS3_SEMI_INVULNERABLE))
            {
                score += 3;
            }
        }
        break;
    case EFFECT_DEFENSE_CURL:
        if (HasMoveEffect(battlerAtk, EFFECT_ROLLOUT) && !(gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL))
            score++;
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_DEF, &score);
        break;
    case EFFECT_FAKE_OUT:
        if (move == MOVE_FAKE_OUT    // filter out first impression
          && ShouldFakeOut(battlerAtk, battlerDef, move))
            score += 8;
        break;
    case EFFECT_STOCKPILE:
        if (AI_DATA->atkAbility == ABILITY_CONTRARY)
            break;
        if (HasMoveEffect(battlerAtk, EFFECT_SWALLOW)
          || HasMoveEffect(battlerAtk, EFFECT_SPIT_UP))
            score += 2;
            
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_DEF, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_SPIT_UP:
        if (gDisableStructs[battlerAtk].stockpileCounter >= 2)
            score++;
        break;
    case EFFECT_ROLLOUT:
        if (gBattleMons[battlerAtk].status2 & STATUS2_DEFENSE_CURL)
            score += 8;
        break;
    case EFFECT_SWAGGER:
        if (HasMoveEffect(battlerAtk, EFFECT_FOUL_PLAY)
          || HasMoveEffect(battlerAtk, EFFECT_PSYCH_UP)
          || HasMoveEffect(battlerAtk, EFFECT_SPECTRAL_THIEF))
            score++;
        
        if (AI_DATA->defAbility == ABILITY_CONTRARY)
            score += 2;
        
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FLATTER:
        if (HasMoveEffect(battlerAtk, EFFECT_PSYCH_UP)
          || HasMoveEffect(battlerAtk, EFFECT_SPECTRAL_THIEF))
            score += 2;
        
        if (AI_DATA->defAbility == ABILITY_CONTRARY)
            score += 2;
        
        IncreaseConfusionScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FURY_CUTTER:
        if (!isDoubleBattle && AI_DATA->atkHoldEffect == HOLD_EFFECT_METRONOME)
            score += 3;
        break;
    case EFFECT_ATTRACT:
        if (!isDoubleBattle && BattlerWillFaintFromSecondaryDamage(battlerDef, AI_DATA->defAbility)
          && GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1) // Target goes first
            break; // Don't use if the attract won't have a change to activate

        if (gBattleMons[battlerDef].status1 & STATUS1_ANY
          || (gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
          || IsBattlerTrapped(battlerDef, TRUE))
            score += 2;
        else
            score++;
        break;
    case EFFECT_SAFEGUARD:
        if (!(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN) || !IsBattlerGrounded(battlerAtk))
            score++;
        //if (CountUsablePartyMons(battlerDef) != 0)
            //score += 8;
        break;
    case EFFECT_PURSUIT:
        /*TODO
        if (IsPredictedToSwitch(battlerDef, battlerAtk))
            score += 3;
        else if (IsPredictedToUsePursuitableMove(battlerDef, battlerAtk) && !MoveWouldHitFirst(move, battlerAtk, battlerDef)) //Pursuit against fast U-Turn
            score += 3;*/
        break;
    case EFFECT_RAPID_SPIN:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);    // Gen 8 increases speed
        //fallthrough
    case EFFECT_DEFOG:
        if (gSideStatuses[GetBattlerSide(battlerAtk)] & SIDE_STATUS_HAZARDS_ANY && CountUsablePartyMons(battlerAtk) != 0)
        {
            score += 3;
            break;
        }
        
        switch (move)
        {
        case MOVE_DEFOG:
            if (gSideStatuses[GetBattlerSide(battlerDef)] & (SIDE_STATUS_SCREEEN_ANY | SIDE_STATUS_SAFEGUARD | SIDE_STATUS_MIST))
            {
                score += 3;
            }
            else if (!(gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SPIKES)) //Don't blow away hazards if you set them up
            {
                if (isDoubleBattle)
                {
                    if (IsHazardMoveEffect(gBattleMoves[AI_DATA->partnerMove].effect) // Partner is going to set up hazards
                      && GetWhoStrikesFirst(battlerAtk, AI_DATA->battlerAtkPartner, TRUE) == 1) // Partner going first
                        break; // Don't use Defog if partner is going to set up hazards
                }
                
                // check defog lowering evasion
                if (ShouldLowerEvasion(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
                {
                    if (gBattleMons[battlerDef].statStages[STAT_EVASION] > 7
                      || HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, TRUE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
                        score += 2; // encourage lowering evasion if they are evasive or we have a move with low accuracy
                    else
                        score++;
                }
            }
            break;
        case MOVE_RAPID_SPIN:
            if (gStatuses3[battlerAtk] & STATUS3_LEECHSEED || gBattleMons[battlerAtk].status2 & STATUS2_WRAPPED)
                score += 3;
            break;
        }
        break;
    case EFFECT_TORMENT:
        break;
    case EFFECT_WILL_O_WISP:
        IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
        break;
    case EFFECT_FOLLOW_ME:
        if (isDoubleBattle
          && move != MOVE_SPOTLIGHT
          && !IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility)
          && (move != MOVE_RAGE_POWDER || IsAffectedByPowder(battlerDef, AI_DATA->defAbility, AI_DATA->defHoldEffect)) // Rage Powder doesn't affect powder immunities
          && IsBattlerAlive(AI_DATA->battlerAtkPartner))
        {
            u16 predictedMoveOnPartner = gLastMoves[AI_DATA->battlerAtkPartner];
            if (predictedMoveOnPartner != MOVE_NONE && !IS_MOVE_STATUS(predictedMoveOnPartner))
                score += 3;
        }
        break;
    case EFFECT_NATURE_POWER:
        return AI_CheckGoodMove(battlerAtk, battlerDef, GetNaturePowerMove(), score);
    case EFFECT_CHARGE:
        if (HasDamagingMoveOfType(battlerAtk, TYPE_ELECTRIC))
            score += 2;
        
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_TAUNT:
        if (IS_MOVE_STATUS(predictedMove))
            score += 3;
        else if (HasMoveWithSplit(battlerDef, SPLIT_STATUS))
            score += 2;
        break;
    case EFFECT_TRICK:
    case EFFECT_BESTOW:
        switch (AI_DATA->atkHoldEffect)
        {
        case HOLD_EFFECT_CHOICE_SCARF:
            score += 2; // assume its beneficial
            break;
        case HOLD_EFFECT_CHOICE_BAND:
            if (!HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL))
                score += 2;
            break;
        case HOLD_EFFECT_CHOICE_SPECS:
            if (!HasMoveWithSplit(battlerDef, SPLIT_SPECIAL))
                score += 2;
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            if (!ShouldPoisonSelf(battlerAtk, AI_DATA->atkAbility) && CanBePoisoned(battlerDef, AI_DATA->defAbility))
                score += 2;
            break;
        case HOLD_EFFECT_FLAME_ORB:
            if (!ShouldBurnSelf(battlerAtk, AI_DATA->atkAbility) && CanBeBurned(battlerAtk, AI_DATA->defAbility))
                score += 2;
            break;
        case HOLD_EFFECT_BLACK_SLUDGE:
            if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON) && AI_DATA->defAbility != ABILITY_MAGIC_GUARD)
                score += 3;
            break;
        case HOLD_EFFECT_IRON_BALL:
            if (!HasMoveEffect(battlerDef, EFFECT_FLING) || !IsBattlerGrounded(battlerDef))
                score += 2;
            break;
        case HOLD_EFFECT_LAGGING_TAIL:
        case HOLD_EFFECT_STICKY_BARB:
            score += 3;
            break;
        case HOLD_EFFECT_UTILITY_UMBRELLA:
            if (AI_DATA->atkAbility != ABILITY_SOLAR_POWER && AI_DATA->atkAbility != ABILITY_DRY_SKIN && AI_WeatherHasEffect())
            {
                switch (AI_DATA->defAbility)
                {
                case ABILITY_SWIFT_SWIM:
                    if (gBattleWeather & WEATHER_RAIN_ANY)
                        score += 3; // Slow 'em down
                    break;
                case ABILITY_CHLOROPHYLL:
                case ABILITY_FLOWER_GIFT:
                    if (gBattleWeather & WEATHER_SUN_ANY)
                        score += 3; // Slow 'em down
                    break;
                }
            }
            break;
        case HOLD_EFFECT_EJECT_BUTTON:
            //if (!IsRaidBattle() && IsDynamaxed(battlerDef) && gNewBS->dynamaxData.timer[battlerDef] > 1 &&
            if (HasDamagingMove(battlerAtk)
             || (isDoubleBattle && IsBattlerAlive(AI_DATA->battlerAtkPartner) && HasDamagingMove(AI_DATA->battlerAtkPartner)))
                score += 2; // Force 'em out next turn
            break;
        default:
            if (move != MOVE_BESTOW && AI_DATA->atkItem == ITEM_NONE)
            {
                switch (AI_DATA->defHoldEffect)
                {
                case HOLD_EFFECT_CHOICE_BAND:
                    break;
                case HOLD_EFFECT_TOXIC_ORB:
                    if (ShouldPoisonSelf(battlerAtk, AI_DATA->atkAbility))
                        score += 2;
                    break;
                case HOLD_EFFECT_FLAME_ORB:
                    if (ShouldBurnSelf(battlerAtk, AI_DATA->atkAbility))
                        score += 2;
                    break;
                case HOLD_EFFECT_BLACK_SLUDGE:
                    if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON) || AI_DATA->atkAbility == ABILITY_MAGIC_GUARD)
                        score += 3;
                    break;
                case HOLD_EFFECT_IRON_BALL:
                    if (HasMoveEffect(battlerAtk, EFFECT_FLING))
                        score += 2;
                    break;
                case HOLD_EFFECT_LAGGING_TAIL:
                case HOLD_EFFECT_STICKY_BARB:
                    break;
                default:
                    score++;    //other hold effects generally universally good
                    break;
                }
            }
        }
        break;
    case EFFECT_ROLE_PLAY:
        if (!IsRolePlayBannedAbilityAtk(AI_DATA->atkAbility)
          && !IsRolePlayBannedAbility(AI_DATA->defAbility)
          && !IsAbilityOfRating(AI_DATA->atkAbility, 5)
          && IsAbilityOfRating(AI_DATA->defAbility, 5))
            score += 2;
        break;
    case EFFECT_INGRAIN:
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_BIG_ROOT)
            score += 3;
        else
            score++;
        break;
    case EFFECT_SUPERPOWER:
    case EFFECT_OVERHEAT:
        if (AI_DATA->atkAbility == ABILITY_CONTRARY)
            score += 10;
        break;
    case EFFECT_MAGIC_COAT:
        if (IS_MOVE_STATUS(predictedMove) && gBattleMoves[predictedMove].target & (MOVE_TARGET_SELECTED | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_BOTH))
            score += 3;
        break;
    case EFFECT_RECYCLE:
        if (gBattleStruct->usedHeldItems[battlerAtk] != ITEM_NONE)
            score++;
        if (IsRecycleEncouragedItem(gBattleStruct->usedHeldItems[battlerAtk]))
            score++;
        break;
    case EFFECT_BRICK_BREAK:
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_REFLECT)
            score++;
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_LIGHTSCREEN)
            score++;
        if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_AURORA_VEIL)
            score++;
        break;
    case EFFECT_KNOCK_OFF:
        if (CanKnockOffItem(battlerDef, AI_DATA->defItem))
        {
            switch (AI_DATA->defHoldEffect)
            {
            case HOLD_EFFECT_IRON_BALL:
                if (HasMoveEffect(battlerDef, EFFECT_FLING))
                    score += 4;
                break;
            case HOLD_EFFECT_LAGGING_TAIL:
            case HOLD_EFFECT_STICKY_BARB:
                break;
            default:
                score += 3;
                break;
            }
        }
        break;
    case EFFECT_SKILL_SWAP:
        if (GetAbilityRating(AI_DATA->defAbility) > GetAbilityRating(AI_DATA->atkAbility))
            score++;
        break;
    case EFFECT_WORRY_SEED:
    case EFFECT_GASTRO_ACID:
    case EFFECT_SIMPLE_BEAM:
        if (IsAbilityOfRating(AI_DATA->defAbility, 5))
            score += 2;
        break;
    case EFFECT_ENTRAINMENT:
        if (IsAbilityOfRating(AI_DATA->defAbility, 5) || GetAbilityRating(AI_DATA->atkAbility) <= 0)
        {
            if (AI_DATA->defAbility != AI_DATA->atkAbility && !(gStatuses3[battlerDef] & STATUS3_GASTRO_ACID))
                score += 2;
        }                        
        break;
    case EFFECT_IMPRISON:
        if (predictedMove != MOVE_NONE && HasMove(battlerAtk, predictedMove))
            score += 3;
        else if (gDisableStructs[battlerAtk].isFirstTurn == 0)
            score++;
        break;
    case EFFECT_REFRESH:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY)
            score += 2;
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
        break;
    case EFFECT_GRUDGE:
        break;
    case EFFECT_SNATCH:
        if (predictedMove != MOVE_NONE && TestMoveFlags(predictedMove, FLAG_SNATCH_AFFECTED))
            score += 3; // Steal move
        break;
    case EFFECT_MUD_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_ELECTRIC) && HasMoveWithType(battlerDef, TYPE_ELECTRIC))
            score++;
        break;
    case EFFECT_WATER_SPORT:
        if (!HasMoveWithType(battlerAtk, TYPE_FIRE) && (HasMoveWithType(battlerDef, TYPE_FIRE)))
            score++;
        break;
    case EFFECT_TICKLE:
        if (gBattleMons[battlerDef].statStages[STAT_DEF] > 4 && HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL)
          && AI_DATA->defAbility != ABILITY_CONTRARY && ShouldLowerDefense(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
        {
            score += 2;
        }
        else if (ShouldLowerAttack(battlerAtk, battlerDef, AI_DATA->defAbility, AI_THINKING_STRUCT->movesetIndex))
        {
            score += 2;
        }
        break;
    case EFFECT_COSMIC_POWER:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_DEF, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_BULK_UP:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_DEF, &score);
        break;
    case EFFECT_CALM_MIND:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_GEOMANCY:
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_POWER_HERB)
            score += 3;
        //fallthrough
    case EFFECT_QUIVER_DANCE:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPDEF, &score);
        break;
    case EFFECT_SHELL_SMASH:
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_POWER_HERB)
            score += 3;
        
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPATK, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        break;
    case EFFECT_DRAGON_DANCE:
    case EFFECT_SHIFT_GEAR:
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_ATK, &score);
        break;
    case EFFECT_GUARD_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_DEF] > gBattleMons[battlerAtk].statStages[STAT_DEF]
          && gBattleMons[battlerDef].statStages[STAT_SPDEF] >= gBattleMons[battlerAtk].statStages[STAT_SPDEF])
            score++;
        else if (gBattleMons[battlerDef].statStages[STAT_SPDEF] > gBattleMons[battlerAtk].statStages[STAT_SPDEF]
          && gBattleMons[battlerDef].statStages[STAT_DEF] >= gBattleMons[battlerAtk].statStages[STAT_DEF])
            score++;
        break;
    case EFFECT_POWER_SWAP:
        if (gBattleMons[battlerDef].statStages[STAT_ATK] > gBattleMons[battlerAtk].statStages[STAT_ATK]
          && gBattleMons[battlerDef].statStages[STAT_SPATK] >= gBattleMons[battlerAtk].statStages[STAT_SPATK])
            score++;
        else if (gBattleMons[battlerDef].statStages[STAT_SPATK] > gBattleMons[battlerAtk].statStages[STAT_SPATK]
          && gBattleMons[battlerDef].statStages[STAT_ATK] >= gBattleMons[battlerAtk].statStages[STAT_ATK])
            score++;
        break;
    case EFFECT_POWER_TRICK:
        if (!(gStatuses3[battlerAtk] & STATUS3_POWER_TRICK))
        {
            if (gBattleMons[battlerAtk].defense > gBattleMons[battlerAtk].attack && HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL))
                score += 2;
            break;
        }
        break;
    case EFFECT_HEART_SWAP:
        {
            bool32 hasHigherStat = FALSE;
            //Only use if all target stats are >= attacker stats to prevent infinite loop
            for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
            {
                if (gBattleMons[battlerDef].statStages[i] < gBattleMons[battlerAtk].statStages[i])
                    break;
                if (gBattleMons[battlerDef].statStages[i] > gBattleMons[battlerAtk].statStages[i])
                    hasHigherStat = TRUE;
            }
            if (hasHigherStat && i == NUM_BATTLE_STATS)
                score++;
        }
        break;
    case EFFECT_SPEED_SWAP:
        // TODO this is cheating a bit...
        if (gBattleMons[battlerDef].speed > gBattleMons[battlerAtk].speed)
            score += 3;
        break;
    case EFFECT_GUARD_SPLIT:
        {
            // TODO also kind of cheating...
            u16 newDefense = (gBattleMons[battlerAtk].defense + gBattleMons[battlerDef].defense) / 2;
            u16 newSpDef = (gBattleMons[battlerAtk].spDefense + gBattleMons[battlerDef].spDefense) / 2;

            if ((newDefense > gBattleMons[battlerAtk].defense && newSpDef >= gBattleMons[battlerAtk].spDefense)
              || (newSpDef > gBattleMons[battlerAtk].spDefense && newDefense >= gBattleMons[battlerAtk].defense))
                score++;
        }
        break;
    case EFFECT_POWER_SPLIT:
        {
            u16 newAttack = (gBattleMons[battlerAtk].attack + gBattleMons[battlerDef].attack) / 2;
            u16 newSpAtk = (gBattleMons[battlerAtk].spAttack + gBattleMons[battlerDef].spAttack) / 2;

            if ((newAttack > gBattleMons[battlerAtk].attack && newSpAtk >= gBattleMons[battlerAtk].spAttack)
              || (newSpAtk > gBattleMons[battlerAtk].spAttack && newAttack >= gBattleMons[battlerAtk].attack))
                score++;
        }
        break;
    case EFFECT_BUG_BITE:   // And pluck
        if (gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE || AI_DATA->defAbility == ABILITY_STICKY_HOLD)
            break;
        else if (ItemId_GetPocket(AI_DATA->defItem) == POCKET_BERRIES)
            score += 3;
        break;
    case EFFECT_INCINERATE:
        if (gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE || AI_DATA->defAbility == ABILITY_STICKY_HOLD)
            break;
        else if (ItemId_GetPocket(AI_DATA->defItem) == POCKET_BERRIES || AI_DATA->defHoldEffect == HOLD_EFFECT_GEMS)
            score += 3;
        break;
    case EFFECT_SMACK_DOWN:
        if (!IsBattlerGrounded(battlerDef))
            score += 3;
        break;
    case EFFECT_SLEEP_HIT:  // Relic Song
        #if (defined SPECIES_MELOETTA && defined SPECIES_MELOETTA_PIROUETTE)
        if (AI_DATA->atkSpecies == SPECIES_MELOETTA && gBattleMons[battlerDef].defense < gBattleMons[battlerDef].spDefense)
            score += 3; // Change to pirouette if can do more damage
        else if (AI_DATA->atkSpecies == SPECIES_MELOETTA_PIROUETTE && gBattleMons[battlerDef].spDefense < gBattleMons[battlerDef].defense)
            score += 3; // Change to Aria if can do more damage
        #endif
        break;
    case EFFECT_ELECTRIC_TERRAIN:
    case EFFECT_MISTY_TERRAIN:
        if (gStatuses3[battlerAtk] & STATUS3_YAWN && IsBattlerGrounded(battlerAtk))
            score += 10;
        //fallthrough
    case EFFECT_GRASSY_TERRAIN:    
    case EFFECT_PSYCHIC_TERRAIN:
        score += 2;
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_TERRAIN_EXTENDER)
            score += 2;
        break;
    case EFFECT_PLEDGE:
        if (isDoubleBattle)
        {
            if (HasMoveEffect(AI_DATA->battlerAtkPartner, EFFECT_PLEDGE))
                score += 3; // Partner might use pledge move
        }
        break;
    case EFFECT_TRICK_ROOM:
        if (!(gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
            score += 3;
        else if ((gFieldStatuses & STATUS_FIELD_TRICK_ROOM) && GetBattlerSideSpeedAverage(battlerAtk) >= GetBattlerSideSpeedAverage(battlerDef))
            score += 3;
        break;
    case EFFECT_MAGIC_ROOM:
        score++;
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_NONE && AI_DATA->defHoldEffect != HOLD_EFFECT_NONE)
            score++;
        if (isDoubleBattle && AI_DATA->atkPartnerHoldEffect == HOLD_EFFECT_NONE && AI_DATA->defPartnerHoldEffect != HOLD_EFFECT_NONE)
            score++;
        break;
    case EFFECT_WONDER_ROOM:
        if ((HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL) && gBattleMons[battlerAtk].defense < gBattleMons[battlerAtk].spDefense)
          || (HasMoveWithSplit(battlerDef, SPLIT_SPECIAL) && gBattleMons[battlerAtk].spDefense < gBattleMons[battlerAtk].defense))
            score += 2;
        break;
    case EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        {
            if (HasSleepMoveWithLowAccuracy(battlerAtk, battlerDef)) // Has Gravity for a move like Hypnosis
                IncreaseSleepScore(battlerAtk, battlerDef, move, &score);
            else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect))
                score += 2;
            else
                score++;
        }
        break;
    case EFFECT_ION_DELUGE:
        if ((AI_DATA->atkAbility == ABILITY_VOLT_ABSORB
          || AI_DATA->atkAbility == ABILITY_MOTOR_DRIVE
          || AI_DATA->atkAbility == ABILITY_LIGHTNING_ROD)
          && gBattleMoves[predictedMove].type == TYPE_NORMAL)
            score += 2;
        break;
    case EFFECT_FLING:
        /* TODO
        switch (gFlingTable[AI_DATA->atkItem].effect)
        {
        case MOVE_EFFECT_BURN:
            IncreaseBurnScore(battlerAtk, battlerDef, move, &score);
            break;
        case MOVE_EFFECT_FLINCH:
            score += ShouldTryToFlinch(battlerAtk, battlerDef, AI_DATA->atkAbility, AI_DATA->defAbility, move);
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
                score += 3;
            break;
        }*/
        break;
    case EFFECT_FEINT:
        if (gBattleMoves[predictedMove].effect == EFFECT_PROTECT)
            score += 3;
        break;
    case EFFECT_EMBARGO:
        if (AI_DATA->defHoldEffect != HOLD_EFFECT_NONE)
            score++;
        break;
    case EFFECT_POWDER:
        if (predictedMove != MOVE_NONE && !IS_MOVE_STATUS(predictedMove) && gBattleMoves[predictedMove].type == TYPE_FIRE)
            score += 3;
        break;
    case EFFECT_TELEKINESIS:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, FALSE, AI_DATA->atkAbility, AI_DATA->defAbility, AI_DATA->atkHoldEffect, AI_DATA->defHoldEffect)
          || !IsBattlerGrounded(battlerDef))
            score++;
        break;
    case EFFECT_THROAT_CHOP:
        if (predictedMove != MOVE_NONE && TestMoveFlags(predictedMove, FLAG_SOUND) && GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)
            score += 3; // Ai goes first and predicts the target will use a sound move
        else if (TestMoveFlagsInMoveset(battlerDef, FLAG_SOUND))
            score += 3;
        break;
    case EFFECT_HEAL_BLOCK:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0 && predictedMove != MOVE_NONE && IsHealingMoveEffect(gBattleMoves[predictedMove].effect))
            score += 3; // Try to cancel healing move
        else if (HasHealingEffect(battlerDef) || AI_DATA->defHoldEffect == HOLD_EFFECT_LEFTOVERS
          || (AI_DATA->defHoldEffect == HOLD_EFFECT_BLACK_SLUDGE && IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON)))
            score += 2;
        break;
    case EFFECT_SOAK:
        if (HasMoveWithType(battlerAtk, TYPE_ELECTRIC) || HasMoveWithType(battlerAtk, TYPE_GRASS) || HasMoveEffect(battlerAtk, EFFECT_FREEZE_DRY))
            score += 2; // Get some super effective moves
        break;
    case EFFECT_THIRD_TYPE:
        if (AI_DATA->defAbility == ABILITY_WONDER_GUARD)
            score += 2; // Give target more weaknesses
        break;
    case EFFECT_ELECTRIFY:
        if (predictedMove != MOVE_NONE && gBattleMoves[predictedMove].type == TYPE_NORMAL
         && (AI_DATA->atkAbility == ABILITY_VOLT_ABSORB
          || AI_DATA->atkAbility == ABILITY_MOTOR_DRIVE
          || AI_DATA->atkAbility == ABILITY_LIGHTNING_ROD))
        {
            score += 3;
        }
        break;
    case EFFECT_TOPSY_TURVY:
        if (CountPositiveStatStages(battlerDef) > CountNegativeStatStages(battlerDef))
            score++;
        break;
    case EFFECT_FAIRY_LOCK:
        if (!IsBattlerTrapped(battlerDef, TRUE))
        {
            if (ShouldTrap(battlerAtk, battlerDef, move))
                score += 8;
        }
        break;
    case EFFECT_QUASH:
        if (isDoubleBattle
          && GetWhoStrikesFirst(AI_DATA->battlerAtkPartner, battlerDef, TRUE) == 1) // Attacker partner wouldn't go before target
            score++;
        break;
    case EFFECT_TAILWIND:
        if (GetBattlerSideSpeedAverage(battlerAtk) < GetBattlerSideSpeedAverage(battlerDef))
            score += 2;
        break;
    case EFFECT_LUCKY_CHANT:
        if (!isDoubleBattle)
        {
            score++;
        }
        else
        {
            if (CountUsablePartyMons(battlerDef) > 0)
                score += 8;
        }
        break;
    case EFFECT_MAGNET_RISE:
        if (IsBattlerGrounded(battlerAtk) && HasDamagingMoveOfType(battlerDef, TYPE_ELECTRIC)
          && !(AI_GetTypeEffectiveness(MOVE_EARTHQUAKE, battlerDef, battlerAtk) == AI_EFFECTIVENESS_x0)) // Doesn't resist ground move
        {
            if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0) // Attacker goes first
            {
                if (gBattleMoves[predictedMove].type == TYPE_GROUND)
                    score += 3; // Cause the enemy's move to fail
                break;
            }
            else // Opponent Goes First
            {
                if (HasDamagingMoveOfType(battlerDef, TYPE_GROUND))
                    score += 2;
                break;
            }
        }
        break;
    case EFFECT_CAMOUFLAGE:
        if (predictedMove != MOVE_NONE && GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0 // Attacker goes first
          && !IS_MOVE_STATUS(move) && AI_GetTypeEffectiveness(predictedMove, battlerDef, battlerAtk) != AI_EFFECTIVENESS_x0)
            score++;
        break;
    case EFFECT_FLAME_BURST:
        if (isDoubleBattle)
        {
            if (IsBattlerAlive(AI_DATA->battlerDefPartner)
              && GetHealthPercentage(AI_DATA->battlerDefPartner) < 12
              && AI_DATA->defPartnerAbility != ABILITY_MAGIC_GUARD
              && !IS_BATTLER_OF_TYPE(AI_DATA->battlerDefPartner, TYPE_FIRE))
                score++;
        }
        break;
    case EFFECT_TOXIC_THREAD:
        IncreasePoisonScore(battlerAtk, battlerDef, move, &score);
        IncreaseStatUpScore(battlerAtk, battlerDef, STAT_SPEED, &score);
        break;
    case EFFECT_TWO_TURNS_ATTACK:
    case EFFECT_SKULL_BASH:
    case EFFECT_SOLARBEAM:
        if (AI_DATA->atkHoldEffect == HOLD_EFFECT_POWER_HERB)
            score += 2;
        break;
    case EFFECT_COUNTER:
        if (!IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility) && predictedMove != MOVE_NONE)
        {
            if (gDisableStructs[battlerDef].tauntTimer != 0)
                score++;    // target must use damaging move
            if (GetMoveDamageResult(predictedMove) >= MOVE_POWER_GOOD && GetBattleMoveSplit(predictedMove) == SPLIT_PHYSICAL)
                score += 3;
        }
        break;
    case EFFECT_MIRROR_COAT:
        if (!IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility) && predictedMove != MOVE_NONE)
        {
            if (gDisableStructs[battlerDef].tauntTimer != 0)
                score++;    // target must use damaging move
            if (GetMoveDamageResult(predictedMove) >= MOVE_POWER_GOOD && GetBattleMoveSplit(predictedMove) == SPLIT_SPECIAL)
                score += 3;
        }
        break;
    case EFFECT_FLAIL:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 0)  // Ai goes first
        {
            if (GetHealthPercentage(battlerAtk) < 20)
                score++;
            else if (GetHealthPercentage(battlerAtk) < 8)
                score += 2;
        }
        break;
    case EFFECT_SHORE_UP:
        if (AI_WeatherHasEffect() && (gBattleWeather & WEATHER_SANDSTORM_ANY)
          && ShouldRecover(battlerAtk, battlerDef, move, 67))
            score += 3;
        else if (ShouldRecover(battlerAtk, battlerDef, move, 50))
            score += 2;
        break;
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON))
            score++;
        break;
    case EFFECT_FOCUS_PUNCH:
        if (!isDoubleBattle && effectiveness > AI_EFFECTIVENESS_x0_5)
        {
            if (IsBattlerIncapacitated(battlerDef, AI_DATA->defAbility))
                score += 2;
            else if (gBattleMons[battlerDef].status2 & (STATUS2_INFATUATION | STATUS2_CONFUSION))
                score++;
        }
        break;
    case EFFECT_SMELLINGSALT:
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS)
            score += 2;
        break;
    case EFFECT_WAKE_UP_SLAP:
        if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP)
            score += 2;
        break;
    case EFFECT_REVENGE:
        if (!(gBattleMons[battlerDef].status1 & STATUS1_SLEEP)
          &&  !(gBattleMons[battlerDef].status2 & (STATUS2_INFATUATION | STATUS2_CONFUSION)))
            score += 2;
        break;
    case EFFECT_ENDEAVOR:
        if (GetWhoStrikesFirst(battlerAtk, battlerDef, TRUE) == 1)  // Opponent faster
        {
            if (GetHealthPercentage(battlerAtk) < 40)
                score++;
        }
        else if (GetHealthPercentage(battlerAtk) < 50)
        {
            score++;
        }
        break;
    //case EFFECT_EXTREME_EVOBOOST: // TODO
        //break;
    //case EFFECT_CLANGOROUS_SOUL:  // TODO
        //break;
    //case EFFECT_NO_RETREAT:       // TODO
        //break;
    //case EFFECT_SKY_DROP
        //break;
    } // move effect checks
    
    return score;
}

static s16 AI_SetupFirstTurn(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static s16 AI_Risky(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static s16 AI_PreferStrongestMove(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static s16 AI_PreferBatonPass(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static s16 AI_DoubleBattle(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static s16 AI_HPAware(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
}

static void AI_Flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void AI_Watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

static s16 AI_Roaming(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    if (IsBattlerTrapped(battlerAtk, FALSE))
        return score;
    
    AI_Flee();
    return score;
}

static s16 AI_Safari(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    u8 safariFleeRate = gBattleStruct->safariEscapeFactor * 5; // Safari flee rate, from 0-20.

    if ((Random() % 100) < safariFleeRate)
        AI_Flee();
    else
        AI_Watch();

    return score;
}

static s16 AI_FirstBattle(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    if (GetHealthPercentage(battlerDef) <= 20)
        AI_Flee();

    return score;
}










