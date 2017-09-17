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

#endif //GUARD_FIELD_CAMERA_H
