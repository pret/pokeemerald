#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_NASTY_PLOT, spAtk: +2);
}

SINGLE_BATTLE_TEST("Nasty Plot increases the user's Sp. Attack by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NASTY_PLOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NASTY_PLOT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}
