#include "global.h"
#include "librfu_stwi_private.h"

void sio32intr_clock_master(void);
void sio32intr_clock_slave(void);
u16 handshake_wait(u16 slot);
void STWI_set_timer_in_RAM(u8 count);
void STWI_stop_timer_in_RAM(void);
void STWI_init_slave(void);
void Callback_Dummy_M(int reqCommandId, int error, void (*callbackM)(u8, u16));
void Callback_Dummy_S(u16 reqCommandId, void (*callbackS)(u16));
void Callback_Dummy_ID(void (*callbackId)(void));

void IntrSIO32(void)
{
    if (gSTWIStatus->state == ID_CHECK)
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

void sio32intr_clock_master(void)
{
    u32 regSIODATA32;
    u32 ackLen;

    STWI_set_timer_in_RAM(80);
    regSIODATA32 = REG_SIODATA32;

    if (gSTWIStatus->state == M_TxREQ)
    {
        if (regSIODATA32 == 0x80000000)
        {
            if (gSTWIStatus->reqNext <= gSTWIStatus->reqLength)
            {
                REG_SIODATA32 = gSTWIStatus->txPacket[gSTWIStatus->reqNext];
                gSTWIStatus->reqNext++;
            }
            else
            {
                gSTWIStatus->state = M_RxACK_HEADER;
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
    else if (gSTWIStatus->state == M_RxACK_HEADER)
    {
        if ((regSIODATA32 & 0xFFFF0000) == 0x99660000)
        {
            gSTWIStatus->ackNext = 0;
            gSTWIStatus->rxPacket[gSTWIStatus->ackNext] = regSIODATA32;
            gSTWIStatus->ackNext++;
            gSTWIStatus->ackActiveCommand = (u8)regSIODATA32;
            ackLen = regSIODATA32 >> 8;
            gSTWIStatus->ackLength = ackLen;
            // ackLen is truncated to u8 when stored in gSTWIStatus->ackLength.
            ackLen = gSTWIStatus->ackLength;
            if (ackLen >= gSTWIStatus->ackNext)
            {
                gSTWIStatus->state = M_RxACK_CONTENTS;
                REG_SIODATA32 = 0x80000000;
            }
            else
            {
                gSTWIStatus->state = M_RxACK_END;
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(130);
            return;
        }
    }
    else if (gSTWIStatus->state == M_RxACK_CONTENTS)
    {
        gSTWIStatus->rxPacket[gSTWIStatus->ackNext] = regSIODATA32;
        gSTWIStatus->ackNext++;
        if (gSTWIStatus->ackLength < gSTWIStatus->ackNext)
            gSTWIStatus->state = M_RxACK_END;
        else
            REG_SIODATA32 = 0x80000000;
    }

    if (handshake_wait(1) == 1)
        return;

    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS | SIO_MULTI_SD;

    if (handshake_wait(0) == 1)
        return;

    STWI_stop_timer_in_RAM();

    if (gSTWIStatus->state == M_RxACK_END)
    {
        if (
            gSTWIStatus->ackActiveCommand == (STWI_ACK_FLAG | ID_MS_CHANGE_REQ)
         || gSTWIStatus->ackActiveCommand == (STWI_ACK_FLAG | ID_DATA_TX_AND_CHANGE_REQ)
         || gSTWIStatus->ackActiveCommand == (STWI_ACK_FLAG | ID_UNK35_REQ)
         || gSTWIStatus->ackActiveCommand == (STWI_ACK_FLAG | ID_RESUME_RETRANSMIT_AND_CHANGE_REQ)
        )
        {

            gSTWIStatus->msMode = AGB_CLK_SLAVE;
            REG_SIODATA32 = 0x80000000;
            REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS;
            REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_ENABLE;
            gSTWIStatus->state = S_RxREQ_HEADER;
        }
        else
        {
            if (gSTWIStatus->ackActiveCommand == 0xEE)
            {
                REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
                gSTWIStatus->state = M_COMPLETE;
                gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
            }
            else
            {
                REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
                gSTWIStatus->state = M_COMPLETE;
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

void sio32intr_clock_slave(void)
{
    u32 regSIODATA32;
    u32 headerWord;
    u32 extractedValue;

    gSTWIStatus->timerActive = 0;
    STWI_set_timer_in_RAM(100);
    if (handshake_wait(0) == 1)
        return;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_MULTI_SD;
    regSIODATA32 = REG_SIODATA32;
    if (gSTWIStatus->state == S_RxREQ_HEADER)
    {
        gSTWIStatus->rxPacket[0] = regSIODATA32;
        gSTWIStatus->reqNext = 1;
        // Check the 0x9966 sync half of the REQ header.
        headerWord = 0x99660000;
        extractedValue = regSIODATA32 >> 16;
        if (extractedValue == (headerWord >> 16))
        {
            extractedValue = regSIODATA32 >> 8;
            gSTWIStatus->reqLength = extractedValue;
            gSTWIStatus->reqActiveCommand = regSIODATA32;
            if (gSTWIStatus->reqLength == 0)
            {
                if (
                    gSTWIStatus->reqActiveCommand == ID_MS_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_DATA_READY_AND_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_DISCONNECTED_AND_CHANGE_REQ
                 || gSTWIStatus->reqActiveCommand == ID_UNK36_REQ
                )
                {
                    gSTWIStatus->ackActiveCommand = gSTWIStatus->reqActiveCommand + STWI_ACK_FLAG;
                    gSTWIStatus->txPacket[0] = 0x99660000 + gSTWIStatus->ackActiveCommand;
                    gSTWIStatus->ackLength = 0;
                }
                else
                {
                    gSTWIStatus->txPacket[0] = 0x996601EE;
                    if (gSTWIStatus->reqActiveCommand >= 0x10 && gSTWIStatus->reqActiveCommand <= 0x3D)
                    {
                        gSTWIStatus->txPacket[1] = 1;
                    }
                    else
                    {
                        gSTWIStatus->txPacket[1] = 2;
                    }
                    gSTWIStatus->ackLength = 1;
                    gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
                }
                REG_SIODATA32 = gSTWIStatus->txPacket[0];
                gSTWIStatus->ackNext = 1;
                gSTWIStatus->state = S_TxACK;
            }
            else
            {
                REG_SIODATA32 = 0x80000000;
                gSTWIStatus->reqNext = 1;
                gSTWIStatus->state = S_RxREQ_CONTENTS;
            }
        }
        else
        {
            STWI_stop_timer_in_RAM();
            STWI_set_timer_in_RAM(100);
            return;
        }
    }
    else if (gSTWIStatus->state == S_RxREQ_CONTENTS)
    {
        gSTWIStatus->rxPacket[gSTWIStatus->reqNext] = regSIODATA32;
        gSTWIStatus->reqNext++;
        if (gSTWIStatus->reqLength < gSTWIStatus->reqNext)
        {
            if (
                gSTWIStatus->reqActiveCommand == ID_DATA_READY_AND_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_DISCONNECTED_AND_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_UNK36_REQ
            )
            {
                gSTWIStatus->ackActiveCommand = gSTWIStatus->reqActiveCommand + STWI_ACK_FLAG;
                gSTWIStatus->txPacket[0] = 0x99660000 + gSTWIStatus->ackActiveCommand;
                gSTWIStatus->ackLength = 0;
            }
            else
            {
                gSTWIStatus->txPacket[0] = 0x996601EE;
                if (gSTWIStatus->reqActiveCommand >= 0x10 && gSTWIStatus->reqActiveCommand <= 0x3D)
                {
                    gSTWIStatus->txPacket[1] = 1;
                }
                else
                {
                    gSTWIStatus->txPacket[1] = 2;
                }
                gSTWIStatus->ackLength = 1;
                gSTWIStatus->error = ERR_REQ_CMD_ACK_REJECTION;
            }
            REG_SIODATA32 = gSTWIStatus->txPacket[0];
            gSTWIStatus->ackNext = 1;
            gSTWIStatus->state = S_TxACK;
        }
        else
            REG_SIODATA32 = 0x80000000;
    }
    else if (gSTWIStatus->state == S_TxACK)
    {
        if (regSIODATA32 == 0x80000000)
        {
            if (gSTWIStatus->ackLength < gSTWIStatus->ackNext)
            {
                gSTWIStatus->state = S_TxACK_END;
            }
            else
            {
                REG_SIODATA32 = gSTWIStatus->txPacket[gSTWIStatus->ackNext];
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
    if (gSTWIStatus->state == S_TxACK_END)
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
            gSTWIStatus->state = M_TxREQ;
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

u16 handshake_wait(u16 slot)
{
    do
    {
        if (gSTWIStatus->timerActive == 1)
        {
            gSTWIStatus->timerActive = 0;
            return 1;
        }
    } while ((REG_SIOCNT & SIO_MULTI_SI) != (slot << SIO_MULTI_SI_SHIFT));
    return 0;
}

void STWI_set_timer_in_RAM(u8 count)
{
    vu16 *regTMCNTL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    vu16 *regTMCNTH = &REG_TMCNT_H(gSTWIStatus->timerSelect);
    REG_IME = 0;
    switch (count)
    {
    case 50:
        *regTMCNTL = 0xFCCB;
        gSTWIStatus->timerState = WAIT50MS;
        break;
    case 80:
        *regTMCNTL = 0xFAE0;
        gSTWIStatus->timerState = WAIT80MS;
        break;
    case 100:
        *regTMCNTL = 0xF996;
        gSTWIStatus->timerState = WAIT100MS;
        break;
    case 130:
        *regTMCNTL = 0xF7AD;
        gSTWIStatus->timerState = WAIT130MS;
        break;
    }
    *regTMCNTH = TIMER_ENABLE | TIMER_64CLK | TIMER_256CLK | TIMER_INTR_ENABLE;
    REG_IF = INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect;
    REG_IME = 1;
}

void STWI_stop_timer_in_RAM(void)
{
    gSTWIStatus->timerState = NOT_USED;
    REG_TMCNT_L(gSTWIStatus->timerSelect) = 0;
    REG_TMCNT_H(gSTWIStatus->timerSelect) = 0;
}

void STWI_init_slave(void)
{
    gSTWIStatus->state = S_RxREQ_HEADER;
    gSTWIStatus->msMode = AGB_CLK_SLAVE;
    gSTWIStatus->reqLength = 0;
    gSTWIStatus->reqNext = 0;
    gSTWIStatus->reqActiveCommand = 0;
    gSTWIStatus->ackLength = 0;
    gSTWIStatus->ackNext = 0;
    gSTWIStatus->ackActiveCommand = 0;
    gSTWIStatus->timerState = NOT_USED;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->error = 0;
    gSTWIStatus->recoveryCount = 0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_57600_BPS | SIO_ENABLE;
}

NAKED
void Callback_Dummy_M(int reqCommandId, int error, void (*callbackM)(u8, u16))
{
    asm("bx r2");
}

NAKED
void Callback_Dummy_S(u16 reqCommandId, void (*callbackS)(u16))
{
    asm("bx r1");
}

NAKED
void Callback_Dummy_ID(void (*callbackId)(void))
{
    asm("bx r0");
}
