#ifndef GUARD_NEW_GAME_H
#define GUARD_NEW_GAME_H

void WriteUnalignedWord(u32 var, u8 *dataPtr);
u32 ReadUnalignedWord(u8* dataPtr);
void CopyUnalignedWord(u8 *copyTo, u8 *copyFrom);
void NewGameInitData(void);
void sub_808447C(void);
void Sav2_ClearSetDefault(void);

#endif // GUARD_NEW_GAME_H
