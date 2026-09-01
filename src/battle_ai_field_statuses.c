#include "global.h"
#include "battle_z_move.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_field_statuses.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
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

static bool32 DoesAbilityBenefitFromWeather(enum Ability ability, u32 weather);
static bool32 DoesAbilityBenefitFromTerrain(enum Ability ability, enum BattleTerrain terrain);
// A move is light sensitive if it is boosted by Sunny Day and weakened by low light weathers.
static bool32 IsLightSensitiveMove(enum Move move);
static bool32 HasLightSensitiveMove(enum BattlerId battler);
// The following functions all feed into WeatherChecker, which is then called by ShouldSetWeather and ShouldClearWeather.
// BenefitsFrom functions all return FIELD_EFFECT_POSITIVE if the weather or field effect is good to have in place from the perspective of the battler, FIELD_EFFECT_NEUTRAL if it is neither good nor bad, and FIELD_EFFECT_NEGATIVE if it is bad.
// The purpose of WeatherChecker and FieldStatusChecker is to cleanly homogenize the logic that's the same with all of them, and to more easily apply single battle logic to double battles.
// ShouldSetWeather and ShouldClearWeather are looking for a positive or negative result respectively, and check the entire side.
// If one Pokémon has a positive result and the other has a negative result, it defaults to the opinion of the battler that may change the weather or field status.
static enum FieldEffectOutcome BenefitsFromSun(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromSandstorm(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromHailOrSnow(enum BattlerId battler, u32 weather);
static enum FieldEffectOutcome BenefitsFromRain(enum BattlerId battler);
// The following functions all feed into FieldStatusChecker, which is then called by ShouldSetFieldStatus and ShouldClearFieldStatus.
// They work approximately the same as the weather functions.
static enum FieldEffectOutcome BenefitsFromElectricTerrain(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromGrassyTerrain(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromMistyTerrain(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromPsychicTerrain(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromGravity(enum BattlerId battler);
static enum FieldEffectOutcome BenefitsFromTrickRoom(enum BattlerId battler);

static bool32 HasBattlerTerrainBoostMove(enum BattlerId battler, enum BattleTerrain terrain)
{
    if (!IsBattlerAlive(battler))
        return FALSE;

    enum Move *moves = GetMovesArray(battler);
    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        enum Move move = moves[moveIndex];
        if (GetMoveEffect(move) == EFFECT_TERRAIN_BOOST
         && GetMoveTerrainBoost_Terrain(move) == terrain)
            return TRUE;
    }

    return FALSE;
}

bool32 WeatherChecker(enum BattlerId battler, u32 weather, enum FieldEffectOutcome desiredResult)
{
    if (IsWeatherActive(B_WEATHER_PRIMAL_ANY) != WEATHER_INACTIVE)
        return (FIELD_EFFECT_BLOCKED == desiredResult);

    enum SideBattlers { USER, PARTNER, COUNT };

    enum SideBattlers sideBattlers = USER;
    enum FieldEffectOutcome result[COUNT] = { FIELD_EFFECT_NEUTRAL, FIELD_EFFECT_NEUTRAL };

    for (u32 battlerIndex = 0; battlerIndex < gBattlersCount; battlerIndex++)
    {
        if (!IsBattlerAlive(battlerIndex) || !IsBattlerAlly(battler, battlerIndex))
            continue;

        if (weather & B_WEATHER_RAIN)
            result[sideBattlers] = BenefitsFromRain(battlerIndex);
        else if (weather & B_WEATHER_SUN)
            result[sideBattlers] = BenefitsFromSun(battlerIndex);
        else if (weather & B_WEATHER_SANDSTORM)
            result[sideBattlers] = BenefitsFromSandstorm(battlerIndex);
        else if (weather & B_WEATHER_ICY_ANY)
            result[sideBattlers] = BenefitsFromHailOrSnow(battlerIndex, weather);

        sideBattlers = PARTNER;
    }

    return result[USER] == desiredResult || result[PARTNER] == desiredResult;
}

bool32 TerrainChecker(enum BattlerId battler, enum BattleTerrain terrain, enum FieldEffectOutcome desiredResult)
{
    enum FieldEffectOutcome result = FIELD_EFFECT_NEUTRAL;
    enum FieldEffectOutcome firstResult = FIELD_EFFECT_NEUTRAL;

    for (u32 battlerIndex = 0; battlerIndex < gBattlersCount; battlerIndex++)
    {
        if (!IsBattlerAlive(battlerIndex) || !IsBattlerAlly(battler, battlerIndex))
            continue;

        switch (terrain)
        {
        case B_TERRAIN_ELECTRIC:
            result = BenefitsFromElectricTerrain(battlerIndex);
            break;
        case B_TERRAIN_GRASSY:
            result = BenefitsFromGrassyTerrain(battlerIndex);
            break;
        case B_TERRAIN_MISTY:
            result = BenefitsFromMistyTerrain(battlerIndex);
            break;
        case B_TERRAIN_PSYCHIC:
            result = BenefitsFromPsychicTerrain(battlerIndex);
            break;
        default:
            break;
        }
    }

    if (firstResult != FIELD_EFFECT_NEUTRAL)
        return (firstResult == result) && (result == desiredResult);
    return (result == desiredResult);
}

bool32 FieldStatusChecker(enum BattlerId battler, u32 fieldStatus, enum FieldEffectOutcome desiredResult)
{
    enum FieldEffectOutcome result = FIELD_EFFECT_NEUTRAL;
    enum FieldEffectOutcome firstResult = FIELD_EFFECT_NEUTRAL;

    for (u32 battlerIndex = 0; battlerIndex < gBattlersCount; battlerIndex++)
    {
        if (!IsBattlerAlive(battlerIndex) || !IsBattlerAlly(battler, battlerIndex))
            continue;

        // other field statuses
        if (fieldStatus & STATUS_FIELD_GRAVITY)
            result = BenefitsFromGravity(battlerIndex);
        if (fieldStatus & STATUS_FIELD_TRICK_ROOM)
            result = BenefitsFromTrickRoom(battlerIndex);

        if (result != FIELD_EFFECT_NEUTRAL)
        {
            // Trick room wants both Pokémon to agree, not just one
            if (fieldStatus & STATUS_FIELD_TRICK_ROOM && battlerIndex == GetBattlerLeftFoe(battler))
                firstResult = result;
        }
    }
    if (firstResult != FIELD_EFFECT_NEUTRAL)
        return (firstResult == result) && (result == desiredResult);
    return (result == desiredResult);
}

static bool32 DoesAbilityBenefitFromWeather(enum Ability ability, u32 weather)
{
    switch (ability)
    {
    case ABILITY_FORECAST:
        return (weather & (B_WEATHER_RAIN | B_WEATHER_SUN | B_WEATHER_ICY_ANY));
    case ABILITY_MAGIC_GUARD:
    case ABILITY_OVERCOAT:
        return (weather & B_WEATHER_DAMAGING_ANY);
    case ABILITY_SAND_FORCE:
    case ABILITY_SAND_RUSH:
    case ABILITY_SAND_VEIL:
        return (weather & B_WEATHER_SANDSTORM);
    case ABILITY_ICE_BODY:
    case ABILITY_ICE_FACE:
    case ABILITY_SNOW_CLOAK:
    case ABILITY_SLUSH_RUSH:
        return (weather & B_WEATHER_ICY_ANY);
    case ABILITY_DRY_SKIN:
    case ABILITY_HYDRATION:
    case ABILITY_RAIN_DISH:
    case ABILITY_SWIFT_SWIM:
        return (weather & B_WEATHER_RAIN);
    case ABILITY_CHLOROPHYLL:
    case ABILITY_FLOWER_GIFT:
    case ABILITY_HARVEST:
    case ABILITY_LEAF_GUARD:
    case ABILITY_ORICHALCUM_PULSE:
    case ABILITY_PROTOSYNTHESIS:
    case ABILITY_SOLAR_POWER:
        return (weather & B_WEATHER_SUN);
    default:
        break;
    }
    return FALSE;
}

static bool32 DoesAbilityBenefitFromTerrain(enum Ability ability, enum BattleTerrain terrain)
{
    switch (ability)
    {
    case ABILITY_MIMICRY:
        return terrain != B_TERRAIN_NONE;
    case ABILITY_HADRON_ENGINE:
    case ABILITY_QUARK_DRIVE:
    case ABILITY_SURGE_SURFER:
        return terrain == B_TERRAIN_ELECTRIC;
    case ABILITY_GRASS_PELT:
        return terrain == B_TERRAIN_GRASSY;
    // no abilities inherently benefit from Misty or Psychic Terrains
    // return terrain == B_TERRAIN_MISTY;
    // return terrain == B_TERRAIN_PSYCHIC;
    default:
        break;
    }
    return FALSE;
}

static bool32 IsLightSensitiveMove(enum Move move)
{
    switch (GetMoveEffect(move))
    {
    case EFFECT_SOLAR_BEAM:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
    case EFFECT_GROWTH:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 HasLightSensitiveMove(enum BattlerId battler)
{
    enum Move *moves = GetMovesArray(battler);

    for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (moves[moveIndex] != MOVE_NONE && moves[moveIndex] != MOVE_UNAVAILABLE && IsLightSensitiveMove(moves[moveIndex]))
            return TRUE;
    }

    return FALSE;
}

// Sun
// Utility Umbrella does not block Protosynthesis, but it does block Orichalcum Pulse's Attack boost.
static enum FieldEffectOutcome BenefitsFromSun(enum BattlerId battler)
{
    enum Ability ability = gAiLogicData->abilities[battler];

    if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_UTILITY_UMBRELLA)
    {
        if (ability == ABILITY_PROTOSYNTHESIS)
            return FIELD_EFFECT_POSITIVE;
        else
            return FIELD_EFFECT_NEUTRAL;
    }

    if (DoesAbilityBenefitFromWeather(ability, B_WEATHER_SUN)
     || HasLightSensitiveMove(battler)
     || HasDamagingMoveOfType(battler, TYPE_FIRE)
     || HasMoveWithEffect(battler, EFFECT_WEATHER_BALL)
     || HasMoveWithEffect(battler, EFFECT_HYDRO_STEAM))
        return FIELD_EFFECT_POSITIVE;

    if (HasMoveWithFlag(battler, MoveHas50AccuracyInSun) || HasDamagingMoveOfType(battler, TYPE_WATER) || gAiLogicData->abilities[battler] == ABILITY_DRY_SKIN)
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_NEUTRAL;
}

// Sandstorm
static enum FieldEffectOutcome BenefitsFromSandstorm(enum BattlerId battler)
{
    if (DoesAbilityBenefitFromWeather(gAiLogicData->abilities[battler], B_WEATHER_SANDSTORM)
     || IS_BATTLER_OF_TYPE(battler, TYPE_ROCK)
     || HasMoveWithEffect(battler, EFFECT_WEATHER_BALL))
        return FIELD_EFFECT_POSITIVE;

    if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_SAFETY_GOGGLES || IS_BATTLER_ANY_TYPE(battler, TYPE_ROCK, TYPE_GROUND, TYPE_STEEL))
    {
        if (!IS_BATTLER_ANY_TYPE(GetBattlerLeftFoe(battler), TYPE_ROCK, TYPE_GROUND, TYPE_STEEL)
         && gAiLogicData->holdEffects[GetBattlerLeftFoe(battler)] != HOLD_EFFECT_SAFETY_GOGGLES
         && !DoesAbilityBenefitFromWeather(gAiLogicData->abilities[GetBattlerLeftFoe(battler)], B_WEATHER_SANDSTORM))
            return FIELD_EFFECT_POSITIVE;
        else
            return FIELD_EFFECT_NEUTRAL;
    }

    return FIELD_EFFECT_NEGATIVE;
}

// Hail or Snow
static enum FieldEffectOutcome BenefitsFromHailOrSnow(enum BattlerId battler, u32 weather)
{
    if (DoesAbilityBenefitFromWeather(gAiLogicData->abilities[battler], weather)
     || IS_BATTLER_OF_TYPE(battler, TYPE_ICE)
     || HasMoveWithEffect(battler, EFFECT_WEATHER_BALL)
     || HasMoveWithFlag(battler, MoveAlwaysHitsInHailSnow)
     || HasBattlerSideMoveWithEffect(battler, EFFECT_AURORA_VEIL))
        return FIELD_EFFECT_POSITIVE;

    if ((weather & B_WEATHER_DAMAGING_ANY) && gAiLogicData->holdEffects[battler] != HOLD_EFFECT_SAFETY_GOGGLES)
        return FIELD_EFFECT_NEGATIVE;

    if (HasLightSensitiveMove(battler))
        return FIELD_EFFECT_NEGATIVE;

    if (HasMoveWithFlag(GetBattlerLeftFoe(battler), MoveAlwaysHitsInHailSnow))
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_NEUTRAL;
}

// Rain
static enum FieldEffectOutcome BenefitsFromRain(enum BattlerId battler)
{
    if (gAiLogicData->holdEffects[battler] == HOLD_EFFECT_UTILITY_UMBRELLA)
        return FIELD_EFFECT_NEUTRAL;

    if (DoesAbilityBenefitFromWeather(gAiLogicData->abilities[battler], B_WEATHER_RAIN)
      || HasMoveWithFlag(battler, MoveAlwaysHitsInRain)
      || HasDamagingMoveOfType(battler, TYPE_WATER)
      || HasMoveWithEffect(battler, EFFECT_WEATHER_BALL)
      || HasMove(battler, MOVE_ELECTRO_SHOT))
        return FIELD_EFFECT_POSITIVE;

    if (HasLightSensitiveMove(battler) || HasDamagingMoveOfType(battler, TYPE_FIRE))
        return FIELD_EFFECT_NEGATIVE;

    if (HasMoveWithFlag(GetBattlerLeftFoe(battler), MoveAlwaysHitsInRain))
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_NEUTRAL;
}

//TODO: when is electric terrain bad?
static enum FieldEffectOutcome BenefitsFromElectricTerrain(enum BattlerId battler)
{
    if (DoesAbilityBenefitFromTerrain(gAiLogicData->abilities[battler], B_TERRAIN_ELECTRIC))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerTerrainBoostMove(battler, B_TERRAIN_ELECTRIC))
        return FIELD_EFFECT_POSITIVE;

    if ((HasMoveWithEffect(GetBattlerLeftFoe(battler), EFFECT_REST) && AI_IsBattlerGrounded(GetBattlerLeftFoe(battler)))
     || (HasMoveWithEffect(GetBattlerRightFoe(battler), EFFECT_REST) && AI_IsBattlerGrounded(GetBattlerRightFoe(battler))))
        return FIELD_EFFECT_POSITIVE;

    bool32 grounded = AI_IsBattlerGrounded(battler);
    if (grounded && HasBattlerSideMoveWithAdditionalEffect(GetBattlerLeftFoe(battler), MOVE_EFFECT_SLEEP))
        return FIELD_EFFECT_POSITIVE;

    if (grounded && ((gBattleMons[battler].status1 & STATUS1_SLEEP)
    || gBattleMons[battler].volatiles.yawn
    || HasDamagingMoveOfType(battler, TYPE_ELECTRIC)))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerTerrainBoostMove(GetBattlerLeftFoe(battler), B_TERRAIN_ELECTRIC)
     || HasBattlerTerrainBoostMove(GetBattlerRightFoe(battler), B_TERRAIN_ELECTRIC))
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_NEUTRAL;
}

//TODO: when is grassy terrain bad?
static enum FieldEffectOutcome BenefitsFromGrassyTerrain(enum BattlerId battler)
{
    if (DoesAbilityBenefitFromTerrain(gAiLogicData->abilities[battler], B_TERRAIN_GRASSY))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerSideMoveWithEffect(battler, EFFECT_GRASSY_GLIDE))
        return FIELD_EFFECT_POSITIVE;
    if (HasMoveWithAdditionalEffect(battler, MOVE_EFFECT_FLORAL_HEALING))
        return FIELD_EFFECT_POSITIVE;

    bool32 grounded = AI_IsBattlerGrounded(battler);

    // Weaken spamming Earthquake, Magnitude, and Bulldoze.
    if (grounded && (HasBattlerSideMoveWithEffect(GetBattlerLeftFoe(battler), EFFECT_EARTHQUAKE)
    || HasBattlerSideMoveWithEffect(GetBattlerLeftFoe(battler), EFFECT_MAGNITUDE)))
        return FIELD_EFFECT_POSITIVE;

    if (grounded && HasDamagingMoveOfType(battler, TYPE_GRASS))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerSideMoveWithEffect(GetBattlerLeftFoe(battler), EFFECT_GRASSY_GLIDE))
        return FIELD_EFFECT_NEGATIVE;


    return FIELD_EFFECT_NEUTRAL;
}

