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
#include "mystery_gift_menu.h"

enum {
    RFUSTATE_INIT,
    RFUSTATE_INIT_END,
    RFUSTATE_PARENT_CONNECT,
    RFUSTATE_PARENT_CONNECT_END,
    RFUSTATE_STOP_MANAGER,
    RFUSTATE_STOP_MANAGER_END,
    RFUSTATE_CHILD_CONNECT,
    RFUSTATE_CHILD_CONNECT_END,
    RFUSTATE_UNUSED,
    RFUSTATE_RECONNECTED,
    RFUSTATE_CONNECTED,
    RFUSTATE_CHILD_TRY_JOIN,
    RFUSTATE_CHILD_JOINED,
    RFUSTATE_UR_PLAYER_EXCHANGE,
    RFUSTATE_UR_STOP_MANAGER,
    RFUSTATE_UR_STOP_MANAGER_END,
    RFUSTATE_UR_FINALIZE,
};
// These states are used for different purposes
// depending on the link mode (parent, child, union room)
#define RFUSTATE_PARENT_FINALIZE_START 17
#define RFUSTATE_PARENT_FINALIZE       18
#define RFUSTATE_UR_CONNECT     17
#define RFUSTATE_UR_CONNECT_END 18
#define RFUSTATE_FINALIZED 20

// States for the 'receiving' field of RfuBlockSend
enum {
    RECV_STATE_READY,
    RECV_STATE_RECEIVING,
    RECV_STATE_FINISHED,
};

struct SioInfo
{
    char magic[sizeof("PokemonSioInfo")];
    u8 playerCount;
    u8 linkPlayerIdx[RFU_CHILD_MAX];
    struct LinkPlayer linkPlayers[MAX_RFU_PLAYERS];
    u8 filler[92];
};

// Struct is mostly empty, presumably because usage of
// its fields was largely removed before release
struct RfuDebug
{
    u8 unused0[6];
    u16 recvCount;
    u8 unused1[6];
    vu8 unkFlag;
    u8 childJoinCount;
    u8 unused2[84];
    u16 blockSendFailures;
    u8 unused3[29];
    u8 blockSendTime;
    u8 unused4[88];
};

u32 gRfuAPIBuffer[RFU_API_BUFF_SIZE_RAM / 4];
struct RfuManager gRfu;

static u8 sHeldKeyCount;
static u8 sResendBlock8[CMD_LENGTH * 2];
static u16 sResendBlock16[CMD_LENGTH];

EWRAM_DATA struct RfuGameData gHostRfuGameData = {};
EWRAM_DATA u8 gHostRfuUsername[RFU_USER_NAME_LENGTH] = {};
static EWRAM_DATA INIT_PARAM sRfuReqConfig = {};
static EWRAM_DATA struct RfuDebug sRfuDebug = {};

static void ResetSendDataManager(struct RfuBlockSend *);
static void InitChildRecvBuffers(void);
static void InitParentSendData(void);
static void MSCCallback_Child(u16);
static void MSCCallback_Parent(u16);
static void UpdateBackupQueue(void);
static void Task_PlayerExchange(u8);
static void Task_PlayerExchangeUpdate(u8);
static void Task_PlayerExchangeChat(u8);
static void RfuHandleReceiveCommand(u8);
static void CallRfuFunc(void);
static void RfuPrepareSendBuffer(u16);
static void HandleBlockSend(void);
static void SendNextBlock(void);
static void SendLastBlock(void);
static u8 GetPartnerIndexByNameAndTrainerID(const u8 *, u16);
static void UpdateChildStatuses(void);
static s32 GetJoinGroupStatus(void);
static void ClearSelectedLinkPlayerIds(u16);
static void ValidateAndReceivePokemonSioInfo(void *);
static void ParentResetChildRecvMetadata(s32);
static void CB2_RfuIdle(void);
static void RfuReqDisconnectSlot(u32);
static void SendDisconnectCommand(u32, u32);
static void Task_TryConnectToUnionRoomParent(u8);
static void Debug_PrintEmpty(void);
static void Task_Idle(u8);

static const INIT_PARAM sRfuReqConfigTemplate = {
    .maxMFrame = 4,
    .MC_TimerCount = 32,
    .availSlot_flag = 0,
    .mboot_flag = 0,
    .serialNo = RFU_SERIAL_GAME,
    .gameName = (void *)&gHostRfuGameData,
    .userName = gHostRfuUsername,
    .fastSearchParent_flag = TRUE,
    .linkRecovery_enable = FALSE,
    .linkRecovery_period = 600,
    .NI_failCounter_limit = 300
};

static const u8 sAvailSlots[] = {
    [1] = AVAIL_SLOT1,
    [2] = AVAIL_SLOT2,
    [3] = AVAIL_SLOT3,
    [4] = AVAIL_SLOT4
};

#define BLOCK_MASK(bitNum)((1 << (bitNum)) - 1)
static const u32 sAllBlocksReceived[] = {
    BLOCK_MASK(0),
    BLOCK_MASK(1),
    BLOCK_MASK(2),
    BLOCK_MASK(3),
    BLOCK_MASK(4),
    BLOCK_MASK(5),
    BLOCK_MASK(6),
    BLOCK_MASK(7),
    BLOCK_MASK(8),
    BLOCK_MASK(9),
    BLOCK_MASK(10),
    BLOCK_MASK(11),
    BLOCK_MASK(12),
    BLOCK_MASK(13),
    BLOCK_MASK(14),
    BLOCK_MASK(15),
    BLOCK_MASK(16),
    BLOCK_MASK(17),
    BLOCK_MASK(18),
    BLOCK_MASK(19),
    BLOCK_MASK(20),
    BLOCK_MASK(21),
    BLOCK_MASK(22),
    BLOCK_MASK(23),
    BLOCK_MASK(24),
};
#undef BLOCK_MASK

static const u8 sSlotToLinkPlayerTableId[] = {
    0, 0, 1,
    1, 2, 2,
    2, 2, 3
};

// Effectively just returns the number of bits set in the index value
// Used for masks of the other players, MAX_RFU_PLAYERS - 1 excludes self
static const u8 sPlayerBitsToCount[1 << (MAX_RFU_PLAYERS - 1)] = {
    0, // 0000
    1, // 0001
    1, // 0010
    2, // 0011
    1, // 0100
    2, // 0101
    2, // 0110
    3, // 0111
    1, // 1000
    2, // 1001
    2, // 1010
    3, // 1011
    2, // 1100
    3, // 1101
    3, // 1110
    4  // 1111
};

// If the 4 bits representing child slots were an array, this table
// would return the index of the most recently set bit
static const u8 sPlayerBitsToNewChildIdx[1 << (MAX_RFU_PLAYERS - 1)] = {
    0, // 0000
    0, // 0001
    1, // 0010
    0, // 0011
    2, // 0100
    0, // 0101
    1, // 0110
    0, // 0111
    3, // 1000
    0, // 1001
    1, // 1010
    0, // 1011
    2, // 1100
    0, // 1101
    1, // 1110
    0  // 1111
};

static const struct BlockRequest sBlockRequests[] = {
    [BLOCK_REQ_SIZE_NONE] = { gBlockSendBuffer, 200 },
    [BLOCK_REQ_SIZE_200]  = { gBlockSendBuffer, 200 },
    [BLOCK_REQ_SIZE_100]  = { gBlockSendBuffer, 100 },
    [BLOCK_REQ_SIZE_220]  = { gBlockSendBuffer, 220 },
    [BLOCK_REQ_SIZE_40]   = { gBlockSendBuffer,  40 }
};

