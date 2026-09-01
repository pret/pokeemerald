#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

#include "battle.h"
#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "task.h"

enum
{
    ANIM_TYPE_GENERAL,
    ANIM_TYPE_MOVE,
    ANIM_TYPE_STATUS,
    ANIM_TYPE_SPECIAL,
};

enum
{
    BG_ANIM_SCREEN_SIZE,
    BG_ANIM_AREA_OVERFLOW_MODE,
    BG_ANIM_MOSAIC,
    BG_ANIM_CHAR_BASE_BLOCK,
    BG_ANIM_PRIORITY,
    BG_ANIM_PALETTES_MODE,
    BG_ANIM_SCREEN_BASE_BLOCK,
};

struct BattleAnimBgData
{
    u8 *bgTiles;
    u16 *bgTilemap;
    u8 paletteId;
    u8 bgId;
    u16 tilesOffset;
    u16 unused;
};

struct BattleAnimBackground
{
    const u32 *image;
    const u16 *palette;
    const u32 *tilemap;
};

struct BattleAnimation
{
    struct CompressedSpriteSheet pic;
    struct SpritePalette palette;
};

// Helper struct for link battles to show correct animations and transformations that can change their look
// Used by EmitBattleAnimation and EmitMoveAnimation
struct LinkBattleAnim
{
    u32 transformedMonPID;
    u8 rolloutTimer;
    u8 furyCutterCounter;
    u8 syrupBombIsShiny:1;
    u8 isTransformedMonShiny:1;
    u8 stockpileCounter:4;
};

#define ANIM_ARGS_COUNT 8
#define MAX_ANIM_CALL_DEPTH 4

extern void (*gAnimScriptCallback)(void);
extern bool8 gAnimScriptActive;
extern u8 gAnimVisualTaskCount;
extern u8 gAnimSoundTaskCount;
extern struct LinkBattleAnim *gAnimDisableStructPtr;
extern s32 gAnimMoveDmg;
extern u16 gAnimMovePower;
extern u8 gAnimFriendship;
extern u16 gWeatherMoveAnim;
extern s16 gBattleAnimArgs[ANIM_ARGS_COUNT];
extern u8 gAnimMoveTurn;
extern enum BattlerId gBattleAnimAttacker;
extern enum BattlerId gBattleAnimTarget;
extern enum Species gAnimBattlerSpecies[MAX_BATTLERS_COUNT];
extern u8 gAnimCustomPanning;
extern u16 gAnimMoveIndex;

void ClearBattleAnimationVars(void);
void DoMoveAnim(enum Move move);
void LaunchBattleAnimation(u32 animType, u32 animId);
void DestroyAnimSprite(struct Sprite *sprite);
void DestroyAnimVisualTask(u8 taskId);
void DestroyAnimSoundTask(u8 taskId);
enum BattlerId GetAnimBattlerId(enum AnimBattler wantedBattler);
bool8 IsBattlerSpriteVisible(enum BattlerId battler);
void MoveBattlerSpriteToBG(enum BattlerId battler, bool8 toBG_2, bool8 setSpriteInvisible);
bool8 IsContest(void);
s8 BattleAnimAdjustPanning(s8 pan);
s8 BattleAnimAdjustPanning2(s8 pan);
s16 KeepPanInRange(s16 panArg, int oldPan);
s16 CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan);
void RelocateBattleBgPal(u16 paletteNum, u16 *dest, u32 offset, bool8 largeScreen);
void ResetBattleAnimBg(bool8 toBG2);
void LoadMoveBg(u16 bgId);

bool32 IsGfxLoaded(u32 tag);
bool32 IsPalLoaded(u32 tag);
bool32 TryLoadGfx(u32 tag);
bool32 TryLoadPal(u32 tag);
bool32 TryLoadSpriteAssets(const struct SpriteTemplate *template);
bool32 StorePalTag(u32 tag);
bool32 StoreGfxTag(u32 tag);

// battle_intro.c
void DrawBattlerOnBg(int bgId, u8 x, u8 y, enum BattlerPosition battlerPosition, u8 paletteId, u8 *tiles, u16 *tilemap, u16 tilesOffset);
void HandleIntroSlide(u8 environment);
void BattleIntroSlide1(u8 taskId);
void BattleIntroSlide2(u8 taskId);
void BattleIntroSlide3(u8 taskId);

