#include "global.h"
#include "malloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "math_util.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/moves.h"

struct {
    s16 startX;
    s16 startY;
    s16 targetX;
    s16 targetY;
} static EWRAM_DATA sFrenzyPlantRootData = {0}; // Debug? Written to but never read.

static void AnimMovePowderParticle_Step(struct Sprite *);
static void AnimSolarBeamSmallOrb(struct Sprite *);
static void AnimSolarBeamSmallOrb_Step(struct Sprite *);
static void AnimAbsorptionOrb_Step(struct Sprite *);
static void AnimHyperBeamOrb_Step(struct Sprite *);
static void AnimSporeParticle_Step(struct Sprite *);
static void AnimPetalDanceBigFlower_Step(struct Sprite *);
static void AnimPetalDanceSmallFlower_Step(struct Sprite *);
static void AnimRazorLeafParticle(struct Sprite *);
static void AnimRazorLeafParticle_Step1(struct Sprite *);
static void AnimRazorLeafParticle_Step2(struct Sprite *);
static void AnimLeechSeed(struct Sprite *);
static void AnimLeechSeed_Step(struct Sprite *);
static void AnimLeechSeedSprouts(struct Sprite *);
static void AnimTranslateLinearSingleSineWave_Step(struct Sprite *);
static void AnimConstrictBinding(struct Sprite *);
static void AnimConstrictBinding_Step1(struct Sprite *);
static void AnimConstrictBinding_Step2(struct Sprite *);
static void AnimIngrainRoot(struct Sprite *);
static void AnimFrenzyPlantRoot(struct Sprite *);
static void AnimRootFlickerOut(struct Sprite *);
static void AnimIngrainOrb(struct Sprite *);
static void AnimPresent(struct Sprite *);
static void AnimKnockOffItem(struct Sprite *);
static void AnimPresentHealParticle(struct Sprite *);
static void AnimItemSteal(struct Sprite *);
static void AnimItemSteal_Step1(struct Sprite *);
static void AnimItemSteal_Step2(struct Sprite *);
static void AnimItemSteal_Step3(struct Sprite *);
static void AnimTrickBag(struct Sprite *);
static void AnimTrickBag_Step1(struct Sprite *);
static void AnimTrickBag_Step2(struct Sprite *);
static void AnimTrickBag_Step3(struct Sprite *);
static void AnimFlyingParticle(struct Sprite *);
static void AnimFlyingParticle_Step(struct Sprite *);
static void AnimSlidingHit(struct Sprite *);
static void AnimWhipHit(struct Sprite *);
static void AnimFlickeringPunch(struct Sprite *);
static void AnimAirCutterSlice(struct Sprite *);
static void AnimSlice_Step(struct Sprite *);
static void AnimCirclingMusicNote(struct Sprite *);
static void AnimCirclingMusicNote_Step(struct Sprite *);
static void AnimProtect(struct Sprite *);
static void AnimProtect_Step(struct Sprite *);
static void AnimMilkBottle(struct Sprite *);
static void AnimMilkBottle_Step1(struct Sprite *);
static void AnimMilkBottle_Step2(struct Sprite *, int, int);
static void AnimSparklingStars(struct Sprite *);
static void AnimBubbleBurst(struct Sprite *);
static void AnimBubbleBurst_Step(struct Sprite *);
static void AnimSleepLetterZ(struct Sprite *);
static void AnimSleepLetterZ_Step(struct Sprite *);
static void AnimLockOnTarget(struct Sprite *);
static void AnimLockOnTarget_Step1(struct Sprite *);
static void AnimLockOnTarget_Step2(struct Sprite *);
static void AnimLockOnTarget_Step3(struct Sprite *);
static void AnimLockOnTarget_Step4(struct Sprite *);
static void AnimLockOnTarget_Step5(struct Sprite *);
static void AnimLockOnTarget_Step6(struct Sprite *);
static void AnimLockOnMoveTarget(struct Sprite *);
static void AnimBowMon(struct Sprite *);
static void AnimBowMon_Step1(struct Sprite *);
static void AnimBowMon_Step1_Callback(struct Sprite *);
static void AnimBowMon_Step2(struct Sprite *);
static void AnimBowMon_Step3(struct Sprite *);
static void AnimBowMon_Step4(struct Sprite *);
static void AnimBowMon_Step3_Callback(struct Sprite *);
static void AnimTipMon(struct Sprite *);
static void AnimTipMon_Step(struct Sprite *);
static void AnimSlashSlice(struct Sprite *);
static void AnimFalseSwipeSlice(struct Sprite *);
static void AnimFalseSwipeSlice_Step1(struct Sprite *);
static void AnimFalseSwipeSlice_Step2(struct Sprite *);
static void AnimFalseSwipePositionedSlice(struct Sprite *);
static void AnimEndureEnergy_Step(struct Sprite *);
static void AnimSharpenSphere(struct Sprite *);
static void AnimSharpenSphere_Step(struct Sprite *);
static void AnimConversion2(struct Sprite *);
static void AnimConversion2_Step(struct Sprite *);
static void AnimMoon(struct Sprite *);
static void AnimMoon_Step(struct Sprite *);
static void AnimMoonlightSparkle(struct Sprite *);
static void AnimMoonlightSparkle_Step(struct Sprite *);
static void AnimHornHit(struct Sprite *);
static void AnimHornHit_Step(struct Sprite *);
static void AnimSuperFang(struct Sprite *);
static void AnimWavyMusicNotes(struct Sprite *);
static void AnimWavyMusicNotes_Step(struct Sprite *);
static void AnimWavyMusicNotes_CalcVelocity(s16, s16, s16 *, s16 *, s8);
static void AnimFlyingMusicNotes(struct Sprite *);
static void AnimFlyingMusicNotes_Step(struct Sprite *);
static void AnimBellyDrumHand(struct Sprite *);
static void AnimSlowFlyingMusicNotes(struct Sprite *);
static void AnimSlowFlyingMusicNotes_Step(struct Sprite *);
static void AnimThoughtBubble_Step(struct Sprite *);
static void AnimMetronomeFinger_Step(struct Sprite *);
static void AnimFollowMeFinger_Step1(struct Sprite *);
static void AnimFollowMeFinger_Step2(struct Sprite *);
static void AnimTauntFinger(struct Sprite *);
static void AnimTauntFinger_Step1(struct Sprite *);
static void AnimTauntFinger_Step2(struct Sprite *);
static void AnimMoveTwisterParticle_Step(struct Sprite *);
static void AnimTask_MoonlightEndFade_Step(u8 taskId);
static void AnimTask_LeafBlade_Step(u8);
static void AnimTask_DuplicateAndShrinkToPos_Step1(u8);
static void AnimTask_DuplicateAndShrinkToPos_Step2(u8);
static s16 LeafBladeGetPosFactor(struct Sprite *);
static void AnimTask_LeafBlade_Step2(struct Task *, u8);
static void AnimTask_LeafBlade_Step2_Callback(struct Sprite *);
static void AnimTask_SkullBashPositionSet(u8);
static void AnimTask_SkullBashPositionReset(u8);
static void AnimMoveFeintSwipe(struct Sprite *);
static void AnimMoveFeintZoom(struct Sprite *);
static void AnimMoveTrumpCard(struct Sprite *);
static void AnimMoveTrumpCardParticle(struct Sprite *);
static void AnimMoveAccupressure(struct Sprite *);
static void AnimMoveWringOut(struct Sprite *);
static void AnimMoveWorrySeed(struct Sprite *);
static void AnimMoveSmallCloud(struct Sprite *);
static void AnimGrassKnotStep(struct Sprite *);
static void AnimGrassKnot(struct Sprite *);
static void AnimWoodHammerSmall(struct Sprite *);
static void AnimWoodHammerBig(struct Sprite *);
static void AnimWoodHammerHammer(struct Sprite *);
static void AnimWoodHammerHammer_WaitForPunch(struct Sprite *);
static void AnimWoodHammerHammer_WaitForDestruction(struct Sprite *);
static void AnimTask_DoubleTeam_Step(u8);
static void AnimDoubleTeam(struct Sprite *);
static void AnimNightSlash(struct Sprite *);
static void AnimRockPolishStreak(struct Sprite *);
static void AnimRockPolishSparkle(struct Sprite *);
static void AnimPoisonJabProjectile(struct Sprite *);
static void AnimNightSlash(struct Sprite *);
static void AnimPluck(struct Sprite *);

