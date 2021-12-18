#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"
#include "AgbRfu_LinkManager.h"

#define RFUCMD_MASK                0xFF00

#define RFUCMD_SEND_PACKET         0x2F00
#define RFUCMD_BLENDER_SEND_KEYS   0x4400
#define RFUCMD_READY_CLOSE_LINK    0x5F00
#define RFUCMD_READY_EXIT_STANDBY  0x6600
#define RFUCMD_SEND_PLAYER_IDS     0x7700
#define RFUCMD_SEND_PLAYER_IDS_NEW 0x7800
#define RFUCMD_SEND_BLOCK_INIT     0x8800
#define RFUCMD_SEND_BLOCK          0x8900
#define RFUCMD_SEND_BLOCK_REQ      0xA100
#define RFUCMD_SEND_HELD_KEYS      0xBE00
#define RFUCMD_DISCONNECT          0xED00
#define RFUCMD_DISCONNECT_PARENT   0xEE00

#define RFU_SERIAL_GAME                0x0002 // Serial number for Pokémon game (FRLG or Emerald)
#define RFU_SERIAL_WONDER_DISTRIBUTOR  0x7F7D // Serial number for distributing Wonder Cards / News
#define RFU_SERIAL_UNKNOWN             0x0000 // Unreferenced acceptable serial number. Gamecube?
#define RFU_SERIAL_END                 0xFFFF

#define COMM_SLOT_LENGTH 14
#define RECV_QUEUE_NUM_SLOTS 32
#define SEND_QUEUE_NUM_SLOTS 40
#define BACKUP_QUEUE_NUM_SLOTS 2

#define RFU_PACKET_SIZE 6

#define RFU_STATUS_OK                   0
#define RFU_STATUS_FATAL_ERROR          1
#define RFU_STATUS_CONNECTION_ERROR     2
#define RFU_STATUS_CHILD_SEND_COMPLETE  3
#define RFU_STATUS_NEW_CHILD_DETECTED   4
#define RFU_STATUS_JOIN_GROUP_OK        5
#define RFU_STATUS_JOIN_GROUP_NO        6
#define RFU_STATUS_WAIT_ACK_JOIN_GROUP  7
#define RFU_STATUS_LEAVE_GROUP_NOTICE   8
#define RFU_STATUS_LEAVE_GROUP          9
#define RFU_STATUS_CHILD_LEAVE_READY    10
#define RFU_STATUS_CHILD_LEAVE          11
#define RFU_STATUS_ACK_JOIN_GROUP       12

// Values for disconnectMode
enum {
    RFU_DISCONNECT_NONE,
    RFU_DISCONNECT_ERROR,
    RFU_DISCONNECT_NORMAL,
};

// Values for errorState
enum {
    RFU_ERROR_STATE_NONE,
    RFU_ERROR_STATE_OCCURRED,
    RFU_ERROR_STATE_PROCESSED,
    RFU_ERROR_STATE_DISCONNECTING,
    RFU_ERROR_STATE_IGNORE,
};

// These error flags are set in errorInfo, and given as
// the uppermost 16 bits of 'status' for sLinkErrorBuffer.
// The first 8 bits are reserved for the link manager msg
// when the error occurred, and the last 8 bits are this
// sequence of presumably meaningful error flags, but
// ultimately sLinkErrorBuffer's status is never read.
#define F_RFU_ERROR_1 (1 << 8)
#define F_RFU_ERROR_2 (1 << 9)  // Never set
#define F_RFU_ERROR_3 (1 << 10) // Never set
#define F_RFU_ERROR_4 (1 << 11) // Never set
#define F_RFU_ERROR_5 (1 << 12)
#define F_RFU_ERROR_6 (1 << 13)
#define F_RFU_ERROR_7 (1 << 14)
#define F_RFU_ERROR_8 (1 << 15)

struct RfuGameCompatibilityData
{
    u16 language:4;
    u16 hasNews:1;
    u16 hasCard:1;
    u16 unknown:1; // Never read
    u16 isChampion:1;
    u16 hasNationalDex:1;
    u16 gameClear:1;
    u16 version:4;
    u16 unused:2;
    u8 playerTrainerId[2];
};

