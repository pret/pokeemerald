#ifndef GUARD_RECORDED_BATTLE_H
#define GUARD_RECORDED_BATTLE_H

#include "constants/battle.h"
#include "link.h"
#include "random.h"

#define BATTLER_RECORD_SIZE 388

struct RecordedBattleSave
{
    struct Pokemon parties[MAX_BATTLE_TRAINERS][PARTY_SIZE];
    u8 playersName[MAX_LINK_PLAYERS][PLAYER_NAME_LENGTH + 1];
    u32 playersTrainerId[MAX_LINK_PLAYERS];
    u8 playersLanguage[MAX_LINK_PLAYERS];
    rng_value_t rngSeed;
    u32 battleFlags;
    u16 opponentA;
    u16 opponentB;
    u16 partnerId;
    u16 frontierFacility:4; // 7 Frontier facilities + Union Room + E-reader
    u16 frontierBrainSymbol:1;
    u16 lvlMode:2;
    u16 battleScene:1;
    u16 textSpeed:3;
    u16 playersGender:4; // 1 bit per player; please don't hate me
    u16 padding:1;
    u64 AI_scripts[MAX_BATTLERS_COUNT];
    u8 recordMixFriendName[PLAYER_NAME_LENGTH + 1];
    u8 recordMixFriendClass;
    u8 apprenticeId;
    u8 recordMixFriendLanguage:3; // 7 languages
    u8 apprenticeLanguage:3;
    u8 multiplayerId:2;
    u8 playersBattlers; // Setup so player 2/3 battler and player 0/1 second battler occupy same bits
    u16 easyChatSpeech[EASY_CHAT_BATTLE_WORDS_COUNT];
    u8 battleRecord[MAX_BATTLERS_COUNT][BATTLER_RECORD_SIZE];
    u32 checksum;
};

enum
{
    RECORDED_BYTE, // Generic.
    RECORDED_ACTION_TYPE,
    RECORDED_MOVE_SLOT,
    RECORDED_MOVE_TARGET,
    RECORDED_PARTY_INDEX,
    RECORDED_BATTLE_PALACE_ACTION,
    RECORDED_ITEM_ID,
    RECORDED_ITEM_TARGET,
    RECORDED_ITEM_MOVE,
};

#define RECORDED_TARGET_DEFAULT 0xF

extern rng_value_t gRecordedBattleRngSeed;
extern rng_value_t gBattlePalaceMoveSelectionRngValue;
extern u8 gRecordedBattleMultiplayerId;

#define B_RECORD_MODE_RECORDING 1
#define B_RECORD_MODE_PLAYBACK 2

void RecordedBattle_Init(u8 mode);
void RecordedBattle_SetTrainerInfo(void);
void RecordedBattle_SetBattlerAction(enum BattlerId battler, u8 action);
void RecordedBattle_ClearBattlerAction(enum BattlerId battler, u8 bytesToClear);
u8 RecordedBattle_GetBattlerAction(u32 actionType, enum BattlerId battler);
u8 RecordedBattle_BufferNewBattlerData(u8 *dst);
void RecordedBattle_RecordAllBattlerData(u8 *src);
bool32 CanCopyRecordedBattleSaveData(void);
bool32 MoveRecordedBattleToSaveData(void);
void SetPartiesFromRecordedSave(struct RecordedBattleSave *src);
void SetVariablesForRecordedBattle(struct RecordedBattleSave *);
void PlayRecordedBattle(void (*CB2_After)(void));
u8 GetRecordedBattleFrontierFacility(void);
u8 GetRecordedBattleFronterBrainSymbol(void);
void RecordedBattle_SaveParties(void);
u8 GetBattlerLinkPlayerGender(enum BattlerId battler);
void RecordedBattle_ClearFrontierPassFlag(void);
void RecordedBattle_SetFrontierPassFlagFromHword(u16 flags);
u8 RecordedBattle_GetFrontierPassFlag(void);
u8 GetBattleSceneInRecordedBattle(void);
u8 GetTextSpeedInRecordedBattle(void);
void RecordedBattle_CopyBattlerMoves(enum BattlerId battler);
void RecordedBattle_CheckMovesetChanges(u8 mode);
u64 GetAiScriptsInRecordedBattle(enum BattlerId battler);
void RecordedBattle_SetPlaybackFinished(void);
bool8 RecordedBattle_CanStopPlayback(void);
void GetRecordedBattleRecordMixFriendName(u8 *dst);
u8 GetRecordedBattleRecordMixFriendClass(void);
u8 GetRecordedBattleApprenticeId(void);
u8 GetRecordedBattleRecordMixFriendLanguage(void);
u8 GetRecordedBattleApprenticeLanguage(void);
void RecordedBattle_SaveBattleOutcome(void);
u16 *GetRecordedBattleEasyChatSpeech(void);

#endif // GUARD_RECORDED_BATTLE_H
