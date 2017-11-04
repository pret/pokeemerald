#ifndef GUARD_RECORD_MIXING_H
#define GUARD_RECORD_MIXING_H

// Exported type declarations

struct DayCareMailRecordMixing {
    struct MailStruct mail;
    u8 OT_name[OT_NAME_LENGTH + 1];
    u8 monName[11];
    u8 language_maybe : 4;
    u8 unknown : 4;
    u32 stepsTaken;
};

// Exported RAM declarations

// Exported ROM declarations

#endif //GUARD_RECORD_MIXING_H
