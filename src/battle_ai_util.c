#include "global.h"
#include "battle_z_move.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_field_statuses.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_stat_change.h"
#include "battle_controllers.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "event_data.h"
#include "data.h"
#include "item.h"
#include "move.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/moves.h"
#include "constants/items.h"

static u32 GetAIEffectGroup(enum BattleMoveEffects effect);
static u32 GetAIEffectGroupFromMove(enum BattlerId battler, enum Move move);

// Functions
enum Ability AI_GetMoldBreakerSanitizedAbility(enum BattlerId battlerAtk, enum Ability abilityAtk, enum Ability abilityDef, enum HoldEffect holdEffectDef, enum Move move)
{
    if (MoveIgnoresTargetAbility(move))
        return ABILITY_NONE;

    if (holdEffectDef != HOLD_EFFECT_ABILITY_SHIELD && IsMoldBreakerTypeAbility(battlerAtk, abilityAtk, move))
        return ABILITY_NONE;

    return abilityDef;
}

static bool32 AI_IsDoubleSpreadMove(enum BattlerId battlerAtk, enum Move move)
{
    u32 numOfTargets = 0;
    enum MoveTarget moveTargetType = AI_GetBattlerMoveTargetType(battlerAtk, move);

    if (!IsDoubleBattle() || !IsSpreadMove(moveTargetType))
        return FALSE;

    for (enum BattlerId battlerDef = 0; battlerDef < MAX_BATTLERS_COUNT; battlerDef++)
    {
        if (battlerAtk == battlerDef || !IsBattlerAlive(battlerDef))
            continue;

        if (moveTargetType == TARGET_BOTH && battlerAtk == GetPartnerBattler(battlerDef))
            continue;

        if (!IsSemiInvulnerable(battlerDef, CHECK_ALL)
         || CanBreakThroughSemiInvulnerablity(battlerAtk, battlerDef, gAiLogicData->abilities[battlerAtk], gAiLogicData->abilities[battlerDef], move))
            numOfTargets++;
    }

    if (numOfTargets > 1)
        return TRUE;

    return FALSE;
}

bool32 AI_IsBattlerGrounded(enum BattlerId battler)
{
    return IsBattlerGrounded(battler, gAiLogicData->abilities[battler], gAiLogicData->holdEffects[battler]);
}

static bool32 AI_CanBattlerHitBothFoesInTerrain(enum BattlerId battler, enum Move move, enum BattleMoveEffects effect)
{
    return effect == EFFECT_TERRAIN_BOOST
        && GetMoveTerrainBoost_HitsBothFoes(move)
        && IsBattlerTerrainAffected(battler, gAiLogicData->abilities[battler], gAiLogicData->holdEffects[battler], GetMoveTerrainBoost_Terrain(move), gFieldTimers.terrain);
}

enum MoveTarget AI_GetBattlerMoveTargetType(enum BattlerId battler, enum Move move)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_CURSE && !IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return TARGET_USER;
    if (AI_CanBattlerHitBothFoesInTerrain(battler, move, effect))
        return TARGET_BOTH;
    if (effect == EFFECT_TERA_STARSTORM && gBattleMons[battler].species == SPECIES_TERAPAGOS_STELLAR)
        return TARGET_BOTH;

    return GetMoveTarget(move);
}

u32 AI_GetDefaultDamageRollForContext(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, struct AiLogicData *aiData, u32 aiRoll)
{
    switch (aiRoll)
    {
    case AI_ROLL_MIN:
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
    case AI_ROLL_MEDIAN:
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].median;
    case AI_ROLL_MAX:
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
    case AI_ROLL_RANDOM:
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].random;
    default:
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].median; // Default assumes it deals median damage
    }
}

u32 AI_GetDamage(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, struct AiLogicData *aiData)
{
    if (calcContext == AI_ATTACKING && BattlerHasAi(battlerAtk))
    {
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE)) // Risky assumes it deals max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY)) // Conservative assumes it deals min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, GetConfig(AI_ROLL_ATTACKING));
    }
    else if (calcContext == AI_DEFENDING && BattlerHasAi(battlerDef))
    {
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE)) // Risky assumes it takes min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY)) // Conservative assumes it takes max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, AI_ROLL_DEFENDING);
    }
    else if (calcContext == AI_SWITCHIN_ATTACKING && BattlerHasAi(battlerAtk))
    {
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE)) // Risky assumes it deals max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY)) // Conservative assumes it deals min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, AI_ROLL_SWITCHIN_ATTACKING);
    }
    else if (calcContext == AI_SWITCHIN_DEFENDING && BattlerHasAi(battlerDef))
    {
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE)) // Risky assumes it takes min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY)) // Conservative assumes it takes max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, AI_ROLL_SWITCHIN_DEFENDING);
    }
    else if (calcContext == AI_SHOULD_SETUP_DEFENDING && BattlerHasAi(battlerDef))
    {
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE)) // Risky assumes it takes min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        if ((gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_RISKY)) // Conservative assumes it takes max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, AI_ROLL_SHOULD_SETUP_DEFENDING);
    }
    else if (calcContext == AI_ATTACKING_PARTNER && BattlerHasAi(battlerAtk))
    {
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE)) // Risky assumes it deals max damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].maximum;
        if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE) && !(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY)) // Conservative assumes it deals min damage
            return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].minimum;
        return AI_GetDefaultDamageRollForContext(battlerAtk, battlerDef, moveIndex, aiData, AI_ROLL_ATTACKING_PARTNER);
    }
    else
    {
        return aiData->simulatedDmg[battlerAtk][battlerDef][moveIndex].median;
    }
}

bool32 AI_IsFaster(enum BattlerId battlerAi, enum BattlerId battlerDef, enum Move aiMove, enum Move playerMove, enum ConsiderPriority considerPriority)
{
    return (AI_WhoStrikesFirst(battlerAi, battlerDef, aiMove, playerMove, considerPriority) == AI_IS_FASTER);
}

bool32 AI_IsSlower(enum BattlerId battlerAi, enum BattlerId battlerDef, enum Move aiMove, enum Move playerMove, enum ConsiderPriority considerPriority)
{
    return (AI_WhoStrikesFirst(battlerAi, battlerDef, aiMove, playerMove, considerPriority) == AI_IS_SLOWER);
}

enum Move GetAIChosenMove(enum BattlerId battlerId)
{
    return (gBattleMons[battlerId].moves[gAiBattleData->chosenMoveIndex[battlerId]]);
}

bool32 AI_RandLessThan(u32 val)
{
    if ((Random() % 0xFF) < val)
        return TRUE;
    return FALSE;
}

bool32 IsAiFlagPresent(u64 flag)
{
    for (enum BattlerId battlerIndex = 0; battlerIndex < MAX_BATTLERS_COUNT; battlerIndex++)
    {
        if (gAiThinkingStruct->aiFlags[battlerIndex] & flag)
            return TRUE;
    }

    return FALSE;
}

bool32 IsAiBattlerAware(enum BattlerId battlerId)
{
    if (IsAiFlagPresent(AI_FLAG_OMNISCIENT))
        return TRUE;

    return BattlerHasAi(battlerId);
}

bool32 IsAiBattlerAssumingStab(enum BattlerId battlerId)
{
    if (IsAiFlagPresent(AI_FLAG_ASSUME_STAB))
        return TRUE;

    return FALSE;
}

bool32 IsAiBattlerAssumingStatusMoves(enum BattlerId battlerId)
{
    if (IsAiFlagPresent(AI_FLAG_ASSUME_STATUS_MOVES))
        return TRUE;

    return FALSE;
}

bool32 IsAiBattlerPredictingAbility(enum BattlerId battlerId)
{
    if (IsAiFlagPresent(AI_FLAG_WEIGH_ABILITY_PREDICTION))
        return TRUE;

    return FALSE;
}

bool32 IsBattlerPredictedToSwitch(enum BattlerId battler)
{
    if (gAiLogicData->predictingSwitch && gAiLogicData->shouldSwitch & (1u << battler))
        return TRUE;
    return FALSE;
}

// Either a predicted move or the last used move from an opposing battler
enum Move GetIncomingMove(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *aiData)
{
    if (aiData->predictingMove)
        return aiData->predictedMove[opposingBattler];
    return aiData->lastUsedMove[opposingBattler];
}

// When not predicting, don't want to reference player's previous move; leads to weird behaviour for cases like Fake Out or Protect, especially in doubles
enum Move GetPredictedMove(enum BattlerId battler, enum BattlerId opposingBattler, struct AiLogicData *aiData)
{
    if (aiData->predictingMove)
        return aiData->predictedMove[opposingBattler];
    return MOVE_NONE;
}

void SaveBattlerData(enum BattlerId battlerId)
{
    if (!BattlerHasAi(battlerId) && !gAiThinkingStruct->saved[battlerId].saved)
    {
        gAiThinkingStruct->saved[battlerId].saved = TRUE;
        gAiThinkingStruct->saved[battlerId].ability = gBattleMons[battlerId].ability;
        gAiThinkingStruct->saved[battlerId].heldItem = gBattleMons[battlerId].item;
        gAiThinkingStruct->saved[battlerId].species = gBattleMons[battlerId].species;
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            gAiThinkingStruct->saved[battlerId].moves[moveIndex] = gBattleMons[battlerId].moves[moveIndex];
    }
    // Save and restore types even for AI controlled battlers in case it gets changed during move evaluation process.
    gAiThinkingStruct->saved[battlerId].types[0] = gBattleMons[battlerId].types[0];
    gAiThinkingStruct->saved[battlerId].types[1] = gBattleMons[battlerId].types[1];
}

bool32 ShouldRecordStatusMove(enum Move move)
{
    if (ASSUME_STATUS_MOVES_HAS_TUNING)
    {
        switch (GetMoveEffect(move))
        {
        // variable odds by additional effect
        case EFFECT_NON_VOLATILE_STATUS:
            if (GetMoveNonVolatileStatus(move) == MOVE_EFFECT_SLEEP && RandomPercentage(RNG_AI_ASSUME_STATUS_SLEEP, ASSUME_STATUS_HIGH_ODDS))
                return TRUE;
            else if (RandomPercentage(RNG_AI_ASSUME_STATUS_NONVOLATILE, ASSUME_STATUS_MEDIUM_ODDS))
                return TRUE;
            break;
        // High odds
        case EFFECT_AURORA_VEIL:
        case EFFECT_WEATHER_AND_SWITCH:
        case EFFECT_FIRST_TURN_ONLY:
        case EFFECT_FOLLOW_ME:
        case EFFECT_INSTRUCT:
        case EFFECT_JUNGLE_HEALING:
        case EFFECT_SHED_TAIL:
            return RandomPercentage(RNG_AI_ASSUME_STATUS_HIGH_ODDS, ASSUME_STATUS_HIGH_ODDS);
        // Medium odds
        case EFFECT_AFTER_YOU:
        case EFFECT_DOODLE:
        case EFFECT_ENCORE:
        case EFFECT_HAZE:
        case EFFECT_PARTING_SHOT:
        case EFFECT_PROTECT:
        case EFFECT_REST:
        case EFFECT_ROAR:
        case EFFECT_ROOST:
        case EFFECT_SLEEP_TALK:
        case EFFECT_TAUNT:
        case EFFECT_TAILWIND:
        case EFFECT_TRICK:
        case EFFECT_TRICK_ROOM:
        // defoggables / screens and hazards
        case EFFECT_LIGHT_SCREEN:
        case EFFECT_REFLECT:
        case EFFECT_SPIKES:
        case EFFECT_STEALTH_ROCK:
        case EFFECT_STICKY_WEB:
        case EFFECT_TOXIC_SPIKES:
            return RandomPercentage(RNG_AI_ASSUME_STATUS_MEDIUM_ODDS, ASSUME_STATUS_MEDIUM_ODDS);
        // Low odds
        case EFFECT_ENTRAINMENT:
        case EFFECT_FIXED_PERCENT_DAMAGE:
        case EFFECT_GASTRO_ACID:
        case EFFECT_IMPRISON:
        case EFFECT_TELEPORT:
            return RandomPercentage(RNG_AI_ASSUME_STATUS_LOW_ODDS, ASSUME_STATUS_LOW_ODDS);
        default:
            break;
        }
    }

    return RandomPercentage(RNG_AI_ASSUME_ALL_STATUS, ASSUME_ALL_STATUS_ODDS) && IsBattleMoveStatus(move);
}

static bool32 ShouldFailForIllusion(enum Species illusionSpecies, enum BattlerId battlerId)
{
    u32 learnsetMoveIndex;
    const struct LevelUpMove *learnset;

    if (gBattleHistory->abilities[battlerId] == ABILITY_ILLUSION)
        return FALSE;

    // Don't fall for Illusion if the mon used a move it cannot know.
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move move = gBattleHistory->usedMoves[battlerId][moveIndex];
        if (move == MOVE_NONE)
            continue;

        learnset = GetSpeciesLevelUpLearnset(illusionSpecies);
        for (learnsetMoveIndex = 0; learnset[learnsetMoveIndex].move != MOVE_UNAVAILABLE; learnsetMoveIndex++)
        {
            if (learnset[learnsetMoveIndex].move == move)
                break;
        }
        // The used move is in the learnsets of the fake species.
        if (learnset[learnsetMoveIndex].move != MOVE_UNAVAILABLE)
            continue;

        // The used move can be learned from Tm/Hm or Move Tutors.
        if (CanLearnTeachableMove(illusionSpecies, move))
            continue;

        // 'Illegal move', AI won't fail for the illusion.
        return FALSE;
    }

    return TRUE;
}

void SetBattlerData(enum BattlerId battlerId)
{
    if (!BattlerHasAi(battlerId) && gAiThinkingStruct->saved[battlerId].saved)
    {
        enum Species species, illusionSpecies;
        enum BattleSide side = GetBattlerSide(battlerId);

        // Simulate Illusion
        species = gBattleMons[battlerId].species;
        illusionSpecies = GetIllusionMonSpecies(battlerId);
        if (illusionSpecies != SPECIES_NONE && ShouldFailForIllusion(illusionSpecies, battlerId))
        {
            // If the battler's type has not been changed, AI assumes the types of the illusion mon.
            if (gBattleMons[battlerId].types[0] == GetSpeciesType(species, 0)
                && gBattleMons[battlerId].types[1] == GetSpeciesType(species, 1))
            {
                gBattleMons[battlerId].types[0] = GetSpeciesType(illusionSpecies, 0);
                gBattleMons[battlerId].types[1] = GetSpeciesType(illusionSpecies, 1);
            }
            species = illusionSpecies;
        }

        // Use the known battler's ability.
        if (gAiPartyData->mons[side][gBattlerPartyIndexes[battlerId]].ability != ABILITY_NONE)
            gBattleMons[battlerId].ability = gAiPartyData->mons[side][gBattlerPartyIndexes[battlerId]].ability;
        // Check if mon can only have one ability.
        else if (GetSpeciesAbility(species, 1) == ABILITY_NONE
                || GetSpeciesAbility(species, 1) == GetSpeciesAbility(species, 0))
            gBattleMons[battlerId].ability = GetSpeciesAbility(species, 0);
        // The ability is unknown.
        else
            gBattleMons[battlerId].ability = ABILITY_NONE;

        if (gAiPartyData->mons[side][gBattlerPartyIndexes[battlerId]].heldEffect == 0)
            gBattleMons[battlerId].item = ITEM_NONE;

        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (gAiPartyData->mons[side][gBattlerPartyIndexes[battlerId]].moves[moveIndex] == 0)
                gBattleMons[battlerId].moves[moveIndex] = MOVE_NONE;
        }
    }
}

void RestoreBattlerData(enum BattlerId battlerId)
{
    if (!BattlerHasAi(battlerId) && gAiThinkingStruct->saved[battlerId].saved)
    {
        gAiThinkingStruct->saved[battlerId].saved = FALSE;
        gBattleMons[battlerId].ability = gAiThinkingStruct->saved[battlerId].ability;
        gBattleMons[battlerId].item = gAiThinkingStruct->saved[battlerId].heldItem;
        gBattleMons[battlerId].species = gAiThinkingStruct->saved[battlerId].species;
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            gBattleMons[battlerId].moves[moveIndex] = gAiThinkingStruct->saved[battlerId].moves[moveIndex];
    }
    gBattleMons[battlerId].types[0] = gAiThinkingStruct->saved[battlerId].types[0];
    gBattleMons[battlerId].types[1] = gAiThinkingStruct->saved[battlerId].types[1];
}

u32 GetHealthPercentage(enum BattlerId battlerId)
{
    return (u32)((100 * gBattleMons[battlerId].hp) / gBattleMons[battlerId].maxHP);
}

bool32 AI_BattlerAtMaxHp(enum BattlerId battlerId)
{
    if (gAiLogicData->hpPercents[battlerId] == 100)
        return TRUE;
    return FALSE;
}


bool32 AI_CanBattlerEscape(enum BattlerId battler)
{
    enum HoldEffect holdEffect = gAiLogicData->holdEffects[battler];

    if (GetConfig(B_GHOSTS_ESCAPE) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return TRUE;
    if (holdEffect == HOLD_EFFECT_SHED_SHELL)
        return TRUE;

    return FALSE;
}

bool32 IsBattlerTrapped(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (AI_CanBattlerEscape(battlerDef))
        return FALSE;

    if (gBattleMons[battlerDef].volatiles.wrapped)
        return TRUE;
    if (gBattleMons[battlerDef].volatiles.escapePrevention)
        return TRUE;
    if (gBattleMons[battlerDef].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
        return TRUE;
    if (gBattleMons[battlerDef].volatiles.root)
        return TRUE;
    if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        return TRUE;
    if (AI_IsAbilityOnSide(battlerAtk, ABILITY_SHADOW_TAG)
        && (B_SHADOW_TAG_ESCAPE >= GEN_4 && gAiLogicData->abilities[battlerDef] != ABILITY_SHADOW_TAG))
        return TRUE;
    if (AI_IsAbilityOnSide(battlerAtk, ABILITY_ARENA_TRAP)
        && AI_IsBattlerGrounded(battlerDef))
        return TRUE;
    if (AI_IsAbilityOnSide(battlerAtk, ABILITY_MAGNET_PULL)
        && IS_BATTLER_OF_TYPE(battlerDef, TYPE_STEEL))
        return TRUE;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && CountUsablePartyMons(battlerDef) == 0)
        return TRUE;

    return FALSE;
}

u32 GetTotalBaseStat(enum Species species)
{
    return GetSpeciesBaseHP(species)
         + GetSpeciesBaseAttack(species)
         + GetSpeciesBaseDefense(species)
         + GetSpeciesBaseSpeed(species)
         + GetSpeciesBaseSpAttack(species)
         + GetSpeciesBaseSpDefense(species);
}

bool32 IsTruantMonVulnerable(enum BattlerId battlerAI, enum BattlerId opposingBattler)
{
    enum Move predictedMove = GetPredictedMove(battlerAI, opposingBattler, gAiLogicData);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move move = gBattleHistory->usedMoves[opposingBattler][moveIndex];
        enum BattleMoveEffects effect = GetMoveEffect(move);
        if (effect == EFFECT_PROTECT && move != MOVE_ENDURE)
            return TRUE;
        if (effect == EFFECT_SEMI_INVULNERABLE && AI_IsSlower(battlerAI, opposingBattler, GetAIChosenMove(battlerAI), predictedMove, CONSIDER_PRIORITY))
            return TRUE;
    }
    return FALSE;
}

bool32 Ai_IsPriorityBlocked(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    s32 atkPriority = GetBattleMovePriority(battlerAtk, aiData->abilities[battlerAtk], move);

    if (atkPriority <= 0 || IsBattlerAlly(battlerAtk, battlerDef))
        return FALSE;

    if (IsMoldBreakerTypeAbility(battlerAtk, aiData->abilities[battlerAtk], move) || MoveIgnoresTargetAbility(move))
        return FALSE;

    if (IsDazzlingAbility(aiData->abilities[battlerDef]))
        return TRUE;

    if (IsDoubleBattle() && IsDazzlingAbility(aiData->abilities[GetPartnerBattler(battlerDef)]))
        return TRUE;

    return FALSE;
}

bool32 AI_CanMoveBeBlockedByTarget(struct DamageContext *ctx)
{
    return CanMoveBeBlockedByTarget(ctx, GetBattleMovePriority(ctx->battlerAtk, ctx->abilities[ctx->battlerAtk], ctx->move));
}

// To save computation time this function has 2 variants. One saves, sets and restores battlers, while the other doesn't.
struct SimulatedDamage AI_CalcDamageSaveBattlers(enum Move move, enum BattlerId battlerAtk, enum BattlerId battlerDef, uq4_12_t *typeEffectiveness, enum Gimmick gimmickAtk, enum Gimmick gimmickDef)
{
    struct SimulatedDamage dmg;
    struct AiCalcValues aiCalc = {
        .move = move,
        .gimmickAtk = gimmickAtk,
        .gimmickDef = gimmickDef,
        .weather = AI_GetWeather(),
        .terrain = gFieldTimers.terrain,
    };

    SaveBattlerData(battlerAtk);
    SaveBattlerData(battlerDef);
    SetBattlerData(battlerAtk);
    SetBattlerData(battlerDef);
    dmg = AI_CalcDamage(&aiCalc, battlerAtk, battlerDef);
    RestoreBattlerData(battlerAtk);
    RestoreBattlerData(battlerDef);
    *typeEffectiveness = aiCalc.typeEffectiveness;
    return dmg;
}

static __attribute__((noinline)) ARM_FUNC s32 LowestRollDmg(s32 dmg)
{
    dmg *= MIN_ROLL_PERCENTAGE;
    dmg /= 100;
    return dmg;
}

static inline s32 HighestRollDmg(s32 dmg)
{
    dmg *= MAX_ROLL_PERCENTAGE;
    dmg /= 100;
    return dmg;
}

static __attribute__((noinline)) ARM_FUNC s32 DmgRoll(s32 dmg)
{
    dmg *= DMG_ROLL_PERCENTAGE;
    dmg /= 100;
    return dmg;
}

static __attribute__((noinline)) ARM_FUNC s32 RandomRollDmg(s32 dmg)
{
    u32 randomRollPercentage = RandomUniform(RNG_AI_DMG_ROLL_RANDOM, MIN_ROLL_PERCENTAGE, MAX_ROLL_PERCENTAGE);
    dmg *= randomRollPercentage;
    dmg /= 100;
    return dmg;
}

bool32 IsDamageMoveUnusable(struct DamageContext *ctx)
{
    enum Ability battlerDefAbility = ctx->abilities[ctx->battlerDef];
    enum Ability partnerDefAbility = ctx->abilities[GetPartnerBattler(ctx->battlerDef)];
    struct AiLogicData *aiData = gAiLogicData;

    if (ctx->typeEffectivenessModifier == UQ_4_12(0.0))
        return TRUE;
    if (gBattleStruct->battlerState[ctx->battlerDef].commandingDondozo)
        return TRUE;

    if (Ai_IsPriorityBlocked(ctx->battlerAtk, ctx->battlerDef, ctx->move, aiData))
        return TRUE;

    if (AI_CanMoveBeBlockedByTarget(ctx))
        return TRUE;

    // Limited to Lighning Rod and Storm Drain because otherwise the AI would consider Water Absorb, etc...
    if (partnerDefAbility == ABILITY_LIGHTNING_ROD || partnerDefAbility == ABILITY_STORM_DRAIN)
    {
        u32 originalTarget = ctx->battlerDef; // Need to preserve origin target;
        ctx->battlerDef = GetPartnerBattler(ctx->battlerDef);
        bool32 canAbilityAbsorbMove = CanAbilityAbsorbMove(ctx);
        ctx->battlerDef = originalTarget;
        if (canAbilityAbsorbMove)
            return TRUE;
    }

    if (ctx->weather & B_WEATHER_SUN_PRIMAL && ctx->moveType == TYPE_WATER)
        return TRUE;
    if (ctx->weather & B_WEATHER_RAIN_PRIMAL && ctx->moveType == TYPE_FIRE)
        return TRUE;

    if (IsMoveDampBanned(ctx->move) && (battlerDefAbility == ABILITY_DAMP || partnerDefAbility == ABILITY_DAMP))
        return TRUE;

    switch (GetMoveEffect(ctx->move))
    {
    case EFFECT_DREAM_EATER:
        if (!IsAsleepOrComatose(ctx->battlerDef, battlerDefAbility))
            return TRUE;
        break;
    case EFFECT_BELCH:
        if (!GetBattlerPartyState(ctx->battlerAtk)->ateBerry)
            return TRUE;
        break;
    case EFFECT_LAST_RESORT:
        if (!CanUseLastResort(ctx->battlerAtk) && !IsConsideringZMove(ctx->battlerAtk, ctx->battlerDef, ctx->move))
            return TRUE;
        break;
    case EFFECT_LOW_KICK:
    case EFFECT_HEAT_CRASH:
        if (GetActiveGimmick(ctx->battlerDef) == GIMMICK_DYNAMAX)
            return TRUE;
        break;
    case EFFECT_FAIL_IF_NOT_ARG_TYPE:
        if (!IS_BATTLER_OF_TYPE(ctx->battlerAtk, GetMoveArgType(ctx->move)))
            return TRUE;
        break;
    case EFFECT_STEEL_ROLLER:
        if (gFieldTimers.terrain == B_TERRAIN_NONE)
            return TRUE;
        break;
    case EFFECT_POLTERGEIST:
        if (gAiLogicData->items[ctx->battlerDef] == ITEM_NONE || !IsBattlerItemEnabled(ctx->battlerDef))
            return TRUE;
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (!IsBattlersFirstTurn(ctx->battlerAtk))
            return TRUE;
        break;
    default:
        break;
    }

    return FALSE;
}

bool32 IsAdditionalEffectBlocked(enum BattlerId battlerAtk, enum Ability abilityAtk, enum BattlerId battlerDef, enum Ability abilityDef, enum Move move)
{
    if (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_COVERT_CLOAK)
        return TRUE;

    if (abilityDef == ABILITY_SHIELD_DUST && !IsMoldBreakerTypeAbility(battlerAtk, abilityAtk, move))
        return TRUE;

    return FALSE;
}

static inline s32 GetDamageByRollType(s32 dmg, enum DamageRollType rollType)
{
    if (rollType == DMG_ROLL_LOWEST)
        return LowestRollDmg(dmg);
    else if (rollType == DMG_ROLL_HIGHEST)
        return HighestRollDmg(dmg);
    else if (rollType == DMG_ROLL_RANDOM)
        return RandomRollDmg(dmg);
    else
        return DmgRoll(dmg);
}

static inline void AI_StoreBattlerTypes(enum BattlerId battlerAtk, enum Type *types)
{
    types[0] = gBattleMons[battlerAtk].types[0];
    types[1] = gBattleMons[battlerAtk].types[1];
    types[2] = gBattleMons[battlerAtk].types[2];
}

static inline void AI_RestoreBattlerTypes(enum BattlerId battlerAtk, enum Type *types)
{
    gBattleMons[battlerAtk].types[0] = types[0];
    gBattleMons[battlerAtk].types[1] = types[1];
    gBattleMons[battlerAtk].types[2] = types[2];
}

static inline void CalcDynamicMoveDamage(struct DamageContext *ctx, struct SimulatedDamage *simDamage)
{
    enum BattleMoveEffects effect = GetMoveEffect(ctx->move);

    u32 median = simDamage->median;
    u32 minimum = simDamage->minimum;
    u32 maximum = simDamage->maximum;
    u32 random = simDamage->random;

    u32 strikeCount = GetMoveStrikeCount(ctx->move);

    if (effect == EFFECT_BEAT_UP && GetConfig(B_BEAT_UP) >= GEN_5)
    {
        u32 partyCount = CalculatePartyCount(GetBattlerTrainer(ctx->battlerAtk));
        u32 i;
        gBattleStruct->beatUpSlot = 0;
        ctx->isCrit = FALSE;
        ctx->fixedBasePower = 0;
        median = 0;
        for (i = 0; i < partyCount; i++)
            median += CalculateMoveDamage(ctx);
        maximum = minimum = median = random;
        gBattleStruct->beatUpSlot = 0;
    }
    else if (strikeCount > 1)
    {
        bool32 multiplyDamage = FALSE;
        if (IsDoubleBattle() && AI_GetBattlerMoveTargetType(ctx->battlerAtk, ctx->move) == TARGET_SMART)
        {
            struct DamageContext partnerCtx = {0};
            partnerCtx = *ctx;
            partnerCtx.battlerDef = GetPartnerBattler(ctx->battlerDef);
            partnerCtx.typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(&partnerCtx);

            if (IsBattlerAlive(partnerCtx.battlerDef) && !IsDamageMoveUnusable(&partnerCtx) && CalculateMoveDamageVars(&partnerCtx) > 0) // Checks if any damage can be done
                gAiLogicData->dragonDartsHitsBothTarget |= 1u << ctx->battlerAtk;
            else
                multiplyDamage = TRUE;
        }
        else if (effect != EFFECT_TRIPLE_KICK)
        {
            multiplyDamage = TRUE;
        }

        if (multiplyDamage)
        {
            median *= strikeCount;
            minimum *= strikeCount;
            maximum *= strikeCount;
            random *= strikeCount;
        }
    }
    else if (IsMultiHitMove(ctx->move))
    {
        if (effect == EFFECT_SPECIES_POWER_OVERRIDE && gBattleMons[ctx->battlerAtk].species == GetMoveSpeciesPowerOverride_Species(ctx->move))
        {
            u32 basePowerOverride = GetMoveSpeciesPowerOverride_NumOfHits(ctx->move);
            median *= basePowerOverride;
            minimum *= basePowerOverride;
            maximum *= basePowerOverride;
            random *= basePowerOverride;
        }
        else if (ctx->abilities[ctx->battlerAtk] == ABILITY_SKILL_LINK)
        {
            median *= 5;
            minimum *= 5;
            maximum *= 5;
            random *= 5;
        }
        else if (ctx->holdEffects[ctx->battlerAtk] == HOLD_EFFECT_LOADED_DICE)
        {
            median *= 9;
            median /= 2;
            minimum *= 4;
            maximum *= 5;
            random *= RandomUniform(RNG_AI_DMG_ROLL_RANDOM, 4, 5);
        }
        else
        {
            median *= 3;
            minimum *= 2;
            maximum *= 5;
            random *= RandomUniform(RNG_AI_DMG_ROLL_RANDOM, 2, 5);
        }
    }
    else if (ctx->abilities[ctx->battlerAtk] == ABILITY_PARENTAL_BOND
          && strikeCount == 0
          && !AI_IsDoubleSpreadMove(ctx->battlerAtk, ctx->move))
    {
        median  += median  / (B_PARENTAL_BOND_DMG >= GEN_7 ? 4 : 2);
        minimum += minimum / (B_PARENTAL_BOND_DMG >= GEN_7 ? 4 : 2);
        maximum += maximum / (B_PARENTAL_BOND_DMG >= GEN_7 ? 4 : 2);
        random  += random  / (B_PARENTAL_BOND_DMG >= GEN_7 ? 4 : 2);
    }

    if (median == 0)
        median = 1;
    if (minimum == 0)
        minimum = 1;
    if (maximum == 0)
        maximum = 1;
    if (random == 0)
        random = 1;

    simDamage->median = median;
    simDamage->minimum = minimum;
    simDamage->maximum = maximum;
    simDamage->random = random;
}

