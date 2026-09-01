#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);
}

SINGLE_BATTLE_TEST("Amnesia increases the user's Sp. Defense by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AMNESIA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AMNESIA, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
    }
}
