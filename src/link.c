
// Includes
#include "global.h"
#include "malloc.h"
#include "save.h"
#include "bg.h"
#include "window.h"
#include "librfu.h"
#include "rng.h"
#include "decompress.h"
#include "string_util.h"
#include "event_data.h"
#include "item_menu.h"
#include "overworld.h"
#include "gpu_regs.h"
#include "palette.h"
#include "task.h"
#include "trade.h"
#include "link.h"

// Static type declarations

struct BlockTransfer
{
    u16 pos;
    u16 size;
    const u8 *src;
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

struct SIOCnt {
    u32 cnt0_0:4;
    u32 cnt0_2:2;
};

#define REG_SIOCNT_STRUCT (*(volatile struct SIOCnt *)REG_ADDR_SIOCNT)

// Static RAM declarations

IWRAM_DATA struct BlockTransfer gUnknown_03000D10;
IWRAM_DATA u32 link_c_unused_03000d1c;
IWRAM_DATA struct BlockTransfer gUnknown_03000D20[MAX_LINK_PLAYERS];
IWRAM_DATA u32 gUnknown_03000D50;
IWRAM_DATA u32 gUnknown_03000D54;
IWRAM_DATA u8 gUnknown_03000D58;
IWRAM_DATA u32 gUnknown_03000D5C;
IWRAM_DATA u32 gUnknown_03000D60;
IWRAM_DATA u8 gUnknown_03000D64;
ALIGNED() IWRAM_DATA u8 gUnknown_03000D68[MAX_LINK_PLAYERS];
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

u16 gUnknown_03003020[6];
u32 gUnknown_0300302C;
struct LinkPlayerBlock gUnknown_03003030;
bool8 gUnknown_0300306C;
u32 gUnknown_03003070;
bool8 gUnknown_03003078[MAX_LINK_PLAYERS];
u8 gUnknown_0300307C[MAX_LINK_PLAYERS];
u16 gUnknown_03003084;
u16 gUnknown_03003090[MAX_LINK_PLAYERS][8];
u32 gUnknown_030030E0;
u8 gUnknown_030030E4;
bool8 gUnknown_030030E8;
u8 gUnknown_030030EC[MAX_LINK_PLAYERS];
u8 gUnknown_030030F0[MAX_LINK_PLAYERS];
u16 gUnknown_030030F4;
u8 gUnknown_030030F8;
bool8 gLinkVSyncDisabled;
bool8 gUnknown_03003100;
u16 gUnknown_03003110[8];
u8 gUnknown_03003120;
bool8 gReceivedRemoteLinkPlayers;
struct LinkTestBGInfo gUnknown_03003130;
void (*gUnknown_03003140)(void);
bool8 gUnknown_03003144;
u16 gUnknown_03003148[MAX_LINK_PLAYERS];
u8 gUnknown_03003150;
u8 gUnknown_03003160;

EWRAM_DATA u8 gUnknown_020223BC = 0;
EWRAM_DATA u8 gUnknown_020223BD = 0;
EWRAM_DATA u32 gUnknown_020223C0 = 0;
EWRAM_DATA u16 gBlockRecvBuffer[MAX_LINK_PLAYERS + 1][BLOCK_BUFFER_SIZE / 2] = {};
EWRAM_DATA u8 gUnknown_020228C4[BLOCK_BUFFER_SIZE] = {};
EWRAM_DATA bool8 gUnknown_020229C4 = FALSE;
EWRAM_DATA u16 gUnknown_020229C6 = 0;
EWRAM_DATA u16 gUnknown_020229C8 = 0;
EWRAM_DATA struct LinkPlayer gUnknown_020229CC = {};
EWRAM_DATA struct LinkPlayer gLinkPlayers[MAX_LINK_PLAYERS + 1] = {};
EWRAM_DATA struct LinkPlayer gUnknown_02022A74[MAX_LINK_PLAYERS + 1] = {};

// Static ROM declarations

void sub_8009638(void);
void sub_80096BC(void);
static void c2_08009A8C(void);
static void sub_8009AA0(u8 unused);
static void sub_8009F70(void);
static void sub_800A2E0(void);
bool32 sub_800A2F4(const void *src, size_t size);
static void sub_800A364(void);
static void sub_800A388(void);
static void sub_800A3EC(void);
void task00_link_test(u8 taskId);
void sub_800A588(u8 who);
u16 sub_800A648(u16 *src, u16 size);
void sub_800A6E8(u32 pos, u8 a0, u8 a1, u8 a2);
void sub_800A824(void);
void c2_800ACD4(void);
void sub_800AEB4(void);
void sub_800B330(bool8 flag);
void sub_800B4A4(void);
void sub_800B524(struct LinkPlayer *linkPlayer);
void sub_800B53C(void);
void sub_800B594(void);

// rfu
u32 sub_800BEC0(void);
void sub_800E700(void);
void sub_800EDD4(void);
bool32 sub_800F7E4(void);
void sub_800F804(void);
void sub_800F850(void);
void Rfu_set_zero(void);
u8 sub_80104F4(void);

// .rodata

ALIGNED(4) const u16 gWirelessLinkDisplayPal[] = INCBIN_U16("graphics/interface/wireless_link_display.gbapal");
const u8 gWirelessLinkDisplayGfx[] = INCBIN_U8("graphics/interface/wireless_link_display.4bpp.lz");
const u8 gWirelessLinkDisplayTilemap[] = INCBIN_U8("graphics/interface/wireless_link_display.bin.lz");
const u16 gLinkTestDigitsPal[] = INCBIN_U16("graphics/interface/link_test_digits.gbapal");
const u16 gLinkTestDigitsGfx[] = INCBIN_U16("graphics/interface/link_test_digits.4bpp");
const u8 unkstring_82ed160[] = _("{HIGHLIGHT TRANSPARENT}{COLOR WHITE}");
const u16 g2BlankTilesGfx[] = INCBIN_U16("graphics/interface/blank_1x2.4bpp");
const struct BlockRequest gUnknown_082ED1A8[] = {
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
const char gASCIIGameFreakInc[] = "GameFreak inc.";
const char gASCIITestPrint[] = "TEST PRINT\nP0\nP1\nP2\nP3";
const struct BgTemplate gUnknown_082ED1FC[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .priority = 1
    }
};
const struct WindowTemplate gUnknown_082ED204[] = {
    {0x00, 0x00, 0x00, 0x1E, 0x05, 0x0F, 0x0002},
    {0x00, 0x00, 0x06, 0x1E, 0x07, 0x0F, 0x0098},
    {0x00, 0x00, 0x0D, 0x1E, 0x07, 0x0F, 0x016A},
    DUMMY_WIN_TEMPLATE
};
const u8 gUnknown_082ED224[] = {
    0x00, 0x01, 0x02, 0x00,
    0xff, 0xfe, 0xff, 0x00
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
    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
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
    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        gUnknown_03003078[i] = 1;
        gUnknown_030030F0[i] = 0;
        gUnknown_030030EC[i] = 0;
    }
}

