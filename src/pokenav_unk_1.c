#include "global.h"
#include "pokenav.h"
#include "event_data.h"
#include "main.h"
#include "sound.h"
#include "constants/songs.h"

struct Pokenav1Struct
{
    u16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u32 (*unkC)(struct Pokenav1Struct*);
};


extern u32 sub_81C76AC(void);
extern u32 sub_81C963C(struct Pokenav1Struct *a0);
extern u32 sub_81C96FC(struct Pokenav1Struct *a0);
extern u32 sub_81C9814(void);
extern void sub_81C97B0(struct Pokenav1Struct *a0, u32 a1);

u32 sub_81C9600(struct Pokenav1Struct *a0);
u32 sub_81C9588(struct Pokenav1Struct *a0);
u32 sub_81C9520(struct Pokenav1Struct *a0);
u32 sub_81C943C(struct Pokenav1Struct *a0);
u32 (*sub_81C93EC(void))(struct Pokenav1Struct*);
void sub_81C939C(struct Pokenav1Struct *state);

extern u8 gUnknown_0861FC59[];

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

u32 sub_81C92CC(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    u8 v0;

    if (state == NULL)
        return 0;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 2;
    state->unk4 = 2;
    state->unk6 = 0;
    sub_81C939C(state);

    return 1;
}

u32 sub_81C9304(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    u8 v0;

    if (state == NULL)
        return 0;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 3;
    state->unk4 = 3;
    sub_81C939C(state);

    return 1;
}

u32 sub_81C9338(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    u8 v0;

    if (state == NULL)
        return 0;
    
    state->unk0 = 3;
    state->unk2 = 0;
    state->unk4 = 5;
    state->unk6 = 0;
    sub_81C939C(state);

    return 1;
}

u32 sub_81C9368(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    u8 v0;

    if (state == NULL)
        return 0;
    
    state->unk0 = 4;
    state->unk2 = sub_81C76AC();
    state->unk4 = 8 + state->unk2;
    state->unk6 = 0;
    sub_81C939C(state);

    return 1;
}

void sub_81C939C(struct Pokenav1Struct *state)
{
    switch (state->unk0)
    {
    case 0:
        SetPokenavMode(0);
        // fallthrough
    case 1:
    case 2:
        state->unkC = sub_81C93EC();
        break;
    case 3:
        state->unkC = sub_81C963C;
        break;
    case 4:
        state->unkC = sub_81C96FC;
        break;
    }
}

u32 (*sub_81C93EC(void))(struct Pokenav1Struct*)
{
    switch (GetPokenavMode())
    {
    default:
    case 0:
        return sub_81C943C;
    case 1:
        return sub_81C9520;
    case 2:
        return sub_81C9588;
    }
}

u32 sub_81C941C(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->unkC(state);
}

void sub_81C9430(void)
{
    FreePokenavSubstruct(1);
}

u32 sub_81C943C(struct Pokenav1Struct *a0)
{
    if (sub_81C9814() != 0)
        return 1;

    if (gMain.newKeys & A_BUTTON)
    {
        switch (gUnknown_0861FC59[a0->unk2 + a0->unk0 * 6])
        {
        case 0:
            a0->unk6 = gSaveBlock2Ptr->regionMapZoom ? 2 : 1;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 6);
            return 8;
        case 1:
            a0->unk0 = 3;
            a0->unk2 = 0;
            a0->unk4 = gUnknown_0861FC59[18];
            a0->unkC = sub_81C963C;
            return 2;
        case 2:
            a0->unk6 = 6;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 11);
            return 8;
        case 3:
            if (CanViewRibbonsMenu())
            {
                a0->unk6 = 9;
                sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 12);
                return 8;
            }
            else
            {
                a0->unkC = sub_81C9600;
                return 6;
            }
        case 4:
            return -1;
        }
    }
    
    if (gMain.newKeys & B_BUTTON)
        return -1;

    return 0;
}

u32 sub_81C9520(struct Pokenav1Struct *a0)
{
    if (sub_81C9814() != 0)
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        if (gUnknown_0861FC59[a0->unk2 + a0->unk0 * 6] == 2)
        {
            a0->unk6 = 6;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 11);
            return 8;
        }
        else
        {
            PlaySE(SE_HAZURE);
            return 0;
        }
    }
    
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_HAZURE);
        return 0;
    }
    
    return 0;
}

u32 sub_81C9588(struct Pokenav1Struct *a0)
{
    if (sub_81C9814() != 0)
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        u32 v0 = gUnknown_0861FC59[a0->unk2 + a0->unk0 * 6];
        if (v0 != 2 && v0 != 4)
        {
            PlaySE(SE_HAZURE);
            return 0;
        }
        else if (v0 == 2)
        {
            a0->unk6 = 6;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 11);
            return 8;
        }
        else
        {
            return -1;
        }
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return -1;
    }
    return 0;
}

u32 sub_81C9600(struct Pokenav1Struct *a0)
{
    if (sub_81C9814() != 0)
    {
        a0->unkC = sub_81C93EC();
        return 1;
    }

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        a0->unkC = sub_81C93EC();
        return 7;
    }

    return 0;
}