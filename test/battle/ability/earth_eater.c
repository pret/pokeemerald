#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Earth Eater heals 25% when hit by ground type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_ORTHWORM) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EARTH_EATER);
        HP_BAR(player, damage: -25);
        MESSAGE("Orthworm had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Earth Eater does not activate if protected")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_ORTHWORM) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_EARTH_EATER); HP_BAR(player);
            MESSAGE("Orthworm had its HP restored.");
        }
    }
}

SINGLE_BATTLE_TEST("Earth Eater activates on status moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SAND_ATTACK) == TYPE_GROUND);
        ASSUME(GetMoveCategory(MOVE_SAND_ATTACK) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_ORTHWORM) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAND_ATTACK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EARTH_EATER);
        HP_BAR(player, damage: -25);
        MESSAGE("Orthworm had its HP restored.");
    }
}
