#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

#include "trainer_hill.h"

struct EReaderTrainerHillTrainer
{
    u8 trainerNum;
    struct TrainerHillTrainer trainer;
    struct TrHillDisplay display;
    u32 checksum;
}; // size=0x274

struct EReaderTrainerHillSet
{
    u8 numTrainers;
    u8 id;
    u16 dummy; // Only read in an assert.
    u32 checksum;
    struct EReaderTrainerHillTrainer trainers[6];
    u8 unk_ec0[40];
}; // size = 0xf00

bool8 ValidateTrainerHillData(struct EReaderTrainerHillSet *);
bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *);
bool32 ReadTrainerHillAndValidate(void);
int EReaderHandleTransfer(u8, size_t, const void *, void *);
void EReaderHelper_Timer3Callback(void);
void EReaderHelper_SerialCallback(void);
void EReaderHelper_SaveRegsState(void);
void EReaderHelper_RestoreRegsState(void);
void EReaderHelper_ClearSendRecvMgr(void);

#endif // GUARD_EREADER_HELPERS_H
