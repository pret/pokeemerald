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

void rfu_enableREQCallback(bool8 enable);
void rfu_STC_REQ_callback(u8 reqCommand, u16 reqResult);
void rfu_constructSendLLFrame(void);
void rfu_NI_checkCommFailCounter(void);

static void rfu_CB_defaultCallback(u8 reqCommand, u16 reqResult);
static void rfu_CB_reset(u8 reqCommand, u16 reqResult);
static void rfu_CB_configGameData(u8 reqCommand, u16 reqResult);
static void rfu_CB_stopMode(u8 reqCommand, u16 reqResult);
static void rfu_CB_startSearchChild(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollAndEndSearchChild(u8 reqCommand, u16 reqResult);
static void rfu_CB_startSearchParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollSearchParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_pollConnectParent(u8 reqCommand, u16 reqResult);
static void rfu_CB_disconnect(u8 reqCommand, u16 reqResult);
static void rfu_CB_CHILD_pollConnectRecovery(u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData(UNUSED u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData2(UNUSED u8 reqCommand, u16 reqResult);
static void rfu_CB_sendData3(u8 reqCommand, u16 reqResult);
static void rfu_CB_recvData(u8 reqCommand, u16 reqResult);
static void rfu_STC_clearAPIVariables(void);
static void rfu_STC_readChildList(void);
static void rfu_STC_readParentCandidateList(void);
static void rfu_STC_removeLinkData(u8, u8);
static void rfu_STC_fastCopy(const u8 **, u8 **, u32);
static void rfu_STC_clearLinkStatus(u8);
static u16 rfu_STC_setSendData_org(u8, u8, u8, const void *, u32);
static u16 rfu_STC_NI_constructLLSF(u8, u8 **, struct NIComm *);
static u16 rfu_STC_UNI_constructLLSF(u8, u8 **);
static void rfu_STC_PARENT_analyzeRecvPacket(void);
static void rfu_STC_CHILD_analyzeRecvPacket(void);
static u16 rfu_STC_analyzeLLSF(u8, u8 *, u16);
static void rfu_STC_UNI_receive(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Receiver(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Sender(u8, u8, const struct RfuLocalStruct *, UNUSED const u8 *);
static void rfu_STC_NI_initSlot_asRecvDataEntity(u8, struct NIComm *);
static void rfu_STC_NI_initSlot_asRecvControllData(u8, struct NIComm *);

COMMON_DATA struct RfuSlotStatusUNI *gRfuSlotStatusUNI[RFU_CHILD_MAX] = {0};
COMMON_DATA struct RfuSlotStatusNI *gRfuSlotStatusNI[RFU_CHILD_MAX] = {0};
COMMON_DATA struct RfuLinkStatus *gRfuLinkStatus = NULL;
COMMON_DATA struct RfuStatic *gRfuStatic = NULL;
COMMON_DATA struct RfuFixed *gRfuFixed = NULL;

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

u16 rfu_initializeAPI(u32 *APIBuffer, u16 buffByteSize, IntrFunc *sioIntrTable_p, bool8 copyInterruptToRam)
{
    u16 i;
    u16 *src;
    u16 *dst;
    u16 buffByteSizeMax;

    // is in EWRAM?
    if (((uintptr_t)APIBuffer & 0xF000000) == EWRAM_START && copyInterruptToRam)
        return ERR_RFU_API_BUFF_ADR;
    // is not 4-byte aligned?
    if ((u32)APIBuffer & 3)
        return ERR_RFU_API_BUFF_ADR;
    if (copyInterruptToRam)
    {
        // An assert/debug print may have existed before, ie
        // printf("%s %u < %u", "somefile.c:12345", buffByteSize, num)
        // to push this into size?
        buffByteSizeMax = RFU_API_BUFF_SIZE_RAM;
        if (buffByteSize < buffByteSizeMax)
            return ERR_RFU_API_BUFF_SIZE;
    }
    else
    {
        buffByteSizeMax = RFU_API_BUFF_SIZE_ROM; // same issue as above
        if (buffByteSize < buffByteSizeMax)
            return ERR_RFU_API_BUFF_SIZE;
    }

    do
    {
        // The API buffer holds these structures back to back.
        gRfuLinkStatus = (struct RfuLinkStatus *)APIBuffer;
        gRfuStatic = (struct RfuStatic *)&gRfuLinkStatus[1];
        gRfuFixed = (struct RfuFixed *)&gRfuStatic[1];
        gRfuSlotStatusNI[0] = (struct RfuSlotStatusNI *)&gRfuFixed[1];
        gRfuSlotStatusUNI[0] = (struct RfuSlotStatusUNI *)&gRfuSlotStatusNI[0][RFU_CHILD_MAX];
        for (i = 1; i < RFU_CHILD_MAX; ++i)
        {
            gRfuSlotStatusNI[i] = &gRfuSlotStatusNI[i - 1][1];
            gRfuSlotStatusUNI[i] = &gRfuSlotStatusUNI[i - 1][1];
        }
        // remaining space in API buffer is used for `struct RfuIntrStruct`.
        gRfuFixed->STWIBuffer = (u32 *)&gRfuSlotStatusUNI[3][1];
        STWI_init_all((struct RfuIntrStruct *)gRfuFixed->STWIBuffer, sioIntrTable_p, copyInterruptToRam);
        rfu_STC_clearAPIVariables();
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            gRfuSlotStatusNI[i]->recvBuffer = NULL;
            gRfuSlotStatusNI[i]->recvBufferSize = 0;
            gRfuSlotStatusUNI[i]->recvBuffer = NULL;
            gRfuSlotStatusUNI[i]->recvBufferSize = 0;
        }

        // rfu_REQ_changeMasterSlave is the function next to rfu_STC_fastCopy
        src = (u16 *)((uintptr_t)&rfu_STC_fastCopy & ~1);
        dst = gRfuFixed->fastCopyBuffer;
#if LIBRFU_VERSION < 1026
        buffByteSizeMax = ((uintptr_t)rfu_REQ_changeMasterSlave - (uintptr_t)rfu_STC_fastCopy) / sizeof(u16);
#else
        buffByteSizeMax = sizeof(gRfuFixed->fastCopyBuffer) / sizeof(u16);
#endif
        while (buffByteSizeMax-- != 0)
            *dst++ = *src++;
        gRfuFixed->fastCopyPtr = (void *)gRfuFixed->fastCopyBuffer + 1;
    } while (0);
    return 0;
}

static void rfu_STC_clearAPIVariables(void)
{
    u8 flags;
    u8 i;
    u16 IMEBackup;

    IMEBackup = REG_IME;
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

void rfu_setMSCCallback(void (*callback)(u16 REQ_commandID))
{
    STWI_set_Callback_S(callback);
}

void rfu_setREQCallback(void (*callback)(u16 REQ_commandID, u16 REQ_result))
{
    bool8 enable;

    gRfuFixed->reqCallback = callback;
    enable = callback != NULL;
    rfu_enableREQCallback(enable);
}

void rfu_enableREQCallback(bool8 enable)
{
    if (enable)
        gRfuStatic->flags |= 8;
    else
        gRfuStatic->flags &= 0xF7;
}

void rfu_STC_REQ_callback(u8 reqCommand, u16 reqResult)
{
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    gRfuStatic->reqResult = reqResult;
    if (gRfuStatic->flags & 8)
        gRfuFixed->reqCallback(reqCommand, reqResult);
}

static void rfu_CB_defaultCallback(u8 reqCommand, u16 reqResult)
{
    u8 i;
    u8 bmSlotFlags;

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
    if (((u8 *)gRfuFixed->STWIBuffer)[0] != 0x93)
        return ERR_REQ_CMD_ID;
    if (STWI_poll_CommandEnd() == 0)
        *rfuState = ((u8 *)gRfuFixed->STWIBuffer)[7];
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
    u8 *s1;
    u8 *s2;
    u8 i;
    u16 checksum;
    u16 *mb_buff_iwram_p;

    // if (strcmp(str1, str2) != 0) return 1;
    s1 = (u8 *)str_checkMbootLL;
    s2 = (u8 *)(IWRAM_START + 0xF0);
    while (*s1 != '\0')
        if (*s1++ != *s2++)
            return 1;
    mb_buff_iwram_p = (u16 *)IWRAM_START;

    // The size of struct RfuLinkStatus is 180
    checksum = 0;
    for (i = 0; i < 180/2; ++i)
        checksum += *mb_buff_iwram_p++;
    if (checksum != *(u16 *)(IWRAM_START + 0xFA))
        return 1;
    CpuCopy16((u16 *)IWRAM_START, gRfuLinkStatus, sizeof(struct RfuLinkStatus));
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
    u16 imeBak;

    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SystemConfigREQ((availSlotFlag & AVAIL_SLOT1) | 0x3C, maxMFrame, mcTimer);
    if (mcTimer == 0)
    {
        gRfuStatic->linkEmergencyLimit = 1;
    }
    else
    {
        imeBak = REG_IME;
        REG_IME = 0;
        gRfuStatic->linkEmergencyLimit = Div(600, mcTimer);
        REG_IME = imeBak;
    }
}

void rfu_REQ_configGameData(u8 mbootFlag, u16 serialNo, const u8 *gname, const u8 *uname)
{
    u8 i;
    u8 packet[16];
    u8 check_sum;
    const u8 *unameBackup;
    const u8 *gnameBackup;

    gnameBackup = gname;
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
    u8 i;
    u8 *buffer;

    if (reqResult == 0)
    {
        buffer = &((u8 *)gSTWIStatus->txPacket)[4];
        gRfuLinkStatus->my.serialNo = *buffer++;
        gRfuLinkStatus->my.serialNo |= *buffer++ << 8;
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
            gRfuLinkStatus->my.gname[i] = *buffer++;
        ++buffer;
        for (i = 0; i < RFU_USER_NAME_LENGTH; ++i)
            gRfuLinkStatus->my.uname[i] = *buffer++;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

void rfu_REQ_startSearchChild(void)
{
    u16 i;
    u16 result;

#if LIBRFU_VERSION >= 1026
    for (i = 0; i < RFU_CHILD_MAX; i++)
        gRfuStatic->lsFixedCount[i] = 0;
#endif
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_SystemStatusREQ();
    result = STWI_poll_CommandEnd();
    if (result == 0)
    {
        if (((u8 *)gRfuFixed->STWIBuffer)[7] == 0)
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
                gRfuLinkStatus->my.id = *(RfuPacketHalfword *)&gRfuFixed->STWIBuffer[1];
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
    u8 *data_p;
    u8 numSlots;
    u8 bm_slot_id;
    u8 i;
#if LIBRFU_VERSION < 1026
    u32 stwiParam;
    u8 true_slots[RFU_CHILD_MAX];
#endif

    numSlots = ((u8 *)gRfuFixed->STWIBuffer)[1];

#if LIBRFU_VERSION < 1026
    if (numSlots != 0)
    {
        stwiParam = gRfuFixed->STWIBuffer[1];
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_LinkStatusREQ();
        if (STWI_poll_CommandEnd() == 0)
        {
            data_p = &((u8 *)gRfuFixed->STWIBuffer)[4];
            for (i = 0; i < RFU_CHILD_MAX; ++i)
                true_slots[i] = *data_p++;
        }
        gRfuFixed->STWIBuffer[1] = stwiParam;
    }
#endif
    for (data_p = &((u8 *)gRfuFixed->STWIBuffer)[4];
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
                gRfuLinkStatus->partner[bm_slot_id].id = *(RfuPacketHalfword *)data_p;
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
            gRfuLinkStatus->partner[bm_slot_id].id = *(RfuPacketHalfword *)data_p;
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
    u8 j;
    u8 i;
    u8 numSlots;
    u8 my_check_sum;
    u8 check_sum;
    u8 *packet_p;
    u8 *uname_p;
    struct RfuTgtData *target;
    u16 id;
    u32 name;

    CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
    packet_p = &((u8 *)gRfuFixed->STWIBuffer)[0];
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
            target->id = *(RfuPacketHalfword *)packet_p;
            packet_p += 2;
            target->slot = *packet_p;
            packet_p += 2;
            target->serialNo = *(RfuPacketHalfword *)packet_p & 0x7FFF;
            if (*(RfuPacketHalfword *)packet_p & 0x8000)
                target->mbootFlag = 1;
            else
                target->mbootFlag = 0;
            packet_p += 2;
            for (j = 0; j < RFU_GAME_NAME_LENGTH; ++j)
                target->gname[j] = *packet_p++;
            ++packet_p;
            for (j = 0; j < RFU_USER_NAME_LENGTH; ++j)
                target->uname[j] = *packet_p++;
            ++gRfuLinkStatus->findParentCount;
        }
    }
}

void rfu_REQ_startConnectParent(u16 pid)
{
    u8 i;
    u16 result = 0;

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
    u8 i;
    u8 bm_slot_flag;
    u8 slot;
    u8 status;
    u8 *recv;
    u16 cid;
    struct RfuTgtData target_local;
    struct RfuTgtData *target_p;

    if (reqResult == 0)
    {
        recv = (u8 *)gRfuFixed->STWIBuffer;
        cid = *(RfuPacketHalfword *)&recv[4];
        slot = recv[6];
        status = recv[7];
        if (status == 0)
        {
            bm_slot_flag = 1 << slot;
            if (!(bm_slot_flag & gRfuLinkStatus->connSlotFlag))
            {
                gRfuLinkStatus->connSlotFlag |= bm_slot_flag;
                gRfuLinkStatus->linkLossSlotFlag &= ~bm_slot_flag;
                gRfuLinkStatus->my.id = cid;
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

    *status = CP_STATUS_UNKNOWN;
    packet_p = (u8 *)gRfuFixed->STWIBuffer;
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
    u8 *recv;

    STWI_set_Callback_M(rfu_CB_pollConnectParent);
    STWI_send_CP_EndREQ();
    recv = (u8 *)gRfuFixed->STWIBuffer;
    if (recv[6] < RFU_CHILD_MAX)
        gRfuStatic->linkEmergencyFlag[recv[6]] = 0;
}

u16 rfu_syncVBlank(void)
{
    u8 i;
    u8 masterSlave;
    u8 bmSlotFlag;

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
    u8 i;
    u8 *packet_p;
    u8 mask;
    u8 watchLinkState = 0;
    u8 reqResult = 0;
    u8 rfuState;
    u8 x;
    u8 disconnectSlots;
    u8 slotIndex;
    u16 childId;
    u32 savedPacket[2];

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
        watchLinkState = 1;
    }
    if ((u8)reqCommandId == ID_DISCONNECTED_AND_CHANGE_REQ)
    {
        packet_p = &((u8 *)gRfuFixed->STWIBuffer)[4];
        *bmLinkLossSlot = *packet_p++;
        *linkLossReason = *packet_p;
        if (*linkLossReason == REASON_LINK_LOSS)
            *bmLinkLossSlot = gRfuLinkStatus->connSlotFlag;
        watchLinkState = 2;
    }
    else
    {
        if (reqCommandId == 0x0136)
        {
            mask = ((u8 *)gRfuFixed->STWIBuffer)[5];
            *bmLinkLossSlot = (mask ^ gRfuLinkStatus->connSlotFlag) & gRfuLinkStatus->connSlotFlag;
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
        if (watchLinkState == 0)
            return 0;
    }
    savedPacket[0] = gRfuFixed->STWIBuffer[0];
    savedPacket[1] = gRfuFixed->STWIBuffer[1];
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_LinkStatusREQ();
    reqResult = STWI_poll_CommandEnd();
    if (reqResult == 0)
    {
        packet_p = &((u8 *)gRfuFixed->STWIBuffer)[4];
        for (i = 0; i < RFU_CHILD_MAX; ++i)
            gRfuLinkStatus->strength[i] = *packet_p++;
    }
    else
    {
        rfu_STC_REQ_callback(ID_LINK_STATUS_REQ, reqResult);
        return reqResult;
    }
    disconnectSlots = 0;
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
    #if LIBRFU_VERSION >= 1026
        if (gRfuStatic->lsFixedCount[i] != 0)
        {
            gRfuStatic->lsFixedCount[i] -= 4;
            if (gRfuLinkStatus->strength[i] <= 15)
                gRfuLinkStatus->strength[i] = 16;
        }
    #endif
        mask = 1 << i;
        if (reqResult == 0)
        {
            if (watchLinkState == 1 && (gRfuLinkStatus->connSlotFlag & mask))
            {
                if (gRfuLinkStatus->strength[i] == 0)
                {
                    if (gRfuLinkStatus->parentChild == MODE_PARENT)
                    {
                        ++gRfuStatic->linkEmergencyFlag[i];
                        if (gRfuStatic->linkEmergencyFlag[i] > 3)
                        {
                            *bmLinkLossSlot |= mask;
                            *linkLossReason = REASON_LINK_LOSS;
                        }
                    }
                    else
                    {
                        STWI_send_SystemStatusREQ();
                        if (STWI_poll_CommandEnd() == 0)
                        {
                            rfuState = ((u8 *)gRfuFixed->STWIBuffer)[7];
                            if (rfuState == 0)
                            {
                                *bmLinkLossSlot |= mask;
                                *linkLossReason = REASON_LINK_LOSS;
                            }
                            else
                            {
                                if (++gRfuStatic->linkEmergencyFlag[i] > gRfuStatic->linkEmergencyLimit)
                                {
                                    gRfuStatic->linkEmergencyFlag[i] = 0;
                                    STWI_send_DisconnectREQ(gRfuLinkStatus->connSlotFlag);
                                    STWI_poll_CommandEnd();
                                    *bmLinkLossSlot |= mask;
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
                if (mask & gRfuLinkStatus->linkLossSlotFlag)
                {
                    if (gRfuLinkStatus->strength[i] > 10)
                    {
                        *parentBmLinkRecoverySlot |= mask;
                        gRfuLinkStatus->connSlotFlag |= mask;
                        gRfuLinkStatus->linkLossSlotFlag &= ~mask;
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
                    if (!((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & mask))
                    {
                        STWI_send_SlotStatusREQ();
                        STWI_poll_CommandEnd();
                        packet_p = (u8 *)gRfuFixed->STWIBuffer;
                        x = packet_p[1] - 1;
                        packet_p += 8;
                        while (x != 0)
                        {
                            childId = *(RfuPacketHalfword *)packet_p;
                            slotIndex = packet_p[2];
                            if (slotIndex == i && childId == gRfuStatic->cidBak[i])
                            {
                                disconnectSlots |= 1 << i;
                                break;
                            }
                            packet_p += 4;
                            x--;
                        }
                    }
                }
            }
        }
        if (mask & (gRfuLinkStatus->connSlotFlag & *bmLinkLossSlot))
            rfu_STC_removeLinkData(i, 0);
    }
    if (disconnectSlots != 0)
    {
        STWI_send_DisconnectREQ(disconnectSlots);
        STWI_poll_CommandEnd();
    }
    gRfuFixed->STWIBuffer[0] = savedPacket[0];
    gRfuFixed->STWIBuffer[1] = savedPacket[1];
    return 0;
}

static void rfu_STC_removeLinkData(u8 bmConnectedPartnerId, u8 bmDisconnect)
{
    u8 mask;

    mask = 1 << bmConnectedPartnerId;
#if LIBRFU_VERSION >= 1026
    gRfuStatic->lsFixedCount[bmConnectedPartnerId] = 0;
#endif
    if ((gRfuLinkStatus->connSlotFlag & mask) && gRfuLinkStatus->connCount != 0)
        gRfuLinkStatus->connCount--;
    gRfuLinkStatus->connSlotFlag &= ~mask;
    gRfuLinkStatus->linkLossSlotFlag |= mask;
    if (gRfuLinkStatus->parentChild == MODE_CHILD && gRfuLinkStatus->connSlotFlag == 0)
        gRfuLinkStatus->parentChild = MODE_NEUTRAL;
    if (bmDisconnect)
    {
        CpuFill16(0, &gRfuLinkStatus->partner[bmConnectedPartnerId], sizeof(struct RfuTgtData));
        gRfuLinkStatus->linkLossSlotFlag &= ~mask;
        gRfuLinkStatus->getNameFlag &= ~mask;
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
                rfu_CB_disconnect(ID_DISCONNECT_REQ, 0);
        }
        else
        {
            if (gRfuStatic->SCStartFlag)
            {
                STWI_set_Callback_M(rfu_CB_defaultCallback);
                STWI_send_SC_EndREQ();
                result = STWI_poll_CommandEnd();
                if (result != 0)
                {
                    rfu_STC_REQ_callback(ID_SC_END_REQ, result);
                    return;
                }
            }
            STWI_set_Callback_M(rfu_CB_disconnect);
            STWI_send_DisconnectREQ(bmDisconnectSlot);
        }
    }
}

static void rfu_CB_disconnect(u8 reqCommand, u16 reqResult)
{
    u8 i;
    u8 mask;

    if (reqResult == 3 && gRfuLinkStatus->parentChild == MODE_CHILD)
    {
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_SystemStatusREQ();
        if (STWI_poll_CommandEnd() == 0 && ((u8 *)gRfuFixed->STWIBuffer)[7] == 0)
            reqResult = 0;
    }
    gRfuStatic->recoveryBmSlot &= gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
    ((u8 *)gRfuFixed->STWIBuffer)[8] = gRfuStatic->recoveryBmSlot;
    if (reqResult == 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            mask = 1 << i;
            if (mask & gRfuStatic->recoveryBmSlot)
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
    u8 i;
    u8 mask;

    if (reqResult == 0 && ((u8 *)gRfuFixed->STWIBuffer)[4] == 0 && gRfuStatic->recoveryBmSlot)
    {
        gRfuLinkStatus->parentChild = MODE_CHILD;
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            mask = 1 << i;
            if (gRfuLinkStatus->linkLossSlotFlag & (gRfuStatic->recoveryBmSlot & mask))
            {
                gRfuLinkStatus->connSlotFlag |= mask;
                gRfuLinkStatus->linkLossSlotFlag &= ~mask;
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
    u8 *recv;

    *status = RC_STATUS_UNKNOWN;
    recv = (u8 *)gRfuFixed->STWIBuffer;
    if (recv[0] == 0xB3 || recv[0] == 0xB4)
    {
        *status = recv[4];
        return 0;
    }
    return ERR_REQ_CMD_ID;
}

void rfu_REQ_CHILD_endConnectRecovery(void)
{
    STWI_set_Callback_M(rfu_CB_CHILD_pollConnectRecovery);
    STWI_send_CPR_EndREQ();
}

static void rfu_STC_fastCopy(const u8 **src_p, u8 **dst_p, u32 size)
{
    const u8 *src;
    u8 *dst;

    src = *src_p;
    dst = *dst_p;
    while (size--)
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
    bool8 masterSlave;

    masterSlave = STWI_read_status(1);

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
    u16 IMEBackup;

    IMEBackup = REG_IME;
    REG_IME = 0;
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
        CpuFill16(0, gRfuSlotStatusNI[i], 2 * sizeof(struct NIComm));
        CpuFill16(0, gRfuSlotStatusUNI[i], sizeof(struct UNISend) + sizeof(struct UNIRecv));
        gRfuLinkStatus->remainLLFrameSizeChild[i] = LLF_C_SIZE;
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
        gRfuLinkStatus->remainLLFrameSizeParent += LLSF_P_HEADER_SIZE;
    }
    else
    {
        if (send_recv == 0)
            gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id] += NI_comm->payloadSize;
        gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id] += LLSF_C_HEADER_SIZE;
    }
}

u16 rfu_clearSlot(u8 connTypeFlag, u8 slotStatusIndex)
{
    u16 i;
    u16 x;
    u16 imeBak;
    struct NIComm *niComm;
    struct UNISend *uniSend;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    if (!(connTypeFlag & (TYPE_UNI_SEND | TYPE_UNI_RECV | TYPE_NI_SEND | TYPE_NI_RECV)))
        return ERR_COMM_TYPE;
    imeBak = REG_IME;
    REG_IME = 0;
    if (connTypeFlag & (TYPE_NI_SEND | TYPE_NI_RECV))
    {
        for (x = 0; x < 2; ++x)
        {
            niComm = NULL;
            if (x == 0)
            {
                if (connTypeFlag & TYPE_NI_SEND)
                {
                    niComm = &gRfuSlotStatusNI[slotStatusIndex]->send;
                    gRfuLinkStatus->sendSlotNIFlag &= ~niComm->bmSlotOrg;
                }
            }
            else
            {
                if (connTypeFlag & TYPE_NI_RECV)
                {
                    niComm = &gRfuSlotStatusNI[slotStatusIndex]->recv;
                    gRfuLinkStatus->recvSlotNIFlag &= ~(1 << slotStatusIndex);
                }
            }
            if (niComm != NULL)
            {
                if (niComm->state & SLOT_BUSY_FLAG)
                {
                    rfu_STC_releaseFrame(slotStatusIndex, x, niComm);
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                        if ((niComm->bmSlotOrg >> i) & 1)
                            niComm->failCounter = 0;
                }
                CpuFill16(0, niComm, sizeof(struct NIComm));
            }
        }
    }
    if (connTypeFlag & TYPE_UNI_SEND)
    {
        uniSend = &gRfuSlotStatusUNI[slotStatusIndex]->send;
        if (uniSend->state & SLOT_BUSY_FLAG)
        {
            if (!(gRfuStatic->flags & 0x80))
                gRfuLinkStatus->remainLLFrameSizeParent += LLSF_P_HEADER_SIZE + (u8)uniSend->payloadSize;
            else
                gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex] += LLSF_C_HEADER_SIZE + (u8)uniSend->payloadSize;
            gRfuLinkStatus->sendSlotUNIFlag &= ~uniSend->bmSlot;
        }
        CpuFill16(0, uniSend, sizeof(struct UNISend));
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
        return 0;
    }
    else if (connType & TYPE_UNI)
    {
        gRfuSlotStatusUNI[slotNo]->recvBuffer = buffer;
        gRfuSlotStatusUNI[slotNo]->recvBufferSize = buffSize;
        return 0;
    }

    return ERR_COMM_TYPE;
}

u16 rfu_NI_setSendData(u8 bmSendSlot, u8 subFrameSize, const void *src, u32 size)
{
    return rfu_STC_setSendData_org(TYPE_NI, bmSendSlot, subFrameSize, src, size);
}

u16 rfu_UNI_setSendData(u8 bmSendSlot, const void *src, u8 size)
{
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        size += LLSF_P_HEADER_SIZE;
    else
        size += LLSF_C_HEADER_SIZE;

    return rfu_STC_setSendData_org(TYPE_UNI, bmSendSlot, size, src, 0);
}

u16 rfu_NI_CHILD_setSendGameName(u8 slotNo, u8 subFrameSize)
{
    return rfu_STC_setSendData_org(64, 1 << slotNo, subFrameSize, &gRfuLinkStatus->my.serialNo, 26);
}

static u16 rfu_STC_setSendData_org(u8 ni_or_uni, u8 bmSendSlot, u8 subFrameSize, const void *src, u32 dataSize)
{
    u8 i;
    u8 slotIndex;
    u8 headerSize;
#ifdef UBFIX
    u8 *remainingFrameSize = NULL;
#else
    u8 *remainingFrameSize;
#endif
    u16 imeBak;
    u16 result;
    struct NIComm *niSend;
    struct UNISend *uniSend;

    if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
        return ERR_MODE_NOT_CONNECTED;
    if (!(bmSendSlot & 0xF))
        return ERR_SLOT_NO;
    if (((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & bmSendSlot) != bmSendSlot)
        return ERR_SLOT_NOT_CONNECTED;
    if (ni_or_uni & TYPE_UNI)
        result = gRfuLinkStatus->sendSlotUNIFlag;
    else
        result = gRfuLinkStatus->sendSlotNIFlag;
    if (result & bmSendSlot)
        return ERR_SLOT_BUSY;
    for (slotIndex = 0; slotIndex < RFU_CHILD_MAX; slotIndex++)
        if ((bmSendSlot >> slotIndex) & 1)
            break;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        remainingFrameSize = &gRfuLinkStatus->remainLLFrameSizeParent;
    else if (gRfuLinkStatus->parentChild == MODE_CHILD)
        remainingFrameSize = &gRfuLinkStatus->remainLLFrameSizeChild[slotIndex];
    headerSize = llsf_struct[gRfuLinkStatus->parentChild].frameSize;
#ifdef UBFIX
    if ((remainingFrameSize && subFrameSize > *remainingFrameSize) || subFrameSize <= headerSize)
#else
    if (subFrameSize > *remainingFrameSize || subFrameSize <= headerSize)
#endif
        return ERR_SUBFRAME_SIZE;
    imeBak = REG_IME;
    REG_IME = 0;
    if ((ni_or_uni & TYPE_NI) || ni_or_uni == 0x40)
    {
        niSend = &gRfuSlotStatusNI[slotIndex]->send;
        i = 0;
        niSend->errorCode = i;
        niSend->now_p[0] = &niSend->dataType;
        niSend->remainSize = 7;
        niSend->bmSlotOrg = bmSendSlot;
        niSend->bmSlot = bmSendSlot;
        niSend->payloadSize = subFrameSize - headerSize;
        if (ni_or_uni & TYPE_NI)
            niSend->dataType = 0;
        else
            niSend->dataType = 1;

        niSend->dataSize = dataSize;
        niSend->src = src;
        niSend->ack = 0;
        niSend->phase = 0;
        for (i = 0; i < WINDOW_COUNT; ++i)
        {
            niSend->recvAckFlag[i] = 0;
            niSend->n[i] = 1;
        }
        for (slotIndex = 0; slotIndex < RFU_CHILD_MAX; ++slotIndex)
        {
            do
            {
                if ((bmSendSlot >> slotIndex) & 1)
                    gRfuSlotStatusNI[slotIndex]->send.failCounter = 0;
            } while (0);
        }
        gRfuLinkStatus->sendSlotNIFlag |= bmSendSlot;
#ifdef UBFIX
        if (remainingFrameSize)
#endif
            *remainingFrameSize -= subFrameSize;
        niSend->state = SLOT_STATE_SEND_START;
    }
    else if (ni_or_uni & TYPE_UNI)
    {
        uniSend = &gRfuSlotStatusUNI[slotIndex]->send;
        uniSend->bmSlot = bmSendSlot;
        uniSend->src = src;
        uniSend->payloadSize = subFrameSize - headerSize;
#ifdef UBFIX
        if (remainingFrameSize)
#endif
            *remainingFrameSize -= subFrameSize;
        uniSend->state = SLOT_STATE_SEND_UNI;
        gRfuLinkStatus->sendSlotUNIFlag |= bmSendSlot;
    }
    REG_IME = imeBak;
    return 0;
}

u16 rfu_changeSendTarget(u8 connType, u8 slotStatusIndex, u8 bmNewTgtSlot)
{
    u8 changedSlots;
    u8 i;
    u8 sendingSlots;
    u16 imeBak;
    struct NIComm *sendp;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    if (connType == TYPE_NI)
    {
        sendp = &gRfuSlotStatusNI[slotStatusIndex]->send;
        if ((sendp->state & SLOT_BUSY_FLAG) && (sendp->state & SLOT_SEND_FLAG))
        {
            changedSlots = bmNewTgtSlot ^ sendp->bmSlot;
            if (!(changedSlots & bmNewTgtSlot))
            {
                if (changedSlots)
                {
                    imeBak = REG_IME;
                    REG_IME = 0;
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                    {
                        if ((changedSlots >> i) & 1)
                            gRfuSlotStatusNI[i]->send.failCounter = 0;
                    }
                    gRfuLinkStatus->sendSlotNIFlag &= ~changedSlots;
                    sendp->bmSlot = bmNewTgtSlot;
                    if (sendp->bmSlot == 0)
                    {
                        rfu_STC_releaseFrame(slotStatusIndex, 0, sendp);
                        sendp->state = SLOT_STATE_SEND_FAILED;
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
        if (connType == TYPE_UNI)
        {
            if (gRfuSlotStatusUNI[slotStatusIndex]->send.state != SLOT_STATE_SEND_UNI)
                return ERR_SLOT_NOT_SENDING;
            sendingSlots = 0;
            for (i = 0; i < RFU_CHILD_MAX; ++i)
                if (i != slotStatusIndex)
                    sendingSlots |= gRfuSlotStatusUNI[i]->send.bmSlot;
            if (bmNewTgtSlot & sendingSlots)
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
    u8 *frameSize;
    u8 remainFrame;
    u16 imeBak;
    struct UNISend *uniSend;

    if (slotStatusIndex >= RFU_CHILD_MAX)
        return ERR_SLOT_NO;
    uniSend = &gRfuSlotStatusUNI[slotStatusIndex]->send;
    if (uniSend->state != SLOT_STATE_SEND_UNI)
        return ERR_SLOT_NOT_SENDING;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        frameSize = &gRfuLinkStatus->remainLLFrameSizeParent;
        remainFrame = gRfuLinkStatus->remainLLFrameSizeParent + (u8)uniSend->payloadSize;
    }
    else
    {
        frameSize = &gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex];
        remainFrame = gRfuLinkStatus->remainLLFrameSizeChild[slotStatusIndex] + (u8)uniSend->payloadSize;
    }
    if (remainFrame < size)
        return ERR_SUBFRAME_SIZE;
    imeBak = REG_IME;
    REG_IME = 0;
    uniSend->src = src;
    *frameSize = remainFrame - size;
    uniSend->payloadSize = size;
    uniSend->dataReadyFlag = 1;
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

void rfu_constructSendLLFrame(void)
{
    u8 slotIndex;
    u8 *frame;
    u32 packetSize;
    u32 totalPacketSize;

    if (gRfuLinkStatus->parentChild != MODE_NEUTRAL
     && gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag)
    {
        gRfuLinkStatus->LLFReadyFlag = 0;
        totalPacketSize = 0;
        frame = (u8 *)&gRfuFixed->LLFBuffer[1];
        for (slotIndex = 0; slotIndex < RFU_CHILD_MAX; ++slotIndex)
        {
            packetSize = 0;
            if (gRfuSlotStatusNI[slotIndex]->send.state & SLOT_BUSY_FLAG)
                packetSize = rfu_STC_NI_constructLLSF(slotIndex, &frame, &gRfuSlotStatusNI[slotIndex]->send);
            if (gRfuSlotStatusNI[slotIndex]->recv.state & SLOT_BUSY_FLAG)
                packetSize += rfu_STC_NI_constructLLSF(slotIndex, &frame, &gRfuSlotStatusNI[slotIndex]->recv);
            if (gRfuSlotStatusUNI[slotIndex]->send.state == SLOT_STATE_SEND_UNI)
                packetSize += rfu_STC_UNI_constructLLSF(slotIndex, &frame);
            if (packetSize != 0)
            {
                if (gRfuLinkStatus->parentChild == MODE_PARENT)
                    totalPacketSize += packetSize;
                else
                    totalPacketSize |= packetSize << (5 * slotIndex + 8);
            }
        }
        if (totalPacketSize != 0)
        {
            while ((u32)frame & 3)
                *frame++ = 0;
            *gRfuFixed->LLFBuffer = totalPacketSize;
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
                totalPacketSize = frame - (u8 *)&gRfuFixed->LLFBuffer[1];
        }
        gRfuStatic->totalPacketSize = totalPacketSize;
    }
}

static u16 rfu_STC_NI_constructLLSF(u8 bm_slot_id, u8 **dest_pp, struct NIComm *NI_comm)
{
    const struct LLSFStruct *fs;
    const u8 *payload;
    u32 header;
    u8 *headerBytes;
    u8 i;
    u16 payloadSize;

    fs = &llsf_struct[gRfuLinkStatus->parentChild];

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
        payloadSize = 0;
    }
    else if (NI_comm->state == SLOT_STATE_SENDING)
    {
        if (NI_comm->now_p[NI_comm->phase] + NI_comm->payloadSize > (const u8 *)NI_comm->src + NI_comm->dataSize)
            payloadSize = (const u8 *)NI_comm->src + NI_comm->dataSize - NI_comm->now_p[NI_comm->phase];
        else
            payloadSize = NI_comm->payloadSize;
    }
    else
    {
        if (NI_comm->remainSize >= NI_comm->payloadSize)
            payloadSize = NI_comm->payloadSize;
        else
            payloadSize = NI_comm->remainSize;
    }
    header = (NI_comm->state & 0xF) << fs->slotStateShift
         | NI_comm->ack << fs->ackShift
         | NI_comm->phase << fs->phaseShift
         | NI_comm->n[NI_comm->phase] << fs->nShift
         | payloadSize;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        header |= NI_comm->bmSlot << 18;
    headerBytes = (u8 *)&header;
    for (i = 0; i < fs->frameSize; ++i)
        *(*dest_pp)++ = *headerBytes++;
    if (payloadSize != 0)
    {
        payload = NI_comm->now_p[NI_comm->phase];
        gRfuFixed->fastCopyPtr(&payload, dest_pp, payloadSize);
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
    return payloadSize + fs->frameSize;
}

static u16 rfu_STC_UNI_constructLLSF(u8 bm_slot_id, u8 **dest_p)
{
    const struct LLSFStruct *fs;
    struct UNISend *uniSend;
    u8 *headerBytes;
    u8 i;
    u32 header;
    const u8 *payload;

    uniSend = &gRfuSlotStatusUNI[bm_slot_id]->send;

    if (!uniSend->dataReadyFlag || !uniSend->bmSlot)
        return 0;
    fs = &llsf_struct[gRfuLinkStatus->parentChild];
    header = (uniSend->state & 0xF) << fs->slotStateShift
         | uniSend->payloadSize;
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        header |= uniSend->bmSlot << 18;
    headerBytes = (u8 *)&header;
    for (i = 0; i < fs->frameSize; ++i)
        *(*dest_p)++ = *headerBytes++;
    payload = uniSend->src;
    gRfuFixed->fastCopyPtr(&payload, dest_p, uniSend->payloadSize);
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
        gRfuLinkStatus->LLFReadyFlag = 16;
    else
        gRfuLinkStatus->LLFReadyFlag |= 16 << bm_slot_id;
    return fs->frameSize + uniSend->payloadSize;
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
    struct NIComm *NI_comm;

    if (reqResult == 0 && ((u8 *)gRfuFixed->STWIBuffer)[1])
    {
        gRfuStatic->NIEndRecvFlag = 0;
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
            rfu_STC_PARENT_analyzeRecvPacket();
        else
            rfu_STC_CHILD_analyzeRecvPacket();
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_LAST && !((gRfuStatic->NIEndRecvFlag >> i) & 1))
            {
                NI_comm = &gRfuSlotStatusNI[i]->recv;
                if (NI_comm->dataType == 1)
                    gRfuLinkStatus->getNameFlag |= 1 << i;
                rfu_STC_releaseFrame(i, 1, NI_comm);
                gRfuLinkStatus->recvSlotNIFlag &= ~NI_comm->bmSlot;
                NI_comm->state = SLOT_STATE_RECV_SUCCESS;
            }
        }
        if (gRfuStatic->recvErrorFlag)
            reqResult = gRfuStatic->recvErrorFlag | ERR_DATA_RECV;
    }
    rfu_STC_REQ_callback(reqCommand, reqResult);
}

static void rfu_STC_PARENT_analyzeRecvPacket(void)
{
    u8 i;
    u8 slotLengths[RFU_CHILD_MAX];
    u8 *recv;
    u8 subframeSize;
    u32 packedLengths;

    packedLengths = gRfuFixed->STWIBuffer[1] >> 8;
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
        slotLengths[i] = packedLengths & 0x1F;
        packedLengths >>= 5;
        if (slotLengths[i] == 0)
            gRfuStatic->NIEndRecvFlag |= 1 << i;
    }
    recv = &((u8 *)gRfuFixed->STWIBuffer)[8];
    for (i = 0; i < RFU_CHILD_MAX; ++i)
    {
        while (slotLengths[i])
        {
            subframeSize = rfu_STC_analyzeLLSF(i, recv, slotLengths[i]);
            recv += subframeSize;
            slotLengths[i] -= subframeSize;
            if (slotLengths[i] & 0x80)
                break;
        }
    }
}

static void rfu_STC_CHILD_analyzeRecvPacket(void)
{
    u8 *recv;
    u16 packetSize;
    u16 subframeSize;

    packetSize = *(RfuPacketHalfword *)&((u8 *)gRfuFixed->STWIBuffer)[4] & 0x7F;
    recv = &((u8 *)gRfuFixed->STWIBuffer)[8];
    if (packetSize == 0)
        gRfuStatic->NIEndRecvFlag = 15;
    do
    {
        if (packetSize == 0)
            break;
        subframeSize = rfu_STC_analyzeLLSF(0, recv, packetSize);
        recv += subframeSize;
        packetSize -= subframeSize;
    } while (!(packetSize & 0x8000));
}

static u16 rfu_STC_analyzeLLSF(u8 slot_id, u8 *src, u16 last_frame)
{
    const struct LLSFStruct *fs;
    struct RfuLocalStruct subframeHeader;
    u8 enabledSlots;
    u8 i;
    u16 subframeSize;
    u32 header;

    // Received header use the other side's header format.
    fs = &llsf_struct[~gRfuLinkStatus->parentChild & 1];
    if (last_frame < fs->frameSize)
        return last_frame;
    header = 0;
    for (i = 0; i < fs->frameSize; ++i)
        header |= *src++ << 8 * i;
    subframeHeader.recvFirst = (header >> fs->recvFirstShift) & fs->recvFirstMask;
    subframeHeader.connSlotFlag = (header >> fs->connSlotFlagShift) & fs->connSlotFlagMask;
    subframeHeader.slotState = (header >> fs->slotStateShift) & fs->slotStateMask;
    subframeHeader.ack = (header >> fs->ackShift) & fs->ackMask;
    subframeHeader.phase = (header >> fs->phaseShift) & fs->phaseMask;
    subframeHeader.n = (header >> fs->nShift) & fs->nMask;
    subframeHeader.frame = fs->framesMask & header;
    subframeSize = subframeHeader.frame + fs->frameSize;
    if (subframeHeader.recvFirst == 0)
    {
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
        {
            if ((gRfuLinkStatus->connSlotFlag >> slot_id) & 1)
            {
                if (subframeHeader.slotState == LCOM_UNI)
                {
                    rfu_STC_UNI_receive(slot_id, &subframeHeader, src);
                }
                else if (subframeHeader.ack == 0)
                {
                    rfu_STC_NI_receive_Receiver(slot_id, &subframeHeader, src);
                }
                else
                {
                    for (i = 0; i < RFU_CHILD_MAX; ++i)
                        if (((gRfuSlotStatusNI[i]->send.bmSlot >> slot_id) & 1)
                         && ((gRfuLinkStatus->sendSlotNIFlag >> slot_id) & 1))
                            break;
                    if (i < RFU_CHILD_MAX)
                        rfu_STC_NI_receive_Sender(i, slot_id, &subframeHeader, src);
                }
            }
        }
        else
        {
            enabledSlots = gRfuLinkStatus->connSlotFlag & subframeHeader.connSlotFlag;
            if (enabledSlots)
            {
                for (i = 0; i < RFU_CHILD_MAX; ++i)
                {
                    if ((enabledSlots >> i) & 1)
                    {
                        if (subframeHeader.slotState == LCOM_UNI)
                            rfu_STC_UNI_receive(i, &subframeHeader, src);
                        else if (subframeHeader.ack == 0)
                            rfu_STC_NI_receive_Receiver(i, &subframeHeader, src);
                        else if ((gRfuLinkStatus->sendSlotNIFlag >> i) & 1)
                            rfu_STC_NI_receive_Sender(i, i, &subframeHeader, src);
                    }
                }
            }
        }
    }
    return subframeSize;
}

static void rfu_STC_UNI_receive(u8 bm_slot_id, const struct RfuLocalStruct *subframeHeader, const u8 *src)
{
    struct UNIRecv *uniRecv;
    u8 *buffer;
    u16 length;

    uniRecv = &gRfuSlotStatusUNI[bm_slot_id]->recv;
    uniRecv->errorCode = 0;
    if (gRfuSlotStatusUNI[bm_slot_id]->recvBufferSize < subframeHeader->frame)
    {
        uniRecv->state = SLOT_STATE_RECV_IGNORE;
        uniRecv->errorCode = ERR_RECV_BUFF_OVER;
    }
    else if (uniRecv->dataBlockFlag && uniRecv->newDataFlag)
    {
        uniRecv->errorCode = ERR_RECV_UNK;
    }
    else
    {
        if (uniRecv->newDataFlag)
            uniRecv->errorCode = ERR_RECV_DATA_OVERWRITED;
        uniRecv->state = SLOT_STATE_RECEIVING;
        length = uniRecv->dataSize = subframeHeader->frame;
        buffer = gRfuSlotStatusUNI[bm_slot_id]->recvBuffer;
        gRfuFixed->fastCopyPtr(&src, &buffer, length);
        uniRecv->newDataFlag = 1;
        uniRecv->state = 0;
    }
    if (uniRecv->errorCode)
        gRfuStatic->recvErrorFlag |= 16 << bm_slot_id;
}

static void rfu_STC_NI_receive_Sender(u8 NI_slot, u8 bm_flag, const struct RfuLocalStruct *subframeHeader, const u8 *data_p)
{
    struct NIComm *NI_comm = &gRfuSlotStatusNI[NI_slot]->send;
    u16 state = NI_comm->state;
    u16 imeBak;
    u8 n = NI_comm->n[subframeHeader->phase];
    u8 i;

    if ((subframeHeader->slotState == LCOM_NI && state == SLOT_STATE_SENDING)
     || (subframeHeader->slotState == LCOM_NI_START && state == SLOT_STATE_SEND_START)
     || (subframeHeader->slotState == LCOM_NI_END && state == SLOT_STATE_SEND_LAST))
    {
        if (NI_comm->n[subframeHeader->phase] == subframeHeader->n)
            NI_comm->recvAckFlag[subframeHeader->phase] |= 1 << bm_flag;
    }
    if ((NI_comm->recvAckFlag[subframeHeader->phase] & NI_comm->bmSlot) == NI_comm->bmSlot)
    {
        NI_comm->n[subframeHeader->phase] = (NI_comm->n[subframeHeader->phase] + 1) & 3;
        NI_comm->recvAckFlag[subframeHeader->phase] = 0;
        if (NI_comm->state == SLOT_STATE_SEND_START || NI_comm->state == SLOT_STATE_SENDING)
        {
            if (NI_comm->state == SLOT_STATE_SEND_START)
                NI_comm->now_p[subframeHeader->phase] += NI_comm->payloadSize;
            else
                NI_comm->now_p[subframeHeader->phase] += NI_comm->payloadSize << 2;
            NI_comm->remainSize -= NI_comm->payloadSize;

            // remainSize is u32; bit 31 is set after underflow from -= payloadSize.
            if (NI_comm->remainSize == 0 || (NI_comm->remainSize & 0x80000000))
            {
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
            }
        }
        else if (NI_comm->state == SLOT_STATE_SEND_LAST)
        {
            NI_comm->state = SLOT_STATE_SEND_NULL;
        }
    }
    if (NI_comm->state != state
     || NI_comm->n[subframeHeader->phase] != n
     || (NI_comm->recvAckFlag[subframeHeader->phase] >> bm_flag) & 1)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        gRfuStatic->recvRenewalFlag |= 16 << bm_flag;
        gRfuSlotStatusNI[bm_flag]->send.failCounter = 0;
        REG_IME = imeBak;
    }
}

static void rfu_STC_NI_receive_Receiver(u8 bm_slot_id, const struct RfuLocalStruct *subframeHeader, const u8 *data_p)
{
    struct NIComm *recvSlot;
    u16 state;
    u16 imeBak;
    u8 n;
    bool8 checkSequence;

    checkSequence = FALSE;
    recvSlot = &gRfuSlotStatusNI[bm_slot_id]->recv;
    state = recvSlot->state;
    n = recvSlot->n[subframeHeader->phase];

    if (subframeHeader->slotState == LCOM_NI_END)
    {
        gRfuStatic->NIEndRecvFlag |= 1 << bm_slot_id;
        if (recvSlot->state == SLOT_STATE_RECEIVING)
        {
            recvSlot->phase = 0;
            recvSlot->n[0] = 0;
            recvSlot->state = SLOT_STATE_RECV_LAST;
        }
    }
    else if (subframeHeader->slotState == LCOM_NI)
    {
        if (state == SLOT_STATE_RECV_START && !recvSlot->remainSize)
            rfu_STC_NI_initSlot_asRecvDataEntity(bm_slot_id, recvSlot);
        if (recvSlot->state == SLOT_STATE_RECEIVING)
            checkSequence = TRUE;
    }
    else if (subframeHeader->slotState == LCOM_NI_START)
    {
        if (state == SLOT_STATE_RECV_START)
        {
            checkSequence = TRUE;
        }
        else
        {
            rfu_STC_NI_initSlot_asRecvControllData(bm_slot_id, recvSlot);
            if (recvSlot->state != SLOT_STATE_RECV_START)
                return;
            checkSequence = TRUE;
        }
    }
    if (checkSequence != 0)
    {
        if (subframeHeader->n == ((recvSlot->n[subframeHeader->phase] + 1) & 3))
        {
            gRfuFixed->fastCopyPtr(&data_p, (u8 **)&recvSlot->now_p[subframeHeader->phase], subframeHeader->frame);
            if (recvSlot->state == SLOT_STATE_RECEIVING)
                recvSlot->now_p[subframeHeader->phase] += 3 * recvSlot->payloadSize;
            recvSlot->remainSize -= subframeHeader->frame;
            recvSlot->n[subframeHeader->phase] = subframeHeader->n;
        }
    }
    if (recvSlot->errorCode == 0)
    {
        recvSlot->phase = subframeHeader->phase;
        if (recvSlot->state != state || recvSlot->n[subframeHeader->phase] != n || recvSlot->n[subframeHeader->phase] == subframeHeader->n)
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
    u8 headerSize;
    u8 *remainingFrameSize;
    u8 mask;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        headerSize = LLSF_P_HEADER_SIZE;
        remainingFrameSize = &gRfuLinkStatus->remainLLFrameSizeParent;
    }
    else
    {
        headerSize = LLSF_C_HEADER_SIZE;
        remainingFrameSize = &gRfuLinkStatus->remainLLFrameSizeChild[bm_slot_id];
    }
    mask = 1 << bm_slot_id;
    if (NI_comm->state == 0)
    {
        if (*remainingFrameSize < headerSize)
        {
            NI_comm->state = SLOT_STATE_RECV_IGNORE;
            NI_comm->errorCode = ERR_RECV_REPLY_SUBFRAME_SIZE;
            gRfuStatic->recvErrorFlag |= mask;
        }
        else
        {
            NI_comm->errorCode = 0;
            *remainingFrameSize -= headerSize;
            NI_comm->now_p[0] = &NI_comm->dataType;
            NI_comm->remainSize = 7;
            NI_comm->ack = 1;
            NI_comm->payloadSize = 0;
            NI_comm->bmSlot = mask;
            NI_comm->state = SLOT_STATE_RECV_START;
            gRfuLinkStatus->recvSlotNIFlag |= mask;
        }
    }
}

static void rfu_STC_NI_initSlot_asRecvDataEntity(u8 bm_slot_id, struct NIComm *NI_comm)
{
    u8 i;
    u8 mask;

    if (NI_comm->dataType == 1)
    {
        NI_comm->now_p[0] = (void *)&gRfuLinkStatus->partner[bm_slot_id].serialNo;
    }
    else
    {
        if (NI_comm->dataSize > gRfuSlotStatusNI[bm_slot_id]->recvBufferSize)
        {
            mask = 1 << bm_slot_id;
            gRfuStatic->recvErrorFlag |= mask;
            gRfuLinkStatus->recvSlotNIFlag &= ~mask;
            NI_comm->errorCode = ERR_RECV_BUFF_OVER;
            NI_comm->state = SLOT_STATE_RECV_FAILED;
            rfu_STC_releaseFrame(bm_slot_id, 1, NI_comm);
            return;
        }
        NI_comm->now_p[0] = gRfuSlotStatusNI[bm_slot_id]->recvBuffer;
    }
    for (i = 0; i < WINDOW_COUNT; ++i)
    {
        NI_comm->n[i] = 0;
        NI_comm->now_p[i] = &NI_comm->now_p[0][NI_comm->payloadSize * i];
    }
    NI_comm->remainSize = NI_comm->dataSize;
    NI_comm->state = SLOT_STATE_RECEIVING;
}

void rfu_NI_checkCommFailCounter(void)
{
    u8 i;
    u8 mask;
    u8 recvRenewalReplyFlags;
    u16 imeBak;

    if (gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        recvRenewalReplyFlags = gRfuStatic->recvRenewalFlag >> 4;
        for (i = 0; i < RFU_CHILD_MAX; ++i)
        {
            mask = 1 << i;
            if (gRfuLinkStatus->sendSlotNIFlag & mask
             && !(gRfuStatic->recvRenewalFlag & mask))
                ++gRfuSlotStatusNI[i]->send.failCounter;
            if (gRfuLinkStatus->recvSlotNIFlag & mask
             && !(recvRenewalReplyFlags & mask))
                ++gRfuSlotStatusNI[i]->recv.failCounter;
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
