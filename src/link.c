
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
#include "battle.h"
#include "link_rfu.h"
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

// Static RAM declarations

IWRAM_DATA struct BlockTransfer sBlockSend;
IWRAM_DATA u32 link_c_unused_03000d1c;
IWRAM_DATA struct BlockTransfer sBlockRecv[MAX_LINK_PLAYERS];
IWRAM_DATA u32 sBlockSendDelayCounter;
IWRAM_DATA u32 gUnknown_03000D54;
IWRAM_DATA u8 gUnknown_03000D58;
IWRAM_DATA u32 sPlayerDataExchangeStatus;
IWRAM_DATA u32 gUnknown_03000D60;
IWRAM_DATA u8 sLinkTestLastBlockSendPos;
ALIGNED() IWRAM_DATA u8 sLinkTestLastBlockRecvPos[MAX_LINK_PLAYERS];
IWRAM_DATA u8 gUnknown_03000D6C;
IWRAM_DATA bool8 gUnknown_03000D6D;
IWRAM_DATA u16 gUnknown_03000D6E;
IWRAM_DATA u16 gUnknown_03000D70;
IWRAM_DATA u8 gUnknown_03000D72;
IWRAM_DATA u8 gUnknown_03000D73;
IWRAM_DATA u8 gUnknown_03000D74;

u16 gUnknown_03003020[6];
u32 gLinkDebugSeed;
struct LinkPlayerBlock gLocalLinkPlayerBlock;
bool8 gLinkErrorOccurred;
u32 gLinkDebugFlags;
u32 gUnknown_03003074;
bool8 gUnknown_03003078[MAX_LINK_PLAYERS];
u8 gUnknown_0300307C[MAX_LINK_PLAYERS];
u32 gFiller_03003080;
u16 gLinkHeldKeys;
u16 gRecvCmds[MAX_RFU_PLAYERS][8];
u32 gLinkStatus;
u8 gUnknown_030030E4;
bool8 gUnknown_030030E8;
u8 gUnknown_030030EC[MAX_LINK_PLAYERS];
u8 gUnknown_030030F0[MAX_LINK_PLAYERS];
u16 gUnknown_030030F4;
u8 gSuppressLinkErrorMessage;
bool8 gSerialIsRFU;
bool8 gSavedLinkPlayerCount;
u16 gSendCmd[8];
u8 gSavedMultiplayerId;
bool8 gReceivedRemoteLinkPlayers;
struct LinkTestBGInfo gLinkTestBGInfo;
void (*gLinkCallback)(void);
bool8 gShouldAdvanceLinkState;
u16 gLinkTestBlockChecksums[MAX_LINK_PLAYERS];
u8 gBlockRequestType;
u32 gFiller_03003154;
u32 gFiller_03003158;
u32 gFiller_0300315c;
u8 gUnknown_03003160;
struct Link gLink;
u8 gUnknown_03004130;
u16 gUnknown_03004134;
u32 gFiller_03004138;
u32 gFiller_0300413C;

EWRAM_DATA u8 gLinkTestDebugValuesEnabled = 0;
EWRAM_DATA u8 gUnknown_020223BD = 0;
EWRAM_DATA u32 gUnknown_020223C0 = 0;
EWRAM_DATA u16 gBlockRecvBuffer[MAX_RFU_PLAYERS][BLOCK_BUFFER_SIZE / 2] = {};
EWRAM_DATA u8 gBlockSendBuffer[BLOCK_BUFFER_SIZE] = {};
EWRAM_DATA bool8 gLinkOpen = FALSE;
EWRAM_DATA u16 gLinkType = 0;
EWRAM_DATA u16 gLinkTimeOutCounter = 0;
EWRAM_DATA struct LinkPlayer gLocalLinkPlayer = {};
EWRAM_DATA struct LinkPlayer gLinkPlayers[MAX_RFU_PLAYERS] = {};
EWRAM_DATA struct LinkPlayer gSavedLinkPlayers[MAX_RFU_PLAYERS] = {};
EWRAM_DATA struct {
    u32 status;
    u8 unk_04;
} gUnknown_02022B00 = {};
EWRAM_DATA u16 gUnknown_02022B08 = 0;
EWRAM_DATA void *gUnknown_02022B0C = NULL;

// Static ROM declarations

