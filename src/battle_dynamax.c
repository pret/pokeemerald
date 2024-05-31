#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "data.h"
#include "event_data.h"
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
#include "constants/flags.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"

static u8 GetMaxPowerTier(u16 move);

struct GMaxMove
{
    u16 species;
    u8 moveType;
    u16 gmaxMove;
};

static const struct GMaxMove sGMaxMoveTable[] =
{
    {SPECIES_VENUSAUR_GIGANTAMAX,                   TYPE_GRASS,      MOVE_G_MAX_VINE_LASH},
    {SPECIES_BLASTOISE_GIGANTAMAX,                  TYPE_WATER,      MOVE_G_MAX_CANNONADE},
    {SPECIES_CHARIZARD_GIGANTAMAX,                  TYPE_FIRE,       MOVE_G_MAX_WILDFIRE},
    {SPECIES_BUTTERFREE_GIGANTAMAX,                 TYPE_BUG,        MOVE_G_MAX_BEFUDDLE},
    {SPECIES_PIKACHU_GIGANTAMAX,                    TYPE_ELECTRIC,   MOVE_G_MAX_VOLT_CRASH},
    {SPECIES_MEOWTH_GIGANTAMAX,                     TYPE_NORMAL,     MOVE_G_MAX_GOLD_RUSH},
    {SPECIES_MACHAMP_GIGANTAMAX,                    TYPE_FIGHTING,   MOVE_G_MAX_CHI_STRIKE},
    {SPECIES_GENGAR_GIGANTAMAX,                     TYPE_GHOST,      MOVE_G_MAX_TERROR},
    {SPECIES_KINGLER_GIGANTAMAX,                    TYPE_WATER,      MOVE_G_MAX_FOAM_BURST},
    {SPECIES_LAPRAS_GIGANTAMAX,                     TYPE_ICE,        MOVE_G_MAX_RESONANCE},
    {SPECIES_EEVEE_GIGANTAMAX,                      TYPE_NORMAL,     MOVE_G_MAX_CUDDLE},
    {SPECIES_SNORLAX_GIGANTAMAX,                    TYPE_NORMAL,     MOVE_G_MAX_REPLENISH},
    {SPECIES_GARBODOR_GIGANTAMAX,                   TYPE_POISON,     MOVE_G_MAX_MALODOR},
    {SPECIES_MELMETAL_GIGANTAMAX,                   TYPE_STEEL,      MOVE_G_MAX_MELTDOWN},
    {SPECIES_RILLABOOM_GIGANTAMAX,                  TYPE_GRASS,      MOVE_G_MAX_DRUM_SOLO},
    {SPECIES_CINDERACE_GIGANTAMAX,                  TYPE_FIRE,       MOVE_G_MAX_FIREBALL},
    {SPECIES_INTELEON_GIGANTAMAX,                   TYPE_WATER,      MOVE_G_MAX_HYDROSNIPE},
    {SPECIES_CORVIKNIGHT_GIGANTAMAX,                TYPE_FLYING,     MOVE_G_MAX_WIND_RAGE},
    {SPECIES_ORBEETLE_GIGANTAMAX,                   TYPE_PSYCHIC,    MOVE_G_MAX_GRAVITAS},
    {SPECIES_DREDNAW_GIGANTAMAX,                    TYPE_WATER,      MOVE_G_MAX_STONESURGE},
    {SPECIES_COALOSSAL_GIGANTAMAX,                  TYPE_ROCK,       MOVE_G_MAX_VOLCALITH},
    {SPECIES_FLAPPLE_GIGANTAMAX,                    TYPE_GRASS,      MOVE_G_MAX_TARTNESS},
    {SPECIES_APPLETUN_GIGANTAMAX,                   TYPE_GRASS,      MOVE_G_MAX_SWEETNESS},
    {SPECIES_SANDACONDA_GIGANTAMAX,                 TYPE_GROUND,     MOVE_G_MAX_SANDBLAST},
    {SPECIES_TOXTRICITY_AMPED_GIGANTAMAX,           TYPE_ELECTRIC,   MOVE_G_MAX_STUN_SHOCK},
    {SPECIES_TOXTRICITY_LOW_KEY_GIGANTAMAX,         TYPE_ELECTRIC,   MOVE_G_MAX_STUN_SHOCK},
    {SPECIES_CENTISKORCH_GIGANTAMAX,                TYPE_FIRE,       MOVE_G_MAX_CENTIFERNO},
    {SPECIES_HATTERENE_GIGANTAMAX,                  TYPE_FAIRY,      MOVE_G_MAX_SMITE},
    {SPECIES_GRIMMSNARL_GIGANTAMAX,                 TYPE_DARK,       MOVE_G_MAX_SNOOZE},
    {SPECIES_ALCREMIE_GIGANTAMAX,                   TYPE_FAIRY,      MOVE_G_MAX_FINALE},
    {SPECIES_COPPERAJAH_GIGANTAMAX,                 TYPE_STEEL,      MOVE_G_MAX_STEELSURGE},
    {SPECIES_DURALUDON_GIGANTAMAX,                  TYPE_DRAGON,     MOVE_G_MAX_DEPLETION},
    {SPECIES_URSHIFU_SINGLE_STRIKE_STYLE_GIGANTAMAX,TYPE_DARK,       MOVE_G_MAX_ONE_BLOW},
    {SPECIES_URSHIFU_RAPID_STRIKE_STYLE_GIGANTAMAX, TYPE_WATER,      MOVE_G_MAX_RAPID_FLOW},
};

