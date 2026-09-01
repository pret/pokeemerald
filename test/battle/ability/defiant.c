#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Defiant sharply raises player's Attack after Intimidate")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_DEFIANT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_DEFIANT; }

    GIVEN {
        PLAYER(SPECIES_MANKEY) { Ability(abilityLeft); }
        PLAYER(SPECIES_PRIMEAPE) { Ability(abilityRight); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target:opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target:opponentRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Mankey's Attack fell!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Mankey's Attack rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Primeape's Attack fell!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Primeape's Attack rose sharply!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Mankey's Attack fell!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Mankey's Attack rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Primeape's Attack fell!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Primeape's Attack rose sharply!");
        }
    } THEN {
        // -2 from Intimidates and +4 from Defiants gets +2 total
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], (abilityLeft == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], (abilityRight == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
    }
}

// Same as above, but for opponent.
DOUBLE_BATTLE_TEST("Defiant sharply raises opponent's Attack after Intimidate")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_DEFIANT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_DEFIANT; }

    GIVEN {
        OPPONENT(SPECIES_MANKEY) { Ability(abilityLeft); }
        OPPONENT(SPECIES_PRIMEAPE) { Ability(abilityRight); }
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target:playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target:playerRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Mankey's Attack fell!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Mankey's Attack rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Primeape's Attack fell!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Primeape's Attack rose sharply!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Mankey's Attack fell!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Mankey's Attack rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Primeape's Attack fell!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Primeape's Attack rose sharply!");
        }
    } THEN {
        // -2 from Intimidates and +4 from Defiants gets +2 total
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], (abilityLeft == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], (abilityRight == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Defiant activates after Sticky Web lowers Speed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Mankey");
        MESSAGE("Mankey was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Speed fell!");
        // Defiant activates
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");
    }
}

SINGLE_BATTLE_TEST("Defiant doesn't activate after Sticky Web lowers Speed if Court Changed (Gen8)")
{
    GIVEN {
        WITH_CONFIG(B_DEFIANT_STICKY_WEB, GEN_8);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        ASSUME(GetMoveEffect(MOVE_COURT_CHANGE) == EFFECT_COURT_CHANGE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); MOVE(opponent, MOVE_COURT_CHANGE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COURT_CHANGE, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Mankey");
        MESSAGE("Mankey was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Speed fell!");
        // Defiant doesn't activate
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Mankey's Attack rose sharply!");
        }
        // Defiant triggers correctly after Sticky Web
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");
    }
}

SINGLE_BATTLE_TEST("Defiant activates after Sticky Web lowers Speed if Court Changed (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_DEFIANT_STICKY_WEB, GEN_9);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        ASSUME(GetMoveEffect(MOVE_COURT_CHANGE) == EFFECT_COURT_CHANGE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); MOVE(opponent, MOVE_COURT_CHANGE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COURT_CHANGE, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Mankey");
        MESSAGE("Mankey was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Speed fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");
        // Defiant triggers correctly after Sticky Web
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");
    }
}

DOUBLE_BATTLE_TEST("Defiant is activated by Cotton Down for non-ally Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
        OPPONENT(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_COTTON_DOWN);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Mankey's Speed fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Mankey's Speed fell!");
        ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Mankey's Attack rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Mankey's Speed fell!");
        ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Mankey's Attack rose sharply!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Defiant activates when opposing Syrup Bomb lowers Speed at end of turn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Defiant doesn't activate when partner's Syrup Bomb lowers Speed at end of turn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SYRUP_BOMB, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, playerRight);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Defiant activates when opposing Octolock lowers stats at end of turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_OCTOLOCK) == EFFECT_OCTOLOCK);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_OCTOLOCK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, opponentRight);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 4);
    }
}

DOUBLE_BATTLE_TEST("Defiant doesn't activate when partner's Octolock lowers stats at end of turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_OCTOLOCK) == EFFECT_OCTOLOCK);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_OCTOLOCK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Defiant activates before White Herb")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_GROWL; }

    GIVEN {
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);

        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");

        if (move == MOVE_LEER) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Mankey returned its stats to normal using its White Herb!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Mankey returned its stats to normal using its White Herb!");
            }
        }
    } THEN {
        if (move == MOVE_LEER) {
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        } else {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        }
    }
}

SINGLE_BATTLE_TEST("Defiant activates for each stat that is lowered")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_TICKLE, attack: -1, defense: -1);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TICKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TICKLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Defense fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose sharply!");

    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
    }
}

SINGLE_BATTLE_TEST("Defiant doesn't activate if the Pokémon lowers it's own stats")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SUPERPOWER; }
    PARAMETRIZE { move = MOVE_CLOSE_COMBAT; }
    PARAMETRIZE { move = MOVE_MAKE_IT_RAIN; }
    PARAMETRIZE { move = MOVE_SPIN_OUT; }

    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SUPERPOWER, self: TRUE, attack: -1, defense: -1);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_CLOSE_COMBAT, self: TRUE, defense: -1, spDef: -1);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_MAKE_IT_RAIN, self: TRUE, spAtk: -1);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SPIN_OUT, self: TRUE, speed: -2);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);

        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Mankey's Attack rose sharply!");
        }
    } THEN {
        if (move == MOVE_SUPERPOWER)
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        else
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Defiant doesn't activate when Room Service lowers Speed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(gItemsInfo[ITEM_ROOM_SERVICE].holdEffect == HOLD_EFFECT_ROOM_SERVICE);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); Item(ITEM_ROOM_SERVICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK_ROOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Defiant doesn't display ability popup when already at Maximum Attack")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_TICKLE, attack: -1, defense: -1);
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); MOVE(opponent, MOVE_TICKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        // Maxed Attack
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TICKLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack fell!");
        ABILITY_POPUP(player, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Attack rose!");
        // Maxed Attack
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mankey's Defense fell!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Mankey's Attack rose sharply!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Defiant doesn't activate when an opposing stat drop fails at minimum stage")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SPIN_OUT, self: TRUE, speed: -2);
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        PLAYER(SPECIES_BISHARP) { Ability(ABILITY_DEFIANT); Level(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIN_OUT); }
        TURN { MOVE(player, MOVE_SPIN_OUT); }
        TURN { MOVE(player, MOVE_SPIN_OUT); }
        TURN { MOVE(opponent, MOVE_SCARY_FACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIN_OUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIN_OUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIN_OUT, player);
        MESSAGE("The opposing Wobbuffet used Scary Face!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], MIN_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
