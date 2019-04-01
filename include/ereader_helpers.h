#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

struct Unk81D38FC
{
    u8 unk0[0x270];
    int checksum;
};

bool8 sub_81D3920(u8 *buffer);
bool32 sub_81D3AB0(struct Unk81D38FC *arg0);
bool32 sub_81D3B34(void);
int sub_81D3D70(u8, u32, u32*, u32*);
void sub_81D3F9C(void);
void sub_81D3FAC(void);
void sub_81D41A0(void);
void sub_81D41F4(void);
void sub_81D4238(void);

#endif // GUARD_EREADER_HELPERS_H
