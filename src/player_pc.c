#include "global.h"
#include "constants/songs.h"
#include "decoration.h"
#include "event_scripts.h"
#include "field_fadetransition.h"
#include "field_screen.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "constants/items.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "player_pc.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"


static EWRAM_DATA u8 *gPcItemMenuOptionOrder = NULL;

static EWRAM_DATA u8 gPcItemMenuOptionsNum = 0;

extern struct MailboxStruct gUnknown_0203BCB8;

#define eMailboxInfo gUnknown_0203BCB8

struct Struct203BCC4
{
    u8 filler[0x668];
    u32 unk668;
    u8 filler2[4];

};

extern struct Struct203BCC4 *gUnknown_0203BCC4;


/*static*/void InitPlayerPCMenu(u8 taskId);
/*static*/void PlayerPCProcessMenuInput(u8 taskId);
/*static*/void InitItemStorageMenu(u8 taskId, u8 var);
/*static*/ void ItemStorageMenuPrint(const u8 *);
/*static*/ void ItemStorageMenuProcessInput(u8 taskId);
/*
static void ItemStorage_ProcessInput(u8);
*/
/*static*/ void ItemStorage_SetItemAndMailCount(u8);
/*
static void ItemStorage_DoItemAction(u8);
static void ItemStorage_GoBackToPlayerPCMenu(u8);
static void ItemStorage_HandleQuantityRolling(u8);
static void ItemStorage_DoItemWithdraw(u8);
static void ItemStorage_DoItemToss(u8);
static void ItemStorage_HandleRemoveItem(u8);
static void ItemStorage_WaitPressHandleResumeProcessInput(u8);
*/
/*static*/ void ItemStorage_HandleReturnToProcessInput(u8);
/*
static void ItemStorage_HandleResumeProcessInput(u8);
static void ItemStorage_DoItemSwap(u8, bool8);
static void ItemStorage_DrawItemList(u8);
static void ItemStorage_PrintItemPcResponse(u16);
static void ItemStorage_DrawBothListAndDescription(u8);
static void ItemStorage_GoBackToItemPCMenu(u8, u8);
static void ItemStorage_LoadPalette(void);
*/
/*static*/ u8 GetMailboxMailCount(void);

/*static*/ void Mailbox_UpdateMailList(void);
/*static*/ void Mailbox_DrawMailboxMenu(u8);
/*static*/ void Mailbox_ProcessInput(u8);
/*
static void Mailbox_CloseScrollIndicators(void);
static void Mailbox_PrintWhatToDoWithPlayerMailText(u8);
static void Mailbox_TurnOff(u8);
static void Mailbox_PrintMailOptions(u8);
static void Mailbox_MailOptionsProcessInput(u8);
static void Mailbox_FadeAndReadMail(u8);
static void Mailbox_ReturnToFieldFromReadMail(void);
static void Mailbox_DrawYesNoBeforeMove(u8);
static void Mailbox_DoGiveMailPokeMenu(u8);
static void Mailbox_NoPokemonForMail(u8);
static void Mailbox_Cancel(u8);
static void Mailbox_DrawMailMenuAndDoProcessInput(u8);
*/
/*static*/ void PlayerPC_ItemStorage(u8 taskId);
/*static*/ void PlayerPC_Mailbox(u8 taskId);
/*static*/ void PlayerPC_Decoration(u8 var);
/*static*/ void PlayerPC_TurnOff(u8 taskId);
/*
static void ItemStorage_Withdraw(u8);
static void ItemStorage_Deposit(u8);
static void ItemStorage_Toss(u8);
*/
/*static*/ void ItemStorage_Exit(u8);
/*
static void ItemStorage_ResumeInputFromYesToss(u8);
static void ItemStorage_ResumeInputFromNoToss(u8);
static void Mailbox_DoMailMoveToBag(u8);
static void Mailbox_ReturnToInputAfterNo(u8);
static void Mailbox_DoMailRead(u8);
static void Mailbox_MoveToBag(u8);
static void Mailbox_Give(u8);
static void Mailbox_Cancel(u8);
*/

