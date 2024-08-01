#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shed Skin triggers 30% of the time")
{
    PASSES_RANDOMLY(3, 10, RNG_SHED_SKIN);
    GIVEN {
        ASSUME(B_ABILITY_TRIGGER_CHANCE >= GEN_4);
        ASSUME(gMovesInfo[MOVE_TACKLE].makesContact);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Status1(STATUS1_POISON); Ability(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN;
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHED_SKIN);
        MESSAGE("Foe Arbok's Shed Skin cured its poison problem!");
        STATUS_ICON(opponent, poison: FALSE);
    }
}
