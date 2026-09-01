#include "global.h"
#include "constants/songs.h"
#include "constants/weather.h"
#include "constants/rgb.h"
#include "util.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "random.h"
#include "script.h"
#include "start_menu.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "gpu_regs.h"
#include "field_camera.h"
#include "overworld.h"

#define DROUGHT_COLOR_INDEX(color) ((((color) >> 1) & 0xF) | (((color) >> 2) & 0xF0) | (((color) >> 3) & 0xF00))

struct RGBColor
{
    u16 r:5;
    u16 g:5;
    u16 b:5;
};

struct WeatherCallbacks
{
    void (*initVars)(void);
    void (*main)(void);
    void (*initAll)(void);
    bool8 (*finish)(void);
};

// This file's functions.
static bool8 LightenSpritePaletteInFog(u8);
static void UpdateWeatherColorMap(void);
static void ApplyColorMap(u8 startPalIndex, u8 numPalettes, s8 colorMapIndex);
static void ApplyColorMapWithBlend(u8 startPalIndex, u8 numPalettes, s8 colorMapIndex, u8 blendCoeff, u32 blendColor);
static void ApplyDroughtColorMapWithBlend(s8 colorMapIndex, u8 blendCoeff, u32 blendColor);
static void ApplyFogBlend(u8 blendCoeff, u32 blendColor);
static bool8 FadeInScreen_RainShowShade(void);
static bool8 FadeInScreen_Drought(void);
static bool8 FadeInScreen_FogHorizontal(void);
static void FadeInScreenWithWeather(void);
static void DoNothing(void);
static void Task_WeatherInit(u8 taskId);
static void Task_WeatherMain(u8 taskId);
static void None_Init(void);
static void None_Main(void);
static u8 None_Finish(void);
static bool32 IsSpritePalTagBlendImmune(u32 palIndex);

EWRAM_DATA struct Weather gWeather = {0};
EWRAM_DATA static u8 ALIGNED(2) sFieldEffectPaletteColorMapTypes[32] = {0};

static const u8 *sPaletteColorMapTypes;

static const u8 sDarkenedContrastColorMaps[NUM_WEATHER_COLOR_MAPS][32] =
{
    {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14, 14, 15, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27},
    {0, 0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 11, 12, 13, 13, 14, 15, 16, 17, 17, 18, 19, 20, 21, 21, 22, 23, 24, 25},
    {0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 11, 11, 12, 13, 14, 14, 15, 16, 17, 17, 18, 19, 20, 20, 21, 22, 23, 24, 24, 25},
    {1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 12, 13, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 20, 21, 22, 23, 23, 24, 25, 25},
    {1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 13, 14, 15, 15, 16, 17, 17, 18, 19, 19, 20, 20, 21, 22, 22, 23, 24, 24, 25, 26},
    {1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 15, 15, 16, 16, 17, 18, 18, 19, 19, 20, 21, 21, 22, 22, 23, 24, 24, 25, 26, 26},
    {1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 16, 16, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 23, 23, 24, 24, 25, 25, 26, 27},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 19, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 24, 25, 25, 26, 26, 27, 27},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 20, 20, 21, 21, 22, 22, 22, 23, 23, 24, 24, 24, 25, 25, 26, 26, 26, 27, 27, 28},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 27, 27, 27, 28, 28},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 23, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 28, 28, 28, 28, 29},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 25, 25, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 29, 29, 29},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 27, 27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},
    {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31}
};

static const u8 sContrastColorMaps[NUM_WEATHER_COLOR_MAPS][32] =
{
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 11, 14, 15, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 16, 17, 18, 18, 19, 20, 21, 22, 22, 23, 24, 25, 26, 26, 27, 28, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 17, 18, 19, 19, 20, 21, 22, 22, 23, 24, 25, 25, 26, 27, 28, 28, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 17, 18, 19, 20, 20, 21, 22, 22, 23, 24, 24, 25, 26, 26, 27, 28, 28, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 19, 19, 20, 21, 21, 22, 22, 23, 24, 24, 25, 26, 26, 27, 27, 28, 29, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 20, 20, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 27, 27, 28, 28, 29, 29, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 22, 23, 23, 24, 24, 24, 25, 25, 26, 26, 27, 27, 27, 28, 28, 29, 29, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 23, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 26, 26, 26, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 27, 27, 27, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31}
};

// The drought weather effect uses a precalculated color lookup table. Presumably this
// is because the underlying color shift calculation is slow.
static const u16 sDroughtWeatherColors[][0x1000] = {
    INCBIN_U16("graphics/weather/drought/colors_0.bin"),
    INCBIN_U16("graphics/weather/drought/colors_1.bin"),
    INCBIN_U16("graphics/weather/drought/colors_2.bin"),
    INCBIN_U16("graphics/weather/drought/colors_3.bin"),
    INCBIN_U16("graphics/weather/drought/colors_4.bin"),
    INCBIN_U16("graphics/weather/drought/colors_5.bin"),
};

// This is a pointer to gWeather. All code in this file accesses gWeather directly,
// while code in other field weather files accesses gWeather through this pointer.
// This is likely the result of compiler optimization, since using the pointer in
// this file produces the same result as accessing gWeather directly.
struct Weather *const gWeatherPtr = &gWeather;

