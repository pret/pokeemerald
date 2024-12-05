#include "global.h"
#include "evolution_graphics.h"
#include "sprite.h"
#include "trig.h"
#include "random.h"
#include "decompress.h"
#include "task.h"
#include "sound.h"
#include "constants/songs.h"
#include "palette.h"
#include "constants/rgb.h"

static void SpriteCB_Sparkle_Dummy(struct Sprite *sprite);

static void Task_Sparkles_SpiralUpward_Init(u8 taskId);
static void Task_Sparkles_SpiralUpward(u8 taskId);
static void Task_Sparkles_SpiralUpward_End(u8 taskId);

static void Task_Sparkles_ArcDown_Init(u8 taskId);
static void Task_Sparkles_ArcDown(u8 taskId);
static void Task_Sparkles_ArcDown_End(u8 taskId);

static void Task_Sparkles_CircleInward_Init(u8 taskId);
static void Task_Sparkles_CircleInward(u8 taskId);
static void Task_Sparkles_CircleInward_End(u8 taskId);

static void Task_Sparkles_SprayAndFlash_Init(u8 taskId);
static void Task_Sparkles_SprayAndFlash(u8 taskId);
static void Task_Sparkles_SprayAndFlashTrade_Init(u8 taskId);
static void Task_Sparkles_SprayAndFlashTrade(u8 taskId);
static void Task_Sparkles_SprayAndFlash_End(u8 taskId);

static void Task_CycleEvolutionMonSprite_Init(u8 taskId);
static void Task_CycleEvolutionMonSprite_TryEnd(u8 taskId);
static void Task_CycleEvolutionMonSprite_UpdateSize(u8 taskId);
static void EndOnPreEvoMon(u8 taskId);
static void EndOnPostEvoMon(u8 taskId);

#define TAG_SPARKLE 1001

static const u16 sEvoSparkle_Pal[] = INCBIN_U16("graphics/misc/evo_sparkle.gbapal");
static const u32 sEvoSparkle_Gfx[] = INCBIN_U32("graphics/misc/evo_sparkle.4bpp.lz");

static const struct CompressedSpriteSheet sEvoSparkleSpriteSheets[] =
{
    {sEvoSparkle_Gfx, 0x20, TAG_SPARKLE},
    {NULL, 0, 0}
};

static const struct SpritePalette sEvoSparkleSpritePals[] =
{
    {sEvoSparkle_Pal, TAG_SPARKLE},
    {NULL, 0}
};