// battle_anim_mons.c
void TranslateSpriteInEllipse(struct Sprite *sprite);
void AnimTranslateLinearAndFlicker(struct Sprite *sprite);
void AnimTranslateLinearAndFlicker_Flipped(struct Sprite *sprite);
void AnimWeatherBallUp(struct Sprite *sprite);
void AnimWeatherBallDown(struct Sprite *sprite);
void AnimSpinningSparkle(struct Sprite *sprite);
void SetAverageBattlerPositions(enum BattlerId battler, bool8 respectMonPicOffsets, s16 *x, s16 *y);
void SetToPartnerPositions(enum BattlerId battler, bool8 respectMonPicOffsets, s16 *x, s16 *y);
void DestroySpriteAndMatrix(struct Sprite *sprite);
void TranslateSpriteLinearFixedPoint(struct Sprite *sprite);
void InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets);
void InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets);
bool32 InitSpritePosToAnimBattler(enum AnimBattler animBattlerId, struct Sprite *sprite, bool8 respectMonPicOffsets);
void StartAnimLinearTranslation(struct Sprite *sprite);
void InitAnimArcTranslation(struct Sprite *sprite);
bool8 AnimTranslateLinear(struct Sprite *sprite);
void TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite);
u8 GetBattlerSpriteCoord2(enum BattlerId battler, u8 coordType);
void InitAnimLinearTranslationWithSpeed(struct Sprite *sprite);
u16 ArcTan2Neg(s16 x, s16 y);
void TrySetSpriteRotScale(struct Sprite *sprite, bool8 recalcCenterVector, s16 xScale, s16 yScale, u16 rotation);
void RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite);
void TranslateSpriteLinearAndFlicker(struct Sprite *sprite);
void SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite);
void RunStoredCallbackWhenAnimEnds(struct Sprite *sprite);
void SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 xOffset);
s16 GetBattlerSpriteCoordAttr(enum BattlerId battler, u8 attr);
u8 GetBattlerYCoordWithElevation(enum BattlerId battler);
void WaitAnimForDuration(struct Sprite *sprite);
void AnimTravelDiagonally(struct Sprite *sprite);
void InitAnimLinearTranslation(struct Sprite *sprite);
void AnimTranslateLinear_WithFollowup(struct Sprite *sprite);
u8 GetBattlerSpriteBGPriority(enum BattlerId battler);
void *LoadPointerFromVars(s16 lo, s16 hi);
void StorePointerInVars(s16 *lo, s16 *hi, const void *ptr);
void InitPrioritiesForVisibleBattlers(void);
void GetBattleAnimBg1Data(struct BattleAnimBgData *out);
void GetBattleAnimBgData(struct BattleAnimBgData *out, u32 bgId);
u8 GetBattlerSpriteSubpriority(enum BattlerId battler);
bool8 TranslateAnimHorizontalArc(struct Sprite *sprite);
bool8 TranslateAnimVerticalArc(struct Sprite *sprite);
void TranslateSpriteLinearByIdFixedPoint(struct Sprite *sprite);
void ResetSpriteRotScale(u8 spriteId);
void SetSpriteRotScale(u8 spriteId, s16 xScale, s16 yScale, u16 rotation);
void InitSpriteDataForLinearTranslation(struct Sprite *sprite);
void PrepareBattlerSpriteForRotScale(u8 spriteId, u8 objMode);
void SetBattlerSpriteYOffsetFromRotation(u8 spriteId);
u32 GetBattlePalettesMask(bool8 battleBackground, bool8 attacker, bool8 target, bool8 attackerPartner, bool8 targetPartner, bool8 anim1, bool8 anim2);
u32 GetBattleMonSpritePalettesMask(u8 playerLeft, u8 playerRight, u8 opponentLeft, u8 opponentRight);
s16 CloneBattlerSpriteWithBlend(enum AnimBattler animBattler);
void DestroySpriteWithActiveSheet(struct Sprite *sprite);
u8 CreateInvisibleSpriteCopy(enum BattlerId battler, u8 spriteId, enum Species species);
void AnimLoadCompressedBgTilemapHandleContest(struct BattleAnimBgData *data, const void *src, bool32 largeScreen);
void AnimLoadCompressedBgGfx(u32 bgId, const u32 *src, u32 tilesOffset);
void UpdateAnimBg3ScreenSize(bool8 largeScreenSize);
void TranslateSpriteInGrowingCircle(struct Sprite *sprite);
void SetBattlerSpriteYOffsetFromYScale(u8 spriteId);
void PrepareEruptAnimTaskData(struct Task *task, u8 spriteId, s16 xScaleStart, s16 yScaleStart, s16 xScaleEnd, s16 yScaleEnd, u16 duration);
u8 UpdateEruptAnimTask(struct Task *task);
void DestroyAnimSpriteAndDisableBlend(struct Sprite *sprite);
void AnimLoadCompressedBgTilemap(u32 bgId, const void *src);
void InitAnimFastLinearTranslationWithSpeed(struct Sprite *sprite);
bool8 AnimFastTranslateLinear(struct Sprite *sprite);
void InitAndRunAnimFastLinearTranslation(struct Sprite *sprite);
void TranslateSpriteLinearById(struct Sprite *sprite);
void TranslateSpriteLinear(struct Sprite *sprite);
void AnimSpriteOnMonPos(struct Sprite *sprite);
void InitAnimLinearTranslationWithSpeedAndPos(struct Sprite *sprite);
void TranslateSpriteInCircle(struct Sprite *sprite);
void SetGrayscaleOrOriginalPalette(u16 paletteNum, bool8 restoreOriginalColor);
void PrepareAffineAnimInTaskData(struct Task *task, u8 spriteId, const union AffineAnimCmd *affineAnimCmds);
bool8 RunAffineAnimFromTaskData(struct Task *task);
void AnimThrowProjectile(struct Sprite *sprite);
void GetBgDataForTransform(struct BattleAnimBgData *out, enum BattlerId battler);
u8 CreateAdditionalMonSpriteForMoveAnim(enum Species species, bool32 isBackpic, u8 id, s16 x, s16 y, u8 subpriority, u32 personality, bool32 isShiny, enum BattlerId battler);
void ResetSpriteRotScale_PreserveAffine(struct Sprite *sprite);
void Trade_MoveSelectedMonToTarget(struct Sprite *sprite);
void DestroyAnimVisualTaskAndDisableBlend(u8 taskId);
void DestroySpriteAndFreeResources_(struct Sprite *sprite);
void SetBattlerSpriteYOffsetFromOtherYScale(u8 spriteId, u8 otherSpriteId);
void ConvertPosDataToTranslateLinearData(struct Sprite *sprite);
void InitAnimFastLinearTranslationWithSpeedAndPos(struct Sprite *sprite);
u8 GetGhostSpriteDefault_Y(enum BattlerId battler);