static const u16 sAcceptedSerialNos[] = {
    RFU_SERIAL_GAME,
    RFU_SERIAL_WONDER_DISTRIBUTOR,
    RFU_SERIAL_UNKNOWN,
    RFU_SERIAL_END
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

// List of additional tasks to destroy (if active) when the RFU shuts down
static const TaskFunc sShutdownTasks[] = {
    Task_PlayerExchange,
    Task_PlayerExchangeUpdate,
    Task_PlayerExchangeChat
};

static const char sASCII_PokemonSioInfo[] = "PokemonSioInfo";
static const char sASCII_LinkLossDisconnect[] = "LINK LOSS DISCONNECT!";
static const char sASCII_LinkLossRecoveryNow[] = "LINK LOSS RECOVERY NOW";
ALIGNED(4) static const char sASCII_30Spaces[] = {"                              "};
static const char sASCII_15Spaces[] = {"               "};
static const char sASCII_8Spaces[] = {"        "};
ALIGNED(4) static const char sASCII_Space[] = {" "};
static const char sASCII_Asterisk[] = {"*"};
static const char sASCII_NowSlot[] = "NOWSLOT";

static const char sASCII_ClockCmds[][12] = {
    "           ",
    "CLOCK DRIFT",
    "BUSY SEND  ",
    "CMD REJECT ",
    "CLOCK SLAVE"
};

static const char sASCII_ChildParentSearch[][8] = {
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
    u8 errorState = gRfu.errorState;
    CpuFill16(0, &gRfu, sizeof(gRfu));
    gRfu.errorState = errorState;
    gRfu.parentChild = 0xFF;
    if (gRfu.errorState != RFU_ERROR_STATE_IGNORE)
        gRfu.errorState = RFU_ERROR_STATE_NONE;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        ResetSendDataManager(&gRfu.recvBlock[i]);
    ResetSendDataManager(&gRfu.sendBlock);
    RfuRecvQueue_Reset(&gRfu.recvQueue);
    RfuSendQueue_Reset(&gRfu.sendQueue);
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
    if (!rfu_initializeAPI((void *)gRfuAPIBuffer, sizeof(gRfuAPIBuffer), &gIntrTable[1], TRUE))
    {
        gLinkType = 0;
        ClearSavedLinkPlayers();
        RfuSetIgnoreError(FALSE);
        ResetLinkRfuGFLayer();
        rfu_setTimerInterrupt(3, &gIntrTable[2]);
    }
}

static void Task_ParentSearchForChildren(u8 taskId)
{
    UpdateChildStatuses();
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_PARENT_CONNECT:
        rfu_LMAN_establishConnection(gRfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        gRfu.state = RFUSTATE_PARENT_CONNECT_END;
        gTasks[taskId].data[1] = 6;
        break;
    case RFUSTATE_PARENT_CONNECT_END:
        break;
    case RFUSTATE_STOP_MANAGER:
        rfu_LMAN_stopManager(FALSE);
        gRfu.state = RFUSTATE_STOP_MANAGER_END;
        break;
    case RFUSTATE_STOP_MANAGER_END:
        break;
    case RFUSTATE_PARENT_FINALIZE:
        gRfu.parentFinished = FALSE;
        rfu_LMAN_setMSCCallback(MSCCallback_Parent);
        InitChildRecvBuffers();
        InitParentSendData();
        gRfu.state = RFUSTATE_FINALIZED;
        gTasks[taskId].data[1] = 8;
        CreateTask(Task_PlayerExchange, 5);
        DestroyTask(taskId);
        break;
    }
}

s32 Rfu_GetIndexOfNewestChild(u8 bits)
{
    return sPlayerBitsToNewChildIdx[bits];
}

static void SetLinkPlayerIdsFromSlots(s32 baseSlots, s32 addSlots)
{
    u8 i;
    u8 baseId = 1;
    s32 baseSlotsCopy = baseSlots;
    s32 newId = 0;
    if (addSlots == -1)
    {
        // Initialize
        for (i = 0; i < RFU_CHILD_MAX; baseSlots >>= 1, i++)
        {
            if (baseSlots & 1)
            {
                gRfu.linkPlayerIdx[i] = baseId;
                baseId++;
            }
        }
    }
    else
    {
        // Clear id for any empty slot
        for (i = 0; i < RFU_CHILD_MAX; baseSlotsCopy >>= 1, i++)
        {
            if (!(baseSlotsCopy & 1))
                gRfu.linkPlayerIdx[i] = 0;
        }

        // Get starting id by checking existing slots
        for (baseId = RFU_CHILD_MAX; baseId != 0; baseId--)
        {
            for (i = 0; i < RFU_CHILD_MAX && gRfu.linkPlayerIdx[i] != baseId; i++)
                ;
            if (i == RFU_CHILD_MAX)
                newId = baseId;
        }

        // Set id for new slots
        for (addSlots &= ~baseSlots, i = 0; i < RFU_CHILD_MAX; addSlots >>= 1, i++)
        {
            if (addSlots & 1)
                gRfu.linkPlayerIdx[i] = newId++;
        }
    }
}

static void Task_ChildSearchForParent(u8 taskId)
{
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU((INIT_PARAM *)&sRfuReqConfigTemplate);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_CHILD_CONNECT:
        rfu_LMAN_establishConnection(gRfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        gRfu.state = RFUSTATE_CHILD_CONNECT_END;
        gTasks[taskId].data[1] = 7;
        break;
    case RFUSTATE_CHILD_CONNECT_END:
        break;
    case RFUSTATE_RECONNECTED:
        gTasks[taskId].data[1] = 10;
        break;
    case RFUSTATE_CHILD_TRY_JOIN:
        switch (GetJoinGroupStatus())
        {
        case RFU_STATUS_JOIN_GROUP_OK:
            gRfu.state = RFUSTATE_CHILD_JOINED;
            break;
        case RFU_STATUS_JOIN_GROUP_NO:
        case RFU_STATUS_LEAVE_GROUP:
            rfu_LMAN_requestChangeAgbClockMaster();
            gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
            DestroyTask(taskId);
            break;
        }
        break;
    case RFUSTATE_CHILD_JOINED:
    {
        u8 bmChildSlot = 1 << gRfu.childSlot;
        rfu_clearSlot(TYPE_NI_SEND | TYPE_NI_RECV, gRfu.childSlot);
        rfu_setRecvBuffer(TYPE_UNI, gRfu.childSlot, gRfu.childRecvQueue, sizeof(gRfu.childRecvQueue));
        rfu_UNI_setSendData(bmChildSlot, gRfu.childSendBuffer,  sizeof(gRfu.childSendBuffer));
        gTasks[taskId].data[1] = 8;
        DestroyTask(taskId);
        if (sRfuDebug.childJoinCount == 0)
        {
            Debug_PrintEmpty();
            sRfuDebug.childJoinCount++;
        }
        CreateTask(Task_PlayerExchange, 5);
        break;
    }
    }
}

static void InitChildRecvBuffers(void)
{
    u8 i;
    u8 acceptSlot = lman.acceptSlot_flag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (acceptSlot & 1)
        {
            rfu_setRecvBuffer(TYPE_UNI, i, gRfu.childRecvBuffer[i], sizeof(gRfu.childRecvBuffer[0]));
            rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, i);
        }
        acceptSlot >>= 1;
    }
}

static void InitParentSendData(void)
{
    u8 acceptSlot = lman.acceptSlot_flag;
    rfu_UNI_setSendData(acceptSlot, gRfu.recvCmds, sizeof(gRfu.recvCmds));
    gRfu.parentSendSlot = Rfu_GetIndexOfNewestChild(acceptSlot);
    gRfu.parentSlots = acceptSlot;
    SetLinkPlayerIdsFromSlots(acceptSlot, -1);
    gRfu.parentChild = MODE_PARENT;
}

#define tConnectingForChat data[7]

static void Task_UnionRoomListen(u8 taskId)
{
    if (GetHostRfuGameData()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM) && RfuGetStatus() == RFU_STATUS_NEW_CHILD_DETECTED)
    {
        rfu_REQ_disconnect(lman.acceptSlot_flag);
        rfu_waitREQComplete();
        RfuSetStatus(RFU_STATUS_OK, 0);
    }
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_UR_CONNECT:
        rfu_LMAN_establishConnection(MODE_P_C_SWITCH, 0, 240, (u16 *)sAcceptedSerialNos);
        rfu_LMAN_setMSCCallback(MSCCallback_Child);
        gRfu.state = RFUSTATE_UR_CONNECT_END;
        break;
    case RFUSTATE_UR_CONNECT_END:
        break;
    case RFUSTATE_UR_PLAYER_EXCHANGE:
        if (rfu_UNI_setSendData(1 << gRfu.childSlot, gRfu.childSendBuffer, sizeof(gRfu.childSendBuffer)) == 0)
        {
            gRfu.parentChild = MODE_CHILD;
            DestroyTask(taskId);
            if (gTasks[taskId].tConnectingForChat)
                CreateTask(Task_PlayerExchangeChat, 1);
            else
                CreateTask(Task_PlayerExchange, 5);
        }
        break;
    case RFUSTATE_UR_STOP_MANAGER:
        rfu_LMAN_stopManager(FALSE);
        gRfu.state = RFUSTATE_UR_STOP_MANAGER_END;
        break;
    case RFUSTATE_UR_STOP_MANAGER_END:
        break;
    case RFUSTATE_UR_FINALIZE:
        gRfu.parentFinished = FALSE;
        rfu_LMAN_setMSCCallback(MSCCallback_Parent);
        UpdateGameData_GroupLockedIn(TRUE);
        InitChildRecvBuffers();
        InitParentSendData();
        gRfu.state = RFUSTATE_FINALIZED;
        gTasks[taskId].data[1] = 8;
        gRfu.parentChild = MODE_PARENT;
        CreateTask(Task_PlayerExchange, 5);
        gRfu.playerExchangeActive = TRUE;
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

// Argument is provided by the RFU and is unused.
static void MSCCallback_Child(u16 REQ_commandID)
{
    s32 i;

    for (i = 0; i < COMM_SLOT_LENGTH; i++)
        gRfu.childSendBuffer[i] = 0;

    rfu_REQ_recvData();
    rfu_waitREQComplete();
    if (gRfuSlotStatusUNI[gRfu.childSlot]->recv.newDataFlag)
    {
        gRfu.childSendCount++;
        RfuRecvQueue_Enqueue(&gRfu.recvQueue, gRfu.childRecvQueue);
        sRfuDebug.recvCount++;
        UpdateBackupQueue();
        rfu_UNI_readySendData(gRfu.childSlot);
        rfu_UNI_clearRecvNewDataFlag(gRfu.childSlot);
    }
    rfu_LMAN_REQ_sendData(TRUE);
}

// Argument is provided by the RFU and is unused.
static void MSCCallback_Parent(u16 REQ_commandID)
{
    gRfu.parentFinished = TRUE;
}

void LinkRfu_Shutdown(void)
{
    u8 i;

    rfu_LMAN_powerDownRFU();
    if (gRfu.parentChild == MODE_PARENT)
    {
        // Stop parent searching for children
        if (FuncIsActiveTask(Task_ParentSearchForChildren) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (gRfu.parentChild == MODE_CHILD)
    {
        // Stop child searching for parent
        if (FuncIsActiveTask(Task_ChildSearchForParent) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (gRfu.parentChild == MODE_P_C_SWITCH)
    {
        // Stop parent-child switching mode (union room)
        if (FuncIsActiveTask(Task_UnionRoomListen) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }

    // Destroy additional tasks
    for (i = 0; i < ARRAY_COUNT(sShutdownTasks); i++)
    {
        if (FuncIsActiveTask(sShutdownTasks[i]) == TRUE)
            DestroyTask(FindTaskIdByFunc(sShutdownTasks[i]));
    }
}

static void CreateTask_ParentSearchForChildren(void)
{
    gRfu.searchTaskId = CreateTask(Task_ParentSearchForChildren, 1);
}

// If no parent ID (or if child connection not ready) can't reconnect with parent yet
static bool8 CanTryReconnectParent(void)
{
    if (gRfu.state == RFUSTATE_CHILD_CONNECT_END && gRfu.parentId)
        return TRUE;
    return FALSE;
}

static bool32 TryReconnectParent(void)
{
    if (gRfu.state == RFUSTATE_CHILD_CONNECT_END && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[gRfu.reconnectParentId].id, 240))
    {
        gRfu.state = RFUSTATE_RECONNECTED;
        return TRUE;
    }
    return FALSE;
}

static void CreateTask_ChildSearchForParent(void)
{
    gRfu.searchTaskId = CreateTask(Task_ChildSearchForParent, 1);
}

bool8 LmanAcceptSlotFlagIsNotZero(void)
{
    if (lman.acceptSlot_flag)
        return TRUE;
    return FALSE;
}

void LinkRfu_StopManagerAndFinalizeSlots(void)
{
    gRfu.state = RFUSTATE_STOP_MANAGER;
    gRfu.acceptSlot_flag = lman.acceptSlot_flag;
}

bool32 WaitRfuState(bool32 force)
{
    if (gRfu.state == RFUSTATE_PARENT_FINALIZE_START || force)
    {
        gRfu.state = RFUSTATE_PARENT_FINALIZE;
        return TRUE;
    }
    return FALSE;
}

void StopUnionRoomLinkManager(void)
{
    gRfu.state = RFUSTATE_UR_STOP_MANAGER;
}

// Unused
static void ReadySendDataForSlots(u8 slots)
{
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (slots & 1)
        {
            rfu_UNI_readySendData(i);
            break;
        }
        slots >>= 1;
    }
}

static void ReadAllPlayerRecvCmds(void)
{
    s32 i, j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        struct RfuManager *rfu = &gRfu;
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            rfu->recvCmds[i][j][1] = gRecvCmds[i][j] >> 8;
            rfu->recvCmds[i][j][0] = gRecvCmds[i][j];
        }
    }
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
}

static void MoveSendCmdToRecv(void)
{
    s32 i;
    for (i = 0; i < CMD_LENGTH - 1; i++)
        gRecvCmds[0][i] = gSendCmd[i];

    for (i = 0; i < CMD_LENGTH - 1; i++)
        gSendCmd[i] = 0;
}

static void UpdateBackupQueue(void)
{
    if (gRfu.linkRecovered)
    {
        bool8 backupEmpty = RfuBackupQueue_Dequeue(&gRfu.backupQueue, gRfu.childSendBuffer);

        if (gRfu.backupQueue.count == 0)
            gRfu.linkRecovered = FALSE;

        if (backupEmpty)
            return;
    }
    if (!gRfu.linkRecovered)
    {
        RfuSendQueue_Dequeue(&gRfu.sendQueue, gRfu.childSendBuffer);
        RfuBackupQueue_Enqueue(&gRfu.backupQueue, gRfu.childSendBuffer);
    }
}

bool32 IsRfuRecvQueueEmpty(void)
{
    s32 i;
    s32 j;

    if (!gRfuLinkStatus->sendSlotUNIFlag)
        return FALSE;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        for (j = 0; j < CMD_LENGTH - 1; j++)
            if (gRecvCmds[i][j] != 0)
                return FALSE;

    return TRUE;
}

static bool32 RfuMain1_Parent(void)
{
    if (gRfu.state < RFUSTATE_FINALIZED)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
    else
    {
        gRfu.parentFinished = FALSE;
        if ((gRfu.parentSlots & gRfuLinkStatus->connSlotFlag) == gRfu.parentSlots && (gRfu.parentSlots & gRfuLinkStatus->connSlotFlag))
        {
            if (!gRfu.parentMain2Failed)
            {
                if (gRfu.disconnectSlots)
                {
                    RfuReqDisconnectSlot(gRfu.disconnectSlots);
                    gRfu.disconnectSlots = 0;
                    if (gRfu.disconnectMode == RFU_DISCONNECT_ERROR)
                    {
                        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_8);
                        RfuSetErrorParams(F_RFU_ERROR_8);
                        return FALSE;
                    }
                    if (!lman.acceptSlot_flag)
                    {
                        LinkRfu_Shutdown();
                        gReceivedRemoteLinkPlayers = 0;
                        return FALSE;
                    }
                }
                ReadAllPlayerRecvCmds();
                rfu_UNI_readySendData(gRfu.parentSendSlot);
                rfu_LMAN_REQ_sendData(TRUE);
            }
            else
            {
                rfu_REQ_PARENT_resumeRetransmitAndChange();
            }
            gRfu.runParentMain2 = TRUE;
        }
    }
    return FALSE;
}

