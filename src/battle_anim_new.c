#include "global.h"
#include "battle_anim.h"
#include "item_menu_icons.h"
#include "sprite.h"
#include "random.h"
#include "gpu_regs.h"
#include "item.h"
#include "rtc.h"
#include "item_icon.h"
#include "sound.h"
#include "menu.h"
#include "malloc.h"
#include "util.h"
#include "trig.h"
#include "graphics.h"
#include "battle_scripts.h"
#include "battle_controllers.h"
#include "constants/moves.h"
#include "constants/hold_effects.h"
#include "constants/items.h"

// function declarations
static void SpriteCB_SpriteToCentreOfSide(struct Sprite* sprite);
static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite);
static void SpriteCB_ToxicThreadWrap(struct Sprite *sprite);
static void SpriteCB_GrowingSuperpower(struct Sprite *sprite);
static void SpriteCB_CentredSpiderWeb(struct Sprite* sprite);
static void SpriteCB_CoreEnforcerHits(struct Sprite* sprite);
static void SpriteCB_CoreEnforcerBeam(struct Sprite* sprite);
static void SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles(struct Sprite* sprite);
static void SpriteCB_FallingObject(struct Sprite *sprite);
static void SpriteCB_FallingObjectStep(struct Sprite *sprite);
static void SpriteCB_SunsteelStrikeRings(struct Sprite* sprite);
static void SpriteCB_MoongeistCharge(struct Sprite *sprite);
static void SpriteCB_MindBlownBall(struct Sprite *sprite);
static void AnimMindBlownBallStep(struct Sprite *sprite);
static void SpriteCB_MindBlownExplosion(struct Sprite* sprite);
static void SpriteCB_LockingJaw(struct Sprite *sprite);
static void SpriteCB_LockingJawStep(struct Sprite *sprite);
static void SpriteCB_LockingJawFinish(struct Sprite *sprite);
static void SpriteCB_LeftRightSlice(struct Sprite *sprite);
static void SpriteCB_LeftRightSliceStep1(struct Sprite *sprite);
static void SpriteCB_LeftRightSliceStep0(struct Sprite *sprite);
static void SpriteCB_PyroBallRockBounce(struct Sprite* sprite);
static void SpriteCB_PyroBallLaunch(struct Sprite* sprite);
static void SpriteCB_AcidLaunchSingleTarget(struct Sprite *sprite);
static void SpriteCB_AcidDripSingleTarget(struct Sprite *sprite);
static void SpriteCB_WaterDroplet(struct Sprite *sprite);
static void SpriteCB_WaterDropletDrip(struct Sprite *sprite);
static void SpriteCB_WaterDropletDrop(struct Sprite *sprite);
static void SpriteCB_AnimSpriteOnSelectedMonPos(struct Sprite *sprite);
static void SpriteCB_SurroundingRing(struct Sprite *sprite);
static void SpriteCB_PhotonGeyserBeam(struct Sprite* sprite);
static void SpriteCB_BeamUpStep(struct Sprite* sprite);
static void SpriteCB_CentredElectricity(struct Sprite* sprite);
static void AnimSkyDropBallUp(struct Sprite *sprite);
static void SpriteCB_SearingShotRock(struct Sprite* sprite);
static void AnimHappyHourCoinShower(struct Sprite *sprite);
static void SpriteCB_Geyser(struct Sprite* sprite);
static void SpriteCB_GeyserTarget(struct Sprite* sprite);
static void SpriteCB_TwinkleOnBattler(struct Sprite *sprite);
static void AnimBlastBurnTargetPlume_Step1(struct Sprite *sprite);
static void AnimBlastBurnTargetPlume(struct Sprite *sprite);
static void AnimEllipticalGustAttacker(struct Sprite *sprite);
static void AnimEllipticalGustAttacker_Step(struct Sprite *sprite);
static void AnimGrowingShockWaveOrbOnTarget(struct Sprite *sprite);
static void AnimTask_GrowStep(u8 taskId);
static void AnimExtremeEvoboostCircle(struct Sprite *sprite);
static void AnimExtremeEvoboostCircle_Step(struct Sprite *sprite);
static void AnimOceanicOperettaSpotlight(struct Sprite *sprite);
static void AnimSoulStealingStar(struct Sprite *sprite);
static void AnimSoulStealingStar_Step1(struct Sprite *sprite);
static void AnimSoulStealingStar_Step2(struct Sprite *sprite);

// const data
// general
static const union AffineAnimCmd sSquishTargetAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 64, 0, 16), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 64),
    AFFINEANIMCMD_FRAME(0, -64, 0, 16),
    AFFINEANIMCMD_END,
};

// GEN 4
// shadow sneak
const struct SpriteTemplate gShadowSneakImpactSpriteTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle
};

// power trick
const struct SpriteTemplate gPowerTrickSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POWER_TRICK,
    .paletteTag = ANIM_TAG_POWER_TRICK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration
};


//// GEN 5
//shell smash
const struct SpriteTemplate gShellSmashLeftShellSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHELL_RIGHT,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite
};

const struct SpriteTemplate gShellSmashRightShellSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHELL_LEFT,
    .paletteTag = ANIM_TAG_SHELL_LEFT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite
};

const struct SpriteTemplate gShellSmashPurpleRocksSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRockFragment
};

//wide guard
const struct SpriteTemplate gWideGuardBlueConversionTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion
};

//guard split
const struct SpriteTemplate gGuardSwapOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gGuardSwapOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc
};

// power split
const struct SpriteTemplate gPowerSplitOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gPowerSplitOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc
};

// automotize
const struct SpriteTemplate gAutotomizeMetalShardsTemplate =
{
    .tileTag = ANIM_TAG_METAL_BITS,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop
};

//rage powder
const struct SpriteTemplate gRagePowderRedPowderTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSporeParticle
};

//flame charge
const struct SpriteTemplate gFlameChargeEmberTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower
};

//final gambit
const struct SpriteTemplate gFinalGambitBlueYawnTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

const struct SpriteTemplate gFinalGambitExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//synchronoise
const struct SpriteTemplate gSynchronoiseVioletRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseBlueRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gSynchronoiseAeroWheelTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gAffineAnims_AirWaveCrescent,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//electro ball
const struct SpriteTemplate gElectroBallCannonBallTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

//foul play
const struct SpriteTemplate gFoulPlayImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gFoulPlayRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//simple beam
const struct SpriteTemplate gSimpleBeamBrownTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};
  
const struct SpriteTemplate gSimpleBeamPinkTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

const struct SpriteTemplate gSimpleBeamBrownRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gSimpleBeamPinkRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

// after you
const struct SpriteTemplate gAfterYouGreenRageTemplate =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAngerMarkAffineAnimTable,
    .callback = AnimAngerMark
};

//quick guard
const struct SpriteTemplate gQuickGuardArmImpactTemplate =
{
    .tileTag = ANIM_TAG_QUICK_GUARD_HAND,
    .paletteTag = ANIM_TAG_QUICK_GUARD_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBasicFistOrFoot
};

//sky drop
static const union AffineAnimCmd sSkyDropFlyBallAffineAnimCmd_0[] = 
{
    AFFINEANIMCMD_FRAME(0xa0, 0x100, 0x50, 0x0), 
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSkyDropFlyBallAffineAnimCmds[] = 
{
    sSkyDropFlyBallAffineAnimCmd_0
};
const struct SpriteTemplate gSkyDropFlyBallTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSkyDropFlyBallAffineAnimCmds,
    .callback = AnimThrowMistBall
};

const struct SpriteTemplate gSkyDropTargetFlyingTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimSkyDropBallUp
};

//shift gear
const struct SpriteTemplate gShiftGearGearsTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration
};

//circle throw
const struct SpriteTemplate gCircleThrowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//quash
const struct SpriteTemplate gQuashArmHitTemplate =
{
    .tileTag = ANIM_TAG_ASSURANCE_HAND,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStompFoot
};

//reflect type
const struct SpriteTemplate gReflectTypeBlueStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeVioletStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeWhiteStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

const struct SpriteTemplate gReflectTypeWhiteRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypePinkRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypeVioletRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gReflectTypeBlueRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

//frost breath
const struct SpriteTemplate gFrostBreathBlueRageTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonRageFirePlume
};

const struct SpriteTemplate gFrostBreathBlueBreathTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonRageFire,
    .images = NULL,
    .affineAnims = gAffineAnims_DragonRageFire,
    .callback = AnimDragonFireToTarget
};

//heart stamp
const struct SpriteTemplate gHeartStampSpinningHeartTemplate =
{
    .tileTag = ANIM_TAG_HEART_STAMP,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gAffineAnims_SpinningHandOrFoot,
    .callback = AnimSpinningKickOrPunch
};

//horn leech
const struct SpriteTemplate gHornLeechHornTemplate =
{
    .tileTag = ANIM_TAG_HORN_LEECH,
    .paletteTag = ANIM_TAG_HORN_LEECH,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimShadowBall
};

//dual chop
const struct SpriteTemplate gDualChopImpactTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//sacred sword
const struct SpriteTemplate gSacredSwordBladesTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

const struct SpriteTemplate gSacredSwordCutTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCuttingSlice
};

//razor shell
const struct SpriteTemplate gRazorShellTemplate =
{
    .tileTag = ANIM_TAG_RAZOR_SHELL,
    .paletteTag = ANIM_TAG_RAZOR_SHELL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_SpriteOnMonForDuration
};

//heat crash
const struct SpriteTemplate gHeatCrashEruptionRockTemplate =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStompFoot
};

//leaf tornado
const struct SpriteTemplate gLeafTornadoVortexTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

//cotton guard
const struct SpriteTemplate gCottonGuardSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};

//night daze
const struct SpriteTemplate gNightDazeVioletRingsTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gNightDazeVioletCirclesTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitScatter
};

//tail slap
const struct SpriteTemplate gTailSlapTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gScratchAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//gear grind
const struct SpriteTemplate gGearGrindTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimBite
};

//searing shot
const struct SpriteTemplate gSearingShotRedChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};

const struct SpriteTemplate gSearingShotEruptionRockTemplate =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOverheatFlame
};

static const union AffineAnimCmd sSpriteAffineAnim_SearingShotRock[] =
{
    AFFINEANIMCMD_FRAME(8, 8, 9, 15),
    AFFINEANIMCMD_FRAME(-8, -8, 9, 15),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_SearingShotRock[] =
{
    sSpriteAffineAnim_SearingShotRock,
};
const struct SpriteTemplate gSearingShotEruptionImpactTemplate =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_SearingShotRock,
    .callback = SpriteCB_SearingShotRock
};

//techno blast
const struct SpriteTemplate gTechnoBlastWhiteChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gTechnoBlastWhiteCircleTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gTechnoBlastWhiteBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};
const struct SpriteTemplate gTechnoBlastWhiteSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};
const struct SpriteTemplate gTechnoBlastWhiteSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gTechnoBlastYellowBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};
const struct SpriteTemplate gTechnoBlastYellowSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};
const struct SpriteTemplate gTechnoBlastYellowSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gTechnoBlastBlueChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gTechnoBlastBlueBubbleTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};
const struct SpriteTemplate gTechnoBlastBlueBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};
const struct SpriteTemplate gTechnoBlastBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};
const struct SpriteTemplate gTechnoBlastBlueSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gTechnoBlastRedChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gTechnoBlastRedBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};
const struct SpriteTemplate gTechnoBlastRedSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};
const struct SpriteTemplate gTechnoBlastRedSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gTechnoBlastIceChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gTechnoBlastIceBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
}; 
const struct SpriteTemplate gTechnoBlastIceSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};
const struct SpriteTemplate gTechnoBlastIceSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gTechnoBlastIceCrystalsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//secret sword
const struct SpriteTemplate gSecretSwordBladesTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//glaciate
const struct SpriteTemplate gGlaciateSmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlackSmoke
};

//blue flare
const struct SpriteTemplate gBlueFlareFlameJabTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gBlueFlareFlameSwirlTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gBlueFlareBurnTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//freeze shock
const struct SpriteTemplate gFreezeShockCircleTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb
};

const struct SpriteTemplate gFreezeShockIceBallTemplate =
{
    .tileTag = ANIM_TAG_ICE_CHUNK,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_IceBallChunk,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

//ice burn
const struct SpriteTemplate gIceBurnSmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlackSmoke
};

//icicle crash
static const union AffineAnimCmd sSpriteAffineAnim_IcicleCrash[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //180 degree turn
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_IcicleCrash[] =
{
    sSpriteAffineAnim_IcicleCrash,
};
const struct SpriteTemplate gIcicleCrashSpearTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ICICLE_SPEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_IcicleCrash,
    .callback = AnimFallingRock
};

//v create
const struct SpriteTemplate gVCreateFlameTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gVCreateRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gVCreateRedOrbTemplate =
{
    .tileTag = ANIM_TAG_ECLIPSING_ORB,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gEclipsingOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//fusion flare
const struct SpriteTemplate gFusionFlareRedBallUpTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWeatherBallUp
};

