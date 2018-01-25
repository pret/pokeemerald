#include "global.h"
#include "bg.h"
#include "palette.h"
#include "window.h"
#include "text.h"
#include "new_menu_helpers.h"
#include "text_window.h"
#include "menu.h"
#include "menu_helpers.h"

#define STD_WINDOW_PALETTE_NUM 14
#define STD_WINDOW_BASE_TILE_NUM 0x214
#define DLG_WINDOW_PALETTE_NUM 15
#define DLG_WINDOW_BASE_TILE_NUM 0x200

extern EWRAM_DATA u8 gUnknown_0203CD8C;
extern EWRAM_DATA u8 gUnknown_0203CD8D;

extern const u8 gUnknown_0860EA6C[];
extern const u16 gUnknown_0860EA4C[];
extern const u16 gUnknown_0860F074[];
extern const u8 gUnknown_0860F094[];
extern const struct WindowTemplate gUnknown_0860F098[];
extern const struct WindowTemplate gUnknown_0860F0A8;

extern void sub_819645C(void);
// Forward declarations
extern void sub_81973A4(void);
extern void DrawStandardFrame(u8, u8, u8, u8, u8, u8);
extern void DrawDialogueFrame(u8, u8, u8, u8, u8, u8);
extern void sub_81977BC(u8, u8, u8, u8, u8, u8);
extern void sub_8197804(u8, u8, u8, u8, u8, u8);

void sub_8197184(u8 window, u32 destTile, u32 destPalette)
{
    LoadBgTiles(GetWindowAttribute(window, WINDOW_PRIORITY), gUnknown_0860EA6C, 0x100, destTile);
    LoadPalette(gUnknown_0860EA4C, destPalette * 16, 32);
}

void sub_81971C4(void)
{
    sub_819645C();
}

void sub_81971D0(void)
{
    InitWindows(gUnknown_0860F098);
    gUnknown_0203CD8C = 0xFF;
    gUnknown_0203CD8D = 0xFF;
}

void sub_81971F4(void)
{
    FreeAllWindowBuffers();
}

void sub_8197200(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    DeactivateAllTextPrinters();
    sub_81973A4();
}

u16 sub_8197224(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(0);
}

u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void (*callback)(struct TextSubPrinter *, u16), u8 fgColor, u8 bgColor, u8 shadowColor)
{
    struct TextSubPrinter printer;
    
    printer.current_text_offset = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = 0;
    printer.y = 1;
    printer.currentX = 0;
    printer.currentY = 1;
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.fontColor_l = 0;
    printer.fgColor = fgColor;
    printer.bgColor = bgColor;
    printer.shadowColor = shadowColor;
    
    gTextFlags.flag_1 = 0;
    return AddTextPrinter(&printer, speed, callback); 
}

void AddTextPrinterForMessage(bool8 allowSkippingDelayWithButtonPress)
{
    void (*callback)(struct TextSubPrinter *, u16) = NULL;
    gTextFlags.flag_0 = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized(0, 1, gStringVar4, GetPlayerTextSpeed(), callback, 2, 1, 3);
}

void AddTextPrinterForMessage_2(bool8 allowSkippingDelayWithButtonPress)
{
    gTextFlags.flag_0 = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized(0, 1, gStringVar4, GetPlayerTextSpeed(), NULL, 2, 1, 3);
}

void AddTextPrinterWithCustomSpeedForMessage(bool8 allowSkippingDelayWithButtonPress, u8 speed)
{
    gTextFlags.flag_0 = allowSkippingDelayWithButtonPress;
    AddTextPrinterParameterized(0, 1, gStringVar4, speed, NULL, 2, 1, 3);
}

void sub_81973A4(void)
{
    copy_textbox_border_tile_patterns_to_vram(0, DLG_WINDOW_BASE_TILE_NUM, 0xF0);
    sub_809882C(0, STD_WINDOW_BASE_TILE_NUM, 0xE0);
}

