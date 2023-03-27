#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);


void CB2_OpenPokedexPlusHGSS(void);
u16 NationalPokedexNumToSpeciesHGSS(u16 nationalNum);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
