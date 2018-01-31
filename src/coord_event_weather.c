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
static void CoordEventWeather_LightRain(void);
static void CoordEventWeather_Snow(void);
static void CoordEventWeather_Thunderstorm(void);
static void CoordEventWeather_Fog(void);
static void CoordEventWeather_DiagonalFog(void);
static void CoordEventWeather_Ash(void);
static void CoordEventWeather_Sandstorm(void);
static void CoordEventWeather_Dark(void);
static void CoordEventWeather_Drought(void);
static void CoordEventWeather_Route119Cycle(void);
static void CoordEventWeather_Route123Cycle(void);

static const struct CoordEventWeather sCoordEventWeatherFuncs[] =
{
    { COORD_EVENT_WEATHER_CLOUDS, CoordEventWeather_Clouds },
    { COORD_EVENT_WEATHER_SUNNY, CoordEventWeather_Sunny },
    { COORD_EVENT_WEATHER_RAIN_LIGHT, CoordEventWeather_LightRain },
    { COORD_EVENT_WEATHER_SNOW, CoordEventWeather_Snow },
    { COORD_EVENT_WEATHER_RAIN_MED, CoordEventWeather_Thunderstorm },
    { COORD_EVENT_WEATHER_FOG_1, CoordEventWeather_Fog },
    { COORD_EVENT_WEATHER_FOG_2, CoordEventWeather_DiagonalFog },
    { COORD_EVENT_WEATHER_ASH, CoordEventWeather_Ash },
    { COORD_EVENT_WEATHER_SANDSTORM, CoordEventWeather_Sandstorm },
    { COORD_EVENT_WEATHER_SHADE, CoordEventWeather_Dark },
    { COORD_EVENT_WEATHER_DROUGHT, CoordEventWeather_Drought },
    { COORD_EVENT_WEATHER_ROUTE119_CYCLE, CoordEventWeather_Route119Cycle },
    { COORD_EVENT_WEATHER_ROUTE123_CYCLE, CoordEventWeather_Route123Cycle },
};

static void CoordEventWeather_Clouds(void)
{
    SetWeather(WEATHER_CLOUDS);
}

static void CoordEventWeather_Sunny(void)
{
    SetWeather(WEATHER_SUNNY);
}

static void CoordEventWeather_LightRain(void)
{
    SetWeather(WEATHER_RAIN_LIGHT);
}

static void CoordEventWeather_Snow(void)
{
    SetWeather(WEATHER_SNOW);
}

static void CoordEventWeather_Thunderstorm(void)
{
    SetWeather(WEATHER_RAIN_MED);
}

static void CoordEventWeather_Fog(void)
{
    SetWeather(WEATHER_FOG_1);
}

static void CoordEventWeather_DiagonalFog(void)
{
    SetWeather(WEATHER_FOG_2);
}

static void CoordEventWeather_Ash(void)
{
    SetWeather(WEATHER_ASH);
}

static void CoordEventWeather_Sandstorm(void)
{
    SetWeather(WEATHER_SANDSTORM);
}

static void CoordEventWeather_Dark(void)
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
