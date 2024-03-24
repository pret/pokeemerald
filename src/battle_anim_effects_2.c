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

static void AnimCirclingFinger(struct Sprite *);
static void AnimBouncingMusicNote(struct Sprite *);
static void AnimBouncingMusicNote_Step(struct Sprite *);
static void AnimVibrateBattlerBack(struct Sprite *);
static void AnimMovingClamp(struct Sprite *);
static void AnimMovingClamp_Step(struct Sprite *);
static void AnimMovingClamp_End(struct Sprite *);
static void AnimKinesisZapEnergy(struct Sprite *);
static void AnimSwordsDanceBlade(struct Sprite *);
static void AnimSwordsDanceBlade_Step(struct Sprite *);
static void AnimAirWaveProjectile(struct Sprite *);
static void AnimAirWaveProjectile_Step1(struct Sprite *sprite);
static void AnimAirWaveProjectile_Step2(struct Sprite *sprite);
static void AnimVoidLines(struct Sprite *);
static void AnimVoidLines_Step(struct Sprite *);
static void AnimCoinThrow(struct Sprite *);
static void AnimFallingCoin(struct Sprite *);
static void AnimFallingCoin_Step(struct Sprite *);
static void AnimBulletSeed(struct Sprite *);
static void AnimBulletSeed_Step1(struct Sprite *);
static void AnimBulletSeed_Step2(struct Sprite *);
static void AnimRazorWindTornado(struct Sprite *);
static void AnimViceGripPincer(struct Sprite *);
static void AnimViceGripPincer_Step(struct Sprite *);
static void AnimGuillotinePincer(struct Sprite *);
static void AnimGuillotinePincer_Step1(struct Sprite *);
static void AnimGuillotinePincer_Step2(struct Sprite *);
static void AnimGuillotinePincer_Step3(struct Sprite *);
static void AnimBreathPuff(struct Sprite *);
static void AnimPencil(struct Sprite *);
static void AnimPencil_Step(struct Sprite *);
static void AnimBlendThinRing(struct Sprite *);
static void AnimSoftBoiledEgg(struct Sprite *);
static void AnimSoftBoiledEgg_Step1(struct Sprite *);
static void AnimSoftBoiledEgg_Step2(struct Sprite *);
static void AnimSoftBoiledEgg_Step3(struct Sprite *);
static void AnimSoftBoiledEgg_Step3_Callback1(struct Sprite *);
static void AnimSoftBoiledEgg_Step3_Callback2(struct Sprite *);
static void AnimSoftBoiledEgg_Step4(struct Sprite *);
static void AnimSoftBoiledEgg_Step4_Callback(struct Sprite *);
static void AnimSpeedDust(struct Sprite *);
static void AnimHealBellMusicNote(struct Sprite *);
static void AnimRedHeartProjectile(struct Sprite *);
static void AnimRedHeartProjectile_Step(struct Sprite *);
static void AnimRedHeartRising(struct Sprite *);
static void AnimRedHeartRising_Step(struct Sprite *);
static void AnimOrbitFast_Step(struct Sprite *);
static void AnimOrbitScatter_Step(struct Sprite *);
static void AnimSpitUpOrb(struct Sprite *);
static void AnimSpitUpOrb_Step(struct Sprite *sprite);
static void AnimEyeSparkle(struct Sprite *);
static void AnimEyeSparkle_Step(struct Sprite *sprite);
static void AnimAngel(struct Sprite *);
static void AnimPinkHeart(struct Sprite *);
static void AnimDevil(struct Sprite *);
static void AnimFurySwipes(struct Sprite *);
static void AnimMovementWaves(struct Sprite *);
static void AnimMovementWaves_Step(struct Sprite *);
static void AnimJaggedMusicNote(struct Sprite *);
static void AnimJaggedMusicNote_Step(struct Sprite *);
static void AnimPerishSongMusicNote2(struct Sprite *);
static void AnimPerishSongMusicNote(struct Sprite *);
static void AnimPerishSongMusicNote_Step1(struct Sprite *);
static void AnimPerishSongMusicNote_Step2(struct Sprite *);
static void AnimGuardRing(struct Sprite *);
static void AnimTask_Withdraw_Step(u8);
static void AnimTask_GrowAndGrayscale_Step(u8);
static void AnimTask_Minimize_Step(u8);
static void CreateMinimizeSprite(struct Task *, u8);
static void ClonedMinizeSprite_Step(struct Sprite *);
static void AnimTask_Splash_Step(u8);
static void AnimTask_GrowAndShrink_Step(u8);
static void AnimTask_ThrashMoveMonHorizontal_Step(u8);
static void AnimTask_ThrashMoveMonVertical_Step(u8);
static void AnimTask_SketchDrawMon_Step(u8);
static void AnimTask_AttackerStretchAndDisappear_Step(u8);
static void AnimTask_ExtremeSpeedImpact_Step(u8);
static void AnimTask_ExtremeSpeedMonReappear_Step(u8);
static void AnimTask_SpeedDust_Step(u8);
static void AnimTask_FakeOut_Step1(u8);
static void AnimTask_FakeOut_Step2(u8);
static void AnimTask_HeartsBackground_Step(u8);
static void AnimTask_ScaryFace_Step(u8);
static void AnimTask_UproarDistortion_Step(u8);

// Unused
static const struct SpriteTemplate sCirclingFingerSpriteTemplate =
{
    .tileTag = ANIM_TAG_FINGER,
    .paletteTag = ANIM_TAG_FINGER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCirclingFinger,
};

static const union AnimCmd sAnim_BouncingMusicNote[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

// Unused (association assumed)
static const union AnimCmd *const sAnims_BouncingMusicNote[] =
{
    sAnim_BouncingMusicNote,
};

// Unused
static const struct SpriteTemplate sBouncingMusicNoteSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES,
    .paletteTag = ANIM_TAG_MUSIC_NOTES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBouncingMusicNote,
};

// Unused
static const struct SpriteTemplate sVibrateBattlerBackSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimVibrateBattlerBack,
};

// Unused
static const struct SpriteTemplate sMovingClampSpriteTemplate =
{
    .tileTag = ANIM_TAG_CLAMP,
    .paletteTag = ANIM_TAG_CLAMP,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_Bite,
    .callback = AnimMovingClamp,
};

static const union AnimCmd sAnim_SmallExplosion[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_SmallExplosion[] =
{
    sAnim_SmallExplosion,
};

static const union AffineAnimCmd sAffineAnim_SmallExplosion[] =
{
    AFFINEANIMCMD_FRAME(0x50, 0x50, 0, 0),
    AFFINEANIMCMD_FRAME(0x9, 0x9, 0, 18),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_SmallExplosion[] =
{
    sAffineAnim_SmallExplosion,
};

// Unused
static const struct SpriteTemplate sSmallExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION_6,
    .paletteTag = ANIM_TAG_EXPLOSION_6,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = sAnims_SmallExplosion,
    .images = NULL,
    .affineAnims = sAffineAnims_SmallExplosion,
    .callback = AnimSpriteOnMonPos,
};

const union AnimCmd gKinesisZapEnergyAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(24, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(40, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_END,
};

const union AnimCmd *const gKinesisZapEnergyAnimTable[] =
{
    gKinesisZapEnergyAnimCmds,
};

const struct SpriteTemplate gKinesisZapEnergySpriteTemplate =
{
    .tileTag = ANIM_TAG_ALERT,
    .paletteTag = ANIM_TAG_ALERT,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gKinesisZapEnergyAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimKinesisZapEnergy,
};

const union AffineAnimCmd gSwordsDanceBladeAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x14, 0x0, 0, 12),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 32),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSwordsDanceBladeAffineAnimTable[] =
{
    gSwordsDanceBladeAffineAnimCmds,
};

const struct SpriteTemplate gSwordsDanceBladeSpriteTemplate =
{
    .tileTag = ANIM_TAG_SWORD,
    .paletteTag = ANIM_TAG_SWORD,
    .oam = &gOamData_AffineNormal_ObjBlend_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSwordsDanceBladeAffineAnimTable,
    .callback = AnimSwordsDanceBlade,
};

const struct SpriteTemplate gSonicBoomSpriteTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_AIR_WAVE,
    .oam = &gOamData_AffineDouble_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSonicBoomProjectile,
};

const struct SpriteTemplate gAirWaveProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_AIR_WAVE,
    .paletteTag = ANIM_TAG_AIR_WAVE,
    .oam = &gOamData_AffineOff_ObjBlend_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAirWaveProjectile,
};

const union AffineAnimCmd gGrowingRingAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 0),
    AFFINEANIMCMD_FRAME(0x7, 0x7, 0, -56),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gWaterPulseRingAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 10),
    AFFINEANIMCMD_FRAME(0xA, 0xA, 0, 10),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gGrowingRingAffineAnimTable[] =
{
    gGrowingRingAffineAnimCmds,
};

const union AffineAnimCmd *const gWaterPulseRingAffineAnimTable[] =
{
    gWaterPulseRingAffineAnimCmds,
};

const struct SpriteTemplate gSupersonicRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_RING,
    .paletteTag = ANIM_TAG_GOLD_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gScreechRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_PURPLE_RING,
    .paletteTag = ANIM_TAG_PURPLE_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gMetalSoundSpriteTemplate =
{
    .tileTag = ANIM_TAG_METAL_SOUND_WAVES,
    .paletteTag = ANIM_TAG_METAL_SOUND_WAVES,
    .oam = &gOamData_AffineDouble_ObjNormal_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = TranslateAnimSpriteToTargetMonLocation,
};

const struct SpriteTemplate gWaterPulseRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_RING_2,
    .paletteTag = ANIM_TAG_BLUE_RING_2,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gWaterPulseRingAffineAnimTable,
    .callback = AnimWaterPulseRing,
};

const struct SpriteTemplate gEggThrowSpriteTemplate =
{
    .tileTag = ANIM_TAG_LARGE_FRESH_EGG,
    .paletteTag = ANIM_TAG_LARGE_FRESH_EGG,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile,
};

// Unused
static const struct SpriteTemplate sVoidLinesSpriteTemplate =
{
    .tileTag = ANIM_TAG_VOID_LINES,
    .paletteTag = ANIM_TAG_VOID_LINES,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimVoidLines,
};

const union AnimCmd gCoinAnimCmds[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gCoinAnimTable[] =
{
    gCoinAnimCmds,
};

const union AffineAnimCmd gFallingCoinAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gFallingCoinAffineAnimTable[] =
{
    gFallingCoinAffineAnimCmds,
};

const struct SpriteTemplate gCoinThrowSpriteTemplate =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gCoinAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimCoinThrow,
};

const struct SpriteTemplate gFallingCoinSpriteTemplate =
{
    .tileTag = ANIM_TAG_COIN,
    .paletteTag = ANIM_TAG_COIN,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gCoinAnimTable,
    .images = NULL,
    .affineAnims = gFallingCoinAffineAnimTable,
    .callback = AnimFallingCoin,
};

const union AffineAnimCmd gBulletSeedAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 20, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gBulletSeedAffineAnimTable[] =
{
    gBulletSeedAffineAnimCmds,
};

