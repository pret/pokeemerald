#include <limits.h>
#include "librfu.h"

// If expanding the length of the player name and wireless link functionality is
// desired, ensure that the name string is limited in size when it's copied from the
// saveblock to any Rfu-related fields (e.g. in SetHostRfuUsername).
// If wireless link functionality is not desired ignore or delete this warning.
#if RFU_USER_NAME_LENGTH < (PLAYER_NAME_LENGTH + 1)
#warning "The Wireless Adapter hardware expects a username of no more than 8 bytes."
#endif

struct LLSFStruct
{
    u8 frameSize;
    u8 recvFirstShift;
    u8 connSlotFlagShift;
    u8 slotStateShift;
    u8 ackShift;
    u8 phaseShift;
    u8 nShift;
    u8 recvFirstMask;
    u8 connSlotFlagMask;
    u8 slotStateMask;
    u8 ackMask;
    u8 phaseMask;
    u8 nMask;
    u16 framesMask;
};

struct RfuLocalStruct
{
    u8 recvFirst;
    u8 connSlotFlag;
    u8 slotState;
    u8 ack;
    u8 phase;
    u8 n;
    u16 frame;
};

static void rfu_CB_defaultCallback(u8 reqCommand, u16 reqResult);
static void rfu_CB_reset(u8 reqCommand, u16 reqResult);
static void rfu_CB_configGameData(u8 reqCommand, u16 reqResult);
static void rfu_CB_stopMode(u8 reqCommand, u16 reqResult);
static void rfu_CB_startSearchChild(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollAndEndSearchChild(u8 reqCommand, u16 reqResult);
static void rfu_CB_startSearchParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollSearchParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollConnectParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollConnectParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_disconnect(u8 reqCommand, u16 reqResult);
static void rfu_CB_CHILD_pollConnectRecovery(u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData(UNUSED u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData2(UNUSED u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData3(u8 reqCommand, u16 reqResult);
static void rfu_CB_recvData(u8 reqCommand, u16 reqResult);
static void rfu_enableREQCallback(bool8 enable);
static void rfu_STC_clearAPIVariables(void);
static void rfu_STC_readChildList(void);
static void rfu_STC_readParentCandidateList(void);
static void rfu_STC_REQ_callback(u8 reqCommand, u16 reqResult);
static void rfu_STC_removeLinkData(u8, u8);
static void rfu_STC_fastCopy(const u8 **, u8 **, s32);
static void rfu_STC_clearLinkStatus(u8);
static void rfu_NI_checkCommFailCounter(void);
static u16 rfu_STC_setSendData_org(u8, u8, u8, const void *, u32);
static void rfu_constructSendLLFrame(void);
static u16 rfu_STC_NI_constructLLSF(u8, u8 **, struct NIComm *);
static u16 rfu_STC_UNI_constructLLSF(u8, u8 **);
static void rfu_STC_PARENT_analyzeRecvPacket(void);
static void rfu_STC_CHILD_analyzeRecvPacket(void);
static u16 rfu_STC_analyzeLLSF(u8, const u8 *, u16);
static void rfu_STC_UNI_receive(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Receiver(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Sender(u8, u8, const struct RfuLocalStruct *, UNUSED const u8 *);
static void rfu_STC_NI_initSlot_asRecvDataEntity(u8, struct NIComm *);
static void rfu_STC_NI_initSlot_asRecvControllData(u8, struct NIComm *);

struct RfuSlotStatusUNI *gRfuSlotStatusUNI[RFU_CHILD_MAX];
struct RfuSlotStatusNI *gRfuSlotStatusNI[RFU_CHILD_MAX];
struct RfuLinkStatus *gRfuLinkStatus;
struct RfuStatic *gRfuStatic;
struct RfuFixed *gRfuFixed;

static const struct LLSFStruct llsf_struct[2] = {
    [MODE_CHILD] = {
        .frameSize = 2,
        .recvFirstShift = 14,
        .connSlotFlagShift = 0,
        .slotStateShift = 10,
        .ackShift = 9,
        .phaseShift = 5,
        .nShift = 7,
        .recvFirstMask = 2,
        .connSlotFlagMask = 0,
        .slotStateMask = 15,
        .ackMask = 1,
        .phaseMask = 3,
        .nMask = 3,
        .framesMask = 0x1f
    },
    [MODE_PARENT] = {
        .frameSize = 3,
        .recvFirstShift = 22,
        .connSlotFlagShift = 18,
        .slotStateShift = 14,
        .ackShift = 13,
        .phaseShift = 9,
        .nShift = 11,
        .recvFirstMask = 3,
        .connSlotFlagMask = 15,
        .slotStateMask = 15,
        .ackMask = 1,
        .phaseMask = 3,
        .nMask = 3,
        .framesMask = 0x7f
    }
};

#define xstr(s) str(s)
#define str(s) #s
static const char version_string[] = "RFU_V" xstr(LIBRFU_VERSION);

static const char str_checkMbootLL[] = "RFU-MBOOT";

#define COPY(src, dst, iterator, size) do {         \
    const u16 *_src = (const u16 *)(src);           \
    u16 *_dst = (u16 *)(dst);                       \
    (iterator) = (size);                            \
    while ((iterator)-- != 0)                       \
        *_dst++ = *_src++;                          \
} while (0)

u16 rfu_initializeAPI(u32 *APIBuffer, u16 buffByteSize, IntrFunc *sioIntrTable_p, bool8 copyInterruptToRam)
{
    u16 i;
    u16 *dst;
    const u16 *src;
    u16 buffByteSizeMax;

    // is in EWRAM?
    if (((uintptr_t)APIBuffer & 0xF000000) == 0x2000000 && copyInterruptToRam)
        return ERR_RFU_API_BUFF_ADR;
    // is not 4-byte aligned?
    if ((u32)APIBuffer & 3)
        return ERR_RFU_API_BUFF_ADR;
    if (copyInterruptToRam)
    {
        // An assert/debug print may have existed before, ie
        // printf("%s %u < %u", "somefile.c:12345", buffByteSize, num)
        // to push this into buffByteSizeMax?
        buffByteSizeMax = RFU_API_BUFF_SIZE_RAM;
        if (buffByteSize < buffByteSizeMax)
            return ERR_RFU_API_BUFF_SIZE;
    }
    if (!copyInterruptToRam)
    {
        buffByteSizeMax = RFU_API_BUFF_SIZE_ROM; // same issue as above
        if (buffByteSize < buffByteSizeMax)
            return ERR_RFU_API_BUFF_SIZE;
    }
    gRfuLinkStatus = (void *)APIBuffer + 0;
    gRfuStatic = (void *)APIBuffer + 0xb4; // + sizeof(*gRfuLinkStatus)
    gRfuFixed = (void *)APIBuffer + 0xdc; // + sizeof(*gRfuStatic)
    gRfuSlotStatusNI[0] = (void *)APIBuffer + 0x1bc; // + sizeof(*gRfuFixed)
    gRfuSlotStatusUNI[0] = (void *)APIBuffer + 0x37c; // + sizeof(*gRfuSlotStatusNI[0]) * RFU_CHILD_MAX
    for (i = 1; i < RFU_CHILD_MAX; ++i)
    {
        gRfuSlotStatusNI[i] = &gRfuSlotStatusNI[i - 1][1];
        gRfuSlotStatusUNI[i] = &gRfuSlotStatusUNI[i - 1][1];
    }
    // remaining space in API buffer is used for `struct RfuIntrStruct`.
    gRfuFixed->STWIBuffer = (struct RfuIntrStruct *)&gRfuSlotStatusUNI[3][1];
    STWI_init_all((struct RfuIntrStruct *)&gRfuSlotStatusUNI[3][1], sioIntrTable_p, copyInterruptToRam);
    rfu_STC_clearAPIVariables();
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
        gRfuSlotStatusNI[i]->recvBuffer = NULL;
        gRfuSlotStatusNI[i]->recvBufferSize = 0;
        gRfuSlotStatusUNI[i]->recvBuffer = NULL;
        gRfuSlotStatusUNI[i]->recvBufferSize = 0;
    }
    // rfu_REQ_changeMasterSlave is the function next to rfu_STC_fastCopy
#if LIBRFU_VERSION < 1026
    src = (const u16 *)((uintptr_t)&rfu_STC_fastCopy & ~1);
    dst = gRfuFixed->fastCopyBuffer;
    buffByteSizeMax = ((void *)rfu_REQ_changeMasterSlave - (void *)rfu_STC_fastCopy) / sizeof(u16);
    while (buffByteSizeMax-- != 0)
        *dst++ = *src++;
#else
    COPY(
        (uintptr_t)&rfu_STC_fastCopy & ~1,
        gRfuFixed->fastCopyBuffer,
        buffByteSizeMax,
        0x60 / sizeof(u16)
        );
#endif
    gRfuFixed->fastCopyPtr = (void *)gRfuFixed->fastCopyBuffer + 1;
    return 0;
}

static void rfu_STC_clearAPIVariables(void)
{
    u16 IMEBackup = REG_IME;
    u8 i, flags;

    REG_IME = 0;
    flags = gRfuStatic->flags;
    CpuFill16(0, gRfuStatic, sizeof(struct RfuStatic));
    gRfuStatic->flags = flags & 8;
    CpuFill16(0, gRfuLinkStatus, sizeof(struct RfuLinkStatus));
    gRfuLinkStatus->watchInterval = 4;
    gRfuStatic->nowWatchInterval = 0;
    gRfuLinkStatus->parentChild = MODE_NEUTRAL;
    rfu_clearAllSlot();
    gRfuStatic->SCStartFlag = 0;
    for (i = 0; i < RFU_CHILD_MAX; ++i)
        gRfuStatic->cidBak[i] = 0;
    REG_IME = IMEBackup;
}

void rfu_REQ_PARENT_resumeRetransmitAndChange(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_ResumeRetransmitAndChangeREQ();
}

u16 rfu_UNI_PARENT_getDRAC_ACK(u8 *ackFlag)
{
    u8 *buf;

    *ackFlag = 0;
    if (gRfuLinkStatus->parentChild != MODE_PARENT)
        return ERR_MODE_NOT_PARENT;
    buf = rfu_getSTWIRecvBuffer();
    switch (*buf)
    {
    case 40:
    case 54:
        if (buf[1] == 0)
            *ackFlag = gRfuLinkStatus->connSlotFlag;
        else
            *ackFlag = buf[4];
        return 0;
    default:
        return ERR_REQ_CMD_ID;
    }
}

void rfu_setTimerInterrupt(u8 timerNo, IntrFunc *timerIntrTable_p)
{
    STWI_init_timer(timerIntrTable_p, timerNo);
}

u8 *rfu_getSTWIRecvBuffer(void)
{
    return (u8 *)gRfuFixed->STWIBuffer;
}

void rfu_setMSCCallback(void (*callback)(u16 reqCommandId))
{
    STWI_set_Callback_S(callback);
}

void rfu_setREQCallback(void (*callback)(u16 reqCommandId, u16 reqResult))
{
    gRfuFixed->reqCallback = callback;
    rfu_enableREQCallback(callback != NULL);
}

static void rfu_enableREQCallback(bool8 enable)
{
    if (enable)
        gRfuStatic->flags |= 8;
    else
        gRfuStatic->flags &= 0xF7;
}

static void rfu_STC_REQ_callback(u8 reqCommand, u16 reqResult)
{
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    gRfuStatic->reqResult = reqResult;
    if (gRfuStatic->flags & 8)
        gRfuFixed->reqCallback(reqCommand, reqResult);
}

static void rfu_CB_defaultCallback(u8 reqCommand, u16 reqResult)
{
    s32 bmSlotFlags;
    u8 i;

    if (reqCommand == ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ)
    {
        if (gRfuStatic->flags & 8)
            gRfuFixed->reqCallback(reqCommand, reqResult);
        bmSlotFlags = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
        for (i = 0; i < RFU_CHILD_MAX; ++i)
            if ((bmSlotFlags >> i) & 1)
                rfu_STC_removeLinkData(i, 1);
        gRfuLinkStatus->parentChild = MODE_NEUTRAL;
    }
}

u16 rfu_waitREQComplete(void)
{
    STWI_poll_CommandEnd();
    return gRfuStatic->reqResult;
}

void rfu_REQ_RFUStatus(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SystemStatusREQ();
}

u16 rfu_getRFUStatus(u8 *rfuState)
{
    if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0] != 0x93)
        return ERR_REQ_CMD_ID;
    if (STWI_poll_CommandEnd() == 0)
        *rfuState = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7];
    else
        *rfuState = 0xFF;
    return 0;
}

/*
 * RFU Multiboot images are loaded into IWRAM
 * struct RfuMbootLL
 * {
 *   struct RfuLinkStatus status;
 *   u8 filler_B4[0x3C];
 *   char name[10];
 *   u16 checksum;
 * }
 * Returns 1 if the packet to inherit is malformed.
 */
u16 rfu_MBOOT_CHILD_inheritanceLinkStatus(void)
{
    const char *s1 = str_checkMbootLL;
    char *s2 = (char *)0x30000F0;
    u16 checksum;
    u16 *mb_buff_iwram_p;
    u8 i;

    // if (strcmp(s1, s2) != 0) return 1;
    while (*s1 != '\0')
        if (*s1++ != *s2++)
            return 1;
    mb_buff_iwram_p = (u16 *)0x3000000;

    // The size of struct RfuLinkStatus is 180
    checksum = 0;
    for (i = 0; i < 180/2; ++i)
        checksum += *mb_buff_iwram_p++;
    if (checksum != *(u16 *)0x30000FA)
        return 1;
    CpuCopy16((u16 *)0x3000000, gRfuLinkStatus, sizeof(struct RfuLinkStatus));
    gRfuStatic->flags |= 0x80; // mboot
    return 0;
}

void rfu_REQ_stopMode(void)
{
    vu32 *timerReg;

    if (REG_IME == 0)
    {
        rfu_STC_REQ_callback(ID_STOP_MODE_REQ, 6);
        gSTWIStatus->error = ERR_REQ_CMD_IME_DISABLE;
    }
    else
    {
        AgbRFU_SoftReset();
        rfu_STC_clearAPIVariables();
        if (AgbRFU_checkID(8) == RFU_ID)
        {
            timerReg = &REG_TMCNT(gSTWIStatus->timerSelect);
            *timerReg = 0;
            *timerReg = (TIMER_ENABLE | TIMER_1024CLK) << 16;
            while (*timerReg << 16 < 262 << 16)
                ;
            *timerReg = 0;
            STWI_set_Callback_M(rfu_CB_stopMode);
            STWI_send_StopModeREQ();
        }
        else
        {
            REG_SIOCNT = SIO_MULTI_MODE;
            rfu_STC_REQ_callback(ID_STOP_MODE_REQ, 0);
        }
    }
}

static void rfu_CB_stopMode(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        REG_SIOCNT = SIO_MULTI_MODE;
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

u32 rfu_REQBN_softReset_and_checkID(void)
{
    u32 id;

    if (REG_IME == 0)
        return ERR_ID_CHECK_IME_DISABLE;
    AgbRFU_SoftReset();
    rfu_STC_clearAPIVariables();
    if ((id = AgbRFU_checkID(30)) == 0)
        REG_SIOCNT = SIO_MULTI_MODE;
    return id;
}

void rfu_REQ_reset(void)
{
    STWI_set_Callback_M(rfu_CB_reset);
    STWI_send_ResetREQ();
}

static void rfu_CB_reset(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_clearAPIVariables();
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

void rfu_REQ_configSystem(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SystemConfigREQ((availSlotFlag & AVAIL_SLOT1) | 0x3C, maxMFrame, mcTimer);
    if (mcTimer == 0)
    {
        gRfuStatic->linkEmergencyLimit = 1;
    }
    else
    {
        u16 IMEBackup = REG_IME;

        REG_IME = 0;
        gRfuStatic->linkEmergencyLimit = Div(600, mcTimer);
        REG_IME = IMEBackup;
    }
}

void rfu_REQ_configGameData(u8 mbootFlag, u16 serialNo, const u8 *gname, const u8 *uname)
{
    u8 packet[16];
    u8 i;
    u8 check_sum;
    const u8 *gnameBackup = gname;
    const u8 *unameBackup;

    packet[0] = serialNo;
    packet[1] = serialNo >> 8;
    if (mbootFlag != 0)
        packet[1] = (serialNo >> 8) | 0x80;
    for (i = 2; i < 15; ++i)
        packet[i] = *gname++;
    check_sum = 0;
    unameBackup = uname;
    for (i = 0; i < 8; ++i)
    {
        check_sum += *unameBackup++;
        check_sum += *gnameBackup++;
    }
    packet[15] = ~check_sum;
    if (mbootFlag != 0)
        packet[14] = 0;
    STWI_set_Callback_M(rfu_CB_configGameData);
    STWI_send_GameConfigREQ(packet, uname);
}

static void rfu_CB_configGameData(u8 reqCommand, u16 reqResult)
{
    s32 serialNo;
    u8 *gname_uname_p;
    u8 i;
    u8 *packet_p;

    if (reqResult == 0)
    {
        packet_p = gSTWIStatus->txPacket->rfuPacket8.data;
        serialNo = gRfuLinkStatus->my.serialNo = packet_p[4];
        gRfuLinkStatus->my.serialNo = (packet_p[5] << 8) | serialNo;
        gname_uname_p = &packet_p[6];
        if (gRfuLinkStatus->my.serialNo & 0x8000)
        {
            gRfuLinkStatus->my.serialNo = gRfuLinkStatus->my.serialNo ^ 0x8000;
            gRfuLinkStatus->my.mbootFlag = 1;
        }
        else
        {
            gRfuLinkStatus->my.mbootFlag = 0;
        }
        for (i = 0; i < RFU_GAME_NAME_LENGTH; ++i)
            gRfuLinkStatus->my.gname[i] = *gname_uname_p++;
        ++gname_uname_p;
        for (i = 0; i < PLAYER_NAME_LENGTH + 1; ++i)
            gRfuLinkStatus->my.uname[i] = *gname_uname_p++;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

void rfu_REQ_startSearchChild(void)
{
    u16 result;
#if LIBRFU_VERSION >= 1026
    u16 i;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        gRfuStatic->lsFixedCount[i] = 0;
    }
#endif

    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_SystemStatusREQ();
    result = STWI_poll_CommandEnd();
    if (result == 0)
    {
        if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
            rfu_STC_clearLinkStatus(MODE_PARENT);
    }
    else
    {
        rfu_STC_REQ_callback(ID_SC_START_REQ, result);
    }
    STWI_set_Callback_M(rfu_CB_startSearchChild);
    STWI_send_SC_StartREQ();
}

static void rfu_CB_startSearchChild(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        gRfuStatic->SCStartFlag = 1;
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

static void rfu_STC_clearLinkStatus(u8 parentChild)
{
    u8 i;

    rfu_clearAllSlot();
    if (parentChild != MODE_CHILD)
    {
        CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
        gRfuLinkStatus->findParentCount = 0;
    }
    for (i = 0; i < RFU_CHILD_MAX; ++i)
        gRfuLinkStatus->strength[i] = 0;
    gRfuLinkStatus->connCount = 0;
    gRfuLinkStatus->connSlotFlag = 0;
    gRfuLinkStatus->linkLossSlotFlag = 0;
    gRfuLinkStatus->getNameFlag = 0;
}

void rfu_REQ_pollSearchChild(void)
{
    STWI_set_Callback_M(rfu_CB_pollAndEndSearchChild);
    STWI_send_SC_PollingREQ();
}

void rfu_REQ_endSearchChild(void)
{
    STWI_set_Callback_M(rfu_CB_pollAndEndSearchChild);
    STWI_send_SC_EndREQ();
}

static void rfu_CB_pollAndEndSearchChild(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_readChildList();
    if (reqCommand == ID_SC_POLL_REQ)
    {
        if (gRfuLinkStatus->my.id == 0)
        {
            STWI_set_Callback_M(rfu_CB_defaultCallback);
            STWI_send_SystemStatusREQ();
            if (STWI_poll_CommandEnd() == 0)
                gRfuLinkStatus->my.id = *(u16 *)&gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        }
    }
    else if (reqCommand == ID_SC_END_REQ)
    {
        if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
            gRfuLinkStatus->my.id = 0;
        gRfuStatic->SCStartFlag = 0;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

static void rfu_STC_readChildList(void)
{
    u32 stwiParam;
    u8 numSlots = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[1];
    u8 *data_p;
    u8 i;
    u8 bm_slot_id;
#if LIBRFU_VERSION < 1026
    u8 true_slots[RFU_CHILD_MAX];
#endif

#if LIBRFU_VERSION < 1026
    if (numSlots != 0)
    {
        stwiParam = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_LinkStatusREQ();
        if (STWI_poll_CommandEnd() == 0)
        {
            data_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
            for (i = 0; i < RFU_CHILD_MAX; ++i)
                true_slots[i] = *data_p++;
        }
        gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] = stwiParam;
    }
#endif
    for (data_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
         numSlots != 0;
         data_p += 4)
    {
        bm_slot_id = data_p[2];
        if (bm_slot_id < RFU_CHILD_MAX && !((gRfuLinkStatus->connSlotFlag >> bm_slot_id) & 1) && !((gRfuLinkStatus->linkLossSlotFlag >> bm_slot_id) & 1))
        {
        #if LIBRFU_VERSION < 1026
            if (true_slots[bm_slot_id] != 0)
                ++gRfuStatic->lsFixedCount[bm_slot_id];
            if (gRfuStatic->lsFixedCount[bm_slot_id] >= 4)
            {
                gRfuStatic->lsFixedCount[bm_slot_id] = 0;
                gRfuLinkStatus->strength[bm_slot_id] = 255;
                gRfuLinkStatus->connSlotFlag |= 1 << bm_slot_id;
                ++gRfuLinkStatus->connCount;
                gRfuLinkStatus->partner[bm_slot_id].id = *(u16 *)data_p;
                gRfuLinkStatus->partner[bm_slot_id].slot = bm_slot_id;
                gRfuLinkStatus->parentChild = MODE_PARENT;
                gRfuStatic->flags &= 0x7F;
                gRfuStatic->cidBak[bm_slot_id] = gRfuLinkStatus->partner[bm_slot_id].id;
            }
        #else
            gRfuStatic->lsFixedCount[bm_slot_id] = 0xF0;
            gRfuLinkStatus->strength[bm_slot_id] = 16;
            gRfuLinkStatus->connSlotFlag |= 1 << bm_slot_id;
            ++gRfuLinkStatus->connCount;
            gRfuLinkStatus->partner[bm_slot_id].id = *(u16 *)data_p;
            gRfuLinkStatus->partner[bm_slot_id].slot = bm_slot_id;
            gRfuLinkStatus->parentChild = MODE_PARENT;
            gRfuStatic->flags &= 0x7F;
            gRfuStatic->cidBak[bm_slot_id] = gRfuLinkStatus->partner[bm_slot_id].id;
        #endif
        }
        --numSlots;
    }
}

void rfu_REQ_startSearchParent(void)
{
    STWI_set_Callback_M(rfu_CB_startSearchParent);
    STWI_send_SP_StartREQ();
}

static void rfu_CB_startSearchParent(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_clearLinkStatus(MODE_CHILD);
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

void rfu_REQ_pollSearchParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollSearchParent);
    STWI_send_SP_PollingREQ();
}

static void rfu_CB_pollSearchParent(u8 reqCommand, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_readParentCandidateList();
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

void rfu_REQ_endSearchParent(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SP_EndREQ();
}

static void rfu_STC_readParentCandidateList(void)
{
    u8 numSlots, i, check_sum, my_check_sum, j;
    u8 *uname_p, *packet_p;
    struct RfuTgtData *target;

    CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
    packet_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0];
    numSlots = packet_p[1];
    packet_p += 4;
    gRfuLinkStatus->findParentCount = 0;
    for (i = 0; i < RFU_CHILD_MAX && numSlots != 0; ++i)
    {
        numSlots -= 7;
        uname_p = packet_p + 6;
        packet_p += 19;
        check_sum = ~*packet_p;
        ++packet_p;
        my_check_sum = 0;
        for (j = 0; j < 8; ++j)
        {
            my_check_sum += *packet_p++;
            my_check_sum += *uname_p++;
        }
        if (my_check_sum == check_sum)
        {
            packet_p -= 28;
            target = &gRfuLinkStatus->partner[gRfuLinkStatus->findParentCount];
            target->id = *(u16 *)packet_p;
            packet_p += 2;
            target->slot = *packet_p;
            packet_p += 2;
            target->serialNo = *(u16 *)packet_p & 0x7FFF;
            if (*(u16 *)packet_p & 0x8000)
                target->mbootFlag = 1;
            else
                target->mbootFlag = 0;
            packet_p += 2;
            for (j = 0; j < RFU_GAME_NAME_LENGTH; ++j)
                target->gname[j] = *packet_p++;
            ++packet_p;
            for (j = 0; j < PLAYER_NAME_LENGTH + 1; ++j)
                target->uname[j] = *packet_p++;
            ++gRfuLinkStatus->findParentCount;
        }
    }
}

void rfu_REQ_startConnectParent(u16 pid)
{
    u16 result = 0;
    u8 i;
    for (i = 0; i < RFU_CHILD_MAX && gRfuLinkStatus->partner[i].id != pid; ++i)
        ;
    if (i == RFU_CHILD_MAX)
        result = ERR_PID_NOT_FOUND;
    if (result == 0)
    {
        gRfuStatic->tryPid = pid;
        STWI_set_Callback_M(rfu_STC_REQ_callback);
        STWI_send_CP_StartREQ(pid);
    }
    else
    {
        rfu_STC_REQ_callback(ID_CP_START_REQ, result);
    }
}

void rfu_REQ_pollConnectParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollConnectParent);
    STWI_send_CP_PollingREQ();
}

static void rfu_CB_pollConnectParent(u8 reqCommand, u16 reqResult)
{
    u16 id;
    u8 slot;
    u8 bm_slot_flag, i;
    struct RfuTgtData *target_p;
    struct RfuTgtData target_local;

    if (reqResult == 0)
    {
        id = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        slot = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6];
        if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
        {
            bm_slot_flag = 1 << slot;
            if (!(bm_slot_flag & gRfuLinkStatus->connSlotFlag))
            {
                gRfuLinkStatus->connSlotFlag |= bm_slot_flag;
                gRfuLinkStatus->linkLossSlotFlag &= ~bm_slot_flag;
                gRfuLinkStatus->my.id = id;
                ++gRfuLinkStatus->connCount;
                gRfuLinkStatus->parentChild = MODE_CHILD;
                gRfuStatic->flags |= 0x80;
                for (i = 0; i < RFU_CHILD_MAX; ++i)
                {
                    if (gRfuLinkStatus->partner[i].id == gRfuStatic->tryPid)
                    {
                        if (gRfuLinkStatus->findParentCount != 0)
                        {
                            target_p = &target_local;
                            CpuCopy16(&gRfuLinkStatus->partner[i], &target_local, sizeof(struct RfuTgtData));
                            CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
                            gRfuLinkStatus->findParentCount = 0;
                        }
                        else
                        {
                            target_p = &gRfuLinkStatus->partner[i];
                        }
                        break;
                    }
                }
                if (i < RFU_CHILD_MAX)
                {
                    CpuCopy16(target_p, &gRfuLinkStatus->partner[slot], sizeof(struct RfuTgtData));
                    gRfuLinkStatus->partner[slot].slot = slot;
                }
            }
        }
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

u16 rfu_getConnectParentStatus(u8 *status, u8 *connectSlotNo)
{
    u8 *packet_p;

    *status = 0xFF;
    packet_p = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;
    if (packet_p[0] == 0xa0 || packet_p[0] == 0xa1)
    {
        packet_p += 6;
        *connectSlotNo = packet_p[0];
        *status = packet_p[1];
        return 0;
    }
    return ERR_REQ_CMD_ID;
}

void rfu_REQ_endConnectParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollConnectParent);
    STWI_send_CP_EndREQ();
    if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6] < 4)
        gRfuStatic->linkEmergencyFlag[gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6]] = 0;
}

