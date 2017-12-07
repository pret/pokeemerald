#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

// Exported type declarations

struct __attribute__((packed)) UnkLinkRfuStruct_02022B14
{
    u16 unk_00_0:4;
    u16 unk_00_4:1;
    u16 unk_00_5:1;
    u16 unk_00_6:1;
    u16 unk_00_7:1;
    u16 unk_01_0:1;
    u16 unk_01_1:1;
    u16 unk_01_2:4;
    u16 unk_01_6:2;
    u8 playerTrainerId[2];
    u8 unk_04[4];
    u16 unk_08_0:10;
    u16 unk_09_2:6;
    u8 unk_0a_0:7;
    u8 unk_0a_7:1;
    u8 playerGender:1;
    u8 unk_0b_1:7;
    u8 unk_0c;
};

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
    u8 fill_00[15];
    u8 unk_0f;
    u8 fill_10[0xcc];
};

struct UnkRfuStruct_1 {
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

struct UnkRfuStruct_2_Sub_6c {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u8 filler_0c[4];
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
};

struct UnkRfuStruct_2_Sub_124 {
    /* 0x000 */ u8 unk_00[32][70];
    /* 0x8c0 */ vu8 unk_8c0;
    /* 0x8c1 */ vu8 unk_8c1;
    /* 0x8c2 */ vu8 unk_8c2;
    /* 0x8c3 */ vu8 unk_8c3;
};

struct UnkRfuStruct_2_Sub_9e8 {
    /* 0x000 */ u8 unk_00[40][14];
    /* 0x230 */ vu8 unk_230;
    /* 0x231 */ vu8 unk_231;
    /* 0x232 */ vu8 unk_232;
    /* 0x233 */ vu8 unk_233;
};

struct UnkRfuStruct_2_Sub_c1c {
    /* 0x00 */ u8 unk_00[2][14];
    /* 0x1c */ vu8 unk_1c;
    /* 0x1d */ vu8 unk_1d;
    /* 0x1e */ vu8 unk_1e;
};

struct UnkRfuStruct_Sub_Unused {
    /* 0x000 */ u8 unk_00[2][256];
    /* 0x200 */ vu8 unk_200;
    /* 0x201 */ vu8 unk_201;
    /* 0x202 */ vu8 unk_202;
    /* 0x203 */ vu8 unk_203;
};

struct UnkRfuStruct_2 {
    /* 0x000 */ u8 filler_00[4];
    /* 0x004 */ u16 unk_04;
    /* 0x006 */ u8 filler_06[6];
    /* 0x00c */ u8 unk_0c;
    /* 0x00d */ u8 playerCount;
    /* 0x00e */ u8 filler_0e[0x3e];
    /* 0x04c */ u8 unk_4c[14 * 2];
    /* 0x068 */ u8 filler_68[4];
    /* 0x06c */ struct UnkRfuStruct_2_Sub_6c unk_6c;
    /* 0x080 */ struct UnkRfuStruct_2_Sub_6c unk_80[5];
    /* 0x0e4 */ u8 filler_e4[10];
    /* 0x0ee */ vu8 unk_ee;
    /* 0x0ef */ u8 filler_ef[0x35];
    /* 0x124 */ struct UnkRfuStruct_2_Sub_124 unk_124;
    /* 0x9e8 */ struct UnkRfuStruct_2_Sub_9e8 unk_9e8;
    /* 0xc1c */ struct UnkRfuStruct_2_Sub_c1c unk_c1c;
    /* 0xc3c */ u8 filler_c3c[2];
    /* 0xc3e */ vu8 unk_c3e;
    /* 0xc3f */ u8 unk_c3f[70 * 2];
    /* 0xccb */ u8 filler_ccb[16];
    /* 0xcdb */ vu8 unk_cdb;
    /* 0xcdc */ u8 filler_cdc[2];
    /* 0xcde */ u8 unk_cde[4];
    /* 0xce2 */ u8 filler_ce2[2];
    /* 0xce4 */ u8 unk_ce4;
    /* 0xce5 */ u8 filler_ce5[15];
}; // size = 0xcf4

// Exported RAM declarations

extern struct UnkRfuStruct_1 gUnknown_03004140;
extern struct UnkRfuStruct_2 gUnknown_03005000;

// Exported ROM declarations
u32 sub_800BEC0(void);
void sub_800E700(void);
void sub_800EDD4(void);
void sub_800F6FC(u8 who);
void sub_800F728(u8 who);
bool32 sub_800F7E4(void);
void sub_800F804(void);
void sub_800F850(void);
u8 sub_800FCD8(void);
bool32 sub_800FE84(const void *src, size_t size);
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
bool32 sub_800F0B8(void);
u32 sub_80124D4(void);
void RfuVSync(void);
void sub_80111B0(bool32 a0);
u8 sub_8011A74(void);

#endif //GUARD_LINK_RFU_H
