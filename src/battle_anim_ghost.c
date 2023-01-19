#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "item_icon.h"
#include "palette.h"
#include "constants/rgb.h"
#include "scanline_effect.h"
#include "constants/songs.h"
#include "sound.h"
#include "trig.h"
#include "util.h"
#include "constants/moves.h"

static void AnimConfuseRayBallBounce(struct Sprite *);
static void AnimConfuseRayBallBounce_Step1(struct Sprite *);
static void AnimConfuseRayBallBounce_Step2(struct Sprite *);
static void UpdateConfuseRayBallBlend(struct Sprite *);
static void AnimConfuseRayBallSpiral(struct Sprite *);
static void AnimConfuseRayBallSpiral_Step(struct Sprite *);
static void AnimTask_NightShadeClone_Step1(u8 taskId);
static void AnimTask_NightShadeClone_Step2(u8 taskId);
static void AnimShadowBall_Step(struct Sprite *);
static void AnimLick(struct Sprite *);
static void AnimLick_Step(struct Sprite *);
static void AnimTask_NightmareClone_Step(u8 taskId);
static void AnimTask_SpiteTargetShadow_Step1(u8 taskId);
static void AnimTask_SpiteTargetShadow_Step2(u8 taskId);
static void AnimTask_SpiteTargetShadow_Step3(u8 taskId);
static void AnimDestinyBondWhiteShadow(struct Sprite *);
static void AnimDestinyBondWhiteShadow_Step(struct Sprite *);
static void AnimTask_DestinyBondWhiteShadow_Step(u8 taskId);
static void AnimTask_CurseStretchingBlackBg_Step1(u8 taskId);
static void AnimTask_CurseStretchingBlackBg_Step2(u8 taskId);
static void AnimCurseNail(struct Sprite *);
static void AnimCurseNail_Step1(struct Sprite *);
static void AnimCurseNail_Step2(struct Sprite *);
static void AnimCurseNail_End(struct Sprite *);
static void AnimGhostStatusSprite_Step(struct Sprite *);
static void AnimGrudgeFlame(struct Sprite *);
static void AnimMonMoveCircular(struct Sprite *);
static void AnimMonMoveCircular_Step(struct Sprite *);
static void AnimPoltergeistItem(struct Sprite *);

static const union AffineAnimCmd sAffineAnim_ConfuseRayBallBounce[] =
{
    AFFINEANIMCMD_FRAME(0x1E, 0x1E, 10, 5),
    AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 10, 5),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sAffineAnims_ConfuseRayBallBounce[] =
{
    sAffineAnim_ConfuseRayBallBounce,
};

const struct SpriteTemplate gConfuseRayBallBounceSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_ConfuseRayBallBounce,
    .callback = AnimConfuseRayBallBounce,
};

const struct SpriteTemplate gConfuseRayBallSpiralSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimConfuseRayBallSpiral,
};

