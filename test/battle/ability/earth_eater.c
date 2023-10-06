#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Earth Eater heals 25% when hit by ground type moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MUD_SLAP].type == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EARTH_EATER);
        HP_BAR(player, damage: -25);
        MESSAGE("Wobbuffet restored HP using its Earth Eater!");
    }
}

SINGLE_BATTLE_TEST("Earth Eater does not activate if protected")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MUD_SLAP].type == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_EARTH_EATER); HP_BAR(player); MESSAGE("Wobbuffet restored HP using its Earth Eater!"); }
    }
}

SINGLE_BATTLE_TEST("Earth Eater activates on status moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SAND_ATTACK].type == TYPE_GROUND);
        ASSUME(gBattleMoves[MOVE_SAND_ATTACK].split == SPLIT_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_EARTH_EATER); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAND_ATTACK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EARTH_EATER);
        HP_BAR(player, damage: -25);
        MESSAGE("Wobbuffet restored HP using its Earth Eater!");
    }
}
