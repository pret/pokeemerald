#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"

// Exported type declarations

struct UnkLinkRfuStruct_02022B2C
{
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u16 unk_06;
    struct UnkLinkRfuStruct_02022B14 *unk_08;
    u8 *unk_0c;
    u8 unk_10;
    u8 unk_11;
    u16 unk_12;
    u16 unk_14;
};

struct UnkLinkRfuStruct_02022B44
{
    u8 fill_00[6];
    u16 unk_06;
    u8 fill_08[6];
    vu8 unk_0e;
    u8 unk_0f;
    u8 fill_10[0x54];
    u16 unk_64;
    u8 fill_66[0x1d];
    u8 unk_83;
    u8 fill_84[0x58];
};

struct UnkRfuStruct_1
{
    /* 0x000 */ u8 unk_00;
    /* 0x001 */ u8 unk_01;
    /* 0x002 */ vu8 unk_02;
    /* 0x003 */ vu8 unk_03;
    /* 0x004 */ u8 unk_04;
    /* 0x005 */ u8 unk_05;
    /* 0x006 */ u8 unk_06;
    /* 0x007 */ u8 unk_07;
    /* 0x008 */ u8 unk_08;
    /* 0x009 */ u8 unk_09;
    /* 0x00a */ u8 unk_0a;
    /* 0x00b */ u8 unk_0b;
    /* 0x00c */ u8 unk_0c;
    /* 0x00d */ u8 unk_0d;
    /* 0x00e */ u8 unk_0e;
    /* 0x00f */ u8 unk_0f;
    /* 0x010 */ u8 unk_10;
    /* 0x011 */ u8 unk_11;
    /* 0x012 */ u8 unk_12;
    // aligned
    /* 0x014 */ u16 unk_14;
    /* 0x016 */ u16 unk_16;
    /* 0x018 */ u16 unk_18;
    /* 0x01a */ u16 unk_1a;
    /* 0x01c */ u16 unk_1c;
    /* 0x01e */ u16 unk_1e;
    /* 0x020 */ const u16 *unk_20;
    /* 0x024 */ u8 unk_24;
    /* 0x026 */ u16 unk_26;
    /* 0x028 */ u16 unk_28[4];
    /* 0x030 */ u8 unk_30;
    // aligned
    /* 0x032 */ u16 unk_32;
    /* 0x034 */ u16 unk_34[4];
    /* 0x03c */ const struct UnkLinkRfuStruct_02022B2C *unk_3c;
    /* 0x040 */ void (*unk_40)(u8, u8);
    /* 0x044 */ void (*unk_44)(u16);
    /* 0x048 */ u8 filler_48[8];
    /* 0x050 */ u32 unk_50[0x399];
    /* 0xeb4 */ u8 filler_e64[12];
};

struct UnkRfuStruct_2_Sub_6c
{
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ const u8 *unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
};

struct UnkRfuStruct_2_Sub_124
{
    /* 0x000 */ u8 unk_00[32][70];
    /* 0x8c0 */ vu8 unk_8c0;
    /* 0x8c1 */ vu8 unk_8c1;
    /* 0x8c2 */ vu8 unk_8c2;
    /* 0x8c3 */ vu8 unk_8c3;
};

struct UnkRfuStruct_2_Sub_9e8
{
    /* 0x000 */ u8 unk_00[40][14];
    /* 0x230 */ vu8 unk_230;
    /* 0x231 */ vu8 unk_231;
    /* 0x232 */ vu8 unk_232;
    /* 0x233 */ vu8 unk_233;
};

struct UnkRfuStruct_2_Sub_c1c
{
    /* 0x00 */ u8 unk_00[2][14];
    /* 0x1c */ vu8 unk_1c;
    /* 0x1d */ vu8 unk_1d;
    /* 0x1e */ vu8 unk_1e;
};

struct UnkRfuStruct_Sub_Unused
{
    /* 0x000 */ u8 unk_00[2][256];
    /* 0x200 */ vu8 unk_200;
    /* 0x201 */ vu8 unk_201;
    /* 0x202 */ vu8 unk_202;
    /* 0x203 */ vu8 unk_203;
};