void InitLocalLinkPlayer(void);
void sub_80096BC(void);
static void CB2_LinkTest(void);
static void ProcessRecvCmds(u8 unused);
static void sub_8009F70(void);
static void ResetBlockSend(void);
static bool32 InitBlockSend(const void *src, size_t size);
static void LinkCB_BlockSendBegin(void);
static void LinkCB_BlockSend(void);
static void LinkCB_BlockSendEnd(void);
static void SetBlockReceivedFlag(u8 who);
static u16 LinkTestCalcBlockChecksum(const u16 *src, u16 size);
static void LinkTest_prnthex(u32 pos, u8 a0, u8 a1, u8 a2);
static void LinkCB_RequestPlayerDataExchange(void);
static void Task_PrintTestData(u8 taskId);
static void sub_800AC80(void);
static void sub_800ACAC(void);
static void sub_800AD5C(void);
static void sub_800AD88(void);
void sub_800AEB4(void);
u8 sub_800B2F8(void);
void sub_800B4A4(void);
void DisableSerial(void);
void EnableSerial(void);

// .rodata

ALIGNED(4) const u16 gWirelessLinkDisplayPal[] = INCBIN_U16("graphics/interface/wireless_link_display.gbapal");
const u8 gWirelessLinkDisplayGfx[] = INCBIN_U8("graphics/interface/wireless_link_display.4bpp.lz");
const u8 gWirelessLinkDisplayTilemap[] = INCBIN_U8("graphics/interface/wireless_link_display.bin.lz");
const u16 gLinkTestDigitsPal[] = INCBIN_U16("graphics/interface/link_test_digits.gbapal");
const u16 gLinkTestDigitsGfx[] = INCBIN_U16("graphics/interface/link_test_digits.4bpp");
const u8 unkstring_82ed160[] = _("{HIGHLIGHT TRANSPARENT}{COLOR WHITE}");
const u16 g2BlankTilesGfx[] = INCBIN_U16("graphics/interface/blank_1x2.4bpp");
const struct BlockRequest gUnknown_082ED1A8[] = {
    {gBlockSendBuffer, 200},
    {gBlockSendBuffer, 200},
    {gBlockSendBuffer, 100},
    {gBlockSendBuffer, 220},
    {gBlockSendBuffer,  40}
};
const u8 gBGControlRegs[] = {
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
    CloseLink();
    RestoreSerialTimer3IntrHandlers();
    return FALSE;
}

void Task_DestroySelf(u8 taskId)
{
    DestroyTask(taskId);
}

static void InitLinkTestBG(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock, u16 a4)
{
    LoadPalette(gLinkTestDigitsPal, paletteNum * 16, 0x20);
    DmaCopy16(3, gLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(charBaseBlock) + (16 * a4), sizeof gLinkTestDigitsGfx);
    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;
    gLinkTestBGInfo.dummy_8 = a4;
    switch (bgNum)
    {
        case 1:
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
        case 2:
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
        case 3:
            SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
    }
    SetGpuReg(REG_OFFSET_BG0HOFS + bgNum * 4, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS + bgNum * 4, 0);
}

void sub_80094EC(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock)
{
    LoadPalette(gLinkTestDigitsPal, paletteNum * 16, 0x20);
    DmaCopy16(3, gLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(charBaseBlock), sizeof gLinkTestDigitsGfx);
    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;
    gLinkTestBGInfo.dummy_8 = 0;
    SetGpuReg(gBGControlRegs[bgNum], BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_CHARBASE(charBaseBlock));
}

