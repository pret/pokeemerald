#include "global.h"
#include "test/battle.h"

// There's no move with EFFECT_EVASION_UP_2 effect. Below is a theoretical test.

/*
ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_X) == EFFECT_EVASION_UP_2);
}

SINGLE_BATTLE_TEST("Double Team raises Evasion by 1 stage")
{
    PASSES_RANDOMLY(GetMoveAccuracy(MOVE_SCRATCH) * 3 / 5, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_X); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_X, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's evasiveness rose sharply!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}
*/
