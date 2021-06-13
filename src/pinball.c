#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pinball.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/rgb.h"

// In order to run the Pinball game, it should be launched via a normal script
// like the example below. VAR_RESULT is set to 1 if the player successfully
// completes the game, 0 otherwise.
//
// ...
// callnative PlayMeowthPinballGame
// waitstate
// ...

#define PINBALL_BG_TEXT        0
#define PINBALL_BG_BASE        1

#define WIN_TEXT 0

#define TAG_BALL_POKEBALL              500
#define TAG_FLIPPER                    501
#define TAG_MEOWTH                     502
#define TAG_MEOWTH_JEWEL               503
#define TAG_MEOWTH_JEWEL_MUTLIPLIER    504
#define TAG_TILES_MEOWTH_JEWEL_SPARKLE 505
#define TAG_DUGTRIO                    506
#define TAG_SEEL                       507
#define TAG_SEEL_SPARKLE               508
#define TAG_SEEL_MULTIPLIER            509
#define TAG_TIMER_DIGIT                510

enum
{
    GAME_TYPE_MEOWTH,
    GAME_TYPE_DIGLETT,
    GAME_TYPE_SEEL,
    GAME_TYPE_GENGAR,
};

enum
{
    PINBALL_STATE_INIT,
    PINBALL_STATE_RUNNING,
    PINBALL_LOST_BALL_FADE_OUT,
    PINBALL_LOST_BALL_FADE_IN,
    PINBALL_STATE_START_EXIT,
    PINBALL_STATE_DELAY_START_EXIT,
    PINBALL_STATE_EXIT,
    PINBALL_STATE_WAIT_ANIM,
};

struct Ball
{
    u8 spriteId;
    u32 xPos;
    u32 yPos;
    s16 xVelocity;
    s16 yVelocity;
    s8 spin;
    u8 rotation;
};

enum
{
    MEOWTH_STATE_WALK,
    MEOWTH_STATE_HIT,
    MEOWTH_STATE_FINISH,
};

enum
{
    MEOWTH_FACING_RIGHT,
    MEOWTH_FACING_LEFT,
};

enum
{
    JEWEL_STATE_HIDDEN,
    JEWEL_STATE_FALLING,
    JEWEL_STATE_LANDED,
    JEWEL_STATE_CONSUMED,
};

#define MAX_MEOWTH_JEWELS 6

struct MeowthJewel
{
    u8 state;
    u8 spriteId;
    u16 xPos;
    u16 yPos;
    s16 xVelocity;
    s16 yVelocity;
    u16 destYPos;
};

struct Meowth
{
    u8 spriteId;
    u8 sparkleSpriteId;
    u16 xPos;
    u16 yPos;
    int state;
    int facing;
    int yMovement;
    int hitDuration;
    struct MeowthJewel jewels[MAX_MEOWTH_JEWELS];
    int score;
    int jewelStreak;
    bool32 completed;
};

enum
{
    DIGLETT_STATE_INIT,
    DIGLETT_STATE_HIDDEN,
    DIGLETT_STATE_IDLE_0,
    DIGLETT_STATE_IDLE_1,
    DIGLETT_STATE_IDLE_2,
    DIGLETT_STATE_IDLE_3,
    DIGLETT_STATE_HIT_0,
    DIGLETT_STATE_HIT_1,
    DIGLETT_STATE_HIT_2,
};

enum
{
    DUGTRIO_STATE_HIDDEN,
    DUGTRIO_STATE_3ALIVE,
    DUGTRIO_STATE_3ALIVE_HIT,
    DUGTRIO_STATE_2ALIVE,
    DUGTRIO_STATE_2ALIVE_HIT,
    DUGTRIO_STATE_1ALIVE,
    DUGTRIO_STATE_1ALIVE_HIT,
    DUGTRIO_STATE_0ALIVE,
    DUGTRIO_STATE_COMPLETE,
};

#define NUM_DIGLETTS 31

struct Diglett
{
    bool32 completed;
    bool8 initialized;
    u8 curInitIndex;
    u8 curUpdateIndex;
    u8 states[NUM_DIGLETTS];
    u8 numDiglettsHit;
    u8 *collisionMap;
    u8 dugtrioSpriteId;
    u8 dugtrioState;
};

enum
{
    SEEL_STATE_SWIM_RIGHT,
    SEEL_STATE_TURN_LEFT,
    SEEL_STATE_SWIM_LEFT,
    SEEL_STATE_TURN_RIGHT,
    SEEL_STATE_EMERGE_RIGHT,
    SEEL_STATE_EMERGE_LEFT,
    SEEL_STATE_VISIBLE_RIGHT,
    SEEL_STATE_VISIBLE_LEFT,
    SEEL_STATE_SUBMERGE_RIGHT,
    SEEL_STATE_SUBMERGE_LEFT,
    SEEL_STATE_HIT_RIGHT,
    SEEL_STATE_HIT_LEFT,
};

struct SeelSwimmer
{
    u8 state;
    u8 spriteId;
    u16 xPos;
    u16 yPos;
    int counter;
};

#define NUM_SEELS 3

struct Seel
{
    bool32 completed;
    struct SeelSwimmer swimmers[NUM_SEELS];
    u8 streak;
    u8 score;
    u8 emergingSwimmerIndex;
    u8 emergingSwimmerCounter;
    u8 sparkleSpriteId;
};

struct Gengar
{
    bool32 completed;
};

#define FLIPPER_LEFT  0
#define FLIPPER_RIGHT 1

struct Flipper
{
    u8 type;
    u8 spriteId;
    u16 xPos;
    u16 yPos;
    int state;
    int prevState;
    int stateDelta;
};

struct Timer
{
    u32 ticks;
    u8 minutesSpriteId;
    u8 colonSpriteId;
    u8 tensSpriteId;
    u8 onesSpriteId;
};

struct PinballGame
{
    u8 state;
    u8 gameType;
    struct Ball ball;
    struct Flipper leftFlipper;
    struct Flipper rightFlipper;
    struct Timer timer;
    bool8 gravityEnabled;
    u8 stageTileWidth;
    u8 stageTileHeight;
    u16 cameraScrollX;
    u16 cameraScrollY;
    struct Meowth meowth;
    struct Diglett diglett;
    struct Seel seel;
    struct Gengar gengar;
    bool8 ballIsEntering;
    bool8 flippersDisabled;
    bool8 completed;
    u8 exitTimer;
    MainCallback returnMainCallback;
};

static void PlayPinballGame(u8 gameType);
static void FadeToPinballScreen(u8 taskId);
static void InitPinballScreen(void);
static void InitPinballGame(void);
static u32 GetTimerTicks(u8 gameType);
static void LoadBgGfx(u8 gameType);
static void LoadSpriteGfx(u8 gameType);
static void InitBallSprite(void);
static void InitFlipperSprites(void);
static void InitTimerSprites(void);
static bool32 GameTypeUsesTimer(u8 gameType);
static void GetTimerScreenCoords(u8 gameType, int *outX, int *outY);
static void InitGameType(u8 gameType);
static void InitMeowth(void);
static void InitDiglett(void);
static void InitSeel(void);
static void InitGengar(void);
static void PinballVBlankCallback(void);
static void PinballMainCallback(void);
static void PinballMain(u8 taskId);
static void StartNewBall(void);
static void LoseBall(void);
static bool32 PlayAnotherBall(void);
static void LostBall(u8 gameType);
static void LostBallMeowth(struct Meowth *meowth);
static void LostBallSeel(struct Seel *seel);
static void LostBallGengar(struct Gengar *gengar);
static void DrawMeowthScoreJewels(struct Meowth *meowth);
static void DrawSeelScoreJewels(struct Seel *seel);
static void OpenEntrance(u8 gameType);
static void OpenEntranceMeowth(void);
static void OpenEntranceDiglett(void);
static void OpenEntranceSeel(void);
static void OpenEntranceGengar(void);
static void CloseEntranceMeowth(void);
static void CloseEntranceDiglett(void);
static void CloseEntranceSeel(void);
static void CloseEntranceGengar(void);
static void HandleBallPhysics(void);
static void ApplyGravity(struct Ball *ball);
static void LimitVelocity(struct Ball *ball);
static bool32 HandleFlippers(struct Ball *ball, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification);
static void UpdateFlipperState(struct Flipper *flipper);
static bool32 CheckFlipperCollision(struct Ball *ball, struct Flipper *flipper, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification);
static void UpdatePosition(struct Ball *ball);
static bool32 CheckStaticCollision(u8 gameType, struct Ball *ball, bool32 ballIsEntering, int stageTileWidth, int stageTileHeight, u8 *outCollisionNormal, u16 *outYForce);
static u8 GetCollisionAttribute(u8 gameType, bool32 ballIsEntering, int index);
static u8 GetCollisionMaskRow(u8 gameType, int collisionAttribute, int row);
static void HandleStaticCollisionForGameType(u8 gameType, int x, int y, u8 collisionAttribute, u16 *outYForce);
static void HandleStaticCollisionDiglett(struct Diglett *diglett, int x, int y, u8 collisionAttribute);
static void HandleStaticCollisionGengar(struct Gengar *gengar, u8 collisionAttribute, u16 *outYForce);
static void RotateVector(s16 *x, s16 *y, u8 angle);
static u8 ReverseBits(u8 value);
static void ApplyCollisionForces(struct Ball *ball, u16 flipperYForce, int collisionAmplification);
static void UpdateCamera(void);
static void UpdateTimer(void);
static void HandleTimeRanOut(void);
static void DisableFlippers(void);
static void StartExitPinballGame(void);
static void ExitPinballGame(void);
static void UpdateBallSprite(struct Sprite *sprite);
static void UpdateFlipperSprite(struct Sprite *sprite);
static void UpdateTimerDigitSprite(struct Sprite *sprite);
static bool32 UpdateGameType(u8 gameType);
static bool32 UpdateMeowth(struct Meowth *meowth);
static bool32 CheckObjectsCollision(u8 gameType, struct Ball *ball, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification);
static bool32 CheckMeowthCollision(struct Ball *ball, struct Meowth *meowth, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification);
static bool32 CheckJewelCollision(struct Ball *ball, struct MeowthJewel *jewel, u8 *outCollisionNormal);
static bool32 IsJewelSpaceOccupied(u16 xPos, u16 destYPos, struct MeowthJewel *jewels);
static bool32 CheckMeowthJewelsCollision(struct Ball *ball, struct Meowth *meowth, u8 *outCollisionNormal);
static int GetNumActiveJewels(struct Meowth *meowth);
static struct MeowthJewel *TryCreateNewJewel(struct Meowth *meowth, int ballXPos);
static void UpdateJewels(struct MeowthJewel *jewels);
static void UpdateMeowthSprite(struct Sprite *sprite);
static void UpdateMeowthJewelSprite(struct Sprite *sprite);
static void UpdateMeowthJewelMultiplierSprite(struct Sprite *sprite);
static void ResetMeowthJewels(struct Meowth *meowth);
static void UpdateMeowthJewelSparkleSprite(struct Sprite *sprite);
static bool32 UpdateDiglett(struct Diglett *diglett);
static void UpdateDiglettTiles(u16 *tilemap, int index, struct Diglett *diglett);
static void UpdateDiglettCollision(u8 *collisionMap, int index, bool32 solidCollision);
static void UpdateDugtrioSprite(struct Sprite *sprite);
static bool32 CheckSeelCollision(struct Ball *ball, struct Seel *seel, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification);
static bool32 UpdateSeel(struct Seel *seel);
static void ResetSeels(struct Seel *seel);
static void ChooseNextEmergingSeel(int curSeelIndex, struct Seel *seel);
static u32 GetSeelVisibleTicks(int curStreak);
static void UpdateSeelSprite(struct Sprite *sprite);
static void UpdateSeelSparkleSprite(struct Sprite *sprite);
static void UpdateSeelMultiplierSprite(struct Sprite *sprite);
static bool32 UpdateGengar(struct Gengar *gengar);

static EWRAM_DATA struct PinballGame *sPinballGame = NULL;