enum
{
    BATTLER_COORD_X,
    BATTLER_COORD_Y,
    BATTLER_COORD_X_2,
    BATTLER_COORD_Y_PIC_OFFSET,
    BATTLER_COORD_Y_PIC_OFFSET_DEFAULT,
};

enum
{
    BATTLER_COORD_ATTR_HEIGHT,
    BATTLER_COORD_ATTR_WIDTH,
    BATTLER_COORD_ATTR_TOP,
    BATTLER_COORD_ATTR_BOTTOM,
    BATTLER_COORD_ATTR_LEFT,
    BATTLER_COORD_ATTR_RIGHT,
    BATTLER_COORD_ATTR_RAW_BOTTOM,
};

u8 GetBattlerSpriteCoord(enum BattlerId battler, u8 coordType);

bool8 IsBattlerSpritePresent(enum BattlerId battler);
void ClearBattleAnimBg(u32 bgId);
u8 GetAnimBattlerSpriteId(enum AnimBattler wantedBattler);
u8 GetBattleBgPaletteNum(void);
u8 GetBattlerSpriteBGPriorityRank(enum BattlerId battler);
void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite *));
void SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite);
u8 GetBattlerSpriteDefault_Y(enum BattlerId battler);
u8 GetSubstituteSpriteDefault_Y(enum BattlerId battler);

