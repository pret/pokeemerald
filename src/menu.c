#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "blit.h"
#include "dma3.h"
#include "event_data.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "region_map.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/songs.h"

#define DLG_WINDOW_PALETTE_NUM 15
#define DLG_WINDOW_BASE_TILE_NUM 0x200
#define STD_WINDOW_PALETTE_NUM 14
#define STD_WINDOW_BASE_TILE_NUM 0x214

struct MenuInfoIcon
{
    u8 width;
    u8 height;
    u16 offset;
};

struct Menu
{
    u8 left;
    u8 top;
    s8 cursorPos;
    s8 minCursorPos;
    s8 maxCursorPos;
    u8 windowId;
    u8 fontId;
    u8 optionWidth;
    u8 optionHeight;
    u8 columns;
    u8 rows;
    bool8 APressMuted;
};

static EWRAM_DATA u8 sStartMenuWindowId = 0;
static EWRAM_DATA u8 sMapNamePopupWindowId = 0;
static EWRAM_DATA struct Menu sMenu = {0};
static EWRAM_DATA u16 sTileNum = 0;
static EWRAM_DATA u8 sPaletteNum = 0;
static EWRAM_DATA u8 sYesNoWindowId = 0;
static EWRAM_DATA u8 sWindowId = 0;
static EWRAM_DATA u16 sFiller = 0;  // needed to align
static EWRAM_DATA bool8 sScheduledBgCopiesToVram[4] = {FALSE};
static EWRAM_DATA u16 sTempTileDataBufferIdx = 0;
static EWRAM_DATA void *sTempTileDataBuffer[0x20] = {NULL};

const u16 gUnknown_0860F074[] = INCBIN_U16("graphics/interface/860F074.gbapal");

static const u8 sTextSpeedFrameDelays[] = 
{ 
    [OPTIONS_TEXT_SPEED_SLOW] = 8, 
    [OPTIONS_TEXT_SPEED_MID]  = 4, 
    [OPTIONS_TEXT_SPEED_FAST] = 1 
};

static const struct WindowTemplate sStandardTextBox_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sYesNo_WindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x125
};

const u16 gUnknown_0860F0B0[] = INCBIN_U16("graphics/interface/860F0B0.gbapal");
const u8 sTextColors[] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };

// Table of move info icon offsets in graphics/interface_fr/menu.png
static const struct MenuInfoIcon sMenuInfoIcons[] =
{   // { width, height, offset }
    { 12, 12, 0x00 },  // Unused
    [TYPE_NORMAL + 1]   = { 32, 12, 0x20 },
    [TYPE_FIGHTING + 1] = { 32, 12, 0x64 },
    [TYPE_FLYING + 1]   = { 32, 12, 0x60 },
    [TYPE_POISON + 1]   = { 32, 12, 0x80 },
    [TYPE_GROUND + 1]   = { 32, 12, 0x48 },
    [TYPE_ROCK + 1]     = { 32, 12, 0x44 },
    [TYPE_BUG + 1]      = { 32, 12, 0x6C },
    [TYPE_GHOST + 1]    = { 32, 12, 0x68 },
    [TYPE_STEEL + 1]    = { 32, 12, 0x88 },
    [TYPE_MYSTERY + 1]  = { 32, 12, 0xA4 },
    [TYPE_FIRE + 1]     = { 32, 12, 0x24 },
    [TYPE_WATER + 1]    = { 32, 12, 0x28 },
    [TYPE_GRASS + 1]    = { 32, 12, 0x2C },
    [TYPE_ELECTRIC + 1] = { 32, 12, 0x40 },
    [TYPE_PSYCHIC + 1]  = { 32, 12, 0x84 },
    [TYPE_ICE + 1]      = { 32, 12, 0x4C },
    [TYPE_DRAGON + 1]   = { 32, 12, 0xA0 },
    [TYPE_DARK + 1]     = { 32, 12, 0x8C },
    [TYPE_FAIRY + 1]    = { 32, 12, 0x4  },
    [MENU_INFO_ICON_TYPE]      = { 42, 12, 0xA8 },
    [MENU_INFO_ICON_POWER]     = { 42, 12, 0xC0 },
    [MENU_INFO_ICON_ACCURACY]  = { 42, 12, 0xC8 },
    [MENU_INFO_ICON_PP]        = { 42, 12, 0xE0 },
    [MENU_INFO_ICON_EFFECT]    = { 42, 12, 0xE8 }, // Unused
    [MENU_INFO_ICON_BALL_RED]  = {  8,  8, 0xAE }, // For placed decorations in Secret Base
    [MENU_INFO_ICON_BALL_BLUE] = {  8,  8, 0xAF }, // For placed decorations in player's room
};


// Forward declarations
void WindowFunc_DrawStandardFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_DrawDialogueFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearStdWindowAndFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearDialogWindowAndFrame(u8, u8, u8, u8, u8, u8);
void WindowFunc_DrawDialogFrameWithCustomTileAndPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearDialogWindowAndFrameNullPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_DrawStdFrameWithCustomTileAndPalette(u8, u8, u8, u8, u8, u8);
void WindowFunc_ClearStdWindowAndFrameToTransparent(u8, u8, u8, u8, u8, u8);
void sub_8198C78(void);
void task_free_buf_after_copying_tile_data_to_vram(u8 taskId);

void InitStandardTextBoxWindows(void)
{
    InitWindows(sStandardTextBox_WindowTemplates);
    sStartMenuWindowId = WINDOW_NONE;
    sMapNamePopupWindowId = WINDOW_NONE;
}

void FreeAllOverworldWindowBuffers(void)
{
    FreeAllWindowBuffers();
}

void InitTextBoxGfxAndPrinters(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

u16 RunTextPrintersAndIsPrinter0Active(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(0);
}

u16 AddTextPrinterParameterized2(u8 windowId, u8 fontId, const u8 *str, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 fgColor, u8 bgColor, u8 shadowColor)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = 0;
    printer.y = 1;
    printer.currentX = 0;
    printer.currentY = 1;
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.unk = 0;
    printer.fgColor = fgColor;
    printer.bgColor = bgColor;
    printer.shadowColor = shadowColor;

    gTextFlags.useAlternateDownArrow = 0;
    return AddTextPrinter(&printer, speed, callback);
}

