#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "palette.h"
#include "sound.h"
#include "util.h"
#include "task.h"
#include "trig.h"

static void AnimFireSpiralInward(struct Sprite *);
static void AnimFireSpread(struct Sprite *);
static void AnimFirePlume(struct Sprite *);
static void AnimLargeFlame(struct Sprite *);
static void AnimLargeFlame_Step(struct Sprite *);
static void AnimUnusedSmallEmber(struct Sprite *);
static void AnimUnusedSmallEmber_Step(struct Sprite *);
static void AnimSunlight(struct Sprite *);
static void AnimEmberFlare(struct Sprite *);
static void AnimBurnFlame(struct Sprite *);
static void AnimFireRing(struct Sprite *);
static void AnimFireRing_Step1(struct Sprite *);
static void AnimFireRing_Step2(struct Sprite *);
static void AnimFireRing_Step3(struct Sprite *);
static void UpdateFireRingCircleOffset(struct Sprite *);
static void AnimFireCross(struct Sprite *);
static void AnimFireSpiralOutward(struct Sprite *);
static void AnimFireSpiralOutward_Step1(struct Sprite *);
static void AnimFireSpiralOutward_Step2(struct Sprite *);
static void AnimTask_EruptionLaunchRocks_Step(u8);
static void CreateEruptionLaunchRocks(u8, u8, u8);
static void AnimEruptionLaunchRock(struct Sprite *);
static u16 GetEruptionLaunchRockInitialYPos(u8);
static void InitEruptionLaunchRockCoordData(struct Sprite *, s16, s16);
static void UpdateEruptionLaunchRockPos(struct Sprite *);
static void AnimEruptionFallingRock(struct Sprite *);
static void AnimEruptionFallingRock_Step(struct Sprite *);
static void AnimWillOWispOrb(struct Sprite *);
static void AnimWillOWispOrb_Step(struct Sprite *);
static void AnimWillOWispFire(struct Sprite *);
static void AnimTask_MoveHeatWaveTargets_Step(u8);

static const union AnimCmd sAnim_FireSpiralSpread_0[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FireSpiralSpread_1[] =
{
    ANIMCMD_FRAME(16, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_FireSpiralSpread[] =
{
    sAnim_FireSpiralSpread_0,
    sAnim_FireSpiralSpread_1,
};

const struct SpriteTemplate gFireSpiralInwardSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FireSpiralSpread,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpiralInward,
};

const struct SpriteTemplate gFireSpreadSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FireSpiralSpread,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread,
};

static const union AnimCmd sAnim_LargeFlame[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_FRAME(112, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_LargeFlame[] =
{
    sAnim_LargeFlame,
};

static const union AnimCmd sAnim_FirePlume[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_FirePlume[] =
{
    sAnim_FirePlume,
};

static const union AffineAnimCmd sAffineAnim_LargeFlame[] =
{
    AFFINEANIMCMD_FRAME(0x32, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x0, 0, 7),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_LargeFlame[] =
{
    sAffineAnim_LargeFlame,
};

const struct SpriteTemplate gLargeFlameSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_FIRE,
    .paletteTag = TAG_BATTLE_ANIM_FIRE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnims_LargeFlame,
    .images = NULL,
    .affineAnims = sAffineAnims_LargeFlame,
    .callback = AnimLargeFlame,
};

const struct SpriteTemplate gLargeFlameScatterSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_FIRE,
    .paletteTag = TAG_BATTLE_ANIM_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_LargeFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLargeFlame,
};

const struct SpriteTemplate gFirePlumeSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_FIRE_PLUME,
    .paletteTag = TAG_BATTLE_ANIM_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFirePlume,
};

// Unused
static const struct SpriteTemplate sUnusedEmberFirePlumeSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFirePlume,
};

static const union AnimCmd sAnim_UnusedSmallEmber[] =
{
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_UnusedSmallEmber[] =
{
    sAnim_UnusedSmallEmber,
};

// Unused
static const struct SpriteTemplate sUnusedSmallEmberSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_UnusedSmallEmber,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimUnusedSmallEmber,
};

static const union AffineAnimCmd sAffineAnim_SunlightRay[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0x2, 0x2, 10, 1),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd *const sAffineAnims_SunlightRay[] =
{
    sAffineAnim_SunlightRay,
};

const struct SpriteTemplate gSunlightRaySpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SUNLIGHT,
    .paletteTag = TAG_BATTLE_ANIM_SUNLIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_SunlightRay,
    .callback = AnimSunlight,
};

