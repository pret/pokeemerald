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
    gUnknown_08DA1E78, 0x3000, 30505
};

const struct CompressedSpritePalette gUnknown_0862A8CC =
{
    gUnknown_08DA3370, 30505
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
    gUnknown_08DA2A5C, 0x200, 30506
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
    gUnknown_08DA2B28, 0x400, 30507
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
    gUnknown_08DA2D1C, 0xF00, 30508
};

const struct CompressedSpritePalette gUnknown_0862A9DC =
{
    gUnknown_08DA3398, 30508
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
    gUnknown_08DA3250, 0xC0, 30509
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
    gUnknown_08DA32A4, 0x200, 30510
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
    gUnknown_08DA3BC0, 0x100, 30555
};

const struct CompressedSpritePalette gUnknown_0862AA98 =
{
    gUnknown_08DA3C7C, 30555
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

