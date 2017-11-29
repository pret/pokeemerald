
// Includes
#include "global.h"
#include "link.h"
#include "librfu.h"
#include "link_rfu.h"

// Static type declarations

// Static RAM declarations

struct UnkRfuStruct_1 gUnknown_03004140;
struct UnkRfuStruct_2 gUnknown_03005000;

IWRAM_DATA u8 gUnknown_03000D74;
ALIGNED(4) IWRAM_DATA u8 gUnknown_03000D78[8];
IWRAM_DATA u8 gUnknown_03000D80[16];
IWRAM_DATA u16 gUnknown_03000D90[8];

EWRAM_DATA u8 gUnknown_02022B10 = 0;
EWRAM_DATA struct UnkLinkRfuStruct_02022B14 gUnknown_02022B14 = {};
EWRAM_DATA struct UnkLinkRfuStruct_02022B2C gUnknown_02022B2C = {};

// Static ROM declarations

void sub_800C000(void);
void sub_800CEB0(u16 r6);
void sub_800C7B4(u16 r8, u16 r6);
void sub_800D30C(u8 a0, u8 a1);
void sub_800D334(u8 a0);
void sub_800D610(void);
void sub_800D630(void);
void sub_800C744(u32 a0);
void sub_800CF34(void);
static void sub_800D158(void);
void sub_800D20C(void);
void sub_800D268(void);
u8 sub_800D294(void);
void sub_800D358(void);
void sub_800D434(void);

// .rodata

// .text

u32 sub_800BEC0(void)
{
    u32 r4;

    r4 = rfu_REQBN_softReset_and_checkID();
    if (r4 == 0x8001)
    {
        gUnknown_03004140.unk_08 = 1;
    }
    if (gUnknown_03004140.unk_04 != 0x17 && gUnknown_03004140.unk_04 != 0x01)
    {
        gUnknown_03004140.unk_05 = 0;
        gUnknown_03004140.unk_04 = 0;
    }
    gUnknown_03004140.unk_07 = 0;
    gUnknown_03004140.unk_0d = 0;
    gUnknown_03004140.unk_01 = 0;
    gUnknown_03004140.unk_00 = 0;
    gUnknown_03004140.unk_06 = -1;
    sub_800D610();
    return r4;
}

void rfu_REQ_sendData_wrapper(u8 r2)
{
    u8 val;
    if (!gUnknown_03007890[0].unk_00)
    {
        val = gUnknown_03004140.unk_02;
        r2 = 0;
        if (val == 1)
        {
            r2 = 1;
        }
    }
    else
    {
        gUnknown_03004140.unk_03 = 0;
    }
    rfu_REQ_sendData(r2);
}

int sub_800BF4C(void (*func1)(u8), void (*func2)(u16))
{
    if (func1 == NULL)
    {
        return 4;
    }
    CpuFill16(0, &gUnknown_03004140, offsetof(struct UnkRfuStruct_1, filler_48));
    gUnknown_03004140.unk_06 = -1;
    gUnknown_03004140.unk_40 = func1;
    gUnknown_03004140.unk_44 = func2;
    rfu_setMSCCallback(sub_800CEB0);
    rfu_setREQCallback(sub_800C7B4);
    return 0;
}

void sub_800BFA0(void)
{
    CpuFill16(0, &gUnknown_03004140, offsetof(struct UnkRfuStruct_1, unk_40));
    gUnknown_03004140.unk_06 = -1;
}

void sub_800BFCC(struct UnkLinkRfuStruct_02022B2C *unk0)
{
    sub_800C000();
    gUnknown_03004140.unk_04 = 1;
    gUnknown_03004140.unk_05 = 2;
    gUnknown_03004140.unk_3c = unk0;
    gUnknown_03004140.unk_09 = unk0->unk_11;
    gUnknown_03004140.unk_32 = unk0->unk_12;
    gUnknown_03004140.unk_18 = unk0->unk_14;
    if (unk0->unk_10)
    {
        gUnknown_03004140.unk_0b = 1;
    }
}

void sub_800C000(void)
{
    u8 i;

    gUnknown_03004140.unk_05 = 0;
    gUnknown_03004140.unk_04 = 0;
    gUnknown_03004140.unk_06 = -1;
    gUnknown_03004140.unk_07 = 0;
    gUnknown_03004140.unk_10 = 0;
    gUnknown_03004140.unk_0c = 0;
    gUnknown_03004140.unk_24 = 0;
    gUnknown_03004140.unk_30 = 0;
    for (i = 0; i < 4; i++)
    {
        gUnknown_03004140.unk_28[i] = 0;
        gUnknown_03004140.unk_34[i] = 0;
    }
}

void sub_800C048(void)
{
    gUnknown_03004140.unk_04 = 0x15;
}

u8 sub_800C054(u8 r5, u16 r7, u16 r8, u16 *r6)
{
    u8 i;
    u16 *buffer;

    if (gUnknown_03004140.unk_04 != 0 && (gUnknown_03004140.unk_04 != 0x08 || r5 != 1))
    {
        gUnknown_03004140.unk_14 = 1;
        sub_800D30C(0xf3, 0x01);
        return 1;
    }
    if (!rfu_getMasterSlave())
    {
        gUnknown_03004140.unk_14 = 2;
        sub_800D30C(0xf3, 0x01);
        return 2;
    }
    for (i = 0, buffer = r6; i < 16; i++)
    {
        if (*buffer++ == 0xFFFF)
        {
            break;
        }
    }
    if (i == 16)
    {
        gUnknown_03004140.unk_14 = 4;
        sub_800D30C(0xf3, 0x01);
        return 4;
    }
    if (r5 > 1)
    {
        gUnknown_03004140.unk_07 = 1;
        r5 = 1;
        r7 = 0;
    }
    else
    {
        gUnknown_03004140.unk_07 = 0;
    }
    if (r5 != 0)
    {
        gUnknown_03004140.unk_04 = 5;
    }
    else
    {
        gUnknown_03004140.unk_04 = 9;
        if (gUnknown_03004140.unk_0b)
        {
            gUnknown_03004140.unk_0b = 2;
        }
    }
    gUnknown_03004140.unk_06 = r5;
    gUnknown_03004140.unk_1a = r7;
    gUnknown_03004140.unk_26 = r8;
    gUnknown_03004140.unk_20 = r6;
    return 0;
}