u16 rfu_syncVBlank(void)
{
    u8 masterSlave, i;
    s32 bmSlotFlag;

    rfu_NI_checkCommFailCounter();
    if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
        return 0;
    if (gRfuStatic->nowWatchInterval != 0)
        --gRfuStatic->nowWatchInterval;
    masterSlave = rfu_getMasterSlave();
    if (!(gRfuStatic->flags & 2))
    {
        if (masterSlave == AGB_CLK_SLAVE)
        {
            gRfuStatic->flags |= 4;
            gRfuStatic->watchdogTimer = 360;
        }
    }
    else if (masterSlave != AGB_CLK_SLAVE)
    {
        gRfuStatic->flags &= 0xFB;
    }
    if (masterSlave != AGB_CLK_SLAVE)
        gRfuStatic->flags &= 0xFD;
    else
        gRfuStatic->flags |= 2;
    if (!(gRfuStatic->flags & 4))
        return 0;
    if (gRfuStatic->watchdogTimer == 0)
    {
        gRfuStatic->flags &= 0xFB;
        bmSlotFlag = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
        for (i = 0; i < RFU_CHILD_MAX; ++i)
            if ((bmSlotFlag >> i) & 1)
                rfu_STC_removeLinkData(i, 1);
        gRfuLinkStatus->parentChild = MODE_NEUTRAL;
        return 1;
    }
    --gRfuStatic->watchdogTimer;
    return 0;
}

