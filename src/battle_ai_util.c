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

// Const Data
static const u16 sDiscouragedPowerfulMoveEffects[] =
{
    EFFECT_EXPLOSION,
    EFFECT_DREAM_EATER,
    EFFECT_RECHARGE,
    EFFECT_SKULL_BASH,
    EFFECT_SOLARBEAM,
    EFFECT_SPIT_UP,
    EFFECT_FOCUS_PUNCH,
    EFFECT_SUPERPOWER,
    EFFECT_ERUPTION,
    EFFECT_OVERHEAT,
    EFFECT_MIND_BLOWN,
    0xFFFF
};

static const u16 sIgnoreMoldBreakerMoves[] = 
{
    MOVE_MOONGEIST_BEAM,
    MOVE_SUNSTEEL_STRIKE,
    MOVE_PHOTON_GEYSER,
    #ifdef MOVE_LIGHT_THAT_BURNS_THE_SKY
    MOVE_LIGHT_THAT_BURNS_THE_SKY,
    #endif
    #ifdef MOVE_MENACING_MOONRAZE_MAELSTROM
    MOVE_MENACING_MOONRAZE_MAELSTROM,
    #endif
    #ifdef MOVE_SEARING_SUNRAZE_SMASH
    MOVE_SEARING_SUNRAZE_SMASH,
    #endif
};

static const u16 sInstructBannedMoves[] = 
{
    MOVE_INSTRUCT,
    MOVE_BIDE,
    MOVE_FOCUS_PUNCH,
    MOVE_BEAK_BLAST,
    MOVE_SHELL_TRAP,
    MOVE_SKETCH,
    MOVE_TRANSFORM,
    MOVE_MIMIC,
    MOVE_KINGS_SHIELD,
    MOVE_STRUGGLE,
    MOVE_BOUNCE,
    MOVE_DIG,
    MOVE_DIVE,
    MOVE_FLY,
    MOVE_FREEZE_SHOCK,
    MOVE_GEOMANCY,
    MOVE_ICE_BURN,
    MOVE_PHANTOM_FORCE,
    MOVE_RAZOR_WIND,
    MOVE_SHADOW_FORCE,
    MOVE_SKULL_BASH,
    MOVE_SKY_ATTACK,
    MOVE_SKY_DROP,
    MOVE_SOLAR_BEAM,
    MOVE_SOLAR_BLADE,
};

static const u16 sRechargeMoves[] = 
{
    MOVE_HYPER_BEAM,
    MOVE_BLAST_BURN,
    MOVE_HYDRO_CANNON,
    MOVE_FRENZY_PLANT,
    MOVE_GIGA_IMPACT,
    MOVE_ROCK_WRECKER,
    MOVE_ROAR_OF_TIME,
    MOVE_PRISMATIC_LASER,
    MOVE_METEOR_ASSAULT,
    MOVE_ETERNABEAM,
};

static const u16 sOtherMoveCallingMoves[] = 
{
    MOVE_ASSIST,
    MOVE_COPYCAT,
    MOVE_ME_FIRST,
    MOVE_METRONOME,
    MOVE_MIRROR_MOVE,
    MOVE_NATURE_POWER,
    MOVE_SLEEP_TALK,
};

// Functions
void RecordLastUsedMoveByTarget(void)
{
    RecordKnownMove(gBattlerTarget, gLastMoves[gBattlerTarget]);
}

bool32 IsBattlerAIControlled(u32 battlerId)
{
    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_PLAYER_LEFT:
    default:
        return FALSE;
    case B_POSITION_OPPONENT_LEFT:
        return TRUE;
    case B_POSITION_PLAYER_RIGHT:
        return ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) != 0);
    case B_POSITION_OPPONENT_RIGHT:
        return TRUE;
    }
}

void ClearBattlerMoveHistory(u8 battlerId)
{
    memset(BATTLE_HISTORY->usedMoves[battlerId], 0, sizeof(BATTLE_HISTORY->usedMoves[battlerId]));
    memset(BATTLE_HISTORY->moveHistory[battlerId], 0, sizeof(BATTLE_HISTORY->moveHistory[battlerId]));
    BATTLE_HISTORY->moveHistoryIndex[battlerId] = 0;
}

void RecordLastUsedMoveBy(u32 battlerId, u32 move)
{
    u8 *index = &BATTLE_HISTORY->moveHistoryIndex[battlerId];

    if (++(*index) >= AI_MOVE_HISTORY_COUNT)
        *index = 0;
    BATTLE_HISTORY->moveHistory[battlerId][*index] = move;
}

void RecordKnownMove(u8 battlerId, u32 move)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (BATTLE_HISTORY->usedMoves[battlerId][i] == move)
            break;
        if (BATTLE_HISTORY->usedMoves[battlerId][i] == MOVE_NONE)
        {
            BATTLE_HISTORY->usedMoves[battlerId][i] = move;
            break;
        }
    }
}

void RecordAbilityBattle(u8 battlerId, u16 abilityId)
{
    BATTLE_HISTORY->abilities[battlerId] = abilityId;
}

void ClearBattlerAbilityHistory(u8 battlerId)
{
    BATTLE_HISTORY->abilities[battlerId] = ABILITY_NONE;
}

void RecordItemEffectBattle(u8 battlerId, u8 itemEffect)
{
    BATTLE_HISTORY->itemEffects[battlerId] = itemEffect;
}

void ClearBattlerItemEffectHistory(u8 battlerId)
{
    BATTLE_HISTORY->itemEffects[battlerId] = 0;
}

void SaveBattlerData(u8 battlerId)
{
    if (!IsBattlerAIControlled(battlerId))
    {
        u32 i;

        AI_THINKING_STRUCT->saved[battlerId].ability = gBattleMons[battlerId].ability;
        AI_THINKING_STRUCT->saved[battlerId].heldItem = gBattleMons[battlerId].item;
        AI_THINKING_STRUCT->saved[battlerId].species = gBattleMons[battlerId].species;
        for (i = 0; i < 4; i++)
            AI_THINKING_STRUCT->saved[battlerId].moves[i] = gBattleMons[battlerId].moves[i];
    }
}