static inline bool32 ShouldCalcCritDamage(struct DamageContext *ctx)
{
    s32 critChanceIndex = 0;

    // Get crit chance
    if (GetConfig(B_CRIT_CHANCE) == GEN_1)
        critChanceIndex = CalcCritChanceStageGen1(ctx);
    else
        critChanceIndex = CalcCritChanceStage(ctx);

    if (critChanceIndex == CRITICAL_HIT_ALWAYS)
        return TRUE;
    if (GetCriticalHitOdds(critChanceIndex) == 1)
        return TRUE;
    if (critChanceIndex >= RISKY_AI_CRIT_STAGE_THRESHOLD // Not guaranteed but above Risky threshold
        && (gAiThinkingStruct->aiFlags[ctx->battlerAtk] & AI_FLAG_RISKY)
        && GetConfig(B_CRIT_CHANCE) != GEN_1)
        return TRUE;
    if (critChanceIndex >= RISKY_AI_CRIT_THRESHOLD_GEN_1 // Not guaranteed but above Risky threshold
        && (gAiThinkingStruct->aiFlags[ctx->battlerAtk] & AI_FLAG_RISKY)
        && GetConfig(B_CRIT_CHANCE) == GEN_1)
        return TRUE;

    return FALSE;
}

static s32 HandleKOThroughBerryReduction(struct DamageContext *ctx, s32 dmg)
{
    if (ctx->aiCheckBerryModifier) // Only set if AI running calcs
    {
        // Only indicate move is ignoring berry resist if it doesn't already OHKO even if resisted
        if (dmg < gBattleMons[ctx->battlerDef].hp)
            gAiLogicData->resistBerryAffected[ctx->battlerAtk][ctx->battlerDef][GetMoveIndex(ctx->battlerAtk, ctx->move)] = TRUE;

        // Ignore resist berry if appropriate
        u32 berryModifier = gAiLogicData->abilities[ctx->battlerDef] == ABILITY_RIPEN ? 4 : 2;
        u32 unmitigatedDamage = dmg * berryModifier;
        u32 totalDamage = dmg;

        // Add unmitigated hits up to the set KO threshold, - 1 because the first hit is dmg
        for (u32 hitsToKO = 0; hitsToKO < AI_IGNORE_BERRY_KO_THRESHOLD - 1; hitsToKO++)
            totalDamage += unmitigatedDamage;

        // If the total damage from reduced hit and non-reduced hit(s) are a KO, we can see our target KO threshold through berry damage
        if (totalDamage >= gBattleMons[ctx->battlerDef].hp)
            return unmitigatedDamage; // Pretend the berry isn't there so the AI can see the KO threshold
        else
            return dmg;
    }
    return dmg;
}

static s32 AI_ApplyModifiersAfterDmgRoll(struct DamageContext *ctx, s32 dmg)
{
    dmg = ApplyModifiersAfterDmgRoll(ctx, dmg);
    dmg = HandleKOThroughBerryReduction(ctx, dmg);
    return dmg;
}

struct SimulatedDamage AI_CalcDamage(struct AiCalcValues *aiCalc, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    struct SimulatedDamage simDamage = {0};
    enum Move move = aiCalc->move;
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    bool32 toggledGimmickAtk = FALSE;
    bool32 toggledGimmickDef = FALSE;
    struct AiLogicData *aiData = gAiLogicData;
    gAiLogicData->aiCalcInProgress = TRUE;
    enum Move baseMove = move;

    if (moveEffect == EFFECT_HIT_ENEMY_HEAL_ALLY
     && battlerDef == GetPartnerBattler(battlerAtk))
    {
        gAiLogicData->aiCalcInProgress = FALSE;
        return simDamage;
    }

    if (moveEffect == EFFECT_NATURE_POWER)
    {
        move = baseMove = GetNaturePowerMove();
        moveEffect = GetMoveEffect(move);
    }

    // Temporarily enable gimmicks for damage calcs if planned
    if (aiCalc->gimmickAtk != GIMMICK_NONE && GetActiveGimmick(battlerAtk) == GIMMICK_NONE)
    {
        toggledGimmickAtk = TRUE;
        SetActiveGimmick(battlerAtk, aiCalc->gimmickAtk);
    }

    if (aiCalc->gimmickDef != GIMMICK_NONE && GetActiveGimmick(battlerDef) == GIMMICK_NONE)
    {
        toggledGimmickDef = TRUE;
        SetActiveGimmick(battlerDef, aiCalc->gimmickDef);
    }

    // We can set those globals because they are going to get rerolled on attack execution
    gBattleStruct->magnitudeBasePower = 70;
    gBattleStruct->presentBasePower = 80;

    struct DamageContext ctx = {0};
    ctx.aiCalc = TRUE;
    ctx.aiCheckBerryModifier = FALSE;
    ctx.battlerAtk = battlerAtk;
    ctx.battlerDef = battlerDef;
    ctx.move = ctx.chosenMove = move;
    ctx.baseMove = baseMove;
    ctx.randomFactor = FALSE;
    ctx.updateFlags = FALSE;
    ctx.terrain = aiCalc->terrain;
    ctx.weather = aiCalc->weather;
    ctx.fixedBasePower = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == battlerAtk)
            ctx.abilities[battler] = aiData->abilities[battler];
        else
            ctx.abilities[battler] = AI_GetMoldBreakerSanitizedAbility(battlerAtk, aiData->abilities[ctx.battlerAtk], aiData->abilities[battler], aiData->holdEffects[battler], move);

        ctx.holdEffects[battler] = aiData->holdEffects[battler];
    }

    SetDynamicMoveCategory(battlerAtk, battlerDef, move);
    SetTypeBeforeUsingMove(move, battlerAtk, ctx.abilities[battlerAtk], ctx.holdEffects[battlerAtk]);

    ctx.moveType = GetBattleMoveType(move);
    ctx.isCrit = ShouldCalcCritDamage(&ctx);
    ctx.typeEffectivenessModifier = aiCalc->typeEffectiveness = CalcTypeEffectivenessMultiplier(&ctx);

    u32 movePower = GetMovePower(move);

    if (movePower && !IsDamageMoveUnusable(&ctx))
    {
        enum Type types[3];
        AI_StoreBattlerTypes(battlerAtk, types);
        ProteanTryChangeType(battlerAtk, aiData->abilities[battlerAtk], move, ctx.moveType);

        s32 fixedDamage = DoFixedDamageMoveCalc(&ctx);
        if (fixedDamage != INT32_MAX)
        {
            simDamage.minimum = simDamage.median = simDamage.maximum = simDamage.random = fixedDamage;
        }
        else if (moveEffect == EFFECT_TRIPLE_KICK)
        {
            for (gMultiHitCounter = GetMoveStrikeCount(move); gMultiHitCounter > 0; gMultiHitCounter--) // The global is used to simulate actual damage done
            {
                s32 damageByRollType = 0;

                s32 oneTripleKickHit = CalculateMoveDamageVars(&ctx);

                damageByRollType = GetDamageByRollType(oneTripleKickHit, DMG_ROLL_LOWEST);
                simDamage.minimum += AI_ApplyModifiersAfterDmgRoll(&ctx, damageByRollType);

                damageByRollType = GetDamageByRollType(oneTripleKickHit, DMG_ROLL_MEDIAN);
                simDamage.median += AI_ApplyModifiersAfterDmgRoll(&ctx, damageByRollType);

                damageByRollType = GetDamageByRollType(oneTripleKickHit, DMG_ROLL_HIGHEST);
                simDamage.maximum += AI_ApplyModifiersAfterDmgRoll(&ctx, damageByRollType);

                damageByRollType = GetDamageByRollType(oneTripleKickHit, DMG_ROLL_RANDOM);
                simDamage.random += AI_ApplyModifiersAfterDmgRoll(&ctx, damageByRollType);
            }
        }
        else
        {
            u32 damage = CalculateMoveDamageVars(&ctx);

            simDamage.minimum = GetDamageByRollType(damage, DMG_ROLL_LOWEST);
            simDamage.minimum = AI_ApplyModifiersAfterDmgRoll(&ctx, simDamage.minimum);

            simDamage.median = GetDamageByRollType(damage, DMG_ROLL_MEDIAN);
            simDamage.median = AI_ApplyModifiersAfterDmgRoll(&ctx, simDamage.median);

            simDamage.maximum = GetDamageByRollType(damage, DMG_ROLL_HIGHEST);
            simDamage.maximum = AI_ApplyModifiersAfterDmgRoll(&ctx, simDamage.maximum);

            simDamage.random = GetDamageByRollType(damage, DMG_ROLL_RANDOM);
            simDamage.random = AI_ApplyModifiersAfterDmgRoll(&ctx, simDamage.random);
        }

        if (GetActiveGimmick(battlerAtk) != GIMMICK_Z_MOVE)
            CalcDynamicMoveDamage(&ctx, &simDamage);

        AI_RestoreBattlerTypes(battlerAtk, types);
    }
    else
    {
        simDamage.minimum = 0;
        simDamage.median = 0;
        simDamage.maximum = 0;
        simDamage.random = 0;
    }

    // Undo temporary settings
    if (toggledGimmickAtk)
        SetActiveGimmick(battlerAtk, GIMMICK_NONE);
    if (toggledGimmickDef)
        SetActiveGimmick(battlerDef, GIMMICK_NONE);

    gBattleStruct->dynamicMoveType = TYPE_NONE;
    gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;
    gBattleStruct->battlerState[battlerAtk].ateBoost = FALSE;
    gSpecialStatuses[battlerAtk].gemBoost = FALSE;

    gAiLogicData->aiCalcInProgress = FALSE;
    return simDamage;
}

bool32 AI_IsDamagedByRecoil(enum BattlerId battler)
{
    enum Ability ability = gAiLogicData->abilities[battler];
    if (ability == ABILITY_MAGIC_GUARD || ability == ABILITY_ROCK_HEAD)
        return FALSE;
    return TRUE;
}

// Decide whether move having an additional effect for .
static bool32 AI_IsMoveEffectInPlus(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 noOfHitsToKo)
{
    enum Ability abilityDef = gAiLogicData->abilities[battlerDef];
    enum Ability abilityAtk = gAiLogicData->abilities[battlerAtk];
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY);

    if (IsSheerForceAffected(move, abilityAtk)
     && !(move == MOVE_ORDER_UP && gBattleStruct->battlerState[battlerAtk].commanderSpecies != SPECIES_NONE))
    {
        return FALSE;
    }

    switch (GetMoveEffect(move))
    {
    case EFFECT_FELL_STINGER:
        if (BattlerStatCanRise(battlerAtk, abilityAtk, STAT_ATK) && noOfHitsToKo == 1)
            return TRUE;
        break;
    case EFFECT_PURSUIT:
        if (noOfHitsToKo == 1)
            return TRUE;
        break;
    default:
        break;
    }

    u32 isAttackerAtMaxHp = IsBattlerAtMaxHp(battlerAtk);
    enum DamageCategory moveCategory = GetMoveCategory(GetIncomingMove(battlerAtk, battlerDef, gAiLogicData));

    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
        // Consider move effects that target self
        if (additionalEffect->self)
        {
            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_ABSORB:
                if (!isAttackerAtMaxHp || (!aiIsFaster && moveCategory != DAMAGE_CATEGORY_STATUS))
                    return TRUE;
                break;
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

                    if (abilityAtk == ABILITY_CONTRARY)
                        stage = -1 * stage;

                    if (stage < 0)
                        continue;

                    if (gBattleMons[battlerAtk].statStages[stat] < MAX_STAT_STAGE)
                        return TRUE;
                }
                break;
            default:
                break;
            }
        }
        else // consider move effects that hinder the target
        {
            if (IsAdditionalEffectBlocked(battlerAtk, abilityAtk, battlerDef, abilityDef, move))
                continue;

            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_POISON:
            case MOVE_EFFECT_TOXIC:
                if (AI_CanPoison(battlerAtk, battlerDef, abilityDef, move, MOVE_NONE))
                    return TRUE;
                break;
            case MOVE_EFFECT_BURN:
                if (AI_CanBurn(battlerAtk, battlerDef, abilityDef, GetPartnerBattler(battlerAtk), move, MOVE_NONE))
                    return TRUE;
                break;
            case MOVE_EFFECT_FREEZE_OR_FROSTBITE:
                if (CanBeFrozen(battlerAtk, battlerDef, abilityDef))
                    return TRUE;
                break;
            case MOVE_EFFECT_PARALYSIS:
                if (AI_CanParalyze(battlerAtk, battlerDef, abilityDef, move, MOVE_NONE))
                    return TRUE;
                break;
            case MOVE_EFFECT_CONFUSION:
                if (AI_CanConfuse(battlerAtk, battlerDef, abilityDef, GetPartnerBattler(battlerAtk), move, MOVE_NONE))
                    return TRUE;
                break;
            case MOVE_EFFECT_FLINCH:
                if (ShouldTryToFlinch(battlerAtk, battlerDef, abilityAtk, abilityDef, move))
                    return TRUE;
                break;
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

                    if (abilityDef == ABILITY_CONTRARY && !DoesBattlerIgnoreAbilityChecks(battlerAtk, abilityAtk, move))
                        stage = -1 * stage;

                    if (stage > 0)
                        continue;

                    if (gBattleMons[battlerDef].statStages[stat] > MIN_STAT_STAGE && noOfHitsToKo > 1)
                        return TRUE;
                }
                break;
            default:
                break;
            }
        }
    }

    return FALSE;
}

static bool32 AI_IsMoveEffectInMinus(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 noOfHitsToKo)
{
    enum Ability abilityAtk = gAiLogicData->abilities[battlerAtk];
    enum Ability abilityDef = gAiLogicData->abilities[battlerDef];

    if (GetMoveStrikeCount(move) > 1 || IsMultiHitMove(move))
    {
        if (AI_MoveMakesContact(battlerAtk, battlerDef, abilityAtk, gAiLogicData->holdEffects[battlerAtk], move)
         && abilityAtk != ABILITY_MAGIC_GUARD
         && (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_ROCKY_HELMET || abilityDef == ABILITY_IRON_BARBS))
        {
            return TRUE;
        }
    }

    if (IsExplosionMove(move))
        return TRUE;

    switch (GetMoveEffect(move))
    {
    case EFFECT_MAX_HP_50_RECOIL:
    case EFFECT_CHLOROBLAST:
    case EFFECT_FINAL_GAMBIT:
        return TRUE;
    case EFFECT_RECOIL:
    case EFFECT_RECOIL_IF_MISS:
        if (AI_IsDamagedByRecoil(battlerAtk))
            return TRUE;
        break;
    case EFFECT_SEMI_INVULNERABLE:
        if (abilityAtk == ABILITY_NO_GUARD || abilityDef == ABILITY_NO_GUARD)
        {
            if (gAiLogicData->holdEffects[battlerAtk] != HOLD_EFFECT_POWER_HERB)
                return TRUE;
        }
        break;
    case EFFECT_DREAM_EATER:
        if (abilityDef == ABILITY_LIQUID_OOZE && GetConfig(B_DREAM_EATER_LIQUID_OOZE) >= GEN_5)
            return TRUE;
        break;
    default:
    {
        u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
        for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
            switch (additionalEffect->moveEffect)
            {
            case MOVE_EFFECT_ABSORB:
                if (abilityDef == ABILITY_LIQUID_OOZE)
                    return TRUE;
                break;
            case MOVE_EFFECT_STAT_PLUS:
            case MOVE_EFFECT_STAT_MINUS:
                for (enum Stat i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    enum Stat stat = sAccurateStatOrder[i];
                    s32 stage = GetStatStage(stat, additionalEffect);
                    enum Ability ability = ABILITY_NONE;

                    if (stage == 0)
                        continue;

                    if (additionalEffect->self)
                        ability = abilityAtk;
                    else if (!DoesBattlerIgnoreAbilityChecks(battlerAtk, abilityAtk, move))
                        ability = abilityDef;

                    if (additionalEffect->moveEffect == MOVE_EFFECT_STAT_MINUS)
                        stage = -1 * stage;

                    if (ability == ABILITY_CONTRARY)
                        stage = -1 * stage;

                    if (additionalEffect->self)
                    {
                        if (stage < 0)
                            return TRUE;
                        continue;
                    }

                    if (noOfHitsToKo > 1 && stage > 0)
                        return TRUE;
                }
                break;
            case MOVE_EFFECT_RECHARGE:
                return additionalEffect->self;
            default:
                break;
            }
        }
        break;
    }
    }

    return FALSE;
}

// Checks if one of the moves has side effects or perks, assuming equal dmg or equal no of hits to KO
enum MoveComparisonResult CompareMoveEffects(enum Move move1, enum Move move2, enum BattlerId battlerAtk, enum BattlerId battlerDef, s32 noOfHitsToKo)
{
    bool32 effect1minus, effect1plus, effect2minus, effect2plus;
    enum Ability defAbility = gAiLogicData->abilities[battlerDef];
    enum Ability atkAbility = gAiLogicData->abilities[battlerAtk];

    // Check if physical moves hurt.
    if (gAiLogicData->holdEffects[battlerAtk] != HOLD_EFFECT_PROTECTIVE_PADS && atkAbility != ABILITY_LONG_REACH
        && (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_ROCKY_HELMET
        || defAbility == ABILITY_IRON_BARBS || defAbility == ABILITY_ROUGH_SKIN))
    {
        bool32 moveContact1 = MoveMakesContact(move1);
        bool32 moveContact2 = MoveMakesContact(move2);
        if (moveContact1 && !moveContact2)
            return MOVE_LOST_COMPARISON;
        if (moveContact2 && !moveContact1)
            return MOVE_WON_COMPARISON;
    }

    // Check additional effects.
    gAiThinkingStruct->movesetIndex = GetMoveIndex(battlerAtk, move1);
    effect1minus = AI_IsMoveEffectInMinus(battlerAtk, battlerDef, move1, noOfHitsToKo);
    effect1plus = AI_IsMoveEffectInPlus(battlerAtk, battlerDef, move1, noOfHitsToKo);

    gAiThinkingStruct->movesetIndex = GetMoveIndex(battlerAtk, move2);
    effect2plus = AI_IsMoveEffectInPlus(battlerAtk, battlerDef, move2, noOfHitsToKo);
    effect2minus = AI_IsMoveEffectInMinus(battlerAtk, battlerDef, move2, noOfHitsToKo);

    gAiThinkingStruct->movesetIndex = 0;

    if (effect2minus && !effect1minus)
        return MOVE_WON_COMPARISON;
    if (effect1minus && !effect2minus)
        return MOVE_LOST_COMPARISON;

    if (effect2plus && !effect1plus)
        return MOVE_LOST_COMPARISON;
    if (effect1plus && !effect2plus)
        return MOVE_WON_COMPARISON;

    return MOVE_NEUTRAL_COMPARISON;
}

u32 GetNoOfHitsToKO(u32 dmg, s32 hp)
{
    if (dmg == 0)
        return 0;
    return (hp + dmg - 1) / dmg;
}

u32 GetNoOfHitsToKOBattlerDmg(u32 dmg, enum BattlerId battlerDef)
{
    return GetNoOfHitsToKO(dmg, gBattleMons[battlerDef].hp);
}

u32 GetNoOfHitsToKOBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext, enum AiConsiderEndure considerEndure)
{
    u32 hitsToKO = GetNoOfHitsToKOBattlerDmg(AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, gAiLogicData), battlerDef);
    enum Move *moves = GetMovesArray(battlerAtk);

    if (CanEndureHit(battlerAtk, battlerDef, moves[moveIndex]) && hitsToKO == 1 && considerEndure == CONSIDER_ENDURE)
        hitsToKO += 1;

    return hitsToKO;
}

u32 GetBestNoOfHitsToKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext)
{
    u32 result = 100;
    u32 tempResult = 0;

    struct AiLogicData *aiData = gAiLogicData;
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        tempResult = GetNoOfHitsToKOBattler(battlerAtk, battlerDef, moveIndex, calcContext, CONSIDER_ENDURE);
        if (tempResult != 0 && tempResult < result)
            result = tempResult;
    }

    return result;
}

uq4_12_t AI_GetMoveEffectiveness(enum Move move, enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    uq4_12_t typeEffectiveness;

    SaveBattlerData(battlerAtk);
    SaveBattlerData(battlerDef);

    SetBattlerData(battlerAtk);
    SetBattlerData(battlerDef);

    struct DamageContext ctx = {0};
    ctx.battlerAtk = battlerAtk;
    ctx.battlerDef = battlerDef;
    ctx.move = ctx.chosenMove = ctx.baseMove = move;
    ctx.updateFlags = FALSE;
    ctx.weather = AI_GetWeather();
    ctx.terrain = gFieldTimers.terrain;
    ctx.abilities[ctx.battlerAtk] = gAiLogicData->abilities[battlerAtk];
    ctx.abilities[ctx.battlerDef] = gAiLogicData->abilities[battlerDef];
    ctx.holdEffects[ctx.battlerAtk] = gAiLogicData->holdEffects[battlerAtk];
    ctx.holdEffects[ctx.battlerDef] = gAiLogicData->holdEffects[battlerDef];

    SetTypeBeforeUsingMove(move, battlerAtk, ctx.abilities[battlerAtk], ctx.holdEffects[battlerAtk]);
    ctx.moveType = GetBattleMoveType(move);
    typeEffectiveness = CalcTypeEffectivenessMultiplier(&ctx);


    RestoreBattlerData(battlerAtk);
    RestoreBattlerData(battlerDef);

    return typeEffectiveness;
}

/* Checks to see if AI will move ahead of another battler
 * The function uses a stripped down version of the checks from GetWhichBattlerFasterArgs
 * Output:
    * AI_IS_FASTER: is user(ai) faster
    * AI_IS_SLOWER: is target faster
*/
s32 AI_WhoStrikesFirst(enum BattlerId battlerAI, enum BattlerId battler, enum Move aiMoveConsidered, enum Move playerMoveConsidered, enum ConsiderPriority considerPriority)
{
    u32 speedBattlerAI, speedBattler;
    enum HoldEffect holdEffectAI = gAiLogicData->holdEffects[battlerAI];
    enum HoldEffect holdEffectPlayer = gAiLogicData->holdEffects[battler];
    enum Ability abilityAI = gAiLogicData->abilities[battlerAI];
    enum Ability abilityPlayer = gAiLogicData->abilities[battler];

    if (considerPriority == CONSIDER_PRIORITY)
    {
        s8 aiPriority = GetBattleMovePriority(battlerAI, abilityAI, aiMoveConsidered);
        s8 playerPriority = GetBattleMovePriority(battler, abilityPlayer, playerMoveConsidered);

        if (aiPriority > playerPriority)
            return AI_IS_FASTER;
        else if (aiPriority < playerPriority)
            return AI_IS_SLOWER;
    }

    speedBattlerAI = gAiLogicData->speedStats[battlerAI];
    speedBattler   = gAiLogicData->speedStats[battler];

    if (holdEffectAI == HOLD_EFFECT_LAGGING_TAIL && holdEffectPlayer != HOLD_EFFECT_LAGGING_TAIL)
        return AI_IS_SLOWER;
    else if (holdEffectAI != HOLD_EFFECT_LAGGING_TAIL && holdEffectPlayer == HOLD_EFFECT_LAGGING_TAIL)
        return AI_IS_FASTER;

    if (abilityAI == ABILITY_STALL && abilityPlayer != ABILITY_STALL)
        return AI_IS_SLOWER;
    else if (abilityAI != ABILITY_STALL && abilityPlayer == ABILITY_STALL)
        return AI_IS_FASTER;

    if (speedBattlerAI > speedBattler)
    {
        if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
            return AI_IS_SLOWER;
        else
            return AI_IS_FASTER;
    }
    else if (speedBattlerAI == speedBattler)
    {
        return AI_IS_FASTER;
    }
    else
    {
        if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
            return AI_IS_FASTER;
        else
            return AI_IS_SLOWER;
    }

    return AI_IS_SLOWER;
}

static bool32 DragonDartsHitsBothTargets(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (AI_GetBattlerMoveTargetType(battlerAtk, move) != TARGET_SMART)
        return FALSE;
    if (gAiLogicData->dragonDartsHitsBothTarget & 1u << battlerAtk)
        return TRUE;
    return FALSE;
}

bool32 CanEndureHit(enum BattlerId battler, enum BattlerId battlerTarget, enum Move move)
{
    if (!AI_BattlerAtMaxHp(battlerTarget) || IsMultiHitMove(move))
        return FALSE;

    if (gAiLogicData->abilities[battler] == ABILITY_PARENTAL_BOND && AI_IsDoubleSpreadMove(battler, move))
        return FALSE;

    if (GetMoveStrikeCount(move) > 1 && !DragonDartsHitsBothTargets(battler, battlerTarget, move))
        return FALSE;

    if (gAiLogicData->holdEffects[battlerTarget] == HOLD_EFFECT_FOCUS_SASH)
        return TRUE;

    if (!DoesBattlerIgnoreAbilityChecks(battler, gAiLogicData->abilities[battler], move))
    {
        if (GetConfig(B_STURDY) >= GEN_5 && gAiLogicData->abilities[battlerTarget] == ABILITY_STURDY)
            return TRUE;
        if (IsMimikyuDisguised(battlerTarget))
            return TRUE;
        if (gAiLogicData->abilities[battlerTarget] == ABILITY_ICE_FACE
            && gBattleMons[battlerTarget].species == SPECIES_EISCUE_ICE && GetMoveCategory(move) == DAMAGE_CATEGORY_PHYSICAL)
            return TRUE;
    }

    return FALSE;
}

// Check if target has means to faint ai mon.
bool32 CanTargetFaintAi(enum BattlerId battlerDef, enum BattlerId battlerAtk)
{
    struct AiLogicData *aiData = gAiLogicData;
    enum Move *moves = GetMovesArray(battlerDef);
    u32 moveLimitations = aiData->moveLimitations[battlerDef];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        if (AI_GetDamage(battlerDef, battlerAtk, moveIndex, AI_DEFENDING, aiData) >= gBattleMons[battlerAtk].hp
            && !CanEndureHit(battlerDef, battlerAtk, moves[moveIndex]))
            return TRUE;
    }

    return FALSE;
}

u32 NoOfHitsForTargetToFaintBattler(enum BattlerId battlerDef, enum BattlerId battlerAtk, enum DamageCalcContext calcContext, enum AiConsiderEndure considerEndure)
{
    u32 currNumberOfHits;
    u32 leastNumberOfHits = UNKNOWN_NO_OF_HITS;

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        currNumberOfHits = GetNoOfHitsToKOBattler(battlerDef, battlerAtk, moveIndex, calcContext, considerEndure);
        if (currNumberOfHits != 0)
        {
            if (currNumberOfHits < leastNumberOfHits)
                leastNumberOfHits = currNumberOfHits;
        }
    }
    return leastNumberOfHits;
}

u32 NoOfHitsForTargetToFaintBattlerWithMod(enum BattlerId battlerDef, enum BattlerId battlerAtk, s32 hpMod)
{
    u32 currNumberOfHits;
    u32 leastNumberOfHits = UNKNOWN_NO_OF_HITS;
    u32 hpCheck = gBattleMons[battlerAtk].hp + hpMod;
    u32 damageDealt = 0;

    if (hpCheck > gBattleMons[battlerAtk].maxHP)
        hpCheck = gBattleMons[battlerAtk].maxHP;

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        damageDealt = AI_GetDamage(battlerDef, battlerAtk, moveIndex, AI_DEFENDING, gAiLogicData);
        if (damageDealt == 0)
            continue;
        currNumberOfHits = hpCheck / (damageDealt + 1) + 1;
        if (currNumberOfHits != 0)
        {
            if (currNumberOfHits < leastNumberOfHits)
                leastNumberOfHits = currNumberOfHits;
        }
    }
    return leastNumberOfHits;
}

void GetBestDmgMovesFromBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum Move *bestMoves)
{
    struct AiLogicData *aiData = gAiLogicData;
    u32 bestDmg = 0;
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];
    u32 countBestMoves = 0;

    if (CanAIFaintTarget(battlerAtk, battlerDef, 1))
    {
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, moveIndex, calcContext))
                bestMoves[countBestMoves++] = moves[moveIndex];
        }
    }
    else
    {
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations)
            || (GetMovePower(moves[moveIndex]) == 0)
            || (AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, aiData) == 0))
                continue;

            if (bestDmg < AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, aiData))
            {
                countBestMoves = 0;
                bestDmg = AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, aiData);
                *bestMoves = 0;
                bestMoves[countBestMoves++] = moves[moveIndex];
            }
            else if (bestDmg == AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, aiData))
            {
                bestMoves[countBestMoves++] = moves[moveIndex];
            }
        }
    }
}

