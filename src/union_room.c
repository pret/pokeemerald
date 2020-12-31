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
#include "script_pokemon_util.h"
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

// States for Task_RunUnionRoom
enum {
    UR_STATE_INIT,
    UR_STATE_INIT_OBJECTS,
    UR_STATE_INIT_LINK,
    UR_STATE_CHECK_SELECTING_MON,
    UR_STATE_MAIN,
    UR_STATE_DO_SOMETHING_PROMPT,
    UR_STATE_HANDLE_DO_SOMETHING_PROMPT_INPUT,   
    UR_STATE_DO_SOMETHING_PROMPT_2,
    UR_STATE_PRINT_MSG,
    UR_STATE_HANDLE_ACTIVITY_REQUEST,
    UR_STATE_DECLINE_ACTIVITY_REQUEST,  
    UR_STATE_PLAYER_CONTACTED_YOU,
    UR_STATE_RECV_CONTACT_DATA,    
    UR_STATE_PRINT_START_ACTIVITY_MSG,
    UR_STATE_START_ACTIVITY_LINK,
    UR_STATE_START_ACTIVITY_WAIT_FOR_LINK,
    UR_STATE_START_ACTIVITY_FREE_UROOM,
    UR_STATE_START_ACTIVITY_FADE,
    UR_STATE_START_ACTIVITY,
    UR_STATE_RECV_JOIN_CHAT_REQUEST,
    UR_STATE_TRY_ACCEPT_CHAT_REQUEST_DELAY,
    UR_STATE_TRY_ACCEPT_CHAT_REQUEST,
    UR_STATE_ACCEPT_CHAT_REQUEST,
    UR_STATE_WAIT_FOR_START_MENU,
    UR_STATE_INTERACT_WITH_PLAYER,
    UR_STATE_TRY_COMMUNICATING,        
    UR_STATE_PRINT_AND_EXIT,
    UR_STATE_SEND_ACTIVITY_REQUEST,
    UR_STATE_TRAINER_APPEARS_BUSY,
    UR_STATE_WAIT_FOR_RESPONSE_TO_REQUEST,
    UR_STATE_CANCEL_ACTIVITY_LINK_ERROR,
    UR_STATE_SEND_TRADE_REQUST,
    UR_STATE_REQUEST_DECLINED,
    UR_STATE_PRINT_CONTACT_MSG,
    UR_STATE_HANDLE_CONTACT_DATA,
    UR_STATE_RECV_ACTIVITY_REQUEST,
    UR_STATE_CANCEL_REQUEST_PRINT_MSG,
    UR_STATE_CANCEL_REQUEST_RESTART_LINK,
    UR_STATE_COMMUNICATING_WAIT_FOR_DATA,
    UR_STATE_WAIT_FOR_CONTACT_DATA,    
    UR_STATE_PRINT_CARD_INFO,
    UR_STATE_WAIT_FINISH_READING_CARD,
    UR_STATE_INTERACT_WITH_ATTENDANT,
    UR_STATE_REGISTER_PROMPT,    
    UR_STATE_CANCEL_REGISTRATION_PROMPT,
    UR_STATE_CHECK_TRADING_BOARD,
    UR_STATE_TRADING_BOARD_LOAD,
    UR_STATE_REGISTER_PROMPT_HANDLE_INPUT,    
    UR_STATE_TRADING_BOARD_HANDLE_INPUT,
    UR_STATE_TRADE_PROMPT,
    UR_STATE_TRADE_SELECT_MON,
    UR_STATE_TRADE_OFFER_MON,
    UR_STATE_REGISTER_REQUEST_TYPE,
    UR_STATE_REGISTER_SELECT_MON_FADE,
    UR_STATE_REGISTER_SELECT_MON,
    UR_STATE_REGISTER_COMPLETE,        
    UR_STATE_CANCEL_REGISTRATION,
};

// States for sUnionRoomTrade.state
enum {
    URTRADE_STATE_NONE,
    URTRADE_STATE_REGISTERING,
    URTRADE_STATE_OFFERING,
};

// States for Task_TryBecomeLinkLeader
enum {
    LL_STATE_INIT,
    LL_STATE_INIT2 = 3,
    LL_STATE_GET_AWAITING_PLAYERS_TEXT,
    LL_STATE_PRINT_AWAITING_PLAYERS,
    LL_STATE_AWAIT_PLAYERS,
    LL_STATE_ACCEPT_NEW_MEMBER_PROMPT,
    LL_STATE_9 = 9,
    LL_STATE_MEMBER_LEFT,
    LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT,
    LL_STATE_UPDATE_AFTER_JOIN_REQUEST,
    LL_STATE_ACCEPTED_FINAL_MEMBER,
    LL_STATE_WAIT_AND_CONFIRM_MEMBERS,
    LL_STATE_MEMBERS_OK_PROMPT,
    LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT,
    LL_STATE_CONFIRMED_MEMBERS,
    LL_STATE_FINAL_MEMBER_CHECK,
    LL_STATE_CANCEL_PROMPT,
    LL_STATE_CANCEL_PROMPT_HANDLE_INPUT,
    LL_STATE_SHUTDOWN_AND_RETRY,
    LL_STATE_RETRY,
    LL_STATE_SHUTDOWN_AND_FAIL,
    LL_STATE_FAILED,
    LL_STATE_TRY_START_ACTIVITY = 26,
    LL_STATE_MEMBER_DISCONNECTED = 29,
    LL_STATE_CANCEL_WITH_MSG
};

// States for Task_TryJoinLinkGroup
enum {
    LG_STATE_INIT,
    LG_STATE_CHOOSE_LEADER_MSG,
    LG_STATE_INIT_WINDOWS,
    LG_STATE_CHOOSE_LEADER_HANDLE_INPUT,
    LG_STATE_ASK_JOIN_GROUP = 5,
    LG_STATE_MAIN,
    LG_STATE_ASK_LEAVE_GROUP,
    LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT,
    LG_STATE_WAIT_LEAVE_GROUP,
    LG_STATE_CANCEL_CHOOSE_LEADER,
    LG_STATE_CANCELED,
    LG_STATE_RFU_ERROR,
    LG_STATE_RFU_ERROR_SHUTDOWN,
    LG_STATE_DISCONNECTED,
    LG_STATE_RETRY_CONNECTION,
    LG_STATE_TRADE_NOT_READY = 18,
    LG_STATE_TRADE_NOT_READY_RETRY,
    LG_STATE_READY_START_ACTIVITY,
    LG_STATE_START_ACTIVITY,
    LG_STATE_SHUTDOWN = 23,
};

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
static void UR_AddTextPrinterParameterized(u8, u8, const u8 *, u8, u8, u8);
static u16 ReadAsU16(const u8 *);
static void Task_TryBecomeLinkLeader(u8);
static void Task_TryJoinLinkGroup(u8);
static void Task_ListenToWireless(u8);
static void Task_MEvent_Leader(u8);
static void Task_CardOrNewsWithFriend(u8);
static void Task_CardOrNewsOverWireless(u8);
static void Task_RunUnionRoom(u8);
static void ClearUnkStruct_x1CArray(struct UnkStruct_Main4 *, u8);
static void ClearUnkStruct_x20Array(struct UnkStruct_x20 *, u8);
static u8 CreateTask_ListenForPartnersWithCompatibleSerialNos(struct UnkStruct_Main4 *, u32);
static u8 CreateTask_ListenForPartnersWithSerial7F7D(struct UnkStruct_Main4 *, u32 );
static bool8 PrintOnTextbox(u8 *, const u8 *);
static bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *, u32, u32);
static u8 sub_8013398(struct UnkStruct_Main0 *);
static s8 UnionRoomHandleYesNo(u8 *, bool32);
static void IntlConvPartnerUname7(u8 *, struct UnkStruct_x20 *);
static void Leader_DestroyResources(struct WirelessLink_Leader *);
static void CreateTask_RunScriptAndFadeToActivity(void);
static u8 LeaderUpdateGroupMembership(struct UnkStruct_Main0 *);
static void PrintGroupMemberCandidateOnWindowWithColor(u8, u8, u8, struct UnkStruct_x20 *, u8, u8 );
static u32 Findx20Inx1CArray(struct UnkStruct_x20 *, struct UnkStruct_x1C *);
static u8 Appendx1Ctox20(struct UnkStruct_x20 *, struct UnkStruct_x1C *, u8);
static u8 GetNewLeaderCandidate(void);
static u32 IsTryingToTradeAcrossVersionTooSoon(struct WirelessLink_Group *, s32);
static void AskToJoinRfuGroup(struct WirelessLink_Group *, s32);
static void JoinGroup_EnableScriptContexts(void);
static void PrintUnionRoomGroupOnWindow(u8, u8, u8, struct UnkStruct_x20 *, u8, u8);
static bool32 AreUnionRoomPlayerGnamesDifferent(struct WirelessGnameUnamePair *, struct WirelessGnameUnamePair *);
static u32 GetPartyPositionOfRegisteredMon(struct UnionRoomTrade *, u8);
static void ResetUnionRoomTrade(struct UnionRoomTrade *);
static void CreateTask_StartActivity(void);
static bool32 HasWonderCardOrNewsByLinkGroup(struct GFtgtGname *, s16);
static u8 CreateTask_SearchForChildOrParent(struct UnkStruct_Main4 *, struct UnkStruct_Main4 *, u32);
static bool32 RegisterTradeMonAndGetIsEgg(u32, struct UnionRoomTrade *);
static void RegisterTradeMon(u32, struct UnionRoomTrade *);
static void UR_EnableScriptContext2AndFreezeObjectEvents(void);
static bool32 IsPlayerFacingTradingBoard(void);
static u8 HandlePlayerListUpdate(void);
static bool32 PollPartnerYesNoResponse(struct WirelessLink_URoom *);
static void ReceiveUnionRoomActivityPacket(struct WirelessLink_URoom *);
static u8 GetActivePartnerSpriteGenderParam(struct WirelessLink_URoom *);
static bool32 UnionRoom_HandleContactFromOtherPlayer(struct WirelessLink_URoom *);
static bool32 UR_RunTextPrinters_CheckPrinter0Active(void);
static s32 GetUnionRoomPlayerGender(s32, struct UnkStruct_Main0 *);
static s32 UnionRoomGetPlayerInteractionResponse(struct UnkStruct_Main0 *, u8, u8, u32);
static void HandleCancelActivity(bool32);
static s32 ListMenuHandler_AllItemsAvailable(u8 *, u8 *, u8 *, const struct WindowTemplate *, const struct ListMenuTemplate *);
static s32 TradeBoardMenuHandler(u8 *, u8 *, u8 *, u8 *, const struct WindowTemplate *, const struct ListMenuTemplate *, struct UnkStruct_Main0 *);
static s32 GetIndexOfNthTradeBoardOffer(struct UnkStruct_x20 *, s32);
static bool32 HasAtLeastTwoMonsOfLevel30OrLower(void);
static u32 GetResponseIdx_InviteToURoomActivity(s32);
static void ViewURoomPartnerTrainerCard(u8 *, struct WirelessLink_URoom *, bool8);
static void GetURoomActivityRejectMsg(u8 *, s32, u32);
static u32 ConvPartnerUnameAndGetWhetherMetAlready(struct UnkStruct_x20 *);
static void GetURoomActivityStartMsg(u8 *, u8);
static void UR_ClearBg0(void);
static s32 IsRequestedTypeOrEggInPlayerParty(u32, u32);
static bool32 UR_PrintFieldMessage(const u8 *);
static s32 GetChatLeaderActionRequestMessage(u8 *, u32, u16 *, struct WirelessLink_URoom *);
static void Task_InitUnionRoom(u8 taskId);
static bool8 AreGnameUnameDifferent(struct WirelessGnameUnamePair*, const struct WirelessGnameUnamePair*);
static void ItemPrintFunc_PossibleGroupMembers(u8, s32, u8);
static void ListMenuItemPrintFunc_UnionRoomGroups(u8, s32, u8);
static void TradeBoardListMenuItemPrintFunc(u8, s32, u8);
static void nullsub_14(u8, s32, u8);

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

    data->state = LL_STATE_INIT;
    data->textState = 0;
    gSpecialVar_Result = LINKUP_ONGOING;
}