u16 rfu_REQBN_watchLink(u16 reqCommandId, u8 *bmLinkLossSlot, u8 *linkLossReason, u8 *parentBmLinkRecoverySlot)
{
    u8 reasonMaybe = 0;
    u8 reqResult = 0;
    u8 i;
    s32 stwiCommand, stwiParam;
    u8 *packet_p;
    u8 to_req_disconnect, newLinkLossFlag, num_packets, connSlotFlag, to_disconnect;

    *bmLinkLossSlot = 0;
    *linkLossReason = REASON_DISCONNECTED;
    *parentBmLinkRecoverySlot = 0;
    if (gRfuLinkStatus->parentChild == MODE_NEUTRAL || gSTWIStatus->msMode == 0)
        return 0;
    if (gRfuStatic->flags & 4)
        gRfuStatic->watchdogTimer = 360;
    if (gRfuStatic->nowWatchInterval == 0)
    {
    #if LIBRFU_VERSION < 1026
        gRfuStatic->nowWatchInterval = gRfuLinkStatus->watchInterval;
    #else
        gRfuStatic->nowWatchInterval = 4;
    #endif
        reasonMaybe = 1;
    }
    if ((u8)reqCommandId == ID_DISCONNECTED_AND_CHANGE_REQ)
    {
        u8 *packet_p_2 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;

        *bmLinkLossSlot = packet_p_2[4];
        *linkLossReason = packet_p_2[5];
        if (*linkLossReason == REASON_LINK_LOSS)
            *bmLinkLossSlot = gRfuLinkStatus->connSlotFlag;
        reasonMaybe = 2;
    }
    else
    {
        if (reqCommandId == 0x0136)
        {
            newLinkLossFlag = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[5];
            newLinkLossFlag ^= gRfuLinkStatus->connSlotFlag;
            *bmLinkLossSlot = newLinkLossFlag & gRfuLinkStatus->connSlotFlag;
            *linkLossReason = REASON_LINK_LOSS;
            for (i = 0; i < RFU_CHILD_MAX; ++i)
            {
                if ((*bmLinkLossSlot >> i) & 1)
                {
                    gRfuLinkStatus->strength[i] = 0;
                    rfu_STC_removeLinkData(i, 0);
                }
            }
        }
        if (reasonMaybe == 0)
            return 0;
    }
    stwiCommand = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.command;
    stwiParam = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_LinkStatusREQ();
    reqResult = STWI_poll_CommandEnd();
    if (reqResult == 0)
    {
        packet_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
        for (i = 0; i < RFU_CHILD_MAX; ++i)
            gRfuLinkStatus->strength[i] = *packet_p++;
        to_req_disconnect = 0;
        i = 0;
    }
    else
    {
        rfu_STC_REQ_callback(ID_LINK_STATUS_REQ, reqResult);
        return reqResult;
    }
    for (; i < RFU_CHILD_MAX; ++i)
    {
    #if LIBRFU_VERSION >= 1026
        if (gRfuStatic->lsFixedCount[i] != 0)
        {
            gRfuStatic->lsFixedCount[i] -= 4;
            if (gRfuLinkStatus->strength[i] <= 15)
                gRfuLinkStatus->strength[i] = 16;
        }
    #endif
        newLinkLossFlag = 1 << i;
        if (reqResult == 0)
        {
            if (reasonMaybe == 1 && (gRfuLinkStatus->connSlotFlag & newLinkLossFlag))
            {
                if (gRfuLinkStatus->strength[i] == 0)
                {
                    if (gRfuLinkStatus->parentChild == MODE_PARENT)
                    {
                        ++gRfuStatic->linkEmergencyFlag[i];
                        if (gRfuStatic->linkEmergencyFlag[i] > 3)
                        {
                            *bmLinkLossSlot |= newLinkLossFlag;
                            *linkLossReason = REASON_LINK_LOSS;
                        }
                    }
                    else
                    {
                        STWI_send_SystemStatusREQ();
                        if (STWI_poll_CommandEnd() == 0)
                        {
                            if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
                            {
                                *bmLinkLossSlot |= newLinkLossFlag;
                                *linkLossReason = REASON_LINK_LOSS;
                            }
                            else
                            {
                                if (++gRfuStatic->linkEmergencyFlag[i] > gRfuStatic->linkEmergencyLimit)
                                {
                                    gRfuStatic->linkEmergencyFlag[i] = 0;
                                    STWI_send_DisconnectREQ(gRfuLinkStatus->connSlotFlag);
                                    STWI_poll_CommandEnd();
                                    *bmLinkLossSlot |= newLinkLossFlag;
                                    *linkLossReason = REASON_LINK_LOSS;
                                }
                            }
                        }
                    }
                }
                else
                {
                    gRfuStatic->linkEmergencyFlag[i] = 0;
                }
            }
            if (gRfuLinkStatus->parentChild == MODE_PARENT && gRfuLinkStatus->strength[i] != 0)
            {
                if (newLinkLossFlag & gRfuLinkStatus->linkLossSlotFlag)
                {
                    if (gRfuLinkStatus->strength[i] > 10)
                    {
                        *parentBmLinkRecoverySlot |= newLinkLossFlag;
                        gRfuLinkStatus->connSlotFlag |= newLinkLossFlag;
                        gRfuLinkStatus->linkLossSlotFlag &= ~newLinkLossFlag;
                        ++gRfuLinkStatus->connCount;
                        gRfuStatic->linkEmergencyFlag[i] = 0;
                    }
                    else
                    {
                        gRfuLinkStatus->strength[i] = 0;
                    }
                }
                else
                {
                    if (!((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & newLinkLossFlag))
                    {
                        STWI_send_SlotStatusREQ();
                        STWI_poll_CommandEnd();
                        packet_p = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;
                        num_packets = packet_p[1] - 1;
                        for (packet_p += 8; num_packets != 0; packet_p += 4, --num_packets)
                        {
                            u16 cid = *(u16 *)packet_p;

                            if (packet_p[2] == i && cid == gRfuStatic->cidBak[i])
                            {
                                to_req_disconnect |= 1 << i;
                                break;
                            }
                        }
                    }
                }
            }
        }
        connSlotFlag = gRfuLinkStatus->connSlotFlag;
        to_disconnect = *bmLinkLossSlot;
        to_disconnect &= connSlotFlag;
        if (newLinkLossFlag & to_disconnect)
            rfu_STC_removeLinkData(i, 0);
    }
    if (to_req_disconnect != 0)
    {
        STWI_send_DisconnectREQ(to_req_disconnect);
        STWI_poll_CommandEnd();
    }
    // equivalent to:
    // gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.command = stwiCommand;
    *(u32 *)gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data = stwiCommand;
    gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] = stwiParam;
    return 0;
}