static const union AffineAnimCmd sAffineAnim_ShadowBall[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gAffineAnims_ShadowBall[] =
{
    sAffineAnim_ShadowBall,
};

const struct SpriteTemplate gShadowBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gEnergyBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_ENERGY_BALL,
    .paletteTag = ANIM_TAG_ENERGY_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_LeafStorm =
{
    .tileTag = ANIM_TAG_RAZOR_LEAF,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gAffineAnims_AirWaveCrescent,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAirWaveCrescent,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_LeafStorm2 =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = AnimNeedleArmSpike,
};

static const union AnimCmd sAnim_Lick[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Lick[] =
{
    sAnim_Lick,
};

const struct SpriteTemplate gLickSpriteTemplate =
{
    .tileTag = ANIM_TAG_LICK,
    .paletteTag = ANIM_TAG_LICK,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = sAnims_Lick,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLick,
};

static const union AffineAnimCmd sAffineAnim_Unused[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

// Unused
static const union AffineAnimCmd *const sAffineAnims_Unused[] =
{
    sAffineAnim_Unused,
};

const struct SpriteTemplate gDestinyBondWhiteShadowSpriteTemplate =
{
    .tileTag = ANIM_TAG_WHITE_SHADOW,
    .paletteTag = ANIM_TAG_WHITE_SHADOW,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDestinyBondWhiteShadow,
};

const struct SpriteTemplate gDarkVoidBlackHoleTemplate =
{
    .tileTag = ANIM_TAG_WHITE_SHADOW,
    .paletteTag = ANIM_TAG_QUICK_GUARD_HAND,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDestinyBondWhiteShadow
};

const struct SpriteTemplate gCurseNailSpriteTemplate =
{
    .tileTag = ANIM_TAG_NAIL,
    .paletteTag = ANIM_TAG_NAIL,
    .oam = &gOamData_AffineOff_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCurseNail,
};

const struct SpriteTemplate gCurseGhostSpriteTemplate =
{
    .tileTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .paletteTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGhostStatusSprite,
};

const struct SpriteTemplate gNightmareDevilSpriteTemplate =
{
    .tileTag = ANIM_TAG_DEVIL,
    .paletteTag = ANIM_TAG_DEVIL,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGhostStatusSprite,
};

static const union AnimCmd sAnim_GrudgeFlame[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_GrudgeFlame[] =
{
    sAnim_GrudgeFlame,
};

const struct SpriteTemplate gGrudgeFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineOff_ObjBlend_16x32,
    .anims = sAnims_GrudgeFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrudgeFlame,
};

// Unused
static const struct SpriteTemplate sMonMoveCircularSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMonMoveCircular,
};

const struct SpriteTemplate gFlashCannonBallMovementTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_FLASH_CANNON_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

const struct SpriteTemplate gPoltergeistEffectTemplate =
{
    .tileTag = ANIM_TAG_POLTERGEIST,
    .paletteTag = ANIM_TAG_POLTERGEIST,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimPoltergeistItem,
};

static void AnimConfuseRayBallBounce(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslationWithSpeed(sprite);
    sprite->callback = AnimConfuseRayBallBounce_Step1;
    sprite->data[6] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, sprite->data[6]);
}

static void AnimConfuseRayBallBounce_Step1(struct Sprite *sprite)
{
    s16 r0;
    s16 r2;
    UpdateConfuseRayBallBlend(sprite);
    if (AnimTranslateLinear(sprite))
    {
        sprite->callback = AnimConfuseRayBallBounce_Step2;
        return;
    }

    sprite->x2 += Sin(sprite->data[5], 10);
    sprite->y2 += Cos(sprite->data[5], 15);
    r2 = sprite->data[5];
    sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    r0 = sprite->data[5];
    if (r2 != 0 && r2 <= 196)
        return;
    if (r0 <= 0)
        return;
    PlaySE12WithPanning(SE_M_CONFUSE_RAY, gAnimCustomPanning);
}

static void AnimConfuseRayBallBounce_Step2(struct Sprite *sprite)
{
    s16 r2;
    s16 r0;
    sprite->data[0] = 1;
    AnimTranslateLinear(sprite);
    sprite->x2 += Sin(sprite->data[5], 10);
    sprite->y2 += Cos(sprite->data[5], 15);

    r2 = sprite->data[5];
    sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    r0 = sprite->data[5];

    if (r2 == 0 || r2 > 196)
    {
        if (r0 > 0)
            PlaySE(SE_M_CONFUSE_RAY);
    }

    if (sprite->data[6] == 0)
    {
        sprite->invisible = TRUE;
        sprite->callback = DestroyAnimSpriteAndDisableBlend;
    }
    else
        UpdateConfuseRayBallBlend(sprite);
}

static void UpdateConfuseRayBallBlend(struct Sprite *sprite)
{
    if (sprite->data[6] > 0xFF)
    {
        if (++sprite->data[6] == 0x10d)
            sprite->data[6] = 0;
        return;
    }

    if ((sprite->data[7]++ & 0xFF) == 0)
    {
        sprite->data[7] &= 0xff00;
        if ((sprite->data[7] & 0x100) != 0)
            sprite->data[6]++;
        else
            sprite->data[6]--;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], 16 - sprite->data[6]));
        if (sprite->data[6] == 0 || sprite->data[6] == 16)
            sprite->data[7] ^= 0x100;
        if (sprite->data[6] == 0)
            sprite->data[6] = 0x100;
    }
}

static void AnimConfuseRayBallSpiral(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->callback = AnimConfuseRayBallSpiral_Step;
    sprite->callback(sprite);
}

static void AnimConfuseRayBallSpiral_Step(struct Sprite *sprite)
{
    u16 temp1;
    sprite->x2 = Sin(sprite->data[0], 32);
    sprite->y2 = Cos(sprite->data[0], 8);
    temp1 = sprite->data[0] - 65;
    if (temp1 <= 130)
        sprite->oam.priority = 2;
    else
        sprite->oam.priority = 1;
    sprite->data[0] = (sprite->data[0] + 19) & 0xFF;
    sprite->data[2] += 80;
    sprite->y2 += sprite->data[2] >> 8;
    sprite->data[7] += 1;
    if (sprite->data[7] == 61)
        DestroyAnimSprite(sprite);
}

// Creates a large transparent clone of the attacker centered on their position which shrinks to original size
void AnimTask_NightShadeClone(u8 taskId)
{
    u8 spriteId;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
    SetSpriteRotScale(spriteId, 128, 128, 0);
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].data[0] = 128;
    gTasks[taskId].data[1] = *gBattleAnimArgs;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 16;
    gTasks[taskId].func = AnimTask_NightShadeClone_Step1;
}

