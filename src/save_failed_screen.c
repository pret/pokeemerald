#include "global.h"
#include "text.h"
#include "main.h"
#include "palette.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "bg.h"
#include "decompress.h"
#include "task.h"
#include "window.h"
#include "menu.h"
#include "save.h"
#include "starter_choose.h"
#include "gba/flash_internal.h"
#include "text_window.h"
#include "constants/rgb.h"

#define MSG_WIN_TOP 12
#define CLOCK_WIN_TOP (MSG_WIN_TOP - 4)

extern const u8 gText_SaveFailedCheckingBackup[];
extern const u8 gText_BackupMemoryDamaged[];
extern const u8 gText_CheckCompleted[];
extern const u8 gText_SaveCompleteGameCannotContinue[];
extern const u8 gText_SaveCompletePressA[];
extern const u8 gText_GamePlayCannotBeContinued[];

// gSaveFailedClockInfo enum
enum
{
    CLOCK_RUNNING,
    DEBUG_TIMER
};

// gSaveFailedWindowIds enum
enum
{
    TEXT_WIN_ID,
    CLOCK_WIN_ID
};

EWRAM_DATA u16 gSaveFailedType = {0};
EWRAM_DATA u16 gSaveFailedClockInfo[2] = {0};
EWRAM_DATA u8 gSaveFailedUnused1[12] = {0};
EWRAM_DATA u8 gSaveFailedWindowIds[2] = {0};
EWRAM_DATA u8 gSaveFailedUnused2[4] = {0};

static const struct OamData sClockOamData =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct BgTemplate sBgTemplates[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const struct WindowTemplate gUnknown_085EFD94[] =
{
    {
        .bg = 255,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0,
    }
};

static const struct WindowTemplate gUnknown_085EFD9C[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 28,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 1,
    }
};

static const struct WindowTemplate gUnknown_085EFDA4[] =
{
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 9,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 169,
    }
};

static const u8 sClockFrames[8][3] =
{
    { 1, 0, 0 },
    { 5, 0, 0 },
    { 9, 0, 0 },
    { 5, 0, 1 },
    { 1, 0, 1 },
    { 5, 1, 1 },
    { 9, 1, 0 },
    { 5, 1, 0 },
};

static const u8 sSaveFailedClockPal[] = INCBIN_U8("graphics/misc/clock_small.gbapal");
static const u32 sSaveFailedClockGfx[] = INCBIN_U32("graphics/misc/clock_small.4bpp.lz");

static void CB2_SaveFailedScreen(void);
static void CB2_WipeSave(void);
static void CB2_GameplayCannotBeContinued(void);
static void CB2_FadeAndReturnToTitleScreen(void);
static void CB2_ReturnToTitleScreen(void);
static void VBlankCB_UpdateClockGraphics(void);
static bool8 VerifySectorWipe(u16 sector);
static bool8 WipeSectors(u32);

// Although this is a general text printer, it's only used in this file.
static void SaveFailedScreenTextPrint(const u8 *text, u8 var1, u8 var2)
{
    u8 color[3];

    color[0] = 0;
    color[1] = 15;
    color[2] = 3;
    AddTextPrinterParameterized4(gSaveFailedWindowIds[TEXT_WIN_ID], 1, var1 * 8, var2 * 8 + 1, 0, 0, color, 0, text);
}

void DoSaveFailedScreen(u8 saveType)
{
    SetMainCallback2(CB2_SaveFailedScreen);
    gSaveFailedType = saveType;
    gSaveFailedClockInfo[CLOCK_RUNNING] = FALSE;
    gSaveFailedClockInfo[DEBUG_TIMER] = 0;
    gSaveFailedWindowIds[TEXT_WIN_ID] = 0;
    gSaveFailedWindowIds[CLOCK_WIN_ID] = 0;
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_SaveFailedScreen(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT, PLTT_SIZE);
        LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
        LZ77UnCompVram(gBirchBagTilemap, (void *)(BG_SCREEN_ADDR(14)));
        LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(15)));
        LZ77UnCompVram(sSaveFailedClockGfx, (void *)(VRAM + 0x10020));
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(0, (void *)&gDecompressionBuffer[0x2000]);
        CpuFill32(0, &gDecompressionBuffer[0x2000], 0x800);
        LoadBgTiles(0, gTextWindowFrame1_Gfx, 0x120, 0x214);
        InitWindows(gUnknown_085EFD94);
        gSaveFailedWindowIds[TEXT_WIN_ID] = AddWindowWithoutTileMap(gUnknown_085EFD9C);
        SetWindowAttribute(gSaveFailedWindowIds[TEXT_WIN_ID], 7, (u32)&gDecompressionBuffer[0x2800]);
        gSaveFailedWindowIds[CLOCK_WIN_ID] = AddWindowWithoutTileMap(gUnknown_085EFDA4);
        SetWindowAttribute(gSaveFailedWindowIds[CLOCK_WIN_ID], 7, (u32)&gDecompressionBuffer[0x3D00]);
        DeactivateAllTextPrinters();
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        LoadPalette(gBirchBagGrassPal, 0, 0x40);
        LoadPalette(sSaveFailedClockPal, 0x100, 0x20);
        LoadPalette(gTextWindowFrame1_Pal, 0xE0, 0x20);
        LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
        DrawStdFrameWithCustomTileAndPalette(gSaveFailedWindowIds[TEXT_WIN_ID], FALSE, 0x214, 0xE);
        DrawStdFrameWithCustomTileAndPalette(gSaveFailedWindowIds[CLOCK_WIN_ID], FALSE, 0x214, 0xE);
        FillWindowPixelBuffer(gSaveFailedWindowIds[CLOCK_WIN_ID], PIXEL_FILL(1)); // backwards?
        FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
        CopyWindowToVram(gSaveFailedWindowIds[CLOCK_WIN_ID], 2); // again?
        CopyWindowToVram(gSaveFailedWindowIds[TEXT_WIN_ID], 1);
        SaveFailedScreenTextPrint(gText_SaveFailedCheckingBackup, 1, 0);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            SetMainCallback2(CB2_WipeSave);
            SetVBlankCallback(VBlankCB_UpdateClockGraphics);
        }
        break;
    }
}

