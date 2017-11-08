
// Includes
#include "global.h"
#include "librfu.h"
#include "rng.h"
#include "string_util.h"
#include "event_data.h"
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

bool8 gUnknown_020229C4 = 0;
u16 gUnknown_020229C6 = 0;
struct LinkPlayer gUnknown_020229CC = {};

// Static ROM declarations

void sub_8009638(void);
void sub_80096BC(void);
void c2_08009A8C(void);
void sub_800A2E0(void);
void task00_link_test(u8 taskId);
void sub_800A824(void);
void sub_800B594(void);
void sub_800B4A4(void);
u32 sub_800BEC0(void);
void sub_800E700(void);

// .rodata

ALIGNED(4) const u16 gWirelessLinkDisplayPal[] = INCBIN_U16("graphics/interface/wireless_link_display.gbapal");
const u8 gWirelessLinkDisplayGfx[] = INCBIN_U8("graphics/interface/wireless_link_display.4bpp.lz");
const u8 gWirelessLinkDisplayTilemap[] = INCBIN_U8("graphics/interface/wireless_link_display.bin.lz");
const u16 gLinkTestDigitsPal[] = INCBIN_U16("graphics/interface/link_test_digits.gbapal");
const u16 gLinkTestDigitsGfx[] = INCBIN_U16("graphics/interface/link_test_digits.4bpp");
const u8 unkstring_82ed160[] = _("{HIGHLIGHT TRANSPARENT}{COLOR WHITE}");
const u16 g2BlankTilesGfx[] = INCBIN_U16("graphics/interface/blank_1x2.4bpp");
const struct {
    void *data;
    u16 size;
} gUnknown_082ED1A8[] = {
    {gUnknown_020228C4, 200},
    {gUnknown_020228C4, 200},
    {gUnknown_020228C4, 100},
    {gUnknown_020228C4, 220},
    {gUnknown_020228C4,  40}
};
const u8 gUnknown_082ED1D0[] = {
    REG_OFFSET_BG0CNT,
    REG_OFFSET_BG1CNT,
    REG_OFFSET_BG2CNT,
    REG_OFFSET_BG3CNT
};

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
    gUnknown_03003130.screenBaseBlock = a2;
    gUnknown_03003130.paletteNum = a0;
    gUnknown_03003130.dummy_8 = a4;
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

void sub_80094EC(u8 a0, u8 a1, u8 a2, u8 a3)
{
    LoadPalette(gLinkTestDigitsPal, a0 * 16, 0x20);
    DmaCopy16(3, gLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(a3), sizeof gLinkTestDigitsGfx);
    gUnknown_03003130.screenBaseBlock = a2;
    gUnknown_03003130.paletteNum = a0;
    gUnknown_03003130.dummy_8 = 0;
    SetGpuReg(gUnknown_082ED1D0[a1], BGCNT_SCREENBASE(a2) | BGCNT_CHARBASE(a3));
}

void sub_8009570(void)
{
    int i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(sub_80096BC);
    sub_800A2E0();
    gUnknown_020229C6 = 0x1111;
    sub_8009734();
    SeedRng(gMain.vblankCounter2);
    for (i = 0; i < 4; i ++)
    {
        gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;
    }
    sub_8009414(0, 2, 4, 0, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    CreateTask(sub_8009404, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    gUnknown_03000D60 = 0;
    sub_8009638();
    CreateTask(task00_link_test, 0);
    SetMainCallback2(c2_08009A8C);
}

void sub_8009628(u8 a0)
{
    gUnknown_020229CC.lp_field_18 = a0;
}

void sub_8009638(void)
{
    gUnknown_020229CC.trainerId = gSaveBlock2Ptr->playerTrainerId[0] | (gSaveBlock2Ptr->playerTrainerId[1] << 8) | (gSaveBlock2Ptr->playerTrainerId[2] << 16) | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    StringCopy(gUnknown_020229CC.name, gSaveBlock2Ptr->playerName);
    gUnknown_020229CC.gender = gSaveBlock2Ptr->playerGender;
    gUnknown_020229CC.linkType = gUnknown_020229C6;
    gUnknown_020229CC.language = gGameLanguage;
    gUnknown_020229CC.version = gGameVersion + 0x4000;
    gUnknown_020229CC.lp_field_2 = 0x8000;
    gUnknown_020229CC.name[8] = IsNationalPokedexEnabled();
    if (FlagGet(SYS_UNKNOWN_87F))
    {
        gUnknown_020229CC.name[8] |= 0x10;
    }
}

void sub_80096BC(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_80096D0(void)
{
    int i;

    for (i = 0; i < 8; i ++)
    {
        gUnknown_03003110[i] = 0xefff;
    }
    gUnknown_020229C4 = TRUE;
    sub_800B594();
}

void task02_080097CC(u8 taskId)
{
    if (++ gTasks[taskId].data[0] == 5)
    {
        gUnknown_03003144 = TRUE;
        DestroyTask(taskId);
    }
}

void sub_8009734(void)
{
    int i;

    if (!gLinkVSyncDisabled)
    {
        sub_800B628();
        sub_80096D0();
        gUnknown_03003140 = sub_800A824;
        gUnknown_03002748 = 0;
        gUnknown_0300306C = 0;
        gUnknown_030030F8 = 0;
        ResetBlockReceivedFlags();
        sub_800A2E0();
        gUnknown_03000D54 = 0;
        gUnknown_030030E8 = 0;
        gUnknown_030030E4 = 0;
        gUnknown_030030F4 = 0;
        CreateTask(task02_080097CC, 2);
    }
    else
    {
        sub_800E700();
    }
    gReceivedRemoteLinkPlayers = 0;
    for (i = 0; i < 4; i ++)
    {
        gUnknown_03003078[i] = 1;
        gUnknown_030030F0[i] = 0;
        gUnknown_030030EC[i] = 0;
    }
}
