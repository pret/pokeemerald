#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_records.h"
#include "battle_setup.h"
#include "cable_club.h"
#include "data.h"
#include "event_data.h"
#include "field_message_box.h"
#include "field_specials.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "m4a.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "union_room.h"
#include "mevent2.h"
#include "script.h"
#include "script_pokemon_util_80F87D8.h"
#include "sound.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trade.h"
#include "trainer_card.h"
#include "party_menu.h"
#include "window.h"
#include "constants/battle_frontier.h"
#include "constants/cable_club.h"
#include "constants/songs.h"

static const struct WindowTemplate gUnknown_08550594 = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 11,
    .width = 11,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0125,
};
static const u8 *const gTrainerCardColorNames[] = {
    gText_BronzeCard,
    gText_CopperCard,
    gText_SilverCard,
    gText_GoldCard
};

static void sub_80B2634(u8 taskId);
static void sub_80B2688(u8 taskId);
static void sub_80B270C(u8 taskId);
static void sub_80B275C(u8 taskId);
static void sub_80B2804(u8 taskId);
static void sub_80B28A8(u8 taskId);
static void sub_80B2918(u8 taskId);
static void sub_80B2A08(u8 taskId);
static void sub_80B2C30(u8 taskId);
static void sub_80B2CB0(u8 taskId);
static void sub_80B2CEC(u8 taskId);
static void sub_80B2D2C(u8 taskId);
static bool8 sub_80B2D6C(u8 taskId);
static void sub_80B2EE4(u8 taskId);
static void sub_80B3144(u8 taskId);
static void sub_80B3194(u8 taskId);
static void sub_80B31E8(u8 taskId);
static void sub_80B3220(u8 taskId);

static void sub_80B236C(u8 arg0, u8 arg1)
{
    if (FindTaskIdByFunc(sub_80B2634) == 0xFF)
    {
        u8 taskId1;

        taskId1 = CreateTask(sub_80B2634, 80);
        gTasks[taskId1].data[1] = arg0;
        gTasks[taskId1].data[2] = arg1;
    }
}

static void sub_80B23B0(u16 windowId, u32 value)
{
    u8 xPos;

    ConvertIntToDecimalStringN(gStringVar1, value, STR_CONV_MODE_LEFT_ALIGN, 1);
    SetStandardWindowBorderStyle(windowId, 0);
    StringExpandPlaceholders(gStringVar4, gText_XPLink);
    xPos = GetStringCenterAlignXOffset(1, gStringVar4, 88);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, xPos, 1, 0xFF, NULL);
    CopyWindowToVram(windowId, 3);
}

static void sub_80B241C(u16 windowId)
{
    // Following this call with a copy-to-vram with mode 3 is identical to
    // calling ClearStdWindowAndFrame(windowId, TRUE).
    ClearStdWindowAndFrame(windowId, FALSE);
    CopyWindowToVram(windowId, 3);
}

static void sub_80B243C(u8 taskId, u8 arg1)
{
    s16 *data = gTasks[taskId].data;

    if (arg1 != data[3])
    {
        if (arg1 <= 1)
            sub_80B241C(data[5]);
        else
            sub_80B23B0(data[5], arg1);
        data[3] = arg1;
    }
}

static u32 sub_80B2478(u8 lower, u8 upper)
{
    int playerCount;

    switch (GetLinkPlayerDataExchangeStatusTimed(lower, upper))
    {
    case EXCHANGE_COMPLETE:
        return 1;
    case EXCHANGE_IN_PROGRESS:
        return 3;
    case EXCHANGE_PLAYER_NOT_READY:
        return 7;
    case EXCHANGE_PARTNER_NOT_READY:
        return 9;
    case EXCHANGE_STAT_6:
        ConvertIntToDecimalStringN(gStringVar1, GetLinkPlayerCount_2(), STR_CONV_MODE_LEFT_ALIGN, 1);
        return 4;
    case EXCHANGE_STAT_7:
        return 10;
    case EXCHANGE_TIMED_OUT:
    default:
        return 0;
    }
}

