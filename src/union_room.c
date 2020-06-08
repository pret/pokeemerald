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
#include "event_object_lock.h"
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
#include "union_room_battle.h"
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

static EWRAM_DATA u8 sUnionRoomPlayerName[12] = {};
EWRAM_DATA u8 gPlayerCurrActivity = 0;
static EWRAM_DATA u8 sPlayerActivityGroupSize = 0;
static EWRAM_DATA union WirelessLink_Main sWirelessLinkMain = {};
static EWRAM_DATA u32 sUnused = 0;
EWRAM_DATA struct GFtgtGnameSub gPartnerTgtGnameSub = {};
EWRAM_DATA u16 gUnionRoomOfferedSpecies = 0;
EWRAM_DATA u8 gUnionRoomRequestedMonType = 0;
static EWRAM_DATA struct UnionRoomTrade sUnionRoomTrade = {};

// IWRAM vars
static struct WirelessLink_Leader *sLeader;
static struct WirelessLink_Group *sGroup;
static struct WirelessLink_URoom *sURoom;

// this file's functions
static void UR_AddTextPrinterParameterized(u8 windowId, u8 arg1, const u8 *str, u8 arg3, u8 arg4, u8 arg5);
static u16 ReadAsU16(const u8 *ptr);
static void Task_TryBecomeLinkLeader(u8 taskId);
static void Task_TryJoinLinkGroup(u8 taskId);
static void Task_ListenToWireless(u8 taskId);
static void Task_MEvent_Leader(u8 taskId);
static void Task_CardOrNewsWithFriend(u8 taskId);
static void Task_CardOrNewsOverWireless(u8 taskId);
static void Task_RunUnionRoom(u8 taskId);
static void ClearUnkStruct_x1CArray(struct UnkStruct_Main4 *arg0, u8 count);
static void ClearUnkStruct_x20Array(struct UnkStruct_x20 *arg0, u8 count);
static u8 CreateTask_ListenForPartnersWithCompatibleSerialNos(struct UnkStruct_Main4 *arg0, u32 arg1);
static u8 CreateTask_ListenForPartnersWithSerial7F7D(struct UnkStruct_Main4 *arg0, u32 arg1);
static bool8 PrintOnTextbox(u8 *textState, const u8 *str);
static bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *data, u32 arg1, u32 arg2);
static u8 sub_8013398(struct UnkStruct_Main0 *arg0);
static s8 UnionRoomHandleYesNo(u8 *arg0, bool32 arg1);
static void IntlConvPartnerUname7(u8 *dest, struct UnkStruct_x20 *arg1);
static void Leader_DestroyResources(struct WirelessLink_Leader *data);
static void CreateTask_RunScriptAndFadeToActivity(void);
static u8 LeaderUpdateGroupMembership(struct UnkStruct_Main0 *arg0);
static void PrintGroupMemberCandidateOnWindowWithColor(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id);
static u32 Findx20Inx1CArray(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1);
static u8 Appendx1Ctox20(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1, u8 arg2);
static u8 GetNewLeaderCandidate(void);
static u32 IsTryingToTradeAcrossVersionTooSoon(struct WirelessLink_Group *data, s32 id);
static void AskToJoinRfuGroup(struct WirelessLink_Group *data, s32 id);
static void JoinGroup_EnableScriptContexts(void);
static void PrintUnionRoomGroupOnWindow(u8 arg0, u8 arg1, u8 arg2, struct UnkStruct_x20 *arg3, u8 arg4, u8 id);
static bool32 AreUnionRoomPlayerGnamesDifferent(struct WirelessGnameUnamePair *arg0, struct WirelessGnameUnamePair *arg1);
static u32 GetPartyPositionOfRegisteredMon(struct UnionRoomTrade *arg0, u8 multiplayerId);
static void ResetUnionRoomTrade(struct UnionRoomTrade *arg0);
static void CreateTask_StartActivity(void);
static bool32 HasWonderCardOrNewsByLinkGroup(struct GFtgtGname *arg0, s16 arg1);
static u8 CreateTask_SearchForChildOrParent(struct UnkStruct_Main4 *arg0, struct UnkStruct_Main4 *arg1, u32 arg2);
static bool32 RegisterTradeMonAndGetIsEgg(u32 monId, struct UnionRoomTrade *trade);
static void RegisterTradeMon(u32 monId, struct UnionRoomTrade *arg1);
static void UR_EnableScriptContext2AndFreezeObjectEvents(void);
static bool32 PlayerIsTalkingToUnionRoomAide(void);
static u8 HandlePlayerListUpdate(void);
static bool32 PollPartnerYesNoResponse(struct WirelessLink_URoom *data);
static void ReceiveUnionRoomActivityPacket(struct WirelessLink_URoom *data);
static u8 GetActivePartnerSpriteGenderParam(struct WirelessLink_URoom *data);
static bool32 UnionRoom_HandleContactFromOtherPlayer(struct WirelessLink_URoom *data);
static bool32 UR_RunTextPrinters_CheckPrinter0Active(void);
static s32 GetUnionRoomPlayerGender(s32 arg1, struct UnkStruct_Main0 *arg0);
static s32 UnionRoomGetPlayerInteractionResponse(struct UnkStruct_Main0 *arg0, u8 arg1, u8 arg2, u32 playerGender);
static void HandleCancelTrade(bool32 arg0);
static s32 ListMenuHandler_AllItemsAvailable(u8 *arg0, u8 *arg1, u8 *arg2, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate);
static s32 TradeBoardMenuHandler(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate, struct UnkStruct_Main0 *arg6);
static s32 GetIndexOfNthTradeBoardOffer(struct UnkStruct_x20 * arg, s32 arg1);
static bool32 HasAtLeastTwoMonsOfLevel30OrLower(void);
static u32 GetResponseIdx_InviteToURoomActivity(s32 arg0);
static void ViewURoomPartnerTrainerCard(u8 *unused, struct WirelessLink_URoom *data, bool8 arg2);
static void GetURoomActivityRejectMsg(u8 *dst, s32 arg1, u32 playerGender);
static u32 ConvPartnerUnameAndGetWhetherMetAlready(struct UnkStruct_x20 *arg0);
static void GetURoomActivityStartMsg(u8 *dst, u8 arg1);
static void UR_ClearBg0(void);
static s32 IsRequestedTypeOrEggInPlayerParty(u32 type, u32 species);
static bool32 UR_PrintFieldMessage(const u8 *src);
static s32 GetChatLeaderActionRequestMessage(u8 *dst, u32 gender, u16 *arg2, struct WirelessLink_URoom *data);
static void Task_InitUnionRoom(u8 taskId);
static bool8 AreGnameUnameDifferent(struct WirelessGnameUnamePair* arg0, const struct WirelessGnameUnamePair* arg1);
static void ItemPrintFunc_PossibleGroupMembers(u8 windowId, s32 itemId, u8 y);
static void ListMenuItemPrintFunc_UnionRoomGroups(u8 windowId, s32 itemId, u8 y);
static void TradeBoardListMenuItemPrintFunc(u8 windowId, s32 itemId, u8 y);
static void nullsub_14(u8 windowId, s32 itemId, u8 y);

#include "data/union_room.h"

// code
static void PrintNumPlayersWaitingForMsg(u8 windowId, u8 capacityCode, u8 stringId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    switch (capacityCode << 8)
    {
    case LINK_GROUP_CAPACITY(0, 2):
        UR_AddTextPrinterParameterized(windowId, 1, sPlayersNeededOrModeTexts[0][stringId - 1], 0, 1, UR_COLOR_DKE_WHT_LTE);
        break;
    case LINK_GROUP_CAPACITY(0, 4):
        UR_AddTextPrinterParameterized(windowId, 1, sPlayersNeededOrModeTexts[1][stringId - 1], 0, 1, UR_COLOR_DKE_WHT_LTE);
        break;
    case LINK_GROUP_CAPACITY(2, 5):
        UR_AddTextPrinterParameterized(windowId, 1, sPlayersNeededOrModeTexts[2][stringId - 1], 0, 1, UR_COLOR_DKE_WHT_LTE);
        break;
    case LINK_GROUP_CAPACITY(3, 5):
        UR_AddTextPrinterParameterized(windowId, 1, sPlayersNeededOrModeTexts[3][stringId - 1], 0, 1, UR_COLOR_DKE_WHT_LTE);
        break;
    case LINK_GROUP_CAPACITY(2, 4):
        UR_AddTextPrinterParameterized(windowId, 1, sPlayersNeededOrModeTexts[4][stringId - 1], 0, 1, UR_COLOR_DKE_WHT_LTE);
        break;
    }

    CopyWindowToVram(windowId, 2);
}

static void PrintPlayerNameAndIdOnWindow(u8 windowId)
{
    u8 text[30];
    u8 *txtPtr;

    UR_AddTextPrinterParameterized(windowId, 1, gSaveBlock2Ptr->playerName, 0, 1, UR_COLOR_DKE_WHT_LTE);
    txtPtr = StringCopy(text, sText_ID);
    ConvertIntToDecimalStringN(txtPtr, ReadAsU16(gSaveBlock2Ptr->playerTrainerId), STR_CONV_MODE_LEADING_ZEROS, 5);
    UR_AddTextPrinterParameterized(windowId, 1, text, 0, 0x11, UR_COLOR_DKE_WHT_LTE);
}

static void StringExpandPlaceholders_AwaitingCommFromAnother(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_TRADE:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_BATTLE_TOWER:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_WONDER_CARD2:
    case ACTIVITY_WONDER_NEWS2:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        // UB: argument *dst isn't used, instead it always prints to gStringVar4
        StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
        break;
    }
}

static bool32 IsActivityWithVariableGroupSize(u32 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        return TRUE;
    default:
        return FALSE;
    }
}

void TryBecomeLinkLeader(void)
{
    u8 taskId;
    struct WirelessLink_Leader *data;

    taskId = CreateTask(Task_TryBecomeLinkLeader, 0);
    sWirelessLinkMain.leader = data = (void*)(gTasks[taskId].data);
    sLeader = data;

    data->state = 0;
    data->textState = 0;
    gSpecialVar_Result = 0;
}

static void Task_TryBecomeLinkLeader(u8 taskId)
{
    u32 id, val;
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;

    switch (data->state)
    {
    case 0:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004];
        sPlayerActivityGroupSize = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004] >> 8;
        SetHostRFUtgtGname(gPlayerCurrActivity, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_LinkLeader(sPlayerActivityGroupSize & 0xF);
        data->state = 3;
        break;
    case 3:
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        data->field_8 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 5);
        LinkRfu3_SetGnameUnameFromStaticBuffers(&data->field_0->arr[0].gname_uname.gname, data->field_0->arr[0].gname_uname.playerName);
        data->field_0->arr[0].field_18 = 0;
        data->field_0->arr[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
        data->field_0->arr[0].field_1A_1 = 0;
        data->field_0->arr[0].field_1B = 0;
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, 0xFF);
        data->bButtonCancelWindowId = AddWindow(&sWindowTemplate_BButtonCancel);
        switch (sPlayerActivityGroupSize & 0xF)
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
        data->nPlayerModeWindowId = AddWindow(&sWindowTemplate_NumPlayerMode);

        FillWindowPixelBuffer(data->bButtonCancelWindowId, PIXEL_FILL(2));
        UR_AddTextPrinterParameterized(data->bButtonCancelWindowId, 0, sText_BButtonCancel, 8, 1, 4);
        PutWindowTilemap(data->bButtonCancelWindowId);
        CopyWindowToVram(data->bButtonCancelWindowId, 2);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = sListMenuTemplate_PossibleGroupMembers;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->nPlayerModeWindowId, FALSE);
        PutWindowTilemap(data->nPlayerModeWindowId);
        CopyWindowToVram(data->nPlayerModeWindowId, 2);

        CopyBgTilemapBufferToVram(0);
        data->playerCount = 1;
        data->state = 4;
        break;
    case 4:
        StringCopy(gStringVar1, sLinkGroupActivityTexts[gPlayerCurrActivity]);
        if ((sPlayerActivityGroupSize >> 4) != 0)
        {
            if (data->playerCount > (sPlayerActivityGroupSize >> 4) - 1 && (sPlayerActivityGroupSize & 0xF) != 0)
                StringExpandPlaceholders(gStringVar4, sText_AwaitingLinkPressStart);
            else
                StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
        }
        else
        {
            StringExpandPlaceholders_AwaitingCommFromAnother(gStringVar4, gPlayerCurrActivity);
        }

        PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
        data->state = 5;
        break;
    case 5:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 6;
        break;
    case 6:
        Leader_SetStateIfMemberListChanged(data, 7, 10);
        if (gMain.newKeys & B_BUTTON)
        {
            if (data->playerCount == 1)
                data->state = 23;
            else if ((sPlayerActivityGroupSize & 0xF0) != 0)
                data->state = 30;
            else
                data->state = 19;
        }
        if ((sPlayerActivityGroupSize >> 4) != 0
            && data->playerCount > (sPlayerActivityGroupSize >> 4) - 1
            && (sPlayerActivityGroupSize & 0xF) != 0
            && sub_8012240()
            && gMain.newKeys & START_BUTTON)
        {
            data->state = 15;
            LinkRfu_StopManagerAndFinalizeSlots();
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
            data->playerCount = sub_8013398(data->field_0);
        }
        break;
    case 10:
        id = ((gPlayerCurrActivity & 0xF) == 2) ? 1 : 0;
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->playerCount = sub_8013398(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = 4;
        }
        break;
    case 29:
        // Other player canceled.
        id = ((sPlayerActivityGroupSize & 0xF) == 2) ? 0 : 1;
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
        switch (UnionRoomHandleYesNo(&data->textState, TrainerIdAndNameStillInPartnersList(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName)))
        {
        case 0:
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->field_19 = 5;
            SendByteToPartnerByIdAndName(5, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 12;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            SendByteToPartnerByIdAndName(6, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 12;
            break;
        case -3:
            data->state = 9;
            break;
        }
        break;
    case 12:
        val = WaitSendByteToPartnerByIdAndName(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->playerCount].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->playerCount++;
                if (data->playerCount == (sPlayerActivityGroupSize & 0xF))
                {
                    if ((sPlayerActivityGroupSize & 0xF0) != 0 || data->playerCount == 4)
                    {
                        data->state = 15;
                    }
                    else
                    {
                        IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->playerCount - 1]);
                        StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
                        data->state = 13;
                    }

                    LinkRfu_StopManagerAndFinalizeSlots();
                    PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
                }
                else
                {
                    data->state = 4;
                }
            }
            else
            {
                RequestDisconnectSlotByTrainerNameAndId(data->field_0->arr[data->playerCount].gname_uname.playerName, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId));
                data->field_0->arr[data->playerCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
                sub_8013398(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = 4;
            }

            data->field_19 = 0;
        }
        else if (val == 2)
        {
            RfuSetErrorStatus(0, 0);
            data->state = 4;
        }
        break;
    case 13:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 14;
        break;
    case 14:
        if (++data->delayTimerAfterOk > 120)
            data->state = 17;
        break;
    case 15:
        if (PrintOnTextbox(&data->textState, sText_AreTheseMembersOK))
            data->state = 16;
        break;
    case 16:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            data->state = 17;
            break;
        case 1:
        case -1:
            if ((sPlayerActivityGroupSize & 0xF0) != 0)
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
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            data->state = 23;
            break;
        case 1:
        case -1:
            if ((sPlayerActivityGroupSize & 0xF0) != 0)
                data->state = 15;
            else if (data->playerCount == (sPlayerActivityGroupSize & 0xF))
                data->state = 15;
            else
                data->state = 4;
            break;
        }
        break;
    case 17:
        if (!Leader_SetStateIfMemberListChanged(data, 7, 29))
            data->state = 18;
        break;
    case 18:
        if (LmanAcceptSlotFlagIsNotZero())
        {
            if (WaitRfuState(FALSE))
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
        LinkRfu_Shutdown();
        Leader_DestroyResources(data);
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
        if (RfuIsErrorStatus1or2())
        {
            data->state = 29;
        }
        else
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                if (IsActivityWithVariableGroupSize(gPlayerCurrActivity))
                    sub_801103C();
                UpdateGameData_GroupLockedIn(TRUE);
                CreateTask_RunScriptAndFadeToActivity();
                Leader_DestroyResources(data);
                DestroyTask(taskId);
            }
        }
        break;
    }
}