static const struct WeatherCallbacks sWeatherFuncs[] =
{
    [WEATHER_NONE]               = {None_Init,              None_Main,          None_Init,             None_Finish},
    [WEATHER_SUNNY_CLOUDS]       = {Clouds_InitVars,        Clouds_Main,        Clouds_InitAll,        Clouds_Finish},
    [WEATHER_SUNNY]              = {Sunny_InitVars,         Sunny_Main,         Sunny_InitAll,         Sunny_Finish},
    [WEATHER_RAIN]               = {Rain_InitVars,          Rain_Main,          Rain_InitAll,          Rain_Finish},
    [WEATHER_SNOW]               = {Snow_InitVars,          Snow_Main,          Snow_InitAll,          Snow_Finish},
    [WEATHER_RAIN_THUNDERSTORM]  = {Thunderstorm_InitVars,  Thunderstorm_Main,  Thunderstorm_InitAll,  Thunderstorm_Finish},
    [WEATHER_FOG_HORIZONTAL]     = {FogHorizontal_InitVars, FogHorizontal_Main, FogHorizontal_InitAll, FogHorizontal_Finish},
    [WEATHER_VOLCANIC_ASH]       = {Ash_InitVars,           Ash_Main,           Ash_InitAll,           Ash_Finish},
    [WEATHER_SANDSTORM]          = {Sandstorm_InitVars,     Sandstorm_Main,     Sandstorm_InitAll,     Sandstorm_Finish},
    [WEATHER_FOG_DIAGONAL]       = {FogDiagonal_InitVars,   FogDiagonal_Main,   FogDiagonal_InitAll,   FogDiagonal_Finish},
    [WEATHER_UNDERWATER]         = {FogHorizontal_InitVars, FogHorizontal_Main, FogHorizontal_InitAll, FogHorizontal_Finish},
    [WEATHER_SHADE]              = {Shade_InitVars,         Shade_Main,         Shade_InitAll,         Shade_Finish},
    [WEATHER_DROUGHT]            = {Drought_InitVars,       Drought_Main,       Drought_InitAll,       Drought_Finish},
    [WEATHER_DOWNPOUR]           = {Downpour_InitVars,      Thunderstorm_Main,  Downpour_InitAll,      Thunderstorm_Finish},
    [WEATHER_UNDERWATER_BUBBLES] = {Bubbles_InitVars,       Bubbles_Main,       Bubbles_InitAll,       Bubbles_Finish},
};

void (*const gWeatherPalStateFuncs[])(void) =
{
    [WEATHER_PAL_STATE_CHANGING_WEATHER]  = UpdateWeatherColorMap,
    [WEATHER_PAL_STATE_SCREEN_FADING_IN]  = FadeInScreenWithWeather,
    [WEATHER_PAL_STATE_SCREEN_FADING_OUT] = DoNothing,
    [WEATHER_PAL_STATE_IDLE]              = DoNothing,
};

// This table specifies which of the color maps should be
// applied to each of the background and sprite palettes.
static const u8 ALIGNED(2) sBasePaletteColorMapTypes[32] =
{
    // background palettes
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_NONE,
    COLOR_MAP_NONE,
    COLOR_MAP_NONE,
    // sprite palettes
    COLOR_MAP_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
    COLOR_MAP_DARK_CONTRAST,
};

const u16 ALIGNED(4) gFogPalette[] = INCGFX_U16("graphics/weather/fog.pal", ".gbapal");

void StartWeather(void)
{
    if (!FuncIsActiveTask(Task_WeatherMain))
    {
        u8 index = AllocSpritePalette(PALTAG_WEATHER);
        CpuCopy32(gFogPalette, &gPlttBufferUnfaded[OBJ_PLTT_ID(index)], PLTT_SIZE_4BPP);

        sPaletteColorMapTypes = sBasePaletteColorMapTypes;

        gWeatherPtr->contrastColorMapSpritePalIndex = index;
        gWeatherPtr->weatherPicSpritePalIndex = 0xFF; // defer allocation until needed
        gWeatherPtr->rainSpriteCount = 0;
        gWeatherPtr->curRainSpriteIndex = 0;
        gWeatherPtr->cloudSpritesCreated = 0;
        gWeatherPtr->snowflakeSpriteCount = 0;
        gWeatherPtr->ashSpritesCreated = 0;
        gWeatherPtr->fogHSpritesCreated = 0;
        gWeatherPtr->fogDSpritesCreated = 0;
        gWeatherPtr->sandstormSpritesCreated = 0;
        gWeatherPtr->sandstormSwirlSpritesCreated = 0;
        gWeatherPtr->bubblesSpritesCreated = 0;
        gWeatherPtr->lightenedFogSpritePalsCount = 0;
        Weather_SetBlendCoeffs(16, 0);
        gWeatherPtr->currWeather = 0;
        gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        gWeatherPtr->readyForInit = FALSE;
        gWeatherPtr->weatherChangeComplete = TRUE;
        gWeatherPtr->taskId = CreateTask(Task_WeatherInit, 80);
    }
}

void SetNextWeather(u8 weather)
{
    if (weather != WEATHER_RAIN && weather != WEATHER_RAIN_THUNDERSTORM && weather != WEATHER_DOWNPOUR)
    {
        PlayRainStoppingSoundEffect();
    }

    if (gWeatherPtr->nextWeather != weather && gWeatherPtr->currWeather == weather)
    {
        sWeatherFuncs[weather].initVars();
    }

    gWeatherPtr->weatherChangeComplete = FALSE;
    gWeatherPtr->nextWeather = weather;
    gWeatherPtr->finishStep = 0;
}

static void UpdateWeatherForms(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        enum Species species = GetMonData(mon, MON_DATA_SPECIES);
        enum Species targetSpecies = GetOverworldWeatherSpecies(species);
        if (species != targetSpecies)
        {
            SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
            CalculateMonStats(mon);
        }
    }
}

void SetCurrentAndNextWeather(u8 weather)
{
    PlayRainStoppingSoundEffect();
    gWeatherPtr->currWeather = weather;
    gWeatherPtr->nextWeather = weather;
    UpdateWeatherForms();
}

void SetCurrentAndNextWeatherNoDelay(u8 weather)
{
    PlayRainStoppingSoundEffect();
    gWeatherPtr->currWeather = weather;
    gWeatherPtr->nextWeather = weather;
    // Overrides the normal delay during screen fading.
    gWeatherPtr->readyForInit = TRUE;
    UpdateWeatherForms();
}

static void Task_WeatherInit(u8 taskId)
{
    // Waits until it's ok to initialize weather.
    // When the screen fades in, this is set to TRUE.
    if (gWeatherPtr->readyForInit)
    {
        UpdateCameraPanning();
        sWeatherFuncs[gWeatherPtr->currWeather].initAll();
        gTasks[taskId].func = Task_WeatherMain;
    }
}

