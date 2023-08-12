#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Pastel Veil prevents Poison Sting poison")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_POISON_STING].effect == EFFECT_POISON_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Poison Sting poison on partner")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_POISON_STING].effect == EFFECT_POISON_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POISON_STING, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, playerLeft);
        NOT STATUS_ICON(opponentRight, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil immediately cures Mold Breaker poison")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_PASTEL_VEIL);
        MESSAGE("Foe Ponyta's Pastel Veil cured its poison problem!");
        STATUS_ICON(opponent, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil does not cure Mold Breaker poison on partner")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, playerLeft, target: opponentRight);
        STATUS_ICON(opponentRight, badPoison: TRUE);
        NOT STATUS_ICON(opponentRight, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil prevents Toxic bad poison")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponent, ABILITY_PASTEL_VEIL);
        MESSAGE("Foe Ponyta is protected by a pastel veil!");
        NOT STATUS_ICON(opponent, badPoison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Toxic bad poison on partner")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponentLeft, ABILITY_PASTEL_VEIL);
        MESSAGE("Foe Wynaut is protected by a pastel veil!");
        NOT STATUS_ICON(opponentRight, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil prevents Toxic Spikes poison")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC_SPIKES].effect == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Ponyta!");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Toxic Spikes poison on partner")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TOXIC_SPIKES].effect == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        NOT STATUS_ICON(opponentRight, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil cures partner's poison on initial switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("2 sent out Wobbuffet and Ponyta!");
        ABILITY_POPUP(opponentRight, ABILITY_PASTEL_VEIL);
        MESSAGE("Foe Wobbuffet was cured of its poisoning!");
        STATUS_ICON(opponentLeft, none: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil cures partner's poison on switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALARIAN) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE("2 sent out Ponyta!");
        ABILITY_POPUP(opponentRight, ABILITY_PASTEL_VEIL);
        MESSAGE("Foe Wobbuffet was cured of its poisoning!");
        STATUS_ICON(opponentLeft, none: TRUE);
    }
}
