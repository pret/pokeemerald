#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Competitive sharply raises player's Sp. Atk after Intimidate")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_FRIEND_GUARD; abilityRight = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { abilityLeft = ABILITY_FRIEND_GUARD; abilityRight = ABILITY_COMPETITIVE; }
    PARAMETRIZE { abilityLeft = ABILITY_COMPETITIVE; abilityRight = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { abilityLeft = ABILITY_COMPETITIVE; abilityRight = ABILITY_COMPETITIVE; }

    GIVEN {
        PLAYER(SPECIES_IGGLYBUFF) { Ability(abilityLeft); }
        PLAYER(SPECIES_JIGGLYPUFF) { Ability(abilityRight); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target:opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target:opponentRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Igglybuff's Attack fell!");
        if (abilityLeft == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Igglybuff's Sp. Atk rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Jigglypuff's Attack fell!");
        if (abilityRight == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(playerRight, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Jigglypuff's Sp. Atk rose sharply!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Igglybuff's Attack fell!");
        if (abilityLeft == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Igglybuff's Sp. Atk rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Jigglypuff's Attack fell!");
        if (abilityRight == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(playerRight, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Jigglypuff's Sp. Atk rose sharply!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + (abilityLeft == ABILITY_COMPETITIVE ? 4 : 0));
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + (abilityRight == ABILITY_COMPETITIVE ? 4 : 0));
    }
}

// Same as above, but for opponent.
DOUBLE_BATTLE_TEST("Competitive sharply raises opponent's Sp. Atk after Intimidate")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_FRIEND_GUARD; abilityRight = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { abilityLeft = ABILITY_FRIEND_GUARD; abilityRight = ABILITY_COMPETITIVE; }
    PARAMETRIZE { abilityLeft = ABILITY_COMPETITIVE; abilityRight = ABILITY_FRIEND_GUARD; }
    PARAMETRIZE { abilityLeft = ABILITY_COMPETITIVE; abilityRight = ABILITY_COMPETITIVE; }

    GIVEN {
        OPPONENT(SPECIES_IGGLYBUFF) { Ability(abilityLeft); }
        OPPONENT(SPECIES_JIGGLYPUFF) { Ability(abilityRight); }
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target:playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target:playerRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Igglybuff's Attack fell!");
        if (abilityLeft == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(opponentLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Igglybuff's Sp. Atk rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Jigglypuff's Attack fell!");
        if (abilityRight == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(opponentRight, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Jigglypuff's Sp. Atk rose sharply!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Igglybuff's Attack fell!");
        if (abilityLeft == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(opponentLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Igglybuff's Sp. Atk rose sharply!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Jigglypuff's Attack fell!");
        if (abilityRight == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(opponentRight, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Jigglypuff's Sp. Atk rose sharply!");
        }
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + (abilityLeft == ABILITY_COMPETITIVE ? 4 : 0));
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + (abilityRight == ABILITY_COMPETITIVE ? 4 : 0));
    }
}

SINGLE_BATTLE_TEST("Competitive activates after Sticky Web lowers Speed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Igglybuff");
        MESSAGE("Igglybuff was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Speed fell!");
        // Competitive activates
        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");
    }
}

SINGLE_BATTLE_TEST("Competitive doesn't activate after Sticky Web lowers Speed if Court Changed (gen8)")
{
    GIVEN {
        WITH_CONFIG(B_DEFIANT_STICKY_WEB, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); MOVE(opponent, MOVE_COURT_CHANGE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COURT_CHANGE, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Igglybuff");
        MESSAGE("Igglybuff was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Speed fell!");
        // Competitive doesn't activate
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Igglybuff's Sp. Atk rose sharply!");
        }
    }
}

SINGLE_BATTLE_TEST("Competitive correctly activates after Sticky Web lowers Speed if Court Changed (Gen8)")
{
    GIVEN {
        WITH_CONFIG(B_DEFIANT_STICKY_WEB, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); MOVE(opponent, MOVE_COURT_CHANGE); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COURT_CHANGE, opponent);
        // Switch-in - Sticky Web activates
        SEND_IN_MESSAGE("Igglybuff");
        MESSAGE("Igglybuff was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Speed fell!");
        // Competitive doesn't activate
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Igglybuff's Sp. Atk rose sharply!");
        }
        // Competitive triggers correctly after Sticky Web
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Attack fell!");
        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");
    }
}

DOUBLE_BATTLE_TEST("Competitive is activated by Cotton Down for non-ally pokemon")
{
    GIVEN {
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
        OPPONENT(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_COTTON_DOWN);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Igglybuff's Speed fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Igglybuff's Speed fell!");
        ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Igglybuff's Speed fell!");
        ABILITY_POPUP(playerRight, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");

    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Competitive activates when opposing Syrup Bomb lowers Speed at end of turn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Competitive doesn't activate when partner's Syrup Bomb lowers Speed at end of turn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
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
            ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Competitive activates when opposing Octolock lowers stats at end of turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_OCTOLOCK) == EFFECT_OCTOLOCK);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_OCTOLOCK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, opponentRight);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 4);
    }
}

DOUBLE_BATTLE_TEST("Competitive doesn't activate when partner's Octolock lowers stats at end of turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_OCTOLOCK) == EFFECT_OCTOLOCK);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_OCTOLOCK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Competitive activates before White Herb")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_CONFIDE; }

    GIVEN {
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);

        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");

        if (move == MOVE_LEER) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Igglybuff returned its stats to normal using its White Herb!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Igglybuff returned its stats to normal using its White Herb!");
            }
        }
    } THEN {
        if (move == MOVE_LEER) {
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        } else {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        }
    }
}

SINGLE_BATTLE_TEST("Competitive activates for each stat that is lowered")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_TICKLE, attack: -1, defense: -1);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TICKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TICKLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);

        MESSAGE("Igglybuff's Attack fell!");
        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");

        MESSAGE("Igglybuff's Defense fell!");
        ABILITY_POPUP(player, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Igglybuff's Sp. Atk rose sharply!");

    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 4);
    }
}

SINGLE_BATTLE_TEST("Competitive doesn't activate if the pokemon lowers it's own stats")
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
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);

        NONE_OF {
            ABILITY_POPUP(player, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Igglybuff's Sp. Atk rose sharply!");
        }
    } THEN {
        if (move == MOVE_SUPERPOWER)
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        else
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Competitive doesn't activate when Room Service lowers Speed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(gItemsInfo[ITEM_ROOM_SERVICE].holdEffect == HOLD_EFFECT_ROOM_SERVICE);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); Item(ITEM_ROOM_SERVICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK_ROOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Competitive doesn't activate when an opposing stat drop fails at minimum stage")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SPIN_OUT, self: TRUE, speed: -2);
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        PLAYER(SPECIES_IGGLYBUFF) { Ability(ABILITY_COMPETITIVE); Level(1); }
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
            ABILITY_POPUP(player, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], MIN_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}
