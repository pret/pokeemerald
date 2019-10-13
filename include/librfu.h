#ifndef GUARD_LIBRFU_H
#define GUARD_LIBRFU_H

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
    RFU_CPR_START,
    RFU_CPR_POLLING,
    RFU_CPR_END,
    RFU_UNK35,
    RFU_UNK36,
    RFU_RESUME_RETRANSMIT_AND_CHANGE,
    RFU_UNK38,
    RFU_UNK39,
    RFU_UNK3A,
    RFU_UNK3B,
    RFU_UNK3C,
    RFU_STOP_MODE, // 3D
};

struct RfuPacket8
{
    u8 data[0x74];
};

struct RfuPacket32
{
    u32 command;
    u32 data[0x1C];
};

union RfuPacket
{
    struct RfuPacket32 rfuPacket32;
    struct RfuPacket8 rfuPacket8;
};

struct UnkLinkRfuStruct_02022B14Substruct
{
    u16 unk_00_0:4;
    u16 unk_00_4:1;
    u16 unk_00_5:1;
    u16 unk_00_6:1;
    u16 isChampion:1;
    u16 hasNationalDex:1;
    u16 gameClear:1; // never read, redundant with isChampion
    u16 unk_01_2:4;  // always 3?
    u16 unk_01_6:2;
    u8 playerTrainerId[2];
};

struct __attribute__((packed, aligned(2))) UnkLinkRfuStruct_02022B14
{
    struct UnkLinkRfuStruct_02022B14Substruct unk_00;
    u8 unk_04[4];
    u16 species:10;
    u16 type:6;
    u8 unk_0a_0:7;
    u8 unk_0a_7:1;
    u8 playerGender:1;
    u8 level:7;
    u8 unk_0c;
};

struct RfuStruct
{
    vs32 unk_0;
    u8 txParams;
    u8 unk_5;
    u8 activeCommand;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 timerSelect;
    u8 unk_b;
    int timerState;
    vu8 timerActive;
    u8 unk_11;
    vu16 unk_12;
    vu8 msMode;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    void (*callbackM)();
    void (*callbackS)();
    u32 callbackID;
    union RfuPacket *txPacket;
    union RfuPacket *rxPacket;
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

struct RfuUnk1
{
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 fill_4[14];
    u8 unk_12;
    u32 unk_14;
    u32 unk_18;
    struct RfuIntrStruct unk_1c;
};

struct RfuUnk2
{
    u16 unk_0;
    u16 unk_2;
    u8 fill_4[0x16];
    u8 unk_1a;
    u8 fill_1b[0x19];
    u16 unk_34;
    u16 unk_36;
    u8 fill_38[0x16];
    u8 unk_4e;
    u8 fill_4f[0x12];
    u8 unk_61;
    u8 fill_62[6];
    void *unk_68;
    void *unk_6c;
    u8 unk_70[0x70];
};

struct RfuUnk3
{
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0xD4];
    u32 unk_dc;
};

struct RfuUnk5Sub
{
    u16 unk_00;
    u8 unk_02;
    u16 unk_04;
    struct UnkLinkRfuStruct_02022B14 unk_06;
    u8 fill_13[1];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
};

struct RfuUnk5
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 filler_09[1];
    u8 unk_0a[4];
    u8 filler_0e[6];
    struct RfuUnk5Sub unk_14[4];
};

extern struct RfuStruct *gRfuState;

extern struct RfuUnk5 *gUnknown_03007890;
extern u32 *gUnknown_03007894;
extern struct RfuUnk3* gUnknown_03007898;
extern struct RfuUnk2* gUnknown_03007880[4];
extern struct RfuUnk1* gUnknown_03007870[4];
extern void* sub_82E53F4;
extern void rfu_STC_clearAPIVariables(void);

void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam);
void rfu_REQ_stopMode(void);
void rfu_waitREQComplete(void);
u32 rfu_REQBN_softReset_and_checkID(void);
void rfu_REQ_sendData(u8);
void rfu_setMSCCallback(void (*func)(u16));
void rfu_setREQCallback(void (*func)(u16, u16));
bool8 rfu_getMasterSlave(void);
void rfu_REQBN_watchLink(u16 a0, u8 *a1, u8 *a2, u8 *a3);
bool16 rfu_syncVBlank(void);
void rfu_REQ_reset(void);
void rfu_REQ_configSystem(u16, u8, u8);
void rfu_REQ_configGameData(u8, u16, struct UnkLinkRfuStruct_02022B14 *, u8 *);
void rfu_REQ_startSearchChild(void);
void rfu_REQ_pollSearchChild(void);
void rfu_REQ_endSearchChild(void);
void rfu_REQ_startSearchParent(void);
void rfu_REQ_pollSearchParent(void);
void rfu_REQ_endSearchParent(void);
void rfu_REQ_startConnectParent(u16);
void rfu_REQ_pollConnectParent(void);
void rfu_REQ_endConnectParent(void);
void rfu_REQ_CHILD_startConnectRecovery(u8);
void rfu_REQ_CHILD_pollConnectRecovery(void);
void rfu_REQ_CHILD_endConnectRecovery(void);
void rfu_REQ_changeMasterSlave(void);
void rfu_REQ_RFUStatus(void);
void rfu_getRFUStatus(u8 *status);
u8 *rfu_getSTWIRecvBuffer(void);
u8 rfu_NI_CHILD_setSendGameName(u8 a0, u8 a1);
void rfu_clearSlot(u8 a0, u8 a1);
void rfu_clearAllSlot(void);
bool16 rfu_CHILD_getConnectRecoveryStatus(u8 *status);
bool16 rfu_getConnectParentStatus(u8 *status, u8 *a1);
bool16 rfu_UNI_PARENT_getDRAC_ACK(u8 *a0);
void rfu_REQ_disconnect(u8 who);
void rfu_changeSendTarget(u8 a0, u8 who, u8 a2);
void rfu_NI_stopReceivingData(u8 who);
u16 rfu_initializeAPI(u32 *unk0, u16 unk1, IntrFunc *interrupt, bool8 copyInterruptToRam);
void rfu_setTimerInterrupt(u8 which, IntrFunc *intr);
void rfu_setRecvBuffer(u8 a0, u8 a1, void *a2, size_t a3);
bool16 rfu_UNI_setSendData(u8 flag, void *ptr, u8 size);
void rfu_REQ_recvData(void);
void rfu_UNI_readySendData(u8 a0);
void rfu_UNI_clearRecvNewDataFlag(u8 a0);
void rfu_REQ_PARENT_resumeRetransmitAndChange(void);
void rfu_NI_setSendData(u8, u8, const void *, u32);

#endif // GUARD_LIBRFU_H
