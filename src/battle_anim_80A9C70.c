#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
extern const u8 *const gBattleAnims_StatusConditions[];
extern const struct OamData gUnknown_08524904;
extern const struct OamData gUnknown_08524A3C;

// This file's functions.
static void sub_80A9DB4(u8 taskId);
static void sub_80A9FD0(u8 taskId);
static void sub_80AA020(u8 taskId);
static void sub_80AA0D0(u8 taskId);
static void sub_80AA124(u8 taskId);
static void Task_DoStatusAnimation(u8 taskId);
static void sub_80A9E44(struct Sprite *sprite);
static void sub_80A9E78(struct Sprite *sprite);

// const rom data
static const struct Subsprite gUnknown_0853EF30[] =
{
    {.x = -16, .y = -16, .shape = ST_OAM_SQUARE,      .size = 3, .tileOffset =   0, .priority = 2},
    {.x = -16, .y =  48, .shape = ST_OAM_H_RECTANGLE, .size = 3, .tileOffset =  64, .priority = 2},
    {.x =  48, .y = -16, .shape = ST_OAM_V_RECTANGLE, .size = 3, .tileOffset =  96, .priority = 2},
    {.x =  48, .y =  48, .shape = ST_OAM_SQUARE,      .size = 2, .tileOffset = 128, .priority = 2},
};

static const struct SubspriteTable gUnknown_0853EF40[] =
{
    {ARRAY_COUNT(gUnknown_0853EF30), gUnknown_0853EF30},
};

static const struct SpriteTemplate gUnknown_0853EF48 =
{
    .tileTag = ANIM_TAG_ICE_CUBE,
    .paletteTag = ANIM_TAG_ICE_CUBE,
    .oam = &gUnknown_08524A3C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gUnknown_0853EF60 =
{
    .tileTag = ANIM_TAG_CIRCLE_IMPACT,
    .paletteTag = ANIM_TAG_CIRCLE_IMPACT,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80A9E44,
};

// code
u8 sub_80A9C70(u8 battlerId, bool8 b)
{
    u8 battlerSpriteId = gBattlerSpriteIds[battlerId];
    u8 taskId = CreateTask(sub_80A9DB4, 10);
    u8 spriteId2;
    u8 i;

    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_CIRCLE_IMPACT)]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_CIRCLE_IMPACT)]);
    gTasks[taskId].data[0] = battlerId;
    if (b)
    {
        gTasks[taskId].data[1] = RGB_RED;
        for (i = 0; i < 10; i++)
        {
            spriteId2 = CreateSprite(&gUnknown_0853EF60, gSprites[battlerSpriteId].pos1.x, gSprites[battlerSpriteId].pos1.y + 32, 0);
            gSprites[spriteId2].data[0] = i * 51;
            gSprites[spriteId2].data[1] = -256;
            gSprites[spriteId2].invisible = TRUE;
            if (i > 4)
                gSprites[spriteId2].data[6] = 21;
        }
    }
    else
    {
        gTasks[taskId].data[1] = RGB_BLUE;
        for (i = 0; i < 10; i++)
        {
            spriteId2 = CreateSprite(&gUnknown_0853EF60, gSprites[battlerSpriteId].pos1.x, gSprites[battlerSpriteId].pos1.y - 32, 0);
            gSprites[spriteId2].data[0] = i * 51;
            gSprites[spriteId2].data[1] = 256;
            gSprites[spriteId2].invisible = TRUE;
            if (i > 4)
                gSprites[spriteId2].data[6] = 21;
        }
    }
    gSprites[spriteId2].data[7] = 1;
    return taskId;
}

static void sub_80A9DB4(u8 taskId)
{
    if (gTasks[taskId].data[2] == 2)
    {
        gTasks[taskId].data[2] = 0;
        BlendPalette(0x100 + gTasks[taskId].data[0] * 16, 16, gTasks[taskId].data[4], gTasks[taskId].data[1]);
        if (gTasks[taskId].data[5] == 0)
        {
            gTasks[taskId].data[4]++;
            if (gTasks[taskId].data[4] > 8)
                gTasks[taskId].data[5] ^= 1;
        }
        else
        {
            u16 var = gTasks[taskId].data[4];

            gTasks[taskId].data[4]--;
            if (gTasks[taskId].data[4] < 0)
            {
                gTasks[taskId].data[4] = var;
                gTasks[taskId].data[5] ^= 1;
                gTasks[taskId].data[3]++;
                if (gTasks[taskId].data[3] == 2)
                    DestroyTask(taskId);
            }
        }
    }
    else
    {
        gTasks[taskId].data[2]++;
    }
}

