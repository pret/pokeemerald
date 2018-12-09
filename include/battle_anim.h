#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

#include "battle.h"
#include "constants/battle_anim.h"
#include "task.h"

enum
{
    BG_ANIM_SCREEN_SIZE,
    BG_ANIM_AREA_OVERFLOW_MODE,
    BG_ANIM2,
    BG_ANIM_CHAR_BASE_BLOCK,
    BG_ANIM_PRIORITY,
    BG_ANIM_5,
    BG_ANIM_6
};

struct UnknownAnimStruct2
{
    u8 *bgTiles;
    u16 *unk4;
    u8 unk8;
    u8 bgId;
    u16 tilesOffset;
    u16 unkC;
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
bool8 IsBattlerSpriteVisible(u8 battlerId);
void sub_80A438C(u8 battlerId, bool8 toBG_2, bool8 setSpriteInvisible);
bool8 IsContest(void);
s8 BattleAnimAdjustPanning(s8 pan);
s8 BattleAnimAdjustPanning2(s8 pan);
s16 KeepPanInRange(s16 a);
s16 CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan);
void sub_80A4720(u16 a, u16 *b, u32 c, u8 d);
void sub_80A477C(bool8);

// battle_anim_80FE840.s
void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
void sub_8118FBC(u8 arg0, u8 arg1, u8 arg2, u8 battlerPosition, u8 arg4, void *arg5, u16 *arg6, u16 arg7);
void HandleIntroSlide(u8 terrainId);
u32 GetAnimBgAttribute(u8 bgId, u8 attributeId);

// battle_anim_80A5C6C.s
void sub_80A6450(struct Sprite *sprite);
void SetAverageBattlerPositions(u8 battlerId, bool8 a2, s16 *x, s16 *y);
void move_anim_8074EE0(struct Sprite *sprite);
void sub_80A656C(struct Sprite *sprite);
void InitAnimSpritePos(struct Sprite *sprite, u8 a2);
void sub_80A6980(struct Sprite *sprite, bool8 a2);
void StartAnimLinearTranslation(struct Sprite *sprite);
void InitAnimArcTranslation(struct Sprite *sprite);
bool8 TranslateAnimLinear(struct Sprite *sprite);
void TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite);
void sub_80A8EE4(struct Sprite *sprite);
u8 GetBattlerSpriteCoord2(u8 battlerId, u8 attributeId);
void sub_80A6FD4(struct Sprite *sprite);
u16 ArcTan2Neg(s16 a, s16 b);
void sub_80A73E0(struct Sprite *sprite, bool8 a2, s16 xScale, s16 yScale, u16 rotation);
void sub_80A67BC(struct Sprite *sprite);
void sub_80A66DC(struct Sprite *sprite);
void sub_80A6838(struct Sprite *sprite);
void sub_80A67D8(struct Sprite *sprite);
void sub_80A6864(struct Sprite *sprite, s16 a2);
s16 sub_80A861C(u8 battlerId, u8 a2);
u8 GetBattlerYCoordWithElevation(u8 battlerId);
void WaitAnimForDuration(struct Sprite *sprite);
void sub_80A7938(struct Sprite *sprite);
void InitAnimLinearTranslation(struct Sprite *sprite);
void sub_80A6F98(struct Sprite *sprite);
u8 sub_80A8328(u8 battlerId);
void *sub_80A8050(s16 bottom, s16 top);
void sub_80A8048(s16 *bottom, s16 *top, const void *ptr);
void sub_80A8278(void);
void sub_80A6B30(struct UnknownAnimStruct2*);
void sub_80A6B90(struct UnknownAnimStruct2*, u32 arg1);
u8 sub_80A82E4(u8 battlerId);
bool8 TranslateAnimArc(struct Sprite *sprite);
void sub_80A6630(struct Sprite *sprite);
void sub_80A6680(struct Sprite *sprite);
void sub_80A7344(u8 spriteId);
void obj_id_set_rotscale(u8 spriteId, s16 xScale, s16 yScale, u16 rotation);
void InitSpriteDataForLinearTranslation(struct Sprite *sprite);
void sub_80A7270(u8 spriteId, u8 objMode);
void sub_80A73A0(u8 spriteId);
u32 sub_80A75AC(u8 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7);
u32 sub_80A76C4(u8 a1, u8 a2, u8 a3, u8 a4);
u8 sub_80A77AC(u8 a1);
s16 duplicate_obj_of_side_rel2move_in_transparent_mode(u8);
void obj_delete_but_dont_free_vram(struct Sprite*);
u8 sub_80A89C8(int, u8, int);
void sub_80A6D60(struct UnknownAnimStruct2*, const void*, u32);
void sub_80A6CC0(u32, const void*, u32);
void sub_80A6DAC(bool8);
void sub_80A634C(struct Sprite *);
void sub_80A653C(struct Sprite *);
void sub_80A7E6C(u8 spriteId);
void sub_80A805C(struct Task *task, u8 a2, s16 a3, s16 a4, s16 a5, s16 a6, u16 a7);
u8 sub_80A80C8(struct Task *task);
void sub_80A8EE4(struct Sprite *);

