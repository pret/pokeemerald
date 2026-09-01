#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
}

SINGLE_BATTLE_TEST("Scary Face reduces the target's Speed by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 2);
    }
}
