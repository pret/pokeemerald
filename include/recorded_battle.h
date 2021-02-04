#ifndef GUARD_RECORDED_BATTLE_H
#define GUARD_RECORDED_BATTLE_H

extern u32 gRecordedBattleRngSeed;
extern u32 gBattlePalaceMoveSelectionRngValue;
extern u8 gRecordedBattleMultiplayerId;

void sub_8184DA4(u8 arg0);
void sub_8184E58(void);
void RecordedBattle_SetBattlerAction(u8 battlerId, u8 action);
void RecordedBattle_ClearBattlerAction(u8 battlerId, u8 bytesToClear);
u8 RecordedBattle_GetBattlerAction(u8 battlerId);
u8 sub_81850D0(void);
u8 sub_81850DC(u8 *arg0);
void sub_81851A8(u8 *arg0);
bool32 CanCopyRecordedBattleSaveData(void);
bool32 MoveRecordedBattleToSaveData(void);
void PlayRecordedBattle(void (*CB2_After)(void));
u8 GetRecordedBattleFrontierFacility(void);
u8 GetRecordedBattleFronterBrainSymbol(void);
void RecordedBattle_SaveParties(void);
u8 GetActiveBattlerLinkPlayerGender(void);
void sub_8185F84(void);
void sub_8185F90(u16 arg0);
u8 sub_8185FAC(void);
u8 GetBattleSceneInRecordedBattle(void);
u8 GetTextSpeedInRecordedBattle(void);
void RecordedBattle_CopyBattlerMoves(void);
void sub_818603C(u8 arg0);
u32 GetAiScriptsInRecordedBattle(void);
void sub_8186444(void);
bool8 sub_8186450(void);
void GetRecordedBattleRecordMixFriendName(u8 *dst);
u8 GetRecordedBattleRecordMixFriendClass(void);
u8 GetRecordedBattleApprenticeId(void);
u8 GetRecordedBattleRecordMixFriendLanguage(void);
u8 GetRecordedBattleApprenticeLanguage(void);
void RecordedBattle_SaveBattleOutcome(void);
u16 *GetRecordedBattleEasyChatSpeech(void);

#endif // GUARD_RECORDED_BATTLE_H
