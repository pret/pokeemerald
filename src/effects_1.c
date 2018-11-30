#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

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
extern void AnimMoveTwisterParticle(struct Sprite *);
extern void sub_80FF0F4(struct Sprite *);
extern void sub_80FF374(struct Sprite *);
extern void sub_80FF698(struct Sprite *);
extern void sub_80FF768(struct Sprite *);
extern void sub_80FF7EC(struct Sprite *);
extern void sub_80FF934(struct Sprite *);
extern void sub_80FFB18(struct Sprite *);
extern void sub_80FFBF4(struct Sprite *);
extern void sub_80FFC70(struct Sprite *);
extern void sub_80FFCB4(struct Sprite *);
extern void sub_80FFDBC(struct Sprite *);
extern void sub_8100640(struct Sprite *);
extern void sub_8100898(struct Sprite *);
extern void sub_8100A50(struct Sprite *);
extern void sub_81009F8(struct Sprite *);
extern void sub_8100A94(struct Sprite *);
extern void sub_8100AE0(struct Sprite *);
extern void sub_8100B88(struct Sprite *);
extern void sub_8100E1C(struct Sprite *);
extern void sub_8100EF0(struct Sprite *);
extern void sub_81010CC(struct Sprite *);
extern void sub_810130C(struct Sprite *);
extern void sub_810135C(struct Sprite *);
extern void sub_8101440(struct Sprite *);
extern void sub_81014F4(struct Sprite *);
extern void sub_81015AC(struct Sprite *);
extern void sub_8101898(struct Sprite *);
extern void sub_8101940(struct Sprite *);
extern void sub_8101B90(struct Sprite *);
extern void sub_8101F40(struct Sprite *);
extern void sub_8101FA8(struct Sprite *);
extern void sub_8101FF0(struct Sprite *);
extern void sub_81020D8(struct Sprite *);
extern void sub_810217C(struct Sprite *);
extern void TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite);
extern void sub_80A77C8(struct Sprite *);
extern void sub_8102268(struct Sprite *);
extern void sub_810234C(struct Sprite *);
extern void sub_81024E0(struct Sprite *);
extern void sub_8102540(struct Sprite *);
extern void sub_80A77C8(struct Sprite *);
extern void sub_8102844(struct Sprite *);
extern void sub_8102BCC(struct Sprite *);
extern void sub_8102CD4(struct Sprite *);
extern void sub_8102EB0(struct Sprite *);
extern void sub_8102FB8(struct Sprite *);
extern void sub_8103028(struct Sprite *);
extern void sub_8103164(struct Sprite *);
extern void sub_8103208(struct Sprite *);
extern void sub_8103284(struct Sprite *);
extern void sub_8103390(struct Sprite *);

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
    .callback = AnimMoveTwisterParticle,
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

