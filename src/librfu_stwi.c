#include "global.h"
#include "librfu.h"

struct STWIStatus *gSTWIStatus;

extern IntrFunc IntrSIO32(void);

extern void STWI_stop_timer(void);

void STWI_init_Callback_M(void);
void STWI_init_Callback_S(void);
void STWI_set_Callback_M(void * callback);
void STWI_set_Callback_S(void * callback);
u16 STWI_init(u8 request);
int STWI_start_Command(void);
void STWI_intr_timer(void);
void STWI_set_timer(u8 unk);

int STWI_restart_Command(void);
int STWI_reset_ClockCounter(void);

void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
    // If we're copying our interrupt into RAM, DMA it to block1 and use
    // block2 for our STWIStatus, otherwise block1 holds the STWIStatus.
    // interrupt usually is a pointer to gIntrTable[1]
    if (copyInterruptToRam == TRUE)
    {
        *interrupt = (IntrFunc)interruptStruct->block1;
        DmaCopy16(3, &IntrSIO32, interruptStruct->block1, 0x960);
        gSTWIStatus = (struct STWIStatus*)interruptStruct->block2;
    }
    else
    {
        *interrupt = (IntrFunc)IntrSIO32;
        gSTWIStatus = (struct STWIStatus*)interruptStruct->block1;
    }

    gSTWIStatus->rxPacket = (union RfuPacket*)interruptStruct->rxPacketAlloc;
    gSTWIStatus->txPacket = (union RfuPacket*)interruptStruct->txPacketAlloc;
    gSTWIStatus->msMode = 1;
    gSTWIStatus->unk_0 = 0;
    gSTWIStatus->txParams = 0;
    gSTWIStatus->unk_5 = 0;
    gSTWIStatus->unk_7 = 0;
    gSTWIStatus->unk_8 = 0;
    gSTWIStatus->unk_9 = 0;
    gSTWIStatus->timerState = 0;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->unk_12 = 0;
    gSTWIStatus->unk_15 = 0;
    gSTWIStatus->unk_2c = 0;

    REG_RCNT = 0x100; //TODO: mystery bit?
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    STWI_init_Callback_M();
    STWI_init_Callback_S();

    IntrEnable(INTR_FLAG_SERIAL);
}

void STWI_init_timer(IntrFunc *interrupt, int timerSelect)
{
    *interrupt = STWI_intr_timer;
    gSTWIStatus->timerSelect = timerSelect;

    IntrEnable(INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect);
}

void AgbRFU_SoftReset(void)
{
    vu16 *timerL;
    vu16 *timerH;

    REG_RCNT = 0x8000;
    REG_RCNT = 0x80A0; // all these bits are undocumented
    timerL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    timerH = &REG_TMCNT_H(gSTWIStatus->timerSelect);
    *timerH = 0;
    *timerL = 0;
    *timerH = 0x83;
    while (*timerL <= 0x11)
        REG_RCNT = 0x80A2;
    *timerH = 3;
    REG_RCNT = 0x80A0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;

    gSTWIStatus->unk_0 = 0;
    gSTWIStatus->txParams = 0;
    gSTWIStatus->unk_5 = 0;
    gSTWIStatus->activeCommand = 0;
    gSTWIStatus->unk_7 = 0;
    gSTWIStatus->unk_8 = 0;
    gSTWIStatus->unk_9 = 0;
    gSTWIStatus->timerState = 0;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->unk_12 = 0;
    gSTWIStatus->msMode = 1;
    gSTWIStatus->unk_15 = 0;
    gSTWIStatus->unk_2c = 0;
}

void STWI_set_MS_mode(u8 mode)
{
    gSTWIStatus->msMode = mode;
}

u16 STWI_read_status(u8 index)
{
    switch (index)
    {
    case 0:
        return gSTWIStatus->unk_12;
    case 1:
        return gSTWIStatus->msMode;
    case 2:
        return gSTWIStatus->unk_0;
    case 3:
        return gSTWIStatus->activeCommand;
    default:
        return 0xFFFF;
    }
}

void STWI_init_Callback_M(void)
{
    STWI_set_Callback_M(0);
}

