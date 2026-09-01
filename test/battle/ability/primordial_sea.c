#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_EMBER) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
}

SINGLE_BATTLE_TEST("Primordial Sea blocks damaging Fire-type moves")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Ember!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("The Fire-type attack fizzled out in the heavy rain!");
        NOT HP_BAR(player);
        MESSAGE("The opposing Wobbuffet used Ember!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("The Fire-type attack fizzled out in the heavy rain!");
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Primordial Sea blocks damaging Fire-type moves and prints the message only once with moves hitting multiple targets")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ERUPTION) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveType(MOVE_ERUPTION) == TYPE_FIRE);
        ASSUME(GetMoveTarget(MOVE_ERUPTION) == TARGET_BOTH);
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ERUPTION); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Eruption!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ERUPTION, opponentLeft);
        MESSAGE("The Fire-type attack fizzled out in the heavy rain!");
        NOT MESSAGE("The Fire-type attack fizzled out in the heavy rain!");
    } THEN {
        EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
    }
}

SINGLE_BATTLE_TEST("Primordial Sea does not block a move if Pokémon is asleep and uses a Fire-type move") // Sleep/confusion/paralysis all happen before the check for primal weather
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        NOT MESSAGE("The Fire-type attack fizzled out in the heavy rain!");
        MESSAGE("The opposing Wobbuffet is fast asleep.");
    }
}

SINGLE_BATTLE_TEST("Primordial Sea blocks weather-setting moves")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }

    GIVEN {
        ASSUME(GetMoveEffect(move) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SUNNY_DAY) == BATTLE_WEATHER_SUN);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primordial Sea prevents other weather abilities")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_DROUGHT;      species = SPECIES_NINETALES; }
    PARAMETRIZE { ability = ABILITY_DRIZZLE;      species = SPECIES_POLITOED; }
    PARAMETRIZE { ability = ABILITY_SAND_STREAM;  species = SPECIES_HIPPOWDON; }
    PARAMETRIZE { ability = ABILITY_SNOW_WARNING; species = SPECIES_ABOMASNOW; }

    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primordial Sea can be replaced by Delta Stream")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DELTA_STREAM);
        MESSAGE("Mysterious strong winds are protecting Flying-type Pokémon!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_STRONG_WINDS);
    }
}

SINGLE_BATTLE_TEST("Primordial Sea can be replaced by Desolate Land")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DESOLATE_LAND);
        MESSAGE("The sunlight turned extremely harsh!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primordial Sea fails if overworld weather is present (Gen9)")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_PRIMORDIAL_SEA);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN);
        ResetStartingStatuses();
    }
}
