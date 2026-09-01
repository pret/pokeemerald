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
#include "constants/pokemon.h"
#include "battle_util.h"
#include "constants/songs.h"

// function declarations
static void AnimTask_DynamaxGrowthStep(u8 taskId);
static void SpriteCB_SpriteToCentreOfSide(struct Sprite *sprite);
static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite);
static void SpriteCB_ToxicThreadWrap(struct Sprite *sprite);
static void SpriteCB_GrowingSuperpower(struct Sprite *sprite);
static void SpriteCB_CentredSpiderWeb(struct Sprite *sprite);
static void SpriteCB_CoreEnforcerHits(struct Sprite *sprite);
static void SpriteCB_CoreEnforcerBeam(struct Sprite *sprite);
static void SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles(struct Sprite *sprite);
static void SpriteCB_FallingObject(struct Sprite *sprite);
static void SpriteCB_FallingObjectStep(struct Sprite *sprite);
static void SpriteCB_SunsteelStrikeRings(struct Sprite *sprite);
static void SpriteCB_MoongeistCharge(struct Sprite *sprite);
static void SpriteCB_MindBlownBall(struct Sprite *sprite);
static void AnimMindBlownBallStep(struct Sprite *sprite);
static void SpriteCB_MindBlownExplosion(struct Sprite *sprite);
static void SpriteCB_LockingJaw(struct Sprite *sprite);
static void SpriteCB_LockingJawStep(struct Sprite *sprite);
static void SpriteCB_LockingJawFinish(struct Sprite *sprite);
static void SpriteCB_LeftRightSlice(struct Sprite *sprite);
static void SpriteCB_LeftRightSliceStep1(struct Sprite *sprite);
static void SpriteCB_LeftRightSliceStep0(struct Sprite *sprite);
static void SpriteCB_PyroBallRockBounce(struct Sprite *sprite);
static void SpriteCB_PyroBallLaunch(struct Sprite *sprite);
static void SpriteCB_AcidLaunchSingleTarget(struct Sprite *sprite);
static void SpriteCB_AcidDripSingleTarget(struct Sprite *sprite);
static void SpriteCB_WaterDroplet(struct Sprite *sprite);
static void SpriteCB_WaterDropletDrip(struct Sprite *sprite);
static void SpriteCB_WaterDropletDrop(struct Sprite *sprite);
static void SpriteCB_AnimSpriteOnSelectedMonPos(struct Sprite *sprite);
static void SpriteCB_SurroundingRing(struct Sprite *sprite);
static void SpriteCB_PhotonGeyserBeam(struct Sprite *sprite);
static void SpriteCB_BeamUpStep(struct Sprite *sprite);
static void SpriteCB_CentredElectricity(struct Sprite *sprite);
static void AnimSkyDropBallUp(struct Sprite *sprite);
static void SpriteCB_SearingShotRock(struct Sprite *sprite);
static void AnimHappyHourCoinShower(struct Sprite *sprite);
static void SpriteCB_Geyser(struct Sprite *sprite);
static void SpriteCB_GeyserTarget(struct Sprite *sprite);
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
static void SpriteCB_PowerShiftBallStep(struct Sprite *sprite);
static void SpriteCB_PowerShiftBall(struct Sprite* sprite);
static void SpriteCB_HorizontalSliceStep(struct Sprite *sprite);
static void SpriteCB_HorizontalSlice(struct Sprite *sprite);
static void SpriteCB_LashOutStrike(struct Sprite* sprite);
static void AnimTask_TwinkleTackleLaunchStep(u8 taskId);
static void SpriteCB_AnimSpriteOnTargetSideCentre(struct Sprite *sprite);
static void SpriteCB_SpriteOnMonUntilAffineAnimEnds(struct Sprite* sprite);
static void SpriteCB_MoveSpriteUpwardsForDurationStep(struct Sprite* sprite);
static void SpriteCB_MoveSpriteUpwardsForDuration(struct Sprite* sprite);
static void SpriteCB_SpriteOnMonForDurationUseY(struct Sprite *sprite);
static void SpriteCB_SurgingStrikes(struct Sprite* sprite);
static void SpriteCB_SteelRoller_Down(struct Sprite *sprite);
static void SpriteCB_SteelRoller_LeftRight(struct Sprite* sprite);
static void SpriteCB_SteelRoller(struct Sprite* sprite);
static void SpriteCB_FlippableSlash(struct Sprite* sprite);
static void SpriteCB_DragonEnergyShot(struct Sprite* sprite);
static void SpriteCB_MaxFlutterbyStep1(struct Sprite* sprite);
static void SpriteCB_MaxFlutterbyStep2(struct Sprite* sprite);
static void SpriteCB_MaxFlutterby(struct Sprite* sprite);
static void SpriteCB_GlacialLance_Step1(struct Sprite* sprite);
static void SpriteCB_GlacialLance_Step2(struct Sprite* sprite);
static void SpriteCB_GlacialLance(struct Sprite* sprite);
static void SpriteCB_TripleArrowKick(struct Sprite* sprite);
static void SpriteCB_Protect(struct Sprite* sprite);

// const data
// general
static const union AffineAnimCmd sSquishTargetAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 64, 0, 16), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 64),
    AFFINEANIMCMD_FRAME(0, -64, 0, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSquishTargetShortAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 64, 0, 4), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -64, 0, 4),
    AFFINEANIMCMD_END,
};

// GEN 4
// Shadow Sneak
const struct SpriteTemplate gShadowSneakImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle,
};

// Power Trick
const struct SpriteTemplate gPowerTrickSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_TRICK,
    .paletteTag = ANIM_TAG_POWER_TRICK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration,
};


// GEN 5
// Shell Smash
const struct SpriteTemplate gShellSmashLeftShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHELL_RIGHT,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_Bite,
    .callback = SpriteCB_LockingJaw,
};

const struct SpriteTemplate gShellSmashRightShellSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHELL_LEFT,
    .paletteTag = ANIM_TAG_SHELL_LEFT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_Bite,
    .callback = SpriteCB_LockingJaw,
};

const struct SpriteTemplate gShellSmashPurpleRocksSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .callback = AnimRockFragment,
};

// Wide Guard
const struct SpriteTemplate gWideGuardBlueConversionTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion,
};

// Guard Split
const struct SpriteTemplate gGuardSwapOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb,
};

const struct SpriteTemplate gGuardSwapOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc,
};

// Power Split
const struct SpriteTemplate gPowerSplitOrbs1Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMimicOrb,
};

const struct SpriteTemplate gPowerSplitOrbs2Template =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimMissileArc,
};

// Automotize
const struct SpriteTemplate gAutotomizeMetalShardsTemplate =
{
    .tileTag = ANIM_TAG_METAL_BITS,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop,
};

// Rage Powder
const struct SpriteTemplate gRagePowderRedPowderTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .callback = AnimSporeParticle,
};

// Flame Charge
const struct SpriteTemplate gFlameChargeEmberTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .callback = AnimPetalDanceBigFlower,
};

// Final Gambit
const struct SpriteTemplate gFinalGambitBlueYawnTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gFinalGambitExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Synchronoise
const struct SpriteTemplate gSynchronoiseVioletRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing,
};

const struct SpriteTemplate gSynchronoiseYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing,
};

const struct SpriteTemplate gSynchronoiseBlueRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing,
};

const struct SpriteTemplate gSynchronoiseAeroWheelTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gAffineAnims_AirWaveCrescent,
    .callback = AnimFireSpread,
};

// Electro Ball
const struct SpriteTemplate gElectroBallCannonBallTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

// Foul Play
const struct SpriteTemplate gFoulPlayImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gFoulPlayRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Simple Beam
const struct SpriteTemplate gSimpleBeamBrownTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gSimpleBeamPinkTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gSimpleBeamBrownRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gSimpleBeamPinkRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

// After You
const struct SpriteTemplate gAfterYouGreenRageTemplate =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAngerMarkAffineAnimTable,
    .callback = AnimAngerMark,
};

// Quick Guard
const struct SpriteTemplate gQuickGuardArmImpactTemplate =
{
    .tileTag = ANIM_TAG_QUICK_GUARD_HAND,
    .paletteTag = ANIM_TAG_QUICK_GUARD_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimBasicFistOrFoot,
};

// Sky Drop
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
    .affineAnims = sSkyDropFlyBallAffineAnimCmds,
    .callback = AnimThrowMistBall,
};

const struct SpriteTemplate gSkyDropTargetFlyingTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROUND_SHADOW,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimSkyDropBallUp,
};

// Shift Gear
const struct SpriteTemplate gShiftGearGearsTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration,
};

// Circle Throw
const struct SpriteTemplate gCircleThrowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Quash
const struct SpriteTemplate gQuashArmHitTemplate =
{
    .tileTag = ANIM_TAG_ASSURANCE_HAND,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimStompFoot,
};

// Reflect Type
const struct SpriteTemplate gReflectTypeBlueStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .callback = SpriteCB_ToxicThreadWrap,
};

const struct SpriteTemplate gReflectTypeVioletStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .callback = SpriteCB_ToxicThreadWrap,
};

const struct SpriteTemplate gReflectTypeWhiteStringTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineOff_ObjBlend_64x32,
    .callback = SpriteCB_ToxicThreadWrap,
};

const struct SpriteTemplate gReflectTypeWhiteRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

const struct SpriteTemplate gReflectTypePinkRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

const struct SpriteTemplate gReflectTypeVioletRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

const struct SpriteTemplate gReflectTypeBlueRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

// Frost Breath
const struct SpriteTemplate gFrostBreathBlueRageTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .callback = AnimDragonRageFirePlume,
};

const struct SpriteTemplate gFrostBreathBlueBreathTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonRageFire,
    .affineAnims = gAffineAnims_DragonRageFire,
    .callback = AnimDragonFireToTarget,
};

// Heart Stamp
const struct SpriteTemplate gHeartStampSpinningHeartTemplate =
{
    .tileTag = ANIM_TAG_HEART_STAMP,
    .paletteTag = ANIM_TAG_HEART_STAMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .affineAnims = gAffineAnims_SpinningHandOrFoot,
    .callback = AnimSpinningKickOrPunch,
};

// Horn Leech
const struct SpriteTemplate gHornLeechHornTemplate =
{
    .tileTag = ANIM_TAG_HORN_LEECH,
    .paletteTag = ANIM_TAG_HORN_LEECH,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimShadowBall,
};

// Dual Chop
const struct SpriteTemplate gDualChopImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Sacred Sword
const struct SpriteTemplate gSacredSwordBladesTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .callback = AnimFireSpread,
};

const struct SpriteTemplate gSacredSwordCutTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .callback = AnimCuttingSlice,
};

// Razor Shell
const struct SpriteTemplate gRazorShellTemplate =
{
    .tileTag = ANIM_TAG_RAZOR_SHELL,
    .paletteTag = ANIM_TAG_RAZOR_SHELL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_SpriteOnMonForDuration,
};

// Heat Crash
const struct SpriteTemplate gHeatCrashEruptionRockTemplate =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimStompFoot,
};

// Leaf Tornado
const struct SpriteTemplate gLeafTornadoVortexTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimParticleInVortex,
};

// Cotton Guard
const struct SpriteTemplate gCottonGuardSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

// Night Daze
const struct SpriteTemplate gNightDazeVioletRingsTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gNightDazeVioletCirclesTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitScatter,
};

// Tail Slap
const struct SpriteTemplate gTailSlapTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gScratchAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Gear Grind
const struct SpriteTemplate gGearGrindTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimBite,
};

// Searing Shot
const struct SpriteTemplate gSearingShotRedChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gSearingShotEruptionRockTemplate =
{
    .tileTag = ANIM_TAG_WARM_ROCK,
    .paletteTag = ANIM_TAG_WARM_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimOverheatFlame,
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
    .affineAnims = sSpriteAffineAnimTable_SearingShotRock,
    .callback = SpriteCB_SearingShotRock,
};

// Techno Blast
const struct SpriteTemplate gTechnoBlastWhiteChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gTechnoBlastWhiteCircleTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gTechnoBlastWhiteBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gTechnoBlastWhiteSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gTechnoBlastWhiteSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTechnoBlastYellowBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gTechnoBlastYellowSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gTechnoBlastYellowSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTechnoBlastBlueChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gTechnoBlastBlueBubbleTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .callback = AnimSmallBubblePair,
};

const struct SpriteTemplate gTechnoBlastBlueBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gTechnoBlastBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gTechnoBlastBlueSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTechnoBlastRedChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gTechnoBlastRedBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gTechnoBlastRedSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gTechnoBlastRedSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTechnoBlastIceChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gTechnoBlastIceBlastTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL_2,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gTechnoBlastIceSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gTechnoBlastIceSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTechnoBlastIceCrystalsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Secret Sword
const struct SpriteTemplate gSecretSwordBladesTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .callback = AnimFireSpread,
};

// Glaciate
const struct SpriteTemplate gGlaciateSmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .callback = AnimBlackSmoke,
};

// Blue Flare
const struct SpriteTemplate gBlueFlareFlameJabTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gBlueFlareFlameSwirlTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gBlueFlareBurnTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_METAL_BITS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlamethrowerFlame,
    .callback = AnimFireSpread,
};

// Freeze Shock
const struct SpriteTemplate gFreezeShockCircleTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb,
};

const struct SpriteTemplate gFreezeShockIceBallTemplate =
{
    .tileTag = ANIM_TAG_ICE_CHUNK,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_IceBallChunk,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

// Ice Burn
const struct SpriteTemplate gIceBurnSmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .callback = AnimBlackSmoke,
};

// Icicle Crash
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
    .affineAnims = sSpriteAffineAnimTable_IcicleCrash,
    .callback = AnimFallingRock,
};

//V-create
const struct SpriteTemplate gVCreateFlameTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gVCreateRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gVCreateRedOrbTemplate =
{
    .tileTag = ANIM_TAG_ECLIPSING_ORB,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gEclipsingOrbAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Fusion Flare
const struct SpriteTemplate gFusionFlareRedBallUpTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimWeatherBallUp,
};

const struct SpriteTemplate gFusionFlareRedBallTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimStompFoot,
};

const struct SpriteTemplate gFusionFlareRedBubblesTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_WaterPulseBubble,
    .callback = AnimWaterPulseBubble,
};

const struct SpriteTemplate gFusionFlareRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

// Fusion Bolt
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

static const union AffineAnimCmd* const sAffineAnimCmdTable_DrakeStriking[] =  // Devestating Drake, Fusion Bolt
{
    sSpriteAffineAnim_DrakeStrikePlayer,
    sSpriteAffineAnim_DrakeStrikeOpponent,
};

const struct SpriteTemplate gFusionBoltBallTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sAffineAnimCmdTable_DrakeStriking,
    .callback = AnimFlyBallAttack,
};

// GEN 6
// Mat Block
const struct SpriteTemplate gMatBlockGreenConversionTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_GREEN_LIGHT_WALL,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion,
};

// Belch
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
    .callback = AnimMissileArc,
};

// Forest's curse
const struct SpriteTemplate gForestsCurseIngrainTemplate =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gIngrainRootAnimTable,
    .callback = AnimWaterPulseBubble,
};

