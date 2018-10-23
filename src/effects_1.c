#include "global.h"
#include "battle_anim.h"

extern void sub_80FE840(struct Sprite *);
extern void sub_80FE8E0(struct Sprite *);
extern void sub_80FE930(struct Sprite *);
extern void sub_80FE988(struct Sprite *);
extern void sub_80FEAD8(struct Sprite *);
extern void sub_80FEB44(struct Sprite *);
extern void sub_80FEC48(struct Sprite *);
extern void sub_80FED28(struct Sprite *);
extern void sub_80FEE78(struct Sprite *);
extern void sub_80FEF44(struct Sprite *);
extern void sub_80FEFFC(struct Sprite *);
extern void sub_80FF268(struct Sprite *);
extern void sub_80FF0F4(struct Sprite *);
extern void sub_80FF374(struct Sprite *);
extern void sub_80FF698(struct Sprite *);

const union AnimCmd gUnknown_085920F0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08592114[] =
{
    gUnknown_085920F0,
};

const struct SpriteTemplate gSleepPowderParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLEEP_POWDER,
    .paletteTag = ANIM_TAG_SLEEP_POWDER,
    .oam = &gUnknown_08524944,
    .anims = gUnknown_08592114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FE840,
};

const struct SpriteTemplate gStunSporeParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_STUN_SPORE,
    .paletteTag = ANIM_TAG_STUN_SPORE,
    .oam = &gUnknown_08524944,
    .anims = gUnknown_08592114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FE840,
};

const struct SpriteTemplate gPoisonPowderParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_POWDER,
    .paletteTag = ANIM_TAG_POISON_POWDER,
    .oam = &gUnknown_08524944,
    .anims = gUnknown_08592114,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FE840,
};

const union AnimCmd gUnknown_08592160[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592168[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592170[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592178[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592180[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592188[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592190[] =
{
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592198[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085921A0[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085921A8[] =
{
    gUnknown_08592160,
    gUnknown_08592168,
    gUnknown_08592170,
    gUnknown_08592178,
    gUnknown_08592180,
    gUnknown_08592188,
    gUnknown_08592190,
};

const union AnimCmd *const gUnknown_085921C4[] =
{
    gUnknown_08592198,
};

const union AnimCmd *const gUnknown_085921C8[] =
{
    gUnknown_085921A0,
};

const union AffineAnimCmd gUnknown_085921CC[] = {
    AFFINEANIMCMD_FRAME(-5, -5, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085921DC[] = {
    gUnknown_085921CC,
};

const struct SpriteTemplate gUnknown_085921E0 =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_085921C8,
    .images = NULL,
    .affineAnims = gUnknown_085921DC,
    .callback = sub_80FE8E0,
};

const struct SpriteTemplate gUnknown_085921F8 =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085921A8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FE930,
};

const struct SpriteTemplate gUnknown_08592210 =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085921C4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FE988,
};

const union AffineAnimCmd gUnknown_08592228[] = {
    AFFINEANIMCMD_FRAME(320, 320, 0, 0),
    AFFINEANIMCMD_FRAME(-14, -14, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08592240[] = {
    gUnknown_08592228,
};

const struct SpriteTemplate gUnknown_08592244 =
{
    .tileTag = ANIM_TAG_GRAY_ORB,
    .paletteTag = ANIM_TAG_GRAY_ORB,
    .oam = &gUnknown_085249C4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08592240,
    .callback = sub_80FE8E0,
};

const union AffineAnimCmd gUnknown_0859225C[] = {
    AFFINEANIMCMD_FRAME(-5, -5, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_0859226C[] = {
    gUnknown_0859225C,
};

const struct SpriteTemplate gUnknown_08592270 =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_085921C8,
    .images = NULL,
    .affineAnims = gUnknown_0859226C,
    .callback = sub_80FEAD8,
};

const struct SpriteTemplate gUnknown_08592288 =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085921A8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FEB44,
};

const union AnimCmd gUnknown_085922A0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085922A8[] =
{
    ANIMCMD_FRAME(4, 7),
    ANIMCMD_FRAME(8, 7),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085922B4[] =
{
    gUnknown_085922A0,
    gUnknown_085922A8,
};

const struct SpriteTemplate gLeechSeedSpriteTemplate =
{
    .tileTag = ANIM_TAG_SEED,
    .paletteTag = ANIM_TAG_SEED,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085922B4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FEC48,
};

const union AnimCmd gUnknown_085922D4[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085922DC[] =
{
    ANIMCMD_FRAME(4, 7),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085922E4[] =
{
    gUnknown_085922D4,
    gUnknown_085922DC,
};

const struct SpriteTemplate gUnknown_085922EC =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085922E4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FED28,
};

const union AnimCmd gUnknown_08592304[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859230C[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592314[] =
{
    gUnknown_08592304,
};

const union AnimCmd *const gUnknown_08592318[] =
{
    gUnknown_0859230C,
};

const struct SpriteTemplate gUnknown_0859231C =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592314,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FEE78,
};

const struct SpriteTemplate gUnknown_08592334 =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08592318,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FEF44,
};

const union AnimCmd gUnknown_0859234C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08592378[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_FRAME(28, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592388[] =
{
    gUnknown_0859234C,
    gUnknown_08592378,
};

const struct SpriteTemplate gUnknown_08592390 =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592388,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FEFFC,
};

const struct SpriteTemplate gUnknown_085923A8 =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592388,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FF268,
};

const union AnimCmd gUnknown_085923C0[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085923D4[] =
{
    gUnknown_085923C0,
};

const struct SpriteTemplate gUnknown_085923D8 =
{
    .tileTag = ANIM_TAG_RAZOR_LEAF,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085923D4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FF0F4,
};

const union AffineAnimCmd gUnknown_085923F0[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08592400[] = {
    gUnknown_085923F0,
};

const struct SpriteTemplate gSwiftStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08592400,
    .callback = sub_80FF0F4,
};

const union AnimCmd gUnknown_0859241C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(96, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592430[] =
{
    ANIMCMD_FRAME(0,  4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592444[] =
{
    gUnknown_0859241C,
    gUnknown_08592430,
};

const union AffineAnimCmd gUnknown_0859244C[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-11, 0, 0, 6),
    AFFINEANIMCMD_FRAME(11, 0, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859246C[] = {
    AFFINEANIMCMD_FRAME(-256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(11, 0, 0, 6),
    AFFINEANIMCMD_FRAME(-11, 0, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859248C[] = {
    gUnknown_0859244C,
    gUnknown_0859246C,
};

const struct SpriteTemplate gUnknown_08592494 =
{
    .tileTag = ANIM_TAG_TENDRILS,
    .paletteTag = ANIM_TAG_TENDRILS,
    .oam = &gUnknown_0852499C,
    .anims = gUnknown_08592444,
    .images = NULL,
    .affineAnims = gUnknown_0859248C,
    .callback = sub_80FF374,
};

const union AffineAnimCmd gUnknown_085924AC[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 0),
    AFFINEANIMCMD_FRAME(48, 48, 0, 14),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085924C4[] = {
    AFFINEANIMCMD_FRAME(-16, -16, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085924D4[] = {
    gUnknown_085924AC,
    gUnknown_085924C4,
};

const struct SpriteTemplate gUnknown_085924DC =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_085921C8,
    .images = NULL,
    .affineAnims = gUnknown_085924D4,
    .callback = sub_80FF698,
};

















































