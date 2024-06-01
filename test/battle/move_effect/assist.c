#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_ASSIST].effect == EFFECT_ASSIST);
}

TO_DO_BATTLE_TEST("Assist randomly calls a move from any party member");
TO_DO_BATTLE_TEST("Assist counts all instances of the same move as separate");
TO_DO_BATTLE_TEST("Assist can call moves with no PP left");
TO_DO_BATTLE_TEST("Assist can call moves from a fainted party member");
TO_DO_BATTLE_TEST("Assist can call moves that are blocked to its partners"); // Eg. double battle parter blocked by Disable
TO_DO_BATTLE_TEST("Assist can only call the original moves of a Transformed partner (Gen4 only)");
TO_DO_BATTLE_TEST("Assist can only call the current moves of a Transformed partner (Gen5+)");
TO_DO_BATTLE_TEST("Assist cannot call a Mimicked move (Gen4 only)");
TO_DO_BATTLE_TEST("Assist can call a Mimicked move but not the original Mimic (Gen5+)");
TO_DO_BATTLE_TEST("Assist can call moves in unhatched Eggs (Gen5 only)");
TO_DO_BATTLE_TEST("Assist can be used by wild Pokémon in Wild Double Battles, even if the partner faints");

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
