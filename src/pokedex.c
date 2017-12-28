#include "global.h"
#include "gba/m4a_internal.h"
#include "pokedex.h"
#include "sprite.h"
#include "graphics.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"

// this file's functions
void sub_80BE604(struct Sprite *sprite);
void sub_80BE658(struct Sprite *sprite);
void sub_80BE758(struct Sprite *sprite);
void sub_80BE780(struct Sprite *sprite);
void sub_80BE44C(struct Sprite *sprite);
void sub_80BE834(struct Sprite *sprite);

// const rom data
#include "data/pokedex_orders.h"

static const struct OamData sOamData_855CFE4 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFEC =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFF4 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855CFFC =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 2,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D004 =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_855D00C =
{
    .y = 160,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_855D014[] =
{
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D01C[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D024[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D02C[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D034[] =
{
    ANIMCMD_FRAME(40, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D03C[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D044[] =
{
    ANIMCMD_FRAME(56, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D04C[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D054[] =
{
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D05C[] =
{
    ANIMCMD_FRAME(160, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D064[] =
{
    ANIMCMD_FRAME(168, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D06C[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D074[] =
{
    ANIMCMD_FRAME(130, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D07C[] =
{
    ANIMCMD_FRAME(132, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D084[] =
{
    ANIMCMD_FRAME(134, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D08C[] =
{
    ANIMCMD_FRAME(136, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D094[] =
{
    ANIMCMD_FRAME(138, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D09C[] =
{
    ANIMCMD_FRAME(140, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0A4[] =
{
    ANIMCMD_FRAME(142, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0AC[] =
{
    ANIMCMD_FRAME(144, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0B4[] =
{
    ANIMCMD_FRAME(146, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0BC[] =
{
    ANIMCMD_FRAME(176, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0C4[] =
{
    ANIMCMD_FRAME(178, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0CC[] =
{
    ANIMCMD_FRAME(180, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0D4[] =
{
    ANIMCMD_FRAME(182, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0DC[] =
{
    ANIMCMD_FRAME(184, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0E4[] =
{
    ANIMCMD_FRAME(186, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0EC[] =
{
    ANIMCMD_FRAME(188, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0F4[] =
{
    ANIMCMD_FRAME(190, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D0FC[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D104[] =
{
    ANIMCMD_FRAME(194, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_855D10C[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_855D114[] =
{
    sSpriteAnim_855D014
};

static const union AnimCmd *const sSpriteAnimTable_855D118[] =
{
    sSpriteAnim_855D01C
};

static const union AnimCmd *const sSpriteAnimTable_855D11C[] =
{
    sSpriteAnim_855D024
};

static const union AnimCmd *const sSpriteAnimTable_855D120[] =
{
    sSpriteAnim_855D02C,
    sSpriteAnim_855D034,
    sSpriteAnim_855D03C,
    sSpriteAnim_855D044
};

static const union AnimCmd *const sSpriteAnimTable_855D130[] =
{
    sSpriteAnim_855D04C,
    sSpriteAnim_855D054
};

static const union AnimCmd *const sSpriteAnimTable_855D138[] =
{
    sSpriteAnim_855D05C,
    sSpriteAnim_855D064
};

static const union AnimCmd *const sSpriteAnimTable_855D140[] =
{
    sSpriteAnim_855D06C,
    sSpriteAnim_855D074,
    sSpriteAnim_855D07C,
    sSpriteAnim_855D084,
    sSpriteAnim_855D08C,
    sSpriteAnim_855D094,
    sSpriteAnim_855D09C,
    sSpriteAnim_855D0A4,
    sSpriteAnim_855D0AC,
    sSpriteAnim_855D0B4
};

static const union AnimCmd *const sSpriteAnimTable_855D168[] =
{
    sSpriteAnim_855D0BC,
    sSpriteAnim_855D0C4,
    sSpriteAnim_855D0CC,
    sSpriteAnim_855D0D4,
    sSpriteAnim_855D0DC,
    sSpriteAnim_855D0E4,
    sSpriteAnim_855D0EC,
    sSpriteAnim_855D0F4,
    sSpriteAnim_855D0FC,
    sSpriteAnim_855D104
};

static const union AnimCmd *const sSpriteAnimTable_855D190[] =
{
    sSpriteAnim_855D10C
};

const struct SpriteTemplate gUnknown_0855D194 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFE4,
    .anims = sSpriteAnimTable_855D114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE604,
};

const struct SpriteTemplate gUnknown_0855D1AC =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFEC,
    .anims = sSpriteAnimTable_855D118,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE658,
};

const struct SpriteTemplate gUnknown_0855D1C4 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D120,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE758,
};

const struct SpriteTemplate gUnknown_0855D1DC =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFFC,
    .anims = sSpriteAnimTable_855D11C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE780,
};

const struct SpriteTemplate gUnknown_0855D1F4 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D004,
    .anims = sSpriteAnimTable_855D130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D20C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855CFF4,
    .anims = sSpriteAnimTable_855D138,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D224 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D140,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D23C =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D168,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE44C,
};

const struct SpriteTemplate gUnknown_0855D254 =
{
    .tileTag = 4096,
    .paletteTag = 4096,
    .oam = &sOamData_855D00C,
    .anims = sSpriteAnimTable_855D190,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80BE834,
};

const struct CompressedSpriteSheet gSpriteSheets_0855D26C[] =
{
    {gPokedexMenu2_Gfx, 0x2000, 4096},
    {0}
};

const struct CompressedSpritePalette gSpritePalettes_0855D26C[] =
{
    {gPokedexText_Pal, 4096},
    {0}
};

const u8 gUnknown_0855D28C[] = {0x4, 0x8, 0x10, 0x20, 0x20};
const u8 gUnknown_0855D291[] = {0x8, 0x4, 0x2, 0x1, 0x1};

const struct BgTemplate gBgTemplates_0855D298[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct WindowTemplate sWindowTemplates_0855D2A8[] =
{
    {2, 0, 0, 0x20, 0x20, 0, 1},
    DUMMY_WIN_TEMPLATE
};

