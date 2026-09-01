#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_TICKLE, attack: -1, defense: -1);
}

SINGLE_BATTLE_TEST("Tickle reduces the target's Attack and Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TICKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TICKLE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Tickle is blocked by Substitute (Gen4+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TICKLE, MOVE_CELEBRATE); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SUBSTITUTE, MOVE_CELEBRATE); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TICKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TICKLE, player);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}
