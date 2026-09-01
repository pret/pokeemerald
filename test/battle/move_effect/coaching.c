#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_COACHING, attack: +1, defense: +1);
}

DOUBLE_BATTLE_TEST("Coaching raises Attack and Defense of ally by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut's Defense rose!");
    }
}

DOUBLE_BATTLE_TEST("Coaching bypasses Protect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_PROTECT); MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut's Defense rose!");
    }
}

DOUBLE_BATTLE_TEST("Coaching bypasses Crafty Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_CRAFTY_SHIELD); MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut's Defense rose!");
    }
}

DOUBLE_BATTLE_TEST("Coaching fails if all allies are is semi-invulnerable")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_HAWLUCHA);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FLY, target: opponentLeft); MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        MESSAGE("Hawlucha used Fly!");
        MESSAGE("Wobbuffet used Coaching!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
            MESSAGE("Hawlucha's Attack rose!");
            MESSAGE("Hawlucha's Defense rose!");
        }
        MESSAGE("Hawlucha avoided the attack!");
    }
}

SINGLE_BATTLE_TEST("Coaching fails in single battles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COACHING); }
    } SCENE {
        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, player);
            MESSAGE("Wynaut's Attack rose!");
            MESSAGE("Wynaut's Defense rose!");
        }
    }
}

DOUBLE_BATTLE_TEST("Coaching fails if there's no ally")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("Wynaut fainted!");
        MESSAGE("Wobbuffet used Coaching!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
            MESSAGE("Wynaut's Attack rose!");
            MESSAGE("Wynaut's Defense rose!");
        }
        MESSAGE("But it failed!");
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Coaching")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_HEADBUTT; }
    PARAMETRIZE { move = MOVE_DAZZLING_GLEAM; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_COACHING, MOVE_POUND); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move); }
    } WHEN {
        if (move == MOVE_HEADBUTT)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_COACHING); }
        else
            TURN {  NOT_EXPECT_MOVE(opponentLeft, MOVE_COACHING); }
    }
}

DOUBLE_BATTLE_TEST("Coaching ignores Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SUBSTITUTE); MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut's Defense rose!");
    }
}
