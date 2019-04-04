#include "global.h"
#include "alloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "union_room.h"
#include "save.h"
#include "sprite.h"
#include "task.h"
#include "util.h"

struct Unknown030012C8
{
    u8 unk0[8];
    u32 *unk8;
    int unkC;
    int unk10;
    int unk14;
};

static void sub_81D4170(void);
static u16 sub_81D3EE8(u8);
static void sub_81D413C(void);
static void sub_81D414C(void);
static void sub_81D3F1C(u32, u32*, u32*);
static void sub_81D3F68(void);

IWRAM_DATA struct Unknown030012C8 gUnknown_030012C8;
IWRAM_DATA u16 gUnknown_030012E0;
IWRAM_DATA u16 gUnknown_030012E2;
IWRAM_DATA u16 gUnknown_030012E4;
IWRAM_DATA u16 gUnknown_030012E6;
IWRAM_DATA u32 gUnknown_030012E8;
IWRAM_DATA u16 gUnknown_030012EC;
IWRAM_DATA u16 gUnknown_030012EE;
IWRAM_DATA u16 gUnknown_030012F0;
IWRAM_DATA u16 gUnknown_030012F2;
IWRAM_DATA u16 gUnknown_030012F4;

extern const u8 gUnknown_08625B6C[][0x148];

static u8 sub_81D38D4(void)
{
    return (gSaveBlock1Ptr->trainerHill.unused + 1) % 256;
}

static bool32 Struct_Unk81D38FC_ValidateChecksum(struct Unk81D38FC *arg0)
{
    int checksum = CalcByteArraySum((u8 *)arg0, 0x270);
    if (checksum != arg0->checksum)
        return FALSE;

    return TRUE;
}