// Petal Blizzard
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
    .callback = AnimMoveTwisterParticle,
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
    .callback = AnimMoveTwisterParticle,
};

// Crafty Shield
const struct SpriteTemplate gCraftyShieldPinkConversionTemplate =
{
    .tileTag = ANIM_TAG_CRAFTY_SHIELD,
    .paletteTag = ANIM_TAG_CRAFTY_SHIELD,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion,
};

// Grassy Terrain
const struct SpriteTemplate gGrassyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gGrassyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .callback = AnimOrbitScatter,
};

// Misty Terrain
const struct SpriteTemplate gMistyTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gMistyTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .callback = AnimOrbitScatter,
};

// Electrify
const struct SpriteTemplate gElectrifyRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

const struct SpriteTemplate gElectrifyYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

// Fairy Wind
const struct SpriteTemplate gFairyWindCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gSwiftStarAffineAnimTable,
    .callback = AnimTranslateLinearSingleSineWave,
};

// Confide
const struct SpriteTemplate gConfideBubbleTemplate =
{
    .tileTag = ANIM_TAG_CONFIDE,
    .paletteTag = ANIM_TAG_CONFIDE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gMetronomeThroughtBubbleAnimTable,
    .callback = AnimThoughtBubble,
};

// Diamond Storm
const struct SpriteTemplate gDiamondStormSwirlingIceTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_Snowball,
    .callback = AnimSwirlingSnowball_Step1,
};

const struct SpriteTemplate gDiamondStormBlizzardTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gAnims_BlizzardIceCrystal,
    .callback = AnimMoveParticleBeyondTarget,
};

const struct SpriteTemplate gDiamondStormDiamondsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .affineAnims = gAffineAnims_BasicRock,
    .callback = AnimMoveTwisterParticle,
};

// Steam Eruption
const struct SpriteTemplate gSteamEruptionBreathTemplate =
{
    .tileTag = ANIM_TAG_STEAM_ERUPTION,
    .paletteTag = ANIM_TAG_STEAM_ERUPTION,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_DragonBreathFire,
    .affineAnims = gAffineAnims_DragonBreathFire,
    .callback = AnimDragonFireToTarget,
};

// Hyperspace Hole
const struct SpriteTemplate gHyperspaceHoleImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle,
};

// Water Shuriken
const struct SpriteTemplate gWaterShurikenStarTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gWaterShurikenRingTemplate =
{
    .tileTag = ANIM_TAG_BLUE_RING_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .affineAnims = gWaterPulseRingAffineAnimTable,
    .callback = AnimWaterPulseRing,
};

const struct SpriteTemplate gWaterShurikenImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Eerie Impulse
const struct SpriteTemplate gEerieImpulseRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing,
};

const struct SpriteTemplate gEerieImpulseImpactTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .callback = AnimGrantingStars,
};

// Venom Drench
const struct SpriteTemplate gVenomDrenchAcidTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .callback = AnimFallingRock,
};

// Powder
const struct SpriteTemplate gPowderBlackSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .callback = AnimSporeParticle,
};

// Geomancy
const struct SpriteTemplate gGeomancyRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

const struct SpriteTemplate gGeomancyYellowRageTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .callback = AnimDragonRageFirePlume,
};

const struct SpriteTemplate gGeomancyRedCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gGeomancyGreenCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gGeomancyBlueCellVortexTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gGeomancyRedCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimRaiseSprite,
};

const struct SpriteTemplate gGeomancyGreenCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimRaiseSprite,
};

const struct SpriteTemplate gGeomancyBlueCellRaiseTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimRaiseSprite,
};

// Magnetic Flux
const struct SpriteTemplate gMagneticFluxUproarTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

// Happy Hour
const struct SpriteTemplate gHappyHourCoinShowerTemplate =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gCoinAnimTable,
    .callback = AnimHappyHourCoinShower,
};

// Electric Terrain
const struct SpriteTemplate gElectricTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gElectricTerrainFlyingBallTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .callback = AnimOrbitScatter,
};

// Celebrate
const struct SpriteTemplate gCelebrateBagTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimFollowMeFinger,
};

// Hold Hands
const struct SpriteTemplate gHoldHandsHeartTemplate =
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimPetalDanceBigFlower,
};

// Hold Back
const struct SpriteTemplate gHoldBackSwipeTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_SWIPE,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = gAnims_RevengeBigScratch,
    .callback = AnimRevengeScratch,
};

const struct SpriteTemplate gHoldBackRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gHoldBackStarsTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDizzyPunchDuck,
};

// Infestation
const struct SpriteTemplate gInfestationBubbleTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_WaterPulseBubble,
    .callback = AnimParticleInVortex,
};

// Oblivion Wing
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
    .affineAnims = sSpriteAffineAnimTable_GrowingRing,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

// Thousand Arrows
const struct SpriteTemplate gThousandArrowsGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gThousandArrowsGreenHexTemplate =
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = SpriteCB_Geyser,
};

const struct SpriteTemplate gThousandArrowsGreenArrowTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimMudSportDirt,
};

const struct SpriteTemplate gThousandArrowsGreenDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .callback = AnimElectricPuff,
};

// Thousand Waves
const struct SpriteTemplate gThousandWavesGreenWaveTemplate =
{
    .tileTag = ANIM_TAG_FLYING_DIRT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .callback = AnimFlyingSandCrescent,
};

const struct SpriteTemplate gThousandWavesGreenRecoverTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gThousandWavesGreenWheelTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimDragonDanceOrb,
};

const struct SpriteTemplate gThousandWavesRotatingImpactTemplate =
{
    .tileTag = ANIM_TAG_ZYGARDE_HEXES,
    .paletteTag = ANIM_TAG_ZYGARDE_HEXES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gThousandWavesPoundImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatOnMonEdge,
};

// Land's Wrath
const struct SpriteTemplate gLandsWrathVortexTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

// Light of Ruin
const struct SpriteTemplate gLightOfRuinPinkOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gLightOfRuinPinkDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .callback = AnimElectricPuff,
};

const struct SpriteTemplate gLightOfRuinPinkExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Origin Pulse
const struct SpriteTemplate gOriginPulseRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gOriginPulseOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimDragonDanceOrb,
};

const struct SpriteTemplate gOriginPulseOrbInwardTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gOriginPulseBlueImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom,
};

const struct SpriteTemplate gOriginPulseBasicSplatTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Precipice Blades
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
    .callback = SpriteCB_SpriteOnMonForDuration,
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
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_SpriteOnMonForDuration,
};

const struct SpriteTemplate gPrecipiceBladesPlumeTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DragonRageFirePlume,
    .callback = SpriteCB_AnimSpriteOnSelectedMonPos,
};

// Dragon Ascent
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
    .affineAnims = sAffineAnimCmdTable_DrakeFaceNorth,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gDragonAscentDrakeTemplate =
{
    .tileTag = ANIM_TAG_DRAGON_ASCENT,
    .paletteTag = ANIM_TAG_DRAGON_ASCENT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sAffineAnimCmdTable_DrakeStriking,
    .callback = AnimFlyBallAttack,
};

// Hyperspace Fury
const struct SpriteTemplate gHyperspaceFuryRingTemplate =
{
    .tileTag = ANIM_TAG_HOOPA_RING,
    .paletteTag = ANIM_TAG_HOOPA_RING,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gHyperspaceFuryHandTemplate =
{
    .tileTag = ANIM_TAG_HOOPA_HAND,
    .paletteTag = ANIM_TAG_HOOPA_HAND,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gHyperspaceFuryImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom,
};

// GEN 7
// First Impression
const struct SpriteTemplate gFirstImpressionPoundTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Baneful Bunker
const struct SpriteTemplate gBanefulBunkerPoisonBubbleTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .callback = AnimSmallBubblePair,
};

// Spirit Shackle
const struct SpriteTemplate gSpiritShackleArrowTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimTranslateStinger,
};

// Darkest Lariat
const struct SpriteTemplate gDarkestLariatImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Sparklig Aria
const struct SpriteTemplate gSparklingAriaBlueChargeTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gSparklingAriaRainTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .callback = AnimMudSportDirt,
};

const struct SpriteTemplate gSparklingAriaBubbleRainTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .callback = AnimMudSportDirt,
};

const struct SpriteTemplate gSparklingAriaBubblesTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gAnims_WaterBubbleProjectile,
    .callback = AnimSmallBubblePair,
};

// Ice Hammer
const struct SpriteTemplate gIceHammerPunchStompTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimStompFoot,
};

const struct SpriteTemplate gIceHammerSmokesTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .callback = AnimBlackSmoke,
};

// Floral Healing
const struct SpriteTemplate gFloralHealingFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .callback = AnimSporeParticle,
};

const struct SpriteTemplate gFloralHealingOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gFloralHealingLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gFloralHealingWindLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimSweetScentPetal,
};

// High Horsepower
const struct SpriteTemplate gHighHorsepowerHorseshoeTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .affineAnims = gAffineAnims_MegaPunchKick,
    .callback = AnimSpinningKickOrPunch,
};

// Strength Sap
const struct SpriteTemplate gStrengthSapRedSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gStrengthSapRedInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimTealAlert,
};

const struct SpriteTemplate gStrengthSapAbsorbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gAbsorptionOrbAffineAnimTable,
    .callback = AnimAbsorptionOrb,
};

// Solar Blade
const struct SpriteTemplate gSolarBladeImpactTemplate =
{
    .tileTag = ANIM_TAG_CLAW_SLASH,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ClawSlash,
    .callback = AnimClawSlash,
};

// Leafage
const struct SpriteTemplate gLeafageImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Toxic Thread
const struct SpriteTemplate gToxicThreadString =
{
    .tileTag = ANIM_TAG_STRING,
    .paletteTag = ANIM_TAG_STRING,
    .oam = &gOamData_AffineOff_ObjNormal_64x32,
    .callback = SpriteCB_ToxicThreadWrap,
};

// Laser Focus
const struct SpriteTemplate gLaserFocusRedEyesTemplate =
{
    .tileTag = ANIM_TAG_OPENING_EYE,
    .paletteTag = ANIM_TAG_EYE_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOpeningEyeAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Gear Up
const struct SpriteTemplate gGearUpGearsTemplate =
{
    .tileTag = ANIM_TAG_GEAR,
    .paletteTag = ANIM_TAG_GEAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimPetalDanceBigFlower,
};

// Throat Chop
const struct SpriteTemplate gThroatChopRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Pollen Puff
const struct SpriteTemplate gPollenPuffPinkStarTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .callback = AnimSmallBubblePair,
};

const struct SpriteTemplate gPollenPuffPinkSparkleTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gPollenPuffYellowSparkleTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gPollenPuffSporeTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .callback = AnimThrowProjectile,
};

const struct SpriteTemplate gPollenPuffImpactTemplates =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPollenPuffHealTemplate =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gHealingBlueStarAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Anchor Shot
const struct SpriteTemplate gAnchorShotAnchorTemplate =
{
    .tileTag = ANIM_TAG_ANCHOR,
    .paletteTag = ANIM_TAG_CHAIN_LINK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimBlockX,
};

const struct SpriteTemplate gAnchorShotAngledAnchorTemplate =
{
    .tileTag = ANIM_TAG_ANCHOR,
    .paletteTag = ANIM_TAG_CHAIN_LINK,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

// Psychic Terrain
const struct SpriteTemplate gPsychicTerrainOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gPsychicTerrainStarTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .callback = AnimOrbitScatter,
};

// Lunge
const struct SpriteTemplate gLungeGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gAffineAnims_PsychoBoostOrb,
    .callback = AnimPsychoBoost,
};

const struct SpriteTemplate gLungeGreenBubbleTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimThrowProjectile,
};

const struct SpriteTemplate gLungeGreenImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Power Trip
const struct SpriteTemplate gPowerTripFocusEnergyTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gPowerTripImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Burn Up
const struct SpriteTemplate gBurnUpRedYawnTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimThrowMistBall,
};

// Speed Swap
const struct SpriteTemplate gSpeedSwapRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSpeedSwapCircleTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMimicOrb,
};

const struct SpriteTemplate gSpeedSwapOrbMissileTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMissileArc,
};

const struct SpriteTemplate gSpeedSwapOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimNeedleArmSpike,
};

// Smart Strike
const struct SpriteTemplate gSmartStrikeGemTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gSmartStrikeImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_FLASH_CANNON_BALL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Purify
const struct SpriteTemplate gPurifyWhiteBallTemplate =
{
    .tileTag = ANIM_TAG_FLASH_CANNON_BALL,
    .paletteTag = ANIM_TAG_FLASH_CANNON_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimMissileArc,
};

const struct SpriteTemplate gPurifySmokeTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .callback = AnimBlackSmoke,
};

// Revelation Dance
const struct SpriteTemplate gRevelationDanceYellowOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimPetalDanceBigFlower,
};

const struct SpriteTemplate gRevelationDanceYellowFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gPetalDanceSmallFlowerAnimTable,
    .callback = AnimPetalDanceSmallFlower,
};

const struct SpriteTemplate gRevelationDanceYellowAirWaveTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .callback = AnimSonicBoomProjectile,
};

const struct SpriteTemplate gRevelationDanceYellowImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gRevelationDanceYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gRevelationDanceYellowDispersalTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = AnimFireSpread,
};

// Core Enforcer
const struct SpriteTemplate gCoreEnforcerBlueRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gCoreEnforcerYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gCoreEnforcerGreenRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gCoreEnforcerCircleChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimFlashingHitSplat,
};

const struct SpriteTemplate gCoreEnforcerBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimSparkElectricity,
};

const struct SpriteTemplate gCoreEnforcerGreenChargeTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimSparkElectricity,
};

const struct SpriteTemplate gCoreEnforcerSnoreTemplate =
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .callback = SpriteCB_CentredSpiderWeb,
};

const struct SpriteTemplate gCoreEnforcerImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_CoreEnforcerHits,
};

const struct SpriteTemplate gCoreEnforcerBeamTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = SpriteCB_CoreEnforcerBeam,
};

const struct SpriteTemplate gCoreEnforcerExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = SpriteCB_SpriteToCentreOfSide,
};

// Trop Kick
const struct SpriteTemplate gTropKickGreenFootTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimJumpKick,
};

const struct SpriteTemplate gTropKickFlowerTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .callback = AnimFireSpread,
};

const struct SpriteTemplate gTropKickLeavesTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = AnimFireSpread,
};

// Clanging Scales
const struct SpriteTemplate gClangingScalesPurpleMetalSoundTemplate =
{
    .tileTag = ANIM_TAG_METAL_SOUND_WAVES,
    .paletteTag = ANIM_TAG_METAL_SOUND_WAVES,
    .oam = &gOamData_AffineDouble_ObjNormal_32x64,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles,
};

// Brutal Swing
const struct SpriteTemplate gBrutalSwingRandomImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatRandom,
};

const struct SpriteTemplate gBrutalSwingBasicImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Aurora Veil
const struct SpriteTemplate gAuroraVeilRingTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

// Shell Trap
const struct SpriteTemplate gShellTrapYellowImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gShellTrapRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gShellTrapFireHitsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_Snowball,
    .callback = AnimMoveParticleBeyondTarget,
};

