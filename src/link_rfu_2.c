#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "berry_blender.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "overworld.h"
#include "random.h"
#include "palette.h"
#include "union_room.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "save.h"
#include "mystery_gift.h"

struct SioInfo
{
    char magic[15]; // PokemonSioInfo
    u8 playerCount;
    u8 linkPlayerIdx[RFU_CHILD_MAX];
    struct LinkPlayer linkPlayers[MAX_RFU_PLAYERS];
    u8 filler[92];
};

struct RfuDebug
{
    u8 filler0[6];
    u16 unk_06;
    u8 filler1[6];
    vu8 unk_0e;
    u8 unk_0f;
    u8 filler2[84];
    u16 unk_64;
    u8 filler3[29];
    u8 unk_83;
    u8 filler4[88];
};

EWRAM_DATA u32 gf_rfu_REQ_api[RFU_API_BUFF_SIZE_RAM / 4] = {};
EWRAM_DATA struct GFRfuManager Rfu = {};

static u8 sHeldKeyCount;
static u8 sResendBlock8[16];
static u16 sResendBlock16[8];

EWRAM_DATA struct GFtgtGname gHostRFUtgtGnameBuffer = {};
EWRAM_DATA u8 gHostRFUtgtUnameBuffer[PLAYER_NAME_LENGTH + 1] = {};
static EWRAM_DATA INIT_PARAM sRfuReqConfig = {};
static EWRAM_DATA struct RfuDebug sRfuDebug = {};

static void ResetSendDataManager(struct RfuBlockSend *);
static void sub_800EAB4(void);
static void sub_800EAFC(void);
static void sub_800ED34(u16);
static void sub_800EDBC(u16);
static void UpdateBackupQueue(void);
static void Task_ExchangeLinkPlayers(u8);
static void RfuHandleReceiveCommand(u8);
static void CallRfuFunc(void);
static void RfuPrepareSendBuffer(u16);
static void HandleBlockSend(void);
static void SendNextBlock(void);
static void SendLastBlock(void);
static u8 GetPartnerIndexByNameAndTrainerID(const u8 *, u16);
static void UpdateChildStatuses(void);
static s32 sub_80107A0(void);
static void sub_801084C(u8);
static void ClearSelectedLinkPlayerIds(u16);
static void ValidateAndReceivePokemonSioInfo(void *);
static void sub_8010D0C(u8);
static void sub_80115EC(s32);
static void sub_8011BF8(void);
static void RfuReqDisconnectSlot(u32);
static void sub_8011E94(u32, u32);
static void sub_801209C(u8);
static void Debug_PrintEmpty(void);
static void Task_Idle(u8);

static const INIT_PARAM sRfuReqConfigTemplate = {
    .maxMFrame = 4,
    .MC_TimerCount = 32,
    .availSlot_flag = 0,
    .mboot_flag = 0,
    .serialNo = 2,
    .gameName = (void *)&gHostRFUtgtGnameBuffer,
    .userName = gHostRFUtgtUnameBuffer,
    .fastSearchParent_flag = TRUE,
    .linkRecovery_enable = FALSE,
    .linkRecovery_period = 600,
    .NI_failCounter_limit = 0x12c
};

static const u8 sAvailSlots[] = {
    [1] = AVAIL_SLOT1,
    [2] = AVAIL_SLOT2,
    [3] = AVAIL_SLOT3,
    [4] = AVAIL_SLOT4
};

static const u32 sAllBlocksReceived[] = {
    0x000000,
    0x000001,
    0x000003,
    0x000007,
    0x00000f,
    0x00001f,
    0x00003f,
    0x00007f,
    0x0000ff,
    0x0001ff,
    0x0003ff,
    0x0007ff,
    0x000fff,
    0x001fff,
    0x003fff,
    0x007fff,
    0x00ffff,
    0x01ffff,
    0x03ffff,
    0x07ffff,
    0x0fffff,
    0x1fffff,
    0x3fffff,
    0x7fffff,
    0xffffff
};

static const u8 sUnknown_082ED68C[] = {
    0, 0, 1,
    1, 2, 2,
    2, 2, 3
};

static const u8 sUnknown_082ED695[] = {
    0, 1, 1, 2,
    1, 2, 2, 3,
    1, 2, 2, 3,
    2, 3, 3, 4
};

static const u8 sUnknown_082ED6A5[] = {
    0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

static const struct BlockRequest sBlockRequests[] = {
    { gBlockSendBuffer, 200 },
    { gBlockSendBuffer, 200 },
    { gBlockSendBuffer, 100 },
    { gBlockSendBuffer, 220 },
    { gBlockSendBuffer,  40 }
};

static const u16 sAcceptedSerialNos[] = {
    0x0002,
    RFU_SERIAL_7F7D,
    0x0000,
    0xFFFF
};

static const char sASCII_RfuCmds[][15] = {
    "RFU WAIT",
    "RFU BOOT",
    "RFU ERROR",
    "RFU RESET",
    "RFU CONFIG",
    "RFU START",
    "RFU SC POLL",
    "RFU SP POLL",
    "RFU START",
    "RFU SEND ERR",
    "RFU CP POLL"
};

static const char sASCII_RecoverCmds[][16] = {
    "              ",
    "RECOVER START ",
    "DISSCONECT    ",
    "RECOVER SUUSES",
    "RECOVER FAILED"
};

static const TaskFunc sUnknown_082ED7E0[] = {
    sub_801084C,
    Task_ExchangeLinkPlayers,
    sub_8010D0C
};

static const char sASCII_PokemonSioInfo[] = "PokemonSioInfo";
static const char sASCII_LinkLossDisconnect[] = "LINK LOSS DISCONNECT!";
static const char sASCII_LinkLossRecoveryNow[] = "LINK LOSS RECOVERY NOW";
ALIGNED(4) static const char sASCII_30Commas[31] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
static const char sASCII_15Commas[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
static const char sASCII_8Commas[9] = {' ',' ',' ',' ',' ',' ',' ',' ','\0'};
ALIGNED(4) static const char sASCII_Space[2] = {' ','\0'};
static const char sASCII_Asterisk[2] = {'*','\0'};
static const char sASCII_NowSlot[8] = "NOWSLOT";

static const char sASCII_ClockCmds[][12] = {
    "           ",
    "CLOCK DRIFT",
    "BUSY SEND  ",
    "CMD REJECT ",
    "CLOCK SLAVE"
};

static const char sASCII_ChildParentSearch[3][8] = {
    "CHILD ",
    "PARENT",
    "SEARCH"
};

static void Debug_PrintString(const void *str, u8 x, u8 y)
{

}

static void Debug_PrintNum(u16 num, u8 x, u8 y, u8 numDigits)
{

}

void ResetLinkRfuGFLayer(void)
{
    s32 i;
    u8 errorState = Rfu.errorState;
    CpuFill16(0, &Rfu, sizeof Rfu);
    Rfu.errorState = errorState;
    Rfu.parentChild = 0xFF;
    if (Rfu.errorState != 4)
    {
        Rfu.errorState = 0;
    }
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        ResetSendDataManager(&Rfu.recvBlock[i]);
    }
    ResetSendDataManager(&Rfu.sendBlock);
    RfuRecvQueue_Reset(&Rfu.recvQueue);
    RfuSendQueue_Reset(&Rfu.sendQueue);
    CpuFill16(0, gSendCmd, sizeof gSendCmd);
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
    CpuFill16(0, gLinkPlayers, sizeof gLinkPlayers);
}

void InitRFU(void)
{
    IntrFunc serialIntr = gIntrTable[1];
    IntrFunc timerIntr = gIntrTable[2];
    InitRFUAPI();
    rfu_REQ_stopMode();
    rfu_waitREQComplete();
    REG_IME = 0;
    gIntrTable[1] = serialIntr;
    gIntrTable[2] = timerIntr;
    REG_IME = INTR_FLAG_VBLANK;
}

void InitRFUAPI(void)
{
    if (!rfu_initializeAPI((void *)gf_rfu_REQ_api, sizeof gf_rfu_REQ_api, gIntrTable + 1, TRUE))
    {
        gLinkType = 0;
        ClearSavedLinkPlayers();
        sub_80111B0(FALSE);
        ResetLinkRfuGFLayer();
        rfu_setTimerInterrupt(3, gIntrTable + 2);
    }
}

static void Task_LinkLeaderSearchForChildren(u8 taskId)
{
    UpdateChildStatuses();
    switch (Rfu.state)
    {
    case 0:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        Rfu.state = 1;
        gTasks[taskId].data[1] = 1;
        break;
    case 1:
        break;
    case 2:
        rfu_LMAN_establishConnection(Rfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        Rfu.state = 3;
        gTasks[taskId].data[1] = 6;
        break;
    case 3:
        break;
    case 4:
        rfu_LMAN_stopManager(FALSE);
        Rfu.state = 5;
        break;
    case 5:
        break;
    case 18:
        Rfu.unk_cdb = FALSE;
        rfu_LMAN_setMSCCallback(sub_800EDBC);
        sub_800EAB4();
        sub_800EAFC();
        Rfu.state = 20;
        gTasks[taskId].data[1] = 8;
        CreateTask(sub_801084C, 5);
        DestroyTask(taskId);
        break;
    }
}

s32 sub_800E87C(u8 idx)
{
    return sUnknown_082ED6A5[idx];
}

void sub_800E88C(s32 r2, s32 r5)
{
    u8 i;
    u8 r4 = 1;
    s32 r1 = r2;
    s32 r6 = 0;
    if (r5 == -1)
    {
        for (i = 0; i < RFU_CHILD_MAX; r2 >>= 1, i++)
        {
            if (r2 & 1)
            {
                Rfu.linkPlayerIdx[i] = r4;
                r4++;
            }
        }
    }
    else
    {
        for (i = 0; i < RFU_CHILD_MAX; r1 >>= 1, i++)
        {
            if (!(r1 & 1))
            {
                Rfu.linkPlayerIdx[i] = 0;
            }
        }
        for (r4 = RFU_CHILD_MAX; r4 != 0; r4--)
        {
            for (i = 0; i < RFU_CHILD_MAX && Rfu.linkPlayerIdx[i] != r4; i++);
            if (i == RFU_CHILD_MAX)
            {
                r6 = r4;
            }
        }
        for (r5 &= ~r2, i = 0; i < RFU_CHILD_MAX; r5 >>= 1, i++)
        {
            if (r5 & 1)
            {
                Rfu.linkPlayerIdx[i] = r6++;
            }
        }
    }
}

static void Task_JoinGroupSearchForParent(u8 taskId)
{
    switch (Rfu.state)
    {
    case 0:
        rfu_LMAN_initializeRFU((INIT_PARAM *)&sRfuReqConfigTemplate);
        Rfu.state = 1;
        gTasks[taskId].data[1] = 1;
        break;
    case 1:
        break;
    case 6:
        rfu_LMAN_establishConnection(Rfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        Rfu.state = 7;
        gTasks[taskId].data[1] = 7;
        break;
    case 7:
        break;
    case 9:
        gTasks[taskId].data[1] = 10;
        break;
    case 11:
        switch (sub_80107A0())
        {
        case RFU_STATUS_JOIN_GROUP_OK:
            Rfu.state = 12;
            break;
        case RFU_STATUS_JOIN_GROUP_NO:
        case RFU_STATUS_LEAVE_GROUP:
            rfu_LMAN_requestChangeAgbClockMaster();
            Rfu.unk_ce4 = 2;
            DestroyTask(taskId);
            break;
        }
        break;
    case 12:
    {
        u8 bmChildSlot = 1 << Rfu.childSlot;
        rfu_clearSlot(TYPE_NI_SEND | TYPE_NI_RECV, Rfu.childSlot);
        rfu_setRecvBuffer(TYPE_UNI, Rfu.childSlot, Rfu.unk_c3f, 70);
        rfu_UNI_setSendData(bmChildSlot, Rfu.unk_4c,  sizeof(Rfu.unk_4c));
        gTasks[taskId].data[1] = 8;
        DestroyTask(taskId);
        if (sRfuDebug.unk_0f == 0)
        {
            Debug_PrintEmpty();
            sRfuDebug.unk_0f++;
        }
        CreateTask(sub_801084C, 5);
        break;
    }
    }
}

static void sub_800EAB4(void)
{
    u8 i;
    u8 acceptSlot = lman.acceptSlot_flag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (acceptSlot & 1)
        {
            rfu_setRecvBuffer(TYPE_UNI, i, Rfu.unk_14[i], 14);
            rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, i);
        }
        acceptSlot >>= 1;
    }
}

static void sub_800EAFC(void)
{
    u8 acceptSlot = lman.acceptSlot_flag;
    rfu_UNI_setSendData(acceptSlot, Rfu.recvCmds, 70);
    Rfu.unk_cda = sub_800E87C(acceptSlot);
    Rfu.unk_ce2 = acceptSlot;
    sub_800E88C(acceptSlot, -1);
    Rfu.parentChild = MODE_PARENT;
}

static void Task_LinkRfu_UnionRoomListen(u8 taskId)
{
    if (GetHostRFUtgtGname()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM) && RfuGetStatus() == RFU_STATUS_NEW_CHILD_DETECTED)
    {
        rfu_REQ_disconnect(lman.acceptSlot_flag);
        rfu_waitREQComplete();
        RfuSetStatus(RFU_STATUS_OK, 0);
    }
    switch (Rfu.state)
    {
    case 0:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        Rfu.state = 1;
        gTasks[taskId].data[1] = 1;
        break;
    case 1:
        break;
    case 17:
        rfu_LMAN_establishConnection(2, 0, 240, (u16 *)sAcceptedSerialNos);
        rfu_LMAN_setMSCCallback(sub_800ED34);
        Rfu.state = 18;
        break;
    case 18:
        break;
    case 13:
        if (rfu_UNI_setSendData(1 << Rfu.childSlot, Rfu.unk_4c, sizeof(Rfu.unk_4c)) == 0)
        {
            Rfu.parentChild = MODE_CHILD;
            DestroyTask(taskId);
            if (gTasks[taskId].data[7])
            {
                CreateTask(sub_8010D0C, 1);
            }
            else
            {
                CreateTask(sub_801084C, 5);
            }
        }
        break;
    case 14:
        rfu_LMAN_stopManager(0);
        Rfu.state = 15;
        break;
    case 15:
        break;
    case 16:
        Rfu.unk_cdb = FALSE;
        rfu_LMAN_setMSCCallback(sub_800EDBC);
        UpdateGameData_GroupLockedIn(TRUE);
        sub_800EAB4();
        sub_800EAFC();
        Rfu.state = 20;
        gTasks[taskId].data[1] = 8;
        Rfu.parentChild = MODE_PARENT;
        CreateTask(sub_801084C, 5);
        Rfu.unk_ce8 = TRUE;
        DestroyTask(taskId);
        break;
    }
}

