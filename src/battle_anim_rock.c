#include "global.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "sound.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void AnimFallingRock(struct Sprite *);
static void AnimFallingRock_Step(struct Sprite *);
static void AnimRockFragment(struct Sprite *);
static void AnimFlyingSandCrescent(struct Sprite *);
static void AnimRaiseSprite(struct Sprite *);
static void AnimTask_Rollout_Step(u8 taskId);
static void AnimRolloutParticle(struct Sprite *);
static void AnimRockTomb(struct Sprite *);
static void AnimRockTomb_Step(struct Sprite *sprite);
static void AnimRockBlastRock(struct Sprite *);
static void AnimRockScatter(struct Sprite *);
static void AnimRockScatter_Step(struct Sprite *sprite);
static void AnimParticleInVortex(struct Sprite *);
static void AnimParticleInVortex_Step(struct Sprite *sprite);
static void AnimTask_LoadSandstormBackground_Step(u8 taskId);
static void CreateRolloutDirtSprite(struct Task *task);
static u8 GetRolloutCounter(void);

static const union AnimCmd sAnim_FlyingRock_0[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FlyingRock_1[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FlyingRock_2[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_FlyingRock[] =
{
    sAnim_FlyingRock_0,
    sAnim_FlyingRock_1,
    sAnim_FlyingRock_2,
};

const struct SpriteTemplate gFallingRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FlyingRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFallingRock,
};

const struct SpriteTemplate gRockFragmentSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FlyingRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRockFragment,
};

const struct SpriteTemplate gSwirlingDirtSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex,
};

static const union AffineAnimCmd sAffineAnim_Whirlpool[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(0x2, 0xFFFD, 0, 5),
    AFFINEANIMCMD_FRAME(0xFFFE, 0x3, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd *const sAffineAnims_Whirlpool[] =
{
    sAffineAnim_Whirlpool,
};

const struct SpriteTemplate gWhirlpoolSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = sAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gFireSpinSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gFlyingSandCrescentSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLYING_DIRT,
    .paletteTag = ANIM_TAG_FLYING_DIRT,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlyingSandCrescent,
};

static const struct Subsprite sFlyingSandSubsprites[] =
{
    {.x = -16, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 0, .priority = 1},
    {.x =  16, .y = 0, .shape = SPRITE_SHAPE(32x16), .size = SPRITE_SIZE(32x16), .tileOffset = 8, .priority = 1},
};

static const struct SubspriteTable sFlyingSandSubspriteTable[] =
{
    {ARRAY_COUNT(sFlyingSandSubsprites), sFlyingSandSubsprites},
};

static const union AnimCmd sAnim_Rock_Biggest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rock_Bigger[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rock_Big[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rock_Small[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rock_Smaller[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Rock_Smallest[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_BasicRock[] =
{
    sAnim_Rock_Biggest,
    sAnim_Rock_Bigger,
    sAnim_Rock_Big,
    sAnim_Rock_Small,
    sAnim_Rock_Smaller,
    sAnim_Rock_Smallest,
};

const struct SpriteTemplate gAncientPowerRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_BasicRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRaiseSprite,
};

const struct SpriteTemplate gRolloutMudSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRolloutParticle,
};

const struct SpriteTemplate gRolloutRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRolloutParticle,
};

const struct SpriteTemplate gRockTombRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_BasicRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRockTomb,
};

static const union AffineAnimCmd sAffineAnim_BasicRock_0[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 5),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_BasicRock_1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 5, 5),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sAffineAnims_BasicRock[] =
{
    sAffineAnim_BasicRock_0,
    sAffineAnim_BasicRock_1,
};

const struct SpriteTemplate gRockBlastRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnims_BasicRock,
    .images = NULL,
    .affineAnims = sAffineAnims_BasicRock,
    .callback = AnimRockBlastRock,
};

const struct SpriteTemplate gRockScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnims_BasicRock,
    .images = NULL,
    .affineAnims = sAffineAnims_BasicRock,
    .callback = AnimRockScatter,
};

const struct SpriteTemplate gTwisterRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = &sAnims_BasicRock[4],
    .images = NULL,
    .affineAnims = sAffineAnims_BasicRock,
    .callback = AnimMoveTwisterParticle,
};

const struct SpriteTemplate gWeatherBallRockDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = &sAnims_BasicRock[2],
    .images = NULL,
    .affineAnims = sAffineAnims_BasicRock,
    .callback = AnimWeatherBallDown,
};

static void AnimFallingRock(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] != 0)
        SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &sprite->x, &sprite->y);

    sprite->x += gBattleAnimArgs[0];
    sprite->y += 14;

    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    AnimateSprite(sprite);

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 4;
    sprite->data[3] = 16;
    sprite->data[4] = -70;
    sprite->data[5] = gBattleAnimArgs[2];

    StoreSpriteCallbackInData6(sprite, AnimFallingRock_Step);
    sprite->callback = TranslateSpriteInEllipse;
    sprite->callback(sprite);
}

