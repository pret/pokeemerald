#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_HURRICANE].effect == EFFECT_THUNDER);
    ASSUME(gMovesInfo[MOVE_HURRICANE].accuracy == 70);
}

SINGLE_BATTLE_TEST("Hurricane's accuracy is lowered to 50% in Sunlight")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_HURRICANE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HURRICANE, opponent);
    }
}

SINGLE_BATTLE_TEST("Hurricane bypasses accuracy checks in Rain")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_HURRICANE); }
    } SCENE {
        NONE_OF { MESSAGE("Wobbuffet's attack missed!"); }
    }
}
TO_DO_BATTLE_TEST("Hurricane Veil can hit airborne targets") // Fly, Bounce, Sky Drop
