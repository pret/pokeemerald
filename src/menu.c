#include "global.h"
#include "new_menu_helpers.h"
#include "bg.h"
#include "window.h"
#include "palette.h"
#include "menu.h"
#include "constants/songs.h"
#include "main.h"
#include "sound.h"
#include "menu_helpers.h"
#include "malloc.h"
#include "task.h"
#include "dma3.h"
#include "string_util.h"
#include "pokemon_icon.h"

struct SomeUnkStruct
{
    u8 unk1;
    u8 unk2;
    u16 unk3;
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
    u8 horizontalCount;
    u8 verticalCount;
    bool8 APressMuted;
};

extern EWRAM_DATA struct Menu gUnknown_0203CD90;
extern EWRAM_DATA u16 gUnknown_0203CD9C;
extern EWRAM_DATA u8 gUnknown_0203CD9E;
extern EWRAM_DATA u8 gUnknown_0203CD9F;
extern EWRAM_DATA u8 gUnknown_0203CDA0;
extern EWRAM_DATA bool8 gUnknown_0203CDA4[4];
extern EWRAM_DATA u16 gUnknown_0203CDA8;
extern EWRAM_DATA void *gUnknown_0203CDAC[0x20];

const u16 gUnknown_0860F0B0[] = INCBIN_U16("graphics/interface/860F0B0.gbapal");
const struct TextColor gUnknown_0860F0D0[] = { 15, 1, 2 };
const struct SomeUnkStruct gUnknown_0860F0D4[] =
{
    { 12, 12, 0x00 },
    { 32, 12, 0x20 },
    { 32, 12, 0x64 },
    { 32, 12, 0x60 },
    { 32, 12, 0x80 },
    { 32, 12, 0x48 },
    { 32, 12, 0x44 },
    { 32, 12, 0x6C },
    { 32, 12, 0x68 },
    { 32, 12, 0x88 },
    { 32, 12, 0xA4 },
    { 32, 12, 0x24 },
    { 32, 12, 0x28 },
    { 32, 12, 0x2C },
    { 32, 12, 0x40 },
    { 32, 12, 0x84 },
    { 32, 12, 0x4C },
    { 32, 12, 0xA0 },
    { 32, 12, 0x8C },
    { 42, 12, 0xA8 },
    { 42, 12, 0xC0 },
    { 42, 12, 0xC8 },
    { 42, 12, 0xE0 },
    { 42, 12, 0xE8 },
    {  8,  8, 0xAE },
    {  8,  8, 0xAF },
};

extern const u8 gText_SelectorArrow3[];
extern const u8 gText_YesNo[];
extern const u16 gFireRedMenuElements1_Pal[16];
extern const u16 gFireRedMenuElements2_Pal[16];
extern const u16 gFireRedMenuElements3_Pal[16];
extern const u8 gFireRedMenuElements_Gfx[];

extern void sub_8197BB4(u8, u8, u8, u8, u8, u8);
extern void sub_8197E30(u8, u8, u8, u8, u8, u8);
extern void DrawWindowBorder(u8, u8, u8, u8, u8, u8);
extern void sub_81980A8(u8, u8, u8, u8, u8, u8);
extern u8 MoveMenuCursor(s8);
extern u8 sub_8199134(s8, s8);
extern void sub_8199F74(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 speed, void (*callback)(struct TextSubPrinter *, u16), u8 letterSpacing, u8 lineSpacing);
extern void sub_8198C78(void);
extern void task_free_buf_after_copying_tile_data_to_vram(u8 taskId);

void AddTextPrinterWithCallbackForMessage(bool8 a1, void (*callback)(struct TextSubPrinter *, u16))
{
    gTextFlags.flag_0 = a1;
    AddTextPrinterParameterized(0, 1, gStringVar4, GetPlayerTextSpeed(), callback, 2, 1, 3);
}

void sub_8197AE8(bool8 copyToVram)
{
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x11);
    if (copyToVram == TRUE)
        CopyBgTilemapBufferToVram(0);
}

void sub_8197B1C(u8 windowId, bool8 copyToVram, u16 a3, u8 a4)
{
    gUnknown_0203CD9C = a3;
    gUnknown_0203CD9E = a4;
    CallWindowFunction(windowId, sub_8197BB4);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_8197B64(u8 windowId, bool8 copyToVram, u16 a3)
{
    gUnknown_0203CD9C = a3;
    gUnknown_0203CD9E = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, sub_8197BB4);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_8197BB4(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 1,
                            tilemapLeft - 2,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 3,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 4,
                            tilemapLeft,
                            tilemapTop - 1,
                            width - 1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 5,
                            tilemapLeft + width - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 6,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 7,
                            tilemapLeft - 2,
                            tilemapTop,
                            1,
                            5,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 9,
                            tilemapLeft - 1,
                            tilemapTop,
                            width + 1,
                            5,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 10,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            5,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(gUnknown_0203CD9C + 1),
                            tilemapLeft - 2,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(gUnknown_0203CD9C + 3),
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(gUnknown_0203CD9C + 4),
                            tilemapLeft,
                            tilemapTop + height,
                            width - 1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(gUnknown_0203CD9C + 5),
                            tilemapLeft + width - 1,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            BG_TILE_V_FLIP(gUnknown_0203CD9C + 6),
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
}

void sub_8197DF8(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, sub_8197E30);
    FillWindowPixelBuffer(windowId, 0);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_8197E30(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 3, tilemapTop - 1, width + 6, height + 2, 0);
}

