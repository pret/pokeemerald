#ifndef GUARD_RECORDED_BATTLE_H
#define GUARD_RECORDED_BATTLE_H

extern u32 gRecordedBattleRngSeed;
extern u32 gBattlePalaceMoveSelectionRngValue;
extern u8 gRecordedBattleMultiplayerId;

#define B_RECORD_MODE_RECORDING 1
#define B_RECORD_MODE_PLAYBACK 2

void RecordedBattle_Init(u8 mode);
void RecordedBattle_SetTrainerInfo(void);
void RecordedBattle_SetBattlerAction(u8 battlerId, u8 action);
void RecordedBattle_ClearBattlerAction(u8 battlerId, u8 bytesToClear);
u8 RecordedBattle_GetBattlerAction(u8 battlerId);
u8 RecordedBattle_BufferNewBattlerData(u8 *dst);
void RecordedBattle_RecordAllBattlerData(u8 *data);
bool32 CanCopyRecordedBattleSaveData(void);
bool32 MoveRecordedBattleToSaveData(void);
void PlayRecordedBattle(void (*CB2_After)(void));
u8 GetRecordedBattleFrontierFacility(void);
u8 GetRecordedBattleFronterBrainSymbol(void);
void RecordedBattle_SaveParties(void);
u8 GetActiveBattlerLinkPlayerGender(void);
void RecordedBattle_ClearFrontierPassFlag(void);
void RecordedBattle_SetFrontierPassFlagFromHword(u16 flags);
u8 RecordedBattle_GetFrontierPassFlag(void);
u8 GetBattleSceneInRecordedBattle(void);
u8 GetTextSpeedInRecordedBattle(void);
void RecordedBattle_CopyBattlerMoves(void);
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
