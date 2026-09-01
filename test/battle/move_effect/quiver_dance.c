#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_QUIVER_DANCE, spAtk: +1, spDef: +1, speed: +1);
}

SINGLE_BATTLE_TEST("Quiver Dance increases the user's Sp. Attack, Sp. Defense and Speed by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_QUIVER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUIVER_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