const union AnimCmd gPowderParticlesAnimCmds[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gPowderParticlesAnimTable[] =
{
    gPowderParticlesAnimCmds,
};

static const union AffineAnimCmd sFeintAffineSwipe[] = { AFFINEANIMCMD_END };
static const union AffineAnimCmd sFeintAffineZoom[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(-30, -30, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sTrumpCardAffine0[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 30, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sTrumpCardAffine1[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0xA0, 40, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sTrumpCardAffine2[] =
{
    AFFINEANIMCMD_FRAME(0xD0, 0xD0, -20, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sTrumpCardAffine3[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 40, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sTrumpCardAffine4[] =
{
    AFFINEANIMCMD_FRAME(0xF0, 0xF0, 60, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const sTrumpCardAffineAnims[] =
{
    sTrumpCardAffine0,
    sTrumpCardAffine1,
    sTrumpCardAffine2,
    sTrumpCardAffine3,
    sTrumpCardAffine4
};

static const union AffineAnimCmd * const sFeintAffineAnims[] =
{
    sFeintAffineZoom,
};

static const union AnimCmd sTrumpCardFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sTrumpCardFrame1[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sTrumpCardFrame2[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sTrumpCardParticleFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sTrumpCardParticleFrame1[] =
{
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END
};

static const union AnimCmd sTrumpCardParticleFrame2[] =
{
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END
};

static const union AnimCmd * const sTrumpCardAnims[] =
{
    sTrumpCardFrame0,
    sTrumpCardFrame1,
    sTrumpCardFrame2
};

static const union AnimCmd * const sTrumpCardParticleAnims[] =
{
    sTrumpCardParticleFrame0,
    sTrumpCardParticleFrame1,
    sTrumpCardParticleFrame2,
};

static const union AffineAnimCmd sAccupressureTurn[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 1, 20),
    AFFINEANIMCMD_FRAME(0, 0, -1, 40),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAccupressureStill[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd * const sAccupressureAffineAnims[] =
{
    sAccupressureStill,
    sAccupressureTurn
};

static const union AffineAnimCmd sSmallCloundsInit[] =
{
    AFFINEANIMCMD_FRAME(0x100,0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSmallCloudsVariant0[] =
{
    AFFINEANIMCMD_FRAME(0x100,0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-10, -10, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSmallCloudsVariant1[] =
{
    AFFINEANIMCMD_FRAME(0x180,0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-18, -18, 0, 21),
    AFFINEANIMCMD_END
};


static const union AffineAnimCmd sSmallCloudsVariant2[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(-6, -6, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd * const sSmallCloudSpriteAffineAnimTable[] =
{
    sSmallCloundsInit,
    sSmallCloudsVariant0,
    sSmallCloudsVariant1,
    sSmallCloudsVariant2,
};

const struct SpriteTemplate gWorrySeedSpriteTemplate =
{
    .tileTag = ANIM_TAG_WORRY_SEED,
    .paletteTag = ANIM_TAG_WORRY_SEED,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveWorrySeed
};

const struct SpriteTemplate gSmallCloudTemplate =
{
    .tileTag = ANIM_TAG_SMALL_CLOUD,
    .paletteTag = ANIM_TAG_SMALL_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSmallCloudSpriteAffineAnimTable,
    .callback = AnimMoveSmallCloud
};

const struct SpriteTemplate gAcupressureSpriteTemplate =
{
    .tileTag = ANIM_TAG_ACUPRESSURE,
    .paletteTag = ANIM_TAG_ACUPRESSURE,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAccupressureAffineAnims,
    .callback = AnimMoveAccupressure,
};

const struct SpriteTemplate gWringOutHandSpriteTemplate =
{
    .tileTag = ANIM_TAG_WRING_OUT,
    .paletteTag = ANIM_TAG_WRING_OUT,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveWringOut,
};

const struct SpriteTemplate gTrumpCardParticleSpriteTempalte =
{
    .tileTag = ANIM_TAG_TRUMP_CARD_PARTICLES,
    .paletteTag = ANIM_TAG_TRUMP_CARD_PARTICLES,
    .oam = &gOamData_AffineDouble_ObjNormal_8x8,
    .anims = sTrumpCardParticleAnims,
    .images = NULL,
    .affineAnims = sTrumpCardAffineAnims,
    .callback = AnimMoveTrumpCardParticle
};

const struct SpriteTemplate gTrumpCardSpriteTemplate =
{
    .tileTag = ANIM_TAG_TRUMP_CARD,
    .paletteTag = ANIM_TAG_TRUMP_CARD,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = sTrumpCardAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTrumpCard
};

const struct SpriteTemplate gFeintSwipeSpriteTemplate =
{
    .tileTag = ANIM_TAG_FEINT,
    .paletteTag = ANIM_TAG_FEINT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveFeintSwipe,
};

const struct SpriteTemplate gFeintZoomSpriteTemplate =
{
    .tileTag = ANIM_TAG_FEINT,
    .paletteTag = ANIM_TAG_FEINT,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sFeintAffineAnims,
    .callback = AnimMoveFeintZoom,
};

const struct SpriteTemplate gSleepPowderParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLEEP_POWDER,
    .paletteTag = ANIM_TAG_SLEEP_POWDER,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gPowderParticlesAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovePowderParticle,
};

const struct SpriteTemplate gStunSporeParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_STUN_SPORE,
    .paletteTag = ANIM_TAG_STUN_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gPowderParticlesAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovePowderParticle,
};

const struct SpriteTemplate gPoisonPowderParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_POISON_POWDER,
    .paletteTag = ANIM_TAG_POISON_POWDER,
    .oam = &gOamData_AffineOff_ObjNormal_8x16,
    .anims = gPowderParticlesAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovePowderParticle,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds3[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds4[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds5[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds6[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamBigOrbAnimCmds7[] =
{
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_END,
};

const union AnimCmd gSolarBeamSmallOrbAnimCms[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_END,
};

const union AnimCmd gPowerAbsorptionOrbAnimCmds[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gSolarBeamBigOrbAnimTable[] =
{
    gSolarBeamBigOrbAnimCmds1,
    gSolarBeamBigOrbAnimCmds2,
    gSolarBeamBigOrbAnimCmds3,
    gSolarBeamBigOrbAnimCmds4,
    gSolarBeamBigOrbAnimCmds5,
    gSolarBeamBigOrbAnimCmds6,
    gSolarBeamBigOrbAnimCmds7,
};

const union AnimCmd *const gSolarBeamSmallOrbAnimTable[] =
{
    gSolarBeamSmallOrbAnimCms,
};

const union AnimCmd *const gPowerAbsorptionOrbAnimTable[] =
{
    gPowerAbsorptionOrbAnimCmds,
};

const union AffineAnimCmd gPowerAbsorptionOrbAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(-5, -5, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gPowerAbsorptionOrbAffineAnimTable[] = {
    gPowerAbsorptionOrbAffineAnimCmds,
};

const struct SpriteTemplate gPowerAbsorptionOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const struct SpriteTemplate gSolarBeamBigOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSolarBeamBigOrb,
};

const struct SpriteTemplate gSolarBeamSmallOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamSmallOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSolarBeamSmallOrb,
};

const union AffineAnimCmd gStockpileAbsorptionOrbAffineCmds[] = {
    AFFINEANIMCMD_FRAME(320, 320, 0, 0),
    AFFINEANIMCMD_FRAME(-14, -14, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gStockpileAbsorptionOrbAffineAnimTable[] = {
    gStockpileAbsorptionOrbAffineCmds,
};

const struct SpriteTemplate gStockpileAbsorptionOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_GRAY_ORB,
    .paletteTag = ANIM_TAG_GRAY_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gStockpileAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb,
};

const union AffineAnimCmd gAbsorptionOrbAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(-5, -5, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gAbsorptionOrbAffineAnimTable[] = {
    gAbsorptionOrbAffineAnimCmds,
};

const struct SpriteTemplate gAbsorptionOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gAbsorptionOrbAffineAnimTable,
    .callback = AnimAbsorptionOrb,
};

const struct SpriteTemplate gHyperBeamOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHyperBeamOrb,
};

const union AnimCmd gLeechSeedAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gLeechSeedAnimCmds2[] =
{
    ANIMCMD_FRAME(4, 7),
    ANIMCMD_FRAME(8, 7),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gLeechSeedAnimTable[] =
{
    gLeechSeedAnimCmds1,
    gLeechSeedAnimCmds2,
};

const struct SpriteTemplate gLeechSeedSpriteTemplate =
{
    .tileTag = ANIM_TAG_SEED,
    .paletteTag = ANIM_TAG_SEED,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gLeechSeedAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLeechSeed,
};

const struct SpriteTemplate gPluckParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SEED_BROWN,
    .paletteTag = ANIM_TAG_SEED_BROWN,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPluck,
};

const union AnimCmd gSporeParticleAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gSporeParticleAnimCmds2[] =
{
    ANIMCMD_FRAME(4, 7),
    ANIMCMD_END,
};

const union AnimCmd *const gSporeParticleAnimTable[] =
{
    gSporeParticleAnimCmds1,
    gSporeParticleAnimCmds2,
};

const struct SpriteTemplate gSporeParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPORE,
    .paletteTag = ANIM_TAG_SPORE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSporeParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSporeParticle,
};

const union AnimCmd gPetalDanceBigFlowerAnimCmds[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gPetalDanceSmallFlowerAnimCmds[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gPetalDanceBigFlowerAnimTable[] =
{
    gPetalDanceBigFlowerAnimCmds,
};

const union AnimCmd *const gPetalDanceSmallFlowerAnimTable[] =
{
    gPetalDanceSmallFlowerAnimCmds,
};

const struct SpriteTemplate gPetalDanceBigFlowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower,
};

const struct SpriteTemplate gPetalDanceSmallFlowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gPetalDanceSmallFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceSmallFlower,
};

const union AnimCmd gRazorLeafParticleAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gRazorLeafParticleAnimCmds2[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_FRAME(28, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gRazorLeafParticleAnimTable[] =
{
    gRazorLeafParticleAnimCmds1,
    gRazorLeafParticleAnimCmds2,
};

void AnimFlyUpTarget(struct Sprite *sprite);

const struct SpriteTemplate gRazorLeafParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRazorLeafParticle,
};

const struct SpriteTemplate gGrassPledgeSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlyUpTarget,
};

const struct SpriteTemplate gTwisterLeafSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle,
};

const struct SpriteTemplate gAttackOrderParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_ATTACK_ORDER,
    .paletteTag = ANIM_TAG_ATTACK_ORDER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRazorLeafParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveTwisterParticle,
};

const union AnimCmd gRazorLeafCutterAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gRazorLeafCutterAnimTable[] =
{
    gRazorLeafCutterAnimCmds,
};

const struct SpriteTemplate gRazorLeafCutterSpriteTemplate =
{
    .tileTag = ANIM_TAG_RAZOR_LEAF,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gRazorLeafCutterAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTranslateLinearSingleSineWave,
};

const union AffineAnimCmd gSwiftStarAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gSwiftStarAffineAnimTable[] = {
    gSwiftStarAffineAnimCmds,
};

const struct SpriteTemplate gSwiftStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_YELLOW_STAR,
    .paletteTag = ANIM_TAG_YELLOW_STAR,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSwiftStarAffineAnimTable,
    .callback = AnimTranslateLinearSingleSineWave,
};

static const union AnimCmd sAnim_ConstrictBinding[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(96, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_ConstrictBinding_Flipped[] =
{
    ANIMCMD_FRAME(0,  4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_ConstrictBinding[] =
{
    sAnim_ConstrictBinding,
    sAnim_ConstrictBinding_Flipped,
};

static const union AffineAnimCmd sAffineAnim_ConstrictBinding[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-11, 0, 0, 6),
    AFFINEANIMCMD_FRAME(11, 0, 0, 6),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_ConstrictBinding_Flipped[] = {
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(11, 0, 0, 6),
    AFFINEANIMCMD_FRAME(-11, 0, 0, 6),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_ConstrictBinding[] = {
    sAffineAnim_ConstrictBinding,
    sAffineAnim_ConstrictBinding_Flipped,
};

const struct SpriteTemplate gConstrictBindingSpriteTemplate =
{
    .tileTag = ANIM_TAG_TENDRILS,
    .paletteTag = ANIM_TAG_TENDRILS,
    .oam = &gOamData_AffineNormal_ObjNormal_64x32,
    .anims = sAnims_ConstrictBinding,
    .images = NULL,
    .affineAnims = sAffineAnims_ConstrictBinding,
    .callback = AnimConstrictBinding,
};

const union AffineAnimCmd gMimicOrbAffineAnimCmds1[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 0),
    AFFINEANIMCMD_FRAME(48, 48, 0, 14),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gMimicOrbAffineAnimCmds2[] = {
    AFFINEANIMCMD_FRAME(-16, -16, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gMimicOrbAffineAnimTable[] = {
    gMimicOrbAffineAnimCmds1,
    gMimicOrbAffineAnimCmds2,
};

const struct SpriteTemplate gMimicOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gMimicOrbAffineAnimTable,
    .callback = AnimMimicOrb,
};

const union AnimCmd gIngrainRootAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_FRAME(48, 7),
    ANIMCMD_END,
};

const union AnimCmd gIngrainRootAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 7, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gIngrainRootAnimCmds3[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_END,
};

const union AnimCmd gIngrainRootAnimCmds4[] =
{
    ANIMCMD_FRAME(0, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 7, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 7, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gIngrainRootAnimTable[] =
{
    gIngrainRootAnimCmds1,
    gIngrainRootAnimCmds2,
    gIngrainRootAnimCmds3,
    gIngrainRootAnimCmds4,
};

const struct SpriteTemplate gIngrainRootSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gIngrainRootAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimIngrainRoot,
};

const struct SpriteTemplate gFrenzyPlantRootSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROOTS,
    .paletteTag = ANIM_TAG_ROOTS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gIngrainRootAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFrenzyPlantRoot,
};

const union AnimCmd gIngrainOrbAnimCmds[] =
{
    ANIMCMD_FRAME(3, 3),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gIngrainOrbAnimTable[] =
{
    gIngrainOrbAnimCmds,
};

const struct SpriteTemplate gIngrainOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_ORBS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gIngrainOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimIngrainOrb,
};

const union AnimCmd gFallingBagAnimCmds[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

const union AnimCmd *const gFallingBagAnimTable[] =
{
    gFallingBagAnimCmds,
};

const union AffineAnimCmd gFallingBagAffineAnimCmds1[] = {
    AFFINEANIMCMD_FRAME(0, 0, -4, 10),
    AFFINEANIMCMD_FRAME(0, 0, 4, 20),
    AFFINEANIMCMD_FRAME(0, 0, -4, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gFallingBagAffineAnimCmds2[] = {
    AFFINEANIMCMD_FRAME(0, 0, -1, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 1, 2),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gFallingBagAffineAnimTable[] = {
    gFallingBagAffineAnimCmds1,
    gFallingBagAffineAnimCmds2,
};

const struct SpriteTemplate gPresentSpriteTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gFallingBagAnimTable,
    .images = NULL,
    .affineAnims = gFallingBagAffineAnimTable,
    .callback = AnimPresent,
};

const struct SpriteTemplate gKnockOffItemSpriteTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gFallingBagAnimTable,
    .images = NULL,
    .affineAnims = gFallingBagAffineAnimTable,
    .callback = AnimKnockOffItem,
};

const union AnimCmd gPresentHealParticleAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gPresentHealParticleAnimTable[] =
{
    gPresentHealParticleAnimCmds,
};

const struct SpriteTemplate gPresentHealParticleSpriteTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPresentHealParticleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPresentHealParticle,
};

const struct SpriteTemplate gItemStealSpriteTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gFallingBagAnimTable,
    .images = NULL,
    .affineAnims = gFallingBagAffineAnimTable,
    .callback = AnimItemSteal,
};

const union AffineAnimCmd gTrickBagAffineAnimCmds1[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 3),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gTrickBagAffineAnimCmds2[] = {
    AFFINEANIMCMD_FRAME(0, -10, 0, 3),
    AFFINEANIMCMD_FRAME(0, -6, 0, 3),
    AFFINEANIMCMD_FRAME(0, -2, 0, 3),
    AFFINEANIMCMD_FRAME(0, 0, 0, 3),
    AFFINEANIMCMD_FRAME(0, 2, 0, 3),
    AFFINEANIMCMD_FRAME(0, 6, 0, 3),
    AFFINEANIMCMD_FRAME(0, 10, 0, 3),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gTrickBagAffineAnimTable[] = {
    gTrickBagAffineAnimCmds1,
    gTrickBagAffineAnimCmds2,
    gFallingBagAffineAnimCmds1,
    gFallingBagAffineAnimCmds2,
};

const struct SpriteTemplate gTrickBagSpriteTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gFallingBagAnimTable,
    .images = NULL,
    .affineAnims = gTrickBagAffineAnimTable,
    .callback = AnimTrickBag,
};

const s8 gTrickBagCoordinates[][3] =
{
    {5, 24,   1},
    {0,  4,   0},
    {8, 16,  -1},
    {0,  2,   0},
    {8, 16,   1},
    {0,  2,   0},
    {8, 16,   1},
    {0,  2,   0},
    {8, 16,   1},
    {0, 16,   0},
    {0,  0, 127},
};

const union AnimCmd gLeafBladeAnimCmds1[] =
{
    ANIMCMD_FRAME(28, 1),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds2[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds3[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds4[] =
{
    ANIMCMD_FRAME(28, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds5[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds6[] =
{
    ANIMCMD_FRAME(16, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gLeafBladeAnimCmds7[] =
{
    ANIMCMD_FRAME(28, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gLeafBladeAnimTable[] =
{
    gLeafBladeAnimCmds1,
    gLeafBladeAnimCmds2,
    gLeafBladeAnimCmds3,
    gLeafBladeAnimCmds4,
    gLeafBladeAnimCmds5,
    gLeafBladeAnimCmds6,
    gLeafBladeAnimCmds7,
};

const struct SpriteTemplate gLeafBladeSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gLeafBladeAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const union AffineAnimCmd gAromatherapyBigFlowerAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gAromatherapyBigFlowerAffineAnimTable[] = {
    gAromatherapyBigFlowerAffineAnimCmds,
};

const struct SpriteTemplate gAromatherapySmallFlowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gPetalDanceSmallFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlyingParticle,
};

const struct SpriteTemplate gAromatherapyBigFlowerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FLOWER,
    .paletteTag = ANIM_TAG_FLOWER,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gAromatherapyBigFlowerAffineAnimTable,
    .callback = AnimFlyingParticle,
};

const union AffineAnimCmd gSilverWindBigSparkAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -10, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gSilverWindMediumSparkAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -12, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gSilverWindSmallSparkAffineAnimCmds[] = {
    AFFINEANIMCMD_FRAME(143, 143, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -15, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gSilverWindBigSparkAffineAnimTable[] = {
    gSilverWindBigSparkAffineAnimCmds,
};

const union AffineAnimCmd *const gSilverWindMediumSparkAffineAnimTable[] = {
    gSilverWindMediumSparkAffineAnimCmds,
};

const union AffineAnimCmd *const gSilverWindSmallSparkAffineAnimTable[] = {
    gSilverWindSmallSparkAffineAnimCmds,
};

const struct SpriteTemplate gSilverWindBigSparkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSilverWindBigSparkAffineAnimTable,
    .callback = AnimFlyingParticle,
};

const struct SpriteTemplate gSilverWindMediumSparkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSilverWindMediumSparkAffineAnimTable,
    .callback = AnimFlyingParticle,
};

const struct SpriteTemplate gSilverWindSmallSparkSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_6,
    .paletteTag = ANIM_TAG_SPARKLE_6,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSilverWindSmallSparkAffineAnimTable,
    .callback = AnimFlyingParticle,
};

const u16 gMagicalLeafBlendColors[] =
{
    RGB_RED,
    RGB(31, 19, 0),
    RGB_YELLOW,
    RGB_GREEN,
    RGB(5, 14, 31),
    RGB(22, 10, 31),
    RGB(22, 21, 31),
};

const struct SpriteTemplate gNeedleArmSpikeSpriteTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_GREEN_SPIKE,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike,
};

static const union AnimCmd sAnim_Whip[] =
{
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 3),
    ANIMCMD_FRAME(112, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Whip_Flipped[] =
{
    ANIMCMD_FRAME(64, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(80, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(112, 6, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Whip[] =
{
    sAnim_Whip,
    sAnim_Whip_Flipped,
};

const struct SpriteTemplate gSlamHitSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLAM_HIT,
    .paletteTag = ANIM_TAG_SLAM_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_Whip,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWhipHit,
};

const struct SpriteTemplate gVineWhipSpriteTemplate =
{
    .tileTag = ANIM_TAG_WHIP_HIT,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_Whip,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWhipHit,
};

static const union AnimCmd sAnim_SlidingHit[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_SlidingHit[] =
{
    sAnim_SlidingHit,
};

// Unused
static const struct SpriteTemplate sSlidingHit1SpriteTemplate =
{
    .tileTag = ANIM_TAG_HIT,
    .paletteTag = ANIM_TAG_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SlidingHit,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSlidingHit,
};

// Unused
static const struct SpriteTemplate sSlidingHit2SpriteTemplate =
{
    .tileTag = ANIM_TAG_HIT_2,
    .paletteTag = ANIM_TAG_HIT_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SlidingHit,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSlidingHit,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_Normal[] = {
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedTopLeft[] = {
    AFFINEANIMCMD_FRAME(256, 256, 32, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedLeft[] = {
    AFFINEANIMCMD_FRAME(256, 256, 64, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedBottomLeft[] = {
    AFFINEANIMCMD_FRAME(256, 256, 96, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_UpsideDown[] = {
    AFFINEANIMCMD_FRAME(256, 256, -128, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedBottomRight[] = {
    AFFINEANIMCMD_FRAME(256, 256, -96, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedRight[] = {
    AFFINEANIMCMD_FRAME(256, 256, -64, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_FlickeringPunch_TurnedTopRight[] = {
    AFFINEANIMCMD_FRAME(256, 256, -32, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_FlickeringPunch[] = {
    sAffineAnim_FlickeringPunch_Normal,
    sAffineAnim_FlickeringPunch_TurnedTopLeft,
    sAffineAnim_FlickeringPunch_TurnedLeft,
    sAffineAnim_FlickeringPunch_TurnedBottomLeft,
    sAffineAnim_FlickeringPunch_UpsideDown,
    sAffineAnim_FlickeringPunch_TurnedBottomRight,
    sAffineAnim_FlickeringPunch_TurnedRight,
    sAffineAnim_FlickeringPunch_TurnedTopRight,
};

// Unused
static const struct SpriteTemplate sFlickeringPunchSpriteTemplate =
{
    .tileTag = ANIM_TAG_HANDS_AND_FEET,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_FlickeringPunch,
    .callback = AnimFlickeringPunch,
};

const union AnimCmd gCuttingSliceAnimCmds[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gCuttingSliceAnimTable[] =
{
    gCuttingSliceAnimCmds,
};

const struct SpriteTemplate gCuttingSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCuttingSlice,
};

const struct SpriteTemplate gAirCutterSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gCuttingSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAirCutterSlice,
};

static const union AnimCmd sAnim_CirclingMusicNote_Eighth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_BeamedEighth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_SlantedBeamedEighth[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_Quarter[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_QuarterRest[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_EighthRest[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_Eighth_Flipped[] =
{
    ANIMCMD_FRAME(0, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_BeamedEighth_Flipped[] =
{
    ANIMCMD_FRAME(4, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_SlantedBeamedEighth_Flipped[] =
{
    ANIMCMD_FRAME(8, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CirclingMusicNote_Quarter_Flipped[] =
{
    ANIMCMD_FRAME(12, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_CirclingMusicNote[] =
{
    sAnim_CirclingMusicNote_Eighth,
    sAnim_CirclingMusicNote_BeamedEighth,
    sAnim_CirclingMusicNote_SlantedBeamedEighth,
    sAnim_CirclingMusicNote_Quarter,
    sAnim_CirclingMusicNote_QuarterRest,
    sAnim_CirclingMusicNote_EighthRest,
    sAnim_CirclingMusicNote_Eighth_Flipped,
    sAnim_CirclingMusicNote_BeamedEighth_Flipped,
    sAnim_CirclingMusicNote_SlantedBeamedEighth_Flipped,
    sAnim_CirclingMusicNote_Quarter_Flipped,
};

// Unused
static const struct SpriteTemplate sCirclingMusicNoteSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_CirclingMusicNote,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCirclingMusicNote,
};

const struct SpriteTemplate gProtectSpriteTemplate =
{
    .tileTag = ANIM_TAG_PROTECT,
    .paletteTag = ANIM_TAG_PROTECT,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimProtect,
};

const union AffineAnimCmd gMilkBottleAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gMilkBottleAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 12),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -2, 24),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 2, 12),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gMilkBottleAffineAnimTable[] =
{
    gMilkBottleAffineAnimCmds1,
    gMilkBottleAffineAnimCmds2,
};

const struct SpriteTemplate gMilkBottleSpriteTemplate =
{
    .tileTag = ANIM_TAG_MILK_BOTTLE,
    .paletteTag = ANIM_TAG_MILK_BOTTLE,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMilkBottleAffineAnimTable,
    .callback = AnimMilkBottle,
};

const union AnimCmd gGrantingStarsAnimCmds[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(16, 7),
    ANIMCMD_FRAME(32, 7),
    ANIMCMD_FRAME(48, 7),
    ANIMCMD_FRAME(64, 7),
    ANIMCMD_FRAME(80, 7),
    ANIMCMD_FRAME(96, 7),
    ANIMCMD_FRAME(112, 7),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gGrantingStarsAnimTable[] =
{
    gGrantingStarsAnimCmds,
};

const struct SpriteTemplate gGrantingStarsSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SPARKLE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars,
};

const struct SpriteTemplate gSparklingStarsSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_SPARKLE_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSparklingStars,
};

static const union AnimCmd sAnim_BubbleBurst[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_FRAME(16, 26),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(24, 15),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BubbleBurst_Flipped[] =
{
    ANIMCMD_FRAME(0, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(12, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 26, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(24, 15, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_BubbleBurst[] =
{
    sAnim_BubbleBurst,
    sAnim_BubbleBurst_Flipped,
};

// Unused
static const struct SpriteTemplate sBubbleBurstSpriteTemplate =
{
    .tileTag = ANIM_TAG_BUBBLE_BURST,
    .paletteTag = ANIM_TAG_BUBBLE_BURST,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_BubbleBurst,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBubbleBurst,
};

const union AnimCmd gSleepLetterZAnimCmds[] =
{
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END,
};

const union AnimCmd *const gSleepLetterZAnimTable[] =
{
    gSleepLetterZAnimCmds,
};

const union AffineAnimCmd gSleepLetterZAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x14, 0x14, -30, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 1, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSleepLetterZAffineAnimCmds1_2[] =
{
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 24),
    AFFINEANIMCMD_LOOP(10),
};

const union AffineAnimCmd gSleepLetterZAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x14, 0x14, 30, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, -1, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSleepLetterZAffineAnimCmds2_2[] =
{
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 24),
    AFFINEANIMCMD_LOOP(10),
};

const union AffineAnimCmd *const gSleepLetterZAffineAnimTable[] =
{
    gSleepLetterZAffineAnimCmds1,
    gSleepLetterZAffineAnimCmds2,
};

const struct SpriteTemplate gSleepLetterZSpriteTemplate =
{
    .tileTag = ANIM_TAG_LETTER_Z,
    .paletteTag = ANIM_TAG_LETTER_Z,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gSleepLetterZAnimTable,
    .images = NULL,
    .affineAnims = gSleepLetterZAffineAnimTable,
    .callback = AnimSleepLetterZ,
};

const struct SpriteTemplate gLockOnTargetSpriteTemplate =
{
    .tileTag = ANIM_TAG_LOCK_ON,
    .paletteTag = ANIM_TAG_LOCK_ON,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLockOnTarget,
};

const struct SpriteTemplate gLockOnMoveTargetSpriteTemplate =
{
    .tileTag = ANIM_TAG_LOCK_ON,
    .paletteTag = ANIM_TAG_LOCK_ON,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLockOnMoveTarget,
};

const s8 gInclineMonCoordTable[][2] =
{
    { 64,  64},
    {  0, -64},
    {-64,  64},
    { 32, -32},
};

const struct SpriteTemplate gBowMonSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBowMon,
};

// Unused
// Same as BowMon above but without backing up
static const struct SpriteTemplate sTipMonSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTipMon,
};

const union AnimCmd gSlashSliceAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd gSlashSliceAnimCmds2[] =
{
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gSlashSliceAnimTable[] =
{
    gSlashSliceAnimCmds1,
    gSlashSliceAnimCmds2,
};

const struct SpriteTemplate gSlashSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLASH,
    .paletteTag = ANIM_TAG_SLASH,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSlashSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSlashSlice,
};

const struct SpriteTemplate gFalseSwipeSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLASH_2,
    .paletteTag = ANIM_TAG_SLASH_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSlashSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFalseSwipeSlice,
};

const struct SpriteTemplate gFalseSwipePositionedSliceSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLASH_2,
    .paletteTag = ANIM_TAG_SLASH_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSlashSliceAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFalseSwipePositionedSlice,
};

const union AnimCmd gEndureEnergyAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gEndureEnergyAnimTable[] =
{
    gEndureEnergyAnimCmds,
};

const struct SpriteTemplate gEndureEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_FOCUS_ENERGY,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gBlueEndureEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_SWEAT_BEAD,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gGreenEndureEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_WHIP_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};

const struct SpriteTemplate gYellowEndureEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_FOCUS_ENERGY,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gEndureEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEndureEnergy,
};

const union AnimCmd gSharpenSphereAnimCmds[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 18),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 18),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(64, 18),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(64, 54),
    ANIMCMD_END,
};

const union AnimCmd *const gSharpenSphereAnimTable[] =
{
    gSharpenSphereAnimCmds,
};

const struct SpriteTemplate gSharpenSphereSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPHERE_TO_CUBE,
    .paletteTag = ANIM_TAG_SPHERE_TO_CUBE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSharpenSphereAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSharpenSphere,
};

const struct SpriteTemplate gOctazookaBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL,
    .paletteTag = ANIM_TAG_BLACK_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const union AnimCmd gOctazookaAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gOctazookaAnimTable[] =
{
    gOctazookaAnimCmds,
};

const struct SpriteTemplate gOctazookaSmokeSpriteTemplate =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_GRAY_SMOKE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOctazookaAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const union AnimCmd gConversionAnimCmds[] =
{
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gConversionAnimTable[] =
{
    gConversionAnimCmds,
};

const union AffineAnimCmd gConversionAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gConversionAffineAnimTable[] =
{
    gConversionAffineAnimCmds,
};

const struct SpriteTemplate gConversionSpriteTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_CONVERSION,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversionAnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion,
};

const union AnimCmd gConversion2AnimCmds[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gConversion2AnimTable[] =
{
    gConversion2AnimCmds,
};

const struct SpriteTemplate gConversion2SpriteTemplate =
{
    .tileTag = ANIM_TAG_CONVERSION,
    .paletteTag = ANIM_TAG_CONVERSION,
    .oam = &gOamData_AffineDouble_ObjBlend_8x8,
    .anims = gConversion2AnimTable,
    .images = NULL,
    .affineAnims = gConversionAffineAnimTable,
    .callback = AnimConversion2,
};

const struct SpriteTemplate gMoonSpriteTemplate =
{
    .tileTag = ANIM_TAG_MOON,
    .paletteTag = ANIM_TAG_MOON,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoon,
};

const union AnimCmd gMoonlightSparkleAnimCmds[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gMoonlightSparkleAnimTable[] =
{
    gMoonlightSparkleAnimCmds,
};

const struct SpriteTemplate gMoonlightSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPARKLE,
    .paletteTag = ANIM_TAG_GREEN_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gMoonlightSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoonlightSparkle,
};

const union AnimCmd gHealingBlueStarAnimCmds[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 3),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gHealingBlueStarAnimTable[] =
{
    gHealingBlueStarAnimCmds,
};

const struct SpriteTemplate gHealingBlueStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_STAR,
    .paletteTag = ANIM_TAG_BLUE_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gHealingBlueStarAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gHornHitSpriteTemplate =
{
    .tileTag = ANIM_TAG_HORN_HIT,
    .paletteTag = ANIM_TAG_HORN_HIT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHornHit,
};

const union AnimCmd gSuperFangAnimCmds[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gSuperFangAnimTable[] =
{
    gSuperFangAnimCmds,
};

const struct SpriteTemplate gSuperFangSpriteTemplate =
{
    .tileTag = ANIM_TAG_FANG_ATTACK,
    .paletteTag = ANIM_TAG_FANG_ATTACK,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gSuperFangAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSuperFang,
};

const union AnimCmd gWavyMusicNotesAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds2[] =
{
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds3[] =
{
    ANIMCMD_FRAME(8, 41),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds4[] =
{
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds5[] =
{
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds6[] =
{
    ANIMCMD_FRAME(20, 10),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds7[] =
{
    ANIMCMD_FRAME(0, 10, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gWavyMusicNotesAnimCmds8[] =
{
    ANIMCMD_FRAME(4, 10, .vFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gMusicNotesAnimTable[] =
{
    gWavyMusicNotesAnimCmds1,
    gWavyMusicNotesAnimCmds2,
    gWavyMusicNotesAnimCmds3,
    gWavyMusicNotesAnimCmds4,
    gWavyMusicNotesAnimCmds5,
    gWavyMusicNotesAnimCmds6,
    gWavyMusicNotesAnimCmds7,
    gWavyMusicNotesAnimCmds8,
};

const union AffineAnimCmd gWavyMusicNotesAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0xC, 0xC, 0, 16),
    AFFINEANIMCMD_FRAME(0xFFF4, 0xFFF4, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gMusicNotesAffineAnimTable[] =
{
    gWavyMusicNotesAffineAnimCmds,
};

const struct SpriteTemplate gWavyMusicNotesSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gMusicNotesAnimTable,
    .images = NULL,
    .affineAnims = gMusicNotesAffineAnimTable,
    .callback = AnimWavyMusicNotes,
};

const u16 gParticlesColorBlendTable[][6] =
{
    {ANIM_TAG_MUSIC_NOTES,     RGB_WHITE, RGB(31, 26, 28), RGB(31, 22, 26), RGB(31, 17, 24), RGB(31, 13, 22)},
    {ANIM_TAG_BENT_SPOON,      RGB_WHITE, RGB(25, 31, 26), RGB(20, 31, 21), RGB(15, 31, 16), RGB(10, 31, 12)},
    {ANIM_TAG_SPHERE_TO_CUBE,  RGB_WHITE, RGB(31, 31, 24), RGB(31, 31, 17), RGB(31, 31, 10), RGB(31, 31, 3)},
    {ANIM_TAG_LARGE_FRESH_EGG, RGB_WHITE, RGB(26, 28, 31), RGB(21, 26, 31), RGB(16, 24, 31), RGB(12, 22, 31)},
};

const struct SpriteTemplate gFastFlyingMusicNotesSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gMusicNotesAnimTable,
    .images = NULL,
    .affineAnims = gMusicNotesAffineAnimTable,
    .callback = AnimFlyingMusicNotes,
};

const struct SpriteTemplate gBellyDrumHandSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
    .paletteTag = ANIM_TAG_PURPLE_HAND_OUTLINE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBellyDrumHand,
};

const union AffineAnimCmd gSlowFlyingMusicNotesAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0xA0, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gSlowFlyingMusicNotesAffineAnimTable[] =
{
    gSlowFlyingMusicNotesAffineAnimCmds,
};

const struct SpriteTemplate gSlowFlyingMusicNotesSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gMusicNotesAnimTable,
    .images = NULL,
    .affineAnims = gSlowFlyingMusicNotesAffineAnimTable,
    .callback = AnimSlowFlyingMusicNotes,
};

const union AnimCmd gMetronomeThroughtBubbleAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gMetronomeThroughtBubbleAnimCmds3[] =
{
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gMetronomeThroughtBubbleAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd gMetronomeThroughtBubbleAnimCmds4[] =
{
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gMetronomeThroughtBubbleAnimTable[] =
{
    gMetronomeThroughtBubbleAnimCmds1,
    gMetronomeThroughtBubbleAnimCmds2,
    gMetronomeThroughtBubbleAnimCmds3,
    gMetronomeThroughtBubbleAnimCmds4,
};

const struct SpriteTemplate gThoughtBubbleSpriteTemplate =
{
    .tileTag = ANIM_TAG_THOUGHT_BUBBLE,
    .paletteTag = ANIM_TAG_THOUGHT_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gMetronomeThroughtBubbleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThoughtBubble,
};

const union AffineAnimCmd gMetronomeFingerAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x1E, 0x1E, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gMetronomeFingerAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 11),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 11),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gMetronomeFingerAffineAnimCmds2_2[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(30, 30, 0, 8),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 11),
    AFFINEANIMCMD_FRAME(0, 0, -4, 11),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_FRAME(-30, -30, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gMetronomeFingerAffineAnimTable[] =
{
    gMetronomeFingerAffineAnimCmds1,
    gMetronomeFingerAffineAnimCmds2,
};

const struct SpriteTemplate gMetronomeFingerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimMetronomeFinger,
};

const struct SpriteTemplate gFollowMeFingerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMetronomeFingerAffineAnimTable,
    .callback = AnimFollowMeFinger,
};

const union AffineAnimCmd gTeaAffineAnimCmds1[] =
{
        AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
        AFFINEANIMCMD_FRAME(0x1E, 0x1E, 0, 8),
        AFFINEANIMCMD_END,
};

const union AffineAnimCmd gTeaAffineAnimCmds2[] =
{
        AFFINEANIMCMD_FRAME(0x0, 0x0, -3, 11),
        AFFINEANIMCMD_FRAME(0x0, 0x0, 3, 11),
        AFFINEANIMCMD_LOOP(2),
        AFFINEANIMCMD_FRAME(0xFFE2, 0xFFE2, 0, 8),
        AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gTeaAffineAnimTable[] =
{
        gTeaAffineAnimCmds1,
        gTeaAffineAnimCmds2,
};

const struct SpriteTemplate gTeapotSpriteTemplate =
{
        .tileTag = ANIM_TAG_TEAPOT,
        .paletteTag = ANIM_TAG_TEAPOT,
        .oam = &gOamData_AffineDouble_ObjNormal_64x64,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gTeaAffineAnimTable,
        .callback = AnimMetronomeFinger,
};

const union AnimCmd gTauntFingerAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gTauntFingerAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gTauntFingerAnimCmds3[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};

const union AnimCmd gTauntFingerAnimCmds4[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gTauntFingerAnimTable[] =
{
    gTauntFingerAnimCmds1,
    gTauntFingerAnimCmds2,
    gTauntFingerAnimCmds3,
    gTauntFingerAnimCmds4,
};

const struct SpriteTemplate gTauntFingerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FINGER_2,
    .paletteTag = ANIM_TAG_FINGER_2,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gTauntFingerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTauntFinger,
};

const struct SpriteTemplate gPowerOrbs_Float =
{
	.tileTag = ANIM_TAG_RED_ORB,
	.paletteTag = ANIM_TAG_RED_ORB,
	.oam = &gOamData_AffineOff_ObjNormal_16x16,
	.anims = gSporeParticleAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = AnimSporeParticle,
};

const union AnimCmd gRockPolishStreak_AnimCmd[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(12, 15),
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gRockPolishStreak_AnimCmds[] =
{
    gRockPolishStreak_AnimCmd,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd2[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x20, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd3[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x30, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x40, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd5[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x50, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd6[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x60, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd7[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x70, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd8[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x80, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmd9[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x90, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdA[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xA0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdB[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xB0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdC[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xC0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdD[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xD0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdE[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xE0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gRockPolishStreak_AffineAnimCmdF[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xF0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gRockPolishStreak_AffineAnimCmds[] =
{
    gRockPolishStreak_AffineAnimCmd0,
    gRockPolishStreak_AffineAnimCmd1,
    gRockPolishStreak_AffineAnimCmd2,
    gRockPolishStreak_AffineAnimCmd3,
    gRockPolishStreak_AffineAnimCmd4,
    gRockPolishStreak_AffineAnimCmd5,
    gRockPolishStreak_AffineAnimCmd6,
    gRockPolishStreak_AffineAnimCmd7,
    gRockPolishStreak_AffineAnimCmd8,
    gRockPolishStreak_AffineAnimCmd9,
    gRockPolishStreak_AffineAnimCmdA,
    gRockPolishStreak_AffineAnimCmdB,
    gRockPolishStreak_AffineAnimCmdC,
    gRockPolishStreak_AffineAnimCmdD,
    gRockPolishStreak_AffineAnimCmdE,
    gRockPolishStreak_AffineAnimCmdF,
};

const struct SpriteTemplate gRockPolishStreakSpriteTemplate =
{
    .tileTag = ANIM_TAG_WHITE_STREAK,
    .paletteTag = ANIM_TAG_WHITE_STREAK,
    .oam = &gOamData_AffineDouble_ObjBlend_32x8,
    .anims = gRockPolishStreak_AnimCmds,
    .images = NULL,
    .affineAnims = gRockPolishStreak_AffineAnimCmds,
    .callback = AnimRockPolishStreak,
};

const union AnimCmd gRockPolishSparkle_AnimCmd1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(4, 7),
    ANIMCMD_FRAME(8, 7),
    ANIMCMD_FRAME(12, 7),
    ANIMCMD_END,
};

const union AnimCmd *const gRockPolishSparkle_AnimCmds[] =
{
    gRockPolishSparkle_AnimCmd1,
};

const struct SpriteTemplate gRockPolishSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_3,
    .paletteTag = ANIM_TAG_SPARKLE_3,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gRockPolishSparkle_AnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRockPolishSparkle,
};

const struct SpriteTemplate gPoisonJabProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_JAB,
    .paletteTag = ANIM_TAG_PURPLE_JAB,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPoisonJabProjectile,
};

const union AnimCmd gNightSlashLeftAnimCmd0[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd gNightSlashLeftAnimCmd1[] =
{
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gNightSlashLeftAnimTable[] =
{
    gNightSlashLeftAnimCmd0,
    gNightSlashLeftAnimCmd1,
};

const struct SpriteTemplate gNightSlashLeftSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLASH,
    .paletteTag = ANIM_TAG_SLASH,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gNightSlashLeftAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNightSlash,
};

const union AnimCmd gNightSlashRightAnimCmd0[] =
{
    ANIMCMD_FRAME(0, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gNightSlashRightAnimCmd1[] =
{
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gNightSlashRightAnimTable[] =
{
    gNightSlashRightAnimCmd0,
    gNightSlashRightAnimCmd1,
};

const struct SpriteTemplate gNightSlashRightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLASH,
    .paletteTag = ANIM_TAG_SLASH,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gNightSlashRightAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNightSlash,
};

const struct SpriteTemplate gLuckyChantBigStarsSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPetalDanceBigFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceBigFlower,
};

const struct SpriteTemplate gLuckyChantSmallStarsSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gPetalDanceSmallFlowerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPetalDanceSmallFlower,
};

const union AnimCmd gWoodHammerBigAnimCmd_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gWoodHammerBigAnimCmd_2[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gWoodHammerBigAnims[] =
{
    gWoodHammerBigAnimCmd_1,
    gWoodHammerBigAnimCmd_2,
};

const union AffineAnimCmd gWoodHammerBigAffineAnimCmd_1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gWoodHammerBigAffineAnimCmd_2[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 5, 5),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gWoodHammerBigAffineAnims[] =
{
    gWoodHammerBigAffineAnimCmd_1,
    gWoodHammerBigAffineAnimCmd_2,
};

#define WOOD_HAMMER_SCALE_STEP 5
#define WOOD_HAMMER_CC_ROTATION_STEP 2
#define WOOD_HAMMER_BACKWARDS_DURATION 40
#define WOOD_HAMMER_ROTATED_AMOUNT (WOOD_HAMMER_CC_ROTATION_STEP * WOOD_HAMMER_BACKWARDS_DURATION)
#define WOOD_HAMMER_SCALED_AMOUNT (WOOD_HAMMER_SCALE_STEP * WOOD_HAMMER_BACKWARDS_DURATION)

const union AffineAnimCmd gWoodHammerHammerAffineAnimCmd_BackwardsRotateAndScale[] =
{
    AFFINEANIMCMD_FRAME(WOOD_HAMMER_SCALE_STEP, WOOD_HAMMER_SCALE_STEP, WOOD_HAMMER_CC_ROTATION_STEP, WOOD_HAMMER_BACKWARDS_DURATION),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd gWoodHammerHammerAffineAnimCmd_BackwardsRotateAndScaleFlipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-WOOD_HAMMER_SCALE_STEP, WOOD_HAMMER_SCALE_STEP, -WOOD_HAMMER_CC_ROTATION_STEP, WOOD_HAMMER_BACKWARDS_DURATION),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd gWoodHammerHammerAffineAnimCmd_PunchClockwise[] =
{
    AFFINEANIMCMD_FRAME(0x100 + WOOD_HAMMER_SCALED_AMOUNT, 0x100 + WOOD_HAMMER_SCALED_AMOUNT, WOOD_HAMMER_ROTATED_AMOUNT, 0),
    AFFINEANIMCMD_FRAME(0, 0, -16, 7),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd gWoodHammerHammerAffineAnimCmd_PunchCounterClockwise[] =
{
    AFFINEANIMCMD_FRAME(-0x100 - WOOD_HAMMER_SCALED_AMOUNT, 0x100 + WOOD_HAMMER_SCALED_AMOUNT, -WOOD_HAMMER_ROTATED_AMOUNT, 0),
    AFFINEANIMCMD_FRAME(0, 0, 16, 7),
    AFFINEANIMCMD_END
};

// Animations 0, 2 are for the player side attacking
// Animations 1, 3 are for the opponent side attacking (flipped)
const union AffineAnimCmd *const gWoodHammerHammerAffineAnims[] =
{
    gWoodHammerHammerAffineAnimCmd_BackwardsRotateAndScale,
    gWoodHammerHammerAffineAnimCmd_BackwardsRotateAndScaleFlipped,
    gWoodHammerHammerAffineAnimCmd_PunchClockwise,
    gWoodHammerHammerAffineAnimCmd_PunchCounterClockwise,
};

const union AnimCmd gWoodHammerSmallAnimCmd_1[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END,
};

const union AnimCmd gWoodHammerSmallAnimCmd_2[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd gWoodHammerSmallAnimCmd_3[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gWoodHammerSmallAnims[] =
{
    gWoodHammerSmallAnimCmd_1,
    gWoodHammerSmallAnimCmd_2,
    gWoodHammerSmallAnimCmd_3,
};

const struct SpriteTemplate gGrassKnotSpriteTemplate =
{
    .tileTag = ANIM_TAG_RAZOR_LEAF,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gRazorLeafCutterAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrassKnot,
};

const struct SpriteTemplate gWoodHammerBigSpriteTemplate =
{
    .tileTag = ANIM_TAG_WOOD_HAMMER,
    .paletteTag = ANIM_TAG_WOOD_HAMMER,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gWoodHammerBigAnims,
    .images = NULL,
    .affineAnims = gWoodHammerBigAffineAnims,
    .callback = AnimWoodHammerBig,
};

const struct SpriteTemplate gWoodHammerSmallSpriteTemplate =
{
    .tileTag = ANIM_TAG_WOOD_HAMMER,
    .paletteTag = ANIM_TAG_WOOD_HAMMER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gWoodHammerSmallAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWoodHammerSmall,
};

const struct SpriteTemplate gWoodHammerHammerSpriteTemplate =
{
    .tileTag = ANIM_TAG_WOOD_HAMMER_HAMMER,
    .paletteTag = ANIM_TAG_WOOD_HAMMER_HAMMER,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gWoodHammerHammerAffineAnims,
    .callback = AnimWoodHammerHammer,
};

const struct SpriteTemplate gJudgmentGrayOutwardSpikesTemplate =
{
    .tileTag = ANIM_TAG_GREEN_SPIKE,
    .paletteTag = ANIM_TAG_GUST,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gJudgmentGrayInwardOrbsTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimNeedleArmSpike
};

const struct SpriteTemplate gDarkVoidPurpleStarsTemplate =
{
    .tileTag = ANIM_TAG_SPARKLE_2,
    .paletteTag = ANIM_TAG_POISON_BUBBLE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gGrantingStarsAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGrantingStars
};

const struct SpriteTemplate gSeedFlareGreenCirclesTemplate =
{
    .tileTag = ANIM_TAG_ORBS,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gPowerAbsorptionOrbAnimTable,
    .images = NULL,
    .affineAnims = gPowerAbsorptionOrbAffineAnimTable,
    .callback = AnimPowerAbsorptionOrb
};

// functions
static void AnimGrassKnot(struct Sprite *sprite)
{
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget && GetBattlerPosition(gBattleAnimTarget) < B_POSITION_PLAYER_RIGHT)
        gBattleAnimArgs[0] *= -1;

    InitSpritePosToAnimTarget(sprite, TRUE);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y;

    InitAnimLinearTranslation(sprite);

    sprite->data[5] = gBattleAnimArgs[5];
    sprite->data[6] = gBattleAnimArgs[4];
    sprite->data[7] = 0;

    sprite->callback = AnimGrassKnotStep;
}

static void AnimGrassKnotStep(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->y2 += Sin(sprite->data[7] >> 8, sprite->data[5]);
        sprite->data[7] += sprite->data[6];
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimWoodHammerBig(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        StartSpriteAffineAnim(sprite, 1);

    TranslateAnimSpriteToTargetMonLocation(sprite);
}

static void AnimWoodHammerSmall(struct Sprite *sprite)
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

#define HAMMER_X_OFFSET 40
#define HAMMER_PUNCH_WAIT_FRAMES 37

static void AnimWoodHammerHammer(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x += HAMMER_X_OFFSET;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->x -= HAMMER_X_OFFSET;
        StartSpriteAffineAnim(sprite, 0);
    }
    sprite->data[6] = HAMMER_PUNCH_WAIT_FRAMES;
    sprite->callback = AnimWoodHammerHammer_WaitForPunch;
}

static void AnimWoodHammerHammer_WaitForPunch(struct Sprite *sprite)
{
    if (!sprite->affineAnimEnded)
        return;

    if (sprite->data[6] != 0)
    {
        sprite->data[6]--;
        if (sprite->data[6] & 1)
        {
            if ((sprite->data[6] / 2) & 1)
                sprite->x2++;
            else
                sprite->x2--;
        }
        return;
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        StartSpriteAffineAnim(sprite, 3);
    }
    else
    {
        StartSpriteAffineAnim(sprite, 2);
    }
    sprite->callback = AnimWoodHammerHammer_WaitForDestruction;
}

static void AnimWoodHammerHammer_WaitForDestruction(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        DestroySpriteAndMatrix(sprite);
    }
}

#undef HAMMER_X_OFFSET
#undef HAMMER_PUNCH_WAIT_FRAMES

// Animates the falling particles that horizontally wave back and forth.
// Used by Sleep Powder, Stun Spore, and Poison Powder.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: total duration in frames
// arg 3: vertical movement speed (sub-pixel value)
// arg 4: wave amplitude
// arg 5: wave speed
void AnimMovePowderParticle(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];

    if (GetBattlerSide(gBattleAnimAttacker))
    {
        sprite->data[3] = -gBattleAnimArgs[4];
    }
    else
    {
        sprite->data[3] = gBattleAnimArgs[4];
    }

    sprite->data[4] = gBattleAnimArgs[5];
    sprite->callback = AnimMovePowderParticle_Step;
}

static void AnimMovePowderParticle_Step(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->y2 = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[1];
        sprite->x2 = Sin(sprite->data[5], sprite->data[3]);
        sprite->data[5] = (sprite->data[5] + sprite->data[4]) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Moves an energy orb towards the center of the mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
void AnimPowerAbsorptionOrb(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// Moves an orb in a straight line towards the target mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
// arg 3: sprite anim number
void AnimSolarBeamBigOrb(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[3]);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Moves a small orb in a wavy pattern towards the target mon.
// The small orb "circles" the big orbs in AnimSolarBeamBigOrb.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
// arg 3: initial wave offset
static void AnimSolarBeamSmallOrb(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);

    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gAnimMoveIndex == MOVE_CORE_ENFORCER)
    {
        CoreEnforcerLoadBeamTarget(sprite);
    }
    else
    {
        sprite->data[0] = gBattleAnimArgs[2];
        sprite->data[1] = sprite->x;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[3] = sprite->y;
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    InitAnimLinearTranslation(sprite);
    sprite->data[5] = gBattleAnimArgs[3];
    sprite->callback = AnimSolarBeamSmallOrb_Step;
    sprite->callback(sprite);
}

static void AnimSolarBeamSmallOrb_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        DestroySprite(sprite);
    }
    else
    {
        if (sprite->data[5] > 0x7F)
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 1;
        else
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 6;

        sprite->x2 += Sin(sprite->data[5], 5);
        sprite->y2 += Cos(sprite->data[5], 14);
        sprite->data[5] = (sprite->data[5] + 15) & 0xFF;
    }
}

// Creates 15 small secondary orbs used in the SolarBeam anim effect.
// There is a 7-frame delay between each of them.
// No args.
void AnimTask_CreateSmallSolarBeamOrbs(u8 taskId)
{
    if (--gTasks[taskId].data[0] == -1)
    {
        gTasks[taskId].data[1]++;
        gTasks[taskId].data[0] = 6;
        gBattleAnimArgs[0] = 15;
        gBattleAnimArgs[1] = 0;
        gBattleAnimArgs[2] = 80;
        gBattleAnimArgs[3] = 0;
        CreateSpriteAndAnimate(&gSolarBeamSmallOrbSpriteTemplate, 0, 0, GetBattlerSpriteSubpriority(gBattleAnimTarget) + 1);
    }

    if (gTasks[taskId].data[1] == 15)
        DestroyAnimVisualTask(taskId);
}

// Moves an orb from the target mon to the attacking mon in an arc-like fashion.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: wave amplitude
// arg 3: wave period (lower means faster wave)
void AnimAbsorptionOrb(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[5] = gBattleAnimArgs[2];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimAbsorptionOrb_Step;
}

static void AnimAbsorptionOrb_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

// Moves an orb in a wave-like fashion towards the target mon. The wave's
// properties and the sprite anim are randomly determined.
void AnimHyperBeamOrb(struct Sprite *sprite)
{
    u16 speed;
    u16 animNum = Random2();

    StartSpriteAnim(sprite, animNum % 8);
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= 20;
    else
        sprite->x += 20;

    speed = Random2();
    sprite->data[0] = (speed & 31) + 64;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimFastLinearTranslationWithSpeed(sprite);
    sprite->data[5] = Random2() & 0xFF;
    sprite->data[6] = sprite->subpriority;
    sprite->callback = AnimHyperBeamOrb_Step;
    sprite->callback(sprite);
}

static void AnimHyperBeamOrb_Step(struct Sprite *sprite)
{
    if (AnimFastTranslateLinear(sprite))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->y2 += Cos(sprite->data[5], 12);
        if (sprite->data[5] < 0x7F)
            sprite->subpriority = sprite->data[6];
        else
            sprite->subpriority = sprite->data[6] + 1;

        sprite->data[5] += 24;
        sprite->data[5] &= 0xFF;
    }
}

static void AnimMoveWorrySeedWait(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: wave period
// arg 3: wave amplitude
static void AnimMoveWorrySeed(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[5] = gBattleAnimArgs[3];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimMoveWorrySeedWait;
}

static void AnimMoveSmallCloudAnimate(struct Sprite *sprite)
{
    sprite->x2 += sprite->data[0];
    sprite->y2 += sprite->data[1];

    if(sprite->affineAnimEnded)
    {
        DestroyAnimSprite(sprite);
    }

}
#define ONE_IF_ZERO(x) ((x) > 0 ? (x) : 1)

// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: cloud type animation [0..2]
// arg 3: horizontal velocity
// arg 4: vertical velocity
// arg 5: duration
static void AnimMoveSmallCloud(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[4];
    sprite->callback = AnimMoveSmallCloudAnimate;
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[2]+1);
}

static void AnimPluckParticle(struct Sprite *sprite)
{
    if(sprite->data[0] > 0)
    {
        s16 yVelocity = sprite->data[5];
        s16 xVelocity = sprite->data[2];
        sprite->y -= yVelocity;
        sprite->x += xVelocity;
        if((sprite->data[0] % 7) == 0)
        {
            sprite->data[5] = yVelocity-1;
        }
        sprite->data[0]--;
    }
    else
    {
        sprite->callback = DestroyAnimSprite;
    }
}

// brown seed particle (jumps up, falls down.)
// used by Pluck.
// arg 0: initial x offset from target
// arg 1: initial y offset from target
// arg 2: lifetime of the particle
// arg 3: upward velocity initial (decreases over time)
// arg 4: horizontal velocity (stays the same)
static void AnimPluck(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[2]; //lifetime of the particle
    sprite->data[5] = gBattleAnimArgs[3]; //upward velocity
    sprite->data[2] = gBattleAnimArgs[4]; //horizontal velocity
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->callback = AnimPluckParticle;
}

static void AnimMoveFeintSwipeStep(struct Sprite *sprite)
{
    switch(sprite->data[5])
    {
    case 0:
        if(AnimTranslateLinear(sprite))
        {
            //Not the most elegant solution here, but it works without messing up the sprites coordinates
            sprite->x2 = 0;
            sprite->x += 64;
            sprite->data[5]++;
            sprite->data[0] = sprite->data[6];
            sprite->data[1] = sprite->x;
            sprite->data[2] = sprite->x - 64;
            sprite->data[3] = sprite->y;
            sprite->data[4] = sprite->y;
            InitAnimLinearTranslation(sprite);
        }
        break;
    case 1:
        if(AnimTranslateLinear(sprite))
        {
            sprite->callback = DestroyAnimSprite;
        }
        break;
    }

}

static void AnimMoveFeintSwipe(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    }
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + 64;
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y;
    sprite->data[5] = 0;
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimMoveFeintSwipeStep;
}

static void AnimMoveFeintZoom(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

static void AnimMoveTrumpCardArc(struct Sprite *sprite)
{
    if(AnimTranslateLinear(sprite))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->y2 = Sin(sprite->data[5], -20);
        sprite->data[5] -= sprite->data[6];
    }

}

static void AnimMoveTrumpCard(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    }
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x - 80;
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y;
    sprite->data[5] = 128;
    sprite->data[6] = 128 / sprite->data[0];
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimMoveTrumpCardArc;
}

static void AnimMoveTrumpCardParticleAlive(struct Sprite *sprite)
{
    if(sprite->data[0] > 0)
    {
        s16 yVelocity = sprite->data[2];
        s16 xVelocity = sprite->data[1];
        sprite->y -= yVelocity;
        sprite->x += xVelocity;
        if((sprite->data[0] % 2) == 0)
        {
            if(xVelocity > 0)
                xVelocity--;
            else if(xVelocity < 0)
                xVelocity++;

            if(yVelocity > 0)
                yVelocity--;
            else if(yVelocity < 0)
                yVelocity++;
            sprite->data[1] = xVelocity;
            sprite->data[2] = yVelocity;
        }
        sprite->data[0]--;
    }
    else
    {
        sprite->callback = DestroyAnimSprite;
    }
}

static void AnimMoveTrumpCardParticle(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
    }
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[6]);
    sprite->data[0] = gBattleAnimArgs[3]; //lifespan
    sprite->data[1] = gBattleAnimArgs[4]; //horizontal velocity, decaying
    sprite->data[2] = gBattleAnimArgs[5]; //vertical velocity, decaying
    sprite->callback = AnimMoveTrumpCardParticleAlive;
}

static void AnimMoveAccupressureTransition(struct Sprite *sprite)
{
    switch(sprite->data[5])
    {
    case 0:
        if(AnimTranslateLinear(sprite))
        {
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[5]++;
        }
        break;
    case 1:
        if(sprite->affineAnimEnded)
        {
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

static void AnimMoveAccupressure(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    sprite->data[5] = 0;
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimMoveAccupressureTransition;
}

static void AnimMoveWringOutCircle(struct Sprite *sprite)
{
    sprite->x2 = Cos(sprite->data[3], sprite->data[2]);
    sprite->y2 = Sin(sprite->data[3], sprite->data[2]);
    if(sprite->data[1] > 0)
    {
        if(sprite->data[3] + sprite->data[0] >= 256)
        {
            sprite->data[3] = (sprite->data[0] + sprite->data[3]) % 256;
            sprite->data[1]--;
        }
        else
        {
            sprite->data[3] += sprite->data[0];
        }

    }
    else if(sprite->data[3] < 64)
    {
        //We need to go for an extra 90°
        sprite->data[3] += sprite->data[0];
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimMoveWringOut(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    if(gBattleAnimArgs[5] == TRUE)
    {
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;
    }
    sprite->data[0] = 256 / gBattleAnimArgs[2]; //step size
    sprite->data[1] = gBattleAnimArgs[3]; //Number of circle spins
    sprite->data[2] = gBattleAnimArgs[4]; //radius
    sprite->data[3] = 64; //current angle 90°
    sprite->callback = AnimMoveWringOutCircle;
}

// seed (sprouts a sapling from a seed.)
// Used by Leech Seed.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x pixel offset
// arg 3: target y pixel offset
// arg 4: duration
// arg 5: wave amplitude
static void AnimLeechSeed(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimLeechSeed_Step;
}

static void AnimLeechSeed_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->invisible = TRUE;
        sprite->data[0] = 10;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimLeechSeedSprouts);
    }
}

static void AnimLeechSeedSprouts(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    StartSpriteAnim(sprite, 1);
    sprite->data[0] = 60;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Moves a spore particle in a halo around the target mon.
// The sprite's priority is updated to give the effect of going
// behind the mon's sprite.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wave offset
// arg 3: duration
// arg 4: blend (0 = off, 1 = on)
void AnimSporeParticle(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    if (gBattleAnimArgs[4] == 1)
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->callback = AnimSporeParticle_Step;
    sprite->callback(sprite);
}

static void AnimSporeParticle_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], 32);
    sprite->y2 = Cos(sprite->data[1], -3) + ((sprite->data[2] += 24) >> 8);
    if ((u16)(sprite->data[1] - 0x40) < 0x80)
    {
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    }
    else
    {
        u8 priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;
        if (priority > 3)
            priority = 3;

        sprite->oam.priority = priority;
    }

    sprite->data[1] += 2;
    sprite->data[1] &= 0xFF;
    if (--sprite->data[0] == -1)
        DestroyAnimSprite(sprite);
}

// In a double battle, Updates the mon sprite background priorities to allow
// the circling effect controlled by AnimSporeParticle.
// No args.
void AnimTask_SporeDoubleBattle(u8 taskId)
{
    if (IsContest() || !IsDoubleBattle())
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimTarget) == 1)
            SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 3);
        else
            SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);

        DestroyAnimVisualTask(taskId);
    }
}

// Rotates a big flower around the attacking mon, and slowly floats
// downward.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target y pixel offset
// arg 3: duration
void AnimPetalDanceBigFlower(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0x40;
    sprite->callback = AnimPetalDanceBigFlower_Step;
    sprite->callback(sprite);
}

static void AnimPetalDanceBigFlower_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[5], 32);
        sprite->y2 += Cos(sprite->data[5], -5);
        if ((u16)(sprite->data[5] - 0x40) < 0x80)
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        else
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + 1;

        sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Slowly floats a small flower downard, while swaying from right to left.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target y pixel offset
// arg 3: duration
void AnimPetalDanceSmallFlower(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0x40;
    sprite->callback = AnimPetalDanceSmallFlower_Step;
    sprite->callback(sprite);
}

static void AnimPetalDanceSmallFlower_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[5], 8);
        if ((u16)(sprite->data[5] - 59) < 5 || (u16)(sprite->data[5] - 187) < 5)
            sprite->oam.matrixNum ^= ST_OAM_HFLIP;

        sprite->data[5] += 5;
        sprite->data[5] &= 0xFF;
    }
    else
    {
       DestroyAnimSprite(sprite);
    }
}

// Shoots a leaf upward, then floats it downward while swaying back and forth.
// arg 0: upward x delta per frame
// arg 1: upward y delta per frame
// arg 2: upward duration
static void AnimRazorLeafParticle(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->callback = AnimRazorLeafParticle_Step1;
}

static void AnimRazorLeafParticle_Step1(struct Sprite *sprite)
{
    if (!sprite->data[2])
    {
        if (sprite->data[1] & 1)
        {
            sprite->data[0] = 0x80;
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
        else
        {
            sprite->data[0] = 0;
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
        sprite->callback = AnimRazorLeafParticle_Step2;
    }
    else
    {
        sprite->data[2]--;
        sprite->x += sprite->data[0];
        sprite->y += sprite->data[1];
    }
}

static void AnimRazorLeafParticle_Step2(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker))
        sprite->x2 = -Sin(sprite->data[0], 25);
    else
        sprite->x2 = Sin(sprite->data[0], 25);

    sprite->data[0] += 2;
    sprite->data[0] &= 0xFF;
    sprite->data[1]++;
    if (!(sprite->data[1] & 1))
        sprite->y2++;

    if (sprite->data[1] > 80)
        DestroyAnimSprite(sprite);
}

// Animates a sprite that moves linearly from one location to another, with a
// single-cycle sine wave added to the y position along the way.
// Used by Razor Leaf and Magical Leaf.
// arg 0: initial x offset
// arg 1: initial y offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: translation duration
// arg 5: wave amplitude
// arg 6: target between double battle opponents (boolean)
void AnimTranslateLinearSingleSineWave(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    if (!gBattleAnimArgs[6])
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->data[2], &sprite->data[4]);
        sprite->data[2] += gBattleAnimArgs[2];
        sprite->data[4] += gBattleAnimArgs[3];
    }

    sprite->data[5] = gBattleAnimArgs[5];
    InitAnimArcTranslation(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
        sprite->data[0] = 1;
    else
        sprite->data[0] = 0;

    sprite->callback = AnimTranslateLinearSingleSineWave_Step;
}

static void AnimTranslateLinearSingleSineWave_Step(struct Sprite *sprite)
{
    bool8 destroy = FALSE;
    s16 a = sprite->data[0];
    s16 b = sprite->data[7];
    s16 r0;

    sprite->data[0] = 1;
    TranslateAnimHorizontalArc(sprite);
    r0 = sprite->data[7];
    sprite->data[0] = a;
    if (b > 200 && r0 < 56 && sprite->oam.affineParam == 0)
        sprite->oam.affineParam++;

    if (sprite->oam.affineParam && sprite->data[0])
    {
        sprite->invisible ^= 1;
        sprite->oam.affineParam++;
        if (sprite->oam.affineParam == 30)
            destroy = TRUE;
    }

    if (sprite->x + sprite->x2 > DISPLAY_WIDTH + 16
     || sprite->x + sprite->x2 < -16
     || sprite->y + sprite->y2 > DISPLAY_HEIGHT
     || sprite->y + sprite->y2 < -16)
        destroy = TRUE;

    if (destroy)
        DestroyAnimSprite(sprite);
}

// Animates particles in the Twister move animation.
// arg 0: duration
// arg 1: total y delta (the particles rise upward)
// arg 2: wave period (higher means faster wave)
// arg 3: wave amplitude
// arg 4: speedup frame (particles move faster at the end of the animation)
void AnimMoveTwisterParticle(struct Sprite *sprite)
{
    if (IsDoubleBattle() == TRUE)
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

    sprite->y += 32;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->data[3] = gBattleAnimArgs[3];
    sprite->data[4] = gBattleAnimArgs[4];
    sprite->callback = AnimMoveTwisterParticle_Step;
}

static void AnimMoveTwisterParticle_Step(struct Sprite *sprite)
{
    if (sprite->data[1] == 0xFF)
    {
        sprite->y -= 2;
    }
    else if (sprite->data[1] > 0)
    {
        sprite->y -= 2;
        sprite->data[1] -= 2;
    }

    sprite->data[5] += sprite->data[2];
    if (sprite->data[0] < sprite->data[4])
        sprite->data[5] += sprite->data[2];

    sprite->data[5] &= 0xFF;
    sprite->x2 = Cos(sprite->data[5], sprite->data[3]);
    sprite->y2 = Sin(sprite->data[5], 5);
    if (sprite->data[5] < 0x80)
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) - 1;
    else
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;

    if (--sprite->data[0] == 0)
        DestroyAnimSprite(sprite);
}

// Squeezes a constricting "rope" several times via affine animations.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: affine anim num
// arg 3: num squeezes
static void AnimConstrictBinding(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->affineAnimPaused = 1;
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[2]);
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[3];
    sprite->callback = AnimConstrictBinding_Step1;
}

static void AnimConstrictBinding_Step1(struct Sprite *sprite)
{
    u8 spriteId;

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->affineAnimPaused = 0;
        spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        sprite->data[0] = 0x100;
        sprite->callback = AnimConstrictBinding_Step2;
    }
}

static void AnimConstrictBinding_Step2(struct Sprite *sprite)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    if (!sprite->data[2])
        sprite->data[0] += 11;
    else
        sprite->data[0] -= 11;

    if (++sprite->data[1] == 6)
    {
        sprite->data[1] = 0;
        sprite->data[2] ^= 1;
    }

    if (sprite->affineAnimEnded)
    {
        if (--sprite->data[7] > 0)
            StartSpriteAffineAnim(sprite, sprite->data[6]);
        else
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_ShrinkTargetCopy(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    if (gSprites[spriteId].invisible)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
        gTasks[taskId].data[14] = gSprites[spriteId].oam.priority;
        gSprites[spriteId].oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        spriteId = GetAnimBattlerSpriteId(ANIM_DEF_PARTNER);
        gTasks[taskId].data[15] = gSprites[spriteId].oam.priority;
        gSprites[spriteId].oam.priority = GetBattlerSpriteBGPriority(BATTLE_PARTNER(gBattleAnimTarget));
        gTasks[taskId].data[0] = gBattleAnimArgs[0];
        gTasks[taskId].data[1] = gBattleAnimArgs[1];
        gTasks[taskId].data[11] = 0x100;
        gTasks[taskId].func = AnimTask_DuplicateAndShrinkToPos_Step1;
    }
}

static void AnimTask_DuplicateAndShrinkToPos_Step1(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    gTasks[taskId].data[10] += gTasks[taskId].data[0];
    gSprites[spriteId].x2 = gTasks[taskId].data[10] >> 8;
    if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
        gSprites[spriteId].x2 = -gSprites[spriteId].x2;

    gTasks[taskId].data[11] += 16;
    SetSpriteRotScale(spriteId, gTasks[taskId].data[11], gTasks[taskId].data[11], 0);
    SetBattlerSpriteYOffsetFromYScale(spriteId);
    if (--gTasks[taskId].data[1] == 0)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = AnimTask_DuplicateAndShrinkToPos_Step2;
    }
}

static void AnimTask_DuplicateAndShrinkToPos_Step2(u8 taskId)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            gSprites[spriteId].oam.priority = gTasks[taskId].data[14];
            spriteId = GetAnimBattlerSpriteId(ANIM_DEF_PARTNER);
            gSprites[spriteId].oam.priority = gTasks[taskId].data[15];
            gTasks[taskId].data[0]++;
            return;
        }
    }
    else
    {
        if (gTasks[taskId].data[0] == 0)
            return;
    }

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 3)
        DestroyAnimVisualTask(taskId);
}

// Moves an orb from the target mon to the attacking mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
void AnimMimicOrb(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
            gBattleAnimArgs[0] *= -1;

        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[0];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[1];
        sprite->invisible = TRUE;
        sprite->data[0]++;
        break;
    case 1:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
        {
            ChangeSpriteAffineAnim(sprite, 1);
            sprite->data[0] = 25;
            sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
            sprite->callback = InitAndRunAnimFastLinearTranslation;
            StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
            break;
        }
    }
}

// Animates a root that flickers away after some time.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: sprite subpriority offset
// arg 3: sprite anim num
// arg 4: duration
static void AnimIngrainRoot(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
        sprite->x2 = gBattleAnimArgs[0];
        sprite->y2 = gBattleAnimArgs[1];
        sprite->subpriority = gBattleAnimArgs[2] + 30;
        StartSpriteAnim(sprite, gBattleAnimArgs[3]);
        sprite->data[2] = gBattleAnimArgs[4];
        sprite->data[0]++;
        if (sprite->y + sprite->y2 > 120)
            sprite->y += sprite->y2 + sprite->y - 120;
    }
    sprite->callback = AnimRootFlickerOut;
}

// Places a root on the path to the target mon that flickers away after some time.
// arg 0: percent along the path to the target mon
// arg 1: x pixel offset
// arg 2: y pixel offset
// arg 3: sprite subpriority offset
// arg 4: sprite anum num
// arg 5: duration
static void AnimFrenzyPlantRoot(struct Sprite *sprite)
{
    s16 attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    s16 attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    s16 targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    s16 targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    targetX -= attackerX;
    targetY -= attackerY;
    sprite->x = attackerX + targetX * gBattleAnimArgs[0] / 100;
    sprite->y = attackerY + targetY * gBattleAnimArgs[0] / 100;
    sprite->x2 = gBattleAnimArgs[1];
    sprite->y2 = gBattleAnimArgs[2];
    sprite->subpriority = gBattleAnimArgs[3] + 30;
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);
    sprite->data[2] = gBattleAnimArgs[5];
    sprite->callback = AnimRootFlickerOut;
    sFrenzyPlantRootData.startX = sprite->x;
    sFrenzyPlantRootData.startY = sprite->y;
    sFrenzyPlantRootData.targetX = targetX;
    sFrenzyPlantRootData.targetY = targetY;
}

static void AnimRootFlickerOut(struct Sprite *sprite)
{
    if (++sprite->data[0] > (sprite->data[2] - 10))
        sprite->invisible = sprite->data[0] % 2;

    if (sprite->data[0] > sprite->data[2])
        DestroyAnimSprite(sprite);
}

// Moves an orb in a fast wavy path.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: horizontal velocity
// arg 3: wave amplitude
// arg 4: duration
static void AnimIngrainOrb(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[1];
        sprite->data[1] = gBattleAnimArgs[2];
        sprite->data[2] = gBattleAnimArgs[3];
        sprite->data[3] = gBattleAnimArgs[4];
    }

    sprite->data[0]++;
    sprite->x2 = sprite->data[1] * sprite->data[0];
    sprite->y2 = Sin((sprite->data[0] * 20) & 0xFF, sprite->data[2]);
    if (sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}

static void InitItemBagData(struct Sprite *sprite, s16 c)
{
    int a = (sprite->x << 8) | sprite->y;
    int b = (sprite->data[6] << 8) | sprite->data[7];
    c <<= 8;
    sprite->data[5] = a;
    sprite->data[6] = b;
    sprite->data[7] = c;
}

bool8 moveAlongLinearPath(struct Sprite *sprite)
{
    u16 xStartPos = (u8)(sprite->data[5] >> 8);
    u16 yStartPos = (u8)sprite->data[5];
    s32 xEndPos = (u8)(sprite->data[6] >> 8);
    s32 yEndPos = (u8)sprite->data[6];
    s16 totalTime = sprite->data[7] >> 8;
    s16 currentTime = sprite->data[7] & 0xFF;
    s16 yEndPos_2;
    s16 r0;
    s32 var1;
    s32 vaxEndPos;

    if (xEndPos == 0)
        xEndPos = -32;
    else if (xEndPos == 255)
        xEndPos = DISPLAY_WIDTH + 32;

    yEndPos_2 = yEndPos - yStartPos;
    r0 = xEndPos - xStartPos;
    var1 = r0 * currentTime / totalTime;
    vaxEndPos = yEndPos_2 * currentTime / totalTime;
    sprite->x = var1 + xStartPos;
    sprite->y = vaxEndPos + yStartPos;
    if (++currentTime == totalTime)
        return TRUE;

    sprite->data[7] = (totalTime << 8) | currentTime;
    return FALSE;
}

static void AnimItemSteal_Step2(struct Sprite *sprite)
{
    if (sprite->data[0] == 10)
        StartSpriteAffineAnim(sprite, 1);

    sprite->data[0]++;
    if (sprite->data[0] > 50)
        DestroyAnimSprite(sprite);
}

static void AnimItemSteal_Step1(struct Sprite *sprite)
{
    sprite->data[0] += sprite->data[3] * 128 / sprite->data[4];
    if (sprite->data[0] >= 128)
    {
        sprite->data[1]++;
        sprite->data[0] = 0;
    }

    sprite->y2 = Sin(sprite->data[0] + 128, 30 - sprite->data[1] * 8);
    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = 0;
        sprite->data[0] = 0;
        sprite->callback = AnimItemSteal_Step2;
    }
}

static void AnimPresent(struct Sprite *sprite)
{
    s16 targetX;
    s16 targetY;
    InitSpritePosToAnimAttacker(sprite, FALSE);
    targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget)
    {
        sprite->data[6] = targetX;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 1;
    }
    else
    {
        sprite->data[6] = targetX;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 3;
    }

    sprite->data[4] = 60;
    sprite->callback = AnimItemSteal_Step1;
}

static void AnimKnockOffOpponentsItem(struct Sprite *sprite)
{
    int zero;
    sprite->data[0] += ((sprite->data[3] * 128) / sprite->data[4]);
    zero = 0;
    if (sprite->data[0] > 0x7F)
    {
        sprite->data[1]++;
        sprite->data[0] = zero;
    }

    sprite->y2 = Sin(sprite->data[0] + 0x80, 30 - sprite->data[1] * 8);
    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = zero;
        sprite->data[0] = zero;
        DestroyAnimSprite(sprite);
    }
}

static void AnimKnockOffItem(struct Sprite *sprite)
{
    s16 targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->data[6] = 0;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 40);
        sprite->data[3] = 3;
        sprite->data[4] = 60;
        sprite->callback = AnimItemSteal_Step1;
    }
    else
    {
        sprite->data[6] = 255;
        sprite->data[7] = targetY + 10;
        if (IsContest())
            sprite->data[6] = 0;

        InitItemBagData(sprite, 40);
        sprite->data[3] = 3;
        sprite->data[4] = 60;
        sprite->callback = AnimKnockOffOpponentsItem;
    }
}

// Animates a heal particle upward.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: vertical velocity
// arg 3: unused
static void AnimPresentHealParticle(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        InitSpritePosToAnimTarget(sprite, FALSE);
        sprite->data[1] = gBattleAnimArgs[2];
    }

    sprite->data[0]++;
    sprite->y2 = sprite->data[1] * sprite->data[0];
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimItemSteal(struct Sprite *sprite)
{
    s16 attackerX;
    s16 attackerY;
    InitSpritePosToAnimTarget(sprite, FALSE);
    attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    if (BATTLE_PARTNER(gBattleAnimTarget) == gBattleAnimAttacker)
    {
        sprite->data[6] = attackerX;
        sprite->data[7] = attackerY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 1;
    }
    else
    {
        sprite->data[6] = attackerX;
        sprite->data[7] = attackerY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 3;
    }

    sprite->data[4] = 60;
    sprite->callback = AnimItemSteal_Step3;
}

static void AnimItemSteal_Step3(struct Sprite *sprite)
{
    int zero;
    sprite->data[0] += ((sprite->data[3] * 128) / sprite->data[4]);
    zero = 0;
    if (sprite->data[0] > 127)
    {
        sprite->data[1]++;
        sprite->data[0] = zero;
    }

    sprite->y2 = Sin(sprite->data[0] + 0x80, 30 - sprite->data[1] * 8);
    if (sprite->y2 == 0)
        PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_TARGET));

    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = 0;
        sprite->data[0] = 0;
        sprite->callback = AnimItemSteal_Step2;
        PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
    }
}

// Moves a bag in a circular motion.
// arg 0: y position
// arg 1: initial wave offset
static void AnimTrickBag(struct Sprite *sprite)
{
    int a;
    int b;

    if (!sprite->data[0])
    {
        if (!IsContest())
        {
            sprite->data[1] = gBattleAnimArgs[1];
            sprite->x = 120;
        }
        else
        {
            a = gBattleAnimArgs[1] - 32;
            if (a < 0)
                b = gBattleAnimArgs[1] + 0xDF;
            else
                b = a;

            sprite->data[1] = a - ((b >> 8) << 8);
            sprite->x = 70;
        }

        sprite->y = gBattleAnimArgs[0];
        sprite->data[2] = gBattleAnimArgs[0];
        sprite->data[4] = 20;
        sprite->x2 = Cos(sprite->data[1], 60);
        sprite->y2 = Sin(sprite->data[1], 20);
        sprite->callback = AnimTrickBag_Step1;
        if (sprite->data[1] > 0 && sprite->data[1] < 192)
            sprite->subpriority = 31;
        else
            sprite->subpriority = 29;
    }
}

static void AnimTrickBag_Step1(struct Sprite *sprite)
{
    switch (sprite->data[3])
    {
    case 0:
        if (sprite->data[2] > 78)
        {
            sprite->data[3] = 1;
            StartSpriteAffineAnim(sprite, 1);
            break;
        }
        else
        {
            sprite->data[2] += sprite->data[4] / 10;
            sprite->data[4] += 3;
            sprite->y = sprite->data[2];
            break;
        }
        break;
    case 1:
        if (sprite->data[3] && sprite->affineAnimEnded)
        {
            sprite->data[0] = 0;
            sprite->data[2] = 0;
            sprite->callback = AnimTrickBag_Step2;
        }
        break;
    }
}

static void AnimTrickBag_Step2(struct Sprite *sprite)
{
    if (sprite->data[2] == gTrickBagCoordinates[sprite->data[0]][1])
    {
        if (gTrickBagCoordinates[sprite->data[0]][2] == 127)
        {
            sprite->data[0] = 0;
            sprite->callback = AnimTrickBag_Step3;
        }

        sprite->data[2] = 0;
        sprite->data[0]++;
    }
    else
    {
        sprite->data[2]++;
        sprite->data[1] = (gTrickBagCoordinates[sprite->data[0]][0] * gTrickBagCoordinates[sprite->data[0]][2] + sprite->data[1]) & 0xFF;
        if (!IsContest())
        {
            if ((u16)(sprite->data[1] - 1) < 191)
                sprite->subpriority = 31;
            else
                sprite->subpriority = 29;
        }

        sprite->x2 = Cos(sprite->data[1], 60);
        sprite->y2 = Sin(sprite->data[1], 20);
    }
}

static void AnimTrickBag_Step3(struct Sprite *sprite)
{
    if (sprite->data[0] > 20)
        DestroyAnimSprite(sprite);

    sprite->invisible = sprite->data[0] % 2;
    sprite->data[0]++;
}

void AnimTask_LeafBlade(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[4] = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 1;
    task->data[6] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[7] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[10] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_WIDTH);
    task->data[11] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT);
    task->data[5] = (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT) ? 1 : -1;
    task->data[9] = 56 - (task->data[5] * 64);
    task->data[8] = task->data[7] - task->data[9] + task->data[6];
    task->data[2] = CreateSprite(&gLeafBladeSpriteTemplate, task->data[8], task->data[9], task->data[4]);
    if (task->data[2] == MAX_SPRITES)
        DestroyAnimVisualTask(taskId);

    gSprites[task->data[2]].data[0] = 10;
    gSprites[task->data[2]].data[1] = task->data[8];
    gSprites[task->data[2]].data[2] = task->data[6] - (task->data[10] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data[3] = task->data[9];
    gSprites[task->data[2]].data[4] = task->data[7] + (task->data[11] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data[5] = LeafBladeGetPosFactor(&gSprites[task->data[2]]);
    InitAnimArcTranslation(&gSprites[task->data[2]]);
    task->func = AnimTask_LeafBlade_Step;
}

static void AnimTask_LeafBlade_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *sprite = &gSprites[task->data[2]];
    int a = task->data[0];
    switch (a)
    {
    case 4:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 5;
            task->data[0] = 0xFF;
        }
        break;
    case 8:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 9;
            task->data[0] = 0xFF;
        }
        break;
    case 0:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 1;
            task->data[0] = 0xFF;
        }
        break;
    case 1:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] += 2;
        task->data[3] = a;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 2:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 3;
            task->data[0] = 0xFF;
        }
        break;
    case 3:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] - ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[3] = 2;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 5:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] + ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] -= 2;
        task->data[3] = 3;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 6:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 7;
            task->data[0] = 0xFF;
        }
        break;
    case 7:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] += 2;
        task->data[3] = 4;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 9:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[3] = 5;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 10:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 11;
            task->data[0] = 0xFF;
        }
        break;
    case 11:
    {
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[8];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[9];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] -= 2;
        task->data[3] = 6;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    }
    case 12:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            DestroySprite(sprite);
            task->data[0]++;
        }
        break;
    case 13:
        if (task->data[12] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    case 0xFF:
        if (++task->data[1] > 5)
        {
            task->data[1] = 0;
            task->data[0] = task->data[15];
        }
        break;
    }
}

static s16 LeafBladeGetPosFactor(struct Sprite *sprite)
{
    s16 var = 8;
    if (sprite->data[4] < sprite->y)
        var = -var;

    return var;
}

static void AnimTask_LeafBlade_Step2(struct Task *task, u8 taskId)
{
    task->data[14]++;
    if (task->data[14] > 0)
    {
        u8 spriteId;
        s16 spriteX;
        s16 spriteY;
        task->data[14] = 0;
        spriteX = gSprites[task->data[2]].x + gSprites[task->data[2]].x2;
        spriteY = gSprites[task->data[2]].y + gSprites[task->data[2]].y2;
        spriteId = CreateSprite(&gLeafBladeSpriteTemplate, spriteX, spriteY, task->data[4]);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[6] = taskId;
            gSprites[spriteId].data[7] = 12;
            gTasks[taskId].data[12]++;
            gSprites[spriteId].data[0] = task->data[13] & 1;
            gTasks[taskId].data[13]++;
            StartSpriteAnim(&gSprites[spriteId], task->data[3]);
            gSprites[spriteId].subpriority = task->data[4];
            gSprites[spriteId].callback = AnimTask_LeafBlade_Step2_Callback;
        }
    }
}

static void AnimTask_LeafBlade_Step2_Callback(struct Sprite *sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 1)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
        sprite->data[1]++;
        if (sprite->data[1] > 8)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            DestroySprite(sprite);
        }
    }
}

static void AnimFlyingParticle(struct Sprite *sprite)
{
    u8 battler;
    if (!gBattleAnimArgs[6])
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (GetBattlerSide(battler) != B_SIDE_PLAYER)
    {
        sprite->data[4] = 0;
        sprite->data[2] = gBattleAnimArgs[3];
        sprite->x = -16;
    }
    else
    {
        sprite->data[4] = 1;
        sprite->data[2] = -gBattleAnimArgs[3];
        sprite->x = DISPLAY_WIDTH + 16;
    }

    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[3] = gBattleAnimArgs[4];
    switch (gBattleAnimArgs[5])
    {
    case 0:
        sprite->y = gBattleAnimArgs[0];
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler);
        break;
    case 1:
        sprite->y = gBattleAnimArgs[0];
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;
        break;
    case 2:
        sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[0];
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler);
        break;
    case 3:
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[0];
        GetAnimBattlerSpriteId(ANIM_TARGET);
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;
        break;
    }

    sprite->callback = AnimFlyingParticle_Step;
}

static void AnimFlyingParticle_Step(struct Sprite *sprite)
{
    int a = sprite->data[7];
    sprite->data[7]++;
    sprite->y2 = (sprite->data[1] * gSineTable[sprite->data[0]]) >> 8;
    sprite->x2 = sprite->data[2] * a;
    sprite->data[0] = (sprite->data[3] * a) & 0xFF;
    if (!sprite->data[4])
    {
        if (sprite->x2 + sprite->x < DISPLAY_WIDTH + 8)
            return;
    }
    else
    {
        if (sprite->x2 + sprite->x > -16)
            return;
    }

    DestroySpriteAndMatrix(sprite);
}

void AnimTask_CycleMagicalLeafPal(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        task->data[8] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_LEAF));
        task->data[12] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_RAZOR_LEAF));
        task->data[0]++;
        break;
    case 1:
        if (++task->data[9] >= 0)
        {
            task->data[9] = 0;
            BlendPalette(task->data[8], 16, task->data[10], gMagicalLeafBlendColors[task->data[11]]);
            BlendPalette(task->data[12], 16, task->data[10], gMagicalLeafBlendColors[task->data[11]]);
            if (++task->data[10] == 17)
            {
                task->data[10] = 0;
                if (++task->data[11] == 7)
                    task->data[11] = 0;
            }
        }
        break;
    }

    if (gBattleAnimArgs[7] == -1)
        DestroyAnimVisualTask(taskId);
}

void AnimNeedleArmSpike(struct Sprite *sprite)
{
    s16 a;
    s16 b;
    u16 c;
    u16 x;
    u16 y;

    if (gBattleAnimArgs[4] == 0)
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        if (gBattleAnimArgs[0] == 0)
        {
            if (IsDoubleBattle())
            {
                SetAverageBattlerPositions(gBattleAnimAttacker, TRUE, &a, &b);
            }
            else
            {
                a = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
                b = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
            }
        }
        else
        {
            if (IsDoubleBattle())
            {
                SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &a, &b);
            }
            else
            {
                a = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
                b = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
            }
        }

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
        c = ArcTan2Neg(sprite->data[5] - x, sprite->data[6] - y);
        if (IsContest())
            c -= 0x8000;

        TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, c);
        sprite->callback = AnimNeedleArmSpike_Step;
    }
}

void AnimNeedleArmSpike_Step(struct Sprite *sprite)
{
    if (sprite->data[0])
    {
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->x = sprite->data[1] >> 4 ;
        sprite->y = sprite->data[2] >> 4 ;
        sprite->data[0]--;
    }
    else
    {
        DestroySpriteAndMatrix(sprite);
    }
}

static void AnimWhipHit_WaitEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSlidingHit(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }
    else
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimWhipHit(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        StartSpriteAnim(sprite, 1);

    sprite->callback = AnimWhipHit_WaitEnd;
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

static void AnimFlickeringPunch(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[6]);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

// Moves the sprite in a diagonally slashing motion across the target mon.
// Used by moves such as MOVE_CUT and MOVE_AERIAL_ACE.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: slice direction; 0 = right-to-left, 1 = left-to-right
void AnimCuttingSlice(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimSlice_Step;
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->x += gBattleAnimArgs[0];
    }
    else
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }

    sprite->y += gBattleAnimArgs[1];
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = gBattleAnimArgs[2];
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

static void AnimAirCutterSlice(struct Sprite *sprite)
{
    u8 x, y;
    switch (gBattleAnimArgs[3])
    {
    case 1:
        x = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y);
        break;
    case 2:
        x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
        {
            x = (GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X) + x) / 2;
            y = (GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y) + y) / 2;
        }
        break;
    case 0:
    default:
        x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
        break;
    }

    sprite->x = x;
    sprite->y = y;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimSlice_Step;
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->x += gBattleAnimArgs[0];
    }
    else
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }

    sprite->y += gBattleAnimArgs[1];
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = gBattleAnimArgs[2];
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

static void AnimSlice_Step(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    if (sprite->data[5] == 0)
        sprite->data[1] += 0x18;
    else
        sprite->data[1] -= 0x18;

    sprite->data[2] -= 0x18;
    sprite->x2 = sprite->data[3] >> 8;
    sprite->y2 = sprite->data[4] >> 8;
    sprite->data[0]++;
    if (sprite->data[0] == 20)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        sprite->data[0] = 3;
        sprite->callback = WaitAnimForDuration;
    }
}

static void UnusedFlickerAnim(struct Sprite *sprite)
{
    if (sprite->data[2] > 1)
    {
        if (sprite->data[3] & 1)
        {
            sprite->invisible = FALSE;
            gSprites[sprite->data[0]].invisible = FALSE;
            gSprites[sprite->data[1]].invisible = FALSE;
        }
        else
        {
            sprite->invisible = TRUE;
            gSprites[sprite->data[0]].invisible = TRUE;
            gSprites[sprite->data[1]].invisible = TRUE;
        }

        sprite->data[2] = 0;
        sprite->data[3]++;
    }
    else
    {
        sprite->data[2]++;
    }

    if (sprite->data[3] == 10)
    {
        DestroySprite(&gSprites[sprite->data[0]]);
        DestroySprite(&gSprites[sprite->data[1]]);
        DestroyAnimSprite(sprite);
    }
}

static void AnimCirclingMusicNote(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    StartSpriteAnim(sprite, gBattleAnimArgs[5]);
    sprite->data[1] = -gBattleAnimArgs[3];
    sprite->y += gBattleAnimArgs[1];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->callback = AnimCirclingMusicNote_Step;
    sprite->callback(sprite);
}

static void AnimCirclingMusicNote_Step(struct Sprite *sprite)
{
    sprite->x2 = Cos(sprite->data[0], 100);
    sprite->y2 = Sin(sprite->data[0], 20);
    if (sprite->data[0] < 128)
        sprite->subpriority = 0;
    else
        sprite->subpriority = 14;

    sprite->data[0] = (sprite->data[0] + sprite->data[1]) & 0xFF;
    sprite->data[5] += 130;
    sprite->y2 += sprite->data[5] >> 8;
    sprite->data[2]++;
    if (sprite->data[2] == sprite->data[3])
        DestroyAnimSprite(sprite);
}

static void AnimProtect(struct Sprite *sprite)
{
    if (IsContest())
        gBattleAnimArgs[1] += 8;

    sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[1];
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER || IsContest())
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker) + 1;
    else
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_PROTECT));
    sprite->data[7] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
    sprite->callback = AnimProtect_Step;
}

