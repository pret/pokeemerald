#ifndef GUARD_TRAINER_HILL_H
#define GUARD_TRAINER_HILL_H

extern u32 *gTrainerHillVBlankCounter;

void CallTrainerHillFunction(void);
void ResetTrainerHillResults(void);
u8 GetTrainerHillOpponentClass(u16 trainerId);
void GetTrainerHillTrainerName(u8 *dst, u16 trainerId);
u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId);
void InitTrainerHillBattleStruct(void);
void FreeTrainerHillBattleStruct(void);
void CopyTrainerHillTrainerText(u8 which, u16 trainerId);
bool8 sub_81D5C18(void);
void nullsub_129(void);
void PrintOnTrainerHillRecordsWindow(void);
void sub_81D5DF8(void);
bool32 sub_81D5F48(void);
void sub_81D5FB4(u16 *mapArg);
bool32 InTrainerHill(void);
u8 GetCurrentTrainerHillMapId(void);
const struct WarpEvent* sub_81D6120(void);
const struct WarpEvent* sub_81D6134(u8 warpEventId);
u16 LocalIdToHillTrainerId(u8 localId);
bool8 GetHillTrainerFlag(u8 eventObjectId);
void SetHillTrainerFlag(void);
const u8 *sub_81D62AC(void);
void FillHillTrainerParty(void);
void FillHillTrainersParties(void);
u32 sub_81D63C4(void);
u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId);
u8 sub_81D6490(void);
void sub_81D64C0(void);
bool32 sub_81D6534(void);

#endif // GUARD_TRAINER_HILL_H