void AddTextPrinterForMessage(bool8 allowSkippingDelayWithButtonPress)
{
    void (*callback)(struct TextPrinterTemplate *, u16) = NULL;
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), callback, 2, 1, 3);
}

void AddTextPrinterForMessage_2(bool8 allowSkippingDelayWithButtonPress)
{
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), NULL, 2, 1, 3);
}

void AddTextPrinterWithCustomSpeedForMessage(bool8 allowSkippingDelayWithButtonPress, u8 speed)
{
    gTextFlags.canABSpeedUpPrint = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized2(0, 1, gStringVar4, speed, NULL, 2, 1, 3);
}

void LoadMessageBoxAndBorderGfx(void)
{
    LoadMessageBoxGfx(0, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM * 0x10);
    LoadUserWindowBorderGfx(0, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM * 0x10);
}

void DrawDialogueFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawDialogueFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawStdWindowFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_DrawStandardFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void ClearDialogWindowAndFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearDialogWindowAndFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void ClearStdWindowAndFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearStdWindowAndFrame);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_DrawStandardFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    int i;

    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 0,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 1,
                            tilemapLeft,
                            tilemapTop - 1,
                            width,
                            1,
                            STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 2,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            STD_WINDOW_PALETTE_NUM);

    for (i = tilemapTop; i < tilemapTop + height; i++)
    {
        FillBgTilemapBufferRect(bg,
                                STD_WINDOW_BASE_TILE_NUM + 3,
                                tilemapLeft - 1,
                                i,
                                1,
                                1,
                                STD_WINDOW_PALETTE_NUM);
        FillBgTilemapBufferRect(bg,
                                STD_WINDOW_BASE_TILE_NUM + 5,
                                tilemapLeft + width,
                                i,
                                1,
                                1,
                                STD_WINDOW_PALETTE_NUM);
    }

    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 6,
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 7,
                            tilemapLeft,
                            tilemapTop + height,
                            width,
                            1,
                            STD_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            STD_WINDOW_BASE_TILE_NUM + 8,
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            STD_WINDOW_PALETTE_NUM);
}

void WindowFunc_DrawDialogueFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 1,
                            tilemapLeft - 2,
                            tilemapTop - 1,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 3,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 4,
                            tilemapLeft,
                            tilemapTop - 1,
                            width - 1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 5,
                            tilemapLeft + width - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 6,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 7,
                            tilemapLeft - 2,
                            tilemapTop,
                            1,
                            5,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 9,
                            tilemapLeft - 1,
                            tilemapTop,
                            width + 1,
                            5,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            DLG_WINDOW_BASE_TILE_NUM + 10,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            5,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(DLG_WINDOW_BASE_TILE_NUM + 1),
                            tilemapLeft - 2,
                            tilemapTop + height,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(DLG_WINDOW_BASE_TILE_NUM + 3),
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(DLG_WINDOW_BASE_TILE_NUM + 4),
                            tilemapLeft,
                            tilemapTop + height,
                            width - 1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(DLG_WINDOW_BASE_TILE_NUM + 5),
                            tilemapLeft + width - 1,
                            tilemapTop + height,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(DLG_WINDOW_BASE_TILE_NUM + 6),
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            DLG_WINDOW_PALETTE_NUM);
}

void WindowFunc_ClearStdWindowAndFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, STD_WINDOW_PALETTE_NUM);
}

void WindowFunc_ClearDialogWindowAndFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, STD_WINDOW_PALETTE_NUM);
}

void SetStandardWindowBorderStyle(u8 windowId, bool8 copyToVram)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, copyToVram, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
}

void sub_819786C(u8 windowId, bool8 copyToVram)
{
    LoadMessageBoxGfx(windowId, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM * 0x10);
    DrawDialogFrameWithCustomTileAndPalette(windowId, copyToVram, DLG_WINDOW_BASE_TILE_NUM, 0xF);
}

void sub_819789C(void)
{
    LoadPalette(gUnknown_0860F074, STD_WINDOW_PALETTE_NUM * 0x10, 0x14);
}

void Menu_LoadStdPalAt(u16 offset)
{
    LoadPalette(gUnknown_0860F074, offset, 0x14);
}

const u16 *sub_81978C8(void)
{
    return gUnknown_0860F074;
}

u16 sub_81978D0(u8 colorNum)
{
    if (colorNum > 15)
        colorNum = 0;
    return gUnknown_0860F074[colorNum];
}

void DisplayItemMessageOnField(u8 taskId, const u8 *string, TaskFunc callback)
{
    LoadMessageBoxAndBorderGfx();
    DisplayMessageAndContinueTask(taskId, 0, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM, 1, GetPlayerTextSpeedDelay(), string, callback);
    CopyWindowToVram(0, 3);
}

void DisplayYesNoMenuDefaultYes(void)
{
    CreateYesNoMenu(&sYesNo_WindowTemplates, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, 0);
}

void DisplayYesNoMenuWithDefault(u8 initialCursorPos)
{
    CreateYesNoMenu(&sYesNo_WindowTemplates, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, initialCursorPos);
}

u32 GetPlayerTextSpeed(void)
{
    if (gTextFlags.forceMidTextSpeed)
        return OPTIONS_TEXT_SPEED_MID;
    return gSaveBlock2Ptr->optionsTextSpeed;
}

u8 GetPlayerTextSpeedDelay(void)
{
    u32 speed;
    if (gSaveBlock2Ptr->optionsTextSpeed > OPTIONS_TEXT_SPEED_FAST)
        gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    speed = GetPlayerTextSpeed();
    return sTextSpeedFrameDelays[speed];
}

u8 sub_81979C4(u8 a1)
{
    if (sStartMenuWindowId == WINDOW_NONE)
        sStartMenuWindowId = sub_8198AA4(0, 0x16, 1, 7, (a1 * 2) + 2, 0xF, 0x139);
    return sStartMenuWindowId;
}

