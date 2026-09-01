#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_EERIE_IMPULSE, spAtk: -2);
}

SINGLE_BATTLE_TEST("Eerie Impulse reduces the target's Sp. Attack by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_IMPULSE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
    }
}
