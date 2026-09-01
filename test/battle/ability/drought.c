#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Drought sets up sun for 5 turns (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DROUGHT);
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight faded.");
    }
}

SINGLE_BATTLE_TEST("Drought sets up sun for 8 turns with Heat Rock (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        ASSUME(gItemsInfo[ITEM_HEAT_ROCK].holdEffect == HOLD_EFFECT_HEAT_ROCK);
        PLAYER(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); Item(ITEM_HEAT_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DROUGHT);
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight faded.");
    }
}

SINGLE_BATTLE_TEST("Drought sets up permanent sun (Gen3-5)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_3);
        PLAYER(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DROUGHT);
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        NOT MESSAGE("The sunlight faded.");
    }
}
