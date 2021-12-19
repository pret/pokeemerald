#include "global.h"
#include "battle_anim.h"
#include "constants/rgb.h"
#include "trig.h"
#include "constants/songs.h"
#include "sound.h"

static void AnimLightning(struct Sprite *);
static void AnimLightning_Step(struct Sprite *);
static void AnimUnusedSpinningFist(struct Sprite *);
static void AnimUnusedSpinningFist_Step(struct Sprite *);
static void AnimUnusedCirclingShock(struct Sprite *);
static void AnimSparkElectricity(struct Sprite *);
static void AnimZapCannonSpark(struct Sprite *);
static void AnimZapCannonSpark_Step(struct Sprite *);
static void AnimThunderboltOrb(struct Sprite *);
static void AnimThunderboltOrb_Step(struct Sprite *);
static void AnimSparkElectricityFlashing(struct Sprite *);
static void AnimSparkElectricityFlashing_Step(struct Sprite *);
static void AnimElectricity(struct Sprite *);
static void AnimTask_ElectricBolt_Step(u8 taskId);
static void AnimElectricBoltSegment(struct Sprite *);
static void AnimThunderWave(struct Sprite *);
static void AnimThunderWave_Step(struct Sprite *);
static void AnimTask_ElectricChargingParticles_Step(u8 taskId);
static void AnimElectricChargingParticles(struct Sprite *);
static void AnimElectricChargingParticles_Step(struct Sprite *);
static void AnimGrowingChargeOrb(struct Sprite *);
static void AnimElectricPuff(struct Sprite *);
static void AnimVoltTackleOrbSlide(struct Sprite *);
static void AnimVoltTackleOrbSlide_Step(struct Sprite *);
static bool8 CreateVoltTackleBolt(struct Task *task, u8 taskId);
static void AnimVoltTackleBolt(struct Sprite *);
static void AnimGrowingShockWaveOrb(struct Sprite *);
static bool8 CreateShockWaveBoltSprite(struct Task *task, u8 taskId);
static void AnimShockWaveProgressingBolt(struct Sprite *);
static bool8 CreateShockWaveLightningSprite(struct Task *task, u8 taskId);
static void AnimShockWaveLightning(struct Sprite *sprite);

static const union AnimCmd sAnim_Lightning[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Lightning[] =
{
    sAnim_Lightning,
};

const struct SpriteTemplate gLightningSpriteTemplate =
{
    .tileTag = ANIM_TAG_LIGHTNING,
    .paletteTag = ANIM_TAG_LIGHTNING,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_Lightning,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLightning,
};

static const union AffineAnimCmd sAffineAnim_UnusedSpinningFist[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -16, 60),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_UnusedSpinningFist[] =
{
    sAffineAnim_UnusedSpinningFist,
};

// Unused
static const struct SpriteTemplate sUnusedSpinningFistSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_UnusedSpinningFist,
    .callback = AnimUnusedSpinningFist,
};

static const union AnimCmd sAnim_UnusedCirclingShock[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_UnusedCirclingShock[] =
{
    sAnim_UnusedCirclingShock,
};

// Unused
static const struct SpriteTemplate sUnusedCirclingShockSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHOCK,
    .paletteTag = ANIM_TAG_SHOCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_UnusedCirclingShock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimUnusedCirclingShock,
};

const struct SpriteTemplate gSparkElectricitySpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparkElectricity,
};

const struct SpriteTemplate gZapCannonBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_BLACK_BALL_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

static const union AffineAnimCmd sAffineAnim_FlashingSpark[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sAffineAnims_FlashingSpark[] =
{
    sAffineAnim_FlashingSpark,
};

const struct SpriteTemplate gZapCannonSparkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

static const union AnimCmd sAnim_ThunderboltOrb[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_ThunderboltOrb[] =
{
    sAnim_ThunderboltOrb,
};

static const union AffineAnimCmd sAffineAnim_ThunderboltOrb[] =
{
    AFFINEANIMCMD_FRAME(0xE8, 0xE8, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 10),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 10),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd *const sAffineAnims_ThunderboltOrb[] =
{
    sAffineAnim_ThunderboltOrb,
};

const struct SpriteTemplate gThunderboltOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnims_ThunderboltOrb,
    .images = NULL,
    .affineAnims = sAffineAnims_ThunderboltOrb,
    .callback = AnimThunderboltOrb,
};

const struct SpriteTemplate gSparkElectricityFlashingSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_FlashingSpark,
    .callback = AnimSparkElectricityFlashing,
};

