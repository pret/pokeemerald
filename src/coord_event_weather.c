#include "global.h"
#include "constants/weather.h"
#include "coord_event_weather.h"
#include "field_weather.h"

struct CoordEventWeather
{
    u8 coordEventWeather;
    void (*func)(void);
};

static void CoordEventWeather_Clouds(void);
static void CoordEventWeather_Sunny(void);
static void CoordEventWeather_Rain(void);
static void CoordEventWeather_Snow(void);
static void CoordEventWeather_Thunderstorm(void);
static void CoordEventWeather_HorizontalFog(void);
static void CoordEventWeather_DiagonalFog(void);
static void CoordEventWeather_Ash(void);
static void CoordEventWeather_Sandstorm(void);
static void CoordEventWeather_Shade(void);
static void CoordEventWeather_Drought(void);
static void CoordEventWeather_Route119Cycle(void);
static void CoordEventWeather_Route123Cycle(void);

static const struct CoordEventWeather sCoordEventWeatherFuncs[] =
{
    { COORD_EVENT_WEATHER_SUNNY_CLOUDS,      CoordEventWeather_Clouds },
    { COORD_EVENT_WEATHER_SUNNY,             CoordEventWeather_Sunny },
    { COORD_EVENT_WEATHER_RAIN,              CoordEventWeather_Rain },
    { COORD_EVENT_WEATHER_SNOW,              CoordEventWeather_Snow },
    { COORD_EVENT_WEATHER_RAIN_THUNDERSTORM, CoordEventWeather_Thunderstorm },
    { COORD_EVENT_WEATHER_FOG_HORIZONTAL,    CoordEventWeather_HorizontalFog },
    { COORD_EVENT_WEATHER_FOG_DIAGONAL,      CoordEventWeather_DiagonalFog },
    { COORD_EVENT_WEATHER_VOLCANIC_ASH,      CoordEventWeather_Ash },
    { COORD_EVENT_WEATHER_SANDSTORM,         CoordEventWeather_Sandstorm },
    { COORD_EVENT_WEATHER_SHADE,             CoordEventWeather_Shade },
    { COORD_EVENT_WEATHER_DROUGHT,           CoordEventWeather_Drought },
    { COORD_EVENT_WEATHER_ROUTE119_CYCLE,    CoordEventWeather_Route119Cycle },
    { COORD_EVENT_WEATHER_ROUTE123_CYCLE,    CoordEventWeather_Route123Cycle },
};

static void CoordEventWeather_Clouds(void)
{
    SetWeather(WEATHER_SUNNY_CLOUDS);
}

static void CoordEventWeather_Sunny(void)
{
    SetWeather(WEATHER_SUNNY);
}

static void CoordEventWeather_Rain(void)
{
    SetWeather(WEATHER_RAIN);
}

static void CoordEventWeather_Snow(void)
{
    SetWeather(WEATHER_SNOW);
}

static void CoordEventWeather_Thunderstorm(void)
{
    SetWeather(WEATHER_RAIN_THUNDERSTORM);
}

static void CoordEventWeather_HorizontalFog(void)
{
    SetWeather(WEATHER_FOG_HORIZONTAL);
}

static void CoordEventWeather_DiagonalFog(void)
{
    SetWeather(WEATHER_FOG_DIAGONAL);
}

static void CoordEventWeather_Ash(void)
{
    SetWeather(WEATHER_VOLCANIC_ASH);
}

static void CoordEventWeather_Sandstorm(void)
{
    SetWeather(WEATHER_SANDSTORM);
}

static void CoordEventWeather_Shade(void)
{
    SetWeather(WEATHER_SHADE);
}

static void CoordEventWeather_Drought(void)
{
    SetWeather(WEATHER_DROUGHT);
}

static void CoordEventWeather_Route119Cycle(void)
{
    SetWeather(WEATHER_ROUTE119_CYCLE);
}

static void CoordEventWeather_Route123Cycle(void)
{
    SetWeather(WEATHER_ROUTE123_CYCLE);
}

void DoCoordEventWeather(u8 coordEventWeather)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sCoordEventWeatherFuncs); i++)
    {
        if (sCoordEventWeatherFuncs[i].coordEventWeather == coordEventWeather)
        {
            sCoordEventWeatherFuncs[i].func();
            return;
        }
    }
}