static void AnimProtect_Step(struct Sprite *sprite)
{
    int i, id, savedPal;
    sprite->data[5] += 96;
    sprite->x2 = -(sprite->data[5] >> 8);
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        savedPal = gPlttBufferFaded[sprite->data[2] + 1];
        i = 0;
        while (i < 6)
        {
            id = sprite->data[2] + ++i;
            gPlttBufferFaded[id] = gPlttBufferFaded[id + 1];
        }

        gPlttBufferFaded[sprite->data[2] + 7] = savedPal;
    }

    if (sprite->data[7] > 6 && sprite->data[0] >0 && ++sprite->data[6] > 1)
    {
        sprite->data[6] = 0;
        sprite->data[7] -= 1;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
    }

    if (sprite->data[0] > 0)
    {
        sprite->data[0] -= 1;
    }
    else if (++sprite->data[6] > 1)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
        if (sprite->data[7] == 16)
        {
            sprite->invisible = TRUE;
            sprite->callback = DestroyAnimSpriteAndDisableBlend;
        }
    }
}

static void AnimMilkBottle(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + 0xFFE8;
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
    sprite->callback = AnimMilkBottle_Step1;
}

static void AnimMilkBottle_Step1(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] > 0)
        {
            sprite->data[2] = 0;
            if (((++sprite->data[1]) & 1) != 0)
            {
                if (sprite->data[6] <= 15)
                    sprite->data[6]++;
            }
            else if (sprite->data[7] > 0)
                sprite->data[7]--;

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
            if (sprite->data[6] == 16 && sprite->data[7] == 0)
            {
                sprite->data[1] = 0;
                sprite->data[0]++;
            }
        }
        break;
    case 1:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 2:
        AnimMilkBottle_Step2(sprite, 16, 4);
        if (++sprite->data[1] > 2)
        {
            sprite->data[1] = 0;
            sprite->y++;
        }

        if (++sprite->data[2] <= 29)
            break;

        if (sprite->data[2] & 1)
        {
            if (sprite->data[6] > 0)
                sprite->data[6]--;
        }
        else if (sprite->data[7] <= 15)
        {
            sprite->data[7]++;
        }

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
        if (sprite->data[6] == 0 && sprite->data[7] == 16)
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->invisible = TRUE;
        sprite->data[0]++;
        break;
    case 4:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimMilkBottle_Step2(struct Sprite *sprite, int unk1, int unk2)
{
    if (sprite->data[3] <= 11)
        sprite->data[4] += 2;

    if ((u16)(sprite->data[3] - 0x12) <= 0x17)
        sprite->data[4] -= 2;

    if ((sprite->data[3]) > 0x2F)
        sprite->data[4] += 2;

    sprite->x2 = sprite->data[4] / 9;
    sprite->y2 = sprite->data[4] / 14;
    if (sprite->y2 < 0)
        sprite->y2 *= -1;

    sprite->data[3]++;
    if (sprite->data[3] > 0x3B)
        sprite->data[3] = 0;
}