const struct SpriteTemplate gElectricitySpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricity,
};

const struct SpriteTemplate gElectricBoltSegmentSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricBoltSegment,
};

const struct SpriteTemplate gThunderWaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_H,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThunderWave,
};

static const s8 sElectricChargingParticleCoordOffsets[][2] =
{
    { 58, -60},
    {-56, -36},
    {  8, -56},
    {-16,  56},
    { 58, -10},
    {-58,  10},
    { 48, -18},
    {-8,   56},
    { 16, -56},
    {-58, -42},
    { 58,  30},
    {-48,  40},
    { 12, -48},
    { 48, -12},
    {-56,  18},
    { 48,  48},
};

static const union AnimCmd sAnim_ElectricChargingParticles_0[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ElectricChargingParticles_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_ElectricChargingParticles[] =
{
    sAnim_ElectricChargingParticles_0,
    sAnim_ElectricChargingParticles_1,
};

const struct SpriteTemplate gElectricChargingParticlesSpriteTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = sAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AffineAnimCmd sAffineAnim_GrowingElectricOrb_0[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 60),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_LOOP(10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_GrowingElectricOrb_1[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFFC, 0xFFFC, 0, 5),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 5),
    AFFINEANIMCMD_JUMP(3),
};

static const union AffineAnimCmd sAffineAnim_GrowingElectricOrb_2[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 30),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 30),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_GrowingElectricOrb[] =
{
    sAffineAnim_GrowingElectricOrb_0,
    sAffineAnim_GrowingElectricOrb_1,
    sAffineAnim_GrowingElectricOrb_2,
};

const struct SpriteTemplate gGrowingChargeOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

static const union AnimCmd sAnim_ElectricPuff[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_ElectricPuff[] =
{
    sAnim_ElectricPuff,
};

const struct SpriteTemplate gElectricPuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_ElectricPuff,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricPuff,
};

const struct SpriteTemplate gVoltTackleOrbSlideSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_GrowingElectricOrb,
    .callback = AnimVoltTackleOrbSlide,
};

static const union AnimCmd sAnim_VoltTackleBolt_0[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VoltTackleBolt_1[] =
{
    ANIMCMD_FRAME(2, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VoltTackleBolt_2[] =
{
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VoltTackleBolt_3[] =
{
    ANIMCMD_FRAME(6, 3),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_VoltTackleBolt[] =
{
    sAnim_VoltTackleBolt_0,
    sAnim_VoltTackleBolt_1,
    sAnim_VoltTackleBolt_2,
    sAnim_VoltTackleBolt_3,
};

static const union AffineAnimCmd sAffineAnim_VoltTackleBolt[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_VoltTackleBolt[] =
{
    sAffineAnim_VoltTackleBolt,
};

const struct SpriteTemplate gVoltTackleBoltSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gOamData_AffineDouble_ObjNormal_8x16,
    .anims = sAnims_VoltTackleBolt,
    .images = NULL,
    .affineAnims = sAffineAnims_VoltTackleBolt,
    .callback = AnimVoltTackleBolt,
};

const struct SpriteTemplate gGrowingShockWaveOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb,
};

const struct SpriteTemplate gShockWaveProgressingBoltSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimShockWaveProgressingBolt,
};

static void AnimLightning(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    sprite->callback = AnimLightning_Step;
}

static void AnimLightning_Step(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimUnusedSpinningFist(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->callback = AnimUnusedSpinningFist_Step;
}

static void AnimUnusedSpinningFist_Step(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        DestroySpriteAndMatrix(sprite);
}

static void AnimUnusedCirclingShock(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y -= gBattleAnimArgs[1];
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInCircle;
}

static void AnimSparkElectricity(struct Sprite *sprite)
{
    u8 battler;
    u32 matrixNum;
    s16 sineVal;

    switch (gBattleAnimArgs[4])
    {
    case ANIM_ATTACKER:
        battler = gBattleAnimAttacker;
        break;
    case ANIM_TARGET:
    default:
        battler = gBattleAnimTarget;
        break;
    case ANIM_ATK_PARTNER:
        if (!IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            battler = gBattleAnimAttacker;
        else
            battler = BATTLE_PARTNER(gBattleAnimAttacker);
        break;
    case ANIM_DEF_PARTNER:
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            battler = BATTLE_PARTNER(gBattleAnimTarget);
        else
            battler = gBattleAnimTarget;
        break;
    }

    if (gBattleAnimArgs[5] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);
    }

    sprite->x2 = (gSineTable[gBattleAnimArgs[0]] * gBattleAnimArgs[1]) >> 8;
    sprite->y2 = (gSineTable[gBattleAnimArgs[0] + 64] * gBattleAnimArgs[1]) >> 8;

    if (gBattleAnimArgs[6] & 1)
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;

    matrixNum = sprite->oam.matrixNum;
    sineVal = gSineTable[gBattleAnimArgs[2]];

    gOamMatrices[matrixNum].a = gOamMatrices[matrixNum].d =  gSineTable[gBattleAnimArgs[2] + 64];
    gOamMatrices[matrixNum].b =  sineVal;
    gOamMatrices[matrixNum].c = -sineVal;

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->callback = DestroyAnimSpriteAfterTimer;
}

static void AnimZapCannonSpark(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 1);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = gBattleAnimArgs[2];
    sprite->data[6] = gBattleAnimArgs[5];
    sprite->data[7] = gBattleAnimArgs[4];
    sprite->oam.tileNum += gBattleAnimArgs[6] * 4;
    sprite->callback = AnimZapCannonSpark_Step;
    AnimZapCannonSpark_Step(sprite);
}

static void AnimZapCannonSpark_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[7], sprite->data[5]);
        sprite->y2 += Cos(sprite->data[7], sprite->data[5]);
        sprite->data[7] = (sprite->data[7] + sprite->data[6]) & 0xFF;
        if(!(sprite->data[7] % 3))
            sprite->invisible ^= 1;
    }
    else
        DestroyAnimSprite(sprite);
}

