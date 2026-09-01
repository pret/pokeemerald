#include "global.h"
#include "decompress.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fldeff.h"
#include "malloc.h"
#include "mirage_tower.h"
#include "palette.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "wild_encounter.h"
#include "util.h"
#include "constants/field_effects.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void FieldCallback_SweetScent(void);
static void TrySweetScentEncounter(u8 taskId);
static void FailSweetScentEncounter(u8 taskId);

bool32 SetUpFieldMove_SweetScent(void)
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
    taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartSweetScentFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSweetScentFieldEffect;
    return FALSE;
}

#define tPalBuffer1 data[1]
#define tPalBuffer2 data[2]

void StartSweetScentFieldEffect(void)
{
    void *palBuffer;
    u32 taskId;
    u32 palettes = ~(1 << (gSprites[GetPlayerAvatarSpriteId()].oam.paletteNum + 16) | (1 << 13) | (1 << 14) | (1 << 15));

    PlaySE(SE_M_SWEET_SCENT);
    palBuffer = Alloc(PLTT_SIZE);
    CpuFastCopy(gPlttBufferUnfaded, palBuffer, PLTT_SIZE);
    CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, PLTT_SIZE);
    BeginNormalPaletteFade(palettes, 4, 0, 8, RGB_RED);
    taskId = CreateTask(TrySweetScentEncounter, 0);
    gTasks[taskId].data[0] = 0;
    StoreWordInTwoHalfwords((u16 *)&gTasks[taskId].tPalBuffer1, (u32) palBuffer);
    FieldEffectActiveListRemove(FLDEFF_SWEET_SCENT);
}

static void *GetPalBufferPtr(u32 taskId)
{
    u32 palBuffer;

    LoadWordFromTwoHalfwords((u16 *)&gTasks[taskId].tPalBuffer1, &palBuffer);
    return (void *) palBuffer;
}

static void FreeDestroyTask(u32 taskId)
{
    Free(GetPalBufferPtr(taskId));
    DestroyTask(taskId);
}

static void TrySweetScentEncounter(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ClearMirageTowerPulseBlendEffect();
        BlendPalettes(0x00000040, 8, RGB_RED);
        if (gTasks[taskId].data[0] == 64)
        {
            gTasks[taskId].data[0] = 0;
            if (SweetScentWildEncounter() == TRUE)
            {
                FreeDestroyTask(taskId);
            }
            else
            {
                gTasks[taskId].func = FailSweetScentEncounter;
                BeginNormalPaletteFade(~(1 << (gSprites[GetPlayerAvatarSpriteId()].oam.paletteNum + 16)), 4, 8, 0, RGB_RED);
                TryStartMirageTowerPulseBlendEffect();
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
        CpuFastCopy(GetPalBufferPtr(taskId), gPlttBufferUnfaded, PLTT_SIZE);
        SetWeatherPalStateIdle();
        ScriptContext_SetupScript(EventScript_FailSweetScent);
        FreeDestroyTask(taskId);
    }
}

#undef tPalBuffer1
#undef tPalBuffer2
