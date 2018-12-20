#include "global.h"
#include "window.h"
#include "bg.h"
#include "string_util.h"
#include "task.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "librfu.h"
#include "alloc.h"
#include "menu.h"
#include "list_menu.h"
#include "menu_helpers.h"
#include "script.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/rgb.h"
#include "constants/battle_frontier.h"
#include "trade.h"
#include "trainer_card.h"
#include "overworld.h"
#include "battle.h"
#include "load_save.h"
#include "cable_club.h"
#include "field_control_avatar.h"
#include "party_menu.h"
#include "field_weather.h"
#include "palette.h"
#include "decompress.h"
#include "start_menu.h"
#include "data2.h"
#include "field_screen_effect.h"

extern void HealPlayerParty(void);

struct UnkStruct_Shared
{
    struct UnkLinkRfuStruct_02022B14 field_0;
    u8 needingPadding[2];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
};

struct UnkStruct_x1C
{
    struct UnkStruct_Shared unk0;
    u8 unk18;
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
    u8 field_2;
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
    u16 field_2;
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u16 field_A;
    u16 field_C;
    u16 species;
    u16 level;
    u16 field_12;
    u32 personality;
};

extern struct TradeUnkStruct gUnknown_02022C40;
extern struct UnkLinkRfuStruct_02022B14Substruct gUnknown_02022C38;
extern union UnkUnion_Main gUnknown_02022C30;
extern u8 gUnknown_02022C2C;
extern u8 gUnknown_02022C2D;
extern u8 gUnknown_02022C3E;
extern u16 gUnknown_02022C3C;
extern u8 gUnknown_02022C20[];
extern u8 gFieldLinkPlayerCount;
extern u8 gUnknown_03005DB4;
extern u8 gSelectedOrderFromParty[];
extern struct MailStruct gUnknown_020321C0[PARTY_SIZE];
extern u8 gUnknown_02032298[2];

// IWRAM vars
IWRAM_DATA struct UnkStruct_Leader *gUnknown_03000DA0;
IWRAM_DATA struct UnkStruct_Group *gUnknown_03000DA4;
IWRAM_DATA struct UnkStruct_URoom *gUnknown_03000DA8;
IWRAM_DATA void *gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

// this file's functions
void sub_80173E0(u8 windowId, u8 arg1, const u8 *str, u8 arg3, u8 arg4, u8 arg5);
u16 ReadAsU16(const u8 *ptr);
void sub_8012780(u8 taskId);
void sub_80134E8(u8 taskId);
void sub_8013C7C(u8 taskId);
void sub_8014A40(u8 taskId);
void sub_8014F48(u8 taskId);
void sub_80152F4(u8 taskId);
void sub_80156E0(u8 taskId);
void sub_80175EC(struct UnkStruct_Main4 *arg0, u8 count);
void sub_8017580(struct UnkStruct_x20 *arg0, u8 count);
u8 sub_8016FC0(struct UnkStruct_Main4 *arg0, u32 arg1);
u8 sub_8016FF0(struct UnkStruct_Main4 *arg0, u32 arg1);
bool8 PrintOnTextbox(u8 *textState, const u8 *str);
bool8 sub_801320C(struct UnkStruct_Leader *data, u32 arg1, u32 arg2);
u8 sub_8013398(struct UnkStruct_Main0 *arg0);
s8 sub_80170B8(u8 *arg0, bool32 arg1);
void sub_8018404(u8 *dest, struct UnkStruct_x20 *arg1);
void sub_8012F64(struct UnkStruct_Leader *data);
void sub_80149C4(void);
u8 sub_80132D4(struct UnkStruct_Main0 *arg0);
void sub_80178A0(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id);
u32 sub_80176E4(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1);
u8 sub_8017734(struct UnkStruct_x20 *arg0, struct UnkStruct_Shared *arg1, u8 arg2);
u8 sub_8013E44(void);
u32 sub_8013B8C(struct UnkStruct_Group *arg0, s32 id);
void sub_8013BD8(struct UnkStruct_Group *arg0, s32 id);
void sub_80173D4(void);
void sub_80177B8(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id);
bool32 sub_8017678(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1);
u32 sub_8018120(struct TradeUnkStruct *arg0, u8 multiplayerId);
void sub_801807C(struct TradeUnkStruct *arg0);
void sub_801B940(void);
void sub_801B94C(u16);
u16 sub_801B39C(void);
void sub_801AC54(void);
void sub_801DD98(void);
void sub_802A9A8(u8 monId, MainCallback callback);
void sub_802493C(u8 monId, MainCallback callback);
void sub_8020C70(MainCallback callback);
void sub_80149D8(void);
u16 sub_8019930(void);
void sub_8018784(u8 windowId);
void sub_8018884(const u8 *src);
bool32 mevent_0814257C(u8 *textState, const u8 *str);
s8 sub_8018B08(u8 *textState, u8 *arg1, u8 arg2, const u8 *str);
bool32 sub_8016F1C(struct UnkStruct_x20 *arg0, s16 arg1);
u8 sub_8016DF0(struct UnkStruct_Main4 *arg0, struct UnkStruct_Main4 *arg1, u32 arg2);
void sub_8019F2C(void);
void sub_8019E70(u8 *arg0, s32 arg1);
bool32 sub_80180A0(u8 monId, struct TradeUnkStruct *arg1);
void sub_80180E8(u8 monId, struct TradeUnkStruct *arg1);
bool32 sub_801A2A8(struct UnkStruct_Main0 *arg0, s16 *arg1, s16 *arg2, u8 *arg3);
void sub_80181CC(void);
bool32 sub_8017940(void);
u8 sub_8016B00(void);
void sub_801A274(struct UnkStruct_URoom *arg0);
void sub_801A284(struct UnkStruct_URoom *arg0);
bool32 sub_8017FD8(struct UnkStruct_URoom *arg0);
void sub_801689C(struct UnkStruct_URoom *arg0);
u8 sub_80181DC(struct UnkStruct_URoom *arg0);
bool32 sub_80168DC(struct UnkStruct_URoom *arg0);
bool32 sub_801704C(void);
s32 sub_8017CF8(s32 arg1, struct UnkStruct_Main0 *arg0);
s32 sub_80179D4(struct UnkStruct_Main0 *arg0, u8 arg1, u8 arg2, u32 playerGender);
void sub_801818C(bool32 arg0);
void sub_801A3D0(u32 arg0, u32 arg1, struct UnkStruct_Main0 *arg2);
s32 sub_8017178(u8 *arg0, u8 *arg1, u8 *arg2, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate);
s32 sub_80172A0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate, struct UnkStruct_Main0 *arg6);
bool32 sub_8018024(void);
u32 sub_8017984(u32 arg0);
void sub_8018220(u8 *unused, struct UnkStruct_URoom *arg1, bool8 arg2);
void sub_8017D9C(u8 *dst, u32 arg1, u32 playerGender);
u32 sub_80179AC(struct UnkStruct_x20 *arg0);
void sub_8017E00(u8 *dst, u8 arg1);
void sub_8019F04(u8 *spriteIds);
void sub_8019E3C(void);
void sub_80173B0(void);
s32 sub_8017D04(u32 type, u32 species);
void sub_8017020(const u8 *src);
void sub_8019BA8(void *);
s32 sub_8017EA0(u8 *dst, u32 gender, u16 *arg2, struct UnkStruct_URoom *arg3);
void sub_801697C(u8 taskId);
bool8 sub_8017630(struct UnkStruct_Shared* arg0, const struct UnkStruct_Shared* arg1);

// const rom data
extern const u8 *const gUnknown_082EDB60[][5];

extern const u8 gText_UnkCtrlCodeF907[];
extern const u8 gUnknown_082EDBC4[];
extern const u8 gText_AwaitingCommunication[];
extern const u8 gText_AwaitingLink[];
extern const u8 gUnknown_082EDC5C[];
extern const u8 gUnknown_082EDC9C[];
extern const u8 gUnknown_082EDC78[];
extern const u8 gUnknown_082EDD58[];
extern const u8 gUnknown_082EDBE8[];
extern const u8 gUnknown_082EDC0C[];
extern const u8 gUnknown_082EDC34[];
extern const u8 gUnknown_082EE560[];
extern const u8 gUnknown_082EE57C[];
extern const u8 gUnknown_082EFC54[];
extern const u8 gUnknown_082EFC3C[];
extern const u8 gUnknown_082EDE0C[];
extern const u8 gUnknown_082EDDF4[];
extern const u8 gUnknown_082EF7DC[];
extern const u8 gUnknown_082EDE48[];
extern const u8 gUnknown_082EDE64[];
extern const u8 gUnknown_082EDF40[];
extern const u8 gText_PleaseStartOver[];
extern const u8 gUnknown_082EF7F8[];
extern const u8 gUnknown_082EFBC8[];
extern const u8 gUnknown_082EFC90[];
extern const u8 gUnknown_082EDEC4[];
extern const u8 gUnknown_082EDF04[];
extern const u8 gText_WirelessSearchCanceled[];
extern const u8 gUnknown_082EF4FC[];
extern const u8 gUnknown_082EF520[];
extern const u8 gUnknown_082EF5B8[];
extern const u8 gUnknown_082EF1EC[];
extern const u8 gUnknown_082EF544[];
extern const u8 gUnknown_082EF47C[];
extern const u8 gUnknown_082EE6C8[];
extern const u8 gUnknown_082EE004[];
extern const u8 gUnknown_082EEBD0[];
extern const u8 gUnknown_082EEB88[];
extern const u8 gUnknown_082EE598[];
extern const u8 gUnknown_082EEC14[];
extern const u8 gUnknown_082EF590[];
extern const u8 gUnknown_082EF20C[];
extern const u8 gUnknown_082EF564[];
extern const u8 gUnknown_082EF4C4[];
extern const u8 gUnknown_082EF298[];
extern const u8 gUnknown_082EF65C[];
extern const u8 gUnknown_082EF6E4[];
extern const u8 gUnknown_082EF718[];

extern const u32 gUnknown_082F00C4[];

extern const u8 gUnknown_082F0530[];

extern const struct WindowTemplate gUnknown_082F00BC;
extern const struct WindowTemplate gUnknown_082F0124;
extern const struct WindowTemplate gUnknown_082F012C;
extern const struct WindowTemplate gUnknown_082F011C;
extern const struct WindowTemplate gUnknown_082F0174;
extern const struct WindowTemplate gUnknown_082F017C;
extern const struct WindowTemplate gUnknown_082F021C;
extern const struct WindowTemplate gUnknown_082F025C;
extern const struct WindowTemplate gUnknown_082F0294;
extern const struct WindowTemplate gUnknown_082F034C;

extern const struct ListMenuTemplate gUnknown_082F015C;
extern const struct ListMenuTemplate gUnknown_082F0204;
extern const struct ListMenuTemplate gUnknown_082F0244;
extern const struct ListMenuTemplate gUnknown_082F027C;
extern const struct ListMenuTemplate gUnknown_082F032C;
extern const struct ListMenuTemplate gUnknown_082F03A4;

