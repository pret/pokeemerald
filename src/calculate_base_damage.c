#include "global.h"
#include "abilities.h"
#include "battle.h"
#include "hold_effects.h"
#include "event_data.h"
#include "item.h"
#include "items.h"
#include "pokemon.h"
#include "species.h"
#include "moves.h"
#include "battle_move_effects.h"

extern u32 gBattleTypeFlags;
extern struct BattlePokemon gBattleMons[4];
extern u16 gCurrentMove;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;
extern struct BattleEnigmaBerry gEnigmaBerries[];
extern u16 gBattleMovePower;
extern u16 gTrainerBattleOpponent;

u8 CountAliveMonsInBattle(u8);
bool8 ShouldGetStatBadgeBoost(u16 flagId, u8 bank);

extern const struct BattleMove gBattleMoves[];
extern const u8 gHoldEffectToType[][2];
extern const u8 gStatStageRatios[][2];

#define APPLY_STAT_MOD(var, mon, stat, statIndex)                                   \
{                                                                                   \
    (var) = (stat) * (gStatStageRatios)[(mon)->statStages[(statIndex)]][0];         \
    (var) /= (gStatStageRatios)[(mon)->statStages[(statIndex)]][1];                 \
}

s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 bankAtk, u8 bankDef)
{
    u32 i;
    s32 damage = 0;
    s32 damageHelper;
    u8 type;
    u16 attack, defense;
    u16 spAttack, spDefense;
    u8 defenderHoldEffect;
    u8 defenderHoldEffectParam;
    u8 attackerHoldEffect;
    u8 attackerHoldEffectParam;

    if (!powerOverride)
        gBattleMovePower = gBattleMoves[move].power;
    else
        gBattleMovePower = powerOverride;

    if (!typeOverride)
        type = gBattleMoves[move].type;
    else
        type = typeOverride & 0x3F;

    attack = attacker->attack;
    defense = defender->defense;
    spAttack = attacker->spAttack;
    spDefense = defender->spDefense;

    if (attacker->item == ITEM_ENIGMA_BERRY)
    {
        attackerHoldEffect = gEnigmaBerries[bankAtk].holdEffect;
        attackerHoldEffectParam = gEnigmaBerries[bankAtk].holdEffectParam;
    }
    else
    {
        attackerHoldEffect = ItemId_GetHoldEffect(attacker->item);
        attackerHoldEffectParam = ItemId_GetHoldEffectParam(attacker->item);
    }

    if (defender->item == ITEM_ENIGMA_BERRY)
    {
        defenderHoldEffect = gEnigmaBerries[bankDef].holdEffect;
        defenderHoldEffectParam = gEnigmaBerries[bankDef].holdEffectParam;
    }
    else
    {
        defenderHoldEffect = ItemId_GetHoldEffect(defender->item);
        defenderHoldEffectParam = ItemId_GetHoldEffectParam(defender->item);
    }

    if (attacker->ability == ABILITY_HUGE_POWER || attacker->ability == ABILITY_PURE_POWER)
        attack *= 2;

    if (ShouldGetStatBadgeBoost(BADGE01_GET, bankAtk))
        attack = (110 * attack) / 100;
    if (ShouldGetStatBadgeBoost(BADGE05_GET, bankDef))
        defense = (110 * defense) / 100;
    if (ShouldGetStatBadgeBoost(BADGE07_GET, bankAtk))
        spAttack = (110 * spAttack) / 100;
    if (ShouldGetStatBadgeBoost(BADGE07_GET, bankDef))
        spDefense = (110 * spDefense) / 100;

    for (i = 0; i < 17; i++)
    {
        if (attackerHoldEffect == gHoldEffectToType[i][0]
            && type == gHoldEffectToType[i][1])
        {
            if (type <= 8)
                attack = (attack * (attackerHoldEffectParam + 100)) / 100;
            else
                spAttack = (spAttack * (attackerHoldEffectParam + 100)) / 100;
            break;
        }
    }

    if (attackerHoldEffect == HOLD_EFFECT_CHOICE_BAND)
        attack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_FRONTIER)) && (attacker->species == SPECIES_LATIAS || attacker->species == SPECIES_LATIOS))
        spAttack = (150 * spAttack) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_FRONTIER)) && (defender->species == SPECIES_LATIAS || defender->species == SPECIES_LATIOS))
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_DEEP_SEA_TOOTH && attacker->species == SPECIES_CLAMPERL)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_DEEP_SEA_SCALE && defender->species == SPECIES_CLAMPERL)
        spDefense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_LIGHT_BALL && attacker->species == SPECIES_PIKACHU)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_METAL_POWDER && defender->species == SPECIES_DITTO)
        defense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_THICK_CLUB && (attacker->species == SPECIES_CUBONE || attacker->species == SPECIES_MAROWAK))
        attack *= 2;
    if (defender->ability == ABILITY_THICK_FAT && (type == TYPE_FIRE || type == TYPE_ICE))
        spAttack /= 2;
    if (attacker->ability == ABILITY_HUSTLE)
        attack = (150 * attack) / 100;
    if (attacker->ability == ABILITY_PLUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_MINUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_MINUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_PLUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_GUTS && attacker->status1)
        attack = (150 * attack) / 100;
    if (defender->ability == ABILITY_MARVEL_SCALE && defender->status1)
        defense = (150 * defense) / 100;
    if (type == TYPE_ELECTRIC && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFD, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_FIRE && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFE, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_GRASS && attacker->ability == ABILITY_OVERGROW && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_FIRE && attacker->ability == ABILITY_BLAZE && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_WATER && attacker->ability == ABILITY_TORRENT && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_BUG && attacker->ability == ABILITY_SWARM && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (gBattleMoves[gCurrentMove].effect == EFFECT_EXPLOSION)
        defense /= 2;

    if (type < TYPE_MYSTERY) // is physical
    {
        if (gCritMultiplier == 2)
        {
            if (attacker->statStages[STAT_STAGE_ATK] > 6)
                APPLY_STAT_MOD(damage, attacker, attack, STAT_STAGE_ATK)
            else
                damage = attack;
        }
        else
            APPLY_STAT_MOD(damage, attacker, attack, STAT_STAGE_ATK)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier == 2)
        {
            if (defender->statStages[STAT_STAGE_DEF] < 6)
                APPLY_STAT_MOD(damageHelper, defender, defense, STAT_STAGE_DEF)
            else
                damageHelper = defense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, defense, STAT_STAGE_DEF)

        damage = damage / damageHelper;
        damage /= 50;

        if ((attacker->status1 & STATUS_BURN) && attacker->ability != ABILITY_GUTS)
            damage /= 2;

        if ((sideStatus & SIDE_STATUS_REFLECT) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMonsInBattle(2) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }

        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMoves[move].target == 8 && CountAliveMonsInBattle(2) == 2)
            damage /= 2;

        // moves always do at least 1 damage.
        if (damage == 0)
            damage = 1;
    }

    if (type == TYPE_MYSTERY)
        damage = 0; // is ??? type. does 0 damage.

    if (type > TYPE_MYSTERY) // is special?
    {
        if (gCritMultiplier == 2)
        {
            if (attacker->statStages[STAT_STAGE_SPATK] > 6)
                APPLY_STAT_MOD(damage, attacker, spAttack, STAT_STAGE_SPATK)
            else
                damage = spAttack;
        }
        else
            APPLY_STAT_MOD(damage, attacker, spAttack, STAT_STAGE_SPATK)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier == 2)
        {
            if (defender->statStages[STAT_STAGE_SPDEF] < 6)
                APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_STAGE_SPDEF)
            else
                damageHelper = spDefense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_STAGE_SPDEF)

        damage = (damage / damageHelper);
        damage /= 50;

        if ((sideStatus & SIDE_STATUS_LIGHTSCREEN) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMonsInBattle(2) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }

        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMoves[move].target == 8 && CountAliveMonsInBattle(2) == 2)
            damage /= 2;

        // are effects of weather negated with cloud nine or air lock
        if (!AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_CLOUD_NINE, 0, 0)
            && !AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_AIR_LOCK, 0, 0))
        {
            if (gBattleWeather & WEATHER_RAIN_TEMPORARY)
            {
                switch (type)
                {
                case TYPE_FIRE:
                    damage /= 2;
                    break;
                case TYPE_WATER:
                    damage = (15 * damage) / 10;
                    break;
                }
            }

            // any weather except sun weakens solar beam
            if ((gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_HAIL)) && gCurrentMove == MOVE_SOLAR_BEAM)
                damage /= 2;

            // sunny
            if (gBattleWeather & WEATHER_SUN_ANY)
            {
                switch (type)
                {
                case TYPE_FIRE:
                    damage = (15 * damage) / 10;
                    break;
                case TYPE_WATER:
                    damage /= 2;
                    break;
                }
            }
        }

        // flash fire triggered
        if ((gBattleResources->flags->flags[bankAtk] & UNKNOWN_FLAG_FLASH_FIRE) && type == TYPE_FIRE)
            damage = (15 * damage) / 10;
    }

    return damage + 2;
}