void AnimGrantingStars(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[2])
        SetSpriteCoordsToAnimAttackerCoords(sprite);

    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[5];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearFixedPoint;
}

static void AnimSparklingStars(struct Sprite *sprite)
{
    u8 battler;
    if (!gBattleAnimArgs[2])
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (IsDoubleBattle() && IsBattlerSpriteVisible(BATTLE_PARTNER(battler)))
    {
        SetAverageBattlerPositions(battler, gBattleAnimArgs[6], &sprite->x, &sprite->y);
        SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
        sprite->y += gBattleAnimArgs[1];
    }
    else
    {
        if (!gBattleAnimArgs[6])
        {
            sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
            sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + gBattleAnimArgs[1];
        }
        else
        {
            sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];
        }

        SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    }

    sprite->data[0] = gBattleAnimArgs[5];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearFixedPoint;
}

static void AnimBubbleBurst(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }
    else
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        StartSpriteAnim(sprite, 1);
    }

    sprite->callback = AnimBubbleBurst_Step;
}

static void AnimBubbleBurst_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] > 30)
    {
        sprite->y2 = (30 - sprite->data[0]) / 3;
        sprite->x2 = Sin(sprite->data[1] * 4, 3);
        sprite->data[1]++;
    }

    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSleepLetterZ(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[3] = 1;
    }
    else
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[3] = 0xFFFF;
        StartSpriteAffineAnim(sprite, 1);
    }

    sprite->callback = AnimSleepLetterZ_Step;
}

