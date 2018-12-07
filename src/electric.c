#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_810A1A8(struct Sprite *);
extern void sub_810A214(struct Sprite *);
extern void sub_810A274(struct Sprite *);
extern void sub_810A308(struct Sprite *);
extern void TranslateAnimSpriteToTargetMonLocation(struct Sprite *);
extern void sub_810A46C(struct Sprite *);
extern void sub_810A5BC(struct Sprite *);
extern void sub_810A628(struct Sprite *);
extern void sub_810A75C(struct Sprite *);
extern void sub_810A9DC(struct Sprite *);
extern void sub_810AA2C(struct Sprite *);
extern void sub_810ACD8(struct Sprite *);
extern void sub_810AD30(struct Sprite *);
extern void sub_810AD98(struct Sprite *);
extern void sub_810B1F0(struct Sprite *);
extern void sub_810B23C(struct Sprite *);
extern void sub_810B51C(struct Sprite *);

const union AnimCmd gUnknown_085956A4[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085956BC[] =
{
    gUnknown_085956A4,
};

const struct SpriteTemplate gUnknown_085956C0 =
{
    .tileTag = ANIM_TAG_LIGHTNING,
    .paletteTag = ANIM_TAG_LIGHTNING,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085956BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A1A8,
};

const union AffineAnimCmd gUnknown_085956D8[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 60),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085956F8[] =
{
    gUnknown_085956D8,
};

const struct SpriteTemplate gUnknown_085956FC =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085956F8,
    .callback = sub_810A214,
};

const union AnimCmd gUnknown_08595714[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595730[] =
{
    gUnknown_08595714,
};

const struct SpriteTemplate gUnknown_08595734 =
{
    .tileTag = ANIM_TAG_SHOCK,
    .paletteTag = ANIM_TAG_SHOCK,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595730,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A274,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_859574C =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A308,
};

const struct SpriteTemplate gUnknown_08595764 =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_BLACK_BALL_2,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const union AffineAnimCmd gUnknown_0859577C[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_0859578C[] =
{
    gUnknown_0859577C,
};

const struct SpriteTemplate gUnknown_08595790 =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859578C,
    .callback = sub_810A46C,
};

const union AnimCmd gUnknown_085957A8[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085957B8[] =
{
    gUnknown_085957A8,
};

const union AffineAnimCmd gUnknown_085957BC[] =
{
    AFFINEANIMCMD_FRAME(0xE8, 0xE8, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 10),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 10),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_085957DC[] =
{
    gUnknown_085957BC,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85957E0 =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085957B8,
    .images = NULL,
    .affineAnims = gUnknown_085957DC,
    .callback = sub_810A5BC,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85957F8 =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859578C,
    .callback = sub_810A628,
};

const struct SpriteTemplate gElectricitySpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A75C,
};

const struct SpriteTemplate gUnknown_08595828 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810A9DC,
};

const struct SpriteTemplate gUnknown_08595840 =
{
    .tileTag = ANIM_TAG_SPARK_H,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810AA2C,
};

const s8 gUnknown_08595858[][2] =
{
    { 58, -60},
    {-56, -36},
    {  8, -56},
    {-16,  56},
    { 58, -10},
    {-58,  10},
    { 48, -18},
    {-8,   56},
    { 16, -56},
    {-58, -42},
    { 58,  30},
    {-48,  40},
    { 12, -48},
    { 48, -12},
    {-56,  18},
    { 48,  48},
};

const union AnimCmd gUnknown_08595878[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859588C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085958A0[] =
{
    gUnknown_08595878,
    gUnknown_0859588C,
};

const struct SpriteTemplate gUnknown_085958A8 =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085958A0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const union AffineAnimCmd gUnknown_085958C0[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 60),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_LOOP(10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595900[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_JUMP(3),
};

const union AffineAnimCmd gUnknown_08595930[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 30),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595950[] =
{
    gUnknown_085958C0,
    gUnknown_08595900,
    gUnknown_08595930,
};

const struct SpriteTemplate gUnknown_0859595C =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810ACD8,
};

const union AnimCmd gUnknown_08595974[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595988[] =
{
    gUnknown_08595974,
};

const struct SpriteTemplate gUnknown_0859598C =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595988,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810AD30,
};

const struct SpriteTemplate gUnknown_085959A4 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810AD98,
};

const union AnimCmd gUnknown_085959BC[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959C4[] =
{
    ANIMCMD_FRAME(2, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959CC[] =
{
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085959D4[] =
{
    ANIMCMD_FRAME(6, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085959DC[] =
{
    gUnknown_085959BC,
    gUnknown_085959C4,
    gUnknown_085959CC,
    gUnknown_085959D4,
};

const union AffineAnimCmd gUnknown_085959EC[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085959FC[] =
{
    gUnknown_085959EC,
};

const struct SpriteTemplate gUnknown_08595A00 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524A04,
    .anims = gUnknown_085959DC,
    .images = NULL,
    .affineAnims = gUnknown_085959FC,
    .callback = sub_810B1F0,
};

const struct SpriteTemplate gUnknown_08595A18 =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595950,
    .callback = sub_810B23C,
};

const struct SpriteTemplate gUnknown_08595A30 =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B51C,
};