u32 GetMoveIndex(enum BattlerId battler, enum Move move)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] == move)
            return moveIndex;
    }

    return MAX_MON_MOVES;
}

bool32 IsBestDmgMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum Move move)
{
    enum Move bestMoves[MAX_MON_MOVES] = {MOVE_NONE};
    u32 index = GetMoveIndex(battlerAtk, move);

    if (CanIndexMoveFaintTarget(battlerAtk, battlerDef, index, calcContext))
        return TRUE;

    GetBestDmgMovesFromBattler(battlerAtk, battlerDef, calcContext, bestMoves);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (bestMoves[moveIndex] == move)
            return TRUE;
    }

    return FALSE;
}

bool32 BestDmgMoveHasEffect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext, enum BattleMoveEffects moveEffect)
{
    enum Move bestMoves[MAX_MON_MOVES] = {MOVE_NONE};

    GetBestDmgMovesFromBattler(battlerAtk, battlerDef, calcContext, bestMoves);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (bestMoves[moveIndex] == MOVE_NONE)
            break;

        if (GetMoveEffect(bestMoves[moveIndex]) == moveEffect)
            return TRUE;
    }

    return FALSE;
}

u32 GetBestDmgFromBattler(enum BattlerId battler, enum BattlerId battlerTarget, enum DamageCalcContext calcContext)
{
    struct AiLogicData *aiData = gAiLogicData;
    u32 bestDmg = 0;
    enum Move *moves = GetMovesArray(battler);
    u32 moveLimitations = aiData->moveLimitations[battler];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        u32 damage = AI_GetDamage(battler, battlerTarget, moveIndex, calcContext, aiData);
        if (bestDmg < damage)
            bestDmg = damage;
    }

    return bestDmg;
}

// Check if AI mon has the means to faint the target with any of its moves.
// If numHits > 1, check if the target will be KO'ed by that number of hits (ignoring healing effects)
bool32 CanAIFaintTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 numHits)
{
    struct AiLogicData *aiData = gAiLogicData;
    s32 dmg;
    u16 *moves = gBattleMons[battlerAtk].moves;
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        dmg = AI_GetDamage(battlerAtk, battlerDef, moveIndex, AI_ATTACKING, aiData);

        if (numHits)
            dmg *= numHits;

        if (gBattleMons[battlerDef].hp <= dmg)
        {
            if (numHits > 1)
                return TRUE;

            if (!CanEndureHit(battlerAtk, battlerDef, moves[moveIndex]))
                return TRUE;
        }
    }

    return FALSE;
}

// Can battler KO the target ignoring any Endure effects (Sturdy, Focus Sash, etc.)
bool32 CanBattlerKOTargetIgnoringSturdy(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    struct AiLogicData *aiData = gAiLogicData;
    s32 dmg;
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;
        dmg = AI_GetDamage(battlerAtk, battlerDef, moveIndex, AI_ATTACKING, aiData);

        if (gBattleMons[battlerDef].hp <= dmg && CanEndureHit(battlerAtk, battlerDef, moves[moveIndex]))
            return TRUE;
    }
    return FALSE;
}

bool32 CanTargetMoveFaintAi(enum Move move, enum BattlerId battlerDef, enum BattlerId battlerAtk, u32 nHits)
{
    u32 indexSlot = GetMoveSlot(GetMovesArray(battlerDef), move);
    if (indexSlot < MAX_MON_MOVES)
    {
        u32 hitsToKO = GetNoOfHitsToKO(AI_GetDamage(battlerDef, battlerAtk, indexSlot, AI_DEFENDING, gAiLogicData), gBattleMons[battlerAtk].hp);
        if (hitsToKO <= nHits && hitsToKO != 0 && !(CanEndureHit(battlerDef, battlerAtk, move) && hitsToKO == 1))
            return TRUE;
    }
    return FALSE;
}

// Check if target has means to faint ai mon after modding hp/dmg
bool32 CanTargetFaintAiWithMod(enum BattlerId battlerDef, enum BattlerId battlerAtk, s32 hpMod, s32 dmgMod)
{
    struct AiLogicData *aiData = gAiLogicData;
    s32 dmg;
    enum Move *moves = GetMovesArray(battlerDef);
    u32 hpCheck = gBattleMons[battlerAtk].hp + hpMod;
    u32 moveLimitations = aiData->moveLimitations[battlerAtk];

    if (hpCheck > gBattleMons[battlerAtk].maxHP)
        hpCheck = gBattleMons[battlerAtk].maxHP;

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        dmg = AI_GetDamage(battlerDef, battlerAtk, moveIndex, AI_DEFENDING, aiData);

        if (dmgMod)
            dmg *= dmgMod;

        // Applies modified HP percent to AI data for consideration when running CanEndureHit
        gAiLogicData->hpPercents[battlerAtk] = (hpCheck/gBattleMons[battlerAtk].maxHP)*100;

        if (dmg >= hpCheck && !(CanEndureHit(battlerDef, battlerAtk, moves[moveIndex]) && (dmgMod <= 1)))
        {
            gAiLogicData->hpPercents[battlerAtk] = (gBattleMons[battlerAtk].hp / gBattleMons[battlerAtk].maxHP) * 100;
            return TRUE;
        }
        gAiLogicData->hpPercents[battlerAtk] = (gBattleMons[battlerAtk].hp / gBattleMons[battlerAtk].maxHP) * 100;
    }

    return FALSE;
}

bool32 AI_IsAbilityOnSide(enum BattlerId battlerId, enum Ability ability)
{
    if (IsBattlerAlive(battlerId) && gAiLogicData->abilities[battlerId] == ability)
        return TRUE;
    else if (IsBattlerAlive(GetPartnerBattler(battlerId)) && gAiLogicData->abilities[GetPartnerBattler(battlerId)] == ability)
        return TRUE;
    else
        return FALSE;
}

// does NOT include ability suppression checks
enum Ability AI_DecideKnownAbilityForTurn(enum BattlerId battlerId)
{
    enum Ability validAbilities[NUM_ABILITY_SLOTS];
    u8 numValidAbilities = 0;
    enum Ability knownAbility = GetBattlerAbilityIgnoreMoldBreaker(battlerId);
    enum Ability indexAbility;
    enum Ability abilityAiRatings[NUM_ABILITY_SLOTS] = {0};

    // We've had ability overwritten by e.g. Worry Seed. It is not part of gAiPartyData in case of switching
    if (gBattleMons[battlerId].volatiles.overwrittenAbility)
        return gBattleMons[battlerId].volatiles.overwrittenAbility;

    // The AI knows its own ability, and omniscience handling
    if (IsAiBattlerAware(battlerId) || (IsAiBattlerAssumingStab(battlerId) && ASSUME_STAB_SEES_ABILITY) || IsAiFlagPresent(AI_FLAG_ABILITY_OMNISCIENCE))
        return knownAbility;

    // Check neutralizing gas, gastro acid
    if (knownAbility == ABILITY_NONE)
        return knownAbility;

    if (gAiPartyData->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].ability != ABILITY_NONE)
        return gAiPartyData->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].ability;

    // Abilities that prevent fleeing - treat as always known
    if (knownAbility == ABILITY_SHADOW_TAG || knownAbility == ABILITY_MAGNET_PULL || knownAbility == ABILITY_ARENA_TRAP)
        return knownAbility;

    for (u32 abilityIndex = 0; abilityIndex < NUM_ABILITY_SLOTS; abilityIndex++)
    {
        indexAbility = GetSpeciesAbility(gBattleMons[battlerId].species, abilityIndex);
        if (indexAbility != ABILITY_NONE)
        {
            abilityAiRatings[numValidAbilities] = gAbilitiesInfo[indexAbility].aiRating;
            validAbilities[numValidAbilities++] = indexAbility;
        }
    }

    if (numValidAbilities > 0 && IsAiBattlerPredictingAbility(battlerId))
        return validAbilities[RandomWeighted(RNG_AI_PREDICT_ABILITY, abilityAiRatings[0], abilityAiRatings[1], abilityAiRatings[2])];

    if (numValidAbilities > 0)
        return validAbilities[RandomUniform(RNG_AI_ABILITY, 0, numValidAbilities - 1)];

    return ABILITY_NONE; // Unknown.
}

enum HoldEffect AI_DecideHoldEffectForTurn(enum BattlerId battlerId)
{
    enum HoldEffect holdEffect = HOLD_EFFECT_NONE;

    if (gBattleMons[battlerId].item == ITEM_NONE) // Failsafe for when user recorded an item but it was consumed
        return holdEffect;

    if (!IsAiBattlerAware(battlerId) && !IsAiFlagPresent(AI_FLAG_ITEM_OMNISCIENCE))
        holdEffect = gAiPartyData->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].heldEffect;
    else
        holdEffect = GetBattlerHoldEffectIgnoreNegation(battlerId);

    if (gAiThinkingStruct->aiFlags[battlerId] & AI_FLAG_NEGATE_UNAWARE)
        return holdEffect;

    if (gBattleMons[battlerId].volatiles.embargoTimer)
        return HOLD_EFFECT_NONE;
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        return HOLD_EFFECT_NONE;
    if (gAiLogicData->abilities[battlerId] == ABILITY_KLUTZ && !gBattleMons[battlerId].volatiles.gastroAcid)
        return HOLD_EFFECT_NONE;

    return holdEffect;
}

bool32 DoesBattlerIgnoreAbilityChecks(enum BattlerId battlerAtk, enum Ability atkAbility, enum Move move)
{
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_NEGATE_UNAWARE)
        return FALSE;   // AI handicap flag: doesn't understand ability suppression concept

    if (atkAbility == ABILITY_MYCELIUM_MIGHT && IsBattleMoveStatus(move))
        return TRUE;

    if (IsMoldBreakerTypeAbility(battlerAtk, atkAbility, move) || MoveIgnoresTargetAbility(move))
        return TRUE;

    return FALSE;
}

static inline bool32 AI_WeatherHasEffect(void)
{
    if (gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_LEFT] & AI_FLAG_NEGATE_UNAWARE
     || gAiThinkingStruct->aiFlags[B_POSITION_OPPONENT_RIGHT] & AI_FLAG_NEGATE_UNAWARE)
        return TRUE;   // AI doesn't understand weather supression (handicap)

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        switch (gAiLogicData->abilities[battler])
        {
        case ABILITY_CLOUD_NINE:
        case ABILITY_AIR_LOCK:
            return FALSE;
        default:
            break;
        }
    }

    return TRUE;
}

u32 AI_GetWeather(void)
{
    if (gBattleWeather == B_WEATHER_NONE)
        return B_WEATHER_NONE;
    if (!AI_WeatherHasEffect())
        return B_WEATHER_NONE;
    return gBattleWeather;
}

u32 AI_GetSwitchinWeather(enum BattlerId battler)
{
    enum Ability ability = gAiLogicData->abilities[battler];

    // Forced weather behaviour
    if (!AI_WeatherHasEffect())
        return B_WEATHER_NONE;
    if (ability == ABILITY_CLOUD_NINE || ability == ABILITY_AIR_LOCK)
        return B_WEATHER_NONE;
    if (gBattleWeather & B_WEATHER_PRIMAL_ANY)
        return gBattleWeather;

    // Switchin will introduce new weather
    switch (ability)
    {
    case ABILITY_DRIZZLE:
        return B_WEATHER_RAIN_NORMAL;
    case ABILITY_DROUGHT:
    case ABILITY_ORICHALCUM_PULSE:
        return B_WEATHER_SUN_NORMAL;
    case ABILITY_SAND_STREAM:
        return B_WEATHER_SANDSTORM;
    case ABILITY_SNOW_WARNING:
        return GetConfig(B_SNOW_WARNING) >= GEN_9 ? B_WEATHER_SNOW : B_WEATHER_HAIL;
    default:
        return gBattleWeather;
    }
}

u32 AI_GetSwitchinTerrain(enum BattlerId battler)
{
    enum BattleTerrain newTerrain;

    if (gBattleStruct->isSkyBattle)
        return gFieldTimers.terrain;

    // Switchin will introduce new terrain
    switch (gAiLogicData->abilities[battler])
    {
    case ABILITY_ELECTRIC_SURGE:
    case ABILITY_HADRON_ENGINE:
        newTerrain = B_TERRAIN_ELECTRIC;
        break;
    case ABILITY_GRASSY_SURGE:
        newTerrain = B_TERRAIN_GRASSY;
        break;
    case ABILITY_MISTY_SURGE:
        newTerrain = B_TERRAIN_MISTY;
        break;
    case ABILITY_PSYCHIC_SURGE:
        newTerrain = B_TERRAIN_PSYCHIC;
        break;
    default:
        return gFieldTimers.terrain;
    }

    if (gFieldTimers.terrain != newTerrain)
        return newTerrain;
    return gFieldTimers.terrain;
}

enum WeatherState IsWeatherActive(u32 flags)
{
    enum WeatherState state = WEATHER_INACTIVE;

    if (gBattleWeather & flags)
        state = WEATHER_ACTIVE;
    else
        state = WEATHER_INACTIVE;

    if (!AI_WeatherHasEffect())
    {
        if (state == WEATHER_ACTIVE)
            state = WEATHER_ACTIVE_BUT_BLOCKED;
        else
            state = WEATHER_INACTIVE_AND_BLOCKED;
    }

    return state;
}

bool32 IsAromaVeilProtectedEffect(enum BattleMoveEffects moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_DISABLE:
    case EFFECT_ATTRACT:
    case EFFECT_ENCORE:
    case EFFECT_TORMENT:
    case EFFECT_TAUNT:
    case EFFECT_HEAL_BLOCK:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsNonVolatileStatusMove(enum Move move)
{
    return GetMoveNonVolatileStatus(move) != MOVE_EFFECT_NONE;
}

bool32 IsConfusionMoveEffect(enum BattleMoveEffects moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_CONFUSE:
    case EFFECT_SWAGGER:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsHazardMove(enum Move move)
{
    // Hazard setting moves like Stealth Rock, Spikes, etc.
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    switch (moveEffect)
    {
    case EFFECT_CEASELESS_EDGE:
    case EFFECT_SPIKES:
    case EFFECT_STEALTH_ROCK:
    case EFFECT_STICKY_WEB:
    case EFFECT_STONE_AXE:
    case EFFECT_TOXIC_SPIKES:
        return TRUE;
    default:
        break;
    }

    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
        switch (additionalEffect->moveEffect)
        {
        case MOVE_EFFECT_STEALTH_ROCK:
        case MOVE_EFFECT_STEELSURGE:
            return TRUE;
        default:
            break;
        }
    }
    return FALSE;
}

bool32 IsHazardClearingMove(enum Move move)
{
    // Hazard clearing effects like Rapid Spin, Tidy Up, etc.
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    switch (moveEffect)
    {
    case EFFECT_RAPID_SPIN:
    case EFFECT_TIDY_UP:
        return TRUE;
    case EFFECT_DEFOG:
        if (GetConfig(B_DEFOG_EFFECT_CLEARING) >= GEN_6)
            return TRUE;
        break;
    default:
        break;
    }

    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
        switch (additionalEffect->moveEffect)
        {
        case MOVE_EFFECT_DEFOG:
            return TRUE;
        default:
            break;
        }
    }

    return FALSE;
}

bool32 IsAllyProtectingFromMove(enum BattlerId battlerAtk, enum Move attackerMove, enum Move allyMove)
{
    enum BattleMoveEffects effect = GetMoveEffect(allyMove);

    if (effect != EFFECT_PROTECT)
    {
        return FALSE;
    }

    enum ProtectMethod protectMethod = GetMoveProtectMethod(allyMove);

    switch (protectMethod)
    {
    case PROTECT_CRAFTY_SHIELD:
        if (!IsBattleMoveStatus(attackerMove))
        {
            return FALSE;
        }
        else if (GetMoveEffect(attackerMove) == EFFECT_HOLD_HANDS)
        {
            return TRUE;
        }
        else
        {
            u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, attackerMove);
            return (GetBattlerSide(battlerAtk) != GetBattlerSide(GetPartnerBattler(battlerAtk))
                && moveTarget != TARGET_OPPONENTS_FIELD
                && moveTarget != TARGET_ALL_BATTLERS);
        }
    case PROTECT_WIDE_GUARD:
        return IsSpreadMove(GetBattlerMoveTargetType(battlerAtk, attackerMove));
    case PROTECT_NORMAL:
    case PROTECT_SPIKY_SHIELD:
    case PROTECT_MAX_GUARD:
    case PROTECT_BANEFUL_BUNKER:
    case PROTECT_BURNING_BULWARK:
        return TRUE;
    case PROTECT_OBSTRUCT:
    case PROTECT_SILK_TRAP:
    case PROTECT_KINGS_SHIELD:
        return !IsBattleMoveStatus(attackerMove);
    case PROTECT_QUICK_GUARD:
        return (GetChosenMovePriority(battlerAtk, gAiLogicData->abilities[battlerAtk]) > 0);
    case PROTECT_MAT_BLOCK:
        return !IsBattleMoveStatus(attackerMove);
    default:
        return FALSE;
    }
}

bool32 IsMoveRedirectionPrevented(enum BattlerId battlerAtk, enum Move move, enum Ability atkAbility)
{
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_NEGATE_UNAWARE)
        return FALSE;

    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_SKY_DROP
      || effect == EFFECT_SNIPE_SHOT
      || atkAbility == ABILITY_PROPELLER_TAIL
      || atkAbility == ABILITY_STALWART)
        return TRUE;
    return FALSE;
}

bool32 ShouldTryOHKO(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability atkAbility, enum Ability defAbility, enum Move move)
{
    enum HoldEffect holdEffect = gAiLogicData->holdEffects[battlerDef];
    u32 accuracy = gAiLogicData->moveAccuracy[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex];

    gPotentialItemEffectBattler = battlerDef;
    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < GetBattlerHoldEffectParam(battlerDef))
        return FALSE;   //probabilistically speaking, focus band should activate so dont OHKO
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && AI_BattlerAtMaxHp(battlerDef))
        return FALSE;

    if (!DoesBattlerIgnoreAbilityChecks(battlerAtk, atkAbility, move) && defAbility == ABILITY_STURDY)
        return FALSE;

    bool32 sureHit = (gBattleMons[battlerAtk].volatiles.battlerWithSureHit == battlerDef + 1) || atkAbility == ABILITY_NO_GUARD || defAbility == ABILITY_NO_GUARD;
    if (sureHit && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
    {
        return TRUE;
    }
    else    // test the odds
    {
        u32 odds = accuracy + (gBattleMons[battlerAtk].level - gBattleMons[battlerDef].level);
        if (MoveDecreasesAccIfUserNotSameType(move) && !IS_BATTLER_OF_TYPE(battlerAtk, GetMoveType(move)))
            odds -= 10;
        if (Random() % 100 + 1 < odds && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
            return TRUE;
    }
    return FALSE;
}

bool32 ShouldRaiseAnyStat(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    // Don't increase stats if opposing battler has Unaware
    if (AI_IsAbilityOnSide(battlerDef, ABILITY_UNAWARE))
        return FALSE;

    // Don't increase stats if Yawn'd
    if (gBattleMons[battlerAtk].volatiles.yawn && CanBeSlept(battlerDef, battlerDef, gAiLogicData->abilities[battlerDef], BLOCKED_BY_SLEEP_CLAUSE))
        return FALSE;

    // Don't set up if AI is dead to residual damage from weather
    if (GetBattlerSecondaryDamage(battlerAtk) >= gBattleMons[battlerAtk].hp)
        return FALSE;

    // Don't increase stats if opposing battler has Opportunist
    if (AI_IsAbilityOnSide(battlerDef, ABILITY_OPPORTUNIST))
        return FALSE;

    // Don't increase stats if opposing battler has used Haze effect or AI effect
    if (!RandomPercentage(RNG_AI_BOOST_INTO_HAZE, BOOST_INTO_HAZE_CHANCE)
      && HasBattlerSideUsedMoveWithEffect(battlerDef, EFFECT_HAZE))
        return FALSE;

    if (CountPositiveStatStages(battlerAtk) > 0
      && HasBattlerSideMoveWithAIEffect(battlerDef, AI_EFFECT_RESET_STATS))
        return FALSE;

    // Don't increase stats if AI could KO target through Sturdy effect, as otherwise it always 2HKOs
    if (CanBattlerKOTargetIgnoringSturdy(battlerAtk, battlerDef))
        return FALSE;

    return TRUE;
}

bool32 ShouldSetWeather(enum BattlerId battler, u32 weather)
{
    if (AI_GetWeather() & weather)
        return FALSE;

    return WeatherChecker(battler, weather, FIELD_EFFECT_POSITIVE);
}

bool32 ShouldClearWeather(enum BattlerId battler, u32 weather)
{
    return WeatherChecker(battler, weather, FIELD_EFFECT_NEGATIVE);
}

bool32 ShouldSetTerrain(enum BattlerId battler, enum BattleTerrain terrain)
{
    return TerrainChecker(battler, terrain, FIELD_EFFECT_POSITIVE);
}

bool32 ShouldClearTerrain(enum BattlerId battler, enum BattleTerrain terrain)
{
    return TerrainChecker(battler, terrain, FIELD_EFFECT_NEGATIVE);
}

bool32 ShouldSetFieldStatus(enum BattlerId battler, u32 fieldStatus)
{
    if (gFieldStatuses & fieldStatus)
    {
        if (!(fieldStatus & STATUS_FIELD_TRICK_ROOM))
            return FALSE;
        // DOUBLE_TRICK_ROOM_ON_LAST_TURN_CHANCE
        else if (gFieldTimers.trickRoomTimer != 1)
            return FALSE;
    }

    return FieldStatusChecker(battler, fieldStatus, FIELD_EFFECT_POSITIVE);
}

bool32 ShouldClearFieldStatus(enum BattlerId battler, u32 fieldStatus)
{
    return FieldStatusChecker(battler, fieldStatus, FIELD_EFFECT_NEGATIVE);
}

bool32 IsBattlerDamagedByStatus(enum BattlerId battler)
{
    return gBattleMons[battler].status1 & STATUS1_DAMAGING
        || gBattleMons[battler].volatiles.wrapped
        || gBattleMons[battler].volatiles.nightmare
        || gBattleMons[battler].volatiles.cursed
        || gBattleMons[battler].volatiles.saltCure
        || gBattleMons[battler].volatiles.leechSeed
        || gBattleMons[battler].volatiles.perishSong
        || gSideStatuses[GetBattlerSide(battler)] & (SIDE_STATUS_SEA_OF_FIRE | SIDE_STATUS_DAMAGE_NON_TYPES);
}

static bool32 ShouldAvoidProtectingAgainstPartnerMove(enum BattlerId battler, enum Move protectMove)
{
    enum BattlerId partner = GetPartnerBattler(battler);
    enum Move partnerMove;

    if (!IsDoubleBattle()
     || !HasPartner(battler)
     || !(gAiLogicData->battlerMovesScored & (1u << partner))
     || gAiLogicData->shouldSwitch & (1u << partner))
    {
        return FALSE;
    }

    partnerMove = gBattleMons[partner].moves[gAiBattleData->chosenMoveIndex[partner]];
    if (partnerMove == MOVE_NONE
     || partnerMove == MOVE_UNAVAILABLE
     || MoveIgnoresProtect(partnerMove)
     || !AI_IsFaster(battler, partner, protectMove, partnerMove, CONSIDER_PRIORITY)
     || !IsAllyProtectingFromMove(partner, partnerMove, protectMove)
     || CanIndexMoveFaintTarget(partner, battler, gAiBattleData->chosenMoveIndex[partner], AI_ATTACKING))
    {
        return FALSE;
    }

    switch (AI_GetBattlerMoveTargetType(partner, partnerMove))
    {
    case TARGET_SELECTED:
    case TARGET_SMART:
    case TARGET_DEPENDS:
    case TARGET_RANDOM:
    case TARGET_ALLY:
    case TARGET_USER_OR_ALLY:
        return gAiBattleData->chosenTarget[partner] == battler;
    case TARGET_FOES_AND_ALLY:
    case TARGET_ALL_BATTLERS:
        if (!DoesBattlerIgnoreAbilityChecks(partner, gAiLogicData->abilities[partner], partnerMove)
         && ShouldTriggerAbility(partner, battler, gAiLogicData->abilities[battler]))
        {
            return TRUE;
        }

        if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_WEAKNESS_POLICY
         && gAiLogicData->effectiveness[partner][battler][gAiBattleData->chosenMoveIndex[partner]] >= UQ_4_12(2.0))
        {
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

s32 ProtectChecks(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum Move predictedMove)
{
    s32 score = 0;

    // TODO more sophisticated logic
    u32 uses = gBattleMons[battlerAtk].volatiles.consecutiveMoveUses;

    if (predictedMove != MOVE_NONE && predictedMove != MOVE_UNAVAILABLE)
    {
        if (MoveIgnoresProtect(predictedMove))
            return WORST_EFFECT;
    }

    if (GetMoveProtectMethod(move) != PROTECT_MAX_GUARD
     && AI_CanContactBypassProtect(battlerDef, battlerAtk, predictedMove))
    {
        return WORST_EFFECT;
    }

    if (ShouldAvoidProtectingAgainstPartnerMove(battlerAtk, move))
        return WORST_EFFECT;

    /*if (GetMoveResultFlags(predictedMove) & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
    {
        ADJUST_SCORE_PTR(-5);
        return;
    }*/

    if (uses == 0)
    {
        if (predictedMove != MOVE_NONE && predictedMove != MOVE_UNAVAILABLE && !IsBattleMoveStatus(predictedMove))
            score += DECENT_EFFECT;
        else if (Random() % 256 < 100)
            score += WEAK_EFFECT;
    }
    else
    {
        if (!IsBattle1v1())
            score -= (2 * min(uses, 3));
        else
            score -= (min(uses, 3));
    }

    if (IsBattlerDamagedByStatus(battlerAtk))
    {
        score -= 1;
    }

    if (IsBattlerDamagedByStatus(battlerDef))
    {
        score += DECENT_EFFECT;
    }

    return score;
}

// stat stages
bool32 CanLowerStat(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData, enum Stat stat)
{
    if (gBattleMons[battlerDef].statStages[stat] == MIN_STAT_STAGE)
        return FALSE;

    if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_CLEAR_AMULET)
        return FALSE;

    enum Move move = gAiThinkingStruct->moveConsidered;
    enum Ability abilityAtk = aiData->abilities[battlerAtk];

    if (gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_MIST && abilityAtk != ABILITY_INFILTRATOR)
        return FALSE;

    if (!DoesBattlerIgnoreAbilityChecks(battlerAtk, abilityAtk, move))
    {
        if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_GRASS) && AI_IsAbilityOnSide(battlerDef, ABILITY_FLOWER_VEIL))
            return FALSE;

        switch (aiData->abilities[battlerDef])
        {
        case ABILITY_SPEED_BOOST:
            if (stat == STAT_SPEED)
                return FALSE;
            break;
        case ABILITY_HYPER_CUTTER:
            if (stat == STAT_ATK)
                return FALSE;
            break;
        case ABILITY_BIG_PECKS:
            if (stat == STAT_DEF)
                return FALSE;
            break;
        case ABILITY_ILLUMINATE:
            if (GetConfig(B_ILLUMINATE_EFFECT) >= GEN_9 && stat == STAT_ACC)
                return FALSE;
            break;
        case ABILITY_KEEN_EYE:
        case ABILITY_MINDS_EYE:
            if (stat == STAT_ACC)
                return FALSE;
            break;
        case ABILITY_CONTRARY:
        case ABILITY_CLEAR_BODY:
        case ABILITY_WHITE_SMOKE:
        case ABILITY_FULL_METAL_BODY:
            return FALSE;
        case ABILITY_SHIELD_DUST:
            if (!IsBattleMoveStatus(move) && GetActiveGimmick(battlerAtk) != GIMMICK_DYNAMAX)
                return FALSE;
            break;
        default:
            break;
        }
    }

    if (stat == STAT_SPEED)
    {
        enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
        // If AI is faster and doesn't have any mons left, lowering speed doesn't give any
        return !(AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, DONT_CONSIDER_PRIORITY)
            && CountUsablePartyMons(battlerAtk) == 0
            && !HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_ELECTRO_BALL));
    }

    return TRUE;
}

enum AIScore IncreaseStatDownScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat)
{
    enum AIScore tempScore = NO_INCREASE;

    // Don't increase score if target is already -3 stat stage
    if (stat != STAT_SPEED && gBattleMons[battlerDef].statStages[stat] <= DEFAULT_STAT_STAGE - 3)
        return NO_INCREASE;

    // Don't decrease stat if target will die to residual damage
    if (GetBattlerSecondaryDamage(battlerDef) >= gBattleMons[battlerDef].hp)
        return NO_INCREASE;

    if (DoesAbilityRaiseStatsWhenLowered(gAiLogicData->abilities[battlerDef]))
        return NO_INCREASE;

    // Don't increase score if AI can just KO
    if (GetNoOfHitsToKOBattlerDmg(GetBestDmgFromBattler(battlerAtk, battlerDef, AI_ATTACKING), battlerDef) == 1)
        return NO_INCREASE;

    // TODO: Avoid decreasing stat if
    // player can kill ai in 2 hits with decreased attack / sp atk stages
    // ai can kill target in 2 hits without decreasing defense / sp def stages

