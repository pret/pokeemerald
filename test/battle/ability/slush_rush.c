#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Slush Rush doubles speed from hail")
{
    GIVEN {
        PLAYER(SPECIES_CETITAN) { Ability(ABILITY_SLUSH_RUSH); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_HAIL); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Slush Rush doubles speed from snow")
{
    GIVEN {
        PLAYER(SPECIES_CETITAN) { Ability(ABILITY_SLUSH_RUSH); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SNOWSCAPE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Slush Rush doesn't double speed if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_CETITAN) { Ability(ABILITY_SLUSH_RUSH); Speed(100); }
        OPPONENT(SPECIES_GOLDUCK) { Speed(199); Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SNOWSCAPE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Slush Rush doesn't prevent non-Ice types from taking damage in Hail")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ICE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ICE);
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CETITAN) { Ability(ABILITY_SLUSH_RUSH); }
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, player);
        HP_BAR(player);
    }
}
