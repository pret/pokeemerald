
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"

#define NELEMS(a) (s32)( sizeof (a) / sizeof (*(a)) )

extern const u8 gTrainerClassNames[][13];

// Static type declarations

typedef struct MatchCallSusbtruct0 {
    const u8 *text;
    u16 flag;
    u16 flag2;
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
    const u8 *v8;
    const u8 *vC;
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
    u16 v4;
    const u8 *v8;
    const u8 *vC;
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
    const u8 *v8[4];
};

// Static RAM declarations

// Static ROM declarations

void sub_81D1920(const match_call_sub0_t *, u8 *);
void sub_81D199C(const match_call_sub0_t *, u16, u8 *);
void sub_8197080(u8 *);
void sub_81D1B0C(u32, const u8 **, const u8 **);

// .rodata

extern const match_call_t gUnknown_086252A8[];
extern bool32 (*const gUnknown_086252FC[])(const match_call_t);
extern u8 (*const gUnknown_08625310[])(const match_call_t);
extern bool32 (*const gUnknown_08625324[])(const match_call_t);
extern bool32 (*const gUnknown_08625338[])(const match_call_t);
extern const struct UnkStruct_08625388 gUnknown_08625388[];
extern u32 (*const gUnknown_0862534C[])(const match_call_t);
extern void (*const gUnknown_08625360[])(const match_call_t, u8 *);
extern void (*const gUnknown_08625374[])(const match_call_t, const u8 **, const u8 **);

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

u32 sub_81D15BC(u32 rematchIdx)
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
    if (matchCall.type1->v4 >= REMATCH_ELITE_FOUR_ENTRIES)
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
        return REMATCH_TABLE_ENTRIES;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    return gUnknown_0862534C[i](matchCall);
}

u32 sub_81D1888(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
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
    return REMATCH_TABLE_ENTRIES;
}

u32 sub_81D1898(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
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

void sub_81D1920(const match_call_sub0_t *sub0, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (sub0[i].flag != 0xffff && FlagGet(sub0[i].flag) == TRUE)
            break;
        i--;
    }
    if (sub0[i].flag2 != 0xffff)
        FlagSet(sub0[i].flag2);
    StringExpandPlaceholders(dest, sub0[i].text);
}

#ifdef NONMATCHING
// There's some weird upmerge going on that I cannot replicate at this time.
void sub_81D199C(const match_call_sub0_t *sub0, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
    {
        if (sub0[i].flag == 0xfffe)
            break;
        if (sub0[i].flag == 0xffff && !FlagGet(sub0[i].flag))
            break;
    }
    if (sub0[i].flag != 0xfffe)
    {
        if (i)
            i--;
        if (sub0[i].flag2 != 0xffff)
            FlagSet(sub0[i].flag2);
        StringExpandPlaceholders(dest, sub0[i].text);
    }
    else
    {
        if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            ;
        else if (gSaveBlock1Ptr->trainerRematches[idx])
            i += 2;
        else if (CountBattledRematchTeams(idx) >= 2)
            i += 3;
        else
            i++;
        StringExpandPlaceholders(dest, sub0[i].text);
    }
}
#else
ASM_DIRECT void sub_81D199C(const match_call_sub0_t *sub0, u16 idx, u8 *dest)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmov r10, r2\n"
                    "\tlsls r1, 16\n"
                    "\tlsrs r7, r1, 16\n"
                    "\tmovs r5, 0\n"
                    "\tldr r0, [r6]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r6, 0x4]\n"
                    "\tldr r1, =0x0000fffe\n"
                    "\tcmp r0, r1\n"
                    "\tbeq _081D1A24\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tmov r9, r0\n"
                    "\tmov r8, r1\n"
                    "\tadds r4, r6, 0\n"
                    "_081D19C6:\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r9\n"
                    "\tbeq _081D19D6\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "_081D19D6:\n"
                    "\tadds r4, 0x8\n"
                    "\tadds r5, 0x1\n"
                    "\tldr r0, [r4]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r8\n"
                    "\tbne _081D19C6\n"
                    "_081D19E6:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldrh r1, [r0, 0x4]\n"
                    "\tldr r0, =0x0000fffe\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A24\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _081D19F8\n"
                    "\tsubs r5, 0x1\n"
                    "_081D19F8:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r4, r0, r6\n"
                    "\tldrh r1, [r4, 0x6]\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A0A\n"
                    "\tadds r0, r1, 0\n"
                    "\tbl FlagSet\n"
                    "_081D1A0A:\n"
                    "\tldr r1, [r4]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "\tb _081D1A5C\n"
                    "\t.pool\n"
                    "_081D1A1C:\n"
                    "\tadds r5, 0x2\n"
                    "\tb _081D1A50\n"
                    "_081D1A20:\n"
                    "\tadds r5, 0x3\n"
                    "\tb _081D1A50\n"
                    "_081D1A24:\n"
                    "\tldr r0, =0x00000864\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1A50\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r0]\n"
                    "\tldr r1, =0x000009ca\n"
                    "\tadds r0, r1\n"
                    "\tadds r0, r7\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _081D1A1C\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl CountBattledRematchTeams\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _081D1A20\n"
                    "\tadds r5, 0x1\n"
                    "_081D1A50:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldr r1, [r0]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "_081D1A5C:\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_81D1A78(u32 idx, const u8 **a1, const u8 **a2)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return;
    matchCall = gUnknown_086252A8[idx];
    i = sub_81D1574(matchCall);
    gUnknown_08625374[i](matchCall, a1, a2);
}

