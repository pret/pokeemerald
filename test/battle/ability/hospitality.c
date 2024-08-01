#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Hospitality user restores 25% of ally's health")
{
    s16 health;

    PARAMETRIZE { health = 75; }
    PARAMETRIZE { health = 100; }

    GIVEN {
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        PLAYER(SPECIES_WOBBUFFET) { HP(health); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        if (health == 75) {
            ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
            MESSAGE("Wobbuffet drank down all the matcha that Poltchageist made!");
            HP_BAR(playerRight, damage: -25);
        } else {
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
                MESSAGE("Wobbuffet drank down all the matcha that Poltchageist made!");
                HP_BAR(playerRight, damage: -25);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Hospitality user restores 25% of ally's health on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET) { HP(75); MaxHP(100); }
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Poltchageist");
        ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
        MESSAGE("Wobbuffet drank down all the matcha that Poltchageist made!");
        HP_BAR(playerRight, damage: -25);
    }
}

DOUBLE_BATTLE_TEST("Hospitality ignores Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SUBSTITUTE); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerRight);
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Poltchageist");
        ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
        MESSAGE("Wobbuffet drank down all the matcha that Poltchageist made!");
    }
}

DOUBLE_BATTLE_TEST("Hospitality does not trigger if there is no ally on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1);  }
        PLAYER(SPECIES_WOBBUFFET) { HP(1);  }
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BLIZZARD); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLIZZARD, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet fainted!");
        HP_BAR(playerRight);
        MESSAGE("Wobbuffet fainted!");
        SEND_IN_MESSAGE("Poltchageist");
        NOT ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
    }
}