void NewMenuHelpers_DrawDialogueFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, DrawDialogueFrame);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void NewMenuHelpers_DrawStdWindowFrame(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, DrawStandardFrame);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_8197434(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, sub_8197804);
    FillWindowPixelBuffer(windowId, 0x11);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_819746C(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, sub_81977BC);
    FillWindowPixelBuffer(windowId, 0x11);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawStandardFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
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

void DrawDialogueFrame(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
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

void sub_81977BC(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, STD_WINDOW_PALETTE_NUM);
}

void sub_8197804(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, STD_WINDOW_PALETTE_NUM);
}

void SetStandardWindowBorderStyle(u8 windowId, bool8 copyToVram)
{
    SetWindowBorderStyle(windowId, copyToVram, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM);
}

void sub_819786C(u8 windowId, bool8 copyToVram)
{
    copy_textbox_border_tile_patterns_to_vram(windowId, DLG_WINDOW_BASE_TILE_NUM, 0xF0);
    sub_8197B1C(windowId, copyToVram, DLG_WINDOW_BASE_TILE_NUM, 0xF);
}

void sub_819789C(void)
{
    LoadPalette(gUnknown_0860F074, 0xE0, 0x14);
}

void sub_81978B0(u16 offset)
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
    sub_81973A4();
    DisplayMessageAndContinueTask(taskId, 0, DLG_WINDOW_BASE_TILE_NUM, DLG_WINDOW_PALETTE_NUM, 1, GetPlayerTextSpeed(), string, callback);
    CopyWindowToVram(0, 3);
}

void sub_8197930(void)
{
    CreateYesNoMenu(&gUnknown_0860F0A8, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, 0);
}

void sub_8197948(u8 initialCursorPos)
{
    CreateYesNoMenu(&gUnknown_0860F0A8, STD_WINDOW_BASE_TILE_NUM, STD_WINDOW_PALETTE_NUM, initialCursorPos);
}

u32 sub_8197964(void)
{
    if (gTextFlags.flag_3)
        return 1;
    return gSaveBlock2Ptr->optionsTextSpeed;
}

u8 GetPlayerTextSpeed(void)
{
    u32 speed;
    if (gSaveBlock2Ptr->optionsTextSpeed > 2)
        gSaveBlock2Ptr->optionsTextSpeed = 1;
    speed = sub_8197964();
    return gUnknown_0860F094[speed];
}

u8 sub_81979C4(u8 a1)
{
    if (gUnknown_0203CD8C == 0xFF)
        gUnknown_0203CD8C = sub_8198AA4(0, 0x16, 1, 7, (a1 * 2) + 2, 0xF, 0x139);
    return gUnknown_0203CD8C;
}

u8 GetStartMenuWindowId(void)
{
    return gUnknown_0203CD8C;
}

void remove_start_menu_window_maybe(void)
{
    if (gUnknown_0203CD8C != 0xFF)
    {
        RemoveWindow(gUnknown_0203CD8C);
        gUnknown_0203CD8C = 0xFF;
    }
}

u16 sub_8197A30(void)
{
    return DLG_WINDOW_BASE_TILE_NUM;
}

u16 sub_8197A38(void)
{
    return STD_WINDOW_BASE_TILE_NUM;
}

u8 AddMapNamePopUpWindow(void)
{
    if (gUnknown_0203CD8D == 0xFF)
        gUnknown_0203CD8D = sub_8198AA4(0, 1, 1, 10, 3, 14, 0x107);
    return gUnknown_0203CD8D;
}

u8 GetMapNamePopUpWindowId(void)
{
    return gUnknown_0203CD8D;
}

void RemoveMapNamePopUpWindow(void)
{
    if (gUnknown_0203CD8D != 0xFF)
    {
        RemoveWindow(gUnknown_0203CD8D);
        gUnknown_0203CD8D = 0xFF;
    }
}
