#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Snow Warning sets up hail for 5 turns (Gen6-8)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail stopped.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up hail for 8 turns with Icy Rock (Gen6-8)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        ASSUME(gItemsInfo[ITEM_ICY_ROCK].holdEffect == HOLD_EFFECT_ICY_ROCK);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); Item(ITEM_ICY_ROCK); }
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
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail stopped.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up permanent hail (Gen4-5)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_5);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
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
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        MESSAGE("The hail is crashing down.");
        NOT MESSAGE("The hail stopped.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up snow for 5 turns (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_9);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_9);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("The snow stopped.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up snow for 8 turns with Icy Rock (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_9);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_9);
        ASSUME(gItemsInfo[ITEM_ICY_ROCK].holdEffect == HOLD_EFFECT_ICY_ROCK);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); Item(ITEM_ICY_ROCK); }
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
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("Snow continues to fall.");
        MESSAGE("The snow stopped.");
    }
}
