#include "global.h"
#include "constants/songs.h"
#include "bg.h"
#include "decoration.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "constants/items.h"
#include "list_menu.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "menu_specialized.h"

// structures
struct Struct203BCC4
{
    struct ListMenuItem unk0[51];
    u8 unk198[51][0x18];
    u8 windowIds[6];
    u8 unk666;
    u8 spriteId;
    u8 spriteIds[7];
};

// static functions
static void InitPlayerPCMenu(u8 taskId);
static void PlayerPCProcessMenuInput(u8 taskId);
static void InitItemStorageMenu(u8 taskId, u8 var);

static u8 GetMailboxMailCount(void);
static void Mailbox_UpdateMailList(void);
static void Mailbox_DrawMailboxMenu(u8 taskId);
static void Mailbox_ProcessInput(u8 taskId);
static void Mailbox_PrintWhatToDoWithPlayerMailText(u8 taskId);
static void Mailbox_ReturnToPlayerPC(u8);
static void Mailbox_PrintMailOptions(u8 taskId);
static void Mailbox_MailOptionsProcessInput(u8 taskId);

static void PlayerPC_ItemStorage(u8 taskId);
static void PlayerPC_Mailbox(u8 taskId);
static void PlayerPC_Decoration(u8 var);
static void PlayerPC_TurnOff(u8 taskId);

static void Mailbox_DoMailMoveToBag(u8 taskId);
static void Mailbox_DoMailRead(u8 taskId);
static void Mailbox_MoveToBag(u8 taskId);
static void Mailbox_Give(u8 taskId);
static void Mailbox_Cancel(u8 taskId);

static void Mailbox_CancelMoveToBag(u8 taskId);
static void Mailbox_MoveToBagYesNoPrompt(u8 taskId);
static void Mailbox_DrawYesNoBeforeMove(u8 taskId);
static void Mailbox_DoGiveMailPokeMenu(u8 taskId);
static void Mailbox_NoPokemonForMail(u8 taskId);

static void Mailbox_FadeAndReadMail(u8 taskId);
static void Mailbox_ReturnToFieldFromReadMail(void);
static void Mailbox_DoRedrawMailboxMenuAfterReturn(void);
static void pal_fill_for_maplights_or_black(void);
static void Mailbox_HandleReturnToProcessInput(u8 taskId);
static void Mailbox_UpdateMailListAfterDeposit(void);

static void ItemStorage_Withdraw(u8 taskId);
static void ItemStorage_Deposit(u8 taskId);
static void ItemStorage_Toss(u8 taskId);
static void ItemStorage_Exit(u8 taskId);
static void ItemStorage_ResumeInputFromYesToss(u8 taskId);
static void ItemStorage_ResumeInputFromNoToss(u8 taskId);

static void ItemStorageMenuPrint(const u8 *);
static void ItemStorageMenuProcessInput(u8 taskId);
static void ItemStorage_ProcessWithdrawTossInput(u8 taskId);
static void ItemStorage_SetItemAndMailCount(u8);
static void ItemStorage_HandleReturnToProcessInput(u8 taskId);

static void ItemStorage_WithdrawToss_Helper(u8 taskId, bool8 toss);
static void Task_ItemStorage_Deposit(u8 taskId);
static void ItemStorage_DoItemWithdraw(u8 taskId);
static void ItemStorage_DoItemToss(u8 taskid);
static void ItemStorage_HandleQuantityRolling(u8 taskid);
static void ItemStorage_GoBackToPlayerPCMenu(u8 taskId);
static void ItemStorage_ItemSwapChoosePrompt(u8 taskId);
static void ItemStorage_DoItemAction(u8 taskId);
static void ItemStorage_ProcessInput(u8 taskId);
static void ItemStorage_DoItemSwap(u8 taskId, bool8 a);
static void ItemStorage_HandleRemoveItem(u8 taskId);
static void ItemStorage_WaitPressHandleResumeProcessInput(u8 taskId);
static void ItemStorage_StartScrollIndicatorAndProcessInput(u8 taskId);

static const u8* ItemStorage_GetItemPcResponse(u16);
static void CopyItemName_PlayerPC(u8 *string, u16 itemId);

static void sub_816BC14(void);
static void sub_816BFE0(u8 y, u8, u8 speed);
static void sub_816BCC4(u8);
static void sub_816C690(u8);
static void sub_816C4FC(u8 taskId);
static void sub_816C0C8(void);
static void sub_816C060(u16 itemId);
static void sub_816BEF0(s32 id);
static void sub_816B4DC(u8 taskId);
static void ItemStorage_MoveCursor(s32 id, bool8 b, struct ListMenu * thisMenu);
static void fish4_goto_x5_or_x6(u8 windowId, s32 id, u8 yOffset);

// EWRAM
static EWRAM_DATA const u8 *gPcItemMenuOptionOrder = NULL;
static EWRAM_DATA u8 gPcItemMenuOptionsNum = 0;
EWRAM_DATA struct PlayerPCItemPageStruct playerPCItemPageInfo = {0, 0, 0, 0, {0, 0, 0}, 0};
static EWRAM_DATA struct Struct203BCC4 *gUnknown_0203BCC4 = NULL;

// .rodata
static const u8 *const gPCText_OptionDescList[] =
{
    gText_TakeOutItemsFromPC,
    gText_StoreItemsInPC,
    gText_ThrowAwayItemsInPC,
    gText_GoBackPrevMenu,
};

static const struct MenuAction sPlayerPCMenuActions[] =
{
    { gText_ItemStorage, PlayerPC_ItemStorage },
    { gText_Mailbox, PlayerPC_Mailbox },
    { gText_Decoration, PlayerPC_Decoration },
    { gText_TurnOff, PlayerPC_TurnOff }
};