static void rfu_STC_removeLinkData(u8 bmConnectedPartnerId, u8 bmDisconnect)
{
    u8 bmLinkLossFlag = 1 << bmConnectedPartnerId;
    s32 bmLinkRetainedFlag;

#if LIBRFU_VERSION >= 1026
    gRfuStatic->lsFixedCount[bmConnectedPartnerId] = 0;
#endif
    if ((gRfuLinkStatus->connSlotFlag & bmLinkLossFlag) && gRfuLinkStatus->connCount != 0)
        --gRfuLinkStatus->connCount;
    gRfuLinkStatus->connSlotFlag &= bmLinkRetainedFlag = ~bmLinkLossFlag;
    gRfuLinkStatus->linkLossSlotFlag |= bmLinkLossFlag;
    if (gRfuLinkStatus->parentChild == MODE_CHILD && gRfuLinkStatus->connSlotFlag == 0)
        gRfuLinkStatus->parentChild = MODE_NEUTRAL;
    if (bmDisconnect)
    {
        CpuFill16(0, &gRfuLinkStatus->partner[bmConnectedPartnerId], sizeof(struct RfuTgtData));
        gRfuLinkStatus->linkLossSlotFlag &= bmLinkRetainedFlag;
        gRfuLinkStatus->getNameFlag &= bmLinkRetainedFlag;
        gRfuLinkStatus->strength[bmConnectedPartnerId] = 0;
    }
}

void rfu_REQ_disconnect(u8 bmDisconnectSlot)
{
    u16 result;

    if ((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & bmDisconnectSlot)
    {
        gRfuStatic->recoveryBmSlot = bmDisconnectSlot;
        if (gRfuLinkStatus->parentChild == MODE_NEUTRAL && gRfuStatic->flags & 0x80)
        {
            if (gRfuLinkStatus->linkLossSlotFlag & bmDisconnectSlot)
                rfu_CB_disconnect(48, 0);
        }
        else if (gRfuStatic->SCStartFlag
              && (STWI_set_Callback_M(rfu_CB_defaultCallback),
                  STWI_send_SC_EndREQ(),
                  (result = STWI_poll_CommandEnd()) != 0))
        {
            rfu_STC_REQ_callback(ID_SC_END_REQ, result);
        }
        else
        {
            STWI_set_Callback_M(rfu_CB_disconnect);
            STWI_send_DisconnectREQ(bmDisconnectSlot);
        }
    }
}

static void rfu_CB_disconnect(u8 reqCommand, u16 reqResult)
{
    u8 i, bm_slot_flag;

    if (reqResult == 3 && gRfuLinkStatus->parentChild == MODE_CHILD)
    {
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_SystemStatusREQ();
        if (STWI_poll_CommandEnd() == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
            reqResult = 0;
    }
    gRfuStatic->recoveryBmSlot &= gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
    gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8] = gRfuStatic->recoveryBmSlot;
    if (reqResult == 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            bm_slot_flag = 1 << i;
            if (bm_slot_flag & gRfuStatic->recoveryBmSlot)
                rfu_STC_removeLinkData(i, 1);
        }
    }
    if ((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) == 0)
        gRfuLinkStatus->parentChild = MODE_NEUTRAL;
    rfu_STC_REQ_callback(reqCommand, reqResult);
    if (gRfuStatic->SCStartFlag)
    {
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_SC_StartREQ();
        reqResult = STWI_poll_CommandEnd();
        if (reqResult != 0)
            rfu_STC_REQ_callback(ID_SC_START_REQ, reqResult);
    }
}

void rfu_REQ_CHILD_startConnectRecovery(u8 bmRecoverySlot)
{
    u8 i;

    gRfuStatic->recoveryBmSlot = bmRecoverySlot;
    for (i = 0; i < RFU_CHILD_MAX && !((bmRecoverySlot >> i) & 1); ++i)
        ;
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    // if i == 4, gRfuLinkStatus->partner[i].id becomes gRfuLinkStatus->my.id
    STWI_send_CPR_StartREQ(gRfuLinkStatus->partner[i].id, gRfuLinkStatus->my.id, bmRecoverySlot);
}

void rfu_REQ_CHILD_pollConnectRecovery(void)
{
    STWI_set_Callback_M(rfu_CB_CHILD_pollConnectRecovery);
    STWI_send_CPR_PollingREQ();
}

static void rfu_CB_CHILD_pollConnectRecovery(u8 reqCommand, u16 reqResult)
{
    u8 bm_slot_flag, i;
    struct RfuLinkStatus *rfuLinkStatus;

    if (reqResult == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4] == 0 && gRfuStatic->recoveryBmSlot)
    {
        gRfuLinkStatus->parentChild = MODE_CHILD;
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            bm_slot_flag = 1 << i;
            rfuLinkStatus = gRfuLinkStatus; // ???
            if (gRfuStatic->recoveryBmSlot & bm_slot_flag & rfuLinkStatus->linkLossSlotFlag)
            {
                gRfuLinkStatus->connSlotFlag |= bm_slot_flag;
                gRfuLinkStatus->linkLossSlotFlag &= ~bm_slot_flag;
                ++gRfuLinkStatus->connCount;
                gRfuStatic->linkEmergencyFlag[i] = 0;
            }
        }
        gRfuStatic->recoveryBmSlot = 0;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

u16 rfu_CHILD_getConnectRecoveryStatus(u8 *status)
{
    *status = 0xFF;
    if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0] == 0xB3 || gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0] == 0xB4)
    {
        *status = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
        return 0;
    }
    return ERR_REQ_CMD_ID;
}

void rfu_REQ_CHILD_endConnectRecovery(void)
{
    STWI_set_Callback_M(rfu_CB_CHILD_pollConnectRecovery);
    STWI_send_CPR_EndREQ();
}