u8 GetStartMenuWindowId(void)
{
    return sStartMenuWindowId;
}

void RemoveStartMenuWindow(void)
{
    if (sStartMenuWindowId != WINDOW_NONE)
    {
        RemoveWindow(sStartMenuWindowId);
        sStartMenuWindowId = WINDOW_NONE;
    }
}

// Unused
static u16 GetDialogFrameBaseTileNum(void)
{
    return DLG_WINDOW_BASE_TILE_NUM;
}

// Unused
static u16 GetStandardFrameBaseTileNum(void)
{
    return STD_WINDOW_BASE_TILE_NUM;
}

u8 AddMapNamePopUpWindow(void)
{
    if (sMapNamePopupWindowId == WINDOW_NONE)
        sMapNamePopupWindowId = sub_8198AA4(0, 1, 1, 10, 3, 14, 0x107);
    return sMapNamePopupWindowId;
}

u8 GetMapNamePopUpWindowId(void)
{
    return sMapNamePopupWindowId;
}

void RemoveMapNamePopUpWindow(void)
{
    if (sMapNamePopupWindowId != WINDOW_NONE)
    {
        RemoveWindow(sMapNamePopupWindowId);
        sMapNamePopupWindowId = WINDOW_NONE;
    }
}

void AddTextPrinterWithCallbackForMessage(bool8 a1, void (*callback)(struct TextPrinterTemplate *, u16))
{
    gTextFlags.canABSpeedUpPrint = a1;
    AddTextPrinterParameterized2(0, 1, gStringVar4, GetPlayerTextSpeedDelay(), callback, 2, 1, 3);
}

void sub_8197AE8(bool8 copyToVram)
{
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x11);
    if (copyToVram == TRUE)
        CopyBgTilemapBufferToVram(0);
}

void DrawDialogFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 tileNum, u8 paletteNum)
{
    sTileNum = tileNum;
    sPaletteNum = paletteNum;
    CallWindowFunction(windowId, WindowFunc_DrawDialogFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

// Never used.
void DrawDialogFrameWithCustomTile(u8 windowId, bool8 copyToVram, u16 tileNum)
{
    sTileNum = tileNum;
    sPaletteNum = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, WindowFunc_DrawDialogFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_DrawDialogFrameWithCustomTileAndPalette(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg,
                            sTileNum + 1,
                            tilemapLeft - 2,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 3,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 4,
                            tilemapLeft,
                            tilemapTop - 1,
                            width - 1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 5,
                            tilemapLeft + width - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 6,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 7,
                            tilemapLeft - 2,
                            tilemapTop,
                            1,
                            5,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 9,
                            tilemapLeft - 1,
                            tilemapTop,
                            width + 1,
                            5,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 10,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            5,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(sTileNum + 1),
                            tilemapLeft - 2,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(sTileNum + 3),
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(sTileNum + 4),
                            tilemapLeft,
                            tilemapTop + height,
                            width - 1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(sTileNum + 5),
                            tilemapLeft + width - 1,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(sTileNum + 6),
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
}

void ClearDialogWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram)
{
    // The palette slot doesn't matter, since the tiles are transparent.
    CallWindowFunction(windowId, WindowFunc_ClearDialogWindowAndFrameNullPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_ClearDialogWindowAndFrameNullPalette(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, 0);
}

void DrawStdFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum)
{
    sTileNum = baseTileNum;
    sPaletteNum = paletteNum;
    CallWindowFunction(windowId, WindowFunc_DrawStdFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

// Never used.
void DrawStdFrameWithCustomTile(u8 windowId, bool8 copyToVram, u16 baseTileNum)
{
    sTileNum = baseTileNum;
    sPaletteNum = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, WindowFunc_DrawStdFrameWithCustomTileAndPalette);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_DrawStdFrameWithCustomTileAndPalette(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg,
                            sTileNum + 0,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 1,
                            tilemapLeft,
                            tilemapTop - 1,
                            width,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 2,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 3,
                            tilemapLeft - 1,
                            tilemapTop,
                            1,
                            height,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 5,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            height,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 6,
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 7,
                            tilemapLeft,
                            tilemapTop + height,
                            width,
                            1,
                            sPaletteNum);
    FillBgTilemapBufferRect(bg,
                            sTileNum + 8,
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            sPaletteNum);
}

void ClearStdWindowAndFrameToTransparent(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearStdWindowAndFrameToTransparent);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void WindowFunc_ClearStdWindowAndFrameToTransparent(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0);
}

u8 sub_81980F0(u8 bg, u8 xPos, u8 yPos, u8 palette, u16 baseTile)
{
    struct WindowTemplate window;
    memset(&window, 0, sizeof(window));

    if (bg > 3)
        window.bg = 0;
    else
        window.bg = bg;

    window.tilemapTop = yPos;
    window.height = 2;
    window.tilemapLeft = 0x1E - xPos;
    window.width = xPos;
    window.paletteNum = palette;
    window.baseBlock = baseTile;

    sWindowId = AddWindow(&window);

    if (palette > 15)
        palette = 15 * 16;
    else
        palette *= 16;

    LoadPalette(gUnknown_0860F0B0, palette, sizeof(gUnknown_0860F0B0));
    return sWindowId;
}

void sub_8198180(const u8 *string, u8 a2, bool8 copyToVram)
{
    u16 width = 0;

    if (sWindowId != WINDOW_NONE)
    {
        PutWindowTilemap(sWindowId);
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        width = GetStringWidth(0, string, 0);
        AddTextPrinterParameterized3(sWindowId,
                  0,
                  0xEC - (GetWindowAttribute(sWindowId, WINDOW_TILEMAP_LEFT) * 8) - a2 - width,
                  1,
                  sTextColors,
                  0,
                  string);
        if (copyToVram)
            CopyWindowToVram(sWindowId, 3);
    }
}

void sub_8198204(const u8 *string, const u8 *string2, u8 a3, u8 a4, bool8 copyToVram)
{
    u8 color[3];
    u16 width = 0;

    if (sWindowId != WINDOW_NONE)
    {
        if (a3 != 0)
        {
            color[0] = TEXT_COLOR_TRANSPARENT;
            color[1] = TEXT_COLOR_WHITE;
            color[2] = TEXT_COLOR_DARK_GRAY;
        }
        else
        {
            color[0] = TEXT_DYNAMIC_COLOR_6;
            color[1] = TEXT_COLOR_WHITE;
            color[2] = TEXT_COLOR_DARK_GRAY;
        }
        PutWindowTilemap(sWindowId);
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        if (string2 != NULL)
        {
            width = GetStringWidth(0, string2, 0);
            AddTextPrinterParameterized3(sWindowId,
                      0,
                      0xEC - (GetWindowAttribute(sWindowId, WINDOW_TILEMAP_LEFT) * 8) - a4 - width,
                      1,
                      color,
                      0,
                      string2);
        }
        AddTextPrinterParameterized4(sWindowId, 1, 4, 1, 0, 0, color, 0, string);
        if (copyToVram)
            CopyWindowToVram(sWindowId, 3);
    }
}

void sub_81982D8(void)
{
    if (sWindowId != WINDOW_NONE)
        CopyWindowToVram(sWindowId, 3);
}

void sub_81982F0(void)
{
    if (sWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(15));
        CopyWindowToVram(sWindowId, 3);
    }
}

void sub_8198314(void)
{
    if (sWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(sWindowId);
        CopyWindowToVram(sWindowId, 3);
        RemoveWindow(sWindowId);
        sWindowId = WINDOW_NONE;
    }
}

u8 sub_8198348(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos, u8 a7)
{
    s32 pos;

    sMenu.left = left;
    sMenu.top = top;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = numChoices - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = fontId;
    sMenu.optionHeight = cursorHeight;
    sMenu.APressMuted = a7;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    Menu_MoveCursor(0);
    return sMenu.cursorPos;
}

u8 sub_81983AC(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos)
{
    return sub_8198348(windowId, fontId, left, top, cursorHeight, numChoices, initialCursorPos, 0);
}

u8 sub_81983EC(u8 windowId, u8 fontId, u8 left, u8 top, u8 numChoices, u8 initialCursorPos)
{
    u8 cursorHeight = GetMenuCursorDimensionByFont(fontId, 1);
    return sub_81983AC(windowId, fontId, left, top, cursorHeight, numChoices, initialCursorPos);
}

void RedrawMenuCursor(u8 oldPos, u8 newPos)
{
    u8 width, height;

    width = GetMenuCursorDimensionByFont(sMenu.fontId, 0);
    height = GetMenuCursorDimensionByFont(sMenu.fontId, 1);
    FillWindowPixelRect(sMenu.windowId, PIXEL_FILL(1), sMenu.left, sMenu.optionHeight * oldPos + sMenu.top, width, height);
    AddTextPrinterParameterized(sMenu.windowId, sMenu.fontId, gText_SelectorArrow3, sMenu.left, sMenu.optionHeight * newPos + sMenu.top, 0, 0);
}

u8 Menu_MoveCursor(s8 cursorDelta)
{
    u8 oldPos = sMenu.cursorPos;
    int newPos = sMenu.cursorPos + cursorDelta;

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, sMenu.cursorPos);
    return sMenu.cursorPos;
}

