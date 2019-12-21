#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "berry_crush.h"
#include "bg.h"
#include "cable_club.h"
#include "data.h"
#include "decompress.h"
#include "dodrio_berry_picking.h"
#include "dynamic_placeholder_text_util.h"
#include "easy_chat.h"
#include "event_data.h"
#include "event_obj_lock.h"
#include "field_control_avatar.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "list_menu.h"
#include "load_save.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mevent.h"
#include "mystery_gift.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_jump.h"
#include "random.h"
#include "save_location.h"
#include "script.h"
#include "script_pokemon_util_80F87D8.h"
#include "sound.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trade.h"
#include "trainer_card.h"
#include "union_room.h"
#include "union_room_chat.h"
#include "union_room_player_avatar.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/cable_club.h"
#include "constants/game_stat.h"
#include "constants/maps.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/union_room.h"

EWRAM_DATA u8 sUnionRoomPlayerName[12] = {};
EWRAM_DATA u8 gUnknown_02022C2C = 0;
EWRAM_DATA u8 gUnknown_02022C2D = 0;
EWRAM_DATA union UnkUnion_Main gUnknown_02022C30 = {};
EWRAM_DATA u32 gFiller_02022C34 = 0;
EWRAM_DATA struct UnkLinkRfuStruct_02022B14Substruct gUnknown_02022C38 = {};
EWRAM_DATA u16 gUnionRoomOfferedSpecies = 0;
EWRAM_DATA u8 gUnionRoomRequestedMonType = 0;
static EWRAM_DATA struct UnionRoomTrade sUnionRoomTrade = {};

// IWRAM vars
static struct UnkStruct_Leader *gUnknown_03000DA0;
static struct UnkStruct_Group *gUnknown_03000DA4;
static struct UnkStruct_URoom *gUnknown_03000DA8;

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
u8 sub_8017734(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1, u8 arg2);
u8 sub_8013E44(void);
u32 sub_8013B8C(struct UnkStruct_Group *arg0, s32 id);
void sub_8013BD8(struct UnkStruct_Group *arg0, s32 id);
void sub_80173D4(void);
void sub_80177B8(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id);
bool32 sub_8017678(struct UnkStruct_Shared *arg0, struct UnkStruct_Shared *arg1);
static u32 GetPartyPositionOfRegisteredMon(struct UnionRoomTrade *arg0, u8 multiplayerId);
static void ResetUnionRoomTrade(struct UnionRoomTrade *arg0);
void sub_801AC54(void);
void sub_80149D8(void);
void MG_DrawTextBorder(u8 windowId);
s8 mevent_message_print_and_prompt_yes_no(u8 *textState, u8 *arg1, u8 arg2, const u8 *str);
bool32 sub_8016F1C(struct UnkLinkRfuStruct_02022B14 *arg0, s16 arg1);
u8 sub_8016DF0(struct UnkStruct_Main4 *arg0, struct UnkStruct_Main4 *arg1, u32 arg2);
void sub_8019F2C(void);
static bool32 RegisterTradeMonAndGetIsEgg(u32 monId, struct UnionRoomTrade *trade);
static void RegisterTradeMon(u32 monId, struct UnionRoomTrade *arg1);
void sub_80181CC(void);
bool32 sub_8017940(void);
u8 sub_8016B00(void);
void sub_801A274(struct UnkStruct_URoom *arg0);
bool32 sub_8017FD8(struct UnkStruct_URoom *arg0);
void sub_801689C(struct UnkStruct_URoom *arg0);
u8 sub_80181DC(struct UnkStruct_URoom *arg0);
bool32 sub_80168DC(struct UnkStruct_URoom *arg0);
bool32 sub_801704C(void);
s32 sub_8017CF8(s32 arg1, struct UnkStruct_Main0 *arg0);
s32 sub_80179D4(struct UnkStruct_Main0 *arg0, u8 arg1, u8 arg2, u32 playerGender);
void sub_801818C(bool32 arg0);
s32 sub_8017178(u8 *arg0, u8 *arg1, u8 *arg2, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate);
s32 sub_80172A0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate, struct UnkStruct_Main0 *arg6);
s32 sub_8017CB0(struct UnkStruct_x20 * arg, s32 arg1);
bool32 HasAtLeastTwoMonsOfLevel30OrLower(void);
u32 sub_8017984(s32 arg0);
void sub_8018220(u8 *unused, struct UnkStruct_URoom *arg1, bool8 arg2);
void sub_8017D9C(u8 *dst, s32 arg1, u32 playerGender);
u32 sub_80179AC(struct UnkStruct_x20 *arg0);
void sub_8017E00(u8 *dst, u8 arg1);
void sub_80173B0(void);
s32 sub_8017D04(u32 type, u32 species);
bool32 sub_8017020(const u8 *src);
u8 sub_8019BA8(struct UnkStruct_8019BA8 * );
s32 sub_8017EA0(u8 *dst, u32 gender, u16 *arg2, struct UnkStruct_URoom *arg3);
void sub_801697C(u8 taskId);
bool8 sub_8017630(struct UnkStruct_Shared* arg0, const struct UnkStruct_Shared* arg1);
void sub_8013278(u8 windowId, s32 itemId, u8 y);
void sub_8013DF4(u8 windowId, s32 itemId, u8 y);
void sub_8017BE8(u8 windowId, s32 itemId, u8 y);
void nullsub_14(u8 windowId, s32 itemId, u8 y);

#include "data/union_room.h"

// code
void nullsub_89(u8 taskId)
{

}

void sub_80124EC(u8 windowId, u8 arg1, u8 stringId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    switch (arg1 << 8)
    {
    case 0x200:
        sub_80173E0(windowId, 1, sPlayersNeededOrModeTexts[0][stringId - 1], 0, 1, 0);
        break;
    case 0x400:
        sub_80173E0(windowId, 1, sPlayersNeededOrModeTexts[1][stringId - 1], 0, 1, 0);
        break;
    case 0x2500:
        sub_80173E0(windowId, 1, sPlayersNeededOrModeTexts[2][stringId - 1], 0, 1, 0);
        break;
    case 0x3500:
        sub_80173E0(windowId, 1, sPlayersNeededOrModeTexts[3][stringId - 1], 0, 1, 0);
        break;
    case 0x2400:
        sub_80173E0(windowId, 1, sPlayersNeededOrModeTexts[4][stringId - 1], 0, 1, 0);
        break;
    }

    CopyWindowToVram(windowId, 2);
}

void sub_80125BC(u8 windowId)
{
    u8 text[30];
    u8 *txtPtr;

    sub_80173E0(windowId, 1, gSaveBlock2Ptr->playerName, 0, 1, 0);
    txtPtr = StringCopy(text, sText_ID);
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
        StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
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

void TryBecomeLinkLeader(void)
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
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
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

        FillWindowPixelBuffer(data->field_10, PIXEL_FILL(2));
        sub_80173E0(data->field_10, 0, sText_BButtonCancel, 8, 1, 4);
        PutWindowTilemap(data->field_10);
        CopyWindowToVram(data->field_10, 2);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F015C;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->field_11, FALSE);
        PutWindowTilemap(data->field_11);
        CopyWindowToVram(data->field_11, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->state = 4;
        break;
    case 4:
        StringCopy(gStringVar1, sLinkGroupActivityTexts[gUnknown_02022C2C]);
        if ((gUnknown_02022C2D >> 4) != 0)
        {
            if (data->field_13 > (gUnknown_02022C2D >> 4) - 1 && (gUnknown_02022C2D & 0xF) != 0)
                StringExpandPlaceholders(gStringVar4, sText_AwaitingLinkPressStart);
            else
                StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
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
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->field_13 = sub_8013398(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = 4;
        }
        break;
    case 29:
        id = ((gUnknown_02022C2D & 0xF) == 2) ? 0 : 1;
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
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
            LoadWirelessStatusIndicatorSpriteGfx();
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
                        StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
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
        if (PrintOnTextbox(&data->textState, sText_AreTheseMembersOK))
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
        if (PrintOnTextbox(&data->textState, sText_CancelModeWithTheseMembers))
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
        if (PrintOnTextbox(&data->textState, sText_ModeWithTheseMembersWillBeCanceled))
            data->state = 23;
        break;
    case 21:
    case 23:
        DestroyWirelessStatusIndicatorSprite();
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
    ClearStdWindowAndFrame(data->field_11, FALSE);
    DestroyListMenuTask(data->listTaskId, 0, 0);
    ClearWindowTilemap(data->field_10);
    ClearStdWindowAndFrame(data->listWindowId, FALSE);
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
        StringExpandPlaceholders(dst, sText_PlayerContactedYouForXAccept);
        break;
    case 21:
    case 22:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouShareX);
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
        StringExpandPlaceholders(dst, sText_PlayerContactedYouAddToMembers);
        break;
    }
}

