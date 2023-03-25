#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "data.h"
#include "graphics.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "sprite.h"
#include "string_util.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"

// Constant Data
static const u16 sMaxMoveTable[] =
{
    [TYPE_NORMAL] = MOVE_MAX_STRIKE,
    [TYPE_FIGHTING] = MOVE_MAX_KNUCKLE,
    [TYPE_FLYING] = MOVE_MAX_AIRSTREAM,
    [TYPE_POISON] = MOVE_MAX_OOZE,
    [TYPE_GROUND] = MOVE_MAX_QUAKE,
    [TYPE_ROCK] = MOVE_MAX_ROCKFALL,
    [TYPE_BUG] = MOVE_MAX_FLUTTERBY,
    [TYPE_GHOST] = MOVE_MAX_PHANTASM,
    [TYPE_STEEL] = MOVE_MAX_STEELSPIKE,
    [TYPE_FIRE] = MOVE_MAX_FLARE,
    [TYPE_WATER] = MOVE_MAX_GEYSER,
    [TYPE_GRASS] = MOVE_MAX_OVERGROWTH,
    [TYPE_ELECTRIC] = MOVE_MAX_LIGHTNING,
    [TYPE_PSYCHIC] = MOVE_MAX_MINDSTORM,
    [TYPE_ICE] = MOVE_MAX_HAILSTORM,
    [TYPE_DRAGON] = MOVE_MAX_WYRMWIND,
    [TYPE_DARK] = MOVE_MAX_DARKNESS,
    [TYPE_FAIRY] = MOVE_MAX_STARFALL,
};

struct GMaxMove
{
    u16 species;
    u8 moveType;
    u16 gmaxMove;
};

static const struct GMaxMove sGMaxMoveTable[] =
{
    {SPECIES_VENUSAUR_GMAX,	                    TYPE_GRASS,      MOVE_G_MAX_VINE_LASH},
    {SPECIES_BLASTOISE_GMAX,                    TYPE_WATER,      MOVE_G_MAX_CANNONADE},
    {SPECIES_CHARIZARD_GMAX,                    TYPE_FIRE,       MOVE_G_MAX_WILDFIRE},
    {SPECIES_BUTTERFREE_GMAX,                   TYPE_BUG,        MOVE_G_MAX_BEFUDDLE},
    {SPECIES_PIKACHU_GMAX,                      TYPE_ELECTRIC,   MOVE_G_MAX_VOLT_CRASH},
    {SPECIES_MEOWTH_GMAX,                       TYPE_NORMAL,     MOVE_G_MAX_GOLD_RUSH},
    {SPECIES_MACHAMP_GMAX,                      TYPE_FIGHTING,   MOVE_G_MAX_CHI_STRIKE},
    {SPECIES_GENGAR_GMAX,                       TYPE_GHOST,      MOVE_G_MAX_TERROR},
    {SPECIES_KINGLER_GMAX,                      TYPE_WATER,      MOVE_G_MAX_FOAM_BURST},
    {SPECIES_LAPRAS_GMAX,                       TYPE_ICE,        MOVE_G_MAX_RESONANCE},
    {SPECIES_EEVEE_GMAX,                        TYPE_NORMAL,     MOVE_G_MAX_CUDDLE},
    {SPECIES_SNORLAX_GMAX,                      TYPE_NORMAL,     MOVE_G_MAX_REPLENISH},
    {SPECIES_GARBODOR_GMAX,                     TYPE_POISON,     MOVE_G_MAX_MALODOR},
    {SPECIES_MELMETAL_GMAX,                     TYPE_STEEL,      MOVE_G_MAX_MELTDOWN},
    {SPECIES_RILLABOOM_GMAX,                    TYPE_GRASS,      MOVE_G_MAX_DRUM_SOLO},
    {SPECIES_CINDERACE_GMAX,                    TYPE_FIRE,       MOVE_G_MAX_FIREBALL},
    {SPECIES_INTELEON_GMAX,                     TYPE_WATER,      MOVE_G_MAX_HYDROSNIPE},
    {SPECIES_CORVIKNIGHT_GMAX,                  TYPE_FLYING,     MOVE_G_MAX_WIND_RAGE},
    {SPECIES_ORBEETLE_GMAX,                     TYPE_PSYCHIC,    MOVE_G_MAX_GRAVITAS},
    {SPECIES_DREDNAW_GMAX,                      TYPE_WATER,      MOVE_G_MAX_STONESURGE},
    {SPECIES_COALOSSAL_GMAX,                    TYPE_ROCK,       MOVE_G_MAX_VOLCALITH},
    {SPECIES_FLAPPLE_GMAX,                      TYPE_GRASS,      MOVE_G_MAX_TARTNESS},
    {SPECIES_APPLETUN_GMAX,                     TYPE_GRASS,      MOVE_G_MAX_SWEETNESS},
    {SPECIES_SANDACONDA_GMAX,                   TYPE_GROUND,     MOVE_G_MAX_SANDBLAST},
    {SPECIES_TOXTRICITY_GMAX,                   TYPE_ELECTRIC,   MOVE_G_MAX_STUN_SHOCK},
    {SPECIES_CENTISKORCH_GMAX,                  TYPE_FIRE,       MOVE_G_MAX_CENTIFERNO},
    {SPECIES_HATTERENE_GMAX,                    TYPE_FAIRY,      MOVE_G_MAX_SMITE},
    {SPECIES_GRIMMSNARL_GMAX,                   TYPE_DARK,       MOVE_G_MAX_SNOOZE},
    {SPECIES_ALCREMIE_GMAX,                     TYPE_FAIRY,      MOVE_G_MAX_FINALE},
    {SPECIES_COPPERAJAH_GMAX,                   TYPE_STEEL,      MOVE_G_MAX_STEELSURGE},
    {SPECIES_DURALUDON_GMAX,                    TYPE_DRAGON,     MOVE_G_MAX_DEPLETION},
    {SPECIES_URSHIFU_GMAX,                      TYPE_DARK,       MOVE_G_MAX_ONE_BLOW},
    {SPECIES_URSHIFU_RAPID_STRIKE_STYLE_GMAX,   TYPE_WATER,      MOVE_G_MAX_RAPID_FLOW},
};

