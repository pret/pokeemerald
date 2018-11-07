#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_811160C(struct Sprite *);
extern void sub_81117F4(struct Sprite *);
extern void sub_81119E0(struct Sprite *);
extern void sub_8111B9C(struct Sprite *);
extern void sub_8112264(struct Sprite *);
extern void sub_81129F0(struct Sprite *);
extern void sub_8112B78(struct Sprite *);
extern void sub_8112E9C(struct Sprite *);
extern void sub_8112F60(struct Sprite *);

const union AffineAnimCmd gUnknown_08596CF8[] =
{
    AFFINEANIMCMD_FRAME(0x1E, 0x1E, 10, 5),
    AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 10, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596D10[] =
{
    gUnknown_08596CF8,
};

const struct SpriteTemplate gUnknown_08596D14 =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gUnknown_085249CC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D10,
    .callback = sub_811160C,
};

const struct SpriteTemplate gUnknown_08596D2C =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gUnknown_08524A2C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81117F4,
};

const union AffineAnimCmd gUnknown_08596D44[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596D54[] =
{
    gUnknown_08596D44,
};

const struct SpriteTemplate gUnknown_08596D58 =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D54,
    .callback = sub_81119E0,
};

const union AnimCmd gUnknown_08596D70[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596D88[] =
{
    gUnknown_08596D70,
};

const struct SpriteTemplate gUnknown_08596D8C =
{
    .tileTag = ANIM_TAG_LICK,
    .paletteTag = ANIM_TAG_LICK,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_08596D88,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8111B9C,
};

const union AffineAnimCmd gUnknown_08596DA4[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596DB4[] =
{
    gUnknown_08596DA4,
};

const struct SpriteTemplate gUnknown_08596DB8 =
{
    .tileTag = ANIM_TAG_WHITE_SHADOW,
    .paletteTag = ANIM_TAG_WHITE_SHADOW,
    .oam = &gUnknown_08524A5C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112264,
};

const struct SpriteTemplate gUnknown_08596DD0 =
{
    .tileTag = ANIM_TAG_NAIL,
    .paletteTag = ANIM_TAG_NAIL,
    .oam = &gUnknown_08524A54,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81129F0,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596DE8 =
{
    .tileTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .paletteTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112B78,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596E00 =
{
    .tileTag = ANIM_TAG_DEVIL,
    .paletteTag = ANIM_TAG_DEVIL,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112B78,
};

const union AnimCmd gUnknown_08596E18[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08596E2C[] =
{
    gUnknown_08596E18,
};

const struct SpriteTemplate gUnknown_08596E30 =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gUnknown_08524A74,
    .anims = gUnknown_08596E2C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112E9C,
};

const struct SpriteTemplate gUnknown_08596E48 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112F60,
};
