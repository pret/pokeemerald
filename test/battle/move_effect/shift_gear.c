#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_SHIFT_GEAR, attack: +1, speed: +2);
}

SINGLE_BATTLE_TEST("Shift Gear increases the user's Speed by 2 stages and Attack by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHIFT_GEAR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHIFT_GEAR, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