// forward declarations
static void SpriteCb_DynamaxTrigger(struct Sprite *);
static void SpriteCb_DynamaxIndicator(struct Sprite *);

// Returns whether a battler is Dynamaxed.
bool32 IsDynamaxed(u16 battlerId)
{
    u8 side = GetBattlerSide(battlerId);
    if (gBattleStruct->dynamax.dynamaxed[battlerId]
        /*|| IsRaidBoss(battlerId)*/)
        return TRUE;
    return FALSE;
}

// Returns whether a battler can Dynamax.
bool32 CanDynamax(u16 battlerId)
{
    // TODO: Requires Dynamax Band if not in a Max Raid (as well as special flag).
    u16 species = gBattleMons[battlerId].species;
    u16 holdEffect = ItemId_GetHoldEffect(gBattleMons[battlerId].item);
    if (!gBattleStruct->dynamax.alreadyDynamaxed[GetBattlerSide(battlerId)]
         && !gBattleStruct->dynamax.dynamaxed[battlerId]
         && !gBattleStruct->dynamax.dynamaxed[BATTLE_PARTNER(battlerId)]
         && !gBattleStruct->dynamax.toDynamax[BATTLE_PARTNER(battlerId)]
         && species != SPECIES_ZACIAN && species != SPECIES_ZACIAN_CROWNED_SWORD
         && species != SPECIES_ZAMAZENTA && species != SPECIES_ZAMAZENTA_CROWNED_SHIELD
         && species != SPECIES_ETERNATUS && species != SPECIES_ETERNATUS_ETERNAMAX
         && holdEffect != HOLD_EFFECT_MEGA_STONE && holdEffect != HOLD_EFFECT_Z_CRYSTAL)
        return TRUE;
    return FALSE;
}

// Applies the HP Multiplier for Dynamaxed Pokemon and Raid Bosses.
void ApplyDynamaxHPMultiplier(u16 battlerId, struct Pokemon* mon)
{
    if (gBattleMons[battlerId].species == SPECIES_SHEDINJA)
    {
        return;
    }
    else
    {
        u16 mult = UQ_4_12(1.5); // placeholder
        u16 hp = UQ_4_12_TO_INT((gBattleMons[battlerId].hp * mult) + UQ_4_12_ROUND);
        u16 maxHP = UQ_4_12_TO_INT((gBattleMons[battlerId].maxHP * mult) + UQ_4_12_ROUND);
        SetMonData(mon, MON_DATA_HP, &hp);
        SetMonData(mon, MON_DATA_MAX_HP, &maxHP);
    }
}

// Returns the non-Dynamax HP of a Pokemon.
u16 GetNonDynamaxHP(u16 battlerId)
{
    if (!IsDynamaxed(battlerId) || gBattleMons[battlerId].species == SPECIES_SHEDINJA)
    {
        return gBattleMons[battlerId].hp;
    }
    else
    {
        u16 mult = UQ_4_12(1.0/1.5); // placeholder
        u16 hp = UQ_4_12_TO_INT((gBattleMons[battlerId].hp * mult) + UQ_4_12_ROUND);
        return hp;
    }
}

// Returns the non-Dynamax Max HP of a Pokemon.
u16 GetNonDynamaxMaxHP(u16 battlerId)
{
    if (!IsDynamaxed(battlerId) || gBattleMons[battlerId].species == SPECIES_SHEDINJA)
    {
        return gBattleMons[battlerId].maxHP;
    }
    else
    {
        u16 mult = UQ_4_12(1.0/1.5); // placeholder
        u16 maxHP = UQ_4_12_TO_INT((gBattleMons[battlerId].maxHP * mult) + UQ_4_12_ROUND);
        return maxHP;
    }
}

// Sets flags used for Dynamaxing and checks Gigantamax forms.
void PrepareBattlerForDynamax(u16 battlerId)
{
    u8 side = GetBattlerSide(battlerId);
    u16 newSpecies;

    gBattleStruct->dynamax.alreadyDynamaxed[side] = TRUE;
    gBattleStruct->dynamax.dynamaxed[battlerId] = TRUE;
    gBattleStruct->dynamax.dynamaxTurns[battlerId] = DYNAMAX_TURNS;

    // Substitute is removed upon Dynamaxing.
    gBattleMons[battlerId].status2 &= ~STATUS2_SUBSTITUTE;
    ClearBehindSubstituteBit(battlerId);

    // Choiced Moves are reset upon Dynamaxing.
    gBattleStruct->choicedMove[battlerId] = MOVE_NONE;

    // Try Gigantamax form change.
    TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_GIGANTAMAX);
}