const struct SpriteTemplate gBulletSeedSpriteTemplate =
{
    .tileTag = ANIM_TAG_SEED,
    .paletteTag = ANIM_TAG_SEED,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gBulletSeedAffineAnimTable,
    .callback = AnimBulletSeed,
};

const union AffineAnimCmd gRazorWindTornadoAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x0, 0, 40),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gRazorWindTornadoAffineAnimTable[] =
{
    gRazorWindTornadoAffineAnimCmds,
};

const struct SpriteTemplate gRazorWindTornadoSpriteTemplate =
{
    .tileTag = ANIM_TAG_GUST,
    .paletteTag = ANIM_TAG_GUST,
    .oam = &gOamData_AffineNormal_ObjNormal_32x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gRazorWindTornadoAffineAnimTable,
    .callback = AnimRazorWindTornado,
};

const union AnimCmd gViceGripAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 20),
    ANIMCMD_END,
};

const union AnimCmd gViceGripAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 20, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gViceGripAnimTable[] =
{
    gViceGripAnimCmds1,
    gViceGripAnimCmds2,
};

const struct SpriteTemplate gViceGripSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gViceGripAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimViceGripPincer,
};

const union AnimCmd gGuillotineAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

const union AnimCmd gGuillotineAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 1, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gGuillotineAnimTable[] =
{
    gGuillotineAnimCmds1,
    gGuillotineAnimCmds2,
};

const struct SpriteTemplate gGuillotineSpriteTemplate =
{
    .tileTag = ANIM_TAG_CUT,
    .paletteTag = ANIM_TAG_CUT,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gGuillotineAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGuillotinePincer,
};

const union AffineAnimCmd gSplashEffectAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-6, 4, 0, 8),
    AFFINEANIMCMD_FRAME(10, -10, 0, 8),
    AFFINEANIMCMD_FRAME(-4, 6, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gGrowAndShrinkAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-4, -5, 0, 12),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(4, 5, 0, 12),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gShrinkAndGrowAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(4, 5, 0, 12),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(-4, -5, 0, 6),
    AFFINEANIMCMD_END,
};

const union AnimCmd gBreathPuffAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 40, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(12, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gBreathPuffAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 40),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gBreathPuffAnimTable[] =
{
    gBreathPuffAnimCmds1,
    gBreathPuffAnimCmds2,
};

const struct SpriteTemplate gBreathPuffSpriteTemplate =
{
    .tileTag = ANIM_TAG_BREATH,
    .paletteTag = ANIM_TAG_BREATH,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gBreathPuffAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBreathPuff,
};

const union AffineAnimCmd gAngerMarkAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0xB, 0xB, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF5, 0xFFF5, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gAngerMarkAffineAnimTable[] =
{
    gAngerMarkAffineAnimCmds,
};

const struct SpriteTemplate gAngerMarkSpriteTemplate =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_ANGER,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAngerMarkAffineAnimTable,
    .callback = AnimAngerMark,
};

const union AffineAnimCmd gThrashMoveMonAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-10, 9, 0, 7),
    AFFINEANIMCMD_FRAME(20, -20, 0, 7),
    AFFINEANIMCMD_FRAME(-20, 20, 0, 7),
    AFFINEANIMCMD_FRAME(10, -9, 0, 7),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gPencilSpriteTemplate =
{
    .tileTag = ANIM_TAG_PENCIL,
    .paletteTag = ANIM_TAG_PENCIL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPencil,
};

const struct SpriteTemplate gSnoreZSpriteTemplate =
{
    .tileTag = ANIM_TAG_SNORE_Z,
    .paletteTag = ANIM_TAG_SNORE_Z,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTravelDiagonally,
};

const union AnimCmd gExplosionAnimCmds[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gExplosionAnimTable[] =
{
    gExplosionAnimCmds,
};

const struct SpriteTemplate gExplosionSpriteTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const union AffineAnimCmd gSoftBoiledEggAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 2),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 2),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gSoftBoiledEggAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSoftBoiledEggAffineAnimCmds3[] =
{
    AFFINEANIMCMD_FRAME(0xFFF8, 0x4, 0, 8),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(0x10, 0xFFF8, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFF0, 0x8, 0, 8),
    AFFINEANIMCMD_LOOP(1),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSoftBoiledEggAffineAnimTable[] =
{
    gSoftBoiledEggAffineAnimCmds1,
    gSoftBoiledEggAffineAnimCmds2,
    gSoftBoiledEggAffineAnimCmds3,
};

const struct SpriteTemplate gSoftBoiledEggSpriteTemplate =
{
    .tileTag = ANIM_TAG_BREAKING_EGG,
    .paletteTag = ANIM_TAG_BREAKING_EGG,
    .oam = &gOamData_AffineDouble_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSoftBoiledEggAffineAnimTable,
    .callback = AnimSoftBoiledEgg,
};

const union AffineAnimCmd gThinRingExpandingAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 30),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gThinRingExpandingAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 15),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gHyperVoiceRingAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0),
    AFFINEANIMCMD_FRAME(0xB, 0xB, 0, 45),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gThinRingExpandingAffineAnimTable[] =
{
    gThinRingExpandingAffineAnimCmds1,
    gThinRingExpandingAffineAnimCmds2,
};

const union AffineAnimCmd *const gHyperVoiceRingAffineAnimTable[] =
{
    gHyperVoiceRingAffineAnimCmds,
};

const struct SpriteTemplate gThinRingExpandingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const union AffineAnimCmd gThinRingShrinkingAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF0, 0xFFF0, 0, 30),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gThinRingShrinkingAffineAnimTable[] =
{
    gThinRingShrinkingAffineAnimCmds,
};

const struct SpriteTemplate gThinRingShrinkingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingShrinkingAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlendThinRingExpandingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimBlendThinRing,
};

const struct SpriteTemplate gHyperVoiceRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHyperVoiceRingAffineAnimTable,
    .callback = AnimHyperVoiceRing,
};

const struct SpriteTemplate gUproarRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_THIN_RING,
    .paletteTag = ANIM_TAG_THIN_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gThinRingExpandingAffineAnimTable,
    .callback = AnimUproarRing,
};

const union AffineAnimCmd gStretchAttackerAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(96, -13, 0, 8),
    AFFINEANIMCMD_END,
};

const union AnimCmd gSpeedDustAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(4, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gSpeedDustAnimTable[] =
{
    gSpeedDustAnimCmds,
};

const struct SpriteTemplate gSpeedDustSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPEED_DUST,
    .paletteTag = ANIM_TAG_SPEED_DUST,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gSpeedDustAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpeedDust,
};

const s8 gSpeedDustPosTable[][2] =
{
    {30, 28},
    {-20, 24},
    {16, 26},
    {-10, 28},
};

const union AnimCmd gBellAnimCmds[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 15, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 15),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gBellAnimTable[] =
{
    gBellAnimCmds,
};

const struct SpriteTemplate gBellSpriteTemplate =
{
    .tileTag = ANIM_TAG_BELL,
    .paletteTag = ANIM_TAG_BELL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gBellAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

#define NUM_MUSIC_NOTE_PAL_TAGS  3

static const u16 sMusicNotePaletteTagsTable[NUM_MUSIC_NOTE_PAL_TAGS] =
{
    ANIM_TAG_MUSIC_NOTES_2,
    ANIM_SPRITES_START - 1,
    ANIM_SPRITES_START - 2,
};

const struct SpriteTemplate gHealBellMusicNoteSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHealBellMusicNote,
};

const struct SpriteTemplate gMagentaHeartSpriteTemplate =
{
    .tileTag = ANIM_TAG_MAGENTA_HEART,
    .paletteTag = ANIM_TAG_MAGENTA_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMagentaHeart,
};

static const union AffineAnimCmd sAffineAnims_StretchBattlerUp[] =
{
    AFFINEANIMCMD_FRAME(0x000A, 0xFFF3, 0x00, 0x0A),
    AFFINEANIMCMD_FRAME(0xFFF6, 0x000D, 0x00, 0x0A),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gRedHeartProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRedHeartProjectile,
};

const struct SpriteTemplate gRedHeartBurstSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleBurst,
};

const struct SpriteTemplate gRedHeartRisingSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_HEART,
    .paletteTag = ANIM_TAG_RED_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRedHeartRising,
};

const union AffineAnimCmd gHiddenPowerOrbAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gHiddenPowerOrbAffineAnimTable[] =
{
    gHiddenPowerOrbAffineAnimCmds,
};

const struct SpriteTemplate gHiddenPowerOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gHiddenPowerOrbScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB,
    .paletteTag = ANIM_TAG_RED_ORB,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitScatter,
};

const struct SpriteTemplate gPowerGemOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitFast,
};

const struct SpriteTemplate gPowerGemOrbScatterSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_GEM,
    .paletteTag = ANIM_TAG_POWER_GEM,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gHiddenPowerOrbAffineAnimTable,
    .callback = AnimOrbitScatter,
};

const union AffineAnimCmd gSpitUpOrbAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x8, 0x8, 0, 1),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd *const gSpitUpOrbAffineAnimTable[] =
{
    gSpitUpOrbAffineAnimCmds,
};

const struct SpriteTemplate gSpitUpOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_ORB_2,
    .paletteTag = ANIM_TAG_RED_ORB_2,
    .oam = &gOamData_AffineDouble_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpitUpOrbAffineAnimTable,
    .callback = AnimSpitUpOrb,
};

const union AnimCmd gEyeSparkleAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gEyeSparkleAnimTable[] =
{
    gEyeSparkleAnimCmds,
};

const struct SpriteTemplate gEyeSparkleSpriteTemplate =
{
    .tileTag = ANIM_TAG_EYE_SPARKLE,
    .paletteTag = ANIM_TAG_EYE_SPARKLE,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gEyeSparkleAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimEyeSparkle,
};

const union AnimCmd gAngelSpriteAnimCmds[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_END,
};

const union AnimCmd *const gAngelSpriteAnimTable[] =
{
    gAngelSpriteAnimCmds,
};

const struct SpriteTemplate gAngelSpriteTemplate =
{
    .tileTag = ANIM_TAG_ANGEL,
    .paletteTag = ANIM_TAG_ANGEL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gAngelSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAngel,
};

const struct SpriteTemplate gPinkHeartSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINK_HEART,
    .paletteTag = ANIM_TAG_PINK_HEART,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPinkHeart,
};

