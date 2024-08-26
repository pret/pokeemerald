#include "global.h"
#include "battle_anim.h"
#include "trig.h"
#include "constants/rgb.h"

static void AnimSludgeProjectile(struct Sprite *);
static void AnimSludgeProjectile_Step(struct Sprite *);
static void AnimAcidPoisonBubble(struct Sprite *);
static void AnimSludgeBombHitParticle_Step(struct Sprite *);
static void AnimAcidPoisonDroplet(struct Sprite *);
static void AnimBubbleEffect_Step(struct Sprite *);
static void AnimSuckerPunchStep(struct Sprite *sprite);
static void AnimSuckerPunch(struct Sprite *sprite);
static void AnimGunkShotParticlesStep(struct Sprite *sprite);
static void AnimGunkShotParticles(struct Sprite *sprite);
static void AnimGunkShotImpact(struct Sprite *sprite);
static void AnimAnimSyrupBomb(struct Sprite *);

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

const union AnimCmd *const gAnims_PoisonProjectile[] =
{
    sAnim_PoisonProjectile,
    sAnim_AcidPoisonDroplet,
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

const union AffineAnimCmd *const gAffineAnims_PoisonProjectile[] =
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
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimSludgeProjectile,
};

const struct SpriteTemplate gAcidPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimAcidPoisonBubble,
};

const struct SpriteTemplate gSludgeBombHitParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = &gAnims_PoisonProjectile[2],
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
    .anims = &gAnims_PoisonProjectile[1],
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

const union AffineAnimCmd *const gAffineAnims_Bubble[] =
{
    sAffineAnim_Bubble,
};

const struct SpriteTemplate gPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gWaterBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterBubble,
    .images = NULL,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gGreenPoisonDrip =
{
    .tileTag = ANIM_TAG_GREEN_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_GREEN_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = &gAnims_PoisonProjectile[1],
    .images = NULL,
    .affineAnims = gAffineAnims_Droplet,
    .callback = AnimAcidPoisonDroplet,
};

const struct SpriteTemplate gGreenPoisonBubble =
{
    .tileTag = ANIM_TAG_GREEN_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_GREEN_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimAcidPoisonBubble,
};

const union AnimCmd gSuckerPunchAnimCmd[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gSuckerPunchAnim[] =
{
    gSuckerPunchAnimCmd,
};

const union AnimCmd gGunkShotParticlesAnimCmd[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gGunkShotParticlesAnims[] =
{
    gGunkShotParticlesAnimCmd,
};

const union AffineAnimCmd gSuckerPunchImpactAffineAnimCmd_1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSuckerPunchImpactAffineAnimCmd_2[] =
{
    AFFINEANIMCMD_FRAME(0xD8, 0xD8, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSuckerPunchImpactAffineAnimCmd_3[] =
{
    AFFINEANIMCMD_FRAME(0xB0, 0xB0, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSuckerPunchImpactAffineAnimCmd_4[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSuckerPunchImpactAffineAnim[] =
{
    gSuckerPunchImpactAffineAnimCmd_1,
    gSuckerPunchImpactAffineAnimCmd_2,
    gSuckerPunchImpactAffineAnimCmd_3,
    gSuckerPunchImpactAffineAnimCmd_4,
};

const struct SpriteTemplate gSuckerPunchSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_JAB,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gSuckerPunchAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSuckerPunch,
};

const struct SpriteTemplate gGunkShoParticlesSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gGunkShotParticlesAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGunkShotParticles,
};

const struct SpriteTemplate gGunkShotImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSuckerPunchImpactAffineAnim,
    .callback = AnimGunkShotImpact,
};

static const union AnimCmd sAnim_SyrupCoat[] =
{
    ANIMCMD_FRAME(128, 10),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(0, 45),
    ANIMCMD_FRAME(64, 15),
    ANIMCMD_FRAME(128, 15),
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SyrupStick[] =
{
    ANIMCMD_FRAME(192, 5),
    ANIMCMD_FRAME(128, 35),
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_SyrupCoat[] =
{
    sAnim_SyrupCoat,
};

static const union AnimCmd *const sAnims_SyrupStick[] =
{
    sAnim_SyrupStick,
};

const struct SpriteTemplate gSyrupRedProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_BLOB_RED,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_RED,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimSludgeProjectile,
};

const struct SpriteTemplate gSyrupYellowProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_BLOB_YELLOW,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_YELLOW,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimSludgeProjectile,
};

const struct SpriteTemplate gSyrupBombRedHitParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_SPLAT_RED,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_RED,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_SludgeBombHit,
    .callback = AnimSludgeBombHitParticle,
};

const struct SpriteTemplate gSyrupBombYellowHitParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_SPLAT_YELLOW,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_YELLOW,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_SludgeBombHit,
    .callback = AnimSludgeBombHitParticle,
};

const struct SpriteTemplate gSyrupBombRedShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_SHELL_RED,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_RED,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = sAnims_SyrupCoat,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAnimSyrupBomb,
};

const struct SpriteTemplate gSyrupBombYellowShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_SHELL_YELLOW,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_YELLOW,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = sAnims_SyrupCoat,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAnimSyrupBomb,
};

