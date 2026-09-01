#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HOLD_HANDS) == EFFECT_HOLD_HANDS);
}

DOUBLE_BATTLE_TEST("Hold Hands is blocked by Crafty Shield")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CRAFTY_SHIELD, target: opponentLeft);
            MOVE(playerRight, MOVE_HOLD_HANDS, target: playerLeft);
        }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HOLD_HANDS, playerLeft);
        MESSAGE("Wynaut protected itself!");
    }
}