const struct SpriteTemplate gFusionFlareRedBallTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStompFoot
};

const struct SpriteTemplate gFusionFlareRedBubblesTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_WaterPulseBubble,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWaterPulseBubble
};

const struct SpriteTemplate gFusionFlareRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

//fusion bolt
static const union AffineAnimCmd sSpriteAffineAnim_DrakeStrikePlayer[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd sSpriteAffineAnim_DrakeStrikeOpponent[] = 
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sAffineAnimCmdTable_DrakeStriking[] =  //devestating drake, fusion bolt
{
    sSpriteAffineAnim_DrakeStrikePlayer,
    sSpriteAffineAnim_DrakeStrikeOpponent,
};
const struct SpriteTemplate gFusionBoltBallTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnimCmdTable_DrakeStriking,
    .callback = AnimFlyBallAttack
};

// GEN 6
//mat block
const struct SpriteTemplate gMatBlockGreenConversionTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_GREEN_LIGHT_WALL,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion
};

//belch
static const union AnimCmd sAnimCmdBerryEaten[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdFramesBerryEaten[] =
{
    sAnimCmdBerryEaten,
};
const struct SpriteTemplate gBelchBerryTemplate =
{
    .tileTag = ANIM_TAG_BERRY_NORMAL,
    .paletteTag = ANIM_TAG_BERRY_NORMAL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnimCmdFramesBerryEaten,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMissileArc
};

//forest's curse
const struct SpriteTemplate gForestsCurseIngrainTemplate =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gIngrainRootAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWaterPulseBubble
};

//petal blizzard
static const union AnimCmd sAnimCmd_PetalBlizzard1_0[] = 
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sAnimCmdTable_PetalBlizzard1[] = 
{
    sAnimCmd_PetalBlizzard1_0,
}; 
const struct SpriteTemplate gPetalBlizzardTwister1Template =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnimCmdTable_PetalBlizzard1,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle
};
static const u16 sPetalBlizzardFlowerOam[] = {0x0, 0x2000,0x0800,0x0};  //todo: convert to oam data
static const union AnimCmd sAnimCmd_PetalBlizzard2_0[] = 
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdTable_PetalBlizzard2[] = 
{
    sAnimCmd_PetalBlizzard2_0,
};
const struct SpriteTemplate gPetalBlizzardTwister2Template =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = (const struct OamData *) &sPetalBlizzardFlowerOam,
    .anims = sAnimCmdTable_PetalBlizzard2,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle
};

//crafty shield
const struct SpriteTemplate gCraftyShieldPinkConversionTemplate =
{
    .tileTag = ANIM_TAG_CRAFTY_SHIELD,
    .paletteTag = ANIM_TAG_CRAFTY_SHIELD,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion
};

//grassy terrain
const struct SpriteTemplate gGrassyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gGrassyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//misty terrain
const struct SpriteTemplate gMistyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gMistyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//electrify
const struct SpriteTemplate gElectrifyRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gElectrifyYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

//fairy wind
const struct SpriteTemplate gFairyWindCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSwiftStarAffineAnimTable,
    .callback = AnimTranslateLinearSingleSineWave
};

//confide
const struct SpriteTemplate gConfideBubbleTemplate =
{
    .tileTag = ANIM_TAG_CONFIDE,
    .paletteTag = ANIM_TAG_CONFIDE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gMetronomeThroughtBubbleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThoughtBubble
};

//diamond storm
const struct SpriteTemplate gDiamondStormSwirlingIceTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_Snowball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSwirlingSnowball_Step1
};

const struct SpriteTemplate gDiamondStormBlizzardTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gAnims_BlizzardIceCrystal,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveParticleBeyondTarget
};

const struct SpriteTemplate gDiamondStormDiamondsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .images = NULL,
    .affineAnims = gAffineAnims_BasicRock,
    .callback = AnimMoveTwisterParticle
};

//steam eruption
const struct SpriteTemplate gSteamEruptionBreathTemplate =
{
    .tileTag = ANIM_TAG_STEAM_ERUPTION,
    .paletteTag = ANIM_TAG_STEAM_ERUPTION,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gAffineAnims_DragonBreathFire,
    .callback = AnimDragonFireToTarget
};

//hyperspace hole
const struct SpriteTemplate gHyperspaceHoleImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle
};

//water shuriken
const struct SpriteTemplate gWaterShurikenStarTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

const struct SpriteTemplate gWaterShurikenRingTemplate =
{
    .tileTag = ANIM_TAG_BLUE_RING_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gWaterPulseRingAffineAnimTable,
    .callback = AnimWaterPulseRing
};

const struct SpriteTemplate gWaterShurikenImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//eerie impulse
const struct SpriteTemplate gEerieImpulseRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing
};

const struct SpriteTemplate gEerieImpulseImpactTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};

//venom drench
const struct SpriteTemplate gVenomDrenchAcidTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFallingRock
};

//powder
const struct SpriteTemplate gPowderBlackSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSporeParticle
};

//geomancy
const struct SpriteTemplate gGeomancyRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

const struct SpriteTemplate gGeomancyYellowRageTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonRageFirePlume
};

const struct SpriteTemplate gGeomancyRedCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gGeomancyGreenCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gGeomancyBlueCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gGeomancyRedCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRaiseSprite
};

const struct SpriteTemplate gGeomancyGreenCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRaiseSprite
};

const struct SpriteTemplate gGeomancyBlueCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRaiseSprite
};

//magnetic flux
const struct SpriteTemplate gMagneticFluxUproarTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

//happy hour
const struct SpriteTemplate gHappyHourCoinShowerTemplate =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gCoinAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHappyHourCoinShower
};

//electric terrain
const struct SpriteTemplate gElectricTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gElectricTerrainFlyingBallTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//celebrate
const struct SpriteTemplate gCelebrateBagTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimFollowMeFinger
};

//hold hands
const struct SpriteTemplate gHoldHandsHeartTemplate =
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower
};

//hold back
const struct SpriteTemplate gHoldBackSwipeTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_SWIPE,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = gAnims_RevengeBigScratch,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRevengeScratch
};

const struct SpriteTemplate gHoldBackRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gHoldBackStarsTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDizzyPunchDuck
};

//infestation
const struct SpriteTemplate gInfestationBubbleTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_WaterPulseBubble,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};

//oblivion wing
static const union AffineAnimCmd sSpriteAffineAnim_GrowingRing[] =
{
    AFFINEANIMCMD_FRAME(8, 8, 0, 16), //Double in size
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_GrowingRing[] =
{
    sSpriteAffineAnim_GrowingRing,
};
const struct SpriteTemplate gOblivionWingBeamTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingRing,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

//thousand arrows
const struct SpriteTemplate gThousandArrowsGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};

const struct SpriteTemplate gThousandArrowsGreenHexTemplate =
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Geyser
};

const struct SpriteTemplate gThousandArrowsGreenArrowTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMudSportDirt
};

const struct SpriteTemplate gThousandArrowsGreenDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricPuff
};

//thousand waves
const struct SpriteTemplate gThousandWavesGreenWaveTemplate =
{
    .tileTag = ANIM_TAG_FLYING_DIRT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlyingSandCrescent
};

const struct SpriteTemplate gThousandWavesGreenRecoverTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};

const struct SpriteTemplate gThousandWavesGreenWheelTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonDanceOrb
};

const struct SpriteTemplate gThousandWavesRotatingImpactTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gThousandWavesPoundImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatOnMonEdge
};

//lands wrath
const struct SpriteTemplate gLandsWrathVortexTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex
};

//light of ruin
const struct SpriteTemplate gLightOfRuinPinkOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate gLightOfRuinPinkDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricPuff
};

const struct SpriteTemplate gLightOfRuinPinkExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//origin pulse
const struct SpriteTemplate gOriginPulseRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gOriginPulseOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonDanceOrb
};

const struct SpriteTemplate gOriginPulseOrbInwardTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gOriginPulseBlueImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom
};

const struct SpriteTemplate gOriginPulseBasicSplatTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//precipice blades
static const union AnimCmd sAnimCmdLargeSpike[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdTable_LargeSpike[] =
{
    sAnimCmdLargeSpike,
};
const struct SpriteTemplate gPrecipiceBladesSpikeTemplate =
{
    .tileTag = ANIM_TAG_LARGE_SPIKE,
    .paletteTag = ANIM_TAG_LARGE_SPIKE,
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
    .anims = sAnimCmdTable_LargeSpike,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpriteOnMonForDuration
};

static const union AffineAnimCmd sSpriteAffineAnim_LargeHailRock[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 1), //Double sprite size
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_LargeHailRock[] =
{
    sSpriteAffineAnim_LargeHailRock,
};
const struct SpriteTemplate gPrecipiceBladesLargeSpikeTemplate =
{
    .tileTag = ANIM_TAG_LARGE_SPIKE,
    .paletteTag = ANIM_TAG_LARGE_SPIKE,
    .oam = &gOamData_AffineDouble_ObjNormal_32x64,
    .anims = sAnimCmdTable_LargeSpike,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_SpriteOnMonForDuration
};

const struct SpriteTemplate gPrecipiceBladesPlumeTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_AnimSpriteOnSelectedMonPos
};

//dragon ascent
static const union AffineAnimCmd sAffineAnimCmd_Drake[] = 
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1), //drake faces up
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sAffineAnimCmdTable_DrakeFaceNorth[] =
{
    sAffineAnimCmd_Drake,
    sAffineAnimCmd_Drake,
};
const struct SpriteTemplate gDragonAscentFlyUpTemplate =
{
    .tileTag = ANIM_TAG_DRAGON_ASCENT,
    .paletteTag = ANIM_TAG_DRAGON_ASCENT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnimCmdTable_DrakeFaceNorth,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gDragonAscentDrakeTemplate =
{
    .tileTag = ANIM_TAG_DRAGON_ASCENT,
    .paletteTag = ANIM_TAG_DRAGON_ASCENT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnimCmdTable_DrakeStriking,
    .callback = AnimFlyBallAttack
};

//hyperspace fury
const struct SpriteTemplate gHyperspaceFuryRingTemplate =
{
    .tileTag = ANIM_TAG_HOOPA_RING,
    .paletteTag = ANIM_TAG_HOOPA_RING,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward
};

const struct SpriteTemplate gHyperspaceFuryHandTemplate =
{
    .tileTag = ANIM_TAG_HOOPA_HAND,
    .paletteTag = ANIM_TAG_HOOPA_HAND,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gHyperspaceFuryImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom
};

// GEN 7
//first impression
const struct SpriteTemplate gFirstImpressionPoundTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//baneful bunker
const struct SpriteTemplate gBanefulBunkerPoisonBubbleTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};

//spirit shackle
const struct SpriteTemplate gSpiritShackleArrowTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSonicBoomProjectile
};

const struct SpriteTemplate gSpiritShackleChainTemplate =
{
    .tileTag = ANIM_TAG_CHAIN_LINK,
    .paletteTag = ANIM_TAG_CHAIN_LINK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThunderWave
};

//darkest lariat
const struct SpriteTemplate gDarkestLariatImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//sparklig aria
const struct SpriteTemplate gSparklingAriaBlueChargeTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};

const struct SpriteTemplate gSparklingAriaRainTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMudSportDirt
};

const struct SpriteTemplate gSparklingAriaBubbleRainTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMudSportDirt
};

const struct SpriteTemplate gSparklingAriaBubblesTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};

//ice hammer
const struct SpriteTemplate gIceHammerPunchStompTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStompFoot
};

const struct SpriteTemplate gIceHammerSmokesTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlackSmoke
};

//floral healing
const struct SpriteTemplate gFloralHealingFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSporeParticle
};

const struct SpriteTemplate gFloralHealingOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gFloralHealingLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex
};

const struct SpriteTemplate gFloralHealingWindLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSweetScentPetal
};

//high horsepower
const struct SpriteTemplate gHighHorsepowerHorseshoeTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gAffineAnims_MegaPunchKick,
    .callback = AnimSpinningKickOrPunch
};

//strength sap
const struct SpriteTemplate gStrengthSapRedSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gStrengthSapRedInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTealAlert
};

const struct SpriteTemplate gStrengthSapAbsorbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gAbsorptionOrbAffineAnimTable,
    .callback = AnimAbsorptionOrb
};

//solar blade
const struct SpriteTemplate gSolarBladeImpactTemplate =
{
    .tileTag = ANIM_TAG_CLAW_SLASH,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ClawSlash,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimClawSlash
};

//leafage
const struct SpriteTemplate gLeafageImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//toxic thread
const struct SpriteTemplate gToxicThreadString =
{
    .tileTag = ANIM_TAG_STRING,
    .paletteTag = ANIM_TAG_STRING,
    .oam = &gOamData_AffineOff_ObjNormal_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ToxicThreadWrap
};