static void Task_TryBecomeLinkLeader(u8 taskId)
{
    u32 id, val;
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;

    switch (data->state)
    {
    case LL_STATE_INIT:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004];
        sPlayerActivityGroupSize = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004] >> 8;
        SetHostRFUtgtGname(gPlayerCurrActivity, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_LinkLeader(GROUP_MAX(sPlayerActivityGroupSize));
        data->state = LL_STATE_INIT2;
        break;
    case LL_STATE_INIT2:
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        data->field_8 = AllocZeroed(5 * sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x1CArray(data->field_4, 4);
        ClearUnkStruct_x20Array(data->field_0->arr, 5);
        LinkRfu3_SetGnameUnameFromStaticBuffers(&data->field_0->arr[0].gname_uname.gname, data->field_0->arr[0].gname_uname.playerName);
        data->field_0->arr[0].timeoutCounter = 0;
        data->field_0->arr[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
        data->field_0->arr[0].useRedText = FALSE;
        data->field_0->arr[0].field_1B = 0;
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, 0xFF);
        data->bButtonCancelWindowId = AddWindow(&sWindowTemplate_BButtonCancel);
        switch (GROUP_MAX(sPlayerActivityGroupSize))
        {
        case 2:
        case 3:
        case 4:
            data->listWindowId = AddWindow(&sWindowTemplate_PlayerList);
            break;
        case 5:
            data->listWindowId = AddWindow(&sWindowTemplate_5PlayerList);
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
        data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        break;
    case LL_STATE_GET_AWAITING_PLAYERS_TEXT:
        StringCopy(gStringVar1, sLinkGroupActivityNameTexts[gPlayerCurrActivity]);
        if (GROUP_MIN(sPlayerActivityGroupSize) != 0)
        {
            if (data->playerCount > GROUP_MIN(sPlayerActivityGroupSize) - 1 && GROUP_MAX(sPlayerActivityGroupSize) != 0)
                StringExpandPlaceholders(gStringVar4, sText_AwaitingLinkPressStart);
            else
                StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
        }
        else
        {
            StringExpandPlaceholders_AwaitingCommFromAnother(gStringVar4, gPlayerCurrActivity);
        }

        PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
        data->state = LL_STATE_PRINT_AWAITING_PLAYERS;
        break;
    case LL_STATE_PRINT_AWAITING_PLAYERS:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = LL_STATE_AWAIT_PLAYERS;
        break;
    case LL_STATE_AWAIT_PLAYERS:
        Leader_SetStateIfMemberListChanged(data, LL_STATE_ACCEPT_NEW_MEMBER_PROMPT, LL_STATE_MEMBER_LEFT);
        if (JOY_NEW(B_BUTTON))
        {
            if (data->playerCount == 1)
                data->state = LL_STATE_SHUTDOWN_AND_FAIL;
            else if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_CANCEL_WITH_MSG;
            else
                data->state = LL_STATE_CANCEL_PROMPT;
        }
        if (GROUP_MIN(sPlayerActivityGroupSize) != 0
            && data->playerCount > GROUP_MIN(sPlayerActivityGroupSize) - 1
            && GROUP_MAX(sPlayerActivityGroupSize) != 0
            && sub_8012240()
            && JOY_NEW(START_BUTTON))
        {
            data->state = LL_STATE_MEMBERS_OK_PROMPT;
            LinkRfu_StopManagerAndFinalizeSlots();
        }
        if (data->state == LL_STATE_AWAIT_PLAYERS && sub_80105EC())
        {
            data->state = LL_STATE_9;
        }
        break;
    case LL_STATE_9:
        if (!sub_80105EC())
        {
            data->state = LL_STATE_AWAIT_PLAYERS;
            data->playerCount = sub_8013398(data->field_0);
        }
        break;
    case LL_STATE_MEMBER_LEFT:
        // BUG: sPlayerActivityGroupSize was meant below, not gPlayerCurrActivity
        //      This will be false for all but ACTIVITY_BATTLE_DOUBLE and ACTIVITY_DECLINE
        //      All this changes is which of two texts gets printed
        #ifdef BUGFIX
        id = (GROUP_MAX(sPlayerActivityGroupSize) == 2) ? 0 : 1;
        #else
        id = (GROUP_MAX(gPlayerCurrActivity) == 2) ? 1 : 0;
        #endif
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->playerCount = sub_8013398(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        }
        break;
    case LL_STATE_MEMBER_DISCONNECTED:
        id = (GROUP_MAX(sPlayerActivityGroupSize) == 2) ? 0 : 1;
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->state = LL_STATE_SHUTDOWN_AND_RETRY;
        }
        break;
    case LL_STATE_ACCEPT_NEW_MEMBER_PROMPT:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            data->state = LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT;
        }
        break;
    case LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, HasTrainerLeftPartnersList(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName)))
        {
        case 0: // YES
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_OK;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = LL_STATE_UPDATE_AFTER_JOIN_REQUEST;
            break;
        case 1: // NO
        case -1:
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_NO;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = LL_STATE_UPDATE_AFTER_JOIN_REQUEST;
            break;
        case -3:
            data->state = LL_STATE_9;
            break;
        }
        break;
    case LL_STATE_UPDATE_AFTER_JOIN_REQUEST:
        val = WaitSendRfuStatusToPartner(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
        if (val == 1) // Send complete
        {
            if (data->joinRequestAnswer == RFU_STATUS_JOIN_GROUP_OK)
            {
                data->field_0->arr[data->playerCount].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->playerCount++;
                if (data->playerCount == GROUP_MAX(sPlayerActivityGroupSize))
                {
                    if (GROUP_MIN2(sPlayerActivityGroupSize) != 0 || data->playerCount == 4)
                    {
                        data->state = LL_STATE_MEMBERS_OK_PROMPT;
                    }
                    else
                    {
                        IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->playerCount - 1]);
                        StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
                        data->state = LL_STATE_ACCEPTED_FINAL_MEMBER;
                    }

                    LinkRfu_StopManagerAndFinalizeSlots();
                    PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
                }
                else
                {
                    data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
                }
            }
            else // Member disconnected
            {
                RequestDisconnectSlotByTrainerNameAndId(data->field_0->arr[data->playerCount].gname_uname.playerName, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId));
                data->field_0->arr[data->playerCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
                sub_8013398(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
            }

            data->joinRequestAnswer = 0;
        }
        else if (val == 2)
        {
            RfuSetStatus(RFU_STATUS_OK, 0);
            data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        }
        break;
    case LL_STATE_ACCEPTED_FINAL_MEMBER:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = LL_STATE_WAIT_AND_CONFIRM_MEMBERS;
        break;
    case LL_STATE_WAIT_AND_CONFIRM_MEMBERS:
        if (++data->delayTimerAfterOk > 120)
            data->state = LL_STATE_CONFIRMED_MEMBERS;
        break;
    case LL_STATE_MEMBERS_OK_PROMPT:
        if (PrintOnTextbox(&data->textState, sText_AreTheseMembersOK))
            data->state = LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT;
        break;
    case LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0: // YES
            data->state = LL_STATE_CONFIRMED_MEMBERS;
            break;
        case 1: // NO
        case -1:
            if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_CANCEL_WITH_MSG;
            else
                data->state = LL_STATE_CANCEL_PROMPT;
            break;
        }
        break;
    case LL_STATE_CANCEL_PROMPT:
        if (PrintOnTextbox(&data->textState, sText_CancelModeWithTheseMembers))
            data->state = LL_STATE_CANCEL_PROMPT_HANDLE_INPUT;
        break;
    case LL_STATE_CANCEL_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0: // YES
            data->state = LL_STATE_SHUTDOWN_AND_FAIL;
            break;
        case 1: // NO
        case -1:
            if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_MEMBERS_OK_PROMPT;
            else if (data->playerCount == GROUP_MAX(sPlayerActivityGroupSize))
                data->state = LL_STATE_MEMBERS_OK_PROMPT;
            else
                data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
            break;
        }
        break;
    case LL_STATE_CONFIRMED_MEMBERS:
        if (!Leader_SetStateIfMemberListChanged(data, LL_STATE_ACCEPT_NEW_MEMBER_PROMPT, LL_STATE_MEMBER_DISCONNECTED))
            data->state = LL_STATE_FINAL_MEMBER_CHECK;
        break;
    case LL_STATE_FINAL_MEMBER_CHECK:
        if (LmanAcceptSlotFlagIsNotZero())
        {
            if (WaitRfuState(FALSE))
            {
                data->state = LL_STATE_TRY_START_ACTIVITY;
            }
            else
            {
                if (++data->memberConfirmTimeout > 300)
                {
                    data->state = LL_STATE_MEMBER_DISCONNECTED;
                    data->textState = 0;
                }
            }
        }
        else
        {
            data->state = LL_STATE_MEMBER_DISCONNECTED;
            data->textState = 0;
        }
        break;
    case LL_STATE_CANCEL_WITH_MSG:
        if (PrintOnTextbox(&data->textState, sText_ModeWithTheseMembersWillBeCanceled))
            data->state = LL_STATE_SHUTDOWN_AND_FAIL;
        break;
    case LL_STATE_SHUTDOWN_AND_RETRY:
    case LL_STATE_SHUTDOWN_AND_FAIL:
        DestroyWirelessStatusIndicatorSprite();
        LinkRfu_Shutdown();
        Leader_DestroyResources(data);
        data->state++; // LL_STATE_RETRY or LL_STATE_FAILED
        break;
    case LL_STATE_FAILED:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = LINKUP_FAILED;
        break;
    case LL_STATE_RETRY:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
        break;
    case LL_STATE_TRY_START_ACTIVITY:
        if (RfuHasErrored())
        {
            data->state = LL_STATE_MEMBER_DISCONNECTED;
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

static bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *data, u32 joinedState, u32 droppedState)
{
    switch (LeaderUpdateGroupMembership(data->field_0))
    {
    case UNION_ROOM_SPAWN_IN:
        PlaySE(SE_PC_LOGIN);
        RedrawListMenu(data->listTaskId);
        IntlConvPartnerUname7(gStringVar2, &data->field_0->arr[data->playerCount]);
        Leader_GetAcceptNewMemberPrompt(gStringVar4, gPlayerCurrActivity);
        data->state = joinedState;
        break;
    case UNION_ROOM_SPAWN_OUT:
        RfuSetStatus(RFU_STATUS_OK, 0);
        RedrawListMenu(data->listTaskId);
        data->state = droppedState;
        return TRUE;
    }

    return FALSE;
}

