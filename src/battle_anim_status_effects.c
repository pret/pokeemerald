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
extern const struct OamData gOamData_AffineOff_ObjNormal_8x8;
extern const struct OamData gOamData_AffineOff_ObjBlend_64x64;

static void Task_UpdateFlashingCircleImpacts(u8 taskId);
static void AnimTask_FrozenIceCube_Step1(u8 taskId);
static void AnimTask_FrozenIceCube_Step2(u8 taskId);
static void AnimTask_FrozenIceCube_Step3(u8 taskId);
static void AnimTask_FrozenIceCube_Step4(u8 taskId);
static void Task_DoStatusAnimation(u8 taskId);
static void AnimFlashingCircleImpact(struct Sprite *sprite);
static void AnimFlashingCircleImpact_Step(struct Sprite *sprite);

static const union AnimCmd sAnim_FlickeringOrb[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_FlickeringOrb[] =
{
    sAnim_FlickeringOrb
};

// Unused
static const struct SpriteTemplate sFlickeringOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORB,
    .paletteTag = ANIM_TAG_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_FlickeringOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTranslateLinearAndFlicker,
};

// Unused
static const struct SpriteTemplate sFlickeringOrbFlippedSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORB,
    .paletteTag = ANIM_TAG_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_FlickeringOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTranslateLinearAndFlicker_Flipped,
};

static const union AnimCmd sAnim_WeatherBallNormal[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_WeatherBallNormal[] =
{
    sAnim_WeatherBallNormal
};

const struct SpriteTemplate gWeatherBallUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_WEATHER_BALL,
    .paletteTag = ANIM_TAG_WEATHER_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_WeatherBallNormal,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWeatherBallUp,
};

const struct SpriteTemplate gWeatherBallNormalDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_WEATHER_BALL,
    .paletteTag = ANIM_TAG_WEATHER_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_WeatherBallNormal,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWeatherBallDown,
};

static const union AnimCmd sAnim_SpinningSparkle[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END
};

const union AnimCmd *const gAnims_SpinningSparkle[] =
{
    sAnim_SpinningSparkle
};

const struct SpriteTemplate gSpinningSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_SpinningSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpinningSparkle,
};

// Unused
static const struct SpriteTemplate sFlickeringFootSpriteTemplate =
{
    .tileTag = ANIM_TAG_MONSTER_FOOT,
    .paletteTag = ANIM_TAG_MONSTER_FOOT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTranslateLinearAndFlicker,
};

static const union AnimCmd sAnim_FlickeringImpact_0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_FlickeringImpact_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_FlickeringImpact_2[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_FlickeringImpact[] =
{
    sAnim_FlickeringImpact_0,
    sAnim_FlickeringImpact_1,
    sAnim_FlickeringImpact_2,
};

// Unused
static const struct SpriteTemplate sFlickeringImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FlickeringImpact,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTranslateLinearAndFlicker,
};

static const union AnimCmd sAnim_FlickeringShrinkOrb[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_FlickeringShrinkOrb[] =
{
    sAnim_FlickeringShrinkOrb
};

static const union AffineAnimCmd sAffineAnim_FlickeringShrinkOrb[] =
{
    AFFINEANIMCMD_FRAME(96, 96, 0, 0),
    AFFINEANIMCMD_FRAME(2, 2, 0, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd *const sAffineAnims_FlickeringShrinkOrb[] =
{
    sAffineAnim_FlickeringShrinkOrb
};

// Unused
static const struct SpriteTemplate sFlickeringShrinkOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORB,
    .paletteTag = ANIM_TAG_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sAnims_FlickeringShrinkOrb,
    .images = NULL,
    .affineAnims = sAffineAnims_FlickeringShrinkOrb,
    .callback = AnimTranslateLinearAndFlicker_Flipped,
};

static const struct Subsprite sFrozenIceCubeSubsprites[] =
{
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 2
    },
    {
        .x = -16,
        .y =  48,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 64,
        .priority = 2
    },
    {
        .x =  48,
        .y = -16,
        .shape = SPRITE_SHAPE(32x64),
        .size = SPRITE_SIZE(32x64),
        .tileOffset = 96,
        .priority = 2
    },
    {
        .x =  48,
        .y =  48,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 128,
        .priority = 2
    },
};

static const struct SubspriteTable sFrozenIceCubeSubspriteTable[] =
{
    {ARRAY_COUNT(sFrozenIceCubeSubsprites), sFrozenIceCubeSubsprites},
};

static const struct SpriteTemplate sFrozenIceCubeSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CUBE,
    .paletteTag = ANIM_TAG_ICE_CUBE,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sFlashingCircleImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_IMPACT,
    .paletteTag = ANIM_TAG_CIRCLE_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlashingCircleImpact,
};