static const union AnimCmd sAnim_BasicFire[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gAnims_BasicFire[] =
{
    sAnim_BasicFire,
};

const struct SpriteTemplate gEmberSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gEmberFlareSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEmberFlare,
};

const struct SpriteTemplate gBurnFlameSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBurnFlame,
};

const struct SpriteTemplate gFireBlastRingSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireRing,
};

static const union AnimCmd sAnim_FireBlastCross[] =
{
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_FireBlastCross[] =
{
    sAnim_FireBlastCross,
};

static const union AffineAnimCmd sAffineAnim_Unused_0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Unused_1[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0xA0, 0, 0),
    AFFINEANIMCMD_END,
};

// Unused
static const union AffineAnimCmd *const sAffineAnims_Unused[] =
{
    sAffineAnim_Unused_0,
    sAffineAnim_Unused_1,
};

const struct SpriteTemplate gFireBlastCrossSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FireBlastCross,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireCross,
};

const struct SpriteTemplate gFireSpiralOutwardSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gWeatherBallFireDownSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .paletteTag = TAG_BATTLE_ANIM_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWeatherBallDown,
};

const struct SpriteTemplate gEruptionLaunchRockSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_WARM_ROCK,
    .paletteTag = TAG_BATTLE_ANIM_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEruptionLaunchRock,
};

static const s16 sEruptionLaunchRockSpeeds[][2] =
{
    {-2, -5},
    {-1, -1},
    { 3, -6},
    { 4, -2},
    { 2, -8},
    {-5, -5},
    { 4, -7},
};

const struct SpriteTemplate gEruptionFallingRockSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_WARM_ROCK,
    .paletteTag = TAG_BATTLE_ANIM_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEruptionFallingRock,
};

static const union AnimCmd sAnim_WillOWispOrb_0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_WillOWispOrb_1[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WillOWispOrb_2[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_WillOWispOrb_3[] =
{
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_WillOWispOrb[] =
{
    sAnim_WillOWispOrb_0,
    sAnim_WillOWispOrb_1,
    sAnim_WillOWispOrb_2,
    sAnim_WillOWispOrb_3,
};

const struct SpriteTemplate gWillOWispOrbSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_WISP_ORB,
    .paletteTag = TAG_BATTLE_ANIM_WISP_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_WillOWispOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWillOWispOrb,
};

static const union AnimCmd sAnim_WillOWispFire[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_WillOWispFire[] =
{
    sAnim_WillOWispFire,
};

const struct SpriteTemplate gWillOWispFireSpriteTemplate =
{
    .tileTag = TAG_BATTLE_ANIM_WISP_FIRE,
    .paletteTag = TAG_BATTLE_ANIM_WISP_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_WillOWispFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWillOWispFire,
};

// Directions for shaking up/down or left/right in AnimTask_ShakeTargetInPattern
// Only first 10 values are ever accessed.
// First pattern results in larger shakes, second results in faster oscillation
static const s8 sShakeDirsPattern0[16] =
{
    -1, -1, 0, 1, 1, 0, 0, -1, -1, 1, 1, 0, 0, -1, 0, 1,
};

static const s8 sShakeDirsPattern1[16] =
{
    -1, 0, 1, 0, -1, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, 1,
};

// For the first stage of Fire Punch
static void AnimFireSpiralInward(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = 0x3C;
    sprite->data[2] = 0x9;
    sprite->data[3] = 0x1E;
    sprite->data[4] = 0xFE00;

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);

    sprite->callback = TranslateSpriteInGrowingCircle;
    sprite->callback(sprite);
}

// For the impact spread of fire sprites for moves like Blaze Kick or Fire Punch
static void AnimFireSpread(struct Sprite *sprite)
{
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);

    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[3];

    sprite->callback = TranslateSpriteLinearFixedPoint;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimFirePlume(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);

    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[2] = -gBattleAnimArgs[4];
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[2] = gBattleAnimArgs[4];
    }

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = AnimLargeFlame_Step;
}

static void AnimLargeFlame(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[2] = gBattleAnimArgs[4];
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[2] = -gBattleAnimArgs[4];
    }

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = AnimLargeFlame_Step;
}