void SetBattlerData(u8 battlerId)
{
    if (!IsBattlerAIControlled(battlerId))
    {
        struct Pokemon *illusionMon;
        u32 i;

        // Use the known battler's ability.
        if (BATTLE_HISTORY->abilities[battlerId] != ABILITY_NONE)
            gBattleMons[battlerId].ability = BATTLE_HISTORY->abilities[battlerId];
        // Check if mon can only have one ability.
        else if (gBaseStats[gBattleMons[battlerId].species].abilities[1] == ABILITY_NONE
                 || gBaseStats[gBattleMons[battlerId].species].abilities[1] == gBaseStats[gBattleMons[battlerId].species].abilities[0])
            gBattleMons[battlerId].ability = gBaseStats[gBattleMons[battlerId].species].abilities[0];
        // The ability is unknown.
        else
            gBattleMons[battlerId].ability = ABILITY_NONE;

        if (BATTLE_HISTORY->itemEffects[battlerId] == 0)
            gBattleMons[battlerId].item = 0;

        for (i = 0; i < 4; i++)
        {
            if (BATTLE_HISTORY->usedMoves[battlerId][i] == 0)
                gBattleMons[battlerId].moves[i] = 0;
        }

        // Simulate Illusion
        if ((illusionMon = GetIllusionMonPtr(battlerId)) != NULL)
            gBattleMons[battlerId].species = GetMonData(illusionMon, MON_DATA_SPECIES2);
    }
}

void RestoreBattlerData(u8 battlerId)
{
    if (!IsBattlerAIControlled(battlerId))
    {
        u32 i;

        gBattleMons[battlerId].ability = AI_THINKING_STRUCT->saved[battlerId].ability;
        gBattleMons[battlerId].item = AI_THINKING_STRUCT->saved[battlerId].heldItem;
        gBattleMons[battlerId].species = AI_THINKING_STRUCT->saved[battlerId].species;
        for (i = 0; i < 4; i++)
            gBattleMons[battlerId].moves[i] = AI_THINKING_STRUCT->saved[battlerId].moves[i];
    }
}

u32 GetHealthPercentage(u8 battlerId)
{
    return (u32)((100 * gBattleMons[battlerId].hp) / gBattleMons[battlerId].maxHP);
}    

bool32 IsBattlerTrapped(u8 battler, bool8 checkSwitch)
{
    u8 holdEffect = AI_GetHoldEffect(battler);
    if (IS_BATTLER_OF_TYPE(battler, TYPE_GHOST)
      || (checkSwitch && holdEffect == HOLD_EFFECT_SHED_SHELL)
      || (!checkSwitch && GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
      || (!checkSwitch && holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN))
    {
        return FALSE;
    }
    else
    {
        if (gBattleMons[battler].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED)
          || IsAbilityPreventingEscape(battler)
          || gStatuses3[battler] & (STATUS3_ROOTED)    // TODO: sky drop target in air
          || (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK))
            return TRUE;
    }

    return FALSE;
}

// Checks if one of the moves has side effects or perks
static u32 WhichMoveBetter(u32 move1, u32 move2)
{
    s32 defAbility = AI_GetAbility(gBattlerTarget);

    // Check if physical moves hurt.
    if (AI_GetHoldEffect(sBattler_AI) != HOLD_EFFECT_PROTECTIVE_PADS
        && (BATTLE_HISTORY->itemEffects[gBattlerTarget] == HOLD_EFFECT_ROCKY_HELMET
        || defAbility == ABILITY_IRON_BARBS || defAbility == ABILITY_ROUGH_SKIN))
    {
        if (IS_MOVE_PHYSICAL(move1) && !IS_MOVE_PHYSICAL(move2))
            return 1;
        if (IS_MOVE_PHYSICAL(move2) && !IS_MOVE_PHYSICAL(move1))
            return 0;
    }
    // Check recoil
    if (GetBattlerAbility(sBattler_AI) != ABILITY_ROCK_HEAD)
    {
        if (((gBattleMoves[move1].effect == EFFECT_RECOIL_25
                || gBattleMoves[move1].effect == EFFECT_RECOIL_IF_MISS
                || gBattleMoves[move1].effect == EFFECT_RECOIL_50
                || gBattleMoves[move1].effect == EFFECT_RECOIL_33
                || gBattleMoves[move1].effect == EFFECT_RECOIL_33_STATUS)
            && (gBattleMoves[move2].effect != EFFECT_RECOIL_25
                 && gBattleMoves[move2].effect != EFFECT_RECOIL_IF_MISS
                 && gBattleMoves[move2].effect != EFFECT_RECOIL_50
                 && gBattleMoves[move2].effect != EFFECT_RECOIL_33
                 && gBattleMoves[move2].effect != EFFECT_RECOIL_33_STATUS
                 && gBattleMoves[move2].effect != EFFECT_RECHARGE)))
            return 1;

        if (((gBattleMoves[move2].effect == EFFECT_RECOIL_25
                || gBattleMoves[move2].effect == EFFECT_RECOIL_IF_MISS
                || gBattleMoves[move2].effect == EFFECT_RECOIL_50
                || gBattleMoves[move2].effect == EFFECT_RECOIL_33
                || gBattleMoves[move2].effect == EFFECT_RECOIL_33_STATUS)
            && (gBattleMoves[move1].effect != EFFECT_RECOIL_25
                 && gBattleMoves[move1].effect != EFFECT_RECOIL_IF_MISS
                 && gBattleMoves[move1].effect != EFFECT_RECOIL_50
                 && gBattleMoves[move1].effect != EFFECT_RECOIL_33
                 && gBattleMoves[move1].effect != EFFECT_RECOIL_33_STATUS
                 && gBattleMoves[move1].effect != EFFECT_RECHARGE)))
            return 0;
    }
    // Check recharge
    if (gBattleMoves[move1].effect == EFFECT_RECHARGE && gBattleMoves[move2].effect != EFFECT_RECHARGE)
        return 1;
    if (gBattleMoves[move2].effect == EFFECT_RECHARGE && gBattleMoves[move1].effect != EFFECT_RECHARGE)
        return 0;
    // Check additional effect.
    if (gBattleMoves[move1].effect == 0 && gBattleMoves[move2].effect != 0)
        return 1;
    if (gBattleMoves[move2].effect == 0 && gBattleMoves[move1].effect != 0)
        return 0;

    return 2;
}

