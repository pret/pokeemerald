#ifndef GUARD_LIBRFU_STWI_PRIVATE_H
#define GUARD_LIBRFU_STWI_PRIVATE_H

#include "librfu.h"

#define STWI_ACK_FLAG 0x80

enum timer_state
{
    NOT_USED = 0,
    WAIT50MS = 1,
    WAIT80MS = 2,
    WAIT100MS = 3,
    WAIT130MS = 4,
};

enum comm_state
{
    M_TxREQ = 0,
    M_RxACK_HEADER = 1,
    M_RxACK_CONTENTS = 2,
    M_RxACK_END = 3,
    M_COMPLETE = 4,
    S_RxREQ_HEADER = 5,
    S_RxREQ_CONTENTS = 6,
    S_TxACK = 7,
    S_TxACK_END = 8,
    S_COMPLETE = 9,
    ID_CHECK = 10,
};

struct RFU_MAY_ALIAS STWIStatus
{
    vs32 state;
    u8 reqLength;
    u8 reqNext;
    u8 reqActiveCommand;
    u8 ackLength;
    u8 ackNext;
    u8 ackActiveCommand;
    u8 timerSelect;
#if LIBRFU_VERSION >= 1026
    s32 timerState;
#else
    u32 timerState;
#endif
    vu8 timerActive;
    vu16 error;
    vu8 msMode;
    u8 recoveryCount;
    void (*callbackM)(u8, u16);
    void (*callbackS)(u16);
    void (*callbackID)(void);
    u32 *txPacket;
    u32 *rxPacket;
    vu8 sending;
};

#define STWI_PACKET_WORDS 29 // 1 command word + 28 parameter words

// Layout of the STWI region at the end of the API buffer. In the SDK this is
// a plain u32 array (RFU_FIXED.STWI_buf is a u32 *).
struct RFU_MAY_ALIAS RfuIntrStruct
{
    u32 rxPacketAlloc[STWI_PACKET_WORDS];
    u32 txPacketAlloc[STWI_PACKET_WORDS];
    u8 ALIGNED(2) block1[0x960]; // size of librfu_intr.s binary
    struct STWIStatus block2;
};

extern struct STWIStatus *gSTWIStatus;

// librfu_sio32id
u32 AgbRFU_checkID(u8 maxTries);

// librfu_intr
void IntrSIO32(void);

// librfu_stwi
void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam);
void STWI_set_MS_mode(u8 mode);
void STWI_init_Callback_M(void);
void STWI_init_Callback_S(void);
void STWI_set_Callback_M(void (*callbackM)(u8, u16));
void STWI_set_Callback_S(void (*callbackS)(u16));
void STWI_init_timer(IntrFunc *interrupt, u8 timerSelect);
void AgbRFU_SoftReset(void);
void STWI_set_Callback_ID(void (*func)(void));
u16 STWI_read_status(u8 index);
u16 STWI_poll_CommandEnd(void);
void STWI_send_DataRxREQ(void);
void STWI_send_MS_ChangeREQ(void);
void STWI_send_StopModeREQ(void);
void STWI_send_SystemStatusREQ(void);
void STWI_send_GameConfigREQ(const u8 *serial_gname, const u8 *uname);
void STWI_send_ResetREQ(void);
void STWI_send_LinkStatusREQ(void);
void STWI_send_VersionStatusREQ(void);
void STWI_send_SlotStatusREQ(void);
void STWI_send_ConfigStatusREQ(void);
void STWI_send_ResumeRetransmitAndChangeREQ(void);
void STWI_send_SystemConfigREQ(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer);
void STWI_send_SC_StartREQ(void);
void STWI_send_SC_PollingREQ(void);
void STWI_send_SC_EndREQ(void);
void STWI_send_SP_StartREQ(void);
void STWI_send_SP_PollingREQ(void);
void STWI_send_SP_EndREQ(void);
void STWI_send_CP_StartREQ(u16 pid);
void STWI_send_CP_PollingREQ(void);
void STWI_send_CP_EndREQ(void);
void STWI_send_DataTxREQ(const void *in, u8 size);
void STWI_send_DataTxAndChangeREQ(const void *in, u8 size);
void STWI_send_DataReadyAndChangeREQ(u8 bmSlot);
void STWI_send_DisconnectedAndChangeREQ(u8 slotStatus, u8 changeFlags);
void STWI_send_DisconnectREQ(u8 bmDisconnectSlot);
void STWI_send_TestModeREQ(u8 mode, u8 submode);
void STWI_send_CPR_StartREQ(u16 partnerId, u16 myId, u8 bmRecoverySlot);
void STWI_send_CPR_PollingREQ(void);
void STWI_send_CPR_EndREQ(void);

#endif // GUARD_LIBRFU_STWI_PRIVATE_H