u8 sub_800C12C(u16 r6, u16 r8)
{
    u8 i;
    struct RfuUnk5 *tmp;

    if (gUnknown_03004140.unk_04 != 0 && (gUnknown_03004140.unk_04 < 9 || gUnknown_03004140.unk_04 > 11))
    {
        gUnknown_03004140.unk_14 = 1;
        sub_800D30C(0xF3, 0x01);
        return 1;
    }
    if (!rfu_getMasterSlave())
    {
        gUnknown_03004140.unk_14 = 2;
        sub_800D30C(0xF3, 0x01);
        return 2;
    }
    for (i = 0; i < gUnknown_03007890[0].unk_08; i++)
    {
        tmp = &gUnknown_03007890[i];
        if (tmp->unk_14 == r6)
        {
            break;
        }
    }
    if (gUnknown_03007890[0].unk_08 == 0 || i == gUnknown_03007890[0].unk_08)
    {
        gUnknown_03004140.unk_14 = 3;
        sub_800D30C(0xF3, 0x01);
        return 3;
    }
    if (gUnknown_03004140.unk_04 == 0 || gUnknown_03004140.unk_04 == 9)
    {
        gUnknown_03004140.unk_04 = 12;
        gUnknown_03004140.unk_05 = 13;
    }
    else
    {
        gUnknown_03004140.unk_04 = 11;
        gUnknown_03004140.unk_05 = 12;
    }
    gUnknown_03004140.unk_1e = r6;
    gUnknown_03004140.unk_1a = r8;
    if (gUnknown_03004140.unk_07 != 0)
    {
        gUnknown_03004140.unk_07 = 7;
    }
    return 0;
}

void sub_800C210(u8 a0)
{
    u8 i;

    if (a0 & gUnknown_03004140.unk_30)
    {
        gUnknown_03004140.unk_30 &= ~a0;
        for (i = 0; i < 4; i++)
        {
            if ((a0 >> i) & 1)
            {
                gUnknown_03004140.unk_34[i] = 0;
            }
        }
        i = gUnknown_03007890[0].unk_03 & a0;
        if (i)
        {
            sub_800D334(i);
        }
        gUnknown_03004140.unk_14 = i;
        sub_800D30C(0x33, i);
    }
}

void sub_800C27C(bool8 a0)
{
    u8 r2;

    r2 = 0;
    gUnknown_03004140.unk_07 = 0;
    if (a0)
    {
        sub_800C000();
        gUnknown_03004140.unk_04 = 23;
    }
    else
    {
        switch (gUnknown_03004140.unk_04)
        {
            case 5:
                gUnknown_03004140.unk_04 = 8;
                gUnknown_03004140.unk_05 = 0;
                r2 = 0x13;
                break;
            case 6:
                gUnknown_03004140.unk_04 = 7;
                gUnknown_03004140.unk_05 = 8;
                break;
            case 7:
                gUnknown_03004140.unk_04 = 7;
                gUnknown_03004140.unk_05 = 8;
                break;
            case 8:
                break;
            case 9:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x21;
                break;
            case 10:
                gUnknown_03004140.unk_04 = 11;
                gUnknown_03004140.unk_05 = 0;
                break;
            case 11:
                gUnknown_03004140.unk_04 = 11;
                gUnknown_03004140.unk_05 = 0;
                break;
            case 12:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x23;
                break;
            case 13:
                gUnknown_03004140.unk_04 = 14;
                break;
            case 14:
                gUnknown_03004140.unk_04 = 14;
                break;
            case 15:
                break;
            case 16:
                gUnknown_03004140.unk_04 = gUnknown_03004140.unk_11;
                gUnknown_03004140.unk_05 = gUnknown_03004140.unk_12;
                sub_800D334(gUnknown_03007890[0].unk_03);
                gUnknown_03004140.unk_14 = gUnknown_03007890[0].unk_03;
                sub_800D30C(0x33, 0x01);
                return;
            case 17:
                gUnknown_03004140.unk_04 = 18;
                break;
            case 18:
                gUnknown_03004140.unk_04 = 18;
                break;
            default:
                gUnknown_03004140.unk_05 = 0;
                gUnknown_03004140.unk_04 = 0;
                r2 = 0x43;
                break;
        }
        if (gUnknown_03004140.unk_04 == 0)
        {
            sub_800D30C(r2, 0);
        }
    }
}

