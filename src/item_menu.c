#include "global.h"
#include "battle_frontier_2.h"
#include "bg.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "decompress.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "menu_indicators.h"
#include "money.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "rom_818CFC8.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"

struct BagStruct {
    void (*bagCallback)(void); 
    u8 location;
    u8 pocket;
    u8 unk6[2];
    u16 cursorPosition[5];
    u16 scrollPosition[5];
    u8 **pocketStringsPtr;
};

struct UnkBagStruct {
    MainCallback unk0;
    u8 unk4[0x800];
    u8 unk804;
    u8 unk805;
    u8 unk806[10];
    u8 unk810[7];
    u8 unk817;
    u8 unk818;
    u8 unk819;
    u8 unk81A;
    u8 unk81B:4;
    u8 unk81B_1:2;
    u8 unk81B_3:1;
    u8 unk81B_2:1;
    u8 filler3[2];
    u8 unk81E;
    u8 unk81F;
    u8* unk820;
    u8 unk824;
    u8 unk825;
    u8 filler[2];
    u8 unk828;
    u8 unk829[5];
    u8 unk82E[6];
    s16 unk834;
    u8 filler4[0xE];
    u8 unk844[32][32];
    u8 filler2[4];
};

struct ListBuffer1 {
    struct ListMenuItem subBuffers[65];
};

struct ListBuffer2 {
    s8 name[65][24];
};

struct TempWallyStruct {
    struct ItemSlot bagPocket_Items[30];
    struct ItemSlot bagPocket_PokeBalls[16];
    u16 cursorPosition[5];
    u16 scrollPosition[5];
    u8 filler[0x2];
    u16 pocket;
};

struct UnkStructTextFunc{
    u8* text;
    TaskFunc func;
};

extern struct BagStruct gUnknown_0203CE58;
extern struct UnkBagStruct *gUnknown_0203CE54;
extern struct ListBuffer1 *gUnknown_0203CE74;
extern struct ListBuffer2 *gUnknown_0203CE78;
extern struct TempWallyStruct *gUnknown_0203CE80;
extern u16 gUnknown_0203CE6A[];
extern u16 gUnknown_0203CE60[];
extern void sub_8086194(void);
extern void sub_80861B0(void);
extern void sub_816B31C(void);
extern void bag_menu_leave_maybe_3(void);
extern void bag_menu_leave_maybe_2(void);
extern void bag_menu_leave_maybe(void);
extern void CB2_ExitSellMenu(void);
extern void SetCB2ToReshowScreenAfterMenu2(void);
extern void sub_81C4F98(u8, void(*)(void));
extern bool8 sub_81221EC(void);
extern bool8 sub_81221AC(void);
extern void sub_81ABA6C(void);
extern void sub_81ABAC4(void);
extern void sub_81ABAE0(void);
extern u8 sub_81AB1F0(u8);
extern void sub_80D4FAC(void);
extern void RemoveBagItemIconObject(u8);
extern u8 ListMenuGetYCoordForPrintingArrowCursor(u8);
extern u8 GetMenuCursorDimensionByFont(u8, u8);
extern u8 AddScrollIndicatorArrowPair(void*, void*);
extern void sub_80D6FB4(struct BagPocket*);
extern void sub_80D6F64(struct BagPocket*);
extern u8 GetLRKeysState(void);
extern void sub_81AC23C(u8);
extern void sub_81AF15C(u8, u8, u8);
extern void sub_80D4FEC(u8);
extern void sub_80D4FC8(u8);
extern void sub_80D702C(struct ItemSlot*, s16, u16);
extern bool8 sub_8122148(u16);
extern void AddItemMenuActionTextPrinters (u8, u8, u8, u8, u8, u8, u8, struct UnkStructTextFunc*, u8*);
extern void sub_8198DBC(u8, u8, u8, u8, u8, u8, u8, struct UnkStructTextFunc*, u8*);
extern void sub_8199944(u8, u8, u8, u8, u8);
extern void sub_8199134(s8, s8);
extern void sub_80FDD10(u8);
extern bool8 AdjustQuantityAccordingToDPadInput(s16*, u16);
extern void sub_81B7F60(void);
extern bool8 itemid_80BF6D8_mail_related(u16);
extern void DoBerryTagScreen(void);
extern void sub_808B864(void);
extern void sub_808BCF4(void);
extern void FreezeMapObjects(void);
extern bool8 InMultiBattleRoom(void);
extern void (*gFieldCallback)(void);
extern void sub_819FA50(void);
extern void sub_818DEF4(void);
extern void sub_818E564(void);
extern void sub_819A2BC(u8, u8);

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)());
void CB2_Bag(void);
bool8 setup_bag_menu(void);
void bag_menu_init_bgs(void);
bool8 load_bag_menu_graphics(void);
void setup_bag_menu_textboxes(void);
void allocate_bag_item_list_buffers(void);
void load_bag_item_list_buffers(u8);
void bag_menu_print_pocket_names(u8*, u8*);
void bag_menu_copy_pocket_name_to_window(u32);
void bag_menu_draw_pocket_indicator_square(u8, u8);
void AddBagVisualObject(u8);
void bag_menu_add_pocket_scroll_arrow_indicators_maybe(void);
void bag_menu_add_list_scroll_arrow_indicators_maybe(void);
void bag_menu_prepare_tmhm_move_window(void);
bool8 IsWallysBag(void);
void Task_WallyTutorialBagMenu(u8);
void Task_BagMenu(u8);
void get_name(s8*, u16);
u16 ItemIdToBattleMoveId(u16);
void ShakeBagVisual(void);
u16 BagGetItemIdByPocketPosition(u8, u16);
void AddBagItemIconObject(u16, u8);
void bag_menu_print_description_box_text(int);
void bag_menu_print_cursor(u8, u8);
void bag_menu_print(u8, u8, u8*, u8, u8, u8, u8, u8, u8);
bool8 itemid_is_unique(u16);
u16 BagGetQuantityByPocketPosition(u8, u16);
void sub_81AB89C(void);
void task_close_bag_menu_2(u8);
u8 AddItemMessageWindow(u8);
void bag_menu_RemoveBagItem_message_window(u8);
void set_callback3_to_bag(u8);
void sub_81ABC54(u8, s16);
u8 bag_menu_add_window(u8);
u8 GetSwitchBagPocketDirection(void);
void SwitchBagPocket(u8, s16, u16);
bool8 sub_81AC2C0(void);
void bag_menu_swap_items(u8);
void SetBagVisualPocketId(u8, u8);
void RemoveBagObject(u8);
void AddSwitchPocketRotatingBallObject(s16);
void sub_81AC10C(u8);
void sub_81AC3C0(u8);
void sub_81AC498(u8);
void sub_81AC590(u8);
void PrintTMHMMoveData(u16);
void sub_81ACAF8(u8);
void sub_81ACB54(u8, u8, u8);
void Task_HandleInBattleItemMenuInput(u8);
void Task_HandleOutOfBattleItemMenuInput(u8);
bool8 sub_81ACDFC(s8);
void bag_menu_remove_window(u8);
void bag_menu_print_there_is_no_pokemon(u8);
void Task_ChooseHowManyToToss(u8);
void BagMenuConfirmToss(u8);
void bag_menu_yes_no(u8, u8, struct YesNoFuncTable*);
void Task_ActuallyToss(u8);
void ItemMenu_Cancel(u8);
void sub_81AD350(u8);
void bag_menu_print_cant_be_held_msg(u8);
void bag_menu_AddMoney_window(void);
void sub_81AD680(u8);
void sub_81AD730(u8);
void sub_81AD6E4(u8);
void bag_menu_remove_money_window(void);
void bag_menu_RemoveBagItem_message_window(u8);
void sub_81AD794(u8);
void sub_81AD8C8(u8);
void sub_81AD9C0(u8);
void sub_81ADB14(u8);
void sub_81ADA7C(u8);
void sub_81ADC0C(u8);

