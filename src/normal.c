#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_811572C(struct Sprite *);
extern void sub_81157FC(struct Sprite *);
extern void sub_81158A4(struct Sprite *);
extern void sub_81159B4(struct Sprite *);
extern void sub_81160A4(struct Sprite *);
extern void sub_8116388(struct Sprite *);
extern void sub_8116420(struct Sprite *);
extern void sub_8116458(struct Sprite *);
extern void sub_81164F0(struct Sprite *);
extern void sub_8116560(struct Sprite *);
extern void sub_81165A8(struct Sprite *);
extern void sub_81163D0(struct Sprite *);

const union AnimCmd gUnknown_0859722C[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08597240[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08597254[] =
{
    gUnknown_0859722C,
    gUnknown_08597240,
};

const struct SpriteTemplate gConfusionDuckSpriteTemplate =
{
    .tileTag = ANIM_TAG_DUCK,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08597254,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_811572C,
};

const struct SpriteTemplate gSimplePaletteBlendSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81157FC,
};

const struct SpriteTemplate gComplexPaletteBlendSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81158A4,
};

const union AnimCmd gUnknown_085972A4[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085972BC[] =
{
    gUnknown_085972A4,
};

const struct SpriteTemplate gUnknown_085972C0 =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085972BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81159B4,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85972D8 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81160A4,
};

const union AffineAnimCmd gUnknown_085972F0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597300[] =
{
    AFFINEANIMCMD_FRAME(0xD8, 0xD8, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597318[] =
{
    AFFINEANIMCMD_FRAME(0xB0, 0xB0, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597330[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08597348[] =
{
    gUnknown_085972F0,
    gUnknown_08597300,
    gUnknown_08597318,
    gUnknown_08597330,
};

const struct SpriteTemplate gBasicHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_8116388,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8597370 =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_8116420,
};

const struct SpriteTemplate gUnknown_08597388 =
{
    .tileTag = ANIM_TAG_WATER_IMPACT,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_8116388,
};

const struct SpriteTemplate gUnknown_085973A0 =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_8116458,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85973B8 =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_81164F0,
};

const struct SpriteTemplate gUnknown_085973D0 =
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_CROSS_IMPACT,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8116560,
};

const struct SpriteTemplate gUnknown_085973E8 =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_81165A8,
};

const struct SpriteTemplate gUnknown_08597400 =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_81163D0,
};
