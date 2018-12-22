#ifndef GUARD_WEATHER_H
#define GUARD_WEATHER_H

#include "sprite.h"

// Controls how the weather should be changing the screen palettes.
enum
{
    WEATHER_PAL_STATE_CHANGING_WEATHER,
    WEATHER_PAL_STATE_SCREEN_FADING_IN,
    WEATHER_PAL_STATE_SCREEN_FADING_OUT,
    WEATHER_PAL_STATE_IDLE,
};

// For the FadeScreen function.
enum
{
    FADE_FROM_BLACK,
    FADE_TO_BLACK,
    FADE_FROM_WHITE,
    FADE_TO_WHITE,
};

struct Weather
{
    union
    {
        struct
        {
            struct Sprite *rainSprites[24];
            struct Sprite *snowflakeSprites[101];
            struct Sprite *cloudSprites[3];
        } s1;
        struct
        {
            u8 filler0[0xA0];
            struct Sprite *fog1Sprites[20];
            struct Sprite *ashSprites[20];
            struct Sprite *fog2Sprites[20];
            struct Sprite *sandstormSprites1[20];
            struct Sprite *sandstormSprites2[5];
        } s2;
    } sprites;
    u8 gammaShifts[19][32];
    u8 altGammaShifts[19][32];
    s8 gammaIndex;
    s8 gammaTargetIndex;
    u8 gammaStepDelay;
    u8 gammaStepFrameCounter;
    u16 fadeDestColor;
    /*0x6C6*/ u8 palProcessingState;
    /*0x6C7*/ u8 fadeScreenCounter;
    /*0x6C8*/ bool8 readyForInit;
    /*0x6C9*/ u8 taskId;
    /*0x6CA*/ u8 unknown_6CA;
    u8 unknown_6CB;
    u16 initStep;
    u16 finishStep;
    u8 currWeather;
    u8 nextWeather;
    u8 weatherGfxLoaded;
    bool8 weatherChangeComplete;
    u8 weatherPicSpritePalIndex;
    u8 altGammaSpritePalIndex;
    u16 unknown_6D6;
    u8 unknown_6D8;
    u8 unknown_6D9;
    u8 rainSpriteCount;
    u8 unknown_6DB;
    u8 unknown_6DC;
    u8 rainStrength;
    /*0x6DE*/ u8 cloudSpritesCreated;
    u8 filler_6DF[1];
    u16 unknown_6E0;
    u16 unknown_6E2;
    u8 snowflakeSpriteCount;
    u8 unknown_6E5;
    u16 unknown_6E6;
    u16 thunderCounter;
    u8 unknown_6EA;
    u8 unknown_6EB;
    u8 unknown_6EC;
    u8 unknown_6ED;
    u16 fog1ScrollPosX;
    u16 unknown_6F0;
    u16 unknown_6F2;
    u8 lightenedFogSpritePals[6];
    u8 lightenedFogSpritePalsCount;
    u8 fog1SpritesCreated;
    u16 unknown_6FC;
    u16 unknown_6FE;
    u8 ashSpritesCreated;
    u8 filler_701[3];
    u32 unknown_704;
    u32 unknown_708;
    u8 filler_70C[2];
    u16 unknown_70E;
    u16 unknown_710;
    u16 unknown_712;
    u16 unknown_714;
    u8 sandstormSprites1Created;
    u8 sandstormSprites2Created;
    u16 unknown_718;
    u16 unknown_71A;
    u16 unknown_71C;
    u16 unknown_71E;
    u16 unknown_720;
    u16 unknown_722;
    u8 fog2SpritesCreated;
    u8 filler_725[1];
    u16 unknown_726;
    u16 unknown_728;
    u16 unknown_72A;
    u16 unknown_72C;
    u8 unknown_72E;
    u8 filler_72F;
    u16 currBlendEVA;
    u16 currBlendEVB;
    u16 targetBlendEVA;
    u16 targetBlendEVB;
    u8 blendUpdateCounter;
    u8 blendFrameCounter;
    u8 blendDelay;
    u8 filler_73B[0x3C-0x3B];
    s16 unknown_73C;
    s16 unknown_73E;
    s16 unknown_740;
    s16 unknown_742;
    u8 filler_744[0xD-4];
    s8 loadDroughtPalsIndex;
    u8 loadDroughtPalsOffset;
};