void LinkTestScreen(void)
{
    int i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(sub_80096BC);
    ResetBlockSend();
    gLinkType = 0x1111;
    OpenLink();
    SeedRng(gMain.vblankCounter2);
    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;
    }
    InitLinkTestBG(0, 2, 4, 0, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    CreateTask(Task_DestroySelf, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    gUnknown_03000D60 = 0;
    InitLocalLinkPlayer();
    CreateTask(Task_PrintTestData, 0);
    SetMainCallback2(CB2_LinkTest);
}

void sub_8009628(u8 a0)
{
    gLocalLinkPlayer.lp_field_18 = a0;
}

void InitLocalLinkPlayer(void)
{
    gLocalLinkPlayer.trainerId = gSaveBlock2Ptr->playerTrainerId[0] | (gSaveBlock2Ptr->playerTrainerId[1] << 8) | (gSaveBlock2Ptr->playerTrainerId[2] << 16) | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    StringCopy(gLocalLinkPlayer.name, gSaveBlock2Ptr->playerName);
    gLocalLinkPlayer.gender = gSaveBlock2Ptr->playerGender;
    gLocalLinkPlayer.linkType = gLinkType;
    gLocalLinkPlayer.language = gGameLanguage;
    gLocalLinkPlayer.version = gGameVersion + 0x4000;
    gLocalLinkPlayer.lp_field_2 = 0x8000;
    gLocalLinkPlayer.name[8] = IsNationalPokedexEnabled();
    if (FlagGet(SYS_UNKNOWN_87F))
    {
        gLocalLinkPlayer.name[8] |= 0x10;
    }
}

void sub_80096BC(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void InitLink(void)
{
    int i;

    for (i = 0; i < 8; i ++)
    {
        gSendCmd[i] = 0xefff;
    }
    gLinkOpen = TRUE;
    EnableSerial();
}

void Task_TriggerHandshake(u8 taskId)
{
    if (++ gTasks[taskId].data[0] == 5)
    {
        gShouldAdvanceLinkState = TRUE;
        DestroyTask(taskId);
    }
}

void OpenLink(void)
{
    int i;

    if (!gSerialIsRFU)
    {
        ResetSerial();
        InitLink();
        gLinkCallback = LinkCB_RequestPlayerDataExchange;
        gLinkVSyncDisabled = FALSE;
        gLinkErrorOccurred = FALSE;
        gSuppressLinkErrorMessage = FALSE;
        ResetBlockReceivedFlags();
        ResetBlockSend();
        gUnknown_03000D54 = 0;
        gUnknown_030030E8 = 0;
        gUnknown_030030E4 = 0;
        gUnknown_030030F4 = 0;
        CreateTask(Task_TriggerHandshake, 2);
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

void CloseLink(void)
{
    gReceivedRemoteLinkPlayers = FALSE;
    if (gSerialIsRFU)
    {
        sub_800EDD4();
    }
    gLinkOpen = FALSE;
    DisableSerial();
}

static void TestBlockTransfer(u8 nothing, u8 is, u8 used)
{
    u8 i;
    u8 status;

    if (sLinkTestLastBlockSendPos != sBlockSend.pos)
    {
        LinkTest_prnthex(sBlockSend.pos, 2, 3, 2);
        sLinkTestLastBlockSendPos = sBlockSend.pos;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        if (sLinkTestLastBlockRecvPos[i] != sBlockRecv[i].pos)
        {
            LinkTest_prnthex(sBlockRecv[i].pos, 2, i + 4, 2);
            sLinkTestLastBlockRecvPos[i] = sBlockRecv[i].pos;
        }
    }
    status = GetBlockReceivedStatus();
    if (status == 0xF) // 0b1111
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i ++)
        {
            if ((status >> i) & 1)
            {
                gLinkTestBlockChecksums[i] = LinkTestCalcBlockChecksum(gBlockRecvBuffer[i], sBlockRecv[i].size);
                ResetBlockReceivedFlag(i);
                if (gLinkTestBlockChecksums[i] != 0x0342)
                {
                    gLinkTestDebugValuesEnabled = FALSE;
                    gUnknown_020223BD = FALSE;
                }
            }
        }
    }
}

void LinkTestProcessKeyInput(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        gShouldAdvanceLinkState = TRUE;
    }
    if (gMain.heldKeys & B_BUTTON)
    {
        InitBlockSend(gHeap + 0x4000, 0x00002004);
    }
    if (gMain.newKeys & L_BUTTON)
    {
        BeginNormalPaletteFade(-1, 0, 16, 0, 2);
    }
    if (gMain.newKeys & START_BUTTON)
    {
        SetSuppressLinkErrorMessage(TRUE);
    }
    if (gMain.newKeys & R_BUTTON)
    {
        TrySavingData(1);
    }
    if (gMain.newKeys & SELECT_BUTTON)
    {
        sub_800AC34();
    }
    if (gLinkTestDebugValuesEnabled)
    {
        SetLinkDebugValues(gMain.vblankCounter2, gLinkCallback ? gLinkVSyncDisabled : gLinkVSyncDisabled | 0x10);
    }
}

static void CB2_LinkTest(void)
{
    LinkTestProcessKeyInput();
    TestBlockTransfer(1, 1, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

u16 LinkMain2(const u16 *heldKeys)
{
    u8 i;

    if (!gLinkOpen)
    {
        return 0;
    }
    for (i = 0; i < 8; i ++)
    {
        gSendCmd[i] = 0;
    }
    gLinkHeldKeys = *heldKeys;
    if (gLinkStatus & LINK_STAT_CONN_ESTABLISHED)
    {
        ProcessRecvCmds(SIO_MULTI_CNT->id);
        if (gLinkCallback != NULL)
        {
            gLinkCallback();
        }
        sub_800AEB4();
    }
    return gLinkStatus;
}

void HandleReceiveRemoteLinkPlayer(u8 who)
{
    int i;
    int count;

    count = 0;
    gUnknown_03003078[who] = FALSE;
    for (i = 0; i < GetLinkPlayerCount_2(); i ++)
    {
        count += gUnknown_03003078[i];
    }
    if (count == 0 && gReceivedRemoteLinkPlayers == 0)
    {
        gReceivedRemoteLinkPlayers = 1;
    }
}

static void ProcessRecvCmds(u8 unused)
{
    u16 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i ++)
    {
        gUnknown_03003020[i] = 0;
        if (gRecvCmds[i][0] == 0)
        {
            continue;
        }
        switch (gRecvCmds[i][0])
        {
            case 0x2222:
            {
                struct LinkPlayerBlock *block;

                InitLocalLinkPlayer();
                block = &gLocalLinkPlayerBlock;
                block->linkPlayer = gLocalLinkPlayer;
                memcpy(block->magic1, gASCIIGameFreakInc, sizeof(block->magic1) - 1);
                memcpy(block->magic2, gASCIIGameFreakInc, sizeof(block->magic2) - 1);
                InitBlockSend(block, sizeof(*block));
                break;
            }
            case 0x4444:
                gUnknown_03003020[i] = gRecvCmds[i][1];
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

                blockRecv = &sBlockRecv[i];
                blockRecv->pos = 0;
                blockRecv->size = gRecvCmds[i][1];
                blockRecv->multiplayerId = gRecvCmds[i][2];
                break;
            }
            case 0x8888:
            {
                if (sBlockRecv[i].size > BLOCK_BUFFER_SIZE)
                {
                    u16 *buffer;
                    u16 j;

                    buffer = (u16 *)gDecompressionBuffer;
                    for (j = 0; j < CMD_LENGTH - 1; j ++)
                    {
                        buffer[(sBlockRecv[i].pos / 2) + j] = gRecvCmds[i][j + 1];
                    }
                }
                else
                {
                    u16 j;

                    for (j = 0; j < CMD_LENGTH - 1; j ++)
                    {
                        gBlockRecvBuffer[i][(sBlockRecv[i].pos / 2) + j] = gRecvCmds[i][j + 1];
                    }
                }

                sBlockRecv[i].pos += (CMD_LENGTH - 1) * 2;

                if (sBlockRecv[i].pos >= sBlockRecv[i].size)
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
                            SetMainCallback2(CB2_LinkError);
                        }
                        else
                        {
                            HandleReceiveRemoteLinkPlayer(i);
                        }
                    }
                    else
                    {
                        SetBlockReceivedFlag(i);
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
                SendBlock(0, gUnknown_082ED1A8[gRecvCmds[i][1]].address, gUnknown_082ED1A8[gRecvCmds[i][1]].size);
                break;
            case 0xCAFE:
                gUnknown_03003020[i] = gRecvCmds[i][1];
                break;
        }
    }
}

void BuildSendCmd(u16 command)
{
    switch (command)
    {
        case 0x2222:
            gSendCmd[0] = 0x2222;
            gSendCmd[1] = gLinkType;
            break;
        case 0x2ffe:
            gSendCmd[0] = 0x2ffe;
            break;
        case 0x4444:
            gSendCmd[0] = 0x4444;
            gSendCmd[1] = gMain.heldKeys;
            break;
        case 0x5555:
            gSendCmd[0] = 0x5555;
            break;
        case 0x6666:
            gSendCmd[0] = 0x6666;
            gSendCmd[1] = 0;
            break;
        case 0x7777:
        {
            u8 i;

            gSendCmd[0] = 0x7777;
            for (i = 0; i < 5; i ++)
            {
                gSendCmd[i + 1] = 0xEE;
            }
            break;
        }
        case 0xbbbb:
            gSendCmd[0] = 0xbbbb;
            gSendCmd[1] = sBlockSend.size;
            gSendCmd[2] = sBlockSend.multiplayerId + 0x80;
            break;
        case 0xaaaa:
            gSendCmd[0] = 0xaaaa;
            break;
        case 0xaaab:
            gSendCmd[0] = 0xaaab;
            gSendCmd[1] = gScriptItemId;
            break;
        case 0xcccc:
            gSendCmd[0] = 0xcccc;
            gSendCmd[1] = gBlockRequestType;
            break;
        case 0x5fff:
            gSendCmd[0] = 0x5fff;
            gSendCmd[1] = gUnknown_030030F4;
            break;
        case 0x5566:
            gSendCmd[0] = 0x5566;
            break;
        case 0xcafe:
            if (gUnknown_03005DA8 == 0 || gLinkTransferringData)
            {
                break;
            }
            gSendCmd[0] = 0xcafe;
            gSendCmd[1] = gUnknown_03005DA8;
            break;
    }
}

void sub_8009F18(void)
{
    if (gSerialIsRFU)
    {
        sub_800F804();
    }
    gLinkCallback = sub_8009F70;
}

bool32 sub_8009F3C(void)
{
    if (gSerialIsRFU)
    {
        return sub_800F7E4();
    }
    if (gLinkCallback == sub_8009F70)
    {
        return TRUE;
    }
    return FALSE;
}

static void sub_8009F70(void)
{
    if (gReceivedRemoteLinkPlayers == TRUE)
    {
        BuildSendCmd(0xcafe);
    }
}

void ClearLinkCallback(void)
{
    if (gSerialIsRFU)
    {
        Rfu_set_zero();
    }
    else
    {
        gLinkCallback = NULL;
    }
}

void ClearLinkCallback_2(void)
{
    if (gSerialIsRFU)
    {
        Rfu_set_zero();
    }
    else
    {
        gLinkCallback = NULL;
    }
}

u8 GetLinkPlayerCount(void)
{
    if (gSerialIsRFU)
    {
        return sub_80104F4();
    }
    return EXTRACT_PLAYER_COUNT(gLinkStatus);
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

void OpenLinkTimed(void)
{
    sPlayerDataExchangeStatus = EXCHANGE_NOT_STARTED;
    gLinkTimeOutCounter = 0;
    OpenLink();
}

u8 GetLinkPlayerDataExchangeStatusTimed(int lower, int upper)
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
        cmpVal = GetLinkPlayerCount_2();
        if (lower > cmpVal || cmpVal > upper)
        {
            sPlayerDataExchangeStatus = EXCHANGE_STAT_6;
            return 6;
        }
        else
        {
            if (GetLinkPlayerCount() == 0)
            {
                gLinkErrorOccurred = TRUE;
                CloseLink();
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
                            sPlayerDataExchangeStatus = EXCHANGE_STAT_4;
                            break;
                        case 2:
                            sPlayerDataExchangeStatus = EXCHANGE_STAT_5;
                            break;
                        case 0:
                            sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
                            break;
                    }
                }
                else
                {
                    sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
                }
            }
            else
            {
                sPlayerDataExchangeStatus = EXCHANGE_IN_PROGRESS;
                linkType1 = gLinkPlayers[GetMultiplayerId()].linkType;
                linkType2 = gLinkPlayers[GetMultiplayerId() ^ 1].linkType;
                if ((linkType1 == 0x2266 && linkType2 == 0x2277) || (linkType1 == 0x2277 && linkType2 == 0x2266))
                {
                    gSpecialVar_0x8005 = 3;
                }
            }
        }
    }
    else if (++ gLinkTimeOutCounter > 600)
    {
        sPlayerDataExchangeStatus = EXCHANGE_TIMED_OUT;
    }
    return sPlayerDataExchangeStatus;
}

