# How to Use Dynamic Weather
*Written by Jordan/harbingerofruination*

## What Is Dynamic Weather?

WEATHER_DYNAMIC applies random daily weather to any map that uses it in its header, updating the weather any time the daily seed resets. 

## How Do I Use Dynamic Weather?

Using dynamic weather was made to be as simple as possible, while still allowing for some customization. It's only a two-step process.

### Step 1: Set Map to Use Dynamic Weather

In either porymap or the map json, change the weather header for the map that you want to have dynamic weather to WEATHER_DYNAMIC.

### Step 2: Define Chooseable Weathers

By default, using WEATHER_DYNAMIC will randomly select from `sDefaultDynamicWeathers[]` in `src/field_weather_effect.c`, which contains sun, rain, snow, sandstorm, volcanic ash, thunderstorm, and drought as possible weathers. However, this may not be ideal for some locations. Let's say, for example, you want Dewford town to have dynamic weather. You'll need to define an array containing the possible weathers that you want. There is currently one commented out you can use as a template, sDynamicWeathers_DewfordTown[]. Let's take a look:

```
static const u8 sDynamicWeathers_DewfordTown[] =
{
    WEATHER_SUNNY,
    WEATHER_RAIN,
    WEATHER_RAIN_THUNDERSTORM,
};
```

With this, we can make Dewford feel more tropical, without the sandstorm, volcanic ash, and snow. We will also need to make entry in sDynamicWeatherPools, such that any maps in MAPSEC_DEWFORD_TOWN share that dynamic weather pool as well as the specific daily weather. That'll look like this:

```
static const struct DynamicWeatherPool sDynamicWeatherPools[] =
{
    { MAPSEC_DEWFORD_TOWN, DYNAMIC_WEATHER_POOL(sDynamicWeathers_DewfordTown) },
};
```

Now, any maps in MAPSEC_DEWFORD_TOWN with WEATHER_DYNAMIC in their header will select from `sDynamicWeathers_DewfordTown[]` instead of the default `sDefaultDynamicWeathers[]` array.