static const u8 gBedroomPC_OptionOrder[] =
{
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_DECORATION,
    PLAYERPC_MENU_TURNOFF
};

static const u8 gPlayerPC_OptionOrder[] =
{
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_TURNOFF
};

static const struct MenuAction gPCText_ItemPCOptionsText[] =
{
    { gText_WithdrawItem, ItemStorage_Withdraw },
    { gText_DepositItem, ItemStorage_Deposit },
    { gText_TossItem, ItemStorage_Toss },
    { gText_Cancel, ItemStorage_Exit }
};

static const struct ItemSlot gNewGamePCItems[] =
{
    { ITEM_POTION, 1 },
    { ITEM_NONE, 0 }
};

const struct MenuAction gMailboxMailOptions[] =
{
    { gText_Read, Mailbox_DoMailRead },
    { gText_MoveToBag, Mailbox_MoveToBag },
    { gText_Give2, Mailbox_Give },
    { gText_Cancel2, Mailbox_Cancel }
};

static const struct WindowTemplate gUnknown_085DFF24[3] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 9,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 1
    }
};

static const struct YesNoFuncTable ResumeFromWithdrawYesNoFuncList = // ResumeFromWithdrawYesNoFuncList
{
    ItemStorage_ResumeInputFromYesToss,
    ItemStorage_ResumeInputFromNoToss
};

static const struct ListMenuTemplate gUnknown_085DFF44 =
{
    .items = NULL,
    .moveCursorFunc = ItemStorage_MoveCursor,
    .itemPrintFunc = fish4_goto_x5_or_x6,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 9,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = FALSE,
    .itemVerticalPadding = 0,
    .scrollMultiple = FALSE,
    .fontId = 7
};

static const struct WindowTemplate gUnknown_085DFF5C[5] =
{
    {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 1,
        .width = 13,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 13,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x00EB
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 3,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x0153
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 13,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0139
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 9,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x015C
    }
};

static const struct WindowTemplate gUnknown_085DFF84 =
{
    .bg = 0,
    .tilemapLeft = 9,
    .tilemapTop = 7,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x0168
};

static const u8 gUnknown_085DFF8C[] = {0x01, 0x03, 0x02, 0x00};

// text
void NewGameInitPCItems(void)
{
    u8 i;

    // because Game Freak don't know how to use a struct or a 2d array
    for(i = 0, ClearItemSlots(gSaveBlock1Ptr->pcItems, ARRAY_COUNT(gSaveBlock1Ptr->pcItems)); NEW_GAME_PC_ITEMS(i, PC_ITEM_ID) && NEW_GAME_PC_ITEMS(i, PC_QUANTITY) &&
        AddPCItem(NEW_GAME_PC_ITEMS(i, PC_ITEM_ID), NEW_GAME_PC_ITEMS(i, PC_QUANTITY)) == TRUE; i++);
}

void BedroomPC(void)
{
    gPcItemMenuOptionOrder = gBedroomPC_OptionOrder;
    gPcItemMenuOptionsNum = 4;
    DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gText_WhatWouldYouLike, InitPlayerPCMenu);
}

void PlayerPC(void)
{
    gPcItemMenuOptionOrder = gPlayerPC_OptionOrder;
    gPcItemMenuOptionsNum = 3;
    DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gText_WhatWouldYouLike, InitPlayerPCMenu);
}

static void InitPlayerPCMenu(u8 taskId)
{
    u16 *data;
    struct WindowTemplate windowTemplate;

    data = gTasks[taskId].data;
    if (gPcItemMenuOptionsNum == 3)
        windowTemplate = gUnknown_085DFF24[0];
    else
        windowTemplate = gUnknown_085DFF24[1];
    windowTemplate.width = sub_81DB3D8(sPlayerPCMenuActions, gPcItemMenuOptionOrder, gPcItemMenuOptionsNum);
    data[4] = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(data[4], 0);
    sub_81995E4(data[4], gPcItemMenuOptionsNum, sPlayerPCMenuActions, gPcItemMenuOptionOrder);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[4], gPcItemMenuOptionsNum, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = PlayerPCProcessMenuInput;
}

static void PlayerPCProcessMenuInput(u8 taskId)
{
    u16 *data;
    s8 inputOptionId;

    data = gTasks[taskId].data;
    if (gPcItemMenuOptionsNum > 3)
        inputOptionId = Menu_ProcessInput();
    else
        inputOptionId = Menu_ProcessInputNoWrap();

    switch (inputOptionId)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(data[4], FALSE);
            ClearWindowTilemap(data[4]);
            RemoveWindow(data[4]);
            ScheduleBgCopyTilemapToVram(0);
            gTasks[taskId].func = PlayerPC_TurnOff;
            break;
        default:
            ClearStdWindowAndFrameToTransparent(data[4], FALSE);
            ClearWindowTilemap(data[4]);
            RemoveWindow(data[4]);
            ScheduleBgCopyTilemapToVram(0);
            gTasks[taskId].func = sPlayerPCMenuActions[gPcItemMenuOptionOrder[inputOptionId]].func.void_u8;
            break;
    }
}

void ReshowPlayerPC(u8 var)
{
    DisplayItemMessageOnField(var, gText_WhatWouldYouLike, InitPlayerPCMenu);
}

static void PlayerPC_ItemStorage(u8 taskId)
{
    InitItemStorageMenu(taskId, ITEMPC_MENU_WITHDRAW);
    gTasks[taskId].func = ItemStorageMenuProcessInput;
}