static const struct OamData sOamData_EvoSparkle =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_EvoSparkle[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_EvoSparkle[] =
{
    sSpriteAnim_EvoSparkle,
};

static const struct SpriteTemplate sEvoSparkleSpriteTemplate =
{
    .tileTag = TAG_SPARKLE,
    .paletteTag = TAG_SPARKLE,
    .oam = &sOamData_EvoSparkle,
    .anims = sSpriteAnimTable_EvoSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Sparkle_Dummy
};

static const u16 sEvoSparkleMatrices[] =
{
    0x3C0, 0x380, 0x340, 0x300, 0x2C0, 0x280,
    0x240, 0x200, 0x1C0, 0x180, 0x140, 0x100
};

static const s16 sUnused[] =
{
    -4, 0x10,
    -3, 0x30,
    -2, 0x50,
    -1, 0x70,
     1, 0x70,
     2, 0x50,
     3, 0x30,
     4, 0x10
};

static void SpriteCB_Sparkle_Dummy(struct Sprite *sprite)
{

}

static void SetEvoSparklesMatrices(void)
{
    u16 i;
    for (i = 0; i < ARRAY_COUNT(sEvoSparkleMatrices); i++)
        SetOamMatrix(20 + i, sEvoSparkleMatrices[i], 0, 0, sEvoSparkleMatrices[i]);
}

#define sSpeed     data[3]
#define sAmplitude data[5]
#define sTrigIdx   data[6]
#define sTimer     data[7]

static void SpriteCB_Sparkle_SpiralUpward(struct Sprite *sprite)
{
    if (sprite->y > 8)
    {
        u8 matrixNum;

        sprite->y = 88 - (sprite->sTimer * sprite->sTimer) / 80;
        sprite->y2 = Sin((u8)sprite->sTrigIdx, sprite->sAmplitude) / 4;
        sprite->x2 = Cos((u8)sprite->sTrigIdx, sprite->sAmplitude);
        sprite->sTrigIdx += 4;
        if (sprite->sTimer & 1)
            sprite->sAmplitude--;
        sprite->sTimer++;
        if (sprite->y2 > 0)
            sprite->subpriority = 1;
        else
            sprite->subpriority = 20;
        matrixNum = sprite->sAmplitude / 4 + 20;
        if (matrixNum > 31)
            matrixNum = 31;
        sprite->oam.matrixNum = matrixNum;
    }
    else
    {
        DestroySprite(sprite);
    }
}

static void CreateSparkle_SpiralUpward(u8 trigIdx)
{
    u8 spriteId = CreateSprite(&sEvoSparkleSpriteTemplate, DISPLAY_WIDTH / 2, 88, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sAmplitude = 48;
        gSprites[spriteId].sTrigIdx = trigIdx;
        gSprites[spriteId].sTimer = 0;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 31;
        gSprites[spriteId].callback = SpriteCB_Sparkle_SpiralUpward;
    }
}

static void SpriteCB_Sparkle_ArcDown(struct Sprite *sprite)
{
    if (sprite->y < 88)
    {
        sprite->y = 8 + (sprite->sTimer * sprite->sTimer) / 5;
        sprite->y2 = Sin((u8)sprite->sTrigIdx, sprite->sAmplitude) / 4;
        sprite->x2 = Cos((u8)sprite->sTrigIdx, sprite->sAmplitude);
        sprite->sAmplitude = 8 + Sin((u8)(sprite->sTimer * 4), 40);
        sprite->sTimer++;
    }
    else
    {
        DestroySprite(sprite);
    }
}

static void CreateSparkle_ArcDown(u8 trigIdx)
{
    u8 spriteId = CreateSprite(&sEvoSparkleSpriteTemplate, DISPLAY_WIDTH / 2, 8, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sAmplitude = 8;
        gSprites[spriteId].sTrigIdx = trigIdx;
        gSprites[spriteId].sTimer = 0;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 25;
        gSprites[spriteId].subpriority = 1;
        gSprites[spriteId].callback = SpriteCB_Sparkle_ArcDown;
    }
}

static void SpriteCB_Sparkle_CircleInward(struct Sprite *sprite)
{
    if (sprite->sAmplitude > 8)
    {
        sprite->y2 = Sin((u8)sprite->sTrigIdx, sprite->sAmplitude);
        sprite->x2 = Cos((u8)sprite->sTrigIdx, sprite->sAmplitude);
        sprite->sAmplitude -= sprite->sSpeed;
        sprite->sTrigIdx += 4;
    }
    else
    {
        DestroySprite(sprite);
    }
}

static void CreateSparkle_CircleInward(u8 trigIdx, u8 speed)
{
    u8 spriteId = CreateSprite(&sEvoSparkleSpriteTemplate, DISPLAY_WIDTH / 2, 56, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sSpeed = speed;
        gSprites[spriteId].sAmplitude = 120;
        gSprites[spriteId].sTrigIdx = trigIdx;
        gSprites[spriteId].sTimer = 0;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 31;
        gSprites[spriteId].subpriority = 1;
        gSprites[spriteId].callback = SpriteCB_Sparkle_CircleInward;
    }
}

static void SpriteCB_Sparkle_Spray(struct Sprite *sprite)
{
    if (!(sprite->sTimer & 3))
        sprite->y++;
    if (sprite->sTrigIdx < 128)
    {
        u8 matrixNum;

        sprite->y2 = -Sin((u8)sprite->sTrigIdx, sprite->sAmplitude);
        sprite->x = (DISPLAY_WIDTH / 2) + (sprite->sSpeed * sprite->sTimer) / 3;
        sprite->sTrigIdx++;
        matrixNum = 31 - (sprite->sTrigIdx * 12 / 128);
        if (sprite->sTrigIdx > 64)
        {
            sprite->subpriority = 1;
        }
        else
        {
            sprite->invisible = FALSE;
            sprite->subpriority = 20;
            if (sprite->sTrigIdx > 112 && sprite->sTrigIdx & 1)
                sprite->invisible = TRUE;
        }
        if (matrixNum < 20)
            matrixNum = 20;
        sprite->oam.matrixNum = matrixNum;
        sprite->sTimer++;
    }
    else
    {
        DestroySprite(sprite);
    }
}

static void CreateSparkle_Spray(u8 id)
{
    u8 spriteId = CreateSprite(&sEvoSparkleSpriteTemplate, DISPLAY_WIDTH / 2, 56, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sSpeed = 3 - (Random() % 7);
        gSprites[spriteId].sAmplitude = 48 + (Random() & 0x3F);
        gSprites[spriteId].sTimer = 0;
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 31;
        gSprites[spriteId].subpriority = 20;
        gSprites[spriteId].callback = SpriteCB_Sparkle_Spray;
    }
}

void LoadEvoSparkleSpriteAndPal(void)
{
    LoadCompressedSpriteSheetUsingHeap(&sEvoSparkleSpriteSheets[0]);
    LoadSpritePalettes(sEvoSparkleSpritePals);
}

#define tPalNum data[1]
#define tTimer  data[15]

u8 EvolutionSparkles_SpiralUpward(u16 palNum)
{
    u8 taskId = CreateTask(Task_Sparkles_SpiralUpward_Init, 0);
    gTasks[taskId].tPalNum = palNum;
    return taskId;
}

static void Task_Sparkles_SpiralUpward_Init(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].tTimer = 0;
    BeginNormalPaletteFade(3 << gTasks[taskId].tPalNum, 0xA, 0, 0x10, RGB_WHITE);
    gTasks[taskId].func = Task_Sparkles_SpiralUpward;
    PlaySE(SE_M_MEGA_KICK); // 'Charging up' sound for the sparkles as they spiral upwards
}