// battle_anim_status_effects.c
#define STAT_ANIM_PLUS1  (NUM_BATTLE_STATS * 0)
#define STAT_ANIM_PLUS2  (NUM_BATTLE_STATS * 1)
#define STAT_ANIM_MINUS1 (NUM_BATTLE_STATS * 2)
#define STAT_ANIM_MINUS2 (NUM_BATTLE_STATS * 3)
#define STAT_ANIM_MULTIPLE_PLUS1 55
#define STAT_ANIM_MULTIPLE_PLUS2 56
#define STAT_ANIM_MULTIPLE_MINUS1 57
#define STAT_ANIM_MULTIPLE_MINUS2 58

enum StatAnimPal
{
    STAT_ANIM_PAL_ATK,
    STAT_ANIM_PAL_DEF,
    STAT_ANIM_PAL_ACC,
    STAT_ANIM_PAL_SPEED,
    STAT_ANIM_PAL_EVASION,
    STAT_ANIM_PAL_SPATK,
    STAT_ANIM_PAL_SPDEF,
    STAT_ANIM_PAL_MULTIPLE = 0xFF
};

void LaunchStatusAnimation(enum BattlerId battler, u8 statusAnimId);
extern const union AnimCmd *const gAnims_SpinningSparkle[];

// battle_anim_ground.c
void AnimTask_HorizontalShake(u8 taskId);
void AnimMudSportDirt(struct Sprite *sprite);
void AnimDirtScatter(struct Sprite *sprite);
void AnimMudSportDirtRising(struct Sprite *sprite);
void AnimDirtPlumeParticle(struct Sprite *);
void AnimBoneHitProjectile(struct Sprite *sprite);
extern const union AnimCmd *const sAnims_MudSlapMud[];
extern const union AffineAnimCmd *const gAffineAnims_SpinningBone[];

// battle_anim_throw.c
void TryShinyAnimation(enum BattlerId battler, struct Pokemon *mon);
u8 AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, enum PokeBall ballId);
u8 LaunchBallFadeMonTask(bool8 unfadeLater, u8 spritePalNum, u32 selectedPalettes, enum PokeBall ballId);
bool32 IsCriticalCapture(void);

// battle_anim_utility_funcs.c
void InitStatsChangeAnimation(u8 taskId);
void StartMonScrollingBgMask(u8 taskId, u16 scrollSpeed, enum BattlerId battler, bool8 includePartner, u8 numFadeSteps, u8 fadeStepDelay, u8 duration, const u32 *gfx, const u32 *tilemap, const u16 *palette);
void LoadHealthboxPalsForLevelUp(u8 *paletteId1, u8 *paletteId2, enum BattlerId battler);
void FreeHealthboxPalsForLevelUp(enum BattlerId battler);
void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
int GetAnimBgAttribute(u8 bgId, u8 attributeId);