bool8 sub_800C36C(u16 a0)
{
    bool8 retVal;
    u8 i;
    u8 sp0;
    u8 sp1;
    u8 sp2;
    u8 flags;

    retVal = FALSE;
    rfu_REQBN_watchLink(a0, &sp0, &sp1, &sp2);
    if (sp0)
    {
        gUnknown_03004140.unk_14 = sp0;
        gUnknown_03004140.unk_16 = sp1;
        if (gUnknown_03004140.unk_09)
        {
            gUnknown_03004140.unk_0a = 1;
            if (gUnknown_03004140.unk_06 == 0 && sp1 == 0)
            {
                gUnknown_03004140.unk_0a = 4;
            }
            if (gUnknown_03004140.unk_0a == 1)
            {
                for (i = 0; i < 4; i++)
                {
                    if ((sp0 >> i) & 1)
                    {
                        gUnknown_03004140.unk_30 |= (1 << i);
                        gUnknown_03004140.unk_34[i] = gUnknown_03004140.unk_32;
                    }
                }
                sub_800D30C(0x31, 0x01);
            }
            else
            {
                gUnknown_03004140.unk_0a = 0;
                sub_800D334(sp0);
                retVal = TRUE;
                sub_800D30C(0x33, 0x01);
            }
        }
        else
        {
            sub_800D334(sp0);
            retVal = TRUE;
            sub_800D30C(0x30, 0x02);
        }
        sub_800D610();
    }
    if (gUnknown_03007890[0].unk_00 == 1)
    {
        if (sp2)
        {
            for (i = 0; i < 4; i++)
            {
                if ((gUnknown_03004140.unk_30 >> i) & 1 && (sp2 >> i) & 1)
                {
                    gUnknown_03004140.unk_34[i] = 0;
                }
            }
            gUnknown_03004140.unk_30 &= ~sp2;
            gUnknown_03004140.unk_14 = sp2;
            sub_800D30C(0x32, 0x01);
        }
        if (gUnknown_03004140.unk_30)
        {
            flags = 0;
            for (i = 0; i < 4; i++)
            {
                if ((gUnknown_03004140.unk_30 >> i) & 1 && gUnknown_03004140.unk_34[i] && --gUnknown_03004140.unk_34[i] == 0)
                {
                    gUnknown_03004140.unk_30 &= ~(1 << i);
                    flags |= (1 << i);
                }
            }
            if (flags)
            {
                sub_800D334(flags);
                retVal = TRUE;
                gUnknown_03004140.unk_14 = flags;
                sub_800D30C(0x33, 0x01);
            }
        }
        if (!gUnknown_03004140.unk_30)
        {
            gUnknown_03004140.unk_0a = 0;
        }
    }
    return retVal;
}

void rfu_syncVBlank_(void)
{
    if (rfu_syncVBlank())
    {
        sub_800D30C(0xF1, 0x00);
        sub_800D610();
    }
}

void sub_800C54C(u32 a0)
{
    u8 r2;

    if (gUnknown_03004140.unk_40 == NULL && gUnknown_03004140.unk_04 != 0)
    {
        gUnknown_03004140.unk_04 = 0;
    }
    else
    {
        if (gUnknown_03004140.unk_07 != 0)
        {
            sub_800C744(a0);
        }
        do
        {
            if (gUnknown_03004140.unk_04 != 0)
            {
                rfu_waitREQComplete();
                gUnknown_03004140.unk_0e = 1;
                switch (gUnknown_03004140.unk_04)
                {
                    case 23:
                        r2 = sub_800BEC0() == 0x8001 ? 0x44 : 0xFF;
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                        sub_800D30C(r2, 0);
                        break;
                    case 1:
                        if (sub_800BEC0() == 0x8001)
                        {
                            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                            gUnknown_03004140.unk_05 = 3;
                        }
                        else
                        {
                            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                            sub_800D30C(0xFF, 0);
                        }
                        break;
                    case 2:
                        rfu_REQ_reset();
                        break;
                    case 3:
                        rfu_REQ_configSystem(gUnknown_03004140.unk_3c->unk_02, gUnknown_03004140.unk_3c->unk_00, gUnknown_03004140.unk_3c->unk_01);
                        break;
                    case 4:
                        rfu_REQ_configGameData(gUnknown_03004140.unk_3c->unk_04, gUnknown_03004140.unk_3c->unk_06, gUnknown_03004140.unk_3c->unk_08, gUnknown_03004140.unk_3c->unk_0c);
                        break;
                    case 5:
                        rfu_REQ_startSearchChild();
                        break;
                    case 6:
                        rfu_REQ_pollSearchChild();
                        break;
                    case 7:
                        rfu_REQ_endSearchChild();
                        break;
                    case 8:
                        break;
                    case 9:
                        rfu_REQ_startSearchParent();
                        break;
                    case 10:
                        rfu_REQ_pollSearchParent();
                        break;
                    case 11:
                        rfu_REQ_endSearchParent();
                        break;
                    case 12:
                        rfu_REQ_startConnectParent(gUnknown_03004140.unk_1e);
                        break;
                    case 13:
                        rfu_REQ_pollConnectParent();
                        break;
                    case 14:
                        rfu_REQ_endConnectParent();
                        break;
                    case 15:
                        break;
                    case 16:
                        rfu_REQ_CHILD_startConnectRecovery(gUnknown_03007890[0].unk_03);
                        break;
                    case 17:
                        rfu_REQ_CHILD_pollConnectRecovery();
                        break;
                    case 18:
                        rfu_REQ_CHILD_endConnectRecovery();
                        break;
                    case 19:
                        rfu_REQ_changeMasterSlave();
                        break;
                    case 20:
                        break;
                    case 21:
                        rfu_REQ_stopMode();
                        break;
                    case 22:
                        break;
                }
                rfu_waitREQComplete();
                gUnknown_03004140.unk_0e = 0;
            }
        } while (gUnknown_03004140.unk_04 == 18 || gUnknown_03004140.unk_04 == 19);
        if (gUnknown_03007890[0].unk_00 != 1 || !sub_800C36C(0))
        {
            sub_800CF34();
            sub_800D158();
            sub_800D268();
            sub_800D434();
        }
    }
}

