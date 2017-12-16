#ifndef GUARD_ROM6_H
#define GUARD_ROM6_H

void sub_81357FC(u8, void(void));
u8 GetLeadMonIndex(void);
u8 GetSSTidalLocation(u8 *grp, u8 *num, s16 *x, s16 *y);
void sub_813BADC(bool8);
bool8 sub_813B9C0(void);
void UpdateMirageRnd(u16 days);
void UpdateBirchState(u16 days);
void UpdateFrontierManiac(u16 days);
void UpdateFrontierGambler(u16 days);
void SetShoalItemFlag(u16 days);

#endif //GUARD_ROM6_H
