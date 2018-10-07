#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

enum
{
    BG_ANIM_SCREEN_SIZE,
    BG_ANIM_AREA_OVERFLOW_MODE,
    BG_ANIM2,
    BG_ANIM3,
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
    void *image;
    void *palette;
    void *tilemap;
};

#define ANIM_ARGS_COUNT 8

#define PAN_SIDE_PLAYER     -64
#define PAN_SIDE_OPPONENT   63

extern void (*gAnimScriptCallback)(void);
extern bool8 gAnimScriptActive;
extern u8 gAnimVisualTaskCount;
extern u8 gAnimSoundTaskCount;
extern struct DisableStruct *gAnimDisableStructPtr;
extern u32 gAnimMoveDmg;
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

// battle_anim_80FE840.s
void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
void sub_8118FBC(u8 arg0, u8 arg1, u8 arg2, u8 battlerPosition, u8 arg4, void *arg5, u16 *arg6, u16 arg7);
void HandleIntroSlide(u8 terrainId);
u32 GetAnimBgAttribute(u8 bgId, u8 attributeId);

// battle_anim_80A5C6C.s
void sub_80A6EEC(struct Sprite *sprite);
void sub_80A68D4(struct Sprite *sprite);
bool8 TranslateAnimLinear(struct Sprite *sprite);
void sub_80A8278(void);
void sub_80A6B30(struct UnknownAnimStruct2*);
void sub_80A6B90(struct UnknownAnimStruct2*, u32 arg1);
u8 sub_80A82E4(u8 battlerId);
bool8 TranslateAnimArc(struct Sprite *sprite);

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
void LaunchStatusAnimation(u8 battlerId, u8 statusAnimId);

// battle_anim_8170478.s
u8 ItemIdToBallId(u16 itemId);
u8 LaunchBallStarsTask(u8 x, u8 y, u8 kindOfStars, u8 arg3, u8 ballId);
u8 LaunchBallFadeMonTask(bool8 unFadeLater, u8 battlerId, u32 arg2, u8 ballId);

u8 GetBattlerSpriteFinal_Y(u8, u16, u8);

#endif // GUARD_BATTLE_ANIM_H