void sub_8013078(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 65:
    case 68:
        StringExpandPlaceholders(dst, sText_OfferDeclined1);
        break;
    case 69:
    case 72:
        StringExpandPlaceholders(dst, sText_OfferDeclined2);
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
        StringExpandPlaceholders(dst, sText_AwaitingPlayersResponse);
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
        StringExpandPlaceholders(dst, sText_PlayerHasBeenAskedToRegisterYouPleaseWait);
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
        StringExpandPlaceholders(dst, sText_PlayerSentBackOK);
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
        StringExpandPlaceholders(dst, sText_PlayerOKdRegistration);
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

void sub_8013278(u8 arg0, s32 id, u8 arg2)
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
        sub_8017734(data->field_0->arr, &data->field_4->arr[id], 5);

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

void TryJoinLinkGroup(void)
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
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
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
        if (PrintOnTextbox(&data->textState, sChooseTrainerTexts[gSpecialVar_0x8004]))
            data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FC0(data->field_4, gSpecialVar_0x8004);
        data->field_C = AddWindow(&gUnknown_082F00BC);
        data->listWindowId = AddWindow(&gUnknown_082F0174);
        data->field_D = AddWindow(&gUnknown_082F017C);

        FillWindowPixelBuffer(data->field_C, PIXEL_FILL(2));
        sub_80173E0(data->field_C, 0, sText_ChooseJoinCancel, 8, 1, 4);
        PutWindowTilemap(data->field_C);
        CopyWindowToVram(data->field_C, 2);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = gUnknown_082F0204;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->field_D, FALSE);
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
            id = ListMenu_ProcessInput(data->listTaskId);
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
                        StringCopy(gStringVar4, sCantTransmitToTrainerTexts[var - 1]);
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
                    StringCopy(gStringVar1, sLinkGroupActivityTexts[gUnknown_02022C2C]);
                    StringExpandPlaceholders(gStringVar4, sText_AwaitingOtherMembers);
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
        if (PrintOnTextbox(&data->textState, sText_QuitBeingMember))
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
        ClearStdWindowAndFrame(data->field_D, FALSE);
        DestroyListMenuTask(data->listTaskId, 0, 0);
        ClearWindowTilemap(data->field_C);
        ClearStdWindowAndFrame(data->listWindowId, FALSE);
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
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[sub_8011A74()]))
        {
            gSpecialVar_Result = 6;
            data->state = 23;
        }
        break;
    case 11:
        DestroyWirelessStatusIndicatorSprite();
        gSpecialVar_Result = 5;
        data->state = 23;
        break;
    case 15:
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[sub_8011A74()]))
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
        if (!(gSaveBlock2Ptr->specialSaveWarpFlags & CHAMPION_SAVEWARP))
            return 1;
        else if (structPtr->unk.field_0.unk_00.isChampion)
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
    LoadWirelessStatusIndicatorSpriteGfx();
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

void sub_8013DF4(u8 arg0, s32 id, u8 arg2)
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
                    if (sub_8017678(&data->field_0->arr[i].unk, &data->field_4->arr[id].unk0))
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
        if (sub_8017734(data->field_0->arr, &data->field_4->arr[id], 16) != 0xFF)
            ret = 1;
    }

    return ret;
}

static void Task_CreateTradeMenu(u8 taskId)
{
    CB2_StartCreateTradeMenu();
    DestroyTask(taskId);
}

u8 sub_8013F78(void)
{
    u8 taskId = CreateTask(Task_CreateTradeMenu, 0);

    return taskId;
}

void sub_8013F90(u8 taskId)
{
    u32 monId = GetPartyPositionOfRegisteredMon(&sUnionRoomTrade, GetMultiplayerId());

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
            IncrementGameStat(GAME_STAT_NUM_UNION_ROOM_BATTLES);
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
            memcpy(gTradeMail, gBlockRecvBuffer[GetMultiplayerId() ^ 1], sizeof(struct MailStruct) * PARTY_SIZE);
            ResetBlockReceivedFlags();
            gSelectedTradeMonPositions[TRADE_PLAYER] = monId;
            gSelectedTradeMonPositions[TRADE_PARTNER] = PARTY_SIZE;
            gMain.savedCallback = CB2_ReturnToField;
            SetMainCallback2(CB2_LinkTrade);
            ResetUnionRoomTrade(&sUnionRoomTrade);
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
                CopyTrainerCardData(&gTrainerCards[i], recvBuff, gLinkPlayers[i].version);
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
            ShowTrainerCardInLink(GetMultiplayerId() ^ 1, CB2_ReturnToField);
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
    gLinkPlayers[0].linkType = LINKTYPE_BATTLE;
    gLinkPlayers[GetMultiplayerId()].id = GetMultiplayerId();
    gLinkPlayers[GetMultiplayerId() ^ 1].id = GetMultiplayerId() ^ 1;
    gMain.savedCallback = sub_80B360C;
    gBattleTypeFlags = battleFlags;
    PlayBattleBGM();
}

