
// Includes
#include "global.h"
#include "region_map.h"

// Static type declarations

struct UnkStruct_0203A148 {
    u8 filler_000[0xa74];
};

// Static RAM declarations

EWRAM_DATA struct RegionMap *gUnknown_0203A144 = NULL;
EWRAM_DATA struct UnkStruct_0203A148 *gUnknown_0203A148 = NULL;

// Static ROM declarations

void sub_8122CF8(struct RegionMap *regionMap, struct UnkStruct_8122CF8 *arg1, bool8 arg2);
bool8 sub_8122DB0(void);
u8 sub_8123254(void);
u8 sub_81230C4(void);

// .rodata

// .text

void sub_8122CDC(struct RegionMap *regionMap, bool8 argument)
{
    sub_8122CF8(regionMap, NULL, argument);
    while (sub_8122DB0());
}

void sub_8122CF8(struct RegionMap *regionMap, struct UnkStruct_8122CF8 *arg1, bool8 arg2)
{
    gUnknown_0203A144 = regionMap;
    gUnknown_0203A144->unk_079 = 0;
    gUnknown_0203A144->unk_078 = arg2;
    gUnknown_0203A144->inputCallback = arg2 == TRUE ? sub_8123254 : sub_81230C4;
    if (arg1 != NULL)
    {
        gUnknown_0203A144->unk_080 = arg1->unk_0_0;
        gUnknown_0203A144->unk_081 = arg1->unk_0_2;
        gUnknown_0203A144->unk_082 = arg1->unk_0_4;
        gUnknown_0203A144->unk_083 = TRUE;
    }
    else
    {
        gUnknown_0203A144->unk_080 = 2;
        gUnknown_0203A144->unk_081 = 2;
        gUnknown_0203A144->unk_082 = 28;
        gUnknown_0203A144->unk_083 = FALSE;
    }
}
