#include "global.h"
#include "librfu.h"

static void sio32intr_clock_master(void);
static void sio32intr_clock_slave(void);
static u16 handshake_wait(u16 slot);
static void STWI_set_timer_in_RAM(u8 count);
static void STWI_stop_timer_in_RAM(void);
static void STWI_init_slave(void);
static void Callback_Dummy_M(int reqCommandId, int error, void (*callbackM)());
static void Callback_Dummy_S(u16 reqCommandId, void (*callbackS)(u16));
static void Callback_Dummy_ID(void (*callbackId)(void));

void IntrSIO32(void)
{
    if (gSTWIStatus->state == 10)
    {
        if (gSTWIStatus->callbackID != NULL)
            Callback_Dummy_ID(gSTWIStatus->callbackID);
    }
    else
    {
        if (gSTWIStatus->msMode == AGB_CLK_MASTER)
            sio32intr_clock_master();
        else
            sio32intr_clock_slave();
    }
}

static void sio32intr_clock_master(void)
{
    u32 regSIODATA32;
    u32 ackLen;

    STWI_set_timer_in_RAM(80);
    regSIODATA32 = REG_SIODATA32;

    if (gSTWIStatus->state == 0) // master send req
    {
        if (regSIODATA32 == 0x80000000)
        {
            if (gSTWIStatus->reqNext <= gSTWIStatus->reqLength)
            {
                REG_SIODATA32 = ((u32*)gSTWIStatus->txPacket->rfuPacket8.data)[gSTWIStatus->reqNext];
                gSTWIStatus->reqNext++;
            }
            else
            {
                gSTWIStatus->state = 1; // master wait ack
                REG_SIODATA32 = 0x80000000;
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(130);
            return;
        }
    }
    else if (gSTWIStatus->state == 1) // master wait ack
    {
        if ((regSIODATA32 & 0xFFFF0000) == 0x99660000)
        {
            gSTWIStatus->ackNext = 0;
            ((u32*)gSTWIStatus->rxPacket)[gSTWIStatus->ackNext] = regSIODATA32;
            gSTWIStatus->ackNext++;
            gSTWIStatus->ackActiveCommand = regSIODATA32;
            gSTWIStatus->ackLength = ackLen = regSIODATA32 >> 8;
            if ((ackLen = gSTWIStatus->ackLength) >= gSTWIStatus->ackNext)
            {
                gSTWIStatus->state = 2; // master receive ack
                REG_SIODATA32 = 0x80000000;
            }
            else
            {
                gSTWIStatus->state = 3; // master done ack
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(130);
            return;
        }
    }
    else if (gSTWIStatus->state == 2) // master receive ack
    {
        ((u32*)gSTWIStatus->rxPacket)[gSTWIStatus->ackNext] = regSIODATA32;
        gSTWIStatus->ackNext++;
        if (gSTWIStatus->ackLength < gSTWIStatus->ackNext)
            gSTWIStatus->state = 3; // master done ack
        else
            REG_SIODATA32 = 0x80000000;
    }

    if (handshake_wait(1) == 1)
        return;

    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS | SIO_MULTI_SD;

    if (handshake_wait(0) == 1)
        return;

    STWI_stop_timer_in_RAM();

    if (gSTWIStatus->state == 3) // master done ack
    {
        if (
            gSTWIStatus->ackActiveCommand == (0x80 | ID_MS_CHANGE_REQ)
         || gSTWIStatus->ackActiveCommand == (0x80 | ID_DATA_TX_AND_CHANGE_REQ)
         || gSTWIStatus->ackActiveCommand == (0x80 | ID_UNK35_REQ)
         || gSTWIStatus->ackActiveCommand == (0x80 | ID_RESUME_RETRANSMIT_AND_CHANGE_REQ)
        )
        {

            gSTWIStatus->msMode = AGB_CLK_SLAVE;
            REG_SIODATA32 = 0x80000000;
            REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS;
            REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_ENABLE;
            gSTWIStatus->state = 5; // slave receive req init
        }
        else
        {
            if (gSTWIStatus->ackActiveCommand == 0xEE)
            {
                REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
                gSTWIStatus->state = 4; // error
                gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
            }
            else
            {
                REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
                gSTWIStatus->state = 4; // error
            }
        }
        gSTWIStatus->sending = 0;
        if (gSTWIStatus->callbackM != NULL)
            Callback_Dummy_M(gSTWIStatus->reqActiveCommand, gSTWIStatus->error, gSTWIStatus->callbackM);
    }
    else
    {
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS | SIO_ENABLE;
    }
}

static void sio32intr_clock_slave(void)
{
    u32 regSIODATA32;
    u32 r0;
    u32 reqLen;

    gSTWIStatus->timerActive = 0;
    STWI_set_timer_in_RAM(100);
    if (handshake_wait(0) == 1)
        return;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_MULTI_SD;
    regSIODATA32 = REG_SIODATA32;
    if (gSTWIStatus->state == 5) // slave receive req init
    {
        ((u32*)gSTWIStatus->rxPacket)[0] = regSIODATA32;
        gSTWIStatus->reqNext = 1;
        r0 = 0x99660000;
        // variable reuse required
        reqLen = (regSIODATA32 >> 16);
        if (reqLen == (r0 >> 16))
        {
            // only reqLen = regSIODATA32 >> 8 is needed to match, but it looks a bit
            // more consistent when both lines update the variables. Might have been a macro?
            gSTWIStatus->reqLength = reqLen = (regSIODATA32 >> 8);
            gSTWIStatus->reqActiveCommand = reqLen = (regSIODATA32 >> 0);
            if (gSTWIStatus->reqLength == 0)
            {
                if (
                    gSTWIStatus->reqActiveCommand == ID_MS_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_DATA_READY_AND_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_DISCONNECTED_AND_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_UNK36_REQ
                )
                {
                    gSTWIStatus->ackActiveCommand = gSTWIStatus->reqActiveCommand + 0x80;
                    ((u32*)gSTWIStatus->txPacket)[0] = 0x99660000 + gSTWIStatus->ackActiveCommand;
                    gSTWIStatus->ackLength = 0;
                }
                else
                {
                    ((u32*)gSTWIStatus->txPacket)[0] = 0x996601EE;
                    if (gSTWIStatus->reqActiveCommand >= 0x10 && gSTWIStatus->reqActiveCommand <= 0x3D)
                    {
                        ((u32*)gSTWIStatus->txPacket)[1] = 1;
                    }
                    else
                    {
                        ((u32*)gSTWIStatus->txPacket)[1] = 2;
                    }
                    gSTWIStatus->ackLength = 1;
                    gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
                }
                REG_SIODATA32 = ((u32*)gSTWIStatus->txPacket)[0];
                gSTWIStatus->ackNext = 1;
                gSTWIStatus->state = 7; // slave send ack
            }
            else
            {
                REG_SIODATA32 = 0x80000000;
                gSTWIStatus->reqNext = 1;
                gSTWIStatus->state = 6; // slave receive req
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(100);
            return;
        }
    }
    else if (gSTWIStatus->state == 6) // slave receive req
    {
        ((u32*)gSTWIStatus->rxPacket)[gSTWIStatus->reqNext] = regSIODATA32;
        gSTWIStatus->reqNext++;
        if (gSTWIStatus->reqLength < gSTWIStatus->reqNext)
        {
            if (
                gSTWIStatus->reqActiveCommand == ID_DATA_READY_AND_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_DISCONNECTED_AND_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_UNK36_REQ
            )
            {
                gSTWIStatus->ackActiveCommand = gSTWIStatus->reqActiveCommand + 0x80;
                ((u32*)gSTWIStatus->txPacket)[0] = 0x99660000 | gSTWIStatus->ackActiveCommand;
                gSTWIStatus->ackLength = 0;
            }
            else
            {
                ((u32*)gSTWIStatus->txPacket)[0] = 0x996601EE;
                if (gSTWIStatus->reqActiveCommand >= 0x10 && gSTWIStatus->reqActiveCommand <= 0x3D)
                {
                    ((u32*)gSTWIStatus->txPacket)[1] = 1;
                }
                else
                {
                    ((u32*)gSTWIStatus->txPacket)[1] = 2;
                }
                gSTWIStatus->ackLength = 1;
                gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
            }
            REG_SIODATA32 = ((u32*)gSTWIStatus->txPacket)[0];
            gSTWIStatus->ackNext = 1;
            gSTWIStatus->state = 7; // slave send ack
        }
        else
        {
            REG_SIODATA32 = 0x80000000;
        }
    }
    else if (gSTWIStatus->state == 7) // slave send ack
    {
        if (regSIODATA32 == 0x80000000)
        {
            if (gSTWIStatus->ackLength < gSTWIStatus->ackNext)
            {
                gSTWIStatus->state = 8; // slave done ack
            }
            else
            {
                REG_SIODATA32 = ((u32*)gSTWIStatus->txPacket)[gSTWIStatus->ackNext];
                gSTWIStatus->ackNext++;
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(100);
            return;
        }
    }
    if (handshake_wait(1) == 1)
        return;
    if (gSTWIStatus->state == 8) // slave done ack
    {
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS;
        STWI_stop_timer_in_RAM();
        if (gSTWIStatus->error == ERR_REQ_CMD_ACK_REJECTION)
        {
            STWI_init_slave();
            if (gSTWIStatus->callbackS != NULL)
            {
                Callback_Dummy_S(0x1EE, gSTWIStatus->callbackS);
            }
        }
        else
        {
            REG_SIODATA32 = 0;
            REG_SIOCNT = 0;
            REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
            gSTWIStatus->msMode = AGB_CLK_MASTER;
            gSTWIStatus->state = 0; // master send req
            if (gSTWIStatus->callbackS != NULL)
            {
                Callback_Dummy_S((gSTWIStatus->reqLength << 8) | (gSTWIStatus->reqActiveCommand), gSTWIStatus->callbackS);
            }
        }
    }
    else
    {
        REG_IME = 0;
        if (REG_TM0CNT_H & TIMER_ENABLE)
        {
            if ((REG_TM0CNT_H & 0x03) == TIMER_1CLK)
            {
                while (REG_TM0CNT_L > 0xFF9B);
            }
            else
            {
                while (REG_TM0CNT_L > 0xFFFE);
            }
        }
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS;
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_ENABLE;
        REG_IME = 1;
    }
}

static u16 handshake_wait(u16 slot)
{
    do
    {
        if ((gSTWIStatus->timerActive & 0xFF) == 1)
        {
            gSTWIStatus->timerActive = 0;
            return 1;
        }
    } while ((REG_SIOCNT & SIO_MULTI_SI) != (slot << SIO_MULTI_SI_SHIFT));
    return 0;
}

static void STWI_set_timer_in_RAM(u8 count)
{
    vu16* regTMCNTL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    vu16* regTMCNTH = &REG_TMCNT_H(gSTWIStatus->timerSelect);
    REG_IME = 0;
    switch (count)
    {
    case 50:
        *regTMCNTL = 0xFCCB;
        gSTWIStatus->timerState = 1;
        break;
    case 80:
        *regTMCNTL = 0xFAE0;
        gSTWIStatus->timerState = 2;
        break;
    case 100:
        *regTMCNTL = 0xF996;
        gSTWIStatus->timerState = 3;
        break;
    case 130:
        *regTMCNTL = 0xF7AD;
        gSTWIStatus->timerState = 4;
        break;
    }
    *regTMCNTH = TIMER_ENABLE | TIMER_64CLK | TIMER_256CLK | TIMER_INTR_ENABLE;
    REG_IF = INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect;
    REG_IME = 1;
}

static void STWI_stop_timer_in_RAM(void)
{
    gSTWIStatus->timerState = 0;
    REG_TMCNT_L(gSTWIStatus->timerSelect) = 0;
    REG_TMCNT_H(gSTWIStatus->timerSelect) = 0;
}

static void STWI_init_slave(void)
{
    gSTWIStatus->state = 5; // slave receive req init
    gSTWIStatus->msMode = AGB_CLK_SLAVE;
    gSTWIStatus->reqLength = 0;
    gSTWIStatus->reqNext = 0;
    gSTWIStatus->reqActiveCommand = 0;
    gSTWIStatus->ackLength = 0;
    gSTWIStatus->ackNext = 0;
    gSTWIStatus->ackActiveCommand = 0;
    gSTWIStatus->timerState = 0;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->error = 0;
    gSTWIStatus->recoveryCount = 0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_ENABLE;
}

NAKED
static void Callback_Dummy_M(int reqCommandId, int error, void (*callbackM)())
{
    asm("bx r2");
}

NAKED
static void Callback_Dummy_S(u16 reqCommandId, void (*callbackS)(u16))
{
    asm("bx r1");
}

NAKED
static void Callback_Dummy_ID(void (*callbackId)(void))
{
    asm("bx r0");
}