// battle_anim_effects_1.c
void AnimFalseSwipeSlice_Step3(struct Sprite *);
void SetSpriteNextToMonHead(enum BattlerId battler, struct Sprite *sprite);
void AnimMoveTwisterParticle(struct Sprite *sprite);
void AnimParticleBurst(struct Sprite *sprite);
void AnimPowerAbsorptionOrb(struct Sprite *sprite);
void AnimNeedleArmSpike(struct Sprite *);
void AnimTask_CompressTargetHorizontally(u8 taskId);
void AnimTask_CompressTargetHorizontallyFast(u8 taskId);
void AnimSporeParticle(struct Sprite *sprite);
void AnimAbsorptionOrb(struct Sprite *sprite);
void AnimPetalDanceSmallFlower(struct Sprite *sprite);
void AnimPetalDanceBigFlower(struct Sprite *sprite);
void AnimEndureEnergy(struct Sprite *sprite);
void AnimMimicOrb(struct Sprite *sprite);
void AnimSolarBeamBigOrb(struct Sprite *sprite);
void AnimHyperBeamOrb(struct Sprite *sprite);
void AnimNeedleArmSpike_Step(struct Sprite *sprite);
void AnimMovePowderParticle(struct Sprite *sprite);
void AnimMetronomeFinger(struct Sprite *sprite);
void AnimConversion(struct Sprite *sprite);
void AnimCuttingSlice(struct Sprite *sprite);
void AnimThoughtBubble(struct Sprite *sprite);
void AnimTranslateLinearSingleSineWave(struct Sprite *sprite);
void AnimTeraStarstormStars(struct Sprite *sprite);
void AnimGrantingStars(struct Sprite *sprite);
void AnimFollowMeFinger(struct Sprite *sprite);
void AnimPoisonJabProjectile(struct Sprite *sprite);
extern const union AnimCmd *const gRazorLeafParticleAnimTable[];
extern const union AnimCmd *const gPowerAbsorptionOrbAnimTable[];
extern const union AffineAnimCmd *const gPowerAbsorptionOrbAffineAnimTable[];
extern const union AnimCmd *const gMusicNotesAnimTable[];
extern const union AffineAnimCmd *const gMimicOrbAffineAnimTable[];
extern const union AnimCmd *const gSolarBeamBigOrbAnimTable[];
extern const union AnimCmd *const gPowderParticlesAnimTable[];
extern const union AffineAnimCmd *const gMetronomeFingerAffineAnimTable[];
extern const union AnimCmd *const gPetalDanceBigFlowerAnimTable[];
extern const union AnimCmd *const gOctazookaAnimTable[];
extern const union AffineAnimCmd *const gAbsorptionOrbAffineAnimTable[];
extern const union AnimCmd *const gGrantingStarsAnimTable[];
extern const union AnimCmd *const gSporeParticleAnimTable[];
extern const union AnimCmd *const gHealingBlueStarAnimTable[];
extern const union AnimCmd *const gMoonlightSparkleAnimTable[];
extern const union AnimCmd *const gEndureEnergyAnimTable[];
extern const union AnimCmd *const gPetalDanceSmallFlowerAnimTable[];
extern const union AnimCmd *const gConversionAnimTable[];
extern const union AffineAnimCmd *const gConversionAffineAnimTable[];
extern const union AnimCmd *const gCuttingSliceAnimTable[];
extern const union AnimCmd *const gScratchAnimTable[];
extern const union AnimCmd *const gIngrainRootAnimTable[];
extern const union AffineAnimCmd *const gSwiftStarAffineAnimTable[];
extern const union AnimCmd *const gMetronomeThroughtBubbleAnimTable[];
extern const union AffineAnimCmd *const gStockpileAbsorptionOrbAffineAnimTable[];
extern const union AnimCmd *const gSlashSliceAnimTable[];
extern const union AffineAnimCmd* const sSpriteAffineAnimTable_HydroCannonBall[];
extern const union AffineAnimCmd sSpriteAffineAnim_HydroCannonBall[];

// battle_anim_effects_2.c
void AnimUproarRing(struct Sprite *sprite);
void AnimSonicBoomProjectile(struct Sprite *sprite);
void AnimOrbitFast(struct Sprite *sprite);
void AnimOrbitScatter(struct Sprite *sprite);
void AnimAngerMark(struct Sprite *sprite);
void AnimHyperVoiceRing(struct Sprite *sprite);
void AnimMagentaHeart(struct Sprite *);
extern const union AffineAnimCmd *const gThinRingShrinkingAffineAnimTable[];
extern const union AffineAnimCmd *const gThinRingExpandingAffineAnimTable[];
extern const union AnimCmd *const gExplosionAnimTable[];
extern const union AffineAnimCmd *const gGuardRingAffineAnimTable[];
extern const union AffineAnimCmd *const gAngerMarkAffineAnimTable[];
extern const union AffineAnimCmd *const gWaterPulseRingAffineAnimTable[];
extern const union AffineAnimCmd *const gHyperVoiceRingAffineAnimTable[];
extern const union AnimCmd *const gCoinAnimTable[];
extern const union AffineAnimCmd *const gHiddenPowerOrbAffineAnimTable[];
extern const union AffineAnimCmd *const gBulletSeedAffineAnimTable[];