extern u8 *gPocketNamesStringsTable[];
extern struct BgTemplate gUnknown_08613F90[];
extern u8 gBagScreen_Gfx[];
extern u8 gUnknown_08D9A88C[];
extern u16 gBagScreenFemale_Pal[];
extern u16 gBagScreenMale_Pal[];
extern struct CompressedSpriteSheet gUnknown_0857FB34;
extern struct CompressedSpriteSheet gUnknown_0857FB3C;
extern struct CompressedSpritePalette gUnknown_0857FB44;
extern u8 gText_CloseBag[];
extern struct ListMenuTemplate gUnknown_08613F9C;
extern u8 gText_ClearTo11Var1Clear5Var2[];
extern u8 gText_UnkF908Var1Clear7Var2[];
extern u8 gMoveNames[][0xD];
extern u8 gBagMenuHMIcon_Gfx[];
extern u8 gUnknown_086140A4[];
extern u8 gText_xVar1[];
extern u8* gReturnToXStringsTable[];
extern u8 gText_ReturnToVar1[];
extern u8 gText_SelectorArrow2[];
extern u32 gUnknown_08614094[];
extern u32 gUnknown_0203CE5E[];
extern u16 gSpecialVar_ItemId;
extern TaskFunc gUnknown_08614054[];
extern u8 gText_MoveVar1Where[];
extern u8 gUnknown_0861402C[];
extern u8 gUnknown_08614030[];
extern u8 gUnknown_08614034[];
extern u8 gUnknown_08614038[];
extern u8 gUnknown_0861403C[];
extern u8 gUnknown_08614042[];
extern u8 gUnknown_08614044[];
extern u8 gUnknown_08614046[];
extern u8 gUnknown_08614047[];
extern u8 gUnknown_0861404B[];
extern u8 gUnknown_0861404D[];
extern u8 gUnknown_0861404F[];
extern u8 gText_Var1IsSelected[];
extern struct UnkStructTextFunc gUnknown_08613FB4[];
extern u8 gText_TossHowManyVar1s[];
extern u8 gText_ConfirmTossItems[];
extern struct YesNoFuncTable gUnknown_08614084;
extern u8 gText_ThrewAwayVar2Var1s[];
extern u8 gText_CantWriteMail[];
extern u8 gText_NoPokemon[];
extern u8 gText_Var1CantBeHeld[];
extern u8 gText_Var1CantBeHeldHere[];
extern u8 EventScript_2736B3[];
extern u8 gText_CantBuyKeyItem[];
extern u8 gText_HowManyToSell[];
extern u8 gText_ICanPayVar1[];
extern struct YesNoFuncTable gUnknown_0861408C;
extern u8 gText_TurnedOverVar1ForVar2[];
extern u8 gText_DepositHowManyVar1[];
extern u8 gText_CantStoreImportantItems[];
extern u8 gText_DepositedVar2Var1s[];
extern u8 gText_NoRoomForItems[];
extern struct WindowTemplate gUnknown_08614174[];
extern u16 gUnknown_0860F074[];
extern struct TextColor gUnknown_08614164[];
extern struct WindowTemplate gUnknown_086141AC[];
extern struct BattleMove gBattleMoves[];
extern u8 gText_ThreeDashes[];

void ResetBagScrollPositions(void)
{
    gUnknown_0203CE58.pocket = 0;
    memset(gUnknown_0203CE58.cursorPosition, 0, 10);
    memset(gUnknown_0203CE58.scrollPosition, 0, 10);
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(0, 5, sub_8086194);
}

void sub_81AABB0(void)
{
    if (!InBattlePyramid())
        GoToBagMenu(1, 5, SetCB2ToReshowScreenAfterMenu2);
    else
        sub_81C4F98(1, SetCB2ToReshowScreenAfterMenu2);
}

void CB2_ChooseBerry(void)
{
    GoToBagMenu(4, 3, sub_80861B0);
}

void sub_81AABF0(void(*callback)(void))
{
    GoToBagMenu(5, 3, callback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(3, 5, CB2_ExitSellMenu);
}

void sub_81AAC14(void)
{
    GoToBagMenu(6, 5, sub_816B31C);
}

void sub_81AAC28(void)
{
    GoToBagMenu(9, 5, bag_menu_leave_maybe_3);
    gSpecialVar_0x8005 = 0;
    gSpecialVar_Result = 0;
}

void sub_81AAC50(void)
{
    GoToBagMenu(7, 5, bag_menu_leave_maybe_2);
    gSpecialVar_Result = 0;
}

void sub_81AAC70(void)
{
    GoToBagMenu(8, 5, bag_menu_leave_maybe);
    gSpecialVar_Result = 0;
}

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)())
{
    u8 temp;
    gUnknown_0203CE54 = AllocZeroed(sizeof(struct UnkBagStruct));
    if (gUnknown_0203CE54 == 0)
        SetMainCallback2(postExitMenuMainCallback2);
    else
    {
        if (bagMenuType != 12)
            gUnknown_0203CE58.location = bagMenuType;
        if (postExitMenuMainCallback2)
            gUnknown_0203CE58.bagCallback = postExitMenuMainCallback2;
        if (pocketId <= 4)
            gUnknown_0203CE58.pocket = pocketId;
        temp = gUnknown_0203CE58.location - 4;
        if (temp <= 1)
            gUnknown_0203CE54->unk81B = 1;
        gUnknown_0203CE54->unk0 = 0;
        gUnknown_0203CE54->unk81A = 0xFF;
        gUnknown_0203CE54->unk81E = -1;
        gUnknown_0203CE54->unk81F = -1;
        memset(&gUnknown_0203CE54->unk804, 0xFF, 12);
        memset(gUnknown_0203CE54->unk810, 0xFF, 10);
        SetMainCallback2(CB2_Bag);
    }
}

void c2_bag_3(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void vblank_cb_bag_menu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_Bag(void)
{
    while(sub_81221EC() != TRUE && setup_bag_menu() != TRUE && sub_81221AC() != TRUE) {};
}

bool8 setup_bag_menu(void)
{
    u32 index;
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        clear_scheduled_bg_copies_to_vram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (sub_81221AC() == FALSE)
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        bag_menu_init_bgs();
        gUnknown_0203CE54->unk834 = 0;
        gMain.state++;
        break;
    case 8:
        if (!load_bag_menu_graphics())
            break;
        gMain.state++;
        break;
    case 9:
        setup_bag_menu_textboxes();
        gMain.state++;
        break;
    case 10:
        sub_81ABA6C();
        sub_81ABAC4();
        sub_81ABAE0();
        gMain.state++;
        break;
    case 11:
        allocate_bag_item_list_buffers();
        gMain.state++;
        break;
    case 12:
        load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
        gMain.state++;
        break;
    case 13:
        bag_menu_print_pocket_names(gPocketNamesStringsTable[gUnknown_0203CE58.pocket], 0);
        bag_menu_copy_pocket_name_to_window(0);
        bag_menu_draw_pocket_indicator_square(gUnknown_0203CE58.pocket, 1);
        gMain.state++;
        break;
    case 14:
        taskId = sub_81AB1F0(gUnknown_0203CE58.location);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[8] = 0;
        gMain.state++;
        break;
    case 15:
        AddBagVisualObject(gUnknown_0203CE58.pocket);
        gMain.state++;
        break;
    case 16:
        sub_80D4FAC();
        gMain.state++;
        break;
    case 17:
        bag_menu_add_pocket_scroll_arrow_indicators_maybe();
        bag_menu_add_list_scroll_arrow_indicators_maybe();
        gMain.state++;
        break;
    case 18:
        bag_menu_prepare_tmhm_move_window();
        gMain.state++;
        break;
    case 19:
        BlendPalettes(-1, 16, 0);
        gMain.state++;
        break;
    case 20:
        BeginNormalPaletteFade(-1, 0, 16, 0, 0);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(vblank_cb_bag_menu);
        SetMainCallback2(c2_bag_3);
        return TRUE;
    }
    return FALSE;
}

void bag_menu_init_bgs(void)
{
    ResetVramOamAndBgCntRegs();
    memset(gUnknown_0203CE54->unk4, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08613F90, 3);
    SetBgTilemapBuffer(2, gUnknown_0203CE54->unk4);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, 0x1040);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

