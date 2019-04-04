#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

struct Unk81D38FC
{
    u8 unk0;
    u8 filler_1[3];
    u8 unk4[0x148];
    u8 unk14C[0x124];
    int checksum;
};

struct EReaderTrainerHillSet
{
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    int checksum;
    struct Unk81D38FC unk_8[6];
    u8 unk_ec0[40];
};

struct Unk81D3998Sub
{
    u8 unk_000[4];
    u8 unk_004[0x148];
    u8 unk_14C[0x148];
    u8 unk_294[0x124];
};

struct Unk81D3998
{
    u8 unk_000;
    u8 unk_001;
    u8 unk_002;
    int checksum;
    struct Unk81D3998Sub unk_008[4];
};

bool8 EReader_IsReceivedDataValid(struct EReaderTrainerHillSet *buffer);
bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *arg0);
bool32 ReadTrainerHillAndValidate(void);
int sub_81D3D70(u8, u32, u32*, u32*);
void sub_81D3F9C(void);
void sub_81D3FAC(void);
void sub_81D41A0(void);
void sub_81D41F4(void);
void sub_81D4238(void);

#endif // GUARD_EREADER_HELPERS_H