static void ItemPrintFunc_PossibleGroupMembers(u8 windowId, s32 id, u8 y)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 colorIdx = UR_COLOR_DKE_WHT_LTE;

    switch (data->field_0->arr[id].groupScheduledAnim)
    {
    case UNION_ROOM_SPAWN_IN:
        if (data->field_0->arr[id].field_1B != 0)
            colorIdx = UR_COLOR_GRN_WHT_LTG;
        break;
    case UNION_ROOM_SPAWN_OUT:
        colorIdx = UR_COLOR_RED_WHT_LTR;
        break;
    }

    PrintGroupMemberCandidateOnWindowWithColor(windowId, 0, y, &data->field_0->arr[id], colorIdx, id);
}

static u8 LeaderUpdateGroupMembership(struct UnkStruct_Main0 *arg0)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 ret = UNION_ROOM_SPAWN_NONE;
    u8 i;
    s32 id;

    for (i = 1; i < MAX_RFU_PLAYERS; i++)
    {
        u16 var = data->field_0->arr[i].groupScheduledAnim;
        if (var == UNION_ROOM_SPAWN_IN)
        {
            id = Findx20Inx1CArray(&data->field_0->arr[i], data->field_4->arr);
            if (id != 0xFF)
            {
                data->field_0->arr[i].gname_uname = data->field_4->arr[id].gname_uname;
                data->field_0->arr[i].timeoutCounter = 1;
            }
            else
            {
                data->field_0->arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                ret = UNION_ROOM_SPAWN_OUT;
            }
        }
    }

    for (id = 0; id < RFU_CHILD_MAX; id++)
        Appendx1Ctox20(data->field_0->arr, &data->field_4->arr[id], MAX_RFU_PLAYERS);

    if (ret != UNION_ROOM_SPAWN_OUT)
    {
        for (id = 0; id < MAX_RFU_PLAYERS; id++)
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
    u8 playerCount;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        data->field_8->arr[i] = data->field_0->arr[i];

    copiedCount = 0;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (data->field_8->arr[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
        {
            data->field_0->arr[copiedCount] = data->field_8->arr[i];
            copiedCount++;
        }
    }

    playerCount = copiedCount;
    for (; copiedCount < MAX_RFU_PLAYERS; copiedCount++)
    {
        data->field_0->arr[copiedCount].gname_uname = sWirelessGnameUnamePair_Dummy;
        data->field_0->arr[copiedCount].timeoutCounter = 0;
        data->field_0->arr[copiedCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
        data->field_0->arr[copiedCount].useRedText = FALSE;
        data->field_0->arr[copiedCount].field_1B = 0;
    }

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (data->field_0->arr[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
            continue;
        if (data->field_0->arr[i].field_1B != 64)
            continue;

        playerCount = i;
        break;
    }

    return playerCount;
}

void TryJoinLinkGroup(void)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_TryJoinLinkGroup, 0);
    sWirelessLinkMain.group = data = (void*)(gTasks[taskId].data);
    sGroup = data;

    data->state = LG_STATE_INIT;
    data->textState = 0;
    gSpecialVar_Result = LINKUP_ONGOING;
}

static void Task_TryJoinLinkGroup(u8 taskId)
{
    s32 id;
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case LG_STATE_INIT:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToURoomActivity[gSpecialVar_0x8004];
        SetHostRFUtgtGname(gPlayerCurrActivity, 0, 0);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        data->field_4 = AllocZeroed(4 * sizeof(struct UnkStruct_x1C));
        data->field_0 = AllocZeroed(16 * sizeof(struct UnkStruct_x20));
        data->state = LG_STATE_CHOOSE_LEADER_MSG;
        break;
    case LG_STATE_CHOOSE_LEADER_MSG:
        if (PrintOnTextbox(&data->textState, sChooseTrainerTexts[gSpecialVar_0x8004]))
            data->state = LG_STATE_INIT_WINDOWS;
        break;
    case LG_STATE_INIT_WINDOWS:
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
        data->state = LG_STATE_CHOOSE_LEADER_HANDLE_INPUT;
        break;
    case LG_STATE_CHOOSE_LEADER_HANDLE_INPUT:
        id = GetNewLeaderCandidate();
        switch (id)
        {
        case 1:
            PlaySE(SE_PC_LOGIN);
            RedrawListMenu(data->listTaskId);
            break;
        case 0:
            id = ListMenu_ProcessInput(data->listTaskId);
            if (JOY_NEW(A_BUTTON) && id != -1)
            {
                // this unused variable along with the assignment is needed to match
                u32 activity = data->field_0->arr[id].gname_uname.gname.activity;

                if (data->field_0->arr[id].groupScheduledAnim == UNION_ROOM_SPAWN_IN && !data->field_0->arr[id].gname_uname.gname.started)
                {
                    u32 readyStatus = IsTryingToTradeAcrossVersionTooSoon(data, id);
                    if (readyStatus == UR_TRADE_READY)
                    {
                        // Trading is allowed, or not trading at all
                        AskToJoinRfuGroup(data, id);
                        data->state = LG_STATE_ASK_JOIN_GROUP;
                        PlaySE(SE_POKENAV_ON);
                    }
                    else
                    {
                        StringCopy(gStringVar4, sCantTransmitToTrainerTexts[readyStatus - 1]);
                        data->state = LG_STATE_TRADE_NOT_READY;
                        PlaySE(SE_POKENAV_ON);
                    }
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                data->state = LG_STATE_CANCEL_CHOOSE_LEADER;
            }
            break;
        default:
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case LG_STATE_ASK_JOIN_GROUP:
        GetYouAskedToJoinGroupPleaseWaitMessage(gStringVar4, gPlayerCurrActivity);
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
            data->state = LG_STATE_MAIN;
        }
        break;
    case LG_STATE_MAIN:
        if (gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = data->field_0->arr[data->leaderId].gname_uname.gname.activity;
            RfuSetStatus(RFU_STATUS_OK, 0);
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
                data->state = LG_STATE_READY_START_ACTIVITY;
                return;
            }
        }

        switch (RfuGetStatus())
        {
        case RFU_STATUS_FATAL_ERROR:
            data->state = LG_STATE_RFU_ERROR;
            break;
        case RFU_STATUS_CONNECTION_ERROR:
        case RFU_STATUS_JOIN_GROUP_NO:
        case RFU_STATUS_LEAVE_GROUP:
            data->state = LG_STATE_DISCONNECTED;
            break;
        case RFU_STATUS_JOIN_GROUP_OK:
            GetGroupLeaderSentAnOKMessage(gStringVar4, gPlayerCurrActivity);
            if (PrintOnTextbox(&data->textState, gStringVar4))
            {
                if (gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER || gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER_OPEN)
                {
                    RfuSetStatus(RFU_STATUS_ACK_JOIN_GROUP, 0);
                }
                else
                {
                    RfuSetStatus(RFU_STATUS_WAIT_ACK_JOIN_GROUP, 0);
                    StringCopy(gStringVar1, sLinkGroupActivityNameTexts[gPlayerCurrActivity]);
                    StringExpandPlaceholders(gStringVar4, sText_AwaitingOtherMembers);
                }
            }
            break;
        case RFU_STATUS_WAIT_ACK_JOIN_GROUP:
            if (data->delayBeforePrint > 240)
            {
                if (PrintOnTextbox(&data->textState, gStringVar4))
                {
                    RfuSetStatus(RFU_STATUS_ACK_JOIN_GROUP, 0);
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

        if (RfuGetStatus() == RFU_STATUS_OK && JOY_NEW(B_BUTTON))
            data->state = LG_STATE_ASK_LEAVE_GROUP;
        break;
    case LG_STATE_ASK_LEAVE_GROUP:
        if (PrintOnTextbox(&data->textState, sText_QuitBeingMember))
            data->state = LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT;
        break;
    case LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, RfuGetStatus()))
        {
        case 0: // YES
            SendLeaveGroupNotice();
            data->state = LG_STATE_WAIT_LEAVE_GROUP;
            RedrawListMenu(data->listTaskId);
            break;
        case 1: // NO
        case -1:
            data->state = LG_STATE_ASK_JOIN_GROUP;
            RedrawListMenu(data->listTaskId);
            break;
        case -3:
            data->state = LG_STATE_MAIN;
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case LG_STATE_WAIT_LEAVE_GROUP:
        if (RfuGetStatus())
            data->state = LG_STATE_MAIN;
        break;
    case LG_STATE_CANCEL_CHOOSE_LEADER: // next: LG_STATE_CANCELED
    case LG_STATE_RFU_ERROR:            // next: LG_STATE_RFU_ERROR_SHUTDOWN
    case LG_STATE_DISCONNECTED:         // next: LG_STATE_RETRY_CONNECTION
    case LG_STATE_TRADE_NOT_READY:      // next: LG_STATE_TRADE_NOT_READY_RETRY
    case LG_STATE_READY_START_ACTIVITY: // next: LG_STATE_START_ACTIVITY
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
    case LG_STATE_RFU_ERROR_SHUTDOWN:
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetStatus()]))
        {
            gSpecialVar_Result = LINKUP_CONNECTION_ERROR;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_CANCELED:
        DestroyWirelessStatusIndicatorSprite();
        gSpecialVar_Result = LINKUP_FAILED;
        data->state = LG_STATE_SHUTDOWN;
        break;
    case LG_STATE_RETRY_CONNECTION:
        // Failure from disconnection
        // Happens if player or required member(s) leave group
        // or if player is rejected from joining group
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetStatus()]))
        {
            gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_TRADE_NOT_READY_RETRY:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_SHUTDOWN:
        DestroyTask(taskId);
        JoinGroup_EnableScriptContexts();
        LinkRfu_Shutdown();
        break;
    case LG_STATE_START_ACTIVITY:
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
            return UR_TRADE_PLAYER_NOT_READY;
        else if (structPtr->gname_uname.gname.unk_00.isChampion)
            return UR_TRADE_READY;
    }
    else
    {
        return UR_TRADE_READY;
    }

    return UR_TRADE_PARTNER_NOT_READY;
}