//laser focus
const struct SpriteTemplate gLaserFocusRedEyesTemplate =
{
    .tileTag = ANIM_TAG_OPENING_EYE,
    .paletteTag = ANIM_TAG_EYE_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOpeningEyeAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//gear up
const struct SpriteTemplate gGearUpGearsTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower
};

//throat chop
const struct SpriteTemplate gThroatChopRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//pollen puff
const struct SpriteTemplate gPollenPuffPinkStarTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};

const struct SpriteTemplate gPollenPuffPinkSparkleTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};

const struct SpriteTemplate gPollenPuffYellowSparkleTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};

const struct SpriteTemplate gPollenPuffSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile
};

const struct SpriteTemplate gPollenPuffImpactTemplates =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPollenPuffHealTemplate =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gHealingBlueStarAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//anchor shot
const struct SpriteTemplate gAnchorShotAnchorTemplate =
{
    .tileTag = ANIM_TAG_ANCHOR,
    .paletteTag = ANIM_TAG_CHAIN_LINK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlockX
};

const struct SpriteTemplate gAnchorShotAngledAnchorTemplate =
{
    .tileTag = ANIM_TAG_ANCHOR,
    .paletteTag = ANIM_TAG_CHAIN_LINK,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

//psychic terrain
const struct SpriteTemplate gPsychicTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast
};

const struct SpriteTemplate gPsychicTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimOrbitScatter
};

//lunge
const struct SpriteTemplate gLungeGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_PsychoBoostOrb,
    .callback = AnimPsychoBoost
};

const struct SpriteTemplate gLungeGreenBubbleTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile
};

const struct SpriteTemplate gLungeGreenImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//power trip
const struct SpriteTemplate gPowerTripFocusEnergyTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};

const struct SpriteTemplate gPowerTripImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//burn up
const struct SpriteTemplate gBurnUpRedYawnTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowMistBall
};

//speed swap
const struct SpriteTemplate gSpeedSwapRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gSpeedSwapCircleTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gSpeedSwapOrbMissileTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMissileArc
};

const struct SpriteTemplate gSpeedSwapOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

//smart strike
const struct SpriteTemplate gSmartStrikeGemTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gSmartStrikeImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_FLASH_CANNON_BALL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//purify
const struct SpriteTemplate gPurifyWhiteBallTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_FLASH_CANNON_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMissileArc
};

const struct SpriteTemplate gPurifySmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlackSmoke
};

//revelation dance
const struct SpriteTemplate gRevelationDanceYellowOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower
};

const struct SpriteTemplate gRevelationDanceYellowFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gPetalDanceSmallFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceSmallFlower
};

const struct SpriteTemplate gRevelationDanceYellowAirWaveTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSonicBoomProjectile
};

const struct SpriteTemplate gRevelationDanceYellowImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gRevelationDanceYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gRevelationDanceYellowDispersalTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//core enforcer
const struct SpriteTemplate gCoreEnforcerBlueRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gCoreEnforcerYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gCoreEnforcerGreenRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gCoreEnforcerCircleChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimFlashingHitSplat
};

const struct SpriteTemplate gCoreEnforcerBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparkElectricity
};

const struct SpriteTemplate gCoreEnforcerGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparkElectricity
};

const struct SpriteTemplate gCoreEnforcerSnoreTemplate =
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CentredSpiderWeb
};

const struct SpriteTemplate gCoreEnforcerImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_CoreEnforcerHits
};

const struct SpriteTemplate gCoreEnforcerBeamTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CoreEnforcerBeam
};

const struct SpriteTemplate gCoreEnforcerExplosionTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpriteToCentreOfSide
};

//trop kick
const struct SpriteTemplate gTropKickGreenFootTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJumpKick
};

const struct SpriteTemplate gTropKickFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

const struct SpriteTemplate gTropKickLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpread
};

//clanging scales
const struct SpriteTemplate gClangingScalesPurpleMetalSoundTemplate =
{
    .tileTag = ANIM_TAG_METAL_SOUND_WAVES,
    .paletteTag = ANIM_TAG_METAL_SOUND_WAVES,
    .oam = &gOamData_AffineDouble_ObjNormal_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles
};

//brutal swing
const struct SpriteTemplate gBrutalSwingRandomImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom
};

const struct SpriteTemplate gBrutalSwingBasicImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

//aurora veil
const struct SpriteTemplate gAuroraVeilRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing
};

//shell trap
const struct SpriteTemplate gShellTrapYellowImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gShellTrapRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gShellTrapFireHitsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_Snowball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveParticleBeyondTarget
};

//fleur cannon
const struct SpriteTemplate gFleurCannonOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};

const struct SpriteTemplate gFleurCannonDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricPuff
};

//stomping tantrum
const struct SpriteTemplate gStompingTantrumRockTemplate =
{
    .tileTag = ANIM_TAG_SMALL_ROCK,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop
};

//prismatic laser
const struct SpriteTemplate gPrismaticLaserChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
 
const struct SpriteTemplate gPrismaticLaserYellowOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserGreenOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserRedOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserVioletOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserYellowInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserGreenInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserRedInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserVioletInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gPrismaticLaserYellowRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FallingObject
};

const struct SpriteTemplate gPrismaticLaserGreenRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FallingObject
};

const struct SpriteTemplate gPrismaticLaserRedRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FallingObject
};

const struct SpriteTemplate gPrismaticLaserVioletRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FallingObject
};

//spectral thief
const struct SpriteTemplate gSpectralThiefBlackSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gSpectralThiefThiefImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle
};

const struct SpriteTemplate gSpectralThiefBlackOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMimicOrb
};

const struct SpriteTemplate gSpectralThiefBlackBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};

//sunsteeel strike
const struct SpriteTemplate gSunsteelStrikeBlackFlyBallTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};

static const struct OamData sSunsteelStrikeBlastOAM =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1, //Above sprites
};
static const union AffineAnimCmd sSpriteAffineAnim_SunsteelStrikeBlastEnemySide[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -64, 1), //90 degree turn
    AFFINEANIMCMD_FRAME(0, 0, 0, 7), //Pause
    AFFINEANIMCMD_FRAME(16, 16, 0, 15), //Double in size
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd sSpriteAffineAnim_SunsteelStrikeBlastPlayerSide[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //180 degree turn
    AFFINEANIMCMD_FRAME(0, 0, 0, 7), //Pause
    AFFINEANIMCMD_FRAME(16, 16, 0, 15), //Double in size
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_SunsteelStrikeBlast[] =
{
    sSpriteAffineAnim_SunsteelStrikeBlastEnemySide,
    sSpriteAffineAnim_SunsteelStrikeBlastPlayerSide,
};
const struct SpriteTemplate gSunsteelStrikeSuperpowerTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_METEOR,
    .oam = &sSunsteelStrikeBlastOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_SunsteelStrikeBlast,
    .callback = AnimFlyBallAttack
};

const struct SpriteTemplate gSunsteelStrikeRedBeamTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallAttack,
    .callback = SpriteCB_SunsteelStrikeRings
};

const struct SpriteTemplate gSunsteelStrikeYellowBeamTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_GOLD_RING,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallAttack,
    .callback = SpriteCB_SunsteelStrikeRings
};

const struct SpriteTemplate gSunsteelStrikeRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

const struct SpriteTemplate gSunsteelStrikeRocksTemplate =
{
    .tileTag = ANIM_TAG_SMALL_ROCK,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop
};

//moongeist beam
const struct SpriteTemplate gMoongeistBeamBlueOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};

const struct SpriteTemplate gMoongeistBeamPurpleOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};

const struct SpriteTemplate gMoongeistBeamChargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MoongeistCharge
};

//zing zap
const struct SpriteTemplate gZingZapYellowBallTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall
};

const struct SpriteTemplate gZingZapRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

//nature's madness
const struct SpriteTemplate gNaturesMadnessPinkStarsTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};

const struct SpriteTemplate gNaturesMadnessCrystalsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_SmallBubblePair,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmallBubblePair
};

const struct SpriteTemplate gNaturesMadnessPinkRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gNaturesMadnessGrayRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//mind blown
const struct SpriteTemplate gMindBlownHeadTemplate =
{
    .tileTag = ANIM_TAG_BLACEPHALON_HEAD,
    .paletteTag = ANIM_TAG_BLACEPHALON_HEAD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_MindBlownBall
};

const struct SpriteTemplate gMindBlownBlueOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MindBlownExplosion
};

const struct SpriteTemplate gMindBlownPinkOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MindBlownExplosion
};

const struct SpriteTemplate gMindBlownBlueImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_RandomCentredHits
};

const struct SpriteTemplate gMindBlownPinkImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_RandomCentredHits
};

//plasma fists
const struct SpriteTemplate gPlasmaFistsChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};

//photon geyser
static const union AnimCmd sAnimCmdPhotonGeyserBeam1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};
static const union AnimCmd sAnimCmdSmiteBeam[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};
static const union AnimCmd sAnimCmdPhotonGeyserBeam2[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};
static const union AnimCmd *const sAnimCmdTable_PhotonGeyserBeam[] =
{
    sAnimCmdPhotonGeyserBeam1,
    sAnimCmdSmiteBeam,
    sAnimCmdPhotonGeyserBeam2,
};
static const union AffineAnimCmd sSpriteAffineAnim_DoNothing[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1), //Do nothing
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd sSpriteAffineAnim_PhotonGeyserBeam[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 16), //Delay
    AFFINEANIMCMD_FRAME(64, 64, 0, 4), //Double in size
    //Pulsate
    AFFINEANIMCMD_FRAME(-128, -128, 0, 1),
    AFFINEANIMCMD_FRAME(128, 128, 0, 1),
    AFFINEANIMCMD_JUMP(2),
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_PhotonGeyserBeam[] =
{
    sSpriteAffineAnim_DoNothing,
    sSpriteAffineAnim_PhotonGeyserBeam,
};
const struct SpriteTemplate gPhotonGeyserBeam =
{
    .tileTag = ANIM_TAG_STRAIGHT_BEAM,
    .paletteTag = ANIM_TAG_STRAIGHT_BEAM,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sAnimCmdTable_PhotonGeyserBeam,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_PhotonGeyserBeam,
    .callback = SpriteCB_PhotonGeyserBeam
};

const struct SpriteTemplate gPhotonGeyserChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};

const struct SpriteTemplate gPhotonGeyserSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparkElectricity
};

const struct SpriteTemplate gPhotonGeyserZapCannonSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark
};

const struct SpriteTemplate gPhotonGeyserWhiteRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gPhotonGeyserYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing
};

const struct SpriteTemplate gPhotonGeyserZapBallTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};


// GEN 8
//snipe shot
static const union AffineAnimCmd sSpriteAffineAnim_LargeSpikePointedLeft[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 32, 1), //45 degree turn
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_LargeSpikePointedRight[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -32, 1), //45 degree turn
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_LargeSpike[] =
{
    sSpriteAffineAnim_LargeSpikePointedLeft,
    sSpriteAffineAnim_LargeSpikePointedRight,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_SnipeShot[] =
{
    sSpriteAffineAnim_LargeSpikePointedRight,
};
static const union AnimCmd sAnimCmdSnipeShot[] =
{
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdTable_SnipeShot[] =
{
    sAnimCmdSnipeShot,
};
const struct SpriteTemplate gSnipeShotBallTemplate =    //used in aura sphere
{
    .tileTag = ANIM_TAG_IMPACT_2,
    .paletteTag = ANIM_TAG_IMPACT_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnimCmdTable_SnipeShot,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_SnipeShot,
    .callback = AnimShadowBall
};

//jaw lock
const struct SpriteTemplate gJawLockTeethTemplate =
{
    .tileTag = ANIM_TAG_SHARP_TEETH,
    .paletteTag = ANIM_TAG_SHARP_TEETH,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = SpriteCB_LockingJaw
};

//stuff cheeks
static const union AnimCmd sAnimCmdBerryChomp[] =
{
    ANIMCMD_FRAME(0, 0x30),
    ANIMCMD_FRAME(0, 0x25),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdTable_BerryChomp[] =
{
    sAnimCmdBerryChomp,
};
const struct SpriteTemplate gFloatingBerryTemplate =
{
    .tileTag = ANIM_TAG_BERRY_NORMAL,
    .paletteTag = ANIM_TAG_BERRY_NORMAL,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = sAnimCmdTable_BerryChomp,
    .images = NULL,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimMetronomeFinger
};

//no retreat
static const struct OamData sPyroBallFlamesOAM =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1, //Above sprites
};
const struct SpriteTemplate gNoRetreatFlameTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpriteOnMonForDuration
};

//magic powder
const struct SpriteTemplate gMagicPowderBluePowderTemplate =
{
    .tileTag = ANIM_TAG_POISON_POWDER,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gPowderParticlesAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovePowderParticle
};

//dreepy missile
const struct SpriteTemplate gDreepyMissileTemplate =
{
    .tileTag = ANIM_TAG_DREEPY,
    .paletteTag = ANIM_TAG_DREEPY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimShadowBall
};

//bolt beak
const struct SpriteTemplate gBoltBeakBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparkElectricity
};