// forward declarations
static void SpriteCb_DynamaxTrigger(struct Sprite *);

// Returns whether a battler is Dynamaxed.
bool32 IsDynamaxed(u16 battlerId)
{
    if (gBattleStruct->dynamax.dynamaxed[battlerId]
        /*|| IsRaidBoss(battlerId)*/)
        return TRUE;
    return FALSE;
}

// Returns whether a battler can Dynamax.
bool32 CanDynamax(u16 battlerId)
{
    u16 species = gBattleMons[battlerId].species;
    u16 holdEffect = ItemId_GetHoldEffect(gBattleMons[battlerId].item);

    // Check if Dynamax battle flag is set. This needs to be defined in include/config/battle.h
    #if B_FLAG_DYNAMAX_BATTLE != 0
    if (!FlagGet(B_FLAG_DYNAMAX_BATTLE))
    #endif
        return FALSE;


    // Check if Player has a Dynamax Band.
    if ((GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT || (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT))
          && !CheckBagHasItem(ITEM_DYNAMAX_BAND, 1))
        return FALSE;

    // Check if species isn't allowed to Dynamax.
    if (GET_BASE_SPECIES_ID(species) == SPECIES_ZACIAN
        || GET_BASE_SPECIES_ID(species) == SPECIES_ZAMAZENTA
        || GET_BASE_SPECIES_ID(species) == SPECIES_ETERNATUS)
        return FALSE;

    // Cannot Dynamax if you can Mega Evolve or use a Z-Move
    if (holdEffect == HOLD_EFFECT_MEGA_STONE || holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        return FALSE;

    // Cannot Dynamax if your side has already or will Dynamax.
    if (gBattleStruct->dynamax.alreadyDynamaxed[GetBattlerSide(battlerId)]
        || gBattleStruct->dynamax.dynamaxed[BATTLE_PARTNER(battlerId)]
        || gBattleStruct->dynamax.toDynamax & gBitTable[BATTLE_PARTNER(battlerId)])
        return FALSE;

    // TODO: Cannot Dynamax in a Max Raid if you don't have Dynamax Energy.
    // if (gBattleTypeFlags & BATTLE_TYPE_RAID && gBattleStruct->raid.dynamaxEnergy != battlerId)
    //    return FALSE;

    // No checks failed, all set!
    return TRUE;
}

// Returns whether a battler is transformed into a Gigantamax form.
bool32 IsGigantamaxed(u16 battlerId)
{
    struct Pokemon *mon = &GetSideParty(GetBattlerSide(battlerId))[gBattlerPartyIndexes[battlerId]];
    if ((gSpeciesInfo[gBattleMons[battlerId].species].isGigantamax) && GetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR))
        return TRUE;
    return FALSE;
}

