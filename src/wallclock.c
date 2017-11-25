#include "global.h"
#include "main.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "rtc.h"
#include "clock.h"
#include "wallclock.h"
#include "event_data.h"
#include "graphics.h"
#include "text.h"
#include "window.h"
#include "text_window.h"
#include "menu.h"
#include "unknown_task.h"
#include "task.h"
#include "strings.h"
#include "sound.h"
#include "songs.h"
#include "trig.h"
#include "decompress.h"

// static types

#define WALL_CLOCK_TASK_MINUTE_HAND_ANGLE  0
#define WALL_CLOCK_TASK_HOUR_HAND_ANGLE    1
#define WALL_CLOCK_TASK_HOUR               2
#define WALL_CLOCK_TASK_MINUTE             3
#define WALL_CLOCK_TASK_SET_COMMAND        4
#define WALL_CLOCK_TASK_12HRCLOCK_AM_PM    5
#define WALL_CLOCK_TASK_SET_SPEED          6

// static declarations

static void sub_8134C9C(void);
static void sub_8134CB8(u8 taskId);
static void sub_8134CE8(u8 taskId);
static void sub_8134DC4(u8 taskId);
static void c3_80BF560(u8 taskId);
static void sub_8134EA4(u8 taskId);
static void c2_080111BC(u8 taskId);
static void sub_8134F10(u8 taskId);
static void sub_8134F40(u8 taskId);
static void sub_8134F78(u8 taskId);
static void sub_8134FB0(u8 taskId);
static u16 GetClockHandAngle(u16 a0, u8 command, u8 a2);
static bool32 MoveClockHand(u8 taskId, u8 command);
static void _12HourClockFixAMPM(u8 taskId, u8 command);
static void sub_8135130(u8 taskId);
static void sub_81351AC(struct Sprite *sprite);
static void sub_8135244(struct Sprite *sprite);
static void sub_81352DC(struct Sprite *sprite);
void sub_8135380(struct Sprite *sprite);

// rodata

const u8 gUnknown_085B1F58[] = INCBIN_U8("graphics/wallclock/graphics_85b1f58.4bpp.lz");
const u16 gUnknown_085B21D4[] = INCBIN_U16("graphics/wallclock/palette_85b21d4.gbapal");
const struct WindowTemplate gUnknown_085B21DC[] = {
    { 0x00, 0x03, 0x11, 0x18, 0x02, 0x0e, 0x200 },
    { 0x02, 0x18, 0x10, 0x06, 0x02, 0x0c, 0x230 },
    DUMMY_WIN_TEMPLATE
};
const struct WindowTemplate gUnknown_085B21F4 = {
    0x00, 0x18, 0x09, 0x05, 0x04, 0x0e, 0x23c
};
const struct BgTemplate gUnknown_085B21FC[] = {
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
const struct CompressedSpriteSheet gUnknown_085B2208 = {
    gUnknown_085B1F58, 0x2000, 0x1000
};
const u32 filler_85B2210[2] = {};
const struct SpritePalette gUnknown_085B2218[] = {
    { gUnknown_08DCC01C, 0x1000 },
    { gUnknown_08DCC03C, 0x1001 },
    {}
};
static const struct OamData Unknown_085B2230 = {
    .y = 0xa0,
    .size = 3,
    .priority = 1
};
static const union AnimCmd Unknown_085B2238[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};
static const union AnimCmd Unknown_085B2240[] = {
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};
static const union AnimCmd *const gUnknown_085B2248[] = {
    Unknown_085B2238
};
static const union AnimCmd *const gUnknown_085B224C[] = {
    Unknown_085B2240
};
const struct SpriteTemplate gUnknown_085B2250 = {
    0x1000,
    0x1000,
    &Unknown_085B2230,
    gUnknown_085B2248,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_81351AC
};
const struct SpriteTemplate gUnknown_085B2268 = {
    0x1000,
    0x1000,
    &Unknown_085B2230,
    gUnknown_085B224C,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_8135244
};
static const struct OamData Unknown_085B2280 = {
    .y = 0xa0,
    .size = 1,
    .priority = 3
};
static const union AnimCmd Unknown_085B2288[] = {
    ANIMCMD_FRAME(0x84, 30),
    ANIMCMD_END
};
static const union AnimCmd Unknown_085B2290[] = {
    ANIMCMD_FRAME(0x80, 30),
    ANIMCMD_END
};
static const union AnimCmd *const gUnknown_085B2298[] = {
    Unknown_085B2288
};
static const union AnimCmd *const gUnknown_085B229C[] = {
    Unknown_085B2290
};
const struct SpriteTemplate gUnknown_085B22A0 = {
    0x1000,
    0x1000,
    &Unknown_085B2280,
    gUnknown_085B2298,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_81352DC
};
const struct SpriteTemplate gUnknown_085B22B8 = {
    0x1000,
    0x1000,
    &Unknown_085B2280,
    gUnknown_085B229C,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_8135380
};
const s8 gUnknown_085B22D0[][2] = {
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

// text

static void sub_81347B4(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void LoadWallClockGraphics(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG3CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG2CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG1CNT, 0x0000);
    SetGpuReg(REG_OFFSET_BG0CNT, 0x0000);
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
    LZ77UnCompVram(gUnknown_08DCC05C, (void *)VRAM);
    if (gSpecialVar_0x8004 == 0)
    {
        LoadPalette(gUnknown_08DCC01C, 0x00, 0x20);
    }
    else
    {
        LoadPalette(gUnknown_08DCC03C, 0x00, 0x20);
    }
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xe0, 0x20);
    LoadPalette(gUnknown_085B21D4, 0xc0, 0x08);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B21FC, 3);
    InitWindows(gUnknown_085B21DC);
    DeactivateAllTextPrinters();
    sub_809882C(0, 0x250, 0xd0);
    clear_scheduled_bg_copies_to_vram();
    remove_some_task();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadCompressedObjectPic(&gUnknown_085B2208);
    LoadSpritePalettes(gUnknown_085B2218);
}