//TODO: when is misty terrain bad?
static enum FieldEffectOutcome BenefitsFromMistyTerrain(enum BattlerId battler)
{
    if (DoesAbilityBenefitFromTerrain(gAiLogicData->abilities[battler], B_TERRAIN_MISTY))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerTerrainBoostMove(battler, B_TERRAIN_MISTY)
     || HasBattlerTerrainBoostMove(GetPartnerBattler(battler), B_TERRAIN_MISTY))
        return FIELD_EFFECT_POSITIVE;

    bool32 grounded = AI_IsBattlerGrounded(battler);
    bool32 allyGrounded = FALSE;
    if (HasPartner(battler))
        allyGrounded = AI_IsBattlerGrounded(GetPartnerBattler(battler));

    if ((HasMoveWithEffect(GetBattlerLeftFoe(battler), EFFECT_REST) && AI_IsBattlerGrounded(GetBattlerLeftFoe(battler)))
     || (HasMoveWithEffect(GetBattlerRightFoe(battler), EFFECT_REST) && AI_IsBattlerGrounded(GetBattlerRightFoe(battler))))
        return FIELD_EFFECT_POSITIVE;

    // harass dragons
    if ((grounded || allyGrounded)
     && (HasDamagingMoveOfType(GetBattlerLeftFoe(battler), TYPE_DRAGON) || HasDamagingMoveOfType(GetBattlerRightFoe(battler), TYPE_DRAGON)))
        return FIELD_EFFECT_POSITIVE;

    if ((grounded || allyGrounded)
     && (HasNonVolatileMoveEffect(GetBattlerLeftFoe(battler), MOVE_EFFECT_SLEEP) || HasNonVolatileMoveEffect(GetBattlerRightFoe(battler), MOVE_EFFECT_SLEEP)))
        return FIELD_EFFECT_POSITIVE;

    if (grounded && (gBattleMons[battler].status1 & STATUS1_SLEEP || gBattleMons[battler].volatiles.yawn))
        return FIELD_EFFECT_POSITIVE;

    return FIELD_EFFECT_NEUTRAL;
}