bool8 load_bag_menu_graphics(void)
{
    switch (gUnknown_0203CE54->unk834)
    {
        case 0:
            reset_temp_tile_data_buffers();
            decompress_and_copy_tile_data_to_vram(2, gBagScreen_Gfx, 0, 0, 0);
            gUnknown_0203CE54->unk834++;
            break;
        case 1:
            if (free_temp_tile_data_buffers_if_possible() != TRUE)
            {
                LZDecompressWram(gUnknown_08D9A88C, gUnknown_0203CE54->unk4);
                gUnknown_0203CE54->unk834++;
            }
            break;
        case 2:
            if (!IsWallysBag() && gSaveBlock2Ptr->playerGender != MALE)
                LoadCompressedPalette(gBagScreenFemale_Pal, 0, 0x40);
            else
                LoadCompressedPalette(gBagScreenMale_Pal, 0, 0x40);
            gUnknown_0203CE54->unk834++;
            break;
        case 3:
            if (IsWallysBag() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
                LoadCompressedObjectPic(&gUnknown_0857FB34);
            else
                LoadCompressedObjectPic(&gUnknown_0857FB3C);
            gUnknown_0203CE54->unk834++;
            break;
        case 4:
            LoadCompressedObjectPalette(&gUnknown_0857FB44);
            gUnknown_0203CE54->unk834++;
            break;
        default:
            LoadListMenuArrowsGfx();
            gUnknown_0203CE54->unk834 = 0;
            return TRUE;
    }
    return FALSE;
}

u8 sub_81AB1F0(u8 a)
{
    u8 taskId;
    if (a == 10)
        taskId = CreateTask(Task_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu, 0);
    return taskId;
}

void allocate_bag_item_list_buffers(void)
{
    gUnknown_0203CE74 = Alloc(sizeof(struct ListBuffer1));
    gUnknown_0203CE78 = Alloc(sizeof(struct ListBuffer2));
}

void load_bag_item_list_buffers(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    struct ListMenuItem *subBuffer;
    
    if (!gUnknown_0203CE54->unk81B_2)
    {
        for (i = 0;i < gUnknown_0203CE54->unk829[pocketId] - 1; i++)
        {
            get_name(gUnknown_0203CE78->name[i], pocket->itemSlots[i].itemId);
            subBuffer = gUnknown_0203CE74->subBuffers;
            subBuffer[i].name = gUnknown_0203CE78->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(gUnknown_0203CE78->name[i], gText_CloseBag);
        subBuffer = gUnknown_0203CE74->subBuffers;
        subBuffer[i].name = gUnknown_0203CE78->name[i];
        subBuffer[i].id = -2;
    }
    else
    {
        for (i = 0;i < gUnknown_0203CE54->unk829[pocketId]; i++)
        {
            get_name(gUnknown_0203CE78->name[i], pocket->itemSlots[i].itemId);
            subBuffer = gUnknown_0203CE74->subBuffers;
            subBuffer[i].name = gUnknown_0203CE78->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = gUnknown_08613F9C;
    gMultiuseListMenuTemplate.totalItems = gUnknown_0203CE54->unk829[pocketId];
    gMultiuseListMenuTemplate.items = gUnknown_0203CE74->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gUnknown_0203CE54->unk82E[pocketId];
}

void get_name(s8 *dest, u16 itemId)
{
    switch (gUnknown_0203CE58.pocket)
    {
        case 2:
            StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
            if (itemId >= ITEM_HM01)
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, 2, 1);
                StringExpandPlaceholders(dest, gText_ClearTo11Var1Clear5Var2);
            }
            else
            {
                ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, 2, 2);
                StringExpandPlaceholders(dest, gText_UnkF908Var1Clear7Var2);
            }
            break;
        case 3:
            ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_CHERI_BERRY + 1, 2, 2);
            CopyItemName(itemId, gStringVar2);
            StringExpandPlaceholders(dest, gText_UnkF908Var1Clear7Var2);
            break;
        default:
            CopyItemName(itemId, dest);
            break;
    }
}

void bag_menu_change_item_callback(u32 a, u8 b)
{
    if (b != 1)
    {
        PlaySE(SE_SELECT);
        ShakeBagVisual();
    }
    if (gUnknown_0203CE54->unk81A == 0xFF)
    {
        RemoveBagItemIconObject(1 ^ gUnknown_0203CE54->unk81B_1);
        if (a != -2)
           AddBagItemIconObject(BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, a), gUnknown_0203CE54->unk81B_1);
        else
           AddBagItemIconObject(-1, gUnknown_0203CE54->unk81B_1);
        gUnknown_0203CE54->unk81B_1 ^= 1;
        if (!gUnknown_0203CE54->unk81B_3)
            bag_menu_print_description_box_text(a);
    }
}

void sub_81AB520(u8 rboxId, int item_index_in_pocket, u8 a)
{
    u16 itemId;
    u16 itemQuantity;
    bool8 unique;
    int offset;
    if (item_index_in_pocket != -2)
    {
        if (gUnknown_0203CE54->unk81A != 0xFF)
        {
            if (gUnknown_0203CE54->unk81A == (u8)item_index_in_pocket)
                bag_menu_print_cursor(a, 2);
            else
                bag_menu_print_cursor(a, -1);
        }
        itemId = BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, item_index_in_pocket);
        itemQuantity = BagGetQuantityByPocketPosition(gUnknown_0203CE58.pocket + 1, item_index_in_pocket);
        if ((u16)(itemId - ITEM_HM01) <= 7)
            BlitBitmapToWindow(rboxId, gBagMenuHMIcon_Gfx, 8, a - 1, 16, 16);
        if (gUnknown_0203CE58.pocket == 3)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, 1, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
            bag_menu_print(rboxId, 7, gStringVar4, offset, a, 0, 0, -1, 0);
        }
        else if (gUnknown_0203CE58.pocket != 4 && (unique = itemid_is_unique(itemId)) == FALSE)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, 1, 2);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
            bag_menu_print(rboxId, 7, gStringVar4, offset, a, unique, unique, -1, unique);
        }
        else
        {
            if (gSaveBlock1Ptr->registeredItem && gSaveBlock1Ptr->registeredItem == itemId)
                BlitBitmapToWindow(rboxId, gUnknown_086140A4, 0x60, a - 1, 0x18, 16);
        }
    }
}

void bag_menu_print_description_box_text(int a)
{
    u8* str;
    if (a != -2)
        str = (u8*)ItemId_GetDescription(BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, a));
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable[gUnknown_0203CE58.location]);
        str = gStringVar4;
        StringExpandPlaceholders(str, gText_ReturnToVar1);
    }
    FillWindowPixelBuffer(1, 0);
    bag_menu_print(1, 1, str, 3, 1, 0, 0, 0, 0);
}

void bag_menu_print_cursor_(u8 a, u8 b)
{
    bag_menu_print_cursor(ListMenuGetYCoordForPrintingArrowCursor(a), b);
}

void bag_menu_print_cursor(u8 a, u8 b)
{
    if (b == 0xFF)
        FillWindowPixelRect(0, 0, 0, a, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        bag_menu_print(0, 1, gText_SelectorArrow2, 0, a, 0, 0, 0, b);

}

void bag_menu_add_pocket_scroll_arrow_indicators_maybe(void)
{
    if (gUnknown_0203CE54->unk81E == 0xFF)
        gUnknown_0203CE54->unk81E = AddScrollIndicatorArrowPairParametrized(2, 0xAC, 12, 0x94, gUnknown_0203CE54->unk829[gUnknown_0203CE58.pocket] - gUnknown_0203CE54->unk82E[gUnknown_0203CE58.pocket], 0x6E, 0x6E, &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket]);
}

void sub_81AB824(void)
{
    if (gUnknown_0203CE54->unk81E != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gUnknown_0203CE54->unk81E);
        gUnknown_0203CE54->unk81E = 0xFF;
    }
    sub_81AB89C();
}

void bag_menu_add_list_scroll_arrow_indicators_maybe(void)
{
    if (gUnknown_0203CE54->unk81B != 1 && gUnknown_0203CE54->unk81F == 0xFF)
        gUnknown_0203CE54->unk81F = AddScrollIndicatorArrowPair(&gUnknown_08614094, &gUnknown_0203CE5E);
}

void sub_81AB89C(void)
{
    if (gUnknown_0203CE54->unk81F != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gUnknown_0203CE54->unk81F);
        gUnknown_0203CE54->unk81F = 0xFF;
    }
}

void free_bag_item_list_buffers(void)
{
    Free(gUnknown_0203CE78);
    Free(gUnknown_0203CE74);
    FreeAllWindowBuffers();
    Free(gUnknown_0203CE54);
}

void unknown_ItemMenu_Confirm(u8 taskId)
{
    BeginNormalPaletteFade(-1, 0, 0, 16, 0);
    gTasks[taskId].func = task_close_bag_menu_2;
}

void task_close_bag_menu_2(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        sub_81AE6C8(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
        if (gUnknown_0203CE54->unk0 != 0)
            SetMainCallback2(gUnknown_0203CE54->unk0);
        else
            SetMainCallback2(gUnknown_0203CE58.bagCallback);
        sub_81AB824();
        ResetSpriteData();
        FreeAllSpritePalettes();
        free_bag_item_list_buffers();
        DestroyTask(taskId);
    }
}

