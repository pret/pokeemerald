#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sound.h"
#include "util.h"
#include "task.h"
#include "trig.h"

static void sub_8108EC8(struct Sprite *);
static void sub_8108F08(struct Sprite *);
static void sub_8108F4C(struct Sprite *);
static void sub_8108FBC(struct Sprite *);
static void sub_8109028(struct Sprite *);
static void sub_8109064(struct Sprite *);
static void sub_81090D8(struct Sprite *);
static void sub_810916C(struct Sprite *);
static void AnimEmberFlare(struct Sprite *);
static void sub_8109200(struct Sprite *);
static void AnimFireRing(struct Sprite *);
static void AnimFireRingStep1(struct Sprite *);
static void AnimFireRingStep2(struct Sprite *);
static void AnimFireRingStep3(struct Sprite *);
static void UpdateFireRingCircleOffset(struct Sprite *);
static void AnimFireCross(struct Sprite *);
static void sub_81093A4(struct Sprite *);
static void sub_81093E4(struct Sprite *);
static void sub_810940C(struct Sprite *);
static void sub_81094D0(u8 taskId);
static void sub_81097B4(u8 spriteId, u8 taskId, u8 a3);
static void sub_81098EC(struct Sprite *);
static u16 sub_8109930(u8 spriteId);
static void sub_8109984(struct Sprite *sprite, s16 x, s16 y);
static void sub_81099A0(struct Sprite *);
static void sub_8109A10(struct Sprite *);
static void sub_8109A64(struct Sprite *);
static void sub_8109AFC(struct Sprite *);
static void sub_8109C4C(struct Sprite *);
static void sub_8109CB0(struct Sprite *);
static void sub_8109E2C(u8 taskId);

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
    .callback = AnimEmberFlare,
};

const union AnimCmd gIncinerateAnim1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gIncinerateAnims[] =
{
    gIncinerateAnim1,
};

const struct SpriteTemplate gIncinerateSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gUnknown_08524914,
    .anims = gIncinerateAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
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
    .callback = AnimFireRing,
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
    .callback = AnimFireCross,
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

static void sub_8108EC8(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = 0x3C;
    sprite->data[2] = 0x9;
    sprite->data[3] = 0x1E;
    sprite->data[4] = 0xFE00;

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);

    sprite->callback = TranslateSpriteInGrowingCircleOverDuration;
    sprite->callback(sprite);
}

static void sub_8108F08(struct Sprite *sprite)
{
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[3];

    sprite->callback = TranslateSpriteLinearFixedPoint;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void sub_8108F4C(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);

    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] = -gBattleAnimArgs[4];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] = gBattleAnimArgs[4];
    }

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = sub_8109028;
}

static void sub_8108FBC(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] = gBattleAnimArgs[4];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] = -gBattleAnimArgs[4];
    }

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = sub_8109028;
}

static void sub_8109028(struct Sprite *sprite)
{
    if (++sprite->data[0] < sprite->data[4])
    {
        sprite->pos2.x += sprite->data[2];
        sprite->pos2.y += sprite->data[3];
    }

    if (sprite->data[0] == sprite->data[1])
        DestroySpriteAndMatrix(sprite);
}

static void sub_8109064(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);

    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->subpriority = 8;
    }

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[6];
    sprite->data[5] = 0;

    sprite->callback = sub_81090D8;
}

static void sub_81090D8(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        if(sprite->data[5] > 10000)
            sprite->subpriority = 1;

        sprite->pos2.x = Sin(sprite->data[0], sprite->data[1] + (sprite->data[5] >> 8));
        sprite->pos2.y = Cos(sprite->data[0], sprite->data[1] + (sprite->data[5] >> 8));

        sprite->data[0] += sprite->data[2];
        sprite->data[5] += sprite->data[4];

        if (sprite->data[0] > 255)
            sprite->data[0] -= 256;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 256;

        sprite->data[3]--;
    }
    else
    {
        DestroySpriteAndMatrix(sprite);
    }
}

