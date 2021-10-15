#include "global.h"
#include "mevent.h"
#include "random.h"
#include "event_data.h"
#include "mevent_news.h"

static u32 sub_801DCAC(struct WonderNewsMetadata *);
static void sub_801DD10(struct WonderNewsMetadata *);
static u32 sub_801DD44(struct WonderNewsMetadata *);
static void sub_801DCD8(struct WonderNewsMetadata *);
static void sub_801DCCC(struct WonderNewsMetadata *);

void GenerateRandomWonderNews(u32 a0)
{
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();

    data->unk_0_0 = a0;
    switch (a0)
    {
    case 0:
        break;
    case 1:
    case 2:
        data->unk_1 = (Random() % 15) + 16;
        break;
    case 3:
        data->unk_1 = (Random() % 15) + 1;
        break;
    }
}

void InitSavedWonderNews(void)
{
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();

    data->unk_0_0 = 0;
    data->unk_0_2 = 0;
    data->unk_0_5 = 0;
    data->unk_1 = 0;
    VarSet(VAR_0x402E, 0);
}

void sub_801DBDC(void)
{
    u16 *r4 = GetVarPointer(VAR_0x402E);
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();
    struct WonderNewsMetadata r0 = *data;

    if ((u8)r0.unk_0_5 > 4 && ++(*r4) > 0x1f3)
    {
        data->unk_0_5 = 0;
        *r4 = 0;
    }
}

// Unused
u16 sub_801DC20(void)
{
    u16 *r6 = &gSpecialVar_Result;
    struct WonderNewsMetadata *data = GetSavedWonderNewsMetadata();
    u16 r5;

    if (!IsMysteryEventEnabled() || !ValidateSavedWonderNews())
        return 0;

    r5 = sub_801DD44(data);

    switch (r5)
    {
    case 0:
        break;
    case 1:
        *r6 = sub_801DCAC(data);
        break;
    case 2:
        *r6 = sub_801DCAC(data);
        break;
    case 3:
        break;
    case 4:
        *r6 = sub_801DCAC(data);
        sub_801DCD8(data);
        break;
    case 5:
        *r6 = sub_801DCAC(data);
        sub_801DCCC(data);
        break;
    case 6:
        break;
    }

    return r5;
}

static u32 sub_801DCAC(struct WonderNewsMetadata *data)
{
    u32 r4;

    data->unk_0_0 = 0;
    r4 = data->unk_1 + 0x84;
    data->unk_1 = 0;
    sub_801DD10(data);
    return r4;
}

static void sub_801DCCC(struct WonderNewsMetadata *data)
{
    data->unk_0_2 = 0;
}

static void sub_801DCD8(struct WonderNewsMetadata *data)
{
    data->unk_0_2++;
    if ((u8)data->unk_0_2 > 4)
        data->unk_0_2 = 4;
}

static void sub_801DD10(struct WonderNewsMetadata *data)
{
    data->unk_0_5++;
    if ((u8)data->unk_0_5 > 5)
        data->unk_0_5 = 5;
}

static u32 sub_801DD44(struct WonderNewsMetadata *data)
{
    struct WonderNewsMetadata r0;
    if ((u8)data->unk_0_5 == 5)
        return 6;

    r0 = *data;
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