extern const u8 *const gPCText_OptionDescList[];
/*
static const u8 *const gPCText_OptionDescList[] =
{
    PCText_TakeOutItems,
    PCText_StoreItems,
    PCText_ThrowAwayItems,
    gMenuText_GoBackToPrev
};
*/
/*static*/ extern const struct MenuAction sPlayerPCMenuActions[];/* =
{
    { SecretBaseText_ItemStorage, PlayerPC_ItemStorage },
    { gPCText_Mailbox, PlayerPC_Mailbox },
    { SecretBaseText_Decoration, PlayerPC_Decoration },
    { SecretBaseText_TurnOff, PlayerPC_TurnOff }
};
*/
/*static*/ extern u8 gBedroomPC_OptionOrder[];/* =
{
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_DECORATION,
    PLAYERPC_MENU_TURNOFF
};
*/
/*static*/ extern u8 gPlayerPC_OptionOrder[];/* =
{
    PLAYERPC_MENU_ITEMSTORAGE,
    PLAYERPC_MENU_MAILBOX,
    PLAYERPC_MENU_TURNOFF
};
*/
extern const struct MenuAction gPCText_ItemPCOptionsText[];
/*
static const struct MenuAction2 gPCText_ItemPCOptionsText[] =
{
    { PCText_WithdrawItem, ItemStorage_Withdraw },
    { PCText_DepositItem, ItemStorage_Deposit },
    { PCText_TossItem, ItemStorage_Toss },
    { gUnknownText_Exit, ItemStorage_Exit }
};

static const struct YesNoFuncTable ResumeFromTossYesNoFuncList[] = // ResumeFromTossYesNoFuncList
{
    ItemStorage_ResumeInputFromYesToss,
    ItemStorage_ResumeInputFromNoToss
};

static const struct YesNoFuncTable ResumeFromWithdrawYesNoFuncList[] = // ResumeFromWithdrawYesNoFuncList
{
    Mailbox_DoMailMoveToBag,
    Mailbox_ReturnToInputAfterNo
};
*/
// the use of this struct is meant to be an ItemSlot struct, but NewGameInitPCItems refuses to match without a weird pointer access.
/*static*/ extern const struct ItemSlot gNewGamePCItems[];/* =
{
    { ITEM_POTION, 1 },
    { ITEM_NONE, 0 }
};

static const struct MenuAction2 gMailboxMailOptions[] =
{
    { OtherText_Read, Mailbox_DoMailRead },
    { gOtherText_MoveToBag, Mailbox_MoveToBag },
    { OtherText_Give, Mailbox_Give },
    { gOtherText_CancelNoTerminator, Mailbox_Cancel }
};

static const u8 gNonSelectedItemFormattedText[] = _("{STR_VAR_1}{CLEAR_TO 80}");
static const u8 gSelectedItemFormattedText[] = _("{COLOR RED}{STR_VAR_1}{CLEAR_TO 80}");
static const u8 gNonSelectedItemQuantityFormatText[] = _("{STR_VAR_1}");
static const u8 gSelectedItemQuantityFormatText[] = _("{COLOR RED}{STR_VAR_1}");
static const u8 gUnknown_08406330[] = _("{CLEAR_TO 32}");
*/

extern const struct WindowTemplate gUnknown_085DFF24[3];

/*
extern u8 *gUnknown_02039314;
extern struct MenuAction gUnknown_08406298[];

extern u8 gUnknown_084062B8[];
extern u8 gUnknown_084062BC[];
extern u8 gUnknown_0840632A[];
extern u8 gUnknown_08406327[];
extern u8 gUnknown_0840631E[];
extern u8 gUnknown_08406318[];

extern u8 gUnknown_030007B4;
extern u8 unk_201FE00[];

extern u8 gUnknown_08152850;
extern u8 gUnknown_08152C75;

extern u32 gUnknown_08406288[];
extern const struct MenuAction gUnknown_084062C0[];
extern const struct YesNoFuncTable gUnknown_084062E0;
*/


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

/*static*/ void InitPlayerPCMenu(u8 taskId)
{
    u16 *data;
    struct WindowTemplate windowTemplate;

    data = gTasks[taskId].data;
    if(gPcItemMenuOptionsNum == 3)
        windowTemplate = gUnknown_085DFF24[0];
    else
        windowTemplate = gUnknown_085DFF24[1];
    windowTemplate.width = sub_81DB3D8(sPlayerPCMenuActions, gPcItemMenuOptionOrder, gPcItemMenuOptionsNum);
    data[4] = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(data[4], 0);
    sub_81995E4(data[4], gPcItemMenuOptionsNum, sPlayerPCMenuActions, gPcItemMenuOptionOrder);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[4], gPcItemMenuOptionsNum, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = PlayerPCProcessMenuInput;
}

