#ifndef GUARD_LINK_H
#define GUARD_LINK_H

#define MAX_LINK_PLAYERS 4
#define MAX_RFU_PLAYERS 5
#define CMD_LENGTH 8
#define QUEUE_CAPACITY 50
#define BLOCK_BUFFER_SIZE 0x100

#define LINK_SLAVE 0
#define LINK_MASTER 8

#define LINK_STAT_LOCAL_ID               0x00000003
#define LINK_STAT_PLAYER_COUNT           0x0000001C
#define LINK_STAT_PLAYER_COUNT_SHIFT     2
#define LINK_STAT_MASTER                 0x00000020
#define LINK_STAT_MASTER_SHIFT           5
#define LINK_STAT_CONN_ESTABLISHED       0x00000040
#define LINK_STAT_CONN_ESTABLISHED_SHIFT 6
#define LINK_STAT_RECEIVED_NOTHING       0x00000100
#define LINK_STAT_RECEIVED_NOTHING_SHIFT 8
#define LINK_STAT_UNK_FLAG_9             0x00000200
#define LINK_STAT_UNK_FLAG_9_SHIFT       9
#define LINK_STAT_ERRORS                 0x0007F000
#define LINK_STAT_ERRORS_SHIFT           12

#define LINK_STAT_ERROR_HARDWARE         0x00001000
#define LINK_STAT_ERROR_HARDWARE_SHIFT   12
#define LINK_STAT_ERROR_CHECKSUM         0x00002000
#define LINK_STAT_ERROR_CHECKSUM_SHIFT   13
#define LINK_STAT_ERROR_QUEUE_FULL       0x00004000
#define LINK_STAT_ERROR_QUEUE_FULL_SHIFT 14
#define LINK_STAT_ERROR_LAG_MASTER       0x00010000
#define LINK_STAT_ERROR_LAG_MASTER_SHIFT 16
#define LINK_STAT_ERROR_INVALID_ID       0x00020000
#define LINK_STAT_ERROR_INVALID_ID_SHIFT 17
#define LINK_STAT_ERROR_LAG_SLAVE        0x00040000
#define LINK_STAT_ERROR_LAG_SLAVE_SHIFT  18

#define EXTRACT_PLAYER_COUNT(status) \
(((status) & LINK_STAT_PLAYER_COUNT) >> LINK_STAT_PLAYER_COUNT_SHIFT)
#define EXTRACT_MASTER(status) \
(((status) >> LINK_STAT_MASTER_SHIFT) & 1)
#define EXTRACT_CONN_ESTABLISHED(status) \
(((status) >> LINK_STAT_CONN_ESTABLISHED_SHIFT) & 1)
#define EXTRACT_RECEIVED_NOTHING(status) \
(((status) >> LINK_STAT_RECEIVED_NOTHING_SHIFT) & 1)
#define EXTRACT_LINK_ERRORS(status) \
(((status) & LINK_STAT_ERRORS) >> LINK_STAT_ERRORS_SHIFT)

#define LINKCMD_BLENDER_STOP            0x1111
#define LINKCMD_SEND_LINK_TYPE          0x2222
#define LINKCMD_BLENDER_SCORE_MISS      0x2345
#define LINKCMD_READY_EXIT_STANDBY      0x2FFE
#define LINKCMD_SEND_PACKET             0x2FFF
#define LINKCMD_BLENDER_SEND_KEYS       0x4444
#define LINKCMD_BLENDER_SCORE_BEST      0x4523
#define LINKCMD_BLENDER_SCORE_GOOD      0x5432
#define LINKCMD_DUMMY_1                 0x5555
#define LINKCMD_DUMMY_2                 0x5566
#define LINKCMD_READY_CLOSE_LINK        0x5FFF
#define LINKCMD_SEND_EMPTY              0x6666
#define LINKCMD_SEND_0xEE               0x7777
#define LINKCMD_BLENDER_PLAY_AGAIN      0x7779
#define LINKCMD_COUNTDOWN               0x7FFF
#define LINKCMD_CONT_BLOCK              0x8888
#define LINKCMD_BLENDER_NO_BERRIES      0x9999
#define LINKCMD_BLENDER_NO_PBLOCK_SPACE 0xAAAA
#define LINKCMD_SEND_ITEM               0xAAAB
#define LINKCMD_READY_TO_TRADE          0xAABB
#define LINKCMD_READY_FINISH_TRADE      0xABCD
#define LINKCMD_INIT_BLOCK              0xBBBB
#define LINKCMD_READY_CANCEL_TRADE      0xBBCC
#define LINKCMD_SEND_HELD_KEYS          0xCAFE
#define LINKCMD_SEND_BLOCK_REQ          0xCCCC
#define LINKCMD_START_TRADE             0xCCDD
#define LINKCMD_CONFIRM_FINISH_TRADE    0xDCBA
#define LINKCMD_SET_MONS_TO_TRADE       0xDDDD
#define LINKCMD_PLAYER_CANCEL_TRADE     0xDDEE
#define LINKCMD_REQUEST_CANCEL          0xEEAA
#define LINKCMD_BOTH_CANCEL_TRADE       0xEEBB
#define LINKCMD_PARTNER_CANCEL_TRADE    0xEECC
#define LINKCMD_NONE                    0xEFFF

