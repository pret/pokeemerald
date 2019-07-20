#include "global.h"
#include "bg.h"
#include "window.h"
#include "pokenav.h"

u32 sub_81CE37C(s32);
u32 sub_81CE2D0(s32);
u32 sub_81CE4D8(s32);
u32 sub_81CE5E4(s32);
u32 sub_81CE6BC(s32);
u32 sub_81CE700(s32);

BSS_DATA u8 gUnknown_030012BC;

const u16 gUnknown_086231E8[] = INCBIN_U16("graphics/pokenav/86231E8.gbapal");
const u16 gUnknown_08623208[] = INCBIN_U16("graphics/pokenav/8623208.gbapal");
const u32 gUnknown_08623228[] = INCBIN_U32("graphics/pokenav/8623228.4bpp.lz");
const u32 gUnknown_0862323C[] = INCBIN_U32("graphics/pokenav/862323C.bin.lz");
const u16 gUnknown_08623338[] = INCBIN_U16("graphics/pokenav/8623338.gbapal");

const struct BgTemplate gUnknown_08623358[3] = 
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct WindowTemplate gUnknown_08623364 = 
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 1,
    .width = 13,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 2
};

const struct WindowTemplate gUnknown_0862336C = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x36
};

const struct WindowTemplate gUnknown_08623374 = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 0x1C,
    .width = 5,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const struct WindowTemplate gUnknown_0862337C = 
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 0x1C,
    .width = 3,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const LoopedTask gUnknown_08623384[] =
{
    NULL,
    sub_81CE37C,
    sub_81CE2D0,
    sub_81CE4D8,
    sub_81CE5E4,
    sub_81CE6BC,
    sub_81CE700
};
