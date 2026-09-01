#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Forecast transforms Castform in weather from an opponent's move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        switch (move)
        {
        case MOVE_SUNNY_DAY:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SUNNY);
            break;
        case MOVE_RAIN_DANCE:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_RAINY);
            break;
        case MOVE_HAIL:
        case MOVE_SNOWSCAPE:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SNOWY);
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform in weather from its own move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        switch (move)
        {
        case MOVE_SUNNY_DAY:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SUNNY);
            break;
        case MOVE_RAIN_DANCE:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_RAINY);
            break;
        case MOVE_HAIL:
        case MOVE_SNOWSCAPE:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SNOWY);
            break;
        default:
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Forecast transforms Castform in weather from a partner's move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, move); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerLeft);
        MESSAGE("Castform transformed!");
    } THEN {
        switch (move)
        {
        case MOVE_SUNNY_DAY:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_SUNNY);
            break;
        case MOVE_RAIN_DANCE:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_RAINY);
            break;
        case MOVE_HAIL:
        case MOVE_SNOWSCAPE:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_SNOWY);
            break;
        default:
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Forecast transforms all Castforms present in weather")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); Speed(10); }
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); Speed(5); }
        OPPONENT(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); Speed(7); }
        OPPONENT(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); Speed(1); }
    } WHEN {
        TURN { MOVE(playerRight, move); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerLeft);
        MESSAGE("Castform transformed!");
        ABILITY_POPUP(opponentLeft, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponentLeft);
        MESSAGE("The opposing Castform transformed!");
        ABILITY_POPUP(playerRight, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerRight);
        MESSAGE("Castform transformed!");
        ABILITY_POPUP(opponentRight, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponentRight);
        MESSAGE("The opposing Castform transformed!");
    } THEN {
        switch (move)
        {
        case MOVE_SUNNY_DAY:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_SUNNY);
            EXPECT_EQ(playerRight->species, SPECIES_CASTFORM_SUNNY);
            EXPECT_EQ(opponentLeft->species, SPECIES_CASTFORM_SUNNY);
            EXPECT_EQ(opponentRight->species, SPECIES_CASTFORM_SUNNY);
            break;
        case MOVE_RAIN_DANCE:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_RAINY);
            EXPECT_EQ(playerRight->species, SPECIES_CASTFORM_RAINY);
            EXPECT_EQ(opponentLeft->species, SPECIES_CASTFORM_RAINY);
            EXPECT_EQ(opponentRight->species, SPECIES_CASTFORM_RAINY);
            break;
        case MOVE_HAIL:
        case MOVE_SNOWSCAPE:
            EXPECT_EQ(playerLeft->species, SPECIES_CASTFORM_SNOWY);
            EXPECT_EQ(playerRight->species, SPECIES_CASTFORM_SNOWY);
            EXPECT_EQ(opponentLeft->species, SPECIES_CASTFORM_SNOWY);
            EXPECT_EQ(opponentRight->species, SPECIES_CASTFORM_SNOWY);
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform in weather from an ability")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_KYOGRE; ability = ABILITY_DRIZZLE; }
    PARAMETRIZE { species = SPECIES_GROUDON; ability = ABILITY_DROUGHT; }
    PARAMETRIZE { species = SPECIES_ABOMASNOW; ability = ABILITY_SNOW_WARNING; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        switch (ability)
        {
        case ABILITY_DROUGHT:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SUNNY);
            break;
        case ABILITY_DRIZZLE:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_RAINY);
            break;
        case ABILITY_SNOW_WARNING:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SNOWY);
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform in primal weather")
{
    enum Species species;
    enum Item item;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_KYOGRE; ability = ABILITY_PRIMORDIAL_SEA; item = ITEM_BLUE_ORB; }
    PARAMETRIZE { species = SPECIES_GROUDON; ability = ABILITY_DESOLATE_LAND; item = ITEM_RED_ORB; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(item); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        switch (ability)
        {
        case ABILITY_DESOLATE_LAND:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_SUNNY);
            break;
        case ABILITY_PRIMORDIAL_SEA:
            EXPECT_EQ(player->species, SPECIES_CASTFORM_RAINY);
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back to normal when weather expires")
{
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        // transforms
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        // back to normal
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_NORMAL);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back to normal when Sandstorm is active")
{
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        // transforms
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        // back to normal
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_NORMAL);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back to normal under Cloud Nine/Air Lock")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_PSYDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        // transforms
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        // back to normal
        ABILITY_POPUP(opponent, ability);
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_NORMAL);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        // turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        // turn 2
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_RAINY);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform when weather changes")
{
    GIVEN {
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        // transforms
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        // transforms again
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_SUNNY);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back to normal when its ability is suppressed")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CASTFORM_NORMAL) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        // back to normal
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CASTFORM_NORMAL);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back when it switches out")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CASTFORM) { Ability(ABILITY_FORECAST); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        SWITCH_OUT_MESSAGE("Castform");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_CASTFORM);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform back when it uses a move that forces it to switch out")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CASTFORM) { Ability(ABILITY_FORECAST); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FORECAST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Castform transformed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_CASTFORM);
    }
}

SINGLE_BATTLE_TEST("Forecast transforms Castform when Cloud Nine ability user leaves the field")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_PSYDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(SPECIES_CASTFORM) { Ability(ABILITY_FORECAST); }
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("2 sent out Wobbuffet!");
        ABILITY_POPUP(player, ABILITY_FORECAST);
        MESSAGE("Castform transformed!");
    }
}

DOUBLE_BATTLE_TEST("Forecast reverts Castform back after Teraform Zero clears weather")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_TERASTAL);
        PLAYER(SPECIES_CASTFORM) { Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_KYOGRE) { Ability(ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_DRIZZLE);
        ABILITY_POPUP(playerRight, ABILITY_FORECAST);
        ABILITY_POPUP(playerLeft, ABILITY_TERAFORM_ZERO);
        ABILITY_POPUP(playerRight, ABILITY_FORECAST);
    } THEN {
        EXPECT_EQ(playerRight->species, SPECIES_CASTFORM_NORMAL);
    }
}

DOUBLE_BATTLE_TEST("Forecast: All Forecast mons revert on the field if Primal Weather is removed due to fainting")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Speed(20); HP(1); Item(ITEM_BLUE_ORB); }
        PLAYER(SPECIES_CASTFORM) { Speed(10); Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_CASTFORM) { Speed(40); Ability(ABILITY_FORECAST); }
        OPPONENT(SPECIES_CASTFORM) { Speed(30); Ability(ABILITY_FORECAST); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_POUND, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerLeft);

        ABILITY_POPUP(opponentLeft, ABILITY_FORECAST);
        ABILITY_POPUP(opponentRight, ABILITY_FORECAST);
        ABILITY_POPUP(playerRight, ABILITY_FORECAST);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->species, SPECIES_CASTFORM_NORMAL);
        EXPECT_EQ(opponentRight->species, SPECIES_CASTFORM_NORMAL);
        EXPECT_EQ(playerRight->species, SPECIES_CASTFORM_NORMAL);
    }
}

