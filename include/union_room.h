#ifndef GUARD_UNION_ROOM_H
#define GUARD_UNION_ROOM_H

#include "link_rfu.h"
#include "link.h"
#include "constants/union_room.h"

// Exported type declarations

struct WirelessGnameUnamePair
{
    struct GFtgtGname gname;
    u8 ALIGNED(4) playerName[PLAYER_NAME_LENGTH + 1];
};

struct UnkStruct_x1C
{
    struct WirelessGnameUnamePair gname_uname;
    u8 active:1;
};

struct UnkStruct_x20
{
    struct WirelessGnameUnamePair gname_uname;
    u16 timeoutCounter;
    u8 groupScheduledAnim:2;
    bool8 useRedText:1; // Never set
    u8 field_1B;
    u8 filler[3];
};

struct UnkStruct_Main0
{
    struct UnkStruct_x20 arr[MAX_UNION_ROOM_PLAYERS];
};

struct UnkStruct_Main4
{
    struct UnkStruct_x1C arr[MAX_RFU_PLAYERS];
};

struct UnkStruct_Main8
{
    struct UnkStruct_x20 arr[MAX_RFU_PLAYERS];
};

struct WirelessLink_Leader
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    struct UnkStruct_Main8 *field_8;
    u8 state;
    u8 textState;
    u8 delayTimerAfterOk;
    u8 listWindowId;
    u8 bButtonCancelWindowId;
    u8 nPlayerModeWindowId;
    u8 listTaskId;
    u8 playerCount;
    u16 field_14;
    u8 field_16;
    u8 listenTaskId;
    u8 activity;
    u8 joinRequestAnswer;
    u16 memberConfirmTimeout;
};

struct WirelessLink_Group
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    u8 state;
    u8 textState;
    u8 field_A;
    u8 listWindowId;
    u8 bButtonCancelWindowId;
    u8 playerNameAndIdWindowId;
    u8 listTaskId;
    u8 leaderId;
    u8 field_10;
    u8 listenTaskId;
    u8 isWonderNews;
    u8 field_13;
    u8 refreshTimer;
    u8 delayBeforePrint;
};

struct UnionRoomObject
{
    u8 state;
    u8 gfxId;
    s8 animState;
    u8 schedAnim;
};

struct WirelessLink_URoom
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    struct UnkStruct_Main0 *field_8;
    struct UnkStruct_Main4 *field_C;
    u16 unknown; // Never read
    u16 field_12;
    u8 state;
    u8 stateAfterPrint;
    u8 textState;
    u8 filler[4];
    u8 topListMenuWindowId;
    u8 topListMenuId;
    u8 tradeBoardSelectWindowId;
    u8 tradeBoardDetailsWindowId;
    u8 unused1;
    u8 searchTaskId;
    u8 spriteIds[40];
    u8 unused2;
    u8 tradeBoardListMenuId;
    u16 playerSendBuffer[6];
    u8 activityRequestStrbufs[4][16];
    u16 partnerYesNoResponse;
    u16 recvActivityRequest[3];
    struct UnionRoomObject objects[MAX_UNION_ROOM_PLAYERS];
    u8 trainerCardStrBuffer[12][15];
    u8 trainerCardColorStrBuffer[48];
    u8 trainerCardMsgStrBuffer[200];
};

union WirelessLink_Main
{
    struct WirelessLink_Leader *leader;
    struct WirelessLink_Group *group;
    struct WirelessLink_URoom *uRoom;
};

struct UnionRoomTrade
{
    u16 state;
    u16 type;
    u32 playerPersonality;
    u8 offerPlayerId;
    u8 filler1;
    u16 playerSpecies;
    u16 playerLevel;
    u16 species;
    u16 level;
    u16 filler2;
    u32 personality;
};

// Exported RAM declarations

extern u8 gPlayerCurrActivity;
extern union WirelessLink_Main gUnknown_02022C30;
extern struct GFtgtGnameSub gPartnerTgtGnameSub;

extern u16 gUnionRoomOfferedSpecies;
extern u8 gUnionRoomRequestedMonType;

// Exported ROM declarations

u8 CreateTask_CreateTradeMenu(void);
void SetUsingUnionRoomStartMenu(void);
void MEvent_CreateTask_CardOrNewsWithFriend(u32 arg0);
void MEvent_CreateTask_CardOrNewsOverWireless(u32 arg0);
void MEvent_CreateTask_Leader(u32 arg0);
u8 CreateTask_ListenToWireless(void);
void StartUnionRoomBattle(u16 battleFlags);

#endif //GUARD_UNION_ROOM_H
