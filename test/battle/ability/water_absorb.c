#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Water Absorb heals 25% when hit by water type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_POLIWAG) { Ability(ABILITY_WATER_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WATER_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Poliwag had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Water Absorb does not activate if protected")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_POLIWAG) { Ability(ABILITY_WATER_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_WATER_ABSORB); HP_BAR(player); MESSAGE("Poliwag had its HP restored."); }
    }
}

SINGLE_BATTLE_TEST("Water Absorb activates on status moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SOAK) == TYPE_WATER);
        ASSUME(GetMoveCategory(MOVE_SOAK) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_POLIWAG) { Ability(ABILITY_WATER_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SOAK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WATER_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Poliwag had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Water Absorb is only triggered once on multi strike moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_SHURIKEN) == TYPE_WATER);
        ASSUME(IsMultiHitMove(MOVE_WATER_SHURIKEN));
        PLAYER(SPECIES_POLIWAG) { Ability(ABILITY_WATER_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_SHURIKEN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WATER_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Poliwag had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Water Absorb prevents Absorb Bulb and Luminous Moss from activating")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_ABSORB_BULB; }
    PARAMETRIZE { item = ITEM_LUMINOUS_MOSS; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUBBLE) == TYPE_WATER);
        PLAYER(SPECIES_POLIWAG) { Ability(ABILITY_WATER_ABSORB); HP(1); MaxHP(100); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BUBBLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WATER_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Poliwag had its HP restored.");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }

    }
}