static void AnimFallingRock_Step(struct Sprite *sprite)
{
    sprite->x += sprite->data[5];

    sprite->data[0] = 192;
    sprite->data[1] = sprite->data[5];
    sprite->data[2] = 4;
    sprite->data[3] = 32;
    sprite->data[4] = -24;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInEllipse;
    sprite->callback(sprite);
}

// Animates the rock particles that are shown on the impact for Rock Blast / Rock Smash
static void AnimRockFragment(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[5]);
    AnimateSprite(sprite);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y + gBattleAnimArgs[3];

    InitSpriteDataForLinearTranslation(sprite);
    sprite->data[3] = 0;
    sprite->data[4] = 0;

    sprite->callback = TranslateSpriteLinearFixedPoint;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// Swirls particle in vortex. Used for moves like Fire Spin or Sand Tomb
static void AnimParticleInVortex(struct Sprite *sprite)
{
    if (gBattleAnimArgs[6] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, FALSE);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];

    sprite->callback = AnimParticleInVortex_Step;
}

static void AnimParticleInVortex_Step(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->y2 = -(sprite->data[4] >> 8);
    sprite->x2 = Sin(sprite->data[5], sprite->data[3]);
    sprite->data[5] = (sprite->data[5] + sprite->data[2]) & 0xFF;

    if (--sprite->data[0] == -1)
    {
        DestroyAnimSprite(sprite);
    }
}

#define tBlendTimer     data[10]
#define tBlend          data[11]
#define tFullAlphaTimer data[11] // not a typo; this data field is used for multiple purposes
#define tState          data[12]

void AnimTask_LoadSandstormBackground(u8 taskId)
{
    int var0;
    struct BattleAnimBgData animBg;

    var0 = 0;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);

    if (!IsContest())
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

    GetBattleAnimBg1Data(&animBg);
    AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimBgImage_Sandstorm, animBg.tilesOffset);
    AnimLoadCompressedBgTilemapHandleContest(&animBg, gBattleAnimBgTilemap_Sandstorm, FALSE);
    LoadCompressedPalette(gBattleAnimSpritePal_FlyingDirt, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);

    if (gBattleAnimArgs[0] && GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        var0 = 1;

    gTasks[taskId].data[0] = var0;
    gTasks[taskId].func = AnimTask_LoadSandstormBackground_Step;
}

static void AnimTask_LoadSandstormBackground_Step(u8 taskId)
{
    struct BattleAnimBgData animBg;

    if (gTasks[taskId].data[0] == 0)
        gBattle_BG1_X += -6;
    else
        gBattle_BG1_X += 6;

    gBattle_BG1_Y += -1;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (++gTasks[taskId].tBlendTimer == 4)
        {
            gTasks[taskId].tBlendTimer = 0;
            gTasks[taskId].tBlend++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
            if (gTasks[taskId].tBlend == 7)
            {
                gTasks[taskId].tState++;
                gTasks[taskId].tFullAlphaTimer = 0;
            }
        }
        break;
    case 1:
        if (++gTasks[taskId].tFullAlphaTimer == 101)
        {
            gTasks[taskId].tBlend = 7;
            gTasks[taskId].tState++;
        }
        break;
    case 2:
        if (++gTasks[taskId].tBlendTimer == 4)
        {
            gTasks[taskId].tBlendTimer = 0;
            gTasks[taskId].tBlend--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].tBlend, 16 - gTasks[taskId].tBlend));
            if (gTasks[taskId].tBlend == 0)
            {
                gTasks[taskId].tState++;
                gTasks[taskId].tFullAlphaTimer = 0;
            }
        }
        break;
    case 3:
        GetBattleAnimBg1Data(&animBg);
        ClearBattleAnimBg(animBg.bgId);
        gTasks[taskId].tState++;
        break;
    case 4:
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

#undef tBlendTimer
#undef tBlend
#undef tFullAlphaTimer
#undef tState

// Animates the sprites that fly diagonally across the screen
// in Sandstorm and Heat Wave.

#define sState       data[0]
#define sVelocityX   data[1] // 256ths of a pixel // init'd from gBattleAnimArgs[1]
#define sVelocityY   data[2] // 256ths of a pixel // init'd from gBattleAnimArgs[2]
#define sFractionalX data[3] // 256ths of a pixel
#define sFractionalY data[4] // 256ths of a pixel
#define sMirroredX   data[5] // init'd from gBattleAnimArgs[3]

// The fields named "velocity" are arguably more like "acceleration," 
// and the fields named "fractional" are arguably more like "velocity."
//
// ...is what I WOULD say if the "fractional" fields weren't AND'd with 
// 0xFF after every frame.

