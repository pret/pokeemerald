#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

#include "battle.h"
#include "constants/battle_anim.h"
#include "task.h"

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
    const u32 *palette;
    const u32 *tilemap;
};

#define ANIM_ARGS_COUNT 8

extern void (*gAnimScriptCallback)(void);
extern bool8 gAnimScriptActive;
extern u8 gAnimVisualTaskCount;
extern u8 gAnimSoundTaskCount;
extern struct DisableStruct *gAnimDisableStructPtr;
extern s32 gAnimMoveDmg;
extern u16 gAnimMovePower;
extern u8 gAnimFriendship;
extern u16 gWeatherMoveAnim;
extern s16 gBattleAnimArgs[ANIM_ARGS_COUNT];
extern u8 gAnimMoveTurn;
extern u8 gBattleAnimAttacker;
extern u8 gBattleAnimTarget;
extern u16 gAnimBattlerSpecies[MAX_BATTLERS_COUNT];
extern u8 gUnknown_02038440;

void ClearBattleAnimationVars(void);
void DoMoveAnim(u16 move);
void LaunchBattleAnimation(const u8 *const animsTable[], u16 tableId, bool8 isMoveAnim);
void DestroyAnimSprite(struct Sprite *sprite);
void DestroyAnimVisualTask(u8 taskId);
void DestroyAnimSoundTask(u8 taskId);
u8 GetAnimBattlerId(u8 wantedBattler);
bool8 IsBattlerSpriteVisible(u8 battlerId);
void MoveBattlerSpriteToBG(u8 battlerId, bool8 toBG_2, bool8 setSpriteInvisible);
bool8 IsContest(void);
s8 BattleAnimAdjustPanning(s8 pan);
s8 BattleAnimAdjustPanning2(s8 pan);
s16 KeepPanInRange(s16 a, int oldPan);
s16 CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan);
void sub_80A4720(u16 a, u16 *b, u32 c, u8 d);
void sub_80A477C(bool8);

// battle_intro.s
void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
void sub_8118FBC(int bgId, u8 arg1, u8 arg2, u8 battlerPosition, u8 arg4, u8 *arg5, u16 *arg6, u16 arg7);
void HandleIntroSlide(u8 terrainId);
int GetAnimBgAttribute(u8 bgId, u8 attributeId);