extern const u8 *const gUnknown_082F0048[];
extern const u8 *const gUnknown_082EDDC4[];
extern const u8 *const gUnknown_082EFB70[];
extern const u8 *const gUnknown_082EDD50[];
extern const u8 *const gUnknown_082EDE9C[];
extern const u8 *const gUnknown_082EDF80[];
extern const u8 *const gUnknown_082EFD58[];
extern const u8 *const gUnknown_082EEB80[];
extern const u8 *const gUnknown_082EE378[];
extern const u8 *const gUnknown_082EEC9C[];
extern const u8 *const gUnknown_082EED3C[];
extern const u8 *const gUnknown_082EE324[];
extern const u8 *const gUnknown_082EE17C[];

extern const u8 *const gUnknown_082EE82C[][4];

extern const u8 *const gUnknown_082EE24C[][2];

extern const struct UnkStruct_Shared gUnknown_082F045C;

extern const u8 *const gUnknown_082F04D8[22];

// code
void nullsub_89(void)
{

}

void sub_80124EC(u8 windowId, u8 arg1, u8 stringId)
{
    FillWindowPixelBuffer(windowId, 0x11);
    switch (arg1 << 8)
    {
    case 0x200:
        sub_80173E0(windowId, 1, gUnknown_082EDB60[0][stringId - 1], 0, 1, 0);
        break;
    case 0x400:
        sub_80173E0(windowId, 1, gUnknown_082EDB60[1][stringId - 1], 0, 1, 0);
        break;
    case 0x2500:
        sub_80173E0(windowId, 1, gUnknown_082EDB60[2][stringId - 1], 0, 1, 0);
        break;
    case 0x3500:
        sub_80173E0(windowId, 1, gUnknown_082EDB60[3][stringId - 1], 0, 1, 0);
        break;
    case 0x2400:
        sub_80173E0(windowId, 1, gUnknown_082EDB60[4][stringId - 1], 0, 1, 0);
        break;
    }

    CopyWindowToVram(windowId, 2);
}

void sub_80125BC(u8 windowId)
{
    u8 text[30];
    u8 *txtPtr;

    sub_80173E0(windowId, 1, gSaveBlock2Ptr->playerName, 0, 1, 0);
    txtPtr = StringCopy(text, gText_UnkCtrlCodeF907);
    ConvertIntToDecimalStringN(txtPtr, ReadAsU16(gSaveBlock2Ptr->playerTrainerId), STR_CONV_MODE_LEADING_ZEROS, 5);
    sub_80173E0(windowId, 1, text, 0, 0x11, 0);
}

void sub_801262C(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 1 ... 4:
    case 9 ... 11:
    case 14 ... 16:
    case 21 ... 28:
        // UB: argument *dst isn't used, instead it always prints to gStringVar4
        StringExpandPlaceholders(gStringVar4, gText_AwaitingCommunication);
        break;
    }
}

bool32 sub_80126CC(u32 caseId)
{
    switch (caseId)
    {
    case 9 ... 11:
    case 15 ... 16:
    case 23 ... 27:
        return TRUE;
    default:
        return FALSE;
    }
}

void BerryBlenderLinkBecomeLeader(void)
{
    u8 taskId;
    struct UnkStruct_Leader *dataPtr;

    taskId = CreateTask(sub_8012780, 0);
    gUnknown_02022C30.leader = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_03000DA0 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    gSpecialVar_Result = 0;
}

void sub_8012780(u8 taskId)
{
    u32 id, val;
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;

    switch (data->state)
    {
    case 0:
        if (gSpecialVar_0x8004 == 20 && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gUnknown_02022C2C = gUnknown_082F00C4[gSpecialVar_0x8004];
        gUnknown_02022C2D = gUnknown_082F00C4[gSpecialVar_0x8004] >> 8;
        sub_8010F84(gUnknown_02022C2C, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C10(gUnknown_02022C2D & 0xF);
        data->state = 3;
        break;
    case 3:
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0xA0);
        data->field_8 = AllocZeroed(0xA0);
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 5);
        sub_800DF90(&data->field_0->arr[0].unk.field_0, data->field_0->arr[0].unk.playerName);
        data->field_0->arr[0].field_18 = 0;
        data->field_0->arr[0].field_1A_0 = 1;
        data->field_0->arr[0].field_1A_1 = 0;
        data->field_0->arr[0].field_1B = 0;
        data->field_17 = sub_8016FC0(data->field_4, 0xFF);
        data->field_10 = AddWindow(&gUnknown_082F00BC);
        switch (gUnknown_02022C2D & 0xF)
        {
        case 2:
        case 3:
        case 4:
            data->listWindowId = AddWindow(&gUnknown_082F011C);
            break;
        case 5:
            data->listWindowId = AddWindow(&gUnknown_082F0124);
            break;
        }
        data->field_11 = AddWindow(&gUnknown_082F012C);

        FillWindowPixelBuffer(data->field_10, 0x22);
        sub_80173E0(data->field_10, 0, gUnknown_082EDBC4, 8, 1, 4);
        PutWindowTilemap(data->field_10);
        CopyWindowToVram(data->field_10, 2);

        NewMenuHelpers_DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F015C;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        NewMenuHelpers_DrawStdWindowFrame(data->field_11, FALSE);
        PutWindowTilemap(data->field_11);
        CopyWindowToVram(data->field_11, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->state = 4;
        break;
    case 4:
        StringCopy(gStringVar1, gUnknown_082F0048[gUnknown_02022C2C]);
        if ((gUnknown_02022C2D >> 4) != 0)
        {
            if (data->field_13 > (gUnknown_02022C2D >> 4) - 1 && (gUnknown_02022C2D & 0xF) != 0)
                StringExpandPlaceholders(gStringVar4, gText_AwaitingLink);
            else
                StringExpandPlaceholders(gStringVar4, gText_AwaitingCommunication);
        }
        else
        {
            sub_801262C(gStringVar4, gUnknown_02022C2C);
        }

        sub_80124EC(data->field_11, gUnknown_02022C2D, data->field_13);
        data->state = 5;
        break;
    case 5:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 6;
        break;
    case 6:
        sub_801320C(data, 7, 10);
        if (gMain.newKeys & B_BUTTON)
        {
            if (data->field_13 == 1)
                data->state = 23;
            else if ((gUnknown_02022C2D & 0xF0) != 0)
                data->state = 30;
            else
                data->state = 19;
        }
        if ((gUnknown_02022C2D >> 4) != 0
            && data->field_13 > (gUnknown_02022C2D >> 4) - 1
            && (gUnknown_02022C2D & 0xF) != 0
            && sub_8012240()
            && gMain.newKeys & START_BUTTON)
        {
            data->state = 15;
            sub_800EF38();
        }
        if (data->state == 6 && sub_80105EC())
        {
            data->state = 9;
        }
        break;
    case 9:
        if (!sub_80105EC())
        {
            data->state = 6;
            data->field_13 = sub_8013398(data->field_0);
        }
        break;
    case 10:
        id = ((gUnknown_02022C2C & 0xF) == 2) ? 1 : 0;
        if (PrintOnTextbox(&data->textState, gUnknown_082EDDC4[id]))
        {
            data->field_13 = sub_8013398(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = 4;
        }
        break;
    case 29:
        id = ((gUnknown_02022C2D & 0xF) == 2) ? 0 : 1;
        if (PrintOnTextbox(&data->textState, gUnknown_082EDDC4[id]))
        {
            data->state = 21;
        }
        break;
    case 7:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            data->state = 11;
        }
        break;
    case 11:
        switch (sub_80170B8(&data->textState, sub_801064C(ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName)))
        {
        case 0:
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->field_19 = 5;
            sub_8010688(5, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            sub_8010688(6, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case -3:
            data->state = 9;
            break;
        }
        break;
    case 12:
        val = sub_8010714(ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->field_13].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->field_13++;
                if (data->field_13 == (gUnknown_02022C2D & 0xF))
                {
                    if ((gUnknown_02022C2D & 0xF0) != 0 || data->field_13 == 4)
                    {
                        data->state = 15;
                    }
                    else
                    {
                        sub_8018404(gStringVar1, &data->field_0->arr[data->field_13 - 1]);
                        StringExpandPlaceholders(gStringVar4, gUnknown_082EDC9C);
                        data->state = 13;
                    }

                    sub_800EF38();
                    sub_80124EC(data->field_11, gUnknown_02022C2D, data->field_13);
                }
                else
                {
                    data->state = 4;
                }
            }
            else
            {
                sub_8011DC0(data->field_0->arr[data->field_13].unk.playerName, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId));
                data->field_0->arr[data->field_13].field_1A_0 = 0;
                sub_8013398(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = 4;
            }

            data->field_19 = 0;
        }
        else if (val == 2)
        {
            sub_8011A64(0, 0);
            data->state = 4;
        }
        break;
    case 13:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 14;
        break;
    case 14:
        if (++data->field_E > 120)
            data->state = 17;
        break;
    case 15:
        if (PrintOnTextbox(&data->textState, gUnknown_082EDC5C))
            data->state = 16;
        break;
    case 16:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            data->state = 17;
            break;
        case 1:
        case -1:
            if ((gUnknown_02022C2D & 0xF0) != 0)
                data->state = 30;
            else
                data->state = 19;
            break;
        }
        break;
    case 19:
        if (PrintOnTextbox(&data->textState, gUnknown_082EDC78))
            data->state = 20;
        break;
    case 20:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            data->state = 23;
            break;
        case 1:
        case -1:
            if ((gUnknown_02022C2D & 0xF0) != 0)
                data->state = 15;
            else if (data->field_13 == (gUnknown_02022C2D & 0xF))
                data->state = 15;
            else
                data->state = 4;
            break;
        }
        break;
    case 17:
        if (!sub_801320C(data, 7, 29))
            data->state = 18;
        break;
    case 18:
        if (sub_800EF1C())
        {
            if (sub_800EF58(FALSE))
            {
                data->state = 26;
            }
            else
            {
                if (++data->field_1A > 300)
                {
                    data->state = 29;
                    data->textState = 0;
                }
            }
        }
        else
        {
            data->state = 29;
            data->textState = 0;
        }
        break;
    case 30:
        if (PrintOnTextbox(&data->textState, gUnknown_082EDD58))
            data->state = 23;
        break;
    case 21:
    case 23:
        sub_800E084();
        sub_800EDD4();
        sub_8012F64(data);
        data->state++;
        break;
    case 24:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = 5;
        break;
    case 22:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = 8;
        break;
    case 26:
        if (sub_8011A80())
        {
            data->state = 29;
        }
        else
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (sub_80126CC(gUnknown_02022C2C))
                    sub_801103C();
                sub_8011068(1);
                sub_80149C4();
                sub_8012F64(data);
                DestroyTask(taskId);
            }
        }
        break;
    }
}

void sub_8012F64(struct UnkStruct_Leader *data)
{
    ClearWindowTilemap(data->field_11);
    sub_819746C(data->field_11, FALSE);
    DestroyListMenuTask(data->listTaskId, 0, 0);
    ClearWindowTilemap(data->field_10);
    sub_819746C(data->listWindowId, FALSE);
    CopyBgTilemapBufferToVram(0);
    RemoveWindow(data->field_11);
    RemoveWindow(data->listWindowId);
    RemoveWindow(data->field_10);
    DestroyTask(data->field_17);

    Free(data->field_8);
    Free(data->field_0);
    Free(data->field_4);
}

