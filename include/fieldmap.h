#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

#define NUM_TILES_IN_PRIMARY_FRLG 640
#define NUM_METATILES_IN_PRIMARY_FRLG 640
#define NUM_PALS_IN_PRIMARY_FRLG 7

#define NUM_TILES_IN_PRIMARY 512
#define NUM_METATILES_IN_PRIMARY 512
#define NUM_PALS_IN_PRIMARY 6

#define NUM_METATILES_TOTAL 1024
#define NUM_TILES_TOTAL 1024
#define NUM_PALS_TOTAL 13
#define MAX_MAP_DATA_SIZE 10240

#define NUM_TILES_PER_METATILE 8

// Map coordinates are offset by 7 when using the map
// buffer because it needs to load sufficient border
// metatiles to fill the player's view (the player has
// 7 metatiles of view horizontally in either direction).
#define MAP_OFFSET 7
#define MAP_OFFSET_W (MAP_OFFSET * 2 + 1)
#define MAP_OFFSET_H (MAP_OFFSET * 2)

#include "main.h"

extern struct BackupMapLayout gBackupMapLayout;
extern u16 ALIGNED(4) sBackupMapData[MAX_MAP_DATA_SIZE];

u32 GetNumTilesInPrimary(struct MapLayout const *mapLayout);
u32 GetNumMetatilesInPrimary(struct MapLayout const *mapLayout);
u32 GetNumPalsInPrimary(struct MapLayout const *mapLayout);
u32 MapGridGetMetatileIdAt(s32 x, s32 y);
u32 MapGridGetMetatileBehaviorAt(s32 x, s32 y);
void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatile);
void MapGridSetMetatileEntryAt(s32 x, s32 y, u16 metatile);
void GetCameraCoords(u16 *x, u16 *y);
u8 MapGridGetCollisionAt(s32 x, s32 y);
enum Connection GetMapBorderIdAt(s32 x, s32 y);
bool32 CanCameraMoveInDirection(enum Direction direction);
u32 GetAttributeByMetatileIdAndMapLayout(u16 metatile, u8 attributeType, bool32 isFrlg);
void GetCameraFocusCoords(u16 *x, u16 *y);
u32 ExtractMetatileAttribute(u32 attributes, u8 attributeType, bool32 isFrlg);
u32 MapGridGetMetatileAttributeAt(s16 x, s16 y, u8 attributeType);
u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y);
u8 MapGridGetElevationAt(s32 x, s32 y);
bool8 CameraMove(s32 x, s32 y);
void SaveMapView(void);
void SetCameraFocusCoords(u16 x, u16 y);
void InitMap(void);
void InitMapFromSavedGame(void);
void InitTrainerHillMap(void);
void InitBattlePyramidMap(bool8 setPlayerPosition);
void CopyMapTilesetsToVram(struct MapLayout const *mapLayout);
void LoadMapTilesetPalettes(struct MapLayout const *mapLayout);
void LoadSecondaryTilesetPalette(struct MapLayout const *mapLayout, bool8 skipFaded);
void CopySecondaryTilesetToVramUsingHeap(struct MapLayout const *mapLayout);
void CopyPrimaryTilesetToVram(struct MapLayout const *mapLayout);
void CopySecondaryTilesetToVram(struct MapLayout const *mapLayout);
const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection);
const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y);
void MapGridSetMetatileImpassabilityAt(s32 x, s32 y, bool32 impassable);
bool32 AreCoordsInsideMap(u8 mapGroup, u8 mapNum, s16 x, s16 y);
bool32 AreCoordsInsidePlayerMap(s16 x, s16 y);

// field_region_map.c
void FieldInitRegionMap(MainCallback callback);

#endif //GUARD_FIELDMAP_H