//sunlight
static void sub_810916C(struct Sprite *sprite)
{
    sprite->pos1.x = 0;
    sprite->pos1.y = 0;
    sprite->data[0] = 60;
    sprite->data[2] = 140;
    sprite->data[4] = 80;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

//fire 2

// Animates the secondary effect of MOVE_EMBER, where the flames grow and slide
// horizontally a bit.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x pixel offset
// arg 3: target y pixel offset
// arg 4: duration
// arg 5: ? (todo: something related to which mon the pixel offsets are based on)
// arg 6: ? (todo: something related to which mon the pixel offsets are based on)
static void AnimEmberFlare(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget)
        && (gBattleAnimAttacker == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)
            || gBattleAnimAttacker == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)))
            gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->callback = sub_80A7938;
    sprite->callback(sprite);
}

static void sub_8109200(struct Sprite *sprite)
{
    gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->callback = sub_80A7938;
}

// Animates the a fire sprite in the first-half of the MOVE_FIRE_BLAST
// animation.  The fire sprite first moves in a circle around the mon,
// and then it is translated towards the target mon, while still rotating.
// Lastly, it moves in a circle around the target mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wave offset
//void AnimFireRing(struct Sprite *sprite)
void AnimFireRing(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);

    sprite->data[7] = gBattleAnimArgs[2];
    sprite->data[0] = 0;

    sprite->callback = AnimFireRingStep1;
}

static void AnimFireRingStep1(struct Sprite *sprite)
{
    UpdateFireRingCircleOffset(sprite);

    if (++sprite->data[0] == 0x12)
    {
        sprite->data[0] = 0x19;
        sprite->data[1] = sprite->pos1.x;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->data[3] = sprite->pos1.y;
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);

        InitAnimLinearTranslation(sprite);

        sprite->callback = AnimFireRingStep2;
    }
}

static void AnimFireRingStep2(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        sprite->data[0] = 0;

        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;

        sprite->callback = AnimFireRingStep3;
        sprite->callback(sprite);
    }
    else
    {
        sprite->pos2.x += Sin(sprite->data[7], 28);
        sprite->pos2.y += Cos(sprite->data[7], 28);

        sprite->data[7] = (sprite->data[7] + 20) & 0xFF;
    }
}

static void AnimFireRingStep3(struct Sprite *sprite)
{
    UpdateFireRingCircleOffset(sprite);

    if (++sprite->data[0] == 0x1F)
        DestroyAnimSprite(sprite);
}

static void UpdateFireRingCircleOffset(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[7], 28);
    sprite->pos2.y = Cos(sprite->data[7], 28);

    sprite->data[7] = (sprite->data[7] + 20) & 0xFF;
}

// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
// arg 3: x delta
// arg 4: y delta
// AnimFireCross(struct Sprite *sprite)
static void AnimFireCross(struct Sprite *sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);

    sprite->callback = TranslateSpriteLinear;
}

static void sub_81093A4(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[3];

    sprite->invisible = TRUE;
    sprite->callback = WaitAnimForDuration;

    StoreSpriteCallbackInData6(sprite, sub_81093E4);
}

static void sub_81093E4(struct Sprite *sprite)
{
    sprite->invisible = FALSE;

    sprite->data[0] = sprite->data[1];
    sprite->data[1] = 0;

    sprite->callback = sub_810940C;
    sprite->callback(sprite);
}

static void sub_810940C(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->pos2.y = Cos(sprite->data[1], sprite->data[2] >> 8);

    sprite->data[1] = (sprite->data[1] + 10) & 0xFF;
    sprite->data[2] += 0xD0;

    if (--sprite->data[0] == -1)
        DestroyAnimSprite(sprite);
}

void sub_8109460(u8 taskId) // initialize animation task for Move_ERUPTION?
{
    struct Task *task = &gTasks[taskId];

    task->data[15] = GetAnimBattlerSpriteId(0);

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[4] = gSprites[task->data[15]].pos1.y;
    task->data[5] = GetBattlerSide(gBattleAnimAttacker);
    task->data[6] = 0;

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);

    task->func = sub_81094D0;
}