    switch (stat)
    {
    case STAT_ATK:
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
            tempScore += DECENT_EFFECT;
        break;
    case STAT_DEF:
        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL)
         || HasMoveWithCategory(GetPartnerBattler(battlerAtk), DAMAGE_CATEGORY_PHYSICAL))
            tempScore += DECENT_EFFECT;
        break;
    case STAT_SPEED:
    {
        enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
        if (AI_IsSlower(battlerAtk, battlerDef, MOVE_NONE, predictedMove, DONT_CONSIDER_PRIORITY)
        || AI_IsSlower(GetPartnerBattler(battlerAtk), battlerDef, MOVE_NONE, predictedMove, DONT_CONSIDER_PRIORITY))
            tempScore += DECENT_EFFECT;
        break;
    }
    case STAT_SPATK:
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
            tempScore += DECENT_EFFECT;
        break;
    case STAT_SPDEF:
        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL)
         || HasMoveWithCategory(GetPartnerBattler(battlerAtk), DAMAGE_CATEGORY_SPECIAL))
            tempScore += DECENT_EFFECT;
        break;
    case STAT_ACC:
        tempScore += WEAK_EFFECT;
        if (IsBattlerTrapped(battlerAtk, battlerDef))
            tempScore += DECENT_EFFECT;
        if (gBattleMons[battlerDef].volatiles.leechSeed)
            tempScore += WEAK_EFFECT;
        if (gBattleMons[battlerDef].volatiles.cursed)
            tempScore += WEAK_EFFECT;
        break;
    case STAT_EVASION:
        if (gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY)
            tempScore += WEAK_EFFECT;
        if (gBattleMons[battlerDef].volatiles.leechSeed)
            tempScore += WEAK_EFFECT;
        if (gBattleMons[battlerDef].volatiles.root)
            tempScore += WEAK_EFFECT;
        if (gBattleMons[battlerDef].volatiles.cursed)
            tempScore += WEAK_EFFECT;
        break;
    default:
        break;
    }

    return (tempScore > BEST_EFFECT) ? BEST_EFFECT : tempScore; // don't inflate score so only max +4
}

bool32 BattlerStatCanRise(enum BattlerId battler, enum Ability battlerAbility, enum Stat stat)
{
    if ((gBattleMons[battler].statStages[stat] < MAX_STAT_STAGE && battlerAbility != ABILITY_CONTRARY)
      || (battlerAbility == ABILITY_CONTRARY && gBattleMons[battler].statStages[stat] > MIN_STAT_STAGE))
        return TRUE;
    return FALSE;
}

bool32 AreBattlersStatsMaxed(enum BattlerId battlerId)
{
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battlerId].statStages[statId] < MAX_STAT_STAGE)
            return FALSE;
    }
    return TRUE;
}

bool32 AnyStatIsRaised(enum BattlerId battlerId)
{
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battlerId].statStages[statId] > DEFAULT_STAT_STAGE)
            return TRUE;
    }
    return FALSE;
}

u32 CountPositiveStatStages(enum BattlerId battlerId)
{
    u32 count = 0;
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battlerId].statStages[statId] > DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

u32 CountNegativeStatStages(enum BattlerId battlerId)
{
    u32 count = 0;
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battlerId].statStages[statId] < DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

bool32 CanIndexMoveFaintTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 moveIndex, enum DamageCalcContext calcContext)
{
    s32 dmg;
    enum Move *moves = gBattleMons[battlerAtk].moves;

    if (IsDoubleBattle() && battlerDef == GetPartnerBattler(battlerAtk))
        dmg = AI_GetDamage(battlerAtk, battlerDef, moveIndex, AI_ATTACKING_PARTNER, gAiLogicData); // Attacking partner, be careful
    else
        dmg = AI_GetDamage(battlerAtk, battlerDef, moveIndex, calcContext, gAiLogicData);

    if (gBattleMons[battlerDef].hp <= dmg && !CanEndureHit(battlerAtk, battlerDef, moves[moveIndex]))
        return TRUE;
    return FALSE;
}

enum Move *GetMovesArray(enum BattlerId battler)
{
    if (IsAiBattlerAware(battler) || IsAiBattlerAware(GetPartnerBattler(battler)) || IsAiFlagPresent(AI_FLAG_MOVE_OMNISCIENCE))
        return gBattleMons[battler].moves;
    else
        return gBattleHistory->usedMoves[battler];
}

u32 GetBattlerMoveIndexWithEffect(enum BattlerId battler, enum BattleMoveEffects effect)
{
    enum Move *moves = GetMovesArray(battler);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (GetMoveEffect(moves[moveIndex]) == effect)
            return moveIndex;
    }
    return MAX_MON_MOVES;
}

static u32 GetUsableMoveIndexWithEffect(enum BattlerId battler, enum BattleMoveEffects effect, u32 moveLimitations)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move battlerMove = moves[moveIndex];
        if (!IsMoveUnusable(moveIndex, battlerMove, moveLimitations) && GetMoveEffect(battlerMove) == effect)
            return moveIndex;
    }

    return MAX_MON_MOVES;
}

static bool32 CanMoveIndexHitAnyOpponent(enum BattlerId battler, u32 moveIndex, struct AiLogicData *aiData)
{
    enum BattlerId leftFoe = GetBattlerLeftFoe(battler);
    enum BattlerId rightFoe = GetBattlerRightFoe(battler);

    if (IsBattlerAlive(leftFoe) && aiData->effectiveness[battler][leftFoe][moveIndex] > UQ_4_12(0.0))
        return TRUE;
    if (IsBattlerAlive(rightFoe) && aiData->effectiveness[battler][rightFoe][moveIndex] > UQ_4_12(0.0))
        return TRUE;

    return FALSE;
}

bool32 ShouldBeatUpForJustified(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, enum Type moveType, bool32 wouldPartnerFaint, struct AiLogicData *aiData)
{
    enum Ability atkPartnerAbility = aiData->abilities[battlerAtkPartner];

    if (wouldPartnerFaint
     || gBattleStruct->monToSwitchIntoId[battlerAtkPartner] != PARTY_SIZE)
        return FALSE;

    if (atkPartnerAbility != ABILITY_JUSTIFIED
     || moveType != TYPE_DARK
     || IsBattleMoveStatus(move)
     || DoesBattlerIgnoreAbilityChecks(battlerAtk, aiData->abilities[battlerAtk], move)
     || IsSubstituteProtected(battlerAtk, battlerAtkPartner, aiData->abilities[battlerAtk], move))
        return FALSE;

    return (HasMoveWithCategory(battlerAtkPartner, DAMAGE_CATEGORY_PHYSICAL)
         && BattlerStatCanRise(battlerAtkPartner, atkPartnerAbility, STAT_ATK));
}

bool32 ShouldBeatUpForRageFist(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, bool32 wouldPartnerFaint, struct AiLogicData *aiData)
{
    if (wouldPartnerFaint
     || gBattleStruct->monToSwitchIntoId[battlerAtkPartner] != PARTY_SIZE)
        return FALSE;

    if (IsBattleMoveStatus(move)
     || IsSubstituteProtected(battlerAtk, battlerAtkPartner, aiData->abilities[battlerAtk], move)
     || GetBattlerPartyState(battlerAtkPartner)->timesGotHit >= 4) // Power is already high beyond this.
        return FALSE;

    u32 rageFistMoveIndex = GetUsableMoveIndexWithEffect(battlerAtkPartner, EFFECT_RAGE_FIST, aiData->moveLimitations[battlerAtkPartner]);

    return (rageFistMoveIndex != MAX_MON_MOVES
         && CanMoveIndexHitAnyOpponent(battlerAtkPartner, rageFistMoveIndex, aiData));
}

static bool32 ShouldSelfInflictBurnForBenefit(enum BattlerId battler, enum Ability ability)
{
    if (!CanBeBurned(battler, battler, ability))
        return FALSE;

    return (ability == ABILITY_MARVEL_SCALE
         || ability == ABILITY_QUICK_FEET
         || (ability == ABILITY_GUTS && HasMoveWithCategory(battler, DAMAGE_CATEGORY_PHYSICAL))
         || (ability == ABILITY_FLARE_BOOST && HasMoveWithCategory(battler, DAMAGE_CATEGORY_SPECIAL))
         || HasMoveWithEffect(battler, EFFECT_FACADE));
}

bool32 ShouldTriggerSpicySprayForBurn(enum BattlerId battlerAtk, enum Move move, u32 noOfHitsToKOPartner, struct AiLogicData *aiData)
{
    enum BattlerId partner = GetPartnerBattler(battlerAtk);

    if (!HasPartner(battlerAtk)
     || gBattleStruct->monToSwitchIntoId[partner] != PARTY_SIZE
     || aiData->abilities[partner] != ABILITY_SPICY_SPRAY)
        return FALSE;

    if (noOfHitsToKOPartner == 0
     || IsSelfSacrificeEffect(move)
     || GetMoveEffect(move) == EFFECT_MAX_HP_50_RECOIL
     || IsSubstituteProtected(battlerAtk, partner, aiData->abilities[battlerAtk], move))
        return FALSE;

    enum HoldEffect holdEffect = aiData->holdEffects[battlerAtk];

    if (holdEffect == HOLD_EFFECT_FLAME_ORB)
        return FALSE;

    if ((holdEffect == HOLD_EFFECT_CURE_BRN || holdEffect == HOLD_EFFECT_CURE_STATUS)
     && !IsUnnerveBlocked(battlerAtk, aiData->items[battlerAtk]))
        return FALSE;

    return ShouldSelfInflictBurnForBenefit(battlerAtk, aiData->abilities[battlerAtk]);
}

bool32 HasPhysicalBestMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum DamageCalcContext calcContext)
{
    enum Move atkBestMoves[MAX_MON_MOVES] = {MOVE_NONE};
    GetBestDmgMovesFromBattler(battlerAtk, battlerDef, calcContext, atkBestMoves);
    bool32 bestMoveIsPhysical = TRUE;
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (atkBestMoves[moveIndex] == MOVE_NONE)
        {
            break;
        }
        else
        {
            if (GetBattleMoveCategory(atkBestMoves[moveIndex]) == DAMAGE_CATEGORY_SPECIAL)
            {
                bestMoveIsPhysical = FALSE;
                break;
            }
        }
    }
    return bestMoveIsPhysical;
}

bool32 HasOnlyMovesWithCategory(enum BattlerId battlerId, enum DamageCategory category, bool32 onlyOffensive)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (onlyOffensive && IsBattleMoveStatus(moves[moveIndex]))
            continue;
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetBattleMoveCategory(moves[moveIndex]) != category)
            return FALSE;
    }

    return TRUE;
}

bool32 HasMoveWithCategory(enum BattlerId battler, enum DamageCategory category)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetBattleMoveCategory(moves[moveIndex]) == category)
            return TRUE;
    }
    return FALSE;
}

bool32 HasMoveWithType(enum BattlerId battler, enum Type type)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetMoveType(moves[moveIndex]) == type)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects effect)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetMoveEffect(moves[moveIndex]) == effect)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithAIEffect(enum BattlerId battler, u32 aiEffect)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE)
        {
            if (GetAIEffectGroupFromMove(battler, moves[moveIndex]) & aiEffect)
                return TRUE;
        }
    }

    return FALSE;
}

bool32 HasBattlerSideMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects effect)
{
    if (HasMoveWithEffect(battler, effect))
        return TRUE;
    if (HasPartnerIgnoreFlags(battler) && HasMoveWithEffect(GetPartnerBattler(battler), effect))
        return TRUE;
    return FALSE;
}

bool32 HasBattlerSideMoveWithAIEffect(enum BattlerId battler, u32 aiEffect)
{
    if (HasMoveWithAIEffect(battler, aiEffect))
        return TRUE;
    if (HasPartnerIgnoreFlags(battler) && HasMoveWithAIEffect(GetPartnerBattler(battler), aiEffect))
        return TRUE;
    return FALSE;
}

// HasBattlerSideMoveWithEffect checks if the AI knows a side has a move effect,
// while HasBattlerSideUsedMoveWithEffect checks if the side has actively USED the move effect.
// It matches both on move effect and on AI move effect; eg, EFFECT_HAZE will also bring up Freezy Frost or Clear Smog, anything with AI_EFFECT_RESET_STATS.
bool32 HasBattlerSideUsedMoveWithEffect(enum BattlerId battler, enum BattleMoveEffects effect)
{
    u32 aiEffect = GetAIEffectGroup(effect);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (GetMoveEffect(gBattleHistory->usedMoves[battler][moveIndex]) == effect)
            return TRUE;

        if (aiEffect != AI_EFFECT_NONE)
        {
            if (GetAIEffectGroupFromMove(battler, gBattleHistory->usedMoves[battler][moveIndex]) & aiEffect)
                return TRUE;
        }

        if (HasPartnerIgnoreFlags(battler))
        {
            if (GetMoveEffect(gBattleHistory->usedMoves[GetPartnerBattler(battler)][moveIndex]) == effect)
                return TRUE;

            if (aiEffect != AI_EFFECT_NONE)
            {
                if (GetAIEffectGroupFromMove(battler, gBattleHistory->usedMoves[GetPartnerBattler(battler)][moveIndex]) & aiEffect)
                    return TRUE;
            }
        }
    }
    return FALSE;
}

bool32 HasNonVolatileMoveEffect(enum BattlerId battlerId, enum MoveEffect effect)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (GetMoveNonVolatileStatus(moves[moveIndex]) == effect)
            return TRUE;
    }

    return FALSE;
}

bool32 IsPowerBasedOnStatus(enum BattlerId battlerId, enum BattleMoveEffects effect, u32 argument)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE
            && GetMoveEffect(moves[moveIndex]) == effect
            && (GetMoveEffectArg_Status(moves[moveIndex]) & argument))
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithAdditionalEffect(enum BattlerId battlerId, enum MoveEffect moveEffect)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE
            && MoveHasAdditionalEffect(moves[moveIndex], moveEffect))
            return TRUE;
    }

    return FALSE;
}

bool32 HasBattlerSideMoveWithAdditionalEffect(enum BattlerId battler, enum MoveEffect moveEffect)
{
    if (HasMoveWithAdditionalEffect(battler, moveEffect))
        return TRUE;
    if (HasPartnerIgnoreFlags(battler) && HasMoveWithAdditionalEffect(GetPartnerBattler(battler), moveEffect))
        return TRUE;
    return FALSE;
}

bool32 HasMoveWithCriticalHitChance(enum BattlerId battlerId)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE
            && GetMoveCriticalHitStage(moves[moveIndex]) > 0)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithMoveEffectExcept(enum BattlerId battlerId, enum MoveEffect moveEffect, enum BattleMoveEffects exception)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE
            && GetMoveEffect(moves[moveIndex]) != exception
            && MoveHasAdditionalEffect(moves[moveIndex], moveEffect))
            return TRUE;
    }

    return FALSE;
}

bool32 HasMove(enum BattlerId battlerId, enum Move move)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && moves[moveIndex] == move)
            return TRUE;
    }

    return FALSE;
}

bool32 HasAnyKnownMove(enum BattlerId battlerId)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveThatLowersOwnStats(enum BattlerId battlerId)
{
    enum Move aiMove;
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        aiMove = moves[moveIndex];
        if (aiMove != MOVE_NONE && aiMove != MOVE_UNAVAILABLE)
        {
            u32 additionalEffectCount = GetMoveAdditionalEffectCount(aiMove);
            for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
            {
                const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(aiMove, effectIndex);
                if (additionalEffect->moveEffect == MOVE_EFFECT_STAT_MINUS && additionalEffect->self)
                    return TRUE;
            }
        }
    }
    return FALSE;
}

bool32 HasMoveThatRaisesOwnStats(enum BattlerId battlerId)
{
    enum Move aiMove;
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        aiMove = moves[moveIndex];
        if (aiMove != MOVE_NONE && aiMove != MOVE_UNAVAILABLE)
        {
            u32 additionalEffectCount = GetMoveAdditionalEffectCount(aiMove);
            for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
            {
                const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(aiMove, effectIndex);
                if (additionalEffect->moveEffect == MOVE_EFFECT_STAT_PLUS && additionalEffect->self)
                    return TRUE;
            }
        }
    }
    return FALSE;
}

bool32 HasMoveWithLowAccuracy(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 accCheck, bool32 ignoreStatus)
{
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = gAiLogicData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        if (ignoreStatus && IsBattleMoveStatus(moves[moveIndex]))
            continue;

        if (!IsBattleMoveStatus(moves[moveIndex]) && GetMoveAccuracy(moves[moveIndex]) == 0)
            continue;

        enum MoveTarget target = AI_GetBattlerMoveTargetType(battlerAtk, moves[moveIndex]);
        if (target == TARGET_USER || target == TARGET_OPPONENTS_FIELD)
            continue;

        if (gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveIndex] <= accCheck)
            return TRUE;
    }

    return FALSE;
}

bool32 HasSleepMoveWithLowAccuracy(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    enum Move *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = gAiLogicData->moveLimitations[battlerAtk];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        if (GetMoveNonVolatileStatus(moves[moveIndex]) == MOVE_EFFECT_SLEEP
        && gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveIndex] < 85)
            return TRUE;
    }
    return FALSE;
}

bool32 HasHealingEffect(enum BattlerId battlerId)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && IsHealingMove(moves[moveIndex]))
            return TRUE;
    }

    return FALSE;
}

bool32 IsTrappingMove(enum Move move)
{
    switch (GetMoveEffect(move))
    {
    case EFFECT_MEAN_LOOK:
    case EFFECT_FAIRY_LOCK:
    //case EFFECT_NO_RETREAT:   // TODO
        return TRUE;
    default:
        return MoveHasAdditionalEffect(move, MOVE_EFFECT_PREVENT_ESCAPE)
            || MoveHasAdditionalEffect(move, MOVE_EFFECT_WRAP);
    }
}

bool32 HasTrappingMoveEffect(enum BattlerId battler)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && IsTrappingMove(moves[moveIndex]))
            return TRUE;
    }

    return FALSE;
}

bool32 HasThawingMove(enum BattlerId battler)
{
    enum Move *moves = GetMovesArray(battler);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && MoveThawsUser(moves[moveIndex]))
            return TRUE;
    }
    return FALSE;
}

bool32 HasMoveUsableWhileAsleep(enum BattlerId battler)
{
    enum Move *moves = GetMovesArray(battler);
    u32 moveLimitations = gAiLogicData->moveLimitations[battler];
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;
        if (IsUsableWhileAsleepEffect(GetMoveEffect(moves[moveIndex])))
            return TRUE;
    }
    return FALSE;
}

bool32 IsStatRaisingMove(enum Move move)
{
    return GetMoveEffect(move) == EFFECT_ACUPRESSURE
        || MoveHasAdditionalEffect(move, STAT_CHANGE_EFFECT_PLUS);
}

bool32 IsStatLoweringMove(enum Move move)
{
    return MoveHasAdditionalEffect(move, STAT_CHANGE_EFFECT_MINUS);
}

bool32 IsSwitchOutEffect(enum BattleMoveEffects effect)
{
    // Switch out effects like U-Turn, Volt Switch, etc.
    switch (effect)
    {
    case EFFECT_TELEPORT:
        return (GetConfig(B_TELEPORT_BEHAVIOR) >= GEN_8);
    case EFFECT_HIT_ESCAPE:
    case EFFECT_PARTING_SHOT:
    case EFFECT_BATON_PASS:
    case EFFECT_WEATHER_AND_SWITCH:
    case EFFECT_SHED_TAIL:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsSelfSacrificeEffect(enum Move move)
{
    // All self sacrificing effects like Explosion, Final Gambit, Memento, etc.
    if (IsExplosionMove(move))
        return TRUE;

    switch (GetMoveEffect(move))
    {
    case EFFECT_FINAL_GAMBIT:
    case EFFECT_MEMENTO:
    case EFFECT_HEALING_WISH:
    case EFFECT_REVIVAL_BLESSING:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsRecoilDamageEffect(enum BattleMoveEffects effect)
{
    // All recoil effects that guarantee dealing self damage like Double Edge, Mind Blown, Chloroblast, etc.
    switch (effect)
    {
    case EFFECT_RECOIL:
    case EFFECT_MAX_HP_50_RECOIL:
    case EFFECT_CHLOROBLAST:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsChaseEffect(enum BattleMoveEffects effect)
{
    // Effects that hit switching out mons like Pursuit
    switch (effect)
    {
    case EFFECT_PURSUIT:
        return TRUE;
    default:
        return FALSE;
    }
}

static inline bool32 IsMoveSleepClauseTrigger(enum Move move)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);

    // Sleeping effects like Sleep Powder, Yawn, Dark Void, etc.
    switch (effect)
    {
    case EFFECT_YAWN:
    case EFFECT_DARK_VOID:
        return TRUE;
    default:
        break;
    }
    switch (GetMoveNonVolatileStatus(move))
    {
    case MOVE_EFFECT_SLEEP:
        return TRUE;
    default:
        break;
    }

    // Sleeping effects like G-Max Befuddle, G-Max Snooze, etc.
    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
        switch (additionalEffect->moveEffect)
        {
        // Skip MOVE_EFFECT_SLEEP as moves with a secondary chance of applying sleep are allowed by Smogon's rules (ie. Relic Song)
        case MOVE_EFFECT_EFFECT_SPORE_SIDE:
        case MOVE_EFFECT_YAWN_FOE:
            return TRUE;
        default:
            break;
        }
    }
    return FALSE;
}

bool32 HasDamagingMove(enum BattlerId battler)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetMovePower(moves[moveIndex]) > 0)
            return TRUE;
    }

    return FALSE;
}

bool32 HasDamagingMoveOfType(enum BattlerId battler, enum Type type)
{
    enum Move *moves = GetMovesArray(battler);
    struct AiLogicData *aiData = gAiLogicData;
    enum Ability ability = aiData->abilities[battler];
    enum HoldEffect holdEffect = aiData->holdEffects[battler];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && GetMovePower(moves[moveIndex]) > 0)
        {
            enum Type moveType = GetDynamicMoveType(GetBattlerMon(battler), moves[moveIndex], battler, ability, holdEffect, MON_IN_BATTLE);

            if (moveType != TYPE_NONE && type == moveType)
                return TRUE;
            if (GetMoveType(moves[moveIndex]) == type)
                return TRUE;
            if (GetMoveEffect(moves[moveIndex]) == EFFECT_NATURE_POWER && GetMoveType(GetNaturePowerMove()) == type)
                return TRUE;
        }
    }

    return FALSE;
}

bool32 HasMoveWithFlag(enum BattlerId battler, MoveFlag getFlag)
{
    enum Move *moves = GetMovesArray(battler);
    u32 moveLimitations = gAiLogicData->moveLimitations[battler];

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (IsMoveUnusable(moveIndex, moves[moveIndex], moveLimitations))
            continue;

        if (getFlag(moves[moveIndex]))
            return TRUE;
    }
    return FALSE;
}

// TODO: this and the function in moves resolution can be merged by changing some code a bit
// Is two turn move but not semi semi-invulnerable
bool32 IsTwoTurnNotSemiInvulnerableMove(enum BattlerId battlerAtk, enum Move move)
{
    switch (GetMoveEffect(move))
    {
    case EFFECT_SOLAR_BEAM:
    case EFFECT_TWO_TURNS_ATTACK:
    {
        u32 weather = AI_GetWeather();
        u32 attackerWeather = GetAttackerWeather(gAiLogicData->holdEffects[battlerAtk], gAiLogicData->abilities[battlerAtk], weather);

        enum BattleWeather moveAffectedByWeather = GetTwoTurnMoveWeather(move);
        enum BattleWeather weatherType = gBattleWeatherInfo[GetBattleWeather(weather)].type;
        enum BattleWeather attackerWeatherType = gBattleWeatherInfo[GetBattleWeather(attackerWeather)].type;

        bool32 isAffectedByWeather = ((attackerWeather != B_WEATHER_NONE)
                                   && ((weatherType == moveAffectedByWeather) || (attackerWeatherType == moveAffectedByWeather)));

        return !(isAffectedByWeather || gAiLogicData->holdEffects[battlerAtk] == HOLD_EFFECT_POWER_HERB);
    }
    default:
        return FALSE;
    }
}

static u32 GetLeechSeedDamage(enum BattlerId battler)
{
    u32 damage = 0;
    u32 leechSeeder = gBattleMons[battler].volatiles.leechSeed;
    if (leechSeeder && gBattleMons[leechSeeder - 1].hp != 0)
     {
        damage = GetNonDynamaxMaxHP(battler) / 8;
        if (damage == 0)
            damage = 1;
     }
     return damage;
}

