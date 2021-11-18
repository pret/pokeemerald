#include "global.h"
#include "battle_anim.h"
#include "trig.h"
#include "constants/rgb.h"

static void AnimSludgeProjectile(struct Sprite *);
static void AnimSludgeProjectile_Step(struct Sprite *);
static void AnimAcidPoisonBubble(struct Sprite *);
static void AnimAcidPoisonBubble_Step(struct Sprite *);
static void AnimSludgeBombHitParticle(struct Sprite *);
static void AnimSludgeBombHitParticle_Step(struct Sprite *);
static void AnimAcidPoisonDroplet(struct Sprite *);
static void AnimBubbleEffect(struct Sprite *);
static void AnimBubbleEffect_Step(struct Sprite *);

static const union AnimCmd sAnim_ToxicBubble[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_ToxicBubble[] =
{
    sAnim_ToxicBubble,
};

const struct SpriteTemplate gToxicBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_TOXIC_BUBBLE,
    .paletteTag = ANIM_TAG_TOXIC_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = sAnims_ToxicBubble,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

static const union AnimCmd sAnim_PoisonProjectile[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AcidPoisonDroplet[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SludgeBombHit[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_PoisonProjectile[] =
{
    sAnim_PoisonProjectile,
};

static const union AnimCmd *const sAnims_AcidPoisonDroplet[] =
{
    sAnim_AcidPoisonDroplet,
};

static const union AnimCmd *const sAnims_SludgeBombHit[] =
{
    sAnim_SludgeBombHit,
};

static const union AffineAnimCmd sAffineAnim_PoisonProjectile[] =
{
    AFFINEANIMCMD_FRAME(0x160, 0x160, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_SludgeBombHit[] =
{
    AFFINEANIMCMD_FRAME(0xEC, 0xEC, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_PoisonProjectile[] =
{
    sAffineAnim_PoisonProjectile,
};

static const union AffineAnimCmd *const sAffineAnims_SludgeBombHit[] =
{
    sAffineAnim_SludgeBombHit,
};

const struct SpriteTemplate gSludgeProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_PoisonProjectile,
    .callback = AnimSludgeProjectile,
};

const struct SpriteTemplate gAcidPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_PoisonProjectile,
    .callback = AnimAcidPoisonBubble,
};

const struct SpriteTemplate gSludgeBombHitParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = sAnims_SludgeBombHit,
    .images = NULL,
    .affineAnims = sAffineAnims_SludgeBombHit,
    .callback = AnimSludgeBombHitParticle,
};

static const union AffineAnimCmd sAffineAnim_AcidPoisonDroplet[] =
{
    AFFINEANIMCMD_FRAME(0xFFF0, 0x10, 0, 6),
    AFFINEANIMCMD_FRAME(0x10, 0xFFF0, 0, 6),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gAffineAnims_Droplet[] =
{
    sAffineAnim_AcidPoisonDroplet,
};

const struct SpriteTemplate gAcidPoisonDropletSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sAnims_AcidPoisonDroplet,
    .images = NULL,
    .affineAnims = gAffineAnims_Droplet,
    .callback = AnimAcidPoisonDroplet,
};

static const union AffineAnimCmd sAffineAnim_Bubble[] =
{
    AFFINEANIMCMD_FRAME(0x9C, 0x9C, 0, 0),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 20),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_Bubble[] =
{
    sAffineAnim_Bubble,
};

const struct SpriteTemplate gPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = sAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_Bubble,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gWaterBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterBubble,
    .images = NULL,
    .affineAnims = sAffineAnims_Bubble,
    .callback = AnimBubbleEffect,
};

static void AnimSludgeProjectile(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, 1);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimSludgeProjectile_Step;
}

static void AnimSludgeProjectile_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

static void AnimAcidPoisonBubble(struct Sprite *sprite)
{
    s16 l1, l2;
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, 1);
    SetAverageBattlerPositions(gBattleAnimTarget, 1, &l1, &l2);

    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = l1 + gBattleAnimArgs[4];
    sprite->data[4] = l2 + gBattleAnimArgs[5];
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimAcidPoisonBubble_Step;
}

static void AnimAcidPoisonBubble_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

static void AnimSludgeBombHitParticle(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[0];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y + gBattleAnimArgs[1];

    InitSpriteDataForLinearTranslation(sprite);

    sprite->data[5] = sprite->data[1] / gBattleAnimArgs[2];
    sprite->data[6] = sprite->data[2] / gBattleAnimArgs[2];

    sprite->callback = AnimSludgeBombHitParticle_Step;
}

static void AnimSludgeBombHitParticle_Step(struct Sprite *sprite)
{
    TranslateSpriteLinearFixedPoint(sprite);

    sprite->data[1] -= sprite->data[5];
    sprite->data[2] -= sprite->data[6];

    if (!sprite->data[0])
        DestroyAnimSprite(sprite);
}

static void AnimAcidPoisonDroplet(struct Sprite *sprite)
{
    SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->y + sprite->data[0];

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates a bubble by rising upward, swaying side to side, and
// enlarging the sprite. This is used as an after-effect by poison-type
// moves, along with MOVE_BUBBLE, and MOVE_BUBBLEBEAM.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: 0 = single-target, 1 = multi-target
static void AnimBubbleEffect(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[2])
    {
        InitSpritePosToAnimTarget(sprite, TRUE);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gBattleAnimArgs[0] = -gBattleAnimArgs[0];

        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->callback = AnimBubbleEffect_Step;
}

static void AnimBubbleEffect_Step(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 0xB) & 0xFF;
    sprite->x2 = Sin(sprite->data[0], 4);
    sprite->data[1] += 0x30;
    sprite->y2 = -(sprite->data[1] >> 8);

    if (sprite->affineAnimEnded)
        DestroyAnimSprite(sprite);
}
