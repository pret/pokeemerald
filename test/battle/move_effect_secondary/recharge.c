#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_METEOR_ASSAULT, MOVE_EFFECT_RECHARGE) == TRUE);
}

SINGLE_BATTLE_TEST("Recharge moves make the user unable to attack for exactly one turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WOBBUFFET) { }
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_ASSAULT, player);
        MESSAGE("Wobbuffet must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Recharge moves don't timeout when all battlers are recharging")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WOBBUFFET) { }
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_ASSAULT); MOVE(opponent, MOVE_METEOR_ASSAULT); }
    }
}

DOUBLE_BATTLE_TEST("Recharge moves don't timeout when all battlers are recharging (doubles")
{

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { }
        PLAYER(SPECIES_WYNAUT) { }
        OPPONENT(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WYNAUT) { }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_METEOR_ASSAULT, target: opponentLeft);
            MOVE(playerRight, MOVE_METEOR_ASSAULT, target: opponentRight);
            MOVE(opponentLeft, MOVE_METEOR_ASSAULT, target: playerLeft);
            MOVE(opponentRight, MOVE_METEOR_ASSAULT, target: playerRight);
        }
    }
}
