#ifndef GUARD_TV_H
#define GUARD_TV_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void ClearTVShowData(void);
void PutPokemonTodayCaughtOnAir(void);
u32 GetPlayerIDAsU32(void);
bool8 GetPriceReduction(u8 newsKind);
u8 GetRibbonCount(struct Pokemon *pokemon);
void sub_80EE184(void);
void sub_80F14F8(TVShow *shows);
int sub_80EF370(int value);

#endif //GUARD_TV_H
