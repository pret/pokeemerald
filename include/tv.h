#ifndef GUARD_TV_H
#define GUARD_TV_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void ClearTVShowData(void);
void PutPokemonTodayCaughtOnAir(void);
u32 player_id_to_dword(void);
bool8 GetPriceReduction(u8);
u8 sub_80EE5A4(struct Pokemon *);
void sub_80EE184(void);

#endif //GUARD_TV_H
