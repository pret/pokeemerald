#include "global.h"
#include "text.h"
#include "main.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "task.h"
#include "window.h"
#include "menu.h"
#include "save.h"
#include "gba/flash_internal.h"

#define MSG_WIN_TOP 12
#define CLOCK_WIN_TOP (MSG_WIN_TOP - 4)

extern void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor *color, u8 speed, u8 *str);

extern void (*gGameContinueCallback)(void);

extern u32 gDamagedSaveSectors;

extern u16 gSaveFailedType;
extern const u8 gBirchHelpGfx[];
extern const u8 gBirchBagTilemap[];
extern const u8 gBirchGrassTilemap[];
extern const u8 gSaveFailedClockGfx[];

extern const struct OamData gClockOamData; // sClockOamData
extern const u8 gClockFrames[8][3]; // sClockFrames

extern const struct BgTemplate gUnknown_085EFD88[];
extern const struct WindowTemplate gUnknown_085EFD94[];
extern struct WindowTemplate gUnknown_085EFD9C;
extern struct WindowTemplate gUnknown_085EFDA4;
extern struct SaveSection gSaveDataBuffer;
extern const u32 gUnknown_0850E87C[];

extern const u16 gBirchBagGrassPal[];
extern const u16 gSaveFailedClockPal[];
extern const u16 gUnknown_0850FEFC[];
extern const u16 gUnknown_0860F074[];

extern u8 gText_SaveFailedCheckingBackup[];
extern u8 gText_BackupMemoryDamaged[];
extern u8 gText_CheckCompleted[];
extern u8 gText_SaveCompleteGameCannotContinue[];
extern u8 gText_SaveCompletePressA[];
extern u8 gText_GamePlayCannotBeContinued[];

extern u8 gDecompressionBuffer[];

struct ClockInfo
{
    bool16 clockRunning;
    u16 debugTimer; // appears to be unused; it's only set to 0 and never used within the game. perhaps it was a volatile-like timer expected to be modified by an external tool?
};

extern struct ClockInfo gSaveFailedClockInfo;

struct WindowIds
{
    u8 textWindowId;
    u8 clockWindowId;
};

extern struct WindowIds gSaveFailedWindowIds;

static void CB2_SaveFailedScreen(void);
static void CB2_WipeSave(void);
static void CB2_GameplayCannotBeContinued(void);
static void CB2_FadeAndReturnToTitleScreen(void);
static void CB2_ReturnToTitleScreen(void);
static void VBlankCB_UpdateClockGraphics(void);
static bool8 VerifySectorWipe(u16 sector);
static bool8 WipeSectors(u32);

// although this is a general text printer, it's only used in this file.
static void SaveFailedScreenTextPrint(u8 *text, u8 var1, u8 var2)
{
    struct TextColor color;

    color.fgColor = 0;
    color.bgColor = 15;
    color.shadowColor = 3;
    AddTextPrinterParametrized2(gSaveFailedWindowIds.textWindowId, 1, var1 * 8, var2 * 8 + 1, 0, 0, &color, 0, text);
}