void sub_8012FC4(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 1:
    case 2:
    case 4:
    case 14:
    case 28:
        StringExpandPlaceholders(dst, gUnknown_082EDBE8);
        break;
    case 21:
    case 22:
        StringExpandPlaceholders(dst, gUnknown_082EDC0C);
        break;
    case 3:
    case 9:
    case 10:
    case 11:
    case 15:
    case 16:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        StringExpandPlaceholders(dst, gUnknown_082EDC34);
        break;
    }
}

void sub_8013078(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 65:
    case 68:
        StringExpandPlaceholders(dst, gUnknown_082EE560);
        break;
    case 69:
    case 72:
        StringExpandPlaceholders(dst, gUnknown_082EE57C);
        break;
    }
}

void sub_80130B4(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 1:
    case 2:
    case 4:
    case 14:
    case 21:
    case 22:
    case 28:
        StringExpandPlaceholders(dst, gUnknown_082EFC3C);
        break;
    case 3:
    case 9:
    case 10:
    case 11:
    case 15:
    case 16:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        StringExpandPlaceholders(dst, gUnknown_082EFC54);
        break;
    }
}

void sub_8013160(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 1:
    case 2:
    case 4:
    case 14:
    case 21:
    case 22:
    case 28:
        StringExpandPlaceholders(dst, gUnknown_082EDDF4);
        break;
    case 3:
    case 9:
    case 10:
    case 11:
    case 15:
    case 16:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        StringExpandPlaceholders(dst, gUnknown_082EDE0C);
        break;
    }
}

bool8 sub_801320C(struct UnkStruct_Leader *data, u32 arg1, u32 arg2)
{
    switch (sub_80132D4(data->field_0))
    {
    case 1:
        PlaySE(SE_PC_LOGIN);
        RedrawListMenu(data->listTaskId);
        sub_8018404(gStringVar2, &data->field_0->arr[data->field_13]);
        sub_8012FC4(gStringVar4, gUnknown_02022C2C);
        data->state = arg1;
        break;
    case 2:
        sub_8011A64(0, 0);
        RedrawListMenu(data->listTaskId);
        data->state = arg2;
        return TRUE;
    }

    return FALSE;
}

void sub_8013278(u8 arg0, u32 id, u8 arg2)
{
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;
    u8 var = 0;

    switch (data->field_0->arr[id].field_1A_0)
    {
    case 1:
        if (data->field_0->arr[id].field_1B != 0)
            var = 2;
        break;
    case 2:
        var = 1;
        break;
    }

    sub_80178A0(arg0, 0, arg2, &data->field_0->arr[id], var, id);
}

u8 sub_80132D4(struct UnkStruct_Main0 *arg0)
{
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;
    u8 ret = 0;
    u8 i;
    s32 id;

    for (i = 1; i < 5; i++)
    {
        u16 var = data->field_0->arr[i].field_1A_0;
        if (var == 1)
        {
            id = sub_80176E4(&data->field_0->arr[i], data->field_4->arr);
            if (id != 0xFF)
            {
                data->field_0->arr[i].unk = data->field_4->arr[id].unk0;
                data->field_0->arr[i].field_18 = var;
            }
            else
            {
                data->field_0->arr[i].field_1A_0 = 2;
                ret = 2;
            }
        }
    }

    for (id = 0; id < 4; id++)
        sub_8017734(data->field_0->arr, &data->field_4->arr[id].unk0, 5);

    if (ret != 2)
    {
        for (id = 0; id < 5; id++)
        {
            if (data->field_0->arr[id].field_1B != 0)
                ret = 1;
        }
    }

    return ret;
}

u8 sub_8013398(struct UnkStruct_Main0 *arg0)
{
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;
    u8 copiedCount;
    s32 i;
    u8 ret;

    for (i = 0; i < 5; i++)
        data->field_8->arr[i] = data->field_0->arr[i];

    copiedCount = 0;
    for (i = 0; i < 5; i++)
    {
        if (data->field_8->arr[i].field_1A_0 == 1)
        {
            data->field_0->arr[copiedCount] = data->field_8->arr[i];
            copiedCount++;
        }
    }

    ret = copiedCount;
    for (; copiedCount < 5; copiedCount++)
    {
        data->field_0->arr[copiedCount].unk = gUnknown_082F045C;
        data->field_0->arr[copiedCount].field_18 = 0;
        data->field_0->arr[copiedCount].field_1A_0 = 0;
        data->field_0->arr[copiedCount].field_1A_1 = 0;
        data->field_0->arr[copiedCount].field_1B = 0;
    }

    for (i = 0; i < 5; i++)
    {
        if (data->field_0->arr[i].field_1A_0 != 1)
            continue;
        if (data->field_0->arr[i].field_1B != 0x40)
            continue;

        ret = i;
        break;
    }

    return ret;
}

void BerryBlenderLinkJoinGroup(void)
{
    u8 taskId;
    struct UnkStruct_Group *dataPtr;

    taskId = CreateTask(sub_80134E8, 0);
    gUnknown_02022C30.group = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_03000DA4 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    gSpecialVar_Result = 0;
}

