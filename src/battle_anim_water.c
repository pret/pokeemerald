#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle.h"
#include "constants/rgb.h"

static void AnimRainDrop(struct Sprite *);
static void AnimRainDrop_Step(struct Sprite *);
static void AnimWaterBubbleProjectile(struct Sprite *);
static void AnimWaterBubbleProjectile_Step1(struct Sprite *);
static void AnimWaterBubbleProjectile_Step2(struct Sprite *);
static void AnimWaterBubbleProjectile_Step3(struct Sprite *);
static void AnimAuroraBeamRings(struct Sprite *);
static void AnimAuroraBeamRings_Step(struct Sprite *);
static void AnimToTargetInSinWave(struct Sprite *);
static void AnimToTargetInSinWave_Step(struct Sprite *);
static void AnimHydroCannonCharge(struct Sprite *);
static void AnimHydroCannonCharge_Step(struct Sprite *);
static void AnimHydroCannonBeam(struct Sprite *);
static void AnimWaterGunDroplet(struct Sprite *);
static void AnimSmallBubblePair(struct Sprite *);
static void AnimSmallBubblePair_Step(struct Sprite *);
static void AnimSmallDriftingBubbles(struct Sprite *);
static void AnimSmallDriftingBubbles_Step(struct Sprite *);
static void AnimSmallWaterOrb(struct Sprite *);
static void AnimWaterSpoutRain(struct Sprite *);
static void AnimWaterSpoutRainHit(struct Sprite *);
static void AnimWaterSportDroplet(struct Sprite *);
static void AnimWaterSportDroplet_Step(struct Sprite *);
static void AnimWaterPulseBubble(struct Sprite *);
static void AnimWaterPulseBubble_Step(struct Sprite *);
static void AnimWaterPulseRingBubble(struct Sprite *);
static void AnimWaterPulseRing_Step(struct Sprite *);
static void AnimTask_RotateAuroraRingColors_Step(u8);
static void AnimTask_RunSinAnimTimer(u8);
static void AnimTask_CreateSurfWave_Step1(u8);
static void AnimTask_CreateSurfWave_Step2(u8);
static void AnimTask_SurfWaveScanlineEffect(u8);
static void AnimTask_WaterSpoutLaunch_Step(u8);
static void AnimTask_WaterSpoutRain_Step(u8);
static u8 GetWaterSpoutPowerForAnim(void);
static void CreateWaterSpoutLaunchDroplets(struct Task *, u8);
static void CreateWaterSpoutRainDroplet(struct Task *, u8);
static void AnimTask_WaterSport_Step(u8);
static void CreateWaterSportDroplet(struct Task *);
static void CreateWaterPulseRingBubbles(struct Sprite *, int, int);

static const u8 sUnusedWater_Gfx[] = INCBIN_U8("graphics/battle_anims/unused/water_gfx.4bpp");
static const u8 sUnusedWater[] = INCBIN_U8("graphics/battle_anims/unused/water.bin");