static void Leader_DestroyResources(struct WirelessLink_Leader *data)
{
    ClearWindowTilemap(data->nPlayerModeWindowId);
    ClearStdWindowAndFrame(data->nPlayerModeWindowId, FALSE);
    DestroyListMenuTask(data->listTaskId, 0, 0);
    ClearWindowTilemap(data->bButtonCancelWindowId);
    ClearStdWindowAndFrame(data->listWindowId, FALSE);
    CopyBgTilemapBufferToVram(0);
    RemoveWindow(data->nPlayerModeWindowId);
    RemoveWindow(data->listWindowId);
    RemoveWindow(data->bButtonCancelWindowId);
    DestroyTask(data->listenTaskId);

    Free(data->field_8);
    Free(data->field_0);
    Free(data->field_4);
}

static void Leader_GetAcceptNewMemberPrompt(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_BATTLE_TOWER:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouForXAccept);
        break;
    case ACTIVITY_WONDER_CARD2:
    case ACTIVITY_WONDER_NEWS2:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouShareX);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouAddToMembers);
        break;
    }
}

static void GetYouDeclinedTheOfferMessage(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_OfferDeclined1);
        break;
    case ACTIVITY_CHAT | IN_UNION_ROOM:
    case ACTIVITY_CARD | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_OfferDeclined2);
        break;
    }
}

static void GetYouAskedToJoinGroupPleaseWaitMessage(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_WONDER_CARD2:
    case ACTIVITY_WONDER_NEWS2:
        StringExpandPlaceholders(dst, sText_AwaitingPlayersResponse);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerHasBeenAskedToRegisterYouPleaseWait);
        break;
    }
}

static void GetGroupLeaderSentAnOKMessage(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_WONDER_CARD2:
    case ACTIVITY_WONDER_NEWS2:
        StringExpandPlaceholders(dst, sText_PlayerSentBackOK);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerOKdRegistration);
        break;
    }
}

static bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *data, u32 state1, u32 state2)
{
    switch (LeaderUpdateGroupMembership(data->field_0))
    {
    case UNION_ROOM_SPAWN_IN:
        PlaySE(SE_PC_LOGIN);
        RedrawListMenu(data->listTaskId);
        IntlConvPartnerUname7(gStringVar2, &data->field_0->arr[data->playerCount]);
        Leader_GetAcceptNewMemberPrompt(gStringVar4, gPlayerCurrActivity);
        data->state = state1;
        break;
    case UNION_ROOM_SPAWN_OUT:
        RfuSetErrorStatus(0, 0);
        RedrawListMenu(data->listTaskId);
        data->state = state2;
        return TRUE;
    }

    return FALSE;
}

static void ItemPrintFunc_PossibleGroupMembers(u8 windowId, s32 id, u8 y)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 var = 0;

    switch (data->field_0->arr[id].groupScheduledAnim)
    {
    case UNION_ROOM_SPAWN_IN:
        if (data->field_0->arr[id].field_1B != 0)
            var = 2;
        break;
    case UNION_ROOM_SPAWN_OUT:
        var = 1;
        break;
    }

    PrintGroupMemberCandidateOnWindowWithColor(windowId, 0, y, &data->field_0->arr[id], var, id);
}

static u8 LeaderUpdateGroupMembership(struct UnkStruct_Main0 *arg0)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 ret = UNION_ROOM_SPAWN_NONE;
    u8 i;
    s32 id;

    for (i = 1; i < 5; i++)
    {
        u16 var = data->field_0->arr[i].groupScheduledAnim;
        if (var == UNION_ROOM_SPAWN_IN)
        {
            id = Findx20Inx1CArray(&data->field_0->arr[i], data->field_4->arr);
            if (id != 0xFF)
            {
                data->field_0->arr[i].gname_uname = data->field_4->arr[id].gname_uname;
                data->field_0->arr[i].field_18 = 1;
            }
            else
            {
                data->field_0->arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                ret = UNION_ROOM_SPAWN_OUT;
            }
        }
    }

    for (id = 0; id < RFU_CHILD_MAX; id++)
        Appendx1Ctox20(data->field_0->arr, &data->field_4->arr[id], 5);

    if (ret != UNION_ROOM_SPAWN_OUT)
    {
        for (id = 0; id < 5; id++)
        {
            if (data->field_0->arr[id].field_1B != 0)
                ret = UNION_ROOM_SPAWN_IN;
        }
    }

    return ret;
}

static u8 sub_8013398(struct UnkStruct_Main0 *arg0)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 copiedCount;
    s32 i;
    u8 ret;

    for (i = 0; i < 5; i++)
        data->field_8->arr[i] = data->field_0->arr[i];

    copiedCount = 0;
    for (i = 0; i < 5; i++)
    {
        if (data->field_8->arr[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
        {
            data->field_0->arr[copiedCount] = data->field_8->arr[i];
            copiedCount++;
        }
    }

    ret = copiedCount;
    for (; copiedCount < 5; copiedCount++)
    {
        data->field_0->arr[copiedCount].gname_uname = sWirelessGnameUnamePair_Dummy;
        data->field_0->arr[copiedCount].field_18 = 0;
        data->field_0->arr[copiedCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
        data->field_0->arr[copiedCount].field_1A_1 = 0;
        data->field_0->arr[copiedCount].field_1B = 0;
    }

    for (i = 0; i < 5; i++)
    {
        if (data->field_0->arr[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
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
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_TryJoinLinkGroup, 0);
    sWirelessLinkMain.group = data = (void*)(gTasks[taskId].data);
    sGroup = data;

    data->state = 0;
    data->textState = 0;
    gSpecialVar_Result = 0;
}

static void Task_TryJoinLinkGroup(u8 taskId)
{
    s32 id;
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case 0:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToURoomActivity[gSpecialVar_0x8004];
        SetHostRFUtgtGname(gPlayerCurrActivity, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(16 * sizeof(struct UnkStruct_x20));
        data->state = 1;
        break;
    case 1:
        if (PrintOnTextbox(&data->textState, sChooseTrainerTexts[gSpecialVar_0x8004]))
            data->state = 2;
        break;
    case 2:
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 16);
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, gSpecialVar_0x8004);
        data->bButtonCancelWindowId = AddWindow(&sWindowTemplate_BButtonCancel);
        data->listWindowId = AddWindow(&gUnknown_082F0174);
        data->playerNameAndIdWindowId = AddWindow(&gUnknown_082F017C);

        FillWindowPixelBuffer(data->bButtonCancelWindowId, PIXEL_FILL(2));
        UR_AddTextPrinterParameterized(data->bButtonCancelWindowId, 0, sText_ChooseJoinCancel, 8, 1, 4);
        PutWindowTilemap(data->bButtonCancelWindowId);
        CopyWindowToVram(data->bButtonCancelWindowId, 2);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = sListMenuTemplate_UnionRoomGroups;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->playerNameAndIdWindowId, FALSE);
        PutWindowTilemap(data->playerNameAndIdWindowId);
        PrintPlayerNameAndIdOnWindow(data->playerNameAndIdWindowId);
        CopyWindowToVram(data->playerNameAndIdWindowId, 2);

        CopyBgTilemapBufferToVram(0);
        data->leaderId = 0;
        data->state = 3;
        break;
    case 3:
        id = GetNewLeaderCandidate();
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
                unusedVar  = data->field_0->arr[id].gname_uname.gname.activity;

                if (data->field_0->arr[id].groupScheduledAnim == UNION_ROOM_SPAWN_IN && !data->field_0->arr[id].gname_uname.gname.started)
                {
                    u32 var = IsTryingToTradeAcrossVersionTooSoon(data, id);
                    if (var == 0)
                    {
                        AskToJoinRfuGroup(data, id);
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
        GetYouAskedToJoinGroupPleaseWaitMessage(gStringVar4, gPlayerCurrActivity);
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
            data->state = 6;
        }
        break;
    case 6:
        if (gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = data->field_0->arr[data->leaderId].gname_uname.gname.activity;
            RfuSetErrorStatus(0, 0);
            switch (gPlayerCurrActivity)
            {
            case ACTIVITY_BATTLE_SINGLE:
            case ACTIVITY_BATTLE_DOUBLE:
            case ACTIVITY_BATTLE_MULTI:
            case ACTIVITY_TRADE:
            case ACTIVITY_CHAT:
            case ACTIVITY_POKEMON_JUMP:
            case ACTIVITY_BERRY_CRUSH:
            case ACTIVITY_BERRY_PICK:
            case ACTIVITY_SPIN_TRADE:
            case ACTIVITY_BATTLE_TOWER:
            case ACTIVITY_BATTLE_TOWER_OPEN:
            case ACTIVITY_RECORD_CORNER:
            case ACTIVITY_BERRY_BLENDER:
            case ACTIVITY_WONDER_CARD2:
            case ACTIVITY_WONDER_NEWS2:
            case ACTIVITY_CONTEST_COOL:
            case ACTIVITY_CONTEST_BEAUTY:
            case ACTIVITY_CONTEST_CUTE:
            case ACTIVITY_CONTEST_SMART:
            case ACTIVITY_CONTEST_TOUGH:
                data->state = 20;
                return;
            }
        }

        switch (RfuGetErrorStatus())
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
            GetGroupLeaderSentAnOKMessage(gStringVar4, gPlayerCurrActivity);
            if (PrintOnTextbox(&data->textState, gStringVar4))
            {
                if (gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER || gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER_OPEN)
                {
                    RfuSetErrorStatus(12, 0);
                }
                else
                {
                    RfuSetErrorStatus(7, 0);
                    StringCopy(gStringVar1, sLinkGroupActivityTexts[gPlayerCurrActivity]);
                    StringExpandPlaceholders(gStringVar4, sText_AwaitingOtherMembers);
                }
            }
            break;
        case 7:
            if (data->delayBeforePrint > 240)
            {
                if (PrintOnTextbox(&data->textState, gStringVar4))
                {
                    RfuSetErrorStatus(12, 0);
                    data->delayBeforePrint = 0;
                }
            }
            else
            {
                switch (gPlayerCurrActivity)
                {
                case ACTIVITY_BATTLE_SINGLE:
                case ACTIVITY_BATTLE_DOUBLE:
                case ACTIVITY_TRADE:
                case ACTIVITY_BATTLE_TOWER:
                case ACTIVITY_BATTLE_TOWER_OPEN:
                    break;
                default:
                    data->delayBeforePrint++;
                    break;
                }
            }
            break;
        }

        if (!RfuGetErrorStatus() && gMain.newKeys & B_BUTTON)
            data->state = 7;
        break;
    case 7:
        if (PrintOnTextbox(&data->textState, sText_QuitBeingMember))
            data->state = 8;
        break;
    case 8:
        switch (UnionRoomHandleYesNo(&data->textState, RfuGetErrorStatus()))
        {
        case 0:
            LinkRfuNIsend8();
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
        if (RfuGetErrorStatus())
            data->state = 6;
        break;
    case 10:
    case 12:
    case 14:
    case 18:
    case 20:
        ClearWindowTilemap(data->playerNameAndIdWindowId);
        ClearStdWindowAndFrame(data->playerNameAndIdWindowId, FALSE);
        DestroyListMenuTask(data->listTaskId, 0, 0);
        ClearWindowTilemap(data->bButtonCancelWindowId);
        ClearStdWindowAndFrame(data->listWindowId, FALSE);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->playerNameAndIdWindowId);
        RemoveWindow(data->listWindowId);
        RemoveWindow(data->bButtonCancelWindowId);
        DestroyTask(data->listenTaskId);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 13:
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetErrorStatus()]))
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
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetErrorStatus()]))
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
        JoinGroup_EnableScriptContexts();
        LinkRfu_Shutdown();
        break;
    case 21:
        CreateTask_RunScriptAndFadeToActivity();
        DestroyTask(taskId);
        break;
    }
}

