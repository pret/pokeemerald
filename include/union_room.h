#ifndef GUARD_UNION_ROOM_H
#define GUARD_UNION_ROOM_H

#include "librfu.h"

// Exported type declarations

struct UnkStruct_Shared
{
    struct UnkLinkRfuStruct_02022B14 field_0;
    u8 ALIGNED(4) playerName[PLAYER_NAME_LENGTH + 1];
};

struct UnkStruct_x1C
{
    struct UnkStruct_Shared unk0;
    u8 unk18:1;
};

struct UnkStruct_x20
{
    struct UnkStruct_Shared unk;
    u16 field_18;
    u8 field_1A_0:2;
    u8 field_1A_1:1;
    u8 field_1B;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;
};

struct UnkStruct_Main0
{
    struct UnkStruct_x20 arr[8];
};

struct UnkStruct_Main4
{
    struct UnkStruct_x1C arr[5];
};

struct UnkStruct_Main8
{
    struct UnkStruct_x20 arr[5];
};

struct UnkStruct_Leader
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    struct UnkStruct_Main8 *field_8;
    u8 state;
    u8 textState;
    u8 field_E;
    u8 listWindowId;
    u8 field_10;
    u8 field_11;
    u8 listTaskId;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 field_19;
    u16 field_1A;
};

struct UnkStruct_Group
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    u8 state;
    u8 textState;
    u8 field_A;
    u8 listWindowId;
    u8 field_C;
    u8 field_D;
    u8 listTaskId;
    u8 field_F;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
};

struct UnkStruct_8019BA8
{
    u8 field_0;
    u8 field_1;
    s8 field_2;
    u8 field_3;
};

struct UnkStruct_URoom
{
    struct UnkStruct_Main0 *field_0;
    struct UnkStruct_Main4 *field_4;
    struct UnkStruct_Main0 *field_8;
    struct UnkStruct_Main4 *field_C;
    u16 field_10;
    u16 field_12;
    u8 state;
    u8 stateAfterPrint;
    u8 textState;
    u8 field_17;
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u8 field_1C;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;
    u8 field_20;
    u8 spriteIds[40];
    u8 field_49;
    u8 field_4A;
    u16 field_4C[6];
    u8 field_58[0x98 - 0x58];
    u16 field_98;
    u16 field_9A[3];
    struct UnkStruct_8019BA8 field_A0[8];
    u8 field_C0[12][15];
    u8 field_174[48];
    u8 field_1A4[200];
};

union UnkUnion_Main
{
    struct UnkStruct_Leader *leader;
    struct UnkStruct_Group *group;
    struct UnkStruct_URoom *uRoom;
};

struct TradeUnkStruct
{
    u16 field_0;
    u16 type;
    u32 playerPersonality;
    u8 field_8;
    u8 field_9;
    u16 playerSpecies;
    u16 playerLevel;
    u16 species;
    u16 level;
    u16 field_12;
    u32 personality;
};

// Exported RAM declarations

extern u8 gUnknown_02022C2C;
extern union UnkUnion_Main gUnknown_02022C30;
extern struct UnkLinkRfuStruct_02022B14Substruct gUnknown_02022C38;

extern u16 gUnknown_02022C3C;
extern u8 gUnknown_02022C3E;

// Exported ROM declarations

u8 sub_8013F78(void);
void nullsub_89(u8 taskId);
void var_800D_set_xB(void);
void MEvent_CreateTask_CardOrNewsWithFriend(u32 arg0);
void MEvent_CreateTask_CardOrNewsOverWireless(u32 arg0);
void MEvent_CreateTask_Leader(u32 arg0);

#endif //GUARD_UNION_ROOM_H
