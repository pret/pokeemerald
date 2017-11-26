#include "global.h"
#include "malloc.h"
#include "main.h"
#include "task.h"
#include "gpu_regs.h"
#include "bg.h"
#include "window.h"
#include "menu.h"
#include "graphics.h"
#include "palette.h"
#include "overworld.h"
#include "field_weather.h"
#include "songs.h"
#include "sound.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
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
    void (*unk_000)(u32);
    u32 (*unk_004)(void);
    u32 unk_008;
    unsigned unk_00c;
    u8 filler_010[0x1c];
    u8 unk_2c[0x800];
};

// static declarations

EWRAM_DATA struct PokenavStruct_203CF40 *gUnknown_0203CF40 = NULL;

static void sub_81C72BC(void);
static void sub_81C7360(struct PokenavStruct_203CF40 *data);
static bool32 sub_81C7388(void);
static void sub_81C7400(void);
static void sub_81C7418(void);
static void sub_81C742C(u8 taskId);
static bool32 sub_81C756C(unsigned a0);
static bool32 sub_81C75D4(void);
static unsigned sub_81C75E0(void);
static void sub_81C75F4(void);
void sub_81C7650(int i);
static bool32 sub_81C76C4(void);
static u32 sub_81C76FC(void);
static void sub_81C7710(void);
static bool32 sub_81C7738(void);
static int sub_81C7764(int a0);
static void sub_81C7834(void (*func0)(u32), u32 (*func1)(void));
static void sub_81C7850(unsigned arg);
static u32 sub_81C786C(void);
static int atk47_cmd47(int a0);
static int sub_81C791C(int a0);
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
void sub_81C9990(u32 a0);
bool32 sub_81C99C0(void);
void sub_81C99D4(void);
void sub_81CAADC(void);
bool32 sub_81CAAE8(void);
bool32 sub_81CAB24(void);
void sub_81CAB38(void);
bool32 sub_81CB260(void);
void sub_81CB29C(u32);
bool32 sub_81CB2CC(void);
void sub_81CB2E0(void);
bool32 sub_81CC4D4(void);
void sub_81CC524(void);
bool32 sub_81CC554(void);
bool32 sub_81CC5F4(void);
void sub_81CC62C(u32);
bool32 sub_81CC65C(void);
void sub_81CC670(void);
bool32 sub_81CCFD8(void);
bool32 sub_81CD024(void);
bool32 sub_81CD070(void);
void sub_81CD1C0(void);
bool32 sub_81CDDD4(void);
void sub_81CDE2C(u32);
bool32 sub_81CDE64(void);
void sub_81CECA0(void);
bool32 sub_81CEF3C(void);
bool32 sub_81CEF98(void);
bool32 sub_81CEFDC(void);
void sub_81CEFF0(void);
bool32 sub_81CF330(void);
bool32 sub_81CF368(void);
void sub_81CF3A0(u32);
bool32 sub_81CF3D0(void);
void sub_81CF3F8(void);
bool32 sub_81CF9BC(void);
bool32 sub_81CFA04(void);
bool32 sub_81CFA34(void);
void sub_81CFA48(void);
bool32 sub_81CFDD0(void);
bool32 sub_81CFE08(void);
void sub_81CFE40(u32);
bool32 sub_81CFE70(void);
void sub_81CFE98(void);
bool32 sub_81D0450(void);
bool32 sub_81D04A0(void);
void sub_81D04B8(void);
bool32 sub_81D0978(void);
void sub_81D09B0(u32 a0);
bool32 sub_81D09E0(void);
void sub_81D09F4(void);
void sub_81C7944(const u16 *src, ptrdiff_t offset, size_t size);
void sub_81C7B74(void);
void sub_81C7C28(void);
void sub_81C7D28(void);

// rodata

const struct {
    bool32 (*unk_00)(void);
    unsigned (*unk_04)(void);
    bool32 (*unk_08)(void);
    void (*unk_0c)(u32);
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

extern const struct BgTemplate gUnknown_0861FA04[1];

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

static void sub_81C7418(void)
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

static bool32 sub_81C756C(unsigned a0)
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

static bool32 sub_81C75D4(void)
{
    return sub_81C786C();
}

static unsigned sub_81C75E0(void)
{
    return gUnknown_0203CF40->unk_00();
}

static void sub_81C75F4(void)
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

static bool32 sub_81C76C4(void)
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

static u32 sub_81C76FC(void)
{
    return sub_81C70D8(sub_81C763C(0)->unk_00c);
}

static void sub_81C7710(void)
{
    PlaySE(SE_PN_OFF);
    sub_81CAADC();
    BeginNormalPaletteFade(-1, -1, 0, 16, 0);
}

static bool32 sub_81C7738(void)
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

static int sub_81C7764(int a0)
{
    struct PokenavStruct_81C76C4 *ptr;
    switch (a0)
    {
        case 0:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            FreeAllWindowBuffers();
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gUnknown_0861FA04, 1);
            sub_8199D98();
            reset_temp_tile_data_buffers();
            return 1;
        case 1:
            ptr = sub_81C763C(0);
            decompress_and_copy_tile_data_to_vram(0, gUnknown_08DC7B80, 0, 0, 0);
            SetBgTilemapBuffer(0, ptr->unk_2c);
            CopyToBgTilemapBuffer(0, gUnknown_08DC7D84, 0, 0);
            sub_81C7944(gUnknown_08DC7B60, 0x00, 0x20);
            CopyBgTilemapBufferToVram(0);
            return 0;
        case 2:
            if (free_temp_tile_data_buffers_if_possible())
            {
                return 2;
            }
            sub_81C7B74();
            return 0;
        case 3:
            if (IsDma3ManagerBusyWithBgCopy())
            {
                return 2;
            }
            sub_81C7C28();
            sub_81C7D28();
            ShowBg(0);
            return 4;
        default:
            return 4;
    }
}

static void sub_81C7834(void (*func0)(u32), u32 (*func1)(void))
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    ptr->unk_000 = func0;
    ptr->unk_004 = func1;
    ptr->unk_008 = 0;
}

static void sub_81C7850(u32 arg)
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    ptr->unk_008 = 0;
    ptr->unk_000(arg);
}

static u32 sub_81C786C(void)
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    return ptr->unk_004();
}

void sub_81C7880(void)
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    ptr->unk_00c = sub_81C7078(atk47_cmd47, 4);
}

void sub_81C78A0(void)
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    ptr->unk_00c = sub_81C7078(sub_81C791C, 4);
}

bool32 sub_81C78C0(void)
{
    struct PokenavStruct_81C76C4 *ptr = sub_81C763C(0);
    return sub_81C70D8(ptr->unk_00c);
}

static int atk47_cmd47(int a0)
{
    switch (a0)
    {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            if (ChangeBgY(0, 0x180, 1) < 0x2000)
            {
                return 2;
            }
            ChangeBgY(0, 0x2000, 0);
            return 4;
        default:
            return 4;
    }
}

static int sub_81C791C(int a0)
{
    if ((int)ChangeBgY(0, 0x180, 2) <= 0)
    {
        ChangeBgY(0, 0, 0);
        return 4;
    }
    return 2;
}

void sub_81C7944(const u16 *src, ptrdiff_t offset, size_t size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
}

void sub_81C795C(struct SpritePalette *palettes)
{
    u32 paletteSlot;

    while (palettes->data != NULL && (paletteSlot = AllocSpritePalette(palettes->tag)) != 0xFF)
    {
        paletteSlot = 16 * paletteSlot + 0x100;
        sub_81C7944(palettes->data, paletteSlot, 0x20);
        palettes++;
    }
}