enum
{
    BATTLER_COORD_X,
    BATTLER_COORD_Y,
    BATTLER_COORD_X_2,
    BATTLER_COORD_3,
    BATTLER_COORD_4,
};

u8 GetBattlerSpriteCoord(u8 battlerId, u8 attributeId);

bool8 IsBattlerSpritePresent(u8 battlerId);
void sub_80A6C68(u32 arg0);
u8 GetAnimBattlerSpriteId(u8 wantedBattler);
bool8 IsDoubleBattle(void);
u8 sub_80A6D94(void);
u8 sub_80A8364(u8 battlerId);
void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*spriteCallback)(struct Sprite*));
void oamt_add_pos2_onto_pos1(struct Sprite *sprite);
u8 GetBattlerSpriteDefault_Y(u8 battlerId);
u8 sub_80A82E4(u8 battlerId);
u8 GetSubstituteSpriteDefault_Y(u8 battlerId);

// battle_anim_80A9C70.s
#define STAT_ANIM_PLUS1  15
#define STAT_ANIM_PLUS2  39
#define STAT_ANIM_MINUS1 22
#define STAT_ANIM_MINUS2 46
#define STAT_ANIM_MULTIPLE_PLUS1 55
#define STAT_ANIM_MULTIPLE_PLUS2 56
#define STAT_ANIM_MULTIPLE_MINUS1 57
#define STAT_ANIM_MULTIPLE_MINUS2 58
void LaunchStatusAnimation(u8 battlerId, u8 statusAnimId);

// battle_anim_8170478.s
u8 ItemIdToBallId(u16 itemId);
u8 LaunchBallStarsTask(u8 x, u8 y, u8 kindOfStars, u8 arg3, u8 ballId);
u8 LaunchBallFadeMonTask(bool8 unFadeLater, u8 battlerId, u32 arg2, u8 ballId);

// battle_anim_utility_funcs.s
void sub_8116EB4(u8);

u32 UnpackSelectedBattleAnimPalettes(s16);

u8 GetBattlerSpriteFinal_Y(u8, u16, u8);

extern const struct OamData gUnknown_08524944;
extern const struct OamData gUnknown_08524A8C;
extern const struct OamData gUnknown_08524904;
extern const struct OamData gUnknown_085249C4;
extern const struct OamData gUnknown_0852490C;
extern const struct OamData gUnknown_08524934;
extern const struct OamData gUnknown_08524974;
extern const struct OamData gUnknown_0852499C;
extern const struct OamData gUnknown_085249CC;
extern const struct OamData gUnknown_08524914;
extern const struct OamData gUnknown_0852496C;
extern const struct OamData gUnknown_08524A34;
extern const struct OamData gUnknown_08524A3C;
extern const struct OamData gUnknown_08524A94;
extern const struct OamData gUnknown_08524954;
extern const struct OamData gUnknown_08524AE4;
extern const struct OamData gUnknown_085249D4;
extern const struct OamData gUnknown_08524A9C;
extern const struct OamData gUnknown_08524ADC;
extern const struct OamData gUnknown_08524B14;
extern const struct OamData gUnknown_08524A54;
extern const struct OamData gUnknown_08524A14;
extern const struct OamData gUnknown_08524A1C;
extern const struct OamData gUnknown_085249BC;
extern const struct OamData gUnknown_08524AF4;
extern const struct OamData gUnknown_085249DC;
extern const struct OamData gUnknown_08524AFC;
extern const struct OamData gUnknown_08524B1C;
extern const struct OamData gUnknown_08524A04;
extern const struct OamData gUnknown_08524A2C;
extern const struct OamData gUnknown_08524AEC;
extern const struct OamData gUnknown_08524964;
extern const struct OamData gUnknown_08524B24;
extern const struct OamData gUnknown_08524A24;
extern const struct OamData gUnknown_08524AC4;
extern const struct OamData gUnknown_08524A84;
extern const struct OamData gUnknown_08524A64;
extern const struct OamData gUnknown_0852491C;
extern const struct OamData gUnknown_0852495C;
extern const struct OamData gUnknown_0852497C;
extern const struct OamData gUnknown_085249F4;
extern const struct OamData gUnknown_0852493C;
extern const struct OamData gUnknown_08524A5C;
extern const struct OamData gUnknown_08524A74;

#endif // GUARD_BATTLE_ANIM_H