void sub_81AB9A8(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    switch (pocketId)
    {
        case 2:
        case 3:
            sub_80D6FB4(pocket);
            break;
        default:
            sub_80D6F64(pocket);
            break;
    }
    gUnknown_0203CE54->unk829[pocketId] = 0;
    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gUnknown_0203CE54->unk829[pocketId]++;
    if (!gUnknown_0203CE54->unk81B_2)
        gUnknown_0203CE54->unk829[pocketId]++;
    if (gUnknown_0203CE54->unk829[pocketId] > 8)
        gUnknown_0203CE54->unk82E[pocketId] = 8;
    else
        gUnknown_0203CE54->unk82E[pocketId] = gUnknown_0203CE54->unk829[pocketId];
}

void sub_81ABA6C(void)
{
    u8 i;
    for (i = 0;i < 5;i++)
        sub_81AB9A8(i);
}

void sub_81ABA88(u8 a)
{
    sub_812225C(&gUnknown_0203CE58.scrollPosition[a], &gUnknown_0203CE58.cursorPosition[a], gUnknown_0203CE54->unk82E[a], gUnknown_0203CE54->unk829[a]);
}

void sub_81ABAC4(void)
{
    u8 i;
    for (i = 0;i < 5;i++)
        sub_81ABA88(i);
}

void sub_81ABAE0(void)
{
    u8 i;
    for (i = 0;i < 5;i++)
        sub_8122298(&gUnknown_0203CE58.scrollPosition[i], &gUnknown_0203CE58.cursorPosition[i], gUnknown_0203CE54->unk82E[i], gUnknown_0203CE54->unk829[i], 8);
}

u8 sub_81ABB2C(u8 a)
{
    return gUnknown_0203CE58.scrollPosition[a] + gUnknown_0203CE58.cursorPosition[a];
}

void DisplayItemMessage(u8 taskId, u8 fontId, u8 *str, void ( *callback)(u8 taskId))
{
    s16* data = gTasks[taskId].data;
    
    data[10] = AddItemMessageWindow(4);
    FillWindowPixelBuffer(data[10], 17);
    DisplayMessageAndContinueTask(taskId, data[10], 10, 13, fontId, GetPlayerTextSpeed(), str, callback);
    schedule_bg_copy_tilemap_to_vram(1);
}

void bag_menu_inits_lists_menu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    bag_menu_RemoveBagItem_message_window(4);
    sub_81AE6C8(data[0], scrollPos, cursorPos);
    sub_81AB9A8(gUnknown_0203CE58.pocket);
    sub_81ABA88(gUnknown_0203CE58.pocket);
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    set_callback3_to_bag(taskId);
}

void sub_81ABC3C(u8 a)
{
    sub_81ABC54(bag_menu_add_window(a), 1);
}

void sub_81ABC54(u8 a, s16 b)
{
    u8 r3 = (gUnknown_0203CE58.pocket == 3) ? 3 : 2;
    ConvertIntToDecimalStringN(gStringVar1, b, 2, r3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    PrintTextOnWindow(a, 1, gStringVar4, GetStringCenterAlignXOffset(1, gStringVar4, 0x28), 2, 0, 0);
}

void sub_81ABCC0(int a, int b, int c)
{
    u8 r3 = (gUnknown_0203CE58.pocket == 3) ? 3 : 2;
    ConvertIntToDecimalStringN(gStringVar1, b, 2, r3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    PrintTextOnWindow(a, 1, gStringVar4, 0, 1, -1, 0);
    PrintMoneyAmount(a, 0x26, 1, c, 0);
}

void Task_BagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    u16 select;
    if (sub_81221EC() != TRUE && !gPaletteFade.active)
    {
        switch (GetSwitchBagPocketDirection())
        {
            case 1:
                SwitchBagPocket(taskId, -1, 0);
                return;
            case 2:
                SwitchBagPocket(taskId, 1, 0);
                return;
        }
        if ((select = (gMain.newKeys & SELECT_BUTTON)))
        {
            if (sub_81AC2C0() == 1)
            {
                sub_81AE860(data[0], scrollPos, cursorPos);
                if ((*scrollPos + *cursorPos) != gUnknown_0203CE54->unk829[gUnknown_0203CE58.pocket] - 1)
                {
                    PlaySE(SE_SELECT);
                    bag_menu_swap_items(taskId);
                }
            }
            return;
        }
        else
        {
            int r4 = ListMenuHandleInputGetItemId(data[0]);
            sub_81AE860(data[0], scrollPos, cursorPos);
            switch (r4)
            {
                case -1:
                    break;
                case -2:
                    if (gUnknown_0203CE58.location == 5)
                    {
                        PlaySE(SE_HAZURE);
                        break;
                    }
                    PlaySE(SE_SELECT);
                    gSpecialVar_ItemId = select;
                    gTasks[taskId].func = unknown_ItemMenu_Confirm;
                    break;
                default:
                    PlaySE(SE_SELECT);
                    sub_81AB824();
                    bag_menu_print_cursor_(data[0], 2);
                    data[1] = r4;
                    data[2] = BagGetQuantityByPocketPosition(gUnknown_0203CE58.pocket + 1, r4);
                    gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, r4);
                    gUnknown_08614054[gUnknown_0203CE58.location](taskId);
            }
        }
    }
}

void set_callback3_to_bag(u8 taskId)
{
    bag_menu_add_pocket_scroll_arrow_indicators_maybe();
    bag_menu_add_list_scroll_arrow_indicators_maybe();
    ClearWindowTilemap(3);
    ClearWindowTilemap(4);
    PutWindowTilemap(1);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = Task_BagMenu;
}

u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;
    if (gUnknown_0203CE54->unk81B != 0)
        return 0;
    LRKeys = GetLRKeysState();
    if ((gMain.newKeys & DPAD_LEFT) || LRKeys == 1)
    {
        PlaySE(SE_SELECT);
        return 1;
    }
    if ((gMain.newKeys & DPAD_RIGHT) || LRKeys == 2)
    {
        PlaySE(SE_SELECT);
        return 2;
    }
    return 0;
}


void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == 1 && *bagPocketId == 4)
        *bagPocketId = 0;
    else if (deltaBagPocketId == -1 && *bagPocketId == 0)
    {
        *bagPocketId = 4;
    }
    else
        *bagPocketId += deltaBagPocketId;
}