static u32 GetNightmareDamage(enum BattlerId battlerId)
{
    u32 damage = 0;
    if (gBattleMons[battlerId].volatiles.nightmare
     && IsAsleepOrComatose(battlerId, gAiLogicData->abilities[battlerId]))
    {
        damage = GetNonDynamaxMaxHP(battlerId) / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetCurseDamage(enum BattlerId battlerId)
{
    u32 damage = 0;
    if (gBattleMons[battlerId].volatiles.cursed)
    {
        damage = GetNonDynamaxMaxHP(battlerId) / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetTrapDamage(enum BattlerId battler)
{
    // ai has no knowledge about turns remaining
    u32 damage = 0;
    if (gBattleMons[battler].volatiles.wrapped)
    {
        if (gBattleMons[battler].volatiles.wrappedBindingBand)
            damage = GetNonDynamaxMaxHP(battler) / (B_BINDING_DAMAGE >= GEN_6 ? 6 : 8);
        else
            damage = GetNonDynamaxMaxHP(battler) / (B_BINDING_DAMAGE >= GEN_6 ? 8 : 16);

        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetPoisonDamage(enum BattlerId battlerId)
{
    u32 damage = 0;

    if (gAiLogicData->abilities[battlerId] == ABILITY_POISON_HEAL)
        return damage;

    if (gBattleMons[battlerId].status1 & STATUS1_POISON)
    {
        damage = gBattleMons[battlerId].maxHP / 8;
        if (damage == 0)
            damage = 1;
    }
    else if (gBattleMons[battlerId].status1 & STATUS1_TOXIC_POISON)
    {
        u32 status1Temp = gBattleMons[battlerId].status1;
        damage = gBattleMons[battlerId].maxHP / 16;
        if (damage == 0)
            damage = 1;
        if ((status1Temp & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
            status1Temp += STATUS1_TOXIC_TURN(1);
        damage *= (status1Temp & STATUS1_TOXIC_COUNTER) >> 8;
    }
    return damage;
}

static bool32 DoesBattlerTakeSandstormDamage(enum BattlerId battlerId, enum Ability ability)
{
    if (!(AI_GetWeather() & B_WEATHER_SANDSTORM))
        return FALSE;

    if (!IS_BATTLER_ANY_TYPE(battlerId, TYPE_ROCK, TYPE_GROUND, TYPE_STEEL)
      && ability != ABILITY_SAND_VEIL
      && ability != ABILITY_SAND_FORCE
      && ability != ABILITY_SAND_RUSH
      && ability != ABILITY_MAGIC_GUARD
      && ability != ABILITY_OVERCOAT)
        return TRUE;
    return FALSE;
}

static bool32 DoesBattlerTakeHailDamage(enum BattlerId battlerId, enum Ability ability)
{
    if (!(AI_GetWeather() & B_WEATHER_HAIL))
        return FALSE;

    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      && ability != ABILITY_SNOW_CLOAK
      && ability != ABILITY_ICE_BODY
      && ability != ABILITY_MAGIC_GUARD
      && ability != ABILITY_OVERCOAT)
        return TRUE;
    return FALSE;
}

static u32 GetWeatherDamage(enum BattlerId battlerId)
{
    enum Ability ability = gAiLogicData->abilities[battlerId];
    enum HoldEffect holdEffect = gAiLogicData->holdEffects[battlerId];
    u32 damage = 0;
    u32 weather = AI_GetWeather();
    if (!weather)
        return 0;

    if (weather & B_WEATHER_SANDSTORM)
    {
        if (DoesBattlerTakeSandstormDamage(battlerId, ability)
          && gBattleMons[battlerId].volatiles.semiInvulnerable != STATE_UNDERGROUND
          && gBattleMons[battlerId].volatiles.semiInvulnerable != STATE_UNDERWATER
          && holdEffect != HOLD_EFFECT_SAFETY_GOGGLES)
        {
            damage = GetNonDynamaxMaxHP(battlerId) / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    if ((weather & B_WEATHER_HAIL) && ability != ABILITY_ICE_BODY)
    {
        if (DoesBattlerTakeHailDamage(battlerId, ability)
          && gBattleMons[battlerId].volatiles.semiInvulnerable != STATE_UNDERGROUND
          && gBattleMons[battlerId].volatiles.semiInvulnerable != STATE_UNDERWATER
          && holdEffect != HOLD_EFFECT_SAFETY_GOGGLES)
        {
            damage = GetNonDynamaxMaxHP(battlerId) / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    return damage;
}

u32 GetBattlerSecondaryDamage(enum BattlerId battlerId)
{
    u32 secondaryDamage;

    if (gAiLogicData->abilities[battlerId] == ABILITY_MAGIC_GUARD)
        return FALSE;

    secondaryDamage = GetLeechSeedDamage(battlerId)
     + GetNightmareDamage(battlerId)
     + GetCurseDamage(battlerId)
     + GetTrapDamage(battlerId)
     + GetPoisonDamage(battlerId)
     + GetWeatherDamage(battlerId);

    return secondaryDamage;
}

bool32 BattlerWillFaintFromWeather(enum BattlerId battler, enum Ability ability)
{
    if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_SAFETY_GOGGLES)
        return FALSE;

    if ((DoesBattlerTakeSandstormDamage(battler, ability) || DoesBattlerTakeHailDamage(battler, ability))
      && gBattleMons[battler].hp <= max(1, GetNonDynamaxMaxHP(battler) / 16))
        return TRUE;

    return FALSE;
}

bool32 BattlerWillFaintFromSecondaryDamage(enum BattlerId battler, enum Ability ability)
{
    u32 secondaryDamage = GetBattlerSecondaryDamage(battler);

    if (secondaryDamage != 0
      && gBattleMons[battler].hp <= secondaryDamage)
        return TRUE;
    return FALSE;
}

bool32 AnyUsefulStatIsRaised(enum BattlerId battler)
{
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battler].statStages[statId] > DEFAULT_STAT_STAGE)
        {
            switch (statId)
            {
            case STAT_ATK:
                if (HasMoveWithCategory(battler, DAMAGE_CATEGORY_PHYSICAL))
                    return TRUE;
                break;
            case STAT_SPATK:
                if (HasMoveWithCategory(battler, DAMAGE_CATEGORY_SPECIAL))
                    return TRUE;
                break;
            case STAT_SPEED:
                return TRUE;
            default:
                break;
            }
        }
    }

    return FALSE;
}

bool32 BattlerHasMaxHPProtection(enum BattlerId battler)
{
    enum Ability ability = gAiLogicData->abilities[battler];
    if (!AI_BattlerAtMaxHp(battler))
        return FALSE;
    if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_FOCUS_SASH)
        return TRUE;
    if (GetConfig(B_STURDY) >= GEN_5 && ability == ABILITY_STURDY)
        return TRUE;
    if (ability == ABILITY_MULTISCALE || ability == ABILITY_SHADOW_SHIELD)
        return TRUE;
    return FALSE;
}

enum AIPivot ShouldPivot(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY);
    bool32 hasGoodSwitchin = gAiLogicData->mostSuitableMonId[battlerAtk] >= PARTY_SIZE ? FALSE : TRUE;
    // If AI should switch, it should pivot
    if (aiIsFaster)
    {
        if (gAiLogicData->shouldSwitch & (1u << battlerAtk))
            return SHOULD_PIVOT;
    }
    else
    {
        if (gAiLogicData->shouldSwitch & (1u << battlerAtk) && !CanTargetFaintAi(battlerDef, battlerAtk))
            return SHOULD_PIVOT;
    }
    // Break Focus Sash / Multiscale effects if a good switchin exists
    if (!IsBattleMoveStatus(move) && BattlerHasMaxHPProtection(battlerDef) && hasGoodSwitchin && RandomPercentage(RNG_AI_SHOULD_PIVOT_BREAK_SASH, SHOULD_PIVOT_BREAK_SASH_CHANCE))
        return SHOULD_PIVOT;
    // Would benefit from Regenerator and have a good switchin
    if (gAiLogicData->abilities[battlerAtk] == ABILITY_REGENERATOR && ShouldRecover(battlerAtk, battlerDef, move, 33) && hasGoodSwitchin)
        return SHOULD_PIVOT;
    // Palafin always wants to activate Zero to Hero via pivoting when able
    if (gAiLogicData->abilities[battlerAtk] == ABILITY_ZERO_TO_HERO && gBattleMons[battlerAtk].species == SPECIES_PALAFIN_ZERO && CountUsablePartyMons(battlerAtk) != 0)
        return SHOULD_PIVOT;
    // If no good switchin candidate and can't KO to change the situation, not good to pivot
    if (GetNoOfHitsToKOBattler(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, CONSIDER_ENDURE) && !hasGoodSwitchin)
        return DONT_PIVOT;
    // Otherwise, neutral effect
    return CAN_TRY_PIVOT;
}

#define BATTLE_TYPE_CANT_KNOCK_OFF (BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK \
                                  | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_SECRET_BASE \
                                  | (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? BATTLE_TYPE_TRAINER : 0))
bool32 CanKnockOffItem(enum BattlerId fromBattler, enum BattlerId battler, enum Item item)
{
    if (item == ITEM_NONE)
        return FALSE;

    if (!(gBattleTypeFlags & BATTLE_TYPE_CANT_KNOCK_OFF) && IsOnPlayerSide(fromBattler))
        return FALSE;

    if (gAiLogicData->abilities[fromBattler] == ABILITY_STICKY_HOLD)
        return FALSE;

    if (!CanBattlerGetOrLoseItem(fromBattler, battler, item))
        return FALSE;

    return TRUE;
}
#undef BATTLE_TYPE_CANT_KNOCK_OFF

// status checks
bool32 IsBattlerIncapacitated(enum BattlerId battler, enum Ability ability)
{
    if ((gBattleMons[battler].status1 & STATUS1_FREEZE) && !HasThawingMove(battler))
        return TRUE;    // if battler has thawing move we assume they will definitely use it, and thus being frozen should be neglected

    if (gBattleMons[battler].status1 & STATUS1_SLEEP && !HasMoveUsableWhileAsleep(battler))
        return TRUE;

    if (gBattleMons[battler].volatiles.rechargeTimer > 0 || (ability == ABILITY_TRUANT && gBattleMons[battler].volatiles.truantCounter != 0))
        return TRUE;

    return FALSE;
}

bool32 AI_CanPutToSleep(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove)
{
    if (!CanBeSlept(battlerAtk, battlerDef, defAbility, BLOCKED_BY_SLEEP_CLAUSE)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(GetPartnerBattler(battlerAtk), battlerDef, partnerMove))   // shouldn't try to sleep mon that partner is trying to make sleep
        return FALSE;
    return TRUE;
}

static inline bool32 DoesBattlerBenefitFromAllVolatileStatus(enum BattlerId battler, enum Ability ability)
{
    if (ability == ABILITY_MARVEL_SCALE
     || ability == ABILITY_QUICK_FEET
     || ability == ABILITY_MAGIC_GUARD
     || (ability == ABILITY_GUTS && HasMoveWithCategory(battler, DAMAGE_CATEGORY_PHYSICAL))
     || HasMoveWithEffect(battler, EFFECT_FACADE)
     || HasMoveWithEffect(battler, EFFECT_PSYCHO_SHIFT))
        return TRUE;
    return FALSE;
}

bool32 ShouldPoison(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    enum Ability abilityDef = gAiLogicData->abilities[battlerDef];
    // Battler can be poisoned and has move/ability that synergizes with being poisoned
    if (CanBePoisoned(battlerAtk, battlerDef, gAiLogicData->abilities[battlerAtk], abilityDef) && (
        DoesBattlerBenefitFromAllVolatileStatus(battlerDef, abilityDef)
        || abilityDef == ABILITY_POISON_HEAL
        || (abilityDef == ABILITY_TOXIC_BOOST && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))))
    {
        if (battlerAtk == battlerDef) // Targeting self
            return TRUE;
        else
            return FALSE;
    }
    if (battlerAtk == battlerDef)
        return FALSE;
    else
        return TRUE;
}

bool32 ShouldBurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    // Battler can be burned and has move/ability that synergizes with being burned
    if (CanBeBurned(battlerAtk, battlerDef, abilityDef) && (
        DoesBattlerBenefitFromAllVolatileStatus(battlerDef, abilityDef)
        || abilityDef == ABILITY_HEATPROOF
        || (abilityDef == ABILITY_FLARE_BOOST && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))))
    {
        if (battlerAtk == battlerDef) // Targeting self
            return TRUE;
        else
            return FALSE;
    }

    if (battlerAtk == battlerDef)
        return FALSE;
    else
        return TRUE;
}

bool32 ShouldFreezeOrFrostbite(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    if (!B_USE_FROSTBITE)
    {
        if (CanBeFrozen(battlerAtk, battlerDef, abilityDef))
        {
            if (battlerAtk == battlerDef) // Targeting self
                return FALSE;
            else
                return TRUE;
        }
        return FALSE;
    }
    else
    {
        // Battler can be frostbitten and has move/ability that synergizes with being frostbitten
        if (CanBeFrozen(battlerAtk, battlerDef, abilityDef)
            && DoesBattlerBenefitFromAllVolatileStatus(battlerDef, abilityDef))
        {
            if (battlerAtk == battlerDef) // Targeting self
                return TRUE;
            else
                return FALSE;
        }

        if (battlerAtk == battlerDef)
            return FALSE;
        else
            return TRUE;
    }
}

bool32 ShouldParalyze(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    // Battler can be paralyzed and has move/ability that synergizes with being paralyzed
    if (CanBeParalyzed(battlerAtk, battlerDef, abilityDef) && (
        DoesBattlerBenefitFromAllVolatileStatus(battlerDef, abilityDef)))
    {
        if (battlerAtk == battlerDef) // Targeting self
            return TRUE;
        else
            return FALSE;
    }
    if (battlerAtk == battlerDef)
        return FALSE;
    else
        return TRUE;
}

bool32 AI_CanPoison(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove)
{
    if (!CanBePoisoned(battlerAtk, battlerDef, gAiLogicData->abilities[battlerAtk], defAbility)
      || gAiLogicData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] == UQ_4_12(0.0)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(GetPartnerBattler(battlerAtk), battlerDef, partnerMove))
        return FALSE;

    return TRUE;
}

bool32 AI_CanParalyze(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum Move move, enum Move partnerMove)
{
    if (!CanBeParalyzed(battlerAtk, battlerDef, defAbility)
      || gAiLogicData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] == UQ_4_12(0.0)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(GetPartnerBattler(battlerAtk), battlerDef, partnerMove))
        return FALSE;
    return TRUE;
}

bool32 AI_CanBeConfused(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum Ability abilityDef)
{
    if (gBattleMons[battlerDef].volatiles.confusionTimer > 0
     || (abilityDef == ABILITY_OWN_TEMPO && !DoesBattlerIgnoreAbilityChecks(battlerAtk, gAiLogicData->abilities[battlerAtk], move))
     || IsMistyTerrainAffected(battlerDef, abilityDef, gAiLogicData->holdEffects[battlerDef], gFieldTimers.terrain)
     || IsSafeguardProtected(battlerAtk, battlerDef, gAiLogicData->abilities[battlerAtk])
     || DoesSubstituteBlockMove(battlerAtk, battlerDef, move))
        return FALSE;
    return TRUE;
}

bool32 AI_CanConfuse(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove)
{
    if (AI_GetBattlerMoveTargetType(battlerAtk, move) == TARGET_FOES_AND_ALLY
     && AI_CanBeConfused(battlerAtk, battlerDef, move, defAbility)
     && !AI_CanBeConfused(battlerAtk, GetPartnerBattler(battlerDef), move, gAiLogicData->abilities[GetPartnerBattler(battlerDef)]))
        return FALSE;

    if (!AI_CanBeConfused(battlerAtk, battlerDef, move, defAbility)
     || DoesPartnerHaveSameMoveEffect(battlerAtkPartner, battlerDef, move, partnerMove))
        return FALSE;

    return TRUE;
}

bool32 AI_CanBurn(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove)
{
    if (!CanBeBurned(battlerAtk, battlerDef, defAbility)
      || gAiLogicData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] == UQ_4_12(0.0)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(battlerAtkPartner, battlerDef, partnerMove))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 AI_CanGiveFrostbite(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove)
{
    if (!CanBeFrozen(battlerAtk, battlerDef, defAbility)
      || gAiLogicData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] == UQ_4_12(0.0)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(battlerAtkPartner, battlerDef, partnerMove))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 AI_CanBeInfatuated(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability defAbility)
{
    if (gBattleMons[battlerDef].volatiles.infatuation
      || gAiLogicData->effectiveness[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex] == UQ_4_12(0.0)
      || defAbility == ABILITY_OBLIVIOUS
      || !AreBattlersOfOppositeGender(battlerAtk, battlerDef)
      || AI_IsAbilityOnSide(battlerDef, ABILITY_AROMA_VEIL))
        return FALSE;
    return TRUE;
}

bool32 ShouldTryToFlinch(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability atkAbility, enum Ability defAbility, enum Move move)
{
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    if (((!IsMoldBreakerTypeAbility(battlerAtk, gAiLogicData->abilities[battlerAtk], move) && (defAbility == ABILITY_SHIELD_DUST || defAbility == ABILITY_INNER_FOCUS))
      || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_COVERT_CLOAK
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))) // Opponent goes first
    {
        return FALSE;
    }
    else if ((atkAbility == ABILITY_SERENE_GRACE
      || gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS
      || gBattleMons[battlerDef].volatiles.infatuation
      || gBattleMons[battlerDef].volatiles.confusionTimer > 0)
      || ((AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY)) && CanTargetFaintAi(battlerDef, battlerAtk)))
    {
        return TRUE;   // good idea to flinch
    }

    return FALSE;   // don't try to flinch
}

bool32 ShouldTrap(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum AIConsiderWrapDamage considerWrapDamage)
{
    bool32 shouldTrap = FALSE;
    bool32 wrapState = gBattleMons[battlerDef].volatiles.wrapped;

    if (AI_CanBattlerEscape(battlerDef))
        return FALSE;

    if (IsBattlerTrapped(battlerAtk, battlerDef))
        return FALSE;

    // Consider Wrap Damage when trying to trap with Wrap
    if (considerWrapDamage == CONSIDER_WRAP_DAMAGE)
        gBattleMons[battlerDef].volatiles.wrapped = TRUE;

    if (BattlerWillFaintFromSecondaryDamage(battlerDef, gAiLogicData->abilities[battlerDef]))
        shouldTrap = TRUE;    // battler is taking secondary damage with low HP

    gBattleMons[battlerDef].volatiles.wrapped = wrapState;

    if (shouldTrap)
        return TRUE;

    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_STALL)
    {
        if (!CanTargetFaintAi(battlerDef, battlerAtk))
            return TRUE;    // attacker goes first and opponent can't kill us
    }

    return FALSE;
}

bool32 IsFlinchGuaranteed(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    if (!MoveHasAdditionalEffect(move, MOVE_EFFECT_FLINCH))
        return FALSE;

    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    if (AI_IsSlower(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY))
        return FALSE;

    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    // check move additional effects that are likely to happen
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, effectIndex);
        // Only consider effects with a guaranteed chance to happen
        if (!MoveEffectIsGuaranteed(battlerAtk, gAiLogicData->abilities[battlerAtk], additionalEffect))
            continue;

        if (additionalEffect->moveEffect == MOVE_EFFECT_FLINCH)
        {
            if (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_COVERT_CLOAK
            || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
            || (!IsMoldBreakerTypeAbility(battlerAtk, gAiLogicData->abilities[battlerAtk], move)
            && (gAiLogicData->abilities[battlerDef] == ABILITY_SHIELD_DUST || gAiLogicData->abilities[battlerDef] == ABILITY_INNER_FOCUS)))
                return FALSE;
            else
                return TRUE;
        }
    }
    return FALSE;
}

bool32 HasChoiceEffect(enum BattlerId battler)
{
    enum Ability ability = gAiLogicData->abilities[battler];
    if (ability == ABILITY_GORILLA_TACTICS)
        return TRUE;

    if (ability == ABILITY_KLUTZ)
        return FALSE;

    enum HoldEffect holdEffect = gAiLogicData->holdEffects[battler];
    switch (holdEffect)
    {
    case HOLD_EFFECT_CHOICE_BAND:
    case HOLD_EFFECT_CHOICE_SCARF:
    case HOLD_EFFECT_CHOICE_SPECS:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsWakeupTurn(enum BattlerId battler)
{
    u32 sleepTurns = gBattleMons[battler].status1 & STATUS1_SLEEP;
    u32 toSub;

    if (sleepTurns == 0)
        return FALSE;

    // Early Bird reduces the sleep timer twice as fast.
    if (gAiLogicData->abilities[battler] == ABILITY_EARLY_BIRD)
        toSub = 2;
    else
        toSub = 1;

    return sleepTurns <= toSub;
}

bool32 AnyPartyMemberStatused(enum BattlerId battlerId, bool32 checkSoundproof)
{
    struct Pokemon *party;
    u32 battlerOnField1, battlerOnField2;
    bool32 hasStatusToCure = FALSE;

    party = GetBattlerParty(battlerId);

    if (HasPartner(battlerId))
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[GetPartnerBattler(battlerId)];
        // Check partner's status
        if ((GetConfig(B_HEAL_BELL_SOUNDPROOF) == GEN_5
            || gAiLogicData->abilities[GetPartnerBattler(battlerId)] != ABILITY_SOUNDPROOF
            || !checkSoundproof)
         && GetMonData(&party[battlerOnField2], MON_DATA_STATUS) != STATUS1_NONE
         && ShouldCureStatus(battlerId, GetPartnerBattler(battlerId), gAiLogicData))
            hasStatusToCure = TRUE;
    }
    else // In singles there's only one battlerId by side.
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[battlerId];
    }

    // Check attacker's status
    if ((GetConfig(B_HEAL_BELL_SOUNDPROOF) == GEN_5
      || GetConfig(B_HEAL_BELL_SOUNDPROOF) >= GEN_8
      || gAiLogicData->abilities[battlerId] != ABILITY_SOUNDPROOF || !checkSoundproof)
     && GetMonData(&party[battlerOnField1], MON_DATA_STATUS) != STATUS1_NONE
     && ShouldCureStatus(battlerId, battlerId, gAiLogicData))
        hasStatusToCure = TRUE;

    // Check inactive party mons' status
    for (u32 monIndex = 0; monIndex < PARTY_SIZE; monIndex++)
    {
        if (monIndex == battlerOnField1 || monIndex == battlerOnField2)
            continue;
        if (GetConfig(B_HEAL_BELL_SOUNDPROOF) < GEN_5
         && checkSoundproof
         && GetMonAbility(&party[monIndex]) == ABILITY_SOUNDPROOF)
            continue;
        if (GetMonData(&party[monIndex], MON_DATA_STATUS) != STATUS1_NONE)
            return TRUE;
    }

    return hasStatusToCure;
}

static inline bool32 RecoveryEnablesWinning1v1(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, bool32 aiIsFaster, u32 healAmount)
{
    if (aiIsFaster)
    {
        if (CanTargetFaintAi(battlerDef, battlerAtk)
          && !CanTargetFaintAiWithMod(battlerDef, battlerAtk, healAmount, 0))
            return TRUE;    // target can faint attacker unless they heal
        else if (!CanTargetFaintAi(battlerDef, battlerAtk) && gAiLogicData->hpPercents[battlerAtk] < ENABLE_RECOVERY_THRESHOLD && RandomPercentage(RNG_AI_SHOULD_RECOVER, SHOULD_RECOVER_CHANCE))
            return TRUE;    // target can't faint attacker at all, generally safe
    }
    else
    {
        if (!CanTargetFaintAi(battlerDef, battlerAtk)
          && GetBestDmgFromBattler(battlerDef, battlerAtk, AI_DEFENDING) < healAmount
          && NoOfHitsForTargetToFaintBattler(battlerDef, battlerAtk, AI_DEFENDING, CONSIDER_ENDURE) < NoOfHitsForTargetToFaintBattlerWithMod(battlerDef, battlerAtk, healAmount))
            return TRUE;    // target can't faint attacker and is dealing less damage than we're healing
        else if (!CanTargetFaintAi(battlerDef, battlerAtk) && gAiLogicData->hpPercents[battlerAtk] < ENABLE_RECOVERY_THRESHOLD && RandomPercentage(RNG_AI_SHOULD_RECOVER, SHOULD_RECOVER_CHANCE))
            return TRUE;    // target can't faint attacker at all, generally safe
    }
    return FALSE;
}

static inline bool32 ShouldDrainHPToWithstandHit(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 currHP, u32 healAmount)
{
    s32 bestDamageFromPlayer = GetBestDmgFromBattler(battlerDef, battlerAtk, AI_DEFENDING);

    if (bestDamageFromPlayer >= GetNonDynamaxMaxHP(battlerAtk) + healAmount)
        return FALSE;

    if (bestDamageFromPlayer >= currHP && currHP + healAmount > bestDamageFromPlayer)
        return TRUE;

    return FALSE;
}

bool32 ShouldAbsorb(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, u32 absorbPercentage)
{
    u32 maxHP = gBattleMons[battlerAtk].maxHP;
    u32 currHP = gBattleMons[battlerAtk].hp;
    u32 healAmount = (AI_GetDamage(battlerAtk, battlerDef, gAiThinkingStruct->movesetIndex, AI_ATTACKING, gAiLogicData) * absorbPercentage / 100);
    healAmount = GetDrainedBigRootHp(battlerAtk, healAmount);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY);

    if (healAmount == 0)
        healAmount = 1;
    if (healAmount + currHP > maxHP)
        healAmount = maxHP - currHP;
    if (gBattleMons[battlerAtk].volatiles.healBlockTimer)
        healAmount = 0;

    if (gAiLogicData->abilities[battlerDef] == ABILITY_LIQUID_OOZE)
        return FALSE;
    if (IsBattlerAtMaxHp(battlerAtk) && (aiIsFaster || GetMoveCategory(GetIncomingMove(battlerAtk, battlerDef, gAiLogicData)) == DAMAGE_CATEGORY_STATUS))
        return FALSE;
    if (RecoveryEnablesWinning1v1(battlerAtk, battlerDef, move, aiIsFaster, healAmount))
        return TRUE;
    if (ShouldDrainHPToWithstandHit(battlerAtk, battlerDef, currHP, healAmount))
        return TRUE;

    return FALSE;
}

bool32 ShouldRecover(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, u32 healPercent)
{
    u32 maxHP = gBattleMons[battlerAtk].maxHP;
    u32 currHP = gBattleMons[battlerAtk].hp;
    u32 healAmount = (healPercent * maxHP) / 100;
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, CONSIDER_PRIORITY);
    if (healAmount + currHP > maxHP)
        healAmount = maxHP - currHP;
    if (gBattleMons[battlerAtk].volatiles.healBlockTimer)
        healAmount = 0;

    if (IsBattlerAtMaxHp(battlerAtk))
        return FALSE;
    if (RecoveryEnablesWinning1v1(battlerAtk, battlerDef, move, aiIsFaster, healAmount))
        return TRUE;
    return FALSE;
}

bool32 ShouldSetScreen(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum BattleMoveEffects moveEffect)
{
    enum BattleSide atkSide = GetBattlerSide(battlerAtk);

    // Don't waste a turn if screens will be broken
    if (HasMoveWithAIEffect(battlerDef, AI_EFFECT_BREAK_SCREENS))
        return FALSE;

    switch (moveEffect)
    {
    case EFFECT_AURORA_VEIL:
        // Use only in Hail and only if AI doesn't already have Reflect, Light Screen or Aurora Veil itself active.
        if ((AI_GetWeather() & (B_WEATHER_ICY_ANY))
            && !(gSideStatuses[atkSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)))
            return TRUE;
        break;
    case EFFECT_REFLECT:
        // Use only if the player has a physical move and AI doesn't already have Reflect itself active.
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL)
            && !(gSideStatuses[atkSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_AURORA_VEIL)))
            return TRUE;
        break;
    case EFFECT_LIGHT_SCREEN:
        // Use only if the player has a special move and AI doesn't already have Light Screen itself active.
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL)
            && !(gSideStatuses[atkSide] & (SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)))
            return TRUE;
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 ShouldCureStatusInternal(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 usingItem, struct AiLogicData *aiData)
{
    bool32 targetingSelf = (battlerAtk == battlerDef);
    bool32 targetingAlly = IsTargetingPartner(battlerAtk, battlerDef);
    u32 status = gBattleMons[battlerDef].status1;

    if (status & STATUS1_SLEEP)
    {
        if (targetingAlly || targetingSelf)
        {
            if (HasMoveUsableWhileAsleep(battlerDef))
                return FALSE;
            else
                return usingItem || targetingAlly;
        }
        return FALSE;
    }

    if (status & STATUS1_FREEZE)
    {
        if (targetingAlly || targetingSelf)
        {
            if (HasThawingMove(battlerDef))
                return FALSE;
            return usingItem || targetingAlly;
        }
        return FALSE;
    }

    bool32 isHarmless = FALSE;

    if (DoesBattlerBenefitFromAllVolatileStatus(battlerDef, aiData->abilities[battlerDef]))
        isHarmless = TRUE;

    if (status & STATUS1_PSN_ANY)
    {
        if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_TOXIC_ORB)
            return FALSE;

        if (aiData->abilities[battlerDef] == ABILITY_POISON_HEAL)
            isHarmless = TRUE;

        if (aiData->abilities[battlerDef] == ABILITY_TOXIC_BOOST && !isHarmless)
        {
            if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                isHarmless = TRUE;
            else if (!(targetingSelf || targetingAlly) && !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
                isHarmless = TRUE;
        }
    }

    if (status & STATUS1_BURN)
    {
        if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_FLAME_ORB)
            return FALSE;

        if (aiData->abilities[battlerDef] == ABILITY_FLARE_BOOST && !isHarmless)
        {
            if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL))
                isHarmless = TRUE;
            else if (!(targetingSelf || targetingAlly) && !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                isHarmless = TRUE;
        }
    }

/*
    if (status & STATUS1_PARALYSIS)
    if (status & STATUS1_FROSTBITE)
*/

    if (isHarmless)
    {
        if (targetingSelf || targetingAlly)
            return FALSE;
        else
            return TRUE;
    }
    else
    {
        if (targetingSelf || targetingAlly)
            return TRUE;
        else
            return FALSE;
    }
}

bool32 ShouldCureStatus(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData)
{
    return ShouldCureStatusInternal(battlerAtk, battlerDef, FALSE, aiData);
}

bool32 ShouldCureStatusWithItem(enum BattlerId battlerAtk, enum BattlerId battlerDef, struct AiLogicData *aiData)
{
    return ShouldCureStatusInternal(battlerAtk, battlerDef, TRUE, aiData);
}

// Partner Logic
bool32 IsBattle1v1(void)
{
    if (IsDoubleBattle()
      && ((IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)) && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)))
      || (IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)) && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)))))
        return FALSE;
    return TRUE;
}

bool32 HasTwoOpponents(enum BattlerId battler)
{
    if (IsDoubleBattle()
      && IsBattlerAlive(GetBattlerLeftFoe(battler)) && IsBattlerAlive(GetBattlerRightFoe(battler)))
        return TRUE;
    return FALSE;
}

bool32 HasPartner(enum BattlerId battler)
{
    if (IsDoubleBattle() && IsBattlerAlive(GetPartnerBattler(battler)))
    {
        if (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_ATTACKS_PARTNER)
            return FALSE;
        else
            return TRUE;
    }
    return FALSE;
}

bool32 HasPartnerIgnoreFlags(enum BattlerId battler)
{
    if (IsDoubleBattle() && IsBattlerAlive(GetPartnerBattler(battler)))
    {
        return TRUE;
    }
    return FALSE;
}

bool32 IsTargetingPartner(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_ATTACKS_PARTNER)
        return FALSE;
    return ((battlerAtk) == (battlerDef ^ BIT_FLANK));
}