void sub_80097E8(void)
{
    gReceivedRemoteLinkPlayers = FALSE;
    if (gLinkVSyncDisabled)
    {
        sub_800EDD4();
    }
    gUnknown_020229C4 = FALSE;
    sub_800B53C();
}

static void sub_8009818(u8 nothing, u8 is, u8 used)
{
    u8 i;
    u8 status;

    if (gUnknown_03000D64 != gUnknown_03000D10.pos)
    {
        sub_800A6E8(gUnknown_03000D10.pos, 2, 3, 2);
        gUnknown_03000D64 = gUnknown_03000D10.pos;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        if (gUnknown_03000D68[i] != gUnknown_03000D20[i].pos)
        {
            sub_800A6E8(gUnknown_03000D20[i].pos, 2, i + 4, 2);
            gUnknown_03000D68[i] = gUnknown_03000D20[i].pos;
        }
    }
    status = GetBlockReceivedStatus();
    if (status == 0xF) // 0b1111
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i ++)
        {
            if ((status >> i) & 1)
            {
                gUnknown_03003148[i] = sub_800A648(gBlockRecvBuffer[i], gUnknown_03000D20[i].size);
                ResetBlockReceivedFlag(i);
                if (gUnknown_03003148[i] != 0x0342)
                {
                    gUnknown_020223BC = 0;
                    gUnknown_020223BD = 0;
                }
            }
        }
    }
}