static u8 UNUSED Task_FlashingCircleImpacts(u8 battlerId, bool8 red)
{
    u8 battlerSpriteId = gBattlerSpriteIds[battlerId];
    u8 taskId = CreateTask(Task_UpdateFlashingCircleImpacts, 10);
    u8 spriteId;
    u8 i;

    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_CIRCLE_IMPACT)]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_CIRCLE_IMPACT)]);
    gTasks[taskId].data[0] = battlerId;
    if (red)
    {
        gTasks[taskId].data[1] = RGB_RED;
        for (i = 0; i < 10; i++)
        {
            spriteId = CreateSprite(&sFlashingCircleImpactSpriteTemplate, gSprites[battlerSpriteId].x, gSprites[battlerSpriteId].y + 32, 0);
            gSprites[spriteId].data[0] = i * 51;
            gSprites[spriteId].data[1] = -256;
            gSprites[spriteId].invisible = TRUE;
            if (i > 4)
                gSprites[spriteId].data[6] = 21;
        }
    }
    else
    {
        gTasks[taskId].data[1] = RGB_BLUE;
        for (i = 0; i < 10; i++)
        {
            spriteId = CreateSprite(&sFlashingCircleImpactSpriteTemplate, gSprites[battlerSpriteId].x, gSprites[battlerSpriteId].y - 32, 0);
            gSprites[spriteId].data[0] = i * 51;
            gSprites[spriteId].data[1] = 256;
            gSprites[spriteId].invisible = TRUE;
            if (i > 4)
                gSprites[spriteId].data[6] = 21;
        }
    }
    gSprites[spriteId].data[7] = 1;
    return taskId;
}

static void Task_UpdateFlashingCircleImpacts(u8 taskId)
{
    if (gTasks[taskId].data[2] == 2)
    {
        gTasks[taskId].data[2] = 0;
        BlendPalette(OBJ_PLTT_ID(gTasks[taskId].data[0]), 16, gTasks[taskId].data[4], gTasks[taskId].data[1]);
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

static void AnimFlashingCircleImpact(struct Sprite *sprite)
{
    if (sprite->data[6] == 0)
    {
        sprite->invisible = FALSE;
        sprite->callback = AnimFlashingCircleImpact_Step;
        AnimFlashingCircleImpact_Step(sprite);
    }
    else
    {
        sprite->data[6]--;
    }
}

static void AnimFlashingCircleImpact_Step(struct Sprite *sprite)
{
    sprite->x2 = Cos(sprite->data[0], 32);
    sprite->y2 = Sin(sprite->data[0], 8);
    if (sprite->data[0] < 128)
        sprite->subpriority = 29;
    else
        sprite->subpriority = 31;
    sprite->data[0] = (sprite->data[0] + 8) & 0xFF;
    sprite->data[5] += sprite->data[1];
    sprite->y2 += sprite->data[5] >> 8;
    sprite->data[2]++;
    if (sprite->data[2] == 52)
    {
        if (sprite->data[7])
            DestroySpriteAndFreeResources(sprite);
        else
            DestroySprite(sprite);
    }
}

void AnimTask_FrozenIceCubeAttacker(u8 taskId)
{
    s16 x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) - 32;
    s16 y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) - 36;
    u8 spriteId;

    if (IsContest())
        x -= 6;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    spriteId = CreateSprite(&sFrozenIceCubeSpriteTemplate, x, y, 4);
    if (GetSpriteTileStartByTag(ANIM_TAG_ICE_CUBE) == 0xFFFF)
        gSprites[spriteId].invisible = TRUE;
    SetSubspriteTables(&gSprites[spriteId], sFrozenIceCubeSubspriteTable);
    gTasks[taskId].data[15] = spriteId;
    gTasks[taskId].func = AnimTask_FrozenIceCube_Step1;
}