const union AnimCmd gDevilAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gDevilAnimCmds2[] =
{
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gDevilAnimTable[] =
{
    gDevilAnimCmds1,
    gDevilAnimCmds2,
};

const struct SpriteTemplate gDevilSpriteTemplate =
{
    .tileTag = ANIM_TAG_DEVIL,
    .paletteTag = ANIM_TAG_DEVIL,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDevilAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimDevil,
};

static const union AnimCmd sAnim_FurySwipes[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FurySwipes_Flipped[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_FurySwipes[] =
{
    sAnim_FurySwipes,
    sAnim_FurySwipes_Flipped,
};

const struct SpriteTemplate gFurySwipesSpriteTemplate =
{
    .tileTag = ANIM_TAG_SWIPE,
    .paletteTag = ANIM_TAG_SWIPE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_FurySwipes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFurySwipes,
};

const union AnimCmd gMovementWavesAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};

const union AnimCmd gMovementWavesAnimCmds2[] =
{
    ANIMCMD_FRAME(16, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd *const gMovementWavesAnimTable[] =
{
    gMovementWavesAnimCmds1,
    gMovementWavesAnimCmds2,
};

const struct SpriteTemplate gMovementWavesSpriteTemplate =
{
    .tileTag = ANIM_TAG_MOVEMENT_WAVES,
    .paletteTag = ANIM_TAG_MOVEMENT_WAVES,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gMovementWavesAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMovementWaves,
};

static const union AffineAnimCmd sAffineAnims_UproarDistortion[] =
{
    AFFINEANIMCMD_FRAME(-12, 8, 0, 4),
    AFFINEANIMCMD_FRAME(20, -20, 0, 4),
    AFFINEANIMCMD_FRAME(-8, 12, 0, 4),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gJaggedMusicNoteSpriteTemplate =
{
    .tileTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .paletteTag = ANIM_TAG_JAGGED_MUSIC_NOTE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimJaggedMusicNote,
};

const union AffineAnimCmd gPerishSongMusicNoteAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 5),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gPerishSongMusicNoteAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 16),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd gPerishSongMusicNoteAffineAnimCmds3[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 16),
    AFFINEANIMCMD_END_ALT(1),
};

const union AffineAnimCmd *const gPerishSongMusicNoteAffineAnimTable[] =
{
    gPerishSongMusicNoteAffineAnimCmds1,
    gPerishSongMusicNoteAffineAnimCmds2,
    gPerishSongMusicNoteAffineAnimCmds3,
};

const struct SpriteTemplate gPerishSongMusicNoteSpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gMusicNotesAnimTable,
    .images = NULL,
    .affineAnims = gPerishSongMusicNoteAffineAnimTable,
    .callback = AnimPerishSongMusicNote,
};

const struct SpriteTemplate gPerishSongMusicNote2SpriteTemplate =
{
    .tileTag = ANIM_TAG_MUSIC_NOTES_2,
    .paletteTag = ANIM_TAG_MUSIC_NOTES_2,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gMusicNotesAnimTable,
    .images = NULL,
    .affineAnims = gPerishSongMusicNoteAffineAnimTable,
    .callback = AnimPerishSongMusicNote2,
};

const union AffineAnimCmd gGuardRingAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gGuardRingAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gGuardRingAffineAnimTable[] =
{
    gGuardRingAffineAnimCmds1,
    gGuardRingAffineAnimCmds2,
};

const struct SpriteTemplate gGuardRingSpriteTemplate =
{
    .tileTag = ANIM_TAG_GUARD_RING,
    .paletteTag = ANIM_TAG_GUARD_RING,
    .oam = &gOamData_AffineDouble_ObjBlend_64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGuardRingAffineAnimTable,
    .callback = AnimGuardRing,
};

const struct SpriteTemplate gCrushGripExplosionTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_EXPLOSION,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

const struct SpriteTemplate gRoarOfTimeBombTemplate =
{
    .tileTag = ANIM_TAG_EXPLOSION,
    .paletteTag = ANIM_TAG_WATER_GUN,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gExplosionAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos
};

#define sAmplitudeX  data[1]
#define sCircleSpeed data[2]
#define sMoveSteps   data[3]
#define sAmplitudeY  data[4]

static void AnimCirclingFinger(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->sAmplitudeX = gBattleAnimArgs[2];
    sprite->sCircleSpeed = gBattleAnimArgs[4];
    sprite->sMoveSteps = gBattleAnimArgs[5];
    sprite->sAmplitudeY = gBattleAnimArgs[3];
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteInEllipse;
    sprite->callback(sprite);
}

#undef sAmplitudeX
#undef sCircleSpeed
#undef sMoveSteps
#undef sAmplitudeY

static void AnimBouncingMusicNote(struct Sprite *sprite)
{
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    SetSpriteNextToMonHead(battler, sprite);
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = AnimBouncingMusicNote_Step;
}

static void AnimBouncingMusicNote_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->y2 -= 3;
        if (++sprite->data[1] == 6)
            sprite->data[0]++;
        break;
    case 1:
        sprite->y2 += 3;
        if (--sprite->data[1] == 0)
            sprite->data[0]++;
        break;
    case 2:
        if (++sprite->data[1] == 64)
            DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimVibrateBattlerBack_Step(struct Sprite *sprite)
{
    s16 temp;
    gSprites[sprite->data[2]].x2 += sprite->data[1];
    temp = sprite->data[1];
    sprite->data[1] = -temp;
    if (sprite->data[0] == 0)
    {
        gSprites[sprite->data[2]].x2 = 0;
        DestroySpriteAndMatrix(sprite);
    }

    sprite->data[0]--;
}

static void AnimVibrateBattlerBack(struct Sprite *sprite)
{
    u8 spriteId;
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    spriteId = gBattlerSpriteIds[gBattleAnimTarget];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = spriteId;
    sprite->callback = AnimVibrateBattlerBack_Step;
    sprite->invisible = TRUE;
}

static void AnimMovingClamp(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[4];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimMovingClamp_Step);
}

static void AnimMovingClamp_Step(struct Sprite *sprite)
{
    sprite->data[0] = sprite->data[1];
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y + 15;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, AnimMovingClamp_End);
}

static void AnimMovingClamp_End(struct Sprite *sprite)
{
    if (sprite->data[5] == 0)
        DestroyAnimSprite(sprite);
    else
        sprite->data[5]--;
}

// Rotates the attacking mon sprite downwards and then back upwards to its original position.
// No args.
void AnimTask_Withdraw(u8 taskId)
{
    PrepareBattlerSpriteForRotScale(gBattlerSpriteIds[gBattleAnimAttacker], ST_OAM_OBJ_NORMAL);
    gTasks[taskId].func = AnimTask_Withdraw_Step;
}

static void AnimTask_Withdraw_Step(u8 taskId)
{
    u8 spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    s16 rotation;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        rotation = -gTasks[taskId].data[0];
    else
        rotation = gTasks[taskId].data[0];

    SetSpriteRotScale(spriteId, 0x100, 0x100, rotation);
    if (gTasks[taskId].data[1] == 0)
    {
        gTasks[taskId].data[0] += 0xB0;
        // this y position update gets overwritten by SetBattlerSpriteYOffsetFromRotation()
        gSprites[spriteId].y2++;
    }
    else if (gTasks[taskId].data[1] == 1)
    {
        if (++gTasks[taskId].data[3] == 30)
            gTasks[taskId].data[1] = 2;

        return;
    }
    else
    {
        gTasks[taskId].data[0] -= 0xB0;
        // this y position update gets overwritten by SetBattlerSpriteYOffsetFromRotation()
        gSprites[spriteId].y2--;
    }

    SetBattlerSpriteYOffsetFromRotation(spriteId);
    if (gTasks[taskId].data[0] == 0xF20 || gTasks[taskId].data[0] == 0)
    {
        if (gTasks[taskId].data[1] == 2)
        {
            ResetSpriteRotScale(spriteId);
            DestroyAnimVisualTask(taskId);
        }
        else
        {
            gTasks[taskId].data[1]++;
        }
    }
}

// Animates a "zap of energy" used in KINESIS.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: vertical flip
static void AnimKinesisZapEnergy(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->hFlip = 1;
        if (gBattleAnimArgs[2])
            sprite->vFlip = 1;
    }
    else
    {
        if (gBattleAnimArgs[2])
            sprite->vFlip = 1;
    }

    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates a sword that rises into the air after a brief pause.
// arg 0: x pixel offset
// arg 1: y pixel offset
static void AnimSwordsDanceBlade(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, AnimSwordsDanceBlade_Step);
}

static void AnimSwordsDanceBlade_Step(struct Sprite *sprite)
{
    sprite->data[0] = 6;
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y - 32;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Moves a projectile towards the target mon. The sprite is rotated to be pointing
// in the same direction it's moving.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x pixel offset
// arg 3: target y pixel offset
// arg 4: duration
void AnimSonicBoomProjectile(struct Sprite *sprite)
{
    s16 targetXPos;
    s16 targetYPos;
    u16 rotation;

    if (IsContest())
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    }
    else if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    InitSpritePosToAnimAttacker(sprite, TRUE);
    targetXPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    targetYPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    rotation = ArcTan2Neg(targetXPos - sprite->x, targetYPos - sprite->y);
    rotation += 0xF000;
    if (IsContest())
        rotation -= 0x6000;

    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = targetXPos;
    sprite->data[4] = targetYPos;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimAirWaveProjectile_Step2(struct Sprite *sprite)
{
    if (sprite->data[0]-- <= 0)
    {
        gTasks[sprite->data[7]].data[1]--;
        DestroySprite(sprite);
    }
}

static void AnimAirWaveProjectile_Step1(struct Sprite *sprite)
{
    struct Task *task = &gTasks[sprite->data[7]];
    if (sprite->data[0] > task->data[5])
    {
        sprite->data[5] += sprite->data[3];
        sprite->data[6] += sprite->data[4];
    }
    else
    {
        sprite->data[5] -= sprite->data[3];
        sprite->data[6] -= sprite->data[4];
    }

    sprite->data[1] += sprite->data[5];
    sprite->data[2] += sprite->data[6];
    if (1 & task->data[7])
        sprite->x2 = ((u16)sprite->data[1] >> 8) * -1;
    else
        sprite->x2 = (u16)sprite->data[1] >> 8;

    if (1 & task->data[8])
        sprite->y2 = ((u16)sprite->data[2] / 256u) * -1;
    else
        sprite->y2 = (u16)sprite->data[2] / 256u;

    if (sprite->data[0]-- <= 0)
    {
        sprite->data[0] = 30;
        sprite->callback = AnimAirWaveProjectile_Step2;
    }
}

static void AnimAirWaveProjectile(struct Sprite *sprite)
{
    s16 a;
    s16 b;
    s16 c;

    struct Task *task = &gTasks[sprite->data[7]];
    sprite->data[1] += (-2 & task->data[7]);
    sprite->data[2] += (-2 & task->data[8]);
    if (1 & task->data[7])
        sprite->x2 = ((u16)sprite->data[1] >> 8) * -1;
    else
        sprite->x2 = (u16)sprite->data[1] >> 8;

    if (1 & task->data[8])
        sprite->y2 = ((u16)sprite->data[2] / 256u) * -1;
    else
        sprite->y2 = (u16)sprite->data[2] / 256u;

    if (sprite->data[0]-- <= 0)
    {
        sprite->data[0] = 8;
        task->data[5] = 4;
        a = MathUtil_Inv16(Q_8_8(16));
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->y2 = 0;
        sprite->x2 = 0;
        if (task->data[11] >= sprite->x)
            b = (task->data[11] - sprite->x) << 8;
        else
            b = (sprite->x - task->data[11]) << 8;

        if (task->data[12] >= sprite->y)
            c = (task->data[12] - sprite->y) << 8;
        else
            c = (sprite->y - task->data[12]) << 8;

        sprite->data[2] = 0;
        sprite->data[1] = 0;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[3] = MathUtil_Mul16(MathUtil_Mul16(b, a), MathUtil_Inv16(Q_8_8(1.75)));
        sprite->data[4] = MathUtil_Mul16(MathUtil_Mul16(c, a), MathUtil_Inv16(Q_8_8(1.75)));
        sprite->callback = AnimAirWaveProjectile_Step1;
    }
}

static void AirCutterProjectileStep2(u8 taskId)
{
    if (gTasks[taskId].data[1] == 0)
        DestroyAnimVisualTask(taskId);
}

static void AirCutterProjectileStep1(u8 taskId)
{
    if (gTasks[taskId].data[0]-- <= 0)
    {
        u8 spriteId;
        struct Sprite *sprite;
        spriteId = CreateSprite(&gAirWaveProjectileSpriteTemplate, gTasks[taskId].data[9], gTasks[taskId].data[10], gTasks[taskId].data[2] - gTasks[taskId].data[1]);
        sprite = &gSprites[spriteId];
        switch (gTasks[taskId].data[4])
        {
        case 1:
            sprite->oam.matrixNum |= (ST_OAM_HFLIP | ST_OAM_VFLIP);
            break;
        case 2:
            sprite->oam.matrixNum = ST_OAM_HFLIP;
            break;
        }

        sprite->data[0] = gTasks[taskId].data[5] - gTasks[taskId].data[6];
        sprite->data[7] = taskId;
        gTasks[taskId].data[gTasks[taskId].data[1] + 13] = spriteId;
        gTasks[taskId].data[0] = gTasks[taskId].data[3];
        gTasks[taskId].data[1]++;
        PlaySE12WithPanning(SE_M_BLIZZARD2, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER + 1));
        if (gTasks[taskId].data[1] > 2)
            gTasks[taskId].func = AirCutterProjectileStep2;
    }
}

