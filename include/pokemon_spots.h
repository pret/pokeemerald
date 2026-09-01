#ifndef GUARD_POKEMON_SPOTS_H
#define GUARD_POKEMON_SPOTS_H


bool32 ShouldDrawSpotsOnSpecies(enum Species species);
void DrawPokemonSpotsBothFrames(u32 personality, enum Species species, u8 *dest);

#endif /* end of include guard: GUARD_POKEMON_SPOTS_H */
