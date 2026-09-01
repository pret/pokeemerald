#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Spite reduces the PP the last move used even while asleep")
{
    GIVEN {
        WITH_CONFIG(B_PP_REDUCED_BY_SPITE, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CELEBRATE, MOVE_POUND); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_CELEBRATE, MOVE_SPORE, MOVE_SPITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_POUND); }
        TURN { MOVE(opponent, MOVE_SPITE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITE, opponent);
        MESSAGE("Wobbuffet lost 4 PP from Pound!");
    }
}

SINGLE_BATTLE_TEST("Spite fails if target has not used any move yet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SPITE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITE, opponent);
        }
    }
}
