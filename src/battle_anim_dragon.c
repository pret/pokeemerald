#include "global.h"
#include "battle_anim.h"
#include "scanline_effect.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"

static void AnimOutrageFlame(struct Sprite *);
static void AnimDragonRageFirePlume(struct Sprite *);
static void AnimDragonFireToTarget(struct Sprite *);
static void AnimDragonDanceOrb(struct Sprite *);
static void AnimDragonDanceOrb_Step(struct Sprite *);
static void AnimOverheatFlame(struct Sprite *);
static void AnimOverheatFlame_Step(struct Sprite *);
static void AnimTask_DragonDanceWaver_Step(u8);
static void sub_8113574(struct Task *);

EWRAM_DATA static u16 gUnknown_0203A100[7] = {0};

static const union AnimCmd gUnknown_08596E60[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gUnknown_08596E78[] =
{
    gUnknown_08596E60,
};

const struct SpriteTemplate gOutrageFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gUnknown_08596E78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOutrageFlame,
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

static const union AnimCmd *const sAnims_DragonBreathFire[] =
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

static const union AffineAnimCmd *const sAffineAnims_DragonBreathFire[] =
{
    sAffineAnim_DragonBreathFire_0,
    sAffineAnim_DragonBreathFire_1,
};

const struct SpriteTemplate gDragonBreathFireSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = sAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = sAffineAnims_DragonBreathFire,
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

static const union AnimCmd *const sAnims_DragonRageFirePlume[] =
{
    sAnim_DragonRageFirePlume,
};

const struct SpriteTemplate gDragonRageFirePlumeSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_DragonRageFirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonRageFirePlume,
};

static const union AnimCmd sAnim_DragonRageFire[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_DragonRageFire[] =
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

static const union AffineAnimCmd *const sAffineAnims_DragonRageFire[] =
{
    sAffineAnim_DragonRageFire_0,
    sAffineAnim_DragonRageFire_1,
};

const struct SpriteTemplate gDragonRageFireSpitSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = sAnims_DragonRageFire,
    .images = NULL,
    .affineAnims = sAffineAnims_DragonRageFire,
    .callback = AnimDragonFireToTarget,
};

const struct SpriteTemplate gDragonDanceOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_HOLLOW_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonDanceOrb,
};

const struct SpriteTemplate gOverheatFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gUnknown_08596E78,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOverheatFlame,
};

static void AnimOutrageFlame(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
    }

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    sprite->invisible = TRUE;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

static void sub_8113100(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x -= gBattleAnimArgs[1];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] -= gBattleAnimArgs[2];
        sprite->data[4] += gBattleAnimArgs[3];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] += gBattleAnimArgs[2];
        sprite->data[4] += gBattleAnimArgs[3];
        StartSpriteAnim(sprite, 1);
    }

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

static void AnimDragonRageFirePlume(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 1);
    }

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[1]);
    sprite->pos1.y += gBattleAnimArgs[2];
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// For Dragon Breath and Dragon Rage
static void AnimDragonFireToTarget(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        StartSpriteAffineAnim(sprite, 1);

    sub_8113100(sprite);
}

static void AnimDragonDanceOrb(struct Sprite *sprite)
{
    u16 r5;
    u16 r0;
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[4] = 0;
    sprite->data[5] = 1;
    sprite->data[6] = gBattleAnimArgs[0];
    r5 = GetBattlerSpriteCoordAttr(gBattlerAttacker, BATTLER_COORD_ATTR_HEIGHT);
    r0 = GetBattlerSpriteCoordAttr(gBattlerAttacker, BATTLER_COORD_ATTR_WIDTH);
    if (r5 > r0)
        sprite->data[7] = r5 / 2;
    else
        sprite->data[7] = r0 / 2;
    sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
    sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
    sprite->callback = AnimDragonDanceOrb_Step;
}

static void AnimDragonDanceOrb_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[6] = (sprite->data[6] - sprite->data[5]) & 0xFF;
        sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
        sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
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
        sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
        sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
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
    struct ScanlineEffectParams sp;
    struct Task *task = &gTasks[taskId];
    u16 i;
    u8 r1;
    if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
    {
        sp.dmaDest = &REG_BG1HOFS;
        task->data[2] = gBattle_BG1_X;
    }
    else
    {
        sp.dmaDest = &REG_BG2HOFS;
        task->data[2] = gBattle_BG2_X;
    }

    sp.dmaControl = 0xA2600001;
    sp.initState = 1;
    sp.unused9 = 0;
    r1 = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
    task->data[3] = r1 - 32;
    task->data[4] = r1 + 32;
    if (task->data[3] < 0)
        task->data[3] = 0;

    for (i = task->data[3]; i <= task->data[4]; i++)
    {
        gScanlineEffectRegBuffers[0][i] = task->data[2];
        gScanlineEffectRegBuffers[1][i] = task->data[2];
    }

    ScanlineEffect_SetParams(sp);
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
        sub_8113574(task);
        break;
    case 1:
        if (++task->data[1] > 0x3C)
            task->data[0]++;
        sub_8113574(task);
        break;
    case 2:
        if (++task->data[7] > 1)
        {
            task->data[7] = 0;
            if (--task->data[6] == 0)
                task->data[0]++;
        }
        sub_8113574(task);
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

static void sub_8113574(struct Task *task)
{
    u16 r3 = task->data[5];
    u16 i;
    for (i = task->data[3]; i <= task->data[4]; i++)
    {
        gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = ((gSineTable[r3] * task->data[6]) >> 7) + task->data[2];
        r3 = (r3 + 8) & 0xFF;
    }

    task->data[5] = (task->data[5] + 9) & 0xFF;
}

static void AnimOverheatFlame(struct Sprite *sprite)
{
    int r6 = (gBattleAnimArgs[2] * 3) / 5;
    int i;
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) + gBattleAnimArgs[4];
    sprite->data[1] = Cos(gBattleAnimArgs[1], gBattleAnimArgs[2]);
    sprite->data[2] = Sin(gBattleAnimArgs[1], r6);
    sprite->pos1.x += sprite->data[1] * gBattleAnimArgs[0];
    sprite->pos1.y += sprite->data[2] * gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[3];
    sprite->callback = AnimOverheatFlame_Step;
    for (i = 0; i < 7; i++)
        gUnknown_0203A100[i] = sprite->data[i];
}

static void AnimOverheatFlame_Step(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->data[5] += sprite->data[2];
    sprite->pos2.x = sprite->data[4] / 10;
    sprite->pos2.y = sprite->data[5] / 10;
    if (++sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}
