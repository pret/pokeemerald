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

static const u32 sLogoCenter_Gfx[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_center.4bpp.lz");
static const u32 sLogoCenter_Tilemap[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_center.bin.lz");
static const u32 sLogoCircles_Gfx[] = INCBIN_U32("graphics/battle_transitions/frontier_logo_circles.4bpp.lz");
static const u16 sLogo_Pal[] = INCBIN_U16("graphics/battle_transitions/frontier_logo_circles.gbapal");

static const struct OamData sOamData_LogoCircles =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

static const TransitionStateFunc sFrontierCirclesMeet_Funcs[] =
{
    Circles_Init,
    CirclesMeet_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesMeet_End
};

static const TransitionStateFunc sFrontierCirclesCross_Funcs[] =
{
    Circles_Init,
    CirclesCross_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesCross_End
};

static const TransitionStateFunc sFrontierCirclesAsymmetricSpiral_Funcs[] =
{
    Circles_Init,
    CirclesAsymmetricSpiral_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesAsymmetricSpiral_End
};

static const TransitionStateFunc sFrontierCirclesSymmetricSpiral_Funcs[] =
{
    Circles_Init,
    CirclesSymmetricSpiral_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesSymmetricSpiral_End
};

static const TransitionStateFunc sFrontierCirclesMeetInSeq_Funcs[] =
{
    Circles_Init,
    CirclesMeetInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesMeetInSeq_End
};

static const TransitionStateFunc sFrontierCirclesCrossInSeq_Funcs[] =
{
    Circles_Init,
    CirclesCrossInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesCrossInSeq_End
};

static const TransitionStateFunc sFrontierCirclesAsymmetricSpiralInSeq_Funcs[] =
{
    Circles_Init,
    CirclesAsymmetricSpiralInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesAsymmetricSpiralInSeq_End
};

static const TransitionStateFunc sFrontierCirclesSymmetricSpiralInSeq_Funcs[] =
{
    Circles_Init,
    CirclesSymmetricSpiralInSeq_CreateSprites,
    WaitForLogoCirclesAnim,
    FadeInCenterLogoCircle,
    CirclesSymmetricSpiralInSeq_End
};

// Task data
#define tState           data[0]
#define tTimer           data[1]
#define tBlend           data[2]
#define tFadeTimer       data[3]
#define tCircle1SpriteId data[4]
#define tCircle2SpriteId data[5]
#define tCircle3SpriteId data[6]

#define sTargetX data[0]
#define sTargetY data[1]

// Sprite data for CreateSlidingLogoCircleSprite
#define sSpeedX  data[2]
#define sSpeedY  data[3]
#define sTimerX  data[4]
#define sTimerY  data[5]
#define sDelayX  data[6]
#define sDelayY  data[7]

// Sprite data for CreateSpiralingLogoCircleSprite
#define sAngle        data[2]
#define sRotateSpeed  data[3]
#define sRadius       data[4]
#define sTargetRadius data[5]
#define sRadiusDelta  data[6]


static void LoadLogoGfx(void)
{
    u16 *tilemap, *tileset;

    GetBg0TilesDst(&tilemap, &tileset);
    LZ77UnCompVram(sLogoCenter_Gfx, tileset);
    LZ77UnCompVram(sLogoCenter_Tilemap, tilemap);
    LoadPalette(sLogo_Pal, BG_PLTT_ID(15), sizeof(sLogo_Pal));
    LoadCompressedSpriteSheet(&sSpriteSheet_LogoCircles);
    LoadSpritePalette(&sSpritePalette_LogoCircles);
}

static u8 CreateSlidingLogoCircleSprite(s16 x, s16 y, u8 delayX, u8 delayY, s8 speedX, s8 speedY, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_LogoCircles, x, y, 0);

    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].sTargetX = 120;
        gSprites[spriteId].sTargetY = 45;
        break;
    case 1:
        gSprites[spriteId].sTargetX = 89;
        gSprites[spriteId].sTargetY = 97;
        break;
    case 2:
        gSprites[spriteId].sTargetX = 151;
        gSprites[spriteId].sTargetY = 97;
        break;
    }

    gSprites[spriteId].sSpeedX = speedX;
    gSprites[spriteId].sSpeedY = speedY;
    gSprites[spriteId].sDelayX = delayX;
    gSprites[spriteId].sDelayY = delayY;
    gSprites[spriteId].sTimerX = 0;
    gSprites[spriteId].sTimerY = 0;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = SpriteCB_LogoCircleSlide;

    return spriteId;
}

static void SpriteCB_LogoCircleSlide(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    if (sprite->x == sTargetX && sprite->y == sTargetY)
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sTimerX == sDelayX)
        {
            sprite->x += sSpeedX;
            sTimerX = 0;
        }
        else
        {
            sTimerX++;
        }

        if (sTimerY == sDelayY)
        {
            sprite->y += sSpeedY;
            sTimerY = 0;
        }
        else
        {
            sTimerY++;
        }
    }
}

