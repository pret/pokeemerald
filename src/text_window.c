#include "global.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "palette.h"
#include "bg.h"
#include "graphics.h"

const u8 gTextWindowFrame1_Gfx[] = INCGFX_U8("graphics/text_window/1.png", ".4bpp");
static const u8 sTextWindowFrame2_Gfx[] = INCGFX_U8("graphics/text_window/2.png", ".4bpp");
static const u8 sTextWindowFrame3_Gfx[] = INCGFX_U8("graphics/text_window/3.png", ".4bpp");
static const u8 sTextWindowFrame4_Gfx[] = INCGFX_U8("graphics/text_window/4.png", ".4bpp");
static const u8 sTextWindowFrame5_Gfx[] = INCGFX_U8("graphics/text_window/5.png", ".4bpp");
static const u8 sTextWindowFrame6_Gfx[] = INCGFX_U8("graphics/text_window/6.png", ".4bpp");
static const u8 sTextWindowFrame7_Gfx[] = INCGFX_U8("graphics/text_window/7.png", ".4bpp");
static const u8 sTextWindowFrame8_Gfx[] = INCGFX_U8("graphics/text_window/8.png", ".4bpp");
static const u8 sTextWindowFrame9_Gfx[] = INCGFX_U8("graphics/text_window/9.png", ".4bpp");
static const u8 sTextWindowFrame10_Gfx[] = INCGFX_U8("graphics/text_window/10.png", ".4bpp");
static const u8 sTextWindowFrame11_Gfx[] = INCGFX_U8("graphics/text_window/11.png", ".4bpp");
static const u8 sTextWindowFrame12_Gfx[] = INCGFX_U8("graphics/text_window/12.png", ".4bpp");
static const u8 sTextWindowFrame13_Gfx[] = INCGFX_U8("graphics/text_window/13.png", ".4bpp");
static const u8 sTextWindowFrame14_Gfx[] = INCGFX_U8("graphics/text_window/14.png", ".4bpp");
static const u8 sTextWindowFrame15_Gfx[] = INCGFX_U8("graphics/text_window/15.png", ".4bpp");
static const u8 sTextWindowFrame16_Gfx[] = INCGFX_U8("graphics/text_window/16.png", ".4bpp");
static const u8 sTextWindowFrame17_Gfx[] = INCGFX_U8("graphics/text_window/17.png", ".4bpp");
static const u8 sTextWindowFrame18_Gfx[] = INCGFX_U8("graphics/text_window/18.png", ".4bpp");
static const u8 sTextWindowFrame19_Gfx[] = INCGFX_U8("graphics/text_window/19.png", ".4bpp");
static const u8 sTextWindowFrame20_Gfx[] = INCGFX_U8("graphics/text_window/20.png", ".4bpp");

const u16 gTextWindowFrame1_Pal[] = INCGFX_U16("graphics/text_window/1.png", ".gbapal");
static const u16 sTextWindowFrame2_Pal[] = INCGFX_U16("graphics/text_window/2.png", ".gbapal");
static const u16 sTextWindowFrame3_Pal[] = INCGFX_U16("graphics/text_window/3.png", ".gbapal");
static const u16 sTextWindowFrame4_Pal[] = INCGFX_U16("graphics/text_window/4.png", ".gbapal");
static const u16 sTextWindowFrame5_Pal[] = INCGFX_U16("graphics/text_window/5.png", ".gbapal");
static const u16 sTextWindowFrame6_Pal[] = INCGFX_U16("graphics/text_window/6.png", ".gbapal");
static const u16 sTextWindowFrame7_Pal[] = INCGFX_U16("graphics/text_window/7.png", ".gbapal");
static const u16 sTextWindowFrame8_Pal[] = INCGFX_U16("graphics/text_window/8.png", ".gbapal");
static const u16 sTextWindowFrame9_Pal[] = INCGFX_U16("graphics/text_window/9.png", ".gbapal");
static const u16 sTextWindowFrame10_Pal[] = INCGFX_U16("graphics/text_window/10.png", ".gbapal");
static const u16 sTextWindowFrame11_Pal[] = INCGFX_U16("graphics/text_window/11.png", ".gbapal");
static const u16 sTextWindowFrame12_Pal[] = INCGFX_U16("graphics/text_window/12.png", ".gbapal");
static const u16 sTextWindowFrame13_Pal[] = INCGFX_U16("graphics/text_window/13.png", ".gbapal");
static const u16 sTextWindowFrame14_Pal[] = INCGFX_U16("graphics/text_window/14.png", ".gbapal");
static const u16 sTextWindowFrame15_Pal[] = INCGFX_U16("graphics/text_window/15.png", ".gbapal");
static const u16 sTextWindowFrame16_Pal[] = INCGFX_U16("graphics/text_window/16.png", ".gbapal");
static const u16 sTextWindowFrame17_Pal[] = INCGFX_U16("graphics/text_window/17.png", ".gbapal");
static const u16 sTextWindowFrame18_Pal[] = INCGFX_U16("graphics/text_window/18.png", ".gbapal");
static const u16 sTextWindowFrame19_Pal[] = INCGFX_U16("graphics/text_window/19.png", ".gbapal");
static const u16 sTextWindowFrame20_Pal[] = INCGFX_U16("graphics/text_window/20.png", ".gbapal");

