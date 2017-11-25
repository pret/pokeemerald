#include "global.h"
#include "malloc.h"
#include "main.h"
#include "task.h"
#include "palette.h"
#include "overworld.h"
#include "field_weather.h"
#include "pokenav.h"

// static types

struct PokenavStruct_203CF40 {
    u8 filler_00[8];
    bool16 unk_08;
    u8 filler_0a[0x52];
}; // size=0x5c

// static declarations

EWRAM_DATA struct PokenavStruct_203CF40 *gUnknown_0203CF40 = NULL;

void sub_81C72BC(void);
void sub_81C7360(void);
void sub_81C7400(void);
void sub_81C7418(void);
void sub_81C742C(u8 taskId);

// rodata

// text

void CB2_PokeNav(void)
{
    gUnknown_0203CF40 = malloc(sizeof(struct PokenavStruct_203CF40));
    if (gUnknown_0203CF40 == NULL)
    {
        SetMainCallback2(sub_8086194);
    }
    else
    {
        sub_81C7360();
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(sub_81C7400);
        SetVBlankCallback(sub_81C7418);
    }
}

void sub_81C72A4(void)
{
    SetMainCallback2(sub_81C72BC);
    fade_screen(1, 0);
}

void sub_81C72BC(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        gUnknown_0203CF40 = malloc(sizeof(struct PokenavStruct_203CF40));
        if (gUnknown_0203CF40 == NULL)
        {
            SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        }
        else
        {
            sub_81C7360();
            gUnknown_0203CF40->unk_08 = TRUE;
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(NULL);
            CreateTask(sub_81C742C, 0);
            SetMainCallback2(sub_81C7400);
            SetVBlankCallback(sub_81C7418);
        }
    }
}
