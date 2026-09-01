#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Cotton Down drops speed by one of opposing battler if hit by a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Cotton Down drops speed by one for each multi hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        ABILITY_POPUP(opponent, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed fell!");
        ABILITY_POPUP(opponent, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Cotton Down drops speed by one of all other battlers on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_COTTON_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wynaut's Speed fell!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Cotton Down correctly gets blocked by stat reduction preventing abilities")
{
    GIVEN {
        PLAYER(SPECIES_METAGROSS) { Ability(ABILITY_CLEAR_BODY); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_CLEAR_AMULET); }
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_COTTON_DOWN);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Corviknight's Speed fell!");
        }
        ABILITY_POPUP(opponentRight, ABILITY_MIRROR_ARMOR);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Metagross's Speed fell!");
        }
        ABILITY_POPUP(playerLeft, ABILITY_CLEAR_BODY);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Wynaut's Speed fell!");
        }
        MESSAGE("The effects of the Clear Amulet held by Wynaut prevents its stats from being lowered!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