//TODO: when is Psychic Terrain negative?
static enum FieldEffectOutcome BenefitsFromPsychicTerrain(enum BattlerId battler)
{
    if (DoesAbilityBenefitFromTerrain(gAiLogicData->abilities[battler], B_TERRAIN_PSYCHIC))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerTerrainBoostMove(battler, B_TERRAIN_PSYCHIC)
     || HasBattlerTerrainBoostMove(GetPartnerBattler(battler), B_TERRAIN_PSYCHIC))
        return FIELD_EFFECT_POSITIVE;

    bool32 grounded = AI_IsBattlerGrounded(battler);
    bool32 allyGrounded = FALSE;
    if (HasPartner(battler))
        allyGrounded = AI_IsBattlerGrounded(GetPartnerBattler(battler));

    // don't bother if we're not grounded
    if (grounded || allyGrounded)
    {
        // harass priority
        if (AI_IsAbilityOnSide(GetBattlerLeftFoe(battler), ABILITY_GALE_WINGS)
         || AI_IsAbilityOnSide(GetBattlerLeftFoe(battler), ABILITY_TRIAGE)
         || AI_IsAbilityOnSide(GetBattlerLeftFoe(battler), ABILITY_PRANKSTER))
            return FIELD_EFFECT_POSITIVE;
    }

    if (grounded && HasDamagingMoveOfType(battler, TYPE_PSYCHIC))
        return FIELD_EFFECT_POSITIVE;

    if (HasBattlerTerrainBoostMove(GetBattlerLeftFoe(battler), B_TERRAIN_PSYCHIC)
     || HasBattlerTerrainBoostMove(GetBattlerRightFoe(battler), B_TERRAIN_PSYCHIC))
        return FIELD_EFFECT_NEGATIVE;

    if (AI_IsAbilityOnSide(battler, ABILITY_GALE_WINGS)
     || AI_IsAbilityOnSide(battler, ABILITY_TRIAGE)
     || AI_IsAbilityOnSide(battler, ABILITY_PRANKSTER))
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_NEUTRAL;
}

