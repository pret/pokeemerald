#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_VICTORY_DANCE, attack: +1, defense: +1, speed: +1);
}

SINGLE_BATTLE_TEST("Victory Dance increases the user's Attack, Defense and Speed by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_VICTORY_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VICTORY_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