static const union AnimCmd sAnim_RainDrop[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 6),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(40, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_RainDrop[] =
{
    sAnim_RainDrop,
};

const struct SpriteTemplate gRainDropSpriteTemplate =
{
    .tileTag = ANIM_TAG_RAIN_DROPS,
    .paletteTag = ANIM_TAG_RAIN_DROPS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = sAnims_RainDrop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRainDrop,
};

static const union AffineAnimCmd sAffineAnim_WaterBubbleProjectile[] =
{
    AFFINEANIMCMD_FRAME(0xFFFB, 0xFFFB, 0, 10),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sAffineAnims_WaterBubbleProjectile[] =
{
    sAffineAnim_WaterBubbleProjectile,
};

static const union AnimCmd sAnim_WaterBubbleProjectile[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_WaterBubbleProjectile[] =
{
    sAnim_WaterBubbleProjectile,
};

const struct SpriteTemplate gWaterBubbleProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = sAnims_WaterBubbleProjectile,
    .images = NULL,
    .affineAnims = sAffineAnims_WaterBubbleProjectile,
    .callback = AnimWaterBubbleProjectile,
};

static const union AnimCmd sAnim_AuroraBeamRing_0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AuroraBeamRing_1[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_AuroraBeamRing[] =
{
    sAnim_AuroraBeamRing_0,
    sAnim_AuroraBeamRing_1,
};

static const union AffineAnimCmd sAffineAnim_AuroraBeamRing[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x60, 0x60, 0, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_AuroraBeamRing[] =
{
    sAffineAnim_AuroraBeamRing,
};

const struct SpriteTemplate gAuroraBeamRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_RAINBOW_RINGS,
    .paletteTag = ANIM_TAG_RAINBOW_RINGS,
    .oam = &gOamData_AffineDouble_ObjNormal_8x16,
    .anims = sAnims_AuroraBeamRing,
    .images = NULL,
    .affineAnims = sAffineAnims_AuroraBeamRing,
    .callback = AnimAuroraBeamRings,
};

static const union AnimCmd sAnim_WaterMudOrb[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gAnims_WaterMudOrb[] =
{
    sAnim_WaterMudOrb,
};

const struct SpriteTemplate gHydroPumpOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

const struct SpriteTemplate gMudShotOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_BROWN_ORB,
    .paletteTag = ANIM_TAG_BROWN_ORB,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

const struct SpriteTemplate gSignalBeamRedOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_GLOWY_RED_ORB,
    .paletteTag = ANIM_TAG_GLOWY_RED_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

const struct SpriteTemplate gSignalBeamGreenOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .paletteTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

static const union AnimCmd sAnim_FlamethrowerFlame[] =
{
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_FlamethrowerFlame[] =
{
    sAnim_FlamethrowerFlame,
};

const struct SpriteTemplate gFlamethrowerFlameSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

const struct SpriteTemplate gPsywaveRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_RING,
    .paletteTag = ANIM_TAG_BLUE_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = AnimToTargetInSinWave,
};

static const union AffineAnimCmd sAffineAnim_HydroCannonCharge[] =
{
    AFFINEANIMCMD_FRAME(0x3, 0x3, 10, 50),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFEC, 0xFFEC, -10, 20),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_HydroCannonBeam[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_HydroCannonCharge[] =
{
    sAffineAnim_HydroCannonCharge,
};

static const union AffineAnimCmd *const sAffineAnims_HydroCannonBeam[] =
{
    sAffineAnim_HydroCannonBeam,
};

const struct SpriteTemplate gHydroCannonChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = sAffineAnims_HydroCannonCharge,
    .callback = AnimHydroCannonCharge,
};

const struct SpriteTemplate gHydroCannonBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = sAffineAnims_HydroCannonBeam,
    .callback = AnimHydroCannonBeam,
};

static const union AnimCmd sAnim_WaterBubble[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WaterGunDroplet[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_WaterBubble[] =
{
    sAnim_WaterBubble,
};

static const union AnimCmd *const sAnims_WaterGunDroplet[] =
{
    sAnim_WaterGunDroplet,
};

const struct SpriteTemplate gWaterGunProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubble,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile,
};

const struct SpriteTemplate gWaterGunDropletSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = sAnims_WaterGunDroplet,
    .images = NULL,
    .affineAnims = gAffineAnims_Droplet,
    .callback = AnimWaterGunDroplet,
};

const struct SpriteTemplate gSmallBubblePairSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS, // ice_crystals_4, which are bubbles
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_SmallBubblePair,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair,
};

const struct SpriteTemplate gSmallDriftingBubblesSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallDriftingBubbles,
};

// Used by Water Spout / Water Sport
const struct SpriteTemplate gSmallWaterOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .paletteTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallWaterOrb,
};

static const union AnimCmd sAnim_WaterPulseBubble_0[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WaterPulseBubble_1[] =
{
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WeatherBallWaterDown[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_WaterPulseBubble[] =
{
    sAnim_WaterPulseBubble_0,
    sAnim_WaterPulseBubble_1,
};

static const union AnimCmd *const sAnims_WeatherBallWaterDown[] =
{
    sAnim_WeatherBallWaterDown,
};

static const union AffineAnimCmd sAffineAnim_WaterPulseRingBubble_0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_WaterPulseRingBubble_1[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_WeatherBallWaterDown[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_WaterPulseRingBubble[] =
{
    sAffineAnim_WaterPulseRingBubble_0,
    sAffineAnim_WaterPulseRingBubble_1,
};

static const union AffineAnimCmd *const sAffineAnims_WeatherBallWaterDown[] =
{
    sAffineAnim_WeatherBallWaterDown,
};

const struct SpriteTemplate gWaterPulseBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = sAnims_WaterPulseBubble,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWaterPulseBubble,
};

const struct SpriteTemplate gWaterPulseRingBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjNormal_8x8,
    .anims = sAnims_WaterPulseBubble,
    .images = NULL,
    .affineAnims = sAffineAnims_WaterPulseRingBubble,
    .callback = AnimWaterPulseRingBubble,
};

const struct SpriteTemplate gWeatherBallWaterDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = sAnims_WeatherBallWaterDown,
    .images = NULL,
    .affineAnims = sAffineAnims_WeatherBallWaterDown,
    .callback = AnimWeatherBallDown,
};

void AnimTask_CreateRaindrops(u8 taskId)
{
    u8 x, y;

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[1] = gBattleAnimArgs[0];
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
    }
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] % gTasks[taskId].data[2] == 1)
    {
        x = Random2() % DISPLAY_WIDTH;
        y = Random2() % (DISPLAY_HEIGHT / 2);
        CreateSprite(&gRainDropSpriteTemplate, x, y, 4);
    }
    if (gTasks[taskId].data[0] == gTasks[taskId].data[3])
        DestroyAnimVisualTask(taskId);
}