static u32 IsTryingToTradeAcrossVersionTooSoon(struct WirelessLink_Group *data, s32 id)
{
    struct UnkStruct_x20 *structPtr = &data->field_0->arr[id];

    if (gPlayerCurrActivity == ACTIVITY_TRADE && structPtr->gname_uname.gname.unk_00.version != VERSION_EMERALD)
    {
        if (!(gSaveBlock2Ptr->specialSaveWarpFlags & CHAMPION_SAVEWARP))
            return 1;
        else if (structPtr->gname_uname.gname.unk_00.isChampion)
            return 0;
    }
    else
    {
        return 0;
    }

    return 2;
}

static void AskToJoinRfuGroup(struct WirelessLink_Group *data, s32 id)
{
    data->leaderId = id;
    LoadWirelessStatusIndicatorSpriteGfx();
    CreateWirelessStatusIndicatorSprite(0, 0);
    RedrawListMenu(data->listTaskId);
    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
    UpdateGameDataWithActivitySpriteGendersFlag(sLinkGroupToURoomActivity[gSpecialVar_0x8004], 0, 1);
    CreateTask_RfuReconnectWithParent(data->field_0->arr[data->leaderId].gname_uname.playerName, ReadAsU16(data->field_0->arr[data->leaderId].gname_uname.gname.unk_00.playerTrainerId));
}

u8 CreateTask_ListenToWireless(void)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_ListenToWireless, 0);
    sWirelessLinkMain.group = data = (void*)(gTasks[taskId].data);

    data->state = 0;
    data->textState = 0;

    sGroup = data;

    return taskId;
}

static void Task_ListenToWireless(u8 taskId)
{
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case 0:
        SetHostRFUtgtGname(0, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        sub_80111B0(TRUE);
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(16 * sizeof(struct UnkStruct_x20));
        data->state = 2;
        break;
    case 2:
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 16);
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, 0xFF);
        data->leaderId = 0;
        data->state = 3;
        break;
    case 3:
        if (GetNewLeaderCandidate() == 1)
            PlaySE(SE_PC_LOGIN);
        if (gTasks[taskId].data[15] == 0xFF)
            data->state = 10;
        break;
    case 10:
        DestroyTask(data->listenTaskId);
        Free(data->field_0);
        Free(data->field_4);
        LinkRfu_Shutdown();
        data->state++;
        break;
    case 11:
        LinkRfu_Shutdown();
        DestroyTask(taskId);
        break;
    }
}

static bool32 IsPartnerActivityAcceptable(u32 activity, u32 linkGroup)
{
    if (linkGroup == 0xFF)
        return TRUE;

    if (linkGroup <= ARRAY_COUNT(sAcceptedActivityIds)) // UB: <= may access data outside the array
    {
        const u8 *bytes = sAcceptedActivityIds[linkGroup];

        while ((*(bytes) != 0xFF))
        {
            if ((*bytes) == activity)
                return TRUE;
            bytes++;
        }
    }

    return FALSE;
}

static u8 URoomGroupListGetTextColor(struct WirelessLink_Group *data, u32 id)
{
    if (data->field_0->arr[id].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
    {
        if (data->field_0->arr[id].gname_uname.gname.started)
            return UR_COLOR_WHT_WHT_LTE;
        else if (data->field_0->arr[id].field_1A_1 != 0)
            return UR_COLOR_RED_WHT_LTR;
        else if (data->field_0->arr[id].field_1B != 0)
            return UR_COLOR_GRN_WHT_LTG;
    }

    return UR_COLOR_DKE_WHT_LTE;
}

static void ListMenuItemPrintFunc_UnionRoomGroups(u8 windowId, s32 id, u8 y)
{
    struct WirelessLink_Group *data = sWirelessLinkMain.group;
    u8 colorId = URoomGroupListGetTextColor(data, id);

    PrintUnionRoomGroupOnWindow(windowId, 8, y, &data->field_0->arr[id], colorId, id);
}

static u8 GetNewLeaderCandidate(void)
{
    struct WirelessLink_Group *data = sWirelessLinkMain.group;
    u8 ret = 0;
    u8 i;
    s32 id;

    for (i = 0; i < 16; i++)
    {
        if (data->field_0->arr[i].groupScheduledAnim != UNION_ROOM_SPAWN_NONE)
        {
            id = Findx20Inx1CArray(&data->field_0->arr[i], data->field_4->arr);
            if (id != 0xFF)
            {
                if (data->field_0->arr[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
                {
                    if (AreUnionRoomPlayerGnamesDifferent(&data->field_0->arr[i].gname_uname, &data->field_4->arr[id].gname_uname))
                    {
                        data->field_0->arr[i].gname_uname = data->field_4->arr[id].gname_uname;
                        data->field_0->arr[i].field_1B = 64;
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
                    data->field_0->arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
                    data->field_0->arr[i].field_1B = 64;
                    ret = 1;
                }

                data->field_0->arr[i].field_18 = 0;
            }
            else
            {
                if (data->field_0->arr[i].groupScheduledAnim != UNION_ROOM_SPAWN_OUT)
                {
                    data->field_0->arr[i].field_18++;
                    if (data->field_0->arr[i].field_18 >= 300)
                    {
                        data->field_0->arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                        ret = 2;
                    }
                }
            }
        }
    }

    for (id = 0; id < RFU_CHILD_MAX; id++)
    {
        if (Appendx1Ctox20(data->field_0->arr, &data->field_4->arr[id], 16) != 0xFF)
            ret = 1;
    }

    return ret;
}

static void Task_CreateTradeMenu(u8 taskId)
{
    CB2_StartCreateTradeMenu();
    DestroyTask(taskId);
}

u8 CreateTask_CreateTradeMenu(void)
{
    u8 taskId = CreateTask(Task_CreateTradeMenu, 0);

    return taskId;
}

static void Task_StartUnionRoomTrade(u8 taskId)
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

static void Task_ExchangeCards(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (GetMultiplayerId() == 0)
            sub_800A4D8(2);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (GetBlockReceivedStatus() == GetLinkPlayerCountAsBitFlags())
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
                MEventHandleReceivedWonderCard(recvBuff[48]);
            }
            else
            {
                ResetReceivedWonderCardFlag();
            }

            ResetBlockReceivedFlags();
            DestroyTask(taskId);
        }
        break;
    }
}

static void CB2_ShowCard(void)
{
    switch (gMain.state)
    {
    case 0:
        CreateTask(Task_ExchangeCards, 5);
        gMain.state++;
        break;
    case 1:
        if (!FuncIsActiveTask(Task_ExchangeCards))
            ShowTrainerCardInLink(GetMultiplayerId() ^ 1, CB2_ReturnToField);
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

void StartUnionRoomBattle(u16 battleFlags)
{
    HealPlayerParty();
    SavePlayerParty();
    LoadPlayerBag();
    gLinkPlayers[0].linkType = LINKTYPE_BATTLE;
    gLinkPlayers[GetMultiplayerId()].id = GetMultiplayerId();
    gLinkPlayers[GetMultiplayerId() ^ 1].id = GetMultiplayerId() ^ 1;
    gMain.savedCallback = CB2_ReturnFromCableClubBattle;
    gBattleTypeFlags = battleFlags;
    PlayBattleBGM();
}

// TODO: pokefirered bad name
static void sub_8014290(u16 linkService, u16 x, u16 y)
{
    VarSet(VAR_CABLE_CLUB_STATE, linkService);
    SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    SetDynamicWarpWithCoords(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    WarpIntoMap();
}

// TODO: pokefirered bad name
static void sub_8014304(s8 mapGroup, s8 mapNum, s32 x, s32 y, u16 linkService)
{
    gSpecialVar_0x8004 = linkService;
    VarSet(VAR_CABLE_CLUB_STATE, linkService);
    gFieldLinkPlayerCount = GetLinkPlayerCount();
    gLocalLinkPlayerId = GetMultiplayerId();
    SetCableClubWarp();
    SetWarpDestination(mapGroup, mapNum, -1, x, y);
    WarpIntoMap();
}

static void CB2_TransitionToCableClub(void)
{
    switch (gMain.state)
    {
    case 0:
        CreateTask(Task_ExchangeCards, 5);
        gMain.state++;
        break;
    case 1:
        if (!FuncIsActiveTask(Task_ExchangeCards))
            SetMainCallback2(CB2_ReturnToFieldCableClub);
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static void CreateTrainerCardInBuffer(void *dest, bool32 setWonderCard)
{
    u16 *argAsU16Ptr = dest;

    TrainerCard_GenerateCardForPlayer((struct TrainerCard *)argAsU16Ptr);
    if (setWonderCard)
        argAsU16Ptr[48] = GetWonderCardFlagID();
    else
        argAsU16Ptr[48] = 0;
}

static void Task_StartActivity(u8 taskId)
{
    ResetReceivedWonderCardFlag();
    switch (gPlayerCurrActivity)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_TRADE:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_SPIN_TRADE:
    case ACTIVITY_RECORD_CORNER:
        RecordMixTrainerNames();
        break;
    }

    switch (gPlayerCurrActivity)
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_ACCEPT | IN_UNION_ROOM:
        CleanupOverworldWindowsAndTilemaps();
        gMain.savedCallback = CB2_UnionRoomBattle;
        InitChooseHalfPartyForBattle(3);
        break;
    case ACTIVITY_BATTLE_SINGLE:
        CleanupOverworldWindowsAndTilemaps();
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_SINGLE_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_BATTLE_DOUBLE:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_DOUBLE_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_BATTLE_MULTI:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        sub_8014304(MAP_GROUP(BATTLE_COLOSSEUM_4P), MAP_NUM(BATTLE_COLOSSEUM_4P), 5, 8, USING_MULTI_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_TRADE:
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        sub_8014304(MAP_GROUP(TRADE_CENTER), MAP_NUM(TRADE_CENTER), 5, 8, USING_TRADE_CENTER);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_RECORD_CORNER:
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        sub_8014304(MAP_GROUP(RECORD_CORNER), MAP_NUM(RECORD_CORNER), 8, 9, USING_RECORD_CORNER);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        CleanupOverworldWindowsAndTilemaps();
        CreateTask(Task_StartUnionRoomTrade, 0);
        break;
    case ACTIVITY_CHAT:
    case ACTIVITY_CHAT | IN_UNION_ROOM:
        if (GetMultiplayerId() == 0)
        {
            LinkRfu_CreateConnectionAsParent();
        }
        else
        {
            LinkRfu_StopManagerBeforeEnteringChat();
            SetHostRFUtgtGname(69, 0, 1);
        }
        EnterUnionRoomChat();
        break;
    case ACTIVITY_CARD:
    case ACTIVITY_CARD | IN_UNION_ROOM:
        CreateTrainerCardInBuffer(gBlockSendBuffer, FALSE);
        SetMainCallback2(CB2_ShowCard);
        break;
    case ACTIVITY_POKEMON_JUMP:
        sub_8014290(USING_MINIGAME, 5, 1);
        StartPokemonJump(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    case ACTIVITY_BERRY_CRUSH:
        sub_8014290(USING_BERRY_CRUSH, 9, 1);
        StartBerryCrush(CB2_LoadMap);
        break;
    case ACTIVITY_BERRY_PICK:
        sub_8014290(USING_MINIGAME, 5, 1);
        StartDodrioBerryPicking(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    }

    DestroyTask(taskId);
    gSpecialVar_Result = 1;
    if (gPlayerCurrActivity != (ACTIVITY_TRADE | IN_UNION_ROOM))
        ScriptContext2_Disable();
}

static void Task_RunScriptAndFadeToActivity(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *sendBuff = (u16*)(gBlockSendBuffer);

    switch (data[0])
    {
    case 0:
        gSpecialVar_Result = LINKUP_SUCCESS;
        switch (gPlayerCurrActivity)
        {
        case ACTIVITY_BATTLE_TOWER:
        case ACTIVITY_BATTLE_TOWER_OPEN:
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
        case ACTIVITY_BERRY_BLENDER:
        case ACTIVITY_CONTEST_COOL:
        case ACTIVITY_CONTEST_BEAUTY:
        case ACTIVITY_CONTEST_CUTE:
        case ACTIVITY_CONTEST_SMART:
        case ACTIVITY_CONTEST_TOUGH:
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
            if (gPlayerCurrActivity == 29)
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
            CreateTask_StartActivity();
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
            if (AreBattleTowerLinkSpeciesSame(gBlockRecvBuffer[0], gBlockRecvBuffer[1]))
            {
                gSpecialVar_Result = LINKUP_FAILED_BATTLE_TOWER;
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

static void CreateTask_RunScriptAndFadeToActivity(void)
{
    CreateTask(Task_RunScriptAndFadeToActivity, 0);
}

static void CreateTask_StartActivity(void)
{
    u8 taskId = CreateTask(Task_StartActivity, 0);
    gTasks[taskId].data[0] = 0;
}

void MEvent_CreateTask_Leader(u32 activity)
{
    u8 taskId;
    struct WirelessLink_Leader *data;

    taskId = CreateTask(Task_MEvent_Leader, 0);
    sWirelessLinkMain.leader = data = (void*)(gTasks[taskId].data);

    data->state = 0;
    data->textState = 0;
    data->activity = activity;
    gSpecialVar_Result = 0;
}

static void Task_MEvent_Leader(u8 taskId)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    struct WindowTemplate winTemplate;
    s32 val;

    switch (data->state)
    {
    case 0:
        gPlayerCurrActivity = data->activity;
        sPlayerActivityGroupSize = 2;
        SetHostRFUtgtGname(data->activity, 0, 0);
        SetGnameBufferWonderFlags(FALSE, FALSE);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_LinkLeader(2);
        data->state = 1;
        break;
    case 1:
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        data->field_8 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 5);
        LinkRfu3_SetGnameUnameFromStaticBuffers(&data->field_0->arr[0].gname_uname.gname, data->field_0->arr[0].gname_uname.playerName);
        data->field_0->arr[0].field_18 = 0;
        data->field_0->arr[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
        data->field_0->arr[0].field_1A_1 = 0;
        data->field_0->arr[0].field_1B = 0;
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, 0xFF);

        winTemplate = gUnknown_082F011C;
        winTemplate.baseBlock = GetMysteryGiftBaseBlock();
        winTemplate.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate);
        MG_DrawTextBorder(data->listWindowId);
        gMultiuseListMenuTemplate = sListMenuTemplate_PossibleGroupMembers;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        CopyBgTilemapBufferToVram(0);
        data->playerCount = 1;
        data->state = 2;
        break;
    case 2:
        StringCopy(gStringVar1, sLinkGroupActivityTexts[gPlayerCurrActivity]);
        StringExpandPlaceholders_AwaitingCommFromAnother(gStringVar4, gPlayerCurrActivity);
        data->state = 3;
        break;
    case 3:
        AddTextPrinterToWindow1(gStringVar4);
        data->state = 4;
        break;
    case 4:
        Leader_SetStateIfMemberListChanged(data, 5, 6);
        if (gMain.newKeys & B_BUTTON)
        {
            data->state = 13;
            DestroyWirelessStatusIndicatorSprite();
        }
        break;
    case 6:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_LinkWithFriendDropped))
        {
            data->playerCount = sub_8013398(data->field_0);
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
            data->field_0->arr[data->playerCount].field_1B = 0;
            RedrawListMenu(data->listTaskId);
            data->field_19 = 5;
            SendByteToPartnerByIdAndName(5, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 8;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            SendByteToPartnerByIdAndName(6, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 8;
            break;
        }
        break;
    case 8:
        val = WaitSendByteToPartnerByIdAndName(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->playerCount].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->playerCount++;
                IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->playerCount - 1]);
                StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
                data->state = 9;
                LinkRfu_StopManagerAndFinalizeSlots();
            }
            else
            {
                RequestDisconnectSlotByTrainerNameAndId(data->field_0->arr[data->playerCount].gname_uname.playerName, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId));
                data->field_0->arr[data->playerCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
                sub_8013398(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = 2;
            }

            data->field_19 = 0;
        }
        else if (val == 2)
        {
            RfuSetErrorStatus(0, 0);
            data->state = 2;
        }
        break;
    case 9:
        AddTextPrinterToWindow1(gStringVar4);
        data->state = 10;
        break;
    case 10:
        if (++data->delayTimerAfterOk > 120)
            data->state = 11;
        break;
    case 11:
        if (!Leader_SetStateIfMemberListChanged(data, 5, 6))
            data->state = 12;
        break;
    case 12:
        if (LmanAcceptSlotFlagIsNotZero())
        {
            WaitRfuState(FALSE);
            data->state = 15;
        }
        else
        {
            data->state = 6;
        }
        break;
    case 13:
        DestroyWirelessStatusIndicatorSprite();
        LinkRfu_Shutdown();
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->listenTaskId);
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
        if (RfuGetErrorStatus() == 1 || RfuGetErrorStatus() == 2)
        {
            data->state = 13;
        }
        else if (gReceivedRemoteLinkPlayers != 0)
        {
            UpdateGameData_GroupLockedIn(TRUE);
            data->state++;
        }
        break;
    case 16:
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->listenTaskId);
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

void MEvent_CreateTask_CardOrNewsWithFriend(u32 activity)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_CardOrNewsWithFriend, 0);
    sWirelessLinkMain.group = data = (void*)(gTasks[taskId].data);
    sGroup = data;

    data->state = 0;
    data->textState = 0;
    data->isWonderNews = activity - ACTIVITY_WONDER_CARD2;
    gSpecialVar_Result = 0;
}

static void Task_CardOrNewsWithFriend(u8 taskId)
{
    s32 id;
    struct WindowTemplate winTemplate1, winTemplate2;
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case 0:
        SetHostRFUtgtGname(data->isWonderNews + ACTIVITY_WONDER_CARD2, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(16 * sizeof(struct UnkStruct_x20));
        data->state = 1;
        break;
    case 1:
        AddTextPrinterToWindow1(sText_ChooseTrainer);
        data->state = 2;
        break;
    case 2:
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 16);
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, data->isWonderNews + LINK_GROUP_WONDER_CARD);

        winTemplate1 = gUnknown_082F0174;
        winTemplate1.baseBlock = GetMysteryGiftBaseBlock();
        winTemplate1.paletteNum = 0xC;
        data->listWindowId = AddWindow(&winTemplate1);

        winTemplate2 = gUnknown_082F017C;
        winTemplate2.paletteNum = 0xC;
        data->playerNameAndIdWindowId = AddWindow(&winTemplate2);

        MG_DrawTextBorder(data->listWindowId);
        gMultiuseListMenuTemplate = sListMenuTemplate_UnionRoomGroups;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        MG_DrawTextBorder(data->playerNameAndIdWindowId);
        FillWindowPixelBuffer(data->playerNameAndIdWindowId, PIXEL_FILL(1));
        PutWindowTilemap(data->playerNameAndIdWindowId);
        PrintPlayerNameAndIdOnWindow(data->playerNameAndIdWindowId);
        CopyWindowToVram(data->playerNameAndIdWindowId, 2);

        CopyBgTilemapBufferToVram(0);
        data->leaderId = 0;
        data->state = 3;
        break;
    case 3:
        id = GetNewLeaderCandidate();
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
                unusedVar  = data->field_0->arr[id].gname_uname.gname.activity;

                if (data->field_0->arr[id].groupScheduledAnim == UNION_ROOM_SPAWN_IN && !data->field_0->arr[id].gname_uname.gname.started)
                {
                    data->leaderId = id;
                    LoadWirelessStatusIndicatorSpriteGfx();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                    RedrawListMenu(data->listTaskId);
                    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
                    CreateTask_RfuReconnectWithParent(data->field_0->arr[data->leaderId].gname_uname.playerName, ReadAsU16(data->field_0->arr[data->leaderId].gname_uname.gname.unk_00.playerTrainerId));
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
        IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
        data->state = 5;
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = data->field_0->arr[data->leaderId].gname_uname.gname.activity;
            data->state = 10;
        }

        switch (RfuGetErrorStatus())
        {
        case 1:
        case 2:
        case 6:
            data->state = 8;
            break;
        case 5:
            AddTextPrinterToWindow1(sText_PlayerSentBackOK);
            RfuSetErrorStatus(0, 0);
            break;
        }
        break;
    case 6:
    case 8:
    case 10:
        DestroyListMenuTask(data->listTaskId, 0, 0);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->playerNameAndIdWindowId);
        RemoveWindow(data->listWindowId);
        DestroyTask(data->listenTaskId);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 9:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sLinkDroppedTexts[RfuGetErrorStatus()]))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        DestroyWirelessStatusIndicatorSprite();
        AddTextPrinterToWindow1(sText_PleaseStartOver);
        DestroyTask(taskId);
        LinkRfu_Shutdown();
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