u8 GetMovePowerResult(u16 move)
{
    s32 i, checkedMove, bestId, currId, hp;
    s32 moveDmgs[MAX_MON_MOVES];
    u8 result;

    for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
    {
        if (gBattleMoves[move].effect == sDiscouragedPowerfulMoveEffects[i])
            break;
    }

    if (gBattleMoves[move].power != 0 && sDiscouragedPowerfulMoveEffects[i] == 0xFFFF)
    {
        for (checkedMove = 0; checkedMove < MAX_MON_MOVES; checkedMove++)
        {
            for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
            {
                if (gBattleMoves[gBattleMons[sBattler_AI].moves[checkedMove]].effect == sDiscouragedPowerfulMoveEffects[i])
                    break;
            }

            if (gBattleMons[sBattler_AI].moves[checkedMove] != MOVE_NONE
                && sDiscouragedPowerfulMoveEffects[i] == 0xFFFF
                && gBattleMoves[gBattleMons[sBattler_AI].moves[checkedMove]].power != 0)
            {
                moveDmgs[checkedMove] = AI_THINKING_STRUCT->simulatedDmg[sBattler_AI][gBattlerTarget][checkedMove];
            }
            else
            {
                moveDmgs[checkedMove] = 0;
            }
        }

        hp = gBattleMons[gBattlerTarget].hp + (20 * gBattleMons[gBattlerTarget].hp / 100); // 20 % add to make sure the battler is always fainted
        // If a move can faint battler, it doesn't matter how much damage it does
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moveDmgs[i] > hp)
                moveDmgs[i] = hp;
        }

        for (bestId = 0, i = 1; i < MAX_MON_MOVES; i++)
        {
            if (moveDmgs[i] > moveDmgs[bestId])
                bestId = i;
            if (moveDmgs[i] == moveDmgs[bestId])
            {
                switch (WhichMoveBetter(gBattleMons[sBattler_AI].moves[bestId], gBattleMons[sBattler_AI].moves[i]))
                {
                case 2:
                    if (Random() & 1)
                        break;
                case 1:
                    bestId = i;
                    break;
                }
            }
        }

        currId = AI_THINKING_STRUCT->movesetIndex;
        if (currId == bestId)
            AI_THINKING_STRUCT->funcResult = MOVE_POWER_BEST;
        // Compare percentage difference.
        else if ((moveDmgs[currId] >= hp || moveDmgs[bestId] < hp) // If current move can faint as well, or if neither can
                 && (moveDmgs[bestId] * 100 / hp) - (moveDmgs[currId] * 100 / hp) <= 30
                 && WhichMoveBetter(gBattleMons[sBattler_AI].moves[bestId], gBattleMons[sBattler_AI].moves[currId]) != 0)
            AI_THINKING_STRUCT->funcResult = MOVE_POWER_GOOD;
        else
            AI_THINKING_STRUCT->funcResult = MOVE_POWER_WEAK;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = MOVE_POWER_DISCOURAGED; // Highly discouraged in terms of power.
    }

    return AI_THINKING_STRUCT->funcResult;
}

u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef)
{
    u16 typeEffectiveness, moveType;

    SaveBattlerData(battlerAtk);
    SaveBattlerData(battlerDef);

    SetBattlerData(battlerAtk);
    SetBattlerData(battlerDef);

    gBattleStruct->dynamicMoveType = 0;
    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);
    typeEffectiveness = CalcTypeEffectivenessMultiplier(move, moveType, battlerAtk, battlerDef, FALSE);

    RestoreBattlerData(battlerAtk);
    RestoreBattlerData(battlerDef);

    return typeEffectiveness;
}

u8 AI_GetMoveEffectiveness(u16 move)
{
    u8 damageVar;
    u32 effectivenessMultiplier;

    gMoveResultFlags = 0;
    gCurrentMove = move;
    effectivenessMultiplier = AI_GetTypeEffectiveness(gCurrentMove, sBattler_AI, gBattlerTarget);
    switch (effectivenessMultiplier)
    {
    case UQ_4_12(0.0):
    default:
        damageVar = AI_EFFECTIVENESS_x0;
        break;
    case UQ_4_12(0.25):
        damageVar = AI_EFFECTIVENESS_x0_25;
        break;
    case UQ_4_12(0.5):
        damageVar = AI_EFFECTIVENESS_x0_5;
        break;
    case UQ_4_12(1.0):
        damageVar = AI_EFFECTIVENESS_x1;
        break;
    case UQ_4_12(2.0):
        damageVar = AI_EFFECTIVENESS_x2;
        break;
    case UQ_4_12(4.0):
        damageVar = AI_EFFECTIVENESS_x4;
        break;
    }

    return damageVar;
}

// 0: is user(ai) faster
// 1: is target faster
bool32 IsBattlerFaster(u8 battler)
{
    u32 fasterAI = 0, fasterPlayer = 0, i;
    s8 prioAI, prioPlayer;

    // Check move priorities first.
    prioAI = GetMovePriority(sBattler_AI, AI_THINKING_STRUCT->moveConsidered);
    SaveBattlerData(gBattlerTarget);
    SetBattlerData(gBattlerTarget);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == 0 || gBattleMons[gBattlerTarget].moves[i] == 0xFFFF)
            continue;

        prioPlayer = GetMovePriority(gBattlerTarget, gBattleMons[gBattlerTarget].moves[i]);
        if (prioAI > prioPlayer)
            fasterAI++;
        else if (prioPlayer > prioAI)
            fasterPlayer++;
    }
    RestoreBattlerData(gBattlerTarget);

    if (fasterAI > fasterPlayer)
    {
        if (battler == 0)   // is user (ai) faster
            return TRUE;
        else
            return FALSE;
    }
    else if (fasterAI < fasterPlayer)
    {
        if (battler == 1)   // is target (player) faster
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        // Priorities are the same(at least comparing to moves the AI is aware of), decide by speed.
        if (GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) == battler)
            return TRUE;
        else
            return FALSE;
    }
}

