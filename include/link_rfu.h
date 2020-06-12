#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"
#include "AgbRfu_LinkManager.h"

#define RFU_COMMAND_0x8800 0x8800
#define RFU_COMMAND_0x8900 0x8900
#define RFU_COMMAND_0xa100 0xa100
#define RFU_COMMAND_0x7700 0x7700
#define RFU_COMMAND_0x7800 0x7800
#define RFU_COMMAND_0x6600 0x6600
#define RFU_COMMAND_0x5f00 0x5f00
#define RFU_COMMAND_0x4400 0x4400
#define RFU_COMMAND_0x2f00 0x2f00
#define RFU_COMMAND_0xbe00 0xbe00
#define RFU_COMMAND_0xee00 0xee00
#define RFU_COMMAND_0xed00 0xed00

struct GFtgtGnameSub
{
    u16 language:4;
    u16 hasNews:1;
    u16 hasCard:1;
    u16 unk_00_6:1;
    u16 isChampion:1;
    u16 hasNationalDex:1;
    u16 gameClear:1;
    u16 version:4;
    u16 unk_01_6:2;
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

struct UnkLinkRfuStruct_02022B2C
{
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u16 unk_06;
    struct GFtgtGname *unk_08;
    u8 *unk_0c;
    u8 unk_10;
    u8 unk_11;
    u16 unk_12;
    u16 unk_14;
};

struct UnkLinkRfuStruct_02022B44
{
    u8 fill_00[6];
    u16 unk_06;
    u8 fill_08[6];
    vu8 unk_0e;
    u8 unk_0f;
    u8 fill_10[0x54];
    u16 unk_64;
    u8 fill_66[0x1d];
    u8 unk_83;
    u8 fill_84[0x58];
};

struct RfuBlockSend
{
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 count; // max 21
    /* 0x04 */ const u8 *payload;
    /* 0x08 */ u32 receivedFlags;
    /* 0x0c */ u32 failedFlags;
    /* 0x10 */ u8 sending;
    /* 0x11 */ u8 owner;
    /* 0x12 */ u8 receiving;
};;

struct UnkRfuStruct_2_Sub_124
{
    /* 0x000 */ u8 slots[32][70];
    /* 0x8c0 */ vu8 recv_slot;
    /* 0x8c1 */ vu8 send_slot;
    /* 0x8c2 */ vu8 count;
    /* 0x8c3 */ vu8 full;
};

struct RfuSendQueue
{
    /* 0x000 */ u8 slots[40][14];
    /* 0x230 */ vu8 recv_slot;
    /* 0x231 */ vu8 send_slot;
    /* 0x232 */ vu8 count;
    /* 0x233 */ vu8 full;
};

struct UnkRfuStruct_2_Sub_c1c
{
    /* 0x00 */ u8 slots[2][14];
    /* 0x1c */ vu8 recv_slot;
    /* 0x1d */ vu8 send_slot;
    /* 0x1e */ vu8 count;
};

struct UnkRfuStruct_Sub_Unused
{
    /* 0x000 */ u8 slots[2][256];
    /* 0x200 */ vu8 recv_slot;
    /* 0x201 */ vu8 send_slot;
    /* 0x202 */ vu8 count;
    /* 0x203 */ vu8 full;
};

typedef struct UnkRfuStruct_2
{
    /* 0x000 */ void (*RfuFunc)(void);
    /* 0x004 */ u16 state;
    /* 0x006 */ u8 filler_06[4];
    /* 0x00a */ u16 linkman_msg;
    /* 0x00c */ u8 parent_child;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ u8 unk_0e;
    /* 0x00f */ u8 unk_0f;
    /* 0x010 */ u16 linkman_param[2];
    /* 0x014 */ u8 unk_14[RFU_CHILD_MAX][14];
    /* 0x04c */ u8 unk_4c[14];
    /* 0x05a */ u8 cmdA100_blockRequestType;
    /* 0x05b */ u8 unk_5b;
    /* 0x05c */ u8 unk_5c[5];
    /* 0x061 */ u8 unk_61[5];
    /* 0x066 */ u8 unk_66;
    /* 0x067 */ u8 unk_67;
    /* 0x068 */ u8 filler_68[4];
    /* 0x06c */ struct RfuBlockSend cmd_8800_sendbuf;
    /* 0x080 */ struct RfuBlockSend cmd_8800_recvbuf[5];
    /* 0x0e4 */ u8 cmd5f00Ack[5];
    /* 0x0e9 */ u8 cmd_6600_recvd[5];
    /* 0x0ee */ vu8 errorState;
    /* 0x0ef */ bool8 isShuttingDown;
    /* 0x0f0 */ u8 linkLossRecoveryState;
    /* 0x0f1 */ u8 unk_f1;
    /* 0x0f2 */ u16 unk_f2[6];
    /* 0x0fe */ u16 cmd_6600_timer;
    /* 0x100 */ u16 cmd_6600_count;
    /* 0x102 */ u8 unk_102;
	/* 0x104 */ struct RfuTgtData unk_104;
    /* 0x124 */ struct UnkRfuStruct_2_Sub_124 unk_124;
    /* 0x6a0 */ struct RfuSendQueue sendQueue;
    /* 0x8d4 */ struct UnkRfuStruct_2_Sub_c1c unk_c1c;
    /* 0x8f4 */ vu8 unk_c3c;
    /* 0x8f5 */ u8 reconnectedParentIdx;
    /* 0x8f6 */ vu8 child_slot;
    /* 0x8f7 */ u8 unk_c3f[70];
    /* 0x93d */ u8 unk_c85;
    /* 0x93e */ u8 unk_c86;
    /* 0x93f */ u8 recvCmds[5][7][2];
    /* 0x985 */ u8 parentId;
    /* 0x986 */ u8 unk_cce; // childId
    /* 0x987 */ u8 unk_ccf;
    /* 0x988 */ vu8 unk_cd0;
    /* 0x989 */ u8 unk_cd1[RFU_CHILD_MAX];
    /* 0x98d */ u8 unk_cd5[RFU_CHILD_MAX];
    /* 0x991 */ u8 unk_cd9;
    /* 0x992 */ u8 unk_cda;
    /* 0x993 */ vu8 unk_cdb;
    /* 0x994 */ vu8 unk_cdc;
    /* 0x995 */ u8 unk_cdd;
    /* 0x996 */ u8 linkPlayerIdx[RFU_CHILD_MAX];
    /* 0x99a */ u8 bm_PartnerFlags;
    /* 0x99b */ u8 bm_DisconnectSlot;
    /* 0x99c */ u8 unk_ce4;
    /* 0x99d */ u8 unk_ce5;
    /* 0x99e */ u8 unionRoomChatters;
    /* 0x99f */ u8 acceptSlot_flag;
    /* 0x9a0 */ bool8 unk_ce8;
    /* 0x9a1 */ u8 unk_ce9;
    /* 0x9a2 */ u8 unk_cea[RFU_CHILD_MAX];
    /* 0x9a6 */ u8 unk_cee[RFU_CHILD_MAX];
} GF_RFU_MANAGER; // size = 0xcf4

struct SioInfo
{
    char magic[15]; // PokemonSioInfo
    u8 playerCount;
    u8 linkPlayerIdx[RFU_CHILD_MAX];
    struct LinkPlayer linkPlayers[MAX_RFU_PLAYERS];
    u8 fill_a0[0x5c];
};

// Exported RAM declarations

extern struct GFtgtGname gHostRFUtgtGnameBuffer;
extern u8 gHostRFUtgtUnameBuffer[];
extern struct UnkRfuStruct_2 Rfu;
extern u8 gWirelessStatusIndicatorSpriteId;

// Exported ROM declarations
void WipeTrainerNameRecords(void);
void sub_800E700(void);
void LinkRfu_Shutdown(void);
void Rfu_SetBlockReceivedFlag(u8 who);
void Rfu_ResetBlockReceivedFlag(u8 who);
bool32 IsSendingKeysToRfu(void);
void StartSendingKeysToRfu(void);
void sub_800F850(void);
u8 Rfu_GetBlockReceivedStatus(void);
bool32 Rfu_InitBlockSend(const u8 *src, size_t size);
void ClearLinkRfuCallback(void);
u8 GetRfuPlayerCount(void);
u8 LinkRfu_GetMultiplayerId(void);
bool8 LinkRfu_PrepareCmd0xA100(u8 a0);
bool8 IsLinkRfuTaskFinished(void);
bool8 Rfu_IsMaster(void);
void Rfu_BeginBuildAndSendCommand5F(void);
void LinkRfu_SetRfuFuncToSend6600(void);
void ResetLinkRfuGFLayer(void);
void UpdateWirelessStatusIndicatorSprite(void);
void InitRFU(void);
bool32 LinkRfuMain1(void);
bool32 LinkRfuMain2(void);
bool32 RfuIsErrorStatus1or2(void);
bool32 IsRfuRecvQueueEmpty(void);
u32 GetRfuRecvQueueLength(void);
void RfuVSync(void);
void sub_80111B0(bool32 a0);
u8 RfuGetErrorStatus(void);
struct GFtgtGname *GetHostRFUtgtGname(void);
void UpdateGameData_GroupLockedIn(u8 a0);
void GetLinkmanErrorParams(u32 a0);
void RfuSetErrorStatus(u8 a0, u16 a1);
u8 ToggleLMANlinkRecovery(bool32 a0);
void sub_800DF90(struct GFtgtGname *buff1, u8 *buff2);
void SetHostRFUtgtGname(u8 a0, u32 a1, u32 a2);
void InitializeRfuLinkManager_LinkLeader(u32 a0);
bool32 sub_8012240(void);
void LinkRfu_StopManagerAndFinalizeSlots(void);
bool32 sub_80105EC(void);
bool32 TrainerIdAndNameStillInPartnersList(u16 a0, const u8 *a1);
void SendByteToPartnerByIdAndName(u8 a0, u16 a1, const u8 *a2);
u32 WaitSendByteToPartnerByIdAndName(u16 a0, const u8 *a1);
void RequestDisconnectSlotByTrainerNameAndId(const u8 *a0, u16 a1);
bool8 LmanAcceptSlotFlagIsNotZero(void);
bool32 WaitRfuState(bool32 a0);
void DestroyWirelessStatusIndicatorSprite(void);
void sub_801103C(void);
void InitializeRfuLinkManager_JoinGroup(void);
void LinkRfuNIsend8(void);
void RecordMixTrainerNames(void);
void LinkRfu_CreateConnectionAsParent(void);
void LinkRfu_StopManagerBeforeEnteringChat(void);
void UpdateGameDataWithActivitySpriteGendersFlag(u8 a0, u32 a1, u32 a2);
void CreateTask_RfuReconnectWithParent(const u8 *src, u16 trainerId);
void SetGnameBufferWonderFlags(bool32 a0, bool32 a1);
void ClearAndInitHostRFUtgtGname(void);
void RfuUpdatePlayerGnameStateAndSend(u32 a0, u32 a1, u32 a2);
void InitializeRfuLinkManager_EnterUnionRoom(void);
void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 a2);
bool32 IsUnionRoomListenTaskActive(void);
void RfuPrepareSend0x2f00(void *a0);
bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name);
void sub_8011DE0(u32 arg0);
u8 sub_801100C(s32 a0);
void sub_800EF7C(void);
bool8 LinkRfu_GetNameIfCompatible(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 LinkRfu3_SetGnameUnameFromStaticBuffers(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
s32 sub_800E87C(u8 idx);
void LinkRfu_CreateIdleTask(void);
void sub_8010198(void);
void sub_8011AC8(void);
void LinkRfu_FatalError(void);
bool32 GetRfuUnkCE8(void);
void sub_80104B0(void);
void sub_8011A50(void);
void sub_80110B8(u32 a0);
bool8 RFU_queue_2_14_send(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void sub_800EAB4(void);
void sub_800EAFC(void);
void MscCallback_Child(u16 unused);
void MSCCallback_SetUnkCDB(u16 unused);
void sub_800F048(void);
void RfuHandleReceiveCommand(u8 unused);
void ResetSendDataManager(struct RfuBlockSend *data);
void RfuPrepareSendBuffer(u16 command);
void RfuFunc_HandleBlockSend(void);
void RfuFunc_SendNextBlock(void);
void RfuFunc_SendLastBlock(void);
bool32 RfuSerialNumberIsValid(u32 a0);
void CallRfuFunc(void);
void sub_8010750(void);
s32 sub_80107A0(void);
void sub_801084C(u8 taskId);
void sub_80109E8(u16 a0);
void ValidateAndReceivePokemonSioInfo(void *a0);
void Task_ExchangeLinkPlayers(u8 taskId);
void sub_8010D0C(u8 taskId);
void sub_80115EC(s32 a0);
u8 GetPartnerIndexByNameAndTrainerID(const u8 *trainerName, u16 trainerId);
void RfuReqDisconnectSlot(u32 a0);
void sub_8011E94(u32 a0, u32 a1);
bool8 sub_8012224(void);
void rfu_dbg_clear(void);
void sub_801209C(u8 taskId);
void sub_8011BF8(void);
void LinkRfu_CreateIdleTask(void);
void RFU_queue_32_70_reset(struct UnkRfuStruct_2_Sub_124 *ptr);
void RFU_queue_40_14_reset(struct RfuSendQueue *ptr);
void RFU_queue_2_256_reset(struct UnkRfuStruct_Sub_Unused *ptr);
void RFU_queue_32_70_recv(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2);
void RFU_queue_40_14_recv(struct RfuSendQueue *q1, u8 *q2);
bool8 RFU_queue_32_70_send(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2);
bool8 RFU_queue_40_14_send(struct RfuSendQueue *q1, u8 *q2);
void RFU_queue_2_14_recv(struct UnkRfuStruct_2_Sub_c1c *q1, const u8 *q2);
bool8 RFU_queue_2_14_send(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void RFU_queue_2_256_recv(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
bool8 RFU_queue_2_256_send(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
void sub_800DBF8(u8 *q1, u8 mode);
void PkmnStrToASCII(u8 *q1, const u8 *q2);
void ASCIIToPkmnStr(u8 *q1, const u8 *q2);
u8 GetConnectedChildStrength(u8 maxFlags);
void InitHostRFUtgtGname(struct GFtgtGname *data, u8 r9, bool32 r2, s32 r3);
bool8 LinkRfu_GetNameIfCompatible(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 LinkRfu3_SetGnameUnameFromStaticBuffers(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
void sub_800DF90(struct GFtgtGname *buff1, u8 *buff2);
void CreateWirelessStatusIndicatorSprite(u8 x, u8 y);
void DestroyWirelessStatusIndicatorSprite(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);
u8 GetParentSignalStrength(void);
void SetAndRestartWirelessStatusIndicatorAnim(struct Sprite *sprite, s32 signalStrengthAnimNum);
void UpdateWirelessStatusIndicatorSprite(void);
void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name);
bool32 NameIsNotEmpty(const u8 *name);
void RecordMixTrainerNames(void);
bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name);
void WipeTrainerNameRecords(void);

#endif //GUARD_LINK_RFU_H
