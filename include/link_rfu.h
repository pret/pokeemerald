#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"
#include "AgbRfu_LinkManager.h"

#define RFUCMD_SEND_PACKET         0x2F00
#define RFUCMD_BLENDER_SEND_KEYS   0x4400
#define RFUCMD_READY_CLOSE_LINK    0x5F00
#define RFUCMD_READY_EXIT_STANDBY  0x6600
#define RFUCMD_0x7700              0x7700
#define RFUCMD_0x7800              0x7800
#define RFUCMD_0x8800              0x8800
#define RFUCMD_0x8900              0x8900
#define RFUCMD_SEND_BLOCK_REQ      0xA100
#define RFUCMD_SEND_HELD_KEYS      0xBE00
#define RFUCMD_0xED00              0xED00
#define RFUCMD_0xEE00              0xEE00

#define RFU_SERIAL_7F7D 0x7F7D

#define RECV_QUEUE_NUM_SLOTS 32
#define RECV_QUEUE_SLOT_LENGTH (14 * MAX_RFU_PLAYERS)

#define SEND_QUEUE_NUM_SLOTS 40
#define SEND_QUEUE_SLOT_LENGTH 14

#define BACKUP_QUEUE_NUM_SLOTS 2
#define BACKUP_QUEUE_SLOT_LENGTH 14

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
#define RFU_STATUS_10                   10
#define RFU_STATUS_11                   11
#define RFU_STATUS_ACK_JOIN_GROUP       12

// RfuTgtData.gname is read as these structs.
struct GFtgtGnameSub
{
    u16 language:4;
    u16 hasNews:1;
    u16 hasCard:1;
    u16 unknown:1; // Never read
    u16 isChampion:1;
    u16 hasNationalDex:1;
    u16 gameClear:1;
    u16 version:4;
    u8 playerTrainerId[2];
};

struct __attribute__((packed, aligned(2))) GFtgtGname
{
    struct GFtgtGnameSub unk_00;
    u8 child_sprite_gender[RFU_CHILD_MAX]; // u8 sprite_idx:3;
    // u8 gender:1;
    // u8 unk_4:3
    // u8 active:1
    u16 species:10;
    u16 type:6;
    u8 activity:7;
    u8 started:1;
    u8 playerGender:1;
    u8 level:7;
    u8 padding;
}; // size: RFU_GNAME_SIZE

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
    /* 0x000 */ u8 slots[RECV_QUEUE_NUM_SLOTS][RECV_QUEUE_SLOT_LENGTH];
    /* 0x8c0 */ vu8 recvSlot;
    /* 0x8c1 */ vu8 sendSlot;
    /* 0x8c2 */ vu8 count;
    /* 0x8c3 */ vu8 full;
};

struct RfuSendQueue
{
    /* 0x000 */ u8 slots[SEND_QUEUE_NUM_SLOTS][SEND_QUEUE_SLOT_LENGTH];
    /* 0x230 */ vu8 recvSlot;
    /* 0x231 */ vu8 sendSlot;
    /* 0x232 */ vu8 count;
    /* 0x233 */ vu8 full;
};

struct RfuBackupQueue
{
    /* 0x00 */ u8 slots[BACKUP_QUEUE_NUM_SLOTS][BACKUP_QUEUE_SLOT_LENGTH];
    /* 0x1c */ vu8 recvSlot;
    /* 0x1d */ vu8 sendSlot;
    /* 0x1e */ vu8 count;
};

struct GFRfuManager
{
    /* 0x000 */ void (*callback)(void);
    /* 0x004 */ u16 state;
    /* 0x006 */ u8 filler_06[4];
    /* 0x00a */ u16 linkmanMsg;
    /* 0x00c */ u8 parentChild;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ bool8 unk_0e;
    /* 0x00f */ u8 unk_0f;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u8 unk_14[RFU_CHILD_MAX][14];
    /* 0x04c */ u8 unk_4c[14];
    /* 0x05a */ u8 blockRequestType;
    /* 0x05b */ u8 unk_5b;
    /* 0x05c */ bool8 blockReceived[MAX_RFU_PLAYERS];
    /* 0x061 */ bool8 numBlocksReceived[MAX_RFU_PLAYERS];
    /* 0x066 */ u8 idleTaskId;
    /* 0x067 */ u8 searchTaskId;
    /* 0x068 */ u8 filler_68[4];
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
    /* 0x100 */ u16 unk_100;
    /* 0x102 */ u8 unk_102;
    /* 0x103 */ u8 filler_103[0x10A - 0x103];
    /* 0x10A */ struct GFtgtGname unk_10A;
    u8 filler_;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    /* 0x124 */ struct RfuRecvQueue recvQueue;
    /* 0x9e8 */ struct RfuSendQueue sendQueue;
    /* 0xc1c */ struct RfuBackupQueue backupQueue;
    /* 0xc3c */ vu8 linkRecovered;
    /* 0xc3d */ u8 unk_c3d;
    /* 0xc3e */ vu8 childSlot;
    /* 0xc3f */ u8 unk_c3f[70];
    /* 0xc85 */ u8 unk_c85;
    /* 0xc86 */ u8 recvStatus;
    /* 0xc87 */ u8 recvCmds[5][7][2];
    /* 0xccd */ u8 parentId;
    /* 0xcce */ u8 multiplayerId;
    /* 0xccf */ u8 unk_ccf;
    /* 0xcd0 */ vu8 unk_cd0;
    /* 0xcd1 */ u8 partnerSendStatuses[RFU_CHILD_MAX];
    /* 0xcd5 */ u8 partnerRecvStatuses[RFU_CHILD_MAX];
    /* 0xcd9 */ u8 unk_cd9;
    /* 0xcda */ u8 unk_cda;
    /* 0xcdb */ vbool8 unk_cdb;
    /* 0xcdc */ vbool8 unk_cdc;
    /* 0xcdd */ u8 unk_cdd;
    /* 0xcde */ u8 linkPlayerIdx[RFU_CHILD_MAX];
    /* 0xce2 */ u8 unk_ce2;
    /* 0xce2 */ u8 unk_ce3;
    /* 0xce4 */ u8 unk_ce4;
    /* 0xce5 */ u8 unk_ce5;
    /* 0xce5 */ u8 unk_ce6;
    /* 0xce7 */ u8 acceptSlot_flag;
    /* 0xce8 */ u8 unk_ce8;
    /* 0xce9 */ u8 unk_ce9;
    /* 0xcea */ u8 unk_cea[4];
    /* 0xcee */ u8 unk_cee[4];
}; // size = 0xcf4

