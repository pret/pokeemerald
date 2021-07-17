#include "global.h"
#include "bg.h"
#include "clock.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "wallclock.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void CB2_WallClock(void);
static void Task_SetClock_WaitFadeIn(u8 taskId);
static void Task_SetClock_HandleInput(u8 taskId);
static void Task_SetClock_AskConfirm(u8 taskId);
static void Task_SetClock_HandleConfirmInput(u8 taskId);
static void Task_SetClock_Confirmed(u8 taskId);
static void Task_SetClock_Exit(u8 taskId);
static void Task_ViewClock_WaitFadeIn(u8 taskId);
static void Task_ViewClock_HandleInput(u8 taskId);
static void Task_ViewClock_FadeOut(u8 taskId);
static void Task_ViewClock_Exit(u8 taskId);
static u16 CalcNewMinHandAngle(u16 angle, u8 direction, u8 speed);
static bool32 AdvanceClock(u8 taskId, u8 direction);
static void UpdateClockPeriod(u8 taskId, u8 direction);
static void InitClockWithRtc(u8 taskId);
static void SpriteCB_MinuteHand(struct Sprite *sprite);
static void SpriteCB_HourHand(struct Sprite *sprite);
static void SpriteCB_PMIndicator(struct Sprite *sprite);
static void SpriteCB_AMIndicator(struct Sprite *sprite);

#define tMinuteHandAngle data[0]
#define tHourHandAngle   data[1]
#define tHours           data[2]
#define tMinutes         data[3]
#define tMoveDir         data[4]
#define tPeriod          data[5]
#define tMoveSpeed       data[6]

#define GFXTAG_WALL_CLOCK_HAND   0x1000
#define PALTAG_WALL_CLOCK_MALE   0x1000
#define PALTAG_WALL_CLOCK_FEMALE 0x1001

enum
{
    PERIOD_AM,
    PERIOD_PM,
};

enum
{
    MOVE_NONE,
    MOVE_BACKWARD,
    MOVE_FORWARD,
};

static const u32 sHand_Gfx[] = INCBIN_U32("graphics/wallclock/hand.4bpp.lz");
static const u16 sTextPrompt_Pal[] = INCBIN_U16("graphics/wallclock/text_prompt.gbapal"); // for "Cancel" or "Confirm"

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 17,
        .width = 24,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 512
    },
    {
        .bg = 2,
        .tilemapLeft = 24,
        .tilemapTop = 16,
        .width = 6,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 560
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplate_ConfirmYesNo =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 572
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 8,
        .priority = 1
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .priority = 2
    }
};

static const struct CompressedSpriteSheet sSpriteSheet_ClockHand =
{
    sHand_Gfx, 0x2000, GFXTAG_WALL_CLOCK_HAND
};

static const u8 sUnused[8] = {0};

static const struct SpritePalette sSpritePalettes_Clock[] =
{
    {
        .data = gWallClockMale_Pal,
        .tag = PALTAG_WALL_CLOCK_MALE
    },
    {
        .data = gWallClockFemale_Pal,
        .tag = PALTAG_WALL_CLOCK_FEMALE
    },
    {}
};

static const struct OamData sOam_ClockHand =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

