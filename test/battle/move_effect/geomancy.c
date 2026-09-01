#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_GEOMANCY, spAtk: +2, spDef: +2, speed: +2);
}

SINGLE_BATTLE_TEST("Geomancy does not boost stats on first turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Geomancy takes 2 turns to increase Sp. Atk, Sp. Def and Speed by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Geomancy only takes 1 turn when holding Power Herb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Geomancy fails on the second turn if the user falls for Taunt while charging")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); MOVE(opponent, MOVE_TAUNT); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GEOMANCY, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