static bool32 sub_80B24F8(u8 taskId)
{
    if (HasLinkErrorOccurred() == TRUE)
    {
        gTasks[taskId].func = sub_80B2D2C;
        return TRUE;
    }
    return FALSE;
}

static bool32 sub_80B252C(u8 taskId)
{
    if ((gMain.newKeys & B_BUTTON)
     && IsLinkConnectionEstablished() == FALSE)
    {
        gLinkType = 0;
        gTasks[taskId].func = sub_80B2CEC;
        return TRUE;
    }
    return FALSE;
}

static bool32 sub_80B2578(u8 taskId)
{
    if (IsLinkConnectionEstablished())
        SetSuppressLinkErrorMessage(TRUE);

    if (gMain.newKeys & B_BUTTON)
    {
        gLinkType = 0;
        gTasks[taskId].func = sub_80B2CEC;
        return TRUE;
    }
    return FALSE;
}

static bool32 sub_80B25CC(u8 taskId)
{
    if (GetSioMultiSI() == 1)
    {
        gTasks[taskId].func = sub_80B2D2C;
        return TRUE;
    }
    return FALSE;
}

static void sub_80B2600(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 10)
    {
        sub_800A4D8(2);
        DestroyTask(taskId);
    }
}

static void sub_80B2634(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        OpenLinkTimed();
        ResetLinkPlayerCount();
        ResetLinkPlayers();
        data[5] = AddWindow(&gUnknown_08550594);
    }
    else if (data[0] > 9)
    {
        gTasks[taskId].func = sub_80B2688;
    }
    data[0]++;
}

static void sub_80B2688(u8 taskId)
{
    u32 playerCount = GetLinkPlayerCount_2();

    if (sub_80B252C(taskId) == TRUE
     || sub_80B2578(taskId) == TRUE
     || playerCount < 2)
        return;

    SetSuppressLinkErrorMessage(TRUE);
    gTasks[taskId].data[3] = 0;
    if (IsLinkMaster() == TRUE)
    {
        PlaySE(SE_PIN);
        ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
        gTasks[taskId].func = sub_80B270C;
    }
    else
    {
        PlaySE(SE_BOO);
        ShowFieldAutoScrollMessage(gText_AwaitingLinkup);
        gTasks[taskId].func = sub_80B2918;
    }
}

static void sub_80B270C(u8 taskId)
{
    if (sub_80B252C(taskId) == TRUE
     || sub_80B25CC(taskId) == TRUE
     || sub_80B24F8(taskId) == TRUE)
        return;

    if (GetFieldMessageBoxMode() == FIELD_MESSAGE_BOX_HIDDEN)
    {
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].func = sub_80B275C;
    }
}

static void sub_80B275C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s32 linkPlayerCount = GetLinkPlayerCount_2();

    if (sub_80B252C(taskId) == TRUE
     || sub_80B25CC(taskId) == TRUE
     || sub_80B24F8(taskId) == TRUE)
        return;

    sub_80B243C(taskId, linkPlayerCount);

    if (!(gMain.newKeys & A_BUTTON))
        return;

    if (linkPlayerCount < data[1])
        return;

    sub_800AA04(linkPlayerCount);
    sub_80B241C(data[5]);
    ConvertIntToDecimalStringN(gStringVar1, linkPlayerCount, STR_CONV_MODE_LEFT_ALIGN, 1);
    ShowFieldAutoScrollMessage(gText_ConfirmStartLinkWithXPlayers);
    gTasks[taskId].func = sub_80B2804;
}

static void sub_80B2804(u8 taskId)
{
    if (sub_80B252C(taskId) == TRUE
     || sub_80B25CC(taskId) == TRUE
     || sub_80B24F8(taskId) == TRUE)
        return;

    if (GetFieldMessageBoxMode() == FIELD_MESSAGE_BOX_HIDDEN)
    {
        if (GetSavedPlayerCount() != GetLinkPlayerCount_2())
        {
            ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
            gTasks[taskId].func = sub_80B270C;
        }
        else if (gMain.heldKeys & B_BUTTON)
        {
            ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
            gTasks[taskId].func = sub_80B270C;
        }
        else if (gMain.heldKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            CheckShouldAdvanceLinkState();
            gTasks[taskId].func = sub_80B28A8;
        }
    }
}

