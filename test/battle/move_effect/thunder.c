#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_THUNDER].effect == EFFECT_THUNDER);
    ASSUME(gBattleMoves[MOVE_THUNDER].accuracy == 70);
}

SINGLE_BATTLE_TEST("Thunder's accuracy is lowered to 50% in Sunlight")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, opponent);
    }
}

SINGLE_BATTLE_TEST("Thunder bypasses accuracy checks in Rain")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_THUNDER); }
    } SCENE {
        NONE_OF { MESSAGE("Wobbuffet's attack missed!"); }
    }
}