void AnimTask_AirCutterProjectile(u8 taskId)
{
    s16 attackerY = 0;
    s16 attackerX = 0;
    s16 targetX = 0;
    s16 targetY = 0;
    s16 xDiff, yDiff;

    if (IsContest())
    {
        gTasks[taskId].data[4] = 2;
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
        if (gBattleAnimArgs[2] & 1)
            gBattleAnimArgs[2] &= ~1;
        else
            gBattleAnimArgs[2] |= 1;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        {
            gTasks[taskId].data[4] = 1;
            gBattleAnimArgs[0] = -gBattleAnimArgs[0];
            gBattleAnimArgs[1] = -gBattleAnimArgs[1];
            if (gBattleAnimArgs[2] & 1)
                gBattleAnimArgs[2] &= ~1;
            else
                gBattleAnimArgs[2] |= 1;
        }
    }

    attackerX = gTasks[taskId].data[9] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    attackerY = gTasks[taskId].data[10] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        && IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
    {
        SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &targetX, &targetY);
    }
    else
    {
        targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }

    targetX = gTasks[taskId].data[11] = targetX + gBattleAnimArgs[0];
    targetY = gTasks[taskId].data[12] = targetY + gBattleAnimArgs[1];
    if (targetX >= attackerX)
        xDiff = targetX - attackerX;
    else
        xDiff = attackerX - targetX;

    gTasks[taskId].data[5] = MathUtil_Mul16(xDiff, MathUtil_Inv16(gBattleAnimArgs[2] & ~1));
    gTasks[taskId].data[6] = MathUtil_Mul16(gTasks[taskId].data[5], Q_8_8(0.5));
    gTasks[taskId].data[7] = gBattleAnimArgs[2];
    if (targetY >= attackerY)
    {
        yDiff = targetY - attackerY;
        gTasks[taskId].data[8] = MathUtil_Mul16(yDiff, MathUtil_Inv16(gTasks[taskId].data[5])) & ~1;
    }
    else
    {
        yDiff = attackerY - targetY;
        gTasks[taskId].data[8] = MathUtil_Mul16(yDiff, MathUtil_Inv16(gTasks[taskId].data[5])) | 1;
    }

    gTasks[taskId].data[3] = gBattleAnimArgs[3];
    if (gBattleAnimArgs[4] & 0x80)
    {
        gBattleAnimArgs[4] ^= 0x80;
        if (gBattleAnimArgs[4] >= 64)
        {
            u16 var = GetBattlerSpriteSubpriority(gBattleAnimTarget) + (gBattleAnimArgs[4] - 64);
            gTasks[taskId].data[2] = var;
        }
        else
        {
            u16 var = GetBattlerSpriteSubpriority(gBattleAnimTarget) - gBattleAnimArgs[4];
            gTasks[taskId].data[2] = var;
        }
    }
    else
    {
        if (gBattleAnimArgs[4] >= 64)
        {
            u16 var = GetBattlerSpriteSubpriority(gBattleAnimTarget) + (gBattleAnimArgs[4] - 64);
            gTasks[taskId].data[2] = var;
        }
        else
        {
            u16 var = GetBattlerSpriteSubpriority(gBattleAnimTarget) - gBattleAnimArgs[4];
            gTasks[taskId].data[2] = var;
        }
    }

    if (gTasks[taskId].data[2] < 3)
        gTasks[taskId].data[2] = 3;

    gTasks[taskId].func = AirCutterProjectileStep1;
}

static void AnimVoidLines(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->data[0] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(sVoidLinesSpriteTemplate.paletteTag));
    sprite->callback = AnimVoidLines_Step;
}

static void AnimVoidLines_Step(struct Sprite *sprite)
{
    u16 id, val;
    int i;

    if (++sprite->data[1] == 2)
    {
        sprite->data[1] = 0;
        id = sprite->data[0];
        val = gPlttBufferFaded[8 + id];
        for (i = 8; i < 16; i++)
            gPlttBufferFaded[i + id] = gPlttBufferFaded[i + id + 1];

        gPlttBufferFaded[id + 15] = val;

        if (++sprite->data[2] == 24)
            DestroyAnimSprite(sprite);
    }
}

static void AnimCoinThrow(struct Sprite *sprite)
{
    s16 r6;
    s16 r7;
    u16 var;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    r6 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    r7 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    r6 += gBattleAnimArgs[2];
    var = ArcTan2Neg(r6 - sprite->x, r7 - sprite->y);
    var += 0xC000;
    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, var);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = r6;
    sprite->data[4] = r7;
    sprite->callback = InitAnimLinearTranslationWithSpeedAndPos;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimFallingCoin(struct Sprite *sprite)
{
    sprite->data[2] = -16;
    sprite->y += 8;
    sprite->callback = AnimFallingCoin_Step;
}

static void AnimFallingCoin_Step(struct Sprite *sprite)
{
    sprite->data[0] += 0x80;
    sprite->x2 = sprite->data[0] >> 8;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        sprite->x2 = -sprite->x2;

    sprite->y2 = Sin(sprite->data[1], sprite->data[2]);
    sprite->data[1] += 5;
    if (sprite->data[1] > 126)
    {
        sprite->data[1] = 0;
        sprite->data[2] /= 2;
        if (++sprite->data[3] == 2)
            DestroyAnimSprite(sprite);
    }
}

static void AnimBulletSeed(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 20;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = StartAnimLinearTranslation;
    sprite->affineAnimPaused = 1;
    StoreSpriteCallbackInData6(sprite, AnimBulletSeed_Step1);
}

static void AnimBulletSeed_Step1(struct Sprite *sprite)
{
    int i;
    u16 rand;
    s16 *ptr;
    PlaySE12WithPanning(SE_M_HORN_ATTACK, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->y2 = 0;
    sprite->x2 = 0;
    ptr = &sprite->data[7];
    for (i = 0; i < 8; i++)
        ptr[i - 7] = 0;

    rand = Random2();
    sprite->data[6] = 0xFFF4 - (rand & 7);
    rand = Random2();
    sprite->data[7] = (rand % 0xA0) + 0xA0;
    sprite->callback = AnimBulletSeed_Step2;
    sprite->affineAnimPaused = 0;
}

static void AnimBulletSeed_Step2(struct Sprite *sprite)
{
    sprite->data[0] += sprite->data[7];
    sprite->x2 = sprite->data[0] >> 8;
    if (sprite->data[7] & 1)
        sprite->x2 = -sprite->x2;

    sprite->y2 = Sin(sprite->data[1], sprite->data[6]);
    sprite->data[1] += 8;
    if (sprite->data[1] > 126)
    {
        sprite->data[1] = 0;
        sprite->data[2] /= 2;
        if (++sprite->data[3] == 1)
            DestroyAnimSprite(sprite);
    }
}

// Moves a tornado in a circlular motion.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: wave amplitude
// arg 3: unused
// arg 4: initial wave offset
// arg 5: wave period (higher means faster wave)
// arg 6: duration
static void AnimRazorWindTornado(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        sprite->y += 16;

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gBattleAnimArgs[2];
    sprite->data[2] = gBattleAnimArgs[5];
    sprite->data[3] = gBattleAnimArgs[6];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = TranslateSpriteInCircle;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback(sprite);
}

// Animates a single pincer line that extends towards the center of the target mon.
// arg 0: invert
static void AnimViceGripPincer(struct Sprite *sprite)
{
    s16 startXOffset = 32;
    s16 startYOffset = -32;
    s16 endXOffset = 16;
    s16 endYOffset = -16;
    if (gBattleAnimArgs[0])
    {
        startXOffset = -32;
        startYOffset = 32;
        endXOffset = -16;
        endYOffset = 16;
        StartSpriteAnim(sprite, 1);
    }

    sprite->x += startXOffset;
    sprite->y += startYOffset;
    sprite->data[0] = 6;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + endXOffset;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + endYOffset;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, AnimViceGripPincer_Step);
}

static void AnimViceGripPincer_Step(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

// Animates a single pincer line that extends towards the center of the target mon, and then back out.
// arg 0: animation id
static void AnimGuillotinePincer(struct Sprite *sprite)
{
    s16 startXOffset = 32;
    s16 startYOffset = -32;
    s16 endXOffset = 16;
    s16 endYOffset = -16;
    if (gBattleAnimArgs[0])
    {
        startXOffset = -32;
        startYOffset = 32;
        endXOffset = -16;
        endYOffset = 16;
        StartSpriteAnim(sprite, gBattleAnimArgs[0]);
    }

    sprite->x += startXOffset;
    sprite->y += startYOffset;
    sprite->data[0] = 6;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + endXOffset;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + endYOffset;
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = gBattleAnimArgs[0];
    sprite->data[6] = sprite->data[0];
    sprite->callback = AnimGuillotinePincer_Step1;
}

static void AnimGuillotinePincer_Step1(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite) && sprite->animEnded)
    {
        SeekSpriteAnim(sprite, 0);
        sprite->animPaused = 1;
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 2;
        sprite->y2 = -2;
        sprite->data[0] = sprite->data[6];
        sprite->data[1] ^= 1;
        sprite->data[2] ^= 1;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
        sprite->callback = AnimGuillotinePincer_Step2;
    }
}

