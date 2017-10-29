
// Includes
#include "global.h"

// Static type declarations

struct FieldCameraUnknownStruct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    bool8 unk4;
};

// Static RAM declarations

IWRAM_DATA struct FieldCameraUnknownStruct gUnknown_03000E20;
IWRAM_DATA s16 gUnknown_03000E28;
IWRAM_DATA s16 gUnknown_03000E2A;
IWRAM_DATA u8 gUnknown_03000E2C;
IWRAM_DATA void (*gUnknown_03000E30)(void);

// Static ROM declarations

// .rodata

// .text