void LinkRfu_CreateConnectionAsParent(void)
{
    rfu_LMAN_establishConnection(MODE_PARENT, 0, 240, (u16 *)sAcceptedSerialNos);
}

void LinkRfu_StopManagerBeforeEnteringChat(void)
{
    rfu_LMAN_stopManager(FALSE);
}

static void sub_800ED34(u16 unused)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(Rfu.unk_4c); i++)
    {
        Rfu.unk_4c[i] = 0;
    }
    rfu_REQ_recvData();
    rfu_waitREQComplete();
    if (gRfuSlotStatusUNI[Rfu.childSlot]->recv.newDataFlag)
    {
        Rfu.unk_cd0++;
        RfuRecvQueue_Enqueue(&Rfu.recvQueue, Rfu.unk_c3f);
        sRfuDebug.unk_06++;
        UpdateBackupQueue();
        rfu_UNI_readySendData(Rfu.childSlot);
        rfu_UNI_clearRecvNewDataFlag(Rfu.childSlot);
    }
    rfu_LMAN_REQ_sendData(TRUE);
}

static void sub_800EDBC(u16 unused)
{
    Rfu.unk_cdb = TRUE;
}

void LinkRfu_Shutdown(void)
{
    u8 i;

    rfu_LMAN_powerDownRFU();
    if (Rfu.parentChild == MODE_PARENT)
    {
        if (FuncIsActiveTask(Task_LinkLeaderSearchForChildren) == TRUE)
        {
            DestroyTask(Rfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (Rfu.parentChild == MODE_CHILD)
    {
        if (FuncIsActiveTask(Task_JoinGroupSearchForParent) == TRUE)
        {
            DestroyTask(Rfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (Rfu.parentChild == 2)
    {
        if (FuncIsActiveTask(Task_LinkRfu_UnionRoomListen) == TRUE)
        {
            DestroyTask(Rfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    for (i = 0; i < ARRAY_COUNT(sUnknown_082ED7E0); i++)
    {
        if (FuncIsActiveTask(sUnknown_082ED7E0[i]) == TRUE)
        {
            DestroyTask(FindTaskIdByFunc(sUnknown_082ED7E0[i]));
        }
    }
}

static void CreateTask_LinkLeaderSearchForChildren(void)
{
    Rfu.searchTaskId = CreateTask(Task_LinkLeaderSearchForChildren, 1);
}

static bool8 sub_800EE94(void)
{
    if (Rfu.state == 7 && Rfu.parentId)
    {
        return TRUE;
    }
    return FALSE;
}

static bool32 IsParentSuccessfullyReconnected(void)
{
    if (Rfu.state == 7 && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[Rfu.unk_c3d].id, 240))
    {
        Rfu.state = 9;
        return TRUE;
    }
    return FALSE;
}

static void CreateTask_JoinGroupSearchForParent(void)
{
    Rfu.searchTaskId = CreateTask(Task_JoinGroupSearchForParent, 1);
}

bool8 LmanAcceptSlotFlagIsNotZero(void)
{
    if (lman.acceptSlot_flag)
    {
        return TRUE;
    }
    return FALSE;
}

void LinkRfu_StopManagerAndFinalizeSlots(void)
{
    Rfu.state = 4;
    Rfu.acceptSlot_flag = lman.acceptSlot_flag;
}

bool32 WaitRfuState(bool32 force)
{
    if (Rfu.state == 17 || force)
    {
        Rfu.state = 18;
        return TRUE;
    }
    return FALSE;
}

void sub_800EF7C(void)
{
    Rfu.state = 14;
}

static void sub_800EF88(u8 a0)
{
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (a0 & 1)
        {
            rfu_UNI_readySendData(i);
            break;
        }
        a0 >>= 1;
    }
}

static void sub_800EFB0(void)
{
    s32 i, j;

    for (i = 0; i < 5; i++)
    {
        struct GFRfuManager *ptr = &Rfu;
        for (j = 0; j < 7; j++)
        {
            ptr->recvCmds[i][j][1] = gRecvCmds[i][j] >> 8;
            ptr->recvCmds[i][j][0] = gRecvCmds[i][j];
        }
    }
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
}

static void sub_800F014(void)
{
    s32 i;
    for (i = 0; i < CMD_LENGTH - 1; i++)
    {
        gRecvCmds[0][i] = gSendCmd[i];
    }
    for (i = 0; i < CMD_LENGTH - 1; i++)
    {
        gSendCmd[i] = 0;
    }
}

static void UpdateBackupQueue(void)
{
    if (Rfu.linkRecovered)
    {
        bool8 backupEmpty = RfuBackupQueue_Dequeue(&Rfu.backupQueue, Rfu.unk_4c);

        if (Rfu.backupQueue.count == 0)
            Rfu.linkRecovered = FALSE;

        if (backupEmpty)
            return;
    }
    if (!Rfu.linkRecovered)
    {
        RfuSendQueue_Dequeue(&Rfu.sendQueue, Rfu.unk_4c);
        RfuBackupQueue_Enqueue(&Rfu.backupQueue, Rfu.unk_4c);
    }
}

bool32 IsRfuRecvQueueEmpty(void)
{
    s32 i;
    s32 j;

    if (gRfuLinkStatus->sendSlotUNIFlag == 0)
    {
        return FALSE;
    }
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            if (gRecvCmds[i][j] != 0)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

static bool32 sub_800F0F8(void)
{
    if (Rfu.state < 20)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
    else
    {
        Rfu.unk_cdb = FALSE;
        if ((Rfu.unk_ce2 & gRfuLinkStatus->connSlotFlag) == Rfu.unk_ce2 && (Rfu.unk_ce2 & gRfuLinkStatus->connSlotFlag))
        {
            if (!Rfu.unk_cdc)
            {
                if (Rfu.unk_ce3)
                {
                    RfuReqDisconnectSlot(Rfu.unk_ce3);
                    Rfu.unk_ce3 = 0;
                    if (Rfu.unk_ce4 == 1)
                    {
                        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x8000);
                        GetLinkmanErrorParams(0x8000);
                        return FALSE;
                    }
                    if (!lman.acceptSlot_flag)
                    {
                        LinkRfu_Shutdown();
                        gReceivedRemoteLinkPlayers = 0;
                        return FALSE;
                    }
                }
                sub_800EFB0();
                rfu_UNI_readySendData(Rfu.unk_cda);
                rfu_LMAN_REQ_sendData(TRUE);
            }
            else
            {
                rfu_REQ_PARENT_resumeRetransmitAndChange();
            }
            Rfu.unk_0e = TRUE;
        }
    }
    return FALSE;
}

static bool32 sub_800F1E0(void)
{
    u16 i;
    u16 flags;
    u8 r0;
    u16 j;
    u8 retval;

    if (Rfu.state >= 20 && Rfu.unk_0e == TRUE)
    {
        rfu_waitREQComplete();
        while (Rfu.unk_cdb == FALSE)
        {
            if (Rfu.errorState != 0)
            {
                return FALSE;
            }
        }
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        if ((lman.parentAck_flag & Rfu.unk_ce2) == Rfu.unk_ce2)
        {
            Rfu.unk_cdc = FALSE;
            sRfuDebug.unk_06++;
            flags = lman.acceptSlot_flag;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (flags & 1)
                {
                    if (Rfu.unk_14[i][1])
                    {
                        if (Rfu.unk_cee[i] != 0xFF && (Rfu.unk_14[i][0] >> 5) != ((Rfu.unk_cee[i] + 1) & 7))
                        {
                            if (++Rfu.unk_cea[i] > 4)
                                GetLinkmanErrorParams(0x8100);
                        }
                        else
                        {
                            Rfu.unk_cee[i] = Rfu.unk_14[i][0] / 32;
                            Rfu.unk_cea[i] = 0;
                            Rfu.unk_14[i][0] &= 0x1f;
                            r0 = Rfu.linkPlayerIdx[i];
                            for (j = 0; j < 7; j++)
                            {
                                gRecvCmds[r0][j] = (Rfu.unk_14[i][(j << 1) + 1] << 8) | Rfu.unk_14[i][(j << 1) + 0];
                                Rfu.unk_14[i][(j << 1) + 1] = 0;
                                Rfu.unk_14[i][(j << 1) + 0] = 0;
                            }
                        }
                    }
                    rfu_UNI_clearRecvNewDataFlag(i);
                }
                flags >>= 1;
            }
            sub_800F014();
            RfuHandleReceiveCommand(0);
            CallRfuFunc();
            if (Rfu.unk_ce5 && !Rfu.unk_cd9)
            {
                sRfuDebug.unk_0e = FALSE;
                rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, Rfu.unk_cda);
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((Rfu.unk_ce5 >> i) & 1)
                    {
                        rfu_setRecvBuffer(TYPE_UNI, i, Rfu.unk_14[i], 14);
                    }
                }
                sub_800E88C(Rfu.unk_ce2, Rfu.unk_ce2 | Rfu.unk_ce5);
                Rfu.unk_ce9 = Rfu.unk_ce5;
                Rfu.unk_ce2 |= Rfu.unk_ce5;
                Rfu.unk_ce5 = 0;
                rfu_UNI_setSendData(Rfu.unk_ce2, Rfu.recvCmds, 70);
                Rfu.unk_cda = sub_800E87C(Rfu.unk_ce2);
                CreateTask(Task_ExchangeLinkPlayers, 0);
            }
        }
        else
        {
            Rfu.unk_cdc = TRUE;
            Rfu.unk_0e = FALSE;
        }
        Rfu.unk_0e = FALSE;
    }
    retval = Rfu.unk_cdc;
    return gRfuLinkStatus->sendSlotUNIFlag ? retval & 1 : FALSE;
}

static void sub_800F498(u16 *a0, u8 *a1)
{
    s32 i;

    if (a0[0])
    {
        a0[0] |= (Rfu.unk_102 << 5);
        Rfu.unk_102 = (Rfu.unk_102 + 1) & 7;
        for (i = 0; i < 7; i++)
        {
            a1[2 * i + 1] = a0[i] >> 8;
            a1[2 * i + 0] = a0[i];
        }
    }
    else
    {
        for (i = 0; i < 14; i++)
            a1[i] = 0;
    }
}

static bool32 RfuProcessEnqueuedRecvBlock(void)
{
    u8 i;
    u8 j;
    u8 sp00[MAX_RFU_PLAYERS * (2 * (CMD_LENGTH - 1))];
    u8 sp48[2 * (CMD_LENGTH - 1)];
    u8 status;

    RfuRecvQueue_Dequeue(&Rfu.recvQueue, sp00);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            gRecvCmds[i][j] = (sp00[i * 14 + (j << 1) + 1] << 8) | sp00[i * 14 + (j << 1) + 0];
        }
    }
    RfuHandleReceiveCommand(0);
    if (lman.childClockSlave_flag == 0 && Rfu.unk_ce4)
    {
        rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
        rfu_waitREQComplete();
        status = RfuGetStatus();
        if (status != RFU_STATUS_FATAL_ERROR && status != RFU_STATUS_JOIN_GROUP_NO && status != RFU_STATUS_LEAVE_GROUP)
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x9000);
        rfu_clearAllSlot();
        gReceivedRemoteLinkPlayers = FALSE;
        Rfu.callback = NULL;
        if (Rfu.unk_ce4 == 1)
        {
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x9000);
            GetLinkmanErrorParams(0x9000);
        }
        lman.state = lman.next_state = 0;
        Rfu.unk_ce4 = 0;
    }
    if (Rfu.unk_cd0)
    {
        Rfu.unk_cd0--;
        CallRfuFunc();
        sub_800F498(gSendCmd, sp48);
        RfuSendQueue_Enqueue(&Rfu.sendQueue, sp48);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i] = 0;
    }
    return IsRfuRecvQueueEmpty();
}

