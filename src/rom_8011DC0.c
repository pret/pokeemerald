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

struct UnkStruct_02
{
    struct UnkLinkRfuStruct_02022B14 field_0;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    u8 playerName[PLAYER_NAME_LENGTH];
    u16 field_18;
    u8 field_1A_0:2;
    u8 field_1A_1:1;
    u8 field_1B;
};

struct UnkStruct_01
{
    struct UnkStruct_02 *field_0;
    void *field_4;
    void *field_8;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
};

extern struct UnkStruct_01 *gUnknown_02022C30;

extern u8 gUnknown_02022C2C;
extern u8 gUnknown_02022C2D;

// IWRAM vars
IWRAM_DATA struct UnkStruct_01 *gUnknown_03000DA0;
IWRAM_DATA u32 gUnknown_03000DA4;
IWRAM_DATA void *gUnknown_03000DA8;
IWRAM_DATA void *gUnknown_03000DAC;
IWRAM_DATA bool32 gUnknown_03000DB0;

// this file's functions
void sub_80173E0(u8 windowId, u8 arg1, const u8 *str, u8 arg3, u8 arg4, u8 arg5);
u16 ReadAsU16(const u8 *ptr);
void sub_8012780(u8 taskId);
void sub_80175EC(void *arg0, u8 count);
void sub_8017580(void *arg0, u8 count);
u8 sub_8016FC0(void *arg0, u32 arg1);
bool8 sub_8017064(u8 *arg0, const u8 *str);
void sub_801320C(struct UnkStruct_01 *arg0, u32 arg1, u32 arg2);

// const rom data
extern const u8 *const gUnknown_082EDB60[][5];
extern const u8 gText_UnkCtrlCodeF907[];
extern const u8 gUnknown_082EDBC4[];
extern const u8 gText_AwaitingCommunication[];
extern const u32 gUnknown_082F00C4[];
extern const struct WindowTemplate gUnknown_082F00BC;
extern const struct WindowTemplate gUnknown_082F0124;
extern const struct WindowTemplate gUnknown_082F012C;
extern const struct WindowTemplate gUnknown_082F011C;
extern const struct ListMenuTemplate gUnknown_082F015C;
extern const u8 *const gUnknown_082F0048[];

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
    struct UnkStruct_01 *dataPtr;

    taskId = CreateTask(sub_8012780, 0);
    gUnknown_02022C30 = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_03000DA0 = dataPtr;

    dataPtr->field_C = 0;
    dataPtr->field_D = 0;
    gSpecialVar_Result = 0;
}

void sub_8012780(u8 taskId)
{
    struct UnkStruct_01 *data = gUnknown_02022C30;

    switch (data->field_C)
    {
    case 0:
        if (gSpecialVar_0x8004 == 20 || gSaveBlock2Ptr->frontierChosenLvl == 1)
            gSpecialVar_0x8004++;
        gUnknown_02022C2C = gUnknown_082F00C4[gSpecialVar_0x8004];
        gUnknown_02022C2D = gUnknown_082F00C4[gSpecialVar_0x8004] >> 8;
        sub_8010F84(gUnknown_02022C2C, 0, 0);
        sub_800B488();
        OpenLink();
        sub_8011C10(gUnknown_02022C2D & 0xF);
        data->field_C = 3;
        break;
    case 3:
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0xA0);
        data->field_8 = AllocZeroed(0xA0);
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0, 5);
        sub_800DF90(&data->field_0->field_0, data->field_0->playerName);
        data->field_0->field_18 = 0;
        data->field_0->field_1A_0 = 1;
        data->field_0->field_1A_1 = 0;
        data->field_0->field_1B = 0;
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
        data->field_12 = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        NewMenuHelpers_DrawStdWindowFrame(data->field_11, FALSE);
        PutWindowTilemap(data->field_11);
        CopyWindowToVram(data->field_11, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->field_C = 4;
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
        data->field_C = 5;
        break;
    case 5:
        if (sub_8017064(&data->field_D, gStringVar4))
            data->field_C = 6;
        break;
    case 6:
        sub_801320C(data, 7, 10);
        if (gMain.newKeys & B_BUTTON)
        {
            if (data->field_13)
        }
        break;
    }
}
