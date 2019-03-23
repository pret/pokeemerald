#include "global.h"
#include "braille_puzzles.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/songs.h"

// structures
struct FlashStruct
{
    u8 unk0;
    u8 unk1;
    bool8 unk2;
    bool8 unk3;
    void (*func)(void);
};

// static functions
static void hm2_flash(void);
static void sub_81371B4(void);
static bool8 sub_8137304(void);
static void sub_81373F0(void);
static void sub_8137404(u8 taskId);
static void sub_8137420(u8 taskId);
static void sub_81374C4(u8 taskId);
static void sub_813750C(u8 taskId);
static void sub_8137574(u8 taskId);
static void sub_81375A8(void);
static void sub_81375BC(u8 taskId);
static void sub_81375D8(u8 taskId);
static void sub_8137678(u8 taskId);
static void sub_81376DC(u8 taskId);

// rodata
static const struct FlashStruct gUnknown_085B27C8[] =
{
    {1, 4, 1, 0, sub_81375A8},
    {2, 4, 1, 0, sub_81375A8},
    {3, 4, 1, 0, sub_81375A8},
    {5, 4, 1, 0, sub_81375A8},
    {6, 4, 1, 0, sub_81375A8},
    {7, 4, 1, 0, sub_81375A8},
    {8, 4, 1, 0, sub_81375A8},
    {9, 4, 1, 0, sub_81375A8},
    {4, 1, 0, 1, sub_81373F0},
    {4, 2, 0, 1, sub_81373F0},
    {4, 3, 0, 1, sub_81373F0},
    {4, 5, 0, 1, sub_81373F0},
    {4, 6, 0, 1, sub_81373F0},
    {4, 7, 0, 1, sub_81373F0},
    {4, 8, 0, 1, sub_81373F0},
    {4, 9, 0, 1, sub_81373F0},
    {0, 0, 0, 0, NULL},
};

static const u16 gCaveTransitionPalette_White[] = INCBIN_U16("graphics/misc/cave_transition_white.gbapal");
static const u16 gCaveTransitionPalette_Black[] = INCBIN_U16("graphics/misc/cave_transition_black.gbapal");

static const u16 gUnknown_085B2890[] = INCBIN_U16("graphics/misc/85B2890.gbapal");
static const u16 gUnknown_085B28A0[] = INCBIN_U16("graphics/misc/85B28A0.gbapal");
static const u32 gCaveTransitionTilemap[] = INCBIN_U32("graphics/misc/cave_transition_map.bin.lz");
static const u32 gCaveTransitionTiles[] = INCBIN_U32("graphics/misc/cave_transition.4bpp.lz");

// text
bool8 SetUpFieldMove_Flash(void)
{
    // In Ruby and Sapphire, Registeel's tomb is opened by using Fly. In Emerald,
    // Flash is used instead.
    if (ShouldDoBrailleRegisteelEffect())
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = SetUpPuzzleEffectRegisteel;
        return TRUE;
    }
    else if (gMapHeader.cave == TRUE && !FlagGet(FLAG_SYS_USE_FLASH))
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = hm2_flash;
        return TRUE;
    }

    return FALSE;
}

static void hm2_flash(void)
{
    u8 taskId = oei_task_add();
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    gTasks[taskId].data[8] = (uintptr_t)sub_81371B4 >> 16;
    gTasks[taskId].data[9] = (uintptr_t)sub_81371B4;
}

static void sub_81371B4(void)
{
    PlaySE(SE_W115);
    FlagSet(FLAG_SYS_USE_FLASH);
    ScriptContext1_SetupScript(EventScript_2926F8);
}