void sub_80134E8(u8 taskId)
{
    s32 id;
    struct UnkStruct_Group *data = gUnknown_02022C30.group;

    switch (data->state)
    {
    case 0:
        if (gSpecialVar_0x8004 == 20 && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gUnknown_02022C2C = gUnknown_082F0530[gSpecialVar_0x8004];
        sub_8010F84(gUnknown_02022C2C, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C5C();
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0x200);
        data->state = 1;
        break;
    case 1:
        if (PrintOnTextbox(&data->textState, gUnknown_082EFB70[gSpecialVar_0x8004]))
            data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FC0(data->field_4, gSpecialVar_0x8004);
        data->field_C = AddWindow(&gUnknown_082F00BC);
        data->listWindowId = AddWindow(&gUnknown_082F0174);
        data->field_D = AddWindow(&gUnknown_082F017C);

        FillWindowPixelBuffer(data->field_C, 0x22);
        sub_80173E0(data->field_C, 0, gUnknown_082EF7DC, 8, 1, 4);
        PutWindowTilemap(data->field_C);
        CopyWindowToVram(data->field_C, 2);

        NewMenuHelpers_DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F0204;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        NewMenuHelpers_DrawStdWindowFrame(data->field_D, FALSE);
        PutWindowTilemap(data->field_D);
        sub_80125BC(data->field_D);
        CopyWindowToVram(data->field_D, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_F = 0;
        data->state = 3;
        break;
    case 3:
        id = sub_8013E44();
        switch (id)
        {
        case 1:
            PlaySE(SE_PC_LOGIN);
            RedrawListMenu(data->listTaskId);
            break;
        case 0:
            id = ListMenuHandleInputGetItemId(data->listTaskId);
            if (gMain.newKeys & A_BUTTON && id != -1)
            {
                // this unused variable along with the assignment is needed to match
                u32 unusedVar;
                unusedVar  = data->field_0->arr[id].unk.field_0.unk_0a_0;

                if (data->field_0->arr[id].field_1A_0 == 1 && !data->field_0->arr[id].unk.field_0.unk_0a_7)
                {
                    u32 var = sub_8013B8C(data, id);
                    if (var == 0)
                    {
                        sub_8013BD8(data, id);
                        data->state = 5;
                        PlaySE(SE_PN_ON);
                    }
                    else
                    {
                        StringCopy(gStringVar4, gUnknown_082EDD50[var - 1]);
                        data->state = 18;
                        PlaySE(SE_PN_ON);
                    }
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                data->state = 10;
            }
            break;
        default:
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case 5:
        sub_80130B4(gStringVar4, gUnknown_02022C2C);
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
            data->state = 6;
        }
        break;
    case 6:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            gUnknown_02022C2C = data->field_0->arr[data->field_F].unk.field_0.unk_0a_0;
            sub_8011A64(0, 0);
            switch (gUnknown_02022C2C)
            {
            case 1 ... 5:
            case 9 ... 11:
            case 13 ... 16:
            case 21 ... 28:
                data->state = 20;
                return;
            }
        }

        switch (sub_8011A74())
        {
        case 1:
            data->state = 12;
            break;
        case 2:
        case 6:
        case 9:
            data->state = 14;
            break;
        case 5:
            sub_8013160(gStringVar4, gUnknown_02022C2C);
            if (PrintOnTextbox(&data->textState, gStringVar4))
            {
                if (gUnknown_02022C2C == 28 || gUnknown_02022C2C == 14)
                {
                    sub_8011A64(12, 0);
                }
                else
                {
                    sub_8011A64(7, 0);
                    StringCopy(gStringVar1, gUnknown_082F0048[gUnknown_02022C2C]);
                    StringExpandPlaceholders(gStringVar4, gUnknown_082EDE48);
                }
            }
            break;
        case 7:
            if (data->field_15 > 0xF0)
            {
                if (PrintOnTextbox(&data->textState, gStringVar4))
                {
                    sub_8011A64(12, 0);
                    data->field_15 = 0;
                }
            }
            else
            {
                switch (gUnknown_02022C2C)
                {
                case 1:
                case 2:
                case 4:
                case 14:
                case 28:
                    break;
                default:
                    data->field_15++;
                    break;
                }
            }
            break;
        }

        if (!sub_8011A74() && gMain.newKeys & B_BUTTON)
            data->state = 7;
        break;
    case 7:
        if (PrintOnTextbox(&data->textState, gUnknown_082EDE64))
            data->state = 8;
        break;
    case 8:
        switch (sub_80170B8(&data->textState, sub_8011A74()))
        {
        case 0:
            sub_80106D4();
            data->state = 9;
            RedrawListMenu(data->listTaskId);
            break;
        case 1:
        case -1:
            data->state = 5;
            RedrawListMenu(data->listTaskId);
            break;
        case -3:
            data->state = 6;
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case 9:
        if (sub_8011A74())
            data->state = 6;
        break;
    case 10:
    case 12:
    case 14:
    case 18:
    case 20:
        ClearWindowTilemap(data->field_D);
        sub_819746C(data->field_D, FALSE);
        DestroyListMenuTask(data->listTaskId, 0, 0);
        ClearWindowTilemap(data->field_C);
        sub_819746C(data->listWindowId, FALSE);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->field_D);
        RemoveWindow(data->listWindowId);
        RemoveWindow(data->field_C);
        DestroyTask(data->field_11);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 13:
        sub_800E084();
        if (PrintOnTextbox(&data->textState, gUnknown_082EDE9C[sub_8011A74()]))
        {
            gSpecialVar_Result = 6;
            data->state = 23;
        }
        break;
    case 11:
        sub_800E084();
        gSpecialVar_Result = 5;
        data->state = 23;
        break;
    case 15:
        sub_800E084();
        if (PrintOnTextbox(&data->textState, gUnknown_082EDE9C[sub_8011A74()]))
        {
            gSpecialVar_Result = 8;
            data->state = 23;
        }
        break;
    case 19:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            gSpecialVar_Result = 8;
            data->state = 23;
        }
        break;
    case 23:
        DestroyTask(taskId);
        sub_80173D4();
        sub_800EDD4();
        break;
    case 21:
        sub_80149C4();
        DestroyTask(taskId);
        break;
    }
}

u32 sub_8013B8C(struct UnkStruct_Group *arg0, s32 id)
{
    struct UnkStruct_x20 *structPtr = &arg0->field_0->arr[id];

    if (gUnknown_02022C2C == 4 && structPtr->unk.field_0.unk_00.unk_01_2 != 3)
    {
        if (!(gSaveBlock2Ptr->specialSaveWarp & 0x80))
            return 1;
        else if (structPtr->unk.field_0.unk_00.unk_00_7)
            return 0;
    }
    else
    {
        return 0;
    }

    return 2;
}

void sub_8013BD8(struct UnkStruct_Group *data, s32 id)
{
    data->field_F = id;
    sub_800E0E8();
    CreateWirelessStatusIndicatorSprite(0, 0);
    RedrawListMenu(data->listTaskId);
    sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
    sub_8011090(gUnknown_082F0530[gSpecialVar_0x8004], 0, 1);
    sub_8011FC8(data->field_0->arr[data->field_F].unk.playerName, ReadAsU16(data->field_0->arr[data->field_F].unk.field_0.unk_00.playerTrainerId));
}

u8 sub_8013C40(void)
{
    u8 taskId;
    struct UnkStruct_Group *dataPtr;

    taskId = CreateTask(sub_8013C7C, 0);
    gUnknown_02022C30.group = dataPtr = (void*)(gTasks[taskId].data);

    dataPtr->state = 0;
    dataPtr->textState = 0;

    gUnknown_03000DA4 = dataPtr;

    return taskId;
}

void sub_8013C7C(u8 taskId)
{
    struct UnkStruct_Group *data = gUnknown_02022C30.group;

    switch (data->state)
    {
    case 0:
        sub_8010F84(0, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C5C();
        sub_80111B0(TRUE);
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0x200);
        data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FC0(data->field_4, 0xFF);
        data->field_F = 0;
        data->state = 3;
        break;
    case 3:
        if (sub_8013E44() == 1)
            PlaySE(SE_PC_LOGIN);
        if (gTasks[taskId].data[15] == 0xFF)
            data->state = 10;
        break;
    case 10:
        DestroyTask(data->field_11);
        Free(data->field_0);
        Free(data->field_4);
        sub_800EDD4();
        data->state++;
        break;
    case 11:
        sub_800EDD4();
        DestroyTask(taskId);
        break;
    }
}

bool32 sub_8013D88(u32 arg0, u32 id)
{
    if (id == 0xFF)
        return TRUE;

    if (id <= ARRAY_COUNT(gUnknown_082F04D8)) // UB: <= may access data outside the array
    {
        const u8 *bytes = gUnknown_082F04D8[id];

        while ((*(bytes) != 0xFF))
        {
            if ((*bytes) == arg0)
                return TRUE;
            bytes++;
        }
    }

    return FALSE;
}

u8 sub_8013DBC(struct UnkStruct_Group *data, u32 id)
{
    if (data->field_0->arr[id].field_1A_0 == 1)
    {
        if (data->field_0->arr[id].unk.field_0.unk_0a_7)
            return 3;
        else if (data->field_0->arr[id].field_1A_1 != 0)
            return 1;
        else if (data->field_0->arr[id].field_1B != 0)
            return 2;
    }

    return 0;
}

void sub_8013DF4(u8 arg0, u32 id, u8 arg2)
{
    struct UnkStruct_Group *data = gUnknown_02022C30.group;
    u8 var = sub_8013DBC(data, id);

    sub_80177B8(arg0, 8, arg2, &data->field_0->arr[id], var, id);
}

u8 sub_8013E44(void)
{
    struct UnkStruct_Group *data = gUnknown_02022C30.group;
    u8 ret = 0;
    u8 i;
    s32 id;

    for (i = 0; i < 16; i++)
    {
        if (data->field_0->arr[i].field_1A_0 != 0)
        {
            id = sub_80176E4(&data->field_0->arr[i], data->field_4->arr);
            if (id != 0xFF)
            {
                if (data->field_0->arr[i].field_1A_0 == 1)
                {
                    if (sub_8017678(&data->field_0->arr[i], &data->field_4->arr[id]))
                    {
                        data->field_0->arr[i].unk = data->field_4->arr[id].unk0;
                        data->field_0->arr[i].field_1B = 0x40;
                        ret = 1;
                    }
                    else
                    {
                        if (data->field_0->arr[i].field_1B != 0)
                        {
                            data->field_0->arr[i].field_1B--;
                            if (data->field_0->arr[i].field_1B == 0)
                                ret = 2;
                        }
                    }
                }
                else
                {
                    data->field_0->arr[i].field_1A_0 = 1;
                    data->field_0->arr[i].field_1B = 0x40;
                    ret = 1;
                }

                data->field_0->arr[i].field_18 = 0;
            }
            else
            {
                if (data->field_0->arr[i].field_1A_0 != 2)
                {
                    data->field_0->arr[i].field_18++;
                    if (data->field_0->arr[i].field_18 >= 300)
                    {
                        data->field_0->arr[i].field_1A_0 = 2;
                        ret = 2;
                    }
                }
            }
        }
    }

    for (id = 0; id < 4; id++)
    {
        if (sub_8017734(data->field_0->arr, &data->field_4->arr[id].unk0, 16) != 0xFF)
            ret = 1;
    }

    return ret;
}

void sub_8013F60(u8 taskId)
{
    sub_80773AC();
    DestroyTask(taskId);
}

u8 sub_8013F78(void)
{
    u8 taskId = CreateTask(sub_8013F60, 0);

    return taskId;
}

void sub_8013F90(u8 taskId)
{
    u32 monId = sub_8018120(&gUnknown_02022C40, GetMultiplayerId());

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gTasks[taskId].data[0]++;
        SendBlock(0, &gPlayerParty[monId], sizeof(struct Pokemon));
        break;
    case 1:
        if (GetBlockReceivedStatus() == 3)
        {
            gEnemyParty[0] = *(struct Pokemon*)(gBlockRecvBuffer[GetMultiplayerId() ^ 1]);
            IncrementGameStat(GAME_STAT_50);
            ResetBlockReceivedFlags();
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, sizeof(struct MailStruct) * PARTY_SIZE + 4);
        if (SendBlock(0, gBlockSendBuffer, sizeof(struct MailStruct) * PARTY_SIZE + 4))
            gTasks[taskId].data[0]++;
        break;
    case 3:
        if (GetBlockReceivedStatus() == 3)
        {
            memcpy(gUnknown_020321C0, gBlockRecvBuffer[GetMultiplayerId() ^ 1], sizeof(struct MailStruct) * PARTY_SIZE);
            ResetBlockReceivedFlags();
            gUnknown_02032298[0] = monId;
            gUnknown_02032298[1] = 6;
            gMain.savedCallback = CB2_ReturnToField;
            SetMainCallback2(sub_807AE50);
            sub_801807C(&gUnknown_02022C40);
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_80140E0(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (GetMultiplayerId() == 0)
            sub_800A4D8(2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (GetBlockReceivedStatus() == sub_800A9D8())
        {
            s32 i;
            u16 *recvBuff;

            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                recvBuff = gBlockRecvBuffer[i];
                sub_80C3120(&gTrainerCards[i], recvBuff, gLinkPlayers[i].version);
            }

            if (GetLinkPlayerCount() == 2)
            {
                recvBuff = gBlockRecvBuffer[GetMultiplayerId() ^ 1];
                sub_801B94C(recvBuff[48]);
            }
            else
            {
                sub_801B940();
            }

            ResetBlockReceivedFlags();
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_80141A4(void)
{
    switch (gMain.state)
    {
    case 0:
        CreateTask(sub_80140E0, 5);
        gMain.state++;
        break;
    case 1:
        if (!FuncIsActiveTask(sub_80140E0))
            TrainerCard_ShowLinkCard(GetMultiplayerId() ^ 1, CB2_ReturnToField);
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

void sub_8014210(u16 battleFlags)
{
    HealPlayerParty();
    SavePlayerParty();
    LoadPlayerBag();
    gLinkPlayers[0].linkType = 0x2211;
    gLinkPlayers[GetMultiplayerId()].id = GetMultiplayerId();
    gLinkPlayers[GetMultiplayerId() ^ 1].id = GetMultiplayerId() ^ 1;
    gMain.savedCallback = sub_80B360C;
    gBattleTypeFlags = battleFlags;
    PlayBattleBGM();
}

void sub_8014290(u16 arg0, u16 x, u16 y)
{
    VarSet(VAR_0x4087, arg0);
    Overworld_SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    saved_warp2_set_2(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    WarpIntoMap();
}

void sub_8014304(s8 mapGroup, s8 mapNum, s32 x, s32 y, u16 arg4)
{
    gSpecialVar_0x8004 = arg4;
    VarSet(VAR_0x4087, arg4);
    gFieldLinkPlayerCount = GetLinkPlayerCount();
    gUnknown_03005DB4 = GetMultiplayerId();
    SetCableClubWarp();
    Overworld_SetWarpDestination(mapGroup, mapNum, -1, x, y);
    WarpIntoMap();
}

void sub_8014384(void)
{
    switch (gMain.state)
    {
    case 0:
        CreateTask(sub_80140E0, 5);
        gMain.state++;
        break;
    case 1:
        if (!FuncIsActiveTask(sub_80140E0))
            SetMainCallback2(sub_8086074);
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

void sub_80143E4(void *arg0, bool32 arg1)
{
    u16 *argAsU16Ptr = arg0;

    TrainerCard_GenerateCardForPlayer((struct TrainerCard *)argAsU16Ptr);
    if (arg1)
        argAsU16Ptr[48] = sub_801B39C();
    else
        argAsU16Ptr[48] = 0;
}

void sub_801440C(u8 taskId)
{
    sub_801B940();
    switch (gUnknown_02022C2C)
    {
    case 1 ... 4:
    case 9 ... 11:
    case 13:
    case 15:
        sub_800E3A8();
        break;
    }

    switch (gUnknown_02022C2C)
    {
    case 65:
    case 81:
        overworld_free_bg_tilemaps();
        gMain.savedCallback = sub_801AC54;
        sub_81B8518(3);
        break;
    case 1:
        overworld_free_bg_tilemaps();
        sub_80143E4(gBlockSendBuffer, TRUE);
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_8014304(MAP_GROUP(SINGLE_BATTLE_COLOSSEUM), MAP_NUM(SINGLE_BATTLE_COLOSSEUM), 6, 8, 1);
        SetMainCallback2(sub_8014384);
        break;
    case 2:
        overworld_free_bg_tilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_80143E4(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(SINGLE_BATTLE_COLOSSEUM), MAP_NUM(SINGLE_BATTLE_COLOSSEUM), 6, 8, 2);
        SetMainCallback2(sub_8014384);
        break;
    case 3:
        overworld_free_bg_tilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_80143E4(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(DOUBLE_BATTLE_COLOSSEUM), MAP_NUM(DOUBLE_BATTLE_COLOSSEUM), 5, 8, 5);
        SetMainCallback2(sub_8014384);
        break;
    case 4:
        sub_80143E4(gBlockSendBuffer, TRUE);
        overworld_free_bg_tilemaps();
        sub_8014304(MAP_GROUP(TRADE_CENTER), MAP_NUM(TRADE_CENTER), 5, 8, 3);
        SetMainCallback2(sub_8014384);
        break;
    case 15:
        sub_80143E4(gBlockSendBuffer, TRUE);
        overworld_free_bg_tilemaps();
        sub_8014304(MAP_GROUP(RECORD_CORNER), MAP_NUM(RECORD_CORNER), 8, 9, 4);
        SetMainCallback2(sub_8014384);
        break;
    case 68:
        overworld_free_bg_tilemaps();
        CreateTask(sub_8013F90, 0);
        break;
    case 5:
    case 69:
        if (GetMultiplayerId() == 0)
        {
            sub_800ED10();
        }
        else
        {
            sub_800ED28();
            sub_8010F84(69, 0, 1);
        }
        sub_801DD98();
        break;
    case 8:
    case 72:
        sub_80143E4(gBlockSendBuffer, FALSE);
        SetMainCallback2(sub_80141A4);
        break;
    case 9:
        sub_8014290(8, 5, 1);
        sub_802A9A8(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    case 10:
        sub_8014290(7, 9, 1);
        sub_8020C70(CB2_LoadMap);
        break;
    case 11:
        sub_8014290(8, 5, 1);
        sub_802493C(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    }

    DestroyTask(taskId);
    gSpecialVar_Result = 1;
    if (gUnknown_02022C2C != 68)
        ScriptContext2_Disable();
}

void sub_8014790(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *sendBuff = (u16*)(gBlockSendBuffer);

    switch (data[0])
    {
    case 0:
        gSpecialVar_Result = 1;
        switch (gUnknown_02022C2C)
        {
        case 14:
        case 28:
            gLinkPlayers[0].linkType = 0x2211;
            gLinkPlayers[0].id = 0;
            gLinkPlayers[1].id = 2;
            sendBuff[0] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[0] - 1], MON_DATA_SPECIES);
            sendBuff[1] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[1] - 1], MON_DATA_SPECIES, NULL);
            gMain.savedCallback = NULL;
            data[0] = 4;
            sub_800E3A8();
            ResetBlockReceivedFlags();
            break;
        case 16:
        case 23 ... 27:
            sub_800E3A8();
            DestroyTask(taskId);
        default:
            EnableBothScriptContexts();
            data[0] = 1;
            break;
        }
        break;
    case 1:
        if (!ScriptContext1_IsScriptSetUp())
        {
            FadeScreen(1, 0);
            data[0] = 2;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            if (gUnknown_02022C2C == 29)
            {
                DestroyTask(taskId);
                SetMainCallback2(sub_80773AC);
            }
            else
            {
                sub_800ADF8();
                data[0] = 3;
            }
        }
        break;
    case 3:
        if (sub_800A520())
        {
            DestroyTask(taskId);
            sub_80149D8();
        }
        break;
    case 4:
        if (SendBlock(0, gBlockSendBuffer, 0xE))
            data[0] = 5;
        break;
    case 5:
        if (GetBlockReceivedStatus() == 3)
        {
            ResetBlockReceivedFlags();
            if (sub_80B2AF4(gBlockRecvBuffer[0], gBlockRecvBuffer[1]))
            {
                gSpecialVar_Result = 11;
                data[0] = 7;
            }
            else
            {
                data[0] = 6;
            }
        }
        break;
    case 6:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        break;
    case 7:
        sub_800AC34();
        data[0] = 8;
        break;
    case 8:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            sub_800E084();
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_80149C4(void)
{
    CreateTask(sub_8014790, 0);
}

void sub_80149D8(void)
{
    u8 taskId = CreateTask(sub_801440C, 0);
    gTasks[taskId].data[0] = 0;
}

void sub_8014A00(u32 arg0)
{
    u8 taskId;
    struct UnkStruct_Leader *dataPtr;

    taskId = CreateTask(sub_8014A40, 0);
    gUnknown_02022C30.leader = dataPtr = (void*)(gTasks[taskId].data);

    dataPtr->state = 0;
    dataPtr->textState = 0;
    dataPtr->field_18 = arg0;
    gSpecialVar_Result = 0;
}

void sub_8014A40(u8 taskId)
{
    struct UnkStruct_Leader *data = gUnknown_02022C30.leader;
    struct WindowTemplate winTemplate;
    s32 val;

    switch (data->state)
    {
    case 0:
        gUnknown_02022C2C = data->field_18;
        gUnknown_02022C2D = 2;
        sub_8010F84(data->field_18, 0, 0);
        sub_8010FA0(FALSE, FALSE);
        sub_800B488();
        OpenLink();
        sub_8011C10(2);
        data->state = 1;
        break;
    case 1:
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0xA0);
        data->field_8 = AllocZeroed(0xA0);
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 5);
        sub_800DF90(&data->field_0->arr[0].unk.field_0, data->field_0->arr[0].unk.playerName);
        data->field_0->arr[0].field_18 = 0;
        data->field_0->arr[0].field_1A_0 = 1;
        data->field_0->arr[0].field_1A_1 = 0;
        data->field_0->arr[0].field_1B = 0;
        data->field_17 = sub_8016FC0(data->field_4, 0xFF);

        winTemplate = gUnknown_082F011C;
        winTemplate.baseBlock = sub_8019930();
        winTemplate.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate);
        sub_8018784(data->listWindowId);
        gMultiuseListMenuTemplate = gUnknown_082F015C;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->state = 2;
        break;
    case 2:
        StringCopy(gStringVar1, gUnknown_082F0048[gUnknown_02022C2C]);
        sub_801262C(gStringVar4, gUnknown_02022C2C);
        data->state = 3;
        break;
    case 3:
        sub_8018884(gStringVar4);
        data->state = 4;
        break;
    case 4:
        sub_801320C(data, 5, 6);
        if (gMain.newKeys & B_BUTTON)
        {
            data->state = 13;
            sub_800E084();
        }
        break;
    case 6:
        if (mevent_0814257C(&data->textState, gUnknown_082EDF40))
        {
            data->field_13 = sub_8013398(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = 2;
        }
        break;
    case 5:
        data->state = 7;
        break;
    case 7:
        switch (sub_8018B08(&data->textState, &data->field_14, 0, gStringVar4))
        {
        case 0:
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->field_0->arr[data->field_13].field_1B = 0;
            RedrawListMenu(data->listTaskId);
            data->field_19 = 5;
            sub_8010688(5, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 8;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            sub_8010688(6, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 8;
            break;
        }
        break;
    case 8:
        val = sub_8010714(ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->field_13].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->field_13++;
                sub_8018404(gStringVar1, &data->field_0->arr[data->field_13 - 1]);
                StringExpandPlaceholders(gStringVar4, gUnknown_082EDC9C);
                data->state = 9;
                sub_800EF38();
            }
            else
            {
                sub_8011DC0(data->field_0->arr[data->field_13].unk.playerName, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId));
                data->field_0->arr[data->field_13].field_1A_0 = 0;
                sub_8013398(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = 2;
            }

            data->field_19 = 0;
        }
        else if (val == 2)
        {
            sub_8011A64(0, 0);
            data->state = 2;
        }
        break;
    case 9:
        sub_8018884(gStringVar4);
        data->state = 10;
        break;
    case 10:
        if (++data->field_E > 120)
            data->state = 11;
        break;
    case 11:
        if (!sub_801320C(data, 5, 6))
            data->state = 12;
        break;
    case 12:
        if (sub_800EF1C())
        {
            sub_800EF58(FALSE);
            data->state = 15;
        }
        else
        {
            data->state = 6;
        }
        break;
    case 13:
        sub_800E084();
        sub_800EDD4();
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->field_17);
        Free(data->field_8);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 14:
        if (mevent_0814257C(&data->textState, gText_PleaseStartOver))
        {
            DestroyTask(taskId);
            gSpecialVar_Result = 5;
        }
        break;
    case 15:
        if (sub_8011A74() == 1 || sub_8011A74() == 2)
        {
            data->state = 13;
        }
        else if (gReceivedRemoteLinkPlayers != 0)
        {
            sub_8011068(1);
            data->state++;
        }
        break;
    case 16:
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->field_17);
        Free(data->field_8);
        Free(data->field_0);
        Free(data->field_4);
        sub_800ADF8();
        data->state++;
        break;
    case 17:
        if (sub_800A520())
            DestroyTask(taskId);
        break;
    }
}

void sub_8014EFC(u32 arg0)
{
    u8 taskId;
    struct UnkStruct_Group *dataPtr;

    taskId = CreateTask(sub_8014F48, 0);
    gUnknown_02022C30.group = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_03000DA4 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    dataPtr->field_12 = arg0 - 21;
    gSpecialVar_Result = 0;
}

void sub_8014F48(u8 taskId)
{
    s32 id;
    struct WindowTemplate winTemplate1, winTemplate2;
    struct UnkStruct_Group *data = gUnknown_02022C30.group;

    switch (data->state)
    {
    case 0:
        sub_8010F84(data->field_12 + 21, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C5C();
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0x200);
        data->state = 1;
        break;
    case 1:
        sub_8018884(gUnknown_082EF7F8);
        data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FC0(data->field_4, data->field_12 + 7);

        winTemplate1 = gUnknown_082F0174;
        winTemplate1.baseBlock = sub_8019930();
        winTemplate1.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate1);

        winTemplate2 = gUnknown_082F017C;
        winTemplate2.paletteNum = 0xC;
        data->field_D = AddWindow(&winTemplate2);

        sub_8018784(data->listWindowId);
        gMultiuseListMenuTemplate = gUnknown_082F0204;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        sub_8018784(data->field_D);
        FillWindowPixelBuffer(data->field_D, 0x11);
        PutWindowTilemap(data->field_D);
        sub_80125BC(data->field_D);
        CopyWindowToVram(data->field_D, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_F = 0;
        data->state = 3;
        break;
    case 3:
        id = sub_8013E44();
        switch (id)
        {
        case 1:
            PlaySE(SE_PC_LOGIN);
        default:
            RedrawListMenu(data->listTaskId);
            break;
        case 0:
            id = ListMenuHandleInputGetItemId(data->listTaskId);
            if (gMain.newKeys & A_BUTTON && id != -1)
            {
                // this unused variable along with the assignment is needed to match
                u32 unusedVar;
                unusedVar  = data->field_0->arr[id].unk.field_0.unk_0a_0;

                if (data->field_0->arr[id].field_1A_0 == 1 && !data->field_0->arr[id].unk.field_0.unk_0a_7)
                {
                    data->field_F = id;
                    sub_800E0E8();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                    RedrawListMenu(data->listTaskId);
                    sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
                    sub_8011FC8(data->field_0->arr[data->field_F].unk.playerName, ReadAsU16(data->field_0->arr[data->field_F].unk.field_0.unk_00.playerTrainerId));
                    PlaySE(SE_PN_ON);
                    data->state = 4;
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                data->state = 6;
            }
            break;
        }
        break;
    case 4:
        sub_8018884(gUnknown_082EFC3C);
        sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
        data->state = 5;
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            gUnknown_02022C2C = data->field_0->arr[data->field_F].unk.field_0.unk_0a_0;
            data->state = 10;
        }

        switch (sub_8011A74())
        {
        case 1:
        case 2:
        case 6:
            data->state = 8;
            break;
        case 5:
            sub_8018884(gUnknown_082EDDF4);
            sub_8011A64(0, 0);
            break;
        }
        break;
    case 6:
    case 8:
    case 10:
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->field_D);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->field_11);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 9:
        if (mevent_0814257C(&data->textState, gUnknown_082EDF80[sub_8011A74()]))
        {
            sub_800E084();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        sub_800E084();
        sub_8018884(gText_PleaseStartOver);
        DestroyTask(taskId);
        sub_800EDD4();
        gSpecialVar_Result = 5;
        break;
    case 11:
        data->state++;
        sub_800ADF8();
        break;
    case 12:
        if (sub_800A520())
            DestroyTask(taskId);
        break;
    }
}

void sub_80152A8(u32 arg0)
{
    u8 taskId;
    struct UnkStruct_Group *dataPtr;

    taskId = CreateTask(sub_80152F4, 0);
    gUnknown_02022C30.group = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_03000DA4 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    dataPtr->field_12 = arg0 - 21;
    gSpecialVar_Result = 0;
}

void sub_80152F4(u8 taskId)
{
    s32 id;
    struct WindowTemplate winTemplate;
    struct UnkStruct_Group *data = gUnknown_02022C30.group;

    switch (data->state)
    {
    case 0:
        sub_8010F84(0, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C5C();
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0x200);
        data->state = 1;
        break;
    case 1:
        sub_8018884(gUnknown_082EFBC8);
        data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FF0(data->field_4, data->field_12 + 7);

        if (data->field_13 != 0)
        {
            winTemplate = gUnknown_082F0174;
            winTemplate.baseBlock = sub_8019930();
            data->listWindowId = AddWindow(&winTemplate);

            sub_8018784(data->listWindowId);
            gMultiuseListMenuTemplate = gUnknown_082F0204;
            gMultiuseListMenuTemplate.windowId = data->listWindowId;
            data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

            CopyBgTilemapBufferToVram(0);
        }

        data->field_F = 0;
        data->state = 3;
        break;
    case 3:
        id = sub_8013E44();
        switch (id)
        {
        case 1:
            PlaySE(SE_PC_LOGIN);
        default:
            if (data->field_13 != 0)
                RedrawListMenu(data->listTaskId);
            break;
        case 0:
            if (data->field_13 != 0)
                id = ListMenuHandleInputGetItemId(data->listTaskId);
            if (data->field_14 > 120)
            {
                if (data->field_0->arr[0].field_1A_0 == 1 && !data->field_0->arr[0].unk.field_0.unk_0a_7)
                {
                    if (sub_8016F1C(&data->field_0->arr[0], data->field_12 + 7))
                    {
                        data->field_F = 0;
                        data->field_14 = 0;
                        sub_800E0E8();
                        CreateWirelessStatusIndicatorSprite(0, 0);
                        sub_8011FC8(data->field_0->arr[0].unk.playerName, ReadAsU16(data->field_0->arr[0].unk.field_0.unk_00.playerTrainerId));
                        PlaySE(SE_PN_ON);
                        data->state = 4;
                    }
                    else
                    {
                        PlaySE(SE_BOO);
                        data->state = 10;
                    }
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                data->state = 6;
                data->field_14 = 0;
            }
            data->field_14++;
            break;
        }
        break;
    case 4:
        sub_8018884(gUnknown_082EFC90);
        sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
        data->state = 5;
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            gUnknown_02022C2C = data->field_0->arr[data->field_F].unk.field_0.unk_0a_0;
            data->state = 12;
        }

        switch (sub_8011A74())
        {
        case 1:
        case 2:
        case 6:
            data->state = 8;
            break;
        case 5:
            sub_8018884(gUnknown_082EDEC4);
            sub_8011A64(0, 0);
            break;
        }
        break;
    case 6:
    case 8:
    case 10:
    case 12:
        if (data->field_13 != 0)
        {
            DestroyListMenuTask(data->listTaskId, 0, 0);
            CopyBgTilemapBufferToVram(0);
            RemoveWindow(data->listWindowId);
        }
        DestroyTask(data->field_11);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 9:
        if (mevent_0814257C(&data->textState, gUnknown_082EDF04))
        {
            sub_800E084();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        if (mevent_0814257C(&data->textState, gText_WirelessSearchCanceled))
        {
            sub_800E084();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 11:
        if (mevent_0814257C(&data->textState, gUnknown_082EFD58[data->field_12]))
        {
            sub_800E084();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 13:
        data->state++;
        sub_800ADF8();
        break;
    case 14:
        if (sub_800A520())
            DestroyTask(taskId);
        break;
    }
}

void UnionRoomSpecial(void)
{
    struct UnkStruct_URoom *dataPtr;

    sub_8010F60();
    CreateTask(sub_80156E0, 10);

    // dumb line needed to match
    gUnknown_02022C30.uRoom = gUnknown_02022C30.uRoom;

    dataPtr = AllocZeroed(0x26C);
    gUnknown_02022C30.uRoom = dataPtr;
    gUnknown_03000DA8 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    dataPtr->field_10 = 0;
    dataPtr->field_12 = 0;

    gSpecialVar_Result = 0;
    sub_819A2BC(0xD0, 1);
}

u16 ReadAsU16(const u8 *ptr)
{
    return (ptr[1] << 8) | (ptr[0]);
}

void sub_8015664(u32 arg0, const u8 *src)
{
    struct UnkStruct_URoom *data = gUnknown_02022C30.uRoom;

    data->state = 8;
    data->stateAfterPrint = arg0;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

void sub_801568C(const u8 *src)
{
    struct UnkStruct_URoom *data = gUnknown_02022C30.uRoom;

    data->state = 26;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

void sub_80156B0(struct UnkStruct_URoom *data)
{
    memcpy(&gDecompressionBuffer[0x3F00], data->field_0, 0x100);
}

void sub_80156C8(struct UnkStruct_URoom *data)
{
    memcpy(data->field_0, &gDecompressionBuffer[0x3F00], 0x100);
}

void sub_80156E0(u8 taskId)
{
    u32 id = 0;
    s32 var5 = 0;
    s32 playerGender = 0;
    struct UnkStruct_URoom *data = gUnknown_02022C30.uRoom;
    s16 *taskData = gTasks[taskId].data;

    switch (data->state)
    {
    case 0:
        data->field_4 = AllocZeroed(0x70);
        data->field_C = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0x100);
        data->field_8 = AllocZeroed(0x20);
        sub_8017580(data->field_0->arr, 8);
        gUnknown_02022C2C = 0x40;
        data->field_20 = sub_8016DF0(data->field_C, data->field_4, 9);
        sub_8019BA8(data->field_A0);
        sub_8019F2C();
        data->state = 1;
        break;
    case 1:
        sub_8019E70(data->spriteIds, taskData[0]);
        if (++taskData[0] == 8)
            data->state = 2;
        break;
    case 2:
        sub_8010F84(0x40, 0, 0);
        sub_8010FCC(gUnknown_02022C40.field_2, gUnknown_02022C40.field_A, gUnknown_02022C40.field_C);
        sub_800B488();
        OpenLink();
        sub_8011C84();
        sub_8017580(&data->field_8->arr[0], 1);
        sub_80175EC(data->field_4, 4);
        sub_80175EC(data->field_C, 4);
        gSpecialVar_Result = 0;
        data->state = 3;
        break;
    case 3:
        if ((sub_81B1360() == 8 || sub_81B1360() == 9) && gUnknown_02022C40.field_0 != 0)
        {
            id = GetCursorSelectionMonId();
            switch (gUnknown_02022C40.field_0)
            {
            case 1:
                sub_8011090(0x54, 0, 1);
                if (id >= PARTY_SIZE)
                {
                    sub_801807C(&gUnknown_02022C40);
                    sub_8010FCC(0, 0, 0);
                    sub_801568C(gUnknown_082EF4FC);
                }
                else if (!sub_80180A0(GetCursorSelectionMonId(), &gUnknown_02022C40))
                {
                    sub_8015664(0x34, gUnknown_082EF47C);
                }
                else
                {
                    data->state = 55;
                }
                break;
            case 2:
                sub_80156C8(data);
                taskData[1] = gUnknown_02022C40.field_8;
                if (id >= PARTY_SIZE)
                {
                    sub_801568C(gUnknown_082EF544);
                }
                else
                {
                    sub_8011090(0x54, 0, 1);
                    gUnknown_02022C2C = 0x44;
                    sub_80180E8(GetCursorSelectionMonId(), &gUnknown_02022C40);
                    data->state = 51;
                }
                break;
            }
            gUnknown_02022C40.field_0 = 0;
        }
        else
        {
            data->state = 4;
        }
        break;
    case 4:
        if (gSpecialVar_Result != 0)
        {
            if (gSpecialVar_Result == 9)
            {
                sub_8011090(0x54, 0, 1);
                PlaySE(SE_PC_LOGIN);
                StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                data->state = 42;
                gSpecialVar_Result = 0;
            }
            else if (gSpecialVar_Result == 11)
            {
                sub_8011090(0x54, 0, 1);
                data->state = 23;
                gSpecialVar_Result = 0;
            }
            else
            {
                taskData[0] = 0;
                taskData[1] = gSpecialVar_Result - 1;
                data->state = 24;
                gSpecialVar_Result = 0;
            }
        }
        else if (ScriptContext2_IsEnabled() != TRUE)
        {
            if (gMain.newKeys & A_BUTTON)
            {
                if (sub_801A2A8(data->field_0, &taskData[0], &taskData[1], data->spriteIds))
                {
                    PlaySE(SE_SELECT);
                    sub_80181CC();
                    data->state = 24;
                    break;
                }
                else if (sub_8017940())
                {
                    sub_8011090(0x54, 0, 1);
                    PlaySE(SE_PC_LOGIN);
                    sub_80181CC();
                    StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                    data->state = 45;
                    break;
                }
            }

            switch (sub_8016B00())
            {
            case 1:
                PlaySE(SE_PC_LOGIN);
            case 2:
                sub_801A274(data);
                break;
            case 4:
                data->state = 11;
                sub_80181CC();
                sub_8010FCC(0, 0, 0);
                sub_8011090(0x53, sub_80181DC(data), 0);
                break;
            }
            sub_801A284(data);
        }
        break;
    case 23:
        if (!FuncIsActiveTask(sub_809FA34))
        {
            sub_8011090(0x40, 0, 0);
            data->state = 4;
        }
        break;
    case 24:
        sub_801704C();
        playerGender = sub_8017CF8(taskData[1], data->field_0);
        sub_8011090(0x54, 0, 1);
        switch (sub_80179D4(data->field_0, taskData[0], taskData[1], playerGender))
        {
        case 0:
            data->state = 26;
            break;
        case 1:
            sub_8012188(data->field_0->arr[taskData[1]].unk.playerName, &data->field_0->arr[taskData[1]].unk.field_0, gUnknown_02022C2C);
            data->field_12 = id; // Should be just 0, but won't match any other way.
            data->state = 25;
            break;
        case 2:
            sub_8015664(0x13, gStringVar4);
            break;
        }
        break;
    case 25:
        sub_801704C();
        switch (sub_8011A74())
        {
        case 4:
            sub_801818C(TRUE);
            data->state = 4;
            break;
        case 1:
        case 2:
            if (sub_8011B90() == TRUE)
                sub_801568C(gUnknown_082EE6C8);
            else
                sub_8015664(30, gUnknown_082EE6C8);

            gUnknown_02022C2C = 0x40;
            break;
        }

        if (gReceivedRemoteLinkPlayers != 0)
        {
            sub_80143E4(gBlockSendBuffer, TRUE);
            CreateTask(sub_80140E0, 5);
            data->state = 38;
        }
        break;
    case 38:
        if (!FuncIsActiveTask(sub_80140E0))
        {
            if (gUnknown_02022C2C == 0x44)
                sub_8015664(31, gUnknown_082EE004);
            else
                data->state = 5;
        }
        break;
    case 30:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            sub_801818C(FALSE);
            sub_801A3D0(taskData[0], taskData[1], data->field_0);
            data->state = 2;
        }
        break;
    case 5:
        id = sub_80179AC(&data->field_0->arr[taskData[1]]);
        playerGender = sub_8017CF8(taskData[1], data->field_0);
        sub_8015664(6, gUnknown_082EE24C[id][playerGender]);
        break;
    case 6:
        var5 = sub_8017178(&data->textState, &data->field_1B, &data->field_1C, &gUnknown_082F021C, &gUnknown_082F0244);
        if (var5 != -1)
        {
            if (gReceivedRemoteLinkPlayers == 0)
            {
                data->state = 28;
            }
            else
            {
                data->field_98 = 0;
                playerGender = sub_8017CF8(taskData[1], data->field_0);
                if (var5 == -2 || var5 == 0x40)
                {
                    data->field_4C[0] = 0x40;
                    sub_800FE50(data->field_4C);
                    StringCopy(gStringVar4, gUnknown_082EEB80[gLinkPlayers[0].gender]);
                    data->state = 32;
                }
                else
                {
                    gUnknown_02022C2C = var5;
                    gUnknown_02022C2D = (u32)(var5) >> 8;
                    if (gUnknown_02022C2C == 0x41 && !sub_8018024())
                    {
                        sub_8015664(5, gUnknown_082EEBD0);
                    }
                    else
                    {
                        data->field_4C[0] = gUnknown_02022C2C | 0x40;
                        sub_800FE50(data->field_4C);
                        data->state = 27;
                    }
                }
            }
        }
        break;
    case 28:
        StringCopy(gStringVar4, gUnknown_082EEB88);
        data->state = 36;
        break;
    case 27:
        sub_8017FD8(data);
        playerGender = sub_8017CF8(taskData[1], data->field_0);
        id = sub_8017984(data->field_4C[0] & 0x3F);
        if (PrintOnTextbox(&data->textState, gUnknown_082EE82C[playerGender][id]))
        {
            taskData[3] = 0;
            data->state = 29;
        }
        break;
    case 32:
        sub_800AC34();
        data->state = 36;
        break;
    case 31:
        data->field_4C[0] = 0x44;
        data->field_4C[1] = gUnknown_02022C40.species;
        data->field_4C[2] = gUnknown_02022C40.level;
        sub_800FE50(data->field_4C);
        data->state = 29;
        break;
    case 29:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            StringCopy(gStringVar4, gUnknown_082EEB88);
            data->state = 28;
        }
        else
        {
            sub_8017FD8(data);
            if (data->field_98 == 0x51)
            {
                if (gUnknown_02022C2C == 8)
                {
                    sub_8018220(gStringVar4, data, FALSE);
                    data->state = 40;
                }
                else
                {
                    data->state = 13;
                }
            }
            else if (data->field_98 == 0x52)
            {
                data->state = 32;
                sub_8017D9C(gStringVar4, gUnknown_02022C2C | 0x40, gLinkPlayers[0].gender);
                gUnknown_02022C2C = 0;
            }
        }
        break;

    case 7:
        id = sub_80179AC(&data->field_0->arr[taskData[1]]);
        playerGender = sub_8017CF8(taskData[1], data->field_0);
        sub_8015664(6, gUnknown_082EE24C[id][playerGender]);
        break;
    case 40:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            data->state = 41;
            sub_800ADF8();
            data->field_98 = 0;
            data->field_9A[0] = 0;
        }
        break;
    case 41:
        if (sub_800A520())
        {
            if (GetMultiplayerId() == 0)
            {
                StringCopy(gStringVar1, gLinkPlayers[GetMultiplayerId() ^ 1].name);
                id = sub_800E540(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
                StringExpandPlaceholders(gStringVar4, gUnknown_082EE378[id]);
                data->state = 33;
            }
            else
            {
                data->state = 7;
            }
        }
        break;
    case 19:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022C2C = 0x45;
            sub_8011090(0x45, 0, 1);
            sub_8012188(data->field_0->arr[taskData[1]].unk.playerName, &data->field_0->arr[taskData[1]].unk.field_0, gUnknown_02022C2C);
            data->field_12 = taskData[1];
            data->state = 20;
            taskData[3] = 0;
            break;
        case 1:
        case -1:
            playerGender = sub_8017CF8(taskData[1], data->field_0);
            sub_801568C(gUnknown_082EEC9C[playerGender]);
            break;
        }
        break;
    case 20:
        if (++taskData[2] > 60)
        {
            data->state = 21;
            taskData[2] = 0;
        }
        break;
    case 21:
        switch (sub_8011A74())
        {
        case 4:
            sub_801818C(TRUE);
            data->state = 4;
            break;
        case 1:
        case 2:
            playerGender = sub_8017CF8(taskData[1], data->field_0);
            sub_8011090(0x54, 0, 1);
            if (sub_8011B90() == TRUE)
                sub_801568C(gUnknown_082EED3C[playerGender]);
            else
                sub_8015664(30, gUnknown_082EED3C[playerGender]);
            break;
        case 3:
            data->state = 22;
            break;
        }
        taskData[3]++;
        break;
    case 22:
        if (sub_8011A80())
        {
            playerGender = sub_8017CF8(taskData[1], data->field_0);
            sub_8011090(0x54, 0, 1);
            if (sub_8011B90() == TRUE)
                sub_801568C(gUnknown_082EED3C[playerGender]);
            else
                sub_8015664(30, gUnknown_082EED3C[playerGender]);
        }
        if (gReceivedRemoteLinkPlayers != 0)
            data->state = 16;
        break;
    case 11:
        PlaySE(SE_PINPON);
        sub_800EF7C();
        data->state = 12;
        data->field_9A[0] = 0;
        break;
    case 12:
        if (sub_8011A80())
        {
            sub_801818C(FALSE);
            data->state = 2;
        }
        else if (gReceivedRemoteLinkPlayers != 0)
        {
            sub_80143E4(gBlockSendBuffer, TRUE);
            CreateTask(sub_80140E0, 5);
            data->state = 39;
        }
        break;
    case 39:
        sub_801689C(data);
        if (!FuncIsActiveTask(sub_80140E0))
        {
            data->state = 33;
            StringCopy(gStringVar1, gLinkPlayers[1].name);
            id = sub_800E540(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
            StringExpandPlaceholders(gStringVar4, gUnknown_082EE324[id]);
        }
        break;
    case 33:
        sub_801689C(data);
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 34;
        break;
    case 34:
        sub_801689C(data);
        if (sub_80168DC(data) && gMain.newKeys & B_BUTTON)
        {
            sub_8011DE0(1);
            StringCopy(gStringVar4, gUnknown_082EE598);
            data->state = 36;
        }
        break;
    case 35:
        sub_8015664(9, gStringVar4);
        break;
    case 9:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            data->field_4C[0] = 0x51;
            if (gUnknown_02022C2C == 0x45)
                sub_8011090(gUnknown_02022C2C | 0x40, sub_801100C(1), 0);
            else
                sub_8011090(gUnknown_02022C2C | 0x40, sub_801100C(1), 1);

            data->field_8->arr[0].field_1B = 0;
            taskData[3] = 0;
            if (gUnknown_02022C2C == 0x41)
            {
                if (!sub_8018024())
                {
                    data->field_4C[0] = 0x52;
                    sub_800FE50(data->field_4C);
                    data->state = 10;
                    StringCopy(gStringVar4, gUnknown_082EEC14);
                }
                else
                {
                    sub_800FE50(data->field_4C);
                    data->state = 13;
                }
            }
            else if (gUnknown_02022C2C == 0x48)
            {
                sub_800FE50(data->field_4C);
                sub_8018220(gStringVar4, data, 1);
                data->state = 40;
            }
            else
            {
                sub_800FE50(data->field_4C);
                data->state = 13;
            }
            break;
        case 1:
        case -1:
            data->field_4C[0] = 0x52;
            sub_800FE50(data->field_4C);
            data->state = 10;
            sub_8013078(gStringVar4, gUnknown_02022C2C);
            break;
        }
        break;
    case 10:
        sub_800AC34();
        data->state = 36;
        break;
    case 36:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            gUnknown_02022C2C = 0x40;
            sub_8015664(0x25, gStringVar4);
            memset(data->field_4C, 0, sizeof(data->field_4C));
            data->field_9A[0] = 0;
            data->field_98 = 0;
        }
        break;
    case 37:
        data->state = 2;
        sub_801818C(FALSE);
        break;
    case 13:
        sub_8017E00(gStringVar4, gUnknown_02022C2C | 0x40);
        sub_8015664(0xE, gStringVar4);
        break;
    case 14:
        sub_800ADF8();
        data->state = 15;
        break;
    case 15:
        if (sub_800A520())
            data->state = 16;
        break;
    case 16:
        Free(data->field_8);
        Free(data->field_0);
        Free(data->field_C);
        Free(data->field_4);
        DestroyTask(data->field_20);
        sub_8019F04(data->spriteIds);
        data->state = 17;
        break;
    case 17:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
        data->state = 18;
        break;
    case 18:
        if (!UpdatePaletteFade())
        {
            sub_8019E3C();
            DestroyTask(taskId);
            Free(gUnknown_02022C30.uRoom);
            sub_80149D8();
        }
        break;
    case 42:
        if (sub_800F7DC()->species == SPECIES_NONE)
        {
            data->state = 43;
        }
        else
        {
            if (sub_800F7DC()->species == SPECIES_EGG)
            {
                StringCopy(gStringVar4, gUnknown_082EF590);
            }
            else
            {
                StringCopy(gStringVar1, gSpeciesNames[sub_800F7DC()->species]);
                ConvertIntToDecimalStringN(gStringVar2, sub_800F7DC()->unk_0b_1, STR_CONV_MODE_LEFT_ALIGN, 3);
                StringExpandPlaceholders(gStringVar4, gUnknown_082EF564);
            }
            sub_8015664(44, gStringVar4);
        }
        break;
    case 43:
        if (PrintOnTextbox(&data->textState, gUnknown_082EF20C))
            data->state = 47;
        break;
    case 47:
        var5 = sub_8017178(&data->textState, &data->field_1D, &data->field_1E, &gUnknown_082F025C, &gUnknown_082F027C);
        if (var5 != -1)
        {
            if (var5 == -2 || var5 == 3)
            {
                data->state = 4;
                sub_801818C(TRUE);
            }
            else
            {
                switch (var5)
                {
                case 1:
                    sub_8015664(53, gUnknown_082EF4C4);
                    break;
                case 2:
                    sub_8015664(47, gUnknown_082EF298);
                    break;
                }
            }
        }
        break;
    case 53:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        data->state = 54;
        break;
    case 54:
        if (!gPaletteFade.active)
        {
            gUnknown_02022C40.field_0 = 1;
            gFieldCallback = sub_80AF128;
            sub_81B8904(8, CB2_ReturnToField);
        }
        break;
    case 52:
        var5 = sub_8017178(&data->textState, &data->field_1D, &data->field_1E, &gUnknown_082F0294, &gUnknown_082F032C);
        if (var5 != -1)
        {
            switch (var5)
            {
            case -2:
            case 18:
                sub_801807C(&gUnknown_02022C40);
                sub_8010FCC(0, 0, 0);
                sub_801568C(gUnknown_082EF4FC);
                break;
            default:
                gUnknown_02022C40.field_2 = var5;
                data->state = 55;
                break;
            }
        }
        break;
    case 55:
        sub_8010FCC(gUnknown_02022C40.field_2, gUnknown_02022C40.field_A, gUnknown_02022C40.field_C);
        sub_801568C(gUnknown_082EF520);
        break;
    case 44:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            data->state = 56;
            break;
        case 1:
        case -1:
            sub_801818C(TRUE);
            data->state = 4;
            break;
        }
        break;
    case 56:
        if (PrintOnTextbox(&data->textState, gUnknown_082EF5B8))
        {
            sub_8010FCC(0, 0, 0);
            sub_801807C(&gUnknown_02022C40);
            sub_801818C(TRUE);
            data->state = 4;
        }
        break;
    case 45:
        if (PrintOnTextbox(&data->textState, gUnknown_082EF1EC))
            data->state = 46;
        break;
    case 46:
        sub_80173B0();
        data->state = 48;
        break;
    case 48:
        var5 = sub_80172A0(&data->textState, &data->field_1D, &data->field_4A, &data->field_1E, &gUnknown_082F034C, &gUnknown_082F03A4, data->field_0);
        if (var5 != -1)
        {
            switch (var5)
            {
            case -2:
            case 8:
                sub_801818C(TRUE);
                data->state = 4;
                break;
            default:
                sub_80173B0();
                switch (sub_8017D04(data->field_0->arr[var5].unk.field_0.type, data->field_0->arr[var5].unk.field_0.species))
                {
                case 0:
                    sub_8018404(gStringVar1, &data->field_0->arr[var5]);
                    sub_8015664(49, gUnknown_082EF65C);
                    taskData[1] = var5;
                    break;
                case 1:
                    sub_8018404(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].unk.field_0.type]);
                    sub_8015664(46, gUnknown_082EF6E4);
                    break;
                case 2:
                    sub_8018404(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].unk.field_0.type]);
                    sub_8015664(46, gUnknown_082EF718);
                    break;
                }
                break;
            }
        }
        break;
    case 49:
        switch (sub_80170B8(&data->textState, FALSE))
        {
        case 0:
            data->state = 50;
            break;
        case -1:
        case 1:
            sub_801818C(TRUE);
            data->state = 4;
            break;
        }
        break;
    case 50:
        if (PrintOnTextbox(&data->textState, gUnknown_082EF4C4))
        {
            gUnknown_02022C40.field_0 = 2;
            memcpy(&gUnknown_02022C38, &data->field_0->arr[taskData[1]].unk.field_0.unk_00, sizeof(gUnknown_02022C38));
            gUnknown_02022C3E = data->field_0->arr[taskData[1]].unk.field_0.type;
            gUnknown_02022C3C = data->field_0->arr[taskData[1]].unk.field_0.species;
            gFieldCallback = sub_80AF128;
            sub_81B8904(9, CB2_ReturnToField);
            sub_80156B0(data);
            gUnknown_02022C40.field_8 = taskData[1];
        }
        break;
    case 51:
        gUnknown_02022C2C = 0x44;
        sub_8012188(data->field_0->arr[taskData[1]].unk.playerName, &data->field_0->arr[taskData[1]].unk.field_0, 0x44);
        sub_8018404(gStringVar1, &data->field_0->arr[taskData[1]]);
        sub_8017020(gUnknown_082EE17C[2]);
        data->state = 25;
        break;
    case 26:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            sub_801818C(TRUE);
            sub_801A3D0(taskData[0], taskData[1], data->field_0);
            data->state = 4;
        }
        break;
    case 8:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = data->stateAfterPrint;
        break;
    }
}

