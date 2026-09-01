#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Compound Eyes raises accuracy")
{
    PASSES_RANDOMLY(91, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_THUNDER) == 70);
        PLAYER(SPECIES_BUTTERFREE) { Ability(ABILITY_COMPOUND_EYES); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Compound Eyes does not affect OHKO moves")
{
    PASSES_RANDOMLY(30, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FISSURE) == 30);
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_BUTTERFREE) { Ability(ABILITY_COMPOUND_EYES); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 0);
    }
}