static bool32 RfuMain2_Parent(void)
{
    u16 i;
    u16 flags;
    u8 r0;
    u16 j;
    bool8 failed;

    if (gRfu.state >= RFUSTATE_FINALIZED && gRfu.runParentMain2 == TRUE)
    {
        rfu_waitREQComplete();
        while (gRfu.parentFinished == FALSE)
        {
            if (gRfu.errorState != RFU_ERROR_STATE_NONE)
                return FALSE;
        }
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        if ((lman.parentAck_flag & gRfu.parentSlots) == gRfu.parentSlots)
        {
            gRfu.parentMain2Failed = FALSE;
            sRfuDebug.recvCount++;
            flags = lman.acceptSlot_flag;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (flags & 1)
                {
                    if (gRfu.childRecvBuffer[i][1])
                    {
                        if (gRfu.childRecvIds[i] != 0xFF && (gRfu.childRecvBuffer[i][0] >> 5) != ((gRfu.childRecvIds[i] + 1) & 7))
                        {
                            if (++gRfu.numChildRecvErrors[i] > 4)
                                RfuSetErrorParams(F_RFU_ERROR_8 | F_RFU_ERROR_1);
                        }
                        else
                        {
                            gRfu.childRecvIds[i] = gRfu.childRecvBuffer[i][0] / 32;
                            gRfu.numChildRecvErrors[i] = 0;
                            gRfu.childRecvBuffer[i][0] &= 0x1f;
                            r0 = gRfu.linkPlayerIdx[i];
                            for (j = 0; j < CMD_LENGTH - 1; j++)
                            {
                                gRecvCmds[r0][j] = (gRfu.childRecvBuffer[i][(j << 1) + 1] << 8) | gRfu.childRecvBuffer[i][(j << 1) + 0];
                                gRfu.childRecvBuffer[i][(j << 1) + 1] = 0;
                                gRfu.childRecvBuffer[i][(j << 1) + 0] = 0;
                            }
                        }
                    }
                    rfu_UNI_clearRecvNewDataFlag(i);
                }
                flags >>= 1;
            }
            MoveSendCmdToRecv();
            RfuHandleReceiveCommand(0);
            CallRfuFunc();
            if (gRfu.nextChildBits && !gRfu.stopNewConnections)
            {
                sRfuDebug.unkFlag = FALSE;
                rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, gRfu.parentSendSlot);
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((gRfu.nextChildBits >> i) & 1)
                        rfu_setRecvBuffer(TYPE_UNI, i, gRfu.childRecvBuffer[i], sizeof(gRfu.childRecvBuffer[0]));
                }
                SetLinkPlayerIdsFromSlots(gRfu.parentSlots, gRfu.parentSlots | gRfu.nextChildBits);
                gRfu.incomingChild = gRfu.nextChildBits;
                gRfu.parentSlots |= gRfu.nextChildBits;
                gRfu.nextChildBits = 0;
                rfu_UNI_setSendData(gRfu.parentSlots, gRfu.recvCmds, sizeof(gRfu.recvCmds));
                gRfu.parentSendSlot = Rfu_GetIndexOfNewestChild(gRfu.parentSlots);
                CreateTask(Task_PlayerExchangeUpdate, 0);
            }
        }
        else
        {
            gRfu.parentMain2Failed = TRUE;
            gRfu.runParentMain2 = FALSE;
        }
        gRfu.runParentMain2 = FALSE;
    }
    failed = gRfu.parentMain2Failed;
    return gRfuLinkStatus->sendSlotUNIFlag ? failed & 1 : FALSE;
}

static void ChildBuildSendCmd(u16 *sendCmd, u8 *dst)
{
    s32 i;

    if (sendCmd[0])
    {
        sendCmd[0] |= (gRfu.childSendCmdId << 5);
        gRfu.childSendCmdId = (gRfu.childSendCmdId + 1) & 7;
        for (i = 0; i < CMD_LENGTH - 1; i++)
        {
            dst[2 * i + 1] = sendCmd[i] >> 8;
            dst[2 * i + 0] = sendCmd[i];
        }
    }
    else
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            dst[i] = 0;
    }
}

static bool32 RfuMain1_Child(void)
{
    u8 i;
    u8 j;
    u8 recv[MAX_RFU_PLAYERS * (2 * (CMD_LENGTH - 1))];
    u8 send[2 * (CMD_LENGTH - 1)];
    u8 status;

    RfuRecvQueue_Dequeue(&gRfu.recvQueue, recv);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
            gRecvCmds[i][j] = (recv[i * COMM_SLOT_LENGTH + (j * 2) + 1] << 8)
                             | recv[i * COMM_SLOT_LENGTH + (j * 2) + 0];
    }
    RfuHandleReceiveCommand(0);
    if (lman.childClockSlave_flag == 0 && gRfu.disconnectMode != RFU_DISCONNECT_NONE)
    {
        rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
        rfu_waitREQComplete();
        status = RfuGetStatus();
        if (status != RFU_STATUS_FATAL_ERROR && status != RFU_STATUS_JOIN_GROUP_NO && status != RFU_STATUS_LEAVE_GROUP)
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_8);
        rfu_clearAllSlot();
        gReceivedRemoteLinkPlayers = FALSE;
        gRfu.callback = NULL;
        if (gRfu.disconnectMode == RFU_DISCONNECT_ERROR)
        {
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_8);
            RfuSetErrorParams(F_RFU_ERROR_5 | F_RFU_ERROR_8);
        }
        lman.state = lman.next_state = 0;
        gRfu.disconnectMode = RFU_DISCONNECT_NONE;
    }
    if (gRfu.childSendCount)
    {
        gRfu.childSendCount--;
        CallRfuFunc();
        ChildBuildSendCmd(gSendCmd, send);
        RfuSendQueue_Enqueue(&gRfu.sendQueue, send);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i] = 0;
    }
    return IsRfuRecvQueueEmpty();
}

static void HandleSendFailure(u8 unused, u32 flags)
{
    s32 i, j, temp;

    const u8 *payload = gRfu.sendBlock.payload;
    for (i = 0; i < gRfu.sendBlock.count; i++)
    {
        if (!(flags & 1))
        {
            sResendBlock16[0] = RFUCMD_SEND_BLOCK | i;
            for (j = 0; j < CMD_LENGTH - 1; j++)
            {
                temp = j * 2;
                sResendBlock16[j + 1] = (payload[(COMM_SLOT_LENGTH - 2) * i + temp + 1] << 8)
                                       | payload[(COMM_SLOT_LENGTH - 2) * i + temp + 0];
            }
            for (j = 0; j < CMD_LENGTH - 1; j++)
            {
                temp = j * 2;
                sResendBlock8[temp + 1] = sResendBlock16[j] >> 8;
                sResendBlock8[temp + 0] = sResendBlock16[j];
            }
            RfuSendQueue_Enqueue(&gRfu.sendQueue, sResendBlock8);
            gRfu.sendBlock.failedFlags |= (1 << i);
        }
        flags >>= 1;
    }
}

void Rfu_SetBlockReceivedFlag(u8 linkPlayerId)
{
    if (gRfu.parentChild == MODE_PARENT && linkPlayerId)
        gRfu.numBlocksReceived[linkPlayerId] = 1;
    else
        gRfu.blockReceived[linkPlayerId] = TRUE;
}

void Rfu_ResetBlockReceivedFlag(u8 linkPlayerId)
{
    gRfu.blockReceived[linkPlayerId] = FALSE;
    gRfu.recvBlock[linkPlayerId].receiving = RECV_STATE_READY;
}

static u8 LoadLinkPlayerIds(const u8 *ids)
{
    u8 i;
    if (gRfu.parentChild == MODE_PARENT)
        return FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
        gRfu.linkPlayerIdx[i] = ids[i];

    return ids[gRfu.childSlot];
}

static void SendKeysToRfu(void)
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

struct RfuGameData *GetHostRfuGameData(void)
{
    return &gHostRfuGameData;
}

bool32 IsSendingKeysToRfu(void)
{
    return gRfu.callback == SendKeysToRfu;
}

void StartSendingKeysToRfu(void)
{
    gRfu.callback = SendKeysToRfu;
}

void ClearLinkRfuCallback(void)
{
    gRfu.callback = NULL;
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
    if (gRfu.callback == NULL)
        gRfu.callback = Rfu_BerryBlenderSendHeldKeys;
}

