#ifndef GUARD_RECORD_MIXING_H
#define GUARD_RECORD_MIXING_H

// Exported type declarations

struct DayCareMailRecordMixing {
    struct MailStruct mail;
    u8 OT_name[OT_NAME_LENGTH + 1];
    u8 monName[11];
    u8 language_maybe:4;
    u8 unknown:4;
};

struct UnkStruct_80E7B60 {
    struct DayCareMailRecordMixing unk_00[2];
    u32 unk_70;
    u16 unk_74[2];
}; // size = 0x78

// Exported RAM declarations

// Exported ROM declarations

void sub_80E8260(void *);

#endif //GUARD_RECORD_MIXING_H
