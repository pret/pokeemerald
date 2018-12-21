#ifndef GUARD_REGION_MAP_H
#define GUARD_REGION_MAP_H

#include <gba/gba.h>

#include "bg.h"

// Exported type declarations

enum
{
    INPUT_EVENT_NONE,
    INPUT_EVENT_MOVE_START,
    INPUT_EVENT_MOVE_CONT,
    INPUT_EVENT_MOVE_END,
    INPUT_EVENT_A_BUTTON,
    INPUT_EVENT_B_BUTTON,
};

enum {
    MAPSECTYPE_NONE,
    MAPSECTYPE_PLAIN,
    MAPSECTYPE_CITY_CANFLY,
    MAPSECTYPE_CITY_CANTFLY,
    MAPSECTYPE_BATTLE_FRONTIER
};

struct RegionMap {
    /*0x000*/ u16 mapSecId;
    /*0x002*/ u8 iconDrawType;
    /*0x003*/ u8 posWithinMapSec;
    /*0x004*/ u8 mapSecName[0x14];
    /*0x018*/ u8 (*inputCallback)(void);
    /*0x01c*/ struct Sprite *cursorSprite;
    /*0x020*/ struct Sprite *playerIconSprite;
    /*0x024*/ s32 bg2x;
    /*0x028*/ s32 bg2y;
    /*0x02c*/ u32 bg2pa;
    /*0x034*/ u32 bg2pc;
    /*0x030*/ u32 bg2pb;
    /*0x038*/ u32 bg2pd;
    /*0x03c*/ s32 unk_03c;
    /*0x040*/ s32 unk_040;
    /*0x044*/ s32 unk_044;
    /*0x048*/ s32 unk_048;
    /*0x04c*/ s32 unk_04c;
    /*0x050*/ s32 unk_050;
    /*0x054*/ u16 cursorPosX;
    /*0x056*/ u16 cursorPosY;
    /*0x058*/ u16 cursorTileTag;
    /*0x05a*/ u16 cursorPaletteTag;
    /*0x05c*/ s16 scrollX;
    /*0x05e*/ s16 scrollY;
    /*0x060*/ s16 unk_060;
    /*0x062*/ s16 unk_062;
    /*0x064*/ u16 zoomedCursorPosX;
    /*0x066*/ u16 zoomedCursorPosY;
    /*0x068*/ s16 zoomedCursorDeltaY;
    /*0x06a*/ s16 zoomedCursorDeltaX;
    /*0x06c*/ u16 zoomedCursorMovementFrameCounter;
    /*0x06e*/ u16 unk_06e;
    /*0x070*/ u16 playerIconTileTag;
    /*0x072*/ u16 playerIconPaletteTag;
    /*0x074*/ u16 playerIconSpritePosX;
    /*0x076*/ u16 playerIconSpritePosY;
    /*0x078*/ bool8 zoomed;
    /*0x079*/ u8 initStep;
    /*0x07a*/ s8 cursorMovementFrameCounter;
    /*0x07b*/ s8 cursorDeltaX;
    /*0x07c*/ s8 cursorDeltaY;
    /*0x07d*/ bool8 needUpdateVideoRegs;
    /*0x07e*/ bool8 blinkPlayerIcon;
    /*0x07f*/ bool8 playerIsInCave;
    /*0x080*/ u8 bgNum;
    /*0x081*/ u8 charBaseIdx;
    /*0x082*/ u8 mapBaseIdx;
    /*0x083*/ bool8 bgManaged;
    /*0x084*/ u8 filler_084[0x100];
    /*0x184*/ u8 cursorSmallImage[0x100];
    /*0x284*/ u8 cursorLargeImage[0x600];
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
void sub_8122CF8(struct RegionMap *regionMap, struct BgTemplate *template, bool8 zoomed);
bool8 sub_8122DB0(void);
void UpdateRegionMapVideoRegs(void);
void InitRegionMap(struct RegionMap *regionMap, u8 argument);
u8 sub_81230AC(void);
bool8 sub_8123514(void);
void FreeRegionMapIconResources(void);
u16 GetRegionMapSectionIdAt(u16 x, u16 y);
void CreateRegionMapPlayerIcon(u16 x, u16 y);
void CreateRegionMapCursor(u16 tileTag, u16 paletteTag);
u8 *GetMapName(u8 *, u16, u16);
bool32 sub_8124668(u8 mapSecId);
u8 *sub_81245DC(u8 *dest, u16 mapSecId);
u8 *sub_8124610(u8 *dest, u16 mapSecId);
u16 CorrectSpecialMapSecId(u16 mapSecId);
void sub_8122D88(struct RegionMap *regionMap);
void PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(s16 x, s16 y);
void MCB2_FlyMap(void);

extern const struct RegionMapLocation gRegionMapEntries[];

#endif //GUARD_REGION_MAP_H