void sub_81D1AB0(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1ABC(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.type1->vC == NULL)
        sub_81D1B0C(_matchCall.type1->v4, a1, a2);
    else
        *a2 = _matchCall.type1->vC;
    *a1 = _matchCall.type1->v8;
}

void sub_81D1ADC(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    sub_81D1B0C(matchCall.type2->v4, a1, a2);
    *a1 = matchCall.type2->v8;
}

void sub_81D1AF4(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1B00(match_call_t matchCall, const u8 **a1, const u8 **a2)
{
    *a1 = matchCall.type0->v4;
    *a2 = matchCall.type0->v8;
}

void sub_81D1B0C(u32 idx, const u8 **a1, const u8 **a2)
{
    const struct Trainer *trainer = gTrainers + sub_81D15BC(idx);
    *a1 = gTrainerClassNames[trainer->trainerClass];
    *a2 = trainer->trainerName;
}

#ifdef NONMATCHING
const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_08625388[i].idx == idx)
        {
            for (; i + 1 < 4 && gUnknown_08625388[i + 1].idx == idx; i++)
            {
                if (!FlagGet(gUnknown_08625388[i + 1].v4))
                    break;
            }
            return gUnknown_08625388[i].v8[offset];
        }
    }
    return NULL;
}
#else
ASM_DIRECT const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r9\n"
                    "\tmov r6, r8\n"
                    "\tpush {r6,r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmovs r5, 0\n"
                    "\tldr r2, =gUnknown_08625388\n"
                    "\tmovs r0, 0x8\n"
                    "\tadds r0, r2\n"
                    "\tmov r9, r0\n"
                    "_081D1B54:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BBC\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tlsls r1, 2\n"
                    "\tmov r8, r1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BA8\n"
                    "\tldr r7, =gUnknown_08625388\n"
                    "_081D1B7C:\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r1, r7, 0x4\n"
                    "\tadds r0, r1\n"
                    "\tldrh r0, [r0]\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1BA8\n"
                    "\tadds r5, r4, 0\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r7\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbeq _081D1B7C\n"
                    "_081D1BA8:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadd r0, r8\n"
                    "\tadd r0, r9\n"
                    "\tldr r0, [r0]\n"
                    "\tb _081D1BC4\n"
                    "\t.pool\n"
                    "_081D1BBC:\n"
                    "\tadds r5, 0x1\n"
                    "\tcmp r5, 0x3\n"
                    "\tbls _081D1B54\n"
                    "\tmovs r0, 0\n"
                    "_081D1BC4:\n"
                    "\tpop {r3,r4}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r1}\n"
                    "\tbx r1");
}
#endif