// Check if target has means to faint ai mon.
bool32 CanTargetFaintAi(u8 battlerDef, u8 battlerAtk)
{
    s32 i, dmg;
    u32 unusable = CheckMoveLimitations(battlerDef, 0, 0xFF & ~MOVE_LIMITATION_PP);
    u16 *moves = gBattleResources->battleHistory->usedMoves[battlerDef];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != 0xFFFF && !(unusable & gBitTable[i])
            && AI_CalcDamage(moves[i], battlerDef, battlerAtk) >= gBattleMons[battlerAtk].hp)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// does NOT include ability suppression checks
s32 AI_GetAbility(u32 battlerId)
{
    // The AI knows its own ability.
    if (IsBattlerAIControlled(battlerId))
        return gBattleMons[battlerId].ability;

    if (BATTLE_HISTORY->abilities[battlerId] != ABILITY_NONE)
        return BATTLE_HISTORY->abilities[battlerId];

    // Abilities that prevent fleeing.
    if (gBattleMons[battlerId].ability == ABILITY_SHADOW_TAG
    || gBattleMons[battlerId].ability == ABILITY_MAGNET_PULL
    || gBattleMons[battlerId].ability == ABILITY_ARENA_TRAP)
        return gBattleMons[battlerId].ability;

    if (gBaseStats[gBattleMons[battlerId].species].abilities[0] != ABILITY_NONE)
    {
        if (gBaseStats[gBattleMons[battlerId].species].abilities[1] != ABILITY_NONE)
        {
            // AI has no knowledge of opponent, so it guesses which ability.
            return gBaseStats[gBattleMons[battlerId].species].abilities[Random() & 1];
        }
        else
        {
            return gBaseStats[gBattleMons[battlerId].species].abilities[0]; // It's definitely ability 1.
        }
    }
    return ABILITY_NONE; // Unknown.
}

u16 AI_GetHoldEffect(u32 battlerId)
{
    u32 holdEffect;
    
    if (!IsBattlerAIControlled(battlerId))
        holdEffect = BATTLE_HISTORY->itemEffects[battlerId];
    else
        holdEffect = GetBattlerHoldEffect(battlerId, FALSE);
    
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_AWARE)
    {
        if (gStatuses3[battlerId] & STATUS3_EMBARGO)
            return HOLD_EFFECT_NONE;
        if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
            return HOLD_EFFECT_NONE;
        if (AI_GetAbility(battlerId) == ABILITY_KLUTZ && !(gStatuses3[battlerId] & STATUS3_GASTRO_ACID))
            return HOLD_EFFECT_NONE;
    }
}

// different from IsBattlerGrounded in that we don't always know battler's hold effect or ability
bool32 AI_IsBattlerGrounded(u8 battlerId)
{
    u32 holdEffect = AI_GetHoldEffect(battlerId);
    
    if (holdEffect == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    else if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_SMACKED_DOWN)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_TELEKINESIS)
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_MAGNET_RISE)
        return FALSE;
    else if (holdEffect == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    else if (AI_GetAbility(battlerId) == ABILITY_LEVITATE)
        return FALSE;
    else if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FLYING))
        return FALSE;
    else
        return TRUE;
}

bool32 DoesBattlerIgnoreAbilityChecks(u16 atkAbility, u16 move)
{
    u32 i;
    
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_AWARE))
        return FALSE;   // AI doesn't understand ability suppression concept
    
    for (i = 0; i < ARRAY_COUNT(sIgnoreMoldBreakerMoves); i++)
    {
        if (move == sIgnoreMoldBreakerMoves[i])
            return TRUE;
    }

    if (atkAbility == ABILITY_MOLD_BREAKER
      || atkAbility == ABILITY_TERAVOLT
      || atkAbility == ABILITY_TURBOBLAZE)
        return TRUE;

    return FALSE;
}

bool32 AI_WeatherHasEffect(void)
{
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_AWARE))
        return FALSE;   // AI doesn't understand ability suppression concept
    
    return WEATHER_HAS_EFFECT;
}

bool32 IsAromaVeilProtectedMove(u16 move)
{
    u32 i;
    
    switch (move)
    {
    case MOVE_DISABLE:
    case MOVE_ATTRACT:
    case MOVE_ENCORE:
    case MOVE_TORMENT:
    case MOVE_TAUNT:
    case MOVE_HEAL_BLOCK:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsNonVolatileStatusMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_SLEEP:
    case EFFECT_TOXIC:
    case EFFECT_POISON:
    case EFFECT_PARALYZE:
    case EFFECT_WILL_O_WISP:
    case EFFECT_YAWN:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsConfusionMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_CONFUSE_HIT:
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
    case EFFECT_TEETER_DANCE:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsStatLoweringMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_ATTACK_DOWN:
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_EVASION_DOWN:
    case EFFECT_ATTACK_DOWN_2:
    case EFFECT_DEFENSE_DOWN_2:
    case EFFECT_SPEED_DOWN_2:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
    case EFFECT_ACCURACY_DOWN_2:
    case EFFECT_EVASION_DOWN_2:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsHazardMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_SPIKES:
    case EFFECT_TOXIC_SPIKES:
    case EFFECT_STICKY_WEB:
    case EFFECT_STEALTH_ROCK:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsMoveRedirectionPrevented(u16 move, u16 atkAbility)
{
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_AWARE))
        return FALSE;
    
    if (move == MOVE_SKY_DROP
      || move == MOVE_SNIPE_SHOT
      || atkAbility == ABILITY_PROPELLER_TAIL
      || atkAbility == ABILITY_STALWART)
        return TRUE;
    return FALSE;
}