// battle_anim_effects_3.c
void AnimKnockOffStrike_Step(struct Sprite *sprite);
void AnimBlackSmoke(struct Sprite *sprite);
void AnimSweetScentPetal(struct Sprite *sprite);
void AnimTealAlert(struct Sprite *sprite);
void AnimBlockX(struct Sprite *sprite);
void AnimFlatterSpotlight_Step(struct Sprite *);
void AnimAssistPawprint(struct Sprite *);
void AnimReversalOrb(struct Sprite *);
void AnimFlatterSpotlight_Step(struct Sprite *sprite);
extern const union AnimCmd *const gOpeningEyeAnimTable[];
extern const union AnimCmd *const gEclipsingOrbAnimTable[];
extern const union AffineAnimCmd *const gSpotlightAffineAnimTable[];
extern const union AffineAnimCmd *const gSmokeBallEscapeCloudAffineAnimTable[];
extern void AnimSmokeBallEscapeCloud(struct Sprite *sprite);
extern const union AffineAnimCmd *const gKnockOffStrikeAffineAnimTable[];
extern const union AnimCmd *const gKnockOffStrikeAnimTable[];

// battle_anim_water.c
void AnimWaterPulseRing(struct Sprite *sprite);
void AnimSmallBubblePair(struct Sprite *sprite);
void AnimWaterPulseBubble(struct Sprite *sprite);
extern const union AnimCmd *const gAnims_WaterBubbleProjectile[];
extern const union AnimCmd *const gAnims_FlamethrowerFlame[];
extern const union AnimCmd *const gAnims_WaterPulseBubble[];

// battle_anim_flying.c
void DestroyAnimSpriteAfterTimer(struct Sprite *sprite);
void AnimAirWaveCrescent(struct Sprite *sprite);
void AnimFlyBallUp(struct Sprite *sprite);
void AnimFlyBallAttack(struct Sprite *sprite);
void AnimFlyBallAttack_Step(struct Sprite *sprite);
void AnimFlyBallUp_Step(struct Sprite *sprite);
void AnimBounceBallLand(struct Sprite *);
void AnimEllipticalGust(struct Sprite *);
extern const union AnimCmd *const gAffineAnims_AirWaveCrescent[];
extern const union AffineAnimCmd *const gAffineAnims_FlyBallUp[];
extern const union AffineAnimCmd *const gAffineAnims_FlyBallAttack[];
extern const union AffineAnimCmd *const gAffineAnims_BounceBallLand[];
extern const union AnimCmd *const gAnims_FallingFeather[];

// battle_anim_poison.c
void AnimSludgeBombHitParticle(struct Sprite *);
void AnimAcidPoisonBubble_Step(struct Sprite *sprite);
void AnimBubbleEffect(struct Sprite *);
extern const union AffineAnimCmd *const gAffineAnims_PoisonProjectile[];
extern const union AnimCmd *const gAnims_PoisonProjectile[];
extern const union AnimCmd *const gAnims_AcidPoisonDroplet[];
extern const union AffineAnimCmd *const gAffineAnims_Bubble[];

// battle_anim_ghost.c
void AnimGhostStatusSprite(struct Sprite *sprite);
void AnimShadowBall(struct Sprite *sprite);
void AnimTask_GrudgeFlames_Step(u8 taskId);
extern const union AffineAnimCmd *const gAffineAnims_ShadowBall[];
extern const union AnimCmd *const gAnims_GrudgeFlame[];

// battle_anim_psychic.c
extern const union AffineAnimCmd *const gAffineAnims_PsychoBoostOrb[];
extern const union AffineAnimCmd *const gAffineAnims_LusterPurgeCircle[];
void AnimPsychoBoost(struct Sprite *sprite);

// battle_anim_smokescreen.c
u8 SmokescreenImpact(s16 x, s16 y, bool8 persist);

u32 UnpackSelectedBattlePalettes(s16 selector);

u8 GetBattlerSpriteFinal_Y(enum BattlerId battler, enum Species species, bool32 a3);

extern const struct OamData gOamData_AffineOff_ObjNormal_8x16;
extern const struct OamData gOamData_AffineNormal_ObjBlend_16x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_8x8;
extern const struct OamData gOamData_AffineDouble_ObjNormal_8x8;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_64x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_16x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_16x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_64x64;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_8x8;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x32;
extern const struct OamData gOamData_AffineNormal_ObjBlend_64x64;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x16;
extern const struct OamData gOamData_AffineDouble_ObjNormal_16x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x64;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_64x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_64x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_64x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_8x16;
extern const struct OamData gOamData_AffineDouble_ObjNormal_64x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_16x16;
extern const struct OamData gOamData_AffineDouble_ObjBlend_16x16;
extern const struct OamData gOamData_AffineNormal_ObjNormal_8x8;
extern const struct OamData gOamData_AffineDouble_ObjBlend_8x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_8x8;
extern const struct OamData gOamData_AffineNormal_ObjBlend_8x16;
extern const struct OamData gOamData_AffineNormal_ObjBlend_8x8;
extern const struct OamData gOamData_AffineOff_ObjBlend_8x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_64x64;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x64;
extern const struct OamData gOamData_AffineNormal_ObjNormal_64x64;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_64x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_64x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_16x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x8;

