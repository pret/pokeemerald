//
// Created by scott on 9/16/2017.
//

#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

// Exported type declarations

// Exported RAM declarations
extern struct MapCoords {
    int width;
    int height;
} gUnknown_03005DC0;

// Exported ROM declarations
u32 MapGridGetMetatileBehaviorAt(int, int);
void MapGridSetMetatileIdAt(int, int, u16);
void GetCameraCoords(u16*, u16*);
bool8 MapGridIsImpassableAt(s16, s16);
s32 GetMapBorderIdAt(s16, s16);
bool32 CanCameraMoveInDirection(u8);

#endif //GUARD_FIELDMAP_H