/*static*/ void PlayerPCProcessMenuInput(u8 taskId)
{
    u16 *data;
    s8 inputOptionId;

    data = gTasks[taskId].data;
    if(gPcItemMenuOptionsNum > 3)
        inputOptionId = ProcessMenuInput();
    else
        inputOptionId = ProcessMenuInputNoWrapAround();

    switch(inputOptionId)
    {
        case -2:
            break;
        case -1:
            PlaySE(SE_SELECT);
            sub_8198070(data[4], FALSE);
            ClearWindowTilemap(data[4]);
            RemoveWindow(data[4]);
            schedule_bg_copy_tilemap_to_vram(0);
            gTasks[taskId].func = PlayerPC_TurnOff;
            break;
        default:
            sub_8198070(data[4], FALSE);
            ClearWindowTilemap(data[4]);
            RemoveWindow(data[4]);
            schedule_bg_copy_tilemap_to_vram(0);
            gTasks[taskId].func = sPlayerPCMenuActions[gPcItemMenuOptionOrder[inputOptionId]].func.void_u8;
            break;
    }
}

void ReshowPlayerPC(u8 var)
{
    DisplayItemMessageOnField(var, gText_WhatWouldYouLike, InitPlayerPCMenu);
}

/*static*/ void PlayerPC_ItemStorage(u8 taskId)
{
    InitItemStorageMenu(taskId, ITEMPC_MENU_WITHDRAW);
    gTasks[taskId].func = ItemStorageMenuProcessInput;
}

bool8 sub_81D1C44(u8);

/*static*/ void PlayerPC_Mailbox(u8 taskId)
{

    eMailboxInfo.count = GetMailboxMailCount();

    if (eMailboxInfo.count == 0)
        DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
    else
    {
        eMailboxInfo.cursorPos = 0;
        eMailboxInfo.itemsAbove = 0;
        eMailboxInfo.unk6[3] = 0xFF;
        Mailbox_UpdateMailList();
        ItemStorage_SetItemAndMailCount(taskId);
        if(sub_81D1C44(eMailboxInfo.count) == TRUE)
        {
            sub_8197434(0, 0);
            Mailbox_DrawMailboxMenu(taskId);
            gTasks[taskId].func = Mailbox_ProcessInput;
        }
        else
            DisplayItemMessageOnField(taskId, gText_NoMailHere, ReshowPlayerPC);
    }
}

void sub_8126B2C(u8);

/*static*/ void PlayerPC_Decoration(u8 var)
{
    sub_8126B2C(var); //DoPlayerPCDecoration(var);
}

/*static*/ void PlayerPC_TurnOff(u8 taskId)
{
    if (gPcItemMenuOptionsNum == 4) // if the option count is 4, we are at the bedroom PC and not player PC, so do gender specific handling.
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
            ScriptContext1_SetupScript(LittlerootTown_BrendansHouse_2F_EventScript_1F863F);
        else
            ScriptContext1_SetupScript(LittlerootTown_MaysHouse_2F_EventScript_1F958F);
    }
    else
    {
        EnableBothScriptContexts();
    }
    DestroyTask(taskId);
}

void ItemStorageMenuPrint(const u8*);

void InitItemStorageMenu(u8 taskId, u8 var)
{
    u16 *data;
    struct WindowTemplate windowTemplate;

    data = gTasks[taskId].data;
    windowTemplate = gUnknown_085DFF24[2];
    windowTemplate.width = GetMaxWidthInMenuTable(gPCText_ItemPCOptionsText, 4);
    data[4] = AddWindow(&windowTemplate);
    SetStandardWindowBorderStyle(data[4], 0);
    PrintMenuTable(data[4], 4, gPCText_ItemPCOptionsText);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[4], 4, var);
    schedule_bg_copy_tilemap_to_vram(0);
    ItemStorageMenuPrint(gPCText_OptionDescList[var]);
}

/*static*/ void ItemStorageMenuPrint(const u8 *textPtr)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    PrintTextOnWindow(0, 1, textPtr, 0, 1, 0, 0);
}

