
// Includes
#include "global.h"

// Static type declarations

struct BlockTransfer
{
    u16 pos;
    u16 size;
    void *src;
    bool8 active;
    u8 multiplayerId;
};

struct LinkTestBGInfo
{
    u32 screenBaseBlock;
    u32 paletteNum;
    u32 dummy_8;
    u32 dummy_C;
};

// Static RAM declarations

IWRAM_DATA struct BlockTransfer gUnknown_03000D10;
IWRAM_DATA u32 link_c_unused_03000d1c;
IWRAM_DATA struct BlockTransfer gUnknown_03000D20[4];
IWRAM_DATA u32 gUnknown_03000D50;
IWRAM_DATA u32 gUnknown_03000D54;
IWRAM_DATA u8 gUnknown_03000D58;
IWRAM_DATA u32 gUnknown_03000D5C;
IWRAM_DATA u32 gUnknown_03000D60;
IWRAM_DATA u8 gUnknown_03000D64[4]; // not really, but won't match otherwise
IWRAM_DATA u8 gUnknown_03000D68[4];
IWRAM_DATA u8 gUnknown_03000D6C;
IWRAM_DATA bool8 gUnknown_03000D6D;
IWRAM_DATA u16 gUnknown_03000D6E;
IWRAM_DATA u16 gUnknown_03000D70;
IWRAM_DATA u8 gUnknown_03000D72;
IWRAM_DATA u8 gUnknown_03000D73;
IWRAM_DATA u8 gUnknown_03000D74[4]; // not really, but won't match otherwise
IWRAM_DATA u8 gUnknown_03000D78[8]; // not really, but won't match otherwise
IWRAM_DATA u8 gUnknown_03000D80[16];
IWRAM_DATA u16 gUnknown_03000D90[8];
IWRAM_DATA u32 gUnknown_03000DA0;
IWRAM_DATA u32 gUnknown_03000DA4;
IWRAM_DATA void *gUnknown_03000DA8;
IWRAM_DATA void *gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

// Static ROM declarations

// .rodata

// .text
