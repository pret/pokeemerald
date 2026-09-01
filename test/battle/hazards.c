#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hazards are applied based on order of set up")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GRIMER);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); SWITCH(player, 1); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); SWITCH(player, 2); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        MESSAGE("Wobbuffet was poisoned!");
        MESSAGE("Pointed stones dug into Wobbuffet!");
        MESSAGE("Wobbuffet was caught in a sticky web!");
        MESSAGE("Wobbuffet was hurt by the spikes!");
        MESSAGE("The toxic spikes disappeared from the ground around your side!");
        MESSAGE("Pointed stones dug into Wynaut!");
        MESSAGE("Wynaut was caught in a sticky web!");
        MESSAGE("Wynaut was hurt by the spikes!");
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_STEALTH_ROCK);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_STICKY_WEB);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
    }
}

SINGLE_BATTLE_TEST("Hazards are applied correctly after a battler faints")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK);
               MOVE(player, MOVE_FINAL_GAMBIT);
               SEND_OUT(player, 1);
               SEND_OUT(player, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        MESSAGE("Wynaut fainted!");
        MESSAGE("Pointed stones dug into Wobbuffet!");
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Pointed stones dug into Wynaut!");
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes can be removed after fainting to other hazards")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_GRIMER) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); SWITCH(player, 1); SEND_OUT(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        MESSAGE("Pointed stones dug into Grimer!");
        MESSAGE("Grimer fainted!");
        MESSAGE("The toxic spikes disappeared from the ground around your side!");
        NONE_OF {
            MESSAGE("Grimer was caught in a sticky web!");
            MESSAGE("Grimer was hurt by the spikes!");
        }
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_STEALTH_ROCK);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_STICKY_WEB);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
    }
}

SINGLE_BATTLE_TEST("Hazards can trigger Emergency Exit and other hazards don't activate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GOLISOPOD) { HP(105); MaxHP(200); Ability(ABILITY_EMERGENCY_EXIT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); SWITCH(player, 1); SEND_OUT(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        MESSAGE("Pointed stones dug into Golisopod!");
        ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
        NONE_OF {
            MESSAGE("Golisopod was poisoned!");
            MESSAGE("Golisopod was caught in a sticky web!");
            MESSAGE("Golisopod was hurt by the spikes!");
        }
        MESSAGE("Pointed stones dug into Wobbuffet!");
        MESSAGE("Wobbuffet was poisoned!");
        MESSAGE("Wobbuffet was caught in a sticky web!");
        MESSAGE("Wobbuffet was hurt by the spikes!");
        NOT MESSAGE("Pointed stones dug into Wobbuffet!"); // Because the previous switch in effects instruction is still kept
    }
}

DOUBLE_BATTLE_TEST("Hazards can trigger Emergency Exit and hazards still activate for other battlers")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); HP(1); }
        PLAYER(SPECIES_GOLISOPOD) { Speed(10); HP(105); MaxHP(200); Ability(ABILITY_EMERGENCY_EXIT); }
        PLAYER(SPECIES_WYNAUT) { Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET)  { Speed(10); }
        OPPONENT(SPECIES_WYNAUT)  { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STEALTH_ROCK); MOVE(opponentRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(opponentRight, MOVE_SPIKES); }
        TURN { MOVE(playerLeft, MOVE_FINAL_GAMBIT, target: opponentRight);
               MOVE(playerRight, MOVE_FINAL_GAMBIT, target: opponentRight);
               SEND_OUT(playerLeft, 2);
               SEND_OUT(playerRight, 3);
               SEND_OUT(playerLeft, 4); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponentRight);
        MESSAGE("Pointed stones dug into Golisopod!");
        ABILITY_POPUP(playerLeft, ABILITY_EMERGENCY_EXIT);
        NONE_OF {
            MESSAGE("Golisopod was poisoned!");
            MESSAGE("Golisopod was caught in a sticky web!");
            MESSAGE("Golisopod was hurt by the spikes!");
        }
        MESSAGE("Pointed stones dug into Wobbuffet!");
        MESSAGE("Wobbuffet was poisoned!");
        MESSAGE("Wobbuffet was caught in a sticky web!");
        MESSAGE("Wobbuffet was hurt by the spikes!");
        MESSAGE("Pointed stones dug into Wynaut!");
        MESSAGE("Wynaut was poisoned!");
        MESSAGE("Wynaut was caught in a sticky web!");
        MESSAGE("Wynaut was hurt by the spikes!");
    }
}