static void AnimThunderboltOrb_Step(struct Sprite *sprite)
{
    if (--sprite->data[5] == -1)
    {
        sprite->invisible ^= 1;
        sprite->data[5] = sprite->data[4];
    }
    if (sprite->data[3]-- <= 0)
        DestroyAnimSprite(sprite);
}

static void AnimThunderboltOrb(struct Sprite *sprite)
{
    if (IsContest() || GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    sprite->data[3] = gBattleAnimArgs[0];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[3];
    sprite->callback = AnimThunderboltOrb_Step;
}

static void AnimSparkElectricityFlashing(struct Sprite *sprite)
{
    u8 battler;

    sprite->data[0] = gBattleAnimArgs[3];
    if (gBattleAnimArgs[7] & 0x8000)
        battler = gBattleAnimTarget;
    else
        battler = gBattleAnimAttacker;

    if (IsContest() || GetBattlerSide(battler) == B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];

    sprite->data[4] = gBattleAnimArgs[7] & 0x7FFF;
    sprite->data[5] = gBattleAnimArgs[2];
    sprite->data[6] = gBattleAnimArgs[5];
    sprite->data[7] = gBattleAnimArgs[4];

    sprite->oam.tileNum += gBattleAnimArgs[6] * 4;
    sprite->callback = AnimSparkElectricityFlashing_Step;
    sprite->callback(sprite);
}

static void AnimSparkElectricityFlashing_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[7], sprite->data[5]);
    sprite->y2 = Cos(sprite->data[7], sprite->data[5]);

    sprite->data[7] = (sprite->data[7] + sprite->data[6]) & 0xFF;
    if (sprite->data[7] % sprite->data[4] == 0)
        sprite->invisible ^= TRUE;

    if (sprite->data[0]-- <= 0)
        DestroyAnimSprite(sprite);
}