static void Task_WeatherMain(u8 taskId)
{
    if (gWeatherPtr->currWeather != gWeatherPtr->nextWeather)
    {
        if (!sWeatherFuncs[gWeatherPtr->currWeather].finish()
            && gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
        {
            // Finished cleaning up previous weather. Now transition to next weather.
            sWeatherFuncs[gWeatherPtr->nextWeather].initVars();
            gWeatherPtr->colorMapStepCounter = 0;
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_CHANGING_WEATHER;
            gWeatherPtr->currWeather = gWeatherPtr->nextWeather;
            gWeatherPtr->weatherChangeComplete = TRUE;
            UpdateWeatherForms();
        }
    }
    else
    {
        sWeatherFuncs[gWeatherPtr->currWeather].main();
    }

    gWeatherPalStateFuncs[gWeatherPtr->palProcessingState]();
}

static void None_Init(void)
{
    Weather_SetBlendCoeffs(8, BASE_SHADOW_INTENSITY); // Indoor shadows
    gWeatherPtr->noShadows = FALSE;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 0;
}

static void None_Main(void)
{
}

static u8 None_Finish(void)
{
    return 0;
}

// When the weather is changing, it gradually updates the palettes
// towards the desired color map.
static void UpdateWeatherColorMap(void)
{
    if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
    {
        if (gWeatherPtr->colorMapIndex == gWeatherPtr->targetColorMapIndex)
        {
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        }
        else
        {
            if (++gWeatherPtr->colorMapStepCounter >= gWeatherPtr->colorMapStepDelay)
            {
                gWeatherPtr->colorMapStepCounter = 0;
                if (gWeatherPtr->colorMapIndex < gWeatherPtr->targetColorMapIndex)
                    gWeatherPtr->colorMapIndex++;
                else
                    gWeatherPtr->colorMapIndex--;

                ApplyColorMap(0, 32, gWeatherPtr->colorMapIndex);
            }
        }
    }
}

static void FadeInScreenWithWeather(void)
{
    if (++gWeatherPtr->fadeInTimer > 1)
        gWeatherPtr->fadeInFirstFrame = FALSE;

    switch (gWeatherPtr->currWeather)
    {
    case WEATHER_RAIN:
    case WEATHER_RAIN_THUNDERSTORM:
    case WEATHER_DOWNPOUR:
    case WEATHER_SHADE:
        if (FadeInScreen_RainShowShade() == FALSE)
        {
            gWeatherPtr->colorMapIndex = 3;
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        }
        break;
    case WEATHER_DROUGHT:
        if (FadeInScreen_Drought() == FALSE)
        {
            gWeatherPtr->colorMapIndex = -6;
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        }
        break;
    case WEATHER_FOG_HORIZONTAL:
        if (FadeInScreen_FogHorizontal() == FALSE)
        {
            gWeatherPtr->colorMapIndex = 0;
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        }
        break;
    case WEATHER_SNOW:
    case WEATHER_VOLCANIC_ASH:
    case WEATHER_SANDSTORM:
    case WEATHER_FOG_DIAGONAL:
    case WEATHER_UNDERWATER:
    default:
        if (!gPaletteFade.active)
        {
            gWeatherPtr->colorMapIndex = gWeatherPtr->targetColorMapIndex;
            gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
        }
        break;
    }
}

static bool8 FadeInScreen_RainShowShade(void)
{
    if (gWeatherPtr->fadeScreenCounter == 16)
        return FALSE;

    if (++gWeatherPtr->fadeScreenCounter >= 16)
    {
        ApplyColorMap(0, 32, 3);
        gWeatherPtr->fadeScreenCounter = 16;
        return FALSE;
    }

    ApplyColorMapWithBlend(0, 32, 3, 16 - gWeatherPtr->fadeScreenCounter, gWeatherPtr->fadeDestColor);
    return TRUE;
}

static bool8 FadeInScreen_Drought(void)
{
    if (gWeatherPtr->fadeScreenCounter == 16)
        return FALSE;

    if (++gWeatherPtr->fadeScreenCounter >= 16)
    {
        ApplyColorMap(0, 32, -6);
        gWeatherPtr->fadeScreenCounter = 16;
        return FALSE;
    }

    ApplyDroughtColorMapWithBlend(-6, 16 - gWeatherPtr->fadeScreenCounter, gWeatherPtr->fadeDestColor);
    return TRUE;
}

static bool8 FadeInScreen_FogHorizontal(void)
{
    if (gWeatherPtr->fadeScreenCounter == 16)
        return FALSE;

    gWeatherPtr->fadeScreenCounter++;
    ApplyFogBlend(16 - gWeatherPtr->fadeScreenCounter, gWeatherPtr->fadeDestColor);
    return TRUE;
}

static void DoNothing(void)
{ }

static bool32 IsSpritePalTagBlendImmune(u32 palIndex)
{
    return (palIndex >= 16 && IS_BLEND_IMMUNE_TAG(GetSpritePaletteTagByPaletteNum(palIndex - 16)));
}

static void ApplyColorMap(u8 startPalIndex, u8 numPalettes, s8 colorMapIndex)
{
    u16 curPalIndex;
    u16 palOffset;
    const u8 *colorMap;
    u32 i;

    if (colorMapIndex > 0)
    {
        // Create the palette mask
        u32 palettes = PALETTES_ALL;
        numPalettes += startPalIndex;
        palettes = (palettes >> startPalIndex) << startPalIndex;
        palettes = (palettes << (32 - numPalettes)) >> (32 - numPalettes);
        numPalettes -= startPalIndex;
        colorMapIndex--;
        palOffset = PLTT_ID(startPalIndex);
        UpdateAltBgPalettes(palettes & PALETTES_BG);
        // Thunder gamma-shift looks bad on night-blended palettes, so ignore time blending in some situations
        if (colorMapIndex <= 3 && MapHasNaturalLight(gMapHeader.mapType))
            UpdatePalettesWithTime(palettes);
        else
            CpuFastCopy(gPlttBufferUnfaded + palOffset, gPlttBufferFaded + palOffset, PLTT_SIZE_4BPP * numPalettes);
        numPalettes += startPalIndex;
        curPalIndex = startPalIndex;

        // Loop through the specified palette range and apply necessary color maps.
        while (curPalIndex < numPalettes)
        {
            // don't blend special palettes immune to blending
            if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_NONE || IsSpritePalTagBlendImmune(curPalIndex))
            {
                // No palette change.
                palOffset += 16;
            }
            else
            {
                u8 r, g, b;

                if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_CONTRAST || curPalIndex - 16 == gWeatherPtr->contrastColorMapSpritePalIndex)
                    colorMap = sContrastColorMaps[colorMapIndex];
                else
                    colorMap = sDarkenedContrastColorMaps[colorMapIndex];

                for (i = 0; i < 16; i++)
                {
                    // Apply color map to the original color.
                    struct RGBColor baseColor = *(struct RGBColor *)&gPlttBufferFaded[palOffset];
                    r = colorMap[baseColor.r];
                    g = colorMap[baseColor.g];
                    b = colorMap[baseColor.b];
                    gPlttBufferFaded[palOffset++] = RGB2(r, g, b);
                }
            }

            curPalIndex++;
        }
    }
    else if (colorMapIndex < 0)
    {
        // A negative gammIndex value means that the blending will come from the special Drought weather's palette tables.
        colorMapIndex = -colorMapIndex - 1;
        palOffset = PLTT_ID(startPalIndex);
        numPalettes += startPalIndex;
        curPalIndex = startPalIndex;

        while (curPalIndex < numPalettes)
        {
            if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_NONE || IsSpritePalTagBlendImmune(curPalIndex))
            {
                // No palette change.
                CpuFastCopy(&gPlttBufferUnfaded[palOffset], &gPlttBufferFaded[palOffset], PLTT_SIZE_4BPP);
                palOffset += 16;
            }
            else
            {
                for (i = 0; i < 16; i++)
                {
                    gPlttBufferFaded[palOffset] = sDroughtWeatherColors[colorMapIndex][DROUGHT_COLOR_INDEX(gPlttBufferUnfaded[palOffset])];
                    palOffset++;
                }
            }

            curPalIndex++;
        }
    }
    else
    {
        if (MapHasNaturalLight(gMapHeader.mapType))
        {
            // Time-blend
            u32 palettes = ((1 << numPalettes) - 1) << startPalIndex;
            UpdateAltBgPalettes(palettes & PALETTES_BG);
            UpdatePalettesWithTime(palettes);
        }
        else
        {
            CpuFastCopy(&gPlttBufferUnfaded[PLTT_ID(startPalIndex)], &gPlttBufferFaded[PLTT_ID(startPalIndex)], numPalettes * PLTT_SIZE_4BPP);
        }
    }
}

