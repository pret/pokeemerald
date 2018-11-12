#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_8114994(struct Sprite *);
extern void sub_8114A7C(struct Sprite *);
extern void sub_8114AF0(struct Sprite *);
extern void sub_8114AF0(struct Sprite *);
extern void sub_8114B80(struct Sprite *);
extern void sub_81151A0(struct Sprite *);
extern void sub_8115244(struct Sprite *);

const union AffineAnimCmd gUnknown_08597150[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 15, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08597160[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08597170[] =
{
    gUnknown_08597150,
};

const union AffineAnimCmd *const gUnknown_08597174[] =
{
    gUnknown_08597160,
};

const struct SpriteTemplate gUnknown_08597178 =
{
    .tileTag = ANIM_TAG_BONE,
    .paletteTag = ANIM_TAG_BONE,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597170,
    .callback = sub_8114994,
};

const struct SpriteTemplate gUnknown_08597190 =
{
    .tileTag = ANIM_TAG_BONE,
    .paletteTag = ANIM_TAG_BONE,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597174,
    .callback = sub_8114A7C,
};

const struct SpriteTemplate gUnknown_085971A8 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8114AF0,
};

const union AnimCmd gUnknown_085971C0[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085971C8[] =
{
    gUnknown_085971C0,
};

const struct SpriteTemplate gUnknown_085971CC =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085971C8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8114AF0,
};

const struct SpriteTemplate gUnknown_085971E4 =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8114B80,
};

const struct SpriteTemplate gUnknown_085971FC =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81151A0,
};

const struct SpriteTemplate gUnknown_08597214 =
{
    .tileTag = ANIM_TAG_DIRT_MOUND,
    .paletteTag = ANIM_TAG_DIRT_MOUND,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8115244,
};
