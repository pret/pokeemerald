#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_INSTRUCT].effect == EFFECT_INSTRUCT);
}

DOUBLE_BATTLE_TEST("Instruct fails if target hasn't made a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if move is banned by Instruct")
{
    ASSUME(gMovesInfo[MOVE_BIDE].instructBanned == TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_BIDE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_BIDE); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move targets the target of the move picked on its last use")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct doesn't bypass sleep")
{
    ASSUME(gMovesInfo[MOVE_SPORE].effect == EFFECT_SLEEP);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); MOVE(opponentLeft, MOVE_SPORE, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        MESSAGE("Wobbuffet is fast asleep.");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if target doesn't know the last move it used")
{
    ASSUME(gMovesInfo[MOVE_DRAGON_DANCE].danceMove == TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ORICORIO) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DRAGON_DANCE); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move fails if it can only be used on the first turn but consumes PP")
{
    ASSUME(gMovesInfo[MOVE_FAKE_OUT].effect == EFFECT_FIRST_TURN_ONLY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FAKE_OUT, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->pp[3], gMovesInfo[MOVE_FAKE_OUT].pp - 2);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move doesn't fail if tormented")
{
    ASSUME(gMovesInfo[MOVE_TORMENT].effect == EFFECT_TORMENT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TORMENT, target: playerRight); MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called status moves don't fail if holding Assault Vest")
{
    ASSUME(gItemsInfo[ITEM_ASSAULT_VEST].holdEffect == HOLD_EFFECT_ASSAULT_VEST);
    ASSUME(gMovesInfo[MOVE_TRICK].effect == EFFECT_TRICK);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_TRICK); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ASSAULT_VEST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TRICK, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called status move fails if taunted")
{
    ASSUME(gMovesInfo[MOVE_TAUNT].effect == EFFECT_TAUNT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_GROWL); MOVE(opponentLeft, MOVE_TAUNT, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    } THEN {
        EXPECT_EQ(playerRight->pp[3], gMovesInfo[MOVE_GROWL].pp - 1);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called moves fail if disabled")
{
    ASSUME(gMovesInfo[MOVE_DISABLE].effect == EFFECT_DISABLE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); MOVE(opponentLeft, MOVE_DISABLE, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->pp[0], gMovesInfo[MOVE_TACKLE].pp - 1);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called moves keep their priority")
{
    ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority == 1);
    ASSUME(gMovesInfo[MOVE_PSYCHIC_TERRAIN].effect == EFFECT_PSYCHIC_TERRAIN);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_POUND, MOVE_SCRATCH, MOVE_QUICK_ATTACK); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft); MOVE(opponentLeft, MOVE_PSYCHIC_TERRAIN, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
    }
}
