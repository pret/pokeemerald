#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
}

SINGLE_BATTLE_TEST("Laser Focus causes the user's move used on the next turn to result in a Critical Hit")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LASER_FOCUS); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}