// Applies the HP Multiplier for Dynamaxed Pokemon and Raid Bosses.
void ApplyDynamaxHPMultiplier(u32 battler, struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA)
        return;
    else
    {
        u32 scale = 150 + 5 * GetMonData(mon, MON_DATA_DYNAMAX_LEVEL);
        u32 hp = (GetMonData(mon, MON_DATA_HP) * scale + 99) / 100;
        u32 maxHP = (GetMonData(mon, MON_DATA_MAX_HP) * scale + 99) / 100;
        SetMonData(mon, MON_DATA_HP, &hp);
        SetMonData(mon, MON_DATA_MAX_HP, &maxHP);
    }
}

// Returns the non-Dynamax HP of a Pokemon.
u16 GetNonDynamaxHP(u16 battlerId)
{
    if (!IsDynamaxed(battlerId) || gBattleMons[battlerId].species == SPECIES_SHEDINJA)
        return gBattleMons[battlerId].hp;
    else
    {
        u16 mult = UQ_4_12(1.0/1.5); // placeholder
        u16 hp = UQ_4_12_TO_INT((gBattleMons[battlerId].hp * mult) + UQ_4_12_ROUND);
        return hp;
    }
}

// Returns the non-Dynamax Max HP of a Pokemon.
u16 GetNonDynamaxMaxHP(u32 battlerId)
{
    if (!IsDynamaxed(battlerId) || gBattleMons[battlerId].species == SPECIES_SHEDINJA)
        return gBattleMons[battlerId].maxHP;
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

    gBattleStruct->dynamax.alreadyDynamaxed[side] = TRUE;
    gBattleStruct->dynamax.dynamaxed[battlerId] = TRUE;
    gBattleStruct->dynamax.dynamaxTurns[battlerId] = DYNAMAX_TURNS_COUNT;

    // Substitute is removed upon Dynamaxing.
    gBattleMons[battlerId].status2 &= ~STATUS2_SUBSTITUTE;
    ClearBehindSubstituteBit(battlerId);

    // Choiced Moves are reset upon Dynamaxing.
    gBattleStruct->choicedMove[battlerId] = MOVE_NONE;

    // Try Gigantamax form change.
    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED)) // Ditto cannot Gigantamax.
        TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_GIGANTAMAX);
}

// Unsets the flags used for Dynamaxing and reverts max HP if needed.
void UndoDynamax(u16 battlerId)
{
    u8 side = GetBattlerSide(battlerId);
    u8 monId = gBattlerPartyIndexes[battlerId];

    // Revert HP if battler is still Dynamaxed.
    if (IsDynamaxed(battlerId))
    {
        struct Pokemon *mon = (side == B_SIDE_PLAYER) ? &gPlayerParty[monId] : &gEnemyParty[monId];
        u16 mult = UQ_4_12(1.0/1.5); // placeholder
        gBattleMons[battlerId].hp = UQ_4_12_TO_INT((GetMonData(mon, MON_DATA_HP) * mult + 1) + UQ_4_12_ROUND); // round up
        SetMonData(mon, MON_DATA_HP, &gBattleMons[battlerId].hp);
        CalculateMonStats(mon);
    }

    // Makes sure there are no Dynamax flags set, including on switch / faint.
    gBattleStruct->dynamax.dynamaxed[battlerId] = FALSE;
    gBattleStruct->dynamax.dynamaxTurns[battlerId] = 0;

    // Undo form change if needed.
    if (IsGigantamaxed(battlerId))
        TryBattleFormChange(battlerId, FORM_CHANGE_END_BATTLE);
}