static void sub_80B28A8(u8 taskId)
{
    u8 local1 = gTasks[taskId].data[1];
    u8 local2 = gTasks[taskId].data[2];

    if (sub_80B24F8(taskId) == TRUE
     || sub_80B2D6C(taskId) == TRUE)
        return;

    if (GetLinkPlayerCount_2() != GetSavedPlayerCount())
    {
        gTasks[taskId].func = sub_80B2D2C;
    }
    else
    {
        gSpecialVar_Result = sub_80B2478(local1, local2);
        if (gSpecialVar_Result != 0)
            gTasks[taskId].func = sub_80B2A08;
    }
}

static void sub_80B2918(u8 taskId)
{
    u8 local1, local2;
    struct TrainerCard *card;

    local1 = gTasks[taskId].data[1];
    local2 = gTasks[taskId].data[2];

    if (sub_80B252C(taskId) == TRUE
     || sub_80B24F8(taskId) == TRUE)
        return;

    gSpecialVar_Result = sub_80B2478(local1, local2);
    if (gSpecialVar_Result == 0)
        return;
    if (gSpecialVar_Result == 3 || gSpecialVar_Result == 4)
    {
        sub_800AC34();
        HideFieldMessageBox();
        gTasks[taskId].func = sub_80B2CB0;
    }
    else if (gSpecialVar_Result == 7 || gSpecialVar_Result == 9)
    {
        CloseLink();
        HideFieldMessageBox();
        gTasks[taskId].func = sub_80B2CB0;
    }
    else
    {
        gFieldLinkPlayerCount = GetLinkPlayerCount_2();
        gLocalLinkPlayerId = GetMultiplayerId();
        sub_800AA04(gFieldLinkPlayerCount);
        card = (struct TrainerCard *)gBlockSendBuffer;
        TrainerCard_GenerateCardForPlayer(card);
        card->monSpecies[0] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[0] - 1], MON_DATA_SPECIES, NULL);
        card->monSpecies[1] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[1] - 1], MON_DATA_SPECIES, NULL);
        gTasks[taskId].func = sub_80B2C30;
    }
}

static void sub_80B2A08(u8 taskId)
{
    struct TrainerCard *card;

    if (sub_80B24F8(taskId) == TRUE)
        return;

    if (gSpecialVar_Result == 4)
    {
        if (!Link_AnyPartnersPlayingRubyOrSapphire())
        {
            sub_800AC34();
            HideFieldMessageBox();
            gTasks[taskId].func = sub_80B2CB0;
        }
        else
        {
            CloseLink();
            HideFieldMessageBox();
            gTasks[taskId].func = sub_80B2CB0;
        }
    }
    else if (gSpecialVar_Result == 3)
    {
        sub_800AC34();
        HideFieldMessageBox();
        gTasks[taskId].func = sub_80B2CB0;
    }
    else if (gSpecialVar_Result == 7 || gSpecialVar_Result == 9)
    {
        CloseLink();
        HideFieldMessageBox();
        gTasks[taskId].func = sub_80B2CB0;
    }
    else
    {
        gFieldLinkPlayerCount = GetLinkPlayerCount_2();
        gLocalLinkPlayerId = GetMultiplayerId();
        sub_800AA04(gFieldLinkPlayerCount);
        card = (struct TrainerCard *)gBlockSendBuffer;
        TrainerCard_GenerateCardForPlayer(card);
        card->monSpecies[0] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[0] - 1], MON_DATA_SPECIES, NULL);
        card->monSpecies[1] = GetMonData(&gPlayerParty[gSelectedOrderFromParty[1] - 1], MON_DATA_SPECIES, NULL);
        gTasks[taskId].func = sub_80B2C30;
        sub_800A4D8(2);
    }
}