// Fleur Cannon
const struct SpriteTemplate gFleurCannonOrbTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gFleurCannonDischargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRICITY,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ElectricPuff,
    .callback = AnimElectricPuff,
};

// Stomping Tantrum
const struct SpriteTemplate gStompingTantrumRockTemplate =
{
    .tileTag = ANIM_TAG_SMALL_ROCK,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop,
};

// Prismatic Laser
const struct SpriteTemplate gPrismaticLaserChargeTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gPrismaticLaserYellowOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserGreenOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserRedOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserVioletOutwardTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserYellowInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserGreenInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserRedInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserVioletInwardTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gPrismaticLaserYellowRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_FallingObject,
};

const struct SpriteTemplate gPrismaticLaserGreenRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_FallingObject,
};

const struct SpriteTemplate gPrismaticLaserRedRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_FallingObject,
};

const struct SpriteTemplate gPrismaticLaserVioletRainTemplate =
{
    .tileTag = ANIM_TAG_NEEDLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_FallingObject,
};

// Spectral Thief
const struct SpriteTemplate gSpectralThiefBlackSmokeTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSpectralThiefThiefImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle,
};

const struct SpriteTemplate gSpectralThiefBlackOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMimicOrb,
};

const struct SpriteTemplate gSpectralThiefBlackBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

// Sunsteeel Strike
const struct SpriteTemplate gSunsteelStrikeBlackFlyBallTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

// Protect
const struct SpriteTemplate gProtectTemplate =
{
    .tileTag = ANIM_TAG_PROTECT,
    .paletteTag = ANIM_TAG_PROTECT,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .callback = SpriteCB_Protect
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
    .affineAnims = sSpriteAffineAnimTable_SunsteelStrikeBlast,
    .callback = AnimFlyBallAttack,
};

const struct SpriteTemplate gSunsteelStrikeRedBeamTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .affineAnims = gAffineAnims_FlyBallAttack,
    .callback = SpriteCB_SunsteelStrikeRings,
};

const struct SpriteTemplate gSunsteelStrikeYellowBeamTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_GOLD_RING,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .affineAnims = gAffineAnims_FlyBallAttack,
    .callback = SpriteCB_SunsteelStrikeRings,
};

const struct SpriteTemplate gSunsteelStrikeRedImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gSunsteelStrikeRocksTemplate =
{
    .tileTag = ANIM_TAG_SMALL_ROCK,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimTearDrop,
};

// Moongeist Beam
const struct SpriteTemplate gMoongeistBeamBlueOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gMoongeistBeamPurpleOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gMoongeistBeamChargeTemplate =
{
    .tileTag = ANIM_TAG_ELECTRIC_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_ElectricChargingParticles,
    .callback = SpriteCB_MoongeistCharge,
};

// Zing Zap
const struct SpriteTemplate gZingZapYellowBallTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_SPARK_H,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gZingZapRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

// Nature's Madness
const struct SpriteTemplate gNaturesMadnessPinkStarsTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .callback = AnimSmallBubblePair,
};

const struct SpriteTemplate gNaturesMadnessCrystalsTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gAnims_SmallBubblePair,
    .callback = AnimSmallBubblePair,
};

const struct SpriteTemplate gNaturesMadnessPinkRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gNaturesMadnessGrayRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Mind Blown
const struct SpriteTemplate gMindBlownHeadTemplate =
{
    .tileTag = ANIM_TAG_BLACEPHALON_HEAD,
    .paletteTag = ANIM_TAG_BLACEPHALON_HEAD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_MindBlownBall,
};

const struct SpriteTemplate gMindBlownBlueOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = SpriteCB_MindBlownExplosion,
};

const struct SpriteTemplate gMindBlownPinkOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .callback = SpriteCB_MindBlownExplosion,
};

const struct SpriteTemplate gMindBlownBlueImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_RandomCentredHits,
};

const struct SpriteTemplate gMindBlownPinkImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = SpriteCB_RandomCentredHits,
};

// Plasma Fists
const struct SpriteTemplate gPlasmaFistsChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SHOCK_3,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

// Photon Geyser
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
    .affineAnims = sSpriteAffineAnimTable_PhotonGeyserBeam,
    .callback = SpriteCB_PhotonGeyserBeam,
};

const struct SpriteTemplate gPhotonGeyserChargeTemplate =
{
    .tileTag = ANIM_TAG_SHOCK_3,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_ThunderboltOrb,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gPhotonGeyserSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimSparkElectricity,
};

const struct SpriteTemplate gPhotonGeyserZapCannonSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimZapCannonSpark,
};

const struct SpriteTemplate gPhotonGeyserWhiteRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gPhotonGeyserYellowRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const struct SpriteTemplate gPhotonGeyserZapBallTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_BALL,
    .paletteTag = ANIM_TAG_YELLOW_BALL,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};


// GEN 8
// Snipe Shot
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

const struct SpriteTemplate gSnipeShotBallTemplate =    //used in Aura Sphere
{
    .tileTag = ANIM_TAG_IMPACT_2,
    .paletteTag = ANIM_TAG_IMPACT_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnimCmdTable_SnipeShot,
    .affineAnims = sSpriteAffineAnimTable_SnipeShot,
    .callback = AnimShadowBall,
};

// Jaw Lock
const struct SpriteTemplate gJawLockTeethTemplate =
{
    .tileTag = ANIM_TAG_SHARP_TEETH,
    .paletteTag = ANIM_TAG_SHARP_TEETH,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_Bite,
    .callback = SpriteCB_LockingJaw,
};

// Stuff Cheeks
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
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimMetronomeFinger,
};

// No Retreat
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
    .callback = SpriteCB_SpriteOnMonForDuration,
};

// Magic Powder
const struct SpriteTemplate gMagicPowderBluePowderTemplate =
{
    .tileTag = ANIM_TAG_POISON_POWDER,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gPowderParticlesAnimTable,
    .callback = AnimMovePowderParticle,
};

// Dreepy missile
const struct SpriteTemplate gDreepyMissilePlayerTemplate =
{
    .tileTag = ANIM_TAG_DREEPY,
    .paletteTag = ANIM_TAG_DREEPY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissilePlayer,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gDreepyMissileOpponentTemplate =
{
    .tileTag = ANIM_TAG_DREEPY,
    .paletteTag = ANIM_TAG_DREEPY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissileOpponent,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gDreepyMissilePlayerShinyTemplate =
{
    .tileTag = ANIM_TAG_DREEPY,
    .paletteTag = ANIM_TAG_DREEPY_SHINY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissilePlayer,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gDreepyMissileOpponentShinyTemplate =
{
    .tileTag = ANIM_TAG_DREEPY,
    .paletteTag = ANIM_TAG_DREEPY_SHINY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissileOpponent,
    .callback = AnimShadowBall,
};

// Bolt Beak
const struct SpriteTemplate gBoltBeakBlueSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimSparkElectricity,
};

const struct SpriteTemplate gBoltBeakBlueFlashingSparkTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ELECTRICITY,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimSparkElectricityFlashing,
};

// Fishious Rend
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
    .callback = SpriteCB_LeftRightSlice,
};

// Clangorous Soul
const struct SpriteTemplate gClangorousSoulBlueBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gClangorousSoulPurpleBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gClangorousSoulWhiteBuffTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gClangorousSoulRedFistTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimJumpKick,
};

const struct SpriteTemplate gClangorousSoulRedRingTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Pyro Ball
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
    .callback = SpriteCB_PyroBallRockBounce,
};

const struct SpriteTemplate gPyroBallBurningRockTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .callback = SpriteCB_PyroBallRockBounce,
};

const struct SpriteTemplate gPyroBallFlamesUpTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gAnims_DragonBreathFire,
    .callback = SpriteCB_PyroBallRockBounce,
};

const struct SpriteTemplate gPyroBallEmberBallTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &sPyroBallFlamesOAM,
    .anims = gAnims_DragonBreathFire,
    .callback = SpriteCB_PyroBallLaunch,
};

// Aura Wheel
const struct SpriteTemplate gAuraWheelBlueElectricityTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gAuraWheelRedElectricityTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimFireSpiralOutward,
};

// Breaking Swipe
const struct SpriteTemplate gBreakingSwipeCenteredElectricity =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_CentredElectricity,
};

// Branch Poke
const struct SpriteTemplate gBranchPokeBranchTemplate =
{
    .tileTag = ANIM_TAG_BRANCH,
    .paletteTag = ANIM_TAG_BRANCH,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimShadowBall,
};

// Apple Acid
const struct SpriteTemplate gAppleAcidFloatingAppleTemplate =
{
    .tileTag = ANIM_TAG_APPLE,
    .paletteTag = ANIM_TAG_APPLE,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimMetronomeFinger,
};

const struct SpriteTemplate gAppleAcidLaunchTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .affineAnims = gAffineAnims_PoisonProjectile,
    .callback = SpriteCB_AcidLaunchSingleTarget,
};

const struct SpriteTemplate gAppleAcidDripTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = &gAnims_PoisonProjectile[1],
    .affineAnims = gAffineAnims_Droplet,
    .callback = SpriteCB_AcidDripSingleTarget,
};

// Grav Apple
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
    .callback = SpriteCB_FallingObject,
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
    .affineAnims = sSpriteAffineAnimTable_ScaledApple,
    .callback = SpriteCB_FallingObject,
};

// Strange Steam
const struct SpriteTemplate gStrangeSteamPinkCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter,
};

const struct SpriteTemplate gStrangeSteamGreenCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter,
};

const struct SpriteTemplate gStrangeSteamBlueCloudTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter,
};

// Life Dew
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
    .callback = SpriteCB_WaterDroplet,
};

const struct SpriteTemplate gLifeDewSpecialOrbsTemplate =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_BLUE_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gHealingBlueStarAnimTable,
    .callback = SpriteCB_AnimSpriteOnSelectedMonPos,
};

// Obstruct
const struct SpriteTemplate gObstructCrossTemplate =
{
    .tileTag = ANIM_TAG_OBSTRUCT_CROSS,
    .paletteTag = ANIM_TAG_OBSTRUCT_CROSS,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .callback = AnimCrossImpact,
};

// Meteor Assault
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

const struct SpriteTemplate gGrowingSuperpowerTemplate =    // Used in Breakneck Blitz
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_METEOR,
    .oam = &sGrowingSuperpowerOAM,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower,
};

// Steel Beam
const struct SpriteTemplate gSteelBeamSpikeShardTemplate =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimDirtScatter,
};

// Skitter Smack
const struct SpriteTemplate gSkitterSmackImpactTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle,
};

// Triple Axel
const struct SpriteTemplate gTripleAxelIceCrystalSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjBlend_8x8,
    .anims = gAnims_IceCrystalSmall,
    .callback = AnimDizzyPunchDuck,
};

// Dual Wingbeat
static const union AffineAnimCmd sSpriteAffineAnim_WingAttackFeather[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -1, 14), //Rotate a little right
    AFFINEANIMCMD_FRAME(0, 0, 1, 28), //Rotate a little left
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_WingAttackFeather[] =
{
    sSpriteAffineAnim_WingAttackFeather,
};

const struct SpriteTemplate gDualWingbeatFeatherSpriteTemplate =
{
    .tileTag = ANIM_TAG_WHITE_FEATHER,
    .paletteTag = ANIM_TAG_WHITE_FEATHER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_FallingFeather,
    .affineAnims = sSpriteAffineAnimTable_WingAttackFeather,
    .callback = AnimDizzyPunchDuck,
};

// False Surrender
const struct SpriteTemplate gSpriteTemplate_LargeCrossImpact =
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_CROSS_IMPACT,
    .oam = &gOamData_AffineDouble_ObjBlend_32x32,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = AnimCrossImpact,
};

// Expanding Force
static const struct OamData sGeyserOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1, //Above sprites
};

const struct SpriteTemplate gSpriteTemplate_ExpandingForceExplode =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &sGeyserOam,
    .anims = gExplosionAnimTable,
    .callback = SpriteCB_AnimSpriteOnTargetSideCentre,
};

// Spirit Break
static const union AffineAnimCmd sSpriteAffineAnim_SpiritBreakBall[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(2, 2, 0, 50), //Grow slowly to half size
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_SpiritBreakBall[] =
{
    sSpriteAffineAnim_SpiritBreakBall,
};

const struct SpriteTemplate gSpriteTemplate_SpiritBreakChargeBall =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sSpriteAffineAnimTable_SpiritBreakBall,
    .callback = SpriteCB_SpriteOnMonUntilAffineAnimEnds,
};

const struct SpriteTemplate gSpriteTemplate_SpiritBreakExplode =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Chloroblast
const union AffineAnimCmd sSpriteAffineAnim_HydroCannonBall[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 16), //Double in size
    AFFINEANIMCMD_END
};

const union AffineAnimCmd* const sSpriteAffineAnimTable_HydroCannonBall[] =
{
    sSpriteAffineAnim_HydroCannonBall,
};

const struct SpriteTemplate gSpriteTemplate_ChloroblastShot =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = AnimShadowBall,
};

// Steel Roller
const struct SpriteTemplate gSpriteTemplate_SteelRoller =
{
    .tileTag = ANIM_TAG_STEAMROLLER,
    .paletteTag = ANIM_TAG_STEAMROLLER,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .callback = SpriteCB_SteelRoller,
};

// Scale Shot
const struct SpriteTemplate gSpriteTemplate_ScaleShotScale =
{
    .tileTag = ANIM_TAG_SHELL_RIGHT,
    .paletteTag = ANIM_TAG_SHELL_RIGHT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = gAffineAnims_BasicRock,
    .callback = AnimRockBlastRock,
};

// Meteor Beam
const struct SpriteTemplate gSpriteTemplate_MeteorBeamRock =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = AnimShadowBall,
};

// Burning Jealousy
const struct SpriteTemplate gSpriteTemplate_BurningJealousyFireBuff =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .callback = SpriteCB_MoveSpriteUpwardsForDuration,
};

const struct SpriteTemplate gSpriteTemplate_BurningJealousyEmit =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .callback = AnimOutrageFlame,
};

// Lash Out
const struct SpriteTemplate gSpriteTemplate_LashOutStrike =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_SLAM_HIT_2,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gKnockOffStrikeAnimTable,
    .affineAnims = gKnockOffStrikeAffineAnimTable,
    .callback = SpriteCB_LashOutStrike,
};

// Flip Turn
const struct SpriteTemplate gSpriteTemplate_FlipTurnThere =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gSpriteTemplate_FlipTurnBack =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimAbsorptionOrb,
};

// U-Turn
const struct SpriteTemplate gUTurnBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gUTurnBallBackSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimAbsorptionOrb,
};

// Dynamax Cannon
const struct SpriteTemplate gSpriteTemplate_DynamaxCannonOrb =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = AnimShadowBall,
};

// Wicked Blow
static const union AffineAnimCmd sSpriteAffineAnim_DrainPunchFist[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 1), //Double sprite size
    AFFINEANIMCMD_FRAME(-32, -32, 0, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_DrainPunchFist[] =
{
    sSpriteAffineAnim_DrainPunchFist,
};

const struct SpriteTemplate gSpriteTemplate_WickedBlowFist =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .affineAnims = sSpriteAffineAnimTable_DrainPunchFist,
    .callback = SpriteCB_SpriteOnMonForDurationUseY,
};

