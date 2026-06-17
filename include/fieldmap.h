#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

#define NUM_TILES_IN_PRIMARY 512
#define NUM_TILES_TOTAL 1024
#define NUM_METATILES_IN_PRIMARY 512
#define NUM_METATILES_TOTAL 1024
#define NUM_PALS_IN_PRIMARY 6
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

s32 MapGridGetMetatileIdAt(s32 x, s32 y);
s32 MapGridGetMetatileBehaviorAt(s32 x, s32 y);
void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatile);
void MapGridSetMetatileEntryAt(s32 x, s32 y, u16 metatile);
void GetCameraCoords(u16 *x, u16 *y);
u8 MapGridGetCollisionAt(s32 x, s32 y);
s32 GetMapBorderIdAt(s32 x, s32 y);
bool32 CanCameraMoveInDirection(s32 direction);
u16 GetMetatileAttributesById(u16 metatile);
void GetCameraFocusCoords(u16 *x, u16 *y);
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
void LoadSecondaryTilesetPalette(struct MapLayout const *mapLayout);
void CopySecondaryTilesetToVramUsingHeap(struct MapLayout const *mapLayout);
void CopyPrimaryTilesetToVram(struct MapLayout const *mapLayout);
void CopySecondaryTilesetToVram(struct MapLayout const *mapLayout);
const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection);
const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y);
void MapGridSetMetatileImpassabilityAt(s32 x, s32 y, bool32 impassable);

// field_region_map.c
void FieldInitRegionMap(MainCallback callback);

#endif //GUARD_FIELDMAP_H
