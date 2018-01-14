#ifndef GUARD_FIELD_CAMERA_H
#define GUARD_FIELD_CAMERA_H

// Exported type declarations

struct CameraObject
{
    void (*callback)(struct CameraObject *);
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 x;
    s32 y;
};

extern struct CameraObject gUnknown_03005DD0;

// Exported RAM declarations

extern u16 gUnknown_03005DEC;
extern u16 gUnknown_03005DE8;

// Exported ROM declarations

void DrawWholeMapView(void);
void CurrentMapDrawMetatileAt(int x, int y);
void sub_8089C08(s16 *a0, s16 *a1);
void DrawDoorMetatileAt(int x, int y, u16 *arr);

#endif //GUARD_FIELD_CAMERA_H