void DoSaveFailedScreen(u8 saveType)
{
    SetMainCallback2(CB2_SaveFailedScreen);
    gSaveFailedType = saveType;
    gSaveFailedClockInfo.clockRunning = FALSE;
    gSaveFailedClockInfo.debugTimer = 0;
    gSaveFailedWindowIds.textWindowId = 0;
    gSaveFailedWindowIds.clockWindowId = 0;
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
            // how come this doesnt use the Dma manager?
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            DmaFill32(3, 0, OAM, OAM_SIZE);
            DmaFill16(3, 0, PLTT, PLTT_SIZE);
            LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
            LZ77UnCompVram(gBirchBagTilemap, (void *)(VRAM + 0x7000));
            LZ77UnCompVram(gBirchGrassTilemap, (void *)(VRAM + 0x7800));
            LZ77UnCompVram(gSaveFailedClockGfx, (void *)(VRAM + 0x10020));
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gUnknown_085EFD88, 3);
            SetBgTilemapBuffer(0, (void *)&gDecompressionBuffer[0x2000]);
            CpuFill32(0, &gDecompressionBuffer[0x2000], 0x800);
            LoadBgTiles(0, gUnknown_0850E87C, 0x120, 0x214);
            InitWindows(gUnknown_085EFD94);
            // AddWindowWithoutTileMap returns a u16/integer, but the info is clobbered into a u8 here resulting in lost info. Bug?
            gSaveFailedWindowIds.textWindowId = AddWindowWithoutTileMap(&gUnknown_085EFD9C);
            SetWindowAttribute(gSaveFailedWindowIds.textWindowId, 7, (u32)&gDecompressionBuffer[0x2800]);
            gSaveFailedWindowIds.clockWindowId = AddWindowWithoutTileMap(&gUnknown_085EFDA4);
            SetWindowAttribute(gSaveFailedWindowIds.clockWindowId, 7, (u32)&gDecompressionBuffer[0x3D00]);
            DeactivateAllTextPrinters();
            ResetSpriteData();
            ResetTasks();
            ResetPaletteFade();
            LoadPalette(gBirchBagGrassPal, 0, 0x40);
            LoadPalette(gSaveFailedClockPal, 0x100, 0x20);
            LoadPalette(gUnknown_0850FEFC, 0xE0, 0x20);
            LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
            SetWindowBorderStyle(gSaveFailedWindowIds.textWindowId, FALSE, 0x214, 0xE);
            SetWindowBorderStyle(gSaveFailedWindowIds.clockWindowId, FALSE, 0x214, 0xE);
            FillWindowPixelBuffer(gSaveFailedWindowIds.clockWindowId, 0x11); // backwards?
            FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
            CopyWindowToVram(gSaveFailedWindowIds.clockWindowId, 2); // again?
            CopyWindowToVram(gSaveFailedWindowIds.textWindowId, 1);
            SaveFailedScreenTextPrint(gText_SaveFailedCheckingBackup, 1, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
            EnableInterrupts(1);
            SetVBlankCallback(VBlankCB);
            SetGpuReg(0, 0x1040);
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

    gSaveFailedClockInfo.clockRunning = TRUE;

    while (gDamagedSaveSectors != 0 && wipeTries < 3)
    {
        if (WipeSectors(gDamagedSaveSectors) != FALSE)
        {
            FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
            SaveFailedScreenTextPrint(gText_BackupMemoryDamaged, 1, 0);
            SetMainCallback2(CB2_GameplayCannotBeContinued);
            return;
        }

        FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
        SaveFailedScreenTextPrint(gText_CheckCompleted, 1, 0);
        HandleSavingData(gSaveFailedType);

        if (gDamagedSaveSectors != 0)
        {
            FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
            SaveFailedScreenTextPrint(gText_SaveFailedCheckingBackup, 1, 0);
        }

        wipeTries++;
    }

    if (wipeTries == 3)
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
        SaveFailedScreenTextPrint(gText_BackupMemoryDamaged, 1, 0);
    }
    else
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);

        if (gGameContinueCallback == NULL)
            SaveFailedScreenTextPrint(gText_SaveCompleteGameCannotContinue, 1, 0);
        else
            SaveFailedScreenTextPrint(gText_SaveCompletePressA, 1, 0);
    }

    SetMainCallback2(CB2_FadeAndReturnToTitleScreen);
}

static void CB2_GameplayCannotBeContinued(void)
{
    gSaveFailedClockInfo.clockRunning = FALSE;

    if (gMain.newKeys & A_BUTTON)
    {
        FillWindowPixelBuffer(gSaveFailedWindowIds.textWindowId, 0x11);
        SaveFailedScreenTextPrint(gText_GamePlayCannotBeContinued, 1, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_FadeAndReturnToTitleScreen);
    }
}

static void CB2_FadeAndReturnToTitleScreen(void)
{
    gSaveFailedClockInfo.clockRunning = FALSE;

    if (gMain.newKeys & A_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_ReturnToTitleScreen);
    }
}

void CB2_ReturnToTitleScreen(void)
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
    unsigned int n = (gMain.vblankCounter2 >> 3) & 7;

    gMain.oamBuffer[0] = gClockOamData;
    gMain.oamBuffer[0].x = 112;
    gMain.oamBuffer[0].y = (CLOCK_WIN_TOP + 1) * 8;;

    if (gSaveFailedClockInfo.clockRunning != FALSE)
    {
        gMain.oamBuffer[0].tileNum = gClockFrames[n][0];
        gMain.oamBuffer[0].matrixNum = (gClockFrames[n][2] << 4) | (gClockFrames[n][1] << 3);
    }
    else
    {
        gMain.oamBuffer[0].tileNum = 1;
    }

    CpuFastCopy(gMain.oamBuffer, (void *)OAM, 4);

    if (gSaveFailedClockInfo.debugTimer)
        gSaveFailedClockInfo.debugTimer--;
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