void SetWindowBorderStyle(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum)
{
    gUnknown_0203CD9C = baseTileNum;
    gUnknown_0203CD9E = paletteNum;
    CallWindowFunction(windowId, DrawWindowBorder);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_8197EC8(u8 windowId, bool8 copyToVram, u16 baseTileNum)
{
    gUnknown_0203CD9C = baseTileNum;
    gUnknown_0203CD9E = GetWindowAttribute(windowId, WINDOW_PALETTE_NUM);
    CallWindowFunction(windowId, DrawWindowBorder);
    FillWindowPixelBuffer(windowId, 0x11);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void DrawWindowBorder(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 0,
                            tilemapLeft - 1,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 1,
                            tilemapLeft,
                            tilemapTop - 1,
                            width,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 2,
                            tilemapLeft + width,
                            tilemapTop - 1,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 3,
                            tilemapLeft - 1,
                            tilemapTop,
                            1,
                            height,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 5,
                            tilemapLeft + width,
                            tilemapTop,
                            1,
                            height,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 6,
                            tilemapLeft - 1,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 7,
                            tilemapLeft,
                            tilemapTop + height,
                            width,
                            1,
                            gUnknown_0203CD9E);
    FillBgTilemapBufferRect(bg,
                            gUnknown_0203CD9C + 8,
                            tilemapLeft + width,
                            tilemapTop + height,
                            1,
                            1,
                            gUnknown_0203CD9E);
}

void sub_8198070(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, sub_81980A8);
    FillWindowPixelBuffer(windowId, 0);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, 3);
}

void sub_81980A8(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(bg, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0);
}

u8 sub_81980F0(u8 bg, u8 xPos, u8 yPos, u8 palette, u16 baseTile)
{
    struct WindowTemplate window;
    memset(&window, 0, sizeof(window));

    if (bg > 3)
        window.priority = 0;
    else
        window.priority = bg;

    window.tilemapTop = yPos;
    window.height = 2;
    window.tilemapLeft = 0x1E - xPos;
    window.width = xPos;
    window.paletteNum = palette;
    window.baseBlock = baseTile;

    gUnknown_0203CDA0 = AddWindow(&window);

    if (palette > 15)
        palette = 15 * 16;
    else
        palette *= 16;

    LoadPalette(gUnknown_0860F0B0, palette, sizeof(gUnknown_0860F0B0));
    return gUnknown_0203CDA0;
}

void sub_8198180(const u8 *string, u8 a2, bool8 copyToVram)
{
    u16 width = 0;

    if (gUnknown_0203CDA0 != 0xFF)
    {
        PutWindowTilemap(gUnknown_0203CDA0);
        FillWindowPixelBuffer(gUnknown_0203CDA0, 0xFF);
        width = GetStringWidth(0, string, 0);
        box_print(gUnknown_0203CDA0,
                  0,
                  0xEC - (GetWindowAttribute(gUnknown_0203CDA0, WINDOW_TILEMAP_LEFT) * 8) - a2 - width,
                  1,
                  gUnknown_0860F0D0,
                  0,
                  string);
        if (copyToVram)
            CopyWindowToVram(gUnknown_0203CDA0, 3);
    }
}

void sub_8198204(const u8 *string, const u8 *string2, u8 a3, u8 a4, bool8 copyToVram)
{
    struct TextColor color;
    u16 width = 0;

    if (gUnknown_0203CDA0 != 0xFF)
    {
        if (a3 != 0)
        {
            color.fgColor = 0;
            color.bgColor = 1;
            color.shadowColor = 2;
        }
        else
        {
            color.fgColor = 15;
            color.bgColor = 1;
            color.shadowColor = 2;
        }
        PutWindowTilemap(gUnknown_0203CDA0);
        FillWindowPixelBuffer(gUnknown_0203CDA0, 0xFF);
        if (string2 != NULL)
        {
            width = GetStringWidth(0, string2, 0);
            box_print(gUnknown_0203CDA0,
                      0,
                      0xEC - (GetWindowAttribute(gUnknown_0203CDA0, WINDOW_TILEMAP_LEFT) * 8) - a4 - width,
                      1,
                      &color,
                      0,
                      string2);
        }
        AddTextPrinterParameterized2(gUnknown_0203CDA0, 1, 4, 1, 0, 0, &color, 0, string);
        if (copyToVram)
            CopyWindowToVram(gUnknown_0203CDA0, 3);
    }
}

void sub_81982D8(void)
{
    if (gUnknown_0203CDA0 != 0xFF)
        CopyWindowToVram(gUnknown_0203CDA0, 3);
}

void sub_81982F0(void)
{
    if (gUnknown_0203CDA0 != 0xFF)
    {
        FillWindowPixelBuffer(gUnknown_0203CDA0, 0xFF);
        CopyWindowToVram(gUnknown_0203CDA0, 3);
    }
}

void sub_8198314(void)
{
    if (gUnknown_0203CDA0 != 0xFF)
    {
        FillWindowPixelBuffer(gUnknown_0203CDA0, 0);
        ClearWindowTilemap(gUnknown_0203CDA0);
        CopyWindowToVram(gUnknown_0203CDA0, 3);
        RemoveWindow(gUnknown_0203CDA0);
        gUnknown_0203CDA0 = 0xFF;
    }
}

u8 sub_8198348(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos, u8 a7)
{
    s32 pos;

    gUnknown_0203CD90.left = left;
    gUnknown_0203CD90.top = top;
    gUnknown_0203CD90.minCursorPos = 0;
    gUnknown_0203CD90.maxCursorPos = numChoices - 1;
    gUnknown_0203CD90.windowId = windowId;
    gUnknown_0203CD90.fontId = fontId;
    gUnknown_0203CD90.optionHeight = cursorHeight;
    gUnknown_0203CD90.APressMuted = a7;

    pos = initialCursorPos;

    if (pos < 0 || pos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = 0;
    else
        gUnknown_0203CD90.cursorPos = pos;

    MoveMenuCursor(0);
    return gUnknown_0203CD90.cursorPos;
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

    width = GetMenuCursorDimensionByFont(gUnknown_0203CD90.fontId, 0);
    height = GetMenuCursorDimensionByFont(gUnknown_0203CD90.fontId, 1);
    FillWindowPixelRect(gUnknown_0203CD90.windowId, 0x11, gUnknown_0203CD90.left, gUnknown_0203CD90.optionHeight * oldPos + gUnknown_0203CD90.top, width, height);
    PrintTextOnWindow(gUnknown_0203CD90.windowId, gUnknown_0203CD90.fontId, gText_SelectorArrow3, gUnknown_0203CD90.left, gUnknown_0203CD90.optionHeight * newPos + gUnknown_0203CD90.top, 0, 0);
}

u8 MoveMenuCursor(s8 cursorDelta)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;
    int newPos = gUnknown_0203CD90.cursorPos + cursorDelta;

    if (newPos < gUnknown_0203CD90.minCursorPos)
        gUnknown_0203CD90.cursorPos = gUnknown_0203CD90.maxCursorPos;
    else if (newPos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = gUnknown_0203CD90.minCursorPos;
    else
        gUnknown_0203CD90.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, gUnknown_0203CD90.cursorPos);
    return gUnknown_0203CD90.cursorPos;
}

