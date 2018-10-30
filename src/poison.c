#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_80A77C8(struct Sprite *);
extern void sub_810DBAC(struct Sprite *);
extern void sub_810DC2C(struct Sprite *);
extern void sub_810DCD0(struct Sprite *);
extern void sub_810DD50(struct Sprite *);
extern void sub_810DDC4(struct Sprite *);
extern void sub_810DDC4(struct Sprite *);

extern const union AnimCmd *const gUnknown_08595200[];

const union AnimCmd gUnknown_0859611C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596130[] =
{
    gUnknown_0859611C,
};

const struct SpriteTemplate gUnknown_08596134 =
{
    .tileTag = ANIM_TAG_TOXIC_BUBBLE,
    .paletteTag = ANIM_TAG_TOXIC_BUBBLE,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_08596130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AnimCmd gUnknown_0859614C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596154[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859615C[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596164[] =
{
    gUnknown_0859614C,
};

const union AnimCmd *const gUnknown_08596168[] =
{
    gUnknown_08596154,
};

const union AnimCmd *const gUnknown_0859616C[] =
{
    gUnknown_0859615C,
};

const union AffineAnimCmd gUnknown_08596170[] =
{
    AFFINEANIMCMD_FRAME(0x160, 0x160, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08596190[] =
{
    AFFINEANIMCMD_FRAME(0xEC, 0xEC, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085961A0[] =
{
    gUnknown_08596170,
};

const union AffineAnimCmd *const gUnknown_085961A4[] =
{
    gUnknown_08596190,
};

const struct SpriteTemplate gUnknown_085961A8 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_085961A0,
    .callback = sub_810DBAC,
};

const struct SpriteTemplate gUnknown_085961C0 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_085961A0,
    .callback = sub_810DC2C,
};

const struct SpriteTemplate gUnknown_085961D8 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_0859616C,
    .images = NULL,
    .affineAnims = gUnknown_085961A4,
    .callback = sub_810DCD0,
};

const union AffineAnimCmd gUnknown_085961F0[] =
{
    AFFINEANIMCMD_FRAME(0xFFF0, 0x10, 0, 6),
    AFFINEANIMCMD_FRAME(0x10, 0xFFF0, 0, 6),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596208[] =
{
    gUnknown_085961F0,
};

const struct SpriteTemplate gUnknown_0859620C =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596168,
    .images = NULL,
    .affineAnims = gUnknown_08596208,
    .callback = sub_810DD50,
};

const union AffineAnimCmd gUnknown_08596224[] =
{
    AFFINEANIMCMD_FRAME(0x9C, 0x9C, 0, 0),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859623C[] =
{
    gUnknown_08596224,
};

const struct SpriteTemplate gPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_0859623C,
    .callback = sub_810DDC4,
};

const struct SpriteTemplate gWaterBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_08595200,
    .images = NULL,
    .affineAnims = gUnknown_0859623C,
    .callback = sub_810DDC4,
};
