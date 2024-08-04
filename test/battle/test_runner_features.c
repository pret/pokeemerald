#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    int i;
    for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
        ASSUME(gSpeciesInfo[SPECIES_KADABRA].abilities[i] != ABILITY_QUARK_DRIVE);
        ASSUME(gSpeciesInfo[SPECIES_ALAKAZAM].abilities[i] != ABILITY_ELECTRIC_SURGE);
    }
}

SINGLE_BATTLE_TEST("Forced abilities activate on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_ALAKAZAM);
        PLAYER(SPECIES_KADABRA) { Ability(ABILITY_QUARK_DRIVE); SpAttack(400);}
        OPPONENT(SPECIES_ARON);
        OPPONENT(SPECIES_ALAKAZAM) { Ability(ABILITY_ELECTRIC_SURGE); };
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1);}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Kadabra's Quark Drive!");
        MESSAGE("Kadabra's Sp. Atk was heightened!");
    }
}
