#include "global.h"
#include "bg.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_indicators.h"
#include "money.h"
#include "new_menu_helpers.h"
#include "palette.h"
#include "rom_818CFC8.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "menu_helpers.h"
#include "window.h"

struct bagStruct {
    void *func; 
    u8 unk4;
    u8 pocket;
    u8 unk6[2];
    u16 unk8[5];
    u16 unk12[5];
    void *unk1C;
};

struct unkBagStruct {
    void* unk0;
    u8 unk4[0x800];
    u8 unk804;
    u8 filler4;
    u8 unk806[10];
    u8 unk810[10];
    u8 unk81A;
    u8 unk81B:4;
    u8 unk81B_1:2;
    u8 unk81B_3:1;
    u8 unk81B_2:1;
    u8 filler3[2];
    u8 unk81E;
    u8 unk81F;
    u8 filler5[9];
    u8 unk829[5];
    u8 unk82E[6];
    s16 unk834;
    u8 filler2[0x412];
};

struct listBuffer1 {
    struct ListMenuItem subBuffers[65];
};

struct listBuffer2 {
    s8 name[65][24];
};

extern struct bagStruct gUnknown_0203CE58;
extern struct unkBagStruct *gUnknown_0203CE54;
extern struct listBuffer1 *gUnknown_0203CE74;
extern struct listBuffer2 *gUnknown_0203CE78;
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

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)());
void CB2_Bag(void);
bool8 setup_bag_menu(void);
void bag_menu_init_bgs(void);
bool8 load_bag_menu_graphics(void);
void setup_bag_menu_textboxes(void);
void allocate_bag_item_list_buffers(void);
void load_bag_item_list_buffers(u8);
void bag_menu_print_pocket_names(u8*, u8*);
void bag_menu_copy_pocket_name_to_window(u8);
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

void ResetBagScrollPositions(void)
{
    gUnknown_0203CE58.pocket = 0;
    memset(gUnknown_0203CE58.unk8, 0, 10);
    memset(gUnknown_0203CE58.unk12, 0, 10);
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
    gUnknown_0203CE54 = AllocZeroed(sizeof(struct unkBagStruct));
    if (gUnknown_0203CE54 == 0)
        SetMainCallback2(postExitMenuMainCallback2);
    else
    {
        if (bagMenuType != 12)
            gUnknown_0203CE58.unk4 = bagMenuType;
        if (postExitMenuMainCallback2)
            gUnknown_0203CE58.func = postExitMenuMainCallback2;
        if (pocketId <= 4)
            gUnknown_0203CE58.pocket = pocketId;
        temp = gUnknown_0203CE58.unk4 - 4;
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
        taskId = sub_81AB1F0(gUnknown_0203CE58.unk4);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket], gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket]);
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
    gUnknown_0203CE74 = Alloc(sizeof(struct listBuffer1));
    gUnknown_0203CE78 = Alloc(sizeof(struct listBuffer2));
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
        StringCopy(gStringVar1, gReturnToXStringsTable[gUnknown_0203CE58.unk4]);
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
        gUnknown_0203CE54->unk81E = AddScrollIndicatorArrowPairParametrized(2, 0xAC, 12, 0x94, gUnknown_0203CE54->unk829[gUnknown_0203CE58.pocket] - gUnknown_0203CE54->unk82E[gUnknown_0203CE58.pocket], 0x6E, 0x6E, &gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket]);
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
        sub_81AE6C8(data[0], &gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket]);
        if (gUnknown_0203CE54->unk0 != 0)
            SetMainCallback2(gUnknown_0203CE54->unk0);
        else
            SetMainCallback2(gUnknown_0203CE58.func);
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
    sub_812225C(&gUnknown_0203CE58.unk12[a], &gUnknown_0203CE58.unk8[a], gUnknown_0203CE54->unk82E[a], gUnknown_0203CE54->unk829[a]);
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
        sub_8122298(&gUnknown_0203CE58.unk12[i], &gUnknown_0203CE58.unk8[i], gUnknown_0203CE54->unk82E[i], gUnknown_0203CE54->unk829[i], 8);
}

u8 sub_81ABB2C(u8 a)
{
    return gUnknown_0203CE58.unk12[a] + gUnknown_0203CE58.unk8[a];
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
    u16* ScrollPos = &gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket];
    u16* CursorPos = &gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket];
    bag_menu_RemoveBagItem_message_window(4);
    sub_81AE6C8(data[0], ScrollPos, CursorPos);
    sub_81AB9A8(gUnknown_0203CE58.pocket);
    sub_81ABA88(gUnknown_0203CE58.pocket);
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *ScrollPos, *CursorPos);
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
    u16* ScrollPos = &gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket];
    u16* CursorPos = &gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket];
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
                sub_81AE860(data[0], ScrollPos, CursorPos);
                if ((*ScrollPos + *CursorPos) != gUnknown_0203CE54->unk829[gUnknown_0203CE58.pocket] - 1)
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
            sub_81AE860(data[0], ScrollPos, CursorPos);
            switch (r4)
            {
                case -1:
                    break;
                case -2:
                    if (gUnknown_0203CE58.unk4 == 5)
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
                    gUnknown_08614054[gUnknown_0203CE58.unk4](taskId);
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
        sub_81AE6C8(data[0], &gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket]);
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
                    bag_menu_copy_pocket_name_to_window(data[12] >> 1);
                else
                    bag_menu_copy_pocket_name_to_window(8 - (data[12] >> 1));
            }
            if (data[12] == 16)
                data[13]++;
            break;
        case 1:
            ChangeBagPocketId(&gUnknown_0203CE58.pocket, data[11]);
            load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
            data[0] = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203CE58.unk12[gUnknown_0203CE58.pocket], gUnknown_0203CE58.unk8[gUnknown_0203CE58.pocket]);
            PutWindowTilemap(1);
            PutWindowTilemap(2);
            schedule_bg_copy_tilemap_to_vram(0);
            bag_menu_add_pocket_scroll_arrow_indicators_maybe();
            bag_menu_add_list_scroll_arrow_indicators_maybe();
            SwitchTaskToFollowupFunc(taskId);
    }
}
