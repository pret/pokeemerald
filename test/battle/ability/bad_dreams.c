#include "global.h"
#include "test/battle.h"

// Also checks that non-sleeping enemy is not affected.
SINGLE_BATTLE_TEST("Bad Dreams causes the sleeping enemy Pokemon to lose 1/8 of HP")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    GIVEN {
        PLAYER(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN {}
    } SCENE {
        if (status == STATUS1_SLEEP) {
            ABILITY_POPUP(player, ABILITY_BAD_DREAMS);
            MESSAGE("The opposing Wobbuffet is tormented!");
            HP_BAR(opponent);
        }
        else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_BAD_DREAMS);
                MESSAGE("The opposing Wobbuffet is tormented!");
                HP_BAR(opponent);
            };
        }
    } THEN {
        if (status == STATUS1_SLEEP) {
            EXPECT_EQ(opponent->hp, opponent->maxHP - opponent->maxHP / 8);
        }
        else {
            EXPECT_EQ(opponent->hp, opponent->maxHP);
        }
    }
}

SINGLE_BATTLE_TEST("Bad Dreams causes Pokémon with Comatose to lose 1/8 of HP")
{
    GIVEN {
        PLAYER(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        OPPONENT(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BAD_DREAMS);
        MESSAGE("The opposing Komala is tormented!");
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, opponent->maxHP - opponent->maxHP / 8);
    }
}

DOUBLE_BATTLE_TEST("Bad Dreams does not activate if only the partner Pokemon is sleeping")
{
    GIVEN {
        PLAYER(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_BAD_DREAMS);
            MESSAGE("Wobbuffet is tormented!");
            HP_BAR(playerRight);
        };
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Bad Dreams activates for both sleeping Pokémon on the player side")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_BAD_DREAMS);
        MESSAGE("Wobbuffet is tormented!");
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet is tormented!");
        HP_BAR(playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(playerLeft->hp, playerLeft->maxHP - playerLeft->maxHP / 8);
        EXPECT_EQ(playerRight->hp, playerRight->maxHP - playerRight->maxHP / 8);
    }
}

DOUBLE_BATTLE_TEST("Bad Dreams faints both sleeping Pokemon on player side")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SEND_OUT(playerLeft, 2); SEND_OUT(playerRight, 3); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_BAD_DREAMS);
        MESSAGE("Wobbuffet is tormented!");
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Wobbuffet is tormented!");
        HP_BAR(playerRight);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Bad Dreams faints both sleeping Pokemon on opponent side")
{
    GIVEN {
        PLAYER(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { SEND_OUT(opponentLeft, 2); SEND_OUT(opponentRight, 3); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BAD_DREAMS);
        MESSAGE("The opposing Wobbuffet is tormented!");
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("The opposing Wobbuffet is tormented!");
        HP_BAR(opponentRight);
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Bad Dreams does not leave subsequent ABILITY_POPUP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_DARKRAI) { Ability(ABILITY_BAD_DREAMS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TAPU_BULU) { Ability(ABILITY_GRASSY_SURGE); }
    } WHEN {
        TURN {}
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_BAD_DREAMS);
        MESSAGE("Wobbuffet is tormented!");
        HP_BAR(playerRight);
        ABILITY_POPUP(opponentRight, ABILITY_GRASSY_SURGE);
        MESSAGE("Grass grew to cover the battlefield!");
    } THEN {
        EXPECT_EQ(gBattleScripting.fixedPopup, FALSE);
    }
}
