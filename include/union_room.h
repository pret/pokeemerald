#ifndef GUARD_UNION_ROOM_H
#define GUARD_UNION_ROOM_H

#include "link_rfu.h"
#include "link.h"
#include "constants/union_room.h"

// In the Union Room the player is only ever connected to ≤ 4 other players.
// However, there can be up to MAX_UNION_ROOM_LEADERS (8) object events to
// represent leaders of recently discovered link groups, and each of those groups 
// may have up to MAX_RFU_PLAYERS (5) players in it including the leader.
// These players are represented on-screen by NPC sprites drawn around the leader.
// Thus there can be 40 sprites of other players on-screen, in 8 groups of 5.
#define NUM_UNION_ROOM_SPRITES (MAX_UNION_ROOM_LEADERS * MAX_RFU_PLAYERS)

// The maximum number of recently connected players that can be tracked.
// Note that this is significantly less than NUM_UNION_ROOM_SPRITES, i.e. not
// every player that can be shown in the Union Room can be tracked at once.
// Information such as a group member's gender can instead be read from partnerInfo  
// of the leader's RfuGameData by tracking at least all of the group leaders.
#define MAX_RFU_PLAYER_LIST_SIZE 16

struct RfuPlayerData
{
    struct RfuGameData data;
    u8 ALIGNED(4) name[RFU_USER_NAME_LENGTH];
};

struct RfuPlayer
{
    struct RfuPlayerData rfu;
    u16 timeoutCounter;
    u8 groupScheduledAnim:2;
    bool8 useRedText:1; // Never set
    u8 newPlayerCountdown;
    u8 unused;
};

struct RfuPlayerList
{
    struct RfuPlayer players[MAX_RFU_PLAYER_LIST_SIZE];
};

struct RfuIncomingPlayer
{
    struct RfuPlayerData rfu;
    bool8 active:1;
};

struct RfuIncomingPlayerList
{
    struct RfuIncomingPlayer players[MAX_RFU_PLAYERS];
};

struct WirelessLink_Leader
{
    struct RfuPlayerList *playerList;
    struct RfuIncomingPlayerList *incomingPlayerList;
    struct RfuPlayerList *playerListBackup;
    u8 state;
    u8 textState;
    u8 delayTimerAfterOk;
    u8 listWindowId;
    u8 bButtonCancelWindowId;
    u8 nPlayerModeWindowId;
    u8 listTaskId;
    u8 playerCount;
    u16 yesNoWindowId;
    u8 unused;
    u8 listenTaskId;
    u8 activity;
    u8 joinRequestAnswer;
    u16 memberConfirmTimeout;
};

struct WirelessLink_Group
{
    struct RfuPlayerList *playerList;
    struct RfuIncomingPlayerList *incomingPlayerList;
    u8 state;
    u8 textState;
    u8 delayTimerAfterOk; // Unused
    u8 listWindowId;
    u8 bButtonCancelWindowId;
    u8 playerNameAndIdWindowId;
    u8 listTaskId;
    u8 leaderId;
    u8 unused;
    u8 listenTaskId;
    bool8 isWonderNews;
    bool8 showListMenu; // Never set
    u8 refreshTimer;
    u8 delayBeforePrint;
};

struct UnionRoomObject
{
    u8 state;
    u16 gfxId;
    s8 animState;
    u8 schedAnim;
};

struct WirelessLink_URoom
{
    struct RfuPlayerList *playerList;
    struct RfuIncomingPlayerList *incomingChildList;
    struct RfuPlayerList *spawnPlayer;
    struct RfuIncomingPlayerList *incomingParentList;
    u16 unknown; // Never read
    u16 unreadPlayerId;
    u8 state;
    u8 stateAfterPrint;
    u8 textState;
    u8 filler[4];
    u8 topListMenuWindowId;
    u8 topListMenuId;
    u8 tradeBoardMainWindowId;
    u8 tradeBoardHeaderWindowId;
    u8 unused1;
    u8 searchTaskId;
    u8 spriteIds[NUM_UNION_ROOM_SPRITES];
    u8 unused2;
    u8 tradeBoardListMenuId;
    u16 playerSendBuffer[6];
    u8 activityRequestStrbufs[4][16];
    u16 partnerYesNoResponse;
    u16 recvActivityRequest[3];
    struct UnionRoomObject objects[MAX_UNION_ROOM_LEADERS];
    u8 trainerCardStrBuffer[12][15];
    u8 trainerCardColorStrBuffer[48];
    u8 trainerCardMsgStrBuffer[200];
};

struct UnionRoomTrade
{
    u16 state;
    u16 type;
    u32 playerPersonality;
    u8 offerPlayerId;
    u16 playerSpecies;
    u16 playerLevel;
    u16 species;
    u16 level;
    u32 personality;
};

extern u8 gPlayerCurrActivity;
extern struct RfuGameCompatibilityData gRfuPartnerCompatibilityData;

extern u16 gUnionRoomOfferedSpecies;
extern u8 gUnionRoomRequestedMonType;

u8 CreateTask_CreateTradeMenu(void);
void SetUsingUnionRoomStartMenu(void);
void CreateTask_LinkMysteryGiftWithFriend(u32 activity);
void CreateTask_LinkMysteryGiftOverWireless(u32 activity);
void CreateTask_SendMysteryGift(u32 activity);
u8 CreateTask_ListenToWireless(void);
void StartUnionRoomBattle(u16 battleFlags);

#endif //GUARD_UNION_ROOM_H