static void AnimTask_NightShadeClone_Step1(u8 taskId)
{
    gTasks[taskId].data[10] += 1;
    if (gTasks[taskId].data[10] == 3)
    {
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].data[2] += 1;
        gTasks[taskId].data[3] -= 1;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[2], gTasks[taskId].data[3]));
        if (gTasks[taskId].data[2] != 9)
            return;

        gTasks[taskId].func = AnimTask_NightShadeClone_Step2;
    }
}

static void AnimTask_NightShadeClone_Step2(u8 taskId)
{
    u8 spriteId;
    if (gTasks[taskId].data[1] > 0)
    {
        gTasks[taskId].data[1] -= 1;
        return;
    }

    spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    gTasks[taskId].data[0] += 8;
    if (gTasks[taskId].data[0] <= 0xFF)
    {
        SetSpriteRotScale(spriteId, gTasks[taskId].data[0], gTasks[taskId].data[0], 0);
    }
    else
    {
        ResetSpriteRotScale(spriteId);
        DestroyAnimVisualTask(taskId);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    }
}

// Spins a sprite towards the target, pausing in the middle.
// Used in Shadow Ball.
// arg 0: duration step 1 (attacker -> center)
// arg 1: duration step 2 (spin center)
// arg 2: duration step 3 (center -> target)
void AnimShadowBall(struct Sprite *sprite)
{
    s16 oldPosX = sprite->x;
    s16 oldPosY = sprite->y;

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = sprite->x << 4;
    sprite->data[5] = sprite->y << 4;
    sprite->data[6] = ((oldPosX - sprite->x) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->data[7] = ((oldPosY - sprite->y) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->callback = AnimShadowBall_Step;
}

static void AnimShadowBall_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->x = sprite->data[4] >> 4;
        sprite->y = sprite->data[5] >> 4;
        sprite->data[1] -= 1;
        if (sprite->data[1] > 0)
            break;
        sprite->data[0] += 1;
        break;
    case 1:
        sprite->data[2] -= 1;
        if (sprite->data[2] > 0)
            break;
        sprite->data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->data[4] = sprite->x << 4;
        sprite->data[5] = sprite->y << 4;
        sprite->data[6] = ((sprite->data[1] - sprite->x) << 4) / sprite->data[3];
        sprite->data[7] = ((sprite->data[2] - sprite->y) << 4) / sprite->data[3];
        sprite->data[0] += 1;
        break;
    case 2:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->x = sprite->data[4] >> 4;
        sprite->y = sprite->data[5] >> 4;
        sprite->data[3] -= 1;
        if (sprite->data[3] > 0)
            break;
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->data[0] += 1;
        break;
    case 3:
        DestroySpriteAndMatrix(sprite);
        break;
    }
}

static void AnimLick(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->callback = AnimLick_Step;
}

static void AnimLick_Step(struct Sprite *sprite)
{
    bool8 r5 = FALSE;
    bool8 r6 = FALSE;

    if (sprite->animEnded)
    {
        if (!sprite->invisible)
            sprite->invisible = TRUE;

        switch (sprite->data[0])
        {
        default:
            r6 = TRUE;
            break;
        case 0:
            if (sprite->data[1] == 2)
                r5 = TRUE;
            break;
        case 1:
            if (sprite->data[1] == 4)
                r5 = TRUE;
            break;
        }

        if (r5)
        {
            sprite->invisible ^= 1;
            sprite->data[2]++;
            sprite->data[1] = 0;
            if (sprite->data[2] == 5)
            {
                sprite->data[2] = 0;
                sprite->data[0]++;
            }
        }
        else if (r6)
        {
            DestroyAnimSprite(sprite);
        }
        else
        {
            sprite->data[1]++;
        }
    }
}

// Creates a transparent clone of the target which drifts up and away to the side
void AnimTask_NightmareClone(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->data[0] = CloneBattlerSpriteWithBlend(ANIM_TARGET);
    if (task->data[0] < 0)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
    task->data[1] = 0;
    task->data[2] = 15;
    task->data[3] = 2;
    task->data[4] = 0;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[2], task->data[3]));
    gSprites[task->data[0]].data[0] = 80;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        gSprites[task->data[0]].data[1] = -144;
        gSprites[task->data[0]].data[2] = 112;
    }
    else
    {
        gSprites[task->data[0]].data[1] = 144;
        gSprites[task->data[0]].data[2] = -112;
    }
    gSprites[task->data[0]].data[3] = 0;
    gSprites[task->data[0]].data[4] = 0;
    StoreSpriteCallbackInData6(&gSprites[task->data[0]], SpriteCallbackDummy);
    gSprites[task->data[0]].callback = TranslateSpriteLinearFixedPoint;
    task->func = AnimTask_NightmareClone_Step;
}