static void AnimGuillotinePincer_Step2(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->x2 = -sprite->x2;
        sprite->y2 = -sprite->y2;
    }

    sprite->data[3] ^= 1;
    if (++sprite->data[4] == 51)
    {
        sprite->y2 = 0;
        sprite->x2 = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
        sprite->animPaused = 0;
        StartSpriteAnim(sprite, sprite->data[5] ^ 1);
        sprite->callback = AnimGuillotinePincer_Step3;
    }
}

static void AnimGuillotinePincer_Step3(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
}

// Scales up the target mon sprite, and sets the palette to grayscale.
// Used in MOVE_DISABLE.
// No args.
void AnimTask_GrowAndGrayscale(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
    SetSpriteRotScale(spriteId, 0xD0, 0xD0, 0);
    SetGrayscaleOrOriginalPalette(gSprites[spriteId].oam.paletteNum + 16, FALSE);
    gTasks[taskId].data[0] = 80;
    gTasks[taskId].func = AnimTask_GrowAndGrayscale_Step;
}

static void AnimTask_GrowAndGrayscale_Step(u8 taskId)
{
    if (--gTasks[taskId].data[0] == -1)
    {
        u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        ResetSpriteRotScale(spriteId);
        SetGrayscaleOrOriginalPalette(gSprites[spriteId].oam.paletteNum + 16, TRUE);
        DestroyAnimVisualTask(taskId);
    }
}

// Shrinks and grows the attacking mon several times. Also creates transparent versions of the
// mon's sprite while it is shrinking.
// No args.
void AnimTask_Minimize(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[0] = spriteId;
    PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[4] = 0x100;
    task->data[5] = 0;
    task->data[6] = 0;
    task->data[7] = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    task->func = AnimTask_Minimize_Step;
}

static void AnimTask_Minimize_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[1])
    {
    case 0:
        if (task->data[2] == 0 || task->data[2] == 3 || task->data[2] == 6)
            CreateMinimizeSprite(task, taskId);
        task->data[2]++;
        task->data[4] += 0x28;
        SetSpriteRotScale(task->data[0], task->data[4], task->data[4], 0);
        SetBattlerSpriteYOffsetFromYScale(task->data[0]);
        if (task->data[2] == 32)
        {
            task->data[5]++;
            task->data[1]++;
        }
        break;
    case 1:
        if (task->data[6] == 0)
        {
            if (task->data[5] == 3)
            {
                task->data[2] = 0;
                task->data[1] = 3;
            }
            else
            {
                task->data[2] = 0;
                task->data[3] = 0;
                task->data[4] = 0x100;
                SetSpriteRotScale(task->data[0], task->data[4], task->data[4], 0);
                SetBattlerSpriteYOffsetFromYScale(task->data[0]);
                task->data[1] = 2;
            }
        }
        break;
    case 2:
        task->data[1] = 0;
        break;
    case 3:
        if (++task->data[2] > 32)
        {
            task->data[2] = 0;
            task->data[1]++;
        }
        break;
    case 4:
        task->data[2] += 2;
        task->data[4] -= 0x50;
        SetSpriteRotScale(task->data[0], task->data[4], task->data[4], 0);
        SetBattlerSpriteYOffsetFromYScale(task->data[0]);
        if (task->data[2] == 32)
        {
            task->data[2] = 0;
            task->data[1]++;
        }
        break;
    case 5:
        ResetSpriteRotScale(task->data[0]);
        gSprites[task->data[15]].y2 = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateMinimizeSprite(struct Task *task, u8 taskId)
{
    u16 matrixNum;
    s16 spriteId = CloneBattlerSpriteWithBlend(ANIM_ATTACKER);
    if (spriteId >= 0)
    {
        if ((matrixNum = AllocOamMatrix()) == 0xFF)
        {
            DestroySpriteWithActiveSheet(&gSprites[spriteId]);
        }
        else
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            gSprites[spriteId].affineAnimPaused = TRUE;
            gSprites[spriteId].oam.matrixNum = matrixNum;
            gSprites[spriteId].subpriority = task->data[7] - task->data[3];
            task->data[3]++;
            task->data[6]++;
            gSprites[spriteId].data[0] = 16;
            gSprites[spriteId].data[1] = taskId;
            gSprites[spriteId].data[2] = 6;
            gSprites[spriteId].callback = ClonedMinizeSprite_Step;
            SetSpriteRotScale(spriteId, task->data[4], task->data[4], 0);
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        }
    }
}

static void ClonedMinizeSprite_Step(struct Sprite *sprite)
{
    if (--sprite->data[0] == 0)
    {
        gTasks[sprite->data[1]].data[sprite->data[2]]--;
        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySpriteWithActiveSheet(sprite);
    }
}

// Task to facilitate expanding and hopping effect seen in Splash.
// arg 0: anim battler
// arg 1: num hops
void AnimTask_Splash(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (gBattleAnimArgs[1] == 0)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        u8 spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        task->data[0] = spriteId;
        task->data[1] = 0;
        task->data[2] = gBattleAnimArgs[1];
        task->data[3] = 0;
        task->data[4] = 0;
        PrepareAffineAnimInTaskData(task, spriteId, gSplashEffectAffineAnimCmds);
        task->func = AnimTask_Splash_Step;
    }
}

static void AnimTask_Splash_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[1])
    {
    case 0:
        RunAffineAnimFromTaskData(task);
        task->data[4] += 3;
        gSprites[task->data[0]].y2 += task->data[4];
        if (++task->data[3] > 7)
        {
            task->data[3] = 0;
            task->data[1]++;
        }
        break;
    case 1:
        RunAffineAnimFromTaskData(task);
        gSprites[task->data[0]].y2 += task->data[4];
        if (++task->data[3] > 7)
        {
            task->data[3] = 0;
            task->data[1]++;
        }
        break;
    case 2:
        if (task->data[4] != 0)
        {
            gSprites[task->data[0]].y2 -= 2;
            task->data[4] -= 2;
        }
        else
            task->data[1]++;
        break;
    case 3:
        if (!RunAffineAnimFromTaskData(task))
        {
            if (--task->data[2] == 0)
            {
                gSprites[task->data[0]].y2 = 0;
                DestroyAnimVisualTask(taskId);
            }
            else
            {
                PrepareAffineAnimInTaskData(task, task->data[0], gSplashEffectAffineAnimCmds);
                task->data[1] = 0;
            }
        }
        break;
    }
}

// Grows, pauses, then shrinks the attacking mon.
// Used by MOVE_SWAGGER and MOVE_BULK_UP
// No args.
void AnimTask_GrowAndShrink(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    PrepareAffineAnimInTaskData(task, spriteId, gGrowAndShrinkAffineAnimCmds);
    task->func = AnimTask_GrowAndShrink_Step;
}

static void AnimTask_GrowAndShrink_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!RunAffineAnimFromTaskData(task))
        DestroyAnimVisualTask(taskId);
}

// Shrinks, pauses, then grows the attacking mon.
// No args.
void AnimTask_ShrinkAndGrow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    PrepareAffineAnimInTaskData(task, spriteId, gShrinkAndGrowAffineAnimCmds);
    task->func = AnimTask_GrowAndShrink_Step;
}

// Animates a little puff of the mon's breath.
// Used by MOVE_SWAGGER and MOVE_BULK_UP
// No args.
static void AnimBreathPuff(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        StartSpriteAnim(sprite, 0);
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + 32;
        sprite->data[1] = 64;
    }
    else
    {
        StartSpriteAnim(sprite, 1);
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) - 32;
        sprite->data[1] = -64;
    }

    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = 52;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearFixedPoint;
}

// Animates an "angry" mark above a mon's head.
// arg 0: target mon (0 = attacker, 1 = target)
// arg 1: x pixel offset
// arg 2: y pixel offset
void AnimAngerMark(struct Sprite *sprite)
{
    u8 battler;
    if (!gBattleAnimArgs[0])
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        gBattleAnimArgs[1] *= -1;

    sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    if (sprite->y < 8)
        sprite->y = 8;

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

// left/right movements
void AnimTask_ThrashMoveMonHorizontal(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[0] = spriteId;
    task->data[1] = 0;
    PrepareAffineAnimInTaskData(task, spriteId, gThrashMoveMonAffineAnimCmds);
    task->func = AnimTask_ThrashMoveMonHorizontal_Step;
}

static void AnimTask_ThrashMoveMonHorizontal_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!RunAffineAnimFromTaskData(task))
        DestroyAnimVisualTask(taskId);
}

// up/down movements
void AnimTask_ThrashMoveMonVertical(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[1] = 0;
    task->data[2] = 4;
    task->data[3] = 7;
    task->data[4] = 3;
    task->data[5] = gSprites[task->data[0]].x;
    task->data[6] = gSprites[task->data[0]].y;
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[9] = 2;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        task->data[2] *= -1;

    task->func = AnimTask_ThrashMoveMonVertical_Step;
}

static void AnimTask_ThrashMoveMonVertical_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (++task->data[7] > 2)
    {
        task->data[7] = 0;
        task->data[8]++;
        if (task->data[8] & 1)
            gSprites[task->data[0]].y += task->data[9];
        else
            gSprites[task->data[0]].y -= task->data[9];
    }
    switch (task->data[1])
    {
    case 0:
        gSprites[task->data[0]].x += task->data[2];
        if (--task->data[3] == 0)
        {
            task->data[3] = 14;
            task->data[1] = 1;
        }
        break;
    case 1:
        gSprites[task->data[0]].x -= task->data[2];
        if (--task->data[3] == 0)
        {
            task->data[3] = 7;
            task->data[1] = 2;
        }
        break;
    case 2:
        gSprites[task->data[0]].x += task->data[2];
        if (--task->data[3] == 0)
        {
            if (--task->data[4] != 0)
            {
                task->data[3] = 7;
                task->data[1] = 0;
            }
            else
            {
                if ((task->data[8] & 1) != 0)
                    gSprites[task->data[0]].y -= task->data[9];

                DestroyAnimVisualTask(taskId);
            }
        }
        break;
    }
}

void AnimTask_SketchDrawMon(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ScanlineEffectParams params;

    s16 i;
    task->data[0] = GetBattlerYCoordWithElevation(gBattleAnimTarget) + 32;
    task->data[1] = 4;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[4] = 0;
    task->data[5] = 0;
    task->data[15] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT);

    if (GetBattlerSpriteBGPriorityRank(gBattleAnimTarget) == 1)
    {
        task->data[6] = gBattle_BG1_X;
        params.dmaDest = &REG_BG1HOFS;
    }
    else
    {
        task->data[6] = gBattle_BG2_X;
        params.dmaDest = &REG_BG2HOFS;
    }

    for (i = task->data[0] - 0x40; i <= task->data[0]; i++)
    {
        if (i >= 0)
        {
            gScanlineEffectRegBuffers[0][i] = task->data[6] + 0xF0;
            gScanlineEffectRegBuffers[1][i] = task->data[6] + 0xF0;
        }
    }

    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.initState = 1;
    params.unused9 = 0;
    ScanlineEffect_SetParams(params);
    task->func = AnimTask_SketchDrawMon_Step;
}

