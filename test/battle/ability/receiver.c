#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Receiver copies ally's ability when they faint and immediately activates it")
{
    GIVEN {
        ASSUME(!gAbilitiesInfo[ABILITY_INTIMIDATE].cantBeCopied);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PASSIMIAN) { Ability(ABILITY_RECEIVER); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Receiver copies ally's ability when they faint and can activate it on future moves")
{
    GIVEN {
        ASSUME(!gAbilitiesInfo[ABILITY_WATER_ABSORB].cantBeCopied);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PASSIMIAN) { Ability(ABILITY_RECEIVER); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_WATER_ABSORB); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
        ABILITY_POPUP(opponentLeft, ABILITY_WATER_ABSORB);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Receiver copies ally's Soul Heart and immediately activates it")
{
    GIVEN {
        ASSUME(!gAbilitiesInfo[ABILITY_SOUL_HEART].cantBeCopied);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PASSIMIAN) { Ability(ABILITY_RECEIVER); }
        OPPONENT(SPECIES_MAGEARNA) { Ability(ABILITY_SOUL_HEART); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
        ABILITY_POPUP(opponentLeft, ABILITY_SOUL_HEART);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Receiver (Ability) test titles")