#define LINKTYPE_TRADE                 0x1111
#define LINKTYPE_TRADE_CONNECTING      0x1122
#define LINKTYPE_TRADE_SETUP           0x1133
#define LINKTYPE_TRADE_DISCONNECTED    0x1144
#define LINKTYPE_BATTLE                0x2211
#define LINKTYPE_UNUSED_BATTLE         0x2222 // Unused, inferred from gap
#define LINKTYPE_SINGLE_BATTLE         0x2233
#define LINKTYPE_DOUBLE_BATTLE         0x2244
#define LINKTYPE_MULTI_BATTLE          0x2255
#define LINKTYPE_BATTLE_TOWER_50       0x2266
#define LINKTYPE_BATTLE_TOWER_OPEN     0x2277
#define LINKTYPE_BATTLE_TOWER          0x2288
#define LINKTYPE_RECORD_MIX_BEFORE     0x3311
#define LINKTYPE_RECORD_MIX_AFTER      0x3322
#define LINKTYPE_BERRY_BLENDER_SETUP   0x4411
#define LINKTYPE_BERRY_BLENDER         0x4422
#define LINKTYPE_MYSTERY_EVENT         0x5501
#define LINKTYPE_UNUSED_EREADER        0x5502 // Unused, inferred from gap
#define LINKTYPE_EREADER               0x5503
#define LINKTYPE_CONTEST_GMODE         0x6601
#define LINKTYPE_CONTEST_EMODE         0x6602

struct LinkStatus
{
    u32 localId:2;
    u32 playerCount:3;
    u32 master:1;
    u32 connEstablished:1;
    u32 unused_7:1;
    u32 receivedNothing:1;
    u32 unused_9:7;
    u32 errors:7;
};

#define MASTER_HANDSHAKE 0x8FFF
#define SLAVE_HANDSHAKE  0xB9A0

#define SIO_MULTI_CNT ((struct SioMultiCnt *)REG_ADDR_SIOCNT)

enum
{
    LINK_STATE_START0,
    LINK_STATE_START1,
    LINK_STATE_HANDSHAKE,
    LINK_STATE_INIT_TIMER,
    LINK_STATE_CONN_ESTABLISHED,
};

enum
{
    EXCHANGE_NOT_STARTED,
    EXCHANGE_COMPLETE,
    EXCHANGE_TIMED_OUT,
    EXCHANGE_DIFF_SELECTIONS,
    EXCHANGE_PLAYER_NOT_READY,
    EXCHANGE_PARTNER_NOT_READY,
    EXCHANGE_WRONG_NUM_PLAYERS,
    EXCHANGE_STAT_7
};

enum
{
    QUEUE_FULL_NONE,
    QUEUE_FULL_SEND,
    QUEUE_FULL_RECV,
};

enum
{
    LAG_NONE,
    LAG_MASTER,
    LAG_SLAVE,
};

