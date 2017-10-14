
// Includes
#include "global.h"
#include "overworld.h"
#include "event_data.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_81B99D4(void);
void sub_81B9A28(void);
void sub_81B9A44(void);
void sub_81B9A60(void);
void sub_81B9A90(void);
void sub_81B9ABC(void);
void sub_81B9B00(void);
void sub_81B9B28(void);
void sub_81B9BA0(void);
void sub_81B9BF4(void);
void sub_81B9C10(void);
void sub_81B9C2C(void);
void sub_81B9C70(void);
void sub_81B9C98(void);
void sub_81B9CF0(void);
void sub_81B9D28(void);
void sub_81B9D7C(void);
void sub_81B9D98(void);
void sub_81B9DB4(void);
void sub_81B9DF8(void);
void sub_81B9E20(void);
void sub_81B9E78(void);
void sub_81B9E88(void);
void sub_81BA040(void);
void sub_81B9EC0(void);

// .rodata

void (*const gUnknown_086160B4[])(void) = {
    sub_81B99D4,
    sub_81B9A28,
    sub_81B9A44,
    sub_81B9A60,
    sub_81B9A90,
    sub_81B9ABC,
    sub_81B9B00,
    sub_81B9B28
};

const u16 gUnknown_086160D4 = 0x08;

void (*const gUnknown_086160D8[])(void) = {
    sub_81B9BA0,
    sub_81B9BF4,
    sub_81B9C10,
    sub_81B9C2C,
    sub_81B9C70,
    sub_81B9C98,
    sub_81B9CF0
};

const u16 gUnknown_086160F4 = 0x15;

void (*const gUnknown_086160F8[])(void) = {
    sub_81B9D28,
    sub_81B9D7C,
    sub_81B9D98,
    sub_81B9DB4,
    sub_81B9DF8,
    sub_81B9E20,
    sub_81B9E78,
    sub_81B9E88,
    sub_81BA040,
    sub_81B9EC0
};

const u16 gUnknown_08616120 = 0x17;

asm(".section .rodata\n"
    "\t.align 2, 0"); // because gcc doesn't do it on its own

// .text

void sub_81B99B4(void)
{
    gUnknown_086160B4[gSpecialVar_0x8004]();
}

void sub_81B99D4(void)
{
    gSaveBlock2Ptr->field_CA8 = 0;
    gSaveBlock2Ptr->field_CB2 = 0;
    gSaveBlock2Ptr->field_CA9_a = 0;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9A28(void)
{
    gScriptResult = gSaveBlock2Ptr->field_E6A;
}

void sub_81B9A44(void)
{
    gSaveBlock2Ptr->field_E6A = gSpecialVar_0x8006;
}