void sub_800C744(u32 a0)
{
    if (gUnknown_03004140.unk_07 == 5)
    {
        gUnknown_03004140.unk_06 = 1;
        gUnknown_03004140.unk_04 = 5;
        gUnknown_03004140.unk_1a = gUnknown_03004140.unk_1c;
        if (gUnknown_03004140.unk_1a)
        {
            gUnknown_03004140.unk_07 = 6;
        }
        else
        {
            gUnknown_03004140.unk_07 = 1;
        }
    }
    if (gUnknown_03004140.unk_07 == 1)
    {
        gUnknown_03004140.unk_06 = 1;
        gUnknown_03004140.unk_04 = 5;
        gUnknown_03004140.unk_1a = a0 % 140;
        gUnknown_03004140.unk_1c = 140 - gUnknown_03004140.unk_1a;
        if (gUnknown_03004140.unk_1a)
        {
            gUnknown_03004140.unk_07 = 2;
        }
        else
        {
            gUnknown_03004140.unk_07 = 3;
        }
    }
    if (gUnknown_03004140.unk_07 == 3)
    {
        gUnknown_03004140.unk_06 = 0;
        gUnknown_03004140.unk_1a = 40;
        gUnknown_03004140.unk_07 = 4;
        gUnknown_03004140.unk_04 = 9;
    }
}

