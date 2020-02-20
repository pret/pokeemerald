#include "global.h"
#include "battle_anim.h"
#include "palette.h"
#include "random.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"

void AnimConfusionDuck(struct Sprite *);
void AnimSimplePaletteBlend(struct Sprite *);
u32 UnpackSelectedBattleAnimPalettes(s16);
void sub_81158A4(struct Sprite *);
void sub_81159B4(struct Sprite *);
void sub_81160A4(struct Sprite *);
static void AnimBasicHitSplat(struct Sprite *);
void sub_8116420(struct Sprite *);
static void AnimHitSplatRandom(struct Sprite *);
static void AnimExtremeSpeedHitSplat(struct Sprite *);
void sub_8116560(struct Sprite *);
static void AnimFlashingHitSplat(struct Sprite *);
static void AnimConfusionDuckStep(struct Sprite *);
static void AnimSimplePaletteBlendStep(struct Sprite *);
static void sub_81158F8(struct Sprite *);
static void sub_8115984(struct Sprite *);
static void BlendColorInCycle(u8, u8, u8);
static void AnimTask_BlendColorInCycleLoop(u8);
static void sub_8115BC8(u8, u8, u8);
static void sub_8115C18(u8);
static void sub_8115CD0(u8, u8, u8);
static void sub_8115D2C(u8);
static void sub_8115E00(u8);
static void sub_8115EB8(u8);
static void sub_8116148(struct Sprite *);
static void sub_81161F4(void);
static void sub_81162F8(u8);
static void sub_81163D0(struct Sprite *);
static void sub_81165E4(struct Sprite *);

const union AnimCmd gUnknown_0859722C[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gUnknown_08597240[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08597254[] =
{
    gUnknown_0859722C,
    gUnknown_08597240,
};

const struct SpriteTemplate gConfusionDuckSpriteTemplate =
{
    .tileTag = ANIM_TAG_DUCK,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gUnknown_08597254,
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
    .callback = sub_81158A4,
};

const union AnimCmd gUnknown_085972A4[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085972BC[] =
{
    gUnknown_085972A4,
};

const struct SpriteTemplate gUnknown_085972C0 =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gUnknown_085972BC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81159B4,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_85972D8 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81160A4,
};

const union AffineAnimCmd gUnknown_085972F0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597300[] =
{
    AFFINEANIMCMD_FRAME(0xD8, 0xD8, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597318[] =
{
    AFFINEANIMCMD_FRAME(0xB0, 0xB0, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08597330[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08597348[] =
{
    gUnknown_085972F0,
    gUnknown_08597300,
    gUnknown_08597318,
    gUnknown_08597330,
};

const struct SpriteTemplate gBasicHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = AnimBasicHitSplat,
};

// TODO: Needs generic descriptive name, what distinguishes this hit splat
const struct SpriteTemplate gSpikeHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_8116420,
};

const struct SpriteTemplate gWaterHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_IMPACT,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = AnimBasicHitSplat,
};

const struct SpriteTemplate gRandomPosHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = AnimHitSplatRandom,
};

// TODO: Needs generic descriptive name, what distinguishes this hit splat
const struct SpriteTemplate gExtremeSpeedHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = AnimExtremeSpeedHitSplat,
};

const struct SpriteTemplate gCrossImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_CROSS_IMPACT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8116560,
};

const struct SpriteTemplate gFlashingHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = AnimFlashingHitSplat,
};

// TODO: Needs generic descriptive name, what distinguishes this hit splat
const struct SpriteTemplate gRevengeHitSplatSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08597348,
    .callback = sub_81163D0,
};

// Moves a spinning duck around the mon's head.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wave offset
// arg 3: wave period (higher means faster wave)
// arg 4: duration
void AnimConfusionDuck(struct Sprite *sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
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
    sprite->callback = AnimConfusionDuckStep;
    sprite->callback(sprite);
}