// battle_anim_mons.s
void TranslateSpriteInEllipseOverDuration(struct Sprite *sprite);
void sub_80A8AEC(struct Sprite *sprite);
void sub_80A8A6C(struct Sprite *sprite);
void sub_80A8E30(struct Sprite *sprite);
void sub_80A8B64(struct Sprite *sprite);
void SetAverageBattlerPositions(u8 battlerId, bool8 respectMonPicOffsets, s16 *x, s16 *y);
void DestroySpriteAndMatrix(struct Sprite *sprite);
void TranslateSpriteLinearFixedPoint(struct Sprite *sprite);
void InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets);
void InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets);
void StartAnimLinearTranslation(struct Sprite *sprite);
void InitAnimArcTranslation(struct Sprite *sprite);
bool8 AnimTranslateLinear(struct Sprite *sprite);
void TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite);
void sub_80A8EE4(struct Sprite *sprite);
u8 GetBattlerSpriteCoord2(u8 battlerId, u8 attributeId);
void sub_80A6FD4(struct Sprite *sprite);
u16 ArcTan2Neg(s16 a, s16 b);
void TrySetSpriteRotScale(struct Sprite *sprite, bool8 a2, s16 xScale, s16 yScale, u16 rotation);
void RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite);
void TranslateSpriteLinearAndFlicker(struct Sprite *sprite);
void SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite);
void RunStoredCallbackWhenAnimEnds(struct Sprite *sprite);
void SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 a2);
s16 GetBattlerSpriteCoordAttr(u8 battlerId, u8 a2);
u8 GetBattlerYCoordWithElevation(u8 battlerId);
void WaitAnimForDuration(struct Sprite *sprite);
void sub_80A7938(struct Sprite *sprite);
void InitAnimLinearTranslation(struct Sprite *sprite);
void sub_80A6F98(struct Sprite *sprite);
u8 GetBattlerSpriteBGPriority(u8 battlerId);
void *LoadPointerFromVars(s16 bottom, s16 top);
void StorePointerInVars(s16 *bottom, s16 *top, const void *ptr);
void sub_80A8278(void);
void sub_80A6B30(struct BattleAnimBgData*);
void sub_80A6B90(struct BattleAnimBgData*, u32 arg1);
u8 GetBattlerSpriteSubpriority(u8 battlerId);
bool8 TranslateAnimHorizontalArc(struct Sprite *sprite);
void sub_80A6630(struct Sprite *sprite);
void TranslateMonSpriteLinearFixedPoint(struct Sprite *sprite);
void ResetSpriteRotScale(u8 spriteId);
void SetSpriteRotScale(u8 spriteId, s16 xScale, s16 yScale, u16 rotation);
void InitSpriteDataForLinearTranslation(struct Sprite *sprite);
void PrepareBattlerSpriteForRotScale(u8 spriteId, u8 objMode);
void SetBattlerSpriteYOffsetFromRotation(u8 spriteId);
u32 sub_80A75AC(u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7);
u32 sub_80A76C4(u8 a1, u8 a2, u8 a3, u8 a4);
u8 sub_80A77AC(u8 a1);
s16 CloneBattlerSpriteWithBlend(u8);
void obj_delete_but_dont_free_vram(struct Sprite*);
u8 sub_80A89C8(int, u8, int);
void sub_80A6D60(struct BattleAnimBgData*, const void*, u32);
void AnimLoadCompressedBgGfx(u32, const u32*, u32);
void sub_80A6DAC(bool8);
void TranslateSpriteInGrowingCircleOverDuration(struct Sprite *);
void sub_80A653C(struct Sprite *);
void SetBattlerSpriteYOffsetFromYScale(u8 spriteId);
void sub_80A805C(struct Task *task, u8 a2, s16 a3, s16 a4, s16 a5, s16 a6, u16 a7);
u8 sub_80A80C8(struct Task *task);
void sub_80A8EE4(struct Sprite *);
void DestroyAnimSpriteAndDisableBlend(struct Sprite *);
void AnimLoadCompressedBgTilemap(u32 bgId, const void *src);
void InitAnimFastLinearTranslationWithSpeed(struct Sprite *sprite);
bool8 AnimFastTranslateLinear(struct Sprite *sprite);
void InitAndRunAnimFastLinearTranslation(struct Sprite *sprite);
void TranslateMonSpriteLinear(struct Sprite *sprite);
void TranslateSpriteLinear(struct Sprite *sprite);
void sub_80A77C8(struct Sprite *sprite);
void sub_80A7000(struct Sprite *sprite);
void TranslateSpriteInCircleOverDuration(struct Sprite *sprite);
void SetGreyscaleOrOriginalPalette(u16 a1, bool8 a2);
void PrepareAffineAnimInTaskData(struct Task *task, u8 spriteId, const union AffineAnimCmd *affineAnimCmds);
bool8 RunAffineAnimFromTaskData(struct Task *task);
void sub_80A78AC(struct Sprite *sprite);
void sub_80A6BFC(struct BattleAnimBgData *unk, u8 unused);
u8 sub_80A8394(u16 species, bool8 isBackpic, u8 a3, s16 x, s16 y, u8 subpriority, u32 personality, u32 trainerId, u32 battlerId, u32 a10);
void sub_80A749C(struct Sprite *sprite);
void sub_80A6DEC(struct Sprite *sprite);
void DestroyAnimVisualTaskAndDisableBlend(u8 taskId);
void DestroySpriteAndFreeResources_(struct Sprite *sprite);
void SetBattlerSpriteYOffsetFromOtherYScale(u8 spriteId, u8 otherSpriteId);
u8 GetBattlerSide(u8 battler);
u8 GetBattlerPosition(u8 battler);
u8 GetBattlerAtPosition(u8 position);

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

u8 GetBattlerSpriteCoord(u8 battlerId, u8 attributeId);

bool8 IsBattlerSpritePresent(u8 battlerId);
void sub_80A6C68(u32 arg0);
u8 GetAnimBattlerSpriteId(u8 wantedBattler);
bool8 IsDoubleBattle(void);
u8 sub_80A6D94(void);
u8 GetBattlerSpriteBGPriorityRank(u8 battlerId);
void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*spriteCallback)(struct Sprite*));
void SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite);
u8 GetBattlerSpriteDefault_Y(u8 battlerId);
u8 GetSubstituteSpriteDefault_Y(u8 battlerId);

// battle_anim_80A64EC.c
void sub_80A64EC(struct Sprite *sprite);
void sub_80A718C(struct Sprite *sprite);

// battle_anim_status_effects.s
#define STAT_ANIM_PLUS1  15
#define STAT_ANIM_PLUS2  39
#define STAT_ANIM_MINUS1 22
#define STAT_ANIM_MINUS2 46
#define STAT_ANIM_MULTIPLE_PLUS1 55
#define STAT_ANIM_MULTIPLE_PLUS2 56
#define STAT_ANIM_MULTIPLE_MINUS1 57
#define STAT_ANIM_MULTIPLE_MINUS2 58
void LaunchStatusAnimation(u8 battlerId, u8 statusAnimId);

// ground.c
void sub_81152DC(u8 taskId);

// battle_anim_special.c
void sub_8172EF0(u8 battler, struct Pokemon *mon);
u8 ItemIdToBallId(u16 itemId);
u8 AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, u8 ballId);
u8 LaunchBallFadeMonTask(bool8 unFadeLater, u8 battlerId, u32 selectedPalettes, u8 ballId);

// battle_anim_utility_funcs.s
void sub_8116EB4(u8);
void sub_8117854(u8 taskId, int unused, u16 arg2, u8 battler1, u8 arg4, u8 arg5, u8 arg6, u8 arg7, const u32 *arg8, const u32 *arg9, const u32 *palette);

