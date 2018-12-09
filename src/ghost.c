#include "global.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sound.h"
#include "trig.h"

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
extern void sub_8112264(struct Sprite *);
extern void sub_81129F0(struct Sprite *);
extern void sub_8112B78(struct Sprite *);
extern void sub_8112E9C(struct Sprite *);
extern void sub_8112F60(struct Sprite *);

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

const struct SpriteTemplate gUnknown_08596D58 =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gUnknown_08524974,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08596D54,
    .callback = InitAnimShadowBall,
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
    InitAnimSpritePos(sprite, 1);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sub_80A6FD4(sprite);
    sprite->callback = sub_8111674;
    sprite->data[6] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
    SetGpuReg(REG_OFFSET_BLDALPHA, sprite->data[6]);
}

static void sub_8111674(struct Sprite *sprite)
{
    s16 r0;
    s16 r2;
    sub_8111764(sprite);
    if (TranslateAnimLinear(sprite))
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
    TranslateAnimLinear(sprite);
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
        sprite->callback = sub_80A67F4;
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
    sub_80A6980(sprite, TRUE);
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
    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x1000);
    spriteId = GetAnimBattlerSpriteId(0);
    sub_80A7270(spriteId, 1);
    obj_id_set_rotscale(spriteId, 128, 128, 0);
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
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].data[3] << 8 | gTasks[taskId].data[2]);
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
        obj_id_set_rotscale(spriteId, gTasks[taskId].data[0], gTasks[taskId].data[0], 0);
    }
    else
    {
        sub_80A7344(spriteId);
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
    u16 r5, r6;
    r5 = sprite->pos1.x;
    r6 = sprite->pos1.y;
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = sprite->pos1.x << 4;
    sprite->data[5] = sprite->pos1.y << 4;
    sprite->data[6] = (((s16)r5 - sprite->pos1.x) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->data[7] = (((s16)r6 - sprite->pos1.y) << 4) / (gBattleAnimArgs[0] << 1);
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
        move_anim_8074EE0(sprite);
        break;
    }
}

static void sub_8111B9C(struct Sprite *sprite)
{
    sub_80A6980(sprite, TRUE);
    sprite->callback = sub_8111BB4;
}

static void sub_8111BB4(struct Sprite *sprite) {
    
    s8 r5 = FALSE;
    bool8 r6 = FALSE;
    if(sprite->animEnded)
    {
        if(!(sprite->invisible))
            sprite->invisible=TRUE;
        switch(sprite->data[0])
        {
            case 0:
                if((sprite->data[1]) != 2)
                    break;
                goto loc_08111C06;
            case 1:
                if((sprite->data[1]) == 4)
                    r5 = TRUE;
                break;
            default:
                r6 = TRUE;
        }
        if(r5)
        {
        loc_08111C06:
            sprite->invisible ^= 1;
            sprite->data[2]++;
            sprite->data[1] = 0;
            if(sprite->data[2] == 5)
            {
                sprite->data[2] = 0;
                sprite->data[0]++;
            }
        }
        else if(r6)
            DestroyAnimSprite(sprite);
        else
            sprite->data[1]++;
    }
}