static void AnimTask_SketchDrawMon_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[4])
    {
    case 0:
        if (++task->data[5] > 20)
            task->data[4]++;
        break;
    case 1:
        if (++task->data[1] > 3)
        {
            task->data[1] = 0;
            task->data[2] = task->data[3] & 3;
            task->data[5] = task->data[0] - task->data[3];
            switch (task->data[2])
            {
            case 0:
                break;
            case 1:
                task->data[5] -= 2;
                break;
            case 2:
                task->data[5] += 1;
                break;
            case 3:
                task->data[5] += 1;
                break;
            }

            if (task->data[5] >= 0)
            {
                gScanlineEffectRegBuffers[0][task->data[5]] = task->data[6];
                gScanlineEffectRegBuffers[1][task->data[5]] = task->data[6];
            }

            if (++task->data[3] >= task->data[15])
            {
                gScanlineEffect.state = 3;
                DestroyAnimVisualTask(taskId);
            }
        }
        break;
    }
}

static void AnimPencil(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) - 16;
    sprite->y = GetBattlerYCoordWithElevation(gBattleAnimTarget) + 16;
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 16;
    sprite->data[4] = 0;
    sprite->data[5] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT) + 2;
    sprite->data[6] = BattleAnimAdjustPanning(SOUND_PAN_TARGET);
    sprite->callback = AnimPencil_Step;
}

static void AnimPencil_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] > 1)
        {
            sprite->data[2] = 0;
            sprite->invisible = !sprite->invisible;
        }
        if (++sprite->data[1] > 16)
        {
            sprite->invisible = FALSE;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 3 && sprite->data[2] < sprite->data[5])
        {
            sprite->data[1] = 0;
            sprite->y -= 1;
            sprite->data[2]++;
            if (sprite->data[2] % 10 == 0)
                PlaySE12WithPanning(SE_M_SKETCH, sprite->data[6]);
        }
        sprite->data[4] += sprite->data[3];
        if (sprite->data[4] > 31)
        {
            sprite->data[4] = 0x40 - sprite->data[4];
            sprite->data[3] *= -1;
        }
        else if (sprite->data[4] <= -32)
        {
            sprite->data[4] = -0x40 - sprite->data[4];
            sprite->data[3] *= -1;
        }
        sprite->x2 = sprite->data[4];
        if (sprite->data[5] == sprite->data[2])
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        if (++sprite->data[2] > 1)
        {
            sprite->data[2] = 0;
            sprite->invisible = !sprite->invisible;
        }
        if (++sprite->data[1] > 16)
        {
            sprite->invisible = FALSE;
            DestroyAnimSprite(sprite);
        }
        break;
    }
}

static void AnimBlendThinRing(struct Sprite *sprite)
{
    u8 battler = 0;
    s16 x = 0;
    s16 y = 0;
    u8 r4;

    if (gBattleAnimArgs[2] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    r4 = gBattleAnimArgs[3] ^ 1;
    if (IsDoubleBattle() && IsBattlerSpriteVisible(BATTLE_PARTNER(battler)))
    {
        SetAverageBattlerPositions(battler, r4, &x, &y);
        if (r4 == 0)
            r4 = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
        else
            r4 = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            gBattleAnimArgs[0] -= (x - r4) - gBattleAnimArgs[0];  // This is weird.
        else
            gBattleAnimArgs[0] = x - r4;
    }

    sprite->callback = AnimSpriteOnMonPos;
    sprite->callback(sprite);
}

static void AnimHyperVoiceRing_WaitEnd(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        FreeSpriteOamMatrix(sprite);
        DestroyAnimSprite(sprite);
    }
}

void AnimHyperVoiceRing(struct Sprite *sprite)
{
    u16 startX = 0;
    u16 startY = 0;
    s16 x = 0;
    s16 y = 0;
    u8 yCoordType;
    u8 battler1;
    u8 battler2;
    u8 xCoordType;

    if (gBattleAnimArgs[5] == 0)
    {
        battler1 = gBattleAnimAttacker;
        battler2 = gBattleAnimTarget;
    }
    else
    {
        battler1 = gBattleAnimTarget;
        battler2 = gBattleAnimAttacker;
    }

    if (!gBattleAnimArgs[6])
    {
        xCoordType = BATTLER_COORD_X;
        yCoordType = BATTLER_COORD_Y;
    }
    else
    {
        xCoordType = BATTLER_COORD_X_2;
        yCoordType = BATTLER_COORD_Y_PIC_OFFSET;
    }

    if (GetBattlerSide(battler1) != B_SIDE_PLAYER)
    {
        startX = GetBattlerSpriteCoord(battler1, xCoordType) + gBattleAnimArgs[0];
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(battler2)))
            sprite->subpriority = gSprites[gBattlerSpriteIds[BATTLE_PARTNER(battler2)]].subpriority - 1;
        else
            sprite->subpriority = gSprites[gBattlerSpriteIds[battler2]].subpriority - 1;
    }
    else
    {
        startX = GetBattlerSpriteCoord(battler1, xCoordType) - gBattleAnimArgs[0];
        if (!IsContest() && IsBattlerSpriteVisible(BATTLE_PARTNER(battler1)))
        {
            if (gSprites[gBattlerSpriteIds[battler1]].x < gSprites[gBattlerSpriteIds[BATTLE_PARTNER(battler1)]].x)
                sprite->subpriority = gSprites[gBattlerSpriteIds[BATTLE_PARTNER(battler1)]].subpriority + 1;
            else
                sprite->subpriority = gSprites[gBattlerSpriteIds[battler1]].subpriority - 1;
        }
        else
        {
            sprite->subpriority = gSprites[gBattlerSpriteIds[battler1]].subpriority - 1;
        }

    }

    startY = GetBattlerSpriteCoord(battler1, yCoordType) + gBattleAnimArgs[1];
    if (!IsContest() && IsBattlerSpriteVisible(BATTLE_PARTNER(battler2)))
    {
        SetAverageBattlerPositions(battler2, gBattleAnimArgs[6], &x, &y);
    }
    else
    {
        x = GetBattlerSpriteCoord(battler2, xCoordType);
        y = GetBattlerSpriteCoord(battler2, yCoordType);
    }

    if (GetBattlerSide(battler2))
        x += gBattleAnimArgs[3];
    else
        x -= gBattleAnimArgs[3];

    y += gBattleAnimArgs[4];
    sprite->x = sprite->data[1] = startX;
    sprite->y = sprite->data[3] = startY;
    sprite->data[2] = x;
    sprite->data[4] = y;
    sprite->data[0] = gBattleAnimArgs[0];
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimHyperVoiceRing_WaitEnd;
    sprite->callback(sprite);
}

void AnimUproarRing(struct Sprite *sprite)
{
    u8 index = IndexOfSpritePaletteTag(ANIM_TAG_THIN_RING);
    if (index != 0xFF)
    {
        BlendPalette((OBJ_PLTT_ID(index) + 1), 15, gBattleAnimArgs[5], gBattleAnimArgs[4]);
    }

    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = AnimSpriteOnMonPos;
    sprite->callback(sprite);
}

static void AnimSoftBoiledEgg(struct Sprite *sprite)
{
    s16 r1;
    InitSpritePosToAnimAttacker(sprite, FALSE);
    r1 = GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER ? -160 : 160;
    sprite->data[0] = 0x380;
    sprite->data[1] = r1;
    sprite->data[7] = gBattleAnimArgs[2];
    sprite->callback = AnimSoftBoiledEgg_Step1;
}

static void AnimSoftBoiledEgg_Step1(struct Sprite *sprite)
{
    s16 add;
    sprite->y2 -= (sprite->data[0] >> 8);
    sprite->x2 = sprite->data[1] >> 8;
    sprite->data[0] -= 32;
    add = GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER ? -160 : 160;
    sprite->data[1] += add;
    if (sprite->y2 > 0)
    {
        sprite->y += sprite->y2;
        sprite->x += sprite->x2;
        sprite->y2 = 0;
        sprite->x2 = 0;
        sprite->data[0] = 0;
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = AnimSoftBoiledEgg_Step2;
    }
}

static void AnimSoftBoiledEgg_Step2(struct Sprite *sprite)
{
    if (sprite->data[0]++ > 19)
    {
        StartSpriteAffineAnim(sprite, 2);
        sprite->callback = AnimSoftBoiledEgg_Step3;
    }
}

static void AnimSoftBoiledEgg_Step3(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 1);
        sprite->data[0] = 0;
        if (sprite->data[7] == 0)
        {
            sprite->oam.tileNum += 16;
            sprite->callback = AnimSoftBoiledEgg_Step3_Callback1;
        }
        else
        {
            sprite->oam.tileNum += 32;
            sprite->callback = AnimSoftBoiledEgg_Step4;
        }
    }
}

static void AnimSoftBoiledEgg_Step3_Callback1(struct Sprite *sprite)
{
    sprite->y2 -= 2;
    if (++sprite->data[0] == 9)
    {
        sprite->data[0] = 16;
        sprite->data[1] = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND((u16)sprite->data[0], 0));
        sprite->callback = AnimSoftBoiledEgg_Step3_Callback2;
    }
}

static void AnimSoftBoiledEgg_Step3_Callback2(struct Sprite *sprite)
{
    if (sprite->data[1]++ % 3 == 0)
    {
        sprite->data[0]--;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]));
        if (sprite->data[0] == 0)
            sprite->callback = AnimSoftBoiledEgg_Step4;
    }
}

static void AnimSoftBoiledEgg_Step4(struct Sprite *sprite)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->invisible = TRUE;
        if (sprite->data[7] == 0)
            sprite->callback = AnimSoftBoiledEgg_Step4_Callback;
        else
            sprite->callback = DestroyAnimSprite;
    }
}

static void AnimSoftBoiledEgg_Step4_Callback(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

// Used by Extremespeed
void AnimTask_AttackerStretchAndDisappear(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[0] = spriteId;
    PrepareAffineAnimInTaskData(task, spriteId, gStretchAttackerAffineAnimCmds);
    task->func = AnimTask_AttackerStretchAndDisappear_Step;
}

static void AnimTask_AttackerStretchAndDisappear_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!RunAffineAnimFromTaskData(task))
    {
        gSprites[task->data[0]].y2 = 0;
        gSprites[task->data[0]].invisible = TRUE;
        DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_ExtremeSpeedImpact(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[12] = 3;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        task->data[13] = 0xFFFF;
        task->data[14] = 8;
    }
    else
    {
        task->data[13] = 1;
        task->data[14] = -8;
    }

    task->data[15] = GetAnimBattlerSpriteId(ANIM_TARGET);
    task->func = AnimTask_ExtremeSpeedImpact_Step;
}