static void Task_Sparkles_SpiralUpward(u8 taskId)
{
    if (gTasks[taskId].tTimer < 64)
    {
        if (!(gTasks[taskId].tTimer & 7))
        {
            u8 i;
            for (i = 0; i < 4; i++)
                CreateSparkle_SpiralUpward((gTasks[taskId].tTimer & 120) * 2 + i * 64);
        }
        gTasks[taskId].tTimer++;
    }
    else
    {
        gTasks[taskId].tTimer = 96;
        gTasks[taskId].func = Task_Sparkles_SpiralUpward_End;
    }
}

static void Task_Sparkles_SpiralUpward_End(u8 taskId)
{
    if (gTasks[taskId].tTimer != 0)
        gTasks[taskId].tTimer--;
    else
        DestroyTask(taskId);
}

u8 EvolutionSparkles_ArcDown(void)
{
    return CreateTask(Task_Sparkles_ArcDown_Init, 0);
}

static void Task_Sparkles_ArcDown_Init(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].func = Task_Sparkles_ArcDown;
    PlaySE(SE_M_BUBBLE_BEAM2);
}

static void Task_Sparkles_ArcDown(u8 taskId)
{
    if (gTasks[taskId].tTimer < 96)
    {
        if (gTasks[taskId].tTimer < 6)
        {
            u8 i;
            for (i = 0; i < 9; i++)
                CreateSparkle_ArcDown(i * 16);
        }
        gTasks[taskId].tTimer++;
    }
    else
    {
        gTasks[taskId].func = Task_Sparkles_ArcDown_End;
    }
}

static void Task_Sparkles_ArcDown_End(u8 taskId)
{
    DestroyTask(taskId);
}