// Certain moves are blocked by Max Guard that normally ignore protection.
bool32 IsMoveBlockedByMaxGuard(u16 move)
{
    switch (move)
    {
        case MOVE_BLOCK:
        case MOVE_FLOWER_SHIELD:
        case MOVE_GEAR_UP:
        case MOVE_MAGNETIC_FLUX:
        case MOVE_PHANTOM_FORCE:
        case MOVE_PSYCH_UP:
        case MOVE_SHADOW_FORCE:
        case MOVE_TEATIME:
        case MOVE_TRANSFORM:
            return TRUE;
    }
    return FALSE;
}

// Weight-based moves (and some other moves in Raids) are blocked by Dynamax.
bool32 IsMoveBlockedByDynamax(u16 move)
{
    // TODO: Certain moves are banned in raids.
    switch (gMovesInfo[move].effect)
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
    // TODO: Raid bosses do not always use Max Moves.
    // if (IsRaidBoss(battlerId))
    //   return !IsRaidBossUsingRegularMove(battlerId, baseMove);
    return IsDynamaxed(battlerId) || gBattleStruct->dynamax.toDynamax & gBitTable[battlerId];
}

static u16 GetTypeBasedMaxMove(u16 battlerId, u16 type)
{
    // Gigantamax check
    u32 i;
    u16 species = gBattleMons[battlerId].species;
    u16 targetSpecies = SPECIES_NONE;

    if (!gSpeciesInfo[species].isGigantamax)
        targetSpecies = GetBattleFormChangeTargetSpecies(battlerId, FORM_CHANGE_BATTLE_GIGANTAMAX);

    if (targetSpecies != SPECIES_NONE)
        species = targetSpecies;

    if (gSpeciesInfo[species].isGigantamax)
    {
        for (i = 0; i < ARRAY_COUNT(sGMaxMoveTable); i++)
        {
            if (sGMaxMoveTable[i].species == species && sGMaxMoveTable[i].moveType == type)
                return sGMaxMoveTable[i].gmaxMove;
        }
    }

    // Regular Max Move
    if (gTypesInfo[type].maxMove == MOVE_NONE) // failsafe
        return gTypesInfo[0].maxMove;
    return gTypesInfo[type].maxMove;
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
    else if (gMovesInfo[baseMove].category == DAMAGE_CATEGORY_STATUS)
    {
        move = MOVE_MAX_GUARD;
    }
    else if (gBattleStruct->dynamicMoveType)
    {
        move = GetTypeBasedMaxMove(battlerId, gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK);
        gBattleStruct->dynamax.categories[battlerId] = gMovesInfo[baseMove].category;
    }
    else
    {
        move = GetTypeBasedMaxMove(battlerId, gMovesInfo[baseMove].type);
        gBattleStruct->dynamax.categories[battlerId] = gMovesInfo[baseMove].category;
    }

    return move;
}

// First value is for Fighting, Poison and Multi-Attack. The second is for everything else.
enum
{
    MAX_POWER_TIER_1,   //  70 or 90 damage
    MAX_POWER_TIER_2,   // 75 or 100 damage
    MAX_POWER_TIER_3,   // 80 or 110 damage
    MAX_POWER_TIER_4,   // 85 or 120 damage
    MAX_POWER_TIER_5,   // 90 or 130 damage
    MAX_POWER_TIER_6,   // 95 or 140 damage
    MAX_POWER_TIER_7,   // 100 or 130 damage
    MAX_POWER_TIER_8,   // 100 or 150 damage
};