bool8 IsLinkPlayerDataExchangeComplete(void)
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
        sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
    }
    else
    {
        retval = FALSE;
        sPlayerDataExchangeStatus = EXCHANGE_IN_PROGRESS;
    }
    return retval;
}

u32 GetLinkPlayerTrainerId(u8 who)
{
    return gLinkPlayers[who].trainerId;
}

void ResetLinkPlayers(void)
{
    int i;

    for (i = 0; i <= MAX_LINK_PLAYERS; i ++)
    {
        gLinkPlayers[i] = (struct LinkPlayer){};
    }
}

static void ResetBlockSend(void)
{
    sBlockSend.active = FALSE;
    sBlockSend.pos = 0;
    sBlockSend.size = 0;
    sBlockSend.src = NULL;
}

static bool32 InitBlockSend(const void *src, size_t size)
{
    if (sBlockSend.active)
    {
        return FALSE;
    }
    sBlockSend.multiplayerId = GetMultiplayerId();
    sBlockSend.active = TRUE;
    sBlockSend.size = size;
    sBlockSend.pos = 0;
    if (size > 0x100)
    {
        sBlockSend.src = src;
    }
    else
    {
        if (src != gBlockSendBuffer)
        {
            memcpy(gBlockSendBuffer, src, size);
        }
        sBlockSend.src = gBlockSendBuffer;
    }
    BuildSendCmd(0xbbbb);
    gLinkCallback = LinkCB_BlockSendBegin;
    sBlockSendDelayCounter = 0;
    return TRUE;
}