struct LinkPlayer
{
    /* 0x00 */ u16 version;
    /* 0x02 */ u16 lp_field_2;
    /* 0x04 */ u32 trainerId;
    /* 0x08 */ u8 name[PLAYER_NAME_LENGTH + 1];
    /* 0x10 */ u8 progressFlags; // (& 0x0F) is hasNationalDex, (& 0xF0) is hasClearedGame
    /* 0x11 */ u8 neverRead;
    /* 0x12 */ u8 progressFlagsCopy;
    /* 0x13 */ u8 gender;
    /* 0x14 */ u32 linkType;
    /* 0x18 */ u16 id; // battler id in battles
    /* 0x1A */ u16 language;
};

struct LinkPlayerBlock
{
    char magic1[16];
    struct LinkPlayer linkPlayer;
    char magic2[16];
};

// circular queues

struct SendQueue
{
    /* 0x000 */ u16 data[CMD_LENGTH][QUEUE_CAPACITY];
    /* 0x320 */ u8 pos;
    /* 0x321 */ u8 count;
};

struct RecvQueue
{
    u16 data[MAX_LINK_PLAYERS][CMD_LENGTH][QUEUE_CAPACITY];
    u8 pos;
    u8 count;
};

struct Link
{
    /* 0x000 */ u8 isMaster; // 0: slave, 8: master
    /* 0x001 */ u8 state;
    /* 0x002 */ u8 localId; // local multi-player ID
    /* 0x003 */ u8 playerCount;
    /* 0x004 */ u16 tempRecvBuffer[4];
    /* 0x00c */ bool8 receivedNothing;
    /* 0x00d */ s8 serialIntrCounter;
    /* 0x00e */ bool8 handshakeAsMaster;
    /* 0x00f */ u8 link_field_F;

    // error conditions
    /* 0x010 */ bool8 hardwareError; // hardware reported an error
    /* 0x011 */ bool8 badChecksum; // checksum didn't match between devices
    /* 0x012 */ u8 queueFull; // send or recv queue out of space
    /* 0x013 */ u8 lag; // connection is lagging

    /* 0x014 */ u16 checksum;

    /* 0x016 */ u8 sendCmdIndex;
    /* 0x017 */ u8 recvCmdIndex;

    /* 0x018 */ struct SendQueue sendQueue;
    /* 0x33c */ struct RecvQueue recvQueue;
};

struct BlockRequest
{
    void * address;
    u32 size;
};

extern const struct BlockRequest sBlockRequestLookupTable[5];

extern struct Link gLink;
extern u16 gRecvCmds[MAX_RFU_PLAYERS][CMD_LENGTH];
extern u8 gBlockSendBuffer[BLOCK_BUFFER_SIZE];
extern u16 gLinkType;
extern u32 gLinkStatus;
extern u16 gBlockRecvBuffer[MAX_RFU_PLAYERS][BLOCK_BUFFER_SIZE / 2];
extern u16 gSendCmd[CMD_LENGTH];
extern struct LinkPlayer gLinkPlayers[5];
extern u16 word_3002910[];
extern bool8 gReceivedRemoteLinkPlayers;
extern u32 gBerryBlenderKeySendAttempts;
extern bool8 gLinkVSyncDisabled;
extern u32 gLinkStatus;