// This struct is sent via the Wireless Adapter as the game name or "gname" data.
// Gname is only applicable during Wireless Single Game Pak Multiplay, when the
// adapter needs this data for connection. Per the RFU manual, during "normal"
// wireless play (the kind the Pokémon games use) the gname data can be used for
// anything the developers want. This struct is what GF decided to use it for.
// It can be up to 13 bytes in size (RFU_GAME_NAME_LENGTH).
// The player's name is sent separately as the username ("uname"), and does not 
// use a struct (gHostRfuUsername). 
struct __attribute__((packed, aligned(2))) RfuGameData
{
    struct RfuGameCompatibilityData compatibility;
    u8 partnerInfo[RFU_CHILD_MAX];
    u16 tradeSpecies;
    u8 activity:7;
    u8 startedActivity:1;
    u8 playerGender:1;
    u8 tradeLevel:7;
    u8 tradeType:6;
    u8 padding:2;
};

// Constants for getting/setting information in 'partnerInfo' of RfuGameData.
// This data is used to determine what the link partners look like from
// the host's perspective.
// Bits 0-2 are a shortened trainerId
// Bit 3 is the player's gender
// Bits 4-6 are unknown/unused
// Bit 7 is an 'active' flag 
#define PINFO_TID_MASK 0x7
#define PINFO_GENDER_SHIFT 3
#define PINFO_ACTIVE_FLAG (1 << 7)

struct RfuBlockSend
{
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 count;
    /* 0x04 */ const u8 *payload;
    /* 0x08 */ u32 receivedFlags;
    /* 0x0c */ u32 failedFlags;
    /* 0x10 */ bool8 sending;
    /* 0x11 */ u8 owner;
    /* 0x12 */ u8 receiving;
};

struct RfuRecvQueue
{
    /* 0x000 */ u8 slots[RECV_QUEUE_NUM_SLOTS][COMM_SLOT_LENGTH * MAX_RFU_PLAYERS];
    /* 0x8c0 */ vu8 recvSlot;
    /* 0x8c1 */ vu8 sendSlot;
    /* 0x8c2 */ vu8 count;
    /* 0x8c3 */ vu8 full;
};

struct RfuSendQueue
{
    /* 0x000 */ u8 slots[SEND_QUEUE_NUM_SLOTS][COMM_SLOT_LENGTH];
    /* 0x230 */ vu8 recvSlot;
    /* 0x231 */ vu8 sendSlot;
    /* 0x232 */ vu8 count;
    /* 0x233 */ vu8 full;
};

struct RfuBackupQueue
{
    /* 0x00 */ u8 slots[BACKUP_QUEUE_NUM_SLOTS][COMM_SLOT_LENGTH];
    /* 0x1c */ vu8 recvSlot;
    /* 0x1d */ vu8 sendSlot;
    /* 0x1e */ vu8 count;
};