const struct SpriteTemplate gBoltBeakBlueFlashingSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimSparkElectricityFlashing
};

//fishious rend
static const struct OamData sFishiousRendTeethOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1, //Above sprites
};
const struct SpriteTemplate gFishiousRendTeethTemplate =
{
    .tileTag = ANIM_TAG_SHARP_TEETH,
    .paletteTag = ANIM_TAG_SHARP_TEETH,
    .oam = &sFishiousRendTeethOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_LeftRightSlice
};

//clangorous soul
const struct SpriteTemplate gClangorousSoulBlueBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};

const struct SpriteTemplate gClangorousSoulPurpleBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};

const struct SpriteTemplate gClangorousSoulWhiteBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};

const struct SpriteTemplate gClangorousSoulRedFistTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJumpKick
};

const struct SpriteTemplate gClangorousSoulRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

//pyro ball
static const struct OamData sPyroBallRockOAM =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1, //Above sprites
};
const struct SpriteTemplate gPyroBallRockTemplate =
{
    .tileTag = ANIM_TAG_FLAT_ROCK,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &sPyroBallRockOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PyroBallRockBounce
};

const struct SpriteTemplate gPyroBallBurningRockTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PyroBallRockBounce
};

const struct SpriteTemplate gPyroBallFlamesUpTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PyroBallRockBounce
};

const struct SpriteTemplate gPyroBallEmberBallTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gAnims_DragonBreathFire,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PyroBallLaunch
};

//aura wheel
const struct SpriteTemplate gAuraWheelBlueElectricityTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward
};

const struct SpriteTemplate gAuraWheelRedElectricityTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward
};

//breaking swipe
const struct SpriteTemplate gBreakingSwipeCenteredElectricity =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CentredElectricity
};

//branch poke
const struct SpriteTemplate gBranchPokeBranchTemplate =
{
    .tileTag = ANIM_TAG_BRANCH,
    .paletteTag = ANIM_TAG_BRANCH,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimShadowBall
};

//apple acid
const struct SpriteTemplate gAppleAcidFloatingAppleTemplate =
{
    .tileTag = ANIM_TAG_APPLE,
    .paletteTag = ANIM_TAG_APPLE,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimMetronomeFinger
};

const struct SpriteTemplate gAppleAcidLaunchTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = SpriteCB_AcidLaunchSingleTarget
};

const struct SpriteTemplate gAppleAcidDripTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_AcidPoisonDroplet,
    .images = NULL,
    .affineAnims = gAffineAnims_Droplet,
    .callback = SpriteCB_AcidDripSingleTarget
};

//grav apple
static const struct OamData sAppleOAM =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1, //Above sprites
};
const struct SpriteTemplate gGravAppleSmallApple =
{
    .tileTag = ANIM_TAG_APPLE,
    .paletteTag = ANIM_TAG_APPLE,
    .oam = &sAppleOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FallingObject
};

static const union AffineAnimCmd sSpriteAffineAnim_ScaledApple[] =
{
    AFFINEANIMCMD_FRAME(64, 64, 0, 10), //Quadruple in size
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_ScaledApple[] =
{
    sSpriteAffineAnim_ScaledApple,
};
const struct SpriteTemplate gGravAppleLargeApple =
{
    .tileTag = ANIM_TAG_APPLE,
    .paletteTag = ANIM_TAG_APPLE,
    .oam = &sAppleOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_ScaledApple,
    .callback = SpriteCB_FallingObject
};

//strange steam
const struct SpriteTemplate gStrangeSteamPinkCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter
};

const struct SpriteTemplate gStrangeSteamGreenCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter
};

const struct SpriteTemplate gStrangeSteamBlueCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter
};

//life dew
static const union AnimCmd sAnimCmdWaterDropletDrip[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};
static const union AnimCmd sAnimCmdWaterDropletSplash[] =
{
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_FRAME(112, 10),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimCmdWaterDroplet[] =
{
    sAnimCmdWaterDropletDrip,
    sAnimCmdWaterDropletSplash,
};
const struct SpriteTemplate gLifeDewDropletTemplate =
{
    .tileTag = ANIM_TAG_WATER_DROPLET,
    .paletteTag = ANIM_TAG_WATER_DROPLET,
    .oam = &sAppleOAM,
    .anims = sAnimCmdWaterDroplet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_WaterDroplet
};

const struct SpriteTemplate gLifeDewSpecialOrbsTemplate =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_BLUE_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gHealingBlueStarAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_AnimSpriteOnSelectedMonPos
};

//obstruct
const struct SpriteTemplate gObstructCrossTemplate =
{
    .tileTag = ANIM_TAG_OBSTRUCT_CROSS,
    .paletteTag = ANIM_TAG_OBSTRUCT_CROSS,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCrossImpact
};

//meteor assault
static const struct OamData sGrowingSuperpowerOAM =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 2,
};
static const union AffineAnimCmd sSpriteAffineAnim_GrowingSuperpowerEnemyAttack[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //180 degree turn
    AFFINEANIMCMD_FRAME(0, 0, 0, 2), //Pause
    AFFINEANIMCMD_FRAME(16, 16, 0, 15), //Double in size
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd sSpriteAffineAnim_GrowingSuperpowerPlayerAttack[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 2), //Pause
    AFFINEANIMCMD_FRAME(16, 16, 0, 15), //Double in size
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sSpriteAffineAnimTable_GrowingSuperpower[] =
{
    sSpriteAffineAnim_GrowingSuperpowerPlayerAttack,
    sSpriteAffineAnim_GrowingSuperpowerEnemyAttack,
};
const struct SpriteTemplate gGrowingSuperpowerTemplate =    //used in breakneck blitz
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_METEOR,
    .oam = &sGrowingSuperpowerOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower
};

//steel beam
const struct SpriteTemplate gSteelBeamSpikeShardTemplate =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter
};

// Z MOVES
//activate
const struct SpriteTemplate gZMoveSymbolSpriteTemplate = 
{
    .tileTag = ANIM_TAG_Z_MOVE_SYMBOL,
    .paletteTag = ANIM_TAG_Z_MOVE_SYMBOL,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_LusterPurgeCircle,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlueZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};
const struct SpriteTemplate gGreenZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};
const struct SpriteTemplate gYellowZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};
// breakneck blitz
const struct SpriteTemplate gBreakneckBlitzDanceSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDragonDanceOrb
};
const struct SpriteTemplate gBreakneckBlitzHitSpriteTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};
// all out pummelling
const struct SpriteTemplate gAllOutPummelingOnslaughtSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJumpKick
};
// supersonic skystrike
static const union AffineAnimCmd sSupersonicSkystrikeAffinePlayerSide[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd sSupersonicSkystrikeAffineOpponentSide[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sSupersonicSkystrikeAffineAnimTable[] = {
    sSupersonicSkystrikeAffinePlayerSide,
    sSupersonicSkystrikeAffineOpponentSide,
};
const struct SpriteTemplate gSupersonicSkystrikeFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_BIRD,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSupersonicSkystrikeAffineAnimTable,
    .callback = AnimFlyBallAttack
};
//acid downpour
const struct SpriteTemplate gAcidDownpourReversalSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimReversalOrb
};
const struct SpriteTemplate gAcidDownpourAuraSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
//tectonic rage
const struct SpriteTemplate gTectonicRageBlastBurnSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlastBurnTargetPlume
};
const struct SpriteTemplate gTectonicRageExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// continental crush
const struct SpriteTemplate gContinentalCrushNeedleArmSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};
const struct SpriteTemplate gContinentalCrushBigRockStompSpriteTemplate = 
{
    .tileTag = ANIM_TAG_REALLY_BIG_ROCK,
    .paletteTag = ANIM_TAG_REALLY_BIG_ROCK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_FallingObject
};
const struct SpriteTemplate gContinentalCrushFocusEnergySpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gContinentalCrushGrowingRockSpriteTemplate = 
{
    .tileTag = ANIM_TAG_REALLY_BIG_ROCK,
    .paletteTag = ANIM_TAG_REALLY_BIG_ROCK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gContinentalCrushEruptionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEruptionFallingRock
};

// savage spin out
const struct SpriteTemplate gSavageSpinOutStringBlastSpriteTemplate = 
{
    .tileTag = ANIM_TAG_STRING,
    .paletteTag = ANIM_TAG_STRING,
    .oam = &gOamData_AffineOff_ObjNormal_64x32,
    .anims = gAffineAnims_AirWaveCrescent,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAirWaveCrescent
};
const struct SpriteTemplate gSavageSpinOutCacoonSpriteTemplate = 
{
    .tileTag = ANIM_TAG_COCOON,
    .paletteTag = ANIM_TAG_COCOON,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite
};
const struct SpriteTemplate gSavageSpinOutGreenChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gSavageSpinOutGreenCutSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCuttingSlice
};
const struct SpriteTemplate gSavageSpinOutWhiteExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// never ending nightmare
const struct SpriteTemplate gNeverEndingNightmareRingAttackerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gNeverEndingNightmareRingTargetSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gNeverEndingNightmareFocusEnergySpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gNeverEndingNightmareHandSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ASSURANCE_HAND,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};
const struct SpriteTemplate gNeverEndingNightmareBlastBurnSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlastBurnTargetPlume
};
const struct SpriteTemplate gNeverEndingNightmareGeyserHexSpriteTemplate = 
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GeyserTarget
};
const struct SpriteTemplate gNeverEndingNightmareExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// corkscrew crash
const struct SpriteTemplate gCorkscrewCrashMetalBitSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gCorkscrewCrashChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gCorkscrewCrashCorkscrewFlyUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimParticleInVortex
};
static const union AffineAnimCmd sCorkscrewCrashFlyDownAffineOpponentSide[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x80, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd* const sCorkscrewCrashFlyDownAffineAnimTable[] = {
    sCorkscrewCrashFlyDownAffineOpponentSide,
};
const struct SpriteTemplate gCorkscrewCrashCorkscrewFlyDownSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashFlyDownAffineAnimTable,
    .callback = AnimStompFoot
};
static const union AffineAnimCmd sCorkscrewCrashStrikePlayerAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd sCorkscrewCrashStrikeTargetAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sCorkscrewCrashStrikeAffineAnimTable[] = {
    sCorkscrewCrashStrikePlayerAffineAnims,
    sCorkscrewCrashStrikeTargetAffineAnims,
};
const struct SpriteTemplate gCorkscrewCrashStrikeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack
};
static const union AffineAnimCmd sCorkscrewCrashLeftAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sCorkscrewCrashLeftAffineAnimTable[] = {
    sCorkscrewCrashLeftAffineAnims,
};
const struct SpriteTemplate gCorkscrewCrashLeftUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashLeftAffineAnimTable,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gCorkscrewCrashLeftDownSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashLeftAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sCorkscrewCrashRightUpAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sCorkscrewCrashRightUpAffineAnimTable[] = {
    sCorkscrewCrashRightUpAffineAnims,
};
const struct SpriteTemplate gCorkscrewCrashRightUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashRightUpAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sCorkscrewCrashRightDownAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xba, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sCorkscrewCrashRightDownAffineAnimTable[] = {
    sCorkscrewCrashRightDownAffineAnims,
};
const struct SpriteTemplate gCorkscrewCrashRightDownSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sCorkscrewCrashRightDownAffineAnimTable,
    .callback = AnimAssistPawprint
};

// inferno overdrive
const struct SpriteTemplate gInfernoOverdriveSuperpowerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &sGrowingSuperpowerOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower
};
const struct SpriteTemplate gInfernoOverdriveChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gInfernoOverdriveExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// hydro vortex
const struct SpriteTemplate gHydroVortexSuperpowerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &sGrowingSuperpowerOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower
};
const struct SpriteTemplate gHydroVortexHurricaneSpriteTemplate = 
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEllipticalGust
};
const struct SpriteTemplate gHydroVortexImpactSpriteTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};

// bloom doom
const struct SpriteTemplate gBloomDoomPetalSpinSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireSpiralOutward
};
const struct SpriteTemplate gBloomDoomGreenChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gBloomDoomHurricaneSpriteTemplate = 
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEllipticalGustAttacker,
};
const struct SpriteTemplate gBloomDoomFlowerGeyserSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Geyser
};
const struct SpriteTemplate gBloomDoomGreenBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate gBloomDoomPetalStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};
const struct SpriteTemplate gBloomDoomExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// gigavolt havoc
const struct SpriteTemplate gGigavoltHavocChargingSpearSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HAVOC_SPEAR,
    .paletteTag = ANIM_TAG_HAVOC_SPEAR,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gGigavoltHavocLaunchSpearSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HAVOC_SPEAR,
    .paletteTag = ANIM_TAG_HAVOC_SPEAR,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSuperpowerFireball
};
const struct SpriteTemplate gGigavoltHavocRingsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gGigavoltHavocGeyserSpriteTemplate = 
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GeyserTarget
};

