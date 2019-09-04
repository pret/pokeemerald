#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

#include "trainer_hill.h"

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
int EReaderHandleTransfer(u8, u32, u32*, u32*);
void sub_81D3F9C(void);
void sub_81D3FAC(void);
void EReaderHelper_SaveRegsState(void);
void EReaderHelper_RestoreRegsState(void);
void sub_81D4238(void);

#endif // GUARD_EREADER_HELPERS_H
