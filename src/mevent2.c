#include "global.h"
#include "util.h"
#include "main.h"
#include "constants/species.h"
#include "event_data.h"
#include "easy_chat.h"
#include "script.h"
#include "battle_tower.h"
#include "menews_jisan.h"
#include "string_util.h"
#include "new_game.h"
#include "mevent.h"

static EWRAM_DATA bool32 gUnknown_02022C70 = FALSE;

extern const u16 gUnknown_082F0DE8[];

void sub_801B180(void);
void sub_801B14C(void);
bool32 sub_801B114(const struct MEventBuffer_3120_Sub * data);
bool32 sub_801B2CC(const struct MEventBuffer_32E0_Sub * data);
void sub_801B330(void);
void sub_801B368(void);
void sub_801B9F8(void);
void sub_8144824(u32 a0, u32 a1, u32 * a2, s32 a3);

void sub_801AFD8(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->unk_322C, sizeof(gSaveBlock1Ptr->unk_322C));
    sub_801B180();
    sub_811F8BC();
}

struct MEventBuffer_3120_Sub * sub_801B00C(void)
{
    return &gSaveBlock1Ptr->unk_322C.buffer_000.data;
}

struct MEventBuffer_32E0_Sub * sav1_get_mevent_buffer_1(void)
{
    return &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
}

struct MEventBuffer_3430_Sub * sav1_get_mevent_buffer_2(void)
{
    return &gSaveBlock1Ptr->unk_322C.buffer_310.data;
}

struct MysteryEventStruct * sub_801B044(void)
{
    return &gSaveBlock1Ptr->unk_322C.unk_340;
}

u16 * sub_801B058(void)
{
    return gSaveBlock1Ptr->unk_322C.unk_338;
}

void sub_801B06C(void)
{
    sub_801B14C();
}

bool32 sub_801B078(const struct MEventBuffer_3120_Sub * src)
{
    if (!sub_801B114(src))
        return FALSE;
    sub_801B14C();
    gSaveBlock1Ptr->unk_322C.buffer_000.data = *src;
    gSaveBlock1Ptr->unk_322C.buffer_000.crc = CalcCRC16WithTable((void *)&gSaveBlock1Ptr->unk_322C.buffer_000.data, sizeof(struct MEventBuffer_3120_Sub));
    return TRUE;
}

bool32 sub_801B0CC(void)
{
    if (CalcCRC16WithTable((void *)&gSaveBlock1Ptr->unk_322C.buffer_000.data, sizeof(struct MEventBuffer_3120_Sub)) != gSaveBlock1Ptr->unk_322C.buffer_000.crc)
        return FALSE;
    if (!sub_801B114(&gSaveBlock1Ptr->unk_322C.buffer_000.data))
        return FALSE;
    return TRUE;
}

bool32 sub_801B114(const struct MEventBuffer_3120_Sub * data)
{
    if (data->unk_00 == 0)
        return FALSE;
    return TRUE;
}

bool32 sub_801B128(void)
{
    const struct MEventBuffer_3120_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_000.data;
    if (data->unk_02 == 0)
        return FALSE;
    return TRUE;
}

void sub_801B14C(void)
{
    CpuFill32(0, sub_801B00C(), sizeof(gSaveBlock1Ptr->unk_322C.buffer_000.data));
    gSaveBlock1Ptr->unk_322C.buffer_000.crc = 0;
}

void sub_801B180(void)
{
    CpuFill32(0, sub_801B044(), sizeof(struct MysteryEventStruct));
    sub_801DBC0();
}

bool32 sub_801B1A4(const u8 * src)
{
    const u8 * r5 = (const u8 *)&gSaveBlock1Ptr->unk_322C.buffer_000.data;
    u32 i;
    if (!sub_801B0CC())
        return FALSE;
    for (i = 0; i < sizeof(struct MEventBuffer_3120_Sub); i++)
    {
        if (r5[i] != src[i])
            return FALSE;
    }
    return TRUE;
}

void sub_801B1E8(void)
{
    sub_801B330();
    sub_801B368();
    sub_801B9F8();
    ClearRamScript();
    sub_809D4D8();
    sub_809D570();
    ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);
}