static void AnimRainDrop(struct Sprite *sprite)
{
    sprite->callback = AnimRainDrop_Step;
}

static void AnimRainDrop_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] <= 13)
    {
        sprite->x2++;
        sprite->y2 += 4;
    }
    if (sprite->animEnded)
        DestroySprite(sprite);
}

// For water bubbles that move to a dest, as in Bubble/Bubblebeam
static void AnimWaterBubbleProjectile(struct Sprite *sprite)
{
    u8 spriteId;

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) - gBattleAnimArgs[0];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];
        sprite->animPaused = TRUE;
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];
        sprite->animPaused = TRUE;
    }
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[6];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    spriteId = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    sprite->data[5] = spriteId;
    sprite->x -= Sin((u8)gBattleAnimArgs[4], gBattleAnimArgs[2]);
    sprite->y -= Cos((u8)gBattleAnimArgs[4], gBattleAnimArgs[3]);
    gSprites[spriteId].data[0] = gBattleAnimArgs[2];
    gSprites[spriteId].data[1] = gBattleAnimArgs[3];
    gSprites[spriteId].data[2] = gBattleAnimArgs[5];
    gSprites[spriteId].data[3] = (u8)gBattleAnimArgs[4] * 256;
    gSprites[spriteId].data[4] = gBattleAnimArgs[6];
    sprite->callback = AnimWaterBubbleProjectile_Step1;
    sprite->callback(sprite);
}

static void AnimWaterBubbleProjectile_Step1(struct Sprite *sprite)
{
    u8 otherSpriteId = sprite->data[5];
    u8 timer = gSprites[otherSpriteId].data[4];
    u16 trigIndex = gSprites[otherSpriteId].data[3];

    sprite->data[0] = 1;
    AnimTranslateLinear(sprite);
    sprite->x2 += Sin(trigIndex >> 8, gSprites[otherSpriteId].data[0]);
    sprite->y2 += Cos(trigIndex >> 8, gSprites[otherSpriteId].data[1]);
    gSprites[otherSpriteId].data[3] = trigIndex + gSprites[otherSpriteId].data[2];
    if (--timer != 0)
    {
        gSprites[otherSpriteId].data[4] = timer;
    }
    else
    {
        sprite->callback = AnimWaterBubbleProjectile_Step2;
        DestroySprite(&gSprites[otherSpriteId]);
    }
}

static void AnimWaterBubbleProjectile_Step2(struct Sprite *sprite)
{
    sprite->animPaused = FALSE;
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, AnimWaterBubbleProjectile_Step3);
}

static void AnimWaterBubbleProjectile_Step3(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

static void AnimAuroraBeamRings(struct Sprite *sprite)
{
    s16 unkArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        unkArg = -gBattleAnimArgs[2];
    else
        unkArg = gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + unkArg;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimAuroraBeamRings_Step;
    sprite->affineAnimPaused = TRUE;
    sprite->callback(sprite);
}

static void AnimAuroraBeamRings_Step(struct Sprite *sprite)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        StartSpriteAnim(sprite, 1);
        sprite->affineAnimPaused = FALSE;
    }
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
}

// Updates the palette on the rainbow rings used in Aurora Beam to make them appear to be rotating counterclockwise
void AnimTask_RotateAuroraRingColors(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[2] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_RAINBOW_RINGS));
    gTasks[taskId].func = AnimTask_RotateAuroraRingColors_Step;
}

static void AnimTask_RotateAuroraRingColors_Step(u8 taskId)
{
    int i;
    u16 palIndex;

    if (++gTasks[taskId].data[10] == 3)
    {
        u16 rgbBuffer;
        gTasks[taskId].data[10] = 0;
        palIndex = gTasks[taskId].data[2] + 1;
        rgbBuffer = gPlttBufferFaded[palIndex];
        for (i = 1; i < 8; i++)
            gPlttBufferFaded[palIndex + i - 1] = gPlttBufferFaded[palIndex + i];
        gPlttBufferFaded[palIndex + 7] = rgbBuffer;
    }
    if (++gTasks[taskId].data[11] == gTasks[taskId].data[0])
        DestroyAnimVisualTask(taskId);
}

// For animating undulating beam attacks (e.g. Flamethrower, Hydro Pump, Signal Beam)
static void AnimToTargetInSinWave(struct Sprite *sprite)
{
    u16 retArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 30;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0xD200 / sprite->data[0];
    sprite->data[7] = gBattleAnimArgs[3];
    retArg = gBattleAnimArgs[7];
    if (gBattleAnimArgs[7] > 127)
    {
        sprite->data[6] = (retArg - 127) * 256;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] = retArg * 256;
    }
    sprite->callback = AnimToTargetInSinWave_Step;
    sprite->callback(sprite);
}