static void AnimTask_ExtremeSpeedImpact_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gSprites[task->data[15]].x2 += task->data[14];
        task->data[1] = 0;
        task->data[2] = 0;
        task->data[3] = 0;
        task->data[0]++;
        break;
    case 1:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            if (task->data[2] & 1)
                gSprites[task->data[15]].x2 += 6;
            else
                gSprites[task->data[15]].x2 -= 6;

            if (++task->data[3] > 4)
            {
                if (task->data[2] & 1)
                    gSprites[task->data[15]].x2 -= 6;

                task->data[0]++;
            }
        }
        break;
    case 2:
        if (--task->data[12] != 0)
            task->data[0] = 0;
        else
            task->data[0]++;
        break;
    case 3:
        gSprites[task->data[15]].x2 += task->data[13];
        if (gSprites[task->data[15]].x2 == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_ExtremeSpeedMonReappear(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[4] = 1;
    task->data[13] = 14;
    task->data[14] = 2;
    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->func = AnimTask_ExtremeSpeedMonReappear_Step;
}

static void AnimTask_ExtremeSpeedMonReappear_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] == 0 && ++task->data[1] > task->data[4])
    {
        task->data[1] = 0;
        if (++task->data[2] & 1)
            gSprites[task->data[15]].invisible = FALSE;
        else
            gSprites[task->data[15]].invisible = TRUE;

        if (++task->data[3] >= task->data[13])
        {
            if (++task->data[4] < task->data[14])
            {
                task->data[1] = 0;
                task->data[2] = 0;
                task->data[3] = 0;
            }
            else
            {
                gSprites[task->data[15]].invisible = FALSE;
                DestroyAnimVisualTask(taskId);
            }
        }
    }
}

void AnimTask_SpeedDust(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[1] = 4;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[4] = 0;
    task->data[5] = 0;
    task->data[6] = 0;
    task->data[7] = 0;
    task->data[8] = 0;
    task->data[13] = 0;
    task->data[14] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    task->data[15] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    task->func = AnimTask_SpeedDust_Step;
}

static void AnimTask_SpeedDust_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[8])
    {
    case 0:
        if (++task->data[4] > 1)
        {
            task->data[4] = 0;
            task->data[5] = (task->data[5] + 1) & 1;
            if (++task->data[6] > 20)
            {
                if (task->data[7] == 0)
                {
                    task->data[6] = 0;
                    task->data[8] = 1;
                }
                else
                    task->data[8] = 2;
            }
        }
        break;
    case 1:
        task->data[5] = 0;
        if (++task->data[4] > 20)
        {
            task->data[7] = 1;
            task->data[8] = 0;
        }
        break;
    case 2:
        task->data[5] = 1;
        break;
    }

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 4)
        {
            u8 spriteId;
            task->data[1] = 0;
            spriteId = CreateSprite(&gSpeedDustSpriteTemplate, task->data[14], task->data[15], 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].data[0] = taskId;
                gSprites[spriteId].data[1] = 13;
                gSprites[spriteId].x2 = gSpeedDustPosTable[task->data[2]][0];
                gSprites[spriteId].y2 = gSpeedDustPosTable[task->data[2]][1];
                task->data[13]++;
                if (++task->data[2] > 3)
                {
                    task->data[2] = 0;
                    if (++task->data[3] > 5)
                        task->data[0]++;
                }
            }
        }
        break;
    case 1:
        if (task->data[13] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimSpeedDust(struct Sprite *sprite)
{
    sprite->invisible = gTasks[sprite->data[0]].data[5];
    if (sprite->animEnded)
    {
        gTasks[sprite->data[0]].data[sprite->data[1]]--;
        DestroySprite(sprite);
    }
}

void AnimTask_LoadMusicNotesPals(u8 taskId)
{
    int i;
    u8 paletteNums[NUM_MUSIC_NOTE_PAL_TAGS];

    paletteNums[0] = IndexOfSpritePaletteTag(ANIM_TAG_MUSIC_NOTES_2);
    for (i = 1; i < NUM_MUSIC_NOTE_PAL_TAGS; i++)
        paletteNums[i] = AllocSpritePalette(ANIM_SPRITES_START - i);

    gMonSpritesGfxPtr->buffer = AllocZeroed(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    LZDecompressWram(gBattleAnimSpritePal_MusicNotes2, gMonSpritesGfxPtr->buffer);
    for (i = 0; i < NUM_MUSIC_NOTE_PAL_TAGS; i++)
        LoadPalette(&gMonSpritesGfxPtr->buffer[i * 32], (u16)(OBJ_PLTT_ID(paletteNums[i])), PLTT_SIZE_4BPP);

    FREE_AND_SET_NULL(gMonSpritesGfxPtr->buffer);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreeMusicNotesPals(u8 taskId)
{
    int i;
    for (i = 0; i < NUM_MUSIC_NOTE_PAL_TAGS; i++)
        FreeSpritePaletteByTag(sMusicNotePaletteTagsTable[i]);

    DestroyAnimVisualTask(taskId);
}

static void SetMusicNotePalette(struct Sprite *sprite, u8 a, u8 b)
{
    u8 tile = (b & 1) ? 32 : 0;
    sprite->oam.tileNum += tile + (a << 2);
    sprite->oam.paletteNum = IndexOfSpritePaletteTag(sMusicNotePaletteTagsTable[b >> 1]);
}

static void AnimHealBellMusicNote(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    SetMusicNotePalette(sprite, gBattleAnimArgs[5], gBattleAnimArgs[6]);
}

void AnimMagentaHeart(struct Sprite *sprite)
{
    if (++sprite->data[0] == 1)
        InitSpritePosToAnimAttacker(sprite, FALSE);

    sprite->x2 = Sin(sprite->data[1], 8);
    sprite->y2 = sprite->data[2] >> 8;
    sprite->data[1] = (sprite->data[1] + 7) & 0xFF;
    sprite->data[2] -= 0x80;
    if (sprite->data[0] == 60)
        DestroyAnimSprite(sprite);
}

void AnimTask_FakeOut(u8 taskId)
{
    u16 win0h = IsContest() ? 152 : DISPLAY_WIDTH;
    u16 win0v = 0;

    gBattle_WIN0H = win0h;
    gBattle_WIN0V = DISPLAY_HEIGHT;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL | WINOUT_WINOBJ_ALL);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 16);
    gTasks[taskId].data[0] = win0v;
    gTasks[taskId].data[1] = win0h;
    gTasks[taskId].func = AnimTask_FakeOut_Step1;
}

static void AnimTask_FakeOut_Step1(u8 taskId)
{
    gTasks[taskId].data[0] += 13;
    gTasks[taskId].data[1] -= 13;
    if (gTasks[taskId].data[0] >= gTasks[taskId].data[1])
    {
        gBattle_WIN0H = 0;
        gTasks[taskId].func = AnimTask_FakeOut_Step2;
    }
    else
    {
        gBattle_WIN0H = WIN_RANGE(gTasks[taskId].data[0], gTasks[taskId].data[1]);
    }
}

static void AnimTask_FakeOut_Step2(u8 taskId)
{
    if (++gTasks[taskId].data[10] == 5)
    {
        gTasks[taskId].data[11] = 0x88;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_LIGHTEN);
        BlendPalettes(GetBattlePalettesMask(TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE), 16, RGB_WHITE);
    }
    else if (gTasks[taskId].data[10] > 4)
    {
        gBattle_WIN0H = 0;
        gBattle_WIN0V = 0;
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_StretchTargetUp(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    if (++gTasks[taskId].data[0] == 1)
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_TARGET), sAffineAnims_StretchBattlerUp);
        gSprites[spriteId].x2 = 4;
    }
    else
    {
        gSprites[spriteId].x2 = -gSprites[spriteId].x2;
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        {
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
}

void AnimTask_StretchAttackerUp(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (++gTasks[taskId].data[0] == 1)
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), sAffineAnims_StretchBattlerUp);
        gSprites[spriteId].x2 = 4;
    }
    else
    {
        gSprites[spriteId].x2 = -gSprites[spriteId].x2;
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        {
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
}

static void AnimRedHeartProjectile(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 95;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    sprite->callback = AnimRedHeartProjectile_Step;
}

static void AnimRedHeartProjectile_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->y2 += Sin(sprite->data[5], 14);
        sprite->data[5] = (sprite->data[5] + 4) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

void AnimParticleBurst(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[1] = gBattleAnimArgs[0];
        sprite->data[2] = gBattleAnimArgs[1];
        sprite->data[0]++;
    }
    else
    {
        sprite->data[4] += sprite->data[1];
        sprite->x2 = sprite->data[4] >> 8;
        sprite->y2 = Sin(sprite->data[3], sprite->data[2]);
        sprite->data[3] = (sprite->data[3] + 3) & 0xFF;
        if (sprite->data[3] > 100)
            sprite->invisible = sprite->data[3] % 2;

        if (sprite->data[3] > 120)
            DestroyAnimSprite(sprite);
    }
}

static void AnimRedHeartRising(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = DISPLAY_HEIGHT;
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimRedHeartRising_Step);
}

static void AnimRedHeartRising_Step(struct Sprite *sprite)
{
    s16 y;
    sprite->data[2] += sprite->data[1];
    sprite->y2 = -((u16)sprite->data[2] >> 8);
    sprite->x2 = Sin(sprite->data[3], 4);
    sprite->data[3] = (sprite->data[3] + 3) & 0xFF;
    y = sprite->y + sprite->y2;
    if (y <= 72)
    {
        sprite->invisible = sprite->data[3] % 2;
        if (y <= 64)
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_HeartsBackground(u8 taskId)
{
    struct BattleAnimBgData animBg;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 3);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
    if (!IsContest())
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    GetBattleAnimBg1Data(&animBg);
    AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimBgImage_Attract, animBg.tilesOffset);
    AnimLoadCompressedBgTilemapHandleContest(&animBg, gBattleAnimBgTilemap_Attract, FALSE);
    LoadCompressedPalette(gBattleAnimBgPalette_Attract, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
    gTasks[taskId].func = AnimTask_HeartsBackground_Step;
}

static void AnimTask_HeartsBackground_Step(u8 taskId)
{
    struct BattleAnimBgData animBg;

    switch (gTasks[taskId].data[12])
    {
    case 0:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 16)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 1:
        if (++gTasks[taskId].data[11] == 141)
        {
            gTasks[taskId].data[11] = 16;
            gTasks[taskId].data[12]++;
        }
        break;
    case 2:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 0)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 3:
        GetBattleAnimBg1Data(&animBg);
        ClearBattleAnimBg(animBg.bgId);
        gTasks[taskId].data[12]++;
        break;
    case 4:
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_ScaryFace(u8 taskId)
{
    struct BattleAnimBgData animBg;
    bool32 onPlayer;

    if (gAnimMoveIndex == MOVE_BITTER_MALICE)
        onPlayer = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER;
    else
        onPlayer = GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND);
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
    if (IsContest())
        AnimLoadCompressedBgTilemapHandleContest(&animBg, &gBattleAnimBgTilemap_ScaryFaceContest, FALSE);
    else if (onPlayer)
        AnimLoadCompressedBgTilemapHandleContest(&animBg, &gBattleAnimBgTilemap_ScaryFacePlayer, FALSE);
    else
        AnimLoadCompressedBgTilemapHandleContest(&animBg, &gBattleAnimBgTilemap_ScaryFaceOpponent, FALSE);

    AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimBgImage_ScaryFace, animBg.tilesOffset);
    LoadCompressedPalette(gBattleAnimBgPalette_ScaryFace, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
    gTasks[taskId].func = AnimTask_ScaryFace_Step;
}

