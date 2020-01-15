#include "librfu.h"

static void Sio32IDIntr(void);
static void Sio32IDInit(void);
static s32 Sio32IDMain(void);

struct RfuSIO32Id gRfuSIO32Id;

static const u16 Sio32ConnectionData[] = { 0x494e, 0x544e, 0x4e45, 0x4f44 }; // NINTENDO
static const char Sio32IDLib_Var[] = "Sio32ID_030820";

s32 AgbRFU_checkID(u8 r5)
{
    u16 r8;
    vu16 *r4;
    s32 r6;

    if (REG_IME == 0)
        return -1;
    r8 = REG_IE;
    gSTWIStatus->state = 10;
    STWI_set_Callback_ID(Sio32IDIntr);
    Sio32IDInit();
    r4 = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    r5 *= 8;
    while (--r5 != 0xFF)
    {
        r6 = Sio32IDMain();
        if (r6 != 0)
            break;
        r4[1] = 0;
        r4[0] = 0;
        r4[1] = TIMER_1024CLK | TIMER_ENABLE;
        while (r4[0] < 32)
            ;
        r4[1] = 0;
        r4[0] = 0;
    }
    REG_IME = 0;
    REG_IE = r8;
    REG_IME = 1;
    gSTWIStatus->state = 0;
    STWI_set_Callback_ID(NULL);
    return r6;
}

static void Sio32IDInit(void)
{
    REG_IME = 0;
    REG_IE &= ~((8 << gSTWIStatus->timerSelect) | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
    CpuFill32(0, &gRfuSIO32Id, sizeof(struct RfuSIO32Id));
    REG_IF = INTR_FLAG_SERIAL;
}

static s32 Sio32IDMain(void)
{
    u8 r12;

    switch (r12 = gRfuSIO32Id.unk1)
    {
    case 0:
        gRfuSIO32Id.unk0 = 1;
        REG_SIOCNT |= SIO_38400_BPS;
        REG_IME = r12;
        REG_IE |= INTR_FLAG_SERIAL;
        REG_IME = 1;
        gRfuSIO32Id.unk1 = 1;
        *(vu8 *)&REG_SIOCNT |= SIO_ENABLE;
        break;
    case 1:
        if (gRfuSIO32Id.unkA == 0)
        {
            if (gRfuSIO32Id.unk0 == 1)
            {
                if (gRfuSIO32Id.unk2 == 0)
                {
                    REG_IME = gRfuSIO32Id.unk2;
                    REG_SIOCNT |= SIO_ENABLE;
                    REG_IME = r12;
                }
            }
            else if (gRfuSIO32Id.unk4 != 0x8001 && !gRfuSIO32Id.unk2)
            {
                REG_IME = gRfuSIO32Id.unk2;
                REG_IE &= ~INTR_FLAG_SERIAL;
                REG_IME = r12;
                REG_SIOCNT = gRfuSIO32Id.unk2;
                REG_SIOCNT = SIO_32BIT_MODE;
                REG_IF = INTR_FLAG_SERIAL;
                REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
                REG_IME = gRfuSIO32Id.unk2;
                REG_IE |= INTR_FLAG_SERIAL;
                REG_IME = r12;
            }
            break;
        }
        else
        {
            gRfuSIO32Id.unk1 = 2;
            // fallthrough
        }
    default:
        return gRfuSIO32Id.unkA;
    }
    return 0;
}

static void Sio32IDIntr(void)
{
    u32 r5;
    u16 r0;
#ifndef NONMATCHING
    register u32 r1 asm("r1");
    register u16 r0_ asm("r0");
#else
    u32 r1;
    u16 r0_;
#endif

    r5 = REG_SIODATA32;
    if (gRfuSIO32Id.unk0 != 1)
        REG_SIOCNT |= SIO_ENABLE;
    r1 = 16 * gRfuSIO32Id.unk0; // to handle side effect of inline asm
    r1 = (r5 << r1) >> 16;
    r5 = (r5 << 16 * (1 - gRfuSIO32Id.unk0)) >> 16;
    if (gRfuSIO32Id.unkA == 0)
    {
        if (r1 == gRfuSIO32Id.unk6)
        {
            if (gRfuSIO32Id.unk2 > 3)
            {
                gRfuSIO32Id.unkA = r5;
            }
            else if (r1 == (u16)~gRfuSIO32Id.unk4)
            {
                r0_ = ~gRfuSIO32Id.unk6;
                if (r5 == r0_)
                    ++gRfuSIO32Id.unk2;
            }
        }
        else
        {
            gRfuSIO32Id.unk2 = gRfuSIO32Id.unkA;
        }
    }
    if (gRfuSIO32Id.unk2 < 4)
        gRfuSIO32Id.unk4 = *(gRfuSIO32Id.unk2 + Sio32ConnectionData);
    else
        gRfuSIO32Id.unk4 = 0x8001;
    gRfuSIO32Id.unk6 = ~r5;
    REG_SIODATA32 = (gRfuSIO32Id.unk4 << 16 * (1 - gRfuSIO32Id.unk0))
                  + (gRfuSIO32Id.unk6 << 16 * gRfuSIO32Id.unk0);
    if (gRfuSIO32Id.unk0 == 1 && (gRfuSIO32Id.unk2 || r5 == 0x494E))
    {
        for (r0 = 0; r0 < 600; ++r0)
            ;
        if (gRfuSIO32Id.unkA == 0)
            REG_SIOCNT |= SIO_ENABLE;
    }
}
