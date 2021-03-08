#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

#include "trainer_hill.h"

enum {
    EREADER_XFR_STATE_INIT = 0,
    EREADER_XFR_STATE_HANDSHAKE,
    EREADER_XFR_STATE_START,
    EREADER_XFR_STATE_TRANSFER,
    EREADER_XFR_STATE_TRANSFER_DONE,
    EREADER_XFR_STATE_CHECKSUM,
    EREADER_XFR_STATE_DONE
};

#define EREADER_XFER_EXE 1
#define EREADER_XFER_CHK 2
#define EREADER_XFER_SHIFT 0
#define EREADER_XFER_MASK  3

#define EREADER_CANCEL_TIMEOUT 1
#define EREADER_CANCEL_KEY     2
#define EREADER_CANCEL_MASK  0xC
#define EREADER_CANCEL_SHIFT 2

#define EREADER_CHECKSUM_OK  1
#define EREADER_CHECKSUM_ERR 2
#define EREADER_CHECKSUM_MASK  0x30
#define EREADER_CHECKSUM_SHIFT 4

struct EReaderTrainerHillTrainer
{
    u8 unk0;
    struct TrainerHillTrainer unk4;
    struct TrHillDisplay unk14C;
    u32 checksum;
}; // size=0x274

struct EReaderTrainerHillSet
{
    u8 count;
    u8 id;
    u16 dummy;
    u32 checksum;
    struct EReaderTrainerHillTrainer unk_8[6];
    u8 unk_ec0[40];
}; // size = 0xf00

bool8 EReader_IsReceivedDataValid(struct EReaderTrainerHillSet *buffer);
bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *arg0);
bool32 ReadTrainerHillAndValidate(void);
u16 EReaderHandleTransfer(u8, u32, const u32*, u32*);
void EReaderHelper_Timer3Callback(void);
void sub_81D3FAC(void);
void EReaderHelper_SaveRegsState(void);
void EReaderHelper_RestoreRegsState(void);
void EReaderHelper_ClearsSendRecvMgr(void);

#endif // GUARD_EREADER_HELPERS_H