static u8 CreateSpiralingLogoCircleSprite(s16 x, s16 y, s16 angle, s16 rotateSpeed, s16 radiusStart, s16 radiusEnd, s16 radiusDelta, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_LogoCircles, x, y, 0);

    // Target coords are set but irrelevant
    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].sTargetX = 120;
        gSprites[spriteId].sTargetY = 45;
        break;
    case 1:
        gSprites[spriteId].sTargetX = 89;
        gSprites[spriteId].sTargetY = 97;
        break;
    case 2:
        gSprites[spriteId].sTargetX = 151;
        gSprites[spriteId].sTargetY = 97;
        break;
    }

    gSprites[spriteId].sAngle = angle;
    gSprites[spriteId].sRotateSpeed = rotateSpeed;
    gSprites[spriteId].sRadius = radiusStart;
    gSprites[spriteId].sTargetRadius = radiusEnd;
    gSprites[spriteId].sRadiusDelta = radiusDelta;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = SpriteCB_LogoCircleSpiral;

    return spriteId;
}

static void SpriteCB_LogoCircleSpiral(struct Sprite *sprite)
{
    sprite->x2 = (Sin2(sprite->sAngle) * sprite->sRadius) >> 12; // div by 4096
    sprite->y2 = (Cos2(sprite->sAngle) * sprite->sRadius) >> 12; // div by 4096

    sprite->sAngle = (sprite->sAngle + sprite->sRotateSpeed) % 360;

    if (sprite->sRadius != sprite->sTargetRadius)
        sprite->sRadius += sprite->sRadiusDelta;
    else
        sprite->callback = SpriteCallbackDummy;
}

static void DestroyLogoCirclesGfx(struct Task *task)
{
    FreeSpriteTilesByTag(PALTAG_LOGO_CIRCLES);
    FreeSpritePaletteByTag(PALTAG_LOGO_CIRCLES);

    DestroySprite(&gSprites[task->tCircle1SpriteId]);
    DestroySprite(&gSprites[task->tCircle2SpriteId]);
    DestroySprite(&gSprites[task->tCircle3SpriteId]);
}

static bool8 IsLogoCirclesAnimFinished(struct Task *task)
{
    if (gSprites[task->tCircle1SpriteId].callback == SpriteCallbackDummy
     && gSprites[task->tCircle2SpriteId].callback == SpriteCallbackDummy
     && gSprites[task->tCircle3SpriteId].callback == SpriteCallbackDummy)
        return TRUE;
    else
        return FALSE;
}

static bool8 Circles_Init(struct Task *task)
{
    if (task->tTimer == 0)
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

        task->tTimer++;
        return FALSE;
    }
    else
    {
        LoadLogoGfx();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0x500, BG_COORD_SUB);

        task->tTimer = 0;
        task->tState++;
        return TRUE;
    }
}

static bool8 FadeInCenterLogoCircle(struct Task *task)
{
    if (task->tBlend == 0)
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

    if (task->tBlend == 16)
    {
        if (task->tFadeTimer == 31)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 0x10, RGB_BLACK);
            task->tState++;
        }
        else
        {
            task->tFadeTimer++;
        }
    }
    else
    {
        u16 blnd;

        task->tBlend++;
        blnd = task->tBlend;
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

void Task_FrontierCirclesMeet(u8 taskId)
{
    while (sFrontierCirclesMeet_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesMeet_CreateSprites(struct Task *task)
{
    task->tCircle1SpriteId = CreateSlidingLogoCircleSprite(120, -51, 0, 0, 0,   2, 0);
    task->tCircle2SpriteId = CreateSlidingLogoCircleSprite(-7,  193, 0, 0, 2,  -2, 1);
    task->tCircle3SpriteId = CreateSlidingLogoCircleSprite(247, 193, 0, 0, -2, -2, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesMeet_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesMeet));
    }

    return FALSE;
}

void Task_FrontierCirclesCross(u8 taskId)
{
    while (sFrontierCirclesCross_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesCross_CreateSprites(struct Task *task)
{
    task->tCircle1SpriteId = CreateSlidingLogoCircleSprite(120, 197, 0, 0, 0, -4, 0);
    task->tCircle2SpriteId = CreateSlidingLogoCircleSprite(241, 59,  0, 1, -4, 2, 1);
    task->tCircle3SpriteId = CreateSlidingLogoCircleSprite(-1,  59,  0, 1, 4,  2, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesCross_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesCross));
    }

    return FALSE;
}

void Task_FrontierCirclesAsymmetricSpiral(u8 taskId)
{
    while (sFrontierCirclesAsymmetricSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesAsymmetricSpiral_CreateSprites(struct Task *task)
{
    task->tCircle1SpriteId = CreateSpiralingLogoCircleSprite(120, 45, 12,  4, 128, 0, -4, 0);
    task->tCircle2SpriteId = CreateSpiralingLogoCircleSprite(89,  97, 252, 4, 128, 0, -4, 1);
    task->tCircle3SpriteId = CreateSpiralingLogoCircleSprite(151, 97, 132, 4, 128, 0, -4, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesAsymmetricSpiral_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesAsymmetricSpiral));
    }

    return FALSE;
}

void Task_FrontierCirclesSymmetricSpiral(u8 taskId)
{
    while (sFrontierCirclesSymmetricSpiral_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesSymmetricSpiral_CreateSprites(struct Task *task)
{
    task->tCircle1SpriteId = CreateSpiralingLogoCircleSprite(120, 80, 284, 8, 131, 35, -3, 0);
    task->tCircle2SpriteId = CreateSpiralingLogoCircleSprite(120, 80, 44,  8, 131, 35, -3, 1);
    task->tCircle3SpriteId = CreateSpiralingLogoCircleSprite(121, 80, 164, 8, 131, 35, -3, 2);

    task->tState++;
    return FALSE;
}

static bool8 CirclesSymmetricSpiral_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesSymmetricSpiral));
    }

    return FALSE;
}