static void AnimTask_NightmareClone_Step(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    switch (task->data[4])
    {
    case 0:
        task->data[1] += 1;
        task->data[5] = task->data[1] & 3;
        if (task->data[5] == 1)
            if (task->data[2] > 0)
                task->data[2] -= 1;
        if (task->data[5] == 3)
            if (task->data[3] <= 15)
                task->data[3] += 1;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[2], task->data[3]));
        if (task->data[3] != 16 || task->data[2] != 0)
            break;
        if (task->data[1] <= 80)
            break;
        DestroySpriteWithActiveSheet(&gSprites[task->data[0]]);
        task->data[4] = 1;
        break;
    case 1:
        if (++task->data[6] <= 1)
            break;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        task->data[4] += 1;
        break;
    case 2:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Creates a blended copy of the target that wavers in front of them
void AnimTask_SpiteTargetShadow(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->data[15] = 0;
    task->func = AnimTask_SpiteTargetShadow_Step1;
    task->func(taskId);
}

static void AnimTask_SpiteTargetShadow_Step1(u8 taskId)
{
    s16 startLine;
    struct Task *task = &gTasks[taskId];
    u8 position = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);

    switch (task->data[15])
    {
    case 0:
        task->data[14] = AllocSpritePalette(ANIM_TAG_BENT_SPOON);
        if (task->data[14] == 0xFF || task->data[14] == 0xF)
        {
            DestroyAnimVisualTask(taskId);
        }
        else
        {
            task->data[0] = CloneBattlerSpriteWithBlend(ANIM_TARGET);
            if (task->data[0] < 0)
            {
                FreeSpritePaletteByTag(ANIM_TAG_BENT_SPOON);
                DestroyAnimVisualTask(taskId);
            }
            else
            {
                s16 mask2;
                gSprites[task->data[0]].oam.paletteNum = task->data[14];
                gSprites[task->data[0]].oam.objMode = ST_OAM_OBJ_NORMAL;
                gSprites[task->data[0]].oam.priority = 3;
                gSprites[task->data[0]].invisible = (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].invisible);
                task->data[1] = 0;
                task->data[2] = 0;
                task->data[3] = 16;
                task->data[13] = GetAnimBattlerSpriteId(ANIM_TARGET);
                task->data[4] = (gSprites[task->data[13]].oam.paletteNum + 16) * 16;
                if (position == 1) {
                    u16 mask = DISPCNT_BG1_ON;
                    mask2 = mask;
                }
                else {
                    u16 mask = DISPCNT_BG2_ON;
                    mask2 = mask;
                }
                ClearGpuRegBits(REG_OFFSET_DISPCNT, mask2);
                task->data[15]++;
            }
        }
        break;
    case 1:
        task->data[14] = (task->data[14] + 16) * 16;
        CpuCopy32(&gPlttBufferUnfaded[task->data[4]], &gPlttBufferFaded[task->data[14]], 32);
        BlendPalette(task->data[4], 16, 10, RGB(13, 0, 15));
        task->data[15]++;
        break;
    case 2:
        startLine = gSprites[task->data[13]].y + gSprites[task->data[13]].y2 - 32;
        if (startLine < 0)
            startLine = 0;

        if (position == 1)
            task->data[10] = ScanlineEffect_InitWave(startLine, startLine + 64, 2, 6, 0, SCANLINE_EFFECT_REG_BG1HOFS, TRUE);
        else
            task->data[10] = ScanlineEffect_InitWave(startLine, startLine + 64, 2, 6, 0, SCANLINE_EFFECT_REG_BG2HOFS, TRUE);

        task->data[15]++;
        break;
    case 3:
        if (position == 1)
            SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL | BLDCNT_TGT1_BG1));
        else
            SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL | BLDCNT_TGT1_BG2));

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
        task->data[15]++;
        break;
    case 4:
        if (position == 1)
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON);
        else
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);

        task->func = AnimTask_SpiteTargetShadow_Step2;
        task->data[15]++;
        break;
    default:
        task->data[15]++;
        break;
    }
}

static void AnimTask_SpiteTargetShadow_Step2(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[1]++;
    task->data[5] = task->data[1] & 1;
    if (task->data[5] == 0)
        task->data[2] = gSineTable[task->data[1]] / 18;

    if (task->data[5] == 1)
        task->data[3] = 16 - (gSineTable[task->data[1]] / 18);

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[2], task->data[3]));
    if (task->data[1] == 128)
    {
        task->data[15] = 0;
        task->func = AnimTask_SpiteTargetShadow_Step3;
        task->func(taskId);
    }
}