u8 EvolutionSparkles_CircleInward(void)
{
    return CreateTask(Task_Sparkles_CircleInward_Init, 0);
}

static void Task_Sparkles_CircleInward_Init(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].func = Task_Sparkles_CircleInward;
    PlaySE(SE_SHINY);
}

static void Task_Sparkles_CircleInward(u8 taskId)
{
    if (gTasks[taskId].tTimer < 48)
    {
        if (gTasks[taskId].tTimer == 0)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                CreateSparkle_CircleInward(i * 16, 4);
        }
        if (gTasks[taskId].tTimer == 32)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                CreateSparkle_CircleInward(i * 16, 8);
        }
        gTasks[taskId].tTimer++;
    }
    else
    {
        gTasks[taskId].func = Task_Sparkles_CircleInward_End;
    }
}

static void Task_Sparkles_CircleInward_End(u8 taskId)
{
    DestroyTask(taskId);
}

#define tSpecies data[2] // Never read

u8 EvolutionSparkles_SprayAndFlash(u16 species)
{
    u8 taskId = CreateTask(Task_Sparkles_SprayAndFlash_Init, 0);
    gTasks[taskId].tSpecies = species;
    return taskId;
}

static void Task_Sparkles_SprayAndFlash_Init(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].tTimer = 0;
    CpuCopy16(&gPlttBufferFaded[BG_PLTT_ID(2)], &gPlttBufferUnfaded[BG_PLTT_ID(2)], 3 * PLTT_SIZE_4BPP);
    BeginNormalPaletteFade(0xFFF9041C, 0, 0, 0x10, RGB_WHITE); // was 0xFFF9001C in R/S
    gTasks[taskId].func = Task_Sparkles_SprayAndFlash;
    PlaySE(SE_M_PETAL_DANCE);
}

static void Task_Sparkles_SprayAndFlash(u8 taskId)
{
    if (gTasks[taskId].tTimer < 128)
    {
        u8 i;
        switch (gTasks[taskId].tTimer)
        {
        default:
            if (gTasks[taskId].tTimer < 50)
                CreateSparkle_Spray(Random() & 7);
            break;
        case 0:
            for (i = 0; i < 8; i++)
                CreateSparkle_Spray(i);
            break;
        case 32:
            BeginNormalPaletteFade(0xFFFF041C, 0x10, 0x10, 0, RGB_WHITE); // was 0xFFF9001C in R/S
            break;
        }
        gTasks[taskId].tTimer++;
    }
    else
    {
        gTasks[taskId].func = Task_Sparkles_SprayAndFlash_End;
    }
}

static void Task_Sparkles_SprayAndFlash_End(u8 taskId)
{
    if (!gPaletteFade.active)
        DestroyTask(taskId);
}

// Separate from EvolutionSparkles_SprayAndFlash for difference in fade color
u8 EvolutionSparkles_SprayAndFlash_Trade(u16 species)
{
    u8 taskId = CreateTask(Task_Sparkles_SprayAndFlashTrade_Init, 0);
    gTasks[taskId].tSpecies = species;
    return taskId;
}

static void Task_Sparkles_SprayAndFlashTrade_Init(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].tTimer = 0;
    CpuCopy16(&gPlttBufferFaded[BG_PLTT_ID(2)], &gPlttBufferUnfaded[BG_PLTT_ID(2)], 3 * PLTT_SIZE_4BPP);
    BeginNormalPaletteFade(0xFFF90400, 0, 0, 0x10, RGB_WHITE); // was 0xFFFF0001 in R/S
    gTasks[taskId].func = Task_Sparkles_SprayAndFlashTrade;
    PlaySE(SE_M_PETAL_DANCE);
}

