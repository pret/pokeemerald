#ifndef GUARD_WINDOW_H
#define GUARD_WINDOW_H

#define WINDOWS_MAX  32

enum
{
    WINDOW_PRIORITY,
    WINDOW_TILEMAP_LEFT,
    WINDOW_TILEMAP_TOP,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_PALETTE_NUM,
    WINDOW_BASE_BLOCK,
    WINDOW_TILE_DATA
};

struct WindowTemplate
{
    u8 priority;
    u8 tilemapLeft;
    u8 tilemapTop;
    u8 width;
    u8 height;
    u8 paletteNum;
    u16 baseBlock;
};

struct Window
{
    struct WindowTemplate window;
    u8 *tileData;
};

extern struct Window gWindows[WINDOWS_MAX];

#endif // GUARD_WINDOW_H