// Unsets the flags used for Dynamaxing and reverts max HP if needed.
void UndoDynamax(u16 battlerId)
{
    u8 side = GetBattlerSide(battlerId);
    // Revert HP and try form reversion if battler is Dynamaxed.
    if (IsDynamaxed(battlerId))
    {
        struct Pokemon *party = (side == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
        u16 mult = UQ_4_12(1.0/1.5); // placeholder
        u16 hp = UQ_4_12_TO_INT((gBattleMons[battlerId].hp * mult + 1) + UQ_4_12_ROUND); // round up
        SetMonData(&party[gBattlerPartyIndexes[battlerId]], MON_DATA_HP, &hp);
        TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_SWITCH);
    }
    // Makes sure there are no Dynamax flags set, including on switch / faint.
    gBattleStruct->dynamax.dynamaxed[battlerId] = FALSE;
    gBattleStruct->dynamax.dynamaxTurns[battlerId] = 0;
}

// Weight-based moves (and some other moves in Raids) are blocked by Dynamax.
bool32 IsMoveBlockedByDynamax(u16 move)
{
    // TODO: Raid moves
    switch (gBattleMoves[move].effect)
    {
        case EFFECT_HEAT_CRASH:
        case EFFECT_LOW_KICK:
            return TRUE;
    }
    return FALSE;
}

// Returns whether a move should be converted into a Max Move.
bool32 ShouldUseMaxMove(u16 battlerId, u16 baseMove)
{
    // TODO: Raids
    //if (IsRaidBoss(battlerId))
    //	return !IsRaidBossUsingRegularMove(battlerId, baseMove);
    return IsDynamaxed(battlerId) || gBattleStruct->dynamax.toDynamax[battlerId];
}

static u16 GetTypeBasedMaxMove(u16 battlerId, u16 type)
{
    u32 species;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL);
    else
        species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL);

    // Gigantamax check
    if (species >= (SPECIES_VENUSAUR_GMAX)
        && sGMaxMoveTable[species - (SPECIES_VENUSAUR_GMAX)].moveType == type)
        return sGMaxMoveTable[species - (SPECIES_VENUSAUR_GMAX)].gmaxMove;

    // regular Max Move
    else
    {
        return sMaxMoveTable[type];
    }
}

// Returns the appropriate Max Move or G-Max Move for a battler to use.
u16 GetMaxMove(u16 battlerId, u16 baseMove)
{
    u16 move = baseMove;
    if (baseMove == MOVE_NONE) // for move display
    {
        return MOVE_NONE;
    }
    else if (baseMove == MOVE_STRUGGLE)
    {
        return MOVE_STRUGGLE;
    }
    else if (gBattleMoves[baseMove].split == SPLIT_STATUS)
    {
        move = MOVE_MAX_GUARD;
    }
    else if (gBattleStruct->dynamicMoveType) // unsure of how to deal with Hidden Power
    {
        move = GetTypeBasedMaxMove(battlerId, gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK);
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
    }
    else
    {
        move = GetTypeBasedMaxMove(battlerId, gBattleMoves[baseMove].type);
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
    }

    return move;
}

// Gets the base power of a Max Move.
u8 GetMaxMovePower(u16 move)
{
    // G-Max Drum Solo, G-Max Hydrosnipe, and G-Max Fireball always have 160 base power. 
    if (gBattleMoves[GetMaxMove(gBattlerAttacker, move)].argument == MAX_EFFECT_FIXED_POWER)
        return 160;
    
    // Some moves are exceptions to the general rules below.
    switch (move)
    {
        case MOVE_CRUSH_GRIP:
        case MOVE_WRING_OUT:
        case MOVE_MAGNITUDE:
        case MOVE_DOUBLE_IRON_BASH:
        case MOVE_TRIPLE_AXEL:
            return 140;
        case MOVE_PIN_MISSILE:
        case MOVE_POWER_TRIP:
        case MOVE_PUNISHMENT:
        case MOVE_DRAGON_DARTS:
        case MOVE_DUAL_CHOP:
        case MOVE_ELECTRO_BALL:
        case MOVE_HEAT_CRASH:
        case MOVE_BULLET_SEED:
        case MOVE_GRASS_KNOT:
        case MOVE_BONEMERANG:
        case MOVE_BONE_RUSH:
        case MOVE_FISSURE:
        case MOVE_ICICLE_SPEAR:
        case MOVE_SHEER_COLD:
        case MOVE_WEATHER_BALL:
        case MOVE_TAIL_SLAP:
        case MOVE_GUILLOTINE:
        case MOVE_HORN_DRILL:
        case MOVE_FLAIL:
        case MOVE_RETURN:
        case MOVE_FRUSTRATION:
        case MOVE_NATURAL_GIFT:
        case MOVE_TRUMP_CARD:
        case MOVE_STORED_POWER:
        case MOVE_ROCK_BLAST:
        case MOVE_GEAR_GRIND:
        case MOVE_GYRO_BALL:
        case MOVE_HEAVY_SLAM:
        case MOVE_DUAL_WINGBEAT:
        case MOVE_SCALE_SHOT:
        case MOVE_TERRAIN_PULSE:
            return 130;
        case MOVE_DOUBLE_HIT:
        case MOVE_SPIKE_CANNON:
            return 120;
        case MOVE_TWINEEDLE:
        case MOVE_BEAT_UP:
        case MOVE_FLING:
        case MOVE_DRAGON_RAGE:
        case MOVE_NATURES_MADNESS:
        case MOVE_NIGHT_SHADE:
        case MOVE_COMET_PUNCH:
        case MOVE_FURY_SWIPES:
        case MOVE_SONIC_BOOM:
        case MOVE_BIDE:
        case MOVE_SUPER_FANG:
        case MOVE_PRESENT:
        case MOVE_SPIT_UP:
        case MOVE_PSYWAVE:
        case MOVE_MIRROR_COAT:
        case MOVE_METAL_BURST:
        case MOVE_LOW_KICK:
        case MOVE_REVERSAL:
        case MOVE_FINAL_GAMBIT:
            return 100;
        case MOVE_DOUBLE_KICK:
        case MOVE_TRIPLE_KICK:
            return 80;
        case MOVE_COUNTER:
        case MOVE_SEISMIC_TOSS:
            return 75;
    } // TODO: maybe bring back gMaxMovePowers lol

    // Fighting and Poison Max Moves are weaker than other types.
    if (gBattleMoves[move].type == TYPE_FIGHTING
             || gBattleMoves[move].type == TYPE_POISON
             || move == MOVE_MULTI_ATTACK)
        switch (gBattleMoves[move].power)
        {
            default:
            case 0 ... 40: return 70;
            case 45 ... 50: return 75;
            case 55 ... 60: return 80;
            case 65 ... 70: return 85;
            case 75 ... 100: return 90;
            case 110 ... 140: return 95;
            case 150 ... 250: return 100;
        }
    else
        switch (gBattleMoves[move].power)
        {
            default:
            case 0 ... 40: return 90;
            case 45 ... 50: return 100;
            case 55 ... 60: return 110;
            case 65 ... 70: return 120;
            case 75 ... 100: return 130;
            case 110 ... 140: return 140;
            case 150 ... 250: return 150;
        }
}

