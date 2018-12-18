#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "alloc.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/species.h"

void sub_815A0D4(struct Sprite *);
void sub_815A1B0(struct Sprite *);
void sub_815A254(struct Sprite *);
void sub_815A2F0(struct Sprite *);
void sub_815A6C4(struct Sprite *);
void sub_815A7B0(struct Sprite *);
void sub_815A7EC(struct Sprite *);
void sub_815A8AC(struct Sprite *);
void sub_815A934(struct Sprite *);
void sub_815AAA4(struct Sprite *);
void sub_815ABD0(struct Sprite *);
void sub_815ACD0(struct Sprite *);
void sub_815B27C(struct Sprite *);
void sub_815B394(struct Sprite *);
void sub_815B49C(struct Sprite *);
void sub_815B570(struct Sprite *);
void sub_815B70C(struct Sprite *);
void sub_815BE04(struct Sprite *);
void sub_815C400(struct Sprite *);
void sub_815C6B0(struct Sprite *);
void sub_815C95C(struct Sprite *);
void sub_815CB88(struct Sprite *);
void sub_815CC94(struct Sprite *);
void sub_815CDB4(struct Sprite *);
void sub_815D7B4(struct Sprite *);
void sub_815D870(struct Sprite *);
void sub_815DEBC(struct Sprite *);
void sub_815E01C(struct Sprite *);
void sub_815E404(struct Sprite *);
void sub_815E444(struct Sprite *);
void sub_815E6D8(struct Sprite *);
void sub_815E954(struct Sprite *);
void sub_815EA14(struct Sprite *);
void sub_815EE84(struct Sprite *);
void sub_815F18C(struct Sprite *);
void sub_815F48C(struct Sprite *);
void sub_815FE80(struct Sprite *);
void sub_81061C4(struct Sprite *);
void sub_8160338(struct Sprite *);
void sub_81603A8(struct Sprite *);