bool32 sub_80B2AF4(u16 *arg0, u16 *arg1)
{
    int i;
    int j;
    bool32 result = FALSE;
    int k = 0;

    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (arg0[i] == arg1[j])
            {
                if (k == 0)
                {
                    StringCopy(gStringVar1, gSpeciesNames[arg0[i]]);
                    result = TRUE;
                }

                if (k == 1)
                {
                    StringCopy(gStringVar2, gSpeciesNames[arg0[i]]);
                    result = TRUE;
                }

                k++;
            }
        }
    }

    gSpecialVar_0x8005 = k;

    return result;
}

static void task_map_chg_seq_0807EC34(u16 *a0, u32 taskId)
{
    struct TrainerCard *trainerCards = gTrainerCards;

    if (*a0 == 1)
    {
        if (gLinkType == LINKTYPE_BATTLE_TOWER_50 || gLinkType == LINKTYPE_BATTLE_TOWER_OPEN)
        {
            if (sub_80B2AF4(trainerCards[0].monSpecies, trainerCards[1].monSpecies))
            {
                *a0 = 11;
                sub_800AC34();
                gTasks[taskId].func = sub_80B2CB0;
            }
            else
            {
                sub_80B241C(gTasks[taskId].data[5]);
                EnableBothScriptContexts();
                DestroyTask(taskId);
            }
        }
        else
        {
            sub_80B241C(gTasks[taskId].data[5]);
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
    }
    else
    {
        sub_800AC34();
        gTasks[taskId].func = sub_80B2CB0;
    }
}

static void sub_80B2C30(u8 taskId)
{
    u8 index;
    struct TrainerCard *trainerCards;

    if (sub_80B24F8(taskId) == TRUE)
        return;

    if (GetBlockReceivedStatus() != sub_800A9A8())
        return;

    for (index = 0; index < GetLinkPlayerCount(); index++)
    {
        CopyTrainerCardData(&gTrainerCards[index], gBlockRecvBuffer[index], gLinkPlayers[index].version);
    }

    SetSuppressLinkErrorMessage(FALSE);
    ResetBlockReceivedFlags();
    task_map_chg_seq_0807EC34(&gSpecialVar_Result, taskId);
}

static void sub_80B2CB0(u8 taskId)
{
    if (gReceivedRemoteLinkPlayers == FALSE)
    {
        sub_80B241C(gTasks[taskId].data[5]);
        EnableBothScriptContexts();
        RemoveWindow(gTasks[taskId].data[5]);
        DestroyTask(taskId);
    }
}

static void sub_80B2CEC(u8 taskId)
{
    gSpecialVar_Result = 5;
    sub_80B241C(gTasks[taskId].data[5]);
    StopFieldMessage();
    RemoveWindow(gTasks[taskId].data[5]);
    EnableBothScriptContexts();
    DestroyTask(taskId);
}

static void sub_80B2D2C(u8 taskId)
{
    gSpecialVar_Result = 6;
    sub_80B241C(gTasks[taskId].data[5]);
    RemoveWindow(gTasks[taskId].data[5]);
    HideFieldMessageBox();
    EnableBothScriptContexts();
    DestroyTask(taskId);
}

static bool8 sub_80B2D6C(u8 taskId)
{
    gTasks[taskId].data[4]++;
    if (gTasks[taskId].data[4] > 600)
    {
        gTasks[taskId].func = sub_80B2D2C;
        return TRUE;
    }

    return FALSE;
}

void TryBattleLinkup(u8 arg0)
{
    u8 r3 = 2;
    u8 r2 = 2;

    switch (gSpecialVar_0x8004)
    {
    case USING_SINGLE_BATTLE:
        r3 = 2;
        gLinkType = LINKTYPE_SINGLE_BATTLE;
        break;
    case USING_DOUBLE_BATTLE:
        r3 = 2;
        gLinkType = LINKTYPE_DOUBLE_BATTLE;
        break;
    case USING_MULTI_BATTLE:
        r3 = 4;
        r2 = 4;
        gLinkType = LINKTYPE_MULTI_BATTLE;
        break;
    case USING_BATTLE_TOWER:
        r3 = 2;
        if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_50)
            gLinkType = LINKTYPE_BATTLE_TOWER_50;
        else
            gLinkType = LINKTYPE_BATTLE_TOWER_OPEN;

        break;
    }

    sub_80B236C(r3, r2);
}

