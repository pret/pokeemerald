
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"

#define NELEMS(a) (s32)( sizeof (a) / sizeof (*(a)) )

// Static type declarations

typedef struct MatchCallSusbtruct0 {
    const u8 *text;
    u16 v4;
    u16 v6;
} match_call_sub0_t;

struct MatchCallStructCommon {
    u8 type;
    u8 v1;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
};

struct MatchCallStruct1 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    u8 fill6[10];
    const match_call_sub0_t *v10;
};

struct MatchCallSubstruct2 {
    u16 v0;
    u8 v2;
};

struct MatchCallStruct2 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
};

struct MatchCallStruct4 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *v4;
    const u8 *v8;
    const match_call_sub0_t *vC;
};

struct MatchCallStruct5 {
    u8 type;
    u8 v1;
    u16 flag;
    u8 fill4[12];
    const match_call_sub0_t *v10;
};

typedef union {
    struct MatchCallStructCommon *common;
    struct MatchCallStruct0 *type0;
    struct MatchCallStruct1 *type1;
    struct MatchCallStruct2 *type2;
    struct MatchCallStruct3 *type3;
    struct MatchCallStruct4 *type4;
    struct MatchCallStruct5 *type5;
} match_call_t;

struct UnkStruct_08625388 {
    u16 idx;
    u16 v2;
    u16 v4;
    const u8 *v8;
    const u8 *vC;
    const u8 *v10;
    const u8 *v14;
};

// Static RAM declarations

// Static ROM declarations

void sub_81D1920(const match_call_sub0_t *, u8 *);
void sub_81D199C(const match_call_sub0_t *, u16, u8 *);
void sub_8197080(u8 *);

// .rodata

extern const match_call_t gUnknown_086252A8[];
extern bool32 (*const gUnknown_086252FC[])(const match_call_t);
extern u8 (*const gUnknown_08625310[])(const match_call_t);
extern bool32 (*const gUnknown_08625324[])(const match_call_t);
extern bool32 (*const gUnknown_08625338[])(const match_call_t);
extern const struct UnkStruct_08625388 gUnknown_08625388[];
extern u32 (*const gUnknown_0862534C[])(const match_call_t);
extern void (*const gUnknown_08625360[])(const match_call_t, u8 *);

// .text

u32 sub_81D1574(const match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}

s32 sub_81D15BC(s32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 sub_81D15CC(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < NELEMS(gRematchTable); rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 sub_81D15F4(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_086252FC[i](matchCall);
}

bool32 sub_81D1628(match_call_t matchCall)
{
    if (matchCall.type0->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type0->flag);
}

bool32 sub_81D164C(match_call_t matchCall)
{
    if (matchCall.type1->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type1->flag);
}

bool32 sub_81D1670(match_call_t matchCall)
{
    if (matchCall.type2->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type2->flag);
}

bool32 sub_81D1694(match_call_t matchCall)
{
    if (matchCall.type4->v1 != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type4->flag);
}

bool32 sub_81D16CC(match_call_t matchCall)
{
    return FlagGet(matchCall.type3->flag);
}

u8 sub_81D16DC(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_08625310[i](matchCall);
}

u8 sub_81D1714(match_call_t matchCall)
{
    return matchCall.type0->v1;
}

u8 sub_81D1718(match_call_t matchCall)
{
    return matchCall.type1->v1;
}

u8 sub_81D171C(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.type2->v10[i].v0 != 0xffff; i++)
    {
        if (!FlagGet(matchCall.type2->v10[i].v0))
            break;
    }
    return matchCall.type2->v10[i].v2;
}

u8 sub_81D1750(match_call_t matchCall)
{
    return 0xd5;
}

u8 sub_81D1754(match_call_t matchCall)
{
    return 0xd5;
}

bool32 sub_81D1758(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return 0;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_08625324[i](matchCall);
}

bool32 sub_81D178C(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1790(match_call_t matchCall)
{
    if (matchCall.type1->v4 > 0x48)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.type1->v4] ? TRUE : FALSE;
}

bool32 sub_81D17C0(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.type2->v4] ? TRUE : FALSE;
}

bool32 sub_81D17E0(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E4(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E8(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    if (gUnknown_08625338[i](matchCall))
        return TRUE;
    for (i = 0; i < 4; i++)
    {
        if (gUnknown_08625388[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

bool32 sub_81D1840(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1844(match_call_t matchCall)
{
    return TRUE;
}

bool32 sub_81D1848(match_call_t matchCall)
{
    return TRUE;
}

bool32 sub_81D184C(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D1850(match_call_t matchCall)
{
    return FALSE;
}

u32 sub_81D1854(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return ARRAY_COUNT(gRematchTable);
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_0862534C[i](matchCall);
}

u32 sub_81D1888(match_call_t matchCall)
{
    return ARRAY_COUNT(gRematchTable);
}

u32 sub_81D188C(match_call_t matchCall)
{
    return matchCall.type1->v4;
}

u32 sub_81D1890(match_call_t matchCall)
{
    return matchCall.type2->v4;
}

u32 sub_81D1894(match_call_t matchCall)
{
    return ARRAY_COUNT(gRematchTable);
}

u32 sub_81D1898(match_call_t matchCall)
{
    return ARRAY_COUNT(gRematchTable);
}

void sub_81D189C(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    gUnknown_08625360[i](matchCall, dest);
}

void sub_81D18D0(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type0->vC, dest);
}

void sub_81D18DC(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != 5)
        sub_81D1920(matchCall.type5->v10, dest);
    else
        sub_81D199C(matchCall.type1->v10, matchCall.type1->v4, dest);
}

void sub_81D18FC(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type2->vC, dest);
}

void sub_81D1908(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type4->vC, dest);
}

void sub_81D1914(match_call_t matchCall, u8 *dest)
{
    sub_8197080(dest);
}
