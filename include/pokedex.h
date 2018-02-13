#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

void ResetPokedex(void);
void CopyMonCategoryText(u16 species, u8 *dst);
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
u16 GetNationalPokedexCount(u8);
u16 GetHoennPokedexCount(u8);

#endif // GUARD_POKEDEX_H