static void PlayerPC_Mailbox(u8 taskId)
{
    playerPCItemPageInfo.count = GetMailboxMailCount();

    if (playerPCItemPageInfo.count == 0)
        DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
    else
    {
        playerPCItemPageInfo.cursorPos = 0;
        playerPCItemPageInfo.itemsAbove = 0;
        playerPCItemPageInfo.scrollIndicatorId = 0xFF;
        Mailbox_UpdateMailList();
        ItemStorage_SetItemAndMailCount(taskId);
        if (sub_81D1C44(playerPCItemPageInfo.count) == TRUE)
        {
            ClearDialogWindowAndFrame(0, 0);
            Mailbox_DrawMailboxMenu(taskId);
            gTasks[taskId].func = Mailbox_ProcessInput;
        }
        else
            DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
    }
}

static void PlayerPC_Decoration(u8 taskId)
{
    DoPlayerRoomDecorationMenu(taskId);
}

static void PlayerPC_TurnOff(u8 taskId)
{
    if (gPcItemMenuOptionsNum == 4) // if the option count is 4, we are at the bedroom PC, so do gender specific handling.
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
            ScriptContext1_SetupScript(LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC);
        else
            ScriptContext1_SetupScript(LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC);
    }
    else
    {
        EnableBothScriptContexts();
    }
    DestroyTask(taskId);
}

static void InitItemStorageMenu(u8 taskId, u8 var)
{
    u16 *data;
    struct WindowTemplate windowTemplate;

    data = gTasks[taskId].data;
    windowTemplate = gUnknown_085DFF24[2];
    windowTemplate.width = GetMaxWidthInMenuTable(gPCText_ItemPCOptionsText, 4);
    data[4] = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(data[4], 0);
    PrintMenuTable(data[4], ARRAY_COUNT(gPCText_ItemPCOptionsText), gPCText_ItemPCOptionsText);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[4], 4, var);
    ScheduleBgCopyTilemapToVram(0);
    ItemStorageMenuPrint(gPCText_OptionDescList[var]);
}

static void ItemStorageMenuPrint(const u8 *textPtr)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, textPtr, 0, 1, 0, 0);
}

static void ItemStorageMenuProcessInput(u8 taskId)
{
    s8 r5;
    s8 r2;
    s8 inputOptionId;

    r5 = Menu_GetCursorPos();
    inputOptionId = Menu_ProcessInput();
    r2 = Menu_GetCursorPos();
    switch (inputOptionId)
    {
        case MENU_NOTHING_CHOSEN:
            if (r5 != r2)
                ItemStorageMenuPrint(gPCText_OptionDescList[r2]);
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            ItemStorage_Exit(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            gPCText_ItemPCOptionsText[inputOptionId].func.void_u8(taskId);
            break;
    }
}

static void ItemStorage_Deposit(u8 taskId)
{
    gTasks[taskId].func = Task_ItemStorage_Deposit;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_ItemStorage_Deposit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        CB2_GoToItemDepositMenu();
        DestroyTask(taskId);
    }
}

void sub_816B31C(void)
{
    gFieldCallback = Mailbox_DoRedrawMailboxMenuAfterReturn;
    SetMainCallback2(CB2_ReturnToField);
}

void Mailbox_DoRedrawMailboxMenuAfterReturn(void)
{
    LoadMessageBoxAndBorderGfx();
    DrawDialogueFrame(0, 1);
    InitItemStorageMenu(CreateTask(ItemStorage_HandleReturnToProcessInput, 0), 1);
    FadeInFromBlack();
}

static void ItemStorage_HandleReturnToProcessInput(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
        gTasks[taskId].func = ItemStorageMenuProcessInput;
}

static void ItemStorage_Withdraw(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    NUM_ITEMS = CountUsedPCItemSlots();
    if (NUM_ITEMS != 0)
        ItemStorage_WithdrawToss_Helper(taskId, FALSE);
    else
    {
        sub_816B4DC(taskId);
        DisplayItemMessageOnField(taskId, gText_NoItems, PlayerPC_ItemStorage);
    }

}

static void ItemStorage_Toss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    NUM_ITEMS = CountUsedPCItemSlots();
    if (NUM_ITEMS != 0)
        ItemStorage_WithdrawToss_Helper(taskId, TRUE);
    else
    {
        sub_816B4DC(taskId);
        DisplayItemMessageOnField(taskId, gText_NoItems, PlayerPC_ItemStorage);
    }
}

static void ItemStorage_WithdrawToss_Helper(u8 taskId, bool8 toss)
{
    u16 *data = gTasks[taskId].data;

    data[3] = toss;
    sub_816B4DC(taskId);
    playerPCItemPageInfo.cursorPos = 0;
    playerPCItemPageInfo.itemsAbove = 0;
    playerPCItemPageInfo.scrollIndicatorId = 0xFF;
    ItemStorage_SetItemAndMailCount(taskId);
    sub_816BC14();
    FreeAndReserveObjectSpritePalettes();
    LoadListMenuArrowsGfx();
    sub_8122344(gUnknown_0203BCC4->spriteIds, 7);
    ClearDialogWindowAndFrame(0,0);
    gTasks[taskId].func = ItemStorage_ProcessWithdrawTossInput;
}

static void ItemStorage_Exit(u8 taskId)
{
    sub_816B4DC(taskId);
    ReshowPlayerPC(taskId);
}


static void ItemStorage_SetItemAndMailCount(u8 taskId)
{
    if (playerPCItemPageInfo.count > 7)
        playerPCItemPageInfo.pageItems = 8;
    else
        playerPCItemPageInfo.pageItems = playerPCItemPageInfo.count + 1;
}

static void sub_816B4DC(u8 taskId)
{
    u16 *data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(data[4], FALSE);
    ClearWindowTilemap(data[4]);
    RemoveWindow(data[4]);
    ScheduleBgCopyTilemapToVram(0);
}