const union AnimCmd gUnknown_085924F4[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_FRAME(48, 7),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592508[] =
{
    ANIMCMD_FRAME(0, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 7, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859251C[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859252C[] =
{
    ANIMCMD_FRAME(0, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 7, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859253C[] =
{
    gUnknown_085924F4,
    gUnknown_08592508,
    gUnknown_0859251C,
    gUnknown_0859252C,
};

const struct SpriteTemplate gUnknown_0859254C =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_0859253C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FF768,
};

const struct SpriteTemplate gUnknown_08592564 =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_0859253C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FF7EC,
};

const union AnimCmd gUnknown_0859257C[] =
{
    ANIMCMD_FRAME(3, 3),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08592588[] =
{
    gUnknown_0859257C,
};

const struct SpriteTemplate gUnknown_0859258C =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08592588,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FF934,
};

const union AnimCmd gUnknown_085925A4[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085925AC[] =
{
    gUnknown_085925A4,
};

const union AffineAnimCmd gUnknown_085925B0[] = {
    AFFINEANIMCMD_FRAME(0, 0, -4, 10),
    AFFINEANIMCMD_FRAME(0, 0, 4, 20),
    AFFINEANIMCMD_FRAME(0, 0, -4, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085925D0[] = {
    AFFINEANIMCMD_FRAME(0, 0, -1, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 1, 2),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08592608[] = {
    gUnknown_085925B0,
    gUnknown_085925D0,
};

const struct SpriteTemplate gUnknown_08592610 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085925AC,
    .images = NULL,
    .affineAnims = gUnknown_08592608,
    .callback = sub_80FFB18,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8592628 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085925AC,
    .images = NULL,
    .affineAnims = gUnknown_08592608,
    .callback = sub_80FFBF4,
};

const union AnimCmd gUnknown_08592640[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592654[] =
{
    gUnknown_08592640,
};

const struct SpriteTemplate gUnknown_08592658 =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592654,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80FFC70,
};

const struct SpriteTemplate gUnknown_08592670 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085925AC,
    .images = NULL,
    .affineAnims = gUnknown_08592608,
    .callback = sub_80FFCB4,
};

const union AffineAnimCmd gUnknown_08592688[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 3),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08592698[] = {
    AFFINEANIMCMD_FRAME(0, -10, 0, 3),
    AFFINEANIMCMD_FRAME(0, -6, 0, 3),
    AFFINEANIMCMD_FRAME(0, -2, 0, 3),
    AFFINEANIMCMD_FRAME(0, 0, 0, 3),
    AFFINEANIMCMD_FRAME(0, 2, 0, 3),
    AFFINEANIMCMD_FRAME(0, 6, 0, 3),
    AFFINEANIMCMD_FRAME(0, 10, 0, 3),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085926D8[] = {
    gUnknown_08592688,
    gUnknown_08592698,
    gUnknown_085925B0,
    gUnknown_085925D0,
};

const struct SpriteTemplate gUnknown_085926E8 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085925AC,
    .images = NULL,
    .affineAnims = gUnknown_085926D8,
    .callback = sub_80FFDBC,
};

const s8 gUnknown_08592700[][3] =
{
    {5, 24,   1},
    {0,  4,   0},
    {8, 16,  -1},
    {0,  2,   0},
    {8, 16,   1},
    {0,  2,   0},
    {8, 16,   1},
    {0,  2,   0},
    {8, 16,   1},
    {0, 16,   0},
    {0,  0, 127},
};

const union AnimCmd gUnknown_08592724[] =
{
    ANIMCMD_FRAME(28, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859272C[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592734[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859273C[] =
{
    ANIMCMD_FRAME(28, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592744[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859274C[] =
{
    ANIMCMD_FRAME(16, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592754[] =
{
    ANIMCMD_FRAME(28, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859275C[] =
{
    gUnknown_08592724,
    gUnknown_0859272C,
    gUnknown_08592734,
    gUnknown_0859273C,
    gUnknown_08592744,
    gUnknown_0859274C,
    gUnknown_08592754,
};

const struct SpriteTemplate gUnknown_08592778 =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_0859275C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const union AffineAnimCmd gUnknown_08592790[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_085927A8[] = {
    gUnknown_08592790,
};

const struct SpriteTemplate gUnknown_085927AC =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08592318,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100640,
};

const struct SpriteTemplate gUnknown_085927C4 =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_08592314,
    .images = NULL,
    .affineAnims = gUnknown_085927A8,
    .callback = sub_8100640,
};

const union AffineAnimCmd gUnknown_085927DC[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_085927F4[] = {
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -12, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_0859280C[] = {
    AFFINEANIMCMD_FRAME(143, 143, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -15, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08592824[] = {
    gUnknown_085927DC,
};

const union AffineAnimCmd *const gUnknown_08592828[] = {
    gUnknown_085927F4,
};

const union AffineAnimCmd *const gUnknown_0859282C[] = {
    gUnknown_0859280C,
};

const struct SpriteTemplate gUnknown_08592830 =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08592824,
    .callback = sub_8100640,
};

const struct SpriteTemplate gUnknown_08592848 =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08592828,
    .callback = sub_8100640,
};

const struct SpriteTemplate gUnknown_08592860 =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859282C,
    .callback = sub_8100640,
};

// sMagicalLeafBlendColors
const u16 gUnknown_08592878[] =
{
    RGB(31, 0, 0),
    RGB(31, 19, 0),
    RGB(31, 31, 0),
    RGB(0, 31, 0),
    RGB(5, 14, 31),
    RGB(22, 10, 31),
    RGB(22, 21, 31),
};

const struct SpriteTemplate gUnknown_08592888 =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_GREEN_SPIKE,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100898,
};

const union AnimCmd gUnknown_085928A0[] =
{
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_FRAME(112, 6),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085928B4[] =
{
    ANIMCMD_FRAME(64, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(80, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(112, 6, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085928C8[] =
{
    gUnknown_085928A0,
    gUnknown_085928B4,
};

const struct SpriteTemplate gUnknown_085928D0 =
{
    .tileTag = ANIM_TAG_SLAM_HIT,
    .paletteTag = ANIM_TAG_SLAM_HIT,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085928C8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100A50,
};

const struct SpriteTemplate gUnknown_085928E8 =
{
    .tileTag = ANIM_TAG_WHIP_HIT,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085928C8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100A50,
};

const union AnimCmd gUnknown_08592900[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592918[] =
{
    gUnknown_08592900,
};

const struct SpriteTemplate gUnknown_0859291C =
{
    .tileTag = ANIM_TAG_UNUSED_HIT,
    .paletteTag = ANIM_TAG_UNUSED_HIT,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592918,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81009F8,
};

const struct SpriteTemplate gUnknown_08592934 =
{
    .tileTag = ANIM_TAG_UNUSED_HIT_2,
    .paletteTag = ANIM_TAG_UNUSED_HIT_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592918,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81009F8,
};

const union AffineAnimCmd gUnknown_0859294C[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859295C[] = {
    AFFINEANIMCMD_FRAME(256, 256, 32, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859296C[] = {
    AFFINEANIMCMD_FRAME(256, 256, 64, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859297C[] = {
    AFFINEANIMCMD_FRAME(256, 256, 96, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859298C[] = {
    AFFINEANIMCMD_FRAME(256, 256, -128, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0859299C[] = {
    AFFINEANIMCMD_FRAME(256, 256, -96, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085929AC[] = {
    AFFINEANIMCMD_FRAME(256, 256, -64, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085929BC[] = {
    AFFINEANIMCMD_FRAME(256, 256, -32, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085929CC[] = {
    gUnknown_0859294C,
    gUnknown_0859295C,
    gUnknown_0859296C,
    gUnknown_0859297C,
    gUnknown_0859298C,
    gUnknown_0859299C,
    gUnknown_085929AC,
    gUnknown_085929BC,
};

const struct SpriteTemplate gUnknown_085929EC =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085929CC,
    .callback = sub_8100A94,
};

const union AnimCmd gUnknown_08592A04[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592A18[] =
{
    gUnknown_08592A04,
};

const struct SpriteTemplate gCuttingSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_08592A18,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100AE0,
};

const struct SpriteTemplate gUnknown_08592A34 =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_08592A18,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100B88,
};

const union AnimCmd gUnknown_08592A4C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A54[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A5C[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A64[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A6C[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A74[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A7C[] =
{
    ANIMCMD_FRAME(0, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A84[] =
{
    ANIMCMD_FRAME(4, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A8C[] =
{
    ANIMCMD_FRAME(8, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592A94[] =
{
    ANIMCMD_FRAME(12, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592A9C[] =
{
    gUnknown_08592A4C,
    gUnknown_08592A54,
    gUnknown_08592A5C,
    gUnknown_08592A64,
    gUnknown_08592A6C,
    gUnknown_08592A74,
    gUnknown_08592A7C,
    gUnknown_08592A84,
    gUnknown_08592A8C,
    gUnknown_08592A94,
};

const struct SpriteTemplate gUnknown_08592AC4 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592A9C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100E1C,
};

const struct SpriteTemplate gUnknown_08592ADC =
{
    .tileTag = ANIM_TAG_PROTECT,
    .paletteTag = ANIM_TAG_PROTECT,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8100EF0,
};

const union AffineAnimCmd gUnknown_08592AF4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08592B04[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 12),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -2, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 12),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08592B34[] =
{
    gUnknown_08592AF4,
    gUnknown_08592B04,
};

const struct SpriteTemplate gUnknown_08592B3C =
{
    .tileTag = ANIM_TAG_MILK_BOTTLE,
    .paletteTag = ANIM_TAG_MILK_BOTTLE,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08592B34,
    .callback = sub_81010CC,
};

const union AnimCmd gUnknown_08592B54[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_FRAME(48, 7),
    ANIMCMD_FRAME(64, 7),
    ANIMCMD_FRAME(80, 7),
    ANIMCMD_FRAME(96, 7),
    ANIMCMD_FRAME(112, 7),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08592B78[] =
{
    gUnknown_08592B54,
};

const struct SpriteTemplate gUnknown_08592B7C =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SPARKLE_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592B78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810130C,
};

const struct SpriteTemplate gUnknown_08592B94 =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SPARKLE_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592B78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810135C,
};

const union AnimCmd gUnknown_08592BAC[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_FRAME(16, 26),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(24, 15),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592BD0[] =
{
    ANIMCMD_FRAME(0, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(12, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 26, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(24, 15, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592BF4[] =
{
    gUnknown_08592BAC,
    gUnknown_08592BD0,
};

const struct SpriteTemplate gUnknown_08592BFC =
{
    .tileTag = ANIM_TAG_UNUSED_BUBBLE_BURST,
    .paletteTag = ANIM_TAG_UNUSED_BUBBLE_BURST,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592BF4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101440,
};

const union AnimCmd gUnknown_08592C14[] =
{
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592C1C[] =
{
    gUnknown_08592C14,
};

const union AffineAnimCmd gUnknown_08592C20[] =
{
    AFFINEANIMCMD_FRAME(0x14, 0x14, -30, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 1, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08592C20_2[] =
{
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_LOOP(10),
};

const union AffineAnimCmd gUnknown_08592C50[] =
{
    AFFINEANIMCMD_FRAME(0x14, 0x14, 30, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, -1, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08592C50_2[] =
{
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 24),
    AFFINEANIMCMD_LOOP(10),
};

const union AffineAnimCmd *const gUnknown_08592C80[] =
{
    gUnknown_08592C20,
    gUnknown_08592C50,
};

const struct SpriteTemplate gUnknown_08592C88 =
{
    .tileTag = ANIM_TAG_LETTER_Z,
    .paletteTag = ANIM_TAG_LETTER_Z,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_08592C1C,
    .images = NULL,
    .affineAnims = gUnknown_08592C80,
    .callback = sub_81014F4,
};

const struct SpriteTemplate gUnknown_08592CA0 =
{
    .tileTag = ANIM_TAG_LOCK_ON,
    .paletteTag = ANIM_TAG_LOCK_ON,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81015AC,
};

const struct SpriteTemplate gUnknown_08592CB8 =
{
    .tileTag = ANIM_TAG_LOCK_ON,
    .paletteTag = ANIM_TAG_LOCK_ON,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101898,
};

const s8 gUnknown_08592CD0[][2] =
{
    { 64,  64},
    {  0, -64},
    {-64,  64},
    { 32, -32},
};

const struct SpriteTemplate gUnknown_08592CD8 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101940,
};

const struct SpriteTemplate gUnknown_08592CF0 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101B90,
};

const union AnimCmd gUnknown_08592D08[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592D1C[] =
{
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592D24[] =
{
    gUnknown_08592D08,
    gUnknown_08592D1C,
};

const struct SpriteTemplate gUnknown_08592D2C =
{
    .tileTag = ANIM_TAG_SLASH,
    .paletteTag = ANIM_TAG_SLASH,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592D24,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101F40,
};

const struct SpriteTemplate gUnknown_08592D44 =
{
    .tileTag = ANIM_TAG_SLASH_2,
    .paletteTag = ANIM_TAG_SLASH_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592D24,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101FA8,
};

const struct SpriteTemplate gUnknown_08592D5C =
{
    .tileTag = ANIM_TAG_SLASH_2,
    .paletteTag = ANIM_TAG_SLASH_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592D24,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8101FF0,
};

const union AnimCmd gUnknown_08592D74[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592D88[] =
{
    gUnknown_08592D74,
};

const struct SpriteTemplate gUnknown_08592D8C =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_FOCUS_ENERGY,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_08592D88,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81020D8,
};

const union AnimCmd gUnknown_08592DA4[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 18),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 18),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(64, 18),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(64, 54),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592DE0[] =
{
    gUnknown_08592DA4,
};

const struct SpriteTemplate gUnknown_08592DE4 =
{
    .tileTag = ANIM_TAG_SPHERE_TO_CUBE,
    .paletteTag = ANIM_TAG_SPHERE_TO_CUBE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592DE0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810217C,
};

const struct SpriteTemplate gUnknown_08592DFC =
{
    .tileTag = ANIM_TAG_BLACK_BALL,
    .paletteTag = ANIM_TAG_BLACK_BALL,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const union AnimCmd gUnknown_08592E14[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592E2C[] =
{
    gUnknown_08592E14,
};

const struct SpriteTemplate gUnknown_08592E30 =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_GRAY_SMOKE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592E2C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AnimCmd gUnknown_08592E48[] =
{
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592E5C[] =
{
    gUnknown_08592E48,
};

const union AffineAnimCmd gUnknown_08592E60[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08592E70[] =
{
    gUnknown_08592E60,
};

const struct SpriteTemplate gUnknown_08592E74 =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_CONVERSION,
    .oam = &gUnknown_08524AE4,
    .anims = gUnknown_08592E5C,
    .images = NULL,
    .affineAnims = gUnknown_08592E70,
    .callback = sub_8102268,
};

const union AnimCmd gUnknown_08592E8C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592EA0[] =
{
    gUnknown_08592E8C,
};

const struct SpriteTemplate gUnknown_08592EA4 =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_CONVERSION,
    .oam = &gUnknown_08524AE4,
    .anims = gUnknown_08592EA0,
    .images = NULL,
    .affineAnims = gUnknown_08592E70,
    .callback = sub_810234C,
};

const struct SpriteTemplate gUnknown_08592EBC =
{
    .tileTag = ANIM_TAG_MOON,
    .paletteTag = ANIM_TAG_MOON,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81024E0,
};

const union AnimCmd gUnknown_08592ED4[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08592EE8[] =
{
    gUnknown_08592ED4,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8592EEC =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08592EE8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8102540,
};

const union AnimCmd gUnknown_08592F04[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592F28[] =
{
    gUnknown_08592F04,
};

const struct SpriteTemplate gUnknown_08592F2C =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_BLUE_STAR,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592F28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_08592F44 =
{
    .tileTag = ANIM_TAG_HORN_HIT,
    .paletteTag = ANIM_TAG_HORN_HIT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8102844,
};

const union AnimCmd gUnknown_08592F5C[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592F70[] =
{
    gUnknown_08592F5C,
};

const struct SpriteTemplate gUnknown_08592F74 =
{
    .tileTag = ANIM_TAG_FANG_ATTACK,
    .paletteTag = ANIM_TAG_FANG_ATTACK,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08592F70,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8102BCC,
};

const union AnimCmd gUnknown_08592F8C[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592F94[] =
{
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592F9C[] =
{
    ANIMCMD_FRAME(8, 41),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592FA4[] =
{
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592FAC[] =
{
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592FB4[] =
{
    ANIMCMD_FRAME(20, 10),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592FBC[] =
{
    ANIMCMD_FRAME(0, 10, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08592FC4[] =
{
    ANIMCMD_FRAME(4, 10, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08592FCC[] =
{
    gUnknown_08592F8C,
    gUnknown_08592F94,
    gUnknown_08592F9C,
    gUnknown_08592FA4,
    gUnknown_08592FAC,
    gUnknown_08592FB4,
    gUnknown_08592FBC,
    gUnknown_08592FC4,
};

const union AffineAnimCmd gUnknown_08592FEC[] =
{
    AFFINEANIMCMD_FRAME(0xC, 0xC, 0, 16),
    AFFINEANIMCMD_FRAME(0xFFF4, 0xFFF4, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08593004[] =
{
    gUnknown_08592FEC,
};

const struct SpriteTemplate gUnknown_08593008 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08592FCC,
    .images = NULL,
    .affineAnims = gUnknown_08593004,
    .callback = sub_8102CD4,
};

const u16 gUnknown_08593020[][6] =
{
    {10072, RGB(31, 31, 31), RGB(31, 26, 28), RGB(31, 22, 26), RGB(31, 17, 24), RGB(31, 13, 22)},
    {10097, RGB(31, 31, 31), RGB(25, 31, 26), RGB(20, 31, 21), RGB(15, 31, 16), RGB(10, 31, 12)},
    {10185, RGB(31, 31, 31), RGB(31, 31, 24), RGB(31, 31, 17), RGB(31, 31, 10), RGB(31, 31, 3)},
    {10175, RGB(31, 31, 31), RGB(26, 28, 31), RGB(21, 26, 31), RGB(16, 24, 31), RGB(12, 22, 31)},
};

const struct SpriteTemplate gUnknown_08593050 =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08592FCC,
    .images = NULL,
    .affineAnims = gUnknown_08593004,
    .callback = sub_8102EB0,
};

const struct SpriteTemplate gUnknown_08593068 =
{
    .tileTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
    .paletteTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8102FB8,
};

const union AffineAnimCmd gUnknown_08593080[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0xA0, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_08593098[] =
{
    gUnknown_08593080,
};

const struct SpriteTemplate gUnknown_0859309C =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08592FCC,
    .images = NULL,
    .affineAnims = gUnknown_08593098,
    .callback = sub_8103028,
};

const union AnimCmd gUnknown_085930B4[] =
{
    ANIMCMD_FRAME(0, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085930C8[] =
{
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085930DC[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085930F0[] =
{
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08593104[] =
{
    gUnknown_085930B4,
    gUnknown_085930DC,
    gUnknown_085930C8,
    gUnknown_085930F0,
};

const struct SpriteTemplate gUnknown_08593114 =
{
    .tileTag = ANIM_TAG_THOUGHT_BUBBLE,
    .paletteTag = ANIM_TAG_THOUGHT_BUBBLE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08593104,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103164,
};

const union AffineAnimCmd gUnknown_0859312C[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x1E, 0x1E, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593144[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 11),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 11),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08593144_2[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(30, 30, 0, 8),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 11),
    AFFINEANIMCMD_FRAME(0, 0, -4, 11),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_FRAME(-30, -30, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085931B4[] =
{
    gUnknown_0859312C,
    gUnknown_08593144,
};

const struct SpriteTemplate gUnknown_085931BC =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gUnknown_085249D4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085931B4,
    .callback = sub_8103208,
};

const struct SpriteTemplate gUnknown_085931D4 =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085931B4,
    .callback = sub_8103284,
};

const union AnimCmd gUnknown_085931EC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085931F4[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085931FC[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859321C[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859323C[] =
{
    gUnknown_085931EC,
    gUnknown_085931F4,
    gUnknown_085931FC,
    gUnknown_0859321C,
};

const struct SpriteTemplate gUnknown_0859324C =
{
    .tileTag = ANIM_TAG_FINGER_2,
    .paletteTag = ANIM_TAG_FINGER_2,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_0859323C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8103390,
};

const struct SpriteTemplate gPowerOrbs_Float =
{
	.tileTag = ANIM_TAG_RED_ORB,
	.paletteTag = ANIM_TAG_RED_ORB,
	.oam = &gUnknown_0852490C,
	.anims = gUnknown_085922E4,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = sub_80FED28,
};