static enum FieldEffectOutcome BenefitsFromGravity(enum BattlerId battler)
{
    if (!AI_IsBattlerGrounded(battler))
        return FIELD_EFFECT_NEGATIVE;

    if (AI_IsAbilityOnSide(battler, ABILITY_HUSTLE))
        return FIELD_EFFECT_POSITIVE;

    if (HasMoveWithFlag(battler, IsMoveGravityBanned))
        return FIELD_EFFECT_NEGATIVE;

    if (IsBattlerAlive(GetBattlerLeftFoe(battler)))
    {
        if (HasMoveWithLowAccuracy(battler, GetBattlerLeftFoe(battler), LOW_ACCURACY_THRESHOLD, FALSE)
         || (!AI_IsBattlerGrounded(GetBattlerLeftFoe(battler)) && HasDamagingMoveOfType(battler, TYPE_GROUND)))
            return FIELD_EFFECT_POSITIVE;
    }

    if (IsBattlerAlive(GetBattlerRightFoe(battler)))
    {
        if (HasMoveWithLowAccuracy(battler, GetBattlerRightFoe(battler), LOW_ACCURACY_THRESHOLD, FALSE)
         || (!AI_IsBattlerGrounded(GetBattlerRightFoe(battler)) && HasDamagingMoveOfType(battler, TYPE_GROUND)))
            return FIELD_EFFECT_POSITIVE;
    }

