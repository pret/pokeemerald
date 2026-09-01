#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGNETIC_FLUX) == EFFECT_STAT_CHANGE_MAGNETIC);
}

SINGLE_BATTLE_TEST("Magnetic Flux raises Defense and Sp. Defense of the user with Plus/Minus in singles")
{
    GIVEN {
        PLAYER(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        OPPONENT(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNETIC_FLUX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNETIC_FLUX, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Magnetic Flux raises Defense and Sp. Defense of all Plus/Minus allies in doubles")
{
    GIVEN {
        PLAYER(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        PLAYER(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
        OPPONENT(SPECIES_PLUSLE) { Ability(ABILITY_PLUS); }
        OPPONENT(SPECIES_MINUN) { Ability(ABILITY_MINUS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MAGNETIC_FLUX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNETIC_FLUX, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}
