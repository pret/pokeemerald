#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "window.h"
#include "pokenav.h"

// Match Call

struct Pokenav2Struct
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u8 field_008;
    u8 field_009;
    u8 field_00a;
    u8 field_00b;
    u8 field_00c;
    u8 field_00d;
    u8 filler_00e[0x87E];
};

struct Pokenav2Struct * sub_81C9958(void);
bool32 sub_81C99FC(void);
u32 sub_81C9A10(int state);
u32 sub_81C9C6C(int state);
u32 sub_81C9CA8(int state);
u32 sub_81C9D44(int state);
u32 sub_81C9DD8(int state);
u32 sub_81C9E58(int state);
u32 sub_81C9EC8(int state);
u32 sub_81C9EF8(int state);
u32 sub_81C9F28(int state);
void sub_81CA7F4(void);
void sub_81C9FEC(void);
void sub_81CA994(void);

const u16 gUnknown_0861FC78[] = INCBIN_U16("graphics/pokenav/bg.gbapal");
const u32 gUnknown_0861FC98[] = INCBIN_U32("graphics/pokenav/bg.4bpp.lz");
const u32 gUnknown_0861FCAC[] = INCBIN_U32("graphics/pokenav/bg.bin.lz");
const u16 gUnknown_0861FD4C[] = INCBIN_U16("graphics/pokenav/outline.gbapal");
const u32 gUnknown_0861FD6C[] = INCBIN_U32("graphics/pokenav/outline.4bpp.lz");
const u32 gUnknown_0861FFF4[] = INCBIN_U32("graphics/pokenav/outline_map.bin.lz");
const u16 gUnknown_08620104[] = INCBIN_U16("graphics/pokenav/blue_light.gbapal");
const u32 gUnknown_08620124[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz");

const struct BgTemplate gUnknown_08620194[] = {
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

const LoopedTask gUnknown_086201A0[] = {
    NULL,
    sub_81C9C6C,
    sub_81C9CA8,
    sub_81C9D44,
    sub_81C9DD8,
    sub_81C9E58,
    sub_81C9EC8,
    sub_81C9EF8,
    sub_81C9F28
};

bool32 sub_81C98D4(void)
{
    s32 i;

    for (i = 0; i < 78; i++)
    {
        if (sub_81CB0C8(i) == gMapHeader.regionMapSectionId
         && sub_81CAE08(i)
         && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}

bool32 sub_81C9924(void)
{
    struct Pokenav2Struct * unk = sub_81C9958();

    if (unk == NULL)
        return FALSE;
    
    unk->field_00d = 0;
    return TRUE;
}

bool32 sub_81C9940(void)
{
    struct Pokenav2Struct * unk = sub_81C9958();

    if (unk == NULL)
        return FALSE;

    unk->field_00d = 1;
    return TRUE;
}

struct Pokenav2Struct * sub_81C9958(void)
{
    struct Pokenav2Struct * unk = AllocSubstruct(2, sizeof(struct Pokenav2Struct));

    if (unk != NULL)
    {
        unk->field_00c = 0;
        unk->loopedTaskId = CreateLoopedTask(sub_81C9A10, 1);
        unk->callback = sub_81C99FC;
    }

    return unk;
}


void sub_81C9990(s32 ltIdx)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    unk->loopedTaskId = CreateLoopedTask(gUnknown_086201A0[ltIdx], 1);
    unk->callback = sub_81C99FC;
}

bool32 sub_81C99C0(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    return unk->callback();
}

void sub_81C99D4(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    sub_81CA7F4();
    RemoveWindow(unk->field_008);
    sub_81C9FEC();
    sub_81CA994();
    FreePokenavSubstruct(2);
}

bool32 sub_81C99FC(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    return IsLoopedTaskActive(unk->loopedTaskId);
}
