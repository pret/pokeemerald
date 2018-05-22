#ifndef GUARD_RECORD_MIXING_H
#define GUARD_RECORD_MIXING_H

// Exported type declarations
struct UnkRecordMixingStruct2a
{
    u8 playerId[4];
    u16 field_4;
    u8 playerName[PLAYER_NAME_LENGTH];
    u8 language;
};

struct UnkRecordMixingStruct2b
{
    u8 playerId1[4];
    u8 playerId2[4];
    u16 field_8;
    u8 playerName1[PLAYER_NAME_LENGTH];
    u8 playerName2[PLAYER_NAME_LENGTH];
    u8 language;
};

struct UnkRecordMixingStruct2
{
    struct UnkRecordMixingStruct2a field_0[9][2];
    struct UnkRecordMixingStruct2b field_120[2];
};

// Exported RAM declarations

// Exported ROM declarations

void sub_80E8260(struct UnkRecordMixingStruct2 *arg0);

#endif //GUARD_RECORD_MIXING_H