static void AnimLargeFlame_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] < sprite->data[4])
    {
        sprite->x2 += sprite->data[2];
        sprite->y2 += sprite->data[3];
    }

    if (sprite->data[0] == sprite->data[1])
        DestroySpriteAndMatrix(sprite);
}

static void AnimUnusedSmallEmber(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);

    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->x -= gBattleAnimArgs[0];
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->subpriority = 8;
    }

    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[6];
    sprite->data[5] = 0;

    sprite->callback = AnimUnusedSmallEmber_Step;
}

static void AnimUnusedSmallEmber_Step(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        if(sprite->data[5] > 10000)
            sprite->subpriority = 1;

        sprite->x2 = Sin(sprite->data[0], sprite->data[1] + (sprite->data[5] >> 8));
        sprite->y2 = Cos(sprite->data[0], sprite->data[1] + (sprite->data[5] >> 8));

        sprite->data[0] += sprite->data[2];
        sprite->data[5] += sprite->data[4];

        if (sprite->data[0] > 255)
            sprite->data[0] -= 256;
        else if (sprite->data[0] < 0)
            sprite->data[0] += 256;

        sprite->data[3]--;
    }
    else
    {
        DestroySpriteAndMatrix(sprite);
    }
}

// Sunlight from Sunny Day / sunny weather
static void AnimSunlight(struct Sprite *sprite)
{
    sprite->x = 0;
    sprite->y = 0;
    sprite->data[0] = 60;
    sprite->data[2] = 140;
    sprite->data[4] = 80;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates the secondary effect of MOVE_EMBER, where the flames grow and slide
// horizontally a bit.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x pixel offset
// arg 3: target y pixel offset
// arg 4: duration
// arg 5: ? (todo: something related to which mon the pixel offsets are based on)
// arg 6: ? (todo: something related to which mon the pixel offsets are based on)
static void AnimEmberFlare(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget)
        && (gBattleAnimAttacker == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)
            || gBattleAnimAttacker == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)))
            gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->callback = AnimTravelDiagonally;
    sprite->callback(sprite);
}

static void AnimBurnFlame(struct Sprite *sprite)
{
    gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->callback = AnimTravelDiagonally;
}

// Animates the a fire sprite in the first-half of the MOVE_FIRE_BLAST
// animation.  The fire sprite first moves in a circle around the mon,
// and then it is translated towards the target mon, while still rotating.
// Lastly, it moves in a circle around the target mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wave offset
//void AnimFireRing(struct Sprite *sprite)
void AnimFireRing(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[7] = gBattleAnimArgs[2];
    sprite->data[0] = 0;

    sprite->callback = AnimFireRing_Step1;
}

static void AnimFireRing_Step1(struct Sprite *sprite)
{
    UpdateFireRingCircleOffset(sprite);

    if (++sprite->data[0] == 0x12)
    {
        sprite->data[0] = 0x19;
        sprite->data[1] = sprite->x;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[3] = sprite->y;
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

        InitAnimLinearTranslation(sprite);

        sprite->callback = AnimFireRing_Step2;
    }
}

static void AnimFireRing_Step2(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        sprite->data[0] = 0;

        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->y2 = 0;
        sprite->x2 = 0;

        sprite->callback = AnimFireRing_Step3;
        sprite->callback(sprite);
    }
    else
    {
        sprite->x2 += Sin(sprite->data[7], 28);
        sprite->y2 += Cos(sprite->data[7], 28);

        sprite->data[7] = (sprite->data[7] + 20) & 0xFF;
    }
}

static void AnimFireRing_Step3(struct Sprite *sprite)
{
    UpdateFireRingCircleOffset(sprite);

    if (++sprite->data[0] == 0x1F)
        DestroyAnimSprite(sprite);
}

static void UpdateFireRingCircleOffset(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[7], 28);
    sprite->y2 = Cos(sprite->data[7], 28);

    sprite->data[7] = (sprite->data[7] + 20) & 0xFF;
}

// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
// arg 3: x delta
// arg 4: y delta
// AnimFireCross(struct Sprite *sprite)
static void AnimFireCross(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];

    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);

    sprite->callback = TranslateSpriteLinear;
}

static void AnimFireSpiralOutward(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[3];

    sprite->invisible = TRUE;
    sprite->callback = WaitAnimForDuration;

    StoreSpriteCallbackInData6(sprite, AnimFireSpiralOutward_Step1);
}

