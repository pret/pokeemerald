#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_8103448(struct Sprite *);
extern void sub_8103498(struct Sprite *);
extern void sub_810358C(struct Sprite *);
extern void sub_8103620(struct Sprite *);
extern void sub_80A77C8(struct Sprite *);
extern void sub_81037D8(struct Sprite *);
extern void sub_810387C(struct Sprite *);
extern void sub_81038C8(struct Sprite *);
extern void sub_8103AA4(struct Sprite *);
extern void TranslateAnimSpriteToTargetMonLocation(struct Sprite *);
extern void sub_8108C94(struct Sprite *);
extern void sub_80A78AC(struct Sprite *);
extern void sub_8103FE8(struct Sprite *);
extern void sub_8104088(struct Sprite *);
extern void sub_810413C(struct Sprite *);
extern void sub_81041C4(struct Sprite *);
extern void sub_8104304(struct Sprite *);
extern void sub_8104364(struct Sprite *);
extern void sub_8104414(struct Sprite *);
extern void sub_8104B1C(struct Sprite *);
extern void sub_8104BAC(struct Sprite *);
extern void sub_810501C(struct Sprite *);
extern void sub_80A7938(struct Sprite *);
extern void sub_8105538(struct Sprite *);
extern void sub_81051C4(struct Sprite *);
extern void sub_81052A4(struct Sprite *);
extern void sub_81054E8(struct Sprite *);
extern void sub_8105C48(struct Sprite *);
extern void sub_8105DE8(struct Sprite *);
extern void sub_8105E60(struct Sprite *);
extern void sub_8106140(struct Sprite *);
extern void sub_81061C4(struct Sprite *);
extern void sub_810624C(struct Sprite *);
extern void sub_810673C(struct Sprite *);
extern void sub_8106878(struct Sprite *);
extern void sub_8106944(struct Sprite *);
extern void sub_81069B8(struct Sprite *);
extern void sub_81069D0(struct Sprite *);
extern void sub_8106AD0(struct Sprite *);
extern void sub_8106B54(struct Sprite *);
extern void sub_8106C80(struct Sprite *);
extern void sub_8106CD0(struct Sprite *);
extern void sub_8106E00(struct Sprite *);
extern void sub_8106F60(struct Sprite *);
extern void sub_8106F00(struct Sprite *);
extern void sub_81070AC(struct Sprite *);

const struct SpriteTemplate gUnknown_08593264 =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103448,
};

const union AnimCmd gUnknown_0859327C[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593284[] =
{
    gUnknown_0859327C,
};

const struct SpriteTemplate gUnknown_08593288 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103498,
};

const struct SpriteTemplate gUnknown_085932A0 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810358C,
};

extern const union AffineAnimCmd *const gUnknown_08597060[];
const struct SpriteTemplate gUnknown_085932B8 =
{
    .tileTag = ANIM_TAG_CLAMP,
    .paletteTag = ANIM_TAG_CLAMP,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597060,
    .callback = sub_8103620,
};