static void sub_81094D0(u8 taskId) // animate Move_ERUPTION?
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sub_80A805C(task, task->data[15], 0x100, 0x100, 0xE0, 0x200, 0x20);

        task->data[0]++;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;

            if (++task->data[2] & 0x1)
                gSprites[task->data[15]].pos2.x = 3;
            else
                gSprites[task->data[15]].pos2.x = -3;
        }

        if (task->data[5])
        {
            if (++task->data[3] > 4)
            {
                task->data[3] = 0;
                gSprites[task->data[15]].pos1.y++;
            }
        }

        if(!sub_80A80C8(task))
        {
            SetBattlerSpriteYOffsetFromYScale(task->data[15]);
            gSprites[task->data[15]].pos2.x = 0;

            task->data[1] = 0;
            task->data[2] = 0;
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[1] > 4)
        {
            if (task->data[5])
                sub_80A805C(task, task->data[15], 0xE0, 0x200, 0x180, 0xF0, 0x6);
            else
                sub_80A805C(task, task->data[15], 0xE0, 0x200, 0x180, 0xC0, 0x6);

            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (!sub_80A80C8(task))
        {
            sub_81097B4(task->data[15], taskId, 6);

            task->data[0]++;
        }
        break;
    case 4:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;

            if (++task->data[2] & 1)
                gSprites[task->data[15]].pos2.y += 3;
            else
                gSprites[task->data[15]].pos2.y -= 3;
        }

        if (++task->data[3] > 0x18)
        {
            if (task->data[5])
                sub_80A805C(task, task->data[15], 0x180, 0xF0, 0x100, 0x100, 0x8);
            else
                sub_80A805C(task, task->data[15], 0x180, 0xC0, 0x100, 0x100, 0x8);

            if (task->data[2] & 1)
                gSprites[task->data[15]].pos2.y -= 3;

            task->data[1] = 0;
            task->data[2] = 0;
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 5:
        if (task->data[5])
            gSprites[task->data[15]].pos1.y--;

        if (!sub_80A80C8(task))
        {
            gSprites[task->data[15]].pos1.y = task->data[4];
            ResetSpriteRotScale(task->data[15]);

            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 6:
        if (!task->data[6])
            DestroyAnimVisualTask(taskId);

        break;
    default:
    }
}

static void sub_81097B4(u8 spriteId, u8 taskId, u8 a3)
{
    u16 i, j;
    s8 sign;

    u16 y = sub_8109930(spriteId);
    u16 x = gSprites[spriteId].pos1.x;

    if(!GetBattlerSide(gBattleAnimAttacker))
    {
        x -= 0xC;
        sign = 1;
    }
    else
    {
        x += 0x10;
        sign = -1;
    }

    for (i = 0, j = 0; i <= 6; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_085955B4, x, y, 2);

        if (spriteId != 0x40)
        {
            gSprites[spriteId].oam.tileNum += j * 4 + 0x40;

            if (++j >= 5)
                j = 0;
            //gHeatedRockCoords
            sub_8109984(&gSprites[spriteId], gUnknown_085955CC[i][0] * sign, gUnknown_085955CC[i][1]);
            gSprites[spriteId].data[6] = taskId;
            gSprites[spriteId].data[7] = a3;

            gTasks[taskId].data[a3]++;
        }
    }
}

static void sub_81098EC(struct Sprite *sprite)
{
    sub_81099A0(sprite);

    if (sprite->invisible)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}

static u16 sub_8109930(u8 spriteId)
{
    u16 var1 = gSprites[spriteId].pos1.y + gSprites[spriteId].pos2.y + gSprites[spriteId].centerToCornerVecY;

    if (GetBattlerSide(gBattleAnimAttacker) == 0)
    {
        var1 = ((var1 << 16) + 0x4A0000) >> 16;
    }
    else
    {
        var1 = ((var1 << 16) + 0x2C0000) >> 16;
    }

    return var1;
}