// Gets the base power of a Max Move.
u8 GetMaxMovePower(u16 move)
{
    u8 tier;
    // G-Max Drum Solo, G-Max Hydrosnipe, and G-Max Fireball always have 160 base power.
    if (gMovesInfo[GetMaxMove(gBattlerAttacker, move)].argument == MAX_EFFECT_FIXED_POWER)
        return 160;

    // Exceptions to all other rules below:
    switch (move)
    {
        case MOVE_TRIPLE_KICK:   return 80;
        case MOVE_GEAR_GRIND:    return 100;
        case MOVE_DUAL_WINGBEAT: return 100;
        case MOVE_TRIPLE_AXEL:   return 140;
    }

    tier = GetMaxPowerTier(move);
    if (gMovesInfo[move].type == TYPE_FIGHTING
     || gMovesInfo[move].type == TYPE_POISON
     || move == MOVE_MULTI_ATTACK)
    {
        switch (tier)
        {
            default:
            case MAX_POWER_TIER_1: return 70;
            case MAX_POWER_TIER_2: return 75;
            case MAX_POWER_TIER_3: return 80;
            case MAX_POWER_TIER_4: return 85;
            case MAX_POWER_TIER_5: return 90;
            case MAX_POWER_TIER_6: return 95;
            case MAX_POWER_TIER_7: return 100;
            case MAX_POWER_TIER_8: return 100;
        }
    }
    else
    {
        switch (tier)
        {
            default:
            case MAX_POWER_TIER_1: return 90;
            case MAX_POWER_TIER_2: return 100;
            case MAX_POWER_TIER_3: return 110;
            case MAX_POWER_TIER_4: return 120;
            case MAX_POWER_TIER_5: return 130;
            case MAX_POWER_TIER_6: return 140;
            case MAX_POWER_TIER_7: return 130;
            case MAX_POWER_TIER_8: return 150;
        }
    }
}

static u8 GetMaxPowerTier(u16 move)
{
    if (gMovesInfo[move].strikeCount >= 2 && gMovesInfo[move].strikeCount <= 5)
    {
        switch(gMovesInfo[move].power)
        {
            case 0 ... 25:  return MAX_POWER_TIER_2;
            case 26 ... 30: return MAX_POWER_TIER_3;
            case 31 ... 35: return MAX_POWER_TIER_4;
            case 36 ... 50: return MAX_POWER_TIER_5;
            default:
            case 51 ... 60: return MAX_POWER_TIER_6;
        }
    }

    switch (gMovesInfo[move].effect)
    {
        case EFFECT_BIDE:
        case EFFECT_SUPER_FANG:
        case EFFECT_LEVEL_DAMAGE:
        case EFFECT_PSYWAVE:
        case EFFECT_COUNTER:
        case EFFECT_PRESENT:
        case EFFECT_BEAT_UP:
        case EFFECT_WEATHER_BALL:
        case EFFECT_FLING:
        case EFFECT_ELECTRO_BALL:
        case EFFECT_METAL_BURST:
        case EFFECT_TERRAIN_PULSE:
        case EFFECT_PUNISHMENT:
        case EFFECT_TRUMP_CARD:
        case EFFECT_FIXED_DAMAGE_ARG:
        case EFFECT_SPIT_UP:
        case EFFECT_NATURAL_GIFT:
        case EFFECT_MIRROR_COAT:
        case EFFECT_FINAL_GAMBIT:
        //case EFFECT_DRAGON_DARTS:
            return MAX_POWER_TIER_2;
        case EFFECT_OHKO:
        case EFFECT_RETURN:
        case EFFECT_FRUSTRATION:
        case EFFECT_HEAT_CRASH:
        case EFFECT_STORED_POWER:
        case EFFECT_GYRO_BALL:
            return MAX_POWER_TIER_5;
        case EFFECT_MAGNITUDE:
        case EFFECT_VARY_POWER_BASED_ON_HP:
            return MAX_POWER_TIER_6;
        case EFFECT_FLAIL:
        case EFFECT_LOW_KICK:
            return MAX_POWER_TIER_7;
        case EFFECT_MULTI_HIT:
            switch(gMovesInfo[move].power)
            {
                case 0 ... 15:    return MAX_POWER_TIER_1;
                case 16 ... 18:   return MAX_POWER_TIER_2;
                case 19 ... 20:   return MAX_POWER_TIER_4;
                default:
                case 21 ... 25:   return MAX_POWER_TIER_5;
            }
    }

    switch (gMovesInfo[move].power)
    {
        case 0 ... 40:    return MAX_POWER_TIER_1;
        case 45 ... 50:   return MAX_POWER_TIER_2;
        case 55 ... 60:   return MAX_POWER_TIER_3;
        case 65 ... 70:   return MAX_POWER_TIER_4;
        case 75 ... 100:  return MAX_POWER_TIER_5;
        case 110 ... 140: return MAX_POWER_TIER_6;
        default:
        case 150 ... 250: return MAX_POWER_TIER_8;
    }
}

