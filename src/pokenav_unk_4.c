#include "global.h"
#include "pokenav.h"
#include "window.h"

struct Pokenav4Struct
{
    u32 (*unk0)(void);
    u32 unk4;
    u8 filler8[0x8];
    u8 unk10;
    u8 filler11[0x1];
    u8 unk12;
    u8 filler13[0x1];
    u8 unk14;
    u8 filler15[0x4];
    u8 unk19;
    u8 filler1A[0x202E];
};

static bool32 sub_81CB310(void);
u32 sub_81CB324(int);
void sub_81CBC1C(void);
void sub_81CC2B4(void);

extern const LoopedTask gUnknown_08622798[];

bool32 sub_81CB260(void)
{
    struct Pokenav4Struct *state = AllocSubstruct(6, sizeof(struct Pokenav4Struct));
    if (!state)
        return FALSE;

    state->unk19 = 0;
    state->unk4 = CreateLoopedTask(sub_81CB324, 1);
    state->unk0 = sub_81CB310;
    return TRUE;
}

void sub_81CB29C(int index)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    state->unk4 = CreateLoopedTask(gUnknown_08622798[index], 1);
    state->unk0 = sub_81CB310;
}

u32 sub_81CB2CC(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    return state->unk0();
}

void sub_81CB2E0(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    sub_81CC2B4();
    sub_81CBC1C();
    RemoveWindow(state->unk12);
    RemoveWindow(state->unk10);
    RemoveWindow(state->unk14);
    FreePokenavSubstruct(6);
}

static bool32 sub_81CB310(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(6);
    return IsLoopedTaskActive(state->unk4);
}
