#include "librfu_stwi_private.h"

void Sio32IDIntr(void);
void Sio32IDInit(void);
s32 Sio32IDMain(void);

struct RfuSIO32Id
{
    u8 MS_mode;
    u8 state;
    u16 count;
    u16 send_id;
    u16 recv_id;
    u16 reserved; // unused
    u16 lastId;
};

COMMON_DATA struct RfuSIO32Id gRfuSIO32Id = {0};

static const u16 Sio32ConnectionData[] = { 0x494e, 0x544e, 0x4e45, 0x4f44 }; // NINTENDO
static const char Sio32IDLib_Var[] = "Sio32ID_030820";

u32 AgbRFU_checkID(u8 maxTries)
{
    u16 ieBak;
    vu16 *regTMCNTL;
    u32 id;

    // Interrupts must be enabled
    if (REG_IME == 0)
        return -1;
    ieBak = REG_IE;
    gSTWIStatus->state = ID_CHECK;
    STWI_set_Callback_ID(Sio32IDIntr);
    Sio32IDInit();
    regTMCNTL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    maxTries *= 8;
    while (maxTries--)
    {
        id = Sio32IDMain();
        if (id)
            break;
        regTMCNTL[1] = 0;
        regTMCNTL[0] = 0;
        regTMCNTL[1] = TIMER_1024CLK | TIMER_ENABLE;
        while (regTMCNTL[0] < 32)
            ;
        regTMCNTL[1] = 0;
        regTMCNTL[0] = 0;
    }
    REG_IME = 0;
    REG_IE = ieBak;
    REG_IME = 1;
    gSTWIStatus->state = M_TxREQ;
    STWI_set_Callback_ID(NULL);
    return id;
}

void Sio32IDInit(void)
{
    REG_IME = 0;
    REG_IE &= ~((INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect) | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
    CpuFill32(0, &gRfuSIO32Id, sizeof(struct RfuSIO32Id));
    REG_IF = INTR_FLAG_SERIAL;
}

s32 Sio32IDMain(void)
{
    switch (gRfuSIO32Id.state)
    {
    case 0:
        gRfuSIO32Id.MS_mode = AGB_CLK_MASTER;
        REG_SIOCNT |= SIO_38400_BPS;
        REG_IME = 0;
        REG_IE |= INTR_FLAG_SERIAL;
        REG_IME = 1;
        gRfuSIO32Id.state = 1;
        *(vu8 *)&REG_SIOCNT |= SIO_ENABLE;
        break;
    case 1:
        if (gRfuSIO32Id.lastId == 0)
        {
            if (gRfuSIO32Id.MS_mode == AGB_CLK_MASTER)
            {
                if (gRfuSIO32Id.count == 0)
                {
                    REG_IME = 0;
                    REG_SIOCNT |= SIO_ENABLE;
                    REG_IME = 1;
                }
            }
            else if (gRfuSIO32Id.send_id != RFU_ID && gRfuSIO32Id.count == 0)
            {
                REG_IME = 0;
                REG_IE &= ~INTR_FLAG_SERIAL;
                REG_IME = 1;
                REG_SIOCNT = 0;
                REG_SIOCNT = SIO_32BIT_MODE;
                REG_IF = INTR_FLAG_SERIAL;
                REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
                REG_IME = 0;
                REG_IE |= INTR_FLAG_SERIAL;
                REG_IME = 1;
            }
            break;
        }
        else
        {
            gRfuSIO32Id.state = 2;
            // fallthrough
        }
    default:
        return gRfuSIO32Id.lastId;
    }
    return 0;
}

void Sio32IDIntr(void)
{
    u32 regSIODATA32;
#ifdef UBFIX
    vu16 delay; // Modern compilers delete the empty delay loop below without volatile
#else
    u16 delay; // volatile here would not match
#endif
    u32 receivedHalfword;

    regSIODATA32 = REG_SIODATA32;
    if (gRfuSIO32Id.MS_mode != AGB_CLK_MASTER)
        REG_SIOCNT |= SIO_ENABLE;
    receivedHalfword = (regSIODATA32 << (16 * gRfuSIO32Id.MS_mode)) >> 16;
    regSIODATA32 = (regSIODATA32 << 16 * (1 - gRfuSIO32Id.MS_mode)) >> 16;
    if (gRfuSIO32Id.lastId == 0)
    {
        u16 receivedId = receivedHalfword;
        if (receivedId == gRfuSIO32Id.recv_id)
        {
            if (gRfuSIO32Id.count < ARRAY_COUNT(Sio32ConnectionData))
            {
                u16 complementedSendId = ~gRfuSIO32Id.send_id;
                if (gRfuSIO32Id.recv_id == complementedSendId)
                {
                    if (regSIODATA32 == (u16)~gRfuSIO32Id.recv_id)
                        gRfuSIO32Id.count++;
                }
            }
            else
            {
                gRfuSIO32Id.lastId = regSIODATA32;
            }
        }
        else
        {
            gRfuSIO32Id.count = 0;
        }
    }
    if (gRfuSIO32Id.count < ARRAY_COUNT(Sio32ConnectionData))
        gRfuSIO32Id.send_id = *(gRfuSIO32Id.count + Sio32ConnectionData);
    else
        gRfuSIO32Id.send_id = RFU_ID;
    gRfuSIO32Id.recv_id = ~regSIODATA32;
    REG_SIODATA32 = (gRfuSIO32Id.send_id << 16 * (1 - gRfuSIO32Id.MS_mode))
                  + (gRfuSIO32Id.recv_id << 16 * gRfuSIO32Id.MS_mode);
    if (gRfuSIO32Id.MS_mode == AGB_CLK_MASTER && (gRfuSIO32Id.count != 0 || regSIODATA32 == 0x494e)) // "NI", the start of Sio32ConnectionData
    {
        for (delay = 0; delay < 600; ++delay)
            ;
        if (gRfuSIO32Id.lastId == 0)
            REG_SIOCNT |= SIO_ENABLE;
    }
}
