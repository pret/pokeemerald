#include "global.h"
#include "battle_anim.h"
#include "trig.h"
#include "constants/rgb.h"

void sub_810DBAC(struct Sprite *);
void sub_810DC2C(struct Sprite *);
void sub_810DCD0(struct Sprite *);
void sub_810DD50(struct Sprite *);
void AnimBubbleEffect(struct Sprite *);
static void sub_810DC10(struct Sprite *);
static void sub_810DCB4(struct Sprite *);
static void sub_810DD24(struct Sprite *);
static void AnimBubbleEffectStep(struct Sprite *);
static void AnimSuckerPunchStep(struct Sprite *sprite);
void AnimSuckerPunch(struct Sprite *sprite);
void AnimGunkShotParticlesStep(struct Sprite *sprite);
void AnimGunkShotParticles(struct Sprite *sprite);
void AnimGunkShotImpact(struct Sprite *sprite);

extern const union AnimCmd *const gUnknown_08595200[];

const union AnimCmd gUnknown_0859611C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596130[] =
{
    gUnknown_0859611C,
};

const struct SpriteTemplate gUnknown_08596134 =
{
    .tileTag = ANIM_TAG_TOXIC_BUBBLE,
    .paletteTag = ANIM_TAG_TOXIC_BUBBLE,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_08596130,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A77C8,
};

const union AnimCmd gUnknown_0859614C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08596154[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_0859615C[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596164[] =
{
    gUnknown_0859614C,
};

const union AnimCmd *const gUnknown_08596168[] =
{
    gUnknown_08596154,
};

const union AnimCmd *const gUnknown_0859616C[] =
{
    gUnknown_0859615C,
};

const union AffineAnimCmd gUnknown_08596170[] =
{
    AFFINEANIMCMD_FRAME(0x160, 0x160, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gUnknown_08596190[] =
{
    AFFINEANIMCMD_FRAME(0xEC, 0xEC, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085961A0[] =
{
    gUnknown_08596170,
};

const union AffineAnimCmd *const gUnknown_085961A4[] =
{
    gUnknown_08596190,
};

const struct SpriteTemplate gUnknown_085961A8 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_085961A0,
    .callback = sub_810DBAC,
};

const struct SpriteTemplate gUnknown_085961C0 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_085961A0,
    .callback = sub_810DC2C,
};

const struct SpriteTemplate gUnknown_085961D8 =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_0859616C,
    .images = NULL,
    .affineAnims = gUnknown_085961A4,
    .callback = sub_810DCD0,
};

const union AffineAnimCmd gUnknown_085961F0[] =
{
    AFFINEANIMCMD_FRAME(0xFFF0, 0x10, 0, 6),
    AFFINEANIMCMD_FRAME(0x10, 0xFFF0, 0, 6),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596208[] =
{
    gUnknown_085961F0,
};

const struct SpriteTemplate gUnknown_0859620C =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08596168,
    .images = NULL,
    .affineAnims = gUnknown_08596208,
    .callback = sub_810DD50,
};

const union AffineAnimCmd gUnknown_08596224[] =
{
    AFFINEANIMCMD_FRAME(0x9C, 0x9C, 0, 0),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_0859623C[] =
{
    gUnknown_08596224,
};

const struct SpriteTemplate gPoisonBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_0852496C,
    .anims = gUnknown_08596164,
    .images = NULL,
    .affineAnims = gUnknown_0859623C,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gWaterBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_08524A8C,
    .anims = gUnknown_08595200,
    .images = NULL,
    .affineAnims = gUnknown_0859623C,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gGreenPoisonDrip =
{
	.tileTag = ANIM_TAG_GREEN_POISON_BUBBLE,
	.paletteTag = ANIM_TAG_GREEN_POISON_BUBBLE,
	.oam = &gUnknown_085249CC,
	.anims = gUnknown_08596168,
	.images = NULL,
	.affineAnims = gUnknown_08596208,
	.callback = sub_810DD50,
};

const struct SpriteTemplate gGreenPoisonBubble =
{
	.tileTag = ANIM_TAG_GREEN_POISON_BUBBLE,
	.paletteTag = ANIM_TAG_GREEN_POISON_BUBBLE,
	.oam = &gUnknown_085249CC,
	.anims = gUnknown_08596164,
	.images = NULL,
	.affineAnims = gUnknown_085961A0,
	.callback = sub_810DC2C,
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
    .oam = &gUnknown_0852496C,
    .anims = gSuckerPunchAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSuckerPunch,
};

const struct SpriteTemplate gGunkShoParticlesSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_08524A2C,
    .anims = gGunkShotParticlesAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGunkShotParticles,
};

const struct SpriteTemplate gGunkShotImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gUnknown_08524A94,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSuckerPunchImpactAffineAnim,
    .callback = AnimGunkShotImpact,
};

void AnimGunkShotImpact(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == 0)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimGunkShotParticles(struct Sprite *sprite)
{
    u16 retArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 30;
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->pos1.y;
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

void AnimGunkShotParticlesStep(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
    sprite->pos2.y += Sin(sprite->data[6] >> 8, sprite->data[7]);
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

void AnimSuckerPunch(struct Sprite *sprite)
{
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget && GetBattlerPosition(gBattleAnimTarget) < B_POSITION_PLAYER_RIGHT)
        gBattleAnimArgs[0] *= -1;

    InitSpritePosToAnimTarget(sprite, TRUE);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = sprite->pos1.y;

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
        sprite->pos2.y += Sin(sprite->data[7] >> 8, sprite->data[5]);
        sprite->data[7] += sprite->data[6];
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_810DBAC(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, 1);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = sub_810DC10;
}

static void sub_810DC10(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

void sub_810DC2C(struct Sprite *sprite)
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

    sprite->callback = sub_810DCB4;
}

static void sub_810DCB4(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

void sub_810DCD0(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[0];
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[1];

    InitSpriteDataForLinearTranslation(sprite);

    sprite->data[5] = sprite->data[1] / gBattleAnimArgs[2];
    sprite->data[6] = sprite->data[2] / gBattleAnimArgs[2];

    sprite->callback = sub_810DD24;
}

static void sub_810DD24(struct Sprite *sprite)
{
    TranslateSpriteLinearFixedPoint(sprite);

    sprite->data[1] -= sprite->data[5];
    sprite->data[2] -= sprite->data[6];

    if (!sprite->data[0])
        DestroyAnimSprite(sprite);
}

void sub_810DD50(struct Sprite *sprite)
{
    SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->pos1.x, &sprite->pos1.y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->pos1.y + sprite->data[0];

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
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->pos1.x, &sprite->pos1.y);

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gBattleAnimArgs[0] = -gBattleAnimArgs[0];

        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }

    sprite->callback = AnimBubbleEffectStep;
}

static void AnimBubbleEffectStep(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 0xB) & 0xFF;
    sprite->pos2.x = Sin(sprite->data[0], 4);
    sprite->data[1] += 0x30;
    sprite->pos2.y = -(sprite->data[1] >> 8);

    if (sprite->affineAnimEnded)
        DestroyAnimSprite(sprite);
}
