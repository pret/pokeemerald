#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

#define NUM_TILES_IN_PRIMARY 512
#define NUM_TILES_TOTAL 1024
#define NUM_METATILES_IN_PRIMARY 512
#define NUM_METATILES_TOTAL 1024
#define NUM_PALS_IN_PRIMARY 6
#define NUM_PALS_TOTAL 13
#define MAX_MAP_DATA_SIZE 0x2800

#define MAP_TILE_ELEVATION_MASK 0xF000  // The byte containing the elevation for a given tile.
#define MAP_TILE_ELEVATION_SHIFT 12     // Alternate way of getting the same data.

#define MAP_IMPASSABLE_MASK 0x0C00      // When this is set, the tile cannot be walked on.
#define MAP_METATILE_ID_MASK 0x03FF     // This is the mask for extracting a metatile id.

#define MAP_UNDEFINED_METATILE_ID 0x03FF // Default value for metatiles.
#define MAP_UNDEFINED_METATILE_ID_32 0x03FF03FF

extern struct BackupMapLayout gBackupMapLayout;

u32 MapGridGetMetatileIdAt(int, int);
u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void MapGridSetMetatileEntryAt(int, int, u16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(int, int);
int GetMapBorderIdAt(int x, int y);
int CanCameraMoveInDirection(int direction);
u16 GetBehaviorByMetatileId(u16 metatileId);
void GetCameraFocusCoords(u16 *x, u16 *y);
u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y);
u8 MapGridGetZCoordAt(int x, int y);
u8 CameraMove(s32 deltaX, s32 deltaY);
struct MapConnection *sub_8088950(u8 direction, int x, int y);
bool8 sub_80889A8(u8 direction, int x, int y, struct MapConnection *connection);
bool8 sub_8088A0C(int x, int src_width, int dest_width, int offset);
void save_serialize_map(void);
void sub_8088B3C(u16 x, u16 y);
void InitMap(void);
void InitMapFromSavedGame(void);
void InitTrainerHillMap(void);
void InitBattlePyramidMap(bool8 setPlayerPosition);
void copy_map_tileset1_tileset2_to_vram(struct MapLayout const *mapLayout);
void apply_map_tileset1_tileset2_palette(struct MapLayout const *mapLayout);
void apply_map_tileset2_palette(struct MapLayout const *mapLayout);
void copy_map_tileset2_to_vram_2(struct MapLayout const *mapLayout);
extern void copy_map_tileset1_to_vram(const struct MapLayout *);
extern void copy_map_tileset2_to_vram(const struct MapLayout *);

void SpriteCB_PokeballGlow(struct Sprite *);
void SpriteCB_PokecenterMonitor(struct Sprite *);
void SpriteCB_HallOfFameMonitor(struct Sprite *);

#endif //GUARD_FIELDMAP_H
