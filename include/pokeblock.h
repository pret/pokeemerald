#ifndef GUARD_POKEBLOCK_H
#define GUARD_POKEBLOCK_H

enum
{
    PBLOCK_CLR_BLACK,
    PBLOCK_CLR_RED,
    PBLOCK_CLR_BLUE,
    PBLOCK_CLR_PINK,
    PBLOCK_CLR_GREEN,
    PBLOCK_CLR_YELLOW
};

enum
{
    PBLOCK_COLOR,
    PBLOCK_SPICY,
    PBLOCK_DRY,
    PBLOCK_SWEET,
    PBLOCK_BITTER,
    PBLOCK_SOUR,
    PBLOCK_FEEL,
};

void ClearPokeblocks(void);
s16 PokeblockGetGain(u8, const struct Pokeblock *);

/*
void sub_810B96C(void);
u8 sub_810BA50(s16, s16, u8);
u8 sub_810C9B0(struct Pokeblock *);
s16 GetPokeblockData(const struct Pokeblock *, u8);
u8 sub_810C9E8(struct Pokeblock *);
void sub_810BA7C(u8);
bool8 PokeblockClearIfExists(u8);
u8 sub_810CB68(u8, u8*);
void PokeblockCopyName(struct Pokeblock *pokeblock, u8 *dest);
void CB2_PreparePokeblockFeedScene(void);

#include "main.h"

void sub_8136130(struct Pokeblock *, MainCallback);
*/

#endif // GUARD_POKEBLOCK_H
