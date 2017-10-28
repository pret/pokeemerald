
// Includes
#include "global.h"
#include "easy_chat.h"

// Static type declarations

// Static RAM declarations

struct UnkStruct_817C7F4 {
    u8 unk_00[48];
};

// Static ROM declarations

// .rodata

extern const struct UnkStruct_817C7F4 gUnknown_085F5494[];
extern const struct UnkStruct_817C7F4 gUnknown_085FA1D8[];
extern const struct UnkStruct_817C7F4 *const gUnknown_0860A168[];
extern const s16 *const gUnknown_0860A320[];
extern const struct UnkStruct_817C7F4 gUnknown_0860A3AC;

// .text

s16 sub_817C7DC(int x, int y)
{
    return gUnknown_0860A320[x][y];
}

const struct UnkStruct_817C7F4 *sub_817C7F4(u16 word)
{
    u32 category;
    u32 subword;
    const struct UnkStruct_817C7F4 *ptr;

    if (sub_811EB10(word))
    {
        return &gUnknown_0860A3AC;
    }
    category = word >> 9;
    subword = word & 0x1ff;
    switch (category)
    {
        case EC_GROUP_POKEMON:
        case EC_GROUP_POKEMON_2:
            ptr = gUnknown_085F5494;
            break;
        case EC_GROUP_MOVE_1:
        case EC_GROUP_MOVE_2:
            ptr = gUnknown_085FA1D8;
            break;
        default:
            ptr = gUnknown_0860A168[category];
            break;
    }
    ptr += subword;
    return ptr;
}