static void AnimFireSpiralOutward_Step1(struct Sprite *sprite)
{
    sprite->invisible = FALSE;

    sprite->data[0] = sprite->data[1];
    sprite->data[1] = 0;

    sprite->callback = AnimFireSpiralOutward_Step2;
    sprite->callback(sprite);
}

static void AnimFireSpiralOutward_Step2(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->y2 = Cos(sprite->data[1], sprite->data[2] >> 8);

    sprite->data[1] = (sprite->data[1] + 10) & 0xFF;
    sprite->data[2] += 0xD0;

    if (--sprite->data[0] == -1)
        DestroyAnimSprite(sprite);
}

#define IDX_ACTIVE_SPRITES 6  // Used by the sprite callback to modify the number of active sprites

#define tState            data[0]
#define tTimer1           data[1]
#define tTimer2           data[2]
#define tTimer3           data[3]
#define tAttackerY        data[4]
#define tAttackerSide     data[5]
#define tActiveSprites    data[IDX_ACTIVE_SPRITES]
// data[8]-data[15] used by PrepareEruptAnimTaskData / UpdateEruptAnimTask
#define tAttackerSpriteId data[15]

#define sSpeedDelay       data[0]
#define sLaunchStage      data[1]
#define sX                data[2]
#define sY                data[3]
#define sSpeedX           data[4]
#define sSpeedY           data[5]
#define sTaskId           data[6]
#define sActiveSpritesIdx data[7]

// Animates first stage of Eruption where the attacker squishes and launches rocks away from themself
void AnimTask_EruptionLaunchRocks(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->tAttackerSpriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    task->tState = 0;
    task->tTimer1 = 0;
    task->tTimer2 = 0;
    task->tTimer3 = 0;
    task->tAttackerY = gSprites[task->tAttackerSpriteId].y;
    task->tAttackerSide = GetBattlerSide(gBattleAnimAttacker);
    task->tActiveSprites = 0;

    PrepareBattlerSpriteForRotScale(task->tAttackerSpriteId, ST_OAM_OBJ_NORMAL);

    task->func = AnimTask_EruptionLaunchRocks_Step;
}

static void AnimTask_EruptionLaunchRocks_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        PrepareEruptAnimTaskData(task, task->tAttackerSpriteId, 0x100, 0x100, 0xE0, 0x200, 32);
        task->tState++;
    case 1:
        if (++task->tTimer1 > 1)
        {
            task->tTimer1 = 0;

            if (++task->tTimer2 & 1)
                gSprites[task->tAttackerSpriteId].x2 = 3;
            else
                gSprites[task->tAttackerSpriteId].x2 = -3;
        }

        if (task->tAttackerSide != B_SIDE_PLAYER)
        {
            if (++task->tTimer3 > 4)
            {
                task->tTimer3 = 0;
                gSprites[task->tAttackerSpriteId].y++;
            }
        }

        if(!UpdateEruptAnimTask(task))
        {
            SetBattlerSpriteYOffsetFromYScale(task->tAttackerSpriteId);
            gSprites[task->tAttackerSpriteId].x2 = 0;

            task->tTimer1 = 0;
            task->tTimer2 = 0;
            task->tTimer3 = 0;
            task->tState++;
        }
        break;
    case 2:
        if (++task->tTimer1 > 4)
        {
            if (task->tAttackerSide != B_SIDE_PLAYER)
                PrepareEruptAnimTaskData(task, task->tAttackerSpriteId, 0xE0, 0x200, 0x180, 0xF0, 6);
            else
                PrepareEruptAnimTaskData(task, task->tAttackerSpriteId, 0xE0, 0x200, 0x180, 0xC0, 6);

            task->tTimer1 = 0;
            task->tState++;
        }
        break;
    case 3:
        if (!UpdateEruptAnimTask(task))
        {
            CreateEruptionLaunchRocks(task->tAttackerSpriteId, taskId, IDX_ACTIVE_SPRITES);
            task->tState++;
        }
        break;
    case 4:
        if (++task->tTimer1 > 1)
        {
            task->tTimer1 = 0;

            if (++task->tTimer2 & 1)
                gSprites[task->tAttackerSpriteId].y2 += 3;
            else
                gSprites[task->tAttackerSpriteId].y2 -= 3;
        }

        if (++task->tTimer3 > 24)
        {
            if (task->tAttackerSide != B_SIDE_PLAYER)
                PrepareEruptAnimTaskData(task, task->tAttackerSpriteId, 0x180, 0xF0, 0x100, 0x100, 8);
            else
                PrepareEruptAnimTaskData(task, task->tAttackerSpriteId, 0x180, 0xC0, 0x100, 0x100, 8);

            if (task->tTimer2 & 1)
                gSprites[task->tAttackerSpriteId].y2 -= 3;

            task->tTimer1 = 0;
            task->tTimer2 = 0;
            task->tTimer3 = 0;
            task->tState++;
        }
        break;
    case 5:
        if (task->tAttackerSide != B_SIDE_PLAYER)
            gSprites[task->tAttackerSpriteId].y--;

        if (!UpdateEruptAnimTask(task))
        {
            gSprites[task->tAttackerSpriteId].y = task->tAttackerY;
            ResetSpriteRotScale(task->tAttackerSpriteId);
            task->tTimer2 = 0;
            task->tState++;
        }
        break;
    case 6:
        if (task->tActiveSprites == 0)
            DestroyAnimVisualTask(taskId);
        break;
    default:
        break;
    }
}