void sub_813498C(void)
{
    BeginNormalPaletteFade(-1, 0, 16, 0, 0);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(sub_81347B4);
    SetMainCallback2(sub_8134C9C);
    SetGpuReg(REG_OFFSET_BLDCNT, 0x0000);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x0000);
    SetGpuReg(REG_OFFSET_BLDY, 0x0000);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(2);
    ShowBg(3);
}

void Cb2_StartWallClock(void)
{
    u8 taskId;
    u8 spriteId;

    LoadWallClockGraphics();
    LZ77UnCompVram(gUnknown_08DCC648, (u16 *)BG_SCREEN_ADDR(7));
    taskId = CreateTask(sub_8134CB8, 0);
    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] = 10;
    gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] = 0;
    gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND] = 0;
    gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = 0;
    gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED] = 0;
    gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] = 0;
    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR_HAND_ANGLE] = 0x12c;
    spriteId = CreateSprite(&gUnknown_085B2250, 0x78, 0x50, 1);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 0;
    spriteId = CreateSprite(&gUnknown_085B2268, 0x78, 0x50, 0);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 1;
    spriteId = CreateSprite(&gUnknown_085B22A0, 0x78, 0x50, 2);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].data1 = 45;
    spriteId = CreateSprite(&gUnknown_085B22B8, 0x78, 0x50, 2);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].data1 = 90;
    sub_813498C();
    PrintTextOnWindow(1, 1, gText_Confirm3, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void Cb2_ViewWallClock(void)
{
    u8 taskId;
    u8 spriteId;
    u8 r10;
    u8 spc;

    LoadWallClockGraphics();
    LZ77UnCompVram(gUnknown_08DCC908, (u16 *)BG_SCREEN_ADDR(7));
    taskId = CreateTask(sub_8134F10, 0);
    sub_8135130(taskId);
    if (gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] == 0)
    {
        r10 = 45;
        spc = 90;
    }
    else
    {
        r10 = 90;
        spc = 135;
    }
    spriteId = CreateSprite(&gUnknown_085B2250, 0x78, 0x50, 1);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 0;
    spriteId = CreateSprite(&gUnknown_085B2268, 0x78, 0x50, 0);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 1;
    spriteId = CreateSprite(&gUnknown_085B22A0, 0x78, 0x50, 2);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].data1 = r10;
    spriteId = CreateSprite(&gUnknown_085B22B8, 0x78, 0x50, 2);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].data1 = spc;
    sub_813498C();
    PrintTextOnWindow(1, 1, gText_Cancel4, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_8134C9C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void sub_8134CB8(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = sub_8134CE8;
    }
}