static void sub_8014290(u16 linkService, u16 x, u16 y)
{
    VarSet(VAR_CABLE_CLUB_STATE, linkService);
    SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    SetDynamicWarpWithCoords(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    WarpIntoMap();
}

void sub_8014304(s8 mapGroup, s8 mapNum, s32 x, s32 y, u16 linkService)
{
    gSpecialVar_0x8004 = linkService;
    VarSet(VAR_CABLE_CLUB_STATE, linkService);
    gFieldLinkPlayerCount = GetLinkPlayerCount();
    gLocalLinkPlayerId = GetMultiplayerId();
    SetCableClubWarp();
    SetWarpDestination(mapGroup, mapNum, -1, x, y);
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
            SetMainCallback2(CB2_ReturnToFieldCableClub);
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
        argAsU16Ptr[48] = GetWonderCardFlagID();
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
        RecordMixTrainerNames();
        break;
    }

    switch (gUnknown_02022C2C)
    {
    case 65:
    case 81:
        CleanupOverworldWindowsAndTilemaps();
        gMain.savedCallback = sub_801AC54;
        InitChooseHalfPartyForBattle(3);
        break;
    case 1:
        CleanupOverworldWindowsAndTilemaps();
        sub_80143E4(gBlockSendBuffer, TRUE);
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_SINGLE_BATTLE);
        SetMainCallback2(sub_8014384);
        break;
    case 2:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_80143E4(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_DOUBLE_BATTLE);
        SetMainCallback2(sub_8014384);
        break;
    case 3:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_80143E4(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_4P), MAP_NUM(BATTLE_COLOSSEUM_4P), 5, 8, USING_MULTI_BATTLE);
        SetMainCallback2(sub_8014384);
        break;
    case 4:
        sub_80143E4(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        sub_8014304(MAP_GROUP(TRADE_CENTER), MAP_NUM(TRADE_CENTER), 5, 8, USING_TRADE_CENTER);
        SetMainCallback2(sub_8014384);
        break;
    case 15:
        sub_80143E4(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        sub_8014304(MAP_GROUP(RECORD_CORNER), MAP_NUM(RECORD_CORNER), 8, 9, USING_RECORD_CORNER);
        SetMainCallback2(sub_8014384);
        break;
    case 68:
        CleanupOverworldWindowsAndTilemaps();
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
        sub_8014290(USING_MINIGAME, 5, 1);
        sub_802A9A8(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    case 10:
        sub_8014290(USING_BERRY_CRUSH, 9, 1);
        sub_8020C70(CB2_LoadMap);
        break;
    case 11:
        sub_8014290(USING_MINIGAME, 5, 1);
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
            gLinkPlayers[0].linkType = LINKTYPE_BATTLE;
            gLinkPlayers[0].id = 0;
            gLinkPlayers[1].id = 2;
            sendBuff[0] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[0] - 1], MON_DATA_SPECIES);
            sendBuff[1] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[1] - 1], MON_DATA_SPECIES, NULL);
            gMain.savedCallback = NULL;
            data[0] = 4;
            RecordMixTrainerNames();
            ResetBlockReceivedFlags();
            break;
        case 16:
        case 23 ... 27:
            RecordMixTrainerNames();
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
            FadeScreen(FADE_TO_BLACK, 0);
            data[0] = 2;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            if (gUnknown_02022C2C == 29)
            {
                DestroyTask(taskId);
                SetMainCallback2(CB2_StartCreateTradeMenu);
            }
            else
            {
                sub_800ADF8();
                data[0] = 3;
            }
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
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
            DestroyWirelessStatusIndicatorSprite();
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

void MEvent_CreateTask_Leader(u32 arg0)
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
        winTemplate.baseBlock = GetMysteryGiftBaseBlock();
        winTemplate.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate);
        MG_DrawTextBorder(data->listWindowId);
        gMultiuseListMenuTemplate = gUnknown_082F015C;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->state = 2;
        break;
    case 2:
        StringCopy(gStringVar1, sLinkGroupActivityTexts[gUnknown_02022C2C]);
        sub_801262C(gStringVar4, gUnknown_02022C2C);
        data->state = 3;
        break;
    case 3:
        AddTextPrinterToWindow1(gStringVar4);
        data->state = 4;
        break;
    case 4:
        sub_801320C(data, 5, 6);
        if (gMain.newKeys & B_BUTTON)
        {
            data->state = 13;
            DestroyWirelessStatusIndicatorSprite();
        }
        break;
    case 6:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_LinkWithFriendDropped))
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
        switch (mevent_message_print_and_prompt_yes_no(&data->textState, &data->field_14, 0, gStringVar4))
        {
        case 0:
            LoadWirelessStatusIndicatorSpriteGfx();
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
                StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
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
        AddTextPrinterToWindow1(gStringVar4);
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
        DestroyWirelessStatusIndicatorSprite();
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
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_PleaseStartOver))
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
        if (IsLinkTaskFinished())
            DestroyTask(taskId);
        break;
    }
}

void MEvent_CreateTask_CardOrNewsWithFriend(u32 arg0)
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
        AddTextPrinterToWindow1(sText_ChooseTrainer);
        data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FC0(data->field_4, data->field_12 + 7);

        winTemplate1 = gUnknown_082F0174;
        winTemplate1.baseBlock = GetMysteryGiftBaseBlock();
        winTemplate1.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate1);

        winTemplate2 = gUnknown_082F017C;
        winTemplate2.paletteNum = 0xC;
        data->field_D = AddWindow(&winTemplate2);

        MG_DrawTextBorder(data->listWindowId);
        gMultiuseListMenuTemplate = gUnknown_082F0204;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        MG_DrawTextBorder(data->field_D);
        FillWindowPixelBuffer(data->field_D, PIXEL_FILL(1));
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
            id = ListMenu_ProcessInput(data->listTaskId);
            if (gMain.newKeys & A_BUTTON && id != -1)
            {
                // this unused variable along with the assignment is needed to match
                u32 unusedVar;
                unusedVar  = data->field_0->arr[id].unk.field_0.unk_0a_0;

                if (data->field_0->arr[id].field_1A_0 == 1 && !data->field_0->arr[id].unk.field_0.unk_0a_7)
                {
                    data->field_F = id;
                    LoadWirelessStatusIndicatorSpriteGfx();
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
        AddTextPrinterToWindow1(sText_AwaitingPlayersResponse);
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
            AddTextPrinterToWindow1(sText_PlayerSentBackOK);
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
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sLinkDroppedTexts[sub_8011A74()]))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        DestroyWirelessStatusIndicatorSprite();
        AddTextPrinterToWindow1(sText_PleaseStartOver);
        DestroyTask(taskId);
        sub_800EDD4();
        gSpecialVar_Result = 5;
        break;
    case 11:
        data->state++;
        sub_800ADF8();
        break;
    case 12:
        if (IsLinkTaskFinished())
            DestroyTask(taskId);
        break;
    }
}

