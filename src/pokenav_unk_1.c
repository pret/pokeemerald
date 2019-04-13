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

static bool32 sub_81C9814(struct Pokenav1Struct *a0);
static void sub_81C97F8(struct Pokenav1Struct *a0);
static void sub_81C97C0(struct Pokenav1Struct *a0);
static u32 sub_81C97BC(struct Pokenav1Struct *a0);
static void sub_81C97B0(struct Pokenav1Struct *a0, u32 a1);
static u32 sub_81C97A4(struct Pokenav1Struct *a0);
static u32 sub_81C9798(struct Pokenav1Struct *a0);
static u32 sub_81C96FC(struct Pokenav1Struct *a0);
static u32 sub_81C963C(struct Pokenav1Struct *a0);
static u32 sub_81C9600(struct Pokenav1Struct *a0);
static u32 sub_81C9588(struct Pokenav1Struct *a0);
static u32 sub_81C9520(struct Pokenav1Struct *a0);
static u32 sub_81C943C(struct Pokenav1Struct *a0);
static u32 (*sub_81C93EC(void))(struct Pokenav1Struct*);
static void sub_81C939C(struct Pokenav1Struct *state);

static const u8 sUnknown_0861FC54[] = {2, 3, 4, 2, 5};

static const u8 sUnknown_0861FC59[][6] =
{
    { 0, 1,  4,  4,  4,  4 },
    { 0, 1,  2,  4,  4,  4 },
    { 0, 1,  2,  3,  4,  4 },
    { 5, 6,  7,  4,  4,  4 },
    { 8, 9, 10, 11, 12, 13 },
};

static u8 sub_81C9268(void)
{
    u8 retVal = 0;
    if (FlagGet(FLAG_ADDED_MATCH_CALL_TO_POKENAV))
    { 
        retVal = 1;
        if (FlagGet(FLAG_SYS_RIBBON_GET))
            retVal = 2;
    }
    
    return retVal;
}

bool32 sub_81C9298(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 0;
    state->unk4 = 0;
    state->unk6 = 0;
    sub_81C939C(state);
    return TRUE;
}

bool32 sub_81C92CC(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 2;
    state->unk4 = 2;
    state->unk6 = 0;
    sub_81C939C(state);
    return TRUE;
}

bool32 sub_81C9304(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->unk0 = sub_81C9268();
    state->unk2 = 3;
    state->unk4 = 3;
    sub_81C939C(state);
    return TRUE;
}

bool32 sub_81C9338(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->unk0 = 3;
    state->unk2 = 0;
    state->unk4 = 5;
    state->unk6 = 0;
    sub_81C939C(state);
    return TRUE;
}

bool32 sub_81C9368(void)
{
    struct Pokenav1Struct *state = AllocSubstruct(1, sizeof(struct Pokenav1Struct));
    if (!state)
        return FALSE;
    
    state->unk0 = 4;
    state->unk2 = sub_81C76AC();
    state->unk4 = state->unk2 + 8;
    state->unk6 = 0;
    sub_81C939C(state);
    return TRUE;
}

static void sub_81C939C(struct Pokenav1Struct *state)
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

static u32 (*sub_81C93EC(void))(struct Pokenav1Struct*)
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

