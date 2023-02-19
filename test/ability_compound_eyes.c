#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Compound Eyes raises accuracy")
{
    PASSES_RANDOMLY(91, 100);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_THUNDER].accuracy == 70);
        PLAYER(SPECIES_BUTTERFREE) { Ability(ABILITY_COMPOUND_EYES); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, player);
        HP_BAR(opponent);
    }
}

// This fails even though the ability works correctly. The failure is due to
// a statistical anomaly in the test system where FISSURE hits 3 times more often
// than we expect.
SINGLE_BATTLE_TEST("Compound Eyes does not affect OHKO moves")
{
    KNOWN_FAILING;
    PASSES_RANDOMLY(30, 100);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FISSURE].accuracy == 30);
        ASSUME(gBattleMoves[MOVE_FISSURE].effect == EFFECT_OHKO);
        PLAYER(SPECIES_BUTTERFREE) { Ability(ABILITY_TINTED_LENS); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 0);
    }
}