/*static*/ void ItemStorageMenuProcessInput(u8 var)
{
    s8 r5;
    s8 r2;
    s8 inputOptionId;

    r5 = GetMenuCursorPos();
    inputOptionId = ProcessMenuInput();
    r2 = GetMenuCursorPos();
    switch(inputOptionId)
    {
        case -2:
            if (r5 != r2)
                ItemStorageMenuPrint(gPCText_OptionDescList[r2]);
            break;
        case -1:
            PlaySE(SE_SELECT);
            ItemStorage_Exit(var);
            break;
        default:
            PlaySE(SE_SELECT);
            gPCText_ItemPCOptionsText[inputOptionId].func.void_u8(var);
            break;
    }
}

void Task_ItemStorage_Deposit(u8 taskId);
/*static*/ void ItemStorage_Deposit(u8 taskId)
{
    gTasks[taskId].func = Task_ItemStorage_Deposit;
    FadeScreen(1, 0);
}

/*static*/ void Task_ItemStorage_Deposit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        sub_81AAC14();
        DestroyTask(taskId);
    }
}

void mapldr_080EBC0C(void);

void (*gFieldCallback)(void);
void sub_816B31C(void)
{
    gFieldCallback = mapldr_080EBC0C;
    SetMainCallback2(CB2_ReturnToField);
}

void mapldr_080EBC0C(void)
{
    sub_81973A4();
    NewMenuHelpers_DrawDialogueFrame(0, 1);
    InitItemStorageMenu(CreateTask(ItemStorage_HandleReturnToProcessInput, 0), 1);
    pal_fill_black();
}

/*static*/ void ItemStorage_HandleReturnToProcessInput(u8 taskId)
{
    if (sub_80ABDFC() == TRUE)
        gTasks[taskId].func = ItemStorageMenuProcessInput;
}

u8 sub_80D6CE4(); //count of items
void sub_816B4DC(u8 taskId);
void sub_816B430(u8 taskId, bool8 toss);
extern const u8 gText_NoItems[];

/*static*/ void ItemStorage_Withdraw(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    NUM_ITEMS = sub_80D6CE4();

    if (NUM_ITEMS != 0)
        sub_816B430(taskId, FALSE);
    else
    {
        sub_816B4DC(taskId);
        DisplayItemMessageOnField(taskId, gText_NoItems, PlayerPC_ItemStorage);
    }

}

/*static*/ void ItemStorage_Toss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    NUM_ITEMS = sub_80D6CE4();
    if (NUM_ITEMS != 0)
        sub_816B430(taskId, TRUE);
    else
    {
        sub_816B4DC(taskId);
        DisplayItemMessageOnField(taskId, gText_NoItems, PlayerPC_ItemStorage);
    }
}

void sub_816BC14(void);
void gpu_pal_allocator_reset__manage_upper_four(void);
void sub_816C158(u8 taskId);

/*static*/ void sub_816B430(u8 taskId, bool8 toss)
{
    u16 *data = gTasks[taskId].data;

    data[3] = toss;
    sub_816B4DC(taskId);
    eMailboxInfo.cursorPos = 0;
    eMailboxInfo.itemsAbove = 0;
    eMailboxInfo.unk6[3] = 0xFF;
    ItemStorage_SetItemAndMailCount(taskId);
    sub_816BC14();
    gpu_pal_allocator_reset__manage_upper_four();
    LoadListMenuArrowsGfx();
    sub_8122344(&(gUnknown_0203BCC4->unk668), 7);
    sub_8197434(0,0);
    gTasks[taskId].func = sub_816C158;
}



/*static*/ void ItemStorage_Exit(u8 taskId)
{
    sub_816B4DC(taskId);
    ReshowPlayerPC(taskId);
}


/*static*/ void ItemStorage_SetItemAndMailCount(u8 taskId)
{
    if (eMailboxInfo.count > 7)
        eMailboxInfo.pageItems = 8;
    else
        eMailboxInfo.pageItems = eMailboxInfo.count + 1;
}

/*static*/ void sub_816B4DC(u8 taskId)
{
    u16 *data = gTasks[taskId].data;

    sub_8198070(data[4], FALSE);
    ClearWindowTilemap(data[4]);
    RemoveWindow(data[4]);
    schedule_bg_copy_tilemap_to_vram(0);
}

/*static*/ u8 GetMailboxMailCount(void)
{
    u8 i, j;

    for(i = 0, j = 6; j < 16; j++)
        if(gSaveBlock1Ptr->mail[j].itemId != 0)
            i++;

    return i;
}