static u32 sub_81C943C(struct Pokenav1Struct *a0)
{
    if (sub_81C9814(a0))
        return 1;

    if (gMain.newKeys & A_BUTTON)
    {
        switch (sUnknown_0861FC59[a0->unk0][a0->unk2])
        {
        case 0:
            a0->unk6 = gSaveBlock2Ptr->regionMapZoom ? 2 : 1;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 6);
            return 8;
        case 1:
            a0->unk0 = 3;
            a0->unk2 = 0;
            a0->unk4 = sUnknown_0861FC59[3][0];
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

static u32 sub_81C9520(struct Pokenav1Struct *a0)
{
    if (sub_81C9814(a0))
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        if (sUnknown_0861FC59[a0->unk0][a0->unk2] == 2)
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

static u32 sub_81C9588(struct Pokenav1Struct *a0)
{
    if (sub_81C9814(a0))
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        u32 v0 = sUnknown_0861FC59[a0->unk0][a0->unk2];
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

static u32 sub_81C9600(struct Pokenav1Struct *a0)
{
    if (sub_81C9814(a0))
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

static u32 sub_81C963C(struct Pokenav1Struct *a0)
{
    u32 v0 = sub_81C9814(a0);
    if (v0)
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        switch (sUnknown_0861FC59[a0->unk0][a0->unk2])
        {
        case 6:
            a0->unk0 = 4;
            a0->unk2 = v0;
            a0->unk4 = sUnknown_0861FC59[4][0];
            a0->unkC = sub_81C96FC;
            return 4;
        case 5:
            a0->unk6 = v0;
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 7);
            return 8;
        case 7:
            PlaySE(SE_SELECT);
            sub_81C97C0(a0);
            return 3;
        }
    }
    if (gMain.newKeys & B_BUTTON)
    {
        if (a0->unk2 != sUnknown_0861FC54[a0->unk0])
        {
            a0->unk2 = sUnknown_0861FC54[a0->unk0];
            a0->unkC = sub_81C9798;
            return 1;
        }
        else
        {
            PlaySE(SE_SELECT);
            sub_81C97C0(a0);
            return 3;
        }
    }

    return 0;
}

static u32 sub_81C96FC(struct Pokenav1Struct *a0)
{
    if (sub_81C9814(a0))
        return 1;
    
    if (gMain.newKeys & A_BUTTON)
    {
        u8 v0 = sUnknown_0861FC59[a0->unk0][a0->unk2];
        if (v0 != 13)
        {
            sub_81C7694(v0 - 8);
            sub_81C97B0(a0, UNKNOWN_POKENAV_OFFSET + 8);
            a0->unk6 = 3;
            return 8;
        }
        else
        {
            PlaySE(SE_SELECT);
            sub_81C97F8(a0);
            return 5;
        }
    }
    if (gMain.newKeys & B_BUTTON)
    {
        if (a0->unk2 != sUnknown_0861FC54[a0->unk0])
        {
            a0->unk2 = sUnknown_0861FC54[a0->unk0];
            a0->unkC = sub_81C97A4;
            return 1;
        }
        else
        {
            PlaySE(SE_SELECT);
            sub_81C97F8(a0);
            return 5;
        }
    }
    return 0;
}

static u32 sub_81C9798(struct Pokenav1Struct *a0)
{
    sub_81C97C0(a0);
    return 3;
}

static u32 sub_81C97A4(struct Pokenav1Struct *a0)
{
    sub_81C97F8(a0);
    return 5;
}

static void sub_81C97B0(struct Pokenav1Struct *a0, u32 a1)
{
    a0->unk8 = a1;
    a0->unkC = sub_81C97BC;
}

static u32 sub_81C97BC(struct Pokenav1Struct *a0)
{
    return a0->unk8;
}

static void sub_81C97C0(struct Pokenav1Struct *a0)
{
    a0->unk0 = sub_81C9268();
    a0->unk2 = 1;
    a0->unk4 = sUnknown_0861FC59[a0->unk0][a0->unk2];
    a0->unkC = sub_81C943C;
}

static void sub_81C97F8(struct Pokenav1Struct *a0)
{
    a0->unk0 = 3;
    a0->unk2 = 1;
    a0->unk4 = sUnknown_0861FC59[3][1];
    a0->unkC = sub_81C963C;
}

static bool32 sub_81C9814(struct Pokenav1Struct *a0)
{
    if (gMain.newKeys & DPAD_UP)
    {
        if (--a0->unk2 < 0)
            a0->unk2 = sUnknown_0861FC54[a0->unk0];

        a0->unk4 = sUnknown_0861FC59[a0->unk0][a0->unk2];
        return TRUE;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        a0->unk2++;
        if (a0->unk2 > sUnknown_0861FC54[a0->unk0])
            a0->unk2 = 0;

        a0->unk4 = sUnknown_0861FC59[a0->unk0][a0->unk2];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int sub_81C9894(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->unk0;
}

int sub_81C98A4(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->unk2;
}

int sub_81C98B4(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->unk4;
}

int sub_81C98C4(void)
{
    struct Pokenav1Struct *state = GetSubstructPtr(1);
    return state->unk6;
}
