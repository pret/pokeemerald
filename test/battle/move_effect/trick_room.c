#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
}

SINGLE_BATTLE_TEST("Trick Room doesn't print its ending message twice when used again")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10);  }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        MESSAGE("Wobbuffet twisted the dimensions!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        MESSAGE("The twisted dimensions returned to normal!");
        NOT MESSAGE("The twisted dimensions returned to normal!");
    }
}

SINGLE_BATTLE_TEST("Trick Room reverses move order for 5 turns including the turn it is used")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Trick Room does not affect move priority")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_CELEBRATE) == 0);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

AI_MULTI_BATTLE_TEST("Trick Room does not fail if the chosen AI target has fainted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MEMENTO) == EFFECT_MEMENTO);
        PLAYER(SPECIES_WYNAUT) { Speed(4); Moves(MOVE_MEMENTO); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_TRICK_ROOM); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_MEMENTO); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_MEMENTO); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_MEMENTO, target:playerRight);
            EXPECT_MOVE(opponentRight, MOVE_MEMENTO);
            EXPECT_MOVE(opponentLeft, MOVE_MEMENTO);
            EXPECT_MOVE(playerRight, MOVE_TRICK_ROOM); // Sets controller to AI
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, playerRight);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Trick Room (Move Effect) test titles")
