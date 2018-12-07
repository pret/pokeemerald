#ifndef GUARD_FRONTIER_UTIL_H
#define GUARD_FRONTIER_UTIL_H

#define FRONTIER_BEFORE_TEXT 0
#define FRONTIER_PLAYER_LOST_TEXT 1
#define FRONTIER_PLAYER_WON_TEXT 2

void CallFrontierUtilFunc(void);
u8 sub_81A3610(void);
void CopyFrontierTrainerText(u8 whichText, u16 trainerId);
void sub_81A3908(void);
u32 GetCurrentFacilityWinStreak(void);
void sub_81A3ACC(void);
u8 GetPlayerSymbolCountForFacility(u8 facility);
void ShowRankingHallRecordsWindow(void);
void ScrollRankingHallRecordsWindow(void);
void ClearRankingHallRecords(void);
void sub_81A4C30(void);
u8 GetFrontierBrainTrainerPicIndex(void);
u8 GetFrontierBrainTrainerClass(void);
void CopyFrontierBrainTrainerName(u8 *dst);
bool8 IsFrontierBrainFemale(void);
void SetFrontierBrainEventObjGfx_2(void);
void CreateFrontierBrainPokemon(void);
u16 GetFrontierBrainMonSpecies(u8 monId);
void SetFrontierBrainEventObjGfx(u8 facility);
u16 GetFrontierBrainMonMove(u8 monId, u8 moveSlotId);
u8 GetFrontierBrainMonNature(u8 monId);
u8 GetFrontierBrainMonEvs(u8 monId, u8 evStatId);
s32 GetFronterBrainSymbol(void);

extern const u16 gFrontierBannedSpecies[];

#endif // GUARD_FRONTIER_UTIL_H