static void rfu_STC_fastCopy(const u8 **src_p, u8 **dst_p, s32 size)
{
    const u8 *src = *src_p;
    u8 *dst = *dst_p;
    s32 i;

    for (i = size - 1; i != -1; --i)
        *dst++ = *src++;
    *src_p = src;
    *dst_p = dst;
}

void rfu_REQ_changeMasterSlave(void)
{
    if (STWI_read_status(1) == AGB_CLK_MASTER)
    {
        STWI_set_Callback_M(rfu_STC_REQ_callback);
        STWI_send_MS_ChangeREQ();
    }
    else
    {
        rfu_STC_REQ_callback(ID_MS_CHANGE_REQ, 0);
    }
}

bool8 rfu_getMasterSlave(void)
{
    bool8 masterSlave = STWI_read_status(1);

    if (masterSlave == AGB_CLK_MASTER)
    {
        if (gSTWIStatus->sending)
        {
            if (gSTWIStatus->reqActiveCommand == ID_MS_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_DATA_TX_AND_CHANGE_REQ
             || gSTWIStatus->reqActiveCommand == ID_RESUME_RETRANSMIT_AND_CHANGE_REQ)
                masterSlave = AGB_CLK_SLAVE;
        }
    }
    return masterSlave;
}

void rfu_clearAllSlot(void)
{
    u16 i;
    u16 IMEBackup = REG_IME;

    REG_IME = 0;
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
        CpuFill16(0, gRfuSlotStatusNI[i], 2 * sizeof(struct NIComm));
        CpuFill16(0, gRfuSlotStatusUNI[i], sizeof(struct UNISend) + sizeof(struct UNIRecv));
        gRfuLinkStatus->remainLLFrameSizeChild[i] = 16;
    }
    gRfuLinkStatus->remainLLFrameSizeParent = LLF_P_SIZE;
    gRfuLinkStatus->sendSlotNIFlag = 0;
    gRfuLinkStatus->recvSlotNIFlag = 0;
    gRfuLinkStatus->sendSlotUNIFlag = 0;
    gRfuStatic->recvRenewalFlag = 0;
    REG_IME = IMEBackup;
}

static void rfu_STC_releaseFrame(u8 bm_slot_id, u8 send_recv, struct NIComm *NI_comm)
{

    if (!(gRfuStatic->flags & 0x80))
    {
        if (send_recv == 0)
            gRfuLinkStatus->remainLLFrameSizeParent += NI_comm->payloadSize;
        gRfuLinkStatus->remainLLFrameSizeParent += 3;
    }
    else
    {
        if (send_recv == 0)
            gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id] += NI_comm->payloadSize;
        gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id] += 2;
    }
}

u16 rfu_clearSlot(u8 connTypeFlag, u8 slotStatusIndex)
{
    u16 imeBak, send_recv, i;
    struct NIComm *NI_comm;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    if (!(connTypeFlag & (TYPE_UNI_SEND | TYPE_UNI_RECV | TYPE_NI_SEND | TYPE_NI_RECV)))
        return ERR_COMM_TYPE;
    imeBak = REG_IME;
    REG_IME = 0;
    if (connTypeFlag & (TYPE_NI_SEND | TYPE_NI_RECV))
    {
        for (send_recv = 0; send_recv < 2; ++send_recv)
        {
            NI_comm = NULL;
            if (send_recv == 0)
            {
                if (connTypeFlag & TYPE_NI_SEND)
                {
                    NI_comm = &gRfuSlotStatusNI[slotStatusIndex]->send;
                    gRfuLinkStatus->sendSlotNIFlag &= ~NI_comm->bmSlotOrg;
                }
            }
            else
            {
                if (connTypeFlag & TYPE_NI_RECV)
                {
                    NI_comm = &gRfuSlotStatusNI[slotStatusIndex]->recv;
                    gRfuLinkStatus->recvSlotNIFlag &= ~(1 << slotStatusIndex);
                }
            }
            if (NI_comm != NULL)
            {
                if (NI_comm->state & SLOT_BUSY_FLAG)
                {
                    rfu_STC_releaseFrame(slotStatusIndex, send_recv, NI_comm);
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                        if ((NI_comm->bmSlotOrg >> i) & 1)
                            NI_comm->failCounter = 0;
                }
                CpuFill16(0, NI_comm, sizeof(struct NIComm));
            }
        }
    }
    if (connTypeFlag & TYPE_UNI_SEND)
    {
        struct RfuSlotStatusUNI *slotStatusUNI = gRfuSlotStatusUNI[slotStatusIndex];

        if (slotStatusUNI->send.state & SLOT_BUSY_FLAG)
        {
            if (!(gRfuStatic->flags & 0x80))
                gRfuLinkStatus->remainLLFrameSizeParent += 3 + (u8)slotStatusUNI->send.payloadSize;
            else
                gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex] += 2 + (u8)slotStatusUNI->send.payloadSize;
            gRfuLinkStatus->sendSlotUNIFlag &= ~slotStatusUNI->send.bmSlot;
        }
        CpuFill16(0, &slotStatusUNI->send, sizeof(struct UNISend));
    }
    if (connTypeFlag & TYPE_UNI_RECV)
    {
        CpuFill16(0, &gRfuSlotStatusUNI[slotStatusIndex]->recv, sizeof(struct UNIRecv));
    }
    REG_IME = imeBak;
    return 0;
}

u16 rfu_setRecvBuffer(u8 connType, u8 slotNo, void *buffer, u32 buffSize)
{
    if (slotNo >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    if (connType & TYPE_NI)
    {
        gRfuSlotStatusNI[slotNo]->recvBuffer = buffer;
        gRfuSlotStatusNI[slotNo]->recvBufferSize = buffSize;
    }
    else if (!(connType & TYPE_UNI))
    {
        return ERR_COMM_TYPE;
    }
    else
    {
        gRfuSlotStatusUNI[slotNo]->recvBuffer = buffer;
        gRfuSlotStatusUNI[slotNo]->recvBufferSize = buffSize;
    }
    return 0;
}

u16 rfu_NI_setSendData(u8 bmSendSlot, u8 subFrameSize, const void *src, u32 size)
{
    return rfu_STC_setSendData_org(32, bmSendSlot, subFrameSize, src, size);
}

u16 rfu_UNI_setSendData(u8 bmSendSlot, const void *src, u8 size)
{
    u8 subFrameSize;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        subFrameSize = size + 3;
    else
        subFrameSize = size + 2;
    return rfu_STC_setSendData_org(16, bmSendSlot, subFrameSize, src, 0);
}

u16 rfu_NI_CHILD_setSendGameName(u8 slotNo, u8 subFrameSize)
{
    return rfu_STC_setSendData_org(64, 1 << slotNo, subFrameSize, &gRfuLinkStatus->my.serialNo, 26);
}

static u16 rfu_STC_setSendData_org(u8 ni_or_uni, u8 bmSendSlot, u8 subFrameSize, const void *src, u32 dataSize)
{
    u8 bm_slot_id, sendSlotFlag;
    u8 frameSize;
    u8 *llFrameSize_p;
    u8 sending;
    u8 i;
    u16 imeBak;
    struct RfuSlotStatusUNI *slotStatus_UNI;
    struct RfuSlotStatusNI *slotStatus_NI;

    if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
        return ERR_MODE_NOT_CONNECTED;
    if (!(bmSendSlot & 0xF))
        return ERR_SLOT_NO;
    if (((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & bmSendSlot) != bmSendSlot)
        return ERR_SLOT_NOT_CONNECTED;
    if (ni_or_uni & 0x10)
        sendSlotFlag = gRfuLinkStatus->sendSlotUNIFlag;
    else
        sendSlotFlag = gRfuLinkStatus->sendSlotNIFlag;
    if (sendSlotFlag & bmSendSlot)
        return ERR_SLOT_BUSY;
    for (bm_slot_id = 0; bm_slot_id < RFU_CHILD_MAX && !((bmSendSlot >> bm_slot_id) & 1); ++bm_slot_id)
        ;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        llFrameSize_p = &gRfuLinkStatus->remainLLFrameSizeParent;
    else if (gRfuLinkStatus->parentChild == MODE_CHILD)
        llFrameSize_p = &gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id];
    frameSize = llsf_struct[gRfuLinkStatus->parentChild].frameSize;
    if (subFrameSize > *llFrameSize_p || subFrameSize <= frameSize)
        return ERR_SUBFRAME_SIZE;
    imeBak = REG_IME;
    REG_IME = 0;
    sending = ni_or_uni & 0x20;
    if (sending || ni_or_uni == 0x40)
    {
        slotStatus_NI = gRfuSlotStatusNI[bm_slot_id];
        slotStatus_UNI = NULL;
        slotStatus_NI->send.errorCode = 0;
        slotStatus_NI->send.now_p[0] = &slotStatus_NI->send.dataType;
        slotStatus_NI->send.remainSize = 7;
        slotStatus_NI->send.bmSlotOrg = bmSendSlot;
        slotStatus_NI->send.bmSlot = bmSendSlot;
        slotStatus_NI->send.payloadSize = subFrameSize - frameSize;
        if (sending != 0)
            slotStatus_NI->send.dataType = 0;
        else
            slotStatus_NI->send.dataType = 1;

        slotStatus_NI->send.dataSize = dataSize;
        slotStatus_NI->send.src = src;
        slotStatus_NI->send.ack = 0;
        slotStatus_NI->send.phase = 0;
        for (i = 0; i < WINDOW_COUNT; ++i)
        {
            slotStatus_NI->send.recvAckFlag[i] = 0;
            slotStatus_NI->send.n[i] = 1;
        }
        for (bm_slot_id = 0; bm_slot_id < RFU_CHILD_MAX; ++bm_slot_id)
        {
            do
            {
                if ((bmSendSlot >> bm_slot_id) & 1)
                    gRfuSlotStatusNI[bm_slot_id]->send.failCounter = 0;
            } while (0);
        }
        gRfuLinkStatus->sendSlotNIFlag |= bmSendSlot;
        *llFrameSize_p -= subFrameSize;
        slotStatus_NI->send.state = SLOT_STATE_SEND_START;
    }
    else if (ni_or_uni & 0x10)
    {
        slotStatus_UNI = gRfuSlotStatusUNI[bm_slot_id];
        slotStatus_UNI->send.bmSlot = bmSendSlot;
        slotStatus_UNI->send.src = src;
        slotStatus_UNI->send.payloadSize = subFrameSize - frameSize;
        *llFrameSize_p -= subFrameSize;
        slotStatus_UNI->send.state = SLOT_STATE_SEND_UNI;
        gRfuLinkStatus->sendSlotUNIFlag |= bmSendSlot;
    }
    REG_IME = imeBak;
    return 0;
}

u16 rfu_changeSendTarget(u8 connType, u8 slotStatusIndex, u8 bmNewTgtSlot)
{
    struct RfuSlotStatusNI *slotStatusNI;
    u16 imeBak;
    u8 i;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    if (connType == 0x20)
    {
        slotStatusNI = gRfuSlotStatusNI[slotStatusIndex];
        if ((slotStatusNI->send.state & SLOT_BUSY_FLAG)
         && (slotStatusNI->send.state & SLOT_SEND_FLAG))
        {
            connType = bmNewTgtSlot ^ slotStatusNI->send.bmSlot;

            if (!(connType & bmNewTgtSlot))
            {
                if (connType)
                {
                    imeBak = REG_IME;
                    REG_IME = 0;
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                    {
                        if ((connType >> i) & 1)
                            gRfuSlotStatusNI[i]->send.failCounter = 0;
                    }
                    gRfuLinkStatus->sendSlotNIFlag &= ~connType;
                    slotStatusNI->send.bmSlot = bmNewTgtSlot;
                    if (slotStatusNI->send.bmSlot == 0)
                    {
                        rfu_STC_releaseFrame(slotStatusIndex, 0, &slotStatusNI->send);
                        slotStatusNI->send.state = SLOT_STATE_SEND_FAILED;
                    }
                    REG_IME = imeBak;
                }
            }
            else
            {
                return ERR_SLOT_TARGET;
            }
        }
        else
        {
            return ERR_SLOT_NOT_SENDING;
        }
    }
    else
    {
        if (connType == 16)
        {
            s32 bmSlot;

            if (gRfuSlotStatusUNI[slotStatusIndex]->send.state != SLOT_STATE_SEND_UNI)
                return ERR_SLOT_NOT_SENDING;
            for (bmSlot = 0, i = 0; i < RFU_CHILD_MAX; ++i)
                if (i != slotStatusIndex)
                    bmSlot |= gRfuSlotStatusUNI[i]->send.bmSlot;
            if (bmNewTgtSlot & bmSlot)
                return ERR_SLOT_TARGET;
            imeBak = REG_IME;
            REG_IME = 0;
            gRfuLinkStatus->sendSlotUNIFlag &= ~gRfuSlotStatusUNI[slotStatusIndex]->send.bmSlot;
            gRfuLinkStatus->sendSlotUNIFlag |= bmNewTgtSlot;
            gRfuSlotStatusUNI[slotStatusIndex]->send.bmSlot = bmNewTgtSlot;
            REG_IME = imeBak;
        }
        else
        {
            return ERR_COMM_TYPE;
        }
    }
    return 0;
}

u16 rfu_NI_stopReceivingData(u8 slotStatusIndex)
{
    u16 imeBak;
    struct NIComm *NI_comm;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    NI_comm = &gRfuSlotStatusNI[slotStatusIndex]->recv;
    imeBak = REG_IME;
    REG_IME = 0;
    if (NI_comm->state & SLOT_BUSY_FLAG)
    {
        if (NI_comm->state == SLOT_STATE_RECV_LAST)
            NI_comm->state = SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN;
        else
            NI_comm->state = SLOT_STATE_RECV_FAILED;
        gRfuLinkStatus->recvSlotNIFlag &= ~(1 << slotStatusIndex);
        rfu_STC_releaseFrame(slotStatusIndex, 1, NI_comm);
    }
    REG_IME = imeBak;
    return 0;
}

u16 rfu_UNI_changeAndReadySendData(u8 slotStatusIndex, const void *src, u8 size)
{
    struct UNISend *UNI_send;
    u8 *frame_p;
    u16 imeBak;
    u8 frameEnd;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    UNI_send = &gRfuSlotStatusUNI[slotStatusIndex]->send;
    if (UNI_send->state != SLOT_STATE_SEND_UNI)
        return ERR_SLOT_NOT_SENDING;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        frame_p = &gRfuLinkStatus->remainLLFrameSizeParent;
        frameEnd = gRfuLinkStatus->remainLLFrameSizeParent + (u8)UNI_send->payloadSize;
    }
    else
    {
        frame_p = &gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex];
        frameEnd = gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex] + (u8)UNI_send->payloadSize;
    }
    if (frameEnd < size)
        return ERR_SUBFRAME_SIZE;
    imeBak = REG_IME;
    REG_IME = 0;
    UNI_send->src = src;
    *frame_p = frameEnd - size;
    UNI_send->payloadSize = size;
    UNI_send->dataReadyFlag = 1;
    REG_IME = imeBak;
    return 0;
}