// differs from GetTotalAccuracy in that we need to check AI history for item, ability, etc
u32 AI_GetMoveAccuracy(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u8 atkHoldEffect, u8 defHoldEffect, u16 move)
{
    u32 calc, moveAcc, atkParam, defParam;
    s8 buff, accStage, evasionStage;
    
    gPotentialItemEffectBattler = battlerDef;
    accStage = gBattleMons[battlerAtk].statStages[STAT_ACC];
    evasionStage = gBattleMons[battlerDef].statStages[STAT_EVASION];
    if (atkAbility == ABILITY_UNAWARE)
        evasionStage = DEFAULT_STAT_STAGE;
    if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
        evasionStage = DEFAULT_STAT_STAGE;
    if (defAbility == ABILITY_UNAWARE)
        accStage = DEFAULT_STAT_STAGE;

    if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT || gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED)
        buff = accStage;
    else
        buff = accStage + DEFAULT_STAT_STAGE - evasionStage;

    if (buff < MIN_STAT_STAGE)
        buff = MIN_STAT_STAGE;
    if (buff > MAX_STAT_STAGE)
        buff = MAX_STAT_STAGE;

    moveAcc = gBattleMoves[move].accuracy;
    // Check Thunder and Hurricane on sunny weather.
    if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY
        && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
        moveAcc = 50;
    // Check Wonder Skin.
    if (defAbility == ABILITY_WONDER_SKIN && gBattleMoves[move].power == 0)
        moveAcc = 50;

    calc = gAccuracyStageRatios[buff].dividend * moveAcc;
    calc /= gAccuracyStageRatios[buff].divisor;

    if (atkAbility == ABILITY_COMPOUND_EYES)
        calc = (calc * 130) / 100; // 1.3 compound eyes boost
    else if (atkAbility == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 victory star boost
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)) && GetBattlerAbility(BATTLE_PARTNER(battlerAtk)) == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 ally's victory star boost

    if (defAbility == ABILITY_SAND_VEIL && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY)
        calc = (calc * 80) / 100; // 1.2 sand veil loss
    else if (defAbility == ABILITY_SNOW_CLOAK && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
        calc = (calc * 80) / 100; // 1.2 snow cloak loss
    else if (defAbility == ABILITY_TANGLED_FEET && gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
        calc = (calc * 50) / 100; // 1.5 tangled feet loss

    if (atkAbility == ABILITY_HUSTLE && IS_MOVE_PHYSICAL(move))
        calc = (calc * 80) / 100; // 1.2 hustle loss

    if (defHoldEffect == HOLD_EFFECT_EVASION_UP)
        calc = (calc * (100 - defParam)) / 100;

    if (atkHoldEffect == HOLD_EFFECT_WIDE_LENS)
        calc = (calc * (100 + atkParam)) / 100;
    else if (atkHoldEffect == HOLD_EFFECT_ZOOM_LENS && GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef));
        calc = (calc * (100 + atkParam)) / 100;

    return calc;
}

bool32 IsMoveEncouragedToHit(u8 battlerAtk, u8 battlerDef, u16 move)
{
    // never hits
    if (gStatuses3[battlerDef] & (STATUS3_SEMI_INVULNERABLE))
        return FALSE;
    
    if ((gStatuses3[battlerDef] & STATUS3_PHANTOM_FORCE)
      || (!TestMoveFlags(move, FLAG_HIT_IN_AIR) && gStatuses3[battlerDef] & STATUS3_ON_AIR)
      || (!TestMoveFlags(move, FLAG_DMG_UNDERGROUND) && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
      || (!TestMoveFlags(move, FLAG_DMG_UNDERWATER) && gStatuses3[battlerDef] & STATUS3_UNDERWATER))
        return FALSE;
    
    //TODO - anticipate protect move?
        
    // always hits
    if (gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS || gDisableStructs[battlerDef].battlerWithSureHit == battlerAtk)
        return TRUE;
    
    if (AI_GetAbility(battlerDef) == ABILITY_NO_GUARD || AI_GetAbility(battlerAtk) == ABILITY_NO_GUARD)
        return TRUE;
    
    if (B_TOXIC_NEVER_MISS >= GEN_6 && gBattleMoves[move].effect == EFFECT_TOXIC && IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON))
        return TRUE;
        
    // discouraged from hitting
    if (AI_WeatherHasEffect() && (gBattleWeather & WEATHER_SUN_ANY)
      && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
        return FALSE;
        
    // increased accuracy but don't always hit    
    if ((AI_WeatherHasEffect() &&
            (((gBattleWeather & WEATHER_RAIN_ANY) && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
         || (((gBattleWeather & WEATHER_HAIL_ANY) && move == MOVE_BLIZZARD))))
     || (gBattleMoves[move].effect == EFFECT_VITAL_THROW)
     || (gBattleMoves[move].accuracy == 0)
     || ((B_MINIMIZE_DMG_ACC >= GEN_6) && (gStatuses3[battlerDef] & STATUS3_MINIMIZED) && (gBattleMoves[move].flags & FLAG_DMG_MINIMIZE)))
    {
        return TRUE;
    }
    
    return FALSE;
}

bool32 ShouldTryOHKO(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u32 accuracy, u16 move)
{
    u32 holdEffect = AI_GetHoldEffect(battlerDef);
    
    gPotentialItemEffectBattler = battlerDef;
    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < GetBattlerHoldEffectParam(battlerDef))
        return FALSE;   //probabilistically speaking, focus band should activate so dont OHKO
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && GetHealthPercentage(battlerDef) == 100)
        return FALSE;
    
    if (!DoesBattlerIgnoreAbilityChecks(atkAbility, move) && defAbility == ABILITY_STURDY)
        return FALSE;
    
    if ((((gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS)
        && gDisableStructs[battlerDef].battlerWithSureHit == battlerAtk)
        || atkAbility == ABILITY_NO_GUARD || defAbility == ABILITY_NO_GUARD)
        && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
    {
        return TRUE;
    }
    else    // test the odds
    {
        u16 odds = accuracy + (gBattleMons[battlerAtk].level - gBattleMons[battlerDef].level);
        if (Random() % 100 + 1 < odds && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
            return TRUE;
    }
    return FALSE;
}

// stat stages
bool32 BattlerStatCanFall(u8 battler, u16 battlerAbility, u8 stat)
{
    if ((gBattleMons[battler].statStages[stat] > MIN_STAT_STAGE && battlerAbility != ABILITY_CONTRARY)
      || (battlerAbility == ABILITY_CONTRARY && gBattleMons[battler].statStages[stat] < MAX_STAT_STAGE))
        return TRUE;
    return FALSE;
}

bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat)
{
    if ((gBattleMons[battler].statStages[stat] < MAX_STAT_STAGE && battlerAbility != ABILITY_CONTRARY)
      || (battlerAbility == ABILITY_CONTRARY && gBattleMons[battler].statStages[stat] > MIN_STAT_STAGE))
        return TRUE;
    return FALSE;
}

bool32 AreBattlersStatsMaxed(u8 battlerId)
{
    u32 i;    
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] < MAX_STAT_STAGE)
            return FALSE;
    }
    return TRUE;
}