#ifdef NONMATCHING
void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, u16 a3)
{
    s16* data = gTasks[taskId].data;
    u8 pocketId;

    
    data[13] = 0;
    data[12] = 0;
    data[11] = deltaBagPocketId;
    if (a3 == 0)
    {
        ClearWindowTilemap(0);
        ClearWindowTilemap(1);
        sub_81AE6C8(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
        schedule_bg_copy_tilemap_to_vram(0);
        gSprites[gUnknown_0203CE54->unk806[gUnknown_0203CE54->unk81B_1 ^ 1]].invisible = 1;
        sub_81AB824();
    }
    pocketId = gUnknown_0203CE58.pocket;
    ChangeBagPocketId(&pocketId, deltaBagPocketId);
    if (deltaBagPocketId == 1)
    {
        bag_menu_print_pocket_names(gPocketNamesStringsTable[gUnknown_0203CE58.pocket], gPocketNamesStringsTable[pocketId]);
        bag_menu_copy_pocket_name_to_window(0);
    }
    else
    {
        bag_menu_print_pocket_names(gPocketNamesStringsTable[pocketId], gPocketNamesStringsTable[gUnknown_0203CE58.pocket]);
        bag_menu_copy_pocket_name_to_window(8);
    }
    bag_menu_draw_pocket_indicator_square(gUnknown_0203CE58.pocket, 0);
    bag_menu_draw_pocket_indicator_square(pocketId, 1);
    FillBgTilemapBufferRect_Palette0(2, 11, 14, 2, 15, 16);
    schedule_bg_copy_tilemap_to_vram(2);
    SetBagVisualPocketId(pocketId, 1);
    RemoveBagObject(1);
    AddSwitchPocketRotatingBallObject(deltaBagPocketId);
    SetTaskFuncWithFollowupFunc(taskId, sub_81AC10C, gTasks[taskId].func);
}
#else
__attribute__((naked))
void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, u16 a3)
{
    asm(".syntax unified\n\
    push {r4-r6,lr}\n\
	sub sp, 0xC\n\
	lsls r0, 24\n\
	lsrs r6, r0, 24\n\
	lsls r1, 16\n\
	lsrs r5, r1, 16\n\
	lsls r2, 16\n\
	lsls r0, r6, 2\n\
	adds r0, r6\n\
	lsls r0, 3\n\
	ldr r1, =gTasks + 0x8\n\
	adds r4, r0, r1\n\
	movs r0, 0\n\
	strh r0, [r4, 0x1A]\n\
	strh r0, [r4, 0x18]\n\
	strh r5, [r4, 0x16]\n\
	cmp r2, 0\n\
	bne _081AC026\n\
	movs r0, 0\n\
	bl ClearWindowTilemap\n\
	movs r0, 0x1\n\
	bl ClearWindowTilemap\n\
	ldrb r0, [r4]\n\
	ldr r3, =gUnknown_0203CE58\n\
	ldrb r2, [r3, 0x5]\n\
	lsls r2, 1\n\
	adds r1, r3, 0\n\
	adds r1, 0x12\n\
	adds r1, r2, r1\n\
	adds r3, 0x8\n\
	adds r2, r3\n\
	bl sub_81AE6C8\n\
	movs r0, 0\n\
	bl schedule_bg_copy_tilemap_to_vram\n\
	ldr r3, =gSprites\n\
	ldr r0, =gUnknown_0203CE54\n\
	ldr r2, [r0]\n\
	ldr r1, =0x0000081b\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	lsls r1, 26\n\
	lsrs r1, 30\n\
	movs r0, 0x1\n\
	eors r0, r1\n\
	adds r2, r0\n\
	ldr r0, =0x00000806\n\
	adds r2, r0\n\
	ldrb r1, [r2]\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r0, r3\n\
	adds r0, 0x3E\n\
	ldrb r1, [r0]\n\
	movs r2, 0x4\n\
	orrs r1, r2\n\
	strb r1, [r0]\n\
	bl sub_81AB824\n\
_081AC026:\n\
	ldr r4, =gUnknown_0203CE58\n\
	ldrb r1, [r4, 0x5]\n\
	add r0, sp, 0x8\n\
	strb r1, [r0]\n\
	lsls r1, r5, 24\n\
	asrs r1, 24\n\
	bl ChangeBagPocketId\n\
	lsls r0, r5, 16\n\
	asrs r1, r0, 16\n\
	adds r5, r0, 0\n\
	cmp r1, 0x1\n\
	bne _081AC07C\n\
	ldr r2, =gPocketNamesStringsTable\n\
	ldrb r0, [r4, 0x5]\n\
	lsls r0, 2\n\
	adds r0, r2\n\
	ldr r0, [r0]\n\
	add r1, sp, 0x8\n\
	ldrb r1, [r1]\n\
	lsls r1, 2\n\
	adds r1, r2\n\
	ldr r1, [r1]\n\
	bl bag_menu_print_pocket_names\n\
	movs r0, 0\n\
	bl bag_menu_copy_pocket_name_to_window\n\
	b _081AC09A\n\
	.pool\n\
_081AC07C:\n\
	ldr r2, =gPocketNamesStringsTable\n\
	add r0, sp, 0x8\n\
	ldrb r0, [r0]\n\
	lsls r0, 2\n\
	adds r0, r2\n\
	ldr r0, [r0]\n\
	ldrb r1, [r4, 0x5]\n\
	lsls r1, 2\n\
	adds r1, r2\n\
	ldr r1, [r1]\n\
	bl bag_menu_print_pocket_names\n\
	movs r0, 0x8\n\
	bl bag_menu_copy_pocket_name_to_window\n\
_081AC09A:\n\
	ldr r0, =gUnknown_0203CE58\n\
	ldrb r0, [r0, 0x5]\n\
	movs r1, 0\n\
	bl bag_menu_draw_pocket_indicator_square\n\
	add r0, sp, 0x8\n\
	ldrb r0, [r0]\n\
	movs r1, 0x1\n\
	bl bag_menu_draw_pocket_indicator_square\n\
	movs r0, 0xF\n\
	str r0, [sp]\n\
	movs r0, 0x10\n\
	str r0, [sp, 0x4]\n\
	movs r0, 0x2\n\
	movs r1, 0xB\n\
	movs r2, 0xE\n\
	movs r3, 0x2\n\
	bl FillBgTilemapBufferRect_Palette0\n\
	movs r0, 0x2\n\
	bl schedule_bg_copy_tilemap_to_vram\n\
	add r0, sp, 0x8\n\
	ldrb r0, [r0]\n\
	movs r1, 0x1\n\
	bl SetBagVisualPocketId\n\
	movs r0, 0x1\n\
	bl RemoveBagObject\n\
	asrs r0, r5, 16\n\
	bl AddSwitchPocketRotatingBallObject\n\
	ldr r1, =sub_81AC10C\n\
	ldr r2, =gTasks\n\
	lsls r0, r6, 2\n\
	adds r0, r6\n\
	lsls r0, 3\n\
	adds r0, r2\n\
	ldr r2, [r0]\n\
	adds r0, r6, 0\n\
	bl SetTaskFuncWithFollowupFunc\n\
	add sp, 0xC\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided\n");
}
#endif

void sub_81AC10C(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (!sub_81221AC() && !IsWallysBag())
    {
        switch (GetSwitchBagPocketDirection())
        {
            case 1:
                ChangeBagPocketId(&gUnknown_0203CE58.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, -1, 1);
                return;
            case 2:
                ChangeBagPocketId(&gUnknown_0203CE58.pocket, data[11]);
                SwitchTaskToFollowupFunc(taskId);
                SwitchBagPocket(taskId, 1, 1);
                return;
        }
    }
    switch (data[13])
    {
        case 0:
            sub_81AC23C(data[12]);
            if (!(++data[12] & 1))
            {
                if (data[11] == 1)
                    bag_menu_copy_pocket_name_to_window((u8)(data[12] >> 1));
                else
                    bag_menu_copy_pocket_name_to_window((u8)(8 - (data[12] >> 1)));
            }
            if (data[12] == 16)
                data[13]++;
            break;
        case 1:
            ChangeBagPocketId(&gUnknown_0203CE58.pocket, data[11]);
            load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
            data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            PutWindowTilemap(1);
            PutWindowTilemap(2);
            schedule_bg_copy_tilemap_to_vram(0);
            bag_menu_add_pocket_scroll_arrow_indicators_maybe();
            bag_menu_add_list_scroll_arrow_indicators_maybe();
            SwitchTaskToFollowupFunc(taskId);
    }
}