static void AnimTask_SpiteTargetShadow_Step3(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 rank = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);

    switch (task->data[15])
    {
    case 0:
        gScanlineEffect.state = 3;
        task->data[14] = GetAnimBattlerSpriteId(ANIM_TARGET);
        if (rank == 1)
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON);
        else
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        break;
    case 1:
        BlendPalette(task->data[4], 16, 0, RGB(13, 0, 15));
        break;
    case 2:
        gSprites[task->data[14]].invisible = TRUE;
        DestroySpriteWithActiveSheet(&gSprites[task->data[0]]);
        FreeSpritePaletteByTag(ANIM_TAG_BENT_SPOON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        if (rank == 1)
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON);
        else
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);

        DestroyAnimVisualTask(taskId);
        break;
    }

    task->data[15]++;
}

static void AnimDestinyBondWhiteShadow(struct Sprite *sprite)
{
    s16 battler1X, battler1Y;
    s16 battler2X, battler2Y;
    s16 yDiff;

    if (gBattleAnimArgs[0] == 0)
    {
        battler1X = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        battler1Y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 28;
        battler2X = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        battler2Y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 28;
    }
    else
    {
        battler1X = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        battler1Y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 28;
        battler2X = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        battler2Y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 28;
    }

    yDiff = battler2Y - battler1Y;
    sprite->data[0] = battler1X * 16;
    sprite->data[1] = battler1Y * 16;
    sprite->data[2] = ((battler2X - battler1X) * 16) / gBattleAnimArgs[1];
    sprite->data[3] = (yDiff * 16) / gBattleAnimArgs[1];
    sprite->data[4] = gBattleAnimArgs[1];
    sprite->data[5] = battler2X;
    sprite->data[6] = battler2Y;
    sprite->data[7] = sprite->data[4] / 2;
    sprite->oam.priority = 2;
    sprite->x = battler1X;
    sprite->y = battler1Y;
    sprite->callback = AnimDestinyBondWhiteShadow_Step;
    sprite->invisible = TRUE;
}

static void AnimDestinyBondWhiteShadow_Step(struct Sprite *sprite)
{
    if (sprite->data[4])
    {
        sprite->data[0] += sprite->data[2];
        sprite->data[1] += sprite->data[3];
        sprite->x = sprite->data[0] >> 4;
        sprite->y = sprite->data[1] >> 4;
        if (--sprite->data[4] == 0)
            sprite->data[0] = 0;
    }
}

void AnimTask_DestinyBondWhiteShadow(u8 taskId)
{
    struct Task *task;
    s16 battler;
    u8 spriteId;
    s16 baseX, baseY;
    s16 x, y;

    task = &gTasks[taskId];
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    task->data[5] = 0;
    task->data[6] = 0;
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 16;
    task->data[10] = gBattleAnimArgs[0];

    baseX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    baseY = GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_BOTTOM);
    if (!IsContest())
    {
        for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            if (battler != gBattleAnimAttacker
             && battler != BATTLE_PARTNER(gBattleAnimAttacker)
             && IsBattlerSpriteVisible(battler))
            {
                if (gAnimMoveIndex == MOVE_DARK_VOID
                 || gAnimMoveIndex == MOVE_POLTERGEIST)
                    spriteId = CreateSprite(&gDarkVoidBlackHoleTemplate, baseX, baseY, 55);   //dark void
                else
                    spriteId = CreateSprite(&gDestinyBondWhiteShadowSpriteTemplate, baseX, baseY, 55);   //destiny bond

                if (spriteId != MAX_SPRITES)
                {
                    x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
                    y = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_BOTTOM);
                    gSprites[spriteId].data[0] = baseX << 4;
                    gSprites[spriteId].data[1] = baseY << 4;
                    gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[4] = gBattleAnimArgs[1];
                    gSprites[spriteId].data[5] = x;
                    gSprites[spriteId].data[6] = y;
                    gSprites[spriteId].callback = AnimDestinyBondWhiteShadow_Step;

                    task->data[task->data[12] + 13] = spriteId;
                    task->data[12]++;
                }
            }
        }
    }
    else
    {
        if (gAnimMoveIndex == MOVE_DARK_VOID)
            spriteId = CreateSprite(&gDarkVoidBlackHoleTemplate, baseX, baseY, 55);   //dark void
        else
            spriteId = CreateSprite(&gDestinyBondWhiteShadowSpriteTemplate, baseX, baseY, 55);   //destiny bond

        if (spriteId != MAX_SPRITES)
        {
            x = 48;
            y = 40;
            gSprites[spriteId].data[0] = baseX << 4;
            gSprites[spriteId].data[1] = baseY << 4;
            gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[4] = gBattleAnimArgs[1];
            gSprites[spriteId].data[5] = x;
            gSprites[spriteId].data[6] = y;
            gSprites[spriteId].callback = AnimDestinyBondWhiteShadow_Step;

            task->data[13] = spriteId;
            task->data[12] = 1;
        }
    }

    task->func = AnimTask_DestinyBondWhiteShadow_Step;
}