void var_800D_set_xB(void)
{
    if (InUnionRoom() == TRUE)
        gSpecialVar_Result = 11;
}

void sub_801689C(struct UnkStruct_URoom *arg0)
{
    if (gRecvCmds[1][1] != 0 && (gRecvCmds[1][0] & 0xFF00) == 0x2F00)
    {
        arg0->field_9A[0] = gRecvCmds[1][1];
        if (gRecvCmds[1][1] == 0x44)
        {
            arg0->field_9A[1] = gRecvCmds[1][2];
            arg0->field_9A[2] = gRecvCmds[1][3];
        }
    }
}

bool32 sub_80168DC(struct UnkStruct_URoom *arg0)
{
    if (arg0->field_9A[0] != 0)
    {
        s32 var = sub_8017EA0(gStringVar4, gLinkPlayers[1].gender, &arg0->field_9A[0], arg0);
        if (var == 0)
        {
            return TRUE;
        }
        else if (var == 1)
        {
            arg0->state = 35;
            gUnknown_02022C2C = arg0->field_9A[0];
            return FALSE;
        }
        else if (var == 2)
        {
            arg0->state = 36;
            sub_800AC34();
            return FALSE;
        }
    }

    return TRUE;
}

void sub_8016934(void)
{
    struct UnkStruct_URoom *ptr;

    gUnknown_02022C20[0] = EOS;
    CreateTask(sub_801697C, 0);
    gUnknown_02022C30.uRoom = gUnknown_02022C30.uRoom; // Needed to match.
    gUnknown_02022C30.uRoom = ptr = AllocZeroed(0x26C);
    gUnknown_03000DA8 = gUnknown_02022C30.uRoom;
    ptr->state = 0;
    ptr->textState = 0;
    ptr->field_10 = 0;
    ptr->field_12 = 0;
    gUnknown_02022C20[0] = EOS;
}

