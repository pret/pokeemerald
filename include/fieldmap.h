#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

extern struct BackupMapLayout gUnknown_03005DC0;

u32 MapGridGetMetatileIdAt(int, int);
u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void MapGridSetMetatileEntryAt(int, int, u16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(int, int);
int GetMapBorderIdAt(int x, int y);
int CanCameraMoveInDirection(int direction);
u16 GetBehaviorByMetatileId(u16 metatileId);
void sav1_camera_get_focus_coords(u16 *x, u16 *y);
u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y);
u8 MapGridGetZCoordAt(int x, int y);
u8 CameraMove(s32 deltaX, s32 deltaY);
void mapheader_copy_mapdata_with_padding(struct MapHeader *mapHeader);
void map_copy_with_padding(u16 *map, u16 width, u16 height);
void mapheader_copy_mapdata_of_adjacent_maps(struct MapHeader *);
void fillSouthConnection(struct MapHeader const *, struct MapHeader const *, s32);
void fillNorthConnection(struct MapHeader const *, struct MapHeader const *, s32);
void fillWestConnection(struct MapHeader const *, struct MapHeader const *, s32);
void fillEastConnection(struct MapHeader const *, struct MapHeader const *, s32);
void mapdata_from_sav2(void);
bool8 sub_8088BF0(u16*, u16, u8);
struct MapConnection *sub_8088950(u8 direction, int x, int y);
bool8 sub_80889A8(u8 direction, int x, int y, struct MapConnection *connection);
bool8 sub_8088A0C(int x, int src_width, int dest_width, int offset);

void SpriteCB_PokeballGlow(struct Sprite *);
void SpriteCB_PokecenterMonitor(struct Sprite *);
void SpriteCB_HallOfFameMonitor(struct Sprite *);

#endif //GUARD_FIELDMAP_H