extern const struct BattleAnimation gBattleAnimTable[ANIM_TAG_COUNT];

extern const struct SpriteTemplate gWaterHitSplatSpriteTemplate;
extern const struct SpriteTemplate gGrudgeFlameSpriteTemplate;

extern const union AnimCmd *const gAnims_WaterMudOrb[];
extern const union AnimCmd *const gAnims_BasicFire[];
extern const union AffineAnimCmd *const gGrowingRingAffineAnimTable[];
extern const union AffineAnimCmd *const gAffineAnims_Droplet[];
extern const union AnimCmd *const gAnims_SmallBubblePair[];
extern const union AnimCmd *const gAnims_WaterBubble[];
extern const union AffineAnimCmd *const gAffineAnims_Bite[];

// battle_anim_normal.c
extern const union AffineAnimCmd *const gAffineAnims_HitSplat[];
void AnimHitSplatBasic(struct Sprite *sprite);
void AnimFlashingHitSplat(struct Sprite *sprite);
void AnimFlashingHitSplat_Step(struct Sprite *sprite);
void AnimHitSplatRandom(struct Sprite *sprite);
void AnimCrossImpact(struct Sprite *sprite);
void AnimHitSplatOnMonEdge(struct Sprite *sprite);

// battle_anim_electric.c
void AnimThunderWave(struct Sprite *sprite);
void AnimGrowingChargeOrb(struct Sprite *sprite);
void AnimZapCannonSpark(struct Sprite *sprite);
void AnimSparkElectricity(struct Sprite *sprite);
void AnimElectricPuff(struct Sprite *sprite);
void AnimSparkElectricityFlashing(struct Sprite *sprite);
void AnimGrowingShockWaveOrb(struct Sprite *sprite);
void AnimElectricity(struct Sprite *);
void AnimTask_VoltSwitch(struct Sprite* sprite);
extern const union AffineAnimCmd *const gAffineAnims_GrowingElectricOrb[];
extern const union AffineAnimCmd *const gAffineAnims_FlashingSpark[];
extern const union AnimCmd *const sAnims_CirclingElectricShock[];
extern const union AnimCmd *const gAnims_ThunderboltOrb[];
extern const union AnimCmd *const gAnims_ElectricPuff[];
extern const union AnimCmd *const gAnims_ElectricChargingParticles[];

// battle_anim_fight.c
void AnimStompFoot(struct Sprite *sprite);
void AnimSpinningKickOrPunch(struct Sprite *sprite);
void AnimBrickBreakWall_Step(struct Sprite *sprite);
void AnimJumpKick(struct Sprite *sprite);
void AnimBasicFistOrFoot(struct Sprite *sprite);
void AnimSpinningKickOrPunchFinish(struct Sprite *sprite);
void AnimRevengeScratch(struct Sprite *sprite);
void AnimDizzyPunchDuck(struct Sprite *sprite);
void AnimSuperpowerFireball(struct Sprite *);
extern const union AnimCmd *const gAnims_HandsAndFeet[];
extern const union AffineAnimCmd *const gAffineAnims_MegaPunchKick[];
extern const union AffineAnimCmd *const gAffineAnims_SpinningHandOrFoot[];
extern const union AnimCmd *const gAnims_RevengeBigScratch[];

