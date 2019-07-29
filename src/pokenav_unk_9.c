#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "window.h"

u32 sub_81CFB8C(void);
u32 sub_81CFC2C(void);
u32 sub_81CFC40(void);
u32 sub_81CFFFC(s32);
u32 sub_81D0074(s32);
u32 sub_81D00EC(s32);
u32 sub_81D0164(s32);
u32 sub_81D01DC(s32);
u32 sub_81D021C(s32);

u32 (*const gUnknown_086235D8[])(void) = 
{
    sub_81CFB8C,
    sub_81CFC2C,
    sub_81CFC40
};

const u16 gUnknown_086235E4[] = INCBIN_U16("graphics/pokenav/ui_ribbons.gbapal");
const u32 gUnknown_08623604[] = INCBIN_U32("graphics/pokenav/ui_ribbons.4bpp.lz");
const u32 gUnknown_086236CC[] = INCBIN_U32("graphics/pokenav/ui_ribbons.bin.lz");
const u16 gUnknown_08623790[] = INCBIN_U16("graphics/pokenav/8623790.gbapal");

const struct BgTemplate gUnknown_086237B0 = 
{
    .bg = 1,
    .charBaseIndex = 1,
    .mapBaseIndex = 0x06,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 2,
    .baseTile = 0
};

const struct BgTemplate gUnknown_086237B4 = 
{
    .bg = 2,
    .charBaseIndex = 2,
    .mapBaseIndex = 0x07,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 3,
    .baseTile = 0
};

const LoopedTask gUnknown_086237B8[] = 
{
    NULL,
    sub_81CFFFC,
    sub_81D0074,
    sub_81D00EC,
    sub_81D0164,
    sub_81D01DC,
    sub_81D021C
};

const struct WindowTemplate gUnknown_086237D4 = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

const u8 gUnknown_086237DC[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086237E8[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086237F4[] = _("{UNK_SPACER}");