// Electricity arcs around the target. Used for Paralysis and various electric move hits
static void AnimElectricity(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->oam.tileNum += gBattleAnimArgs[3] * 4;

    if (gBattleAnimArgs[3] == 1)
        sprite->oam.matrixNum = ST_OAM_HFLIP;
    else if (gBattleAnimArgs[3] == 2)
        sprite->oam.matrixNum = ST_OAM_VFLIP;

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// The vertical falling thunder bolt used in Thunder Wave/Shock/Bolt
void AnimTask_ElectricBolt(u8 taskId)
{
    gTasks[taskId].data[0] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[0];
    gTasks[taskId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[1];
    gTasks[taskId].data[2] = gBattleAnimArgs[2];
    gTasks[taskId].func = AnimTask_ElectricBolt_Step;
}

static void AnimTask_ElectricBolt_Step(u8 taskId)
{
    u16 r8;
    u16 r2;
    s16 r12;
    u8 spriteId = 0;
    u8 r7 = 0;
    u8 sp = gTasks[taskId].data[2];
    s16 x = gTasks[taskId].data[0];
    s16 y = gTasks[taskId].data[1];

    if (!gTasks[taskId].data[2])
    {
        r8 = 0;
        r2 = 1;
        r12 = 16;
    }
    else
    {
        r12 = 16;
        r8 = 8;
        r2 = 4;
    }

    switch (gTasks[taskId].data[10])
    {
    case 0:
        r12 *= 1;
        spriteId = CreateSprite(&gElectricBoltSegmentSpriteTemplate, x, y + r12, 2);
        r7++;
        break;
    case 2:
        r12 *= 2;
        r8 += r2;
        spriteId = CreateSprite(&gElectricBoltSegmentSpriteTemplate, x, y + r12, 2);
        r7++;
        break;
    case 4:
        r12 *= 3;
        r8 += r2 * 2;
        spriteId = CreateSprite(&gElectricBoltSegmentSpriteTemplate, x, y + r12, 2);
        r7++;
        break;
    case 6:
        r12 *= 4;
        r8 += r2 * 3;
        spriteId = CreateSprite(&gElectricBoltSegmentSpriteTemplate, x, y + r12, 2);
        r7++;
        break;
    case 8:
        r12 *= 5;
        spriteId = CreateSprite(&gElectricBoltSegmentSpriteTemplate, x, y + r12, 2);
        r7++;
        break;
    case 10:
        DestroyAnimVisualTask(taskId);
        return;
    }

    if (r7)
    {
        gSprites[spriteId].oam.tileNum += r8;
        gSprites[spriteId].data[0] = sp;
        gSprites[spriteId].callback(&gSprites[spriteId]);
    }

    gTasks[taskId].data[10]++;
}

static void AnimElectricBoltSegment(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->oam.shape = SPRITE_SHAPE(8x16);
        sprite->oam.size = SPRITE_SIZE(8x16);
    }
    else
    {
        sprite->oam.shape = SPRITE_SHAPE(16x16);
        sprite->oam.size = SPRITE_SIZE(16x16);
    }
    if (++sprite->data[1] == 15)
        DestroySprite(sprite);
}

// The horizontal bands of electricity used in Thunder Wave
static void AnimThunderWave(struct Sprite *sprite)
{
    u8 spriteId;

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    spriteId = CreateSprite(&gThunderWaveSpriteTemplate, sprite->x + 32, sprite->y, sprite->subpriority);
    gSprites[spriteId].oam.tileNum += 8;
    gAnimVisualTaskCount++;
    gSprites[spriteId].callback = AnimThunderWave_Step;
    sprite->callback = AnimThunderWave_Step;
}

static void AnimThunderWave_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] == 3)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }

    if (++sprite->data[1] == 51)
        DestroyAnimSprite(sprite);
}

// Animates small electric orbs moving from around the battler inward. For Charge/Shock Wave
void AnimTask_ElectricChargingParticles(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        task->data[15] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        task->data[15] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    task->data[6] = gBattleAnimArgs[1];
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 0;
    task->data[10] = 0;
    task->data[11] = gBattleAnimArgs[3];
    task->data[12] = 0;
    task->data[13] = gBattleAnimArgs[2];
    task->func = AnimTask_ElectricChargingParticles_Step;
}

static void AnimTask_ElectricChargingParticles_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (task->data[6])
    {
        if (++task->data[12] > task->data[13])
        {
            u8 spriteId;
            task->data[12] = 0;
            spriteId = CreateSprite(&gElectricChargingParticlesSpriteTemplate, task->data[14], task->data[15], 2);
            if (spriteId != MAX_SPRITES)
            {
                struct Sprite *sprite = &gSprites[spriteId];
                sprite->x += sElectricChargingParticleCoordOffsets[task->data[9]][0];
                sprite->y += sElectricChargingParticleCoordOffsets[task->data[9]][1];

                sprite->data[0] = 40 - task->data[8] * 5;
                sprite->data[1] = sprite->x;
                sprite->data[2] = task->data[14];
                sprite->data[3] = sprite->y;
                sprite->data[4] = task->data[15];
                sprite->data[5] = taskId;

                InitAnimLinearTranslation(sprite);
                StoreSpriteCallbackInData6(sprite, AnimElectricChargingParticles);
                sprite->callback = RunStoredCallbackWhenAnimEnds;

                if (++task->data[9] > 15)
                    task->data[9] = 0;

                if (++task->data[10] >= task->data[11])
                {
                    task->data[10] = 0;
                    if (task->data[8] <= 5)
                        task->data[8]++;
                }

                task->data[7]++;
                task->data[6]--;
            }
        }
    }
    else if(task->data[7] == 0)
        DestroyAnimVisualTask(taskId);
}

