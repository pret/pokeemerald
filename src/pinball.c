#include "global.h"
#include "bg.h"
#include "decompress.h"
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
// like the example below.
//
// ...
// callnative PlayPinballGame
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

enum
{
    PINBALL_STATE_INIT,
    PINBALL_STATE_RUNNING,
    PINBALL_LOST_BALL_FADE_OUT,
    PINBALL_LOST_BALL_FADE_IN,
    PINBALL_STATE_START_EXIT,
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

struct PinballGame
{
    u8 state;
    struct Ball ball;
    struct Flipper leftFlipper;
    struct Flipper rightFlipper;
    bool8 gravityEnabled;
    u8 stageTileWidth;
    u8 stageTileHeight;
    u16 cameraScrollX;
    u16 cameraScrollY;
    struct Meowth meowth;
    bool8 ballIsEntering;
    MainCallback returnMainCallback;
};

static void FadeToPinballScreen(u8 taskId);
static void InitPinballScreen(void);
static void InitPinballGame(void);
static void InitBallSprite(void);
static void InitFlipperSprites(void);
static void InitMeowth(void);
static void PinballVBlankCallback(void);
static void PinballMainCallback(void);
static void PinballMain(u8 taskId);
static void StartNewBall(void);
static void LoseBall(void);
static void LoseBallMeowth(struct Meowth *meowth);
static void DrawMeowthScoreJewels(struct Meowth *meowth);
static void OpenEntrance(void);
static void HandleBallPhysics(void);
static void ApplyGravity(struct Ball *ball);
static void LimitVelocity(struct Ball *ball);
static bool32 HandleFlippers(struct Ball *ball, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification);
static void UpdateFlipperState(struct Flipper *flipper);
static bool32 CheckFlipperCollision(struct Ball *ball, struct Flipper *flipper, u16 *outYForce, u8 *outCollisionNormal, int *outCollisionAmplification);
static void UpdatePosition(struct Ball *ball);
static bool32 CheckStaticCollision(struct Ball *ball, bool32 ballIsEntering, int stageTileWidth, int stageTileHeight, u8 *outCollisionNormal);
static u8 GetCollisionMaskRow(int collisionAttribute, int row);
static void RotateVector(s16 *x, s16 *y, u8 angle);
static u8 ReverseBits(u8 value);
static void ApplyCollisionForces(struct Ball *ball, u16 flipperYForce, int collisionAmplification);
static void UpdateCamera(void);
static void StartExitPinballGame(void);
static void ExitPinballGame(void);
static void UpdateBallSprite(struct Sprite *sprite);
static void UpdateFlipperSprite(struct Sprite *sprite);
static void UpdateMeowth(struct Meowth *meowth);
static bool32 CheckObjectsCollision(struct Ball *ball, u8 *outCollisionNormal, int *outCollisionAmplification);
static bool32 CheckMeowthCollision(struct Ball *ball, struct Meowth *meowth, u8 *outCollisionNormal, int *outCollisionAmplification);
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

static const u32 sMeowthStageBgGfx[] = INCBIN_U32("graphics/pinball/bg_tiles_meowth.4bpp");
static const u16 sMeowthStageBgPalette[] = INCBIN_U16("graphics/pinball/bg_tiles_meowth.gbapal");
static const u16 sMeowthStageBgTilemap[] = INCBIN_U16("graphics/pinball/bg_tilemap_meowth.bin");
static const u8 sMeowthStageBgCollisionMasks[] = INCBIN_U8("graphics/pinball/bg_collision_masks_meowth.1bpp");
static const u8 sMeowthStageBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_meowth.bin");
static const u8 sMeowthStageEntranceBgCollisionMap[] = INCBIN_U8("graphics/pinball/bg_collision_map_meowth_entrance.bin");
static const u8 sFlipperLeftMeowthCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_left_masks_meowth.1bpp");
static const u8 sFlipperRightMeowthCollisionMasks[][0x80] = INCBIN_U8("graphics/pinball/flipper_right_masks_meowth.1bpp");

static const u32 sBallPokeballGfx[] = INCBIN_U32("graphics/pinball/ball_pokeball.4bpp.lz");
static const u16 sBallPokeballPalette[] = INCBIN_U16("graphics/pinball/ball_pokeball.gbapal");
static const u32 sFlipperGfx[] = INCBIN_U32("graphics/pinball/flipper.4bpp.lz");
static const u16 sFlipperPalette[] = INCBIN_U16("graphics/pinball/flipper.gbapal");

static const u8 sFlipperCollisionRadii[] = INCBIN_U8("data/pinball/flipper_radii.bin");
static const u8 sFlipperCollisionNormalAngles[] = INCBIN_U8("data/pinball/flipper_normal_angles.bin");

static const u32 sMeowthAnimationGfx[] = INCBIN_U32("graphics/pinball/meowth_animation.4bpp.lz");
static const u16 sMeowthAnimationPalette[] = INCBIN_U16("graphics/pinball/meowth_animation.gbapal");
static const u32 sMeowthJewelGfx[] = INCBIN_U32("graphics/pinball/meowth_jewel_animation.4bpp.lz");
static const u16 sMeowthJewelPalette[] = INCBIN_U16("graphics/pinball/meowth_jewel_animation.gbapal");
static const u32 sMeowthJewelMultipliersGfx[] = INCBIN_U32("graphics/pinball/meowth_jewel_multipliers.4bpp.lz");
static const u32 sMeowthJewelSparkleGfx[] = INCBIN_U32("graphics/pinball/meowth_sparkle.4bpp.lz");
static const u16 sMeowthJewelMultipliersPalette[] = INCBIN_U16("graphics/pinball/meowth_jewel_multipliers.gbapal");
static const u8 sMeowthCollisionNormalAngles[] = INCBIN_U8("data/pinball/meowth_normal_angles.bin");
static const u8 sMeowthJewelCollisionNormalAngles[] = INCBIN_U8("data/pinball/meowth_jewel_normal_angles.bin");

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

static const struct SpritePalette sPinballSpritePalette = { sBallPokeballPalette, TAG_BALL_POKEBALL };
static const struct SpritePalette sFlipperSpritePalette = { sFlipperPalette, TAG_FLIPPER };
static const struct SpritePalette sMeowthAnimationSpritePalette = { sMeowthAnimationPalette, TAG_MEOWTH };
static const struct SpritePalette sMeowthJewelSpritePalette = { sMeowthJewelPalette, TAG_MEOWTH_JEWEL };
static const struct SpritePalette sMeowthJewelMultipliersSpritePalette = { sMeowthJewelMultipliersPalette, TAG_MEOWTH_JEWEL_MUTLIPLIER };

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

void PlayPinballGame(void)
{
    u8 taskId;

    ScriptContext1_Stop();
    sPinballGame = AllocZeroed(sizeof(*sPinballGame));
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
        LoadBgTiles(PINBALL_BG_BASE, sMeowthStageBgGfx, sizeof(sMeowthStageBgGfx), 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sMeowthStageBgTilemap, sizeof(sMeowthStageBgTilemap), 0);
        ResetPaletteFade();
        LoadPalette(sMeowthStageBgPalette, 0, sizeof(sMeowthStageBgPalette));
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
        LoadCompressedSpriteSheet(&sMeowthAnimationSpriteSheet);
        LoadSpritePalette(&sMeowthAnimationSpritePalette);
        LoadCompressedSpriteSheet(&sMeowthJewelSpriteSheet);
        LoadSpritePalette(&sMeowthJewelSpritePalette);
        LoadCompressedSpriteSheet(&sMeowthJewelMultipliersSpriteSheet);
        LoadCompressedSpriteSheet(&sMeowthSparkleSpriteSheet);
        LoadSpritePalette(&sMeowthJewelMultipliersSpritePalette);
        InitPinballGame();
        InitBallSprite();
        InitFlipperSprites();
        InitMeowth();
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
    switch (sPinballGame->state)
    {
    case PINBALL_STATE_INIT:
        if (!gPaletteFade.active)
        {
            sPinballGame->state = PINBALL_STATE_RUNNING;
        }
        break;
    case PINBALL_STATE_RUNNING:
        UpdateMeowth(&sPinballGame->meowth);
        HandleBallPhysics();
        UpdateCamera();
        break;
    case PINBALL_LOST_BALL_FADE_OUT:
        if (!gPaletteFade.active)
        {
            LoseBallMeowth(&sPinballGame->meowth);
            StartNewBall();
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_WHITE);
            sPinballGame->state = PINBALL_LOST_BALL_FADE_IN;
        }
        break;
    case PINBALL_LOST_BALL_FADE_IN:
        if (!gPaletteFade.active)
            sPinballGame->state = PINBALL_STATE_RUNNING;
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
    OpenEntrance();
}

static void OpenEntrance(void)
{
    u16 *tilemap;
    sPinballGame->ballIsEntering = TRUE;

    tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
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

static void CloseEntrance(void)
{
    u16 *tilemap;

    sPinballGame->ballIsEntering = FALSE;
    tilemap = GetBgTilemapBuffer(PINBALL_BG_BASE);
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

static void HandleBallPhysics(void)
{
    bool32 isFlipperColliding;
    bool32 isStaticColliding;
    bool32 isObjectColliding = FALSE;
    u8 flipperCollisionNormal;
    u8 objectCollisionNormal;
    u8 staticCollisionNormal;
    u8 collisionNormal;
    u16 flipperYForce = 0;
    int collisionAmplification = 0;
    struct Ball *ball = &sPinballGame->ball;

    if (sPinballGame->ballIsEntering && (ball->xPos >> 8) < 144)
        CloseEntrance();

    if (sPinballGame->gravityEnabled)
        ApplyGravity(ball);

    LimitVelocity(ball);
    isFlipperColliding = HandleFlippers(ball, &flipperYForce, &flipperCollisionNormal, &collisionAmplification);
    if (!isFlipperColliding)
        isObjectColliding = CheckObjectsCollision(ball, &objectCollisionNormal, &collisionAmplification);

    isStaticColliding = CheckStaticCollision(ball, sPinballGame->ballIsEntering, sPinballGame->stageTileWidth, sPinballGame->stageTileHeight, &staticCollisionNormal);
    if (isFlipperColliding)
        collisionNormal = flipperCollisionNormal;
    else if (isObjectColliding)
        collisionNormal = objectCollisionNormal;
    else
        collisionNormal = staticCollisionNormal;

    if (isFlipperColliding || isObjectColliding || isStaticColliding)
    {
        RotateVector(&ball->xVelocity, &ball->yVelocity, collisionNormal);
        ApplyCollisionForces(ball, flipperYForce, collisionAmplification);
        RotateVector(&ball->xVelocity, &ball->yVelocity, -collisionNormal);
    }

    UpdatePosition(ball);

    if ((ball->yPos >> 8) > 168)
        LoseBall();
}

static void LoseBall(void)
{
    sPinballGame->state = PINBALL_LOST_BALL_FADE_OUT;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_WHITE);
}

#define JEWEL_SPARKLE_DURATION 180

static void LoseBallMeowth(struct Meowth *meowth)
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
    if (gMain.heldKeys & (A_BUTTON | B_BUTTON))
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
}

static bool32 CheckStaticCollision(struct Ball *ball, bool32 ballIsEntering, int stageTileWidth, int stageTileHeight, u8 *outCollisionNormal)
{
    int i;
    u16 xDelta, yDelta;
    int collisionIndex;
    int maxStringStart, maxStringEnd, curStringStart, curStringLength, maxStringLength;
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
            continue;

        tileX = testX / 8;
        tileY = testY / 8;
        row = testY % 8;
        column = testX % 8;
        tileIndex = (tileY * stageTileWidth) + tileX;
        if (ballIsEntering)
            collisionAttribute = sMeowthStageEntranceBgCollisionMap[tileIndex];
        else
            collisionAttribute = sMeowthStageBgCollisionMap[tileIndex];

        collisionMaskRow = GetCollisionMaskRow(collisionAttribute, row);
        collisionTests[i] = (collisionMaskRow & (1 << column)) != 0;
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
    return TRUE;
}

static u8 GetCollisionMaskRow(int collisionAttribute, int row)
{
    struct Flipper *flipper;
    int state;
    int offset;
    const u8 *flipperStateMasks;
    u8 mask;

    if (collisionAttribute < 0xE0)
    {
        // Reverse the bits because my tooling is backwards.
        return ReverseBits(sMeowthStageBgCollisionMasks[(collisionAttribute * 0x8) + row]);
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

static void StartExitPinballGame(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    sPinballGame->state = PINBALL_STATE_EXIT;
}

static void ExitPinballGame(void)
{
    if (!gPaletteFade.active)
    {
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

#define MEOWTH_HORIZONTAL_SPEED 1
#define MEOWTH_VERTICAL_SPEED 1

static void UpdateMeowth(struct Meowth *meowth)
{
    switch (meowth->state)
    {
    case MEOWTH_STATE_WALK:
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

        break;
    case MEOWTH_STATE_HIT:
        break;
    case MEOWTH_STATE_FINISH:
        break;
    }

    UpdateJewels(meowth->jewels);
}

static bool32 CheckObjectsCollision(struct Ball *ball, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    bool32 isColliding = CheckMeowthCollision(ball, &sPinballGame->meowth, outCollisionNormal, outCollisionAmplification);
    if (!isColliding)
        isColliding = CheckMeowthJewelsCollision(ball, &sPinballGame->meowth, outCollisionNormal);

    return isColliding;
}

static bool32 CheckMeowthCollision(struct Ball *ball, struct Meowth *meowth, u8 *outCollisionNormal, int *outCollisionAmplification)
{
    int x, y;
    u8 collisionNormal;
    int ballXPos = (ball->xPos >> 8);
    int ballYPos = (ball->yPos >> 8);
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