static void AnimFlyingSandCrescent(struct Sprite *sprite)
{
    if (sprite->sState == 0)
    {
        if (gBattleAnimArgs[3] != 0 && GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            sprite->x = DISPLAY_WIDTH + 64;
            gBattleAnimArgs[1] = -gBattleAnimArgs[1];
            sprite->sMirroredX = 1;
            sprite->oam.matrixNum = ST_OAM_HFLIP;
        }
        else
        {
            sprite->x = -64;
        }

        sprite->y = gBattleAnimArgs[0];
        SetSubspriteTables(sprite, sFlyingSandSubspriteTable);
        sprite->sVelocityX = gBattleAnimArgs[1];
        sprite->sVelocityY = gBattleAnimArgs[2];
        sprite->sState++;
    }
    else
    {
        sprite->sFractionalX += sprite->sVelocityX;
        sprite->sFractionalY += sprite->sVelocityY;
        sprite->x2 += (sprite->sFractionalX >> 8);
        sprite->y2 += (sprite->sFractionalY >> 8);
        sprite->sFractionalX &= 0xFF;
        sprite->sFractionalY &= 0xFF;

        if (sprite->data[5] == 0)
        {
            if (sprite->x + sprite->x2 > DISPLAY_WIDTH + 32)
            {
                sprite->callback = DestroyAnimSprite;
            }
        }
        else if (sprite->x + sprite->x2 < -32)
        {
            sprite->callback = DestroyAnimSprite;
        }
    }
}

#undef sState
#undef sVelocityX
#undef sVelocityY
#undef sFractionalX
#undef sFractionalY
#undef sMirroredX

// Animates the rising rocks in Ancient Power.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: terminal y offset
// arg 3: duration
// arg 4: sprite size [1,5]
static void AnimRaiseSprite(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    InitSpritePosToAnimAttacker(sprite, FALSE);

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y + gBattleAnimArgs[2];

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimTask_Rollout(u8 taskId)
{
    u16 var0, var1, var2, var3;
    u8 rolloutCounter;
    s16 pan1, pan2;
    struct Task *task;

    task = &gTasks[taskId];

    var0 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    var1 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 24;
    var2 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    var3 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 24;

    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget)
        var3 = var1;

    rolloutCounter = GetRolloutCounter();
    if (rolloutCounter == 1)
        task->data[8] = 32;
    else
        task->data[8] = 48 - (rolloutCounter * 8);

    task->data[0] = 0;
    task->data[11] = 0;
    task->data[9] = 0;
    task->data[12] = 1;
    task->data[10] = (task->data[8] / 8) - 1;
    task->data[2] = var0 * 8;
    task->data[3] = var1 * 8;
    task->data[4] = ((var2 - var0) * 8) / task->data[8];
    task->data[5] = ((var3 - var1) * 8) / task->data[8];
    task->data[6] = 0;
    task->data[7] = 0;

    pan1 = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);
    pan2 = BattleAnimAdjustPanning(SOUND_PAN_TARGET);

    task->data[13] = pan1;
    task->data[14] = (pan2 - pan1) / task->data[8];
    task->data[1] = rolloutCounter;
    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    task->func = AnimTask_Rollout_Step;
}