// Returns whether a move is a Max Move or not.
bool32 IsMaxMove(u16 move)
{
    return move >= FIRST_MAX_MOVE && move <= LAST_MAX_MOVE;
}

// Returns the full name of a Max Move for the move usage text.
const u8 *GetMaxMoveName(u16 move)
{
    if (IsMaxMove(move))
        return gMaxMoveNames[move - FIRST_MAX_MOVE];
    else
        return gMaxMoveNames[0];   // Failsafe
}

// Assigns the multistring to use for the "Damage Non- Types" G-Max effect. 
void ChooseDamageNonTypesString(u8 type)
{
    switch (type) {
        case TYPE_GRASS:
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            break;
        case TYPE_WATER:
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            break;
        case TYPE_FIRE:
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            break;
        case TYPE_ROCK:
            gBattleCommunication[MULTISTRING_CHOOSER] = 3;
            break;
    }
}

// Returns the status effect that should be applied by a G-Max Move.
u32 GetMaxMoveStatusEffect(u16 move)
{
    u8 maxEffect = gBattleMoves[move].argument;
    switch (maxEffect)
    {
        // Status 1
        case MAX_EFFECT_PARALYZE_FOES:
            return STATUS1_PARALYSIS;
        case MAX_EFFECT_POISON_FOES:
            return STATUS1_POISON;
        case MAX_EFFECT_POISON_PARALYZE_FOES:
            if (Random() % 2)
                return STATUS1_POISON;
            else
                return STATUS1_PARALYSIS;
        case MAX_EFFECT_EFFECT_SPORE_FOES:
        {
            u8 effect = Random() % 3;
            if (effect == 0)
                return STATUS1_PARALYSIS;
            else if (effect == 1)
                return STATUS1_POISON;
            else
                return STATUS1_SLEEP;
        }
        // Status 2
        case MAX_EFFECT_CONFUSE_FOES:
        case MAX_EFFECT_CONFUSE_FOES_PAY_DAY:
            return STATUS2_CONFUSION;
        case MAX_EFFECT_INFATUATE_FOES:
            return STATUS2_INFATUATION;
        case MAX_EFFECT_MEAN_LOOK:
            return STATUS2_ESCAPE_PREVENTION;
        case MAX_EFFECT_TORMENT_FOES:
            return STATUS2_TORMENT;
    }
}