u8 MoveMenuCursorNoWrapAround(s8 cursorDelta)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;
    int newPos = gUnknown_0203CD90.cursorPos + cursorDelta;

    if (newPos < gUnknown_0203CD90.minCursorPos)
        gUnknown_0203CD90.cursorPos = gUnknown_0203CD90.minCursorPos;
    else if (newPos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = gUnknown_0203CD90.maxCursorPos;
    else
        gUnknown_0203CD90.cursorPos += cursorDelta;

    RedrawMenuCursor(oldPos, gUnknown_0203CD90.cursorPos);
    return gUnknown_0203CD90.cursorPos;
}

u8 GetMenuCursorPos(void)
{
    return gUnknown_0203CD90.cursorPos;
}

s8 ProcessMenuInput(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (!gUnknown_0203CD90.APressMuted)
            PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(-1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(1);
        return -2;
    }

    return -2;
}

s8 ProcessMenuInputNoWrapAround(void)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        if (!gUnknown_0203CD90.APressMuted)
            PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (oldPos != MoveMenuCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (oldPos != MoveMenuCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return -2;
    }

    return -2;
}

s8 ProcessMenuInput_other(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (!gUnknown_0203CD90.APressMuted)
            PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(-1);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        MoveMenuCursor(1);
        return -2;
    }

    return -2;
}

s8 ProcessMenuInputNoWrapAround_other(void)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        if (!gUnknown_0203CD90.APressMuted)
            PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        if (oldPos != MoveMenuCursorNoWrapAround(-1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        if (oldPos != MoveMenuCursorNoWrapAround(1))
            PlaySE(SE_SELECT);
        return -2;
    }

    return -2;
}

