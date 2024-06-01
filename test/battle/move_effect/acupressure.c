#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Acupressure increases one of two stats by 2 stages at random");
TO_DO_BATTLE_TEST("Acupressure doesn't try to increase a stat that has been maximized");
TO_DO_BATTLE_TEST("Acupressure fails on the user if all of its stats are maximized");
TO_DO_BATTLE_TEST("Acupressure fails on the ally if all of its stats are maximized");
TO_DO_BATTLE_TEST("Acupressure works on the user if it's behind a Substitute (Gen5+)");
TO_DO_BATTLE_TEST("Acupressure fails on its ally if it's behind a Substitute");

DOUBLE_BATTLE_TEST("Acupressure works on the ally if the user targeted itself but switched positions via Ally Switch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target:playerRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NOT MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Ally Switch")
{
    KNOWN_FAILING; // Tested in Gen 5, Acupressure fails here
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KADABRA);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ACUPRESSURE, target:playerLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Ally Switch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft);
        MESSAGE("Wobbuffet and Wynaut switched places!");

        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    }
}

TO_DO_BATTLE_TEST("Acupressure works on the user if its side is protected by Crafty Shield");
TO_DO_BATTLE_TEST("Acupressure fails on the ally if its side is protected by Crafty Shield");

// Triple Battles required to test
//TO_DO_BATTLE_TEST("Acupressure works on the ally if the user targeted itself but switched positions via Triple Battle shift before execution");
//TO_DO_BATTLE_TEST("Acupressure fails on the user if it targeted its ally but switched positions via Triple Battle shift before execution");