static void AnimToTargetInSinWave_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
    sprite->y2 += Sin(sprite->data[6] >> 8, sprite->data[7]);
    if ((sprite->data[6] + sprite->data[5]) >> 8 > 127)
    {
        sprite->data[6] = 0;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] += sprite->data[5];
    }
}

void AnimTask_StartSinAnimTimer(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gBattleAnimArgs[7] = 0;
    gTasks[taskId].func = AnimTask_RunSinAnimTimer;
}

static void AnimTask_RunSinAnimTimer(u8 taskId)
{
    gBattleAnimArgs[7] = (gBattleAnimArgs[7] + 3) & 0xFF;
    if (--gTasks[taskId].data[0] == 0)
        DestroyAnimVisualTask(taskId);
}

// Flashing blue orbs grow in size near the attacker. First stage of Hydro Cannon
static void AnimHydroCannonCharge(struct Sprite *sprite)
{
    u8 priority;

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    sprite->y2 = -10;
    priority = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    if (!IsContest())
    {
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        {
            sprite->x2 = 10;
            sprite->subpriority = priority + 2;
        }
        else
        {
            sprite->x2 = -10;
            sprite->subpriority = priority - 2;
        }
    }
    else
    {
        sprite->x2 = -10;
        sprite->subpriority = priority + 2;
    }
    sprite->callback = AnimHydroCannonCharge_Step;
}

static void AnimHydroCannonCharge_Step(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        DestroyAnimSprite(sprite);
}

// Flashing blue orbs move from the attacker to the target. Second stage of Hydro Cannon
static void AnimHydroCannonBeam(struct Sprite *sprite)
{
    bool8 animType;
    u8 coordType;
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
    {
        gBattleAnimArgs[0] *= -1;
        if (GetBattlerPosition(gBattleAnimAttacker) == B_POSITION_PLAYER_LEFT || GetBattlerPosition(gBattleAnimAttacker) == B_POSITION_OPPONENT_LEFT)
            gBattleAnimArgs[0] *= -1;
    }
    if ((gBattleAnimArgs[5] & 0xFF00) == 0)
        animType = TRUE;
    else
        animType = FALSE;
    if ((u8)gBattleAnimArgs[5] == 0)
        coordType = BATTLER_COORD_Y_PIC_OFFSET;
    else
        coordType = BATTLER_COORD_Y;
    InitSpritePosToAnimAttacker(sprite, animType);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, coordType) + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Water droplet appears and drips down. Used by Water Gun on impact
static void AnimWaterGunDroplet(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->y + gBattleAnimArgs[4];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimSmallBubblePair(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] != ANIM_ATTACKER)
        InitSpritePosToAnimTarget(sprite, TRUE);
    else
        InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[7] = gBattleAnimArgs[2];
    sprite->callback = AnimSmallBubblePair_Step;
}

static void AnimSmallBubblePair_Step(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 11) & 0xFF;
    sprite->x2 = Sin(sprite->data[0], 4);
    sprite->data[1] += 48;
    sprite->y2 = -(sprite->data[1] >> 8);
    if (--sprite->data[7] == -1)
        DestroyAnimSprite(sprite);
}