void sub_81AC23C(u8 a)
{
    FillBgTilemapBufferRect_Palette0(2, 17, 14, a + 2, 15, 1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void bag_menu_draw_pocket_indicator_square(u8 x, u8 is_current_bag)
{
    if (is_current_bag == 0)
        FillBgTilemapBufferRect_Palette0(2, 0x1017, x + 5, 3, 1, 1);
    else
        FillBgTilemapBufferRect_Palette0(2, 0x102B, x + 5, 3, 1, 1);
    schedule_bg_copy_tilemap_to_vram(2);
}

bool8 sub_81AC2C0(void)
{
    if (gUnknown_0203CE58.location <= 1)
    {
        u8 temp = gUnknown_0203CE58.pocket - 2;
        if (temp > 1)
            return TRUE;
    }
    return FALSE;
}

void bag_menu_swap_items(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    sub_81AF15C(data[0], 16, 1);
    data[1] = gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket] + gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    gUnknown_0203CE54->unk81A = data[1];
    CopyItemName(BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, data[1]), gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(1, 0);
    bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    sub_80D4FEC(data[1]);
    sub_81AB89C();
    bag_menu_print_cursor_(data[0], 2);
    gTasks[taskId].func = sub_81AC3C0;
}

void sub_81AC3C0(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    int r7;
    
    if (sub_81221EC() != TRUE)
    {
        if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_81AE860(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            sub_81AC498(taskId);
        }
        else
        {
            r7 = ListMenuHandleInputGetItemId(data[0]);
            sub_81AE860(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            sub_80D4FC8(0);
            sub_80D4FEC(gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            switch (r7)
            {
                case -1:
                    break;
                case -2:
                    PlaySE(SE_SELECT);
                    if (gMain.newKeys & A_BUTTON)
                        sub_81AC498(taskId);
                    else
                        sub_81AC590(taskId);
                    break;
                default:
                    PlaySE(SE_SELECT);
                    sub_81AC498(taskId);
            }
        }
    }
}

void sub_81AC498(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    u16 realPos = *scrollPos + *cursorPos;
    
    if (data[1] == realPos || data[1] == (realPos - 1))
        sub_81AC590(taskId);
    else
    {
        sub_80D702C(gBagPockets[gUnknown_0203CE58.pocket].itemSlots, data[1], realPos);
        gUnknown_0203CE54->unk81A = -1;
        sub_81AE6C8(data[0], scrollPos, cursorPos);
        if (data[1] < realPos)
            gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]--;
        load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        sub_80D4FC8(1);
        bag_menu_add_list_scroll_arrow_indicators_maybe();
        gTasks[taskId].func = Task_BagMenu;
    }
}

void sub_81AC590(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    
    gUnknown_0203CE54->unk81A = -1;
    sub_81AE6C8(data[0], scrollPos, cursorPos);
    if (data[1] < (*scrollPos + *cursorPos))
        gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]--;
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    sub_80D4FC8(1);
    bag_menu_add_list_scroll_arrow_indicators_maybe();
    gTasks[taskId].func = Task_BagMenu;
}

void sub_81AC644(u8 unused)
{
    switch (gUnknown_0203CE58.location - 1)
    {
        case 0:
        case 9:
            if (ItemId_GetBattleUsage(gSpecialVar_ItemId))
            {
                gUnknown_0203CE54->unk820 = gUnknown_08614042;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 4:
            gUnknown_0203CE54->unk820 = gUnknown_08614047;
            gUnknown_0203CE54->unk828 = 4;
            break;
        case 8:
            if (!itemid_is_unique(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404B;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 6:
            if (!itemid_is_unique(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404D;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 7:
            if (!itemid_is_unique(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404F;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        default:
            if (sub_81221AC() == TRUE || InUnionRoom() == TRUE)
            {
                if (gUnknown_0203CE58.pocket == 4 || !sub_8122148(gSpecialVar_ItemId))
                {
                    gUnknown_0203CE54->unk820 = gUnknown_08614046;
                    gUnknown_0203CE54->unk828 = 1;
                }
                else
                {
                    gUnknown_0203CE54->unk820 = gUnknown_08614044;
                    gUnknown_0203CE54->unk828 = 2;
                }
            }
            else
            {
                switch (gUnknown_0203CE58.pocket)
                {
                    case 0:
                        gUnknown_0203CE54->unk820 = &gUnknown_0203CE54->unk824;
                        gUnknown_0203CE54->unk828 = 4;
                        memcpy(&gUnknown_0203CE54->unk824, &gUnknown_0861402C, 4);
                        if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                            gUnknown_0203CE54->unk824 = 6;
                        break;
                    case 4:
                        gUnknown_0203CE54->unk820 = &gUnknown_0203CE54->unk824;
                        gUnknown_0203CE54->unk828 = 4;
                        memcpy(&gUnknown_0203CE54->unk824, &gUnknown_08614030, 4);
                        if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                            gUnknown_0203CE54->unk825 = 8;
                        if (gSpecialVar_ItemId == ITEM_MACH_BIKE || gSpecialVar_ItemId == ITEM_ACRO_BIKE)
                        {
                            if (TestPlayerAvatarFlags(6))
                                gUnknown_0203CE54->unk824 = 7;
                        }
                        break;
                    case 1:
                        gUnknown_0203CE54->unk820 = gUnknown_08614034;
                        gUnknown_0203CE54->unk828 = 4;
                        break;
                    case 2:
                        gUnknown_0203CE54->unk820 = gUnknown_08614038;
                        gUnknown_0203CE54->unk828 = 4;
                        break;
                    case 3:
                        gUnknown_0203CE54->unk820 = gUnknown_0861403C;
                        gUnknown_0203CE54->unk828 = 6;
                        break;
                }
            }
    }
    if (gUnknown_0203CE58.pocket == 2)
    {
        ClearWindowTilemap(1);
        PrintTMHMMoveData(gSpecialVar_ItemId);
        PutWindowTilemap(3);
        PutWindowTilemap(4);
        schedule_bg_copy_tilemap_to_vram(0);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
        FillWindowPixelBuffer(1, 0);
        bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    }
    if (gUnknown_0203CE54->unk828 == 1)
        sub_81ACAF8(bag_menu_add_window(0));
    else if (gUnknown_0203CE54->unk828 == 2)
    {
        sub_81ACAF8(bag_menu_add_window(1));
    }
    else if (gUnknown_0203CE54->unk828 == 4)
    {
        sub_81ACB54(bag_menu_add_window(2), 2, 2);
    }
    else
        sub_81ACB54(bag_menu_add_window(3), 2, 3);
}

void sub_81ACAF8(u8 a)
{
    AddItemMenuActionTextPrinters(a, 7, 8, 1, 0, 16, gUnknown_0203CE54->unk828, gUnknown_08613FB4, gUnknown_0203CE54->unk820);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(a, gUnknown_0203CE54->unk828, 0);
}

void sub_81ACB54(u8 a, u8 b, u8 c)
{
    sub_8198DBC(a, 7, 8, 1, 0x38, b, c, gUnknown_08613FB4, gUnknown_0203CE54->unk820);
    sub_8199944(a, 0x38, b, c, 0);
}

void unknown_item_menu_type(u8 taskId)
{
    sub_81AC644(taskId);
    if (gUnknown_0203CE54->unk828 <= 2)
        gTasks[taskId].func = Task_HandleInBattleItemMenuInput;
    else
        gTasks[taskId].func = Task_HandleOutOfBattleItemMenuInput;
}

void Task_HandleInBattleItemMenuInput(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 r4 = ProcessMenuInputNoWrapAround();
        switch (r4)
        {
            case -2:
                break;
            case -1:
                PlaySE(SE_SELECT);
                gUnknown_08613FB4[4].func(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gUnknown_08613FB4[gUnknown_0203CE54->unk820[r4]].func(taskId);
                break;
        }
    }
}

void Task_HandleOutOfBattleItemMenuInput(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 cursorPos = GetMenuCursorPos();
        if (gMain.newKeys & DPAD_UP)
        {
            if (cursorPos > 0 && sub_81ACDFC(cursorPos - 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, -1);
            }
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (cursorPos < (gUnknown_0203CE54->unk828 - 2) && sub_81ACDFC(cursorPos + 2))
            {
                PlaySE(SE_SELECT);
                sub_8199134(0, 1);
            }
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysState() == 1)
        {
            if ((cursorPos & 1) && sub_81ACDFC(cursorPos - 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(-1, 0);
            }
        }
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysState() == 2)
        {
            if (!(cursorPos & 1) && sub_81ACDFC(cursorPos + 1))
            {
                PlaySE(SE_SELECT);
                sub_8199134(1, 0);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_08613FB4[gUnknown_0203CE54->unk820[cursorPos]].func(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_08613FB4[4].func(taskId);
        }
    }
}

bool8 sub_81ACDFC(s8 a)
{
    if (a < 0)
        return FALSE;
    if (a > gUnknown_0203CE54->unk828)
        return FALSE;
    if (gUnknown_0203CE54->unk820[a] == 14)
        return FALSE;
    return TRUE;
}

void bag_menu_remove_some_window(void)
{
    if (gUnknown_0203CE54->unk828 == 1)
            bag_menu_remove_window(0);
    else if (gUnknown_0203CE54->unk828 == 2)
    {
            bag_menu_remove_window(1);
    }
    else if (gUnknown_0203CE54->unk828 == 4)
    {
            bag_menu_remove_window(2);
    }
    else
            bag_menu_remove_window(3);
}

void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (ItemId_GetFieldFunc(gSpecialVar_ItemId))
    {
        bag_menu_remove_some_window();
        if (CalculatePlayerPartyCount() == 0 && ItemId_GetType(gSpecialVar_ItemId) == 1)
            bag_menu_print_there_is_no_pokemon(taskId);
        else
        {
            FillWindowPixelBuffer(1, 0);
            schedule_bg_copy_tilemap_to_vram(0);
            if (gUnknown_0203CE58.pocket != 3)
                ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                sub_80FDD10(taskId);
        }
    }
}

void ItemMenu_Toss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    bag_menu_remove_some_window();
    data[8] = 1;
    if (data[2] == 1)
        BagMenuConfirmToss(taskId);
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(1, 0);
        bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        sub_81ABC3C(7);
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

void BagMenuConfirmToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], 0, 3);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(1, 0);
    bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    bag_menu_yes_no(taskId, 5, &gUnknown_08614084);
}

void BagMenuCancelToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    bag_menu_print_description_box_text(data[1]);
    bag_menu_print_cursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void Task_ChooseHowManyToToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
        sub_81ABC54(gUnknown_0203CE54->unk817, data[8]);
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_remove_window(7);
        BagMenuConfirmToss(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_remove_window(7);
        BagMenuCancelToss(taskId);
    }
}

void BagMenuActuallyToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, data[8], 0, 3);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(1, 0);
    bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    gTasks[taskId].func = Task_ActuallyToss;
}

void Task_ActuallyToss(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, data[8]);
        sub_81AE6C8(data[0], scrollPos, cursorPos);
        sub_81AB9A8(gUnknown_0203CE58.pocket);
        sub_81ABA88(gUnknown_0203CE58.pocket);
        load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
        data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        schedule_bg_copy_tilemap_to_vram(0);
        set_callback3_to_bag(taskId);
    }
}