static void AnimConfusionDuckStep(struct Sprite *sprite)
{
    sprite->pos2.x = Cos(sprite->data[0], 30);
    sprite->pos2.y = Sin(sprite->data[0], 10);

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
void AnimSimplePaletteBlend(struct Sprite *sprite)
{
    u32 selectedPalettes = UnpackSelectedBattleAnimPalettes(gBattleAnimArgs[0]);
    BeginNormalPaletteFade(selectedPalettes, gBattleAnimArgs[1], gBattleAnimArgs[2], gBattleAnimArgs[3], gBattleAnimArgs[4]);
    sprite->invisible = 1;
    sprite->callback = AnimSimplePaletteBlendStep;
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
u32 UnpackSelectedBattleAnimPalettes(s16 selector)
{
    u8 battleBackground = selector & 1;
    u8 attacker = (selector >> 1) & 1;
    u8 target = (selector >> 2) & 1;
    u8 attackerPartner = (selector >> 3) & 1;
    u8 targetPartner = (selector >> 4) & 1;
    u8 arg5 = (selector >> 5) & 1;
    u8 arg6 = (selector >> 6) & 1;
    return sub_80A75AC(battleBackground, attacker, target, attackerPartner, targetPartner, arg5, arg6);
}

static void AnimSimplePaletteBlendStep(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
        DestroyAnimSprite(sprite);
}

void sub_81158A4(struct Sprite *sprite)
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

    selectedPalettes = UnpackSelectedBattleAnimPalettes(sprite->data[7]);
    BlendPalettes(selectedPalettes, gBattleAnimArgs[4], gBattleAnimArgs[3]);
    sprite->invisible = 1;
    sprite->callback = sub_81158F8;
}

static void sub_81158F8(struct Sprite *sprite)
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
        sprite->callback = sub_8115984;
        return;
    }

    selectedPalettes = UnpackSelectedBattleAnimPalettes(sprite->data[7]);
    if (sprite->data[1] & 0x100)
        BlendPalettes(selectedPalettes, sprite->data[4], sprite->data[3]);
    else
        BlendPalettes(selectedPalettes, sprite->data[6], sprite->data[5]);

    sprite->data[1] ^= 0x100;
    sprite->data[0] = sprite->data[1] & 0xFF;
    sprite->data[2]--;
}

static void sub_8115984(struct Sprite *sprite)
{
    u32 selectedPalettes;

    if (!gPaletteFade.active)
    {
        selectedPalettes = UnpackSelectedBattleAnimPalettes(sprite->data[7]);
        BlendPalettes(selectedPalettes, 0, 0);
        DestroyAnimSprite(sprite);
    }
}

void sub_81159B4(struct Sprite *sprite)
{
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
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

// Task data for AnimTask_BlendColorCycle
#define tPalSelector   data[0]
#define tDelay         data[1]
#define tNumBlends     data[2]
#define tInitialBlendY data[3]
#define tTargetBlendY  data[4]
#define tBlendColor    data[5]
#define tRestoreBlend  data[8]

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
    BlendColorInCycle(taskId, 0, gTasks[taskId].tTargetBlendY);
    gTasks[taskId].func = AnimTask_BlendColorInCycleLoop;
}

static void BlendColorInCycle(u8 taskId, u8 startBlendAmount, u8 targetBlendAmount)
{
    u32 selectedPalettes = UnpackSelectedBattleAnimPalettes(gTasks[taskId].tPalSelector);
    BeginNormalPaletteFade(
        selectedPalettes,
        gTasks[taskId].tDelay,
        startBlendAmount,
        targetBlendAmount,
        gTasks[taskId].tBlendColor);

    gTasks[taskId].tNumBlends--;
    gTasks[taskId].tRestoreBlend ^= 1;
}

static void AnimTask_BlendColorInCycleLoop(u8 taskId)
{
    u8 startBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tNumBlends > 0)
        {
            if (gTasks[taskId].tRestoreBlend == FALSE)
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

            BlendColorInCycle(taskId, startBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

#undef tPalSelector
#undef tDelay
#undef tNumBlends
#undef tInitialBlendY
#undef tTargetBlendY
#undef tBlendColor
#undef tFirstBlendDone

void sub_8115B0C(u8 taskId)
{
    int battler;
    u32 selectedPalettes = 0;

    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].data[8] = 0;

    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler != gBattleAnimAttacker && battler != gBattleAnimTarget)
            selectedPalettes |= 1 << (battler + 16);
    }

    if (gBattleAnimArgs[0] == 1)
        selectedPalettes |= 0xE;

    gTasks[taskId].data[9] = selectedPalettes >> 16;
    gTasks[taskId].data[10] = selectedPalettes & 0xFF;
    sub_8115BC8(taskId, 0, gTasks[taskId].data[4]);
    gTasks[taskId].func = sub_8115C18;
}

static void sub_8115BC8(u8 taskId, u8 initialBlendAmount, u8 targetBlendAmount)
{
    u32 selectedPalettes = ((u16)gTasks[taskId].data[9] << 16) | (u16)gTasks[taskId].data[10];
    BeginNormalPaletteFade(
        selectedPalettes,
        gTasks[taskId].data[1],
        initialBlendAmount,
        targetBlendAmount,
        gTasks[taskId].data[5]);

    gTasks[taskId].data[2]--;
    gTasks[taskId].data[8] ^= 1;
}