bool32 AnyStatIsRaised(u8 battlerId)
{
    u32 i;
    
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE)
            return TRUE;
    }
    return FALSE;
}

u32 CountPositiveStatStages(u8 battlerId)
{
    u32 count = 0;
    u32 i;
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

u32 CountNegativeStatStages(u8 battlerId)
{
    u32 count = 0;
    u32 i;
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

// checks for growth, gear up, work up
bool32 BattlerShouldRaiseAttacks(u8 battlerId, u16 ability)
{
    if (((!BattlerStatCanRise(battlerId, ability, STAT_ATK)|| !HasMoveWithSplit(battlerId, SPLIT_PHYSICAL))
      && (!BattlerStatCanRise(battlerId, ability, STAT_SPATK) || !HasMoveWithSplit(battlerId, SPLIT_SPECIAL)))
      || ability == ABILITY_CONTRARY)
    {
        return FALSE;
    }
    return TRUE;
}

bool32 CanAttackerFaintTarget(u8 battlerAtk, u8 battlerDef, u8 index)
{
    s32 dmg = AI_THINKING_STRUCT->simulatedDmg[battlerAtk][battlerDef][index];
    
    if (gBattleMons[battlerDef].hp <= dmg)
        return TRUE;
    return FALSE;
}

s32 CountUsablePartyMons(u8 battlerId)
{
    s32 battlerOnField1, battlerOnField2, i, ret;
    struct Pokemon *party;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[GetBattlerAtPosition(GetBattlerPosition(battlerId) ^ BIT_FLANK)];
    }
    else // In singles there's only one battlerId by side.
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[battlerId];
    }

    ret = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != battlerOnField1 && i != battlerOnField2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            ret++;
        }
    }

    return ret;
}

u16 *GetMovesArray(u32 battler)
{
    if (IsBattlerAIControlled(battler) || IsBattlerAIControlled(BATTLE_PARTNER(battler)))
        return gBattleMons[battler].moves;
    else
        return gBattleResources->battleHistory->usedMoves[battler];
}

bool32 HasMoveWithSplit(u32 battler, u32 split)
{
    u32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != 0xFFFF && GetBattleMoveSplit(moves[i]) == split)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithType(u32 battler, u8 type)
{
    s32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != 0xFFFF && gBattleMoves[moves[i]].type == type)
            return TRUE;
    }

    return FALSE;
}

bool32 IsInstructBannedMove(u16 move)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sInstructBannedMoves); i++)
    {
        if (move == sInstructBannedMoves[i])
            return TRUE;
    }
    return FALSE;
}

bool32 MoveRequiresRecharging(u16 move)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRechargeMoves); i++)
    {
        if (move == sRechargeMoves[i])
            return TRUE;
    }
    return FALSE;
}

bool32 MoveCallsOtherMove(u16 move)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sOtherMoveCallingMoves); i++)
    {
        if (move == sOtherMoveCallingMoves[i])
            return TRUE;
    }
    return FALSE;
}

bool32 TestMoveFlagsInMoveset(u8 battler, u32 flags)
{
    s32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != 0xFFFF && TestMoveFlags(moves[i], flags))
            return TRUE;
    }
    return FALSE;
}

bool32 BattlerHasDamagingMove(u8 battlerId)
{
    u32 i;
    u16 *moves = GetMovesArray(battlerId);
    
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != 0xFFFF && gBattleMoves[moves[i]].power != 0)
            return TRUE;
    }

    return FALSE;
}

static u32 GetLeechSeedDamage(u8 battlerId)
{
    u32 damage = 0;
    if ((gStatuses3[battlerId] & STATUS3_LEECHSEED)
     && gBattleMons[gStatuses3[battlerId] & STATUS3_LEECHSEED_BATTLER].hp != 0)
     {
        damage = gBattleMons[battlerId].maxHP / 8;
        if (damage == 0)
            damage = 1;
     }
     return damage;
}

