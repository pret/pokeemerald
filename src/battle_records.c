#include "global.h"
#include "battle_records.h"
#include "bg.h"
#include "window.h"
#include "link.h"
#include "battle.h"
#include "overworld.h"
#include "constants/game_stat.h"

// const rom data
const u32 gUnknown_085B3484[] = INCBIN_U32("graphics/unknown/unknown_5B3484.4bpp");
const u16 gUnknown_085B3544[] = INCBIN_U16("graphics/unknown/unknown_5B3484.gbapal");
const u32 gUnknown_085B3564[] = INCBIN_U32("graphics/unknown/unknown_5B3564.bin");

const struct BgTemplate gUnknown_085B3D64[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct WindowTemplate gUnknown_085B3D6C[] =
{
    {0x0, 0x2, 0x1, 0x1A, 0x12, 0xF, 0x14},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_085B3D7C = {0x0, 0x2, 0x1, 0x1A, 0x11, 0xF, 0x1};

const u8 gUnknown_085B3D84[] = _("-------");
const u8 gUnknown_085B3D8C[] = _("----");

// code
