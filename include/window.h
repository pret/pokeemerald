#ifndef GUARD_WINDOW_H
#define GUARD_WINDOW_H

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

#endif // GUARD_WINDOW_H
