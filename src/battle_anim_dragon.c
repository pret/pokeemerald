#include "global.h"
#include "battle_anim.h"
#include "battle_anim_internal.h"
#include "scanline_effect.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"

static void AnimDragonDanceOrb_Step(struct Sprite *);
static void AnimOverheatFlame_Step(struct Sprite *);
static void AnimTask_DragonDanceWaver_Step(u8);
static void UpdateDragonDanceScanlineEffect(struct Task *);
static void AnimDragonRush(struct Sprite *sprite);
static void AnimDragonRushStep(struct Sprite *sprite);
static void AnimSpinningDracoMeteor(struct Sprite *sprite);
static void AnimSpinningDracoMeteorFinish(struct Sprite *sprite);
static void AnimDracoMeteorRock_Step(struct Sprite *sprite);

static const union AnimCmd sAnim_OutrageOverheatFire_0[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_OutrageOverheatFire[] =
{
    sAnim_OutrageOverheatFire_0,
};

const struct SpriteTemplate gOutrageFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_OutrageOverheatFire,
    .callback = AnimOutrageFlame,
};

static const union AnimCmd sAnim_DreepyMissileOpponent_0[] =
{
    ANIMCMD_FRAME(0, 0, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_DreepyMissileOpponent[] =
{
    sAnim_DreepyMissileOpponent_0,
};

static const union AnimCmd sAnim_DreepyMissilePlayer_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_DreepyMissilePlayer[] =
{
    sAnim_DreepyMissilePlayer_0,
};

static const union AnimCmd sAnim_DreepyMissileNotDrag_0[] =
{
    ANIMCMD_FRAME(0, 0, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_DreepyMissileOpponentNotDrag[] =
{
    sAnim_DreepyMissileNotDrag_0,
};

static const union AnimCmd sAnim_DragonBreathFire_0[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_DragonBreathFire_1[] =
{
    ANIMCMD_FRAME(16, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gAnims_DragonBreathFire[] =
{
    sAnim_DragonBreathFire_0,
    sAnim_DragonBreathFire_1,
};

static const union AffineAnimCmd sAffineAnim_DragonBreathFire_0[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 127, 0),
    AFFINEANIMCMD_FRAME(0xD, 0xD, 0, 100),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_DragonBreathFire_1[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0xD, 0xD, 0, 100),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAffineAnims_DragonBreathFire[] =
{
    sAffineAnim_DragonBreathFire_0,
    sAffineAnim_DragonBreathFire_1,
};

const struct SpriteTemplate gDragonBreathFireSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .affineAnims = gAffineAnims_DragonBreathFire,
    .callback = AnimDragonFireToTarget,
};

static const union AnimCmd sAnim_DragonRageFirePlume[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_DragonRageFirePlume[] =
{
    sAnim_DragonRageFirePlume,
};

const struct SpriteTemplate gDragonRageFirePlumeSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .callback = AnimDragonRageFirePlume,
};

static const union AnimCmd sAnim_DragonRageFire[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gAnims_DragonRageFire[] =
{
    sAnim_DragonRageFire,
    sAnim_DragonRageFire,
};

static const union AffineAnimCmd sAffineAnim_DragonRageFire_0[] =
{
    AFFINEANIMCMD_FRAME(0x64, 0x64, 127, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_DragonRageFire_1[] =
{
    AFFINEANIMCMD_FRAME(0x64, 0x64, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAffineAnims_DragonRageFire[] =
{
    sAffineAnim_DragonRageFire_0,
    sAffineAnim_DragonRageFire_1,
};

const struct SpriteTemplate gDragonRageFireSpitSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonRageFire,
    .affineAnims = gAffineAnims_DragonRageFire,
    .callback = AnimDragonFireToTarget,
};

const struct SpriteTemplate gDragonDanceOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_HOLLOW_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDragonDanceOrb,
};

const struct SpriteTemplate gOverheatFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_OutrageOverheatFire,
    .callback = AnimOverheatFlame,
};

// Draco Meteor Rocks
const struct SpriteTemplate gDracoMeteorRocksSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_FAIRY_LOCK_CHAINS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimDracoMeteorRock,
};

// Draco Meteor Tail
const struct SpriteTemplate gDracoMeteorTailSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_GUN,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = AnimDracoMeteorRock,
};

const union AnimCmd gDragonRushAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gDragonRushAnimTable[] =
{
    gDragonRushAnimCmds,
};

const union AffineAnimCmd gDragonRushAffineanimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gDragonRushAffineanimCmds2[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gDragonRushAffineAnimTable[] =
{
    gDragonRushAffineanimCmds1,
    gDragonRushAffineanimCmds2,
};

const union AnimCmd gDracoMeteorAnimTable[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gDracoMeteorAnimCmd[] =
{
    gDracoMeteorAnimTable,
};

const union AffineAnimCmd gDracoMeteorAffineAnimCmd[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 20, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gDracoMeteorAffineAnims[] =
{
    gDracoMeteorAffineAnimCmd,
};

const struct SpriteTemplate gDragonRushSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDragonRushAnimTable,
    .affineAnims = gDragonRushAffineAnimTable,
    .callback = AnimDragonRush,
};

const struct SpriteTemplate gDracoMetorSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDracoMeteorAnimCmd,
    .affineAnims = gDracoMeteorAffineAnims,
    .callback = AnimSpinningDracoMeteor,
};

const struct SpriteTemplate gDragonPulseSpriteTemplate =
{
    .tileTag = ANIM_TAG_DRAGON_PULSE,
    .paletteTag = ANIM_TAG_DRAGON_PULSE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

// Animates a strike that swipes downard at the target mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
static void AnimDragonRush(struct Sprite *sprite)
{
    if (IsOnPlayerSide(gBattleAnimTarget))
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[0] = -11;
        sprite->data[1] = 192;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->data[0] = 11;
        sprite->data[1] = 192;
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->callback = AnimDragonRushStep;
}

// args[0] - initial x delta
// args[1] - initial y delta
// args[2] - x delta to end x
// args[3] - y delta to end y
// args[4] - num frames
// args[5] - sprite anim number
static void AnimDragonRushStep(struct Sprite *sprite)
{
    // These two cases are identical.
    if (IsOnPlayerSide(gBattleAnimTarget))
    {
        sprite->data[1] += sprite->data[0];
        sprite->data[1] &= 0xFF;
    }
    else
    {
        sprite->data[1] += sprite->data[0];
        sprite->data[1] &= 0xFF;
    }

    sprite->x2 = Cos(sprite->data[1], 20);
    sprite->y2 = Sin(sprite->data[1], 20);
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);

    sprite->data[2]++;
}

static void AnimSpinningDracoMeteorFinish(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 0);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = 20;

    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimSpinningDracoMeteor(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    sprite->data[0] = gBattleAnimArgs[3];

    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimSpinningDracoMeteorFinish);
}

void AnimOutrageFlame(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration, xVelocity, yVelocity, flickerDuration);

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    if (!IsOnPlayerSide(gBattleAnimAttacker))
    {
        sprite->x -= cmd->x;
        cmd->xVelocity = -cmd->xVelocity;
        cmd->yVelocity = -cmd->yVelocity;
    }
    else
    {
        sprite->x += cmd->x;
    }

    sprite->y += cmd->y;
    sprite->data[0] = cmd->duration;
    sprite->data[1] = cmd->xVelocity;
    sprite->data[3] = cmd->yVelocity;
    sprite->data[5] = cmd->flickerDuration;
    sprite->invisible = TRUE;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

static void StartDragonFireTranslation(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, targetX, targetY, duration);

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    if (!IsOnPlayerSide(gBattleAnimAttacker))
    {
        sprite->x -= cmd->initialY;
        sprite->y += cmd->initialY;
        sprite->data[2] -= cmd->targetX;
        sprite->data[4] += cmd->targetY;
    }
    else
    {
        sprite->x += cmd->initialX;
        sprite->y += cmd->initialY;
        sprite->data[2] += cmd->targetX;
        sprite->data[4] += cmd->targetY;
        StartSpriteAnim(sprite, 1);
    }

    sprite->data[0] = cmd->duration;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// args[0] - attacker or target
// args[1] - initial x offset
// args[2] - initial y offset
void AnimDragonRageFirePlume(struct Sprite *sprite)
{
    CMD_ARGS(relativeTo, x, y);

    if (cmd->relativeTo == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }

    SetAnimSpriteInitialXOffset(sprite, cmd->x);
    sprite->y += cmd->y;
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// For Dragon Breath and Dragon Rage
void AnimDragonFireToTarget(struct Sprite *sprite)
{
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        StartSpriteAffineAnim(sprite, 1);

    StartDragonFireTranslation(sprite);
}

void AnimDragonDanceOrb(struct Sprite *sprite)
{
    CMD_ARGS(angle);

    u16 r5;
    u16 r0;
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[4] = 0;
    sprite->data[5] = 1;
    sprite->data[6] = cmd->angle;
    r5 = GetBattlerSpriteCoordAttr(gBattlerAttacker, BATTLER_COORD_ATTR_HEIGHT);
    r0 = GetBattlerSpriteCoordAttr(gBattlerAttacker, BATTLER_COORD_ATTR_WIDTH);
    if (r5 > r0)
        sprite->data[7] = r5 / 2;
    else
        sprite->data[7] = r0 / 2;
    sprite->x2 = Cos(sprite->data[6], sprite->data[7]);
    sprite->y2 = Sin(sprite->data[6], sprite->data[7]);
    sprite->callback = AnimDragonDanceOrb_Step;
}

static void AnimDragonDanceOrb_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[6] = (sprite->data[6] - sprite->data[5]) & 0xFF;
        sprite->x2 = Cos(sprite->data[6], sprite->data[7]);
        sprite->y2 = Sin(sprite->data[6], sprite->data[7]);
        if (++sprite->data[4] > 5)
        {
            sprite->data[4] = 0;
            if (sprite->data[5] <= 15 && ++sprite->data[5] > 15)
                sprite->data[5] = 16;
        }
        if (++sprite->data[3] > 0x3C)
        {
            sprite->data[3] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->data[6] = (sprite->data[6] - sprite->data[5]) & 0xFF;
        if (sprite->data[7] <= 0x95 && (sprite->data[7] += 8) > 0x95)
            sprite->data[7] = 0x96;
        sprite->x2 = Cos(sprite->data[6], sprite->data[7]);
        sprite->y2 = Sin(sprite->data[6], sprite->data[7]);
        if (++sprite->data[4] > 5)
        {
            sprite->data[4] = 0;
            if (sprite->data[5] <= 15 && ++sprite->data[5] > 15)
                sprite->data[5] = 16;
        }
        if (++sprite->data[3] > 20)
            DestroyAnimSprite(sprite);
        break;
    }
}

// Wavers the attacker back and forth. Progressing vertical wave of scanline shifts
// Used by Dragon Dance
void AnimTask_DragonDanceWaver(u8 taskId)
{
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];
    u16 i;
    u8 y;
    if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
    {
        scanlineParams.dmaDest = &REG_BG1HOFS;
        task->data[2] = gBattle_BG1_X;
    }
    else
    {
        scanlineParams.dmaDest = &REG_BG2HOFS;
        task->data[2] = gBattle_BG2_X;
    }

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    y = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
    task->data[3] = y - 32;
    task->data[4] = y + 32;
    if (task->data[3] < 0)
        task->data[3] = 0;

    for (i = task->data[3]; i <= task->data[4]; i++)
    {
        gScanlineEffectRegBuffers[0][i] = task->data[2];
        gScanlineEffectRegBuffers[1][i] = task->data[2];
    }

    ScanlineEffect_SetParams(scanlineParams);
    task->func = AnimTask_DragonDanceWaver_Step;
}

static void AnimTask_DragonDanceWaver_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        if (++task->data[7] > 1)
        {
            task->data[7] = 0;
            if (++task->data[6] == 3)
                task->data[0]++;
        }
        UpdateDragonDanceScanlineEffect(task);
        break;
    case 1:
        if (++task->data[1] > 0x3C)
            task->data[0]++;
        UpdateDragonDanceScanlineEffect(task);
        break;
    case 2:
        if (++task->data[7] > 1)
        {
            task->data[7] = 0;
            if (--task->data[6] == 0)
                task->data[0]++;
        }
        UpdateDragonDanceScanlineEffect(task);
        break;
    case 3:
        gScanlineEffect.state = 3;
        task->data[0]++;
        break;
    case 4:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void UpdateDragonDanceScanlineEffect(struct Task *task)
{
    u16 sineIndex = task->data[5];
    u16 i;
    for (i = task->data[3]; i <= task->data[4]; i++)
    {
        gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = ((gSineTable[sineIndex] * task->data[6]) >> 7) + task->data[2];
        sineIndex = (sineIndex + 8) & 0xFF;
    }

    task->data[5] = (task->data[5] + 9) & 0xFF;
}

void AnimOverheatFlame(struct Sprite *sprite)
{
    CMD_ARGS(speed, unk1, unk2, duration, y);

    int yAmplitude = (cmd->unk2 * 3) / 5;
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + cmd->y;
    sprite->data[1] = Cos(cmd->unk1, cmd->unk2);
    sprite->data[2] = Sin(cmd->unk1, yAmplitude);
    sprite->x += sprite->data[1] * cmd->speed;
    sprite->y += sprite->data[2] * cmd->speed;
    sprite->data[3] = cmd->duration;
    sprite->callback = AnimOverheatFlame_Step;
}

static void AnimOverheatFlame_Step(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->data[5] += sprite->data[2];
    sprite->x2 = sprite->data[4] / 10;
    sprite->y2 = sprite->data[5] / 10;
    if (++sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}

void AnimDracoMeteorRock(struct Sprite *sprite)
{
    if (IsOnPlayerSide(gBattleAnimTarget))
    {
        sprite->data[0] = sprite->x - gBattleAnimArgs[0];
        sprite->data[2] = sprite->x - gBattleAnimArgs[2];
    }
    else
    {
        sprite->data[0] = sprite->x + gBattleAnimArgs[0];
        sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    }

    sprite->data[1] = sprite->y + gBattleAnimArgs[1];
    sprite->data[3] = sprite->y + gBattleAnimArgs[3];
    sprite->data[4] = gBattleAnimArgs[4];

    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[3];

    sprite->x = sprite->data[0];
    sprite->y = sprite->data[1];
    sprite->callback = AnimDracoMeteorRock_Step;
}

static void AnimDracoMeteorRock_Step(struct Sprite *sprite)
{
    sprite->x2 = ((sprite->data[2] - sprite->data[0]) * sprite->data[5]) / sprite->data[4];
    sprite->y2 = ((sprite->data[3] - sprite->data[1]) * sprite->data[5]) / sprite->data[4];

    if (sprite->data[5] == sprite->data[4])
        DestroyAnimSprite(sprite);

    sprite->data[5]++;
}