static void HandleSendFailure(u8 unused, u32 flags)
{
    s32 i, j, temp;

    const u8 *r10 = Rfu.sendBlock.payload;
    for (i = 0; i < Rfu.sendBlock.count; i++)
    {
        if (!(flags & 1))
        {
            sResendBlock16[0] = RFUCMD_0x8900 | i;
            for (j = 0; j < 7; j++)
            {
                temp = j << 1;
                sResendBlock16[j + 1] = (r10[12 * i + temp + 1] << 8) | r10[12 * i + temp + 0];
            }
            for (j = 0; j < 7; j++)
            {
                temp = j << 1;
                sResendBlock8[temp + 1] = sResendBlock16[j] >> 8;
                sResendBlock8[temp + 0] = sResendBlock16[j];
            }
            RfuSendQueue_Enqueue(&Rfu.sendQueue, sResendBlock8);
            Rfu.sendBlock.failedFlags |= (1 << i);
        }
        flags >>= 1;
    }
}

void Rfu_SetBlockReceivedFlag(u8 linkPlayerId)
{
    if (Rfu.parentChild == MODE_PARENT && linkPlayerId)
        Rfu.numBlocksReceived[linkPlayerId] = 1;
    else
        Rfu.blockReceived[linkPlayerId] = TRUE;
}

void Rfu_ResetBlockReceivedFlag(u8 linkPlayerId)
{
    Rfu.blockReceived[linkPlayerId] = FALSE;
    Rfu.recvBlock[linkPlayerId].receiving = 0;
}

static u8 sub_800F74C(const u8 *a0)
{
    u8 i;

    if (Rfu.parentChild == MODE_PARENT)
        return FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        Rfu.linkPlayerIdx[i] = a0[i];
    }
    return a0[Rfu.childSlot];
}

static void RfuFunc_SendKeysToRfu(void)
{
    if (gReceivedRemoteLinkPlayers
        && gHeldKeyCodeToSend != LINK_KEY_CODE_NULL
        && gLinkTransferringData != TRUE)
    {
        sHeldKeyCount++;
        gHeldKeyCodeToSend |= (sHeldKeyCount << 8);
        RfuPrepareSendBuffer(RFUCMD_SEND_HELD_KEYS);
    }
}

struct GFtgtGname *GetHostRFUtgtGname(void)
{
    return &gHostRFUtgtGnameBuffer;
}

bool32 IsSendingKeysToRfu(void)
{
    return Rfu.callback == RfuFunc_SendKeysToRfu;
}

void StartSendingKeysToRfu(void)
{
    Rfu.callback = RfuFunc_SendKeysToRfu;
}

void ClearLinkRfuCallback(void)
{
    Rfu.callback = NULL;
}

static void Rfu_BerryBlenderSendHeldKeys(void)
{
    RfuPrepareSendBuffer(RFUCMD_BLENDER_SEND_KEYS);
    if (GetMultiplayerId() == 0)
        gSendCmd[BLENDER_COMM_ARROW_POS] = GetBlenderArrowPosition();
    gBerryBlenderKeySendAttempts++;
}

void Rfu_SetBerryBlenderLinkCallback(void)
{
    if (Rfu.callback == NULL)
        Rfu.callback = Rfu_BerryBlenderSendHeldKeys;
}