static u8 GetMailboxMailCount(void)
{
    u8 i, j;

    for(i = 0, j = 6; j < 16; j++)
        if (gSaveBlock1Ptr->mail[j].itemId != 0)
            i++;

    return i;
}

static void Mailbox_UpdateMailList(void)
{
    struct MailStruct mailBuffer;
    u8 i, j;

    for (i=6; i<15; i++)
    {
        for (j=i+1; j<16; j++)
        {
            if (gSaveBlock1Ptr->mail[i].itemId == 0)
            {
                mailBuffer = gSaveBlock1Ptr->mail[i];
                gSaveBlock1Ptr->mail[i] = gSaveBlock1Ptr->mail[j];
                gSaveBlock1Ptr->mail[j] = mailBuffer;
            }
        }
    }
}

static void Mailbox_DrawMailboxMenu(u8 taskId)
{
    u8 windowId;

    windowId = sub_81D1C84(0);
    sub_81D1C84(1);
    AddTextPrinterParameterized(windowId, 1, gText_Mailbox, GetStringCenterAlignXOffset(1, gText_Mailbox, 0x40), 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].data[5] = sub_81D1DC0(&playerPCItemPageInfo);
    sub_81D1E90(&playerPCItemPageInfo);
}

static void Mailbox_ProcessInput(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    s32 inputOptionId;

    if (!gPaletteFade.active)
    {
        inputOptionId = ListMenu_ProcessInput(data[5]);
        ListMenuGetScrollAndRow(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));

        switch (inputOptionId)
        {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                RemoveScrollIndicatorArrowPair(playerPCItemPageInfo.scrollIndicatorId);
                Mailbox_ReturnToPlayerPC(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                sub_81D1D04(0);
                sub_81D1D04(1);
                DestroyListMenuTask(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
                ScheduleBgCopyTilemapToVram(0);
                RemoveScrollIndicatorArrowPair(playerPCItemPageInfo.scrollIndicatorId);
                gTasks[taskId].func = Mailbox_PrintWhatToDoWithPlayerMailText;
                break;
        }
    }
}

static void Mailbox_PrintWhatToDoWithPlayerMailText(u8 taskId)
{
    StringCopy(gStringVar1, gSaveBlock1Ptr->mail[playerPCItemPageInfo.itemsAbove + 6 + playerPCItemPageInfo.cursorPos].playerName);
    sub_81DB554(gStringVar1, 0);
    StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithVar1sMail);
    DisplayItemMessageOnField(taskId, gStringVar4, Mailbox_PrintMailOptions);
}

static void Mailbox_ReturnToPlayerPC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81D1D04(0);
    sub_81D1D04(1);
    DestroyListMenuTask(data[5], NULL, NULL);
    ScheduleBgCopyTilemapToVram(0);
    sub_81D1EC0();
    ReshowPlayerPC(taskId);
}

static void Mailbox_PrintMailOptions(u8 taskId)
{
    u8 r4 = sub_81D1C84(2);
    PrintMenuTable(r4, ARRAY_COUNT(gMailboxMailOptions), gMailboxMailOptions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(r4, 4, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Mailbox_MailOptionsProcessInput;
}

static void Mailbox_MailOptionsProcessInput(u8 taskId)
{
    s8 inputOptionId = ProcessMenuInput_other();

    switch(inputOptionId)
    {
        case -2:
            break;
        case -1:
            PlaySE(SE_SELECT);
            Mailbox_Cancel(taskId);
            break;

        default:
            PlaySE(SE_SELECT);
            gMailboxMailOptions[inputOptionId].func.void_u8(taskId);
            break;
    }
}

static void Mailbox_DoMailRead(u8 taskId)
{
    FadeScreen(FADE_TO_BLACK, 0);
    gTasks[taskId].func = Mailbox_FadeAndReadMail;
}

static void Mailbox_FadeAndReadMail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_81D1EC0();
        CleanupOverworldWindowsAndTilemaps();
        ReadMail(&(gSaveBlock1Ptr->mail[playerPCItemPageInfo.itemsAbove + 6 + playerPCItemPageInfo.cursorPos]), Mailbox_ReturnToFieldFromReadMail, TRUE);
        DestroyTask(taskId);
    }
}

static void Mailbox_ReturnToFieldFromReadMail(void)
{
    gFieldCallback = pal_fill_for_maplights_or_black;
    SetMainCallback2(CB2_ReturnToField);
}

static void pal_fill_for_maplights_or_black(void)
{
    u8 taskId;

    LoadMessageBoxAndBorderGfx();
    taskId = CreateTask(Mailbox_HandleReturnToProcessInput, 0);
    if (sub_81D1C44(playerPCItemPageInfo.count) == TRUE)
        Mailbox_DrawMailboxMenu(taskId);
    else
        DestroyTask(taskId);
    FadeInFromBlack();
}

static void Mailbox_HandleReturnToProcessInput(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
        gTasks[taskId].func = Mailbox_ProcessInput;
}

static void Mailbox_MoveToBag(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_MessageWillBeLost, Mailbox_DrawYesNoBeforeMove);
}

static void Mailbox_DrawYesNoBeforeMove(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    gTasks[taskId].func = Mailbox_MoveToBagYesNoPrompt;
}

static void Mailbox_MoveToBagYesNoPrompt(u8 taskId)
{
    switch(Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            Mailbox_DoMailMoveToBag(taskId);
            break;
        case -1:
            PlaySE(SE_SELECT);
        case 1:
            Mailbox_CancelMoveToBag(taskId);
            break;
        case -2:
        default:
            break;
    }
}