static void ApplyColorMapWithBlend(u8 startPalIndex, u8 numPalettes, s8 colorMapIndex, u8 blendCoeff, u32 blendColor)
{
    u16 palOffset;
    u16 curPalIndex;
    u32 i;
    struct RGBColor color = *(struct RGBColor *)&blendColor;
    u8 rBlend = color.r;
    u8 gBlend = color.g;
    u8 bBlend = color.b;

    palOffset = PLTT_ID(startPalIndex);
    numPalettes += startPalIndex;
    colorMapIndex--;
    curPalIndex = startPalIndex;

    while (curPalIndex < numPalettes)
    {
        UpdateAltBgPalettes((1 << (palOffset >> 4)) & PALETTES_BG);
        CpuFastCopy(gPlttBufferUnfaded + palOffset, gPlttBufferFaded + palOffset, 16 * sizeof(u16));
        UpdatePalettesWithTime(1 << (palOffset >> 4)); // Apply TOD blend
        if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_NONE || IsSpritePalTagBlendImmune(curPalIndex))
        {
            // No color map. Simply blend the colors.
            BlendPalettesFine(1, gPlttBufferFaded + palOffset, gPlttBufferFaded + palOffset, blendCoeff, blendColor);
            palOffset += 16;
        }
        else
        {
            const u8 *colorMap;

            if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_DARK_CONTRAST)
                colorMap = sDarkenedContrastColorMaps[colorMapIndex];
            else
                colorMap = sContrastColorMaps[colorMapIndex];

            for (i = 0; i < 16; i++)
            {
                struct RGBColor baseColor = *(struct RGBColor *)&gPlttBufferFaded[palOffset];
                u8 r = colorMap[baseColor.r];
                u8 g = colorMap[baseColor.g];
                u8 b = colorMap[baseColor.b];

                // Apply color map and target blend color to the original color.
                r += ((rBlend - r) * blendCoeff) >> 4;
                g += ((gBlend - g) * blendCoeff) >> 4;
                b += ((bBlend - b) * blendCoeff) >> 4;
                gPlttBufferFaded[palOffset++] = RGB2(r, g, b);
            }
        }

        curPalIndex++;
    }
}

