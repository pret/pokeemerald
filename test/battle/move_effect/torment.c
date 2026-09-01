#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
}

SINGLE_BATTLE_TEST("Torment prevents consecutive move uses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TORMENT); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(opponent, MOVE_SPLASH, allowed: FALSE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, player);
        MESSAGE("The opposing Wobbuffet was subjected to torment!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Torment forces Struggle if the only move is prevented")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_TORMENT); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(opponent, MOVE_SPLASH, allowed: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Torment allows non-consecutive move uses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TORMENT); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
    }
}

DOUBLE_BATTLE_TEST("Torment works even if the target's last move failed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SUCKER_PUNCH); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SUCKER_PUNCH, target: playerRight);
            MOVE(opponentRight, MOVE_SUCKER_PUNCH, target: playerLeft);
            MOVE(playerRight, MOVE_FOLLOW_ME);
            MOVE(playerLeft, MOVE_TORMENT, target: opponentLeft);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SUCKER_PUNCH, target: playerLeft, allowed: FALSE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentLeft);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentRight);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, playerLeft);
        MESSAGE("The opposing Wobbuffet was subjected to torment!");
    }
}