static void Task_Sparkles_SprayAndFlashTrade(u8 taskId)
{
    if (gTasks[taskId].tTimer < 128)
    {
        u8 i;
        switch (gTasks[taskId].tTimer)
        {
        default:
            if (gTasks[taskId].tTimer < 50)
                CreateSparkle_Spray(Random() & 7);
            break;
        case 0:
            for (i = 0; i < 8; i++)
                CreateSparkle_Spray(i);
            break;
        case 32:
            BeginNormalPaletteFade(0xFFFF0400, 0x10, 0x10, 0, RGB_WHITE); // was 0xFFFF0001 in R/S
            break;
        }
        gTasks[taskId].tTimer++;
    }
    else
    {
        gTasks[taskId].func = Task_Sparkles_SprayAndFlash_End;
    }
}

#undef tTimer
#undef tSpecies

static void SpriteCB_EvolutionMonSprite(struct Sprite *sprite)
{

}

#define tPreEvoSpriteId     data[1]
#define tPostEvoSpriteId    data[2]
#define tPreEvoScale        data[3]
#define tPostEvoScale       data[4]
#define tShowingPostEvo     data[5]
#define tScaleSpeed         data[6]
#define tEvoStopped         data[8]

#define MATRIX_PRE_EVO  30
#define MATRIX_POST_EVO 31

#define MON_MAX_SCALE 256
#define MON_MIN_SCALE 16

