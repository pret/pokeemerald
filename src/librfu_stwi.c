#include "librfu.h"

static void STWI_intr_timer(void);
static u16 STWI_init(u8 request);
static s32 STWI_start_Command(void);
static void STWI_set_timer(u8 unk);
static void STWI_stop_timer(void);
static s32 STWI_restart_Command(void);
static s32 STWI_reset_ClockCounter(void);

struct STWIStatus *gSTWIStatus;

void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
    // If we're copying our interrupt into RAM, DMA it to block1 and use
    // block2 for our STWIStatus, otherwise block1 holds the STWIStatus.
    // interrupt usually is a pointer to gIntrTable[1]
    if (copyInterruptToRam == TRUE)
    {
        *interrupt = (IntrFunc)interruptStruct->block1;
        DmaCopy16(3, &IntrSIO32, interruptStruct->block1, sizeof(interruptStruct->block1));
        gSTWIStatus = &interruptStruct->block2;
    }
    else
    {
        *interrupt = IntrSIO32;
        gSTWIStatus = (struct STWIStatus *)interruptStruct->block1;
    }
    gSTWIStatus->rxPacket = &interruptStruct->rxPacketAlloc;
    gSTWIStatus->txPacket = &interruptStruct->txPacketAlloc;
    gSTWIStatus->msMode = AGB_CLK_MASTER;
    gSTWIStatus->state = 0; // master send req
    gSTWIStatus->reqLength = 0;
    gSTWIStatus->reqNext = 0;
    gSTWIStatus->ackLength = 0;
    gSTWIStatus->ackNext = 0;
    gSTWIStatus->ackActiveCommand = 0;
    gSTWIStatus->timerState = 0;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->error = 0;
    gSTWIStatus->recoveryCount = 0;
    gSTWIStatus->sending = 0;
    REG_RCNT = 0x100; // TODO: mystery bit?
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    STWI_init_Callback_M();
    STWI_init_Callback_S();
    IntrEnable(INTR_FLAG_SERIAL);
}

void STWI_init_timer(IntrFunc *interrupt, s32 timerSelect)
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
    *timerH = TIMER_ENABLE | TIMER_1024CLK;
    while (*timerL <= 0x11)
        REG_RCNT = 0x80A2;
    *timerH = 3;
    REG_RCNT = 0x80A0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    gSTWIStatus->state = 0; // master send req
    gSTWIStatus->reqLength = 0;
    gSTWIStatus->reqNext = 0;
    gSTWIStatus->reqActiveCommand = 0;
    gSTWIStatus->ackLength = 0;
    gSTWIStatus->ackNext = 0;
    gSTWIStatus->ackActiveCommand = 0;
    gSTWIStatus->timerState = 0;
    gSTWIStatus->timerActive = 0;
    gSTWIStatus->error = 0;
    gSTWIStatus->msMode = AGB_CLK_MASTER;
    gSTWIStatus->recoveryCount = 0;
    gSTWIStatus->sending = 0;
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
        return gSTWIStatus->error;
    case 1:
        return gSTWIStatus->msMode;
    case 2:
        return gSTWIStatus->state;
    case 3:
        return gSTWIStatus->reqActiveCommand;
    default:
        return 0xFFFF;
    }
}

void STWI_init_Callback_M(void)
{
    STWI_set_Callback_M(NULL);
}

void STWI_init_Callback_S(void)
{
    STWI_set_Callback_S(NULL);
}

// The callback can take 2 or 3 arguments.
void STWI_set_Callback_M(void *callbackM)
{
    gSTWIStatus->callbackM = callbackM;
}

void STWI_set_Callback_S(void (*callbackS)(u16))
{
    gSTWIStatus->callbackS = callbackS;
}

void STWI_set_Callback_ID(void (*func)(void)) // name in SDK, but is actually setting a function pointer
{
    gSTWIStatus->callbackID = func;
}

u16 STWI_poll_CommandEnd(void)
{
    while (gSTWIStatus->sending == 1)
        ;
    return gSTWIStatus->error;
}

