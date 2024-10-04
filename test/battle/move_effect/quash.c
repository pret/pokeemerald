#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_QUASH].effect == EFFECT_QUASH);
}

DOUBLE_BATTLE_TEST("Quash-affected target will move last in the priority bracket")
{
    GIVEN {
        PLAYER(SPECIES_VOLBEAT) { Speed(10); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_TORCHIC) { Speed(20); }
        OPPONENT(SPECIES_TREECKO) { Speed(40); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUASH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Quash is not affected by dynamic speed")
{
    GIVEN {
        ASSUME(B_RECALC_TURN_AFTER_ACTIONS >= GEN_8);
        ASSUME(gMovesInfo[MOVE_TAILWIND].effect == EFFECT_TAILWIND);
        PLAYER(SPECIES_VOLBEAT) { Speed(10); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_TORCHIC) { Speed(50); }
        OPPONENT(SPECIES_TREECKO) { Speed(40); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUASH, target: opponentLeft);
               MOVE(opponentRight, MOVE_TAILWIND);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Quash calculates correct turn order if only one pokemon is left on the opposing side")
{
    GIVEN {
        PLAYER(SPECIES_GRENINJA) { Speed(120); }
        PLAYER(SPECIES_REGIROCK) { Speed(100); }
        OPPONENT(SPECIES_PIDGEOT) { Speed(10); }
        OPPONENT(SPECIES_DRAGONITE) { Speed(60); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_QUASH, target: playerRight);
            MOVE(playerRight, MOVE_STONE_EDGE, target: opponentLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
        TURN {
            MOVE(playerLeft, MOVE_QUASH, target: playerRight);
            MOVE(playerRight, MOVE_STONE_EDGE, target: opponentRight);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_EDGE, playerRight);
        HP_BAR(opponentLeft);
        MESSAGE("Foe Pidgeot fainted!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_EDGE, playerRight);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Quash-affected targets move from fastest to slowest (Gen 8+) or from first affected battler to last (Gen 7-)")
{
    u32 speedLeft, speedRight;

    PARAMETRIZE { speedLeft = 60; speedRight = 50; }
    PARAMETRIZE { speedLeft = 50; speedRight = 60; }
    GIVEN {
        PLAYER(SPECIES_VOLBEAT) { Speed(10); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(70); }
        OPPONENT(SPECIES_TORCHIC) { Speed(speedLeft); }
        OPPONENT(SPECIES_TREECKO) { Speed(speedRight); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUASH, target: opponentRight);
               MOVE(playerRight, MOVE_QUASH, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerRight);
        if (B_QUASH_TURN_ORDER < GEN_8) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        }
        else if (speedLeft > speedRight) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        }
        else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Quash-affected mon that acted early via After You is not affected by dynamic speed")
{
    GIVEN {
        ASSUME(B_RECALC_TURN_AFTER_ACTIONS >= GEN_8);
        ASSUME(gMovesInfo[MOVE_TAILWIND].effect == EFFECT_TAILWIND);
        ASSUME(gMovesInfo[MOVE_AFTER_YOU].effect == EFFECT_AFTER_YOU);
        PLAYER(SPECIES_VOLBEAT) { Speed(20); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_TORCHIC) { Speed(10); }
        OPPONENT(SPECIES_TREECKO) { Speed(40); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUASH, target: opponentLeft);
               MOVE(opponentRight, MOVE_AFTER_YOU, target: opponentLeft);
               MOVE(opponentLeft, MOVE_TAILWIND);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight); // this is the relevant part, testing if quash affected battler becomes last to move causing playerRight to not move
    }
}
