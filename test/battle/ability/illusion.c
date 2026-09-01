#include "global.h"
#include "test/battle.h"

//  This test is eyes on only
SINGLE_BATTLE_TEST("Illusion can only imitate Normal Form terapagos")
{
    GIVEN {
        PLAYER(SPECIES_ZOROARK) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_TERAPAGOS) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        //  Zoroark is out, should be normal form Terapagos
        //  Switch to Terapagos which enters Terastal Form
        TURN { SWITCH(player, 1); }
        //  Switch back to Zoroark, should not be Terastal Terapagos
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_SCRATCH); }
        //  Switch back to Terapagos
        TURN { SWITCH(player, 1); }
        //  Terapagos Stellar, Zoroark gets Roared in, should not be Stellar Terapagos
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_ROAR); }
        //  Reveal the Zoroark
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    }
}

SINGLE_BATTLE_TEST("Illusion breaks if the target faints")
{
    GIVEN {
        PLAYER(SPECIES_ZOROARK) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
        MESSAGE("Zoroark's illusion wore off!");
    }
}

SINGLE_BATTLE_TEST("Illusion does not break if the attacker faints without taking damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
        PLAYER(SPECIES_ZOROARK) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
            MESSAGE("Zoroark's illusion wore off!");
        }
    }
}

SINGLE_BATTLE_TEST("Illusion cannot imitate if the user is on the last slot")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_ZOROARK);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_ZOROARK);
        EXPECT_EQ(gBattleStruct->illusion[0].state, ILLUSION_OFF); // Battler is Zoroark and not Illusioned
    }
}

ONE_VS_TWO_BATTLE_TEST("Illusion works for the second opponent trainer in a battle with two opponent trainers")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); }
        OPPONENT_B(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(gBattleStruct->illusion[B_POSITION_OPPONENT_RIGHT].state, ILLUSION_ON);
        EXPECT(&gParties[B_TRAINER_OPPONENT_B][1] == gBattleStruct->illusion[B_POSITION_OPPONENT_RIGHT].mon);
    }
}

MULTI_BATTLE_TEST("Illusion works when the user's partner and disguise are in the same party slot")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); }
        PLAYER(SPECIES_WYNAUT);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerRight, 2); }
        TURN { SWITCH(playerLeft, 1); }
    } THEN {
        EXPECT_EQ(gBattleStruct->illusion[B_POSITION_PLAYER_LEFT].state, ILLUSION_ON);
        EXPECT(&gParties[B_TRAINER_PLAYER][2] == gBattleStruct->illusion[B_POSITION_PLAYER_LEFT].mon);
    }
}

SINGLE_BATTLE_TEST("Illusion breaks in Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_ZOROARK);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
    }
}

SINGLE_BATTLE_TEST("Illusion breaks if affected by Gastro Acid")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_ZOROARK);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
    }
}

SINGLE_BATTLE_TEST("Illusion breaks if user loses Illusion due to Worry Seed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        PLAYER(SPECIES_ZOROARK);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WORRY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
    }
}

SINGLE_BATTLE_TEST("Illusion breaks when hit through a substitute")
{
    GIVEN {
        WITH_CONFIG(B_INFILTRATOR_SUBSTITUTE, GEN_6);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ABILITY_INFILTRATOR); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_ZOROARK) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_SHED_TAIL); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SWAP_FROM_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SWAP_TO_SUBSTITUTE, opponent);
        MESSAGE("The opposing Zoroark's illusion wore off!");
    }
}

SINGLE_BATTLE_TEST("Illusion does not break if indirect damage causes the user to faint")
{
    GIVEN {
        PLAYER(SPECIES_ZOROARK) { HP(1); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SEND_OUT(player, 1); }
    } SCENE {
        HP_BAR(player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ILLUSION_OFF, player);
            MESSAGE("Zoroark's illusion wore off!");
        }
    }
}
