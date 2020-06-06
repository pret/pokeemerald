#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"
#include "AgbRfu_LinkManager.h"

#define RFU_COMMAND_0x4400 0x4400
#define RFU_COMMAND_0x8800 0x8800
#define RFU_COMMAND_0x8900 0x8900
#define RFU_COMMAND_0xA100 0xA100
#define RFU_COMMAND_0x7700 0x7700
#define RFU_COMMAND_0x7800 0x7800
#define RFU_COMMAND_0x6600 0x6600
#define RFU_COMMAND_0x5F00 0x5F00
#define RFU_COMMAND_0x2F00 0x2F00
#define RFU_COMMAND_0xBE00 0xBE00
#define RFU_COMMAND_0xEE00 0xEE00
#define RFU_COMMAND_0xED00 0xED00

// RfuTgtData.gname is read as these structs.
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
    /* 0x000 */ u8 unk_00[32][70];
    /* 0x8c0 */ vu8 unk_8c0;
    /* 0x8c1 */ vu8 unk_8c1;
    /* 0x8c2 */ vu8 count;
    /* 0x8c3 */ vu8 full;
};

struct RfuSendQueue
{
    /* 0x000 */ u8 unk_00[40][14];
    /* 0x230 */ vu8 unk_230;
    /* 0x231 */ vu8 unk_231;
    /* 0x232 */ vu8 count;
    /* 0x233 */ vu8 full;
};

struct UnkRfuStruct_2_Sub_c1c
{
    /* 0x00 */ u8 unk_00[2][14];
    /* 0x1c */ vu8 unk_1c;
    /* 0x1d */ vu8 unk_1d;
    /* 0x1e */ vu8 count;
};

struct UnkRfuStruct_Sub_Unused
{
    /* 0x000 */ u8 unk_00[2][256];
    /* 0x200 */ vu8 unk_200;
    /* 0x201 */ vu8 unk_201;
    /* 0x202 */ vu8 unk_202;
    /* 0x203 */ vu8 unk_203;
};