// Activates the secondary effect of a Max Move.
u16 SetMaxMoveEffect(u16 move)
{
    u16 effect = 0;
    u8 maxEffect = gBattleMoves[move].argument;

    // Don't continue if the move didn't land.
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        return effect;
    
    switch (maxEffect)
    {
        case MAX_EFFECT_RAISE_TEAM_ATTACK:
        case MAX_EFFECT_RAISE_TEAM_DEFENSE:
        case MAX_EFFECT_RAISE_TEAM_SPEED:
        case MAX_EFFECT_RAISE_TEAM_SP_ATK:
        case MAX_EFFECT_RAISE_TEAM_SP_DEF:
            if (!NoAliveMonsForEitherParty())
            {
                // Max Effects are ordered by stat ID.
                SET_STATCHANGER(gBattleMoves[gCurrentMove].argument, 1, FALSE);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
                effect++;
            }
            break;
        case MAX_EFFECT_LOWER_ATTACK:
        case MAX_EFFECT_LOWER_DEFENSE:
        case MAX_EFFECT_LOWER_SPEED:
        case MAX_EFFECT_LOWER_SP_ATK:
        case MAX_EFFECT_LOWER_SP_DEF:
        case MAX_EFFECT_LOWER_SPEED_2_FOES:
        case MAX_EFFECT_LOWER_EVASIVENESS_FOES:
            if (!NoAliveMonsForEitherParty())
            {
                u8 statId = 0;
                u8 stage = 1;
                switch (maxEffect)
                {
                    case MAX_EFFECT_LOWER_SPEED_2_FOES:
                        statId = STAT_SPEED;
                        stage = 2;
                        break;
                    case MAX_EFFECT_LOWER_EVASIVENESS_FOES:
                        statId = STAT_EVASION;
                        break;
                    default:
                        // Max Effects are ordered by stat ID.
                        statId = gBattleMoves[gCurrentMove].argument - MAX_EFFECT_LOWER_ATTACK + 1;
                        break;
                }
                SET_STATCHANGER(statId, stage, TRUE);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectLowerStatFoes;
                effect++;
            }
            break;
        case MAX_EFFECT_SUN:
        case MAX_EFFECT_RAIN:
        case MAX_EFFECT_SANDSTORM:
        case MAX_EFFECT_HAIL:
        {
            u8 weather, msg;
            switch (maxEffect)
            {
                case MAX_EFFECT_SUN:
                    weather = ENUM_WEATHER_SUN;
                    msg = B_MSG_STARTED_SUNLIGHT;
                    break;
                case MAX_EFFECT_RAIN:
                    weather = ENUM_WEATHER_RAIN;
                    msg = B_MSG_STARTED_RAIN;
                    break;
                case MAX_EFFECT_SANDSTORM:
                    weather = ENUM_WEATHER_SANDSTORM;
                    msg = B_MSG_STARTED_SANDSTORM;
                    break;
                case MAX_EFFECT_HAIL:
                    weather = ENUM_WEATHER_HAIL;
                    msg = B_MSG_STARTED_HAIL;
                    break;
            }
            if (TryChangeBattleWeather(gBattlerAttacker, weather, FALSE))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = msg;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectSetWeather;
                effect++;
            }
            break;
        }
        case MAX_EFFECT_MISTY_TERRAIN:
        case MAX_EFFECT_GRASSY_TERRAIN:
        case MAX_EFFECT_ELECTRIC_TERRAIN:
        case MAX_EFFECT_PSYCHIC_TERRAIN:
        {
            u32 statusFlag = 0;
            u8 *timer = NULL;
            switch (gBattleMoves[gCurrentMove].argument)
            {
                case MAX_EFFECT_MISTY_TERRAIN:
                    statusFlag = STATUS_FIELD_MISTY_TERRAIN, timer = &gFieldTimers.terrainTimer;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    break;
                case MAX_EFFECT_GRASSY_TERRAIN:
                    statusFlag = STATUS_FIELD_GRASSY_TERRAIN, timer = &gFieldTimers.terrainTimer;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    break;
                case MAX_EFFECT_ELECTRIC_TERRAIN:
                    statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN, timer = &gFieldTimers.terrainTimer;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                    break;
                case MAX_EFFECT_PSYCHIC_TERRAIN:
                    statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN, timer = &gFieldTimers.terrainTimer;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                    break;
            }
            if (!(gFieldStatuses & statusFlag) && statusFlag != 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
                gFieldStatuses |= statusFlag;
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
                    *timer = 8;
                else
                    *timer = 5;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectSetTerrain;
            }
            break;
        }
        case MAX_EFFECT_VINE_LASH:
        case MAX_EFFECT_CANNONADE:
        case MAX_EFFECT_WILDFIRE:
        case MAX_EFFECT_VOLCALITH:
        {
            u8 side = GetBattlerSide(gBattlerTarget);
            if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
            {
                gSideStatuses[side] |= SIDE_STATUS_DAMAGE_NON_TYPES;
                gSideTimers[side].damageNonTypesTimer = 5; // damage is dealt for 4 turns, ends on 5th
                gSideTimers[side].damageNonTypesType = gBattleMoves[gCurrentMove].type;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                ChooseDamageNonTypesString(gBattleMoves[gCurrentMove].type);
                gBattlescriptCurrInstr = BattleScript_DamageNonTypesStarts;
                effect++;
            }
            break;
        }
        case MAX_EFFECT_STEALTH_ROCK:
            if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEALTH_ROCK))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StealthRockActivates;
                effect++;
            }
            break;
        case MAX_EFFECT_STEELSURGE:
            if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEELSURGE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_SteelsurgeActivates;
                effect++;
            }
            break;
        case MAX_EFFECT_DEFOG:
            if (gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_SCREEN_ANY
                || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_HAZARDS_ANY
                || gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_HAZARDS_ANY
                || gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_DefogTryHazards;
                effect++;
            }
            break;
        case MAX_EFFECT_AURORA_VEIL:
            if (!(gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_AURORA_VEIL))
            {
                gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_AURORA_VEIL;
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                    gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = 8;
                else
                    gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = 5;
                gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilBattlerId = gBattlerAttacker;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_SAFEGUARD;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectAuroraVeilSuccess;
                effect++;
            }
            break;
        case MAX_EFFECT_GRAVITY:
            if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
            {
                gFieldStatuses |= STATUS_FIELD_GRAVITY;
                gFieldTimers.gravityTimer = 5;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectGravitySuccess;
                effect++;
            }
            break;
        case MAX_EFFECT_SANDBLAST_FOES:
        case MAX_EFFECT_FIRE_SPIN_FOES:
        {
            // Affects both opponents, but doesn't print strings so we can handle it here.
            u8 battler;
            for (battler = 0; battler < MAX_BATTLERS_COUNT; ++battler)
            {
                if (GetBattlerSide(battler) != GetBattlerSide(gBattlerTarget))
                    continue;
                if (!(gBattleMons[battler].status2 & STATUS2_WRAPPED))
                {
                    gBattleMons[battler].status2 |= STATUS2_WRAPPED;
                    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                #if B_BINDING_TURNS >= GEN_5
                        gDisableStructs[battler].wrapTurns = 7;
                    else
                        gDisableStructs[battler].wrapTurns = (Random() % 2) + 4;
                #else
                        gDisableStructs[battler].wrapTurns = 5;
                    else
                        gDisableStructs[battler].wrapTurns = (Random() % 4) + 2;
                #endif
                    // The Wrap effect does not expire when the user switches, so here's some cheese.
                    gBattleStruct->wrappedBy[battler] = gBattlerTarget;
                    if (maxEffect == MAX_EFFECT_SANDBLAST_FOES)
                        gBattleStruct->wrappedMove[battler] = MOVE_SAND_TOMB;
                    else
                        gBattleStruct->wrappedMove[battler] = MOVE_FIRE_SPIN;
                }
            }
            break;
        }
        case MAX_EFFECT_YAWN_FOE:
            if (!(gStatuses3[gBattlerTarget] & STATUS3_YAWN)
                && CanSleep(gBattlerTarget)
                && Random() % 2) // 50% chance of success
            {
                gStatuses3[gBattlerTarget] |= STATUS3_YAWN_TURN(2);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectYawnSuccess;
                effect++;
            }
            break;
        case MAX_EFFECT_SPITE:
            if (gLastMoves[gBattlerTarget] != MOVE_NONE
                && gLastMoves[gBattlerTarget] != MOVE_UNAVAILABLE)
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectTryReducePP;
                effect++;
            }
            break;
        case MAX_EFFECT_PARALYZE_FOES:
        case MAX_EFFECT_POISON_FOES:
        case MAX_EFFECT_POISON_PARALYZE_FOES:
        case MAX_EFFECT_EFFECT_SPORE_FOES:
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectStatus1Foes;
            effect++;
            break;
        case MAX_EFFECT_CONFUSE_FOES_PAY_DAY:
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u16 payday = gPaydayMoney;
                gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 100);
                if (payday > gPaydayMoney)
                    gPaydayMoney = 0xFFFF;
                gBattleCommunication[CURSOR_POSITION] = 1; // add "Coins scattered." message
            }
            // fall through
        case MAX_EFFECT_CONFUSE_FOES:
        case MAX_EFFECT_INFATUATE_FOES:
        case MAX_EFFECT_TORMENT_FOES:
        case MAX_EFFECT_MEAN_LOOK:
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectStatus2Foes;
            effect++;
            break;
        case MAX_EFFECT_CRIT_PLUS:
            gBattleStruct->bonusCritStages[gBattlerAttacker]++;
            gBattleStruct->bonusCritStages[BATTLE_PARTNER(gBattlerAttacker)]++;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseCritAlliesAnim;
            effect++;
            break;
        case MAX_EFFECT_HEAL_TEAM:
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectHealOneSixthAllies;
            effect++;
            break;
        case MAX_EFFECT_AROMATHERAPY:
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectCureStatusAllies;
            effect++;
            break;
        case MAX_EFFECT_RECYCLE_BERRIES:
            if (Random() % 2) // 50% chance of success
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
                effect++;
            }
            break;

    }
    return effect;
}

