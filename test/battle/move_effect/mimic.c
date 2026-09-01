#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mimic doesn't error when the last move used by the target resolves to MOVE_UNAVAILABLE")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {MOVE(opponent, MOVE_TRANSFORM); MOVE(player, MOVE_MIMIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIMIC, player);
    } THEN {
        EXPECT_EQ(gLastMoves[1], MOVE_UNAVAILABLE); // This test depends on the current implementation of Transform, if this changes, the test should be changed
    }
}

SINGLE_BATTLE_TEST("Mimic copies the last move used even while asleep")
{
    GIVEN {
        WITH_CONFIG(B_PP_REDUCED_BY_SPITE, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CELEBRATE, MOVE_POUND); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_CELEBRATE, MOVE_SPORE, MOVE_MIMIC); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_POUND); }
        TURN { MOVE(opponent, MOVE_MIMIC); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIMIC, opponent);
        MESSAGE("The opposing Wobbuffet learned Pound!");
    }
}

SINGLE_BATTLE_TEST("Mimic fails if target has not used any move yet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_MIMIC); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MIMIC, opponent);
        }
    }
}
