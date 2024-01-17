#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sleep prevents the battler from using a move")
{
    u32 turns, j;
    PARAMETRIZE { turns = 1; }
    PARAMETRIZE { turns = 2; }
    PARAMETRIZE { turns = 3; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(turns)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < turns; j++)
            TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        for (j = 0; j < turns - 1; j++)
            MESSAGE("Wobbuffet is fast asleep.");
        MESSAGE("Wobbuffet woke up!");
        STATUS_ICON(player, none: TRUE);
        MESSAGE("Wobbuffet used Celebrate!");
    }
}
