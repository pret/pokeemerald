#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_ASSIST].effect == EFFECT_ASSIST);
}

SINGLE_BATTLE_TEST("Assist fails if there are no valid moves to choose from")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ASSIST, MOVE_CELEBRATE, MOVE_METRONOME, MOVE_ME_FIRST); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ASSIST, MOVE_ENDURE, MOVE_DRAGON_TAIL, MOVE_SPOTLIGHT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ASSIST); }
    } SCENE {
        MESSAGE("Wobbuffet used Assist!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSIST, player);
        MESSAGE("But it failed!");
    }
}
