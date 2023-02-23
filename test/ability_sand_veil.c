#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Sand Veil prevents damage from sandstorm")
{
    GIVEN {
        PLAYER(SPECIES_SANDSHREW) { Ability(ABILITY_SAND_VEIL); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN {}
    } SCENE {
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("Sand Veil reduces accuracy during sandstorm")
{
    PASSES_RANDOMLY(4,5);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_POUND].accuracy == 100);
        PLAYER(SPECIES_SANDSHREW) { Ability(ABILITY_SAND_VEIL); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN { MOVE(opponent, MOVE_POUND); }
    } SCENE {
        HP_BAR(player);
    }
}
