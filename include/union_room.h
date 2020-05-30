#ifndef GUARD_UNION_ROOM_H
#define GUARD_UNION_ROOM_H

#include "link_rfu.h"

// Exported type declarations

struct WirelessGnameUnamePair
{
    struct GFtgtGname gname;
    u8 ALIGNED(4) playerName[PLAYER_NAME_LENGTH + 1];
};

struct UnkStruct_x1C // WirelessLink_Member?
{
    struct WirelessGnameUnamePair gname_uname;
    u8 active:1;
};

struct UnkStruct_x20 // WirelessLink_Member?
{
    struct WirelessGnameUnamePair gname_uname;
    u16 field_18;
    u8 groupScheduledAnim:2;
    u8 field_1A_1:1;
    u8 field_1B;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;
};

struct UnkStruct_Main0
{
    struct UnkStruct_x20 arr[8];
};

struct UnkStruct_Main4
{
    struct UnkStruct_x1C arr[5];
};

struct UnkStruct_Main8
{
    struct UnkStruct_x20 arr[5];
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
    u8 field_19;
    u16 field_1A;
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

struct UnkStruct_8019BA8
{
    u8 field_0;
    u8 field_1;
    s8 field_2;
    u8 field_3;
};

struct WirelessLink_URoom
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    struct UnkStruct_Main0 *field_8;
    struct UnkStruct_Main4 *field_C;
    u16 field_10;
    u16 field_12;
    u8 state;
    u8 stateAfterPrint;
    u8 textState;
    u8 field_17;
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 topListMenuWindowId;
    u8 topListMenuId;
    u8 tradeBoardSelectWindowId;
    u8 tradeBoardDetailsWindowId;
    u8 field_1F;
    u8 field_20;
    u8 spriteIds[40];
    u8 field_49;
    u8 field_4A;
    u16 playerSendBuffer[6];
    u8 activityRequestStrbufs[4][16];
    u16 partnerYesNoResponse;
    u16 recvActivityRequest[3];
    struct UnkStruct_8019BA8 field_A0[8];
    u8 field_C0[12][15];
    u8 field_174[48];
    u8 field_1A4[200];
};

union WirelessLink_Main
{
    struct WirelessLink_Leader *leader;
    struct WirelessLink_Group *group;
    struct WirelessLink_URoom *uRoom;
};

struct UnionRoomTrade
{
    u16 field_0;
    u16 type;
    u32 playerPersonality;
    u8 field_8;
    u8 field_9;
    u16 playerSpecies;
    u16 playerLevel;
    u16 species;
    u16 level;
    u16 field_12;
    u32 personality;
};

// Exported RAM declarations

extern u8 gPlayerCurrActivity;
extern union WirelessLink_Main gUnknown_02022C30;
extern struct GFtgtGnameSub gPartnerTgtGnameSub;

extern u16 gUnionRoomOfferedSpecies;
extern u8 gUnionRoomRequestedMonType;

// Exported ROM declarations

u8 CreateTask_ReturnFromLinkTrade(void);
void nullsub_89(u8 taskId);
void var_800D_set_xB(void);
void MEvent_CreateTask_CardOrNewsWithFriend(u32 arg0);
void MEvent_CreateTask_CardOrNewsOverWireless(u32 arg0);
void MEvent_CreateTask_Leader(u32 arg0);
u8 CreateTask_ListenToWireless(void);
void StartUnionRoomBattle(u16 battleFlags);

#endif //GUARD_UNION_ROOM_H