const struct SpriteTemplate gSpriteTemplate_WickedBlowBlackStars =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDizzyPunchDuck,
};

const struct SpriteTemplate gSpriteTemplate_WickedBlowRedStars =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_PAIN_SPLIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDizzyPunchDuck,
};

// Surging Strikes
static const union AnimCmd sAnimCmdSurgingStrike[] =
{
    //Only tthe first three frames of the animation
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimCmdTable_SurgingStrike[] =
{
    sAnimCmdSurgingStrike,
};

const struct SpriteTemplate gSpriteTemplate_SurgingStrikesImpact =
{
    .tileTag = ANIM_TAG_IMPACT_2,
    .paletteTag = ANIM_TAG_IMPACT_2,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnimCmdTable_SurgingStrike,
    .callback = SpriteCB_SurgingStrikes,
};

// Dragon Energy
const struct SpriteTemplate gSpriteTemplate_DragonEnergyShot =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = SpriteCB_DragonEnergyShot,
};

// Fiery Wrath
const struct SpriteTemplate gSpriteTemplate_FieryWrathGeyser =
{
    .tileTag = ANIM_TAG_PURPLE_RING,
    .paletteTag = ANIM_TAG_PURPLE_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = SpriteCB_Geyser,
};

// Glacial Lance
static const union AffineAnimCmd sSpriteAffineAnim_GlacialLance_Grow[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 30), //Double sprite size
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_GlacialLance_OnFoe[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 1), //Double sprite size
    AFFINEANIMCMD_FRAME(0, 0, -8, 4), //Rotate 45 degrees right
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_GlacialLance_OnPlayer[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 1), //Double sprite size
    AFFINEANIMCMD_FRAME(0, 0, 24, 4), //Rotate 135 degrees left
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_GlacialLance[] =
{
    sSpriteAffineAnim_GlacialLance_Grow,
    sSpriteAffineAnim_GlacialLance_OnFoe,
    sSpriteAffineAnim_GlacialLance_OnPlayer,
};

const struct SpriteTemplate gSpriteTemplate_GlacialLance =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ICICLE_SPEAR,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .affineAnims = sSpriteAffineAnimTable_GlacialLance,
    .callback = SpriteCB_GlacialLance,
};

// Eerie Spell
static const struct OamData sOamData_EerieSpellFlame =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct SpriteTemplate gSpriteTemplate_EerieSpellFlame =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &sOamData_EerieSpellFlame,
    .anims = gAnims_GrudgeFlame,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimNeedleArmSpike,
};


// GEN 9
// Psyshield Bash
const struct SpriteTemplate gSpriteTemplate_PsyshieldBashHit =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Power Shift
const struct SpriteTemplate gSpriteTemplate_PowerShiftOffenseBall =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_PowerShiftBall,
};

const struct SpriteTemplate gSpriteTemplate_PowerShiftDefenseBall =
{
    .tileTag = ANIM_TAG_BLUEGREEN_ORB,
    .paletteTag = ANIM_TAG_BLUEGREEN_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_PowerShiftBall,
};

// Stone Axe
static const union AnimCmd sAnimCmdFlippedX[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimCmdTable_FlippedX[] =
{
    sAnimCmdFlippedX,
};

const struct SpriteTemplate gSpriteTemplate_StoneAxeSlash =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_SLAM_HIT_2,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = sAnimCmdTable_FlippedX,
    .callback = SpriteCB_HorizontalSlice,
};

// Springtide Storm
const struct SpriteTemplate gSpriteTemplate_SpringtideHeart =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimParticleInVortex,
};

// Mystical Power
const struct SpriteTemplate gSpriteTemplate_VioletMind = {  // also Psystrike
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

static const union AffineAnimCmd sSpriteAffineAnim_MysticalPowerRing[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0), //Start small
    AFFINEANIMCMD_FRAME(16, 16, 0, 15), //Grow sprite
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_MysticalPowerRing[] =
{
    sSpriteAffineAnim_MysticalPowerRing,
};

const struct SpriteTemplate gSpriteTemplate_MysticalPowerRing =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sSpriteAffineAnimTable_MysticalPowerRing,
    .callback = AnimHitSplatBasic,
};

// Mountain Gale
const struct SpriteTemplate gSpriteTemplate_MountainGaleRock =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_DRAGON_ASCENT_FOE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .affineAnims = gBulletSeedAffineAnimTable,
    .callback = AnimMissileArc,
};

// Bleakwind Storm
const struct SpriteTemplate gSpriteTemplate_BleakwindIce =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gAnims_IceCrystalLarge,
    .callback = AnimParticleInVortex,
};

// Headlong Rush
const struct SpriteTemplate gSpriteTemplate_HeadlongRushImpact =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineDouble_ObjBlend_32x32,
    .affineAnims = sSpriteAffineAnimTable_DrainPunchFist,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gSpriteTemplate_MaxQuakeDirtGeyser =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimMudSportDirt,
};

const struct SpriteTemplate gSpriteTemplate_MaxQuakeRockGeyser =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .callback = SpriteCB_Geyser,
};

// Barb Barrage
const struct SpriteTemplate gSpriteTemplate_BarbBarrage =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimOutrageFlame,
};

// Esper Wing
const struct SpriteTemplate gSpriteTemplate_WingAttackFeather = {   // TODo update wing attaack anim
    .tileTag = ANIM_TAG_WHITE_FEATHER,
    .paletteTag = ANIM_TAG_WHITE_FEATHER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gAnims_FallingFeather,
    .affineAnims = sSpriteAffineAnimTable_WingAttackFeather,
    .callback = AnimDizzyPunchDuck,
};

// Triple Arrows
const struct SpriteTemplate gSpriteTemplate_TripleArrowKick =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = SpriteCB_TripleArrowKick,
};

// Infernal Parade
static const union AffineAnimCmd sSpriteAffineAnim_FlutterbyPulsate[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 4),
    AFFINEANIMCMD_FRAME(-16, -16, 0, 4),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_FlutterbyGrow[] =
{
    AFFINEANIMCMD_FRAME(8, 8, 0, 16), //Double in size
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSpriteAffineAnimTable_Flutterby[] =
{
    sSpriteAffineAnim_FlutterbyPulsate,
    sSpriteAffineAnim_FlutterbyGrow,
};

const struct SpriteTemplate gSpriteTemplate_InfernalParadeFlame =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gAnims_GrudgeFlame,
    .affineAnims = sSpriteAffineAnimTable_Flutterby,
    .callback = SpriteCB_MaxFlutterby,
};

// Ceaseless Edge
const struct SpriteTemplate gSpriteTemplate_CeaselessEdgeSlash =
{
    .tileTag = ANIM_TAG_SLASH,
    .paletteTag = ANIM_TAG_SLASH,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSlashSliceAnimTable,
    .callback = SpriteCB_FlippableSlash,
};

// Wildbolt Storm
static const union AnimCmd sAnimCmdAnimatedSpark2[] =
{
    ANIMCMD_FRAME((16 * 16) / (8 * 8) * 0, 8),
    ANIMCMD_FRAME((16 * 16) / (8 * 8) * 1, 8),
    ANIMCMD_FRAME((16 * 16) / (8 * 8) * 2, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnimCmdTable_AnimatedSpark2[] =
{
    sAnimCmdAnimatedSpark2,
};

const struct SpriteTemplate gSpriteTemplate_WildboltStormSpark =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnimCmdTable_AnimatedSpark2,
    .callback = AnimParticleInVortex,
};

// Lunar Blessing/Lunar Dance
const struct SpriteTemplate gSpriteTemplate_LunarDanceRing =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

// Take Heart
const struct SpriteTemplate gSpriteTemplate_TakeHeartFallingHeart =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = SpriteCB_FallingObject,
};

const struct SpriteTemplate gSpriteTemplate_TakeHeartRing =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = SpriteCB_SurroundingRing,
};

// Bitter Malice
const struct SpriteTemplate gSpriteTemplate_BitterMaliceRing =
{
    .tileTag = ANIM_TAG_PURPLE_RING,
    .paletteTag = ANIM_TAG_PURPLE_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimParticleInVortex,
};

// Ultra Burst
const struct SpriteTemplate gUltraBurstSymbolSpriteTemplate =
{
    .tileTag = ANIM_TAG_ULTRA_BURST_SYMBOL,
    .paletteTag = ANIM_TAG_ULTRA_BURST_SYMBOL,
    .oam = &gOamData_AffineDouble_ObjBlend_32x32,
    .affineAnims = gAffineAnims_LusterPurgeCircle,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gAxeKickSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = &gAnims_HandsAndFeet[2],
    .callback = AnimBounceBallLand,
};

// Z MOVES
//activate
const struct SpriteTemplate gZMoveSymbolSpriteTemplate =
{
    .tileTag = ANIM_TAG_Z_MOVE_SYMBOL,
    .paletteTag = ANIM_TAG_Z_MOVE_SYMBOL,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_LusterPurgeCircle,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlueZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gGreenZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gYellowZMoveEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};
// Breakneck Blitz
const struct SpriteTemplate gBreakneckBlitzDanceSpriteTemplate =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDragonDanceOrb,
};

const struct SpriteTemplate gBreakneckBlitzHitSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_FLAT_ROCK,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};
// All-Out Pummelling
const struct SpriteTemplate gAllOutPummelingOnslaughtSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_IMPACT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimJumpKick,
};
// Supersonic Skystrike
static const union AffineAnimCmd sSupersonicSkystrikeAffinePlayerSide[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSupersonicSkystrikeAffineOpponentSide[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sSupersonicSkystrikeAffineAnimTable[] =
{
    sSupersonicSkystrikeAffinePlayerSide,
    sSupersonicSkystrikeAffineOpponentSide,
};

const struct SpriteTemplate gSupersonicSkystrikeFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_BIRD,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sSupersonicSkystrikeAffineAnimTable,
    .callback = AnimFlyBallAttack,
};
// Acid Downpour
const struct SpriteTemplate gAcidDownpourReversalSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimReversalOrb,
};

const struct SpriteTemplate gAcidDownpourAuraSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimParticleInVortex,
};
// Tectonic Rage
const struct SpriteTemplate gTectonicRageBlastBurnSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .callback = AnimBlastBurnTargetPlume,
};

const struct SpriteTemplate gTectonicRageExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Continental Crush
const struct SpriteTemplate gContinentalCrushNeedleArmSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gContinentalCrushBigRockStompSpriteTemplate =
{
    .tileTag = ANIM_TAG_REALLY_BIG_ROCK,
    .paletteTag = ANIM_TAG_REALLY_BIG_ROCK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = sSpriteAffineAnimTable_LargeHailRock,
    .callback = SpriteCB_FallingObject,
};

const struct SpriteTemplate gContinentalCrushFocusEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gContinentalCrushGrowingRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_REALLY_BIG_ROCK,
    .paletteTag = ANIM_TAG_REALLY_BIG_ROCK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gContinentalCrushEruptionSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimEruptionFallingRock,
};

// savage Spin-Out
const struct SpriteTemplate gSavageSpinOutStringBlastSpriteTemplate =
{
    .tileTag = ANIM_TAG_STRING,
    .paletteTag = ANIM_TAG_STRING,
    .oam = &gOamData_AffineOff_ObjNormal_64x32,
    .anims = gAffineAnims_AirWaveCrescent,
    .callback = AnimAirWaveCrescent,
};

const struct SpriteTemplate gSavageSpinOutCacoonSpriteTemplate =
{
    .tileTag = ANIM_TAG_COCOON,
    .paletteTag = ANIM_TAG_COCOON,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimBite,
};

const struct SpriteTemplate gSavageSpinOutGreenChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gSavageSpinOutGreenCutSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .callback = AnimCuttingSlice,
};

const struct SpriteTemplate gSavageSpinOutWhiteExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Never-ending Nightmare
const struct SpriteTemplate gNeverEndingNightmareRingAttackerSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gNeverEndingNightmareRingTargetSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gNeverEndingNightmareFocusEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gNeverEndingNightmareHandSpriteTemplate =
{
    .tileTag = ANIM_TAG_ASSURANCE_HAND,
    .paletteTag = ANIM_TAG_ASSURANCE_HAND,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gNeverEndingNightmareBlastBurnSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .callback = AnimBlastBurnTargetPlume,
};

const struct SpriteTemplate gNeverEndingNightmareGeyserHexSpriteTemplate =
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = SpriteCB_GeyserTarget,
};

const struct SpriteTemplate gNeverEndingNightmareExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Corkscrew Crash
const struct SpriteTemplate gCorkscrewCrashMetalBitSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gAffineAnims_TearDrop,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gCorkscrewCrashChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gCorkscrewCrashCorkscrewFlyUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimParticleInVortex,
};

static const union AffineAnimCmd sCorkscrewCrashFlyDownAffineOpponentSide[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x80, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sCorkscrewCrashFlyDownAffineAnimTable[] =
{
    sCorkscrewCrashFlyDownAffineOpponentSide,
};

const struct SpriteTemplate gCorkscrewCrashCorkscrewFlyDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashFlyDownAffineAnimTable,
    .callback = AnimStompFoot,
};

static const union AffineAnimCmd sCorkscrewCrashStrikePlayerAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sCorkscrewCrashStrikeTargetAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sCorkscrewCrashStrikeAffineAnimTable[] =
{
    sCorkscrewCrashStrikePlayerAffineAnims,
    sCorkscrewCrashStrikeTargetAffineAnims,
};

const struct SpriteTemplate gCorkscrewCrashStrikeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack,
};

static const union AffineAnimCmd sCorkscrewCrashLeftAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sCorkscrewCrashLeftAffineAnimTable[] =
{
    sCorkscrewCrashLeftAffineAnims,
};

const struct SpriteTemplate gCorkscrewCrashLeftUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashLeftAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gCorkscrewCrashLeftDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashLeftAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sCorkscrewCrashRightUpAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sCorkscrewCrashRightUpAffineAnimTable[] =
{
    sCorkscrewCrashRightUpAffineAnims,
};

const struct SpriteTemplate gCorkscrewCrashRightUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashRightUpAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sCorkscrewCrashRightDownAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xba, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sCorkscrewCrashRightDownAffineAnimTable[] =
{
    sCorkscrewCrashRightDownAffineAnims,
};

const struct SpriteTemplate gCorkscrewCrashRightDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_CORKSCREW,
    .paletteTag = ANIM_TAG_CORKSCREW,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sCorkscrewCrashRightDownAffineAnimTable,
    .callback = AnimAssistPawprint,
};

// Inferno Overdrive
const struct SpriteTemplate gInfernoOverdriveSuperpowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &sGrowingSuperpowerOAM,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower,
};

const struct SpriteTemplate gInfernoOverdriveChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gInfernoOverdriveExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Hydro Vortex
const struct SpriteTemplate gHydroVortexSuperpowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &sGrowingSuperpowerOAM,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower,
};

const struct SpriteTemplate gHydroVortexHurricaneSpriteTemplate =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
    .callback = AnimEllipticalGust,
};

const struct SpriteTemplate gHydroVortexImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

// Bloom Doom
const struct SpriteTemplate gBloomDoomPetalSpinSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gBloomDoomGreenChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gBloomDoomHurricaneSpriteTemplate =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x64,
    .callback = AnimEllipticalGustAttacker,
};

