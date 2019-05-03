#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "palette.h"
#include "constants/rgb.h"
#include "scanline_effect.h"
#include "constants/songs.h"
#include "sound.h"
#include "trig.h"
#include "util.h"

static void sub_811160C(struct Sprite *);
static void sub_8111674(struct Sprite *);
static void sub_81116E8(struct Sprite *);
static void sub_8111764(struct Sprite *);
static void sub_81117F4(struct Sprite *);
static void sub_8111814(struct Sprite *);
static void sub_8111914(u8 taskId);
static void sub_811196C(u8 taskId);
static void InitAnimShadowBall(struct Sprite *);
static void AnimShadowBallStep(struct Sprite *);
static void sub_8111B9C(struct Sprite *);
static void sub_8111BB4(struct Sprite *);
static void sub_8111D78(u8 taskId);
static void sub_8111E78(u8 taskId);
static void sub_81120DC(u8 taskId);
static void sub_8112170(u8 taskId);
static void sub_8112264(struct Sprite *);
static void sub_8112384(struct Sprite *);
static void sub_81125E0(u8 taskId);
static void sub_811280C(u8 taskId);
static void sub_8112994(u8 taskId);
static void sub_81129F0(struct Sprite *);
static void sub_8112A4C(struct Sprite *);
static void sub_8112ACC(struct Sprite *);
static void sub_8112B44(struct Sprite *);
static void sub_8112C4C(struct Sprite *);
static void sub_8112D10(u8 taskId);
static void sub_8112E9C(struct Sprite *);
static void sub_8112F60(struct Sprite *);
static void sub_8112FB8(struct Sprite *);

const union AffineAnimCmd gUnknown_08596CF8[] =
{
    AFFINEANIMCMD_FRAME(0x1E, 0x1E, 10, 5),
    AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 10, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596D10[] =
{
    gUnknown_08596CF8,
};

const struct SpriteTemplate gUnknown_08596D14 =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gUnknown_085249CC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D10,
    .callback = sub_811160C,
};

const struct SpriteTemplate gUnknown_08596D2C =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gUnknown_08524A2C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81117F4,
};

const union AffineAnimCmd gUnknown_08596D44[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08596D54[] =
{
    gUnknown_08596D44,
};

const struct SpriteTemplate gShadowBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D54,
    .callback = InitAnimShadowBall,
};

const struct SpriteTemplate gEnergyBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_ENERGY_BALL,
    .paletteTag = ANIM_TAG_ENERGY_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D54,
    .callback = InitAnimShadowBall,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_LeafStorm =
{
    .tileTag = ANIM_TAG_RAZOR_LEAF,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gUnknown_08524934,
    .anims = gUnknown_085962D0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810E044,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_LeafStorm2 =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gUnknown_085249CC,
    .anims = gUnknown_08592388,
    .images = NULL,
    .affineAnims = gUnknown_085961A0,
    .callback = sub_8100898,
};