    return FIELD_EFFECT_NEUTRAL;
}

static enum FieldEffectOutcome BenefitsFromTrickRoom(enum BattlerId battler)
{
    // If we're in singles, we literally only care about speed.
    if (IsBattle1v1())
    {
        if (gAiLogicData->speedStats[battler] < gAiLogicData->speedStats[GetBattlerLeftFoe(battler)])
            return FIELD_EFFECT_POSITIVE;
        // If we tie, we shouldn't change trick room state.
        else if (gAiLogicData->speedStats[battler] == gAiLogicData->speedStats[GetBattlerLeftFoe(battler)])
            return FIELD_EFFECT_NEUTRAL;
        else
            return FIELD_EFFECT_NEGATIVE;
    }

    // First checking if we have enough priority for one Pokémon to disregard Trick Room entirely.
    if (gFieldTimers.terrain != B_TERRAIN_PSYCHIC)
    {
        enum Move *aiMoves = GetMovesArray(battler);
        for (u32 moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            enum Move move = aiMoves[moveIndex];
            if (GetBattleMovePriority(battler, gAiLogicData->abilities[battler], move) > 0 && !(GetMovePriority(move) > 0 && IsBattleMoveStatus(move)))
            {
                return FIELD_EFFECT_POSITIVE;
            }
        }
    }

