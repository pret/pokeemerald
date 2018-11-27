#ifndef GUARD_BATTLE_PYRAMID_H
#define GUARD_BATTLE_PYRAMID_H

void CallBattlePyramidFunction(void);
u16 LocalIdToPyramidTrainerId(u8 localId);
bool8 GetBattlePyramidTrainerFlag(u8 eventId);
void sub_81A9B04(void);
void GenerateBattlePyramidWildMon(void);
u8 GetPyramidRunMultiplier(void);
u8 InBattlePyramid(void);
bool8 InBattlePyramid_(void);
void sub_81A9E90(void);
void sub_81A9EC8(void);
void CopyPyramidTrainerSpeechBefore(u16 trainerId);
void CopyPyramidTrainerWinSpeech(u16 trainerId);
void CopyPyramidTrainerLoseSpeech(u16 trainerId);
u8 GetTrainerEncounterMusicIdInBattlePyramind(u16 trainerId);
void sub_81AA078(u16 *mapArg, u8 arg1);
void sub_81AA1D8(void);
void sub_81AA2F8(void);
u8 sub_81AAA40(void);
u16 GetBattlePyramidPickupItemId(void);

#endif // GUARD_BATTLE_PYRAMID_H
