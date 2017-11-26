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
s8 GetFirstFreePokeblockSlot(void);
bool32 AddPokeblock(struct Pokeblock *pokeblock);
u8 GetHighestPokeblocksFlavourLevel(const struct Pokeblock *pokeblock);
u8 GetPokeblocksFeel(const struct Pokeblock *pokeblock);
u8 GetPokeblocksFlavour(const struct Pokeblock *pokeblock);
s16 PokeblockGetGain(u8, const struct Pokeblock *);

#endif // GUARD_POKEBLOCK_H