void Task_FrontierCirclesMeetInSeq(u8 taskId)
{
    while (sFrontierCirclesMeetInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesMeetInSeq_CreateSprites(struct Task *task)
{
    if (task->tTimer == 0)
    {
        task->tCircle1SpriteId = CreateSlidingLogoCircleSprite(120, -51, 0, 0, 0, 4,  0);
    }
    else if (task->tTimer == 16)
    {
        task->tCircle2SpriteId = CreateSlidingLogoCircleSprite(-7,  193, 0, 0, 4, -4, 1);
    }
    else if (task->tTimer == 32)
    {
        task->tCircle3SpriteId = CreateSlidingLogoCircleSprite(247, 193, 0, 0, -4, -4, 2);
        task->tState++;
    }

    task->tTimer++;
    return FALSE;
}

static bool8 CirclesMeetInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesMeetInSeq));
    }

    return FALSE;
}

void Task_FrontierCirclesCrossInSeq(u8 taskId)
{
    while (sFrontierCirclesCrossInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesCrossInSeq_CreateSprites(struct Task *task)
{
    if (task->tTimer == 0)
    {
        task->tCircle1SpriteId = CreateSlidingLogoCircleSprite(120, 197, 0, 0, 0, -8,  0);
    }
    else if (task->tTimer == 16)
    {
        task->tCircle2SpriteId = CreateSlidingLogoCircleSprite(241, 78,  0, 0, -8, 1,  1);
    }
    else if (task->tTimer == 32)
    {
        task->tCircle3SpriteId = CreateSlidingLogoCircleSprite(-1,  78,  0, 0, 8,  1,  2);
        task->tState++;
    }

    task->tTimer++;
    return FALSE;
}

static bool8 CirclesCrossInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesCrossInSeq));
    }

    return FALSE;
}

void Task_FrontierCirclesAsymmetricSpiralInSeq(u8 taskId)
{
    while (sFrontierCirclesAsymmetricSpiralInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesAsymmetricSpiralInSeq_CreateSprites(struct Task *task)
{
    if (task->tTimer == 0)
    {
        task->tCircle1SpriteId = CreateSpiralingLogoCircleSprite(120, 45, 12,  4, 128, 0, -4, 0);
    }
    else if (task->tTimer == 16)
    {
        task->tCircle2SpriteId = CreateSpiralingLogoCircleSprite(89,  97, 252, 4, 128, 0, -4, 1);
    }
    else if (task->tTimer == 32)
    {
        task->tCircle3SpriteId = CreateSpiralingLogoCircleSprite(151, 97, 132, 4, 128, 0, -4, 2);
        task->tState++;
    }

    task->tTimer++;
    return FALSE;
}

static bool8 CirclesAsymmetricSpiralInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesAsymmetricSpiralInSeq));
    }

    return FALSE;
}

void Task_FrontierCirclesSymmetricSpiralInSeq(u8 taskId)
{
    while (sFrontierCirclesSymmetricSpiralInSeq_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 CirclesSymmetricSpiralInSeq_CreateSprites(struct Task *task)
{
    if (task->tTimer == 0)
    {
        task->tCircle1SpriteId = CreateSpiralingLogoCircleSprite(120, 80, 284, 8, 131, 35, -3, 0);
    }
    else if (task->tTimer == 16)
    {
        task->tCircle2SpriteId = CreateSpiralingLogoCircleSprite(120, 80, 44,  8, 131, 35, -3, 1);
    }
    else if (task->tTimer == 32)
    {
        task->tCircle3SpriteId = CreateSpiralingLogoCircleSprite(121, 80, 164, 8, 131, 35, -3, 2);
        task->tState++;
    }

    task->tTimer++;
    return FALSE;
}

static bool8 CirclesSymmetricSpiralInSeq_End(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        DestroyLogoCirclesGfx(task);
        DestroyTask(FindTaskIdByFunc(Task_FrontierCirclesSymmetricSpiralInSeq));
    }

    return FALSE;
}