const union AnimCmd gUnknown_085CE004[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE01C[] =
{
    gUnknown_085CE004,
};

const struct SpriteTemplate gUnknown_085CE020 =
{
    .tileTag = ANIM_TAG_SCRATCH,
    .paletteTag = ANIM_TAG_SCRATCH,
    .oam = &gUnknown_08524A34,
    .anims = gUnknown_085CE01C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_085CE038 =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_BLACK_SMOKE,
    .oam = &gUnknown_08524934,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A0D4,
};

const struct SpriteTemplate gUnknown_085CE050 =
{
    .tileTag = ANIM_TAG_BLACK_BALL,
    .paletteTag = ANIM_TAG_BLACK_BALL,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A78AC,
};

const union AnimCmd gUnknown_085CE068[] =
{
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 40),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE078[] =
{
    gUnknown_085CE068,
};

const struct SpriteTemplate gUnknown_085CE07C =
{
    .tileTag = ANIM_TAG_OPENING_EYE,
    .paletteTag = ANIM_TAG_OPENING_EYE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE078,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const struct SpriteTemplate gUnknown_085CE094 =
{
    .tileTag = ANIM_TAG_ROUND_WHITE_HALO,
    .paletteTag = ANIM_TAG_ROUND_WHITE_HALO,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A1B0,
};

const struct SpriteTemplate gUnknown_085CE0AC =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_TEAL_ALERT,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A254,
};

const union AffineAnimCmd gUnknown_085CE0C4[] =
{
    AFFINEANIMCMD_FRAME(0x180, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, 0x18, 0, 5),
    AFFINEANIMCMD_FRAME(0x18, -0x20, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gUnknown_085CE0E4[] =
{
    AFFINEANIMCMD_FRAME(0x30, 0x30, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE0FC[] =
{
    gUnknown_085CE0C4,
    gUnknown_085CE0E4,
};

const struct SpriteTemplate gUnknown_085CE104 =
{
    .tileTag = ANIM_TAG_EYE,
    .paletteTag = ANIM_TAG_EYE,
    .oam = &gUnknown_08524AFC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE0FC,
    .callback = sub_815A2F0,
};

const struct SpriteTemplate gUnknown_085CE11C =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A6C4,
};

const union AnimCmd gUnknown_085CE134[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE14C[] =
{
    gUnknown_085CE134,
};

const struct SpriteTemplate gUnknown_085CE150 =
{
    .tileTag = ANIM_TAG_LEER,
    .paletteTag = ANIM_TAG_LEER,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE14C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815A7B0,
};

const union AnimCmd gUnknown_085CE168[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE170[] =
{
    gUnknown_085CE168,
};

const union AffineAnimCmd gUnknown_085CE174[] =
{
    AFFINEANIMCMD_FRAME(-7, -7, -3, 16),
    AFFINEANIMCMD_FRAME(7, 7, 3, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE18C[] =
{
    gUnknown_085CE174,
};

const struct SpriteTemplate gUnknown_085CE190 =
{
    .tileTag = ANIM_TAG_LETTER_Z,
    .paletteTag = ANIM_TAG_LETTER_Z,
    .oam = &gUnknown_08524974,
    .anims = gUnknown_085CE170,
    .images = NULL,
    .affineAnims = gUnknown_085CE18C,
    .callback = sub_815A7EC,
};

const union AnimCmd gUnknown_085CE1A8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 16),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE1BC[] =
{
    gUnknown_085CE1A8,
};

const union AffineAnimCmd gUnknown_085CE1C0[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, -0x20, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE1D8[] =
{
    gUnknown_085CE1C0,
};

const struct SpriteTemplate gUnknown_085CE1DC =
{
    .tileTag = ANIM_TAG_FANG_ATTACK,
    .paletteTag = ANIM_TAG_FANG_ATTACK,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_085CE1BC,
    .images = NULL,
    .affineAnims = gUnknown_085CE1D8,
    .callback = sub_815A8AC,
};

const union AffineAnimCmd gUnknown_085CE1F4[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x0, 0, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE20C[] =
{
    AFFINEANIMCMD_FRAME(0x140, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, 0x0, 0, 19),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE224[] =
{
    gUnknown_085CE1F4,
    gUnknown_085CE20C,
};

const struct SpriteTemplate gUnknown_085CE22C =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE224,
    .callback = sub_815A934,
};

const struct SpriteTemplate gUnknown_085CE244 =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815AAA4,
};

const struct SpriteTemplate gUnknown_085CE25C =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815ABD0,
};

const union AnimCmd gUnknown_085CE274[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085CE284[] =
{
    gUnknown_085CE274,
};

const struct SpriteTemplate gUnknown_085CE288 =
{
    .tileTag = ANIM_TAG_RAPID_SPIN,
    .paletteTag = ANIM_TAG_RAPID_SPIN,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085CE284,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815ACD0,
};

const union AffineAnimCmd gUnknown_085CE2A0[] =
{
    AFFINEANIMCMD_FRAME(-12, 8, 0, 4),
    AFFINEANIMCMD_FRAME(20, -20, 0, 4),
    AFFINEANIMCMD_FRAME(-8, 12, 0, 4),
    AFFINEANIMCMD_END,
};

const union AnimCmd gUnknown_085CE2C0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE2C8[] =
{
    gUnknown_085CE2C0,
};

const union AffineAnimCmd gUnknown_085CE2CC[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 5, 40),
    AFFINEANIMCMD_FRAME(0, 0, 10, 10),
    AFFINEANIMCMD_FRAME(0, 0, 15, 10),
    AFFINEANIMCMD_FRAME(0, 0, 20, 40),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE2F4[] =
{
    gUnknown_085CE2CC,
};

const struct SpriteTemplate gUnknown_085CE2F8 =
{
    .tileTag = ANIM_TAG_TRI_FORCE_TRIANGLE,
    .paletteTag = ANIM_TAG_TRI_FORCE_TRIANGLE,
    .oam = &gUnknown_085249DC,
    .anims = gUnknown_085CE2C8,
    .images = NULL,
    .affineAnims = gUnknown_085CE2F4,
    .callback = sub_815B27C,
};

const union AnimCmd gUnknown_085CE310[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE334[] =
{
    gUnknown_085CE310,
};

const struct SpriteTemplate gUnknown_085CE338 =
{
    .tileTag = ANIM_TAG_ECLIPSING_ORB,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE334,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AffineAnimCmd gUnknown_085CE350[] =
{
    AFFINEANIMCMD_FRAME(-12, 20, 0, 8),
    AFFINEANIMCMD_FRAME(12, -20, 0, 8),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE370 =
{
    .tileTag = ANIM_TAG_POKEBALL,
    .paletteTag = ANIM_TAG_POKEBALL,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B394,
};

const struct SpriteTemplate gUnknown_085CE388 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B49C,
};

const struct SpriteTemplate gUnknown_085CE3A0 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B570,
};

const union AffineAnimCmd gUnknown_085CE3B8[] =
{
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 12),
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_LOOP(1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE3E0[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(0, -18, 0, 6),
    AFFINEANIMCMD_FRAME(-18, -18, 0, 3),
    AFFINEANIMCMD_FRAME(0, 0, 0, 15),
    AFFINEANIMCMD_FRAME(4, 4, 0, 13),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE418 =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815B70C,
};

const union AffineAnimCmd gUnknown_085CE430[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(7, -30, 0, 6),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(-2, 3, 0, 20),
    AFFINEANIMCMD_END,
};

const s8 gUnknown_085CE460[] =
{
    0xE8, 
    0x18, 
    0xFC, 
    0x00,
};

const union AnimCmd gUnknown_085CE464[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE470[] =
{
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085CE478[] =
{
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE480[] =
{
    gUnknown_085CE464,
    gUnknown_085CE470,
    gUnknown_085CE478,
};

const struct SpriteTemplate gUnknown_085CE48C =
{
    .tileTag = ANIM_TAG_GREEN_STAR,
    .paletteTag = ANIM_TAG_GREEN_STAR,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085CE480,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815BE04,
};

const s8 gUnknown_085CE4A4[] =
{
    0x78,
    0x50,
    0x28,
    0x00,
};

const u8 gUnknown_085CE4A8[] =
{
    0,
    0,
    0,
    0,
    50,
};

const union AffineAnimCmd gUnknown_085CE4B0[] =
{
    AFFINEANIMCMD_FRAME(0, -15, 0, 7),
    AFFINEANIMCMD_FRAME(0, 15, 0, 7),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE4D0 =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_ANGER,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C400,
};

const union AnimCmd gUnknown_085CE4E8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE50C[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE530[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE538[] =
{
    gUnknown_085CE4E8,
    gUnknown_085CE50C,
    gUnknown_085CE530,
};

const struct SpriteTemplate gUnknown_085CE544 =
{
    .tileTag = ANIM_TAG_PINK_PETAL,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_085CE538,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C6B0,
};

const u16 gUnknown_085CE55C[] = INCBIN_U16("graphics/unknown/unknown_85CE55C.gbapal");

const union AnimCmd gUnknown_085CE57C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 9),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE58C[] =
{
    gUnknown_085CE57C,
};

const struct SpriteTemplate gUnknown_085CE590 =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_PAIN_SPLIT,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_085CE58C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815C95C,
};

const struct SpriteTemplate gUnknown_085CE5A8 =
{
    .tileTag = ANIM_TAG_CONFETTI,
    .paletteTag = ANIM_TAG_CONFETTI,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815CB88,
};

const struct SpriteTemplate gUnknown_085CE5C0 =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gUnknown_085249DC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE224,
    .callback = sub_815CC94,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85CE5D8 =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815CDB4,
};

const union AffineAnimCmd gUnknown_085CE5F0[] =
{
    AFFINEANIMCMD_FRAME(16, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, -3, 0, 16),
    AFFINEANIMCMD_FRAME(4, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(-5, 3, 0, 16),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE620[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE640[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE660[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE680[] =
{
    gUnknown_085CE620,
    gUnknown_085CE640,
    gUnknown_085CE660,
};

const struct SpriteTemplate gUnknown_085CE68C =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE680,
    .callback = sub_815D7B4,
};

const union AffineAnimCmd gUnknown_085CE6A4[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE6C4[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE6E4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_085CE704[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 10, 0, 30),
    AFFINEANIMCMD_FRAME(-8, -10, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE724[] =
{
    gUnknown_085CE6A4,
    gUnknown_085CE6C4,
    gUnknown_085CE6E4,
    gUnknown_085CE704,
};

const struct SpriteTemplate gUnknown_085CE734 =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gUnknown_085249D4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE724,
    .callback = sub_815D870,
};

const union AffineAnimCmd gUnknown_085CE74C[] =
{
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_FRAME(16, -16, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE76C =
{
    .tileTag = ANIM_TAG_SWEAT_DROP,
    .paletteTag = ANIM_TAG_SWEAT_DROP,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815DEBC,
};

const u16 gUnknown_085CE784[] = INCBIN_U16("graphics/battle_anims/sprites/effect.gbapal");

const union AnimCmd gUnknown_085CE7B4[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_085CE7C0[] =
{
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085CE7CC[] =
{
    gUnknown_085CE7B4,
    gUnknown_085CE7C0,
};

const struct SpriteTemplate gUnknown_085CE7D4 =
{
    .tileTag = ANIM_TAG_NOISE_LINE,
    .paletteTag = ANIM_TAG_NOISE_LINE,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085CE7CC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E01C,
};

const struct SpriteTemplate gUnknown_085CE7EC =
{
    .tileTag = ANIM_TAG_SMALL_RED_EYE,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E404,
};

const struct SpriteTemplate gUnknown_085CE804 =
{
    .tileTag = ANIM_TAG_PAW_PRINT,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E444,
};

const union AffineAnimCmd gUnknown_085CE81C[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE82C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE844[] =
{
    gUnknown_085CE81C,
    gUnknown_085CE82C,
};

const struct SpriteTemplate gUnknown_085CE84C =
{
    .tileTag = ANIM_TAG_RED_BALL,
    .paletteTag = ANIM_TAG_RED_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE844,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gUnknown_085CE864 =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E6D8,
};

const union AffineAnimCmd gUnknown_085CE87C[] =
{
    AFFINEANIMCMD_FRAME(0, -16, 0, 6),
    AFFINEANIMCMD_FRAME(0, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gUnknown_085CE894 =
{
    .tileTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .paletteTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815E954,
};

const struct SpriteTemplate gUnknown_085CE8AC =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815EA14,
};

const struct SpriteTemplate gUnknown_085CE8C4 =
{
    .tileTag = ANIM_TAG_MAGNIFYING_GLASS,
    .paletteTag = ANIM_TAG_MAGNIFYING_GLASS,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815EE84,
};

const struct SpriteTemplate gUnknown_085CE8DC =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815F18C,
};

const struct SpriteTemplate gUnknown_085CE8F4 =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81061C4,
};

const struct SpriteTemplate gUnknown_085CE90C =
{
    .tileTag = ANIM_TAG_X_SIGN,
    .paletteTag = ANIM_TAG_X_SIGN,
    .oam = &gUnknown_0852491C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815F48C,
};

const struct SpriteTemplate gUnknown_085CE924 =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gUnknown_08524914,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_815FE80,
};

const union AnimCmd gUnknown_085CE93C[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085CE948[] =
{
    gUnknown_085CE93C,
};

const union AffineAnimCmd gUnknown_085CE94C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085CE964[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085CE97C[] =
{
    gUnknown_085CE94C,
    gUnknown_085CE964,
};

const struct SpriteTemplate gUnknown_085CE984 =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_SLAM_HIT_2,
    .oam = &gUnknown_0852497C,
    .anims = gUnknown_085CE948,
    .images = NULL,
    .affineAnims = gUnknown_085CE97C,
    .callback = sub_8160338,
};

const union AffineAnimCmd gUnknown_085CE99C[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 64),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_085CE9AC[] =
{
    gUnknown_085CE99C,
};

const struct SpriteTemplate gUnknown_085CE9B0 =
{
    .tileTag = ANIM_TAG_RECYCLE,
    .paletteTag = ANIM_TAG_RECYCLE,
    .oam = &gUnknown_08524A9C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_085CE9AC,
    .callback = sub_81603A8,
};

const union AffineAnimCmd gUnknown_085CE9C8[] =
{
    AFFINEANIMCMD_FRAME(0, 16, 0, 4),
    AFFINEANIMCMD_FRAME(-2, 0, 0, 8),
    AFFINEANIMCMD_FRAME(0, 4, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(1, -5, 0, 16),
    AFFINEANIMCMD_END,
};