// Returns whether a move is a Max Move or not.
bool32 IsMaxMove(u16 move)
{
    return move >= FIRST_MAX_MOVE && move <= LAST_MAX_MOVE;
}

// Assigns the multistring to use for the "Damage Non- Types" G-Max effect.
void ChooseDamageNonTypesString(u8 type)
{
    switch (type)
    {
        case TYPE_GRASS:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TRAPPED_WITH_VINES;
            break;
        case TYPE_WATER:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CAUGHT_IN_VORTEX;
            break;
        case TYPE_FIRE:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SURROUNDED_BY_FIRE;
            break;
        case TYPE_ROCK:
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SURROUNDED_BY_ROCKS;
            break;
    }
}

// Returns the status effect that should be applied by a G-Max Move.
static u32 GetMaxMoveStatusEffect(u16 move)
{
    u8 maxEffect = gMovesInfo[move].argument;
    switch (maxEffect)
    {
        // Status 1
        case MAX_EFFECT_PARALYZE_FOES:
            return STATUS1_PARALYSIS;
        case MAX_EFFECT_POISON_FOES:
            return STATUS1_POISON;
        case MAX_EFFECT_POISON_PARALYZE_FOES:
        {
            static const u8 sStunShockEffects[] = {STATUS1_PARALYSIS, STATUS1_POISON};
            return RandomElement(RNG_G_MAX_STUN_SHOCK, sStunShockEffects);
        }
        case MAX_EFFECT_EFFECT_SPORE_FOES:
        {
            static const u8 sBefuddleEffects[] = {STATUS1_PARALYSIS, STATUS1_POISON, STATUS1_SLEEP};
            return RandomElement(RNG_G_MAX_BEFUDDLE, sBefuddleEffects);
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
        default:
            return STATUS1_NONE;
    }
}

// CALLNATIVE FUNCTIONS
#define CMD_ARGS(...) const struct __attribute__((packed)) { u8 opcode; MEMBERS(__VA_ARGS__) const u8 nextInstr[0]; } *const cmd  = (const void *)gBattlescriptCurrInstr
#define NATIVE_ARGS(...) CMD_ARGS(void (*func)(void), ##__VA_ARGS__)

#define MEMBERS(...) VARARG_8(MEMBERS_, __VA_ARGS__)
#define MEMBERS_0()
#define MEMBERS_1(a) a;
#define MEMBERS_2(a, b) a; b;
#define MEMBERS_3(a, b, c) a; b; c;
#define MEMBERS_4(a, b, c, d) a; b; c; d;
#define MEMBERS_5(a, b, c, d, e) a; b; c; d; e;
#define MEMBERS_6(a, b, c, d, e, f) a; b; c; d; e; f;
#define MEMBERS_7(a, b, c, d, e, f, g) a; b; c; d; e; f; g;
#define MEMBERS_8(a, b, c, d, e, f, g, h) a; b; c; d; e; f; g; h;

// Updates Dynamax HP multipliers and healthboxes.
void BS_UpdateDynamax(void)
{
    NATIVE_ARGS();
    u16 battler = gBattleScripting.battler;
    struct Pokemon *mon = &GetSideParty(GetBattlerSide(battler))[gBattlerPartyIndexes[battler]];

    if (!IsGigantamaxed(battler)) // RecalcBattlerStats will get called on form change.
        RecalcBattlerStats(battler, mon);

    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_ALL);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Activates the secondary effect of a Max Move.
void BS_SetMaxMoveEffect(void)
{
    NATIVE_ARGS();
    u16 effect = 0;
    u8 maxEffect = gMovesInfo[gCurrentMove].argument;

    // Don't continue if the move didn't land.
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

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
                SET_STATCHANGER(gMovesInfo[gCurrentMove].argument, 1, FALSE);
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
                        statId = gMovesInfo[gCurrentMove].argument - MAX_EFFECT_LOWER_ATTACK + 1;
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
            u8 weather = 0, msg = 0;
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
            switch (gMovesInfo[gCurrentMove].argument)
            {
                case MAX_EFFECT_MISTY_TERRAIN:
                    statusFlag = STATUS_FIELD_MISTY_TERRAIN;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
                    break;
                case MAX_EFFECT_GRASSY_TERRAIN:
                    statusFlag = STATUS_FIELD_GRASSY_TERRAIN;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_GRASSY;
                    break;
                case MAX_EFFECT_ELECTRIC_TERRAIN:
                    statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
                    break;
                case MAX_EFFECT_PSYCHIC_TERRAIN:
                    statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
                    break;
            }
            if (!(gFieldStatuses & statusFlag) && statusFlag != 0)
            {
                gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
                gFieldStatuses |= statusFlag;
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
                    gFieldTimers.terrainTimer = 8;
                else
                    gFieldTimers.terrainTimer = 5;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectSetTerrain;
                effect++;
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
                gSideTimers[side].damageNonTypesType = gMovesInfo[gCurrentMove].type;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                ChooseDamageNonTypesString(gMovesInfo[gCurrentMove].type);
                gBattlescriptCurrInstr = BattleScript_DamageNonTypesStarts;
                effect++;
            }
            break;
        }
        case MAX_EFFECT_STEALTH_ROCK:
            if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEALTH_ROCK))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectStonesurge;
                effect++;
            }
            break;
        case MAX_EFFECT_STEELSURGE:
            if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEELSURGE))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SHARPSTEELFLOATS;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectSteelsurge;
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
        {
            static const u8 sSnoozeEffects[] = {TRUE, FALSE};
            if (!(gStatuses3[gBattlerTarget] & STATUS3_YAWN)
                && CanSleep(gBattlerTarget)
                && RandomElement(RNG_G_MAX_SNOOZE, sSnoozeEffects)) // 50% chance of success
            {
                gStatuses3[gBattlerTarget] |= STATUS3_YAWN_TURN(2);
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectYawnSuccess;
                effect++;
            }
            break;
        }
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
        {
            static const u8 sReplenishEffects[] = {TRUE, FALSE};
            if (RandomElement(RNG_G_MAX_REPLENISH, sReplenishEffects)) // 50% chance of success
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
                effect++;
            }
            break;
        }
    }

    if (!effect)
        gBattlescriptCurrInstr = cmd->nextInstr;
}

