#include "global.h"
#include "malloc.h"
#include "main.h"
#include "task.h"
#include "palette.h"
#include "overworld.h"
#include "field_weather.h"
#include "pokemon_storage_system.h"
#include "pokenav.h"

// static types

struct PokenavStruct_203CF40 {
    int unk_00;
    int unk_04;
    bool16 unk_08;
    bool32 anyMonsHaveRibbons;
    void *unk_10[19];
}; // size=0x5c

// static declarations

EWRAM_DATA struct PokenavStruct_203CF40 *gUnknown_0203CF40 = NULL;

static void sub_81C72BC(void);
static void sub_81C7360(struct PokenavStruct_203CF40 *data);
static bool32 sub_81C7388(void);
void sub_81C7400(void);
void sub_81C7418(void);
void sub_81C742C(u8 taskId);
void sub_81C7650(int i);

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
        sub_81C7360(gUnknown_0203CF40);
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

static void sub_81C72BC(void)
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
            sub_81C7360(gUnknown_0203CF40);
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

void sub_81C7334(void)
{
    int i;

    for (i = 0; i < 19; i++)
    {
        sub_81C7650(i);
    }
    free(gUnknown_0203CF40);
    gUnknown_0203CF40 = NULL;
    InitKeys();
}

static void sub_81C7360(struct PokenavStruct_203CF40 *data)
{
    int i;

    for (i = 0; i < 19; i++)
    {
        data->unk_10[i] = NULL;
    }
    data->unk_08 = FALSE;
    data->unk_04 = 0;
    data->anyMonsHaveRibbons = sub_81C7388();
    data->unk_00 = 0;
}

static bool32 sub_81C7388(void)
{
    int i;
    int j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_BIT2) && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_BIT3) && GetMonData(&gPlayerParty[i], MON_DATA_RIBBON_COUNT) != 0)
        {
            return TRUE;
        }
    }
    for (j = 0; j < 14; j++)
    {
        for (i = 0; i < 30; i++)
        {
            if (sub_80D2270(j, i) && GetBoxMonDataFromAnyBox(j, i, MON_DATA_RIBBON_COUNT) != 0)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}