void sub_801697C(u8 taskId)
{
    s32 i;
    u8 text[32];
    struct UnkStruct_URoom *structPtr = gUnknown_02022C30.uRoom;

    switch (structPtr->state)
    {
    case 0:
        structPtr->state = 1;
        break;
    case 1:
        sub_8010F84(0xC, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C84();
        sub_80111B0(1);
        structPtr->state = 2;
        break;
    case 2:
        structPtr->field_4 = AllocZeroed(0x70);
        sub_80175EC(structPtr->field_4, 4);
        structPtr->field_C = AllocZeroed(0x70);
        sub_80175EC(structPtr->field_C, 4);
        structPtr->field_0 = AllocZeroed(0x100);
        sub_8017580(structPtr->field_0->arr, 8);
        structPtr->field_8 = AllocZeroed(0x20);
        sub_8017580(&structPtr->field_8->arr[0], 1);
        structPtr->field_20 = sub_8016DF0(structPtr->field_C, structPtr->field_4, 10);
        structPtr->state = 3;
        break;
    case 3:
        switch (sub_8016B00())
        {
        case 1:
        case 2:
            if (gUnknown_02022C20[0] == EOS)
            {
                for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
                {
                    if (structPtr->field_0->arr[i].field_1A_0 == 1)
                    {
                        sub_8018404(text, &structPtr->field_0->arr[i]);
                        if (sub_800E540(ReadAsU16(structPtr->field_0->arr[i].unk.field_0.unk_00.playerTrainerId), text))
                        {
                            StringCopy(gUnknown_02022C20, text);
                            break;
                        }
                    }
                }
            }
            break;
        case 3:
            break;
        }
        break;
    case 4:
        free(structPtr->field_8);
        free(structPtr->field_0);
        free(structPtr->field_C);
        free(structPtr->field_4);
        DestroyTask(structPtr->field_20);
        free(gUnknown_02022C30.uRoom);
        sub_800EDD4();
        DestroyTask(taskId);
        break;
    }
}

bool16 sp182_move_string(void)
{
    if (gUnknown_02022C20[0] != EOS)
    {
        StringCopy(gStringVar1, gUnknown_02022C20);
        gUnknown_02022C20[0] = EOS;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

u8 sub_8016B00(void)
{
    s32 i;
    u8 j;
    struct UnkStruct_URoom *structPtr = gUnknown_02022C30.uRoom;
    s32 r7 = 0;

    for (i = 0; i < 4; i++)
    {
        if (sub_8017630(&structPtr->field_C->arr[i].unk0, &gUnknown_082F045C) == TRUE)
        {
            structPtr->field_8->arr[0].unk = structPtr->field_C->arr[i].unk0;
            structPtr->field_8->arr[0].field_18 = 0;
            structPtr->field_8->arr[0].field_1A_0 = 1;
            structPtr->field_8->arr[0].field_1B = 1;
            return 4;
        }
    }
    for (j = 0; j < 8; j++)
    {
        if (structPtr->field_0->arr[j].field_1A_0 != 0)
        {
            i = sub_80176E4(&structPtr->field_0->arr[j], &structPtr->field_4->arr[0]);
            if (i != 0xFF)
            {
                if (structPtr->field_0->arr[j].field_1A_0 == 1)
                {
                    if (sub_8017678(&structPtr->field_0->arr[j], &structPtr->field_4->arr[i]))
                    {
                        structPtr->field_0->arr[j].unk = structPtr->field_4->arr[i].unk0;
                        structPtr->field_0->arr[j].field_1B = 0x40;
                        r7 = 1;
                    }
                    else if (structPtr->field_0->arr[j].field_1B != 0)
                    {
                        structPtr->field_0->arr[j].field_1B--;
                        if (structPtr->field_0->arr[j].field_1B == 0)
                            r7 = 2;
                    }
                }
                else
                {
                    structPtr->field_0->arr[j].field_1A_0 = 1;
                    structPtr->field_0->arr[j].field_1B = 0;
                    r7 = 2;
                }
                structPtr->field_0->arr[j].field_18 = 0;
            }
            else if (structPtr->field_0->arr[j].field_1A_0 != 2)
            {
                structPtr->field_0->arr[j].field_18++;
                if (structPtr->field_0->arr[j].field_18 >= 600)
                {
                    structPtr->field_0->arr[j].field_1A_0 = 2;
                    r7 = 2;
                }
            }
            else if (structPtr->field_0->arr[j].field_1A_0 == 2)
            {
                structPtr->field_0->arr[j].field_18++;
                if (structPtr->field_0->arr[j].field_18 >= 900)
                {
                    sub_8017580(&structPtr->field_0->arr[j], 1);
                }
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (sub_8017734(&structPtr->field_0->arr[0], &structPtr->field_4->arr[i].unk0, 8) != 0xFF)
            r7 = 1;
    }

    return r7;
}

/*
void sub_8016CA0(u8 taskId)
{
    s32 i, j;
    struct UnkLinkRfuStruct_02022B14 sp0;
    u8 text[10];
    struct UnkStruct_Main4 *ptr = (void*) gTasks[taskId].data;

    for (i = 0; i < 4; i++)
    {
        j = sub_800DE7C(&sp0, text, i);
        if (!sub_8013D88(sp0.unk_0a_0, gTasks[taskId].data[4]))
            sp0 = gUnknown_082F045C.field_0;
        if (sp0.unk_00.unk_00_0 == 1)
            sp0 = gUnknown_082F045C.field_0;

        if (!j)
        {
            for (j = 0; j < i; j++)
            {
                if (sub_8017630())
            }
        }
        else
        {

        }
    }
}
*/