static void Mailbox_DoMailMoveToBag(u8 taskId)
{
    struct MailStruct *mailStruct = &(gSaveBlock1Ptr->mail[playerPCItemPageInfo.itemsAbove + 6 + playerPCItemPageInfo.cursorPos]);
    if (!AddBagItem(mailStruct->itemId, 1))
    {
        DisplayItemMessageOnField(taskId, gText_BagIsFull, Mailbox_Cancel);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_MailToBagMessageErased, Mailbox_Cancel);
        ClearMailStruct(mailStruct);
        Mailbox_UpdateMailList();
        playerPCItemPageInfo.count--;
        if (playerPCItemPageInfo.count < (playerPCItemPageInfo.pageItems + playerPCItemPageInfo.itemsAbove) && playerPCItemPageInfo.itemsAbove != 0)
            playerPCItemPageInfo.itemsAbove--;
        ItemStorage_SetItemAndMailCount(taskId);
    }
}

static void Mailbox_CancelMoveToBag(u8 taskId)
{
    Mailbox_Cancel(taskId);
}

static void Mailbox_Give(u8 taskId)
{
    if (CalculatePlayerPartyCount() == 0)
        Mailbox_NoPokemonForMail(taskId);
    else
    {
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Mailbox_DoGiveMailPokeMenu;
    }
}

static void Mailbox_DoGiveMailPokeMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_81D1EC0();
        CleanupOverworldWindowsAndTilemaps();
        ChooseMonToGiveMailFromMailbox();
        DestroyTask(taskId);
    }
}

void Mailbox_ReturnToMailListAfterDeposit(void)
{
    gFieldCallback = Mailbox_UpdateMailListAfterDeposit;
    SetMainCallback2(CB2_ReturnToField);
}

static void Mailbox_UpdateMailListAfterDeposit(void)
{
    u8 taskId;
    u8 prevCount;
    taskId = CreateTask(Mailbox_HandleReturnToProcessInput, 0);
    prevCount = playerPCItemPageInfo.count;
    playerPCItemPageInfo.count = GetMailboxMailCount();
    Mailbox_UpdateMailList();
    if (prevCount != playerPCItemPageInfo.count && (playerPCItemPageInfo.count < (playerPCItemPageInfo.pageItems + playerPCItemPageInfo.itemsAbove))
       && playerPCItemPageInfo.itemsAbove != 0)
        playerPCItemPageInfo.itemsAbove--;
    ItemStorage_SetItemAndMailCount(taskId);
    LoadMessageBoxAndBorderGfx();
    if (sub_81D1C44(playerPCItemPageInfo.count) == TRUE)
        Mailbox_DrawMailboxMenu(taskId);
    else
        DestroyTask(taskId);
    FadeInFromBlack();
}

static void Mailbox_NoPokemonForMail(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_NoPokemon, Mailbox_Cancel);
}

static void Mailbox_Cancel(u8 taskId)
{
    sub_81D1D04(2);
    ClearDialogWindowAndFrame(0, 0);
    Mailbox_DrawMailboxMenu(taskId);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Mailbox_ProcessInput;
}

static void sub_816BC14(void)
{
    gUnknown_0203BCC4 = AllocZeroed(sizeof(struct Struct203BCC4));
    memset(gUnknown_0203BCC4->windowIds, 0xFF, 0x6);
    gUnknown_0203BCC4->unk666 = 0xFF;
    gUnknown_0203BCC4->spriteId = 0xFF;
}

static void sub_816BC58(void)
{
    u32 i;

    for(i = 0; i < 6; i++)
        sub_816BCC4(i);
    Free(gUnknown_0203BCC4);
}

static u8 sub_816BC7C(u8 a)
{
    u8 *windowIdLoc = &(gUnknown_0203BCC4->windowIds[a]);
    if (*windowIdLoc == 0xFF)
    {
        *windowIdLoc = AddWindow(&gUnknown_085DFF5C[a]);
        DrawStdFrameWithCustomTileAndPalette(*windowIdLoc, FALSE, 0x214, 0xE);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *windowIdLoc;
}

static void sub_816BCC4(u8 a)
{
    u8 *windowIdLoc = &(gUnknown_0203BCC4->windowIds[a]);
    if (*windowIdLoc != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*windowIdLoc, FALSE);
        ClearWindowTilemap(*windowIdLoc);
        ScheduleBgCopyTilemapToVram(0);
        RemoveWindow(*windowIdLoc);
        *windowIdLoc = 0xFF;
    }
}

void ItemStorage_RefreshListMenu(void)
{
    u16 i;

    for(i = 0; i < playerPCItemPageInfo.count - 1; i++)
    {
        CopyItemName_PlayerPC(&(gUnknown_0203BCC4->unk198[i][0]), gSaveBlock1Ptr->pcItems[i].itemId);
        gUnknown_0203BCC4->unk0[i].name = &(gUnknown_0203BCC4->unk198[i][0]);
        gUnknown_0203BCC4->unk0[i].id = i;
    }
    StringCopy(&(gUnknown_0203BCC4->unk198[i][0]) ,gText_Cancel2);
    gUnknown_0203BCC4->unk0[i].name = &(gUnknown_0203BCC4->unk198[i][0]);
    gUnknown_0203BCC4->unk0[i].id = -2;
    gMultiuseListMenuTemplate = gUnknown_085DFF44;
    gMultiuseListMenuTemplate.windowId = sub_816BC7C(0);
    gMultiuseListMenuTemplate.totalItems = playerPCItemPageInfo.count;
    gMultiuseListMenuTemplate.items = gUnknown_0203BCC4->unk0;
    gMultiuseListMenuTemplate.maxShowed = playerPCItemPageInfo.pageItems;
}

