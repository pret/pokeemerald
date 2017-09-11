#include "global.h"
#include "main.h"

enum
{
    RFU_RESET = 0x10,
    RFU_LINK_STATUS,
    RFU_VERSION_STATUS,
    RFU_SYSTEM_STATUS,
    RFU_SLOT_STATUS,
    RFU_CONFIG_STATUS,
    RFU_GAME_CONFIG,
    RFU_SYSTEM_CONFIG,
    RFU_UNK18,
    RFU_SC_START,
    RFU_SC_POLLING,
    RFU_SC_END,
    RFU_SP_START,
    RFU_SP_POLLING,
    RFU_SP_END,
    RFU_CP_START,
    RFU_CP_POLLING,
    RFU_CP_END,
    RFU_UNK22,
    RFU_UNK23,
    RFU_DATA_TX,
    RFU_DATA_TX_AND_CHANGE,
    RFU_DATA_RX,
    RFU_MS_CHANGE,
    RFU_DATA_READY_AND_CHANGE,
    RFU_DISCONNECTED_AND_CHANGE,
    RFU_UNK2A,
    RFU_UNK2B,
    RFU_UNK2C,
    RFU_UNK2D,
    RFU_UNK2E,
    RFU_UNK2F,
    RFU_DISCONNECT,
    RFU_TEST_MODE,
    RFU_UNK32,
    RFU_UNK33,
    RFU_UNK34,
    RFU_UNK35,
    RFU_UNK36,
    RFU_RESUME_RETRANSMIT_AND_CHANGE
};

struct RfuPacket
{
    u32 unk_0;
    u32 data[0x1C];
};

struct RfuStruct
{
    vs32 unk_0;
    u8 txParams;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 timerSelect;
    u8 unk_b;
    u32 unk_c;
    vu8 unk_10;
    u8 unk_11;
    vu16 unk_12;
    vu8 msMode;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    void *callbackM;
    void *callbackS;
    u32 callbackID;
    struct RfuPacket *txPacket;
    struct RfuPacket *rxPacket;
    vu8 unk_2c;
    u8 padding[3];
};

struct RfuIntrStruct
{
    u8 rxPacketAlloc[0x74];
    u8 txPacketAlloc[0x74];
    u8 block1[0x960];
    u8 block2[0x30];
};

extern IntrFunc IntrSIO32(void);
extern struct RfuStruct *gRfuState;
void STWI_init_Callback_M(void);
void STWI_init_Callback_S(void);
void STWI_set_Callback_M(void * callback);
void STWI_set_Callback_S(void * callback);
u16 STWI_init(u8 request);
int STWI_start_Command(void);
extern void STWI_intr_timer(void);

void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
    // If we're copying our interrupt into RAM, DMA it to block1 and use
    // block2 for our RfuStruct, otherwise block1 holds the RfuStruct.
    // interrupt usually is a pointer to gIntrTable[1]
    if (copyInterruptToRam == TRUE)
    {
        *interrupt = (IntrFunc)interruptStruct->block1;
        DmaCopy16(3, &IntrSIO32, interruptStruct->block1, 0x960);
        gRfuState = (struct RfuStruct*)interruptStruct->block2;
    }
    else
    {
        *interrupt = (IntrFunc)IntrSIO32;
        gRfuState = (struct RfuStruct*)interruptStruct->block1;
    }

    gRfuState->rxPacket = (struct RfuPacket*)interruptStruct->rxPacketAlloc;
    gRfuState->txPacket = (struct RfuPacket*)interruptStruct->txPacketAlloc;
    gRfuState->msMode = 1;
    gRfuState->unk_0 = 0;
    gRfuState->txParams = 0;
    gRfuState->unk_5 = 0;
    gRfuState->unk_7 = 0;
    gRfuState->unk_8 = 0;
    gRfuState->unk_9 = 0;
    gRfuState->unk_c = 0;
    gRfuState->unk_10 = 0;
    gRfuState->unk_12 = 0;
    gRfuState->unk_15 = 0;
    gRfuState->unk_2c = 0;

    REG_RCNT = 0x100; //TODO: mystery bit?
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;
    STWI_init_Callback_M();
    STWI_init_Callback_S();

    IntrEnable(INTR_FLAG_SERIAL);
}

void STWI_init_timer(IntrFunc *interrupt, int timerSelect)
{
    *interrupt = STWI_intr_timer;
    gRfuState->timerSelect = timerSelect;

    IntrEnable(INTR_FLAG_TIMER0 << gRfuState->timerSelect);
}

void AgbRFU_SoftReset(void)
{
    vu16 *timerL;
    vu16 *timerH;

    REG_RCNT = 0x8000;
    REG_RCNT = 0x80A0; // all these bits are undocumented
    timerL = &REG_TMCNT_L(gRfuState->timerSelect);
    timerH = &REG_TMCNT_H(gRfuState->timerSelect);
    *timerH = 0;
    *timerL = 0;
    *timerH = 0x83;
    while (*timerL <= 0x11)
        REG_RCNT = 0x80A2;
    *timerH = 3;
    REG_RCNT = 0x80A0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE | SIO_115200_BPS;

    gRfuState->unk_0 = 0;
    gRfuState->txParams = 0;
    gRfuState->unk_5 = 0;
    gRfuState->unk_6 = 0;
    gRfuState->unk_7 = 0;
    gRfuState->unk_8 = 0;
    gRfuState->unk_9 = 0;
    gRfuState->unk_c = 0;
    gRfuState->unk_10 = 0;
    gRfuState->unk_12 = 0;
    gRfuState->msMode = 1;
    gRfuState->unk_15 = 0;
    gRfuState->unk_2c = 0;
}