static void AnimTask_Rollout_Step(u8 taskId)
{
    struct Task *task;

    task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[6] -= task->data[4];
        task->data[7] -= task->data[5];
        gSprites[task->data[15]].x2 = task->data[6] >> 3;
        gSprites[task->data[15]].y2 = task->data[7] >> 3;

        if (++task->data[9] == 10)
        {
            task->data[11] = 20;
            task->data[0]++;
        }

        PlaySE12WithPanning(SE_M_HEADBUTT, task->data[13]);
        break;
    case 1:
        if (--task->data[11] == 0)
            task->data[0]++;
        break;
    case 2:
        if (--task->data[9] != 0)
        {
            task->data[6] += task->data[4];
            task->data[7] += task->data[5];
        }
        else
        {
            task->data[6] = 0;
            task->data[7] = 0;
            task->data[0]++;
        }

        gSprites[task->data[15]].x2 = task->data[6] >> 3;
        gSprites[task->data[15]].y2 = task->data[7] >> 3;
        break;
    case 3:
        task->data[2] += task->data[4];
        task->data[3] += task->data[5];
        if (++task->data[9] >= task->data[10])
        {
            task->data[9] = 0;
            CreateRolloutDirtSprite(task);
            task->data[13] += task->data[14];
            PlaySE12WithPanning(SE_M_DIG, task->data[13]);
        }

        if (--task->data[8] == 0)
        {
            task->data[0]++;
        }
        break;
    case 4:
        if (task->data[11] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateRolloutDirtSprite(struct Task *task)
{
    const struct SpriteTemplate *spriteTemplate;
    int tileOffset;
    u16 x, y;
    u8 spriteId;

    switch (task->data[1])
    {
    case 1:
        spriteTemplate = &gRolloutMudSpriteTemplate;
        tileOffset = 0;
        break;
    case 2:
    case 3:
        spriteTemplate = &gRolloutRockSpriteTemplate;
        tileOffset = 80;
        break;
    case 4:
        spriteTemplate = &gRolloutRockSpriteTemplate;
        tileOffset = 64;
        break;
    case 5:
        spriteTemplate = &gRolloutRockSpriteTemplate;
        tileOffset = 48;
        break;
    default:
        return;
    }

    x = task->data[2] >> 3;
    y = task->data[3] >> 3;
    x += (task->data[12] * 4);

    spriteId = CreateSprite(spriteTemplate, x, y, 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[0] = 18;
        gSprites[spriteId].data[2] = ((task->data[12] * 20) + x) + (task->data[1] * 3);
        gSprites[spriteId].data[4] = y;
        gSprites[spriteId].data[5] = -16 - (task->data[1] * 2);
        gSprites[spriteId].oam.tileNum += tileOffset;

        InitAnimArcTranslation(&gSprites[spriteId]);
        task->data[11]++;
    }

    task->data[12] *= -1;
}

static void AnimRolloutParticle(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        u8 taskId = FindTaskIdByFunc(AnimTask_Rollout_Step);
        if (taskId != TASK_NONE)
            gTasks[taskId].data[11]--;

        DestroySprite(sprite);
    }
}

static u8 GetRolloutCounter(void)
{
    u8 retVal = gAnimDisableStructPtr->rolloutTimerStartValue - gAnimDisableStructPtr->rolloutTimer;
    u8 var0 = retVal - 1;
    if (var0 > 4)
        retVal = 1;

    return retVal;
}

static void AnimRockTomb(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);

    sprite->x2 = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] -= gBattleAnimArgs[2];
    sprite->data[0] = 3;
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = AnimRockTomb_Step;
    sprite->invisible = TRUE;
}

static void AnimRockTomb_Step(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (sprite->data[3] != 0)
    {
        sprite->y2 = sprite->data[2] + sprite->data[3];
        sprite->data[3] += sprite->data[0];
        sprite->data[0]++;
        if (sprite->data[3] > 0)
        {
            sprite->data[3] = 0;
        }
    }
    else
    {
        if (--sprite->data[1] == 0)
            DestroyAnimSprite(sprite);
    }
}

static void AnimRockBlastRock(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        StartSpriteAffineAnim(sprite, 1);

    TranslateAnimSpriteToTargetMonLocation(sprite);
}

static void AnimRockScatter(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[5] = gBattleAnimArgs[2];

    StartSpriteAnim(sprite, gBattleAnimArgs[3]);
    sprite->callback = AnimRockScatter_Step;
}

static void AnimRockScatter_Step(struct Sprite *sprite)
{
    sprite->data[0] += 8;
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];

    sprite->x2 += sprite->data[3] / 40;
    sprite->y2 -= Sin(sprite->data[0], sprite->data[5]);

    if (sprite->data[0] > 140)
        DestroyAnimSprite(sprite);
}

void AnimTask_GetSeismicTossDamageLevel(u8 taskId)
{
    if (gAnimMoveDmg < 33)
        gBattleAnimArgs[ARG_RET_ID] = 0;
    if ((u32)gAnimMoveDmg - 33 < 33)
        gBattleAnimArgs[ARG_RET_ID] = 1;
    if (gAnimMoveDmg > 65)
        gBattleAnimArgs[ARG_RET_ID] = 2;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_MoveSeismicTossBg(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        UpdateAnimBg3ScreenSize(FALSE);
        gTasks[taskId].data[1] = 200;
    }

    gBattle_BG3_Y += gTasks[taskId].data[1] / 10;
    gTasks[taskId].data[1] -= 3;

    if (gTasks[taskId].data[0] == 120)
    {
        UpdateAnimBg3ScreenSize(TRUE);
        DestroyAnimVisualTask(taskId);
    }

    gTasks[taskId].data[0]++;
}

void AnimTask_SeismicTossBgAccelerateDownAtEnd(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        UpdateAnimBg3ScreenSize(FALSE);
        gTasks[taskId].data[0]++;
        gTasks[taskId].data[2] = gBattle_BG3_Y;
    }

    gTasks[taskId].data[1] += 80;
    gTasks[taskId].data[1] &= 0xFF;
    gBattle_BG3_Y = gTasks[taskId].data[2] + Cos(4, gTasks[taskId].data[1]);

    if (gBattleAnimArgs[7] == 0xFFF)
    {
        gBattle_BG3_Y = 0;
        UpdateAnimBg3ScreenSize(TRUE);
        DestroyAnimVisualTask(taskId);
    }
}