void AnimTask_CreateSurfWave(u8 taskId)
{
    struct BattleAnimBgData animBg;
    u8 taskId2;
    u16 *x;
    u16 *y;

    x = &gBattle_BG1_X;
    y = &gBattle_BG1_Y;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 1);
    GetBattleAnimBg1Data(&animBg);
    if (!IsContest())
    {
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            AnimLoadCompressedBgTilemap(animBg.bgId, gBattleAnimBgTilemap_SurfOpponent);
        else
            AnimLoadCompressedBgTilemap(animBg.bgId, gBattleAnimBgTilemap_SurfPlayer);
    }
    else
    {
        AnimLoadCompressedBgTilemapHandleContest(&animBg, gBattleAnimBgTilemap_SurfContest, TRUE);
    }
    AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimBgImage_Surf, animBg.tilesOffset);
    if (gBattleAnimArgs[0] == 0)
        LoadCompressedPalette(gBattleAnimBgPalette_Surf, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
    else
        LoadCompressedPalette(gBattleAnimBackgroundImageMuddyWater_Pal, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
    taskId2 = CreateTask(AnimTask_SurfWaveScanlineEffect, gTasks[taskId].priority + 1);
    gTasks[taskId].data[15] = taskId2;
    gTasks[taskId2].data[0] = 0;
    gTasks[taskId2].data[1] = 0x1000;
    gTasks[taskId2].data[2] = 0x1000;
    if (IsContest())
    {
        *x = -80;
        *y = -48;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    else if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
    {
        *x = -224;
        *y = 256;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = -1;
        gTasks[taskId2].data[3] = 1;
    }
    else
    {
        *x = 0;
        *y = -48;
        gTasks[taskId].data[0] = -2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    SetGpuReg(REG_OFFSET_BG1HOFS, *x);
    SetGpuReg(REG_OFFSET_BG1VOFS, *y);
    if (gTasks[taskId2].data[3] == 0)
    {
        gTasks[taskId2].data[4] = 48;
        gTasks[taskId2].data[5] = 112;
    }
    else
    {
        gTasks[taskId2].data[4] = 0;
        gTasks[taskId2].data[5] = 0;
    }
    gTasks[taskId].data[6] = 1;
    gTasks[taskId].func = AnimTask_CreateSurfWave_Step1;
}

static void AnimTask_CreateSurfWave_Step1(u8 taskId)
{
    struct BattleAnimBgData animBg;
    u8 i;
    u16 rgbBuffer;
    u16 *BGptrX = &gBattle_BG1_X;
    u16 *BGptrY = &gBattle_BG1_Y;

    *BGptrX += gTasks[taskId].data[0];
    *BGptrY += gTasks[taskId].data[1];
    GetBattleAnimBg1Data(&animBg);
    gTasks[taskId].data[2] += gTasks[taskId].data[1];
    if (++gTasks[taskId].data[5] == 4)
    {
        rgbBuffer = gPlttBufferFaded[BG_PLTT_ID(animBg.paletteId) + 7];
        for (i = 6; i != 0; i--)
        {
            gPlttBufferFaded[BG_PLTT_ID(animBg.paletteId) + 1 + i] = gPlttBufferFaded[BG_PLTT_ID(animBg.paletteId) + 1 + i - 1]; // 1 + i - 1 is needed to match for some bizarre reason
        }
        gPlttBufferFaded[BG_PLTT_ID(animBg.paletteId) + 1] = rgbBuffer;
        gTasks[taskId].data[5] = 0;
    }
    if (++gTasks[taskId].data[6] > 1)
    {
        gTasks[taskId].data[6] = 0;
        if (++gTasks[taskId].data[3] <= 13)
        {
            gTasks[gTasks[taskId].data[15]].data[1] = (s16)((gTasks[taskId].data[3]) | ((16 - gTasks[taskId].data[3]) << 8));
            gTasks[taskId].data[4]++;
        }
        if (gTasks[taskId].data[3] > 54)
        {
            gTasks[taskId].data[4]--;
            gTasks[gTasks[taskId].data[15]].data[1] = (s16)((gTasks[taskId].data[4]) | ((16 - gTasks[taskId].data[4]) << 8));
        }
    }
    if (!(gTasks[gTasks[taskId].data[15]].data[1] & 0x1F))
    {
        gTasks[taskId].data[0] = gTasks[gTasks[taskId].data[15]].data[1] & 0x1F;
        gTasks[taskId].func = AnimTask_CreateSurfWave_Step2;
    }
}

static void AnimTask_CreateSurfWave_Step2(u8 taskId)
{
    u16 *BGptrX = &gBattle_BG1_X;
    u16 *BGptrY = &gBattle_BG1_Y;
    if (gTasks[taskId].data[0] == 0)
    {
        ClearBattleAnimBg(1);
        ClearBattleAnimBg(2);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);
        *BGptrX = 0;
        *BGptrY = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        gTasks[gTasks[taskId].data[15]].data[15] = -1;
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimTask_SurfWaveScanlineEffect(u8 taskId)
{
    s16 i;
    struct ScanlineEffectParams params;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];

        if (task->data[4] == 0)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[1];
        else
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];

        params.dmaDest = &REG_BLDALPHA;
        params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
        params.initState = 1;
        params.unused9 = 0;
        ScanlineEffect_SetParams(params);
        task->data[0]++;
        break;
    case 1:
        if (task->data[3] == 0)
        {
            if (--task->data[4] <= 0)
            {
                task->data[4] = 0;
                task->data[0]++;
            }
        }
        else if (++task->data[5] > 111)
        {
            task->data[0]++;
        }

        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        break;
    case 2:
        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];

        if (task->data[15] == -1)
        {
            ScanlineEffect_Stop();
            DestroyTask(taskId);
        }
        break;
    }
}

static void AnimSmallDriftingBubbles(struct Sprite *sprite)
{
    s16 randData;
    s16 randData2;

    sprite->oam.tileNum += 8;
    InitSpritePosToAnimTarget(sprite, TRUE);
    randData = (Random2() & 0xFF) | 256;
    randData2 = (Random2() & 0x1FF);
    if (randData2 > 255)
        randData2 = 256 - randData2;
    sprite->data[1] = randData;
    sprite->data[2] = randData2;
    sprite->callback = AnimSmallDriftingBubbles_Step;
}

static void AnimSmallDriftingBubbles_Step(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    if (sprite->data[1] & 1)
        sprite->x2 = -(sprite->data[3] >> 8);
    else
        sprite->x2 = sprite->data[3] >> 8;
    sprite->y2 = sprite->data[4] >> 8;
    if (++sprite->data[0] == 21)
        DestroyAnimSprite(sprite);
}