static void ApplyDroughtColorMapWithBlend(s8 colorMapIndex, u8 blendCoeff, u32 blendColor)
{
    struct RGBColor color;
    u8 rBlend;
    u8 gBlend;
    u8 bBlend;
    u16 curPalIndex;
    u16 palOffset;
    u16 i;

    colorMapIndex = -colorMapIndex - 1;
    color = *(struct RGBColor *)&blendColor;
    rBlend = color.r;
    gBlend = color.g;
    bBlend = color.b;
    palOffset = 0;
    for (curPalIndex = 0; curPalIndex < 32; curPalIndex++)
    {
        if (sPaletteColorMapTypes[curPalIndex] == COLOR_MAP_NONE|| IsSpritePalTagBlendImmune(curPalIndex))
        {
            // No color map. Simply blend the colors.
            BlendPalette(palOffset, 16, blendCoeff, blendColor);
            palOffset += 16;
        }
        else
        {
            for (i = 0; i < 16; i++)
            {
                u32 offset;
                struct RGBColor color1;
                struct RGBColor color2;
                u8 r1, g1, b1;
                u8 r2, g2, b2;

                color1 = *(struct RGBColor *)&gPlttBufferUnfaded[palOffset];
                r1 = color1.r;
                g1 = color1.g;
                b1 = color1.b;

                offset = ((b1 & 0x1E) << 7) | ((g1 & 0x1E) << 3) | ((r1 & 0x1E) >> 1);
                color2 = *(struct RGBColor *)&sDroughtWeatherColors[colorMapIndex][offset];
                r2 = color2.r;
                g2 = color2.g;
                b2 = color2.b;

                r2 += ((rBlend - r2) * blendCoeff) >> 4;
                g2 += ((gBlend - g2) * blendCoeff) >> 4;
                b2 += ((bBlend - b2) * blendCoeff) >> 4;

                gPlttBufferFaded[palOffset++] = RGB2(r2, g2, b2);
            }
        }
    }
}

// This is only called during fade-in/fade-out in fog
// blendCoeff & blendColor are the *fade* colors, not fog colors
static void ApplyFogBlend(u8 blendCoeff, u32 blendColor)
{
    u32 curPalIndex;
    u16 fogCoeff = min((gTimeOfDay + 1) * 4, 12);

    // First blend all palettes with time
    UpdateAltBgPalettes(PALETTES_BG);
    CpuFastCopy(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_BUFFER_SIZE * 2);
    UpdatePalettesWithTime(PALETTES_ALL);
    // Then blend tile palettes [0, 12] faded->faded with fadeIn color
    BlendPalettesFine(PALETTES_MAP, gPlttBufferFaded, gPlttBufferFaded, blendCoeff, blendColor);

    // Do fog blending on marked sprite palettes
    for (curPalIndex = 16; curPalIndex < 32; curPalIndex++)
    {
        if (LightenSpritePaletteInFog(curPalIndex))
            BlendPalettesFine(1, gPlttBufferFaded + PLTT_ID(curPalIndex), gPlttBufferFaded + PLTT_ID(curPalIndex), fogCoeff, RGB(28, 31, 28));
    }
    // Finally blend all sprite palettes faded->faded with fadeIn color
    BlendPalettesFine(PALETTES_OBJECTS, gPlttBufferFaded, gPlttBufferFaded, blendCoeff, blendColor);
}

static void MarkFogSpritePalToLighten(u8 paletteIndex)
{
    if (gWeatherPtr->lightenedFogSpritePalsCount < 6)
    {
        gWeatherPtr->lightenedFogSpritePals[gWeatherPtr->lightenedFogSpritePalsCount] = paletteIndex;
        gWeatherPtr->lightenedFogSpritePalsCount++;
    }
}

static bool8 LightenSpritePaletteInFog(u8 paletteIndex)
{
    u32 i;

    if (paletteIndex >= 16 && IS_BLEND_IMMUNE_TAG(GetSpritePaletteTagByPaletteNum(paletteIndex - 16)))
        return FALSE;

    for (i = 0; i < gWeatherPtr->lightenedFogSpritePalsCount; i++)
    {
        if (gWeatherPtr->lightenedFogSpritePals[i] == paletteIndex)
            return TRUE;
    }

    return FALSE;
}

void ApplyWeatherColorMapIfIdle(s8 colorMapIndex)
{
    if (gWeatherPtr->palProcessingState == WEATHER_PAL_STATE_IDLE)
    {
        ApplyColorMap(0, 32, colorMapIndex);
        gWeatherPtr->colorMapIndex = colorMapIndex;
    }
}

void ApplyWeatherColorMapIfIdle_Gradual(u8 colorMapIndex, u8 targetColorMapIndex, u8 colorMapStepDelay)
{
    if (gWeatherPtr->palProcessingState == WEATHER_PAL_STATE_IDLE)
    {
        gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_CHANGING_WEATHER;
        gWeatherPtr->colorMapIndex = colorMapIndex;
        gWeatherPtr->targetColorMapIndex = targetColorMapIndex;
        gWeatherPtr->colorMapStepCounter = 0;
        gWeatherPtr->colorMapStepDelay = colorMapStepDelay;
        ApplyWeatherColorMapIfIdle(colorMapIndex);
    }
}

void FadeScreen(u8 mode, s8 delay)
{
    FadeSelectedPals(mode, delay, PALETTES_ALL);
}

void FadeSelectedPals(u8 mode, s8 delay, u32 selectedPalettes)
{
    u32 fadeColor;
    bool8 fadeOut;
    bool8 useWeatherPal;

    switch (mode)
    {
    case FADE_FROM_BLACK:
        fadeColor = RGB_BLACK;
        fadeOut = FALSE;
        break;
    case FADE_FROM_WHITE:
        fadeColor = RGB_WHITEALPHA;
        fadeOut = FALSE;
        break;
    case FADE_TO_BLACK:
        fadeColor = RGB_BLACK;
        fadeOut = TRUE;
        break;
    case FADE_TO_WHITE:
        fadeColor = RGB_WHITEALPHA;
        fadeOut = TRUE;
        break;
    default:
        return;
    }

    switch (gWeatherPtr->currWeather)
    {
    case WEATHER_RAIN:
    case WEATHER_RAIN_THUNDERSTORM:
    case WEATHER_DOWNPOUR:
    case WEATHER_FOG_HORIZONTAL:
    case WEATHER_SHADE:
    case WEATHER_DROUGHT:
        useWeatherPal = TRUE;
        break;
    default:
        useWeatherPal = FALSE;
        break;
    }

    if (fadeOut)
    {
        // Note: Copying faded -> unfaded like this works fine, except if the screen is faded back in
        // without transitioning to a different screen
        // For cases like that, use fadescreenswapbuffers
        CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, PLTT_BUFFER_SIZE * 2);

        gPaletteFade.simultaneousFade = TRUE;
        BeginNormalPaletteFade(selectedPalettes, delay, 0, 16, fadeColor);
        gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_SCREEN_FADING_OUT;
    }
    else
    {
        gWeatherPtr->fadeDestColor = fadeColor;
        UpdateTimeOfDay(TRUE);
        if (useWeatherPal)
        {
            gWeatherPtr->fadeScreenCounter = 0; // Triggers gamma-shift-based fade-in
        }
        else if (MapHasNaturalLight(gMapHeader.mapType))
        {
            UpdateAltBgPalettes(selectedPalettes & PALETTES_BG);
            BeginTimeOfDayPaletteFade(selectedPalettes, delay, 16, 0, &gTimeBlend.startBlend, &gTimeBlend.endBlend, gTimeBlend.weight, fadeColor);
        }
        else
        {
            BeginNormalPaletteFade(selectedPalettes, delay, 16, 0, fadeColor);
        }

        gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_SCREEN_FADING_IN;
        gWeatherPtr->fadeInFirstFrame = TRUE;
        gWeatherPtr->fadeInTimer = 0;
        Weather_SetBlendCoeffs(gWeatherPtr->currBlendEVA, gWeatherPtr->currBlendEVB);
        gWeatherPtr->readyForInit = TRUE;
    }
}

