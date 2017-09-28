#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

void ClearRoamerData(void);
void ClearRoamerLocationData(void);
void InitRoamer(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
bool8 IsRoamerAt(u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(void);
u8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(void);
void GetRoamerLocation(u8 *mapGroup, u8 *mapNum);

#endif // GUARD_ROAMER_H