// Exported RAM declarations

extern struct GFtgtGname gHostRFUtgtGnameBuffer;
extern u8 gHostRFUtgtUnameBuffer[];
extern struct GFRfuManager Rfu;
extern u8 gWirelessStatusIndicatorSpriteId;

// Exported ROM declarations
void WipeTrainerNameRecords(void);
void InitRFUAPI(void);
void LinkRfu_Shutdown(void);
void Rfu_SetBlockReceivedFlag(u8 who);
void Rfu_ResetBlockReceivedFlag(u8 who);
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
bool32 sub_8010EC0(void);
bool32 sub_8010F1C(void);
bool32 RfuHasErrored(void);
bool32 IsRfuRecvQueueEmpty(void);
u32 GetRfuRecvQueueLength(void);
void RfuVSync(void);
void sub_80111B0(bool32 a0);
u8 RfuGetStatus(void);
struct GFtgtGname *GetHostRFUtgtGname(void);
void UpdateGameData_GroupLockedIn(u8 a0);
void GetLinkmanErrorParams(u32 a0);
void RfuSetStatus(u8 a0, u16 a1);
u8 sub_801048C(bool32 a0);
void LinkRfu3_SetGnameUnameFromStaticBuffers(struct GFtgtGname *buff1, u8 *buff2);
void SetHostRFUtgtGname(u8 activity, u32 child_sprite_genders, bool32 started);
void InitializeRfuLinkManager_LinkLeader(u32 a0);
bool32 sub_8012240(void);
void LinkRfu_StopManagerAndFinalizeSlots(void);
bool32 sub_80105EC(void);
bool32 HasTrainerLeftPartnersList(u16 trainerId, const u8 *name);
void SendRfuStatusToPartner(u8 status, u16 trainerId, const u8 *name);
u32 WaitSendRfuStatusToPartner(u16 trainerId, const u8 *name);
void RequestDisconnectSlotByTrainerNameAndId(const u8 *a0, u16 a1);
bool8 LmanAcceptSlotFlagIsNotZero(void);
bool32 WaitRfuState(bool32 a0);
void sub_801103C(void);
void InitializeRfuLinkManager_JoinGroup(void);
void SendLeaveGroupNotice(void);
void RecordMixTrainerNames(void);
void LinkRfu_CreateConnectionAsParent(void);
void LinkRfu_StopManagerBeforeEnteringChat(void);
void UpdateGameData_SetActivity(u8 activity, u32 flags, bool32 started);
void CreateTask_RfuReconnectWithParent(const u8 *src, u16 trainerId);
void SetGnameBufferWonderFlags(bool32 a0, bool32 a1);
void ClearAndInitHostRFUtgtGname(void);
void SetTradeBoardRegisteredMonInfo(u32 type, u32 species, u32 level);
void InitializeRfuLinkManager_EnterUnionRoom(void);
void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 a2);
bool32 IsUnionRoomListenTaskActive(void);
void Rfu_SendPacket(void *data);
bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name);
void sub_8011DE0(u32 arg0);
u8 sub_801100C(s32 a0);
void sub_800EF7C(void);
bool8 LinkRfu_GetNameIfCompatible(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 LinkRfu_GetNameIfSerial7F7D(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
s32 sub_800E87C(u8 idx);
void CreateTask_RfuIdle(void);
void DestroyTask_RfuIdle(void);
void ClearRecvCommands(void);
void LinkRfu_FatalError(void);
bool32 sub_8011A9C(void);
void sub_80104B0(void);
void sub_8011A50(void);
void sub_80110B8(u32 a0);
bool32 IsRfuSerialNumberValid(u32 serialNo);
bool8 IsRfuRecoveringFromLinkLoss(void);
void RfuRecvQueue_Reset(struct RfuRecvQueue *queue);
void RfuSendQueue_Reset(struct RfuSendQueue *queue);
void RfuRecvQueue_Enqueue(struct RfuRecvQueue *queue, u8 *data);
void RfuSendQueue_Enqueue(struct RfuSendQueue *queue, u8 *data);
bool8 RfuRecvQueue_Dequeue(struct RfuRecvQueue *queue, u8 *dest);
bool8 RfuSendQueue_Dequeue(struct RfuSendQueue *queue, u8 *dest);
void RfuBackupQueue_Enqueue(struct RfuBackupQueue *queue, const u8 *q2);
bool8 RfuBackupQueue_Dequeue(struct RfuBackupQueue *queue, u8 *q2);
void InitHostRFUtgtGname(struct GFtgtGname *data, u8 activity, bool32 started, s32 child_sprite_genders);
void CreateWirelessStatusIndicatorSprite(u8 x, u8 y);
void DestroyWirelessStatusIndicatorSprite(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);

#endif //GUARD_LINK_RFU_H