// fades screen using BLDY
// Note: This enables blending in all windows;
// These bits may need to be disabled later
// (i.e if blending lighting effects using WINOBJ)
void FadeScreenHardware(u32 mode, s32 delay)
{
    u32 bldCnt = GetGpuReg(REG_OFFSET_BLDCNT) & BLDCNT_TGT2_ALL;
    bldCnt |= BLDCNT_TGT1_ALL;
    // enable blend in all windows
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);

    switch (mode)
    {
    case FADE_FROM_BLACK:
        BeginHardwarePaletteFade(bldCnt | BLDCNT_EFFECT_DARKEN, delay, 16, 0, TRUE);
        break;
    case FADE_TO_BLACK:
        BeginHardwarePaletteFade(bldCnt | BLDCNT_EFFECT_DARKEN, delay, 0, 16, FALSE);
        break;
    case FADE_FROM_WHITE:
        BeginHardwarePaletteFade(bldCnt | BLDCNT_EFFECT_LIGHTEN, delay, 16, 0, TRUE);
        break;
    case FADE_TO_WHITE:
        BeginHardwarePaletteFade(bldCnt | BLDCNT_EFFECT_LIGHTEN, delay, 0, 16, FALSE);
        break;
    }
}

bool8 IsWeatherNotFadingIn(void)
{
    return (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_IN);
}

void UpdateSpritePaletteWithWeather(u8 spritePaletteIndex, bool8 allowFog)
{
    u16 paletteIndex = 16 + spritePaletteIndex;
    u16 i;

    switch (gWeatherPtr->palProcessingState)
    {
    case WEATHER_PAL_STATE_SCREEN_FADING_IN:
        if (gWeatherPtr->fadeInFirstFrame)
        {
            if (gWeatherPtr->currWeather == WEATHER_FOG_HORIZONTAL)
                MarkFogSpritePalToLighten(paletteIndex);
            paletteIndex = PLTT_ID(paletteIndex);
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteIndex + i] = gWeatherPtr->fadeDestColor;
        }
        break;
    case WEATHER_PAL_STATE_SCREEN_FADING_OUT:
        paletteIndex = PLTT_ID(paletteIndex);
        CpuFastCopy(&gPlttBufferFaded[paletteIndex], &gPlttBufferUnfaded[paletteIndex], PLTT_SIZE_4BPP);
        BlendPalette(paletteIndex, 16, gPaletteFade.y, gPaletteFade.blendColor);
        break;
    // WEATHER_PAL_STATE_CHANGING_WEATHER
    // WEATHER_PAL_STATE_CHANGING_IDLE
    default:
        if (gWeatherPtr->currWeather != WEATHER_FOG_HORIZONTAL)
        {
            if (gWeatherPtr->colorMapIndex)
                ApplyColorMap(paletteIndex, 1, gWeatherPtr->colorMapIndex);
            else
                UpdateSpritePaletteWithTime(spritePaletteIndex);
        }
        else
        {
            // In horizontal fog, only specific palettes should be fog-blended
            if (allowFog)
            {
                i = min((gTimeOfDay + 1) * 4, 12); // fog coeff, highest in day and lowest at night
                paletteIndex = PLTT_ID(paletteIndex);
                // First blend with time
                CpuFastCopy(gPlttBufferUnfaded + paletteIndex, gPlttBufferFaded + paletteIndex, PLTT_SIZE_4BPP);
                UpdateSpritePaletteWithTime(spritePaletteIndex);
                // Then blend faded->faded with fog coeff
                BlendPalettesFine(1, gPlttBufferFaded + paletteIndex, gPlttBufferFaded + paletteIndex, i, RGB(28, 31, 28));
            }
            else
            {
                // Otherwise, just time-blend the palette
                UpdateSpritePaletteWithTime(spritePaletteIndex);
            }
        }
        break;
    }
}

void ApplyWeatherColorMapToPals(u8 startPalIndex, u8 numPalettes)
{
    ApplyColorMap(startPalIndex, numPalettes, gWeatherPtr->colorMapIndex);
}

static bool8 UNUSED IsFirstFrameOfWeatherFadeIn(void)
{
    if (gWeatherPtr->palProcessingState == WEATHER_PAL_STATE_SCREEN_FADING_IN)
        return gWeatherPtr->fadeInFirstFrame;
    else
        return FALSE;
}

void LoadCustomWeatherSpritePalette(const u16 *palette)
{
    if (gWeatherPtr->weatherPicSpritePalIndex > 16 // haven't allocated palette yet
    && (gWeatherPtr->weatherPicSpritePalIndex = AllocSpritePalette(PALTAG_WEATHER_2)) > 16)
        return;
    LoadPalette(palette, OBJ_PLTT_ID(gWeatherPtr->weatherPicSpritePalIndex), PLTT_SIZE_4BPP);
    UpdateSpritePaletteWithWeather(gWeatherPtr->weatherPicSpritePalIndex, TRUE);
}

