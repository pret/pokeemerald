#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TEETER_DANCE].effect == EFFECT_CONFUSE);
}

SINGLE_BATTLE_TEST("Teeter Dance confuses target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("Foe Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Teeter Dance confusion is blocked by Own Tempo")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEETER_DANCE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("Foe Wobbuffet became confused!");
        }
    }
}

DOUBLE_BATTLE_TEST("Teeter Dance can confuse foes and allies")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("Foe Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerRight);
        MESSAGE("Wynaut became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("Foe Wynaut became confused!");
    }
}
