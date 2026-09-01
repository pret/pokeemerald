#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_DECORATE, attack: +2, spAtk: +2);
}

SINGLE_BATTLE_TEST("Decorate raises the target's Attack and Sp. Attack by 2 stages each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DECORATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DECORATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}