static void RfuHandleReceiveCommand(u8 unused)
{
    u16 i;
    u16 j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        switch (gRecvCmds[i][0] & RFUCMD_MASK)
        {
        case RFUCMD_SEND_PLAYER_IDS_NEW:
            if (gRfu.parentChild == MODE_CHILD && gReceivedRemoteLinkPlayers)
                return;
            // fallthrough
        case RFUCMD_SEND_PLAYER_IDS:
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
            {
                gRfu.playerCount = gRecvCmds[i][1];
                gRfu.multiplayerId = LoadLinkPlayerIds((u8 *)(gRecvCmds[i] + 2));
            }
            break;
        case RFUCMD_SEND_BLOCK_INIT:
            if (gRfu.recvBlock[i].receiving == RECV_STATE_READY)
            {
                gRfu.recvBlock[i].next = 0;
                gRfu.recvBlock[i].count = gRecvCmds[i][1];
                gRfu.recvBlock[i].owner = gRecvCmds[i][2];
                gRfu.recvBlock[i].receivedFlags = 0;
                gRfu.recvBlock[i].receiving = RECV_STATE_RECEIVING;
                gRfu.blockReceived[i] = FALSE;
            }
            break;
        case RFUCMD_SEND_BLOCK:
            if (gRfu.recvBlock[i].receiving == RECV_STATE_RECEIVING)
            {
                gRfu.recvBlock[i].next = gRecvCmds[i][0] & 0xff;
                gRfu.recvBlock[i].receivedFlags |= (1 << gRfu.recvBlock[i].next);
                for (j = 0; j < 6; j++)
                    gBlockRecvBuffer[i][gRfu.recvBlock[i].next * 6 + j] = gRecvCmds[i][j + 1];
                if (gRfu.recvBlock[i].receivedFlags == sAllBlocksReceived[gRfu.recvBlock[i].count])
                {
                    gRfu.recvBlock[i].receiving = RECV_STATE_FINISHED;
                    Rfu_SetBlockReceivedFlag(i);
                    if (GetHostRfuGameData()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && gReceivedRemoteLinkPlayers && gRfu.parentChild == MODE_CHILD)
                        ValidateAndReceivePokemonSioInfo(gBlockRecvBuffer);
                }
            }
            break;
        case RFUCMD_SEND_BLOCK_REQ:
            Rfu_InitBlockSend(sBlockRequests[gRecvCmds[i][1]].address, (u16)sBlockRequests[gRecvCmds[i][1]].size);
            break;
        case RFUCMD_READY_CLOSE_LINK:
            gRfu.readyCloseLink[i] = TRUE;
            break;
        case RFUCMD_READY_EXIT_STANDBY:
            if (gRfu.allReadyNum == gRecvCmds[i][1])
                gRfu.readyExitStandby[i] = TRUE;
            break;
        case RFUCMD_DISCONNECT:
            if (gRfu.parentChild == MODE_CHILD)
            {
                // Disconnect child
                if (gReceivedRemoteLinkPlayers)
                {
                    if (gRecvCmds[i][1] & gRfuLinkStatus->connSlotFlag)
                    {
                        gReceivedRemoteLinkPlayers = 0;
                        rfu_LMAN_requestChangeAgbClockMaster();
                        gRfu.disconnectMode = gRecvCmds[i][2];
                    }
                    gRfu.playerCount = gRecvCmds[i][3];
                    ClearSelectedLinkPlayerIds(gRecvCmds[i][1]);
                }
            }
            else
            {
                // Disconnect parent
                RfuPrepareSendBuffer(RFUCMD_DISCONNECT_PARENT);
                gSendCmd[1] = gRecvCmds[i][1];
                gSendCmd[2] = gRecvCmds[i][2];
                gSendCmd[3] = gRecvCmds[i][3];
            }
            break;
        case RFUCMD_DISCONNECT_PARENT:
            if (gRfu.parentChild == MODE_PARENT)
            {
                gRfu.disconnectSlots |= gRecvCmds[i][1];
                gRfu.disconnectMode = gRecvCmds[i][2];
                ClearSelectedLinkPlayerIds(gRecvCmds[i][1]);
            }
            break;
        case RFUCMD_BLENDER_SEND_KEYS:
        case RFUCMD_SEND_HELD_KEYS:
            gLinkPartnersHeldKeys[i] = gRecvCmds[i][1];
            break;
        }
        if (gRfu.parentChild == MODE_PARENT && gRfu.numBlocksReceived[i])
        {
            if (gRfu.numBlocksReceived[i] == 4)
            {
                gRfu.blockReceived[i] = TRUE;
                gRfu.numBlocksReceived[i] = 0;
            }
            else
                gRfu.numBlocksReceived[i]++;
        }
    }
}

static bool8 AreAllPlayersReadyToReceive(void)
{
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (gRfu.recvBlock[i].receiving != RECV_STATE_READY)
            return FALSE;
    }
    return TRUE;
}

static bool8 AreAllPlayersFinishedReceiving(void)
{
    s32 i;

    for (i = 0; i < gRfu.playerCount; i++)
    {
        if (gRfu.recvBlock[i].receiving != RECV_STATE_FINISHED || gRfu.blockReceived[i] != TRUE)
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
    data->receiving = RECV_STATE_READY;
}

u8 Rfu_GetBlockReceivedStatus(void)
{
    u8 flags = 0;
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (gRfu.recvBlock[i].receiving == RECV_STATE_FINISHED && gRfu.blockReceived[i] == TRUE)
            flags |= (1 << i);
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
    case RFUCMD_SEND_BLOCK_INIT:
        gSendCmd[1] = gRfu.sendBlock.count;
        gSendCmd[2] = gRfu.sendBlock.owner + 0x80;
        break;
    case RFUCMD_SEND_BLOCK_REQ:
        if (AreAllPlayersReadyToReceive())
            gSendCmd[1] = gRfu.blockRequestType;
        break;
    case RFUCMD_SEND_PLAYER_IDS:
    case RFUCMD_SEND_PLAYER_IDS_NEW:
        tmp = gRfu.parentSlots ^ gRfu.disconnectSlots;
        gRfu.playerCount = sPlayerBitsToCount[tmp] + 1;
        gSendCmd[1] = gRfu.playerCount;
        buff = (u8 *)&gSendCmd[2];
        for (i = 0; i < RFU_CHILD_MAX; i++)
            buff[i] = gRfu.linkPlayerIdx[i];
        break;
    case RFUCMD_READY_EXIT_STANDBY:
    case RFUCMD_READY_CLOSE_LINK:
        gSendCmd[1] = gRfu.allReadyNum;
        break;
    case RFUCMD_BLENDER_SEND_KEYS:
        gSendCmd[0] = command;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case RFUCMD_SEND_PACKET:
        for (i = 0; i < RFU_PACKET_SIZE; i++)
            gSendCmd[1 + i] = gRfu.packet[i];
        break;
    case RFUCMD_SEND_HELD_KEYS:
        gSendCmd[1] = gHeldKeyCodeToSend;
        break;
    case RFUCMD_DISCONNECT_PARENT:
    case RFUCMD_DISCONNECT:
        break;
    }
}

void Rfu_SendPacket(void *data)
{
    if (gSendCmd[0] == 0 && !RfuHasErrored())
    {
        memcpy(gRfu.packet, data, sizeof(gRfu.packet));
        RfuPrepareSendBuffer(RFUCMD_SEND_PACKET);
    }
}

bool32 Rfu_InitBlockSend(const u8 *src, size_t size)
{
    bool8 r4;
    if (gRfu.callback != NULL)
        return FALSE;
    if (gSendCmd[0] != 0)
        return FALSE;
    if (gRfu.sendBlock.sending)
    {
        sRfuDebug.blockSendTime++;
        return FALSE;
    }
    r4 = (size % 12) != 0;
    gRfu.sendBlock.owner = GetMultiplayerId();
    gRfu.sendBlock.sending = TRUE;
    gRfu.sendBlock.count = (size / 12) + r4;
    gRfu.sendBlock.next = 0;
    if (size > BLOCK_BUFFER_SIZE)
        gRfu.sendBlock.payload = src;
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);
        gRfu.sendBlock.payload = gBlockSendBuffer;
    }
    RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_INIT);
    gRfu.callback = HandleBlockSend;
    gRfu.blockSendAttempts = 0;
    return TRUE;
}

static void HandleBlockSend(void)
{
    if (gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_INIT);
        if (gRfu.parentChild == MODE_PARENT)
        {
            if (++gRfu.blockSendAttempts > 2)
                gRfu.callback = SendNextBlock;
        }
        else
        {
            if ((gRecvCmds[GetMultiplayerId()][0] & RFUCMD_MASK) == RFUCMD_SEND_BLOCK_INIT)
                gRfu.callback = SendNextBlock;
        }
    }
}

static void SendNextBlock(void)
{
    s32 i;
    const u8 *src = gRfu.sendBlock.payload;
    gSendCmd[0] = RFUCMD_SEND_BLOCK | gRfu.sendBlock.next;
    for (i = 0; i < CMD_LENGTH - 1; i++)
        gSendCmd[i + 1] = (src[(i << 1) + gRfu.sendBlock.next * 12 + 1] << 8) | src[(i << 1) + gRfu.sendBlock.next * 12 + 0];
    gRfu.sendBlock.next++;
    if (gRfu.sendBlock.count <= gRfu.sendBlock.next)
    {
        gRfu.sendBlock.sending = FALSE;
        gRfu.callback = SendLastBlock;
    }
}

static void SendLastBlock(void)
{
    const u8 *src = gRfu.sendBlock.payload;
    u8 mpId = GetMultiplayerId();
    s32 i;
    if (gRfu.parentChild == MODE_CHILD)
    {
        gSendCmd[0] = RFUCMD_SEND_BLOCK | (gRfu.sendBlock.count - 1);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i + 1] = (src[(i << 1) + (gRfu.sendBlock.count - 1) * 12 + 1] << 8) | src[(i << 1) + (gRfu.sendBlock.count - 1) * 12 + 0];
        if ((u8)gRecvCmds[mpId][0] == gRfu.sendBlock.count - 1)
        {
            if (gRfu.recvBlock[mpId].receivedFlags != sAllBlocksReceived[gRfu.recvBlock[mpId].count])
            {
                HandleSendFailure(mpId, gRfu.recvBlock[mpId].receivedFlags);
                sRfuDebug.blockSendFailures++;
            }
            else
            {
                gRfu.callback = NULL;
            }
        }
    }
    else
    {
        gRfu.callback = NULL;
    }
}

bool8 Rfu_SendBlockRequest(u8 type)
{
    gRfu.blockRequestType = type;
    RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_REQ);
    return TRUE;
}

static void RfuShutdownAfterDisconnect(void)
{
    rfu_clearAllSlot();
    rfu_LMAN_powerDownRFU();
    gReceivedRemoteLinkPlayers = 0;
    gRfu.isShuttingDown = TRUE;
    gRfu.callback = NULL;
}

static void DisconnectRfu(void)
{
    rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
    rfu_waitREQComplete();
    RfuShutdownAfterDisconnect();
}

static void TryDisconnectRfu(void)
{
    if (gRfu.parentChild == MODE_CHILD)
    {
        rfu_LMAN_requestChangeAgbClockMaster();
        gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
    }
    else
    {
        gRfu.callback = DisconnectRfu;
    }
}