void sub_800C7B4(u16 r8, u16 r6)
{
    u8 sp0;
    register u8 *stwiRecvBuffer asm("r0");
    u8 *tmp;
    u8 i;

    if (gUnknown_03004140.unk_0e != 0)
    {
        gUnknown_03004140.unk_0e = 0;
        switch (r8)
        {
            case 16:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                    gUnknown_03004140.unk_05 = 4;
                }
                break;
            case 23:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                    gUnknown_03004140.unk_05 = 0;
                }
                break;
            case 22:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                    sub_800D30C(0x00, 0x00);
                }
                break;
            case 25:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 6;
                }
                break;
            case 26:
                if (gUnknown_03004140.unk_1a && --gUnknown_03004140.unk_1a == 0)
                {
                    gUnknown_03004140.unk_04 = 7;
                    gUnknown_03004140.unk_05 = 8;
                }
                break;
            case 27:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                    gUnknown_03004140.unk_05 = 0;
                    if (gUnknown_03004140.unk_07 == 0)
                    {
                        sub_800D30C(0x13, 0x00);
                    }
                }
                break;
            case 28:
                if (r6 == 0)
                {
                    if (gUnknown_03004140.unk_0b == 1 && gUnknown_03004140.unk_1a > 1)
                    {
                        gUnknown_03004140.unk_1a--;
                    }
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 10;
                }
                break;
            case 29:
                if (r6 == 0)
                {
                    sp0 = sub_800D294();
                    gUnknown_03004140.unk_14 = sp0;
                    if (sp0)
                    {
                        sub_800D30C(0x20, 0x01);
                    }
                    if (gUnknown_03004140.unk_0b && gUnknown_03004140.unk_1a != 1 && gUnknown_03007890[0].unk_08 == 4)
                    {
                        rfu_REQ_endSearchParent();
                        rfu_waitREQComplete();
                        gUnknown_03004140.unk_04 = 9;
                        gUnknown_03004140.unk_0b = 1;
                    }
                }
                if (gUnknown_03004140.unk_1a && --gUnknown_03004140.unk_1a == 0)
                {
                    gUnknown_03004140.unk_04 = 11;
                    gUnknown_03004140.unk_05 = 0;
                }
                break;
            case 30:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                    if (gUnknown_03004140.unk_07 == 0)
                    {
                        if (gUnknown_03004140.unk_04 == 0)
                        {
                            sub_800D30C(0x21, 0x00);
                        }
                    }
                    else if (gUnknown_03004140.unk_07 != 7)
                    {
                        gUnknown_03004140.unk_04 = 5;
                        gUnknown_03004140.unk_07 = 5;
                    }
                }
                break;
            case 31:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 13;
                }
                break;
            case 32:
                if (r6 == 0 && !rfu_getConnectParentStatus(&sp0, &gUnknown_03004140.unk_10) && !sp0)
                {
                    gUnknown_03004140.unk_04 = 14;
                }
                if (gUnknown_03004140.unk_1a && --gUnknown_03004140.unk_1a == 0)
                {
                    gUnknown_03004140.unk_04 = 14;
                }
                break;
            case 33:
                if (r6 == 0 && !rfu_getConnectParentStatus(&sp0, &gUnknown_03004140.unk_10))
                {
                    if (!sp0)
                    {
                        gUnknown_03004140.unk_04 = 19;
                        gUnknown_03004140.unk_05 = 15;
                        gUnknown_03004140.unk_1e = 0x22;
                        gUnknown_03004140.unk_14 = gUnknown_03004140.unk_10;
                    }
                    else
                    {
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                        gUnknown_03004140.unk_1e = 0x23;
                        gUnknown_03004140.unk_14 = sp0;
                        if (gUnknown_03004140.unk_07)
                        {
                            gUnknown_03004140.unk_07 = 3;
                            gUnknown_03004140.unk_04 = 9;
                        }
                    }
                    sub_800D30C(gUnknown_03004140.unk_1e, 0x01);
                    gUnknown_03004140.unk_1e = 0;
                }
                break;
            case 50:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_14 = gUnknown_03007890[0].unk_03;
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 17;
                    for (gUnknown_03004140.unk_10 = 0; gUnknown_03004140.unk_10 < 4; gUnknown_03004140.unk_10 ++)
                    {
                        if ((gUnknown_03007890[0].unk_03 >> gUnknown_03004140.unk_10) & 1)
                        {
                            break;
                        }
                    }
                }
                break;
            case 51:
                if (r6 == 0 && !rfu_CHILD_getConnectRecoveryStatus(&sp0) && sp0 < 2)
                {
                    gUnknown_03004140.unk_04 = 18;
                }
                if (gUnknown_03004140.unk_34[gUnknown_03004140.unk_10] && --gUnknown_03004140.unk_34[gUnknown_03004140.unk_10] == 0)
                {
                    gUnknown_03004140.unk_04 = 18;
                }
                break;
            case 52:
                if (r6 == 0 && !rfu_CHILD_getConnectRecoveryStatus(&sp0))
                {
                    if (!sp0)
                    {
                        gUnknown_03004140.unk_04 = 19;
                        gUnknown_03004140.unk_05 = 22;
                        gUnknown_03004140.unk_1e = 0x32;
                    }
                    else
                    {
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                        sub_800D334(gUnknown_03007890[0].unk_03);
                        gUnknown_03004140.unk_1e = 0x33;
                    }
                    gUnknown_03004140.unk_34[gUnknown_03004140.unk_10] = 0;
                    gUnknown_03004140.unk_30 = 0;
                    gUnknown_03004140.unk_0a = 0;
                    sub_800D30C(gUnknown_03004140.unk_1e, 0x01);
                    gUnknown_03004140.unk_1e = 0;
                }
                break;
            case 39:
                if (r6 == 0)
                {
                    if (gUnknown_03004140.unk_05 == 22)
                    {
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_11;
                        gUnknown_03004140.unk_05 = gUnknown_03004140.unk_12;
                        gUnknown_03004140.unk_02 = 1;
                        sub_800D30C(0x41, 0x00);
                    }
                    else if (gUnknown_03004140.unk_05 == 15)
                    {
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05;
                        gUnknown_03004140.unk_02 = 1;
                        sub_800D30C(0x41, 0x00);
                        gUnknown_03004140.unk_24 |= 1 << gUnknown_03004140.unk_10;
                        gUnknown_03004140.unk_28[gUnknown_03004140.unk_10] = gUnknown_03004140.unk_26;
                        rfu_clearSlot(4, gUnknown_03004140.unk_10);
                        tmp = &sp0;
                        *tmp = rfu_NI_CHILD_setSendGameName(gUnknown_03004140.unk_10, 0x0e);
                        if (*tmp)
                        {
                            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                            sub_800D610();
                            sub_800D334(gUnknown_03007890[0].unk_02 | gUnknown_03007890[0].unk_03);
                            gUnknown_03004140.unk_14 = sp0;
                            sub_800D30C(0x25, 0x01);
                        }
                    }
                }
                break;
            case 61:
                if (r6 == 0)
                {
                    gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                    sub_800D30C(0x42, 0x00);
                }
                break;
        }
        gUnknown_03004140.unk_0e = 1;
    }
    else if (r6 == 3 && gUnknown_03004140.unk_0f && (r8 == 0x24 || r8 == 0x26 || r8 == 0x27))
    {
        rfu_REQ_RFUStatus();
        rfu_waitREQComplete();
        rfu_getRFUStatus(&sp0);
        if (sp0 == 0 && gUnknown_03007890[0].unk_00 == 0)
        {
            stwiRecvBuffer = rfu_getSTWIRecvBuffer();
            stwiRecvBuffer[4] = gUnknown_03007890[0].unk_02;
            stwiRecvBuffer[5] = 1;
            sub_800C36C(0x29);
            r6 = 0;
        }
    }
    switch (r8)
    {
        case 48:
            if (r6 == 0)
            {
                stwiRecvBuffer = rfu_getSTWIRecvBuffer();
                gUnknown_03004140.unk_14 = stwiRecvBuffer[8];
                sub_800D358();
                if (gUnknown_03004140.unk_30)
                {
                    gUnknown_03004140.unk_30 &= ~gUnknown_03004140.unk_14;
                    for (i = 0; i < 4; i++)
                    {
                        if ((gUnknown_03004140.unk_14 >> i) & 1)
                        {
                            gUnknown_03004140.unk_34[i] = 0;
                        }
                    }
                    if (gUnknown_03004140.unk_06 == 0)
                    {
                        gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                    }
                }
                sp0 = gUnknown_03004140.unk_00 & gUnknown_03004140.unk_14;
                for (i = 0; i < 4; i++)
                {
                    if ((sp0 >> i) & 1 && gUnknown_03004140.unk_01)
                    {
                        gUnknown_03004140.unk_01--;
                    }
                }
                gUnknown_03004140.unk_00 &= ~gUnknown_03004140.unk_14;
                if (gUnknown_03004140.unk_07)
                {
                    if (gUnknown_03007890[0].unk_00 == 0xFF)
                    {
                        if (gUnknown_03004140.unk_07 == 8)
                        {
                            gUnknown_03004140.unk_1a = gUnknown_03004140.unk_1c;
                            gUnknown_03004140.unk_07 = 6;
                            gUnknown_03004140.unk_04 = 6;
                        }
                        else if (gUnknown_03004140.unk_04 != 6 && gUnknown_03004140.unk_04 != 7)
                        {
                            gUnknown_03004140.unk_07 = 1;
                            gUnknown_03004140.unk_04 = 5;
                        }
                    }
                }
                if (gUnknown_03007890[0].unk_00 == 0xFF)
                {
                    if (gUnknown_03004140.unk_04 == 0)
                    {
                        gUnknown_03004140.unk_06 = -1;
                    }
                }
                if (gUnknown_03004140.unk_0e == 0)
                {
                    sub_800D30C(0x40, 0x01);
                }
            }
            break;
        case 38:
            sub_800D20C();
            if (gUnknown_03007890[0].unk_00 != 0xFF)
            {
                sub_800D30C(0x50, 0x00);
            }
            break;
        case 16:
        case 61:
            if (r6 == 0)
            {
                gUnknown_03004140.unk_0d = 0;
                gUnknown_03004140.unk_01 = 0;
                gUnknown_03004140.unk_00 = 0;;
                gUnknown_03004140.unk_06 = -1;
                sub_800D610();
                if (r8 == 61)
                {
                    sub_800BFA0();
                }
            }
            break;
    }
    if (r6 != 0)
    {
        if (r8 == 28 && r6 != 0 && gUnknown_03004140.unk_07 == 4)
        {
            gUnknown_03007890[0].unk_00 = 1;
            gUnknown_03007890[0].unk_02 = 15;
            sub_800D334(15);
            rfu_waitREQComplete();
            return;
        }
        else
        {
            gUnknown_03004140.unk_14 = r8;
            gUnknown_03004140.unk_16 = r6;
            if (gUnknown_03004140.unk_0e)
            {
                gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
            }
            sub_800D30C(0xf0, 0x02);
            sub_800D610();
        }
    }
    if (r8 == 0xFF)
    {
        sub_800D30C(0xf2, 0x00);
        sub_800D610();
    }
}

