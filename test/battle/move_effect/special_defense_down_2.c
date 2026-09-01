#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_FAKE_TEARS, spDef: -2);
}

SINGLE_BATTLE_TEST("Fake Tears reduces the target's Sp. Defense by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FAKE_TEARS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_TEARS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 2);
    }
}
