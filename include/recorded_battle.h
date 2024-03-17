#ifndef GUARD_RECORDED_BATTLE_H
#define GUARD_RECORDED_BATTLE_H

#include "constants/battle.h"
#include "random.h"

#define BATTLER_RECORD_SIZE 664

struct RecordedBattleSave
{
    struct Pokemon playerParty[PARTY_SIZE];
    struct Pokemon opponentParty[PARTY_SIZE];
    u8 playersName[MAX_BATTLERS_COUNT][PLAYER_NAME_LENGTH + 1];
    u8 playersGender[MAX_BATTLERS_COUNT];
    u32 playersTrainerId[MAX_BATTLERS_COUNT];
    u8 playersLanguage[MAX_BATTLERS_COUNT];
    rng_value_t rngSeed;
    u32 battleFlags;
    u8 playersBattlers[MAX_BATTLERS_COUNT];
    u16 opponentA;
    u16 opponentB;
    u16 partnerId;
    u16 multiplayerId;
    u8 lvlMode;
    u8 frontierFacility;
    u8 frontierBrainSymbol;
    u8 battleScene:1;
    u8 textSpeed:3;
    u32 AI_scripts;
    u8 recordMixFriendName[PLAYER_NAME_LENGTH + 1];
    u8 recordMixFriendClass;
    u8 apprenticeId;
    u16 easyChatSpeech[EASY_CHAT_BATTLE_WORDS_COUNT];
    u8 recordMixFriendLanguage;
    u8 apprenticeLanguage;
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

extern rng_value_t gRecordedBattleRngSeed;
extern rng_value_t gBattlePalaceMoveSelectionRngValue;
extern u8 gRecordedBattleMultiplayerId;

#define B_RECORD_MODE_RECORDING 1
#define B_RECORD_MODE_PLAYBACK 2

void RecordedBattle_Init(u8 mode);
void RecordedBattle_SetTrainerInfo(void);
void RecordedBattle_SetBattlerAction(u8 battlerId, u8 action);
void RecordedBattle_ClearBattlerAction(u8 battlerId, u8 bytesToClear);
u8 RecordedBattle_GetBattlerAction(u32 actionType, u8 battlerId);
u8 RecordedBattle_BufferNewBattlerData(u8 *dst);
void RecordedBattle_RecordAllBattlerData(u8 *data);
bool32 CanCopyRecordedBattleSaveData(void);
bool32 MoveRecordedBattleToSaveData(void);
void SetPartiesFromRecordedSave(struct RecordedBattleSave *src);
void SetVariablesForRecordedBattle(struct RecordedBattleSave *);
void PlayRecordedBattle(void (*CB2_After)(void));
u8 GetRecordedBattleFrontierFacility(void);
u8 GetRecordedBattleFronterBrainSymbol(void);
void RecordedBattle_SaveParties(void);
u8 GetBattlerLinkPlayerGender(u32 battler);
void RecordedBattle_ClearFrontierPassFlag(void);
void RecordedBattle_SetFrontierPassFlagFromHword(u16 flags);
u8 RecordedBattle_GetFrontierPassFlag(void);
u8 GetBattleSceneInRecordedBattle(void);
u8 GetTextSpeedInRecordedBattle(void);
void RecordedBattle_CopyBattlerMoves(u32 battler);
void RecordedBattle_CheckMovesetChanges(u8 mode);
u32 GetAiScriptsInRecordedBattle(void);
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