void sub_800CEB0(u16 r6)
{
    u8 r7;
    u8 sp0;

    r7 = gUnknown_03004140.unk_0e;
    gUnknown_03004140.unk_0e = 0;
    gUnknown_03004140.unk_0f = 1;
    if (gUnknown_03007890[0].unk_00 == 0)
    {
        sub_800C36C(r6);
        if (gUnknown_03004140.unk_02 != 1)
        {
            sub_800D610();
            gUnknown_03004140.unk_0f = 0;
            gUnknown_03004140.unk_0e = r7;
            return;
        }
    }
    else
    {
        if (!rfu_UNI_PARENT_getDRAC_ACK(&sp0))
        {
            gUnknown_03004140.unk_03 |= sp0;
        }
    }
    if (gUnknown_03004140.unk_44 != NULL)
    {
        gUnknown_03004140.unk_44(r6);
        rfu_waitREQComplete();
        if (gUnknown_03004140.unk_02 == 2)
        {
            sub_800D610();
        }
    }
    gUnknown_03004140.unk_0f = 0;
    gUnknown_03004140.unk_0e = r7;
}

#ifdef NONMATCHING
void sub_800CF34(void)
{
    u8 flags;
    u8 sp0;
    u8 i;
    u8 r5;
    u8 r4;
    u16 *ptr;

    if (gUnknown_03004140.unk_04 == 5 || gUnknown_03004140.unk_04 == 6 || gUnknown_03004140.unk_04 == 7 || gUnknown_03004140.unk_04 == 8)
    {
        flags = ((gUnknown_03007890[0].unk_02 ^ gUnknown_03004140.unk_0c) & gUnknown_03007890[0].unk_02) & ~gUnknown_03007890[0].unk_07;
        gUnknown_03004140.unk_0c = gUnknown_03007890[0].unk_02;
        if (flags)
        {
            gUnknown_03004140.unk_14 = flags;
            sub_800D30C(0x10, 0x01);
        }
        sp0 = 0x00;
        for (i = 0; i < 4; i++)
        {
            r4 = 1 << i;
            r5 = 0x00;
            if (flags & r4)
            {
                gUnknown_03004140.unk_28[i] = gUnknown_03004140.unk_26;
                gUnknown_03004140.unk_24 |= r4;
            }
            else if (gUnknown_03004140.unk_24 & r4)
            {
                if (gUnknown_03007880[i]->unk_34 == 0x46)
                {
                    if (gUnknown_03007880[i]->unk_61 == 1)
                    {
                        r5 = 0x02;
                        for (ptr = gUnknown_03004140.unk_20; *ptr != 0xFFFF; ptr++)
                        {
                            if (*gUnknown_03007890[i].unk_18 == *ptr) // FIXME: Role of r0 and r1 is swapped
                            {
                                gUnknown_03004140.unk_00 |= r4;
                                gUnknown_03004140.unk_01++;
                                sp0 |= r4;
                                r5 |= 0x01;
                                break;
                            }
                        }
                        if (!(r5 & 0x01))
                        {
                            r5 |= 0x04;
                        }
                    }
                }
                else if (--gUnknown_03004140.unk_28[i] == 0)
                {
                    r5 = 0x06;
                }
                if (r5 & 0x02)
                {
                    gUnknown_03004140.unk_24 &= ~r4;
                    gUnknown_03004140.unk_28[i] = 0;
                    rfu_clearSlot(0x08, i);
                }
                if (r5 & 0x04)
                {
                    gUnknown_03004140.unk_0d |= r4;
                }
            }
        }
        if (sp0)
        {
            gUnknown_03004140.unk_14 = sp0;
            sub_800D30C(0x11, 0x01);
        }
        if (gUnknown_03004140.unk_0d)
        {
            r5 = 0x01;
            if (gUnknown_03007890[0].unk_06 && ((gUnknown_03004140.unk_03 & gUnknown_03004140.unk_00) != gUnknown_03004140.unk_00))
            {
                r5 = 0x00;
            }
            if (r5)
            {
                sub_800D334(gUnknown_03004140.unk_0d);
                gUnknown_03004140.unk_14 = gUnknown_03004140.unk_0d;
                gUnknown_03004140.unk_0d = 0;
                sub_800D30C(0x12, 0x01);
            }
        }
        if (gUnknown_03004140.unk_24 == 0 && gUnknown_03004140.unk_04 == 8)
        {
            if (gUnknown_03004140.unk_07 == 0)
            {
                gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
                sub_800D30C(0x14, 0x00);
            }
            else
            {
                if (gUnknown_03004140.unk_07 == 2)
                {
                    gUnknown_03004140.unk_07 = 3;
                    gUnknown_03004140.unk_04 = 9;
                }
                else
                {
                    gUnknown_03004140.unk_07 = 1;
                    gUnknown_03004140.unk_04 = 5;
                }
                if (gUnknown_03004140.unk_00)
                {
                    gUnknown_03004140.unk_1a = 0;
                    gUnknown_03004140.unk_07 = 8;
                    gUnknown_03004140.unk_04 = 5;
                }
            }
        }
    }
}
#else
__attribute__((naked)) void sub_800CF34(void)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tsub sp, 0x8\n"
                    "\tldr r1, =gUnknown_03004140\n"
                    "\tldrb r0, [r1, 0x4]\n"
                    "\tsubs r0, 0x5\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tadds r3, r1, 0\n"
                    "\tcmp r0, 0x3\n"
                    "\tbls _0800CF52\n"
                    "\tb _0800D146_break\n"
                    "_0800CF52:\n"
                    "\tldr r0, =gUnknown_03007890\n"
                    "\tldr r2, [r0]\n"
                    "\tldrb r1, [r2, 0x2]\n"
                    "\tldrb r0, [r3, 0xC]\n"
                    "\tadds r4, r1, 0\n"
                    "\teors r4, r0\n"
                    "\tands r4, r1\n"
                    "\tldrb r0, [r2, 0x7]\n"
                    "\tbics r4, r0\n"
                    "\tmov r8, r4\n"
                    "\tstrb r1, [r3, 0xC]\n"
                    "\tcmp r4, 0\n"
                    "\tbeq _0800CF7A\n"
                    "\tstrh r4, [r3, 0x14]\n"
                    "\tmovs r0, 0x10\n"
                    "\tmovs r1, 0x1\n"
                    "\tstr r3, [sp, 0x4]\n"
                    "\tbl sub_800D30C\n"
                    "\tldr r3, [sp, 0x4]\n"
                    "_0800CF7A:\n"
                    "\tmovs r0, 0\n"
                    "\tstr r0, [sp]\n"
                    "\tmovs r6, 0\n"
                    "\tadds r7, r3, 0\n"
                    "\tmovs r1, 0x24\n"
                    "\tadds r1, r3\n"
                    "\tmov r9, r1\n"
                    "_0800CF88:\n"
                    "\tmovs r0, 0x80\n"
                    "\tlsls r0, 17\n"
                    "\tlsls r0, r6\n"
                    "\tlsrs r4, r0, 24\n"
                    "\tmovs r5, 0\n"
                    "\tmov r0, r8\n"
                    "\tands r0, r4\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800CFDA\n"
                    "\tlsls r1, r6, 1\n"
                    "\tadds r0, r7, 0\n"
                    "\tadds r0, 0x28\n"
                    "\tadds r1, r0\n"
                    "\tldrh r0, [r7, 0x26]\n"
                    "\tstrh r0, [r1]\n"
                    "\tmov r2, r9\n"
                    "\tldrb r1, [r2]\n"
                    "\tadds r0, r4, 0\n"
                    "\torrs r0, r1\n"
                    "\tstrb r0, [r2]\n"
                    "\tadds r6, 0x1\n"
                    "\tmov r10, r6\n"
                    "\tb _0800D090\n"
                    "\t.pool\n"
                    "_0800CFC0:\n"
                    "\tldrb r1, [r7]\n"
                    "\tadds r0, r4, 0\n"
                    "\torrs r0, r1\n"
                    "\tstrb r0, [r7]\n"
                    "\tldrb r0, [r7, 0x1]\n"
                    "\tadds r0, 0x1\n"
                    "\tstrb r0, [r7, 0x1]\n"
                    "\tldr r0, [sp]\n"
                    "\torrs r0, r4\n"
                    "\tstr r0, [sp]\n"
                    "\tmovs r0, 0x1\n"
                    "\torrs r5, r0\n"
                    "\tb _0800D024\n"
                    "_0800CFDA:\n"
                    "\tmov r1, r9\n"
                    "\tldrb r0, [r1]\n"
                    "\tands r0, r4\n"
                    "\tadds r2, r6, 0x1\n"
                    "\tmov r10, r2\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800D090\n"
                    "\tldr r0, =gUnknown_03007880\n"
                    "\tlsls r1, r6, 2\n"
                    "\tadds r1, r0\n"
                    "\tldr r1, [r1]\n"
                    "\tldrh r0, [r1, 0x34]\n"
                    "\tcmp r0, 0x46\n"
                    "\tbne _0800D040\n"
                    "\tadds r0, r1, 0\n"
                    "\tadds r0, 0x61\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _0800D058\n"
                    "\tmovs r5, 0x2\n"
                    "\tldr r3, [r3, 0x20]\n"
                    "\tldrh r2, [r3]\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tcmp r2, r0\n"
                    "\tbeq _0800D024\n"
                    "\tldr r0, =gUnknown_03007890\n"
                    "\tldr r0, [r0]\n"
                    "\tlsls r1, r6, 5\n"
                    "\tadds r0, r1\n"
                    "\tldrh r0, [r0, 0x18]\n"
                    "\tldr r1, =0x0000ffff\n"
                    "_0800D018:\n"
                    "\tcmp r0, r2\n"
                    "\tbeq _0800CFC0\n"
                    "\tadds r3, 0x2\n"
                    "\tldrh r2, [r3]\n"
                    "\tcmp r2, r1\n"
                    "\tbne _0800D018\n"
                    "_0800D024:\n"
                    "\tmovs r0, 0x1\n"
                    "\tands r0, r5\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0800D058\n"
                    "\tmovs r0, 0x4\n"
                    "\torrs r5, r0\n"
                    "\tb _0800D058\n"
                    "\t.pool\n"
                    "_0800D040:\n"
                    "\tlsls r1, r6, 1\n"
                    "\tadds r0, r3, 0\n"
                    "\tadds r0, 0x28\n"
                    "\tadds r1, r0\n"
                    "\tldrh r0, [r1]\n"
                    "\tsubs r0, 0x1\n"
                    "\tstrh r0, [r1]\n"
                    "\tldr r1, =0x0000ffff\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0800D058\n"
                    "\tmovs r5, 0x6\n"
                    "_0800D058:\n"
                    "\tmovs r0, 0x2\n"
                    "\tands r0, r5\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800D07E\n"
                    "\tmov r2, r9\n"
                    "\tldrb r0, [r2]\n"
                    "\tbics r0, r4\n"
                    "\tmovs r2, 0\n"
                    "\tmov r1, r9\n"
                    "\tstrb r0, [r1]\n"
                    "\tlsls r0, r6, 1\n"
                    "\tadds r1, r7, 0\n"
                    "\tadds r1, 0x28\n"
                    "\tadds r0, r1\n"
                    "\tstrh r2, [r0]\n"
                    "\tmovs r0, 0x8\n"
                    "\tadds r1, r6, 0\n"
                    "\tbl rfu_clearSlot\n"
                    "_0800D07E:\n"
                    "\tmovs r0, 0x4\n"
                    "\tands r5, r0\n"
                    "\tldr r3, =gUnknown_03004140\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _0800D090\n"
                    "\tldrb r1, [r7, 0xD]\n"
                    "\tadds r0, r4, 0\n"
                    "\torrs r0, r1\n"
                    "\tstrb r0, [r7, 0xD]\n"
                    "_0800D090:\n"
                    "\tmov r2, r10\n"
                    "\tlsls r0, r2, 24\n"
                    "\tlsrs r6, r0, 24\n"
                    "\tcmp r6, 0x3\n"
                    "\tbhi _0800D09C\n"
                    "\tb _0800CF88\n"
                    "_0800D09C:\n"
                    "\tldr r4, [sp]\n"
                    "\tcmp r4, 0\n"
                    "\tbeq _0800D0AE\n"
                    "\tldr r0, =gUnknown_03004140\n"
                    "\tstrh r4, [r0, 0x14]\n"
                    "\tmovs r0, 0x11\n"
                    "\tmovs r1, 0x1\n"
                    "\tbl sub_800D30C\n"
                    "_0800D0AE:\n"
                    "\tldr r1, =gUnknown_03004140\n"
                    "\tldrb r0, [r1, 0xD]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800D0EA\n"
                    "\tmovs r5, 0x1\n"
                    "\tldr r0, =gUnknown_03007890\n"
                    "\tldr r0, [r0]\n"
                    "\tldrb r0, [r0, 0x6]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800D0CE\n"
                    "\tldrb r0, [r1, 0x3]\n"
                    "\tldrb r1, [r1]\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, r1\n"
                    "\tbeq _0800D0CE\n"
                    "\tmovs r5, 0\n"
                    "_0800D0CE:\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _0800D0EA\n"
                    "\tldr r4, =gUnknown_03004140\n"
                    "\tldrb r0, [r4, 0xD]\n"
                    "\tbl sub_800D334\n"
                    "\tldrb r0, [r4, 0xD]\n"
                    "\tmovs r1, 0\n"
                    "\tstrh r0, [r4, 0x14]\n"
                    "\tstrb r1, [r4, 0xD]\n"
                    "\tmovs r0, 0x12\n"
                    "\tmovs r1, 0x1\n"
                    "\tbl sub_800D30C\n"
                    "_0800D0EA:\n"
                    "\tldr r0, =gUnknown_03004140\n"
                    "\tadds r1, r0, 0\n"
                    "\tadds r1, 0x24\n"
                    "\tldrb r1, [r1]\n"
                    "\tadds r3, r0, 0\n"
                    "\tcmp r1, 0\n"
                    "\tbne _0800D146_break\n"
                    "\tldrb r0, [r3, 0x4]\n"
                    "\tcmp r0, 0x8\n"
                    "\tbne _0800D146_break\n"
                    "\tldrb r0, [r3, 0x7]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0800D120\n"
                    "\tstrb r0, [r3, 0x5]\n"
                    "\tstrb r0, [r3, 0x4]\n"
                    "\tmovs r0, 0x14\n"
                    "\tmovs r1, 0\n"
                    "\tbl sub_800D30C\n"
                    "\tb _0800D146_break\n"
                    "\t.pool\n"
                    "_0800D120:\n"
                    "\tcmp r0, 0x2\n"
                    "\tbne _0800D12C\n"
                    "\tmovs r0, 0x3\n"
                    "\tstrb r0, [r3, 0x7]\n"
                    "\tmovs r0, 0x9\n"
                    "\tb _0800D132\n"
                    "_0800D12C:\n"
                    "\tmovs r0, 0x1\n"
                    "\tstrb r0, [r3, 0x7]\n"
                    "\tmovs r0, 0x5\n"
                    "_0800D132:\n"
                    "\tstrb r0, [r3, 0x4]\n"
                    "\tldrb r0, [r3]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0800D146_break\n"
                    "\tmovs r0, 0\n"
                    "\tstrh r0, [r3, 0x1A]\n"
                    "\tmovs r0, 0x8\n"
                    "\tstrb r0, [r3, 0x7]\n"
                    "\tmovs r0, 0x5\n"
                    "\tstrb r0, [r3, 0x4]\n"
                    "_0800D146_break:\n"
                    "\tadd sp, 0x8\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0");
}
#endif