static void AnimTask_DestinyBondWhiteShadow_Step(u8 taskId)
{
    u16 i;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (task->data[6] == 0)
        {
            if (++task->data[5] > 1)
            {
                task->data[5] = 0;
                task->data[7]++;
                if (task->data[7] & 1)
                {
                    if (task->data[8] < 16)
                        task->data[8]++;
                }
                else
                {
                    if (task->data[9])
                        task->data[9]--;
                }

                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[8], task->data[9]));
                if (task->data[7] >= 24)
                {
                    task->data[7] = 0;
                    task->data[6] = 1;
                }
            }
        }

        if (task->data[10])
            task->data[10]--;
        else if (task->data[6])
            task->data[0]++;
        break;
    case 1:
        if (++task->data[5] > 1)
        {
            task->data[5] = 0;
            task->data[7]++;
            if (task->data[7] & 1)
            {
                if (task->data[8])
                    task->data[8]--;
            }
            else
            {
                if (task->data[9] < 16)
                    task->data[9]++;
            }

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[8], task->data[9]));
            if (task->data[8] == 0 && task->data[9] == 16)
            {
                for (i = 0; i < task->data[12]; i++)
                    DestroySprite(&gSprites[task->data[i + 13]]);

                task->data[0]++;
            }
        }
        break;
    case 2:
        if (++task->data[5] > 0)
            task->data[0]++;
        break;
    case 3:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_CurseStretchingBlackBg(u8 taskId)
{
    s16 startX, startY;
    s16 leftDistance, topDistance, bottomDistance, rightDistance;

    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WININ, ((WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR) |
                                    (WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR)));
    SetGpuReg(REG_OFFSET_WINOUT, ((WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ) |
                                    (WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR)));
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_DARKEN));
    SetGpuReg(REG_OFFSET_BLDY, 16);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER || IsContest())
        startX = 40;
    else
        startX = 200;

    gBattle_WIN0H = WIN_RANGE(startX, startX);
    startY = 40;
    gBattle_WIN0V = WIN_RANGE(startY, startY);

    leftDistance = startX;
    rightDistance = DISPLAY_WIDTH - startX;
    topDistance = startY;
    bottomDistance = 72;
    gTasks[taskId].data[1] = leftDistance;
    gTasks[taskId].data[2] = rightDistance;
    gTasks[taskId].data[3] = topDistance;
    gTasks[taskId].data[4] = bottomDistance;
    gTasks[taskId].data[5] = startX;
    gTasks[taskId].data[6] = startY;
    gTasks[taskId].func = AnimTask_CurseStretchingBlackBg_Step1;
}

static void AnimTask_CurseStretchingBlackBg_Step1(u8 taskId)
{
    s16 step;
    s16 leftDistance, rightDistance, topDistance, bottomDistance;
    s16 startX, startY;
    u16 left, right, top, bottom;
    u16 selectedPalettes;

    step = gTasks[taskId].data[0];
    gTasks[taskId].data[0]++;
    leftDistance = gTasks[taskId].data[1];
    rightDistance = gTasks[taskId].data[2];
    topDistance = gTasks[taskId].data[3];
    bottomDistance = gTasks[taskId].data[4];
    startX = gTasks[taskId].data[5];
    startY = gTasks[taskId].data[6];

    if (step < 16)
    {
        left   = startX - (leftDistance   * 0.0625) * step;
        right  = startX + (rightDistance  * 0.0625) * step;
        top    = startY - (topDistance    * 0.0625) * step;
        bottom = startY + (bottomDistance * 0.0625) * step;
    }
    else
    {
        left = 0;
        right = DISPLAY_WIDTH;
        top = 0;
        bottom = 112;
        selectedPalettes = GetBattlePalettesMask(TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 16, RGB(0, 0, 0));
        gTasks[taskId].func = AnimTask_CurseStretchingBlackBg_Step2;
    }

    gBattle_WIN0H = WIN_RANGE(left, right);
    gBattle_WIN0V = WIN_RANGE(top, bottom);
}

static void AnimTask_CurseStretchingBlackBg_Step2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gBattle_WIN0H = 0;
        gBattle_WIN0V = 0;
        SetGpuReg(REG_OFFSET_WININ, ((WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR) |
                                        (WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR)));
        SetGpuReg(REG_OFFSET_WINOUT, ((WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR) |
                                        (WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR)));
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimCurseNail(struct Sprite *sprite)
{
    s16 xDelta;
    s16 xDelta2;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        xDelta = 24;
        xDelta2 = -2;
        sprite->oam.matrixNum = ST_OAM_HFLIP;
    }
    else
    {
        xDelta = -24;
        xDelta2 = 2;
    }

    sprite->x += xDelta;
    sprite->data[1] = xDelta2;
    sprite->data[0] = 60;
    sprite->callback = AnimCurseNail_Step1;
}