static void AnimSleepLetterZ_Step(struct Sprite *sprite)
{
    sprite->y2 = -(sprite->data[0] / 0x28);
    sprite->x2 = sprite->data[4] / 10;
    sprite->data[4] += sprite->data[3] * 2;
    sprite->data[0] += sprite->data[1];
    if (++sprite->data[1] > 60)
        DestroySpriteAndMatrix(sprite);
}

static void AnimLockOnTarget(struct Sprite *sprite)
{
    sprite->x -= 32;
    sprite->y -= 32;
    sprite->data[0] = 20;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step1);
}

static void AnimLockOnTarget_Step1(struct Sprite *sprite)
{
    switch (sprite->data[5] & 1)
    {
    case 0:
        sprite->data[0] = 1;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step1);
        break;
    case 1:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->y2 = 0;
        sprite->x2 = 0;
        sprite->data[0] = 8;
        sprite->data[2] = sprite->x + gInclineMonCoordTable[sprite->data[5] >> 8][0];
        sprite->data[4] = sprite->y + gInclineMonCoordTable[sprite->data[5] >> 8][1];
        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step2);
        sprite->data[5] += 0x100;
        PlaySE12WithPanning(SE_M_LOCK_ON, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
        break;
    }

    sprite->data[5] ^= 1;
}