void MEvent_CreateTask_CardOrNewsOverWireless(u32 activity)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_CardOrNewsOverWireless, 0);
    sWirelessLinkMain.group = data = (void*)(gTasks[taskId].data);
    sGroup = data;

    data->state = 0;
    data->textState = 0;
    data->isWonderNews = activity - ACTIVITY_WONDER_CARD2;
    gSpecialVar_Result = 0;
}

static void Task_CardOrNewsOverWireless(u8 taskId)
{
    s32 id;
    struct WindowTemplate winTemplate;
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case 0:
        SetHostRFUtgtGname(0, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(16 * sizeof(struct UnkStruct_x20));
        data->state = 1;
        break;
    case 1:
        AddTextPrinterToWindow1(sText_SearchingForWirelessSystemWait);
        data->state = 2;
        break;
    case 2:
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 16);
        data->listenTaskId = CreateTask_ListenForPartnersWithSerial7F7D(data->field_4, data->isWonderNews + LINK_GROUP_WONDER_CARD);

        if (data->field_13 != 0)
        {
            winTemplate = gUnknown_082F0174;
            winTemplate.baseBlock = GetMysteryGiftBaseBlock();
            data->listWindowId = AddWindow(&winTemplate);

            MG_DrawTextBorder(data->listWindowId);
            gMultiuseListMenuTemplate = sListMenuTemplate_UnionRoomGroups;
            gMultiuseListMenuTemplate.windowId = data->listWindowId;
            data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

            CopyBgTilemapBufferToVram(0);
        }

        data->leaderId = 0;
        data->state = 3;
        break;
    case 3:
        id = GetNewLeaderCandidate();
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
            if (data->refreshTimer > 120)
            {
                if (data->field_0->arr[0].groupScheduledAnim == UNION_ROOM_SPAWN_IN && !data->field_0->arr[0].gname_uname.gname.started)
                {
                    if (HasWonderCardOrNewsByLinkGroup(&data->field_0->arr[0].gname_uname.gname, data->isWonderNews + LINK_GROUP_WONDER_CARD))
                    {
                        data->leaderId = 0;
                        data->refreshTimer = 0;
                        LoadWirelessStatusIndicatorSpriteGfx();
                        CreateWirelessStatusIndicatorSprite(0, 0);
                        CreateTask_RfuReconnectWithParent(data->field_0->arr[0].gname_uname.playerName, ReadAsU16(data->field_0->arr[0].gname_uname.gname.unk_00.playerTrainerId));
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
                data->refreshTimer = 0;
            }
            data->refreshTimer++;
            break;
        }
        break;
    case 4:
        AddTextPrinterToWindow1(sText_AwaitingResponseFromWirelessSystem);
        IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
        data->state = 5;
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = data->field_0->arr[data->leaderId].gname_uname.gname.activity;
            data->state = 12;
        }

        switch (RfuGetErrorStatus())
        {
        case 1:
        case 2:
        case 6:
            data->state = 8;
            break;
        case 5:
            AddTextPrinterToWindow1(sText_WirelessLinkEstablished);
            RfuSetErrorStatus(0, 0);
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
        DestroyTask(data->listenTaskId);
        Free(data->field_0);
        Free(data->field_4);
        data->state++;
        break;
    case 9:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_WirelessLinkDropped))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = 5;
        }
        break;
    case 7:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_WirelessSearchCanceled))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = 5;
        }
        break;
    case 11:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sNoWonderSharedTexts[data->isWonderNews]))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
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
    struct WirelessLink_URoom *data;

    ClearAndInitHostRFUtgtGname();
    CreateTask(Task_RunUnionRoom, 10);

    // dumb line needed to match
    sWirelessLinkMain.uRoom = sWirelessLinkMain.uRoom;

    data = AllocZeroed(sizeof(*sWirelessLinkMain.uRoom));
    sWirelessLinkMain.uRoom = data;
    sURoom = data;

    data->state = 0;
    data->textState = 0;
    data->field_10 = 0;
    data->field_12 = 0;

    gSpecialVar_Result = 0;
    ListMenuLoadStdPalAt(0xD0, 1);
}

static u16 ReadAsU16(const u8 *ptr)
{
    return (ptr[1] << 8) | (ptr[0]);
}

