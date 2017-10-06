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

extern u16 gUnknown_0203BCFC;
extern const u8 gUnknown_085B0E04[];
extern const u8 gUnknown_085B0A80[];
extern const u8 gUnknown_085B0C0C[];
extern const u8 gUnknown_085EFDE4[];

extern const struct OamData gUnknown_085EFD80; // sClockOamData
extern const u8 gUnknown_085EFDAC[8][3]; // sClockFrames

extern const struct BgTemplate gUnknown_085EFD88[];
extern const struct WindowTemplate gUnknown_085EFD94[];
extern struct WindowTemplate gUnknown_085EFD9C;
extern struct WindowTemplate gUnknown_085EFDA4;
extern struct SaveSection gSaveDataBuffer;
extern const u32 gUnknown_0850E87C[];

extern const u16 gUnknown_085B0A00[];
extern const u16 gUnknown_085EFDC4[];
extern const u16 gUnknown_0850FEFC[];
extern const u16 gUnknown_0860F074[];

extern u8 gText_SaveFailedCheckingBackup[];
extern u8 gText_BackupMemoryDamaged[];
extern u8 gText_CheckCompleted[];
extern u8 gText_SaveCompleteGameCannotContinue[];
extern u8 gText_SaveCompletePressA[];
extern u8 gText_GamePlayCannotBeContinued[];

extern void sub_8179454(void);

extern u8 gDecompressionBuffer[];

struct Unk203BCFC
{
    u16 unk0;
    u16 unk2;
};

extern struct Unk203BCFC gUnknown_0203BCFE;

struct Unk203BD0E
{
    u8 unk0;
    u8 unk1;
};

extern struct Unk203BD0E gUnknown_0203BD0E;

void sub_8178FDC(void);
void sub_8179288(void);
void sub_8179390(void);
void sub_81793E0(void);
bool8 sub_81795AC(u32);
void sub_8179428(void);
bool8 sub_8179514(u16 sector);

void sub_8178F44(u8 *text, u8 var1, u8 var2)
{
    struct TextColor color;

    color.fgColor = 0;
    color.bgColor = 15;
    color.shadowColor = 3;
    AddTextPrinterParametrized2(gUnknown_0203BD0E.unk0, 1, var1 * 8, var2 * 8 + 1, 0, 0, &color, 0, text);
}

void DoSaveFailedScreen(u8 saveType)
{
    SetMainCallback2(sub_8178FDC);
    gUnknown_0203BCFC = saveType;
    gUnknown_0203BCFE.unk0 = 0;
    gUnknown_0203BCFE.unk2 = 0;
    gUnknown_0203BD0E.unk0 = 0;
    gUnknown_0203BD0E.unk1 = 0;
}

void sub_8178FC8(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8178FDC(void)
{
    switch(gMain.state)
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
            LZ77UnCompVram(gUnknown_085B0E04, (void *)VRAM);
            LZ77UnCompVram(gUnknown_085B0A80, (void *)(VRAM + 0x7000));
            LZ77UnCompVram(gUnknown_085B0C0C, (void *)(VRAM + 0x7800));
            LZ77UnCompVram(gUnknown_085EFDE4, (void *)(VRAM + 0x10020));
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gUnknown_085EFD88, 3);
            SetBgTilemapBuffer(0, (void *)&gDecompressionBuffer[0x2000]);
            CpuFill32(0, &gDecompressionBuffer[0x2000], 0x800);
            LoadBgTiles(0, gUnknown_0850E87C, 0x120, 0x214);
            InitWindows(gUnknown_085EFD94);
            // AddWindowWithoutTileMap returns a u16/integer, but the info is clobbered into a u8 here resulting in lost info. Bug?
            gUnknown_0203BD0E.unk0 = AddWindowWithoutTileMap(&gUnknown_085EFD9C);
            SetWindowAttribute(gUnknown_0203BD0E.unk0, 7, (u32)&gDecompressionBuffer[0x2800]);
            gUnknown_0203BD0E.unk1 = AddWindowWithoutTileMap(&gUnknown_085EFDA4);
            SetWindowAttribute(gUnknown_0203BD0E.unk1, 7, (u32)&gDecompressionBuffer[0x3D00]);
            DeactivateAllTextPrinters();
            ResetSpriteData();
            ResetTasks();
            ResetPaletteFade();
            LoadPalette(gUnknown_085B0A00, 0, 0x40);
            LoadPalette(gUnknown_085EFDC4, 0x100, 0x20);
            LoadPalette(gUnknown_0850FEFC, 0xE0, 0x20);
            LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
            SetWindowBorderStyle(gUnknown_0203BD0E.unk0, FALSE, 0x214, 0xE);
            SetWindowBorderStyle(gUnknown_0203BD0E.unk1, FALSE, 0x214, 0xE);
            FillWindowPixelBuffer(gUnknown_0203BD0E.unk1, 0x11); // backwards?
            FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
            CopyWindowToVram(gUnknown_0203BD0E.unk1, 2); // again?
            CopyWindowToVram(gUnknown_0203BD0E.unk0, 1);
            sub_8178F44(gText_SaveFailedCheckingBackup, 1, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
            EnableInterrupts(1);
            SetVBlankCallback(sub_8178FC8);
            SetGpuReg(0, 0x1040);
            ShowBg(0);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 1:
            if(!UpdatePaletteFade())
            {
                SetMainCallback2(sub_8179288);
                SetVBlankCallback(sub_8179454);
            }
            break;
    }
}