static void CreateEruptionLaunchRocks(u8 spriteId, u8 taskId, u8 activeSpritesIdx)
{
    u16 i, j;
    s8 sign;

    u16 y = GetEruptionLaunchRockInitialYPos(spriteId);
    u16 x = gSprites[spriteId].x;

    if(GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        x -= 12;
        sign = 1;
    }
    else
    {
        x += 16;
        sign = -1;
    }

    for (i = 0, j = 0; i <= 6; i++)
    {
        u8 spriteId = CreateSprite(&gEruptionLaunchRockSpriteTemplate, x, y, 2);

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.tileNum += j * 4 + 0x40;

            if (++j >= 5)
                j = 0;

            InitEruptionLaunchRockCoordData(&gSprites[spriteId], sEruptionLaunchRockSpeeds[i][0] * sign, sEruptionLaunchRockSpeeds[i][1]);
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].sActiveSpritesIdx = activeSpritesIdx;

            gTasks[taskId].data[activeSpritesIdx]++;
        }
    }
}

static void AnimEruptionLaunchRock(struct Sprite *sprite)
{
    UpdateEruptionLaunchRockPos(sprite);

    if (sprite->invisible)
    {
        gTasks[sprite->sTaskId].data[sprite->sActiveSpritesIdx]--;
        DestroySprite(sprite);
    }
}

static u16 GetEruptionLaunchRockInitialYPos(u8 spriteId)
{
    s16 y = gSprites[spriteId].y + gSprites[spriteId].y2 + gSprites[spriteId].centerToCornerVecY;

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        y += 74;
    else
        y += 44;

    return y;
}

static void InitEruptionLaunchRockCoordData(struct Sprite *sprite, s16 speedX, s16 speedY)
{
    sprite->sSpeedDelay = 0;
    sprite->sLaunchStage = 0;
    sprite->sX = (u16)sprite->x * 8;
    sprite->sY = (u16)sprite->y * 8;
    sprite->sSpeedX = speedX * 8;
    sprite->sSpeedY = speedY * 8;
}

static void UpdateEruptionLaunchRockPos(struct Sprite *sprite)
{
    int extraLaunchSpeed;
    if (++sprite->sSpeedDelay > 2)
    {
        sprite->sSpeedDelay = 0;
        ++sprite->sLaunchStage;
        extraLaunchSpeed = (u16)sprite->sLaunchStage * (u16)sprite->sLaunchStage;
        sprite->sY += extraLaunchSpeed;
    }

    sprite->sX += sprite->sSpeedX;
    sprite->x = sprite->sX >> 3;
    sprite->sY += sprite->sSpeedY;
    sprite->y = sprite->sY >> 3;

    if (sprite->x < -8 || sprite->x > DISPLAY_WIDTH + 8 || sprite->y < -8 || sprite->y > 120)
        sprite->invisible = TRUE;
}

#undef IDX_ACTIVE_SPRITES
#undef tState
#undef tTimer1
#undef tTimer2
#undef tTimer3
#undef tAttackerY
#undef tAttackerSide
#undef tActiveSprites
#undef tAttackerSpriteId
#undef sSpeedDelay
#undef sLaunchStage
#undef sX
#undef sY
#undef sSpeedX
#undef sSpeedY
#undef sTaskId
#undef sActiveSpritesIdx

