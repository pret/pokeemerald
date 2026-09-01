#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
}

SINGLE_BATTLE_TEST("Rain Dish recovers 1/16th of Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RAIN_DISH);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SIMPLE_HEAL, player);
        HP_BAR(player, damage:  -(100 / 16));
    }
}

SINGLE_BATTLE_TEST("Rain Dish doesn't recover HP if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_RAIN_DISH);
    }
}
