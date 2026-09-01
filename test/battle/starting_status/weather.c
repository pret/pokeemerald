#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("SetStartingStatus starts a chosen weather at the beginning of battle and lasts infinitely long if it's defined as such")
{
    u16 weather;

    PARAMETRIZE { weather = STARTING_STATUS_WEATHER_SUN; }
    PARAMETRIZE { weather = STARTING_STATUS_WEATHER_RAIN; }
    PARAMETRIZE { weather = STARTING_STATUS_WEATHER_SANDSTORM; }
    PARAMETRIZE { weather = STARTING_STATUS_WEATHER_HAIL; }
    PARAMETRIZE { weather = STARTING_STATUS_WEATHER_SNOW_TEMPORARY; }

    SetStartingStatus(weather);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        switch (weather)
        {
        case STARTING_STATUS_WEATHER_SUN:
            MESSAGE("The sunlight turned harsh!");
            break;
        case STARTING_STATUS_WEATHER_RAIN:
            MESSAGE("It started to rain!");
            break;
        case STARTING_STATUS_WEATHER_SANDSTORM:
            MESSAGE("A sandstorm kicked up!");
            break;
        case STARTING_STATUS_WEATHER_HAIL:
            MESSAGE("It started to hail!");
            break;
        case STARTING_STATUS_WEATHER_SNOW_TEMPORARY:
            MESSAGE("It started to snow!");
            break;
        }
        if (weather != STARTING_STATUS_WEATHER_SNOW_TEMPORARY) {
            NONE_OF {
                MESSAGE("The sunlight faded.");
                MESSAGE("The rain stopped.");
                MESSAGE("The sandstorm subsided.");
                MESSAGE("The hail stopped.");
            }
        } else {
            MESSAGE("The snow stopped.");
        }
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Weather started after the one which started the battle lasts only 5 turns")
{
    bool32 viaMove;

    PARAMETRIZE { viaMove = TRUE; }
    PARAMETRIZE { viaMove = FALSE; }

    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        WITH_CONFIG(B_OVERWORLD_WEATHER_OVERRIDE, GEN_8);
        PLAYER(SPECIES_POLITOED) { Ability(viaMove == TRUE ? ABILITY_DAMP : ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN { MOVE(player, viaMove == TRUE ? MOVE_RAIN_DANCE : MOVE_CELEBRATE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        // Harsh Sunlight at battle's start
        MESSAGE("The sunlight turned harsh!");
        // Player uses Rain Dance
        if (viaMove) {
            MESSAGE("Politoed used Rain Dance!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
            MESSAGE("It started to rain!");
        } else {
            ABILITY_POPUP(player, ABILITY_DRIZZLE);
            MESSAGE("It started to rain!");
        }

        // 5 turns
        MESSAGE("Politoed used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Politoed used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Politoed used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("The rain stopped.");
    } THEN {
        ResetStartingStatuses();
    }
}

// In game: Overworld rain cures status AFTER end of turn 1 (Test result is accurate)
SINGLE_BATTLE_TEST("StartingStatus weather activates weather-reliant abilities")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_RAIN);

    GIVEN {
        PLAYER(SPECIES_SWANNA) { Ability(ABILITY_HYDRATION); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("It started to rain!");
        ABILITY_POPUP(player, ABILITY_HYDRATION);
        MESSAGE("Swanna's burn was cured!");
        STATUS_ICON(player, none: TRUE);
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Overworld weather cannot be overridden (Gen9)")
{
    bool32 viaMove;

    PARAMETRIZE { viaMove = TRUE; }
    PARAMETRIZE { viaMove = FALSE; }

    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        WITH_CONFIG(B_OVERWORLD_WEATHER_OVERRIDE, GEN_9);
        PLAYER(SPECIES_POLITOED) { Ability(viaMove == TRUE ? ABILITY_DAMP : ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, viaMove == TRUE ? MOVE_RAIN_DANCE : MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The sunlight turned harsh!");
        if (viaMove) {
            MESSAGE("Politoed used Rain Dance!");
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
                MESSAGE("It started to rain!");
            }
        } else {
            ABILITY_POPUP(player, ABILITY_DRIZZLE);
            NOT MESSAGE("It started to rain!");
        }
    } THEN {
        ResetStartingStatuses();
    }
}