void ItemMenu_Register(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    
    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = 0;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;
    sub_81AE6C8(data[0], scrollPos, cursorPos);
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    ItemMenu_Cancel(taskId);
}

void ItemMenu_Give(u8 taskId)
{
    bag_menu_remove_some_window();
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (!itemid_is_unique(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
            bag_menu_print_there_is_no_pokemon(taskId);
        else
        {
            gUnknown_0203CE54->unk0 = sub_81B7F60;
            unknown_ItemMenu_Confirm(taskId);
        }
    }
    else
        bag_menu_print_cant_be_held_msg(taskId);
}

void bag_menu_print_there_is_no_pokemon(u8 taskId)
{
    DisplayItemMessage(taskId, 1, gText_NoPokemon, sub_81AD350);
}

void bag_menu_print_cant_be_held_msg(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
}

void sub_81AD350(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_inits_lists_menu(taskId);
    }
}

void ItemMenu_CheckTag(u8 taskId)
{
    gUnknown_0203CE54->unk0 = DoBerryTagScreen;
    unknown_ItemMenu_Confirm(taskId);
}

void ItemMenu_Cancel(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    bag_menu_remove_some_window();
    bag_menu_print_description_box_text(data[1]);
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    bag_menu_print_cursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void ItemMenu_UseInBattle(u8 taskId)
{
    if (ItemId_GetBattleFunc(gSpecialVar_ItemId))
    {
        bag_menu_remove_some_window();
        ItemId_GetBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

void bag_menu_mail_related(void)
{
    GoToBagMenu(12, 5, NULL);
}

void item_menu_type_2(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (!sub_8122148(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
    }
    else if (gUnknown_0203CE58.pocket != 4 && !itemid_is_unique(gSpecialVar_ItemId))
    {
        unknown_ItemMenu_Confirm(taskId);
    }
    else
        bag_menu_print_cant_be_held_msg(taskId);
}

void item_menu_type_b(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (gUnknown_0203CE58.pocket != 4 && !itemid_is_unique(gSpecialVar_ItemId))
    {
        gTasks[taskId].func = unknown_ItemMenu_Confirm;
    }
    else
        bag_menu_print_cant_be_held_msg(taskId);
}

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;
    
    if (InUnionRoom() == TRUE || InBattlePyramid() || InBattlePike() || InMultiBattleRoom() == TRUE)
        return FALSE;
    else
    {
        HideMapNamePopUpWindow();
        ChangeBgY_ScreenOff(0, 0, 0);
        if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
        {
            if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
            {
                ScriptContext2_Enable();
                FreezeMapObjects();
                sub_808B864();
                sub_808BCF4();
                gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
                taskId = CreateTask(ItemId_GetFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
                gTasks[taskId].data[3] = 1;
                return TRUE;
            }
            else
                gSaveBlock1Ptr->registeredItem = ITEM_NONE;
        }
        ScriptContext1_SetupScript(EventScript_2736B3);
    }
    return TRUE;
}

void display_sell_item_ask_str(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (itemid_get_market_price(gSpecialVar_ItemId) == 0)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, 1, gStringVar4, bag_menu_inits_lists_menu);
    }
    else 
    {
        data[8] = 1;
        if (data[2] == 1)
        {
            bag_menu_AddMoney_window();
            sub_81AD680(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar2);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD730);
        }
    }
}

void sub_81AD680(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    ConvertIntToDecimalStringN(gStringVar1, (itemid_get_market_price(gSpecialVar_ItemId) / 2) * data[8], 0, 6);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD6E4);
}

void sub_81AD6E4(u8 taskId)
{
    bag_menu_yes_no(taskId, 6, &gUnknown_0861408C);
}

void sub_81AD6FC(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    bag_menu_remove_money_window();
    bag_menu_RemoveBagItem_message_window(4);
    bag_menu_print_cursor_(data[0], 0);
    set_callback3_to_bag(taskId);
}

void sub_81AD730(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u8 windowId = bag_menu_add_window(8);
    
    sub_81ABCC0(windowId, 1, (itemid_get_market_price(gSpecialVar_ItemId) / 2) * data[8]);
    bag_menu_AddMoney_window();
    gTasks[taskId].func = sub_81AD794;
}

void sub_81AD794(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
        sub_81ABCC0(gUnknown_0203CE54->unk818, data[8], (itemid_get_market_price(gSpecialVar_ItemId) / 2) * data[8]);
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_remove_window(8);
        sub_81AD680(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_print_cursor_(data[0], 0);
        bag_menu_remove_money_window();
        bag_menu_remove_window(8);
        bag_menu_RemoveBagItem_message_window(4);
        set_callback3_to_bag(taskId);
    }
}

void sub_81AD84C(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    ConvertIntToDecimalStringN(gStringVar1, (itemid_get_market_price(gSpecialVar_ItemId) / 2) * data[8], 0, 6);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD8C8);
}

void sub_81AD8C8(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    
    PlaySE(SE_REGI);
    RemoveBagItem(gSpecialVar_ItemId, data[8]);
    AddMoney(&gSaveBlock1Ptr->money, (itemid_get_market_price(gSpecialVar_ItemId) / 2) * data[8]);
    sub_81AE6C8(data[0], scrollPos, cursorPos);
    sub_81AB9A8(gUnknown_0203CE58.pocket);
    sub_81ABA88(gUnknown_0203CE58.pocket);
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    bag_menu_print_cursor_(data[0], 2);
    PrintMoneyAmountInMoneyBox(gUnknown_0203CE54->unk819, GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = sub_81AD9C0;
}

void sub_81AD9C0(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        bag_menu_remove_money_window();
        bag_menu_inits_lists_menu(taskId);
    }
}

void display_deposit_item_ask_str(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    data[8] = 1;
    if (data[2] == 1)
        sub_81ADB14(taskId);
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_DepositHowManyVar1);
        FillWindowPixelBuffer(1, 0);
        bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        sub_81ABC3C(7);
        gTasks[taskId].func = sub_81ADA7C;
    }
}

void sub_81ADA7C(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
        sub_81ABC54(gUnknown_0203CE54->unk817, data[8]);
    else if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_remove_window(7);
        sub_81ADB14(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        bag_menu_print_description_box_text(data[1]);
        bag_menu_print_cursor_(data[0], 0);
        bag_menu_remove_window(7);
        set_callback3_to_bag(taskId);
    }
}

void sub_81ADB14(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    FillWindowPixelBuffer(1, 0);
    if (itemid_is_unique(gSpecialVar_ItemId))
    {
        bag_menu_print(1, 1, gText_CantStoreImportantItems, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = sub_81ADC0C;
    }
    else if (AddPCItem(gSpecialVar_ItemId, data[8]) == TRUE)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, data[8], 0, 3);
        StringExpandPlaceholders(gStringVar4, gText_DepositedVar2Var1s);
        bag_menu_print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = Task_ActuallyToss;
    }
    else
    {
        bag_menu_print(1, 1, gText_NoRoomForItems, 3, 1, 0, 0, 0, 0);
        gTasks[taskId].func = sub_81ADC0C;
    }
}

void sub_81ADC0C(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        bag_menu_print_description_box_text(data[1]);
        bag_menu_print_cursor_(data[0], 0);
        set_callback3_to_bag(taskId);
    }
}

bool8 IsWallysBag(void)
{
    if (gUnknown_0203CE58.location == 10)
        return TRUE;
    return FALSE;
}

void PrepareBagForWallyTutorial(void)
{
    u32 i;
    
    gUnknown_0203CE80 = AllocZeroed(sizeof(struct TempWallyStruct));
    memcpy(gUnknown_0203CE80->bagPocket_Items, gSaveBlock1Ptr->bagPocket_Items, sizeof(gSaveBlock1Ptr->bagPocket_Items));
    memcpy(gUnknown_0203CE80->bagPocket_PokeBalls, gSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(gSaveBlock1Ptr->bagPocket_PokeBalls));
    gUnknown_0203CE80->pocket = gUnknown_0203CE58.pocket;
    for (i = 0; i <= 4; i++)
    {
        gUnknown_0203CE80->cursorPosition[i] = gUnknown_0203CE58.cursorPosition[i];
        gUnknown_0203CE80->scrollPosition[i] = gUnknown_0203CE58.scrollPosition[i];
    }
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_Items, 30);
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_PokeBalls, 16);
    ResetBagScrollPositions();
}