static void LoadDroughtWeatherPalette(u8 *palsIndex, u8 *palsOffset)
{
    *palsIndex = 0x20;
    *palsOffset = 0x20;
}

void ResetDroughtWeatherPaletteLoading(void)
{
    gWeatherPtr->loadDroughtPalsIndex = 1;
    gWeatherPtr->loadDroughtPalsOffset = 1;
}

bool8 LoadDroughtWeatherPalettes(void)
{
    if (gWeatherPtr->loadDroughtPalsIndex < 32)
    {
        LoadDroughtWeatherPalette(&gWeatherPtr->loadDroughtPalsIndex, &gWeatherPtr->loadDroughtPalsOffset);
        if (gWeatherPtr->loadDroughtPalsIndex < 32)
            return TRUE;
    }
    return FALSE;
}

static void SetDroughtColorMap(s8 colorMapIndex)
{
    ApplyWeatherColorMapIfIdle(-colorMapIndex - 1);
}

void DroughtStateInit(void)
{
    gWeatherPtr->droughtBrightnessStage = 0;
    gWeatherPtr->droughtTimer = 0;
    gWeatherPtr->droughtState = 0;
    gWeatherPtr->droughtLastBrightnessStage = 0;
}

void DroughtStateRun(void)
{
    switch (gWeatherPtr->droughtState)
    {
    case 0:
        if (++gWeatherPtr->droughtTimer > 5)
        {
            gWeatherPtr->droughtTimer = 0;
            SetDroughtColorMap(gWeatherPtr->droughtBrightnessStage++);
            if (gWeatherPtr->droughtBrightnessStage > 5)
            {
                gWeatherPtr->droughtLastBrightnessStage = gWeatherPtr->droughtBrightnessStage;
                gWeatherPtr->droughtState = 1;
                gWeatherPtr->droughtTimer = 60;
            }
        }
        break;
    case 1:
        gWeatherPtr->droughtTimer = (gWeatherPtr->droughtTimer + 3) & 0x7F;
        gWeatherPtr->droughtBrightnessStage = ((gSineTable[gWeatherPtr->droughtTimer] - 1) >> 6) + 2;
        if (gWeatherPtr->droughtBrightnessStage != gWeatherPtr->droughtLastBrightnessStage)
            SetDroughtColorMap(gWeatherPtr->droughtBrightnessStage);
        gWeatherPtr->droughtLastBrightnessStage = gWeatherPtr->droughtBrightnessStage;
        break;
    case 2:
        if (++gWeatherPtr->droughtTimer > 5)
        {
            gWeatherPtr->droughtTimer = 0;
            SetDroughtColorMap(--gWeatherPtr->droughtBrightnessStage);
            if (gWeatherPtr->droughtBrightnessStage == 3)
                gWeatherPtr->droughtState = 0;
        }
        break;
    }
}

void Weather_SetBlendCoeffs(u8 eva, u8 evb)
{
    gWeatherPtr->currBlendEVA = eva;
    gWeatherPtr->currBlendEVB = evb;
    gWeatherPtr->targetBlendEVA = eva;
    gWeatherPtr->targetBlendEVB = evb;

    // don't update BLDALPHA if a hardware fade is on-screen
    if ((GetGpuReg(REG_OFFSET_BLDCNT) & BLDCNT_EFFECT_EFF_MASK) < BLDCNT_EFFECT_LIGHTEN)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(eva, evb));
}

void Weather_SetTargetBlendCoeffs(u8 eva, u8 evb, int delay)
{
    gWeatherPtr->targetBlendEVA = eva;
    gWeatherPtr->targetBlendEVB = evb;
    gWeatherPtr->blendDelay = delay;
    gWeatherPtr->blendFrameCounter = 0;
    gWeatherPtr->blendUpdateCounter = 0;
}

bool8 Weather_UpdateBlend(void)
{
    if (gWeatherPtr->currBlendEVA == gWeatherPtr->targetBlendEVA
     && gWeatherPtr->currBlendEVB == gWeatherPtr->targetBlendEVB)
        return TRUE;

    if (++gWeatherPtr->blendFrameCounter > gWeatherPtr->blendDelay)
    {
        gWeatherPtr->blendFrameCounter = 0;
        gWeatherPtr->blendUpdateCounter++;

        // Update currBlendEVA and currBlendEVB on alternate frames
        if (gWeatherPtr->blendUpdateCounter & 1)
        {
            if (gWeatherPtr->currBlendEVA < gWeatherPtr->targetBlendEVA)
                gWeatherPtr->currBlendEVA++;
            else if (gWeatherPtr->currBlendEVA > gWeatherPtr->targetBlendEVA)
                gWeatherPtr->currBlendEVA--;
        }
        else
        {
            if (gWeatherPtr->currBlendEVB < gWeatherPtr->targetBlendEVB)
                gWeatherPtr->currBlendEVB++;
            else if (gWeatherPtr->currBlendEVB > gWeatherPtr->targetBlendEVB)
                gWeatherPtr->currBlendEVB--;
        }
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gWeatherPtr->currBlendEVA, gWeatherPtr->currBlendEVB));

    if (gWeatherPtr->currBlendEVA == gWeatherPtr->targetBlendEVA
     && gWeatherPtr->currBlendEVB == gWeatherPtr->targetBlendEVB)
        return TRUE;

    return FALSE;
}