static void LinkCB_BlockSendBegin(void)
{
    if (++ sBlockSendDelayCounter > 2)
    {
        gLinkCallback = LinkCB_BlockSend;
    }
}

static void LinkCB_BlockSend(void)
{
    int i;
    const u8 *src;

    src = sBlockSend.src;
    gSendCmd[0] = 0x8888;
    for (i = 0; i < 7; i ++)
    {
        gSendCmd[i + 1] = (src[sBlockSend.pos + i * 2 + 1] << 8) | src[sBlockSend.pos + i * 2];
    }
    sBlockSend.pos += 14;
    if (sBlockSend.size <= sBlockSend.pos)
    {
        sBlockSend.active = FALSE;
        gLinkCallback = LinkCB_BlockSendEnd;
    }
}

static void LinkCB_BlockSendEnd(void)
{
    gLinkCallback = NULL;
}

static void sub_800A3F8(void)
{
    GetMultiplayerId();
    BuildSendCmd(0x4444);
    gUnknown_020223C0 ++;
}

void sub_800A418(void)
{
    gUnknown_020223C0 = 0;
    if (gSerialIsRFU)
    {
        sub_800F850();
    }
    else
    {
        gLinkCallback = sub_800A3F8;
    }
}

u32 sub_800A44C(void)
{
    return gUnknown_020223C0;
}

