#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void unc_080B08A0(struct Sprite *);
extern void sub_810CE68(struct Sprite *);
extern void sub_810CEB4(struct Sprite *);
extern void sub_810CEE0(struct Sprite *);
extern void sub_810CF30(struct Sprite *);
extern void sub_810D10C(struct Sprite *);
extern void sub_810D1B4(struct Sprite *);
extern void sub_810D278(struct Sprite *);
extern void sub_810D2E4(struct Sprite *);
extern void sub_810D37C(struct Sprite *);
extern void sub_810D40C(struct Sprite *);
extern void sub_810D4F4(struct Sprite *);
extern void sub_810D608(struct Sprite *);
extern void sub_810D714(struct Sprite *);
extern void sub_810D874(struct Sprite *);
extern void sub_810D984(struct Sprite *);
extern void sub_810DA10(struct Sprite *);
extern void sub_810DA7C(struct Sprite *);

const struct SpriteTemplate gUnknown_08595E14 =
{
    .tileTag = ANIM_TAG_HUMANOID_FOOT,
    .paletteTag = ANIM_TAG_HUMANOID_FOOT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = unc_080B08A0,
};

const union AnimCmd gUnknown_08595E2C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595E34[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595E3C[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595E44[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595E4C[] =
{
    ANIMCMD_FRAME(48, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595E54[] =
{
    gUnknown_08595E2C,
};

const union AnimCmd *const gUnknown_08595E58[] =
{
    gUnknown_08595E34,
    gUnknown_08595E3C,
};

const union AnimCmd *const gUnknown_08595E60[] =
{
    gUnknown_08595E44,
    gUnknown_08595E4C,
};

const struct SpriteTemplate gUnknown_08595E68 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CE68,
};

const struct SpriteTemplate gUnknown_08595E80 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CEB4,
};

const struct SpriteTemplate gFistFootSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CEE0,
};

const struct SpriteTemplate gUnknown_08595EB0 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CF30,
};

const struct SpriteTemplate gUnknown_08595EC8 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E60,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D10C,
};

const struct SpriteTemplate gUnknown_08595EE0 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E58,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D1B4,
};

const union AffineAnimCmd gUnknown_08595EF8[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 20, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08595F10[] =
{
    gUnknown_08595EF8,
};

const struct SpriteTemplate gUnknown_08595F14 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gUnknown_08595F10,
    .callback = sub_810D278,
};

const union AffineAnimCmd gUnknown_08595F2C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 20, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08595F44[] =
{
    gUnknown_08595F2C,
};

const struct SpriteTemplate gMegaPunchKickSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gUnknown_08595F44,
    .callback = sub_810D278,
};

const struct SpriteTemplate gUnknown_08595F60 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E58,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D2E4,
};

const struct SpriteTemplate gUnknown_08595F78 =
{
    .tileTag = ANIM_TAG_DUCK,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D37C,
};

const struct SpriteTemplate gUnknown_08595F90 =
{
    .tileTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .paletteTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D40C,
};

const struct SpriteTemplate gUnknown_08595FA8 =
{
    .tileTag = ANIM_TAG_TORN_METAL,
    .paletteTag = ANIM_TAG_TORN_METAL,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D4F4,
};

const union AffineAnimCmd gUnknown_08595FC0[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 64),
    AFFINEANIMCMD_FRAME(0xFFFA, 0xFFFA, 0, 8),
    AFFINEANIMCMD_FRAME(0x6, 0x6, 0, 8),
    AFFINEANIMCMD_JUMP(2),
};

const union AffineAnimCmd *const gUnknown_08595FE8[] =
{
    gUnknown_08595FC0,
};

const struct SpriteTemplate gUnknown_08595FEC =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595FE8,
    .callback = sub_810D608,
};

const struct SpriteTemplate gUnknown_08596004 =
{
    .tileTag = ANIM_TAG_FLAT_ROCK,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D714,
};

const struct SpriteTemplate gUnknown_0859601C =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_METEOR,
    .oam = &gUnknown_0852491C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D874,
};

const struct SpriteTemplate gUnknown_08596034 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810D984,
};

const union AnimCmd gUnknown_0859604C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859605C[] =
{
    ANIMCMD_FRAME(0, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859606C[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859607C[] =
{
    gUnknown_0859604C,
    gUnknown_0859605C,
    gUnknown_0859606C,
};

const struct SpriteTemplate gUnknown_08596088 =
{
    .tileTag = ANIM_TAG_PURPLE_SCRATCH,
    .paletteTag = ANIM_TAG_PURPLE_SCRATCH,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_0859607C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810DA10,
};

const union AnimCmd gUnknown_085960A0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085960AC[] =
{
    ANIMCMD_FRAME(0, 6, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 6, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085960B8[] =
{
    ANIMCMD_FRAME(0, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 6, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085960C4[] =
{
    gUnknown_085960A0,
    gUnknown_085960AC,
    gUnknown_085960B8,
};

const struct SpriteTemplate gUnknown_085960D0 =
{
    .tileTag = ANIM_TAG_PURPLE_SWIPE,
    .paletteTag = ANIM_TAG_PURPLE_SWIPE,
    .oam = &gUnknown_0852491C,
    .anims = gUnknown_085960C4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810DA10,
};

const union AffineAnimCmd gUnknown_085960E8[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFE0, 0xFFE0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596100[] =
{
    gUnknown_085960E8,
};

const struct SpriteTemplate gUnknown_08596104 =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08595E54,
    .images = NULL,
    .affineAnims = gUnknown_08596100,
    .callback = sub_810DA7C,
};

const struct SpriteTemplate gPalmSpriteTemplate =
{
	.tileTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
	.paletteTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
	.oam = &gUnknown_08524914,
	.anims = gUnknown_08595E54,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = sub_810CEE0,
};

const struct SpriteTemplate gAuraSphereBlast =
{
	.tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
	.paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
	.oam = &gUnknown_0852491C,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = sub_810D874,
};