void AnimTask_WaterSpoutLaunch(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[5] = gSprites[task->data[15]].y;
    task->data[1] = GetWaterSpoutPowerForAnim();
    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = AnimTask_WaterSpoutLaunch_Step;
}

static void AnimTask_WaterSpoutLaunch_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        PrepareEruptAnimTaskData(task, task->data[15], 0x100, 0x100, 0xE0, 0x200, 32);
        task->data[0]++;
    case 1:
        if (++task->data[3] > 1)
        {
            task->data[3] = 0;
            if (++task->data[4] & 1)
            {
                gSprites[task->data[15]].x2 = 3;
                gSprites[task->data[15]].y++;
            }
            else
            {
                gSprites[task->data[15]].x2 = -3;
            }
        }
        if (UpdateEruptAnimTask(task) == 0)
        {
            SetBattlerSpriteYOffsetFromYScale(task->data[15]);
            gSprites[task->data[15]].x2 = 0;
            task->data[3] = 0;
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[3] > 4)
        {
            PrepareEruptAnimTaskData(task, task->data[15], 0xE0, 0x200, 0x180, 0xE0, 8);
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (UpdateEruptAnimTask(task) == 0)
        {
            task->data[3] = 0;
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 4:
        CreateWaterSpoutLaunchDroplets(task, taskId);
        task->data[0]++;
    case 5:
        if (++task->data[3] > 1)
        {
            task->data[3] = 0;
            if (++task->data[4] & 1)
                gSprites[task->data[15]].y2 += 2;
            else
                gSprites[task->data[15]].y2 -= 2;
            if (task->data[4] == 10)
            {
                PrepareEruptAnimTaskData(task, task->data[15], 0x180, 0xE0, 0x100, 0x100, 8);
                task->data[3] = 0;
                task->data[4] = 0;
                task->data[0]++;
            }
        }
        break;
    case 6:
        gSprites[task->data[15]].y--;
        if (UpdateEruptAnimTask(task) == 0)
        {
            ResetSpriteRotScale(task->data[15]);
            gSprites[task->data[15]].y = task->data[5];
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 7:
        if (task->data[2] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

// Returns a value 0-3 relative to which quarter HP the attacker is in
// A higher number results in more water sprites during the Water Spout animation
static u8 GetWaterSpoutPowerForAnim(void)
{
    u8 i;
    u16 hp;
    u16 maxhp;
    u16 partyIndex;
    struct Pokemon *slot;

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        partyIndex = gBattlerPartyIndexes[gBattleAnimAttacker];
        slot =  &gPlayerParty[partyIndex];
        maxhp = GetMonData(slot, MON_DATA_MAX_HP);
        hp = GetMonData(slot, MON_DATA_HP);
        maxhp /= 4;
    }
    else
    {
        partyIndex = gBattlerPartyIndexes[gBattleAnimAttacker];
        slot =  &gEnemyParty[partyIndex];
        maxhp = GetMonData(slot, MON_DATA_MAX_HP);
        hp = GetMonData(slot, MON_DATA_HP);
        maxhp /= 4;
    }
    for (i = 0; i < 3; i++)
    {
        if (hp < maxhp * (i + 1))
            return i;
    }
    return 3;
}

static void CreateWaterSpoutLaunchDroplets(struct Task *task, u8 taskId)
{
    s16 i;
    s16 attackerCoordX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    s16 attackerCoordY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    s16 trigIndex = 172;
    u8 subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
    s16 increment = 4 - task->data[1];
    u8 spriteId;

    if (increment <= 0)
        increment = 1;
    for (i = 0; i < 20; i += increment)
    {
        spriteId = CreateSprite(&gSmallWaterOrbSpriteTemplate, attackerCoordX, attackerCoordY, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = attackerCoordX * 16;
            gSprites[spriteId].data[3] = attackerCoordY * 16;
            gSprites[spriteId].data[4] = Cos(trigIndex, 64);
            gSprites[spriteId].data[5] = Sin(trigIndex, 64);
            gSprites[spriteId].data[6] = taskId;
            gSprites[spriteId].data[7] = 2;
            if (task->data[2] & 1)
                AnimSmallWaterOrb(&gSprites[spriteId]);
            task->data[2]++;
        }
        trigIndex = (trigIndex + increment * 2);
        trigIndex &= 0xFF;
    }
}

static void AnimSmallWaterOrb(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[4] += (sprite->data[1] % 6) * 3;
        sprite->data[5] += (sprite->data[1] % 3) * 3;
        sprite->data[0]++;
    case 1:
        sprite->data[2] += sprite->data[4];
        sprite->data[3] += sprite->data[5];
        sprite->x = sprite->data[2] >> 4;
        sprite->y = sprite->data[3] >> 4;
        if (sprite->x < -8 || sprite->x > 248 || sprite->y < -8 || sprite->y > 120)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            DestroySprite(sprite);
        }
        break;
    }
}

void AnimTask_WaterSpoutRain(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[1] = GetWaterSpoutPowerForAnim();
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        task->data[4] = 136;
        task->data[6] = 40;
    }
    else
    {
        task->data[4] = 16;
        task->data[6] = 80;
    }
    task->data[5] = 98;
    task->data[7] = task->data[4] + 49;
    task->data[12] = task->data[1] * 5 + 5;
    task->func = AnimTask_WaterSpoutRain_Step;
}

