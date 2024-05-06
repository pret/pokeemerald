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
        TURN { MOVE(playerLeft, MOVE_QUASH, target: opponentRight);
               MOVE(opponentLeft, MOVE_TAILWIND);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}
