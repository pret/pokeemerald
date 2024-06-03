#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_PURSUIT].effect == EFFECT_PURSUIT);
}

SINGLE_BATTLE_TEST("Pursuited mon correctly switches out after it got hit and activated ability Tangling Hair")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_PURSUIT); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Dugtrio");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PURSUIT, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wynaut's Speed fell!");
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

TO_DO_BATTLE_TEST("Baton Pass doesn't cause Pursuit to increase its power or priority");
