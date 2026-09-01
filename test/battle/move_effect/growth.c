#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Growth increases Attack and Sp. Atk by 1 stage or 2 stages under Sun (Gen 5+)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE;}
    PARAMETRIZE { move = MOVE_SUNNY_DAY;}

    GIVEN {
        WITH_CONFIG(B_GROWTH_STAT_RAISE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_GROWTH) == EFFECT_GROWTH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_GROWTH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWTH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        if (move == MOVE_CELEBRATE) {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        }
        else {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        }
    }
}