// DYNAMAX TRIGGER:
static const u8 ALIGNED(4) sDynamaxTriggerGfx[] = INCBIN_U8("graphics/battle_interface/dynamax_trigger.4bpp");
static const u16 sDynamaxTriggerPal[] = INCBIN_U16("graphics/battle_interface/dynamax_trigger.gbapal");

static const struct SpriteSheet sSpriteSheet_DynamaxTrigger =
{
    sDynamaxTriggerGfx, sizeof(sDynamaxTriggerGfx), TAG_DYNAMAX_TRIGGER_TILE
};
static const struct SpritePalette sSpritePalette_DynamaxTrigger =
{
    sDynamaxTriggerPal, TAG_DYNAMAX_TRIGGER_PAL
};

static const struct OamData sOamData_DynamaxTrigger =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_DynamaxTriggerOff[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_DynamaxTriggerOn[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_DynamaxTrigger[] =
{
    sSpriteAnim_DynamaxTriggerOff,
    sSpriteAnim_DynamaxTriggerOn,
};

static const struct SpriteTemplate sSpriteTemplate_DynamaxTrigger =
{
    .tileTag = TAG_DYNAMAX_TRIGGER_TILE,
    .paletteTag = TAG_DYNAMAX_TRIGGER_PAL,
    .oam = &sOamData_DynamaxTrigger,
    .anims = sSpriteAnimTable_DynamaxTrigger,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_DynamaxTrigger
};

// Dynamax Evolution Trigger icon functions.
void ChangeDynamaxTriggerSprite(u8 spriteId, u8 animId)
{
    StartSpriteAnim(&gSprites[spriteId], animId);
}

#define SINGLES_DYNAMAX_TRIGGER_POS_X_OPTIMAL (30)
#define SINGLES_DYNAMAX_TRIGGER_POS_X_PRIORITY (31)
#define SINGLES_DYNAMAX_TRIGGER_POS_X_SLIDE (15)
#define SINGLES_DYNAMAX_TRIGGER_POS_Y_DIFF (-11)

#define DOUBLES_DYNAMAX_TRIGGER_POS_X_OPTIMAL (30)
#define DOUBLES_DYNAMAX_TRIGGER_POS_X_PRIORITY (31)
#define DOUBLES_DYNAMAX_TRIGGER_POS_X_SLIDE (15)
#define DOUBLES_DYNAMAX_TRIGGER_POS_Y_DIFF (-4)

#define tBattler    data[0]
#define tHide       data[1]

void CreateDynamaxTriggerSprite(u8 battlerId, u8 palId)
{
    LoadSpritePalette(&sSpritePalette_DynamaxTrigger);
    if (GetSpriteTileStartByTag(TAG_DYNAMAX_TRIGGER_TILE) == 0xFFFF)
        LoadSpriteSheet(&sSpriteSheet_DynamaxTrigger);
    if (gBattleStruct->dynamax.triggerSpriteId == 0xFF)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            gBattleStruct->dynamax.triggerSpriteId = CreateSprite(&sSpriteTemplate_DynamaxTrigger,
                                                             gSprites[gHealthboxSpriteIds[battlerId]].x - DOUBLES_DYNAMAX_TRIGGER_POS_X_SLIDE,
                                                             gSprites[gHealthboxSpriteIds[battlerId]].y - DOUBLES_DYNAMAX_TRIGGER_POS_Y_DIFF, 0);
        else
            gBattleStruct->dynamax.triggerSpriteId = CreateSprite(&sSpriteTemplate_DynamaxTrigger,
                                                             gSprites[gHealthboxSpriteIds[battlerId]].x - SINGLES_DYNAMAX_TRIGGER_POS_X_SLIDE,
                                                             gSprites[gHealthboxSpriteIds[battlerId]].y - SINGLES_DYNAMAX_TRIGGER_POS_Y_DIFF, 0);
    }
    gSprites[gBattleStruct->dynamax.triggerSpriteId].tBattler = battlerId;
    gSprites[gBattleStruct->dynamax.triggerSpriteId].tHide = FALSE;

    ChangeDynamaxTriggerSprite(gBattleStruct->dynamax.triggerSpriteId, palId);
}

static void SpriteCb_DynamaxTrigger(struct Sprite *sprite)
{
    s32 xSlide, xPriority, xOptimal;
    s32 yDiff;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        xSlide = DOUBLES_DYNAMAX_TRIGGER_POS_X_SLIDE;
        xPriority = DOUBLES_DYNAMAX_TRIGGER_POS_X_PRIORITY;
        xOptimal = DOUBLES_DYNAMAX_TRIGGER_POS_X_OPTIMAL;
        yDiff = DOUBLES_DYNAMAX_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        xSlide = SINGLES_DYNAMAX_TRIGGER_POS_X_SLIDE;
        xPriority = SINGLES_DYNAMAX_TRIGGER_POS_X_PRIORITY;
        xOptimal = SINGLES_DYNAMAX_TRIGGER_POS_X_OPTIMAL;
        yDiff = SINGLES_DYNAMAX_TRIGGER_POS_Y_DIFF;
    }

    if (sprite->tHide)
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            sprite->x++;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
        if (sprite->x == gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xSlide)
            DestroyDynamaxTriggerSprite();
    }
    else
    {
        if (sprite->x != gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xOptimal)
            sprite->x--;

        if (sprite->x >= gSprites[gHealthboxSpriteIds[sprite->tBattler]].x - xPriority)
            sprite->oam.priority = 2;
        else
            sprite->oam.priority = 1;

        sprite->y = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y - yDiff;
        sprite->y2 = gSprites[gHealthboxSpriteIds[sprite->tBattler]].y2 - yDiff;
    }
}

