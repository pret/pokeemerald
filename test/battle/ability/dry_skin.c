#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dry Skin causes 1/8th Max HP damage in Sun")
{
    GIVEN {
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: 200 / 8);
    }
}

SINGLE_BATTLE_TEST("Dry Skin doesn't get damaged in Sun if Cloud Nine/Air Lock is on the field")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DRY_SKIN);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Dry Skin heals 1/8th Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SIMPLE_HEAL, player);
        HP_BAR(player, damage: -(200 / 8));
    }
}

SINGLE_BATTLE_TEST("Dry Skin doesn't heal in Rain if Cloud Nine/Air Lock is on the field")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DRY_SKIN);
            HP_BAR(player);
            MESSAGE("Parasect had its HP restored.");
        }
    }
}

SINGLE_BATTLE_TEST("Dry Skin increases damage taken from Fire-type moves by 25%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_EFFECT_SPORE; }
    PARAMETRIZE { ability = ABILITY_DRY_SKIN; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMovePower(MOVE_EMBER) == 40);
        ASSUME(GetSpeciesType(SPECIES_PARASECT, 0) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_PARASECT, 1) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { SpAttack(71); }
        OPPONENT(SPECIES_PARASECT) { Ability(ability); SpDefense(165); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Wobbuffet used Ember!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // Due to numerics related to rounding on each applied multiplier,
        // the ability effect doesn't manifest as a 25% damage increase, but as a ~31% damage increase in this case.
        // Values obtained from https://calc.pokemonshowdown.com (Neutral nature and 0 IVs on both sides)
        EXPECT_EQ(results[0].damage, 52);
        EXPECT_EQ(results[1].damage, 68);
    }
}

SINGLE_BATTLE_TEST("Dry Skin heals 25% when hit by water type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Dry Skin does not activate if protected")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_DRY_SKIN); HP_BAR(player); MESSAGE("Parasect restored HP using its Dry Skin!"); }
    }
}

SINGLE_BATTLE_TEST("Dry Skin is only triggered once on multi strike moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_SHURIKEN) == TYPE_WATER);
        ASSUME(IsMultiHitMove(MOVE_WATER_SHURIKEN));
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_SHURIKEN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Dry Skin prevents Absorb Bulb and Luminous Moss from activating")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_ABSORB_BULB; }
    PARAMETRIZE { item = ITEM_LUMINOUS_MOSS; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect had its HP restored.");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}
