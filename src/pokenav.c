#include "global.h"
#include "malloc.h"
#include "main.h"
#include "task.h"
#include "palette.h"
#include "overworld.h"
#include "field_weather.h"
#include "songs.h"
#include "sound.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "window.h"
#include "pokenav.h"

// static types

struct PokenavStruct_203CF40 {
    unsigned (*unk_00)(void);
    int unk_04;
    bool16 unk_08;
    u16 unk_0a;
    bool32 anyMonsHaveRibbons;
    void *unk_10[19];
}; // size=0x5c

struct PokenavStruct_81C76C4 {
    u8 filler_000[12];
    unsigned unk_00c;
    u8 filler_010[0x81c];
};

// static declarations

EWRAM_DATA struct PokenavStruct_203CF40 *gUnknown_0203CF40 = NULL;

static void sub_81C72BC(void);
static void sub_81C7360(struct PokenavStruct_203CF40 *data);
static bool32 sub_81C7388(void);
static void sub_81C7400(void);
void sub_81C7418(void);
static void sub_81C742C(u8 taskId);
bool32 sub_81C756C(unsigned a0);
bool32 sub_81C75D4(void);
unsigned sub_81C75E0(void);
void sub_81C75F4(void);
void sub_81C7650(int i);
bool32 sub_81C76C4(void);
bool32 sub_81C76FC(void);
void sub_81C7710(void);
bool32 sub_81C7738(void);
int sub_81C7764(int a0);
void sub_81C7834(u32 (*a0)(void), u32 (*a1)(void));
void sub_81C7850(unsigned a0);
bool32 sub_81C786C(void);
void sub_81C7C94(void);
bool32 sub_81C9298(void);
bool32 sub_81C92CC(void);
bool32 sub_81C9304(void);
bool32 sub_81C9338(void);
bool32 sub_81C9368(void);
bool32 sub_81C941C(void);
bool32 sub_81C9924(void);
void sub_81C9430(void);
bool32 sub_81C9940(void);
bool32 sub_81C9990(void);
bool32 sub_81C99C0(void);
void sub_81C99D4(void);
void sub_81CAADC(void);
bool32 sub_81CAAE8(void);
bool32 sub_81CAB24(void);
void sub_81CAB38(void);
bool32 sub_81CB260(void);
bool32 sub_81CB29C(void);
bool32 sub_81CB2CC(void);
void sub_81CB2E0(void);
bool32 sub_81CC4D4(void);
void sub_81CC524(void);
bool32 sub_81CC554(void);
bool32 sub_81CC5F4(void);
bool32 sub_81CC62C(void);
bool32 sub_81CC65C(void);
void sub_81CC670(void);
bool32 sub_81CCFD8(void);
bool32 sub_81CD024(void);
bool32 sub_81CD070(void);
void sub_81CD1C0(void);
bool32 sub_81CDDD4(void);
bool32 sub_81CDE2C(void);
bool32 sub_81CDE64(void);
void sub_81CECA0(void);
bool32 sub_81CEF3C(void);
bool32 sub_81CEF98(void);
bool32 sub_81CEFDC(void);
void sub_81CEFF0(void);
bool32 sub_81CF330(void);
bool32 sub_81CF368(void);
bool32 sub_81CF3A0(void);
bool32 sub_81CF3D0(void);
void sub_81CF3F8(void);
bool32 sub_81CF9BC(void);
bool32 sub_81CFA04(void);
bool32 sub_81CFA34(void);
void sub_81CFA48(void);
bool32 sub_81CFDD0(void);
bool32 sub_81CFE08(void);
bool32 sub_81CFE40(void);
bool32 sub_81CFE70(void);
void sub_81CFE98(void);
bool32 sub_81D0450(void);
bool32 sub_81D04A0(void);
void sub_81D04B8(void);
bool32 sub_81D0978(void);
bool32 sub_81D09B0(void);
bool32 sub_81D09E0(void);
void sub_81D09F4(void);

// rodata

const struct {
    bool32 (*unk_00)(void);
    unsigned (*unk_04)(void);
    bool32 (*unk_08)(void);
    u32 (*unk_0c)(void);
    u32 (*unk_10)(void);
    void (*unk_14)(void);
    void (*unk_18)(void);
} gUnknown_0861F3EC[] = {
    {sub_81C9298, sub_81C941C, sub_81C9924, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81C9298, sub_81C941C, sub_81C9940, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81C9338, sub_81C941C, sub_81C9940, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81C9368, sub_81C941C, sub_81C9940, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81C92CC, sub_81C941C, sub_81C9940, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81C9304, sub_81C941C, sub_81C9940, sub_81C9990, sub_81C99C0, sub_81C9430, sub_81C99D4},
    {sub_81CC4D4, sub_81CC554, sub_81CC5F4, sub_81CC62C, sub_81CC65C, sub_81CC524, sub_81CC670},
    {sub_81CCFD8, sub_81CD070, sub_81CDDD4, sub_81CDE2C, sub_81CDE64, sub_81CD1C0, sub_81CECA0},
    {sub_81CEF3C, sub_81CEFDC, sub_81CF330, sub_81CF3A0, sub_81CF3D0, sub_81CEFF0, sub_81CF3F8},
    {sub_81CD024, sub_81CD070, sub_81CDDD4, sub_81CDE2C, sub_81CDE64, sub_81CD1C0, sub_81CECA0},
    {sub_81CEF98, sub_81CEFDC, sub_81CF368, sub_81CF3A0, sub_81CF3D0, sub_81CEFF0, sub_81CF3F8},
    {sub_81CAAE8, sub_81CAB24, sub_81CB260, sub_81CB29C, sub_81CB2CC, sub_81CAB38, sub_81CB2E0},
    {sub_81CF9BC, sub_81CFA34, sub_81CFDD0, sub_81CFE40, sub_81CFE70, sub_81CFA48, sub_81CFE98},
    {sub_81D0450, sub_81D04A0, sub_81D0978, sub_81D09B0, sub_81D09E0, sub_81D04B8, sub_81D09F4},
    {sub_81CFA04, sub_81CFA34, sub_81CFE08, sub_81CFE40, sub_81CFE70, sub_81CFA48, sub_81CFE98}
};

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
    data->unk_00 = NULL;
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

