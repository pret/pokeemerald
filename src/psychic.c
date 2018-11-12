#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_80A77C8(struct Sprite *);
extern void sub_810F1EC(struct Sprite *);
extern void sub_810F1EC(struct Sprite *);
extern void sub_810F58C(struct Sprite *);
extern void TranslateAnimSpriteToTargetMonLocation(struct Sprite *);
extern void sub_810F634(struct Sprite *);
extern void sub_810F6B0(struct Sprite *);
extern void sub_810FBA8(struct Sprite *);
extern void sub_810FDF0(struct Sprite *);
extern void sub_80A77C8(struct Sprite *);
extern void sub_8110240(struct Sprite *);

const union AffineAnimCmd gUnknown_0859652C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFFE, 0xFFFE, -10, 120),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596544[] =
{
    gUnknown_0859652C,
};

const struct SpriteTemplate gUnknown_08596548 =
{
    .tileTag = ANIM_TAG_SPIRAL,
    .paletteTag = ANIM_TAG_SPIRAL,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596544,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_08596560 =
{
    .tileTag = ANIM_TAG_GREEN_LIGHT_WALL,
    .paletteTag = ANIM_TAG_GREEN_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F1EC,
};

const struct SpriteTemplate gUnknown_08596578 =
{
    .tileTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .paletteTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F1EC,
};

const struct SpriteTemplate gUnknown_08596590 =
{
    .tileTag = ANIM_TAG_RED_LIGHT_WALL,
    .paletteTag = ANIM_TAG_RED_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F1EC,
};

const struct SpriteTemplate gUnknown_085965A8 =
{
    .tileTag = ANIM_TAG_GRAY_LIGHT_WALL,
    .paletteTag = ANIM_TAG_GRAY_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F1EC,
};

const struct SpriteTemplate gUnknown_085965C0 =
{
    .tileTag = ANIM_TAG_ORANGE_LIGHT_WALL,
    .paletteTag = ANIM_TAG_ORANGE_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F1EC,
};

const union AnimCmd gUnknown_085965D8[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085965F0[] =
{
    gUnknown_085965D8,
};

const struct SpriteTemplate gUnknown_085965F4 =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085965F0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F58C,
};

const union AnimCmd gUnknown_0859660C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596620[] =
{
    gUnknown_0859660C,
};

const struct SpriteTemplate gUnknown_08596624 =
{
    .tileTag = ANIM_TAG_SPARKLE_3,
    .paletteTag = ANIM_TAG_SPARKLE_3,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08596620,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F58C,
};

const struct SpriteTemplate gUnknown_0859663C =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_GOLD_RING,
    .oam = &gUnknown_08524954,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const union AnimCmd gUnknown_08596654[] =
{
    ANIMCMD_FRAME(8, 60, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 22, .hFlip = TRUE),
    ANIMCMD_LOOP(0),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 5, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(8, 22, .hFlip = TRUE),
    ANIMCMD_FRAME(24, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(40, 22, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596694[] =
{
    ANIMCMD_FRAME(8, 60),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(8, 22),
    ANIMCMD_LOOP(0),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(8, 22),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(40, 22),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085966D4[] =
{
    gUnknown_08596654,
    gUnknown_08596694,
};

const struct SpriteTemplate gUnknown_085966DC =
{
    .tileTag = ANIM_TAG_BENT_SPOON,
    .paletteTag = ANIM_TAG_BENT_SPOON,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_085966D4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F634,
};

const union AnimCmd gUnknown_085966F4[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(96, 18),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596714[] =
{
    gUnknown_085966F4,
};

const union AffineAnimCmd gUnknown_08596718[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 4, 4),
    AFFINEANIMCMD_FRAME(0, 0, -4, 8),
    AFFINEANIMCMD_FRAME(0, 0, 4, 4),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596740[] =
{
    gUnknown_08596718,
};

const struct SpriteTemplate gUnknown_08596744 =
{
    .tileTag = ANIM_TAG_AMNESIA,
    .paletteTag = ANIM_TAG_AMNESIA,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596714,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810F6B0,
};

const union AffineAnimCmd gUnknown_0859675C[] =
{
    AFFINEANIMCMD_FRAME(-8, 10, 0, 16),
    AFFINEANIMCMD_FRAME(18, -18, 0, 16),
    AFFINEANIMCMD_FRAME(-20, 16, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859677C[] =
{
    AFFINEANIMCMD_FRAME(64, -4, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, -56),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_08596794 =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_HOLLOW_ORB,
    .oam = &gUnknown_08524A2C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_085967AC =
{
    .tileTag = 10250,
    .paletteTag = 10250,
    .oam = &gUnknown_0852491C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810FBA8,
};

const union AffineAnimCmd gUnknown_085967C4[] =
{
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 8),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085967DC[] =
{
    AFFINEANIMCMD_FRAME(0xF0, 0xF0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 6),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 2),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_08596804[] =
{
    AFFINEANIMCMD_FRAME(0xD0, 0xD0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 4),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 4),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_0859682C[] =
{
    AFFINEANIMCMD_FRAME(0xB0, 0xB0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 2),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 6),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08596854[] =
{
    gUnknown_085967C4,
    gUnknown_085967DC,
    gUnknown_08596804,
    gUnknown_0859682C,
};

const struct SpriteTemplate gUnknown_08596864 =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596854,
    .callback = sub_810FDF0,
};

const union AffineAnimCmd gUnknown_0859687C[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 120),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gUnknown_08596894[] =
{
    gUnknown_0859687C,
};

const struct SpriteTemplate gUnknown_08596898 =
{
    .tileTag = ANIM_TAG_WHITE_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WHITE_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596894,
    .callback = sub_80A77C8,
};

const union AffineAnimCmd gUnknown_085968B0[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 17),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 10),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 10),
    AFFINEANIMCMD_LOOP(4),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFF0, 0xFFF0, 0, 5),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 5),
    AFFINEANIMCMD_LOOP(7),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596908[] =
{
    AFFINEANIMCMD_FRAME(0xFFEC, 0x18, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596918[] =
{
    gUnknown_085968B0,
    gUnknown_08596908,
};

const struct SpriteTemplate gUnknown_08596920 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596918,
    .callback = sub_8110240,
};
