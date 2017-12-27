#include "global.h"
#include "sprite.h"
#include "task.h"
#include "graphics.h"
#include "bg.h"

struct UnkRayquazaStruct
{
    u32 field_0;
    u32 field_4;
    u32 field_8;
};

// this file's functions
void sub_81D7134(u8 taskId);
void sub_81D7F4C(u8 taskId);
void sub_81D84EC(u8 taskId);
void sub_81D8980(u8 taskId);
void sub_81D8DB4(u8 taskId);
void sub_81D6800(u8 taskId);

void sub_81D8260(struct Sprite *sprite);
void sub_81D961C(struct Sprite *sprite);

// const rom data
const TaskFunc gUnknown_0862A6A0[] =
{
    sub_81D7134,
    sub_81D7134,
    sub_81D7F4C,
    sub_81D84EC,
    sub_81D8980,
    sub_81D8DB4,
    sub_81D6800
};

static const struct OamData sOamData_862A6BC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6C4 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6CC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6D4 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6DC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6E4 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6EC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_862A6F4 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_862A6FC[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A710[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862A724[] =
{
    sSpriteAnim_862A6FC,
    sSpriteAnim_862A710
};

const struct SpriteTemplate gUnknown_0862A72C =
{
    .tileTag = 30505,
    .paletteTag = 30505,
    .oam = &sOamData_862A6BC,
    .anims = sSpriteAnimTable_862A724,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A744[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862A74C[] =
{
    sSpriteAnim_862A744
};

const struct SpriteTemplate gUnknown_0862A750 =
{
    .tileTag = 30506,
    .paletteTag = 30505,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862A74C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A768[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862A770[] =
{
    sSpriteAnim_862A768
};

const struct SpriteTemplate gUnknown_0862A774 =
{
    .tileTag = 30507,
    .paletteTag = 30505,
    .oam = &sOamData_862A6CC,
    .anims = sSpriteAnimTable_862A770,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A78C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A794[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A79C[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7A4[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7AC[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7B4[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A7BC[] =
{
    ANIMCMD_FRAME(48, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_FRAME(80, 36),
    ANIMCMD_FRAME(64, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A7D0[] =
{
    ANIMCMD_FRAME(56, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_FRAME(88, 36),
    ANIMCMD_FRAME(72, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A7E4[] =
{
    ANIMCMD_FRAME(96, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_FRAME(112, 36),
    ANIMCMD_FRAME(104, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862A7F8[] =
{
    sSpriteAnim_862A78C,
    sSpriteAnim_862A794,
    sSpriteAnim_862A79C,
    sSpriteAnim_862A7A4,
    sSpriteAnim_862A7AC,
    sSpriteAnim_862A7B4,
    sSpriteAnim_862A7BC,
    sSpriteAnim_862A7D0,
    sSpriteAnim_862A7E4
};

const struct SpriteTemplate gUnknown_0862A81C =
{
    .tileTag = 30508,
    .paletteTag = 30508,
    .oam = &sOamData_862A6D4,
    .anims = sSpriteAnimTable_862A7F8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A834[] =
{
    ANIMCMD_FRAME(0, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_FRAME(4, 36),
    ANIMCMD_FRAME(2, 36),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862A848[] =
{
    sSpriteAnim_862A834
};

const struct SpriteTemplate gUnknown_0862A84C =
{
    .tileTag = 30509,
    .paletteTag = 30508,
    .oam = &sOamData_862A6DC,
    .anims = sSpriteAnimTable_862A848,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862A864 =
{
    .tileTag = 30510,
    .paletteTag = 30508,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862A74C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct UnkRayquazaStruct gUnknown_0862A87C = {0x4000014, 0xA2600001, 1};

const struct BgTemplate gUnknown_0862A888[] =
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
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const union AnimCmd sSpriteAnim_862A894[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A8A8[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_FRAME(320, 20),
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862A8BC[] =
{
    sSpriteAnim_862A894,
    sSpriteAnim_862A8A8
};

const struct CompressedSpriteSheet gUnknown_0862A8C4 =
{
    gRaySceneGroudon_Gfx, 0x3000, 30505
};

const struct CompressedSpritePalette gUnknown_0862A8CC =
{
    gRaySceneGroudon_Pal, 30505
};

const struct SpriteTemplate gUnknown_0862A8D4 =
{
    .tileTag = 30505,
    .paletteTag = 30505,
    .oam = &sOamData_862A6BC,
    .anims = sSpriteAnimTable_862A8BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A8EC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862A8F4[] =
{
    sSpriteAnim_862A8EC
};

const struct CompressedSpriteSheet gUnknown_0862A8F8 =
{
    gRaySceneGroudon2_Gfx, 0x200, 30506
};

const struct SpriteTemplate gUnknown_0862A900 =
{
    .tileTag = 30506,
    .paletteTag = 30505,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862A8F4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A918[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862A920[] =
{
    sSpriteAnim_862A918
};

const struct CompressedSpriteSheet gUnknown_0862A924 =
{
    gRaySceneGroudon3_Gfx, 0x400, 30507
};

const struct SpriteTemplate gUnknown_0862A92C =
{
    .tileTag = 30507,
    .paletteTag = 30505,
    .oam = &sOamData_862A6CC,
    .anims = sSpriteAnimTable_862A920,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A944[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A94C[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A954[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A95C[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A964[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A96C[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862A974[] =
{
    ANIMCMD_FRAME(48, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_FRAME(80, 24),
    ANIMCMD_FRAME(64, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A988[] =
{
    ANIMCMD_FRAME(56, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_FRAME(88, 24),
    ANIMCMD_FRAME(72, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_862A99C[] =
{
    ANIMCMD_FRAME(96, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_FRAME(112, 24),
    ANIMCMD_FRAME(104, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862A9B0[] =
{
    sSpriteAnim_862A944,
    sSpriteAnim_862A94C,
    sSpriteAnim_862A954,
    sSpriteAnim_862A95C,
    sSpriteAnim_862A964,
    sSpriteAnim_862A96C,
    sSpriteAnim_862A974,
    sSpriteAnim_862A988,
    sSpriteAnim_862A99C
};

const struct CompressedSpriteSheet gUnknown_0862A9D4 =
{
    gRaySceneKyogre_Gfx, 0xF00, 30508
};

const struct CompressedSpritePalette gUnknown_0862A9DC =
{
    gRaySceneKyogre_Pal, 30508
};

const struct SpriteTemplate gUnknown_0862A9E4 =
{
    .tileTag = 30508,
    .paletteTag = 30508,
    .oam = &sOamData_862A6D4,
    .anims = sSpriteAnimTable_862A9B0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AnimCmd sSpriteAnim_862A9FC[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862AA10[] =
{
    sSpriteAnim_862A9FC
};

const struct CompressedSpriteSheet gUnknown_0862AA14 =
{
    gRaySceneKyogre2_Gfx, 0xC0, 30509
};

const struct SpriteTemplate gUnknown_0862AA1C =
{
    .tileTag = 30509,
    .paletteTag = 30508,
    .oam = &sOamData_862A6DC,
    .anims = sSpriteAnimTable_862AA10,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct CompressedSpriteSheet gUnknown_0862AA34 =
{
    gRaySceneKyogre3_Gfx, 0x200, 30510
};

const struct SpriteTemplate gUnknown_0862AA3C =
{
    .tileTag = 30510,
    .paletteTag = 30508,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862A8F4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct BgTemplate gUnknown_0862AA54[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const union AnimCmd sSpriteAnim_862AA60[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862AA68[] =
{
    sSpriteAnim_862AA60
};

static const union AffineAnimCmd sSpriteAffineAnim_862AA6C[] =
{
    AFFINEANIMCMD_FRAME(-64, -64, 0, 1),
    AFFINEANIMCMD_FRAME(32, 32, 0, 14),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_862AA8C[] =
{
    sSpriteAffineAnim_862AA6C
};

const struct CompressedSpriteSheet gUnknown_0862AA90 =
{
    gRaySceneSmoke_Gfx, 0x100, 30555
};

const struct CompressedSpritePalette gUnknown_0862AA98 =
{
    gRaySceneSmoke_Pal, 30555
};

const struct SpriteTemplate gUnknown_0862AAA0 =
{
    .tileTag = 30555,
    .paletteTag = 30555,
    .oam = &sOamData_862A6D4,
    .anims = sSpriteAnimTable_862AA68,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_862AA8C,
    .callback = sub_81D8260,
};

const s8 gUnknown_0862AAB8[][2] =
{
    {-1,    5},
    {-3,    -4},
    {5,     -3},
    {-7,    2},
    {-9,    -1},
    {1,     -5},
    {3,     4},
    {-5,    3},
    {7,     -2},
    {9,     1}
};

const struct BgTemplate gUnknown_0862AACC[] =
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
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sSpriteAnim_862AADC[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862AAE8[] =
{
    sSpriteAnim_862AADC
};

static const union AnimCmd sSpriteAnim_862AAEC[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(8, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_862AAF8[] =
{
    sSpriteAnim_862AAEC
};

const struct CompressedSpriteSheet gUnknown_0862AAFC =
{
    gRaySceneRayquazaFly1_Gfx, 0x1000, 30556
};

const struct CompressedSpriteSheet gUnknown_0862AB04 =
{
    gRaySceneRayquazaTail_Gfx, 0x200, 30557
};

const struct CompressedSpritePalette gUnknown_0862AB0C =
{
    gRaySceneRayquaza_Pal, 30556
};

const struct SpriteTemplate gUnknown_0862AB14 =
{
    .tileTag = 30556,
    .paletteTag = 30556,
    .oam = &sOamData_862A6BC,
    .anims = sSpriteAnimTable_862AAE8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862AB2C =
{
    .tileTag = 30557,
    .paletteTag = 30556,
    .oam = &sOamData_862A6E4,
    .anims = sSpriteAnimTable_862AAF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct BgTemplate gUnknown_0862AB44[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AnimCmd sSpriteAnim_862AB54[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB5C[] =
{
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(64, 32),
    ANIMCMD_FRAME(0, 48),
    ANIMCMD_FRAME(128, 32),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_862AB70[] =
{
    sSpriteAnim_862AB54,
    sSpriteAnim_862AB5C
};

static const union AnimCmd sSpriteAnim_862AB78[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862AB80[] =
{
    sSpriteAnim_862AB78,
};

static const union AnimCmd sSpriteAnim_862AB84[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB8C[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862AB94[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862AB9C[] =
{
    sSpriteAnim_862AB84,
    sSpriteAnim_862AB8C,
    sSpriteAnim_862AB94
};

static const union AnimCmd sSpriteAnim_862ABA8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABB0[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABB8[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABC0[] =
{
    ANIMCMD_FRAME(192, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862ABC8[] =
{
    sSpriteAnim_862ABA8,
    sSpriteAnim_862ABB0,
    sSpriteAnim_862ABB8,
    sSpriteAnim_862ABC0
};

static const union AnimCmd sSpriteAnim_862ABD8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABE0[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABE8[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862ABF0[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862ABF8[] =
{
    sSpriteAnim_862ABD8,
    sSpriteAnim_862ABE0,
    sSpriteAnim_862ABE8,
    sSpriteAnim_862ABF0
};

static const union AnimCmd sSpriteAnim_862AC08[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(20, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_862AC24[] =
{
    sSpriteAnim_862AC08
};

const struct CompressedSpriteSheet gUnknown_0862AC28 =
{
    gRaySceneGroudonLeft_Gfx, 0x1800, 30565
};

const struct CompressedSpriteSheet gUnknown_0862AC30 =
{
    gRaySceneGroudonTail_Gfx, 0x80, 30566
};

const struct CompressedSpriteSheet gUnknown_0862AC38 =
{
    gRaySceneKyogreRight_Gfx, 0x600, 30568
};

const struct CompressedSpriteSheet gUnknown_0862AC40 =
{
    gRaySceneRayquazaHover_Gfx, 0x2000, 30569
};

const struct CompressedSpriteSheet gUnknown_0862AC48 =
{
    gRaySceneRayquazaFlyIn_Gfx, 0x800, 30570
};

const struct CompressedSpriteSheet gUnknown_0862AC50 =
{
    gRaySceneSplash_Gfx, 0x300, 30571
};

const struct CompressedSpritePalette gUnknown_0862AC58 =
{
    gRaySceneGroudonLeft_Pal, 30565
};

const struct CompressedSpritePalette gUnknown_0862AC60 =
{
    gRaySceneKyogreRight_Pal, 30568
};

const struct CompressedSpritePalette gUnknown_0862AC68 =
{
    gRaySceneRayquazaHover_Pal, 30569
};

const struct CompressedSpritePalette gUnknown_0862AC70 =
{
    gRaySceneSplash_Pal, 30571
};

const struct SpriteTemplate gUnknown_0862AC78 =
{
    .tileTag = 30565,
    .paletteTag = 30565,
    .oam = &sOamData_862A6BC,
    .anims = sSpriteAnimTable_862AB70,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862AC90 =
{
    .tileTag = 30566,
    .paletteTag = 30565,
    .oam = &sOamData_862A6EC,
    .anims = sSpriteAnimTable_862AB80,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862ACA8 =
{
    .tileTag = 30568,
    .paletteTag = 30568,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862AB9C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862ACC0 =
{
    .tileTag = 30569,
    .paletteTag = 30569,
    .oam = &sOamData_862A6BC,
    .anims = sSpriteAnimTable_862ABC8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81D961C,
};

const struct SpriteTemplate gUnknown_0862ACD8 =
{
    .tileTag = 30570,
    .paletteTag = 30569,
    .oam = &sOamData_862A6C4,
    .anims = sSpriteAnimTable_862ABF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_0862ACF0 =
{
    .tileTag = 30571,
    .paletteTag = 30571,
    .oam = &sOamData_862A6F4,
    .anims = sSpriteAnimTable_862AC24,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct BgTemplate gUnknown_0862AD08[] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