// shattered psyche
const struct SpriteTemplate gShatteredPsycheReflectHitSpriteTemplate = 
{
    .tileTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .paletteTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};
const struct SpriteTemplate gShatteredPsychePinkChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gShatteredPsycheRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// subzero slammer
const struct SpriteTemplate gSubzeroSlammerIceSpinSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimFireSpiralOutward
};
const struct SpriteTemplate gSubzeroSlammerExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSubzeroSlammerIceSwirlSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .images = NULL,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimParticleInVortex
};

// devastating drake
static const union AffineAnimCmd sDevastatingDrakeStrikePlayer[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd sDevastatingDrakeStrikeOpponent[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sDevastatingDrakeStrikeAffineAnimTable[] = {
    sDevastatingDrakeStrikePlayer,
    sDevastatingDrakeStrikeOpponent,
};
static const union AffineAnimCmd sDevastatingDrakeFlyUpAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sDevastatingDrakeFlyUpAffineAnimTable[] =  {
    sDevastatingDrakeFlyUpAffineAnims,
    sDevastatingDrakeFlyUpAffineAnims
};
static const union AffineAnimCmd sDevastatingDrakeRightAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sDevastatingDrakeRightAffineAnimTable[] = {
    sDevastatingDrakeRightAffineAnims,
    sDevastatingDrakeRightAffineAnims
};
static const union AffineAnimCmd sDevastatingDrakeLeftAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd* const sDevastatingDrakeLeftAffineAnimTable[] = {
    sDevastatingDrakeLeftAffineAnims,
    sDevastatingDrakeLeftAffineAnims,
};
const struct SpriteTemplate gDevastatingDrakePurpleEnergySpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gDevastatingDrakeShockwaveSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb
};
const struct SpriteTemplate gDevastatingDrakeDrakeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sDevastatingDrakeFlyUpAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gDevastatingDrakeRightSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sDevastatingDrakeRightAffineAnimTable,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gDevastatingDrakeLeftSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sDevastatingDrakeLeftAffineAnimTable,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gDevastatingDrakeStrikeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sDevastatingDrakeStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack
};
const struct SpriteTemplate gDevastatingDrakePurpleBlastSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlastBurnTargetPlume
};
const struct SpriteTemplate gDevastatingDrakeHexSpriteTemplate = 
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Geyser
};
const struct SpriteTemplate gDevastatingDrakeExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gDevastatingDrakeExplosion2SpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// black hole eclipse
const struct SpriteTemplate gBlackHoleEclipseShockwaveSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BLACK_BALL_2,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb
};
const struct SpriteTemplate gBlackHoleEclipseBlueRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlackHoleEclipseBlackRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlackHoleEclipseRedExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlackHoleEclipseWispSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WISP_ORB,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gAnims_WillOWispOrb,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWillOWispOrb
};
const struct SpriteTemplate gBlackHoleEclipseRedRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlackHoleEclipseBlueRingInwardsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gBlackHoleEclipseRedRingInwardsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
static const union AffineAnimCmd gGrowingBackHoleTargetAffineCmds[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 0x88),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gGrowingBlackHoleTargetAffineAnimTable[] = {
    gGrowingBackHoleTargetAffineCmds,
};
const struct SpriteTemplate gBlackHoleEclipseHoleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingBlackHoleTargetAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
static const union AffineAnimCmd gShrinkingBlackHoleAffineCmds[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0xf6, 8),
    AFFINEANIMCMD_END_ALT(1),
};
static const union AffineAnimCmd *const gShrinkingBlackHoleAffineAnimTable[] = {
    gShrinkingBlackHoleAffineCmds,
};
const struct SpriteTemplate gBlackHoleEclipseHoleShrinkSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gShrinkingBlackHoleAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
static const union AffineAnimCmd gGrowingBackHoleAffineCmds[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 0x48),
    AFFINEANIMCMD_END,
};
static const union AffineAnimCmd *const gGrowingBlackHoleAffineAnimTable[] = {
    gGrowingBackHoleAffineCmds,
};
const struct SpriteTemplate gBlackHoleEclipseHoleUserSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingBlackHoleAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gTargetTwinkleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SpinningSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TwinkleOnBattler
};

// twinkle tackle
static const union AffineAnimCmd sTwinkleTackleStarPlayerAffineAnims[] = {
    AFFINEANIMCMD_FRAME(8, 8, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0x0, 0x1e),
    AFFINEANIMCMD_END_ALT(1),
};
static const union AffineAnimCmd sTwinkleTackleStarOpponentAffineAnims[] = {
    AFFINEANIMCMD_FRAME(8, 8, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0xf),
    AFFINEANIMCMD_END_ALT(1),
};
static const union AffineAnimCmd *const sTwinkleTackleStarAffineAnimTable[] = {
    sTwinkleTackleStarPlayerAffineAnims,
    sTwinkleTackleStarOpponentAffineAnims
};
const struct SpriteTemplate gTwinkleTacklePinkStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};
const struct SpriteTemplate gTwinkleTacklePinkRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gTwinkleTackleStarGrowSpriteTemplate = 
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sTwinkleTackleStarAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gTwinkleTackleTwinkleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SpinningSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TwinkleOnBattler
};
const struct SpriteTemplate gTwinkleTackleDigStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDirtPlumeParticle
};
const struct SpriteTemplate gTwinkleTackleYellowImpactSpriteTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};
const struct SpriteTemplate gTwinkleTackleImpactStarsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDizzyPunchDuck
};

// catastrokpika
const struct SpriteTemplate gCatastrokpikaSuperpowerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &sGrowingSuperpowerOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower
};

// 10e6 volt thunderbolt
const struct SpriteTemplate g10MillionVoltBoltYellowFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate g10MillionVoltBoltShockwaveSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget,
};
const struct SpriteTemplate g10MillionVoltBoltRedBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate g10MillionVoltBoltBlueBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate g10MillionVoltBoltPinkBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate g10MillionVoltBoltYellowBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate g10MillionVoltBoltGreenBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate g10MillionVoltBoltPurpleBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};

// stoked sparksurfer
const struct SpriteTemplate gStokedSparksurferFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};

// extreme evoboost
const struct SpriteTemplate gExtremeEvoboostRedChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostPinkChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostIceChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostBlackChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostBlueChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostPurpleChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostYellowChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostGreenChargeUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gExtremeEvoboostRedChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostPinkChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostIceChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostBlackChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostBlueChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostPurpleChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostYellowChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostGreenChargeCircleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimExtremeEvoboostCircle
};
const struct SpriteTemplate gExtremeEvoboostRedStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostPinkStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostIceStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostBlackStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostBlueStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostPurpleStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostYellowStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};
const struct SpriteTemplate gExtremeEvoboostGreenStockpileSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};

// pulverizing pancake
const struct SpriteTemplate gPulverizingPancakeRedDetectSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SpinningSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpinningSparkle
};
const struct SpriteTemplate gPulverizingPancakeExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gPulverizingPancakeYellowRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// genesis supernova
const struct SpriteTemplate gGenesisSupernovaOrbRiseSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gGenesisSupernovaReversalSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimReversalOrb
};
const struct SpriteTemplate gGenesisSupernovaSpinUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gGenesisSupernovaChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gGenesisSupernovaSuperpowerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &sGrowingSuperpowerOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower
};
const struct SpriteTemplate gGenesisSupernovaBubbleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .images = NULL,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimBubbleEffect
};
const struct SpriteTemplate gGenesisSupernovaExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// sinister arrow raid
static const union AffineAnimCmd sArrowRaidFlyStrikePlayerAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd sArrowRaidFlyStrikeOpponentAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidFlyStrikeAffineAnimTable[] = {
    sArrowRaidFlyStrikePlayerAffineAnims,
    sArrowRaidFlyStrikeOpponentAffineAnims
};
static const union AffineAnimCmd sArrowRaidFlyRightAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidFlyRightAffineAnimTable[] = {
    sArrowRaidFlyRightAffineAnims,
    sArrowRaidFlyRightAffineAnims
};
static const union AffineAnimCmd sArrowRaidFlyLeftAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidFlyLeftAffineAnimTable[] = {
    sArrowRaidFlyLeftAffineAnims,
    sArrowRaidFlyLeftAffineAnims
};
const struct SpriteTemplate gArrowRaidExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gArrowRaidFlyUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate gArrowRaidFlyRightSpriteTemplate = 
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidFlyRightAffineAnimTable,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gArrowRaidFlyLeftSpriteTemplate = 
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidFlyLeftAffineAnimTable,
    .callback = AnimAssistPawprint
};
const struct SpriteTemplate gArrowRaidFlyStrikeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidFlyStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack
};
static const union AffineAnimCmd sArrowRaidArrowUpAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xa0, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidArrowUpAffineAnimTable[] = {
    sArrowRaidArrowUpAffineAnims,
};
const struct SpriteTemplate gArrowRaidArrowUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidArrowUpAffineAnimTable,
    .callback = AnimParticleInVortex
};
static const union AffineAnimCmd sArrowRaidArrowRightUpAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x75, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidArrowRightUpAffineAnimTable[] = {
    sArrowRaidArrowRightUpAffineAnims,
};
const struct SpriteTemplate gArrowRaidRightUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidArrowRightUpAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidRightDownAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidRightDownAffineAnimTable[] = {
    sArrowRaidRightDownAffineAnims,
};
const struct SpriteTemplate gArrowRaidRightDownSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidRightDownAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidArrowLeftUpAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xe0, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidLeftUpAffineAnimTable[] = {
    sArrowRaidArrowLeftUpAffineAnims,
};
const struct SpriteTemplate gArrowRaidLeftUpSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidLeftUpAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidFaceUpLeftAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xe0, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidFaceUpLeftAffineAnimTable[] = {
    sArrowRaidFaceUpLeftAffineAnims,
};
const struct SpriteTemplate gArrowRaidFaceUpLeftSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidFaceUpLeftAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidArrowFaceRightAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidArrowFaceRightAffineAnimTable[] = {
    sArrowRaidArrowFaceRightAffineAnims
};
const struct SpriteTemplate gArrowRaidRightSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidArrowFaceRightAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidLeftDownAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xd0, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidLeftDownAffineAnimTable[] = {
    sArrowRaidLeftDownAffineAnims
};
const struct SpriteTemplate gArrowRaidLeftDownSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidLeftDownAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sArrowRaidOnslaughtAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x30, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sArrowRaidOnslaughtAffineAnimTable[] = {
    sArrowRaidOnslaughtAffineAnims
};
const struct SpriteTemplate gArrowRaidArrowOnslaughtSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sArrowRaidOnslaughtAffineAnimTable,
    .callback = AnimAssistPawprint
};

// malicious moonsault
const struct SpriteTemplate gMaliciousMoonsaultRedFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate gMaliciousMoonsaultRedBounceSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_BounceBallLand,
    .callback = AnimBounceBallLand
};
const struct SpriteTemplate gMaliciousMoonsaultRedImpactSpriteTemplate = 
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic
};
const struct SpriteTemplate gMaliciousMoonsaultFireblastSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFireCross
};
const struct SpriteTemplate gMaliciousMoonsaultExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// oceanic operetta
const struct SpriteTemplate gOceanOperaSpotlightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpotlightAffineAnimTable,
    .callback = AnimOceanicOperettaSpotlight,
};
const struct SpriteTemplate gOceanOperaBlueFlareSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gOceanOperaBlueChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gOceanOperaBlueRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gOceanOperaMovingOrbsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowMistBall
};
const struct SpriteTemplate gOceanOperaBlueOrbsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBite
};
const struct SpriteTemplate gOceanOperaExpandingRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gOceanOperaExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gOceanOperaSparkleSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};