const struct SpriteTemplate gBloomDoomFlowerGeyserSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .callback = SpriteCB_Geyser,
};

const struct SpriteTemplate gBloomDoomGreenBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gBloomDoomPetalStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .callback = AnimNeedleArmSpike,
};

const struct SpriteTemplate gBloomDoomExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Gigavolt Havoc
const struct SpriteTemplate gGigavoltHavocChargingSpearSpriteTemplate =
{
    .tileTag = ANIM_TAG_HAVOC_SPEAR,
    .paletteTag = ANIM_TAG_HAVOC_SPEAR,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gGigavoltHavocLaunchSpearSpriteTemplate =
{
    .tileTag = ANIM_TAG_HAVOC_SPEAR,
    .paletteTag = ANIM_TAG_HAVOC_SPEAR,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimSuperpowerFireball,
};

const struct SpriteTemplate gGigavoltHavocRingsSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gGigavoltHavocGeyserSpriteTemplate =
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = SpriteCB_GeyserTarget,
};

// Shattered Psyche
const struct SpriteTemplate gShatteredPsycheReflectHitSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .paletteTag = ANIM_TAG_BLUE_LIGHT_WALL,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gShatteredPsychePinkChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gShatteredPsycheRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Subzero Slammer
const struct SpriteTemplate gSubzeroSlammerIceSpinSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gSubzeroSlammerExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSubzeroSlammerIceSwirlSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .affineAnims = gAffineAnims_IceCrystalHit,
    .callback = AnimParticleInVortex,
};

// Devastating Drake
static const union AffineAnimCmd sDevastatingDrakeStrikePlayer[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sDevastatingDrakeStrikeOpponent[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sDevastatingDrakeStrikeAffineAnimTable[] =
{
    sDevastatingDrakeStrikePlayer,
    sDevastatingDrakeStrikeOpponent,
};

static const union AffineAnimCmd sDevastatingDrakeFlyUpAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sDevastatingDrakeFlyUpAffineAnimTable[] =  {
    sDevastatingDrakeFlyUpAffineAnims,
    sDevastatingDrakeFlyUpAffineAnims
};

static const union AffineAnimCmd sDevastatingDrakeRightAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sDevastatingDrakeRightAffineAnimTable[] =
{
    sDevastatingDrakeRightAffineAnims,
    sDevastatingDrakeRightAffineAnims
};

static const union AffineAnimCmd sDevastatingDrakeLeftAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sDevastatingDrakeLeftAffineAnimTable[] =
{
    sDevastatingDrakeLeftAffineAnims,
    sDevastatingDrakeLeftAffineAnims,
};

const struct SpriteTemplate gDevastatingDrakePurpleEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gDevastatingDrakeShockwaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb,
};

const struct SpriteTemplate gDevastatingDrakeDrakeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sDevastatingDrakeFlyUpAffineAnimTable,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gDevastatingDrakeRightSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sDevastatingDrakeRightAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gDevastatingDrakeLeftSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sDevastatingDrakeLeftAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gDevastatingDrakeStrikeSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_DRAKE,
    .paletteTag = ANIM_TAG_PURPLE_DRAKE,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sDevastatingDrakeStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack,
};

const struct SpriteTemplate gDevastatingDrakePurpleBlastSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_FIRE_PLUME,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .callback = AnimBlastBurnTargetPlume,
};

const struct SpriteTemplate gDevastatingDrakeHexSpriteTemplate =
{
    .tileTag = ANIM_TAG_VERTICAL_HEX,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .callback = SpriteCB_Geyser,
};

const struct SpriteTemplate gDevastatingDrakeExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gDevastatingDrakeExplosion2SpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Black Hole Eclipse
const struct SpriteTemplate gBlackHoleEclipseShockwaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BLACK_BALL_2,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrb,
};

const struct SpriteTemplate gBlackHoleEclipseBlueRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackHoleEclipseBlackRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_SHADOW_BALL,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackHoleEclipseRedExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackHoleEclipseWispSpriteTemplate =
{
    .tileTag = ANIM_TAG_WISP_ORB,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gAnims_WillOWispOrb,
    .callback = AnimWillOWispOrb,
};

const struct SpriteTemplate gBlackHoleEclipseRedRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackHoleEclipseBlueRingInwardsSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackHoleEclipseRedRingInwardsSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

static const union AffineAnimCmd sGrowingBackHoleTargetAffineCmds[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 0x88),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const gGrowingBlackHoleTargetAffineAnimTable[] =
{
    sGrowingBackHoleTargetAffineCmds,
};

const struct SpriteTemplate gBlackHoleEclipseHoleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gGrowingBlackHoleTargetAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

static const union AffineAnimCmd sShrinkingBlackHoleAffineCmds[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0xf6, 8),
    AFFINEANIMCMD_END_ALT(1),
};

static const union AffineAnimCmd *const gShrinkingBlackHoleAffineAnimTable[] =
{
    sShrinkingBlackHoleAffineCmds,
};

const struct SpriteTemplate gBlackHoleEclipseHoleShrinkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gShrinkingBlackHoleAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

static const union AffineAnimCmd sGrowingBackHoleAffineCmds[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 0x48),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const gGrowingBlackHoleAffineAnimTable[] =
{
    sGrowingBackHoleAffineCmds,
};

const struct SpriteTemplate gBlackHoleEclipseHoleUserSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gGrowingBlackHoleAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTargetTwinkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_SpinningSparkle,
    .callback = SpriteCB_TwinkleOnBattler,
};

// Twinkle Tackle
static const union AffineAnimCmd sTwinkleTackleStarPlayerAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(8, 8, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0x0, 0x1e),
    AFFINEANIMCMD_END_ALT(1),
};

static const union AffineAnimCmd sTwinkleTackleStarOpponentAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(8, 8, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0xf),
    AFFINEANIMCMD_END_ALT(1),
};

static const union AffineAnimCmd *const sTwinkleTackleStarAffineAnimTable[] =
{
    sTwinkleTackleStarPlayerAffineAnims,
    sTwinkleTackleStarOpponentAffineAnims
};

const struct SpriteTemplate gTwinkleTacklePinkStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .callback = AnimGrantingStars,
};

const struct SpriteTemplate gTwinkleTacklePinkRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTwinkleTackleStarGrowSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .affineAnims = sTwinkleTackleStarAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gTwinkleTackleTwinkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_SPARKLE_4,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_SpinningSparkle,
    .callback = SpriteCB_TwinkleOnBattler,
};

const struct SpriteTemplate gTwinkleTackleDigStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .callback = AnimDirtPlumeParticle,
};

const struct SpriteTemplate gTwinkleTackleYellowImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gTwinkleTackleImpactStarsSpriteTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDizzyPunchDuck,
};

// Catastropika
const struct SpriteTemplate gCatastrokpikaSuperpowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &sGrowingSuperpowerOAM,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower,
};

// 10e6 volt thunderbolt
const struct SpriteTemplate g10MillionVoltBoltYellowFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate g10MillionVoltBoltShockwaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget,
};

const struct SpriteTemplate g10MillionVoltBoltRedBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate g10MillionVoltBoltBlueBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate g10MillionVoltBoltPinkBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate g10MillionVoltBoltYellowBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate g10MillionVoltBoltGreenBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate g10MillionVoltBoltPurpleBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

// Stoked Sparksurfer
const struct SpriteTemplate gStokedSparksurferFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_SPARK_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

// Extreme Evoboost
const struct SpriteTemplate gExtremeEvoboostRedChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostPinkChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostIceChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostBlackChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostBlueChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostPurpleChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostYellowChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostGreenChargeUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gExtremeEvoboostRedChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostPinkChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostIceChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostBlackChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostBlueChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostPurpleChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostYellowChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostGreenChargeCircleSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimExtremeEvoboostCircle,
};

const struct SpriteTemplate gExtremeEvoboostRedStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostPinkStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_BERRY_EATEN,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostIceStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostBlackStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostBlueStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostPurpleStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostYellowStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gExtremeEvoboostGreenStockpileSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

// Pulverizing Pancake
const struct SpriteTemplate gPulverizingPancakeRedDetectSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_SpinningSparkle,
    .callback = AnimSpinningSparkle,
};

const struct SpriteTemplate gPulverizingPancakeExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gPulverizingPancakeYellowRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_ELECTRIC_ORBS,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Genesis Supernova
const struct SpriteTemplate gGenesisSupernovaOrbRiseSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gGenesisSupernovaReversalSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimReversalOrb,
};

const struct SpriteTemplate gGenesisSupernovaSpinUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gGenesisSupernovaChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gGenesisSupernovaSuperpowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &sGrowingSuperpowerOAM,
    .affineAnims = sSpriteAffineAnimTable_GrowingSuperpower,
    .callback = SpriteCB_GrowingSuperpower,
};

const struct SpriteTemplate gGenesisSupernovaBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_JAB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gAnims_PoisonProjectile,
    .affineAnims = gAffineAnims_Bubble,
    .callback = AnimBubbleEffect,
};

const struct SpriteTemplate gGenesisSupernovaExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WISP_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Sinister Arrow Raid
static const union AffineAnimCmd sArrowRaidFlyStrikePlayerAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sArrowRaidFlyStrikeOpponentAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidFlyStrikeAffineAnimTable[] =
{
    sArrowRaidFlyStrikePlayerAffineAnims,
    sArrowRaidFlyStrikeOpponentAffineAnims
};

static const union AffineAnimCmd sArrowRaidFlyRightAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xc2, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidFlyRightAffineAnimTable[] =
{
    sArrowRaidFlyRightAffineAnims,
    sArrowRaidFlyRightAffineAnims
};

static const union AffineAnimCmd sArrowRaidFlyLeftAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x40, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidFlyLeftAffineAnimTable[] =
{
    sArrowRaidFlyLeftAffineAnims,
    sArrowRaidFlyLeftAffineAnims
};

const struct SpriteTemplate gArrowRaidExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gArrowRaidFlyUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate gArrowRaidFlyRightSpriteTemplate =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sArrowRaidFlyRightAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gArrowRaidFlyLeftSpriteTemplate =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sArrowRaidFlyLeftAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gArrowRaidFlyStrikeSpriteTemplate =
{
    .tileTag = ANIM_TAG_BIRD,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .affineAnims = sArrowRaidFlyStrikeAffineAnimTable,
    .callback = AnimFlyBallAttack,
};

static const union AffineAnimCmd sArrowRaidArrowUpAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xa0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidArrowUpAffineAnimTable[] =
{
    sArrowRaidArrowUpAffineAnims,
};

const struct SpriteTemplate gArrowRaidArrowUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidArrowUpAffineAnimTable,
    .callback = AnimParticleInVortex,
};

static const union AffineAnimCmd sArrowRaidArrowRightUpAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x75, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidArrowRightUpAffineAnimTable[] =
{
    sArrowRaidArrowRightUpAffineAnims,
};

const struct SpriteTemplate gArrowRaidRightUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidArrowRightUpAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidRightDownAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidRightDownAffineAnimTable[] =
{
    sArrowRaidRightDownAffineAnims,
};

const struct SpriteTemplate gArrowRaidRightDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidRightDownAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidArrowLeftUpAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xe0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidLeftUpAffineAnimTable[] =
{
    sArrowRaidArrowLeftUpAffineAnims,
};

const struct SpriteTemplate gArrowRaidLeftUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidLeftUpAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidFaceUpLeftAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xe0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidFaceUpLeftAffineAnimTable[] =
{
    sArrowRaidFaceUpLeftAffineAnims,
};

const struct SpriteTemplate gArrowRaidFaceUpLeftSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidFaceUpLeftAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidArrowFaceRightAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidArrowFaceRightAffineAnimTable[] =
{
    sArrowRaidArrowFaceRightAffineAnims
};

const struct SpriteTemplate gArrowRaidRightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidArrowFaceRightAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidLeftDownAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xd0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidLeftDownAffineAnimTable[] =
{
    sArrowRaidLeftDownAffineAnims
};

const struct SpriteTemplate gArrowRaidLeftDownSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidLeftDownAffineAnimTable,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sArrowRaidOnslaughtAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x30, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sArrowRaidOnslaughtAffineAnimTable[] =
{
    sArrowRaidOnslaughtAffineAnims
};

const struct SpriteTemplate gArrowRaidArrowOnslaughtSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIRIT_ARROW,
    .paletteTag = ANIM_TAG_SPIRIT_ARROW,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = sArrowRaidOnslaughtAffineAnimTable,
    .callback = AnimAssistPawprint,
};

// Malicious Moonsault
const struct SpriteTemplate gMaliciousMoonsaultRedFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate gMaliciousMoonsaultRedBounceSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_BounceBallLand,
    .callback = AnimBounceBallLand,
};

const struct SpriteTemplate gMaliciousMoonsaultRedImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .affineAnims = gAffineAnims_HitSplat,
    .callback = AnimHitSplatBasic,
};

const struct SpriteTemplate gMaliciousMoonsaultFireblastSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FireBlastCross,
    .callback = AnimFireCross,
};

const struct SpriteTemplate gMaliciousMoonsaultExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Oceanic Operetta
const struct SpriteTemplate gOceanOperaSpotlightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gSpotlightAffineAnimTable,
    .callback = AnimOceanicOperettaSpotlight,
};

const struct SpriteTemplate gOceanOperaBlueFlareSpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gOceanOperaBlueChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gOceanOperaBlueRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gOceanOperaMovingOrbsSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimThrowMistBall,
};

const struct SpriteTemplate gOceanOperaBlueOrbsSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .callback = AnimBite,
};

const struct SpriteTemplate gOceanOperaExpandingRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gOceanOperaExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gOceanOperaSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .callback = AnimGrantingStars,
};

// Splintered Stormshards
const struct SpriteTemplate gSplinteredShardsFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate gSplinteredShardsExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSplinteredShardsRisingSpearSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimAssistPawprint,
};

static const union AffineAnimCmd sSplinteredShardsOpponentSteepAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xca, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSplinteredShardsOpponentSteepAffineAnimTable[] =
{
    sSplinteredShardsOpponentSteepAffineAnims,
};

const struct SpriteTemplate gSplinteredShardsSplinterOpponentSteepSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sSplinteredShardsOpponentSteepAffineAnimTable,
    .callback = AnimJumpKick,
};

static const union AffineAnimCmd sSplinteredShardsOpponentShallowAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0xb9, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSplinteredShardsOpponentShallowAffineAnimTable[] =
{
    sSplinteredShardsOpponentShallowAffineAnims
};

const struct SpriteTemplate gSplinteredShardsSplinterOpponentShallowSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sSplinteredShardsOpponentShallowAffineAnimTable,
    .callback = AnimJumpKick,
};

static const union AffineAnimCmd sSplinteredShardsPlayerSteepAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x60, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSplinteredShardsPlayerSteepAffineAnimTable[] =
{
    sSplinteredShardsPlayerSteepAffineAnims
};