    // If we are faster or tie, we don't want trick room.
    if ((gAiLogicData->speedStats[battler] >= gAiLogicData->speedStats[GetBattlerLeftFoe(battler)]) || (gAiLogicData->speedStats[battler] >= gAiLogicData->speedStats[GetBattlerRightFoe(battler)]))
        return FIELD_EFFECT_NEGATIVE;

    return FIELD_EFFECT_POSITIVE;
}

s32 CalcWeatherScore(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, struct AiLogicData *aiData)
{
    s32 score = 0;

    switch (GetMoveWeatherType(move))
    {
    case BATTLE_WEATHER_RAIN:
        if (ShouldSetWeather(battlerAtk, B_WEATHER_RAIN))
        {
            score += DECENT_EFFECT;

            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_WEATHER_BALL))
                score += WEAK_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_DAMP_ROCK)
                score += WEAK_EFFECT;
            if (HasBattlerSideMoveWithEffect(battlerDef, EFFECT_MORNING_SUN)
             || HasBattlerSideMoveWithEffect(battlerDef, EFFECT_SYNTHESIS)
             || HasBattlerSideMoveWithEffect(battlerDef, EFFECT_SOLAR_BEAM)
             || HasBattlerSideMoveWithEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
            if (HasDamagingMoveOfType(battlerDef, TYPE_FIRE) || HasDamagingMoveOfType(GetPartnerBattler(battlerDef), TYPE_FIRE))
                score += WEAK_EFFECT;
        }
        break;
    case BATTLE_WEATHER_SUN:
        if (ShouldSetWeather(battlerAtk, B_WEATHER_SUN))
        {
            score += DECENT_EFFECT;

            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_WEATHER_BALL))
                score += WEAK_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_HEAT_ROCK)
                score += WEAK_EFFECT;
            if (HasDamagingMoveOfType(battlerDef, TYPE_WATER) || HasDamagingMoveOfType(GetPartnerBattler(battlerDef), TYPE_WATER))
                score += WEAK_EFFECT;
            if (HasMoveWithFlag(battlerDef, MoveHas50AccuracyInSun) || HasMoveWithFlag(GetPartnerBattler(battlerDef), MoveHas50AccuracyInSun))
                score += WEAK_EFFECT;
        }
        break;
    case BATTLE_WEATHER_SANDSTORM:
        if (ShouldSetWeather(battlerAtk, B_WEATHER_SANDSTORM))
        {
            score += DECENT_EFFECT;

            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_WEATHER_BALL))
                score += WEAK_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_SMOOTH_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveWithEffect(battlerDef, EFFECT_MORNING_SUN)
             || HasMoveWithEffect(battlerDef, EFFECT_SYNTHESIS)
             || HasMoveWithEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
        }
        break;
    case BATTLE_WEATHER_HAIL:
        if (ShouldSetWeather(battlerAtk, B_WEATHER_HAIL))
        {
            score += DECENT_EFFECT;

            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_AURORA_VEIL) && ShouldSetScreen(battlerAtk, battlerDef, EFFECT_AURORA_VEIL))
                score += GOOD_EFFECT;
            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_WEATHER_BALL))
                score += WEAK_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_ICY_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveWithEffect(battlerDef, EFFECT_MORNING_SUN)
             || HasMoveWithEffect(battlerDef, EFFECT_SYNTHESIS)
             || HasMoveWithEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
        }
        break;
    case BATTLE_WEATHER_SNOW:
        if (ShouldSetWeather(battlerAtk, B_WEATHER_SNOW))
        {
            score += DECENT_EFFECT;

            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_AURORA_VEIL) && ShouldSetScreen(battlerAtk, battlerDef, EFFECT_AURORA_VEIL))
                score += GOOD_EFFECT;
            if (HasBattlerSideMoveWithEffect(battlerAtk, EFFECT_WEATHER_BALL))
                score += WEAK_EFFECT;
            if (aiData->holdEffects[battlerAtk] == HOLD_EFFECT_ICY_ROCK)
                score += WEAK_EFFECT;
            if (HasMoveWithEffect(battlerDef, EFFECT_MORNING_SUN)
             || HasMoveWithEffect(battlerDef, EFFECT_SYNTHESIS)
             || HasMoveWithEffect(battlerDef, EFFECT_MOONLIGHT))
                score += WEAK_EFFECT;
        }
        break;
    default:
        break;
    }

    return score;
}