void STWI_set_MS_mode(u8 mode)
{
    gRfuState->msMode = mode;
}

u16 STWI_read_status(u8 index)
{
    switch (index)
    {
    case 0:
        return gRfuState->unk_12;
    case 1:
        return gRfuState->msMode;
    case 2:
        return gRfuState->unk_0;
    case 3:
        return gRfuState->unk_6;
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
    gRfuState->callbackM = callback;
}

void STWI_set_Callback_S(void *callback)
{
    gRfuState->callbackS = callback;
}

void STWI_set_Callback_ID(u32 id)
{
    gRfuState->callbackID = id;
}

u16 STWI_poll_CommandEnd(void)
{
    while (gRfuState->unk_2c == TRUE)
        ;
    return gRfuState->unk_12;
}

void STWI_send_ResetREQ(void)
{
    if (!STWI_init(RFU_RESET))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_LinkStatusREQ(void)
{
    if (!STWI_init(RFU_LINK_STATUS))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_VersionStatusREQ(void)
{
    if (!STWI_init(RFU_VERSION_STATUS))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SystemStatusREQ(void)
{
    if (!STWI_init(RFU_SYSTEM_STATUS))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SlotStatusREQ(void)
{
    if (!STWI_init(RFU_SLOT_STATUS))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_ConfigStatusREQ(void)
{
    if (!STWI_init(RFU_CONFIG_STATUS))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_GameConfigREQ(u8 * unk1, u8 *data)
{
    u8 *v5;
    int i;

    if (!STWI_init(RFU_GAME_CONFIG))
    {
        gRfuState->txParams = 6;

        //TODO: kinda gross but it was probably written weird
        v5 = (u8*)gRfuState->txPacket;
        v5 += sizeof(u32);
        *(u16*)v5 = *(u16*)unk1;

        v5 += sizeof(u16);
        unk1 += sizeof(u16);

        for (i = 0; i < 14; i++)
        {
            *v5 = *unk1;
            v5++;
            unk1++;
        }

        for (i = 0; i < 8; i++)
        {
            *v5 = *data;
            v5++;
            data++;
        }

        STWI_start_Command();
    }
}

void STWI_send_SystemConfigREQ(u16 unk1, u8 unk2, u8 unk3)
{
   u8 *v5;

    if (!STWI_init(RFU_SYSTEM_CONFIG))
    {
        gRfuState->txParams = 1;

        //TODO: kinda weird but I think it was written weird
        v5 = (u8*)gRfuState->txPacket;
        v5 += sizeof(u32);

        *v5++ = unk3;
        *v5++ = unk2;
        *(u16*)v5 = unk1;
        STWI_start_Command();
    }
}

void STWI_send_SC_StartREQ(void)
{
    if (!STWI_init(RFU_SC_START))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_PollingREQ(void)
{
    if (!STWI_init(RFU_SC_POLLING))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SC_EndREQ(void)
{
    if (!STWI_init(RFU_SC_END))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_StartREQ(void)
{
    if (!STWI_init(RFU_SP_START))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_PollingREQ(void)
{
    if (!STWI_init(RFU_SP_POLLING))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_SP_EndREQ(void)
{
    if (!STWI_init(RFU_SP_END))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_StartREQ(u16 unk1)
{
    if (!STWI_init(RFU_CP_START))
    {
        gRfuState->txParams = 1;
        gRfuState->txPacket->data[0] = unk1;
        STWI_start_Command();
    }
}

void STWI_send_CP_PollingREQ(void)
{
    if (!STWI_init(RFU_CP_POLLING))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_CP_EndREQ(void)
{
    if (!STWI_init(RFU_CP_END))
    {
        gRfuState->txParams = 0;
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
            
        gRfuState->txParams = txParams;
        CpuCopy32(in, gRfuState->txPacket->data, gRfuState->txParams * sizeof(u32));
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

        gRfuState->txParams = txParams;
        CpuCopy32(in, gRfuState->txPacket->data, gRfuState->txParams * sizeof(u32));
        STWI_start_Command();
    }
}

void STWI_send_DataRxREQ()
{
    if (!STWI_init(RFU_DATA_RX))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_MS_ChangeREQ()
{
    if (!STWI_init(RFU_MS_CHANGE))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_DataReadyAndChangeREQ(u8 unk)
{
    if (!STWI_init(RFU_DATA_READY_AND_CHANGE))
    {
        if (!unk)
        {
            gRfuState->txParams = 0;
        }
        else
        {
            u8 *packetBytes;

            gRfuState->txParams = 1;

            packetBytes = (u8*)gRfuState->txPacket;
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

        gRfuState->txParams = 1;

        packetBytes = (u8*)gRfuState->txPacket;
        packetBytes += sizeof(u32);

        *packetBytes++ = unk0;
        *packetBytes++ = unk1;
        *packetBytes++ = 0;
        *packetBytes = 0;

        STWI_start_Command();
    }
}

void STWI_send_ResumeRetransmitAndChangeREQ()
{
    if (!STWI_init(RFU_RESUME_RETRANSMIT_AND_CHANGE))
    {
        gRfuState->txParams = 0;
        STWI_start_Command();
    }
}

void STWI_send_DisconnectREQ(u8 unk)
{
    if (!STWI_init(RFU_DISCONNECT))
    {
        gRfuState->txParams = 1;
        gRfuState->txPacket->data[0] = unk;

        STWI_start_Command();
    }
}

void STWI_send_TestModeREQ(u8 unk0, u8 unk1)
{
    if (!STWI_init(RFU_TEST_MODE))
    {
        gRfuState->txParams = 1;
        gRfuState->txPacket->data[0] = unk0 | (unk1 << 8);

        STWI_start_Command();
    }
}