bool32 IsDynamaxTriggerSpriteActive(void)
{
    if (GetSpriteTileStartByTag(TAG_DYNAMAX_TRIGGER_TILE) == 0xFFFF)
        return FALSE;
    else if (IndexOfSpritePaletteTag(TAG_DYNAMAX_TRIGGER_PAL) != 0xFF)
        return TRUE;
    else
        return FALSE;
}

void HideDynamaxTriggerSprite(void)
{
    if (gBattleStruct->dynamax.triggerSpriteId != 0xFF)
    {
        ChangeDynamaxTriggerSprite(gBattleStruct->dynamax.triggerSpriteId, 0);
        gSprites[gBattleStruct->dynamax.triggerSpriteId].tHide = TRUE;
    }
}

void DestroyDynamaxTriggerSprite(void)
{
    FreeSpritePaletteByTag(TAG_DYNAMAX_TRIGGER_PAL);
    FreeSpriteTilesByTag(TAG_DYNAMAX_TRIGGER_TILE);
    if (gBattleStruct->dynamax.triggerSpriteId != 0xFF)
        DestroySprite(&gSprites[gBattleStruct->dynamax.triggerSpriteId]);
    gBattleStruct->dynamax.triggerSpriteId = 0xFF;
}

#undef tBattler
#undef tHide


// DYNAMAX INDICATOR:
static const u8 ALIGNED(4) sDynamaxIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dynamax_indicator.4bpp");
static const u16 sDynamaxIndicatorPal[] = INCBIN_U16("graphics/battle_interface/misc_indicator.gbapal");