static void ScheduleFieldMessageWithFollowupState(u32 nextState, const u8 *src)
{
    struct WirelessLink_URoom *data = sWirelessLinkMain.uRoom;

    data->state = 8;
    data->stateAfterPrint = nextState;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

static void ScheduleFieldMessageAndExit(const u8 *src)
{
    struct WirelessLink_URoom *data = sWirelessLinkMain.uRoom;

    data->state = 26;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

static void sub_80156B0(struct WirelessLink_URoom *data)
{
    memcpy(&gDecompressionBuffer[0x3F00], data->field_0, 0x100);
}

static void sub_80156C8(struct WirelessLink_URoom *data)
{
    memcpy(data->field_0, &gDecompressionBuffer[0x3F00], 0x100);
}

static void Task_RunUnionRoom(u8 taskId)
{
    u32 id = 0;
    s32 var5 = 0;
    s32 playerGender = MALE;
    struct WirelessLink_URoom *data = sWirelessLinkMain.uRoom;
    s16 *taskData = gTasks[taskId].data;

    switch (data->state)
    {
    case 0:
        data->field_4 = AllocZeroed(RFU_CHILD_MAX * sizeof(struct UnkStruct_x1C));
        data->field_C = AllocZeroed(RFU_CHILD_MAX * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(8 * sizeof(struct UnkStruct_x20));
        data->field_8 = AllocZeroed(sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x20Array(data->field_0->arr, ARRAY_COUNT(data->field_0->arr));
        gPlayerCurrActivity = IN_UNION_ROOM;
        data->field_20 = CreateTask_SearchForChildOrParent(data->field_C, data->field_4, LINK_GROUP_UNION_ROOM_RESUME);
        InitUnionRoomPlayerObjects(data->objects);
        SetTilesAroundUnionRoomPlayersPassable();
        data->state = 1;
        break;
    case 1:
        CreateGroupMemberSpritesInvisible(data->spriteIds, taskData[0]);
        if (++taskData[0] == 8)
            data->state = 2;
        break;
    case 2:
        SetHostRFUtgtGname(IN_UNION_ROOM, 0, 0);
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_EnterUnionRoom();
        ClearUnkStruct_x20Array(&data->field_8->arr[0], 1);
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x1CArray(data->field_C, 4);
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
                UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                if (id >= PARTY_SIZE)
                {
                    ResetUnionRoomTrade(&sUnionRoomTrade);
                    SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                    ScheduleFieldMessageAndExit(sText_RegistrationCanceled);
                }
                else if (!RegisterTradeMonAndGetIsEgg(GetCursorSelectionMonId(), &sUnionRoomTrade))
                {
                    ScheduleFieldMessageWithFollowupState(52, sText_ChooseRequestedMonType);
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
                    ScheduleFieldMessageAndExit(sText_TradeCanceled);
                }
                else
                {
                    UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                    gPlayerCurrActivity = ACTIVITY_TRADE | IN_UNION_ROOM;
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
                UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
                PlaySE(SE_PC_LOGIN);
                StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                data->state = 42;
                gSpecialVar_Result = 0;
            }
            else if (gSpecialVar_Result == 11)
            {
                UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
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
                if (TrySetUnionRoomMemberFacePlayer(data->field_0, &taskData[0], &taskData[1], data->spriteIds))
                {
                    PlaySE(SE_SELECT);
                    UR_EnableScriptContext2AndFreezeObjectEvents();
                    data->state = 24;
                    break;
                }
                else if (PlayerIsTalkingToUnionRoomAide())
                {
                    UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
                    PlaySE(SE_PC_LOGIN);
                    UR_EnableScriptContext2AndFreezeObjectEvents();
                    StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                    data->state = 45;
                    break;
                }
            }

            switch (HandlePlayerListUpdate())
            {
            case 1:
                PlaySE(SE_PC_LOGIN);
            case 2:
                ScheduleUnionRoomPlayerRefresh(data);
                break;
            case 4:
                data->state = 11;
                UR_EnableScriptContext2AndFreezeObjectEvents();
                SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_NPCTALK | IN_UNION_ROOM, GetActivePartnerSpriteGenderParam(data), 0);
                break;
            }
            HandleUnionRoomPlayerRefresh(data);
        }
        break;
    case 23:
        if (!FuncIsActiveTask(Task_ShowStartMenu))
        {
            UpdateGameDataWithActivitySpriteGendersFlag(IN_UNION_ROOM, 0, FALSE);
            data->state = 4;
        }
        break;
    case 24:
        UR_RunTextPrinters_CheckPrinter0Active();
        playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
        UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
        switch (UnionRoomGetPlayerInteractionResponse(data->field_0, taskData[0], taskData[1], playerGender))
        {
        case 0:
            data->state = 26;
            break;
        case 1:
            sub_8012188(data->field_0->arr[taskData[1]].gname_uname.playerName, &data->field_0->arr[taskData[1]].gname_uname.gname, gPlayerCurrActivity);
            data->field_12 = id; // Should be just 0, but won't match any other way.
            data->state = 25;
            break;
        case 2:
            ScheduleFieldMessageWithFollowupState(19, gStringVar4);
            break;
        }
        break;
    case 25:
        UR_RunTextPrinters_CheckPrinter0Active();
        switch (RfuGetErrorStatus())
        {
        case 4:
            HandleCancelTrade(TRUE);
            data->state = 4;
            break;
        case 1:
        case 2:
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sText_TrainerAppearsBusy);
            else
                ScheduleFieldMessageWithFollowupState(30, sText_TrainerAppearsBusy);

            gPlayerCurrActivity = IN_UNION_ROOM;
            break;
        }

        if (gReceivedRemoteLinkPlayers)
        {
            CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
            CreateTask(Task_ExchangeCards, 5);
            data->state = 38;
        }
        break;
    case 38:
        if (!FuncIsActiveTask(Task_ExchangeCards))
        {
            if (gPlayerCurrActivity == (ACTIVITY_TRADE | IN_UNION_ROOM))
                ScheduleFieldMessageWithFollowupState(31, sText_AwaitingPlayersResponseAboutTrade);
            else
                data->state = 5;
        }
        break;
    case 30:
        if (!gReceivedRemoteLinkPlayers)
        {
            HandleCancelTrade(FALSE);
            UpdateUnionRoomMemberFacing(taskData[0], taskData[1], data->field_0);
            data->state = 2;
        }
        break;
    case 5:
        id = ConvPartnerUnameAndGetWhetherMetAlready(&data->field_0->arr[taskData[1]]);
        playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
        ScheduleFieldMessageWithFollowupState(6, sHiDoSomethingTexts[id][playerGender]);
        break;
    case 6:
        var5 = ListMenuHandler_AllItemsAvailable(&data->textState, &data->topListMenuWindowId, &data->topListMenuId, &sWindowTemplate_InviteToActivity, &sListMenuTemplate_InviteToActivity);
        if (var5 != -1)
        {
            if (!gReceivedRemoteLinkPlayers)
            {
                data->state = 28;
            }
            else
            {
                data->partnerYesNoResponse = 0;
                playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
                if (var5 == -2 || var5 == IN_UNION_ROOM)
                {
                    data->playerSendBuffer[0] = IN_UNION_ROOM;
                    sub_800FE50(data->playerSendBuffer);
                    StringCopy(gStringVar4, sIfYouWantToDoSomethingTexts[gLinkPlayers[0].gender]);
                    data->state = 32;
                }
                else
                {
                    gPlayerCurrActivity = var5;
                    sPlayerActivityGroupSize = (u32)(var5) >> 8;
                    if (gPlayerCurrActivity == (ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM) && !HasAtLeastTwoMonsOfLevel30OrLower())
                    {
                        ScheduleFieldMessageWithFollowupState(5, sText_NeedTwoMonsOfLevel30OrLower1);
                    }
                    else
                    {
                        data->playerSendBuffer[0] = gPlayerCurrActivity | 0x40;
                        sub_800FE50(data->playerSendBuffer);
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
        PollPartnerYesNoResponse(data);
        playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
        id = GetResponseIdx_InviteToURoomActivity(data->playerSendBuffer[0] & 0x3F);
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
        data->playerSendBuffer[0] = ACTIVITY_TRADE | IN_UNION_ROOM;
        data->playerSendBuffer[1] = sUnionRoomTrade.species;
        data->playerSendBuffer[2] = sUnionRoomTrade.level;
        sub_800FE50(data->playerSendBuffer);
        data->state = 29;
        break;
    case 29:
        if (!gReceivedRemoteLinkPlayers)
        {
            StringCopy(gStringVar4, sText_TrainerBattleBusy);
            data->state = 28;
        }
        else
        {
            PollPartnerYesNoResponse(data);
            if (data->partnerYesNoResponse == (ACTIVITY_ACCEPT | IN_UNION_ROOM))
            {
                if (gPlayerCurrActivity == ACTIVITY_CARD)
                {
                    ViewURoomPartnerTrainerCard(gStringVar4, data, FALSE);
                    data->state = 40;
                }
                else
                {
                    data->state = 13;
                }
            }
            else if (data->partnerYesNoResponse == (ACTIVITY_DECLINE | IN_UNION_ROOM))
            {
                data->state = 32;
                GetURoomActivityRejectMsg(gStringVar4, gPlayerCurrActivity | IN_UNION_ROOM, gLinkPlayers[0].gender);
                gPlayerCurrActivity = ACTIVITY_NONE;
            }
        }
        break;

    case 7:
        id = ConvPartnerUnameAndGetWhetherMetAlready(&data->field_0->arr[taskData[1]]);
        playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
        ScheduleFieldMessageWithFollowupState(6, sHiDoSomethingTexts[id][playerGender]);
        break;
    case 40:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            data->state = 41;
            sub_800ADF8();
            data->partnerYesNoResponse = 0;
            data->recvActivityRequest[0] = 0;
        }
        break;
    case 41:
        if (IsLinkTaskFinished())
        {
            if (GetMultiplayerId() == 0)
            {
                StringCopy(gStringVar1, gLinkPlayers[GetMultiplayerId() ^ 1].name);
                id = PlayerHasMetTrainerBefore(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
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
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            CopyBgTilemapBufferToVram(0);
            gPlayerCurrActivity = ACTIVITY_CHAT | IN_UNION_ROOM;
            UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_CHAT | IN_UNION_ROOM, 0, 1);
            sub_8012188(data->field_0->arr[taskData[1]].gname_uname.playerName, &data->field_0->arr[taskData[1]].gname_uname.gname, gPlayerCurrActivity);
            data->field_12 = taskData[1];
            data->state = 20;
            taskData[3] = 0;
            break;
        case 1:
        case -1:
            playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
            ScheduleFieldMessageAndExit(sDeclineBattleTexts[playerGender]);
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
        switch (RfuGetErrorStatus())
        {
        case 4:
            HandleCancelTrade(TRUE);
            data->state = 4;
            break;
        case 1:
        case 2:
            playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
            UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sChatDeclinedTexts[playerGender]);
            else
                ScheduleFieldMessageWithFollowupState(30, sChatDeclinedTexts[playerGender]);
            break;
        case 3:
            data->state = 22;
            break;
        }
        taskData[3]++;
        break;
    case 22:
        if (RfuIsErrorStatus1or2())
        {
            playerGender = GetUnionRoomPlayerGender(taskData[1], data->field_0);
            UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, 1);
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sChatDeclinedTexts[playerGender]);
            else
                ScheduleFieldMessageWithFollowupState(30, sChatDeclinedTexts[playerGender]);
        }
        if (gReceivedRemoteLinkPlayers)
            data->state = 16;
        break;
    case 11:
        PlaySE(SE_PINPON);
        sub_800EF7C();
        data->state = 12;
        data->recvActivityRequest[0] = 0;
        break;
    case 12:
        if (RfuIsErrorStatus1or2())
        {
            HandleCancelTrade(FALSE);
            data->state = 2;
        }
        else if (gReceivedRemoteLinkPlayers)
        {
            CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
            CreateTask(Task_ExchangeCards, 5);
            data->state = 39;
        }
        break;
    case 39:
        ReceiveUnionRoomActivityPacket(data);
        if (!FuncIsActiveTask(Task_ExchangeCards))
        {
            data->state = 33;
            StringCopy(gStringVar1, gLinkPlayers[1].name);
            id = PlayerHasMetTrainerBefore(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
            StringExpandPlaceholders(gStringVar4, sPlayerContactedYouTexts[id]);
        }
        break;
    case 33:
        ReceiveUnionRoomActivityPacket(data);
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = 34;
        break;
    case 34:
        ReceiveUnionRoomActivityPacket(data);
        if (UnionRoom_HandleContactFromOtherPlayer(data) && gMain.newKeys & B_BUTTON)
        {
            sub_8011DE0(1);
            StringCopy(gStringVar4, sText_ChatEnded);
            data->state = 36;
        }
        break;
    case 35:
        ScheduleFieldMessageWithFollowupState(9, gStringVar4);
        break;
    case 9:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            data->playerSendBuffer[0] = ACTIVITY_ACCEPT | IN_UNION_ROOM;
            if (gPlayerCurrActivity == (ACTIVITY_CHAT | IN_UNION_ROOM))
                UpdateGameDataWithActivitySpriteGendersFlag(gPlayerCurrActivity | 0x40, sub_801100C(1), 0);
            else
                UpdateGameDataWithActivitySpriteGendersFlag(gPlayerCurrActivity | 0x40, sub_801100C(1), 1);

            data->field_8->arr[0].field_1B = 0;
            taskData[3] = 0;
            if (gPlayerCurrActivity == (ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM))
            {
                if (!HasAtLeastTwoMonsOfLevel30OrLower())
                {
                    data->playerSendBuffer[0] = ACTIVITY_DECLINE | IN_UNION_ROOM;
                    sub_800FE50(data->playerSendBuffer);
                    data->state = 10;
                    StringCopy(gStringVar4, sText_NeedTwoMonsOfLevel30OrLower2);
                }
                else
                {
                    sub_800FE50(data->playerSendBuffer);
                    data->state = 13;
                }
            }
            else if (gPlayerCurrActivity == (ACTIVITY_CARD | IN_UNION_ROOM))
            {
                sub_800FE50(data->playerSendBuffer);
                ViewURoomPartnerTrainerCard(gStringVar4, data, TRUE);
                data->state = 40;
            }
            else
            {
                sub_800FE50(data->playerSendBuffer);
                data->state = 13;
            }
            break;
        case 1:
        case -1:
            data->playerSendBuffer[0] = ACTIVITY_DECLINE | IN_UNION_ROOM;
            sub_800FE50(data->playerSendBuffer);
            data->state = 10;
            GetYouDeclinedTheOfferMessage(gStringVar4, gPlayerCurrActivity);
            break;
        }
        break;
    case 10:
        sub_800AC34();
        data->state = 36;
        break;
    case 36:
        if (!gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = IN_UNION_ROOM;
            ScheduleFieldMessageWithFollowupState(37, gStringVar4);
            memset(data->playerSendBuffer, 0, sizeof(data->playerSendBuffer));
            data->recvActivityRequest[0] = 0;
            data->partnerYesNoResponse = 0;
        }
        break;
    case 37:
        data->state = 2;
        HandleCancelTrade(FALSE);
        break;
    case 13:
        GetURoomActivityStartMsg(gStringVar4, gPlayerCurrActivity | IN_UNION_ROOM);
        ScheduleFieldMessageWithFollowupState(14, gStringVar4);
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
        DestroyGroupMemberSprites(data->spriteIds);
        data->state = 17;
        break;
    case 17:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
        data->state = 18;
        break;
    case 18:
        if (!UpdatePaletteFade())
        {
            DestroyUnionRoomPlayerObjects();
            DestroyTask(taskId);
            Free(sWirelessLinkMain.uRoom);
            CreateTask_StartActivity();
        }
        break;
    case 42:
        if (GetHostRFUtgtGname()->species == SPECIES_NONE)
        {
            data->state = 43;
        }
        else
        {
            if (GetHostRFUtgtGname()->species == SPECIES_EGG)
            {
                StringCopy(gStringVar4, sText_CancelRegistrationOfEgg);
            }
            else
            {
                StringCopy(gStringVar1, gSpeciesNames[GetHostRFUtgtGname()->species]);
                ConvertIntToDecimalStringN(gStringVar2, GetHostRFUtgtGname()->level, STR_CONV_MODE_LEFT_ALIGN, 3);
                StringExpandPlaceholders(gStringVar4, sText_CancelRegistrationOfMon);
            }
            ScheduleFieldMessageWithFollowupState(44, gStringVar4);
        }
        break;
    case 43:
        if (PrintOnTextbox(&data->textState, sText_RegisterMonAtTradingBoard))
            data->state = 47;
        break;
    case 47:
        var5 = ListMenuHandler_AllItemsAvailable(&data->textState, &data->tradeBoardSelectWindowId, &data->tradeBoardDetailsWindowId, &gUnknown_082F025C, &gUnknown_082F027C);
        if (var5 != -1)
        {
            if (var5 == -2 || var5 == 3)
            {
                data->state = 4;
                HandleCancelTrade(TRUE);
            }
            else
            {
                switch (var5)
                {
                case 1: // REGISTER
                    ScheduleFieldMessageWithFollowupState(53, sText_WhichMonWillYouOffer);
                    break;
                case 2: // INFO
                    ScheduleFieldMessageWithFollowupState(47, sText_TradingBoardInfo);
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
        var5 = ListMenuHandler_AllItemsAvailable(&data->textState, &data->tradeBoardSelectWindowId, &data->tradeBoardDetailsWindowId, &gUnknown_082F0294, &sMenuTemplate_TradingBoardRequestType);
        if (var5 != -1)
        {
            switch (var5)
            {
            case -2:
            case 18:
                ResetUnionRoomTrade(&sUnionRoomTrade);
                SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                ScheduleFieldMessageAndExit(sText_RegistrationCanceled);
                break;
            default:
                sUnionRoomTrade.type = var5;
                data->state = 55;
                break;
            }
        }
        break;
    case 55:
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        ScheduleFieldMessageAndExit(sText_RegistraionCompleted);
        break;
    case 44:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            data->state = 56;
            break;
        case 1:
        case -1:
            HandleCancelTrade(TRUE);
            data->state = 4;
            break;
        }
        break;
    case 56:
        if (PrintOnTextbox(&data->textState, sText_RegistrationCanceled2))
        {
            SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
            ResetUnionRoomTrade(&sUnionRoomTrade);
            HandleCancelTrade(TRUE);
            data->state = 4;
        }
        break;
    case 45:
        if (PrintOnTextbox(&data->textState, sText_XCheckedTradingBoard))
            data->state = 46;
        break;
    case 46:
        UR_ClearBg0();
        data->state = 48;
        break;
    case 48:
        var5 = TradeBoardMenuHandler(&data->textState, &data->tradeBoardSelectWindowId, &data->field_4A, &data->tradeBoardDetailsWindowId, &gUnknown_082F034C, &sTradeBoardListMenuTemplate, data->field_0);
        if (var5 != -1)
        {
            switch (var5)
            {
            case -2:
            case 8:
                HandleCancelTrade(TRUE);
                data->state = 4;
                break;
            default:
                UR_ClearBg0();
                switch (IsRequestedTypeOrEggInPlayerParty(data->field_0->arr[var5].gname_uname.gname.type, data->field_0->arr[var5].gname_uname.gname.species))
                {
                case UR_TRADE_MATCH:
                    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[var5]);
                    ScheduleFieldMessageWithFollowupState(49, sText_AskTrainerToMakeTrade);
                    taskData[1] = var5;
                    break;
                case UR_TRADE_NOTYPE:
                    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].gname_uname.gname.type]);
                    ScheduleFieldMessageWithFollowupState(46, sText_DontHaveTypeTrainerWants);
                    break;
                case UR_TRADE_NOEGG:
                    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[var5]);
                    StringCopy(gStringVar2, gTypeNames[data->field_0->arr[var5].gname_uname.gname.type]);
                    ScheduleFieldMessageWithFollowupState(46, sText_DontHaveEggTrainerWants);
                    break;
                }
                break;
            }
        }
        break;
    case 49:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0:
            data->state = 50;
            break;
        case -1:
        case 1:
            HandleCancelTrade(TRUE);
            data->state = 4;
            break;
        }
        break;
    case 50:
        if (PrintOnTextbox(&data->textState, sText_WhichMonWillYouOffer))
        {
            sUnionRoomTrade.field_0 = 2;
            memcpy(&gPartnerTgtGnameSub, &data->field_0->arr[taskData[1]].gname_uname.gname.unk_00, sizeof(gPartnerTgtGnameSub));
            gUnionRoomRequestedMonType = data->field_0->arr[taskData[1]].gname_uname.gname.type;
            gUnionRoomOfferedSpecies = data->field_0->arr[taskData[1]].gname_uname.gname.species;
            gFieldCallback = FieldCB_ContinueScriptUnionRoom;
            ChooseMonForTradingBoard(PARTY_MENU_TYPE_UNION_ROOM_TRADE, CB2_ReturnToField);
            sub_80156B0(data);
            sUnionRoomTrade.field_8 = taskData[1];
        }
        break;
    case 51:
        gPlayerCurrActivity = ACTIVITY_TRADE | IN_UNION_ROOM;
        sub_8012188(data->field_0->arr[taskData[1]].gname_uname.playerName, &data->field_0->arr[taskData[1]].gname_uname.gname, 0x44);
        IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[taskData[1]]);
        UR_PrintFieldMessage(sCommunicatingWaitTexts[2]);
        data->state = 25;
        break;
    case 26:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            HandleCancelTrade(TRUE);
            UpdateUnionRoomMemberFacing(taskData[0], taskData[1], data->field_0);
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