const struct SpriteTemplate gSplinteredShardsSplinterPlayerSteepSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sSplinteredShardsPlayerSteepAffineAnimTable,
    .callback = AnimJumpKick,
};

static const union AffineAnimCmd sSplinteredShardsPlayerShallowAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0x50, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSplinteredShardsPlayerShallowAffineAnimTable[] =
{
    sSplinteredShardsPlayerShallowAffineAnims
};

const struct SpriteTemplate gSplinteredShardsSplinterPlayerShallowSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sSplinteredShardsPlayerShallowAffineAnimTable,
    .callback = AnimJumpKick,
};

// Let's Snuggle Forever
const struct SpriteTemplate gSnuggleForeverEyesSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_4,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_SpinningSparkle,
    .callback = AnimSpinningSparkle,
};

const struct SpriteTemplate gSnuggleForeverStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_DUCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimDizzyPunchDuck,
};

const struct SpriteTemplate gSnuggleForeverHeartSpriteTemplate =
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimMagentaHeart,
};

// Clangorous Soulblaze
const struct SpriteTemplate gClangoorousSoulblazeWhiteFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate gClangoorousSoulblazePurpleSwirlSpriteTemplate =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gAnims_WaterMudOrb,
    .affineAnims = gAffineAnims_Whirlpool,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gClangoorousSoulblazePurpleChargeSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gClangoorousSoulblazePulseSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

// Guardian of Alola
const struct SpriteTemplate gGuardianOfAlolaFistSpriteTemplate =
{
    .tileTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .paletteTag = ANIM_TAG_HORSESHOE_SIDE_FIST,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = AnimStompFoot,
};

const struct SpriteTemplate gGuardianOfAlolaDirtGeyserSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimMudSportDirt,
};

// Searing Sunraze Smash
static const union AffineAnimCmd sSearingSunrazeSmashWormholeGrowingAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0xf8, 0x88),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSearingSunrazeSmashWormholeGrowingAffineAnimTable[] =
{
    sSearingSunrazeSmashWormholeGrowingAffineAnims
};

const struct SpriteTemplate gSearingSunrazeSmashGrowWormholeSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sSearingSunrazeSmashWormholeGrowingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSearingSunrazeSmashBlueRingInwardsSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSearingSunrazeSmashWhiteRingInwardsSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSearingSunrazeSmashCrossImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_CROSS_IMPACT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .callback = AnimCrossImpact,
};

const struct SpriteTemplate gSearingSunrazeSmashWhiteCutSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .callback = AnimCuttingSlice,
};

const struct SpriteTemplate gSearingSunrazeSmashInfernoOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingChargeOrb,
};

const struct SpriteTemplate gSearingSunrazeSmashShockwaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget,
};

const struct SpriteTemplate gSearingSunrazeSmashRedFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_VERTICAL_HEX,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

// Menacing Moonraze Maelstrom
const struct SpriteTemplate gMoonrazeMaelstromBlueBuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gMoonrazeMaelstromBlackBuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gMoonrazeMaelstromPurpleBuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gMoonrazeMaelstromBlackSparklesSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .callback = AnimGrantingStars,
};

const struct SpriteTemplate gMoonrazeMaelstromBlueRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gMoonrazeMaelstromWhiteRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gMoonrazeMaelstromSuperpowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_METEOR,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .callback = AnimSuperpowerFireball,
};

const struct SpriteTemplate gMoonrazeMaelstromBlackOrbsSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimParticleInVortex,
};

const struct SpriteTemplate gMoonrazeMaelstromBeamSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .callback = AnimHyperBeamOrb,
};

const struct SpriteTemplate gMoonrazeMaelstromExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gMoonrazeMaelstromShockwaveSpriteTemplate =
{
    .tileTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = gAffineAnims_GrowingElectricOrb,
    .callback = AnimGrowingShockWaveOrbOnTarget,
};

static const union AffineAnimCmd sMoonrazeMaelstromWormholeAffineAnims[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0xf6, 0x88),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sMoonrazeMaelstromWormholeAffineAnimTable[] =
{
    sMoonrazeMaelstromWormholeAffineAnims
};

const struct SpriteTemplate gMoonrazeMaelstromWormholeSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHADOW_BALL,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = sMoonrazeMaelstromWormholeAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Light That Burns the Sky
const struct SpriteTemplate gLightThatBurnsTheSkyGreenSparkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = gAffineAnims_FlashingSpark,
    .callback = AnimSparkElectricityFlashing,
};

const struct SpriteTemplate gLightThatBurnsTheSkyBlastBurnSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_CIRCLE_OF_LIGHT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .callback = AnimBlastBurnTargetPlume,
};

const struct SpriteTemplate gLightThatBurnsTheSkyExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_2,
    .paletteTag = ANIM_TAG_EXPLOSION_2,
    .oam = &sGeyserOam,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

// Soul-Stealing 7-Star Strike
const struct SpriteTemplate gSoulStealBlackFlySpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_SHADOW,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .affineAnims = gAffineAnims_FlyBallUp,
    .callback = AnimFlyBallUp,
};

const struct SpriteTemplate gSoulStealIceBuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gSoulStealBlueFistSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_HandsAndFeet,
    .callback = AnimJumpKick,
};

const struct SpriteTemplate gSoulStealBlueStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimSoulStealingStar,
};

const struct SpriteTemplate gSoulStealBlueParalyzeSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARK_2,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimElectricity,
};

const struct SpriteTemplate gSoulStealBlastburnSpriteTemplate =
{
    .tileTag = ANIM_TAG_FIRE_PLUME,
    .paletteTag = ANIM_TAG_WISP_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FirePlume,
    .callback = AnimFirePlume,
};

const struct SpriteTemplate gSoulStealExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WISP_FIRE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gSoulStealZStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .callback = AnimCrossImpact,
};

// Bitter Blade
const struct SpriteTemplate gBitterBladeImpactTemplate =
{
    .tileTag = ANIM_TAG_CLAW_SLASH,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_ClawSlash,
    .callback = AnimClawSlash,
};

const struct SpriteTemplate gRedExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_EXPLOSION,
    .paletteTag = ANIM_TAG_RED_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBloodMoonOnslaughtSpriteTemplate =
{
    .tileTag = ANIM_TAG_BEAM,
    .paletteTag = ANIM_TAG_BEAM,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .affineAnims = sArrowRaidOnslaughtAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const struct SpriteTemplate gMoonUpSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLOOD_MOON,
    .paletteTag = ANIM_TAG_BLOOD_MOON,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .callback = AnimWeatherBallUp,
};

const struct SpriteTemplate gAlphaGeyserSpriteTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .affineAnims = gSpriteAffineAnimTable_PrimalSymbol,
    .callback = SpriteCB_Geyser,
};

const struct SpriteTemplate gOmegaGeyserSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .affineAnims = gSpriteAffineAnimTable_PrimalSymbol,
    .callback = SpriteCB_Geyser,
};

// Moves objects (ice crystals) in a wave-like behavior. Seen in Max Flutterby
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: wave amplitude
const struct SpriteTemplate gIceShardSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gAnims_IceCrystalSmall,
    .affineAnims = sSpriteAffineAnimTable_Flutterby,
    .callback = SpriteCB_MaxFlutterby,
};

const struct SpriteTemplate gSpinningVineSpriteTemplate =
{
    .tileTag = ANIM_TAG_PUNISHMENT_BLADES,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = AnimBoneHitProjectile,
};

const struct SpriteTemplate gMaxFlutterbyButterflySpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .affineAnims = sSpriteAffineAnimTable_Flutterby,
    .callback = SpriteCB_MaxFlutterby,
};

const struct SpriteTemplate gReallyBigRockBlastRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_REALLY_BIG_ROCK,
    .paletteTag = ANIM_TAG_REALLY_BIG_ROCK,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .callback = AnimRockBlastRock,
};

const struct SpriteTemplate gOrderUpTatsugiriCurlySpriteTemplate =
{
    .tileTag = ANIM_TAG_TATSUGIRI_CURLY,
    .paletteTag = ANIM_TAG_TATSUGIRI_CURLY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissilePlayer,
    .callback = AnimRockTomb,
};

const struct SpriteTemplate gOrderUpTatsugiriDroopySpriteTemplate =
{
    .tileTag = ANIM_TAG_TATSUGIRI_DROOPY,
    .paletteTag = ANIM_TAG_TATSUGIRI_DROOPY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissilePlayer,
    .callback = AnimRockTomb,
};

const struct SpriteTemplate gOrderUpTatsugiriStretchySpriteTemplate =
{
    .tileTag = ANIM_TAG_TATSUGIRI_STRETCHY,
    .paletteTag = ANIM_TAG_TATSUGIRI_STRETCHY,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_DreepyMissilePlayer,
    .callback = AnimRockTomb,
};

// Start of Tera Blast sprite templates
const struct SpriteTemplate gFireSpreadBlastSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_BasicFire,
    .callback = AnimIceBeamParticle,
};

const struct SpriteTemplate gPurpleFlameSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_FLAME,
    .paletteTag = ANIM_TAG_PURPLE_FLAME,
    .oam = &gOamData_AffineOff_ObjBlend_16x32,
    .anims = gAnims_GrudgeFlame,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gAirWaveSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE_2,
    .paletteTag = ANIM_TAG_AIR_WAVE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gAffineAnims_AirWaveCrescent,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gPinkVioletOrbSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINKVIO_ORB,
    .paletteTag = ANIM_TAG_PINKVIO_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gHydroPumpSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sCirclingShockSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_SHOCK,
    .paletteTag = ANIM_TAG_SHOCK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_CirclingElectricShock,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sIceCrystalSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineDouble_ObjBlend_8x16,
    .anims = gAnims_IceCrystalLarge,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sMudSandSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUD_SAND,
    .paletteTag = ANIM_TAG_MUD_SAND,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_MudSlapMud,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sPoisonSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_BUBBLE,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = &gAnims_PoisonProjectile[0],
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sRockSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAnims_FlyingRock,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sMetalBallSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_METAL_BALL,
    .paletteTag = ANIM_TAG_METAL_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate sPinkHeartSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINK_HEART,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gDragonDanceOrbSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_HOLLOW_ORB,
    .paletteTag = ANIM_TAG_HOLLOW_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gYellowStarSpiralOutwardSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .callback = AnimFireSpiralOutward,
};

const struct SpriteTemplate gTeraBlastFlyingSpriteTemplate =
{
    .tileTag = ANIM_TAG_METAL_SOUND_WAVES,
    .paletteTag = ANIM_TAG_METAL_SOUND_WAVES,
    .oam = &gOamData_AffineDouble_ObjNormal_32x64,
    .affineAnims = gAffineAnims_SpinningBone,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gTeraBlastWaterSpriteTemplate =
{
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .callback = AnimDracoMeteorRock,
};

const struct SpriteTemplate gTeraBlastRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_BasicRock,
    .callback = AnimDracoMeteorRock,
};

const struct SpriteTemplate gGhostProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .paletteTag = ANIM_TAG_GHOSTLY_SPIRIT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .callback = AnimPoisonJabProjectile,
};
// End of Tera Blast sprite templates

const union AnimCmd gSproutAnimCmds[] =
{
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gSproutAnimTable[] =
{
    gSproutAnimCmds,
};

const struct SpriteTemplate gSproutGrowSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPROUT,
    .paletteTag = ANIM_TAG_SPROUT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSproutAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gFreezyFrostRisingSpearSpriteTemplate =
{
    .tileTag = ANIM_TAG_ICICLE_SPEAR,
    .paletteTag = ANIM_TAG_ICICLE_SPEAR,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .callback = SpriteCB_GeyserTarget,
};

// functions
//general
void AnimTask_IsTargetPartner(u8 taskId)
{
    if (gBattleAnimTarget == GetPartnerBattler(gBattleAnimAttacker))
        gBattleAnimArgs[0] = 1;
    else
        gBattleAnimArgs[0] = 0;

    DestroyAnimVisualTask(taskId);
}

static enum BattlerId LoadBattleAnimTarget(u8 arg)
{
    enum BattlerId battler;
    enum AnimBattler animBattler = gBattleAnimArgs[arg];

    if (IsDoubleBattle())
    {
        switch (animBattler)
        {
        case ANIM_ATTACKER:
            battler = gBattleAnimAttacker;
            break;
        default:
            battler = gBattleAnimTarget;
            break;
        case ANIM_ATK_PARTNER:
            battler = GetPartnerBattler(gBattleAnimAttacker);
            break;
        case ANIM_DEF_PARTNER:
            battler = GetPartnerBattler(gBattleAnimTarget);
            break;
        }
    }
    else
    {
        if (animBattler == ANIM_ATTACKER)
            battler = gBattleAnimAttacker;
        else
            battler = gBattleAnimTarget;
    }

    return battler;
}

static u8 GetProperCentredCoord(enum BattlerId battler, u8 coordType)
{
    if (IsDoubleBattle())
        return (GetBattlerSpriteCoord2(battler, coordType) + GetBattlerSpriteCoord2(GetPartnerBattler(battler), coordType)) / 2;

    return GetBattlerSpriteCoord(battler, coordType);
}

static void InitSpritePosToGivenTarget(struct Sprite *sprite, enum BattlerId target)
{
    sprite->x = GetBattlerSpriteCoord2(target, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord2(target, BATTLER_COORD_Y);

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y2 = gBattleAnimArgs[1];
}

void InitSpritePosToAnimTargetsCentre(struct Sprite *sprite, bool32 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_X)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_Y)) / 2;
    }

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

static void InitSpritePosToAnimAttackersCentre(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimAttacker), BATTLER_COORD_X)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimAttacker), BATTLER_COORD_Y)) / 2;
    }
    else
    {
        sprite->x = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X_2)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimAttacker), BATTLER_COORD_X_2)) / 2;
        sprite->y = (GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET)
                       +  GetBattlerSpriteCoord2(GetPartnerBattler(gBattleAnimAttacker), BATTLER_COORD_Y_PIC_OFFSET)) / 2;
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
    if (!IsOnPlayerSide(gBattleAnimTarget))
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