bool8 IsWirelessAdapterConnected(void);
void Task_DestroySelf(u8 taskId);
void OpenLink(void);
void CloseLink(void);
u16 LinkMain2(const u16 *);
void sub_8007B14(void);
bool32 sub_8007B24(void);
void ClearLinkCallback(void);
void ClearLinkCallback_2(void);
u8 GetLinkPlayerCount(void);
void OpenLinkTimed(void);
u8 GetLinkPlayerDataExchangeStatusTimed(int lower, int upper);
bool8 IsLinkPlayerDataExchangeComplete(void);
u32 GetLinkPlayerTrainerId(u8);
void ResetLinkPlayers(void);
void sub_8007E24(void);
void sub_8007E4C(void);
u8 GetMultiplayerId(void);
u8 bitmask_all_link_players_but_self(void);
bool8 SendBlock(u8, const void *, u16);
u8 GetBlockReceivedStatus(void);
void ResetBlockReceivedFlags(void);
void ResetBlockReceivedFlag(u8);
u8 GetLinkPlayerCount_2(void);
bool8 IsLinkMaster(void);
void CB2_LinkError(void);
u8 GetSioMultiSI(void);
bool8 IsLinkConnectionEstablished(void);
bool8 HasLinkErrorOccurred(void);
void ResetSerial(void);
u32 LinkMain1(u8 *shouldAdvanceLinkState, u16 *sendCmd, u16 (*recvCmds)[CMD_LENGTH]);
void LinkVSync(void);
void Timer3Intr(void);
void SerialCB(void);
bool32 InUnionRoom(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);
bool8 IsLinkTaskFinished(void);
void CreateWirelessStatusIndicatorSprite(u8, u8);
void SetLinkStandbyCallback(void);
void SetWirelessCommType1(void);
void CheckShouldAdvanceLinkState(void);
u8 IsLinkMaster(void);
void SetCloseLinkCallback(void);
bool8 HandleLinkConnection(void);
void SetLinkDebugValues(u32 seed, u32 flags);
void SetBerryBlenderLinkCallback(void);
void SetSuppressLinkErrorMessage(bool8 flag);
void ConvertLinkPlayerName(struct LinkPlayer *linkPlayer);
u8 GetSioMultiSI(void);
void ClearSavedLinkPlayers(void);
void BufferLinkErrorInfo(u32 status, u8 lastSendQueueCount, u8 lastRecvQueueCount, bool8 disconnected);
void LocalLinkPlayerToBlock(void);
void LinkPlayerFromBlock(u32 who);
bool32 Link_AnyPartnersPlayingFRLG_JP(void);
void ResetLinkPlayerCount(void);
void SaveLinkPlayers(u8 a0);
void SetWirelessCommType0(void);
bool32 IsLinkRecvQueueLengthAtLeast3(void);

extern u16 gLinkPartnersHeldKeys[6];
extern u32 gLinkDebugSeed;
extern struct LinkPlayerBlock gLocalLinkPlayerBlock;
extern bool8 gLinkErrorOccurred;
extern u32 gLinkDebugFlags;
extern bool8 gRemoteLinkPlayersNotReceived[MAX_LINK_PLAYERS];
extern u8 gBlockReceivedStatus[MAX_LINK_PLAYERS];
extern u16 gLinkHeldKeys;
extern u32 gLinkStatus;
extern u8 gUnknown_030030E4;
extern u8 gUnknown_030030E8;
extern bool8 gReadyToExitStandby[MAX_LINK_PLAYERS];
extern bool8 gReadyToCloseLink[MAX_LINK_PLAYERS];
extern u16 gReadyCloseLinkType;
extern u8 gSuppressLinkErrorMessage;
extern u8 gWirelessCommType;
extern bool8 gSavedLinkPlayerCount;
extern u8 gSavedMultiplayerId;
extern struct LinkTestBGInfo gLinkTestBGInfo;
extern void (*gLinkCallback)(void);
extern u8 gShouldAdvanceLinkState;
extern u16 gLinkTestBlockChecksums[MAX_LINK_PLAYERS];
extern u8 gBlockRequestType;
extern u8 gLastSendQueueCount;
extern u8 gLastRecvQueueCount;
extern u16 gLinkSavedIme;
extern u32 gFiller_03003074;
extern u32 gFiller_03003154;
extern u32 gFiller_03003158;
extern u32 gFiller_0300315c;
extern u32 gFiller_03004138;
extern u32 gFiller_0300413C;
extern u32 gFiller_03003080;
extern struct LinkPlayer gLocalLinkPlayer;

bool32 Link_AnyPartnersPlayingRubyOrSapphire(void);
bool32 LinkDummy_Return2(void);
void SetLocalLinkPlayerId(u8);
u8 GetSavedPlayerCount(void);
void sub_8009FAC(void);
bool8 SendBlockRequest(u8 type);
u8 GetLinkPlayerCountAsBitFlags(void);
u8 sub_800A0C8(s32, s32);
u8 GetSavedLinkPlayerCountAsBitFlags(void);
void SetCloseLinkCallbackHandleJP(void);
void CheckLinkPlayersMatchSaved(void);
void StartSendingKeysToLink(void);
bool8 DoesLinkPlayerCountMatchSaved(void);
void SetCloseLinkCallbackAndType(u16 type);
bool32 IsSendingKeysToLink(void);
u32 GetLinkRecvQueueLength(void);

#endif // GUARD_LINK_H
