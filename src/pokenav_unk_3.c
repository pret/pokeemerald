#include "global.h"
#include "pokenav.h"

struct Pokenav3Struct
{
    u8 filler0[0x8];
    u16 unk8;
    u8 fillerA[0x6];
    u32 unk10;
    u32 unk14;
    u32 (*unk18)(struct Pokenav3Struct*);
    u8 filler1C[0x18C];
};

u32 sub_81CAB44(struct Pokenav3Struct *);
u32 sub_81CAD20(int);

bool32 sub_81CAAE8(void)
{
    struct Pokenav3Struct *state = AllocSubstruct(5, sizeof(struct Pokenav3Struct));
    if (!state)
        return FALSE;

    state->unk18 = sub_81CAB44;
    state->unk8 = 0;
    state->unk10 = 0;
    state->unk14 = CreateLoopedTask(sub_81CAD20, 1);
    return TRUE;
}

u32 sub_81CAB24(void)
{
    struct Pokenav3Struct *state = GetSubstructPtr(5);
    return state->unk18(state);
}

void sub_81CAB38(void)
{
    FreePokenavSubstruct(5);
}