const struct SpriteTemplate gSyrupBombRedShellBSpriteTemplate =
{
     .tileTag = ANIM_TAG_SYRUP_SHELL_RED,
     .paletteTag = ANIM_TAG_SYRUP_BLOB_RED,
     .oam = &gOamData_AffineOff_ObjNormal_64x64,
     .anims = sAnims_SyrupStick,
     .images = NULL,
     .affineAnims = gDummySpriteAffineAnimTable,
     .callback = AnimAnimSyrupBomb,
};

const struct SpriteTemplate gSyrupBombYellowShellBSpriteTemplate =
{
    .tileTag = ANIM_TAG_SYRUP_SHELL_YELLOW,
    .paletteTag = ANIM_TAG_SYRUP_BLOB_YELLOW,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = sAnims_SyrupStick,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAnimSyrupBomb,
};

static void AnimGunkShotImpact(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == 0)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimGunkShotParticles(struct Sprite *sprite)
{
    u16 retArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 30;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0xD200 / sprite->data[0];
    sprite->data[7] = gBattleAnimArgs[3];
    retArg = gBattleAnimArgs[ARG_RET_ID];
    if (gBattleAnimArgs[ARG_RET_ID] > 127)
    {
        sprite->data[6] = (retArg - 127) * 256;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] = retArg * 256;
    }
    sprite->callback = AnimGunkShotParticlesStep;
    sprite->callback(sprite);
}

static void AnimGunkShotParticlesStep(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
    sprite->y2 += Sin(sprite->data[6] >> 8, sprite->data[7]);
    if ((sprite->data[6] + sprite->data[5]) >> 8 > 127)
    {
        sprite->data[6] = 0;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] += sprite->data[5];
    }
}

static void AnimSuckerPunch(struct Sprite *sprite)
{
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget && GetBattlerPosition(gBattleAnimTarget) < B_POSITION_PLAYER_RIGHT)
        gBattleAnimArgs[0] *= -1;

    InitSpritePosToAnimTarget(sprite, TRUE);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y;

    InitAnimLinearTranslation(sprite);

    sprite->data[5] = gBattleAnimArgs[5];
    sprite->data[6] = gBattleAnimArgs[4];
    sprite->data[7] = 0;

    sprite->callback = AnimSuckerPunchStep;
}

static void AnimSuckerPunchStep(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->y2 += Sin(sprite->data[7] >> 8, sprite->data[5]);
        sprite->data[7] += sprite->data[6];
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimSludgeProjectile(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, TRUE);

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
    s16 l1 = 0, l2 = 0;
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (gBattleAnimArgs[6])
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &l1, &l2);
    else
        l1 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2), l2 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = l1 + gBattleAnimArgs[4];
    sprite->data[4] = l2 + gBattleAnimArgs[5];
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimAcidPoisonBubble_Step;
}

void AnimAcidPoisonBubble_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

void AnimSludgeBombHitParticle(struct Sprite *sprite)
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
    if (gBattleAnimArgs[5])
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
void AnimBubbleEffect(struct Sprite *sprite)
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

static void AnimSyrupBomb_Step(struct Sprite *sprite)
{
    if (sprite->data[1] > sprite->data[0] - 10)
        sprite->invisible = sprite->data[1] & 1;

    if (sprite->data[1] == sprite->data[0])
        DestroyAnimSprite(sprite);

    sprite->data[1]++;
}

static void AnimAnimSyrupBomb(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_TARGET)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 2;
    }

    sprite->data[0] = gBattleAnimArgs[1];
    sprite->callback = AnimSyrupBomb_Step;
}
