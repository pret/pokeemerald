#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "palette.h"
#include "party_menu.h"
#include "rom6.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "wild_encounter.h"
#include "constants/field_effects.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void FieldCallback_SweetScent(void);
static void StartSweetScentFieldEffect(void);
static void TrySweetScentEncounter(u8 taskId);
static void FailSweetScentEncounter(u8 taskId);
void sub_81BE6B8(void);
void sub_81BE72C(void);

bool8 SetUpFieldMove_SweetScent(void)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_SweetScent;
    return TRUE;
}

static void FieldCallback_SweetScent(void)
{
    FieldEffectStart(FLDEFF_SWEET_SCENT);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_SweetScent(void)
{
    u8 taskId;

    SetWeatherScreenFadeOut();
    taskId = oei_task_add();
    gTasks[taskId].data[8] = (u32)StartSweetScentFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSweetScentFieldEffect;
    return FALSE;
}

static void StartSweetScentFieldEffect(void)
{
    u8 taskId;

    PlaySE(SE_W230);
    CpuFastSet(gPlttBufferUnfaded, gPaletteDecompressionBuffer, 0x100);
    CpuFastSet(gPlttBufferFaded, gPlttBufferUnfaded, 0x100);
    BeginNormalPaletteFade(~(1 << (gSprites[GetPlayerAvatarObjectId()].oam.paletteNum + 16)), 4, 0, 8, RGB_RED);
    taskId = CreateTask(TrySweetScentEncounter, 0);
    gTasks[taskId].data[0] = 0;
    FieldEffectActiveListRemove(FLDEFF_SWEET_SCENT);
}

static void TrySweetScentEncounter(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_81BE72C();
        BlendPalettes(0x00000040, 8, RGB_RED);
        if (gTasks[taskId].data[0] == 64)
        {
            gTasks[taskId].data[0] = 0;
            if (SweetScentWildEncounter() == TRUE)
            {
                DestroyTask(taskId);
            }
            else
            {
                gTasks[taskId].func = FailSweetScentEncounter;
                BeginNormalPaletteFade(~(1 << (gSprites[GetPlayerAvatarObjectId()].oam.paletteNum + 16)), 4, 8, 0, RGB_RED);
                sub_81BE6B8();
            }
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
    }
}

static void FailSweetScentEncounter(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CpuFastSet(gPaletteDecompressionBuffer, gPlttBufferUnfaded, 0x100);
        sub_80AC3E4();
        ScriptContext1_SetupScript(EventScript_290CAE);
        DestroyTask(taskId);
    }
}