// Uses the same numbering scheme as the coord events
static void UNUSED SetFieldWeather(u8 weather)
{
    switch (weather)
    {
    case COORD_EVENT_WEATHER_SUNNY_CLOUDS:
        SetWeather(WEATHER_SUNNY_CLOUDS);
        break;
    case COORD_EVENT_WEATHER_SUNNY:
        SetWeather(WEATHER_SUNNY);
        break;
    case COORD_EVENT_WEATHER_RAIN:
        SetWeather(WEATHER_RAIN);
        break;
    case COORD_EVENT_WEATHER_SNOW:
        SetWeather(WEATHER_SNOW);
        break;
    case COORD_EVENT_WEATHER_RAIN_THUNDERSTORM:
        SetWeather(WEATHER_RAIN_THUNDERSTORM);
        break;
    case COORD_EVENT_WEATHER_FOG_HORIZONTAL:
        SetWeather(WEATHER_FOG_HORIZONTAL);
        break;
    case COORD_EVENT_WEATHER_FOG_DIAGONAL:
        SetWeather(WEATHER_FOG_DIAGONAL);
        break;
    case COORD_EVENT_WEATHER_VOLCANIC_ASH:
        SetWeather(WEATHER_VOLCANIC_ASH);
        break;
    case COORD_EVENT_WEATHER_SANDSTORM:
        SetWeather(WEATHER_SANDSTORM);
        break;
    case COORD_EVENT_WEATHER_SHADE:
        SetWeather(WEATHER_SHADE);
        break;
    }
}

u8 GetCurrentWeather(void)
{
    return gWeatherPtr->currWeather;
}

void SetRainStrengthFromSoundEffect(u16 soundEffect)
{
    if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_SCREEN_FADING_OUT)
    {
        switch (soundEffect)
        {
        case SE_RAIN:
            gWeatherPtr->rainStrength = 0;
            break;
        case SE_DOWNPOUR:
            gWeatherPtr->rainStrength = 1;
            break;
        case SE_THUNDERSTORM:
            gWeatherPtr->rainStrength = 2;
            break;
        default:
            return;
        }

        PlaySE(soundEffect);
    }
}

void PlayRainStoppingSoundEffect(void)
{
    if (IsSpecialSEPlaying())
    {
        switch (gWeatherPtr->rainStrength)
        {
        case 0:
            PlaySE(SE_RAIN_STOP);
            break;
        case 1:
            PlaySE(SE_DOWNPOUR_STOP);
            break;
        case 2:
        default:
            PlaySE(SE_THUNDERSTORM_STOP);
            break;
        }
    }
}

u8 IsWeatherChangeComplete(void)
{
    return gWeatherPtr->weatherChangeComplete;
}

void SetWeatherScreenFadeOut(void)
{
    gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_SCREEN_FADING_OUT;
}

void SetWeatherPalStateIdle(void)
{
    gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
}

const u8 *SetPaletteColorMapType(u8 paletteIndex, enum ColorMapType colorMapType)
{
    if (sPaletteColorMapTypes[paletteIndex] == colorMapType)
        return sPaletteColorMapTypes;
    // setup field effect color map
    if (sPaletteColorMapTypes != sFieldEffectPaletteColorMapTypes)
    {
        CpuCopy16(sBasePaletteColorMapTypes, sFieldEffectPaletteColorMapTypes, 32);
        sPaletteColorMapTypes = sFieldEffectPaletteColorMapTypes;
    }
    sFieldEffectPaletteColorMapTypes[paletteIndex] = colorMapType;
    return sPaletteColorMapTypes;
}

void PreservePaletteInWeather(u8 preservedPalIndex)
{
    SetPaletteColorMapType(preservedPalIndex, COLOR_MAP_NONE);
}

void ResetPaletteColorMapType(u8 paletteIndex)
{
    if (sPaletteColorMapTypes != sBasePaletteColorMapTypes)
        sFieldEffectPaletteColorMapTypes[paletteIndex] = sBasePaletteColorMapTypes[paletteIndex];
}

void ResetPreservedPalettesInWeather(void)
{
    sPaletteColorMapTypes = sBasePaletteColorMapTypes;
}

bool32 IsWeatherAlphaBlend(void)
{
    return (gWeatherPtr->currWeather == WEATHER_FOG_HORIZONTAL
         || gWeatherPtr->currWeather == WEATHER_FOG_DIAGONAL
         || gWeatherPtr->currWeather == WEATHER_UNDERWATER_BUBBLES
         || gWeatherPtr->currWeather == WEATHER_UNDERWATER);
}

static const u8 sWeatherNames[WEATHER_COUNT][24] = {
    [WEATHER_NONE]               = _("NONE"),
    [WEATHER_SUNNY_CLOUDS]       = _("SUNNY CLOUDS"),
    [WEATHER_SUNNY]              = _("SUNNY"),
    [WEATHER_RAIN]               = _("RAIN"),
    [WEATHER_SNOW]               = _("SNOW"),
    [WEATHER_RAIN_THUNDERSTORM]  = _("RAIN THUNDERSTORM"),
    [WEATHER_FOG_HORIZONTAL]     = _("FOG HORIZONTAL"),
    [WEATHER_VOLCANIC_ASH]       = _("VOLCANIC ASH"),
    [WEATHER_SANDSTORM]          = _("SANDSTORM"),
    [WEATHER_FOG_DIAGONAL]       = _("FOG DIAGONAL"),
    [WEATHER_UNDERWATER]         = _("UNDERWATER"),
    [WEATHER_SHADE]              = _("SHADE"),
    [WEATHER_DROUGHT]            = _("DROUGHT"),
    [WEATHER_DOWNPOUR]           = _("DOWNPOUR"),
    [WEATHER_UNDERWATER_BUBBLES] = _("UNDERWATER BUBBLES"),
    [WEATHER_ABNORMAL]           = _("ABNORMAL(NOT WORKING)"),
    [WEATHER_ROUTE119_CYCLE]     = _("ROUTE119 CYCLE"),
    [WEATHER_ROUTE123_CYCLE]     = _("ROUTE123 CYCLE"),
    [WEATHER_FOG]                = _("FOG"),
};

static const u8 sDebugText_WeatherNotDefined[] = _("NOT DEFINED!!!");
const u8 *GetWeatherName(u32 weatherId)
{
    if (sWeatherNames[weatherId][0] != 0)
        return sWeatherNames[weatherId];
    return sDebugText_WeatherNotDefined;
}
