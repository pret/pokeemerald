#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Psychic Surge creates Psychic Terrain when entering the battle")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_LELE) { Ability(ABILITY_PSYCHIC_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_PSYCHIC_SURGE);
        MESSAGE("The battlefield got weird!");
    }
}