static void AnimTask_ScaryFace_Step(u8 taskId)
{
    struct BattleAnimBgData animBg;

    switch (gTasks[taskId].data[12])
    {
    case 0:
        if (++gTasks[taskId].data[10] == 2)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 14)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 1:
        if (++gTasks[taskId].data[11] == 21)
        {
            gTasks[taskId].data[11] = 14;
            gTasks[taskId].data[12]++;
        }
        break;
    case 2:
        if (++gTasks[taskId].data[10] == 2)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 0)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 3:
        GetBattleAnimBg1Data(&animBg);
        ClearBattleAnimBg(1);
        ClearBattleAnimBg(2);
        gTasks[taskId].data[12]++;
        // fall through
    case 4:
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Orbits a sphere in an ellipse around the mon.
// Used by MOVE_HIDDEN_POWER
// arg 0: duration
// arg 1: initial wave offset
void AnimOrbitFast(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[7] = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    sprite->callback = AnimOrbitFast_Step;
    sprite->callback(sprite);
}

static void AnimOrbitFast_Step(struct Sprite *sprite)
{
    if (sprite->data[1] >= 64 && sprite->data[1] <= 191)
        sprite->subpriority = sprite->data[7] + 1;
    else
        sprite->subpriority = sprite->data[7] - 1;

    sprite->x2 = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->y2 = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;
    switch (sprite->data[5])
    {
    case 1:
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[5] = 2;
            return;
        }
        break;
    case 0:
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        if (++sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
        break;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyAnimSprite(sprite);
}

// Moves orbs away from the mon, based on where they are in their orbit.
// Used in MOVE_HIDDEN_POWER.
// arg 0: initial wave offset
void AnimOrbitScatter(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->callback = AnimOrbitScatter_Step;
}

static void AnimOrbitScatter_Step(struct Sprite *sprite)
{
    sprite->x2 += sprite->data[0];
    sprite->y2 += sprite->data[1];
    if (sprite->x + sprite->x2 + 16 > ((u32)DISPLAY_WIDTH + 32)
     || sprite->y + sprite->y2 > DISPLAY_HEIGHT || sprite->y + sprite->y2 < -16)
        DestroyAnimSprite(sprite);
}

static void AnimSpitUpOrb_Step(struct Sprite *sprite)
{
    sprite->x2 += sprite->data[0];
    sprite->y2 += sprite->data[1];
    if (sprite->data[3]++ >= sprite->data[2])
        DestroyAnimSprite(sprite);
}

static void AnimSpitUpOrb(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = Sin(gBattleAnimArgs[0], 10);
    sprite->data[1] = Cos(gBattleAnimArgs[0], 7);
    sprite->data[2] = gBattleAnimArgs[1];
    sprite->callback = AnimSpitUpOrb_Step;
}

static void AnimEyeSparkle_Step(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimEyeSparkle(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->callback = AnimEyeSparkle_Step;
}

static void AnimAngel(struct Sprite *sprite)
{
    s16 var0;
    if (!sprite->data[0])
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->data[0]++;
    var0 = (sprite->data[0] * 10) & 0xFF;
    sprite->x2 = Sin(var0, 80) >> 8;
    if (sprite->data[0] < 80)
        sprite->y2 = (sprite->data[0] / 2) + (Cos(var0, 80) >> 8);

    if (sprite->data[0] > 90)
    {
        sprite->data[2]++;
        sprite->x2 -= sprite->data[2] / 2;
    }

    if (sprite->data[0] > 100)
        DestroyAnimSprite(sprite);
}

static void AnimPinkHeart_Step(struct Sprite *sprite)
{
    sprite->data[5]++;
    sprite->x2 = Sin(sprite->data[3], 5);
    sprite->y2 = sprite->data[5] / 2;
    sprite->data[3] = (sprite->data[3] + 3) & 0xFF;
    if (sprite->data[5] > 20)
        sprite->invisible = sprite->data[5] % 2;

    if (sprite->data[5] > 30)
        DestroyAnimSprite(sprite);
}

static void AnimPinkHeart(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[1] = gBattleAnimArgs[0];
        sprite->data[2] = gBattleAnimArgs[1];
        sprite->data[0]++;
    }
    else
    {
        sprite->data[4] += sprite->data[1];
        sprite->x2 = sprite->data[4] >> 8;
        sprite->y2 = Sin(sprite->data[3], sprite->data[2]);
        sprite->data[3] = (sprite->data[3] + 3) & 0xFF;
        if (sprite->data[3] > 70)
        {
            sprite->callback = AnimPinkHeart_Step;
            sprite->x += sprite->x2;
            sprite->y += sprite->y2;
            sprite->x2 = 0;
            sprite->y2 = 0;
            sprite->data[3] = Random2() % 180;
        }
    }
}

static void AnimDevil(struct Sprite *sprite)
{
    if (sprite->data[3] == 0)
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        StartSpriteAnim(sprite, 0);
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 1;
        sprite->data[2] = 1;
    }
    sprite->data[0] += sprite->data[2];
    sprite->data[1] = (sprite->data[0] * 4) % 256;
    if (sprite->data[1] < 0)
        sprite->data[1] = 0;
    sprite->x2 = Cos(sprite->data[1], 30 - sprite->data[0] / 4);
    sprite->y2 = Sin(sprite->data[1], 10 - sprite->data[0] / 8);
    if (sprite->data[1] > 128 && sprite->data[2] > 0)
        sprite->data[2] = -1;
    if (sprite->data[1] == 0 && sprite->data[2] < 0)
        sprite->data[2] = 1;
    sprite->data[3]++;
    if (sprite->data[3] < 10 || sprite->data[3] > 80)
        sprite->invisible = sprite->data[0] % 2;
    else
        sprite->invisible = FALSE;
    if (sprite->data[3] > 90)
        DestroyAnimSprite(sprite);
}

static void AnimFurySwipes(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        StartSpriteAnim(sprite, gBattleAnimArgs[2]);
        sprite->data[0]++;
    }
    else if (sprite->animEnded)
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimMovementWaves(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[2])
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        if (!gBattleAnimArgs[0])
        {
            sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        }
        else
        {
            sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        }

        if (!gBattleAnimArgs[1])
            sprite->x += 32;
        else
            sprite->x -= 32;

        sprite->data[0] = gBattleAnimArgs[2];
        sprite->data[1] = gBattleAnimArgs[1];
        StartSpriteAnim(sprite, sprite->data[1]);
        sprite->callback = AnimMovementWaves_Step;
    }
}

static void AnimMovementWaves_Step(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        if (--sprite->data[0])
            StartSpriteAnim(sprite, sprite->data[1]);
        else
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_UproarDistortion(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    PrepareAffineAnimInTaskData(&gTasks[taskId], spriteId, sAffineAnims_UproarDistortion);
    gTasks[taskId].func = AnimTask_UproarDistortion_Step;
}

static void AnimTask_UproarDistortion_Step(u8 taskId)
{
    if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        DestroyAnimVisualTask(taskId);
}

static void AnimJaggedMusicNote(struct Sprite *sprite)
{
    u8 battler = !gBattleAnimArgs[0] ? gBattleAnimAttacker : gBattleAnimTarget;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        gBattleAnimArgs[1] *= -1;

    sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2)  + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    sprite->data[0] = 0;
    sprite->data[1] = (u16)sprite->x << 3;
    sprite->data[2] = (u16)sprite->y << 3;
    sprite->data[3] = (gBattleAnimArgs[1] << 3) / 8;
    sprite->data[4] = (gBattleAnimArgs[2] << 3) / 8;

    sprite->oam.tileNum += gBattleAnimArgs[3] * 16;
    sprite->callback = AnimJaggedMusicNote_Step;
}

static void AnimJaggedMusicNote_Step(struct Sprite *sprite)
{
    sprite->data[1] += sprite->data[3];
    sprite->data[2] += sprite->data[4];
    sprite->x = sprite->data[1] >> 3;
    sprite->y = sprite->data[2] >> 3;
    if (++sprite->data[0] > 16)
        DestroyAnimSprite(sprite);
}

static void AnimPerishSongMusicNote2(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        sprite->data[1] = 120 - gBattleAnimArgs[0];
        sprite->invisible = TRUE;
    }

    if (++sprite->data[0] == sprite->data[1])
        SetGrayscaleOrOriginalPalette(sprite->oam.paletteNum + 16, FALSE);

    if (sprite->data[0] == sprite->data[1] + 80)
        DestroyAnimSprite(sprite);
}

static void AnimPerishSongMusicNote(struct Sprite *sprite)
{
    int index;
    int var2;

    if (!sprite->data[0])
    {
        sprite->x = 120;
        sprite->y = (gBattleAnimArgs[0] + (((u16)gBattleAnimArgs[0]) >> 31)) / 2 - 15;

        StartSpriteAnim(sprite, gBattleAnimArgs[1]);

        sprite->data[5] = 120;
        sprite->data[3] = gBattleAnimArgs[2];
    }

    sprite->data[0]++;

    sprite->data[1] = (sprite->data[0] + ((u16)sprite->data[0] >> 31)) / 2;
    index = ((sprite->data[0] * 3) + (u16)sprite->data[3]);
    var2 = 0xFF;
    sprite->data[6] = (sprite->data[6] + 10) & 0xFF;

    index &= var2;
    sprite->x2 = Cos(index, 100);

    sprite->y2 = sprite->data[1] + Sin(index, 10) + Cos(sprite->data[6], 4);

    if (sprite->data[0] > sprite->data[5])
    {
        sprite->callback = AnimPerishSongMusicNote_Step1;

        sprite->data[0] = 0;
        SetSpritePrimaryCoordsFromSecondaryCoords(sprite);
        sprite->data[2] = 5;
        sprite->data[4] = 0;
        sprite->data[3] = 0;

        StartSpriteAffineAnim(sprite, 1);
    }
}

static void AnimPerishSongMusicNote_Step1(struct Sprite *sprite)
{
    if (++sprite->data[0] > 10)
    {
        sprite->data[0] = 0;
        sprite->callback = AnimPerishSongMusicNote_Step2;
    }
}

static void AnimPerishSongMusicNote_Step2(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[2];
    sprite->y2 = sprite->data[3];

    sprite->data[2]++;

    if (sprite->data[3] > 48 && sprite->data[2] > 0)
    {
        sprite->data[2] = sprite->data[4] - 5;
        sprite->data[4]++;
    }

    if (sprite->data[4] > 3)
    {
        sprite->invisible = sprite->data[2] % 2;
        DestroyAnimSprite(sprite);
    }

    if (sprite->data[4] == 4)
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimGuardRing(struct Sprite *sprite)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
    {
        SetAverageBattlerPositions(gBattleAnimAttacker, FALSE, &sprite->x, &sprite->y);
        sprite->y += 40;

        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 40;
    }

    sprite->data[0] = 13;
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y - 72;

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void AnimTask_IsFuryCutterHitRight(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gAnimDisableStructPtr->furyCutterCounter & 1;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetFuryCutterHitCount(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gAnimDisableStructPtr->furyCutterCounter;
    DestroyAnimVisualTask(taskId);
}