static void AskToJoinRfuGroup(struct WirelessLink_Group *data, s32 id)
{
    data->leaderId = id;
    LoadWirelessStatusIndicatorSpriteGfx();
    CreateWirelessStatusIndicatorSprite(0, 0);
    RedrawListMenu(data->listTaskId);
    IntlConvPartnerUname7(gStringVar1, &data->field_0->arr[data->leaderId]);
    UpdateGameData_SetActivity(sLinkGroupToURoomActivity[gSpecialVar_0x8004], 0, TRUE);
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

    #ifdef UBFIX
    if (linkGroup < ARRAY_COUNT(sAcceptedActivityIds))
    #else
    if (linkGroup <= ARRAY_COUNT(sAcceptedActivityIds))
    #endif
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
        else if (data->field_0->arr[id].useRedText)
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

                data->field_0->arr[i].timeoutCounter = 0;
            }
            else
            {
                if (data->field_0->arr[i].groupScheduledAnim != UNION_ROOM_SPAWN_OUT)
                {
                    data->field_0->arr[i].timeoutCounter++;
                    if (data->field_0->arr[i].timeoutCounter >= 300)
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
            SendBlockRequest(2);
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

static void WarpForWirelessMinigame(u16 linkService, u16 x, u16 y)
{
    VarSet(VAR_CABLE_CLUB_STATE, linkService);
    SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    SetDynamicWarpWithCoords(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, x, y);
    WarpIntoMap();
}

static void WarpForCableClubActivity(s8 mapGroup, s8 mapNum, s32 x, s32 y, u16 linkService)
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
        WarpForCableClubActivity(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_SINGLE_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_BATTLE_DOUBLE:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        WarpForCableClubActivity(MAP_GROUP(BATTLE_COLOSSEUM_2P), MAP_NUM(BATTLE_COLOSSEUM_2P), 6, 8, USING_DOUBLE_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_BATTLE_MULTI:
        CleanupOverworldWindowsAndTilemaps();
        HealPlayerParty();
        SavePlayerParty();
        LoadPlayerBag();
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        WarpForCableClubActivity(MAP_GROUP(BATTLE_COLOSSEUM_4P), MAP_NUM(BATTLE_COLOSSEUM_4P), 5, 8, USING_MULTI_BATTLE);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_TRADE:
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        WarpForCableClubActivity(MAP_GROUP(TRADE_CENTER), MAP_NUM(TRADE_CENTER), 5, 8, USING_TRADE_CENTER);
        SetMainCallback2(CB2_TransitionToCableClub);
        break;
    case ACTIVITY_RECORD_CORNER:
        CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
        CleanupOverworldWindowsAndTilemaps();
        WarpForCableClubActivity(MAP_GROUP(RECORD_CORNER), MAP_NUM(RECORD_CORNER), 8, 9, USING_RECORD_CORNER);
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
        WarpForWirelessMinigame(USING_MINIGAME, 5, 1);
        StartPokemonJump(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    case ACTIVITY_BERRY_CRUSH:
        WarpForWirelessMinigame(USING_BERRY_CRUSH, 9, 1);
        StartBerryCrush(CB2_LoadMap);
        break;
    case ACTIVITY_BERRY_PICK:
        WarpForWirelessMinigame(USING_MINIGAME, 5, 1);
        StartDodrioBerryPicking(GetCursorSelectionMonId(), CB2_LoadMap);
        break;
    }

    DestroyTask(taskId);
    gSpecialVar_Result = LINKUP_SUCCESS;
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
            if (gPlayerCurrActivity == ACTIVITY_29)
            {
                DestroyTask(taskId);
                SetMainCallback2(CB2_StartCreateTradeMenu);
            }
            else
            {
                SetLinkStandbyCallback();
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
        SetCloseLinkCallback();
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
    gSpecialVar_Result = LINKUP_ONGOING;
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
        data->field_0->arr[0].timeoutCounter = 0;
        data->field_0->arr[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
        data->field_0->arr[0].useRedText = FALSE;
        data->field_0->arr[0].field_1B = 0;
        data->listenTaskId = CreateTask_ListenForPartnersWithCompatibleSerialNos(data->field_4, 0xFF);

        winTemplate = sWindowTemplate_PlayerList;
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
        StringCopy(gStringVar1, sLinkGroupActivityNameTexts[gPlayerCurrActivity]);
        StringExpandPlaceholders_AwaitingCommFromAnother(gStringVar4, gPlayerCurrActivity);
        data->state = 3;
        break;
    case 3:
        AddTextPrinterToWindow1(gStringVar4);
        data->state = 4;
        break;
    case 4:
        Leader_SetStateIfMemberListChanged(data, 5, 6);
        if (JOY_NEW(B_BUTTON))
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
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_OK;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 8;
            break;
        case 1:
        case -1:
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_NO;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
            data->state = 8;
            break;
        }
        break;
    case 8:
        val = WaitSendRfuStatusToPartner(ReadAsU16(data->field_0->arr[data->playerCount].gname_uname.gname.unk_00.playerTrainerId), data->field_0->arr[data->playerCount].gname_uname.playerName);
        if (val == 1) // Send complete
        {
            if (data->joinRequestAnswer == RFU_STATUS_JOIN_GROUP_OK)
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

            data->joinRequestAnswer = 0;
        }
        else if (val == 2) // Member disconnected
        {
            RfuSetStatus(RFU_STATUS_OK, 0);
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
            gSpecialVar_Result = LINKUP_FAILED;
        }
        break;
    case 15:
        if (RfuGetStatus() == RFU_STATUS_FATAL_ERROR || RfuGetStatus() == RFU_STATUS_CONNECTION_ERROR)
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
        SetLinkStandbyCallback();
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
    gSpecialVar_Result = LINKUP_ONGOING;
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
            if (JOY_NEW(A_BUTTON) && id != -1)
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
                    PlaySE(SE_POKENAV_ON);
                    data->state = 4;
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
            else if (JOY_NEW(B_BUTTON))
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

        switch (RfuGetStatus())
        {
        case RFU_STATUS_FATAL_ERROR:
        case RFU_STATUS_CONNECTION_ERROR:
        case RFU_STATUS_JOIN_GROUP_NO:
            data->state = 8;
            break;
        case RFU_STATUS_JOIN_GROUP_OK:
            AddTextPrinterToWindow1(sText_PlayerSentBackOK);
            RfuSetStatus(RFU_STATUS_OK, 0);
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
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sLinkDroppedTexts[RfuGetStatus()]))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = LINKUP_FAILED;
        }
        break;
    case 7:
        DestroyWirelessStatusIndicatorSprite();
        AddTextPrinterToWindow1(sText_PleaseStartOver);
        DestroyTask(taskId);
        LinkRfu_Shutdown();
        gSpecialVar_Result = LINKUP_FAILED;
        break;
    case 11:
        data->state++;
        SetLinkStandbyCallback();
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
    gSpecialVar_Result = LINKUP_ONGOING;
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
                        PlaySE(SE_POKENAV_ON);
                        data->state = 4;
                    }
                    else
                    {
                        PlaySE(SE_BOO);
                        data->state = 10;
                    }
                }
            }
            else if (JOY_NEW(B_BUTTON))
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

        switch (RfuGetStatus())
        {
        case RFU_STATUS_FATAL_ERROR:
        case RFU_STATUS_CONNECTION_ERROR:
        case RFU_STATUS_JOIN_GROUP_NO:
            data->state = 8;
            break;
        case RFU_STATUS_JOIN_GROUP_OK:
            AddTextPrinterToWindow1(sText_WirelessLinkEstablished);
            RfuSetStatus(RFU_STATUS_OK, 0);
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
            gSpecialVar_Result = LINKUP_FAILED;
        }
        break;
    case 7:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sText_WirelessSearchCanceled))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = LINKUP_FAILED;
        }
        break;
    case 11:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, sNoWonderSharedTexts[data->isWonderNews]))
        {
            DestroyWirelessStatusIndicatorSprite();
            DestroyTask(taskId);
            LinkRfu_Shutdown();
            gSpecialVar_Result = LINKUP_FAILED;
        }
        break;
    case 13:
        data->state++;
        SetLinkStandbyCallback();
        break;
    case 14:
        if (IsLinkTaskFinished())
            DestroyTask(taskId);
        break;
    }
}

void RunUnionRoom(void)
{
    struct WirelessLink_URoom *uroom;

    ClearAndInitHostRFUtgtGname();
    CreateTask(Task_RunUnionRoom, 10);

    // dumb line needed to match
    sWirelessLinkMain.uRoom = sWirelessLinkMain.uRoom;

    uroom = AllocZeroed(sizeof(*sWirelessLinkMain.uRoom));
    sWirelessLinkMain.uRoom = uroom;
    sURoom = uroom;

    uroom->state = UR_STATE_INIT;
    uroom->textState = 0;
    uroom->unknown = 0;
    uroom->field_12 = 0;

    gSpecialVar_Result = 0;
    ListMenuLoadStdPalAt(0xD0, 1);
}

static u16 ReadAsU16(const u8 *ptr)
{
    return (ptr[1] << 8) | (ptr[0]);
}

