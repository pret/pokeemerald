#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"

extern void sub_810B6C4(struct Sprite *);
extern void sub_810B8AC(struct Sprite *);
extern void sub_810B8EC(struct Sprite *);
extern void sub_810B974(struct Sprite *);
extern void sub_810BA24(struct Sprite *);
extern void sub_810BC94(struct Sprite *);
extern void sub_810BE48(struct Sprite *);
extern void sub_810BED0(struct Sprite *);
extern void sub_810C2F0(struct Sprite *);
extern void sub_810C560(struct Sprite *);
extern void sub_810CB58(struct Sprite *);
extern void sub_80A8EE4(struct Sprite *);
extern void unc_080B06FC(struct Sprite *);
extern void sub_810CD4C(struct Sprite *);

const union AnimCmd gUnknown_08595A48[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 5, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595A54[] =
{
    gUnknown_08595A48,
};

// unknown sprite template
const struct SpriteTemplate gUnknown_08595A58 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B6C4,
};

const union AnimCmd gUnknown_08595A70[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A78[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A80[] =
{
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A88[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A90[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A98[] =
{
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_FRAME(13, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595AA4[] =
{
    gUnknown_08595A70,
};

const union AnimCmd *const gUnknown_08595AA8[] =
{
    gUnknown_08595A78,
};

const union AnimCmd *const gUnknown_08595AAC[] =
{
    gUnknown_08595A80,
};

const union AnimCmd *const gUnknown_08595AB0[] =
{
    gUnknown_08595A88,
};

const union AnimCmd *const gUnknown_08595AB4[] =
{
    gUnknown_08595A90,
};

const union AnimCmd *const gUnknown_08595AB8[] =
{
    gUnknown_08595A98,
};

const union AffineAnimCmd gUnknown_08595ABC[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 40, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595ACC[] =
{
    gUnknown_08595ABC,
};

const struct SpriteTemplate gUnknown_08595AD0 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524B24,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595ACC,
    .callback = sub_810B8AC,
};

const struct SpriteTemplate gUnknown_08595AE8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A24,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B8AC,
};

const union AffineAnimCmd gUnknown_08595B00[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595B10[] =
{
    gUnknown_08595B00,
};

const struct SpriteTemplate gUnknown_08595B14 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524AC4,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B10,
    .callback = sub_810B8EC,
};

const struct SpriteTemplate gUnknown_08595B2C =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A24,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B8EC,
};

const union AffineAnimCmd gUnknown_08595B44[] =
{
    AFFINEANIMCMD_FRAME(0xCE, 0xCE, 0, 0),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595B64[] =
{
    gUnknown_08595B44,
};

const struct SpriteTemplate gUnknown_08595B68 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524AC4,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = sub_810B974,
};

const struct SpriteTemplate gUnknown_08595B80 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A84,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = sub_810B974,
};

const struct SpriteTemplate gUnknown_08595B98 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BA24,
};

const struct SpriteTemplate gUnknown_08595BB0 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08595AB4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BC94,
};

const struct SpriteTemplate gUnknown_08595BC8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BC94,
};

const union AnimCmd gUnknown_08595BE0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595C00[] =
{
    gUnknown_08595BE0,
};

const struct SpriteTemplate gUnknown_08595C04 =
{
    .tileTag = ANIM_TAG_ICE_SPIKES,
    .paletteTag = ANIM_TAG_ICE_SPIKES,
    .oam = &gUnknown_08524A64,
    .anims = gUnknown_08595C00,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BE48,
};

const union AnimCmd gUnknown_08595C1C[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595C28[] =
{
    gUnknown_08595C1C,
};

const struct SpriteTemplate gUnknown_08595C2C =
{
    .tileTag = ANIM_TAG_MIST_CLOUD,
    .paletteTag = ANIM_TAG_MIST_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BED0,
};

const struct SpriteTemplate gUnknown_08595C44 =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BED0,
};

const u8 gUnknown_08595C5C[] =
{
    0, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 7, 8, 8, 8, 9,
};

const struct SpriteTemplate gUnknown_08595C70 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810C2F0,
};

const u8 gUnknown_08595C88[] =
{
    0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5,
};

const struct SpriteTemplate gUnknown_08595C9C =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810C560,
};

const u8 gUnknown_08595CB4[][4] =
{
    {0x64, 0xE0, 0x01, 0x20},
    {0x55, 0xE0, 0x01, 0x00},
    {0xF2, 0xE0, 0x11, 0x10},
    {0x42, 0xE0, 0x21, 0x10},
    {0xB6, 0xE0, 0x31, 0x00},
    {0x3C, 0xE0, 0x01, 0x20},
    {0xD6, 0xE0, 0x11, 0x00},
    {0x71, 0xE0, 0x01, 0x10},
    {0xD2, 0xE0, 0x31, 0x10},
    {0x26, 0xE0, 0x21, 0x00},
};

const union AffineAnimCmd gUnknown_08595CDC[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595CEC[] =
{
    AFFINEANIMCMD_FRAME(0xF0, 0xF0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595CFC[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595D0C[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595D1C[] =
{
    gUnknown_08595CDC,
    gUnknown_08595CEC,
    gUnknown_08595CFC,
};

const union AffineAnimCmd *const gUnknown_08595D28[] =
{
    gUnknown_08595D0C,
};

const struct SpriteTemplate gUnknown_08595D2C =
{
    .tileTag = ANIM_TAG_HAIL,
    .paletteTag = ANIM_TAG_HAIL,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595D1C,
    .callback = sub_810CB58,
};

const struct SpriteTemplate gUnknown_08595D44 =
{
    .tileTag = ANIM_TAG_HAIL,
    .paletteTag = ANIM_TAG_HAIL,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595D28,
    .callback = sub_80A8EE4,
};

const union AnimCmd gUnknown_08595D5C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595D64[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595D78[] =
{
    gUnknown_08595D5C,
    gUnknown_08595D64,
};

const union AffineAnimCmd gUnknown_08595D80[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595D90[] =
{
    AFFINEANIMCMD_FRAME(0x118, 0x118, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DA0[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DB0[] =
{
    AFFINEANIMCMD_FRAME(0x180, 0x180, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DC0[] =
{
    AFFINEANIMCMD_FRAME(0x1C0, 0x1C0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595DD0[] =
{
    gUnknown_08595D80,
    gUnknown_08595D90,
    gUnknown_08595DA0,
    gUnknown_08595DB0,
    gUnknown_08595DC0,
};

const struct SpriteTemplate gUnknown_08595DE4 =
{
    .tileTag = ANIM_TAG_ICE_CHUNK,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08595D78,
    .images = NULL,
    .affineAnims = gUnknown_08595DD0,
    .callback = unc_080B06FC,
};

const struct SpriteTemplate gUnknown_08595DFC =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CD4C,
};