static void ReceiveUnionRoomActivityPacket(struct WirelessLink_URoom *data)
{
    if (gRecvCmds[1][1] != 0 && (gRecvCmds[1][0] & 0xFF00) == 0x2F00)
    {
        data->recvActivityRequest[0] = gRecvCmds[1][1];
        if (gRecvCmds[1][1] == (ACTIVITY_TRADE | IN_UNION_ROOM))
        {
            data->recvActivityRequest[1] = gRecvCmds[1][2];
            data->recvActivityRequest[2] = gRecvCmds[1][3];
        }
    }
}

static bool32 UnionRoom_HandleContactFromOtherPlayer(struct WirelessLink_URoom *data)
{
    if (data->recvActivityRequest[0] != 0)
    {
        s32 var = GetChatLeaderActionRequestMessage(gStringVar4, gLinkPlayers[1].gender, &data->recvActivityRequest[0], data);
        if (var == 0)
        {
            return TRUE;
        }
        else if (var == 1)
        {
            data->state = 35;
            gPlayerCurrActivity = data->recvActivityRequest[0];
            return FALSE;
        }
        else if (var == 2)
        {
            data->state = 36;
            sub_800AC34();
            return FALSE;
        }
    }

    return TRUE;
}

void InitUnionRoom(void)
{
    struct WirelessLink_URoom *data;

    sUnionRoomPlayerName[0] = EOS;
    CreateTask(Task_InitUnionRoom, 0);
    sWirelessLinkMain.uRoom = sWirelessLinkMain.uRoom; // Needed to match.
    sWirelessLinkMain.uRoom = data = AllocZeroed(sizeof(struct WirelessLink_URoom));
    sURoom = sWirelessLinkMain.uRoom;
    data->state = 0;
    data->textState = 0;
    data->field_10 = 0;
    data->field_12 = 0;
    sUnionRoomPlayerName[0] = EOS;
}