static void sub_81371D4(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_81371EC(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void c2_change_map(void)
{
    u16 ime;

    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    ResetPaletteFade();
    ResetTasks();
    ResetSpriteData();
    ime = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = ime;
    SetVBlankCallback(sub_81371EC);
    SetMainCallback2(sub_81371D4);
    if (!sub_8137304())
        SetMainCallback2(gMain.savedCallback);
}

static bool8 sub_8137304(void)
{
    u8 i;
    u8 v0 = GetLastUsedWarpMapType();
    u8 v1 = GetCurrentMapType();

    for (i = 0; gUnknown_085B27C8[i].unk0; i++)
    {
        if (gUnknown_085B27C8[i].unk0 == v0 && gUnknown_085B27C8[i].unk1 == v1)
        {
            gUnknown_085B27C8[i].func();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 GetMapPairFadeToType(u8 a1, u8 a2)
{
    u8 i;
    u8 v0 = a1;
    u8 v1 = a2;

    for (i = 0; gUnknown_085B27C8[i].unk0; i++)
    {
        if (gUnknown_085B27C8[i].unk0 == v0 && gUnknown_085B27C8[i].unk1 == v1)
        {
            return gUnknown_085B27C8[i].unk2;
        }
    }

    return FALSE;
}

bool8 GetMapPairFadeFromType(u8 a1, u8 a2)
{
    u8 i;
    u8 v0 = a1;
    u8 v1 = a2;

    for (i = 0; gUnknown_085B27C8[i].unk0; i++)
    {
        if (gUnknown_085B27C8[i].unk0 == v0 && gUnknown_085B27C8[i].unk1 == v1)
        {
            return gUnknown_085B27C8[i].unk3;
        }
    }

    return FALSE;
}

static void sub_81373F0(void)
{
    CreateTask(sub_8137404, 0);
}

static void sub_8137404(u8 taskId)
{
    gTasks[taskId].func = sub_8137420;
}

static void sub_8137420(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(gCaveTransitionTiles, (void *)0x600C000);
    LZ77UnCompVram(gCaveTransitionTilemap, (void *)0x600F800);
    LoadPalette(gCaveTransitionPalette_White, 0xE0, 0x20);
    LoadPalette(gUnknown_085B28A0, 0xE0, 0x10);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                                | BLDCNT_EFFECT_BLEND
                                | BLDCNT_TGT2_BG1
                                | BLDCNT_TGT2_BG2
                                | BLDCNT_TGT2_BG3
                                | BLDCNT_TGT2_OBJ
                                | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_OBJ_ON);
    gTasks[taskId].func = sub_81374C4;
    gTasks[taskId].data[0] = 16;
    gTasks[taskId].data[1] = 0;
}

static void sub_81374C4(u8 taskId)
{
    u16 count = gTasks[taskId].data[1];
    u16 blend = count + 0x1000;

    SetGpuReg(REG_OFFSET_BLDALPHA, blend);
    if (count <= 0x10)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_813750C;
    }
}

static void sub_813750C(u8 taskId)
{
    u16 count;

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 16));
    count = gTasks[taskId].data[2];

    if (count < 8)
    {
        gTasks[taskId].data[2]++;
        LoadPalette(&gUnknown_085B28A0[count], 0xE0, 16 - 2 * count);
    }
    else
    {
        LoadPalette(gCaveTransitionPalette_White, 0, 0x20);
        gTasks[taskId].func = sub_8137574;
        gTasks[taskId].data[2] = 8;
    }
}

static void sub_8137574(u8 taskId)
{
    if (gTasks[taskId].data[2])
        gTasks[taskId].data[2]--;
    else
        SetMainCallback2(gMain.savedCallback);
}

static void sub_81375A8(void)
{
    CreateTask(sub_81375BC, 0);
}

static void sub_81375BC(u8 taskId)
{
    gTasks[taskId].func = sub_81375D8;
}

static void sub_81375D8(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(gCaveTransitionTiles, (void *)0x600C000);
    LZ77UnCompVram(gCaveTransitionTilemap, (void *)0x600F800);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_OBJ_ON);
    LoadPalette(gCaveTransitionPalette_White, 0xE0, 0x20);
    LoadPalette(gCaveTransitionPalette_Black, 0, 0x20);
    gTasks[taskId].func = sub_8137678;
    gTasks[taskId].data[0] = 16;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
}

static void sub_8137678(u8 taskId)
{
    u16 count = gTasks[taskId].data[2];

    if (count < 16)
    {
        gTasks[taskId].data[2]++;
        gTasks[taskId].data[2]++;
        LoadPalette(&gUnknown_085B2890[15 - count], 0xE0, 2 * (count + 1));
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 16));
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                                    | BLDCNT_EFFECT_BLEND
                                    | BLDCNT_TGT2_BG1
                                    | BLDCNT_TGT2_BG2
                                    | BLDCNT_TGT2_BG3
                                    | BLDCNT_TGT2_OBJ
                                    | BLDCNT_TGT2_BD);
        gTasks[taskId].func = sub_81376DC;
    }
}

static void sub_81376DC(u8 taskId)
{
    u16 count = 16 - gTasks[taskId].data[1];
    u16 blend = count + 0x1000;

    SetGpuReg(REG_OFFSET_BLDALPHA, blend);
    if (count)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        LoadPalette(gCaveTransitionPalette_Black, 0, 0x20);
        SetMainCallback2(gMain.savedCallback);
    }
}