/*static*/ void Mailbox_UpdateMailList(void)
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

extern const u8 gText_Mailbox[];
u8 sub_81D1C84(u8);
u8 sub_81D1DC0(struct MailboxStruct *);
void sub_81D1E90(struct MailboxStruct *);


/*static*/ void Mailbox_DrawMailboxMenu(u8 taskId)
{
    u8 windowId;

    windowId = sub_81D1C84(0);
    sub_81D1C84(1);
    PrintTextOnWindow(windowId, 1, gText_Mailbox, GetStringCenterAlignXOffset(1, gText_Mailbox, 0x40), 1, 0, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].data[5] = sub_81D1DC0(&eMailboxInfo);
    sub_81D1E90(&eMailboxInfo);
}

u32 ListMenuHandleInputGetItemId(u8);
void sub_81AE860(u8, void *, void *);
void sub_81AE6C8(u8, void *, void *);
void sub_816B798(u8);
void RemoveScrollIndicatorArrowPair(u8);
void sub_81D1D04(u8);
void sub_816B730(u8);

/*static*/ void Mailbox_ProcessInput(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    s32 inputOptionId;

    if(!gPaletteFade.active)
    {
        inputOptionId = ListMenuHandleInputGetItemId(data[5]);
        sub_81AE860(data[5], &(eMailboxInfo.itemsAbove), &eMailboxInfo);

        switch(inputOptionId)
        {
            case -1:
                break;
            case -2:
                PlaySE(SE_SELECT);
                RemoveScrollIndicatorArrowPair(eMailboxInfo.unk6[3]);
                sub_816B798(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                sub_81D1D04(0);
                sub_81D1D04(1);
                sub_81AE6C8(data[5], &(eMailboxInfo.itemsAbove), &eMailboxInfo);
                schedule_bg_copy_tilemap_to_vram(0);
                RemoveScrollIndicatorArrowPair(eMailboxInfo.unk6[3]);
                gTasks[taskId].func = sub_816B730;
                break;
        }
    }
}

void sub_81DB554(u8 *, u8);
void sub_816B7DC(u8);
extern const u8 gText_WhatToDoWithVar1sMail[];

/*static*/ void sub_816B730(u8 taskId)//Mailbox_PrintWhatToDoWithPlayerMailText(u8 taskId)
{
    StringCopy(gStringVar1, gSaveBlock1Ptr->mail[eMailboxInfo.itemsAbove + 6 + eMailboxInfo.cursorPos].playerName);
    sub_81DB554(gStringVar1, 0);
    StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithVar1sMail);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_816B7DC);
}

void sub_81D1EC0(void);

/*static*/ void sub_816B798(u8 taskId)//Mailbox_ReturnToPlayerPC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81D1D04(0);
    sub_81D1D04(1);
    sub_81AE6C8(data[5], NULL, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_81D1EC0();
    ReshowPlayerPC(taskId);
}

extern const struct MenuAction gUnknown_085DFF04[];

void sub_816B82C(u8 taskId);

void sub_816B7DC(u8 taskId)
{
    u8 r4 = sub_81D1C84(2);
    PrintMenuTable(r4, 4, gUnknown_085DFF04);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(r4, 4, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = sub_816B82C;
}

void sub_816BBD4(u8 taskId);

void sub_816B82C(u8 taskId)
{
    s8 inputOptionId = ProcessMenuInput_other();

    switch(inputOptionId)
    {
        case -2:
            break;
        case -1:
            PlaySE(SE_SELECT);
            sub_816BBD4(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            gUnknown_085DFF04[inputOptionId].func.void_u8(taskId);
            break;
    }
}

void sub_816B8A4(u8 taskId);

void sub_816B878(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].func = sub_816B8A4;
}

void sub_816B900();

void sub_816B8A4(u8 taskId)
{
    if(!gPaletteFade.active)
    {
        sub_81D1EC0();
        overworld_free_bg_tilemaps();
        ReadMail(&(gSaveBlock1Ptr->mail[eMailboxInfo.itemsAbove + 6 + eMailboxInfo.cursorPos]), sub_816B900, TRUE);
        DestroyTask(taskId);
    }
}

void pal_fill_for_maplights_or_black();

void sub_816B900()
{
    gFieldCallback = pal_fill_for_maplights_or_black;
    SetMainCallback2(CB2_ReturnToField);
}