void TryTradeLinkup(void)
{
    gLinkType = LINKTYPE_0x1133;
    gBattleTypeFlags = 0;
    sub_80B236C(2, 2);
}

void TryRecordMixLinkup(void)
{
    gSpecialVar_Result = 0;
    gLinkType = LINKTYPE_0x3311;
    gBattleTypeFlags = 0;
    sub_80B236C(2, 4);
}

void sub_80B2EA8(void)
{
    u32 taskId = FindTaskIdByFunc(sub_80B2EE4);

    if (taskId == 0xFF)
    {
        taskId = CreateTask(sub_80B2EE4, 80);
        gTasks[taskId].data[0] = 0;
    }
}

static void sub_80B2EE4(u8 taskId)
{
    int playerCount;
    int i;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gSpecialVar_Result == 1)
        {
            bool32 unk = FALSE;
            bool32 isEnglishRSLinked = FALSE;
            bool32 isJapaneseEmeraldLinked = FALSE;

            playerCount = GetLinkPlayerCount();
            for (i = 0; i < playerCount; i++)
            {
                u32 version = (u8)gLinkPlayers[i].version;
                u32 language = gLinkPlayers[i].language;

                if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
                {
                    if (language == LANGUAGE_JAPANESE)
                    {
                        unk = TRUE;
                        break;
                    }
                    else
                    {
                        isEnglishRSLinked = TRUE;
                    }
                }
                else if (version == VERSION_EMERALD)
                {
                    if (language == LANGUAGE_JAPANESE)
                    {
                        isJapaneseEmeraldLinked = TRUE;
                    }
                }
            }

            if (isEnglishRSLinked && isJapaneseEmeraldLinked)
            {
                unk = TRUE;
            }

            if (unk)
            {
                gSpecialVar_Result = 12;
                sub_800AD10();
                gTasks[taskId].data[0] = 1;
                return;
            }
        }
        EnableBothScriptContexts();
        DestroyTask(taskId);
        break;
    case 1:
        if (gReceivedRemoteLinkPlayers == FALSE)
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        break;
    }
}

void TryBerryBlenderLinkup(void)
{
    gLinkType = LINKTYPE_BERRY_BLENDER_SETUP;
    gBattleTypeFlags = 0;
    sub_80B236C(2, 4);
}

void TryContestGModeLinkup(void)
{
    gLinkType = LINKTYPE_CONTEST_GMODE;
    gBattleTypeFlags = 0;
    sub_80B236C(4, 4);
}

void TryContestEModeLinkup(void)
{
    gLinkType = LINKTYPE_CONTEST_EMODE;
    gBattleTypeFlags = 0;
    sub_80B236C(2, 4);
}

u8 sub_80B3050(void)
{
    if (FuncIsActiveTask(sub_80B3144) != FALSE)
        return 0xFF;

    switch (gSpecialVar_0x8004)
    {
    case USING_SINGLE_BATTLE:
        gLinkType = LINKTYPE_SINGLE_BATTLE;
        break;
    case USING_DOUBLE_BATTLE:
        gLinkType = LINKTYPE_DOUBLE_BATTLE;
        break;
    case USING_MULTI_BATTLE:
        gLinkType = LINKTYPE_MULTI_BATTLE;
        break;
    case USING_BATTLE_TOWER:
        if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_50)
        {
            gLinkType = LINKTYPE_BATTLE_TOWER_50;
        }
        else
        {
            gLinkType = LINKTYPE_BATTLE_TOWER_OPEN;
        }
        break;
    case USING_TRADE_CENTER:
        gLinkType = LINKTYPE_0x1111;
        break;
    case USING_RECORD_CORNER:
        gLinkType = LINKTYPE_0x3322;
        break;
    }

    return CreateTask(sub_80B3144, 80);
}

static void sub_80B3144(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        OpenLink();
        ResetLinkPlayers();
        CreateTask(task00_08081A90, 80);
    }
    else if (data[0] >= 10)
    {
        gTasks[taskId].func = sub_80B3194;
    }
    data[0]++;
}

