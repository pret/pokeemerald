#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_weather.h"
#include "fldeff.h"
#include "palette.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/weather.h"

static void FieldCallback_Defog(void);
static void FieldMove_Defog(void);
static void EndDefogTask(u8 taskId);

bool32 SetUpFieldMove_Defog(void)
{
    if (gWeather.currWeather != WEATHER_FOG_HORIZONTAL && gWeather.currWeather != WEATHER_FOG_DIAGONAL)
        return FALSE;

    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_Defog;
    return TRUE;
}

static void FieldCallback_Defog(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseDefog);
}

bool8 FldEff_Defog(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (uintptr_t)FieldMove_Defog>> 16;
    gTasks[taskId].data[9] = (uintptr_t)FieldMove_Defog;
    return FALSE;
}

#define tFrameCount data[0]

static void FieldMove_Defog(void)
{
    PlaySE12WithPanning(SE_M_SOLAR_BEAM, SOUND_PAN_ATTACKER);
    SetWeatherScreenFadeOut();
    FieldEffectActiveListRemove(FLDEFF_DEFOG);
    SetWeather(WEATHER_NONE);
    u32 taskId = CreateTask(EndDefogTask, 0);
    gTasks[taskId].tFrameCount = 0;
};

static void EndDefogTask(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    gTasks[taskId].tFrameCount++;

    if (gTasks[taskId].tFrameCount != 120)
        return;

    gWeatherPtr->currWeather = WEATHER_NONE;
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#undef tFrameCount