static const struct SpriteSheet sSpriteSheet_DynamaxIndicator =
{
    sDynamaxIndicatorGfx, sizeof(sDynamaxIndicatorGfx), TAG_DYNAMAX_INDICATOR_TILE
};
static const struct SpritePalette sSpritePalette_DynamaxIndicator =
{
    sDynamaxIndicatorPal, TAG_MISC_INDICATOR_PAL
};

static const struct SpriteSheet sDynamaxIndicator_SpriteSheet[] =
{
    sDynamaxIndicatorGfx, sizeof(sDynamaxIndicatorGfx), TAG_DYNAMAX_INDICATOR_TILE
};

static const struct SpritePalette sDynamaxIndicator_SpritePalette[] =
{
    sDynamaxIndicatorPal, TAG_MISC_INDICATOR_PAL
};

static const struct OamData sOamData_DynamaxIndicator =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct SpriteTemplate sSpriteTemplate_DynamaxIndicator =
{
    .tileTag = TAG_DYNAMAX_INDICATOR_TILE,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_DynamaxIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_DynamaxIndicator,
};

static const s8 sIndicatorPositions[][2] =
{
    [B_POSITION_PLAYER_LEFT] = {52, -9},
    [B_POSITION_OPPONENT_LEFT] = {44, -9},
    [B_POSITION_PLAYER_RIGHT] = {52, -9},
    [B_POSITION_OPPONENT_RIGHT] = {44, -9},
};

// for sprite data fields
#define tBattler        data[0]
#define tType           data[1] // Indicator type: dynamax
#define tPosX           data[2]
#define tLevelXDelta    data[3] // X position depends whether level has 3, 2 or 1 digit

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_DynamaxIndicatorId    data[3]
#define hMain_HealthBarSpriteId     data[5]
#define hMain_Battler               data[6]
#define hMain_Data7                 data[7]

// data fields for healthboxRight
#define hOther_HealthBoxSpriteId    data[5]

// data fields for healthbar
#define hBar_HealthBoxSpriteId      data[5]

void DynamaxIndicator_LoadSpriteGfx(void)
{
    LoadSpriteSheet(sDynamaxIndicator_SpriteSheet);
    LoadSpritePalette(sDynamaxIndicator_SpritePalette);
}

bool32 DynamaxIndicator_ShouldBeInvisible(u32 battlerId)
{
    return !IsDynamaxed(battlerId);
}

u8 DynamaxIndicator_GetSpriteId(u32 healthboxSpriteId)
{
    return gBattleStruct->dynamax.indicatorSpriteId[gSprites[healthboxSpriteId].hMain_Battler];
}

void DynamaxIndicator_SetVisibilities(u32 healthboxId, bool32 invisible)
{
    u32 i;
    u8 spriteId = DynamaxIndicator_GetSpriteId(healthboxId);
    u32 battlerId = gSprites[healthboxId].hMain_Battler;

    if (invisible == TRUE)
        gSprites[spriteId].invisible = TRUE;
    else // Try visible.
        gSprites[spriteId].invisible = DynamaxIndicator_ShouldBeInvisible(battlerId);
}

void DynamaxIndicator_UpdateOamPriorities(u32 healthboxId, u32 oamPriority)
{
    u32 i;
    u8 spriteId = DynamaxIndicator_GetSpriteId(healthboxId);
    gSprites[spriteId].oam.priority = oamPriority;
}

void DynamaxIndicator_UpdateLevel(u32 healthboxId, u32 level)
{
    u32 i;
    s16 xDelta = 0;
    u8 spriteId = DynamaxIndicator_GetSpriteId(healthboxId);

    if (level >= 100)
        xDelta -= 4;
    else if (level < 10)
        xDelta += 5;

    gSprites[spriteId].tLevelXDelta = xDelta;
}

void DynamaxIndicator_CreateSprite(u32 battlerId, u32 healthboxSpriteId)
{
    u32 position, level;
    u8 spriteId;
    s16 xHealthbox = 0, y = 0;
    s32 x = 0;

    position = GetBattlerPosition(battlerId);
    GetBattlerHealthboxCoords(battlerId, &xHealthbox, &y);

    x = sIndicatorPositions[position][0];
    y += sIndicatorPositions[position][1];

    spriteId = gBattleStruct->dynamax.indicatorSpriteId[battlerId] = CreateSpriteAtEnd(&sSpriteTemplate_DynamaxIndicator, 0, y, 0);
    gSprites[spriteId].tBattler = battlerId;
    gSprites[spriteId].tPosX = x;
    gSprites[spriteId].invisible = TRUE;
}

void DynamaxIndicator_DestroySprite(u32 healthboxSpriteId)
{
    u8 spriteId = DynamaxIndicator_GetSpriteId(healthboxSpriteId);
    DestroySprite(&gSprites[spriteId]);
}

static void SpriteCb_DynamaxIndicator(struct Sprite *sprite)
{
    u32 battlerId = sprite->tBattler;

    sprite->x = gSprites[gHealthboxSpriteIds[battlerId]].x + sprite->tPosX + sprite->tLevelXDelta;
    sprite->x2 = gSprites[gHealthboxSpriteIds[battlerId]].x2;
    sprite->y2 = gSprites[gHealthboxSpriteIds[battlerId]].y2;
}

#undef tBattler
#undef tType
#undef tPosX
#undef tLevelXDelta