static void sub_8134CE8(u8 taskId)
{
    if (gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] % 6)
    {
        gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] = GetClockHandAngle(gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE], gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND], gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED]);
    }
    else
    {
        gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] = gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] * 6;
        gTasks[taskId].data[WALL_CLOCK_TASK_HOUR_HAND_ANGLE] = (gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] % 12) * 30 + (gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] / 10) * 5;
        if (gMain.newKeys & A_BUTTON)
        {
            gTasks[taskId].func = sub_8134DC4;
        }
        else
        {
            gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND] = 0;
            if (gMain.heldKeys & DPAD_LEFT)
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND] = 1;
            }
            if (gMain.heldKeys & DPAD_RIGHT)
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND] = 2;
            }
            if (gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND] != 0)
            {
                if (gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED] <= 0xFE)
                {
                    gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED]++;
                }
                gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] = GetClockHandAngle(gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE], gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND], gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED]);
                MoveClockHand(taskId, gTasks[taskId].data[WALL_CLOCK_TASK_SET_COMMAND]);
            }
            else
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_SET_SPEED] = 0;
            }
        }
    }
}

static void sub_8134DC4(u8 taskId)
{
    SetWindowBorderStyle(0, FALSE, 0x250, 0x0d);
    PrintTextOnWindow(0, 1, gText_IsThisTheCorrectTime, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    schedule_bg_copy_tilemap_to_vram(0);
    CreateYesNoMenu(&gUnknown_085B21F4, 0x250, 0x0d, 1);
    gTasks[taskId].func = c3_80BF560;
}

static void c3_80BF560(u8 taskId)
{
    switch (sub_8198C58())
    {
        case 0:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = sub_8134EA4;
            break;
        case 1:
        case -1:
            PlaySE(SE_SELECT);
            sub_8198070(0, FALSE);
            ClearWindowTilemap(0);
            gTasks[taskId].func = sub_8134CE8;
            break;
    }
}

static void sub_8134EA4(u8 taskId)
{
    RtcInitLocalTimeOffset(gTasks[taskId].data[WALL_CLOCK_TASK_HOUR], gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE]);
    BeginNormalPaletteFade(-1, 0, 0, 16, 0);
    gTasks[taskId].func = c2_080111BC;
}

static void c2_080111BC(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void sub_8134F10(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = sub_8134F40;
    }
}

static void sub_8134F40(u8 taskId)
{
    sub_8135130(taskId);
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        gTasks[taskId].func = sub_8134F78;
    }
}

static void sub_8134F78(u8 taskId)
{
    BeginNormalPaletteFade(-1, 0, 0, 16, 0);
    gTasks[taskId].func = sub_8134FB0;
}

static void sub_8134FB0(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gMain.savedCallback);
    }
}

static u8 GetClockHandAngleChange(u16 a0)
{
    if (a0 > 60)
    {
        return 6;
    }
    if (a0 > 30)
    {
        return 3;
    }
    if (a0 > 10)
    {
        return 2;
    }
    return 1;
}

static u16 GetClockHandAngle(u16 a0, u8 command, u8 a2)
{
    u8 r1 = GetClockHandAngleChange(a2);
    switch (command)
    {
        case 1:
            if (a0) a0 -= r1;
            else a0 = 360 - r1;
            break;
        case 2:
            if (a0 < 360 - r1) a0 += r1;
            else a0 = 0;
            break;
    }
    return a0;
}