// splintered stormshards
const struct SpriteTemplate gSplinteredShardsFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate gSplinteredShardsExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSplinteredShardsRisingSpearSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAssistPawprint
};
static const union AffineAnimCmd sSplinteredShardsOpponentSteepAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xca, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSplinteredShardsOpponentSteepAffineAnimTable[] = {
    sSplinteredShardsOpponentSteepAffineAnims,
};
const struct SpriteTemplate gSplinteredShardsSplinterOpponentSteepSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSplinteredShardsOpponentSteepAffineAnimTable,
    .callback = AnimJumpKick
};
static const union AffineAnimCmd sSplinteredShardsOpponentShallowAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSplinteredShardsOpponentShallowAffineAnimTable[] = {
    sSplinteredShardsOpponentShallowAffineAnims
};
const struct SpriteTemplate gSplinteredShardsSplinterOpponentShallowSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSplinteredShardsOpponentShallowAffineAnimTable,
    .callback = AnimJumpKick
};
static const union AffineAnimCmd sSplinteredShardsPlayerSteepAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSplinteredShardsPlayerSteepAffineAnimTable[] = {
    sSplinteredShardsPlayerSteepAffineAnims
};
const struct SpriteTemplate gSplinteredShardsSplinterPlayerSteepSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSplinteredShardsPlayerSteepAffineAnimTable,
    .callback = AnimJumpKick
};
static const union AffineAnimCmd sSplinteredShardsPlayerShallowAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSplinteredShardsPlayerShallowAffineAnimTable[] = {
    sSplinteredShardsPlayerShallowAffineAnims
};
const struct SpriteTemplate gSplinteredShardsSplinterPlayerShallowSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSplinteredShardsPlayerShallowAffineAnimTable,
    .callback = AnimJumpKick
};

// lets snuggle forever
const struct SpriteTemplate gSnuggleForeverEyesSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SpinningSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpinningSparkle
};
const struct SpriteTemplate gSnuggleForeverStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDizzyPunchDuck
};
const struct SpriteTemplate gSnuggleForeverHeartSpriteTemplate = 
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMagentaHeart
};

// clangorous soulblaze
const struct SpriteTemplate gClangoorousSoulblazeWhiteFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate gClangoorousSoulblazePurpleSwirlSpriteTemplate = 
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .images = NULL,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gClangoorousSoulblazePurpleChargeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gClangoorousSoulblazePulseSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation
};

// guardian of alola 
const struct SpriteTemplate gGuardianOfAlolaFistSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimStompFoot
};
const struct SpriteTemplate gGuardianOfAlolaDirtGeyserSpriteTemplate = 
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMudSportDirt
};

// seering sunraze smash
static const union AffineAnimCmd sSearingSunrazeSmashWormholeGrowingAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0xf8, 0x88),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sSearingSunrazeSmashWormholeGrowingAffineAnimTable[] = {
    sSearingSunrazeSmashWormholeGrowingAffineAnims
};
const struct SpriteTemplate gSearingSunrazeSmashGrowWormholeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSearingSunrazeSmashWormholeGrowingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSearingSunrazeSmashBlueRingInwardsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSearingSunrazeSmashWhiteRingInwardsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSearingSunrazeSmashCrossImpactSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCrossImpact
};
const struct SpriteTemplate gSearingSunrazeSmashWhiteCutSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCuttingSlice
};
const struct SpriteTemplate gSearingSunrazeSmashInfernoOrbSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb
};
const struct SpriteTemplate gSearingSunrazeSmashShockwaveSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget
};
const struct SpriteTemplate gSearingSunrazeSmashRedFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};

// menacing moonraze maelstrom
const struct SpriteTemplate gMoonrazeMaelstromBlueBuffSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gMoonrazeMaelstromBlackBuffSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gMoonrazeMaelstromPurpleBuffSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gMoonrazeMaelstromBlackSparklesSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};
const struct SpriteTemplate gMoonrazeMaelstromBlueRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL, 
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gMoonrazeMaelstromWhiteRingSpriteTemplate = 
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL, 
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gMoonrazeMaelstromSuperpowerSpriteTemplate = 
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSuperpowerFireball
};
const struct SpriteTemplate gMoonrazeMaelstromBlackOrbsSpriteTemplate = 
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleInVortex
};
const struct SpriteTemplate gMoonrazeMaelstromBeamSpriteTemplate = 
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb
};
const struct SpriteTemplate gMoonrazeMaelstromExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gMoonrazeMaelstromShockwaveSpriteTemplate = 
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget
};
static const union AffineAnimCmd sMoonrazeMaelstromWormholeAffineAnims[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0xf6, 0x88),
    AFFINEANIMCMD_END
};
static const union AffineAnimCmd *const sMoonrazeMaelstromWormholeAffineAnimTable[] = {
    sMoonrazeMaelstromWormholeAffineAnims
};
const struct SpriteTemplate gMoonrazeMaelstromWormholeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sMoonrazeMaelstromWormholeAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// light that burns the sky
const struct SpriteTemplate gLightThatBurnsTheSkyGreenSparkSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimSparkElectricityFlashing
};
const struct SpriteTemplate gLightThatBurnsTheSkyBlastBurnSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlastBurnTargetPlume
};
static const struct OamData sGeyserOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1, //Above sprites
};
const struct SpriteTemplate gLightThatBurnsTheSkyExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &sGeyserOam,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

// soul stealing 7star strike
const struct SpriteTemplate gSoulStealBlackFlySpriteTemplate = 
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp
};
const struct SpriteTemplate gSoulStealIceBuffSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy
};
const struct SpriteTemplate gSoulStealBlueFistSpriteTemplate = 
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJumpKick
};
const struct SpriteTemplate gSoulStealBlueStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimSoulStealingStar
};
const struct SpriteTemplate gSoulStealBlueParalyzeSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimElectricity
};
const struct SpriteTemplate gSoulStealBlastburnSpriteTemplate = 
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_WISP_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFirePlume
};
const struct SpriteTemplate gSoulStealExplosionSpriteTemplate = 
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WISP_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};
const struct SpriteTemplate gSoulStealZStarSpriteTemplate = 
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCrossImpact
};

// functions
//general
void AnimTask_IsTargetPartner(u8 taskId)
{
    if (gBattleAnimTarget == (gBattleAnimAttacker ^ BIT_FLANK))
        gBattleAnimArgs[0] = 1;
    else
        gBattleAnimArgs[0] = 0;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBanksInvisible(u8 taskId)
{
    u32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        u8 spriteId = gBattlerSpriteIds[i];
        if (spriteId != 0xFF)
            gSprites[spriteId].invisible = TRUE;
    }
    DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBanksVisible(u8 taskId)
{
    u32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        u8 spriteId = gBattlerSpriteIds[i];
        if (spriteId != 0xFF)
            gSprites[spriteId].invisible = FALSE;
    }
    DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBanksInvisibleExceptAttackerAndTarget(u8 taskId)
{
    u32 i;
    for (i = 0; i < gBattlersCount; ++i)
    {
        u8 spriteId = gBattlerSpriteIds[i];
        if (spriteId == GetAnimBattlerSpriteId(ANIM_ATTACKER) || spriteId == GetAnimBattlerSpriteId(ANIM_TARGET))
            continue;
        if (spriteId != 0xFF || !IsBattlerSpriteVisible(i)) //Pokemon that are already hidden
            gSprites[spriteId].invisible = TRUE;
    }
    DestroyAnimVisualTask(taskId);
}

static u8 LoadBattleAnimTarget(u8 arg)
{
    u8 battler;
    
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        switch (gBattleAnimArgs[arg])
        {
        case 0:
            battler = gBattleAnimAttacker;
            break;
        default:
            battler = gBattleAnimTarget;
            break;
        case 2:
            battler = BATTLE_PARTNER(gBattleAnimAttacker);
            break;
        case 3:
            battler = BATTLE_PARTNER(gBattleAnimTarget);
            break;
        }
    }
    else
    {
        if (gBattleAnimArgs[arg] == 0)
            battler = gBattleAnimAttacker;
        else
            battler = gBattleAnimTarget;
    }
    
    return battler;
}

static u8 GetProperCentredCoord(u8 battler, u8 coordType)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return (GetBattlerSpriteCoord2(battler, coordType) + GetBattlerSpriteCoord2(BATTLE_PARTNER(battler), coordType)) / 2;

    return GetBattlerSpriteCoord(battler, coordType);
}

static void InitSpritePosToGivenTarget(struct Sprite* sprite, u8 target)
{
    sprite->x = GetBattlerSpriteCoord2(target, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord2(target, BATTLER_COORD_Y);

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y2 = gBattleAnimArgs[1];
}

static void InitSpritePosToAnimTargetsCentre(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y)) / 2;
    }

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

static void InitSpritePosToAnimAttackersCentre(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_X)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_Y)) / 2;
    }
    else
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X_2)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_X_2)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET)
                       +  GetBattlerSpriteCoord2(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_Y_PIC_OFFSET)) / 2;
    }

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

//sprite callbacks
static void AnimSoulStealingStar(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[4];
    sprite->data[2] = gBattleAnimArgs[5];
    sprite->callback = AnimSoulStealingStar_Step1;
}

static void AnimSoulStealingStar_Step1(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[0];
    sprite->data[5] += sprite->data[1];
    sprite->x2 = sprite->data[4] >> 8;
    sprite->y2 = sprite->data[5] >> 8;
    if (++sprite->data[3] == sprite->data[2])
        sprite->callback = AnimSoulStealingStar_Step2;
}

static void AnimSoulStealingStar_Step2(struct Sprite *sprite)
{
    sprite->data[4] -= sprite->data[0];
    sprite->data[5] -= sprite->data[1];
    sprite->x2 = sprite->data[4] >> 8;
    sprite->y2 = sprite->data[5] >> 8;
    if (--sprite->data[3] == 0)
        DestroySpriteAndMatrix(sprite);
}

//Creates The Extreme Evoboost Circles
static void AnimExtremeEvoboostCircle(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->y += 20;
    sprite->data[1] = 191;
    sprite->callback = AnimExtremeEvoboostCircle_Step;
    sprite->callback(sprite);
}

static void AnimExtremeEvoboostCircle_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], 32);
    sprite->y2 = Cos(sprite->data[1], 8);
    sprite->data[1] += 5;
    sprite->data[1] &= 0xFF;
    if (++sprite->data[0] == 71)
        DestroyAnimSprite(sprite);
}

static void AnimGrowingShockWaveOrbOnTarget(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        StartSpriteAffineAnim(sprite, 2);
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->affineAnimEnded)
            DestroySpriteAndMatrix(sprite);
        break;
    }
}

static void AnimEllipticalGustAttacker(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->y += 20;
    sprite->data[1] = 191;
    sprite->callback = AnimEllipticalGustAttacker_Step;
    sprite->callback(sprite);
}

static void AnimEllipticalGustAttacker_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], 32);
    sprite->y2 = Cos(sprite->data[1], 8);
    sprite->data[1] += 5;
    sprite->data[1] &= 0xFF;
    if (++sprite->data[0] == 71)
        DestroyAnimSprite(sprite);
}

static void SetSpriteCoordsToAnimTargetCoords(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
}

static void AnimBlastBurnTargetPlume(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimTargetCoords(sprite);
    if (GetBattlerSide(gBattleAnimTarget))
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

    sprite->callback = AnimBlastBurnTargetPlume_Step1;
}
static void AnimBlastBurnTargetPlume_Step1(struct Sprite *sprite)
{
    if (++sprite->data[0] < sprite->data[4])
    {
        sprite->x2 += sprite->data[2];
        sprite->y2 += sprite->data[3];
    }

    if (sprite->data[0] == sprite->data[1])
        DestroySpriteAndMatrix(sprite);
}

static void SpriteCB_SpriteToCentreOfSide(struct Sprite* sprite)
{
    bool8 var;

    if (!sprite->data[0])
    {
        if (!gBattleAnimArgs[3])
            var = TRUE;
        else
            var = FALSE;

        if (gBattleAnimArgs[2] == 0) //Attacker
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                InitSpritePosToAnimAttackersCentre(sprite, var);
            else
                InitSpritePosToAnimAttacker(sprite, var);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                InitSpritePosToAnimTargetsCentre(sprite, var);
            else
                InitSpritePosToAnimTarget(sprite, var);
        }

        sprite->data[0]++;
    }
    else if (sprite->animEnded || sprite->affineAnimEnded)
    {
        DestroySpriteAndMatrix(sprite);
    }
}

static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite)
{
    u8 target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, 0);
        sprite->y = GetBattlerSpriteCoord(target, 1);
        sprite->x += gBattleAnimArgs[1];
        sprite->y += gBattleAnimArgs[2];
        sprite->data[0] = 0;
        sprite->data[1] = gBattleAnimArgs[3];
        sprite->data[2] = gBattleAnimArgs[4];
        sprite->data[3] = 0;
        sprite->callback = AnimBrickBreakWall_Step;
    }
}

static void SpriteCB_ToxicThreadWrap(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimStringWrap_Step;
}


static void SpriteCB_GrowingSuperpower(struct Sprite *sprite)
{
    u8 battler;

    if (gBattleAnimArgs[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
        battler = gBattleAnimTarget;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    }
    else
    {
        battler = gBattleAnimAttacker;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    }

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        StartSpriteAffineAnim(sprite, 1);

    sprite->data[0] = 16;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(battler, 2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(battler, 3);

    InitAnimLinearTranslation(sprite);
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = AnimTranslateLinear_WithFollowup;
}

static void SpriteCB_CentredSpiderWeb(struct Sprite* sprite)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        InitSpritePosToAnimTargetsCentre(sprite, FALSE);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->callback = AnimSpiderWeb;
}

static void SpriteCB_CoreEnforcerHits(struct Sprite* sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);

    if (gBattleAnimArgs[2] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            InitSpritePosToAnimAttackersCentre(sprite, FALSE);
        else
            InitSpritePosToAnimAttacker(sprite, FALSE);
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            InitSpritePosToAnimTargetsCentre(sprite, FALSE);
        else
            InitSpritePosToAnimTarget(sprite, FALSE);
    }

    sprite->y += 20;
    sprite->callback = AnimFlashingHitSplat_Step;
}