static void sub_81C7400(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_81C7418(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_81C742C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    unsigned value;

    switch (data[0])
    {
        case 0:
            sub_81C76C4();
            data[0] = 1;
            break;
        case 1:
            if (!sub_81C76FC())
            {
                sub_81C756C(100000);
                data[0] = 4;
            }
            break;
        case 2:
            if (sub_81C786C())
            {
                break;
            }
            data[0] = 3;
            // fallthrough
        case 3:
            value = sub_81C75E0();
            if (value == -1u)
            {
                sub_81C7710();
                data[0] = 5;
            }
            else if (value >= 100000)
            {
                gUnknown_0861F3EC[gUnknown_0203CF40->unk_04].unk_18();
                gUnknown_0861F3EC[gUnknown_0203CF40->unk_04].unk_14();
                if (sub_81C756C(value))
                {
                    data[0] = 4;
                }
                else
                {
                    sub_81C7710();
                    data[0] = 5;
                }
            }
            else if (value != 0)
            {
                sub_81C7850(value);
                if (sub_81C786C()) {
                    data[0] = 2;
                }
            }
            break;
        case 4:
            if (!sub_81C75D4())
            {
                data[0] = 3;
            }
            break;
        case 5:
            if (!sub_81C7738())
            {
                bool32 flag = gUnknown_0203CF40->unk_08 ? TRUE : FALSE;
                sub_81C9430();
                sub_81C7334();
                if (flag)
                {
                    SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
                }
                else
                {
                    SetMainCallback2(sub_8086194);
                }
            }
            break;
    }
}

bool32 sub_81C756C(unsigned a0)
{
    unsigned v0 = a0 - 100000;
    sub_81C75F4();
    if (gUnknown_0861F3EC[v0].unk_00() && gUnknown_0861F3EC[v0].unk_08())
    {
        sub_81C7834(gUnknown_0861F3EC[v0].unk_0c, gUnknown_0861F3EC[v0].unk_10);
        gUnknown_0203CF40->unk_00 = gUnknown_0861F3EC[v0].unk_04;
        gUnknown_0203CF40->unk_04 = v0;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_81C75D4(void)
{
    return sub_81C786C();
}

unsigned sub_81C75E0(void)
{
    return gUnknown_0203CF40->unk_00();
}

void sub_81C75F4(void)
{
    InitKeys();
}

void c3args_set_0toR1_1to0(void (*callback)(void))
{
    SetVBlankCallback(callback);
}

void sub_81C760C(void)
{
    SetVBlankCallback(sub_81C7418);
}

void *sub_81C761C(int i, size_t size)
{
    gUnknown_0203CF40->unk_10[i] = malloc(size);
    return gUnknown_0203CF40->unk_10[i];
}

struct PokenavStruct_81C76C4 *sub_81C763C(int i)
{
    return gUnknown_0203CF40->unk_10[i];
}

void sub_81C7650(int i)
{
    if (gUnknown_0203CF40->unk_10[i] != NULL)
    {
        free(gUnknown_0203CF40->unk_10[i]);
        gUnknown_0203CF40->unk_10[i] = NULL;
    }
}

bool16 sub_81C767C(void)
{
    return gUnknown_0203CF40->unk_08;
}

void sub_81C7688(bool16 flag)
{
    gUnknown_0203CF40->unk_08 = flag;
}

void sub_81C7694(unsigned a0)
{
    if (a0 > 4)
    {
        a0 = 0;
    }
    gUnknown_0203CF40->unk_0a = a0;
}

u16 sub_81C76AC(void)
{
    return gUnknown_0203CF40->unk_0a;
}
bool32 sub_81C76B8(void)
{
    return gUnknown_0203CF40->anyMonsHaveRibbons;
}

bool32 sub_81C76C4(void)
{
    struct PokenavStruct_81C76C4 *v0 = sub_81C761C(0, sizeof(struct PokenavStruct_81C76C4));
    if (v0 == NULL)
    {
        return FALSE;
    }
    ResetSpriteData();
    FreeAllSpritePalettes();
    v0->unk_00c = sub_81C7078(sub_81C7764, 1);
    return TRUE;
}

u32 sub_81C76FC(void)
{
    return sub_81C70D8(sub_81C763C(0)->unk_00c);
}

void sub_81C7710(void)
{
    PlaySE(SE_PN_OFF);
    sub_81CAADC();
    BeginNormalPaletteFade(-1, -1, 0, 16, 0);
}

bool32 sub_81C7738(void)
{
    if (!gPaletteFade.active)
    {
        sub_81C99D4();
        sub_81C7C94();
        FreeAllWindowBuffers();
        return FALSE;
    }
    return TRUE;
}
