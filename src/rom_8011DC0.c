#include "global.h"
#include "window.h"
#include "bg.h"
#include "string_util.h"
#include "task.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "librfu.h"
#include "malloc.h"
#include "menu.h"
#include "list_menu.h"
#include "menu_helpers.h"
#include "script.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "trade.h"
#include "trainer_card.h"
#include "overworld.h"
#include "battle.h"
#include "load_save.h"
#include "cable_club.h"
#include "field_control_avatar.h"

extern void HealPlayerParty(void);

struct UnkStruct_Shared
{
    struct UnkLinkRfuStruct_02022B14 field_0;
    u8 field_xD;
    u8 field_E;
    u8 field_F;
    u8 playerName[PLAYER_NAME_LENGTH];
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
    struct UnkStruct_x20 arr[5];
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
    u8 field_F;
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
    u8 field_B;
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

union UnkUnion_Main
{
    struct UnkStruct_Leader *leader;
    struct UnkStruct_Group *group;
};

struct TradeUnkStruct
{
    u16 field_0;
    u16 field_2;
    u32 field_4;
    u32 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    u16 field_12;
    u32 field_14;
};

extern struct TradeUnkStruct gUnknown_02022C40;

extern union UnkUnion_Main gUnknown_02022C30;

extern u8 gUnknown_02022C2C;
extern u8 gUnknown_02022C2D;

extern u8 gFieldLinkPlayerCount;
extern u8 gUnknown_03005DB4;

// IWRAM vars
IWRAM_DATA struct UnkStruct_Leader *gUnknown_03000DA0;
IWRAM_DATA struct UnkStruct_Group *gUnknown_03000DA4;
IWRAM_DATA void *gUnknown_03000DA8;
IWRAM_DATA void *gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

// this file's functions
void sub_80173E0(u8 windowId, u8 arg1, const u8 *str, u8 arg3, u8 arg4, u8 arg5);
u16 ReadAsU16(const u8 *ptr);
void sub_8012780(u8 taskId);
void sub_80134E8(u8 taskId);
void sub_8013C7C(u8 taskId);
void sub_80175EC(struct UnkStruct_Main4 *arg0, u8 count);
void sub_8017580(struct UnkStruct_Main0 *arg0, u8 count);
u8 sub_8016FC0(struct UnkStruct_Main4 *arg0, u32 arg1);
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

extern const u32 gUnknown_082F00C4[];

extern const u8 gUnknown_082F0530[];

extern const struct WindowTemplate gUnknown_082F00BC;
extern const struct WindowTemplate gUnknown_082F0124;
extern const struct WindowTemplate gUnknown_082F012C;
extern const struct WindowTemplate gUnknown_082F011C;
extern const struct WindowTemplate gUnknown_082F0174;
extern const struct WindowTemplate gUnknown_082F017C;

extern const struct ListMenuTemplate gUnknown_082F015C;
extern const struct ListMenuTemplate gUnknown_082F0204;

extern const u8 *const gUnknown_082F0048[];
extern const u8 *const gUnknown_082EDDC4[];
extern const u8 *const gUnknown_082EFB70[];
extern const u8 *const gUnknown_082EDD50[];
extern const u8 *const gUnknown_082EDE9C[];

extern const struct UnkStruct_Shared gUnknown_082F045C[];

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
        if (gSpecialVar_0x8004 == 20 && gSaveBlock2Ptr->frontierChosenLvl == 1)
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
        sub_8017580(data->field_0, 5);
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
            data->field_F = AddWindow(&gUnknown_082F011C);
            break;
        case 5:
            data->field_F = AddWindow(&gUnknown_082F0124);
            break;
        }
        data->field_11 = AddWindow(&gUnknown_082F012C);

        FillWindowPixelBuffer(data->field_10, 0x22);
        sub_80173E0(data->field_10, 0, gUnknown_082EDBC4, 8, 1, 4);
        PutWindowTilemap(data->field_10);
        CopyWindowToVram(data->field_10, 2);

        NewMenuHelpers_DrawStdWindowFrame(data->field_F, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F015C;
        gMultiuseListMenuTemplate.windowId = data->field_F;
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
            sub_81AE70C(data->listTaskId);
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
        switch (sub_80170B8(&data->textState, sub_801064C(ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName)))
        {
        case 0:
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->field_19 = 5;
            sub_8010688(5, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            sub_8010688(6, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case -3:
            data->state = 9;
            break;
        }
        break;
    case 12:
        val = sub_8010714(ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->field_13].field_1B = 0;
                sub_81AE70C(data->listTaskId);
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
                sub_8011DC0(data->field_0->arr[data->field_13].unk.playerName, ReadAsU16(data->field_0->arr[data->field_13].unk.field_0.playerTrainerId));
                data->field_0->arr[data->field_13].field_1A_0 = 0;
                sub_8013398(data->field_0);
                sub_81AE70C(data->listTaskId);
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
    sub_819746C(data->field_F, FALSE);
    CopyBgTilemapBufferToVram(0);
    RemoveWindow(data->field_11);
    RemoveWindow(data->field_F);
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
        sub_81AE70C(data->listTaskId);
        sub_8018404(gStringVar2, &data->field_0->arr[data->field_13]);
        sub_8012FC4(gStringVar4, gUnknown_02022C2C);
        data->state = arg1;
        break;
    case 2:
        sub_8011A64(0, 0);
        sub_81AE70C(data->listTaskId);
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
        data->field_0->arr[copiedCount].unk = gUnknown_082F045C[0];
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
        if (gSpecialVar_0x8004 == 20 && gSaveBlock2Ptr->frontierChosenLvl == 1)
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
        sub_8017580(data->field_0, 16);
        data->field_11 = sub_8016FC0(data->field_4, gSpecialVar_0x8004);
        data->field_C = AddWindow(&gUnknown_082F00BC);
        data->field_B = AddWindow(&gUnknown_082F0174);
        data->field_D = AddWindow(&gUnknown_082F017C);

        FillWindowPixelBuffer(data->field_C, 0x22);
        sub_80173E0(data->field_C, 0, gUnknown_082EF7DC, 8, 1, 4);
        PutWindowTilemap(data->field_C);
        CopyWindowToVram(data->field_C, 2);

        NewMenuHelpers_DrawStdWindowFrame(data->field_B, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F0204;
        gMultiuseListMenuTemplate.windowId = data->field_B;
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
            sub_81AE70C(data->listTaskId);
            break;
        case 0:
            id = ListMenuHandleInputGetItemId(data->listTaskId);
            if (gMain.newKeys & A_BUTTON && id != -1)
            {
                // this unused variable along with the assignment is needed to match
                u32 unusedVar;
                unusedVar  = data->field_0->arr[id].unk.field_0.unk_0a_0;

                if (data->field_0->arr[id].field_1A_0 == 1 && data->field_0->arr[id].unk.field_0.unk_0a_7 == 0)
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
            sub_81AE70C(data->listTaskId);
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
            sub_81AE70C(data->listTaskId);
            break;
        case 1:
        case -1:
            data->state = 5;
            sub_81AE70C(data->listTaskId);
            break;
        case -3:
            data->state = 6;
            sub_81AE70C(data->listTaskId);
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
        sub_819746C(data->field_B, FALSE);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->field_D);
        RemoveWindow(data->field_B);
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

    if (gUnknown_02022C2C == 4 && structPtr->unk.field_0.unk_01_2 != 3)
    {
        if (!(gSaveBlock2Ptr->specialSaveWarp & 0x80))
            return 1;
        else if (structPtr->unk.field_0.unk_00_7)
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
    sub_81AE70C(data->listTaskId);
    sub_8018404(gStringVar1, &data->field_0->arr[data->field_F]);
    sub_8011090(gUnknown_082F0530[gSpecialVar_0x8004], 0, 1);
    sub_8011FC8(data->field_0->arr[data->field_F].unk.playerName, ReadAsU16(data->field_0->arr[data->field_F].unk.field_0.playerTrainerId));
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
        sub_8017580(data->field_0, 16);
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

extern const u8 *const gUnknown_082F04D8[22];

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
        if (data->field_0->arr[id].unk.field_0.unk_0a_7 != 0)
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

extern struct MailStruct gUnknown_020321C0[PARTY_SIZE];
extern u8 gUnknown_02032298[2];

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
            sub_80C4E74(GetMultiplayerId() ^ 1, CB2_ReturnToField);
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
    gLinkPlayers[GetMultiplayerId()].lp_field_18 = GetMultiplayerId();
    gLinkPlayers[GetMultiplayerId() ^ 1].lp_field_18 = GetMultiplayerId() ^ 1;
    gMain.savedCallback = sub_80B360C;
    gBattleTypeFlags = battleFlags;
    PlayBattleBGM();
}

void sub_8014290(u16 arg0, u16 x, u16 y)
{
    VarSet(VAR_0x4087, arg0);
    Overworld_SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    saved_warp2_set_2(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    warp_in();
}

void sub_8014304(s8 mapGroup, s8 mapNum, s32 x, s32 y, u16 arg4)
{
    gSpecialVar_0x8004 = arg4;
    VarSet(VAR_0x4087, arg4);
    gFieldLinkPlayerCount = GetLinkPlayerCount();
    gUnknown_03005DB4 = GetMultiplayerId();
    sub_809D2BC();
    Overworld_SetWarpDestination(mapGroup, mapNum, -1, x, y);
    warp_in();
}