const union AnimCmd gUnknown_08596D70[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08596D88[] =
{
    gUnknown_08596D70,
};

const struct SpriteTemplate gUnknown_08596D8C =
{
    .tileTag = ANIM_TAG_LICK,
    .paletteTag = ANIM_TAG_LICK,
    .oam = &gUnknown_08524954,
    .anims = gUnknown_08596D88,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8111B9C,
};

const union AffineAnimCmd gUnknown_08596DA4[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08596DB4[] =
{
    gUnknown_08596DA4,
};

const struct SpriteTemplate gUnknown_08596DB8 =
{
    .tileTag = ANIM_TAG_WHITE_SHADOW,
    .paletteTag = ANIM_TAG_WHITE_SHADOW,
    .oam = &gUnknown_08524A5C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112264,
};

const struct SpriteTemplate gUnknown_08596DD0 =
{
    .tileTag = ANIM_TAG_NAIL,
    .paletteTag = ANIM_TAG_NAIL,
    .oam = &gUnknown_08524A54,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81129F0,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596DE8 =
{
    .tileTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .paletteTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112B78,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8596E00 =
{
    .tileTag = ANIM_TAG_DEVIL,
    .paletteTag = ANIM_TAG_DEVIL,
    .oam = &gUnknown_08524A34,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112B78,
};

const union AnimCmd gUnknown_08596E18[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08596E2C[] =
{
    gUnknown_08596E18,
};

const struct SpriteTemplate gUnknown_08596E30 =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gUnknown_08524A74,
    .anims = gUnknown_08596E2C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112E9C,
};

const struct SpriteTemplate gUnknown_08596E48 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8112F60,
};

static void sub_811160C(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sub_80A6FD4(sprite);
    sprite->callback = sub_8111674;
    sprite->data[6] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, sprite->data[6]);
}

static void sub_8111674(struct Sprite *sprite)
{
    s16 r0;
    s16 r2;
    sub_8111764(sprite);
    if (AnimTranslateLinear(sprite))
    {
        sprite->callback = sub_81116E8;
        return;
    }

    sprite->pos2.x += Sin(sprite->data[5], 10);
    sprite->pos2.y += Cos(sprite->data[5], 15);
    r2 = sprite->data[5];
    sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    r0 = sprite->data[5];
    if (r2 != 0 && r2 <= 196)
        return;
    if (r0 <= 0)
        return;
    PlaySE12WithPanning(SE_W109, gUnknown_02038440);
}

static void sub_81116E8(struct Sprite *sprite)
{
    s16 r2;
    s16 r0;
    sprite->data[0] = 1;
    AnimTranslateLinear(sprite);
    sprite->pos2.x += Sin(sprite->data[5], 10);
    sprite->pos2.y += Cos(sprite->data[5], 15);

    r2 = sprite->data[5];
    sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    r0 = sprite->data[5];

    if (r2 == 0 || r2 > 196)
    {
        if (r0 > 0)
            PlaySE(SE_W109);
    }

    if (sprite->data[6] == 0)
    {
        sprite->invisible = TRUE;
        sprite->callback = DestroyAnimSpriteAndDisableBlend;
    }
    else
        sub_8111764(sprite);
}

static void sub_8111764(struct Sprite *sprite)
{

    s16 r0;
    if (sprite->data[6] > 0xFF)
    {
        if (++sprite->data[6] == 0x10d)
            sprite->data[6] = 0;
        return;
    }

    r0 = sprite->data[7];
    sprite->data[7]++;

    if ((r0 & 0xFF) == 0)
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

static void sub_81117F4(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->callback = sub_8111814;
    sprite->callback(sprite);
}

static void sub_8111814(struct Sprite *sprite)
{
    u16 temp1;
    sprite->pos2.x = Sin(sprite->data[0], 32);
    sprite->pos2.y = Cos(sprite->data[0], 8);
    temp1 = sprite->data[0] - 65;
    if (temp1 <= 130)
        sprite->oam.priority = 2;
    else
        sprite->oam.priority = 1;
    sprite->data[0] = (sprite->data[0] + 19) & 0xFF;
    sprite->data[2] += 80;
    sprite->pos2.y += sprite->data[2] >> 8;
    sprite->data[7] += 1;
    if (sprite->data[7] == 61)
        DestroyAnimSprite(sprite);
}

void sub_811188C(u8 taskId)
{
    u8 spriteId;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    spriteId = GetAnimBattlerSpriteId(0);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
    SetSpriteRotScale(spriteId, 128, 128, 0);
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].data[0] = 128;
    gTasks[taskId].data[1] = *gBattleAnimArgs;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 16;
    gTasks[taskId].func = sub_8111914;
}

static void sub_8111914(u8 taskId)
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

        gTasks[taskId].func = sub_811196C;
    }
}

