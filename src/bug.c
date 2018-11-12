#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_8110368(struct Sprite *);
extern void sub_8110438(struct Sprite *);
extern void sub_81104E4(struct Sprite *);
extern void sub_81105B4(struct Sprite *);
extern void sub_811067C(struct Sprite *);
extern void sub_8110720(struct Sprite *);
extern void sub_8110850(struct Sprite *);
extern void sub_8110994(struct Sprite *);

const union AffineAnimCmd gUnknown_08596938[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 30, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596948[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -99, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596958[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 94, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596968[] =
{
    gUnknown_08596938,
    gUnknown_08596948,
    gUnknown_08596958,
};

const struct SpriteTemplate gUnknown_08596974 =
{
    .tileTag = ANIM_TAG_HORN_HIT_2,
    .paletteTag = ANIM_TAG_HORN_HIT_2,
    .oam = &gUnknown_085249F4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596968,
    .callback = sub_8110368,
};

const union AffineAnimCmd gUnknown_0859698C[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -33, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859699C[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 96, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085969AC[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -96, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085969BC[] =
{
    gUnknown_0859698C,
    gUnknown_0859699C,
    gUnknown_085969AC,
};

const struct SpriteTemplate gUnknown_085969C8 =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_NEEDLE,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085969BC,
    .callback = sub_8110438,
};

const struct SpriteTemplate gUnknown_085969E0 =
{
    .tileTag = ANIM_TAG_WEB_THREAD,
    .paletteTag = ANIM_TAG_WEB_THREAD,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81104E4,
};

const struct SpriteTemplate gUnknown_085969F8 =
{
    .tileTag = ANIM_TAG_STRING,
    .paletteTag = ANIM_TAG_STRING,
    .oam = &gUnknown_0852493C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81105B4,
};

const union AffineAnimCmd gUnknown_08596A10[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x6, 0x6, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08596A28[] =
{
    gUnknown_08596A10,
};

const struct SpriteTemplate gUnknown_08596A2C =
{
    .tileTag = ANIM_TAG_SPIDER_WEB,
    .paletteTag = ANIM_TAG_SPIDER_WEB,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596A28,
    .callback = sub_811067C,
};

const struct SpriteTemplate gLinearStingerSpriteTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_NEEDLE,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110720,
};

const struct SpriteTemplate gPinMissileSpriteTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_NEEDLE,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110850,
};

const struct SpriteTemplate gIcicleSpearSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ICICLE_SPEAR,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8110850,
};

const union AffineAnimCmd gUnknown_08596A8C[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 18),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFFB, 0xFFFB, 0, 8),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 8),
    AFFINEANIMCMD_LOOP(5),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596AC4[] =
{
    gUnknown_08596A8C,
};

const struct SpriteTemplate gUnknown_08596AC8 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596AC4,
    .callback = sub_8110994,
};
