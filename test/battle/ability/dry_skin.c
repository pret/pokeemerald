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
        MESSAGE("The Parasect's Dry Skin takes its toll!");
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
        MESSAGE("Parasect's Dry Skin restored its HP a little!");
        HP_BAR(player, damage: -(200 / 8));
    }
}

SINGLE_BATTLE_TEST("Dry Skin increases damage taken from Fire-type moves by 25%", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_EFFECT_SPORE; }
    PARAMETRIZE { ability = ABILITY_DRY_SKIN; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_EMBER].type == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PARASECT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Wobbuffet used Ember!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Dry Skin heals 25% when hit by water type moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_BUBBLE].type == TYPE_WATER);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect restored HP using its Dry Skin!");
    }
}

SINGLE_BATTLE_TEST("Dry Skin does not activate if protected")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_BUBBLE].type == TYPE_WATER);
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
        ASSUME(gBattleMoves[MOVE_WATER_SHURIKEN].type == TYPE_WATER);
        ASSUME(gBattleMoves[MOVE_WATER_SHURIKEN].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_SHURIKEN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect restored HP using its Dry Skin!");
    }
}

SINGLE_BATTLE_TEST("Dry Skin prevents Absorb Bulb and Luminous Moss from activating")
{
    u32 item;
    PARAMETRIZE { item = ITEM_ABSORB_BULB; }
    PARAMETRIZE { item = ITEM_LUMINOUS_MOSS; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_BUBBLE].type == TYPE_WATER);
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); HP(100); MaxHP(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRY_SKIN);
        HP_BAR(player, damage: -50);
        MESSAGE("Parasect restored HP using its Dry Skin!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}