static const u16 sTextWindowPalettes[][16] =
{
    INCGFX_U16("graphics/text_window/message_box.png", ".gbapal"),
    INCGFX_U16("graphics/text_window/text_pal1.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/text_pal2.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/text_pal3.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/text_pal4.pal", ".gbapal")
};

static const struct TilesPal sWindowFrames[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1_Gfx, gTextWindowFrame1_Pal},
    {sTextWindowFrame2_Gfx, sTextWindowFrame2_Pal},
    {sTextWindowFrame3_Gfx, sTextWindowFrame3_Pal},
    {sTextWindowFrame4_Gfx, sTextWindowFrame4_Pal},
    {sTextWindowFrame5_Gfx, sTextWindowFrame5_Pal},
    {sTextWindowFrame6_Gfx, sTextWindowFrame6_Pal},
    {sTextWindowFrame7_Gfx, sTextWindowFrame7_Pal},
    {sTextWindowFrame8_Gfx, sTextWindowFrame8_Pal},
    {sTextWindowFrame9_Gfx, sTextWindowFrame9_Pal},
    {sTextWindowFrame10_Gfx, sTextWindowFrame10_Pal},
    {sTextWindowFrame11_Gfx, sTextWindowFrame11_Pal},
    {sTextWindowFrame12_Gfx, sTextWindowFrame12_Pal},
    {sTextWindowFrame13_Gfx, sTextWindowFrame13_Pal},
    {sTextWindowFrame14_Gfx, sTextWindowFrame14_Pal},
    {sTextWindowFrame15_Gfx, sTextWindowFrame15_Pal},
    {sTextWindowFrame16_Gfx, sTextWindowFrame16_Pal},
    {sTextWindowFrame17_Gfx, sTextWindowFrame17_Pal},
    {sTextWindowFrame18_Gfx, sTextWindowFrame18_Pal},
    {sTextWindowFrame19_Gfx, sTextWindowFrame19_Pal},
    {sTextWindowFrame20_Gfx, sTextWindowFrame20_Pal}
};

// code
const struct TilesPal *GetWindowFrameTilesPal(u8 id)
{
    if (id >= WINDOW_FRAMES_COUNT)
        return &sWindowFrames[0];
    else
        return &sWindowFrames[id];
}

void LoadMessageBoxGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), gMessageBox_Gfx, 0x1C0, destOffset);
    LoadPalette(GetOverworldTextboxPalettePtr(), palOffset, PLTT_SIZE_4BPP);
}

void LoadUserWindowBorderGfx_(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadUserWindowBorderGfx(windowId, destOffset, palOffset);
}

void LoadWindowGfx(u8 windowId, u8 frameId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFrames[frameId].tiles, 0x120, destOffset);
    LoadPalette(sWindowFrames[frameId].pal, palOffset, PLTT_SIZE_4BPP);
}

void LoadUserWindowBorderGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, destOffset, palOffset);
}

void DrawTextBorderOuter(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft - 1,      tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft,          tilemapTop - 1,         width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width,  tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft - 1,      tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width,  tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft - 1,      tilemapTop + height,    1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft,          tilemapTop + height,    width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width,  tilemapTop + height,    1,      1,      palNum);
}

void DrawTextBorderInner(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft,              tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft + 1,          tilemapTop,                 width - 2,  1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width - 1,  tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft,              tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width - 1,  tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft,              tilemapTop + height - 1,    1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft + 1,          tilemapTop + height - 1,    width -     2,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width - 1,  tilemapTop + height - 1,    1,          1,          palNum);
}

void rbox_fill_rectangle(u8 windowId)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0x11);
}

const u16 *GetTextWindowPalette(u8 id)
{
    switch (id)
    {
    case 0:
        id = 0x00;
        break;
    case 1:
        id = 0x10;
        break;
    case 2:
        id = 0x20;
        break;
    case 3:
        id = 0x30;
        break;
    case 4:
    default:
        id = 0x40;
        break;
    }

    return (const u16 *)(sTextWindowPalettes) + id;
}

const u16 *GetOverworldTextboxPalettePtr(void)
{
    return gMessageBox_Pal;
}

// Effectively LoadUserWindowBorderGfx but specifying the bg directly instead of a window from that bg
void LoadUserWindowBorderGfxOnBg(u8 bg, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(bg, sWindowFrames[gSaveBlock2Ptr->optionsWindowFrameType].tiles, 0x120, destOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, palOffset, PLTT_SIZE_4BPP);
}
