#include "global.h"
#include "mevent.h"
#include "random.h"
#include "event_data.h"
#include "mevent_news.h"

static u32 sub_801DCAC(struct MysteryEventStruct *);
static void sub_801DD10(struct MysteryEventStruct *);
static u32 sub_801DD44(struct MysteryEventStruct *);
static void sub_801DCD8(struct MysteryEventStruct *);
static void sub_801DCCC(struct MysteryEventStruct *);

void GenerateRandomNews(u32 a0)
{
    struct MysteryEventStruct *r5 = sub_801B044();

    r5->unk_0_0 = a0;
    switch (a0)
    {
    case 0:
        break;
    case 1:
    case 2:
        r5->unk_1 = (Random() % 15) + 16;
        break;
    case 3:
        r5->unk_1 = (Random() % 15) + 1;
        break;
    }
}

void sub_801DBC0(void)
{
    struct MysteryEventStruct *r5 = sub_801B044();

    r5->unk_0_0 = 0;
    r5->unk_0_2 = 0;
    r5->unk_0_5 = 0;
    r5->unk_1 = 0;
    VarSet(VAR_0x402E, 0);
}

void sub_801DBDC(void)
{
    u16 *r4 = GetVarPointer(VAR_0x402E);
    struct MysteryEventStruct *r2 = sub_801B044();
    struct MysteryEventStruct r0 = *r2;

    if ((u8)r0.unk_0_5 > 4 && ++(*r4) > 0x1f3)
    {
        r2->unk_0_5 = 0;
        *r4 = 0;
    }
}

// Unused
u16 sub_801DC20(void)
{
    u16 *r6 = &gSpecialVar_Result;
    struct MysteryEventStruct *r4 = sub_801B044();
    u16 r5;

    if (!IsMysteryEventEnabled() || !ValidateReceivedWonderNews())
        return 0;

    r5 = sub_801DD44(r4);

    switch (r5)
    {
    case 0:
        break;
    case 1:
        *r6 = sub_801DCAC(r4);
        break;
    case 2:
        *r6 = sub_801DCAC(r4);
        break;
    case 3:
        break;
    case 4:
        *r6 = sub_801DCAC(r4);
        sub_801DCD8(r4);
        break;
    case 5:
        *r6 = sub_801DCAC(r4);
        sub_801DCCC(r4);
        break;
    case 6:
        break;
    }

    return r5;
}

static u32 sub_801DCAC(struct MysteryEventStruct *a0)
{
    u32 r4;

    a0->unk_0_0 = 0;
    r4 = a0->unk_1 + 0x84;
    a0->unk_1 = 0;
    sub_801DD10(a0);
    return r4;
}

static void sub_801DCCC(struct MysteryEventStruct *a0)
{
    a0->unk_0_2 = 0;
}

static void sub_801DCD8(struct MysteryEventStruct *a0)
{
    a0->unk_0_2++;
    if ((u8)a0->unk_0_2 > 4)
        a0->unk_0_2 = 4;
}

static void sub_801DD10(struct MysteryEventStruct *a0)
{
    a0->unk_0_5++;
    if ((u8)a0->unk_0_5 > 5)
        a0->unk_0_5 = 5;
}

static u32 sub_801DD44(struct MysteryEventStruct *a0)
{
    struct MysteryEventStruct r0;
    if ((u8)a0->unk_0_5 == 5)
        return 6;

    r0 = *a0;
    switch (r0.unk_0_0)
    {
    case 0:
        return 3;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        if ((u8)r0.unk_0_2 < 3)
            return 4;
        return 5;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}