// field_weather.c
extern struct Weather gWeather;
extern struct Weather *const gWeatherPtr;
extern const u16 gUnknown_083970E8[];

// field_weather_effect.c
extern const u8 gWeatherFog1Tiles[];

void StartWeather(void);
void ChangeWeather(u8 weather);
void sub_80AB104(u8 weather);
void sub_80AB130(u8 weather);
void sub_80ABC48(s8 gammaIndex);
void sub_80ABC7C(u8 gammaIndex, u8 gammaTargetIndex, u8 gammaStepDelay);
void FadeScreen(u8 mode, s8 delay);
bool8 IsWeatherNotFadingIn(void);
void UpdateSpritePaletteWithWeather(u8 spritePaletteIndex);
void ApplyWeatherGammaShiftToPal(u8 paletteIndex);
u8 sub_80ABF20(void);
void LoadCustomWeatherSpritePalette(const u16 *palette);
void ResetDroughtWeatherPaletteLoading(void);
bool8 LoadDroughtWeatherPalettes(void);
void sub_80ABFE0(s8 gammaIndex);
void sub_80ABFF0(void);
void sub_80AC01C(void);
void Weather_SetBlendCoeffs(u8 eva, u8 evb);
void Weather_SetTargetBlendCoeffs(u8 eva, u8 evb, int delay);
bool8 Weather_UpdateBlend(void);
void sub_80AC274(u8 a);
u8 GetCurrentWeather(void);
void SetRainStrengthFromSoundEffect(u16 soundEffect);
void PlayRainSoundEffect(void);
u8 IsWeatherChangeComplete(void);
void SetWeatherScreenFadeOut(void);
void sub_80AC3E4(void);
void PreservePaletteInWeather(u8 preservedPalIndex);
void ResetPreservedPalettesInWeather(void);

// field_weather_effect.c
void Clouds_InitVars(void);
void Clouds_Main(void);
void Clouds_InitAll(void);
bool8 Clouds_Finish(void);
void Weather2_InitVars(void);
void Weather2_Main(void);
void Weather2_InitAll(void);
bool8 Weather2_Finish(void);
void LightRain_InitVars(void);
void LightRain_Main(void);
void LightRain_InitAll(void);
bool8 LightRain_Finish(void);
void Snow_InitVars(void);
void Snow_Main(void);
void Snow_InitAll(void);
bool8 Snow_Finish(void);
void MedRain_InitVars(void);
void Rain_Main(void);
void MedRain_InitAll(void);
bool8 Rain_Finish(void);
void Fog1_InitVars(void);
void Fog1_Main(void);
void Fog1_InitAll(void);
bool8 Fog1_Finish(void);
void Ash_InitVars(void);
void Ash_Main(void);
void Ash_InitAll(void);
bool8 Ash_Finish(void);
void Sandstorm_InitVars(void);
void Sandstorm_Main(void);
void Sandstorm_InitAll(void);
bool8 Sandstorm_Finish(void);
void Fog2_InitVars(void);
void Fog2_Main(void);
void Fog2_InitAll(void);
bool8 Fog2_Finish(void);
void Fog1_InitVars(void);
void Fog1_Main(void);
void Fog1_InitAll(void);
bool8 Fog1_Finish(void);
void Shade_InitVars(void);
void Shade_Main(void);
void Shade_InitAll(void);
bool8 Shade_Finish(void);
void Drought_InitVars(void);
void Drought_Main(void);
void Drought_InitAll(void);
bool8 Drought_Finish(void);
void HeavyRain_InitVars(void);
void Rain_Main(void);
void HeavyRain_InitAll(void);
bool8 Rain_Finish(void);
void Bubbles_InitVars(void);
void Bubbles_Main(void);
void Bubbles_InitAll(void);
bool8 Bubbles_Finish(void);

u8 GetSav1Weather(void);
void SetSav1Weather(u32 weather);
void SetSav1WeatherFromCurrMapHeader(void);
void SetWeather(u32 weather);
void DoCurrentWeather(void);
void UpdateWeatherPerDay(u16 increment);

#endif // GUARD_WEATHER_H