static void RfuHandleReceiveCommand(u8 unused)
{
    u16 i;
    u16 j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        switch (gRecvCmds[i][0] & 0xff00)
        {
        case RFUCMD_0x7800:
            if (Rfu.parentChild == MODE_CHILD && gReceivedRemoteLinkPlayers)
                return;
            // fallthrough
        case RFUCMD_0x7700:
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
            {
                Rfu.playerCount = gRecvCmds[i][1];
                Rfu.multiplayerId = sub_800F74C((u8 *)(gRecvCmds[i] + 2));
            }
            break;
        case RFUCMD_0x8800:
            if (Rfu.recvBlock[i].receiving == 0)
            {
                Rfu.recvBlock[i].next = 0;
                Rfu.recvBlock[i].count = gRecvCmds[i][1];
                Rfu.recvBlock[i].owner = gRecvCmds[i][2];
                Rfu.recvBlock[i].receivedFlags = 0;
                Rfu.recvBlock[i].receiving = 1;
                Rfu.blockReceived[i] = FALSE;
            }
            break;
        case RFUCMD_0x8900:
            if (Rfu.recvBlock[i].receiving == 1)
            {
                Rfu.recvBlock[i].next = gRecvCmds[i][0] & 0xff;
                Rfu.recvBlock[i].receivedFlags |= (1 << Rfu.recvBlock[i].next);
                for (j = 0; j < 6; j++)
                    gBlockRecvBuffer[i][Rfu.recvBlock[i].next * 6 + j] = gRecvCmds[i][j + 1];
                if (Rfu.recvBlock[i].receivedFlags == sAllBlocksReceived[Rfu.recvBlock[i].count])
                {
                    Rfu.recvBlock[i].receiving = 2;
                    Rfu_SetBlockReceivedFlag(i);
                    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && gReceivedRemoteLinkPlayers != 0 && Rfu.parentChild == MODE_CHILD)
                        ValidateAndReceivePokemonSioInfo(gBlockRecvBuffer);
                }
            }
            break;
        case RFUCMD_SEND_BLOCK_REQ:
            Rfu_InitBlockSend(sBlockRequests[gRecvCmds[i][1]].address, (u16)sBlockRequests[gRecvCmds[i][1]].size);
            break;
        case RFUCMD_READY_CLOSE_LINK:
            Rfu.readyCloseLink[i] = TRUE;
            break;
        case RFUCMD_READY_EXIT_STANDBY:
            if (Rfu.unk_100 == gRecvCmds[i][1])
                Rfu.readyExitStandby[i] = TRUE;
            break;
        case RFUCMD_0xED00:
            if (Rfu.parentChild == MODE_CHILD)
            {
                if (gReceivedRemoteLinkPlayers)
                {
                    if (gRecvCmds[i][1] & gRfuLinkStatus->connSlotFlag)
                    {
                        gReceivedRemoteLinkPlayers = 0;
                        rfu_LMAN_requestChangeAgbClockMaster();
                        Rfu.unk_ce4 = gRecvCmds[i][2];
                    }
                    Rfu.playerCount = gRecvCmds[i][3];
                    ClearSelectedLinkPlayerIds(gRecvCmds[i][1]);
                }
            }
            else
            {
                RfuPrepareSendBuffer(RFUCMD_0xEE00);
                gSendCmd[1] = gRecvCmds[i][1];
                gSendCmd[2] = gRecvCmds[i][2];
                gSendCmd[3] = gRecvCmds[i][3];
            }
            break;
        case RFUCMD_0xEE00:
            if (Rfu.parentChild == MODE_PARENT)
            {
                Rfu.unk_ce3 |= gRecvCmds[i][1];
                Rfu.unk_ce4 = gRecvCmds[i][2];
                ClearSelectedLinkPlayerIds(gRecvCmds[i][1]);
            }
            break;
        case RFUCMD_BLENDER_SEND_KEYS:
        case RFUCMD_SEND_HELD_KEYS:
            gLinkPartnersHeldKeys[i] = gRecvCmds[i][1];
            break;
        }
        if (Rfu.parentChild == MODE_PARENT && Rfu.numBlocksReceived[i])
        {
            if (Rfu.numBlocksReceived[i] == 4)
            {
                Rfu.blockReceived[i] = TRUE;
                Rfu.numBlocksReceived[i] = 0;
            }
            else
                Rfu.numBlocksReceived[i]++;
        }
    }
}

static bool8 AreNoPlayersReceiving(void)
{
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (Rfu.recvBlock[i].receiving)
            return FALSE;
    }
    return TRUE;
}

static bool8 sub_800FC88(void)
{
    s32 i;

    for (i = 0; i < Rfu.playerCount; i++)
    {
        if (Rfu.recvBlock[i].receiving != 2 || Rfu.blockReceived[i] != TRUE)
            return FALSE;
    }
    return TRUE;
}

static void ResetSendDataManager(struct RfuBlockSend *data)
{
    data->next = 0;
    data->count = 0;
    data->payload = NULL;
    data->receivedFlags = 0;
    data->sending = FALSE;
    data->owner = 0;
    data->receiving = 0;
}

u8 Rfu_GetBlockReceivedStatus(void)
{
    u8 flags = 0;
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (Rfu.recvBlock[i].receiving == 2 && Rfu.blockReceived[i] == TRUE)
        {
            flags |= (1 << i);
        }
    }
    return flags;
}

static void RfuPrepareSendBuffer(u16 command)
{
    u8 i;
    u8 *buff;
    u8 tmp;

    gSendCmd[0] = command;
    switch (command)
    {
    case RFUCMD_0x8800:
        gSendCmd[1] = Rfu.sendBlock.count;
        gSendCmd[2] = Rfu.sendBlock.owner + 0x80;
        break;
    case RFUCMD_SEND_BLOCK_REQ:
        if (AreNoPlayersReceiving())
            gSendCmd[1] = Rfu.blockRequestType;
        break;
    case RFUCMD_0x7700:
    case RFUCMD_0x7800:
        tmp = Rfu.unk_ce2 ^ Rfu.unk_ce3;
        Rfu.playerCount = sUnknown_082ED695[tmp] + 1;
        gSendCmd[1] = Rfu.playerCount;
        buff = (u8 *)(gSendCmd + 2);
        for (i = 0; i < RFU_CHILD_MAX; i++)
            buff[i] = Rfu.linkPlayerIdx[i];
        break;
    case RFUCMD_READY_EXIT_STANDBY:
    case RFUCMD_READY_CLOSE_LINK:
        gSendCmd[1] = Rfu.unk_100;
        break;
    case RFUCMD_BLENDER_SEND_KEYS:
        gSendCmd[0] = command;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case RFUCMD_SEND_PACKET:
        for (i = 0; i < RFU_PACKET_SIZE; i++)
            gSendCmd[1 + i] = Rfu.packet[i];
        break;
    case RFUCMD_SEND_HELD_KEYS:
        gSendCmd[1] = gHeldKeyCodeToSend;
        break;
    case RFUCMD_0xEE00:
        break;
    case RFUCMD_0xED00:
        break;
    }
}

void Rfu_SendPacket(void *data)
{
    if (gSendCmd[0] == 0 && !RfuHasErrored())
    {
        memcpy(Rfu.packet, data, sizeof(Rfu.packet));
        RfuPrepareSendBuffer(RFUCMD_SEND_PACKET);
    }
}

bool32 Rfu_InitBlockSend(const u8 *src, size_t size)
{
    bool8 r4;
    if (Rfu.callback != NULL)
        return FALSE;
    if (gSendCmd[0] != 0)
        return FALSE;
    if (Rfu.sendBlock.sending)
    {
        sRfuDebug.unk_83++;
        return FALSE;
    }
    r4 = (size % 12) != 0;
    Rfu.sendBlock.owner = GetMultiplayerId();
    Rfu.sendBlock.sending = TRUE;
    Rfu.sendBlock.count = (size / 12) + r4;
    Rfu.sendBlock.next = 0;
    if (size > 0x100)
        Rfu.sendBlock.payload = src;
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);
        Rfu.sendBlock.payload = gBlockSendBuffer;
    }
    RfuPrepareSendBuffer(RFUCMD_0x8800);
    Rfu.callback = HandleBlockSend;
    Rfu.unk_5b = 0;
    return TRUE;
}

static void HandleBlockSend(void)
{
    if (gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_0x8800);
        if (Rfu.parentChild == MODE_PARENT)
        {
            if (++Rfu.unk_5b > 2)
                Rfu.callback = SendNextBlock;
        }
        else
        {
            if ((gRecvCmds[GetMultiplayerId()][0] & 0xff00) == RFUCMD_0x8800)
                Rfu.callback = SendNextBlock;
        }
    }
}

static void SendNextBlock(void)
{
    s32 i;
    const u8 *src = Rfu.sendBlock.payload;
    gSendCmd[0] = RFUCMD_0x8900 | Rfu.sendBlock.next;
    for (i = 0; i < CMD_LENGTH - 1; i++)
        gSendCmd[i + 1] = (src[(i << 1) + Rfu.sendBlock.next * 12 + 1] << 8) | src[(i << 1) + Rfu.sendBlock.next * 12 + 0];
    Rfu.sendBlock.next++;
    if (Rfu.sendBlock.count <= Rfu.sendBlock.next)
    {
        Rfu.sendBlock.sending = FALSE;
        Rfu.callback = SendLastBlock;
    }
}

static void SendLastBlock(void)
{
    const u8 *src = Rfu.sendBlock.payload;
    u8 mpId = GetMultiplayerId();
    s32 i;
    if (Rfu.parentChild == MODE_CHILD)
    {
        gSendCmd[0] = RFUCMD_0x8900 | (Rfu.sendBlock.count - 1);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i + 1] = (src[(i << 1) + (Rfu.sendBlock.count - 1) * 12 + 1] << 8) | src[(i << 1) + (Rfu.sendBlock.count - 1) * 12 + 0];
        if ((u8)gRecvCmds[mpId][0] == Rfu.sendBlock.count - 1)
        {
            if (Rfu.recvBlock[mpId].receivedFlags != sAllBlocksReceived[Rfu.recvBlock[mpId].count])
            {
                HandleSendFailure(mpId, Rfu.recvBlock[mpId].receivedFlags);
                sRfuDebug.unk_64++;
            }
            else
                Rfu.callback = NULL;
        }
    }
    else
        Rfu.callback = NULL;
}

bool8 Rfu_SendBlockRequest(u8 type)
{
    Rfu.blockRequestType = type;
    RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_REQ);
    return TRUE;
}

static void sub_801011C(void)
{
    rfu_clearAllSlot();
    rfu_LMAN_powerDownRFU();
    gReceivedRemoteLinkPlayers = 0;
    Rfu.isShuttingDown = TRUE;
    Rfu.callback = NULL;
}

static void DisconnectRfu(void)
{
    rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
    rfu_waitREQComplete();
    sub_801011C();
}

static void TryDisconnectRfu(void)
{
    if (Rfu.parentChild == MODE_CHILD)
    {
        rfu_LMAN_requestChangeAgbClockMaster();
        Rfu.unk_ce4 = 2;
    }
    else
        Rfu.callback = DisconnectRfu;
}

void LinkRfu_FatalError(void)
{
    rfu_LMAN_requestChangeAgbClockMaster();
    Rfu.unk_ce4 = 1;
    Rfu.unk_ce3 = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
}