bool32 sub_801B21C(const struct MEventBuffer_32E0_Sub * data)
{
    struct MEventBuffer_3430_Sub * r2;
    struct MEventBuffer_32E0_Sub * r1;
    if (!sub_801B2CC(data))
        return FALSE;
    sub_801B1E8();
    memcpy(&gSaveBlock1Ptr->unk_322C.buffer_1c0.data, data, sizeof(struct MEventBuffer_32E0_Sub));
    gSaveBlock1Ptr->unk_322C.buffer_1c0.crc = CalcCRC16WithTable((void *)&gSaveBlock1Ptr->unk_322C.buffer_1c0.data, sizeof(struct MEventBuffer_32E0_Sub));
    r2 = &gSaveBlock1Ptr->unk_322C.buffer_310.data;
    r1 = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
    r2->unk_06 = r1->unk_02;
    return TRUE;
}

bool32 sub_801B27C(void)
{
    if (gSaveBlock1Ptr->unk_322C.buffer_1c0.crc != CalcCRC16WithTable((void *)&gSaveBlock1Ptr->unk_322C.buffer_1c0.data, sizeof(struct MEventBuffer_32E0_Sub)))
        return FALSE;
    if (!sub_801B2CC(&gSaveBlock1Ptr->unk_322C.buffer_1c0.data))
        return FALSE;
    if (!sub_80991F8())
        return FALSE;
    return TRUE;
}

bool32 sub_801B2CC(const struct MEventBuffer_32E0_Sub * data)
{
    if (data->unk_00 == 0)
        return FALSE;
    if (data->unk_08_0 > 2)
        return FALSE;
    if (!(data->unk_08_6 == 0 || data->unk_08_6 == 1 || data->unk_08_6 == 2))
        return FALSE;
    if (data->unk_08_2 > 7)
        return FALSE;
    if (data->unk_09 > 7)
        return FALSE;
    return TRUE;
}

bool32 sub_801B308(void)
{
    const struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
    if (data->unk_08_6 == 0)
        return FALSE;
    return TRUE;
}

void sub_801B330(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->unk_322C.buffer_1c0.data, sizeof(struct MEventBuffer_32E0_Sub));
    gSaveBlock1Ptr->unk_322C.buffer_1c0.crc = 0;
}

void sub_801B368(void)
{
    CpuFill32(0, sav1_get_mevent_buffer_2(), 18 * sizeof(u16));
    gSaveBlock1Ptr->unk_322C.buffer_310.crc = 0;
}

u16 sub_801B39C(void)
{
    if (sub_801B27C())
        return gSaveBlock1Ptr->unk_322C.buffer_1c0.data.unk_00;
    return 0;
}

void sub_801B3C0(struct MEventBuffer_32E0_Sub * buffer)
{
    if (buffer->unk_08_6 == 1)
        buffer->unk_08_6 = 0;
}

bool32 sub_801B3D8(u16 a0)
{
    if (a0 >= 1000 && a0 < 1020)
        return TRUE;
    return FALSE;
}

bool32 sub_801B3F8(void)
{
    u16 value = sub_801B39C();
    if (!sub_801B3D8(value))
        return FALSE;
    if (FlagGet(gUnknown_082F0DE8[value - 1000]) == TRUE)
        return FALSE;
    return TRUE;
}

s32 sub_801B438(const struct MEventBuffer_3430_Sub * data, s32 size)
{
    s32 r3 = 0;
    s32 i;
    for (i = 0; i < size; i++)
    {
        if (data->unk_08[1][i] && data->unk_08[0][i])
            r3++;
    }
    return r3;
}

bool32 sub_801B460(const struct MEventBuffer_3430_Sub * data1, const u16 * data2, s32 size)
{
    s32 i;
    for (i = 0; i < size; i++)
    {
        if (data1->unk_08[1][i] == data2[1])
            return TRUE;
        if (data1->unk_08[0][i] == data2[0])
            return TRUE;
    }
    return FALSE;
}

bool32 sub_801B4A4(const u16 * data)
{
    if (data[1] == 0)
        return FALSE;
    if (data[0] == 0)
        return FALSE;
    if (data[0] >= NUM_SPECIES)
        return FALSE;
    return TRUE;
}