static void SpriteCB_CoreEnforcerBeam(struct Sprite* sprite)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        AnimSolarBeamBigOrb(sprite);
    }
    else
    {
        InitSpritePosToAnimAttacker(sprite, TRUE);
        StartSpriteAnim(sprite, gBattleAnimArgs[3]);

        sprite->data[0] = gBattleAnimArgs[2];

        sprite->data[2] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2)
                        +  GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X_2)) / 2;


        sprite->data[4] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET)
                        +  GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y_PIC_OFFSET)) / 2;

        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

static void SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles(struct Sprite* sprite)
{
    bool8 v1;
    u8 target;
    u8 coordType;

    if (!(gBattleAnimArgs[5] & 0xff00))
        v1 = TRUE;
    else
        v1 = FALSE;

    if (!(gBattleAnimArgs[5] & 0xff))
        coordType = BATTLER_COORD_Y_PIC_OFFSET;
    else
        coordType = BATTLER_COORD_Y;

    InitSpritePosToAnimAttacker(sprite, v1);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    target = LoadBattleAnimTarget(6);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        sprite->data[0] = gBattleAnimArgs[4];
        sprite->data[2] = GetBattlerSpriteCoord(target, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
        sprite->data[4] = GetBattlerSpriteCoord(target, coordType) + gBattleAnimArgs[3];
        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

//Causes an object to fall from the sky.
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: speed
//arg 3: anim battler
static void SpriteCB_FallingObject(struct Sprite *sprite)
{
    u8 target = LoadBattleAnimTarget(3);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        sprite->x = GetBattlerSpriteCoord2(target, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(target, BATTLER_COORD_Y);

        sprite->x2 = gBattleAnimArgs[0];
        sprite->y = gBattleAnimArgs[1];
        sprite->y2 = -gBattleAnimArgs[1];

        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        {
            sprite->y += 45;
            sprite->y2 -= 45;
        }

        sprite->data[3] = gBattleAnimArgs[2]; //Speed
        sprite->callback = SpriteCB_FallingObjectStep;
    }
}
static void SpriteCB_FallingObjectStep(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->y2 += sprite->data[3];
        if (sprite->y2 >= 0)
        {
            sprite->y2 = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 0)
        {
            sprite->data[1] = 0;
            sprite->invisible ^= 1;
            if (++sprite->data[2] == 10)
                DestroySpriteAndMatrix(sprite);
        }
        break;
    }
}

static void SpriteCB_SunsteelStrikeRings(struct Sprite* sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x = 272;
        sprite->y = -32;
    }
    else
    {
        sprite->x = -32;
        sprite->y = -32;
    }

    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimFlyBallAttack_Step;
}

//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: target x pixel offset
//arg 3: target y pixel offset
//arg 4: duration
//arg 5: wave amplitude
static void SpriteCB_MoongeistCharge(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[2]; //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3]; //Target Y
    sprite->data[5] = gBattleAnimArgs[5];

    InitAnimArcTranslation(sprite);
    sprite->callback = AnimMissileArc_Step;
}

//Spins a sprite towards the target, pausing in the middle.
//Used in Mind Blown.
//arg 0: duration step 1 (attacker -> center)
//arg 1: duration step 2 (spin center)
//arg 2: duration step 3 (center -> target)
static void SpriteCB_MindBlownBall(struct Sprite *sprite)
{
    s16 oldPosX = sprite->x;
    s16 oldPosY = sprite->y;
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = sprite->x << 4;
    sprite->data[5] = sprite->y << 4;
    sprite->data[6] = ((oldPosX - sprite->x) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->data[7] = ((oldPosY - sprite->y) << 4) / (gBattleAnimArgs[0] << 1);
    sprite->callback = AnimMindBlownBallStep;
}
static void AnimMindBlownBallStep(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->x = sprite->data[4] >> 4;
        sprite->y = sprite->data[5] >> 4;
        sprite->data[1] -= 1;
        if (sprite->data[1] > 0)
            break;
        sprite->data[0] += 1;
        break;
    case 1:
        sprite->data[2] -= 1;
        if (sprite->data[2] > 0)
            break;

        sprite->data[1] = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[2] = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->data[4] = sprite->x << 4;
        sprite->data[5] = sprite->y << 4;
        sprite->data[6] = ((sprite->data[1] - sprite->x) << 4) / sprite->data[3];
        sprite->data[7] = ((sprite->data[2] - sprite->y) << 4) / sprite->data[3];
        sprite->data[0] += 1;
        break;
    case 2:
        sprite->data[4] += sprite->data[6];
        sprite->data[5] += sprite->data[7];
        sprite->x = sprite->data[4] >> 4;
        sprite->y = sprite->data[5] >> 4;
        sprite->data[3] -= 1;
        if (sprite->data[3] > 0)
            break;
        sprite->x = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->data[0] += 1;
        break;
    case 3:
        DestroySpriteAndMatrix(sprite);
        break;
    }
}

static void SpriteCB_MindBlownExplosion(struct Sprite* sprite)
{
    u8 a;
    u8 b;
    u16 x;
    u16 y;

    if (gBattleAnimArgs[4] == 0)
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        a = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        b = GetProperCentredCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

        sprite->data[0] = gBattleAnimArgs[4];
        if (gBattleAnimArgs[1] == 0)
        {
            sprite->x = gBattleAnimArgs[2] + a;
            sprite->y = gBattleAnimArgs[3] + b;
            sprite->data[5] = a;
            sprite->data[6] = b;
        }
        else
        {
            sprite->x = a;
            sprite->y = b;
            sprite->data[5] = gBattleAnimArgs[2] + a;
            sprite->data[6] = gBattleAnimArgs[3] + b;
        }

        x = sprite->x;
        sprite->data[1] = x * 16;
        y = sprite->y;
        sprite->data[2] = y * 16;
        sprite->data[3] = (sprite->data[5] - sprite->x) * 16 / gBattleAnimArgs[4];
        sprite->data[4] = (sprite->data[6] - sprite->y) * 16 / gBattleAnimArgs[4];

        sprite->callback = AnimNeedleArmSpike_Step;
    }
}

void SpriteCB_RandomCentredHits(struct Sprite* sprite)
{
    if (gBattleAnimArgs[1] == -1)
        gBattleAnimArgs[1] = Random() & 3;

    StartSpriteAffineAnim(sprite, gBattleAnimArgs[1]);

    if (gBattleAnimArgs[0] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            InitSpritePosToAnimAttackersCentre(sprite, FALSE);
        else
            InitSpritePosToAnimAttacker(sprite, FALSE);
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            InitSpritePosToAnimTargetsCentre(sprite, FALSE);
        else
            InitSpritePosToAnimTarget(sprite, FALSE);
    }

    sprite->x2 += (Random() % 48) - 24;
    sprite->y2 += (Random() % 24) - 12;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

//Creates a jaw that bites down and locks on the target.
//args: Idk same as bite and crunch
//arg 6: Time to hold bite for.
static void SpriteCB_LockingJaw(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[2]);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[4];
    sprite->data[2] = gBattleAnimArgs[5];
    sprite->data[6] = -gBattleAnimArgs[6];
    sprite->callback = SpriteCB_LockingJawStep;
}
static void SpriteCB_LockingJawStep(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[0];
    sprite->data[5] += sprite->data[1];
    sprite->x2 = sprite->data[4] >> 8;
    sprite->y2 = sprite->data[5] >> 8;
    if (++sprite->data[3] == sprite->data[2])
        sprite->callback = SpriteCB_LockingJawFinish;
}
static void SpriteCB_LockingJawFinish(struct Sprite *sprite)
{
    if (--sprite->data[3] <= sprite->data[6])
        DestroySpriteAndMatrix(sprite);
}

//Creates a sprite that moves left then right along the target.
//arg 0: Slice distance
//arg 1: Speed
static void SpriteCB_LeftRightSlice(struct Sprite *sprite)
{
    sprite->x2 = gBattleAnimArgs[0];
    sprite->data[0] = -gBattleAnimArgs[0]; //Slice distance
    sprite->data[1] = gBattleAnimArgs[1]; //Slice speed
    sprite->callback = SpriteCB_LeftRightSliceStep0;
}
static void SpriteCB_LeftRightSliceStep1(struct Sprite *sprite)
{
    sprite->x2 += sprite->data[1];
    if (sprite->x2 >= sprite->data[0])
        DestroyAnimSprite(sprite);
}
static void SpriteCB_LeftRightSliceStep0(struct Sprite *sprite)
{
    sprite->x2 -= sprite->data[1];
    if (sprite->x2 <= sprite->data[0])
    {
        sprite->data[0] = -sprite->data[0];
        sprite->callback = SpriteCB_LeftRightSliceStep1;
    }
}

//Creates a rock that bounces between the attacker's feet.
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: Ignore horizontal motion if TRUE. Only bounce once.
#define sVerticalTime sprite->data[0]
#define sHorizontalTime sprite->data[1]
#define sMovingBackHorizontally sprite->data[2]
static void SpriteCB_PyroBallRockBounceStep(struct Sprite* sprite)
{
    s8 initialVerticalVelocity;
    s8 initialHorizontalVelocity;
    
    if (sprite->y2 > 0) //Rock returned back down
    {
        if (gBattleAnimArgs[2] || sMovingBackHorizontally) //Finished moving from left to right
            DestroyAnimSprite(sprite);
        else
        {
            sVerticalTime = 0;
            sMovingBackHorizontally = TRUE;
        }
    }

    initialVerticalVelocity = -6;
    initialHorizontalVelocity = -1; //Starts by moving right to left

    //vi = -6
    //g = 0.25 (gravity not negative b/c go up to go closer to 0)
    //h = vi*t + 0.5g*t^2
    //t = sVerticalTime
    sprite->y2 = (initialVerticalVelocity * sVerticalTime + (1 * sVerticalTime * sVerticalTime) / 4);

    //x = vi*t
    //vi = sprite->data[2]
    //t = sHorizontalTime
    if (!gBattleAnimArgs[2])
        sprite->x2 = (initialHorizontalVelocity * sHorizontalTime);

    sVerticalTime++;

    if (sMovingBackHorizontally)
        sHorizontalTime--; //Move left to right
    else
        sHorizontalTime++; //Move right to left
}

static void InitSpritePositionForPyroBall(struct Sprite* sprite)
{
    InitSpritePosToAnimAttacker(sprite, 0);
    sprite->y += 20; //Move closer to attacker's feet

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        sprite->y += 20; //Move below the text box

}

static void SpriteCB_PyroBallRockBounce(struct Sprite* sprite)
{
    InitSpritePositionForPyroBall(sprite);
    sprite->callback = SpriteCB_PyroBallRockBounceStep;
}
#undef sVerticalTime
#undef sHorizontalTime
#undef sMovingBackHorizontally

//Launches a projectile from the attacker's feet at the target.
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: target x pixel offset
//arg 3: target y pixel offset
//arg 4: duration
//arg 5: wave amplitude
static void SpriteCB_PyroBallLaunch(struct Sprite* sprite)
{
    InitSpritePositionForPyroBall(sprite);

    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2]; //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3]; //Target Y
    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);

    sprite->callback = AnimMissileArc_Step;
}

//Throws acid at a single target.
static void SpriteCB_AcidLaunchSingleTarget(struct Sprite *sprite)
{
    s16 l1, l2;
    
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimTarget(sprite, TRUE);
    l1 = sprite->x; l2 = sprite->y;
    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = l1 + gBattleAnimArgs[4];
    sprite->data[4] = l2 + gBattleAnimArgs[5];
    sprite->data[5] = -30;
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimAcidPoisonBubble_Step;
}