// Sets up sharp steel on the target's side.
void BS_SetSteelsurge(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideStatuses[targetSide] & SIDE_STATUS_STEELSURGE)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STEELSURGE;
        gSideTimers[targetSide].steelsurgeAmount = 1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

// Applies the status1 effect associated with a given G-Max Move.
// Could be expanded to function for any move.
void BS_TrySetStatus1(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u8 effect = 0;
    u32 status1 = GetMaxMoveStatusEffect(gCurrentMove);
    switch (status1)
    {
        case STATUS1_POISON:
            if (CanBePoisoned(gBattlerAttacker, gBattlerTarget))
            {
                gBattleMons[gBattlerTarget].status1 |= STATUS1_POISON;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                effect++;
            }
            break;
        case STATUS1_PARALYSIS:
            if (CanBeParalyzed(gBattlerTarget))
            {
                gBattleMons[gBattlerTarget].status1 |= STATUS1_PARALYSIS;
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                effect++;
            }
            break;
        case STATUS1_SLEEP:
            if (CanSleep(gBattlerTarget))
            {
                if (B_SLEEP_TURNS >= GEN_5)
                    gBattleMons[gBattlerTarget].status1 |=  STATUS1_SLEEP_TURN((Random() % 3) + 2);
                else
                    gBattleMons[gBattlerTarget].status1 |=  STATUS1_SLEEP_TURN((Random() % 4) + 3);
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
                effect++;
            }
            break;
    }
    if (effect)
    {
        gEffectBattler = gBattlerTarget;
        BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
        MarkBattlerForControllerExec(gBattlerTarget);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Applies the status2 effect associated with a given G-Max Move.
void BS_TrySetStatus2(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u8 effect = 0;
    u32 status2 = GetMaxMoveStatusEffect(gCurrentMove);
    switch (status2)
    {
        case STATUS2_CONFUSION:
            if (CanBeConfused(gBattlerTarget))
            {
                gBattleMons[gBattlerTarget].status2 |= STATUS2_CONFUSION_TURN(((Random()) % 4) + 2);
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                gBattleCommunication[MULTIUSE_STATE] = 1;
                effect++;
            }
            break;
        case STATUS2_INFATUATION:
        {
            u8 atkGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerAttacker].species, gBattleMons[gBattlerAttacker].personality);
            u8 defGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerTarget].species, gBattleMons[gBattlerTarget].personality);
            if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION)
                && gBattleMons[gBattlerTarget].ability != ABILITY_OBLIVIOUS
                && !IsAbilityOnSide(gBattlerTarget, ABILITY_AROMA_VEIL)
                && atkGender != defGender
                && atkGender != MON_GENDERLESS
                && defGender != MON_GENDERLESS)
            {
                gBattleMons[gBattlerTarget].status2 |= STATUS2_INFATUATED_WITH(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                gBattleCommunication[MULTIUSE_STATE] = 2;
                effect++;
            }
            break;
        }
        case STATUS2_ESCAPE_PREVENTION:
            if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
            {
                gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                effect++;
            }
            break;
        case STATUS2_TORMENT:
            if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_TORMENT)
                && !IsAbilityOnSide(gBattlerTarget, ABILITY_AROMA_VEIL))
            {
                gBattleMons[gBattlerTarget].status2 |= STATUS2_TORMENT;
                gDisableStructs[gBattlerTarget].tormentTimer = 3; // 3 turns excluding current turn
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                effect++;
            }
            break;
    }
    if (effect)
    {
        gEffectBattler = gBattlerTarget;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Applies the endturn damage effect associated with the "Damage Non-" G-Max moves.
void BS_DamageNonTypes(void)
{
    NATIVE_ARGS();
    u8 side = GetBattlerSide(gBattlerAttacker);
    gBattleMoveDamage = 0;
    if (gSideTimers[side].damageNonTypesTimer
        && !IS_BATTLER_OF_TYPE(gBattlerAttacker, gSideTimers[side].damageNonTypesType)
        && IsBattlerAlive(gBattlerAttacker)
        && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
    {
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 6;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Heals one-sixth of the target's HP, including for Dynamaxed targets.
void BS_HealOneSixth(void)
{
    NATIVE_ARGS(const u8* failInstr);
    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 6;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
        gBattlescriptCurrInstr = cmd->failInstr;    // fail
    else
        gBattlescriptCurrInstr = cmd->nextInstr;    // can heal
}

// Recycles the target's item if it is specifically holding a berry.
void BS_TryRecycleBerry(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u16* usedHeldItem = &gBattleStruct->usedHeldItems[gBattlerPartyIndexes[gBattlerTarget]][GetBattlerSide(gBattlerTarget)];
    if (gBattleMons[gBattlerTarget].item == ITEM_NONE
        && gBattleStruct->changedItems[gBattlerTarget] == ITEM_NONE   // Will not inherit an item
        && ItemId_GetPocket(*usedHeldItem) == POCKET_BERRIES)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = ITEM_NONE;
        gBattleMons[gBattlerTarget].item = gLastUsedItem;

        BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[gBattlerTarget].item);
        MarkBattlerForControllerExec(gBattlerTarget);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Goes to the jump instruction if the target is Dynamaxed.
void BS_JumpIfDynamaxed(void)
{
    NATIVE_ARGS(const u8 *jumpInstr);
    if (IsDynamaxed(gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
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
    if (gBattleStruct->dynamax.triggerSpriteId >= MAX_SPRITES)
        return;
    ChangeDynamaxTriggerSprite(gBattleStruct->dynamax.triggerSpriteId, 0);
    gSprites[gBattleStruct->dynamax.triggerSpriteId].tHide = TRUE;
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
