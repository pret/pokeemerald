#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Aromatic Mist raises Sp. Defense of a target ally by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING_GALAR);
        PLAYER(SPECIES_SYLVEON);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AROMATIC_MIST); }
    } SCENE {
        MESSAGE("Weezing used Aromatic Mist!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Aromatic Mist fails in Single Battles")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING_GALAR);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AROMATIC_MIST); }
    } SCENE {
        MESSAGE("Weezing used Aromatic Mist!");
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}