//Causes acid to drip down a single target.
static void SpriteCB_AcidDripSingleTarget(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->y + sprite->data[0];

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

//Causes an object to fall from the sky.
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: anim battler
static void SpriteCB_WaterDroplet(struct Sprite *sprite)
{
    u8 target = LoadBattleAnimTarget(2);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        InitSpritePosToGivenTarget(sprite, target);
        sprite->data[1] = sprite->y; //Target's y coord

        sprite->x2 = gBattleAnimArgs[0];
        sprite->y2 = 0;

        //Put droplet at the top of the screen
        sprite->y = 15;

        sprite->callback = SpriteCB_WaterDropletDrip;
    }
}
static void SpriteCB_WaterDropletDrip(struct Sprite *sprite)
{
    sprite->data[0] = 12;
    StartSpriteAnim(sprite, 0);
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, SpriteCB_WaterDropletDrop);
}
static void SpriteCB_WaterDropletDrop(struct Sprite *sprite)
{
    sprite->y2 += 4;
    if (sprite->y2 >= sprite->data[1])
    {
        sprite->data[0] = 19;
        StartSpriteAnim(sprite, 1);
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

static void SpriteCB_AnimSpriteOnSelectedMonPos(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        u8 target = LoadBattleAnimTarget(2);

        if (!IsBattlerSpriteVisible(target))
            DestroyAnimSprite(sprite);
        else
        {
            InitSpritePosToGivenTarget(sprite, target);
            sprite->data[0]++;
        }
    }
    else if (sprite->animEnded || sprite->affineAnimEnded)
    {
        DestroySpriteAndMatrix(sprite);
    }
}

static void SpriteCB_SurroundingRing(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1) + 40;

    sprite->data[0] = 13;
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y - 72;

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

//Imitates launching a beam of light towards the sky
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: battler
//arg 3: duration
//arg 4: Anim num
//arg 5: affine anim start delay
static void SpriteCB_PhotonGeyserBeam(struct Sprite* sprite)
{
    u8 target = LoadBattleAnimTarget(2);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        InitSpritePosToGivenTarget(sprite, target);
        StartSpriteAnim(sprite, gBattleAnimArgs[4]);
        sprite->data[0] = gBattleAnimArgs[3];
        sprite->data[1] = gBattleAnimArgs[5];
        sprite->callback = SpriteCB_BeamUpStep;
    }
}
//Animates the beam of light
static void SpriteCB_BeamUpStep(struct Sprite* sprite)
{
    if (sprite->data[1]-- == 0)
        StartSpriteAffineAnim(sprite, 1);

    if (sprite->data[0]-- <= 0)
        DestroySpriteAndMatrix(sprite);
}

static void SpriteCB_CentredElectricity(struct Sprite* sprite)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        InitSpritePosToAnimTargetsCentre(sprite, FALSE);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->oam.tileNum += gBattleAnimArgs[3] * 4;

    if (gBattleAnimArgs[3] == 1)
        sprite->oam.matrixNum = 8;
    else if (gBattleAnimArgs[3] == 2)
        sprite->oam.matrixNum = 16;

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimSkyDropBallUp(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = AnimFlyBallUp_Step;
    gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)].invisible = TRUE;
}

static void SpriteCB_SearingShotRock(struct Sprite* sprite)
{
    u8 target = LoadBattleAnimTarget(4);

    if (!IsBattlerSpriteVisible(target))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        InitSpritePosToGivenTarget(sprite, target);
        StartSpriteAnim(sprite, gBattleAnimArgs[2]);
        sprite->data[0] = gBattleAnimArgs[3];
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimSpinningKickOrPunchFinish);
    }
}

static void AnimHappyHourCoinShower(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] != 0)
        SetAverageBattlerPositions(gBattleAnimAttacker, 0, &sprite->x, &sprite->y);   //coin shower on attacker
    
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

//Launches an object upwards like they were being shot from a geyser
//arg 0: null
//arg 1: initial x pixel offset
//arg 2: initial y pixel offset
static void SpriteCB_Geyser(struct Sprite* sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) + gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[1] > 0 ? 1 : -1;
    sprite->callback = AnimMudSportDirtRising;
}

//Launches an object upwards like they were being shot from a geyser
//arg 0: null
//arg 1: initial x pixel offset
//arg 2: initial y pixel offset
static void SpriteCB_GeyserTarget(struct Sprite* sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, 2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, 3) + gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[1] > 0 ? 1 : -1;
    sprite->callback = AnimMudSportDirtRising;
}

// Anim Tasks Functions
#define tSpriteId data[0]
#define tTimer data[1]
#define tInitialXPos data[2]
#define tInitialYPos data[3]
#define tSide data[4]
#define tAnimLengthTime data[5]
static const s8 sHomerunEnemyHorizontalMovement[] =
{
    3, 3, 3, 3,
    3, 3, 2, 2,
    1, 1, 1, 1,
    1, 1, 1, 1,
    0, 1, 0, 1,
    0, 1, 0, 0,
    1, 0, 0, 1,
    0, 0, 0, 1,
    0, 0, 0, 1,
};

static const s8 sHomerunEnemyVerticalMovement[] =
{
    -4, -4, -4, -4,
    -4, -3, -3, -2,
    -2, -1, -1, -1,
    -1, -1, -1, -1,
     0, -1,  0, -1,
     0, -1,  0,  0,
     0,  0, -1,  0,
     0, -1,  0,  0,
    -1,  0,  0,  0,
};

void AnimTask_TwinkleTackleLaunchStep(u8 taskId)
{
    u16 rotation;
    s16 xScale, yScale;
    struct Task* task = &gTasks[taskId];
    struct Sprite* sprite = &gSprites[task->tSpriteId];

    if (task->tTimer > task->tAnimLengthTime)
    {
        if (task->tTimer > task->tAnimLengthTime + 5) //Wait an extra few frames so the glint can be placed on the target
        {
            sprite->x = task->tInitialXPos;
            sprite->y = task->tInitialYPos;
            ResetSpriteRotScale(task->tSpriteId);
            DestroyAnimVisualTask(taskId);
        }
        else
            ++task->tTimer;
        return;
    }
    else if ((u16) task->tTimer < NELEMS(sHomerunEnemyHorizontalMovement))
    {
        s8 movement = sHomerunEnemyHorizontalMovement[task->tTimer];
        if (task->tSide == B_SIDE_PLAYER)
            movement *= -1;
        sprite->x += movement;

        movement = sHomerunEnemyVerticalMovement[task->tTimer];
        if (task->tSide == B_SIDE_PLAYER)
            movement *= -1;
        sprite->y += movement;
    }

    xScale = 0x180;
    yScale = 0x180;
    rotation = (task->tTimer << 4) + (task->tTimer << 3);

    xScale += rotation;
    yScale += rotation;
    rotation <<= 7;

    if (task->tSide == B_SIDE_OPPONENT)
        rotation *= -1;

    SetSpriteRotScale(task->tSpriteId, xScale, yScale, rotation);

    if (++task->tTimer > task->tAnimLengthTime)
        sprite->invisible = TRUE;
}

//Launches the target in Twinkle Tackle
//arg 0: Anim time
void AnimTask_TwinkleTackleLaunch(u8 taskId)
{
    struct Task* task = &gTasks[taskId];

    task->tSpriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    task->tSide = GetBattlerSide(gBattleAnimTarget);
    task->tAnimLengthTime = gBattleAnimArgs[0];
    task->tInitialXPos = gSprites[task->tSpriteId].x;
    task->tInitialYPos = gSprites[task->tSpriteId].y;
    task->tTimer = 0;
    task->func = AnimTask_TwinkleTackleLaunchStep;

    PrepareBattlerSpriteForRotScale(task->tSpriteId, ST_OAM_OBJ_NORMAL);
}
#undef tSpriteId
#undef tTimer
#undef tInitialXPos
#undef tInitialYPos
#undef tSide
#undef tAnimLengthTime

void AnimTask_GetTimeOfDay(u8 taskId)
{
    gBattleAnimArgs[0] = 0; //Daytime is default

    RtcCalcLocalTime();
    if (gLocalTime.hours >= 20 || gLocalTime.hours < 4)
        gBattleAnimArgs[0] = 1;
    else if (gLocalTime.hours >= 17 && gLocalTime.hours < 20)
        gBattleAnimArgs[0] = 2;
    
    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetLycanrocForm(u8 taskId)
{

    #ifdef POKEMON_EXPANSION
    if (GetMonData(GetIllusionMonPtr(gBattleAnimAttacker), MON_DATA_SPECIES) == SPECIES_LYCANROC_MIDNIGHT)
        gBattleAnimArgs[0] = 1;
    else
    #endif
        gBattleAnimArgs[0] = 0;
    
    gBattleAnimArgs[0] = 0;
    DestroyAnimVisualTask(taskId);
}

// Scales up the target mon sprite
// Used in Let's Snuggle Forever
// No args.
void AnimTask_GrowTarget(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
    SetSpriteRotScale(spriteId, 208, 208, 0);
    gTasks[taskId].data[0] = 120;
    gTasks[taskId].func = AnimTask_GrowStep;
}
static void AnimTask_GrowStep(u8 taskId)
{
    if (--gTasks[taskId].data[0] == -1)
    {
        u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        ResetSpriteRotScale(spriteId);
        DestroyAnimVisualTask(taskId);
    }
}

// Uses a spotlight sprite as a light mask to illuminate the attacker. The spotlight grows and shrinks.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration of fully-opened spotlight
static void AnimOceanicOperettaSpotlight(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    sprite->data[0] = gBattleAnimArgs[2];
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = TRUE;
    sprite->callback = AnimFlatterSpotlight_Step;
}

static void AnimTask_WaitAffineAnim(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    
    if (!RunAffineAnimFromTaskData(task))
        DestroyAnimVisualTask(taskId);
}

void AnimTask_SquishTarget(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    
    PrepareAffineAnimInTaskData(task, spriteId, sSquishTargetAffineAnimCmds);
    task->func = AnimTask_WaitAffineAnim;
}

void CoreEnforcerLoadBeamTarget(struct Sprite* sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2)
                    +  GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X_2)) / 2;
    sprite->data[3] = sprite->y;
    sprite->data[4] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET)
                    +  GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y_PIC_OFFSET)) / 2;
}

void AnimTask_CreateBestowItem(u8 taskId)
{
    u8 iconSpriteId = AddItemIconSprite(ANIM_TAG_ITEM_BAG, ANIM_TAG_ITEM_BAG, gLastUsedItem);

    if (iconSpriteId != MAX_SPRITES)
    {
        gSprites[iconSpriteId].oam.priority = 2;
        gSprites[iconSpriteId].callback = AnimThrowProjectile;
        ++gAnimVisualTaskCount;
    }
    DestroyAnimVisualTask(taskId);
}

//Creates purple flames that surround the target.
//No args.
void AnimTask_PurpleFlamesOnTarget(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 16;
    task->data[9] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[10] = GetBattlerYCoordWithElevation(gBattleAnimTarget);
    task->data[11] = (GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_WIDTH) / 2) + 8;
    task->data[7] = 0;
    task->data[5] = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    task->data[6] = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 2;
    task->data[3] = 0;
    task->data[4] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, (BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL));
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0x10));
    task->data[8] = 0;
    task->func = AnimTask_GrudgeFlames_Step;
}

void AnimTask_TechnoBlast(u8 taskId)
{
    if (ItemId_GetHoldEffect(gBattleMons[gBattleAnimAttacker].item) == HOLD_EFFECT_DRIVE)
        gBattleAnimArgs[0] = ItemId_GetSecondaryId(gBattleMons[gBattleAnimAttacker].item);
    else
        gBattleAnimArgs[0] = 0;
    DestroyAnimVisualTask(taskId);
}

// Z MOVES
//Creates a twinkle at the location the target was knocked too in Twinkle Tackle
static void SpriteCB_TwinkleOnBattler(struct Sprite *sprite)
{
    struct Sprite* monSprite;

    if (gBattleAnimArgs[2] == ANIM_TARGET)
        monSprite = &gSprites[GetAnimBattlerSpriteId(ANIM_TARGET)];
    else
        monSprite = &gSprites[GetAnimBattlerSpriteId(ANIM_ATTACKER)];

    sprite->x = monSprite->x;
    sprite->y = monSprite->y;
    sprite->x2 = monSprite->x2;
    sprite->y2 = monSprite->y2;
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimTask_PrimalReversion(u8 taskId)
{
    if (ItemId_GetId(gBattleMons[gBattleAnimAttacker].item) == ITEM_RED_ORB)
        gBattleAnimArgs[0] = ItemId_GetId(gBattleMons[gBattleAnimAttacker].item);
    else
        gBattleAnimArgs[0] = 0;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_ShellSideArm(u8 taskId)
{
    if (gBattleStruct->swapDamageCategory)
        gBattleAnimArgs[0] = TRUE;
    else
        gBattleAnimArgs[0] = FALSE;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_TerrainPulse(u8 taskId)
{
    if (IsBattlerTerrainAffected(gBattleAnimAttacker, STATUS_FIELD_TERRAIN_ANY))
    {
        if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
            gBattleAnimArgs[0] = TYPE_ELECTRIC;
        else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
            gBattleAnimArgs[0] = TYPE_GRASS;
        else if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
            gBattleAnimArgs[0] = TYPE_FAIRY;
        else if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
            gBattleAnimArgs[0] = TYPE_PSYCHIC;
        else //failsafe
            gBattleAnimArgs[0] = 0;
    }
    else
    {
        gBattleAnimArgs[0] = 0;
    }
    DestroyAnimVisualTask(taskId);
}
