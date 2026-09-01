#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HYPNOSIS) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_HYPNOSIS) == MOVE_EFFECT_SLEEP);
}

DOUBLE_BATTLE_TEST("Sweet Veil prevents Sleep on partner - right target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BOUNSWEET) { Ability(ABILITY_SWEET_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPNOSIS, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_SWEET_VEIL);
        NOT STATUS_ICON(opponentRight, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sweet Veil prevents Sleep on partner - left target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BOUNSWEET) { Ability(ABILITY_SWEET_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPNOSIS, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_SWEET_VEIL);
        NOT STATUS_ICON(opponentLeft, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Sweet Veil prevents Yawn activation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BOUNSWEET) { Ability(ABILITY_SWEET_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); }
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, playerLeft);

        // Turn 2
        ABILITY_POPUP(opponentRight, ABILITY_SWEET_VEIL);
        NOT STATUS_ICON(opponentLeft, sleep: TRUE);
    }
}