struct UnkRfuStruct_2
{
    /* 0x000 */ void (*unk_00)(void);
    /* 0x004 */ u16 unk_04;
    /* 0x006 */ u8 filler_06[4];
    /* 0x00a */ u16 unk_0a;
    /* 0x00c */ u8 unk_0c;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ u8 unk_0e;
    /* 0x00f */ u8 unk_0f;
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u16 unk_12;
    /* 0x014 */ u8 unk_14[4][14];
    /* 0x04c */ u8 unk_4c[14];
    /* 0x05a */ u8 unk_5a;
    /* 0x05b */ u8 unk_5b;
    /* 0x05c */ u8 unk_5c[5];
    /* 0x061 */ u8 unk_61[5];
    /* 0x066 */ u8 unk_66;
    /* 0x067 */ u8 unk_67;
    /* 0x068 */ u8 filler_68[4];
    /* 0x06c */ struct UnkRfuStruct_2_Sub_6c unk_6c;
    /* 0x080 */ struct UnkRfuStruct_2_Sub_6c unk_80[5];
    /* 0x0e4 */ u8 unk_e4[5];
    /* 0x0e9 */ u8 unk_e9[5];
    /* 0x0ee */ vu8 unk_ee;
    /* 0x0ef */ u8 unk_ef;
    /* 0x0f0 */ u8 unk_f0;
    /* 0x0f1 */ u8 unk_f1;
    /* 0x0f2 */ u16 unk_f2[6];
    /* 0x0fe */ u16 unk_fe;
    /* 0x100 */ u16 unk_100;
    /* 0x102 */ u8 unk_102;
    /* 0x103 */ u8 filler_103[0x10A - 0x103];
    /* 0x10A */ struct UnkLinkRfuStruct_02022B14 unk_10A;
    u8 filler_;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    /* 0x124 */ struct UnkRfuStruct_2_Sub_124 unk_124;
    /* 0x9e8 */ struct UnkRfuStruct_2_Sub_9e8 unk_9e8;
    /* 0xc1c */ struct UnkRfuStruct_2_Sub_c1c unk_c1c;
    /* 0xc3c */ vu8 unk_c3c;
    /* 0xc3d */ u8 unk_c3d;
    /* 0xc3e */ vu8 unk_c3e;
    /* 0xc3f */ u8 unk_c3f[70];
    /* 0xc85 */ u8 unk_c85;
    /* 0xc86 */ u8 unk_c86;
    /* 0xc87 */ u8 unk_c87[5][7][2];
    /* 0xccd */ u8 unk_ccd;
    /* 0xcce */ u8 unk_cce;
    /* 0xccf */ u8 unk_ccf;
    /* 0xcd0 */ vu8 unk_cd0;
    /* 0xcd1 */ u8 unk_cd1[4];
    /* 0xcd5 */ u8 unk_cd5[4];
    /* 0xcd9 */ u8 unk_cd9;
    /* 0xcda */ u8 unk_cda;
    /* 0xcdb */ vu8 unk_cdb;
    /* 0xcdc */ vu8 unk_cdc;
    /* 0xcdd */ u8 unk_cdd;
    /* 0xcde */ u8 unk_cde[4];
    /* 0xce2 */ u8 unk_ce2;
    /* 0xce2 */ u8 unk_ce3;
    /* 0xce4 */ u8 unk_ce4;
    /* 0xce5 */ u8 unk_ce5;
    /* 0xce5 */ u8 unk_ce6;
    /* 0xce7 */ u8 unk_ce7;
    /* 0xce8 */ u8 unk_ce8;
    /* 0xce9 */ u8 unk_ce9;
    /* 0xcea */ u8 unk_cea[4];
    /* 0xcee */ u8 unk_cee[4];
}; // size = 0xcf4

struct UnkRfuStruct_8010A14
{
    char unk_00[15];
    u8 unk_0f;
    u8 unk_10[4];
    struct LinkPlayer unk_14[5];
    u8 fill_a0[0x5c];
};

