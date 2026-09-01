#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_REVENGE) == EFFECT_REVENGE);
}

SINGLE_BATTLE_TEST("Revenge doubles in power if False Swipe connected but didn't do any damage")
{
    s16 hits[3];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_REVENGE); }
        TURN { MOVE(opponent, MOVE_FALSE_SWIPE); MOVE(player, MOVE_REVENGE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_REVENGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, player);
        HP_BAR(opponent, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, player);
        HP_BAR(opponent, captureDamage: &hits[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, player);
        HP_BAR(opponent, captureDamage: &hits[2]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
        EXPECT_EQ(hits[0], hits[2]);
    }
}

DOUBLE_BATTLE_TEST("Revenge doesn't double in power if user was not hit by target in doubles")
{
    s16 hits[3];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_REVENGE, target: playerRight); }
        TURN {
            MOVE(playerRight, MOVE_POUND, target: opponentRight);
            MOVE(opponentLeft, MOVE_REVENGE, target: playerRight);
        }
        TURN {
            MOVE(playerRight, MOVE_POUND, target: opponentLeft);
            MOVE(opponentLeft, MOVE_REVENGE, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, opponentLeft);
        HP_BAR(playerRight, captureDamage: &hits[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, opponentLeft);
        HP_BAR(playerRight, captureDamage: &hits[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVENGE, opponentLeft);
        HP_BAR(playerRight, captureDamage: &hits[2]);
    } THEN {
        EXPECT_EQ(hits[0], hits[1]);
        EXPECT_MUL_EQ(hits[1], Q_4_12(2.0), hits[2]);
    }
}