void CopyItemName_PlayerPC(u8 *string, u16 itemId)
{
    CopyItemName(itemId, string);
}

static void ItemStorage_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu)
{
    if (b != TRUE)
        PlaySE(SE_SELECT);
    if (gUnknown_0203BCC4->unk666 == 0xFF)
    {
        sub_816C0C8();
        if (id != -2)
            sub_816C060(gSaveBlock1Ptr->pcItems[id].itemId);
        else
            sub_816C060(ITEMPC_GO_BACK_TO_PREV);
        sub_816BEF0(id);
    }
}

static void fish4_goto_x5_or_x6(u8 windowId, s32 id, u8 yOffset)
{
    if (id != -2)
    {
        if (gUnknown_0203BCC4->unk666 != 0xFF)
        {
            if (gUnknown_0203BCC4->unk666 == (u8)id)
                sub_816BFE0(yOffset, 0, 0xFF);
            else
                sub_816BFE0(yOffset, 0xFF, 0xFF);
        }
        ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->pcItems[id].quantity, STR_CONV_MODE_RIGHT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(windowId, 7, gStringVar4, GetStringRightAlignXOffset(7, gStringVar4, 104), yOffset, 0xFF, NULL);
    }
}

static void sub_816BEF0(s32 id)
{
    const u8* description;
    u8 windowId = gUnknown_0203BCC4->windowIds[1];

    if (id != -2)
        description = (u8 *)ItemId_GetDescription(gSaveBlock1Ptr->pcItems[id].itemId);
    else
        description = ItemStorage_GetItemPcResponse(ITEMPC_GO_BACK_TO_PREV);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 1, description, 0, 1, 0, NULL);
}

static void ItemStorage_StartScrollIndicator(void)
{
    if (playerPCItemPageInfo.scrollIndicatorId == 0xFF)
        playerPCItemPageInfo.scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 0xB0, 0xC, 0x94, playerPCItemPageInfo.count - playerPCItemPageInfo.pageItems, 0x13F8, 0x13F8, &(playerPCItemPageInfo.itemsAbove));
}

static void ItemStorage_RemoveScrollIndicator(void)
{
    if (playerPCItemPageInfo.scrollIndicatorId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(playerPCItemPageInfo.scrollIndicatorId);
        playerPCItemPageInfo.scrollIndicatorId = 0xFF;
    }
}

static void sub_816BFB8(u8 a, u8 b, u8 speed)
{
    sub_816BFE0(ListMenuGetYCoordForPrintingArrowCursor(a), b, speed);
}

static void sub_816BFE0(u8 y, u8 b, u8 speed)
{
    u8 windowId = gUnknown_0203BCC4->windowIds[0];
    if (b == 0xFF)
        FillWindowPixelRect(windowId, PIXEL_FILL(1), 0, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        AddTextPrinterParameterized4(windowId, 1, 0, y, 0, 0, gUnknown_085DFF8C, speed, gText_SelectorArrow2);
}

static void sub_816C060(u16 itemId)
{
    u8 spriteId;
    u8* spriteIdLoc = &(gUnknown_0203BCC4->spriteId);

    if (*spriteIdLoc == 0xFF)
    {
        FreeSpriteTilesByTag(0x13F6);
        FreeSpritePaletteByTag(0x13F6);
        spriteId = AddItemIconSprite(0x13F6, 0x13F6, itemId);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdLoc = spriteId;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 80;
        }
    }
}

static void sub_816C0C8(void)
{
    u8* spriteIdLoc = &(gUnknown_0203BCC4->spriteId);
    if (*spriteIdLoc != 0xFF)
    {
        FreeSpriteTilesByTag(0x13F6);
        FreeSpritePaletteByTag(0x13F6);
        DestroySprite(&(gSprites[*spriteIdLoc]));
        *spriteIdLoc = 0xFF;
    }
}

static void sub_816C110(void)
{
    CompactPCItems();
    sub_812220C(gSaveBlock1Ptr->pcItems, 50, &(playerPCItemPageInfo.pageItems), &(playerPCItemPageInfo.count), 0x8);
}

static void sub_816C140(void)
{
    sub_812225C(&(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos), playerPCItemPageInfo.pageItems, playerPCItemPageInfo.count);
}

static void ItemStorage_ProcessWithdrawTossInput(u8 taskId)
{
    s16 *data;
    bool32 toss;
    u32 i, x;
    const u8* text;

    data = gTasks[taskId].data;
    for(i = 0; i <=3; i++)
        sub_816BC7C(i);
    toss = data[3];
    text = gText_TossItem;
    if (!toss)
        text = gText_WithdrawItem;
    x = GetStringCenterAlignXOffset(1, text, 104);
    AddTextPrinterParameterized(gUnknown_0203BCC4->windowIds[3], 1, text, x, 1, 0, NULL);
    CopyWindowToVram(gUnknown_0203BCC4->windowIds[2], 2);
    sub_816C110();
    sub_816C140();
    ItemStorage_RefreshListMenu();
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, playerPCItemPageInfo.itemsAbove, playerPCItemPageInfo.cursorPos);
    ItemStorage_StartScrollIndicator();
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = ItemStorage_ProcessInput;
}

