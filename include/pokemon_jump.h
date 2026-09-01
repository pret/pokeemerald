#ifndef GUARD_POKEMON_JUMP_H
#define GUARD_POKEMON_JUMP_H

#include "main.h"

void StartPokemonJump(u16 partyId, MainCallback exitCallback);
bool32 IsSpeciesAllowedInPokemonJump(enum Species species);
void IsPokemonJumpSpeciesInParty(void);
void ResetPokemonJumpRecords(void);
void ShowPokemonJumpRecords(void);

#endif // GUARD_POKEMON_JUMP_H