const union AnimCmd gUnknown_085932D0[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085932E4[] =
{
    gUnknown_085932D0,
};

const union AffineAnimCmd gUnknown_085932E8[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0x9, 0x9, 0, 18),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08593300[] =
{
    gUnknown_085932E8,
};

const struct SpriteTemplate gUnknown_08593304 =
{
    .tileTag = ANIM_TAG_UNUSED_EXPLOSION,
    .paletteTag = ANIM_TAG_UNUSED_EXPLOSION,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085932E4,
    .images = NULL,
    .affineAnims = gUnknown_08593300,
    .callback = sub_80A77C8,
};

const union AnimCmd gUnknown_0859331C[] =
{
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(24, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(40, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593340[] =
{
    gUnknown_0859331C,
};

const struct SpriteTemplate gUnknown_08593344 =
{
    .tileTag = ANIM_TAG_ALERT,
    .paletteTag = ANIM_TAG_ALERT,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_08593340,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81037D8,
};

const union AffineAnimCmd gUnknown_0859335C[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x14, 0x0, 0, 12),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859337C[] =
{
    gUnknown_0859335C,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8593380 =
{
    .tileTag = ANIM_TAG_SWORD,
    .paletteTag = ANIM_TAG_SWORD,
    .oam = &gUnknown_08524ADC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859337C,
    .callback = sub_810387C,
};

const struct SpriteTemplate gSonicBoomSpriteTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_AIR_WAVE,
    .oam = &gUnknown_08524B14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81038C8,
};

const struct SpriteTemplate gUnknown_085933B0 =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_AIR_WAVE,
    .oam = &gUnknown_08524A54,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103AA4,
};

const union AffineAnimCmd gUnknown_085933C8[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x7, 0x7, 0, -56),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085933E0[] =
{
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08593420[] =
{
    gUnknown_085933C8,
};

const union AffineAnimCmd *const gUnknown_08593424[] =
{
    gUnknown_085933E0,
};

const struct SpriteTemplate gSupersonicWaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_GOLD_RING,
    .oam = &gUnknown_08524A14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593420,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gScreechWaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_RING,
    .paletteTag = ANIM_TAG_PURPLE_RING,
    .oam = &gUnknown_08524A14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593420,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gUnknown_08593458 =
{
    .tileTag = ANIM_TAG_METAL_SOUND_WAVES,
    .paletteTag = ANIM_TAG_METAL_SOUND_WAVES,
    .oam = &gUnknown_08524A1C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593420,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gUnknown_08593470 =
{
    .tileTag = ANIM_TAG_BLUE_RING_2,
    .paletteTag = ANIM_TAG_BLUE_RING_2,
    .oam = &gUnknown_08524A14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593424,
    .callback = sub_8108C94,
};

const struct SpriteTemplate gUnknown_08593488 =
{
    .tileTag = ANIM_TAG_LARGE_FRESH_EGG,
    .paletteTag = ANIM_TAG_LARGE_FRESH_EGG,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A78AC,
};

const struct SpriteTemplate gUnknown_085934A0 =
{
    .tileTag = ANIM_TAG_UNUSED_VOID_LINES,
    .paletteTag = ANIM_TAG_UNUSED_VOID_LINES,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103FE8,
};

const union AnimCmd gUnknown_085934B8[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085934C0[] =
{
    gUnknown_085934B8,
};

const union AffineAnimCmd gUnknown_085934C4[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085934D4[] =
{
    gUnknown_085934C4,
};

const struct SpriteTemplate gUnknown_085934D8 =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_085934C0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8104088,
};

const struct SpriteTemplate gUnknown_085934F0 =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_085934C0,
    .images = NULL,
    .affineAnims = gUnknown_085934D4,
    .callback = sub_810413C,
};

const union AffineAnimCmd gUnknown_08593508[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08593518[] =
{
    gUnknown_08593508,
};

const struct SpriteTemplate gUnknown_0859351C =
{
    .tileTag = ANIM_TAG_SEED,
    .paletteTag = ANIM_TAG_SEED,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593518,
    .callback = sub_81041C4,
};

const union AffineAnimCmd gUnknown_08593534[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x0, 0, 40),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859354C[] =
{
    gUnknown_08593534,
};

const struct SpriteTemplate gUnknown_08593550 =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_GUST,
    .oam = &gUnknown_085249BC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859354C,
    .callback = sub_8104304,
};

const union AnimCmd gUnknown_08593568[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 20),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08593578[] =
{
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 20, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593588[] =
{
    gUnknown_08593568,
    gUnknown_08593578,
};

const struct SpriteTemplate gUnknown_08593590 =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_08593588,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8104364,
};

const union AnimCmd gUnknown_085935A8[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085935B8[] =
{
    ANIMCMD_FRAME(0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 1, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085935C8[] =
{
    gUnknown_085935A8,
    gUnknown_085935B8,
};

const struct SpriteTemplate gUnknown_085935D0 =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_085935C8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8104414,
};

const union AffineAnimCmd gUnknown_085935E8[] =
{
    AFFINEANIMCMD_FRAME(-6, 4, 0, 8),
    AFFINEANIMCMD_FRAME(10, -10, 0, 8),
    AFFINEANIMCMD_FRAME(-4, 6, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593608[] =
{
    AFFINEANIMCMD_FRAME(-4, -5, 0, 12),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(4, 5, 0, 12),
    AFFINEANIMCMD_END,
};

const union AnimCmd gUnknown_08593628[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 40, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(12, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859363C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 40),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593650[] =
{
    gUnknown_08593628,
    gUnknown_0859363C,
};

const struct SpriteTemplate gUnknown_08593658 =
{
    .tileTag = ANIM_TAG_BREATH,
    .paletteTag = ANIM_TAG_BREATH,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08593650,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8104B1C,
};

const union AffineAnimCmd gUnknown_08593670[] =
{
    AFFINEANIMCMD_FRAME(0xB, 0xB, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF5, 0xFFF5, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08593688[] =
{
    gUnknown_08593670,
};

const struct SpriteTemplate gUnknown_0859368C =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_ANGER,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593688,
    .callback = sub_8104BAC,
};

const union AffineAnimCmd gUnknown_085936A4[] =
{
    AFFINEANIMCMD_FRAME(-10, 9, 0, 7),
    AFFINEANIMCMD_FRAME(20, -20, 0, 7),
    AFFINEANIMCMD_FRAME(-20, 20, 0, 7),
    AFFINEANIMCMD_FRAME(10, -9, 0, 7),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085936D4 =
{
    .tileTag = ANIM_TAG_PENCIL,
    .paletteTag = ANIM_TAG_PENCIL,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810501C,
};

const struct SpriteTemplate gUnknown_085936EC =
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A7938,
};

const union AnimCmd gUnknown_08593704[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593718[] =
{
    gUnknown_08593704,
};
//*
const struct SpriteTemplate gBattleAnimSpriteTemplate_859371C =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593718,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AffineAnimCmd gUnknown_08593734[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 2),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 2),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08593754[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593764[] =
{
    AFFINEANIMCMD_FRAME(0xFFF8, 0x4, 0, 8),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x10, 0xFFF8, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF0, 0x8, 0, 8),
    AFFINEANIMCMD_LOOP(1),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085937A4[] =
{
    gUnknown_08593734,
    gUnknown_08593754,
    gUnknown_08593764,
};
//*
const struct SpriteTemplate gUnknown_085937B0 =
{
    .tileTag = ANIM_TAG_BREAKING_EGG,
    .paletteTag = ANIM_TAG_BREAKING_EGG,
    .oam = &gUnknown_08524AF4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085937A4,
    .callback = sub_8105538,
};

const union AffineAnimCmd gUnknown_085937C8[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 30),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gUnknown_085937E0[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 15),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gUnknown_085937F8[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0xB, 0xB, 0, 45),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gUnknown_08593810[] =
{
    gUnknown_085937C8,
    gUnknown_085937E0,
};

const union AffineAnimCmd *const gUnknown_08593818[] =
{
    gUnknown_085937F8,
};

const struct SpriteTemplate gUnknown_0859381C =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593810,
    .callback = sub_80A77C8,
};
//*
const union AffineAnimCmd gUnknown_08593834[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF0, 0xFFF0, 0, 30),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gUnknown_0859384C[] =
{
    gUnknown_08593834,
};

const struct SpriteTemplate gUnknown_08593850 =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859384C,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_08593868 =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593810,
    .callback = sub_81051C4,
};

const struct SpriteTemplate gUnknown_08593880 =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593818,
    .callback = sub_81052A4,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8593898 =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593810,
    .callback = sub_81054E8,
};

const union AffineAnimCmd gUnknown_085938B0[] =
{
    AFFINEANIMCMD_FRAME(96, -13, 0, 8),
    AFFINEANIMCMD_END,
};

const union AnimCmd gUnknown_085938C0[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085938D8[] =
{
    gUnknown_085938C0,
};

const struct SpriteTemplate gUnknown_085938DC =
{
    .tileTag = ANIM_TAG_SPEED_DUST,
    .paletteTag = ANIM_TAG_SPEED_DUST,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085938D8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8105C48,
};

const s8 gUnknown_085938F4[][2] =
{
    {30, 28},
    {-20, 24},
    {16, 26},
    {-10, 28},
};

const union AnimCmd gUnknown_085938FC[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 15, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593934[] =
{
    gUnknown_085938FC,
};

const struct SpriteTemplate gUnknown_08593938 =
{
    .tileTag = ANIM_TAG_BELL,
    .paletteTag = ANIM_TAG_BELL,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593934,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const u16 gUnknown_08593950[] =
{
    10206,
    9999,
    9998,
    0,
};

const struct SpriteTemplate gUnknown_08593958 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8105DE8,
};

const struct SpriteTemplate gUnknown_08593970 =
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_MAGENTA_HEART,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8105E60,
};

const union AffineAnimCmd gUnknown_08593988[] =
{
    AFFINEANIMCMD_FRAME(0x000A, 0xFFF3, 0x00, 0x0A),
    AFFINEANIMCMD_FRAME(0xFFF6, 0x000D, 0x00, 0x0A),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085939A0 =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106140,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85939B8 =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81061C4,
};

const struct SpriteTemplate gUnknown_085939D0 =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810624C,
};

const union AffineAnimCmd gUnknown_085939E8[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08593A00[] =
{
    gUnknown_085939E8,
};

const struct SpriteTemplate gHiddenPowerOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593A00,
    .callback = sub_810673C,
};

const struct SpriteTemplate gHiddenPowerOrbScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gUnknown_085249CC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593A00,
    .callback = sub_8106878,
};

const union AffineAnimCmd gUnknown_08593A34[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08593A4C[] =
{
    gUnknown_08593A34,
};

const struct SpriteTemplate gUnknown_08593A50 =
{
    .tileTag = ANIM_TAG_RED_ORB_2,
    .paletteTag = ANIM_TAG_RED_ORB_2,
    .oam = &gUnknown_085249C4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593A4C,
    .callback = sub_8106944,
};

const union AnimCmd gUnknown_08593A68[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593A80[] =
{
    gUnknown_08593A68,
};

const struct SpriteTemplate gUnknown_08593A84 =
{
    .tileTag = ANIM_TAG_EYE_SPARKLE,
    .paletteTag = ANIM_TAG_EYE_SPARKLE,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08593A80,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81069B8,
};

const union AnimCmd gUnknown_08593A9C[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593AA4[] =
{
    gUnknown_08593A9C,
};

const struct SpriteTemplate gUnknown_08593AA8 =
{
    .tileTag = ANIM_TAG_ANGEL,
    .paletteTag = ANIM_TAG_ANGEL,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593AA4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81069D0,
};

const struct SpriteTemplate gUnknown_08593AC0 =
{
    .tileTag = ANIM_TAG_PINK_HEART,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106AD0,
};

const union AnimCmd gUnknown_08593AD8[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08593AE0[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08593AE8[] =
{
    gUnknown_08593AD8,
    gUnknown_08593AE0,
};

const struct SpriteTemplate gUnknown_08593AF0 =
{
    .tileTag = ANIM_TAG_DEVIL,
    .paletteTag = ANIM_TAG_DEVIL,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593AE8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106B54,
};

const union AnimCmd gUnknown_08593B08[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08593B1C[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593B30[] =
{
    gUnknown_08593B08,
    gUnknown_08593B1C,
};

const struct SpriteTemplate gUnknown_08593B38 =
{
    .tileTag = ANIM_TAG_SWIPE,
    .paletteTag = ANIM_TAG_SWIPE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593B30,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106C80,
};

const union AnimCmd gUnknown_08593B50[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08593B64[] =
{
    ANIMCMD_FRAME(16, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593B78[] =
{
    gUnknown_08593B50,
    gUnknown_08593B64,
};

const struct SpriteTemplate gUnknown_08593B80 =
{
    .tileTag = ANIM_TAG_MOVEMENT_WAVES,
    .paletteTag = ANIM_TAG_MOVEMENT_WAVES,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593B78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106CD0,
};

const union AffineAnimCmd gUnknown_08593B98[] =
{
    AFFINEANIMCMD_FRAME(-12, 8, 0, 4),
    AFFINEANIMCMD_FRAME(20, -20, 0, 4),
    AFFINEANIMCMD_FRAME(-8, 12, 0, 4),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8593BB8 =
{
    .tileTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8106E00,
};

const union AffineAnimCmd gUnknown_08593BD0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 5),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593BE0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 16),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gUnknown_08593BF0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 16),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gUnknown_08593C00[] =
{
    gUnknown_08593BD0,
    gUnknown_08593BE0,
    gUnknown_08593BF0,
};

extern const union AnimCmd *const gUnknown_08592FCC[];
const struct SpriteTemplate gUnknown_08593C0C =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_08592FCC,
    .images = NULL,
    .affineAnims = gUnknown_08593C00,
    .callback = sub_8106F60,
};

const struct SpriteTemplate gUnknown_08593C24 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_08592FCC,
    .images = NULL,
    .affineAnims = gUnknown_08593C00,
    .callback = sub_8106F00,
};

const union AffineAnimCmd gUnknown_08593C3C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593C4C[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08593C5C[] =
{
    gUnknown_08593C3C,
    gUnknown_08593C4C,
};

const struct SpriteTemplate gUnknown_08593C64 =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gUnknown_08524B1C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08593C5C,
    .callback = sub_81070AC,
};
