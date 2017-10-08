#ifndef GUARD_TV_H
#define GUARD_TV_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void ClearTVShowData(void);
void PutPokemonTodayCaughtOnAir(void);
u32 GetPlayerIDAsU32(void);
bool8 GetPriceReduction(u8);
u8 sub_80EE5A4(struct Pokemon *);
void sub_80EE184(void);
void sub_80F14F8(TVShow *);

#endif //GUARD_TV_H