void LinkRfu_FatalError(void)
{
    rfu_LMAN_requestChangeAgbClockMaster();
    gRfu.disconnectMode = RFU_DISCONNECT_ERROR;
    gRfu.disconnectSlots = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
}

// RFU equivalent of LinkCB_WaitCloseLink
static void WaitAllReadyToCloseLink(void)
{
    s32 i;
    u8 playerCount = gRfu.playerCount;
    s32 count = 0;

    // Wait for all players to be ready
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (gRfu.readyCloseLink[i])
            count++;
    }
    if (count == playerCount)
    {
        // All ready, close link
        gBattleTypeFlags &= ~BATTLE_TYPE_LINK_IN_BATTLE;
        if (gRfu.parentChild == MODE_CHILD)
        {
            gRfu.errorState = RFU_ERROR_STATE_DISCONNECTING;
            TryDisconnectRfu();
        }
        else
        {
            gRfu.callback = TryDisconnectRfu;
        }
    }
}

static void SendReadyCloseLink(void)
{
    if (gSendCmd[0] == 0 && !gRfu.playerExchangeActive)
    {
        RfuPrepareSendBuffer(RFUCMD_READY_CLOSE_LINK);
        gRfu.callback = WaitAllReadyToCloseLink;
    }
}

static void Task_TryReadyCloseLink(u8 taskId)
{
    if (gRfu.callback == NULL)
    {
        gRfu.stopNewConnections = TRUE;
        gRfu.callback = SendReadyCloseLink;
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
        if (gRfu.recvQueue.count == 0 && gRfu.resendExitStandbyTimer > 60)
        {
            RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
            gRfu.resendExitStandbyTimer = 0;
        }
    }
    playerCount = GetLinkPlayerCount();
    for (i = 0; i < playerCount; i++)
    {
        if (!gRfu.readyExitStandby[i])
            break;
    }
    if (i == playerCount)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            gRfu.readyExitStandby[i] = FALSE;
        gRfu.allReadyNum++;
        gRfu.callback = NULL;
    }
    gRfu.resendExitStandbyTimer++;
}

static void LinkLeaderReadyToExitStandby(void)
{
    if (gRfu.recvQueue.count == 0 && gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
        gRfu.callback = SendReadyExitStandbyUntilAllReady;
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
        if (gRfu.recvQueue.count == 0 && gSendCmd[0] == 0)
        {
            RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
            gRfu.callback = SendReadyExitStandbyUntilAllReady;
        }
    }
    else
    {
        // Link leader, wait for all members to send exit ready
        playerCount = GetLinkPlayerCount();
        for (i = 1; i < playerCount; i++)
        {
            if (!gRfu.readyExitStandby[i])
                break;
        }
        if (i == playerCount)
        {
            if (gRfu.recvQueue.count == 0 && gSendCmd[0] == 0)
            {
                RfuPrepareSendBuffer(RFUCMD_READY_EXIT_STANDBY);
                gRfu.callback = LinkLeaderReadyToExitStandby;
            }
        }
    }
}

void Rfu_SetLinkStandbyCallback(void)
{
    if (gRfu.callback == NULL)
    {
        gRfu.callback = Rfu_LinkStandby;
        gRfu.resendExitStandbyTimer = 0;
    }
}

bool32 IsRfuSerialNumberValid(u32 serialNo)
{
    s32 i;
    for (i = 0; sAcceptedSerialNos[i] != serialNo; i++)
    {
        if (sAcceptedSerialNos[i] == RFU_SERIAL_END)
            return FALSE;
    }
    return TRUE;
}

u8 Rfu_SetLinkRecovery(bool32 enable)
{
    if (enable == FALSE)
        return rfu_LMAN_setLinkRecovery(0, 0);
    rfu_LMAN_setLinkRecovery(1, 600);
    return 0;
}

void Rfu_StopPartnerSearch(void)
{
    gRfu.stopNewConnections = TRUE;
    rfu_LMAN_stopManager(FALSE);
}

u8 Rfu_GetMultiplayerId(void)
{
    if (gRfu.parentChild == MODE_PARENT)
        return 0;
    return gRfu.multiplayerId;
}

u8 Rfu_GetLinkPlayerCount(void)
{
    return gRfu.playerCount;
}

bool8 IsLinkRfuTaskFinished(void)
{
    if (gRfu.status == RFU_STATUS_CONNECTION_ERROR)
        return FALSE;
    return gRfu.callback ? FALSE : TRUE;
}

static void CallRfuFunc(void)
{
    if (gRfu.callback)
        gRfu.callback();
}

static bool8 CheckForLeavingGroupMembers(void)
{
    s32 i;
    bool8 memberLeft = FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (gRfu.partnerSendStatuses[i] < RFU_STATUS_JOIN_GROUP_OK
         || gRfu.partnerSendStatuses[i] > RFU_STATUS_JOIN_GROUP_NO)
        {
            if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS
             || gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
            {
                if (gRfu.partnerRecvStatuses[i] == RFU_STATUS_LEAVE_GROUP_NOTICE)
                {
                    gRfu.partnerSendStatuses[i] = RFU_STATUS_LEAVE_GROUP;
                    gRfu.partnerRecvStatuses[i] = RFU_STATUS_CHILD_LEAVE_READY;
                    rfu_clearSlot(TYPE_NI_RECV, i);
                    rfu_NI_setSendData(1 << i, 8, &gRfu.partnerSendStatuses[i], 1);
                    memberLeft = TRUE;
                }

            }
            else if (gRfuSlotStatusNI[gRfu.childSlot]->recv.state == SLOT_STATE_RECV_FAILED)
                rfu_clearSlot(TYPE_NI_RECV, i);
            {

            }
        }
    }
    return memberLeft;
}

bool32 RfuTryDisconnectLeavingChildren(void)
{
    u8 childrenLeaving = 0;
    s32 i;

    // Check all children, get those waiting to be disconnected
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (gRfu.partnerRecvStatuses[i] == RFU_STATUS_CHILD_LEAVE)
        {
            childrenLeaving |= (1 << i);
            gRfu.partnerRecvStatuses[i] = RFU_STATUS_OK;
        }
    }

    // Disconnect any leaving children
    if (childrenLeaving)
    {
        rfu_REQ_disconnect(childrenLeaving);
        rfu_waitREQComplete();
    }

    // Return true if any children have left or are still waiting to leave
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (gRfu.partnerRecvStatuses[i] == RFU_STATUS_CHILD_LEAVE_READY
         || gRfu.partnerRecvStatuses[i] == RFU_STATUS_CHILD_LEAVE)
            return TRUE;
    }
    return FALSE;
}

bool32 HasTrainerLeftPartnersList(u16 trainerId, const u8 *name)
{
    u8 idx = GetPartnerIndexByNameAndTrainerID(name, trainerId);
    if (idx == 0xFF)
        return TRUE;
    if (gRfu.partnerSendStatuses[idx] == RFU_STATUS_LEAVE_GROUP)
        return TRUE;
    return FALSE;
}

void SendRfuStatusToPartner(u8 status, u16 trainerId, const u8 *name)
{
    u8 idx = GetPartnerIndexByNameAndTrainerID(name, trainerId);
    gRfu.partnerSendStatuses[idx] = status;
    rfu_clearSlot(TYPE_NI_SEND, idx);
    rfu_NI_setSendData(1 << idx, 8, &gRfu.partnerSendStatuses[idx], 1);
}

void SendLeaveGroupNotice(void)
{
    gRfu.leaveGroupStatus = RFU_STATUS_LEAVE_GROUP_NOTICE;
    rfu_clearSlot(TYPE_NI_SEND, gRfu.childSlot);
    rfu_NI_setSendData(1 << gRfu.childSlot, 8, &gRfu.leaveGroupStatus, 1);
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
            if (gRfu.partnerRecvStatuses[i] == RFU_STATUS_CHILD_LEAVE_READY)
                gRfu.partnerRecvStatuses[i] = RFU_STATUS_CHILD_LEAVE;
            rfu_clearSlot(TYPE_NI_SEND, i);
        }
    }
}