static void AnimTask_WaterSpoutRain_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 taskId2;

    switch (task->data[0])
    {
    case 0:
        if (++task->data[2] > 2)
        {
            task->data[2] = 0;
            CreateWaterSpoutRainDroplet(task, taskId);
        }
        if (task->data[10] != 0 && task->data[13] == 0)
        {
            gBattleAnimArgs[0] = ANIM_TARGET;
            gBattleAnimArgs[1] = 0;
            gBattleAnimArgs[2] = 12;
            taskId2 = CreateTask(AnimTask_HorizontalShake, 80);
            if (taskId2 != TASK_NONE)
            {
                gTasks[taskId2].func(taskId2);
                gAnimVisualTaskCount++;
            }
            gBattleAnimArgs[0] = ANIM_DEF_PARTNER;
            taskId2 = CreateTask(AnimTask_HorizontalShake, 80);
            if (taskId2 != TASK_NONE)
            {
                gTasks[taskId2].func(taskId2);
                gAnimVisualTaskCount++;
            }
            task->data[13] = 1;
        }
        if (task->data[11] >= task->data[12])
            task->data[0]++;
        break;
    case 1:
        if (task->data[9] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateWaterSpoutRainDroplet(struct Task *task, u8 taskId)
{
    u16 yPosArg = ((gSineTable[task->data[8]] + 3) >> 4) + task->data[6];
    u8 spriteId = CreateSprite(&gSmallWaterOrbSpriteTemplate, task->data[7], 0, 0);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].callback = AnimWaterSpoutRain;
        gSprites[spriteId].data[5] = yPosArg;
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 9;
        task->data[9]++;
    }
    task->data[11]++;
    task->data[8] = (task->data[8] + 39) & 0xFF;
    task->data[7] = (ISO_RANDOMIZE2(task->data[7]) % task->data[5]) + task->data[4];
}

static void AnimWaterSpoutRain(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->y += 8;
        if (sprite->y >= sprite->data[5])
        {
            gTasks[sprite->data[6]].data[10] = 1;
            sprite->data[1] = CreateSprite(&gWaterHitSplatSpriteTemplate, sprite->x, sprite->y, 1);
            if (sprite->data[1] != MAX_SPRITES)
            {
                StartSpriteAffineAnim(&gSprites[sprite->data[1]], 3);
                gSprites[sprite->data[1]].data[6] = sprite->data[6];
                gSprites[sprite->data[1]].data[7] = sprite->data[7];
                gSprites[sprite->data[1]].callback = AnimWaterSpoutRainHit;
            }
            DestroySprite(sprite);
        }
    }
}

static void AnimWaterSpoutRainHit(struct Sprite *sprite)
{
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        sprite->invisible ^= 1;
        if (++sprite->data[2] == 12)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            FreeOamMatrix(sprite->oam.matrixNum);
            DestroySprite(sprite);
        }
    }
}

void AnimTask_WaterSport(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[7] = (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER) ? 1 : -1;
    if (IsContest())
        task->data[7] *= -1;
    task->data[5] = task->data[3] + task->data[7] * 8;
    task->data[6] = task->data[4] - task->data[7] * 8;
    task->data[9] = -32;
    task->data[1] = 0;
    task->data[0] = 0;
    task->func = AnimTask_WaterSport_Step;
}