static void sub_811196C(u8 taskId)
{
    u8 spriteId;
    if (gTasks[taskId].data[1] > 0)
    {
        gTasks[taskId].data[1] -= 1;
        return;
    }

    spriteId = GetAnimBattlerSpriteId(0);
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
static void InitAnimShadowBall(struct Sprite *sprite)
{
    s16 oldPosX = sprite->pos1.x;
    s16 oldPosY = sprite->pos1.y;

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = sprite->pos1.x << 4;
    sprite->data[5] = sprite->pos1.y << 4;
    sprite->data[6] = ((oldPosX - sprite->pos1.x) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->data[7] = ((oldPosY - sprite->pos1.y) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->callback = AnimShadowBallStep;
}

static void AnimShadowBallStep(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->pos1.x = sprite->data[4] >> 4;
        sprite->pos1.y = sprite->data[5] >> 4;
        sprite->data[1] -= 1;
        if (sprite->data[1] > 0)
            break;
        sprite->data[0] += 1;
        break;
    case 1:
        sprite->data[2] -= 1;
        if (sprite->data[2] > 0)
            break;
        sprite->data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
        sprite->data[4] = sprite->pos1.x << 4;
        sprite->data[5] = sprite->pos1.y << 4;
        sprite->data[6] = ((sprite->data[1] - sprite->pos1.x) << 4) / sprite->data[3];
        sprite->data[7] = ((sprite->data[2] - sprite->pos1.y) << 4) / sprite->data[3];
        sprite->data[0] += 1;
        break;
    case 2:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->pos1.x = sprite->data[4] >> 4;
        sprite->pos1.y = sprite->data[5] >> 4;
        sprite->data[3] -= 1;
        if (sprite->data[3] > 0)
            break;
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
        sprite->data[0] += 1;
        break;
    case 3:
        DestroySpriteAndMatrix(sprite);
        break;
    }
}

static void sub_8111B9C(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->callback = sub_8111BB4;
}

static void sub_8111BB4(struct Sprite *sprite)
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

void sub_8111C50(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->data[0] = CloneBattlerSpriteWithBlend(1);
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
    task->func = sub_8111D78;
}

static void sub_8111D78(u8 taskId)
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
        obj_delete_but_dont_free_vram(&gSprites[task->data[0]]);
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

void sub_8111E50(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->data[15] = 0;
    task->func = sub_8111E78;
    task->func(taskId);
}

static void sub_8111E78(u8 taskId)
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
            task->data[0] = CloneBattlerSpriteWithBlend(1);
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
                task->data[13] = GetAnimBattlerSpriteId(1);
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
        CpuSet(&gPlttBufferUnfaded[task->data[4]], &gPlttBufferFaded[task->data[14]], 0x4000008);
        BlendPalette(task->data[4], 16, 10, RGB(13, 0, 15));
        task->data[15]++;
        break;
    case 2:
        startLine = gSprites[task->data[13]].pos1.y + gSprites[task->data[13]].pos2.y - 32;
        if (startLine < 0)
            startLine = 0;

        if (position == 1)
            task->data[10] = ScanlineEffect_InitWave(startLine, startLine + 64, 2, 6, 0, 4, 1);
        else
            task->data[10] = ScanlineEffect_InitWave(startLine, startLine + 64, 2, 6, 0, 8, 1);

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

        task->func = sub_81120DC;
        task->data[15]++;
        break;
    default:
        task->data[15]++;
        break;
    }
}

static void sub_81120DC(u8 taskId)
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
        task->func = sub_8112170;
        task->func(taskId);
    }
}