static void sub_80A9E44(struct Sprite *sprite)
{
    if (sprite->data[6] == 0)
    {
        sprite->invisible = FALSE;
        sprite->callback = sub_80A9E78;
        sub_80A9E78(sprite);
    }
    else
    {
        sprite->data[6]--;
    }
}

static void sub_80A9E78(struct Sprite *sprite)
{
    sprite->pos2.x = Cos(sprite->data[0], 32);
    sprite->pos2.y = Sin(sprite->data[0], 8);
    if (sprite->data[0] < 128)
        sprite->subpriority = 29;
    else
        sprite->subpriority = 31;
    sprite->data[0] = (sprite->data[0] + 8) & 0xFF;
    sprite->data[5] += sprite->data[1];
    sprite->pos2.y += sprite->data[5] >> 8;
    sprite->data[2]++;
    if (sprite->data[2] == 52)
    {
        if (sprite->data[7])
            DestroySpriteAndFreeResources(sprite);
        else
            DestroySprite(sprite);
    }
}

void sub_80A9EF4(u8 taskId)
{
    s16 x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) - 32;
    s16 y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) - 36;
    u8 spriteId;

    if (IsContest())
        x -= 6;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    spriteId = CreateSprite(&gUnknown_0853EF48, x, y, 4);
    if (GetSpriteTileStartByTag(ANIM_TAG_ICE_CUBE) == 0xFFFF)
        gSprites[spriteId].invisible = TRUE;
    SetSubspriteTables(&gSprites[spriteId], gUnknown_0853EF40);
    gTasks[taskId].data[15] = spriteId;
    gTasks[taskId].func = sub_80A9FD0;
}

static void sub_80A9FD0(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] == 10)
    {
        gTasks[taskId].func = sub_80AA020;
        gTasks[taskId].data[1] = 0;
    }
    else
    {
        u8 var = gTasks[taskId].data[1];

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(var, 16 - var));
    }
}

static void sub_80AA020(u8 taskId)
{
    u8 palIndex = IndexOfSpritePaletteTag(ANIM_TAG_ICE_CUBE);

    if (gTasks[taskId].data[1]++ > 13)
    {
        gTasks[taskId].data[2]++;
        if (gTasks[taskId].data[2] == 3)
        {
            u16 temp;

            temp = gPlttBufferFaded[0x100 + palIndex * 16 + 13];
            gPlttBufferFaded[0x100 + palIndex * 16 + 13] = gPlttBufferFaded[0x100 + palIndex * 16 + 14];
            gPlttBufferFaded[0x100 + palIndex * 16 + 14] = gPlttBufferFaded[0x100 + palIndex * 16 + 15];
            gPlttBufferFaded[0x100 + palIndex * 16 + 15] = temp;

            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[3]++;
            if (gTasks[taskId].data[3] == 3)
            {
                gTasks[taskId].data[3] = 0;
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[4]++;
                if (gTasks[taskId].data[4] == 2)
                {
                    gTasks[taskId].data[1] = 9;
                    gTasks[taskId].func = sub_80AA0D0;
                }
            }
        }
    }
}

static void sub_80AA0D0(u8 taskId)
{
    gTasks[taskId].data[1]--;
    if (gTasks[taskId].data[1] == -1)
    {
        gTasks[taskId].func = sub_80AA124;
        gTasks[taskId].data[1] = 0;
    }
    else
    {
        u8 var = gTasks[taskId].data[1];

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(var, 16 - var));
    }
}

static void sub_80AA124(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] == 37)
    {
        u8 spriteId = gTasks[taskId].data[15];

        FreeSpriteOamMatrix(&gSprites[spriteId]);
        DestroySprite(&gSprites[spriteId]);
    }
    else if (gTasks[taskId].data[1] == 39)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
    }
}

#define CASE(by, stat) case (STAT_ANIM_##by + stat - 1)