static const struct BgTemplate sPinballBgTemplates[] = {
    {
       .bg = PINBALL_BG_TEXT,
       .charBaseIndex = 0,
       .mapBaseIndex = 27,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = PINBALL_BG_BASE,
       .charBaseIndex = 2,
       .mapBaseIndex = 28,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
};

static const struct WindowTemplate sPinballWinTemplates[] = {
    { // WIN_TEXT
        .bg = PINBALL_BG_TEXT,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    DUMMY_WIN_TEMPLATE,
};

// static const u32 sPinballBaseBgGfx[] = INCBIN_U32("graphics/pinball/base_bg_tiles.4bpp");
// static const u16 sPinballBaseBgPalette[] = INCBIN_U16("graphics/pinball/base_bg_tiles.gbapal");
// static const u32 sPinballBaseBgTilemap[] = INCBIN_U32("graphics/pinball/base_bg_tilemap.bin");
// static const u8 sPinballBaseBgCollisionMasks[] = INCBIN_U8("graphics/pinball/base_bg_collision_masks.1bpp");
// static const u8 sPinballBaseBgCollisionMap[] = INCBIN_U8("graphics/pinball/base_bg_collision_map.bin");
// static const u8 sFlipperLeftBaseCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_left_masks.1bpp");
// static const u8 sFlipperRightBaseCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_right_masks.1bpp");

static const u8 sFlipperLeftMeowthCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_left_masks_meowth.1bpp");
static const u8 sFlipperRightMeowthCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_right_masks_meowth.1bpp");

static const u32 sBallPokeballGfx[] = INCBIN_U32("graphics/pinball/ball_pokeball.4bpp.lz");
static const u16 sBallPokeballPalette[] = INCBIN_U16("graphics/pinball/ball_pokeball.gbapal");
static const u32 sFlipperGfx[] = INCBIN_U32("graphics/pinball/flipper.4bpp.lz");
static const u16 sFlipperPalette[] = INCBIN_U16("graphics/pinball/flipper.gbapal");
static const u32 sTimerDigitsGfx[] = INCBIN_U32("graphics/pinball/timer_digits.4bpp.lz");
static const u16 sTimerDigitsPalette[] = INCBIN_U16("graphics/pinball/timer_digits.gbapal");

static const u8 sFlipperCollisionRadii[] = INCBIN_U8("data/pinball/flipper_radii.bin");
static const u8 sFlipperCollisionNormalAngles[] = INCBIN_U8("data/pinball/flipper_normal_angles.bin");

static const u32 sMeowthStageBgGfx[] = INCBIN_U32("graphics/pinball/bg_tiles_meowth.4bpp");
static const u16 sMeowthStageBgPalette[] = INCBIN_U16("graphics/pinball/bg_tiles_meowth.gbapal");
static const u16 sMeowthStageBgTilemap[] = INCBIN_U16("graphics/pinball/bg_tilemap_meowth.bin");
static const u8 sMeowthStageBgCollisionMasks[] = INCBIN_U8("graphics/pinball/bg_collision_masks_meowth.1bpp");
static const u8 sMeowthStageBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_meowth.bin");
static const u8 sMeowthStageEntranceBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_meowth_entrance.bin");
static const u32 sMeowthAnimationGfx[] = INCBIN_U32("graphics/pinball/meowth_animation.4bpp.lz");
static const u16 sMeowthAnimationPalette[] = INCBIN_U16("graphics/pinball/meowth_animation.gbapal");
static const u32 sMeowthJewelGfx[] = INCBIN_U32("graphics/pinball/meowth_jewel_animation.4bpp.lz");
static const u16 sMeowthJewelPalette[] = INCBIN_U16("graphics/pinball/meowth_jewel_animation.gbapal");
static const u32 sMeowthJewelMultipliersGfx[] = INCBIN_U32("graphics/pinball/meowth_jewel_multipliers.4bpp.lz");
static const u32 sMeowthJewelSparkleGfx[] = INCBIN_U32("graphics/pinball/meowth_sparkle.4bpp.lz");
static const u16 sMeowthJewelMultipliersPalette[] = INCBIN_U16("graphics/pinball/meowth_jewel_multipliers.gbapal");
static const u8 sMeowthCollisionNormalAngles[] = INCBIN_U8("data/pinball/meowth_normal_angles.bin");
static const u8 sMeowthJewelCollisionNormalAngles[] = INCBIN_U8("data/pinball/meowth_jewel_normal_angles.bin");

static const u32 sDiglettStageBgGfx[] = INCBIN_U32("graphics/pinball/bg_tiles_diglett.4bpp");
static const u16 sDiglettStageBgPalette[] = INCBIN_U16("graphics/pinball/bg_tiles_diglett.gbapal");
static const u16 sDiglettStageBgTilemap[] = INCBIN_U16("graphics/pinball/bg_tilemap_diglett.bin");
static const u8 sDiglettStageBgCollisionMasks[] = INCBIN_U8("graphics/pinball/bg_collision_masks_diglett.1bpp");
static const u8 sDiglettStageBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_diglett.bin");
static const u8 sDiglettStageEntranceBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_diglett_entrance.bin");
static const u32 sDugtrioAnimationGfx[] = INCBIN_U32("graphics/pinball/dugtrio_animation.4bpp.lz");
static const u16 sDugtrioAnimationPalette[] = INCBIN_U16("graphics/pinball/dugtrio_animation.gbapal");

static const u32 sSeelStageBgGfx[] = INCBIN_U32("graphics/pinball/bg_tiles_seel.4bpp");
static const u16 sSeelStageBgPalette[] = INCBIN_U16("graphics/pinball/bg_tiles_seel.gbapal");
static const u16 sSeelStageBgTilemap[] = INCBIN_U16("graphics/pinball/bg_tilemap_seel.bin");
static const u8 sSeelStageBgCollisionMasks[] = INCBIN_U8("graphics/pinball/bg_collision_masks_seel.1bpp");
static const u8 sSeelStageBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_seel.bin");
static const u8 sSeelStageEntranceBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_seel_entrance.bin");
static const u32 sSeelAnimationGfx[] = INCBIN_U32("graphics/pinball/seel_animation.4bpp.lz");
static const u16 sSeelAnimationPalette[] = INCBIN_U16("graphics/pinball/seel_animation.gbapal");
static const u8 sSeelCollisionNormalAngles[] = INCBIN_U8("data/pinball/seel_normal_angles.bin");
static const u32 sSeelSparkleGfx[] = INCBIN_U32("graphics/pinball/seel_sparkle.4bpp.lz");
static const u16 sSeelSparklePalette[] = INCBIN_U16("graphics/pinball/seel_sparkle.gbapal");
static const u32 sSeelMultipliersGfx[] = INCBIN_U32("graphics/pinball/seel_multipliers.4bpp.lz");
static const u16 sSeelMultipliersPalette[] = INCBIN_U16("graphics/pinball/seel_multipliers.gbapal");

static const u32 sGengarStageBgGfx[] = INCBIN_U32("graphics/pinball/bg_tiles_gengar.4bpp");
static const u16 sGengarStageBgPalette[] = INCBIN_U16("graphics/pinball/bg_tiles_gengar.gbapal");
static const u16 sGengarStageBgTilemap[] = INCBIN_U16("graphics/pinball/bg_tilemap_gengar.bin");
static const u8 sGengarStageBgCollisionMasks[] = INCBIN_U8("graphics/pinball/bg_collision_masks_gengar.1bpp");
static const u8 sGengarStageBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_gengar.bin");
static const u8 sGengarStageEntranceBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_gengar_entrance.bin");

static const struct CompressedSpriteSheet sBallPokeballSpriteSheet = {
    .data = sBallPokeballGfx,
    .size = 0x400,
    .tag = TAG_BALL_POKEBALL,
};

static const struct CompressedSpriteSheet sFlipperSpriteSheet = {
    .data = sFlipperGfx,
    .size = 0x600,
    .tag = TAG_FLIPPER,
};

static const struct CompressedSpriteSheet sTimerDigitsSpriteSheet = {
    .data = sTimerDigitsGfx,
    .size = 0x2C0,
    .tag = TAG_TIMER_DIGIT,
};

static const struct CompressedSpriteSheet sMeowthAnimationSpriteSheet = {
    .data = sMeowthAnimationGfx,
    .size = 0xA00,
    .tag = TAG_MEOWTH,
};

static const struct CompressedSpriteSheet sMeowthJewelSpriteSheet = {
    .data = sMeowthJewelGfx,
    .size = 0x400,
    .tag = TAG_MEOWTH_JEWEL,
};

static const struct CompressedSpriteSheet sMeowthJewelMultipliersSpriteSheet = {
    .data = sMeowthJewelMultipliersGfx,
    .size = 0x140,
    .tag = TAG_MEOWTH_JEWEL_MUTLIPLIER,
};

static const struct CompressedSpriteSheet sMeowthSparkleSpriteSheet = {
    .data = sMeowthJewelSparkleGfx,
    .size = 0x40,
    .tag = TAG_TILES_MEOWTH_JEWEL_SPARKLE,
};

static const struct CompressedSpriteSheet sDugtrioAnimationSpriteSheet = {
    .data = sDugtrioAnimationGfx,
    .size = 0x1A00,
    .tag = TAG_DUGTRIO,
};

static const struct CompressedSpriteSheet sSeelAnimationSpriteSheet = {
    .data = sSeelAnimationGfx,
    .size = 0x1E00,
    .tag = TAG_SEEL,
};

static const struct CompressedSpriteSheet sSeelSparkleSpriteSheet = {
    .data = sSeelSparkleGfx,
    .size = 0x40,
    .tag = TAG_SEEL_SPARKLE,
};

static const struct CompressedSpriteSheet sSeelMultipliersSpriteSheet = {
    .data = sSeelMultipliersGfx,
    .size = 0x1C0,
    .tag = TAG_SEEL_MULTIPLIER,
};

static const struct SpritePalette sPinballSpritePalette = { sBallPokeballPalette, TAG_BALL_POKEBALL };
static const struct SpritePalette sFlipperSpritePalette = { sFlipperPalette, TAG_FLIPPER };
static const struct SpritePalette sTimerDigitsSpritePalette = { sTimerDigitsPalette, TAG_TIMER_DIGIT };
static const struct SpritePalette sMeowthAnimationSpritePalette = { sMeowthAnimationPalette, TAG_MEOWTH };
static const struct SpritePalette sMeowthJewelSpritePalette = { sMeowthJewelPalette, TAG_MEOWTH_JEWEL };
static const struct SpritePalette sMeowthJewelMultipliersSpritePalette = { sMeowthJewelMultipliersPalette, TAG_MEOWTH_JEWEL_MUTLIPLIER };
static const struct SpritePalette sDugtrioAnimationSpritePalette = { sDugtrioAnimationPalette, TAG_DUGTRIO };
static const struct SpritePalette sSeelAnimationSpritePalette = { sSeelAnimationPalette, TAG_SEEL };
static const struct SpritePalette sSeelSparkleSpritePalette = { sSeelSparklePalette, TAG_SEEL_SPARKLE };
static const struct SpritePalette sSeelMultipliersSpritePalette = { sSeelMultipliersPalette, TAG_SEEL_MULTIPLIER };

static const struct OamData sBallOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define BALL_FRAME_ANIMCMD(n) \
static const union AnimCmd sBallAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 4, 0),\
    ANIMCMD_END,\
};

BALL_FRAME_ANIMCMD(0)
BALL_FRAME_ANIMCMD(1)
BALL_FRAME_ANIMCMD(2)
BALL_FRAME_ANIMCMD(3)
BALL_FRAME_ANIMCMD(4)
BALL_FRAME_ANIMCMD(5)
BALL_FRAME_ANIMCMD(6)
BALL_FRAME_ANIMCMD(7)

static const union AnimCmd *const sBallAnimCmds[] = {
    sBallAnimCmd_0,
    sBallAnimCmd_1,
    sBallAnimCmd_2,
    sBallAnimCmd_3,
    sBallAnimCmd_4,
    sBallAnimCmd_5,
    sBallAnimCmd_6,
    sBallAnimCmd_7,
};

static const struct SpriteTemplate sBallPokeballSpriteTemplate = {
    .tileTag = TAG_BALL_POKEBALL,
    .paletteTag = TAG_BALL_POKEBALL,
    .oam = &sBallOamData,
    .anims = sBallAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateBallSprite,
};

static const struct OamData sFlipperOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define FLIPPER_FRAME_ANIMCMD(n, flip) \
static const union AnimCmd sFlipperAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME(((n) % 3) * 16, 0, .hFlip = (flip)),\
    ANIMCMD_END,\
};

FLIPPER_FRAME_ANIMCMD(0, FALSE)
FLIPPER_FRAME_ANIMCMD(1, FALSE)
FLIPPER_FRAME_ANIMCMD(2, FALSE)
FLIPPER_FRAME_ANIMCMD(3, TRUE)
FLIPPER_FRAME_ANIMCMD(4, TRUE)
FLIPPER_FRAME_ANIMCMD(5, TRUE)

static const union AnimCmd *const sFlipperAnimCmds[] = {
    sFlipperAnimCmd_0,
    sFlipperAnimCmd_1,
    sFlipperAnimCmd_2,
    sFlipperAnimCmd_3,
    sFlipperAnimCmd_4,
    sFlipperAnimCmd_5,
};

static const struct SpriteTemplate sFlipperSpriteTemplate = {
    .tileTag = TAG_FLIPPER,
    .paletteTag = TAG_FLIPPER,
    .oam = &sFlipperOamData,
    .anims = sFlipperAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateFlipperSprite,
};

static const struct OamData sTimerDigitOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

#define TIMER_DIGIT_FRAME_ANIMCMD(n) \
static const union AnimCmd sTimerDigitAnimCmd_##n[] =\
{\
    ANIMCMD_FRAME((n) * 2, 0),\
    ANIMCMD_END,\
};

TIMER_DIGIT_FRAME_ANIMCMD(0)
TIMER_DIGIT_FRAME_ANIMCMD(1)
TIMER_DIGIT_FRAME_ANIMCMD(2)
TIMER_DIGIT_FRAME_ANIMCMD(3)
TIMER_DIGIT_FRAME_ANIMCMD(4)
TIMER_DIGIT_FRAME_ANIMCMD(5)
TIMER_DIGIT_FRAME_ANIMCMD(6)
TIMER_DIGIT_FRAME_ANIMCMD(7)
TIMER_DIGIT_FRAME_ANIMCMD(8)
TIMER_DIGIT_FRAME_ANIMCMD(9)
TIMER_DIGIT_FRAME_ANIMCMD(10)

static const union AnimCmd *const sTimerDigitAnimCmds[] = {
    sTimerDigitAnimCmd_0,
    sTimerDigitAnimCmd_1,
    sTimerDigitAnimCmd_2,
    sTimerDigitAnimCmd_3,
    sTimerDigitAnimCmd_4,
    sTimerDigitAnimCmd_5,
    sTimerDigitAnimCmd_6,
    sTimerDigitAnimCmd_7,
    sTimerDigitAnimCmd_8,
    sTimerDigitAnimCmd_9,
    sTimerDigitAnimCmd_10,
};

static const struct SpriteTemplate sTimerDigitSpriteTemplate = {
    .tileTag = TAG_TIMER_DIGIT,
    .paletteTag = TAG_TIMER_DIGIT,
    .oam = &sTimerDigitOamData,
    .anims = sTimerDigitAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateTimerDigitSprite,
};

