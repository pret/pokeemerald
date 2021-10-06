#include "global.h"
#include "battle_anim.h"
#include "palette.h"
#include "random.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"

static void AnimConfusionDuck(struct Sprite *);
static void AnimSimplePaletteBlend(struct Sprite *);
static void AnimSimplePaletteBlend_Step(struct Sprite *);
static void AnimComplexPaletteBlend(struct Sprite *);
static void AnimComplexPaletteBlend_Step1(struct Sprite *);
static void AnimComplexPaletteBlend_Step2(struct Sprite *);
static void AnimCirclingSparkle(struct Sprite *);
static void AnimShakeMonOrBattleTerrain(struct Sprite *);
static void AnimShakeMonOrBattleTerrain_Step(struct Sprite *);
static void AnimShakeMonOrBattleTerrain_UpdateCoordOffsetEnabled(void);
static void AnimHitSplatPersistent(struct Sprite *);
static void AnimHitSplatHandleInvert(struct Sprite *);
static void AnimConfusionDuck_Step(struct Sprite *);
static void BlendColorCycle(u8, u8, u8);
static void AnimTask_BlendColorCycleLoop(u8);
static void BlendColorCycleExclude(u8, u8, u8);
static void AnimTask_BlendColorCycleExcludeLoop(u8);
static void BlendColorCycleByTag(u8, u8, u8);
static void AnimTask_BlendColorCycleByTagLoop(u8);
static void AnimTask_FlashAnimTagWithColor_Step1(u8);
static void AnimTask_FlashAnimTagWithColor_Step2(u8);
static void AnimTask_ShakeBattleTerrain_Step(u8);
static void AnimMovePowerSwapGuardSwap(struct Sprite *);

static const union AnimCmd sAnim_ConfusionDuck_0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ConfusionDuck_1[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_ConfusionDuck[] =
{
    sAnim_ConfusionDuck_0,
    sAnim_ConfusionDuck_1,
};

const struct SpriteTemplate gConfusionDuckSpriteTemplate =
{
    .tileTag = ANIM_TAG_DUCK,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_ConfusionDuck,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimConfusionDuck,
};

const struct SpriteTemplate gSimplePaletteBlendSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSimplePaletteBlend,
};

const struct SpriteTemplate gComplexPaletteBlendSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimComplexPaletteBlend,
};