static void sub_800D158(void)
{
    u16 imeBak = REG_IME;
    REG_IME = 0;
    if (gUnknown_03004140.unk_04 == 15)
    {
        if (--gUnknown_03004140.unk_28[gUnknown_03004140.unk_10] == 0 || gUnknown_03007880[gUnknown_03004140.unk_10]->unk_0 == 0x27)
        {
            sub_800D630();
            gUnknown_03004140.unk_04 = 24;
            rfu_clearSlot(4, gUnknown_03004140.unk_10);
            gUnknown_03004140.unk_24 &= ~(1 << gUnknown_03004140.unk_10);
            gUnknown_03004140.unk_28[gUnknown_03004140.unk_10] = 0;
        }
    }
    REG_IME = imeBak;
    if (gUnknown_03004140.unk_04 == 24)
    {
        if (gUnknown_03004140.unk_02 == 1)
        {
            sub_800D630();
        }
        if (gUnknown_03004140.unk_02 == 0)
        {
            gUnknown_03004140.unk_04 = gUnknown_03004140.unk_05 = 0;
            sub_800D334(gUnknown_03007890[0].unk_02 | gUnknown_03007890[0].unk_03);
            gUnknown_03004140.unk_14 = 0;
            sub_800D30C(0x25, 0x01);
        }
    }
}
