#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

#include "global.h"

void ResetPokedex(void);
void CopyMonCategoryText(u32 species, u8 *dst);
u16 GetPokedexHeightWeight(u16 dexNum, u8 data);
u16 GetNationalPokedexCount(u8);
u16 GetHoennPokedexCount(u8);
u8 CreateDexDisplayMonDataTask(u16 dexNum, u32 trainerId, u32 personality);

enum
{
    FLAG_GET_SEEN,
    FLAG_GET_CAUGHT,
    FLAG_SET_SEEN,
    FLAG_SET_CAUGHT
};

s8 GetSetPokedexFlag(u16 nationalNum, u8 caseId);
u16 sub_80C0E9C(u16, s16, s16, u16);

#endif // GUARD_POKEDEX_H