static void AnimLockOnTarget_Step2(struct Sprite *sprite)
{
    if ((sprite->data[5] >> 8) == 4)
    {
        sprite->data[0] = 10;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step3);
    }
    else
    {
        sprite->callback = AnimLockOnTarget_Step1;
    }
}

static void AnimLockOnTarget_Step3(struct Sprite *sprite)
{
    s16 a;
    s16 b;
    if (sprite->oam.affineParam == 0)
    {
        sprite->data[0] = 3;
        sprite->data[1] = 0;
        sprite->data[2] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step4);
    }
    else
    {
        switch (sprite->oam.affineParam)
        {
        case 1:
            a = -8;
            b = -8;
            break;
        case 2:
            a = -8;
            b = 8;
            break;
        case 3:
            a = 8;
            b = -8;
            break;
        default:
            a = 8;
            b = 8;
            break;
        }

        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->y2 = 0;
        sprite->x2 = 0;
        sprite->data[0] = 6;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + a;
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + b;
        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, AnimLockOnTarget_Step5);
    }
}

static void AnimLockOnTarget_Step4(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->data[1] += 3) > 16)
            sprite->data[1] = 16;
    }
    else if ((sprite->data[1] -= 3) < 0)
    {
        sprite->data[1] = 0;
    }

    BlendPalettes(GetBattlePalettesMask(TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE), sprite->data[1], RGB_WHITE);
    if (sprite->data[1] == 16)
    {
        int pal;
        sprite->data[2]++;
        pal = sprite->oam.paletteNum;
        LoadPalette(&gPlttBufferUnfaded[OBJ_PLTT_ID(pal) + 8], OBJ_PLTT_ID(pal) + 1, PLTT_SIZEOF(2));
        PlaySE12WithPanning(SE_M_LEER, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
    }
    else if (sprite->data[1] == 0)
    {
        sprite->callback = AnimLockOnTarget_Step5;
    }
}