static void sub_80B3194(u8 taskId)
{
    if (GetLinkPlayerCount_2() >= 2)
    {
        if (IsLinkMaster() == TRUE)
            gTasks[taskId].func = sub_80B31E8;
        else
            gTasks[taskId].func = sub_80B3220;
    }
}

static void sub_80B31E8(u8 taskId)
{
    if (GetSavedPlayerCount() == GetLinkPlayerCount_2())
    {
        CheckShouldAdvanceLinkState();
        gTasks[taskId].func = sub_80B3220;
    }
}

static void sub_80B3220(u8 taskId)
{
    if (gReceivedRemoteLinkPlayers == TRUE
     && IsLinkPlayerDataExchangeComplete() == TRUE)
    {
        sub_800AB18();
        sub_8009F18();
        DestroyTask(taskId);
    }
}

// Unused
void CableClubSaveGame(void)
{
    SaveGame();
}

static void SetLinkBattleTypeFlags(int linkService)
{
    switch (linkService)
    {
        case USING_SINGLE_BATTLE:
            gBattleTypeFlags = BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER;
            break;
        case USING_DOUBLE_BATTLE:
            gBattleTypeFlags = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER;
            break;
        case USING_MULTI_BATTLE:
            ReducePlayerPartyToSelectedMons();
            gBattleTypeFlags = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI;
            break;
        case USING_BATTLE_TOWER:
            gBattleTypeFlags = BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI;
            break;
    }
}

static void sub_80B32B4(u8 taskId)
{
    struct Task* task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        FadeScreen(FADE_TO_BLACK, 0);
        gLinkType = LINKTYPE_BATTLE;
        ClearLinkCallback_2();
        task->data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
            task->data[0]++;
        break;
    case 2:
        task->data[1]++;
        if (task->data[1] > 20)
            task->data[0]++;
        break;
    case 3:
        sub_800AC34();
        task->data[0]++;
        break;
    case 4:
        if (!gReceivedRemoteLinkPlayers)
            task->data[0]++;
        break;
    case 5:
        if (gLinkPlayers[0].trainerId & 1)
            PlayMapChosenOrBattleBGM(MUS_BATTLE32);
        else
            PlayMapChosenOrBattleBGM(MUS_BATTLE20);

        SetLinkBattleTypeFlags(gSpecialVar_0x8004);
        CleanupOverworldWindowsAndTilemaps();
        gTrainerBattleOpponent_A = 0x800;
        SetMainCallback2(CB2_InitBattle);
        gMain.savedCallback = sub_80B360C;
        DestroyTask(taskId);
        break;
    }
}

static void sub_80B33BC(u8 taskId)
{
    int i;
    s16* data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        FadeScreen(FADE_TO_BLACK, 0);
        gLinkType = LINKTYPE_BATTLE;
        ClearLinkCallback_2();
        data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
            data[0] = 2;
        break;
    case 2:
        SendBlock(0, &gLocalLinkPlayer, sizeof(gLocalLinkPlayer));
        data[0] = 3;
        break;
    case 3:
        if (GetBlockReceivedStatus() == sub_800A9D8())
        {
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                struct LinkPlayer *player = (struct LinkPlayer *)gBlockRecvBuffer[i];
                gLinkPlayers[i] = *player;
                sub_800B524(&gLinkPlayers[i]);
                ResetBlockReceivedFlag(i);
            }
            data[0] = 4;
        }
        break;
    case 4:
        data[1]++;
        if (data[1] > 20)
            data[0] = 5;
        break;
    case 5:
        sub_800ADF8();
        data[0] = 6;
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            data[0] = 7;
        }
        break;
    case 7:
        if (gLinkPlayers[0].trainerId & 1)
            PlayMapChosenOrBattleBGM(MUS_BATTLE32);
        else
            PlayMapChosenOrBattleBGM(MUS_BATTLE20);

        gLinkPlayers[0].linkType = LINKTYPE_BATTLE;
        SetLinkBattleTypeFlags(gSpecialVar_0x8004);
        CleanupOverworldWindowsAndTilemaps();
        gTrainerBattleOpponent_A = 0x800;
        SetMainCallback2(CB2_InitBattle);
        gMain.savedCallback = sub_80B360C;
        DestroyTask(taskId);
        break;
    }
}