static void CB2_WipeSave(void)
{
    u8 wipeTries = 0;

    gSaveFailedClockInfo[CLOCK_RUNNING] = TRUE;

    while (gDamagedSaveSectors != 0 && wipeTries < 3)
    {
        if (WipeSectors(gDamagedSaveSectors) != FALSE)
        {
            FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
            SaveFailedScreenTextPrint(gText_BackupMemoryDamaged, 1, 0);
            SetMainCallback2(CB2_GameplayCannotBeContinued);
            return;
        }

        FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
        SaveFailedScreenTextPrint(gText_CheckCompleted, 1, 0);
        HandleSavingData(gSaveFailedType);

        if (gDamagedSaveSectors != 0)
        {
            FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
            SaveFailedScreenTextPrint(gText_SaveFailedCheckingBackup, 1, 0);
        }

        wipeTries++;
    }

    if (wipeTries == 3)
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
        SaveFailedScreenTextPrint(gText_BackupMemoryDamaged, 1, 0);
    }
    else
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));

        if (gGameContinueCallback == NULL)
            SaveFailedScreenTextPrint(gText_SaveCompleteGameCannotContinue, 1, 0);
        else
            SaveFailedScreenTextPrint(gText_SaveCompletePressA, 1, 0);
    }

    SetMainCallback2(CB2_FadeAndReturnToTitleScreen);
}

static void CB2_GameplayCannotBeContinued(void)
{
    gSaveFailedClockInfo[CLOCK_RUNNING] = FALSE;

    if (JOY_NEW(A_BUTTON))
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds[TEXT_WIN_ID], PIXEL_FILL(1));
        SaveFailedScreenTextPrint(gText_GamePlayCannotBeContinued, 1, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_FadeAndReturnToTitleScreen);
    }
}

static void CB2_FadeAndReturnToTitleScreen(void)
{
    gSaveFailedClockInfo[CLOCK_RUNNING] = FALSE;

    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_ReturnToTitleScreen);
    }
}

static void CB2_ReturnToTitleScreen(void)
{
    if (!UpdatePaletteFade())
    {
        if (gGameContinueCallback == NULL) // no callback exists, so do a soft reset.
        {
            DoSoftReset();
        }
        else
        {
            SetMainCallback2((MainCallback)gGameContinueCallback);
            gGameContinueCallback = NULL;
        }
    }
}

static void VBlankCB_UpdateClockGraphics(void)
{
    u32 n = (gMain.vblankCounter2 >> 3) & 7;

    gMain.oamBuffer[0] = sClockOamData;
    gMain.oamBuffer[0].x = 112;
    gMain.oamBuffer[0].y = (CLOCK_WIN_TOP + 1) * 8;

    if (gSaveFailedClockInfo[CLOCK_RUNNING] != FALSE)
    {
        gMain.oamBuffer[0].tileNum = sClockFrames[n][0];
        gMain.oamBuffer[0].matrixNum = (sClockFrames[n][2] << 4) | (sClockFrames[n][1] << 3);
    }
    else
    {
        gMain.oamBuffer[0].tileNum = 1;
    }

    CpuFastCopy(gMain.oamBuffer, (void *)OAM, 4);

    if (gSaveFailedClockInfo[DEBUG_TIMER])
        gSaveFailedClockInfo[DEBUG_TIMER]--;
}

static bool8 VerifySectorWipe(u16 sector)
{
    u32 *ptr = (u32 *)&gSaveDataBuffer;
    u16 i;

    ReadFlash(sector, 0, (u8 *)ptr, 4096);

    for (i = 0; i < 0x400; i++, ptr++)
        if (*ptr)
            return TRUE;

    return FALSE;
}

static bool8 WipeSector(u16 sector)
{
    u16 i, j;
    bool8 failed = TRUE;

    for (i = 0; failed && i < 130; i++)
    {
        for (j = 0; j < 0x1000; j++)
            ProgramFlashByte(sector, j, 0);

        failed = VerifySectorWipe(sector);
    }

    return failed;
}

static bool8 WipeSectors(u32 sectorBits)
{
    u16 i;

    for (i = 0; i < 0x20; i++)
        if ((sectorBits & (1 << i)) && !WipeSector(i))
            sectorBits &= ~(1 << i);

    if (sectorBits == 0)
        return FALSE;
    else
        return TRUE;
}