void rfu_UNI_readySendData(u8 slotStatusIndex)
{
    if (slotStatusIndex < RFU_CHILD_MAX)
    {
        if (gRfuSlotStatusUNI[slotStatusIndex]->send.state == SLOT_STATE_SEND_UNI)
            gRfuSlotStatusUNI[slotStatusIndex]->send.dataReadyFlag = 1;
    }
}

void rfu_UNI_clearRecvNewDataFlag(u8 slotStatusIndex)
{
    if (slotStatusIndex < RFU_CHILD_MAX)
        gRfuSlotStatusUNI[slotStatusIndex]->recv.newDataFlag = 0;
}

void rfu_REQ_sendData(bool8 clockChangeFlag)
{
    if (gRfuLinkStatus->parentChild != MODE_NEUTRAL)
    {
        if (gRfuLinkStatus->parentChild == MODE_PARENT
         && !(gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag))
        {
            if (gRfuStatic->commExistFlag)
            {
                gRfuStatic->emberCount = 16;
                gRfuStatic->nullFrameCount = 0;
            }
            if (gRfuStatic->emberCount)
                --gRfuStatic->emberCount;
            else
                ++gRfuStatic->nullFrameCount;
            if (gRfuStatic->emberCount
             || !(gRfuStatic->nullFrameCount & 0xF))
            {
                gRfuFixed->LLFBuffer[0] = 1;
                gRfuFixed->LLFBuffer[4] = 0xFF;
                STWI_set_Callback_M(rfu_CB_sendData3);
                if (!clockChangeFlag)
                    STWI_send_DataTxREQ(gRfuFixed->LLFBuffer, 1);
                else
                    STWI_send_DataTxAndChangeREQ(gRfuFixed->LLFBuffer, 1);
                return;
            }
        }
        else
        {
            if (!gRfuLinkStatus->LLFReadyFlag)
                rfu_constructSendLLFrame();
            if (gRfuLinkStatus->LLFReadyFlag)
            {
                STWI_set_Callback_M(rfu_CB_sendData);
                if (clockChangeFlag)
                {
                    STWI_send_DataTxAndChangeREQ(gRfuFixed->LLFBuffer, gRfuStatic->totalPacketSize + 4);
                    return;
                }
                STWI_send_DataTxREQ(gRfuFixed->LLFBuffer, gRfuStatic->totalPacketSize + 4);
            }
        }
        if (clockChangeFlag)
        {
            if (gRfuLinkStatus->parentChild == MODE_PARENT)
            {
                if (gSTWIStatus->callbackS != NULL)
                    gSTWIStatus->callbackS(39);
            }
            else
            {
                STWI_set_Callback_M(rfu_CB_sendData2);
                STWI_send_MS_ChangeREQ();
            }
        }
    }
}

static void rfu_CB_sendData(UNUSED u8 reqCommand, u16 reqResult)
{
    u8 i;
    struct NIComm *NI_comm;

    if (reqResult == 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            if (gRfuSlotStatusUNI[i]->send.dataReadyFlag)
                gRfuSlotStatusUNI[i]->send.dataReadyFlag = 0;
            NI_comm = &gRfuSlotStatusNI[i]->send;
            if (NI_comm->state == SLOT_STATE_SEND_NULL)
            {
                rfu_STC_releaseFrame(i, 0, NI_comm);
                gRfuLinkStatus->sendSlotNIFlag &= ~NI_comm->bmSlot;
                if (NI_comm->dataType == 1)
                    gRfuLinkStatus->getNameFlag |= 1 << i;
                NI_comm->state = SLOT_STATE_SEND_SUCCESS;
            }
        }
    }
    gRfuLinkStatus->LLFReadyFlag = 0;
    rfu_STC_REQ_callback(ID_DATA_TX_REQ, reqResult);
}

static void rfu_CB_sendData2(UNUSED u8 reqCommand, u16 reqResult)
{
    rfu_STC_REQ_callback(ID_DATA_TX_REQ, reqResult);
}

static void rfu_CB_sendData3(u8 reqCommand, u16 reqResult)
{
    if (reqResult != 0)
        rfu_STC_REQ_callback(ID_DATA_TX_REQ, reqResult);
    else if (reqCommand == ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ)
        rfu_STC_REQ_callback(ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ, 0);
}

static void rfu_constructSendLLFrame(void)
{
    u32 pakcketSize, currSize;
    u8 i;
    u8 *llf_p;

    if (gRfuLinkStatus->parentChild != MODE_NEUTRAL
     && gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag)
    {
        gRfuLinkStatus->LLFReadyFlag = 0;
        pakcketSize = 0;
        llf_p = (u8 *)&gRfuFixed->LLFBuffer[1];
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            currSize = 0;
            if (gRfuSlotStatusNI[i]->send.state & SLOT_BUSY_FLAG)
                currSize = rfu_STC_NI_constructLLSF(i, &llf_p, &gRfuSlotStatusNI[i]->send);
            if (gRfuSlotStatusNI[i]->recv.state & SLOT_BUSY_FLAG)
                currSize += rfu_STC_NI_constructLLSF(i, &llf_p, &gRfuSlotStatusNI[i]->recv);
            if (gRfuSlotStatusUNI[i]->send.state == SLOT_STATE_SEND_UNI)
                currSize += rfu_STC_UNI_constructLLSF(i, &llf_p);
            if (currSize != 0)
            {
                if (gRfuLinkStatus->parentChild == MODE_PARENT)
                    pakcketSize += currSize;
                else
                    pakcketSize |= currSize << (5 * i + 8);
            }
        }
        if (pakcketSize != 0)
        {
            while ((u32)llf_p & 3)
                *llf_p++ = 0;
            gRfuFixed->LLFBuffer[0] = pakcketSize;
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
            {
                u8 *maxSize = llf_p - offsetof(struct RfuFixed, LLFBuffer[1]);

                pakcketSize = maxSize - *(u8 *volatile *)&gRfuFixed;
            }
        }
        gRfuStatic->totalPacketSize = pakcketSize;
    }
}