static void sub_8112170(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 rank = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);

    switch (task->data[15])
    {
    case 0:
        gScanlineEffect.state = 3;
        task->data[14] = GetAnimBattlerSpriteId(1);
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
        obj_delete_but_dont_free_vram(&gSprites[task->data[0]]);
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

static void sub_8112264(struct Sprite *sprite)
{
    s16 battler1X, battler1Y;
    s16 battler2X, battler2Y;
    s16 yDiff;

    if (gBattleAnimArgs[0] == 0)
    {
        battler1X = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        battler1Y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 28;
        battler2X = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
        battler2Y = GetBattlerSpriteCoord(gBattleAnimTarget, 1) + 28;
    }
    else
    {
        battler1X = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
        battler1Y = GetBattlerSpriteCoord(gBattleAnimTarget, 1) + 28;
        battler2X = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        battler2Y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 28;
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
    sprite->pos1.x = battler1X;
    sprite->pos1.y = battler1Y;
    sprite->callback = sub_8112384;
    sprite->invisible = 1;
}

static void sub_8112384(struct Sprite *sprite)
{
    if (sprite->data[4])
    {
        sprite->data[0] += sprite->data[2];
        sprite->data[1] += sprite->data[3];
        sprite->pos1.x = sprite->data[0] >> 4;
        sprite->pos1.y = sprite->data[1] >> 4;
        if (--sprite->data[4] == 0)
            sprite->data[0] = 0;
    }
}

void sub_81123C4(u8 taskId)
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
        for (battler = 0; battler < 4; battler++)
        {
            if (battler != gBattleAnimAttacker
             && battler != (gBattleAnimAttacker ^ 2)
             && IsBattlerSpriteVisible(battler))
            {
                spriteId = CreateSprite(&gUnknown_08596DB8, baseX, baseY, 55);
                if (spriteId != MAX_SPRITES)
                {
                    x = GetBattlerSpriteCoord(battler, 2);
                    y = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_BOTTOM);
                    gSprites[spriteId].data[0] = baseX << 4;
                    gSprites[spriteId].data[1] = baseY << 4;
                    gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[4] = gBattleAnimArgs[1];
                    gSprites[spriteId].data[5] = x;
                    gSprites[spriteId].data[6] = y;
                    gSprites[spriteId].callback = sub_8112384;

                    task->data[task->data[12] + 13] = spriteId;
                    task->data[12]++;
                }
            }
        }
    }
    else
    {
        spriteId = CreateSprite(&gUnknown_08596DB8, baseX, baseY, 55);
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
            gSprites[spriteId].callback = sub_8112384;

            task->data[13] = spriteId;
            task->data[12] = 1;
        }
    }

    task->func = sub_81125E0;
}

static void sub_81125E0(u8 taskId)
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

void sub_8112758(u8 taskId)
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
    SetGpuReg(REG_OFFSET_BLDY, 0x10);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER || IsContest())
        startX = 40;
    else
        startX = 200;

    gBattle_WIN0H = (startX << 8) | startX;
    startY = 40;
    gBattle_WIN0V = (startY << 8) | startY;

    leftDistance = startX;
    rightDistance = 240 - startX;
    topDistance = startY;
    bottomDistance = 72;
    gTasks[taskId].data[1] = leftDistance;
    gTasks[taskId].data[2] = rightDistance;
    gTasks[taskId].data[3] = topDistance;
    gTasks[taskId].data[4] = bottomDistance;
    gTasks[taskId].data[5] = startX;
    gTasks[taskId].data[6] = startY;
    gTasks[taskId].func = sub_811280C;
}

static void sub_811280C(u8 taskId)
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
        right = 240;
        top = 0;
        bottom = 112;
        selectedPalettes = sub_80A75AC(1, 0, 0, 0, 0, 0, 0);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 16, RGB(0, 0, 0));
        gTasks[taskId].func = sub_8112994;
    }

    gBattle_WIN0H = (left << 8) | right;
    gBattle_WIN0V = (top  << 8) | bottom;
}

static void sub_8112994(u8 taskId)
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

static void sub_81129F0(struct Sprite *sprite)
{
    s16 xDelta;
    s16 xDelta2;

    InitSpritePosToAnimAttacker(sprite, 1);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        xDelta = 24;
        xDelta2 = -2;
        sprite->oam.matrixNum = 8;
    }
    else
    {
        xDelta = -24;
        xDelta2 = 2;
    }

    sprite->pos1.x += xDelta;
    sprite->data[1] = xDelta2;
    sprite->data[0] = 60;
    sprite->callback = sub_8112A4C;
}

