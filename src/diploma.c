#include "global.h"
#include "palette.h"
#include "main.h"
#include "gpu_regs.h"
#include "unknown_task.h"
#include "task.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"
#include "string_util.h"
#include "text.h"

extern void reset_temp_tile_data_buffers(void);
extern int decompress_and_copy_tile_data_to_vram(u8 bg_id, void *src, int size, u16 offset, u8 mode);
extern bool8 free_temp_tile_data_buffers_if_possible(void);
extern void sub_80861E8(void); // rom4
extern bool16 sub_80C0944(void);
extern void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor *color, s8 speed, u8 *str);

extern u16 gUnknown_0860F074[];

extern u8 gText_DexNational[];
extern u8 gText_DexHoenn[];
extern u8 gText_PokedexDiploma[];

static void MainCB2(void);
static void Task_DiplomaFadeIn(u8);
static void Task_DiplomaWaitForKeyPress(u8);
static void Task_DiplomaFadeOut(u8);
static void DisplayDiplomaText(void);
static void InitDiplomaBg(void);
static void InitDiplomaWindow(void);
static void PrintDiplomaText(u8 *, u8, u8);

EWRAM_DATA void **gDiplomaTilemapPtr = {NULL};

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const u16 gDiplomaPalettes[][16] =
{
    INCBIN_U16("graphics/misc/diploma_national.gbapal"),
    INCBIN_U16("graphics/misc/diploma_hoenn.gbapal"),
};

static const u8 gDiplomaTilemap[] = INCBIN_U8("graphics/misc/diploma_map.bin.lz");
static const u8 gDiplomaTiles[] = INCBIN_U8("graphics/misc/diploma.4bpp.lz");

void CB2_ShowDiploma(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0VOFS, DISPCNT_MODE_0);
    // why doesn't this one use the dma manager either?
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    remove_some_task();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadPalette(gDiplomaPalettes, 0, 64);
    gDiplomaTilemapPtr = malloc(0x1000);
    InitDiplomaBg();
    InitDiplomaWindow();
    reset_temp_tile_data_buffers();
    decompress_and_copy_tile_data_to_vram(1, &gDiplomaTiles, 0, 0, 0);
    while (free_temp_tile_data_buffers_if_possible())
        ;
    LZDecompressWram(&gDiplomaTilemap, gDiplomaTilemapPtr);
    CopyBgTilemapBufferToVram(1);
    DisplayDiplomaText();
    BlendPalettes(-1, 16, 0);
    BeginNormalPaletteFade(-1, 0, 16, 0, 0);
    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(MainCB2);
    CreateTask(Task_DiplomaFadeIn, 0);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_DiplomaFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DiplomaWaitForKeyPress;
}

static void Task_DiplomaWaitForKeyPress(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskId].func = Task_DiplomaFadeOut;
    }
}

static void Task_DiplomaFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(gDiplomaTilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(sub_80861E8);
    }
}

static void DisplayDiplomaText(void)
{
    if (sub_80C0944())
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_BG0_ON);
        StringCopy(gStringVar1, gText_DexNational);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_MODE_0);
        StringCopy(gStringVar1, gText_DexHoenn);
    }
    StringExpandPlaceholders(gStringVar4, gText_PokedexDiploma);
    PrintDiplomaText(gStringVar4, 0, 1);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static const struct BgTemplate gDiplomaBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static void InitDiplomaBg(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gDiplomaBgTemplates, 2);
    SetBgTilemapBuffer(1, gDiplomaTilemapPtr);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BLDALPHA, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BLDY, DISPCNT_MODE_0);
}

static const struct WindowTemplate gDiplomaWinTemplates[2] =
{
    {
        .priority = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 20,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

static void InitDiplomaWindow(void)
{
    InitWindows(gDiplomaWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
    FillWindowPixelBuffer(0, 0);
    PutWindowTilemap(0);
}

static void PrintDiplomaText(u8 *text, u8 var1, u8 var2)
{
    struct TextColor color =
    {
        .fgColor = 0,
        .bgColor = 2,
        .shadowColor = 3,
    };

    AddTextPrinterParametrized2(0, 1, var1, var2, 0, 0, &color, -1, text);
}