static const u8* ItemStorage_GetItemPcResponse(u16 itemId)
{
    const u8 *string;

    switch(itemId)
    {
        case ITEMPC_GO_BACK_TO_PREV:
            string = gText_GoBackPrevMenu;
            break;
        case ITEMPC_HOW_MANY_TO_WITHDRAW:
            string = gText_WithdrawHowManyItems;
            break;
        case ITEMPC_WITHDREW_THING:
            string = gText_WithdrawXItems;
            break;
        case ITEMPC_HOW_MANY_TO_TOSS:
            string = gText_TossHowManyVar1s;
            break;
        case ITEMPC_THREW_AWAY_ITEM:
            string = gText_ThrewAwayVar2Var1s;
            break;
        case ITEMPC_NO_MORE_ROOM:
            string = gText_NoRoomInBag;
            break;
        case ITEMPC_TOO_IMPORTANT:
            string = gText_TooImportantToToss;
            break;
        case ITEMPC_OKAY_TO_THROW_AWAY:
            string = gText_ConfirmTossItems;
            break;
        case ITEMPC_SWITCH_WHICH_ITEM:
            string = gText_MoveVar1Where;
            break;
        default:
            string = ItemId_GetDescription(itemId);
            break;
    }
    return string;
}

static void ItemStorage_PrintItemPcResponse(const u8 *string)
{
    u8 windowId = gUnknown_0203BCC4->windowIds[1];
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, string);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
}

static void ItemStorage_ProcessInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    if (JOY_NEW(SELECT_BUTTON))
    {
        ListMenuGetScrollAndRow(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
        if ((playerPCItemPageInfo.itemsAbove + playerPCItemPageInfo.cursorPos) != (playerPCItemPageInfo.count - 1))
        {
            PlaySE(SE_SELECT);
            ItemStorage_ItemSwapChoosePrompt(taskId);
        }
    }
    else
    {
        id = ListMenu_ProcessInput(data[5]);
        ListMenuGetScrollAndRow(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
        switch(id)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ItemStorage_GoBackToPlayerPCMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            ItemStorage_DoItemAction(taskId);
            break;
        }
    }
}

static void ItemStorage_GoBackToPlayerPCMenu_InitStorage(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        DrawDialogueFrame(0, 0);
        if (!data[3])
            InitItemStorageMenu(taskId, ITEMPC_MENU_WITHDRAW);
        else
            InitItemStorageMenu(taskId, ITEMPC_MENU_TOSS);
        gTasks[taskId].func = ItemStorageMenuProcessInput;
    }
}

static void ItemStorage_GoBackToPlayerPCMenu(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    sub_816C0C8();
    ItemStorage_RemoveScrollIndicator();
    DestroyListMenuTask(data[5], NULL, NULL);
    sub_81223B0(gUnknown_0203BCC4->spriteIds, 7);
    sub_816BC58();
    gTasks[taskId].func = ItemStorage_GoBackToPlayerPCMenu_InitStorage;
}

static void ItemStorage_ItemSwapChoosePrompt(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    ListMenuSetUnkIndicatorsStructField(data[5], 16, 1);
    gUnknown_0203BCC4->unk666 = (playerPCItemPageInfo.itemsAbove + playerPCItemPageInfo.cursorPos);
    sub_816BFB8(data[5], 0, 0);
    sub_816C690(gUnknown_0203BCC4->unk666);
    CopyItemName(gSaveBlock1Ptr->pcItems[gUnknown_0203BCC4->unk666].itemId, gStringVar1);
    ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_SWITCH_WHICH_ITEM));
    gTasks[taskId].func = sub_816C4FC;
}

static void sub_816C4FC(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    if (JOY_NEW(SELECT_BUTTON))
    {
        ListMenuGetScrollAndRow(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
        ItemStorage_DoItemSwap(taskId, FALSE);
        return;
    }
    id = ListMenu_ProcessInput(data[5]);
    ListMenuGetScrollAndRow(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
    sub_81223FC(gUnknown_0203BCC4->spriteIds, 7, 0);
    sub_816C690(playerPCItemPageInfo.cursorPos);
    switch(id)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (JOY_NEW(A_BUTTON))
        {
            ItemStorage_DoItemSwap(taskId, FALSE);
        }
        else
        {
            ItemStorage_DoItemSwap(taskId, TRUE);
        }
        break;
    default:
        ItemStorage_DoItemSwap(taskId, FALSE);
        break;
    }
}

static void ItemStorage_DoItemSwap(u8 taskId, bool8 a)
{
    s16 *data;
    u16 b;
    u8 c;

    data = gTasks[taskId].data;
    b = (playerPCItemPageInfo.itemsAbove + playerPCItemPageInfo.cursorPos);
    PlaySE(SE_SELECT);
    DestroyListMenuTask(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
    if (!a)
    {
        c = gUnknown_0203BCC4->unk666;
        if (c != b)
        {
            if (c != b - 1)
            {
                MoveItemSlotInList(gSaveBlock1Ptr->pcItems, c, b);
                ItemStorage_RefreshListMenu();
            }
        }
        else
            goto LABEL_SKIP_CURSOR_DECREMENT;
    }
    if (gUnknown_0203BCC4->unk666 < b)
        playerPCItemPageInfo.cursorPos--;
    LABEL_SKIP_CURSOR_DECREMENT:
    sub_81223FC(gUnknown_0203BCC4->spriteIds, 7, 1);
    gUnknown_0203BCC4->unk666 = 0xFF;
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, playerPCItemPageInfo.itemsAbove, playerPCItemPageInfo.cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = ItemStorage_ProcessInput;
}

static void sub_816C690(u8 a)
{
    sub_8122448(gUnknown_0203BCC4->spriteIds, 7, 128, ((a+1) * 16));
}

static void sub_816C6BC(u8 windowId, u16 value, u32 mode, u8 x, u8 y, u8 n)
{
    ConvertIntToDecimalStringN(gStringVar1, value, mode, n);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, GetStringCenterAlignXOffset(1, gStringVar4, 48), y, 0, NULL);
}

static void ItemStorage_DoItemAction(u8 taskId)
{
    s16 *data;
    u16 b;

    data = gTasks[taskId].data;
    b = (playerPCItemPageInfo.cursorPos + playerPCItemPageInfo.itemsAbove);
    ItemStorage_RemoveScrollIndicator();
    data[2] = 1;
    if (!data[3])
    {
        if (gSaveBlock1Ptr->pcItems[b].quantity == 1)
        {
            ItemStorage_DoItemWithdraw(taskId);
            return;
        }
        CopyItemName(gSaveBlock1Ptr->pcItems[b].itemId, gStringVar1);
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_HOW_MANY_TO_WITHDRAW));
    }
    else
    {
        if (gSaveBlock1Ptr->pcItems[b].quantity == 1)
        {
            ItemStorage_DoItemToss(taskId);
            return;
        }
        CopyItemName(gSaveBlock1Ptr->pcItems[b].itemId, gStringVar1);
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_HOW_MANY_TO_TOSS));
    }
    sub_816C6BC(sub_816BC7C(4), data[2], STR_CONV_MODE_LEADING_ZEROS, 8, 1, 3);
    gTasks[taskId].func = ItemStorage_HandleQuantityRolling;
}