// RFU equivalent of LinkCB_WaitCloseLink
static void WaitAllReadyToCloseLink(void)
{
    s32 i;
    u8 playerCount = Rfu.playerCount;
    s32 count = 0;

    // Wait for all players to be ready
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (Rfu.readyCloseLink[i])
            count++;
    }
    if (count == playerCount)
    {
        // All ready, close link
        gBattleTypeFlags &= ~BATTLE_TYPE_LINK_IN_BATTLE;
        if (Rfu.parentChild == MODE_CHILD)
        {
            Rfu.errorState = 3;
            TryDisconnectRfu();
        }
        else
            Rfu.callback = TryDisconnectRfu;
    }
}

static void SendReadyCloseLink(void)
{
    if (gSendCmd[0] == 0 && Rfu.unk_ce8 == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_READY_CLOSE_LINK);
        Rfu.callback = WaitAllReadyToCloseLink;
    }
}

static void Task_TryReadyCloseLink(u8 taskId)
{
    if (Rfu.callback == NULL)
    {
        Rfu.unk_cd9 = 1;
        Rfu.callback = SendReadyCloseLink;
        DestroyTask(taskId);
    }
}

void Rfu_SetCloseLinkCallback(void)
{
    if (!FuncIsActiveTask(Task_TryReadyCloseLink))
        CreateTask(Task_TryReadyCloseLink, 5);
}

static void SendReadyExitStandbyUntilAllReady(void)
{
    u8 playerCount;
    u8 i;

    if (GetMultiplayerId() != 0)
    {
        if (Rfu.recvQueue.count == 0 && Rfu.resendExitStandbyTimer > 60)
        {
            RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
            Rfu.resendExitStandbyTimer = 0;
        }
    }
    playerCount = GetLinkPlayerCount();
    for (i = 0; i < playerCount; i++)
    {
        if (!Rfu.readyExitStandby[i])
            break;
    }
    if (i == playerCount)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            Rfu.readyExitStandby[i] = FALSE;
        Rfu.unk_100++;
        Rfu.callback = NULL;
    }
    Rfu.resendExitStandbyTimer++;
}

static void LinkLeaderReadyToExitStandby(void)
{
    if (Rfu.recvQueue.count == 0 && gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
        Rfu.callback = SendReadyExitStandbyUntilAllReady;
    }
}

// RFU equivalent of LinkCB_Standby and LinkCB_StandbyForAll
static void Rfu_LinkStandby(void)
{
    u8 i;
    u8 playerCount;

    if (GetMultiplayerId() != 0)
    {
        // Not link leader, send exit standby when ready
        if (Rfu.recvQueue.count == 0 && gSendCmd[0] == 0)
        {
            RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
            Rfu.callback = SendReadyExitStandbyUntilAllReady;
        }
    }
    else
    {
        // Link leader, wait for all members to send exit ready
        playerCount = GetLinkPlayerCount();
        for (i = 1; i < playerCount; i++)
        {
            if (!Rfu.readyExitStandby[i])
                break;
        }
        if (i == playerCount)
        {
            if (Rfu.recvQueue.count == 0 && gSendCmd[0] == 0)
            {
                RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
                Rfu.callback = LinkLeaderReadyToExitStandby;
            }
        }
    }
}

void Rfu_SetLinkStandbyCallback(void)
{
    if (Rfu.callback == NULL)
    {
        Rfu.callback = Rfu_LinkStandby;
        Rfu.resendExitStandbyTimer = 0;
    }
}

bool32 IsRfuSerialNumberValid(u32 serialNo)
{
    s32 i;
    for (i = 0; sAcceptedSerialNos[i] != serialNo; i++)
    {
        if (sAcceptedSerialNos[i] == 0xFFFF)
            return FALSE;
    }
    return TRUE;
}

u8 sub_801048C(bool32 a0)
{
    if (a0 == FALSE)
        return rfu_LMAN_setLinkRecovery(0, 0);
    rfu_LMAN_setLinkRecovery(1, 600);
    return 0;
}

void sub_80104B0(void)
{
    Rfu.unk_cd9 = 1;
    rfu_LMAN_stopManager(FALSE);
}

u8 Rfu_GetMultiplayerId(void)
{
    if (Rfu.parentChild == MODE_PARENT)
        return 0;
    return Rfu.multiplayerId;
}

u8 Rfu_GetLinkPlayerCount(void)
{
    return Rfu.playerCount;
}

bool8 IsLinkRfuTaskFinished(void)
{
    if (Rfu.status == RFU_STATUS_CONNECTION_ERROR)
        return FALSE;
    return Rfu.callback ? FALSE : TRUE;
}

static void CallRfuFunc(void)
{
    if (Rfu.callback)
        Rfu.callback();
}

static bool8 CheckForLeavingGroupMembers(void)
{
    s32 i;
    bool8 memberLeft = FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.partnerSendStatuses[i] < RFU_STATUS_JOIN_GROUP_OK
         || Rfu.partnerSendStatuses[i] > RFU_STATUS_JOIN_GROUP_NO)
        {
            if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS
             || gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
            {
                if (Rfu.partnerRecvStatuses[i] == RFU_STATUS_LEAVE_GROUP_NOTICE)
                {
                    Rfu.partnerSendStatuses[i] = RFU_STATUS_LEAVE_GROUP;
                    Rfu.partnerRecvStatuses[i] = RFU_STATUS_10;
                    rfu_clearSlot(TYPE_NI_RECV, i);
                    rfu_NI_setSendData(1 << i, 8, &Rfu.partnerSendStatuses[i], 1);
                    memberLeft = TRUE;
                }

            }
            else if (gRfuSlotStatusNI[Rfu.childSlot]->recv.state == SLOT_STATE_RECV_FAILED)
                rfu_clearSlot(TYPE_NI_RECV, i);
            {

            }
        }
    }
    return memberLeft;
}

bool32 sub_80105EC(void)
{
    u8 flags = 0;
    s32 i;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.partnerRecvStatuses[i] == RFU_STATUS_11)
        {
            flags |= (1 << i);
            Rfu.partnerRecvStatuses[i] = RFU_STATUS_OK;
        }
    }
    if (flags)
    {
        rfu_REQ_disconnect(flags);
        rfu_waitREQComplete();
    }
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.partnerRecvStatuses[i] == RFU_STATUS_10
         || Rfu.partnerRecvStatuses[i] == RFU_STATUS_11)
            return TRUE;
    }
    return FALSE;
}

bool32 HasTrainerLeftPartnersList(u16 trainerId, const u8 *name)
{
    u8 idx = GetPartnerIndexByNameAndTrainerID(name, trainerId);
    if (idx == 0xFF)
        return TRUE;
    if (Rfu.partnerSendStatuses[idx] == RFU_STATUS_LEAVE_GROUP)
        return TRUE;
    return FALSE;
}

void SendRfuStatusToPartner(u8 status, u16 trainerId, const u8 *name)
{
    u8 idx = GetPartnerIndexByNameAndTrainerID(name, trainerId);
    Rfu.partnerSendStatuses[idx] = status;
    rfu_clearSlot(TYPE_NI_SEND, idx);
    rfu_NI_setSendData(1 << idx, 8, &Rfu.partnerSendStatuses[idx], 1);
}

void SendLeaveGroupNotice(void)
{
    Rfu.unk_c85 = RFU_STATUS_LEAVE_GROUP_NOTICE;
    rfu_clearSlot(TYPE_NI_SEND, Rfu.childSlot);
    rfu_NI_setSendData(1 << Rfu.childSlot, 8, &Rfu.unk_c85, 1);
}

u32 WaitSendRfuStatusToPartner(u16 trainerId, const u8 *name)
{
    u8 idx = GetPartnerIndexByNameAndTrainerID(name, trainerId);
    if (idx == 0xFF)
        return 2;
    if (gRfuSlotStatusNI[idx]->send.state == 0)
        return 1;
    return 0;
}

static void UpdateChildStatuses(void)
{
    s32 i;

    CheckForLeavingGroupMembers();
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (gRfuSlotStatusNI[i]->send.state == SLOT_STATE_SEND_SUCCESS
         || gRfuSlotStatusNI[i]->send.state == SLOT_STATE_SEND_FAILED)
        {
            if (Rfu.partnerRecvStatuses[i] == RFU_STATUS_10)
                Rfu.partnerRecvStatuses[i] = RFU_STATUS_11;
            rfu_clearSlot(TYPE_NI_SEND, i);
        }
    }
}

static s32 sub_80107A0(void)
{
    s32 status = RFU_STATUS_OK;
    if (Rfu.unk_c85 == 8)
    {
        if (gRfuSlotStatusNI[Rfu.childSlot]->send.state == SLOT_STATE_SEND_SUCCESS
         || gRfuSlotStatusNI[Rfu.childSlot]->send.state == SLOT_STATE_SEND_FAILED)
            rfu_clearSlot(TYPE_NI_SEND, Rfu.childSlot);
    }
    if (gRfuSlotStatusNI[Rfu.childSlot]->recv.state == SLOT_STATE_RECV_SUCCESS
     || gRfuSlotStatusNI[Rfu.childSlot]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
    {
        rfu_clearSlot(TYPE_NI_RECV, Rfu.childSlot);
        RfuSetStatus(Rfu.recvStatus, 0);
        status = Rfu.recvStatus;
    }
    else if (gRfuSlotStatusNI[Rfu.childSlot]->recv.state == SLOT_STATE_RECV_FAILED)
    {
        rfu_clearSlot(TYPE_NI_RECV, Rfu.childSlot);
        status = RFU_STATUS_JOIN_GROUP_NO;
    }
    return status;
}

static void sub_801084C(u8 taskId)
{
    s32 i;

    if (Rfu.status == RFU_STATUS_FATAL_ERROR || Rfu.status == RFU_STATUS_CONNECTION_ERROR)
    {
        Rfu.unk_ce8 = 0;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (AreNoPlayersReceiving())
        {
            ResetBlockReceivedFlags();
            LocalLinkPlayerToBlock();
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (Rfu.parentChild == MODE_PARENT)
        {
            if (gReceivedRemoteLinkPlayers)
                RfuPrepareSendBuffer(RFUCMD_0x7800);
            else
                RfuPrepareSendBuffer(RFUCMD_0x7700);
            gTasks[taskId].data[0] = 101;
        }
        else
            gTasks[taskId].data[0] = 2;
        break;
    case 101:
        if (gSendCmd[0] == 0)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        if (Rfu.playerCount)
            gTasks[taskId].data[0]++;
        break;
    case 3:
        if (Rfu.parentChild == MODE_PARENT)
        {
            if (AreNoPlayersReceiving())
            {
                Rfu.blockRequestType = 0;
                RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_REQ);
                gTasks[taskId].data[0]++;
            }
        }
        else
            gTasks[taskId].data[0]++;
        break;
    case 4:
        if (sub_800FC88())
            gTasks[taskId].data[0]++;
        break;
    case 5:
        for (i = 0; i < Rfu.playerCount; i++)
        {
            LinkPlayerFromBlock(i);
            Rfu_ResetBlockReceivedFlag(i);
        }
        gTasks[taskId].data[0]++;
        break;
    case 6:
        DestroyTask(taskId);
        gReceivedRemoteLinkPlayers = TRUE;
        Rfu.unk_ce8 = FALSE;
        rfu_LMAN_setLinkRecovery(1, 600);
        if (Rfu.unk_ce6)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((Rfu.unk_ce6 >> i) & 1)
                {
                    Rfu.unk_ce5 = 1 << i;
                    Rfu.unk_ce6 ^= (1 << i);
                }
            }
        }
        break;
    }
}