static void AnimElectricChargingParticles_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        gTasks[sprite->data[5]].data[7]--;
        DestroySprite(sprite);
    }
}

static void AnimElectricChargingParticles(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = AnimElectricChargingParticles_Step;
}

static void AnimGrowingChargeOrb(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

// The quick electric burst at the end of Charge / during the Volt Tackle hit
static void AnimElectricPuff(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    sprite->x2 = gBattleAnimArgs[1];
    sprite->y2 = gBattleAnimArgs[2];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

// Creates an orb of electricity that grows then slides off-screen. The attacker slides with it
static void AnimVoltTackleOrbSlide(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[6] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    sprite->data[7] = 16;

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        sprite->data[7] *= -1;

    sprite->callback = AnimVoltTackleOrbSlide_Step;
}

static void AnimVoltTackleOrbSlide_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 40)
            sprite->data[0]++;
        break;
    case 1:
        sprite->x += sprite->data[7];
        gSprites[sprite->data[6]].x2 += sprite->data[7];
        if ((u16)(sprite->x + 80) > 400)
            DestroySpriteAndMatrix(sprite);
    }
}

void AnimTask_VoltTackleAttackerReappear(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        task->data[14] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        {
            task->data[14] = -32;
            task->data[13] = 2;
        }
        else
        {
            task->data[14] = 32;
            task->data[13] = -2;
        }

        gSprites[task->data[15]].x2 = task->data[14];
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            gSprites[task->data[15]].invisible ^= 1;

            if (task->data[14])
            {
                task->data[14] += task->data[13];
                gSprites[task->data[15]].x2 = task->data[14];
            }
            else
                task->data[0]++;

        }
        break;
    case 2:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            gSprites[task->data[15]].invisible ^= 1;

            if (++task->data[2] == 8)
                task->data[0]++;
        }
        break;
    case 3:
        gSprites[task->data[15]].invisible = FALSE;
        DestroyAnimVisualTask(taskId);
    }
}

// The horizontal bolts of electricity for Volt Tackle
void AnimTask_VoltTackleBolt(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
    case 0:
        task->data[1] = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER ? 1 : -1;

        switch (gBattleAnimArgs[0])
        {
        case 0:
            task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            task->data[5] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
            task->data[4] = (task->data[1] * 128) + 120;
            break;
        case 4:
            task->data[3] = 120 - (task->data[1] * 128);
            task->data[5] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
            task->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) - (task->data[1] * 32);
            break;
        default:
            if ((gBattleAnimArgs[0] & 1) != 0)
            {
                task->data[3] = 256;
                task->data[4] = -16;
            }
            else
            {
                task->data[3] = -16;
                task->data[4] = 256;
            }

            if (task->data[1] == 1)
            {
                task->data[5] = 80 - gBattleAnimArgs[0] * 10;
            }
            else
            {
                u16 temp;
                task->data[5] = gBattleAnimArgs[0] * 10 + 40;
                temp = task->data[3];
                task->data[3] = task->data[4];
                task->data[4] = temp;
            }
        }

        if (task->data[3] < task->data[4])
        {
            task->data[1] = 1;
            task->data[6] = 0;
        }
        else
        {
            task->data[1] = -1;
            task->data[6] = 3;
        }

        task->data[0]++;
        break;
    case 1:
        if (++task->data[2] > 0)
        {
            task->data[2] = 0;
            if (CreateVoltTackleBolt(task, taskId) || CreateVoltTackleBolt(task, taskId))
                task->data[0]++;
        }
        break;
    case 2:
        if (task->data[7] == 0)
            DestroyAnimVisualTask(taskId);
    }
}

