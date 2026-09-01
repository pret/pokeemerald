#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Ally Switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target: playerLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");
        MESSAGE("Wynaut used Acupressure!");
        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the ally if it targeted itself but switched positions via Ally Switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target: playerRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");
        MESSAGE("Wynaut used Acupressure!");
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure will not try to raise partners stat if it already increased its own")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the user if its side is protected by Crafty Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CRAFTY_SHIELD);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the ally if its side is protected by Crafty Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CRAFTY_SHIELD);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Acupressure works on the user if it's behind a Substitute (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Acupressure fails on its ally if it's behind a Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SUBSTITUTE);
            MOVE(opponentRight, MOVE_ACUPRESSURE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponentLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Acupressure will target self if both side allies fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_POUND, target: opponentRight);
            MOVE(opponentLeft, MOVE_POUND, target: playerRight);
            MOVE(playerLeft, MOVE_ACUPRESSURE, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    }
}

TO_DO_BATTLE_TEST("Acupressure fails on the user if all of its stats are maximized");
TO_DO_BATTLE_TEST("Acupressure fails on the ally if all of its stats are maximized");
TO_DO_BATTLE_TEST("Acupressure doesn't try to increase a stat that has been maximized");
TO_DO_BATTLE_TEST("Acupressure increases one of its stats by 2 stages at random");

// Triple Battles required to test
//TO_DO_BATTLE_TEST("Acupressure works on the ally if the user targeted itself but switched positions via Triple Battle shift before execution");
//TO_DO_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Triple Battle shift before execution");