void MEvent_CreateTask_CardOrNewsOverWireless(u32 arg0)
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
        AddTextPrinterToWindow1(sText_SearchingForWirelessSystemWait);
        data->state = 2;
        break;
    case 2:
        sub_80175EC(data->field_4, 4);
        sub_8017580(data->field_0->arr, 16);
        data->field_11 = sub_8016FF0(data->field_4, data->field_12 + 7);

        if (data->field_13 != 0)
        {
            winTemplate = gUnknown_082F0174;
            winTemplate.baseBlock = GetMysteryGiftBaseBlock();
            data->listWindowId = AddWindow(&winTemplate);

            MG_DrawTextBorder(data->listWindowId);
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
                id = ListMenu_ProcessInput(data->listTaskId);
            if (data->field_14 > 120)
            {
                if (data->field_0->arr[0].field_1A_0 == 1 && !data->field_0->arr[0].unk.field_0.unk_0a_7)
                {
                    if (sub_8016F1C(&data->field_0->arr[0].unk.field_0, data->field_12 + 7))
                    {
                        data->field_F = 0;
                        data->field_14 = 0;
                        LoadWirelessStatusIndicatorSpriteGfx();
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
        AddTextPrinterToWindow1(sText_AwaitingResponseFromWirelessSystem);
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
            AddTextPrinterToWindow1(sText_WirelessLinkEstablished);
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
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_WirelessLinkDropped))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_WirelessSearchCanceled))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            sub_800EDD4();
            gSpecialVar_Result = 5;
        }
        break;
    case 11:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sNoWonderSharedTexts[data->field_12]))
        {
            DestroyWirelessStatusIndicatorSprite();
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
        if (IsLinkTaskFinished())
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

    dataPtr = AllocZeroed(sizeof(*gUnknown_02022C30.uRoom));
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

void sub_8015664(u32 nextState, const u8 *src)
{
    struct UnkStruct_URoom *data = gUnknown_02022C30.uRoom;

    data->state = 8;
    data->stateAfterPrint = nextState;
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
        sub_8010FCC(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
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
        if ((GetPartyMenuType() == PARTY_MENU_TYPE_UNION_ROOM_REGISTER 
           || GetPartyMenuType() == PARTY_MENU_TYPE_UNION_ROOM_TRADE) 
           && sUnionRoomTrade.field_0 != 0)
        {
            id = GetCursorSelectionMonId();
            switch (sUnionRoomTrade.field_0)
            {
            case 1:
                sub_8011090(0x54, 0, 1);
                if (id >= PARTY_SIZE)
                {
                    ResetUnionRoomTrade(&sUnionRoomTrade);
                    sub_8010FCC(0, 0, 0);
                    sub_801568C(sText_RegistrationCanceled);
                }
                else if (!RegisterTradeMonAndGetIsEgg(GetCursorSelectionMonId(), &sUnionRoomTrade))
                {
                    sub_8015664(0x34, sText_ChooseRequestedMonType);
                }
                else
                {
                    data->state = 55;
                }
                break;
            case 2:
                sub_80156C8(data);
                taskData[1] = sUnionRoomTrade.field_8;
                if (id >= PARTY_SIZE)
                {
                    sub_801568C(sText_TradeCanceled);
                }
                else
                {
                    sub_8011090(0x54, 0, 1);
                    gUnknown_02022C2C = 0x44;
                    RegisterTradeMon(GetCursorSelectionMonId(), &sUnionRoomTrade);
                    data->state = 51;
                }
                break;
            }
            sUnionRoomTrade.field_0 = 0;
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
        if (!FuncIsActiveTask(Task_ShowStartMenu))
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
                sub_801568C(sText_TrainerAppearsBusy);
            else
                sub_8015664(30, sText_TrainerAppearsBusy);

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
                sub_8015664(31, sText_AwaitingPlayersResponseAboutTrade);
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
        sub_8015664(6, sHiDoSomethingTexts[id][playerGender]);
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
                    StringCopy(gStringVar4, sIfYouWantToDoSomethingTexts[gLinkPlayers[0].gender]);
                    data->state = 32;
                }
                else
                {
                    gUnknown_02022C2C = var5;
                    gUnknown_02022C2D = (u32)(var5) >> 8;
                    if (gUnknown_02022C2C == 0x41 && !HasAtLeastTwoMonsOfLevel30OrLower())
                    {
                        sub_8015664(5, sText_NeedTwoMonsOfLevel30OrLower1);
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
        StringCopy(gStringVar4, sText_TrainerBattleBusy);
        data->state = 36;
        break;
    case 27:
        sub_8017FD8(data);
        playerGender = sub_8017CF8(taskData[1], data->field_0);
        id = sub_8017984(data->field_4C[0] & 0x3F);
        if (PrintOnTextbox(&data->textState, sText_WaitOrShowCardTexts[playerGender][id]))
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
        data->field_4C[1] = sUnionRoomTrade.species;
        data->field_4C[2] = sUnionRoomTrade.level;
        sub_800FE50(data->field_4C);
        data->state = 29;
        break;
    case 29:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            StringCopy(gStringVar4, sText_TrainerBattleBusy);
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
        sub_8015664(6, sHiDoSomethingTexts[id][playerGender]);
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
        if (IsLinkTaskFinished())
        {
            if (GetMultiplayerId() == 0)
            {
                StringCopy(gStringVar1, gLinkPlayers[GetMultiplayerId() ^ 1].name);
                id = sub_800E540(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
                StringExpandPlaceholders(gStringVar4, sAwaitingResponseTexts[id]);
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
            sub_801568C(sDeclineBattleTexts[playerGender]);
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
                sub_801568C(sChatDeclinedTexts[playerGender]);
            else
                sub_8015664(30, sChatDeclinedTexts[playerGender]);
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
                sub_801568C(sChatDeclinedTexts[playerGender]);
            else
                sub_8015664(30, sChatDeclinedTexts[playerGender]);
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
            StringExpandPlaceholders(gStringVar4, sPlayerContactedYouTexts[id]);
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
            StringCopy(gStringVar4, sText_ChatEnded);
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
                if (!HasAtLeastTwoMonsOfLevel30OrLower())
                {
                    data->field_4C[0] = 0x52;
                    sub_800FE50(data->field_4C);
                    data->state = 10;
                    StringCopy(gStringVar4, sText_NeedTwoMonsOfLevel30OrLower2);
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
        sub_8015664(14, gStringVar4);
        break;
    case 14:
        sub_800ADF8();
        data->state = 15;
        break;
    case 15:
        if (IsLinkTaskFinished())
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
                StringCopy(gStringVar4, sText_CancelRegistrationOfEgg);
            }
            else
            {
                StringCopy(gStringVar1, gSpeciesNames[sub_800F7DC()->species]);
                ConvertIntToDecimalStringN(gStringVar2, sub_800F7DC()->level, STR_CONV_MODE_LEFT_ALIGN, 3);
                StringExpandPlaceholders(gStringVar4, sText_CancelRegistrationOfMon);
            }
            sub_8015664(44, gStringVar4);
        }
        break;
    case 43:
        if (PrintOnTextbox(&data->textState, sText_RegisterMonAtTradingBoard))
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
                case 1: // REGISTER
                    sub_8015664(53, sText_WhichMonWillYouOffer);
                    break;
                case 2: // INFO
                    sub_8015664(47, sText_TradingBoardInfo);
                    break;
                }
            }
        }
        break;
    case 53:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
        data->state = 54;
        break;
    case 54:
        if (!gPaletteFade.active)
        {
            sUnionRoomTrade.field_0 = 1;
            gFieldCallback = FieldCB_ContinueScriptUnionRoom;
            ChooseMonForTradingBoard(PARTY_MENU_TYPE_UNION_ROOM_REGISTER, CB2_ReturnToField);
        }
        break;
    case 52:
        var5 = sub_8017178(&data->textState, &data->field_1D, &data->field_1E, &gUnknown_082F0294, &sMenuTemplate_TradingBoardRequestType);
        if (var5 != -1)
        {
            switch (var5)
            {
            case -2:
            case 18:
                ResetUnionRoomTrade(&sUnionRoomTrade);
                sub_8010FCC(0, 0, 0);
                sub_801568C(sText_RegistrationCanceled);
                break;
            default:
                sUnionRoomTrade.type = var5;
                data->state = 55;
                break;
            }
        }
        break;
    case 55:
        sub_8010FCC(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        sub_801568C(sText_RegistraionCompleted);
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
        if (PrintOnTextbox(&data->textState, sText_RegistrationCanceled2))
        {
            sub_8010FCC(0, 0, 0);
            ResetUnionRoomTrade(&sUnionRoomTrade);
            sub_801818C(TRUE);
            data->state = 4;
        }
        break;
    case 45:
        if (PrintOnTextbox(&data->textState, sText_XCheckedTradingBoard))
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
                    sub_8015664(49, sText_AskTrainerToMakeTrade);
                    taskData[1] = var5;
                    break;
                case 1:
                    sub_8018404(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].unk.field_0.type]);
                    sub_8015664(46, sText_DontHaveTypeTrainerWants);
                    break;
                case 2:
                    sub_8018404(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].unk.field_0.type]);
                    sub_8015664(46, sText_DontHaveEggTrainerWants);
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
        if (PrintOnTextbox(&data->textState, sText_WhichMonWillYouOffer))
        {
            sUnionRoomTrade.field_0 = 2;
            memcpy(&gUnknown_02022C38, &data->field_0->arr[taskData[1]].unk.field_0.unk_00, sizeof(gUnknown_02022C38));
            gUnionRoomRequestedMonType = data->field_0->arr[taskData[1]].unk.field_0.type;
            gUnionRoomOfferedSpecies = data->field_0->arr[taskData[1]].unk.field_0.species;
            gFieldCallback = FieldCB_ContinueScriptUnionRoom;
            ChooseMonForTradingBoard(PARTY_MENU_TYPE_UNION_ROOM_TRADE, CB2_ReturnToField);
            sub_80156B0(data);
            sUnionRoomTrade.field_8 = taskData[1];
        }
        break;
    case 51:
        gUnknown_02022C2C = 0x44;
        sub_8012188(data->field_0->arr[taskData[1]].unk.playerName, &data->field_0->arr[taskData[1]].unk.field_0, 0x44);
        sub_8018404(gStringVar1, &data->field_0->arr[taskData[1]]);
        sub_8017020(sCommunicatingWaitTexts[2]);
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

void InitUnionRoom(void)
{
    struct UnkStruct_URoom *ptr;

    sUnionRoomPlayerName[0] = EOS;
    CreateTask(sub_801697C, 0);
    gUnknown_02022C30.uRoom = gUnknown_02022C30.uRoom; // Needed to match.
    gUnknown_02022C30.uRoom = ptr = AllocZeroed(sizeof(struct UnkStruct_URoom));
    gUnknown_03000DA8 = gUnknown_02022C30.uRoom;
    ptr->state = 0;
    ptr->textState = 0;
    ptr->field_10 = 0;
    ptr->field_12 = 0;
    sUnionRoomPlayerName[0] = EOS;
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
            if (sUnionRoomPlayerName[0] == EOS)
            {
                for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
                {
                    if (structPtr->field_0->arr[i].field_1A_0 == 1)
                    {
                        sub_8018404(text, &structPtr->field_0->arr[i]);
                        if (sub_800E540(ReadAsU16(structPtr->field_0->arr[i].unk.field_0.unk_00.playerTrainerId), text))
                        {
                            StringCopy(sUnionRoomPlayerName, text);
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

bool16 BufferUnionRoomPlayerName(void)
{
    if (sUnionRoomPlayerName[0] != EOS)
    {
        StringCopy(gStringVar1, sUnionRoomPlayerName);
        sUnionRoomPlayerName[0] = EOS;
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
                    if (sub_8017678(&structPtr->field_0->arr[j].unk, &structPtr->field_4->arr[i].unk0))
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
        if (sub_8017734(&structPtr->field_0->arr[0], &structPtr->field_4->arr[i], 8) != 0xFF)
            r7 = 1;
    }

    return r7;
}

void sub_8016CA0(u8 taskId)
{
    s32 i, j;
    struct UnkStruct_Shared sp0;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    bool8 r4;

    for (i = 0; i < 4; i++)
    {
        r4 = sub_800DE7C(&sp0.field_0, sp0.playerName, i);
        if (!sub_8013D88(sp0.field_0.unk_0a_0, gTasks[taskId].data[4]))
        {
            sp0 = gUnknown_082F045C;
        }
        if (sp0.field_0.unk_00.unk_00_0 == 1)
        {
            sp0 = gUnknown_082F045C;
        }
        if (!r4)
        {
            for (j = 0; j < i; j++)
            {
                if (!sub_8017630(&ptr[1]->arr[j].unk0, &sp0))
                {
                    sp0 = gUnknown_082F045C;
                }
            }
            ptr[1]->arr[i].unk0 = sp0;
            ptr[1]->arr[i].unk18 = sub_8017630(&ptr[1]->arr[i].unk0, &gUnknown_082F045C);
        }
        else
        {
            ptr[0]->arr[i].unk0 = sp0;
            ptr[0]->arr[i].unk18 = sub_8017630(&ptr[0]->arr[i].unk0, &gUnknown_082F045C);
        }
    }
}

u8 sub_8016DF0(struct UnkStruct_Main4 * a0, struct UnkStruct_Main4 * a1, u32 a2)
{
    u8 taskId = CreateTask(sub_8016CA0, 0);
    struct UnkStruct_Main4 ** data = (void *)gTasks[taskId].data;
    data[0] = a0;
    data[1] = a1;
    gTasks[taskId].data[4] = a2;
    return taskId;
}

void sub_8016E24(u8 taskId)
{
    s32 i, j;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;

    for (i = 0; i < 4; i++)
    {
        sub_800DE7C(&ptr[0]->arr[i].unk0.field_0, ptr[0]->arr[i].unk0.playerName, i);
        if (!sub_8013D88(ptr[0]->arr[i].unk0.field_0.unk_0a_0, gTasks[taskId].data[2]))
        {
            ptr[0]->arr[i].unk0 = gUnknown_082F045C;
        }
        for (j = 0; j < i; j++)
        {
            if (!sub_8017630(&ptr[0]->arr[j].unk0, &ptr[0]->arr[i].unk0))
            {
                ptr[0]->arr[i].unk0 = gUnknown_082F045C;
            }
        }
        ptr[0]->arr[i].unk18 = sub_8017630(&ptr[0]->arr[i].unk0, &gUnknown_082F045C);
    }
}

bool32 sub_8016F1C(struct UnkLinkRfuStruct_02022B14 *arg0, s16 arg1)
{
    if (arg1 == 7)
    {
        if (!arg0->unk_00.unk_00_5)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else if (arg1 == 8)
    {
        if (!arg0->unk_00.unk_00_4)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}

void sub_8016F44(u8 taskId)
{
    s32 i;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;

    for (i = 0; i < 4; i++)
    {
        if (sub_800DF34(&ptr[0]->arr[i].unk0.field_0, ptr[0]->arr[i].unk0.playerName, i))
        {
            sub_8016F1C(&ptr[0]->arr[i].unk0.field_0, gTasks[taskId].data[2]);
        }
        ptr[0]->arr[i].unk18 = sub_8017630(&ptr[0]->arr[i].unk0, &gUnknown_082F045C);
    }
}

u8 sub_8016FC0(struct UnkStruct_Main4 * a0, u32 a1)
{
    u8 taskId = CreateTask(sub_8016E24, 0);
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    ptr[0] = a0;
    gTasks[taskId].data[2] = a1;
    return taskId;
}

u8 sub_8016FF0(struct UnkStruct_Main4 * a0, u32 a1)
{
    u8 taskId = CreateTask(sub_8016F44, 0);
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    ptr[0] = a0;
    gTasks[taskId].data[2] = a1;
    return taskId;
}

bool32 sub_8017020(const u8 *src)
{
    sub_81973A4();
    DrawDialogueFrame(0, 1);
    StringExpandPlaceholders(gStringVar4, src);
    AddTextPrinterWithCustomSpeedForMessage(FALSE, 1);
    return FALSE;
}

bool32 sub_801704C(void)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 PrintOnTextbox(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        sub_81973A4();
        DrawDialogueFrame(0, 1);
        StringExpandPlaceholders(gStringVar4, str);
        AddTextPrinterForMessage_2(TRUE);
        (*textState)++;
        break;
    case 1:
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            *textState = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

s8 sub_80170B8(u8 *arg0, bool32 arg1)
{
    s8 r1;

    switch (*arg0)
    {
    case 0:
        if (arg1)
        {
            return -3;
        }
        DisplayYesNoMenuDefaultYes();
        (*arg0)++;
        break;
    case 1:
        if (arg1)
        {
            sub_8198C78();
            *arg0 = 0;
            return -3;
        }
        r1 = Menu_ProcessInputNoWrapClearOnChoose();
        if (r1 == -1 || r1 == 0 || r1 == 1)
        {
            *arg0 = 0;
            return r1;
        }
        break;
    }
    return -2;
}

u8 sub_8017118(const struct WindowTemplate * template)
{
    u8 windowId = AddWindow(template);
    DrawStdWindowFrame(windowId, FALSE);
    FillWindowPixelBuffer(windowId, 0xFF);
    sub_80173E0(windowId, 1, sText_NameWantedOfferLv, 8, 1, 6);
    CopyWindowToVram(windowId, 2);
    PutWindowTilemap(windowId);
    return windowId;
}

void sub_8017168(u8 windowId)
{
    RemoveWindow(windowId);
}

s32 sub_8017178(u8 *arg0, u8 *arg1, u8 *arg2, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate)
{
    s32 r1, r8;
    struct WindowTemplate winTemplateCopy;

    switch (*arg0)
    {
    case 0:
        winTemplateCopy = *winTemplate;
        r1 = Intl_GetListMenuWidth(menuTemplate);
        if (winTemplateCopy.width > r1)
        {
            winTemplateCopy.width = r1;
        }
        if (winTemplateCopy.tilemapLeft + winTemplateCopy.width > 29)
        {
            winTemplateCopy.tilemapLeft = max(29 - winTemplateCopy.width, 0);
        }
        *arg1 = AddWindow(&winTemplateCopy);
        DrawStdWindowFrame(*arg1, FALSE);
        gMultiuseListMenuTemplate = *menuTemplate;
        gMultiuseListMenuTemplate.windowId = *arg1;
        *arg2 = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        CopyWindowToVram(*arg1, TRUE);
        (*arg0)++;
        break;
    case 1:
        r8 = ListMenu_ProcessInput(*arg2);
        if (({gMain.newKeys & A_BUTTON;}))
        {
            DestroyListMenuTask(*arg2, NULL, NULL);
            ClearStdWindowAndFrame(*arg1, TRUE);
            RemoveWindow(*arg1);
            *arg0 = 0;
            return r8;
        }
        else if (({gMain.newKeys & B_BUTTON;}))
        {
            DestroyListMenuTask(*arg2, NULL, NULL);
            ClearStdWindowAndFrame(*arg1, TRUE);
            RemoveWindow(*arg1);
            *arg0 = 0;
            return -2;
        }
        break;
    }

    return -1;
}

s32 sub_80172A0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate, struct UnkStruct_Main0 *arg6)
{
    s32 input;
    s32 r4;

    switch (*arg0)
    {
    case 0:
        *arg3 = sub_8017118(&gUnknown_082F0344);
        *arg1 = AddWindow(winTemplate);
        DrawStdWindowFrame(*arg1, FALSE);
        gMultiuseListMenuTemplate = *menuTemplate;
        gMultiuseListMenuTemplate.windowId = *arg1;
        *arg2 = ListMenuInit(&gMultiuseListMenuTemplate, 0, 1);
        (*arg0)++;
        break;
    case 1:
        CopyWindowToVram(*arg1, TRUE);
        (*arg0)++;
        break;
    case 2:
        // Register swap r1 <---> r2
        input = ListMenu_ProcessInput(*arg2);
        if (({gMain.newKeys & (A_BUTTON | B_BUTTON);}))
        {
            if (input == 8 || ({gMain.newKeys & B_BUTTON;}))
            {
                DestroyListMenuTask(*arg2, NULL, NULL);
                RemoveWindow(*arg1);
                sub_8017168(*arg3);
                *arg0 = 0;
                return -2;
            }
            else
            {
                r4 = sub_8017CB0(arg6->arr, input);
                if (r4 >= 0)
                {
                    DestroyListMenuTask(*arg2, NULL, NULL);
                    RemoveWindow(*arg1);
                    sub_8017168(*arg3);
                    *arg0 = 0;
                    return r4;
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
        }
        break;
    }

    return -1;
}
void sub_80173B0(void)
{
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
}

void sub_80173D4(void)
{
    EnableBothScriptContexts();
}

void sub_80173E0(u8 windowId, u8 arg1, const u8 *str, u8 arg3, u8 arg4, u8 arg5)
{
    struct TextPrinterTemplate sp0;

    sp0.currentChar = str;
    sp0.windowId = windowId;
    sp0.fontId = arg1;
    sp0.x = arg3;
    sp0.y = arg4;
    sp0.currentX = arg3;
    sp0.currentY = arg4;
    sp0.unk = 0;

    gTextFlags.useAlternateDownArrow = FALSE;
    switch (arg5)
    {
    case 0:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 2;
        sp0.bgColor = 1;
        sp0.shadowColor = 3;
        break;
    case 1:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 4;
        sp0.bgColor = 1;
        sp0.shadowColor = 5;
        break;
    case 2:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 6;
        sp0.bgColor = 1;
        sp0.shadowColor = 7;
        break;
    case 3:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 1;
        sp0.bgColor = 1;
        sp0.shadowColor = 3;
        break;
    case 4:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 1;
        sp0.bgColor = 2;
        sp0.shadowColor = 3;
        break;
    case 5:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 7;
        sp0.bgColor = 15;
        sp0.shadowColor = 9;
        break;
    case 6:
        sp0.letterSpacing = 0;
        sp0.lineSpacing = 0;
        sp0.fgColor = 14;
        sp0.bgColor = 15;
        sp0.shadowColor = 9;
        break;
    }

    AddTextPrinter(&sp0, 0xFF, NULL);
}

void sub_8017580(struct UnkStruct_x20 *arg0, u8 count)
{
    s32 i;

    for (i = 0; i < count; i++)
    {
        arg0[i].unk = gUnknown_082F045C;
        arg0[i].field_18 = 0xFF;
        arg0[i].field_1A_0 = 0;
        arg0[i].field_1A_1 = 0;
        arg0[i].field_1B = 0;
    }
}

void sub_80175EC(struct UnkStruct_Main4 *arg0, u8 count)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        arg0->arr[i].unk0 = gUnknown_082F045C;
        arg0->arr[i].unk18 = 0;
    }
}

bool8 sub_8017630(struct UnkStruct_Shared* arg0, const struct UnkStruct_Shared* arg1)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (arg0->field_0.unk_00.playerTrainerId[i] != arg1->field_0.unk_00.playerTrainerId[i])
        {
            return TRUE;
        }
    }

    for (i = 0; i < 8; i++)
    {
        if (arg0->playerName[i] != arg1->playerName[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_8017678(struct UnkStruct_Shared *arg0, struct UnkStruct_Shared *arg1)
{
    s32 i;

    if (arg0->field_0.unk_0a_0 != arg1->field_0.unk_0a_0)
    {
        return TRUE;
    }

    if (arg0->field_0.unk_0a_7 != arg1->field_0.unk_0a_7)
    {
        return TRUE;
    }

    for (i = 0; i < 4; i++)
    {
        if (arg0->field_0.unk_04[i] != arg1->field_0.unk_04[i])
        {
            return TRUE;
        }
    }

    if (arg0->field_0.species != arg1->field_0.species)
    {
        return TRUE;
    }

    if (arg0->field_0.type != arg1->field_0.type)
    {
        return TRUE;
    }

    return FALSE;
}

u32 sub_80176E4(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1)
{
    u8 result = 0xFF;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (arg1[i].unk18 && !sub_8017630(&arg0->unk, &arg1[i].unk0))
        {
            result = i;
            arg1[i].unk18 = FALSE;
        }
    }

    return result;
}

u8 sub_8017734(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1, u8 arg2)
{
    s32 i;

    if (arg1->unk18)
    {
        for (i = 0; i < arg2; i++)
        {
            if (arg0[i].field_1A_0 == 0)
            {
                arg0[i].unk = arg1->unk0;
                arg0[i].field_18 = 0;
                arg0[i].field_1A_0 = 1;
                arg0[i].field_1B = 64;
                arg1->unk18 = FALSE;
                return i;
            }
        }
    }

    return 0xFF;
}

void sub_80177B8(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id)
{
    u8 r2;
    u8 sp0[6];

    ConvertIntToDecimalStringN(gStringVar4, id + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar4, sText_Colon);
    sub_80173E0(arg0, 1, gStringVar4, arg1, arg2, 0);
    arg1 += 18;
    r2 = arg3->unk.field_0.unk_0a_0;
    if (arg3->field_1A_0 == 1 && !(r2 & 0x40))
    {
        sub_8018404(gStringVar4, arg3);
        sub_80173E0(arg0, 1, gStringVar4, arg1, arg2, arg4);
        ConvertIntToDecimalStringN(sp0, arg3->unk.field_0.unk_00.playerTrainerId[0] | (arg3->unk.field_0.unk_00.playerTrainerId[1] << 8), STR_CONV_MODE_LEADING_ZEROS, 5);
        StringCopy(gStringVar4, sText_ID);
        StringAppend(gStringVar4, sp0);
        sub_80173E0(arg0, 1, gStringVar4, GetStringRightAlignXOffset(1, gStringVar4, 0x88), arg2, arg4);
    }
}

void sub_80178A0(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id)
{
    u8 sp0[6];

    if (arg3->field_1A_0 == 1)
    {
        sub_8018404(gStringVar4, arg3);
        sub_80173E0(arg0, 1, gStringVar4, arg1, arg2, arg4);
        ConvertIntToDecimalStringN(sp0, arg3->unk.field_0.unk_00.playerTrainerId[0] | (arg3->unk.field_0.unk_00.playerTrainerId[1] << 8), STR_CONV_MODE_LEADING_ZEROS, 5);
        StringCopy(gStringVar4, sText_ID);
        StringAppend(gStringVar4, sp0);
        sub_80173E0(arg0, 1, gStringVar4, GetStringRightAlignXOffset(1, gStringVar4, 0x68), arg2, arg4);
    }
}

bool32 sub_8017940(void)
{
    s16 x, y;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    if (x != 9)
    {
        return FALSE;
    }
    if (y != 8)
    {
        return FALSE;
    }
    if (gPlayerAvatar.tileTransitionState == 2 || gPlayerAvatar.tileTransitionState == 0)
    {
        return TRUE;
    }

    return FALSE;
}

u32 sub_8017984(s32 arg0)
{
    switch (arg0)
    {
    case 5:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 3:
    default:
        return 0;
    }
}

u32 sub_80179AC(struct UnkStruct_x20 *arg0)
{
    u8 sp0[30];
    sub_8018404(sp0, arg0);
    return sub_800E540(ReadAsU16(arg0->unk.field_0.unk_00.playerTrainerId), sp0);
}

s32 sub_80179D4(struct UnkStruct_Main0 *arg0, u8 arg1, u8 arg2, u32 playerGender)
{
    bool32 r2;

    struct UnkStruct_x20 * r5 = &arg0->arr[arg2];

    if (!r5->unk.field_0.unk_0a_7 && arg1 == 0)
    {
        sub_8018404(gStringVar1, r5);
        r2 = sub_800E540(ReadAsU16(r5->unk.field_0.unk_00.playerTrainerId), gStringVar1);
        if (r5->unk.field_0.unk_0a_0 == 0x45)
        {
            StringExpandPlaceholders(gStringVar4, sJoinChatTexts[r2][playerGender]);
            return 2;
        }
        else
        {
            sub_8017020(sCommunicatingWaitTexts[r2]);
            return 1;
        }
    }
    else
    {
        sub_8018404(gStringVar1, r5);
        if (arg1 != 0)
        {
            playerGender = (r5->unk.field_0.unk_00.playerTrainerId[arg1 + 1] >> 3) & 1;
        }
        switch (r5->unk.field_0.unk_0a_0 & 0x3F)
        {
        case 1:
            StringExpandPlaceholders(gStringVar4, sBattleReactionTexts[playerGender][Random() % 4]);
            break;
        case 4:
            StringExpandPlaceholders(gStringVar4, sTradeReactionTexts[playerGender][Random() % 2]);
            break;
        case 5:
            StringExpandPlaceholders(gStringVar4, sChatReactionTexts[playerGender][Random() % 4]);
            break;
        case 8:
            StringExpandPlaceholders(gStringVar4, sTrainerCardReactionTexts[playerGender][Random() % 2]);
            break;
        default:
            StringExpandPlaceholders(gStringVar4, sText_TrainerAppearsBusy);
            break;
        }
        return 0;
    }
}

void nullsub_14(u8 windowId, s32 itemId, u8 y)
{

}

void sub_8017B3C(u8 arg0, u8 arg1, struct UnkLinkRfuStruct_02022B14 * arg2, const u8 * str, u8 arg4)
{
    u8 sp8[4];
    u16 r8 = arg2->species;
    u8 r7 = arg2->type;
    u8 r9 = arg2->level;

    sub_80173E0(arg0, 1, str, 8, arg1, arg4);
    if (r8 == SPECIES_EGG)
    {
        sub_80173E0(arg0, 1, sText_EggTrade, 0x44, arg1, arg4);
    }
    else
    {
        blit_move_info_icon(arg0, r7 + 1, 0x44, arg1);
        sub_80173E0(arg0, 1, gSpeciesNames[r8], 0x76, arg1, arg4);
        ConvertIntToDecimalStringN(sp8, r9, STR_CONV_MODE_RIGHT_ALIGN, 3);
        sub_80173E0(arg0, 1, sp8, 0xC6, arg1, arg4);
    }
}

void sub_8017BE8(u8 windowId, s32 itemId, u8 y)
{
    struct UnkStruct_Leader *leader = gUnknown_02022C30.leader;
    struct UnkLinkRfuStruct_02022B14 *rfu;
    s32 i, j;
    u8 sp4[11];

    if (itemId == -3 && y == gUnknown_082F03A4.upText_Y)
    {
        rfu = sub_800F7DC();
        if (rfu->species != SPECIES_NONE)
        {
            sub_8017B3C(windowId, y, rfu, gSaveBlock2Ptr->playerName, 5);
        }
    }
    else
    {
        j = 0;
        for (i = 0; i < 8; i++)
        {
            if (leader->field_0->arr[i].field_1A_0 == 1 && leader->field_0->arr[i].unk.field_0.species != SPECIES_NONE)
            {
                j++;
            }
            if (j == itemId + 1)
            {
                sub_8018404(sp4, &leader->field_0->arr[i]);
                sub_8017B3C(windowId, y, &leader->field_0->arr[i].unk.field_0, sp4, 6);
                break;
            }
        }
    }
}

s32 sub_8017CB0(struct UnkStruct_x20 * arg, s32 arg1)
{
    s32 i;
    s32 j = 0;

    for (i = 0; i < 8; i++)
    {
        if (arg[i].field_1A_0 == 1 && arg[i].unk.field_0.species != SPECIES_NONE)
        {
            j++;
        }
        if (j == arg1 + 1)
        {
            return i;
        }
    }

    return -1;
}

s32 sub_8017CF8(s32 arg1, struct UnkStruct_Main0 *arg0)
{
    return arg0->arr[arg1].unk.field_0.playerGender;
}

s32 sub_8017D04(u32 type, u32 species)
{
    s32 i;

    if (species == SPECIES_EGG)
    {
        for (i = 0; i < gPlayerPartyCount; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (species == SPECIES_EGG)
            {
                return 0;
            }
        }
        return 2;
    }
    else
    {
        for (i = 0; i < gPlayerPartyCount; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (gBaseStats[species].type1 == type || gBaseStats[species].type2 == type)
            {
                return 0;
            }
        }
        return 1;
    }
}

void sub_8017D9C(u8 *dst, s32 arg1, u32 playerGender)
{
    switch (arg1)
    {
    case 0x41:
        StringExpandPlaceholders(dst, sBattleDeclinedTexts[playerGender]);
        break;
    case 0x45:
        StringExpandPlaceholders(dst, sChatDeclinedTexts[playerGender]);
        break;
    case 0x44:
        StringExpandPlaceholders(dst, sText_TradeOfferRejected);
        break;
    case 0x48:
        StringExpandPlaceholders(dst, sShowTrainerCardDeclinedTexts[playerGender]);
        break;
    }
}

void sub_8017E00(u8 *dst, u8 arg1)
{
    u8 mpId = GetMultiplayerId();
    u8 gender = gLinkPlayers[mpId ^ 1].gender;

    switch (arg1)
    {
    case 0x41:
        StringCopy(dst, sStartActivityTexts[mpId][gender][0]);
        break;
    case 0x44:
        StringCopy(dst, sStartActivityTexts[mpId][gender][2]);
        break;
    case 0x45:
        StringCopy(dst, sStartActivityTexts[mpId][gender][1]);
        break;
    }
}

s32 sub_8017EA0(u8 *dst, u32 gender, u16 *arg2, struct UnkStruct_URoom *arg3)
{
    s32 result = 0;
    u16 species = SPECIES_NONE;
    s32 i;

    switch (arg2[0])
    {
    case 0x41:
        StringExpandPlaceholders(dst, sText_BattleChallenge);
        result = 1;
        break;
    case 0x45:
        StringExpandPlaceholders(dst, sText_ChatInvitation);
        result = 1;
        break;
    case 0x44:
        ConvertIntToDecimalStringN(arg3->field_58 + 0x00, sUnionRoomTrade.playerLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(arg3->field_58 + 0x10, gSpeciesNames[sUnionRoomTrade.playerSpecies]);
        for (i = 0; i < 4; i++)
        {
            if (gUnknown_03007890->unk_14[i].unk_04 == 2)
            {
                ConvertIntToDecimalStringN(arg3->field_58 + 0x20, arg2[2], STR_CONV_MODE_LEFT_ALIGN, 3);
                StringCopy(arg3->field_58 + 0x30, gSpeciesNames[arg2[1]]);
                species = arg2[1];
                break;
            }
        }
        if (species == SPECIES_EGG)
        {
            StringCopy(dst, sText_OfferToTradeEgg);
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                DynamicPlaceholderTextUtil_SetPlaceholderPtr(i, arg3->field_58 + 0x10 * i);
            }
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dst, sText_OfferToTradeMon);
        }
        result = 1;
        break;
    case 0x48:
        StringExpandPlaceholders(dst, sText_ShowTrainerCard);
        result = 1;
        break;
    case 0x40:
        StringExpandPlaceholders(dst, sText_ChatDropped);
        result = 2;
        break;
    }

    return result;
}

bool32 sub_8017FD8(struct UnkStruct_URoom *arg0)
{
    if (gRecvCmds[0][1] != 0)
    {
        if (gRecvCmds[0][1] == 0x51)
        {
            arg0->field_98 = 0x51;
            return TRUE;
        }
        else if (gRecvCmds[0][1] == 0x52)
        {
            arg0->field_98 = 0x52;
            return TRUE;
        }
    }
    return FALSE;
}

bool32 InUnionRoom(void)
{
    return    gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(UNION_ROOM)
           && gSaveBlock1Ptr->location.mapNum == MAP_NUM(UNION_ROOM)
           ? TRUE : FALSE;
}

bool32 HasAtLeastTwoMonsOfLevel30OrLower(void)
{
    s32 i;
    s32 count = 0;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) <= 30
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            count++;
        }
    }

    if (count > 1)
        return TRUE;
    else
        return FALSE;
}

static void ResetUnionRoomTrade(struct UnionRoomTrade *arg0)
{
    arg0->field_0 = 0;
    arg0->type = 0;
    arg0->playerPersonality = 0;
    arg0->playerSpecies = 0;
    arg0->playerLevel = 0;
    arg0->species = 0;
    arg0->level = 0;
    arg0->personality = 0;
}

void Script_ResetUnionRoomTrade(void)
{
    ResetUnionRoomTrade(&sUnionRoomTrade);
}

static bool32 RegisterTradeMonAndGetIsEgg(u32 monId, struct UnionRoomTrade *trade)
{
    trade->playerSpecies = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES2);
    trade->playerLevel = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
    trade->playerPersonality = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
    if (trade->playerSpecies == SPECIES_EGG)
        return TRUE;
    else
        return FALSE;
}

static void RegisterTradeMon(u32 monId, struct UnionRoomTrade *trade)
{
    trade->species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES2);
    trade->level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
    trade->personality = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
}

static u32 GetPartyPositionOfRegisteredMon(struct UnionRoomTrade *trade, u8 multiplayerId)
{
    u16 response = 0;
    u16 species;
    u32 personality;
    u32 cur_personality;
    u16 cur_species;
    s32 i;

    // player
    if (multiplayerId == 0)
    {
        species = trade->playerSpecies;
        personality = trade->playerPersonality;
    }
    // partner
    else
    {
        species = trade->species;
        personality = trade->personality;
    }

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        cur_personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
        if (cur_personality != personality)
        {
            continue;
        }
        cur_species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (cur_species != species)
        {
            continue;
        }
        response = i;
        break;
    }

    return response;
}

void sub_801818C(bool32 arg0)
{
    sub_80173B0();
    ScriptContext2_Disable();
    sub_8098524();
    gUnknown_02022C2C = 0;
    if (arg0)
    {
        sub_8010FCC(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        sub_8011090(0x40, 0, 0);
    }
}

void sub_80181CC(void)
{
    ScriptContext2_Enable();
    ScriptFreezeEventObjects();
}

u8 sub_80181DC(struct UnkStruct_URoom *arg0)
{
    u8 retVal = 0x80;
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (arg0->field_C->arr[i].unk18)
        {
            retVal |= arg0->field_C->arr[i].unk0.field_0.playerGender << 3;
            retVal |= arg0->field_C->arr[i].unk0.field_0.unk_00.playerTrainerId[0] & 7;
            break;
        }
    }

    return retVal;
}

void sub_8018220(u8 *unused, struct UnkStruct_URoom *arg1, bool8 arg2)
{
    struct TrainerCard *trainerCard = &gTrainerCards[GetMultiplayerId() ^ 1];
    s32 i;
    s32 n;

    DynamicPlaceholderTextUtil_Reset();

    StringCopy(arg1->field_C0[0], gTrainerClassNames[sub_8068BB0()]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, arg1->field_C0[0]);

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, trainerCard->playerName);

    StringCopy(arg1->field_174, sCardColorTexts[trainerCard->stars]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, arg1->field_174);

    ConvertIntToDecimalStringN(arg1->field_C0[2], trainerCard->caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, arg1->field_C0[2]);

    ConvertIntToDecimalStringN(arg1->field_C0[3], trainerCard->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(arg1->field_C0[4], trainerCard->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, arg1->field_C0[3]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, arg1->field_C0[4]);

    DynamicPlaceholderTextUtil_ExpandPlaceholders(arg1->field_1A4, sText_TrainerCardInfoPage1);
    StringCopy(gStringVar4, arg1->field_1A4);

    n = trainerCard->linkBattleWins;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(arg1->field_C0[0], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, arg1->field_C0[0]);

    n = trainerCard->linkBattleLosses;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(arg1->field_C0[1], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, arg1->field_C0[1]);

    ConvertIntToDecimalStringN(arg1->field_C0[2], trainerCard->pokemonTrades, STR_CONV_MODE_LEFT_ALIGN, 5);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, arg1->field_C0[2]);

    for (i = 0; i < 4; i++)
    {
        CopyEasyChatWord(arg1->field_C0[i + 3], trainerCard->var_28[i]);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(i + 4, arg1->field_C0[i + 3]);
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(arg1->field_1A4, sText_TrainerCardInfoPage2);
    StringAppend(gStringVar4, arg1->field_1A4);

    if (arg2 == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(arg1->field_1A4, sText_FinishedCheckingPlayersTrainerCard);
        StringAppend(gStringVar4, arg1->field_1A4);
    }
    else if (arg2 == FALSE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(arg1->field_1A4, sGladToMeetYouTexts[trainerCard->gender]);
        StringAppend(gStringVar4, arg1->field_1A4);
    }
}

void sub_8018404(u8 *dest, struct UnkStruct_x20 *arg1)
{
    StringCopy7(dest, arg1->unk.playerName);
    ConvertInternationalString(dest, arg1->unk.field_0.unk_00.unk_00_0);
}