static void sub_8115C18(u8 taskId)
{
    u8 initialBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].data[2] > 0)
        {
            if (gTasks[taskId].data[8] == 0)
            {
                initialBlendAmount = gTasks[taskId].data[3];
                targetBlendAmount = gTasks[taskId].data[4];
            }
            else
            {
                initialBlendAmount = gTasks[taskId].data[4];
                targetBlendAmount = gTasks[taskId].data[3];
            }

            if (gTasks[taskId].data[2] == 1)
                targetBlendAmount = 0;

            sub_8115BC8(taskId, initialBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

void sub_8115C80(u8 taskId)
{
    u8 paletteIndex;

    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].data[8] = 0;

    sub_8115CD0(taskId, 0, gTasks[taskId].data[4]);
    gTasks[taskId].func = sub_8115D2C;
}

static void sub_8115CD0(u8 taskId, u8 initialBlendAmount, u8 targetBlendAmount)
{
    u8 paletteIndex = IndexOfSpritePaletteTag(gTasks[taskId].data[0]);
    BeginNormalPaletteFade(
        1 << (paletteIndex + 16),
        gTasks[taskId].data[1],
        initialBlendAmount,
        targetBlendAmount,
        gTasks[taskId].data[5]);

    gTasks[taskId].data[2]--;
    gTasks[taskId].data[8] ^= 1;
}

static void sub_8115D2C(u8 taskId)
{
    u8 initialBlendAmount, targetBlendAmount;
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].data[2] > 0)
        {
            if (gTasks[taskId].data[8] == 0)
            {
                initialBlendAmount = gTasks[taskId].data[3];
                targetBlendAmount = gTasks[taskId].data[4];
            }
            else
            {
                initialBlendAmount = gTasks[taskId].data[4];
                targetBlendAmount = gTasks[taskId].data[3];
            }

            if (gTasks[taskId].data[2] == 1)
                targetBlendAmount = 0;

            sub_8115CD0(taskId, initialBlendAmount, targetBlendAmount);
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

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

    gTasks[taskId].func = sub_8115E00;
}

static void sub_8115E00(u8 taskId)
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
        gTasks[taskId].func = sub_8115EB8;
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

static void sub_8115EB8(u8 taskId)
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
    u8 attackerBattler = gBattleAnimAttacker;
    u8 targetBattler = gBattleAnimTarget;

    if (gBattleAnimArgs[0] & 0x100)
        selectedPalettes = sub_80A75AC(1, 0, 0, 0, 0, 0, 0);

    if (gBattleAnimArgs[1] & 0x100)
        selectedPalettes |= (0x10000 << attackerBattler);

    if (gBattleAnimArgs[2] & 0x100)
        selectedPalettes |= (0x10000 << targetBattler);

    InvertPlttBuffer(selectedPalettes);
    DestroyAnimVisualTask(taskId);
}

void sub_8115F94(u8 taskId)
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

void sub_81160A4(struct Sprite *sprite)
{
    u16 var0;

    sprite->invisible = 1;
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
        sub_81161F4();

    sprite->callback = sub_8116148;
}

static void sub_8116148(struct Sprite *sprite)
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
                gSprites[gBattlerSpriteIds[i]].coordOffsetEnabled = 0;
        }

        DestroyAnimSprite(sprite);
    }
}

static void sub_81161F4(void)
{
    gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = 0;
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = 0;

    if (gBattleAnimArgs[4] == 2)
    {
        gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = 1;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = 1;
    }
    else
    {
        if (gBattleAnimArgs[4] == 0)
            gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].coordOffsetEnabled = 1;
        else
            gSprites[gBattlerSpriteIds[gBattleAnimTarget]].coordOffsetEnabled = 1;
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
    gTasks[taskId].func = sub_81162F8;
    gTasks[taskId].func(taskId);
}

static void sub_81162F8(u8 taskId)
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

static void AnimBasicHitSplat(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void sub_81163D0(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, sub_810E2C8);
}

void sub_8116420(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER && !IsContest())
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
    
    AnimBasicHitSplat(sprite);
}

static void AnimHitSplatRandom(struct Sprite *sprite)
{
    if (gBattleAnimArgs[1] == -1)
        gBattleAnimArgs[1] = Random2() & 3;

    StartSpriteAffineAnim(sprite, gBattleAnimArgs[1]);
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 0);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->pos2.x += (Random2() % 48) - 24;
    sprite->pos2.y += (Random2() % 24) - 12;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

static void AnimExtremeSpeedHitSplat(struct Sprite *sprite)
{
    sprite->data[0] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x + gSprites[sprite->data[0]].pos2.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y + gSprites[sprite->data[0]].pos2.y;
    sprite->pos2.x = gBattleAnimArgs[1];
    sprite->pos2.y = gBattleAnimArgs[2];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

void sub_8116560(struct Sprite *sprite)
{
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[3];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = WaitAnimForDuration;
}

static void AnimFlashingHitSplat(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, 1);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->callback = sub_81165E4;
}

static void sub_81165E4(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    if (sprite->data[0]++ > 12)
        DestroyAnimSprite(sprite);
}