static void AnimCurseNail_Step1(struct Sprite *sprite)
{
    u16 var0;

    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
    }
    else
    {
        sprite->x2 += sprite->data[1];
        var0 = sprite->x2 + 7;
        if (var0 > 14)
        {
            sprite->x += sprite->x2;
            sprite->x2 = 0;
            sprite->oam.tileNum += 8;
            if (++sprite->data[2] == 3)
            {
                sprite->data[0] = 30;
                sprite->callback = WaitAnimForDuration;
                StoreSpriteCallbackInData6(sprite, AnimCurseNail_Step2);
            }
            else
            {
                sprite->data[0] = 40;
            }
        }
    }
}

static void AnimCurseNail_Step2(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        sprite->data[0]++;
        sprite->data[1] = 0;
        sprite->data[2] = 0;
    }
    else if (sprite->data[1] < 2)
    {
        sprite->data[1]++;
    }
    else
    {
        sprite->data[1] = 0;
        sprite->data[2]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, (16 - sprite->data[2]) | (sprite->data[2] << 8));
        if (sprite->data[2] == 16)
        {
            sprite->invisible = TRUE;
            sprite->callback = AnimCurseNail_End;
        }
    }
}

static void AnimCurseNail_End(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    DestroyAnimSprite(sprite);
}

void AnimGhostStatusSprite(struct Sprite *sprite)
{
    u16 coeffB;
    u16 coeffA;

    sprite->x2 = Sin(sprite->data[0], 12);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x2 = -sprite->x2;

    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1] += 0x100;
    sprite->y2 = -(sprite->data[1] >> 8);

    sprite->data[7]++;
    if (sprite->data[7] == 1)
    {
        sprite->data[6] = 0x050B;
        SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
        SetGpuReg(REG_OFFSET_BLDALPHA, sprite->data[6]);
    }
    else if (sprite->data[7] > 30)
    {
        sprite->data[2]++;
        coeffB = sprite->data[6] >> 8;
        coeffA = sprite->data[6] & 0xFF;

        if (++coeffB > 16)
            coeffB = 16;
        --coeffA;
        if ((s16)coeffA < 0)
            coeffA = 0;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(coeffA, coeffB));
        sprite->data[6] = BLDALPHA_BLEND(coeffA, coeffB);
        if (coeffB == 16 && coeffA == 0)
        {
            sprite->invisible = TRUE;
            sprite->callback = AnimGhostStatusSprite_Step;
        }
    }
}

static void AnimGhostStatusSprite_Step(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void AnimTask_GrudgeFlames(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 16;
    task->data[9] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[10] = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
    task->data[11] = (GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_WIDTH) / 2) + 8;
    task->data[7] = 0;
    task->data[5] = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    task->data[6] = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 2;
    task->data[3] = 0;
    task->data[4] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    task->data[8] = 0;
    task->func = AnimTask_GrudgeFlames_Step;
}

void AnimTask_GrudgeFlames_Step(u8 taskId)
{
    u16 i;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        for (i = 0; i < 6; i++)
        {
            spriteId = CreateSprite(&gGrudgeFlameSpriteTemplate, task->data[9], task->data[10], task->data[6]);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].data[0] = taskId;
                gSprites[spriteId].data[1] = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER;

                gSprites[spriteId].data[2] = (i * 42) & 0xFF;
                gSprites[spriteId].data[3] = task->data[11];
                gSprites[spriteId].data[5] = i * 6;
                task->data[7]++;
            }
        }

        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] & 1)
        {
            if (task->data[3] < 14)
                task->data[3]++;
        }
        else
        {
            if (task->data[4] > 4)
                task->data[4]--;
        }

        if (task->data[3] == 14 && task->data[4] == 4)
        {
            task->data[1] = 0;
            task->data[0]++;
        }

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
        break;
    case 2:
        if (++task->data[1] > 30)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (++task->data[1] & 1)
        {
            if (task->data[3] > 0)
                task->data[3]--;
        }
        else
        {
            if (task->data[4] < 16)
                task->data[4]++;
        }

        if (task->data[3] == 0 && task->data[4] == 16)
        {
            task->data[8] = 1;
            task->data[0]++;
        }

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
        break;
    case 4:
        if (task->data[7] == 0)
            task->data[0]++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimGrudgeFlame(struct Sprite *sprite)
{
    u16 index;

    if (sprite->data[1] == 0)
        sprite->data[2] += 2;
    else
        sprite->data[2] -= 2;

    sprite->data[2] &= 0xFF;
    sprite->x2 = Sin(sprite->data[2], sprite->data[3]);

    index = sprite->data[2] - 65;
    if (index < 127)
        sprite->oam.priority = gTasks[sprite->data[0]].data[5] + 1;
    else
        sprite->oam.priority = gTasks[sprite->data[0]].data[5];

    sprite->data[5]++;
    sprite->data[6] = (sprite->data[5] * 8) & 0xFF;
    sprite->y2 = Sin(sprite->data[6], 7);
    if (gTasks[sprite->data[0]].data[8])
    {
        gTasks[sprite->data[0]].data[7]--;
        DestroySprite(sprite);
    }
}

