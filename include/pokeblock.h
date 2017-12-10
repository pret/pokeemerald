#ifndef GUARD_POKEBLOCK_H
#define GUARD_POKEBLOCK_H

#define TAG_POKEBLOCK_GFX 0x39E2

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

// use pokeblock
extern u8 gPokeblockMonId;
extern s16 gPokeblockGain;

void ChooseMonToGivePokeblock(struct Pokeblock *pokeblock, void (*callback)(void));

// pokeblock feed
void CB2_PreparePokeblockFeedScene(void);

// pokeblock
u8 CreatePokeblockCaseSprite(s16 x, s16 y, u8 subpriority);
u8 GetPokeblockData(const struct Pokeblock *pokeblock, u8 dataId);
void ClearPokeblocks(void);
s8 GetFirstFreePokeblockSlot(void);
bool32 AddPokeblock(struct Pokeblock *pokeblock);
u8 GetHighestPokeblocksFlavorLevel(const struct Pokeblock *pokeblock);
u8 GetPokeblocksFeel(const struct Pokeblock *pokeblock);
u8 GetPokeblocksFlavor(const struct Pokeblock *pokeblock);
s16 PokeblockGetGain(u8, const struct Pokeblock *pokeblock);
void PokeblockCopyName(const struct Pokeblock *pokeblock, u8 *dst);

#endif // GUARD_POKEBLOCK_H
