#ifndef GUARD_LIBRFU_LL_PRIVATE_H
#define GUARD_LIBRFU_LL_PRIVATE_H

#include "librfu.h"

struct RFU_MAY_ALIAS RfuFixed
{
    void (*reqCallback)(u16, u16);
    void (*fastCopyPtr)(const u8 **, u8 **, u32);
    u16 fastCopyBuffer[48];
    u32 LLFBuffer[29];
    u32 *STWIBuffer;
};

#define RFU_FLAG_CLOCK_SLAVE  0x02 // The AGB was the clock slave at the last rfu_syncVBlank
#define RFU_FLAG_WATCHDOG     0x04 // The clock slave watchdog timer is running
#define RFU_FLAG_REQ_CALLBACK 0x08 // Set by rfu_enableREQCallback
#define RFU_FLAG_CHILD        0x80 // Linked as a child, so the child frame sizes apply

#define RFU_WATCHDOG_FRAMES 360 // 6 seconds as the clock slave before a watchdog timer error

struct RFU_MAY_ALIAS RfuStatic
{
    u8 flags;
    u8 NIEndRecvFlag;
    u8 recvRenewalFlag;
    u8 commExistFlag;
    u8 recvErrorFlag;
    u8 recoveryBmSlot;
    u8 nowWatchInterval;
    u8 nullFrameCount;
    u8 emberCount;
    u8 SCStartFlag;
    u8 linkEmergencyFlag[RFU_CHILD_MAX];
    u8 lsFixedCount[RFU_CHILD_MAX];
    u16 cidBak[RFU_CHILD_MAX];
    u16 linkEmergencyLimit;
    u16 reqResult;
    u16 tryPid;
    u16 watchdogTimer;
    u32 totalPacketSize;
};

#endif // GUARD_LIBRFU_LL_PRIVATE_H
