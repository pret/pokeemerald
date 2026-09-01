#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
    ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
}

SINGLE_BATTLE_TEST("Ice Body prevents damage from hail")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("Ice Body recovers 1/16th of Max HP in hail.")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_BODY);
        HP_BAR(player, damage: -(100 / 16));
        MESSAGE("Glalie's Ice Body healed it a little bit!");
    }
}

SINGLE_BATTLE_TEST("Ice Body doesn't recover HP if Cloud Nine/Air Lock is on the field")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_GLALIE) { Ability(ABILITY_ICE_BODY); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ICE_BODY);
    }
}