struct GFRfuManager
{
    /* 0x000 */ void (*callback)(void);
    /* 0x004 */ u16 state;
    /* 0x006 */ u8 filler_06[4];
    /* 0x00a */ u16 linkmanMsg;
    /* 0x00c */ u8 parentChild;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ u8 unk_0e;
    /* 0x00f */ u8 unk_0f;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u8 unk_14[4][14];
    /* 0x04c */ u8 unk_4c[14];
    /* 0x05a */ u8 unk_5a;
    /* 0x05b */ u8 unk_5b;
    /* 0x05c */ bool8 unk_5c[MAX_RFU_PLAYERS];
    /* 0x061 */ bool8 unk_61[MAX_RFU_PLAYERS];
    /* 0x066 */ u8 idleTaskId;
    /* 0x067 */ u8 searchTaskId;
    /* 0x068 */ u8 filler_68[4];
    /* 0x06c */ struct RfuBlockSend unk_6c;
    /* 0x080 */ struct RfuBlockSend unk_80[MAX_RFU_PLAYERS];
    /* 0x0e4 */ u8 unk_e4[5];
    /* 0x0e9 */ u8 unk_e9[5];
    /* 0x0ee */ vu8 errorState;
    /* 0x0ef */ bool8 isShuttingDown;
    /* 0x0f0 */ u8 linkLossRecoveryState;
    /* 0x0f1 */ u8 errorStatus;
    /* 0x0f2 */ u16 unk_f2[6];
    /* 0x0fe */ u16 unk_fe;
    /* 0x100 */ u16 unk_100;
    /* 0x102 */ u8 unk_102;
    /* 0x103 */ u8 filler_103[0x10A - 0x103];
    /* 0x10A */ struct GFtgtGname unk_10A;
    u8 filler_;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    /* 0x124 */ struct RfuRecvQueue recvQueue;
    /* 0x9e8 */ struct RfuSendQueue sendQueue;
    /* 0xc1c */ struct UnkRfuStruct_2_Sub_c1c unk_c1c;
    /* 0xc3c */ vu8 unk_c3c;
    /* 0xc3d */ u8 unk_c3d;
    /* 0xc3e */ vu8 childSlot;
    /* 0xc3f */ u8 unk_c3f[70];
    /* 0xc85 */ u8 unk_c85;
    /* 0xc86 */ u8 unk_c86;
    /* 0xc87 */ u8 recvCmds[5][7][2];
    /* 0xccd */ u8 parentId;
    /* 0xcce */ u8 multiplayerId;
    /* 0xccf */ u8 unk_ccf;
    /* 0xcd0 */ vu8 unk_cd0;
    /* 0xcd1 */ u8 unk_cd1[4];
    /* 0xcd5 */ u8 unk_cd5[4];
    /* 0xcd9 */ u8 unk_cd9;
    /* 0xcda */ u8 unk_cda;
    /* 0xcdb */ vu8 unk_cdb;
    /* 0xcdc */ vu8 unk_cdc;
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
u8 Rfu_GetLinkPlayerCount(void);
u8 Rfu_GetMultiplayerId(void);
bool8 sub_8010100(u8 a0);
bool8 IsLinkRfuTaskFinished(void);
bool8 Rfu_IsMaster(void);
void task_add_05_task_del_08FA224_when_no_RfuFunc(void);
void sub_8010434(void);
void ResetLinkRfuGFLayer(void);
void sub_800E174(void);
void InitRFU(void);
bool32 sub_8010EC0(void);
bool32 sub_8010F1C(void);
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
u8 sub_801048C(bool32 a0);
void LinkRfu3_SetGnameUnameFromStaticBuffers(struct GFtgtGname *buff1, u8 *buff2);
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
void SetTradeBoardRegisteredMonInfo(u32 type, u32 species, u32 level);
void InitializeRfuLinkManager_EnterUnionRoom(void);
void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 a2);
bool32 IsUnionRoomListenTaskActive(void);
void sub_800FE50(void *a0);
bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name);
void sub_8011DE0(u32 arg0);
u8 sub_801100C(s32 a0);
void sub_800EF7C(void);
bool8 LinkRfu_GetNameIfCompatible(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 LinkRfu_GetNameIfSerial7F7D(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
s32 sub_800E87C(u8 idx);
void CreateTask_RfuIdle(void);
void DestroyTask_RfuIdle(void);
void sub_8010198(void);
void sub_8011AC8(void);
void LinkRfu_FatalError(void);
bool32 sub_8011A9C(void);
void sub_80104B0(void);
void sub_8011A50(void);
void sub_80110B8(u32 a0);
bool8 sub_800DAC8(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void sub_800ED34(u16 unused);
bool32 RfuSerialNumberIsValid(u32 serialNo);
bool8 sub_8012224(void);
void sub_8011BA4(void);
void sub_800D6C8(struct RfuRecvQueue *ptr);
void sub_800D724(struct RfuSendQueue *ptr);
void sub_800D780(struct UnkRfuStruct_Sub_Unused *ptr);
void sub_800D7D8(struct RfuRecvQueue *q1, u8 *q2);
void sub_800D888(struct RfuSendQueue *q1, u8 *q2);
bool8 sub_800D934(struct RfuRecvQueue *q1, u8 *q2);
bool8 sub_800D9DC(struct RfuSendQueue *q1, u8 *q2);
void sub_800DA68(struct UnkRfuStruct_2_Sub_c1c *q1, const u8 *q2);
bool8 sub_800DAC8(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void sub_800DB18(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
bool8 sub_800DB84(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
void sub_800DBF8(u8 *q1, u8 mode);
void PkmnStrToASCII(u8 *q1, const u8 *q2);
void ASCIIToPkmnStr(u8 *q1, const u8 *q2);
u8 sub_800DD1C(u8 maxFlags);
void sub_800DD94(struct GFtgtGname *data, u8 r9, bool32 r2, s32 r3);
void CreateWirelessStatusIndicatorSprite(u8 x, u8 y);
void DestroyWirelessStatusIndicatorSprite(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);
u8 sub_800E124(void);
void sub_800E15C(struct Sprite *sprite, s32 signalStrengthAnimNum);
void sub_800E174(void);
void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name);
bool32 NameIsNotEmpty(const u8 *name);
void RecordMixTrainerNames(void);
void WipeTrainerNameRecords(void);

#endif //GUARD_LINK_RFU_H