static void ScheduleFieldMessageWithFollowupState(u32 nextState, const u8 *src)
{
    struct WirelessLink_URoom *uroom = sWirelessLinkMain.uRoom;

    uroom->state = UR_STATE_PRINT_MSG;
    uroom->stateAfterPrint = nextState;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

static void ScheduleFieldMessageAndExit(const u8 *src)
{
    struct WirelessLink_URoom *uroom = sWirelessLinkMain.uRoom;

    uroom->state = UR_STATE_PRINT_AND_EXIT;
    if (src != gStringVar4)
        StringExpandPlaceholders(gStringVar4, src);
}

static void sub_80156B0(struct WirelessLink_URoom *uroom)
{
    memcpy(&gDecompressionBuffer[0x3F00], uroom->field_0, 0x100);
}

static void sub_80156C8(struct WirelessLink_URoom *uroom)
{
    memcpy(uroom->field_0, &gDecompressionBuffer[0x3F00], 0x100);
}

static void Task_RunUnionRoom(u8 taskId)
{
    u32 id = 0;
    s32 input = 0;
    s32 playerGender = MALE;
    struct WirelessLink_URoom *uroom = sWirelessLinkMain.uRoom;
    s16 *taskData = gTasks[taskId].data;

    switch (uroom->state)
    {
    case UR_STATE_INIT:
        uroom->field_4 = AllocZeroed(RFU_CHILD_MAX * sizeof(struct UnkStruct_x1C));
        uroom->field_C = AllocZeroed(RFU_CHILD_MAX * sizeof(struct UnkStruct_x1C));
        uroom->field_0 = AllocZeroed(8 * sizeof(struct UnkStruct_x20));
        uroom->field_8 = AllocZeroed(sizeof(struct UnkStruct_x20));
        ClearUnkStruct_x20Array(uroom->field_0->arr, ARRAY_COUNT(uroom->field_0->arr));
        gPlayerCurrActivity = IN_UNION_ROOM;
        uroom->searchTaskId = CreateTask_SearchForChildOrParent(uroom->field_C, uroom->field_4, LINK_GROUP_UNION_ROOM_RESUME);
        InitUnionRoomPlayerObjects(uroom->objects);
        SetTilesAroundUnionRoomPlayersPassable();
        uroom->state = UR_STATE_INIT_OBJECTS;
        break;
    case UR_STATE_INIT_OBJECTS:
        CreateGroupMemberSpritesInvisible(uroom->spriteIds, taskData[0]);
        if (++taskData[0] == 8)
            uroom->state = UR_STATE_INIT_LINK;
        break;
    case UR_STATE_INIT_LINK:
        SetHostRFUtgtGname(IN_UNION_ROOM, 0, 0);
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_EnterUnionRoom();
        ClearUnkStruct_x20Array(&uroom->field_8->arr[0], 1);
        ClearUnkStruct_x1CArray(uroom->field_4, 4);
        ClearUnkStruct_x1CArray(uroom->field_C, 4);
        gSpecialVar_Result = 0;
        uroom->state = UR_STATE_CHECK_SELECTING_MON;
        break;
    case UR_STATE_CHECK_SELECTING_MON:
        if ((GetPartyMenuType() == PARTY_MENU_TYPE_UNION_ROOM_REGISTER 
          || GetPartyMenuType() == PARTY_MENU_TYPE_UNION_ROOM_TRADE) 
           && sUnionRoomTrade.state != URTRADE_STATE_NONE)
        {
            id = GetCursorSelectionMonId();
            switch (sUnionRoomTrade.state)
            {
            case URTRADE_STATE_REGISTERING:
                UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                if (id >= PARTY_SIZE)
                {
                    ResetUnionRoomTrade(&sUnionRoomTrade);
                    SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                    ScheduleFieldMessageAndExit(sText_RegistrationCanceled);
                }
                else if (!RegisterTradeMonAndGetIsEgg(GetCursorSelectionMonId(), &sUnionRoomTrade))
                {
                    ScheduleFieldMessageWithFollowupState(UR_STATE_REGISTER_REQUEST_TYPE, sText_ChooseRequestedMonType);
                }
                else
                {
                    uroom->state = UR_STATE_REGISTER_COMPLETE;
                }
                break;
            case URTRADE_STATE_OFFERING:
                sub_80156C8(uroom);
                taskData[1] = sUnionRoomTrade.offerPlayerId;
                if (id >= PARTY_SIZE)
                {
                    ScheduleFieldMessageAndExit(sText_TradeCanceled);
                }
                else
                {
                    UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                    gPlayerCurrActivity = ACTIVITY_TRADE | IN_UNION_ROOM;
                    RegisterTradeMon(GetCursorSelectionMonId(), &sUnionRoomTrade);
                    uroom->state = UR_STATE_TRADE_OFFER_MON;
                }
                break;
            }
            sUnionRoomTrade.state = URTRADE_STATE_NONE;
        }
        else
        {
            uroom->state = UR_STATE_MAIN;
        }
        break;
    case UR_STATE_MAIN:
        if (gSpecialVar_Result != 0)
        {
            if (gSpecialVar_Result == UR_INTERACT_ATTENDANT)
            {
                UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                PlaySE(SE_PC_LOGIN);
                StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                uroom->state = UR_STATE_INTERACT_WITH_ATTENDANT;
                gSpecialVar_Result = 0;
            }
            else if (gSpecialVar_Result == UR_INTERACT_START_MENU)
            {
                UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                uroom->state = UR_STATE_WAIT_FOR_START_MENU;
                gSpecialVar_Result = 0;
            }
            else // UR_INTERACT_PLAYER_# (1-8)
            {
                taskData[0] = 0;
                taskData[1] = gSpecialVar_Result - 1;
                uroom->state = UR_STATE_INTERACT_WITH_PLAYER;
                gSpecialVar_Result = 0;
            }
        }
        else if (ScriptContext2_IsEnabled() != TRUE)
        {
            if (JOY_NEW(A_BUTTON))
            {
                if (TryInteractWithUnionRoomMember(uroom->field_0, &taskData[0], &taskData[1], uroom->spriteIds))
                {
                    PlaySE(SE_SELECT);
                    UR_EnableScriptContext2AndFreezeObjectEvents();
                    uroom->state = UR_STATE_INTERACT_WITH_PLAYER;
                    break;
                }
                else if (IsPlayerFacingTradingBoard())
                {
                    UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
                    PlaySE(SE_PC_LOGIN);
                    UR_EnableScriptContext2AndFreezeObjectEvents();
                    StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                    uroom->state = UR_STATE_CHECK_TRADING_BOARD;
                    break;
                }
            }

            switch (HandlePlayerListUpdate())
            {
            case 1:
                PlaySE(SE_PC_LOGIN);
            case 2:
                ScheduleUnionRoomPlayerRefresh(uroom);
                break;
            case 4:
                uroom->state = UR_STATE_PLAYER_CONTACTED_YOU;
                UR_EnableScriptContext2AndFreezeObjectEvents();
                SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                UpdateGameData_SetActivity(ACTIVITY_NPCTALK | IN_UNION_ROOM, GetActivePartnerSpriteGenderParam(uroom), FALSE);
                break;
            }
            HandleUnionRoomPlayerRefresh(uroom);
        }
        break;
    case UR_STATE_WAIT_FOR_START_MENU:
        if (!FuncIsActiveTask(Task_ShowStartMenu))
        {
            UpdateGameData_SetActivity(ACTIVITY_NONE | IN_UNION_ROOM, 0, FALSE);
            uroom->state = UR_STATE_MAIN;
        }
        break;
    case UR_STATE_INTERACT_WITH_PLAYER:
        UR_RunTextPrinters_CheckPrinter0Active();
        playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
        UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
        switch (UnionRoomGetPlayerInteractionResponse(uroom->field_0, taskData[0], taskData[1], playerGender))
        {
        case 0: // Player is or was just doing an activity
            uroom->state = UR_STATE_PRINT_AND_EXIT;
            break;
        case 1: // Link communicating
            sub_8012188(uroom->field_0->arr[taskData[1]].gname_uname.playerName, &uroom->field_0->arr[taskData[1]].gname_uname.gname, gPlayerCurrActivity);
            uroom->field_12 = id; // Should be just 0, but won't match any other way.
            uroom->state = UR_STATE_TRY_COMMUNICATING;
            break;
        case 2: // Ask to join chat
            ScheduleFieldMessageWithFollowupState(UR_STATE_RECV_JOIN_CHAT_REQUEST, gStringVar4);
            break;
        }
        break;
    case UR_STATE_TRY_COMMUNICATING:
        UR_RunTextPrinters_CheckPrinter0Active();
        switch (RfuGetStatus())
        {
        case RFU_STATUS_NEW_CHILD_DETECTED:
            HandleCancelActivity(TRUE);
            uroom->state = UR_STATE_MAIN;
            break;
        case RFU_STATUS_FATAL_ERROR:
        case RFU_STATUS_CONNECTION_ERROR:
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sText_TrainerAppearsBusy);
            else
                ScheduleFieldMessageWithFollowupState(UR_STATE_CANCEL_ACTIVITY_LINK_ERROR, sText_TrainerAppearsBusy);

            gPlayerCurrActivity = IN_UNION_ROOM;
            break;
        }

        if (gReceivedRemoteLinkPlayers)
        {
            CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
            CreateTask(Task_ExchangeCards, 5);
            uroom->state = UR_STATE_COMMUNICATING_WAIT_FOR_DATA;
        }
        break;
    case UR_STATE_COMMUNICATING_WAIT_FOR_DATA:
        if (!FuncIsActiveTask(Task_ExchangeCards))
        {
            if (gPlayerCurrActivity == (ACTIVITY_TRADE | IN_UNION_ROOM))
                ScheduleFieldMessageWithFollowupState(UR_STATE_SEND_TRADE_REQUST, sText_AwaitingPlayersResponseAboutTrade);
            else
                uroom->state = UR_STATE_DO_SOMETHING_PROMPT;
        }
        break;
    case UR_STATE_CANCEL_ACTIVITY_LINK_ERROR:
        if (!gReceivedRemoteLinkPlayers)
        {
            HandleCancelActivity(FALSE);
            UpdateUnionRoomMemberFacing(taskData[0], taskData[1], uroom->field_0);
            uroom->state = UR_STATE_INIT_LINK;
        }
        break;
    case UR_STATE_DO_SOMETHING_PROMPT:
        id = ConvPartnerUnameAndGetWhetherMetAlready(&uroom->field_0->arr[taskData[1]]);
        playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
        ScheduleFieldMessageWithFollowupState(UR_STATE_HANDLE_DO_SOMETHING_PROMPT_INPUT, sHiDoSomethingTexts[id][playerGender]);
        break;
    case UR_STATE_HANDLE_DO_SOMETHING_PROMPT_INPUT:
        input = ListMenuHandler_AllItemsAvailable(&uroom->textState, 
                                                  &uroom->topListMenuWindowId, 
                                                  &uroom->topListMenuId, 
                                                  &sWindowTemplate_InviteToActivity, 
                                                  &sListMenuTemplate_InviteToActivity);
        if (input != -1)
        {
            if (!gReceivedRemoteLinkPlayers)
            {
                uroom->state = UR_STATE_TRAINER_APPEARS_BUSY;
            }
            else
            {
                uroom->partnerYesNoResponse = 0;
                playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
                if (input == -2 || input == IN_UNION_ROOM)
                {
                    uroom->playerSendBuffer[0] = IN_UNION_ROOM;
                    Rfu_SendPacket(uroom->playerSendBuffer);
                    StringCopy(gStringVar4, sIfYouWantToDoSomethingTexts[gLinkPlayers[0].gender]);
                    uroom->state = UR_STATE_REQUEST_DECLINED;
                }
                else
                {
                    gPlayerCurrActivity = input;
                    sPlayerActivityGroupSize = (u32)(input) >> 8;
                    if (gPlayerCurrActivity == (ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM) && !HasAtLeastTwoMonsOfLevel30OrLower())
                    {
                        ScheduleFieldMessageWithFollowupState(UR_STATE_DO_SOMETHING_PROMPT, sText_NeedTwoMonsOfLevel30OrLower1);
                    }
                    else
                    {
                        uroom->playerSendBuffer[0] = gPlayerCurrActivity | IN_UNION_ROOM;
                        Rfu_SendPacket(uroom->playerSendBuffer);
                        uroom->state = UR_STATE_SEND_ACTIVITY_REQUEST;
                    }
                }
            }
        }
        break;
    case UR_STATE_TRAINER_APPEARS_BUSY:
        StringCopy(gStringVar4, sText_TrainerBattleBusy);
        uroom->state = UR_STATE_CANCEL_REQUEST_PRINT_MSG;
        break;
    case UR_STATE_SEND_ACTIVITY_REQUEST:
        PollPartnerYesNoResponse(uroom);
        playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
        id = GetResponseIdx_InviteToURoomActivity(uroom->playerSendBuffer[0] & 0x3F);
        if (PrintOnTextbox(&uroom->textState, sText_WaitOrShowCardTexts[playerGender][id]))
        {
            taskData[3] = 0;
            uroom->state = UR_STATE_WAIT_FOR_RESPONSE_TO_REQUEST;
        }
        break;
    case UR_STATE_REQUEST_DECLINED:
        SetCloseLinkCallback();
        uroom->state = UR_STATE_CANCEL_REQUEST_PRINT_MSG;
        break;
    case UR_STATE_SEND_TRADE_REQUST:
        uroom->playerSendBuffer[0] = ACTIVITY_TRADE | IN_UNION_ROOM;
        uroom->playerSendBuffer[1] = sUnionRoomTrade.species;
        uroom->playerSendBuffer[2] = sUnionRoomTrade.level;
        Rfu_SendPacket(uroom->playerSendBuffer);
        uroom->state = UR_STATE_WAIT_FOR_RESPONSE_TO_REQUEST;
        break;
    case UR_STATE_WAIT_FOR_RESPONSE_TO_REQUEST:
        if (!gReceivedRemoteLinkPlayers)
        {
            StringCopy(gStringVar4, sText_TrainerBattleBusy); // Redundant, will be copied again in next state
            uroom->state = UR_STATE_TRAINER_APPEARS_BUSY;
        }
        else
        {
            PollPartnerYesNoResponse(uroom);
            if (uroom->partnerYesNoResponse == (ACTIVITY_ACCEPT | IN_UNION_ROOM))
            {
                if (gPlayerCurrActivity == ACTIVITY_CARD)
                {
                    ViewURoomPartnerTrainerCard(gStringVar4, uroom, FALSE);
                    uroom->state = UR_STATE_PRINT_CARD_INFO;
                }
                else
                {
                    uroom->state = UR_STATE_PRINT_START_ACTIVITY_MSG;
                }
            }
            else if (uroom->partnerYesNoResponse == (ACTIVITY_DECLINE | IN_UNION_ROOM))
            {
                uroom->state = UR_STATE_REQUEST_DECLINED;
                GetURoomActivityRejectMsg(gStringVar4, gPlayerCurrActivity | IN_UNION_ROOM, gLinkPlayers[0].gender);
                gPlayerCurrActivity = ACTIVITY_NONE;
            }
        }
        break;

    case UR_STATE_DO_SOMETHING_PROMPT_2: // Identical to UR_STATE_DO_SOMETHING_PROMPT
        id = ConvPartnerUnameAndGetWhetherMetAlready(&uroom->field_0->arr[taskData[1]]);
        playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
        ScheduleFieldMessageWithFollowupState(UR_STATE_HANDLE_DO_SOMETHING_PROMPT_INPUT, sHiDoSomethingTexts[id][playerGender]);
        break;
    case UR_STATE_PRINT_CARD_INFO:
        if (PrintOnTextbox(&uroom->textState, gStringVar4))
        {
            uroom->state = UR_STATE_WAIT_FINISH_READING_CARD;
            SetLinkStandbyCallback();
            uroom->partnerYesNoResponse = 0;
            uroom->recvActivityRequest[0] = 0;
        }
        break;
    case UR_STATE_WAIT_FINISH_READING_CARD:
        if (IsLinkTaskFinished())
        {
            if (GetMultiplayerId() == 0)
            {
                StringCopy(gStringVar1, gLinkPlayers[GetMultiplayerId() ^ 1].name);
                id = PlayerHasMetTrainerBefore(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
                StringExpandPlaceholders(gStringVar4, sAwaitingResponseTexts[id]);
                uroom->state = UR_STATE_PRINT_CONTACT_MSG;
            }
            else
            {
                uroom->state = UR_STATE_DO_SOMETHING_PROMPT_2;
            }
        }
        break;
    case UR_STATE_RECV_JOIN_CHAT_REQUEST:
        switch (UnionRoomHandleYesNo(&uroom->textState, FALSE))
        {
        case 0: // YES
            CopyBgTilemapBufferToVram(0);
            gPlayerCurrActivity = ACTIVITY_CHAT | IN_UNION_ROOM;
            UpdateGameData_SetActivity(ACTIVITY_CHAT | IN_UNION_ROOM, 0, TRUE);
            sub_8012188(uroom->field_0->arr[taskData[1]].gname_uname.playerName, &uroom->field_0->arr[taskData[1]].gname_uname.gname, gPlayerCurrActivity);
            uroom->field_12 = taskData[1];
            uroom->state = UR_STATE_TRY_ACCEPT_CHAT_REQUEST_DELAY;
            taskData[3] = 0;
            break;
        case 1: // NO
        case -1:
            playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
            ScheduleFieldMessageAndExit(sDeclineChatTexts[playerGender]);
            break;
        }
        break;
    case UR_STATE_TRY_ACCEPT_CHAT_REQUEST_DELAY:
        if (++taskData[2] > 60)
        {
            uroom->state = UR_STATE_TRY_ACCEPT_CHAT_REQUEST;
            taskData[2] = 0;
        }
        break;
    case UR_STATE_TRY_ACCEPT_CHAT_REQUEST:
        switch (RfuGetStatus())
        {
        case RFU_STATUS_NEW_CHILD_DETECTED:
            HandleCancelActivity(TRUE);
            uroom->state = UR_STATE_MAIN;
            break;
        case RFU_STATUS_FATAL_ERROR:
        case RFU_STATUS_CONNECTION_ERROR:
            playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
            UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sChatDeclinedTexts[playerGender]);
            else
                ScheduleFieldMessageWithFollowupState(UR_STATE_CANCEL_ACTIVITY_LINK_ERROR, sChatDeclinedTexts[playerGender]);
            break;
        case RFU_STATUS_CHILD_SEND_COMPLETE:
            uroom->state = UR_STATE_ACCEPT_CHAT_REQUEST;
            break;
        }
        taskData[3]++;
        break;
    case UR_STATE_ACCEPT_CHAT_REQUEST:
        if (RfuHasErrored())
        {
            playerGender = GetUnionRoomPlayerGender(taskData[1], uroom->field_0);
            UpdateGameData_SetActivity(ACTIVITY_PLYRTALK | IN_UNION_ROOM, 0, TRUE);
            if (IsUnionRoomListenTaskActive() == TRUE)
                ScheduleFieldMessageAndExit(sChatDeclinedTexts[playerGender]);
            else
                ScheduleFieldMessageWithFollowupState(UR_STATE_CANCEL_ACTIVITY_LINK_ERROR, sChatDeclinedTexts[playerGender]);
        }
        if (gReceivedRemoteLinkPlayers)
            uroom->state = UR_STATE_START_ACTIVITY_FREE_UROOM;
        break;
    case UR_STATE_PLAYER_CONTACTED_YOU:
        PlaySE(SE_DING_DONG);
        sub_800EF7C();
        uroom->state = UR_STATE_RECV_CONTACT_DATA;
        uroom->recvActivityRequest[0] = 0;
        break;
    case UR_STATE_RECV_CONTACT_DATA:
        if (RfuHasErrored())
        {
            HandleCancelActivity(FALSE);
            uroom->state = UR_STATE_INIT_LINK;
        }
        else if (gReceivedRemoteLinkPlayers)
        {
            CreateTrainerCardInBuffer(gBlockSendBuffer, TRUE);
            CreateTask(Task_ExchangeCards, 5);
            uroom->state = UR_STATE_WAIT_FOR_CONTACT_DATA;
        }
        break;
    case UR_STATE_WAIT_FOR_CONTACT_DATA:
        ReceiveUnionRoomActivityPacket(uroom);
        if (!FuncIsActiveTask(Task_ExchangeCards))
        {
            uroom->state = UR_STATE_PRINT_CONTACT_MSG;
            StringCopy(gStringVar1, gLinkPlayers[1].name);
            id = PlayerHasMetTrainerBefore(gLinkPlayers[1].trainerId, gLinkPlayers[1].name);
            StringExpandPlaceholders(gStringVar4, sPlayerContactedYouTexts[id]);
        }
        break;
    case UR_STATE_PRINT_CONTACT_MSG:
        ReceiveUnionRoomActivityPacket(uroom);
        if (PrintOnTextbox(&uroom->textState, gStringVar4))
            uroom->state = UR_STATE_HANDLE_CONTACT_DATA;
        break;
    case UR_STATE_HANDLE_CONTACT_DATA:
        ReceiveUnionRoomActivityPacket(uroom);
        if (UnionRoom_HandleContactFromOtherPlayer(uroom) && JOY_NEW(B_BUTTON))
        {
            sub_8011DE0(1);
            StringCopy(gStringVar4, sText_ChatEnded);
            uroom->state = UR_STATE_CANCEL_REQUEST_PRINT_MSG;
        }
        break;
    case UR_STATE_RECV_ACTIVITY_REQUEST:
        ScheduleFieldMessageWithFollowupState(UR_STATE_HANDLE_ACTIVITY_REQUEST, gStringVar4);
        break;
    case UR_STATE_HANDLE_ACTIVITY_REQUEST:
        switch (UnionRoomHandleYesNo(&uroom->textState, FALSE))
        {
        case 0: // ACCEPT
            uroom->playerSendBuffer[0] = ACTIVITY_ACCEPT | IN_UNION_ROOM;
            if (gPlayerCurrActivity == (ACTIVITY_CHAT | IN_UNION_ROOM))
                UpdateGameData_SetActivity(gPlayerCurrActivity | IN_UNION_ROOM, sub_801100C(1), FALSE);
            else
                UpdateGameData_SetActivity(gPlayerCurrActivity | IN_UNION_ROOM, sub_801100C(1), TRUE);

            uroom->field_8->arr[0].field_1B = 0;
            taskData[3] = 0;
            if (gPlayerCurrActivity == (ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM))
            {
                if (!HasAtLeastTwoMonsOfLevel30OrLower())
                {
                    uroom->playerSendBuffer[0] = ACTIVITY_DECLINE | IN_UNION_ROOM;
                    Rfu_SendPacket(uroom->playerSendBuffer);
                    uroom->state = UR_STATE_DECLINE_ACTIVITY_REQUEST;
                    StringCopy(gStringVar4, sText_NeedTwoMonsOfLevel30OrLower2);
                }
                else
                {
                    Rfu_SendPacket(uroom->playerSendBuffer);
                    uroom->state = UR_STATE_PRINT_START_ACTIVITY_MSG;
                }
            }
            else if (gPlayerCurrActivity == (ACTIVITY_CARD | IN_UNION_ROOM))
            {
                Rfu_SendPacket(uroom->playerSendBuffer);
                ViewURoomPartnerTrainerCard(gStringVar4, uroom, TRUE);
                uroom->state = UR_STATE_PRINT_CARD_INFO;
            }
            else
            {
                Rfu_SendPacket(uroom->playerSendBuffer);
                uroom->state = UR_STATE_PRINT_START_ACTIVITY_MSG;
            }
            break;
        case 1: // DECLINE
        case -1:
            uroom->playerSendBuffer[0] = ACTIVITY_DECLINE | IN_UNION_ROOM;
            Rfu_SendPacket(uroom->playerSendBuffer);
            uroom->state = UR_STATE_DECLINE_ACTIVITY_REQUEST;
            GetYouDeclinedTheOfferMessage(gStringVar4, gPlayerCurrActivity);
            break;
        }
        break;
    case UR_STATE_DECLINE_ACTIVITY_REQUEST:
        SetCloseLinkCallback();
        uroom->state = UR_STATE_CANCEL_REQUEST_PRINT_MSG;
        break;
    case UR_STATE_CANCEL_REQUEST_PRINT_MSG:
        if (!gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = IN_UNION_ROOM;
            ScheduleFieldMessageWithFollowupState(UR_STATE_CANCEL_REQUEST_RESTART_LINK, gStringVar4);
            memset(uroom->playerSendBuffer, 0, sizeof(uroom->playerSendBuffer));
            uroom->recvActivityRequest[0] = 0;
            uroom->partnerYesNoResponse = 0;
        }
        break;
    case UR_STATE_CANCEL_REQUEST_RESTART_LINK:
        uroom->state = UR_STATE_INIT_LINK;
        HandleCancelActivity(FALSE);
        break;
    case UR_STATE_PRINT_START_ACTIVITY_MSG:
        GetURoomActivityStartMsg(gStringVar4, gPlayerCurrActivity | IN_UNION_ROOM);
        ScheduleFieldMessageWithFollowupState(UR_STATE_START_ACTIVITY_LINK, gStringVar4);
        break;
    case UR_STATE_START_ACTIVITY_LINK:
        SetLinkStandbyCallback();
        uroom->state = UR_STATE_START_ACTIVITY_WAIT_FOR_LINK;
        break;
    case UR_STATE_START_ACTIVITY_WAIT_FOR_LINK:
        if (IsLinkTaskFinished())
            uroom->state = UR_STATE_START_ACTIVITY_FREE_UROOM;
        break;
    case UR_STATE_START_ACTIVITY_FREE_UROOM:
        Free(uroom->field_8);
        Free(uroom->field_0);
        Free(uroom->field_C);
        Free(uroom->field_4);
        DestroyTask(uroom->searchTaskId);
        DestroyGroupMemberSprites(uroom->spriteIds);
        uroom->state = UR_STATE_START_ACTIVITY_FADE;
        break;
    case UR_STATE_START_ACTIVITY_FADE:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
        uroom->state = UR_STATE_START_ACTIVITY;
        break;
    case UR_STATE_START_ACTIVITY:
        if (!UpdatePaletteFade())
        {
            DestroyUnionRoomPlayerObjects();
            DestroyTask(taskId);
            Free(sWirelessLinkMain.uRoom);
            CreateTask_StartActivity();
        }
        break;
    case UR_STATE_INTERACT_WITH_ATTENDANT:
        if (GetHostRFUtgtGname()->species == SPECIES_NONE)
        {
            uroom->state = UR_STATE_REGISTER_PROMPT;
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
            ScheduleFieldMessageWithFollowupState(UR_STATE_CANCEL_REGISTRATION_PROMPT, gStringVar4);
        }
        break;
    case UR_STATE_REGISTER_PROMPT:
        if (PrintOnTextbox(&uroom->textState, sText_RegisterMonAtTradingBoard))
            uroom->state = UR_STATE_REGISTER_PROMPT_HANDLE_INPUT;
        break;
    case UR_STATE_REGISTER_PROMPT_HANDLE_INPUT:
        input = ListMenuHandler_AllItemsAvailable(&uroom->textState, 
                                                  &uroom->tradeBoardSelectWindowId, 
                                                  &uroom->tradeBoardDetailsWindowId, 
                                                  &sWindowTemplate_RegisterForTrade, 
                                                  &sListMenuTemplate_RegisterForTrade);
        if (input != -1)
        {
            if (input == -2 || input == 3)
            {
                uroom->state = UR_STATE_MAIN;
                HandleCancelActivity(TRUE);
            }
            else
            {
                switch (input)
                {
                case 1: // REGISTER
                    ScheduleFieldMessageWithFollowupState(UR_STATE_REGISTER_SELECT_MON_FADE, sText_WhichMonWillYouOffer);
                    break;
                case 2: // INFO
                    ScheduleFieldMessageWithFollowupState(UR_STATE_REGISTER_PROMPT_HANDLE_INPUT, sText_TradingBoardInfo);
                    break;
                }
            }
        }
        break;
    case UR_STATE_REGISTER_SELECT_MON_FADE:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, RGB_BLACK);
        uroom->state = UR_STATE_REGISTER_SELECT_MON;
        break;
    case UR_STATE_REGISTER_SELECT_MON:
        if (!gPaletteFade.active)
        {
            sUnionRoomTrade.state = URTRADE_STATE_REGISTERING;
            gFieldCallback = FieldCB_ContinueScriptUnionRoom;
            ChooseMonForTradingBoard(PARTY_MENU_TYPE_UNION_ROOM_REGISTER, CB2_ReturnToField);
        }
        break;
    case UR_STATE_REGISTER_REQUEST_TYPE:
        input = ListMenuHandler_AllItemsAvailable(&uroom->textState, 
                                                  &uroom->tradeBoardSelectWindowId, 
                                                  &uroom->tradeBoardDetailsWindowId, 
                                                  &gUnknown_082F0294, 
                                                  &sMenuTemplate_TradingBoardRequestType);
        if (input != -1)
        {
            switch (input)
            {
            case -2:
            case NUMBER_OF_MON_TYPES: // Exit
                ResetUnionRoomTrade(&sUnionRoomTrade);
                SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
                ScheduleFieldMessageAndExit(sText_RegistrationCanceled);
                break;
            default:
                sUnionRoomTrade.type = input;
                uroom->state = UR_STATE_REGISTER_COMPLETE;
                break;
            }
        }
        break;
    case UR_STATE_REGISTER_COMPLETE:
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        ScheduleFieldMessageAndExit(sText_RegistraionCompleted);
        break;
    case UR_STATE_CANCEL_REGISTRATION_PROMPT:
        switch (UnionRoomHandleYesNo(&uroom->textState, FALSE))
        {
        case 0: // YES
            uroom->state = UR_STATE_CANCEL_REGISTRATION;
            break;
        case 1: // NO
        case -1:
            HandleCancelActivity(TRUE);
            uroom->state = UR_STATE_MAIN;
            break;
        }
        break;
    case UR_STATE_CANCEL_REGISTRATION:
        if (PrintOnTextbox(&uroom->textState, sText_RegistrationCanceled2))
        {
            SetTradeBoardRegisteredMonInfo(TYPE_NORMAL, SPECIES_NONE, 0);
            ResetUnionRoomTrade(&sUnionRoomTrade);
            HandleCancelActivity(TRUE);
            uroom->state = UR_STATE_MAIN;
        }
        break;
    case UR_STATE_CHECK_TRADING_BOARD:
        if (PrintOnTextbox(&uroom->textState, sText_XCheckedTradingBoard))
            uroom->state = UR_STATE_TRADING_BOARD_LOAD;
        break;
    case UR_STATE_TRADING_BOARD_LOAD:
        UR_ClearBg0();
        uroom->state = UR_STATE_TRADING_BOARD_HANDLE_INPUT;
        break;
    case UR_STATE_TRADING_BOARD_HANDLE_INPUT:
        input = TradeBoardMenuHandler(&uroom->textState, &uroom->tradeBoardSelectWindowId, &uroom->tradeBoardListMenuId, &uroom->tradeBoardDetailsWindowId, &gUnknown_082F034C, &sTradeBoardListMenuTemplate, uroom->field_0);
        if (input != -1)
        {
            switch (input)
            {
            case -2:
            case 8: // EXIT
                HandleCancelActivity(TRUE);
                uroom->state = UR_STATE_MAIN;
                break;
            default:
                UR_ClearBg0();
                switch (IsRequestedTypeOrEggInPlayerParty(uroom->field_0->arr[input].gname_uname.gname.type, uroom->field_0->arr[input].gname_uname.gname.species))
                {
                case UR_TRADE_MATCH:
                    IntlConvPartnerUname7(gStringVar1, &uroom->field_0->arr[input]);
                    ScheduleFieldMessageWithFollowupState(UR_STATE_TRADE_PROMPT, sText_AskTrainerToMakeTrade);
                    taskData[1] = input;
                    break;
                case UR_TRADE_NOTYPE:
                    IntlConvPartnerUname7(gStringVar1, &uroom->field_0->arr[input]);
                    StringCopy(gStringVar2, gTypeNames[uroom->field_0->arr[input].gname_uname.gname.type]);
                    ScheduleFieldMessageWithFollowupState(UR_STATE_TRADING_BOARD_LOAD, sText_DontHaveTypeTrainerWants);
                    break;
                case UR_TRADE_NOEGG:
                    IntlConvPartnerUname7(gStringVar1, &uroom->field_0->arr[input]);
                    StringCopy(gStringVar2, gTypeNames[uroom->field_0->arr[input].gname_uname.gname.type]);
                    ScheduleFieldMessageWithFollowupState(UR_STATE_TRADING_BOARD_LOAD, sText_DontHaveEggTrainerWants);
                    break;
                }
                break;
            }
        }
        break;
    case UR_STATE_TRADE_PROMPT:
        switch (UnionRoomHandleYesNo(&uroom->textState, FALSE))
        {
        case 0: // YES
            uroom->state = UR_STATE_TRADE_SELECT_MON;
            break;
        case -1: // NO
        case 1:
            HandleCancelActivity(TRUE);
            uroom->state = UR_STATE_MAIN;
            break;
        }
        break;
    case UR_STATE_TRADE_SELECT_MON:
        if (PrintOnTextbox(&uroom->textState, sText_WhichMonWillYouOffer))
        {
            sUnionRoomTrade.state = URTRADE_STATE_OFFERING;
            memcpy(&gPartnerTgtGnameSub, &uroom->field_0->arr[taskData[1]].gname_uname.gname.unk_00, sizeof(gPartnerTgtGnameSub));
            gUnionRoomRequestedMonType = uroom->field_0->arr[taskData[1]].gname_uname.gname.type;
            gUnionRoomOfferedSpecies = uroom->field_0->arr[taskData[1]].gname_uname.gname.species;
            gFieldCallback = FieldCB_ContinueScriptUnionRoom;
            ChooseMonForTradingBoard(PARTY_MENU_TYPE_UNION_ROOM_TRADE, CB2_ReturnToField);
            sub_80156B0(uroom);
            sUnionRoomTrade.offerPlayerId = taskData[1];
        }
        break;
    case UR_STATE_TRADE_OFFER_MON:
        gPlayerCurrActivity = ACTIVITY_TRADE | IN_UNION_ROOM;
        sub_8012188(uroom->field_0->arr[taskData[1]].gname_uname.playerName, &uroom->field_0->arr[taskData[1]].gname_uname.gname, gPlayerCurrActivity);
        IntlConvPartnerUname7(gStringVar1, &uroom->field_0->arr[taskData[1]]);
        UR_PrintFieldMessage(sCommunicatingWaitTexts[2]);
        uroom->state = UR_STATE_TRY_COMMUNICATING;
        break;
    case UR_STATE_PRINT_AND_EXIT:
        if (PrintOnTextbox(&uroom->textState, gStringVar4))
        {
            HandleCancelActivity(TRUE);
            UpdateUnionRoomMemberFacing(taskData[0], taskData[1], uroom->field_0);
            uroom->state = UR_STATE_MAIN;
        }
        break;
    case UR_STATE_PRINT_MSG:
        if (PrintOnTextbox(&uroom->textState, gStringVar4))
            uroom->state = uroom->stateAfterPrint;
        break;
    }
}