static void sub_80B3554(void)
{
    u8 playerCount;
    int i;
    bool32 r4;

    switch (gMain.state)
    {
        case 0:
            playerCount = GetLinkPlayerCount();
            r4 = FALSE;
            for (i = 0; i < playerCount; i++)
            {
                u32 version = (u8)gLinkPlayers[i].version;
                if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
                {
                    r4 = TRUE;
                    break;
                }
            }

            if (r4)
            {
                gMain.state = 2;
            }
            else
            {
                sub_800AC34();
                gMain.state = 1;
            }
            break;
        case 1:
            if (gReceivedRemoteLinkPlayers == FALSE)
            {
                SetMainCallback2(CB2_ReturnToField);
            }
            break;
        case 2:
            SetMainCallback2(CB2_ReturnToField);
            break;
    }
    RunTasks();
}

void sub_80B360C(void)
{
    gBattleTypeFlags &= ~BATTLE_TYPE_20;
    Overworld_ResetMapMusic();
    LoadPlayerParty();
    SavePlayerBag();
    UpdateTrainerFansAfterLinkBattle();

    if (gSpecialVar_0x8004 == USING_SINGLE_BATTLE || gSpecialVar_0x8004 == USING_DOUBLE_BATTLE)
    {
        UpdatePlayerLinkBattleRecords(gLocalLinkPlayerId ^ 1);
        if (gWirelessCommType)
        {
            switch (gBattleOutcome)
            {
                case B_OUTCOME_WON:
                    sub_801B990(0, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
                    break;
                case B_OUTCOME_LOST:
                    sub_801B990(1, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
                    break;
            }
        }
    }

    if (InUnionRoom() == TRUE)
    {
        gMain.savedCallback = sub_80B3554;
    }
    else
    {
        gMain.savedCallback = CB2_ReturnToFieldFromMultiplayer;
    }

    SetMainCallback2(sub_80A0514);
}

void CleanupLinkRoomState(void)
{
    if (gSpecialVar_0x8004 == USING_SINGLE_BATTLE 
     || gSpecialVar_0x8004 == USING_DOUBLE_BATTLE 
     || gSpecialVar_0x8004 == USING_MULTI_BATTLE 
     || gSpecialVar_0x8004 == USING_BATTLE_TOWER)
    {
        LoadPlayerParty();
        SavePlayerBag();
    }
    SetWarpDestinationToDynamicWarp(0x7F);
}

void ExitLinkRoom(void)
{
    QueueExitLinkRoomKey();
}

static void sub_80B3728(u8 taskId)
{
    struct Task* task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        ShowFieldMessage(gText_PleaseWaitForLink);
        task->data[0] = 1;
        break;
    case 1:
        if (IsFieldMessageBoxHidden())
        {
            sub_8087288();
            SetLocalLinkPlayerId(gSpecialVar_0x8005);
            task->data[0] = 2;
        }
        break;
    case 2:
        switch (sub_8087214())
        {
        case 0:
            break;
        case 1:
            HideFieldMessageBox();
            task->data[0] = 0;
            sub_80872C4();
            SwitchTaskToFollowupFunc(taskId);
            break;
        case 2:
            task->data[0] = 3;
            break;
        }
        break;
    case 3:
        sub_808729C();
        sub_8197AE8(TRUE);
        DestroyTask(taskId);
        EnableBothScriptContexts();
        break;
    }
}

void sub_80B37D4(TaskFunc followupFunc)
{
    u8 taskId = CreateTask(sub_80B3728, 80);
    SetTaskFuncWithFollowupFunc(taskId, sub_80B3728, followupFunc);
    ScriptContext1_Stop();
}

static void sub_80B37FC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        ScriptContext2_Enable();
        FadeScreen(FADE_TO_BLACK, 0);
        ClearLinkCallback_2();
        task->data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
            task->data[0]++;
        break;
    case 2:
        gSelectedTradeMonPositions[TRADE_PLAYER] = 0;
        gSelectedTradeMonPositions[TRADE_PARTNER] = 0;
        m4aMPlayAllStop();
        sub_800AC34();
        task->data[0]++;
        break;
    case 3:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetMainCallback2(CB2_StartCreateTradeMenu);
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_80B3894(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        ScriptContext2_Enable();
        FadeScreen(FADE_TO_BLACK, 0);
        ClearLinkRfuCallback();
        data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
            data[0]++;
        break;
    case 2:
        gSelectedTradeMonPositions[TRADE_PLAYER] = 0;
        gSelectedTradeMonPositions[TRADE_PARTNER] = 0;
        m4aMPlayAllStop();
        sub_800ADF8();
        data[0]++;
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            sub_8013F78();
            DestroyTask(taskId);
        }
        break;
    }
}

