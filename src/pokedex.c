#include "global.h"
#include "gba/m4a_internal.h"
#include "pokedex.h"

#include "data/pokedex_orders.h"

static const struct OamData gOamData_83A0404 =
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
    .affineParam = 0,
};
static const struct OamData gOamData_83A040C =
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
    .affineParam = 0,
};
static const struct OamData gOamData_83A0414 =
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
    .affineParam = 0,
};
static const struct OamData gOamData_83A041C =
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
    .affineParam = 0,
};
static const struct OamData gOamData_83A0424 =
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
    .affineParam = 0,
};
static const struct OamData gOamData_83A042C =
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
    .affineParam = 0,
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