void SetUsingUnionRoomStartMenu(void)
{
    if (InUnionRoom() == TRUE)
        gSpecialVar_Result = UR_INTERACT_START_MENU;
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

static bool32 UnionRoom_HandleContactFromOtherPlayer(struct WirelessLink_URoom *uroom)
{
    if (uroom->recvActivityRequest[0] != 0)
    {
        s32 id = GetChatLeaderActionRequestMessage(gStringVar4, gLinkPlayers[1].gender, &uroom->recvActivityRequest[0], uroom);
        if (id == 0) // Error
        {
            return TRUE;
        }
        else if (id == 1) // Recieve activity request
        {
            uroom->state = UR_STATE_RECV_ACTIVITY_REQUEST;
            gPlayerCurrActivity = uroom->recvActivityRequest[0];
            return FALSE;
        }
        else if (id == 2) // No activity
        {
            uroom->state = UR_STATE_CANCEL_REQUEST_PRINT_MSG;
            SetCloseLinkCallback();
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
    data->unknown = 0;
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
        data->searchTaskId = CreateTask_SearchForChildOrParent(data->field_C, data->field_4, 10);
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
        DestroyTask(data->searchTaskId);
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
            data->field_8->arr[0].timeoutCounter = 0;
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
                        data->field_0->arr[j].field_1B = 64;
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
                data->field_0->arr[j].timeoutCounter = 0;
            }
            else if (data->field_0->arr[j].groupScheduledAnim != UNION_ROOM_SPAWN_OUT)
            {
                data->field_0->arr[j].timeoutCounter++;
                if (data->field_0->arr[j].timeoutCounter >= 600)
                {
                    data->field_0->arr[j].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                    r7 = 2;
                }
            }
            else if (data->field_0->arr[j].groupScheduledAnim == UNION_ROOM_SPAWN_OUT)
            {
                data->field_0->arr[j].timeoutCounter++;
                if (data->field_0->arr[j].timeoutCounter >= 900)
                {
                    ClearUnkStruct_x20Array(&data->field_0->arr[j], 1);
                }
            }
        }
    }
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Appendx1Ctox20(&data->field_0->arr[0], &data->field_4->arr[i], MAX_UNION_ROOM_PLAYERS) != 0xFF)
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
    s8 input;

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
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == -1 || input == 0 || input == 1)
        {
            *state = 0;
            return input;
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
        if (JOY_NEW(A_BUTTON))
        {
            DestroyListMenuTask(*listMenuId, NULL, NULL);
            ClearStdWindowAndFrame(*windowId, TRUE);
            RemoveWindow(*windowId);
            *state = 0;
            return input;
        }
        else if (JOY_NEW(B_BUTTON))
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
        *tradeBoardWindowId = CreateTradeBoardWindow(&sWindowTemplate_TradingBoard);
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
        input = ListMenu_ProcessInput(*listMenuId);
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            if (input == 8 || JOY_NEW(B_BUTTON))
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
        arr[i].timeoutCounter = 255;
        arr[i].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
        arr[i].useRedText = FALSE;
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

static u8 Appendx1Ctox20(struct UnkStruct_x20 *arg0, struct UnkStruct_x1C *arg1, u8 max)
{
    s32 i;

    if (arg1->active)
    {
        for (i = 0; i < max; i++)
        {
            if (arg0[i].groupScheduledAnim == UNION_ROOM_SPAWN_NONE)
            {
                arg0[i].gname_uname = arg1->gname_uname;
                arg0[i].timeoutCounter = 0;
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

static bool32 IsPlayerFacingTradingBoard(void)
{
    s16 x, y;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    if (x != 2 + 7)
        return FALSE;

    if (y != 1 + 7)
        return FALSE;

    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
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
        UR_AddTextPrinterParameterized(windowId, 1, sText_EggTrade, 68, y, colorIdx);
    }
    else
    {
        BlitMenuInfoIcon(windowId, type + 1, 68, y);
        UR_AddTextPrinterParameterized(windowId, 1, gSpeciesNames[species], 118, y, colorIdx);
        ConvertIntToDecimalStringN(levelStr, level, STR_CONV_MODE_RIGHT_ALIGN, 3);
        UR_AddTextPrinterParameterized(windowId, 1, levelStr, 198, y, colorIdx);
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
    case ACTIVITY_NONE | IN_UNION_ROOM:
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
    uroomTrade->state = URTRADE_STATE_NONE;
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

static void HandleCancelActivity(bool32 setData)
{
    UR_ClearBg0();
    ScriptContext2_Disable();
    UnionRoom_UnlockPlayerAndChatPartner();
    gPlayerCurrActivity = ACTIVITY_NONE;
    if (setData)
    {
        SetTradeBoardRegisteredMonInfo(sUnionRoomTrade.type, sUnionRoomTrade.playerSpecies, sUnionRoomTrade.playerLevel);
        UpdateGameData_SetActivity(ACTIVITY_NONE | IN_UNION_ROOM, 0, FALSE);
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

    StringCopy(data->trainerCardStrBuffer[0], gTrainerClassNames[GetUnionRoomTrainerClass()]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, data->trainerCardStrBuffer[0]);

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, trainerCard->playerName);

    StringCopy(data->trainerCardColorStrBuffer, sCardColorTexts[trainerCard->stars]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, data->trainerCardColorStrBuffer);

    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[2], trainerCard->caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, data->trainerCardStrBuffer[2]);

    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[3], trainerCard->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[4], trainerCard->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, data->trainerCardStrBuffer[3]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, data->trainerCardStrBuffer[4]);

    DynamicPlaceholderTextUtil_ExpandPlaceholders(data->trainerCardMsgStrBuffer, sText_TrainerCardInfoPage1);
    StringCopy(gStringVar4, data->trainerCardMsgStrBuffer);

    n = trainerCard->linkBattleWins;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[0], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, data->trainerCardStrBuffer[0]);

    n = trainerCard->linkBattleLosses;
    if (n > 9999)
    {
        n = 9999;
    }
    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[1], n, STR_CONV_MODE_LEFT_ALIGN, 4);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, data->trainerCardStrBuffer[1]);

    ConvertIntToDecimalStringN(data->trainerCardStrBuffer[2], trainerCard->pokemonTrades, STR_CONV_MODE_LEFT_ALIGN, 5);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, data->trainerCardStrBuffer[2]);

    for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
    {
        CopyEasyChatWord(data->trainerCardStrBuffer[i + 3], trainerCard->easyChatProfile[i]);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(i + 4, data->trainerCardStrBuffer[i + 3]);
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(data->trainerCardMsgStrBuffer, sText_TrainerCardInfoPage2);
    StringAppend(gStringVar4, data->trainerCardMsgStrBuffer);

    if (isParent == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(data->trainerCardMsgStrBuffer, sText_FinishedCheckingPlayersTrainerCard);
        StringAppend(gStringVar4, data->trainerCardMsgStrBuffer);
    }
    else if (isParent == FALSE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(data->trainerCardMsgStrBuffer, sGladToMeetYouTexts[trainerCard->gender]);
        StringAppend(gStringVar4, data->trainerCardMsgStrBuffer);
    }
}

static void IntlConvPartnerUname7(u8 *dest, struct UnkStruct_x20 *arg1)
{
    StringCopy7(dest, arg1->gname_uname.playerName);
    ConvertInternationalString(dest, arg1->gname_uname.gname.unk_00.language);
}