void AnimTask_CentredFrozenIceCube(u8 taskId)
{
    // same as AnimTask_FrozenIceCube but center position on target(s)
	s16 x, y;
	u8 spriteId;
	u8 battler1 = gBattleAnimTarget;
	u8 battler2 = BATTLE_PARTNER(battler1);

	if (!IsDoubleBattle() || IsAlly(gBattleAnimAttacker, gBattleAnimTarget))
	{
		x = GetBattlerSpriteCoord(battler1, BATTLER_COORD_X_2);
		y = GetBattlerSpriteCoord(battler1, BATTLER_COORD_Y_PIC_OFFSET);
	}
	else
	{
		x = (GetBattlerSpriteCoord(battler1, BATTLER_COORD_X_2) + GetBattlerSpriteCoord(battler2, BATTLER_COORD_X_2)) / 2;
		y = (GetBattlerSpriteCoord(battler1, BATTLER_COORD_Y_PIC_OFFSET) + GetBattlerSpriteCoord(battler2, BATTLER_COORD_Y_PIC_OFFSET)) / 2;
	}

	x -= 32;
	y -= 36;

	spriteId = CreateSprite(&sFrozenIceCubeSpriteTemplate, x, y, 4);
	if (GetSpriteTileStartByTag(ANIM_TAG_ICE_CUBE) == 0xFFFF)
		gSprites[spriteId].invisible = TRUE;

    SetSubspriteTables(&gSprites[spriteId], sFrozenIceCubeSubspriteTable);
    gTasks[taskId].data[15] = spriteId;
    gTasks[taskId].func = AnimTask_FrozenIceCube_Step1;
}

void AnimTask_FrozenIceCube(u8 taskId)
{
    s16 x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) - 32;
    s16 y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) - 36;
    u8 spriteId;

    if (IsContest())
        x -= 6;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    spriteId = CreateSprite(&sFrozenIceCubeSpriteTemplate, x, y, 4);
    if (GetSpriteTileStartByTag(ANIM_TAG_ICE_CUBE) == 0xFFFF)
        gSprites[spriteId].invisible = TRUE;
    SetSubspriteTables(&gSprites[spriteId], sFrozenIceCubeSubspriteTable);
    gTasks[taskId].data[15] = spriteId;
    gTasks[taskId].func = AnimTask_FrozenIceCube_Step1;
}

static void AnimTask_FrozenIceCube_Step1(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] == 10)
    {
        gTasks[taskId].func = AnimTask_FrozenIceCube_Step2;
        gTasks[taskId].data[1] = 0;
    }
    else
    {
        u8 var = gTasks[taskId].data[1];

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(var, 16 - var));
    }
}

static void AnimTask_FrozenIceCube_Step2(u8 taskId)
{
    u8 palIndex = IndexOfSpritePaletteTag(ANIM_TAG_ICE_CUBE);

    if (gTasks[taskId].data[1]++ > 13)
    {
        gTasks[taskId].data[2]++;
        if (gTasks[taskId].data[2] == 3)
        {
            u16 temp;

            temp = gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 13];
            gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 13] = gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 14];
            gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 14] = gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 15];
            gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + 15] = temp;

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
                    gTasks[taskId].func = AnimTask_FrozenIceCube_Step3;
                }
            }
        }
    }
}

static void AnimTask_FrozenIceCube_Step3(u8 taskId)
{
    gTasks[taskId].data[1]--;
    if (gTasks[taskId].data[1] == -1)
    {
        gTasks[taskId].func = AnimTask_FrozenIceCube_Step4;
        gTasks[taskId].data[1] = 0;
    }
    else
    {
        u8 var = gTasks[taskId].data[1];

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(var, 16 - var));
    }
}

static void AnimTask_FrozenIceCube_Step4(u8 taskId)
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