static void ClearSelectedLinkPlayerIds(u16 selected)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((selected >> i) & 1)
            Rfu.linkPlayerIdx[i] = 0;
    }
}

static void ReceiveRfuLinkPlayers(const struct SioInfo *sioInfo)
{
    s32 i;
    Rfu.playerCount = sioInfo->playerCount;
    for (i = 0; i < RFU_CHILD_MAX; i++)
        Rfu.linkPlayerIdx[i] = sioInfo->linkPlayerIdx[i];
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        gLinkPlayers[i] = sioInfo->linkPlayers[i];
        ConvertLinkPlayerName(gLinkPlayers + i);
    }
}

static void ValidateAndReceivePokemonSioInfo(void *recvBuffer)
{
    if (strcmp(sASCII_PokemonSioInfo, recvBuffer) == 0)
    {
        ReceiveRfuLinkPlayers(recvBuffer);
        CpuFill16(0, recvBuffer, sizeof(struct SioInfo));
        ResetBlockReceivedFlag(0);
    }
}

static void Task_ExchangeLinkPlayers(u8 taskId)
{
    s32 i;
    struct LinkPlayerBlock *r2;
    struct SioInfo *r5;
    u8 r4 = Rfu.linkPlayerIdx[sUnknown_082ED68C[Rfu.unk_ce9]];
    if (Rfu.status == RFU_STATUS_FATAL_ERROR || Rfu.status == RFU_STATUS_CONNECTION_ERROR)
    {
        Rfu.unk_ce8 = 0;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gSendCmd[0] == 0)
        {
            ResetBlockReceivedFlag(r4);
            RfuPrepareSendBuffer(RFUCMD_0x7800);
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (gSendCmd[0] == 0)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        if ((GetBlockReceivedStatus() >> r4) & 1)
        {
            ResetBlockReceivedFlag(r4);
            r2 = (struct LinkPlayerBlock *)gBlockRecvBuffer[r4];
            gLinkPlayers[r4] = r2->linkPlayer;
            ConvertLinkPlayerName(gLinkPlayers + r4);
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        r5 = (struct SioInfo *)gBlockSendBuffer;
        memcpy(r5->magic, sASCII_PokemonSioInfo, sizeof sASCII_PokemonSioInfo);
        r5->playerCount = Rfu.playerCount;
        for (i = 0; i < RFU_CHILD_MAX; i++)
            r5->linkPlayerIdx[i] = Rfu.linkPlayerIdx[i];
        memcpy(r5->linkPlayers, gLinkPlayers, sizeof gLinkPlayers);
        gTasks[taskId].data[0]++;
        // fallthrough
    case 4:
        r5 = (struct SioInfo *)gBlockSendBuffer;
        r5->playerCount = Rfu.playerCount;
        for (i = 0; i < RFU_CHILD_MAX; i++)
            r5->linkPlayerIdx[i] = Rfu.linkPlayerIdx[i];
        memcpy(r5->linkPlayers, gLinkPlayers, sizeof gLinkPlayers);
        if (SendBlock(0, gBlockSendBuffer, 0xa0))
            gTasks[taskId].data[0]++;
        break;
    case 5:
        if (IsLinkTaskFinished() && GetBlockReceivedStatus() & 1)
        {
            CpuFill16(0, gBlockRecvBuffer, sizeof(struct SioInfo));
            ResetBlockReceivedFlag(0);
            Rfu.unk_ce8 = 0;
            if (Rfu.unk_ce6)
            {
                for (i = 0; i < 4; i++)
                {
                    if ((Rfu.unk_ce6 >> i) & 1)
                    {
                        Rfu.unk_ce5 = 1 << i;
                        Rfu.unk_ce6 ^= (1 << i);
                        Rfu.unk_ce8 = 1;
                        break;
                    }
                }
            }
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_8010D0C(u8 taskId)
{
    if (Rfu.status == RFU_STATUS_FATAL_ERROR || Rfu.status == RFU_STATUS_CONNECTION_ERROR)
        DestroyTask(taskId);
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (Rfu.playerCount)
        {
            LocalLinkPlayerToBlock();
            SendBlock(0, gBlockSendBuffer, sizeof(struct LinkPlayerBlock));
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
            gTasks[taskId].data[0]++;
        break;
    case 2:
        if (GetBlockReceivedStatus() & 1)
        {
            ReceiveRfuLinkPlayers((const struct SioInfo *)gBlockRecvBuffer);
            ResetBlockReceivedFlag(0);
            gReceivedRemoteLinkPlayers = 1;
            DestroyTask(taskId);
        }
        break;
    }
}

static void RfuCheckErrorStatus(void)
{
    if (Rfu.errorState == 1 && lman.childClockSlave_flag == 0)
    {
        if (gMain.callback2 == c2_mystery_gift_e_reader_run || lman.init_param->mboot_flag)
            gWirelessCommType = 2;
        SetMainCallback2(CB2_LinkError);
        gMain.savedCallback = CB2_LinkError;
        BufferLinkErrorInfo((Rfu.linkmanMsg << 16) | (Rfu.unk_10 << 8) | Rfu.unk_12, Rfu.recvQueue.count, Rfu.sendQueue.count, RfuGetStatus() == RFU_STATUS_CONNECTION_ERROR);
        Rfu.errorState = 2;
        CloseLink();
    }
    else if (Rfu.sendQueue.full == TRUE || Rfu.recvQueue.full == TRUE)
    {
        if (lman.childClockSlave_flag)
            rfu_LMAN_requestChangeAgbClockMaster();
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, 0x7000);
        GetLinkmanErrorParams(0x7000);
    }
}

static void rfu_REQ_recvData_then_sendData(void)
{
    if (lman.parent_child == 1)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(0);
    }
}

bool32 sub_8010EC0(void)
{
    bool32 retval = FALSE;
    Rfu.parentId = 0;
    rfu_LMAN_manager_entity(Random2());
    if (!Rfu.isShuttingDown)
    {
        switch (Rfu.parentChild)
        {
        case MODE_PARENT:
            sub_800F0F8();
            break;
        case MODE_CHILD:
            retval = RfuProcessEnqueuedRecvBlock();
            break;
        case 2:
            rfu_REQ_recvData_then_sendData();
            break;
        }
    }
    return retval;
}

bool32 sub_8010F1C(void)
{
    bool32 retval = FALSE;
    if (!Rfu.isShuttingDown)
    {
        if (Rfu.parentChild == MODE_PARENT)
            retval = sub_800F1E0();
        RfuCheckErrorStatus();
    }
    return retval;
}

static void CopyPlayerNameToUnameBuffer(void)
{
    StringCopy(gHostRFUtgtUnameBuffer, gSaveBlock2Ptr->playerName);
}

void ClearAndInitHostRFUtgtGname(void)
{
    memset(&gHostRFUtgtGnameBuffer, 0, RFU_GAME_NAME_LENGTH);
    InitHostRFUtgtGname(&gHostRFUtgtGnameBuffer, ACTIVITY_NONE, FALSE, 0);
}

void SetHostRFUtgtGname(u8 activity, u32 child_sprite_genders, bool32 started)
{
    InitHostRFUtgtGname(&gHostRFUtgtGnameBuffer, activity, started, child_sprite_genders);
}

void SetGnameBufferWonderFlags(bool32 hasNews, bool32 hasCard)
{
    gHostRFUtgtGnameBuffer.unk_00.hasNews = hasNews;
    gHostRFUtgtGnameBuffer.unk_00.hasCard = hasCard;
}

void SetTradeBoardRegisteredMonInfo(u32 type, u32 species, u32 level)
{
    gHostRFUtgtGnameBuffer.type = type;
    gHostRFUtgtGnameBuffer.species = species;
    gHostRFUtgtGnameBuffer.level = level;
}

u8 sub_801100C(s32 a0)
{
    u8 retval = 0x80;
    retval |= (gLinkPlayers[a0].gender << 3);
    retval |= (gLinkPlayers[a0].trainerId & 7);
    return retval;
}

void sub_801103C(void)
{
    struct GFtgtGname *r5 = &gHostRFUtgtGnameBuffer;
    s32 i;

    for (i = 1; i < GetLinkPlayerCount(); i++)
        r5->child_sprite_gender[i - 1] = sub_801100C(i);
}

void UpdateGameData_GroupLockedIn(bool8 started)
{
    gHostRFUtgtGnameBuffer.started = started;
    rfu_REQ_configGameData(0, 2, (void *)&gHostRFUtgtGnameBuffer, gHostRFUtgtUnameBuffer);
}

void UpdateGameData_SetActivity(u8 activity, u32 flags, bool32 started)
{
    if (activity != ACTIVITY_NONE)
        SetHostRFUtgtGname(activity, flags, started);
    rfu_REQ_configGameData(0, 2, (void *)&gHostRFUtgtGnameBuffer, gHostRFUtgtUnameBuffer);
}

void sub_80110B8(u32 a0)
{
    s32 i;
    u32 numConnectedChildren;
    u32 child_sprite_genders;
    s32 r8;

    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        numConnectedChildren = 0;
        child_sprite_genders = 0;
        r8 = Rfu.unk_ce2 ^ Rfu.unk_ce3;
        for (i = 0; i < 4; i++)
        {
            if ((r8 >> i) & 1)
            {
                child_sprite_genders |= ((0x80 | ((gLinkPlayers[Rfu.linkPlayerIdx[i]].gender & 1) << 3) | (gLinkPlayers[Rfu.linkPlayerIdx[i]].trainerId & 7)) << (numConnectedChildren << 3));
                numConnectedChildren++;
                if (numConnectedChildren == a0 - 1)
                    break;
            }
        }
        UpdateGameData_SetActivity((ACTIVITY_CHAT | IN_UNION_ROOM), child_sprite_genders, FALSE);
    }
}

void GetLinkmanErrorParams(u32 msg)
{
    if (Rfu.errorState == 0)
    {
        Rfu.unk_10 = lman.param[0];
        Rfu.unk_12 = lman.param[1];
        Rfu.linkmanMsg = msg;
        Rfu.errorState = 1;
    }
}

static void ResetErrorState(void)
{
    Rfu.errorState = 0;
}

void sub_80111B0(bool32 a0)
{
    if (!a0)
        Rfu.errorState = 0;
    else
        Rfu.errorState = 4;
}

static void sub_80111DC(void)
{
    sub_8011E94(lman.acceptSlot_flag, 1);
    Rfu.callback = NULL;
}

static void sub_80111FC(void)
{
    Rfu.callback = sub_80111DC;
}

static void sub_801120C(u8 msg, u8 paramCount)
{
    u8 i;
    u8 disconnectFlag = 0;
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 2;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        sub_80115EC(lman.param[0]);
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((lman.param[0] >> i) & 1)
            {
                struct GFtgtGname *structPtr = (void *)gRfuLinkStatus->partner[i].gname;
                if (structPtr->activity == GetHostRFUtgtGname()->activity)
                {
                    Rfu.partnerSendStatuses[i] = RFU_STATUS_OK;
                    Rfu.partnerRecvStatuses[i] = RFU_STATUS_OK;
                    rfu_setRecvBuffer(TYPE_NI, i, &Rfu.partnerRecvStatuses[i], 1);
                }
                else
                {
                    disconnectFlag |= (1 << i);
                }
            }
        }
        if (disconnectFlag)
        {
            rfu_REQ_disconnect(disconnectFlag);
            rfu_waitREQComplete();
        }
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
        break;
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_END_WAIT_CHILD_NAME:
        if (Rfu.acceptSlot_flag != lman.acceptSlot_flag)
        {
            rfu_REQ_disconnect(Rfu.acceptSlot_flag ^ lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        Rfu.state = 17;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        Rfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 4;
        Rfu.unk_ce2 &= ~lman.param[0];
        if (gReceivedRemoteLinkPlayers == 1)
        {
            if (Rfu.unk_ce2 == 0)
                GetLinkmanErrorParams(msg);
            else
                sub_80111FC();
        }
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case 0x34:
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        GetLinkmanErrorParams(msg);
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        Rfu.unk_cdb = TRUE;
        break;
    }
}

void sub_8011404(u8 msg, u8 unused1)
{
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 6;
        break;
    case LMAN_MSG_PARENT_FOUND:
        Rfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        Rfu.childSlot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        Rfu.state = 11;
        Rfu.unk_c85 = 0;
        Rfu.recvStatus = RFU_STATUS_OK;
        rfu_setRecvBuffer(TYPE_NI, Rfu.childSlot, &Rfu.recvStatus, 1);
        rfu_setRecvBuffer(TYPE_UNI, Rfu.childSlot, Rfu.unk_c3f, 70);
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 2;
        if (Rfu.recvStatus == RFU_STATUS_JOIN_GROUP_NO)
            break;
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (Rfu.linkLossRecoveryState != 2)
            Rfu.linkLossRecoveryState = 4;
        if (Rfu.recvStatus != RFU_STATUS_LEAVE_GROUP)
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        Debug_PrintString(sASCII_LinkLossDisconnect, 5, 5);
        if (gReceivedRemoteLinkPlayers == 1)
            GetLinkmanErrorParams(msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        Rfu.linkLossRecoveryState = 1;
        Debug_PrintString(sASCII_LinkLossRecoveryNow, 5, 5);
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        Rfu.linkRecovered = TRUE;
        break;
    case 0x34:
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        GetLinkmanErrorParams(msg);
        Rfu.unk_cdb = TRUE;
        break;
    }
}

static void sub_80115EC(s32 a0)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((a0 >> i) & 1)
        {
            Rfu.unk_cea[i] = 0;
            Rfu.unk_cee[i] = 0xFF;
        }
    }
}

