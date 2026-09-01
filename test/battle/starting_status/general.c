#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("SetStartingStatus messages work as intended")
{
    u16 status = 0;

    PARAMETRIZE { status = STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_MISTY_TERRAIN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_GRASSY_TERRAIN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_PSYCHIC_TERRAIN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_TRICK_ROOM_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_MAGIC_ROOM_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WONDER_ROOM_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_RAINBOW_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_SEA_OF_FIRE_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_SWAMP_OPPONENT_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_SPIKES_OPPONENT_L3; }
    PARAMETRIZE { status = STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2; }
    PARAMETRIZE { status = STARTING_STATUS_STICKY_WEB_OPPONENT; }
    PARAMETRIZE { status = STARTING_STATUS_STEALTH_ROCK_OPPONENT; }
    PARAMETRIZE { status = STARTING_STATUS_SHARP_STEEL_OPPONENT; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_SUN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_RAIN_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_SANDSTORM_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_HAIL_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_SNOW_TEMPORARY; }
    PARAMETRIZE { status = STARTING_STATUS_WEATHER_FOG_TEMPORARY; }

    SetStartingStatus(status);

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DEFOG) == EFFECT_DEFOG);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN { MOVE(player, (status >= STARTING_STATUS_SPIKES_OPPONENT_L3 && status <= STARTING_STATUS_SHARP_STEEL_OPPONENT) ? MOVE_DEFOG : MOVE_CELEBRATE); }
        TURN {}
        TURN {}
    } SCENE {
        // Before first turn
        switch (status)
        {
        case STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY:
            MESSAGE("An electric current is running across the battlefield!");
            break;
        case STARTING_STATUS_MISTY_TERRAIN_TEMPORARY:
            MESSAGE("Mist swirls around the battlefield!");
            break;
        case STARTING_STATUS_GRASSY_TERRAIN_TEMPORARY:
            MESSAGE("The battlefield is covered with grass!");
            break;
        case STARTING_STATUS_PSYCHIC_TERRAIN_TEMPORARY:
            MESSAGE("The battlefield seems weird!");
            break;
        case STARTING_STATUS_TRICK_ROOM_TEMPORARY:
            MESSAGE("The dimensions were twisted!");
            break;
        case STARTING_STATUS_MAGIC_ROOM_TEMPORARY:
            MESSAGE("A bizarre area was created in which Pokémon's held items lose their effects!");
            break;
        case STARTING_STATUS_WONDER_ROOM_TEMPORARY:
            MESSAGE("A bizarre area was created in which Defense and Sp. Def stats are swapped!");
            break;
        case STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY:
            MESSAGE("A tailwind started blowing on the opposing side!");
            break;
        case STARTING_STATUS_RAINBOW_OPPONENT_TEMPORARY:
            MESSAGE("A rainbow appeared in the sky on the opposing side!");
            break;
        case STARTING_STATUS_SEA_OF_FIRE_OPPONENT_TEMPORARY:
            MESSAGE("A sea of fire enveloped the opposing side!");
            break;
        case STARTING_STATUS_SWAMP_OPPONENT_TEMPORARY:
            MESSAGE("A swamp enveloped the opposing side!");
            break;
        case STARTING_STATUS_SPIKES_OPPONENT_L3:
            MESSAGE("Spikes were scattered on the ground all around the opposing side!");
            MESSAGE("The opposing Wobbuffet was hurt by the spikes!");
            break;
        case STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2:
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
            MESSAGE("The opposing Wobbuffet was badly poisoned!");
            break;
        case STARTING_STATUS_STICKY_WEB_OPPONENT:
            MESSAGE("A sticky web has been laid out on the ground on the opposing side!");
            MESSAGE("The opposing Wobbuffet was caught in a sticky web!");
            break;
        case STARTING_STATUS_STEALTH_ROCK_OPPONENT:
            MESSAGE("Pointed stones float in the air on the opposing side!");
            MESSAGE("Pointed stones dug into the opposing Wobbuffet!");
            break;
        case STARTING_STATUS_SHARP_STEEL_OPPONENT:
            MESSAGE("Sharp-pointed pieces of steel started floating around the opposing Pokémon!");
            MESSAGE("The sharp steel bit into the opposing Wobbuffet!");
            break;
        case STARTING_STATUS_WEATHER_SUN_TEMPORARY:
            MESSAGE("The sunlight turned harsh!");
            break;
        case STARTING_STATUS_WEATHER_RAIN_TEMPORARY:
            MESSAGE("It started to rain!");
            break;
        case STARTING_STATUS_WEATHER_SANDSTORM_TEMPORARY:
            MESSAGE("A sandstorm kicked up!");
            break;
        case STARTING_STATUS_WEATHER_HAIL_TEMPORARY:
            MESSAGE("It started to hail!");
            break;
        case STARTING_STATUS_WEATHER_SNOW_TEMPORARY:
            MESSAGE("It started to snow!");
            break;
        case STARTING_STATUS_WEATHER_FOG_TEMPORARY:
            MESSAGE("Fog crept up as thick as soup!");
            break;
        }

        // End turn messages
        switch (status)
        {
        case STARTING_STATUS_SEA_OF_FIRE_OPPONENT_TEMPORARY:
            MESSAGE("The opposing Wobbuffet was hurt by the sea of fire!");
            break;
        case STARTING_STATUS_WEATHER_SUN_TEMPORARY:
            MESSAGE("The sunlight is strong.");
            break;
        case STARTING_STATUS_WEATHER_RAIN_TEMPORARY:
            MESSAGE("Rain continues to fall.");
            break;
        case STARTING_STATUS_WEATHER_SANDSTORM_TEMPORARY:
            MESSAGE("The sandstorm is raging.");
            break;
        case STARTING_STATUS_WEATHER_HAIL_TEMPORARY: 
            MESSAGE("The hail is crashing down.");
            break;
        case STARTING_STATUS_WEATHER_SNOW_TEMPORARY: 
            MESSAGE("Snow continues to fall.");
            break;
        case STARTING_STATUS_WEATHER_FOG_TEMPORARY: 
            MESSAGE("The fog is deep…");
            break;
        }

        // Turn 3 Defog
        switch (status)
        {
        case STARTING_STATUS_SPIKES_OPPONENT_L3:
            MESSAGE("The spikes disappeared from the ground around the opposing side!");
            break;
        case STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2:
            MESSAGE("The toxic spikes disappeared from the ground around the opposing side!");
            break;
        case STARTING_STATUS_STICKY_WEB_OPPONENT:
            MESSAGE("The sticky web has disappeared from the ground on the opposing side!");
            break;
        case STARTING_STATUS_STEALTH_ROCK_OPPONENT:
            MESSAGE("The pointed stones disappeared from the opposing side!");
            break;
        case STARTING_STATUS_SHARP_STEEL_OPPONENT:
            MESSAGE("The pieces of steel surrounding the opposing Pokémon disappeared!");
            break;
        }

        // Turn 4 end
        switch (status)
        {
        case STARTING_STATUS_TAILWIND_OPPONENT_TEMPORARY:
            MESSAGE("The opposing side's tailwind petered out!");
            break;
        case STARTING_STATUS_RAINBOW_OPPONENT_TEMPORARY:
            MESSAGE("The rainbow on the opposing side disappeared!");
            break;
        case STARTING_STATUS_SEA_OF_FIRE_OPPONENT_TEMPORARY:
            MESSAGE("The sea of fire around the opposing side disappeared!");
            break;
        case STARTING_STATUS_SWAMP_OPPONENT_TEMPORARY:
            MESSAGE("The swamp around the opposing side disappeared!");
            break;
        }

        // Turn 5 end
        switch (status)
        {
        case STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY:
            MESSAGE("The electricity disappeared from the battlefield.");
            break;
        case STARTING_STATUS_TRICK_ROOM_TEMPORARY:
            MESSAGE("The twisted dimensions returned to normal!");
            break;
        case STARTING_STATUS_WONDER_ROOM_TEMPORARY:
            MESSAGE("Wonder Room wore off, and Defense and Sp. Def stats returned to normal!");
            break;
        case STARTING_STATUS_MAGIC_ROOM_TEMPORARY:
            MESSAGE("Magic Room wore off, and held items' effects returned to normal!");
            break;
        case STARTING_STATUS_WEATHER_SUN_TEMPORARY:
            MESSAGE("The sunlight faded.");
            break;
        case STARTING_STATUS_WEATHER_RAIN_TEMPORARY:
            MESSAGE("The rain stopped.");
            break;
        case STARTING_STATUS_WEATHER_SANDSTORM_TEMPORARY:
            MESSAGE("The sandstorm subsided.");
            break;
        case STARTING_STATUS_WEATHER_HAIL_TEMPORARY: 
            MESSAGE("The hail stopped.");
            break;
        case STARTING_STATUS_WEATHER_SNOW_TEMPORARY: 
            MESSAGE("The snow stopped.");
            break;
        case STARTING_STATUS_WEATHER_FOG_TEMPORARY: 
            MESSAGE("The fog lifted.");
            break;
        }
    } THEN {
        ResetStartingStatuses();
    }
}