// Stores data needed for the RFU on GF's end
struct RfuManager
{
    /* 0x000 */ void (*callback)(void);
    /* 0x004 */ u16 state;
    /* 0x006 */ u8 unused1[4];
    /* 0x00a */ u16 errorInfo;
    /* 0x00c */ u8 parentChild;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ bool8 runParentMain2;
    /* 0x00f */ u8 unused2;
    /* 0x010 */ u16 errorParam0;
    /* 0x012 */ u16 errorParam1;
    /* 0x014 */ u8 childRecvBuffer[RFU_CHILD_MAX][COMM_SLOT_LENGTH];
    /* 0x04c */ u8 childSendBuffer[COMM_SLOT_LENGTH];
    /* 0x05a */ u8 blockRequestType;
    /* 0x05b */ u8 blockSendAttempts;
    /* 0x05c */ bool8 blockReceived[MAX_RFU_PLAYERS];
    /* 0x061 */ bool8 numBlocksReceived[MAX_RFU_PLAYERS];
    /* 0x066 */ u8 idleTaskId;
    /* 0x067 */ u8 searchTaskId;
    /* 0x068 */ u8 unused3[4];
    /* 0x06c */ struct RfuBlockSend sendBlock;
    /* 0x080 */ struct RfuBlockSend recvBlock[MAX_RFU_PLAYERS];
    /* 0x0e4 */ bool8 readyCloseLink[MAX_RFU_PLAYERS];
    /* 0x0e9 */ bool8 readyExitStandby[MAX_RFU_PLAYERS];
    /* 0x0ee */ vu8 errorState;
    /* 0x0ef */ bool8 isShuttingDown;
    /* 0x0f0 */ u8 linkLossRecoveryState;
    /* 0x0f1 */ u8 status;
    /* 0x0f2 */ u16 packet[RFU_PACKET_SIZE];
    /* 0x0fe */ u16 resendExitStandbyTimer;
    /* 0x100 */ u16 allReadyNum;
    /* 0x102 */ u8 childSendCmdId;
    /* 0x103 */ u8 unused4[7];
    /* 0x10A */ struct RfuGameData parent;
    u8 filler_;
    u8 parentName[RFU_USER_NAME_LENGTH];
    /* 0x124 */ struct RfuRecvQueue recvQueue;
    /* 0x9e8 */ struct RfuSendQueue sendQueue;
    /* 0xc1c */ struct RfuBackupQueue backupQueue;
    /* 0xc3c */ vu8 linkRecovered;
    /* 0xc3d */ u8 reconnectParentId;
    /* 0xc3e */ vu8 childSlot;
    /* 0xc3f */ u8 childRecvQueue[COMM_SLOT_LENGTH * MAX_RFU_PLAYERS];
    /* 0xc85 */ u8 leaveGroupStatus;
    /* 0xc86 */ u8 childRecvStatus;
    /* 0xc87 */ u8 recvCmds[MAX_RFU_PLAYERS][CMD_LENGTH - 1][2];
    /* 0xccd */ u8 parentId;
    /* 0xcce */ u8 multiplayerId;
    /* 0xccf */ u8 connectParentFailures;
    /* 0xcd0 */ vu8 childSendCount;
    /* 0xcd1 */ u8 partnerSendStatuses[RFU_CHILD_MAX];
    /* 0xcd5 */ u8 partnerRecvStatuses[RFU_CHILD_MAX];
    /* 0xcd9 */ bool8 stopNewConnections;
    /* 0xcda */ u8 parentSendSlot;
    /* 0xcdb */ vbool8 parentFinished;
    /* 0xcdc */ vbool8 parentMain2Failed;
    /* 0xcdd */ u8 unused5;
    /* 0xcde */ u8 linkPlayerIdx[RFU_CHILD_MAX];
    /* 0xce2 */ u8 parentSlots;
    /* 0xce2 */ u8 disconnectSlots;
    /* 0xce4 */ u8 disconnectMode;
    /* 0xce5 */ u8 nextChildBits;
    /* 0xce5 */ u8 newChildQueue;
    /* 0xce7 */ u8 acceptSlot_flag;
    /* 0xce8 */ bool8 playerExchangeActive;
    /* 0xce9 */ u8 incomingChild;
    /* 0xcea */ u8 numChildRecvErrors[RFU_CHILD_MAX];
    /* 0xcee */ u8 childRecvIds[RFU_CHILD_MAX];
}; // size = 0xcf4

extern struct RfuGameData gHostRfuGameData;
extern u8 gHostRfuUsername[];
extern struct RfuManager gRfu;
extern u8 gWirelessStatusIndicatorSpriteId;

