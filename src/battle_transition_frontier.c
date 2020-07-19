#include "global.h"
#include "sprite.h"
#include "decompress.h"
#include "battle_transition_frontier.h"
#include "battle_transition.h"
#include "task.h"
#include "palette.h"
#include "trig.h"
#include "bg.h"
#include "gpu_regs.h"
#include "constants/rgb.h"

/*
    There are 3 "categories" of Battle Frontier transition
    1. The full logo is used (B_TRANSITION_FRONTIER_LOGO_*)
    2. Small squares with the logo on it are used (B_TRANSITION_FRONTIER_SQUARES_*)
    3. The balls that make up the logo come together to form the full logo (B_TRANSITION_FRONTIER_CIRCLES_*)

    This file handles category 3. Functions for the other two are handled in battle_transition.c
*/

typedef bool8 (*TransitionStateFunc)(struct Task *task);

// this file's functions
static void SpriteCB_LogoCircleSlide(struct Sprite *sprite);
static void SpriteCB_LogoCircleSpiral(struct Sprite *sprite);
static bool8 WaitForLogoCirclesAnim(struct Task *task);
static bool8 FadeInCenterLogoCircle(struct Task *task);
static bool8 Circles_Init(struct Task *task);
static bool8 CirclesMeet_CreateSprites(struct Task *task);
static bool8 CirclesMeet_End(struct Task *task);
static bool8 CirclesCross_CreateSprites(struct Task *task);
static bool8 CirclesCross_End(struct Task *task);
static bool8 CirclesAsymmetricSpiral_CreateSprites(struct Task *task);
static bool8 CirclesAsymmetricSpiral_End(struct Task *task);
static bool8 CirclesSymmetricSpiral_CreateSprites(struct Task *task);
static bool8 CirclesSymmetricSpiral_End(struct Task *task);
static bool8 CirclesMeetInSeq_CreateSprites(struct Task *task);
static bool8 CirclesMeetInSeq_End(struct Task *task);
static bool8 CirclesCrossInSeq_CreateSprites(struct Task *task);
static bool8 CirclesCrossInSeq_End(struct Task *task);
static bool8 CirclesAsymmetricSpiralInSeq_CreateSprites(struct Task *task);
static bool8 CirclesAsymmetricSpiralInSeq_End(struct Task *task);
static bool8 CirclesSymmetricSpiralInSeq_CreateSprites(struct Task *task);
static bool8 CirclesSymmetricSpiralInSeq_End(struct Task *task);

#define PALTAG_LOGO_CIRCLES 0x2E90