static void AnimLockOnTarget_Step5(struct Sprite *sprite)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->data[1] = 0;
        sprite->data[0] = 0;
        sprite->callback = AnimLockOnTarget_Step6;
    }
}

static void AnimLockOnTarget_Step6(struct Sprite *sprite)
{
    if (sprite->data[0] % 3 == 0)
    {
        sprite->data[1]++;
        sprite->invisible ^= 1;
    }

    sprite->data[0]++;
    if (sprite->data[1] == 8)
        DestroyAnimSprite(sprite);
}

static void AnimLockOnMoveTarget(struct Sprite *sprite)
{
    sprite->oam.affineParam = gBattleAnimArgs[0];
    if ((s16)sprite->oam.affineParam == 1)
    {
        sprite->x -= 0x18;
        sprite->y -= 0x18;
    }
    else if ((s16)sprite->oam.affineParam == 2)
    {
        sprite->x -= 0x18;
        sprite->y += 0x18;
        sprite->oam.matrixNum = ST_OAM_VFLIP;
    }
    else if ((s16)sprite->oam.affineParam == 3)
    {
        sprite->x += 0x18;
        sprite->y -= 0x18;
        sprite->oam.matrixNum = ST_OAM_HFLIP;
    }
    else
    {
        sprite->x += 0x18;
        sprite->y += 0x18;
        sprite->oam.matrixNum = ST_OAM_HFLIP | ST_OAM_VFLIP;
    }

    sprite->oam.tileNum = (sprite->oam.tileNum + 16);
    sprite->callback = AnimLockOnTarget;
    sprite->callback(sprite);
}

static void AnimBowMon(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
    sprite->data[0] = 0;
    switch (gBattleAnimArgs[0])
    {
    case 0:
        sprite->callback = AnimBowMon_Step1;
        break;
    case 1:
        sprite->callback = AnimBowMon_Step2;
        break;
    case 2:
        sprite->callback = AnimBowMon_Step3;
        break;
    default:
        sprite->callback = AnimBowMon_Step4;
        break;
    }
}

static void AnimBowMon_Step1(struct Sprite *sprite)
{
    sprite->data[0] = 6;
    sprite->data[1] = (GetBattlerSide(gBattleAnimAttacker)) ? 2 : -2;
    sprite->data[2] = 0;
    sprite->data[3] = gBattlerSpriteIds[gBattleAnimAttacker];
    StoreSpriteCallbackInData6(sprite, AnimBowMon_Step1_Callback);
    sprite->callback = TranslateSpriteLinearById;
}

static void AnimBowMon_Step1_Callback(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[3] = gBattlerSpriteIds[gBattleAnimAttacker];
        PrepareBattlerSpriteForRotScale(sprite->data[3], ST_OAM_OBJ_NORMAL);
        sprite->data[4] = (sprite->data[6] = GetBattlerSide(gBattleAnimAttacker)) ? 0x300 : 0xFFFFFD00;
        sprite->data[5] = 0;
    }

    sprite->data[5] += sprite->data[4];
    SetSpriteRotScale(sprite->data[3], 0x100, 0x100, sprite->data[5]);
    SetBattlerSpriteYOffsetFromRotation(sprite->data[3]);
    if (++sprite->data[0] > 3)
    {
        sprite->data[0] = 0;
        sprite->callback = AnimBowMon_Step4;
    }
}

static void AnimBowMon_Step2(struct Sprite *sprite)
{
    sprite->data[0] = 4;
    sprite->data[1] = (GetBattlerSide(gBattleAnimAttacker)) ? -3 : 3;
    sprite->data[2] = 0;
    sprite->data[3] = gBattlerSpriteIds[gBattleAnimAttacker];
    StoreSpriteCallbackInData6(sprite, AnimBowMon_Step4);
    sprite->callback = TranslateSpriteLinearById;
}

static void AnimBowMon_Step3(struct Sprite *sprite)
{
    if (++sprite->data[0] > 8)
    {
        sprite->data[0] = 0;
        sprite->callback = AnimBowMon_Step3_Callback;
    }
}

static void AnimBowMon_Step3_Callback(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[3] = gBattlerSpriteIds[gBattleAnimAttacker];
        sprite->data[6] = GetBattlerSide(gBattleAnimAttacker);
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            sprite->data[4] = 0xFC00;
            sprite->data[5] = 0xC00;
        }
        else
        {
            sprite->data[4] = 0x400;
            sprite->data[5] = 0xF400;
        }
    }

    sprite->data[5] += sprite->data[4];
    SetSpriteRotScale(sprite->data[3], 0x100, 0x100, sprite->data[5]);
    SetBattlerSpriteYOffsetFromRotation(sprite->data[3]);
    if (++sprite->data[0] > 2)
    {
        ResetSpriteRotScale(sprite->data[3]);
        sprite->callback = AnimBowMon_Step4;
    }
}

static void AnimBowMon_Step4(struct Sprite *sprite)
{
    DestroyAnimSprite(sprite);
}

static void AnimTipMon(struct Sprite *sprite)
{
    sprite->data[0] = 0;
    sprite->callback = AnimTipMon_Step;
}

static void AnimTipMon_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = 0;
        sprite->data[2] = gBattlerSpriteIds[gBattleAnimAttacker];
        sprite->data[3] = GetBattlerSide(gBattleAnimAttacker);
        sprite->data[4] = (sprite->data[3] != B_SIDE_PLAYER) ? 0x200 : -0x200;
        sprite->data[5] = 0;
        PrepareBattlerSpriteForRotScale(sprite->data[2], ST_OAM_OBJ_NORMAL);
        sprite->data[0]++;
        // fall through
    case 1:
        sprite->data[5] += sprite->data[4];
        SetSpriteRotScale(sprite->data[2], 0x100, 0x100, sprite->data[5]);
        SetBattlerSpriteYOffsetFromRotation(sprite->data[2]);
        if (++sprite->data[1] > 3)
        {
            sprite->data[1] = 0;
            sprite->data[4] *= -1;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[5] += sprite->data[4];
        SetSpriteRotScale(sprite->data[2], 0x100, 0x100, sprite->data[5]);
        SetBattlerSpriteYOffsetFromRotation(sprite->data[2]);
        if (++sprite->data[1] > 3)
        {
            ResetSpriteRotScale(sprite->data[2]);
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

void AnimTask_SkullBashPosition(u8 taskId)
{
    u8 side;

    gTasks[taskId].data[0] = gBattlerSpriteIds[gBattleAnimAttacker];
    side = GetBattlerSide(gBattleAnimAttacker);
    gTasks[taskId].data[1] = side;
    gTasks[taskId].data[2] = 0;
    switch (gBattleAnimArgs[0])
    {
    default:
        DestroyAnimVisualTask(taskId);
        break;
    case 0:
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 8;
        gTasks[taskId].data[4] = 0;
        gTasks[taskId].data[5] = 3;
        if (side == B_SIDE_PLAYER)
            gTasks[taskId].data[5] *= -1;

        gTasks[taskId].func = AnimTask_SkullBashPositionSet;
        break;
    case 1:
        gTasks[taskId].data[3] = 8;
        gTasks[taskId].data[4] = 0x600;
        gTasks[taskId].data[5] = 0xC0;
        if (side == B_SIDE_PLAYER)
        {
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }

        gTasks[taskId].func = AnimTask_SkullBashPositionReset;
        break;
    }
}

static void AnimTask_SkullBashPositionSet(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[2])
    {
    case 0:
        if (task->data[3])
        {
            task->data[4] += task->data[5];
            gSprites[task->data[0]].x2 = task->data[4];
            task->data[3]--;
        }
        else
        {
            task->data[3] = 8;
            task->data[4] = 0;
            task->data[5] = (task->data[1] == 0) ? -0xC0 : 0xC0;
            PrepareBattlerSpriteForRotScale(task->data[0], ST_OAM_OBJ_NORMAL);
            task->data[2]++;
        }
        break;
    case 1:
        if (task->data[3])
        {
            task->data[4] += task->data[5];
            SetSpriteRotScale(task->data[0], 0x100, 0x100, task->data[4]);
            SetBattlerSpriteYOffsetFromRotation(task->data[0]);
            task->data[3]--;
        }
        else
        {
            task->data[3] = 8;
            task->data[4] = gSprites[task->data[0]].x2;
            task->data[5] = (task->data[1] == 0) ? 0x2 : -0x2;
            task->data[6] = 1;
            task->data[2]++;
        }
        break;
    case 2:
        if (task->data[3])
        {
            if (task->data[6])
            {
                task->data[6]--;
            }
            else
            {
                if (task->data[3] & 1)
                    gSprites[task->data[0]].x2 = task->data[4] + task->data[5];
                else
                    gSprites[task->data[0]].x2 = task->data[4] - task->data[5];

                task->data[6] = 1;
                task->data[3]--;
            }
        }
        else
        {
            gSprites[task->data[0]].x2 = task->data[4];
            task->data[3] = 12;
            task->data[2]++;
        }
        break;
    case 3:
        if (task->data[3])
        {
            task->data[3]--;
        }
        else
        {
            task->data[3] = 3;
            task->data[4] = gSprites[task->data[0]].x2;
            task->data[5] = (task->data[1] == 0) ? 8 : -8;
            task->data[2]++;
        }
        break;
    case 4:
        if (task->data[3])
        {
            task->data[4] += task->data[5];
            gSprites[task->data[0]].x2 = task->data[4];
            task->data[3]--;
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
        break;
    }
}

static void AnimTask_SkullBashPositionReset(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[3])
    {
        task->data[4] -= task->data[5];
        SetSpriteRotScale(task->data[0], 0x100, 0x100, task->data[4]);
        SetBattlerSpriteYOffsetFromRotation(task->data[0]);
        task->data[3]--;
    }
    else
    {
        ResetSpriteRotScale(task->data[0]);
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimSlashSlice(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    }

    sprite->data[0] = 0;
    sprite->data[1] = 0;
    StoreSpriteCallbackInData6(sprite, AnimFalseSwipeSlice_Step3);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

static void AnimFalseSwipeSlice(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + 0xFFD0;
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    StoreSpriteCallbackInData6(sprite, AnimFalseSwipeSlice_Step1);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

static void AnimFalseSwipePositionedSlice(struct Sprite *sprite)
{
    sprite->x = sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + 0xFFD0 + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    StartSpriteAnim(sprite, 1);
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = AnimFalseSwipeSlice_Step3;
}

static void AnimFalseSwipeSlice_Step1(struct Sprite *sprite)
{
    if (++sprite->data[0] > 8)
    {
        sprite->data[0] = 12;
        sprite->data[1] = 8;
        sprite->data[2] = 0;
        StoreSpriteCallbackInData6(sprite, AnimFalseSwipeSlice_Step2);
        sprite->callback = TranslateSpriteLinear;
    }
}

static void AnimFalseSwipeSlice_Step2(struct Sprite *sprite)
{
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = AnimFalseSwipeSlice_Step3;
}

void AnimFalseSwipeSlice_Step3(struct Sprite *sprite)
{
    if (++sprite->data[0] > 1)
    {
        sprite->data[0] = 0;
        sprite->invisible = !sprite->invisible;
        if (++sprite->data[1] > 8)
            DestroyAnimSprite(sprite);
    }
}

void AnimEndureEnergy(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
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
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = AnimEndureEnergy_Step;
}

static void AnimEndureEnergy_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] > sprite->data[1])
    {
        sprite->data[0] = 0;
        sprite->y--;
    }

    sprite->y -= sprite->data[0];
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSharpenSphere(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) - 12;
    sprite->data[0] = 0;
    sprite->data[1] = 2;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);
    sprite->callback = AnimSharpenSphere_Step;
}

static void AnimSharpenSphere_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] >= sprite->data[1])
    {
        sprite->invisible = !sprite->invisible;
        if (!sprite->invisible)
        {
            sprite->data[4]++;
            if (!(sprite->data[4] & 1))
                PlaySE12WithPanning(SE_M_SWAGGER2, sprite->data[5]);
        }

        sprite->data[0] = 0;
        if (++sprite->data[2] > 1)
        {
            sprite->data[2] = 0;
            sprite->data[1]++;
        }
    }

    if (sprite->animEnded && sprite->data[1] > 16 && sprite->invisible)
        DestroyAnimSprite(sprite);
}

void AnimConversion(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[0];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[1];
        if (IsContest())
            sprite->y += 10;

        sprite->data[0]++;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyAnimSprite(sprite);
}

void AnimTask_ConversionAlphaBlend(u8 taskId)
{
    if (gTasks[taskId].data[2] == 1)
    {
        gBattleAnimArgs[7] = 0xFFFF;
        gTasks[taskId].data[2]++;
    }
    else if (gTasks[taskId].data[2] == 2)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (++gTasks[taskId].data[0] == 4)
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - gTasks[taskId].data[1], gTasks[taskId].data[1]));
            if (gTasks[taskId].data[1] == 16)
                gTasks[taskId].data[2]++;
        }
    }
}

static void AnimConversion2(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->animPaused = 1;
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->callback = AnimConversion2_Step;
}

static void AnimConversion2_Step(struct Sprite *sprite)
{
    if (sprite->data[0])
    {
        sprite->data[0]--;
    }
    else
    {
        sprite->animPaused = 0;
        sprite->data[0] = 30;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->callback = StartAnimLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

void AnimTask_Conversion2AlphaBlend(u8 taskId)
{
    if (++gTasks[taskId].data[0] == 4)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 16)
            DestroyAnimVisualTask(taskId);
    }
}

// Unused
static void AnimTask_HideBattlersHealthbox(u8 taskId)
{
    u8 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattleAnimArgs[0] == TRUE && GetBattlerSide(i) == B_SIDE_PLAYER)
            SetHealthboxSpriteInvisible(gHealthboxSpriteIds[i]);

        if (gBattleAnimArgs[1] == TRUE && GetBattlerSide(i) == B_SIDE_OPPONENT)
            SetHealthboxSpriteInvisible(gHealthboxSpriteIds[i]);
    }

    DestroyAnimVisualTask(taskId);
}

// Unused
static void AnimTask_ShowBattlersHealthbox(u8 taskId)
{
    u8 i;
    for (i = 0; i < gBattlersCount; i++)
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[i]);

    DestroyAnimVisualTask(taskId);
}

static void AnimMoon(struct Sprite *sprite)
{
    if (IsContest())
    {
        sprite->x = 48;
        sprite->y = 40;
    }
    else
    {
        sprite->x = gBattleAnimArgs[0];
        sprite->y = gBattleAnimArgs[1];
    }

    sprite->oam.shape = SPRITE_SHAPE(64x64);
    sprite->oam.size = SPRITE_SIZE(64x64);
    sprite->data[0] = 0;
    sprite->callback = AnimMoon_Step;
}

static void AnimMoon_Step(struct Sprite *sprite)
{
    if (sprite->data[0])
        DestroyAnimSprite(sprite);
}

static void AnimMoonlightSparkle(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->y = gBattleAnimArgs[1];
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 1;
    sprite->callback = AnimMoonlightSparkle_Step;
}

static void AnimMoonlightSparkle_Step(struct Sprite *sprite)
{
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        if (sprite->data[2] < 120)
        {
            sprite->y++;
            sprite->data[2]++;
        }
    }

    if (sprite->data[0])
        DestroyAnimSprite(sprite);
}

void AnimTask_MoonlightEndFade(u8 taskId)
{
    int a = GetBattlePalettesMask(TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE) & 0xFFFF;
    int b;
    int c;
    int d;

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = a;
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
    gTasks[taskId].data[7] = 13;
    gTasks[taskId].data[8] = 14;
    gTasks[taskId].data[9] = 15;
    b = GetBattleMonSpritePalettesMask(1, 1, 1, 1);
    c = a | b;
    StorePointerInVars(&gTasks[taskId].data[14], &gTasks[taskId].data[15], (void *)c);
    b = b | (0x10000 << IndexOfSpritePaletteTag(ANIM_TAG_MOON));
    d = IndexOfSpritePaletteTag(ANIM_TAG_GREEN_SPARKLE);
    BeginNormalPaletteFade((0x10000 << d) | b, 0, 0, 16, RGB(27, 29, 31));
    gTasks[taskId].func = AnimTask_MoonlightEndFade_Step;
    gTasks[taskId].func(taskId);
}