s32 sub_801B4CC(void)
{
    struct MEventBuffer_32E0_Sub * data;
    if (!sub_801B27C())
        return 0;
    data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
    if (data->unk_08_0 != 1)
        return 0;
    return sub_801B438(&gSaveBlock1Ptr->unk_322C.buffer_310.data, data->unk_09);
}

bool32 sub_801B508(const u16 * data)
{
    struct MEventBuffer_32E0_Sub * buffer = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
    s32 size = buffer->unk_09;
    s32 i;
    if (!sub_801B4A4(data))
        return FALSE;
    if (sub_801B460(&gSaveBlock1Ptr->unk_322C.buffer_310.data, data, size))
        return FALSE;
    for (i = 0; i < size; i++)
    {
        if (gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_08[1][i] == 0 && gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_08[0][i] == 0)
        {
            gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_08[1][i] = data[1];
            gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_08[0][i] = data[0];
            return TRUE;
        }
    }
    return FALSE;
}

void sub_801B580(struct MEventStruct_Unk1442CC * data, bool32 a1)
{
    s32 i;
    CpuFill32(0, data, sizeof(struct MEventStruct_Unk1442CC));
    data->unk_00 = 0x101;
    data->unk_04 = 1;
    data->unk_08 = 1;

    if (a1)
    {
        data->unk_0C = 5;
        data->unk_10 = 0x0201;
    }
    else
    {
        data->unk_0C = 4;
        data->unk_10 = 0x0200;
    }

    if (sub_801B27C())
    {
        data->unk_14 = sav1_get_mevent_buffer_1()->unk_00;
        data->unk_20 = *sav1_get_mevent_buffer_2();
        data->unk_44 = sav1_get_mevent_buffer_1()->unk_09;
    }
    else
        data->unk_14 = 0;
    for (i = 0; i < 4; i++)
        data->unk_16[i] = gSaveBlock1Ptr->unk_322C.unk_338[i];
    CopyTrainerId(data->unk_4C, gSaveBlock2Ptr->playerTrainerId);
    StringCopy(data->unk_45, gSaveBlock2Ptr->playerName);
    for (i = 0; i < 6; i++)
        data->unk_50[i] = gSaveBlock1Ptr->unk2BB0[i];
    memcpy(data->unk_5C, RomHeaderGameCode, 4);
    data->unk_60 = RomHeaderSoftwareVersion;
}

bool32 sub_801B6A0(const struct MEventStruct_Unk1442CC * data, bool32 a1)
{
    if (data->unk_00 != 0x101)
        return FALSE;
    if (!(data->unk_04 & 1))
        return FALSE;
    if (!(data->unk_08 & 1))
        return FALSE;
    if (!a1)
    {
        if (!(data->unk_0C & 4))
            return FALSE;
        if (!(data->unk_10 & 0x380))
            return FALSE;
    }
    return TRUE;
}

u32 sub_801B6EC(const u16 * a0, const struct MEventStruct_Unk1442CC * a1, void * unused)
{
    if (a1->unk_14 == 0)
        return 0;
    if (*a0 == a1->unk_14)
        return 1;
    return 2;
}

u32 sub_801B708(const u16 * a0, const struct MEventStruct_Unk1442CC * a1, void * unused)
{
    s32 r4 = a1->unk_44 - sub_801B438(&a1->unk_20, a1->unk_44);
    if (r4 == 0)
        return 1;
    if (sub_801B460(&a1->unk_20, a0, a1->unk_44))
        return 3;
    if (r4 == 1)
        return 4;
    return 2;
}

bool32 sub_801B748(const struct MEventStruct_Unk1442CC * a0, const u16 * a1)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        if (a0->unk_16[i] != a1[i])
            return FALSE;
    }
    return TRUE;
}

s32 sub_801B770(const struct MEventStruct_Unk1442CC * a0)
{
    return sub_801B438(&a0->unk_20, a0->unk_44);
}

u16 sub_801B784(const struct MEventStruct_Unk1442CC * a0, u32 command)
{
    switch (command)
    {
        case 0:
            return a0->unk_20.unk_00;
        case 1:
            return a0->unk_20.unk_02;
        case 2:
            return a0->unk_20.unk_04;
        case 3:
            return sub_801B770(a0);
        case 4:
            return a0->unk_44;
        default:
            AGB_ASSERT(0);
            return 0;
    }
}

