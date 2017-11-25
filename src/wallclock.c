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
#include "decompress.h"

// static types

// static declarations

void sub_8134C9C(void);
void sub_8134CB8(u8 taskId);
void sub_81351AC(struct Sprite *sprite);
void sub_8135244(struct Sprite *sprite);
void sub_81352DC(struct Sprite *sprite);
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
    gTasks[taskId].data[2] = 10;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0x12c;
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
    gSprites[spriteId].data1 = 0x2d;
    spriteId = CreateSprite(&gUnknown_085B22B8, 0x78, 0x50, 2);
    gSprites[spriteId].data0 = taskId;
    gSprites[spriteId].data1 = 0x5a;
    sub_813498C();
    PrintTextOnWindow(1, 1, gText_Confirm3, 0, 1, 0, NULL);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(2);
}
