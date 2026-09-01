#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_anim_scripts.h"
#include "battle_arena.h"
#include "battle_environment.h"
#include "battle_pyramid.h"
#include "battle_util.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "battle_hold_effects.h"
#include "battle_stat_change.h"
#include "config_changes.h"
#include "party_menu.h"
#include "pokemon.h"
#include "international_string_util.h"
#include "item.h"
#include "util.h"
#include "battle_scripts.h"
#include "random.h"
#include "text.h"
#include "safari_zone.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "test_runner.h"
#include "trig.h"
#include "trainer_slide.h"
#include "window.h"
#include "battle_message.h"
#include "battle_ai_record.h"
#include "battle_ai_util.h"
#include "event_data.h"
#include "link.h"
#include "malloc.h"
#include "berry.h"
#include "pokedex.h"
#include "mail.h"
#include "field_weather.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/weather.h"
#include "constants/pokemon.h"
#include "test/battle.h"

static bool32 TryRemoveScreens(enum BattlerId battler);
static bool32 IsUnnerveAbilityOnOpposingSide(enum BattlerId battler);
static u32 GetFlingPowerFromItemId(enum Item itemId);
static bool32 IsNonVolatileStatusBlocked(enum BattlerId battlerDef, enum Ability abilityDef, bool32 abilityAffected, const u8 *battleScript, enum ResultOption option);
static bool32 CanSleepDueToSleepClause(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum ResultOption option);
static bool32 IsOpposingSideEmpty(enum BattlerId battler);
static void ResetParadoxWeatherStat(enum BattlerId battler);
static void ResetParadoxTerrainStat(enum BattlerId battler);
static bool32 CanBattlerFormChange(enum BattlerId battler, enum FormChanges method);
const u8 *AbsorbedByDrainHpAbility(enum BattlerId battlerDef);
const u8 *AbsorbedByStatIncreaseAbility(struct DamageContext *ctx, enum Stat statId, u32 statAmount);
const u8 *AbsorbedByFlashFire(struct DamageContext *ctx);
static bool32 IsCriticalHit(struct DamageContext *ctx);

ARM_FUNC NOINLINE static uq4_12_t PercentToUQ4_12(u32 percent);
ARM_FUNC NOINLINE static uq4_12_t PercentToUQ4_12_Floored(u32 percent);

extern const u8 *const gBattlescriptsForRunningByItem[];
extern const u8 *const gBattlescriptsForUsingItem[];
extern const u8 *const gBattlescriptsForSafariActions[];

enum BattlerId GetBattlerAtPosition(enum BattlerPosition position)
{
    enum BattlerId battler;
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (GetBattlerPosition(battler) == position)
            break;
    }
    return battler;
}

enum BattlerPosition GetPartnerPosition(enum BattlerPosition position)
{
    return (position ^ BIT_FLANK);
}

enum BattlerPosition GetOppositePosition(enum BattlerPosition position)
{
    return (position ^ BIT_SIDE);
}

enum BattlerId GetPartnerBattler(enum BattlerId battler)
{
    return GetBattlerAtPosition(GetPartnerPosition(GetBattlerPosition(battler)));
}

enum BattlerId GetOppositeBattler(enum BattlerId battler)
{
    return GetBattlerAtPosition(GetOppositePosition(GetBattlerPosition(battler)));
}

// Left and right are determined by how they're referred to in tests and everywhere else.
// Left is battlers 0 and 1, right 2 and 3; if you assume the battler referencing them is south, left is to the northeast and right to the northwest.
enum BattlerId GetBattlerLeftFoe(enum BattlerId battler)
{
    return GetBattlerAtPosition(GetOppositePosition((enum BattlerPosition)GetBattlerSide(battler)));
}

enum BattlerId GetBattlerRightFoe(enum BattlerId battler)
{
    return GetPartnerBattler(GetBattlerLeftFoe(battler));
}

enum BattlerId GetDefaultSelectionTarget(enum BattlerId battler, enum MoveTarget moveTarget)
{
    switch (moveTarget)
    {
    case TARGET_USER:
    case TARGET_USER_OR_ALLY:
    case TARGET_USER_AND_ALLY:
        return battler;
    case TARGET_ALLY:
        return GetPartnerBattler(battler);
    default:
        return GetBattlerLeftFoe(battler);
    }
}

static const u8 sPkblToEscapeFactor[][3] = {
    {
        [B_MSG_MON_CURIOUS]    = 0,
        [B_MSG_MON_ENTHRALLED] = 0,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 3,
        [B_MSG_MON_ENTHRALLED] = 5,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 2,
        [B_MSG_MON_ENTHRALLED] = 3,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 2,
        [B_MSG_MON_IGNORED]    = 0
    },{
        [B_MSG_MON_CURIOUS]    = 1,
        [B_MSG_MON_ENTHRALLED] = 1,
        [B_MSG_MON_IGNORED]    = 0
    }
};
static const u8 sGoNearCounterToCatchFactor[] = {4, 3, 2, 1};
static const u8 sGoNearCounterToEscapeFactor[] = {4, 4, 4, 4};

const struct BattleWeatherInfo gBattleWeatherInfo[BATTLE_WEATHER_COUNT] = {
    [BATTLE_WEATHER_RAIN] =
    {
        .flag = B_WEATHER_RAIN_NORMAL,
        .rock = HOLD_EFFECT_DAMP_ROCK,
        .abilityStartMessage = B_MSG_STARTED_DRIZZLE,
        .moveStartMessage = B_MSG_STARTED_RAIN,
        .endMessage = B_MSG_WEATHER_END_RAIN,
        .continuesMessage = B_MSG_WEATHER_TURN_RAIN,
        .animation = B_ANIM_RAIN_CONTINUES,
        .type = BATTLE_WEATHER_RAIN,
    },

    [BATTLE_WEATHER_RAIN_PRIMAL] =
    {
        .flag = B_WEATHER_RAIN_PRIMAL,
        .rock = HOLD_EFFECT_DAMP_ROCK,
        .abilityStartMessage = B_MSG_STARTED_PRIMORDIAL_SEA,
        .moveStartMessage = B_MSG_STARTED_RAIN, // Placeholder
        .endMessage = B_MSG_WEATHER_END_RAIN,
        .continuesMessage = B_MSG_WEATHER_TURN_RAIN,
        .animation = B_ANIM_RAIN_CONTINUES,
        .type = BATTLE_WEATHER_RAIN,
    },

    [BATTLE_WEATHER_RAIN_DOWNPOUR] =
    {
        .flag = B_WEATHER_RAIN_NORMAL,
        .rock = HOLD_EFFECT_DAMP_ROCK,
        .abilityStartMessage = B_MSG_STARTED_DRIZZLE,
        .moveStartMessage = B_MSG_STARTED_RAIN,
        .endMessage = B_MSG_WEATHER_END_RAIN,
        .continuesMessage = B_MSG_WEATHER_TURN_DOWNPOUR,
        .animation = B_ANIM_RAIN_CONTINUES,
        .type = BATTLE_WEATHER_RAIN,
    },

    [BATTLE_WEATHER_SUN] =
    {
        .flag = B_WEATHER_SUN_NORMAL,
        .rock = HOLD_EFFECT_HEAT_ROCK,
        .abilityStartMessage = B_MSG_STARTED_DROUGHT,
        .moveStartMessage = B_MSG_STARTED_SUNLIGHT,
        .endMessage = B_MSG_WEATHER_END_SUN,
        .continuesMessage = B_MSG_WEATHER_TURN_SUN,
        .animation = B_ANIM_SUN_CONTINUES,
        .type = BATTLE_WEATHER_SUN,
    },

    [BATTLE_WEATHER_SUN_PRIMAL] =
    {
        .flag = B_WEATHER_SUN_PRIMAL,
        .rock = HOLD_EFFECT_HEAT_ROCK,
        .abilityStartMessage = B_MSG_STARTED_DESOLATE_LAND,
        .moveStartMessage = B_MSG_STARTED_SUNLIGHT, // Placeholder
        .endMessage = B_MSG_WEATHER_END_SUN,
        .continuesMessage = B_MSG_WEATHER_TURN_SUN,
        .animation = B_ANIM_SUN_CONTINUES,
        .type = BATTLE_WEATHER_SUN,
    },

    [BATTLE_WEATHER_SANDSTORM] =
    {
        .flag = B_WEATHER_SANDSTORM,
        .rock = HOLD_EFFECT_SMOOTH_ROCK,
        .abilityStartMessage = B_MSG_STARTED_SAND_STREAM,
        .moveStartMessage = B_MSG_STARTED_SANDSTORM,
        .endMessage = B_MSG_WEATHER_END_SANDSTORM,
        .continuesMessage = B_MSG_WEATHER_TURN_SANDSTORM,
        .animation = B_ANIM_SANDSTORM_CONTINUES,
        .type = BATTLE_WEATHER_SANDSTORM,
    },

    [BATTLE_WEATHER_HAIL] =
    {
        .flag = B_WEATHER_HAIL,
        .rock = HOLD_EFFECT_ICY_ROCK,
        .abilityStartMessage = B_MSG_STARTED_HAIL_WARNING,
        .moveStartMessage = B_MSG_STARTED_HAIL,
        .endMessage = B_MSG_WEATHER_END_HAIL,
        .continuesMessage = B_MSG_WEATHER_TURN_HAIL,
        .animation = B_ANIM_HAIL_CONTINUES,
        .type = BATTLE_WEATHER_SNOW,
    },

    [BATTLE_WEATHER_SNOW] =
    {
        .flag = B_WEATHER_SNOW,
        .rock = HOLD_EFFECT_ICY_ROCK,
        .abilityStartMessage = B_MSG_STARTED_SNOW_WARNING,
        .moveStartMessage = B_MSG_STARTED_SNOW,
        .endMessage = B_MSG_WEATHER_END_SNOW,
        .continuesMessage = B_MSG_WEATHER_TURN_SNOW,
        .animation = B_ANIM_SNOW_CONTINUES,
        .type = BATTLE_WEATHER_SNOW,
    },

    [BATTLE_WEATHER_FOG] =
    {
        .flag = B_WEATHER_FOG,
        .rock = HOLD_EFFECT_NONE,
        .abilityStartMessage = B_MSG_STARTED_DRIZZLE, // Placeholder
        .moveStartMessage = B_MSG_STARTED_FOG, // Placeholder
        .endMessage = B_MSG_WEATHER_END_FOG,
        .continuesMessage = B_MSG_WEATHER_TURN_FOG,
        .animation = B_ANIM_FOG_CONTINUES,
        .type = BATTLE_WEATHER_FOG,
    },

    [BATTLE_WEATHER_STRONG_WINDS] =
    {
        .flag = B_WEATHER_STRONG_WINDS,
        .rock = HOLD_EFFECT_NONE,
        .abilityStartMessage = B_MSG_STARTED_STRONG_WINDS,
        .moveStartMessage = B_MSG_STARTED_RAIN, // Placeholder
        .endMessage = B_MSG_WEATHER_END_STRONG_WINDS,
        .continuesMessage = B_MSG_WEATHER_TURN_STRONG_WINDS,
        .animation = B_ANIM_STRONG_WINDS,
        .type = BATTLE_WEATHER_STRONG_WINDS,
    },
};

enum BattleWeather GetBattleWeather(u32 weather)
{
    u32 currBattleWeather = BATTLE_WEATHER_NONE;

    for (u32 i = 0; i < ARRAY_COUNT(gBattleWeatherInfo); i++)
    {
        if (weather & gBattleWeatherInfo[i].flag)
        {
            currBattleWeather = i;
            break;
        }
    }

    return currBattleWeather;
}

const struct TerrainInfo gBattleTerrainInfo[B_TERRAIN_COUNT] = {
    [B_TERRAIN_GRASSY] = {
        .type = TYPE_GRASS,
        .secretPowerAnimation = gBattleAnimMove_NeedleArm,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .naturePowerMove = MOVE_ENERGY_BALL,
        .battleBackground = BG_GRASSY_TERRAIN,
        .seedStat = STAT_DEF,
        .seedHoldEffect = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .startMessage = B_MSG_TERRAIN_SET_GRASSY,
        .endMessage = B_MSG_TERRAIN_END_GRASSY,
    },

    [B_TERRAIN_MISTY] = {
        .type = TYPE_FAIRY,
        .secretPowerAnimation = gBattleAnimMove_FairyWind,
        .secretPowerEffect = SECRET_POWER_SP_ATK_MINUS_1,
        .naturePowerMove = MOVE_MOONBLAST,
        .battleBackground = BG_MISTY_TERRAIN,
        .seedStat = STAT_SPDEF,
        .seedHoldEffect = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .startMessage = B_MSG_TERRAIN_SET_MISTY,
        .endMessage = B_MSG_TERRAIN_END_MISTY,
    },

    [B_TERRAIN_ELECTRIC] = {
        .type = TYPE_ELECTRIC,
        .secretPowerAnimation = gBattleAnimMove_ThunderShock,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .naturePowerMove = MOVE_THUNDERBOLT,
        .battleBackground = BG_ELECTRIC_TERRAIN,
        .seedStat = STAT_DEF,
        .seedHoldEffect = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .startMessage = B_MSG_TERRAIN_SET_ELECTRIC,
        .endMessage = B_MSG_TERRAIN_END_ELECTRIC,
    },

    [B_TERRAIN_PSYCHIC] = {
        .type = TYPE_PSYCHIC,
        .secretPowerAnimation = gBattleAnimMove_Confusion,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .naturePowerMove = MOVE_PSYCHIC,
        .battleBackground = BG_PSYCHIC_TERRAIN,
        .seedStat = STAT_SPDEF,
        .seedHoldEffect = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .startMessage = B_MSG_TERRAIN_SET_PSYCHIC,
        .endMessage = B_MSG_TERRAIN_END_PSYCHIC,
    },
};

bool32 EndOrContinueWeather(void)
{
    enum BattleWeather currBattleWeather = GetBattleWeather(gBattleWeather);

    if (currBattleWeather == BATTLE_WEATHER_NONE)
        return FALSE;

    if (gBattleStruct->weatherDuration > 0 && --gBattleStruct->weatherDuration == 0)
    {
        gBattleWeather = B_WEATHER_NONE;
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            gBattleMons[battler].volatiles.weatherAbilityDone = FALSE;
            ResetParadoxWeatherStat(battler);
        }
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleWeatherInfo[currBattleWeather].endMessage;
        BattleScriptCall(BattleScript_WeatherFaded);
        return TRUE;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleWeatherInfo[currBattleWeather].continuesMessage;
        gBattleScripting.animArg1 = gBattleWeatherInfo[currBattleWeather].animation;
        BattleScriptCall(BattleScript_WeatherContinues);
        return TRUE;
    }

    return FALSE;
}

// Gen5+
static u32 CalcBeatUpPower(void)
{
    enum Species species = gBattleStruct->beatUpSpecies[gBattleStruct->beatUpSlot++];
    // FIXME: Why call CalcBeatUpPower when 'beatUpSlot' is OOB?
    if (species == 0xFFFF)
        return 0;
    return (GetSpeciesBaseAttack(species) / 10) + 5;
}

// Gen 3/4
static s32 CalcBeatUpDamage(struct DamageContext *ctx)
{
    u32 partyIndex = gBattleStruct->beatUpSpecies[gBattleStruct->beatUpSlot++];
    struct Pokemon *party = GetBattlerParty(ctx->battlerAtk);
    enum Species species = GetMonData(&party[partyIndex], MON_DATA_SPECIES);
    u32 levelFactor = GetMonData(&party[partyIndex], MON_DATA_LEVEL) * 2 / 5 + 2;
    s32 dmg = GetSpeciesBaseAttack(species);

    dmg *= GetMovePower(ctx->move);
    dmg *= levelFactor;
    dmg /= GetSpeciesBaseDefense(gBattleMons[ctx->battlerDef].species);
    dmg = (dmg / 50) + 2;

    if (gProtectStructs[ctx->battlerAtk].helpingHand)
        dmg = dmg * 15 / 10;
    if (ctx->isCrit)
        dmg *= 2;

    return dmg;
}

enum DamageCategory GetReflectDamageMoveDamageCategory(enum BattlerId battler, enum Move move)
{
    u32 damageCategories = GetMoveReflectDamage_DamageCategories(move);

    if (damageCategories == 1u << DAMAGE_CATEGORY_PHYSICAL) // Counter
        return DAMAGE_CATEGORY_PHYSICAL;
    if (damageCategories == 1u << DAMAGE_CATEGORY_SPECIAL) // Mirror Coat
        return DAMAGE_CATEGORY_SPECIAL;

    // Metal Burst / Comeuppance
    if (gProtectStructs[battler].lastHitBySpecialMove)
        return DAMAGE_CATEGORY_SPECIAL;
    else
        return DAMAGE_CATEGORY_PHYSICAL;
}

bool32 ShouldTeraShellDistortTypeMatchups(struct DamageContext *ctx)
{
    if (ctx->abilities[ctx->battlerDef] == ABILITY_TERA_SHELL
     && gBattleMons[ctx->battlerDef].species == SPECIES_TERAPAGOS_TERASTAL
     && gBattleMons[ctx->battlerDef].hp == gBattleMons[ctx->battlerDef].maxHP
     && !IsBattleMoveStatus(ctx->move))
        return TRUE;

    return FALSE;
}

bool32 IsUnnerveBlocked(enum BattlerId battler, enum Item itemId)
{
    if (GetItemPocket(itemId) != POCKET_BERRIES)
        return FALSE;

    if (gBattleScripting.overrideBerryRequirements > 0) // Berries that aren't eaten naturally ignore unnerve
        return FALSE;

    if (IsUnnerveAbilityOnOpposingSide(battler))
        return TRUE;

    return FALSE;
}

static bool32 IsUnnerveAbilityOnOpposingSide(enum BattlerId battler)
{
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (battler == battlerDef || IsBattlerAlly(battler, battlerDef))
            continue;

        enum Ability ability = GetBattlerAbility(battlerDef);
        switch (ability)
        {
        case ABILITY_UNNERVE:
        case ABILITY_AS_ONE_ICE_RIDER:
        case ABILITY_AS_ONE_SHADOW_RIDER:
            return TRUE;
        default:
            break;
        }
    }

    return FALSE;
}

// Functions
void HandleAction_UseMove(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (!IsBattlerAlive(gBattlerAttacker)
     || gBattleStruct->battlerState[gBattlerAttacker].commandingDondozo)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gCurrMovePos = gChosenMovePos = gBattleStruct->chosenMovePositions[gBattlerAttacker];

    // choose move
    if (gProtectStructs[gBattlerAttacker].noValidMoves)
    {
        gProtectStructs[gBattlerAttacker].noValidMoves = FALSE;
        gCurrentMove = gChosenMove = MOVE_STRUGGLE;
        gBattleStruct->moveTarget[gBattlerAttacker] = GetBattleMoveTarget(MOVE_STRUGGLE, TARGET_NONE);
    }
    else if (gBattleMons[gBattlerAttacker].volatiles.multipleTurns || gBattleMons[gBattlerAttacker].volatiles.rechargeTimer > 0)
    {
        gCurrentMove = gChosenMove = gLockedMoves[gBattlerAttacker];
    }
    // encore forces you to use the same move
    else if (GetActiveGimmick(gBattlerAttacker) != GIMMICK_Z_MOVE && gBattleMons[gBattlerAttacker].volatiles.encoredMove != MOVE_NONE
             && gBattleMons[gBattlerAttacker].volatiles.encoredMove == gBattleMons[gBattlerAttacker].moves[gBattleMons[gBattlerAttacker].volatiles.encoredMovePos])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].volatiles.encoredMove;
        gCurrMovePos = gChosenMovePos = gBattleMons[gBattlerAttacker].volatiles.encoredMovePos;
        if (GetConfig(B_ENCORE_TARGET) < GEN_5)
            gBattleStruct->moveTarget[gBattlerAttacker] = GetBattleMoveTarget(gCurrentMove, TARGET_NONE);
    }
    // check if the encored move wasn't overwritten
    else if (GetActiveGimmick(gBattlerAttacker) != GIMMICK_Z_MOVE && gBattleMons[gBattlerAttacker].volatiles.encoredMove != MOVE_NONE
          && gBattleMons[gBattlerAttacker].volatiles.encoredMove != gBattleMons[gBattlerAttacker].moves[gBattleMons[gBattlerAttacker].volatiles.encoredMovePos])
    {
        gCurrMovePos = gChosenMovePos = gBattleMons[gBattlerAttacker].volatiles.encoredMovePos;
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gBattleMons[gBattlerAttacker].volatiles.encoredMove = MOVE_NONE;
        gBattleMons[gBattlerAttacker].volatiles.encoredMovePos = 0;
        gBattleMons[gBattlerAttacker].volatiles.encoreTimer = 0;
        gBattleStruct->moveTarget[gBattlerAttacker] = GetBattleMoveTarget(gCurrentMove, TARGET_NONE);
    }
    else if (gBattleMons[gBattlerAttacker].moves[gCurrMovePos] != gChosenMoveByBattler[gBattlerAttacker])
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
        gBattleStruct->moveTarget[gBattlerAttacker] = GetBattleMoveTarget(gCurrentMove, TARGET_NONE);
    }
    else
    {
        gCurrentMove = gChosenMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
    }

    if (IsBattlerAlive(gBattlerAttacker))
    {
        if (IsOnPlayerSide(gBattlerAttacker))
            gBattleResults.lastUsedMovePlayer = gCurrentMove;
        else
            gBattleResults.lastUsedMoveOpponent = gCurrentMove;
    }

    SetTypeBeforeUsingMove(gChosenMove, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker));
    gBattleStruct->baseMove = gCurrentMove;

    // check Z-Move used
    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE
     && GetMoveCategory(gCurrentMove) != DAMAGE_CATEGORY_STATUS // Check the actual type, not the dynamic one
     && !IsZMove(gCurrentMove))
    {
        gCurrentMove = gChosenMove = GetUsableZMove(gBattlerAttacker, gCurrentMove);
    }
    // check Max Move used
    else if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_DYNAMAX)
    {
        gCurrentMove = gChosenMove = GetMaxMove(gBattlerAttacker, gCurrentMove);
    }

    gBattleStruct->eventState.atkCanceler = 0;
    ClearDamageCalcResults();
    ClearBothStatChangeQueues();
    gMultiHitCounter = 0;
    gBattlerTarget = gBattleStruct->moveTarget[gBattlerAttacker];

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE && gProtectStructs[gBattlerAttacker].palaceUnableToUseMove)
    {
        // Battle Palace, select battle script for failure to use move
        if (!IsBattlerAlive(gBattlerAttacker))
        {
            gCurrentActionFuncId = B_ACTION_FINISHED;
            return;
        }
        else if (gPalaceSelectionBattleScripts[gBattlerAttacker] != NULL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = gPalaceSelectionBattleScripts[gBattlerAttacker];
            gPalaceSelectionBattleScripts[gBattlerAttacker] = NULL;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_INCAPABLE_OF_POWER;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
        }
    }
    else
    {
        gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddMindPoints(gBattlerAttacker);

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        gBattleStruct->battlerState[battler].wasAboveHalfHp = gBattleMons[battler].hp > gBattleMons[battler].maxHP / 2;
        gBattleMons[battler].volatiles.activateDancer = FALSE;
    }

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    enum BattlerId partnerAtk = GetPartnerBattler(gBattlerAttacker);
    // if switching to a mon that is already on field, cancel switch
    if (!(gAbsentBattlerFlags & (1u << partnerAtk))
     && IsBattlerAlive(partnerAtk)
     && gBattlerPartyIndexes[partnerAtk] == gBattleStruct->monToSwitchIntoId[gBattlerAttacker]
     && BattlersShareParty(gBattlerAttacker, partnerAtk))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattleStruct->battlerPartyIndexes[gBattlerAttacker]);

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;

    TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_SWITCH_OUT, GetBattlerAbility(gBattlerAttacker));
}

void HandleAction_UseItem(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    ClearVariousBattlerFlags(gBattlerAttacker);

    gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][1] | (gBattleResources->bufferB[gBattlerAttacker][2] << 8);
    if (X_ITEM_FRIENDSHIP_INCREASE > 0
        && GetItemEffectType(gLastUsedItem) == ITEM_EFFECT_X_ITEM
        && !ShouldSkipFriendshipChange())
        UpdateFriendshipFromXItem(gBattlerAttacker);

    gBattlescriptCurrInstr = gBattlescriptsForUsingItem[GetItemBattleUsage(gLastUsedItem) - 1];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

bool32 TryRunFromBattle(enum BattlerId battler)
{
    bool32 effect = FALSE;
    u8 holdEffect;
    u8 pyramidMultiplier;
    u8 speedVar;

    // If this flag is set, running will never be successful under any circumstances.
    if (FlagGet(WE_FLAG_NO_RUNNING))
        return effect;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY_E_READER)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = GetItemHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    if (holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
    {
        gLastUsedItem = gBattleMons[battler].item;
        gProtectStructs[battler].fleeType = FLEE_ITEM;
        effect = TRUE;
    }
    else if (GetConfig(B_GHOSTS_ESCAPE) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
    {
        effect = TRUE;
    }
    else if (GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
    {
        if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        {
            gBattleStruct->runTries++;
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[GetOppositeBattler(battler)].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
            {
                gLastUsedAbility = ABILITY_RUN_AWAY;
                gProtectStructs[battler].fleeType = FLEE_ABILITY;
                effect = TRUE;
            }
        }
        else
        {
            gLastUsedAbility = ABILITY_RUN_AWAY;
            gProtectStructs[battler].fleeType = FLEE_ABILITY;
            effect = TRUE;
        }
    }
    else if (IsGhostBattleWithoutScope())
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            effect = TRUE;
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL) && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        effect = TRUE;
    }
    else if (CanPlayerForfeitNormalTrainerBattle())
    {
        effect = TRUE;
    }
    else
    {
        enum BattlerId runningFromBattler = GetOppositeBattler(battler);
        if (!IsBattlerAlive(runningFromBattler))
            runningFromBattler |= BIT_FLANK;

        if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        {
            pyramidMultiplier = GetPyramidRunMultiplier();
            speedVar = (gBattleMons[battler].speed * pyramidMultiplier) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect = TRUE;
        }
        else if (gBattleMons[battler].speed < gBattleMons[runningFromBattler].speed)
        {
            speedVar = (gBattleMons[battler].speed * 128) / (gBattleMons[runningFromBattler].speed) + (gBattleStruct->runTries * 30);
            if (speedVar > (Random() & 0xFF))
                effect = TRUE;
        }
        else // same speed or faster
        {
            effect = TRUE;
        }

        gBattleStruct->runTries++;
    }

    if (effect)
    {
        gCurrentTurnActionNumber = gBattlersCount;
        gBattleOutcome = B_OUTCOME_RAN;
    }

    return effect;
}

void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gCurrentTurnActionNumber = gBattlersCount;

        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            if (IsOnPlayerSide(i))
            {
                if (gChosenActionByBattler[i] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_LOST;
            }
            else
            {
                if (gChosenActionByBattler[i] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_WON;
            }
        }

        gBattleOutcome |= B_OUTCOME_LINK_BATTLE_RAN;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else
    {
        if (IsOnPlayerSide(gBattlerAttacker))
        {
            if (!TryRunFromBattle(gBattlerAttacker)) // failed to run away
            {
                ClearVariousBattlerFlags(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE_2;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
        }
        else
        {
            if (GetBattlerHoldEffect(gBattlerAttacker) != HOLD_EFFECT_CAN_ALWAYS_RUN
             && GetBattlerAbility(gBattlerAttacker) != ABILITY_RUN_AWAY
             && !CanBattlerEscape(gBattlerAttacker))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ATTACKER_CANT_ESCAPE;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gBattlersCount;
                gBattleOutcome = B_OUTCOME_MON_FLED;
            }
        }
    }
}

#define safariBaitThrowCounter safariPkblThrowCounter
#define safariRockThrowCounter safariGoNearCounter

void HandleAction_WatchesCarefully(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    if (IS_FRLG)
    {
        if (gBattleStruct->safariRockThrowCounter != 0)
        {
            gBattleStruct->safariRockThrowCounter--;
            if (gBattleStruct->safariRockThrowCounter == 0)
            {
                gBattleStruct->safariCatchFactor = gSpeciesInfo[GetMonData(gParties[B_TRAINER_OPPONENT_A], MON_DATA_SPECIES)].catchRate * 100 / 1275;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_WATCHING;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_ANGRY;
            }
        }
        else
        {
            if (gBattleStruct->safariBaitThrowCounter != 0)
            {
                --gBattleStruct->safariBaitThrowCounter;
                if (gBattleStruct->safariBaitThrowCounter == 0)
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_WATCHING;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_EATING;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_WATCHING;
            }
        }
        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MON_WATCHING;
        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    }
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = BattleScript_SafariBallThrow;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowBall(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gLastUsedItem = gBallToDisplay;
    if (!GetItemImportance(gLastUsedItem))
        RemoveBagItem(gLastUsedItem, 1);
    gBattlescriptCurrInstr = BattleScript_BallThrow;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    if (IS_FRLG)
    {
        // throw bait
        gBattleStruct->safariBaitThrowCounter += Random() % 5 + 2;
        if (gBattleStruct->safariBaitThrowCounter > 6)
            gBattleStruct->safariBaitThrowCounter = 6;

        gBattleStruct->safariRockThrowCounter = 0;
        gBattleStruct->safariCatchFactor >>= 1;

        if (gBattleStruct->safariCatchFactor <= 2)
            gBattleStruct->safariCatchFactor = 3;

        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[5];
    }
    else
    {
        // throw pokeblock
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleResources->bufferB[gBattlerAttacker][1] - 1;
        gLastUsedItem = gBattleResources->bufferB[gBattlerAttacker][2];

        if (gBattleResults.pokeblockThrows < 255)
            gBattleResults.pokeblockThrows++;
        if (gBattleStruct->safariPkblThrowCounter < 3)
            gBattleStruct->safariPkblThrowCounter++;
        if (gBattleStruct->safariEscapeFactor > 1)
        {
            // BUG: safariEscapeFactor can become 0 below. This causes the pokeblock throw glitch.
            #ifdef BUGFIX
            if (gBattleStruct->safariEscapeFactor <= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
            #else
            if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
            #endif
                gBattleStruct->safariEscapeFactor = 1;
            else
                gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
        }

        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    }

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    if (IS_FRLG)
    {
        // throw rock
        gBattleStruct->safariRockThrowCounter += Random() % 5 + 2;
        if (gBattleStruct->safariRockThrowCounter > 6)
            gBattleStruct->safariRockThrowCounter = 6;

        gBattleStruct->safariBaitThrowCounter = 0;
        gBattleStruct->safariCatchFactor <<= 1;

        if (gBattleStruct->safariCatchFactor > 20)
            gBattleStruct->safariCatchFactor = 20;

        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[4];
    }
    else
    {
        // go near
        gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
        if (gBattleStruct->safariCatchFactor > 20)
            gBattleStruct->safariCatchFactor = 20;

        gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
        if (gBattleStruct->safariEscapeFactor > 20)
            gBattleStruct->safariEscapeFactor = 20;

        if (gBattleStruct->safariGoNearCounter < 3)
        {
            gBattleStruct->safariGoNearCounter++;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CREPT_CLOSER;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_GET_CLOSER;
        }
        gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    }

    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

#undef safariBaitThrowCounter
#undef safariRockThrowCounter

void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_FLEE);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

void HandleAction_WallyBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
    gActionsByTurnOrder[1] = B_ACTION_FINISHED;
}

void HandleAction_TryFinish(void)
{
    if (!HandleFaintedMonActions())
    {
        gBattleStruct->eventState.faintedAction = 0;
        gCurrentActionFuncId = B_ACTION_FINISHED;
    }
}

void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
}

void HandleAction_ActionFinished(void)
{
    u32 i, j;
    bool32 afterYouActive = gSpecialStatuses[gBattlerByTurnOrder[gCurrentTurnActionNumber + 1]].afterYou;
    gBattleStruct->monToSwitchIntoId[gBattlerByTurnOrder[gCurrentTurnActionNumber]] = gSelectedMonPartyId = PARTY_SIZE;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    memset(&gSpecialStatuses, 0, sizeof(gSpecialStatuses));

    gCurrentMove = MOVE_NONE;
    ClearDamageCalcResults(); // Relies on gCurrentMove
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleStruct->bouncedMoveIsUsed = FALSE;
    gBattleStruct->snatchedMoveIsUsed = FALSE;
    gBattleScripting.moveendState = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleResources->battleScriptsStack->size = 0;

    if (GetConfig(B_RECALC_TURN_AFTER_ACTIONS) >= GEN_8
     && !afterYouActive
     && gBattleStruct->pledgeState != PLEDGE_COMBO_WAITING
     && !IsPursuitTargetSet())
    {
        // i starts at `gCurrentTurnActionNumber` because we don't want to recalculate turn order for mon that have already
        // taken action. It's been previously increased, which we want in order to not recalculate the turn of the mon that just finished its action

        struct BattleCalcValues calcValues = {0};
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            calcValues.abilities[battler] = GetBattlerAbility(battler);
            calcValues.holdEffects[battler] = GetBattlerHoldEffect(battler);
        }
        for (i = gCurrentTurnActionNumber; i < gBattlersCount - 1; i++)
        {
            for (j = i + 1; j < gBattlersCount; j++)
            {
                calcValues.battlerAtk = gBattlerByTurnOrder[i];
                calcValues.battlerDef = gBattlerByTurnOrder[j];

                if (gProtectStructs[calcValues.battlerAtk].quash || gProtectStructs[calcValues.battlerDef].quash
                    || gProtectStructs[calcValues.battlerAtk].shellTrap || gProtectStructs[calcValues.battlerDef].shellTrap)
                    continue;

                // We recalculate order only for action of the same priority. If any action other than switch/move has been taken, they should
                // have been executed before. The only recalculation needed is for moves/switch. Mega evolution is handled in src/battle_main.c/TryChangeOrder
                if ((gActionsByTurnOrder[i] == B_ACTION_USE_MOVE && gActionsByTurnOrder[j] == B_ACTION_USE_MOVE))
                {
                    if (GetWhichBattlerFaster(&calcValues, FALSE) == -1)
                        SwapTurnOrder(i, j);
                }
                else if ((gActionsByTurnOrder[i] == B_ACTION_SWITCH && gActionsByTurnOrder[j] == B_ACTION_SWITCH))
                {
                    if (GetWhichBattlerFaster(&calcValues, TRUE) == -1) // If the actions chosen are switching, we recalc order but ignoring the moves
                        SwapTurnOrder(i, j);
                }
            }
        }
    }
}

// code

ARM_FUNC NOINLINE static uq4_12_t PercentToUQ4_12(u32 percent)
{
    return (4096 * percent + 50) / 100;
}

ARM_FUNC NOINLINE static uq4_12_t PercentToUQ4_12_Floored(u32 percent)
{
    return (4096 * percent) / 100;
}

static inline uq4_12_t PercentToUQ4_12AddOne(u32 percent)
{
    return uq4_12_add(UQ_4_12(1.0), PercentToUQ4_12(percent));
}

enum BattlerId GetBattlerForBattleScript(u8 caseId)
{
    enum BattlerId ret = 0;
    switch (caseId)
    {
    case BS_TARGET:
        ret = gBattlerTarget;
        break;
    case BS_ATTACKER:
        ret = gBattlerAttacker;
        break;
    case BS_ATTACKER_PARTNER:
        ret = GetPartnerBattler(gBattlerAttacker);
        break;
    case BS_EFFECT_BATTLER:
        ret = gEffectBattler;
        break;
    case BS_BATTLER_0:
        ret = 0;
        break;
    case BS_SCRIPTING:
        ret = gBattleScripting.battler;
        break;
    case BS_FAINTED:
        ret = gBattlerFainted;
        break;
    case BS_FAINTED_MULTIPLE_1:
        ret = gBattlerFainted;
        break;
    case BS_FAINTED_MULTIPLE_2:
        ret = GetPartnerBattler(gBattlerFainted);
        break;
    case BS_ATTACKER_WITH_PARTNER:
    case BS_ATTACKER_SIDE:
    case BS_TARGET_SIDE:
    case BS_PLAYER1:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    case BS_OPPONENT1:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case BS_PLAYER2:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        break;
    case BS_OPPONENT2:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        break;
    case BS_ABILITY_BATTLER:
        ret = gBattlerAbility;
        break;
    }
    return ret;
}

static void UNUSED MarkAllBattlersForControllerExec(void)
{
    enum BattlerId i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        for (i = 0; i < gBattlersCount; i++)
            MarkBattleControllerMessageOutboundOverLink(i);
    }
    else
    {
        for (i = 0; i < gBattlersCount; i++)
            MarkBattleControllerActiveOnLocal(i);
    }
}

bool32 IsBattlerMarkedForControllerExec(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return IsBattleControllerMessageSynchronizedOverLink(battler);
    else
        return IsBattleControllerActiveOnLocal(battler);
}

void MarkBattlerForControllerExec(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        MarkBattleControllerMessageOutboundOverLink(battler);
    else
        MarkBattleControllerActiveOnLocal(battler);
}

void MarkBattlerReceivedLinkData(enum BattlerId battler)
{
    s32 i;

    for (i = 0; i < GetLinkPlayerCount(); i++)
        MarkBattleControllerActiveForPlayer(battler, i);

    MarkBattleControllerMessageSynchronizedOverLink(battler);
}

void CancelMultiTurnMoves(enum BattlerId battler)
{
    gBattleMons[battler].volatiles.uproarTurns = 0;
    gBattleMons[battler].volatiles.bideTurns = 0;
    gBattleMons[battler].volatiles.rolloutTimer = 0;
    gBattleMons[battler].volatiles.furyCutterCounter = 0;

    if (B_RAMPAGE_CONFUSION < GEN_5
     || gBattleMons[battler].volatiles.rampageTurns != 1) // Will be confused at the end of the turn
    {
        gLockedMoves[battler] = MOVE_NONE;
        gBattleMons[battler].volatiles.multipleTurns = 0;
        gBattleMons[battler].volatiles.rampageTurns = 0;
    }

    // Clear battler's semi-invulnerable bits if they are not held by Sky Drop.
    if (gBattleMons[battler].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET)
        gBattleMons[battler].volatiles.semiInvulnerable = STATE_NONE;

}

// Returns TRUE if no other battler after this one in turn order will use a move
bool32 IsLastMonToMove(enum BattlerId battler)
{
    u32 i;
    u32 battlerTurnOrderNum = GetBattlerTurnOrderNum(battler);

    if (battlerTurnOrderNum >= gBattlersCount - 1)
        return TRUE;

    for (i = battlerTurnOrderNum + 1; i < gBattlersCount; i++)
    {
        enum BattlerId otherBattler = gBattlerByTurnOrder[i];
        if (!IsBattlerAlive(otherBattler))
            continue;
        if (gActionsByTurnOrder[i] == B_ACTION_USE_MOVE)
            return FALSE;
    }
    return TRUE;
}

static u32 GetAiTurnOrder(u8 *aiTurnOrder, enum BattlerId battler)
{
    for (u32 i = 0; i < gBattlersCount; i++)
    {
        if (aiTurnOrder[i] == battler)
            return i;
    }
    return 0;
}

static bool32 Ai_AttackerMovesAfterTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    u8 aiTurnOrder[4] = {0};
    AI_SetBattlerTurnOrder(aiTurnOrder);

    return GetAiTurnOrder(aiTurnOrder, battlerAtk) > GetAiTurnOrder(aiTurnOrder, battlerDef);
}

static bool32 Ai_AttackerMovesLast(enum BattlerId battlerAtk)
{
    u8 aiTurnOrder[4] = {0};
    AI_SetBattlerTurnOrder(aiTurnOrder);
    u32 numAliveBattlers = 0;
    u32 battlerTurnOrder = GetAiTurnOrder(aiTurnOrder, battlerAtk);

    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        if (IsBattlerAlive(battler))
            numAliveBattlers++;
    }

    if (battlerTurnOrder >= numAliveBattlers - 1)
        return TRUE;

    return FALSE;
}

void PrepareStringBattleWithWait(enum StringID stringId, enum BattlerId battler)
{
    PrepareStringBattle(stringId, battler);
    gBattleCommunication[MSG_DISPLAY] = MSG_DISPLAY_WAIT;
}

void PrepareStringBattle(enum StringID stringId, enum BattlerId battler)
{
    switch (stringId)
    {
    case STRINGID_ITDOESNTAFFECT:
    case STRINGID_PKMNUNAFFECTED:
        TryInitializeTrainerSlideMonUnaffected(gBattlerTarget, gBattlerAttacker);
        break;
    default:
        break;
    }

    BtlController_EmitPrintString(battler, B_COMM_TO_CONTROLLER, stringId);
    MarkBattlerForControllerExec(battler);
}

void ResetSentPokesToOpponentValue(void)
{
    s32 i;
    u32 bits = 0;

    gSentPokesToOpponent[0] = 0;
    gSentPokesToOpponent[1] = 0;

    for (i = 0; i < gBattlersCount; i += 2)
        bits |= 1u << gBattlerPartyIndexes[i];

    for (i = 1; i < gBattlersCount; i += 2)
        gSentPokesToOpponent[(i & BIT_FLANK) >> 1] = bits;
}

void OpponentSwitchInResetSentPokesToOpponentValue(enum BattlerId battler)
{
    s32 i = 0;
    u32 bits = 0;

    if (!IsOnPlayerSide(battler))
    {
        u8 flank = ((battler & BIT_FLANK) >> 1);
        gSentPokesToOpponent[flank] = 0;

        for (i = 0; i < gBattlersCount; i += 2)
        {
            if (!(gAbsentBattlerFlags & (1u << i)))
                bits |= 1u << gBattlerPartyIndexes[i];
        }
        gSentPokesToOpponent[flank] = bits;
    }
}

void UpdateSentPokesToOpponentValue(enum BattlerId battler)
{
    if (!IsOnPlayerSide(battler))
    {
        OpponentSwitchInResetSentPokesToOpponentValue(battler);
    }
    else
    {
        s32 i;
        for (i = 1; i < gBattlersCount; i++)
            gSentPokesToOpponent[(i & BIT_FLANK) >> 1] |= 1u << gBattlerPartyIndexes[battler];
    }
}

void BattleScriptPush(const u8 *bsPtr)
{
    assertf(gBattleResources->battleScriptsStack->size < ARRAY_COUNT(gBattleResources->battleScriptsStack->ptr), "attempted to push a battle script, but battleScriptsStack is full!")
    {
        return;
    }
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    assertf(gBattleResources->battleScriptsStack->size < ARRAY_COUNT(gBattleResources->battleScriptsStack->ptr), "attempted to push cursor, but battleScriptsStack is full!")
    {
        return;
    }
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = gBattlescriptCurrInstr;
}

void BattleScriptCall(const u8 *bsPtr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = bsPtr;
}

void BattleScriptPop(void)
{
    if (gBattleResources->battleScriptsStack->size != 0)
        gBattlescriptCurrInstr = gBattleResources->battleScriptsStack->ptr[--gBattleResources->battleScriptsStack->size];
}

void BattleScriptExecute(const u8 *BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands_PopCallbacksStack;
    gCurrentActionFuncId = 0;
}

void BattleScriptPushCursorAndCallback(const u8 *BS_ptr)
{
    BattleScriptCall(BS_ptr);
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands;
}

bool32 IsGravityPreventingMove(enum Move move)
{
    if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        return FALSE;

    return IsMoveGravityBanned(move);
}

bool32 IsHealBlockPreventingMove(enum BattlerId battler, enum Move move)
{
    if (!gBattleMons[battler].volatiles.healBlockTimer)
        return FALSE;

    return IsHealingMove(move);
}

bool32 IsBelchPreventingMove(enum BattlerId battler, enum Move move)
{
    if (GetMoveEffect(move) != EFFECT_BELCH)
        return FALSE;

    return (!GetBattlerPartyState(battler)->ateBerry && GetConfig(B_BELCH_SELECTABLE) < GEN_CHAMPIONS);
}

static bool32 SetCantSelectScript(enum BattlerId battler, enum Move move, const u8 *palaceScript, const u8 *script)
{
    gCurrentMove = move;

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gPalaceSelectionBattleScripts[battler] = palaceScript;
        gProtectStructs[battler].palaceUnableToUseMove = TRUE;
        return FALSE;
    }
    else
    {
        gSelectionBattleScripts[battler] = script;
        return TRUE;
    }
}

static bool32 IsGimmickChosenForAction(enum BattlerId battler, enum Gimmick gimmick)
{
    return (gBattleResources->bufferB[battler][2] & RET_GIMMICK)
         && gBattleStruct->gimmick.usableGimmick[battler] == gimmick;
}

u32 TrySetCantSelectMoveBattleScript(enum BattlerId battler)
{
    u32 limitations = 0;
    u8 moveId = gBattleResources->bufferB[battler][2] & ~RET_GIMMICK;
    enum Move move = gBattleMons[battler].moves[moveId];
    enum HoldEffect holdEffect = GetBattlerHoldEffect(battler);
    u16 *choicedMove = &gBattleStruct->choicedMove[battler];
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);

    // Dynamax bypasses all selection prevention except Taunt and Assault Vest.
    bool32 dynamaxBypassCheck = (!IsGimmickChosenForAction(battler, GIMMICK_DYNAMAX) && GetActiveGimmick(battler) != GIMMICK_DYNAMAX);

    // Z-Moves bypass the effects of disruption moves like Encore, Taunt, Disable
    bool32 zMoveBypassCheck = (!IsGimmickChosenForAction(battler, GIMMICK_Z_MOVE) && GetActiveGimmick(battler) != GIMMICK_Z_MOVE);

    if (GetConfig(B_ENCORE_TARGET) >= GEN_5
     && dynamaxBypassCheck && zMoveBypassCheck && gBattleMons[battler].volatiles.encoredMove != move && gBattleMons[battler].volatiles.encoredMove != MOVE_NONE)
    {
        gBattleScripting.battler = battler;
        limitations = SetCantSelectScript(battler, gBattleMons[battler].volatiles.encoredMove, BattleScript_EncoredMoveInPalace, BattleScript_EncoredMove);
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && gBattleMons[battler].volatiles.disabledMove == move && move != MOVE_NONE)
    {
        gBattleScripting.battler = battler;
        if (SetCantSelectScript(battler, gBattleMons[battler].volatiles.disabledMove, BattleScript_SelectingDisabledMoveInPalace, BattleScript_SelectingDisabledMove))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && move == gLastMoves[battler] && move != MOVE_STRUGGLE && (gBattleMons[battler].volatiles.torment == TRUE))
    {
        CancelMultiTurnMoves(battler);
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[battler] = BattleScript_SelectingTormentedMoveInPalace;
            gProtectStructs[battler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[battler] = BattleScript_SelectingTormentedMove;
            limitations++;
        }
    }

    if (zMoveBypassCheck
     && gBattleMons[battler].volatiles.tauntTimer != 0
     && IsBattleMoveStatus(move)
     && (GetConfig(B_TAUNT_ME_FIRST) < GEN_5 || moveEffect != EFFECT_ME_FIRST))
    {
        if ((GetActiveGimmick(battler) == GIMMICK_DYNAMAX))
            gCurrentMove = MOVE_MAX_GUARD;
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveTauntInPalace, BattleScript_SelectingNotAllowedMoveTaunt))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && gBattleMons[battler].volatiles.throatChopTimer > 0 && IsSoundMove(move))
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveThroatChopInPalace, BattleScript_SelectingNotAllowedMoveThroatChop))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && GetImprisonedMovesCount(battler, move))
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingImprisonedMoveInPalace, BattleScript_SelectingImprisonedMove))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && IsGravityPreventingMove(move))
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveGravityInPalace, BattleScript_SelectingNotAllowedMoveGravity))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && IsHealBlockPreventingMove(battler, move))
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveHealBlockInPalace, BattleScript_SelectingNotAllowedMoveHealBlock))
            limitations++;
    }

    if (dynamaxBypassCheck && zMoveBypassCheck && IsBelchPreventingMove(battler, move))
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedBelchInPalace, BattleScript_SelectingNotAllowedBelch))
            limitations++;
    }

    if (dynamaxBypassCheck && moveEffect == EFFECT_STUFF_CHEEKS && GetItemPocket(gBattleMons[battler].item) != POCKET_BERRIES && GetConfig(B_STUFF_CHEEKS_SELECTABLE) < GEN_CHAMPIONS)
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedStuffCheeksInPalace, BattleScript_SelectingNotAllowedStuffCheeks))
            limitations++;
    }

    if (MoveCantBeUsedTwice(move) && move == gLastResultingMoves[battler])
    {
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gCurrentMove);
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedCurrentMoveInPalace, BattleScript_SelectingNotAllowedCurrentMove))
            limitations++;
    }

    // Unconfirmed: We're making an assumption that a Max Move variant of moves that otherwise result in
    // "This move can't be used!" can be used while Dynamaxed
    if (dynamaxBypassCheck
     && moveEffect == EFFECT_FIRST_TURN_ONLY
     && !IsBattlersFirstTurn(battler)
     && GetConfig(B_FIRST_TURN_MOVE) >= GEN_CHAMPIONS)
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingCantUseMoveInPalace, BattleScript_SelectingCantUseMove))
            limitations++;
    }

    if (dynamaxBypassCheck
     && moveEffect == EFFECT_SPIT_UP
     && gBattleMons[battler].volatiles.stockpileCounter == 0
     && GetConfig(B_SPIT_UP_SELECTABLE) >= GEN_CHAMPIONS)
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingCantUseMoveInPalace, BattleScript_SelectingCantUseMove))
            limitations++;
    }

    if (dynamaxBypassCheck
     && zMoveBypassCheck
     && moveEffect == EFFECT_FAIL_IF_NOT_ARG_TYPE
     && !IS_BATTLER_OF_TYPE(battler, GetMoveArgType(move))
     && GetConfig(B_MOVES_THAT_REMOVE_TYPE) >= GEN_CHAMPIONS)
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingCantUseMoveInPalace, BattleScript_SelectingCantUseMove))
            limitations++;
    }

    if (dynamaxBypassCheck
     && zMoveBypassCheck
     && moveEffect == EFFECT_LAST_RESORT
     && !CanUseLastResort(battler)
     && GetConfig(B_LAST_RESORT_SELECTABLE) >= GEN_CHAMPIONS)
    {
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingCantUseMoveInPalace, BattleScript_SelectingCantUseMove))
            limitations++;
    }

    gPotentialItemEffectBattler = battler;
    if (dynamaxBypassCheck && IsHoldEffectChoice(holdEffect) && *choicedMove != MOVE_NONE && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[battler].item;
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveChoiceItemInPalace, BattleScript_SelectingNotAllowedMoveChoiceItem))
            limitations++;
    }
    else if (holdEffect == HOLD_EFFECT_ASSAULT_VEST && IsBattleMoveStatus(move) && moveEffect != EFFECT_ME_FIRST)
    {
        if ((GetActiveGimmick(battler) == GIMMICK_DYNAMAX))
            gCurrentMove = MOVE_MAX_GUARD;
        gLastUsedItem = gBattleMons[battler].item;
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveAssaultVestInPalace, BattleScript_SelectingNotAllowedMoveAssaultVest))
            limitations++;
    }
    if (dynamaxBypassCheck && (GetBattlerAbility(battler) == ABILITY_GORILLA_TACTICS) && *choicedMove != MOVE_NONE
              && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[battler].item;
        if (SetCantSelectScript(battler, gCurrentMove, BattleScript_SelectingNotAllowedMoveGorillaTacticsInPalace, BattleScript_SelectingNotAllowedMoveGorillaTactics))
            limitations++;
    }

    if (gBattleMons[battler].pp[moveId] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[battler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[battler] = BattleScript_SelectingMoveWithNoPP;
            limitations++;
        }
    }

    if (moveEffect == EFFECT_PLACEHOLDER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedPlaceholderInPalace;
            gProtectStructs[battler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[battler] = BattleScript_SelectingNotAllowedPlaceholder;
            limitations++;
        }
    }

    return limitations;
}

u32 CheckMoveLimitations(enum BattlerId battler, u8 unusableMoves, u32 check)
{
    enum Move move;
    enum BattleMoveEffects moveEffect;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(battler);
    u16 *choicedMove = &gBattleStruct->choicedMove[battler];
    s32 i;

    gPotentialItemEffectBattler = battler;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[battler].moves[i];
        moveEffect = GetMoveEffect(move);
        // No move
        if (check & MOVE_LIMITATION_ZEROMOVE && move == MOVE_NONE)
            unusableMoves |= 1u << i;
        // No PP
        else if (check & MOVE_LIMITATION_PP && gBattleMons[battler].pp[i] == 0)
            unusableMoves |= 1u << i;
        // Placeholder
        else if (check & MOVE_LIMITATION_PLACEHOLDER && moveEffect == EFFECT_PLACEHOLDER)
            unusableMoves |= 1u << i;
        // Disable
        else if (check & MOVE_LIMITATION_DISABLED && move == gBattleMons[battler].volatiles.disabledMove)
            unusableMoves |= 1u << i;
        // Torment
        else if (check & MOVE_LIMITATION_TORMENTED && move == gLastMoves[battler] && gBattleMons[battler].volatiles.torment == TRUE)
            unusableMoves |= 1u << i;
        // Taunt
        else if (check & MOVE_LIMITATION_TAUNT
              && gBattleMons[battler].volatiles.tauntTimer
              && IsBattleMoveStatus(move)
              && (GetConfig(B_TAUNT_ME_FIRST) < GEN_5 || moveEffect != EFFECT_ME_FIRST))
            unusableMoves |= 1u << i;
        // Imprison
        else if (check & MOVE_LIMITATION_IMPRISON && GetImprisonedMovesCount(battler, move))
            unusableMoves |= 1u << i;
        // Encore
        else if (check & MOVE_LIMITATION_ENCORE && gBattleMons[battler].volatiles.encoreTimer && gBattleMons[battler].volatiles.encoredMove != move)
            unusableMoves |= 1u << i;
        // Choice Items
        else if (check & MOVE_LIMITATION_CHOICE_ITEM && IsHoldEffectChoice(holdEffect) && *choicedMove != MOVE_NONE && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != move)
            unusableMoves |= 1u << i;
        // Assault Vest
        else if (check & MOVE_LIMITATION_ASSAULT_VEST && holdEffect == HOLD_EFFECT_ASSAULT_VEST && IsBattleMoveStatus(move) && moveEffect != EFFECT_ME_FIRST)
            unusableMoves |= 1u << i;
        // Gravity
        else if (check & MOVE_LIMITATION_GRAVITY && IsGravityPreventingMove(move))
            unusableMoves |= 1u << i;
        // Heal Block
        else if (check & MOVE_LIMITATION_HEAL_BLOCK && IsHealBlockPreventingMove(battler, move))
            unusableMoves |= 1u << i;
        // Belch
        else if (check & MOVE_LIMITATION_BELCH && IsBelchPreventingMove(battler, move))
            unusableMoves |= 1u << i;
        // Throat Chop
        else if (check & MOVE_LIMITATION_THROAT_CHOP && gBattleMons[battler].volatiles.throatChopTimer > 0 && IsSoundMove(move))
            unusableMoves |= 1u << i;
        // Stuff Cheeks
        else if (check & MOVE_LIMITATION_STUFF_CHEEKS && moveEffect == EFFECT_STUFF_CHEEKS && GetItemPocket(gBattleMons[battler].item) != POCKET_BERRIES && GetConfig(B_STUFF_CHEEKS_SELECTABLE) < GEN_CHAMPIONS)
            unusableMoves |= 1u << i;
        // Gorilla Tactics
        else if (check & MOVE_LIMITATION_CHOICE_ITEM && GetBattlerAbility(battler) == ABILITY_GORILLA_TACTICS && *choicedMove != MOVE_NONE && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != move)
            unusableMoves |= 1u << i;
        // Can't Use Twice flag
        else if (check & MOVE_LIMITATION_CANT_USE_TWICE && MoveCantBeUsedTwice(move) && move == gLastResultingMoves[battler])
            unusableMoves |= 1u << i;
        else if (check & MOVE_LIMITATION_UNUSABLE)
        {
            switch (moveEffect)
            {
                // Fake Out, First Impression
                case EFFECT_FIRST_TURN_ONLY:
                    if (!IsBattlersFirstTurn(battler) && GetConfig(B_FIRST_TURN_MOVE) >= GEN_CHAMPIONS)
                        unusableMoves |= 1u << i;
                    break;
                // Spit Up
                case EFFECT_SPIT_UP:
                    if (gBattleMons[battler].volatiles.stockpileCounter == 0 && GetConfig(B_SPIT_UP_SELECTABLE) >= GEN_CHAMPIONS)
                        unusableMoves |= 1u << i;
                    break;
                // Burn Up, Double Shock
                case EFFECT_FAIL_IF_NOT_ARG_TYPE:
                    if (!IS_BATTLER_OF_TYPE(battler, GetMoveArgType(move)) && GetConfig(B_MOVES_THAT_REMOVE_TYPE) >= GEN_CHAMPIONS)
                        unusableMoves |= 1u << i;
                    break;
                // Last Resort
                case EFFECT_LAST_RESORT:
                    if (!CanUseLastResort(battler) && GetConfig(B_LAST_RESORT_SELECTABLE) >= GEN_CHAMPIONS)
                        unusableMoves |= 1u << i;
                    break;
                default:
                    break;
            }
        }
    }
    return unusableMoves;
}

bool32 AreAllMovesUnusable(enum BattlerId battler)
{
    u32 unusable = CheckMoveLimitations(battler, 0, MOVE_LIMITATIONS_ALL);
    u32 allMovesMask = ((1 << MAX_MON_MOVES) - 1);

    if (unusable == allMovesMask) // All moves are unusable.
    {
        gProtectStructs[battler].noValidMoves = TRUE;
        gSelectionBattleScripts[battler] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[battler].noValidMoves = FALSE;
    }

    return (unusable == allMovesMask);
}

u8 GetImprisonedMovesCount(enum BattlerId battler, enum Move move)
{
    s32 i;
    u8 imprisonedMoves = 0;
    u32 battlerSide = GetBattlerSide(battler);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (battlerSide != GetBattlerSide(i) && gBattleMons[i].volatiles.imprison)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < MAX_MON_MOVES)
                imprisonedMoves++;
        }
    }

    return imprisonedMoves;
}

u32 GetBattlerAffectionHearts(enum BattlerId battler)
{
    if (!IsOnPlayerSide(battler)
     || gBattleStruct->battlerState[battler].notOnField
     || gSpecialStatuses[battler].attackerInParty)
        return AFFECTION_NO_HEARTS;

    if (gSpeciesInfo[gBattleMons[battler].species].isMegaEvolution
          || (gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                                | BATTLE_TYPE_FRONTIER
                                | BATTLE_TYPE_LINK
                                | BATTLE_TYPE_RECORDED_LINK
                                | BATTLE_TYPE_SECRET_BASE)))
        return AFFECTION_NO_HEARTS;

    return gBattleMons[battler].affectionHearts;
}

// gBattlerAttacker is the battler that's trying to raise their stats and due to limitations of RandomUniformExcept, cannot be an argument
bool32 MoodyCantRaiseStat(u32 stat)
{
    return CompareStat(gBattlerAttacker, stat, MAX_STAT_STAGE, CMP_EQUAL, GetBattlerAbility(gBattlerAttacker));
}

// gBattlerAttacker is the battler that's trying to lower their stats and due to limitations of RandomUniformExcept, cannot be an argument
bool32 MoodyCantLowerStat(u32 stat)
{
    return stat == gSpecialStatuses[gBattlerAttacker].statStageQueue[0].stat
        || CompareStat(gBattlerAttacker, stat, MIN_STAT_STAGE, CMP_EQUAL, GetBattlerAbility(gBattlerAttacker));
}

void TryToRevertMimicryAndFlags(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        gBattleMons[battler].volatiles.terrainAbilityDone = FALSE;
        ResetParadoxTerrainStat(battler);
        if (IsAbilityAndRecord(battler, GetBattlerAbility(battler), ABILITY_MIMICRY))
            RESTORE_BATTLER_TYPE(battler);
    }
}

// Ingrain, Leech Seed, Strength Sap and Aqua Ring
s32 GetDrainedBigRootHp(enum BattlerId battler, s32 hp)
{
    if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_BIG_ROOT)
        hp = (hp * 1300) / 1000;
    if (hp == 0)
        hp = 1;

    return hp;
}

// Should always be the last check. Otherwise the ability might be wrongly recorded.
bool32 IsAbilityAndRecord(enum BattlerId battler, enum Ability battlerAbility, enum Ability abilityToCheck)
{
    if (battlerAbility != abilityToCheck)
        return FALSE;

    RecordAbilityBattle(battler, abilityToCheck);
    return TRUE;
}

bool32 HandleFaintedMonActions(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;

    do
    {
        switch (gBattleStruct->eventState.faintedAction)
        {
        case FAINTED_ACTIONS_NO_MONS_TO_SWITCH:
            gBattleStruct->eventState.faintedActionBattler = 0;
            gBattleStruct->eventState.faintedAction++;
            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & (1u << i) && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(1u << i);
            }
            // fall through
        case FAINTED_ACTIONS_GIVE_EXP:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->eventState.faintedActionBattler;
                if (gBattleMons[gBattlerFainted].hp == 0
                 && !(gBattleStruct->givenExpMons[GetBattlerTrainer(gBattlerFainted) & BIT_FLANK] & (1u << gBattlerPartyIndexes[gBattlerFainted]))
                 && !(gAbsentBattlerFlags & (1u << gBattlerFainted)))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_SET_ABSENT_FLAGS;
                    return TRUE;
                }
            } while (++gBattleStruct->eventState.faintedActionBattler != gBattlersCount);
            gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_WAIT_STATE;
            break;
        case FAINTED_ACTIONS_SET_ABSENT_FLAGS:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gBattleStruct->eventState.faintedActionBattler == gBattlersCount)
                gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_WAIT_STATE;
            else
                gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_GIVE_EXP;
            // Don't switch mons until all Pokémon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4
                && gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                gAbsentBattlerFlags |= 1u << gBattlerFainted;
                if (gBattleStruct->eventState.faintedAction != FAINTED_ACTIONS_GIVE_EXP)
                    return FALSE;
            }
            break;
        case FAINTED_ACTIONS_WAIT_STATE:
            // Don't switch mons until all Pokémon performed their actions or the battle's over.
            if (B_FAINT_SWITCH_IN >= GEN_4
                && gBattleOutcome == 0
                && !NoAliveMonsForEitherParty()
                && gCurrentTurnActionNumber != gBattlersCount)
            {
                return FALSE;
            }
            gBattleStruct->eventState.faintedActionBattler = 0;
            gBattleStruct->eventState.faintedAction++;
            // fall through
        case FAINTED_ACTIONS_HANDLE_FAINTED_MON:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->eventState.faintedActionBattler;
                if (gBattleMons[gBattleStruct->eventState.faintedActionBattler].hp == 0
                 && !(gAbsentBattlerFlags & (1u << gBattleStruct->eventState.faintedActionBattler)))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_HANDLE_NEXT_BATTLER;
                    return TRUE;
                }
            } while (++gBattleStruct->eventState.faintedActionBattler != gBattlersCount);
            gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_MAX_CASE;
            break;
        case FAINTED_ACTIONS_HANDLE_NEXT_BATTLER:
            if (++gBattleStruct->eventState.faintedActionBattler == gBattlersCount)
                gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_MAX_CASE;
            else
                gBattleStruct->eventState.faintedAction = FAINTED_ACTIONS_HANDLE_FAINTED_MON;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gBattleStruct->eventState.faintedAction != FAINTED_ACTIONS_MAX_CASE);
    return FALSE;
}

bool32 HasNoMonsToSwitch(enum BattlerId battler, u8 partyIdBattlerOn1, u8 partyIdBattlerOn2)
{
    u32 i, playerId, flankId;
    s32 lastId = GetAILastPartyIndex(battler); // + 1
    struct Pokemon *party = GetBattlerParty(battler);


    if (!IsDoubleBattle())
        return FALSE;

    bool32 isPlayerSide = IsOnPlayerSide(battler);

    if (BATTLE_TWO_VS_ONE_OPPONENT && !isPlayerSide)
    {
        flankId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        playerId = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

        // Edge case: If both opposing Pokemon were knocked out on the same turn,
        // make sure opponent only sends out the final Pokemon once.
        if (battler == playerId
         && (gHitMarker & HITMARKER_FAINTED(flankId))
         && (gHitMarker & HITMARKER_FAINTED(playerId)))
        {
            u8 count = 0;
            for (i = 0; i < lastId; i++)
                if (IsValidForBattle(&party[i]))
                    count++;

            if (count < 2)
                return TRUE;
        }

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[flankId];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[playerId];

        for (i = 0; i < lastId; i++)
        {
            if (IsValidForBattle(&party[i])
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != gBattleStruct->monToSwitchIntoId[flankId] && i != playerId[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == lastId);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (!isPlayerSide && WILD_DOUBLE_BATTLE)
        {
            flankId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            playerId = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);

            if (partyIdBattlerOn1 == PARTY_SIZE)
                partyIdBattlerOn1 = gBattlerPartyIndexes[flankId];
            if (partyIdBattlerOn2 == PARTY_SIZE)
                partyIdBattlerOn2 = gBattlerPartyIndexes[playerId];

            for (i = 0; i < lastId; i++)
            {
                if (IsValidForBattle(&party[i])
                 && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
                 && i != gBattleStruct->monToSwitchIntoId[flankId] && i != playerId[gBattleStruct->monToSwitchIntoId])
                    break;
            }
            return (i == lastId);
        }
        else
        {
            for (i = 0; i < lastId; i++)
            {
                if (IsValidForBattle(&party[i]))
                    break;
            }
            return (i == lastId);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        for (i = 0; i < lastId; i++)
        {
            if (IsValidForBattle(&party[i]))
                break;
        }
        return (i == lastId);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && !isPlayerSide)
    {
        for (i = 0; i < lastId; i++)
        {
            if (IsValidForBattle(&party[i]))
                break;
        }
        return (i == lastId);
    }
    else
    {
        if (!isPlayerSide)
        {
            flankId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            playerId = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            flankId = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            playerId = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[flankId];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[playerId];

        for (i = 0; i < lastId; i++)
        {
            if (IsValidForBattle(&party[i])
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != gBattleStruct->monToSwitchIntoId[flankId] && i != playerId[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == lastId);
    }
}

static bool32 TryChangeWeatherWithAbility(enum BattlerId battler, u32 battleWeather, enum Ability ability)
{
    switch (TryChangeBattleWeather(battler, battleWeather, ability))
    {
    case WEATHER_FAILURE_SAME_WEATHER:
        if (ability == ABILITY_ORICHALCUM_PULSE)
        {
            BattleScriptCall(BattleScript_OrichalcumPulseActivatesInSun);
            return TRUE;
        }
        return FALSE;
    case WEATHER_FAILURE_OVERWORLD:
        BattleScriptCall(BattleScript_BlockedByOverworldWeather);
        return TRUE;
    case WEATHER_FAILURE_PRIMAL:
        BattleScriptCall(BattleScript_BlockedByPrimalWeather);
        return TRUE;
    case WEATHER_FAILURE_SUCCESS:
        if (ability == ABILITY_ORICHALCUM_PULSE)
            BattleScriptCall(BattleScript_OrichalcumPulseActivates);
        else
            BattleScriptCall(BattleScript_WeatherAbilityActivates);
        return TRUE;
    }
    return FALSE;
}

enum WeatherFailure TryChangeBattleWeather(enum BattlerId battler, u32 battleWeatherId, enum Ability ability)
{
    if (gBattleWeather & gBattleWeatherInfo[battleWeatherId].flag)
        return WEATHER_FAILURE_SAME_WEATHER;

    if (gBattleStruct->overworldWeatherPresent)
        return WEATHER_FAILURE_OVERWORLD;

    if (gBattleWeather & B_WEATHER_PRIMAL_ANY
          && ability != ABILITY_DESOLATE_LAND
          && ability != ABILITY_PRIMORDIAL_SEA
          && ability != ABILITY_DELTA_STREAM)
    {
        return WEATHER_FAILURE_PRIMAL;
    }

    if (GetConfig(B_ABILITY_WEATHER) < GEN_6 && ability != ABILITY_NONE)
    {
        gBattleWeather = gBattleWeatherInfo[battleWeatherId].flag;
    }
    else
    {
        u32 rock = gBattleWeatherInfo[battleWeatherId].rock;
        gBattleWeather = gBattleWeatherInfo[battleWeatherId].flag;

        if (gBattleWeather & B_WEATHER_PRIMAL_ANY)
            gBattleStruct->weatherDuration = 0;
        else if (rock != 0 && GetBattlerHoldEffect(battler) == rock)
            gBattleStruct->weatherDuration = 8;
        else
            gBattleStruct->weatherDuration = 5;
    }

    if (ability != ABILITY_NONE) // Weather started by Ability
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleWeatherInfo[battleWeatherId].abilityStartMessage;
        gBattleScripting.animArg1 = gBattleWeatherInfo[battleWeatherId].animation;
    }
    else // Weather started by Move
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleWeatherInfo[battleWeatherId].moveStartMessage;
    }

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        gBattleMons[i].volatiles.weatherAbilityDone = FALSE;
        ResetParadoxWeatherStat(i);
    }

    return WEATHER_FAILURE_SUCCESS;
}

bool32 TryChangeBattleTerrain(enum BattlerId battler, enum BattleTerrain terrain)
{
    if (terrain == B_TERRAIN_NONE || terrain == gFieldTimers.terrain)
        return FALSE;

    if (gBattleStruct->isSkyBattle)
        return FALSE;

    if (gFieldTimers.terrain != terrain)
    {
        gFieldTimers.terrain = terrain;
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleTerrainInfo[terrain].startMessage;

        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].volatiles.terrainAbilityDone = FALSE;
            ResetParadoxTerrainStat(i);
        }
        if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_TERRAIN_EXTENDER)
            gFieldTimers.terrainTimer = 8;
        else
            gFieldTimers.terrainTimer = 5;
        gBattleScripting.battler = battler;
        return TRUE;
    }

    return FALSE;
}

static void ForewarnChooseMove(enum BattlerId battler)
{
    struct Forewarn {
        enum BattlerId battler;
        u8 power;
        enum Move moveId;
    };
    u32 i, j, bestId, count;
    struct Forewarn *data = Alloc(sizeof(struct Forewarn) * MAX_BATTLERS_COUNT * MAX_MON_MOVES);

    // Put all moves
    for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && !IsBattlerAlly(i, battler))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[i].moves[j] == MOVE_NONE)
                    continue;
                data[count].moveId = gBattleMons[i].moves[j];
                data[count].battler = i;
                switch (GetMoveEffect(data[count].moveId))
                {
                case EFFECT_OHKO:
                    data[count].power = 150;
                    break;
                case EFFECT_REFLECT_DAMAGE:
                    data[count].power = 120;
                    break;
                default:
                {
                    u32 movePower = GetMovePower(data[count].moveId);
                    if (movePower == 1)
                        data[count].power = 80;
                    else
                        data[count].power = movePower;
                    break;
                }
                }
                count++;
            }
        }
    }

    if (count == 0)
    {
        Free(data);
        return;
    }

    u32 tieCount = 1;
    u8 bestPower = data[0].power;

    bestId = 0;
    for (i = 1; i < count; i++)
    {
        if (data[i].power > bestPower)
        {
            bestPower = data[i].power;
            bestId = i;
            tieCount = 1;
        }
        else if (data[i].power == bestPower)
        {
            tieCount++;
        }
    }

    if (tieCount > 1)
    {
        u32 tieIndex = RandomUniform(RNG_FOREWARN, 0, tieCount - 1);
        for (i = 0, bestId = 0; i < count; i++)
        {
            if (data[i].power != bestPower)
                continue;
            if (tieIndex-- == 0)
            {
                bestId = i;
                break;
            }
        }
    }

    gEffectBattler = data[bestId].battler;
    PREPARE_MOVE_BUFFER(gBattleTextBuff1, data[bestId].moveId)
    RecordKnownMove(data[bestId].battler, data[bestId].moveId);

    Free(data);
}

bool32 ChangeTypeBasedOnTerrain(enum BattlerId battler)
{
    enum Type battlerType = gBattleTerrainInfo[gFieldTimers.terrain].type;

    SET_BATTLER_TYPE(battler, battlerType);
    PREPARE_TYPE_BUFFER(gBattleTextBuff1, battlerType);
    return TRUE;
}

// Supreme Overlord adds a x0.1 damage boost for each fainted ally.
static inline uq4_12_t GetSupremeOverlordModifier(enum BattlerId battler)
{
    return UQ_4_12(1.0) + (PercentToUQ4_12(gBattleMons[battler].volatiles.supremeOverlordCounter * 10));
}

bool32 HadMoreThanHalfHpNowDoesnt(enum BattlerId battler)
{
    // Had more than half of hp before, now has less
    return gBattleStruct->battlerState[battler].wasAboveHalfHp
        && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2;
}

u32 NumFaintedBattlersByAttacker(enum BattlerId battlerAtk)
{
    u32 numMonsFainted = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == battlerAtk)
            continue;

        if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES) && !IsBattlerAlive(battler))
            numMonsFainted++;
    }

    return numMonsFainted;
}

bool32 CanMoveBeBlockedByTarget(struct DamageContext *ctx, s32 movePriority)
{
    return CanAbilityAbsorbMove(ctx)
        || CanTargetBlockPranksterMove(ctx, movePriority)
        || IsPowderMoveBlocked(ctx);
}

bool32 CanPsychicTerrainProtectTarget(struct DamageContext *ctx, s32 movePriority)
{
    if (movePriority <= 0
     || !IsPsychicTerrainAffected(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef], ctx->terrain)
     || IsBattlerAlly(ctx->battlerAtk, ctx->battlerDef)
     || GetMoveTarget(ctx->move) == TARGET_ALL_BATTLERS
     || GetMoveTarget(ctx->move) == TARGET_OPPONENTS_FIELD)
        return FALSE;

    if (ctx->runScript)
        BattleScriptCall(BattleScript_MoveUsedPsychicTerrainPrevents);

    return TRUE;
}

bool32 CanTargetBlockPranksterMove(struct DamageContext *ctx, s32 movePriority)
{
    if (movePriority <= 0
     || !IsBattleMoveStatus(ctx->move)
     || !BlocksPrankster(ctx->move, ctx->battlerAtk, ctx->battlerDef, TRUE)
     || (IsBattleMoveStatus(ctx->move) && (ctx->abilities[ctx->battlerDef] == ABILITY_MAGIC_BOUNCE || gProtectStructs[ctx->battlerDef].bounceMove)))
        return FALSE;

    if (ctx->runScript)
        BattleScriptCall(BattleScript_DoesntAffectScripting);

    return TRUE;
}

bool32 IsPowderMoveBlocked(struct DamageContext *ctx)
{
    if (!IsPowderMove(ctx->move)
     || ctx->battlerAtk == ctx->battlerDef
     || IsAffectedByPowderMove(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef]))
        return FALSE;

    if (ctx->runScript)
    {
        gLastUsedAbility = ctx->abilities[ctx->battlerDef];
        gBattlerAbility = ctx->battlerDef;
        BattleScriptCall(BattleScript_PowderMoveNoEffect);
    }

    return TRUE;
}

bool32 CanAbilityAbsorbMove(struct DamageContext *ctx)
{
    const u8 *battleScript = NULL;

    switch (ctx->abilities[ctx->battlerDef])
    {
    case ABILITY_VOLT_ABSORB:
        if (ctx->moveType == TYPE_ELECTRIC)
            battleScript = AbsorbedByDrainHpAbility(ctx->battlerDef);
        break;
    case ABILITY_WATER_ABSORB:
    case ABILITY_DRY_SKIN:
        if (ctx->moveType == TYPE_WATER)
            battleScript = AbsorbedByDrainHpAbility(ctx->battlerDef);
        break;
    case ABILITY_EARTH_EATER:
        if (ctx->moveType == TYPE_GROUND)
            battleScript = AbsorbedByDrainHpAbility(ctx->battlerDef);
        break;
    case ABILITY_MOTOR_DRIVE:
        if (ctx->moveType == TYPE_ELECTRIC)
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_SPEED, 1);
        break;
    case ABILITY_LIGHTNING_ROD:
        if (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) >= GEN_5 && ctx->moveType == TYPE_ELECTRIC)
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_SPATK, 1);
        break;
    case ABILITY_STORM_DRAIN:
        if (GetConfig(B_REDIRECT_ABILITY_IMMUNITY) >= GEN_5 && ctx->moveType == TYPE_WATER)
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_SPATK, 1);
        break;
    case ABILITY_SAP_SIPPER:
        if (ctx->moveType == TYPE_GRASS)
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_ATK, 1);
        break;
    case ABILITY_WELL_BAKED_BODY:
        if (ctx->moveType == TYPE_FIRE)
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_DEF, 2);
        break;
    case ABILITY_WIND_RIDER:
        if (IsWindMove(ctx->move))
            battleScript = AbsorbedByStatIncreaseAbility(ctx, STAT_ATK, 1);
        break;
    case ABILITY_FLASH_FIRE:
        if (ctx->moveType == TYPE_FIRE && (B_FLASH_FIRE_FROZEN >= GEN_5 || !(gBattleMons[ctx->battlerDef].status1 & STATUS1_FREEZE)))
            battleScript = AbsorbedByFlashFire(ctx);
        break;
    case ABILITY_SOUNDPROOF:
        if (IsSoundMove(ctx->move))
            battleScript = BattleScript_AbilityProtectedTarget;
        break;
    case ABILITY_BULLETPROOF:
        if (IsBallisticMove(ctx->move))
            battleScript = BattleScript_AbilityProtectedTarget;
        break;
    case ABILITY_GOOD_AS_GOLD:
        if (IsBattleMoveStatus(ctx->move))
        {
            enum MoveTarget target = GetBattlerMoveTargetType(ctx->battlerAtk, ctx->move);
            if (target != TARGET_OPPONENTS_FIELD && target != TARGET_ALL_BATTLERS)
                battleScript = BattleScript_AbilityProtectedTarget;
        }
        break;
    default:
        break;
    }

    if (battleScript == NULL)
        return FALSE;

    if (ctx->runScript)
    {
        gLastUsedAbility = ctx->abilities[ctx->battlerDef];
        gBattleScripting.battler = gBattlerAbility = ctx->battlerDef;
        BattleScriptCall(battleScript);
    }

    return TRUE;
}

const u8 *AbsorbedByDrainHpAbility(enum BattlerId battlerDef)
{
    if (IsBattlerAtMaxHp(battlerDef) || (B_HEAL_BLOCKING >= GEN_5 && gBattleMons[battlerDef].volatiles.healBlockTimer))
    {
        return BattleScript_AbilityProtectedTarget;
    }
    else
    {
        SetHealAmount(battlerDef, GetNonDynamaxMaxHP(battlerDef) / 4);
        return BattleScript_MoveHPDrain;
    }
}

const u8 *AbsorbedByStatIncreaseAbility(struct DamageContext *ctx, enum Stat statId, u32 statAmount)
{
    if (!CompareStat(ctx->battlerDef, statId, MAX_STAT_STAGE, CMP_LESS_THAN, ctx->abilities[ctx->battlerDef]))
    {
        return BattleScript_AbilityProtectedTarget;
    }
    else
    {
        if (ctx->runScript)
            SetStatChange(ctx->battlerDef, statId, statAmount);
        return BattleScript_MoveStatDrain;
    }
}

const u8 *AbsorbedByFlashFire(struct DamageContext *ctx)
{
    if (!gBattleMons[ctx->battlerDef].volatiles.flashFireBoosted)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_BOOST;
        if (ctx->runScript)
            gBattleMons[ctx->battlerDef].volatiles.flashFireBoosted = TRUE;
        return BattleScript_FlashFireBoost;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_NO_BOOST;
        return BattleScript_FlashFireBoost;
    }
}

static u32 GetFirstBattlerOnSide(enum BattleSide side)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (GetBattlerSide(battler) == side && !IsBattlerAlive(battler))
            return battler;
    }

    return GetBattlerAtPosition(side == B_SIDE_PLAYER ? B_POSITION_PLAYER_LEFT : B_POSITION_OPPONENT_LEFT);
}

static inline bool32 SetStartingFieldTerrain(enum BattleTerrain terrain, u8 *timer, u16 time)
{
    if (gFieldTimers.terrain != terrain)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleTerrainInfo[terrain].startMessage;
        gFieldTimers.terrain = terrain;
        gBattleScripting.animArg1 = 0;
        *timer = time;

        BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);

        return TRUE;
    }

    return FALSE;
}

static inline bool32 SetStartingFieldStatus(u32 flag, u32 message, u32 anim, u8 *timer, u16 time)
{
    if (!(gFieldStatuses & flag))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = message;
        gFieldStatuses |= flag;
        gBattleScripting.animArg1 = anim;
        *timer = time;

        BattleScriptPushCursorAndCallback(BattleScript_OverworldStatusStarts);

        return TRUE;
    }

    return FALSE;
}

static inline bool32 SetStartingSideStatus(u32 flag, enum BattleSide side, u32 message, u32 anim, u16 *timer, u16 time)
{
    if (!(gSideStatuses[side] & flag))
    {
        gEffectBattler = gBattlerAttacker = gBattlerTarget = (enum BattlerId)side;
        gBattleCommunication[MULTISTRING_CHOOSER] = message;
        gSideStatuses[side] |= flag;
        gBattleScripting.animArg1 = anim;
        *timer = time;
        BattleScriptPushCursorAndCallback(BattleScript_OverworldStatusStarts);

        return TRUE;
    }

    return FALSE;
}

static bool32 SetStartingHazardStatus(enum Hazards hazard, u32 targetSide, u8 layers, enum StartingStatusStringID messageId)
{
    bool32 effect = FALSE;
    u32 setterSide = (targetSide == B_SIDE_PLAYER) ? B_SIDE_OPPONENT : B_SIDE_PLAYER;

    switch (hazard)
    {
    case HAZARDS_SPIKES:
        if (layers != 0)
        {
            if (!IsHazardOnSide(targetSide, HAZARDS_SPIKES))
                PushHazardTypeToQueue(targetSide, HAZARDS_SPIKES);
            gSideTimers[targetSide].spikesAmount = layers;
            effect = TRUE;
        }
        break;
    case HAZARDS_TOXIC_SPIKES:
        if (layers != 0)
        {
            if (!IsHazardOnSide(targetSide, HAZARDS_TOXIC_SPIKES))
                PushHazardTypeToQueue(targetSide, HAZARDS_TOXIC_SPIKES);
            gSideTimers[targetSide].toxicSpikesAmount = layers;
            effect = TRUE;
        }
        break;
    case HAZARDS_STICKY_WEB:
        if (!IsHazardOnSide(targetSide, HAZARDS_STICKY_WEB))
        {
            PushHazardTypeToQueue(targetSide, HAZARDS_STICKY_WEB);
            gSideTimers[targetSide].stickyWebBattlerId = 0xFF;
            gSideTimers[targetSide].stickyWebBattlerSide = setterSide;
            effect = TRUE;
        }
        break;
    case HAZARDS_STEALTH_ROCK:
        if (!IsHazardOnSide(targetSide, HAZARDS_STEALTH_ROCK))
        {
            PushHazardTypeToQueue(targetSide, HAZARDS_STEALTH_ROCK);
            effect = TRUE;
        }
        break;
    case HAZARDS_STEELSURGE:
        if (!IsHazardOnSide(targetSide, HAZARDS_STEELSURGE))
        {
            PushHazardTypeToQueue(targetSide, HAZARDS_STEELSURGE);
            effect = TRUE;
        }
        break;
    case HAZARDS_NONE:
    case HAZARDS_MAX_COUNT:
        break;
    }

    if (effect)
    {
        gBattlerAttacker = GetFirstBattlerOnSide(setterSide);
        gBattleScripting.battler = gBattlerAttacker;
        gBattlerTarget = GetFirstBattlerOnSide(targetSide);
        gBattleCommunication[MULTISTRING_CHOOSER] = messageId;
        BattleScriptPushCursorAndCallback(BattleScript_OverworldHazard);
    }

    return effect;
}

static bool32 SetStartingWeatherStatus(enum BattleWeather weather, bool32 isPermanent)
{
    if (gBattleWeather & gBattleWeatherInfo[weather].flag)
        return FALSE;

    gBattleWeather = gBattleWeatherInfo[weather].flag;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleWeatherInfo[weather].moveStartMessage;
    gBattleScripting.animArg1 = gBattleWeatherInfo[weather].animation;
    if (GetConfig(B_OVERWORLD_WEATHER_OVERRIDE) >= GEN_9)
        gBattleStruct->overworldWeatherPresent = TRUE;

    if (isPermanent)
        gBattleStruct->weatherDuration = 0;
    else
        gBattleStruct->weatherDuration = 5;

    BattleScriptPushCursorAndCallback(BattleScript_OverworldSSWeatherStarts);
    return TRUE;
}

bool32 TryFieldEffects(enum FieldEffectCases caseId)
{
    bool32 effect = FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;

    switch (caseId)
    {
    case FIELD_EFFECT_TRAINER_STATUSES:  // starting field/side/etc statuses with a variable
        if (gStartingStatuses.electricTerrain || gStartingStatuses.electricTerrainTemporary)
        {
            effect = SetStartingFieldTerrain(B_TERRAIN_ELECTRIC, &gFieldTimers.terrainTimer,
                gStartingStatuses.electricTerrain ? 0 : 5);
            gStartingStatuses.electricTerrainTemporary = gStartingStatuses.electricTerrain = FALSE;
            return effect;
        }
        else if (gStartingStatuses.mistyTerrain || gStartingStatuses.mistyTerrainTemporary)
        {
            effect = SetStartingFieldTerrain(B_TERRAIN_MISTY, &gFieldTimers.terrainTimer,
                gStartingStatuses.mistyTerrain ? 0 : 5);
            gStartingStatuses.mistyTerrainTemporary = gStartingStatuses.mistyTerrain = FALSE;
            return effect;
        }
        else if (gStartingStatuses.grassyTerrain || gStartingStatuses.grassyTerrainTemporary)
        {
            effect = SetStartingFieldTerrain(B_TERRAIN_GRASSY, &gFieldTimers.terrainTimer,
                gStartingStatuses.grassyTerrain ? 0 : 5);
            gStartingStatuses.grassyTerrainTemporary = gStartingStatuses.grassyTerrain = FALSE;
            return effect;
        }
        else if (gStartingStatuses.psychicTerrain || gStartingStatuses.psychicTerrainTemporary)
        {
            effect = SetStartingFieldTerrain(B_TERRAIN_PSYCHIC, &gFieldTimers.terrainTimer,
                gStartingStatuses.psychicTerrain ? 0 : 5);
            gStartingStatuses.psychicTerrainTemporary = gStartingStatuses.psychicTerrain = FALSE;
            return effect;
        }
        else if (gStartingStatuses.trickRoom || gStartingStatuses.trickRoomTemporary)
        {
            effect = SetStartingFieldStatus(
                        STATUS_FIELD_TRICK_ROOM,
                        B_MSG_SET_TRICK_ROOM,
                        B_ANIM_TRICK_ROOM,
                        &gFieldTimers.trickRoomTimer, gStartingStatuses.trickRoom ? 0 : 5);
            gStartingStatuses.trickRoomTemporary = gStartingStatuses.trickRoom = FALSE;
            return effect;
        }
        else if (gStartingStatuses.magicRoom || gStartingStatuses.magicRoomTemporary)
        {
            effect = SetStartingFieldStatus(
                        STATUS_FIELD_MAGIC_ROOM,
                        B_MSG_SET_MAGIC_ROOM,
                        B_ANIM_MAGIC_ROOM,
                        &gFieldTimers.magicRoomTimer, gStartingStatuses.magicRoom ? 0 : 5);
            gStartingStatuses.magicRoomTemporary = gStartingStatuses.magicRoom = FALSE;
            return effect;
        }
        else if (gStartingStatuses.wonderRoom || gStartingStatuses.wonderRoomTemporary)
        {
            effect = SetStartingFieldStatus(
                        STATUS_FIELD_WONDER_ROOM,
                        B_MSG_SET_WONDER_ROOM,
                        B_ANIM_WONDER_ROOM,
                        &gFieldTimers.wonderRoomTimer,  gStartingStatuses.wonderRoom ? 0 : 5);
            gStartingStatuses.wonderRoomTemporary = gStartingStatuses.wonderRoom = FALSE;
            return effect;
        }
        else if (gStartingStatuses.tailwindPlayer || gStartingStatuses.tailwindPlayerTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_TAILWIND,
                        B_SIDE_PLAYER,
                        B_MSG_SET_TAILWIND,
                        B_ANIM_TAILWIND,
                        &gSideTimers[B_SIDE_PLAYER].tailwindTimer, gStartingStatuses.tailwindPlayer ? 0 : (B_TAILWIND_TURNS >= GEN_5 ? 4 : 3));
            gStartingStatuses.tailwindPlayerTemporary = gStartingStatuses.tailwindPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.tailwindOpponent || gStartingStatuses.tailwindOpponentTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_TAILWIND,
                        B_SIDE_OPPONENT,
                        B_MSG_SET_TAILWIND,
                        B_ANIM_TAILWIND,
                        &gSideTimers[B_SIDE_OPPONENT].tailwindTimer, gStartingStatuses.tailwindOpponent ? 0 : (B_TAILWIND_TURNS >= GEN_5 ? 4 : 3));
            gStartingStatuses.tailwindOpponentTemporary = gStartingStatuses.tailwindOpponent = FALSE;
            return effect;
        }
        else if (gStartingStatuses.rainbowPlayer || gStartingStatuses.rainbowPlayerTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_RAINBOW,
                        B_SIDE_PLAYER,
                        B_MSG_SET_RAINBOW,
                        B_ANIM_RAINBOW,
                        &gSideTimers[B_SIDE_PLAYER].rainbowTimer, gStartingStatuses.rainbowPlayer ? 0 : 4);
            gStartingStatuses.rainbowPlayerTemporary = gStartingStatuses.rainbowPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.rainbowOpponent || gStartingStatuses.rainbowOpponentTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_RAINBOW,
                        B_SIDE_OPPONENT,
                        B_MSG_SET_RAINBOW,
                        B_ANIM_RAINBOW,
                        &gSideTimers[B_SIDE_OPPONENT].rainbowTimer, gStartingStatuses.rainbowOpponent ? 0 : 4);
            gStartingStatuses.rainbowOpponentTemporary = gStartingStatuses.rainbowOpponent = FALSE;
            return effect;
        }
        else if (gStartingStatuses.seaOfFirePlayer || gStartingStatuses.seaOfFirePlayerTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_SEA_OF_FIRE,
                        B_SIDE_PLAYER,
                        B_MSG_SET_SEA_OF_FIRE,
                        B_ANIM_SEA_OF_FIRE,
                        &gSideTimers[B_SIDE_PLAYER].seaOfFireTimer, gStartingStatuses.seaOfFirePlayer ? 0 : 4);
            gStartingStatuses.seaOfFirePlayerTemporary = gStartingStatuses.seaOfFirePlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.seaOfFireOpponent || gStartingStatuses.seaOfFireOpponentTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_SEA_OF_FIRE,
                        B_SIDE_OPPONENT,
                        B_MSG_SET_SEA_OF_FIRE,
                        B_ANIM_SEA_OF_FIRE,
                        &gSideTimers[B_SIDE_OPPONENT].seaOfFireTimer, gStartingStatuses.seaOfFireOpponent ? 0 : 4);
            gStartingStatuses.seaOfFireOpponentTemporary = gStartingStatuses.seaOfFireOpponent = FALSE;
            return effect;
        }
        else if (gStartingStatuses.swampPlayer || gStartingStatuses.swampPlayerTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_SWAMP,
                        B_SIDE_PLAYER,
                        B_MSG_SET_SWAMP,
                        B_ANIM_SWAMP,
                        &gSideTimers[B_SIDE_PLAYER].swampTimer, gStartingStatuses.swampPlayer ? 0 : 4);
            gStartingStatuses.swampPlayerTemporary = gStartingStatuses.swampPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.swampOpponent || gStartingStatuses.swampOpponentTemporary)
        {
            effect = SetStartingSideStatus(
                        SIDE_STATUS_SWAMP,
                        B_SIDE_OPPONENT,
                        B_MSG_SET_SWAMP,
                        B_ANIM_SWAMP,
                        &gSideTimers[B_SIDE_OPPONENT].swampTimer, gStartingStatuses.swampOpponent ? 0 : 4);
            gStartingStatuses.swampOpponentTemporary = gStartingStatuses.swampOpponent = FALSE;
            return effect;
        }
        // Hazards - Spikes
        else if (gStartingStatuses.spikesPlayerL1)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_PLAYER, 1, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesPlayerL1 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.spikesPlayerL2)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_PLAYER, 2, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesPlayerL2 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.spikesPlayerL3)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_PLAYER, 3, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesPlayerL3 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.spikesOpponentL1)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_OPPONENT, 1, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesOpponentL1 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.spikesOpponentL2)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_OPPONENT, 2, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesOpponentL2 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.spikesOpponentL3)
        {
            effect = SetStartingHazardStatus(HAZARDS_SPIKES, B_SIDE_OPPONENT, 3, B_MSG_SET_SPIKES);
            gStartingStatuses.spikesOpponentL3 = FALSE;
            return effect;
        }
        // Hazards - Toxic Spikes
        else if (gStartingStatuses.toxicSpikesPlayerL1)
        {
            effect = SetStartingHazardStatus(HAZARDS_TOXIC_SPIKES, B_SIDE_PLAYER, 1, B_MSG_SET_POISON_SPIKES);
            gStartingStatuses.toxicSpikesPlayerL1 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.toxicSpikesPlayerL2)
        {
            effect = SetStartingHazardStatus(HAZARDS_TOXIC_SPIKES, B_SIDE_PLAYER, 2, B_MSG_SET_POISON_SPIKES);
            gStartingStatuses.toxicSpikesPlayerL2 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.toxicSpikesOpponentL1)
        {
            effect = SetStartingHazardStatus(HAZARDS_TOXIC_SPIKES, B_SIDE_OPPONENT, 1, B_MSG_SET_POISON_SPIKES);
            gStartingStatuses.toxicSpikesOpponentL1 = FALSE;
            return effect;
        }
        else if (gStartingStatuses.toxicSpikesOpponentL2)
        {
            effect = SetStartingHazardStatus(HAZARDS_TOXIC_SPIKES, B_SIDE_OPPONENT, 2, B_MSG_SET_POISON_SPIKES);
            gStartingStatuses.toxicSpikesOpponentL2 = FALSE;
            return effect;
        }
        // Hazards - Sticky Web
        else if (gStartingStatuses.stickyWebPlayer)
        {
            effect = SetStartingHazardStatus(HAZARDS_STICKY_WEB, B_SIDE_PLAYER, 1, B_MSG_SET_STICKY_WEB);
            gStartingStatuses.stickyWebPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.stickyWebOpponent)
        {
            effect = SetStartingHazardStatus(HAZARDS_STICKY_WEB, B_SIDE_OPPONENT, 1, B_MSG_SET_STICKY_WEB);
            gStartingStatuses.stickyWebOpponent = FALSE;
            return effect;
        }
        // Hazards - Stealth Rock
        else if (gStartingStatuses.stealthRockPlayer)
        {
            effect = SetStartingHazardStatus(HAZARDS_STEALTH_ROCK, B_SIDE_PLAYER, 1, B_MSG_SET_STEALTH_ROCK);
            gStartingStatuses.stealthRockPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.stealthRockOpponent)
        {
            effect = SetStartingHazardStatus(HAZARDS_STEALTH_ROCK, B_SIDE_OPPONENT, 1, B_MSG_SET_STEALTH_ROCK);
            gStartingStatuses.stealthRockOpponent = FALSE;
            return effect;
        }
        // Hazards - Steelsurge
        else if (gStartingStatuses.sharpSteelPlayer)
        {
            effect = SetStartingHazardStatus(HAZARDS_STEELSURGE, B_SIDE_PLAYER, 1, B_MSG_SET_SHARP_STEEL);
            gStartingStatuses.sharpSteelPlayer = FALSE;
            return effect;
        }
        else if (gStartingStatuses.sharpSteelOpponent)
        {
            effect = SetStartingHazardStatus(HAZARDS_STEELSURGE, B_SIDE_OPPONENT, 1, B_MSG_SET_SHARP_STEEL);
            gStartingStatuses.sharpSteelOpponent = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherSun || gStartingStatuses.weatherSunTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_SUN, gStartingStatuses.weatherSun);
            gStartingStatuses.weatherSun = gStartingStatuses.weatherSunTemporary = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherRain || gStartingStatuses.weatherRainTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_RAIN, gStartingStatuses.weatherRain);
            gStartingStatuses.weatherRain = gStartingStatuses.weatherRainTemporary = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherSandstorm || gStartingStatuses.weatherSandstormTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_SANDSTORM, gStartingStatuses.weatherSandstorm);
            gStartingStatuses.weatherSandstorm = gStartingStatuses.weatherSandstormTemporary = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherHail || gStartingStatuses.weatherHailTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_HAIL, gStartingStatuses.weatherHail);
            gStartingStatuses.weatherHail = gStartingStatuses.weatherHailTemporary = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherSnow || gStartingStatuses.weatherSnowTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_SNOW, gStartingStatuses.weatherSnow);
            gStartingStatuses.weatherSnow = gStartingStatuses.weatherSnowTemporary = FALSE;
            return effect;
        }
        else if (gStartingStatuses.weatherFog || gStartingStatuses.weatherFogTemporary)
        {
            effect = SetStartingWeatherStatus(BATTLE_WEATHER_FOG, gStartingStatuses.weatherFog);
            gStartingStatuses.weatherFog = gStartingStatuses.weatherFogTemporary = FALSE;
            return effect;
        }
        break;
    case FIELD_EFFECT_OVERWORLD_TERRAIN:   // terrain starting from overworld weather
        if (B_THUNDERSTORM_TERRAIN == TRUE
         && gFieldTimers.terrain != B_TERRAIN_ELECTRIC
         && GetCurrentWeather() == WEATHER_RAIN_THUNDERSTORM)
        {
            // overworld weather started rain, so just do electric terrain anim
            gFieldTimers.terrain = B_TERRAIN_ELECTRIC;
            gFieldTimers.terrainTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
            BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
            effect = TRUE;
        }
        else if (B_OVERWORLD_FOG >= GEN_8
              && (GetCurrentWeather() == WEATHER_FOG_HORIZONTAL || GetCurrentWeather() == WEATHER_FOG_DIAGONAL)
              && gFieldTimers.terrain != B_TERRAIN_MISTY)
        {
            gFieldTimers.terrain = B_TERRAIN_MISTY;
            gFieldTimers.terrainTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
            BattleScriptPushCursorAndCallback(BattleScript_OverworldTerrain);
            effect = TRUE;
        }
        break;
    case FIELD_EFFECT_OVERWORLD_WEATHER:
        if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        {
            switch (GetCurrentWeather())
            {
            case WEATHER_RAIN:
            case WEATHER_RAIN_THUNDERSTORM:
            case WEATHER_DOWNPOUR:
                if (!(gBattleWeather & B_WEATHER_RAIN))
                {
                    gBattleWeather = B_WEATHER_RAIN_NORMAL;
                    gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
                    effect = TRUE;
                }
                break;
            case WEATHER_SANDSTORM:
                if (!(gBattleWeather & B_WEATHER_SANDSTORM))
                {
                    gBattleWeather = B_WEATHER_SANDSTORM;
                    gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                    effect = TRUE;
                }
                break;
            case WEATHER_DROUGHT:
                if (!(gBattleWeather & B_WEATHER_SUN))
                {
                    gBattleWeather = B_WEATHER_SUN_NORMAL;
                    gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
                    effect = TRUE;
                }
                break;
            case WEATHER_SNOW:
                if (!(gBattleWeather & B_WEATHER_ICY_ANY))
                {
                    if (B_OVERWORLD_SNOW >= GEN_9)
                    {
                        gBattleWeather = B_WEATHER_SNOW;
                        gBattleScripting.animArg1 = B_ANIM_SNOW_CONTINUES;
                    }
                    else
                    {
                        gBattleWeather = B_WEATHER_HAIL;
                        gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                    }
                    effect = TRUE;
                }
                break;
            case WEATHER_FOG_DIAGONAL:
            case WEATHER_FOG_HORIZONTAL:
                if (B_OVERWORLD_FOG == GEN_4 && !(gBattleWeather & B_WEATHER_FOG))
                {
                    gBattleWeather = B_WEATHER_FOG;
                    gBattleScripting.animArg1 = B_ANIM_FOG_CONTINUES;
                    effect = TRUE;
                }
                break;
            }
        }
        if (effect)
        {
            if (GetConfig(B_OVERWORLD_WEATHER_OVERRIDE) >= GEN_9)
                gBattleStruct->overworldWeatherPresent = TRUE;
            gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeather();
            BattleScriptPushCursorAndCallback(BattleScript_OverworldWeatherStarts);
        }
        break;
    }

    return effect;
}

static bool32 IsRestrictedAbility(enum BattlerId battler, enum Ability ability)
{
    return GetSpeciesAbility(gBattleMons[battler].species, 0) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 1) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 2) == ability;
}

static bool32 TryDancer(void)
{
    u32 order = 0;
    enum BattlerId dancerBattler = MAX_BATTLERS_COUNT;

    if (!IsDanceMove(gCurrentMove))
        return FALSE;

    for (order = 0; order < gBattlersCount; order++)
    {
        if (GetConfig(B_DANCER_ORDER) < GEN_8)
            dancerBattler = gBattlersByRawSpeed[gBattlersCount - order - 1]; // pick from slowest to fastest Raw Speed
        else
            dancerBattler = gBattlersBySpeed[order]; // pick from fastest to slowest Speed including modifiers

        if (gBattleMons[dancerBattler].volatiles.activateDancer && !gSpecialStatuses[dancerBattler].dancerUsedMove)
            break;
    }

    if (order >= gBattlersCount) // no battler activates Dancer
        return FALSE;

    // Dance move succeeds
    // Set target for other Dancer mons; set bit so that mon cannot activate Dancer off of its own move
    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
    {
        gBattleStruct->dancerSavedTarget = gBattlerTarget;
        gBattleStruct->dancerSavedAttacker = gBattlerAttacker;
        gSpecialStatuses[gBattlerAttacker].dancerUsedMove = TRUE;
    }

    if (IsBattlerAlive(dancerBattler))
    {
        gSpecialStatuses[dancerBattler].dancerUsedMove = TRUE;
        gSpecialStatuses[dancerBattler].backUpTarget = gBattleStruct->moveTarget[dancerBattler] + 1;
        gBattleMons[dancerBattler].volatiles.activateDancer = FALSE;
        gBattlerAttacker = gBattlerAbility = dancerBattler;
        gCalledMove = gCurrentMove;
        gLastUsedAbility = ABILITY_DANCER;
        RecordAbilityBattle(gBattlerAttacker, ABILITY_DANCER);

        // Set the target to the original target of the mon that first used a Dance move
        gBattlerTarget = gBattleStruct->dancerSavedTarget;

        // Make sure that the target isn't an ally - if it is, target the original user
        if (IsBattlerAlly(gBattlerTarget, gBattlerAttacker))
            gBattlerTarget = gBattleStruct->dancerSavedAttacker;

        BattleScriptExecute(BattleScript_DancerActivates);
        return TRUE;
    }

    return FALSE;
}

u32 AbilityBattleEffects(enum AbilityEffect caseID, enum BattlerId battler, enum Ability ability, enum Move move, bool32 shouldAbilityTrigger)
{
    u32 effect = 0;
    enum Type moveType = 0;
    u32 side = 0;
    u32 i = 0, j = 0;
    u32 partner = 0;
    enum Species speciesForm = SPECIES_NONE;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return 0;

    if (gBattlerAttacker >= gBattlersCount)
        gBattlerAttacker = battler;

    if (ability)
        gLastUsedAbility = ability;
    else
        gLastUsedAbility = GetBattlerAbility(battler);

    if (move == MOVE_NONE)
        move = gCurrentMove;

    moveType = GetBattleMoveType(move);

    switch (caseID)
    {
    case ABILITYEFFECT_ON_FORM_CHANGE:
        switch (gLastUsedAbility)
        {
        case ABILITY_TERAFORM_ZERO:
            if (gBattleStruct->overworldWeatherPresent)
            {
                if (gFieldTimers.terrain != B_TERRAIN_NONE)
                    BattleScriptCall(BattleScript_ActivateTeraformZeroRemovesOnlyTerrain);
                else
                    BattleScriptCall(BattleScript_BlockedByOverworldWeather);
                effect++;
            }
            else if (gBattleWeather != WEATHER_NONE || gFieldTimers.terrain != B_TERRAIN_NONE)
            {
                BattleScriptCall(BattleScript_ActivateTeraformZero);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_SWITCHIN:
        gBattleScripting.battler = battler;
        switch (gLastUsedAbility)
        {
        case ABILITY_TRACE:
            if (!gBattleMons[battler].volatiles.traceActivated)
            {
                enum BattlerId chosenTarget;
                enum BattlerId target1;
                enum BattlerId target2;

                side = (GetBattlerSide(battler) ^ BIT_SIDE);
                target1 = GetBattlerAtPosition(side);
                target2 = GetBattlerAtPosition(side + BIT_FLANK);
                if (IsDoubleBattle())
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0
                        && !gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = GetBattlerAtPosition((RandomPercentage(RNG_TRACE, 50) * 2) | side), effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = target2, effect++;
                }
                else
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                }

                if (effect != 0)
                {
                    gBattleMons[battler].volatiles.traceActivated = TRUE;
                    if (GetBattlerHoldEffectIgnoreAbility(battler) == HOLD_EFFECT_ABILITY_SHIELD)
                        break;
                    BattleScriptCall(BattleScript_TraceActivates);
                    gBattleStruct->tracedAbility[battler] = gLastUsedAbility = gBattleMons[chosenTarget].ability;
                    RecordAbilityBattle(chosenTarget, gLastUsedAbility); // Record the opposing battler has this ability
                    PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff1, chosenTarget, gBattlerPartyIndexes[chosenTarget])
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
                }
            }
            break;
        case ABILITY_IMPOSTER:
            if (gBattleStruct->battlerState[battler].switchIn)
            {
                enum BattlerId diagonalBattler = GetOppositeBattler(battler);
                if (IsDoubleBattle())
                    diagonalBattler = GetPartnerBattler(diagonalBattler);

                // Imposter only activates when the battler first switches in
                if (!gBattleMons[battler].volatiles.overwrittenAbility
                    && IsBattlerAlive(diagonalBattler)
                    && !gBattleMons[diagonalBattler].volatiles.substitute
                    && !gBattleMons[diagonalBattler].volatiles.transformed
                    && !gBattleMons[battler].volatiles.transformed
                    && gBattleStruct->illusion[diagonalBattler].state != ILLUSION_ON
                    && !IsSemiInvulnerable(diagonalBattler, EXCLUDE_COMMANDER))
                {
                    SaveBattlerAttacker(gBattlerAttacker);
                    SaveBattlerTarget(gBattlerTarget);
                    gBattlerAttacker = battler;
                    gBattlerTarget = diagonalBattler;
                    BattleScriptCall(BattleScript_ImposterActivates);
                    effect++;
                }
            }
            break;
        case ABILITY_MOLD_BREAKER:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_MOLDBREAKER;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TERAVOLT:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TERAVOLT;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TURBOBLAZE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TURBOBLAZE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SLOW_START:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.slowStartTimer = B_SLOW_START_TIMER;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SLOWSTART;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_CURIOUS_MEDICINE:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && IsBattlerAlive(GetPartnerBattler(battler))
             && TryResetBattlerStatChanges(GetPartnerBattler(battler)))
            {
                gEffectBattler = GetPartnerBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CURIOUS_MEDICINE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_PASTEL_VEIL:
            if (shouldAbilityTrigger)
            {
                SaveBattlerTarget(gBattlerTarget);
                gBattlerTarget = battler;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PASTEL_VEIL;
                BattleScriptCall(BattleScript_PastelVeilActivates);
                effect++;
            }
            break;
        case ABILITY_ANTICIPATION:
            if (shouldAbilityTrigger)
            {
                struct DamageContext ctx = {0};
                uq4_12_t modifier = UQ_4_12(1.0);
                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (IsBattlerAlive(i) && !IsBattlerAlly(i, battler))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            move = gBattleMons[i].moves[j];
                            enum BattleMoveEffects moveEffect = GetMoveEffect(move);
                            moveType = GetBattleMoveType(move);

                            ctx.battlerAtk = i;
                            ctx.battlerDef = battler;
                            ctx.move = ctx.chosenMove = ctx.baseMove = move;
                            ctx.moveType = moveType;
                            ctx.isAnticipation = TRUE;
                            modifier = CalcTypeEffectivenessMultiplier(&ctx);

                            if (modifier >= UQ_4_12(2.0) || moveEffect == EFFECT_OHKO)
                            {
                                effect++;
                                break;
                            }
                        }
                    }
                }

                if (effect != 0)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ANTICIPATION;
                    BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                }
            }
            break;
        case ABILITY_FRISK:
            if (shouldAbilityTrigger)
            {
                enum BattlerId battlerDef = B_BATTLER_0;

                for (battlerDef = B_BATTLER_0; battlerDef < gBattlersCount; battlerDef++)
                {
                    if (IsBattlerAlly(battler, battlerDef) || !IsBattlerAlive(battlerDef))
                        continue;
                    if (gBattleMons[battlerDef].item != ITEM_NONE)
                        break;
                }

                if (battlerDef == gBattlersCount)
                    break; // no item found

                gBattlerAbility = gEffectBattler = battler;
                BattleScriptCall(BattleScript_FriskActivates);
                effect++;
            }
            return effect; // Note: It returns effect as to not record the ability if Frisk does not activate.
        case ABILITY_FOREWARN:
            if (shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
            {
                ForewarnChooseMove(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FOREWARN;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DOWNLOAD:
            if (shouldAbilityTrigger)
            {
                enum Stat statId = GetDownloadStat(battler);

                if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, statId, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_PRESSURE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DARK_AURA:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_DARKAURA;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_FAIRY_AURA:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AURA_BREAK:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_AURABREAK;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_COMATOSE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COMATOSE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SCREEN_CLEANER:
            if (shouldAbilityTrigger && TryRemoveScreens(battler))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SCREENCLEANER;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DRIZZLE:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_SAND_STREAM:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SANDSTORM, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_DROUGHT:
        case ABILITY_ORICHALCUM_PULSE:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_SNOW_WARNING:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, GetConfig(B_SNOW_WARNING) >= GEN_9 ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_ELECTRIC_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
            {
                BattleScriptCall(BattleScript_ElectricSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_HADRON_ENGINE:
            if (!shouldAbilityTrigger)
                break;
            if (gFieldTimers.terrain == B_TERRAIN_ELECTRIC)
            {
                BattleScriptCall(BattleScript_HadronEngineActivatesInTerrain);
                effect++;
            }
            else if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
            {
                BattleScriptCall(BattleScript_HadronEngineActivates);
                effect++;
            }
            break;
        case ABILITY_GRASSY_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_GRASSY))
            {
                BattleScriptCall(BattleScript_GrassySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_MISTY_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_MISTY))
            {
                BattleScriptCall(BattleScript_MistySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_PSYCHIC_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_PSYCHIC))
            {
                BattleScriptCall(BattleScript_PsychicSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_INTIMIDATE:
            if (shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
            {
                gEffectBattler = battler;
                gBattleStruct->intimidateActivated = TRUE; // For rattled and Adrenaile Orb
                for (enum BattlerId i = 0; i < gBattlersCount; i++)
                {
                    if (IsBattlerAlly(battler, i) || !IsBattlerAlive(i))
                        continue;
                    SetStatChange(i, STAT_ATK, -1);
                }
                BattleScriptCall(BattleScript_IntimidateActivates); // Sets a flag to check for intim failure. Similar abilities should use BattleScript_AbilityStatChange.
                effect++;
            }
            break;
        case ABILITY_SUPERSWEET_SYRUP:
            if (shouldAbilityTrigger
             && !GetBattlerPartyState(battler)->supersweetSyrup
             && !IsOpposingSideEmpty(battler))
            {
                gEffectBattler = battler;
                GetBattlerPartyState(battler)->supersweetSyrup = TRUE;
                for (enum BattlerId i = 0; i < gBattlersCount; i++)
                {
                    if (IsBattlerAlly(battler, i) || !IsBattlerAlive(i))
                        continue;
                    SetStatChange(i, STAT_EVASION, -1);
                }
                BattleScriptCall(BattleScript_SupersweetSyrupActivates);
                effect++;
            }
            break;
        case ABILITY_CLOUD_NINE:
        case ABILITY_AIR_LOCK:
            if (shouldAbilityTrigger)
            {
                BattleScriptCall(BattleScript_AnnounceAirLockCloudNine);
                effect++;
            }
            break;
        case ABILITY_INTREPID_SWORD:
            if (shouldAbilityTrigger && !GetBattlerPartyState(battler)->intrepidSwordBoost)
            {
                if (GetConfig(B_INTREPID_SWORD) >= GEN_9)
                    GetBattlerPartyState(battler)->intrepidSwordBoost = TRUE;

                if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, STAT_ATK, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_DAUNTLESS_SHIELD:
            if (shouldAbilityTrigger && !GetBattlerPartyState(battler)->dauntlessShieldBoost)
            {
                if (GetConfig(B_DAUNTLESS_SHIELD) >= GEN_9)
                    GetBattlerPartyState(battler)->dauntlessShieldBoost = TRUE;

                if (CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, STAT_DEF, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_WIND_RIDER:
            if (shouldAbilityTrigger
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility)
             && gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_DESOLATE_LAND:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN_PRIMAL, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_PRIMORDIAL_SEA:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN_PRIMAL, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_DELTA_STREAM:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_STRONG_WINDS, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_VESSEL_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.vesselOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPATK);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_SWORD_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.swordOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_DEF);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_TABLETS_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.tabletsOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_BEADS_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.beadsOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPDEF);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_SUPREME_OVERLORD:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.supremeOverlordCounter = min(5, gBattleStruct->faintCounter[GetBattlerTrainer(battler)]);
                if (gBattleMons[battler].volatiles.supremeOverlordCounter > 0)
                {
                    BattleScriptCall(BattleScript_SupremeOverlordActivates);
                    effect++;
                }
            }
            break;
        case ABILITY_ZERO_TO_HERO:
            if (GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES) == SPECIES_PALAFIN_HERO
             && !GetBattlerPartyState(battler)->transformZeroToHero)
            {
                GetBattlerPartyState(battler)->transformZeroToHero = TRUE;
                BattleScriptCall(BattleScript_ZeroToHeroActivates);
                effect++;
            }
            break;
        case ABILITY_EMBODY_ASPECT_TEAL_MASK:
        case ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK:
        case ABILITY_EMBODY_ASPECT_WELLSPRING_MASK:
        case ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.embodyAspectActivated)
            {
                enum Stat stat;
                gBattleMons[battler].volatiles.embodyAspectActivated = TRUE;

                if (gLastUsedAbility == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
                    stat = STAT_ATK;
                else if (gLastUsedAbility == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
                    stat = STAT_SPDEF;
                else if (gLastUsedAbility == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
                    stat = STAT_DEF;
                else //ABILITY_EMBODY_ASPECT_TEAL_MASK
                    stat = STAT_SPEED;

                if (CompareStat(battler, stat, MAX_STAT_STAGE, CMP_EQUAL, gLastUsedAbility))
                    break;

                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, stat, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_SWITCH_IN_FORM_CHANGE:
        if (shouldAbilityTrigger && TryBattleFormChange(battler, FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT, ability))
        {
            gBattleScripting.battler = battler;
            // To prevent the new form's ability from pop up
            gBattleScripting.abilityPopupOverwrite = ability;
            BattleScriptCall(BattleScript_BattlerFormChange);
            effect++;
        }
        break;
    case ABILITYEFFECT_ENDTURN:
        if (IsBattlerAlive(battler))
        {
            gBattlerAttacker = battler;
            switch (gLastUsedAbility)
            {
            case ABILITY_PICKUP:
                if (gBattleMons[battler].item == ITEM_NONE
                 && PickupHasValidTarget(battler))
                {
                    gBattlerTarget = RandomUniformExcept(RNG_PICKUP, 0, gBattlersCount - 1, CantPickupItem);
                    gLastUsedItem = GetBattlerPartyState(gBattlerTarget)->usedHeldItem;
                    BattleScriptCall(BattleScript_PickupActivates);
                    effect++;
                }
                break;
            case ABILITY_HARVEST:
                if ((IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_SUN) || RandomPercentage(RNG_HARVEST, 50))
                 && gBattleMons[battler].item == ITEM_NONE
                 && GetItemPocket(GetBattlerPartyState(battler)->usedHeldItem) == POCKET_BERRIES)
                {
                    gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
                    BattleScriptCall(BattleScript_HarvestActivates);
                    effect++;
                }
                break;
            case ABILITY_ICE_BODY:
                if (IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_ICY_ANY)
                 && !IsBattlerAtMaxHp(battler)
                 && gBattleMons[battler].volatiles.semiInvulnerable != STATE_UNDERGROUND
                 && gBattleMons[battler].volatiles.semiInvulnerable != STATE_UNDERWATER
                 && !gBattleMons[battler].volatiles.healBlockTimer)
                {
                    BattleScriptCall(BattleScript_IceBodyHeal);
                    SetHealAmount(battler, GetNonDynamaxMaxHP(battler) / 16);
                    effect++;
                }
                break;
            case ABILITY_DRY_SKIN:
                if (IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_SUN))
                    goto SOLAR_POWER_HP_DROP;
            // Dry Skin works similarly to Rain Dish in Rain
            case ABILITY_RAIN_DISH:
                if (IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_RAIN)
                 && !IsBattlerAtMaxHp(battler)
                 && !gBattleMons[battler].volatiles.healBlockTimer)
                {
                    s32 healAmount = gLastUsedAbility == ABILITY_RAIN_DISH ? 16 : 8;
                    SetHealAmount(battler, GetNonDynamaxMaxHP(battler) / healAmount);
                    BattleScriptCall(BattleScript_AbilityHpHeal);
                    effect++;
                }
                break;
            case ABILITY_HYDRATION:
                if (IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_RAIN)
                 && gBattleMons[battler].status1 & STATUS1_ANY)
                {
                    goto ABILITY_HEAL_MON_STATUS;
                }
                break;
            case ABILITY_SHED_SKIN:
                if ((gBattleMons[battler].status1 & STATUS1_ANY)
                 && (GetConfig(B_ABILITY_TRIGGER_CHANCE) == GEN_4 ? RandomPercentage(RNG_SHED_SKIN, 30) : RandomChance(RNG_SHED_SKIN, 1, 3)))
                {
                ABILITY_HEAL_MON_STATUS:
                    if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
                        TryDeactivateSleepClause(battler, gBattlerPartyIndexes[battler]);
                    }
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
                    if (gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;

                    gBattleMons[battler].status1 = 0;
                    gBattleMons[battler].volatiles.nightmare = FALSE;
                    gBattleScripting.battler = battler;
                    BattleScriptCall(BattleScript_ShedSkinActivates);
                    BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarkBattlerForControllerExec(battler);
                    effect++;
                }
                break;
            case ABILITY_SPEED_BOOST:
                if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility) && !BattlerJustSwitchedIn(battler))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, STAT_SPEED, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
                break;
            case ABILITY_MOODY:
                {
                    enum Stat stat = STAT_ATK;
                    u32 validToRaise = 0, validToLower = 0;
                    u32 statsNum = GetConfig(B_MOODY_ACC_EVASION) >= GEN_8 ? NUM_STATS : NUM_BATTLE_STATS;

                    for (stat = STAT_ATK; stat < statsNum; stat++)
                    {
                        if (CompareStat(battler, stat, MIN_STAT_STAGE, CMP_GREATER_THAN, gLastUsedAbility))
                            validToLower |= 1u << stat;
                        if (CompareStat(battler, stat, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
                            validToRaise |= 1u << stat;
                    }

                    if (validToRaise) // Find stat to raise
                    {
                        stat = RandomUniformExcept(RNG_MOODY_INCREASE, STAT_ATK, statsNum - 1, MoodyCantRaiseStat);
                        SetStatChange(battler, stat, 2);
                        validToLower &= ~(1u << stat); // Can't lower the same stat as raising.
                    }
                    if (validToLower) // Find stat to lower
                    {
                        // MoodyCantLowerStat already checks that both stats are different
                        stat = RandomUniformExcept(RNG_MOODY_DECREASE, STAT_ATK, statsNum - 1, MoodyCantLowerStat);
                        SetStatChange(battler, stat, -1);
                    }

                    gEffectBattler = gBattlerAbility = battler;
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
                break;
            case ABILITY_TRUANT:
                gBattleMons[gBattlerAttacker].volatiles.truantCounter ^= 1;
                break;
            case ABILITY_SLOW_START:
                if (gBattleMons[battler].volatiles.slowStartTimer > 0 && --gBattleMons[battler].volatiles.slowStartTimer == 0)
                {
                    BattleScriptCall(BattleScript_SlowStartEnds);
                    effect++;
                }
                break;
            case ABILITY_BAD_DREAMS:
                BattleScriptCall(BattleScript_BadDreamsActivates);
                effect++;
                break;
            case ABILITY_SOLAR_POWER:
                if (IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), GetWeather(), B_WEATHER_SUN))
                {
                SOLAR_POWER_HP_DROP:
                    SetPassiveDamageAmount(battler, GetNonDynamaxMaxHP(battler) / 8);
                    BattleScriptCall(BattleScript_SolarPowerActivates);
                    effect++;
                }
                break;
            case ABILITY_HEALER:
                gBattleScripting.battler = GetPartnerBattler(battler);
                if (IsBattlerAlive(gBattleScripting.battler)
                 && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY
                 && RandomPercentage(RNG_HEALER, 30))
                {
                    BattleScriptCall(BattleScript_HealerActivates);
                    effect++;
                }
                break;
            case ABILITY_BALL_FETCH:
                if (!(gBattleTypeFlags & BATTLE_TYPE_RAID)
                 && gBattleMons[battler].item == ITEM_NONE
                 && gBattleResults.catchAttempts[ItemIdToBallId(gLastUsedBall)] >= 1
                 && !gHasFetchedBall)
                {
                    gLastUsedItem = gLastUsedBall;
                    gBattleScripting.battler = battler;
                    gBattleMons[battler].item = gLastUsedItem;
                    BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
                    MarkBattlerForControllerExec(battler);
                    gHasFetchedBall = TRUE;
                    BattleScriptCall(BattleScript_BallFetch);
                    effect++;
                }
                break;
            case ABILITY_CUD_CHEW:
                if (gBattleMons[battler].volatiles.cudChew == TRUE)
                {
                    gBattleScripting.battler = battler;
                    gBattleMons[battler].volatiles.cudChew = FALSE;
                    gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
                    GetBattlerPartyState(battler)->usedHeldItem = ITEM_NONE;
                    BattleScriptCall(BattleScript_CudChewActivates);
                    effect++;
                }
                else if (!gBattleMons[battler].volatiles.cudChew && GetItemPocket(GetBattlerPartyState(battler)->usedHeldItem) == POCKET_BERRIES)
                {
                    gBattleMons[battler].volatiles.cudChew = TRUE;
                }
                break;
            default:
                break;
            }
        }
        break;
    case ABILITYEFFECT_COLOR_CHANGE:
        switch (gLastUsedAbility)
        {
        case ABILITY_COLOR_CHANGE:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !IS_BATTLER_OF_TYPE(battler, moveType)
             && move != MOVE_STRUGGLE
             && moveType != TYPE_STELLAR
             && moveType != TYPE_MYSTERY)
            {
                gEffectBattler = gBattlerAbility = battler;
                SET_BATTLER_TYPE(battler, moveType);
                PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
                BattleScriptCall(BattleScript_ColorChangeActivates);
                effect++;
            }
            break;
        case ABILITY_BERSERK:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && HadMoreThanHalfHpNowDoesnt(battler)
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_ANGER_SHELL:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && HadMoreThanHalfHpNowDoesnt(battler))
            {
                gEffectBattler = gBattlerAbility = battler;
                if (CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN, ABILITY_NONE))
                    SetStatChange(battler, STAT_DEF, -1);

                if (CompareStat(battler, STAT_SPDEF, MIN_STAT_STAGE, CMP_GREATER_THAN, ABILITY_NONE))
                    SetStatChange(battler, STAT_SPDEF, -1);

                if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                    SetStatChange(battler, STAT_ATK, 1);

                if (CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                    SetStatChange(battler, STAT_SPATK, 1);

                if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                    SetStatChange(battler, STAT_SPEED, 1);

                if (gSpecialStatuses[battler].statStageAmount > 0)
                    BattleScriptCall(BattleScript_AbilityStatChange);
                else // Not sure if there is an actual ability popup in this case
                    BattleScriptCall(BattleScript_AbilityPopUp);

                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END: // Think contact abilities.
        switch (gLastUsedAbility)
        {
        case ABILITY_JUSTIFIED:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && moveType == TYPE_DARK
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WATER_COMPACTION:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && moveType == TYPE_WATER
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, 2);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_STAMINA:
            if (gBattlerAttacker != gBattlerTarget
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && IsBattleMovePhysical(gCurrentMove)
             && (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility) // Don't activate if both Speed and Defense cannot be raised.
               || CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN, gLastUsedAbility)))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, -1);
                if (GetConfig(B_WEAK_ARMOR_SPEED) >= GEN_7)
                    SetStatChange(battler, STAT_SPEED, 2);
                else
                    SetStatChange(battler, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && GetMoveEffect(move) != EFFECT_FUTURE_SIGHT
             && gBattleMons[gBattlerAttacker].volatiles.disabledMove == MOVE_NONE
             && IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
             && gChosenMove != MOVE_STRUGGLE
             && GetActiveGimmick(gBattlerAttacker) != GIMMICK_DYNAMAX
             && RandomPercentage(RNG_CURSED_BODY, 30))
            {
                gBattleMons[gBattlerAttacker].volatiles.disabledMove = gChosenMove;
                gBattleMons[gBattlerAttacker].volatiles.disableTimer = B_DISABLE_TIMER;
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
                BattleScriptCall(BattleScript_CursedBodyActivates);
                effect++;
            }
            break;
        case ABILITY_LINGERING_AROMA:
        case ABILITY_MUMMY:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && gBattleMons[gBattlerAttacker].volatiles.overwrittenAbility != GetBattlerAbility(gBattlerTarget)
             && gBattleMons[gBattlerAttacker].ability != ABILITY_MUMMY
             && gBattleMons[gBattlerAttacker].ability != ABILITY_LINGERING_AROMA
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSuppressed)
            {
                if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                RemoveAbilityFlags(gBattlerAttacker);
                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                gBattleMons[gBattlerAttacker].ability = gBattleMons[gBattlerAttacker].volatiles.overwrittenAbility = gBattleMons[gBattlerTarget].ability;
                BattleScriptCall(BattleScript_MummyActivates);
                effect++;
                break;
            }
            break;
        case ABILITY_WANDERING_SPIRIT:
            if (IsBattlerAlive(gBattlerAttacker)
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && !(GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX)
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSwapped)
            {
                if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }
                if (GetBattlerHoldEffectIgnoreAbility(gBattlerTarget) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                RemoveAbilityFlags(gBattlerAttacker);
                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                gBattleMons[gBattlerAttacker].ability = gBattleMons[gBattlerAttacker].volatiles.overwrittenAbility = gBattleMons[gBattlerTarget].ability;
                gBattleMons[gBattlerTarget].ability = gBattleMons[gBattlerTarget].volatiles.overwrittenAbility = gLastUsedAbility;
                BattleScriptCall(BattleScript_WanderingSpiritActivates);
                effect++;
                break;
            }
            break;
        case ABILITY_ANGER_POINT:
            if (gSpecialStatuses[battler].criticalHit
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 12);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_GOOEY:
        case ABILITY_TANGLING_HAIR:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !gBattleStruct->unableToUseMove)
            {
                struct BattleCalcValues cv = {
                    .battlerAtk = gBattlerTarget,
                    .battlerDef = gBattlerAttacker,
                    .move = MOVE_NONE,
                };

                cv.abilities[gBattlerAttacker] = GetBattlerAbility(gBattlerAttacker);
                cv.abilities[gBattlerTarget] = ability;
                cv.holdEffects[gBattlerAttacker] = GetBattlerHoldEffect(gBattlerAttacker);
                cv.holdEffects[gBattlerTarget] = GetBattlerHoldEffect(gBattlerTarget);

                struct StatChange st = {
                    .onlyChecking = TRUE,
                };

                struct StatStages change = {
                    .stat = STAT_SPEED,
                    .stage = -1,
                };

                st.statStageQueue = &change;
                st.statStageAmount = 1;

                if (CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, cv.abilities[gBattlerAttacker], cv.holdEffects[gBattlerAttacker], move))
                    break;

                if (TryStatChange(&cv, &st) == STAT_CHANGE_WORKED || cv.abilities[gBattlerAttacker] == ABILITY_MIRROR_ARMOR)
                {
                    gEffectBattler = gBattlerAbility = gBattlerTarget;
                    SetStatChange(gBattlerAttacker, STAT_SPEED, -1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_ROUGH_SKIN:
        case ABILITY_IRON_BARBS:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move))
            {
                if (!IsAbilityAndRecord(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), ABILITY_MAGIC_GUARD))
                {
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    SetPassiveDamageAmount(gBattlerAttacker, GetNonDynamaxMaxHP(gBattlerAttacker) / (B_ROUGH_SKIN_DMG >= GEN_4 ? 8 : 16));
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HURT;
                    BattleScriptCall(BattleScript_RoughSkinActivates);
                }
                else
                {
                    BattleScriptCall(BattleScript_AbilityPopUp);
                }
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (!IsBattlerUnaffectedByMove(gBattlerTarget)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && !IsBattlerAlive(gBattlerTarget)
             && IsBattlerAlive(gBattlerAttacker)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move))
            {
                if ((battler = IsAbilityOnField(ABILITY_DAMP)))
                {
                    gBattleScripting.battler = battler - 1;
                    BattleScriptCall(BattleScript_DampPreventsAftermath);
                }
                else
                {
                    gBattleScripting.battler = gBattlerTarget;
                    SetPassiveDamageAmount(gBattlerAttacker, GetNonDynamaxMaxHP(gBattlerAttacker) / 4);
                    BattleScriptCall(BattleScript_AftermathDmg);
                }
                effect++;
            }
            break;
        case ABILITY_INNARDS_OUT:
            if (!IsBattlerUnaffectedByMove(gBattlerTarget)
             && !IsBattlerAlive(gBattlerTarget)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerAlive(gBattlerAttacker))
            {
                s32 damage = gBattleStruct->moveDamage[gBattlerTarget];

                if (gBattleStruct->innardsOutHpLost[gBattlerTarget] != 0)
                    damage = gBattleStruct->innardsOutHpLost[gBattlerTarget];

                gBattleScripting.battler = gBattlerTarget;
                SetPassiveDamageAmount(gBattlerAttacker, damage);
                BattleScriptCall(BattleScript_AftermathDmg);
                effect++;
            }
            break;
        case ABILITY_EFFECT_SPORE:
        {
            enum Ability abilityAtk = GetBattlerAbility(gBattlerAttacker);
            enum HoldEffect holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker);
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, abilityAtk, holdEffectAtk, move)
             && IsAffectedByPowderMove(gBattlerAttacker, abilityAtk, holdEffectAtk))
            {
                u32 poison, paralysis, sleep;

                if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_5)
                {
                    poison = 9;
                    paralysis = 19;
                }
                else
                {
                    poison = 10;
                    paralysis = 20;
                }
                sleep = 30;

                i = RandomUniform(RNG_EFFECT_SPORE, 0, GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? 99 : 299);
                if (i < poison)
                    goto POISON_POINT;
                if (i < paralysis)
                    goto STATIC;
                // Sleep
                if (i < sleep && CanBeSlept(gBattlerTarget, gBattlerAttacker, abilityAtk, NOT_BLOCKED_BY_SLEEP_CLAUSE))
                {
                    if (IsSleepClauseEnabled())
                        gBattleStruct->battlerState[gBattlerAttacker].sleepClauseEffectExempt = TRUE;
                    gEffectBattler = gBattlerAttacker;
                    gBattleScripting.battler = gBattlerTarget;
                    gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
        }
            break;
        case ABILITY_POISON_POINT:
            if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_POISON_POINT, 30) : RandomChance(RNG_POISON_POINT, 1, 3))
            {
            POISON_POINT:
            {
                enum Ability abilityAtk = GetBattlerAbility(gBattlerAttacker);
                if (IsBattlerAlive(gBattlerAttacker)
                 && !gSpecialStatuses[gBattlerAttacker].attackerInParty
                 && !gBattleStruct->unableToUseMove
                 && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
                 && CanBePoisoned(gBattlerTarget, gBattlerAttacker, gLastUsedAbility, abilityAtk)
                 && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, abilityAtk, GetBattlerHoldEffect(gBattlerAttacker), move))
                {
                    gEffectBattler = gBattlerAttacker;
                    gBattleScripting.battler = gBattlerTarget;
                    gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
            }
            break;
        case ABILITY_STATIC:
            if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_STATIC, 30) : RandomChance(RNG_STATIC, 1, 3))
            {
            STATIC:
            {
                enum Ability abilityAtk = GetBattlerAbility(gBattlerAttacker);
                if (IsBattlerAlive(gBattlerAttacker)
                 && !gSpecialStatuses[gBattlerAttacker].attackerInParty
                 && !gBattleStruct->unableToUseMove
                 && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
                 && CanBeParalyzed(gBattlerTarget, gBattlerAttacker, abilityAtk)
                 && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, abilityAtk, GetBattlerHoldEffect(gBattlerAttacker), move))
                {
                    gEffectBattler = gBattlerAttacker;
                    gBattleScripting.battler = gBattlerTarget;
                    gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
            }
            break;
        case ABILITY_FLAME_BODY:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && CanBeBurned(gBattlerTarget, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker))
             && (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_FLAME_BODY, 30) : RandomChance(RNG_FLAME_BODY, 1, 3)))
            {
                gEffectBattler = gBattlerAttacker;
                gBattleScripting.battler = gBattlerTarget;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect++;
            }
            break;
        case ABILITY_CUTE_CHARM:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(gBattlerTarget)
             && (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_CUTE_CHARM, 30) : RandomChance(RNG_CUTE_CHARM, 1, 3))
             && !(gBattleMons[gBattlerAttacker].volatiles.infatuation)
             && AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget)
             && !IsAbilityAndRecord(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), ABILITY_OBLIVIOUS)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL))
            {
                gBattleMons[gBattlerAttacker].volatiles.infatuation = INFATUATED_WITH(gBattlerTarget);
                BattleScriptCall(BattleScript_CuteCharmActivates);
                effect++;
            }
            break;
        case ABILITY_ILLUSION:
            if (gBattleStruct->illusion[gBattlerTarget].state == ILLUSION_ON && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES))
            {
                gBattleScripting.battler = gBattlerTarget;
                BattleScriptCall(BattleScript_IllusionOff);
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES))
            {
                gEffectBattler = gBattlerAbility = gBattlerTarget;
                for (enum BattlerId i = 0; i < gBattlersCount; i++)
                {
                    if (battler == i || !IsBattlerAlive(i))
                        continue;
                    SetStatChange(i, STAT_SPEED, -1);
                }
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility)
             && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
            {
                gEffectBattler = gBattlerAbility = gBattlerTarget;
                SetStatChange(battler, STAT_SPEED, 6);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_SAND_SPIT:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES) && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SANDSTORM, gLastUsedAbility))
                effect++;
            break;
        case ABILITY_PERISH_BODY:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && !gBattleMons[gBattlerAttacker].volatiles.perishSong)
            {
                if (!gBattleMons[battler].volatiles.perishSong)
                {
                    gBattleMons[battler].volatiles.perishSong = TRUE;
                    gBattleMons[battler].volatiles.perishSongTimer = 3;
                }
                gBattleMons[gBattlerAttacker].volatiles.perishSong = TRUE;
                gBattleMons[gBattlerAttacker].volatiles.perishSongTimer = 3;
                BattleScriptCall(BattleScript_PerishBodyActivates);
                effect++;
            }
            break;
        case ABILITY_SEED_SOWER:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && TryChangeBattleTerrain(gBattlerTarget, B_TERRAIN_GRASSY))
            {
                BattleScriptCall(BattleScript_SeedSowerActivates);
                effect++;
            }
            break;
        case ABILITY_THERMAL_EXCHANGE:
            if (IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(gBattlerTarget)
             && CompareStat(gBattlerTarget, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility)
             && moveType == TYPE_FIRE)
            {
                gEffectBattler = gBattlerAbility = gBattlerTarget;
                SetStatChange(gBattlerTarget, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WIND_POWER:
            if (!IsWindMove(gCurrentMove))
                break;
            // fall through
        case ABILITY_ELECTROMORPHOSIS:
            if (!gBattleStruct->unableToUseMove && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES))
            {
                gBattlerAbility = battler;
                BattleScriptCall(BattleScript_WindPowerActivates);
                effect++;
            }
            break;
        case ABILITY_TOXIC_DEBRIS:
        {
            enum BattlerId toxicSpikesTarget = GetOppositeBattler(gBattlerTarget);
            if (!gBattleStruct->isSkyBattle
             && IsBattleMovePhysical(gCurrentMove)
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && (gSideTimers[GetBattlerSide(toxicSpikesTarget)].toxicSpikesAmount != 2))
            {
                SaveBattlerTarget(gBattlerTarget);
                SaveBattlerAttacker(gBattlerAttacker);
                gBattlerAttacker = gBattlerTarget;
                gBattlerTarget = GetOppositeBattler(gBattlerAttacker);
                BattleScriptCall(BattleScript_ToxicDebrisActivates);
                effect++;
            }
            break;
        }
        case ABILITY_SPICY_SPRAY:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && CanBeBurned(gBattlerTarget, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker)))
            {
                gEffectBattler = gBattlerAttacker;
                gBattleScripting.battler = gBattlerTarget;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER: // Same as above, but for attacker
        switch (gLastUsedAbility)
        {
        case ABILITY_POISON_TOUCH:
            if (IsBattlerAlive(gBattlerTarget)
             && !IsMoveEffectBlockedByTarget(GetBattlerAbility(gBattlerTarget))
             && CanBePoisoned(gBattlerAttacker, gBattlerTarget, gLastUsedAbility, GetBattlerAbility(gBattlerTarget))
             && IsMoveMakingContact(gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), move)
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES) // Need to actually hit the target
             && RandomPercentage(RNG_POISON_TOUCH, 30))
            {
                gEffectBattler = gBattlerTarget;
                gBattleScripting.battler = gBattlerAttacker;
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect++;
            }
            break;
        case ABILITY_TOXIC_CHAIN:
            if (gBattleStruct->toxicChainPriority)
            {
                gBattleStruct->toxicChainPriority = FALSE;
                if (!IsMoveEffectBlockedByTarget(GetBattlerAbility(gBattlerTarget)))
                {
                    gEffectBattler = gBattlerTarget;
                    gBattleScripting.battler = gBattlerAttacker;
                    gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
            break;
        case ABILITY_STENCH:
            if (IsBattlerAlive(gBattlerTarget)
             && !gBattleStruct->unableToUseMove
             && RandomChance(RNG_STENCH, 1, 10)
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && !MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_FLINCH))
            {
                SetMoveEffectHelper(gBattlerAttacker, gBattlerTarget, MOVE_EFFECT_FLINCH, gBattlescriptCurrInstr, NO_FLAGS);
                effect++;
            }
            break;
        case ABILITY_POISON_PUPPETEER:
            if (IsRestrictedAbility(gBattlerAttacker, ABILITY_POISON_PUPPETEER)
             && gSpecialStatuses[gBattlerTarget].poisonPuppeteer)
            {
                gSpecialStatuses[gBattlerTarget].poisonPuppeteer = FALSE;
                if (CanBeConfused(gBattlerAttacker, gBattlerTarget))
                {
                    gBattleScripting.battler = gBattlerAttacker;
                    gEffectBattler = gBattlerTarget;
                    gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_FORM_CHANGE_ON_HIT:
        speciesForm = gBattleMons[gBattlerTarget].species;

        if (gBattleStruct->unableToUseMove
         || !IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
         || !TryBattleFormChange(gBattlerTarget, FORM_CHANGE_BATTLE_HIT_BY_MOVE_CATEGORY, ability))
            break;

        gBattleScripting.abilityPopupOverwrite = ability;
        gBattleScripting.battler = gBattlerAbility = battler;
        effect++;

        switch (ability)
        {
        case ABILITY_GULP_MISSILE:
            if (!IsBattlerAlive(gBattlerAttacker))
                break;

            if (!IsAbilityAndRecord(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), ABILITY_MAGIC_GUARD))
                SetPassiveDamageAmount(gBattlerAttacker, GetNonDynamaxMaxHP(gBattlerAttacker) / 4);

            switch (speciesForm)
            {
            case SPECIES_CRAMORANT_GORGING:
                BattleScriptCall(BattleScript_GulpMissileGorging);
                break;
            case SPECIES_CRAMORANT_GULPING:
                SetStatChange(gBattlerAttacker, STAT_DEF, -1);
                BattleScriptCall(BattleScript_GulpMissileGulping);
                break;
            default:
                BattleScriptCall(BattleScript_BattlerFormChange); // Fallback
                break;
            }
            break;
        case ABILITY_DISGUISE:
            if (GetConfig(B_DISGUISE_HP_LOSS) >= GEN_8 && ability == ABILITY_DISGUISE)
                SetPassiveDamageAmount(gBattlerTarget, GetNonDynamaxMaxHP(gBattlerTarget) / 8);
            BattleScriptCall(BattleScript_BattlerFormChangeDisguise);
            break;
        case ABILITY_ICE_FACE:
            BattleScriptCall(BattleScript_IceFaceNullsDamage);
            break;
        default:
            BattleScriptCall(BattleScript_BattlerFormChange);
            break;
        }
        break;
    case ABILITYEFFECT_DANCER:
        return TryDancer();
    case ABILITYEFFECT_MOVE_END_FOES_FAINTED:
        switch (ability)
        {
        case ABILITY_MAGICIAN:
            if (GetMoveEffect(move) != EFFECT_FLING
             && GetMoveEffect(move) != EFFECT_NATURAL_GIFT
             && GetMoveEffect(move) != EFFECT_FUTURE_SIGHT
             && gBattleMons[battler].item == ITEM_NONE
             && !gSpecialStatuses[battler].gemBoost) // In base game, gems are consumed after magician would activate.
            {
                u32 numFoeMagicianTargets = 0;
                u32 numAllyMagicianTargets = 0;
                u32 foeMagicianTargets = 0;
                u32 allyMagicianTargets = 0;

                for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
                {
                    if (gBattleMons[battlerDef].item != ITEM_NONE
                     && battlerDef != battler
                     && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
                     && CanStealItem(battler, battlerDef, gBattleMons[battlerDef].item)
                     && !GetBattlerPartyState(battlerDef)->isKnockedOff)
                    {
                        if (IsBattlerAlly(battler, battlerDef))
                        {
                            allyMagicianTargets |= 1u << battlerDef;
                            numAllyMagicianTargets++;
                        }
                        else
                        {
                            foeMagicianTargets |= 1u << battlerDef;
                            numFoeMagicianTargets++;
                        }
                    }
                }

                if (numFoeMagicianTargets == 0 && numAllyMagicianTargets == 0)
                {
                    effect = FALSE;
                    break;
                }

                // For spread moves, Magician prioritizes opponents over allies.
                u32 magicianTargets = (numFoeMagicianTargets != 0) ? foeMagicianTargets : allyMagicianTargets;
                u32 numMagicianTargets = (numFoeMagicianTargets != 0) ? numFoeMagicianTargets : numAllyMagicianTargets;
                enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};

                if (numMagicianTargets > 1)
                    SortBattlersBySpeed(battlers, (gFieldStatuses & STATUS_FIELD_TRICK_ROOM) != 0);

                for (u32 i = 0; i < gBattlersCount; i++)
                {
                    enum BattlerId targetBattler = battlers[i];

                    if (!(magicianTargets & 1u << targetBattler))
                        continue;

                    if (GetBattlerAbility(targetBattler) == ABILITY_STICKY_HOLD)
                    {
                        effect = FALSE;
                        break;
                    }

                    StealTargetItem(battler, targetBattler, ITEM_NONE);
                    gBattlerAbility = battler;
                    gEffectBattler = targetBattler;
                    BattleScriptCall(BattleScript_MagicianActivates);
                    effect = TRUE;
                    break; // found target to steal from
                }
            }
            break;
        case ABILITY_MOXIE:
        case ABILITY_CHILLING_NEIGH:
        case ABILITY_AS_ONE_ICE_RIDER:
        case ABILITY_GRIM_NEIGH:
        case ABILITY_AS_ONE_SHADOW_RIDER:
        case ABILITY_BEAST_BOOST:
        case ABILITY_EELEVATE:
            {
                if (NoAliveMonsForEitherParty())
                    break;

                enum Stat stat = STAT_ATK;
                u32 numMonsFainted = NumFaintedBattlersByAttacker(battler);

                if (ability == ABILITY_BEAST_BOOST || ability == ABILITY_EELEVATE)
                    stat = GetHighestStatId(battler);
                else if (ability == ABILITY_GRIM_NEIGH || ability == ABILITY_AS_ONE_SHADOW_RIDER)
                    stat = STAT_SPATK;

                if (numMonsFainted && CompareStat(battler, stat, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                {
                    gLastUsedAbility = ability;
                    if (ability == ABILITY_AS_ONE_ICE_RIDER)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CHILLING_NEIGH;
                    else if (ability == ABILITY_AS_ONE_SHADOW_RIDER)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GRIM_NEIGH;

                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, stat, numMonsFainted);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect = TRUE;
                }
            }
            break;
        case ABILITY_BATTLE_BOND:
            {
                if (NoAliveMonsForEitherParty()
                 || NumFaintedBattlersByAttacker(battler) == 0)
                    break;

                if (GetBattlerPartyState(battler)->battleBondBoost || gBattleMons[battler].species != SPECIES_GRENINJA_BATTLE_BOND)
                    break;

                if (GetConfig(B_BATTLE_BOND) < GEN_9)
                {
                    gLastUsedAbility = ability;
                    GetBattlerPartyState(battler)->battleBondBoost = TRUE;
                    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battler].species);
                    TryBattleFormChange(battler, FORM_CHANGE_BATTLE_BOND, ability);
                    BattleScriptCall(BattleScript_BattleBondActivatesOnMoveEndAttacker);
                    effect = TRUE;
                }
                else
                {
                    if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_ATK, 1);
                    if (CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_SPATK, 1);
                    if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_SPEED, 1);

                    if (gSpecialStatuses[battler].statStageAmount > 0)
                    {
                        gLastUsedAbility = ability;
                        gEffectBattler = gBattlerAbility = battler;

                        GetBattlerPartyState(battler)->battleBondBoost = TRUE;
                        BattleScriptCall(BattleScript_AbilityStatChange);
                        effect = TRUE;
                    }
                }
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_OPPORTUNIST:
        switch (ability)
        {
        case ABILITY_OPPORTUNIST:
            if (gProtectStructs[battler].activateOpportunist)
            {
                for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
                {
                    u32 queuedStat = stat - 1;
                    if (gQueuedStatBoosts[battler].stats & (1 << queuedStat))
                        SetStatChange(battler, stat, gQueuedStatBoosts[battler].statChanges[queuedStat]);

                }
                gBattleScripting.battler = gBattlerAbility = battler;
                gProtectStructs[battler].activateOpportunist = FALSE;
                BattleScriptCall(BattleScript_OpportunistCopyStatChange);
                effect = 1;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_IMMUNITY:
        effect = TryImmunityAbilityHealStatus(battler);
        if (effect)
            return effect;
        break;
    case ABILITYEFFECT_TERA_SHIFT:
        if (TryBattleFormChange(battler, FORM_CHANGE_BATTLE_SWITCH_IN, ability))
        {
            gBattleScripting.battler = battler;
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ability;
            BattleScriptCall(BattleScript_BattlerFormChangeWithString);
            effect++;
        }
        break;
    case ABILITYEFFECT_NEUTRALIZINGGAS:
        if (ability == ABILITY_NEUTRALIZING_GAS && !gBattleMons[battler].volatiles.neutralizingGas)
        {
            for (enum BattlerId battlerDef = B_BATTLER_0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (battler == battlerDef || GetBattlerHoldEffectIgnoreAbility(battlerDef) == HOLD_EFFECT_ABILITY_SHIELD)
                    continue;
                RemoveRuinAbilityFlags(battlerDef);
            }

            gBattleMons[battler].volatiles.neutralizingGas = TRUE;
            gBattlerAbility = battler;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect++;
        }
        break;
    case ABILITYEFFECT_UNNERVE:
        switch (ability)
        {
        case ABILITY_UNNERVE:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
            {
                gBattleScripting.battler = battler;
                gEffectBattler = GetOppositeBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_UNNERVE;
                gBattleMons[battler].volatiles.unnerveActivated = TRUE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AS_ONE_ICE_RIDER:
        case ABILITY_AS_ONE_SHADOW_RIDER:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
            {
                gBattleScripting.battler = battler;
                gEffectBattler = GetOppositeBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ASONE;
                gBattleMons[battler].volatiles.unnerveActivated = TRUE;
                BattleScriptCall(BattleScript_ActivateAsOne);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_DEPENDS_ON_ALLY:
        gBattleScripting.battler = battler;
        partner = GetPartnerBattler(battler);
        switch (ability)
        {
        case ABILITY_COMMANDER:
            if (IsBattlerAlive(partner)
             && !HasPartnerTrainer(battler)
             && gBattleStruct->battlerState[partner].commanderSpecies == SPECIES_NONE
             && gBattleMons[partner].species == SPECIES_DONDOZO
             && (gChosenActionByBattler[battler] != B_ACTION_SWITCH || HasBattlerActedThisTurn(battler))
             && (gChosenActionByBattler[partner] != B_ACTION_SWITCH || HasBattlerActedThisTurn(partner))
             && GET_BASE_SPECIES_ID(GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES)) == SPECIES_TATSUGIRI)
            {
                gEffectBattler = partner;
                PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, partner, gBattlerPartyIndexes[partner]);
                gBattleStruct->battlerState[battler].commandingDondozo = TRUE;
                gBattleStruct->battlerState[partner].commanderSpecies = gBattleMons[battler].species;
                gBattleMons[battler].volatiles.semiInvulnerable = STATE_COMMANDER;
                if ((gBattleStruct->gimmick.toActivate & (1u << battler)) && gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_NONE)
                    gBattleStruct->gimmick.toActivate &= ~(1u << battler);

                struct Volatiles *vol = &gBattleMons[battler].volatiles;
                if (vol->confusionTimer > 0 && vol->confusionTimer != PERMANENT_VOLATILE)
                    vol->confusionTimer--;

                BtlController_EmitSpriteInvisibility(battler, B_COMM_TO_CONTROLLER, TRUE);
                MarkBattlerForControllerExec(battler);
                SetStatChange(partner, STAT_ATK, 2);
                SetStatChange(partner, STAT_DEF, 2);
                SetStatChange(partner, STAT_SPATK, 2);
                SetStatChange(partner, STAT_SPDEF, 2);
                SetStatChange(partner, STAT_SPEED, 2);
                BattleScriptCall(BattleScript_CommanderActivates);
                effect++;
            }
            break;
        case ABILITY_HOSPITALITY:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && !gBattleMons[partner].volatiles.healBlockTimer
             && gBattleMons[partner].hp < gBattleMons[partner].maxHP
             && IsBattlerAlive(partner))
            {
                gEffectBattler = partner;
                SetHealAmount(partner, GetNonDynamaxMaxHP(partner) / 4);
                BattleScriptCall(BattleScript_HospitalityActivates);
                effect++;
            }
            break;
        case ABILITY_COSTAR:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && IsBattlerAlive(partner)
             && BattlerHasCopyableChanges(partner))
            {
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                    gBattleMons[battler].statStages[i] = gBattleMons[partner].statStages[i];
                // Copy crit boosts (Focus Energy, Dragon Cheer, G-Max Chi Strike)
                gBattleMons[battler].volatiles.focusEnergy = gBattleMons[partner].volatiles.focusEnergy;
                gBattleMons[battler].volatiles.dragonCheer = gBattleMons[partner].volatiles.dragonCheer;
                gBattleMons[battler].volatiles.bonusCritStages = gBattleMons[partner].volatiles.bonusCritStages;
                gEffectBattler = partner;
                BattleScriptCall(BattleScript_CostarActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_WEATHER: // For ability effects that activate when the battle weather changes.
        gLastUsedAbility = GetBattlerAbility(battler);
        switch (gLastUsedAbility)
        {
        case ABILITY_FORECAST:
        case ABILITY_FLOWER_GIFT:
        case ABILITY_ICE_FACE:
        {
            u32 weather = GetWeather();
            bool32 battlerWeatherAffected = IsBattlerWeatherAffected(GetBattlerHoldEffect(battler), weather, gBattleWeather);
            if (battlerWeatherAffected && !CanBattlerFormChange(battler, FORM_CHANGE_BATTLE_WEATHER))
            {
                // If Hail/Snow activates when in Eiscue is in base, prevent reversion when Eiscue Noice gets broken
                gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
            }

            if (((!gBattleMons[battler].volatiles.weatherAbilityDone && battlerWeatherAffected) || weather == B_WEATHER_NONE)
             && TryBattleFormChange(battler, FORM_CHANGE_BATTLE_WEATHER, gLastUsedAbility))
            {
                gBattleScripting.battler = battler;
                gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
                BattleScriptCall(BattleScript_BattlerFormChangeWithString);
                effect++;
            }
            break;
        }
        case ABILITY_PROTOSYNTHESIS:
            if (!gBattleMons[battler].volatiles.weatherAbilityDone
             && (GetWeather() & B_WEATHER_SUN)
             && !gBattleMons[battler].volatiles.transformed
             && !gBattleMons[battler].volatiles.boosterEnergyActivated)
            {
                gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
                gBattleMons[battler].volatiles.paradoxBoostedStat = GetParadoxHighestStatId(battler);
                PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleMons[battler].volatiles.paradoxBoostedStat);
                gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_ProtosynthesisActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_TERRAIN:  // For ability effects that activate when the field terrain changes.
        gLastUsedAbility = GetBattlerAbility(battler);
        switch (gLastUsedAbility)
        {
        case ABILITY_MIMICRY:
            if (!gBattleMons[battler].volatiles.terrainAbilityDone && ChangeTypeBasedOnTerrain(battler))
            {
                gBattleMons[battler].volatiles.terrainAbilityDone = TRUE;
                ChangeTypeBasedOnTerrain(battler);
                gBattlerAbility = gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_MimicryActivates);
                effect++;
            }
            break;
        case ABILITY_QUARK_DRIVE:
            if (!gBattleMons[battler].volatiles.terrainAbilityDone
             && gFieldTimers.terrain == B_TERRAIN_ELECTRIC
             && !gBattleMons[battler].volatiles.transformed
             && !gBattleMons[battler].volatiles.boosterEnergyActivated)
            {
                gBattleMons[battler].volatiles.terrainAbilityDone = TRUE;
                gBattleMons[battler].volatiles.paradoxBoostedStat = GetParadoxHighestStatId(battler);
                PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleMons[battler].volatiles.paradoxBoostedStat);
                gBattlerAbility = gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_QuarkDriveActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    }

    if (effect)
    {
        RecordAbilityBattle(battler, gLastUsedAbility);
        gBattlerAbility = battler;
    }

    return effect;
}

bool32 TryPrimalReversion(enum BattlerId battler)
{
    if (TryBattleFormChange(battler, FORM_CHANGE_BATTLE_PRIMAL_REVERSION, GetBattlerAbility(battler)))
    {
        gBattleScripting.battler = battler;
        BattleScriptCall(BattleScript_PrimalReversion);
        return TRUE;
    }
    return FALSE;
}

bool32 IsNeutralizingGasOnField(void)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].volatiles.neutralizingGas && !gBattleMons[i].volatiles.gastroAcid)
            return TRUE;
    }

    return FALSE;
}

bool32 IsMoldBreakerTypeAbility(enum BattlerId battler, enum Ability ability, enum Move move)
{
    if (gBattleMons[battler].volatiles.gastroAcid)
        return FALSE;

    if (ability == ABILITY_MOLD_BREAKER
     || ability == ABILITY_TERAVOLT
     || ability == ABILITY_TURBOBLAZE
     || (ability == ABILITY_MYCELIUM_MIGHT && IsBattleMoveStatus(move)))
    {
        RecordAbilityBattle(battler, ability);
        return TRUE;
    }

    return FALSE;
}

static inline bool32 CanBreakThroughAbility(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 hasAbilityShield, bool32 ignoreMoldBreaker)
{
    if (hasAbilityShield || ignoreMoldBreaker || battlerDef == battlerAtk)
        return FALSE;
    return gBattleStruct->moldBreakerActive && gAbilitiesInfo[gBattleMons[battlerDef].ability].breakable;
}

enum Ability GetBattlerAbilityNoAbilityShield(enum BattlerId battler)
{
    return GetBattlerAbilityInternal(battler, FALSE, TRUE);
}

enum Ability GetBattlerAbilityIgnoreMoldBreaker(enum BattlerId battler)
{
    return GetBattlerAbilityInternal(battler, TRUE, FALSE);
}

enum Ability GetBattlerAbility(enum BattlerId battler)
{
    return GetBattlerAbilityInternal(battler, FALSE, FALSE);
}

enum Ability GetBattlerAbilityInternal(enum BattlerId battler, bool32 ignoreMoldBreaker, bool32 noAbilityShield)
{
    bool32 hasAbilityShield = !noAbilityShield && GetBattlerHoldEffectIgnoreAbility(battler) == HOLD_EFFECT_ABILITY_SHIELD;
    bool32 abilityCantBeSuppressed = gAbilitiesInfo[gBattleMons[battler].ability].cantBeSuppressed;

    if (gBattleStruct->battlerState[battler].notOnField || gSpecialStatuses[battler].attackerInParty)
        return ABILITY_NONE;

    if (abilityCantBeSuppressed)
    {
        // Edge case: Pokémon under the effect of gastro acid transforms into a Pokémon with Comatose (Todo: verify how other unsuppressable abilities behave)
        if (gBattleMons[battler].volatiles.transformed
            && gBattleMons[battler].volatiles.gastroAcid
            && gBattleMons[battler].ability == ABILITY_COMATOSE)
                return ABILITY_NONE;

        if (CanBreakThroughAbility(gBattlerAttacker, battler, hasAbilityShield, ignoreMoldBreaker))
            return ABILITY_NONE;

        return gBattleMons[battler].ability;
    }

    if (gBattleMons[battler].volatiles.gastroAcid)
        return ABILITY_NONE;

    if (!hasAbilityShield
     && IsNeutralizingGasOnField()
     && (gBattleMons[battler].ability != ABILITY_NEUTRALIZING_GAS || gBattleMons[battler].volatiles.gastroAcid))
        return ABILITY_NONE;

    if (CanBreakThroughAbility(gBattlerAttacker, battler, hasAbilityShield, ignoreMoldBreaker))
        return ABILITY_NONE;

    return gBattleMons[battler].ability;
}

u32 IsAbilityOnSide(enum BattlerId battler, enum Ability ability)
{
    if (IsBattlerAlive(battler) && GetBattlerAbility(battler) == ability)
        return battler + 1;
    else if (IsBattlerAlive(GetPartnerBattler(battler)) && GetBattlerAbility(GetPartnerBattler(battler)) == ability)
        return GetPartnerBattler(battler) + 1;
    else
        return 0;
}

u32 IsAbilityOnField(enum Ability ability)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (IsBattlerAlive(i) && GetBattlerAbility(i) == ability)
            return i + 1;
    }

    return 0;
}

u32 IsAbilityPreventingEscape(enum BattlerId battler)
{
    if (GetConfig(B_GHOSTS_ESCAPE) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return 0;

    bool32 isBattlerGrounded = IsBattlerGrounded(battler, GetBattlerAbility(battler), GetBattlerHoldEffect(battler));
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (battler == battlerDef || IsBattlerAlly(battler, battlerDef))
            continue;

        enum Ability ability = GetBattlerAbility(battlerDef);

        if (ability == ABILITY_SHADOW_TAG && (B_SHADOW_TAG_ESCAPE <= GEN_3 || GetBattlerAbility(battler) != ABILITY_SHADOW_TAG))
            return battlerDef + 1;

        if (ability == ABILITY_ARENA_TRAP && isBattlerGrounded)
            return battlerDef + 1;

        if (ability == ABILITY_MAGNET_PULL && IS_BATTLER_OF_TYPE(battler, TYPE_STEEL))
            return battlerDef + 1;
    }

    return 0;
}

bool32 CanBattlerEscape(enum BattlerId battler) // no ability check
{
    if (gBattleStruct->battlerState[battler].commanderSpecies != SPECIES_NONE)
        return FALSE;
    else if (GetConfig(B_GHOSTS_ESCAPE) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return TRUE;
    else if (gBattleMons[battler].volatiles.escapePrevention)
        return FALSE;
    else if (gBattleMons[battler].volatiles.wrapped)
        return FALSE;
    else if (gBattleMons[battler].volatiles.root)
        return FALSE;
    else if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        return FALSE;
    else if (gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
        return FALSE;
    else
        return TRUE;
}

bool32 IsPsychicTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain currTerrain)
{
    return IsBattlerTerrainAffected(battler, ability, holdEffect, B_TERRAIN_PSYCHIC, currTerrain);
}

bool32 IsMistyTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain currTerrain)
{
    return IsBattlerTerrainAffected(battler, ability, holdEffect, B_TERRAIN_MISTY, currTerrain);
}

bool32 IsGrassyTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain currTerrain)
{
    return IsBattlerTerrainAffected(battler, ability, holdEffect, B_TERRAIN_GRASSY, currTerrain);
}

bool32 IsElectricTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain currTerrain)
{
    return IsBattlerTerrainAffected(battler, ability, holdEffect, B_TERRAIN_ELECTRIC, currTerrain);
}

bool32 IsAnyTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain currTerrain)
{
    if (currTerrain == B_TERRAIN_NONE)
        return FALSE;
    if (IsSemiInvulnerable(battler, CHECK_ALL))
        return FALSE;

    return IsBattlerGrounded(battler, ability, holdEffect);
}

bool32 IsBattlerTerrainAffected(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum BattleTerrain terrain, enum BattleTerrain currTerrain)
{
    if (currTerrain != terrain)
        return FALSE;
    if (IsSemiInvulnerable(battler, CHECK_ALL))
        return FALSE;

    return IsBattlerGrounded(battler, ability, holdEffect);
}

enum Stat GetHighestStatId(enum BattlerId battler)
{
    enum Stat highestId = STAT_ATK;
    bool32 wonderRoom = (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) != 0;
    u32 highestStat = gBattleMons[battler].attack;

    for (enum Stat stat = STAT_DEF; stat < NUM_STATS; stat++)
    {
        if (stat == STAT_SPEED)
            continue;

        u32 statVal;
        switch (stat)
        {
        case STAT_ATK:
            statVal = gBattleMons[battler].attack;
            break;
        case STAT_DEF:
            statVal = wonderRoom ? gBattleMons[battler].spDefense : gBattleMons[battler].defense;
            break;
        case STAT_SPATK:
            statVal = gBattleMons[battler].spAttack;
            break;
        case STAT_SPDEF:
            statVal = wonderRoom ? gBattleMons[battler].defense : gBattleMons[battler].spDefense;
            break;
        default:
            continue;
        }

        if (statVal > highestStat)
        {
            highestStat = statVal;
            highestId = stat;
        }
    }

    if (gBattleMons[battler].speed > highestStat)
        highestId = STAT_SPEED;

    return highestId;
}

static u32 GetStatValueWithStages(enum BattlerId battler, enum Stat stat)
{
    u32 statValue;

    switch (stat)
    {
    case STAT_ATK:
        statValue = gBattleMons[battler].attack;
        break;
    case STAT_DEF:
        statValue = gBattleMons[battler].defense;
        break;
    case STAT_SPATK:
        statValue = gBattleMons[battler].spAttack;
        break;
    case STAT_SPDEF:
        statValue = gBattleMons[battler].spDefense;
        break;
    case STAT_SPEED:
        statValue = gBattleMons[battler].speed;
        break;
    default:
        return 0;
    }

    statValue *= gStatStageRatios[gBattleMons[battler].statStages[stat]][0];
    statValue /= gStatStageRatios[gBattleMons[battler].statStages[stat]][1];

    return statValue;
}

enum Stat GetParadoxHighestStatId(enum BattlerId battler)
{
    enum Stat highestId = STAT_ATK;
    bool32 wonderRoom = gFieldStatuses & STATUS_FIELD_WONDER_ROOM;
    u32 highestStat = GetStatValueWithStages(battler, STAT_ATK);

    for (enum Stat stat = STAT_DEF; stat < NUM_STATS; stat++)
    {
        if (stat == STAT_SPEED)
            continue;

        u32 statValue;
        switch (stat)
        {
        case STAT_DEF:
            statValue = wonderRoom ? gBattleMons[battler].spDefense : gBattleMons[battler].defense;
            statValue *= gStatStageRatios[gBattleMons[battler].statStages[STAT_DEF]][0];
            statValue /= gStatStageRatios[gBattleMons[battler].statStages[STAT_DEF]][1];
            break;
        case STAT_SPDEF:
            statValue = wonderRoom ? gBattleMons[battler].defense : gBattleMons[battler].spDefense;
            statValue *= gStatStageRatios[gBattleMons[battler].statStages[STAT_SPDEF]][0];
            statValue /= gStatStageRatios[gBattleMons[battler].statStages[STAT_SPDEF]][1];
            break;
        default:
            statValue = GetStatValueWithStages(battler, stat);
            break;
        }
        if (statValue > highestStat)
        {
            highestStat = statValue;
            highestId = stat;
        }
    }

    u32 speed = GetStatValueWithStages(battler, STAT_SPEED);
    if (speed > highestStat)
        highestId = STAT_SPEED;

    return highestId;
}

static void ResetParadoxWeatherStat(enum BattlerId battler)
{
    if (gBattleMons[battler].ability == ABILITY_PROTOSYNTHESIS
     && !gBattleMons[battler].volatiles.boosterEnergyActivated)
        gBattleMons[battler].volatiles.paradoxBoostedStat = 0;
}

static void ResetParadoxTerrainStat(enum BattlerId battler)
{
    if (gBattleMons[battler].ability == ABILITY_QUARK_DRIVE
     && !gBattleMons[battler].volatiles.boosterEnergyActivated)
        gBattleMons[battler].volatiles.paradoxBoostedStat = 0;
}

enum Stat GetParadoxBoostedStatId(enum BattlerId battler)
{
    if (gBattleMons[battler].volatiles.paradoxBoostedStat == 0)
        gBattleMons[battler].volatiles.paradoxBoostedStat = GetParadoxHighestStatId(battler);

    return gBattleMons[battler].volatiles.paradoxBoostedStat;
}

bool32 CanBeSlept(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef, enum SleepClauseBlock isBlockedBySleepClause)
{
    if (IsSleepClauseActiveForSide(GetBattlerSide(battlerDef)) && isBlockedBySleepClause != NOT_BLOCKED_BY_SLEEP_CLAUSE)
        return FALSE;

    if (isBlockedBySleepClause == NOT_BLOCKED_BY_SLEEP_CLAUSE)
        gBattleStruct->sleepClauseNotBlocked = TRUE;

    bool32 effect = FALSE;
    if (CanSetNonVolatileStatus(
            battlerAtk,
            battlerDef,
            ABILITY_NONE, // attacker ability does not matter
            abilityDef,
            MOVE_EFFECT_SLEEP, // also covers yawn
            CHECK_TRIGGER))
        effect = TRUE;

    gBattleStruct->sleepClauseNotBlocked = FALSE;
    return effect;
}

bool32 CanBePoisoned(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Ability abilityDef)
{
    if (CanSetNonVolatileStatus(
            battlerAtk,
            battlerDef,
            abilityAtk,
            abilityDef,
            MOVE_EFFECT_TOXIC, // also covers poison
            CHECK_TRIGGER))
        return TRUE;
    return FALSE;
}

// TODO: check order of battlerAtk and battlerDef
bool32 CanBeBurned(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    if (CanSetNonVolatileStatus(
            battlerAtk,
            battlerDef,
            ABILITY_NONE, // attacker ability does not matter
            abilityDef,
            MOVE_EFFECT_BURN,
            CHECK_TRIGGER))
        return TRUE;
    return FALSE;
}

bool32 CanBeParalyzed(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    if (CanSetNonVolatileStatus(
            battlerAtk,
            battlerDef,
            ABILITY_NONE, // attacker ability does not matter
            abilityDef,
            MOVE_EFFECT_PARALYSIS,
            CHECK_TRIGGER))
        return TRUE;
    return FALSE;
}

bool32 CanBeFrozen(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityDef)
{
    if (CanSetNonVolatileStatus(
            battlerAtk,
            battlerDef,
            ABILITY_NONE, // attacker ability does not matter
            abilityDef,
            MOVE_EFFECT_FREEZE,
            CHECK_TRIGGER))
        return TRUE;
    return FALSE;
}

bool32 IsSafeguardProtected(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk)
{
    if (!(gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SAFEGUARD))
        return FALSE;
    if (IsBattlerAlly(battlerAtk, battlerDef))
        return TRUE;
    if (abilityAtk == ABILITY_INFILTRATOR)
        return FALSE;
    return TRUE;
}

bool32 CanSetNonVolatileStatus(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Ability abilityDef, enum MoveEffect effect, enum ResultOption option)
{
    const u8 *battleScript = NULL;
    u32 sideBattler = 0;
    bool32 abilityAffected = FALSE;

    // Move specific checks
    switch (effect)
    {
    case MOVE_EFFECT_POISON:
    case MOVE_EFFECT_TOXIC:
        if (gBattleMons[battlerDef].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
        {
            battleScript = BattleScript_AlreadyPoisoned;
        }
        else if (abilityAtk != ABILITY_CORROSION && IS_BATTLER_ANY_TYPE(battlerDef, TYPE_POISON, TYPE_STEEL))
        {
            battleScript = BattleScript_NotAffected;
        }
        else if ((sideBattler = IsAbilityOnSide(battlerDef, ABILITY_PASTEL_VEIL)))
        {
            abilityAffected = TRUE;
            battlerDef = sideBattler - 1;
            abilityDef = ABILITY_PASTEL_VEIL;
            battleScript = BattleScript_ImmunityProtected;
        }
        else if (abilityDef == ABILITY_IMMUNITY)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_ImmunityProtected;
        }
        break;
    case MOVE_EFFECT_PARALYSIS:
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS)
        {
            battleScript = BattleScript_AlreadyParalyzed;
        }
        else if (GetConfig(B_PARALYZE_ELECTRIC) >= GEN_6 && IS_BATTLER_OF_TYPE(battlerDef, TYPE_ELECTRIC))
        {
            battleScript = BattleScript_NotAffected;
        }
        else if (option == RUN_SCRIPT && IsBattlerUnaffectedByMove(battlerDef))
        {
            battleScript = BattleScript_ButItFailed;
        }
        else if (abilityDef == ABILITY_LIMBER)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_ImmunityProtected;
        }
        break;
    case MOVE_EFFECT_BURN:
        if (gBattleMons[battlerDef].status1 & STATUS1_BURN)
        {
            battleScript = BattleScript_AlreadyBurned;
        }
        else if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_FIRE))
        {
            battleScript = BattleScript_NotAffected;
        }
        else if (abilityDef == ABILITY_WATER_VEIL || abilityDef == ABILITY_WATER_BUBBLE)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_ImmunityProtected;
        }
        else if (abilityDef == ABILITY_THERMAL_EXCHANGE)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_AbilityProtectsDoesntAffect;
        }
        break;
    case MOVE_EFFECT_SLEEP:
        if (gBattleMons[battlerDef].status1 & STATUS1_SLEEP)
        {
            battleScript = BattleScript_AlreadyAsleep;
        }
        else if (UproarWakeUpCheck(battlerDef))
        {
            battleScript = BattleScript_CantMakeAsleep;
        }
        else if (!gBattleStruct->sleepClauseNotBlocked && CanSleepDueToSleepClause(battlerAtk, battlerDef, option))
        {
            battleScript = BattleScript_SleepClauseBlocked;
        }
        else if (IsElectricTerrainAffected(battlerDef, abilityDef, GetBattlerHoldEffect(battlerDef), gFieldTimers.terrain))
        {
            battleScript = BattleScript_ElectricTerrainPrevents;
        }
        else if ((sideBattler = IsAbilityOnSide(battlerDef, ABILITY_SWEET_VEIL)))
        {
            abilityAffected = TRUE;
            battlerDef = sideBattler - 1;
            abilityDef = ABILITY_SWEET_VEIL;
            battleScript = BattleScript_ImmunityProtected;
        }
        else if (abilityDef == ABILITY_VITAL_SPIRIT || abilityDef == ABILITY_INSOMNIA)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_PrintAbilityMadeIneffective;
        }
        break;
    case MOVE_EFFECT_FREEZE:
    case MOVE_EFFECT_FROSTBITE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ICY_ANY)
        {
            battleScript = BattleScript_AlreadyBurned;
        }
        else if (IS_BATTLER_OF_TYPE(battlerDef, TYPE_ICE) || IsBattlerWeatherAffected(GetBattlerHoldEffect(battlerDef), GetWeather(), B_WEATHER_SUN))
        {
            battleScript = BattleScript_NotAffected;
        }
        else if (abilityDef == ABILITY_MAGMA_ARMOR)
        {
            abilityAffected = TRUE;
            battleScript = BattleScript_NotAffected;
        }
        break;
    default:
        break;
    }

    if (IsNonVolatileStatusBlocked(battlerDef, abilityDef, abilityAffected, battleScript, option))
        return FALSE;

    // Checks that apply to all non volatile statuses
    if (abilityDef == ABILITY_COMATOSE
     || abilityDef == ABILITY_PURIFYING_SALT)
    {
        abilityAffected = TRUE;
        battleScript = BattleScript_AbilityProtectsDoesntAffect;
    }
    else if (IsMistyTerrainAffected(battlerDef, abilityDef, GetBattlerHoldEffect(battlerDef), gFieldTimers.terrain))
    {
        battleScript = BattleScript_MistyTerrainPrevents;
    }
    else if (IsLeafGuardProtected(battlerDef, abilityDef))
    {
        abilityAffected = TRUE;
        battleScript = BattleScript_AbilityProtectsDoesntAffect;
    }
    else if (IsShieldsDownProtected(battlerDef, abilityDef))
    {
        abilityAffected = TRUE;
        battleScript = BattleScript_AbilityProtectsDoesntAffect;
    }
    else if ((sideBattler = IsFlowerVeilProtected(battlerDef)))
    {
        abilityAffected = TRUE;
        battlerDef = sideBattler - 1;
        abilityDef = ABILITY_FLOWER_VEIL;
        battleScript = BattleScript_FlowerVeilProtects;
    }
    else if (IsSafeguardProtected(battlerAtk, battlerDef, abilityAtk))
    {
        battleScript = BattleScript_SafeguardProtected;
    }
    else if (gBattleMons[battlerDef].status1 & STATUS1_ANY)
    {
        battleScript = BattleScript_ButItFailed;
    }

    if (IsNonVolatileStatusBlocked(battlerDef, abilityDef, abilityAffected, battleScript, option))
        return FALSE;

    return TRUE;
}

static bool32 IsNonVolatileStatusBlocked(enum BattlerId battlerDef, enum Ability abilityDef, bool32 abilityAffected, const u8 *battleScript, enum ResultOption option)
{
    if (battleScript != NULL)
    {
        if (option == RUN_SCRIPT)
        {
            if (battleScript != BattleScript_NotAffected)
                gBattleStruct->moveResultFlags[battlerDef] |= MOVE_RESULT_FAILED;

            gBattleScripting.battler = battlerDef;
            if (abilityAffected)
            {
                gLastUsedAbility = abilityDef;
                gBattlerAbility = battlerDef;
                RecordAbilityBattle(battlerDef, abilityDef);
            }

            gBattlescriptCurrInstr = battleScript;
        }

        return TRUE;
    }

    return FALSE;
}

static bool32 CanSleepDueToSleepClause(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum ResultOption option)
{
    // Can freely sleep own partner
    if (IsDoubleBattle() && IsSleepClauseEnabled() && IsBattlerAlly(battlerAtk, battlerDef))
    {
        if (option == RUN_SCRIPT)
            gBattleStruct->battlerState[battlerDef].sleepClauseEffectExempt = TRUE;
        return FALSE;
    }

    if (option == RUN_SCRIPT)
        gBattleStruct->battlerState[battlerDef].sleepClauseEffectExempt = FALSE;
    // Can't sleep if clause is active otherwise
    if (IsSleepClauseActiveForSide(GetBattlerSide(battlerDef)))
        return TRUE;

    return FALSE;
}

bool32 CanBeConfused(enum BattlerId battlerAtk, enum BattlerId effectBattler)
{
    enum Ability effectAbility = GetBattlerAbility(effectBattler);

    if (gBattleMons[effectBattler].volatiles.confusionTimer > 0
     || IsSafeguardProtected(battlerAtk, effectBattler, GetBattlerAbility(battlerAtk))
     || IsMistyTerrainAffected(effectBattler, effectAbility, GetBattlerHoldEffect(effectBattler), gFieldTimers.terrain)
     || IsAbilityAndRecord(effectBattler, effectAbility, ABILITY_OWN_TEMPO))
        return FALSE;

    return TRUE;
}

// second argument is 1/X of current hp compared to max hp
bool32 HasEnoughHpToEatBerry(enum BattlerId battler, enum Ability ability, u32 hpFraction, enum Item itemId)
{
    if (!IsBattlerAlive(battler))
        return FALSE;
    if (gBattleScripting.overrideBerryRequirements)
        return TRUE;
    if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / hpFraction)
        return TRUE;

    if (hpFraction <= 4 && GetItemPocket(itemId) == POCKET_BERRIES
         && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2
         && IsAbilityAndRecord(battler, GetBattlerAbility(battler), ABILITY_GLUTTONY))
        return TRUE;

    return FALSE;
}

void ClearVariousBattlerFlags(enum BattlerId battler)
{
    gBattleMons[battler].volatiles.furyCutterCounter = 0;
    gBattleMons[battler].volatiles.destinyBond = 0;
    gBattleMons[battler].volatiles.glaiveRush = FALSE;
    gBattleMons[battler].volatiles.grudge = FALSE;
}

void HandleAction_RunBattleScript(void)
{
    RunBattleScriptCommands();
}

u32 SetRandomTarget(enum BattlerId battlerAtk)
{
    enum BattlerId target;
    static const u8 targets[NUM_BATTLE_SIDES][MAX_BATTLERS_COUNT / 2] =
    {
        [B_SIDE_PLAYER] = {B_POSITION_OPPONENT_LEFT, B_POSITION_OPPONENT_RIGHT},
        [B_SIDE_OPPONENT] = {B_POSITION_PLAYER_LEFT, B_POSITION_PLAYER_RIGHT},
    };

    if (IsDoubleBattle())
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerAtk)][RandomUniform(RNG_RANDOM_TARGET, 0, 1)]);
        if (!IsBattlerAlive(target))
            target ^= BIT_FLANK;
    }
    else
    {
        target = GetBattlerAtPosition(targets[GetBattlerSide(battlerAtk)][0]);
    }

    return target;
}

u32 GetBattleMoveTarget(enum Move move, enum MoveTarget moveTarget)
{
    u32 targetBattler = 0;
    enum BattleSide side;

    if (moveTarget == TARGET_NONE)
        moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, move);

    switch (moveTarget)
    {
    case TARGET_SELECTED:
    case TARGET_SMART:
    case TARGET_OPPONENT:
    case TARGET_RANDOM:
        side = (GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE);
        if (IsAffectedByFollowMe(gBattlerAttacker, side, move))
            targetBattler = gSideTimers[side].followmeTarget;
        else
            targetBattler = SetRandomTarget(gBattlerAttacker);
        break;
    case TARGET_DEPENDS:
    case TARGET_BOTH:
    case TARGET_FOES_AND_ALLY:
        targetBattler = GetBattlerLeftFoe(gBattlerAttacker);
        if (IsDoubleBattle() && !IsBattlerAlive(targetBattler))
            targetBattler ^= BIT_FLANK;
        break;
    case TARGET_OPPONENTS_FIELD:
        targetBattler = GetBattlerLeftFoe(gBattlerAttacker);
        break;
    case TARGET_USER_OR_ALLY:
        if (!IsBattlerAlive(GetPartnerBattler(gBattlerAttacker)))
            targetBattler = gBattlerAttacker;
        break;
    case TARGET_USER:
    default:
        targetBattler = gBattlerAttacker;
        break;
    case TARGET_ALLY:
        if (IsBattlerAlive(GetPartnerBattler(gBattlerAttacker)))
            targetBattler = GetPartnerBattler(gBattlerAttacker);
        else
            targetBattler = gBattlerAttacker;
        break;
    }

    gBattleStruct->moveTarget[gBattlerAttacker] = targetBattler;

    return targetBattler;
}

enum Obedience GetAttackerObedienceForAction(void)
{
    s32 rnd;
    s32 calc;
    u8 obedienceLevel = 0;
    u8 levelReferenced;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return OBEYS;
    if (BattlerHasAi(gBattlerAttacker))
        return OBEYS;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_RIGHT)
        return OBEYS;
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return OBEYS;
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        return OBEYS;
    if (B_OBEDIENCE_MECHANICS < GEN_8 && !IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
        return OBEYS;
    if (FlagGet(FLAG_BADGE08_GET)) // Rain Badge, ignore obedience altogether
        return OBEYS;

    obedienceLevel = 10;

    if (FlagGet(FLAG_BADGE01_GET)) // Stone Badge
        obedienceLevel = 20;
    if (FlagGet(FLAG_BADGE02_GET)) // Knuckle Badge
        obedienceLevel = 30;
    if (FlagGet(FLAG_BADGE03_GET)) // Dynamo Badge
        obedienceLevel = 40;
    if (FlagGet(FLAG_BADGE04_GET)) // Heat Badge
        obedienceLevel = 50;
    if (FlagGet(FLAG_BADGE05_GET)) // Balance Badge
        obedienceLevel = 60;
    if (FlagGet(FLAG_BADGE06_GET)) // Feather Badge
        obedienceLevel = 70;
    if (FlagGet(FLAG_BADGE07_GET)) // Mind Badge
        obedienceLevel = 80;

    if (B_OBEDIENCE_MECHANICS >= GEN_8
     && !IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
        levelReferenced = gBattleMons[gBattlerAttacker].metLevel;
    else
        levelReferenced = gBattleMons[gBattlerAttacker].level;

    if (levelReferenced <= obedienceLevel)
        return OBEYS;

    rnd = Random();
    calc = (levelReferenced + obedienceLevel) * (rnd & 255) >> 8;
    if (calc < obedienceLevel)
        return OBEYS;

    //  Clear the Z-Move flags if the battler is disobedient as to not waste the Z-Move
    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE)
    {
        gBattleStruct->gimmick.activated[gBattlerAttacker][GIMMICK_Z_MOVE] = FALSE;
        gBattleStruct->gimmick.activeGimmick[GetBattlerSide(gBattlerAttacker)][gBattlerPartyIndexes[gBattlerAttacker]] = GIMMICK_NONE;
    }

    // is not obedient
    enum BattleMoveEffects moveEffect = GetMoveEffect(gCurrentMove);
    if (MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_RAGE))
        gBattleMons[gBattlerAttacker].volatiles.rage = FALSE;
    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP && IsUsableWhileAsleepEffect(moveEffect))
        return DISOBEYS_WHILE_ASLEEP;

    calc = (levelReferenced + obedienceLevel) * ((rnd >> 8) & 255) >> 8;
    if (calc < obedienceLevel)
    {
        calc = CheckMoveLimitations(gBattlerAttacker, 1u << gCurrMovePos, MOVE_LIMITATIONS_ALL);
        if (calc == ALL_MOVES_MASK) // all moves cannot be used
            return DISOBEYS_LOAFS;
        else // use a random move
            do
                gCurrMovePos = gChosenMovePos = MOD(Random(), MAX_MON_MOVES);
            while ((1u << gCurrMovePos) & calc);
        return DISOBEYS_RANDOM_MOVE;
    }
    else
    {
        obedienceLevel = levelReferenced - obedienceLevel;

        calc = ((rnd >> 16) & 255);
        if (calc < obedienceLevel && CanBeSlept(gBattlerAttacker, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), NOT_BLOCKED_BY_SLEEP_CLAUSE))
        {
            // try putting asleep
            enum BattlerId i;
            for (i = 0; i < gBattlersCount; i++)
                if (gBattleMons[i].volatiles.uproarTurns)
                    break;
            if (i == gBattlersCount)
                return DISOBEYS_FALL_ASLEEP;
        }
        calc -= obedienceLevel;
        if (calc < obedienceLevel)
            return DISOBEYS_HITS_SELF;
        else
            return DISOBEYS_LOAFS;
    }
}

enum HoldEffect GetBattlerHoldEffect(enum BattlerId battler)
{
    return GetBattlerHoldEffectInternal(battler, GetBattlerAbility(battler));
}

enum HoldEffect GetBattlerHoldEffectIgnoreAbility(enum BattlerId battler)
{
    return GetBattlerHoldEffectInternal(battler, ABILITY_NONE);
}

enum HoldEffect GetBattlerHoldEffectInternal(enum BattlerId battler, enum Ability ability)
{
    if (gBattleStruct->battlerState[battler].notOnField)
        return HOLD_EFFECT_NONE;
    if (gSpecialStatuses[battler].attackerInParty)
        return HOLD_EFFECT_NONE;
    if (gBattleMons[battler].volatiles.embargoTimer)
        return HOLD_EFFECT_NONE;
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        return HOLD_EFFECT_NONE;
    if (ability == ABILITY_KLUTZ && !gBattleMons[battler].volatiles.gastroAcid)
        return HOLD_EFFECT_NONE;

    gPotentialItemEffectBattler = battler;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY_E_READER)
        return gEnigmaBerries[battler].holdEffect;
    else
        return GetItemHoldEffect(gBattleMons[battler].item);
}

enum HoldEffect GetBattlerHoldEffectIgnoreNegation(enum BattlerId battler)
{
    if (gBattleStruct->battlerState[battler].notOnField)
        return HOLD_EFFECT_NONE;
    if (gSpecialStatuses[battler].attackerInParty)
        return HOLD_EFFECT_NONE;

    gPotentialItemEffectBattler = battler;
    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY_E_READER)
        return gEnigmaBerries[battler].holdEffect;
    else
        return GetItemHoldEffect(gBattleMons[battler].item);
}

u32 GetBattlerHoldEffectParam(enum BattlerId battler)
{
    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY_E_READER)
        return gEnigmaBerries[battler].holdEffectParam;
    else
        return GetItemHoldEffectParam(gBattleMons[battler].item);
}

bool32 CanBattlerAvoidContactEffects(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum HoldEffect holdEffectAtk, enum Move move)
{
    if (holdEffectAtk == HOLD_EFFECT_PROTECTIVE_PADS)
    {
        RecordItemEffectBattle(battlerAtk, HOLD_EFFECT_PROTECTIVE_PADS);
        return TRUE;
    }

    return !IsMoveMakingContact(battlerAtk, battlerDef, abilityAtk, holdEffectAtk, move);
}

bool32 IsMoveMakingContact(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum HoldEffect holdEffectAtk, enum Move move)
{
    if (!(MoveMakesContact(move) || (GetMoveEffect(move) == EFFECT_SHELL_SIDE_ARM
                                  && gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] == DAMAGE_CATEGORY_PHYSICAL)))
    {
        return FALSE;
    }
    else if (holdEffectAtk == HOLD_EFFECT_PUNCHING_GLOVE && IsPunchingMove(move))
    {
        RecordItemEffectBattle(battlerAtk, HOLD_EFFECT_PUNCHING_GLOVE);
        return FALSE;
    }
    else if (abilityAtk == ABILITY_LONG_REACH)
    {
        RecordAbilityBattle(battlerAtk, ABILITY_LONG_REACH);
        return FALSE;
    }
    return TRUE;
}

static inline bool32 IsSideProtected(enum BattlerId battler, enum ProtectMethod method)
{
    return gProtectStructs[battler].protected == method
        || gProtectStructs[GetPartnerBattler(battler)].protected == method;
}

static bool32 IsCraftyShieldProtected(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (!IsBattleMoveStatus(move))
        return FALSE;

    if (!IsSideProtected(battlerDef, PROTECT_CRAFTY_SHIELD))
        return FALSE;

    if (GetMoveEffect(move) == EFFECT_HOLD_HANDS)
        return TRUE;

    u32 moveTarget = GetBattlerMoveTargetType(battlerAtk, move);
    if (!IsBattlerAlly(battlerAtk, battlerDef)
     && moveTarget != TARGET_OPPONENTS_FIELD
     && moveTarget != TARGET_ALL_BATTLERS)
        return TRUE;

    return FALSE;
}

bool32 IsBattlerProtected(struct BattleCalcValues *cv)
{
    if (gProtectStructs[cv->battlerDef].protected == PROTECT_NONE
     && gProtectStructs[GetPartnerBattler(cv->battlerDef)].protected == PROTECT_NONE)
        return FALSE;

    if (GetMoveEffect(cv->move) == EFFECT_CURSE && !IS_BATTLER_OF_TYPE(cv->battlerAtk, TYPE_GHOST))
        return FALSE;

    if (gProtectStructs[cv->battlerDef].protected != PROTECT_MAX_GUARD && !MoveIgnoresProtect(cv->move))
    {
        if (IsZMove(cv->move) || IsMaxMove(cv->move))
            return FALSE; // Z-Moves and Max Moves bypass protection (except Max Guard).

        if ((cv->abilities[cv->battlerAtk] == ABILITY_UNSEEN_FIST || cv->abilities[cv->battlerAtk] == ABILITY_PIERCING_DRILL)
         && IsMoveMakingContact(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move))
        {
            gSpecialStatuses[cv->battlerDef].breaksThroughProtectFully = TRUE;
            return FALSE;
        }
    }

    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    if (moveTarget == TARGET_ALL_BATTLERS)
        return FALSE;

    bool32 isProtected = FALSE;

    if (IsCraftyShieldProtected(cv->battlerAtk, cv->battlerDef, cv->move))
        isProtected = TRUE;
    else if (MoveIgnoresProtect(cv->move))
        isProtected = FALSE;
    else if (IsSideProtected(cv->battlerDef, PROTECT_WIDE_GUARD)
         && (moveTarget == TARGET_BOTH || moveTarget == TARGET_FOES_AND_ALLY))
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_NORMAL)
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_SPIKY_SHIELD)
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_MAX_GUARD)
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_BANEFUL_BUNKER)
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_BURNING_BULWARK && !IsBattleMoveStatus(cv->move))
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_OBSTRUCT && !IsBattleMoveStatus(cv->move))
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_SILK_TRAP && !IsBattleMoveStatus(cv->move))
        isProtected = TRUE;
    else if (gProtectStructs[cv->battlerDef].protected == PROTECT_KINGS_SHIELD && !IsBattleMoveStatus(cv->move))
        isProtected = TRUE;
    else if (IsSideProtected(cv->battlerDef, PROTECT_QUICK_GUARD) && GetChosenMovePriority(cv->battlerAtk, cv->abilities[cv->battlerAtk]) > 0)
        isProtected = TRUE;
    else if (IsSideProtected(cv->battlerDef, PROTECT_MAT_BLOCK) && !IsBattleMoveStatus(cv->move))
        isProtected = TRUE;
    else
        isProtected = FALSE;

    return isProtected;
}

enum ProtectType GetProtectType(enum ProtectMethod method)
{
    switch (method)
    {
    case PROTECT_NONE:
        return PROTECT_TYPE_NONE;
    case PROTECT_NORMAL:
    case PROTECT_SPIKY_SHIELD:
    case PROTECT_KINGS_SHIELD:
    case PROTECT_BANEFUL_BUNKER:
    case PROTECT_BURNING_BULWARK:
    case PROTECT_OBSTRUCT:
    case PROTECT_SILK_TRAP:
    case PROTECT_MAX_GUARD:
        return PROTECT_TYPE_SINGLE;
    case PROTECT_WIDE_GUARD:
    case PROTECT_QUICK_GUARD:
    case PROTECT_CRAFTY_SHIELD:
    case PROTECT_MAT_BLOCK:
        return PROTECT_TYPE_SIDE;
    }

    return FALSE;
}

enum InverseBattleCheck
{
    INVERSE_BATTLE,
    NOT_INVERSE_BATTLE
};

enum IronBallCheck
{
    CHECK_IRON_BALL,
    IGNORE_IRON_BALL
};

static bool32 IsBattlerUngroundedByAbilityItemOrEffect(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    if (gBattleMons[battler].volatiles.telekinesis)
        return TRUE;
    if (gBattleMons[battler].volatiles.magnetRiseTimer > 0)
        return TRUE;
    if (holdEffect == HOLD_EFFECT_AIR_BALLOON)
        return TRUE;
    if (ability == ABILITY_LEVITATE || ability == ABILITY_EELEVATE)
        return TRUE;
    return FALSE;
}

static bool32 IsBattlerGroundedInverseCheck(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum InverseBattleCheck checkInverse, bool32 isAnticipation)
{
    if (holdEffect == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    if (gFieldStatuses & STATUS_FIELD_GRAVITY && isAnticipation == FALSE)
        return TRUE;
    if (B_ROOTED_GROUNDING >= GEN_4 && gBattleMons[battler].volatiles.root)
        return TRUE;
    if (gBattleMons[battler].volatiles.smackDown)
        return TRUE;
    if (IsBattlerUngroundedByAbilityItemOrEffect(battler, ability, holdEffect))
        return FALSE;
    if (IS_BATTLER_OF_TYPE(battler, TYPE_FLYING) && (checkInverse != INVERSE_BATTLE || !FlagGet(B_FLAG_INVERSE_BATTLE)))
        return FALSE;
    return TRUE;
}

bool32 IsBattlerGrounded(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    return IsBattlerGroundedInverseCheck(battler, ability, holdEffect, NOT_INVERSE_BATTLE, FALSE);
}

u32 GetMoveSlot(enum Move *moves, enum Move move)
{
    u32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == move)
            break;
    }
    return i;
}

u32 GetBattlerWeight(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    u32 i;
    u32 weight = GetSpeciesWeight(gBattleMons[battler].species);

    // Autotomize's weight reduction is applied before other weight modifiers (e.g. Heavy Metal / Light Metal / Float Stone).
    for (i = 0; i < gBattleMons[battler].volatiles.autotomizeCount; i++)
    {
        if (weight > 1000)
        {
            weight -= 1000;
        }
        else if (weight <= 1000)
        {
            weight = 1;
            break;
        }
    }

    if (ability == ABILITY_HEAVY_METAL)
        weight *= 2;
    else if (ability == ABILITY_LIGHT_METAL)
        weight /= 2;

    if (holdEffect == HOLD_EFFECT_FLOAT_STONE)
        weight /= 2;

    if (weight == 0)
        weight = 1;

    return weight;
}

u32 CountBattlerStatIncreases(enum BattlerId battler, bool32 countEvasionAcc)
{
    enum Stat i;
    u32 count = 0;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if ((i == STAT_ACC || i == STAT_EVASION) && !countEvasionAcc)
            continue;
        if (gBattleMons[battler].statStages[i] > DEFAULT_STAT_STAGE) // Stat is increased.
            count += gBattleMons[battler].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return count;
}

bool32 BattlerHasCopyableChanges(enum BattlerId battler)
{
    u32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battler].statStages[i] != DEFAULT_STAT_STAGE)
            return TRUE;
    }

    if (gBattleMons[battler].volatiles.focusEnergy
     || gBattleMons[battler].volatiles.dragonCheer
     || gBattleMons[battler].volatiles.bonusCritStages != 0)
        return TRUE;

    return FALSE;
}

u32 GetMoveTargetCount(struct DamageContext *ctx)
{
    switch (GetBattlerMoveTargetType(ctx->battlerAtk, ctx->move))
    {
    case TARGET_BOTH:
        return CountTrue(
            IsBattlerAlive(ctx->battlerDef),
            IsBattlerAlive(GetPartnerBattler(ctx->battlerDef))
        );
    case TARGET_FOES_AND_ALLY:
        return CountTrue(
            IsBattlerAlive(ctx->battlerDef),
            IsBattlerAlive(GetPartnerBattler(ctx->battlerDef)),
            IsBattlerAlive(GetPartnerBattler(ctx->battlerAtk))
        );
    case TARGET_OPPONENTS_FIELD:
        return 1;
    case TARGET_DEPENDS:
    case TARGET_SELECTED:
    case TARGET_RANDOM:
    case TARGET_OPPONENT:
        return CountTrue(IsBattlerAlive(ctx->battlerDef));
    case TARGET_USER:
        return CountTrue(IsBattlerAlive(ctx->battlerAtk));
    default:
        return 0;
    }
}

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
};

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
{
    100, 20,
    250, 40,
    500, 60,
    1000, 80,
    2000, 100,
    0xFFFF, 0xFFFF
};

static const u8 sSpeedDiffPowerTable[] = {40, 60, 80, 120, 150};
static const u8 sHeatCrashPowerTable[] = {40, 40, 60, 80, 100, 120};
static const u8 sTrumpCardPowerTable[] = {200, 80, 60, 50, 40};

static inline u32 CalcRolloutBasePower(enum BattlerId battlerAtk, u32 basePower)
{
    u32 i;
    for (i = 0; i < gBattleMons[battlerAtk].volatiles.rolloutTimer; i++)
        basePower *= 2;
    if (gBattleMons[battlerAtk].volatiles.defenseCurl)
        basePower *= 2;
    return basePower;
}

static inline u32 CalcFuryCutterBasePower(enum BattlerId battlerAtk, u32 basePower)
{
    for (u32 i = 0; i < gBattleMons[battlerAtk].volatiles.furyCutterCounter; i++)
        basePower *= 2;
    return min(basePower, 160); // The duration to reach 160 depends on a gen
}

static inline u32 CalcTerrainBoostedPower(struct DamageContext *ctx, u32 basePower)
{
    bool32 isTerrainAffected = FALSE;

    if (GetMoveTerrainBoost_GroundCheck(ctx->move) == GROUND_CHECK_USER)
        isTerrainAffected = IsBattlerTerrainAffected(ctx->battlerAtk, ctx->abilities[ctx->battlerAtk], ctx->holdEffects[ctx->battlerAtk], GetMoveTerrainBoost_Terrain(ctx->move), ctx->terrain);
    else if (GetMoveTerrainBoost_GroundCheck(ctx->move) == GROUND_CHECK_TARGET)
        isTerrainAffected = IsBattlerTerrainAffected(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef], GetMoveTerrainBoost_Terrain(ctx->move), ctx->terrain);
    else if (gFieldTimers.terrain == GetMoveTerrainBoost_Terrain(ctx->move)) // no ground check (Psyblade)
        isTerrainAffected = TRUE;

    if (isTerrainAffected)
        basePower = uq4_12_multiply(basePower, PercentToUQ4_12AddOne(GetMoveTerrainBoost_Percent(ctx->move)));

    return basePower;
}

static inline u32 IsFieldMudSportAffected(enum Type moveType)
{
    if (moveType != TYPE_ELECTRIC)
        return FALSE;

    if (gFieldStatuses & STATUS_FIELD_MUDSPORT)
        return TRUE;

    if (B_SPORT_TURNS < GEN_6)
    {
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            if (gBattleMons[battler].volatiles.mudSport)
                return TRUE;
        }
    }

    return FALSE;
}

static inline u32 IsFieldWaterSportAffected(enum Type moveType)
{
    if (moveType != TYPE_FIRE)
        return FALSE;

    if (gFieldStatuses & STATUS_FIELD_WATERSPORT)
        return TRUE;

    if (B_SPORT_TURNS < GEN_6)
    {
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            if (gBattleMons[battler].volatiles.waterSport)
                return TRUE;
        }
    }

    return FALSE;
}

static inline u32 CalcMoveBasePower(struct DamageContext *ctx)
{
    enum BattlerId battlerAtk = ctx->battlerAtk;
    enum BattlerId battlerDef = ctx->battlerDef;
    enum Move move = ctx->move;

    u32 i;
    u32 basePower = GetMovePower(move);
    u32 moveEffect = GetMoveEffect(move);
    u32 weight, hpFraction, speed;

    switch (GetActiveGimmick(battlerAtk))
    {
    case GIMMICK_Z_MOVE:
        return GetZMovePower(ctx->baseMove);
    case GIMMICK_DYNAMAX:
        return GetMaxMovePower(ctx->baseMove, ctx->move);
    default:
        break;
    }

    switch (moveEffect)
    {
    case EFFECT_PLEDGE:
        if (gBattleStruct->pledgeState == PLEDGE_COMBO_ATTACK)
            basePower = 150;
        break;
    case EFFECT_FLING:
        basePower = GetFlingPowerFromItemId(gBattleMons[battlerAtk].item);
        break;
    case EFFECT_POWER_BASED_ON_USER_HP:
        basePower = gBattleMons[battlerAtk].hp * basePower / gBattleMons[battlerAtk].maxHP;
        break;
    case EFFECT_FLAIL:
        hpFraction = GetScaledHPFraction(gBattleMons[battlerAtk].hp, gBattleMons[battlerAtk].maxHP, 48);
        for (i = 0; i < sizeof(sFlailHpScaleToPowerTable); i += 2)
        {
            if (hpFraction <= sFlailHpScaleToPowerTable[i])
                break;
        }
        basePower = sFlailHpScaleToPowerTable[i + 1];
        break;
    case EFFECT_RETURN:
        basePower = 10 * (gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FRUSTRATION:
        basePower = 10 * (MAX_FRIENDSHIP - gBattleMons[battlerAtk].friendship) / 25;
        break;
    case EFFECT_FURY_CUTTER:
        basePower = CalcFuryCutterBasePower(battlerAtk, basePower);
        break;
    case EFFECT_ROLLOUT:
        basePower = CalcRolloutBasePower(battlerAtk, basePower);
        break;
    case EFFECT_MAGNITUDE:
        basePower = gBattleStruct->magnitudeBasePower;
        break;
    case EFFECT_PRESENT:
        basePower = gBattleStruct->presentBasePower;
        break;
    case EFFECT_TRIPLE_KICK:
        basePower *= 1 + GetMoveStrikeCount(move) - gMultiHitCounter;
        break;
    case EFFECT_SPIT_UP:
        basePower = 100 * gBattleMons[battlerAtk].volatiles.stockpileCounter;
        break;
    case EFFECT_REVENGE:
        if (gProtectStructs[battlerAtk].revengeDoubled & 1u << battlerDef)
            basePower *= 2;
        break;
    case EFFECT_WEATHER_BALL:
        if (GetAttackerWeather(ctx->holdEffects[ctx->battlerAtk], ctx->abilities[ctx->battlerAtk], ctx->weather) & (B_WEATHER_ANY & ~B_WEATHER_STRONG_WINDS))
            basePower *= 2;
        break;
    case EFFECT_PURSUIT:
        if (gBattleStruct->battlerState[battlerDef].pursuitTarget)
            basePower *= 2;
        break;
    case EFFECT_NATURAL_GIFT:
        basePower = gBerries[ItemIdToBerryType(gBattleMons[battlerAtk].item)].naturalGiftPower;
        break;
    case EFFECT_DOUBLE_POWER_ON_ARG_STATUS:
        // Comatose targets treated as if asleep
        if ((gBattleMons[battlerDef].status1 | (STATUS1_SLEEP * (ctx->abilities[ctx->battlerDef] == ABILITY_COMATOSE))) & GetMoveEffectArg_Status(move)
         && !((GetMoveAdditionalEffectById(move, 0)->moveEffect == MOVE_EFFECT_REMOVE_STATUS) && DoesSubstituteBlockMove(battlerAtk, battlerDef, move)))
            basePower *= 2;
        break;
    case EFFECT_POWER_BASED_ON_TARGET_HP:
        basePower = gBattleMons[battlerDef].hp * basePower / gBattleMons[battlerDef].maxHP;
        break;
    case EFFECT_ASSURANCE:
        if (gProtectStructs[battlerDef].assuranceDoubled)
            basePower *= 2;
        break;
    case EFFECT_TRUMP_CARD:
        i = GetMoveSlot(gBattleMons[battlerAtk].moves, ctx->chosenMove);
        if (i != MAX_MON_MOVES)
        {
            if (gBattleMons[battlerAtk].pp[i] >= ARRAY_COUNT(sTrumpCardPowerTable))
                basePower = sTrumpCardPowerTable[ARRAY_COUNT(sTrumpCardPowerTable) - 1];
            else
                basePower = sTrumpCardPowerTable[gBattleMons[battlerAtk].pp[i]];
        }
        break;
    case EFFECT_ACROBATICS:
        if (gBattleMons[battlerAtk].item == ITEM_NONE
            // Edge case, because removal of items happens after damage calculation.
            || (gSpecialStatuses[battlerAtk].gemBoost && ctx->holdEffects[battlerAtk] == HOLD_EFFECT_GEMS))
            basePower *= 2;
        break;
    case EFFECT_LOW_KICK:
        weight = GetBattlerWeight(battlerDef, ctx->abilities[battlerDef], ctx->holdEffects[battlerDef]);
        for (i = 0; sWeightToDamageTable[i] != 0xFFFF; i += 2)
        {
            if (sWeightToDamageTable[i] > weight)
                break;
        }
        if (sWeightToDamageTable[i] != 0xFFFF)
            basePower = sWeightToDamageTable[i + 1];
        else
            basePower = 120;
        break;
    case EFFECT_HEAT_CRASH:
        weight = GetBattlerWeight(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk]) / GetBattlerWeight(battlerDef, ctx->abilities[battlerDef], ctx->holdEffects[battlerDef]);
        if (weight >= ARRAY_COUNT(sHeatCrashPowerTable))
            basePower = sHeatCrashPowerTable[ARRAY_COUNT(sHeatCrashPowerTable) - 1];
        else
            basePower = sHeatCrashPowerTable[weight];
        break;
    case EFFECT_PUNISHMENT:
        basePower = 60 + (CountBattlerStatIncreases(battlerDef, FALSE) * 20);
        if (basePower > 200)
            basePower = 200;
        break;
    case EFFECT_STORED_POWER:
        basePower += (CountBattlerStatIncreases(battlerAtk, TRUE) * 20);
        break;
    case EFFECT_ELECTRO_BALL:
        speed = GetBattlerTotalSpeedStat(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk]) / GetBattlerTotalSpeedStat(battlerDef, ctx->abilities[battlerDef], ctx->holdEffects[battlerDef]);
        if (speed >= ARRAY_COUNT(sSpeedDiffPowerTable))
            speed = ARRAY_COUNT(sSpeedDiffPowerTable) - 1;
        basePower = sSpeedDiffPowerTable[speed];
        break;
    case EFFECT_GYRO_BALL:
        {
            u32 attackerSpeed = GetBattlerTotalSpeedStat(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk]);
            if (attackerSpeed == 0)
            {
                basePower = 1;
            }
            else
            {
                basePower = ((25 * GetBattlerTotalSpeedStat(battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef])) / attackerSpeed) + 1;
                if (basePower > 150)
                    basePower = 150;
            }
            break;
        }
    case EFFECT_ECHOED_VOICE:
        // gBattleStruct->echoedVoiceCounter incremented in EndTurnVarious called by DoEndTurnEffects
        if (gBattleStruct->echoedVoiceCounter != 0)
        {
            basePower += (basePower * gBattleStruct->echoedVoiceCounter);
            if (basePower > 200)
                basePower = 200;
        }
        break;
    case EFFECT_PAYBACK:
        if (ctx->aiCalc)
        {
            if (Ai_AttackerMovesAfterTarget(battlerAtk, battlerDef))
                basePower *= 2;
        }
        else if (HasBattlerActedThisTurn(battlerDef)
            && (B_PAYBACK_SWITCH_BOOST < GEN_5 || !BattlerJustSwitchedIn(battlerDef)))
        {
            basePower *= 2;
        }
        break;
    case EFFECT_BOLT_BEAK:
        if (ctx->aiCalc)
        {
            if (!Ai_AttackerMovesAfterTarget(battlerAtk, battlerDef))
                basePower *= 2;
        }
        else if (!HasBattlerActedThisTurn(battlerDef)
              || BattlerJustSwitchedIn(battlerDef))
        {
            basePower *= 2;
        }
        break;
    case EFFECT_FUSION_COMBO:
        if (move == gLastUsedMove)
            break;
        // fallthrough
    case EFFECT_ROUND:
        // don't double power due to previous turn's Round/Fusion move
        if (gCurrentTurnActionNumber != 0
         && gActionsByTurnOrder[gCurrentTurnActionNumber - 1] == B_ACTION_USE_MOVE
         && GetMoveEffect(gLastUsedMove) == moveEffect)
            basePower *= 2;
        break;
    case EFFECT_LASH_OUT:
        if (gProtectStructs[battlerAtk].lashOutAffected)
            basePower *= 2;
        break;
    case EFFECT_TERRAIN_BOOST:
        basePower = CalcTerrainBoostedPower(ctx, basePower);
        break;
    case EFFECT_DYNAMAX_DOUBLE_DMG:
        if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            basePower *= 2;
        break;
    case EFFECT_HIDDEN_POWER:
    {
        if (B_HIDDEN_POWER_DMG < GEN_6)
        {
            u8 powerBits = ((gBattleMons[battlerAtk].hpIV & 2) >> 1)
                         | ((gBattleMons[battlerAtk].attackIV & 2) << 0)
                         | ((gBattleMons[battlerAtk].defenseIV & 2) << 1)
                         | ((gBattleMons[battlerAtk].speedIV & 2) << 2)
                         | ((gBattleMons[battlerAtk].spAttackIV & 2) << 3)
                         | ((gBattleMons[battlerAtk].spDefenseIV & 2) << 4);

            basePower = (40 * powerBits) / 63 + 30;
        }
        break;
    }
    case EFFECT_GRAV_APPLE:
        if (gFieldStatuses & STATUS_FIELD_GRAVITY)
            basePower = uq4_12_multiply(basePower, UQ_4_12(1.5));
        break;
    case EFFECT_TERRAIN_PULSE:
        if (IsAnyTerrainAffected(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk], ctx->terrain))
            basePower *= 2;
        break;
    case EFFECT_BEAT_UP:
        if (GetConfig(B_BEAT_UP) >= GEN_5)
            basePower = CalcBeatUpPower();
        break;
    case EFFECT_RAGE_FIST:
        basePower += 50 * GetBattlerPartyState(battlerAtk)->timesGotHit;
        basePower = (basePower > 350) ? 350 : basePower;
        break;
    case EFFECT_FICKLE_BEAM:
        if (gBattleStruct->fickleBeamBoosted)
            basePower *= 2;
        break;
    case EFFECT_TERA_BLAST:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA && GetBattlerTeraType(battlerAtk) == TYPE_STELLAR)
            basePower = 100;
        break;
    case EFFECT_LAST_RESPECTS:
        basePower += (basePower * min(100, gBattleStruct->faintCounter[GetBattlerTrainer(battlerAtk)]));
        break;
    case EFFECT_SPECIES_POWER_OVERRIDE:
        if (gBattleMons[battlerAtk].species == GetMoveSpeciesPowerOverride_Species(ctx->move))
            basePower = GetMoveSpeciesPowerOverride_Power(ctx->move);
    default:
        break;
    }

    if (basePower == 0)
        basePower = 1;
    return basePower;
}

static bool32 DmgCalc_IsAbilityOnField(enum Ability ability, enum Ability abilities[], enum BattlerId *battler)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (abilities[i] == ability)
        {
            *battler = i;
            return TRUE;
        }
    }

    return FALSE;
}

static inline u32 CalcMoveBasePowerAfterModifiers(struct DamageContext *ctx)
{
    u32 holdEffectParamAtk;
    u32 basePower = CalcMoveBasePower(ctx);
    enum BattlerId battlerAtk = ctx->battlerAtk;
    enum BattlerId battlerDef = ctx->battlerDef;
    enum Move move = ctx->move;
    enum Type moveType = ctx->moveType;
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);

    uq4_12_t holdEffectModifier;
    uq4_12_t modifier = UQ_4_12(1.0);
    u32 atkSide = GetBattlerSide(battlerAtk);

    // move effect
    switch (moveEffect)
    {
    case EFFECT_FACADE:
        if (gBattleMons[battlerAtk].status1 & (STATUS1_BURN | STATUS1_PSN_ANY | STATUS1_PARALYSIS | STATUS1_FROSTBITE))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_BRINE:
        if (gBattleMons[battlerDef].hp <= (gBattleMons[battlerDef].maxHP / 2))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_RETALIATE:
    {
        u32 retaliateTimer = gSideTimers[atkSide].retaliateTimer;
        if (retaliateTimer  == 1 || (gAiLogicData->switchInCalc && retaliateTimer == 2))
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    }
    case EFFECT_SOLAR_BEAM:
    {
        u32 weather = GetAttackerWeather(ctx->holdEffects[ctx->battlerAtk], ctx->abilities[ctx->battlerAtk], ctx->weather);
        if ((GetConfig(B_SANDSTORM_SOLAR_BEAM) >= GEN_3 && weather & B_WEATHER_LOW_LIGHT)
            || weather & (B_WEATHER_RAIN | B_WEATHER_ICY_ANY | B_WEATHER_FOG)) // Excludes Sandstorm
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
        break;
    }
    case EFFECT_STOMPING_TANTRUM:
        if (!gAiLogicData->switchInCalc && gBattleStruct->battlerState[battlerAtk].stompingTantrumTimer == 1)
            modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case EFFECT_MAGNITUDE:
    case EFFECT_EARTHQUAKE:
        if (ctx->terrain == B_TERRAIN_GRASSY && !IsSemiInvulnerable(battlerDef, CHECK_ALL))
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
        break;
    case EFFECT_KNOCK_OFF:
        if (B_KNOCK_OFF_DMG >= GEN_6
            && gBattleMons[battlerDef].item != ITEM_NONE
            && CanBattlerGetOrLoseItem(battlerDef, battlerAtk, gBattleMons[battlerDef].item))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    // various effects
    for (u32 i = 0; i < gProtectStructs[battlerAtk].helpingHand; i++)
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));

    if (gSpecialStatuses[battlerAtk].gemBoost)
        modifier = uq4_12_multiply(modifier, PercentToUQ4_12AddOne(gSpecialStatuses[battlerAtk].gemParam));
    if (moveType == TYPE_ELECTRIC && gBattleMons[battlerAtk].volatiles.chargeTimer > 0)
        modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
    if (GetMoveEffect(ctx->chosenMove) == EFFECT_ME_FIRST)
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
    if (IsGrassyTerrainAffected(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk], ctx->terrain) && moveType == TYPE_GRASS)
        modifier = uq4_12_multiply(modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8 ? UQ_4_12(1.3) : UQ_4_12(1.5)));
    if (IsMistyTerrainAffected(battlerDef, ctx->abilities[battlerDef], ctx->holdEffects[battlerDef], ctx->terrain) && moveType == TYPE_DRAGON)
        modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
    if (IsElectricTerrainAffected(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk], ctx->terrain) && moveType == TYPE_ELECTRIC)
        modifier = uq4_12_multiply(modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8 ? UQ_4_12(1.3) : UQ_4_12(1.5)));
    if (IsPsychicTerrainAffected(battlerAtk, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk], ctx->terrain) && moveType == TYPE_PSYCHIC)
        modifier = uq4_12_multiply(modifier, (B_TERRAIN_TYPE_BOOST >= GEN_8 ? UQ_4_12(1.3) : UQ_4_12(1.5)));
    if (IsFieldMudSportAffected(ctx->moveType))
        modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_SPORT_DMG_REDUCTION) >= GEN_5 ? 0.33 : 0.5));
    if (IsFieldWaterSportAffected(ctx->moveType))
        modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_SPORT_DMG_REDUCTION) >= GEN_5 ? 0.33 : 0.5));

    // attacker's abilities
    switch (ctx->abilities[battlerAtk])
    {
    case ABILITY_TECHNICIAN:
        if (basePower <= 60)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_FLARE_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_BURN && IsBattleMoveSpecial(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TOXIC_BOOST:
        if (gBattleMons[battlerAtk].status1 & STATUS1_PSN_ANY && IsBattleMovePhysical(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_RECKLESS:
        if (moveEffect == EFFECT_RECOIL || moveEffect == EFFECT_RECOIL_IF_MISS)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_IRON_FIST:
        if (IsPunchingMove(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_SHEER_FORCE:
        if (MoveIsAffectedBySheerForce(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_SAND_FORCE:
        if ((moveType == TYPE_STEEL || moveType == TYPE_ROCK || moveType == TYPE_GROUND)
            && ctx->weather & B_WEATHER_SANDSTORM)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_RIVALRY:
        if (AreBattlersOfSameGender(battlerAtk, battlerDef))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        else if (AreBattlersOfOppositeGender(battlerAtk, battlerDef))
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.75));
        break;
    case ABILITY_ANALYTIC:
        if (moveEffect == EFFECT_FUTURE_SIGHT)
            break;

        if (ctx->aiCalc)
        {
            if (Ai_AttackerMovesLast(battlerAtk))
               modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        }
        else if (IsLastMonToMove(battlerAtk))
        {
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        }
        break;
    case ABILITY_TOUGH_CLAWS:
        if (IsMoveMakingContact(battlerAtk, battlerDef, ctx->abilities[battlerAtk], ctx->holdEffects[battlerAtk], ctx->move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STRONG_JAW:
        if (IsBitingMove(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_MEGA_LAUNCHER:
        if (IsPulseMove(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_WATER)
           modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));
        break;
    case ABILITY_STEELWORKER:
        if (moveType == TYPE_STEEL)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PIXILATE:
        if (moveType == TYPE_FAIRY && gBattleStruct->battlerState[battlerAtk].ateBoost)
            modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_ATE_MULTIPLIER) >= GEN_7 ? 1.2 : 1.3));
        break;
    case ABILITY_GALVANIZE:
        if (moveType == TYPE_ELECTRIC && gBattleStruct->battlerState[battlerAtk].ateBoost)
            modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_ATE_MULTIPLIER) >= GEN_7 ? 1.2 : 1.3));
        break;
    case ABILITY_REFRIGERATE:
        if (moveType == TYPE_ICE && gBattleStruct->battlerState[battlerAtk].ateBoost)
            modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_ATE_MULTIPLIER) >= GEN_7 ? 1.2 : 1.3));
        break;
    case ABILITY_AERILATE:
        if (moveType == TYPE_FLYING && gBattleStruct->battlerState[battlerAtk].ateBoost)
            modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_ATE_MULTIPLIER) >= GEN_7 ? 1.2 : 1.3));
        break;
    case ABILITY_DRAGONIZE:
        if (moveType == TYPE_DRAGON && gBattleStruct->battlerState[battlerAtk].ateBoost)
            modifier = uq4_12_multiply(modifier, UQ_4_12(GetConfig(B_ATE_MULTIPLIER) >= GEN_7 ? 1.2 : 1.3));
        break;
    case ABILITY_NORMALIZE:
        if (moveType == TYPE_NORMAL && gBattleStruct->battlerState[battlerAtk].ateBoost && GetConfig(B_ATE_MULTIPLIER) >= GEN_7)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    case ABILITY_PUNK_ROCK:
        if (IsSoundMove(move))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STEELY_SPIRIT:
        if (moveType == TYPE_STEEL)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SHARPNESS:
        if (IsSlicingMove(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SUPREME_OVERLORD:
        modifier = uq4_12_multiply(modifier, GetSupremeOverlordModifier(battlerAtk));
        break;
    default:
        break;
    }

    // field abilities
    enum BattlerId fieldAbilityBattler = MAX_BATTLERS_COUNT;
    if ((moveType == TYPE_DARK && DmgCalc_IsAbilityOnField(ABILITY_DARK_AURA, ctx->abilities, &fieldAbilityBattler))
     || (moveType == TYPE_FAIRY && DmgCalc_IsAbilityOnField(ABILITY_FAIRY_AURA, ctx->abilities, &fieldAbilityBattler)))
    {
        if (ctx->updateFlags)
            RecordAbilityBattle(fieldAbilityBattler, ctx->abilities[fieldAbilityBattler]);

        if (DmgCalc_IsAbilityOnField(ABILITY_AURA_BREAK, ctx->abilities, &fieldAbilityBattler))
        {
            if (ctx->updateFlags)
                RecordAbilityBattle(fieldAbilityBattler, ctx->abilities[fieldAbilityBattler]);
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.75));
        }
        else
        {
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.33));
        }

    }

    // attacker partner's abilities
    switch (ctx->abilities[GetPartnerBattler(battlerAtk)])
    {
    case ABILITY_BATTERY:
        if (IsBattleMoveSpecial(move))
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_POWER_SPOT:
        modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        break;
    case ABILITY_STEELY_SPIRIT:
        if (moveType == TYPE_STEEL)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    // target's abilities
    switch (ctx->abilities[ctx->battlerDef])
    {
    case ABILITY_HEATPROOF:
    case ABILITY_WATER_BUBBLE:
        if (moveType == TYPE_FIRE)
        {
            modifier = uq4_12_multiply(modifier, UQ_4_12(0.5));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ctx->abilities[ctx->battlerDef]);
        }
        break;
    case ABILITY_DRY_SKIN:
        if (moveType == TYPE_FIRE)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.25));
        break;
    default:
        break;
    }

    holdEffectParamAtk = GetBattlerHoldEffectParam(battlerAtk);
    if (holdEffectParamAtk > 100)
        holdEffectParamAtk = 100;

    holdEffectModifier = uq4_12_add(UQ_4_12(1.0), PercentToUQ4_12(holdEffectParamAtk));

    // attacker's hold effect
    switch (ctx->holdEffects[ctx->battlerAtk])
    {
    case HOLD_EFFECT_MUSCLE_BAND:
        if (IsBattleMovePhysical(move))
            modifier = uq4_12_multiply(modifier, uq4_12_add(UQ_4_12(1.0), PercentToUQ4_12_Floored(holdEffectParamAtk)));
        break;
    case HOLD_EFFECT_WISE_GLASSES:
        if (IsBattleMoveSpecial(move))
            modifier = uq4_12_multiply(modifier, uq4_12_add(UQ_4_12(1.0), PercentToUQ4_12_Floored(holdEffectParamAtk)));
        break;
    case HOLD_EFFECT_LUSTROUS_ORB:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_PALKIA && (moveType == TYPE_WATER || moveType == TYPE_DRAGON))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_ADAMANT_ORB:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_DIALGA && (moveType == TYPE_STEEL || moveType == TYPE_DRAGON))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_GRISEOUS_ORB:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_GIRATINA && (moveType == TYPE_GHOST || moveType == TYPE_DRAGON))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_SOUL_DEW:
        if ((gBattleMons[battlerAtk].species == SPECIES_LATIAS || gBattleMons[battlerAtk].species == SPECIES_LATIOS)
            && ((B_SOUL_DEW_BOOST >= GEN_7 && (moveType == TYPE_PSYCHIC || moveType == TYPE_DRAGON))
             || (B_SOUL_DEW_BOOST < GEN_7 && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && IsBattleMoveSpecial(move))))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_TYPE_POWER:
    case HOLD_EFFECT_PLATE:
        if (moveType == GetItemSecondaryId(gBattleMons[battlerAtk].item))
            modifier = uq4_12_multiply(modifier, holdEffectModifier);
        break;
    case HOLD_EFFECT_PUNCHING_GLOVE:
        if (IsPunchingMove(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.1));
        break;
    case HOLD_EFFECT_OGERPON_MASK:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_OGERPON)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.2));
        break;
    default:
        break;
    }

    // Terastallization boosts weak, non-priority, non-multi hit moves after modifiers to 60 BP.
    if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA
        && (moveType == GetBattlerTeraType(battlerAtk)
        || (GetBattlerTeraType(battlerAtk) == TYPE_STELLAR && IsTypeStellarBoosted(battlerAtk, moveType)))
        && uq4_12_multiply_by_int_half_down(modifier, basePower) < 60
        && GetMovePower(move) > 1
        && GetMoveStrikeCount(move) < 2
        && !IsMultiHitMove(move)
        && moveEffect != EFFECT_POWER_BASED_ON_USER_HP
        && moveEffect != EFFECT_POWER_BASED_ON_TARGET_HP
        && GetMovePriority(move) == 0)
    {
        return 60;
    }

    return uq4_12_multiply_by_int_half_down(modifier, basePower);
}

static bool32 IsRuinStatusActive(u32 fieldEffect)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (GetBattlerVolatile(battler, fieldEffect))
            return TRUE;
    }

    return FALSE;
}

static inline uq4_12_t ApplyOffensiveBadgeBoost(uq4_12_t modifier, enum BattlerId battler, enum Move move)
{
    if (ShouldGetStatBadgeBoost(B_FLAG_BADGE_BOOST_ATTACK, battler) && IsBattleMovePhysical(move))
        modifier = uq4_12_multiply_half_down(modifier, GetBadgeBoostModifier());
    if (ShouldGetStatBadgeBoost(B_FLAG_BADGE_BOOST_SPATK, battler) && IsBattleMoveSpecial(move))
        modifier = uq4_12_multiply_half_down(modifier, GetBadgeBoostModifier());
    return modifier;
}

static inline uq4_12_t ApplyDefensiveBadgeBoost(uq4_12_t modifier, enum BattlerId battler, enum Move move)
{
    if (ShouldGetStatBadgeBoost(B_FLAG_BADGE_BOOST_DEFENSE, battler) && IsBattleMovePhysical(move))
        modifier = uq4_12_multiply_half_down(modifier, GetBadgeBoostModifier());
    if (ShouldGetStatBadgeBoost(B_FLAG_BADGE_BOOST_SPDEF, battler) && IsBattleMoveSpecial(move))
        modifier = uq4_12_multiply_half_down(modifier, GetBadgeBoostModifier());
    return modifier;
}

static inline u32 CalcAttackStat(struct DamageContext *ctx)
{
    u8 atkStage;
    u32 atkStat;
    uq4_12_t modifier;
    enum Species atkBaseSpeciesId;
    enum BattlerId battlerAtk = ctx->battlerAtk;
    enum BattlerId battlerDef = ctx->battlerDef;
    enum Move move = ctx->move;
    enum Type moveType = ctx->moveType;
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);

    atkBaseSpeciesId = GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species);

    if (moveEffect == EFFECT_FOUL_PLAY)
    {
        if (IsBattleMovePhysical(move))
        {
            atkStat = gBattleMons[battlerDef].attack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerDef].spAttack;
            atkStage = gBattleMons[battlerDef].statStages[STAT_SPATK];
        }
    }
    else if (moveEffect == EFFECT_BODY_PRESS)
    {
        if (IsBattleMovePhysical(move))
        {
            atkStat = gBattleMons[battlerAtk].defense;
            // Edge case: Body Press used during Wonder Room. For some reason, it still uses Defense over Sp.Def, but uses Sp.Def stat changes
            if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
                atkStage = gBattleMons[battlerAtk].statStages[STAT_SPDEF];
            else
                atkStage = gBattleMons[battlerAtk].statStages[STAT_DEF];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spDefense;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_SPDEF];
        }
    }
    else
    {
        if (IsBattleMovePhysical(move))
        {
            atkStat = gBattleMons[battlerAtk].attack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_ATK];
        }
        else
        {
            atkStat = gBattleMons[battlerAtk].spAttack;
            atkStage = gBattleMons[battlerAtk].statStages[STAT_SPATK];
        }
    }

    // critical hits ignore attack stat's stage drops
    if (ctx->isCrit && atkStage < DEFAULT_STAT_STAGE)
        atkStage = DEFAULT_STAT_STAGE;
    // Pokémon with unaware ignore attack stat changes while taking damage
    if (ctx->abilities[ctx->battlerDef] == ABILITY_UNAWARE)
        atkStage = DEFAULT_STAT_STAGE;

    atkStat *= gStatStageRatios[atkStage][0];
    atkStat /= gStatStageRatios[atkStage][1];

    // apply attack stat modifiers
    modifier = UQ_4_12(1.0);

    if (ctx->isSelfInflicted)
        return uq4_12_multiply_by_int_half_down(ApplyOffensiveBadgeBoost(modifier, battlerAtk, move), atkStat);

    // attacker's abilities
    switch (ctx->abilities[battlerAtk])
    {
    case ABILITY_HUGE_POWER:
    case ABILITY_PURE_POWER:
        if (IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case ABILITY_SLOW_START:
        if (gBattleMons[battlerAtk].volatiles.slowStartTimer > 0 && IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
        break;
    case ABILITY_SOLAR_POWER:
        if (IsBattleMoveSpecial(move) && IsBattlerWeatherAffected(ctx->holdEffects[ctx->battlerAtk], ctx->weather, B_WEATHER_SUN))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_DEFEATIST:
        if (gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 2))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
        break;
    case ABILITY_FLASH_FIRE:
        if (moveType == TYPE_FIRE && gBattleMons[battlerAtk].volatiles.flashFireBoosted)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_SWARM:
        if (moveType == TYPE_BUG && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TORRENT:
        if (moveType == TYPE_WATER && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_BLAZE:
        if (moveType == TYPE_FIRE && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_OVERGROW:
        if (moveType == TYPE_GRASS && gBattleMons[battlerAtk].hp <= (gBattleMons[battlerAtk].maxHP / 3))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PLUS:
        if (IsBattleMoveSpecial(move))
        {
            enum Ability partnerAbility = ctx->abilities[GetPartnerBattler(battlerAtk)];
            if (partnerAbility == ABILITY_MINUS
            || (B_PLUS_MINUS_INTERACTION >= GEN_5 && partnerAbility == ABILITY_PLUS))
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_MINUS:
        if (IsBattleMoveSpecial(move))
        {
            enum Ability partnerAbility = ctx->abilities[GetPartnerBattler(battlerAtk)];
            if (partnerAbility == ABILITY_PLUS
            || (B_PLUS_MINUS_INTERACTION >= GEN_5 && partnerAbility == ABILITY_MINUS))
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[battlerAtk].species == SPECIES_CHERRIM_SUNSHINE
         && IsBattlerWeatherAffected(ctx->holdEffects[ctx->battlerAtk], ctx->weather, B_WEATHER_SUN) && IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_HUSTLE:
        if (IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_STAKEOUT:
        if (BattlerJustSwitchedIn(battlerDef))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case ABILITY_GUTS:
        if (gBattleMons[battlerAtk].status1 & STATUS1_ANY && IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_TRANSISTOR:
        if (moveType == TYPE_ELECTRIC)
        {
            if (GetConfig(B_TRANSISTOR_BOOST) >= GEN_9)
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
            else
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        }
        break;
    case ABILITY_DRAGONS_MAW:
        if (moveType == TYPE_DRAGON)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_GORILLA_TACTICS:
        if (IsBattleMovePhysical(move)
         && !IsGimmickSelected(battlerAtk, GIMMICK_DYNAMAX)
         && GetActiveGimmick(battlerAtk) != GIMMICK_DYNAMAX)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_ROCKY_PAYLOAD:
        if (moveType == TYPE_ROCK)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PROTOSYNTHESIS:
        if (!(gBattleMons[battlerAtk].volatiles.transformed))
        {
            enum Stat atkHighestStat = GetParadoxBoostedStatId(battlerAtk);
            if (ctx->weather & B_WEATHER_SUN || gBattleMons[battlerAtk].volatiles.boosterEnergyActivated)
            {
                if ((IsBattleMovePhysical(move) && atkHighestStat == STAT_ATK) || (IsBattleMoveSpecial(move) && atkHighestStat == STAT_SPATK))
                    modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
            }
        }
        break;
    case ABILITY_QUARK_DRIVE:
        if (!(gBattleMons[battlerAtk].volatiles.transformed))
        {
            enum Stat atkHighestStat = GetParadoxBoostedStatId(battlerAtk);
            if (gFieldTimers.terrain == B_TERRAIN_ELECTRIC || gBattleMons[battlerAtk].volatiles.boosterEnergyActivated)
            {
                if ((IsBattleMovePhysical(move) && atkHighestStat == STAT_ATK) || (IsBattleMoveSpecial(move) && atkHighestStat == STAT_SPATK))
                    modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
            }
        }
        break;
    case ABILITY_ORICHALCUM_PULSE:
        if (ctx->weather & B_WEATHER_SUN && IsBattleMovePhysical(move)
         && ctx->holdEffects[ctx->battlerAtk] != HOLD_EFFECT_UTILITY_UMBRELLA)
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3333));
        break;
    case ABILITY_HADRON_ENGINE:
        if (gFieldTimers.terrain == B_TERRAIN_ELECTRIC && IsBattleMoveSpecial(move))
           modifier = uq4_12_multiply(modifier, UQ_4_12(1.3333));
        break;
    case ABILITY_FIRE_MANE:
        if (moveType == TYPE_FIRE)
            modifier = uq4_12_multiply(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    // target's abilities
    switch (ctx->abilities[ctx->battlerDef])
    {
    case ABILITY_THICK_FAT:
        if (moveType == TYPE_FIRE || moveType == TYPE_ICE)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_THICK_FAT);
        }
        break;
    case ABILITY_PURIFYING_SALT:
        if (moveType == TYPE_GHOST)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.5));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_PURIFYING_SALT);
        }
        break;
    default:
        break;
    }

    // ally's abilities
    switch (ctx->abilities[GetPartnerBattler(battlerAtk)])
    {
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[GetPartnerBattler(battlerAtk)].species == SPECIES_CHERRIM_SUNSHINE && IsBattlerWeatherAffected(ctx->holdEffects[GetPartnerBattler(battlerAtk)], ctx->weather, B_WEATHER_SUN) && IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    // Ruin field effects
    if (IsBattleMoveSpecial(move) && ctx->abilities[ctx->battlerAtk] != ABILITY_VESSEL_OF_RUIN && IsRuinStatusActive(VOLATILE_VESSEL_OF_RUIN))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.75));

    if (IsBattleMovePhysical(move) && ctx->abilities[ctx->battlerAtk] != ABILITY_TABLETS_OF_RUIN && IsRuinStatusActive(VOLATILE_TABLETS_OF_RUIN))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.75));

    // attacker's hold effect
    switch (ctx->holdEffects[ctx->battlerAtk])
    {
    case HOLD_EFFECT_THICK_CLUB:
        if ((atkBaseSpeciesId == SPECIES_CUBONE || atkBaseSpeciesId == SPECIES_MAROWAK) && IsBattleMovePhysical(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_DEEP_SEA_TOOTH:
        if (gBattleMons[battlerAtk].species == SPECIES_CLAMPERL && IsBattleMoveSpecial(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_LIGHT_BALL:
        if (atkBaseSpeciesId == SPECIES_PIKACHU && (GetConfig(B_LIGHT_BALL_ATTACK_BOOST) >= GEN_4 || IsBattleMoveSpecial(move)))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_CHOICE_BAND:
        if (IsBattleMovePhysical(move) && GetActiveGimmick(battlerAtk) != GIMMICK_DYNAMAX)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_CHOICE_SPECS:
        if (IsBattleMoveSpecial(move) && GetActiveGimmick(battlerAtk) != GIMMICK_DYNAMAX)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    modifier = ApplyOffensiveBadgeBoost(modifier, battlerAtk, move);

    return uq4_12_multiply_by_int_half_down(modifier, atkStat);
}

static bool32 CanEvolve(enum Species species)
{
    u32 i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions != NULL)
    {
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (evolutions[i].method
             && SanitizeSpeciesId(evolutions[i].targetSpecies) != SPECIES_NONE)
                return TRUE;
        }
    }
    return FALSE;
}

static inline u32 CalcDefenseStat(struct DamageContext *ctx)
{
    bool32 usesDefStat;
    u8 defStage;
    u32 defStat, def, spDef;
    uq4_12_t modifier;
    enum BattlerId battlerDef = ctx->battlerDef;
    enum Move move = ctx->move;
    enum BattleMoveEffects moveEffect = GetMoveEffect(move);
    def = gBattleMons[battlerDef].defense;
    spDef = gBattleMons[battlerDef].spDefense;

    if (moveEffect == EFFECT_PSYSHOCK || IsBattleMovePhysical(move)) // uses defense stat instead of sp.def
    {
        if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) // the defense stats are swapped
        {
            defStat = spDef;
            usesDefStat = FALSE;
        }
        else
        {
            defStat = def;
            usesDefStat = TRUE;
        }
        defStage = gBattleMons[battlerDef].statStages[STAT_DEF];
    }
    else // is special
    {
        if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM) // the defense stats are swapped
        {
            defStat = def;
            usesDefStat = TRUE;
        }
        else
        {
            defStat = spDef;
            usesDefStat = FALSE;
        }
        defStage = gBattleMons[battlerDef].statStages[STAT_SPDEF];
    }

    // Self-destruct / Explosion cut defense in half
    if (GetConfig(B_EXPLOSION_DEFENSE) < GEN_5 && IsExplosionMove(ctx->move))
        defStat /= 2;

    // critical hits ignore positive stat changes
    if (ctx->isCrit && defStage > DEFAULT_STAT_STAGE)
        defStage = DEFAULT_STAT_STAGE;
    // Pokémon with unaware ignore defense stat changes while dealing damage
    if (ctx->abilities[ctx->battlerAtk] == ABILITY_UNAWARE)
        defStage = DEFAULT_STAT_STAGE;
    // certain moves also ignore stat changes
    if (MoveIgnoresDefenseEvasionStages(move))
        defStage = DEFAULT_STAT_STAGE;

    defStat *= gStatStageRatios[defStage][0];
    defStat /= gStatStageRatios[defStage][1];

    // apply defense stat modifiers
    modifier = UQ_4_12(1.0);

    if (ctx->isSelfInflicted)
        return uq4_12_multiply_by_int_half_down(ApplyDefensiveBadgeBoost(modifier, battlerDef, move), defStat);

    // target's abilities
    switch (ctx->abilities[ctx->battlerDef])
    {
    case ABILITY_MARVEL_SCALE:
        if (gBattleMons[battlerDef].status1 & STATUS1_ANY && usesDefStat)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_MARVEL_SCALE);
        }
        break;
    case ABILITY_FUR_COAT:
        if (usesDefStat)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_FUR_COAT);
        }
        break;
    case ABILITY_GRASS_PELT:
        if (gFieldTimers.terrain == B_TERRAIN_GRASSY && usesDefStat)
        {
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
            if (ctx->updateFlags)
                RecordAbilityBattle(battlerDef, ABILITY_GRASS_PELT);
        }
        break;
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[battlerDef].species == SPECIES_CHERRIM_SUNSHINE && IsBattlerWeatherAffected(ctx->holdEffects[ctx->battlerDef], ctx->weather, B_WEATHER_SUN) && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case ABILITY_PROTOSYNTHESIS:
        {
            enum Stat defHighestStat = GetParadoxBoostedStatId(battlerDef);
            if (((ctx->weather & B_WEATHER_SUN) || gBattleMons[battlerDef].volatiles.boosterEnergyActivated)
             && ((IsBattleMovePhysical(move) && defHighestStat == STAT_DEF) || (IsBattleMoveSpecial(move) && defHighestStat == STAT_SPDEF))
             && !(gBattleMons[battlerDef].volatiles.transformed))
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        }
        break;
    case ABILITY_QUARK_DRIVE:
        {
            enum Stat defHighestStat = GetParadoxBoostedStatId(battlerDef);
            if ((gFieldTimers.terrain == B_TERRAIN_ELECTRIC || gBattleMons[battlerDef].volatiles.boosterEnergyActivated)
             && ((IsBattleMovePhysical(move) && defHighestStat == STAT_DEF) || (IsBattleMoveSpecial(move) && defHighestStat == STAT_SPDEF))
             && !(gBattleMons[battlerDef].volatiles.transformed))
                modifier = uq4_12_multiply(modifier, UQ_4_12(1.3));
        }
        break;
    default:
        break;
    }

    // ally's abilities
    switch (ctx->abilities[GetPartnerBattler(battlerDef)])
    {
    case ABILITY_FLOWER_GIFT:
        if (gBattleMons[GetPartnerBattler(battlerDef)].species == SPECIES_CHERRIM_SUNSHINE
         && IsBattlerWeatherAffected(ctx->holdEffects[GetPartnerBattler(battlerDef)], ctx->weather, B_WEATHER_SUN) && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    // Ruin field effects
    if (usesDefStat && ctx->abilities[ctx->battlerDef] != ABILITY_SWORD_OF_RUIN && IsRuinStatusActive(VOLATILE_SWORD_OF_RUIN))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.75));

    if (!usesDefStat && ctx->abilities[ctx->battlerDef] != ABILITY_BEADS_OF_RUIN && IsRuinStatusActive(VOLATILE_BEADS_OF_RUIN))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(0.75));

    // target's hold effects
    switch (ctx->holdEffects[ctx->battlerDef])
    {
    case HOLD_EFFECT_DEEP_SEA_SCALE:
        if (gBattleMons[battlerDef].species == SPECIES_CLAMPERL && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_METAL_POWDER:
        if (gBattleMons[battlerDef].species == SPECIES_DITTO && usesDefStat && !(gBattleMons[battlerDef].volatiles.transformed))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
    case HOLD_EFFECT_EVIOLITE:
        {
            enum Species species = gBattleMons[battlerDef].species;
            if (gBattleMons[battlerDef].volatiles.transformed && gBattleMons[battlerDef].volatiles.transformedMonSpecies != SPECIES_NONE)
                species = gBattleMons[battlerDef].volatiles.transformedMonSpecies;
            if (CanEvolve(species))
                modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        }
        break;
    case HOLD_EFFECT_ASSAULT_VEST:
        if (!usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    case HOLD_EFFECT_SOUL_DEW:
        if (B_SOUL_DEW_BOOST < GEN_7
         && (gBattleMons[battlerDef].species == SPECIES_LATIAS || gBattleMons[battlerDef].species == SPECIES_LATIOS)
         && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
         && !usesDefStat)
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
        break;
    default:
        break;
    }

    u32 attackerWeather = GetAttackerWeather(ctx->holdEffects[ctx->battlerAtk], ctx->abilities[ctx->battlerAtk], ctx->weather);
    // sandstorm sp.def boost for rock types
    if (GetConfig(B_SANDSTORM_SPDEF_BOOST) >= GEN_4
	 && attackerWeather & B_WEATHER_SANDSTORM
	 && IS_BATTLER_OF_TYPE(battlerDef, TYPE_ROCK)
	 && !usesDefStat)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));
    // snow def boost for ice types
    if (attackerWeather  & B_WEATHER_SNOW
	 && IS_BATTLER_OF_TYPE(battlerDef, TYPE_ICE)
	 && usesDefStat)
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));

    modifier = ApplyDefensiveBadgeBoost(modifier, battlerDef, move);

    return uq4_12_multiply_by_int_half_down(modifier, defStat);
}

// base damage formula before adding any modifiers
static inline s32 CalculateBaseDamage(u32 power, u32 userFinalAttack, u32 level, u32 targetFinalDefense)
{
    return power * userFinalAttack * (2 * level / 5 + 2) / targetFinalDefense / 50 + 2;
}

static inline uq4_12_t GetTargetDamageModifier(struct DamageContext *ctx)
{
    if (IsDoubleBattle())
    {
        u32 targetCount = GetMoveTargetCount(ctx);
        if (targetCount == 2)
            return B_MULTIPLE_TARGETS_DMG >= GEN_4 ? UQ_4_12(0.75) : UQ_4_12(0.5);
        else if (targetCount >= 3)
            return B_MULTIPLE_TARGETS_DMG >= GEN_4 ? UQ_4_12(0.75) : UQ_4_12(1.0);
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetParentalBondModifier(enum BattlerId battlerAtk)
{
    if (gSpecialStatuses[battlerAtk].parentalBondState != PARENTAL_BOND_2ND_HIT)
        return UQ_4_12(1.0);
    return B_PARENTAL_BOND_DMG >= GEN_7 ? UQ_4_12(0.25) : UQ_4_12(0.5);
}

static inline uq4_12_t GetSameTypeAttackBonusModifier(struct DamageContext *ctx)
{
    bool32 isAdaptability = ctx->abilities[ctx->battlerAtk] == ABILITY_ADAPTABILITY;

    if (IS_BATTLER_OF_TYPE(ctx->battlerAtk, ctx->moveType) && ctx->move != MOVE_STRUGGLE)
        return isAdaptability ? UQ_4_12(2.0) : UQ_4_12(1.5);

    if (gBattleStruct->pledgeState == PLEDGE_COMBO_ATTACK && IS_BATTLER_OF_TYPE(GetPartnerBattler(ctx->battlerAtk), ctx->moveType))
        return isAdaptability ? UQ_4_12(2.0) : UQ_4_12(1.5);

    return UQ_4_12(1.0);
}

// Utility Umbrella holders take normal damage from what would be rain- and sun-weakened attacks.
static uq4_12_t GetWeatherDamageModifier(struct DamageContext *ctx)
{
    u32 attackerWeather = GetAttackerWeather(ctx->holdEffects[ctx->battlerAtk], ctx->abilities[ctx->battlerAtk], ctx->weather);
    if ((attackerWeather | ctx->weather) == B_WEATHER_NONE)
        return UQ_4_12(1.0);// This early exit helps limit AI thinking time
    if (GetMoveEffect(ctx->move) == EFFECT_HYDRO_STEAM && (attackerWeather & B_WEATHER_SUN))
        return UQ_4_12(1.5);
    if (ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_UTILITY_UMBRELLA)
        return UQ_4_12(1.0);

    if (ctx->weather & B_WEATHER_SUN || attackerWeather & B_WEATHER_SUN) // called because utility umbrella is only active on the defender for this calc.
    {
        if (ctx->moveType != TYPE_FIRE && ctx->moveType != TYPE_WATER)
            return UQ_4_12(1.0);
        return (ctx->moveType == TYPE_WATER) ? UQ_4_12(0.5) : UQ_4_12(1.5);
    }

    if (ctx->weather & B_WEATHER_RAIN || attackerWeather & B_WEATHER_RAIN)
    {
        if (ctx->moveType != TYPE_FIRE && ctx->moveType != TYPE_WATER)
            return UQ_4_12(1.0);
        return (ctx->moveType == TYPE_FIRE) ? UQ_4_12(0.5) : UQ_4_12(1.5);
    }

    return UQ_4_12(1.0);
}

static inline uq4_12_t GetBurnOrFrostBiteModifier(struct DamageContext *ctx)
{
    enum BattleMoveEffects moveEffect = GetMoveEffect(ctx->move);

    if (gBattleMons[ctx->battlerAtk].status1 & STATUS1_BURN
        && IsBattleMovePhysical(ctx->move)
        && (GetConfig(B_BURN_FACADE_DMG) < GEN_6 || moveEffect != EFFECT_FACADE)
        && ctx->abilities[ctx->battlerAtk] != ABILITY_GUTS)
        return UQ_4_12(0.5);
    if (gBattleMons[ctx->battlerAtk].status1 & STATUS1_FROSTBITE
        && IsBattleMoveSpecial(ctx->move)
        && (GetConfig(B_BURN_FACADE_DMG) < GEN_6 || moveEffect != EFFECT_FACADE))
        return UQ_4_12(0.5);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetCriticalModifier(bool32 isCrit)
{
    if (isCrit)
        return GetConfig(B_CRIT_MULTIPLIER) >= GEN_6 ? UQ_4_12(1.5) : UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetGlaiveRushModifier(enum BattlerId battlerDef)
{
    if (gBattleMons[battlerDef].volatiles.glaiveRush)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetMoveAgainstProtectionModifier(struct DamageContext *ctx)
{
    if (MoveIgnoresProtect(ctx->move))
        return UQ_4_12(1.0);

    // Unseen Fist and Piercing Drill
    u32 protected = gProtectStructs[ctx->battlerDef].protected;
    if (GetProtectType(protected) == PROTECT_TYPE_SINGLE && protected != PROTECT_MAX_GUARD
         && (ctx->abilities[ctx->battlerAtk] == ABILITY_UNSEEN_FIST || ctx->abilities[ctx->battlerAtk] == ABILITY_PIERCING_DRILL)
         && GetConfig(B_UNSEEN_FIST_PIERCING_DRILL) >= GEN_CHAMPIONS)
        return UQ_4_12(0.25);

    // Z-Moves and Max Moves
    if (!IsZMove(ctx->move) && !IsMaxMove(ctx->move))
        return UQ_4_12(1.0);

    if (GetProtectType(protected) == PROTECT_TYPE_SINGLE && protected != PROTECT_MAX_GUARD)
        return UQ_4_12(0.25);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetMinimizeModifier(enum Move move, enum BattlerId battlerDef)
{
    if (MoveIncreasesPowerToMinimizedTargets(move) && gBattleMons[battlerDef].volatiles.minimize)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetUndergroundModifier(enum Move move, enum BattlerId battlerDef)
{
    if (MoveDamagesUnderground(move) && gBattleMons[battlerDef].volatiles.semiInvulnerable == STATE_UNDERGROUND)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDiveModifier(enum Move move, enum BattlerId battlerDef)
{
    if (MoveDamagesUnderWater(move) && gBattleMons[battlerDef].volatiles.semiInvulnerable == STATE_UNDERWATER)
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAirborneModifier(enum Move move, enum BattlerId battlerDef)
{
    if (MoveDamagesAirborneDoubleDamage(move) && IsBattlerOnAir(battlerDef))
        return UQ_4_12(2.0);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetScreensModifier(struct DamageContext *ctx)
{
    u32 sideStatus = gSideStatuses[GetBattlerSide(ctx->battlerDef)];
    bool32 lightScreen = (sideStatus & SIDE_STATUS_LIGHTSCREEN) && IsBattleMoveSpecial(ctx->move);
    bool32 reflect = (sideStatus & SIDE_STATUS_REFLECT) && IsBattleMovePhysical(ctx->move);
    bool32 auroraVeil = sideStatus & SIDE_STATUS_AURORA_VEIL;

    if (ctx->isCrit || ctx->isSelfInflicted)
    {
        return UQ_4_12(1.0);
    }
    if (ctx->abilities[ctx->battlerAtk] == ABILITY_INFILTRATOR && !IsBattlerAlly(ctx->battlerAtk, ctx->battlerDef))
    {
        if (ctx->updateFlags)
            RecordAbilityBattle(ctx->battlerAtk, ctx->abilities[ctx->battlerAtk]);
        return UQ_4_12(1.0);
    }
    if (reflect || lightScreen || auroraVeil)
    {
        return (IsDoubleBattle()) ? UQ_4_12(0.667) : UQ_4_12(0.5);
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetCollisionCourseElectroDriftModifier(enum Move move, uq4_12_t typeEffectivenessModifier)
{
    if (GetMoveEffect(move) == EFFECT_COLLISION_COURSE && typeEffectivenessModifier >= UQ_4_12(2.0))
        return UQ_4_12(1.3333);
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAttackerAbilitiesModifier(enum BattlerId battlerAtk, uq4_12_t typeEffectivenessModifier, bool32 isCrit, enum Ability abilityAtk)
{
    switch (abilityAtk)
    {
    case ABILITY_NEUROFORCE:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            return UQ_4_12(1.25);
        break;
    case ABILITY_SNIPER:
        if (isCrit)
            return UQ_4_12(1.5);
        break;
    case ABILITY_TINTED_LENS:
        if (typeEffectivenessModifier <= UQ_4_12(0.5))
            return UQ_4_12(2.0);
        break;
    default:
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDefenderAbilitiesModifier(struct DamageContext *ctx)
{
    bool32 recordAbility = FALSE;
    uq4_12_t modifier = UQ_4_12(1.0);

    switch (ctx->abilities[ctx->battlerDef])
    {
    case ABILITY_MULTISCALE:
    case ABILITY_SHADOW_SHIELD:
        if (IsBattlerAtMaxHp(ctx->battlerDef))
        {
            modifier = UQ_4_12(0.5);
            recordAbility = TRUE;
        }
        break;
    case ABILITY_FILTER:
    case ABILITY_SOLID_ROCK:
    case ABILITY_PRISM_ARMOR:
        if (ctx->typeEffectivenessModifier >= UQ_4_12(2.0))
        {
            modifier = UQ_4_12(0.75);
            recordAbility = TRUE;
        }
        break;
    case ABILITY_FLUFFY:
        if (ctx->moveType == TYPE_FIRE && !IsMoveMakingContact(ctx->battlerAtk, ctx->battlerDef, ctx->abilities[ctx->battlerAtk], ctx->holdEffects[ctx->battlerAtk], ctx->move))
        {
            modifier = UQ_4_12(2.0);
            recordAbility = TRUE;
        }
        if (ctx->moveType != TYPE_FIRE && IsMoveMakingContact(ctx->battlerAtk, ctx->battlerDef, ctx->abilities[ctx->battlerAtk], ctx->holdEffects[ctx->battlerAtk], ctx->move))
        {
            modifier = UQ_4_12(0.5);
            recordAbility = TRUE;
        }
        break;
    case ABILITY_PUNK_ROCK:
        if (IsSoundMove(ctx->move))
        {
            modifier = UQ_4_12(0.5);
            recordAbility = TRUE;
        }
        break;
    case ABILITY_ICE_SCALES:
        if (IsBattleMoveSpecial(ctx->move))
        {
            modifier =  UQ_4_12(0.5);
            recordAbility = TRUE;
        }
        break;
    default:
        break;
    }

    if (recordAbility && ctx->updateFlags)
        RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);

    return modifier;
}

static inline uq4_12_t GetDefenderPartnerAbilitiesModifier(struct DamageContext *ctx)
{
    enum BattlerId battlerDefPartner = GetPartnerBattler(ctx->battlerDef);
    if (!IsBattlerAlive(battlerDefPartner))
        return UQ_4_12(1.0);

    switch (ctx->abilities[battlerDefPartner])
    {
    case ABILITY_FRIEND_GUARD:
    {
        if (ctx->battlerAtk != ctx->battlerDef) // Friend Guard doesn't reduce Confusion damage
            return UQ_4_12(0.75);
        break;
    }
    default:
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetAttackerItemsModifier(enum BattlerId battlerAtk, uq4_12_t typeEffectivenessModifier, enum HoldEffect holdEffectAtk)
{
    u32 metronomeTurns;
    uq4_12_t metronomeBoostBase;
    switch (holdEffectAtk)
    {
    case HOLD_EFFECT_METRONOME:
        metronomeBoostBase = PercentToUQ4_12(GetBattlerHoldEffectParam(battlerAtk));
        metronomeTurns = min(gBattleMons[battlerAtk].volatiles.metronomeItemCounter, 5);
        // according to bulbapedia this is the "correct" way to calculate the metronome boost
        // due to the limited domain of damage numbers it will never really matter whether this is off by one
        return uq4_12_add(UQ_4_12(1.0), metronomeBoostBase * metronomeTurns);
        break;
    case HOLD_EFFECT_EXPERT_BELT:
        if (typeEffectivenessModifier >= UQ_4_12(2.0))
            return UQ_4_12(1.2);
        break;
    case HOLD_EFFECT_LIFE_ORB:
        return UQ_4_12_FLOORED(1.3);
        break;
    default:
        break;
    }
    return UQ_4_12(1.0);
}

static inline uq4_12_t GetDefenderItemsModifier(struct DamageContext *ctx)
{
    switch (ctx->holdEffects[ctx->battlerDef])
    {
    case HOLD_EFFECT_RESIST_BERRY:
        if (IsUnnerveBlocked(ctx->battlerDef, gBattleMons[ctx->battlerDef].item))
            return UQ_4_12(1.0);
        if (ctx->moveType == GetBattlerHoldEffectParam(ctx->battlerDef) && (ctx->moveType == TYPE_NORMAL || ctx->typeEffectivenessModifier >= UQ_4_12(2.0)))
        {
            if (ctx->updateFlags)
                gSpecialStatuses[ctx->battlerDef].berryReduced = TRUE;
            if (ctx->aiCalc && AI_DAMAGES_THROUGH_BERRIES)
                ctx->aiCheckBerryModifier = TRUE;
            return (ctx->abilities[ctx->battlerDef] == ABILITY_RIPEN) ? UQ_4_12(0.25) : UQ_4_12(0.5);
        }
        break;
    default:
        break;
    }
    return UQ_4_12(1.0);
}

#define DAMAGE_MULTIPLY_MODIFIER(modifier) do {                     \
    finalModifier = uq4_12_multiply_half_down(modifier, finalModifier); \
} while (0)

// Calculates the "other" modifier which accounts for held items, abilities,
// or very specific interactions of moves that are not handled in the basic
// damage calculation. It is implemented as described by bulbapedia:
// https://bulbapedia.bulbagarden.net/wiki/Damage#Generation_V_onward
// Please Note: Fixed Point Multiplication is not associative.
// The order of operations is relevant.
static inline uq4_12_t GetOtherModifiers(struct DamageContext *ctx)
{
    uq4_12_t finalModifier = UQ_4_12(1.0);
    u32 unmodifiedAttackerSpeed = gBattleMons[ctx->battlerAtk].speed;
    u32 unmodifiedDefenderSpeed = gBattleMons[ctx->battlerDef].speed;

    //TODO: Behemoth Blade, Behemoth Bash, Dynamax Cannon (Dynamax)
    DAMAGE_MULTIPLY_MODIFIER(GetMinimizeModifier(ctx->move, ctx->battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetUndergroundModifier(ctx->move, ctx->battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetDiveModifier(ctx->move, ctx->battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetAirborneModifier(ctx->move, ctx->battlerDef));
    DAMAGE_MULTIPLY_MODIFIER(GetScreensModifier(ctx));
    DAMAGE_MULTIPLY_MODIFIER(GetCollisionCourseElectroDriftModifier(ctx->move, ctx->typeEffectivenessModifier));

    if (unmodifiedAttackerSpeed >= unmodifiedDefenderSpeed)
    {
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(ctx->battlerAtk, ctx->typeEffectivenessModifier, ctx->isCrit, ctx->abilities[ctx->battlerAtk]));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(ctx));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderPartnerAbilitiesModifier(ctx));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(ctx->battlerAtk, ctx->typeEffectivenessModifier, ctx->holdEffects[ctx->battlerAtk]));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(ctx));
    }
    else
    {
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderAbilitiesModifier(ctx));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderPartnerAbilitiesModifier(ctx));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerAbilitiesModifier(ctx->battlerAtk, ctx->typeEffectivenessModifier, ctx->isCrit, ctx->abilities[ctx->battlerAtk]));
        DAMAGE_MULTIPLY_MODIFIER(GetDefenderItemsModifier(ctx));
        DAMAGE_MULTIPLY_MODIFIER(GetAttackerItemsModifier(ctx->battlerAtk, ctx->typeEffectivenessModifier, ctx->holdEffects[ctx->battlerAtk]));
    }
    return finalModifier;
}

#undef DAMAGE_ACCUMULATE_MULTIPLIER

#define DAMAGE_APPLY_MODIFIER(modifier) do {               \
    dmg = uq4_12_multiply_by_int_half_down(modifier, dmg); \
} while (0)

static inline s32 DoMoveDamageCalcVars(struct DamageContext *ctx)
{
    s32 dmg;
    u32 userFinalAttack;
    u32 targetFinalDefense;

    if (ctx->fixedBasePower)
        gBattleMovePower = ctx->fixedBasePower;
    else
        gBattleMovePower = CalcMoveBasePowerAfterModifiers(ctx);

    userFinalAttack = CalcAttackStat(ctx);
    targetFinalDefense = CalcDefenseStat(ctx);

    dmg = CalculateBaseDamage(gBattleMovePower, userFinalAttack, gBattleMons[ctx->battlerAtk].level, targetFinalDefense);
    DAMAGE_APPLY_MODIFIER(GetTargetDamageModifier(ctx));
    DAMAGE_APPLY_MODIFIER(GetParentalBondModifier(ctx->battlerAtk));
    DAMAGE_APPLY_MODIFIER(GetWeatherDamageModifier(ctx));
    DAMAGE_APPLY_MODIFIER(GetCriticalModifier(ctx->isCrit));
    DAMAGE_APPLY_MODIFIER(GetGlaiveRushModifier(ctx->battlerDef));

    if (ctx->randomFactor)
    {
        dmg *= DMG_ROLL_PERCENT_HI - RandomUniform(RNG_DAMAGE_MODIFIER, 0, DMG_ROLL_PERCENT_HI - DMG_ROLL_PERCENT_LO);
        dmg /= 100;
    }
    else // Apply rest of modifiers in the ai function
    {
        if (dmg == 0)
            dmg = 1;
        return dmg;
    }

    dmg = ApplyModifiersAfterDmgRoll(ctx, dmg);

    if (dmg == 0)
        dmg = 1;
    return dmg;
}

s32 ApplyModifiersAfterDmgRoll(struct DamageContext *ctx, s32 dmg)
{
    if (GetActiveGimmick(ctx->battlerAtk) == GIMMICK_TERA)
        DAMAGE_APPLY_MODIFIER(GetTeraMultiplier(ctx));
    else
        DAMAGE_APPLY_MODIFIER(GetSameTypeAttackBonusModifier(ctx));
    DAMAGE_APPLY_MODIFIER(ctx->typeEffectivenessModifier);
    DAMAGE_APPLY_MODIFIER(GetBurnOrFrostBiteModifier(ctx));
    DAMAGE_APPLY_MODIFIER(GetMoveAgainstProtectionModifier(ctx));
    DAMAGE_APPLY_MODIFIER(GetOtherModifiers(ctx));

    return dmg;
}

s32 DoFixedDamageMoveCalc(struct DamageContext *ctx)
{
    s32 dmg = INT32_MAX;
    s32 randDamage;

    switch (GetMoveEffect(ctx->move))
    {
    case EFFECT_LEVEL_DAMAGE:
        dmg = gBattleMons[ctx->battlerAtk].level;
        break;
    case EFFECT_PSYWAVE:
        if (B_PSYWAVE_DMG >= GEN_5)
        {
            randDamage = Random() % 101;
            dmg = gBattleMons[ctx->battlerAtk].level * (randDamage + 50) / 100;
        }
        else if (B_PSYWAVE_DMG >= GEN_3)
        {
            randDamage = Random() % 11;
            dmg = gBattleMons[ctx->battlerAtk].level * ((randDamage * 10) + 50) / 100;
        }
        else
        {
            dmg = Random() % ((gBattleMons[ctx->battlerAtk].level + (gBattleMons[ctx->battlerAtk].level / 2)) + 1);
        }
        break;
    case EFFECT_FIXED_HP_DAMAGE:
        dmg = GetMoveFixedHPDamage(ctx->move);
        break;
    case EFFECT_FIXED_PERCENT_DAMAGE:
        dmg = GetNonDynamaxHP(ctx->battlerDef) * GetMoveDamagePercentage(ctx->move) / 100;
        break;
    case EFFECT_FINAL_GAMBIT:
        dmg = GetNonDynamaxHP(ctx->battlerAtk);
        break;
    case EFFECT_BEAT_UP:
        if (GetConfig(B_BEAT_UP) < GEN_5)
            dmg = CalcBeatUpDamage(ctx);
        break;
    case EFFECT_REFLECT_DAMAGE:
        if (!ctx->aiCalc)
        {
            u32 percentMultiplier = GetMoveReflectDamage_DamagePercent(ctx->move);
            enum DamageCategory reflectCategory = GetReflectDamageMoveDamageCategory(ctx->battlerAtk, ctx->move);
            s32 baseDamage;

            if (reflectCategory == DAMAGE_CATEGORY_PHYSICAL)
                baseDamage = gProtectStructs[ctx->battlerAtk].physicalDmg;
            else
                baseDamage = gProtectStructs[ctx->battlerAtk].specialDmg;

            dmg = (baseDamage - 1) * percentMultiplier / 100;
        }
        break;
    case EFFECT_ENDEAVOR:
        if (GetNonDynamaxHP(ctx->battlerDef) <= gBattleMons[ctx->battlerAtk].hp) // for accurate ai calcs but otherwise failure is handled prior
        {
            dmg = 0;
        }
        else
        {
            dmg = GetNonDynamaxHP(ctx->battlerDef) - gBattleMons[ctx->battlerAtk].hp;
        }
        break;
    case EFFECT_OHKO:
        dmg = gBattleMons[ctx->battlerDef].hp;
        break;
    case EFFECT_BIDE:
        dmg = gBideDmg[ctx->battlerAtk] * 2;
        break;
    default:
        break;
    }

    if (dmg == INT32_MAX)
        return dmg;

    gBattleStruct->moveResultFlags[ctx->battlerDef] &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE);
    gSpecialStatuses[ctx->battlerDef].criticalHit = FALSE;

    if (dmg == 0)
        dmg = 1;

    return dmg;
}

static inline s32 DoMoveDamageCalc(struct DamageContext *ctx)
{
    if (ctx->useStoredTypeEffectiveness)
        ctx->typeEffectivenessModifier = gSpecialStatuses[ctx->battlerDef].storedTypeEffectiveness;
    else
        ctx->typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(ctx);

    if (ctx->typeEffectivenessModifier == UQ_4_12(0.0))
        return 0;

    s32 dmg = DoFixedDamageMoveCalc(ctx);
    if (dmg != INT32_MAX)
        return dmg;

    ctx->isCrit = IsCriticalHit(ctx);
    return DoMoveDamageCalcVars(ctx);
}

static inline s32 DoFutureSightAttackDamageCalc(struct DamageContext *ctx)
{
    struct Pokemon *party = GetBattlerParty(ctx->battlerAtk);
    struct Pokemon *partyMon = &party[gBattleStruct->futureSight[ctx->battlerDef].partyIndex];
    struct BattlePokemon *savedBattleMons = AllocSaveBattleMons();

    bool32 vesselOrRuin = gBattleMons[ctx->battlerAtk].volatiles.vesselOfRuin;
    bool32 tabletsOfRuin = gBattleMons[ctx->battlerAtk].volatiles.tabletsOfRuin;
    bool32 swordOfRuin = gBattleMons[ctx->battlerAtk].volatiles.swordOfRuin;
    bool32 beadsOfRuin = gBattleMons[ctx->battlerAtk].volatiles.beadsOfRuin;

    PokemonToBattleMon(partyMon , &gBattleMons[ctx->battlerAtk]);

    gBattleMons[ctx->battlerAtk].volatiles.vesselOfRuin = vesselOrRuin;
    gBattleMons[ctx->battlerAtk].volatiles.tabletsOfRuin = tabletsOfRuin;
    gBattleMons[ctx->battlerAtk].volatiles.swordOfRuin = swordOfRuin;
    gBattleMons[ctx->battlerAtk].volatiles.beadsOfRuin = beadsOfRuin;

    ctx->abilities[ctx->battlerAtk] = ABILITY_NONE;
    ctx->holdEffects[ctx->battlerAtk] = HOLD_EFFECT_NONE;
    ctx->typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(ctx);
    ctx->isCrit = IsCriticalHit(ctx);

    if (ctx->typeEffectivenessModifier == UQ_4_12(0.0))
	{
		FreeRestoreBattleMons(savedBattleMons);
        return 0;
	}

    s32 dmg = DoMoveDamageCalc(ctx);

    FreeRestoreBattleMons(savedBattleMons);
    return dmg;
}

#undef DAMAGE_APPLY_MODIFIER

// The chance is 1/N for each stage.
static const u32 sGen7CriticalHitOdds[] = {24,  8,  2,  1,   1}; // 1/X
static const u32 sGen6CriticalHitOdds[] = {16,  8,  2,  1,   1}; // 1/X
static const u32 sCriticalHitOdds[]     = {16,  8,  4,  3,   2}; // 1/X, Gens 3,4,5
static const u32 sGen2CriticalHitOdds[] = {17, 32, 64, 85, 128}; // X/256

u32 GetCriticalHitOdds(u32 critChance)
{
    if (GetConfig(B_CRIT_CHANCE) >= GEN_7)
        return sGen7CriticalHitOdds[critChance];
    if (GetConfig(B_CRIT_CHANCE) == GEN_6)
        return sGen6CriticalHitOdds[critChance];
    if (GetConfig(B_CRIT_CHANCE) == GEN_2)
        return sGen2CriticalHitOdds[critChance];

    return sCriticalHitOdds[critChance];
}

static inline bool32 IsBattlerLeekAffected(enum BattlerId battler, enum HoldEffect holdEffect)
{
    if (holdEffect == HOLD_EFFECT_LEEK)
    {
        return GET_BASE_SPECIES_ID(gBattleMons[battler].species) == SPECIES_FARFETCHD
            || gBattleMons[battler].species == SPECIES_SIRFETCHD;
    }
    return FALSE;
}

static inline u32 GetHoldEffectCritChanceIncrease(enum BattlerId battler, enum HoldEffect holdEffect)
{
    u32 critStageIncrease = 0;

    switch (holdEffect)
    {
    case HOLD_EFFECT_SCOPE_LENS:
        critStageIncrease = 1;
        break;
    case HOLD_EFFECT_LUCKY_PUNCH:
        if (gBattleMons[battler].species == SPECIES_CHANSEY)
            critStageIncrease = 2;
        break;
    case HOLD_EFFECT_LEEK:
        if (IsBattlerLeekAffected(battler, holdEffect))
            critStageIncrease = 2;
        break;
    default:
        critStageIncrease = 0;
        break;
    }

    return critStageIncrease;
}

s32 CalcCritChanceStage(struct DamageContext *ctx)
{
    s32 critChance = 0;

    if (gSideStatuses[GetBattlerSide(ctx->battlerDef)] & SIDE_STATUS_LUCKY_CHANT)
    {
        critChance = CRITICAL_HIT_BLOCKED;
    }
    else if (gBattleMons[ctx->battlerAtk].volatiles.laserFocusTimer > 0
          || MoveAlwaysCrits(ctx->move)
          || (ctx->abilities[ctx->battlerAtk] == ABILITY_MERCILESS && gBattleMons[ctx->battlerDef].status1 & STATUS1_PSN_ANY))
    {
        critChance = CRITICAL_HIT_ALWAYS;
    }
    else
    {
        critChance  = (gBattleMons[ctx->battlerAtk].volatiles.focusEnergy != 0 ? 2 : 0)
                    + (gBattleMons[ctx->battlerAtk].volatiles.dragonCheer != 0 ? 1 : 0)
                    + GetMoveCriticalHitStage(ctx->move)
                    + GetHoldEffectCritChanceIncrease(ctx->battlerAtk, ctx->holdEffects[ctx->battlerAtk])
                    + ((B_AFFECTION_MECHANICS == TRUE && GetBattlerAffectionHearts(ctx->battlerAtk) == AFFECTION_FIVE_HEARTS) ? 2 : 0)
                    + (ctx->abilities[ctx->battlerAtk] == ABILITY_SUPER_LUCK ? 1 : 0)
                    + gBattleMons[ctx->battlerAtk].volatiles.bonusCritStages;

        if (critChance >= ARRAY_COUNT(sCriticalHitOdds))
            critChance = ARRAY_COUNT(sCriticalHitOdds) - 1;
    }

    if (critChance != CRITICAL_HIT_BLOCKED && (ctx->abilities[ctx->battlerDef] == ABILITY_BATTLE_ARMOR || ctx->abilities[ctx->battlerDef] == ABILITY_SHELL_ARMOR))
    {
        // Record ability only if move had 100% chance to get a crit
        if (ctx->updateFlags)
        {
            if (critChance == CRITICAL_HIT_ALWAYS)
                RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);
            else if (GetCriticalHitOdds(critChance) == 1)
                RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);
        }
        critChance = CRITICAL_HIT_BLOCKED;
    }

    return critChance;
}

// Bulbapedia: https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Generation_I
// Crit chance = Threshold / 256, Threshold maximum of 255
// Threshold = Base Speed / 2
// High crit move = 8 * (Base Speed / 2)
// Focus Energy = 4 * (Base Speed / 2)
s32 CalcCritChanceStageGen1(struct DamageContext *ctx)
{
    s32 critChance = 0;
    s32 moveCritStage = GetMoveCriticalHitStage(ctx->move);
    s32 bonusCritStage = gBattleMons[ctx->battlerAtk].volatiles.bonusCritStages; // G-Max Chi Strike
    u32 holdEffectCritStage = GetHoldEffectCritChanceIncrease(ctx->battlerAtk, ctx->holdEffects[ctx->battlerAtk]);
    u16 baseSpeed = GetSpeciesBaseSpeed(gBattleMons[ctx->battlerAtk].species);

    critChance = baseSpeed / 2;

    // Crit scaling
    if (moveCritStage > 0)
        critChance *= 8 * moveCritStage;

    if (bonusCritStage > 0)
        critChance *= bonusCritStage;

    if (gBattleMons[ctx->battlerAtk].volatiles.focusEnergy)
        critChance *= 4;
    else if (gBattleMons[ctx->battlerAtk].volatiles.dragonCheer)
        critChance *= 2;

    if (holdEffectCritStage > 0)
        critChance *= 4 * holdEffectCritStage;

    if (ctx->abilities[ctx->battlerAtk] == ABILITY_SUPER_LUCK)
        critChance *= 4;

    if (critChance > 255)
        critChance = 255;

    if (ctx->abilities[ctx->battlerDef] == ABILITY_BATTLE_ARMOR || ctx->abilities[ctx->battlerDef] == ABILITY_SHELL_ARMOR)
    {
        if (ctx->updateFlags)
            RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);
        critChance = CRITICAL_HIT_BLOCKED;
    }
    else if (gBattleMons[ctx->battlerAtk].volatiles.laserFocusTimer > 0
          || MoveAlwaysCrits(ctx->move)
          || (ctx->abilities[ctx->battlerAtk] == ABILITY_MERCILESS && gBattleMons[ctx->battlerDef].status1 & STATUS1_PSN_ANY))
    {
        critChance = CRITICAL_HIT_ALWAYS;
    }

    return critChance;
}

static bool32 IsCriticalHit(struct DamageContext *ctx)
{

    if ((gBattleTypeFlags & (BATTLE_TYPE_CATCH_TUTORIAL | BATTLE_TYPE_POKEDUDE))
    || ((gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE) && (!IS_FRLG || !BtlCtrl_OakOldMan_TestState2Flag(1))))
        return FALSE;
    if (ctx->isSelfInflicted)
        return FALSE;
    if (gSideStatuses[GetBattlerSide(ctx->battlerDef)] & SIDE_STATUS_LUCKY_CHANT)
        return FALSE;

    bool32 isCrit = FALSE;
    s32 critChance = 0;

    if (GetConfig(B_CRIT_CHANCE) == GEN_1)
        critChance = CalcCritChanceStageGen1(ctx);
    else
        critChance = CalcCritChanceStage(ctx);

    if (critChance == CRITICAL_HIT_BLOCKED)
        isCrit = FALSE;
    else if (critChance == CRITICAL_HIT_ALWAYS)
        isCrit = TRUE;
    else if (GetConfig(B_CRIT_CHANCE) == GEN_1)
        isCrit = RandomChance(RNG_CRITICAL_HIT, critChance, 256);
    else if (GetConfig(B_CRIT_CHANCE) == GEN_2)
        isCrit = RandomChance(RNG_CRITICAL_HIT, GetCriticalHitOdds(critChance), 256);
    else
        isCrit = RandomChance(RNG_CRITICAL_HIT, 1, GetCriticalHitOdds(critChance));

    // Counter for IF_CRITICAL_HITS_GE evolution condition.
    if (isCrit && IsOnPlayerSide(ctx->battlerAtk)
     && !(gBattleTypeFlags & BATTLE_TYPE_MULTI && GetBattlerPosition(ctx->battlerAtk) == B_POSITION_PLAYER_LEFT))
        gPartyCriticalHits[gBattlerPartyIndexes[ctx->battlerAtk]]++;

    gSpecialStatuses[ctx->battlerDef].criticalHit = isCrit;
    return isCrit;
}

s32 GetAdjustedDamage(struct DamageContext *ctx, s32 damage)
{
    if (DoesSubstituteBlockMove(ctx->battlerAtk, ctx->battlerDef, ctx->move)
     || DoesDisguiseBlockMove(ctx->battlerDef, ctx->move)
     || DoesIceFaceBlockMove(ctx->battlerDef, ctx->move))
        return damage; // No damage will be dealt

    if (gBattleMons[ctx->battlerDef].hp > damage)
        return damage;

    bool32 enduredHit = FALSE;
    u32 rand = Random() % 100;
    u32 affectionScore = GetBattlerAffectionHearts(ctx->battlerDef);

    if (gBattleMons[ctx->battlerDef].volatiles.endured)
    {
        enduredHit = TRUE;
        gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_FOE_ENDURED;
    }
    else if (GetMoveEffect(ctx->move) == EFFECT_FALSE_SWIPE)
    {
        enduredHit = TRUE;
    }
    else if (GetConfig(B_STURDY) >= GEN_5 && ctx->abilities[ctx->battlerDef] == ABILITY_STURDY && IsBattlerAtMaxHp(ctx->battlerDef))
    {
        enduredHit = TRUE;
        RecordAbilityBattle(ctx->battlerDef, ABILITY_STURDY);
        gLastUsedAbility = ABILITY_STURDY;
        gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_STURDIED;
    }
    else if (ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_FOCUS_BAND && rand < GetBattlerHoldEffectParam(ctx->battlerDef))
    {
        enduredHit = TRUE;
        RecordItemEffectBattle(ctx->battlerDef, ctx->holdEffects[ctx->battlerDef]);
        gLastUsedItem = gBattleMons[ctx->battlerDef].item;
        gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_FOE_HUNG_ON;
    }
    else if (ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_FOCUS_SASH && IsBattlerAtMaxHp(ctx->battlerDef))
    {
        enduredHit = TRUE;
        RecordItemEffectBattle(ctx->battlerDef, ctx->holdEffects[ctx->battlerDef]);
        gLastUsedItem = gBattleMons[ctx->battlerDef].item;
        gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_FOE_HUNG_ON;
    }
    else if (B_AFFECTION_MECHANICS == TRUE && IsOnPlayerSide(ctx->battlerDef) && affectionScore >= AFFECTION_THREE_HEARTS)
    {
        if ((affectionScore == AFFECTION_FIVE_HEARTS && rand < 20)
         || (affectionScore == AFFECTION_FOUR_HEARTS && rand < 15)
         || (affectionScore == AFFECTION_THREE_HEARTS && rand < 10))
        {
            enduredHit = TRUE;
            gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_FOE_ENDURED_AFFECTION;
        }
    }

    if (enduredHit)
    {
        damage = gBattleMons[ctx->battlerDef].hp - 1; // Reduce damage to 1 hp.
        gProtectStructs[ctx->battlerDef].assuranceDoubled = TRUE;
    }

    return damage;
}

s32 CalculateMoveDamage(struct DamageContext *ctx)
{
    s32 damage = 0;

    if (gSpecialStatuses[ctx->battlerAtk].attackerInParty)
        damage = DoFutureSightAttackDamageCalc(ctx);
    else
        damage = DoMoveDamageCalc(ctx);

    return GetAdjustedDamage(ctx, damage);
}

// for AI so that typeEffectivenessModifier, weather, abilities and holdEffects are calculated only once
s32 CalculateMoveDamageVars(struct DamageContext *ctx)
{
    return DoMoveDamageCalcVars(ctx);
}

static inline void MulByTypeEffectiveness(struct DamageContext *ctx, uq4_12_t *modifier, enum Type defType)
{
    uq4_12_t mod = GetTypeModifier(ctx->moveType, defType);

    if (mod == UQ_4_12(0.0) && ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_RING_TARGET)
    {
        mod = UQ_4_12(1.0);
        if (ctx->updateFlags)
            RecordItemEffectBattle(ctx->battlerDef, HOLD_EFFECT_RING_TARGET);
    }
    else if ((ctx->moveType == TYPE_FIGHTING || ctx->moveType == TYPE_NORMAL) && defType == TYPE_GHOST && gBattleMons[ctx->battlerDef].volatiles.foresight && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
    }
    else if ((ctx->moveType == TYPE_FIGHTING || ctx->moveType == TYPE_NORMAL) && defType == TYPE_GHOST
        && (ctx->abilities[ctx->battlerAtk] == ABILITY_SCRAPPY || ctx->abilities[ctx->battlerAtk] == ABILITY_MINDS_EYE)
        && mod == UQ_4_12(0.0))
    {
        mod = UQ_4_12(1.0);
        if (ctx->updateFlags)
            RecordAbilityBattle(ctx->battlerAtk, ctx->abilities[ctx->battlerAtk]);
    }

    if (ctx->moveType == TYPE_PSYCHIC && defType == TYPE_DARK && gBattleMons[ctx->battlerDef].volatiles.miracleEye && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if (GetMoveEffect(ctx->move) == EFFECT_SUPER_EFFECTIVE_ON_ARG && defType == GetMoveArgType(ctx->move) && !ctx->isAnticipation)
        mod = UQ_4_12(2.0);
    if (ctx->moveType == TYPE_GROUND && defType == TYPE_FLYING && IsBattlerGrounded(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef]) && mod == UQ_4_12(0.0))
        mod = UQ_4_12(1.0);
    if (ctx->moveType == TYPE_STELLAR && GetActiveGimmick(ctx->battlerDef) == GIMMICK_TERA)
        mod = UQ_4_12(2.0);

    // B_WEATHER_STRONG_WINDS weakens Super Effective moves against Flying-type Pokémon
    if (ctx->weather & B_WEATHER_STRONG_WINDS && !ctx->isAnticipation)
    {
        if (defType == TYPE_FLYING && mod >= UQ_4_12(2.0))
            mod = UQ_4_12(1.0);
    }

    if (mod > UQ_4_12(0.0) && ShouldTeraShellDistortTypeMatchups(ctx))
    {
        mod = UQ_4_12(0.5);
        if (ctx->updateFlags)
        {
            gSpecialStatuses[ctx->battlerDef].teraShellAbilityDone = TRUE;
            RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);
        }
    }

    *modifier = uq4_12_multiply(*modifier, mod);
}

static inline void TryNoticeIllusionInTypeEffectiveness(struct DamageContext *ctx, uq4_12_t resultingModifier, enum Species illusionSpecies)
{
    // Check if the type effectiveness would've been different if the Pokémon really had the types as the disguise.
    uq4_12_t presumedModifier = UQ_4_12(1.0);

    struct DamageContext illusionContext = *ctx;

    illusionContext.abilities[illusionContext.battlerDef] = ABILITY_ILLUSION;
    illusionContext.typeEffectivenessModifier = presumedModifier;

    MulByTypeEffectiveness(&illusionContext, &presumedModifier, GetSpeciesType(illusionSpecies, 0));
    if (GetSpeciesType(illusionSpecies, 1) != GetSpeciesType(illusionSpecies, 0))
        MulByTypeEffectiveness(&illusionContext, &presumedModifier, GetSpeciesType(illusionSpecies, 1));

    if (presumedModifier != resultingModifier)
        RecordAbilityBattle(illusionContext.battlerDef, ABILITY_ILLUSION);
}

void UpdateMoveResultFlags(uq4_12_t modifier, u32 *resultFlags)
{
    if (modifier == UQ_4_12(0.0))
    {
        *resultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        *resultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE);
        gBattleStruct->blunderPolicy = FALSE; // Don't activate if missed
    }
    else if (modifier == UQ_4_12(1.0))
    {
        *resultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modifier > UQ_4_12(2.0))
    {
        *resultFlags |= MOVE_RESULT_EXTREMELY_EFFECTIVE;
        *resultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modifier > UQ_4_12(1.0))
    {
        *resultFlags |= MOVE_RESULT_SUPER_EFFECTIVE;
        *resultFlags &= ~(MOVE_RESULT_EXTREMELY_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else if (modifier < UQ_4_12(0.5))
    {
        *resultFlags |= MOVE_RESULT_MOSTLY_INEFFECTIVE;
        *resultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
    else
    {
        *resultFlags |= MOVE_RESULT_NOT_VERY_EFFECTIVE;
        *resultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_EXTREMELY_EFFECTIVE | MOVE_RESULT_MOSTLY_INEFFECTIVE | MOVE_RESULT_DOESNT_AFFECT_FOE);
    }
}

static inline uq4_12_t CalcTypeEffectivenessMultiplierInternal(struct DamageContext *ctx, uq4_12_t modifier)
{
    enum Species illusionSpecies;
    enum Type types[3];
    GetBattlerTypes(ctx->battlerDef, FALSE, types);

    MulByTypeEffectiveness(ctx, &modifier, types[0]);
    if (types[1] != types[0])
        MulByTypeEffectiveness(ctx, &modifier, types[1]);
    if (types[2] != TYPE_MYSTERY && types[2] != types[1] && types[2] != types[0])
        MulByTypeEffectiveness(ctx, &modifier, types[2]);
    if (ctx->moveType == TYPE_FIRE && gBattleMons[ctx->battlerDef].volatiles.tarShot)
        modifier = uq4_12_multiply(modifier, UQ_4_12(2.0));

    if (ctx->updateFlags && (illusionSpecies = GetIllusionMonSpecies(ctx->battlerDef)))
        TryNoticeIllusionInTypeEffectiveness(ctx, modifier, illusionSpecies);

    bool32 isPresentHealing = GetMoveEffect(ctx->move) == EFFECT_PRESENT && gBattleStruct->presentBasePower == 0;
    bool32 ignoreTypeCalc = isPresentHealing || IsBattleMoveStatus(ctx->move);
    if (ignoreTypeCalc && ctx->move != MOVE_THUNDER_WAVE)
    {
        modifier = UQ_4_12(1.0);
        if (B_GLARE_GHOST < GEN_4 && ctx->move == MOVE_GLARE && IS_BATTLER_OF_TYPE(ctx->battlerDef, TYPE_GHOST))
            modifier = UQ_4_12(0.0);
    }
    else if (ctx->moveType == TYPE_GROUND
        && !IsBattlerGroundedInverseCheck(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef], INVERSE_BATTLE, ctx->isAnticipation)
        && !(MoveIgnoresTypeIfFlyingAndUngrounded(ctx->move))
        && !(ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_RING_TARGET && IS_BATTLER_OF_TYPE(ctx->battlerDef, TYPE_FLYING) && !IsBattlerUngroundedByAbilityItemOrEffect(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef])))
    {
        modifier = UQ_4_12(0.0);
        if (ctx->updateFlags && (ctx->abilities[ctx->battlerDef] == ABILITY_LEVITATE || ctx->abilities[ctx->battlerDef] == ABILITY_EELEVATE))
        {
            gBattleStruct->moveResultFlags[ctx->battlerDef] |= (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE);
            gLastUsedAbility = ctx->abilities[ctx->battlerDef];
            ctx->abilityBlocked = TRUE;
            RecordAbilityBattle(ctx->battlerDef, ctx->abilities[ctx->battlerDef]);
        }
        else if (ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_AIR_BALLOON)
        {
            ctx->airBalloonBlocked = TRUE;
        }
    }
    else if (MoveHasNoEffectOnSameType(ctx->move) && IS_BATTLER_OF_TYPE(ctx->battlerDef, GetMoveType(ctx->move)))
    {
        modifier = UQ_4_12(0.0);
    }

    // Thousand Arrows ignores type modifiers for flying mons
    if (MoveIgnoresTypeIfFlyingAndUngrounded(ctx->move)
     && !IsBattlerGrounded(ctx->battlerDef, ctx->abilities[ctx->battlerDef], ctx->holdEffects[ctx->battlerDef])
     && IS_BATTLER_OF_TYPE(ctx->battlerDef, TYPE_FLYING))
    {
        modifier = UQ_4_12(1.0);
    }

    // Iron Ball ignores type modifiers for flying-type mons if it is the only source of grounding
    if (GetConfig(B_IRON_BALL) >= GEN_5
        && ctx->moveType == TYPE_GROUND
        && ctx->holdEffects[ctx->battlerDef] == HOLD_EFFECT_IRON_BALL
        && IS_BATTLER_OF_TYPE(ctx->battlerDef, TYPE_FLYING)
        && !IsBattlerGrounded(ctx->battlerDef, ctx->abilities[ctx->battlerDef], HOLD_EFFECT_NONE) // We want to ignore Iron Ball so skip item check
        && !FlagGet(B_FLAG_INVERSE_BATTLE))
    {
        modifier = UQ_4_12(1.0);
    }

    if (((ctx->abilities[ctx->battlerDef] == ABILITY_WONDER_GUARD && modifier <= UQ_4_12(1.0) && !isPresentHealing)
        || (ctx->abilities[ctx->battlerDef] == ABILITY_TELEPATHY && ctx->battlerDef == GetPartnerBattler(ctx->battlerAtk)))
        && GetMovePower(ctx->move) != 0)
    {
        modifier = UQ_4_12(0.0);
        ctx->abilityBlocked = TRUE;
        if (ctx->updateFlags)
        {
            gLastUsedAbility = ctx->abilities[ctx->battlerDef];
            gBattleStruct->moveResultFlags[ctx->battlerDef] |= MOVE_RESULT_MISSED;
            RecordAbilityBattle(ctx->battlerDef, gBattleMons[ctx->battlerDef].ability);
        }
    }

    if (ctx->updateFlags)
        TryInitializeFirstSTABMoveTrainerSlide(ctx->battlerDef, ctx->battlerAtk, ctx->moveType);

    return modifier;
}

uq4_12_t CalcTypeEffectivenessMultiplier(struct DamageContext *ctx)
{
    uq4_12_t modifier = UQ_4_12(1.0);

    if (ctx->move != MOVE_STRUGGLE && ctx->moveType != TYPE_MYSTERY)
    {
        modifier = CalcTypeEffectivenessMultiplierInternal(ctx, modifier);
        if (GetMoveEffect(ctx->move) == EFFECT_TWO_TYPED_MOVE && !ctx->isAnticipation)
        {
            enum Type primaryType = ctx->moveType;

            ctx->moveType = GetMoveArgType(ctx->move);
            modifier = CalcTypeEffectivenessMultiplierInternal(ctx, modifier);
            ctx->moveType = primaryType;
        }
    }

    if (ctx->updateFlags)
        UpdateMoveResultFlags(modifier, &gBattleStruct->moveResultFlags[ctx->battlerDef]);
    return modifier;
}

uq4_12_t CalcPartyMonTypeEffectivenessMultiplier(enum Move move, enum Species speciesDef, enum Ability abilityDef)
{
    uq4_12_t modifier = UQ_4_12(1.0);
    enum Type moveType = GetBattleMoveType(move);

    if (move != MOVE_STRUGGLE && moveType != TYPE_MYSTERY)
    {
        struct DamageContext ctx = {0};
        ctx.move = ctx.chosenMove = ctx.baseMove = move;
        ctx.moveType = moveType;
        ctx.updateFlags = FALSE;
        ctx.abilities[B_BATTLER_0] = abilityDef;

        MulByTypeEffectiveness(&ctx, &modifier, GetSpeciesType(speciesDef, 0));
        if (GetSpeciesType(speciesDef, 1) != GetSpeciesType(speciesDef, 0))
            MulByTypeEffectiveness(&ctx, &modifier, GetSpeciesType(speciesDef, 1));

        if (ctx.moveType == TYPE_GROUND
         && (abilityDef == ABILITY_LEVITATE || abilityDef == ABILITY_EELEVATE)
         && !(gFieldStatuses & STATUS_FIELD_GRAVITY))
            modifier = UQ_4_12(0.0);
        if (abilityDef == ABILITY_WONDER_GUARD && modifier <= UQ_4_12(1.0) && GetMovePower(move) != 0)
            modifier = UQ_4_12(0.0);
    }

    return modifier;
}

static uq4_12_t GetInverseTypeMultiplier(uq4_12_t multiplier)
{
    switch (multiplier)
    {
    case UQ_4_12(0.0):
    case UQ_4_12(0.5):
        return UQ_4_12(2.0);
    case UQ_4_12(2.0):
        return UQ_4_12(0.5);
    case UQ_4_12(1.0):
    default:
        return UQ_4_12(1.0);
    }
}

uq4_12_t GetOverworldTypeEffectiveness(struct Pokemon *mon, enum Type moveType)
{
    uq4_12_t modifier = UQ_4_12(1.0);

    if (moveType == TYPE_MYSTERY)
        return modifier;


    struct DamageContext ctx = {0};
    ctx.abilities[B_BATTLER_0] = GetMonAbility(mon);
    ctx.move = ctx.chosenMove = ctx.baseMove = MOVE_POUND;
    ctx.moveType = moveType;
    ctx.updateFlags = FALSE;

    enum Species speciesDef = GetMonData(mon, MON_DATA_SPECIES);
    enum Type type1 = GetSpeciesType(speciesDef, 0);
    enum Type type2 = GetSpeciesType(speciesDef, 1);

    MulByTypeEffectiveness(&ctx, &modifier, type1);
    if (type2 != type1)
        MulByTypeEffectiveness(&ctx, &modifier, type2);

    if ((modifier <= UQ_4_12(1.0) && ctx.abilities[B_BATTLER_0] == ABILITY_WONDER_GUARD)
     || CanAbilityAbsorbMove(&ctx))
        modifier = UQ_4_12(0.0);

    return modifier;
}

uq4_12_t GetTypeModifier(enum Type atkType, enum Type defType)
{
    if (B_FLAG_INVERSE_BATTLE != 0 && FlagGet(B_FLAG_INVERSE_BATTLE))
        return GetInverseTypeMultiplier(gTypeEffectivenessTable[atkType][defType]);
    return gTypeEffectivenessTable[atkType][defType];
}

s32 GetStealthHazardDamageByTypesAndHP(enum TypeSideHazard hazardType, enum Type type1, enum Type type2, u32 maxHp)
{
    s32 dmg = 0;
    uq4_12_t modifier = UQ_4_12(1.0);

    modifier = uq4_12_multiply(modifier, GetTypeModifier((u8)hazardType, type1));
    if (type2 != type1)
        modifier = uq4_12_multiply(modifier, GetTypeModifier((u8)hazardType, type2));

    switch (modifier)
    {
    case UQ_4_12(0.0):
        dmg = 0;
        break;
    case UQ_4_12(0.25):
        dmg = maxHp / 32;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(0.5):
        dmg = maxHp / 16;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(1.0):
        dmg = maxHp / 8;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(2.0):
        dmg = maxHp / 4;
        if (dmg == 0)
            dmg = 1;
        break;
    case UQ_4_12(4.0):
        dmg = maxHp / 2;
        if (dmg == 0)
            dmg = 1;
        break;
    }

    return dmg;
}

s32 GetStealthHazardDamage(enum TypeSideHazard hazardType, enum BattlerId battler)
{
    enum Type types[3];
    GetBattlerTypes(battler, FALSE, types);
    u32 maxHp = gBattleMons[battler].maxHP;

    return GetStealthHazardDamageByTypesAndHP(hazardType, types[0], types[1], maxHp);
}

bool32 IsPartnerMonFromSameTrainer(enum BattlerId battler)
{
    if (!IsOnPlayerSide(battler))
        return !(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS);
    else
        return !(gBattleTypeFlags & BATTLE_TYPE_MULTI);
}

bool32 DoesSpeciesUseHoldItemToChangeForm(enum Species species, enum Item heldItemId)
{
    u32 i;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (heldItemId == ITEM_NONE)
        return FALSE;

    for (i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        enum FormChanges method = formChanges[i].method;
        switch (method)
        {
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM:
        case FORM_CHANGE_BATTLE_PRIMAL_REVERSION:
        case FORM_CHANGE_BATTLE_ULTRA_BURST:
        case FORM_CHANGE_ITEM_HOLD:
        case FORM_CHANGE_BEGIN_BATTLE:
            if (formChanges[i].param1 == heldItemId)
                return TRUE;
            break;
        default:
            break;
        }
    }
    return FALSE;
}

bool32 CanMegaEvolve(enum BattlerId battler)
{
    enum HoldEffect holdEffect = GetBattlerHoldEffectIgnoreNegation(battler);
    enum BattlerPosition position = GetBattlerPosition(battler);

    // Check if Player has a Mega Ring.
    if (!TESTING
        && (position == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && position == B_POSITION_PLAYER_RIGHT))
        && !CheckBagHasItem(ITEM_MEGA_RING, 1))
        return FALSE;

    // Check if Trainer has already Mega Evolved.
    if (HasTrainerUsedGimmick(battler, GIMMICK_MEGA))
        return FALSE;

    // Check if battler has another gimmick active.
    if (GetActiveGimmick(battler) != GIMMICK_NONE)
        return FALSE;

    // Check if battler is currently held by Sky Drop.
    if (gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
        return FALSE;

    // Check if battler is holding a Z-Crystal.
    if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;

    enum Ability ability = GetBattlerAbility(battler);

    // Check if there is an entry in the form change table for regular Mega Evolution and battler is holding Mega Stone.
    if (GetBattleFormChangeTargetSpecies(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM, ability) != gBattleMons[battler].species)
        return TRUE;

    // Check if there is an entry in the form change table for Wish Mega Evolution.
    if (GetBattleFormChangeTargetSpecies(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE, ability) != gBattleMons[battler].species)
        return TRUE;

    // No checks passed, the mon CAN'T mega evolve.
    return FALSE;
}

bool32 CanUltraBurst(enum BattlerId battler)
{
    enum HoldEffect holdEffect = GetBattlerHoldEffectIgnoreNegation(battler);
    enum BattlerPosition position = GetBattlerPosition(battler);

    // Check if Player has a Z-Ring
    if (!TESTING && (position == B_POSITION_PLAYER_LEFT
        || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && position == B_POSITION_PLAYER_RIGHT))
        && !CheckBagHasItem(ITEM_Z_POWER_RING, 1))
        return FALSE;

    // Check if Trainer has already Ultra Bursted.
    if (HasTrainerUsedGimmick(battler, GIMMICK_ULTRA_BURST))
        return FALSE;

    // Check if battler has another gimmick active.
    if (GetActiveGimmick(battler) != GIMMICK_NONE)
        return FALSE;

    // Check if mon is currently held by Sky Drop
    if (gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
        return FALSE;

    enum Ability ability = GetBattlerAbility(battler);

    // Check if there is an entry in the form change table for Ultra Burst and battler is holding a Z-Crystal.
    if (GetBattleFormChangeTargetSpecies(battler, FORM_CHANGE_BATTLE_ULTRA_BURST, ability) != gBattleMons[battler].species && holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return TRUE;

    // No checks passed, the mon CAN'T ultra burst.
    return FALSE;
}

void ActivateMegaEvolution(enum BattlerId battler)
{
    enum Ability ability = GetBattlerAbility(battler);
    gLastUsedItem = gBattleMons[battler].item;
    SetActiveGimmick(battler, GIMMICK_MEGA);
    SetGimmickAsActivated(battler, GIMMICK_MEGA);

    if (TryBattleFormChange(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE, ability))
    {
        BattleScriptPushCursorAndCallback(BattleScript_WishMegaEvolution);
    }
    else
    {
        TryBattleFormChange(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM, ability);
        BattleScriptPushCursorAndCallback(BattleScript_MegaEvolution);
    }
}

void ActivateUltraBurst(enum BattlerId battler)
{
    enum Ability ability = GetBattlerAbility(battler);
    gLastUsedItem = gBattleMons[battler].item;
    SetActiveGimmick(battler, GIMMICK_ULTRA_BURST);
    SetGimmickAsActivated(battler, GIMMICK_ULTRA_BURST);
    TryBattleFormChange(battler, FORM_CHANGE_BATTLE_ULTRA_BURST, ability);
    BattleScriptPushCursorAndCallback(BattleScript_UltraBurst);
}

bool32 IsBattlerMegaEvolved(enum BattlerId battler)
{
    // While Transform does copy stats and visuals, it shouldn't be counted as true Mega Evolution.
    if (gBattleMons[battler].volatiles.transformed)
        return FALSE;
    return (gSpeciesInfo[gBattleMons[battler].species].isMegaEvolution);
}

bool32 IsBattlerPrimalReverted(enum BattlerId battler)
{
    // While Transform does copy stats and visuals, it shouldn't be counted as true Primal Revesion.
    if (gBattleMons[battler].volatiles.transformed)
        return FALSE;
    return (gSpeciesInfo[gBattleMons[battler].species].isPrimalReversion);
}

bool32 IsBattlerUltraBursted(enum BattlerId battler)
{
    // While Transform does copy stats and visuals, it shouldn't be counted as true Ultra Burst.
    if (gBattleMons[battler].volatiles.transformed)
        return FALSE;
    return (gSpeciesInfo[gBattleMons[battler].species].isUltraBurst);
}

bool32 IsBattlerInTeraForm(enum BattlerId battler)
{
    // While Transform does copy stats and visuals, it shouldn't be counted as a true Tera Form.
    if (gBattleMons[battler].volatiles.transformed)
        return FALSE;
    return (gSpeciesInfo[gBattleMons[battler].species].isTeraForm);
}

enum Species GetBattleFormChangeTargetSpecies(enum BattlerId battler, enum FormChanges method, enum Ability ability)
{
    enum Species species = gBattleMons[battler].species;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges == NULL)
        return species;

    struct FormChangeContext ctx =
    {
        .method = method,
        .currentSpecies = gBattleMons[battler].species,
        .heldItem = gBattleMons[battler].item,
        .ability = ability,
        .status = gBattleMons[battler].status1,
        .gmaxFactor = GetMonData(GetBattlerMon(battler), MON_DATA_GIGANTAMAX_FACTOR),
        .hp = gBattleMons[battler].hp,
        .maxHP = gBattleMons[battler].maxHP,
        .teraType = GetBattlerTeraType(battler),
        .level = gBattleMons[battler].level,
    };

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        ctx.moves[i] = gBattleMons[battler].moves[i];

    return GetFormChangeTargetSpecies_Internal(ctx);
}

static bool32 CanBattlerFormChange(enum BattlerId battler, enum FormChanges method)
{
    // Can't change form if transformed.
    if (gBattleMons[battler].volatiles.transformed
        && GetConfig(B_TRANSFORM_FORM_CHANGES) >= GEN_5)
        return FALSE;

    switch (method)
    {
    case FORM_CHANGE_END_BATTLE:
        if (IsBattlerPrimalReverted(battler))
            return TRUE;
        // Fallthrough
    case FORM_CHANGE_FAINT:
        if (IsBattlerMegaEvolved(battler) || IsBattlerUltraBursted(battler) || IsBattlerInTeraForm(battler) || IsGigantamaxed(battler))
            return TRUE;
        break;
    case FORM_CHANGE_BATTLE_SWITCH_OUT:
        if (IsGigantamaxed(battler))
            return TRUE;
        else if (GetActiveGimmick(battler) == GIMMICK_TERA && DoesSpeciesHaveFormChangeMethod(gBattleMons[battler].species, FORM_CHANGE_BATTLE_TURN_END))
            return FALSE;
        break;
    case FORM_CHANGE_BATTLE_TURN_END:
        if (GetActiveGimmick(battler) == GIMMICK_TERA)
            return FALSE;
        break;
    default:
        break;
    }
    return DoesSpeciesHaveFormChangeMethod(gBattleMons[battler].species, method);
}

bool32 TryRevertPartyMonFormChange(u32 partyIndex)
{
     bool32 changedForm = FALSE;

    // Appeared in battle and didn't faint
    if (gBattleStruct->partyState[B_SIDE_PLAYER][partyIndex].sentOut && GetMonData(&gParties[B_TRAINER_PLAYER][partyIndex], MON_DATA_HP) != 0)
        changedForm = TryFormChange(&gParties[B_TRAINER_PLAYER][partyIndex], FORM_CHANGE_END_BATTLE_ENVIRONMENT, B_TRAINER_PLAYER);

    if (!changedForm)
        changedForm = TryFormChange(&gParties[B_TRAINER_PLAYER][partyIndex], FORM_CHANGE_END_BATTLE, B_TRAINER_PLAYER);

    // Clear original species field
    gBattleStruct->partyState[B_SIDE_PLAYER][partyIndex].changedSpecies = SPECIES_NONE;

    return changedForm;
}

bool32 TryBattleFormChange(enum BattlerId battler, enum FormChanges method, enum Ability ability)
{
    struct Pokemon *mon = GetBattlerMon(battler);

    if (!CanBattlerFormChange(battler, method))
        return FALSE;

    enum Species currentSpecies = GetMonData(mon, MON_DATA_SPECIES);
    enum Species targetSpecies = GetBattleFormChangeTargetSpecies(battler, method, ability);

    struct PartyState *battlePartyState = GetBattlerPartyState(battler);
    // If the battle ends, and there's not a specified species to change back to,
    // use the species at the start of the battle.
    if (targetSpecies == SPECIES_NONE
        && battlePartyState != NULL && battlePartyState->changedSpecies != SPECIES_NONE
        // This is added to prevent FORM_CHANGE_END_BATTLE_ENVIRONMENT from omitting move changes
        // at the end of the battle, as it was being counting as a successful form change.
        && (method == FORM_CHANGE_END_BATTLE || method == FORM_CHANGE_FAINT))
    {
        targetSpecies = battlePartyState->changedSpecies;
    }

    assertf(targetSpecies != SPECIES_NONE, "form change target returned NONE. cur:%d, method:%d", currentSpecies, method)
    {
        return FALSE;
    }

    if (targetSpecies != currentSpecies)
    {
        // Saves the original species on the first form change.
        if (GetBattlerPartyState(battler)->changedSpecies == SPECIES_NONE)
            GetBattlerPartyState(battler)->changedSpecies = gBattleMons[battler].species;

        TryToSetBattleFormChangeMoves(mon, method);
        SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
        gBattleMons[battler].species = targetSpecies;
        RecalcBattlerStats(battler, mon, method == FORM_CHANGE_BATTLE_GIGANTAMAX);
        return TRUE;
    }

    return FALSE;
}

bool32 DoBattlersShareType(enum BattlerId battler1, enum BattlerId battler2)
{
    s32 i;
    s32 j;
    enum Type types1[3], types2[3];
    GetBattlerTypes(battler1, FALSE, types1);
    GetBattlerTypes(battler2, FALSE, types2);

    for (i = 0; i < 3; i++)
    {
        if (types1[i] == TYPE_MYSTERY)
            continue;

        for (j = 0; j < 3; j++)
        {
            if (types2[j] == TYPE_MYSTERY)
                continue;
            if (types1[i] == types2[j])
                return TRUE;
        }
    }

    return FALSE;
}

bool32 CanBattlerGetOrLoseItem(enum BattlerId fromBattler, enum BattlerId battler, enum Item itemId)
{
    enum Species fromSpecies = gBattleMons[fromBattler].species;
    enum Species otherSpecies = gBattleMons[battler].species;

    enum HoldEffect holdEffect = GetItemHoldEffect(itemId); // Raw hold effect

    if (ItemIsMail(itemId))
        return FALSE;
    else if (itemId == ITEM_ENIGMA_BERRY_E_READER)
        return FALSE;
    else if (DoesSpeciesUseHoldItemToChangeForm(fromSpecies, itemId) || (DoesSpeciesUseHoldItemToChangeForm(otherSpecies, itemId) && GetConfig(B_KNOCK_OFF_REMOVAL) < GEN_CHAMPIONS))
        return FALSE;
    else if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;
    else if (holdEffect == HOLD_EFFECT_BOOSTER_ENERGY
         && (gSpeciesInfo[fromSpecies].isParadox || gSpeciesInfo[otherSpecies].isParadox))
        return FALSE;
    else if (holdEffect == HOLD_EFFECT_OGERPON_MASK && GET_BASE_SPECIES_ID(fromSpecies) == SPECIES_OGERPON)
        return FALSE;
    else
        return TRUE;
}

enum Species GetBattlerVisualSpecies(enum BattlerId battler)
{
    enum Species illusionSpecies = GetIllusionMonSpecies(battler);
    if (illusionSpecies != SPECIES_NONE)
        return illusionSpecies;
    return gBattleMons[battler].species;
}

bool32 TryClearIllusion(enum BattlerId battler, enum Ability ability)
{
    if (gBattleStruct->illusion[battler].state != ILLUSION_ON)
        return FALSE;
    if (ability == ABILITY_ILLUSION && !IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES))
        return FALSE;

    gBattleScripting.battler = battler;
    BattleScriptCall(BattleScript_IllusionOff);
    return TRUE;
}

struct Pokemon *GetIllusionMonPtr(enum BattlerId battler)
{
    if (gBattleStruct->illusion[battler].state == ILLUSION_NOT_SET)
        SetIllusionMon(GetBattlerMon(battler), battler);
    if (gBattleStruct->illusion[battler].state != ILLUSION_ON)
        return NULL;

    return gBattleStruct->illusion[battler].mon;
}

void ClearIllusionMon(enum BattlerId battler)
{
    memset(&gBattleStruct->illusion[battler], 0, sizeof(gBattleStruct->illusion[battler]));
}

enum Species GetIllusionMonSpecies(enum BattlerId battler)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        return GetMonData(illusionMon, MON_DATA_SPECIES);
    return SPECIES_NONE;
}

u32 GetIllusionMonPartyId(struct Pokemon *party, struct Pokemon *mon, struct Pokemon *partnerMon, enum BattlerId battler)
{
    // Find last alive non-egg Pokémon.
    for (s32 id = PARTY_SIZE - 1; id >= 0; id--)
    {
        if (GetMonData(&party[id], MON_DATA_SANITY_HAS_SPECIES)
            && GetMonData(&party[id], MON_DATA_HP)
            && !GetMonData(&party[id], MON_DATA_IS_EGG))
        {
            enum Species species = GetMonData(&party[id], MON_DATA_SPECIES);
            if (species == SPECIES_TERAPAGOS_STELLAR || (species >= SPECIES_OGERPON_TEAL_TERA && species <= SPECIES_OGERPON_CORNERSTONE_TERA))
                continue;
            if (&party[id] != mon && &party[id] != partnerMon)
                return id;
            else // If this Pokémon or its partner is last in the party, ignore Illusion.
                return PARTY_SIZE;
        }
    }
    return PARTY_SIZE;
}

void SetIllusionMon(struct Pokemon *mon, enum BattlerId battler)
{
    struct Pokemon *party, *partnerMon;
    u32 id;

    gBattleStruct->illusion[battler].state = ILLUSION_OFF;
    if (GetMonAbility(mon) != ABILITY_ILLUSION)
        return;

    party = GetBattlerParty(battler);

    if (IsBattlerAlive(GetPartnerBattler(battler)))
        partnerMon = GetBattlerMon(GetPartnerBattler(battler));
    else
        partnerMon = mon;

    id = GetIllusionMonPartyId(party, mon, partnerMon, battler);
    if (id != PARTY_SIZE)
    {
        gBattleStruct->illusion[battler].state = ILLUSION_ON;
        gBattleStruct->illusion[battler].mon = &party[id];
    }
}

enum ImmunityHealStatusOutcome TryImmunityAbilityHealStatus(enum BattlerId battler)
{
    enum ImmunityHealStatusOutcome outcome = IMMUNITY_NO_EFFECT;
    switch (GetBattlerAbilityIgnoreMoldBreaker(battler))
    {
    case ABILITY_IMMUNITY:
    case ABILITY_PASTEL_VEIL:
        if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_OWN_TEMPO:
        if (gBattleMons[battler].volatiles.confusionTimer > 0)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_CONFUSION;
            outcome = IMMUNITY_CONFUSION_CLEARED;
        }
        break;
    case ABILITY_LIMBER:
        if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_INSOMNIA:
    case ABILITY_VITAL_SPIRIT:
        if (gBattleMons[battler].status1 & STATUS1_SLEEP)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
            TryDeactivateSleepClause(battler, gBattlerPartyIndexes[battler]);
            gBattleMons[battler].volatiles.nightmare = FALSE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_WATER_VEIL:
    case ABILITY_WATER_BUBBLE:
    case ABILITY_THERMAL_EXCHANGE:
        if (gBattleMons[battler].status1 & STATUS1_BURN)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_MAGMA_ARMOR:
        if (gBattleMons[battler].status1 & STATUS1_FREEZE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        else if (gBattleMons[battler].status1 & STATUS1_FROSTBITE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_OBLIVIOUS:
        if (gBattleMons[battler].volatiles.infatuation)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_INFATUATION;
            outcome = IMMUNITY_INFATUATION_CLEARED;
        }
        else if (GetConfig(B_OBLIVIOUS_TAUNT) >= GEN_6 && gBattleMons[battler].volatiles.tauntTimer != 0)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_TAUNT;
            outcome = IMMUNITY_TAUNT_CLEARED;
        }
        break;
    default:
        break;
    }

    switch (outcome)
    {
    case IMMUNITY_STATUS_CLEARED:
        gBattleMons[battler].status1 = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_CONFUSION_CLEARED:
        gBattleMons[battler].volatiles.confusionTimer = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_INFATUATION_CLEARED:
        gBattleMons[battler].volatiles.infatuation = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_TAUNT_CLEARED:
        gBattleMons[battler].volatiles.tauntTimer = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_NO_EFFECT:
        return IMMUNITY_NO_EFFECT;
    }

    gBattleScripting.battler = gBattlerAbility = battler;
    if (outcome == IMMUNITY_STATUS_CLEARED)
    {
        BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
        MarkBattlerForControllerExec(battler);
    }
    return outcome;
}

uq4_12_t GetBadgeBoostModifier(void)
{
    if (GetConfig(B_BADGE_BOOST) < GEN_3)
        return UQ_4_12(1.125);
    else
        return UQ_4_12(1.1);
}

bool32 ShouldGetStatBadgeBoost(u16 badgeFlag, enum BattlerId battler)
{
    if (GetConfig(B_BADGE_BOOST) <= GEN_3 && badgeFlag != 0)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_FRONTIER))
            return FALSE;
        else if (!IsOnPlayerSide(battler))
            return FALSE;
        else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && TRAINER_BATTLE_PARAM.opponentA == TRAINER_SECRET_BASE)
            return FALSE;
        else if (FlagGet(badgeFlag))
            return TRUE;
    }
    return FALSE;
}

enum DamageCategory GetBattleMoveCategory(enum Move move)
{
    bool32 inBattle = gBattleStruct != NULL;

    if (inBattle && gBattleStruct->dynamicMoveCategory != DAMAGE_CATEGORY_NONE)
        return gBattleStruct->dynamicMoveCategory;

    if (GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS)
        return DAMAGE_CATEGORY_STATUS;

    if (B_PHYSICAL_SPECIAL_SPLIT < GEN_4)
    {
        if (inBattle)
            return gTypesInfo[GetBattleMoveType(move)].damageCategory;
        else
            return gTypesInfo[GetMoveType(move)].damageCategory;
    }

    return GetMoveCategory(move);
}

void SetDynamicMoveCategory(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;

    switch (GetMoveEffect(move))
    {
    case EFFECT_PHOTON_GEYSER:
        if (GetCategoryBasedOnStats(battlerAtk) == DAMAGE_CATEGORY_PHYSICAL)
            gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_PHYSICAL;
        else
            gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_SPECIAL;
        break;
    case EFFECT_SHELL_SIDE_ARM:
        gBattleStruct->dynamicMoveCategory = gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef];
        break;
    case EFFECT_TERA_BLAST:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA)
        {
            if (GetCategoryBasedOnStats(battlerAtk) == DAMAGE_CATEGORY_PHYSICAL)
                gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_PHYSICAL;
            else
                gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_SPECIAL;
        }
        else
        {
            gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;
        }
        break;
    case EFFECT_TERA_STARSTORM:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_TERA && GET_BASE_SPECIES_ID(GetMonData(GetBattlerMon(battlerAtk), MON_DATA_SPECIES)) == SPECIES_TERAPAGOS)
        {
            if (GetCategoryBasedOnStats(battlerAtk) == DAMAGE_CATEGORY_PHYSICAL)
                gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_PHYSICAL;
            else
                gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_SPECIAL;
        }
        else
        {
            gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_NONE;
        }
        break;
    case EFFECT_PRESENT:
    {
        gBattleStruct->presentBasePower = 0;
        u32 rand = RandomUniform(RNG_PRESENT, 0, 0xFF);
        if (rand < 102)
            gBattleStruct->presentBasePower = 40;
        else if (rand < 178)
            gBattleStruct->presentBasePower = 80;
        else if (rand < 204)
            gBattleStruct->presentBasePower = 120;
        else
            gBattleStruct->dynamicMoveCategory = DAMAGE_CATEGORY_STATUS;
        break;
    }
    default:
        if (GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX)
            gBattleStruct->dynamicMoveCategory = GetMoveCategory(GetBattlerChosenMove(battlerAtk));
        break;
    }
}

static bool32 TryRemoveScreens(enum BattlerId battler)
{
    bool32 removed = FALSE;
    u32 battlerSide = GetBattlerSide(battler);
    u8 enemySide = GetBattlerSide(GetOppositeBattler(battler));

    // try to remove from battler's side
    if (gSideStatuses[battlerSide] & SIDE_STATUS_SCREEN_ANY)
    {
        gSideStatuses[battlerSide] &= ~SIDE_STATUS_SCREEN_ANY;
        removed = TRUE;
    }

    // try to remove from battler opponent's side
    if (gSideStatuses[enemySide] & SIDE_STATUS_SCREEN_ANY)
    {
        gSideStatuses[enemySide] &= ~SIDE_STATUS_SCREEN_ANY;
        removed = TRUE;
    }

    return removed;
}

// Photon Geyser, Light That Burns the Sky, Tera Blast
enum DamageCategory GetCategoryBasedOnStats(enum BattlerId battler)
{
    u32 attack = gBattleMons[battler].attack;
    u32 spAttack = gBattleMons[battler].spAttack;

    attack = attack * gStatStageRatios[gBattleMons[battler].statStages[STAT_ATK]][0];
    attack = attack / gStatStageRatios[gBattleMons[battler].statStages[STAT_ATK]][1];

    spAttack = spAttack * gStatStageRatios[gBattleMons[battler].statStages[STAT_SPATK]][0];
    spAttack = spAttack / gStatStageRatios[gBattleMons[battler].statStages[STAT_SPATK]][1];

    if (spAttack >= attack)
        return DAMAGE_CATEGORY_SPECIAL;
    else
        return DAMAGE_CATEGORY_PHYSICAL;
}

static u32 GetFlingPowerFromItemId(enum Item itemId)
{
    if (gItemsInfo[itemId].pocket == POCKET_TM_HM)
    {
        u32 power = GetMovePower(ItemIdToBattleMoveId(itemId));
        if (power > 1)
            return power;
        return 10; // Status moves and moves with variable power always return 10 power.
    }
    else
        return GetItemFlingPower(itemId);
}

bool32 CanFling(enum BattlerId battlerAtk, enum Ability abilityAtk)
{
    enum Item item = gBattleMons[battlerAtk].item;

    if (item == ITEM_NONE
      || (GetConfig(B_KLUTZ_FLING_INTERACTION) >= GEN_5 && abilityAtk == ABILITY_KLUTZ)
      || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
      || gBattleMons[battlerAtk].volatiles.embargoTimer
      || (GetItemTMHMIndex(item) != 0 && GetItemImportance(item) == 1) // don't fling reusable TMs
      || GetFlingPowerFromItemId(item) == 0
      || !CanBattlerGetOrLoseItem(battlerAtk, battlerAtk, item)) // defender being a paradox mon doesn't matter
        return FALSE;

    return TRUE;
}

void SortBattlersByRawSpeed(u8 battlers[])
{
    for (u32 i = 0; i < gBattlersCount; i++)
        battlers[i] = i;

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        for (u32 j = 0; j < gBattlersCount; j++)
        {
            if (gBattleMons[battlers[i]].speed >= gBattleMons[battlers[j]].speed)
            {
                u32 temp = battlers[i];
                battlers[i] = battlers[j];
                battlers[j] = temp;
            }
        }
    }
}

// Sort an array of battlers by speed
// Useful for effects like pickpocket, eject button, red card, dancer
void SortBattlersBySpeed(enum BattlerId *battlers, bool32 slowToFast)
{
    int i, j, currSpeed;
    enum BattlerId currBattler;
    u16 speeds[MAX_BATTLERS_COUNT] = {0};

    for (i = 0; i < gBattlersCount; i++)
    {
        enum BattlerId battler = battlers[i];
        speeds[i] = GetBattlerTotalSpeedStat(battler, GetBattlerAbility(battler), GetBattlerHoldEffect(battler));
    }

    for (i = 1; i < gBattlersCount; i++)
    {
        currBattler = battlers[i];
        currSpeed = speeds[i];
        j = i - 1;

        if (slowToFast)
        {
            while (j >= 0 && speeds[j] > currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && speeds[j] < currSpeed)
            {
                battlers[j + 1] = battlers[j];
                speeds[j + 1] = speeds[j];
                j = j - 1;
            }
        }

        battlers[j + 1] = currBattler;
        speeds[j + 1] = currSpeed;
    }
}

void TryRestoreHeldItems(void)
{
    if (!B_TRAINERS_KNOCK_OFF_ITEMS && B_RESTORE_HELD_BATTLE_ITEMS < GEN_9)
        return;

    bool32 returnNPCItems = B_RETURN_STOLEN_NPC_ITEMS >= GEN_5 && gBattleTypeFlags & BATTLE_TYPE_TRAINER;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleStruct->itemLost[B_TRAINER_PLAYER][i].stolen || returnNPCItems)
        {
            enum Item lostItem = gBattleStruct->itemLost[B_TRAINER_PLAYER][i].originalItem;

            if (GetItemPocket(lostItem) == POCKET_BERRIES && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM) != lostItem)
                lostItem = ITEM_NONE;

            if ((lostItem != ITEM_NONE || returnNPCItems) && GetItemPocket(lostItem) != POCKET_BERRIES)
                SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM, &lostItem);
        }
    }
}

bool32 CanStealItem(enum BattlerId battlerStealing, enum BattlerId battlerItem, enum Item item)
{
    enum BattleSide stealerSide = GetBattlerSide(battlerStealing);

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        return FALSE;

    // Check if the battler trying to steal should be able to
    if (stealerSide == B_SIDE_OPPONENT
        && !(gBattleTypeFlags &
             (BATTLE_TYPE_EREADER_TRAINER
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_LINK
              | BATTLE_TYPE_RECORDED_LINK
              | BATTLE_TYPE_SECRET_BASE
              | (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? BATTLE_TYPE_TRAINER : 0)
              )))
    {
        return FALSE;
    }
    else if (!(gBattleTypeFlags &
          (BATTLE_TYPE_EREADER_TRAINER
           | BATTLE_TYPE_FRONTIER
           | BATTLE_TYPE_LINK
           | BATTLE_TYPE_RECORDED_LINK
           | BATTLE_TYPE_SECRET_BASE))
        && GetBattlerPartyState(battlerStealing)->isKnockedOff)
    {
        return FALSE;
    }

    if (!CanBattlerGetOrLoseItem(battlerItem, battlerStealing, item)  // Battler with item cannot have it stolen
     || !CanBattlerGetOrLoseItem(battlerStealing, battlerItem, item)) // Stealer cannot take the item
        return FALSE;

    return TRUE;
}

void TrySaveExchangedItem(enum BattlerId battler, enum Item stolenItem)
{
    // Because BtlController_EmitSetMonData does SetMonData, we need to save the stolen item only if it matches the battler's original
    // So, if the player steals an item during battle and has it stolen from it, it will not end the battle with it (naturally)
    if (B_TRAINERS_KNOCK_OFF_ITEMS == FALSE)
        return;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return;

    if (GetBattlerTrainer(battler) != B_TRAINER_PLAYER)
        return;

    // If regular trainer battle and mon's original item matches what is being stolen, save it to be restored at end of battle
    if (stolenItem == gBattleStruct->itemLost[B_TRAINER_PLAYER][gBattlerPartyIndexes[battler]].originalItem)
        gBattleStruct->itemLost[B_TRAINER_PLAYER][gBattlerPartyIndexes[battler]].stolen = TRUE;
}

bool32 IsBattlerAffectedByHazards(enum BattlerId battler, enum HoldEffect holdEffect, bool32 toxicSpikes)
{
    bool32 ret = TRUE;
    if (!IsBattlerAlive(battler))
    {
        ret = FALSE;
    }
    else if (toxicSpikes && holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS && !IS_BATTLER_OF_TYPE(battler, TYPE_POISON))
    {
        ret = FALSE;
        RecordItemEffectBattle(battler, holdEffect);
    }
    else if (holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
    {
        ret = FALSE;
        RecordItemEffectBattle(battler, holdEffect);
    }
    return ret;
}

bool32 IsSheerForceAffected(enum Move move, enum Ability ability)
{
    return ability == ABILITY_SHEER_FORCE && MoveIsAffectedBySheerForce(move);
}

bool32 BlocksPrankster(enum Move move, enum BattlerId battlerPrankster, enum BattlerId battlerDef, bool32 checkTarget)
{
    if (GetConfig(B_PRANKSTER_DARK_TYPES) < GEN_7)
        return FALSE;
    if (!gProtectStructs[battlerPrankster].pranksterElevated)
        return FALSE;
    if (IsBattlerAlly(battlerPrankster, battlerDef))
        return FALSE;
    if (checkTarget && GetBattlerMoveTargetType(battlerPrankster, move) == TARGET_DEPENDS)
        return FALSE;
    if (checkTarget && GetBattlerMoveTargetType(battlerPrankster, move) == TARGET_OPPONENTS_FIELD)
        return FALSE;
    if (!IS_BATTLER_OF_TYPE(battlerDef, TYPE_DARK))
        return FALSE;
    if (IsSemiInvulnerable(battlerDef, CHECK_ALL))
        return FALSE;

    return TRUE;
}

// Not enum BattlerId to allow using it with RandomUniformExcept
bool32 CantPickupItem(u32 _battler)
{
    enum BattlerId battler = _battler;
    // Used by RandomUniformExcept() for RNG_PICKUP
    if (battler == gBattlerAttacker && (GetConfig(B_PICKUP_WILD) < GEN_9 || gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_LINK)))
        return TRUE;
    return !(IsBattlerAlive(battler) && GetBattlerPartyState(battler)->usedHeldItem && gBattleStruct->battlerState[battler].canPickupItem);
}

bool32 PickupHasValidTarget(enum BattlerId battler)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (!CantPickupItem(i))
            return TRUE;
    }
    return FALSE;
}

u32 GetWeather(void)
{
    if (gBattleWeather == B_WEATHER_NONE || !HasWeatherEffect())
        return B_WEATHER_NONE;
    return gBattleWeather;
}

u32 GetAttackerWeather(enum HoldEffect holdEffect, enum Ability ability, u32 weather)
{
    if (ability == ABILITY_MEGA_SOL)
        return B_WEATHER_SUN;

    if (holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA)
        return weather & ~(B_WEATHER_SUN | B_WEATHER_RAIN); // This was assumed not to block mega sol, like cloud nine doesn't.

    return weather;
}


bool32 IsBattlerWeatherAffected(enum HoldEffect holdEffect, u32 weather, u32 weatherFlags)
{
    if (weather & (B_WEATHER_SUN | B_WEATHER_RAIN) && holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA)
        return FALSE;

    if (weather == B_WEATHER_NONE || !(gBattleWeather & weatherFlags))
        return FALSE;

    return TRUE;
}

static u32 CanBattlerHitBothFoesInTerrain(enum BattlerId battler, enum Move move, enum BattleMoveEffects effect)
{
    return effect == EFFECT_TERRAIN_BOOST
        && GetMoveTerrainBoost_HitsBothFoes(move)
        && IsBattlerTerrainAffected(battler, GetBattlerAbility(battler), GetBattlerHoldEffect(battler), GetMoveTerrainBoost_Terrain(move), gFieldTimers.terrain);
}

enum MoveTarget GetBattlerMoveSelectionTargetType(enum BattlerId battler, enum Move move)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_CURSE && !IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return TARGET_USER;
    if (effect == EFFECT_TERA_STARSTORM && gBattleMons[battler].species == SPECIES_TERAPAGOS_STELLAR)
        return TARGET_BOTH;

    return GetMoveTarget(move);
}

enum MoveTarget GetBattlerMoveTargetType(enum BattlerId battler, enum Move move)
{
    if (CanBattlerHitBothFoesInTerrain(battler, move, GetMoveEffect(move)))
        return TARGET_BOTH;

    return GetBattlerMoveSelectionTargetType(battler, move);
}

bool32 CanTargetBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move)
{
    if (GetMoveEffect(move) == EFFECT_HIT_ENEMY_HEAL_ALLY
    &&  IsBattlerAlly(battlerAtk, battlerDef)
    &&  gBattleMons[battlerAtk].volatiles.healBlockTimer)
        return FALSE;   // Pokémon affected by Heal Block cannot target allies with Pollen Puff
    if (!IsBattlerAlive(battlerDef))
        return FALSE;
    if (IsBattlerAlly(battlerAtk, battlerDef) && (GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX
                                               || IsGimmickSelected(battlerAtk, GIMMICK_DYNAMAX)))
        return FALSE;

    return TRUE;
}

u32 GetNextTarget(u32 moveTarget, bool32 excludeCurrent)
{
    enum BattlerId battler;
    for (battler = B_BATTLER_0; battler < MAX_BATTLERS_COUNT; battler++)
    {
        if (excludeCurrent && battler == gBattlerTarget)
            continue;
        if (gBattleStruct->battlerState[gBattlerAttacker].targetsDone[battler])
            continue;
        if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_NO_EFFECT)
            continue;
        break;
    }
    return battler;
}

void CopyMonLevelAndBaseStatsToBattleMon(enum BattlerId battler, struct Pokemon *mon, bool32 updateSpeedStat)
{
    gBattleMons[battler].level = GetMonData(mon, MON_DATA_LEVEL);
    gBattleMons[battler].hp = GetMonData(mon, MON_DATA_HP);
    gBattleMons[battler].maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    gBattleMons[battler].attack = GetMonData(mon, MON_DATA_ATK);
    gBattleMons[battler].defense = GetMonData(mon, MON_DATA_DEF);
    if (updateSpeedStat)
        gBattleMons[battler].speed = GetMonData(mon, MON_DATA_SPEED);
    gBattleMons[battler].spAttack = GetMonData(mon, MON_DATA_SPATK);
    gBattleMons[battler].spDefense = GetMonData(mon, MON_DATA_SPDEF);
}

void CopyMonAbilityAndTypesToBattleMon(enum BattlerId battler, struct Pokemon *mon)
{
    gBattleMons[battler].ability = GetMonAbility(mon);
    #if TESTING
    if (gTestRunnerEnabled)
    {
        u32 array = (!IsPartnerMonFromSameTrainer(battler)) ? battler : GetBattlerSide(battler);
        u32 partyIndex = gBattlerPartyIndexes[battler];
        if (TestRunner_Battle_GetForcedAbility(array, partyIndex))
            gBattleMons[battler].ability = TestRunner_Battle_GetForcedAbility(array, partyIndex);
    }
    #endif
    gBattleMons[battler].types[0] = GetSpeciesType(gBattleMons[battler].species, 0);
    gBattleMons[battler].types[1] = GetSpeciesType(gBattleMons[battler].species, 1);
    gBattleMons[battler].types[2] = TYPE_MYSTERY;
}

void RecalcBattlerStats(enum BattlerId battler, struct Pokemon *mon, bool32 isDynamaxing)
{
    u32 hp = GetMonData(mon, MON_DATA_HP);
    u32 oldMaxHp = GetMonData(mon, MON_DATA_MAX_HP);
    if (gBattleMons[battler].volatiles.speedSwapped && GetConfig(B_MEGA_EVO_SPEED_SWAP) >= GEN_CHAMPIONS)
        CalculateMonStatsCont(mon, FALSE);
    else
        CalculateMonStats(mon);

    if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && gChosenActionByBattler[battler] != B_ACTION_SWITCH)
    {
        ApplyDynamaxHPMultiplier(mon);
        u32 newMaxHp = GetMonData(mon, MON_DATA_MAX_HP);
        if (!isDynamaxing)
        {
            if (newMaxHp > oldMaxHp) // restore hp gained from changing form, without this, dynamaxed form changes are calculated incorrectly
            {
                hp += (newMaxHp - oldMaxHp);
                SetMonData(mon, MON_DATA_HP, &hp);
            }
            else
            {
                SetMonData(mon, MON_DATA_HP, &hp);
            }
        }
    }
    if (gBattleMons[battler].volatiles.speedSwapped && GetConfig(B_MEGA_EVO_SPEED_SWAP) >= GEN_CHAMPIONS)
        CopyMonLevelAndBaseStatsToBattleMon(battler, mon, FALSE);
    else
        CopyMonLevelAndBaseStatsToBattleMon(battler, mon, TRUE);
    CopyMonAbilityAndTypesToBattleMon(battler, mon);
}

u32 GetBattlerGender(enum BattlerId battler)
{
    return GetGenderFromSpeciesAndPersonality(gBattleMons[battler].species,
                                              gBattleMons[battler].personality);
}

bool32 AreBattlersOfOppositeGender(enum BattlerId battler1, enum BattlerId battler2)
{
    u32 gender1 = GetBattlerGender(battler1);
    u32 gender2 = GetBattlerGender(battler2);

    return (gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS && gender1 != gender2);
}

bool32 AreBattlersOfSameGender(enum BattlerId battler1, enum BattlerId battler2)
{
    u32 gender1 = GetBattlerGender(battler1);
    u32 gender2 = GetBattlerGender(battler2);

    return (gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS && gender1 == gender2);
}

u32 CalcSecondaryEffectChance(enum BattlerId battler, enum Ability battlerAbility, const struct AdditionalEffect *additionalEffect)
{
    bool8 hasSereneGrace = (battlerAbility == ABILITY_SERENE_GRACE);
    bool8 hasRainbow = (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_RAINBOW) != 0;
    u16 secondaryEffectChance = additionalEffect->chance;

    if (hasRainbow && hasSereneGrace && additionalEffect->moveEffect == MOVE_EFFECT_FLINCH)
        return secondaryEffectChance * 2;

    if (hasSereneGrace)
        secondaryEffectChance *= 2;
    if (hasRainbow && additionalEffect->moveEffect != MOVE_EFFECT_SECRET_POWER)
        secondaryEffectChance *= 2;

    return secondaryEffectChance;
}

bool32 MoveEffectIsGuaranteed(enum BattlerId battler, enum Ability battlerAbility, const struct AdditionalEffect *additionalEffect)
{
    return additionalEffect->chance == 0 || CalcSecondaryEffectChance(battler, battlerAbility, additionalEffect) >= 100;
}

bool32 IsGen6ExpShareEnabled(void)
{
    if (I_EXP_SHARE_FLAG <= TEMP_FLAGS_END)
        return FALSE;

    return FlagGet(I_EXP_SHARE_FLAG);
}


bool32 MoveHasAdditionalEffect(enum Move move, enum MoveEffect moveEffect)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        if (additionalEffect->moveEffect == moveEffect && additionalEffect->self == FALSE)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalOnSideEffect(enum Move move)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        if (additionalEffect->onSide)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectWithChance(enum Move move, enum MoveEffect moveEffect, u32 chance)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        if (additionalEffect->moveEffect == moveEffect && additionalEffect->chance == chance)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveHasAdditionalEffectSelf(enum Move move, enum MoveEffect moveEffect)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        if (additionalEffect->moveEffect == moveEffect && additionalEffect->self == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool32 IsMoveEffectRemoveSpeciesType(enum Move move, enum MoveEffect moveEffect, enum Type type)
{
    return (MoveHasAdditionalEffectSelf(move, moveEffect) && GetMoveArgType(move) == type);
}

bool32 MoveHasChargeTurnAdditionalEffect(enum Move move)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        if (GetMoveAdditionalEffectById(move, i)->onChargeTurnOnly)
            return TRUE;
    }
    return FALSE;
}

bool32 MoveIsAffectedBySheerForce(enum Move move)
{
    u32 i;
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);
    for (i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        if ((additionalEffect->chance > 0) != additionalEffect->sheerForceOverride)
            return TRUE;
    }
    return FALSE;
}

bool32 CanMonParticipateInSkyBattle(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 monAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    enum Ability ability = GetSpeciesAbility(species, monAbilityNum);

    bool32 hasLevitateAbility = (ability == ABILITY_LEVITATE || ability == ABILITY_EELEVATE);
    bool32 isFlyingType = GetSpeciesType(species, 0) == TYPE_FLYING || GetSpeciesType(species, 1) == TYPE_FLYING;
    bool32 monIsValidAndNotEgg = GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(mon, MON_DATA_IS_EGG);

    if (monIsValidAndNotEgg)
    {
        if ((hasLevitateAbility || isFlyingType) && !gSpeciesInfo[species].isSkyBattleBanned)
            return TRUE;
    }
    return FALSE;
}

void GetBattlerTypes(enum BattlerId battler, bool32 ignoreTera, enum Type types[static 3])
{
    // Terastallization.
    bool32 isTera = GetActiveGimmick(battler) == GIMMICK_TERA;
    if (!ignoreTera && isTera)
    {
        enum Type teraType = GetBattlerTeraType(battler);
        if (teraType != TYPE_STELLAR)
        {
            types[0] = types[1] = types[2] = teraType;
            return;
        }
    }

    types[0] = gBattleMons[battler].types[0];
    types[1] = gBattleMons[battler].types[1];
    types[2] = gBattleMons[battler].types[2];

    // Roost.
    if (!isTera && gBattleMons[battler].volatiles.roostActive)
    {
        if (types[0] == TYPE_FLYING && types[1] == TYPE_FLYING)
            types[0] = types[1] = B_ROOST_PURE_FLYING >= GEN_5 ? TYPE_NORMAL : TYPE_MYSTERY;
        else if (types[0] == TYPE_FLYING)
            types[0] = TYPE_MYSTERY;
        else if (types[1] == TYPE_FLYING)
            types[1] = TYPE_MYSTERY;
    }
}

void RemoveBattlerType(enum BattlerId battler, enum Type type)
{
    u32 i;
    if (GetActiveGimmick(battler) == GIMMICK_TERA) // don't remove type if Terastallized
        return;
    for (i = 0; i < 3; i++)
    {
        if (*(u8 *)(&gBattleMons[battler].types[0] + i) == type)
            *(u8 *)(&gBattleMons[battler].types[0] + i) = TYPE_MYSTERY;
    }
}

void SetShellSideArmCategory(void)
{
    enum BattlerId battlerAtk, battlerDef;
    u32 attackerAtkStat;
    u32 targetDefStat;
    u32 attackerSpAtkStat;
    u32 targetSpDefStat;
    u8 statStage;
    u32 physical;
    u32 special;
    u32 power = GetMovePower(MOVE_SHELL_SIDE_ARM);

    // Don't run this check for Safari Battles. Because player's stats are zeroed out, this performs division by zero which previously would crash on certain emulators in Safari Zone.
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return;

    for (battlerAtk = 0; battlerAtk < gBattlersCount; battlerAtk++)
    {
        attackerAtkStat = gBattleMons[battlerAtk].attack;
        statStage = gBattleMons[battlerAtk].statStages[STAT_ATK];
        attackerAtkStat *= gStatStageRatios[statStage][0];
        attackerAtkStat /= gStatStageRatios[statStage][1];

        attackerSpAtkStat = gBattleMons[battlerAtk].spAttack;
        statStage = gBattleMons[battlerAtk].statStages[STAT_SPATK];
        attackerSpAtkStat *= gStatStageRatios[statStage][0];
        attackerSpAtkStat /= gStatStageRatios[statStage][1];

        for (battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
        {
            if (battlerAtk == battlerDef)
                continue;

            targetDefStat = gBattleMons[battlerDef].defense;
            statStage = gBattleMons[battlerDef].statStages[STAT_DEF];
            targetDefStat *= gStatStageRatios[statStage][0];
            targetDefStat /= gStatStageRatios[statStage][1];
            if (targetDefStat == 0)
                targetDefStat = 1;

            physical = ((((2 * gBattleMons[battlerAtk].level / 5 + 2) * power * attackerAtkStat) / targetDefStat) / 50);

            targetSpDefStat = gBattleMons[battlerDef].spDefense;
            statStage = gBattleMons[battlerDef].statStages[STAT_SPDEF];
            targetSpDefStat *= gStatStageRatios[statStage][0];
            targetSpDefStat /= gStatStageRatios[statStage][1];
            if (targetSpDefStat == 0)
                targetSpDefStat = 1;

            special = ((((2 * gBattleMons[battlerAtk].level / 5 + 2) * power * attackerSpAtkStat) / targetSpDefStat) / 50);

            if ((physical > special) || (physical == special && RandomPercentage(RNG_SHELL_SIDE_ARM, 50)))
                gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] = DAMAGE_CATEGORY_PHYSICAL;
            else
                gBattleStruct->shellSideArmCategory[battlerAtk][battlerDef] = DAMAGE_CATEGORY_SPECIAL;
        }
    }
}

bool32 CanTargetPartner(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return (IsDoubleBattle()
         && IsBattlerAlive(GetPartnerBattler(battlerDef))
         && battlerDef != GetPartnerBattler(battlerAtk));
}

bool32 IsBattlerUnaffectedByMove(enum BattlerId battler)
{
    return gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_NO_EFFECT;
}

enum Type GetBattleMoveType(enum Move move)
{
    if (gMain.inBattle)
    {
        if (gBattleStruct->dynamicMoveType != TYPE_NONE)
            return gBattleStruct->dynamicMoveType;

        enum BattleMoveEffects effect = GetMoveEffect(move);
        if (B_UPDATED_MOVE_TYPES < GEN_5
         && (effect == EFFECT_BEAT_UP || effect == EFFECT_FUTURE_SIGHT))
          return TYPE_MYSTERY;
    }
    return GetMoveType(move);
}

void TryActivateSleepClause(enum BattlerId battler, u32 indexInParty)
{
    if (gBattleStruct->battlerState[battler].sleepClauseEffectExempt)
    {
        gBattleStruct->battlerState[battler].sleepClauseEffectExempt = FALSE;
        return;
    }

    if (IsSleepClauseEnabled())
    {
        enum BattleSide side = GetBattlerSide(battler);
        struct SleepClause *monCausingSleepClause = &gBattleStruct->monCausingSleepClause[side];
        monCausingSleepClause->partyIndex = indexInParty;
        monCausingSleepClause->trainer = GetBattlerTrainer(battler);
    }
}

void TryDeactivateSleepClause(enum BattlerId battler, u32 indexInParty)
{
    enum BattleSide side = GetBattlerSide(battler);
    struct SleepClause *monCausingSleepClause = &gBattleStruct->monCausingSleepClause[side];
    // If the Pokémon on the given side and trainer party at the given index in the party is the one causing Sleep Clause to be
    // active, set monCausingSleepClause->partyIndex = PARTY_SIZE, which means Sleep Clause is not active for the given side
    if (IsSleepClauseEnabled()
     && monCausingSleepClause->partyIndex == indexInParty
     && monCausingSleepClause->trainer == GetBattlerTrainer(battler))
    {
        monCausingSleepClause->partyIndex = PARTY_SIZE;
        monCausingSleepClause->trainer = MAX_BATTLE_TRAINERS;
    }
}

bool32 IsSleepClauseActiveForSide(enum BattleSide battlerSide)
{
    // If monCausingSleepClause[battlerSide].partyIndex == PARTY_SIZE, Sleep Clause is not active for the given side.
    // If monCausingSleepClause[battlerSide].partyIndex < PARTY_SIZE, it means it is storing the index of the mon that is causing Sleep Clause to be active,
    // from which it follows that Sleep Clause is active.
    return (IsSleepClauseEnabled() && (gBattleStruct->monCausingSleepClause[battlerSide].partyIndex < PARTY_SIZE));
}

bool32 IsSleepClauseEnabled(void)
{
    if (B_SLEEP_CLAUSE)
        return TRUE;
    if (FlagGet(B_FLAG_SLEEP_CLAUSE))
        return TRUE;
    return FALSE;
}

bool32 AreMultiPartiesFullTeams(void)
{
#if TESTING
    u8 *partySizes = gBattleTestRunnerState->data.partySizes;
    bool32 fullTeam = FALSE;

    if (partySizes[B_TRAINER_PLAYER] && partySizes[B_TRAINER_PARTNER]
        && (partySizes[B_TRAINER_PLAYER] > MULTI_PARTY_SIZE || partySizes[B_TRAINER_PARTNER] > MULTI_PARTY_SIZE))
    {
        fullTeam = TRUE;
    }
    if (partySizes[B_TRAINER_OPPONENT_A] && partySizes[B_TRAINER_OPPONENT_B]
        && (partySizes[B_TRAINER_OPPONENT_A] > MULTI_PARTY_SIZE || partySizes[B_TRAINER_OPPONENT_B] > MULTI_PARTY_SIZE))
    {
        fullTeam = TRUE;
    }

    if (!fullTeam)
    {
        gSpecialVar_Result = FALSE;
        return FALSE;
    }
#else
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (B_MULTI_HALF_TEAMS)
		return FALSE;

	if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
		return TRUE;
		
    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
     || gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI
     || (gTrainers[difficulty][TRAINER_BATTLE_PARAM.opponentA].multiTeamSize == MULTI_TEAM_SIZE_HALF)
     || (gTrainers[difficulty][TRAINER_BATTLE_PARAM.opponentB].multiTeamSize == MULTI_TEAM_SIZE_HALF))
    {
        gSpecialVar_Result = FALSE;
        return FALSE;
    }
#endif

    gSpecialVar_Result = TRUE;
    return TRUE;
}

void ClearDamageCalcResults(void)
{
    for (enum BattlerId battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
    {
        gBattleStruct->moveDamage[battler] = 0;
        gBattleStruct->innardsOutHpLost[battler] = 0;
        gBattleStruct->moveResultFlags[battler] = 0;
        gBattleStruct->passiveHpUpdate[battler] = 0;
        gSpecialStatuses[battler].criticalHit = FALSE;
        gSpecialStatuses[battler].damagedByAttack = FALSE;
    }

    gBattleStruct->numSpreadTargets = 0;
    gBattleStruct->unableToUseMove = FALSE;
    gBattleStruct->attackAnimPlayed = FALSE;
    gBattleScripting.savedDmg = 0;
    if (gCurrentMove != MOVE_NONE)
        gBattleStruct->moldBreakerActive = IsMoldBreakerTypeAbility(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), gCurrentMove) || MoveIgnoresTargetAbility(gCurrentMove);
    else
        gBattleStruct->moldBreakerActive = FALSE;
}

bool32 DoesDestinyBondFail(enum BattlerId battler)
{
    return GetConfig(B_DESTINY_BOND_FAIL) >= GEN_7 && gBattleMons[battler].volatiles.destinyBond;
}

// This check has always to be the last in a condtion statement because of the recording of AI data.
bool32 IsMoveEffectBlockedByTarget(enum Ability ability)
{
    if (ability == ABILITY_SHIELD_DUST)
    {
        RecordAbilityBattle(gBattlerTarget, ability);
        return TRUE;
    }
    else if (GetBattlerHoldEffect(gBattlerTarget) == HOLD_EFFECT_COVERT_CLOAK)
    {
        RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_COVERT_CLOAK);
        return TRUE;
    }

    return FALSE;
}

bool32 SetTargetToNextPursuiter(enum BattlerId battlerDef)
{
    u32 i;
    for (i = gCurrentTurnActionNumber + 1; i < gBattlersCount; i++)
    {
        enum BattlerId battler = gBattlerByTurnOrder[i];
        if (gChosenActionByBattler[battler] == B_ACTION_USE_MOVE
        && GetMoveEffect(gChosenMoveByBattler[battler]) == EFFECT_PURSUIT
        && IsBattlerAlive(battlerDef)
        && IsBattlerAlive(battler)
        && !IsBattlerAlly(battler, battlerDef)
        && (B_PURSUIT_TARGET >= GEN_4 || gBattleStruct->moveTarget[battler] == battlerDef)
        && !IsGimmickSelected(battler, GIMMICK_Z_MOVE)
        && !IsGimmickSelected(battler, GIMMICK_DYNAMAX)
        && GetActiveGimmick(battler) != GIMMICK_DYNAMAX)
        {
            gBattlerTarget = battler;
            return TRUE;
        }
    }
    return FALSE;
}

bool32 IsPursuitTargetSet(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->battlerState[battler].pursuitTarget)
            return TRUE;
    }
    return FALSE;
}

void ClearPursuitValues(void)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleStruct->battlerState[i].pursuitTarget = FALSE;
    gBattleStruct->pursuitStoredSwitch = PARTY_SIZE;
}

void ClearPursuitValuesIfSet(enum BattlerId battler)
{
    if (gBattleStruct->battlerState[battler].pursuitTarget)
        ClearPursuitValues();
}

bool32 HasWeatherEffect(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        enum Ability ability = GetBattlerAbility(battler);
        switch (ability)
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

bool32 TrySwitchInEjectPack(enum EjectPackTiming timing)
{
    // Because sorting the battlers by speed takes lots of cycles, it's better to just check if any of the battlers has the Eject items.
    u32 ejectPackBattlers = 0;
    u32 numEjectPackBattlers = 0;

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].volatiles.tryEjectPack
         && IsBattlerAlive(i)
         && !IsBattlerInvolvedInSkyDrop(i)
         && GetBattlerHoldEffect(i) == HOLD_EFFECT_EJECT_PACK
         && gBattleMons[i].volatiles.semiInvulnerable != STATE_COMMANDER
         && gBattleStruct->battlerState[i].commanderSpecies == SPECIES_NONE
         && CanBattlerSwitch(i))
        {
            ejectPackBattlers |= 1u << i;
            numEjectPackBattlers++;
        }
    }

    if (numEjectPackBattlers == 0)
        return FALSE;

    enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
    if (numEjectPackBattlers > 1)
        SortBattlersBySpeed(battlers, FALSE);

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        enum BattlerId battler = battlers[i];

        if (!(ejectPackBattlers & 1u << battler))
            continue;

        gBattleScripting.battler = battler;
        gLastUsedItem = gBattleMons[battler].item;
        if (timing != END_TURN)
        {
            BattleScriptCall(BattleScript_EjectPackActivates_SendReplacement);
        }
        else
        {
            gSpecialStatuses[battler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
            BattleScriptCall(BattleScript_EjectItemActivates);
        }
        gAiLogicData->ejectPackSwitch = TRUE;
        return TRUE;
    }

    return FALSE;
}

bool32 EmergencyExitCanBeTriggered(enum BattlerId battler, enum Ability ability)
{
    if (ability != ABILITY_EMERGENCY_EXIT && ability != ABILITY_WIMP_OUT)
        return FALSE;

    if (IsBattlerAlive(battler)
     && !IsPursuitTargetSet()
     && gBattleStruct->battlerState[battler].commanderSpecies == SPECIES_NONE
     && (HadMoreThanHalfHpNowDoesnt(battler) || gSpecialStatuses[battler].shellBellEmergencyExit)
     && (CanBattlerSwitch(battler) || !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
     && !(gBattleTypeFlags & BATTLE_TYPE_ARENA)
     && gBattleMons[battler].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET)
        return TRUE;

    return FALSE;
}

bool32 TryTriggerSymbiosis(enum BattlerId battler, u32 ally)
{
    return GetBattlerAbility(ally) == ABILITY_SYMBIOSIS
        && gBattleMons[battler].item == ITEM_NONE
        && gBattleMons[ally].item != ITEM_NONE
        && CanBattlerGetOrLoseItem(battler, ally, gBattleMons[ally].item)
        && CanBattlerGetOrLoseItem(ally, battler, gBattleMons[ally].item)
        && IsBattlerAlive(battler)
        && IsBattlerAlive(ally);
}

// itemId represents the item that was removed, not the item being given.
bool32 TrySymbiosis(enum BattlerId battler, enum Item itemId, const u8 *nextInstr)
{
    if (GetItemHoldEffect(itemId) != HOLD_EFFECT_EJECT_BUTTON
     && GetItemHoldEffect(itemId) != HOLD_EFFECT_EJECT_PACK
     && (GetConfig(B_SYMBIOSIS_GEMS) < GEN_7 || !(gSpecialStatuses[battler].gemBoost))
     && !gSpecialStatuses[battler].berryReduced //Fling and damage-reducing berries are handled separately.
     && TryTriggerSymbiosis(battler, GetPartnerBattler(battler)))
    {
        BestowItem(GetPartnerBattler(battler), battler);
        gLastUsedAbility = gBattleMons[GetPartnerBattler(battler)].ability;
        gEffectBattler = battler;
        gBattleScripting.battler = gBattlerAbility = GetPartnerBattler(battler);
        if (nextInstr == NULL)
            BattleScriptPushCursor();
        else
            BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
        return TRUE;
    }
    return FALSE;
}

// Used by Bestow and Symbiosis to take an item from one battler and give to another.
void BestowItem(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    gLastUsedItem = gBattleMons[battlerAtk].item;

    gBattleMons[battlerAtk].item = ITEM_NONE;
    BtlController_EmitSetMonData(battlerAtk, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerAtk].item), &gBattleMons[battlerAtk].item);
    MarkBattlerForControllerExec(battlerAtk);
    CheckSetUnburden(battlerAtk);

    gBattleMons[battlerDef].item = gLastUsedItem;
    BtlController_EmitSetMonData(battlerDef, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerDef].item), &gBattleMons[battlerDef].item);
    MarkBattlerForControllerExec(battlerDef);
    gBattleMons[battlerDef].volatiles.unburdenActive = FALSE;
}

#define UNPACK_VOLATILE_GETTERS(_enum, _fieldName, _typeMaxValue, ...) case _enum: return gBattleMons[battler].volatiles._fieldName;

// Gets the value of a volatile status flag for a certain battler
// Primarily used for the debug menu and scripts. Outside of it explicit references are preferred
// Uses Arm because there is a compiler bug when it tries to compile in thumb
ARM_FUNC u32 GetBattlerVolatile(enum BattlerId battler, enum Volatile _volatile)
{
    switch (_volatile)
    {
    VOLATILE_DEFINITIONS(UNPACK_VOLATILE_GETTERS)
    /* Expands to:
    case VOLATILE_CONFUSION:
        return gBattleMons[battler].volatiles.confusionTimer;
    */
    default: // Invalid volatile status
        return 0;
    }
}

#define UNPACK_VOLATILE_SETTERS(_enum, _fieldName, _typeMaxValue, ...) case _enum: gBattleMons[battler].volatiles._fieldName = min(GET_VOLATILE_MAXIMUM(_typeMaxValue), newValue); break;

// Sets the value of a volatile status flag for a certain battler
// Primarily used for the debug menu and scripts. Outside of it explicit references are preferred
void SetMonVolatile(enum BattlerId battler, enum Volatile _volatile, u32 newValue)
{
    switch (_volatile)
    {
        VOLATILE_DEFINITIONS(UNPACK_VOLATILE_SETTERS)
        /* Expands to:
    case VOLATILE_CONFUSION:
            gBattleMons[battler].volatiles.confusionTimer = min(MAX_BITS(3), newValue);
            break;
        */
    default: // Invalid volatile status
            return;
    }
}

bool32 ItemHealMonVolatile(enum BattlerId battler, enum Item itemId)
{
    bool32 statusChanged = FALSE;
    const u8 *effect = GetItemEffect(itemId);
    if (effect[3] & ITEM3_STATUS_ALL)
    {
        statusChanged = (gBattleMons[battler].volatiles.infatuation || gBattleMons[battler].volatiles.confusionTimer > 0);
        gBattleMons[battler].volatiles.infatuation = 0;
        gBattleMons[battler].volatiles.confusionTimer = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_CONFUSION;
    }
    else if (effect[0] & ITEM0_INFATUATION)
    {
        statusChanged = !!gBattleMons[battler].volatiles.infatuation;
        gBattleMons[battler].volatiles.infatuation = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_INFATUATION;
    }
    else if (effect[3] & ITEM3_CONFUSION)
    {
        statusChanged = (gBattleMons[battler].volatiles.confusionTimer > 0);
        gBattleMons[battler].volatiles.confusionTimer = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_CONFUSION;
    }

    return statusChanged;
}

// Hazards are added to a queue and applied based in order (FIFO)
void PushHazardTypeToQueue(enum BattleSide side, enum Hazards hazardType)
{
    if (!IsHazardOnSide(side, hazardType)) // Failsafe
        gBattleStruct->hazardsQueue[side][gBattleStruct->numHazards[side]++] = hazardType;
}

bool32 IsHazardOnSide(enum BattleSide side, enum Hazards hazardType)
{
    for (u32 i = 0; i < HAZARDS_MAX_COUNT; i++)
    {
        if (gBattleStruct->hazardsQueue[side][i] == hazardType)
            return TRUE;
    }
    return FALSE;
}

bool32 AreAnyHazardsOnSide(enum BattleSide side)
{
    return gBattleStruct->numHazards[side] > 0;
}

bool32 IsHazardOnSideAndClear(enum BattleSide side, enum Hazards hazardType)
{
    for (u32 i = 0; i < HAZARDS_MAX_COUNT; i++)
    {
        if (gBattleStruct->hazardsQueue[side][i] == hazardType)
        {
            gBattleStruct->hazardsQueue[side][i] = HAZARDS_NONE;
            if (hazardType == HAZARDS_SPIKES)
                gSideTimers[side].spikesAmount = 0;
            else if (hazardType == HAZARDS_TOXIC_SPIKES)
                gSideTimers[side].toxicSpikesAmount = 0;
            return TRUE;
        }
    }
    return FALSE;
}

void RemoveHazardFromField(enum BattleSide side, enum Hazards hazardType)
{
    u32 i;
    for (i = 0; i < HAZARDS_MAX_COUNT; i++)
    {
        if (gBattleStruct->hazardsQueue[side][i] == hazardType)
        {
            gBattleStruct->hazardsQueue[side][i] = HAZARDS_NONE;
            gBattleStruct->numHazards[side]--;
            if (hazardType == HAZARDS_SPIKES)
                gSideTimers[side].spikesAmount = 0;
            else if (hazardType == HAZARDS_TOXIC_SPIKES)
                gSideTimers[side].toxicSpikesAmount = 0;
            break;
        }
    }
    while (i < HAZARDS_MAX_COUNT)
    {
        if (i + 1 == HAZARDS_MAX_COUNT)
        {
            gBattleStruct->hazardsQueue[side][i] = HAZARDS_NONE;
            break;
        }
        gBattleStruct->hazardsQueue[side][i] = gBattleStruct->hazardsQueue[side][i+1];
        i++;
    }
}

static bool32 CanMoveSkipAccuracyCheck(enum BattlerId battlerAtk, enum Move move)
{
    return MoveAlwaysHitsOnSameType(move) && IS_BATTLER_OF_TYPE(battlerAtk, GetMoveType(move));
}

bool32 CanMoveSkipAccuracyCalc(struct BattleCalcValues *cv, u32 weather, enum ResultOption option)
{
    bool32 effect = FALSE;
    enum BattlerId battlerAtk = cv->battlerAtk;
    enum BattlerId battlerDef = cv->battlerDef;
    enum Ability ability = ABILITY_NONE;
    enum BattlerId abilityBattler = battlerAtk;
    enum BattleMoveEffects moveEffect = GetMoveEffect(cv->move);
    bool32 shouldAvoidSkyDropBattlers = (moveEffect != EFFECT_SKY_DROP && IsBattlerInvolvedInSkyDrop(battlerDef));

    if (gBattleMons[battlerAtk].volatiles.battlerWithSureHit == battlerDef + 1
     || CanMoveSkipAccuracyCheck(battlerAtk, cv->move)
     || gBattleMons[battlerDef].volatiles.glaiveRush)
    {
        effect = TRUE;
    }
    else if (cv->abilities[battlerAtk] == ABILITY_NO_GUARD
          && gBattleMons[battlerDef].volatiles.semiInvulnerable != STATE_COMMANDER
          && !shouldAvoidSkyDropBattlers)
    {
        effect = TRUE;
        ability = ABILITY_NO_GUARD;
        abilityBattler = battlerAtk;
    }
    else if (cv->abilities[battlerDef] == ABILITY_NO_GUARD && !shouldAvoidSkyDropBattlers)
    {
        effect = TRUE;
        ability = ABILITY_NO_GUARD;
        abilityBattler = battlerDef;
    }
    // If the target is under the effects of Telekinesis, and the move isn't a OH-KO move, move hits.
    else if (gBattleMons[battlerDef].volatiles.telekinesis
          && !IsSemiInvulnerable(battlerDef, CHECK_ALL)
          && moveEffect != EFFECT_OHKO)
    {
        effect = TRUE;
    }
    else if (gBattleStruct->battlerState[battlerDef].pursuitTarget)
    {
        effect = TRUE;
    }
    else if (GetActiveGimmick(battlerAtk) == GIMMICK_Z_MOVE && !IsSemiInvulnerable(battlerDef, CHECK_ALL))
    {
        effect = TRUE;
    }
    else if (B_MINIMIZE_DMG_ACC >= GEN_6
     && gBattleMons[battlerDef].volatiles.minimize
     && MoveIncreasesPowerToMinimizedTargets(cv->move))
    {
        effect = TRUE;
    }
    else if (GetMoveAccuracy(cv->move) == 0)
    {
        effect = TRUE;
    }
    else
    {
        u32 attackerWeather = GetAttackerWeather(cv->holdEffects[battlerAtk], cv->abilities[battlerAtk], weather);

        if ((attackerWeather & B_WEATHER_RAIN) && MoveAlwaysHitsInRain(cv->move))
            effect = TRUE;
        else if ((attackerWeather & B_WEATHER_ICY_ANY) && MoveAlwaysHitsInHailSnow(cv->move))
            effect = TRUE;

        if (effect)
            return effect;
    }

    if (ability != ABILITY_NONE && option == RUN_SCRIPT)
        RecordAbilityBattle(abilityBattler, ability);

    return effect;
}

u32 GetTotalAccuracy(struct BattleCalcValues *cv, u32 weather)
{
    s32 buff, accStage, evasionStage;

    enum BattlerId battlerAtk = cv->battlerAtk;
    enum BattlerId battlerDef = cv->battlerDef;

    u32 atkParam = GetBattlerHoldEffectParam(battlerAtk);
    u32 defParam = GetBattlerHoldEffectParam(battlerDef);

    gPotentialItemEffectBattler = battlerDef;

    accStage = gBattleMons[battlerAtk].statStages[STAT_ACC];
    evasionStage = gBattleMons[battlerDef].statStages[STAT_EVASION];

    if (cv->abilities[battlerAtk] == ABILITY_UNAWARE
     || cv->abilities[battlerAtk] == ABILITY_KEEN_EYE
     || cv->abilities[battlerAtk] == ABILITY_MINDS_EYE
     || (GetConfig(B_ILLUMINATE_EFFECT) >= GEN_9 && cv->abilities[battlerAtk] == ABILITY_ILLUMINATE))
        evasionStage = DEFAULT_STAT_STAGE;
    if (MoveIgnoresDefenseEvasionStages(cv->move))
        evasionStage = DEFAULT_STAT_STAGE;
    if (cv->abilities[battlerDef] == ABILITY_UNAWARE)
        accStage = DEFAULT_STAT_STAGE;

    if (gBattleMons[battlerDef].volatiles.foresight || gBattleMons[battlerDef].volatiles.miracleEye)
        buff = accStage;
    else
        buff = accStage + DEFAULT_STAT_STAGE - evasionStage;

    if (buff < MIN_STAT_STAGE)
        buff = MIN_STAT_STAGE;
    if (buff > MAX_STAT_STAGE)
        buff = MAX_STAT_STAGE;

    u32 moveAcc = GetMoveAccuracy(cv->move);
    u32 attackerWeather = GetAttackerWeather(cv->holdEffects[battlerAtk], cv->abilities[battlerAtk], weather);

    // Check Thunder and Hurricane on sunny weather.
    if ((attackerWeather & B_WEATHER_SUN) && MoveHas50AccuracyInSun(cv->move))
        moveAcc = 50;
    // Check Wonder Skin.
    if (cv->abilities[battlerDef] == ABILITY_WONDER_SKIN && IsBattleMoveStatus(cv->move) && moveAcc > 50)
        moveAcc = 50;

    u32 calc = gAccuracyStageRatios[buff].dividend * moveAcc;
    calc /= gAccuracyStageRatios[buff].divisor;

    // Attacker's ability
    switch (cv->abilities[battlerAtk])
    {
    case ABILITY_COMPOUND_EYES:
        calc = (calc * 130) / 100; // 1.3 compound eyes boost
        break;
    case ABILITY_VICTORY_STAR:
        calc = (calc * 110) / 100; // 1.1 victory star boost
        break;
    case ABILITY_HUSTLE:
        if (IsBattleMovePhysical(cv->move))
            calc = (calc * 80) / 100; // 1.2 hustle loss
        break;
    default:
        break;
    }

    // Target's ability
    switch (cv->abilities[battlerDef])
    {
    case ABILITY_SAND_VEIL:
        if (attackerWeather & B_WEATHER_SANDSTORM)
            calc = (calc * 80) / 100; // 1.2 sand veil loss
        break;
    case ABILITY_SNOW_CLOAK:
        if (attackerWeather & B_WEATHER_ICY_ANY)
            calc = (calc * 80) / 100; // 1.2 snow cloak loss
        break;
    case ABILITY_TANGLED_FEET:
        if (gBattleMons[battlerDef].volatiles.confusionTimer)
            calc = (calc * 50) / 100; // 1.5 tangled feet loss
        break;
    default:
        break;
    }

    // Attacker's ally's ability
    enum BattlerId atkAlly = GetPartnerBattler(battlerAtk);
    switch (cv->abilities[atkAlly])
    {
    case ABILITY_VICTORY_STAR:
        if (IsBattlerAlive(atkAlly))
            calc = (calc * 110) / 100; // 1.1 ally's victory star boost
        break;
    default:
        break;
    }

    if (MoveDecreasesAccIfUserNotSameType(cv->move) && !IS_BATTLER_OF_TYPE(battlerAtk, GetBattleMoveType(cv->move)))
        calc = (calc * 90) / 100;

    // Attacker's hold effect
    switch (cv->holdEffects[battlerAtk])
    {
    case HOLD_EFFECT_WIDE_LENS:
        calc = (calc * (100 + atkParam)) / 100;
        break;
    case HOLD_EFFECT_ZOOM_LENS:
        if (HasBattlerActedThisTurn(battlerDef) && !BattlerJustSwitchedIn(battlerDef))
            calc = (calc * (100 + atkParam)) / 100;
        break;
    default:
        break;
    }

    // Target's hold effect
    switch (cv->holdEffects[battlerDef])
    {
    case HOLD_EFFECT_EVASION_UP:
        calc = (calc * (100 - defParam)) / 100;
        break;
    default:
        break;
    }

    if (gBattleStruct->battlerState[battlerAtk].usedMicleBerry)
        calc = (calc * 120) / 100;  // 20% acc boost

    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        calc = (calc * 5) / 3; // 1.66 Gravity acc boost

    if (B_AFFECTION_MECHANICS == TRUE && GetBattlerAffectionHearts(battlerDef) == AFFECTION_FIVE_HEARTS)
        calc = (calc * 90) / 100;

    if (weather & B_WEATHER_FOG)
        calc = (calc * 60) / 100; // modified by 3/5

    return calc;
}

bool32 DoesOHKOMoveMissTarget(struct BattleCalcValues *cv)
{
    enum OHKOResult {
        NO_HIT,
        CALC_ACC,
        SURE_HIT,
    };

    // Dynamaxed Pokemon cannot be hit by OHKO moves.
    if (GetActiveGimmick(cv->battlerDef) == GIMMICK_DYNAMAX)
    {
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_ONE_HIT_KO_NO_AFFECT;
        return TRUE;
    }

    if (gBattleMons[cv->battlerDef].level > gBattleMons[cv->battlerAtk].level)
    {
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_ONE_HIT_KO_NO_AFFECT;
        return TRUE;
    }

    if (cv->abilities[cv->battlerDef] == ABILITY_STURDY)
    {
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_ONE_HIT_KO_STURDY;
        return TRUE;
    }

    enum OHKOResult lands = NO_HIT;

    if (gBattleMons[cv->battlerDef].volatiles.glaiveRush
     || gBattleMons[cv->battlerAtk].volatiles.battlerWithSureHit == cv->battlerDef + 1
     || IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_NO_GUARD)
     || IsAbilityAndRecord(cv->battlerDef, cv->abilities[cv->battlerDef], ABILITY_NO_GUARD))
    {
        lands = SURE_HIT;
    }
    else
    {
        lands = CALC_ACC;
    }

    if (lands == CALC_ACC)
    {
        u32 odds = GetMoveAccuracy(cv->move) + (gBattleMons[cv->battlerAtk].level - gBattleMons[cv->battlerDef].level);
        if (MoveDecreasesAccIfUserNotSameType(cv->move) && !IS_BATTLER_OF_TYPE(cv->battlerAtk, GetBattleMoveType(cv->move)))
            odds -= 10;
        if (RandomPercentage(RNG_ACCURACY, odds) && gBattleMons[cv->battlerAtk].level >= gBattleMons[cv->battlerDef].level)
            lands = SURE_HIT;
    }

    if (lands == SURE_HIT)
    {
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_ONE_HIT_KO_NO_AFFECT;
        return FALSE;
    }

    return TRUE;
}

bool32 DoesMoveMissTarget(struct BattleCalcValues *cv)
{
    if (GetMoveEffect(cv->move) == EFFECT_OHKO)
        return DoesOHKOMoveMissTarget(cv);

    u32 weather = GetWeather();

    if (CanMoveSkipAccuracyCalc(cv, weather, RUN_SCRIPT))
        return FALSE;

    u32 accuracy = GetTotalAccuracy(cv, weather);

    return !RandomPercentage(RNG_ACCURACY, accuracy);
}

bool32 IsSemiInvulnerable(enum BattlerId battler, enum SemiInvulnerableExclusion excludeCommander)
{
    if (gBattleMons[battler].volatiles.semiInvulnerable == STATE_COMMANDER)
        return excludeCommander != EXCLUDE_COMMANDER;
    return gBattleMons[battler].volatiles.semiInvulnerable != STATE_NONE;
}

static bool32 CanBreakThroughSemiInvulnerablityInternal(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Ability abilityDef, enum Move move, enum SemiInvulnerableState state)
{
    if (state != STATE_COMMANDER)
    {
        if (CanMoveSkipAccuracyCheck(battlerAtk, move))
            return TRUE;
        if (abilityAtk == ABILITY_NO_GUARD || abilityDef == ABILITY_NO_GUARD)
            return TRUE;
        if (gBattleMons[battlerAtk].volatiles.battlerWithSureHit == battlerDef + 1)
            return TRUE;
    }

    switch (state)
    {
    case STATE_UNDERGROUND:
        return MoveDamagesUnderground(move);
    case STATE_UNDERWATER:
        return MoveDamagesUnderWater(move);
    case STATE_ON_AIR:
    case STATE_SKY_DROP_ATTACKER:
    case STATE_SKY_DROP_TARGET:
        return MoveDamagesAirborne(move) || MoveDamagesAirborneDoubleDamage(move);
    case STATE_PHANTOM_FORCE:
        return FALSE;
    case STATE_COMMANDER:
        return GetMoveEffect(move) == EFFECT_TRANSFORM;
    case STATE_NONE:
    case SEMI_INVULNERABLE_COUNT:
        return TRUE;
    }

    return FALSE;
}

bool32 CanBreakThroughSemiInvulnerablity(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Ability abilityDef, enum Move move)
{
    return CanBreakThroughSemiInvulnerablityInternal(battlerAtk, battlerDef, abilityAtk, abilityDef, move, gBattleMons[battlerDef].volatiles.semiInvulnerable);
}

bool32 BreaksThroughSemiInvulnerableState(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Ability abilityAtk, enum Ability abilityDef, enum Move move, enum SemiInvulnerableState state)
{
    return CanBreakThroughSemiInvulnerablityInternal(battlerAtk, battlerDef, abilityAtk, abilityDef, move, state);
}

bool32 IsBattlerOnAir(enum BattlerId battler)
{
    switch (gBattleMons[battler].volatiles.semiInvulnerable)
    {
    case STATE_ON_AIR:
    case STATE_SKY_DROP_ATTACKER:
    case STATE_SKY_DROP_TARGET:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 HasPartnerTrainer(enum BattlerId battler)
{
    if ((GetBattlerSide(battler) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_PLAYER_HAS_PARTNER)
     || (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
        return TRUE;
    else
        return FALSE;
}

static bool32 IsOpposingSideEmpty(enum BattlerId battler)
{
    enum BattlerId oppositeBattler = GetOppositeBattler(battler);

    if (IsBattlerAlive(oppositeBattler))
        return FALSE;

    if (!IsDoubleBattle())
        return TRUE;

    if (IsBattlerAlive(GetPartnerBattler(oppositeBattler)))
        return FALSE;
    return TRUE;
}

bool32 IsAffectedByPowderMove(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect)
{
    if (GetConfig(B_POWDER_OVERCOAT) >= GEN_6 && ability == ABILITY_OVERCOAT)
        return FALSE;
    if (GetConfig(B_POWDER_GRASS) >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
        return FALSE;
    if (holdEffect == HOLD_EFFECT_SAFETY_GOGGLES)
        return FALSE;
    return TRUE;
}

void RemoveAbilityFlags(enum BattlerId battler)
{
    gBattleMons[battler].volatiles.unburdenActive = FALSE;
    gBattleMons[battler].volatiles.traceActivated = FALSE;

    switch (GetBattlerAbility(battler))
    {
    case ABILITY_FLASH_FIRE:
        gBattleMons[battler].volatiles.flashFireBoosted = FALSE;
        break;
    case ABILITY_VESSEL_OF_RUIN:
        gBattleMons[battler].volatiles.vesselOfRuin = FALSE;
        break;
    case ABILITY_TABLETS_OF_RUIN:
        gBattleMons[battler].volatiles.tabletsOfRuin = FALSE;
        break;
    case ABILITY_SWORD_OF_RUIN:
        gBattleMons[battler].volatiles.swordOfRuin = FALSE;
        break;
    case ABILITY_BEADS_OF_RUIN:
        gBattleMons[battler].volatiles.beadsOfRuin = FALSE;
        break;
    default:
       break;
    }
}

void RemoveRuinAbilityFlags(enum BattlerId battler)
{
    switch (GetBattlerAbility(battler))
    {
    case ABILITY_VESSEL_OF_RUIN:
        gBattleMons[battler].volatiles.vesselOfRuin = FALSE;
        break;
    case ABILITY_TABLETS_OF_RUIN:
        gBattleMons[battler].volatiles.tabletsOfRuin = FALSE;
        break;
    case ABILITY_SWORD_OF_RUIN:
        gBattleMons[battler].volatiles.swordOfRuin = FALSE;
        break;
    case ABILITY_BEADS_OF_RUIN:
        gBattleMons[battler].volatiles.beadsOfRuin = FALSE;
        break;
    default:
       break;
    }
}

void CheckSetUnburden(enum BattlerId battler)
{
    if (!(gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        && !gBattleMons[battler].volatiles.embargoTimer
        && IsAbilityAndRecord(battler, GetBattlerAbility(battler), ABILITY_UNBURDEN))
    {
        gBattleMons[battler].volatiles.unburdenActive = TRUE;
    }
}

bool32 IsAnyTargetTurnDamaged(enum BattlerId battlerAtk, enum SubCheck subCheck)
{
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (battlerDef == battlerAtk)
            continue;
        if (IsBattlerTurnDamaged(battlerDef, subCheck))
            return TRUE;
    }
    return FALSE;
}

bool32 IsAnyTargetAffected(void)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
    bool32 isSpreadMove = IsSpreadMove(moveTarget);

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_NOT_PRESENT)
            continue;

        switch (moveTarget)
        {
        case TARGET_ALL_BATTLERS: // check all battlers
            break;
        case TARGET_USER_AND_ALLY: // only check allied battlers
            if (!IsBattlerAlly(gBattlerAttacker, battler))
                continue;
            break;
        default:
            if (isSpreadMove) // check all battlers except attacker (flags are set for non-targeted battlers)
            {
                if (battler == gBattlerAttacker)
                    continue;
            }
            else // check a single target
            {
                if (battler != gBattlerTarget)
                    continue;
            }
            break;
        }

        if (!IsBattlerUnaffectedByMove(battler))
            return TRUE;
    }

    return FALSE;
}

bool32 IsDoubleSpreadMove(void)
{
    return gBattleStruct->numSpreadTargets > 1
        && !gBattleStruct->unableToUseMove
        && IsSpreadMove(GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove));
}

bool32 IsBattlerInvalidForSpreadMove(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return battlerDef == battlerAtk
        || !IsBattlerAlive(battlerDef)
        || IsBattlerUnaffectedByMove(battlerDef);
}

bool32 IsAllowedToUseBag(void)
{
    switch (VarGet(B_VAR_NO_BAG_USE))
    {
    case NO_BAG_RESTRICTION:
        return TRUE;
    case NO_BAG_AGAINST_TRAINER: //True in wild battle; False in trainer battle
        return (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER));
    case NO_BAG_IN_BATTLE:
        return FALSE;
    default:
        return TRUE; // Undefined Behavior
    }
}

bool32 IsMimikyuDisguised(enum BattlerId battler)
{
    return gBattleMons[battler].species == SPECIES_MIMIKYU_DISGUISED
        || gBattleMons[battler].species == SPECIES_MIMIKYU_TOTEM_DISGUISED;
}

#define UNPACK_STARTING_STATUS_TO_EWRAM(_enum, _fieldName, ...) case _enum: gStartingStatuses._fieldName = TRUE; break;

void SetStartingStatus(enum StartingStatus status)
{
    switch (status)
    {
    STARTING_STATUS_DEFINITIONS(UNPACK_STARTING_STATUS_TO_EWRAM);
    }
}

#define UNPACK_STARTING_STATUS_RESET(_enum, _fieldName, ...) gStartingStatuses._fieldName = FALSE;

void ResetStartingStatuses(void)
{
    STARTING_STATUS_DEFINITIONS(UNPACK_STARTING_STATUS_RESET);
}

bool32 IsUsableWhileAsleepEffect(enum BattleMoveEffects effect)
{
    // All moves usable while asleep like Snore, Sleep Talk, etc.
    switch (effect)
    {
    case EFFECT_SNORE:
    case EFFECT_SLEEP_TALK:
        return TRUE;
    default:
        return FALSE;
    }
}

void SetWrapTurns(enum BattlerId battler, enum HoldEffect holdEffect)
{
    u32 normalWrapTurns = B_WRAP_TURNS - 2; // 5 turns
    if (holdEffect == HOLD_EFFECT_GRIP_CLAW)
    {
        gBattleMons[battler].volatiles.wrapTurns = GetConfig(B_BINDING_TURNS) >= GEN_5 ? B_WRAP_TURNS : normalWrapTurns;
        gBattleMons[battler].volatiles.wrappedBindingBand = FALSE;
    }
    else
    {
        gBattleMons[battler].volatiles.wrapTurns = GetConfig(B_BINDING_TURNS) >= GEN_5 ? RandomUniform(RNG_WRAP, 4, normalWrapTurns) : RandomUniform(RNG_WRAP, 2, normalWrapTurns);
        gBattleMons[battler].volatiles.wrappedBindingBand = holdEffect == HOLD_EFFECT_BINDING_BAND;
    }
}

// Return True if the order was changed, and false if the order was not changed(for example because the target would move after the attacker anyway).
bool32 ChangeOrderTargetAfterAttacker(enum BattlerId battlerDef)
{
    u8 data[MAX_BATTLERS_COUNT];
    u8 actionsData[MAX_BATTLERS_COUNT];
    u32 attackerTurnOrderNum = GetBattlerTurnOrderNum(gBattlerAttacker);
    u32 targetTurnOrderNum = GetBattlerTurnOrderNum(battlerDef);

    if (attackerTurnOrderNum > targetTurnOrderNum)
        return FALSE;
    if (attackerTurnOrderNum + 1 == targetTurnOrderNum)
        return GetConfig(B_AFTER_YOU_TURN_ORDER) >= GEN_8;

    for (enum BattlerId i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        data[i] = gBattlerByTurnOrder[i];
        actionsData[i] = gActionsByTurnOrder[i];
    }
    if (attackerTurnOrderNum == 0 && targetTurnOrderNum == 2)
    {
        gBattlerByTurnOrder[1] = battlerDef;
        gActionsByTurnOrder[1] = actionsData[2];
        gBattlerByTurnOrder[2] = data[1];
        gActionsByTurnOrder[2] = actionsData[1];
    }
    else if (attackerTurnOrderNum == 0 && targetTurnOrderNum == 3)
    {
        gBattlerByTurnOrder[1] = battlerDef;
        gActionsByTurnOrder[1] = actionsData[3];
        gBattlerByTurnOrder[2] = data[1];
        gActionsByTurnOrder[2] = actionsData[1];
        gBattlerByTurnOrder[3] = data[2];
        gActionsByTurnOrder[3] = actionsData[2];
    }
    else // attackerTurnOrderNum == 1, targetTurnOrderNum == 3
    {
        gBattlerByTurnOrder[2] = battlerDef;
        gActionsByTurnOrder[2] = actionsData[3];
        gBattlerByTurnOrder[3] = data[2];
        gActionsByTurnOrder[3] = actionsData[2];
    }
    return TRUE;
}

void TryUpdateEvolutionTracker(enum EvolutionConditions evolutionCondition, u32 upAmount, enum Move usedMove)
{
    u32 i, j;

    if (IsOnPlayerSide(gBattlerAttacker)
     && ((TESTING && IsDoubleBattle()) // To be removed when Wild Double Battles are added to tests
     || !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                             | BATTLE_TYPE_EREADER_TRAINER
                             | BATTLE_TYPE_RECORDED_LINK
                             | BATTLE_TYPE_TRAINER_HILL
                             | BATTLE_TYPE_FRONTIER))))
    {
        const struct Evolution *evolutions = GetSpeciesEvolutions(gBattleMons[gBattlerAttacker].species);
        if (evolutions == NULL)
            return;

        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;
            if (evolutions[i].params == NULL)
                continue;

            for (j = 0; evolutions[i].params[j].condition != CONDITIONS_END; j++)
            {
                if (evolutions[i].params[j].condition != evolutionCondition)
                    continue;

                struct Pokemon *monAtk = GetBattlerMon(gBattlerAttacker);
                struct Pokemon *monDef = GetBattlerMon(gBattlerTarget);
                // We only have 10 bits to use
                u16 val = min(1023, GetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER) + upAmount);
                // Reset progress if you faint for the recoil method.
                switch (evolutionCondition)
                {
                case IF_USED_MOVE_X_TIMES:
                    if (evolutions[i].params[j].arg1 == usedMove)
                        SetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER, &val);
                    break;
                case IF_RECOIL_DAMAGE_GE:
                    if (gBattleMons[gBattlerAttacker].hp == 0)
                        val = 0;
                    SetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER, &val);
                    break;
                case IF_DEFEAT_X_WITH_ITEMS:
                    if (GetMonData(monDef, MON_DATA_SPECIES) == evolutions[i].params[j].arg1
                     && GetMonData(monDef, MON_DATA_HELD_ITEM) == evolutions[i].params[j].arg2)
                        SetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER, &val);
                    break;
                default:
                    assertf(FALSE, "evolution condition %d is not handled within TryUpdateEvolutionTracker", evolutionCondition) {}
                    break;
                }
                return;
            }
        }
    }
}

static const u16 sProtectFailChances[] =
{
    1,
    2,
    4,
    8
};

static const u16 sGen5ProtectFailChances[] =
{
    1,
    3,
    9,
    27
};

bool32 CanUseMoveConsecutively(enum BattlerId battler)
{
    u32 moveUses = gBattleMons[battler].volatiles.consecutiveMoveUses;
    if (moveUses >= ARRAY_COUNT(sProtectFailChances))
        moveUses = ARRAY_COUNT(sProtectFailChances) - 1;

    u32 failChances;

    if (B_PROTECT_FAILURE_RATE < GEN_5)
        failChances = sProtectFailChances[moveUses];
    else
        failChances = sGen5ProtectFailChances[moveUses];

    if (failChances == 1)
        return TRUE;

    return RandomUniform(RNG_PROTECT_FAIL, 1, failChances) == 1;
}

// Used for Protect, Endure and Ally switch
void TryResetConsecutiveUseCounter(enum BattlerId battler)
{
    enum Move lastMove = gLastResultingMoves[battler];
    if (lastMove == MOVE_UNAVAILABLE)
    {
        gBattleMons[battler].volatiles.consecutiveMoveUses = 0;
        return;
    }

    enum BattleMoveEffects lastEffect = GetMoveEffect(lastMove);
    if (!gBattleMoveEffects[lastEffect].usesProtectCounter)
    {
        if (GetConfig(B_ALLY_SWITCH_FAIL_CHANCE) < GEN_9 || lastEffect != EFFECT_ALLY_SWITCH)
            gBattleMons[battler].volatiles.consecutiveMoveUses = 0;
    }
}

void SetOrClearRageVolatile(void)
{
    if (GetConfig(B_RAGE_BUILDS) <= GEN_3 && MoveHasAdditionalEffectSelf(gCurrentMove, MOVE_EFFECT_RAGE))
        gBattleMons[gBattlerAttacker].volatiles.rage = TRUE;
    else
        gBattleMons[gBattlerAttacker].volatiles.rage = FALSE;
}

enum BattlerId GetTargetBySlot(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (IsDoubleBattle())
        return GetTargetFromSlotId(battlerAtk, battlerDef);
    return battlerDef;
}

enum BattlerId GetTargetFromSlotId(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    switch (battlerDef)
    {
    case B_BATTLER_0:
        return battlerAtk;
    case B_BATTLER_1:
        return GetPartnerBattler(battlerAtk);
    case B_BATTLER_2:
        return GetBattlerLeftFoe(battlerAtk);
    case B_BATTLER_3:
        return GetBattlerRightFoe(battlerAtk);
    default:
        errorf("Illegal battler");
        return B_BATTLER_0;
    }
}

bool32 IsNaturalEnemy(enum Species speciesAttacker, enum Species speciesTarget)
{
    if (WE_WILD_NATURAL_ENEMIES != TRUE)
        return FALSE;

    switch (speciesAttacker)
    {
    case SPECIES_ZANGOOSE:
        return (speciesTarget == SPECIES_SEVIPER);
    case SPECIES_SEVIPER:
        return (speciesTarget == SPECIES_ZANGOOSE);
    case SPECIES_HEATMOR:
        return (speciesTarget == SPECIES_DURANT);
    case SPECIES_DURANT:
        return (speciesTarget == SPECIES_HEATMOR);
    case SPECIES_SABLEYE:
        return (speciesTarget == SPECIES_CARBINK);
    case SPECIES_MAREANIE:
        return (speciesTarget == SPECIES_CORSOLA);
    default:
        return FALSE;
    }
    return FALSE;
}

enum Stat GetDownloadStat(enum BattlerId battler)
{
    enum BattlerId opposingBattler;
    u32 opposingDef = 0, opposingSpDef = 0;

    opposingBattler = GetOppositeBattler(battler);
    for (u32 i = 0; i < 2; opposingBattler ^= BIT_FLANK, i++)
    {
        if (IsBattlerAlive(opposingBattler))
        {
            opposingDef += gBattleMons[opposingBattler].defense
                        * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][0]
                        / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_DEF]][1];
            opposingSpDef += gBattleMons[opposingBattler].spDefense
                            * gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][0]
                            / gStatStageRatios[gBattleMons[opposingBattler].statStages[STAT_SPDEF]][1];
        }
    }

    if (opposingDef < opposingSpDef)
        return STAT_ATK;
    else
        return STAT_SPATK;
}

bool32 BattlerJustSwitchedIn(enum BattlerId battler)
{
    return gBattleStruct->battlerState[battler].isFirstTurn == 2;
}

bool32 IsBattlersFirstTurn(enum BattlerId battler)
{
    return gBattleStruct->battlerState[battler].isFirstTurn == 1
        || gBattleStruct->battlerState[battler].isFirstTurn == 2;
}

struct PartyState *GetBattlerPartyState(enum BattlerId battler)
{
    return &gBattleStruct->partyState[GetBattlerTrainer(battler)][gBattlerPartyIndexes[battler]];
}

void SetValuesOnFaint(enum BattlerId battler)
{
    gHitMarker |= HITMARKER_FAINTED(battler);
    gBattleStruct->eventState.faintedAction = 0;
    gBattlerFainted = battler;
    TryDeactivateSleepClause(battler, gBattlerPartyIndexes[battler]);

    if (gBattleStruct->faintCounter[GetBattlerTrainer(battler)] < 255)
        gBattleStruct->faintCounter[GetBattlerTrainer(battler)]++;

    if (IsOnPlayerSide(battler))
    {
        gHitMarker |= HITMARKER_PLAYER_FAINTED;
        if (gBattleResults.playerFaintCounter < 255)
            gBattleResults.playerFaintCounter++;
        AdjustFriendshipOnBattleFaint(battler);
        gSideTimers[B_SIDE_PLAYER].retaliateTimer = 2;
    }
    else
    {
        if (gBattleResults.opponentFaintCounter < 255)
            gBattleResults.opponentFaintCounter++;
        gBattleResults.lastOpponentSpecies = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);
        gSideTimers[B_SIDE_OPPONENT].retaliateTimer = 2;
    }
}

bool32 IsVictoryCatch(void)
{
    return gBattleTypeFlags & BATTLE_TYPE_RAID
        || FlagGet(B_FLAG_VICTORY_CATCH_RANDOM)
        || FlagGet(B_FLAG_VICTORY_CATCH_GUARANTEED);
}

bool32 IsVictoryCatchGuaranteed(void)
{
    return gBattleTypeFlags & BATTLE_TYPE_RAID
        || FlagGet(B_FLAG_VICTORY_CATCH_GUARANTEED);
}

bool32 IsBattlerInvolvedInSkyDrop(enum BattlerId battler)
{
    return gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_ATTACKER
        || gBattleMons[battler].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET;
}

bool32 IsAsleepOrComatose(enum BattlerId battler, enum Ability ability)
{
    return (gBattleMons[battler].status1 & STATUS1_SLEEP) || ability == ABILITY_COMATOSE;
}