static u8 GetNewChildrenInUnionRoomChat(s32 a0)
{
    u8 ret = 0;
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((a0 >> i) & 1)
        {
            struct GFtgtGname *structPtr = (void *)gRfuLinkStatus->partner[i].gname;
            if (structPtr->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
                ret |= (1 << i);
        }
    }

    return ret;
}

static void sub_8011674(u8 msg, u8 paramCount)
{
    u8 r1;

    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 17;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        RfuSetStatus(RFU_STATUS_NEW_CHILD_DETECTED, 0);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && Rfu.unk_cd9 == 0)
        {
            u8 idx = GetNewChildrenInUnionRoomChat(lman.param[0]);
            if (idx != 0)
            {
                r1 = 1 << sub_800E87C(idx);
                if (Rfu.unk_ce6 == 0 && Rfu.unk_ce8 == 0)
                {
                    Rfu.unk_ce5 = r1;
                    Rfu.unk_ce6 |= (r1 ^ idx);
                    Rfu.unk_ce8 = TRUE;
                }
                else
                {
                    Rfu.unk_ce6 |= idx;
                }
            }
            if (idx != lman.param[0])
            {
                Rfu.unk_ce3 |= (idx ^ lman.param[0]);
                Rfu.unk_ce4 = 2;
            }
        }
        else if (GetHostRFUtgtGname()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM))
        {
            rfu_REQ_disconnect(lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        sub_80115EC(lman.param[0]);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
        break;
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_END_WAIT_CHILD_NAME:
        if (GetHostRFUtgtGname()->activity != (ACTIVITY_CHAT | IN_UNION_ROOM) && lman.acceptCount > 1)
        {
            r1 = 1 << sub_800E87C(lman.param[0]);
            rfu_REQ_disconnect(lman.acceptSlot_flag ^ r1);
            rfu_waitREQComplete();
        }
        if (Rfu.state == 15)
            Rfu.state = 16;
        break;
        break;
    case LMAN_MSG_PARENT_FOUND:
        Rfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        Rfu.childSlot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        Rfu.state = 18;
        if (Rfu.unk_ccf < 2)
        {
            Rfu.unk_ccf++;
            CreateTask(sub_801209C, 2);
        }
        else
        {
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        }
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        Rfu.state = 13;
        RfuSetStatus(RFU_STATUS_CHILD_SEND_COMPLETE, 0);
        rfu_setRecvBuffer(TYPE_UNI, Rfu.childSlot, Rfu.unk_c3f, 70);
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        if (lman.acceptSlot_flag & lman.param[0])
            Rfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        if (gRfuLinkStatus->parentChild == MODE_CHILD)
            Rfu.linkRecovered = TRUE;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 2;
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (Rfu.linkLossRecoveryState != 2)
            Rfu.linkLossRecoveryState = 4;
        if (Rfu.parentChild == MODE_PARENT)
        {
            if (gReceivedRemoteLinkPlayers == 1)
            {
                Rfu.unk_ce2 &= ~(lman.param[0]);
                if (Rfu.unk_ce2 == 0)
                    GetLinkmanErrorParams(msg);
                else
                    sub_80111FC();
            }
        }
        else if (Rfu.unk_ce4 != 2 && gReceivedRemoteLinkPlayers == 1)
        {
            GetLinkmanErrorParams(msg);
            rfu_LMAN_stopManager(0);
        }

        if (gRfuLinkStatus->parentChild == MODE_NEUTRAL && lman.pcswitch_flag == 0 && FuncIsActiveTask(Task_LinkRfu_UnionRoomListen) == TRUE)
            Rfu.state = 17;

        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER:
        Rfu.unk_ce3 = 0;
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        GetLinkmanErrorParams(msg);
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        Rfu.unk_cdb = FALSE;
        break;
    }
}

void sub_8011A50(void)
{
    Rfu.unk_ce4 = 2;
}

void RfuSetStatus(u8 status, u16 msg)
{
    Rfu.status = status;
    Rfu.linkmanMsg = msg;
}

u8 RfuGetStatus(void)
{
    return Rfu.status;
}

