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
    struct Ball *ball = &sPinballGame->ball;

    ball->xPos = 0x8000;
    if (sPinballGame->gravityEnabled)
        ApplyGravity(ball);

    LimitVelocity(ball);
    UpdatePosition(ball);

    if ((ball->yPos >> 8) > 160)
    {
        ball->yPos = 0;
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