static s32 GetJoinGroupStatus(void)
{
    s32 status = RFU_STATUS_OK;
    if (gRfu.leaveGroupStatus == RFU_STATUS_LEAVE_GROUP_NOTICE)
    {
        if (gRfuSlotStatusNI[gRfu.childSlot]->send.state == SLOT_STATE_SEND_SUCCESS
         || gRfuSlotStatusNI[gRfu.childSlot]->send.state == SLOT_STATE_SEND_FAILED)
            rfu_clearSlot(TYPE_NI_SEND, gRfu.childSlot);
    }
    if (gRfuSlotStatusNI[gRfu.childSlot]->recv.state == SLOT_STATE_RECV_SUCCESS
     || gRfuSlotStatusNI[gRfu.childSlot]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
    {
        rfu_clearSlot(TYPE_NI_RECV, gRfu.childSlot);
        RfuSetStatus(gRfu.childRecvStatus, 0);
        status = gRfu.childRecvStatus;
    }
    else if (gRfuSlotStatusNI[gRfu.childSlot]->recv.state == SLOT_STATE_RECV_FAILED)
    {
        rfu_clearSlot(TYPE_NI_RECV, gRfu.childSlot);
        status = RFU_STATUS_JOIN_GROUP_NO;
    }
    return status;
}

#define tState data[0]

static void Task_PlayerExchange(u8 taskId)
{
    s32 i;

    if (gRfu.status == RFU_STATUS_FATAL_ERROR || gRfu.status == RFU_STATUS_CONNECTION_ERROR)
    {
        gRfu.playerExchangeActive = FALSE;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (AreAllPlayersReadyToReceive())
        {
            ResetBlockReceivedFlags();
            LocalLinkPlayerToBlock();
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (gRfu.parentChild == MODE_PARENT)
        {
            if (gReceivedRemoteLinkPlayers)
                RfuPrepareSendBuffer(RFUCMD_SEND_PLAYER_IDS_NEW);
            else
                RfuPrepareSendBuffer(RFUCMD_SEND_PLAYER_IDS);
            gTasks[taskId].tState = 101;
        }
        else
            gTasks[taskId].tState = 2;
        break;
    case 101:
        if (gSendCmd[0] == 0)
            gTasks[taskId].tState = 2;
        break;
    case 2:
        if (gRfu.playerCount)
            gTasks[taskId].tState++;
        break;
    case 3:
        if (gRfu.parentChild == MODE_PARENT)
        {
            if (AreAllPlayersReadyToReceive())
            {
                gRfu.blockRequestType = BLOCK_REQ_SIZE_NONE;
                RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_REQ);
                gTasks[taskId].tState++;
            }
        }
        else
            gTasks[taskId].tState++;
        break;
    case 4:
        if (AreAllPlayersFinishedReceiving())
            gTasks[taskId].tState++;
        break;
    case 5:
        for (i = 0; i < gRfu.playerCount; i++)
        {
            LinkPlayerFromBlock(i);
            Rfu_ResetBlockReceivedFlag(i);
        }
        gTasks[taskId].tState++;
        break;
    case 6:
        DestroyTask(taskId);
        gReceivedRemoteLinkPlayers = TRUE;
        gRfu.playerExchangeActive = FALSE;
        rfu_LMAN_setLinkRecovery(1, 600);
        if (gRfu.newChildQueue)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((gRfu.newChildQueue >> i) & 1)
                {
                    gRfu.nextChildBits = 1 << i;
                    gRfu.newChildQueue ^= (1 << i);
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
            gRfu.linkPlayerIdx[i] = 0;
    }
}

static void ReceiveRfuLinkPlayers(const struct SioInfo *sioInfo)
{
    s32 i;
    gRfu.playerCount = sioInfo->playerCount;
    for (i = 0; i < RFU_CHILD_MAX; i++)
        gRfu.linkPlayerIdx[i] = sioInfo->linkPlayerIdx[i];
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

// Equivalent to Task_PlayerExchange, but for when new children arrive after the first exchange
static void Task_PlayerExchangeUpdate(u8 taskId)
{
    s32 i;
    struct LinkPlayerBlock *playerBlock;
    struct SioInfo *sio;
    u8 playerId = gRfu.linkPlayerIdx[sSlotToLinkPlayerTableId[gRfu.incomingChild]];
    if (gRfu.status == RFU_STATUS_FATAL_ERROR || gRfu.status == RFU_STATUS_CONNECTION_ERROR)
    {
        gRfu.playerExchangeActive = FALSE;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (gSendCmd[0] == 0)
        {
            ResetBlockReceivedFlag(playerId);
            RfuPrepareSendBuffer(RFUCMD_SEND_PLAYER_IDS_NEW);
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (gSendCmd[0] == 0)
            gTasks[taskId].tState++;
        break;
    case 2:
        if ((GetBlockReceivedStatus() >> playerId) & 1)
        {
            ResetBlockReceivedFlag(playerId);
            playerBlock = (struct LinkPlayerBlock *)gBlockRecvBuffer[playerId];
            gLinkPlayers[playerId] = playerBlock->linkPlayer;
            ConvertLinkPlayerName(&gLinkPlayers[playerId]);
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        sio = (struct SioInfo *)gBlockSendBuffer;
        memcpy(sio->magic, sASCII_PokemonSioInfo, sizeof sASCII_PokemonSioInfo);
        sio->playerCount = gRfu.playerCount;
        for (i = 0; i < RFU_CHILD_MAX; i++)
            sio->linkPlayerIdx[i] = gRfu.linkPlayerIdx[i];
        memcpy(sio->linkPlayers, gLinkPlayers, sizeof gLinkPlayers);
        gTasks[taskId].tState++;
        // fallthrough
    case 4:
        sio = (struct SioInfo *)gBlockSendBuffer;
        sio->playerCount = gRfu.playerCount;
        for (i = 0; i < RFU_CHILD_MAX; i++)
            sio->linkPlayerIdx[i] = gRfu.linkPlayerIdx[i];
        memcpy(sio->linkPlayers, gLinkPlayers, sizeof(gLinkPlayers));
        // Send SioInfo but exclude the 92 unused bytes at the end
        if (SendBlock(0, gBlockSendBuffer, offsetof(struct SioInfo, filler)))
            gTasks[taskId].tState++;
        break;
    case 5:
        if (IsLinkTaskFinished() && GetBlockReceivedStatus() & 1)
        {
            CpuFill16(0, gBlockRecvBuffer, sizeof(struct SioInfo));
            ResetBlockReceivedFlag(0);
            gRfu.playerExchangeActive = FALSE;
            if (gRfu.newChildQueue)
            {
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((gRfu.newChildQueue >> i) & 1)
                    {
                        gRfu.nextChildBits = 1 << i;
                        gRfu.newChildQueue ^= (1 << i);
                        gRfu.playerExchangeActive = TRUE;
                        break;
                    }
                }
            }
            DestroyTask(taskId);
        }
        break;
    }
}

// Equivalent to Task_PlayerExchange but for chatting with a Union Room partner
static void Task_PlayerExchangeChat(u8 taskId)
{
    if (gRfu.status == RFU_STATUS_FATAL_ERROR || gRfu.status == RFU_STATUS_CONNECTION_ERROR)
        DestroyTask(taskId);
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (gRfu.playerCount)
        {
            LocalLinkPlayerToBlock();
            SendBlock(0, gBlockSendBuffer, sizeof(struct LinkPlayerBlock));
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
            gTasks[taskId].tState++;
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
    if (gRfu.errorState == RFU_ERROR_STATE_OCCURRED && lman.childClockSlave_flag == 0)
    {
        if (gMain.callback2 == CB2_MysteryGiftEReader || lman.init_param->mboot_flag)
            gWirelessCommType = 2;
        SetMainCallback2(CB2_LinkError);
        gMain.savedCallback = CB2_LinkError;
        SetLinkErrorBuffer((gRfu.errorInfo << 16) | (gRfu.errorParam0 << 8) | gRfu.errorParam1, gRfu.recvQueue.count, gRfu.sendQueue.count, RfuGetStatus() == RFU_STATUS_CONNECTION_ERROR);
        gRfu.errorState = RFU_ERROR_STATE_PROCESSED;
        CloseLink();
    }
    else if (gRfu.sendQueue.full == TRUE || gRfu.recvQueue.full == TRUE)
    {
        if (lman.childClockSlave_flag)
            rfu_LMAN_requestChangeAgbClockMaster();
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
        RfuSetErrorParams(F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
    }
}

static void RfuMain1_UnionRoom(void)
{
    if (lman.parent_child == MODE_PARENT)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
}

// Rfu equivalent of LinkMain1
bool32 RfuMain1(void)
{
    bool32 retval = FALSE;
    gRfu.parentId = 0;
    rfu_LMAN_manager_entity(Random2());
    if (!gRfu.isShuttingDown)
    {
        switch (gRfu.parentChild)
        {
        case MODE_PARENT:
            RfuMain1_Parent();
            break;
        case MODE_CHILD:
            retval = RfuMain1_Child();
            break;
        case MODE_P_C_SWITCH:
            RfuMain1_UnionRoom();
            break;
        }
    }
    return retval;
}

// Rfu equivalent of LinkMain2
bool32 RfuMain2(void)
{
    bool32 retval = FALSE;
    if (!gRfu.isShuttingDown)
    {
        if (gRfu.parentChild == MODE_PARENT)
            retval = RfuMain2_Parent();
        RfuCheckErrorStatus();
    }
    return retval;
}

static void SetHostRfuUsername(void)
{
    StringCopy(gHostRfuUsername, gSaveBlock2Ptr->playerName);
}

void ResetHostRfuGameData(void)
{
    memset(&gHostRfuGameData, 0, RFU_GAME_NAME_LENGTH);
    InitHostRfuGameData(&gHostRfuGameData, ACTIVITY_NONE, FALSE, 0);
}

void SetHostRfuGameData(u8 activity, u32 partnerInfo, bool32 startedActivity)
{
    InitHostRfuGameData(&gHostRfuGameData, activity, startedActivity, partnerInfo);
}

void SetHostRfuWonderFlags(bool32 hasNews, bool32 hasCard)
{
    gHostRfuGameData.compatibility.hasNews = hasNews;
    gHostRfuGameData.compatibility.hasCard = hasCard;
}

void SetTradeBoardRegisteredMonInfo(u32 type, u32 species, u32 level)
{
    gHostRfuGameData.tradeType = type;
    gHostRfuGameData.tradeSpecies = species;
    gHostRfuGameData.tradeLevel = level;
}

u8 GetLinkPlayerInfoFlags(s32 playerId)
{
    u8 retval = PINFO_ACTIVE_FLAG;
    retval |= (gLinkPlayers[playerId].gender << PINFO_GENDER_SHIFT);
    retval |= (gLinkPlayers[playerId].trainerId & PINFO_TID_MASK);
    return retval;
}

void GetOtherPlayersInfoFlags(void)
{
    struct RfuGameData *data = &gHostRfuGameData;
    s32 i;

    for (i = 1; i < GetLinkPlayerCount(); i++)
        data->partnerInfo[i - 1] = GetLinkPlayerInfoFlags(i);
}

void UpdateGameData_GroupLockedIn(bool8 startedActivity)
{
    gHostRfuGameData.startedActivity = startedActivity;
    rfu_REQ_configGameData(0, RFU_SERIAL_GAME, (void *)&gHostRfuGameData, gHostRfuUsername);
}

void UpdateGameData_SetActivity(u8 activity, u32 partnerInfo, bool32 startedActivity)
{
    if (activity != ACTIVITY_NONE)
        SetHostRfuGameData(activity, partnerInfo, startedActivity);
    rfu_REQ_configGameData(0, RFU_SERIAL_GAME, (void *)&gHostRfuGameData, gHostRfuUsername);
}

void SetUnionRoomChatPlayerData(u32 numPlayers)
{
    s32 i;
    u32 numConnectedChildren;
    u32 partnerInfo;
    s32 slots;

    if (GetHostRfuGameData()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        numConnectedChildren = 0;
        partnerInfo = 0;
        slots = gRfu.parentSlots ^ gRfu.disconnectSlots;
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((slots >> i) & 1)
            {
                // Only trainerId is shifted by the number of children, so the active flag and gender
                // are only ever set for the first child
                partnerInfo |= ((PINFO_ACTIVE_FLAG
                             | ((gLinkPlayers[gRfu.linkPlayerIdx[i]].gender & 1) << PINFO_GENDER_SHIFT)
                             | (gLinkPlayers[gRfu.linkPlayerIdx[i]].trainerId & PINFO_TID_MASK)) << (numConnectedChildren * 8));
                numConnectedChildren++;
                if (numConnectedChildren == numPlayers - 1)
                    break;
            }
        }
        UpdateGameData_SetActivity(ACTIVITY_CHAT | IN_UNION_ROOM, partnerInfo, FALSE);
    }
}

void RfuSetErrorParams(u32 errorInfo)
{
    if (gRfu.errorState == RFU_ERROR_STATE_NONE)
    {
        gRfu.errorParam0 = lman.param[0];
        gRfu.errorParam1 = lman.param[1];
        gRfu.errorInfo = errorInfo;
        gRfu.errorState = RFU_ERROR_STATE_OCCURRED;
    }
}

static void ResetErrorState(void)
{
    gRfu.errorState = RFU_ERROR_STATE_NONE;
}

void RfuSetIgnoreError(bool32 enable)
{
    if (!enable)
        gRfu.errorState = RFU_ERROR_STATE_NONE;
    else
        gRfu.errorState = RFU_ERROR_STATE_IGNORE;
}

static void DisconnectNewChild(void)
{
    SendDisconnectCommand(lman.acceptSlot_flag, RFU_DISCONNECT_ERROR);
    gRfu.callback = NULL;
}

static void StartDisconnectNewChild(void)
{
    gRfu.callback = DisconnectNewChild;
}

static void LinkManagerCB_Parent(u8 msg, u8 paramCount)
{
    u8 i;
    u8 disconnectFlag = 0;
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        gRfu.state = RFUSTATE_PARENT_CONNECT;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        ParentResetChildRecvMetadata(lman.param[0]);
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((lman.param[0] >> i) & 1)
            {
                struct RfuGameData *data = (void *)gRfuLinkStatus->partner[i].gname;
                if (data->activity == GetHostRfuGameData()->activity)
                {
                    gRfu.partnerSendStatuses[i] = RFU_STATUS_OK;
                    gRfu.partnerRecvStatuses[i] = RFU_STATUS_OK;
                    rfu_setRecvBuffer(TYPE_NI, i, &gRfu.partnerRecvStatuses[i], sizeof(gRfu.partnerRecvStatuses[0]));
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
        if (gRfu.acceptSlot_flag != lman.acceptSlot_flag)
        {
            rfu_REQ_disconnect(gRfu.acceptSlot_flag ^ lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        gRfu.state = RFUSTATE_PARENT_FINALIZE_START;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        gRfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        gRfu.linkLossRecoveryState = 3;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        gRfu.linkLossRecoveryState = 4;
        gRfu.parentSlots &= ~lman.param[0];
        if (gReceivedRemoteLinkPlayers == 1)
        {
            if (gRfu.parentSlots == 0)
                RfuSetErrorParams(msg);
            else
                StartDisconnectNewChild();
        }
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case 0x34: // ? Not a valid LMAN_MSG value
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        RfuSetErrorParams(msg);
        gRfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        RfuSetErrorParams(msg);
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        gRfu.parentFinished = TRUE;
        break;
    }
}

static void LinkManagerCB_Child(u8 msg, u8 unused1)
{
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        gRfu.state = RFUSTATE_CHILD_CONNECT;
        break;
    case LMAN_MSG_PARENT_FOUND:
        gRfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        gRfu.childSlot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        gRfu.state = RFUSTATE_CHILD_TRY_JOIN;
        gRfu.leaveGroupStatus = RFU_STATUS_OK;
        gRfu.childRecvStatus = RFU_STATUS_OK;
        rfu_setRecvBuffer(TYPE_NI, gRfu.childSlot, &gRfu.childRecvStatus, sizeof(gRfu.childRecvStatus));
        rfu_setRecvBuffer(TYPE_UNI, gRfu.childSlot, gRfu.childRecvQueue, sizeof(gRfu.childRecvQueue));
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        gRfu.linkLossRecoveryState = 2;
        if (gRfu.childRecvStatus == RFU_STATUS_JOIN_GROUP_NO)
            break;
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (gRfu.linkLossRecoveryState != 2)
            gRfu.linkLossRecoveryState = 4;
        if (gRfu.childRecvStatus != RFU_STATUS_LEAVE_GROUP)
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        Debug_PrintString(sASCII_LinkLossDisconnect, 5, 5);
        if (gReceivedRemoteLinkPlayers == 1)
            RfuSetErrorParams(msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        gRfu.linkLossRecoveryState = 1;
        Debug_PrintString(sASCII_LinkLossRecoveryNow, 5, 5);
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        gRfu.linkLossRecoveryState = 3;
        gRfu.linkRecovered = TRUE;
        break;
    case 0x34: // ? Not a valid LMAN_MSG value
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        RfuSetErrorParams(msg);
        gRfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        RfuSetErrorParams(msg);
        gRfu.parentFinished = TRUE;
        break;
    }
}

static void ParentResetChildRecvMetadata(s32 slot)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((slot >> i) & 1)
        {
            gRfu.numChildRecvErrors[i] = 0;
            gRfu.childRecvIds[i] = 0xFF;
        }
    }
}

static u8 GetNewChildrenInUnionRoomChat(s32 emptySlotMask)
{
    u8 ret = 0;
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((emptySlotMask >> i) & 1)
        {
            struct RfuGameData *data = (void *)gRfuLinkStatus->partner[i].gname;
            if (data->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
                ret |= (1 << i);
        }
    }

    return ret;
}

static void LinkManagerCB_UnionRoom(u8 msg, u8 paramCount)
{
    u8 acceptSlot;

    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        gRfu.state = RFUSTATE_UR_CONNECT;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        RfuSetStatus(RFU_STATUS_NEW_CHILD_DETECTED, 0);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        if (GetHostRfuGameData()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && !gRfu.stopNewConnections)
        {
            u8 newChildren = GetNewChildrenInUnionRoomChat(lman.param[0]);
            if (newChildren != 0)
            {
                acceptSlot = 1 << Rfu_GetIndexOfNewestChild(newChildren);
                if (gRfu.newChildQueue == 0 && !gRfu.playerExchangeActive)
                {
                    gRfu.nextChildBits = acceptSlot;
                    gRfu.newChildQueue |= (acceptSlot ^ newChildren);
                    gRfu.playerExchangeActive = TRUE;
                }
                else
                {
                    gRfu.newChildQueue |= newChildren;
                }
            }
            if (newChildren != lman.param[0])
            {
                gRfu.disconnectSlots |= (newChildren ^ lman.param[0]);
                gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
            }
        }
        else if (GetHostRfuGameData()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM))
        {
            rfu_REQ_disconnect(lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        ParentResetChildRecvMetadata(lman.param[0]);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
        break;
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_END_WAIT_CHILD_NAME:
        if (GetHostRfuGameData()->activity != (ACTIVITY_CHAT | IN_UNION_ROOM) && lman.acceptCount > 1)
        {
            acceptSlot = 1 << Rfu_GetIndexOfNewestChild(lman.param[0]);
            rfu_REQ_disconnect(lman.acceptSlot_flag ^ acceptSlot);
            rfu_waitREQComplete();
        }
        if (gRfu.state == RFUSTATE_UR_STOP_MANAGER_END)
            gRfu.state = RFUSTATE_UR_FINALIZE;
        break;
        break;
    case LMAN_MSG_PARENT_FOUND:
        gRfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        gRfu.childSlot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        gRfu.state = RFUSTATE_UR_CONNECT_END;
        if (gRfu.connectParentFailures < 2)
        {
            gRfu.connectParentFailures++;
            CreateTask(Task_TryConnectToUnionRoomParent, 2);
        }
        else
        {
            RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        }
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        gRfu.state = RFUSTATE_UR_PLAYER_EXCHANGE;
        RfuSetStatus(RFU_STATUS_CHILD_SEND_COMPLETE, 0);
        rfu_setRecvBuffer(TYPE_UNI, gRfu.childSlot, gRfu.childRecvQueue, sizeof(gRfu.childRecvQueue));
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        if (lman.acceptSlot_flag & lman.param[0])
            gRfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        gRfu.linkLossRecoveryState = 3;
        if (gRfuLinkStatus->parentChild == MODE_CHILD)
            gRfu.linkRecovered = TRUE;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        gRfu.linkLossRecoveryState = 2;
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (gRfu.linkLossRecoveryState != 2)
            gRfu.linkLossRecoveryState = 4;
        if (gRfu.parentChild == MODE_PARENT)
        {
            if (gReceivedRemoteLinkPlayers == 1)
            {
                gRfu.parentSlots &= ~(lman.param[0]);
                if (gRfu.parentSlots == 0)
                    RfuSetErrorParams(msg);
                else
                    StartDisconnectNewChild();
            }
        }
        else if (gRfu.disconnectMode != RFU_DISCONNECT_NORMAL && gReceivedRemoteLinkPlayers == 1)
        {
            RfuSetErrorParams(msg);
            rfu_LMAN_stopManager(FALSE);
        }

        if (gRfuLinkStatus->parentChild == MODE_NEUTRAL
            && !lman.pcswitch_flag
            && FuncIsActiveTask(Task_UnionRoomListen) == TRUE)
            gRfu.state = RFUSTATE_UR_CONNECT;

        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, msg);
        break;
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER:
        gRfu.disconnectSlots = 0;
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        RfuSetErrorParams(msg);
        gRfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        RfuSetErrorParams(msg);
        RfuSetStatus(RFU_STATUS_FATAL_ERROR, msg);
        gRfu.parentFinished = FALSE;
        break;
    }
}

void RfuSetNormalDisconnectMode(void)
{
    gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
}

void RfuSetStatus(u8 status, u16 errorInfo)
{
    gRfu.status = status;
    gRfu.errorInfo = errorInfo;
}

u8 RfuGetStatus(void)
{
    return gRfu.status;
}

bool32 RfuHasErrored(void)
{
    u32 status = RfuGetStatus();
    if (status == RFU_STATUS_FATAL_ERROR || status == RFU_STATUS_CONNECTION_ERROR)
        return TRUE;
    else
        return FALSE;
}

bool32 Rfu_IsPlayerExchangeActive(void)
{
    return gRfu.playerExchangeActive;
}

bool8 Rfu_IsMaster(void)
{
    return gRfu.parentChild;
}

void RfuVSync(void)
{
    rfu_LMAN_syncVBlank();
}

void ClearRecvCommands(void)
{
    CpuFill32(0, gRecvCmds, sizeof(gRecvCmds));
}

static void VBlank_RfuIdle(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Unused
static void Debug_RfuIdle(void)
{
    s32 i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();
    SetVBlankCallback(VBlank_RfuIdle);
    if (IsWirelessAdapterConnected())
    {
        gLinkType = LINKTYPE_TRADE;
        SetWirelessCommType1();
        OpenLink();
        SeedRng(gMain.vblankCounter2);
        for (i = 0; i < TRAINER_ID_LENGTH; i++)
            gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_1D_MAP);
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        CreateTask_RfuIdle();
        SetMainCallback2(CB2_RfuIdle);
    }
}

bool32 IsUnionRoomListenTaskActive(void)
{
    return FuncIsActiveTask(Task_UnionRoomListen);
}

void CreateTask_RfuIdle(void)
{
    if (!FuncIsActiveTask(Task_Idle))
        gRfu.idleTaskId = CreateTask(Task_Idle, 0);
}

void DestroyTask_RfuIdle(void)
{
     if (FuncIsActiveTask(Task_Idle) == TRUE)
        DestroyTask(gRfu.idleTaskId);
}

static void CB2_RfuIdle(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void InitializeRfuLinkManager_LinkLeader(u32 groupMax)
{
    gRfu.parentChild = MODE_PARENT;
    SetHostRfuUsername();
    rfu_LMAN_initializeManager(LinkManagerCB_Parent, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.availSlot_flag = sAvailSlots[groupMax - 1];
    CreateTask_ParentSearchForChildren();
}

void InitializeRfuLinkManager_JoinGroup(void)
{
    gRfu.parentChild = MODE_CHILD;
    SetHostRfuUsername();
    rfu_LMAN_initializeManager(LinkManagerCB_Child, MSCCallback_Child);
    CreateTask_ChildSearchForParent();
}

void InitializeRfuLinkManager_EnterUnionRoom(void)
{
    gRfu.parentChild = MODE_P_C_SWITCH;
    SetHostRfuUsername();
    rfu_LMAN_initializeManager(LinkManagerCB_UnionRoom, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.linkRecovery_enable = 0;
    sRfuReqConfig.linkRecovery_period = 600;
    gRfu.searchTaskId = CreateTask(Task_UnionRoomListen, 1);
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
        u16 trainerId = ReadU16(((struct RfuGameData *)gRfuLinkStatus->partner[i].gname)->compatibility.playerTrainerId);
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
    gRfu.parentSlots &= ~slot;
    rfu_clearSlot(1, gRfu.parentSendSlot);
    rfu_UNI_setSendData(gRfu.parentSlots, gRfu.recvCmds, sizeof(gRfu.recvCmds));
    gRfu.parentSendSlot = Rfu_GetIndexOfNewestChild(gRfu.parentSlots);
}

void RequestDisconnectSlotByTrainerNameAndId(const u8 *name, u16 id)
{
    u8 index = GetPartnerIndexByNameAndTrainerID(name, id);
    if (index != 0xFF)
        RfuReqDisconnectSlot(1 << index);
}

void Rfu_DisconnectPlayerById(u32 playerIdx)
{
    if (playerIdx != 0)
    {
        s32 i;
        u8 toDisconnect = 0;

        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (gRfu.linkPlayerIdx[i] == playerIdx && (gRfu.parentSlots >> i) & 1)
                toDisconnect |= 1 << i;
        }
        if (toDisconnect)
            SendDisconnectCommand(toDisconnect, RFU_DISCONNECT_NORMAL);
    }
}

#define tDisconnectPlayers data[0]
#define tDisconnectMode    data[1]

static void Task_SendDisconnectCommand(u8 taskId)
{
    if (gSendCmd[0] == 0 && !gRfu.playerExchangeActive)
    {
        RfuPrepareSendBuffer(RFUCMD_DISCONNECT);
        gSendCmd[1] = gTasks[taskId].tDisconnectPlayers;
        gSendCmd[2] = gTasks[taskId].tDisconnectMode;
        gRfu.playerCount -= sPlayerBitsToCount[gTasks[taskId].tDisconnectPlayers];
        gSendCmd[3] = gRfu.playerCount;
        DestroyTask(taskId);
    }
}

static void SendDisconnectCommand(u32 playersToDisconnect, u32 disconnectMode)
{
    u8 taskId = FindTaskIdByFunc(Task_SendDisconnectCommand);
    if (taskId == TASK_NONE)
    {
        taskId = CreateTask(Task_SendDisconnectCommand, 5);
        gTasks[taskId].tDisconnectPlayers = playersToDisconnect;
    }
    else
    {
        // Task is already active, just add the new players to disconnect
        gTasks[taskId].tDisconnectPlayers |= playersToDisconnect;
    }

    gTasks[taskId].tDisconnectMode = disconnectMode;
}

#undef tDisconnectMode

#define tTime data[15]

static void Task_RfuReconnectWithParent(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (CanTryReconnectParent())
    {
        u8 id = GetPartnerIndexByNameAndTrainerID((u8 *)data, ReadU16(&data[8]));
        if (id != 0xFF)
        {
            if (gRfuLinkStatus->partner[id].slot != 0xFF)
            {
                gRfu.reconnectParentId = id;
                if (TryReconnectParent())
                    DestroyTask(taskId);
            }
            else if (GetHostRfuGameData()->activity == ACTIVITY_WONDER_CARD
                  || GetHostRfuGameData()->activity == ACTIVITY_WONDER_NEWS)
            {
                tTime++;
            }
            else
            {
                // Error, unable to reconnect to parent
                RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
                DestroyTask(taskId);
            }
        }
        else
        {
            tTime++;
            gRfu.reconnectParentId = id;
        }
    }
    else
    {
        tTime++;
    }

    if (tTime > 240)
    {
        // Timeout error
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
        DestroyTask(taskId);
    }
}

#undef tTime

void CreateTask_RfuReconnectWithParent(const u8 *name, u16 trainerId)
{
    u8 taskId;
    s16 *data;

    gRfu.status = RFU_STATUS_OK;
    taskId = CreateTask(Task_RfuReconnectWithParent, 3);
    data = gTasks[taskId].data;
    StringCopy((u8 *)(data), name);
    data[8] = trainerId;
}

static bool32 IsPartnerActivityIncompatible(s16 activity, struct RfuGameData *partner)
{
    if (GetHostRfuGameData()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        // Host trying to chat, but partner isn't
        if (partner->activity != (ACTIVITY_CHAT | IN_UNION_ROOM))
            return TRUE;
    }
    else if (partner->activity != IN_UNION_ROOM)
    {
        // Partner not in union room
        return TRUE;
    }
    else if (activity == (ACTIVITY_TRADE | IN_UNION_ROOM))
    {
        // Verify that the trade offered hasn't changed
        struct RfuGameData *original = &gRfu.parent;
        if (original->tradeSpecies == SPECIES_EGG)
        {
            if (partner->tradeSpecies == original->tradeSpecies)
                return FALSE;
            else
                return TRUE;
        }
        else if (partner->tradeSpecies != original->tradeSpecies
                 || partner->tradeLevel != original->tradeLevel
                 || partner->tradeType != original->tradeType)
        {
            return TRUE;
        }
    }

    return FALSE;
}

#define tTime     data[0]
#define tActivity data[1]

static void Task_TryConnectToUnionRoomParent(u8 taskId)
{
    // Stop task if player is the new parent
    if (gRfu.status == RFU_STATUS_NEW_CHILD_DETECTED)
        DestroyTask(taskId);

    if (++gTasks[taskId].tTime > 300)
    {
        // Timeout error
        RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
        DestroyTask(taskId);
    }

    // Check if parent should be searched for
    if (gRfu.parentId != 0 && lman.parent_child == MODE_CHILD)
    {
        // Search for parent
        u16 trainerId = ReadU16(gRfu.parent.compatibility.playerTrainerId);
        u8 id = GetPartnerIndexByNameAndTrainerID(gRfu.parentName, trainerId);
        if (id != 0xFF)
        {
            // Parent found, try to connect
            if (!IsPartnerActivityIncompatible(gTasks[taskId].tActivity, (void *)gRfuLinkStatus->partner[id].gname))
            {
                if (gRfuLinkStatus->partner[id].slot != 0xFF && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[id].id, 90))
                {
                    // Succesfully connected to parent
                    gRfu.state = RFUSTATE_CONNECTED;
                    DestroyTask(taskId);
                }
            }
            else
            {
                // Incompatible partner activity
                RfuSetStatus(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_6 | F_RFU_ERROR_7);
                DestroyTask(taskId);
            }
        }
    }
}

void TryConnectToUnionRoomParent(const u8 *name, struct RfuGameData *parent, u8 activity)
{
    u8 taskId, listenTaskId;

    gRfu.connectParentFailures = 0;
    gRfu.status = RFU_STATUS_OK;
    StringCopy(gRfu.parentName, name);
    memcpy(&gRfu.parent, parent, RFU_GAME_NAME_LENGTH);
    rfu_LMAN_forceChangeSP();
    taskId = CreateTask(Task_TryConnectToUnionRoomParent, 2);
    gTasks[taskId].tActivity = activity;
    listenTaskId = FindTaskIdByFunc(Task_UnionRoomListen);
    if (activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        if (listenTaskId != TASK_NONE)
            gTasks[listenTaskId].tConnectingForChat = TRUE;
    }
    else
    {
        if (listenTaskId != TASK_NONE)
            gTasks[listenTaskId].tConnectingForChat = FALSE;
    }
}

bool8 IsRfuRecoveringFromLinkLoss(void)
{
    if (gRfu.linkLossRecoveryState == 1)
        return TRUE;
    else
        return FALSE;
}

bool32 IsRfuCommunicatingWithAllChildren(void)
{
    s32 i;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        // RFU_STATUS_OK is the default status.
        // If any connected child is receiving a status other
        // than OK, then the parent is communicating with them
        if ((lman.acceptSlot_flag >> i) & 1 && gRfu.partnerSendStatuses[i] == RFU_STATUS_OK)
            return FALSE;
    }

    return TRUE;
}

static void Debug_PrintEmpty(void)
{
    s32 i;
    for (i = 0; i < 20; i++)
        Debug_PrintString(sASCII_30Spaces, 0, i);
}

static void Debug_PrintStatus(void)
{
    s32 i, j;
    Debug_PrintNum(GetBlockReceivedStatus(), 28, 19, 2);
    Debug_PrintNum(gRfuLinkStatus->connSlotFlag, 20, 1, 1);
    Debug_PrintNum(gRfuLinkStatus->linkLossSlotFlag, 23, 1, 1);
    if (gRfu.parentChild == MODE_PARENT)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((gRfuLinkStatus->getNameFlag >> i) & 1)
            {
                Debug_PrintNum(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                Debug_PrintString((void *)gRfuLinkStatus->partner[i].gname, 6, i + 3);
                Debug_PrintString(gRfuLinkStatus->partner[i].uname, 22, i + 3);
            }
        }
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            for (j = 0; j < COMM_SLOT_LENGTH; j++)
                Debug_PrintNum(gRfu.childRecvBuffer[i][j], j * 2, i + 11, 2);
        }
        Debug_PrintString(sASCII_NowSlot, 1, 15);
    }
    else if (gRfuLinkStatus->connSlotFlag != 0 && gRfuLinkStatus->getNameFlag != 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            Debug_PrintNum(0, 1, i + 3, 4);
            Debug_PrintString(sASCII_15Spaces, 6, i + 3);
            Debug_PrintString(sASCII_8Spaces, 22, i + 3);
        }
        Debug_PrintNum(gRfuLinkStatus->partner[gRfu.childSlot].serialNo, 1, 3, 4);
        Debug_PrintString((void *)gRfuLinkStatus->partner[gRfu.childSlot].gname, 6, 3);
        Debug_PrintString(gRfuLinkStatus->partner[gRfu.childSlot].uname, 22, 3);
    }
    else
    {
        for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
        {
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
            {
                Debug_PrintNum(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                Debug_PrintNum(gRfuLinkStatus->partner[i].id, 6, i + 3, 4);
                Debug_PrintString(gRfuLinkStatus->partner[i].uname, 22, i + 3);
            }
        }
        for (; i < RFU_CHILD_MAX; i++)
        {
            Debug_PrintNum(0, 1, i + 3, 4);
            Debug_PrintString(sASCII_15Spaces, 6, i + 3);
            Debug_PrintString(sASCII_8Spaces, 22, i + 3);
        }
    }
}

static u32 GetRfuSendQueueLength(void)
{
    return gRfu.sendQueue.count;
}

u32 GetRfuRecvQueueLength(void)
{
    return gRfu.recvQueue.count;
}

static void Task_Idle(u8 taskId)
{

}