// battle_anim_rock.c
extern const union AnimCmd *const gAnims_FlyingRock[];
extern const union AffineAnimCmd *const gAffineAnims_Whirlpool[];
extern const union AffineAnimCmd *const gAffineAnims_BasicRock[];
extern const union AnimCmd *const gAnims_FlyingRock[];
extern const union AnimCmd *const sAnims_BasicRock[];
void AnimRockTomb(struct Sprite *sprite);
void AnimParticleInVortex(struct Sprite *sprite);
void AnimFallingRock(struct Sprite *sprite);
void AnimRaiseSprite(struct Sprite *sprite);
void AnimFallingRock_Step(struct Sprite *sprite);
void AnimFlyingSandCrescent(struct Sprite *sprite);
void AnimRockFragment(struct Sprite *);
void AnimRockBlastRock(struct Sprite *sprite);

// battle_anim_dark.c
void AnimClawSlash(struct Sprite *sprite);
void AnimTearDrop(struct Sprite *sprite);
void AnimBite(struct Sprite *sprite);
extern const union AnimCmd *const gAnims_ClawSlash[];
extern const union AffineAnimCmd *const gAffineAnims_TearDrop[];

// battle_anim_bug.c
void AnimStringWrap_Step(struct Sprite *sprite);
void AnimMissileArc(struct Sprite *sprite);
void AnimSpiderWeb(struct Sprite *sprite);
void AnimMissileArc_Step(struct Sprite *sprite);

// battle_anim_ice.c
void AnimThrowMistBall(struct Sprite *sprite);
void AnimMoveParticleBeyondTarget(struct Sprite *sprite);
void AnimIceEffectParticle(struct Sprite *sprite);
void AnimSwirlingSnowball_Step1(struct Sprite *sprite);
extern const union AnimCmd *const gAnims_Snowball[];
extern const union AffineAnimCmd *const gAffineAnims_IceCrystalHit[];
extern const union AnimCmd *const gAnims_IceCrystalLarge[];
extern const union AnimCmd *const gAnims_IceCrystalSmall[];
extern const union AnimCmd *const gAnims_IceBallChunk[];
extern const union AnimCmd *const gAnims_BlizzardIceCrystal[];

// battle_anim_fire.c
void AnimFireSpread(struct Sprite *sprite);
void AnimFireSpiralOutward(struct Sprite *sprite);
void AnimWillOWispOrb(struct Sprite *);
void AnimEruptionFallingRock(struct Sprite *);
void AnimFireCross(struct Sprite *);
void AnimFirePlume(struct Sprite *);
extern const union AnimCmd *const gAnims_FireBlastCross[];
extern const union AnimCmd *const gAnims_WillOWispOrb[];
extern const union AnimCmd *const gAnims_FirePlume[];

// battle_anim_dragon.c
extern const union AnimCmd *const gAnims_DreepyMissilePlayer[];
extern const union AnimCmd *const gAnims_DreepyMissileOpponent[];
extern const union AnimCmd *const gAnims_DreepyMissileOpponentNotDrag[];
extern const union AnimCmd *const gAnims_DragonBreathFire[];
extern const union AnimCmd *const gAnims_DragonRageFirePlume[];
extern const union AffineAnimCmd *const gAffineAnims_DragonRageFire[];
extern const union AnimCmd *const gAnims_DragonRageFire[];
extern const union AffineAnimCmd *const gAffineAnims_DragonBreathFire[];
void AnimDragonRageFirePlume(struct Sprite *sprite);
void AnimDragonFireToTarget(struct Sprite *sprite);
void AnimDragonDanceOrb(struct Sprite *sprite);
void AnimOverheatFlame(struct Sprite *sprite);
void AnimOutrageFlame(struct Sprite *sprite);
void AnimDracoMeteorRock(struct Sprite *sprite);

// battle_anim_new.c
void CoreEnforcerLoadBeamTarget(struct Sprite *sprite);
void SpriteCB_RandomCentredHits(struct Sprite *sprite);
void InitSpritePosToAnimTargetsCentre(struct Sprite *sprite, bool32 respectMonPicOffsets);
extern const union AffineAnimCmd *const gSpriteAffineAnimTable_PrimalSymbol[];
extern const union AffineAnimCmd *const gSpriteAffineAnimTable_MegaSymbol[];

// battle_anim_ice.c
void AnimIceBeamParticle(struct Sprite *sprite);

// battle_anim_bug.c
void AnimTranslateStinger(struct Sprite *sprite);

extern const struct BattleAnimBackground gBattleAnimBackgroundTable[];

#endif // GUARD_BATTLE_ANIM_H
