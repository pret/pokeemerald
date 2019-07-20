#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "window.h"

u32 sub_81CF134(void);
u32 sub_81CF1C4(void);
u32 sub_81CF1D8(void);
u32 sub_81CF278(void);
u32 sub_81CF578(s32);
u32 sub_81CF5F0(s32);
u32 sub_81CF668(s32);
u32 sub_81CF6E0(s32);
u32 sub_81CF758(s32);
u32 sub_81CF798(s32);

const u32 gUnknown_086233A0[] = {0x16, 0x17, 0x18, 0x21, 0x2F};

u32 (*const gUnknown_086233B4[])(void) = 
{
    sub_81CF134,
    sub_81CF1C4,
    sub_81CF1D8,
    sub_81CF278
};

const u16 gUnknown_086233C4[] = INCBIN_U16("graphics/pokenav/condition_search2.gbapal");
const u32 gUnknown_086233E4[] = INCBIN_U32("graphics/pokenav/condition_search2.4bpp.lz");
const u32 gUnknown_086234AC[] = INCBIN_U32("graphics/pokenav/condition_search2.bin.lz");
const u16 gUnknown_08623570[] = INCBIN_U16("graphics/pokenav/8623570.gbapal");

const struct BgTemplate gUnknown_08623590 = 
{
    .bg = 1,
    .charBaseIndex = 1,
    .mapBaseIndex = 0x06,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 2,
    .baseTile = 0
};

const struct BgTemplate gUnknown_08623594 = 
{
    .bg = 2,
    .charBaseIndex = 2,
    .mapBaseIndex = 0x07,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 3,
    .baseTile = 0
};

const LoopedTask gUnknown_08623598[] = 
{
    NULL,
    sub_81CF578,
    sub_81CF5F0,
    sub_81CF668,
    sub_81CF6E0,
    sub_81CF758,
    sub_81CF798
};

const struct WindowTemplate gUnknown_086235B4 = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

const u8 gUnknown_086235BC[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086235C8[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086235D4[] = _("{UNK_SPACER}");
