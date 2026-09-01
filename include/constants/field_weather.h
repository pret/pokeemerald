#ifndef GUARD_CONSTANTS_FIELD_WEATHER_H
#define GUARD_CONSTANTS_FIELD_WEATHER_H

#include "config/overworld.h"

// sPaletteColorMapTypes & field_effect_scripts
enum ColorMapType
{
    COLOR_MAP_NONE,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_CONTRAST,
};

#define MAX_RAIN_SPRITES             24
#define NUM_CLOUD_SPRITES            3
#define NUM_FOG_HORIZONTAL_SPRITES   20
#define NUM_ASH_SPRITES              20
#define NUM_FOG_DIAGONAL_SPRITES     20
#define NUM_SANDSTORM_SPRITES        20
#define NUM_SWIRL_SANDSTORM_SPRITES  5
#define NUM_SNOWFLAKE_SPRITES        16

// Controls how the weather should be changing the screen palettes.
#define WEATHER_PAL_STATE_CHANGING_WEATHER   0
#define WEATHER_PAL_STATE_SCREEN_FADING_IN   1
#define WEATHER_PAL_STATE_SCREEN_FADING_OUT  2
#define WEATHER_PAL_STATE_IDLE               3

// Modes for FadeScreen
#define FADE_FROM_BLACK  0
#define FADE_TO_BLACK    1
#define FADE_FROM_WHITE  2
#define FADE_TO_WHITE    3

// Shadows values
#define BASE_SHADOW_INTENSITY (16 - OW_SHADOW_INTENSITY)
#define SHADOW_COLOR_INDEX     9 // Within the weather palette, shadow sprites' color index

#endif // GUARD_CONSTANTS_FIELD_WEATHER_H
