#ifndef GUARD_FIELD_SPECIALS_H
#define GUARD_FIELD_SPECIALS_H

u8 GetLeadMonIndex(void);
u8 sub_813B260(void);
u16 get_unknown_box_id(void);
bool8 InMultiBattleRoom(void);
void sub_813BF10(void);
void IncrementBirthIslandRockStepCount(void);
bool8 UnusualWeatherHasExpired(void);
bool8 ShouldDoBrailleRegicePuzzle(void);
bool32 ShouldDoWallyCall(void);
bool32 ShouldDoWinonaCall(void);
bool32 ShouldDoScottCall(void);
bool32 ShouldDoRoxanneCall(void);
bool32 ShouldDoRivalRayquazaCall(void);
bool32 CountSSTidalStep(u16 delta);
u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y);
void sub_813A128(void);
void sub_813A878(u8 a0);
u8 sub_813BADC(u8 a0);
bool8 sub_813B9C0(void);
void SetShoalItemFlag(u16 v0);
void UpdateFrontierManiac(u16 a0);
void UpdateFrontierGambler(u16 a0);
void ResetCyclingRoadChallengeData(void);
bool8 warp0_in_pokecenter(void);
void ResetFanClub(void);


#endif // GUARD_FIELD_SPECIALS_H
