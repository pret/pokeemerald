#ifndef GUARD_POKEMON_JUMP_H
#define GUARD_POKEMON_JUMP_H

#include "main.h"

void sub_802A9A8(u16 monId, MainCallback callback);
bool32 IsSpeciesAllowedInPokemonJump(u16 species);
void IsPokemonJumpSpeciesInParty(void);
void ResetPokeJumpResults(void);
void ShowPokemonJumpRecords(void);
void sub_802EB24(s16 tileTag, s16 palTag, s16 x, s16 y, u8 subpriority);
bool32 sub_802EB84(void);

#endif // GUARD_POKEMON_JUMP_H