static void Task_InitUnionRoom(u8 taskId)
{
    s32 i;
    u8 text[32];
    struct WirelessLink_URoom *data = sWirelessLinkMain.uRoom;

    switch (data->state)
    {
    case 0:
        data->state = 1;
        break;
    case 1:
        SetHostRFUtgtGname(ACTIVITY_SEARCH, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_EnterUnionRoom();
        sub_80111B0(TRUE);
        data->state = 2;
        break;
    case 2:
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        ClearUnkStruct_x1CArray(data->field_4, 4);
        data->field_C = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        ClearUnkStruct_x1CArray(data->field_C, 4);
        data->field_0 = AllocZeroed(8 * sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x20Array(data->field_0->arr, 8);
        data->field_8 = AllocZeroed(sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x20Array(&data->field_8->arr[0], 1);
        data->field_20 = CreateTask_SearchForChildOrParent(data->field_C, data->field_4, 10);
        data->state = 3;
        break;
    case 3:
        switch (HandlePlayerListUpdate())
        {
        case 1:
        case 2:
            if (sUnionRoomPlayerName[0] == EOS)
            {
                for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
                {
                    if (data->field_0->arr[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
                    {
                        IntlConvPartnerUname7(text, &data->field_0->arr[i]);
                        if (PlayerHasMetTrainerBefore(ReadAsU16(data->field_0->arr[i].gname_uname.gname.unk_00.playerTrainerId), text))
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
        free(data->field_8);
        free(data->field_0);
        free(data->field_C);
        free(data->field_4);
        DestroyTask(data->field_20);
        free(sWirelessLinkMain.uRoom);
        LinkRfu_Shutdown();
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

static u8 HandlePlayerListUpdate(void)
{
    s32 i;
    u8 j;
    struct WirelessLink_URoom *data = sWirelessLinkMain.uRoom;
    s32 r7 = 0;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (AreGnameUnameDifferent(&data->field_C->arr[i].gname_uname, &sWirelessGnameUnamePair_Dummy) == TRUE)
        {
            data->field_8->arr[0].gname_uname = data->field_C->arr[i].gname_uname;
            data->field_8->arr[0].field_18 = 0;
            data->field_8->arr[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
            data->field_8->arr[0].field_1B = 1;
            return 4;
        }
    }
    for (j = 0; j < ARRAY_COUNT(data->field_0->arr); j++)
    {
        if (data->field_0->arr[j].groupScheduledAnim != UNION_ROOM_SPAWN_NONE)
        {
            i = Findx20Inx1CArray(&data->field_0->arr[j], &data->field_4->arr[0]);
            if (i != 0xFF)
            {
                if (data->field_0->arr[j].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
                {
                    if (AreUnionRoomPlayerGnamesDifferent(&data->field_0->arr[j].gname_uname, &data->field_4->arr[i].gname_uname))
                    {
                        data->field_0->arr[j].gname_uname = data->field_4->arr[i].gname_uname;
                        data->field_0->arr[j].field_1B = 0x40;
                        r7 = 1;
                    }
                    else if (data->field_0->arr[j].field_1B != 0)
                    {
                        data->field_0->arr[j].field_1B--;
                        if (data->field_0->arr[j].field_1B == 0)
                            r7 = 2;
                    }
                }
                else
                {
                    data->field_0->arr[j].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
                    data->field_0->arr[j].field_1B = 0;
                    r7 = 2;
                }
                data->field_0->arr[j].field_18 = 0;
            }
            else if (data->field_0->arr[j].groupScheduledAnim != UNION_ROOM_SPAWN_OUT)
            {
                data->field_0->arr[j].field_18++;
                if (data->field_0->arr[j].field_18 >= 600)
                {
                    data->field_0->arr[j].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                    r7 = 2;
                }
            }
            else if (data->field_0->arr[j].groupScheduledAnim == UNION_ROOM_SPAWN_OUT)
            {
                data->field_0->arr[j].field_18++;
                if (data->field_0->arr[j].field_18 >= 900)
                {
                    ClearUnkStruct_x20Array(&data->field_0->arr[j], 1);
                }
            }
        }
    }
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Appendx1Ctox20(&data->field_0->arr[0], &data->field_4->arr[i], 8) != 0xFF)
            r7 = 1;
    }

    return r7;
}

static void Task_SearchForChildOrParent(u8 taskId)
{
    s32 i, j;
    struct WirelessGnameUnamePair gname_uname;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    bool8 isParent;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        isParent = LinkRfu_GetNameIfCompatible(&gname_uname.gname, gname_uname.playerName, i);
        if (!IsPartnerActivityAcceptable(gname_uname.gname.activity, gTasks[taskId].data[4]))
        {
            gname_uname = sWirelessGnameUnamePair_Dummy;
        }
        if (gname_uname.gname.unk_00.language == LANGUAGE_JAPANESE)
        {
            gname_uname = sWirelessGnameUnamePair_Dummy;
        }
        if (!isParent)
        {
            for (j = 0; j < i; j++)
            {
                if (!AreGnameUnameDifferent(&ptr[1]->arr[j].gname_uname, &gname_uname))
                {
                    gname_uname = sWirelessGnameUnamePair_Dummy;
                }
            }
            ptr[1]->arr[i].gname_uname = gname_uname;
            ptr[1]->arr[i].active = AreGnameUnameDifferent(&ptr[1]->arr[i].gname_uname, &sWirelessGnameUnamePair_Dummy);
        }
        else
        {
            ptr[0]->arr[i].gname_uname = gname_uname;
            ptr[0]->arr[i].active = AreGnameUnameDifferent(&ptr[0]->arr[i].gname_uname, &sWirelessGnameUnamePair_Dummy);
        }
    }
}

static u8 CreateTask_SearchForChildOrParent(struct UnkStruct_Main4 * main4_parent, struct UnkStruct_Main4 * main4_child, u32 linkGroup)
{
    u8 taskId = CreateTask(Task_SearchForChildOrParent, 0);
    struct UnkStruct_Main4 ** data = (void *)gTasks[taskId].data;
    data[0] = main4_parent;
    data[1] = main4_child;
    gTasks[taskId].data[4] = linkGroup;
    return taskId;
}

static void Task_ListenForPartnersWithCompatibleSerialNos(u8 taskId)
{
    s32 i, j;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        LinkRfu_GetNameIfCompatible(&ptr[0]->arr[i].gname_uname.gname, ptr[0]->arr[i].gname_uname.playerName, i);
        if (!IsPartnerActivityAcceptable(ptr[0]->arr[i].gname_uname.gname.activity, gTasks[taskId].data[2]))
        {
            ptr[0]->arr[i].gname_uname = sWirelessGnameUnamePair_Dummy;
        }
        for (j = 0; j < i; j++)
        {
            if (!AreGnameUnameDifferent(&ptr[0]->arr[j].gname_uname, &ptr[0]->arr[i].gname_uname))
            {
                ptr[0]->arr[i].gname_uname = sWirelessGnameUnamePair_Dummy;
            }
        }
        ptr[0]->arr[i].active = AreGnameUnameDifferent(&ptr[0]->arr[i].gname_uname, &sWirelessGnameUnamePair_Dummy);
    }
}

static bool32 HasWonderCardOrNewsByLinkGroup(struct GFtgtGname *gname, s16 linkGroup)
{
    if (linkGroup == LINK_GROUP_WONDER_CARD)
    {
        if (!gname->unk_00.hasCard)
            return FALSE;
        else
            return TRUE;
    }
    else if (linkGroup == LINK_GROUP_WONDER_NEWS)
    {
        if (!gname->unk_00.hasNews)
            return FALSE;
        else
            return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_ListenForPartnersWithSerial7F7D(u8 taskId)
{
    s32 i;
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (LinkRfu_GetNameIfSerial7F7D(&ptr[0]->arr[i].gname_uname.gname, ptr[0]->arr[i].gname_uname.playerName, i))
        {
            HasWonderCardOrNewsByLinkGroup(&ptr[0]->arr[i].gname_uname.gname, gTasks[taskId].data[2]);
        }
        ptr[0]->arr[i].active = AreGnameUnameDifferent(&ptr[0]->arr[i].gname_uname, &sWirelessGnameUnamePair_Dummy);
    }
}

static u8 CreateTask_ListenForPartnersWithCompatibleSerialNos(struct UnkStruct_Main4 * main4, u32 linkGroup)
{
    u8 taskId = CreateTask(Task_ListenForPartnersWithCompatibleSerialNos, 0);
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    ptr[0] = main4;
    gTasks[taskId].data[2] = linkGroup;
    return taskId;
}

static u8 CreateTask_ListenForPartnersWithSerial7F7D(struct UnkStruct_Main4 * main4, u32 linkGroup)
{
    u8 taskId = CreateTask(Task_ListenForPartnersWithSerial7F7D, 0);
    struct UnkStruct_Main4 **ptr = (void*) gTasks[taskId].data;
    ptr[0] = main4;
    gTasks[taskId].data[2] = linkGroup;
    return taskId;
}

static bool32 UR_PrintFieldMessage(const u8 *src)
{
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, 1);
    StringExpandPlaceholders(gStringVar4, src);
    AddTextPrinterWithCustomSpeedForMessage(FALSE, 1);
    return FALSE;
}

static bool32 UR_RunTextPrinters_CheckPrinter0Active(void)
{
    if (!RunTextPrintersAndIsPrinter0Active())
        return TRUE;
    else
        return FALSE;
}

static bool8 PrintOnTextbox(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        LoadMessageBoxAndBorderGfx();
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

static s8 UnionRoomHandleYesNo(u8 *state, bool32 noDraw)
{
    s8 r1;

    switch (*state)
    {
    case 0:
        if (noDraw)
        {
            return -3;
        }
        DisplayYesNoMenuDefaultYes();
        (*state)++;
        break;
    case 1:
        if (noDraw)
        {
            sub_8198C78();
            *state = 0;
            return -3;
        }
        r1 = Menu_ProcessInputNoWrapClearOnChoose();
        if (r1 == -1 || r1 == 0 || r1 == 1)
        {
            *state = 0;
            return r1;
        }
        break;
    }
    return -2;
}

static u8 CreateTradeBoardWindow(const struct WindowTemplate * template)
{
    u8 windowId = AddWindow(template);
    DrawStdWindowFrame(windowId, FALSE);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    UR_AddTextPrinterParameterized(windowId, 1, sText_NameWantedOfferLv, 8, 1, 6);
    CopyWindowToVram(windowId, 2);
    PutWindowTilemap(windowId);
    return windowId;
}

static void DeleteTradeBoardWindow(u8 windowId)
{
    RemoveWindow(windowId);
}

static s32 ListMenuHandler_AllItemsAvailable(u8 *state, u8 *windowId, u8 *listMenuId, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate)
{
    s32 maxWidth, input;
    struct WindowTemplate winTemplateCopy;

    switch (*state)
    {
    case 0:
        winTemplateCopy = *winTemplate;
        maxWidth = Intl_GetListMenuWidth(menuTemplate);
        if (winTemplateCopy.width > maxWidth)
        {
            winTemplateCopy.width = maxWidth;
        }
        if (winTemplateCopy.tilemapLeft + winTemplateCopy.width > 29)
        {
            winTemplateCopy.tilemapLeft = max(29 - winTemplateCopy.width, 0);
        }
        *windowId = AddWindow(&winTemplateCopy);
        DrawStdWindowFrame(*windowId, FALSE);
        gMultiuseListMenuTemplate = *menuTemplate;
        gMultiuseListMenuTemplate.windowId = *windowId;
        *listMenuId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        CopyWindowToVram(*windowId, TRUE);
        (*state)++;
        break;
    case 1:
        input = ListMenu_ProcessInput(*listMenuId);
        if (({gMain.newKeys & A_BUTTON;}))
        {
            DestroyListMenuTask(*listMenuId, NULL, NULL);
            ClearStdWindowAndFrame(*windowId, TRUE);
            RemoveWindow(*windowId);
            *state = 0;
            return input;
        }
        else if (({gMain.newKeys & B_BUTTON;}))
        {
            DestroyListMenuTask(*listMenuId, NULL, NULL);
            ClearStdWindowAndFrame(*windowId, TRUE);
            RemoveWindow(*windowId);
            *state = 0;
            return -2;
        }
        break;
    }

    return -1;
}

static s32 TradeBoardMenuHandler(u8 *state, u8 *windowId, u8 *listMenuId, u8 *tradeBoardWindowId, const struct WindowTemplate *winTemplate, const struct ListMenuTemplate *menuTemplate, struct UnkStruct_Main0 *traders)
{
    s32 input;
    s32 idx;

    switch (*state)
    {
    case 0:
        *tradeBoardWindowId = CreateTradeBoardWindow(&gUnknown_082F0344);
        *windowId = AddWindow(winTemplate);
        DrawStdWindowFrame(*windowId, FALSE);
        gMultiuseListMenuTemplate = *menuTemplate;
        gMultiuseListMenuTemplate.windowId = *windowId;
        *listMenuId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 1);
        (*state)++;
        break;
    case 1:
        CopyWindowToVram(*windowId, TRUE);
        (*state)++;
        break;
    case 2:
        // Register swap r1 <---> r2
        input = ListMenu_ProcessInput(*listMenuId);
        if (({gMain.newKeys & (A_BUTTON | B_BUTTON);}))
        {
            if (input == 8 || ({gMain.newKeys & B_BUTTON;}))
            {
                DestroyListMenuTask(*listMenuId, NULL, NULL);
                RemoveWindow(*windowId);
                DeleteTradeBoardWindow(*tradeBoardWindowId);
                *state = 0;
                return -2;
            }
            else
            {
                idx = GetIndexOfNthTradeBoardOffer(traders->arr, input);
                if (idx >= 0)
                {
                    DestroyListMenuTask(*listMenuId, NULL, NULL);
                    RemoveWindow(*windowId);
                    DeleteTradeBoardWindow(*tradeBoardWindowId);
                    *state = 0;
                    return idx;
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

static void UR_ClearBg0(void)
{
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
}

static void JoinGroup_EnableScriptContexts(void)
{
    EnableBothScriptContexts();
}

static void UR_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 colorIdx)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.unk = 0;

    gTextFlags.useAlternateDownArrow = FALSE;
    switch (colorIdx)
    {
    case UR_COLOR_DKE_WHT_LTE:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_DARK_GREY;
        printerTemplate.bgColor = TEXT_COLOR_WHITE;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_GREY;
        break;
    case UR_COLOR_RED_WHT_LTR:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_RED;
        printerTemplate.bgColor = TEXT_COLOR_WHITE;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_RED;
        break;
    case UR_COLOR_GRN_WHT_LTG:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_GREEN;
        printerTemplate.bgColor = TEXT_COLOR_WHITE;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_GREEN;
        break;
    case UR_COLOR_WHT_WHT_LTE:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_WHITE;
        printerTemplate.bgColor = TEXT_COLOR_WHITE;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_GREY;
        break;
    case UR_COLOR_WHT_DKE_LTE:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_WHITE;
        printerTemplate.bgColor = TEXT_COLOR_DARK_GREY;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_GREY;
        break;
    case UR_COLOR_GRN_DN6_LTB:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_COLOR_LIGHT_GREEN;
        printerTemplate.bgColor = TEXT_DYNAMIC_COLOR_6;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_BLUE;
        break;
    case UR_COLOR_DN5_DN6_LTB:
        printerTemplate.letterSpacing = 0;
        printerTemplate.lineSpacing = 0;
        printerTemplate.fgColor = TEXT_DYNAMIC_COLOR_5;
        printerTemplate.bgColor = TEXT_DYNAMIC_COLOR_6;
        printerTemplate.shadowColor = TEXT_COLOR_LIGHT_BLUE;
        break;
    }

    AddTextPrinter(&printerTemplate, 0xFF, NULL);
}

static void ClearUnkStruct_x20Array(struct UnkStruct_x20 *arr, u8 count)
{
    s32 i;

    for (i = 0; i < count; i++)
    {
        arr[i].gname_uname = sWirelessGnameUnamePair_Dummy;
        arr[i].field_18 = 0xFF;
        arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
        arr[i].field_1A_1 = 0;
        arr[i].field_1B = 0;
    }
}

static void ClearUnkStruct_x1CArray(struct UnkStruct_Main4 *main4, u8 count)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        main4->arr[i].gname_uname = sWirelessGnameUnamePair_Dummy;
        main4->arr[i].active = FALSE;
    }
}

static bool8 AreGnameUnameDifferent(struct WirelessGnameUnamePair* pair1, const struct WirelessGnameUnamePair* pair2)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        if (pair1->gname.unk_00.playerTrainerId[i] != pair2->gname.unk_00.playerTrainerId[i])
        {
            return TRUE;
        }
    }

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
    {
        if (pair1->playerName[i] != pair2->playerName[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 AreUnionRoomPlayerGnamesDifferent(struct WirelessGnameUnamePair *pair1, struct WirelessGnameUnamePair *pair2)
{
    s32 i;

    if (pair1->gname.activity != pair2->gname.activity)
    {
        return TRUE;
    }

    if (pair1->gname.started != pair2->gname.started)
    {
        return TRUE;
    }

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (pair1->gname.child_sprite_gender[i] != pair2->gname.child_sprite_gender[i])
        {
            return TRUE;
        }
    }

    if (pair1->gname.species != pair2->gname.species)
    {
        return TRUE;
    }

    if (pair1->gname.type != pair2->gname.type)
    {
        return TRUE;
    }

    return FALSE;
}

static u32 Findx20Inx1CArray(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1)
{
    u8 result = 0xFF;
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (arg1[i].active && !AreGnameUnameDifferent(&arg0->gname_uname, &arg1[i].gname_uname))
        {
            result = i;
            arg1[i].active = FALSE;
        }
    }

    return result;
}

static u8 Appendx1Ctox20(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1, u8 arg2)
{
    s32 i;

    if (arg1->active)
    {
        for (i = 0; i < arg2; i++)
        {
            if (arg0[i].groupScheduledAnim == UNION_ROOM_SPAWN_NONE)
            {
                arg0[i].gname_uname = arg1->gname_uname;
                arg0[i].field_18 = 0;
                arg0[i].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
                arg0[i].field_1B = 64;
                arg1->active = FALSE;
                return i;
            }
        }
    }

    return 0xFF;
}

static void PrintUnionRoomGroupOnWindow(u8 windowId, u8 x, u8 y, struct UnkStruct_x20 *group, u8 colorIdx, u8 id)
{
    u8 activity;
    u8 trainerId[6];

    ConvertIntToDecimalStringN(gStringVar4, id + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringAppend(gStringVar4, sText_Colon);
    UR_AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, 0);
    x += 18;
    activity = group->gname_uname.gname.activity;
    if (group->groupScheduledAnim == UNION_ROOM_SPAWN_IN && !(activity & IN_UNION_ROOM))
    {
        IntlConvPartnerUname7(gStringVar4, group);
        UR_AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, colorIdx);
        ConvertIntToDecimalStringN(trainerId, group->gname_uname.gname.unk_00.playerTrainerId[0] | (group->gname_uname.gname.unk_00.playerTrainerId[1] << 8), STR_CONV_MODE_LEADING_ZEROS, 5);
        StringCopy(gStringVar4, sText_ID);
        StringAppend(gStringVar4, trainerId);
        UR_AddTextPrinterParameterized(windowId, 1, gStringVar4, GetStringRightAlignXOffset(1, gStringVar4, 0x88), y, colorIdx);
    }
}

static void PrintGroupMemberCandidateOnWindowWithColor(u8 windowId, u8 x, u8 y, struct UnkStruct_x20 *group, u8 colorIdx, u8 id)
{
    u8 trainerId[6];

    if (group->groupScheduledAnim == UNION_ROOM_SPAWN_IN)
    {
        IntlConvPartnerUname7(gStringVar4, group);
        UR_AddTextPrinterParameterized(windowId, 1, gStringVar4, x, y, colorIdx);
        ConvertIntToDecimalStringN(trainerId, group->gname_uname.gname.unk_00.playerTrainerId[0] | (group->gname_uname.gname.unk_00.playerTrainerId[1] << 8), STR_CONV_MODE_LEADING_ZEROS, 5);
        StringCopy(gStringVar4, sText_ID);
        StringAppend(gStringVar4, trainerId);
        UR_AddTextPrinterParameterized(windowId, 1, gStringVar4, GetStringRightAlignXOffset(1, gStringVar4, 0x68), y, colorIdx);
    }
}

static bool32 PlayerIsTalkingToUnionRoomAide(void)
{
    s16 x, y;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    if (x != 9)
        return FALSE;

    if (y != 8)
        return FALSE;

    if (gPlayerAvatar.tileTransitionState == 2 || gPlayerAvatar.tileTransitionState == 0)
        return TRUE;

    return FALSE;
}

static u32 GetResponseIdx_InviteToURoomActivity(s32 activity)
{
    switch (activity)
    {
    case ACTIVITY_CHAT:
        return 1;
    case ACTIVITY_TRADE:
        return 2;
    case ACTIVITY_CARD:
        return 3;
    case ACTIVITY_BATTLE_MULTI:
    default:
        return 0;
    }
}

static u32 ConvPartnerUnameAndGetWhetherMetAlready(struct UnkStruct_x20 *arg0)
{
    u8 name[30];
    IntlConvPartnerUname7(name, arg0);
    return PlayerHasMetTrainerBefore(ReadAsU16(arg0->gname_uname.gname.unk_00.playerTrainerId), name);
}

static s32 UnionRoomGetPlayerInteractionResponse(struct UnkStruct_Main0 *main0, bool8 overrideGender, u8 playerIdx, u32 playerGender)
{
    bool32 metBefore;

    struct UnkStruct_x20 * r5 = &main0->arr[playerIdx];

    if (!r5->gname_uname.gname.started && !overrideGender)
    {
        IntlConvPartnerUname7(gStringVar1, r5);
        metBefore = PlayerHasMetTrainerBefore(ReadAsU16(r5->gname_uname.gname.unk_00.playerTrainerId), gStringVar1);
        if (r5->gname_uname.gname.activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
        {
            StringExpandPlaceholders(gStringVar4, sJoinChatTexts[metBefore][playerGender]);
            return 2;
        }
        else
        {
            UR_PrintFieldMessage(sCommunicatingWaitTexts[metBefore]);
            return 1;
        }
    }
    else
    {
        IntlConvPartnerUname7(gStringVar1, r5);
        if (overrideGender)
        {
            playerGender = (r5->gname_uname.gname.unk_00.playerTrainerId[overrideGender + 1] >> 3) & 1;
        }
        switch (r5->gname_uname.gname.activity & 0x3F)
        {
        case ACTIVITY_BATTLE_SINGLE:
            StringExpandPlaceholders(gStringVar4, sBattleReactionTexts[playerGender][Random() % ARRAY_COUNT(sBattleReactionTexts[0])]);
            break;
        case ACTIVITY_TRADE:
            StringExpandPlaceholders(gStringVar4, sTradeReactionTexts[playerGender][Random() % 2]);
            break;
        case ACTIVITY_CHAT:
            StringExpandPlaceholders(gStringVar4, sChatReactionTexts[playerGender][Random() % ARRAY_COUNT(sChatReactionTexts[0])]);
            break;
        case ACTIVITY_CARD:
            StringExpandPlaceholders(gStringVar4, sTrainerCardReactionTexts[playerGender][Random() % ARRAY_COUNT(sTrainerCardReactionTexts[0])]);
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

static void TradeBoardPrintItemInfo(u8 windowId, u8 y, struct GFtgtGname * gname, const u8 * uname, u8 colorIdx)
{
    u8 levelStr[4];
    u16 species = gname->species;
    u8 type = gname->type;
    u8 level = gname->level;

    UR_AddTextPrinterParameterized(windowId, 1, uname, 8, y, colorIdx);
    if (species == SPECIES_EGG)
    {
        UR_AddTextPrinterParameterized(windowId, 1, sText_EggTrade, 0x44, y, colorIdx);
    }
    else
    {
        blit_move_info_icon(windowId, type + 1, 0x44, y);
        UR_AddTextPrinterParameterized(windowId, 1, gSpeciesNames[species], 0x76, y, colorIdx);
        ConvertIntToDecimalStringN(levelStr, level, STR_CONV_MODE_RIGHT_ALIGN, 3);
        UR_AddTextPrinterParameterized(windowId, 1, levelStr, 0xC6, y, colorIdx);
    }
}

static void TradeBoardListMenuItemPrintFunc(u8 windowId, s32 itemId, u8 y)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    struct GFtgtGname *rfu;
    s32 i, j;
    u8 playerName[11];

    if (itemId == -3 && y == sTradeBoardListMenuTemplate.upText_Y)
    {
        rfu = GetHostRFUtgtGname();
        if (rfu->species != SPECIES_NONE)
        {
            TradeBoardPrintItemInfo(windowId, y, rfu, gSaveBlock2Ptr->playerName, 5);
        }
    }
    else
    {
        j = 0;
        for (i = 0; i < (int)ARRAY_COUNT(data->field_0->arr); i++)
        {
            if (data->field_0->arr[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN && data->field_0->arr[i].gname_uname.gname.species != SPECIES_NONE)
            {
                j++;
            }
            if (j == itemId + 1)
            {
                IntlConvPartnerUname7(playerName, &data->field_0->arr[i]);
                TradeBoardPrintItemInfo(windowId, y, &data->field_0->arr[i].gname_uname.gname, playerName, 6);
                break;
            }
        }
    }
}

static s32 GetIndexOfNthTradeBoardOffer(struct UnkStruct_x20 * arg, s32 n)
{
    s32 i;
    s32 j = 0;

    for (i = 0; i < 8; i++)
    {
        if (arg[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN && arg[i].gname_uname.gname.species != SPECIES_NONE)
        {
            j++;
        }
        if (j == n + 1)
        {
            return i;
        }
    }

    return -1;
}

static s32 GetUnionRoomPlayerGender(s32 playerIdx, struct UnkStruct_Main0 *main0)
{
    return main0->arr[playerIdx].gname_uname.gname.playerGender;
}

static s32 IsRequestedTypeOrEggInPlayerParty(u32 type, u32 species)
{
    s32 i;

    if (species == SPECIES_EGG)
    {
        for (i = 0; i < gPlayerPartyCount; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (species == SPECIES_EGG)
            {
                return UR_TRADE_MATCH;
            }
        }
        return UR_TRADE_NOEGG;
    }
    else
    {
        for (i = 0; i < gPlayerPartyCount; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (gBaseStats[species].type1 == type || gBaseStats[species].type2 == type)
            {
                return UR_TRADE_MATCH;
            }
        }
        return UR_TRADE_NOTYPE;
    }
}

static void GetURoomActivityRejectMsg(u8 *dst, s32 acitivty, u32 playerGender)
{
    switch (acitivty)
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sBattleDeclinedTexts[playerGender]);
        break;
    case ACTIVITY_CHAT | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sChatDeclinedTexts[playerGender]);
        break;
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_TradeOfferRejected);
        break;
    case ACTIVITY_CARD | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sShowTrainerCardDeclinedTexts[playerGender]);
        break;
    }
}

static void GetURoomActivityStartMsg(u8 *dst, u8 acitivty)
{
    u8 mpId = GetMultiplayerId();
    u8 gender = gLinkPlayers[mpId ^ 1].gender;

    switch (acitivty)
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
        StringCopy(dst, sStartActivityTexts[mpId][gender][0]);
        break;
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        StringCopy(dst, sStartActivityTexts[mpId][gender][2]);
        break;
    case ACTIVITY_CHAT | IN_UNION_ROOM:
        StringCopy(dst, sStartActivityTexts[mpId][gender][1]);
        break;
    }
}

static s32 GetChatLeaderActionRequestMessage(u8 *dst, u32 gender, u16 *activityData, struct WirelessLink_URoom *uroom)
{
    s32 result = 0;
    u16 species = SPECIES_NONE;
    s32 i;

    switch (activityData[0])
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_BattleChallenge);
        result = 1;
        break;
    case ACTIVITY_CHAT | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_ChatInvitation);
        result = 1;
        break;
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        ConvertIntToDecimalStringN(uroom->activityRequestStrbufs[0], sUnionRoomTrade.playerLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(uroom->activityRequestStrbufs[1], gSpeciesNames[sUnionRoomTrade.playerSpecies]);
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (gRfuLinkStatus->partner[i].serialNo == 2)
            {
                ConvertIntToDecimalStringN(uroom->activityRequestStrbufs[2], activityData[2], STR_CONV_MODE_LEFT_ALIGN, 3);
                StringCopy(uroom->activityRequestStrbufs[3], gSpeciesNames[activityData[1]]);
                species = activityData[1];
                break;
            }
        }
        if (species == SPECIES_EGG)
        {
            StringCopy(dst, sText_OfferToTradeEgg);
        }
        else
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                DynamicPlaceholderTextUtil_SetPlaceholderPtr(i, uroom->activityRequestStrbufs[i]);
            }
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dst, sText_OfferToTradeMon);
        }
        result = 1;
        break;
    case ACTIVITY_CARD | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_ShowTrainerCard);
        result = 1;
        break;
    case IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_ChatDropped);
        result = 2;
        break;
    }

    return result;
}