static bool8 CreateVoltTackleBolt(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gVoltTackleBoltSpriteTemplate, task->data[3], task->data[5], 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 7;
        task->data[7]++;
    }

    task->data[6] += task->data[1];
    if (task->data[6] < 0)
        task->data[6] = 3;

    if (task->data[6] > 3)
        task->data[6] = 0;

    task->data[3] += task->data[1] * 16;

    if ((task->data[1] == 1 && task->data[3] >= task->data[4])
        || (task->data[1] == -1 && task->data[3] <= task->data[4]))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void AnimVoltTackleBolt(struct Sprite *sprite)
{
    if (++sprite->data[0] > 12)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
}

static void AnimGrowingShockWaveOrb(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        StartSpriteAffineAnim(sprite, 2);
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->affineAnimEnded)
            DestroySpriteAndMatrix(sprite);
        break;
    }
}

// Thin bolt of electricity that moves up and down toward the target. Used by Shock Wave
void AnimTask_ShockWaveProgressingBolt(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[6] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        task->data[7] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        task->data[8] = 4;
        task->data[10] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        task->data[9] = (task->data[10] - task->data[6]) / 5;
        task->data[4] = 7;
        task->data[5] = -1;
        task->data[11] = 12;
        task->data[12] = BattleAnimAdjustPanning(task->data[11] - 76);
        task->data[13] = BattleAnimAdjustPanning(SOUND_PAN_TARGET);
        task->data[14] = task->data[12];
        task->data[15] = (task->data[13] - task->data[12]) / 3;
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 0)
        {
            task->data[1] = 0;
            if (CreateShockWaveBoltSprite(task, taskId))
            {
                if (task->data[2] == 5)
                    task->data[0] = 3;
                else
                    task->data[0]++;
            }
        }

        if (task->data[11])
            task->data[11]--;
        break;
    case 2:
        if (task->data[11])
            task->data[11]--;

        if (++task->data[1] > 4)
        {
            task->data[1] = 0;
            if (task->data[2] & 1)
            {
                task->data[7] = 4;
                task->data[8] = 68;
                task->data[4] = 0;
                task->data[5] = 1;
            }
            else
            {
                task->data[7] = 68;
                task->data[8] = 4;
                task->data[4] = 7;
                task->data[5] = -1;
            }

            if (task->data[11])
                task->data[0] = 4;
            else
                task->data[0] = 1;
        }
        break;
    case 3:
        if (task->data[3] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    case 4:
        if (task->data[11])
            task->data[11]--;
        else
            task->data[0] = 1;
        break;
    }
}

static bool8 CreateShockWaveBoltSprite(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gShockWaveProgressingBoltSpriteTemplate, task->data[6], task->data[7], 35);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.tileNum += task->data[4];
        task->data[4] += task->data[5];
        if (task->data[4] < 0)
            task->data[4] = 7;
        if (task->data[4] > 7)
            task->data[4] = 0;

        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 3;
        task->data[3]++;
    }

    if (task->data[4] == 0 && task->data[5] > 0)
    {
        task->data[14] += task->data[15];
        PlaySE12WithPanning(SE_M_THUNDERBOLT, task->data[14]);
    }

    if ((task->data[5] < 0 && task->data[7] <= task->data[8])
        || (task->data[5] > 0 && task->data[7] >= task->data[8]))
    {
        task->data[2]++;
        task->data[6] += task->data[9];
        return TRUE;
    }
    else
    {
        task->data[7] += task->data[5] * 8;
        return FALSE;
    }
}

// Just runs timer for sprite. See AnimTask_ShockWaveProgressingBolt
static void AnimShockWaveProgressingBolt(struct Sprite *sprite)
{
    if (++sprite->data[0] > 12)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}

void AnimTask_ShockWaveLightning(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[15] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 32;
        task->data[14] = task->data[15];
        while (task->data[14] > 16)
        {
            task->data[14] -= 32;
        }

        task->data[13] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        task->data[12] = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 2;
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            if (CreateShockWaveLightningSprite(task, taskId))
                task->data[0]++;
        }
        break;
    case 2:
        if (task->data[10] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static bool8 CreateShockWaveLightningSprite(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gLightningSpriteTemplate, task->data[13], task->data[14], task->data[12]);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].callback = AnimShockWaveLightning;
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 10;
        task->data[10]++;
    }
    if (task->data[14] >= task->data[15])
        return TRUE;
    task->data[14] += 32;
    return FALSE;
}

static void AnimShockWaveLightning(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}
