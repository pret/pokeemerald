#ifndef GUARD_REGION_MAP_H
#define GUARD_REGION_MAP_H

#include "bg.h"

// Exported type declarations
#define MAP_NAME_LENGTH 16

enum
{
    MAP_INPUT_NONE,
    MAP_INPUT_MOVE_START,
    MAP_INPUT_MOVE_CONT,
    MAP_INPUT_MOVE_END,
    MAP_INPUT_A_BUTTON,
    MAP_INPUT_B_BUTTON,
};

enum {
    MAPSECTYPE_NONE,
    MAPSECTYPE_ROUTE,
    MAPSECTYPE_CITY_CANFLY,
    MAPSECTYPE_CITY_CANTFLY,
    MAPSECTYPE_BATTLE_FRONTIER,
    NUM_MAPSEC_TYPES
};

struct RegionMap {
    mapsec_u16_t mapSecId;
    u8 mapSecType;
    u8 posWithinMapSec;
    u8 mapSecName[20];
    u8 (*inputCallback)(void);
    struct Sprite *cursorSprite;
    struct Sprite *playerIconSprite;
    s32 bg2x;
    s32 bg2y;
    u32 bg2pa;
    u32 bg2pc;
    u32 bg2pb;
    u32 bg2pd;
    s32 unk_03c;
    s32 unk_040;
    s32 unk_044;
    s32 unk_048;
    s32 unk_04c;
    s32 unk_050;
    u16 cursorPosX;
    u16 cursorPosY;
    u16 cursorTileTag;
    u16 cursorPaletteTag;
    s16 scrollX;
    s16 scrollY;
    s16 unk_060;
    s16 unk_062;
    u16 zoomedCursorPosX;
    u16 zoomedCursorPosY;
    s16 zoomedCursorDeltaY;
    s16 zoomedCursorDeltaX;
    u16 zoomedCursorMovementFrameCounter;
    u16 unk_06e;
    u16 playerIconTileTag;
    u16 playerIconPaletteTag;
    u16 playerIconSpritePosX;
    u16 playerIconSpritePosY;
    bool8 zoomed;
    u8 initStep;
    s8 cursorMovementFrameCounter;
    s8 cursorDeltaX;
    s8 cursorDeltaY;
    bool8 needUpdateVideoRegs;
    bool8 blinkPlayerIcon;
    bool8 playerIsInCave;
    u8 bgNum;
    u8 charBaseIdx;
    u8 mapBaseIdx;
    bool8 bgManaged;
    u8 filler_084[0x100];
    u8 cursorSmallImage[0x100];
    u8 cursorLargeImage[0x600];
}; // size = 0x884

struct RegionMapLocation
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u8 *name;
};

// Exported RAM declarations

// Exported ROM declarations
void InitRegionMapData(struct RegionMap *regionMap, const struct BgTemplate *template, bool8 zoomed);
bool8 LoadRegionMapGfx(void);
void UpdateRegionMapVideoRegs(void);
void InitRegionMap(struct RegionMap *regionMap, bool8 zoomed);
u8 DoRegionMapInputCallback(void);
bool8 UpdateRegionMapZoom(void);
void FreeRegionMapIconResources(void);
mapsec_u16_t GetRegionMapSecIdAt(u16 x, u16 y);
void CreateRegionMapPlayerIcon(u16 tileTag, u16 paletteTag);
void CreateRegionMapCursor(u16 tileTag, u16 paletteTag);
bool32 IsEventIslandMapSecId(mapsec_u8_t mapSecId);
u8 *GetMapName(u8 *dest, mapsec_u16_t regionMapId, u16 padLength);
u8 *GetMapNameGeneric(u8 *dest, mapsec_u16_t mapSecId);
u8 *GetMapNameHandleAquaHideout(u8 *dest, mapsec_u16_t mapSecId);
mapsec_u16_t CorrectSpecialMapSecId(mapsec_u16_t mapSecId);
void ShowRegionMapForPokedexAreaScreen(struct RegionMap *regionMap);
void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y);
void CB2_OpenFlyMap(void);
bool8 IsRegionMapZoomed(void);
void TrySetPlayerIconBlink(void);
void BlendRegionMap(u16 color, u32 coeff);
void SetRegionMapDataForZoom(void);

extern const struct RegionMapLocation gRegionMapEntries[];

#endif //GUARD_REGION_MAP_H