static bool32 PollPartnerYesNoResponse(struct WirelessLink_URoom *data)
{
    if (gRecvCmds[0][1] != 0)
    {
        if (gRecvCmds[0][1] == (ACTIVITY_ACCEPT | IN_UNION_ROOM))
        {
            data->partnerYesNoResponse = ACTIVITY_ACCEPT | IN_UNION_ROOM;
            return TRUE;
        }
        else if (gRecvCmds[0][1] == (ACTIVITY_DECLINE | IN_UNION_ROOM))
        {
            data->partnerYesNoResponse = ACTIVITY_DECLINE | IN_UNION_ROOM;
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

static bool32 HasAtLeastTwoMonsOfLevel30OrLower(void)
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

static void ResetUnionRoomTrade(struct UnionRoomTrade *uroomTrade)
{
    uroomTrade->field_0 = 0;
    uroomTrade->type = 0;
    uroomTrade->playerPersonality = 0;
    uroomTrade->playerSpecies = 0;
    uroomTrade->playerLevel = 0;
    uroomTrade->species = 0;
    uroomTrade->level = 0;
    uroomTrade->personality = 0;
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

static void HandleCancelTrade(bool32 unlockObjs)
{
    UR_ClearBg0();
    ScriptContext2_Disable();
    UnionRoom_UnlockPlayerAndChatPartner();
    gPlayerCurrActivity = 0;
    if (unlockObjs)
    {
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        UpdateGameDataWithActivitySpriteGendersFlag(IN_UNION_ROOM, 0, 0);
    }
}

static void UR_EnableScriptContext2AndFreezeObjectEvents(void)
{
    ScriptContext2_Enable();
    ScriptFreezeObjectEvents();
}

static u8 GetActivePartnerSpriteGenderParam(struct WirelessLink_URoom *data)
{
    u8 retVal = 0x80;
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (data->field_C->arr[i].active)
        {
            retVal |= data->field_C->arr[i].gname_uname.gname.playerGender << 3;
            retVal |= data->field_C->arr[i].gname_uname.gname.unk_00.playerTrainerId[0] & 7;
            break;
        }
    }

    return retVal;
}

static void ViewURoomPartnerTrainerCard(u8 *unused, struct WirelessLink_URoom *data, bool8 isParent)
{
    struct TrainerCard *trainerCard = &gTrainerCards[GetMultiplayerId() ^ 1];
    s32 i;
    s32 n;

    DynamicPlaceholderTextUtil_Reset();

    StringCopy(data->field_C0[0], gTrainerClassNames[GetUnionRoomTrainerClass()]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, data->field_C0[0]);

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, trainerCard->playerName);

    StringCopy(data->field_174, sCardColorTexts[trainerCard->stars]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, data->field_174);

    ConvertIntToDecimalStringN(data->field_C0[2], trainerCard->caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, data->field_C0[2]);

    ConvertIntToDecimalStringN(data->field_C0[3], trainerCard->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(data->field_C0[4], trainerCard->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, data->field_C0[3]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, data->field_C0[4]);

    DynamicPlaceholderTextUtil_ExpandPlaceholders(data->field_1A4, sText_TrainerCardInfoPage1);
    StringCopy(gStringVar4, data->field_1A4);

    n = trainerCard->linkBattleWins;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(data->field_C0[0], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, data->field_C0[0]);

    n = trainerCard->linkBattleLosses;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(data->field_C0[1], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, data->field_C0[1]);

    ConvertIntToDecimalStringN(data->field_C0[2], trainerCard->pokemonTrades, STR_CONV_MODE_LEFT_ALIGN, 5);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, data->field_C0[2]);

    for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
    {
        CopyEasyChatWord(data->field_C0[i + 3], trainerCard->easyChatProfile[i]);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(i + 4, data->field_C0[i + 3]);
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(data->field_1A4, sText_TrainerCardInfoPage2);
    StringAppend(gStringVar4, data->field_1A4);

    if (isParent == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(data->field_1A4, sText_FinishedCheckingPlayersTrainerCard);
        StringAppend(gStringVar4, data->field_1A4);
    }
    else if (isParent == FALSE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(data->field_1A4, sGladToMeetYouTexts[trainerCard->gender]);
        StringAppend(gStringVar4, data->field_1A4);
    }
}

static void IntlConvPartnerUname7(u8 *dest, struct UnkStruct_x20 *arg1)
{
    StringCopy7(dest, arg1->gname_uname.playerName);
    ConvertInternationalString(dest, arg1->gname_uname.gname.unk_00.language);
}