// Alternately grow/shrink the pre-evolution and post-evolution mon sprites
u8 CycleEvolutionMonSprite(u8 preEvoSpriteId, u8 postEvoSpriteId)
{
    u16 i;
    u16 monPalette[16];
    u8 taskId;
    s32 toDiv;

    for (i = 0; i < ARRAY_COUNT(monPalette); i++)
        monPalette[i] = RGB_WHITE;

    taskId = CreateTask(Task_CycleEvolutionMonSprite_Init, 0);
    gTasks[taskId].tPreEvoSpriteId = preEvoSpriteId;
    gTasks[taskId].tPostEvoSpriteId = postEvoSpriteId;
    gTasks[taskId].tPreEvoScale = MON_MAX_SCALE;
    gTasks[taskId].tPostEvoScale = MON_MIN_SCALE;

    toDiv = 65536;
    SetOamMatrix(MATRIX_PRE_EVO, MON_MAX_SCALE, 0, 0, MON_MAX_SCALE);
    SetOamMatrix(MATRIX_POST_EVO, toDiv / gTasks[taskId].tPostEvoScale, 0, 0, toDiv / gTasks[taskId].tPostEvoScale);

    gSprites[preEvoSpriteId].callback = SpriteCB_EvolutionMonSprite;
    gSprites[preEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[preEvoSpriteId].oam.matrixNum = MATRIX_PRE_EVO;
    gSprites[preEvoSpriteId].invisible = FALSE;
    CpuSet(monPalette, &gPlttBufferFaded[OBJ_PLTT_ID(gSprites[preEvoSpriteId].oam.paletteNum)], 16);

    gSprites[postEvoSpriteId].callback = SpriteCB_EvolutionMonSprite;
    gSprites[postEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[postEvoSpriteId].oam.matrixNum = MATRIX_POST_EVO;
    gSprites[postEvoSpriteId].invisible = FALSE;
    CpuSet(monPalette, &gPlttBufferFaded[OBJ_PLTT_ID(gSprites[postEvoSpriteId].oam.paletteNum)], 16);

    gTasks[taskId].tEvoStopped = FALSE;
    return taskId;
}

static void Task_CycleEvolutionMonSprite_Init(u8 taskId)
{
    gTasks[taskId].tShowingPostEvo = FALSE;
    gTasks[taskId].tScaleSpeed = 8;
    gTasks[taskId].func = Task_CycleEvolutionMonSprite_TryEnd;
}

// Try to end sprite cycling
// If evo hasn't stopped or growth/shrink speed hasn't been maxed out, start another cycle
static void Task_CycleEvolutionMonSprite_TryEnd(u8 taskId)
{
    if (gTasks[taskId].tEvoStopped)
    {
        EndOnPreEvoMon(taskId);
    }
    else if (gTasks[taskId].tScaleSpeed == 128)
    {
        EndOnPostEvoMon(taskId);
    }
    else
    {
        gTasks[taskId].tScaleSpeed += 2;
        gTasks[taskId].tShowingPostEvo ^= 1;
        gTasks[taskId].func = Task_CycleEvolutionMonSprite_UpdateSize;
    }
}

static void Task_CycleEvolutionMonSprite_UpdateSize(u8 taskId)
{
    if (gTasks[taskId].tEvoStopped)
    {
        gTasks[taskId].func = EndOnPreEvoMon;
    }
    else
    {
        u16 oamMatrixArg;
        u8 numSpritesFinished = 0;
        if (!gTasks[taskId].tShowingPostEvo)
        {
            // Set pre-evo sprite growth
            if (gTasks[taskId].tPreEvoScale < MON_MAX_SCALE - gTasks[taskId].tScaleSpeed)
            {
                gTasks[taskId].tPreEvoScale += gTasks[taskId].tScaleSpeed;
            }
            else
            {
                gTasks[taskId].tPreEvoScale = MON_MAX_SCALE;
                numSpritesFinished++;
            }

            // Set post-evo sprite shrink
            if (gTasks[taskId].tPostEvoScale > MON_MIN_SCALE + gTasks[taskId].tScaleSpeed)
            {
                gTasks[taskId].tPostEvoScale  -= gTasks[taskId].tScaleSpeed;
            }
            else
            {
                gTasks[taskId].tPostEvoScale = MON_MIN_SCALE;
                numSpritesFinished++;
            }
        }
        else
        {
            // Set post-evo sprite growth
            if (gTasks[taskId].tPostEvoScale < MON_MAX_SCALE - gTasks[taskId].tScaleSpeed)
            {
                gTasks[taskId].tPostEvoScale += gTasks[taskId].tScaleSpeed;
            }
            else
            {
                gTasks[taskId].tPostEvoScale = MON_MAX_SCALE;
                numSpritesFinished++;
            }

            // Set pre-evo sprite shrink
            if (gTasks[taskId].tPreEvoScale > MON_MIN_SCALE + gTasks[taskId].tScaleSpeed)
            {
                gTasks[taskId].tPreEvoScale  -= gTasks[taskId].tScaleSpeed;
            }
            else
            {
                gTasks[taskId].tPreEvoScale = MON_MIN_SCALE;
                numSpritesFinished++;
            }
        }

        // Grow/shrink pre-evo sprite
        oamMatrixArg = 65536 / gTasks[taskId].tPreEvoScale;
        SetOamMatrix(MATRIX_PRE_EVO, oamMatrixArg, 0, 0, oamMatrixArg);

        // Grow/shrink post-evo sprite
        oamMatrixArg = 65536 / gTasks[taskId].tPostEvoScale;
        SetOamMatrix(MATRIX_POST_EVO, oamMatrixArg, 0, 0, oamMatrixArg);

        // Both sprites have reached their size extreme
        if (numSpritesFinished == 2)
            gTasks[taskId].func = Task_CycleEvolutionMonSprite_TryEnd;
    }
}

static void EndOnPostEvoMon(u8 taskId)
{
    gSprites[gTasks[taskId].tPreEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].tPreEvoSpriteId].oam.matrixNum = 0;
    gSprites[gTasks[taskId].tPreEvoSpriteId].invisible = TRUE;

    gSprites[gTasks[taskId].tPostEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].tPostEvoSpriteId].oam.matrixNum = 0;
    gSprites[gTasks[taskId].tPostEvoSpriteId].invisible = FALSE;

    DestroyTask(taskId);
}

static void EndOnPreEvoMon(u8 taskId)
{
    gSprites[gTasks[taskId].tPreEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].tPreEvoSpriteId].oam.matrixNum = 0;
    gSprites[gTasks[taskId].tPreEvoSpriteId].invisible = FALSE;

    gSprites[gTasks[taskId].tPostEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].tPostEvoSpriteId].oam.matrixNum = 0;
    gSprites[gTasks[taskId].tPostEvoSpriteId].invisible = TRUE;

    DestroyTask(taskId);
}