static const union AnimCmd sAnim_MinuteHand[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HourHand[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_MinuteHand[] =
{
    sAnim_MinuteHand
};

static const union AnimCmd *const sAnims_HourHand[] =
{
    sAnim_HourHand
};

static const struct SpriteTemplate sSpriteTemplate_MinuteHand =
{
    .tileTag = GFXTAG_WALL_CLOCK_HAND,
    .paletteTag = PALTAG_WALL_CLOCK_MALE,
    .oam = &sOam_ClockHand,
    .anims = sAnims_MinuteHand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MinuteHand,
};

static const struct SpriteTemplate sSpriteTemplate_HourHand =
{
    .tileTag = GFXTAG_WALL_CLOCK_HAND,
    .paletteTag = PALTAG_WALL_CLOCK_MALE,
    .oam = &sOam_ClockHand,
    .anims = sAnims_HourHand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_HourHand,
};

static const struct OamData sOam_PeriodIndicator =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 3,
};

static const union AnimCmd sAnim_PM[] =
{
    ANIMCMD_FRAME(132, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_AM[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_PM[] =
{
    sAnim_PM
};

static const union AnimCmd *const sAnims_AM[] =
{
    sAnim_AM
};

static const struct SpriteTemplate sSpriteTemplate_PM =
{
    .tileTag = GFXTAG_WALL_CLOCK_HAND,
    .paletteTag = PALTAG_WALL_CLOCK_MALE,
    .oam = &sOam_PeriodIndicator,
    .anims = sAnims_PM,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PMIndicator
};

static const struct SpriteTemplate sSpriteTemplate_AM =
{
    .tileTag = GFXTAG_WALL_CLOCK_HAND,
    .paletteTag = PALTAG_WALL_CLOCK_MALE,
    .oam = &sOam_PeriodIndicator,
    .anims = sAnims_AM,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_AMIndicator
};

static const s8 sClockHandCoords[][2] =
{
    { 0x00, -0x18},
    { 0x01, -0x19},
    { 0x01, -0x19},
    { 0x02, -0x19},
    { 0x02, -0x19},
    { 0x02, -0x19},
    { 0x03, -0x18},
    { 0x03, -0x19},
    { 0x04, -0x19},
    { 0x04, -0x19},
    { 0x04, -0x19},
    { 0x05, -0x19},
    { 0x05, -0x19},
    { 0x06, -0x18},
    { 0x06, -0x18},
    { 0x06, -0x18},
    { 0x07, -0x18},
    { 0x07, -0x18},
    { 0x07, -0x18},
    { 0x08, -0x18},
    { 0x08, -0x18},
    { 0x09, -0x18},
    { 0x09, -0x18},
    { 0x0a, -0x17},
    { 0x0a, -0x17},
    { 0x0b, -0x16},
    { 0x0b, -0x16},
    { 0x0b, -0x16},
    { 0x0c, -0x16},
    { 0x0c, -0x15},
    { 0x0d, -0x15},
    { 0x0d, -0x15},
    { 0x0d, -0x15},
    { 0x0e, -0x15},
    { 0x0e, -0x15},
    { 0x0e, -0x14},
    { 0x0e, -0x14},
    { 0x0f, -0x14},
    { 0x0f, -0x13},
    { 0x10, -0x13},
    { 0x10, -0x13},
    { 0x10, -0x13},
    { 0x10, -0x12},
    { 0x10, -0x12},
    { 0x11, -0x12},
    { 0x11, -0x11},
    { 0x11, -0x11},
    { 0x12, -0x11},
    { 0x12, -0x11},
    { 0x12, -0x10},
    { 0x12, -0x10},
    { 0x13, -0x10},
    { 0x13, -0x0f},
    { 0x13, -0x0f},
    { 0x14, -0x0f},
    { 0x14, -0x0e},
    { 0x14, -0x0e},
    { 0x14, -0x0d},
    { 0x14, -0x0d},
    { 0x15, -0x0d},
    { 0x15, -0x0d},
    { 0x15, -0x0c},
    { 0x16, -0x0c},
    { 0x16, -0x0c},
    { 0x16, -0x0b},
    { 0x16, -0x0b},
    { 0x16, -0x0a},
    { 0x17, -0x0a},
    { 0x17, -0x09},
    { 0x17, -0x09},
    { 0x17, -0x09},
    { 0x17, -0x09},
    { 0x17, -0x08},
    { 0x17, -0x08},
    { 0x17, -0x07},
    { 0x17, -0x07},
    { 0x17, -0x06},
    { 0x18, -0x06},
    { 0x18, -0x06},
    { 0x19, -0x05},
    { 0x19, -0x05},
    { 0x18, -0x04},
    { 0x19, -0x04},
    { 0x18, -0x03},
    { 0x19, -0x03},
    { 0x19, -0x03},
    { 0x19, -0x02},
    { 0x19, -0x02},
    { 0x18, -0x01},
    { 0x19, -0x01},
    { 0x18,  0x00},
    { 0x18,  0x00},
    { 0x18,  0x00},
    { 0x18,  0x01},
    { 0x18,  0x01},
    { 0x19,  0x02},
    { 0x18,  0x02},
    { 0x19,  0x02},
    { 0x18,  0x03},
    { 0x18,  0x03},
    { 0x19,  0x04},
    { 0x18,  0x04},
    { 0x18,  0x05},
    { 0x18,  0x05},
    { 0x18,  0x05},
    { 0x18,  0x06},
    { 0x17,  0x06},
    { 0x17,  0x06},
    { 0x17,  0x07},
    { 0x17,  0x08},
    { 0x17,  0x08},
    { 0x17,  0x08},
    { 0x17,  0x09},
    { 0x17,  0x09},
    { 0x17,  0x0a},
    { 0x16,  0x0a},
    { 0x16,  0x0a},
    { 0x16,  0x0b},
    { 0x16,  0x0b},
    { 0x16,  0x0b},
    { 0x16,  0x0c},
    { 0x15,  0x0c},
    { 0x15,  0x0c},
    { 0x15,  0x0d},
    { 0x14,  0x0d},
    { 0x14,  0x0d},
    { 0x13,  0x0d},
    { 0x13,  0x0d},
    { 0x13,  0x0e},
    { 0x13,  0x0e},
    { 0x13,  0x0f},
    { 0x13,  0x0f},
    { 0x12,  0x0f},
    { 0x12,  0x10},
    { 0x11,  0x10},
    { 0x11,  0x10},
    { 0x11,  0x11},
    { 0x11,  0x11},
    { 0x10,  0x11},
    { 0x10,  0x12},
    { 0x10,  0x12},
    { 0x0f,  0x12},
    { 0x0e,  0x12},
    { 0x0f,  0x13},
    { 0x0e,  0x13},
    { 0x0e,  0x13},
    { 0x0d,  0x13},
    { 0x0d,  0x14},
    { 0x0d,  0x14},
    { 0x0d,  0x14},
    { 0x0c,  0x14},
    { 0x0c,  0x14},
    { 0x0c,  0x15},
    { 0x0b,  0x15},
    { 0x0b,  0x15},
    { 0x0b,  0x15},
    { 0x0a,  0x15},
    { 0x0a,  0x16},
    { 0x0a,  0x16},
    { 0x09,  0x16},
    { 0x09,  0x16},
    { 0x08,  0x16},
    { 0x07,  0x16},
    { 0x07,  0x17},
    { 0x07,  0x17},
    { 0x06,  0x17},
    { 0x06,  0x17},
    { 0x05,  0x17},
    { 0x05,  0x17},
    { 0x05,  0x18},
    { 0x04,  0x18},
    { 0x04,  0x18},
    { 0x04,  0x18},
    { 0x03,  0x18},
    { 0x02,  0x18},
    { 0x02,  0x18},
    { 0x01,  0x18},
    { 0x01,  0x18},
    { 0x00,  0x18},
    { 0x00,  0x18},
    {-0x01,  0x17},
    { 0x00,  0x18},
    { 0x00,  0x18},
    {-0x01,  0x18},
    {-0x01,  0x18},
    {-0x02,  0x18},
    {-0x02,  0x18},
    {-0x03,  0x18},
    {-0x03,  0x18},
    {-0x04,  0x18},
    {-0x04,  0x18},
    {-0x05,  0x18},
    {-0x05,  0x17},
    {-0x05,  0x17},
    {-0x06,  0x17},
    {-0x06,  0x17},
    {-0x07,  0x17},
    {-0x07,  0x17},
    {-0x07,  0x17},
    {-0x08,  0x17},
    {-0x08,  0x16},
    {-0x09,  0x16},
    {-0x09,  0x16},
    {-0x0a,  0x16},
    {-0x0a,  0x16},
    {-0x0a,  0x15},
    {-0x0b,  0x15},
    {-0x0b,  0x15},
    {-0x0b,  0x15},
    {-0x0b,  0x14},
    {-0x0c,  0x14},
    {-0x0c,  0x14},
    {-0x0d,  0x14},
    {-0x0d,  0x14},
    {-0x0d,  0x13},
    {-0x0e,  0x13},
    {-0x0e,  0x13},
    {-0x0e,  0x13},
    {-0x0e,  0x12},
    {-0x0f,  0x12},
    {-0x0f,  0x12},
    {-0x0f,  0x11},
    {-0x10,  0x11},
    {-0x10,  0x11},
    {-0x11,  0x11},
    {-0x11,  0x10},
    {-0x11,  0x10},
    {-0x12,  0x10},
    {-0x11,  0x0f},
    {-0x12,  0x0f},
    {-0x12,  0x0f},
    {-0x13,  0x0f},
    {-0x13,  0x0e},
    {-0x13,  0x0e},
    {-0x13,  0x0d},
    {-0x13,  0x0d},
    {-0x14,  0x0d},
    {-0x14,  0x0c},
    {-0x14,  0x0c},
    {-0x15,  0x0c},
    {-0x15,  0x0c},
    {-0x15,  0x0b},
    {-0x15,  0x0b},
    {-0x15,  0x0a},
    {-0x15,  0x0a},
    {-0x15,  0x09},
    {-0x16,  0x09},
    {-0x16,  0x09},
    {-0x16,  0x08},
    {-0x16,  0x08},
    {-0x16,  0x07},
    {-0x17,  0x07},
    {-0x17,  0x07},
    {-0x17,  0x06},
    {-0x17,  0x06},
    {-0x17,  0x05},
    {-0x18,  0x05},
    {-0x17,  0x04},
    {-0x17,  0x04},
    {-0x18,  0x04},
    {-0x18,  0x04},
    {-0x18,  0x03},
    {-0x18,  0x03},
    {-0x18,  0x02},
    {-0x18,  0x02},
    {-0x18,  0x01},
    {-0x18,  0x01},
    {-0x18,  0x01},
    {-0x18,  0x00},
    {-0x19,  0x00},
    {-0x18, -0x01},
    {-0x19, -0x01},
    {-0x18, -0x01},
    {-0x18, -0x02},
    {-0x18, -0x02},
    {-0x18, -0x03},
    {-0x18, -0x03},
    {-0x18, -0x04},
    {-0x18, -0x04},
    {-0x18, -0x04},
    {-0x18, -0x05},
    {-0x18, -0x05},
    {-0x18, -0x06},
    {-0x18, -0x06},
    {-0x17, -0x06},
    {-0x17, -0x07},
    {-0x17, -0x07},
    {-0x17, -0x08},
    {-0x17, -0x08},
    {-0x17, -0x09},
    {-0x17, -0x09},
    {-0x16, -0x09},
    {-0x16, -0x09},
    {-0x16, -0x0a},
    {-0x16, -0x0a},
    {-0x15, -0x0a},
    {-0x15, -0x0b},
    {-0x16, -0x0b},
    {-0x16, -0x0c},
    {-0x15, -0x0c},
    {-0x15, -0x0d},
    {-0x15, -0x0d},
    {-0x14, -0x0d},
    {-0x15, -0x0e},
    {-0x14, -0x0e},
    {-0x14, -0x0e},
    {-0x13, -0x0e},
    {-0x13, -0x0f},
    {-0x13, -0x0f},
    {-0x12, -0x10},
    {-0x12, -0x10},
    {-0x12, -0x10},
    {-0x12, -0x11},
    {-0x12, -0x11},
    {-0x11, -0x11},
    {-0x11, -0x12},
    {-0x11, -0x12},
    {-0x10, -0x12},
    {-0x10, -0x12},
    {-0x10, -0x13},
    {-0x10, -0x13},
    {-0x0f, -0x13},
    {-0x0f, -0x13},
    {-0x0f, -0x14},
    {-0x0e, -0x14},
    {-0x0e, -0x14},
    {-0x0e, -0x15},
    {-0x0d, -0x15},
    {-0x0d, -0x15},
    {-0x0d, -0x15},
    {-0x0c, -0x15},
    {-0x0c, -0x16},
    {-0x0b, -0x16},
    {-0x0b, -0x16},
    {-0x0b, -0x16},
    {-0x0a, -0x16},
    {-0x0a, -0x16},
    {-0x09, -0x16},
    {-0x09, -0x17},
    {-0x09, -0x17},
    {-0x08, -0x17},
    {-0x08, -0x17},
    {-0x07, -0x17},
    {-0x07, -0x17},
    {-0x07, -0x18},
    {-0x06, -0x18},
    {-0x06, -0x18},
    {-0x05, -0x18},
    {-0x05, -0x18},
    {-0x04, -0x18},
    {-0x04, -0x18},
    {-0x04, -0x18},
    {-0x04, -0x19},
    {-0x03, -0x19},
    {-0x02, -0x19},
    {-0x02, -0x18},
    {-0x02, -0x18},
    {-0x01, -0x19},
    {-0x01, -0x19},
    { 0x00, -0x19}
};

static void VBlankCB_WallClock(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void LoadWallClockGraphics(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    LZ77UnCompVram(gWallClock_Gfx, (void *)VRAM);

    if (gSpecialVar_0x8004 == MALE)
        LoadPalette(gWallClockMale_Pal, 0, 32);
    else
        LoadPalette(gWallClockFemale_Pal, 0, 32);

    LoadPalette(GetOverworldTextboxPalettePtr(), 0xe0, 32);
    LoadPalette(sTextPrompt_Pal, 0xc0, 8);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadCompressedSpriteSheet(&sSpriteSheet_ClockHand);
    LoadSpritePalettes(sSpritePalettes_Clock);
}

static void WallClockInit(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_WallClock);
    SetMainCallback2(CB2_WallClock);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(2);
    ShowBg(3);
}

void CB2_StartWallClock(void)
{
    u8 taskId;
    u8 spriteId;

    LoadWallClockGraphics();
    LZ77UnCompVram(gWallClockStart_Tilemap, (u16 *)BG_SCREEN_ADDR(7));

    taskId = CreateTask(Task_SetClock_WaitFadeIn, 0);
    gTasks[taskId].tHours = 10;
    gTasks[taskId].tMinutes = 0;
    gTasks[taskId].tMoveDir = 0;
    gTasks[taskId].tPeriod = 0;
    gTasks[taskId].tMoveSpeed = 0;
    gTasks[taskId].tMinuteHandAngle = 0;
    gTasks[taskId].tHourHandAngle = 300;

    spriteId = CreateSprite(&sSpriteTemplate_MinuteHand, 120, 80, 1);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 0;

    spriteId = CreateSprite(&sSpriteTemplate_HourHand, 120, 80, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 1;

    spriteId = CreateSprite(&sSpriteTemplate_PM, 120, 80, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 45;

    spriteId = CreateSprite(&sSpriteTemplate_AM, 120, 80, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 90;

    WallClockInit();

    AddTextPrinterParameterized(1, 1, gText_Confirm3, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    ScheduleBgCopyTilemapToVram(2);
}

void CB2_ViewWallClock(void)
{
    u8 taskId;
    u8 spriteId;
    u8 angle1;
    u8 angle2;

    LoadWallClockGraphics();
    LZ77UnCompVram(gWallClockView_Tilemap, (u16 *)BG_SCREEN_ADDR(7));

    taskId = CreateTask(Task_ViewClock_WaitFadeIn, 0);
    InitClockWithRtc(taskId);
    if (gTasks[taskId].tPeriod == PERIOD_AM)
    {
        angle1 = 45;
        angle2 = 90;
    }
    else
    {
        angle1 = 90;
        angle2 = 135;
    }

    spriteId = CreateSprite(&sSpriteTemplate_MinuteHand, 120, 80, 1);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 0;

    spriteId = CreateSprite(&sSpriteTemplate_HourHand, 120, 80, 0);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 1;

    spriteId = CreateSprite(&sSpriteTemplate_PM, 120, 80, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = angle1;

    spriteId = CreateSprite(&sSpriteTemplate_AM, 120, 80, 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = angle2;

    WallClockInit();

    AddTextPrinterParameterized(1, 1, gText_Cancel4, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    ScheduleBgCopyTilemapToVram(2);
}

static void CB2_WallClock(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_SetClock_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SetClock_HandleInput;
    }
}

static void Task_SetClock_HandleInput(u8 taskId)
{
    if (gTasks[taskId].tMinuteHandAngle % 6)
    {
        gTasks[taskId].tMinuteHandAngle = CalcNewMinHandAngle(gTasks[taskId].tMinuteHandAngle, gTasks[taskId].tMoveDir, gTasks[taskId].tMoveSpeed);
    }
    else
    {
        gTasks[taskId].tMinuteHandAngle = gTasks[taskId].tMinutes * 6;
        gTasks[taskId].tHourHandAngle = (gTasks[taskId].tHours % 12) * 30 + (gTasks[taskId].tMinutes / 10) * 5;
        if (JOY_NEW(A_BUTTON))
        {
            gTasks[taskId].func = Task_SetClock_AskConfirm;
        }
        else
        {
            gTasks[taskId].tMoveDir = MOVE_NONE;

            if (JOY_HELD(DPAD_LEFT))
                gTasks[taskId].tMoveDir = MOVE_BACKWARD;

            if (JOY_HELD(DPAD_RIGHT))
                gTasks[taskId].tMoveDir = MOVE_FORWARD;

            if (gTasks[taskId].tMoveDir != MOVE_NONE)
            {
                if (gTasks[taskId].tMoveSpeed < 0xFF)
                    gTasks[taskId].tMoveSpeed++;

                gTasks[taskId].tMinuteHandAngle = CalcNewMinHandAngle(gTasks[taskId].tMinuteHandAngle, gTasks[taskId].tMoveDir, gTasks[taskId].tMoveSpeed);
                AdvanceClock(taskId, gTasks[taskId].tMoveDir);
            }
            else
            {
                gTasks[taskId].tMoveSpeed = 0;
            }
        }
    }
}

static void Task_SetClock_AskConfirm(u8 taskId)
{
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x250, 0x0d);
    AddTextPrinterParameterized(0, 1, gText_IsThisTheCorrectTime, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    CreateYesNoMenu(&sWindowTemplate_ConfirmYesNo, 0x250, 0x0d, 1);
    gTasks[taskId].func = Task_SetClock_HandleConfirmInput;
}

static void Task_SetClock_HandleConfirmInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_SetClock_Confirmed;
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(0, FALSE);
        ClearWindowTilemap(0);
        gTasks[taskId].func = Task_SetClock_HandleInput;
        break;
    }
}

static void Task_SetClock_Confirmed(u8 taskId)
{
    RtcInitLocalTimeOffset(gTasks[taskId].tHours, gTasks[taskId].tMinutes);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_SetClock_Exit;
}

static void Task_SetClock_Exit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void Task_ViewClock_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ViewClock_HandleInput;
}

static void Task_ViewClock_HandleInput(u8 taskId)
{
    InitClockWithRtc(taskId);
    if (JOY_NEW(A_BUTTON | B_BUTTON))
        gTasks[taskId].func = Task_ViewClock_FadeOut;
}

static void Task_ViewClock_FadeOut(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ViewClock_Exit;
}

static void Task_ViewClock_Exit(u8 taskId)
{
    if (!gPaletteFade.active)
        SetMainCallback2(gMain.savedCallback);
}

static u8 CalcMinHandDelta(u16 speed)
{
    if (speed > 60)
        return 6;
    if (speed > 30)
        return 3;
    if (speed > 10)
        return 2;

    return 1;
}

static u16 CalcNewMinHandAngle(u16 angle, u8 direction, u8 speed)
{
    u8 delta = CalcMinHandDelta(speed);
    switch (direction)
    {
    case MOVE_BACKWARD:
        if (angle)
            angle -= delta;
        else
            angle = 360 - delta;
        break;
    case MOVE_FORWARD:
        if (angle < 360 - delta)
            angle += delta;
        else
            angle = 0;
        break;
    }
    return angle;
}

static bool32 AdvanceClock(u8 taskId, u8 direction)
{
    switch (direction)
    {
    case MOVE_BACKWARD:
        if (gTasks[taskId].tMinutes > 0)
        {
            gTasks[taskId].tMinutes--;
        }
        else
        {
            gTasks[taskId].tMinutes = 59;

            if (gTasks[taskId].tHours > 0)
                gTasks[taskId].tHours--;
            else
                gTasks[taskId].tHours = 23;

            UpdateClockPeriod(taskId, direction);
        }
        break;
    case MOVE_FORWARD:
        if (gTasks[taskId].tMinutes < 59)
        {
            gTasks[taskId].tMinutes++;
        }
        else
        {
            gTasks[taskId].tMinutes = 0;

            if (gTasks[taskId].tHours < 23)
                gTasks[taskId].tHours++;
            else
                gTasks[taskId].tHours = 0;

            UpdateClockPeriod(taskId, direction);
        }
        break;
    }
    return FALSE;
}

static void UpdateClockPeriod(u8 taskId, u8 direction)
{
    u8 hours = gTasks[taskId].tHours;
    switch (direction)
    {
    case MOVE_BACKWARD:
        switch (hours)
        {
        case 11:
            gTasks[taskId].tPeriod = PERIOD_AM;
            break;
        case 23:
            gTasks[taskId].tPeriod = PERIOD_PM;
            break;
        }
        break;
    case MOVE_FORWARD:
        switch (hours)
        {
        case 0:
            gTasks[taskId].tPeriod = PERIOD_AM;
            break;
        case 12:
            gTasks[taskId].tPeriod = PERIOD_PM;
            break;
        }
        break;
    }
}

static void InitClockWithRtc(u8 taskId)
{
    RtcCalcLocalTime();
    gTasks[taskId].tHours = gLocalTime.hours;
    gTasks[taskId].tMinutes = gLocalTime.minutes;
    gTasks[taskId].tMinuteHandAngle = gTasks[taskId].tMinutes * 6;
    gTasks[taskId].tHourHandAngle = (gTasks[taskId].tHours % 12) * 30 + (gTasks[taskId].tMinutes / 10) * 5;

    if (gLocalTime.hours < 12)
        gTasks[taskId].tPeriod = PERIOD_AM;
    else
        gTasks[taskId].tPeriod = PERIOD_PM;
}

static void SpriteCB_MinuteHand(struct Sprite *sprite)
{
    u16 angle = gTasks[sprite->data[0]].tMinuteHandAngle;
    s16 sin = Sin2(angle) / 16;
    s16 cos = Cos2(angle) / 16;
    u16 x, y;

    SetOamMatrix(0, cos, sin, -sin, cos);
    x = sClockHandCoords[angle][0];
    y = sClockHandCoords[angle][1];

    if (x > 128)
        x |= 0xff00;
    if (y > 128)
        y |= 0xff00;

    sprite->x2 = x;
    sprite->y2 = y;
}

static void SpriteCB_HourHand(struct Sprite *sprite)
{
    u16 angle = gTasks[sprite->data[0]].tHourHandAngle;
    s16 sin = Sin2(angle) / 16;
    s16 cos = Cos2(angle) / 16;
    u16 x, y;

    SetOamMatrix(1, cos, sin, -sin, cos);
    x = sClockHandCoords[angle][0];
    y = sClockHandCoords[angle][1];

    if (x > 128)
        x |= 0xff00;
    if (y > 128)
        y |= 0xff00;

    sprite->x2 = x;
    sprite->y2 = y;
}

static void SpriteCB_PMIndicator(struct Sprite *sprite)
{
    if (gTasks[sprite->data[0]].tPeriod != PERIOD_AM)
    {
        if (sprite->data[1] >= 60 && sprite->data[1] < 90)
        {
            sprite->data[1] += 5;
        }
        if (sprite->data[1] < 60)
        {
            sprite->data[1]++;
        }
    }
    else
    {
        if (sprite->data[1] >= 46 && sprite->data[1] < 76)
        {
            sprite->data[1] -= 5;
        }
        if (sprite->data[1] > 75)
        {
            sprite->data[1]--;
        }
    }
    sprite->x2 = Cos2(sprite->data[1]) * 30 / 0x1000;
    sprite->y2 = Sin2(sprite->data[1]) * 30 / 0x1000;
}

static void SpriteCB_AMIndicator(struct Sprite *sprite)
{
    if (gTasks[sprite->data[0]].tPeriod != PERIOD_AM)
    {
        if (sprite->data[1] >= 105 && sprite->data[1] < 135)
        {
            sprite->data[1] += 5;
        }
        if (sprite->data[1] < 105)
        {
            sprite->data[1]++;
        }
    }
    else
    {
        if (sprite->data[1] >= 91 && sprite->data[1] < 121)
        {
            sprite->data[1] -= 5;
        }
        if (sprite->data[1] > 120)
        {
            sprite->data[1]--;
        }
    }
    sprite->x2 = Cos2(sprite->data[1]) * 30 / 0x1000;
    sprite->y2 = Sin2(sprite->data[1]) * 30 / 0x1000;
}
