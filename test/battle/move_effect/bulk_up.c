#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_BULK_UP, attack: +1, defense: +1);
}

SINGLE_BATTLE_TEST("Bulk Up increases the user's Attack and Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULK_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULK_UP, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}