void AnimTask_StatsChange(u8 taskId)
{
    bool16 goesDown = FALSE;
    s16 animStatId = 0;
    bool16 sharply = FALSE;

    switch (gBattleSpritesDataPtr->animationData->animArg)
    {
    CASE(PLUS1,  STAT_ATK):     goesDown = FALSE;  animStatId = 0;  break;
    CASE(PLUS1,  STAT_DEF):     goesDown = FALSE;  animStatId = 1;  break;
    CASE(PLUS1,  STAT_SPEED):   goesDown = FALSE;  animStatId = 3;  break;
    CASE(PLUS1,  STAT_SPATK):   goesDown = FALSE;  animStatId = 5;  break;
    CASE(PLUS1,  STAT_SPDEF):   goesDown = FALSE;  animStatId = 6;  break;
    CASE(PLUS1,  STAT_ACC):     goesDown = FALSE;  animStatId = 2;  break;
    CASE(PLUS1,  STAT_EVASION): goesDown = FALSE;  animStatId = 4;  break;

    CASE(MINUS1, STAT_ATK):     goesDown = TRUE;   animStatId = 0;  break;
    CASE(MINUS1, STAT_DEF):     goesDown = TRUE;   animStatId = 1;  break;
    CASE(MINUS1, STAT_SPEED):   goesDown = TRUE;   animStatId = 3;  break;
    CASE(MINUS1, STAT_SPATK):   goesDown = TRUE;   animStatId = 5;  break;
    CASE(MINUS1, STAT_SPDEF):   goesDown = TRUE;   animStatId = 6;  break;
    CASE(MINUS1, STAT_ACC):     goesDown = TRUE;   animStatId = 2;  break;
    CASE(MINUS1, STAT_EVASION): goesDown = TRUE;   animStatId = 4;  break;

    CASE(PLUS2,  STAT_ATK):     goesDown = FALSE;  animStatId = 0;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_DEF):     goesDown = FALSE;  animStatId = 1;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_SPEED):   goesDown = FALSE;  animStatId = 3;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_SPATK):   goesDown = FALSE;  animStatId = 5;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_SPDEF):   goesDown = FALSE;  animStatId = 6;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_ACC):     goesDown = FALSE;  animStatId = 2;     sharply = TRUE;   break;
    CASE(PLUS2,  STAT_EVASION): goesDown = FALSE;  animStatId = 4;     sharply = TRUE;   break;

    CASE(MINUS2, STAT_ATK):     goesDown = TRUE;   animStatId = 0;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_DEF):     goesDown = TRUE;   animStatId = 1;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_SPEED):   goesDown = TRUE;   animStatId = 3;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_SPATK):   goesDown = TRUE;   animStatId = 5;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_SPDEF):   goesDown = TRUE;   animStatId = 6;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_ACC):     goesDown = TRUE;   animStatId = 2;     sharply = TRUE;   break;
    CASE(MINUS2, STAT_EVASION): goesDown = TRUE;   animStatId = 4;     sharply = TRUE;   break;

    case STAT_ANIM_MULTIPLE_PLUS1:  goesDown = FALSE;  animStatId = 0xFF;  sharply = FALSE;  break;
    case STAT_ANIM_MULTIPLE_PLUS2:  goesDown = FALSE;  animStatId = 0xFF;  sharply = TRUE;   break;
    case STAT_ANIM_MULTIPLE_MINUS1: goesDown = TRUE;   animStatId = 0xFF;  sharply = FALSE;  break;
    case STAT_ANIM_MULTIPLE_MINUS2: goesDown = TRUE;   animStatId = 0xFF;  sharply = TRUE;   break;

    default:
        DestroyAnimVisualTask(taskId);
        return;
    }

    gBattleAnimArgs[0] = goesDown;
    gBattleAnimArgs[1] = animStatId;
    gBattleAnimArgs[2] = 0;
    gBattleAnimArgs[3] = 0;
    gBattleAnimArgs[4] = sharply;
    gTasks[taskId].func = sub_8116EB4;
    sub_8116EB4(taskId);
}

#undef CASE

void LaunchStatusAnimation(u8 battlerId, u8 statusAnimId)
{
    u8 taskId;

    gBattleAnimAttacker = battlerId;
    gBattleAnimTarget = battlerId;
    LaunchBattleAnimation(gBattleAnims_StatusConditions, statusAnimId, 0);
    taskId = CreateTask(Task_DoStatusAnimation, 10);
    gTasks[taskId].data[0] = battlerId;
}

static void Task_DoStatusAnimation(u8 taskId)
{
    gAnimScriptCallback();
    if (!gAnimScriptActive)
    {
        gBattleSpritesDataPtr->healthBoxesData[gTasks[taskId].data[0]].statusAnimActive = FALSE;
        DestroyTask(taskId);
    }
}