void sub_800A458(void)
{
    BuildSendCmd(0xaaaa);
}

u8 GetMultiplayerId(void)
{
    if (gSerialIsRFU == TRUE)
    {
        return rfu_get_multiplayer_id();
    }
    return SIO_MULTI_CNT->id;
}

u8 bitmask_all_link_players_but_self(void)
{
    u8 mpId;

    mpId = GetMultiplayerId();
    return ((1 << MAX_LINK_PLAYERS) - 1) ^ (1 << mpId);
}

bool8 SendBlock(u8 unused, const void *src, u16 size)
{
    if (gSerialIsRFU == TRUE)
    {
        return sub_800FE84(src, size);
    }
    return InitBlockSend(src, size);
}

bool8 sub_800A4D8(u8 a0)
{
    if (gSerialIsRFU == TRUE)
    {
        return sub_8010100(a0);
    }
    if (gLinkCallback == NULL)
    {
        gBlockRequestType = a0;
        BuildSendCmd(0xcccc);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_800A520(void)
{
    if (gSerialIsRFU == TRUE)
    {
        return sub_8010500();
    }
    return gLinkCallback == NULL;
}

u8 GetBlockReceivedStatus(void)
{
    if (gSerialIsRFU == TRUE)
    {
        return sub_800FCD8();
    }
    return (gUnknown_0300307C[3] << 3) | (gUnknown_0300307C[2] << 2) | (gUnknown_0300307C[1] << 1) | (gUnknown_0300307C[0] << 0);
}

static void SetBlockReceivedFlag(u8 who)
{
    if (gSerialIsRFU == TRUE)
    {
        sub_800F6FC(who);
    }
    else
    {
        gUnknown_0300307C[who] = TRUE;
    }
}

void ResetBlockReceivedFlags(void)
{
    int i;
    
    if (gSerialIsRFU == TRUE)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i ++)
        {
            sub_800F728(i);
        }
    }
    else
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i ++)
        {
            gUnknown_0300307C[i] = FALSE;
        }
    }
}

void ResetBlockReceivedFlag(u8 who)
{
    if (gSerialIsRFU == TRUE)
    {
        sub_800F728(who);
    }
    else if (gUnknown_0300307C[who])
    {
        gUnknown_0300307C[who] = FALSE;
    }
}

void sub_800A620(void)
{
    if ((gLinkStatus & LINK_STAT_MASTER) && EXTRACT_PLAYER_COUNT(gLinkStatus) > 1)
    {
        gShouldAdvanceLinkState = TRUE;
    }
}

static u16 LinkTestCalcBlockChecksum(const u16 *src, u16 size)
{
    u16 chksum;
    u16 i;

    chksum = 0;
    for (i = 0; i < size / 2; i ++)
    {
        chksum += src[i];
    }
    return chksum;
}

static void LinkTest_prnthexchar(char a0, u8 a1, u8 a2)
{
    u16 *vAddr;

    vAddr = (u16 *)BG_SCREEN_ADDR(gLinkTestBGInfo.screenBaseBlock);
    vAddr[a2 * 32 + a1] = (gLinkTestBGInfo.paletteNum << 12) | (a0 + 1 + gLinkTestBGInfo.dummy_8);
}

static void LinkTest_prntchar(char a0, u8 a1, u8 a2)
{
    u16 *vAddr;

    vAddr = (u16 *)BG_SCREEN_ADDR(gLinkTestBGInfo.screenBaseBlock);
    vAddr[a2 * 32 + a1] = (gLinkTestBGInfo.paletteNum << 12) | (a0 + gLinkTestBGInfo.dummy_8);
}