static u16 rfu_STC_NI_constructLLSF(u8 bm_slot_id, u8 **dest_pp, struct NIComm *NI_comm)
{
    u16 size;
    u32 frame;
    u8 i;
    u8 *frame8_p;
    const struct LLSFStruct *llsf = &llsf_struct[gRfuLinkStatus->parentChild];

    if (NI_comm->state == SLOT_STATE_SENDING)
    {
        while (NI_comm->now_p[NI_comm->phase] >= (const u8 *)NI_comm->src + NI_comm->dataSize)
        {
            ++NI_comm->phase;
            if (NI_comm->phase == 4)
                NI_comm->phase = 0;
        }
    }
    if (NI_comm->state & SLOT_RECV_FLAG)
    {
        size = 0;
    }
    else if (NI_comm->state == SLOT_STATE_SENDING)
    {
        if (NI_comm->now_p[NI_comm->phase] + NI_comm->payloadSize > (const u8 *)NI_comm->src + NI_comm->dataSize)
            size = (const u8 *)NI_comm->src + NI_comm->dataSize - NI_comm->now_p[NI_comm->phase];
        else
            size = NI_comm->payloadSize;
    }
    else
    {
        if (NI_comm->remainSize >= NI_comm->payloadSize)
            size = NI_comm->payloadSize;
        else
            size = NI_comm->remainSize;
    }
    frame = (NI_comm->state & 0xF) << llsf->slotStateShift
         | NI_comm->ack << llsf->ackShift
         | NI_comm->phase << llsf->phaseShift
         | NI_comm->n[NI_comm->phase] << llsf->nShift
         | size;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        frame |= NI_comm->bmSlot << 18;
    frame8_p = (u8 *)&frame;
    for (i = 0; i < llsf->frameSize; ++i)
        *(*dest_pp)++ = *frame8_p++;
    if (size != 0)
    {
        const u8 *src = NI_comm->now_p[NI_comm->phase];

        gRfuFixed->fastCopyPtr(&src, dest_pp, size);
    }
    if (NI_comm->state == SLOT_STATE_SENDING)
    {
        ++NI_comm->phase;
        if (NI_comm->phase == 4)
            NI_comm->phase = 0;
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        gRfuLinkStatus->LLFReadyFlag = 1;
    else
        gRfuLinkStatus->LLFReadyFlag |= 1 << bm_slot_id;
    return size + llsf->frameSize;
}

static u16 rfu_STC_UNI_constructLLSF(u8 bm_slot_id, u8 **dest_p)
{
    const struct LLSFStruct *llsf;
    const u8 *src_p;
    u32 frame;
    u8 *frame8_p;
    u8 i;
    struct UNISend *UNI_send = &gRfuSlotStatusUNI[bm_slot_id]->send;

    if (!UNI_send->dataReadyFlag || !UNI_send->bmSlot)
        return 0;
    llsf = &llsf_struct[gRfuLinkStatus->parentChild];
    frame = (UNI_send->state & 0xF) << llsf->slotStateShift
         | UNI_send->payloadSize;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        frame |= UNI_send->bmSlot << 18;
    frame8_p = (u8 *)&frame;
    for (i = 0; i < llsf->frameSize; ++i)
        *(*dest_p)++ = *frame8_p++;
    src_p = UNI_send->src;
    gRfuFixed->fastCopyPtr(&src_p, dest_p, UNI_send->payloadSize);
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        gRfuLinkStatus->LLFReadyFlag = 16;
    else
        gRfuLinkStatus->LLFReadyFlag |= 16 << bm_slot_id;
    return llsf->frameSize + UNI_send->payloadSize;
}

void rfu_REQ_recvData(void)
{
    if (gRfuLinkStatus->parentChild != MODE_NEUTRAL)
    {
        gRfuStatic->commExistFlag = gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag;
        gRfuStatic->recvErrorFlag = 0;
        STWI_set_Callback_M(rfu_CB_recvData);
        STWI_send_DataRxREQ();
    }
}

static void rfu_CB_recvData(u8 reqCommand, u16 reqResult)
{
    u8 i;
    struct RfuSlotStatusNI *slotStatusNI;
    struct NIComm *NI_comm;

    if (reqResult == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[1])
    {
        gRfuStatic->NIEndRecvFlag = 0;
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
            rfu_STC_PARENT_analyzeRecvPacket();
        else
            rfu_STC_CHILD_analyzeRecvPacket();
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            slotStatusNI = gRfuSlotStatusNI[i];
            if (slotStatusNI->recv.state == SLOT_STATE_RECV_LAST && !((gRfuStatic->NIEndRecvFlag >> i) & 1))
            {
                NI_comm = &slotStatusNI->recv;
                if (NI_comm->dataType == 1)
                    gRfuLinkStatus->getNameFlag |= 1 << i;
                rfu_STC_releaseFrame(i, 1, NI_comm);
                gRfuLinkStatus->recvSlotNIFlag &= ~NI_comm->bmSlot;
                slotStatusNI->recv.state = SLOT_STATE_RECV_SUCCESS;
            }
        }
        if (gRfuStatic->recvErrorFlag)
            reqResult = gRfuStatic->recvErrorFlag | ERR_DATA_RECV;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

static void rfu_STC_PARENT_analyzeRecvPacket(void)
{
    u32 frames32;
    u8 bm_slot_id;
    u8 frame_counts[RFU_CHILD_MAX];
    u8 *packet_p;

    frames32 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] >> 8;
    for (bm_slot_id = 0; bm_slot_id < RFU_CHILD_MAX; ++bm_slot_id)
    {
        frame_counts[bm_slot_id] = frames32 & 0x1F;
        frames32 >>= 5;
        if (frame_counts[bm_slot_id] == 0)
            gRfuStatic->NIEndRecvFlag |= 1 << bm_slot_id;
    }
    packet_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8];
    for (bm_slot_id = 0; bm_slot_id < RFU_CHILD_MAX; ++bm_slot_id)
    {
        if (frame_counts[bm_slot_id])
        {
            u8 *frames_p = &frame_counts[bm_slot_id];

            do
            {
                u8 analyzed_frames = rfu_STC_analyzeLLSF(bm_slot_id, packet_p, *frames_p);

                packet_p += analyzed_frames;
                *frames_p -= analyzed_frames;
            } while (!(*frames_p & 0x80) && (*frames_p));
        }
    }
}

static void rfu_STC_CHILD_analyzeRecvPacket(void)
{
    u16 frames_remaining;
    u8 *packet_p;
    u16 analyzed_frames;

    frames_remaining = *(u16 *)&gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4] & 0x7F;
    packet_p = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8];
    if (frames_remaining == 0)
        gRfuStatic->NIEndRecvFlag = 15;
    do
    {
        if (frames_remaining == 0)
            break;
        analyzed_frames = rfu_STC_analyzeLLSF(0, packet_p, frames_remaining);
        packet_p += analyzed_frames;
        frames_remaining -= analyzed_frames;
    } while (!(frames_remaining & 0x8000));
}

static u16 rfu_STC_analyzeLLSF(u8 slot_id, const u8 *src, u16 last_frame)
{
    struct RfuLocalStruct llsf_NI;
    const struct LLSFStruct *llsf_p;
    u32 frames;
    u8 i;
    u16 retVal;

    llsf_p = &llsf_struct[~gRfuLinkStatus->parentChild & (MODE_NEUTRAL & MODE_PARENT)];
    if (last_frame < llsf_p->frameSize)
        return last_frame;
    frames = 0;
    for (i = 0; i < llsf_p->frameSize; ++i)
        frames |= *src++ << 8 * i;
    llsf_NI.recvFirst = (frames >> llsf_p->recvFirstShift) & llsf_p->recvFirstMask;
    llsf_NI.connSlotFlag = (frames >> llsf_p->connSlotFlagShift) & llsf_p->connSlotFlagMask;
    llsf_NI.slotState = (frames >> llsf_p->slotStateShift) & llsf_p->slotStateMask;
    llsf_NI.ack = (frames >> llsf_p->ackShift) & llsf_p->ackMask;
    llsf_NI.phase = (frames >> llsf_p->phaseShift) & llsf_p->phaseMask;
    llsf_NI.n = (frames >> llsf_p->nShift) & llsf_p->nMask;
    llsf_NI.frame = (frames  & llsf_p->framesMask) & frames;
    retVal = llsf_NI.frame + llsf_p->frameSize;
    if (llsf_NI.recvFirst == 0)
    {
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
        {
            if ((gRfuLinkStatus->connSlotFlag >> slot_id) & 1)
            {
                if (llsf_NI.slotState == LCOM_UNI)
                {
                    rfu_STC_UNI_receive(slot_id, &llsf_NI, src);
                }
                else if (llsf_NI.ack == 0)
                {
                    rfu_STC_NI_receive_Receiver(slot_id, &llsf_NI, src);
                }
                else
                {
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                        if (((gRfuSlotStatusNI[i]->send.bmSlot >> slot_id) & 1)
                         && ((gRfuLinkStatus->sendSlotNIFlag >> slot_id) & 1))
                            break;
                    if (i < RFU_CHILD_MAX)
                        rfu_STC_NI_receive_Sender(i, slot_id, &llsf_NI, src);
                }
            }
        }
        else
        {
            s32 conSlots = gRfuLinkStatus->connSlotFlag & llsf_NI.connSlotFlag;

            if (conSlots)
            {
                for (i = 0; i < RFU_CHILD_MAX; ++i)
                {
                    if ((conSlots >> i) & 1)
                    {
                        if (llsf_NI.slotState == LCOM_UNI)
                            rfu_STC_UNI_receive(i, &llsf_NI, src);
                        else if (llsf_NI.ack == 0)
                            rfu_STC_NI_receive_Receiver(i, &llsf_NI, src);
                        else if ((gRfuLinkStatus->sendSlotNIFlag >> i) & 1)
                            rfu_STC_NI_receive_Sender(i, i, &llsf_NI, src);
                    }
                }
            }
        }
    }
    return retVal;
}