void AnimTask_StatsChange(u8 taskId)
{
    bool16 goesDown = FALSE;
    s16 animStatId = 0;
    bool16 sharply = FALSE;

    switch (gBattleSpritesDataPtr->animationData->animArg)
    {
    case STAT_ANIM_PLUS1 + STAT_ATK:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_ATK;      break;
    case STAT_ANIM_PLUS1 + STAT_DEF:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_DEF;      break;
    case STAT_ANIM_PLUS1 + STAT_SPEED:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPEED;    break;
    case STAT_ANIM_PLUS1 + STAT_SPATK:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPATK;    break;
    case STAT_ANIM_PLUS1 + STAT_SPDEF:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPDEF;    break;
    case STAT_ANIM_PLUS1 + STAT_ACC:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_ACC;      break;
    case STAT_ANIM_PLUS1 + STAT_EVASION: goesDown = FALSE;  animStatId = STAT_ANIM_PAL_EVASION;  break;

    case STAT_ANIM_MINUS1 + STAT_ATK:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_ATK;      break;
    case STAT_ANIM_MINUS1 + STAT_DEF:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_DEF;      break;
    case STAT_ANIM_MINUS1 + STAT_SPEED:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPEED;    break;
    case STAT_ANIM_MINUS1 + STAT_SPATK:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPATK;    break;
    case STAT_ANIM_MINUS1 + STAT_SPDEF:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPDEF;    break;
    case STAT_ANIM_MINUS1 + STAT_ACC:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_ACC;      break;
    case STAT_ANIM_MINUS1 + STAT_EVASION: goesDown = TRUE;  animStatId = STAT_ANIM_PAL_EVASION;  break;

    case STAT_ANIM_PLUS2 + STAT_ATK:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_ATK;      sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_DEF:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_DEF;      sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_SPEED:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPEED;    sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_SPATK:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPATK;    sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_SPDEF:   goesDown = FALSE;  animStatId = STAT_ANIM_PAL_SPDEF;    sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_ACC:     goesDown = FALSE;  animStatId = STAT_ANIM_PAL_ACC;      sharply = TRUE;  break;
    case STAT_ANIM_PLUS2 + STAT_EVASION: goesDown = FALSE;  animStatId = STAT_ANIM_PAL_EVASION;  sharply = TRUE;  break;

    case STAT_ANIM_MINUS2 + STAT_ATK:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_ATK;      sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_DEF:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_DEF;      sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_SPEED:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPEED;    sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_SPATK:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPATK;    sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_SPDEF:   goesDown = TRUE;  animStatId = STAT_ANIM_PAL_SPDEF;    sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_ACC:     goesDown = TRUE;  animStatId = STAT_ANIM_PAL_ACC;      sharply = TRUE;  break;
    case STAT_ANIM_MINUS2 + STAT_EVASION: goesDown = TRUE;  animStatId = STAT_ANIM_PAL_EVASION;  sharply = TRUE;  break;

    case STAT_ANIM_MULTIPLE_PLUS1:  goesDown = FALSE;  animStatId = STAT_ANIM_PAL_MULTIPLE;  sharply = FALSE;  break;
    case STAT_ANIM_MULTIPLE_PLUS2:  goesDown = FALSE;  animStatId = STAT_ANIM_PAL_MULTIPLE;  sharply = TRUE;   break;
    case STAT_ANIM_MULTIPLE_MINUS1: goesDown = TRUE;   animStatId = STAT_ANIM_PAL_MULTIPLE;  sharply = FALSE;  break;
    case STAT_ANIM_MULTIPLE_MINUS2: goesDown = TRUE;   animStatId = STAT_ANIM_PAL_MULTIPLE;  sharply = TRUE;   break;

    default:
        DestroyAnimVisualTask(taskId);
        return;
    }

    gBattleAnimArgs[0] = goesDown;
    gBattleAnimArgs[1] = animStatId;
    gBattleAnimArgs[2] = FALSE; // Whether it's the target, rather than attacker
    gBattleAnimArgs[3] = FALSE; // Whether it hits multiple battlers
    gBattleAnimArgs[4] = sharply;
    gTasks[taskId].func = InitStatsChangeAnimation;
    gTasks[taskId].func(taskId);
}

#undef CASE

void LaunchStatusAnimation(u8 battlerId, u8 statusAnimId)
{
    u8 taskId;

    gBattleAnimAttacker = battlerId;
    gBattleAnimTarget = battlerId;
    LaunchBattleAnimation(ANIM_TYPE_STATUS, statusAnimId);
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
