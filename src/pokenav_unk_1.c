#include "global.h"
#include "pokenav.h"
#include "event_data.h"

struct Pokenav1Struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8[8];
};

extern void sub_81C939C(struct Pokenav1Struct *state);

u8 sub_81C9268(void)
{
    u32 ret = 0;
    if (FlagGet(FLAG_ADDED_MATCH_CALL_TO_POKENAV))
    { 
        ret = 1;
        if (FlagGet(FLAG_SYS_RIBBON_GET))
            ret = 2;
    }
    
    return ret;
}

u32 sub_81C9298(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));

    if (state == NULL)
        return 0;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 0;
    state->unk4 = 0;
    state->unk6 = 0;
    sub_81C939C(state);

    return 1;
}