static void rfu_STC_UNI_receive(u8 bm_slot_id, const struct RfuLocalStruct *llsf_NI, const u8 *src)
{
    u8 *dest;
    u32 size;
    struct RfuSlotStatusUNI *slotStatusUNI = gRfuSlotStatusUNI[bm_slot_id];
    struct UNIRecv *UNI_recv = &slotStatusUNI->recv;

    UNI_recv->errorCode = 0;
    if (gRfuSlotStatusUNI[bm_slot_id]->recvBufferSize < llsf_NI->frame)
    {
        slotStatusUNI->recv.state = SLOT_STATE_RECV_IGNORE;
        UNI_recv->errorCode = ERR_RECV_BUFF_OVER;
    }
    else
    {
        if (UNI_recv->dataBlockFlag)
        {
            if (UNI_recv->newDataFlag)
            {
                UNI_recv->errorCode = ERR_RECV_UNK;
                goto force_tail_merge;
            }
        }
        else
        {
            if (UNI_recv->newDataFlag)
                UNI_recv->errorCode = ERR_RECV_DATA_OVERWRITED;
        }
        UNI_recv->state = SLOT_STATE_RECEIVING;
        size = UNI_recv->dataSize = llsf_NI->frame;
        dest = gRfuSlotStatusUNI[bm_slot_id]->recvBuffer;
        gRfuFixed->fastCopyPtr(&src, &dest, size);
        UNI_recv->newDataFlag = 1;
        UNI_recv->state = 0;
    }
force_tail_merge:
    if (UNI_recv->errorCode)
        gRfuStatic->recvErrorFlag |= 16 << bm_slot_id;
}

static void rfu_STC_NI_receive_Sender(u8 NI_slot, u8 bm_flag, const struct RfuLocalStruct *llsf_NI, const u8 *data_p)
{
    struct NIComm *NI_comm = &gRfuSlotStatusNI[NI_slot]->send;
    u16 state = NI_comm->state;
    u8 n = NI_comm->n[llsf_NI->phase];
    u8 i;
    u16 imeBak;

    if ((llsf_NI->slotState == LCOM_NI && state == SLOT_STATE_SENDING)
     || (llsf_NI->slotState == LCOM_NI_START && state == SLOT_STATE_SEND_START)
     || (llsf_NI->slotState == LCOM_NI_END && state == SLOT_STATE_SEND_LAST))
    {
        if (NI_comm->n[llsf_NI->phase] == llsf_NI->n)
            NI_comm->recvAckFlag[llsf_NI->phase] |= 1 << bm_flag;
    }
    if ((NI_comm->recvAckFlag[llsf_NI->phase] & NI_comm->bmSlot) == NI_comm->bmSlot)
    {
        NI_comm->n[llsf_NI->phase] = (NI_comm->n[llsf_NI->phase] + 1) & 3;
        NI_comm->recvAckFlag[llsf_NI->phase] = 0;
        if ((u16)(NI_comm->state + ~SLOT_STATE_SEND_NULL) <= 1)
        {
            if (NI_comm->state == SLOT_STATE_SEND_START)
                NI_comm->now_p[llsf_NI->phase] += NI_comm->payloadSize;
            else
                NI_comm->now_p[llsf_NI->phase] += NI_comm->payloadSize << 2;
            NI_comm->remainSize -= NI_comm->payloadSize;
            switch (NI_comm->remainSize)
            {
            default:
            case 0:
                NI_comm->phase = 0;
                if (NI_comm->state == SLOT_STATE_SEND_START)
                {
                    for (i = 0; i < WINDOW_COUNT; ++i)
                    {
                        NI_comm->n[i] = 1;
                        NI_comm->now_p[i] = NI_comm->src + NI_comm->payloadSize * i;
                    }
                    NI_comm->remainSize = NI_comm->dataSize;
                    NI_comm->state = SLOT_STATE_SENDING;
                }
                else
                {
                    NI_comm->n[0] = 0;
                    NI_comm->remainSize = 0;
                    NI_comm->state = SLOT_STATE_SEND_LAST;
                }
                break;
            case 1 ... INT_MAX:
                break;
            }
        }
        else if (NI_comm->state == SLOT_STATE_SEND_LAST)
        {
            NI_comm->state = SLOT_STATE_SEND_NULL;
        }
    }
    if (NI_comm->state != state
     || NI_comm->n[llsf_NI->phase] != n
     || (NI_comm->recvAckFlag[llsf_NI->phase] >> bm_flag) & 1)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        gRfuStatic->recvRenewalFlag |= 16 << bm_flag;
        gRfuSlotStatusNI[bm_flag]->send.failCounter = 0;
        REG_IME = imeBak;
    }
}

static void rfu_STC_NI_receive_Receiver(u8 bm_slot_id, const struct RfuLocalStruct *llsf_NI, const u8 *data_p)
{
    u16 imeBak;
    u32 state_check = 0;
    struct RfuSlotStatusNI *slotStatus_NI = gRfuSlotStatusNI[bm_slot_id];
    struct NIComm *recvSlot = &slotStatus_NI->recv;
    u16 state = slotStatus_NI->recv.state;
    u8 n = slotStatus_NI->recv.n[llsf_NI->phase];

    if (llsf_NI->slotState == LCOM_NI_END)
    {
        gRfuStatic->NIEndRecvFlag |= 1 << bm_slot_id;
        if (slotStatus_NI->recv.state == SLOT_STATE_RECEIVING)
        {
            slotStatus_NI->recv.phase = 0;
            slotStatus_NI->recv.n[0] = 0;
            slotStatus_NI->recv.state = SLOT_STATE_RECV_LAST;
        }
    }
    else if (llsf_NI->slotState == LCOM_NI)
    {
        if (state == SLOT_STATE_RECV_START && !recvSlot->remainSize)
            rfu_STC_NI_initSlot_asRecvDataEntity(bm_slot_id, recvSlot);
        if (recvSlot->state == SLOT_STATE_RECEIVING)
            state_check = 1;
    }
    else if (llsf_NI->slotState == LCOM_NI_START)
    {
        if (state == SLOT_STATE_RECV_START)
        {
            state_check = 1;
        }
        else
        {
            rfu_STC_NI_initSlot_asRecvControllData(bm_slot_id, recvSlot);
            if (slotStatus_NI->recv.state != SLOT_STATE_RECV_START)
                return;
            state_check = 1;
        }
    }
    if (state_check != 0)
    {
        if (llsf_NI->n == ((recvSlot->n[llsf_NI->phase] + 1) & 3))
        {
            gRfuFixed->fastCopyPtr(&data_p, (u8 **)&recvSlot->now_p[llsf_NI->phase], llsf_NI->frame);
            if (recvSlot->state == SLOT_STATE_RECEIVING)
                recvSlot->now_p[llsf_NI->phase] += 3 * recvSlot->payloadSize;
            recvSlot->remainSize -= llsf_NI->frame;
            recvSlot->n[llsf_NI->phase] = llsf_NI->n;
        }
    }
    if (recvSlot->errorCode == 0)
    {
        recvSlot->phase = llsf_NI->phase;
        if (recvSlot->state != state || recvSlot->n[llsf_NI->phase] != n || recvSlot->n[llsf_NI->phase] == llsf_NI->n)
        {
            imeBak = REG_IME;
            REG_IME = 0;
            gRfuStatic->recvRenewalFlag |= 1 << bm_slot_id;
            recvSlot->failCounter = 0;
            REG_IME = imeBak;
        }
    }
}

static void rfu_STC_NI_initSlot_asRecvControllData(u8 bm_slot_id, struct NIComm *NI_comm)
{
    u8 *llFrameSize_p;
    u32 llFrameSize;
    u8 bm_slot_flag;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        llFrameSize = 3;
        llFrameSize_p = &gRfuLinkStatus->remainLLFrameSizeParent;
    }
    else
    {
        llFrameSize = 2;
        llFrameSize_p = &gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id];
    }
    bm_slot_flag = 1 << bm_slot_id;
    if (NI_comm->state == 0)
    {
        if (*llFrameSize_p < llFrameSize)
        {
            NI_comm->state = SLOT_STATE_RECV_IGNORE;
            NI_comm->errorCode = ERR_RECV_REPLY_SUBFRAME_SIZE;
            gRfuStatic->recvErrorFlag |= bm_slot_flag;
        }
        else
        {
            NI_comm->errorCode = 0;
            *llFrameSize_p -= llFrameSize;
            NI_comm->now_p[0] = &NI_comm->dataType;
            NI_comm->remainSize = 7;
            NI_comm->ack = 1;
            NI_comm->payloadSize = 0;
            NI_comm->bmSlot = bm_slot_flag;
            NI_comm->state = SLOT_STATE_RECV_START;
            gRfuLinkStatus->recvSlotNIFlag |= bm_slot_flag;
        }
    }
}

static void rfu_STC_NI_initSlot_asRecvDataEntity(u8 bm_slot_id, struct NIComm *NI_comm)
{
    u8 bm_slot_flag, win_id;

    if (NI_comm->dataType == 1)
    {
        NI_comm->now_p[0] = (void *)&gRfuLinkStatus->partner[bm_slot_id].serialNo;
    }
    else
    {
        if (NI_comm->dataSize > gRfuSlotStatusNI[bm_slot_id]->recvBufferSize)
        {
            bm_slot_flag = 1 << bm_slot_id;
            gRfuStatic->recvErrorFlag |= bm_slot_flag;
            gRfuLinkStatus->recvSlotNIFlag &= ~bm_slot_flag;
            NI_comm->errorCode = ERR_RECV_BUFF_OVER;
            NI_comm->state = SLOT_STATE_RECV_FAILED;
            rfu_STC_releaseFrame(bm_slot_id, 1, NI_comm);
            return;
        }
        NI_comm->now_p[0] = gRfuSlotStatusNI[bm_slot_id]->recvBuffer;
    }
    for (win_id = 0; win_id < WINDOW_COUNT; ++win_id)
    {
        NI_comm->n[win_id] = 0;
        NI_comm->now_p[win_id] = &NI_comm->now_p[0][NI_comm->payloadSize * win_id];
    }
    NI_comm->remainSize = NI_comm->dataSize;
    NI_comm->state = SLOT_STATE_RECEIVING;
}

static void rfu_NI_checkCommFailCounter(void)
{
    u16 imeBak;
    u32 recvRenewalFlag;
    u8 bm_slot_flag, bm_slot_id;

    if (gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        recvRenewalFlag = gRfuStatic->recvRenewalFlag >> 4;
        for (bm_slot_id = 0; bm_slot_id < RFU_CHILD_MAX; ++bm_slot_id)
        {
            bm_slot_flag = 1 << bm_slot_id;
            if (gRfuLinkStatus->sendSlotNIFlag & bm_slot_flag
             && !(gRfuStatic->recvRenewalFlag & bm_slot_flag))
                ++gRfuSlotStatusNI[bm_slot_id]->send.failCounter;
            if (gRfuLinkStatus->recvSlotNIFlag & bm_slot_flag
             && !(recvRenewalFlag & bm_slot_flag))
                ++gRfuSlotStatusNI[bm_slot_id]->recv.failCounter;
        }
        gRfuStatic->recvRenewalFlag = 0;
        REG_IME = imeBak;
    }
}

void rfu_REQ_noise(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_TestModeREQ(1, 0);
}