static bool32 MoveClockHand(u8 taskId, u8 command)
{
    switch (command)
    {
        case 1:
            if (gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] > 0)
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE]--;
            }
            else
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] = 59;
                if (gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] > 0)
                {
                    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR]--;
                }
                else
                {
                    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] = 23;
                }
                _12HourClockFixAMPM(taskId, command);
            }
            break;
        case 2:
            if (gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] < 59)
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE]++;
            }
            else
            {
                gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] = 0;
                if (gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] < 23)
                {
                    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR]++;
                }
                else
                {
                    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] = 0;
                }
                _12HourClockFixAMPM(taskId, command);
            }
            break;
    }
    return FALSE;
}

static void _12HourClockFixAMPM(u8 taskId, u8 command)
{
    u8 hours = gTasks[taskId].data[WALL_CLOCK_TASK_HOUR];
    switch (command)
    {
        case 1:
            switch (hours)
            {
                case 11:
                    gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = FALSE;
                    break;
                case 23:
                    gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = TRUE;
                    break;
            }
            break;
        case 2:
            switch (hours)
            {
                case 0:
                    gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = FALSE;
                    break;
                case 12:
                    gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = TRUE;
                    break;
            }
            break;
    }
}

static void sub_8135130(u8 taskId)
{
    RtcCalcLocalTime();
    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] = gLocalTime.hours;
    gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] = gLocalTime.minutes;
    gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE] = gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] * 6;
    gTasks[taskId].data[WALL_CLOCK_TASK_HOUR_HAND_ANGLE] = (gTasks[taskId].data[WALL_CLOCK_TASK_HOUR] % 12) * 30 + (gTasks[taskId].data[WALL_CLOCK_TASK_MINUTE] / 10) * 5;
    if (gLocalTime.hours < 12)
    {
        gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = FALSE;
    }
    else
    {
        gTasks[taskId].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM] = TRUE;
    }
}

static void sub_81351AC(struct Sprite *sprite)
{
    u16 angle = gTasks[sprite->data0].data[WALL_CLOCK_TASK_MINUTE_HAND_ANGLE];
    s16 sin = Sin2(angle) / 16;
    s16 cos = Cos2(angle) / 16;
    u16 xhat;
    u16 yhat;
    SetOamMatrix(0, cos, sin, -sin, cos);
    xhat = gUnknown_085B22D0[angle][0];
    yhat = gUnknown_085B22D0[angle][1];
    if (xhat > 0x80)
    {
        xhat |= 0xff00;
    }
    if (yhat > 0x80)
    {
        yhat |= 0xff00;
    }
    sprite->pos2.x = xhat;
    sprite->pos2.y = yhat;
}

static void sub_8135244(struct Sprite *sprite)
{
    u16 angle = gTasks[sprite->data0].data[WALL_CLOCK_TASK_HOUR_HAND_ANGLE];
    s16 sin = Sin2(angle) / 16;
    s16 cos = Cos2(angle) / 16;
    u16 xhat;
    u16 yhat;
    SetOamMatrix(1, cos, sin, -sin, cos);
    xhat = gUnknown_085B22D0[angle][0];
    yhat = gUnknown_085B22D0[angle][1];
    if (xhat > 0x80)
    {
        xhat |= 0xff00;
    }
    if (yhat > 0x80)
    {
        yhat |= 0xff00;
    }
    sprite->pos2.x = xhat;
    sprite->pos2.y = yhat;
}

static void sub_81352DC(struct Sprite *sprite)
{
    if (gTasks[sprite->data0].data[WALL_CLOCK_TASK_12HRCLOCK_AM_PM])
    {
        if ((u16)(sprite->data1 - 60) < 30)
        {
            sprite->data1 += 5;
        }
        if (sprite->data1 < 60)
        {
            sprite->data1++;
        }
    }
    else
    {
        if ((u16)(sprite->data1 - 46) < 30)
        {
            sprite->data1 -= 5;
        }
        if (sprite->data1 > 75)
        {
            sprite->data1--;
        }
    }
    sprite->pos2.x = Cos2(sprite->data1) * 30 / 0x1000;
    sprite->pos2.y = Sin2(sprite->data1) * 30 / 0x1000;
}
