#ifndef GUARD_BG_H
#define GUARD_BG_H

#include "global.h"

enum {
    BG_CTRL_ATTR_VISIBLE = 1,
    BG_CTRL_ATTR_CHARBASEINDEX = 2,
    BG_CTRL_ATTR_MAPBASEINDEX = 3,
    BG_CTRL_ATTR_SCREENSIZE = 4,
    BG_CTRL_ATTR_PALETTEMODE = 5,
    BG_CTRL_ATTR_PRIORITY = 6,
    BG_CTRL_ATTR_MOSAIC = 7,
    BG_CTRL_ATTR_WRAPAROUND = 8,
};

struct BgControl {
    struct BgConfig {
        u16 visible:1;
        u16 unknown_1:1;
        u16 screenSize:2;
        u16 priority:2;
        u16 mosaic:1;
        u16 wraparound:1;
        
        u16 charBaseIndex:2;
        u16 mapBaseIndex:5;
        u16 paletteMode:1;
        
        u8 unknown_2;
        u8 unknown_3;
    } configs[4];
    
    u16 bgVisibilityAndMode;
};

struct BgTemplate {
    u32 bg:2;
    u32 charBaseIndex:2;
    u32 mapBaseIndex:5;
    u32 screenSize:2;
    u32 paletteMode:1;
    u32 priority:2;
    u32 baseTile:10;
};

struct BgConfig2 {
    u32 baseTile:10;
    u32 basePalette:4;
    u32 unk_3:18;
    
    void* tilemap;
    u32 bg_x;
    u32 bg_y;
};

bool32 IsInvalidBg32(u8);
void ResetBgControlStructs();
u16 GetBgMetricTextMode(u8, u8);
u32 GetBgMetricAffineMode(u8, u8);
u32 GetBgType(u8);
void SetTextModeAndHideBgs();
bool8 IsInvalidBg(u8);
bool32 IsTileMapOutsideWram(u8);
void CopyRectToBgTilemapBufferRect(u8, void*, u8, u8, u8, u8, u8, u8, u8, u8, u8, u16, u16);
void CopyTileMapEntry(u16*, u16*, s32, u32, u32);
u32 GetTileMapIndexFromCoords(s32, s32, s32, u32, u32);
void WriteSequenceToBgTilemapBuffer(u8, u16, u8, u8, u8, u8, u8, s16);

#endif // GUARD_BG_H