void sub_801B7D8(u32 command)
{
    struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
    if (data->unk_08_0 == 2)
    {
        u16 * dest = NULL;
        switch (command)
        {
            case 0:
                dest = &gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_00;
                break;
            case 1:
                dest = &gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_02;
                break;
            case 2:
                dest = &gSaveBlock1Ptr->unk_322C.buffer_310.data.unk_04;
                break;
            case 3:
                break;
            case 4:
                break;
        }
        if (dest == NULL)
        {
            AGB_ASSERT(0);
        }
        else if (++(*dest) > 999)
        {
            *dest = 999;
        }
    }
}

u16 mevent_081445C0(u32 command)
{
    switch (command)
    {
        case 0:
        {
            struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
            if (data->unk_08_0 == 2)
            {
                struct MEventBuffer_3430_Sub * buffer = &gSaveBlock1Ptr->unk_322C.buffer_310.data;
                return buffer->unk_00;
            }
            break;
        }
        case 1:
        {
            struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
            if (data->unk_08_0 == 2)
            {
                struct MEventBuffer_3430_Sub * buffer = &gSaveBlock1Ptr->unk_322C.buffer_310.data;
                return buffer->unk_02;
            }
            break;
        }
        case 2:
        {
            struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
            if (data->unk_08_0 == 2)
            {
                struct MEventBuffer_3430_Sub * buffer = &gSaveBlock1Ptr->unk_322C.buffer_310.data;
                return buffer->unk_04;
            }
            break;
        }
        case 3:
        {
            struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
            if (data->unk_08_0 == 1)
                return sub_801B4CC();
            break;
        }
        case 4:
        {
            struct MEventBuffer_32E0_Sub * data = &gSaveBlock1Ptr->unk_322C.buffer_1c0.data;
            if (data->unk_08_0 == 1)
                return data->unk_09;
            break;
        }
    }
    AGB_ASSERT(0);
    return 0;
}

void sub_801B940(void)
{
    gUnknown_02022C70 = FALSE;
}

bool32 sub_801B94C(u16 a0)
{
    gUnknown_02022C70 = FALSE;
    if (a0 == 0)
        return FALSE;
    if (!sub_801B27C())
        return FALSE;
    if (gSaveBlock1Ptr->unk_322C.buffer_1c0.data.unk_00 != a0)
        return FALSE;
    gUnknown_02022C70 = TRUE;
    return TRUE;
}

void sub_801B990(u32 a0, u32 a1)
{
    if (gUnknown_02022C70)
    {
        switch (a0)
        {
            case 2:
                sub_8144824(2, a1, gSaveBlock1Ptr->unk_322C.unk_344[1], 5);
                break;
            case 0:
                sub_8144824(0, a1, gSaveBlock1Ptr->unk_322C.unk_344[0], 5);
                break;
            case 1:
                sub_8144824(1, a1, gSaveBlock1Ptr->unk_322C.unk_344[0], 5);
                break;
            default:
                AGB_ASSERT(0);
        }
    }
}

void sub_801B9F8(void)
{
    CpuFill32(0, gSaveBlock1Ptr->unk_322C.unk_344, sizeof(gSaveBlock1Ptr->unk_322C.unk_344));
}

bool32 sub_801BA24(u32 a0, u32 * a1, s32 size)
{
    s32 i;
    s32 j;

    for (i = 0; i < size; i++)
    {
        if (a1[i] == a0)
            break;
    }
    if (i == size)
    {
        for (j = size - 1; j > 0; j--)
        {
            a1[j] = a1[j - 1];
        }
        a1[0] = a0;
        return TRUE;
    }
    else
    {
        for (j = i; j > 0; j--)
        {
            a1[j] = a1[j - 1];
        }
        a1[0] = a0;
        return FALSE;
    }
}

void sub_8144824(u32 a0, u32 a1, u32 * a2, s32 a3)
{
    if (sub_801BA24(a1, a2, a3))
        sub_801B7D8(a0);
}