#define sState       data[0]
#define sBounceTimer data[1]
#define sBounceDir   data[2]
#define sEndTimer    data[3]
#define sFallDelay   data[6]
#define sTargetY     data[7]

static void AnimEruptionFallingRock(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = gBattleAnimArgs[1];

    sprite->sState = 0;
    sprite->sBounceTimer = 0;
    sprite->sBounceDir = 0;
    sprite->sFallDelay = gBattleAnimArgs[2];
    sprite->sTargetY = gBattleAnimArgs[3];

    sprite->oam.tileNum += gBattleAnimArgs[4] * 16;
    sprite->callback = AnimEruptionFallingRock_Step;
}

static void AnimEruptionFallingRock_Step(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        // Wait to begin falling
        if (sprite->sFallDelay != 0)
        {
            sprite->sFallDelay--;
            return;
        }

        sprite->sState++;
        // fall through
    case 1:
        // Rock is falling
        sprite->y += 8;
        if (sprite->y >= sprite->sTargetY)
        {
            sprite->y = sprite->sTargetY;
            sprite->sState++;
        }
        break;
    case 2:
        // Bounce up and down on landing spot
        if (++sprite->sBounceTimer > 1)
        {
            sprite->sBounceTimer = 0;
            if ((++sprite->sBounceDir & 1) != 0)
                sprite->y2 = -3;
            else
                sprite->y2 = 3;
        }

        if (++sprite->sEndTimer > 16)
            DestroyAnimSprite(sprite);
        break;
    }
}

#undef sState
#undef sBounceTimer
#undef sBounceDir
#undef sEndTimer
#undef sFallDelay
#undef sTargetY

static void AnimWillOWispOrb(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        InitSpritePosToAnimAttacker(sprite, FALSE);
        StartSpriteAnim(sprite, gBattleAnimArgs[2]);
        sprite->data[7] = gBattleAnimArgs[2];

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            sprite->data[4] = 4;
        }
        else
        {
            sprite->data[4] = -4;
        }

        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        sprite->data[0]++;
        break;
    case 1:
        sprite->data[1] += 192;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            sprite->y2 = -(sprite->data[1] >> 8);
        }
        else
        {
            sprite->y2 = sprite->data[1] >> 8;
        }

        sprite->x2 = Sin(sprite->data[2], sprite->data[4]);
        sprite->data[2] = (sprite->data[2] + 4) & 0xFF;

        if (++sprite->data[3] == 1)
        {
            sprite->data[3] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->x2 = Sin(sprite->data[2], sprite->data[4]);
        sprite->data[2] = (sprite->data[2] + 4) & 0xFF;

        if (++sprite->data[3] == 31)
        {
            sprite->x += sprite->x2;
            sprite->y += sprite->y2;
            sprite->y2 = 0;
            sprite->x2 = 0;

            sprite->data[0] = 256;
            sprite->data[1] = sprite->x;
            sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
            sprite->data[3] = sprite->y;
            sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

            InitAnimLinearTranslationWithSpeed(sprite);
            sprite->callback = AnimWillOWispOrb_Step;
        }
        break;
    }
}

static void AnimWillOWispOrb_Step(struct Sprite *sprite)
{
    s16 initialData5;
    s16 newData5;

    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[5], 16);
        initialData5 = sprite->data[5];
        sprite->data[5] = (sprite->data[5] + 4) & 0xFF;
        newData5 = sprite->data[5];

        if ((initialData5 == 0 || initialData5 > 196) && newData5 > 0 && sprite->data[7] == 0)
        {
            PlaySE12WithPanning(SE_M_FLAME_WHEEL, gAnimCustomPanning);
        }
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimWillOWispFire(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->data[1] = gBattleAnimArgs[0];
        sprite->data[0] += 1;
    }

    sprite->data[3] += 0xC0 * 2;
    sprite->data[4] += 0xA0;

    sprite->x2 = Sin(sprite->data[1], sprite->data[3] >> 8);
    sprite->y2 = Cos(sprite->data[1], sprite->data[4] >> 8);

    sprite->data[1] = (sprite->data[1] + 7) & 0xFF;

    if (!IsContest())
    {
        if (sprite->data[1] < 64 || sprite->data[1] > 195)
            sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        else
            sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;
    }
    else
    {
        if (sprite->data[1] < 64 || sprite->data[1] > 195)
            sprite->subpriority = 0x1D;
        else
            sprite->subpriority = 0x1F;
    }

    if (++sprite->data[2] > 0x14)
        sprite->invisible ^= 1;

    if (sprite->data[2] == 0x1E)
        DestroyAnimSprite(sprite);
}