bool8 EReader_IsReceivedDataValid(struct EReaderTrainerHillSet *buffer)
{
    u32 i;
    u32 checksum;
    int var0 = buffer->unk_0;
    if (var0 < 1 || var0 > 8)
        return FALSE;

    for (i = 0; i < var0; i++)
    {
        if (!Struct_Unk81D38FC_ValidateChecksum(&buffer->unk_8[i]))
            return FALSE;
    }

    checksum = CalcByteArraySum((u8 *)buffer->unk_8, var0 * sizeof(struct Unk81D38FC));
    if (checksum != buffer->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TrainerHill_VerifyChecksum(struct EReaderTrainerHillSet *buffer)
{
    u32 checksum;
    int var0 = buffer->unk_0;
    if (var0 < 1 || var0 > 8)
        return FALSE;

    checksum = CalcByteArraySum((u8 *)buffer->unk_8, sizeof(struct EReaderTrainerHillSet) - offsetof(struct EReaderTrainerHillSet, unk_8));
    if (checksum != buffer->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TryWriteTrainerHill_r(struct EReaderTrainerHillSet *arg0, struct Unk81D3998 *buffer2)
{
    int i;

    memset(buffer2, 0, 0x1000);
    buffer2->unk_000 = arg0->unk_0;
    buffer2->unk_001 = sub_81D38D4();
    buffer2->unk_002 = (arg0->unk_0 + 1) / 2;

    for (i = 0; i < arg0->unk_0; i++)
    {
        if (!(i & 1))
        {
            buffer2->unk_008[i / 2].unk_000[0] = arg0->unk_8[i].unk0;
            memcpy(buffer2->unk_008[i / 2].unk_294, arg0->unk_8[i].unk14C, 0x124);
            memcpy(buffer2->unk_008[i / 2].unk_004, arg0->unk_8[i].unk4, 0x148);
        }
        else
        {
            buffer2->unk_008[i / 2].unk_000[1] = arg0->unk_8[i].unk0;
            memcpy(buffer2->unk_008[i / 2].unk_14C, arg0->unk_8[i].unk4, 0x148);
        }
    }

    if (i & 1)
    {
        u8 * dest = buffer2->unk_008[i / 2].unk_14C;
        const u8 (* src)[0x148] = gUnknown_08625B6C;
        memcpy(dest, src[i / 2], 0x148);
    }

    buffer2->checksum = CalcByteArraySum((u8 *)buffer2->unk_008, sizeof(struct Unk81D3998) - offsetof(struct Unk81D3998, unk_008));
    if (TryWriteSpecialSaveSection(SECTOR_ID_TRAINER_HILL, (u8 *)buffer2) != 1)
        return FALSE;

    return TRUE;
}

bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *arg0)
{
    struct Unk81D3998 *var0 = AllocZeroed(0x1000);
    bool32 result = TryWriteTrainerHill_r(arg0, var0);
    Free(var0);
    return result;
}

static bool32 TryReadTrainerHill_r(struct EReaderTrainerHillSet *arg0, u8 *arg1)
{
    if (TryReadSpecialSaveSection(SECTOR_ID_TRAINER_HILL, arg1) != 1)
        return FALSE;

    memcpy(arg0, arg1, sizeof(struct EReaderTrainerHillSet));
    if (!TrainerHill_VerifyChecksum(arg0))
        return FALSE;

    return TRUE;
}

static bool32 TryReadTrainerHill(struct EReaderTrainerHillSet *arg0)
{
    u8 *var0 = AllocZeroed(0x1000);
    bool32 result = TryReadTrainerHill_r(arg0, var0);
    Free(var0);
    return result;
}

bool32 ReadTrainerHillAndValidate(void)
{
    struct EReaderTrainerHillSet *var0 = AllocZeroed(0x1000);
    bool32 result = TryReadTrainerHill(var0);
    Free(var0);
    return result;
}

static int unref_sub_81D3B54(int arg0, u32 *arg1)
{
    int result;
    u16 var0;
    int var1;

    sub_81D41A0();
    while (1)
    {
        sub_81D4170();
        if (gUnknown_030012E2 & 2)
            gShouldAdvanceLinkState = 2;

        var1 = sub_81D3D70(1, arg0, arg1, NULL);
        gUnknown_030012E4 = var1;
        if ((gUnknown_030012E4 & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (gUnknown_030012E4 & 0x8)
        {
            result = 1;
            break;
        }

        var0 = gUnknown_030012E4 & 0x4;
        if (var0)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = var0;
        VBlankIntrWait();
    }

    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
    sub_81D41F4();
    return result;
}

static int unref_sub_81D3BE8(u32 *arg0)
{
    int result;
    u16 var0;
    int var1;

    sub_81D41A0();
    while (1)
    {
        sub_81D4170();
        if (gUnknown_030012E2 & 2)
            gShouldAdvanceLinkState = 2;

        var1 = sub_81D3D70(0, 0, NULL, arg0);
        gUnknown_030012E4 = var1;
        if ((gUnknown_030012E4 & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (gUnknown_030012E4 & 0x8)
        {
            result = 1;
            break;
        }

        var0 = gUnknown_030012E4 & 0x4;
        if (var0)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = var0;
        VBlankIntrWait();
    }

    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
    sub_81D41F4();
    return result;
}

static void sub_81D3C7C(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

static void sub_81D3CBC(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;

    if (!gUnknown_030012C8.unk0[1])
        CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
}

static void sub_81D3D34(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_INTR_ENABLE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    gUnknown_030012E6 = 0;
    gUnknown_030012E8 = 0;
}

int sub_81D3D70(u8 arg0, u32 arg1, u32 *arg2, u32 *arg3)
{
    switch (gUnknown_030012C8.unk0[1])
    {
    case 0:
        sub_81D3CBC();
        gUnknown_030012C8.unk0[2] = 1;
        gUnknown_030012C8.unk0[1] = 1;
        break;
    case 1:
        if (sub_81D3EE8(arg0))
            sub_81D413C();

        if (gShouldAdvanceLinkState == 2)
        {
            gUnknown_030012C8.unk0[4] = 2;
            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    case 2:
        sub_81D3D34();
        sub_81D3F1C(arg1, arg2, arg3);
        gUnknown_030012C8.unk0[1] = 3;
        // fall through
    case 3:
        if (gShouldAdvanceLinkState == 2)
        {
            gUnknown_030012C8.unk0[4] = 2;
            gUnknown_030012C8.unk0[1] = 6;
        }
        else
        {
            gUnknown_030012E6++;
            gUnknown_030012E8++;
            if (!gUnknown_030012C8.unk0[0] && gUnknown_030012E8 > 60)
            {
                gUnknown_030012C8.unk0[4] = 1;
                gUnknown_030012C8.unk0[1] = 6;
            }

            if (gUnknown_030012C8.unk0[2] != 2)
            {
                if (gUnknown_030012C8.unk0[0] && gUnknown_030012E6 > 2)
                {
                    sub_81D413C();
                    gUnknown_030012C8.unk0[2] = 2;
                }
                else
                {
                    sub_81D413C();
                    gUnknown_030012C8.unk0[2] = 2;
                }
            }
        }
        break;
    case 4:
        sub_81D3CBC();
        gUnknown_030012C8.unk0[1] = 5;
        break;
    case 5:
        if (gUnknown_030012C8.unk0[0] == 1 && gUnknown_030012E6 > 2)
            sub_81D413C();

        if (++gUnknown_030012E6 > 60)
        {
            gUnknown_030012C8.unk0[4] = 1;
            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    case 6:
        if (gUnknown_030012C8.unk0[2])
        {
            sub_81D3C7C();
            gUnknown_030012C8.unk0[2] = 0;
        }
        break;
    }

    return gUnknown_030012C8.unk0[2] | (gUnknown_030012C8.unk0[4] << 2) | (gUnknown_030012C8.unk0[3] << 4);
}

static u16 sub_81D3EE8(u8 arg0)
{
    u16 terminal = (*(vu32 *)REG_ADDR_SIOCNT) & (SIO_MULTI_SI | SIO_MULTI_SD);
    if (terminal == SIO_MULTI_SD && arg0)
    {
        gUnknown_030012C8.unk0[0] = 1;
        return 1;
    }
    else
    {
        gUnknown_030012C8.unk0[0] = 0;
        return 0;
    }
}

static void sub_81D3F1C(u32 arg0, u32 *arg1, u32 *arg2)
{
    if (gUnknown_030012C8.unk0[0])
    {
        REG_SIOCNT |= SIO_38400_BPS;
        gUnknown_030012C8.unk8 = arg1;
        REG_SIODATA32 = arg0;
        gUnknown_030012C8.unk10 = arg0 / 4 + 1;
        sub_81D3F68();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        gUnknown_030012C8.unk8 = arg2;
    }
}

static void sub_81D3F68(void)
{
    REG_TM3CNT_L = 0xFDA7;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void sub_81D3F9C(void)
{
    sub_81D414C();
    sub_81D413C();
}

void sub_81D3FAC(void)
{
    u16 i, playerCount, k;
    u32 value;
    u16 var0;
    u16 recvBuffer[4];

    switch (gUnknown_030012C8.unk0[1])
    {
    case 1:
        REG_SIOMLT_SEND = 0xCCD0; // Handshake id
        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        for (i = 0, playerCount = 0, k = 0; i < 4; i++)
        {
            if (recvBuffer[i] == 0xCCD0)
                playerCount++;
            else if (recvBuffer[i] != 0xFFFF)
                k++;
        }

        if (playerCount == 2 && k == 0)
            gUnknown_030012C8.unk0[1] = 2;
        break;
    case 3:
        value = REG_SIODATA32;
        if (!gUnknown_030012C8.unkC && !gUnknown_030012C8.unk0[0])
            gUnknown_030012C8.unk10 = value / 4 + 1;

        if (gUnknown_030012C8.unk0[0] == 1)
        {
            if (gUnknown_030012C8.unkC < gUnknown_030012C8.unk10)
            {
                REG_SIODATA32 = gUnknown_030012C8.unk8[gUnknown_030012C8.unkC];
                gUnknown_030012C8.unk14 += gUnknown_030012C8.unk8[gUnknown_030012C8.unkC];
            }
            else
            {
                REG_SIODATA32 = gUnknown_030012C8.unk14;
            }
        }
        else
        {
            if (gUnknown_030012C8.unkC > 0 && gUnknown_030012C8.unkC < gUnknown_030012C8.unk10 + 1)
            {
                gUnknown_030012C8.unk8[gUnknown_030012C8.unkC - 1] = value;
                gUnknown_030012C8.unk14 += value;
            }
            else if (gUnknown_030012C8.unkC)
            {
                if (gUnknown_030012C8.unk14 == value)
                    gUnknown_030012C8.unk0[3] = 1;
                else
                    gUnknown_030012C8.unk0[3] = 2;
            }

            gUnknown_030012E8 = 0;
        }

        if (++gUnknown_030012C8.unkC < gUnknown_030012C8.unk10 + 2)
        {
            if (gUnknown_030012C8.unk0[0])
                REG_TM3CNT_H |= TIMER_ENABLE;
            else
                sub_81D413C();
        }
        else
        {
            gUnknown_030012C8.unk0[1] = 4;
            gUnknown_030012E6 = 0;
        }
        break;
    case 5:
        if (!gUnknown_030012C8.unk0[0])
            REG_SIOMLT_SEND = gUnknown_030012C8.unk0[3];

        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        var0 = recvBuffer[1] - 1;
        if (var0 < 2)
        {
            if (gUnknown_030012C8.unk0[0] == 1)
                gUnknown_030012C8.unk0[3] = recvBuffer[1];

            gUnknown_030012C8.unk0[1] = 6;
        }
        break;
    }
}

static void sub_81D413C(void)
{
    REG_SIOCNT |= SIO_ENABLE;
}

static void sub_81D414C(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFDA7;
}

static void sub_81D4170(void)
{
    int keysMask = REG_KEYINPUT ^ KEYS_MASK;
    gUnknown_030012E2 = keysMask & ~gUnknown_030012E0;
    gUnknown_030012E0 = keysMask;
}

void sub_81D41A0(void)
{
    gUnknown_030012EC = REG_IME;
    gUnknown_030012EE = REG_IE;
    gUnknown_030012F0 = REG_TM3CNT_H;
    gUnknown_030012F2 = REG_SIOCNT;
    gUnknown_030012F4 = REG_RCNT;
}

void sub_81D41F4(void)
{
    REG_IME = gUnknown_030012EC;
    REG_IE = gUnknown_030012EE;
    REG_TM3CNT_H = gUnknown_030012F0;
    REG_SIOCNT = gUnknown_030012F2;
    REG_RCNT = gUnknown_030012F4;
}

void sub_81D4238(void)
{
    CpuFill32(0, &gUnknown_030012C8, sizeof(struct Unknown030012C8));
}
