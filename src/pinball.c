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
// callnative PlayPinball
// waitstate
// ...

#define PINBALL_BG_TEXT        0
#define PINBALL_BG_BASE        1

#define WIN_TEXT 0

#define TAG_BALL_POKEBALL 500

enum
{
    PINBALL_STATE_INIT,
    PINBALL_STATE_RUNNING,
    PINBALL_STATE_START_EXIT,
    PINBALL_STATE_EXIT,
    PINBALL_STATE_WAIT_ANIM,
};

struct Ball
{
    u8 spriteId;
    u16 xPos;
    u16 yPos;
    s16 xVelocity;
    s16 yVelocity;
    s8 spin;
    u8 rotation;
};

struct PinballGame
{
    u8 state;
    struct Ball ball;
    bool8 gravityEnabled;
    MainCallback returnMainCallback;
};

static void FadeToPinballScreen(u8 taskId);
static void InitPinballScreen(void);
static void InitBallSprite(void);
static void PinballVBlankCallback(void);
static void PinballMainCallback(void);
static void PinballMain(u8 taskId);
static void HandleBallPhysics(void);
static void ApplyGravity(struct Ball *ball);
static void LimitVelocity(struct Ball *ball);
static void UpdatePosition(struct Ball *ball);
static bool32 HandleStaticCollision(struct Ball *ball);
static void RotateVector(s16 *x, s16 *y, u8 angle);
static void ApplyCollisionForces(struct Ball *ball);
static void StartExitPinballGame(void);
static void ExitPinballGame(void);
static void UpdateBallSprite(struct Sprite *sprite);

static EWRAM_DATA struct PinballGame *sPinballGame = NULL;

static const struct BgTemplate sPinballBgTemplates[] = {
    {
       .bg = PINBALL_BG_TEXT,
       .charBaseIndex = 2,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = PINBALL_BG_BASE,
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
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
        .baseBlock = 0x14,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u32 sPinballBaseBgGfx[] = INCBIN_U32("graphics/pinball/base_bg_tiles.4bpp.lz");
static const u16 sPinballBaseBgPalette[] = INCBIN_U16("graphics/pinball/base_bg_tiles.gbapal");
static const u32 sPinballBaseBgTilemap[] = INCBIN_U32("graphics/pinball/base_bg_tilemap.bin.lz");
static const u32 sBallPokeballGfx[] = INCBIN_U32("graphics/pinball/ball_pokeball.4bpp.lz");
static const u16 sBallPokeballPalette[] = INCBIN_U16("graphics/pinball/ball_pokeball.gbapal");
static const u8 sPinballBaseBgCollisionMasks[] = INCBIN_U8("graphics/pinball/base_bg_collision_masks.1bpp");
static const u8 sPinballBaseBgCollisionMap[] = INCBIN_U8("graphics/pinball/base_bg_collision_map.bin");

static const struct CompressedSpriteSheet sBallPokeballSpriteSheet = {
    .data = sBallPokeballGfx,
    .size = 0x400,
    .tag = TAG_BALL_POKEBALL,
};

static const struct SpritePalette sPinballSpritePalettes[] = {
    {sBallPokeballPalette, TAG_BALL_POKEBALL},
    {0},
};

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
        SetBgTilemapBuffer(PINBALL_BG_BASE, AllocZeroed(BG_SCREEN_SIZE));
        DecompressAndLoadBgGfxUsingHeap(PINBALL_BG_BASE, sPinballBaseBgGfx, 0, 0, 0);
        CopyToBgTilemapBuffer(PINBALL_BG_BASE, sPinballBaseBgTilemap, 0, 0);
        ResetPaletteFade();
        LoadPalette(sPinballBaseBgPalette, 0, sizeof(sPinballBaseBgPalette));
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
        LoadSpritePalettes(sPinballSpritePalettes);
        InitBallSprite();
        gMain.state++;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(PinballVBlankCallback);
        SetMainCallback2(PinballMainCallback);
        CreateTask(PinballMain, 0);
        return;
    }
}

static void InitBallSprite(void)
{
    sPinballGame->ball.spriteId = CreateSprite(&sBallPokeballSpriteTemplate, 10, 10, 3);
    StartSpriteAnim(&gSprites[sPinballGame->ball.spriteId], 3);
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
            sPinballGame->gravityEnabled = TRUE;
            sPinballGame->state = PINBALL_STATE_RUNNING;
            sPinballGame->ball.xPos = 104 << 8;
            sPinballGame->ball.yPos = 24 << 8;
        }
        break;
    case PINBALL_STATE_RUNNING:
        HandleBallPhysics();
        break;
    case PINBALL_STATE_START_EXIT:
        StartExitPinballGame();
        break;
    case PINBALL_STATE_EXIT:
        ExitPinballGame();
        break;
    }
}

static void HandleBallPhysics(void)
{
    bool32 isColliding;
    struct Ball *ball = &sPinballGame->ball;

    if (sPinballGame->gravityEnabled)
        ApplyGravity(ball);

    LimitVelocity(ball);
    isColliding = HandleStaticCollision(ball);
    UpdatePosition(ball);

    if ((ball->yPos >> 8) > 160)
    {
        ball->xPos = 104 << 8;
        ball->yPos = 24 << 8;
        ball->yVelocity = 0;
    }
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

static bool32 HandleStaticCollision(struct Ball *ball)
{
    int i;
    u8 collisionNormal;
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
        tileIndex = (tileY * 32) + tileX;
        collisionAttribute = sPinballBaseBgCollisionMap[tileIndex];
        collisionMaskRow = sPinballBaseBgCollisionMasks[(collisionAttribute * 0x8) + row];
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
    ball->xPos += sCollisionXDeltas[collisionIndex];
    ball->yPos += sCollisionYDeltas[collisionIndex];
    collisionNormal = sCollisionNormals[collisionIndex];
    RotateVector(&ball->xVelocity, &ball->yVelocity, collisionNormal);
    ApplyCollisionForces(ball);
    RotateVector(&ball->xVelocity, &ball->yVelocity, -collisionNormal);

    return TRUE;
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

static void ApplyCollisionForces(struct Ball *ball)
{
    // Only apply the collision forces if the ball is moving
    // towards the wall it collided with, which can only be
    // true if the y velocity is traveling downward in the rotated
    // coordinate system.
    if (ball->yVelocity < 0)
        return;

    // Apply dampening to the vertical velocity component, and
    // negate it so that the ball bounces off the wall.
    ball->yVelocity = -(ball->yVelocity / 1);
    ball->xVelocity += ball->spin / 2;
    ball->spin = (ball->xVelocity * 4) >> 8;
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
    sprite->pos1.x = ball->xPos >> 8;
    sprite->pos1.y = ball->yPos >> 8;

    ball->rotation += ball->spin;
    ballAnim = (ball->rotation >> 4) % 8;
    StartSpriteAnim(sprite, ballAnim);
}