void STWI_init_Callback_S(void)
{
    STWI_set_Callback_S(0);
}

void STWI_set_Callback_M(void *callback)
{
    gSTWIStatus->callbackM = callback;
}

void STWI_set_Callback_S(void *callback)
{
    gSTWIStatus->callbackS = callback;
}

void STWI_set_Callback_ID(u32 id)
{
    gSTWIStatus->callbackID = id;
}

u16 STWI_poll_CommandEnd(void)
{
    while (gSTWIStatus->unk_2c == TRUE)
        ;
    return gSTWIStatus->unk_12;
}

void STWI_send_ResetREQ(void)
{
    if (!STWI_init(RFU_RESET))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_LinkStatusREQ(void)
{
    if (!STWI_init(RFU_LINK_STATUS))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_VersionStatusREQ(void)
{
    if (!STWI_init(RFU_VERSION_STATUS))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SystemStatusREQ(void)
{
    if (!STWI_init(RFU_SYSTEM_STATUS))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SlotStatusREQ(void)
{
    if (!STWI_init(RFU_SLOT_STATUS))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_ConfigStatusREQ(void)
{
    if (!STWI_init(RFU_CONFIG_STATUS))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_GameConfigREQ(u8 * unk1, u8 *data)
{
    u8 *packetBytes;
    int i;

    if (!STWI_init(RFU_GAME_CONFIG))
    {
        gSTWIStatus->txParams = 6;

        //TODO: what is unk1
        packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
        packetBytes += sizeof(u32);
        *(u16*)packetBytes = *(u16*)unk1;

        packetBytes += sizeof(u16);
        unk1 += sizeof(u16);

        for (i = 0; i < 14; i++)
        {
            *packetBytes = *unk1;
            packetBytes++;
            unk1++;
        }

        for (i = 0; i < 8; i++)
        {
            *packetBytes = *data;
            packetBytes++;
            data++;
        }

        STWI_start_Command();
    }
}

void STWI_send_SystemConfigREQ(u16 unk1, u8 unk2, u8 unk3)
{
    if (!STWI_init(RFU_SYSTEM_CONFIG))
    {
        u8 *packetBytes;

        gSTWIStatus->txParams = 1;

        packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
        packetBytes += sizeof(u32);

        *packetBytes++ = unk3;
        *packetBytes++ = unk2;
        *(u16*)packetBytes = unk1;
        STWI_start_Command();
    }
}

void STWI_send_SC_StartREQ(void)
{
    if (!STWI_init(RFU_SC_START))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_PollingREQ(void)
{
    if (!STWI_init(RFU_SC_POLLING))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_EndREQ(void)
{
    if (!STWI_init(RFU_SC_END))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_StartREQ(void)
{
    if (!STWI_init(RFU_SP_START))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_PollingREQ(void)
{
    if (!STWI_init(RFU_SP_POLLING))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_EndREQ(void)
{
    if (!STWI_init(RFU_SP_END))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_StartREQ(u16 unk1)
{
    if (!STWI_init(RFU_CP_START))
    {
        gSTWIStatus->txParams = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk1;
        STWI_start_Command();
    }
}

void STWI_send_CP_PollingREQ(void)
{
    if (!STWI_init(RFU_CP_POLLING))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_EndREQ(void)
{
    if (!STWI_init(RFU_CP_END))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_DataTxREQ(void *in, u8 size)
{
    if (!STWI_init(RFU_DATA_TX))
    {
        u8 txParams = (size / sizeof(u32));
        if (size & (sizeof(u32) - 1))
            txParams += 1;

        gSTWIStatus->txParams = txParams;
        CpuCopy32(in, gSTWIStatus->txPacket->rfuPacket32.data, gSTWIStatus->txParams * sizeof(u32));
        STWI_start_Command();
    }
}

void STWI_send_DataTxAndChangeREQ(void *in, u8 size)
{
    if (!STWI_init(RFU_DATA_TX_AND_CHANGE))
    {
        u8 txParams = (size / sizeof(u32));
        if (size & (sizeof(u32) - 1))
            txParams += 1;

        gSTWIStatus->txParams = txParams;
        CpuCopy32(in, gSTWIStatus->txPacket->rfuPacket32.data, gSTWIStatus->txParams * sizeof(u32));
        STWI_start_Command();
    }
}

void STWI_send_DataRxREQ(void)
{
    if (!STWI_init(RFU_DATA_RX))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_MS_ChangeREQ(void)
{
    if (!STWI_init(RFU_MS_CHANGE))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_DataReadyAndChangeREQ(u8 unk)
{
    if (!STWI_init(RFU_DATA_READY_AND_CHANGE))
    {
        if (!unk)
        {
            gSTWIStatus->txParams = 0;
        }
        else
        {
            u8 *packetBytes;

            gSTWIStatus->txParams = 1;

            packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
            packetBytes += sizeof(u32);

            *packetBytes++ = unk;
            *packetBytes++ = 0;
            *packetBytes++ = 0;
            *packetBytes = 0;
        }

        STWI_start_Command();
    }
}

void STWI_send_DisconnectedAndChangeREQ(u8 unk0, u8 unk1)
{
    if (!STWI_init(RFU_DISCONNECTED_AND_CHANGE))
    {
        u8 *packetBytes;

        gSTWIStatus->txParams = 1;

        packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
        packetBytes += sizeof(u32);

        *packetBytes++ = unk0;
        *packetBytes++ = unk1;
        *packetBytes++ = 0;
        *packetBytes = 0;

        STWI_start_Command();
    }
}

void STWI_send_ResumeRetransmitAndChangeREQ(void)
{
    if (!STWI_init(RFU_RESUME_RETRANSMIT_AND_CHANGE))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_DisconnectREQ(u8 unk)
{
    if (!STWI_init(RFU_DISCONNECT))
    {
        gSTWIStatus->txParams = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk;

        STWI_start_Command();
    }
}

void STWI_send_TestModeREQ(u8 unk0, u8 unk1)
{
    if (!STWI_init(RFU_TEST_MODE))
    {
        gSTWIStatus->txParams = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk0 | (unk1 << 8);

        STWI_start_Command();
    }
}

void STWI_send_CPR_StartREQ(u16 unk0, u16 unk1, u8 unk2)
{
    u32 *packetData;
    u32 arg1;

    if (!STWI_init(RFU_CPR_START))
    {
        gSTWIStatus->txParams = 2;

        arg1 = unk1 | (unk0 << 16);
        packetData = gSTWIStatus->txPacket->rfuPacket32.data;
        packetData[0] = arg1;
        packetData[1] = unk2;

        STWI_start_Command();
    }
}

void STWI_send_CPR_PollingREQ(void)
{
    if (!STWI_init(RFU_CPR_POLLING))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_CPR_EndREQ(void)
{
    if (!STWI_init(RFU_CPR_END))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_StopModeREQ(void)
{
    if (!STWI_init(RFU_STOP_MODE))
    {
        gSTWIStatus->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_intr_timer(void)
{
    switch (gSTWIStatus->timerState)
    {
        //TODO: Make an enum for these
        case 2:
            gSTWIStatus->timerActive = 1;
            STWI_set_timer(50);
            break;
        case 1:
        case 4:
            STWI_stop_timer();
            STWI_restart_Command();
            break;
        case 3:
            gSTWIStatus->timerActive = 1;
            STWI_stop_timer();
            STWI_reset_ClockCounter();
            if (gSTWIStatus->callbackM)
                gSTWIStatus->callbackM(255, 0);
            break;
    }
}

void STWI_set_timer(u8 unk)
{
    vu16 *timerL;
    vu16 *timerH;

    timerL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    timerH = &REG_TMCNT_H(gSTWIStatus->timerSelect);
    REG_IME = 0;
    switch (unk)
    {
        case 50:
            *timerL = 0xFCCB;
            gSTWIStatus->timerState = 1;
            break;
        case 80:
            *timerL = 0xFAE0;
            gSTWIStatus->timerState = 2;
            break;
        case 100:
            *timerL = 0xF996;
            gSTWIStatus->timerState = 3;
            break;
        case 130:
            *timerL = 0xF7AD;
            gSTWIStatus->timerState = 4;
            break;
    }
    *timerH = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_1024CLK;
    REG_IF = INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect;
    REG_IME = 1;
}

void STWI_stop_timer(void)
{
    gSTWIStatus->timerState = 0;

    REG_TMCNT_L(gSTWIStatus->timerSelect) = 0;
    REG_TMCNT_H(gSTWIStatus->timerSelect) = 0;
}

u16 STWI_init(u8 request)
{
    if (!REG_IME)
    {
        gSTWIStatus->unk_12 = 6;
        if (gSTWIStatus->callbackM)
            gSTWIStatus->callbackM(request, gSTWIStatus->unk_12);
        return TRUE;
    }
    else if (gSTWIStatus->unk_2c == TRUE)
    {
        gSTWIStatus->unk_12 = 2;
        gSTWIStatus->unk_2c = FALSE;
        if (gSTWIStatus->callbackM)
            gSTWIStatus->callbackM(request, gSTWIStatus->unk_12);
        return TRUE;
    }
    else if(!gSTWIStatus->msMode)
    {
        gSTWIStatus->unk_12 = 4;
        if (gSTWIStatus->callbackM)
            gSTWIStatus->callbackM(request, gSTWIStatus->unk_12, gSTWIStatus);
        return TRUE;
    }
    else
    {
        gSTWIStatus->unk_2c = TRUE;
        gSTWIStatus->activeCommand = request;
        gSTWIStatus->unk_0 = 0;
        gSTWIStatus->txParams = 0;
        gSTWIStatus->unk_5 = 0;
        gSTWIStatus->unk_7 = 0;
        gSTWIStatus->unk_8 = 0;
        gSTWIStatus->unk_9 = 0;
        gSTWIStatus->timerState = 0;
        gSTWIStatus->timerActive = 0;
        gSTWIStatus->unk_12 = 0;
        gSTWIStatus->unk_15 = 0;

        REG_RCNT = 0x100;
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
        return FALSE;
    }
}

int STWI_start_Command()
{
    u16 imeTemp;

    // Yes, it matters that it's casted to a u32...
    *(u32*)gSTWIStatus->txPacket->rfuPacket8.data = 0x99660000 | (gSTWIStatus->txParams << 8) | gSTWIStatus->activeCommand;
    REG_SIODATA32 = gSTWIStatus->txPacket->rfuPacket32.command;

    gSTWIStatus->unk_0 = 0;
    gSTWIStatus->unk_5 = 1;

    imeTemp = REG_IME;
    REG_IME = 0;
    REG_IE |= (INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect);
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = imeTemp;

    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_MULTI_BUSY | SIO_115200_BPS;

    return 0;
}

int STWI_restart_Command(void)
{
    if (gSTWIStatus->unk_15 <= 1)
    {
        gSTWIStatus->unk_15++;
        STWI_start_Command();
    }
    else
    {
        if (gSTWIStatus->activeCommand == RFU_MS_CHANGE || gSTWIStatus->activeCommand == RFU_DATA_TX_AND_CHANGE || gSTWIStatus->activeCommand == RFU_UNK35 || gSTWIStatus->activeCommand == RFU_RESUME_RETRANSMIT_AND_CHANGE)
        {
            gSTWIStatus->unk_12 = 1;
            gSTWIStatus->unk_2c = 0;

            if (gSTWIStatus->callbackM)
                gSTWIStatus->callbackM(gSTWIStatus->activeCommand, gSTWIStatus->unk_12);
        }
        else
        {
            gSTWIStatus->unk_12 = 1;
            gSTWIStatus->unk_2c = 0;

            if (gSTWIStatus->callbackM)
                gSTWIStatus->callbackM(gSTWIStatus->activeCommand, gSTWIStatus->unk_12);

            gSTWIStatus->unk_0 = 4; //TODO: what's 4
        }
    }

    return 0;
}

int STWI_reset_ClockCounter(void)
{
    gSTWIStatus->unk_0 = 5; //TODO: what is 5
    gSTWIStatus->txParams = 0;
    gSTWIStatus->unk_5 = 0;
    REG_SIODATA32 = (1 << 31);
    REG_SIOCNT = 0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    REG_SIOCNT = (SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS) + 0x7F;

    return 0;
}