static void ItemStorage_HandleQuantityRolling(u8 taskId)
{
    s16 *data;
    u16 b;

    data = gTasks[taskId].data;
    b = (playerPCItemPageInfo.cursorPos + playerPCItemPageInfo.itemsAbove);
    if (AdjustQuantityAccordingToDPadInput(&(data[2]), gSaveBlock1Ptr->pcItems[b].quantity) == TRUE)
        sub_816C6BC(sub_816BC7C(4), data[2], STR_CONV_MODE_LEADING_ZEROS, 8, 1, 3);
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            sub_816BCC4(4);
            if (!data[3])
                ItemStorage_DoItemWithdraw(taskId);
            else
                ItemStorage_DoItemToss(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sub_816BCC4(4);
            ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(gSaveBlock1Ptr->pcItems[b].itemId));
            ItemStorage_StartScrollIndicatorAndProcessInput(taskId);
        }
    }
}

static void ItemStorage_DoItemWithdraw(u8 taskId)
{
    s16 *data;
    u16 b;

    data = gTasks[taskId].data;
    b = (playerPCItemPageInfo.cursorPos + playerPCItemPageInfo.itemsAbove);
    if (AddBagItem(gSaveBlock1Ptr->pcItems[b].itemId, data[2]) == TRUE)
    {
        CopyItemName(gSaveBlock1Ptr->pcItems[b].itemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, data[2], STR_CONV_MODE_LEFT_ALIGN, 3);
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_WITHDREW_THING));
        gTasks[taskId].func = ItemStorage_HandleRemoveItem;
    }
    else
    {
        data[2] = 0;
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_NO_MORE_ROOM));
        gTasks[taskId].func = ItemStorage_WaitPressHandleResumeProcessInput;
    }
}

static void ItemStorage_DoItemToss(u8 taskId)
{
    s16 *data;
    u16 b;

    data = gTasks[taskId].data;
    b = (playerPCItemPageInfo.cursorPos + playerPCItemPageInfo.itemsAbove);
    if (!ItemId_GetImportance(gSaveBlock1Ptr->pcItems[b].itemId))
    {
        CopyItemName(gSaveBlock1Ptr->pcItems[b].itemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, data[2], STR_CONV_MODE_LEFT_ALIGN, 3);
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_OKAY_TO_THROW_AWAY));
        CreateYesNoMenuWithCallbacks(taskId, &gUnknown_085DFF84, 1, 0, 1, 0x214, 0xE, &ResumeFromWithdrawYesNoFuncList);
    }
    else
    {
        data[2] = 0;
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_TOO_IMPORTANT));
        gTasks[taskId].func = ItemStorage_WaitPressHandleResumeProcessInput;
    }
}

static void ItemStorage_ResumeInputFromYesToss(u8 taskId)
{
    ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(ITEMPC_THREW_AWAY_ITEM));
    gTasks[taskId].func = ItemStorage_HandleRemoveItem;
}

static void ItemStorage_ResumeInputFromNoToss(u8 taskId)
{
    ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(gSaveBlock1Ptr->pcItems[(playerPCItemPageInfo.itemsAbove + playerPCItemPageInfo.cursorPos)].itemId));
    ItemStorage_StartScrollIndicatorAndProcessInput(taskId);
}

static void ItemStorage_HandleRemoveItem(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        RemovePCItem((playerPCItemPageInfo.cursorPos + playerPCItemPageInfo.itemsAbove), data[2]);
        DestroyListMenuTask(data[5], &(playerPCItemPageInfo.itemsAbove), &(playerPCItemPageInfo.cursorPos));
        sub_816C110();
        sub_816C140();
        ItemStorage_RefreshListMenu();
        data[5] = ListMenuInit(&gMultiuseListMenuTemplate, playerPCItemPageInfo.itemsAbove, playerPCItemPageInfo.cursorPos);
        ItemStorage_StartScrollIndicatorAndProcessInput(taskId);
    }
}

static void ItemStorage_WaitPressHandleResumeProcessInput(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ItemStorage_PrintItemPcResponse(ItemStorage_GetItemPcResponse(gSaveBlock1Ptr->pcItems[(playerPCItemPageInfo.itemsAbove + playerPCItemPageInfo.cursorPos)].itemId));
        ItemStorage_StartScrollIndicatorAndProcessInput(taskId);
    }
}

static void ItemStorage_StartScrollIndicatorAndProcessInput(u8 taskId)
{
    ItemStorage_StartScrollIndicator();
    gTasks[taskId].func = ItemStorage_ProcessInput;
}