static void AnimTask_MoonlightEndFade_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 0)
        {
            u16 color;
            u16 bitmask;
            u16 r3;
            u16 i;
            u16 j;
            task->data[1] = 0;
            if (++task->data[2] <= 15)
            {
                u16 red;
                u16 green;
                u16 blue;
                task->data[4] += task->data[7];
                task->data[5] += task->data[8];
                task->data[6] += task->data[9];
                red = task->data[4] >> 3;
                green = task->data[5] >> 3;
                blue = task->data[6] >> 3;
                color = RGB(red, green, blue);
            }
            else
            {
                color = RGB(27, 29, 31);
                task->data[0]++;
            }

            bitmask = 1;
            r3 = 0;
            for (i = 0; i <= 15; i++)
            {
                if (task->data[3] & bitmask)
                {
                    for (j = 1; j <= 15; j++)
                    {
                        gPlttBufferFaded[r3 + j] = color;
                    }
                }

                bitmask <<= 1;
                r3 += 16;
            }
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            u8 spriteId;
            for (spriteId = 0; spriteId < MAX_SPRITES; spriteId++)
            {
                if (gSprites[spriteId].template == &gMoonSpriteTemplate || gSprites[spriteId].template == &gMoonlightSparkleSpriteTemplate)
                    gSprites[spriteId].data[0] = 1;
            }

            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[1] > 30)
        {
            BeginNormalPaletteFade((u32)LoadPointerFromVars(task->data[14], task->data[15]), 0, 16, 0, RGB(27, 29, 31));
            task->data[0]++;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimHornHit(struct Sprite *sprite)
{
    if (gBattleAnimArgs[2] < 2)
        gBattleAnimArgs[2] = 2;

    if (gBattleAnimArgs[2] > 0x7F)
        gBattleAnimArgs[2] = 0x7F;

    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[1];
    sprite->data[6] = sprite->x;
    sprite->data[7] = sprite->y;
    if (IsContest())
    {
        sprite->oam.matrixNum = ST_OAM_HFLIP;
        sprite->x += 40;
        sprite->y += 20;
        sprite->data[2] = sprite->x << 7;
        sprite->data[3] = -0x1400 / sprite->data[1];
        sprite->data[4] = sprite->y << 7;
        sprite->data[5] = -0xA00 / sprite->data[1];
    }
    else if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x -= 40;
        sprite->y += 20;
        sprite->data[2] = sprite->x << 7;
        sprite->data[3] = 0x1400 / sprite->data[1];
        sprite->data[4] = sprite->y << 7;
        sprite->data[5] = -0xA00 / sprite->data[1];
    }
    else
    {
        sprite->x += 40;
        sprite->y -= 20;
        sprite->data[2] = sprite->x << 7;
        sprite->data[3] = -0x1400 / sprite->data[1];
        sprite->data[4] = sprite->y << 7;
        sprite->data[5] = 0xA00 / sprite->data[1];
        sprite->oam.matrixNum = (ST_OAM_HFLIP | ST_OAM_VFLIP);
    }

    sprite->callback = AnimHornHit_Step;
}

static void AnimHornHit_Step(struct Sprite *sprite)
{
    sprite->data[2] += sprite->data[3];
    sprite->data[4] += sprite->data[5];
    sprite->x = sprite->data[2] >> 7;
    sprite->y = sprite->data[4] >> 7;
    if (--sprite->data[1] == 1)
    {
        sprite->x = sprite->data[6];
        sprite->y = sprite->data[7];
    }

    if (sprite->data[1] == 0)
        DestroyAnimSprite(sprite);
}

void AnimTask_DoubleTeam(u8 taskId)
{
    u16 i;
    int obj;
    u16 r3;
    u16 r4;
    struct Task *task = &gTasks[taskId];
    task->data[0] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[1] = AllocSpritePalette(ANIM_TAG_BENT_SPOON);
    r3 = OBJ_PLTT_ID(task->data[1]);
    r4 = OBJ_PLTT_ID2(gSprites[task->data[0]].oam.paletteNum);
    for (i = 1; i < 16; i++)
        gPlttBufferUnfaded[r3 + i] = gPlttBufferUnfaded[r4 + i];

    BlendPalette(r3, 16, 11, RGB_BLACK);
    task->data[3] = 0;
    i = 0;
    while (i < 2 && (obj = CloneBattlerSpriteWithBlend(0)) >= 0)
    {
        gSprites[obj].oam.paletteNum = task->data[1];
        gSprites[obj].data[0] = 0;
        gSprites[obj].data[1] = i << 7;
        gSprites[obj].data[2] = taskId;
        gSprites[obj].callback = AnimDoubleTeam;
        task->data[3]++;
        i++;
    }

    task->func = AnimTask_DoubleTeam_Step;
    if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON);
    else
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
}

static void AnimTask_DoubleTeam_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->data[3])
    {
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG1_ON);
        else
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);

        FreeSpritePaletteByTag(ANIM_TAG_BENT_SPOON);
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimDoubleTeam(struct Sprite *sprite)
{
    if (++sprite->data[3] > 1)
    {
        sprite->data[3] = 0;
        sprite->data[0]++;
    }

    if (sprite->data[0] > 64)
    {
        gTasks[sprite->data[2]].data[3]--;
        DestroySpriteWithActiveSheet(sprite);
    }
    else
    {
        sprite->data[4] = gSineTable[sprite->data[0]] / 6;
        sprite->data[5] = gSineTable[sprite->data[0]] / 13;
        sprite->data[1] = (sprite->data[1] + sprite->data[5]) & 0xFF;
        sprite->x2 = Sin(sprite->data[1], sprite->data[4]);
    }
}

static void AnimSuperFang(struct Sprite *sprite)
{
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

void AnimTask_MusicNotesRainbowBlend(u8 taskId)
{
    u16 i;
    u16 j;
    u16 index;

    index = IndexOfSpritePaletteTag(gParticlesColorBlendTable[0][0]);
    if (index != 0xFF)
    {
        index = OBJ_PLTT_ID(index);
        for (i = 1; i < ARRAY_COUNT(gParticlesColorBlendTable[0]); i++)
            gPlttBufferFaded[index + i] = gParticlesColorBlendTable[0][i];
    }

    for (j = 1; j < ARRAY_COUNT(gParticlesColorBlendTable); j++)
    {
        index = AllocSpritePalette(gParticlesColorBlendTable[j][0]);
        if (index != 0xFF)
        {
            index = OBJ_PLTT_ID(index);
            for (i = 1; i < ARRAY_COUNT(gParticlesColorBlendTable[0]); i++)
                gPlttBufferFaded[index + i] = gParticlesColorBlendTable[j][i];
        }
    }
    DestroyAnimVisualTask(taskId);
}

// clears the rainbow effect for musical notes.
void AnimTask_MusicNotesClearRainbowBlend(u8 taskId)
{
    u16 i;
    for (i = 1; i < ARRAY_COUNT(gParticlesColorBlendTable); i++)
        FreeSpritePaletteByTag(gParticlesColorBlendTable[i][0]);

    DestroyAnimVisualTask(taskId);
}

#define sMoveTimer      data[0]
#define sBlendTableIdx  data[1]
#define sBlendTimer     data[2]
#define sBlendCycleTime data[3]
#define sX              data[4]
#define sY              data[5]
#define sVelocX         data[6]
#define sVelocY         data[7]

static void AnimWavyMusicNotes(struct Sprite *sprite)
{
    u8 index;
    u8 x, y;
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    StartSpriteAnim(sprite, gBattleAnimArgs[0]);
    if ((index = IndexOfSpritePaletteTag(gParticlesColorBlendTable[gBattleAnimArgs[1]][0])) != 0xFF)
        sprite->oam.paletteNum = index;

    sprite->sBlendTableIdx = gBattleAnimArgs[1];
    sprite->sBlendTimer = 0;
    sprite->sBlendCycleTime = gBattleAnimArgs[2];
    if (IsContest())
    {
        x = 48;
        y = 40;
    }
    else
    {
        x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }

    sprite->sX = sprite->x << 4;
    sprite->sY = sprite->y << 4;
    AnimWavyMusicNotes_CalcVelocity(x - sprite->x, y - sprite->y, &sprite->sVelocX, &sprite->sVelocY, 40);
    sprite->callback = AnimWavyMusicNotes_Step;
}

static void AnimWavyMusicNotes_CalcVelocity(s16 x, s16 y, s16 *velocX, s16 *velocY, s8 xSpeedFactor)
{
    int x2;
    int time;
    if (x < 0)
        xSpeedFactor = -xSpeedFactor;

    x2 = x * 256;
    time = x2 / xSpeedFactor;
    if (time == 0)
        time = 1;

    *velocX = x2 / time;
    *velocY = (y * 256) / time;
}

static void AnimWavyMusicNotes_Step(struct Sprite *sprite)
{
    s16 y, trigIdx;
    u8 index;

    sprite->sMoveTimer++;
    trigIdx = sprite->sMoveTimer * 5 - ((sprite->sMoveTimer * 5 / 256) << 8);
    sprite->sX += sprite->sVelocX;
    sprite->sY += sprite->sVelocY;
    sprite->x = sprite->sX >> 4;
    sprite->y = sprite->sY >> 4;
    sprite->y2 = Sin(trigIdx, 15);

    y = sprite->y;
    if (sprite->x < -16 || sprite->x > DISPLAY_WIDTH + 16 || y < -16 || y > DISPLAY_HEIGHT - 32)
    {
        DestroySpriteAndMatrix(sprite);
    }
    else
    {
        if (sprite->sBlendCycleTime && ++sprite->sBlendTimer > sprite->sBlendCycleTime)
        {
            sprite->sBlendTimer = 0;
            if (++sprite->sBlendTableIdx > (int)ARRAY_COUNT(gParticlesColorBlendTable) - 1)
                sprite->sBlendTableIdx = 0;

            index = IndexOfSpritePaletteTag(gParticlesColorBlendTable[sprite->sBlendTableIdx][0]);
            if (index != 0xFF)
                sprite->oam.paletteNum = index;
        }
    }
}

static void AnimFlyingMusicNotes(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        gBattleAnimArgs[1] *= -1;

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    StartSpriteAnim(sprite, gBattleAnimArgs[0]);
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = sprite->x << 4;
    sprite->data[5] = sprite->y << 4;
    sprite->data[6] = (gBattleAnimArgs[1] << 4) / 5;
    sprite->data[7] = (gBattleAnimArgs[2] << 7) / 5;
    sprite->callback = AnimFlyingMusicNotes_Step;
}

static void AnimFlyingMusicNotes_Step(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[6];
    sprite->data[5] += sprite->data[7];
    sprite->x = sprite->data[4] >> 4;
    sprite->y = sprite->data[5] >> 4;
    if (sprite->data[0] > 5 && sprite->data[3] == 0)
    {
        sprite->data[2] = (sprite->data[2] + 16) & 0xFF;
        sprite->x2 = Cos(sprite->data[2], 18);
        sprite->y2 = Sin(sprite->data[2], 18);
        if (sprite->data[2] == 0)
            sprite->data[3] = 1;
    }

    if (++sprite->data[0] == 48)
        DestroySpriteAndMatrix(sprite);
}

static void AnimBellyDrumHand(struct Sprite *sprite)
{
    s16 a;
    if (gBattleAnimArgs[0] == 1)
    {
        sprite->oam.matrixNum = ST_OAM_HFLIP;
        a = 16;
    }
    else
    {
        a = -16;
    }

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + a;
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + 8;
    sprite->data[0] = 8;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimSlowFlyingMusicNotes(struct Sprite *sprite)
{
    s16 xDiff;
    u8 index;
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    sprite->y += 8;
    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    index = IndexOfSpritePaletteTag(gParticlesColorBlendTable[gBattleAnimArgs[2]][0]);
    if (index != 0xFF)
        sprite->oam.paletteNum = index;

    xDiff = (gBattleAnimArgs[0] == 0) ? -32 : 32;
    sprite->data[0] = 40;
    sprite->data[1] = sprite->x;
    sprite->data[2] = xDiff + sprite->data[1];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->data[3] - 40;
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = gBattleAnimArgs[3];
    sprite->callback = AnimSlowFlyingMusicNotes_Step;
}

static void AnimSlowFlyingMusicNotes_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite) == 0)
    {
        s16 xDiff;
        xDiff = Sin(sprite->data[5], 8);
        if (sprite->x2 < 0)
            xDiff = -xDiff;

        sprite->x2 += xDiff;
        sprite->y2 += Sin(sprite->data[5], 4);
        sprite->data[5] = (sprite->data[5] + 8) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

void SetSpriteNextToMonHead(u8 battler, struct Sprite *sprite)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_RIGHT) + 8;
    else
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_LEFT) - 8;

    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) - (s16)GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_HEIGHT) / 4;
}

void AnimThoughtBubble(struct Sprite *sprite)
{
    u8 animNum;
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    SetSpriteNextToMonHead(battler, sprite);
    animNum = (GetBattlerSide(battler) == B_SIDE_PLAYER) ? 0 : 1;
    sprite->data[0] = gBattleAnimArgs[1];
    sprite->data[1] = animNum + 2;
    StartSpriteAnim(sprite, animNum);
    StoreSpriteCallbackInData6(sprite, AnimThoughtBubble_Step);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

static void AnimThoughtBubble_Step(struct Sprite *sprite)
{
    if (--sprite->data[0] == 0)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        StartSpriteAnim(sprite, sprite->data[1]);
        sprite->callback = RunStoredCallbackWhenAnimEnds;
    }
}

void AnimMetronomeFinger(struct Sprite *sprite)
{
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    SetSpriteNextToMonHead(battler, sprite);
    sprite->data[0] = 0;
    StoreSpriteCallbackInData6(sprite, AnimMetronomeFinger_Step);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

static void AnimMetronomeFinger_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] > 16)
    {
        StartSpriteAffineAnim(sprite, 1);
        StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
        sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    }
}

void AnimFollowMeFinger(struct Sprite *sprite)
{
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_TOP);
    if (sprite->y <= 9)
        sprite->y = 10;

    sprite->data[0] = 1;
    sprite->data[1] = 0;
    sprite->data[2] = sprite->subpriority;
    sprite->data[3] = sprite->subpriority + 4;
    sprite->data[4] = 0;
    StoreSpriteCallbackInData6(sprite, AnimFollowMeFinger_Step1);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

static void AnimFollowMeFinger_Step1(struct Sprite *sprite)
{
    if (++sprite->data[4] > 12)
        sprite->callback = AnimFollowMeFinger_Step2;
}

static void AnimFollowMeFinger_Step2(struct Sprite *sprite)
{
    s16 x1, x2;

    sprite->data[1] += 4;
    if (sprite->data[1] > 254)
    {
        if (--sprite->data[0] == 0)
        {
            sprite->x2 = 0;
            sprite->callback = AnimMetronomeFinger_Step;
            return;
        }
        else
        {
            sprite->data[1] &= 0xFF;
        }
    }

    if (sprite->data[1] > 0x4F)
        sprite->subpriority = sprite->data[3];

    if (sprite->data[1] > 0x9F)
        sprite->subpriority = sprite->data[2];

    x1 = gSineTable[sprite->data[1]];
    x2 = x1 >> 3;
    sprite->x2 = (x1 >> 3) + (x2 >> 1);
}

static void AnimTauntFinger(struct Sprite *sprite)
{
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    SetSpriteNextToMonHead(battler, sprite);
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
    {
        StartSpriteAnim(sprite, 0);
        sprite->data[0] = 2;
    }
    else
    {
        StartSpriteAnim(sprite, 1);
        sprite->data[0] = 3;
    }

    sprite->callback = AnimTauntFinger_Step1;
}

static void AnimTauntFinger_Step1(struct Sprite *sprite)
{
    if (++sprite->data[1] > 10)
    {
        sprite->data[1] = 0;
        StartSpriteAnim(sprite, sprite->data[0]);
        StoreSpriteCallbackInData6(sprite, AnimTauntFinger_Step2);
        sprite->callback = RunStoredCallbackWhenAnimEnds;
    }
}

static void AnimTauntFinger_Step2(struct Sprite *sprite)
{
    if (++sprite->data[1] > 5)
        DestroyAnimSprite(sprite);
}

// Animates a white streak by giving it a random rotation.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
static void AnimRockPolishStreak(struct Sprite *sprite)
{
    int affineAnimNum = Random2() % ARRAY_COUNT(gRockPolishStreak_AffineAnimCmds);
    InitSpritePosToAnimAttacker(sprite, TRUE);
    StartSpriteAffineAnim(sprite, affineAnimNum);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

// Places a blue sparkle that plays its default animation.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
static void AnimRockPolishSparkle(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
}

// Moves a projectile towards the center of the target mon.  The sprite is rotated to look
// like it's traveling along that path.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
static void AnimPoisonJabProjectile(struct Sprite *sprite)
{
    s16 targetXPos;
    s16 targetYPos;
    u16 rotation;

    InitSpritePosToAnimTarget(sprite, TRUE);
    targetXPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    targetYPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    rotation = ArcTan2Neg(targetXPos - sprite->x, targetYPos - sprite->y);
    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = targetXPos;
    sprite->data[4] = targetYPos;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimTask_BlendNightSlash(u8 taskId)
{
    int paletteOffset = IndexOfSpritePaletteTag(ANIM_TAG_SLASH) * 16 + 256;
    BlendPalette(paletteOffset, 16, 6, RGB_RED);
    DestroyAnimVisualTask(taskId);
}

static void AnimNightSlash(struct Sprite *sprite)
{
    sprite->callback = AnimSlashSlice;
    sprite->callback(sprite);
}

static const union AffineAnimCmd sCompressTargetHorizontallyAffineAnimCmds[] =
{
	AFFINEANIMCMD_FRAME(64, 0, 0, 16), //Compress
	AFFINEANIMCMD_FRAME(0, 0, 0, 64),
	AFFINEANIMCMD_FRAME(-64, 0, 0, 16),
	AFFINEANIMCMD_END,
};

static void AnimTask_CompressTargetStep(u8 taskId)
{
	struct Task* task = &gTasks[taskId];

	if (!RunAffineAnimFromTaskData(task))
		DestroyAnimVisualTask(taskId);
}

void AnimTask_CompressTargetHorizontally(u8 taskId)
{
	struct Task* task = &gTasks[taskId];
	u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
	PrepareAffineAnimInTaskData(task, spriteId, sCompressTargetHorizontallyAffineAnimCmds);
	task->func = AnimTask_CompressTargetStep;
}

const struct SpriteTemplate gSteelBeamBigOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_STEEL_BEAM,
    .paletteTag = ANIM_TAG_STEEL_BEAM,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamBigOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSolarBeamBigOrb,
};

const struct SpriteTemplate gSteelBeamSmallOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_STEEL_BEAM,
    .paletteTag = ANIM_TAG_STEEL_BEAM,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSolarBeamSmallOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSolarBeamSmallOrb,
};

void AnimTask_CreateSmallSteelBeamOrbs(u8 taskId)
{
    if (--gTasks[taskId].data[0] == -1)
    {
        gTasks[taskId].data[1]++;
        gTasks[taskId].data[0] = 6;
        gBattleAnimArgs[0] = 15;
        gBattleAnimArgs[1] = 0;
        gBattleAnimArgs[2] = 80;
        gBattleAnimArgs[3] = 0;
        CreateSpriteAndAnimate(&gSteelBeamSmallOrbSpriteTemplate, 0, 0, GetBattlerSpriteSubpriority(gBattleAnimTarget) + 1);
    }

    if (gTasks[taskId].data[1] == 15)
        DestroyAnimVisualTask(taskId);
}
