#ifndef GUARD_FIELD_CAMERA_H
#define GUARD_FIELD_CAMERA_H

#include "global.h"

// Exported type declarations

struct CameraObject
{
    void (*callback)(struct CameraObject *);
    u32 spriteId;
    s32 unk8;
    s32 unkC;
    s32 x;
    s32 y;
};

// Exported RAM declarations
extern struct CameraObject gUnknown_03005DD0;
extern u16 gUnknown_03005DEC;
extern u16 gUnknown_03005DE8;

// Exported ROM declarations
void DrawWholeMapView(void);
void CurrentMapDrawMetatileAt(int x, int y);
void sub_8089C08(s16 *a0, s16 *a1);
void DrawDoorMetatileAt(int x, int y, u16 *arr);
void move_tilemap_camera_to_upper_left_corner(void);
void sub_8057A58(void);
void ResetCameraUpdateInfo(void);
u32 InitCameraUpdateCallback(u8 a);
void CameraUpdate(void);
void SetCameraPanningCallback(void (*a)(void));
void SetCameraPanning(s16 a, s16 b);
void InstallCameraPanAheadCallback(void);
void UpdateCameraPanning(void);

#endif //GUARD_FIELD_CAMERA_H
