#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_VENOM_DRENCH) == EFFECT_STAT_CHANGE_ON_STATUS);
}

SINGLE_BATTLE_TEST("Venom Drench lowers stats of a poisoned target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(player, MOVE_VENOM_DRENCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VENOM_DRENCH, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Venom Drench is blocked by Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_VENOM_DRENCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_VENOM_DRENCH, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Venom Drench lowers stats of a poisoned target - Doubles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VENOM_DRENCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VENOM_DRENCH, playerLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}
