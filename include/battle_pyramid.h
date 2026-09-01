#ifndef GUARD_BATTLE_PYRAMID_H
#define GUARD_BATTLE_PYRAMID_H

#include "constants/battle_pyramid.h"

void CallBattlePyramidFunction(void);
u16 LocalIdToPyramidTrainerId(u8 localId);
bool8 GetBattlePyramidTrainerFlag(u8 eventId);
void MarkApproachingPyramidTrainersAsBattled(void);
void GenerateBattlePyramidWildMon(enum Species forceSpecies);
u8 GetPyramidRunMultiplier(void);
u8 CurrentBattlePyramidLocation(void);
bool8 InBattlePyramid(void);
void PausePyramidChallenge(void);
void SoftResetInBattlePyramid(void);
void CopyPyramidTrainerSpeechBefore(u16 trainerId);
u8 GetTrainerEncounterMusicIdInBattlePyramid(u16 trainerId);
void GenerateBattlePyramidFloorLayout(u16 *backupMapData, bool8 setPlayerPosition);
void LoadBattlePyramidObjectEventTemplates(void);
void LoadBattlePyramidFloorObjectEventScripts(void);
u8 GetNumBattlePyramidObjectEvents(void);
u16 GetBattlePyramidPickupItemId(void);
const u8 *GetBattlePyramidTrainerScript();

#endif // GUARD_BATTLE_PYRAMID_H
