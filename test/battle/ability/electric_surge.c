#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electric Surge creates Electric Terrain when entering the battle")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        MESSAGE("An electric current ran across the battlefield!");
    }
}