void WipeTrainerNameRecords(void);
void InitRFUAPI(void);
void LinkRfu_Shutdown(void);
void Rfu_SetBlockReceivedFlag(u8 linkPlayerId);
void Rfu_ResetBlockReceivedFlag(u8 linkPlayerId);
bool32 IsSendingKeysToRfu(void);
void StartSendingKeysToRfu(void);
void Rfu_SetBerryBlenderLinkCallback(void);
u8 Rfu_GetBlockReceivedStatus(void);
bool32 Rfu_InitBlockSend(const u8 *src, size_t size);
void ClearLinkRfuCallback(void);
u8 Rfu_GetLinkPlayerCount(void);
u8 Rfu_GetMultiplayerId(void);
bool8 Rfu_SendBlockRequest(u8 type);
bool8 IsLinkRfuTaskFinished(void);
bool8 Rfu_IsMaster(void);
void Rfu_SetCloseLinkCallback(void);
void Rfu_SetLinkStandbyCallback(void);
void ResetLinkRfuGFLayer(void);
void UpdateWirelessStatusIndicatorSprite(void);
void InitRFU(void);
bool32 RfuMain1(void);
bool32 RfuMain2(void);
bool32 RfuHasErrored(void);
bool32 IsRfuRecvQueueEmpty(void);
u32 GetRfuRecvQueueLength(void);
void RfuVSync(void);
void RfuSetIgnoreError(bool32 enable);
u8 RfuGetStatus(void);
struct RfuGameData *GetHostRfuGameData(void);
void UpdateGameData_GroupLockedIn(u8 startedActivity);
void RfuSetErrorParams(u32 errorInfo);
void RfuSetStatus(u8 status, u16 errorInfo);
u8 Rfu_SetLinkRecovery(bool32 enable);
void CopyHostRfuGameDataAndUsername(struct RfuGameData *gameData, u8 *username);
void SetHostRfuGameData(u8 activity, u32 partnerInfo, bool32 startedActivity);
void InitializeRfuLinkManager_LinkLeader(u32 groupMax);
bool32 IsRfuCommunicatingWithAllChildren(void);
void LinkRfu_StopManagerAndFinalizeSlots(void);
bool32 RfuTryDisconnectLeavingChildren(void);
bool32 HasTrainerLeftPartnersList(u16 trainerId, const u8 *name);
void SendRfuStatusToPartner(u8 status, u16 trainerId, const u8 *name);
u32 WaitSendRfuStatusToPartner(u16 trainerId, const u8 *name);
void RequestDisconnectSlotByTrainerNameAndId(const u8 *name, u16 id);
bool8 LmanAcceptSlotFlagIsNotZero(void);
bool32 WaitRfuState(bool32 force);
void GetOtherPlayersInfoFlags(void);
void InitializeRfuLinkManager_JoinGroup(void);
void SendLeaveGroupNotice(void);
void SaveLinkTrainerNames(void);
void LinkRfu_CreateConnectionAsParent(void);
void LinkRfu_StopManagerBeforeEnteringChat(void);
void UpdateGameData_SetActivity(u8 activity, u32 partnerInfo, bool32 startedActivity);
void CreateTask_RfuReconnectWithParent(const u8 *name, u16 trainerId);
void SetHostRfuWonderFlags(bool32 hasNews, bool32 hasCard);
void ResetHostRfuGameData(void);
void SetTradeBoardRegisteredMonInfo(u32 type, u32 species, u32 level);
void InitializeRfuLinkManager_EnterUnionRoom(void);
void TryConnectToUnionRoomParent(const u8 *name, struct RfuGameData *parent, u8 activity);
bool32 IsUnionRoomListenTaskActive(void);
void Rfu_SendPacket(void *data);
bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name);
void Rfu_DisconnectPlayerById(u32 playerIdx);
u8 GetLinkPlayerInfoFlags(s32 playerId);
void StopUnionRoomLinkManager(void);
bool8 Rfu_GetCompatiblePlayerData(struct RfuGameData *gameData, u8 *username, u8 idx);
bool8 Rfu_GetWonderDistributorPlayerData(struct RfuGameData *gameData, u8 *username, u8 idx);
s32 Rfu_GetIndexOfNewestChild(u8 bits);
void CreateTask_RfuIdle(void);
void DestroyTask_RfuIdle(void);
void ClearRecvCommands(void);
void LinkRfu_FatalError(void);
bool32 Rfu_IsPlayerExchangeActive(void);
void Rfu_StopPartnerSearch(void);
void RfuSetNormalDisconnectMode(void);
void SetUnionRoomChatPlayerData(u32 numPlayers);
bool32 IsRfuSerialNumberValid(u32 serialNo);
bool8 IsRfuRecoveringFromLinkLoss(void);
void RfuRecvQueue_Reset(struct RfuRecvQueue *queue);
void RfuSendQueue_Reset(struct RfuSendQueue *queue);
void RfuRecvQueue_Enqueue(struct RfuRecvQueue *queue, u8 *data);
void RfuSendQueue_Enqueue(struct RfuSendQueue *queue, u8 *data);
bool8 RfuRecvQueue_Dequeue(struct RfuRecvQueue *queue, u8 *dest);
bool8 RfuSendQueue_Dequeue(struct RfuSendQueue *queue, u8 *dest);
void RfuBackupQueue_Enqueue(struct RfuBackupQueue *queue, const u8 *data);
bool8 RfuBackupQueue_Dequeue(struct RfuBackupQueue *queue, u8 *src);
void InitHostRfuGameData(struct RfuGameData *data, u8 activity, bool32 startedActivity, s32 partnerInfo);
void CreateWirelessStatusIndicatorSprite(u8 x, u8 y);
void DestroyWirelessStatusIndicatorSprite(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);

#endif //GUARD_LINK_RFU_H
