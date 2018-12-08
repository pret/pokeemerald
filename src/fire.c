#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_8108EC8(struct Sprite *);
extern void sub_8108F08(struct Sprite *);
extern void sub_8108FBC(struct Sprite *);
extern void sub_8108F4C(struct Sprite *);
extern void sub_8109064(struct Sprite *);
extern void sub_810916C(struct Sprite *);
extern void TranslateAnimSpriteToTargetMonLocation(struct Sprite *);
extern void sub_8109198(struct Sprite *);
extern void sub_8109200(struct Sprite *);
extern void sub_810921C(struct Sprite *);
extern void sub_8109364(struct Sprite *);
extern void sub_81093A4(struct Sprite *);
extern void sub_80A8EE4(struct Sprite *);
extern void sub_81098EC(struct Sprite *);
extern void sub_8109A10(struct Sprite *);
extern void sub_8109AFC(struct Sprite *);
extern void sub_8109CB0(struct Sprite *);

const union AnimCmd gUnknown_08595340[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08595350[] =
{
    ANIMCMD_FRAME(16, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595360[] =
{
    gUnknown_08595340,
    gUnknown_08595350,
};

const struct SpriteTemplate gUnknown_08595368 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595360,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108EC8,
};

const struct SpriteTemplate gUnknown_08595380 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595360,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108F08,
};

const union AnimCmd gUnknown_08595398[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_FRAME(112, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085953BC[] =
{
    gUnknown_08595398,
};

const union AnimCmd gUnknown_085953C0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085953D8[] =
{
    gUnknown_085953C0,
};

const union AffineAnimCmd gUnknown_085953DC[] =
{
    AFFINEANIMCMD_FRAME(0x32, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x0, 0, 7),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085953F4[] =
{
    gUnknown_085953DC,
};

const struct SpriteTemplate gUnknown_085953F8 =
{
    .tileTag = ANIM_TAG_FIRE,
    .paletteTag = ANIM_TAG_FIRE,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085953BC,
    .images = NULL,
    .affineAnims = gUnknown_085953F4,
    .callback = sub_8108FBC,
};

const struct SpriteTemplate gUnknown_08595410 =
{
    .tileTag = ANIM_TAG_FIRE,
    .paletteTag = ANIM_TAG_FIRE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085953BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108FBC,
};

const struct SpriteTemplate gUnknown_08595428 =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085953D8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108F4C,
};

const struct SpriteTemplate gUnknown_08595440 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085953D8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108F4C,
};

const union AnimCmd gUnknown_08595458[] =
{
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595468[] =
{
    gUnknown_08595458,
};

const struct SpriteTemplate gUnknown_0859546C =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595468,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109064,
};

const union AffineAnimCmd gUnknown_08595484[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0x2, 0x2, 10, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gUnknown_0859549C[] =
{
    gUnknown_08595484,
};

const struct SpriteTemplate gUnknown_085954A0 =
{
    .tileTag = ANIM_TAG_SUNLIGHT,
    .paletteTag = ANIM_TAG_SUNLIGHT,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_0859549C,
    .callback = sub_810916C,
};

const union AnimCmd gUnknown_085954B8[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085954D0[] =
{
    gUnknown_085954B8,
};

const struct SpriteTemplate gEmberSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gEmberFlareSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109198,
};

const struct SpriteTemplate gUnknown_08595504 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109200,
};

const struct SpriteTemplate gUnknown_0859551C =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810921C,
};

const union AnimCmd gUnknown_08595534[] =
{
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595540[] =
{
    gUnknown_08595534,
};

const union AffineAnimCmd gUnknown_08595544[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595554[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0xA0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595564[] =
{
    gUnknown_08595544,
    gUnknown_08595554,
};

const struct SpriteTemplate gUnknown_0859556C =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595540,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109364,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8595584 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81093A4,
};

const struct SpriteTemplate gUnknown_0859559C =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085954D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A8EE4,
};

const struct SpriteTemplate gUnknown_085955B4 =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81098EC,
};

// gHeatedRockCoords
const s16 gUnknown_085955CC[][2] =
{
    {-2, -5},
    {-1, -1},
    { 3, -6},
    { 4, -2},
    { 2, -8},
    {-5, -5},
    { 4, -7},
};

const struct SpriteTemplate gUnknown_085955E8 =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109A10,
};

const union AnimCmd gUnknown_08595600[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08595614[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859561C[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595624[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859562C[] =
{
    gUnknown_08595600,
    gUnknown_08595614,
    gUnknown_0859561C,
    gUnknown_08595624,
};

const struct SpriteTemplate gUnknown_0859563C =
{
    .tileTag = ANIM_TAG_WISP_ORB,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_0859562C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109AFC,
};

const union AnimCmd gUnknown_08595654[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595668[] =
{
    gUnknown_08595654,
};

const struct SpriteTemplate gUnknown_0859566C =
{
    .tileTag = ANIM_TAG_WISP_FIRE,
    .paletteTag = ANIM_TAG_WISP_FIRE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_08595668,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8109CB0,
};

const s8 gUnknown_08595684[16] =
{
    -1, -1, 0, 1, 1, 0, 0, -1, -1, 1, 1, 0, 0, -1, 0, 1,
};

const s8 gUnknown_08595694[16] =
{
    -1, 0, 1, 0, -1, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, 1,
};

void sub_8108EC8(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = 0x3C;
    sprite->data[2] = 0x9;
    sprite->data[3] = 0x1E;
    sprite->data[4] = 0xFE00;

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);

    sprite->callback = sub_80A634C;
    sprite->callback(sprite);
}