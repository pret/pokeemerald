#ifndef GUARD_BG_H
#define GUARD_BG_H

enum
{
    BG_ATTR_CHARBASEINDEX = 1,
    BG_ATTR_MAPBASEINDEX,
    BG_ATTR_SCREENSIZE,
    BG_ATTR_PALETTEMODE,
    BG_ATTR_MOSAIC,
    BG_ATTR_WRAPAROUND,
    BG_ATTR_PRIORITY,
    BG_ATTR_METRIC,
    BG_ATTR_TYPE,
    BG_ATTR_BASETILE,
};

enum {
    BG_TYPE_NORMAL,
    BG_TYPE_AFFINE,
    BG_TYPE_NONE = 0xFFFF
};

// Modes for ChangeBgX / ChangeBgY
enum {
    BG_COORD_SET,
    BG_COORD_ADD,
    BG_COORD_SUB,
};

// Modes for Unused_AdjustBgMosaic
enum {
    BG_MOSAIC_SET_HV,
    BG_MOSAIC_SET_H,
    BG_MOSAIC_ADD_H,
    BG_MOSAIC_SUB_H,
    BG_MOSAIC_SET_V,
    BG_MOSAIC_ADD_V,
    BG_MOSAIC_SUB_V,
};

struct BgTemplate
{
    u16 bg:2;                   // 0x1, 0x2 -> 0x3
    u16 charBaseIndex:2;        // 0x4, 0x8 -> 0xC
    u16 mapBaseIndex:5;         // 0x10, 0x20, 0x40, 0x80, 0x100 -> 0x1F0
    u16 screenSize:2;           // 0x200, 0x400 -> 0x600
    u16 paletteMode:1;          // 0x800
    u16 priority:2;             // 0x1000, 0x2000 > 0x3000
    u16 baseTile:10;
};

void ResetBgs(void);
u32 GetBgMode(void);
void ResetBgControlStructs(void);
void Unused_ResetBgControlStruct(u32 bg);
u8 LoadBgVram(u32 bg, const void *src, u16 size, u16 destOffset, u32 mode);
void SetTextModeAndHideBgs(void);
bool32 IsInvalidBg(u32 bg);
int BgTileAllocOp(int bg, int offset, int count, int mode);
void ResetBgsAndClearDma3BusyFlags(u32 leftoverFireRedLeafGreenVariable);
void InitBgsFromTemplates(u32 bgMode, const struct BgTemplate *templates, u8 numTemplates);
void InitBgFromTemplate(const struct BgTemplate *template);
void SetBgMode(u32 bgMode);
u16 LoadBgTiles(u32 bg, const void *src, u16 size, u16 destOffset);
u16 LoadBgTilemap(u32 bg, const void *src, u16 size, u16 destOffset);
u16 Unused_LoadBgPalette(u32 bg, const void *src, u16 size, u16 destOffset);
bool32 IsDma3ManagerBusyWithBgCopy(void);
void ShowBg(u32 bg);
void HideBg(u32 bg);
void SetBgAttribute(u32 bg, u32 attributeId, u8 value);
u16 GetBgAttribute(u32 bg, u32 attributeId);
s32 ChangeBgX(u32 bg, s32 value, u8 op);
s32 GetBgX(u32 bg);
s32 ChangeBgY(u32 bg, s32 value, u8 op);
s32 ChangeBgY_ScreenOff(u32 bg, s32 value, u8 op);
s32 GetBgY(u32 bg);
void SetBgAffine(u32 bg, s32 srcCenterX, s32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle);
u8 Unused_AdjustBgMosaic(u8 val, u32 mode);
void SetBgTilemapBuffer(u32 bg, void *tilemap);
void UnsetBgTilemapBuffer(u32 bg);
void *GetBgTilemapBuffer(u32 bg);
void CopyToBgTilemapBuffer(u32 bg, const void *src, u16 mode, u16 destOffset);
void CopyBgTilemapBufferToVram(u32 bg);
void CopyToBgTilemapBufferRect(u32 bg, const void *src, u8 destX, u8 destY, u8 width, u8 height);
void CopyToBgTilemapBufferRect_ChangePalette(u32 bg, const void *src, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette);
void CopyRectToBgTilemapBufferRect(u32 bg, const void *src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette1, s16 tileOffset, s16 palette2);
void FillBgTilemapBufferRect_Palette0(u32 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height);
void FillBgTilemapBufferRect(u32 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height, u8 palette);
void WriteSequenceToBgTilemapBuffer(u32 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, s16 tileNumDelta);
u16 GetBgMetricTextMode(u32 bg, u32 whichMetric);
u32 GetBgMetricAffineMode(u32 bg, u32 whichMetric);
u32 GetTileMapIndexFromCoords(s32 x, s32 y, s32 screenSize, u32 screenWidth, u32 screenHeight);
void CopyTileMapEntry(const u16 *src, u16 *dest, s32 palette1, s32 tileOffset, s32 palette2);
bool32 IsTileMapOutsideWram(u32 bg);

#endif // GUARD_BG_H