// battle_anim_effects_1.c
void sub_810310C(u8 battler, struct Sprite* sprite);
void AnimMoveTwisterParticle(struct Sprite* sprite);
void AnimPowerAbsorptionOrb(struct Sprite* sprite);
extern const union AnimCmd *const gUnknown_08592388[];
extern const union AnimCmd *const gUnknown_085921C8[];
extern const union AffineAnimCmd *const gUnknown_085921DC[];
void sub_8100898(struct Sprite *);

// water.c
void sub_8108C94(struct Sprite *sprite);

// flying.c
void sub_810E2C8(struct Sprite *sprite);
extern const union AnimCmd *const gUnknown_085962D0[];
void sub_810E044(struct Sprite *sprite);

//poison.c
extern const union AffineAnimCmd *const gUnknown_085961A0[];

// ghost.c
void sub_8112B78(struct Sprite *sprite);

// psychic.c
extern const union AffineAnimCmd *const gUnknown_08596894[];

// smokescreen.c
u8 sub_807521C(s16 x, s16 y, u8 a3);

u32 UnpackSelectedBattleAnimPalettes(s16);

u8 GetBattlerSpriteFinal_Y(u8, u16, u8);

extern const struct OamData gUnknown_08524904;
extern const struct OamData gUnknown_0852490C;
extern const struct OamData gUnknown_08524914;
extern const struct OamData gUnknown_0852491C;
extern const struct OamData gUnknown_08524924;
extern const struct OamData gUnknown_0852492C;
extern const struct OamData gUnknown_08524934;
extern const struct OamData gUnknown_0852493C;
extern const struct OamData gUnknown_08524944;
extern const struct OamData gUnknown_0852494C;
extern const struct OamData gUnknown_08524954;
extern const struct OamData gUnknown_0852495C;
extern const struct OamData gUnknown_08524964;
extern const struct OamData gUnknown_0852496C;
extern const struct OamData gUnknown_08524974;
extern const struct OamData gUnknown_0852497C;
extern const struct OamData gUnknown_08524984;
extern const struct OamData gUnknown_0852498C;
extern const struct OamData gUnknown_08524994;
extern const struct OamData gUnknown_0852499C;
extern const struct OamData gUnknown_085249A4;
extern const struct OamData gUnknown_085249AC;
extern const struct OamData gUnknown_085249B4;
extern const struct OamData gUnknown_085249BC;
extern const struct OamData gUnknown_085249C4;
extern const struct OamData gUnknown_085249CC;
extern const struct OamData gUnknown_085249D4;
extern const struct OamData gUnknown_085249DC;
extern const struct OamData gUnknown_085249E4;
extern const struct OamData gUnknown_085249EC;
extern const struct OamData gUnknown_085249F4;
extern const struct OamData gUnknown_085249FC;
extern const struct OamData gUnknown_08524A04;
extern const struct OamData gUnknown_08524A0C;
extern const struct OamData gUnknown_08524A14;
extern const struct OamData gUnknown_08524A1C;
extern const struct OamData gUnknown_08524A24;
extern const struct OamData gUnknown_08524A2C;
extern const struct OamData gUnknown_08524A34;
extern const struct OamData gUnknown_08524A3C;
extern const struct OamData gUnknown_08524A44;
extern const struct OamData gUnknown_08524A4C;
extern const struct OamData gUnknown_08524A54;
extern const struct OamData gUnknown_08524A5C;
extern const struct OamData gUnknown_08524A64;
extern const struct OamData gUnknown_08524A6C;
extern const struct OamData gUnknown_08524A74;
extern const struct OamData gUnknown_08524A7C;
extern const struct OamData gUnknown_08524A84;
extern const struct OamData gUnknown_08524A8C;
extern const struct OamData gUnknown_08524A94;
extern const struct OamData gUnknown_08524A9C;
extern const struct OamData gUnknown_08524AA4;
extern const struct OamData gUnknown_08524AAC;
extern const struct OamData gUnknown_08524AB4;
extern const struct OamData gUnknown_08524ABC;
extern const struct OamData gUnknown_08524AC4;
extern const struct OamData gUnknown_08524ACC;
extern const struct OamData gUnknown_08524AD4;
extern const struct OamData gUnknown_08524ADC;
extern const struct OamData gUnknown_08524AE4;
extern const struct OamData gUnknown_08524AEC;
extern const struct OamData gUnknown_08524AF4;
extern const struct OamData gUnknown_08524AFC;
extern const struct OamData gUnknown_08524B04;
extern const struct OamData gUnknown_08524B0C;
extern const struct OamData gUnknown_08524B14;
extern const struct OamData gUnknown_08524B1C;
extern const struct OamData gUnknown_08524B24;
extern const struct OamData gUnknown_08524B2C;
extern const struct OamData gUnknown_08524B34;
extern const struct OamData gUnknown_08524B3C;

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];

#endif // GUARD_BATTLE_ANIM_H