static void LinkTest_prnthex(u32 pos, u8 a0, u8 a1, u8 a2)
{
    char sp[32 / 2];
    int i;

    for (i = 0; i < a2; i ++)
    {
        sp[i] = pos & 0xf;
        pos >>= 4;
    }
    for (i = a2 - 1; i >= 0; i --)
    {
        LinkTest_prnthexchar(sp[i], a0, a1);
        a0 ++;
    }
}

static void LinkTest_prntint(int a0, u8 a1, u8 a2, u8 a3)
{
    char sp[32 / 2];
    int sp10;
    int i;

    sp10 = -1;
    if (a0 < 0)
    {
        sp10 = a1;
        a0 = -a0;
    }
    for (i = 0; i < a3; i ++)
    {
        sp[i] = a0 % 10;
        a0 /= 10;
    }
    for (i = a3 - 1; i >= 0; i --)
    {
        LinkTest_prnthexchar(sp[i], a1, a2);
        a1 ++;
    }
    if (sp10 != -1)
    {
        LinkTest_prnthexchar(*"\n", sp10, a2);
    }
}

static void LinkTest_prntstr(const char *a0, u8 a1, u8 a2)
{
    int r6;
    int i;
    int r5;

    r5 = 0;
    r6 = 0;
    for (i = 0; a0[i] != 0; a0 ++)
    {
        if (a0[i] == *"\n")
        {
            r5 ++;
            r6 = 0;
        }
        else
        {
            LinkTest_prntchar(a0[i], a1 + r6, a2 + r5);
            r6 ++;
        }
    }
}

static void LinkCB_RequestPlayerDataExchange(void)
{
    if (gLinkStatus & LINK_STAT_MASTER)
    {
        BuildSendCmd(0x2222);
    }
    gLinkCallback = NULL;
}

static void Task_PrintTestData(u8 taskId)
{
    char sp[32];
    int i;

    strcpy(sp, gASCIITestPrint);
    LinkTest_prntstr(sp, 5, 2);
    LinkTest_prnthex(gShouldAdvanceLinkState, 2, 1, 2);
    LinkTest_prnthex(gLinkStatus, 15, 1, 8);
    LinkTest_prnthex(gLink.state, 2, 10, 2);
    LinkTest_prnthex(EXTRACT_PLAYER_COUNT(gLinkStatus), 15, 10, 2);
    LinkTest_prnthex(GetMultiplayerId(), 15, 12, 2);
    LinkTest_prnthex(gUnknown_03003160, 25, 1, 2);
    LinkTest_prnthex(gUnknown_03004130, 25, 2, 2);
    LinkTest_prnthex(GetBlockReceivedStatus(), 15, 5, 2);
    LinkTest_prnthex(gLinkDebugSeed, 2, 12, 8);
    LinkTest_prnthex(gLinkDebugFlags, 2, 13, 8);
    LinkTest_prnthex(sub_800B2E8(), 25, 5, 1);
    LinkTest_prnthex(sub_800B2F8(), 25, 6, 1);
    LinkTest_prnthex(sub_800B320(), 25, 7, 1);
    LinkTest_prnthex(sub_800B33C(), 25, 8, 1);
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        LinkTest_prnthex(gLinkTestBlockChecksums[i], 10, 4 + i, 4);
    }
}

void SetLinkDebugValues(u32 seed, u32 flags)
{
    gLinkDebugSeed = seed;
    gLinkDebugFlags = flags;
}

u8 sub_800A9A8(void)
{
    int i;
    u8 flags;

    flags = 0;
    for (i = 0; i < gSavedLinkPlayerCount; i ++)
    {
        flags |= (1 << i);
    }
    return flags;
}

u8 sub_800A9D8(void)
{
    int i;
    u8 flags;

    flags = 0;
    for (i = 0; i < GetLinkPlayerCount(); i ++)
    {
        flags |= (1 << i);
    }
    return flags;
}

void sub_800AA04(u8 a0)
{
    int i;

    gSavedLinkPlayerCount = a0;
    gSavedMultiplayerId = GetMultiplayerId();
    for (i = 0; i < MAX_RFU_PLAYERS; i ++)
    {
        gSavedLinkPlayers[i] = gLinkPlayers[i];
    }
}

u8 sub_800AA48(void)
{
    return gSavedLinkPlayerCount;
}

u8 sub_800AA54(void)
{
    return gSavedMultiplayerId;
}

