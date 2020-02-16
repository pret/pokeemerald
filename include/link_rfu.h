#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

#include "librfu.h"
#include "link.h"
#include "AgbRfu_LinkManager.h"

// Exported type declarations

// RfuTgtData.gname is read as these structs.
struct GFtgtGnameSub
{
    u16 language:4;
    u16 hasNews:1;
    u16 hasCard:1;
    u16 unk_00_6:1;
    u16 isChampion:1;
    u16 hasNationalDex:1;
    u16 gameClear:1;
    u16 version:4;
    u16 unk_01_6:2;
    u8 playerTrainerId[2];
};

struct __attribute__((packed, aligned(2))) GFtgtGname
{
    struct GFtgtGnameSub unk_00;
    u8 child_sprite_gender[RFU_CHILD_MAX]; // u8 sprite_idx:3;
    // u8 gender:1;
    // u8 unk_4:3
    // u8 active:1
    u16 species:10;
    u16 type:6;
    u8 activity:7;
    u8 started:1;
    u8 playerGender:1;
    u8 level:7;
    u8 padding;
}; // size: RFU_GNAME_SIZE

struct UnkLinkRfuStruct_02022B2C
{
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u16 unk_06;
    struct GFtgtGname *unk_08;
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
    /* 0x000 */ void (*linkRfuCallback)(void);
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
    /* 0x10A */ struct GFtgtGname unk_10A;
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

extern struct GFtgtGname gUnknown_02022B14;
extern u8 gUnknown_02022B22[];
extern struct UnkRfuStruct_2 Rfu;
extern u8 gWirelessStatusIndicatorSpriteId;

// Exported ROM declarations
void WipeTrainerNameRecords(void);
void sub_800E700(void);
void sub_800EDD4(void);
void sub_800F6FC(u8 who);
void sub_800F728(u8 who);
bool32 IsSendingKeysToRfu(void);
void sub_800F804(void);
void sub_800F850(void);
u8 sub_800FCD8(void);
bool32 sub_800FE84(const u8 *src, size_t size);
void ClearLinkRfuCallback(void);
u8 sub_80104F4(void);
u8 rfu_get_multiplayer_id(void);
bool8 sub_8010100(u8 a0);
bool8 IsLinkRfuTaskFinished(void);
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
struct GFtgtGname *sub_800F7DC(void);
void sub_8011068(u8 a0);
void sub_8011170(u32 a0);
void sub_8011A64(u8 a0, u16 a1);
u8 sub_801048C(bool32 a0);
void sub_800DF90(struct GFtgtGname *buff1, u8 *buff2);
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
void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 a2);
bool32 sub_8011B90(void);
void sub_800FE50(void *a0);
bool32 sub_800E540(u16 id, u8 *name);
void sub_8011DE0(u32 arg0);
u8 sub_801100C(s32 a0);
void sub_800EF7C(void);
bool8 sub_800DE7C(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 sub_800DF34(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
s32 sub_800E87C(u8 idx);
void sub_8011BA4(void);
void sub_8010198(void);
void sub_8011AC8(void);
void LinkRfu_FatalError(void);
bool32 sub_8011A9C(void);
void sub_80104B0(void);
void sub_8011A50(void);
void sub_80110B8(u32 a0);
bool8 sub_800DAC8(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void sub_800EAB4(void);
void sub_800EAFC(void);
void sub_800ED34(u16 unused);
void sub_800EDBC(u16 unused);
void sub_800F048(void);
void sub_800F86C(u8 unused);
void sub_800FCC4(struct UnkRfuStruct_2_Sub_6c *data);
void sub_800FD14(u16 command);
void rfufunc_80F9F44(void);
void sub_800FFB0(void);
void rfufunc_80FA020(void);
bool32 sub_8010454(u32 a0);
void sub_8010528(void);
void sub_8010750(void);
s32 sub_80107A0(void);
void sub_801084C(u8 taskId);
void sub_80109E8(u16 a0);
void sub_8010A70(void *a0);
void sub_8010AAC(u8 taskId);
void sub_8010D0C(u8 taskId);
void sub_80115EC(s32 a0);
u8 sub_8011CE4(const u8 *a0, u16 a1);
void sub_8011D6C(u32 a0);
void sub_8011E94(u32 a0, u32 a1);
bool8 sub_8012224(void);
void sub_801227C(void);
void sub_801209C(u8 taskId);
void sub_8011BF8(void);
void sub_8011BA4(void);
void sub_800D6C8(struct UnkRfuStruct_2_Sub_124 *ptr);
void sub_800D724(struct UnkRfuStruct_2_Sub_9e8 *ptr);
void sub_800D780(struct UnkRfuStruct_Sub_Unused *ptr);
void sub_800D7D8(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2);
void sub_800D888(struct UnkRfuStruct_2_Sub_9e8 *q1, u8 *q2);
bool8 sub_800D934(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2);
bool8 sub_800D9DC(struct UnkRfuStruct_2_Sub_9e8 *q1, u8 *q2);
void sub_800DA68(struct UnkRfuStruct_2_Sub_c1c *q1, const u8 *q2);
bool8 sub_800DAC8(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2);
void sub_800DB18(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
bool8 sub_800DB84(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2);
void sub_800DBF8(u8 *q1, u8 mode);
void PkmnStrToASCII(u8 *q1, const u8 *q2);
void ASCIIToPkmnStr(u8 *q1, const u8 *q2);
u8 sub_800DD1C(u8 maxFlags);
void sub_800DD94(struct GFtgtGname *data, u8 r9, bool32 r2, s32 r3);
bool8 sub_800DE7C(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
bool8 sub_800DF34(struct GFtgtGname *buff1, u8 *buff2, u8 idx);
void sub_800DF90(struct GFtgtGname *buff1, u8 *buff2);
void CreateWirelessStatusIndicatorSprite(u8 x, u8 y);
void DestroyWirelessStatusIndicatorSprite(void);
void LoadWirelessStatusIndicatorSpriteGfx(void);
u8 sub_800E124(void);
void sub_800E15C(struct Sprite *sprite, s32 signalStrengthAnimNum);
void sub_800E174(void);
void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name);
bool32 NameIsNotEmpty(const u8 *name);
void RecordMixTrainerNames(void);
bool32 sub_800E540(u16 id, u8 *name);
void WipeTrainerNameRecords(void);

#endif //GUARD_LINK_RFU_H