static void sub_8112A4C(struct Sprite *sprite)
{
    u16 var0;

    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
    }
    else
    {
        sprite->pos2.x += sprite->data[1];
        var0 = sprite->pos2.x + 7;
        if (var0 > 14)
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos2.x = 0;
            sprite->oam.tileNum += 8;
            if (++sprite->data[2] == 3)
            {
                sprite->data[0] = 30;
                sprite->callback = WaitAnimForDuration;
                StoreSpriteCallbackInData6(sprite, sub_8112ACC);
            }
            else
            {
                sprite->data[0] = 40;
            }
        }
    }
}

static void sub_8112ACC(struct Sprite *sprite)
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
            sprite->invisible = 1;
            sprite->callback = sub_8112B44;
        }
    }
}

static void sub_8112B44(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    DestroyAnimSprite(sprite);
}

void sub_8112B78(struct Sprite *sprite)
{
    u16 coeffB;
    u16 coeffA;

    sprite->pos2.x = Sin(sprite->data[0], 12);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->pos2.x = -sprite->pos2.x;

    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1] += 0x100;
    sprite->pos2.y = -(sprite->data[1] >> 8);

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
        if (--(s16)coeffA < 0)
            coeffA = 0;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(coeffA, coeffB));
        sprite->data[6] = BLDALPHA_BLEND(coeffA, coeffB);
        if (coeffB == 16 && coeffA == 0)
        {
            sprite->invisible = 1;
            sprite->callback = sub_8112C4C;
        }
    }
}

static void sub_8112C4C(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void sub_8112C6C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 16;
    task->data[9] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
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
    task->func = sub_8112D10;
}

static void sub_8112D10(u8 taskId)
{
    u16 i;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        for (i = 0; i < 6; i++)
        {
            spriteId = CreateSprite(&gUnknown_08596E30, task->data[9], task->data[10], task->data[6]);
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

static void sub_8112E9C(struct Sprite *sprite)
{
    u16 index;

    if (sprite->data[1] == 0)
        sprite->data[2] += 2;
    else
        sprite->data[2] -= 2;

    sprite->data[2] &= 0xFF;
    sprite->pos2.x = Sin(sprite->data[2], sprite->data[3]);

    index = sprite->data[2] - 65;
    if (index < 127)
        sprite->oam.priority = gTasks[sprite->data[0]].data[5] + 1;
    else
        sprite->oam.priority = gTasks[sprite->data[0]].data[5];

    sprite->data[5]++;
    sprite->data[6] = (sprite->data[5] * 8) & 0xFF;
    sprite->pos2.y = Sin(sprite->data[6], 7);
    if (gTasks[sprite->data[0]].data[8])
    {
        gTasks[sprite->data[0]].data[7]--;
        DestroySprite(sprite);
    }
}

static void sub_8112F60(struct Sprite *sprite)
{
    sprite->invisible = 1;
    sprite->data[5] = gBattlerSpriteIds[gBattleAnimAttacker];
    sprite->data[0] = 128;
    sprite->data[1] = 10;
    sprite->data[2] = gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[1];
    sprite->callback = sub_8112FB8;

    gSprites[sprite->data[5]].pos1.y += 8;
}

static void sub_8112FB8(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->data[3]--;
        gSprites[sprite->data[5]].pos2.x = Sin(sprite->data[0], sprite->data[1]);
        gSprites[sprite->data[5]].pos2.y = Cos(sprite->data[0], sprite->data[1]);
        sprite->data[0] += sprite->data[2];
        if (sprite->data[0] > 255)
            sprite->data[0] -= 256;
    }
    else
    {
        gSprites[sprite->data[5]].pos2.x = 0;
        gSprites[sprite->data[5]].pos2.y = 0;
        gSprites[sprite->data[5]].pos1.y -= 8;
        sprite->callback = DestroySpriteAndMatrix;
    }
}