u8 Menu_MoveCursorNoWrapAround(s8 cursorDelta)
{
    u8 oldPos = sMenu.cursorPos;
    int newPos = sMenu.cursorPos + cursorDelta;

    if (newPos < sMenu.minCursorPos)
        sMenu.cursorPos = sMenu.minCursorPos;
    else if (newPos > sMenu.maxCursorPos)
        sMenu.cursorPos = sMenu.maxCursorPos;
    else
        sMenu.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, sMenu.cursorPos);
    return sMenu.cursorPos;
}

u8 Menu_GetCursorPos(void)
{
    return sMenu.cursorPos;
}

s8 Menu_ProcessInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(-1);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(1);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputNoWrap(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (JOY_NEW(A_BUTTON))
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 ProcessMenuInput_other(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(-1);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        Menu_MoveCursor(1);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputNoWrapAround_other(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (JOY_NEW(A_BUTTON))
    {
        if (!sMenu.APressMuted)
            PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if (JOY_REPEAT(DPAD_ANY) == DPAD_UP)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_REPEAT(DPAD_ANY) == DPAD_DOWN)
    {
        if (oldPos != Menu_MoveCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

void PrintTextArray(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *menuActions)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized(windowId, fontId, menuActions[i].text, left, (lineHeight * i) + top, 0xFF, NULL);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_81987BC(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *menuActions, u8 a6, u8 a7)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized5(windowId, fontId, menuActions[i].text, left, (lineHeight * i) + top, 0xFF, NULL, a6, a7);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198854(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *menuActions)
{
    PrintTextArray(windowId, fontId, GetFontAttribute(fontId, 0), 1, lineHeight, itemCount, menuActions);
}

void AddItemMenuActionTextPrinters(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineHeight, u8 itemCount, const struct MenuAction *menuActions, const u8 *actionIds)
{
    u8 i;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    printer.x = left;
    printer.currentX = left;

    for (i = 0; i < itemCount; i++)
    {
        printer.currentChar = menuActions[actionIds[i]].text;
        printer.y = (lineHeight * i) + top;
        printer.currentY = printer.y;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81989B8(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *menuActions, const u8 *actionIds)
{
    AddItemMenuActionTextPrinters(windowId, fontId, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH), 1, GetFontAttribute(fontId, FONTATTR_LETTER_SPACING), lineHeight, itemCount, menuActions, actionIds);
}

void SetWindowTemplateFields(struct WindowTemplate *template, u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    template->bg = bg;
    template->tilemapLeft = left;
    template->tilemapTop = top;
    template->width = width;
    template->height = height;
    template->paletteNum = paletteNum;
    template->baseBlock = baseBlock;
}

struct WindowTemplate CreateWindowTemplate(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, bg, left, top, width, height, paletteNum, baseBlock);
    return template;
}

u16 sub_8198AA4(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, bg, left, top, width, height, paletteNum, baseBlock);
    return AddWindow(&template);
}

void sub_8198AF8(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate printer;

    sYesNoWindowId = AddWindow(window);
    DrawStdFrameWithCustomTileAndPalette(sYesNoWindowId, TRUE, baseTileNum, paletteNum);

    printer.currentChar = gText_YesNo;
    printer.windowId = sYesNoWindowId;
    printer.fontId = fontId;
    printer.x = GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH) + left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);

    AddTextPrinter(&printer, 0xFF, NULL);

    sub_81983AC(sYesNoWindowId, fontId, left, top, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_HEIGHT), 2, initialCursorPos);
}

void sub_8198C34(const struct WindowTemplate *window, u8 fontId, u16 baseTileNum, u8 paletteNum)
{
    sub_8198AF8(window, fontId, 0, 1, baseTileNum, paletteNum, 0);
}

s8 Menu_ProcessInputNoWrapClearOnChoose(void)
{
    s8 result = Menu_ProcessInputNoWrap();
    if (result != MENU_NOTHING_CHOSEN)
        sub_8198C78();
    return result;
}

void sub_8198C78(void)
{
    ClearStdWindowAndFrameToTransparent(sYesNoWindowId, TRUE);
    RemoveWindow(sYesNoWindowId);
}

void sub_8198C94(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7, const struct MenuAction *menuActions)
{
    u8 i;
    u8 j;
    for (i = 0; i < a7; i++)
    {
        for (j = 0; j < a6; j++)
        {
            AddTextPrinterParameterized(windowId, fontId, menuActions[(i * a6) + j].text, (a4 * j) + left, (a5 * i) + top, 0xFF, NULL);
        }
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198D54(u8 windowId, u8 fontId, u8 a2, u8 a3, u8 a4, u8 a5, const struct MenuAction *menuActions)
{
    sub_8198C94(windowId, fontId, GetFontAttribute(fontId, 0), 0, a2, a3, a4, a5, menuActions);
}

void PrintMenuActionGrid(u8 windowId, u8 fontId, u8 left, u8 top, u8 optionWidth, u8 horizontalCount, u8 verticalCount, const struct MenuAction *menuActions, const u8 *actionIds)
{
    u8 i;
    u8 j;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    printer.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    printer.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);

    for (i = 0; i < verticalCount; i++)
    {
        for (j = 0; j < horizontalCount; j++)
        {
            printer.currentChar = menuActions[actionIds[(horizontalCount * i) + j]].text;
            printer.x = (optionWidth * j) + left;
            printer.y = (GetFontAttribute(fontId, FONTATTR_MAX_LETTER_HEIGHT) * i) + top;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

// Unused
static void PrintMenuActionGrid_TopLeft(u8 windowId, u8 fontId, u8 optionWidth, u8 unused, u8 horizontalCount, u8 verticalCount, const struct MenuAction *menuActions, const u8 *actionIds)
{
    PrintMenuActionGrid(windowId, fontId, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_WIDTH), 0, optionWidth, horizontalCount, verticalCount, menuActions, actionIds);
}

u8 sub_8198F58(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 cursorHeight, u8 a6, u8 a7, u8 numChoices, u8 a9)
{
    s32 pos;

    sMenu.left = left;
    sMenu.top = top;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = numChoices - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = fontId;
    sMenu.optionWidth = a4;
    sMenu.optionHeight = cursorHeight;
    sMenu.columns = a6;
    sMenu.rows = a7;

    pos = a9;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    // Why call this when it's not gonna move?
    ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_NONE);
    return sMenu.cursorPos;
}

// Unused
u8 sub_8198FD4(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7)
{
    u8 cursorHeight = GetMenuCursorDimensionByFont(fontId, 1);
    u8 numChoices = a5 * a6;
    return sub_8198F58(windowId, fontId, left, top, a4, cursorHeight, a5, a6, numChoices, a7);
}

void sub_8199060(u8 oldCursorPos, u8 newCursorPos)
{
    u8 cursorWidth = GetMenuCursorDimensionByFont(sMenu.fontId, 0);
    u8 cursorHeight = GetMenuCursorDimensionByFont(sMenu.fontId, 1);
    u8 xPos = (oldCursorPos % sMenu.columns) * sMenu.optionWidth + sMenu.left;
    u8 yPos = (oldCursorPos / sMenu.columns) * sMenu.optionHeight + sMenu.top;
    FillWindowPixelRect(sMenu.windowId,
                        PIXEL_FILL(1),
                        xPos,
                        yPos,
                        cursorWidth,
                        cursorHeight);
    xPos = (newCursorPos % sMenu.columns) * sMenu.optionWidth + sMenu.left;
    yPos = (newCursorPos / sMenu.columns) * sMenu.optionHeight + sMenu.top;
    AddTextPrinterParameterized(sMenu.windowId,
                      sMenu.fontId,
                      gText_SelectorArrow3,
                      xPos,
                      yPos,
                      0,
                      0);
}

u8 ChangeListMenuCursorPosition(s8 deltaX, s8 deltaY)
{
    u8 oldPos = sMenu.cursorPos;

    if (deltaX != 0)
    {
        if ((sMenu.cursorPos % sMenu.columns) + deltaX < 0)
            sMenu.cursorPos += sMenu.columns - 1;
        else if ((sMenu.cursorPos % sMenu.columns) + deltaX >= sMenu.columns)
            sMenu.cursorPos = (sMenu.cursorPos / sMenu.columns) * sMenu.columns;
        else
            sMenu.cursorPos += deltaX;
    }

    if (deltaY != 0)
    {
        if ((sMenu.cursorPos / sMenu.columns) + deltaY < 0)
            sMenu.cursorPos += sMenu.columns * (sMenu.rows - 1);
        else if ((sMenu.cursorPos / sMenu.columns) + deltaY >= sMenu.rows)
            sMenu.cursorPos -= sMenu.columns * (sMenu.rows - 1);
        else
            sMenu.cursorPos += (sMenu.columns * deltaY);
    }

    if (sMenu.cursorPos > sMenu.maxCursorPos)
    {
        sMenu.cursorPos = oldPos;
        return sMenu.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, sMenu.cursorPos);
        return sMenu.cursorPos;
    }
}

u8 ChangeGridMenuCursorPosition(s8 deltaX, s8 deltaY)
{
    u8 oldPos = sMenu.cursorPos;

    if (deltaX != 0)
    {
        if (((sMenu.cursorPos % sMenu.columns) + deltaX >= 0) &&
        ((sMenu.cursorPos % sMenu.columns) + deltaX < sMenu.columns))
        {
            sMenu.cursorPos += deltaX;
        }
    }

    if (deltaY != 0)
    {
        if (((sMenu.cursorPos / sMenu.columns) + deltaY >= 0) &&
        ((sMenu.cursorPos / sMenu.columns) + deltaY < sMenu.rows))
        {
            sMenu.cursorPos += (sMenu.columns * deltaY);
        }
    }

    if (sMenu.cursorPos > sMenu.maxCursorPos)
    {
        sMenu.cursorPos = oldPos;
        return sMenu.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, sMenu.cursorPos);
        return sMenu.cursorPos;
    }
}

s8 sub_8199284(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 Menu_ProcessInputGridLayout(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (oldPos != ChangeGridMenuCursorPosition(0, -1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (oldPos != ChangeGridMenuCursorPosition(0, 1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
    {
        if (oldPos != ChangeGridMenuCursorPosition(-1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
    {
        if (oldPos != ChangeGridMenuCursorPosition(1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

s8 sub_81993D8(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_LEFT || GetLRKeysPressedAndHeld() == MENU_L_PRESSED)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_RIGHT || GetLRKeysPressedAndHeld() == MENU_R_PRESSED)
    {
        PlaySE(SE_SELECT);
        ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

//Unused
s8 sub_8199484(void)
{
    u8 oldPos = sMenu.cursorPos;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return sMenu.cursorPos;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return MENU_B_PRESSED;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_UP)
    {
        if (oldPos != ChangeGridMenuCursorPosition(0, -1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_DOWN)
    {
        if (oldPos != ChangeGridMenuCursorPosition(0, 1))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_LEFT || GetLRKeysPressedAndHeld() == MENU_L_PRESSED)
    {
        if (oldPos != ChangeGridMenuCursorPosition(-1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }
    else if ((JOY_REPEAT(DPAD_ANY)) == DPAD_RIGHT || GetLRKeysPressedAndHeld() == MENU_R_PRESSED)
    {
        if (oldPos != ChangeGridMenuCursorPosition(1, 0))
            PlaySE(SE_SELECT);
        return MENU_NOTHING_CHOSEN;
    }

    return MENU_NOTHING_CHOSEN;
}

u8 InitMenuInUpperLeftCorner(u8 windowId, u8 itemCount, u8 initialCursorPos, bool8 APressMuted)
{
    s32 pos;

    sMenu.left = 0;
    sMenu.top = 1;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = itemCount - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = 1;
    sMenu.optionHeight = 16;
    sMenu.APressMuted = APressMuted;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    return Menu_MoveCursor(0);
}

u8 InitMenuInUpperLeftCornerPlaySoundWhenAPressed(u8 windowId, u8 itemCount, u8 initialCursorPos)
{
    return InitMenuInUpperLeftCorner(windowId, itemCount, initialCursorPos, FALSE);
}

void PrintMenuTable(u8 windowId, u8 itemCount, const struct MenuAction *menuActions)
{
    u32 i;

    for (i = 0; i < itemCount; i++)
    {
        AddTextPrinterParameterized(windowId, 1, menuActions[i].text, 8, (i * 16) + 1, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81995E4(u8 windowId, u8 itemCount, const struct MenuAction *menuActions, const u8 *actionIds)
{
    u8 i;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.x = 8;
    printer.currentX = 8;

    for (i = 0; i < itemCount; i++)
    {
        printer.currentChar = menuActions[actionIds[i]].text;
        printer.y = (i * 16) + 1;
        printer.currentY = (i * 16) + 1;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void CreateYesNoMenu(const struct WindowTemplate *window, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate printer;

    sYesNoWindowId = AddWindow(window);
    DrawStdFrameWithCustomTileAndPalette(sYesNoWindowId, TRUE, baseTileNum, paletteNum);

    printer.currentChar = gText_YesNo;
    printer.windowId = sYesNoWindowId;
    printer.fontId = 1;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    AddTextPrinter(&printer, 0xFF, NULL);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sYesNoWindowId, 2, initialCursorPos);
}

void PrintMenuGridTable(u8 windowId, u8 optionWidth, u8 columns, u8 rows, const struct MenuAction *menuActions)
{
    u32 i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            AddTextPrinterParameterized(windowId, 1, menuActions[(i * columns) + j].text, (optionWidth * j) + 8, (i * 16) + 1, 0xFF, NULL);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_819983C(u8 windowId, u8 a4, u8 itemCount, u8 itemCount2, const struct MenuAction *menuActions, const u8 *actionIds)
{
    u8 i;
    u8 j;
    struct TextPrinterTemplate printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, FONTATTR_COLOR_FOREGROUND);
    printer.bgColor = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    printer.shadowColor = GetFontAttribute(1, FONTATTR_COLOR_SHADOW);
    printer.unk = GetFontAttribute(1, FONTATTR_UNKNOWN);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    for (i = 0; i < itemCount2; i++)
    {
        for (j = 0; j < itemCount; j++)
        {
            printer.currentChar = menuActions[actionIds[(itemCount * i) + j]].text;
            printer.x = (a4 * j) + 8;
            printer.y = (16 * i) + 1;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

u8 InitMenuActionGrid(u8 windowId, u8 optionWidth, u8 columns, u8 rows, u8 initialCursorPos)
{
    s32 pos;

    sMenu.left = 0;
    sMenu.top = 1;
    sMenu.minCursorPos = 0;
    sMenu.maxCursorPos = (columns * rows) - 1;
    sMenu.windowId = windowId;
    sMenu.fontId = 1;
    sMenu.optionWidth = optionWidth;
    sMenu.optionHeight = 16;
    sMenu.columns = columns;
    sMenu.rows = rows;

    pos = initialCursorPos;

    if (pos < 0 || pos > sMenu.maxCursorPos)
        sMenu.cursorPos = 0;
    else
        sMenu.cursorPos = pos;

    // Why call this when it's not gonna move?
    ChangeListMenuCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_NONE);
    return sMenu.cursorPos;
}

void ClearScheduledBgCopiesToVram(void)
{
    memset(sScheduledBgCopiesToVram, 0, sizeof(sScheduledBgCopiesToVram));
}

void ScheduleBgCopyTilemapToVram(u8 bgId)
{
    sScheduledBgCopiesToVram[bgId] = TRUE;
}

void DoScheduledBgTilemapCopiesToVram(void)
{
    if (sScheduledBgCopiesToVram[0] == TRUE)
    {
        CopyBgTilemapBufferToVram(0);
        sScheduledBgCopiesToVram[0] = FALSE;
    }
    if (sScheduledBgCopiesToVram[1] == TRUE)
    {
        CopyBgTilemapBufferToVram(1);
        sScheduledBgCopiesToVram[1] = FALSE;
    }
    if (sScheduledBgCopiesToVram[2] == TRUE)
    {
        CopyBgTilemapBufferToVram(2);
        sScheduledBgCopiesToVram[2] = FALSE;
    }
    if (sScheduledBgCopiesToVram[3] == TRUE)
    {
        CopyBgTilemapBufferToVram(3);
        sScheduledBgCopiesToVram[3] = FALSE;
    }
}

void ResetTempTileDataBuffers(void)
{
    int i;
    for (i = 0; i < (int)ARRAY_COUNT(sTempTileDataBuffer); i++)
    {
        sTempTileDataBuffer[i] = NULL;
    }
    sTempTileDataBufferIdx = 0;
}

bool8 FreeTempTileDataBuffersIfPossible(void)
{
    int i;

    if (!IsDma3ManagerBusyWithBgCopy())
    {
        if (sTempTileDataBufferIdx)
        {
            for (i = 0; i < sTempTileDataBufferIdx; i++)
            {
                FREE_AND_SET_NULL(sTempTileDataBuffer[i]);
            }
            sTempTileDataBufferIdx = 0;
        }
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void *DecompressAndCopyTileDataToVram(u8 bgId, const void *src, u32 size, u16 offset, u8 mode)
{
    u32 sizeOut;
    if (sTempTileDataBufferIdx < ARRAY_COUNT(sTempTileDataBuffer))
    {
        void *ptr = malloc_and_decompress(src, &sizeOut);
        if (!size)
            size = sizeOut;
        if (ptr)
        {
            copy_decompressed_tile_data_to_vram(bgId, ptr, size, offset, mode);
            sTempTileDataBuffer[sTempTileDataBufferIdx++] = ptr;
        }
        return ptr;
    }
    return NULL;
}

void DecompressAndLoadBgGfxUsingHeap(u8 bgId, const void *src, u32 size, u16 offset, u8 mode)
{
    u32 sizeOut;
    void *ptr = malloc_and_decompress(src, &sizeOut);
    if (!size)
        size = sizeOut;
    if (ptr)
    {
        u8 taskId = CreateTask(task_free_buf_after_copying_tile_data_to_vram, 0);
        gTasks[taskId].data[0] = copy_decompressed_tile_data_to_vram(bgId, ptr, size, offset, mode);
        SetWordTaskArg(taskId, 1, (u32)ptr);
    }
}

void task_free_buf_after_copying_tile_data_to_vram(u8 taskId)
{
    if (!CheckForSpaceForDma3Request(gTasks[taskId].data[0]))
    {
        Free((void *)GetWordTaskArg(taskId, 1));
        DestroyTask(taskId);
    }
}

void *malloc_and_decompress(const void *src, u32 *size)
{
    void *ptr;
    u8 *sizeAsBytes = (u8 *)size;
    u8 *srcAsBytes = (u8 *)src;

    sizeAsBytes[0] = srcAsBytes[1];
    sizeAsBytes[1] = srcAsBytes[2];
    sizeAsBytes[2] = srcAsBytes[3];
    sizeAsBytes[3] = 0;

    ptr = Alloc(*size);
    if (ptr)
        LZ77UnCompWram(src, ptr);
    return ptr;
}

u16 copy_decompressed_tile_data_to_vram(u8 bgId, const void *src, u16 size, u16 offset, u8 mode)
{
    switch (mode)
    {
        case 0:
            return LoadBgTiles(bgId, src, size, offset);
        case 1:
            return LoadBgTilemap(bgId, src, size, offset);
        default:
            return -1;
    }
}

void SetBgTilemapPalette(u8 bgId, u8 left, u8 top, u8 width, u8 height, u8 palette)
{
    u8 i;
    u8 j;
    u16 *ptr = GetBgTilemapBuffer(bgId);

    for (i = top; i < top + height; i++)
    {
        for (j = left; j < left + width; j++)
        {
            ptr[(i * 32) + j] = (ptr[(i * 32) + j] & 0xFFF) | (palette << 12);
        }
    }
}

void CopyToBufferFromBgTilemap(u8 bgId, u16 *dest, u8 left, u8 top, u8 width, u8 height)
{
    u8 i;
    u8 j;
    const u16 *src = GetBgTilemapBuffer(bgId);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            dest[(i * width) + j] = src[(i + top) * 32 + j + left];
        }
    }
}

void sub_8199D3C(void *ptr, int delta, int width, int height, bool32 is8BPP)
{
    int i;
    int area = width * height;
    if (is8BPP == TRUE)
    {
        u8 *as8BPP = ptr;
        for (i = 0; i < area; i++)
        {
            as8BPP[i] += delta;
        }
    }
    else
    {
        u16 *as4BPP = ptr;
        for (i = 0; i < area; i++)
        {
            as4BPP[i] = (as4BPP[i] & 0xFC00) | ((as4BPP[i] + delta) & 0x3FF);
        }
    }
}

void ResetBgPositions(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgY(3, 0, 0);
}

void sub_8199DF0(u32 bg, u8 a1, int a2, int a3)
{
    int temp = (!GetBgAttribute(bg, BG_ATTR_PALETTEMODE)) ? 0x20 : 0x40;
    void *addr = (void *)((GetBgAttribute(bg, BG_ATTR_CHARBASEINDEX) * 0x4000) + (GetBgAttribute(bg, BG_ATTR_BASETILE) + a2) * temp);
    RequestDma3Fill(a1 << 24 | a1 << 16 | a1 << 8 | a1, addr + VRAM, a3 * temp, 1);
}

void AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 left, u8 top, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];

    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];

    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized5(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 letterSpacing, u8 lineSpacing)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = left;
    printer.currentY = top;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;

    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);

    AddTextPrinter(&printer, speed, callback);
}

void PrintPlayerNameOnWindow(u8 windowId, const u8 *src, u16 x, u16 y)
{
    int count = 0;
    while (gSaveBlock2Ptr->playerName[count] != EOS)
        count++;

    StringExpandPlaceholders(gStringVar4, src);

    AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, 0xFF, 0);
}

// Unused. Similar to BlitBitmapRect4Bit.
void sub_819A080(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height)
{
    int loopSrcY, loopDstY, loopSrcX, loopDstX, xEnd, yEnd, multiplierSrcY, multiplierDstY;
    const u8 *pixelsSrc;
    u8 *pixelsDst;
    u16 toOrr;

    if (dst->width - dstX < width)
        xEnd = dst->width - dstX + srcX;
    else
        xEnd = width + srcX;

    if (dst->height - dstY < height)
        yEnd = srcY + dst->height - dstY;
    else
        yEnd = srcY + height;

    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;

    for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
    {
        for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
        {
            pixelsSrc = src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 29) >> 27);
            pixelsDst = (void*) dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + ((( loopDstY >> 3) * multiplierDstY) << 5) + ((u32)(loopDstY << 29) >> 27);

            if ((uintptr_t)pixelsDst & 0x1)
            {
                pixelsDst--;
                if (loopDstX & 0x1)
                {
                    toOrr = *(vu16*)pixelsDst;
                    toOrr &= 0x0fff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 8);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 12);
                }
                else
                {
                    toOrr = *(vu16*)pixelsDst;
                    toOrr &= 0xf0ff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 8);
                }
            }
            else
            {
                if (loopDstX & 1)
                {
                    toOrr = *(vu16*)pixelsDst;
                    toOrr &= 0xff0f;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 0);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 4);
                }
                else
                {
                    toOrr = *(vu16*)pixelsDst;
                    toOrr &= 0xfff0;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) >> 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) >> 0);
                }
            }
            *(vu16*)pixelsDst = toOrr;
        }
    }
}

void sub_819A25C(u8 palOffset, u16 speciesId)
{
    LoadPalette(GetValidMonIconPalettePtr(speciesId), palOffset, 0x20);
}

void sub_819A27C(u8 windowId, u16 speciesId, u32 personality, u16 x, u16 y)
{
    BlitBitmapToWindow(windowId, GetMonIconPtr(speciesId, personality), x, y, 32, 32);
}

void ListMenuLoadStdPalAt(u8 palOffset, u8 palId)
{
    const u16 *palette;

    switch (palId)
    {
        case 0:
        default:
            palette = gFireRedMenuElements1_Pal;
            break;
        case 1:
            palette = gFireRedMenuElements2_Pal;
            break;
        case 2:
            palette = gFireRedMenuElements3_Pal;
            break;
    }

    LoadPalette(palette, palOffset, 0x20);
}

void BlitMenuInfoIcon(u8 windowId, u8 iconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(windowId, gFireRedMenuElements_Gfx + sMenuInfoIcons[iconId].offset * 32, 0, 0, 128, 128, x, y, sMenuInfoIcons[iconId].width, sMenuInfoIcons[iconId].height);
}

void BufferSaveMenuText(u8 textId, u8 *dest, u8 color)
{
    s32 curFlag;
    s32 flagCount;
    u8 *endOfString;
    u8 *string = dest;

    *(string++) = EXT_CTRL_CODE_BEGIN;
    *(string++) = EXT_CTRL_CODE_COLOR;
    *(string++) = color;
    *(string++) = EXT_CTRL_CODE_BEGIN;
    *(string++) = EXT_CTRL_CODE_SHADOW;
    *(string++) = color + 1;

    switch (textId)
    {
        case SAVE_MENU_NAME:
            StringCopy(string, gSaveBlock2Ptr->playerName);
            break;
        case SAVE_MENU_CAUGHT:
            if (IsNationalPokedexEnabled())
                string = ConvertIntToDecimalStringN(string, GetNationalPokedexCount(FLAG_GET_CAUGHT), STR_CONV_MODE_LEFT_ALIGN, 3);
            else
                string = ConvertIntToDecimalStringN(string, GetHoennPokedexCount(FLAG_GET_CAUGHT), STR_CONV_MODE_LEFT_ALIGN, 3);
            *string = EOS;
            break;
        case SAVE_MENU_PLAY_TIME:
            string = ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
            *(string++) = CHAR_COLON;
            ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
            break;
        case SAVE_MENU_LOCATION:
            GetMapNameGeneric(string, gMapHeader.regionMapSectionId);
            break;
        case SAVE_MENU_BADGES:
            for (curFlag = FLAG_BADGE01_GET, flagCount = 0, endOfString = string + 1; curFlag < FLAG_BADGE01_GET + NUM_BADGES; curFlag++)
            {
                if (FlagGet(curFlag))
                    flagCount++;
            }
            *string = flagCount + CHAR_0;
            *endOfString = EOS;
            break;
    }
}