static u32 GetNightmareDamage(u8 battlerId)
{
    u32 damage = 0;
    if ((gBattleMons[battlerId].status2 & STATUS2_NIGHTMARE) && gBattleMons[battlerId].status1 & STATUS1_SLEEP)
    {
        damage = gBattleMons[battlerId].maxHP / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetCurseDamage(u8 battlerId)
{
    u32 damage = 0;
    if (gBattleMons[battlerId].status2 & STATUS2_CURSED)
    {
        damage = gBattleMons[battlerId].maxHP / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetTrapDamage(u8 battlerId)
{
    // ai has no knowledge about turns remaining
    u32 damage = 0;
    u32 holdEffect = AI_GetHoldEffect(gBattleStruct->wrappedBy[battlerId]);
    if (gBattleMons[battlerId].status2 & STATUS2_WRAPPED)
    {
        if (holdEffect == HOLD_EFFECT_BINDING_BAND)
            damage = gBattleMons[battlerId].maxHP / (B_BINDING_DAMAGE >= GEN_6) ? 6 : 8;
        else
            damage = gBattleMons[battlerId].maxHP / (B_BINDING_DAMAGE >= GEN_6) ? 8 : 16;

        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetPoisonDamage(u8 battlerId)
{
    u32 damage = 0;
    
    if (AI_GetAbility(battlerId) == ABILITY_POISON_HEAL)
        return damage;
    
    if (gBattleMons[battlerId].status1 & STATUS1_POISON)
    {
        damage = gBattleMons[battlerId].maxHP / 8;
        if (damage == 0)
            damage = 1;
    }
    else if (gBattleMons[battlerId].status1 & STATUS1_TOXIC_POISON)
    {
        damage = gBattleMons[battlerId].maxHP / 16;
        if (damage == 0)
            damage = 1;
        if ((gBattleMons[battlerId].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
            gBattleMons[battlerId].status1 += STATUS1_TOXIC_TURN(1);
        damage *= (gBattleMons[battlerId].status1 & STATUS1_TOXIC_COUNTER) >> 8;
    }
    return damage;
}

static bool32 BattlerAffectedBySandstorm(u8 battlerId, u16 ability)
{
    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_ROCK)
      && !IS_BATTLER_OF_TYPE(battlerId, TYPE_GROUND)
      && !IS_BATTLER_OF_TYPE(battlerId, TYPE_STEEL)
      && ability != ABILITY_SAND_VEIL
      && ability != ABILITY_SAND_FORCE
      && ability != ABILITY_SAND_RUSH
      && ability != ABILITY_OVERCOAT)
        return TRUE;
    return FALSE;
}

static bool32 BattlerAffectedByHail(u8 battlerId, u16 ability)
{
    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      && ability != ABILITY_SNOW_CLOAK
      && ability != ABILITY_OVERCOAT
      && ability != ABILITY_ICE_BODY)
        return TRUE;
    return FALSE;
}

static u32 GetWeatherDamage(u8 battlerId)
{
    u32 ability = AI_GetAbility(battlerId);
    u32 holdEffect = AI_GetHoldEffect(battlerId);
    u32 damage = 0;
    if (!AI_WeatherHasEffect())
        return 0;
    
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
    {
        if (BattlerAffectedBySandstorm(battlerId, ability)
          && !(gStatuses3[battlerId] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
          && holdEffect != HOLD_EFFECT_SAFETY_GOOGLES)
        {
            damage = gBattleMons[battlerId].maxHP / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    if ((gBattleWeather & WEATHER_HAIL_ANY) && ability != ABILITY_ICE_BODY)
    {
        if (BattlerAffectedByHail(battlerId, ability)
          && !(gStatuses3[battlerId] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
          && holdEffect != HOLD_EFFECT_SAFETY_GOOGLES)
        {
            damage = gBattleMons[battlerId].maxHP / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    return damage;
}

bool32 BattlerHasSecondaryDamage(u8 battlerId)
{
    u32 secondaryDamage;
    
    if (AI_GetAbility(battlerId) == ABILITY_MAGIC_GUARD)
        return FALSE;
    
    secondaryDamage = GetLeechSeedDamage(battlerId)
     + GetNightmareDamage(battlerId)
     + GetCurseDamage(battlerId)
     + GetTrapDamage(battlerId)
     + GetPoisonDamage(battlerId)
     + GetWeatherDamage(battlerId);
    
    if (secondaryDamage != 0)
        return TRUE;
    return FALSE;
}

bool32 BattlerWillFaintFromWeather(u8 battler, u16 ability)
{
    if ((BattlerAffectedBySandstorm(battler, ability) || BattlerAffectedByHail(battler, ability))
      && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 16)
        return TRUE;

    return FALSE;
}

// status checks
bool32 AI_ShouldPutToSleep(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove)
{
    if (defAbility == ABILITY_INSOMNIA
      || defAbility == ABILITY_VITAL_SPIRIT
      || gBattleMons[battlerDef].status1 & STATUS1_ANY
      || gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SAFEGUARD
      || IsAbilityStatusProtected(battlerDef)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))   // shouldn't try to sleep mon that partner is trying to make sleep
        return FALSE;
    return TRUE;
}

bool32 AI_ShouldPoison(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove)
{
    if (defAbility == ABILITY_IMMUNITY
      || defAbility == ABILITY_PASTEL_VEIL
      || gBattleMons[battlerDef].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerDef)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))
        return FALSE;
    else if (defAbility != ABILITY_CORROSION && (IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON) || IS_BATTLER_OF_TYPE(battlerDef, TYPE_STEEL)))
        return FALSE;
    else if (IsValidDoubleBattle(battlerAtk) && AI_GetAbility(BATTLE_PARTNER(battlerDef)) == ABILITY_PASTEL_VEIL)
        return FALSE;

    return TRUE;
}

bool32 AI_CanParalyze(u8 battlerAtk, u8 battlerDef, u16 defAbility, u16 move, u16 partnerMove)
{
    if (defAbility == ABILITY_LIMBER
      || IS_BATTLER_OF_TYPE(battlerDef, TYPE_ELECTRIC)
      || gBattleMons[battlerDef].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerDef)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))
        return FALSE;
    return TRUE;
}

bool32 AI_CanConfuse(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove)
{
    if ((gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
      || (!DoesBattlerIgnoreAbilityChecks(battlerAtk, move) && defAbility == ABILITY_OWN_TEMPO)
      || (IsBattlerGrounded(battlerDef) && (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || DoesPartnerHaveSameMoveEffect(battlerAtkPartner, battlerDef, move, partnerMove))
    {
        return FALSE;
    }
    
    return TRUE;
}

bool32 AI_CanBurn(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 battlerAtkPartner, u16 move, u16 partnerMove)
{
    if (defAbility == ABILITY_WATER_VEIL
      || defAbility == ABILITY_WATER_BUBBLE
      || IS_BATTLER_OF_TYPE(battlerDef, TYPE_FIRE)
      || gBattleMons[battlerDef].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battlerDef)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(battlerAtkPartner, battlerDef, partnerMove))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 AI_CanBeInfatuated(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 atkGender, u8 defGender)
{
    if (IsBattlerAlive(battlerDef)
      && !(gBattleMons[battlerDef].status2 & STATUS2_INFATUATION)
      && defAbility != ABILITY_OBLIVIOUS
      && atkGender != defGender
      && atkGender != MON_GENDERLESS
      && defGender != MON_GENDERLESS
      && !IsAbilityOnSide(battlerDef, ABILITY_AROMA_VEIL))
        return FALSE;
    return TRUE;
}


bool32 AnyPartyMemberStatused(u8 battlerId, bool32 checkSoundproof)
{
    struct Pokemon *party;
    u32 i;
    
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;
    
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (checkSoundproof && GetMonAbility(&party[i]) == ABILITY_SOUNDPROOF)
            continue;

        if (GetMonData(&party[i], MON_DATA_STATUS) != STATUS1_NONE)
            return TRUE;
    }

    return FALSE;
}

bool32 IsPartyFullyHealedExceptBattler(u8 battlerId)
{
    struct Pokemon *party;
    u32 i;
    
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;
    
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != gBattlerPartyIndexes[battlerId]
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
         && GetMonData(&party[i], MON_DATA_HP) < GetMonData(&party[i], MON_DATA_MAX_HP))
            return FALSE;
    }
    return TRUE;
}

u16 GetBattlerSideSpeedAverage(u8 battler)
{
    u16 speed1 = 0;
    u16 speed2 = 0;
    u8 numBattlersAlive = 0;

    if (IsBattlerAlive(battler))
    {
        speed1 = GetBattlerTotalSpeedStat(battler);
        numBattlersAlive++;
    }

    if (IsDoubleBattle() && IsBattlerAlive(BATTLE_PARTNER(battler)))
    {
        speed2 = GetBattlerTotalSpeedStat(BATTLE_PARTNER(battler));
        numBattlersAlive++;
    }

    return (speed1 + speed2) / numBattlersAlive;
}

bool32 ShouldUseRecoilMove(u8 battlerAtk, u8 battlerDef, u32 recoilDmg, u8 moveIndex)
{
    if (recoilDmg >= gBattleMons[battlerAtk].hp //Recoil kills attacker
      && CountUsablePartyMons(battlerDef) > 1) //Foe has more than 1 target left
    {
        if (recoilDmg >= gBattleMons[battlerDef].hp && !CanAttackerFaintTarget(battlerAtk, battlerDef, moveIndex))
            return TRUE; //If it's the only KO move then just use it
        else
            return FALSE; //Not as good to use move if you'll faint and not win
    }
    
    return TRUE;
}

// Partner Logic
bool32 IsValidDoubleBattle(u8 battlerAtk)
{
    if (IsDoubleBattle()
      && ((IsBattlerAlive(BATTLE_OPPOSITE(battlerAtk)) && IsBattlerAlive(BATTLE_PARTNER(BATTLE_OPPOSITE(battlerAtk)))) || IsBattlerAlive(BATTLE_PARTNER(battlerAtk))))
        return TRUE;
    return FALSE;
}

u16 GetAllyChosenMove(void)
{
    u8 partnerBattler = BATTLE_PARTNER(sBattler_AI);
    
    if (!IsBattlerAlive(partnerBattler) || !IsBattlerAIControlled(partnerBattler))
        return MOVE_NONE;   // TODO: prediction?
    else if (partnerBattler > sBattler_AI) // Battler with the lower id chooses the move first.
        return MOVE_NONE;
    else
        return gBattleMons[partnerBattler].moves[gBattleStruct->chosenMovePositions[partnerBattler]];
}

bool32 IsTargetingPartner(u8 battlerAtk, u8 battlerDef)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    if (battlerDef == BATTLE_PARTNER(battlerAtk))
        return TRUE;
    
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_SAME
bool32 DoesPartnerHaveSameMoveEffect(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gBattleMoves[move].effect == gBattleMoves[partnerMove].effect
      && gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE
      && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef)
    {
        return TRUE;
    }
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_SAME_NO_TARGET
bool32 PartnerHasSameMoveEffectWithoutTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gBattleMoves[move].effect == gBattleMoves[partnerMove].effect
      && gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_STATUS_SAME_TARGET
bool32 PartnerMoveEffectIsStatusSameTarget(u8 battlerAtkPartner, u8 battlerDef, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE
     && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef
     && (gBattleMoves[partnerMove].effect == EFFECT_SLEEP
       || gBattleMoves[partnerMove].effect == EFFECT_POISON
       || gBattleMoves[partnerMove].effect == EFFECT_TOXIC
       || gBattleMoves[partnerMove].effect == EFFECT_PARALYZE
       || gBattleMoves[partnerMove].effect == EFFECT_WILL_O_WISP
       || gBattleMoves[partnerMove].effect == EFFECT_YAWN))
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_WEATHER
bool32 PartnerMoveEffectIsWeather(u8 battlerAtkPartner, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE
     && (gBattleMoves[partnerMove].effect == EFFECT_SUNNY_DAY
      || gBattleMoves[partnerMove].effect == EFFECT_RAIN_DANCE
      || gBattleMoves[partnerMove].effect == EFFECT_SANDSTORM
      || gBattleMoves[partnerMove].effect == EFFECT_HAIL))
        return TRUE;
    
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_TERRAIN
bool32 PartnerMoveEffectIsTerrain(u8 battlerAtkPartner, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE
     && (gBattleMoves[partnerMove].effect == EFFECT_GRASSY_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_MISTY_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_ELECTRIC_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_PSYCHIC_TERRAIN))
        return TRUE;
    
    return FALSE;
}

//PARTNER_MOVE_IS_TAILWIND_TRICKROOM
bool32 PartnerMoveIs(u8 battlerAtkPartner, u16 partnerMove, u16 moveCheck)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE && partnerMove == moveCheck)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME
bool32 PartnerMoveIsSameAsAttacker(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE && move == partnerMove && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME_NO_TARGET
bool32 PartnerMoveIsSameNoTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    if (gChosenMoveByBattler[battlerAtkPartner] != MOVE_NONE && move == partnerMove)
        return TRUE;
    return FALSE;
}