static void AnimTask_WaterSport_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        CreateWaterSportDroplet(task);
        if (task->data[10] != 0)
            task->data[0]++;
        break;
    case 1:
        CreateWaterSportDroplet(task);
        if (++task->data[1] > 16)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        CreateWaterSportDroplet(task);
        task->data[5] += task->data[7] * 6;
        if (!(task->data[5] >= -16 && task->data[5] <= 256))
        {
            if (++task->data[12] > 2)
            {
                task->data[13] = 1;
                task->data[0] = 6;
                task->data[1] = 0;
            }
            else
            {
                task->data[1] = 0;
                task->data[0]++;
            }
        }
        break;
    case 3:
        CreateWaterSportDroplet(task);
        task->data[6] -= task->data[7] * 2;
        if (++task->data[1] > 7)
            task->data[0]++;
        break;
    case 4:
        CreateWaterSportDroplet(task);
        task->data[5] -= task->data[7] * 6;
        if (!(task->data[5] >= -16 && task->data[5] <= 256))
        {
            task->data[12]++;
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 5:
        CreateWaterSportDroplet(task);
        task->data[6] -= task->data[7] * 2;
        if (++task->data[1] > 7)
            task->data[0] = 2;
        break;
    case 6:
        if (task->data[8] == 0)
            task->data[0]++;
        break;
    default:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateWaterSportDroplet(struct Task *task)
{
    u8 spriteId;

    if (++task->data[2] > 1)
    {
        task->data[2] = 0;
        spriteId = CreateSprite(&gSmallWaterOrbSpriteTemplate, task->data[3], task->data[4], 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = 16;
            gSprites[spriteId].data[2] = task->data[5];
            gSprites[spriteId].data[4] = task->data[6];
            gSprites[spriteId].data[5] = task->data[9];
            InitAnimArcTranslation(&gSprites[spriteId]);
            gSprites[spriteId].callback = AnimWaterSportDroplet;
            task->data[8]++;
        }
    }
}

static void AnimWaterSportDroplet(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->data[0] = 6;
        sprite->data[2] = (Random2() & 0x1F) - 16 + sprite->x;
        sprite->data[4] = (Random2() & 0x1F) - 16 + sprite->y;
        sprite->data[5] = ~(Random2() & 7);
        InitAnimArcTranslation(sprite);
        sprite->callback = AnimWaterSportDroplet_Step;
    }
}

static void AnimWaterSportDroplet_Step(struct Sprite *sprite)
{
    u16 i;

    if (TranslateAnimHorizontalArc(sprite))
    {
        for (i = 0; i < NUM_TASKS; i++)
        {
            if (gTasks[i].func == AnimTask_WaterSport_Step)
            {
                gTasks[i].data[10] = 1;
                gTasks[i].data[8]--;
                DestroySprite(sprite);
            }
        }
    }
}

static void AnimWaterPulseBubble(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->callback = AnimWaterPulseBubble_Step;
}

static void AnimWaterPulseBubble_Step(struct Sprite *sprite)
{
    sprite->data[4] -= sprite->data[0];
    sprite->y2 = sprite->data[4] / 10;
    sprite->data[5] = (sprite->data[5] + sprite->data[1]) & 0xFF;
    sprite->x2 = Sin(sprite->data[5], sprite->data[2]);
    if (--sprite->data[3] == 0)
        DestroyAnimSprite(sprite);
}

static void AnimWaterPulseRingBubble(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    sprite->x2 = sprite->data[3] >> 7;
    sprite->y2 = sprite->data[4] >> 7;
    if (--sprite->data[0] == 0)
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void AnimWaterPulseRing(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = AnimWaterPulseRing_Step;
}

static void AnimWaterPulseRing_Step(struct Sprite *sprite)
{
    int xDiff = sprite->data[1] - sprite->x;
    int yDiff = sprite->data[2] - sprite->y;

    sprite->x2 = (sprite->data[0] * xDiff) / sprite->data[3];
    sprite->y2 = (sprite->data[0] * yDiff) / sprite->data[3];
    if (++sprite->data[5] == sprite->data[4])
    {
        sprite->data[5] = 0;
        CreateWaterPulseRingBubbles(sprite, xDiff, yDiff);
    }
    if (sprite->data[3] == sprite->data[0])
        DestroyAnimSprite(sprite);
    sprite->data[0]++;
}

static void CreateWaterPulseRingBubbles(struct Sprite *sprite, int xDiff, int yDiff)
{
    s16 combinedX;
    s16 combinedY;
    s16 i;
    s16 something;
    s16 unusedVar = 1; //unusedVar is needed to match
    s16 randomSomethingY;
    s16 randomSomethingX;
    u8 spriteId;

    something = sprite->data[0] / 2;
    combinedX = sprite->x + sprite->x2;
    combinedY = sprite->y + sprite->y2;
    if (yDiff < 0)
        unusedVar *= -1; //Needed to match
    randomSomethingY = yDiff + (Random2() % 10) - 5;
    randomSomethingX = -xDiff + (Random2() % 10) - 5;

    for (i = 0; i <= 0; i++)
    {
        spriteId = CreateSprite(&gWaterPulseRingBubbleSpriteTemplate, combinedX, combinedY + something, 130);
        gSprites[spriteId].data[0] = 20;
        gSprites[spriteId].data[1] = randomSomethingY;
        gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        if (randomSomethingX < 0)
            gSprites[spriteId].data[2] = -randomSomethingX;
        else
            gSprites[spriteId].data[2] = randomSomethingX;
    }
    for (i = 0; i <= 0; i++)
    {
        spriteId = CreateSprite(&gWaterPulseRingBubbleSpriteTemplate, combinedX, combinedY - something, 130);
        gSprites[spriteId].data[0] = 20;
        gSprites[spriteId].data[1] = randomSomethingY;
        gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        if (randomSomethingX > 0)
            gSprites[spriteId].data[2] = -randomSomethingX;
        else
            gSprites[spriteId].data[2] = randomSomethingX;
    }
}