static const struct OamData sMeowthOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sMeowthAnimCmd_WalkRight[] = {
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(16, 15),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMeowthAnimCmd_WalkLeft[] = {
    ANIMCMD_FRAME(0, 15, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 15, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sMeowthAnimCmd_HitRight[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthAnimCmd_HitLeft[] = {
    ANIMCMD_FRAME(32, 0, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthAnimCmd_Finish[] = {
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMeowthAnimCmds[] = {
    sMeowthAnimCmd_WalkRight,
    sMeowthAnimCmd_WalkLeft,
    sMeowthAnimCmd_HitRight,
    sMeowthAnimCmd_HitLeft,
    sMeowthAnimCmd_Finish,
};

static const struct SpriteTemplate sMeowthSpriteTemplate = {
    .tileTag = TAG_MEOWTH,
    .paletteTag = TAG_MEOWTH,
    .oam = &sMeowthOamData,
    .anims = sMeowthAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateMeowthSprite,
};

static const struct OamData sMeowthJewelOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sMeowthJewelAnimCmd_Create[] = {
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelAnimCmd_Sparkle[] = {
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelAnimCmd_Disappear[] = {
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_FRAME(28, 1),
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sMeowthJewelAnimCmds[] = {
    sMeowthJewelAnimCmd_Create,
    sMeowthJewelAnimCmd_Sparkle,
    sMeowthJewelAnimCmd_Disappear,
};

static const struct SpriteTemplate sMeowthJewelSpriteTemplate = {
    .tileTag = TAG_MEOWTH_JEWEL,
    .paletteTag = TAG_MEOWTH_JEWEL,
    .oam = &sMeowthJewelOamData,
    .anims = sMeowthJewelAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateMeowthJewelSprite,
};

static const struct OamData sMeowthJewelMultiplierOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sMeowthJewelMultiplierAnimCmd_2x[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelMultiplierAnimCmd_3x[] = {
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelMultiplierAnimCmd_4x[] = {
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelMultiplierAnimCmd_5x[] = {
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_END,
};

static const union AnimCmd sMeowthJewelMultiplierAnimCmd_6x[] = {
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sMeowthJewelMultiplierAnimCmds[] = {
    sMeowthJewelMultiplierAnimCmd_2x,
    sMeowthJewelMultiplierAnimCmd_3x,
    sMeowthJewelMultiplierAnimCmd_4x,
    sMeowthJewelMultiplierAnimCmd_5x,
    sMeowthJewelMultiplierAnimCmd_6x,
};

static const struct SpriteTemplate sMeowthJewelMultiplierSpriteTemplate = {
    .tileTag = TAG_MEOWTH_JEWEL_MUTLIPLIER,
    .paletteTag = TAG_MEOWTH_JEWEL_MUTLIPLIER,
    .oam = &sMeowthJewelMultiplierOamData,
    .anims = sMeowthJewelMultiplierAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateMeowthJewelMultiplierSprite,
};

static const struct OamData sMeowthJewelSparkleOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sMeowthJewelSparkleAnimCmd_0[] = {
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMeowthJewelSparkleAnimCmds[] = {
    sMeowthJewelSparkleAnimCmd_0,
};

static const struct SpriteTemplate sMeowthJewelSparkleSpriteTemplate = {
    .tileTag = TAG_TILES_MEOWTH_JEWEL_SPARKLE,
    .paletteTag = TAG_MEOWTH_JEWEL_MUTLIPLIER,
    .oam = &sMeowthJewelSparkleOamData,
    .anims = sMeowthJewelSparkleAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateMeowthJewelSparkleSprite,
};

static const u8 sDiglettStateTiles[][4] = {
    [DIGLETT_STATE_INIT] = {0x4C, 0x4D, 0x4E, 0x4F},
    [DIGLETT_STATE_HIDDEN] = {0x4C, 0x4D, 0x4E, 0x4F},
    [DIGLETT_STATE_IDLE_0] = {0x3C, 0x3D, 0x3E, 0x3F},
    [DIGLETT_STATE_IDLE_1] = {0x44, 0x45, 0x46, 0x47},
    [DIGLETT_STATE_IDLE_2] = {0x3C, 0x3D, 0x3E, 0x3F},
    [DIGLETT_STATE_IDLE_3] = {0x40, 0x41, 0x42, 0x43},
    [DIGLETT_STATE_HIT_0]  = {0x48, 0x49, 0x4A, 0x4B},
    [DIGLETT_STATE_HIT_1]  = {0x48, 0x49, 0x4A, 0x4B},
    [DIGLETT_STATE_HIT_2]  = {0x48, 0x49, 0x4A, 0x4B},
};

static const u8 sDiglettCoords[NUM_DIGLETTS][2] = {
    {1, 3},
    {1, 5},
    {1, 7},
    {3, 4},
    {3, 6},
    {3, 8},
    {5, 3},
    {5, 5},
    {5, 7},
    {5, 9},
    {7, 4},
    {7, 6},
    {7, 8},
    {7, 10},
    {9, 5},
    {9, 7},
    {9, 9},
    {11, 4},
    {11, 6},
    {11, 8},
    {11, 10},
    {13, 3},
    {13, 5},
    {13, 7},
    {13, 9},
    {15, 4},
    {15, 6},
    {15, 8},
    {17, 3},
    {17, 5},
    {17, 7},
};

static const u8 sDiglettInitOrder[NUM_DIGLETTS] = { 0, 28, 1, 29, 3, 25, 6, 21, 2, 30, 4, 26, 7, 22, 10, 17, 5, 27, 8, 23, 11, 18, 14, 9, 24, 12, 19, 15, 13, 20, 16 };

static const struct OamData sDugtrioOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sDugtrioAnimCmd_Hidden[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sDugtrioAnimCmd_3Alive[] = {
    ANIMCMD_FRAME(16, 14),
    ANIMCMD_FRAME(32, 14),
    ANIMCMD_FRAME(48, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sDugtrioAnimCmd_3AliveHit[] = {
    ANIMCMD_FRAME(64, 12),
    ANIMCMD_END,
};

static const union AnimCmd sDugtrioAnimCmd_2Alive[] = {
    ANIMCMD_FRAME(80, 14),
    ANIMCMD_FRAME(96, 14),
    ANIMCMD_FRAME(112, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sDugtrioAnimCmd_2AliveHit[] = {
    ANIMCMD_FRAME(128, 12),
    ANIMCMD_END,
};

static const union AnimCmd sDugtrioAnimCmd_1Alive[] = {
    ANIMCMD_FRAME(144, 14),
    ANIMCMD_FRAME(160, 28),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sDugtrioAnimCmd_1AliveHit[] = {
    ANIMCMD_FRAME(176, 12),
    ANIMCMD_END,
};

static const union AnimCmd sDugtrioAnimCmd_0Alive[] = {
    ANIMCMD_FRAME(192, 33), // We want a duration of 66 frames, but 63 is the maximum an ANIMCMD_FRAME can hold.
    ANIMCMD_FRAME(192, 33),
    ANIMCMD_END,
};

static const union AnimCmd *const sDugtrioAnimCmds[] = {
    sDugtrioAnimCmd_Hidden,
    sDugtrioAnimCmd_3Alive,
    sDugtrioAnimCmd_3AliveHit,
    sDugtrioAnimCmd_2Alive,
    sDugtrioAnimCmd_2AliveHit,
    sDugtrioAnimCmd_1Alive,
    sDugtrioAnimCmd_1AliveHit,
    sDugtrioAnimCmd_0Alive,
};

static const struct SpriteTemplate sDugtrioSpriteTemplate = {
    .tileTag = TAG_DUGTRIO,
    .paletteTag = TAG_DUGTRIO,
    .oam = &sDugtrioOamData,
    .anims = sDugtrioAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateDugtrioSprite,
};

static const struct OamData sSeelOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSeelAnimCmd_SwimRight[] = {
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 13),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSeelAnimCmd_TurnLeft[] = {
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(64, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_SwimLeft[] = {
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 13, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 12, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSeelAnimCmd_TurnRight[] = {
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(80, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_EmergeRight[] = {
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(144, 8),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_EmergeLeft[] = {
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(144, 8),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_Visible[] = {
    ANIMCMD_FRAME(160, 30),
    ANIMCMD_FRAME(176, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSeelAnimCmd_SubmergeRight[] = {
    ANIMCMD_FRAME(144, 9),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 6),
    ANIMCMD_FRAME(224, 16),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(64, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_SubmergeLeft[] = {
    ANIMCMD_FRAME(144, 9),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 6),
    ANIMCMD_FRAME(224, 16),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_HitRight[] = {
    ANIMCMD_FRAME(208, 16),
    ANIMCMD_FRAME(192, 6),
    ANIMCMD_FRAME(224, 16),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(64, 4, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSeelAnimCmd_HitLeft[] = {
    ANIMCMD_FRAME(208, 16),
    ANIMCMD_FRAME(192, 6),
    ANIMCMD_FRAME(224, 16),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(80, 6),
    ANIMCMD_FRAME(112, 5),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(64, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 4, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sSeelAnimCmds[] = {
    sSeelAnimCmd_SwimRight,
    sSeelAnimCmd_TurnLeft,
    sSeelAnimCmd_SwimLeft,
    sSeelAnimCmd_TurnRight,
    sSeelAnimCmd_EmergeRight,
    sSeelAnimCmd_EmergeLeft,
    sSeelAnimCmd_Visible,
    sSeelAnimCmd_SubmergeRight,
    sSeelAnimCmd_SubmergeLeft,
    sSeelAnimCmd_HitRight,
    sSeelAnimCmd_HitLeft,
};

static const struct SpriteTemplate sSeelSpriteTemplate = {
    .tileTag = TAG_SEEL,
    .paletteTag = TAG_SEEL,
    .oam = &sSeelOamData,
    .anims = sSeelAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSeelSprite,
};

static const u8 sInitialSeelStates[NUM_SEELS] = {
    SEEL_STATE_SWIM_RIGHT,
    SEEL_STATE_SWIM_LEFT,
    SEEL_STATE_SWIM_RIGHT,
};

static const u8 sInitialSeelCoords[NUM_SEELS][2] = {
    {110, 30},
    {46, 56},
    {78, 82},
};

static const struct OamData sSeelSparkleOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSeelSparkleAnimCmd_0[] = {
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSeelSparkleAnimCmds[] = {
    sSeelSparkleAnimCmd_0,
};

static const struct SpriteTemplate sSeelSparkleSpriteTemplate = {
    .tileTag = TAG_SEEL_SPARKLE,
    .paletteTag = TAG_SEEL_SPARKLE,
    .oam = &sSeelSparkleOamData,
    .anims = sSeelSparkleAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSeelSparkleSprite,
};

static const struct OamData sSeelMultiplierOamData = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSeelMultiplierAnimCmd_2x[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_3x[] = {
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_4x[] = {
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_5x[] = {
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_6x[] = {
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_7x[] = {
    ANIMCMD_FRAME(10, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSeelMultiplierAnimCmd_8x[] = {
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sSeelMultiplierAnimCmds[] = {
    sSeelMultiplierAnimCmd_2x,
    sSeelMultiplierAnimCmd_3x,
    sSeelMultiplierAnimCmd_4x,
    sSeelMultiplierAnimCmd_5x,
    sSeelMultiplierAnimCmd_6x,
    sSeelMultiplierAnimCmd_7x,
    sSeelMultiplierAnimCmd_8x,
};

static const struct SpriteTemplate sSeelMultiplierSpriteTemplate = {
    .tileTag = TAG_SEEL_MULTIPLIER,
    .paletteTag = TAG_SEEL_MULTIPLIER,
    .oam = &sSeelMultiplierOamData,
    .anims = sSeelMultiplierAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSeelMultiplierSprite,
};

static const u8 sGengarGravestoneCollisionAttributes[] = {0x19, 0x1A, 0x1B, 0x1C, 0x27, 0x1D, 0x1E, 0x1F, 0x20};

static const s8 sCollisionTestPointOffsets[][2] = {
    {  4,  0 },
    {  4,  1 },
    {  3,  3 },
    {  1,  4 },
    {  0,  4 },
    { -1,  4 },
    { -3,  3 },
    { -4,  1 },
    { -4,  0 },
    { -4, -1 },
    { -3, -3 },
    { -1, -4 },
    {  0, -4 },
    {  1, -4 },
    {  3, -3 },
    {  4, -1 },
};

// This array is indexed by the start and end indexes of the 16 collision point tests.
// The values here are on a 256-degree'd unit circle, where an angle of 0x00 is pointing
// directly up, 0x40 is pointing directly right, 0x80 is pointing directly down, and
// 0xC0 is pointing directly left.
static const u8 sCollisionNormals[256] = {
    0xC0, 0xC5, 0xD0, 0xDB, 0xE0, 0xE5, 0xF0, 0xFB, 0x00, 0x05, 0x10, 0x1B, 0x20, 0x25, 0x30, 0x3B, // 0x0X
    0x45, 0xCA, 0xD5, 0xE0, 0xE5, 0xEA, 0xF5, 0x00, 0x05, 0x0A, 0x15, 0x20, 0x25, 0x2A, 0x35, 0x40, // 0x1X
    0x50, 0x55, 0xE0, 0xEB, 0xF0, 0xF5, 0x00, 0x0B, 0x10, 0x15, 0x20, 0x2B, 0x30, 0x35, 0x40, 0x4B, // 0x2X
    0x5B, 0x60, 0x6B, 0xF6, 0xFB, 0x00, 0x0B, 0x16, 0x1B, 0x20, 0x2B, 0x36, 0x3B, 0x40, 0x4B, 0x56, // 0x3X
    0x60, 0x65, 0x70, 0x7B, 0x00, 0x05, 0x10, 0x1B, 0x20, 0x25, 0x30, 0x3B, 0x40, 0x45, 0x50, 0x5B, // 0x4X
    0x65, 0x6A, 0x75, 0x80, 0x85, 0x0A, 0x15, 0x20, 0x25, 0x2A, 0x35, 0x40, 0x45, 0x4A, 0x55, 0x60, // 0x5X
    0x70, 0x75, 0x80, 0x8B, 0x90, 0x95, 0x20, 0x2B, 0x30, 0x35, 0x40, 0x4B, 0x50, 0x55, 0x60, 0x6B, // 0x6X
    0x7B, 0x80, 0x8B, 0x96, 0x9B, 0xA0, 0xAB, 0x36, 0x3B, 0x40, 0x4B, 0x56, 0x5B, 0x60, 0x6B, 0x76, // 0x7X
    0x80, 0x85, 0x90, 0x9B, 0xA0, 0xA5, 0xB0, 0xBB, 0x40, 0x45, 0x50, 0x5B, 0x60, 0x65, 0x70, 0x7B, // 0x8X
    0x85, 0x8A, 0x95, 0xA0, 0xA5, 0xAA, 0xB5, 0xC0, 0xC5, 0x4A, 0x55, 0x60, 0x65, 0x6A, 0x75, 0x80, // 0x9X
    0x90, 0x95, 0xA0, 0xAB, 0xB0, 0xB5, 0xC0, 0xCB, 0xD0, 0xD5, 0x60, 0x6B, 0x70, 0x75, 0x80, 0x8B, // 0xAX
    0x9B, 0xA0, 0xAB, 0xB6, 0xBB, 0xC0, 0xCB, 0xD6, 0xDB, 0xE0, 0xEB, 0x76, 0x7B, 0x80, 0x8B, 0x96, // 0xBX
    0xA0, 0xA5, 0xB0, 0xBB, 0xC0, 0xC5, 0xD0, 0xDB, 0xE0, 0xE5, 0xF0, 0xFB, 0x80, 0x85, 0x90, 0x9B, // 0xCX
    0xA5, 0xAA, 0xB5, 0xC0, 0xC5, 0xCA, 0xD5, 0xE0, 0xE5, 0xEA, 0xF5, 0x00, 0x05, 0x8A, 0x95, 0xA0, // 0xDX
    0xB0, 0xB5, 0xC0, 0xCB, 0xD0, 0xD5, 0xE0, 0xEB, 0xF0, 0xF5, 0x00, 0x0B, 0x10, 0x15, 0xA0, 0xAB, // 0xEX
    0xBB, 0xC0, 0xCB, 0xD6, 0xDB, 0xE0, 0xEB, 0xF6, 0xFB, 0x00, 0x0B, 0x16, 0x1B, 0x20, 0x2B, 0xB6, // 0xFX
};

// This array is indexed by the start and end indexes of the 16 collision point tests.
// It is used to move the ball out of the the wall it's colliding with.
static const u16 sCollisionXDeltas[256] = {
    0xFF00, 0xFEFB, 0xFECC, 0xFE8C, 0xFE77, 0xFE71, 0xFEAD, 0xFF73, 0x0000, 0x00AC, 0x027F, 0x0497, 0x0589, 0x066D, 0x0808, 0x08E7, // 0x0X
    0x08E7, 0xFF08, 0xFF01, 0xFEE4, 0xFEDE, 0xFEE3, 0xFF32, 0x0000, 0x008D, 0x0137, 0x02FD, 0x04FD, 0x05E1, 0x06B6, 0x082C, 0x08E1, // 0x1X
    0x0808, 0x07B4, 0xFF4B, 0xFF70, 0xFF81, 0xFF99, 0x0000, 0x00CE, 0x0153, 0x01F0, 0x0389, 0x0547, 0x0608, 0x06B8, 0x07D4, 0x082C, // 0x2X
    0x066D, 0x05F6, 0x045D, 0xFFC2, 0xFFE0, 0x0000, 0x0067, 0x011D, 0x018F, 0x0214, 0x036C, 0x04D9, 0x0572, 0x05F8, 0x06B8, 0x06B6, // 0x3X
    0x0589, 0x0504, 0x0353, 0x0119, 0x0000, 0x0020, 0x007F, 0x0122, 0x0189, 0x0200, 0x0334, 0x0479, 0x04FF, 0x0572, 0x0608, 0x05E1, // 0x4X
    0x0497, 0x0406, 0x0243, 0x0000, 0xFEE7, 0x003E, 0x0090, 0x011C, 0x0174, 0x01DC, 0x02EB, 0x0407, 0x0479, 0x04D9, 0x0547, 0x04FD, // 0x5X
    0x027F, 0x01DC, 0x0000, 0xFDBD, 0xFCAD, 0xFBA3, 0x00B5, 0x00FF, 0x0134, 0x0176, 0x022B, 0x02EB, 0x0334, 0x036C, 0x0389, 0x02FD, // 0x6X
    0x00AC, 0x0000, 0xFE24, 0xFBFA, 0xFAFC, 0xFA0A, 0xF84C, 0x00F8, 0x0105, 0x011E, 0x0176, 0x01DC, 0x0200, 0x0214, 0x01F0, 0x0137, // 0x7X
    0x0000, 0xFF54, 0xFD81, 0xFB69, 0xFA77, 0xF993, 0xF7F8, 0xF719, 0x0100, 0x0105, 0x0134, 0x0174, 0x0189, 0x018F, 0x0153, 0x008D, // 0x8X
    0xFF73, 0xFEC9, 0xFD03, 0xFB03, 0xFA1F, 0xF94A, 0xF7D4, 0xF71F, 0xF719, 0x00F8, 0x00FF, 0x011C, 0x0122, 0x011D, 0x00CE, 0x0000, // 0x9X
    0xFEAD, 0xFE10, 0xFC77, 0xFAB9, 0xF9F8, 0xF948, 0xF82C, 0xF7D4, 0xF7F8, 0xF84C, 0x00B5, 0x0090, 0x007F, 0x0067, 0x0000, 0xFF32, // 0xAX
    0xFE71, 0xFDEC, 0xFC94, 0xFB27, 0xFA8E, 0xFA08, 0xF948, 0xF94A, 0xF993, 0xFA0A, 0xFBA3, 0x003E, 0x0020, 0x0000, 0xFF99, 0xFEE3, // 0xBX
    0xFE77, 0xFE00, 0xFCCC, 0xFB87, 0xFB01, 0xFA8E, 0xF9F8, 0xFA1F, 0xFA77, 0xFAFC, 0xFCAD, 0xFEE7, 0x0000, 0xFFE0, 0xFF81, 0xFEDE, // 0xCX
    0xFE8C, 0xFE24, 0xFD15, 0xFBF9, 0xFB87, 0xFB27, 0xFAB9, 0xFB03, 0xFB69, 0xFBFA, 0xFDBD, 0x0000, 0x0119, 0xFFC2, 0xFF70, 0xFEE4, // 0xDX
    0xFECC, 0xFE8A, 0xFDD5, 0xFD15, 0xFCCC, 0xFC94, 0xFC77, 0xFD03, 0xFD81, 0xFE24, 0x0000, 0x0243, 0x0353, 0x045D, 0xFF4B, 0xFF01, // 0xEX
    0xFEFB, 0xFEE2, 0xFE8A, 0xFE24, 0xFE00, 0xFDEC, 0xFE10, 0xFEC9, 0xFF54, 0x0000, 0x01DC, 0x0406, 0x0504, 0x05F6, 0x07B4, 0xFF08, // 0xFX
};

// This array is indexed by the start and end indexes of the 16 collision point tests.
// It is used to move the ball out of the the wall it's colliding with.
static const u16 sCollisionYDeltas[256] = {
    0x0000, 0xFFE0, 0xFF81, 0xFEDE, 0xFE77, 0xFE00, 0xFCCC, 0xFB87, 0xFB01, 0xFA8E, 0xF9F8, 0xFA1F, 0xFA77, 0xFAFC, 0xFCAD, 0xFEE7, // 0x0X
    0x0119, 0xFFC2, 0xFF70, 0xFEE4, 0xFE8C, 0xFE24, 0xFD15, 0xFBF9, 0xFB87, 0xFB27, 0xFAB9, 0xFB03, 0xFB69, 0xFBFA, 0xFDBD, 0x0000, // 0x1X
    0x0353, 0x045D, 0xFF4B, 0xFF01, 0xFECC, 0xFE8A, 0xFDD5, 0xFD15, 0xFCCC, 0xFC94, 0xFC77, 0xFD03, 0xFD81, 0xFE24, 0x0000, 0x0243, // 0x2X
    0x0504, 0x05F6, 0x07B4, 0xFF08, 0xFEFB, 0xFEE2, 0xFE8A, 0xFE24, 0xFE00, 0xFDEC, 0xFE10, 0xFEC9, 0xFF54, 0x0000, 0x01DC, 0x0406, // 0x3X
    0x0589, 0x066D, 0x0808, 0x08E7, 0xFF00, 0xFEFB, 0xFECC, 0xFE8C, 0xFE77, 0xFE71, 0xFEAD, 0xFF73, 0x0000, 0x00AC, 0x027F, 0x0497, // 0x4X
    0x05E1, 0x06B6, 0x082C, 0x08E1, 0x08E7, 0xFF08, 0xFF01, 0xFEE4, 0xFEDE, 0xFEE3, 0xFF32, 0x0000, 0x008D, 0x0137, 0x02FD, 0x04FD, // 0x5X
    0x0608, 0x06B8, 0x07D4, 0x082C, 0x0808, 0x07B4, 0xFF4B, 0xFF70, 0xFF81, 0xFF99, 0x0000, 0x00CE, 0x0153, 0x01F0, 0x0389, 0x0547, // 0x6X
    0x0572, 0x05F8, 0x06B8, 0x06B6, 0x066D, 0x05F6, 0x045D, 0xFFC2, 0xFFE0, 0x0000, 0x0067, 0x011D, 0x018F, 0x0214, 0x036C, 0x04D9, // 0x7X
    0x04FF, 0x0572, 0x0608, 0x05E1, 0x0589, 0x0504, 0x0353, 0x0119, 0x0000, 0x0020, 0x007F, 0x0122, 0x0189, 0x0200, 0x0334, 0x0479, // 0x8X
    0x0479, 0x04D9, 0x0547, 0x04FD, 0x0497, 0x0406, 0x0243, 0x0000, 0xFEE7, 0x003E, 0x0090, 0x011C, 0x0174, 0x01DC, 0x02EB, 0x0407, // 0x9X
    0x0334, 0x036C, 0x0389, 0x02FD, 0x027F, 0x01DC, 0x0000, 0xFDBD, 0xFCAD, 0xFBA3, 0x00B5, 0x00FF, 0x0134, 0x0176, 0x022B, 0x02EB, // 0xAX
    0x0200, 0x0214, 0x01F0, 0x0137, 0x00AC, 0x0000, 0xFE24, 0xFBFA, 0xFAFC, 0xFA0A, 0xF84C, 0x00F8, 0x0105, 0x011E, 0x0176, 0x01DC, // 0xBX
    0x0189, 0x018F, 0x0153, 0x008D, 0x0000, 0xFF54, 0xFD81, 0xFB69, 0xFA77, 0xF993, 0xF7F8, 0xF719, 0x0100, 0x0105, 0x0134, 0x0174, // 0xCX
    0x0122, 0x011D, 0x00CE, 0x0000, 0xFF73, 0xFEC9, 0xFD03, 0xFB03, 0xFA1F, 0xF94A, 0xF7D4, 0xF71F, 0xF719, 0x00F8, 0x00FF, 0x011C, // 0xDX
    0x007F, 0x0067, 0x0000, 0xFF32, 0xFEAD, 0xFE10, 0xFC77, 0xFAB9, 0xF9F8, 0xF948, 0xF82C, 0xF7D4, 0xF7F8, 0xF84C, 0x00B5, 0x0090, // 0xEX
    0x0020, 0x0000, 0xFF99, 0xFEE3, 0xFE71, 0xFDEC, 0xFC94, 0xFB27, 0xFA8E, 0xFA08, 0xF948, 0xF94A, 0xF993, 0xFA0A, 0xFBA3, 0x003E, // 0xFX
};

static const u16 sFlipperRadiusMagnitudes[32] = {
    0x0000, 0x000C, 0x001C, 0x0030, 0x0038, 0x0048, 0x005C, 0x006C, 0x0070, 0x0080, 0x0094, 0x00A4, 0x00B4, 0x00C4, 0x00D4, 0x00E4,
    0x00F8, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC,
};

void PlayMeowthPinballGame(void)
{
    PlayPinballGame(GAME_TYPE_MEOWTH);
}

void PlayDiglettPinballGame(void)
{
    PlayPinballGame(GAME_TYPE_DIGLETT);
}

void PlaySeelPinballGame(void)
{
    PlayPinballGame(GAME_TYPE_SEEL);
}

void PlayGengarPinballGame(void)
{
    PlayPinballGame(GAME_TYPE_GENGAR);
}

static void PlayPinballGame(u8 gameType)
{
    u8 taskId;

    ScriptContext1_Stop();
    sPinballGame = AllocZeroed(sizeof(*sPinballGame));
    sPinballGame->gameType = gameType;
    sPinballGame->returnMainCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    taskId = CreateTask(FadeToPinballScreen, 0);
}

static void FadeToPinballScreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(InitPinballScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

static void InitPinballScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetAllBgsCoordinates();
        gMain.state++;
        break;
    case 1:
        ResetVramOamAndBgCntRegs();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sPinballBgTemplates, ARRAY_COUNT(sPinballBgTemplates));
        SetBgTilemapBuffer(PINBALL_BG_BASE, AllocZeroed(BG_SCREEN_SIZE * 4));
        LoadBgGfx(sPinballGame->gameType);
        InitWindows(sPinballWinTemplates);
        DeactivateAllTextPrinters();
        LoadMessageBoxGfx(WIN_TEXT, 0x200, 0xF0);
        LoadUserWindowBorderGfx(WIN_TEXT, 0x214, 0xE0);
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(PINBALL_BG_TEXT);
        ShowBg(PINBALL_BG_BASE);
        gMain.state++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sBallPokeballSpriteSheet);
        LoadSpritePalette(&sPinballSpritePalette);
        LoadCompressedSpriteSheet(&sFlipperSpriteSheet);
        LoadSpritePalette(&sFlipperSpritePalette);
        LoadCompressedSpriteSheet(&sTimerDigitsSpriteSheet);
        LoadSpritePalette(&sTimerDigitsSpritePalette);
        LoadSpriteGfx(sPinballGame->gameType);
        InitPinballGame();
        InitBallSprite();
        InitFlipperSprites();
        InitTimerSprites();
        InitGameType(sPinballGame->gameType);
        StartNewBall();
        gMain.state++;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(PinballVBlankCallback);
        SetMainCallback2(PinballMainCallback);
        CreateTask(PinballMain, 0);
        return;
    }
}

static void LoadBgGfx(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        LoadBgTiles(PINBALL_BG_BASE, sMeowthStageBgGfx, sizeof(sMeowthStageBgGfx), 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sMeowthStageBgTilemap, sizeof(sMeowthStageBgTilemap), 0);
        ResetPaletteFade();
        LoadPalette(sMeowthStageBgPalette, 0, sizeof(sMeowthStageBgPalette));
        break;
    case GAME_TYPE_DIGLETT:
        LoadBgTiles(PINBALL_BG_BASE, sDiglettStageBgGfx, sizeof(sDiglettStageBgGfx), 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sDiglettStageBgTilemap, sizeof(sDiglettStageBgTilemap), 0);
        ResetPaletteFade();
        LoadPalette(sDiglettStageBgPalette, 0, sizeof(sDiglettStageBgPalette));
        break;
    case GAME_TYPE_SEEL:
        LoadBgTiles(PINBALL_BG_BASE, sSeelStageBgGfx, sizeof(sSeelStageBgGfx), 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sSeelStageBgTilemap, sizeof(sSeelStageBgTilemap), 0);
        ResetPaletteFade();
        LoadPalette(sSeelStageBgPalette, 0, sizeof(sSeelStageBgPalette));
        break;
    case GAME_TYPE_GENGAR:
        LoadBgTiles(PINBALL_BG_BASE, sGengarStageBgGfx, sizeof(sGengarStageBgGfx), 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sGengarStageBgTilemap, sizeof(sGengarStageBgTilemap), 0);
        ResetPaletteFade();
        LoadPalette(sGengarStageBgPalette, 0, sizeof(sGengarStageBgPalette));
        break;
    }
}

static void LoadSpriteGfx(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        LoadCompressedSpriteSheet(&sMeowthAnimationSpriteSheet);
        LoadSpritePalette(&sMeowthAnimationSpritePalette);
        LoadCompressedSpriteSheet(&sMeowthJewelSpriteSheet);
        LoadSpritePalette(&sMeowthJewelSpritePalette);
        LoadCompressedSpriteSheet(&sMeowthJewelMultipliersSpriteSheet);
        LoadCompressedSpriteSheet(&sMeowthSparkleSpriteSheet);
        LoadSpritePalette(&sMeowthJewelMultipliersSpritePalette);
        break;
    case GAME_TYPE_DIGLETT:
        LoadCompressedSpriteSheet(&sDugtrioAnimationSpriteSheet);
        LoadSpritePalette(&sDugtrioAnimationSpritePalette);
        break;
    case GAME_TYPE_SEEL:
        LoadCompressedSpriteSheet(&sSeelAnimationSpriteSheet);
        LoadSpritePalette(&sSeelAnimationSpritePalette);
        LoadCompressedSpriteSheet(&sSeelSparkleSpriteSheet);
        LoadSpritePalette(&sSeelSparkleSpritePalette);
        LoadCompressedSpriteSheet(&sSeelMultipliersSpriteSheet);
        LoadSpritePalette(&sSeelMultipliersSpritePalette);
        break;
    case GAME_TYPE_GENGAR:
        break;
    }
}

static void InitPinballGame(void)
{
    sPinballGame->stageTileWidth = 32;
    sPinballGame->stageTileHeight = 32;
    sPinballGame->gravityEnabled = TRUE;
    sPinballGame->rightFlipper.type = FLIPPER_RIGHT;
    sPinballGame->rightFlipper.xPos = 93;
    sPinballGame->rightFlipper.yPos = 122;
    sPinballGame->leftFlipper.type = FLIPPER_LEFT;
    sPinballGame->leftFlipper.xPos = 67;
    sPinballGame->leftFlipper.yPos = 122;
    sPinballGame->timer.ticks = GetTimerTicks(sPinballGame->gameType);
    sPinballGame->flippersDisabled = FALSE;
}

static u32 GetTimerTicks(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        return 60 * 60 + 59;
    case GAME_TYPE_SEEL:
        return 90 * 60 + 59;
    case GAME_TYPE_GENGAR:
        return 90 * 60 + 59;
    default:
        return 1;
    }
}

static void InitBallSprite(void)
{
    sPinballGame->ball.spriteId = CreateSprite(&sBallPokeballSpriteTemplate, 0, 0, 3);
    StartSpriteAnim(&gSprites[sPinballGame->ball.spriteId], 3);
}

static void InitFlipperSprites(void)
{
    sPinballGame->rightFlipper.spriteId = CreateSprite(&sFlipperSpriteTemplate, 0, 0, 4);
    sPinballGame->leftFlipper.spriteId = CreateSprite(&sFlipperSpriteTemplate, 0, 0, 4);
    gSprites[sPinballGame->leftFlipper.spriteId].data[0] = FLIPPER_LEFT;
    gSprites[sPinballGame->rightFlipper.spriteId].data[0] = FLIPPER_RIGHT;
    StartSpriteAnim(&gSprites[sPinballGame->leftFlipper.spriteId], 0);
    StartSpriteAnim(&gSprites[sPinballGame->rightFlipper.spriteId], 3);
}

static void InitTimerSprites(void)
{
    if (GameTypeUsesTimer(sPinballGame->gameType))
    {
        int x, y;
        GetTimerScreenCoords(sPinballGame->gameType, &x, &y);
        sPinballGame->timer.minutesSpriteId = CreateSprite(&sTimerDigitSpriteTemplate, x, y, 4);
        sPinballGame->timer.colonSpriteId = CreateSprite(&sTimerDigitSpriteTemplate, x + 8, y, 4);
        sPinballGame->timer.tensSpriteId = CreateSprite(&sTimerDigitSpriteTemplate, x + 16, y, 4);
        sPinballGame->timer.onesSpriteId = CreateSprite(&sTimerDigitSpriteTemplate, x + 24, y, 4);
        gSprites[sPinballGame->timer.minutesSpriteId].data[0] = 0;
        gSprites[sPinballGame->timer.colonSpriteId].data[0] = 1;
        gSprites[sPinballGame->timer.tensSpriteId].data[0] = 2;
        gSprites[sPinballGame->timer.onesSpriteId].data[0] = 3;
        StartSpriteAnim(&gSprites[sPinballGame->timer.minutesSpriteId], 0);
        StartSpriteAnim(&gSprites[sPinballGame->timer.colonSpriteId], 10);
        StartSpriteAnim(&gSprites[sPinballGame->timer.tensSpriteId], 0);
        StartSpriteAnim(&gSprites[sPinballGame->timer.onesSpriteId], 0);
    }
}

static bool32 GameTypeUsesTimer(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_DIGLETT:
        return FALSE;
    default:
        return TRUE;
    }
}

static void GetTimerScreenCoords(u8 gameType, int *outX, int *outY)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
    case GAME_TYPE_SEEL:
        *outX = 131;
        *outY = 109;
        break;
    case GAME_TYPE_GENGAR:
        *outX = 131;
        *outY = 8;
        break;
    default:
        *outX = 0;
        *outY = 0;
        break;
    }
}

static void InitGameType(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        InitMeowth();
        break;
    case GAME_TYPE_DIGLETT:
        InitDiglett();
        break;
    case GAME_TYPE_SEEL:
        InitSeel();
        break;
    case GAME_TYPE_GENGAR:
        InitGengar();
        break;
    }
}

static void InitMeowth(void)
{
    struct Meowth *meowth = &sPinballGame->meowth;

    meowth->xPos = 40;
    meowth->yPos = 40;
    meowth->state = MEOWTH_STATE_WALK;
    meowth->facing = MEOWTH_FACING_RIGHT;
    meowth->yMovement = 0;
    meowth->score = 0;
    meowth->jewelStreak = 0;
    meowth->spriteId = CreateSprite(&sMeowthSpriteTemplate, 0, 0, 5);
    meowth->sparkleSpriteId = CreateSprite(&sMeowthJewelSparkleSpriteTemplate, 0, 0, 6);
    StartSpriteAnim(&gSprites[meowth->spriteId], 0);
    StartSpriteAnim(&gSprites[meowth->sparkleSpriteId], 0);
}

static void InitDiglett(void)
{
    struct Diglett *diglett = &sPinballGame->diglett;
    diglett->completed = FALSE;
    diglett->numDiglettsHit = 0;
    diglett->collisionMap = Alloc(ARRAY_COUNT(sDiglettStageBgCollisionMap) * sizeof(sDiglettStageBgCollisionMap[0]));
    memcpy(diglett->collisionMap, sDiglettStageBgCollisionMap, ARRAY_COUNT(sDiglettStageBgCollisionMap) * sizeof(sDiglettStageBgCollisionMap[0]));
    diglett->dugtrioSpriteId = CreateSprite(&sDugtrioSpriteTemplate, 80, 16, 5);
    diglett->dugtrioState = DUGTRIO_STATE_HIDDEN;
    gSprites[diglett->dugtrioSpriteId].data[0] = DUGTRIO_STATE_HIDDEN;
    StartSpriteAnim(&gSprites[diglett->dugtrioSpriteId], 0);
}

static void InitSeel(void)
{
    int i;
    struct Seel *seel = &sPinballGame->seel;
    seel->completed = FALSE;
    seel->streak = 0;
    seel->sparkleSpriteId = CreateSprite(&sSeelSparkleSpriteTemplate, 0, 0, 6);
    StartSpriteAnim(&gSprites[seel->sparkleSpriteId], 0);
    for (i = 0; i < NUM_SEELS; i++)
    {
        struct SeelSwimmer *swimmer = &seel->swimmers[i];
        swimmer->state = sInitialSeelStates[i];
        swimmer->xPos = sInitialSeelCoords[i][0] << 8;
        swimmer->yPos = sInitialSeelCoords[i][1] << 8;
        swimmer->spriteId = CreateSprite(&sSeelSpriteTemplate, swimmer->xPos >> 8, swimmer->yPos >> 8, 5);
        gSprites[swimmer->spriteId].data[0] = swimmer->state;
        gSprites[swimmer->spriteId].data[1] = i;
        if (swimmer->state == SEEL_STATE_SWIM_RIGHT)
            StartSpriteAnim(&gSprites[swimmer->spriteId], 0);
        else
            StartSpriteAnim(&gSprites[swimmer->spriteId], 2);
    }
}

static void InitGengar(void)
{
    
}

static void PinballVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void PinballMainCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PinballMain(u8 taskId)
{
    bool32 completed;

    switch (sPinballGame->state)
    {
    case PINBALL_STATE_INIT:
        if (!gPaletteFade.active)
        {
            sPinballGame->state = PINBALL_STATE_RUNNING;
        }
        break;
    case PINBALL_STATE_RUNNING:
        completed = UpdateGameType(sPinballGame->gameType);
        if (!sPinballGame->completed && completed)
            sPinballGame->completed = TRUE;

        HandleBallPhysics();
        UpdateCamera();
        UpdateTimer();
        break;
    case PINBALL_LOST_BALL_FADE_OUT:
        if (!gPaletteFade.active)
        {
            LostBall(sPinballGame->gameType);
            StartNewBall();
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_WHITE);
            sPinballGame->state = PINBALL_LOST_BALL_FADE_IN;
        }
        break;
    case PINBALL_LOST_BALL_FADE_IN:
        if (!gPaletteFade.active)
            sPinballGame->state = PINBALL_STATE_RUNNING;
        break;
    case PINBALL_STATE_DELAY_START_EXIT:
        if (--sPinballGame->exitTimer == 0)
            sPinballGame->state = PINBALL_STATE_START_EXIT;
        break;
    case PINBALL_STATE_START_EXIT:
        StartExitPinballGame();
        break;
    case PINBALL_STATE_EXIT:
        ExitPinballGame();
        break;
    }
}

static void StartNewBall(void)
{
    sPinballGame->ball.xPos = 166 << 8;
    sPinballGame->ball.yPos = 70 << 8;
    sPinballGame->ball.xVelocity = 0x40;
    sPinballGame->ball.yVelocity = 0;
    sPinballGame->ball.spin = 0;
    OpenEntrance(sPinballGame->gameType);
}

static void OpenEntrance(u8 gameType)
{
    sPinballGame->ballIsEntering = TRUE;
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        OpenEntranceMeowth();
        break;
    case GAME_TYPE_DIGLETT:
        OpenEntranceDiglett();
        break;
    case GAME_TYPE_SEEL:
        OpenEntranceSeel();
        break;
    case GAME_TYPE_GENGAR:
        OpenEntranceGengar();
        break;
    }
}

static void OpenEntranceMeowth(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x415;
    tilemap[0x114] = 0x414;
    tilemap[0x133] = 0x413;
    tilemap[0x134] = 0x412;
    tilemap[0x152] = 0x400;
    tilemap[0x153] = 0x410;
    tilemap[0x154] = 0x011;
    tilemap[0x172] = 0x409;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void OpenEntranceDiglett(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x55;
    tilemap[0x114] = 0x56;
    tilemap[0x133] = 0x0;
    tilemap[0x134] = 0x54;
    tilemap[0x152] = 0x0;
    tilemap[0x153] = 0x52;
    tilemap[0x154] = 0x53;
    tilemap[0x172] = 0x50;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void OpenEntranceSeel(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x41E;
    tilemap[0x114] = 0x41D;
    tilemap[0x133] = 0x41B;
    tilemap[0x134] = 0x41A;
    tilemap[0x152] = 0x400;
    tilemap[0x153] = 0x418;
    tilemap[0x154] = 0x417;
    tilemap[0x172] = 0x414;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void OpenEntranceGengar(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x0;
    tilemap[0x132] = 0x1;
    tilemap[0x133] = 0x2;
    tilemap[0x152] = 0x5;
    tilemap[0x153] = 0x3;
    tilemap[0x172] = 0x4;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void CloseEntrance(u8 gameType)
{
    sPinballGame->ballIsEntering = FALSE;
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        CloseEntranceMeowth();
        break;
    case GAME_TYPE_DIGLETT:
        CloseEntranceDiglett();
        break;
    case GAME_TYPE_SEEL:
        CloseEntranceSeel();
        break;
    case GAME_TYPE_GENGAR:
        CloseEntranceGengar();
        break;
    }
}

static void CloseEntranceMeowth(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x404;
    tilemap[0x114] = 0x402;
    tilemap[0x133] = 0x403;
    tilemap[0x134] = 0x401;
    tilemap[0x152] = 0x40F;
    tilemap[0x153] = 0x40E;
    tilemap[0x154] = 0x002;
    tilemap[0x172] = 0x40C;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void CloseEntranceDiglett(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x24;
    tilemap[0x114] = 0x2;
    tilemap[0x133] = 0x22;
    tilemap[0x134] = 0x1;
    tilemap[0x152] = 0x1F;
    tilemap[0x153] = 0x20;
    tilemap[0x154] = 0x2;
    tilemap[0x172] = 0x1B;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void CloseEntranceSeel(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x41C;
    tilemap[0x114] = 0x401;
    tilemap[0x133] = 0x419;
    tilemap[0x134] = 0x408;
    tilemap[0x152] = 0x416;
    tilemap[0x153] = 0x415;
    tilemap[0x154] = 0x405;
    tilemap[0x172] = 0x411;
    tilemap[0x173] = 0x401;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void CloseEntranceGengar(void)
{
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    tilemap[0x113] = 0x4D;
    tilemap[0x132] = 0x41;
    tilemap[0x133] = 0x42;
    tilemap[0x152] = 0x36;
    tilemap[0x153] = 0x37;
    tilemap[0x172] = 0x2F;
    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void DrawMeowthScoreJewels(struct Meowth *meowth)
{
    int i;
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    for (i = 0; i < 20; i++)
    {
        if (i < meowth->score)
            tilemap[i] = i % 2 ? 0x41E : 0x1E;
        else
            tilemap[i] = sMeowthStageBgTilemap[i];
    }

    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void DrawSeelScoreJewels(struct Seel *seel)
{
    int i;
    u16 *tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
    for (i = 0; i < 20; i++)
    {
        if (i < seel->score)
        {
            if (i == 0 || i == 19)
                tilemap[i] = 0x28;
            else if (i == 1)
                tilemap[i] = 0x29;
            else if (i == 18)
                tilemap[i] = 0x2B;
            else
                tilemap[i] = 0x2A;
        }
        else
        {
            tilemap[i] = sSeelStageBgTilemap[i];
        }
    }

    CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
}

static void HandleBallPhysics(void)
{
    bool32 isFlipperColliding;
    bool32 isStaticColliding;
    bool32 isObjectColliding = FALSE;
    u8 flipperCollisionNormal;
    u8 objectCollisionNormal;
    u8 staticCollisionNormal;
    u8 collisionNormal;
    u16 artificialYForce = 0;
    int collisionAmplification = 0;
    struct Ball *ball = &sPinballGame->ball;

    if (sPinballGame->ballIsEntering && (ball->xPos >> 8) < 144)
        CloseEntrance(sPinballGame->gameType);

    if (sPinballGame->gravityEnabled)
        ApplyGravity(ball);

    LimitVelocity(ball);
    isFlipperColliding = HandleFlippers(ball, &artificialYForce, &flipperCollisionNormal, &collisionAmplification);
    if (!isFlipperColliding)
        isObjectColliding = CheckObjectsCollision(sPinballGame->gameType, ball, sPinballGame->timer.ticks, &objectCollisionNormal, &collisionAmplification);

    isStaticColliding = CheckStaticCollision(sPinballGame->gameType, ball, sPinballGame->ballIsEntering, sPinballGame->stageTileWidth, sPinballGame->stageTileHeight, &staticCollisionNormal, &artificialYForce);
    if (isFlipperColliding)
        collisionNormal = flipperCollisionNormal;
    else if (isObjectColliding)
        collisionNormal = objectCollisionNormal;
    else
        collisionNormal = staticCollisionNormal;

    if (isFlipperColliding || isObjectColliding || isStaticColliding)
    {
        RotateVector(&ball->xVelocity, &ball->yVelocity, collisionNormal);
        ApplyCollisionForces(ball, artificialYForce, collisionAmplification);
        RotateVector(&ball->xVelocity, &ball->yVelocity, -collisionNormal);
    }

    UpdatePosition(ball);

    if ((ball->yPos >> 8) > 168)
        LoseBall();
}

static void LoseBall(void)
{
    if (PlayAnotherBall())
    {
        sPinballGame->state = PINBALL_LOST_BALL_FADE_OUT;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_WHITE);
    }
    else
    {
        sPinballGame->state = PINBALL_STATE_DELAY_START_EXIT;
        sPinballGame->exitTimer = 2 * 60;
        gSpecialVar_Result = sPinballGame->completed;
    }
}

static bool32 PlayAnotherBall(void)
{
    switch (sPinballGame->gameType)
    {
    case GAME_TYPE_MEOWTH:
    case GAME_TYPE_SEEL:
    case GAME_TYPE_GENGAR:
        return sPinballGame->timer.ticks > 0 && !sPinballGame->completed;
    case GAME_TYPE_DIGLETT:
        return FALSE;
    default:
        return TRUE;
    }
}

static void LostBall(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        LostBallMeowth(&sPinballGame->meowth);
        break;
    case GAME_TYPE_DIGLETT:
        break;
    case GAME_TYPE_SEEL:
        LostBallSeel(&sPinballGame->seel);
        break;
    case GAME_TYPE_GENGAR:
        LostBallGengar(&sPinballGame->gengar);
        break;
    }
}

#define JEWEL_SPARKLE_DURATION 180

static void LostBallMeowth(struct Meowth *meowth)
{
    struct Sprite *sparkleSprite = &gSprites[sPinballGame->meowth.sparkleSpriteId];
    if (meowth->score > 4)
    {
        meowth->score -= 4;
        sparkleSprite->data[0] = JEWEL_SPARKLE_DURATION;
        sparkleSprite->data[1] = meowth->score;
    }
    else
    {
        meowth->score = 0;
        sparkleSprite->data[0] = 0;
        sparkleSprite->data[1] = 0;
    }

    meowth->jewelStreak = 0;
    ResetMeowthJewels(meowth);
    DrawMeowthScoreJewels(meowth);
}

#define SEEL_SPARKLE_DURATION 180

static void LostBallSeel(struct Seel *seel)
{
    struct Sprite *sparkleSprite = &gSprites[sPinballGame->seel.sparkleSpriteId];
    if (seel->score > 4)
    {
        seel->score -= 4;
        sparkleSprite->data[0] = SEEL_SPARKLE_DURATION;
        sparkleSprite->data[1] = seel->score;
    }
    else
    {
        seel->score = 0;
        sparkleSprite->data[0] = 0;
        sparkleSprite->data[1] = 0;
    }

    seel->streak = 0;
    ResetSeels(seel);
    DrawSeelScoreJewels(seel);
}

static void LostBallGengar(struct Gengar *gengar)
{
}

#define GRAVITY 0x0B

static void ApplyGravity(struct Ball *ball)
{
    ball->yVelocity += GRAVITY;
}

#define MAX_VELOCITY 0x07FF

static void LimitVelocity(struct Ball *ball)
{
    // Limit each velocity axis independently. This means
    // the ball can move diagonally at a higher speed.
    if (ball->xVelocity > MAX_VELOCITY)
        ball->xVelocity = MAX_VELOCITY;
    else if (ball->xVelocity < -MAX_VELOCITY)
        ball->xVelocity = -MAX_VELOCITY;

    if (ball->yVelocity > MAX_VELOCITY)
        ball->yVelocity = MAX_VELOCITY;
    else if (ball->yVelocity < -MAX_VELOCITY)
        ball->yVelocity = -MAX_VELOCITY;
}

static bool32 HandleFlippers(struct Ball *ball, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    bool32 collided;
    struct Flipper *flipper;

    UpdateFlipperState(&sPinballGame->rightFlipper);
    UpdateFlipperState(&sPinballGame->leftFlipper);
    
    collided = CheckFlipperCollision(ball, &sPinballGame->rightFlipper, outYForce, outCollisionNormal, outCollisionAmplification);
    if (!collided)
        collided = CheckFlipperCollision(ball, &sPinballGame->leftFlipper, outYForce, outCollisionNormal, outCollisionAmplification);

    return collided;
}

#define FLIPPER_STATE_DELTA 0x0333

static void UpdateFlipperState(struct Flipper *flipper)
{
    int stateDelta;

    flipper->prevState = flipper->state;
    if (!sPinballGame->flippersDisabled && (gMain.heldKeys & (A_BUTTON | B_BUTTON)))
    {
        if (flipper->state == 0x0FFF)
            stateDelta = 0;
        else
            stateDelta = FLIPPER_STATE_DELTA;
    }
    else
    {
        if (flipper->state == 0)
            stateDelta = 0;
        else
            stateDelta = -FLIPPER_STATE_DELTA;
    }

    flipper->stateDelta = stateDelta;
    flipper->state += stateDelta;
}

static bool32 CheckFlipperCollision(struct Ball *ball, struct Flipper *flipper, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    int curState, stateDelta;
    int offset;
    u32 collisionRadius, magnitude;
    u8 collisionNormal;
    int ballXPos = (ball->xPos >> 8);
    int ballYPos = (ball->yPos >> 8);
    int xOffset = ballXPos - flipper->xPos + 24;
    int yOffset = ballYPos - flipper->yPos + 16;

    if (xOffset < 0 || xOffset >= 48 || yOffset < 0 || yOffset >= 32)
        return FALSE;

    *outYForce = 0;
    *outCollisionAmplification = 0;

    if (flipper->type == FLIPPER_RIGHT)
        xOffset = 48 - xOffset;

    offset = xOffset * 32 + yOffset;
    collisionRadius = 0;

    stateDelta = flipper->prevState < flipper->state ? 1 : -1;
    curState = flipper->prevState >> 8;
    while (1)
    {
        collisionRadius = sFlipperCollisionRadii[curState * 0x600 + offset];
        if (collisionRadius != 0)
            break;

        if (curState == (flipper->state >> 8))
            return FALSE;

        curState += stateDelta;
    }

    collisionNormal = sFlipperCollisionNormalAngles[curState * 0x600 + offset];
    magnitude = sFlipperRadiusMagnitudes[collisionRadius];
    *outYForce = ((flipper->stateDelta * 4) * magnitude) >> 8;
    *outCollisionNormal = flipper->type == FLIPPER_LEFT ? collisionNormal : -collisionNormal;
    *outCollisionAmplification = 1;

    // Don't apply any y force if the ball is being forced downwards into the flipper
    if ((*outYForce) & 0x8000)
    {
        *outYForce = 0;
        *outCollisionAmplification = 0;
    }

    return TRUE;
}

#define MAX_POS_UPDATE 0x04FF

static void UpdatePosition(struct Ball *ball)
{
    // Moves the ball's position according to its velocity.
    // The amount it's moved is artificially limited at a lower
    // threshold than the maximum velocity.
    if (ball->xVelocity > MAX_POS_UPDATE)
        ball->xPos += MAX_POS_UPDATE;
    else if (ball->xVelocity < -MAX_POS_UPDATE)
        ball->xPos -= MAX_POS_UPDATE;
    else
        ball->xPos += ball->xVelocity;

    if (ball->yVelocity > MAX_POS_UPDATE)
        ball->yPos += MAX_POS_UPDATE;
    else if (ball->yVelocity < -MAX_POS_UPDATE)
        ball->yPos -= MAX_POS_UPDATE;
    else
        ball->yPos += ball->yVelocity;

    if (ball->xPos & 0x80000000)
        ball->xPos = 0;
    if (ball->yPos & 0x80000000)
        ball->yPos = 0;

}

static bool32 CheckStaticCollision(u8 gameType, struct Ball *ball, bool32 ballIsEntering, int stageTileWidth, int stageTileHeight, u8 *outCollisionNormal, u16 *outYForce)
{
    int i;
    u16 xDelta, yDelta;
    int collisionIndex;
    int maxStringStart, maxStringEnd, curStringStart, curStringLength, maxStringLength;
    u8 collisionTestAttributes[ARRAY_COUNT(sCollisionTestPointOffsets)];
    u8 collisionTestCoords[ARRAY_COUNT(sCollisionTestPointOffsets)][2];
    u8 collisionTests[ARRAY_COUNT(sCollisionTestPointOffsets)];

    // Check each of the test points around the ball's origin
    // to see if they are colliding with the static collision masks.
    for (i = 0; i < ARRAY_COUNT(sCollisionTestPointOffsets); i++)
    {
        int testX, testY;
        int tileX, tileY, tileIndex;
        int collisionAttribute, row, column;
        u8 collisionMaskRow;
        int xPos = ball->xPos >> 8;
        int yPos = ball->yPos >> 8;

        collisionTests[i] = 0;
        testX = xPos + sCollisionTestPointOffsets[i][0];
        testY = yPos + sCollisionTestPointOffsets[i][1];
        if (testX < 0 || testY < 0)
        {
            collisionTests[i] = 1;
            continue;
        }

        tileX = testX / 8;
        tileY = testY / 8;
        row = testY % 8;
        column = testX % 8;
        tileIndex = (tileY * stageTileWidth) + tileX;
        collisionAttribute = GetCollisionAttribute(gameType, ballIsEntering, tileIndex);
        collisionMaskRow = GetCollisionMaskRow(gameType, collisionAttribute, row);
        collisionTests[i] = (collisionMaskRow & (1 << column)) != 0;
        collisionTestCoords[i][0] = testX;
        collisionTestCoords[i][1] = testY;
        collisionTestAttributes[i] = collisionAttribute;
    }

    // Find the largest string of consecutive colliding test points.
    maxStringStart = 0;
    maxStringEnd = 0;
    maxStringLength = 0;
    curStringStart = -1;
    curStringLength = 0;
    for (i = 0; i < ARRAY_COUNT(sCollisionTestPointOffsets); i++)
    {
        if (collisionTests[i])
        {
            if (curStringStart == -1)
                curStringStart = i;

            curStringLength++;
            if (curStringLength > maxStringLength)
            {
                maxStringLength = curStringLength;
                maxStringStart = curStringStart;
                maxStringEnd = i;
            }
        }
        else
        {
            curStringLength = 0;
            curStringStart = -1;
        }
    }

    // If all of the test points are colliding, then the ball
    // is inside a wall. Just early exit with no collision.
    if (maxStringLength == 0 || maxStringLength == 16)
        return FALSE;

    // Check if the maximum string loops around to the front of
    // the collision tests array.
    if (curStringStart != -1)
    {
        for (i = 0; i < ARRAY_COUNT(sCollisionTestPointOffsets); i++)
        {
            if (!collisionTests[i])
                break;

            curStringLength++;
            if (curStringLength > maxStringLength)
            {
                maxStringLength = curStringLength;
                maxStringStart = curStringStart;
                maxStringEnd = i;
            }
        }
    }
 
    collisionIndex = ((maxStringStart & 0xF) << 4) | (maxStringEnd & 0xF);

    // Treat the delta values as signed.
    xDelta = sCollisionXDeltas[collisionIndex];
    if (xDelta > 0x8000)
        ball->xPos -= 0x10000 - xDelta;
    else
        ball->xPos += xDelta;

    yDelta = sCollisionYDeltas[collisionIndex];
    if (yDelta > 0x8000)
        ball->yPos -= 0x10000 - yDelta;
    else
        ball->yPos += yDelta;

    *outCollisionNormal = sCollisionNormals[collisionIndex];
    HandleStaticCollisionForGameType(
        gameType,
        collisionTestCoords[maxStringStart][0],
        collisionTestCoords[maxStringStart][1],
        collisionTestAttributes[maxStringStart],
        outYForce
    );

    return TRUE;
}

static u8 GetCollisionAttribute(u8 gameType, bool32 ballIsEntering, int index)
{
    const u8 *entranceCollisionMap;
    const u8 *collisionMap;

    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        entranceCollisionMap = sMeowthStageEntranceBgCollisionMap;
        collisionMap = sMeowthStageBgCollisionMap;
        break;
    case GAME_TYPE_DIGLETT:
        entranceCollisionMap = sDiglettStageEntranceBgCollisionMap;
        collisionMap = sPinballGame->diglett.collisionMap;
        break;
    case GAME_TYPE_SEEL:
        entranceCollisionMap = sSeelStageEntranceBgCollisionMap;
        collisionMap = sSeelStageBgCollisionMap;
        break;
    case GAME_TYPE_GENGAR:
        entranceCollisionMap = sGengarStageEntranceBgCollisionMap;
        collisionMap = sGengarStageBgCollisionMap;
        break;
    }

    if (ballIsEntering)
        return entranceCollisionMap[index];

    return collisionMap[index];
}

static u8 GetCollisionMaskRow(u8 gameType, int collisionAttribute, int row)
{
    struct Flipper *flipper;
    int state;
    int offset;
    const u8 *flipperStateMasks;
    u8 mask;

    if (collisionAttribute < 0xE0)
    {
        const u8 *masks;
        switch (gameType)
        {
        case GAME_TYPE_MEOWTH:
            masks = sMeowthStageBgCollisionMasks;
            break;
        case GAME_TYPE_DIGLETT:
            masks = sDiglettStageBgCollisionMasks;
            break;
        case GAME_TYPE_SEEL:
            masks = sSeelStageBgCollisionMasks;
            break;
        case GAME_TYPE_GENGAR:
            masks = sGengarStageBgCollisionMasks;
            break;
        }

        // Reverse the bits because my tooling is backwards.
        return ReverseBits(masks[(collisionAttribute * 0x8) + row]);
    }

    // Collision attribute from 0xE0 - 0xFF are special
    // static flipper collision masks.
    if (collisionAttribute < 0xF0)
        flipper = &sPinballGame->leftFlipper;
    else
        flipper = &sPinballGame->rightFlipper;

    state = flipper->state >> 8;
    if (state < 7)
        offset = 0;
    else if (state < 14)
        offset = 1;
    else
        offset = 2;

    if (collisionAttribute < 0xF0)
        flipperStateMasks = sFlipperLeftMeowthCollisionMasks[offset];
    else
        flipperStateMasks = sFlipperRightMeowthCollisionMasks[offset];

    mask = flipperStateMasks[(collisionAttribute % 0x10) * 0x8 + row];

    // Reverse the bits because my tooling is backwards.
    return ReverseBits(mask);
}

static u8 ReverseBits(u8 b)
{
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

static void RotateVector(s16 *x, s16 *y, u8 angle)
{
    // Rotate a vector by an angle with a 2D rotation matrix calculation.
    // rotatedX = xComponent * cos(angle) + yComponent * sin(angle)
    // rotatedY = yComponent * cos(angle) - xComponent * sin(angle)
    s16 sin = gSineTable[angle];
    s16 cos = gSineTable[angle + 64];
    s16 newX = ((*x * cos) / 256) + ((*y * sin) / 256);
    s16 newY = ((*y * cos) / 256) - ((*x * sin) / 256);
    *x = newX;
    *y = newY;
}

static void HandleStaticCollisionForGameType(u8 gameType, int x, int y, u8 collisionAttribute, u16 *outYForce)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
    case GAME_TYPE_SEEL:
        break;
    case GAME_TYPE_GENGAR:
        HandleStaticCollisionGengar(&sPinballGame->gengar, collisionAttribute, outYForce);
        break;
    case GAME_TYPE_DIGLETT:
        HandleStaticCollisionDiglett(&sPinballGame->diglett, x, y, collisionAttribute);
        break;
    }
}

static void HandleStaticCollisionDiglett(struct Diglett *diglett, int x, int y, u8 collisionAttribute)
{
    if (collisionAttribute == 0x19 || collisionAttribute == 0x1A || collisionAttribute == 0x1B)
    {
        // If the ball hit a Diglett, remove the Diglett's solid collision from the map.
        int i;
        int tileX = x / 8;
        int tileY = y / 8;

        // Find the id of the collided Diglett.
        for (i = 0; i < NUM_DIGLETTS; i++)
        {
            int diglettX = sDiglettCoords[i][0];
            int diglettY = sDiglettCoords[i][1];
            int xDiff = tileX - diglettX;
            int yDiff = tileY - diglettY;
            if ((xDiff == 0 || xDiff == 1) && (yDiff == 0 || yDiff == 1))
                break;
        }

        if (i != NUM_DIGLETTS)
        {
            u16 *tilemap;
            int tileIndex = sDiglettCoords[i][0] + sDiglettCoords[i][1] * 32;
            diglett->collisionMap[tileIndex]      = 0x2;
            diglett->collisionMap[tileIndex + 1]  = 0x2;
            diglett->collisionMap[tileIndex + 32] = 0x2;
            diglett->collisionMap[tileIndex + 33] = 0x2;
            diglett->states[i] = DIGLETT_STATE_HIT_0;
            tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
            UpdateDiglettTiles(tilemap, i, diglett);
            CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
        }
    }
    else if (collisionAttribute == 0x14 || collisionAttribute == 0x15 ||
             collisionAttribute == 0x16 || collisionAttribute == 0x17 ||
             collisionAttribute == 0x18)
    {
        // If the ball hit Dugtrio, advance its state.
        switch (diglett->dugtrioState)
        {
        case DUGTRIO_STATE_3ALIVE:
            diglett->dugtrioState = DUGTRIO_STATE_3ALIVE_HIT;
            break;
        case DUGTRIO_STATE_2ALIVE:
            diglett->dugtrioState = DUGTRIO_STATE_2ALIVE_HIT;
            break;
        case DUGTRIO_STATE_1ALIVE:
            diglett->dugtrioState = DUGTRIO_STATE_1ALIVE_HIT;
            // Clear the collision map for the Dugtrio-occupied tiles.
            diglett->collisionMap[0x48] = 0x2;
            diglett->collisionMap[0x49] = 0x2;
            diglett->collisionMap[0x4A] = 0x2;
            diglett->collisionMap[0x4B] = 0x2;
            diglett->collisionMap[0x68] = 0x2;
            diglett->collisionMap[0x69] = 0x2;
            diglett->collisionMap[0x6A] = 0x2;
            diglett->collisionMap[0x6B] = 0x2;
            break;
        }
    }
}

static void HandleStaticCollisionGengar(struct Gengar *gengar, u8 collisionAttribute, u16 *outYForce)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sGengarGravestoneCollisionAttributes); i++)
    {
        if (collisionAttribute == sGengarGravestoneCollisionAttributes[i])
        {
            // If the ball hit a gravestone, apply some artificial force to
            // make the ball bounce harder.
            *outYForce = 0x100;
            return;
        }
    }
}

static void ApplyCollisionForces(struct Ball *ball, u16 flipperYForce, int collisionAmplification)
{
    // Only apply the collision forces if the ball is moving
    // towards the wall it collided with, which can only be
    // true if the y velocity is traveling downward in the rotated
    // coordinate system.
    if (ball->yVelocity < 0)
        return;

    // Apply dampening to the vertical velocity component, and
    // negate it so that the ball bounces off the wall.
    ball->yVelocity = -(((2 + collisionAmplification) * ball->yVelocity) / 8);
    ball->xVelocity += ball->spin / 2;
    ball->spin = (ball->xVelocity * 4) >> 8;

    ball->yVelocity -= flipperYForce;
}

static void UpdateCamera(void)
{
    int scrollX, scrollY;
    int stagePixelWidth = sPinballGame->stageTileWidth * 8;
    int stagePixelHeight = sPinballGame->stageTileHeight * 8;
    struct Ball *ball = &sPinballGame->ball;

    scrollX = (ball->xPos >> 8) - (DISPLAY_WIDTH / 2);
    if (scrollX < 0)
        scrollX = 0;
    if (scrollX > stagePixelWidth - DISPLAY_WIDTH)
        scrollX = stagePixelWidth - DISPLAY_WIDTH;

    scrollY = (ball->yPos >> 8) - (DISPLAY_HEIGHT / 2);
    if (scrollY < 0)
        scrollY = 0;
    if (scrollY > stagePixelHeight - DISPLAY_HEIGHT)
        scrollY = stagePixelHeight - DISPLAY_HEIGHT;

    scrollX = 0;
    scrollY = 0;

    sPinballGame->cameraScrollX = scrollX;
    sPinballGame->cameraScrollY = scrollY;

    SetGpuReg(REG_OFFSET_BG1HOFS, scrollX);
    SetGpuReg(REG_OFFSET_BG1VOFS, scrollY);
}

static void UpdateTimer(void)
{
    if (GameTypeUsesTimer(sPinballGame->gameType) && sPinballGame->timer.ticks > 0)
    {
        if (--sPinballGame->timer.ticks == 0)
        {
            // Time has completely run out.
            // Disable the flippers, and play any ending
            // animation stuff.
            DisableFlippers();
            HandleTimeRanOut();
        }
    }
}

static void HandleTimeRanOut(void)
{
    switch (sPinballGame->gameType)
    {
    case GAME_TYPE_MEOWTH:
        sPinballGame->meowth.state = MEOWTH_STATE_FINISH;
        break;
    case GAME_TYPE_DIGLETT:
        break;
    case GAME_TYPE_SEEL:
        break;
    case GAME_TYPE_GENGAR:
        break;
    }
}

static void DisableFlippers(void)
{
    int flipperPaletteIndex;
    sPinballGame->flippersDisabled = TRUE;

    // Change the flippers' color to red.
    flipperPaletteIndex = IndexOfSpritePaletteTag(TAG_FLIPPER);
    gPlttBufferUnfaded[0x100 + flipperPaletteIndex * 0x10 + 2] = RGB(20, 4, 4);
    gPlttBufferUnfaded[0x100 + flipperPaletteIndex * 0x10 + 3] = RGB(27, 10, 10);
    gPlttBufferFaded[0x100 + flipperPaletteIndex * 0x10 + 2] = RGB(20, 4, 4);
    gPlttBufferFaded[0x100 + flipperPaletteIndex * 0x10 + 3] = RGB(27, 10, 10);
}

static void StartExitPinballGame(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sPinballGame->state = PINBALL_STATE_EXIT;
}

static void ExitPinballGame(void)
{
    if (!gPaletteFade.active)
    {
        if (sPinballGame->gameType == GAME_TYPE_DIGLETT)
            FREE_AND_SET_NULL(sPinballGame->diglett.collisionMap);

        SetMainCallback2(sPinballGame->returnMainCallback);
        FREE_AND_SET_NULL(sPinballGame);
    }
}

static void UpdateBallSprite(struct Sprite *sprite)
{
    int ballAnim;
    struct Ball *ball = &sPinballGame->ball;
    sprite->pos1.x = (ball->xPos >> 8) - sPinballGame->cameraScrollX;
    sprite->pos1.y = (ball->yPos >> 8) - sPinballGame->cameraScrollY;

    ball->rotation += ball->spin;
    ballAnim = (ball->rotation >> 4) % 8;
    StartSpriteAnim(sprite, ballAnim);
}

static void UpdateFlipperSprite(struct Sprite *sprite)
{
    int anim;
    struct Flipper *flipper;
    if (sprite->data[0] == FLIPPER_RIGHT)
        flipper = &sPinballGame->rightFlipper;
    else
        flipper = &sPinballGame->leftFlipper;

    sprite->pos1.x = flipper->xPos - sPinballGame->cameraScrollX;
    sprite->pos1.y = flipper->yPos - sPinballGame->cameraScrollY;

    anim = (flipper->type * 3) + ((flipper->state >> 8) / 6);
    StartSpriteAnim(sprite, anim);
}

static void UpdateTimerDigitSprite(struct Sprite *sprite)
{
    int minutes, tensDigit, onesDigit;
    int type = sprite->data[0];

    switch (type)
    {
    case 0: // Minutes ones digit
        minutes = (sPinballGame->timer.ticks / 3600) % 10;
        StartSpriteAnim(sprite, minutes);
        break;
    case 2: // Seconds tens digit
        tensDigit = ((sPinballGame->timer.ticks / 60) % 60) / 10;
        StartSpriteAnim(sprite, tensDigit);
        break;
    case 3: // Seconds ones digit
        onesDigit = ((sPinballGame->timer.ticks / 60) % 60) % 10;
        StartSpriteAnim(sprite, onesDigit);
        break;
    }
}

static bool32 UpdateGameType(u8 gameType)
{
    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        return UpdateMeowth(&sPinballGame->meowth);
    case GAME_TYPE_DIGLETT:
        return UpdateDiglett(&sPinballGame->diglett);
    case GAME_TYPE_SEEL:
        return UpdateSeel(&sPinballGame->seel);
    case GAME_TYPE_GENGAR:
        return UpdateGengar(&sPinballGame->gengar);
    default:
        return FALSE;
    }
}

#define MEOWTH_HORIZONTAL_SPEED 1
#define MEOWTH_VERTICAL_SPEED 1

static bool32 UpdateMeowth(struct Meowth *meowth)
{
    if (meowth->state == MEOWTH_STATE_WALK)
    {
        if (meowth->facing == MEOWTH_FACING_RIGHT)
            meowth->xPos += MEOWTH_HORIZONTAL_SPEED;
        else
            meowth->xPos -= MEOWTH_HORIZONTAL_SPEED;

        meowth->yPos += meowth->yMovement;

        if (meowth->xPos > 136)
        {
            meowth->facing = MEOWTH_FACING_LEFT;
            meowth->xPos = 136;
        }
        else if (meowth->xPos < 24)
        {
            meowth->facing = MEOWTH_FACING_RIGHT;
            meowth->xPos = 24;
        }
        else if (gMain.vblankCounter1 % 64 == 0)
        {
            meowth->facing = Random() % 2 ? MEOWTH_FACING_RIGHT : MEOWTH_FACING_LEFT;
        }

        if (meowth->yPos > 48)
        {
            meowth->yPos = 48;
            meowth->yMovement = 0;
        }
        else if (meowth->yPos < 32)
        {
            meowth->yPos = 32;
            meowth->yMovement = 0;
        }
        else if (gMain.vblankCounter1 % 64 == 0)
        {
            meowth->yMovement = Random() % 2 ? -MEOWTH_VERTICAL_SPEED : MEOWTH_VERTICAL_SPEED;
        }
    }

    UpdateJewels(meowth->jewels);
    return meowth->completed;
}

static bool32 CheckObjectsCollision(u8 gameType, struct Ball *ball, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    bool32 isColliding = FALSE;

    switch (gameType)
    {
    case GAME_TYPE_MEOWTH:
        isColliding = CheckMeowthCollision(ball, &sPinballGame->meowth, ticks, outCollisionNormal, outCollisionAmplification);
        if (!isColliding)
            isColliding = CheckMeowthJewelsCollision(ball, &sPinballGame->meowth, outCollisionNormal);
        break;
    case GAME_TYPE_DIGLETT:
        isColliding = FALSE;
        break;
    case GAME_TYPE_SEEL:
        isColliding = CheckSeelCollision(ball, &sPinballGame->seel, ticks, outCollisionNormal, outCollisionAmplification);
        break;
    case GAME_TYPE_GENGAR:
        isColliding = FALSE;
        break;
    }

    return isColliding;
}

static bool32 CheckMeowthCollision(struct Ball *ball, struct Meowth *meowth, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    int x, y;
    u8 collisionNormal;
    int ballXPos = (ball->xPos >> 8);
    int ballYPos = (ball->yPos >> 8);

    if (ticks <= 0)
        return FALSE;

    if (ballXPos < meowth->xPos - 24 || ballXPos >= meowth->xPos + 24
     || ballYPos < meowth->yPos - 20 || ballYPos >= meowth->yPos + 20)
        return FALSE;

    x = ballXPos - meowth->xPos + 24;
    y = ballYPos - meowth->yPos + 20;
    collisionNormal = sMeowthCollisionNormalAngles[y * 48 + x];
    if (collisionNormal == 0xFF)
        return FALSE;

    // Multiply normal by two because the original data is stored halved.
    *outCollisionNormal = collisionNormal * 2;
    //*outCollisionAmplification = 1;

    if (meowth->state == MEOWTH_STATE_WALK)
    {
        meowth->state = MEOWTH_STATE_HIT;
        meowth->hitDuration = 30;
        TryCreateNewJewel(meowth, ballXPos);
    }

    return TRUE;
}

static bool32 CheckMeowthJewelsCollision(struct Ball *ball, struct Meowth *meowth, u8 *outCollisionNormal)
{
    int i;
    struct Sprite *sparkleSprite = &gSprites[meowth->sparkleSpriteId];

    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        struct MeowthJewel *jewel = &meowth->jewels[i];
        if (jewel->state == JEWEL_STATE_LANDED)
        {
            if (CheckJewelCollision(ball, jewel, outCollisionNormal))
            {
                if (++meowth->jewelStreak > 6)
                    meowth->jewelStreak = 6;

                meowth->score += meowth->jewelStreak;
                if (!meowth->completed && meowth->score >= 20)
                    meowth->completed = TRUE;

                sparkleSprite->data[0] = JEWEL_SPARKLE_DURATION;
                sparkleSprite->data[1] = min(20, meowth->score);
                DrawMeowthScoreJewels(meowth);
                if (meowth->jewelStreak > 1)
                {
                    int y = (jewel->yPos >> 8) - 8;
                    u8 spriteId = CreateSprite(&sMeowthJewelMultiplierSpriteTemplate, jewel->xPos, y, 4);
                    gSprites[spriteId].data[2] = y;
                    StartSpriteAnim(&gSprites[spriteId], meowth->jewelStreak - 2);
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

static int GetNumActiveJewels(struct Meowth *meowth)
{
    int i, count;
    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        if (meowth->jewels[i].state != JEWEL_STATE_HIDDEN)
            count++;
    }
    return count;
}

static struct MeowthJewel *TryCreateNewJewel(struct Meowth *meowth, int ballXPos)
{
    int i, count;
    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        if (meowth->jewels[i].state == JEWEL_STATE_HIDDEN)
            break;
    }

    if (i == MAX_MEOWTH_JEWELS)
        return NULL;

    meowth->jewelStreak = 0;

    meowth->jewels[i].state = JEWEL_STATE_FALLING;
    meowth->jewels[i].xPos = meowth->xPos;
    meowth->jewels[i].yPos = (meowth->yPos - 12) << 8;
    meowth->jewels[i].spriteId = CreateSprite(&sMeowthJewelSpriteTemplate, meowth->jewels[i].xPos, meowth->jewels[i].yPos, 4);
    meowth->jewels[i].xVelocity = ballXPos < meowth->xPos ? 2 : -2;
    meowth->jewels[i].yVelocity = -2 << 8;
    meowth->jewels[i].destYPos = meowth->yPos < 40 ? 72 : 88;
    gSprites[meowth->jewels[i].spriteId].data[0] = i;
    gSprites[meowth->jewels[i].spriteId].data[1] = JEWEL_STATE_HIDDEN;

    return &meowth->jewels[i];
}

static void UpdateJewels(struct MeowthJewel *jewels)
{
    int i;
    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        struct MeowthJewel *jewel = &jewels[i];
        if (jewel->state == JEWEL_STATE_FALLING)
        {
            jewel->xPos += jewel->xVelocity;
            if (jewel->xPos < 16)
            {
                jewel->xPos = 16;
                jewel->xVelocity *= -1;
            }
            else if (jewel->xPos >= 148)
            {
                jewel->xPos = 148;
                jewel->xVelocity *= -1;
            }

            jewel->yPos += jewel->yVelocity;
            jewel->yVelocity += 0x40;
            if ((jewel->yPos >> 8) >= jewel->destYPos)
            {
                if (IsJewelSpaceOccupied(jewel->xPos, jewel->destYPos, jewels))
                {
                    jewel->yVelocity = -1 << 8;
                }
                else
                {
                    jewel->yPos = jewel->destYPos << 8;
                    jewel->state = JEWEL_STATE_LANDED;
                }
            }
        }
    }
}

static bool32 IsJewelSpaceOccupied(u16 xPos, u16 destYPos, struct MeowthJewel *jewels)
{
    int i;
    struct MeowthJewel *jewel;
    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        jewel = &jewels[i];
        if (jewel->state == JEWEL_STATE_LANDED && jewel->destYPos == destYPos && abs(xPos - jewel->xPos) < 16)
            return TRUE;
    }

    return FALSE;
}

static bool32 CheckJewelCollision(struct Ball *ball, struct MeowthJewel *jewel, u8 *outCollisionNormal)
{
    int x, y;
    u8 collisionNormal;
    int ballXPos = (ball->xPos >> 8);
    int ballYPos = (ball->yPos >> 8);
    int jewelXPos = jewel->xPos;
    int jewelYPos = jewel->yPos >> 8;
    if (ballXPos < jewelXPos - 12 || ballXPos >= jewelXPos + 12
     || ballYPos < jewelYPos - 12 || ballYPos >= jewelYPos + 12)
        return FALSE;

    x = ballXPos - jewelXPos + 12;
    y = ballYPos - jewelYPos + 12;
    collisionNormal = sMeowthJewelCollisionNormalAngles[y * 24 + x];
    if (collisionNormal == 0xFF)
        return FALSE;

    // Multiply normal by two because the original data is stored halved.
    *outCollisionNormal = collisionNormal * 2;
    jewel->state = JEWEL_STATE_CONSUMED;
    return TRUE;
}

static void UpdateMeowthSprite(struct Sprite *sprite)
{
    int animNum;
    struct Meowth *meowth = &sPinballGame->meowth;
    int prevState = sprite->data[0];
    int prevFacing = sprite->data[1];
    int curState = meowth->state;
    int curFacing = meowth->facing;
    sprite->pos1.x = meowth->xPos;
    sprite->pos1.y = meowth->yPos;

    // Check if Meowth's state changed, and start the appropriate
    // sprite animation.
    if (prevState != curState || prevFacing != curFacing)
    {
        sprite->data[0] = curState;
        sprite->data[1] = curFacing;
        switch (curState)
        {
        case MEOWTH_STATE_WALK:
            animNum = curFacing == MEOWTH_FACING_RIGHT ? 0 : 1;
            StartSpriteAnim(sprite, animNum);
            break;
        case MEOWTH_STATE_HIT:
            animNum = curFacing == MEOWTH_FACING_RIGHT ? 2 : 3;
            StartSpriteAnim(sprite, animNum);
            break;
        case MEOWTH_STATE_FINISH:
            StartSpriteAnim(sprite, 4);
            break;
        }
    }

    if (curState == MEOWTH_STATE_HIT)
    {
        if (--meowth->hitDuration == 0)
            meowth->state = MEOWTH_STATE_WALK;
    }
}

static void UpdateMeowthJewelSprite(struct Sprite *sprite)
{
    int jewelId = sprite->data[0];
    struct MeowthJewel *jewel = &sPinballGame->meowth.jewels[jewelId];
    int prevState = sprite->data[1];
    int curState = jewel->state;
    sprite->pos1.x = jewel->xPos;
    sprite->pos1.y = jewel->yPos >> 8;
    if (prevState != curState)
    {
        sprite->data[1] = curState;
        switch (curState)
        {
        case JEWEL_STATE_HIDDEN:
            DestroySprite(sprite);
            break;
        case JEWEL_STATE_FALLING:
            StartSpriteAnim(sprite, 0);
            break;
        case JEWEL_STATE_LANDED:
            StartSpriteAnim(sprite, 1);
            break;
        case JEWEL_STATE_CONSUMED:
            StartSpriteAnim(sprite, 2);
            break;
        }
    }

    if (curState == JEWEL_STATE_CONSUMED && sprite->animEnded)
    {
        sPinballGame->meowth.jewels[jewelId].state = JEWEL_STATE_HIDDEN;
        DestroySprite(sprite);
    }
}

static void UpdateMeowthJewelMultiplierSprite(struct Sprite *sprite)
{
    // data[0] = state
    // data[1] = state counter
    // data[2] = original y position
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.y--;
        if (++sprite->data[1] == 5)
        {
            sprite->data[0] = 1;
            sprite->data[1] = 0;
            sprite->pos1.y = sprite->data[2];
        }
        break;
    case 1:
        if (++sprite->data[1] >= 22)
        {
            sprite->data[0] = 2;
            sprite->data[1] = 0;
        }
        break;
    case 2:
        if (++sprite->data[1] >= 24)
        {
            DestroySprite(sprite);
            return;
        }

        if (sprite->data[1] % 8 < 4)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
        break;
    }
}

static void ResetMeowthJewels(struct Meowth *meowth)
{
    int i;
    for (i = 0; i < MAX_MEOWTH_JEWELS; i++)
    {
        struct MeowthJewel *jewel = &meowth->jewels[i];
        if (jewel->state != JEWEL_STATE_HIDDEN)
        {
            DestroySprite(&gSprites[jewel->spriteId]);
            jewel->state = JEWEL_STATE_HIDDEN;
        }
    }
}

static void UpdateMeowthJewelSparkleSprite(struct Sprite *sprite)
{
    // data[0] is visibility counter timer
    // data[1] is the player's score, capped at 20.
    if (sprite->data[0] == 0)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->data[0]--;
        sprite->pos1.x = (sprite->data[1] - 1) * 8 + 4;
        sprite->pos1.y = 4;
        sprite->invisible = FALSE;
    }
}

static bool32 UpdateDiglett(struct Diglett *diglett)
{
    u16 *tilemap;

    if (!diglett->initialized)
    {
        if (gMain.vblankCounter1 & 1)
        {
            int index = sDiglettInitOrder[diglett->curInitIndex];
            diglett->states[index] = DIGLETT_STATE_IDLE_0 + (Random() % 4);

            tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
            UpdateDiglettTiles(tilemap, index, diglett);
            CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
            UpdateDiglettCollision(diglett->collisionMap, index, TRUE);

            if (++diglett->curInitIndex == NUM_DIGLETTS)
                diglett->initialized = TRUE;
        }
    }
    else if (diglett->numDiglettsHit < NUM_DIGLETTS)
    {
        // Update 4 digletts each frame.
        int i;
        for (i = 0; i < 4; i++)
        {
            int index = (diglett->curUpdateIndex + i) % NUM_DIGLETTS;
            switch (diglett->states[index])
            {
            case DIGLETT_STATE_INIT:
            case DIGLETT_STATE_HIDDEN:
                break;
            case DIGLETT_STATE_IDLE_0:
                diglett->states[index] = DIGLETT_STATE_IDLE_1;
                break;
            case DIGLETT_STATE_IDLE_1:
                diglett->states[index] = DIGLETT_STATE_IDLE_2;
                break;
            case DIGLETT_STATE_IDLE_2:
                diglett->states[index] = DIGLETT_STATE_IDLE_3;
                break;
            case DIGLETT_STATE_IDLE_3:
                diglett->states[index] = DIGLETT_STATE_IDLE_0;
                break;
            case DIGLETT_STATE_HIT_0:
                diglett->states[index] = DIGLETT_STATE_HIT_1;
                break;
            case DIGLETT_STATE_HIT_1:
                diglett->states[index] = DIGLETT_STATE_HIT_2;
                break;
            case DIGLETT_STATE_HIT_2:
                diglett->states[index] = DIGLETT_STATE_HIDDEN;
                UpdateDiglettCollision(diglett->collisionMap, index, FALSE);
                if (++diglett->numDiglettsHit == NUM_DIGLETTS)
                {
                    diglett->dugtrioState = DUGTRIO_STATE_3ALIVE;

                    // Update the colision tilemap for the Dugtrio-occupied tiles.
                    tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
                    diglett->collisionMap[0x48] = 0x14;
                    diglett->collisionMap[0x49] = 0x14;
                    diglett->collisionMap[0x4A] = 0x14;
                    diglett->collisionMap[0x4B] = 0x14;
                    diglett->collisionMap[0x68] = 0x15;
                    diglett->collisionMap[0x69] = 0x16;
                    diglett->collisionMap[0x6A] = 0x17;
                    diglett->collisionMap[0x6B] = 0x18;
                }
                break;
            }

            // Update bg tilemap for the new diglett states.
            tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
            UpdateDiglettTiles(tilemap, index, diglett);
        }

        CopyBgTilemapBufferToVram(PINBALL_BG_BASE);
        diglett->curUpdateIndex = (diglett->curUpdateIndex + 4) % NUM_DIGLETTS;
    }
    else
    {
        // At this point, all the Digletts are hidden and Dugtrio is visible.
        struct Sprite *dugtrioSprite = &gSprites[diglett->dugtrioSpriteId];
        switch (diglett->dugtrioState)
        {
        case DUGTRIO_STATE_3ALIVE_HIT:
            if (dugtrioSprite->animEnded)
                diglett->dugtrioState = DUGTRIO_STATE_2ALIVE;
            break;
        case DUGTRIO_STATE_2ALIVE_HIT:
            if (dugtrioSprite->animEnded)
                diglett->dugtrioState = DUGTRIO_STATE_1ALIVE;
            break;
        case DUGTRIO_STATE_1ALIVE_HIT:
            if (dugtrioSprite->animEnded)
            {
                diglett->dugtrioState = DUGTRIO_STATE_0ALIVE;
                StartSpriteAnim(dugtrioSprite, 7);
                DisableFlippers();
                diglett->completed = TRUE;
                return TRUE;
            }
            break;
        case DUGTRIO_STATE_0ALIVE:
            if (dugtrioSprite->animEnded)
                diglett->dugtrioState = DUGTRIO_STATE_COMPLETE;
            return TRUE;
        }
    }

    return FALSE;
}

static void UpdateDiglettTiles(u16 *tilemap, int index, struct Diglett *diglett)
{
    int tileIndex = sDiglettCoords[index][0] + sDiglettCoords[index][1] * 32;
    tilemap[tileIndex]      = sDiglettStateTiles[diglett->states[index]][0];
    tilemap[tileIndex + 1]  = sDiglettStateTiles[diglett->states[index]][1];
    tilemap[tileIndex + 32] = sDiglettStateTiles[diglett->states[index]][2];
    tilemap[tileIndex + 33] = sDiglettStateTiles[diglett->states[index]][3];
}

static void UpdateDiglettCollision(u8 *collisionMap, int index, bool32 solidCollision)
{
    int tileIndex = sDiglettCoords[index][0] + sDiglettCoords[index][1] * 32;
    if (solidCollision)
    {
        collisionMap[tileIndex]      = 0x19;
        collisionMap[tileIndex + 1]  = 0x19;
        collisionMap[tileIndex + 32] = 0x1A;
        collisionMap[tileIndex + 33] = 0x1B;
    }
    else
    {
        collisionMap[tileIndex]      = 0x2;
        collisionMap[tileIndex + 1]  = 0x2;
        collisionMap[tileIndex + 32] = 0x2;
        collisionMap[tileIndex + 33] = 0x2;
    }
}

static void UpdateDugtrioSprite(struct Sprite *sprite)
{
    // data[0] = previous state
    struct Diglett *diglett = &sPinballGame->diglett;
    int prevState = sprite->data[0];
    int curState = diglett->dugtrioState;

    // Check if Dugtrio's state changed, and start the appropriate
    // sprite animation.
    if (prevState != curState)
    {
        sprite->data[0] = curState;
        switch (curState)
        {
        case DUGTRIO_STATE_HIDDEN:
            StartSpriteAnim(sprite, 0);
            break;
        case DUGTRIO_STATE_3ALIVE:
            StartSpriteAnim(sprite, 1);
            break;
        case DUGTRIO_STATE_3ALIVE_HIT:
            StartSpriteAnim(sprite, 2);
            break;
        case DUGTRIO_STATE_2ALIVE:
            StartSpriteAnim(sprite, 3);
            break;
        case DUGTRIO_STATE_2ALIVE_HIT:
            StartSpriteAnim(sprite, 4);
            break;
        case DUGTRIO_STATE_1ALIVE:
            StartSpriteAnim(sprite, 5);
            break;
        case DUGTRIO_STATE_1ALIVE_HIT:
            StartSpriteAnim(sprite, 6);
            break;
        case DUGTRIO_STATE_0ALIVE:
            StartSpriteAnim(sprite, 7);
            break;
        case DUGTRIO_STATE_COMPLETE:
            StartSpriteAnim(sprite, 0);
            break;
        }
    }
}

static bool32 CheckSeelCollision(struct Ball *ball, struct Seel *seel, u32 ticks, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    int x, y;
    u8 collisionNormal;
    struct Sprite *sparkleSprite = &gSprites[seel->sparkleSpriteId];
    struct SeelSwimmer *swimmer = &seel->swimmers[seel->emergingSwimmerIndex];
    int ballXPos = (ball->xPos >> 8);
    int ballYPos = (ball->yPos >> 8);
    int swimmerXPos = (swimmer->xPos >> 8);
    int swimmerYPos = (swimmer->yPos >> 8);

    if (ticks <= 0)
        return FALSE;

    if (swimmer->state != SEEL_STATE_VISIBLE_RIGHT && swimmer->state != SEEL_STATE_VISIBLE_LEFT)
        return FALSE;

    if (ballXPos < swimmerXPos - 16 || ballXPos >= swimmerXPos + 16
     || ballYPos < swimmerYPos - 16 || ballYPos >= swimmerYPos + 16)
        return FALSE;

    x = ballXPos - swimmerXPos + 16;
    y = ballYPos - swimmerYPos + 16;
    collisionNormal = sSeelCollisionNormalAngles[y * 32 + x];
    if (collisionNormal == 0xFF)
        return FALSE;

    // Multiply normal by two because the original data is stored halved.
    *outCollisionNormal = collisionNormal * 2;
    //*outCollisionAmplification = 1;

    if (swimmer->state == SEEL_STATE_VISIBLE_RIGHT)
        swimmer->state = SEEL_STATE_HIT_RIGHT;
    else
        swimmer->state = SEEL_STATE_HIT_LEFT;

    seel->score += seel->streak + 1;
    if (!seel->completed && seel->score >= 20)
        seel->completed = TRUE;

    if (++seel->streak >= 9)
        seel->streak = 0;

    sparkleSprite->data[0] = SEEL_SPARKLE_DURATION;
    sparkleSprite->data[1] = min(20, seel->score);
    DrawSeelScoreJewels(seel);
    if (seel->streak > 1)
    {
        int y = swimmerYPos - 16;
        u8 spriteId = CreateSprite(&sSeelMultiplierSpriteTemplate, swimmerXPos, y, 4);
        gSprites[spriteId].data[2] = y;
        StartSpriteAnim(&gSprites[spriteId], seel->streak - 2);
    }

    return TRUE;
}

#define SEEL_SWIMMER_SPEED 0x34

static bool32 UpdateSeel(struct Seel *seel)
{
    int i;

    for (i = 0; i < NUM_SEELS; i++)
    {
        struct SeelSwimmer *swimmer = &seel->swimmers[i];
        struct Sprite *swimmerSprite = &gSprites[swimmer->spriteId];
        switch (swimmer->state)
        {
        case SEEL_STATE_SWIM_RIGHT:
            swimmer->xPos += SEEL_SWIMMER_SPEED;
            if ((swimmer->xPos >> 8) > 136)
            {
                swimmer->state = SEEL_STATE_TURN_LEFT;
                swimmer->xPos = 136 << 8;
            }
            else if (seel->emergingSwimmerIndex == i)
            {
                if (--seel->emergingSwimmerCounter == 0)
                    swimmer->state = SEEL_STATE_EMERGE_RIGHT;
            }
            break;
        case SEEL_STATE_TURN_LEFT:
            if (swimmerSprite->animEnded)
                swimmer->state = SEEL_STATE_SWIM_LEFT;
            break;
        case SEEL_STATE_SWIM_LEFT:
            swimmer->xPos -= SEEL_SWIMMER_SPEED;
            if ((swimmer->xPos >> 8) < 24)
            {
                swimmer->state = SEEL_STATE_TURN_RIGHT;
                swimmer->xPos = 24 << 8;
            }
            else if (seel->emergingSwimmerIndex == i)
            {
                if (--seel->emergingSwimmerCounter == 0)
                    swimmer->state = SEEL_STATE_EMERGE_LEFT;
            }
            break;
        case SEEL_STATE_TURN_RIGHT:
            if (swimmerSprite->animEnded)
                swimmer->state = SEEL_STATE_SWIM_RIGHT;
            break;
        case SEEL_STATE_EMERGE_RIGHT:
            if (swimmerSprite->animEnded)
            {
                swimmer->state = SEEL_STATE_VISIBLE_RIGHT;
                swimmer->counter = GetSeelVisibleTicks(seel->streak);
            }
            break;
        case SEEL_STATE_EMERGE_LEFT:
            if (swimmerSprite->animEnded)
            {
                swimmer->state = SEEL_STATE_VISIBLE_LEFT;
                swimmer->counter = GetSeelVisibleTicks(seel->streak);
            }
            break;
        case SEEL_STATE_VISIBLE_RIGHT:
        case SEEL_STATE_VISIBLE_LEFT:
            if (--swimmer->counter == 0)
            {
                swimmer->state = (Random() & 1) ? SEEL_STATE_SUBMERGE_RIGHT : SEEL_STATE_SUBMERGE_LEFT;
                seel->streak = 0;
            }
            break;
        case SEEL_STATE_SUBMERGE_RIGHT:
        case SEEL_STATE_HIT_RIGHT:
            if (swimmerSprite->animEnded)
            {
                swimmer->state = SEEL_STATE_SWIM_RIGHT;
                ChooseNextEmergingSeel(i, seel);
            }
            break;
        case SEEL_STATE_SUBMERGE_LEFT:
        case SEEL_STATE_HIT_LEFT:
            if (swimmerSprite->animEnded)
            {
                swimmer->state = SEEL_STATE_SWIM_LEFT;
                ChooseNextEmergingSeel(i, seel);
            }
            break;
        }
    }

    return seel->completed;
}

static void ChooseNextEmergingSeel(int curSeelIndex, struct Seel *seel)
{
    int index;
    do {
        index = Random() % NUM_SEELS;
    } while (index == curSeelIndex);

    seel->emergingSwimmerIndex = index;
    seel->emergingSwimmerCounter = Random() % 60;
}

static u32 GetSeelVisibleTicks(int curStreak)
{
    if (curStreak < 2)
        return 3 * 60;

    if (curStreak < 6)
        return 2 * 60;

    return 1 * 60;
}

static void ResetSeels(struct Seel *seel)
{
    int i;
    bool32 isSeelVisible = FALSE;

    for (i = 0; i < NUM_SEELS; i++)
    {
        struct SeelSwimmer *swimmer = &seel->swimmers[i];
        if (swimmer->state == SEEL_STATE_VISIBLE_RIGHT || swimmer->state == SEEL_STATE_VISIBLE_LEFT)
        {
            isSeelVisible = TRUE;
            break;
        }
    }

    for (i = 0; i < NUM_SEELS; i++)
    {
        struct SeelSwimmer *swimmer = &seel->swimmers[i];
        if (isSeelVisible)
        {
            // Reset to original positions.
            // The original game does this for some reason.
            swimmer->state = sInitialSeelStates[i];
            swimmer->xPos = sInitialSeelCoords[i][0] << 8;
            swimmer->yPos = sInitialSeelCoords[i][1] << 8;
        }
        else
        {
            // Revert the seel back to a swimming state, depending on
            // its current direction.
            swimmer->state = (swimmer->state == SEEL_STATE_SWIM_RIGHT     ||
                              swimmer->state == SEEL_STATE_TURN_LEFT      ||
                              swimmer->state == SEEL_STATE_EMERGE_RIGHT   ||
                              swimmer->state == SEEL_STATE_SUBMERGE_RIGHT ||
                              swimmer->state == SEEL_STATE_HIT_RIGHT)
                            ? SEEL_STATE_SWIM_RIGHT
                            : SEEL_STATE_SWIM_LEFT;
        }
    }
}

static void UpdateSeelSprite(struct Sprite *sprite)
{
    // data[0] = previous state
    // data[1] = seel swimmer index
    struct SeelSwimmer *swimmer = &sPinballGame->seel.swimmers[sprite->data[1]];
    int prevState = sprite->data[0];
    int curState = swimmer->state;
    sprite->pos1.x = swimmer->xPos >> 8;
    sprite->pos1.y = swimmer->yPos >> 8;

    // Check if this Seel's state changed, and start the appropriate
    // sprite animation.
    if (prevState != curState)
    {
        sprite->data[0] = curState;
        switch (curState)
        {
        case SEEL_STATE_SWIM_RIGHT:
            StartSpriteAnim(sprite, 0);
            break;
        case SEEL_STATE_TURN_LEFT:
            StartSpriteAnim(sprite, 1);
            break;
        case SEEL_STATE_SWIM_LEFT:
            StartSpriteAnim(sprite, 2);
            break;
        case SEEL_STATE_TURN_RIGHT:
            StartSpriteAnim(sprite, 3);
            break;
        case SEEL_STATE_EMERGE_RIGHT:
            StartSpriteAnim(sprite, 4);
            break;
        case SEEL_STATE_EMERGE_LEFT:
            StartSpriteAnim(sprite, 5);
            break;
        case SEEL_STATE_VISIBLE_RIGHT:
        case SEEL_STATE_VISIBLE_LEFT:
            StartSpriteAnim(sprite, 6);
            break;
        case SEEL_STATE_SUBMERGE_RIGHT:
            StartSpriteAnim(sprite, 7);
            break;
        case SEEL_STATE_SUBMERGE_LEFT:
            StartSpriteAnim(sprite, 8);
            break;
        case SEEL_STATE_HIT_RIGHT:
            StartSpriteAnim(sprite, 9);
            break;
        case SEEL_STATE_HIT_LEFT:
            StartSpriteAnim(sprite, 10);
            break;
        }
    }
}

static void UpdateSeelSparkleSprite(struct Sprite *sprite)
{
    // data[0] is visibility counter timer
    // data[1] is the player's score, capped at 20.
    if (sprite->data[0] == 0)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->data[0]--;
        sprite->pos1.x = (sprite->data[1] - 1) * 8 + 4;
        sprite->pos1.y = 4;
        sprite->invisible = FALSE;
    }
}

static void UpdateSeelMultiplierSprite(struct Sprite *sprite)
{
    // data[0] = state
    // data[1] = state counter
    // data[2] = original y position
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.y--;
        if (++sprite->data[1] == 5)
        {
            sprite->data[0] = 1;
            sprite->data[1] = 0;
            sprite->pos1.y = sprite->data[2];
        }
        break;
    case 1:
        if (++sprite->data[1] >= 22)
        {
            sprite->data[0] = 2;
            sprite->data[1] = 0;
        }
        break;
    case 2:
        if (++sprite->data[1] >= 24)
        {
            DestroySprite(sprite);
            return;
        }

        if (sprite->data[1] % 8 < 4)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
        break;
    }
}

static bool32 UpdateGengar(struct Gengar *gengar)
{
    return FALSE;
}
