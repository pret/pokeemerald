#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
}

SINGLE_BATTLE_TEST("Desolate Land blocks damaging Water-type moves")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT HP_BAR(player);
        MESSAGE("The opposing Wobbuffet used Water Gun!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Desolate Land blocks damaging Water-type moves and prints the message only once with moves hitting multiple targets")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SURF) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SURF); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Surf!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, opponentLeft);
        MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        NOT MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
    } THEN {
        EXPECT_EQ(playerLeft->hp, playerLeft->maxHP);
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

SINGLE_BATTLE_TEST("Desolate Land does not block a move if Pokémon is asleep and uses a Water-type move") // Sleep/confusion/paralysis all happen before the check for primal weather
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        NOT MESSAGE("The Water-type attack evaporated in the extremely harsh sunlight!");
        MESSAGE("The opposing Wobbuffet is fast asleep.");
    }
}

SINGLE_BATTLE_TEST("Desolate Land will not create a softlock when move in semi invulnerable position is blocked")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
        TURN { SWITCH(opponent, 1); SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ABILITY_POPUP(opponent, ABILITY_DESOLATE_LAND);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Desolate Land is removed immediately if user faints")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { HP(1); Item(ITEM_RED_ORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POUND); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        NOT MESSAGE("The sunlight is strong.");
        MESSAGE("The extremely harsh sunlight faded!");
    }
}

SINGLE_BATTLE_TEST("Desolate Land blocks weather-setting moves")
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
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Desolate Land prevents other weather abilities")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_DROUGHT;      species = SPECIES_NINETALES; }
    PARAMETRIZE { ability = ABILITY_DRIZZLE;      species = SPECIES_POLITOED; }
    PARAMETRIZE { ability = ABILITY_SAND_STREAM;  species = SPECIES_HIPPOWDON; }
    PARAMETRIZE { ability = ABILITY_SNOW_WARNING; species = SPECIES_ABOMASNOW; }

    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Desolate Land can be replaced by Delta Stream")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
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

SINGLE_BATTLE_TEST("Desolate Land can be replaced by Primordial Sea")
{
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PRIMORDIAL_SEA);
        MESSAGE("A heavy rain began to fall!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_RAIN_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Desolate Land fails if overworld weather is present (Gen9)")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DESOLATE_LAND);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(gBattleWeather & B_WEATHER_SUN);
        ResetStartingStatuses();
    }
}
