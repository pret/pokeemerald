
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"

#define NELEMS(a) (s32)( sizeof (a) / sizeof (*(a)) )

// Static type declarations

typedef struct {
    u8 v0;
    u8 v1;
    u16 v2;
    void *v4;
    void *v8;
    void *vC;
} match_call_t;

// Static RAM declarations

// Static ROM declarations

// .rodata

extern const void *const gUnknown_086252A8[];
extern bool32 (*const gUnknown_086252FC[])(const match_call_t *);
extern bool8 (*const gUnknown_08625310[])(const match_call_t *);

// .text

s32 sub_81D1574(const match_call_t *matchCall)
{
    switch (matchCall->v0)
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
    const match_call_t *matchCall;
    s32 v0;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    v0 = sub_81D1574(matchCall);
    return gUnknown_086252FC[v0](matchCall);
}

bool32 sub_81D1628(const match_call_t *matchCall)
{
    if (matchCall->v2 == 0xffff)
        return TRUE;
    return FlagGet(matchCall->v2);
}

bool32 sub_81D164C(const match_call_t *matchCall)
{
    if (matchCall->v2 == 0xffff)
        return TRUE;
    return FlagGet(matchCall->v2);
}

bool32 sub_81D1670(const match_call_t *matchCall)
{
    if (matchCall->v2 == 0xffff)
        return TRUE;
    return FlagGet(matchCall->v2);
}

bool32 sub_81D1694(const match_call_t *matchCall)
{
    if (matchCall->v1 != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall->v2 == 0xffff)
        return TRUE;
    return FlagGet(matchCall->v2);
}

bool32 sub_81D16CC(const match_call_t *matchCall)
{
    return FlagGet(matchCall->v2);
}

bool8 sub_81D16DC(u32 idx)
{
    const match_call_t *matchCall;
    s32 v0;

    if (idx > 20)
        return FALSE;
    matchCall = gUnknown_086252A8[idx];
    v0 = sub_81D1574(matchCall);
    return gUnknown_08625310[v0](matchCall);
}
