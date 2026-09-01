#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_NOBLE_ROAR, attack: -1, spAtk: -1);
}

SINGLE_BATTLE_TEST("Noble Roar reduces the target's Attack and Sp. Attack by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NOBLE_ROAR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NOBLE_ROAR, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
    }
}