void sub_8009900(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        gUnknown_03003144 = TRUE;
    }
    if (gMain.heldKeys & B_BUTTON)
    {
        sub_800A2F4(gHeap + 0x4000, 0x00002004);
    }
    if (gMain.newKeys & L_BUTTON)
    {
        BeginNormalPaletteFade(-1, 0, 16, 0, 2);
    }
    if (gMain.newKeys & START_BUTTON)
    {
        sub_800B330(1);
    }
    if (gMain.newKeys & R_BUTTON)
    {
        TrySavingData(1);
    }
    if (gMain.newKeys & SELECT_BUTTON)
    {
        sub_800AC34();
    }
    if (gUnknown_020223BC)
    {
        sub_800A994(gMain.vblankCounter2, gUnknown_03003140 ? gUnknown_03002748 : gUnknown_03002748 | 0x10);
    }
}

static void c2_08009A8C(void)
{
    sub_8009900();
    sub_8009818(1, 1, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

u16 sub_80099E0(const u16 *src)
{
    u8 i;

    if (!gUnknown_020229C4)
    {
        return 0;
    }
    for (i = 0; i < 8; i ++)
    {
        gUnknown_03003110[i] = 0;
    }
    gUnknown_03003084 = *src;
    if (gUnknown_030030E0 & 0x40)
    {
        sub_8009AA0(REG_SIOCNT_STRUCT.cnt0_2);
        if (gUnknown_03003140 != NULL)
        {
            gUnknown_03003140();
        }
        sub_800AEB4();
    }
    return gUnknown_030030E0;
}

void sub_8009A58(u8 who)
{
    int i;
    int count;

    count = 0;
    gUnknown_03003078[who] = FALSE;
    for (i = 0; i < sub_800ABAC(); i ++)
    {
        count += gUnknown_03003078[i];
    }
    if (count == 0 && gReceivedRemoteLinkPlayers == 0)
    {
        gReceivedRemoteLinkPlayers = 1;
    }
}

static void sub_8009AA0(u8 unused)
{
    u16 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        gUnknown_03003020[i] = 0;
        if (gUnknown_03003090[i][0] == 0)
        {
            continue;
        }
        switch (gUnknown_03003090[i][0])
        {
            case 0x2222:
            {
                struct LinkPlayerBlock *block;

                sub_8009638();
                block = &gUnknown_03003030;
                block->linkPlayer = gUnknown_020229CC;
                memcpy(block->magic1, gASCIIGameFreakInc, sizeof(block->magic1) - 1);
                memcpy(block->magic2, gASCIIGameFreakInc, sizeof(block->magic2) - 1);
                sub_800A2F4(block, sizeof(*block));
                break;
            }
            case 0x4444:
                gUnknown_03003020[i] = gUnknown_03003090[i][1];
                break;
            case 0x5555:
                gUnknown_030030E8 = 1;
                break;
            case 0x5566:
                gUnknown_030030E8 = 1;
                break;
            case 0xBBBB:
            {
                struct BlockTransfer *blockRecv;

                blockRecv = &gUnknown_03000D20[i];
                blockRecv->pos = 0;
                blockRecv->size = gUnknown_03003090[i][1];
                blockRecv->multiplayerId = gUnknown_03003090[i][2];
                break;
            }
            case 0x8888:
            {
                if (gUnknown_03000D20[i].size > BLOCK_BUFFER_SIZE)
                {
                    u16 *buffer;
                    u16 j;

                    buffer = (u16 *)gDecompressionBuffer;
                    for (j = 0; j < CMD_LENGTH - 1; j ++)
                    {
                        buffer[(gUnknown_03000D20[i].pos / 2) + j] = gUnknown_03003090[i][j + 1];
                    }
                }
                else
                {
                    u16 j;

                    for (j = 0; j < CMD_LENGTH - 1; j ++)
                    {
                        gBlockRecvBuffer[i][(gUnknown_03000D20[i].pos / 2) + j] = gUnknown_03003090[i][j + 1];
                    }
                }

                gUnknown_03000D20[i].pos += (CMD_LENGTH - 1) * 2;

                if (gUnknown_03000D20[i].pos >= gUnknown_03000D20[i].size)
                {
                    if (gUnknown_03003078[i] == TRUE)
                    {
                        struct LinkPlayerBlock *block;
                        struct LinkPlayer *linkPlayer;

                        block = (struct LinkPlayerBlock *)&gBlockRecvBuffer[i];
                        linkPlayer = &gLinkPlayers[i];
                        *linkPlayer = block->linkPlayer;
                        if ((linkPlayer->version & 0xFF) == VERSION_RUBY || (linkPlayer->version & 0xFF) == VERSION_SAPPHIRE)
                        {
                            linkPlayer->name[10] = 0;
                            linkPlayer->name[9] = 0;
                            linkPlayer->name[8] = 0;
                        }
                        sub_800B524(linkPlayer);
                        if (strcmp(block->magic1, gASCIIGameFreakInc) != 0
                            || strcmp(block->magic2, gASCIIGameFreakInc) != 0)
                        {
                            SetMainCallback2(c2_800ACD4);
                        }
                        else
                        {
                            sub_8009A58(i);
                        }
                    }
                    else
                    {
                        sub_800A588(i);
                    }
                }
            }
                break;
            case 0x5FFF:
                gUnknown_030030F0[i] = 1;
                break;
            case 0x2FFE:
                gUnknown_030030EC[i] = 1;
                break;
            case 0xAAAA:
                sub_800A418();
                break;
            case 0xCCCC:
                SendBlock(0, gUnknown_082ED1A8[gUnknown_03003090[i][1]].address, gUnknown_082ED1A8[gUnknown_03003090[i][1]].size);
                break;
            case 0xCAFE:
                gUnknown_03003020[i] = gUnknown_03003090[i][1];
                break;
        }
    }
}

void sub_8009D90(u16 command)
{
    switch (command)
    {
        case 0x2222:
            gUnknown_03003110[0] = 0x2222;
            gUnknown_03003110[1] = gUnknown_020229C6;
            break;
        case 0x2ffe:
            gUnknown_03003110[0] = 0x2ffe;
            break;
        case 0x4444:
            gUnknown_03003110[0] = 0x4444;
            gUnknown_03003110[1] = gMain.heldKeys;
            break;
        case 0x5555:
            gUnknown_03003110[0] = 0x5555;
            break;
        case 0x6666:
            gUnknown_03003110[0] = 0x6666;
            gUnknown_03003110[1] = 0;
            break;
        case 0x7777:
        {
            u8 i;

            gUnknown_03003110[0] = 0x7777;
            for (i = 0; i < 5; i ++)
            {
                gUnknown_03003110[i + 1] = 0xEE;
            }
            break;
        }
        case 0xbbbb:
            gUnknown_03003110[0] = 0xbbbb;
            gUnknown_03003110[1] = gUnknown_03000D10.size;
            gUnknown_03003110[2] = gUnknown_03000D10.multiplayerId + 0x80;
            break;
        case 0xaaaa:
            gUnknown_03003110[0] = 0xaaaa;
            break;
        case 0xaaab:
            gUnknown_03003110[0] = 0xaaab;
            gUnknown_03003110[1] = gScriptItemId;
            break;
        case 0xcccc:
            gUnknown_03003110[0] = 0xcccc;
            gUnknown_03003110[1] = gUnknown_03003150;
            break;
        case 0x5fff:
            gUnknown_03003110[0] = 0x5fff;
            gUnknown_03003110[1] = gUnknown_030030F4;
            break;
        case 0x5566:
            gUnknown_03003110[0] = 0x5566;
            break;
        case 0xcafe:
            if (gUnknown_03005DA8 == 0 || gUnknown_030022B4)
            {
                break;
            }
            gUnknown_03003110[0] = 0xcafe;
            gUnknown_03003110[1] = gUnknown_03005DA8;
            break;
    }
}

void sub_8009F18(void)
{
    if (gLinkVSyncDisabled)
    {
        sub_800F804();
    }
    gUnknown_03003140 = sub_8009F70;
}

bool32 sub_8009F3C(void)
{
    if (gLinkVSyncDisabled)
    {
        return sub_800F7E4();
    }
    if (gUnknown_03003140 == sub_8009F70)
    {
        return TRUE;
    }
    return FALSE;
}

static void sub_8009F70(void)
{
    if (gReceivedRemoteLinkPlayers == TRUE)
    {
        sub_8009D90(0xcafe);
    }
}

void sub_8009F8C(void)
{
    if (gLinkVSyncDisabled)
    {
        Rfu_set_zero();
    }
    else
    {
        gUnknown_03003140 = NULL;
    }
}

void sub_8009FAC(void)
{
    if (gLinkVSyncDisabled)
    {
        Rfu_set_zero();
    }
    else
    {
        gUnknown_03003140 = NULL;
    }
}

u8 GetLinkPlayerCount(void)
{
    if (gLinkVSyncDisabled)
    {
        return sub_80104F4();
    }
    return EXTRACT_PLAYER_COUNT(gUnknown_030030E0);
}

int sub_8009FF8(u32 version1, u32 version2)
{
    int i;
    u8 nPlayers;

    nPlayers = GetLinkPlayerCount();
    for (i = 0; i < nPlayers; i ++)
    {
        if ((gLinkPlayers[i].version & 0xFF) == version1 || (gLinkPlayers[i].version & 0xFF) == version2)
        {
            return 1;
        }
    }
    return -1;
}

u32 sub_800A03C(void)
{
    return 2;
}

bool32 sub_800A040(void)
{
    if (GetLinkPlayerCount() != 4 || sub_8009FF8(VERSION_RUBY, VERSION_SAPPHIRE) < 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool32 sub_800A064(void)
{
    if (sub_8009FF8(VERSION_RUBY, VERSION_SAPPHIRE) >= 0)
    {
        return TRUE;
    }
    return FALSE;
}

bool32 sub_800A07C(void)
{
    int i;

    i = sub_8009FF8(VERSION_FIRE_RED, VERSION_LEAF_GREEN);
    if (i >= 0 && gLinkPlayers[i].language == LANGUAGE_JAPANESE)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_800A0AC(void)
{
    gUnknown_03000D5C = 0;
    gUnknown_020229C8 = 0;
    sub_8009734();
}

u8 sub_800A0C8(int lower, int upper)
{
    int i;
    int count;
    u32 index;
    u8 cmpVal;
    u32 linkType1;
    u32 linkType2;

    count = 0;
    if (gReceivedRemoteLinkPlayers == TRUE)
    {
        cmpVal = sub_800ABAC();
        if (lower > cmpVal || cmpVal > upper)
        {
            gUnknown_03000D5C = 6;
            return 6;
        }
        else
        {
            if (GetLinkPlayerCount() == 0)
            {
                gUnknown_0300306C = TRUE;
                sub_80097E8();
            }
            for (i = 0, index = 0; i < GetLinkPlayerCount(); index ++, i ++)
            {
                if (gLinkPlayers[index].linkType == gLinkPlayers[0].linkType)
                {
                    count ++;
                }
            }
            if (count == GetLinkPlayerCount())
            {
                if (gLinkPlayers[0].linkType == 0x1133)
                {
                    switch (sub_807A728())
                    {
                        case 1:
                            gUnknown_03000D5C = 4;
                            break;
                        case 2:
                            gUnknown_03000D5C = 5;
                            break;
                        case 0:
                            gUnknown_03000D5C = 1;
                            break;
                    }
                }
                else
                {
                    gUnknown_03000D5C = 1;
                }
            }
            else
            {
                gUnknown_03000D5C = 3;
                linkType1 = gLinkPlayers[GetMultiplayerId()].linkType;
                linkType2 = gLinkPlayers[GetMultiplayerId() ^ 1].linkType;
                if ((linkType1 == 0x2266 && linkType2 == 0x2277) || (linkType1 == 0x2277 && linkType2 == 0x2266))
                {
                    gSpecialVar_0x8005 = 3;
                }
            }
        }
    }
    else if (++ gUnknown_020229C8 > 600)
    {
        gUnknown_03000D5C = 2;
    }
    return gUnknown_03000D5C;
}

bool8 sub_800A23C(void)
{
    u8 i;
    u8 count;
    bool8 retval;

    count = 0;
    for (i = 0; i < GetLinkPlayerCount(); i ++)
    {
        if (gLinkPlayers[i].linkType == gLinkPlayers[0].linkType)
        {
            count ++;
        }
    }
    if (count == GetLinkPlayerCount())
    {
        retval = TRUE;
        gUnknown_03000D5C = 1;
    }
    else
    {
        retval = FALSE;
        gUnknown_03000D5C = 3;
    }
    return retval;
}

u32 GetLinkPlayerTrainerId(u8 who)
{
    return gLinkPlayers[who].trainerId;
}

void sub_800A2BC(void)
{
    int i;

    for (i = 0; i <= MAX_LINK_PLAYERS; i ++)
    {
        gLinkPlayers[i] = (struct LinkPlayer){};
    }
}

static void sub_800A2E0(void)
{
    gUnknown_03000D10.active = FALSE;
    gUnknown_03000D10.pos = 0;
    gUnknown_03000D10.size = 0;
    gUnknown_03000D10.src = NULL;
}

bool32 sub_800A2F4(const void *src, size_t size)
{
    if (gUnknown_03000D10.active)
    {
        return FALSE;
    }
    gUnknown_03000D10.multiplayerId = GetMultiplayerId();
    gUnknown_03000D10.active = TRUE;
    gUnknown_03000D10.size = size;
    gUnknown_03000D10.pos = 0;
    if (size > 0x100)
    {
        gUnknown_03000D10.src = src;
    }
    else
    {
        if (src != gUnknown_020228C4)
        {
            memcpy(gUnknown_020228C4, src, size);
        }
        gUnknown_03000D10.src = gUnknown_020228C4;
    }
    sub_8009D90(0xbbbb);
    gUnknown_03003140 = sub_800A364;
    gUnknown_03000D50 = 0;
    return TRUE;
}

static void sub_800A364(void)
{
    if (++ gUnknown_03000D50 > 2)
    {
        gUnknown_03003140 = sub_800A388;
    }
}

static void sub_800A388(void)
{
    int i;
    const u8 *src;

    src = gUnknown_03000D10.src;
    gUnknown_03003110[0] = 0x8888;
    for (i = 0; i < 7; i ++)
    {
        gUnknown_03003110[i + 1] = (src[gUnknown_03000D10.pos + i * 2 + 1] << 8) | src[gUnknown_03000D10.pos + i * 2];
    }
    gUnknown_03000D10.pos += 14;
    if (gUnknown_03000D10.size <= gUnknown_03000D10.pos)
    {
        gUnknown_03000D10.active = FALSE;
        gUnknown_03003140 = sub_800A3EC;
    }
}

static void sub_800A3EC(void)
{
    gUnknown_03003140 = NULL;
}

void sub_800A3F8(void)
{
    GetMultiplayerId();
    sub_8009D90(0x4444);
    gUnknown_020223C0 ++;
}

void sub_800A418(void)
{
    gUnknown_020223C0 = 0;
    if (gLinkVSyncDisabled)
    {
        sub_800F850();
    }
    else
    {
        gUnknown_03003140 = sub_800A3F8;
    }
}
