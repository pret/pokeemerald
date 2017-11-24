#include "global.h"
#include "main.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "rtc.h"
#include "clock.h"
#include "wallclock.h"
#include "event_data.h"
#include "graphics.h"
#include "text.h"
#include "window.h"
#include "text_window.h"
#include "menu.h"
#include "unknown_task.h"
#include "task.h"
#include "decompress.h"

// static types

// static declarations

// rodata

extern const u16 gUnknown_085B21D4[];
extern const struct BgTemplate gUnknown_085B21FC[];
extern const struct WindowTemplate gUnknown_085B21DC[];
extern const struct CompressedSpriteSheet gUnknown_085B2208;
extern const struct SpritePalette gUnknown_085B2218;

// text

void sub_81347B4(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void LoadWallClockGraphics(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG3CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG2CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG1CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG0CNT, 0x0000);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    LZ77UnCompVram(gUnknown_08DCC05C, (void *)VRAM);
    if (gSpecialVar_0x8004 == 0)
    {
        LoadPalette(gUnknown_08DCC01C, 0x00, 0x20);
    }
    else
    {
        LoadPalette(gUnknown_08DCC03C, 0x00, 0x20);
    }
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xe0, 0x20);
    LoadPalette(gUnknown_085B21D4, 0xc0, 0x08);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B21FC, 3);
    InitWindows(gUnknown_085B21DC);
    DeactivateAllTextPrinters();
    sub_809882C(0, 0x250, 0xd0);
    clear_scheduled_bg_copies_to_vram();
    remove_some_task();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadCompressedObjectPic(&gUnknown_085B2208);
    LoadSpritePalettes(&gUnknown_085B2218);
}
