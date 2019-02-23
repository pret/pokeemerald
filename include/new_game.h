#ifndef GUARD_NEW_GAME_H
#define GUARD_NEW_GAME_H

extern bool8 gDifferentSaveFile;
extern bool8 gUnknown_020322D5; // The purpose of this variable is unknown as it's read only 3 times(2 times in contest.c and 1 time in berry_blender.c), never written to.

void SetTrainerId(u32 trainerId, u8 *dst);
u32 GetTrainerId(u8 *trainerId);
void CopyTrainerId(u8 *dst, u8 *src);
void NewGameInitData(void);
void ResetMenuAndMonGlobals(void);
void Sav2_ClearSetDefault(void);

#endif // GUARD_NEW_GAME_H
