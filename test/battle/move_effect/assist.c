#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ASSIST) == EFFECT_ASSIST);
}

TO_DO_BATTLE_TEST("Assist randomly calls a move from any party member");
TO_DO_BATTLE_TEST("Assist counts all instances of the same move as separate");
TO_DO_BATTLE_TEST("Assist can call moves with no PP left");
TO_DO_BATTLE_TEST("Assist can call moves from a fainted party member");
TO_DO_BATTLE_TEST("Assist can call moves that are blocked to its partners"); // Eg. double battle parter blocked by Disable
TO_DO_BATTLE_TEST("Assist can only call the original moves of a Transformed partner (Gen4 only)");
TO_DO_BATTLE_TEST("Assist cannot call a Mimicked move (Gen4 only)");
TO_DO_BATTLE_TEST("Assist can call a Mimicked move but not the original Mimic (Gen5+)");
TO_DO_BATTLE_TEST("Assist can call moves in unhatched Eggs (Gen5 only)");
TO_DO_BATTLE_TEST("Assist can be used by wild Pokémon in Wild Double Battles, even if the partner faints");
TO_DO_BATTLE_TEST("Assist called move does not get boosted by Normalize");

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

SINGLE_BATTLE_TEST("Assisted move triggers correct weakness berry")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_CHILAN_BERRY; }
    PARAMETRIZE { item = ITEM_PASSHO_BERRY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ASSIST, MOVE_NONE, MOVE_NONE, MOVE_NONE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SURF, MOVE_NONE, MOVE_NONE, MOVE_NONE); }
        OPPONENT(SPECIES_ARON) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_ASSIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSIST, player);
        if (item == ITEM_PASSHO_BERRY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        } else {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
    }
}

DOUBLE_BATTLE_TEST("Assist can only call the current moves of a Transformed partner (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_ASSIST); }
        PLAYER(SPECIES_DITTO) { Speed(4); Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_TRANSFORM, target: opponentLeft);
            MOVE(playerLeft, MOVE_ASSIST);
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSIST, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
    }
}
