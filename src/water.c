#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_810721C(struct Sprite *);
extern void sub_8107260(struct Sprite *);
extern void sub_810744C(struct Sprite *);
extern void sub_81075EC(struct Sprite *);
extern void sub_8107730(struct Sprite *);
extern void sub_81077C0(struct Sprite *);
extern void sub_80A78AC(struct Sprite *);
extern void sub_8107894(struct Sprite *);
extern void sub_81078D0(struct Sprite *);
extern void sub_8108034(struct Sprite *);
extern void sub_810851C(struct Sprite *);
extern void sub_8108BE0(struct Sprite *);
extern void sub_8108C54(struct Sprite *);
extern void sub_80A8EE4(struct Sprite *);

extern const union AffineAnimCmd *const gUnknown_08593420[];
extern const union AffineAnimCmd *const gUnknown_08596208[];
extern const union AnimCmd *const gUnknown_08595AB8[];

// what is this?
const u8 gUnknown_8593C80[] = INCBIN_U8("graphics/unknown/unknown_593C80.4bpp");
const u8 gUnknown_8593FFC[] = INCBIN_U8("graphics/unknown/unknown_593FFC.bin");

const union AnimCmd gUnknown_08594FFC[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 6),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(40, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859501C[] =
{
    gUnknown_08594FFC,
};

const struct SpriteTemplate gUnknown_08595020 =
{
    .tileTag = ANIM_TAG_RAIN_DROPS,
    .paletteTag = ANIM_TAG_RAIN_DROPS,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_0859501C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810721C,
};

const union AffineAnimCmd gUnknown_08595038[] =
{
    AFFINEANIMCMD_FRAME(0xFFFB, 0xFFFB, 0, 10),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595050[] =
{
    gUnknown_08595038,
};

const union AnimCmd gUnknown_08595054[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595064[] =
{
    gUnknown_08595054,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8595068 =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_08595064,
    .images = NULL,
    .affineAnims = gUnknown_08595050,
    .callback = sub_8107260,
};

const union AnimCmd gUnknown_08595080[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595088[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595090[] =
{
    gUnknown_08595080,
    gUnknown_08595088,
};

const union AffineAnimCmd gUnknown_08595098[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x60, 0x60, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085950B0[] =
{
    gUnknown_08595098,
};

// Multi-colored rings used in Aurora Beam.
const struct SpriteTemplate gUnknown_085950B4 =
{
    .tileTag = ANIM_TAG_RAINBOW_RINGS,
    .paletteTag = ANIM_TAG_RAINBOW_RINGS,
    .oam = &gUnknown_08524A04,
    .anims = gUnknown_08595090,
    .images = NULL,
    .affineAnims = gUnknown_085950B0,
    .callback = sub_810744C,
};

const union AnimCmd gUnknown_085950CC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085950E0[] =
{
    gUnknown_085950CC,
};

const struct SpriteTemplate gUnknown_085950E4 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gUnknown_08524A2C,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_085950FC =
{
    .tileTag = ANIM_TAG_BROWN_ORB,
    .paletteTag = ANIM_TAG_BROWN_ORB,
    .oam = &gUnknown_08524A2C,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_08595114 =
{
    .tileTag = ANIM_TAG_GLOWY_RED_ORB,
    .paletteTag = ANIM_TAG_GLOWY_RED_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_0859512C =
{
    .tileTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .paletteTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const union AnimCmd gUnknown_08595144[] =
{
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595154[] =
{
    gUnknown_08595144,
};

const struct SpriteTemplate gUnknown_08595158 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595154,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_08595170 =
{
    .tileTag = ANIM_TAG_BLUE_RING,
    .paletteTag = ANIM_TAG_BLUE_RING,
    .oam = &gUnknown_08524A14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593420,
    .callback = sub_81075EC,
};

const union AffineAnimCmd gUnknown_08595188[] =
{
    AFFINEANIMCMD_FRAME(0x3, 0x3, 10, 50),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFEC, 0xFFEC, -10, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085951A8[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085951B8[] =
{
    gUnknown_08595188,
};

const union AffineAnimCmd *const gUnknown_085951BC[] =
{
    gUnknown_085951A8,
};

const struct SpriteTemplate gUnknown_085951C0 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gUnknown_08524AEC,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_085951B8,
    .callback = sub_8107730,
};

const struct SpriteTemplate gUnknown_085951D8 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gUnknown_08524AEC,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_085951BC,
    .callback = sub_81077C0,
};

const union AnimCmd gUnknown_085951F0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085951F8[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595200[] =
{
    gUnknown_085951F0,
};

const union AnimCmd *const gUnknown_08595204[] =
{
    gUnknown_085951F8,
};

const struct SpriteTemplate gUnknown_08595208 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524A2C,
    .anims = gUnknown_08595200,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A78AC,
};

const struct SpriteTemplate gUnknown_08595220 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524AEC,
    .anims = gUnknown_08595204,
    .images = NULL,
    .affineAnims = gUnknown_08596208,
    .callback = sub_8107894,
};

const struct SpriteTemplate gUnknown_08595238 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AB8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81078D0,
};

const struct SpriteTemplate gUnknown_08595250 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108034,
};

const struct SpriteTemplate gUnknown_08595268 =
{
    .tileTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .paletteTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810851C,
};

const union AnimCmd gUnknown_08595280[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595288[] =
{
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595290[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595298[] =
{
    gUnknown_08595280,
    gUnknown_08595288,
};

const union AnimCmd *const gUnknown_085952A0[] =
{
    gUnknown_08595290,
};

const union AffineAnimCmd gUnknown_085952A4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085952BC[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085952D4[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085952EC[] =
{
    gUnknown_085952A4,
    gUnknown_085952BC,
};

const union AffineAnimCmd *const gUnknown_085952F4[] =
{
    gUnknown_085952D4,
};

const struct SpriteTemplate gUnknown_085952F8 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595298,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108BE0,
};

const struct SpriteTemplate gUnknown_08595310 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524964,
    .anims = gUnknown_08595298,
    .images = NULL,
    .affineAnims = gUnknown_085952EC,
    .callback = sub_8108C54,
};

const struct SpriteTemplate gUnknown_08595328 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_085952A0,
    .images = NULL,
    .affineAnims = gUnknown_085952F4,
    .callback = sub_80A8EE4,
};
