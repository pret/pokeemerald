#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_CALM_MIND, spAtk: +1, spDef: +1);
}

SINGLE_BATTLE_TEST("Calm Mind increases the user's Sp. Attack and Sp. Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CALM_MIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CALM_MIND, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}
