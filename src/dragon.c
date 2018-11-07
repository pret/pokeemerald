#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_8113064(struct Sprite *);
extern void sub_8113224(struct Sprite *);
extern void sub_81131B4(struct Sprite *);
extern void sub_8113224(struct Sprite *);
extern void sub_8113250(struct Sprite *);
extern void sub_81135EC(struct Sprite *);

const union AnimCmd gUnknown_08596E60[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08596E78[] =
{
    gUnknown_08596E60,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596E7C =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596E78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8113064,
};

const union AnimCmd gUnknown_08596E94[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08596EA4[] =
{
    ANIMCMD_FRAME(16, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08596EB4[] =
{
    gUnknown_08596E94,
    gUnknown_08596EA4,
};

const union AffineAnimCmd gUnknown_08596EBC[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 127, 0),
    AFFINEANIMCMD_FRAME(0xD, 0xD, 0, 100),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596ED4[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0xD, 0xD, 0, 100),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596EEC[] =
{
    gUnknown_08596EBC,
    gUnknown_08596ED4,
};

const struct SpriteTemplate gUnknown_08596EF4 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08596EB4,
    .images = NULL,
    .affineAnims = gUnknown_08596EEC,
    .callback = sub_8113224,
};

const union AnimCmd gUnknown_08596F0C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596F24[] =
{
    gUnknown_08596F0C,
};

const struct SpriteTemplate gUnknown_08596F28 =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596F24,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81131B4,
};

const union AnimCmd gUnknown_08596F40[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08596F50[] =
{
    gUnknown_08596F40,
    gUnknown_08596F40,
};

const union AffineAnimCmd gUnknown_08596F58[] =
{
    AFFINEANIMCMD_FRAME(0x64, 0x64, 127, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08596F68[] =
{
    AFFINEANIMCMD_FRAME(0x64, 0x64, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596F78[] =
{
    gUnknown_08596F58,
    gUnknown_08596F68,
};

const struct SpriteTemplate gUnknown_08596F80 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08596F50,
    .images = NULL,
    .affineAnims = gUnknown_08596F78,
    .callback = sub_8113224,
};

const struct SpriteTemplate gUnknown_08596F98 =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_HOLLOW_ORB,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8113250,
};

const struct SpriteTemplate gUnknown_08596FB0 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08596E78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81135EC,
};