/*

void sub_80DE1B0(u8 taskId)
{
    struct Task *task;
    
    task = &gTasks[taskId];
    task->data[0] = duplicate_obj_of_side_rel2move_in_transparent_mode(1);
    if (task->data[0] < 0)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }
    task->data[1] = 0;
    task->data[2] = 15;
    task->data[3] = 2;
    task->data[4] = 0;
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = (task->data[3] << 8) | task->data[2];
    gSprites[task->data[0]].data[0] = 80;
    if (GetBattlerSide(gAnimBankTarget) == 0)
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
    StoreSpriteCallbackInData(&gSprites[task->data[0]], SpriteCallbackDummy);
    gSprites[task->data[0]].callback = sub_8078394;
    task->func = sub_80DE2DC;
}

static void sub_80DE2DC(u8 taskId)
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
        REG_BLDALPHA = (task->data[3] << 8) | task->data[2];
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
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        task->data[4] += 1;
        break;
    case 2:
        DestroyAnimVisualTask(taskId);
    }
}

void sub_80DE3AC(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];
    task->data[15] = 0;
    task->func = sub_80DE3D4;
    task->func(taskId);
}

static void sub_80DE3D4(u8 taskId)
{
    s16 startLine;
    struct Task *task = &gTasks[taskId];
    u8 position = GetBattlerPosition_permutated(gAnimBankTarget);

    switch (task->data[15])
    {
    case 0:
        task->data[14] = AllocSpritePalette(0x2771);
        if (task->data[14] == 0xFF)
        {
            DestroyAnimVisualTask(taskId);
        }
        else
        {
            task->data[0] = duplicate_obj_of_side_rel2move_in_transparent_mode(1);
            if (task->data[0] < 0)
            {
                FreeSpritePaletteByTag(0x2771);
                DestroyAnimVisualTask(taskId);
            }
            else
            {
                gSprites[task->data[0]].oam.paletteNum = task->data[14];
                gSprites[task->data[0]].oam.objMode = ST_OAM_OBJ_NORMAL;
                gSprites[task->data[0]].oam.priority = 3;
                task->data[1] = 0;
                task->data[2] = 0;
                task->data[3] = 16;
                task->data[13] = GetAnimBattlerSpriteId(1);
                task->data[4] = (gSprites[task->data[13]].oam.paletteNum + 16) * 16;
                if (position == 1)
                    REG_DISPCNT &= 0xFDFF;
                else
                    REG_DISPCNT &= 0xFBFF;

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
            REG_BLDCNT = 0x3F42;
        else
            REG_BLDCNT = 0x3F44;

        REG_BLDALPHA = 0x1000;
        task->data[15]++;
        break;
    case 4:
        if (position == 1)
            REG_DISPCNT |= DISPCNT_BG1_ON;
        else
            REG_DISPCNT |= DISPCNT_BG2_ON;

        task->func = sub_80DE61C;
        task->data[15]++;
        break;
    default:
        task->data[15]++;
        break;
    }
}

static void sub_80DE61C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[1]++;
    task->data[5] = task->data[1] & 1;
    if (task->data[5] == 0)
        task->data[2] = gSineTable[task->data[1]] / 18;

    if (task->data[5] == 1)
        task->data[3] = 16 - (gSineTable[task->data[1]] / 18);

    REG_BLDALPHA = (task->data[3] << 8) | task->data[2];
    if (task->data[1] == 128)
    {
        task->data[15] = 0;
        task->func = sub_80DE6B0;
        task->func(taskId);
    }
}

static void sub_80DE6B0(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 position = GetBattlerPosition_permutated(gAnimBankTarget);

    switch (task->data[15])
    {
    case 0:
        gScanlineEffect.state = 3;
        task->data[14] = GetAnimBattlerSpriteId(1);
        if (position == 1)
            REG_DISPCNT &= 0xFDFF;
        else
            REG_DISPCNT &= 0xFBFF;
        break;
    case 1:
        BlendPalette(task->data[4], 16, 0, RGB(13, 0, 15));
        break;
    case 2:
        gSprites[task->data[14]].invisible = 1;
        obj_delete_but_dont_free_vram(&gSprites[task->data[0]]);
        FreeSpritePaletteByTag(0x2771);
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        if (position == 1)
            REG_DISPCNT |= DISPCNT_BG1_ON;
        else
            REG_DISPCNT |= DISPCNT_BG2_ON;

        DestroyAnimVisualTask(taskId);
        break;
    }

    task->data[15]++;
}

static void sub_80DE7B8(struct Sprite *sprite)
{
    s16 battler1X, battler1Y;
    s16 battler2X, battler2Y;
    s16 yDiff;

    if (gBattleAnimArgs[0] == 0)
    {
        battler1X = GetBattlerSpriteCoord(gAnimBankAttacker, 0);
        battler1Y = GetBattlerSpriteCoord(gAnimBankAttacker, 1) + 28;
        battler2X = GetBattlerSpriteCoord(gAnimBankTarget, 0);
        battler2Y = GetBattlerSpriteCoord(gAnimBankTarget, 1) + 28;
    }
    else
    {
        battler1X = GetBattlerSpriteCoord(gAnimBankTarget, 0);
        battler1Y = GetBattlerSpriteCoord(gAnimBankTarget, 1) + 28;
        battler2X = GetBattlerSpriteCoord(gAnimBankAttacker, 0);
        battler2Y = GetBattlerSpriteCoord(gAnimBankAttacker, 1) + 28;
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
    sprite->callback = sub_80DE8D8;
    sprite->invisible = 1;
}

static void sub_80DE8D8(struct Sprite *sprite)
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

void sub_80DE918(u8 taskId)
{
    struct Task *task;
    s16 battler;
    u8 spriteId;
    s16 baseX, baseY;
    s16 x, y;

    task = &gTasks[taskId];
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = 0x1000;
    task->data[5] = 0;
    task->data[6] = 0;
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 16;
    task->data[10] = gBattleAnimArgs[0];

    baseX = GetBattlerSpriteCoord(gAnimBankAttacker, 2);
    baseY = sub_807A100(gAnimBankAttacker, 3);
    if (!IsContest())
    {
        for (battler = 0; battler < 4; battler++)
        {
            if (battler != gAnimBankAttacker
             && battler != (gAnimBankAttacker ^ 2)
             && IsAnimBankSpriteVisible(battler))
            {
                spriteId = CreateSprite(&gSpriteTemplate_83DAF08, baseX, baseY, 55);
                if (spriteId != MAX_SPRITES)
                {
                    x = GetBattlerSpriteCoord(battler, 2);
                    y = sub_807A100(battler, 3);
                    gSprites[spriteId].data[0] = baseX << 4;
                    gSprites[spriteId].data[1] = baseY << 4;
                    gSprites[spriteId].data[2] = ((x - baseX) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[3] = ((y - baseY) << 4) / gBattleAnimArgs[1];
                    gSprites[spriteId].data[4] = gBattleAnimArgs[1];
                    gSprites[spriteId].data[5] = x;
                    gSprites[spriteId].data[6] = y;
                    gSprites[spriteId].callback = sub_80DE8D8;

                    task->data[task->data[12] + 13] = spriteId;
                    task->data[12]++;
                }
            }
        }
    }
    else
    {
        spriteId = CreateSprite(&gSpriteTemplate_83DAF08, baseX, baseY, 55);
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
            gSprites[spriteId].callback = sub_80DE8D8;

            task->data[13] = spriteId;
            task->data[12] = 1;
        }
    }

    task->func = sub_80DEB38;
}

static void sub_80DEB38(u8 taskId)
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

                REG_BLDALPHA = (task->data[9] << 8) | task->data[8];
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

            REG_BLDALPHA = (task->data[9] << 8) | task->data[8];
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
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_80DECB0(u8 taskId)
{
    s16 startX, startY;
    s16 leftDistance, topDistance, bottomDistance, rightDistance;

    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x3F1F;
    REG_BLDCNT = 0xC8;
    REG_BLDY = 0x10;

    if (GetBattlerSide(gAnimBankAttacker) != B_SIDE_PLAYER || IsContest())
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
    gTasks[taskId].func = sub_80DED60;
}

static void sub_80DED60(u8 taskId)
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
        selectedPalettes = sub_80791A8(1, 0, 0, 0, 0, 0, 0);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 16, RGB(0, 0, 0));
        gTasks[taskId].func = sub_80DEEE8;
    }

    gBattle_WIN0H = (left << 8) | right;
    gBattle_WIN0V = (top  << 8) | bottom;
}

static void sub_80DEEE8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gBattle_WIN0H = 0;
        gBattle_WIN0V = 0;
        REG_WININ = 0x3F3F;
        REG_WINOUT = 0x3F3F;
        REG_BLDCNT = 0;
        REG_BLDY = 0;
        DestroyAnimVisualTask(taskId);
    }
}

static void sub_80DEF3C(struct Sprite *sprite)
{
    s16 xDelta;
    s16 xDelta2;

    InitAnimSpritePos(sprite, 1);
    if (GetBattlerSide(gAnimBankAttacker) == B_SIDE_PLAYER)
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
    sprite->callback = sub_80DEF98;
}

static void sub_80DEF98(struct Sprite *sprite)
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
                StoreSpriteCallbackInData(sprite, sub_80DF018);
            }
            else
            {
                sprite->data[0] = 40;
            }
        }
    }
}

static void sub_80DF018(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        REG_BLDCNT = 0x3F40;
        REG_BLDALPHA = 0x0010;
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
        REG_BLDALPHA = (16 - sprite->data[2]) | (sprite->data[2] << 8);
        if (sprite->data[2] == 16)
        {
            sprite->invisible = 1;
            sprite->callback = sub_80DF090;
        }
    }
}

static void sub_80DF090(struct Sprite *sprite)
{
    REG_BLDCNT = 0;
    REG_BLDALPHA = 0;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    DestroyAnimSprite(sprite);
}

static void sub_80DF0B8(struct Sprite *sprite)
{
    u16 coeffB;
    u16 coeffA;

    sprite->pos2.x = Sin(sprite->data[0], 12);
    if (GetBattlerSide(gAnimBankAttacker) != B_SIDE_PLAYER)
        sprite->pos2.x = -sprite->pos2.x;
    
    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1] += 0x100;
    sprite->pos2.y = -(sprite->data[1] >> 8);

    sprite->data[7]++;
    if (sprite->data[7] == 1)
    {
        sprite->data[6] = 0x050B;
        REG_BLDCNT = 0x3F40;
        REG_BLDALPHA = sprite->data[6];
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

        REG_BLDALPHA = (coeffB << 8) | coeffA;
        sprite->data[6] = (coeffB << 8) | coeffA;
        if (coeffB == 16 && coeffA == 0)
        {
            sprite->invisible = 1;
            sprite->callback = sub_80DF18C;
        }
    }
}

static void sub_80DF18C(struct Sprite *sprite)
{
    REG_BLDCNT = 0;
    REG_BLDALPHA = 0;
    DestroyAnimSprite(sprite);
}

void sub_80DF1A4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 16;
    task->data[9] = GetBattlerSpriteCoord(gAnimBankAttacker, 2);
    task->data[10] = sub_8077FC0(gAnimBankAttacker);
    task->data[11] = (sub_807A100(gAnimBankAttacker, 1) / 2) + 8;
    task->data[7] = 0;
    task->data[5] = sub_8079ED4(gAnimBankAttacker);
    task->data[6] = GetBattlerSubpriority(gAnimBankAttacker) - 2;
    task->data[3] = 0;
    task->data[4] = 16;
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = 0x1000;
    task->data[8] = 0;
    task->func = sub_80DF24C;
}

static void sub_80DF24C(u8 taskId)
{
    u16 i;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        for (i = 0; i < 6; i++)
        {
            spriteId = CreateSprite(&gSpriteTemplate_83DAF80, task->data[9], task->data[10], task->data[6]);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].data[0] = taskId;
                gSprites[spriteId].data[1] = GetBattlerSide(gAnimBankAttacker) == B_SIDE_PLAYER;

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

        REG_BLDALPHA = (task->data[4] << 8) | task->data[3];
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

        REG_BLDALPHA = (task->data[4] << 8) | task->data[3];
        break;
    case 4:
        if (task->data[7] == 0)
            task->data[0]++;
        break;
    case 5:
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void sub_80DF3D8(struct Sprite *sprite)
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

static void sub_80DF49C(struct Sprite *sprite)
{
    sprite->invisible = 1;
    sprite->data[5] = gBankSpriteIds[gAnimBankAttacker];
    sprite->data[0] = 128;
    sprite->data[1] = 10;
    sprite->data[2] = gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[1];
    sprite->callback = sub_80DF4F4;

    gSprites[sprite->data[5]].pos1.y += 8;
}

static void sub_80DF4F4(struct Sprite *sprite)
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
        sprite->callback = move_anim_8074EE0;
    }
}*/