bool32 AreMovesEquivalent(enum BattlerId battlerAtk, enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove)
{
    if (!IsBattlerAlive(battlerAtkPartner) || partnerMove == MOVE_NONE)
        return FALSE;

    enum BattlerId battlerDef = gBattleStruct->moveTarget[battlerAtk];

    // We don't care the effect is basically the same; we would use this move anyway.
    if (IsBestDmgMove(battlerAtk, battlerDef, AI_ATTACKING, move))
        return FALSE;

    u32 atkEffect = GetAIEffectGroupFromMove(battlerAtk, move);
    u32 partnerEffect = GetAIEffectGroupFromMove(battlerAtkPartner, partnerMove);

    // shared bits indicate they're meaningfully the same in some way
    if (atkEffect & partnerEffect)
    {
        if (GetMoveTarget(move) == TARGET_SELECTED && GetMoveTarget(partnerMove) == TARGET_SELECTED)
        {
            if (battlerDef == gBattleStruct->moveTarget[battlerAtkPartner])
                return TRUE;
            else
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

static u32 GetAIEffectGroup(enum BattleMoveEffects effect)
{
    u32 aiEffect = AI_EFFECT_NONE;

    switch (effect)
    {
    case EFFECT_WEATHER:
    case EFFECT_WEATHER_AND_SWITCH:
        aiEffect |= AI_EFFECT_WEATHER;
        break;
    case EFFECT_TERRAIN:
    case EFFECT_STEEL_ROLLER:
    case EFFECT_ICE_SPINNER:
        aiEffect |= AI_EFFECT_TERRAIN;
        break;
    case EFFECT_COURT_CHANGE:
        aiEffect |= AI_EFFECT_CLEAR_HAZARDS | AI_EFFECT_AURORA_VEIL | AI_EFFECT_BREAK_SCREENS;
        break;
    case EFFECT_DEFOG:
        aiEffect |= AI_EFFECT_CLEAR_HAZARDS | AI_EFFECT_BREAK_SCREENS;
        break;
    case EFFECT_RAPID_SPIN:
    case EFFECT_TIDY_UP:
        aiEffect |= AI_EFFECT_CLEAR_HAZARDS;
        break;
    case EFFECT_HAZE:
        aiEffect |= AI_EFFECT_RESET_STATS;
        break;
    case EFFECT_HIT_SWITCH_TARGET:
    case EFFECT_ROAR:
        aiEffect |= AI_EFFECT_FORCE_SWITCH;
        break;
    case EFFECT_TORMENT:
        aiEffect |= AI_EFFECT_TORMENT;
        break;
    case EFFECT_AURORA_VEIL:
        aiEffect |= AI_EFFECT_AURORA_VEIL;
        break;
    case EFFECT_LIGHT_SCREEN:
        aiEffect |= AI_EFFECT_LIGHT_SCREEN;
        break;
    case EFFECT_REFLECT:
        aiEffect |= AI_EFFECT_REFLECT;
        break;
    case EFFECT_GRAVITY:
        aiEffect |= AI_EFFECT_GRAVITY;
        break;
    case EFFECT_DOODLE:
    case EFFECT_ENTRAINMENT:
    case EFFECT_GASTRO_ACID:
    case EFFECT_ROLE_PLAY:
    case EFFECT_SKILL_SWAP:
    case EFFECT_OVERWRITE_ABILITY:
        aiEffect |= AI_EFFECT_CHANGE_ABILITY;
        break;
    default:
        break;
    }

    return aiEffect;
}

static u32 GetAIEffectGroupFromMove(enum BattlerId battler, enum Move move)
{
    u32 aiEffect = GetAIEffectGroup(GetMoveEffect(move));

    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
    {
        switch (GetMoveAdditionalEffectById(move, effectIndex)->moveEffect)
        {
        case MOVE_EFFECT_SUN:
        case MOVE_EFFECT_RAIN:
        case MOVE_EFFECT_SANDSTORM:
        case MOVE_EFFECT_HAIL:
            aiEffect |= AI_EFFECT_WEATHER;
            break;
        case MOVE_EFFECT_ELECTRIC_TERRAIN:
        case MOVE_EFFECT_GRASSY_TERRAIN:
        case MOVE_EFFECT_MISTY_TERRAIN:
        case MOVE_EFFECT_PSYCHIC_TERRAIN:
            aiEffect |= AI_EFFECT_TERRAIN;
            break;
        case MOVE_EFFECT_DEFOG:
            aiEffect |= AI_EFFECT_CLEAR_HAZARDS | AI_EFFECT_BREAK_SCREENS;
            break;
        case MOVE_EFFECT_CLEAR_SMOG:
        case MOVE_EFFECT_HAZE:
            aiEffect |= AI_EFFECT_RESET_STATS;
            break;
        case MOVE_EFFECT_TORMENT_SIDE:
            aiEffect |= AI_EFFECT_TORMENT;
            break;
        case MOVE_EFFECT_LIGHT_SCREEN:
            aiEffect |= AI_EFFECT_LIGHT_SCREEN;
            break;
        case MOVE_EFFECT_REFLECT:
            aiEffect |= AI_EFFECT_REFLECT;
            break;
        case MOVE_EFFECT_AURORA_VEIL:
            aiEffect |= AI_EFFECT_AURORA_VEIL;
            break;
        case MOVE_EFFECT_GRAVITY:
            aiEffect |= AI_EFFECT_GRAVITY;
            break;
        case MOVE_EFFECT_BREAK_SCREEN:
            aiEffect |= AI_EFFECT_BREAK_SCREENS;
            break;
        default:
            break;
        }
    }

    return aiEffect;
}

// It matches both on move effect and on AI move effect; eg, EFFECT_HAZE will also bring up Freezy Frost or Clear Smog, anything with AI_EFFECT_RESET_STATS.
bool32 DoesPartnerHaveSameMoveEffect(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move move, enum Move partnerMove)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;

    if (GetMoveEffect(move) == GetMoveEffect(partnerMove)
      && partnerMove != MOVE_NONE)
    {
        if (GetMoveTarget(move) == TARGET_SELECTED && GetMoveTarget(partnerMove) == TARGET_SELECTED)
        {
            return gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef;
        }
        return TRUE;
    }
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_STATUS_SAME_TARGET
bool32 PartnerMoveEffectIsStatusSameTarget(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move partnerMove)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;

    enum BattleMoveEffects partnerEffect = GetMoveEffect(partnerMove);
    enum MoveEffect nonVolatileStatus = GetMoveNonVolatileStatus(partnerMove);
    if (partnerMove != MOVE_NONE
     && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef
     && (nonVolatileStatus == MOVE_EFFECT_POISON
       || nonVolatileStatus == MOVE_EFFECT_TOXIC
       || nonVolatileStatus == MOVE_EFFECT_SLEEP
       || nonVolatileStatus == MOVE_EFFECT_PARALYSIS
       || nonVolatileStatus == MOVE_EFFECT_BURN
       || partnerEffect == EFFECT_YAWN))
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS
bool32 PartnerMoveEffectIs(enum BattlerId battlerAtkPartner, enum Move partnerMove, enum BattleMoveEffects effectCheck)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;

    if (partnerMove != MOVE_NONE && GetMoveEffect(partnerMove) == effectCheck)
        return TRUE;

    return FALSE;
}

//PARTNER_MOVE_IS_TAILWIND_TRICKROOM
bool32 PartnerMoveIs(enum BattlerId battlerAtkPartner, enum Move partnerMove, enum Move moveCheck)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;

    if (partnerMove != MOVE_NONE && partnerMove == moveCheck)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME
bool32 PartnerMoveIsSameAsAttacker(enum BattlerId battlerAtkPartner, enum BattlerId battlerDef, enum Move move, enum Move partnerMove)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;

    if (partnerMove != MOVE_NONE && move == partnerMove && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME_NO_TARGET
bool32 PartnerMoveIsSameNoTarget(enum BattlerId battlerAtkPartner, enum Move move, enum Move partnerMove)
{
    if (!HasPartner(battlerAtkPartner))
        return FALSE;
    if (partnerMove != MOVE_NONE && move == partnerMove)
        return TRUE;
    return FALSE;
}

bool32 PartnerMoveActivatesSleepClause(enum Move partnerMove)
{
    if (IsBattle1v1() || !IsSleepClauseEnabled())
        return FALSE;
    return IsMoveSleepClauseTrigger(partnerMove);
}

bool32 ShouldUseWishAromatherapy(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    s32 lastId = GetAILastPartyIndex(battlerAtk); // + 1
    struct Pokemon *party;
    bool32 hasStatus = AnyPartyMemberStatused(battlerAtk, IsSoundMove(move));
    bool32 needHealing = FALSE;

    party = GetBattlerParty(battlerAtk);

    if (CountUsablePartyMons(battlerAtk) == 0
      && (CanTargetFaintAi(battlerDef, battlerAtk) || BattlerWillFaintFromSecondaryDamage(battlerAtk, gAiLogicData->abilities[battlerAtk])))
        return FALSE; // Don't heal if last mon and will faint

    for (u32 monIndex = 0; monIndex < PARTY_SIZE; monIndex++)
    {
        u32 currHp = GetMonData(&party[monIndex], MON_DATA_HP);
        u32 maxHp = GetMonData(&party[monIndex], MON_DATA_MAX_HP);

        if (!GetMonData(&party[monIndex], MON_DATA_IS_EGG) && currHp > 0)
        {
            if ((currHp * 100) / maxHp < 65 // Less than 65% health remaining
              && monIndex >= 0 && monIndex < lastId) // Can only switch to mon on your team
            {
                needHealing = TRUE;
            }
        }
    }

    if (IsBattle1v1())
    {
        switch (GetMoveEffect(move))
        {
        case EFFECT_WISH:
            if (needHealing)
                return TRUE;
            break;
        case EFFECT_HEAL_BELL:
            if (hasStatus)
                return TRUE;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (GetMoveEffect(move))
        {
        case EFFECT_WISH:
            return ShouldRecover(battlerAtk, battlerDef, move, 50); // Switch recovery isn't good idea in doubles
        case EFFECT_HEAL_BELL:
            if (hasStatus)
                return TRUE;
            break;
        default:
            break;
        }
    }

    return FALSE;
}

#define SIZE_G_BATTLE_MONS (sizeof(struct BattlePokemon) * MAX_BATTLERS_COUNT)

struct BattlePokemon *AllocSaveBattleMons(void)
{
    struct BattlePokemon *savedBattleMons = Alloc(SIZE_G_BATTLE_MONS);
    memcpy(savedBattleMons, gBattleMons, SIZE_G_BATTLE_MONS);
    return savedBattleMons;
}

void FreeRestoreBattleMons(struct BattlePokemon *savedBattleMons)
{
    memcpy(gBattleMons, savedBattleMons, SIZE_G_BATTLE_MONS);
    Free(savedBattleMons);
}

#define SIZE_G_AI_LOGIC_DATA (sizeof(struct AiLogicData))

struct AiLogicData *AllocSaveAiLogicData(void)
{
    struct AiLogicData *savedAiLogicData = Alloc(SIZE_G_AI_LOGIC_DATA);
    memcpy(savedAiLogicData, gAiLogicData, SIZE_G_AI_LOGIC_DATA);
    return savedAiLogicData;
}

void FreeRestoreAiLogicData(struct AiLogicData *savedAiLogicData)
{
    memcpy(gAiLogicData, savedAiLogicData, SIZE_G_AI_LOGIC_DATA);
    Free(savedAiLogicData);
}

// party logic
s32 CountUsablePartyMons(enum BattlerId battlerId)
{
    s32 battlerOnField1, battlerOnField2, ret;
    struct Pokemon *party;
    party = GetBattlerParty(battlerId);

    if (IsDoubleBattle())
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[GetPartnerBattler(battlerId)];
    }
    else // In singles there's only one battlerId by side.
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[battlerId];
    }

    ret = 0;
    s32 lastId = GetAILastPartyIndex(battlerId); // + 1
    for (u32 monIndex = 0; monIndex < lastId; monIndex++)
    {
        if (monIndex != battlerOnField1 && monIndex != battlerOnField2
         && GetMonData(&party[monIndex], MON_DATA_HP) != 0
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            ret++;
        }
    }

    return ret;
}

s32 CountUsableSideMons(enum BattlerId battlerId)
{
    if (BattleSideHasTwoTrainers(GetBattlerSide(battlerId)))
        return (CountUsablePartyMons(battlerId) + CountUsablePartyMons(GetPartnerBattler(battlerId)));
    else
        return CountUsablePartyMons(battlerId);
}

bool32 IsPartyFullyHealedExceptBattler(enum BattlerId battlerId)
{
    struct Pokemon *party = GetBattlerParty(battlerId);

    for (u32 monIndex = 0; monIndex < PARTY_SIZE; monIndex++)
    {
        if (monIndex != gBattlerPartyIndexes[battlerId]
         && GetMonData(&party[monIndex], MON_DATA_HP) != 0
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
         && GetMonData(&party[monIndex], MON_DATA_HP) < GetMonData(&party[monIndex], MON_DATA_MAX_HP))
            return FALSE;
    }
    return TRUE;
}

bool32 IsAbilityOfRating(enum Ability ability, s32 rating)
{
    if (gAbilitiesInfo[ability].aiRating >= rating)
        return TRUE;
    return FALSE;
}

static const enum Item sRecycleEncouragedItems[] =
{
    ITEM_CHESTO_BERRY,
    ITEM_LUM_BERRY,
    ITEM_STARF_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_MICLE_BERRY,
    ITEM_CUSTAP_BERRY,
    ITEM_MENTAL_HERB,
    ITEM_FOCUS_SASH,
    ITEM_SALAC_BERRY,
    ITEM_LIECHI_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_IAPAPA_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MENTAL_HERB,
    ITEM_POWER_HERB,
    ITEM_BERRY_JUICE,
    ITEM_WEAKNESS_POLICY,
    ITEM_BLUNDER_POLICY,
    ITEM_KEE_BERRY,
    ITEM_MARANGA_BERRY,
    // TODO expand this
};

// Its assumed that the berry is strategically given, so no need to check benefits of the berry
bool32 IsStatBoostingBerry(enum Item item)
{
    switch (item)
    {
    case ITEM_LIECHI_BERRY:
    case ITEM_GANLON_BERRY:
    case ITEM_SALAC_BERRY:
    case ITEM_PETAYA_BERRY:
    case ITEM_APICOT_BERRY:
    //case ITEM_LANSAT_BERRY:
    case ITEM_STARF_BERRY:
    case ITEM_MICLE_BERRY:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 ShouldRestoreHpBerry(enum BattlerId battlerAtk, enum Item item)
{
    switch (item)
    {
    case ITEM_ORAN_BERRY:
        if (gBattleMons[battlerAtk].maxHP <= 50)
            return TRUE;    // Only worth it in the early game
        return FALSE;
    case ITEM_SITRUS_BERRY:
    case ITEM_FIGY_BERRY:
    case ITEM_WIKI_BERRY:
    case ITEM_MAGO_BERRY:
    case ITEM_AGUAV_BERRY:
    case ITEM_IAPAPA_BERRY:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsRecycleEncouragedItem(enum Item item)
{
    for (u32 recycleIndex = 0; recycleIndex < ARRAY_COUNT(sRecycleEncouragedItems); recycleIndex++)
    {
        if (item == sRecycleEncouragedItems[recycleIndex])
            return TRUE;
    }
    return FALSE;
}

static bool32 HasMoveThatChangesKOThreshold(enum BattlerId battlerId, u32 noOfHitsToFaint)
{
    enum Move *moves = GetMovesArray(battlerId);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] == MOVE_NONE || moves[moveIndex] == MOVE_UNAVAILABLE)
            continue;
        if (noOfHitsToFaint <= 2)
        {
            if (GetMovePriority(moves[moveIndex]) > 0)
                return TRUE;

            u32 additionalEffectCount = GetMoveAdditionalEffectCount(moves[moveIndex]);
            for (u32 effectIndex = 0; effectIndex < additionalEffectCount; effectIndex++)
            {
                const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(moves[moveIndex], effectIndex);
                switch (additionalEffect->moveEffect)
                {
                case MOVE_EFFECT_STAT_MINUS:
                {
                    if (additionalEffect->speed && !additionalEffect->self)
                        return TRUE;
                }
                default:
                    break;
                }
            }
        }
    }

    return FALSE;
}

static enum AIScore IncreaseStatUpScoreInternal(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat statId, s32 stages, bool32 considerContrary)
{
    enum AIScore tempScore = NO_INCREASE;
    u32 noOfHitsToFaint = NoOfHitsForTargetToFaintBattler(battlerDef, battlerAtk, AI_SHOULD_SETUP_DEFENDING, DONT_CONSIDER_ENDURE);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    bool32 aiIsFaster = AI_IsFaster(battlerAtk, battlerDef, MOVE_NONE, predictedMove, DONT_CONSIDER_PRIORITY); // Don't care about the priority of our setup move, care about outspeeding otherwise
    bool32 shouldSetUp = ((noOfHitsToFaint >= 2 && aiIsFaster) || (noOfHitsToFaint >= 3 && !aiIsFaster) || noOfHitsToFaint == UNKNOWN_NO_OF_HITS);

    // This should be now redundant
    if (considerContrary && gAiLogicData->abilities[battlerAtk] == ABILITY_CONTRARY)
        return NO_INCREASE;

    if (!ShouldRaiseAnyStat(battlerAtk, battlerDef))
        return NO_INCREASE;

    // Don't increase stat if AI has less then 70% HP and number of hits isn't known
    if (gAiLogicData->hpPercents[battlerAtk] < 70 && noOfHitsToFaint == UNKNOWN_NO_OF_HITS)
        return NO_INCREASE;

    // Don't increase stats if player has a move that can change the KO threshold
    if (aiIsFaster && HasMoveThatChangesKOThreshold(battlerDef, noOfHitsToFaint))
        return NO_INCREASE;

    // Don't increase stat if AI is at +4
    if (gBattleMons[battlerAtk].statStages[statId] >= MAX_STAT_STAGE - 2)
        return NO_INCREASE;

    // Stat stages are effectively doubled under Simple.
    if (gAiLogicData->abilities[battlerAtk] == ABILITY_SIMPLE)
        stages *= 2;

    // Predicting switch
    if (IsBattlerPredictedToSwitch(battlerDef))
    {
        struct Pokemon *playerParty = GetBattlerParty(battlerDef);
        // If expected switchin outspeeds and has Encore, don't increase
        for (u32 monIndex = 0; monIndex < MAX_MON_MOVES; monIndex++)
        {
            if (GetMoveEffect(GetMonData(&playerParty[gAiLogicData->mostSuitableMonId[battlerDef]], MON_DATA_MOVE1 + monIndex)) == EFFECT_ENCORE
                && GetMonData(&playerParty[gAiLogicData->mostSuitableMonId[battlerDef]], MON_DATA_PP1 + monIndex) > 0)
            {
                if (GetMonData(&playerParty[gAiLogicData->mostSuitableMonId[battlerDef]], MON_DATA_SPEED) > gBattleMons[battlerAtk].speed)
                    return NO_INCREASE;
            }
        }
        // Otherwise if predicting switch, stat increases are great momentum
        tempScore += WEAK_EFFECT;
    }

    switch (statId)
    {
    case STAT_ATK:
        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL) && shouldSetUp)
        {
            if (stages == 1)
                tempScore += DECENT_EFFECT;
            else if (stages == 6)
                tempScore += BEST_EFFECT;
            else
                tempScore += GOOD_EFFECT;
        }
        break;
    case STAT_DEF:
    {
        bool32 defRelevant = (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL) || !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL));
        bool32 bodyPressCheck = (HasMoveWithEffect(battlerAtk, EFFECT_BODY_PRESS) && !(gFieldStatuses & STATUS_FIELD_WONDER_ROOM) && shouldSetUp);

        if (defRelevant || bodyPressCheck)
        {
            if (defRelevant && (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_STALL))
                tempScore += WEAK_EFFECT;
            if (stages == 1)
                tempScore += bodyPressCheck ? DECENT_EFFECT : WEAK_EFFECT;
            else
                tempScore += bodyPressCheck ? GOOD_EFFECT : DECENT_EFFECT;
        }
        break;
    }
    case STAT_SPEED:
        if ((noOfHitsToFaint >= 3 && !aiIsFaster) || noOfHitsToFaint == UNKNOWN_NO_OF_HITS)
        {
            if (stages == 1)
                tempScore += DECENT_EFFECT;
            else
                tempScore += GOOD_EFFECT;
        }
        break;
    case STAT_SPATK:
        if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL) && shouldSetUp)
        {
            if (stages == 1)
                tempScore += DECENT_EFFECT;
            else
                tempScore += GOOD_EFFECT;
        }
        break;
    case STAT_SPDEF:
    {
        bool32 spDefRelevant = (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL) || !HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL));
        // Wonder Room makes Body Press use Sp. Def stages for its damage calculation.
        bool32 bodyPressCheck = (HasMoveWithEffect(battlerAtk, EFFECT_BODY_PRESS) && (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) && shouldSetUp);

        if (spDefRelevant || bodyPressCheck)
        {
            if (spDefRelevant && (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_STALL))
                tempScore += WEAK_EFFECT;
            if (stages == 1)
                tempScore += bodyPressCheck ? DECENT_EFFECT : WEAK_EFFECT;
            else
                tempScore += bodyPressCheck ? GOOD_EFFECT : DECENT_EFFECT;
        }
        break;
    }
    case STAT_ACC:
        if (gBattleMons[battlerAtk].statStages[statId] <= DEFAULT_STAT_STAGE - 3) // Increase only if necessary
            tempScore += DECENT_EFFECT;
        break;
    case STAT_EVASION:
        if (noOfHitsToFaint > 3 || noOfHitsToFaint == UNKNOWN_NO_OF_HITS)
            tempScore += GOOD_EFFECT;
        else
            tempScore += DECENT_EFFECT;
        break;
    default:
        break;
    }

    // if already inclined to boost, be slightly more likely to if boost levels matter
    if (tempScore > 0 && HasMoveWithEffect(battlerAtk, EFFECT_STORED_POWER))
        tempScore += WEAK_EFFECT;

    return tempScore;
}

bool32 HasHPForDamagingSetup(enum BattlerId battlerAtk, enum BattlerId battlerDef, u32 hpThreshold)
{
    bool32 bestMoveIsPhysical = HasPhysicalBestMove(battlerDef, battlerAtk, AI_DEFENDING);

    if (GetBestDmgFromBattler(battlerDef, battlerAtk, AI_DEFENDING) < ((hpThreshold * gBattleMons[battlerAtk].maxHP) / 100))
        return TRUE;

    if (bestMoveIsPhysical
     && gAiLogicData->abilities[battlerAtk] == ABILITY_ICE_FACE
     && gBattleMons[battlerAtk].species == SPECIES_EISCUE_ICE
     && !IsMoldBreakerTypeAbility(battlerDef, gAiLogicData->abilities[battlerDef], MOVE_NONE)) // ice face will absorb the hit, safe to use setup
        return TRUE;

    if (gAiLogicData->abilities[battlerAtk] == ABILITY_DISGUISE
     && IsMimikyuDisguised(battlerAtk)
     && !IsMoldBreakerTypeAbility(battlerDef, gAiLogicData->abilities[battlerDef], MOVE_NONE)) // disguise will absorb the hit, safe to use setup
        return TRUE;

    return FALSE;
}

enum AIScore IncreaseStatUpScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat, s32 stage)
{
    return IncreaseStatUpScoreInternal(battlerAtk, battlerDef, stat, stage, TRUE);
}

enum AIScore IncreaseStatUpScoreContrary(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat, s32 stage)
{
    return IncreaseStatUpScoreInternal(battlerAtk, battlerDef, stat, stage, FALSE);
}

void IncreasePoisonScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
            || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_PSN || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanPoison(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], move, gAiLogicData->partnerMove) && gAiLogicData->hpPercents[battlerDef] > 20)
    {
        if (!HasDamagingMove(battlerDef))
            ADJUST_SCORE_PTR(DECENT_EFFECT);

        if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_STALL && HasMoveWithEffect(battlerAtk, EFFECT_PROTECT))
            ADJUST_SCORE_PTR(WEAK_EFFECT);    // stall tactic

        if (IsPowerBasedOnStatus(battlerAtk, EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_PSN_ANY)
         || HasMoveWithEffect(battlerAtk, EFFECT_STAT_CHANGE_ON_STATUS)
         || gAiLogicData->abilities[battlerAtk] == ABILITY_MERCILESS)
            ADJUST_SCORE_PTR(DECENT_EFFECT);
        else
            ADJUST_SCORE_PTR(WEAK_EFFECT);
    }
}

void IncreaseBurnScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
            || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_BRN || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanBurn(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, gAiLogicData->partnerMove))
    {
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL)
            || (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_OMNISCIENT) // Not Omniscient but expects physical attacker
                && GetSpeciesBaseAttack(gBattleMons[battlerDef].species) >= GetSpeciesBaseSpAttack(gBattleMons[battlerDef].species) + 10))
        {
            enum Move defBestMoves[MAX_MON_MOVES] = {MOVE_NONE};
            bool32 hasPhysical = FALSE;

            GetBestDmgMovesFromBattler(battlerAtk, battlerDef, AI_DEFENDING, defBestMoves);

            for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            {
                if (defBestMoves[moveIndex] == MOVE_NONE)
                    break;

                if (GetMoveCategory(defBestMoves[moveIndex]) == DAMAGE_CATEGORY_PHYSICAL)
                {
                    hasPhysical = TRUE;
                    break;
                }
            }

            if (hasPhysical)
                ADJUST_SCORE_PTR(DECENT_EFFECT);
            else
                ADJUST_SCORE_PTR(WEAK_EFFECT);
        }

        if (IsPowerBasedOnStatus(battlerAtk, EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_BURN)
          || IsPowerBasedOnStatus(GetPartnerBattler(battlerAtk), EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_BURN))
            ADJUST_SCORE_PTR(WEAK_EFFECT);
    }
}

void IncreaseParalyzeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
            || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_PAR || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanParalyze(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], move, gAiLogicData->partnerMove))
    {
        u32 atkSpeed = gAiLogicData->speedStats[battlerAtk];
        u32 defSpeed = gAiLogicData->speedStats[battlerDef];

        if ((defSpeed >= atkSpeed && defSpeed / 2 < atkSpeed) // You'll go first after paralyzing foe
          || IsPowerBasedOnStatus(battlerAtk, EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_PARALYSIS)
          || (HasMoveWithMoveEffectExcept(battlerAtk, MOVE_EFFECT_FLINCH, EFFECT_FIRST_TURN_ONLY)) // filter out Fake Out
          || gBattleMons[battlerDef].volatiles.infatuation
          || gBattleMons[battlerDef].volatiles.confusionTimer > 0)
            ADJUST_SCORE_PTR(GOOD_EFFECT);
        else
            ADJUST_SCORE_PTR(DECENT_EFFECT);
    }
}

void IncreaseSleepScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_SLP || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0)))
    {
        enum Move bestMoves[MAX_MON_MOVES] = {MOVE_NONE};

        GetBestDmgMovesFromBattler(battlerAtk, battlerDef, AI_ATTACKING, bestMoves);

        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if ((GetMoveEffect(bestMoves[moveIndex]) != EFFECT_FOCUS_PUNCH) && (bestMoves[moveIndex] != MOVE_NONE))
                return;
        }
    }

    if (AI_CanPutToSleep(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], move, gAiLogicData->partnerMove))
        ADJUST_SCORE_PTR(DECENT_EFFECT);
    else
        return;

    if ((HasMoveWithEffect(battlerAtk, EFFECT_DREAM_EATER) || HasMoveWithEffect(battlerAtk, EFFECT_NIGHTMARE))
      && !HasMoveUsableWhileAsleep(battlerDef))
        ADJUST_SCORE_PTR(WEAK_EFFECT);

    if (IsPowerBasedOnStatus(battlerAtk, EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_SLEEP)
      || IsPowerBasedOnStatus(GetPartnerBattler(battlerAtk), EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_SLEEP))
        ADJUST_SCORE_PTR(WEAK_EFFECT);
}

void IncreaseConfusionScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
            || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_CONFUSION || gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanConfuse(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, gAiLogicData->partnerMove)
      && gAiLogicData->holdEffects[battlerDef] != HOLD_EFFECT_CURE_CONFUSION
      && gAiLogicData->holdEffects[battlerDef] != HOLD_EFFECT_CURE_STATUS)
    {
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS
          || gBattleMons[battlerDef].volatiles.infatuation
          || (gAiLogicData->abilities[battlerAtk] == ABILITY_SERENE_GRACE && HasMoveWithMoveEffectExcept(battlerAtk, MOVE_EFFECT_FLINCH, EFFECT_FIRST_TURN_ONLY)))
            ADJUST_SCORE_PTR(GOOD_EFFECT);
        else
            ADJUST_SCORE_PTR(DECENT_EFFECT);
    }
}

void IncreaseFrostbiteScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if ((gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return;

    if (AI_CanGiveFrostbite(battlerAtk, battlerDef, gAiLogicData->abilities[battlerDef], GetPartnerBattler(battlerAtk), move, gAiLogicData->partnerMove))
    {
        if (HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL)
            || (!(gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_OMNISCIENT) // Not Omniscient but expects special attacker
                && GetSpeciesBaseSpAttack(gBattleMons[battlerDef].species) >= GetSpeciesBaseAttack(gBattleMons[battlerDef].species) + 10))
        {
            enum Move defBestMoves[MAX_MON_MOVES] = {MOVE_NONE};
            bool32 hasSpecial = FALSE;

            GetBestDmgMovesFromBattler(battlerAtk, battlerDef, AI_DEFENDING, defBestMoves);

            for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            {
                if (defBestMoves[moveIndex] == MOVE_NONE)
                    break;

                if (GetMoveCategory(defBestMoves[moveIndex]) == DAMAGE_CATEGORY_SPECIAL)
                {
                    hasSpecial = TRUE;
                    break;
                }
            }

            if (hasSpecial)
                ADJUST_SCORE_PTR(DECENT_EFFECT);
            else
                ADJUST_SCORE_PTR(WEAK_EFFECT);
        }

        if (IsPowerBasedOnStatus(battlerAtk, EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_FROSTBITE)
          || IsPowerBasedOnStatus(GetPartnerBattler(battlerAtk), EFFECT_DOUBLE_POWER_ON_ARG_STATUS, STATUS1_FROSTBITE))
            ADJUST_SCORE_PTR(WEAK_EFFECT);
    }
}

bool32 AI_MoveMakesContact(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability ability, enum HoldEffect holdEffect, enum Move move)
{
    if (GetMoveEffect(move) == EFFECT_SHELL_SIDE_ARM)
    {
        if (gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] != DAMAGE_CATEGORY_PHYSICAL)
            return FALSE;
    }
    else if (!MoveMakesContact(move))
    {
        return FALSE;
    }

    if (ability == ABILITY_LONG_REACH)
        return FALSE;
    if (holdEffect == HOLD_EFFECT_PROTECTIVE_PADS)
        return FALSE;
    if (holdEffect == HOLD_EFFECT_PUNCHING_GLOVE && IsPunchingMove(move))
        return FALSE;
    return TRUE;
}

bool32 AI_CanContactBypassProtect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    if (move == MOVE_NONE || move == MOVE_UNAVAILABLE)
        return FALSE;
    if (gAiLogicData->abilities[battlerAtk] != ABILITY_UNSEEN_FIST && gAiLogicData->abilities[battlerAtk] != ABILITY_PIERCING_DRILL)
        return FALSE;
    if (GetMoveEffect(move) == EFFECT_SHELL_SIDE_ARM)
    {
        if (gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] != DAMAGE_CATEGORY_PHYSICAL)
            return FALSE;
    }
    else if (!MoveMakesContact(move))
    {
        return FALSE;
    }

    if (gAiLogicData->holdEffects[battlerAtk] == HOLD_EFFECT_PUNCHING_GLOVE && IsPunchingMove(move))
        return FALSE;

    return TRUE;
}


bool32 IsConsideringZMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    if (GetMovePower(move) == 0 && GetMoveZEffect(move) == Z_EFFECT_NONE)
        return FALSE;

    return gBattleStruct->gimmick.usableGimmick[battlerAtk] == GIMMICK_Z_MOVE && ShouldUseZMove(battlerAtk, battlerDef, move);
}