static void SpriteCB_SpriteToCentreOfSide(struct Sprite *sprite)
{
    bool8 respectMonPicOffsets;

    if (!sprite->data[0])
    {
        if (!gBattleAnimArgs[3])
            respectMonPicOffsets = TRUE;
        else
            respectMonPicOffsets = FALSE;

        if (gBattleAnimArgs[2] == 0) //Attacker
        {
            if (IsDoubleBattle())
                InitSpritePosToAnimAttackersCentre(sprite, respectMonPicOffsets);
            else
                InitSpritePosToAnimAttacker(sprite, respectMonPicOffsets);
        }
        else
        {
            if (IsDoubleBattle())
                InitSpritePosToAnimTargetsCentre(sprite, respectMonPicOffsets);
            else
                InitSpritePosToAnimTarget(sprite, respectMonPicOffsets);
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
    enum BattlerId target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(target, BATTLER_COORD_Y);
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
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    if (IsOnPlayerSide(gBattleAnimTarget))
        sprite->y += 8;

    sprite->callback = AnimStringWrap_Step;
}


static void SpriteCB_GrowingSuperpower(struct Sprite *sprite)
{
    enum BattlerId battler;

    if (gBattleAnimArgs[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        battler = gBattleAnimTarget;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    }
    else
    {
        battler = gBattleAnimAttacker;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    }

    if (!IsOnPlayerSide(gBattleAnimAttacker))
        StartSpriteAffineAnim(sprite, 1);

    sprite->data[0] = 16;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);

    InitAnimLinearTranslation(sprite);
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = AnimTranslateLinear_WithFollowup;
}

static void SpriteCB_Protect(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->callback = AnimSpiderWeb;
}

static void SpriteCB_CentredSpiderWeb(struct Sprite *sprite)
{
    if (IsDoubleBattle())
        InitSpritePosToAnimTargetsCentre(sprite, FALSE);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->callback = AnimSpiderWeb;
}

static void SpriteCB_CoreEnforcerHits(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);

    if (gBattleAnimArgs[2] == 0)
    {
        if (IsDoubleBattle())
            InitSpritePosToAnimAttackersCentre(sprite, FALSE);
        else
            InitSpritePosToAnimAttacker(sprite, FALSE);
    }
    else
    {
        if (IsDoubleBattle())
            InitSpritePosToAnimTargetsCentre(sprite, FALSE);
        else
            InitSpritePosToAnimTarget(sprite, FALSE);
    }

    sprite->y += 20;
    sprite->callback = AnimFlashingHitSplat_Step;
}

static void SpriteCB_CoreEnforcerBeam(struct Sprite *sprite)
{
    if (!IsDoubleBattle())
    {
        AnimSolarBeamBigOrb(sprite);
    }
    else
    {
        InitSpritePosToAnimAttacker(sprite, TRUE);
        StartSpriteAnim(sprite, gBattleAnimArgs[3]);

        sprite->data[0] = gBattleAnimArgs[2];

        sprite->data[2] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2)
                        +  GetBattlerSpriteCoord(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_X_2)) / 2;


        sprite->data[4] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET)
                        +  GetBattlerSpriteCoord(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_Y_PIC_OFFSET)) / 2;

        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

static void SpriteCB_TranslateAnimSpriteToTargetMonLocationDoubles(struct Sprite *sprite)
{
    bool8 respectMonPicOffsets;
    enum BattlerId target;
    u8 coordType;

    if (!(gBattleAnimArgs[5] & 0xff00))
        respectMonPicOffsets = TRUE;
    else
        respectMonPicOffsets = FALSE;

    if (!(gBattleAnimArgs[5] & 0xff))
        coordType = BATTLER_COORD_Y_PIC_OFFSET;
    else
        coordType = BATTLER_COORD_Y;

    InitSpritePosToAnimAttacker(sprite, respectMonPicOffsets);
    if (!IsOnPlayerSide(gBattleAnimAttacker))
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
    enum BattlerId target = LoadBattleAnimTarget(3);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        sprite->x = GetBattlerSpriteCoord2(target, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(target, BATTLER_COORD_Y);

        sprite->x2 = gBattleAnimArgs[0];
        sprite->y = gBattleAnimArgs[1];
        sprite->y2 = -gBattleAnimArgs[1];

        if (IsOnPlayerSide(gBattleAnimTarget))
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

static void SpriteCB_SunsteelStrikeRings(struct Sprite *sprite)
{
    if (!IsOnPlayerSide(gBattleAnimAttacker))
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
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = sprite->x << 4;
    sprite->data[5] = sprite->y << 4;
    sprite->data[6] = SAFE_DIV((oldPosX - sprite->x) << 4, gBattleAnimArgs[0] << 1);
    sprite->data[7] = SAFE_DIV((oldPosY - sprite->y) << 4, gBattleAnimArgs[0] << 1);
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

static void SpriteCB_MindBlownExplosion(struct Sprite *sprite)
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

void SpriteCB_RandomCentredHits(struct Sprite *sprite)
{
    if (gBattleAnimArgs[1] == -1)
        gBattleAnimArgs[1] = Random() & 3;

    StartSpriteAffineAnim(sprite, gBattleAnimArgs[1]);

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        if (IsDoubleBattle())
            InitSpritePosToAnimAttackersCentre(sprite, FALSE);
        else
            InitSpritePosToAnimAttacker(sprite, FALSE);
    }
    else
    {
        if (IsDoubleBattle())
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
static void SpriteCB_PyroBallRockBounceStep(struct Sprite *sprite)
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

static void InitSpritePositionForPyroBall(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->y += 20; //Move closer to attacker's feet

    if (IsOnPlayerSide(gBattleAnimAttacker))
        sprite->y += 20; //Move below the text box

}

static void SpriteCB_PyroBallRockBounce(struct Sprite *sprite)
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
static void SpriteCB_PyroBallLaunch(struct Sprite *sprite)
{
    InitSpritePositionForPyroBall(sprite);

    if (!IsOnPlayerSide(gBattleAnimAttacker))
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
    if (!IsOnPlayerSide(gBattleAnimAttacker))
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
    if (!IsOnPlayerSide(gBattleAnimAttacker))
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
    enum BattlerId target = LoadBattleAnimTarget(2);

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
        enum BattlerId target = LoadBattleAnimTarget(2);

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
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 40;

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
static void SpriteCB_PhotonGeyserBeam(struct Sprite *sprite)
{
    enum BattlerId target = LoadBattleAnimTarget(2);

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
static void SpriteCB_BeamUpStep(struct Sprite *sprite)
{
    if (sprite->data[1]-- == 0)
        StartSpriteAffineAnim(sprite, 1);

    if (sprite->data[0]-- <= 0)
        DestroySpriteAndMatrix(sprite);
}

static void SpriteCB_CentredElectricity(struct Sprite *sprite)
{
    if (IsDoubleBattle())
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

static void SpriteCB_SearingShotRock(struct Sprite *sprite)
{
    enum BattlerId target = LoadBattleAnimTarget(4);

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
static void SpriteCB_Geyser(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[1] > 0 ? 1 : -1;
    sprite->callback = AnimMudSportDirtRising;
}

//Launches an object upwards like they were being shot from a geyser
//arg 0: null
//arg 1: initial x pixel offset
//arg 2: initial y pixel offset
static void SpriteCB_GeyserTarget(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[1] > 0 ? 1 : -1;
    sprite->callback = AnimMudSportDirtRising;
}

//// Anim Tasks Functions
void AnimTask_IsAttackerPlayerSide(u8 taskId)
{
    if (!IsOnPlayerSide(gBattleAnimAttacker))
        gBattleAnimArgs[7] = 0;
    else
        gBattleAnimArgs[7] = 1;

    DestroyAnimVisualTask(taskId);
}

static void AnimTask_FadeOutParticlesHelper(u8 taskId)
{
    if (gTasks[taskId].data[1] == 0) //Target reached
    {
        DestroyAnimVisualTask(taskId);
    }
    else if (gTasks[taskId].data[4]++ >= gTasks[taskId].data[3])
    {
        gTasks[taskId].data[4] = 0; //Reset timer
        gTasks[taskId].data[1]--;
        gTasks[taskId].data[2]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].data[2] * 256) + gTasks[taskId].data[1]);
    }
}

void AnimTask_FadeOutParticles(u8 taskId)
{
    u8 existingTaskId = FindTaskIdByFunc(AnimTask_FadeOutParticlesHelper);
    if (existingTaskId != 0xFF)
        DestroyAnimVisualTask(existingTaskId); //Can only have one of these tasks going at a time

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL); //Blend sprites out
    gTasks[taskId].data[1] = 16;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = gBattleAnimArgs[0]; //Delay
    gTasks[taskId].data[4] = 0; //Delay Timer
    gTasks[taskId].func = AnimTask_FadeOutParticlesHelper;
}


static const union AffineAnimCmd sShellSmashShrinkAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(64, 64, 0, 16), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 48),
    AFFINEANIMCMD_FRAME(-64, -64, 0, 16),
    AFFINEANIMCMD_END,
};
//Shrinks the attacker, pauses, then scales up the attacker again
void AnimTask_ShellSmashShrinkAttacker(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId;

    task->data[0] = gBattleAnimArgs[0]; //Pause
    spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    PrepareAffineAnimInTaskData(task, spriteId, sShellSmashShrinkAffineAnimCmds);
    task->func = AnimTask_DynamaxGrowthStep;
}

static void AnimTask_DynamaxGrowthStep(u8 taskId) // from CFRU
{
    struct Task* task = &gTasks[taskId];
    if (!RunAffineAnimFromTaskData(task))
        DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBattlersInvisible(u8 taskId)
{
    u32 spriteId;
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        spriteId = gBattlerSpriteIds[i];
        if (spriteId != 0xFF)
            gSprites[spriteId].invisible = TRUE;
    }
    DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBattlersVisible(u8 taskId)
{
    u32 spriteId;
    for (enum BattlerId i = 0; i < gBattlersCount; ++i)
    {
        spriteId = gBattlerSpriteIds[i];
        if (IsBattlerSpriteVisible(i) && spriteId != 0xFF)
            gSprites[spriteId].invisible = FALSE;
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_AllBattlersInvisibleExceptAttackerAndTarget(u8 taskId)
{
    for (enum BattlerId i = 0; i < gBattlersCount; ++i)
    {
        u8 spriteId = gBattlerSpriteIds[i];
        if (spriteId == GetAnimBattlerSpriteId(ANIM_ATTACKER) || spriteId == GetAnimBattlerSpriteId(ANIM_TARGET))
            continue;
        if (spriteId != 0xFF || !IsBattlerSpriteVisible(i)) //Pokemon that are already hidden
            gSprites[spriteId].invisible = TRUE;
    }
    DestroyAnimVisualTask(taskId);
}

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
    struct Sprite *sprite = &gSprites[task->tSpriteId];

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
    gBattleAnimArgs[0] = 0;
    if (gBattleMons[gBattleAnimAttacker].species == SPECIES_LYCANROC_MIDNIGHT)
        gBattleAnimArgs[0] = 1;
    else if (gBattleMons[gBattleAnimAttacker].species == SPECIES_LYCANROC_DUSK)
        gBattleAnimArgs[0] = 2;

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

void AnimTask_SquishTargetShort(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);

    PrepareAffineAnimInTaskData(task, spriteId, sSquishTargetShortAffineAnimCmds);
    task->func = AnimTask_WaitAffineAnim;
}

void CoreEnforcerLoadBeamTarget(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2)
                    +  GetBattlerSpriteCoord(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_X_2)) / 2;
    sprite->data[3] = sprite->y;
    sprite->data[4] = (GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET)
                    +  GetBattlerSpriteCoord(GetPartnerBattler(gBattleAnimTarget), BATTLER_COORD_Y_PIC_OFFSET)) / 2;
}

void AnimTask_CreateBestowItem(u8 taskId)
{
    StoreGfxTag(ANIM_TAG_ITEM_BAG);
    StorePalTag(ANIM_TAG_ITEM_BAG);

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
    if (!TryLoadSpriteAssets(&gGrudgeFlameSpriteTemplate))
    {
        DestroyTask(taskId);
        return;
    }

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
    if (GetItemHoldEffect(gBattleMons[gBattleAnimAttacker].item) == HOLD_EFFECT_DRIVE)
        gBattleAnimArgs[0] = GetItemSecondaryId(gBattleMons[gBattleAnimAttacker].item);
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
    if (gBattleMons[gBattleAnimAttacker].item == ITEM_RED_ORB || gBattleMons[gBattleAnimAttacker].item == ITEM_BLUE_ORB)
        gBattleAnimArgs[0] = gBattleMons[gBattleAnimAttacker].item;
    else
        gBattleAnimArgs[0] = 0;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_ShellSideArm(u8 taskId)
{
    if (IsBattleMovePhysical(gCurrentMove))
        gBattleAnimArgs[0] = TRUE;
    else
        gBattleAnimArgs[0] = FALSE;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_TerrainPulse(u8 taskId)
{
    if (IsAnyTerrainAffected(gBattleAnimAttacker, GetBattlerAbility(gBattleAnimAttacker), GetBattlerHoldEffect(gBattleAnimAttacker), gFieldTimers.terrain))
        gBattleAnimArgs[0] = gBattleTerrainInfo[gFieldTimers.terrain].type;
    else
        gBattleAnimArgs[0] = 0;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_AffectionHangedOn(u8 taskId)
{
    gBattleAnimArgs[0] = GetBattlerAffectionHearts(gBattleAnimTarget);
    DestroyAnimVisualTask(taskId);
}

//Launches the stat ball for Power Shift
//arg 0: X starting offset
//arg 1: Y starting offset
//arg 2: X finishing offset
//arg 3: Y finishing offset
//arg 4: Duration
//arg 5: Wave Amplitude
static void SpriteCB_PowerShiftBall(struct Sprite* sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);

    if (!IsOnPlayerSide(gBattleAnimAttacker))
        gBattleAnimArgs[2] *= -1; //Flip X

    sprite->data[0] = gBattleAnimArgs[4]; //Duration
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[2]; //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3]; //Target Y
    sprite->data[5] = gBattleAnimArgs[5]; //Wave Amplitude

    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_PowerShiftBallStep;
}

static void SpriteCB_PowerShiftBallStep(struct Sprite* sprite) // Also used by Triple Arrows
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroySpriteAndMatrix(sprite);
}

//Creates a sprite that moves left or right along the target.
//arg 0: Initial x-pixel offset
//arg 1: Initial y-pixel offset
//arg 2: Slice distance
//arg 3: Speed
//arg 4: direction
static void SpriteCB_HorizontalSlice(struct Sprite *sprite)
{
    sprite->x2 = gBattleAnimArgs[0];
    sprite->y2 = gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[2]; //Slice distance
    sprite->data[1] = gBattleAnimArgs[3]; //Slice speed
    sprite->data[2] = gBattleAnimArgs[4]; //Slice direction
    sprite->data[3] = 0; //Timer

    sprite->callback = SpriteCB_HorizontalSliceStep;
}

void SpriteCB_HorizontalSliceStep(struct Sprite *sprite)
{
    if (sprite->data[2] == 1) //Move left
        sprite->x2 -= sprite->data[1];
    else
        sprite->x2 += sprite->data[1];

    sprite->data[3] += sprite->data[1];

    if (sprite->data[3] >= sprite->data[0])
        DestroySpriteAndMatrix(sprite);
}

//Creates the slam hit for LashOut
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: flip
static void SpriteCB_LashOutStrike(struct Sprite* sprite)
{
    bool8 flip = IsOnPlayerSide(gBattleAnimTarget);

    if (gBattleAnimArgs[2])
        flip ^= 1;

    sprite->data[0] = 11;

    if (flip)
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->data[0] *= -1;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
    }

    sprite->y += gBattleAnimArgs[1];
    sprite->data[1] = 192;
    sprite->callback = AnimKnockOffStrike_Step;
}

/* TODO - Use the ShellSmash Anim
//Moves the shells towards the attacker and leaves them there until they fade out
//arg 0: Initial x-pos
//arg 1: Final x-pos
//arg 2: Movement duration
//arg 3: Affine anim
static void SpriteCB_ShellSmashShell(struct Sprite* sprite)
{
    //Init Position
    sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + 2; //2 to slightly encompass the entire sprite

    //Prepare linear movement
    sprite->data[0] = gBattleAnimArgs[2]; //Duration
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->data[4] = sprite->y;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, SpriteCB_ShellSmashShell_DestroyDuringFadeOut);

    //Rotate properly
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[3]);
}

static void SpriteCB_ShellSmashShell_DestroyDuringFadeOut(struct Sprite* sprite)
{
    if (GetGpuReg(REG_OFFSET_BLDALPHA) >= BLDALPHA_BLEND(0, 8)) //Fade out 1/2 done
        DestroyAnimSprite(sprite);
}
*/

static void SpriteCB_AnimSpriteOnTargetSideCentre(struct Sprite *sprite)
{
    enum BattlerId target = LoadBattleAnimTarget(2);

    if (!sprite->data[0])
    {
        if (IsBattlerAlly(gBattleAnimAttacker, target))
        {
            if (IsDoubleBattle())
                InitSpritePosToAnimAttackersCentre(sprite, FALSE);
            else
                InitSpritePosToAnimAttacker(sprite, FALSE);
        }
        else
        {
            if (IsDoubleBattle())
                InitSpritePosToAnimTargetsCentre(sprite, FALSE);
            else
                InitSpritePosToAnimTarget(sprite, FALSE);
        }

        sprite->data[0]++;
    }
    else if (sprite->animEnded || sprite->affineAnimEnded)
    {
        DestroySpriteAndMatrix(sprite);
    }
}

static void SpriteCB_SpriteOnMonUntilAffineAnimEnds(struct Sprite* sprite)
{
    enum BattlerId target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(target, BATTLER_COORD_Y_PIC_OFFSET);
        StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
        sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    }
}