void STWI_send_ResetREQ(void)
{
    if (!STWI_init(ID_RESET_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_LinkStatusREQ(void)
{
    if (!STWI_init(ID_LINK_STATUS_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_VersionStatusREQ(void)
{
    if (!STWI_init(ID_VERSION_STATUS_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SystemStatusREQ(void)
{
    if (!STWI_init(ID_SYSTEM_STATUS_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SlotStatusREQ(void)
{
    if (!STWI_init(ID_SLOT_STATUS_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_ConfigStatusREQ(void)
{
    if (!STWI_init(ID_CONFIG_STATUS_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_GameConfigREQ(const u8 *serial_gname, const u8 *uname)
{
    u8 *packetBytes;
    s32 i;

    if (!STWI_init(ID_GAME_CONFIG_REQ))
    {
        gSTWIStatus->reqLength = 6;
        packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
        packetBytes += sizeof(u32);
        *(u16 *)packetBytes = *(u16 *)serial_gname;
        packetBytes += sizeof(u16);
        serial_gname += sizeof(u16);
        for (i = 0; i < 14; ++i)
        {
            *packetBytes = *serial_gname;
            ++packetBytes;
            ++serial_gname;
        }
        for (i = 0; i < 8; ++i)
        {
            *packetBytes = *uname;
            ++packetBytes;
            ++uname;
        }
        STWI_start_Command();
    }
}

void STWI_send_SystemConfigREQ(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer)
{
    if (!STWI_init(ID_SYSTEM_CONFIG_REQ))
    {
        u8 *packetBytes;

        gSTWIStatus->reqLength = 1;
        packetBytes = gSTWIStatus->txPacket->rfuPacket8.data;
        packetBytes += sizeof(u32);
        *packetBytes++ = mcTimer;
        *packetBytes++ = maxMFrame;
        *(u16*)packetBytes = availSlotFlag;
        STWI_start_Command();
    }
}

void STWI_send_SC_StartREQ(void)
{
    if (!STWI_init(ID_SC_START_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_PollingREQ(void)
{
    if (!STWI_init(ID_SC_POLL_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_EndREQ(void)
{
    if (!STWI_init(ID_SC_END_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_StartREQ(void)
{
    if (!STWI_init(ID_SP_START_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_PollingREQ(void)
{
    if (!STWI_init(ID_SP_POLL_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_EndREQ(void)
{
    if (!STWI_init(ID_SP_END_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_StartREQ(u16 unk1)
{
    if (!STWI_init(ID_CP_START_REQ))
    {
        gSTWIStatus->reqLength = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk1;
        STWI_start_Command();
    }
}

void STWI_send_CP_PollingREQ(void)
{
    if (!STWI_init(ID_CP_POLL_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_EndREQ(void)
{
    if (!STWI_init(ID_CP_END_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_DataTxREQ(const void *in, u8 size)
{
    if (!STWI_init(ID_DATA_TX_REQ))
    {
        u8 reqLength = (size / sizeof(u32));
        if (size & (sizeof(u32) - 1))
            reqLength += 1;
        gSTWIStatus->reqLength = reqLength;
        CpuCopy32(in, gSTWIStatus->txPacket->rfuPacket32.data, gSTWIStatus->reqLength * sizeof(u32));
        STWI_start_Command();
    }
}

void STWI_send_DataTxAndChangeREQ(const void *in, u8 size)
{
    if (!STWI_init(ID_DATA_TX_AND_CHANGE_REQ))
    {
        u8 reqLength = (size / sizeof(u32));
        if (size & (sizeof(u32) - 1))
            reqLength += 1;
        gSTWIStatus->reqLength = reqLength;
        CpuCopy32(in, gSTWIStatus->txPacket->rfuPacket32.data, gSTWIStatus->reqLength * sizeof(u32));
        STWI_start_Command();
    }
}

void STWI_send_DataRxREQ(void)
{
    if (!STWI_init(ID_DATA_RX_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_MS_ChangeREQ(void)
{
    if (!STWI_init(ID_MS_CHANGE_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_DataReadyAndChangeREQ(u8 unk)
{
    if (!STWI_init(ID_DATA_READY_AND_CHANGE_REQ))
    {
        if (!unk)
        {
            gSTWIStatus->reqLength = 0;
        }
        else
        {
            u8 *packetBytes;

            gSTWIStatus->reqLength = 1;
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
    if (!STWI_init(ID_DISCONNECTED_AND_CHANGE_REQ))
    {
        u8 *packetBytes;

        gSTWIStatus->reqLength = 1;
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
    if (!STWI_init(ID_RESUME_RETRANSMIT_AND_CHANGE_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_DisconnectREQ(u8 unk)
{
    if (!STWI_init(ID_DISCONNECT_REQ))
    {
        gSTWIStatus->reqLength = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk;
        STWI_start_Command();
    }
}

void STWI_send_TestModeREQ(u8 unk0, u8 unk1)
{
    if (!STWI_init(ID_TEST_MODE_REQ))
    {
        gSTWIStatus->reqLength = 1;
        gSTWIStatus->txPacket->rfuPacket32.data[0] = unk0 | (unk1 << 8);
        STWI_start_Command();
    }
}

void STWI_send_CPR_StartREQ(u16 unk0, u16 unk1, u8 unk2)
{
    u32 *packetData;
    u32 arg1;

    if (!STWI_init(ID_CPR_START_REQ))
    {
        gSTWIStatus->reqLength = 2;
        arg1 = unk1 | (unk0 << 16);
        packetData = gSTWIStatus->txPacket->rfuPacket32.data;
        packetData[0] = arg1;
        packetData[1] = unk2;
        STWI_start_Command();
    }
}

void STWI_send_CPR_PollingREQ(void)
{
    if (!STWI_init(ID_CPR_POLL_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_CPR_EndREQ(void)
{
    if (!STWI_init(ID_CPR_END_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

void STWI_send_StopModeREQ(void)
{
    if (!STWI_init(ID_STOP_MODE_REQ))
    {
        gSTWIStatus->reqLength = 0;
        STWI_start_Command();
    }
}

static void STWI_intr_timer(void)
{
    switch (gSTWIStatus->timerState)
    {
    // TODO: Make an enum for these
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
        if (gSTWIStatus->callbackM != NULL)
            gSTWIStatus->callbackM(ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ, 0);
        break;
    }
}

static void STWI_set_timer(u8 count)
{
    vu16 *timerL = &REG_TMCNT_L(gSTWIStatus->timerSelect);
    vu16 *timerH = &REG_TMCNT_H(gSTWIStatus->timerSelect);
    REG_IME = 0;
    switch (count)
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

static void STWI_stop_timer(void)
{
    gSTWIStatus->timerState = 0;
    REG_TMCNT_L(gSTWIStatus->timerSelect) = 0;
    REG_TMCNT_H(gSTWIStatus->timerSelect) = 0;
}

/*
 * Set up STWI to send REQ. Returns 1 if error (see below).
 */
static u16 STWI_init(u8 request)
{
    if (!REG_IME)
    {
        // Can't start sending if IME is disabled.
        gSTWIStatus->error = ERR_REQ_CMD_IME_DISABLE;
        if (gSTWIStatus->callbackM != NULL)
            gSTWIStatus->callbackM(request, gSTWIStatus->error);
        return TRUE;
    }
    else if (gSTWIStatus->sending == 1)
    {
        // Already sending something. Cancel and error.
        gSTWIStatus->error = ERR_REQ_CMD_SENDING;
        gSTWIStatus->sending = 0;
        if (gSTWIStatus->callbackM != NULL)
            gSTWIStatus->callbackM(request, gSTWIStatus->error);
        return TRUE;
    }
    else if (gSTWIStatus->msMode == AGB_CLK_SLAVE)
    {
        // Can't send if clock slave
        gSTWIStatus->error = ERR_REQ_CMD_CLOCK_SLAVE;
        if (gSTWIStatus->callbackM != NULL)
            gSTWIStatus->callbackM(request, gSTWIStatus->error, gSTWIStatus);
        return TRUE;
    }
    else
    {
        // Good to go, start sending
        gSTWIStatus->sending = 1;
        gSTWIStatus->reqActiveCommand = request;
        gSTWIStatus->state = 0; // master send req
        gSTWIStatus->reqLength = 0;
        gSTWIStatus->reqNext = 0;
        gSTWIStatus->ackLength = 0;
        gSTWIStatus->ackNext = 0;
        gSTWIStatus->ackActiveCommand = 0;
        gSTWIStatus->timerState = 0;
        gSTWIStatus->timerActive = 0;
        gSTWIStatus->error = 0;
        gSTWIStatus->recoveryCount = 0;
        REG_RCNT = 0x100;
        REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
        return FALSE;
    }
}

static s32 STWI_start_Command(void)
{
    u16 imeTemp;

    // equivalent to gSTWIStatus->txPacket->rfuPacket32.command,
    // but the cast here is required to avoid register issue
    *(u32 *)gSTWIStatus->txPacket->rfuPacket8.data = 0x99660000 | (gSTWIStatus->reqLength << 8) | gSTWIStatus->reqActiveCommand;
    REG_SIODATA32 = gSTWIStatus->txPacket->rfuPacket32.command;
    gSTWIStatus->state = 0; // master send req
    gSTWIStatus->reqNext = 1;
    imeTemp = REG_IME;
    REG_IME = 0;
    REG_IE |= (INTR_FLAG_TIMER0 << gSTWIStatus->timerSelect);
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = imeTemp;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_MULTI_BUSY | SIO_115200_BPS;
    return 0;
}

static s32 STWI_restart_Command(void)
{
    if (gSTWIStatus->recoveryCount < 2)
    {
        ++gSTWIStatus->recoveryCount;
        STWI_start_Command();
    }
    else
    {
        if (gSTWIStatus->reqActiveCommand == ID_MS_CHANGE_REQ || gSTWIStatus->reqActiveCommand == ID_DATA_TX_AND_CHANGE_REQ || gSTWIStatus->reqActiveCommand == ID_UNK35_REQ || gSTWIStatus->reqActiveCommand == ID_RESUME_RETRANSMIT_AND_CHANGE_REQ)
        {
            gSTWIStatus->error = ERR_REQ_CMD_CLOCK_DRIFT;
            gSTWIStatus->sending = 0;
            if (gSTWIStatus->callbackM != NULL)
                gSTWIStatus->callbackM(gSTWIStatus->reqActiveCommand, gSTWIStatus->error);
        }
        else
        {
            gSTWIStatus->error = ERR_REQ_CMD_CLOCK_DRIFT;
            gSTWIStatus->sending = 0;
            if (gSTWIStatus->callbackM != NULL)
                gSTWIStatus->callbackM(gSTWIStatus->reqActiveCommand, gSTWIStatus->error);
            gSTWIStatus->state = 4; // error
        }
    }
    return 0;
}

static s32 STWI_reset_ClockCounter(void)
{
    gSTWIStatus->state = 5; // slave receive req init
    gSTWIStatus->reqLength = 0;
    gSTWIStatus->reqNext = 0;
    REG_SIODATA32 = (1 << 31);
    REG_SIOCNT = 0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    REG_SIOCNT = (SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS) + 0x7F;
    return 0;
}