// Exported RAM declarations

extern struct UnkRfuStruct_1 gUnknown_03004140;
extern struct UnkRfuStruct_2 gUnknown_03005000;
extern u8 gWirelessStatusIndicatorSpriteId;

// Exported ROM declarations
void WipeTrainerNameRecords(void);
u32 sub_800BEC0(void);
void sub_800E700(void);
void sub_800EDD4(void);
void sub_800F6FC(u8 who);
void sub_800F728(u8 who);
bool32 IsSendingKeysToRfu(void);
void sub_800F804(void);
void sub_800F850(void);
u8 sub_800FCD8(void);
bool32 sub_800FE84(const u8 *src, size_t size);
void Rfu_set_zero(void);
u8 sub_80104F4(void);
u8 rfu_get_multiplayer_id(void);
bool8 sub_8010100(u8 a0);
bool8 sub_8010500(void);
bool8 Rfu_IsMaster(void);
void task_add_05_task_del_08FA224_when_no_RfuFunc(void);
void sub_8010434(void);
void sub_800E604(void);
void sub_800E174(void);
void sub_800E6D0(void);
bool32 sub_8010EC0(void);
bool32 sub_8010F1C(void);
bool32 sub_8011A80(void);
bool32 IsRfuRecvQueueEmpty(void);
u32 GetRfuRecvQueueLength(void);
void RfuVSync(void);
void sub_80111B0(bool32 a0);
u8 sub_8011A74(void);
struct UnkLinkRfuStruct_02022B14 *sub_800F7DC(void);
void sub_8011068(u8 a0);
void sub_8011170(u32 a0);
void sub_8011A64(u8 a0, u16 a1);
u8 sub_801048C(bool32 a0);
void sub_800DF90(struct UnkLinkRfuStruct_02022B14 *buff1, u8 *buff2);
void sub_8010F84(u8 a0, u32 a1, u32 a2);
void sub_8011C10(u32 a0);
bool32 sub_8012240(void);
void sub_800EF38(void);
bool32 sub_80105EC(void);
bool32 sub_801064C(u16 a0, const u8 *a1);
void sub_8010688(u8 a0, u16 a1, const u8 *a2);
u32 sub_8010714(u16 a0, const u8 *a1);
void sub_8011DC0(const u8 *a0, u16 a1);
bool8 sub_800EF1C(void);
bool32 sub_800EF58(bool32 a0);
void DestroyWirelessStatusIndicatorSprite(void);
void sub_801103C(void);
void sub_8011C5C(void);
void sub_80106D4(void);
void RecordMixTrainerNames(void);
void sub_800ED10(void);
void sub_800ED28(void);
void sub_8011090(u8 a0, u32 a1, u32 a2);
void sub_8011FC8(const u8 *src, u16 trainerId);
void sub_8010FA0(bool32 a0, bool32 a1);
void sub_8010F60(void);
void sub_8010FCC(u32 a0, u32 a1, u32 a2);
void sub_8011C84(void);
void sub_8012188(const u8 *name, struct UnkLinkRfuStruct_02022B14 *structPtr, u8 a2);
bool32 sub_8011B90(void);
void sub_800FE50(u16 *a0);
bool32 sub_800E540(u16 id, u8 *name);
void sub_8011DE0(u32 arg0);
u8 sub_801100C(int a0);
void sub_800EF7C(void);
bool8 sub_800DE7C(struct UnkLinkRfuStruct_02022B14 *buff1, u8 *buff2, u8 idx);
bool8 sub_800DF34(struct UnkLinkRfuStruct_02022B14 *buff1, u8 *buff2, u8 idx);
s32 sub_800E87C(u8 idx);
void sub_8011BA4(void);
void sub_8010198(void);
void sub_8011AC8(void);
void LinkRfu_FatalError(void);
bool32 sub_8011A9C(void);
void sub_80104B0(void);
void sub_8011A50(void);
void sub_80110B8(u32 a0);

#endif //GUARD_LINK_RFU_H
