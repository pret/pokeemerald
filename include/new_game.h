#ifndef GUARD_NEW_GAME_H
#define GUARD_NEW_GAME_H

#include <gba/gba.h>

void SetTrainerId(u32 trainerId, u8 *dst);
u32 GetTrainerId(u8 *trainerId);
void CopyTrainerId(u8 *dst, u8 *src);
void NewGameInitData(void);
void sub_808447C(void);
void Sav2_ClearSetDefault(void);

#endif // GUARD_NEW_GAME_H