static const union AnimCmd sPowerSwapGuardSwapFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sPowerSwapGuardSwapFrame1[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sPowerSwapGuardSwapFrame2[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sPowerSwapGuardSwapFrame3[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sPowerSwapGuardSwapFrame4[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sPowerSwapGuardSwapFrame5[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd * const sPowerSwapGuardSwapAnimTable[] =
{
    sPowerSwapGuardSwapFrame0,
    sPowerSwapGuardSwapFrame1,
    sPowerSwapGuardSwapFrame2,
    sPowerSwapGuardSwapFrame3,
    sPowerSwapGuardSwapFrame4,
    sPowerSwapGuardSwapFrame5
};

const struct SpriteTemplate gPowerSwapGuardSwapSpriteTemplate =
{
    .tileTag = ANIM_TAG_COLORED_ORBS,
    .paletteTag = ANIM_TAG_COLORED_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sPowerSwapGuardSwapAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovePowerSwapGuardSwap
};

static const union AnimCmd sAnim_CirclingSparkle[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_CirclingSparkle[] =
{
    sAnim_CirclingSparkle,
};

// Unused
static const struct SpriteTemplate sCirclingSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_CirclingSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCirclingSparkle,
};

const struct SpriteTemplate gShakeMonOrTerrainSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimShakeMonOrBattleTerrain,
};

static const union AffineAnimCmd sAffineAnim_HitSplat_0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_HitSplat_1[] =
{
    AFFINEANIMCMD_FRAME(0xD8, 0xD8, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_HitSplat_2[] =
{
    AFFINEANIMCMD_FRAME(0xB0, 0xB0, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_HitSplat_3[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAffineAnims_HitSplat[] =
{
    sAffineAnim_HitSplat_0,
    sAffineAnim_HitSplat_1,
    sAffineAnim_HitSplat_2,
    sAffineAnim_HitSplat_3,
};

const struct SpriteTemplate gBasicHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gHandleInvertHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatHandleInvert,
};

const struct SpriteTemplate gWaterHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_IMPACT,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gRandomPosHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom,
};

const struct SpriteTemplate gMonEdgeHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatOnMonEdge,
};

const struct SpriteTemplate gCrossImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_CROSS_IMPACT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCrossImpact,
};

const struct SpriteTemplate gFlashingHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimFlashingHitSplat,
};

const struct SpriteTemplate gPersistHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatPersistent,
};

static void AnimMovePowerSwapGuardSwapWait(struct Sprite* sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: orb type (0..5) - color and size
// arg 3: from user to target / target to user
// arg 4: wave period
// arg 5: wave amplitude
static void AnimMovePowerSwapGuardSwap(struct Sprite* sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    if(gBattleAnimArgs[3] == 0)
    {
        InitSpritePosToAnimAttacker(sprite, TRUE);
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }
    else
    {
        InitSpritePosToAnimTarget(sprite, TRUE);
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimMovePowerSwapGuardSwapWait;
}

// Moves a spinning duck around the mon's head.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wave offset
// arg 3: wave period (higher means faster wave)
// arg 4: duration
static void AnimConfusionDuck(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->data[1] = -gBattleAnimArgs[3];
        sprite->data[4] = 1;
    }
    else
    {
        sprite->data[1] = gBattleAnimArgs[3];
        sprite->data[4] = 0;
        StartSpriteAnim(sprite, 1);
    }

    sprite->data[3] = gBattleAnimArgs[4];
    sprite->callback = AnimConfusionDuck_Step;
    sprite->callback(sprite);
}

static void AnimConfusionDuck_Step(struct Sprite *sprite)
{
    sprite->x2 = Cos(sprite->data[0], 30);
    sprite->y2 = Sin(sprite->data[0], 10);

    if ((u16)sprite->data[0] < 128)
        sprite->oam.priority = 1;
    else
        sprite->oam.priority = 3;

    sprite->data[0] = (sprite->data[0] + sprite->data[1]) & 0xFF;
    if (++sprite->data[2] == sprite->data[3])
        DestroyAnimSprite(sprite);
}

// Performs a simple color blend on a specified sprite.
// arg 0: palette selector
// arg 1: delay
// arg 2: start blend amount
// arg 3: end blend amount
// arg 4: blend color
static void AnimSimplePaletteBlend(struct Sprite *sprite)
{
    u32 selectedPalettes = UnpackSelectedBattleBgPalettes(gBattleAnimArgs[0]);
    BeginNormalPaletteFade(selectedPalettes, gBattleAnimArgs[1], gBattleAnimArgs[2], gBattleAnimArgs[3], gBattleAnimArgs[4]);
    sprite->invisible = TRUE;
    sprite->callback = AnimSimplePaletteBlend_Step;
}

// Unpacks a bitfield and returns a bitmask of its selected palettes.
// Bits 0-6 of the selector parameter result in the following palettes being selected:
//   0: battle background palettes (BG palettes 1, 2, and 3)
//   1: gBattleAnimAttacker OBJ palette
//   2: gBattleAnimTarget OBJ palette
//   3: gBattleAnimAttacker partner OBJ palette
//   4: gBattleAnimTarget partner OBJ palette
//   5: BG palette 4
//   6: BG palette 5
u32 UnpackSelectedBattleBgPalettes(s16 selector)
{
    u8 battleBackground = selector & 1;
    u8 attacker = (selector >> 1) & 1;
    u8 target = (selector >> 2) & 1;
    u8 attackerPartner = (selector >> 3) & 1;
    u8 targetPartner = (selector >> 4) & 1;
    u8 arg5 = (selector >> 5) & 1;
    u8 arg6 = (selector >> 6) & 1;
    return GetBattleBgPalettesMask(battleBackground, attacker, target, attackerPartner, targetPartner, arg5, arg6);
}

static void AnimSimplePaletteBlend_Step(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
        DestroyAnimSprite(sprite);
}

static void AnimComplexPaletteBlend(struct Sprite *sprite)
{
    u32 selectedPalettes;

    sprite->data[0] = gBattleAnimArgs[1];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->data[3] = gBattleAnimArgs[3];
    sprite->data[4] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    sprite->data[6] = gBattleAnimArgs[6];
    sprite->data[7] = gBattleAnimArgs[0];

    selectedPalettes = UnpackSelectedBattleBgPalettes(sprite->data[7]);
    BlendPalettes(selectedPalettes, gBattleAnimArgs[4], gBattleAnimArgs[3]);
    sprite->invisible = TRUE;
    sprite->callback = AnimComplexPaletteBlend_Step1;
}

static void AnimComplexPaletteBlend_Step1(struct Sprite *sprite)
{
    u32 selectedPalettes;

    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        return;
    }

    if (gPaletteFade.active)
        return;

    if (sprite->data[2] == 0)
    {
        sprite->callback = AnimComplexPaletteBlend_Step2;
        return;
    }

    selectedPalettes = UnpackSelectedBattleBgPalettes(sprite->data[7]);
    if (sprite->data[1] & 0x100)
        BlendPalettes(selectedPalettes, sprite->data[4], sprite->data[3]);
    else
        BlendPalettes(selectedPalettes, sprite->data[6], sprite->data[5]);

    sprite->data[1] ^= 0x100;
    sprite->data[0] = sprite->data[1] & 0xFF;
    sprite->data[2]--;
}

static void AnimComplexPaletteBlend_Step2(struct Sprite *sprite)
{
    u32 selectedPalettes;

    if (!gPaletteFade.active)
    {
        selectedPalettes = UnpackSelectedBattleBgPalettes(sprite->data[7]);
        BlendPalettes(selectedPalettes, 0, 0);
        DestroyAnimSprite(sprite);
    }
}

static void AnimCirclingSparkle(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = 0;
    sprite->data[1] = 10;
    sprite->data[2] = 8;
    sprite->data[3] = 40;
    sprite->data[4] = 112;
    sprite->data[5] = 0;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInGrowingCircleOverDuration;
    sprite->callback(sprite);
}

// Task data for AnimTask_BlendColorCycle, AnimTask_BlendColorCycleExclude, and AnimTask_BlendColorCycleByTag
#define tPalSelector   data[0]  // AnimTask_BlendColorCycle
#define tPalTag        data[0]  // AnimTask_BlendColorCycleByTag
#define tDelay         data[1]
#define tNumBlends     data[2]
#define tInitialBlendY data[3]
#define tTargetBlendY  data[4]
#define tBlendColor    data[5]
#define tRestoreBlend  data[8]
#define tPalSelectorHi data[9]
#define tPalSelectorLo data[10]

// Blends mon/screen to designated color or back alternately tNumBlends times
// Many uses of this task only set a tNumBlends of 2, which has the effect of blending to a color and back once
void AnimTask_BlendColorCycle(u8 taskId)
{
    gTasks[taskId].tPalSelector = gBattleAnimArgs[0];
    gTasks[taskId].tDelay = gBattleAnimArgs[1];
    gTasks[taskId].tNumBlends = gBattleAnimArgs[2];
    gTasks[taskId].tInitialBlendY = gBattleAnimArgs[3];
    gTasks[taskId].tTargetBlendY = gBattleAnimArgs[4];
    gTasks[taskId].tBlendColor = gBattleAnimArgs[5];
    gTasks[taskId].tRestoreBlend = FALSE;
    BlendColorCycle(taskId, 0, gTasks[taskId].tTargetBlendY);
    gTasks[taskId].func = AnimTask_BlendColorCycleLoop;
}

static void BlendColorCycle(u8 taskId, u8 startBlendAmount, u8 targetBlendAmount)
{
    u32 selectedPalettes = UnpackSelectedBattleBgPalettes(gTasks[taskId].tPalSelector);
    BeginNormalPaletteFade(
        selectedPalettes,
        gTasks[taskId].tDelay,
        startBlendAmount,
        targetBlendAmount,
        gTasks[taskId].tBlendColor);

    gTasks[taskId].tNumBlends--;
    gTasks[taskId].tRestoreBlend ^= 1;
}

static void AnimTask_BlendColorCycleLoop(u8 taskId)
{
    u8 startBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tNumBlends > 0)
        {
            if (!gTasks[taskId].tRestoreBlend)
            {
                // Blend to designated color
                startBlendAmount = gTasks[taskId].tInitialBlendY;
                targetBlendAmount = gTasks[taskId].tTargetBlendY;
            }
            else
            {
                // Blend back to original color
                startBlendAmount = gTasks[taskId].tTargetBlendY;
                targetBlendAmount = gTasks[taskId].tInitialBlendY;
            }

            if (gTasks[taskId].tNumBlends == 1)
                targetBlendAmount = 0;

            BlendColorCycle(taskId, startBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

// See AnimTask_BlendColorCycle. Same, but excludes Attacker and Target
void AnimTask_BlendColorCycleExclude(u8 taskId)
{
    int battler;
    u32 selectedPalettes = 0;

    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].tDelay = gBattleAnimArgs[1];
    gTasks[taskId].tNumBlends = gBattleAnimArgs[2];
    gTasks[taskId].tInitialBlendY = gBattleAnimArgs[3];
    gTasks[taskId].tTargetBlendY = gBattleAnimArgs[4];
    gTasks[taskId].tBlendColor = gBattleAnimArgs[5];
    gTasks[taskId].tRestoreBlend = 0;

    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler != gBattleAnimAttacker && battler != gBattleAnimTarget)
            selectedPalettes |= 1 << (battler + 16);
    }

    if (gBattleAnimArgs[0] == 1)
        selectedPalettes |= 0xE;

    gTasks[taskId].tPalSelectorHi = selectedPalettes >> 16;
    gTasks[taskId].tPalSelectorLo = selectedPalettes & 0xFF;
    BlendColorCycleExclude(taskId, 0, gTasks[taskId].tTargetBlendY);
    gTasks[taskId].func = AnimTask_BlendColorCycleExcludeLoop;
}

static void BlendColorCycleExclude(u8 taskId, u8 startBlendAmount, u8 targetBlendAmount)
{
    u32 selectedPalettes = ((u16)gTasks[taskId].tPalSelectorHi << 16) | (u16)gTasks[taskId].tPalSelectorLo;
    BeginNormalPaletteFade(
        selectedPalettes,
        gTasks[taskId].tDelay,
        startBlendAmount,
        targetBlendAmount,
        gTasks[taskId].tBlendColor);

    gTasks[taskId].tNumBlends--;
    gTasks[taskId].tRestoreBlend ^= 1;
}

static void AnimTask_BlendColorCycleExcludeLoop(u8 taskId)
{
    u8 startBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tNumBlends > 0)
        {
            if (!gTasks[taskId].tRestoreBlend)
            {
                // Blend to designated color
                startBlendAmount = gTasks[taskId].tInitialBlendY;
                targetBlendAmount = gTasks[taskId].tTargetBlendY;
            }
            else
            {
                // Blend back to original color
                startBlendAmount = gTasks[taskId].tTargetBlendY;
                targetBlendAmount = gTasks[taskId].tInitialBlendY;
            }

            if (gTasks[taskId].tNumBlends == 1)
                targetBlendAmount = 0;

            BlendColorCycleExclude(taskId, startBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

// See AnimTask_BlendColorCycle. Same, but selects palette by ANIM_TAG_*
void AnimTask_BlendColorCycleByTag(u8 taskId)
{
    gTasks[taskId].tPalTag = gBattleAnimArgs[0];
    gTasks[taskId].tDelay = gBattleAnimArgs[1];
    gTasks[taskId].tNumBlends = gBattleAnimArgs[2];
    gTasks[taskId].tInitialBlendY = gBattleAnimArgs[3];
    gTasks[taskId].tTargetBlendY = gBattleAnimArgs[4];
    gTasks[taskId].tBlendColor = gBattleAnimArgs[5];
    gTasks[taskId].tRestoreBlend = FALSE;

    BlendColorCycleByTag(taskId, 0, gTasks[taskId].tTargetBlendY);
    gTasks[taskId].func = AnimTask_BlendColorCycleByTagLoop;
}

static void BlendColorCycleByTag(u8 taskId, u8 startBlendAmount, u8 targetBlendAmount)
{
    u8 paletteIndex = IndexOfSpritePaletteTag(gTasks[taskId].tPalTag);
    BeginNormalPaletteFade(
        1 << (paletteIndex + 16),
        gTasks[taskId].tDelay,
        startBlendAmount,
        targetBlendAmount,
        gTasks[taskId].tBlendColor);

    gTasks[taskId].tNumBlends--;
    gTasks[taskId].tRestoreBlend ^= 1;
}

static void AnimTask_BlendColorCycleByTagLoop(u8 taskId)
{
    u8 startBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tNumBlends > 0)
        {
            if (!gTasks[taskId].tRestoreBlend)
            {
                // Blend to designated color
                startBlendAmount = gTasks[taskId].tInitialBlendY;
                targetBlendAmount = gTasks[taskId].tTargetBlendY;
            }
            else
            {
                // Blend back to original color
                startBlendAmount = gTasks[taskId].tTargetBlendY;
                targetBlendAmount = gTasks[taskId].tInitialBlendY;
            }

            if (gTasks[taskId].tNumBlends == 1)
                targetBlendAmount = 0;

            BlendColorCycleByTag(taskId, startBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

#undef tPalSelector
#undef tPalTag
#undef tDelay
#undef tNumBlends
#undef tInitialBlendY
#undef tTargetBlendY
#undef tBlendColor
#undef tRestoreBlend
#undef tPalSelectorHi
#undef tPalSelectorLo

// Flashes the specified anim tag with given color. Used e.g. to flash the particles red in Hyper Beam
void AnimTask_FlashAnimTagWithColor(u8 taskId)
{
    u8 paletteIndex;

    gTasks[taskId].data[0] = gBattleAnimArgs[1];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].data[6] = gBattleAnimArgs[6];
    gTasks[taskId].data[7] = gBattleAnimArgs[0];

    paletteIndex = IndexOfSpritePaletteTag(gBattleAnimArgs[0]);
    BeginNormalPaletteFade(
        1 << (paletteIndex + 16),
        0,
        gBattleAnimArgs[4],
        gBattleAnimArgs[4],
        gBattleAnimArgs[3]);

    gTasks[taskId].func = AnimTask_FlashAnimTagWithColor_Step1;
}

static void AnimTask_FlashAnimTagWithColor_Step1(u8 taskId)
{
    u32 selectedPalettes;

    if (gTasks[taskId].data[0] > 0)
    {
        gTasks[taskId].data[0]--;
        return;
    }

    if (gPaletteFade.active)
        return;

    if (gTasks[taskId].data[2] == 0)
    {
        gTasks[taskId].func = AnimTask_FlashAnimTagWithColor_Step2;
        return;
    }

    selectedPalettes = 1 << (IndexOfSpritePaletteTag(gTasks[taskId].data[7]) + 16);
    if (gTasks[taskId].data[1] & 0x100)
    {
        BeginNormalPaletteFade(
            selectedPalettes,
            0,
            gTasks[taskId].data[4],
            gTasks[taskId].data[4],
            gTasks[taskId].data[3]);
    }
    else
    {
        BeginNormalPaletteFade(
            selectedPalettes,
            0,
            gTasks[taskId].data[6],
            gTasks[taskId].data[6],
            gTasks[taskId].data[5]);
    }

    gTasks[taskId].data[1] ^= 0x100;
    gTasks[taskId].data[0] = gTasks[taskId].data[1] & 0xFF;
    gTasks[taskId].data[2]--;
}

static void AnimTask_FlashAnimTagWithColor_Step2(u8 taskId)
{
    u32 selectedPalettes;

    if (!gPaletteFade.active)
    {
        selectedPalettes = 1 << (IndexOfSpritePaletteTag(gTasks[taskId].data[7]) + 16);
        BeginNormalPaletteFade(selectedPalettes, 0, 0, 0, RGB(0, 0, 0));
        DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_InvertScreenColor(u8 taskId)
{
    u32 selectedPalettes = 0;

    if (gBattleAnimArgs[0] & 0x1)
        selectedPalettes = GetBattleBgPalettesMask(1, 0, 0, 0, 0, 0, 0);
    if (gBattleAnimArgs[0] & 0x2)
        selectedPalettes |= (0x10000 << gBattleAnimAttacker);
    if (gBattleAnimArgs[0] & 0x4)
        selectedPalettes |= (0x10000 << gBattleAnimTarget);
    if (gBattleAnimArgs[0] & 0x8 && IsBattlerAlive(BATTLE_PARTNER(gBattleAnimTarget)))
        selectedPalettes |= (0x10000 << BATTLE_PARTNER(gBattleAnimTarget));
	if (gBattleAnimArgs[0] & 0x10 && IsBattlerAlive(BATTLE_PARTNER(gBattleAnimAttacker)))
        selectedPalettes |= (0x10000 << BATTLE_PARTNER(gBattleAnimAttacker));

    InvertPlttBuffer(selectedPalettes);
    DestroyAnimVisualTask(taskId);
}

void UnusedAnimTask_8115F94(u8 taskId)
{
    u8 attackerBattler;
    u8 targetBattler;
    u8 paletteIndex;
    u32 selectedPalettes = 0;

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[2] = gBattleAnimArgs[0];
        gTasks[taskId].data[3] = gBattleAnimArgs[1];
        gTasks[taskId].data[4] = gBattleAnimArgs[2];
        gTasks[taskId].data[1] = gBattleAnimArgs[3];
        gTasks[taskId].data[5] = gBattleAnimArgs[4];
        gTasks[taskId].data[6] = gBattleAnimArgs[5];
        gTasks[taskId].data[7] = gBattleAnimArgs[6];
    }

    gTasks[taskId].data[0]++;
    attackerBattler = gBattleAnimAttacker;
    targetBattler = gBattleAnimTarget;

    if (gTasks[taskId].data[2] & 0x100)
        selectedPalettes = 0x0000FFFF;

    if (gTasks[taskId].data[2] & 0x1)
    {
        paletteIndex = IndexOfSpritePaletteTag(gSprites[gHealthboxSpriteIds[attackerBattler]].template->paletteTag);
        selectedPalettes |= (1 << paletteIndex) << 16;
    }

    if (gTasks[taskId].data[3] & 0x100)
        selectedPalettes |= (1 << attackerBattler) << 16;

    if (gTasks[taskId].data[4] & 0x100)
        selectedPalettes |= (1 << targetBattler) << 16;

    TintPlttBuffer(selectedPalettes, gTasks[taskId].data[5], gTasks[taskId].data[6], gTasks[taskId].data[7]);
    if (gTasks[taskId].data[0] == gTasks[taskId].data[1])
    {
        UnfadePlttBuffer(selectedPalettes);
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimShakeMonOrBattleTerrain(struct Sprite *sprite)
{
    u16 var0;

    sprite->invisible = TRUE;
    sprite->data[0] = -gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];

    switch (gBattleAnimArgs[3])
    {
    case 0:
        StoreSpriteCallbackInData6(sprite, (void *)&gBattle_BG3_X);
        break;
    case 1:
        StoreSpriteCallbackInData6(sprite, (void *)&gBattle_BG3_Y);
        break;
    case 2:
        StoreSpriteCallbackInData6(sprite, (void *)&gSpriteCoordOffsetX);
        break;
    default:
        StoreSpriteCallbackInData6(sprite, (void *)&gSpriteCoordOffsetY);
        break;
    }

    sprite->data[4] = *(u16 *)(sprite->data[6] | (sprite->data[7] << 16));
    sprite->data[5] = gBattleAnimArgs[3];
    var0 = sprite->data[5] - 2;
    if (var0 < 2)
        AnimShakeMonOrBattleTerrain_UpdateCoordOffsetEnabled();

    sprite->callback = AnimShakeMonOrBattleTerrain_Step;
}

static void AnimShakeMonOrBattleTerrain_Step(struct Sprite *sprite)
{
    u8 i;
    u16 var0;

    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
        if (sprite->data[1] > 0)
        {
            sprite->data[1]--;
        }
        else
        {
            sprite->data[1] = sprite->data[2];
            *(u16 *)(sprite->data[6] | (sprite->data[7] << 16)) += sprite->data[0];
            sprite->data[0] = -sprite->data[0];
        }
    }
    else
    {
        *(u16 *)(sprite->data[6] | (sprite->data[7] << 16)) = sprite->data[4];
        var0 = sprite->data[5] - 2;
        if (var0 < 2)
        {
            for (i = 0; i < gBattlersCount; i++)
                gSprites[gBattlerSpriteIds[i]].coordOffsetEnabled = FALSE;
        }

        DestroyAnimSprite(sprite);
    }
}

static void AnimShakeMonOrBattleTerrain_UpdateCoordOffsetEnabled(void)
{
    gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = FALSE;
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = FALSE;

    if (gBattleAnimArgs[4] == 2)
    {
        gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = TRUE;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = TRUE;
    }
    else
    {
        if (gBattleAnimArgs[4] == 0)
            gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = TRUE;
        else
            gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = TRUE;
    }
}

// Task data for AnimTask_ShakeBattleTerrain
#define tXOffset     data[0]
#define tYOffset     data[1]
#define tNumShakes   data[2]
#define tTimer       data[3]
#define tShakeDelay  data[8]

// Can shake battle terrain back and forth on the X or down and back to original pos on Y (cant shake up from orig pos)
// arg0: x offset of shake
// arg1: y offset of shake
// arg2: number of shakes
// arg3: time between shakes
void AnimTask_ShakeBattleTerrain(u8 taskId)
{
    gTasks[taskId].tXOffset = gBattleAnimArgs[0];
    gTasks[taskId].tYOffset = gBattleAnimArgs[1];
    gTasks[taskId].tNumShakes = gBattleAnimArgs[2];
    gTasks[taskId].tTimer = gBattleAnimArgs[3];
    gTasks[taskId].tShakeDelay = gBattleAnimArgs[3];
    gBattle_BG3_X = gBattleAnimArgs[0];
    gBattle_BG3_Y = gBattleAnimArgs[1];
    gTasks[taskId].func = AnimTask_ShakeBattleTerrain_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_ShakeBattleTerrain_Step(u8 taskId)
{
    if (gTasks[taskId].tTimer == 0)
    {
        if (gBattle_BG3_X == gTasks[taskId].tXOffset)
            gBattle_BG3_X = -gTasks[taskId].tXOffset;
        else
            gBattle_BG3_X = gTasks[taskId].tXOffset;

        if (gBattle_BG3_Y == -gTasks[taskId].tYOffset)
            gBattle_BG3_Y = 0;
        else
            gBattle_BG3_Y = -gTasks[taskId].tYOffset;

        gTasks[taskId].tTimer = gTasks[taskId].tShakeDelay;
        if (--gTasks[taskId].tNumShakes == 0)
        {
            gBattle_BG3_X = 0;
            gBattle_BG3_Y = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
    else
    {
        gTasks[taskId].tTimer--;
    }
}

#undef tXOffset
#undef tYOffset
#undef tNumShakes
#undef tTimer
#undef tShakeDelay

void AnimHitSplatBasic(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Same as basic hit splat but takes a length of time to persist for (arg4)
static void AnimHitSplatPersistent(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSpriteAfterTimer);
}

// For paired hit splats whose position is inverted when used by the opponent on the player.
// Used by Twineedle and Spike Cannon
static void AnimHitSplatHandleInvert(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER && !IsContest())
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    AnimHitSplatBasic(sprite);
}

void AnimHitSplatRandom(struct Sprite *sprite)
{
    if (gBattleAnimArgs[1] == -1)
        gBattleAnimArgs[1] = Random2() & 3;

    if (!InitSpritePosToAnimBattler(gBattleAnimArgs[0], sprite, FALSE))
        return;
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[1]);

    sprite->x2 += (Random2() % 48) - 24;
    sprite->y2 += (Random2() % 24) - 12;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

void AnimHitSplatOnMonEdge(struct Sprite *sprite)
{
    sprite->data[0] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    sprite->x = gSprites[sprite->data[0]].x + gSprites[sprite->data[0]].x2;
    sprite->y = gSprites[sprite->data[0]].y + gSprites[sprite->data[0]].y2;
    sprite->x2 = gBattleAnimArgs[1];
    sprite->y2 = gBattleAnimArgs[2];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

void AnimCrossImpact(struct Sprite *sprite)
{
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[3];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = WaitAnimForDuration;
}

void AnimFlashingHitSplat(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = AnimFlashingHitSplat_Step;
}

void AnimFlashingHitSplat_Step(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    if (sprite->data[0]++ > 12)
        DestroyAnimSprite(sprite);
}