bool8 sub_800AA60(void)
{
    int i;
    unsigned count;

    count = 0;
    for (i = 0; i < gSavedLinkPlayerCount; i ++)
    {
        if (gLinkPlayers[i].trainerId == gSavedLinkPlayers[i].trainerId)
        {
            if (gLinkType == 0x2288)
            {
                if (gLinkType == gLinkPlayers[i].linkType)
                {
                    count ++;
                }
            }
            else
            {
                count ++;
            }
        }
    }
    if (count == gSavedLinkPlayerCount)
    {
        if (GetLinkPlayerCount_2() == gSavedLinkPlayerCount)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_800AAF4(void)
{
    int i;

    // Clearly not what was meant to be written, but here it is anyway.
    for (i = 0; i < 4; i ++)
    {
        CpuSet(&gSavedLinkPlayers[i], NULL, sizeof(struct LinkPlayer));
    }
}

void sub_800AB18(void)
{
    u8 i;

    for (i = 0; i < gSavedLinkPlayerCount; i ++)
    {
        if (gSavedLinkPlayers[i].trainerId != gLinkPlayers[i].trainerId || StringCompare(gSavedLinkPlayers[i].name, gLinkPlayers[i].name) != 0)
        {
            gLinkErrorOccurred = TRUE;
            CloseLink();
            SetMainCallback2(CB2_LinkError);
        }
    }
}

void sub_800AB98(void)
{
    gSavedLinkPlayerCount = 0;
    gSavedMultiplayerId = 0;
}

u8 GetLinkPlayerCount_2(void)
{
    return EXTRACT_PLAYER_COUNT(gLinkStatus);
}

bool8 IsLinkMaster(void)
{
    if (gSerialIsRFU)
    {
        return Rfu_IsMaster();
    }
    return EXTRACT_MASTER(gLinkStatus);
}

u8 sub_800ABE8(void)
{
    return gUnknown_03000D58;
}

void sub_800ABF4(u16 a0)
{
    if (gSerialIsRFU == TRUE)
    {
        task_add_05_task_del_08FA224_when_no_RfuFunc();
    }
    else
    {
        if (gLinkCallback == NULL)
        {
            gLinkCallback = sub_800AC80;
            gUnknown_030030E4 = 0;
            gUnknown_030030F4 = a0;
        }
    }
}

void sub_800AC34(void)
{
    if (gSerialIsRFU == TRUE)
    {
        task_add_05_task_del_08FA224_when_no_RfuFunc();
    }
    else
    {
        if (gLinkCallback != NULL)
        {
            gUnknown_02022B08 ++;
        }
        else
        {
            gLinkCallback = sub_800AC80;
            gUnknown_030030E4 = 0;
            gUnknown_030030F4 = 0;
        }
    }
}

static void sub_800AC80(void)
{
    if (gUnknown_03004130 == 0)
    {
        BuildSendCmd(0x5fff);
        gLinkCallback = sub_800ACAC;
    }
}

static void sub_800ACAC(void)
{
    int i;
    unsigned count;
    u8 linkPlayerCount;

    linkPlayerCount = GetLinkPlayerCount();
    count = 0;
    for (i = 0; i < linkPlayerCount; i ++)
    {
        if (gUnknown_030030F0[i])
        {
            count ++;
        }
    }
    if (count == linkPlayerCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        gLinkVSyncDisabled = TRUE;
        CloseLink();
        gLinkCallback = NULL;
        gUnknown_030030E4 = 1;
    }
}

void sub_800AD10(void)
{
    if (gSerialIsRFU == TRUE)
    {
        task_add_05_task_del_08FA224_when_no_RfuFunc();
    }
    else
    {
        if (gLinkCallback != NULL)
        {
            gUnknown_02022B08 ++;
        }
        else
        {
            gLinkCallback = sub_800AD5C;
            gUnknown_030030E4 = 0;
            gUnknown_030030F4 = 0;
        }
    }
}

static void sub_800AD5C(void)
{
    if (gUnknown_03004130 == 0)
    {
        BuildSendCmd(0x5fff);
        gLinkCallback = sub_800AD88;
    }
}

static void sub_800AD88(void)
{
    int i;
    unsigned count;
    u8 linkPlayerCount;

    linkPlayerCount = GetLinkPlayerCount();
    count = 0;
    for (i = 0; i < linkPlayerCount; i ++)
    {
        if (gLinkPlayers[i].language == LANGUAGE_JAPANESE)
        {
            count ++;
        }
        else if (gUnknown_030030F0[i])
        {
            count ++;
        }
    }
    if (count == linkPlayerCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        gLinkVSyncDisabled = TRUE;
        CloseLink();
        gLinkCallback = NULL;
        gUnknown_030030E4 = 1;
    }
}