void AnimTask_MoveHeatWaveTargets(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[12] = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER ? 1 : -1;
    task->data[13] = IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)) + 1;
    task->data[14] = GetAnimBattlerSpriteId(ANIM_TARGET);
    task->data[15] = GetAnimBattlerSpriteId(ANIM_DEF_PARTNER);

    task->func = AnimTask_MoveHeatWaveTargets_Step;
}

static void AnimTask_MoveHeatWaveTargets_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
        case 0:
            task->data[10] += task->data[12] * 2;
            if (++task->data[1] >= 2)
            {
                task->data[1] = 0;
                task->data[2]++;
                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].x2 = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 16)
            {
                task->data[9] = 0;
                task->data[0]++;
            }
            break;
        case 1:
            if (++task->data[1] >= 5)
            {
                task->data[1] = 0;
                task->data[2]++;

                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].x2 = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 96)
            {
                task->data[9] = 0;
                task->data[0]++;
            }
            break;
        case 2:
            task->data[10] -= task->data[12] * 2;

            if (++task->data[1] >= 2)
            {
                task->data[1] = 0;
                task->data[2]++;

                if (task->data[2] & 1)
                    task->data[11] = 2;
                else
                    task->data[11] = -2;
            }

            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].x2 = task->data[10] + task->data[11];
            }

            if (++task->data[9] == 16)
            {
                task->data[0]++;
            }
            break;
        case 3:
            for (task->data[3] = 0; task->data[3] < task->data[13]; task->data[3]++)
            {
                gSprites[task->data[task->data[3] + 14]].x2 = 0;
            }

            DestroyAnimVisualTask(taskId);
            break;
    }
}

// Used to add a color mask to the battle background.
// arg 0: opacity
// arg 1: color code
void AnimTask_BlendBackground(u8 taskId)
{
    struct BattleAnimBgData animBg;
    GetBattleAnimBg1Data(&animBg);
    BlendPalette(BG_PLTT_ID(animBg.paletteId), 16, gBattleAnimArgs[0], gBattleAnimArgs[1]);
    DestroyAnimVisualTask(taskId);
}

#define tShakeNum    data[0]
#define tMaxShakes   data[1]
#define tShakeOffset data[2] // Never read, gBattleAnimArgs[1] is used directly instead
#define tVertical    data[3]
#define tPatternId   data[4]

// Shakes target horizontally or vertically tMaxShakes times, following a set pattern of alternations
void AnimTask_ShakeTargetInPattern(u8 taskId)
{
    s8 dir;
    u8 spriteId;

    if (gTasks[taskId].tShakeNum == 0)
    {
        gTasks[taskId].tMaxShakes = gBattleAnimArgs[0];
        gTasks[taskId].tShakeOffset = gBattleAnimArgs[1];
        gTasks[taskId].tVertical = gBattleAnimArgs[2];
        gTasks[taskId].tPatternId = gBattleAnimArgs[3];
    }
    gTasks[taskId].tShakeNum++;

    spriteId = gBattlerSpriteIds[gBattleAnimTarget];

    if (gTasks[taskId].tPatternId == 0)
        dir = sShakeDirsPattern0[gTasks[taskId].tShakeNum % 10];
    else
        dir = sShakeDirsPattern1[gTasks[taskId].tShakeNum % 10];

    if (gTasks[taskId].tVertical == TRUE)
        gSprites[spriteId].y2 = gBattleAnimArgs[1] * dir < 0 ? -(gBattleAnimArgs[1] * dir) : gBattleAnimArgs[1] * dir;
    else
        gSprites[spriteId].x2 = gBattleAnimArgs[1] * dir;

    if (gTasks[taskId].tShakeNum == gTasks[taskId].tMaxShakes)
    {
        gSprites[spriteId].x2 = 0;
        gSprites[spriteId].y2 = 0;
        DestroyAnimVisualTask(taskId);
    }
}