// const rom data
static const u32 sLogoCenter_Gfx[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_center.4bpp.lz");
static const u32 sLogoCenter_Tilemap[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_center.bin");
static const u32 sLogoCircles_Gfx[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_circles.4bpp.lz");
static const u16 sLogo_Pal[] = INCBIN_U16("graphics/battle_transitions/frontier_logo_circles.gbapal");

// Unused Empty data.
static const u8 sFiller[0x1C0] = {0};

static const struct OamData sOamData_LogoCircles =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct CompressedSpriteSheet sSpriteSheet_LogoCircles =
{
    .data = sLogoCircles_Gfx,
    .size = 0x1800,
    .tag = PALTAG_LOGO_CIRCLES
};

static const struct SpritePalette sSpritePalette_LogoCircles =
{
    .data = sLogo_Pal,
    .tag = PALTAG_LOGO_CIRCLES
};

static const union AnimCmd sAnim_LogoCircle_Top[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_LogoCircle_Left[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_LogoCircle_Right[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_LogoCircles[] =
{
    sAnim_LogoCircle_Top,
    sAnim_LogoCircle_Left,
    sAnim_LogoCircle_Right
};

static const struct SpriteTemplate sSpriteTemplate_LogoCircles =
{
    .tileTag = PALTAG_LOGO_CIRCLES,
    .paletteTag = PALTAG_LOGO_CIRCLES,
    .oam = &sOamData_LogoCircles,
    .anims = sAnimTable_LogoCircles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const TransitionStateFunc sPhase2_FrontierCirclesMeet_Funcs[] =
{
    Circles_Init,
    CirclesMeet_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesMeet_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesCross_Funcs[] =
{
    Circles_Init,
    CirclesCross_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesCross_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesAsymmetricSpiral_Funcs[] =
{
    Circles_Init,
    CirclesAsymmetricSpiral_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesAsymmetricSpiral_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesSymmetricSpiral_Funcs[] =
{
    Circles_Init,
    CirclesSymmetricSpiral_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesSymmetricSpiral_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesMeetInSeq_Funcs[] =
{
    Circles_Init,
    CirclesMeetInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesMeetInSeq_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesCrossInSeq_Funcs[] =
{
    Circles_Init,
    CirclesCrossInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesCrossInSeq_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesAsymmetricSpiralInSeq_Funcs[] =
{
    Circles_Init,
    CirclesAsymmetricSpiralInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesAsymmetricSpiralInSeq_End
};

static const TransitionStateFunc sPhase2_FrontierCirclesSymmetricSpiralInSeq_Funcs[] =
{
    Circles_Init,
    CirclesSymmetricSpiralInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesSymmetricSpiralInSeq_End
};

// code
static void LoadLogoGfx(void)
{
    u16 *dst1, *dst2;

    GetBg0TilesDst(&dst1, &dst2);
    LZ77UnCompVram(sLogoCenter_Gfx, dst2);
    LZ77UnCompVram(sLogoCenter_Tilemap, dst1);
    LoadPalette(sLogo_Pal, 0xF0, 0x20);
    LoadCompressedSpriteSheet(&sSpriteSheet_LogoCircles);
    LoadSpritePalette(&sSpritePalette_LogoCircles);
}

static u8 CreateSlidingLogoCircleSprite(s16 x, s16 y, u8 arg2, u8 arg3, s8 arg4, s8 arg5, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_LogoCircles, x, y, 0);

    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].data[0] = 120;
        gSprites[spriteId].data[1] = 45;
        break;
    case 1:
        gSprites[spriteId].data[0] = 89;
        gSprites[spriteId].data[1] = 97;
        break;
    case 2:
        gSprites[spriteId].data[0] = 151;
        gSprites[spriteId].data[1] = 97;
        break;
    }

    gSprites[spriteId].data[2] = arg4;
    gSprites[spriteId].data[3] = arg5;
    gSprites[spriteId].data[6] = arg2;
    gSprites[spriteId].data[7] = arg3;
    gSprites[spriteId].data[4] = 0;
    gSprites[spriteId].data[5] = 0;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = SpriteCB_LogoCircleSlide;

    return spriteId;
}

static void SpriteCB_LogoCircleSlide(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    if (sprite->pos1.x == data[0] && sprite->pos1.y == data[1])
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (data[4] == data[6])
        {
            sprite->pos1.x += data[2];
            data[4] = 0;
        }
        else
        {
            data[4]++;
        }

        if (data[5] == data[7])
        {
            sprite->pos1.y += data[3];
            data[5] = 0;
        }
        else
        {
            data[5]++;
        }
    }
}

static u8 CreateSpiralingLogoCircleSprite(s16 x, s16 y, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_LogoCircles, x, y, 0);

    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].data[0] = 120;
        gSprites[spriteId].data[1] = 45;
        break;
    case 1:
        gSprites[spriteId].data[0] = 89;
        gSprites[spriteId].data[1] = 97;
        break;
    case 2:
        gSprites[spriteId].data[0] = 151;
        gSprites[spriteId].data[1] = 97;
        break;
    }

    gSprites[spriteId].data[2] = arg2;
    gSprites[spriteId].data[3] = arg3;
    gSprites[spriteId].data[4] = arg4;
    gSprites[spriteId].data[5] = arg5;
    gSprites[spriteId].data[6] = arg6;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = SpriteCB_LogoCircleSpiral;

    return spriteId;
}

static void SpriteCB_LogoCircleSpiral(struct Sprite *sprite)
{
    sprite->pos2.x = (Sin2(sprite->data[2]) * sprite->data[4]) >> 12; // div by 4096
    sprite->pos2.y = (Cos2(sprite->data[2]) * sprite->data[4]) >> 12; // div by 4096

    sprite->data[2] = (sprite->data[2] + sprite->data[3]) % 360;

    if (sprite->data[4] != sprite->data[5])
        sprite->data[4] += sprite->data[6];
    else
        sprite->callback = SpriteCallbackDummy;
}

#define tState          data[0]

static void DestroyLogoCirclesGfx(struct Task *task)
{
    FreeSpriteTilesByTag(PALTAG_LOGO_CIRCLES);
    FreeSpritePaletteByTag(PALTAG_LOGO_CIRCLES);

    DestroySprite(&gSprites[task->data[4]]);
    DestroySprite(&gSprites[task->data[5]]);
    DestroySprite(&gSprites[task->data[6]]);
}

static bool8 IsLogoCirclesAnimFinished(struct Task *task)
{
    if (gSprites[task->data[4]].callback == SpriteCallbackDummy
        && gSprites[task->data[5]].callback == SpriteCallbackDummy
        && gSprites[task->data[6]].callback == SpriteCallbackDummy)
        return TRUE;
    else
        return FALSE;
}

static bool8 Circles_Init(struct Task *task)
{
    if (task->data[1] == 0)
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

        task->data[1]++;
        return FALSE;
    }
    else
    {
        LoadLogoGfx();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgY(0, 0x500, 2);

        task->data[1] = 0;
        task->tState++;
        return TRUE;
    }
}

static bool8 FadeInCenterLogoCircle(struct Task *task)
{
    if (task->data[2] == 0)
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

    if (task->data[2] == 16)
    {
        if (task->data[3] == 31)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 0x10, RGB_BLACK);
            task->tState++;
        }
        else
        {
            task->data[3]++;
        }
    }
    else
    {
        u16 blnd;

        task->data[2]++;
        blnd = task->data[2];
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(blnd, 16 - blnd));
    }

    return FALSE;
}

static bool8 WaitForLogoCirclesAnim(struct Task *task)
{
    if (IsLogoCirclesAnimFinished(task) == TRUE)
        task->tState++;

    return FALSE;
}

void Phase2Task_FrontierCirclesMeet(u8 taskId)
{
    while (sPhase2_FrontierCirclesMeet_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesMeet_CreateSprites(struct Task *task)
{
    task->data[4] = CreateSlidingLogoCircleSprite(120, -51, 0, 0, 0,   2, 0);
    task->data[5] = CreateSlidingLogoCircleSprite(-7,  193, 0, 0, 2,  -2, 1);
    task->data[6] = CreateSlidingLogoCircleSprite(247, 193, 0, 0, -2, -2, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesMeet_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesMeet));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesCross(u8 taskId)
{
    while (sPhase2_FrontierCirclesCross_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesCross_CreateSprites(struct Task *task)
{
    task->data[4] = CreateSlidingLogoCircleSprite(120, 197, 0, 0, 0, -4, 0);
    task->data[5] = CreateSlidingLogoCircleSprite(241, 59,  0, 1, -4, 2, 1);
    task->data[6] = CreateSlidingLogoCircleSprite(-1,  59,  0, 1, 4,  2, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesCross_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesCross));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesAsymmetricSpiral(u8 taskId)
{
    while (sPhase2_FrontierCirclesAsymmetricSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesAsymmetricSpiral_CreateSprites(struct Task *task)
{
    task->data[4] = CreateSpiralingLogoCircleSprite(120, 45, 12,  4, 128, 0, -4, 0);
    task->data[5] = CreateSpiralingLogoCircleSprite(89,  97, 252, 4, 128, 0, -4, 1);
    task->data[6] = CreateSpiralingLogoCircleSprite(151, 97, 132, 4, 128, 0, -4, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesAsymmetricSpiral_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesAsymmetricSpiral));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesSymmetricSpiral(u8 taskId)
{
    while (sPhase2_FrontierCirclesSymmetricSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesSymmetricSpiral_CreateSprites(struct Task *task)
{
    task->data[4] = CreateSpiralingLogoCircleSprite(120, 80, 284, 8, 131, 35, -3, 0);
    task->data[5] = CreateSpiralingLogoCircleSprite(120, 80, 44,  8, 131, 35, -3, 1);
    task->data[6] = CreateSpiralingLogoCircleSprite(121, 80, 164, 8, 131, 35, -3, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesSymmetricSpiral_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesSymmetricSpiral));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesMeetInSeq(u8 taskId)
{
    while (sPhase2_FrontierCirclesMeetInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesMeetInSeq_CreateSprites(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = CreateSlidingLogoCircleSprite(120, -51, 0, 0, 0, 4,  0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = CreateSlidingLogoCircleSprite(-7,  193, 0, 0, 4, -4, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = CreateSlidingLogoCircleSprite(247, 193, 0, 0, -4, -4, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 CirclesMeetInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesMeetInSeq));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesCrossInSeq(u8 taskId)
{
    while (sPhase2_FrontierCirclesCrossInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesCrossInSeq_CreateSprites(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = CreateSlidingLogoCircleSprite(120, 197, 0, 0, 0, -8,  0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = CreateSlidingLogoCircleSprite(241, 78,  0, 0, -8, 1,  1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = CreateSlidingLogoCircleSprite(-1,  78,  0, 0, 8,  1,  2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 CirclesCrossInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesCrossInSeq));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesAsymmetricSpiralInSeq(u8 taskId)
{
    while (sPhase2_FrontierCirclesAsymmetricSpiralInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesAsymmetricSpiralInSeq_CreateSprites(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = CreateSpiralingLogoCircleSprite(120, 45, 12,  4, 128, 0, -4, 0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = CreateSpiralingLogoCircleSprite(89,  97, 252, 4, 128, 0, -4, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = CreateSpiralingLogoCircleSprite(151, 97, 132, 4, 128, 0, -4, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 CirclesAsymmetricSpiralInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesAsymmetricSpiralInSeq));
    }

    return FALSE;
}

void Phase2Task_FrontierCirclesSymmetricSpiralInSeq(u8 taskId)
{
    while (sPhase2_FrontierCirclesSymmetricSpiralInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesSymmetricSpiralInSeq_CreateSprites(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = CreateSpiralingLogoCircleSprite(120, 80, 284, 8, 131, 35, -3, 0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = CreateSpiralingLogoCircleSprite(120, 80, 44,  8, 131, 35, -3, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = CreateSpiralingLogoCircleSprite(121, 80, 164, 8, 131, 35, -3, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 CirclesSymmetricSpiralInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_FrontierCirclesSymmetricSpiralInSeq));
    }

    return FALSE;
}