void PrintTextArray(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        PrintTextOnWindow(windowId, fontId, strs[i].text, left, (lineHeight * i) + top, 0xFF, NULL);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_81987BC(u8 windowId, u8 fontId, u8 left, u8 top, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, u8 a6, u8 a7)
{
    u8 i;
    for (i = 0; i < itemCount; i++)
    {
        sub_8199F74(windowId, fontId, strs[i].text, left, (lineHeight * i) + top, 0xFF, NULL, a6, a7);
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198854(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *strs)
{
    PrintTextArray(windowId, fontId, GetFontAttribute(fontId, 0), 1, lineHeight, itemCount, strs);
}

void AddItemMenuActionTextPrinters(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    struct TextSubPrinter printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);
    printer.fontColor_l = GetFontAttribute(fontId, 4);
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = GetFontAttribute(fontId, 3);
    printer.x = left;
    printer.currentX = left;

    for (i = 0; i < itemCount; i++)
    {
        printer.current_text_offset = strs[a8[i]].text;
        printer.y = (lineHeight * i) + top;
        printer.currentY = printer.y;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81989B8(u8 windowId, u8 fontId, u8 lineHeight, u8 itemCount, const struct MenuAction *strs, const u8 *a5)
{
    AddItemMenuActionTextPrinters(windowId, fontId, GetFontAttribute(fontId, 0), 1, GetFontAttribute(fontId, 2), lineHeight, itemCount, strs, a5);
}

void SetWindowTemplateFields(struct WindowTemplate *template, u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
{
    template->priority = bg;
    template->tilemapLeft = left;
    template->tilemapTop = top;
    template->width = width;
    template->height = height;
    template->paletteNum = paletteNum;
    template->baseBlock = baseBlock;
}

struct WindowTemplate sub_8198A50(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock)
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
    struct TextSubPrinter printer;

    gUnknown_0203CD9F = AddWindow(window);
    SetWindowBorderStyle(gUnknown_0203CD9F, TRUE, baseTileNum, paletteNum);

    printer.current_text_offset = gText_YesNo;
    printer.windowId = gUnknown_0203CD9F;
    printer.fontId = fontId;
    printer.x = GetFontAttribute(fontId, 0) + left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);
    printer.fontColor_l = GetFontAttribute(fontId, 4);
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);

    AddTextPrinter(&printer, 0xFF, NULL);

    sub_81983AC(gUnknown_0203CD9F, fontId, left, top, GetFontAttribute(fontId, 1), 2, initialCursorPos);
}

void sub_8198C34(const struct WindowTemplate *window, u8 fontId, u16 baseTileNum, u8 paletteNum)
{
    sub_8198AF8(window, fontId, 0, 1, baseTileNum, paletteNum, 0);
}

s8 ProcessMenuInputNoWrap_(void)
{
    s8 result = ProcessMenuInputNoWrapAround();
    if (result != -2)
        sub_8198C78();
    return result;
}

void sub_8198C78(void)
{
    sub_8198070(gUnknown_0203CD9F, TRUE);
    RemoveWindow(gUnknown_0203CD9F);
}

void sub_8198C94(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7, const struct MenuAction *strs)
{
    u8 i;
    u8 j;
    for (i = 0; i < a7; i++)
    {
        for (j = 0; j < a6; j++)
        {
            PrintTextOnWindow(windowId, fontId, strs[(i * a6) + j].text, (a4 * j) + left, (a5 * i) + top, 0xFF, NULL);
        }
    }
    CopyWindowToVram(windowId, 2);
}

void sub_8198D54(u8 windowId, u8 fontId, u8 a2, u8 a3, u8 a4, u8 a5, const struct MenuAction *strs)
{
    sub_8198C94(windowId, fontId, GetFontAttribute(fontId, 0), 0, a2, a3, a4, a5, strs);
}

void sub_8198DBC(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 itemCount, u8 itemCount2, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    u8 j;
    struct TextSubPrinter printer;

    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);
    printer.fontColor_l = GetFontAttribute(fontId, 4);
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);

    for (i = 0; i < itemCount2; i++)
    {
        for (j = 0; j < itemCount; j++)
        {
            printer.current_text_offset = strs[a8[(itemCount * i) + j]].text;
            printer.x = (a4 * j) + left;
            printer.y = (GetFontAttribute(fontId, 1) * i) + top;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

void sub_8198EF8(u8 windowId, u8 fontId, u8 a2, u8 a3, u8 a4, u8 a5, const struct MenuAction *strs, const u8 *a8)
{
    sub_8198DBC(windowId, fontId, GetFontAttribute(fontId, 0), 0, a2, a4, a5, strs, a8);
}

u8 sub_8198F58(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 cursorHeight, u8 a6, u8 a7, u8 numChoices, u8 a9)
{
    s32 pos;

    gUnknown_0203CD90.left = left;
    gUnknown_0203CD90.top = top;
    gUnknown_0203CD90.minCursorPos = 0;
    gUnknown_0203CD90.maxCursorPos = numChoices - 1;
    gUnknown_0203CD90.windowId = windowId;
    gUnknown_0203CD90.fontId = fontId;
    gUnknown_0203CD90.optionWidth = a4;
    gUnknown_0203CD90.optionHeight = cursorHeight;
    gUnknown_0203CD90.horizontalCount = a6;
    gUnknown_0203CD90.verticalCount = a7;

    pos = a9;

    if (pos < 0 || pos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = 0;
    else
        gUnknown_0203CD90.cursorPos = pos;

    sub_8199134(0, 0);
    return gUnknown_0203CD90.cursorPos;
}

u8 sub_8198FD4(u8 windowId, u8 fontId, u8 left, u8 top, u8 a4, u8 a5, u8 a6, u8 a7)
{
    u8 cursorHeight = GetMenuCursorDimensionByFont(fontId, 1);
    u8 numChoices = a5 * a6;
    return sub_8198F58(windowId, fontId, left, top, a4, cursorHeight, a5, a6, numChoices, a7);
}

void sub_8199060(u8 oldCursorPos, u8 newCursorPos)
{
    u8 cursorWidth = GetMenuCursorDimensionByFont(gUnknown_0203CD90.fontId, 0);
    u8 cursorHeight = GetMenuCursorDimensionByFont(gUnknown_0203CD90.fontId, 1);
    u8 xPos = (oldCursorPos % gUnknown_0203CD90.horizontalCount) * gUnknown_0203CD90.optionWidth + gUnknown_0203CD90.left;
    u8 yPos = (oldCursorPos / gUnknown_0203CD90.horizontalCount) * gUnknown_0203CD90.optionHeight + gUnknown_0203CD90.top;
    FillWindowPixelRect(gUnknown_0203CD90.windowId,
                        0x11,
                        xPos,
                        yPos,
                        cursorWidth,
                        cursorHeight);
    xPos = (newCursorPos % gUnknown_0203CD90.horizontalCount) * gUnknown_0203CD90.optionWidth + gUnknown_0203CD90.left;
    yPos = (newCursorPos / gUnknown_0203CD90.horizontalCount) * gUnknown_0203CD90.optionHeight + gUnknown_0203CD90.top;
    PrintTextOnWindow(gUnknown_0203CD90.windowId,
                      gUnknown_0203CD90.fontId,
                      gText_SelectorArrow3,
                      xPos,
                      yPos,
                      0,
                      0);
}

u8 sub_8199134(s8 deltaX, s8 deltaY)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (deltaX != 0)
    {
        if ((gUnknown_0203CD90.cursorPos % gUnknown_0203CD90.horizontalCount) + deltaX < 0)
        {
            gUnknown_0203CD90.cursorPos += gUnknown_0203CD90.horizontalCount - 1;
        }
        else if ((gUnknown_0203CD90.cursorPos % gUnknown_0203CD90.horizontalCount) + deltaX >= gUnknown_0203CD90.horizontalCount)
        {
            gUnknown_0203CD90.cursorPos = (gUnknown_0203CD90.cursorPos / gUnknown_0203CD90.horizontalCount) * gUnknown_0203CD90.horizontalCount;
        }
        else
        {
            gUnknown_0203CD90.cursorPos += deltaX;
        }
    }

    if (deltaY != 0)
    {
        if ((gUnknown_0203CD90.cursorPos / gUnknown_0203CD90.horizontalCount) + deltaY < 0)
        {
            gUnknown_0203CD90.cursorPos += gUnknown_0203CD90.horizontalCount * (gUnknown_0203CD90.verticalCount - 1);
        }
        else if ((gUnknown_0203CD90.cursorPos / gUnknown_0203CD90.horizontalCount) + deltaY >= gUnknown_0203CD90.verticalCount)
        {
            gUnknown_0203CD90.cursorPos -= gUnknown_0203CD90.horizontalCount * (gUnknown_0203CD90.verticalCount - 1);
        }
        else
        {
            gUnknown_0203CD90.cursorPos += (gUnknown_0203CD90.horizontalCount * deltaY);
        }
    }

    if (gUnknown_0203CD90.cursorPos > gUnknown_0203CD90.maxCursorPos)
    {
        gUnknown_0203CD90.cursorPos = oldPos;
        return gUnknown_0203CD90.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, gUnknown_0203CD90.cursorPos);
        return gUnknown_0203CD90.cursorPos;
    }
}

u8 sub_81991F8(s8 deltaX, s8 deltaY)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (deltaX != 0)
    {
        if (((gUnknown_0203CD90.cursorPos % gUnknown_0203CD90.horizontalCount) + deltaX >= 0) &&
        ((gUnknown_0203CD90.cursorPos % gUnknown_0203CD90.horizontalCount) + deltaX < gUnknown_0203CD90.horizontalCount))
        {
            gUnknown_0203CD90.cursorPos += deltaX;
        }
    }

    if (deltaY != 0)
    {
        if (((gUnknown_0203CD90.cursorPos / gUnknown_0203CD90.horizontalCount) + deltaY >= 0) &&
        ((gUnknown_0203CD90.cursorPos / gUnknown_0203CD90.horizontalCount) + deltaY < gUnknown_0203CD90.verticalCount))
        {
            gUnknown_0203CD90.cursorPos += (gUnknown_0203CD90.horizontalCount * deltaY);
        }
    }

    if (gUnknown_0203CD90.cursorPos > gUnknown_0203CD90.maxCursorPos)
    {
        gUnknown_0203CD90.cursorPos = oldPos;
        return gUnknown_0203CD90.cursorPos;
    }
    else
    {
        sub_8199060(oldPos, gUnknown_0203CD90.cursorPos);
        return gUnknown_0203CD90.cursorPos;
    }
}

s8 sub_8199284(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, -1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, 1);
        return -2;
    }
    else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
    {
        PlaySE(SE_SELECT);
        sub_8199134(-1, 0);
        return -2;
    }
    else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
    {
        PlaySE(SE_SELECT);
        sub_8199134(1, 0);
        return -2;
    }

    return -2;
}

