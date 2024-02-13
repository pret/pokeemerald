#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Snow Cloak prevents damage from hail")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLACEON) { Ability(ABILITY_SNOW_CLOAK); }
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("Snow Cloak increases evasion during hail")
{
    PASSES_RANDOMLY(4, 5, RNG_ACCURACY);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_POUND].accuracy == 100);
        PLAYER(SPECIES_GLACEON) { Ability(ABILITY_SNOW_CLOAK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
        TURN { MOVE(opponent, MOVE_POUND); }
    } SCENE {
        HP_BAR(player);
    }
}
