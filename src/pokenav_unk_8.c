#include "global.h"
#include "pokenav.h"

struct PokenavSub7
{
    u32 (*unk0)(struct PokenavSub7 *);
    u32 loopedTaskId;
    u8 fill1[12];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    struct PokenavSub18 *unkPtr;
};

extern const u32 gUnknown_086233A0[];

u32 sub_81CF010(struct PokenavSub7 *structPtr);
u32 sub_81CF030(struct PokenavSub7 *structPtr);
u32 sub_81CF0B8(struct PokenavSub7 *structPtr);
u32 sub_81CF0B0(struct PokenavSub7 *structPtr);
u32 sub_81CF11C(s32 state);

bool32 sub_81CEF3C(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unkPtr = AllocSubstruct(18, sizeof(struct PokenavSub18));
    if (structPtr->unkPtr == NULL)
        return FALSE;

    structPtr->unk0 = sub_81CF010;
    structPtr->loopedTaskId = CreateLoopedTask(sub_81CF11C, 1);
    structPtr->unk18 = 0;
    structPtr->unk14 = gUnknown_086233A0[sub_81C76AC()];
    return TRUE;
}

bool32 sub_81CEF98(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unkPtr = GetSubstructPtr(18);
    structPtr->unk0 = sub_81CF030;
    structPtr->unk18 = 1;
    structPtr->unk14 = gUnknown_086233A0[sub_81C76AC()];
    return TRUE;
}

u32 sub_81CEFDC(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    return structPtr->unk0(structPtr);
}

void sub_81CEFF0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    if (structPtr->unk1C == 0)
        FreePokenavSubstruct(18);
    FreePokenavSubstruct(7);
}

bool32 sub_81CF010(struct PokenavSub7 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->unk0 = sub_81CF030;
    return FALSE;
}

u32 sub_81CF030(struct PokenavSub7 *structPtr)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return 1;
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return 2;
    else if (gMain.newKeys & DPAD_LEFT)
        return 3;
    else if (gMain.newKeys & DPAD_RIGHT)
        return 4;
    else if (gMain.newKeys & B_BUTTON)
    {
        structPtr->unk1C = 0;
        structPtr->unk0 = sub_81CF0B0;
        return 5;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        structPtr->unkPtr->unk2 = GetSelectedMatchCall();
        structPtr->unk1C = 1;
        structPtr->unk0 = sub_81CF0B8;
        return 6;
    }
    else
        return 0;
}

u32 sub_81CF0B0(struct PokenavSub7 *structPtr)
{
    return 0x186A3;
}

u32 sub_81CF0B8(struct PokenavSub7 *structPtr)
{
    return 0x186A9;
}

u32 sub_81CF0C0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    return structPtr->unk18;
}