// Note: VAR_0x8005 is set to the ID of the trade seat.
void PlayerEnteredTradeSeat(void)
{
    if (gWirelessCommType != 0)
    {
        sub_80B37D4(sub_80B3894);
    }
    else
    {
        sub_80B37D4(sub_80B37FC);
    }
}

static void sub_80B3950(void)
{
    CreateTask(sub_80B37FC, 80);
}

void nullsub_37(void)
{

}

// Note: VAR_0x8005 is set to the ID of the player spot.
void ColosseumPlayerSpotTriggered(void)
{
    gLinkType = LINKTYPE_BATTLE;

    if (gWirelessCommType != 0)
    {
        sub_80B37D4(sub_80B33BC);
    }
    else
    {
        sub_80B37D4(sub_80B32B4);
    }
}

// This function is never called.
static void sub_80B39A4(void)
{
    u8 taskId = CreateTask(sub_80B3728, 80);
    ScriptContext1_Stop();
}

void Script_ShowLinkTrainerCard(void)
{
    ShowTrainerCardInLink(gSpecialVar_0x8006, CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

// Returns FALSE if the player has no stars. Returns TRUE otherwise, and puts the name of the
// color into gStringVar2.
bool32 GetLinkTrainerCardColor(u8 linkPlayerIndex)
{
    u32 numStars;

    gSpecialVar_0x8006 = linkPlayerIndex;
    StringCopy(gStringVar1, gLinkPlayers[linkPlayerIndex].name);

    numStars = GetTrainerCardStars(linkPlayerIndex);
    if (numStars == 0)
        return FALSE;

    StringCopy(gStringVar2, gTrainerCardColorNames[numStars - 1]);
    return TRUE;
}

void task00_08081A90(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0]++;
    if (task->data[0] > 300)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        DestroyTask(taskId);
    }

    if (gReceivedRemoteLinkPlayers)
    {
        if (gWirelessCommType == 0)
        {
            if (!sub_800AA60())
            {
                CloseLink();
                SetMainCallback2(CB2_LinkError);
            }
            DestroyTask(taskId);
        }
        else
        {
            DestroyTask(taskId);
        }
    }
}

static void sub_80B3AAC(u8 taskId)
{
    if (!gReceivedRemoteLinkPlayers)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void sub_80B3AD0(u8 taskId)
{
    sub_800AC34();
    gTasks[taskId].func = sub_80B3AAC;
}

void sub_80B3AF8(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            if (gWirelessCommType != 0)
            {
                DestroyTask(taskId);
            }
            else
            {
                OpenLink();
                CreateTask(task00_08081A90, 1);
                data[0]++;
            }
            break;
        case 1:
            if (++data[1] > 11)
            {
                data[1] = 0;
                data[0]++;
            }
            break;
        case 2:
            if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
            {
                if (IsLinkMaster())
                {
                    if (++data[1] > 30)
                    {
                        CheckShouldAdvanceLinkState();
                        data[0]++;
                    }
                }
                else
                {
                    data[0]++;
                }
            }
            break;
        case 3:
            if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
            {
                DestroyTask(taskId);
            }
            break;
    }
}

void TrySetBattleTowerLinkType(void)
{
    if (gWirelessCommType == 0)
    {
        gLinkType = LINKTYPE_BATTLE_TOWER;
    }
}