s8 sub_8199334(void)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (oldPos != sub_81991F8(0, -1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (oldPos != sub_81991F8(0, 1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
    {
        if (oldPos != sub_81991F8(-1, 0))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
    {
        if (oldPos != sub_81991F8(1, 0))
            PlaySE(SE_SELECT);
        return -2;
    }

    return -2;
}

s8 sub_81993D8(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, -1);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        sub_8199134(0, 1);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_LEFT || sub_812210C() == 1)
    {
        PlaySE(SE_SELECT);
        sub_8199134(-1, 0);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_RIGHT || sub_812210C() == 2)
    {
        PlaySE(SE_SELECT);
        sub_8199134(1, 0);
        return -2;
    }

    return -2;
}

s8 sub_8199484(void)
{
    u8 oldPos = gUnknown_0203CD90.cursorPos;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_0203CD90.cursorPos;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_UP)
    {
        if (oldPos != sub_81991F8(0, -1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_DOWN)
    {
        if (oldPos != sub_81991F8(0, 1))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_LEFT || sub_812210C() == 1)
    {
        if (oldPos != sub_81991F8(-1, 0))
            PlaySE(SE_SELECT);
        return -2;
    }
    else if ((gMain.newAndRepeatedKeys & DPAD_ANY) == DPAD_RIGHT || sub_812210C() == 2)
    {
        if (oldPos != sub_81991F8(1, 0))
            PlaySE(SE_SELECT);
        return -2;
    }

    return -2;
}

u8 InitMenuInUpperLeftCorner(u8 windowId, u8 itemCount, u8 initialCursorPos, bool8 APressMuted)
{
    s32 pos;

    gUnknown_0203CD90.left = 0;
    gUnknown_0203CD90.top = 1;
    gUnknown_0203CD90.minCursorPos = 0;
    gUnknown_0203CD90.maxCursorPos = itemCount - 1;
    gUnknown_0203CD90.windowId = windowId;
    gUnknown_0203CD90.fontId = 1;
    gUnknown_0203CD90.optionHeight = 16;
    gUnknown_0203CD90.APressMuted = APressMuted;

    pos = initialCursorPos;

    if (pos < 0 || pos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = 0;
    else
        gUnknown_0203CD90.cursorPos = pos;

    return MoveMenuCursor(0);
}

u8 InitMenuInUpperLeftCornerPlaySoundWhenAPressed(u8 windowId, u8 itemCount, u8 initialCursorPos)
{
    return InitMenuInUpperLeftCorner(windowId, itemCount, initialCursorPos, FALSE);
}

void PrintMenuTable(u8 windowId, u8 itemCount, const struct MenuAction *strs)
{
    u32 i;

    for (i = 0; i < itemCount; i++)
    {
        PrintTextOnWindow(windowId, 1, strs[i].text, 8, (i * 16) + 1, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void sub_81995E4(u8 windowId, u8 itemCount, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    struct TextSubPrinter printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, 5);
    printer.bgColor = GetFontAttribute(1, 6);
    printer.shadowColor = GetFontAttribute(1, 7);
    printer.fontColor_l = GetFontAttribute(1, 4);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;
    printer.x = 8;
    printer.currentX = 8;

    for (i = 0; i < itemCount; i++)
    {
        printer.current_text_offset = strs[a8[i]].text;
        printer.y = (i * 16) + 1;
        printer.currentY = (i * 16) + 1;
        AddTextPrinter(&printer, 0xFF, NULL);
    }

    CopyWindowToVram(windowId, 2);
}

void CreateYesNoMenu(const struct WindowTemplate *window, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextSubPrinter printer;

    gUnknown_0203CD9F = AddWindow(window);
    SetWindowBorderStyle(gUnknown_0203CD9F, TRUE, baseTileNum, paletteNum);

    printer.current_text_offset = gText_YesNo;
    printer.windowId = gUnknown_0203CD9F;
    printer.fontId = 1;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.fgColor = GetFontAttribute(1, 5);
    printer.bgColor = GetFontAttribute(1, 6);
    printer.shadowColor = GetFontAttribute(1, 7);
    printer.fontColor_l = GetFontAttribute(1, 4);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    AddTextPrinter(&printer, 0xFF, NULL);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gUnknown_0203CD9F, 2, initialCursorPos);
}

void sub_81997AC(u8 windowId, u8 a4, u8 a6, u8 a7, const struct MenuAction *strs)
{
    u32 i;
    u32 j;
    for (i = 0; i < a7; i++)
    {
        for (j = 0; j < a6; j++)
        {
            PrintTextOnWindow(windowId, 1, strs[(i * a6) + j].text, (a4 * j) + 8, (i * 16) + 1, 0xFF, NULL);
        }
    }
    CopyWindowToVram(windowId, 2);
}

void sub_819983C(u8 windowId, u8 a4, u8 itemCount, u8 itemCount2, const struct MenuAction *strs, const u8 *a8)
{
    u8 i;
    u8 j;
    struct TextSubPrinter printer;

    printer.windowId = windowId;
    printer.fontId = 1;
    printer.fgColor = GetFontAttribute(1, 5);
    printer.bgColor = GetFontAttribute(1, 6);
    printer.shadowColor = GetFontAttribute(1, 7);
    printer.fontColor_l = GetFontAttribute(1, 4);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    for (i = 0; i < itemCount2; i++)
    {
        for (j = 0; j < itemCount; j++)
        {
            printer.current_text_offset = strs[a8[(itemCount * i) + j]].text;
            printer.x = (a4 * j) + 8;
            printer.y = (16 * i) + 1;
            printer.currentX = printer.x;
            printer.currentY = printer.y;
            AddTextPrinter(&printer, 0xFF, NULL);
        }
    }

    CopyWindowToVram(windowId, 2);
}

u8 sub_8199944(u8 windowId, u8 optionWidth, u8 horizontalCount, u8 verticalCount, u8 initialCursorPos)
{
    s32 pos;

    gUnknown_0203CD90.left = 0;
    gUnknown_0203CD90.top = 1;
    gUnknown_0203CD90.minCursorPos = 0;
    gUnknown_0203CD90.maxCursorPos = (horizontalCount * verticalCount) - 1;
    gUnknown_0203CD90.windowId = windowId;
    gUnknown_0203CD90.fontId = 1;
    gUnknown_0203CD90.optionWidth = optionWidth;
    gUnknown_0203CD90.optionHeight = 16;
    gUnknown_0203CD90.horizontalCount = horizontalCount;
    gUnknown_0203CD90.verticalCount = verticalCount;

    pos = initialCursorPos;

    if (pos < 0 || pos > gUnknown_0203CD90.maxCursorPos)
        gUnknown_0203CD90.cursorPos = 0;
    else
        gUnknown_0203CD90.cursorPos = pos;

    sub_8199134(0, 0);
    return gUnknown_0203CD90.cursorPos;
}

void clear_scheduled_bg_copies_to_vram(void)
{
    memset(gUnknown_0203CDA4, 0, sizeof(gUnknown_0203CDA4));
}

void schedule_bg_copy_tilemap_to_vram(u8 bgId)
{
    gUnknown_0203CDA4[bgId] = TRUE;
}

void do_scheduled_bg_tilemap_copies_to_vram(void)
{
    if (gUnknown_0203CDA4[0] == TRUE)
    {
        CopyBgTilemapBufferToVram(0);
        gUnknown_0203CDA4[0] = FALSE;
    }
    if (gUnknown_0203CDA4[1] == TRUE)
    {
        CopyBgTilemapBufferToVram(1);
        gUnknown_0203CDA4[1] = FALSE;
    }
    if (gUnknown_0203CDA4[2] == TRUE)
    {
        CopyBgTilemapBufferToVram(2);
        gUnknown_0203CDA4[2] = FALSE;
    }
    if (gUnknown_0203CDA4[3] == TRUE)
    {
        CopyBgTilemapBufferToVram(3);
        gUnknown_0203CDA4[3] = FALSE;
    }
}

void reset_temp_tile_data_buffers(void)
{
    int i;
    for (i = 0; i < (s32)ARRAY_COUNT(gUnknown_0203CDAC); i++)
    {
        gUnknown_0203CDAC[i] = NULL;
    }
    gUnknown_0203CDA8 = 0;
}

bool8 free_temp_tile_data_buffers_if_possible(void)
{
    int i;

    if (!IsDma3ManagerBusyWithBgCopy())
    {
        if (gUnknown_0203CDA8)
        {
            for (i = 0; i < gUnknown_0203CDA8; i++)
            {
                FREE_AND_SET_NULL(gUnknown_0203CDAC[i]);
            }
            gUnknown_0203CDA8 = 0;
        }
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void *decompress_and_copy_tile_data_to_vram(u8 bgId, const void *src, int size, u16 offset, u8 mode)
{
    int sizeOut;
    if (gUnknown_0203CDA8 < ARRAY_COUNT(gUnknown_0203CDAC))
    {
        void *ptr = malloc_and_decompress(src, &sizeOut);
        if (!size)
            size = sizeOut;
        if (ptr)
        {
            copy_decompressed_tile_data_to_vram(bgId, ptr, size, offset, mode);
            gUnknown_0203CDAC[gUnknown_0203CDA8++] = ptr;
        }
        return ptr;
    }
    return NULL;
}

void copy_decompressed_tile_data_to_vram_autofree(u8 bgId, const void *src, int size, u16 offset, u8 mode)
{
    int sizeOut;
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

void *malloc_and_decompress(const void *src, int *size)
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

void sub_8199C30(u8 bgId, u8 left, u8 top, u8 width, u8 height, u8 palette)
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

void sub_8199CBC(u8 bgId, u16 *dest, u8 left, u8 top, u8 width, u8 height)
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

void sub_8199D98(void)
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
    int temp = (!GetBgAttribute(bg, 4)) ? 0x20 : 0x40;
    void *addr = (void *)((GetBgAttribute(bg, 1) * 0x4000) + (GetBgAttribute(bg, 10) + a2) * temp);
    RequestDma3Fill(a1 << 24 | a1 << 16 | a1 << 8 | a1, addr + VRAM, a3 * temp, 1);
}

void box_print(u8 windowId, u8 fontId, u8 left, u8 top, const struct TextColor *color, s8 speed, const u8 *str)
{
    struct TextSubPrinter printer;

    printer.current_text_offset = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);
    printer.fontColor_l = 0;
    printer.fgColor = color->bgColor;
    printer.bgColor = color->fgColor;
    printer.shadowColor = color->shadowColor;

    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized2(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const struct TextColor *color, s8 speed, const u8 *str)
{
    struct TextSubPrinter printer;

    printer.current_text_offset = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.fontColor_l = 0;
    printer.fgColor = color->bgColor;
    printer.bgColor = color->fgColor;
    printer.shadowColor = color->shadowColor;

    AddTextPrinter(&printer, speed, NULL);
}

void sub_8199F74(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 speed, void (*callback)(struct TextSubPrinter *, u16), u8 letterSpacing, u8 lineSpacing)
{
    struct TextSubPrinter printer;

    printer.current_text_offset = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = left;
    printer.y = top;
    printer.currentX = left;
    printer.currentY = top;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.fontColor_l = 0;

    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);

    AddTextPrinter(&printer, speed, callback);
}

void sub_819A024(u8 windowId, const u8 *src, u16 a2, u16 a3)
{
    int count = 0;
    while (gSaveBlock2Ptr->playerName[count] != EOS)
        count++;

    StringExpandPlaceholders(gStringVar4, src);

    PrintTextOnWindow(windowId, 1, gStringVar4, a2, a3, 0xFF, 0);
}

//Screw this function, it's long and unreferenced and ugh

struct UnkStruct_819A080 {
    u8 *unk00;
    u16 unk04;
    u16 unk06;
};

#ifdef NONMATCHING
void sub_819A080(struct UnkStruct_819A080 *a0, struct UnkStruct_819A080 *a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7)
{
    // r3 = a3
    // r4 = a5
    // r1 = a6
    // r5 = a7
    // sp+00 = a0
    // sp+04 = a1
    // sp+08 = a2
    // sp+0c = a4
    int sp10 = a1->unk04 - a4 > a6 ? a6 + a2 : a1->unk04 - a4;
    int sp14 = a0->unk06 - a5 < a7 ? a3 + a0->unk06 - a5 : a3 + a7;
    int sp18 = (a0->unk04 + (a0->unk04 & 0x7)) / 8;
    int sp1c = (a1->unk04 + (a1->unk04 & 0x7)) / 8;
    int r12; // sp+20
    int r8;  // sp+24
    int r5;
    int r6;
    u16 r2;

    for (r12 = a3, r8 = a5; r12 < sp14; r12++, r8++)
    {
        for (r5 = a2, r6 = a4; a5 < sp10; a5++, a6++)
        {
            u8 *r3 = a0->unk00 + ((r5 >> 1) & 0x3) + ((r5 >> 3) << 5) + (((r12 >> 3) * sp18) << 5) + ((r12 & 0x7) << 2);
            u8 *r4 = a1->unk00 + ((r6 >> 1) & 0x3) + ((r6 >> 3) << 5) + (((r8 >> 3) * sp1c) << 5) + ((r8 & 0x7) << 2);
            if (((uintptr_t)r4) & 0x1)
            {
                u16 *r4_2 = (u16 *)(r4 - 1);
                if (r6 & 0x1)
                {
                    r2 = *r4_2 & 0x0fff;
                    if (r5 & 0x1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 8);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 12);
                }
                else
                {
                    r2 = *r4_2 * 0xf0ff;
                    if (r5 & 0x1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 4);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 8);
                }
            }
            else
            {
                u16 *r4_2 = (u16 *)r4;
                if (r6 & 1)
                {
                    r2 = *r4_2 & 0xff0f;
                    if (r5 & 1)
                        *r4_2 = r2 | ((*r3 & 0xf0) << 0);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) << 4);
                }
                else
                {
                    r2 = *r4_2 & 0xfff0;
                    if (r5 & 1)
                        *r4_2 = r2 | ((*r3 & 0xf0) >> 4);
                    else
                        *r4_2 = r2 | ((*r3 & 0x0f) >> 0);
                }
            }
        }
    }
}
#else
__attribute__((naked))
void sub_819A080(truct UnkStruct_819A080 *a0, struct UnkStruct_819A080 *a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6, u16 a7)
{
	asm("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, #0x28\n\
	str r0, [sp]\n\
	str r1, [sp, #0x4]\n\
	ldr r0, [sp, #0x48]\n\
	ldr r4, [sp, #0x4C]\n\
	ldr r1, [sp, #0x50]\n\
	ldr r5, [sp, #0x54]\n\
	lsl r2, #16\n\
	lsr r2, #16\n\
	str r2, [sp, #0x8]\n\
	lsl r3, #16\n\
	lsr r3, #16\n\
	lsl r0, #16\n\
	lsr r0, #16\n\
	str r0, [sp, #0xC]\n\
	lsl r4, #16\n\
	lsr r4, #16\n\
	lsl r1, #16\n\
	lsr r1, #16\n\
	lsl r5, #16\n\
	lsr r5, #16\n\
	ldr r2, [sp, #0x4]\n\
	ldrh r0, [r2, #0x4]\n\
	ldr r2, [sp, #0xC]\n\
	sub r0, r2\n\
	ldr r2, [sp, #0x8]\n\
	add r2, r1, r2\n\
	str r2, [sp, #0x10]\n\
	cmp r0, r1\n\
	bge _0819A0CC\n\
	ldr r1, [sp, #0x8]\n\
	add r0, r1\n\
	str r0, [sp, #0x10]\n\
_0819A0CC:\n\
	ldr r2, [sp, #0x4]\n\
	ldrh r1, [r2, #0x6]\n\
	sub r0, r1, r4\n\
	cmp r0, r5\n\
	bge _0819A0DE\n\
	add r0, r3, r1\n\
	sub r0, r4\n\
	str r0, [sp, #0x14]\n\
	b _0819A0E2\n\
_0819A0DE:\n\
	add r5, r3, r5\n\
	str r5, [sp, #0x14]\n\
_0819A0E2:\n\
	ldr r0, [sp]\n\
	ldrh r1, [r0, #0x4]\n\
	mov r2, #0x7\n\
	add r0, r1, #0\n\
	and r0, r2\n\
	add r1, r0\n\
	asr r1, #3\n\
	str r1, [sp, #0x18]\n\
	ldr r0, [sp, #0x4]\n\
	ldrh r1, [r0, #0x4]\n\
	add r0, r1, #0\n\
	and r0, r2\n\
	add r1, r0\n\
	asr r1, #3\n\
	str r1, [sp, #0x1C]\n\
	mov r12, r3\n\
	mov r8, r4\n\
	ldr r1, [sp, #0x14]\n\
	cmp r12, r1\n\
	blt _0819A10C\n\
	b _0819A24A\n\
_0819A10C:\n\
	ldr r5, [sp, #0x8]\n\
	ldr r6, [sp, #0xC]\n\
	mov r2, r12\n\
	add r2, #0x1\n\
	str r2, [sp, #0x20]\n\
	mov r0, r8\n\
	add r0, #0x1\n\
	str r0, [sp, #0x24]\n\
	ldr r1, [sp, #0x10]\n\
	cmp r5, r1\n\
	blt _0819A124\n\
	b _0819A23A\n\
_0819A124:\n\
	mov r7, #0x1\n\
	mov r2, #0xF0\n\
	mov r10, r2\n\
	mov r0, #0xF\n\
	mov r9, r0\n\
_0819A12E:\n\
	asr r0, r5, #1\n\
	mov r1, #0x3\n\
	and r0, r1\n\
	ldr r2, [sp]\n\
	ldr r1, [r2]\n\
	add r1, r0\n\
	asr r0, r5, #3\n\
	lsl r0, #5\n\
	add r1, r0\n\
	mov r2, r12\n\
	asr r0, r2, #3\n\
	ldr r2, [sp, #0x18]\n\
	mul r0, r2\n\
	lsl r0, #5\n\
	add r1, r0\n\
	mov r2, r12\n\
	lsl r0, r2, #29\n\
	lsr r0, #27\n\
	add r3, r1, r0\n\
	asr r0, r6, #1\n\
	mov r1, #0x3\n\
	and r0, r1\n\
	ldr r2, [sp, #0x4]\n\
	ldr r1, [r2]\n\
	add r1, r0\n\
	asr r0, r6, #3\n\
	lsl r0, #5\n\
	add r1, r0\n\
	mov r2, r8\n\
	asr r0, r2, #3\n\
	ldr r2, [sp, #0x1C]\n\
	mul r0, r2\n\
	lsl r0, #5\n\
	add r1, r0\n\
	mov r2, r8\n\
	lsl r0, r2, #29\n\
	lsr r0, #27\n\
	add r4, r1, r0\n\
	add r0, r4, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A1DA\n\
	sub r4, #0x1\n\
	add r0, r6, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A1B2\n\
	ldrh r0, [r4]\n\
	ldr r2, =0x00000fff\n\
	and r2, r0\n\
	add r0, r5, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A1A8\n\
	ldrb r1, [r3]\n\
	mov r0, r10\n\
	and r0, r1\n\
	lsl r0, #8\n\
	b _0819A22A\n\
	.pool\n\
_0819A1A8:\n\
	ldrb r1, [r3]\n\
	mov r0, r9\n\
	and r0, r1\n\
	lsl r0, #12\n\
	b _0819A22A\n\
_0819A1B2:\n\
	ldrh r0, [r4]\n\
	ldr r2, =0x0000f0ff\n\
	and r2, r0\n\
	add r0, r5, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A1D0\n\
	ldrb r1, [r3]\n\
	mov r0, r10\n\
	and r0, r1\n\
	lsl r0, #4\n\
	b _0819A22A\n\
	.pool\n\
_0819A1D0:\n\
	ldrb r1, [r3]\n\
	mov r0, r9\n\
	and r0, r1\n\
	lsl r0, #8\n\
	b _0819A22A\n\
_0819A1DA:\n\
	add r0, r6, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A206\n\
	ldrh r0, [r4]\n\
	ldr r2, =0x0000ff0f\n\
	and r2, r0\n\
	add r0, r5, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A1FC\n\
	ldrb r1, [r3]\n\
	mov r0, r10\n\
	b _0819A228\n\
	.pool\n\
_0819A1FC:\n\
	ldrb r1, [r3]\n\
	mov r0, r9\n\
	and r0, r1\n\
	lsl r0, #4\n\
	b _0819A22A\n\
_0819A206:\n\
	ldrh r0, [r4]\n\
	ldr r2, =0x0000fff0\n\
	and r2, r0\n\
	add r0, r5, #0\n\
	and r0, r7\n\
	cmp r0, #0\n\
	beq _0819A224\n\
	ldrb r1, [r3]\n\
	mov r0, r10\n\
	and r0, r1\n\
	lsr r0, #4\n\
	b _0819A22A\n\
	.pool\n\
_0819A224:\n\
	ldrb r1, [r3]\n\
	mov r0, r9\n\
_0819A228:\n\
	and r0, r1\n\
_0819A22A:\n\
	orr r2, r0\n\
	strh r2, [r4]\n\
	add r5, #0x1\n\
	add r6, #0x1\n\
	ldr r0, [sp, #0x10]\n\
	cmp r5, r0\n\
	bge _0819A23A\n\
	b _0819A12E\n\
_0819A23A:\n\
	ldr r1, [sp, #0x20]\n\
	mov r12, r1\n\
	ldr r2, [sp, #0x24]\n\
	mov r8, r2\n\
	ldr r0, [sp, #0x14]\n\
	cmp r12, r0\n\
	bge _0819A24A\n\
	b _0819A10C\n\
_0819A24A:\n\
	add sp, #0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n");
}
#endif

void sub_819A25C(u8 palOffset, u16 speciesId)
{
    LoadPalette(GetValidMonIconPalettePtr(speciesId), palOffset, 0x20);
}

void sub_819A27C(u8 windowId, u16 speciesId, u32 personality, u16 x, u16 y)
{
    BlitBitmapToWindow(windowId, GetMonIconPtr(speciesId, personality, 1), x, y, 32, 32);
}

void sub_819A2BC(u8 palOffset, u8 palId)
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

void blit_move_info_icon(u8 windowId, u8 iconId, u16 x, u16 y)
{
    BlitBitmapRectToWindow(windowId, gFireRedMenuElements_Gfx + gUnknown_0860F0D4[iconId].unk3 * 32, 0, 0, 128, 128, x, y, gUnknown_0860F0D4[iconId].unk1, gUnknown_0860F0D4[iconId].unk2);
}