static void sub_8109984(struct Sprite *sprite, s16 x, s16 y)
{
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = (u16)sprite->pos1.x * 8;
    sprite->data[3] = (u16)sprite->pos1.y * 8;
    sprite->data[4] = x * 8;
    sprite->data[5] = y * 8;
}

static void sub_81099A0(struct Sprite *sprite)
{
    int var1;
    if (++sprite->data[0] > 2)
    {
        sprite->data[0] = 0;
        ++sprite->data[1];
        var1 = (u16)sprite->data[1] * (u16)sprite->data[1];
        sprite->data[3] += var1;
    }

    sprite->data[2] += sprite->data[4];
    sprite->pos1.x = sprite->data[2] >> 3;
    sprite->data[3] += sprite->data[5];
    sprite->pos1.y = sprite->data[3] >> 3;

    if (sprite->pos1.x < -8 || sprite->pos1.x > 0xf8 || sprite->pos1.y < -8 || sprite->pos1.y > 120)
        sprite->invisible = TRUE;
}

static void sub_8109A10(struct Sprite *sprite)
{
    sprite->pos1.x = gBattleAnimArgs[0];
    sprite->pos1.y = gBattleAnimArgs[1];

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[3];

    sprite->oam.tileNum += gBattleAnimArgs[4] * 16;
    sprite->callback = sub_8109A64;
}

static void sub_8109A64(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->data[6] != 0)
        {
            sprite->data[6]--;
            return;
        }

        sprite->data[0]++;
        // fall through
    case 1:
        sprite->pos1.y += 8;
        if (sprite->pos1.y >= sprite->data[7])
        {
            sprite->pos1.y = sprite->data[7];
            sprite->data[0]++;
        }
        break;
    case 2:
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            if ((++sprite->data[2] & 1) != 0)
            {
                sprite->pos2.y = -3;
            }
            else
            {
                sprite->pos2.y = 3;
            }
        }

        if (++sprite->data[3] > 16)
        {
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

//wisp orb
static void sub_8109AFC(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        InitSpritePosToAnimAttacker(sprite, 0);
        StartSpriteAnim(sprite, gBattleAnimArgs[2]);
        sprite->data[7] = gBattleAnimArgs[2];

        if (GetBattlerSide(gBattleAnimAttacker) != 0)
        {
            sprite->data[4] = 4;
        }
        else
        {
            sprite->data[4] = -4;
        }

        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        sprite->data[0]++;
        break;
    case 1:
        sprite->data[1] += 192;
        if (GetBattlerSide(gBattleAnimAttacker) != 0)
        {
            sprite->pos2.y = -(sprite->data[1] >> 8);
        }
        else
        {
            sprite->pos2.y = sprite->data[1] >> 8;
        }

        sprite->pos2.x = Sin(sprite->data[2], sprite->data[4]);
        sprite->data[2] = (sprite->data[2] + 4) & 0xFF;

        if (++sprite->data[3] == 1)
        {
            sprite->data[3] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->pos2.x = Sin(sprite->data[2], sprite->data[4]);
        sprite->data[2] = (sprite->data[2] + 4) & 0xFF;

        if (++sprite->data[3] == 31)
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.y = 0;
            sprite->pos2.x = 0;

            sprite->data[0] = 256;
            sprite->data[1] = sprite->pos1.x;
            sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
            sprite->data[3] = sprite->pos1.y;
            sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);

            sub_80A6FD4(sprite);
            sprite->callback = sub_8109C4C;
        }
        break;
    }
}