static void SpriteCB_SpriteOnMonForDurationUseY(struct Sprite *sprite)
{
    enum BattlerId target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
        DestroyAnimSprite(sprite);
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(target, BATTLER_COORD_Y_PIC_OFFSET);

        sprite->x2 = gBattleAnimArgs[1];
        sprite->y2 = gBattleAnimArgs[2];
        sprite->data[0] = 0;
        sprite->data[1] = gBattleAnimArgs[3];
        sprite->data[2] = gBattleAnimArgs[4];
        sprite->data[3] = 0;
        sprite->callback = AnimBrickBreakWall_Step;
    }
}

//Moves a sprite upward for set amount of time
//arg 0: Bank
//arg 1: X-Offset
//arg 2: Y-Offset
//arg 3: Speed
//arg 4: Duration
static void SpriteCB_MoveSpriteUpwardsForDuration(struct Sprite* sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[2];
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[2];
    }

    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[3]; //Speed
    sprite->data[2] = gBattleAnimArgs[4]; //Duration
    sprite->callback = SpriteCB_MoveSpriteUpwardsForDurationStep;
}

static void SpriteCB_MoveSpriteUpwardsForDurationStep(struct Sprite* sprite)
{
    sprite->y -= sprite->data[1];
    if (sprite->data[0]++ > sprite->data[2])
        DestroyAnimSprite(sprite);
}

//Creates arc impacts for Surging Strikes
//arg 0: initial x pixel offset (from target)
//arg 1: initial y pixel offset (from target)
//arg 2: target x pixel offset (from target)
//arg 3: target y pixel offset (from target)
//arg 4: duration
//arg 5: wave amplitude
static void SpriteCB_SurgingStrikes(struct Sprite* sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2]; //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3]; //Target Y
    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimMissileArc_Step;
}

//Creates the moving Steel Wheel for Steel Roller
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: falling speed
//arg 3: horizontal distance
//arg 4: horizontal speed
static void SpriteCB_SteelRoller(struct Sprite* sprite)
{
    sprite->x = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y);

    sprite->x2 = gBattleAnimArgs[0];
    sprite->y2 += gBattleAnimArgs[1];

    sprite->data[4] = gBattleAnimArgs[3]; //Left/Right distance
    sprite->data[5] = gBattleAnimArgs[4]; //Left/Right speed

    sprite->data[3] = gBattleAnimArgs[2]; //Falling Speed
    sprite->callback = SpriteCB_SteelRoller_Down;
}

static void SpriteCB_SteelRoller_Down(struct Sprite *sprite)
{
    sprite->y2 += sprite->data[3];
    if (sprite->y2 >= 0)
    {
        sprite->y2 = 0;
        sprite->callback = SpriteCB_SteelRoller_LeftRight;
    }
}

static void SpriteCB_SteelRoller_LeftRight(struct Sprite* sprite)
{
    sprite->data[0] = -sprite->data[4]; //Slice distance
    sprite->data[1] = sprite->data[5]; //Slice speed
    sprite->callback = SpriteCB_LeftRightSliceStep0;
}

//Creates slashes that can be flipped.
//arg 0: x pixel offset (from target)
//arg 1: y pixel offset (from target)
//arg 2: flip x
//arg 3: flip y
static void SpriteCB_FlippableSlash(struct Sprite* sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);

    if (gBattleAnimArgs[2]) //Flip X
        sprite->hFlip = TRUE;

    if (gBattleAnimArgs[3]) //Flip Y
        sprite->vFlip = TRUE;

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    StoreSpriteCallbackInData6(sprite, AnimFalseSwipeSlice_Step3);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

//Moves the balls for Dragon Energy sideways along the target side
//arg 0: Duration
static void SpriteCB_DragonEnergyShot(struct Sprite* sprite)
{
    s16 startingX, finishingX, y;
    enum BattlerId def1 = gBattleAnimTarget;
    enum BattlerId def2 = GetPartnerBattler(def1);

    if (!IsDoubleBattle() || IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
        y = GetBattlerSpriteCoord(def1, BATTLER_COORD_Y_PIC_OFFSET);
    else
    {
        y = 0;

        if (IsBattlerSpritePresent(def1))
            y = GetBattlerSpriteCoord(def1, BATTLER_COORD_Y_PIC_OFFSET);

        if (IsBattlerSpritePresent(def2))
            y += GetBattlerSpriteCoord(def2, BATTLER_COORD_Y_PIC_OFFSET);

        if (IsBattlerSpritePresent(def1) && IsBattlerSpritePresent(def2)) //Both targets are visible
            y /= 2;
    }

    if (!IsOnPlayerSide(gBattleAnimTarget))
    {
        startingX = 0;
        finishingX = 255;
    }
    else
    {
        startingX = 255;
        finishingX = 0;
    }

    sprite->x = startingX;
    sprite->y = y;
    sprite->x2 = 0;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[2] = finishingX;
    sprite->data[4] = y;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

//Moves the butterflies created in Max Flutterby
//arg 0: initial x pixel offset
//arg 1: initial y pixel offset
//arg 2: wave amplitude
static void SpriteCB_MaxFlutterby(struct Sprite* sprite)
{
    s16 target_x;
    s16 target_y;
    if (GetMoveTarget(gAnimMoveIndex) == TARGET_BOTH)
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &target_x, &target_y);
    }
    else
    {
        target_x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        target_y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    InitSpritePosToAnimAttacker(sprite, FALSE);

    sprite->data[0] = 0x10; //Speed delay
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2); //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET); //Target Y
    sprite->data[5] = gBattleAnimArgs[2]; //Wave amplitude

    sprite->callback = SpriteCB_MaxFlutterbyStep1;
}

//The butterflies prepare to move towards the target
static void SpriteCB_MaxFlutterbyStep1(struct Sprite* sprite)
{
    if (!FuncIsActiveTask(AnimTask_DynamaxGrowthStep))
    {
        if (gAnimMoveIndex != MOVE_INFERNAL_PARADE
         && gAnimMoveIndex != MOVE_ASTRAL_BARRAGE)
            PlaySE(SE_M_SAND_ATTACK);

        StartSpriteAffineAnim(sprite, 1);
        InitAnimArcTranslation(sprite);
        sprite->callback = SpriteCB_MaxFlutterbyStep2;
    }
}

//Destroys the butterflies when they reach the target
static void SpriteCB_MaxFlutterbyStep2(struct Sprite* sprite)
{
    sprite->invisible = FALSE;

    if (TranslateAnimHorizontalArc(sprite))
    {
        if (gAnimMoveIndex == MOVE_INFERNAL_PARADE)
            PlaySE(SE_M_FLAME_WHEEL2);

        DestroySpriteAndMatrix(sprite);
    }
}

//Moves the ice lance for Glacial Lance
//arg 0: initial x pixel offset (from attacker)
//arg 1: initial y pixel offset (from attacker)
//arg 2: target x pixel offset (from target)
//arg 3: target y pixel offset (from target)
//arg 4: distance moved up
//arg 5: pause in middle
//arg 6: duration to target
static void SpriteCB_GlacialLance(struct Sprite* sprite)
{
    enum BattlerId def1 = gBattleAnimTarget;
    enum BattlerId def2 = GetPartnerBattler(def1);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[5] = gBattleAnimArgs[4];
    sprite->data[6] = gBattleAnimArgs[5];

    sprite->data[0] = gBattleAnimArgs[6];

    if (!IsDoubleBattle() || IsBattlerAlly(gBattleAnimAttacker, gBattleAnimTarget))
    {
        sprite->data[2] = GetBattlerSpriteCoord(def1, BATTLER_COORD_X_2) + gBattleAnimArgs[2]; //Converge on target
        sprite->data[4] = GetBattlerSpriteCoord(def1, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    }
    else
    {
        sprite->data[2] = (GetBattlerSpriteCoord(def1, BATTLER_COORD_X_2) + GetBattlerSpriteCoord(def2, BATTLER_COORD_X_2)) / 2 + gBattleAnimArgs[2]; //Converge on target
        sprite->data[4] = (GetBattlerSpriteCoord(def1, BATTLER_COORD_Y_PIC_OFFSET) + GetBattlerSpriteCoord(def2, BATTLER_COORD_Y_PIC_OFFSET)) / 2 + gBattleAnimArgs[3];
    }

    sprite->oam.priority = 1; //Above the ice cube
    sprite->callback = SpriteCB_GlacialLance_Step1;
}

static void SpriteCB_GlacialLance_Step1(struct Sprite* sprite)
{
    if (sprite->data[7]++ >= sprite->data[5])
    {
        sprite->data[7] = 0;
        sprite->callback = SpriteCB_GlacialLance_Step2;
    }
    else
        --sprite->y; //Move up
}

static void SpriteCB_GlacialLance_Step2(struct Sprite* sprite)
{
    if (sprite->data[7]++ >= sprite->data[6])
    {
        if (IsOnPlayerSide(gBattleAnimTarget))
            StartSpriteAffineAnim(sprite, 2);
        else
            StartSpriteAffineAnim(sprite, 1);

        sprite->data[5] = 0;
        sprite->data[6] = 0;
        sprite->data[7] = 0;
        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}


//Delivers a rainbow kick for Triple Arrows
//arg 0: Initial x pixel offset
//arg 1: Initial y pixel offset
//arg 2: Duration
//arg 3: Wave Amplitude
static void SpriteCB_TripleArrowKick(struct Sprite* sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, 1); //Feet

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2); //Target X
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET); //Target Y
    sprite->data[5] = gBattleAnimArgs[3];

    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_PowerShiftBallStep; //Arc until complete
}

// DYNAMAX
static const union AffineAnimCmd sDynamaxGrowthAffineAnimCmds[] = // from CFRU
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 64), //Double in size over 1 second
    AFFINEANIMCMD_FRAME(0, 0, 0, 64), //Pause for 1 seconds
    AFFINEANIMCMD_FRAME(16, 16, 0, 8), //Shrink back down in 1/8 of a second
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sDynamaxGrowthAttackAnimationAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-4, -4, 0, 32), //Double in size quicker
    AFFINEANIMCMD_FRAME(0, 0, 0, 32), //Pause for less
    AFFINEANIMCMD_FRAME(16, 16, 0, 8),
    AFFINEANIMCMD_END,
};

//Arg 0: Animation for attack
void AnimTask_DynamaxGrowth(u8 taskId) // from CFRU
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    if (gBattleAnimArgs[0] == 0)
        PrepareAffineAnimInTaskData(task, spriteId, sDynamaxGrowthAffineAnimCmds);
    else
        PrepareAffineAnimInTaskData(task, spriteId, sDynamaxGrowthAttackAnimationAffineAnimCmds);
    task->func = AnimTask_DynamaxGrowthStep;
}

void AnimTask_GetWeatherToSet(u8 taskId)
{
    if (MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_SUN))
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_SUN;
    else if (MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_RAIN))
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_RAIN;
    else if (MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_SANDSTORM))
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_SANDSTORM;
    else if (MoveHasAdditionalEffect(gCurrentMove, MOVE_EFFECT_HAIL))
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_HAIL;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_SyrupBomb(u8 taskId)
{
    struct Pokemon *mon = GetBattlerMon(gBattleAnimAttacker);
    gBattleAnimArgs[0] = IsMonShiny(mon);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_StickySyrup(u8 taskId)
{
    gBattleAnimArgs[0] = gAnimDisableStructPtr->syrupBombIsShiny;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_RandomBool(u8 taskId)
{
    if (RandomPercentage(RNG_NONE, 50))
        gBattleAnimArgs[ARG_RET_ID] = TRUE;
    else
        gBattleAnimArgs[ARG_RET_ID] = FALSE;

    DestroyAnimVisualTask(taskId);
}

#define PRIMAL_PULSE_SCALE_SIZE 16
#define PRIMAL_PULSE_FRAME_COUNT 4
static const union AffineAnimCmd sSpriteAffineAnim_PrimalSymbol[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(32, 32, 0, 15),
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-32, -32, 0, 15), //Shrink down again
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_PrimalSymbol[] =
{
    sSpriteAffineAnim_PrimalSymbol,
};

static const union AffineAnimCmd sSpriteAffineAnim_MegaSymbol[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0), //Start small
    AFFINEANIMCMD_FRAME(32, 32, 0, 15), //Grow sprite
    AFFINEANIMCMD_FRAME(0, 0, 0, 2), //Pause

    //Pulsate
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-PRIMAL_PULSE_SCALE_SIZE, -PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME( PRIMAL_PULSE_SCALE_SIZE,  PRIMAL_PULSE_SCALE_SIZE, 0, PRIMAL_PULSE_FRAME_COUNT),
    AFFINEANIMCMD_FRAME(-32, -32, 0, 15), //Shrink down again
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd* const gSpriteAffineAnimTable_MegaSymbol[] =
{
    sSpriteAffineAnim_MegaSymbol,
};

// Used for determining which animation to use for Order Up
void AnimTask_GetCommanderType(u8 taskId)
{
    switch (gBattleStruct->battlerState[gEffectBattler].commanderSpecies)
    {
    case SPECIES_TATSUGIRI_CURLY:
        gBattleAnimArgs[ARG_RET_ID] = ANIM_ORDER_UP_CURLY;
        break;
    case SPECIES_TATSUGIRI_DROOPY:
        gBattleAnimArgs[ARG_RET_ID] = ANIM_ORDER_UP_DROOPY;
        break;
    case SPECIES_TATSUGIRI_STRETCHY:
        gBattleAnimArgs[ARG_RET_ID] = ANIM_ORDER_UP_STRETCHY;
        break;
    default:
        gBattleAnimArgs[ARG_RET_ID] = ANIM_ORDER_UP_NONE;
        break;
    }

    DestroyAnimVisualTask(taskId);
}