void sub_8179288(void)
{
    u8 wipeTries = 0;

    gUnknown_0203BCFE.unk0 = TRUE;

    while (gDamagedSaveSectors != 0 && wipeTries < 3)
    {
        if (sub_81795AC(gDamagedSaveSectors) != FALSE)
        {
            FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
            sub_8178F44(gText_BackupMemoryDamaged, 1, 0);
            SetMainCallback2(sub_8179390);
            return;
        }

        FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
        sub_8178F44(gText_CheckCompleted, 1, 0);
        HandleSavingData(gUnknown_0203BCFC);

        if(gDamagedSaveSectors != 0)
        {
            FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
            sub_8178F44(gText_SaveFailedCheckingBackup, 1, 0);
        }

        wipeTries++;
    }

    if(wipeTries == 3)
    {
        FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
        sub_8178F44(gText_BackupMemoryDamaged, 1, 0);
    }
    else
    {
        FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);

        if(gGameContinueCallback == NULL)
            sub_8178F44(gText_SaveCompleteGameCannotContinue, 1, 0);
        else
            sub_8178F44(gText_SaveCompletePressA, 1, 0);
    }

    SetMainCallback2(sub_81793E0);
}

void sub_8179390(void)
{
    gUnknown_0203BCFE.unk0 = FALSE;

    if(gMain.newKeys & A_BUTTON)
    {
        FillWindowPixelBuffer(gUnknown_0203BD0E.unk0, 0x11);
        sub_8178F44(gText_GamePlayCannotBeContinued, 1, 0);
        SetVBlankCallback(sub_8178FC8);
        SetMainCallback2(sub_81793E0);
    }
}

void sub_81793E0(void)
{
    gUnknown_0203BCFE.unk0 = FALSE;

    if(gMain.newKeys & A_BUTTON)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        SetVBlankCallback(sub_8178FC8);
        SetMainCallback2(sub_8179428);
    }
}

void sub_8179428(void)
{
    if(!UpdatePaletteFade())
    {
        if(gGameContinueCallback == NULL) // no callback exists, so do a soft reset.
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

void sub_8179454(void)
{
    unsigned int n = (gMain.vblankCounter2 >> 3) & 7;

    gMain.oamBuffer[0] = gUnknown_085EFD80;
    gMain.oamBuffer[0].x = 112;
    gMain.oamBuffer[0].y = (CLOCK_WIN_TOP + 1) * 8;;

    if(gUnknown_0203BCFE.unk0 != FALSE)
    {
        gMain.oamBuffer[0].tileNum = gUnknown_085EFDAC[n][0];
        gMain.oamBuffer[0].matrixNum = (gUnknown_085EFDAC[n][2] << 4) | (gUnknown_085EFDAC[n][1] << 3);
    }
    else
    {
        gMain.oamBuffer[0].tileNum = 1;
    }

    CpuFastCopy(gMain.oamBuffer, (void *)OAM, 4);

    if(gUnknown_0203BCFE.unk2)
        gUnknown_0203BCFE.unk2--;
}

bool8 sub_8179514(u16 sector)
{
    u32 *ptr = (u32 *)&gSaveDataBuffer;
    u16 i;

    ReadFlash(sector, 0, (u8 *)ptr, 4096);

    for (i = 0; i < 0x400; i++, ptr++)
        if (*ptr)
            return TRUE;

    return FALSE;
}

bool8 sub_8179554(u16 sector)
{
    u16 i, j;
    bool8 failed = TRUE;

    for (i = 0; failed && i < 130; i++)
    {
        for (j = 0; j < 0x1000; j++)
            ProgramFlashByte(sector, j, 0);

        failed = sub_8179514(sector);
    }

    return failed;
}

bool8 sub_81795AC(u32 sectorBits)
{
    u16 i;

    for (i = 0; i < 0x20; i++)
        if ((sectorBits & (1 << i)) && !sub_8179554(i))
            sectorBits &= ~(1 << i);

    if (sectorBits == 0)
        return FALSE;
    else
        return TRUE;
}
