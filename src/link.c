
// Includes
#include "global.h"
#include "librfu.h"
#include "gpu_regs.h"
#include "palette.h"
#include "task.h"
#include "link.h"

// Static type declarations

struct BlockTransfer
{
    u16 pos;
    u16 size;
    void *src;
    bool8 active;
    u8 multiplayerId;
};

struct LinkTestBGInfo
{
    u32 screenBaseBlock;
    u32 paletteNum;
    u32 dummy_8;
    u32 dummy_C;
};

// Static RAM declarations

IWRAM_DATA struct BlockTransfer gUnknown_03000D10;
IWRAM_DATA u32 link_c_unused_03000d1c;
IWRAM_DATA struct BlockTransfer gUnknown_03000D20[4];
IWRAM_DATA u32 gUnknown_03000D50;
IWRAM_DATA u32 gUnknown_03000D54;
IWRAM_DATA u8 gUnknown_03000D58;
IWRAM_DATA u32 gUnknown_03000D5C;
IWRAM_DATA u32 gUnknown_03000D60;
IWRAM_DATA u8 gUnknown_03000D64;
ALIGNED() IWRAM_DATA u8 gUnknown_03000D68[4];
IWRAM_DATA u8 gUnknown_03000D6C;
IWRAM_DATA bool8 gUnknown_03000D6D;
IWRAM_DATA u16 gUnknown_03000D6E;
IWRAM_DATA u16 gUnknown_03000D70;
IWRAM_DATA u8 gUnknown_03000D72;
IWRAM_DATA u8 gUnknown_03000D73;
IWRAM_DATA u8 gUnknown_03000D74;
ALIGNED() IWRAM_DATA u8 gUnknown_03000D78;
ALIGNED(8) IWRAM_DATA u8 gUnknown_03000D80[16];
IWRAM_DATA u16 gUnknown_03000D90[8];
IWRAM_DATA u32 gUnknown_03000DA0;
IWRAM_DATA u32 gUnknown_03000DA4;
IWRAM_DATA void *gUnknown_03000DA8;
IWRAM_DATA void *gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

// Static ROM declarations

void sub_800E700(void);
u32 sub_800BEC0(void);
void sub_800B4A4(void);

// .rodata

ALIGNED(4) const u16 gWirelessLinkDisplayPal[] = INCBIN_U16("graphics/interface/wireless_link_display.gbapal");
const u8 gWirelessLinkDisplayGfx[] = INCBIN_U8("graphics/interface/wireless_link_display.4bpp.lz");
const u8 gWirelessLinkDisplayTilemap[] = INCBIN_U8("graphics/interface/wireless_link_display.bin.lz");
const u16 gLinkTestDigitsPal[] = INCBIN_U16("graphics/interface/link_test_digits.gbapal");
const u16 gLinkTestDigitsGfx[] = INCBIN_U16("graphics/interface/link_test_digits.4bpp");

// .text

bool8 sub_80093CC(void)
{
    sub_800B488();
    sub_800E700();
    if (sub_800BEC0() == 0x8001)
    {
        rfu_REQ_stopMode();
        rfu_waitREQComplete();
        return TRUE;
    }
    sub_800B4A4();
    sub_80097E8();
    RestoreSerialTimer3IntrHandlers();
    return FALSE;
}

void sub_8009404(u8 taskId)
{
    DestroyTask(taskId);
}

void sub_8009414(u8 a0, u8 a1, u8 a2, u8 a3, u16 a4)
{
    LoadPalette(gLinkTestDigitsPal, a0 * 16, 0x20);
    DmaCopy16(3, gLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(a3) + (16 * a4), sizeof gLinkTestDigitsGfx);
    gUnknown_03003130[0] = a2;
    gUnknown_03003130[1] = a0;
    gUnknown_03003130[2] = a4;
    switch (a1)
    {
        case 1:
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_SCREENBASE(a2) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(a3));
            break;
        case 2:
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_SCREENBASE(a2) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(a3));
            break;
        case 3:
            SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_SCREENBASE(a2) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(a3));
            break;
    }
    SetGpuReg(REG_OFFSET_BG0HOFS + a1 * 4, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS + a1 * 4, 0);
}
