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
        TURN {}
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
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BLIZZARD); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLIZZARD, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Wobbuffet fainted!");
        SEND_IN_MESSAGE("Poltchageist");
        NOT ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
    }
}

DOUBLE_BATTLE_TEST("Hospitality is blocked by Heal Block")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET) { HP(75); MaxHP(100); }
        PLAYER(SPECIES_POLTCHAGEIST) { Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_HEAL_BLOCK, target: playerRight); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponentLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_HOSPITALITY);
            MESSAGE("Wobbuffet drank down all the matcha that Poltchageist made!");
            HP_BAR(playerRight, damage: -25);
        }
    }
}

DOUBLE_BATTLE_TEST("Hospitality user restores 25% of ally's max HP after taking hazard damage")
{
    u32 speedLeft, speedRight = 0;

    PARAMETRIZE { speedLeft = 200; speedRight = 150; }
    PARAMETRIZE { speedLeft = 150; speedRight = 200; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedLeft); };
        PLAYER(SPECIES_POLTCHAGEIST) { Speed(speedRight); Ability(ABILITY_HOSPITALITY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(110); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPIKES);
            MOVE(opponentRight, MOVE_HYPER_VOICE);
            SEND_OUT(playerLeft, 2);
            SEND_OUT(playerRight, 3);
        }
    } SCENE {
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        if (speedLeft == 200) {
            HP_BAR(playerLeft); // Spikes dmg
            HP_BAR(playerRight); // Spikes dmg
        } else {
            HP_BAR(playerRight); // Spikes dmg
            HP_BAR(playerLeft); // Spikes dmg
        }
        ABILITY_POPUP(playerRight, ABILITY_HOSPITALITY);
        HP_BAR(playerLeft); // Hospitality Heal
    }
}