//TODO - this could use some more sophisticated logic
bool32 ShouldUseZMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move chosenMove)
{
    // simple logic. just upgrades chosen move to z move if possible, unless regular move would kill opponent
    enum MoveTarget target = AI_GetBattlerMoveTargetType(battlerAtk, chosenMove);
    if ((IsDoubleBattle()) && battlerDef == GetPartnerBattler(battlerAtk) && target != TARGET_ALLY && target != TARGET_USER_OR_ALLY)
        return FALSE;   // don't use z move on partner
    if (HasTrainerUsedGimmick(battlerAtk, GIMMICK_Z_MOVE))
        return FALSE;   // can't use z move twice

    if (IsViableZMove(battlerAtk, chosenMove))
    {
        enum BattleMoveEffects baseEffect = GetMoveEffect(chosenMove);
        bool32 isEager = FALSE; // more likely to use a z move than typical

        enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
        bool32 isSlower = AI_IsSlower(battlerAtk, battlerDef, chosenMove, predictedMove, CONSIDER_PRIORITY);

        switch (baseEffect)
        {
        case EFFECT_STAT_CHANGE_HALF_HP:
        case EFFECT_BELLY_DRUM:
            if (isSlower)
                return TRUE;
            isEager = TRUE;
            break;
        case EFFECT_PROTECT:
            if (HasDamagingMoveOfType(battlerAtk, GetMoveType(chosenMove)))
                return FALSE;
            else
                isEager = TRUE;
            break;
        case EFFECT_TELEPORT:
            isEager = TRUE;
            break;
        case EFFECT_TRANSFORM:
            if (IsBattlerTrapped(battlerDef, battlerAtk) && !HasDamagingMoveOfType(battlerDef, GetMoveType(chosenMove)))
                return TRUE;
            if (isSlower)
                isEager = TRUE;
            break;
        default:
            break;
        }

        enum Move zMove = GetUsableZMove(battlerAtk, chosenMove);

        if (IsBattleMoveStatus(chosenMove))
        {
            enum ZEffect zEffect = GetMoveZEffect(chosenMove);
            enum Stat stat = STAT_HP;
            s32 stage = 0;

            if (zEffect == Z_EFFECT_CURSE)
            {
                if (IS_BATTLER_OF_TYPE(battlerAtk, TYPE_GHOST))
                    zEffect = Z_EFFECT_RECOVER_HP;
                else
                    zEffect = Z_EFFECT_ATK_UP_1;
            }

            switch (zEffect)
            {
            case Z_EFFECT_NONE:
                if (GetMovePower(chosenMove) == 0)
                    return FALSE;
                break;
            case Z_EFFECT_RESET_STATS:
                if (CountNegativeStatStages(battlerAtk) > 1)
                    return TRUE;
                break;
            case Z_EFFECT_ALL_STATS_UP_1:
                return ShouldRaiseAnyStat(battlerAtk, battlerDef);
            case Z_EFFECT_BOOST_CRITS:
                return TRUE;
            case Z_EFFECT_FOLLOW_ME:
                return HasPartnerIgnoreFlags(battlerAtk) && (GetHealthPercentage(battlerAtk) <= Z_EFFECT_FOLLOW_ME_THRESHOLD || GetBestNoOfHitsToKO(battlerDef, battlerAtk, AI_DEFENDING) == 1);
                break;
            case Z_EFFECT_RECOVER_HP:
                if (GetBestNoOfHitsToKO(battlerDef, battlerAtk, AI_DEFENDING) == 1 && GetHealthPercentage(battlerAtk) > Z_EFFECT_RESTORE_HP_HIGHER_THRESHOLD)
                    return TRUE;
                if (isEager)
                    return GetHealthPercentage(battlerAtk) <= Z_EFFECT_RESTORE_HP_HIGHER_THRESHOLD;
                return GetHealthPercentage(battlerAtk) <= Z_EFFECT_RESTORE_HP_LOWER_THRESHOLD;
            case Z_EFFECT_RESTORE_REPLACEMENT_HP:
                break;
            case Z_EFFECT_ACC_UP_1:
            case Z_EFFECT_ACC_UP_2:
            case Z_EFFECT_ACC_UP_3:
                stat = STAT_ACC;
                stage = zEffect - Z_EFFECT_ACC_UP_1 + 1;
                break;
            case Z_EFFECT_EVSN_UP_1:
            case Z_EFFECT_EVSN_UP_2:
            case Z_EFFECT_EVSN_UP_3:
                stat = STAT_EVASION;
                stage = zEffect - Z_EFFECT_EVSN_UP_1 + 1;
                break;
            case Z_EFFECT_ATK_UP_1:
            case Z_EFFECT_ATK_UP_2:
            case Z_EFFECT_ATK_UP_3:
                stat = STAT_ATK;
                stage = zEffect - Z_EFFECT_ATK_UP_1 + 1;
                break;
            case Z_EFFECT_DEF_UP_1:
            case Z_EFFECT_DEF_UP_2:
            case Z_EFFECT_DEF_UP_3:
                stat = STAT_DEF;
                stage = zEffect - Z_EFFECT_DEF_UP_1 + 1;
                break;
            case Z_EFFECT_SPD_UP_1:
            case Z_EFFECT_SPD_UP_2:
            case Z_EFFECT_SPD_UP_3:
                stat = STAT_SPEED;
                stage = zEffect - Z_EFFECT_SPD_UP_1 + 1;
                break;
            case Z_EFFECT_SPATK_UP_1:
            case Z_EFFECT_SPATK_UP_2:
            case Z_EFFECT_SPATK_UP_3:
                stat = STAT_SPATK;
                stage = zEffect - Z_EFFECT_SPATK_UP_1 + 1;
                break;
            case Z_EFFECT_SPDEF_UP_1:
            case Z_EFFECT_SPDEF_UP_2:
            case Z_EFFECT_SPDEF_UP_3:
                stat = STAT_SPDEF;
                stage = zEffect - Z_EFFECT_SPDEF_UP_1 + 1;
                break;
            default:
                return FALSE;
            }

            if (stat != STAT_HP && (isEager || IncreaseStatUpScoreContrary(battlerAtk, battlerDef, stat, stage) > 0))
                return TRUE;

        }
        else if (GetMoveEffect(zMove) == EFFECT_EXTREME_EVOBOOST)
        {
            return gAiLogicData->abilities[battlerAtk] != ABILITY_CONTRARY && ShouldRaiseAnyStat(battlerAtk, battlerDef);
        }
        else if (!IsBattleMoveStatus(chosenMove) && IsBattleMoveStatus(zMove))
        {
            return FALSE;
        }

        if (GetMoveEffect(chosenMove) == EFFECT_LAST_RESORT && !CanUseLastResort(battlerAtk))
            return TRUE;

        uq4_12_t effectiveness;
        struct SimulatedDamage dmg;

        if (gBattleMons[battlerDef].ability == ABILITY_DISGUISE
            && !MoveIgnoresTargetAbility(zMove)
            && IsMimikyuDisguised(battlerDef))
            return FALSE; // Don't waste a Z-Move busting disguise
        if (gBattleMons[battlerDef].ability == ABILITY_ICE_FACE
            && !MoveIgnoresTargetAbility(zMove)
            && gBattleMons[battlerDef].species == SPECIES_EISCUE_ICE && IsBattleMovePhysical(chosenMove))
            return FALSE; // Don't waste a Z-Move busting Ice Face

        dmg = AI_CalcDamageSaveBattlers(chosenMove, battlerAtk, battlerDef, &effectiveness, GIMMICK_NONE, GIMMICK_NONE);

        // don't waste a damaging z move if the normal move will KO
        if (!IsBattleMoveStatus(chosenMove) && dmg.minimum >= gBattleMons[battlerDef].hp)
        {
            // Risky AI skips accuracy check.
            if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_RISKY)
                return FALSE;

            u32 acc = gAiLogicData->moveAccuracy[battlerAtk][battlerDef][gAiThinkingStruct->movesetIndex];

            if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_CONSERVATIVE)
                return (acc < 100);

            return acc < LOW_ACCURACY_THRESHOLD;
        }

        return TRUE;
    }

    return FALSE;
}

void SetAIUsingGimmick(enum BattlerId battler, enum AIConsiderGimmick use)
{
    if (use == USE_GIMMICK)
        gAiBattleData->aiUsingGimmick |= (1<<battler);
    else
        gAiBattleData->aiUsingGimmick &= ~(1<<battler);
}

struct AltTeraCalcs
{
    struct SimulatedDamage takenWithTera[MAX_MON_MOVES];
    struct SimulatedDamage dealtWithoutTera[MAX_MON_MOVES];
};

enum AIConsiderGimmick ShouldTeraFromCalcs(enum BattlerId battler, enum BattlerId opposingBattler, struct AltTeraCalcs *altCalcs);

void DecideTerastal(enum BattlerId battler)
{
    if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_TERA)
        return;

    if (!(gAiThinkingStruct->aiFlags[battler] & AI_FLAG_SMART_TERA))
        return;

    // TODO: Currently only single battles are considered.
    if (!IsBattle1v1())
        return;

    // TODO: A lot of these checks are most effective for an omnicient ai.
    // If we don't have enough information about the opponent's moves, consider simpler checks based on type effectivness.

    enum BattlerId opposingBattler = GetOppositeBattler(battler);

    // Default calculations automatically assume gimmicks for the attacker, but not the defender.
    // Consider calcs for the other possibilities.
    struct AltTeraCalcs altCalcs;

    struct SimulatedDamage noDmg = {0};

    uq4_12_t effectivenessTakenWithTera[MAX_MON_MOVES];

    enum Move *aiMoves = GetMovesArray(battler);
    enum Move *oppMoves = GetMovesArray(opposingBattler);
    u32 weather = AI_GetWeather();

    struct AiCalcValues aiCalcNoTera = {
        .gimmickAtk = GIMMICK_NONE,
        .gimmickDef = GIMMICK_NONE,
        .weather = weather,
        .terrain = gFieldTimers.terrain,
    };

    struct AiCalcValues aiCalcWithTera = {
        .gimmickAtk = gBattleStruct->gimmick.usableGimmick[opposingBattler],
        .gimmickDef = gBattleStruct->gimmick.usableGimmick[battler],
        .weather = weather,
        .terrain = gFieldTimers.terrain,
    };

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        aiCalcNoTera.move = aiMoves[moveIndex];
        if (!IsMoveUnusable(moveIndex, aiCalcNoTera.move, gAiLogicData->moveLimitations[battler]) && !IsBattleMoveStatus(aiCalcNoTera.move))
            altCalcs.dealtWithoutTera[moveIndex] = AI_CalcDamage(&aiCalcNoTera, battler, opposingBattler);
        else
            altCalcs.dealtWithoutTera[moveIndex] = noDmg;

        aiCalcWithTera.move = oppMoves[moveIndex];
        if (!IsMoveUnusable(moveIndex, aiCalcWithTera.move, gAiLogicData->moveLimitations[opposingBattler]) && !IsBattleMoveStatus(aiCalcWithTera.move))
        {
            altCalcs.takenWithTera[moveIndex] = AI_CalcDamage(&aiCalcWithTera, opposingBattler, battler);
            effectivenessTakenWithTera[moveIndex] = aiCalcWithTera.typeEffectiveness;
        }
        else
        {
            altCalcs.takenWithTera[moveIndex] = noDmg;
            effectivenessTakenWithTera[moveIndex] = Q_4_12(0.0);
        }
    }


    enum AIConsiderGimmick res = ShouldTeraFromCalcs(battler, opposingBattler, &altCalcs);


    if (res == USE_GIMMICK)
    {
        // Damage calcs for damage received assumed we wouldn't tera. Adjust that so that further AI decisions are more accurate.
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            gAiLogicData->simulatedDmg[opposingBattler][battler][moveIndex] = altCalcs.takenWithTera[moveIndex];
            gAiLogicData->effectiveness[opposingBattler][battler][moveIndex] = effectivenessTakenWithTera[moveIndex];
        }
    }
    else
    {
        // Damage calcs for damage dealt assumed we would tera. Adjust that so that further AI decisions are more accurate.
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
            gAiLogicData->simulatedDmg[battler][opposingBattler][moveIndex] = altCalcs.dealtWithoutTera[moveIndex];
    }

    SetAIUsingGimmick(battler, res);
    return;
}

// macros are not expanded recursively
#define dealtWithTera gAiLogicData->simulatedDmg[battler][opposingBattler]
#define dealtWithoutTera altCalcs->dealtWithoutTera
#define takenWithTera altCalcs->takenWithTera
#define takenWithoutTera gAiLogicData->simulatedDmg[opposingBattler][battler]

enum AIConsiderGimmick ShouldTeraFromCalcs(enum BattlerId battler, enum BattlerId opposingBattler, struct AltTeraCalcs *altCalcs)
{
    struct Pokemon *party = GetBattlerParty(battler);

    // Check how many Pokémon we have that could tera
    int numPossibleTera = 0;
    for (u32 monIndex = 0; monIndex < PARTY_SIZE; monIndex++)
    {
        if (GetMonData(&party[monIndex], MON_DATA_HP) != 0
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[monIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
         && GetMonData(&party[monIndex], MON_DATA_TERA_TYPE) > 0)
            numPossibleTera++;
    }

    u32 aiHp = gBattleMons[battler].hp;
    u32 oppHp = gBattleMons[opposingBattler].hp;

    enum Move *aiMoves = GetMovesArray(battler);
    enum Move *oppMoves = GetMovesArray(opposingBattler);

    // Check whether tera enables a KO
    bool32 hasKoWithout = FALSE;
    enum Move killingMove = MOVE_NONE;

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (dealtWithTera[moveIndex].median >= oppHp)
        {
            enum Move move = aiMoves[moveIndex];
            if (killingMove == MOVE_NONE || GetBattleMovePriority(battler, gAiLogicData->abilities[battler], move) > GetBattleMovePriority(battler, gAiLogicData->abilities[battler], killingMove))
                killingMove = move;
        }
        if (dealtWithoutTera[moveIndex].median >= oppHp)
            hasKoWithout = TRUE;
    }

    bool32 enablesKo = (killingMove != MOVE_NONE) && !hasKoWithout;

    // Check whether tera saves us from a KO
    bool32 savedFromKo = FALSE;
    bool32 getsKodRegardlessBySingleMove = FALSE;

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (takenWithoutTera[moveIndex].maximum >= aiHp && takenWithTera[moveIndex].maximum >= aiHp)
            getsKodRegardlessBySingleMove = TRUE;

        if (takenWithoutTera[moveIndex].maximum >= aiHp && takenWithTera[moveIndex].maximum < aiHp)
            savedFromKo = TRUE;
    }

    if (getsKodRegardlessBySingleMove)
        savedFromKo = FALSE;

    // Check whether opponent can punish tera by ko'ing
    enum Move hardPunishingMove = MOVE_NONE;
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (takenWithTera[moveIndex].maximum >= aiHp)
        {
            enum Move move = oppMoves[moveIndex];
            if (hardPunishingMove == MOVE_NONE || GetBattleMovePriority(opposingBattler, gAiLogicData->abilities[opposingBattler], move) > GetBattleMovePriority(opposingBattler, gAiLogicData->abilities[opposingBattler], hardPunishingMove))
                hardPunishingMove = move;
        }
    }

    // Check whether there is a move that deals over half hp, and all such moves are reduced to under 1/4 hp by tera
    // (e.g. a weakness becomes a resistance, a 4x weakness becomes neutral, etc)
    bool32 takesBigHit = FALSE;
    bool32 savedFromAllBigHits = TRUE;
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (takenWithoutTera[moveIndex].median > aiHp/2)
        {
            takesBigHit = TRUE;
            if (takenWithTera[moveIndex].median > aiHp/4)
                savedFromAllBigHits = FALSE;
        }
    }

    // Check for any benefit whatsoever. Only used for the last possible mon that could tera.
    bool32 anyOffensiveBenefit = FALSE;
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (dealtWithTera[moveIndex].median > dealtWithoutTera[moveIndex].median)
            anyOffensiveBenefit = TRUE;
    }

    bool32 anyDefensiveBenefit = FALSE;
    bool32 anyDefensiveDrawback = FALSE;
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (takenWithTera[moveIndex].median < takenWithoutTera[moveIndex].median)
            anyDefensiveBenefit = TRUE;

        if (takenWithTera[moveIndex].median > takenWithoutTera[moveIndex].median)
            anyDefensiveDrawback = TRUE;
    }

    // Make decisions
    // This is done after all loops to minimize the possibility of a timing attack in which the player could
    // determine whether the AI will tera based on the time taken to select a move.

    if (enablesKo)
    {
        if (hardPunishingMove == MOVE_NONE)
        {
            return USE_GIMMICK;
        }
        else
        {
            enum Move predictedMove = GetPredictedMove(battler, opposingBattler, gAiLogicData);
            // will we go first?
            if (AI_IsFaster(battler, opposingBattler, killingMove, predictedMove, CONSIDER_PRIORITY) && GetBattleMovePriority(battler, gAiLogicData->abilities[battler], killingMove) >= GetBattleMovePriority(opposingBattler, gAiLogicData->abilities[opposingBattler], hardPunishingMove))
                return USE_GIMMICK;
        }
    }

    // Decide to conserve tera based on number of possible later oppotunities
    u32 conserveTeraChance = AI_CONSERVE_TERA_CHANCE_PER_MON * (numPossibleTera-1);
    if (RandomPercentage(RNG_AI_CONSERVE_TERA, conserveTeraChance))
        return NO_GIMMICK;

    if (savedFromKo)
    {
        if (hardPunishingMove == MOVE_NONE)
        {
            return USE_GIMMICK;
        }
        else
        {
            // If tera saves us from a ko from one move, but enables a ko otherwise, randomly predict
            // savesFromKo being true ensures opponent doesn't have a ko if we don't tera
            if (Random() % 100 < AI_TERA_PREDICT_CHANCE)
                return USE_GIMMICK;
        }
    }

    if (hardPunishingMove != MOVE_NONE)
        return NO_GIMMICK;

    if (takesBigHit && savedFromAllBigHits)
        return USE_GIMMICK;

    // No strongly compelling reason to tera. Conserve it if possible.
    if (numPossibleTera > 1)
        return NO_GIMMICK;

    if (anyOffensiveBenefit || (anyDefensiveBenefit && !anyDefensiveDrawback))
        return USE_GIMMICK;

    // TODO: Effects other than direct damage are not yet considered. For example, may want to tera poison to avoid a Toxic.


    return NO_GIMMICK;
}
#undef dealtWithTera
#undef dealtWithoutTera
#undef takenWithTera
#undef takenWithoutTera

s32 AI_TryToClearStats(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 isDoubleBattle)
{
    if (isDoubleBattle)
        return min(CountPositiveStatStages(battlerDef) + CountPositiveStatStages(GetPartnerBattler(battlerDef)), 7);
    else
        return min(CountPositiveStatStages(battlerDef), 4);
}

bool32 AI_ShouldCopyStatChanges(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    // Want to copy positive stat changes
    for (enum Stat statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battlerDef].statStages[statId] > gBattleMons[battlerAtk].statStages[statId])
        {
            switch (statId)
            {
            case STAT_ATK:
                return (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL));
            case STAT_SPATK:
                return (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL));
            case STAT_ACC:
                return HasMoveWithLowAccuracy(battlerAtk, battlerDef, LOW_ACCURACY_THRESHOLD, FALSE);
            case STAT_EVASION:
            case STAT_SPEED:
                return TRUE;
            case STAT_DEF:
            case STAT_SPDEF:
                return (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_STALL);
            default:
                break;
            }
        }
    }

    return FALSE;
}

//TODO - track entire opponent party data to determine hazard effectiveness
bool32 AI_ShouldSetUpHazards(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    if (CountUsablePartyMons(battlerDef) == 0
     || HasBattlerSideMoveWithAIEffect(battlerDef, AI_EFFECT_CLEAR_HAZARDS))
        return FALSE;

    if (IsBattleMoveStatus(move))
    {
        if (HasMoveWithEffect(battlerDef, EFFECT_MAGIC_COAT))
            return FALSE;
        if (DoesBattlerIgnoreAbilityChecks(battlerAtk, aiData->abilities[battlerAtk], move))
            return TRUE;
        if (aiData->abilities[battlerDef] == ABILITY_MAGIC_BOUNCE)
            return FALSE;
    }
    else
    {
        if (DoesBattlerIgnoreAbilityChecks(battlerAtk, aiData->abilities[battlerAtk], move))
            return TRUE;
        if (aiData->abilities[battlerDef] == ABILITY_SHIELD_DUST)
            return FALSE;
    }
    return TRUE;
}

void IncreaseTidyUpScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score)
{
    if (AreAnyHazardsOnSide(GetBattlerSide(battlerAtk)) && CountUsablePartyMons(battlerAtk) != 0)
        ADJUST_SCORE_PTR(GOOD_EFFECT);
    if (AreAnyHazardsOnSide(GetBattlerSide(battlerDef)) && CountUsablePartyMons(battlerDef) != 0)
        ADJUST_SCORE_PTR(-2);
    enum Move predictedMove = GetPredictedMove(battlerAtk, battlerDef, gAiLogicData);
    if (gBattleMons[battlerAtk].volatiles.substitute && AI_IsFaster(battlerAtk, battlerDef, move, predictedMove, DONT_CONSIDER_PRIORITY))
        ADJUST_SCORE_PTR(-10);
    if (gBattleMons[battlerDef].volatiles.substitute)
        ADJUST_SCORE_PTR(GOOD_EFFECT);

    if (gBattleMons[battlerAtk].volatiles.leechSeed)
        ADJUST_SCORE_PTR(DECENT_EFFECT);
    if (gBattleMons[battlerDef].volatiles.leechSeed)
        ADJUST_SCORE_PTR(-2);
}

u32 IncreaseSubstituteMoveScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    u32 scoreIncrease = 0;
    if (effect == EFFECT_SUBSTITUTE) // Substitute specific
    {
        if (HasAnyKnownMove(battlerDef) && GetBestDmgFromBattler(battlerDef, battlerAtk, AI_DEFENDING) < gBattleMons[battlerAtk].maxHP / 4)
            scoreIncrease += GOOD_EFFECT;
    }
    else if (effect == EFFECT_SHED_TAIL) // Shed Tail specific
    {
        if ((ShouldPivot(battlerAtk, battlerDef, move))
        && (HasAnyKnownMove(battlerDef) && (GetBestDmgFromBattler(battlerDef, battlerAtk, AI_DEFENDING) < gBattleMons[battlerAtk].maxHP / 2)))
            scoreIncrease += BEST_EFFECT;
    }

    if (gBattleMons[battlerDef].volatiles.perishSong)
        scoreIncrease += GOOD_EFFECT;

    if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP)
        scoreIncrease += GOOD_EFFECT;
    else if (gBattleMons[battlerDef].status1 & STATUS1_DAMAGING)
        scoreIncrease += DECENT_EFFECT;

    if (IsBattlerPredictedToSwitch(battlerDef))
        scoreIncrease += DECENT_EFFECT;

    if (HasNonVolatileMoveEffect(battlerDef, MOVE_EFFECT_SLEEP)
     || HasNonVolatileMoveEffect(battlerDef, MOVE_EFFECT_TOXIC)
     || HasNonVolatileMoveEffect(battlerDef, MOVE_EFFECT_PARALYSIS)
     || HasNonVolatileMoveEffect(battlerDef, MOVE_EFFECT_BURN)
     || HasMoveWithEffect(battlerDef, EFFECT_CONFUSE)
     || HasMoveWithEffect(battlerDef, EFFECT_LEECH_SEED))
        scoreIncrease += GOOD_EFFECT;

    if (gAiLogicData->hpPercents[battlerAtk] > 70)
        scoreIncrease += WEAK_EFFECT;
    return scoreIncrease;
}

bool32 IsBattlerItemEnabled(enum BattlerId battler)
{
    if (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_NEGATE_UNAWARE)
        return TRUE;
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        return FALSE;
    if (gBattleMons[battler].volatiles.embargoTimer)
        return FALSE;
    if (gAiLogicData->abilities[battler] == ABILITY_KLUTZ && !gBattleMons[battler].volatiles.gastroAcid)
        return FALSE;
    return TRUE;
}

u32 GetFriendlyFireKOThreshold(enum BattlerId battler)
{
    if (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_RISKY)
        return FRIENDLY_FIRE_RISKY_THRESHOLD;
    if (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_CONSERVATIVE)
        return FRIENDLY_FIRE_CONSERVATIVE_THRESHOLD;
    if (gAiThinkingStruct->aiFlags[battler] & AI_FLAG_ATTACKS_PARTNER)
        return 0;

    return FRIENDLY_FIRE_NORMAL_THRESHOLD;
}

bool32 IsMoxieTypeAbility(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_MOXIE:
    case ABILITY_BEAST_BOOST:
    case ABILITY_CHILLING_NEIGH:
    case ABILITY_AS_ONE_ICE_RIDER:
    case ABILITY_GRIM_NEIGH:
    case ABILITY_AS_ONE_SHADOW_RIDER:
    case ABILITY_EELEVATE:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 DoesAbilityRaiseStatsWhenLowered(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_CONTRARY:
    case ABILITY_COMPETITIVE:
    case ABILITY_DEFIANT:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 DoesIntimidateRaiseStats(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_COMPETITIVE:
    case ABILITY_CONTRARY:
    case ABILITY_DEFIANT:
    case ABILITY_GUARD_DOG:
        return TRUE;
    case ABILITY_RATTLED:
        return GetConfig(B_UPDATED_INTIMIDATE) >= GEN_8;
    default:
        return FALSE;
    }
}

// TODO: work out when to attack into the player's contextually 'beneficial' ability
bool32 ShouldTriggerAbility(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability ability)
{
    if (IsTargetingPartner(battlerAtk, battlerDef))
    {
        switch (ability)
        {
        case ABILITY_LIGHTNING_ROD:
        case ABILITY_STORM_DRAIN:
            if (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) < GEN_5)
                return FALSE;
            else
                return (BattlerStatCanRise(battlerDef, ability, STAT_SPATK) && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL));

        case ABILITY_DEFIANT:
        case ABILITY_JUSTIFIED:
        case ABILITY_MOXIE:
        case ABILITY_SAP_SIPPER:
        case ABILITY_THERMAL_EXCHANGE:
            return (BattlerStatCanRise(battlerDef, ability, STAT_ATK) && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL));

        case ABILITY_COMPETITIVE:
            return (BattlerStatCanRise(battlerDef, ability, STAT_SPATK) && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL));

        // TODO: logic for when to trigger Contrary
        case ABILITY_CONTRARY:
            return TRUE;

        case ABILITY_DRY_SKIN:
        case ABILITY_VOLT_ABSORB:
        case ABILITY_WATER_ABSORB:
            return (gAiThinkingStruct->aiFlags[battlerDef] & AI_FLAG_HP_AWARE);

        case ABILITY_RATTLED:
        case ABILITY_STEAM_ENGINE:
            return BattlerStatCanRise(battlerDef, ability, STAT_SPEED);

        case ABILITY_FLASH_FIRE:
            return (HasMoveWithType(battlerDef, TYPE_FIRE) && !gBattleMons[battlerDef].volatiles.flashFireBoosted);

        case ABILITY_WATER_COMPACTION:
        case ABILITY_WELL_BAKED_BODY:
            return (BattlerStatCanRise(battlerDef, ability, STAT_DEF));

        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

// Used by CheckBadMove; this is determining purely if the effect CAN change an ability, not if it SHOULD.
// At the moment, the parts about Mummy and Wandering Spirit are not actually used.
bool32 CanEffectChangeAbility(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);

    // Dynamaxed Pokemon are immune to some ability-changing effects.
    if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
    {
        switch (effect)
        {
        case EFFECT_ENTRAINMENT:
        case EFFECT_SKILL_SWAP:
            return FALSE;
        default:
            break;
        }
    }

    if (gBattleMons[battlerDef].volatiles.gastroAcid)
        return FALSE;

    enum Ability atkAbility = aiData->abilities[battlerAtk];
    enum Ability defAbility = aiData->abilities[battlerDef];
    bool32 hasSameAbility = (atkAbility == defAbility);

    if (defAbility == ABILITY_NONE)
        return FALSE;

    if (atkAbility == ABILITY_NONE)
    {
        switch (effect)
        {
        case EFFECT_DOODLE:
        case EFFECT_ENTRAINMENT:
        case EFFECT_ROLE_PLAY:
        case EFFECT_SKILL_SWAP:
            return FALSE;

        default:
            break;
        }
    }

    // Checking for Ability-specific immunities.
    switch (effect)
    {
    case EFFECT_DOODLE:
        if (hasSameAbility || gAbilitiesInfo[atkAbility].cantBeSuppressed || gAbilitiesInfo[defAbility].cantBeCopied)
            return FALSE;

        if (HasPartnerIgnoreFlags(battlerAtk))
        {
            enum Ability partnerAbility = aiData->abilities[GetPartnerBattler(battlerAtk)];
            if (gAbilitiesInfo[partnerAbility].cantBeSuppressed)
                return FALSE;
            if (partnerAbility == defAbility)
                return FALSE;
        }
        break;

    case EFFECT_ROLE_PLAY:
        if (hasSameAbility || gAbilitiesInfo[atkAbility].cantBeSuppressed || gAbilitiesInfo[defAbility].cantBeCopied)
            return FALSE;
        break;

    case EFFECT_SKILL_SWAP:
        if (hasSameAbility || gAbilitiesInfo[atkAbility].cantBeSwapped || gAbilitiesInfo[defAbility].cantBeSwapped)
            return FALSE;
        break;

    case EFFECT_GASTRO_ACID:
        if (gAbilitiesInfo[defAbility].cantBeSuppressed)
            return FALSE;
        break;

    case EFFECT_ENTRAINMENT:
        if (hasSameAbility || gAbilitiesInfo[defAbility].cantBeOverwritten || gAbilitiesInfo[atkAbility].cantBeCopied)
            return FALSE;
        break;

    case EFFECT_OVERWRITE_ABILITY:
        if (defAbility == GetMoveOverwriteAbility(move) || gAbilitiesInfo[defAbility].cantBeOverwritten)
            return FALSE;
        break;

    default:
        return FALSE;
    }

    if (aiData->holdEffects[battlerDef] == HOLD_EFFECT_ABILITY_SHIELD)
    {
        switch (effect)
        {
        case EFFECT_ENTRAINMENT:
        case EFFECT_GASTRO_ACID:
        case EFFECT_ROLE_PLAY:
        case EFFECT_SKILL_SWAP:
        case EFFECT_OVERWRITE_ABILITY:
            return FALSE;
        default:
            break;
        }
    }

    if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_ABILITY_SHIELD)
    {
        switch (effect)
        {
        case EFFECT_DOODLE:
        case EFFECT_ROLE_PLAY:
        case EFFECT_SKILL_SWAP:
            return FALSE;
        default:
            break;
        }
    }

    return TRUE;
}

bool32 DoesEffectReplaceTargetAbility(u32 effect)
{
    switch (effect)
    {
    case EFFECT_ENTRAINMENT:
    case EFFECT_GASTRO_ACID:
    case EFFECT_SKILL_SWAP:
    case EFFECT_OVERWRITE_ABILITY:
        return TRUE;
    default:
        return FALSE;
    }
}

void AbilityChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, s32 *score, struct AiLogicData *aiData)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    bool32 isTargetingPartner = IsTargetingPartner(battlerAtk, battlerDef);
    enum Ability abilityAtk = aiData->abilities[battlerAtk];
    enum Ability abilityDef = aiData->abilities[battlerDef];
    bool32 partnerHasBadAbility = FALSE;
    enum Ability partnerAbility = ABILITY_NONE;
    bool32 attackerHasBadAbility = (gAbilitiesInfo[abilityAtk].aiRating < 0);
    enum AIScore currentAbilityScore, transferredAbilityScore = NO_INCREASE;

    if (HasPartner(battlerAtk))
    {
        partnerAbility = aiData->abilities[GetPartnerBattler(battlerAtk)];
        if (!(gAbilitiesInfo[partnerAbility].cantBeSuppressed) && (gAbilitiesInfo[partnerAbility].aiRating < 0))
            partnerHasBadAbility = TRUE;
    }

    if (effect == EFFECT_GASTRO_ACID)
        abilityAtk = ABILITY_NONE;
    else if (effect == EFFECT_OVERWRITE_ABILITY)
        abilityAtk = GetMoveOverwriteAbility(move);

    if (effect == EFFECT_DOODLE || effect == EFFECT_ROLE_PLAY || effect == EFFECT_SKILL_SWAP)
    {
        if (partnerHasBadAbility && effect == EFFECT_DOODLE)
            ADJUST_SCORE_PTR(DECENT_EFFECT);

        if (attackerHasBadAbility)
            ADJUST_SCORE_PTR(DECENT_EFFECT);

        currentAbilityScore = BattlerBenefitsFromAbilityScore(battlerAtk, abilityAtk, aiData);
        transferredAbilityScore = BattlerBenefitsFromAbilityScore(battlerAtk, abilityDef, aiData);
        ADJUST_SCORE_PTR(transferredAbilityScore - currentAbilityScore);
    }

    if (isTargetingPartner)
    {
        if (DoesEffectReplaceTargetAbility(effect))
        {
            if (partnerHasBadAbility)
                ADJUST_SCORE_PTR(BEST_EFFECT);

            currentAbilityScore = BattlerBenefitsFromAbilityScore(battlerDef, abilityDef, aiData);
            transferredAbilityScore = BattlerBenefitsFromAbilityScore(battlerDef, abilityAtk, aiData);
            ADJUST_SCORE_PTR(transferredAbilityScore - currentAbilityScore);
        }
        else // This is only Role Play as Doodle can't target the partner
        {
            ADJUST_SCORE_PTR(-20);
        }

        // Trigger Plus or Minus in modern gens. This is not in the overarching function because Skill Swap is rarely beneficial here.
        if (B_PLUS_MINUS_INTERACTION >= GEN_5)
        {
            if (((effect == EFFECT_ENTRAINMENT) && (abilityAtk == ABILITY_PLUS || abilityAtk == ABILITY_MINUS)) || ((effect == EFFECT_ROLE_PLAY) && (abilityDef == ABILITY_PLUS || abilityDef == ABILITY_MINUS)))
                ADJUST_SCORE_PTR(DECENT_EFFECT);
        }

    }
    // Targeting an opponent.
    else
    {
        // We already checked if we want their ability, so now we look to see if we want them to lose their ability.
        if (DoesEffectReplaceTargetAbility(effect))
        {
            currentAbilityScore = BattlerBenefitsFromAbilityScore(battlerDef, abilityDef, aiData);
            transferredAbilityScore = BattlerBenefitsFromAbilityScore(battlerDef, abilityAtk, aiData);
            ADJUST_SCORE_PTR(currentAbilityScore - transferredAbilityScore);
        }
    }
}

enum AIScore BattlerBenefitsFromAbilityScore(enum BattlerId battler, enum Ability ability, struct AiLogicData *aiData)
{
    if (gAbilitiesInfo[ability].aiRating < 0)
        return WORST_EFFECT;

    switch (ability)
    {
    // Transferrable abilities that can be assumed to be always beneficial.
    case ABILITY_CLEAR_BODY:
    case ABILITY_GOOD_AS_GOLD:
    case ABILITY_MAGIC_GUARD:
    case ABILITY_MOODY:
    case ABILITY_PURIFYING_SALT:
    case ABILITY_SPEED_BOOST:
    case ABILITY_WHITE_SMOKE:
        return GOOD_EFFECT;
    // Conditional ability logic goes here.
    case ABILITY_COMPOUND_EYES:
        if (HasMoveWithLowAccuracy(battler, GetBattlerLeftFoe(battler), 90, FALSE)
         || HasMoveWithLowAccuracy(battler, GetBattlerRightFoe(battler), 90, FALSE))
            return GOOD_EFFECT;
        break;
    case ABILITY_CONTRARY:
        if (HasMoveThatLowersOwnStats(battler))
            return BEST_EFFECT;
        if (HasMoveThatRaisesOwnStats(battler))
            return AWFUL_EFFECT;
        break;
    case ABILITY_FRIEND_GUARD:
    case ABILITY_POWER_SPOT:
    case ABILITY_VICTORY_STAR:
        if (HasPartner(battler) && aiData->abilities[GetPartnerBattler(battler)] != ability)
            return BEST_EFFECT;
        break;
    case ABILITY_GUTS:
        if (HasMoveWithCategory(battler, DAMAGE_CATEGORY_PHYSICAL) && gBattleMons[battler].status1 & (STATUS1_CAN_MOVE))
            return GOOD_EFFECT;
        break;
    case ABILITY_HUGE_POWER:
    case ABILITY_PURE_POWER:
        if (HasMoveWithCategory(battler, DAMAGE_CATEGORY_PHYSICAL))
            return BEST_EFFECT;
        break;
    // Also used to Worry Seed WORRY_SEED
    case ABILITY_INSOMNIA:
    case ABILITY_VITAL_SPIRIT:
        if (HasMoveWithEffect(battler, EFFECT_REST))
            return WORST_EFFECT;
        break;
    case ABILITY_INTIMIDATE:
    {
        enum Ability abilityDef = aiData->abilities[GetBattlerLeftFoe(battler)];
        if (DoesIntimidateRaiseStats(abilityDef))
        {
            return AWFUL_EFFECT;
        }
        else
        {
            if (HasTwoOpponents(battler))
            {
                abilityDef = aiData->abilities[GetBattlerRightFoe(battler)];
                if (DoesIntimidateRaiseStats(abilityDef))
                {
                    return AWFUL_EFFECT;
                }
                else
                {
                    enum AIScore score1 = IncreaseStatDownScore(battler, GetBattlerLeftFoe(battler), STAT_ATK);
                    enum AIScore score2 = IncreaseStatDownScore(battler, GetBattlerRightFoe(battler), STAT_ATK);
                    if (score1 > score2)
                        return score1;
                    else
                        return score2;
                }
            }
            return IncreaseStatDownScore(battler, GetBattlerLeftFoe(battler), STAT_ATK);
        }
    }
    case ABILITY_NO_GUARD:
        if (HasMoveWithLowAccuracy(battler, GetBattlerLeftFoe(battler), LOW_ACCURACY_THRESHOLD, FALSE)
         || HasMoveWithLowAccuracy(battler, GetBattlerRightFoe(battler), LOW_ACCURACY_THRESHOLD, FALSE))
            return GOOD_EFFECT;
        break;
    // Toxic counter ticks upward while Poison Healed; losing Poison Heal while Toxiced can KO.
    case ABILITY_POISON_HEAL:
        if (gBattleMons[battler].status1 & (STATUS1_POISON))
            return WEAK_EFFECT;
        if (gBattleMons[battler].status1 & (STATUS1_TOXIC_POISON))
            return BEST_EFFECT;
        if (gBattleMons[battler].status1 & STATUS1_ANY)
            return NO_INCREASE;
        break;
    // Also used to Simple Beam SIMPLE_BEAM.
    case ABILITY_SIMPLE:
        // Prioritize moves like Metal Claw, Charge Beam, or Power up Punch
        if (HasMoveThatRaisesOwnStats(battler))
            return GOOD_EFFECT;
        return NO_INCREASE;
    case ABILITY_BEADS_OF_RUIN:
    case ABILITY_SWORD_OF_RUIN:
    case ABILITY_TABLETS_OF_RUIN:
    case ABILITY_VESSEL_OF_RUIN:
        if (HasPartner(battler))
        {
            if (aiData->abilities[GetPartnerBattler(battler)] != ability)
                return GOOD_EFFECT;
            else
                return NO_INCREASE;
        }
        return GOOD_EFFECT;
    case ABILITY_NONE:
        return NO_INCREASE;
    default:
        break;
    }

    return WEAK_EFFECT;
}

u32 GetAIExplosionChanceFromHP(u32 hpPercent)
{
    if (hpPercent >= EXPLOSION_HIGHER_HP_THRESHOLD)
        return EXPLOSION_MINIMUM_CHANCE;
    if (hpPercent <= EXPLOSION_LOWER_HP_THRESHOLD)
        return EXPLOSION_MAXIMUM_CHANCE;
    return (EXPLOSION_HIGHER_HP_THRESHOLD - hpPercent);
}

bool32 ShouldFinalGambit(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 aiIsFaster)
{
    if (!gAiLogicData->shouldConsiderFinalGambit)
        return FALSE;
    // Note to use GetScaledHPFraction
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_OMNISCIENT)
    {
        if (gBattleMons[battlerAtk].hp >= gBattleMons[battlerDef].hp && aiIsFaster)
            return TRUE;
    }
    else if (gAiLogicData->hpPercents[battlerAtk] >= gAiLogicData->hpPercents[battlerDef] // Consider using GetScaledHPFraction and moving B_HEALTHBAR_PIXELS define
        && GetSpeciesBaseHP(gBattleMons[battlerAtk].species) >= GetSpeciesBaseHP(gBattleMons[battlerDef].species)
        && aiIsFaster)
    {
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldConsiderSelfSacrificeDamageEffect(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, bool32 aiIsFaster)
{
    if (gAiThinkingStruct->aiFlags[battlerAtk] & AI_FLAG_WILL_SUICIDE)
        return TRUE;
    if (!IsDoubleBattle() && IsExplosionMove(move) && gAiLogicData->shouldConsiderExplosion)
        return TRUE;
    if (GetMoveEffect(move) == EFFECT_FINAL_GAMBIT)
        return ShouldFinalGambit(battlerAtk, battlerDef, aiIsFaster);
    return FALSE;
}

bool32 AiExpectsToFaintPlayer(enum BattlerId battler)
{
    u8 target = gAiBattleData->chosenTarget[battler];

    if (gAiBattleData->actionFlee || gAiBattleData->choiceWatch)
        return FALSE; // AI not planning to use move

    if (!IsBattlerAlly(target, battler)
      && CanIndexMoveFaintTarget(battler, target, gAiBattleData->chosenMoveIndex[battler], AI_ATTACKING)
      && AI_IsFaster(battler, target, GetAIChosenMove(battler), GetIncomingMove(battler, target, gAiLogicData), CONSIDER_PRIORITY))
    {
        // We expect to faint the target and move first -> dont use an item or switch
        return TRUE;
    }

    return FALSE;
}

bool32 AI_OpponentCanFaintAiWithMod(enum BattlerId battler, u32 healAmount)
{
    // Check special cases to NOT heal
    for (enum BattlerId battlerIndex = 0; battlerIndex < gBattlersCount; battlerIndex++)
    {
        if (IsOnPlayerSide(battlerIndex) && CanTargetFaintAiWithMod(battlerIndex, battler, healAmount, 0))
        {
            // Target is expected to faint us
            return TRUE;
        }
    }
    return FALSE;
}

s32 GetAILastPartyIndex(enum BattlerId battler)
{
    return (BattleSideHasTwoTrainers(battler & BIT_SIDE) && !AreMultiPartiesFullTeams()) ? PARTY_SIZE / 2 : PARTY_SIZE;
}

bool32 ShouldInstructPartner(enum BattlerId partner, enum Move move)
{
    if (GetMoveEffect(move) == EFFECT_MAX_HP_50_RECOIL && gAiLogicData->abilities[partner] != ABILITY_MAGIC_GUARD)
        return FALSE;

    enum MoveTarget type = AI_GetBattlerMoveTargetType(partner, move);
    switch (type)
    {
    case TARGET_SELECTED:
    case TARGET_SMART:
    case TARGET_DEPENDS:
    case TARGET_RANDOM:
    case TARGET_BOTH:
    case TARGET_FOES_AND_ALLY:
    case TARGET_USER_AND_ALLY:
    case TARGET_OPPONENTS_FIELD:
        return TRUE;
    default:
        return FALSE;
    }

    return FALSE;
}

bool32 CanMoveBeBouncedBack(enum BattlerId battler, enum Move move)
{
    if (!MoveCanBeBouncedBack(move) || !IsBattleMoveStatus(move))
        return FALSE;

    enum MoveTarget type = AI_GetBattlerMoveTargetType(battler, move);
    switch (type)
    {
    case TARGET_SELECTED:
    case TARGET_SMART:
    case TARGET_OPPONENTS_FIELD:
    case TARGET_BOTH:
        return TRUE;
    default:
        return FALSE;
    }

    return FALSE;
}

u32 GetActiveBattlerIds(enum BattlerId battler, enum BattlerId *battlerIn1, enum BattlerId *battlerIn2)
{
    enum BattlerId opposingBattler = 0;
    enum BattlerPosition battlerPosition = GetBattlerPosition(battler);
    if (IsDoubleBattle())
    {
        *battlerIn1 = battler;
        if (gAbsentBattlerFlags & (1u << GetPartnerBattler(battler)))
            *battlerIn2 = battler;
        else
            *battlerIn2 = GetBattlerAtPosition(GetPartnerPosition(battlerPosition));

        opposingBattler = GetOppositeBattler(*battlerIn1);
        if (gAbsentBattlerFlags & (1u << opposingBattler))
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(GetOppositePosition(battlerPosition));
        *battlerIn1 = battler;
        *battlerIn2 = battler;
    }

    return opposingBattler;
}

bool32 IsPartyMonOnFieldOrChosenToSwitch(enum BattlerId battler, u32 partyIndex, enum BattlerId battlerIn1, enum BattlerId battlerIn2)
{
    if ((partyIndex == gBattlerPartyIndexes[battlerIn1] && BattlersShareParty(battler, battlerIn1))
            || (partyIndex == gBattlerPartyIndexes[battlerIn2] && BattlersShareParty(battler, battlerIn2)))
        return TRUE;
    if ((partyIndex == gBattleStruct->monToSwitchIntoId[battlerIn1] && BattlersShareParty(battler, battlerIn1))
            || (partyIndex == gBattleStruct->monToSwitchIntoId[battlerIn2] && BattlersShareParty(battler, battlerIn2)))
        return TRUE;
    return FALSE;
}

bool32 IsPartyMonPlannedToBeSwitchedInByPartner(u32 partyIndex, enum BattlerId battler)
{
    enum BattlerId battlerPartner = GetPartnerBattler(battler);
    if (partyIndex == gAiLogicData->mostSuitableMonId[battlerPartner] && (gAiLogicData->shouldSwitch & (1u << battlerPartner)) && BattlersShareParty(battler, battlerPartner))
        return TRUE;
    return FALSE;
}

s32 AI_GetAdjustedStatStage(enum BattlerId battler, enum Move move, s32 stage)
{
    if (GetMoveEffect(move) == EFFECT_GROWTH
     && GetAttackerWeather(gAiLogicData->holdEffects[battler], gAiLogicData->abilities[battler], AI_GetWeather()) & B_WEATHER_SUN)
        stage = 2;

    if (stage == STAT_CHANGE_FORCE_MAX)
        stage = 12;

    switch (gAiLogicData->abilities[battler])
    {
    case ABILITY_CONTRARY:
        return (stage * -1);
        break;
    case ABILITY_SIMPLE:
        return (stage * 2);
    default:
        return stage;
    }
}

// For user and Foe
s32 GetStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    s32 tempScore = 0;
    enum MoveTarget targetType = AI_GetBattlerMoveTargetType(battlerAtk, move);

    switch (targetType)
    {
    case TARGET_ALL_BATTLERS:
    case TARGET_USER:
        tempScore = GetSelfStatChangeScore(battlerAtk, battlerDef, move);
        break;
    case TARGET_USER_AND_ALLY:
    case TARGET_USER_OR_ALLY:
        if (battlerAtk == GetPartnerBattler(battlerDef))
            break; // Handled in AI_DoubleBattler
        tempScore = GetSelfStatChangeScore(battlerAtk, battlerDef, move);
        break;
    case TARGET_ALLY:
        break; // Handled in AI_DoubleBattle
    default:
        if (battlerAtk == GetPartnerBattler(battlerDef))
            break; // Handled in AI_DoubleBattle
        tempScore = GetFoeStatChangeScore(battlerAtk, battlerDef, move);
        break;
    }

    return tempScore;
}

s32 GetSelfStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    s32 tempScore = 0;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);

    // This is technically already included in IncreaseStatUpScore
    if (!ShouldRaiseAnyStat(battlerAtk, battlerDef))
        return NO_INCREASE;

    for (u32 effectIndex = 0; effectIndex < numAdditionalEffects; effectIndex++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(move, effectIndex);

        if (effect->moveEffect != STAT_CHANGE_EFFECT_PLUS
         && effect->moveEffect != STAT_CHANGE_EFFECT_MINUS)
            continue;

        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
        {
            s32 stage = GetStatStage(stat, effect);

            if (stage == 0)
                continue;

            if (effect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
                stage = -1 * stage;

            stage = AI_GetAdjustedStatStage(battlerAtk, move, stage);

            if (stage > 0)
            {
                // The function handles Simple which it does not need in this case, but it is harmless
                // Also a lot of recalculating happening in there, can be optimized later (should be split in 2 parts)
                tempScore += IncreaseStatUpScoreContrary(battlerAtk, battlerDef, stat, stage);
            }
            else if (stage < 0)
            {
                if (gAiLogicData->holdEffects[battlerAtk] == HOLD_EFFECT_WHITE_HERB)
                    continue; // No Score decrease

                switch (stat)
                {
                case STAT_ATK:
                    if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_PHYSICAL))
                        return NO_INCREASE; // Don't lower power of mons attacking moves
                    break;
                case STAT_SPATK:
                    if (HasMoveWithCategory(battlerAtk, DAMAGE_CATEGORY_SPECIAL))
                        return NO_INCREASE; // Don't lower power of mons attacking moves
                    break;
                default: // Case can be made to also never lower Speed
                    tempScore--; // Minor score decrease if stats are reduced. Positive stat changes should take priority
                }
            }
        }
    }

    return (tempScore > BEST_EFFECT) ? BEST_EFFECT : tempScore;
}

s32 GetFoeStatChangeScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    s32 score = 0;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);

    for (u32 effectIndex = 0; effectIndex < numAdditionalEffects; effectIndex++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(move, effectIndex);

        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
        {
            s32 stage = GetStatStage(stat, effect);

            if (stage == 0)
                continue;

            if (effect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
                stage = -1 * stage;

            stage = AI_GetAdjustedStatStage(battlerDef, move, stage);

            if (stage > 0)
            {
                if ((stat == STAT_ATK && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_PHYSICAL))
                 || (stat == STAT_SPATK && HasMoveWithCategory(battlerDef, DAMAGE_CATEGORY_SPECIAL)))
                    return -10; // Don't decrease any stats since the price might be to high
            }
            else if (stage < 0)
            {
                if (gAiLogicData->holdEffects[battlerDef] == HOLD_EFFECT_WHITE_HERB)
                    return -10; // White Herb resotres stats
                score += IncreaseStatDownScore(battlerAtk, battlerDef, stat);
            }
        }
    }

    return (score > BEST_EFFECT) ? BEST_EFFECT : score;
}

s32 GetAllyStatChangeScore(enum BattlerId battlerAtk, enum BattlerId partner, enum Move move)
{
    s32 tempScore = 0;
    enum BattlerId foe = GetBattlerLeftFoe(battlerAtk);

    if (AI_IsAbilityOnSide(foe, ABILITY_UNAWARE) || AI_IsAbilityOnSide(foe, ABILITY_OPPORTUNIST))
        return tempScore;

    if (gBattleMons[partner].volatiles.yawn && CanBeSlept(partner, partner, gAiLogicData->abilities[partner], BLOCKED_BY_SLEEP_CLAUSE))
        return tempScore;

    if (GetBattlerSecondaryDamage(partner) >= gBattleMons[partner].hp)
        return tempScore;

    if (!RandomPercentage(RNG_AI_BOOST_INTO_HAZE, BOOST_INTO_HAZE_CHANCE)
     && HasBattlerSideUsedMoveWithEffect(foe, EFFECT_HAZE))
        return tempScore;

    if (CanBattlerKOTargetIgnoringSturdy(partner, foe)
     || CanBattlerKOTargetIgnoringSturdy(partner, GetPartnerBattler(foe)))
        return tempScore;

    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);

    for (u32 effectIndex = 0; effectIndex < numAdditionalEffects; effectIndex++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(move, effectIndex);

        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
        {
            s32 stage = GetStatStage(stat, effect);

            if (stage == 0)
                continue;

            if (effect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
                stage = -1 * stage;

            stage = AI_GetAdjustedStatStage(partner, move, stage);

            if (stage > 0)
            {
                switch (stat)
                {
                case STAT_ATK:
                    if (HasMoveWithCategory(partner, DAMAGE_CATEGORY_PHYSICAL)
                     && !HasBattlerSideMoveWithEffect(foe, EFFECT_FOUL_PLAY))
                        tempScore += GOOD_EFFECT;
                    break;
                case STAT_SPATK:
                    if (HasMoveWithCategory(partner, DAMAGE_CATEGORY_SPECIAL))
                        tempScore += GOOD_EFFECT;
                    break;
                case STAT_DEF: // could check if foes moves are physical / status only
                case STAT_SPDEF: // same here but for special
                case STAT_SPEED: // could check if slower then foes
                case STAT_ACC:
                case STAT_EVASION:
                    tempScore += WEAK_EFFECT; // only increase if multiply stats can be increased
                    break;
                default:
                    break;
                }
            }
            else if (stage < 0)
            {
                if (gAiLogicData->holdEffects[partner] == HOLD_EFFECT_WHITE_HERB
                 || gAiLogicData->holdEffects[partner] == HOLD_EFFECT_CLEAR_AMULET)
                    continue; // No Score decrease

                switch (stat)
                {
                // TODO: check if partner has move to increase corresponding stats. In which case don't increase score at all
                case STAT_ATK:
                    if (HasMoveWithCategory(partner, DAMAGE_CATEGORY_PHYSICAL))
                        return NO_INCREASE; // Don't lower power of mons attacking moves
                    break;
                case STAT_SPATK:
                    if (HasMoveWithCategory(partner, DAMAGE_CATEGORY_SPECIAL))
                        return NO_INCREASE; // Don't lower power of mons attacking moves
                    break;
                default: // Case can be made to also never lower Speed
                    tempScore--; // Minor score decrease if stats are reduced. Positive stat changes should take priority
                }
            }
        }
    }

    return (tempScore > BEST_EFFECT) ? BEST_EFFECT : tempScore;
}

static bool32 AI_CanStatChangeBePrevented(struct BattleCalcValues *cv)
{
    enum MoveTarget targetType = AI_GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    switch (targetType)
    {
    case TARGET_USER:
    case TARGET_USER_AND_ALLY:
    case TARGET_USER_OR_ALLY:
    case TARGET_ALLY:
        return FALSE;
    case TARGET_ALL_BATTLERS:
        if (cv->battlerAtk == cv->battlerDef)
            return FALSE;
    default:
        if (IsSubstituteProtected(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->move)
         || cv->abilities[cv->battlerDef] == ABILITY_GOOD_AS_GOLD)
            return TRUE;
    }

    return FALSE;
}

// Only checks if a stat can actually change. Doesn't do any other sophisticated decision
bool32 AI_CanAnyStatChange(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    struct BattleCalcValues cv = {
        .battlerAtk = battlerAtk,
        .battlerDef = battlerDef,
        .move = move,
    };
    struct StatChange st = {
        .onlyChecking = TRUE,
        .certain = (battlerAtk == battlerDef),
    };

    cv.abilities[battlerAtk] = gAiLogicData->abilities[battlerAtk];
    cv.holdEffects[battlerAtk] = gAiLogicData->holdEffects[battlerAtk];

    if (battlerAtk != battlerDef)
    {
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            if (battler == battlerAtk)
                continue;

            cv.holdEffects[battler] = gAiLogicData->holdEffects[battler];
            cv.abilities[battler] = AI_GetMoldBreakerSanitizedAbility(
                                        battlerAtk,
                                        cv.abilities[battlerAtk],
                                        gAiLogicData->abilities[battler],
                                        cv.holdEffects[battler],
                                        move
                                    );
        }
    }

    if (AI_CanStatChangeBePrevented(&cv))
        return FALSE;

    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);

    for (u32 effectIndex = 0; effectIndex < numAdditionalEffects; effectIndex++)
    {
        const struct AdditionalEffect *effect = GetMoveAdditionalEffectById(move, effectIndex);

        for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
        {
            st.stat = stat;
            st.stage = GetStatStage(stat, effect);

            if (st.stage == 0)
                continue;

            if (effect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
                st.stage = -1 * st.stage;

            st.stage = AI_GetAdjustedStatStage(battlerDef, move, st.stage);

            if (CanStatChange(&cv, &st))
                return TRUE;
        }
    }

    return FALSE;
}

void AI_SetBattlerTurnOrder(u8 *aiTurnOrder)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        aiTurnOrder[battler] = battler;

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        for (u32 j = 0; j < gBattlersCount; j++)
        {
            if (AI_WhoStrikesFirst(aiTurnOrder[i], aiTurnOrder[j], MOVE_NONE, MOVE_NONE, DONT_CONSIDER_PRIORITY) == AI_IS_FASTER)
            {
                u32 temp = aiTurnOrder[i];
                aiTurnOrder[i] = aiTurnOrder[j];
                aiTurnOrder[j] = temp;
            }
        }
    }
}

static bool32 WillPartnerActBeforeOrAfter(enum BattlerId battler, enum BattlerId partner)
{
    u8 aiTurnOrder[MAX_BATTLERS_COUNT] = {0};
    u32 battlerTurnOrder = MAX_BATTLERS_COUNT;
    u32 partnerTurnOrder = MAX_BATTLERS_COUNT;
    AI_SetBattlerTurnOrder(aiTurnOrder);

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        if (aiTurnOrder[i] == battler)
            battlerTurnOrder = i;
        else if (aiTurnOrder[i] == partner)
            partnerTurnOrder = i;
    }

    return battlerTurnOrder + 1 == partnerTurnOrder || partnerTurnOrder + 1 == battlerTurnOrder;
}

bool32 ShouldUseFusionMove(enum BattlerId battler)
{
    enum BattlerId partner = GetPartnerBattler(battler);
    enum Move partnerMove = gAiLogicData->partnerMove;

    if (!IsBattlerAlive(partner))
        return FALSE;

    if (!WillPartnerActBeforeOrAfter(battler, partner))
        return FALSE;

    if (gAiLogicData->partnerMoveSimulation)
        return HasMoveWithEffect(partner, EFFECT_FUSION_COMBO);

    if (GetMoveEffect(partnerMove) == EFFECT_FUSION_COMBO)
        return TRUE;

    return FALSE;
}

bool32 ShouldUseRound(enum BattlerId battler, enum BattleMoveEffects moveEffect)
{
    enum BattlerId partner = GetPartnerBattler(battler);
    enum Move partnerMove = gAiLogicData->partnerMove;

    if (!IsBattlerAlive(partner))
        return FALSE;

    // First battler check, so check moveset of partner
    if (gAiLogicData->partnerMoveSimulation)
        return HasMoveWithEffect(partner, moveEffect);

    // Check if partner actually chose the combo move
    if (GetMoveEffect(partnerMove) == moveEffect)
        return TRUE;

    return FALSE;
}

bool32 ShouldUsePledgeMove(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    enum BattlerId partner = GetPartnerBattler(battlerAtk);
    enum Move partnerMove = gAiLogicData->partnerMove;

    u32 atkSide = GetBattlerSide(battlerAtk);
    u32 defSide = GetBattlerSide(battlerDef);

    if (gAiLogicData->partnerMoveSimulation)
    {
        switch (move)
        {
        case MOVE_GRASS_PLEDGE:
            if (HasMove(partner, MOVE_FIRE_PLEDGE))
                return gSideTimers[defSide].seaOfFireTimer == 0;
            if (HasMove(partner, MOVE_WATER_PLEDGE))
                return gSideTimers[defSide].swampTimer == 0;
            break;
        case MOVE_FIRE_PLEDGE:
            if (HasMove(partner, MOVE_WATER_PLEDGE))
                return gSideTimers[atkSide].rainbowTimer == 0;
            if (HasMove(partner, MOVE_GRASS_PLEDGE))
                return gSideTimers[defSide].seaOfFireTimer == 0;
            break;
        case MOVE_WATER_PLEDGE:
            if (HasMove(partner, MOVE_GRASS_PLEDGE))
                return gSideTimers[defSide].swampTimer == 0;
            if (HasMove(partner, MOVE_FIRE_PLEDGE))
                return gSideTimers[atkSide].rainbowTimer == 0;
            break;
        default:
            break;
        }
    }
    else if (GetMoveEffect(partnerMove) == EFFECT_PLEDGE)
    {
        switch (move)
        {
        case MOVE_GRASS_PLEDGE:
            if (partnerMove == MOVE_FIRE_PLEDGE)
                return gSideTimers[defSide].seaOfFireTimer == 0;
            if (partnerMove == MOVE_WATER_PLEDGE)
                return gSideTimers[defSide].swampTimer == 0;
            break;
        case MOVE_FIRE_PLEDGE:
            if (partnerMove == MOVE_WATER_PLEDGE)
                return gSideTimers[atkSide].rainbowTimer == 0;
            if (partnerMove == MOVE_GRASS_PLEDGE)
                return gSideTimers[defSide].seaOfFireTimer == 0;
            break;
        case MOVE_WATER_PLEDGE:
            if (partnerMove == MOVE_GRASS_PLEDGE)
                return gSideTimers[defSide].swampTimer == 0;
            if (partnerMove == MOVE_FIRE_PLEDGE)
                return gSideTimers[atkSide].rainbowTimer == 0;
            break;
        default:
            break;
        }
    }

    return FALSE;
}
