#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

extern struct MapCoords {
    int width;
    int height;
} gUnknown_03005DC0;

u32 MapGridGetMetatileIdAt(int, int);
u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void MapGridSetMetatileEntryAt(int, int, u16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(s16, s16);
s32 GetMapBorderIdAt(s16, s16);
bool32 CanCameraMoveInDirection(u8);
u16 GetBehaviorByMetatileId(u16 metatileId);
void sav1_camera_get_focus_coords(u16 *x, u16 *y);
u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y);
u8 CameraMove(s32 deltaX, s32 deltaY);

#endif //GUARD_FIELDMAP_H
