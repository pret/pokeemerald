#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

extern struct MapCoords {
    int width;
    int height;
} gUnknown_03005DC0;

u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void MapGridSetMetatileEntryAt(int, int, u16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(s16, s16);
s32 GetMapBorderIdAt(s16, s16);
bool32 CanCameraMoveInDirection(u8);
u16 GetBehaviorByMetatileId(u16 metatileId);

#endif //GUARD_FIELDMAP_H
