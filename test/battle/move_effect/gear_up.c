#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GEAR_UP) == EFFECT_STAT_CHANGE_MAGNETIC);
}

SINGLE_BATTLE_TEST("Gear Up raises Attack and Sp. Attack of the user with Plus/Minus in singles")
{
    GIVEN {
        PLAYER(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        OPPONENT(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_GEAR_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEAR_UP, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Gear Up raises Attack and Sp. Attack of all Plus/Minus allies in doubles")
{
    GIVEN {
        PLAYER(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
        OPPONENT(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        OPPONENT(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GEAR_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEAR_UP, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Gear Up used by both battlers raises Attack and Sp. Attack of a single opponent with plus/minus twice")
{
    GIVEN {
        PLAYER(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GEAR_UP); MOVE(opponentRight, MOVE_GEAR_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEAR_UP, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GEAR_UP, opponentRight);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}
