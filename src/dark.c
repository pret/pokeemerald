#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_81138D4(struct Sprite *);
extern void sub_81139DC(struct Sprite *);
extern void sub_8113A90(struct Sprite *);
extern void sub_81144BC(struct Sprite *);

const struct SpriteTemplate gUnknown_08596FC8 =
{
    .tileTag = ANIM_TAG_TIED_BAG,
    .paletteTag = ANIM_TAG_TIED_BAG,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81138D4,
};

const union AffineAnimCmd gUnknown_08596FE0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596FF0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 32, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597000[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 64, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597010[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 96, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597020[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -128, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597030[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -96, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597040[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -64, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597050[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -32, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08597060[] =
{
    gUnknown_08596FE0,
    gUnknown_08596FF0,
    gUnknown_08597000,
    gUnknown_08597010,
    gUnknown_08597020,
    gUnknown_08597030,
    gUnknown_08597040,
    gUnknown_08597050,
};

const struct SpriteTemplate gUnknown_08597080 =
{
    .tileTag = ANIM_TAG_SHARP_TEETH,
    .paletteTag = ANIM_TAG_SHARP_TEETH,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597060,
    .callback = sub_81139DC,
};

const struct SpriteTemplate gUnknown_08597098 =
{
    .tileTag = ANIM_TAG_CLAMP,
    .paletteTag = ANIM_TAG_CLAMP,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597060,
    .callback = sub_81139DC,
};

const union AffineAnimCmd gUnknown_085970B0[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 80, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -2, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085970C8[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, -80, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085970E0[] =
{
    gUnknown_085970B0,
    gUnknown_085970C8,
};

const struct SpriteTemplate gUnknown_085970E8 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085970E0,
    .callback = sub_8113A90,
};

const union AnimCmd gUnknown_08597100[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08597118[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08597130[] =
{
    gUnknown_08597100,
    gUnknown_08597118,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8597138 =
{
    .tileTag = ANIM_TAG_CLAW_SLASH,
    .paletteTag = ANIM_TAG_CLAW_SLASH,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08597130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81144BC,
};