static void sub_8109C4C(struct Sprite *sprite)
{
    s16 initialData5;
    s16 newData5;

    if (!AnimTranslateLinear(sprite))
    {
        sprite->pos2.x += Sin(sprite->data[5], 16);
        initialData5 = sprite->data[5];
        sprite->data[5] = (sprite->data[5] + 4) & 0xFF;
        newData5 = sprite->data[5];

        if ((initialData5 == 0 || initialData5 > 196) && newData5 > 0 && sprite->data[7] == 0)
        {
            PlaySE12WithPanning(SE_W172, gUnknown_02038440);
        }
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

//wisp fire
void sub_8109CB0(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->data[1] = gBattleAnimArgs[0];
        sprite->data[0] += 1;
    }

    sprite->data[3] += 0xC0 * 2;
    sprite->data[4] += 0xA0;

    sprite->pos2.x = Sin(sprite->data[1], sprite->data[3] >> 8);
    sprite->pos2.y = Cos(sprite->data[1], sprite->data[4] >> 8);

    sprite->data[1] = (sprite->data[1] + 7) & 0xFF;

    if (!IsContest())
    {
        if (sprite->data[1] < 64 || sprite->data[1] > 195)
            sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        else
            sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;
    }
    else
    {
        if (sprite->data[1] < 64 || sprite->data[1] > 195)
            sprite->subpriority = 0x1D;
        else
            sprite->subpriority = 0x1F;
    }

    if (++sprite->data[2] > 0x14)
        sprite->invisible ^= 1;

    if (sprite->data[2] == 0x1E)
        DestroyAnimSprite(sprite);
}

void sub_8109DBC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[12] = !GetBattlerSide(gBattleAnimAttacker) ? 1 : -1;
    task->data[13] = IsBattlerSpriteVisible(gBattleAnimTarget ^ 2) + 1;
    task->data[14] = GetAnimBattlerSpriteId(1);
    task->data[15] = GetAnimBattlerSpriteId(3);

    task->func = sub_8109E2C;
}

static void sub_8109E2C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
            task->data[10] += task->data[12] * 2;
            if (++task->data[1] >= 2)
            {
                task->data[1] = 0;
                task->data[2]++;
                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].pos2.x = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 16)
            {
                task->data[9] = 0;
                task->data[0]++;
            }
            break;
        case 1:
            if (++task->data[1] >= 5)
            {
                task->data[1] = 0;
                task->data[2]++;

                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].pos2.x = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 96)
            {
                task->data[9] = 0;
                task->data[0]++;
            }
            break;
        case 2:
            task->data[10] -= task->data[12] * 2;

            if (++task->data[1] >= 2)
            {
                task->data[1] = 0;
                task->data[2]++;

                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].pos2.x = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 16)
            {
                task->data[0]++;
            }
            break;
        case 3:
            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].pos2.x = 0;
            }

            DestroyAnimVisualTask(taskId);
            break;
    }
}

// Used to add a color mask to the battle interface / HUD in Heat Wave.
// arg 0: opacity
// arg 1: color code
void AnimTask_BlendBackground(u8 taskId)
{
    struct BattleAnimBgData animBg;
    sub_80A6B30(&animBg);
    BlendPalette(animBg.paletteId * 16, 16, gBattleAnimArgs[0], gBattleAnimArgs[1]); // u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor
    DestroyAnimVisualTask(taskId);
}

void sub_810A094(u8 taskId)
{
    s8 unk;
    u8 spriteId;

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[1] = gBattleAnimArgs[0];
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
        gTasks[taskId].data[4] = gBattleAnimArgs[3];
    }
    gTasks[taskId].data[0]++;

    spriteId = gBattlerSpriteIds[gBattleAnimTarget];

    if (!gTasks[taskId].data[4])
        unk = gUnknown_08595684[gTasks[taskId].data[0] % 10];
    else
        unk = gUnknown_08595694[gTasks[taskId].data[0] % 10];

    if (gTasks[taskId].data[3] == 1)
        gSprites[spriteId].pos2.y = gBattleAnimArgs[1] * unk < 0 ? -(gBattleAnimArgs[1] * unk) : gBattleAnimArgs[1] * unk;
    else
        gSprites[spriteId].pos2.x = gBattleAnimArgs[1] * unk;

    if (gTasks[taskId].data[0] == gTasks[taskId].data[1])
    {
        gSprites[spriteId].pos2.x = 0;
        gSprites[spriteId].pos2.y = 0;
        DestroyAnimVisualTask(taskId);
    }
}