void RestoreBagAfterWallyTutorial(void)
{
    u32 i;
    
    memcpy(gSaveBlock1Ptr->bagPocket_Items, gUnknown_0203CE80->bagPocket_Items, sizeof(gUnknown_0203CE80->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bagPocket_PokeBalls, gUnknown_0203CE80->bagPocket_PokeBalls, sizeof(gUnknown_0203CE80->bagPocket_PokeBalls));
    gUnknown_0203CE58.pocket = gUnknown_0203CE80->pocket;
    for (i = 0; i <= 4; i++)
    {
        gUnknown_0203CE58.cursorPosition[i] = gUnknown_0203CE80->cursorPosition[i];
        gUnknown_0203CE58.scrollPosition[i] = gUnknown_0203CE80->scrollPosition[i];
    }
    Free(gUnknown_0203CE80);
}

void DoWallyTutorialBagMenu(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(10, 0, SetCB2ToReshowScreenAfterMenu2);
}

void Task_WallyTutorialBagMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (!gPaletteFade.active)
    {
        switch (data[8])
        {
            case 0x66:
                PlaySE(SE_SELECT);
                SwitchBagPocket(taskId, 1, 0);
                data[8]++;
                break;
            case 0xCC:
                PlaySE(SE_SELECT);
                bag_menu_print_cursor_(data[0], 2);
                gSpecialVar_ItemId = ITEM_POKE_BALL;
                sub_81AC644(taskId);
                data[8]++;
                break;
            case 0x132:
                PlaySE(SE_SELECT);
                bag_menu_remove_some_window();
                sub_81AE6C8(data[0], 0, 0);
                RestoreBagAfterWallyTutorial();
                unknown_ItemMenu_Confirm(taskId);
                break;
            default:
                data[8]++;
                break;
        }
    }
}

void unknown_ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = 1;
    bag_menu_remove_some_window();
    unknown_ItemMenu_Confirm(taskId);
}

void bag_menu_leave_maybe_3(void)
{
    gFieldCallback = sub_819FA50;
    SetMainCallback2(c2_exit_to_overworld_2_switch);
}

void unknown_ItemMenu_Give2(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = 1;
    bag_menu_remove_some_window();
    unknown_ItemMenu_Confirm(taskId);
}

void bag_menu_leave_maybe_2(void)
{
    gFieldCallback = sub_818DEF4;
    SetMainCallback2(c2_exit_to_overworld_2_switch);
}

void unknown_ItemMenu_Confirm2(u8 taskId)
{
    gSpecialVar_Result = 1;
    bag_menu_remove_some_window();
    unknown_ItemMenu_Confirm(taskId);
}

void bag_menu_leave_maybe(void)
{
    gFieldCallback = sub_818E564;
    SetMainCallback2(c2_exit_to_overworld_2_switch);
}

void bag_menu_print_pocket_names(u8 *pocketName1, u8 *pocketName2)
{
    struct WindowTemplate window = {0, 0, 0, 0, 0, 0, 0};
    u16 windowId;
    int offset;
    
    window.width = 16;
    window.height = 2;
    windowId = AddWindow(&window);
    FillWindowPixelBuffer(windowId, 0);
    offset = GetStringCenterAlignXOffset(1, pocketName1, 0x40);
    bag_menu_print(windowId, 1, pocketName1, offset, 1, 0, 0, -1, 1);
    if (pocketName2)
    {
        offset = GetStringCenterAlignXOffset(1, pocketName2, 0x40);
        bag_menu_print(windowId, 1, pocketName2, offset + 0x40, 1, 0, 0, -1, 1);
    }
    CpuCopy32((u8*)GetWindowAttribute(windowId, 7), gUnknown_0203CE54->unk844, 0x400);
    RemoveWindow(windowId);
}

// probably a fakematching

void bag_menu_copy_pocket_name_to_window(u32 a)
{
    u8 (* r4)[32][32];
    u8* windowAttribute;
    int b;
    if (a > 8)
        a = 8;
    r4 = &gUnknown_0203CE54->unk844;
    windowAttribute = (u8*)GetWindowAttribute(2, 7);
    CpuCopy32(r4[0][a], windowAttribute, 0x100);
    b = a + 16;
    CpuCopy32(r4[0][b], windowAttribute + 0x100, 0x100);
    CopyWindowToVram(2, 2);
}

void setup_bag_menu_textboxes(void)
{
    u8 i;
    
    InitWindows(gUnknown_08614174);
    DeactivateAllTextPrinters();
    sub_809882C(0, 1, -32);
    copy_textbox_border_tile_patterns_to_vram(0, 10, -48);
    sub_819A2BC(-64, 1);
    LoadPalette(&gUnknown_0860F074, 0xF0, 0x20);
    for (i = 0;i < 3; i++)
    {
        FillWindowPixelBuffer(i, 0);
        PutWindowTilemap(i);
    }
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
}

void bag_menu_print(u8 a, u8 b, u8 *str, u8 c, u8 d, u8 e, u8 f, u8 g, u8 h)
{
    AddTextPrinterParameterized2(a, b, c, d, e, f, &gUnknown_08614164[h], g, str);
}

u8 sub_81AE124(u8 a)
{
    return gUnknown_0203CE54->unk810[a];
}    

u8 bag_menu_add_window(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->unk810[a];
    if (*ptr == 0xFF)
    {
        *ptr = AddWindow(&gUnknown_086141AC[a]);
        SetWindowBorderStyle(*ptr, 0, 1, 14);
        schedule_bg_copy_tilemap_to_vram(1);
    }
    return *ptr;
}

void bag_menu_remove_window(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->unk810[a];
    if (*ptr != 0xFF)
    {
        sub_8198070(*ptr, 0);
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        schedule_bg_copy_tilemap_to_vram(1);
        *ptr = 0xFF;
    }
}

u8 AddItemMessageWindow(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->unk810[a];
    if (*ptr == 0xFF)
        *ptr = AddWindow(&gUnknown_086141AC[a]);
    return *ptr;
}

void bag_menu_RemoveBagItem_message_window(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->unk810[a];
    if (*ptr != 0xFF)
    {
        sub_8197DF8(*ptr, 0);
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        schedule_bg_copy_tilemap_to_vram(1);
        *ptr = 0xFF;
    }
}

void bag_menu_yes_no(u8 a, u8 b, struct YesNoFuncTable *funcTable)
{
    CreateYesNoMenuWithCallbacks(a, &gUnknown_086141AC[b], 1, 0, 2, 1, 14, funcTable);
}

void bag_menu_AddMoney_window(void)
{
    u8 windowId = bag_menu_add_window(9);
    PrintMoneyAmountInMoneyBoxWithBorder(windowId, 1, 14, GetMoney(&gSaveBlock1Ptr->money));
    AddMoneyLabelObject(19, 11);
}

void bag_menu_remove_money_window(void)
{
    bag_menu_remove_window(9);
    RemoveMoneyLabelObject();
}

void bag_menu_prepare_tmhm_move_window(void)
{
    FillWindowPixelBuffer(3, 0);
    blit_move_info_icon(3, 19, 0, 0);
    blit_move_info_icon(3, 20, 0, 12);
    blit_move_info_icon(3, 21, 0, 24);
    blit_move_info_icon(3, 22, 0, 36);
    CopyWindowToVram(3, 2);
}

void PrintTMHMMoveData(u16 itemId)
{
    u8 i;
    u16 moveId;
    u8* text;
    
    FillWindowPixelBuffer(4, 0);
    if (itemId == ITEM_NONE)
    {
        for (i = 0;i < 4; i++)
            bag_menu_print(4, 1, gText_ThreeDashes, 7, i * 12, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
    else
    {
        moveId = ItemIdToBattleMoveId(itemId);
        blit_move_info_icon(4, gBattleMoves[moveId].type + 1, 0, 0);
        if (gBattleMoves[moveId].power <= 1)
            text = gText_ThreeDashes;
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].power, 1, 3);
            text = gStringVar1;
        }
        bag_menu_print(4, 1, text, 7, 12, 0, 0, -1, 4);
        if (gBattleMoves[moveId].accuracy == 0)
            text = gText_ThreeDashes;
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].accuracy, 1, 3);
            text = gStringVar1;
        }
        bag_menu_print(4, 1, text, 7, 24, 0, 0, -1, 4);
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].pp, 1, 3);
        bag_menu_print(4, 1, gStringVar1, 7, 36, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
}
