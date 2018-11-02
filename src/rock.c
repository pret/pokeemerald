#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_81109F0(struct Sprite *);
extern void sub_8110AB4(struct Sprite *);
extern void sub_8110B38(struct Sprite *);
extern void sub_8110E4C(struct Sprite *);
extern void sub_8110F30(struct Sprite *);
extern void sub_811131C(struct Sprite *);
extern void sub_8111388(struct Sprite *);
extern void sub_8111418(struct Sprite *);
extern void sub_8111444(struct Sprite *);
extern void sub_80FF268(struct Sprite *);
extern void sub_80A8EE4(struct Sprite *);

extern const union AnimCmd *const gUnknown_085950E0[];
extern const union AnimCmd *const gUnknown_085954D0[];

const union AnimCmd gUnknown_08596AE0[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596AE8[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596AF0[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596AF8[] =
{
    gUnknown_08596AE0,
    gUnknown_08596AE8,
    gUnknown_08596AF0,
};

const struct SpriteTemplate gUnknown_08596B04 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596AF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81109F0,
};

const struct SpriteTemplate gUnknown_08596B1C =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596AF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110AB4,
};

const struct SpriteTemplate gUnknown_08596B34 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110B38,
};

const union AffineAnimCmd gUnknown_08596B4C[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(0x2, 0xFFFD, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFFE, 0x3, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08596B6C[] =
{
    gUnknown_08596B4C,
};

const struct SpriteTemplate gUnknown_08596B70 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_08596B6C,
    .callback = sub_8110B38,
};

const struct SpriteTemplate gUnknown_08596B88 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110B38,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596BA0 =
{
    .tileTag = ANIM_TAG_FLYING_DIRT,
    .paletteTag = ANIM_TAG_FLYING_DIRT,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110E4C,
};

const struct Subsprite gUnknown_08596BB8[] =
{
    {.x = -16, .y = 0, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 0, .priority = 1},
    {.x =  16, .y = 0, .shape = ST_OAM_H_RECTANGLE, .size = 2, .tileOffset = 8, .priority = 1},
};

const struct SubspriteTable gUnknown_08596BC0[] =
{
    {ARRAY_COUNT(gUnknown_08596BB8), gUnknown_08596BB8},
};

const union AnimCmd gUnknown_08596BC8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BD0[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BD8[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BE0[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BE8[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596BF0[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596BF8[] =
{
    gUnknown_08596BC8,
    gUnknown_08596BD0,
};

const union AnimCmd *const gUnknown_08596C00[] =
{
    gUnknown_08596BD8,
    gUnknown_08596BE0,
};

const union AnimCmd *const gUnknown_08596C08[] =
{
    gUnknown_08596BE8,
    gUnknown_08596BF0,
};

const struct SpriteTemplate gUnknown_08596C10 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110F30,
};

const struct SpriteTemplate gUnknown_08596C28 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_811131C,
};

const struct SpriteTemplate gUnknown_08596C40 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_811131C,
};

const struct SpriteTemplate gUnknown_08596C58 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8111388,
};

const union AffineAnimCmd gUnknown_08596C70[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08596C80[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596C90[] =
{
    gUnknown_08596C70,
    gUnknown_08596C80,
};

const struct SpriteTemplate gUnknown_08596C98 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_8111418,
};

const struct SpriteTemplate gUnknown_08596CB0 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596BF8,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_8111444,
};

const struct SpriteTemplate gUnknown_08596CC8 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596C08,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_80FF268,
};

const struct SpriteTemplate gUnknown_08596CE0 =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08596C00,
    .images = NULL,
    .affineAnims = gUnknown_08596C90,
    .callback = sub_80A8EE4,
};