static void AnimMonMoveCircular(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
    sprite->data[5] = gBattlerSpriteIds[gBattleAnimAttacker];
    sprite->data[0] = 128;
    sprite->data[1] = 10;
    sprite->data[2] = gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[1];
    sprite->callback = AnimMonMoveCircular_Step;

    gSprites[sprite->data[5]].y += 8;
}

static void AnimMonMoveCircular_Step(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->data[3]--;
        gSprites[sprite->data[5]].x2 = Sin(sprite->data[0], sprite->data[1]);
        gSprites[sprite->data[5]].y2 = Cos(sprite->data[0], sprite->data[1]);
        sprite->data[0] += sprite->data[2];
        if (sprite->data[0] > 255)
            sprite->data[0] -= 256;
    }
    else
    {
        gSprites[sprite->data[5]].x2 = 0;
        gSprites[sprite->data[5]].y2 = 0;
        gSprites[sprite->data[5]].y -= 8;
        sprite->callback = DestroySpriteAndMatrix;
    }
}

void AnimTask_PoltergeistItem(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    u8 y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + (GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT) / 2);

    task->data[0] = AddItemIconSprite(ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gLastUsedItem);
    gSprites[task->data[0]].x = x + 4;
    gSprites[task->data[0]].y = y + 4;
    gSprites[task->data[0]].data[0] = x + 4;
    gSprites[task->data[0]].data[1] = y + 4;
    gSprites[task->data[0]].callback = AnimPoltergeistItem;

    task->data[1] = CreateSprite(&gPoltergeistEffectTemplate, x, y, 1);
    gSprites[task->data[1]].data[0] = x;
    gSprites[task->data[1]].data[1] = y;

    gAnimVisualTaskCount += 2;

    DestroyAnimVisualTask(taskId);
}

static void AnimPoltergeistItem(struct Sprite *sprite)
{
    sprite->data[2] += 4;

    sprite->x = sprite->data[0] + Sin(sprite->data[2], 24);
    sprite->y = sprite->data[1] + (Cos(sprite->data[2], 24) - 24);

    if (sprite->data[2] == 256)
        DestroyAnimSprite(sprite);
}

//pulverizing pancake - destiny bond shadow from attacker to target
void AnimTask_PulverizingPancakeWhiteShadow(u8 taskId)
{
    struct Task *task;
    s16 battler;
    u8 spriteId;
    s16 baseX, baseY;
    s16 x, y;

    task = &gTasks[taskId];
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    task->data[5] = 0;
    task->data[6] = 0;
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 16;
    task->data[10] = gBattleAnimArgs[0];

    baseX = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    baseY = GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_BOTTOM);
    if (!IsContest())
    {
        spriteId = CreateSprite(&gDestinyBondWhiteShadowSpriteTemplate, baseX, baseY, 55);
        if (spriteId != MAX_SPRITES)
        {
            x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
            y = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_BOTTOM);
            gSprites[spriteId].data[0] = baseX << 4;
            gSprites[spriteId].data[1] = baseY << 4;
            gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[4] = gBattleAnimArgs[1];
            gSprites[spriteId].data[5] = x;
            gSprites[spriteId].data[6] = y;
            gSprites[spriteId].callback = AnimDestinyBondWhiteShadow_Step;

            task->data[task->data[12] + 13] = spriteId;
            task->data[12]++;
        }
    }
    else
    {
        spriteId = CreateSprite(&gDestinyBondWhiteShadowSpriteTemplate, baseX, baseY, 55);
        if (spriteId != MAX_SPRITES)
        {
            x = 48;
            y = 40;
            gSprites[spriteId].data[0] = baseX << 4;
            gSprites[spriteId].data[1] = baseY << 4;
            gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
            gSprites[spriteId].data[4] = gBattleAnimArgs[1];
            gSprites[spriteId].data[5] = x;
            gSprites[spriteId].data[6] = y;
            gSprites[spriteId].callback = AnimDestinyBondWhiteShadow_Step;

            task->data[13] = spriteId;
            task->data[12] = 1;
        }
    }

    task->func = AnimTask_DestinyBondWhiteShadow_Step;
}