bool32 RfuHasErrored(void)
{
    // RFU_STATUS_OK will underflow here intentionally
    u32 var = RfuGetStatus() - 1;
    if (var < RFU_STATUS_CONNECTION_ERROR)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8011A9C(void)
{
    return Rfu.unk_ce8;
}

bool8 Rfu_IsMaster(void)
{
    return Rfu.parentChild;
}

void RfuVSync(void)
{
    rfu_LMAN_syncVBlank();
}

void ClearRecvCommands(void)
{
    CpuFill32(0, gRecvCmds, sizeof(gRecvCmds));
}

static void sub_8011AE8(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8011AFC(void)
{
    s32 i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();
    SetVBlankCallback(sub_8011AE8);
    if (IsWirelessAdapterConnected())
    {
        gLinkType = LINKTYPE_TRADE;
        SetWirelessCommType1();
        OpenLink();
        SeedRng(gMain.vblankCounter2);
        for (i = 0; i < 4; i++)
            gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_1D_MAP);
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        CreateTask_RfuIdle();
        SetMainCallback2(sub_8011BF8);
    }
}

bool32 IsUnionRoomListenTaskActive(void)
{
    return FuncIsActiveTask(Task_LinkRfu_UnionRoomListen);
}

void CreateTask_RfuIdle(void)
{
    if (!FuncIsActiveTask(Task_Idle))
        Rfu.idleTaskId = CreateTask(Task_Idle, 0);
}

void DestroyTask_RfuIdle(void)
{
     if (FuncIsActiveTask(Task_Idle) == TRUE)
        DestroyTask(Rfu.idleTaskId);
}

static void sub_8011BF8(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void InitializeRfuLinkManager_LinkLeader(u32 a0)
{
    Rfu.parentChild = MODE_PARENT;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(sub_801120C, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.availSlot_flag = sAvailSlots[a0 - 1];
    CreateTask_LinkLeaderSearchForChildren();
}

void InitializeRfuLinkManager_JoinGroup(void)
{
    Rfu.parentChild = MODE_CHILD;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(sub_8011404, sub_800ED34);
    CreateTask_JoinGroupSearchForParent();
}

void InitializeRfuLinkManager_EnterUnionRoom(void)
{
    Rfu.parentChild = 2;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(sub_8011674, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.linkRecovery_enable = 0;
    sRfuReqConfig.linkRecovery_period = 600;
    Rfu.searchTaskId = CreateTask(Task_LinkRfu_UnionRoomListen, 1);
}

static u16 ReadU16(const void *ptr)
{
    const u8 *ptr_ = ptr;
    return (ptr_[1] << 8) | (ptr_[0]);
}

static u8 GetPartnerIndexByNameAndTrainerID(const u8 *name, u16 id)
{
    u8 i;
    u8 idx = 0xFF;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        u16 trainerId = ReadU16(gRfuLinkStatus->partner[i].gname + 2);
        if (IsRfuSerialNumberValid(gRfuLinkStatus->partner[i].serialNo)
            && !StringCompare(name, gRfuLinkStatus->partner[i].uname)
            && id == trainerId)
        {
            idx = i;
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
                break;
        }
    }

    return idx;
}

static void RfuReqDisconnectSlot(u32 slot)
{
    rfu_REQ_disconnect(slot);
    rfu_waitREQComplete();
    Rfu.unk_ce2 &= ~(slot);
    rfu_clearSlot(1, Rfu.unk_cda);
    rfu_UNI_setSendData(Rfu.unk_ce2, Rfu.recvCmds, 70);
    Rfu.unk_cda = sub_800E87C(Rfu.unk_ce2);
}

void RequestDisconnectSlotByTrainerNameAndId(const u8 *name, u16 id)
{
    u8 var = GetPartnerIndexByNameAndTrainerID(name, id);
    if (var != 0xFF)
        RfuReqDisconnectSlot(1 << var);
}

void sub_8011DE0(u32 a0)
{
    if (a0 != 0)
    {
        s32 i;
        u8 var = 0;

        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (Rfu.linkPlayerIdx[i] == a0 && (Rfu.unk_ce2 >> i) & 1)
                var |= 1 << i;
        }
        if (var)
            sub_8011E94(var, 2);
    }
}

static void sub_8011E2C(u8 taskId)
{
    if (gSendCmd[0] == 0 && Rfu.unk_ce8 == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_0xED00);
        gSendCmd[1] = gTasks[taskId].data[0];
        gSendCmd[2] = gTasks[taskId].data[1];
        Rfu.playerCount -= sUnknown_082ED695[gTasks[taskId].data[0]];
        gSendCmd[3] = Rfu.playerCount;
        DestroyTask(taskId);
    }
}

static void sub_8011E94(u32 a0, u32 a1)
{
    u8 taskId = FindTaskIdByFunc(sub_8011E2C);
    if (taskId == TASK_NONE)
    {
        taskId = CreateTask(sub_8011E2C, 5);
        gTasks[taskId].data[0] = a0;
    }
    else
    {
        gTasks[taskId].data[0] |= a0;
    }

    gTasks[taskId].data[1] = a1;
}

static void Task_RfuReconnectWithParent(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (sub_800EE94())
    {
        u8 id = GetPartnerIndexByNameAndTrainerID((u8*)data, ReadU16(&data[8]));
        if (id != 0xFF)
        {
            if (gRfuLinkStatus->partner[id].slot != 0xFF)
            {
                Rfu.unk_c3d = id;
                if (IsParentSuccessfullyReconnected())
                    DestroyTask(taskId);
            }
            else if (GetHostRFUtgtGname()->activity == ACTIVITY_WONDER_CARD2
                  || GetHostRFUtgtGname()->activity == ACTIVITY_WONDER_NEWS2)
            {
                data[15]++;
            }
            else
            {
                RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x7000);
                DestroyTask(taskId);
            }
        }
        else
        {
            data[15]++;
            Rfu.unk_c3d = id;
        }
    }
    else
    {
        data[15]++;
    }

    if (data[15] > 240)
    {
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x7000);
        DestroyTask(taskId);
    }
}

void CreateTask_RfuReconnectWithParent(const u8 *name, u16 trainerId)
{
    u8 taskId;
    s16 *data;

    Rfu.status = RFU_STATUS_OK;
    taskId = CreateTask(Task_RfuReconnectWithParent, 3);
    data = gTasks[taskId].data;
    StringCopy((u8*)(data), name);
    data[8] = trainerId;
}

static bool32 ShouldRejectPartnerConnectionBasedOnActivity(s16 activity, struct GFtgtGname *partnerGname)
{
    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        if (partnerGname->activity != (ACTIVITY_CHAT | IN_UNION_ROOM))
            return TRUE;
    }
    else if (partnerGname->activity != IN_UNION_ROOM)
    {
        return TRUE;
    }
    else if (activity == (ACTIVITY_TRADE | IN_UNION_ROOM))
    {
        struct GFtgtGname *tradeGname = &Rfu.unk_10A;
        if (tradeGname->species == SPECIES_EGG)
        {
            if (partnerGname->species == tradeGname->species)
                return FALSE;
            else
                return TRUE;
        }
        else if (partnerGname->species != tradeGname->species
                 || partnerGname->level != tradeGname->level
                 || partnerGname->type != tradeGname->type)
        {
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_801209C(u8 taskId)
{
    if (Rfu.status == RFU_STATUS_NEW_CHILD_DETECTED)
        DestroyTask(taskId);

    if (++gTasks[taskId].data[0] > 300)
    {
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x7000);
        DestroyTask(taskId);
    }

    if (Rfu.parentId != 0 && lman.parent_child == 0)
    {
        u16 trainerId = ReadU16(Rfu.unk_10A.unk_00.playerTrainerId);
        u8 id = GetPartnerIndexByNameAndTrainerID(Rfu.playerName, trainerId);
        if (id != 0xFF)
        {
            if (!ShouldRejectPartnerConnectionBasedOnActivity(gTasks[taskId].data[1], (void *)gRfuLinkStatus->partner[id].gname))
            {
                if (gRfuLinkStatus->partner[id].slot != 0xFF && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[id].id, 0x5A))
                {
                    Rfu.state = 0xA;
                    DestroyTask(taskId);
                }
            }
            else
            {
                RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, 0x7000);
                DestroyTask(taskId);
            }
        }
    }
}

void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 activity)
{
    u8 taskId, taskId2;

    Rfu.unk_ccf = 0;
    Rfu.status = RFU_STATUS_OK;
    StringCopy(Rfu.playerName, name);
    memcpy(&Rfu.unk_10A, structPtr, RFU_GAME_NAME_LENGTH);
    rfu_LMAN_forceChangeSP();
    taskId = CreateTask(sub_801209C, 2);
    gTasks[taskId].data[1] = activity;
    taskId2 = FindTaskIdByFunc(Task_LinkRfu_UnionRoomListen);
    if (activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        if (taskId2 != TASK_NONE)
            gTasks[taskId2].data[7] = 1;
    }
    else
    {
        if (taskId2 != TASK_NONE)
            gTasks[taskId2].data[7] = 0;
    }
}

bool8 IsRfuRecoveringFromLinkLoss(void)
{
    if (Rfu.linkLossRecoveryState == 1)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8012240(void)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((lman.acceptSlot_flag >> i) & 1 && Rfu.partnerSendStatuses[i] == RFU_STATUS_OK)
            return FALSE;
    }

    return TRUE;
}

static void Debug_PrintEmpty(void)
{
    s32 i;

    for (i = 0; i < 20; i++)
        Debug_PrintString(sASCII_30Commas, 0, i);
}

static void Debug_PrintStatus(void)
{
    s32 i, j;

    Debug_PrintNum(GetBlockReceivedStatus(), 0x1C, 0x13, 2);
    Debug_PrintNum(gRfuLinkStatus->connSlotFlag, 0x14, 1, 1);
    Debug_PrintNum(gRfuLinkStatus->linkLossSlotFlag, 0x17, 1, 1);
    if (Rfu.parentChild == MODE_PARENT)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((gRfuLinkStatus->getNameFlag >> i) & 1)
            {
                Debug_PrintNum(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                Debug_PrintString((void*)gRfuLinkStatus->partner[i].gname, 6, i + 3);
                Debug_PrintString(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            for (j = 0; j < (int)ARRAY_COUNT(Rfu.unk_14[0]); j++)
            {
                Debug_PrintNum(Rfu.unk_14[i][j], j * 2, i + 11, 2);
            }
        }
        Debug_PrintString(sASCII_NowSlot, 1, 0xF);
    }
    else if (gRfuLinkStatus->connSlotFlag != 0 && gRfuLinkStatus->getNameFlag != 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            Debug_PrintNum(0, 1, i + 3, 4);
            Debug_PrintString(sASCII_15Commas, 6, i + 3);
            Debug_PrintString(sASCII_8Commas, 0x16, i + 3);
        }
        Debug_PrintNum(gRfuLinkStatus->partner[Rfu.childSlot].serialNo, 1, 3, 4);
        Debug_PrintString((void*)gRfuLinkStatus->partner[Rfu.childSlot].gname, 6, 3);
        Debug_PrintString(gRfuLinkStatus->partner[Rfu.childSlot].uname, 0x16, 3);
    }
    else
    {
        for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
        {
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
            {
                Debug_PrintNum(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                Debug_PrintNum(gRfuLinkStatus->partner[i].id, 6, i + 3, 4);
                Debug_PrintString(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (; i < RFU_CHILD_MAX; i++)
        {
            Debug_PrintNum(0, 1, i + 3, 4);
            Debug_PrintString(sASCII_15Commas, 6, i + 3);
            Debug_PrintString(sASCII_8Commas, 0x16, i + 3);
        }
    }
}

static u32 GetRfuSendQueueLength(void)
{
    return Rfu.sendQueue.count;
}

u32 GetRfuRecvQueueLength(void)
{
    return Rfu.recvQueue.count;
}

static void Task_Idle(u8 taskId)
{

}
