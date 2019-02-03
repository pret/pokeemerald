#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "frontier_util.h"
#include "berry_tag_screen.h"
#include "bg.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu_icons.h"
#include "item_use.h"
#include "lilycove_lady.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "main.h"
#include "alloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "rom_818CFC8.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)());
void CB2_Bag(void);
bool8 setup_bag_menu(void);
void bag_menu_init_bgs(void);
bool8 load_bag_menu_graphics(void);
void setup_bag_menu_textboxes(void);
void allocate_bag_item_list_buffers(void);
void load_bag_item_list_buffers(u8);
void bag_menu_print_pocket_names(const u8*, const u8*);
void bag_menu_copy_pocket_name_to_window(u32);
void bag_menu_draw_pocket_indicator_square(u8, u8);
void bag_menu_add_pocket_scroll_arrow_indicators_maybe(void);
void bag_menu_add_list_scroll_arrow_indicators_maybe(void);
void bag_menu_prepare_tmhm_move_window(void);
bool8 IsWallysBag(void);
void Task_WallyTutorialBagMenu(u8);
void Task_BagMenu(u8);
void get_name(s8*, u16);
u16 ItemIdToBattleMoveId(u16);
u16 BagGetItemIdByPocketPosition(u8, u16);
void bag_menu_print_description_box_text(int);
void bag_menu_print_cursor(u8, u8);
void bag_menu_print(u8, u8, const u8*, u8, u8, u8, u8, u8, u8);
bool8 ItemId_GetImportance(u16);
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
void bag_menu_yes_no(u8, u8, const struct YesNoFuncTable*);
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
void bag_menu_leave_maybe_3(void);
void bag_menu_leave_maybe_2(void);
void bag_menu_leave_maybe(void);
void sub_81ABA6C(void);
static void SetPocketListPositions(void);
void sub_81ABAE0(void);
u8 sub_81AB1F0(u8);
void sub_81AC23C(u8);
void bag_menu_change_item_callback(s32 a, bool8 b, struct ListMenu*);
void sub_81AB520(u8 rboxId, int item_index_in_pocket, u8 a);
void ItemMenu_UseOutOfBattle(u8 taskId);
void ItemMenu_Toss(u8 taskId);
void ItemMenu_Register(u8 taskId);
void ItemMenu_Give(u8 taskId);
void ItemMenu_Cancel(u8 taskId);
void ItemMenu_UseInBattle(u8 taskId);
void ItemMenu_CheckTag(u8 taskId);
void unknown_ItemMenu_Confirm(u8 taskId);
void unknown_ItemMenu_Show(u8 taskId);
void unknown_ItemMenu_Give2(u8 taskId);
void unknown_ItemMenu_Confirm2(u8 taskId);
void unknown_item_menu_type(u8 taskId);
void item_menu_type_2(u8 taskId);
void display_sell_item_ask_str(u8 taskId);
void unknown_ItemMenu_Confirm(u8 taskId);
void display_deposit_item_ask_str(u8 taskId);
void item_menu_type_b(u8 taskId);
void BagMenuActuallyToss(u8 taskId);
void BagMenuCancelToss(u8 taskId);
void sub_81AD84C(u8 taskId);
void sub_81AD6FC(u8 taskId);

// .rodata

static const struct BgTemplate sBgTemplates_ItemMenu[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = bag_menu_change_item_callback,
    .itemPrintFunc = sub_81AB520,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 7,
    .cursorKind = 0
};

const struct MenuAction gUnknown_08613FB4[] = {
    {gMenuText_Use, ItemMenu_UseOutOfBattle},
    {gMenuText_Toss, ItemMenu_Toss},
    {gMenuText_Register, ItemMenu_Register},
    {gMenuText_Give, ItemMenu_Give},
    {gText_Cancel2, ItemMenu_Cancel},
    {gMenuText_Use, ItemMenu_UseInBattle},
    {gMenuText_Check, ItemMenu_UseOutOfBattle},
    {gMenuText_Walk, ItemMenu_UseOutOfBattle},
    {gMenuText_Deselect, ItemMenu_Register},
    {gMenuText_CheckTag, ItemMenu_CheckTag},
    {gMenuText_Confirm, unknown_ItemMenu_Confirm},
    {gMenuText_Show, unknown_ItemMenu_Show},
    {gMenuText_Give2, unknown_ItemMenu_Give2},
    {gMenuText_Confirm, unknown_ItemMenu_Confirm2},
    {gText_EmptyString2, NULL}
};

const u8 gUnknown_0861402C[] = {0, 3, 1, 4};
const u8 gUnknown_08614030[] = {0, 2, 14, 4};
const u8 gUnknown_08614034[] = {3, 14, 1, 4};
const u8 gUnknown_08614038[] = {0, 3, 14, 4};
const u8 gUnknown_0861403C[] = {9, 14, 0, 3, 1, 4};
const u8 gUnknown_08614042[] = {5, 4};
const u8 gUnknown_08614044[] = {3, 4};
const u8 gUnknown_08614046 = 4;
const u8 gUnknown_08614047[] = {10, 9, 14, 4};
const u8 gUnknown_0861404B[] = {11, 4};
const u8 gUnknown_0861404D[] = {12, 4};
const u8 gUnknown_0861404F[] = {13, 4};

const TaskFunc gUnknown_08614054[] = {
    unknown_item_menu_type,
    unknown_item_menu_type,
    item_menu_type_2,
    display_sell_item_ask_str,
    unknown_ItemMenu_Confirm,
    unknown_item_menu_type,
    display_deposit_item_ask_str,
    unknown_item_menu_type,
    unknown_item_menu_type,
    unknown_item_menu_type,
    NULL,
    item_menu_type_b
};

const struct YesNoFuncTable gUnknown_08614084 = {BagMenuActuallyToss, BagMenuCancelToss};

const struct YesNoFuncTable gUnknown_0861408C = {sub_81AD84C, sub_81AD6FC};

const struct ScrollArrowsTemplate gUnknown_08614094 = {SCROLL_ARROW_LEFT, 0x1C, 16, SCROLL_ARROW_RIGHT, 100, 16, -1, -1, 0x6F, 0x6F, 0};

const u8 gUnknown_086140A4[] = INCBIN_U8("graphics/interface/select_button.4bpp");

static const u8 sFontColorTable[][3] = {
// bgColor, textColor, shadowColor
    {0, 1, 3},
    {0, 1, 4},
    {0, 3, 6},
    {2, 1, 3},
    {0, 14, 10}
};

const struct WindowTemplate gUnknown_08614174[] =
{
    { // Item names
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 1,
        .baseBlock = 0x27,
    },
    { // Description
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 1,
        .baseBlock = 0x117,
    },
    { // Pocket name
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 0x1A1,
    },
    { // TM/HM info icons
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 5,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x16B,
    },
    {// TM/HM info
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 13,
        .width = 4,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x189,
    },
    { // Field message box
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1B1,
    },
    DUMMY_WIN_TEMPLATE,
};

const struct WindowTemplate gUnknown_086141AC[] =
{
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1B1,
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 17,
        .width = 5,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    {
        .bg = 1,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x245,
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x231,
    },
};

// .text

struct ListBuffer1 {
    struct ListMenuItem subBuffers[65];
};

struct ListBuffer2 {
    s8 name[65][24];
};

struct TempWallyStruct {
    struct ItemSlot bagPocket_Items[30];
    struct ItemSlot bagPocket_PokeBalls[16];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u8 filler[0x2];
    u16 pocket;
};

EWRAM_DATA struct UnkBagStruct *gUnknown_0203CE54 = 0;
EWRAM_DATA struct BagStruct gUnknown_0203CE58 = {0};
static EWRAM_DATA struct ListBuffer1 *sListBuffer1 = 0;
static EWRAM_DATA struct ListBuffer2 *sListBuffer2 = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = 0;
static EWRAM_DATA struct TempWallyStruct *gUnknown_0203CE80 = 0;

extern u8 *const gPocketNamesStringsTable[];
extern const u8 gMoveNames[][0xD];
extern u8* gReturnToXStringsTable[];
extern const u8 EventScript_2736B3[];
extern const u16 gUnknown_0860F074[];

void ResetBagScrollPositions(void)
{
    gUnknown_0203CE58.pocket = ITEMS_POCKET;
    memset(gUnknown_0203CE58.cursorPosition, 0, 10);
    memset(gUnknown_0203CE58.scrollPosition, 0, 10);
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void sub_81AABB0(void)
{
    if (!InBattlePyramid())
        GoToBagMenu(RETURN_LOCATION_BATTLE, POCKETS_COUNT, SetCB2ToReshowScreenAfterMenu2);
    else
        sub_81C4F98(1, SetCB2ToReshowScreenAfterMenu2);
}

void CB2_ChooseBerry(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_2, BERRIES_POCKET, CB2_ReturnToFieldContinueScript);
}

void sub_81AABF0(void(*callback)(void))
{
    GoToBagMenu(RETURN_LOCATION_FIELD_3, BERRIES_POCKET, callback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(RETURN_LOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void sub_81AAC14(void)
{
    GoToBagMenu(RETURN_LOCATION_PC, POCKETS_COUNT, sub_816B31C);
}

void sub_81AAC28(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_6, POCKETS_COUNT, bag_menu_leave_maybe_3);
    gSpecialVar_0x8005 = 0;
    gSpecialVar_Result = 0;
}

void sub_81AAC50(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_4, POCKETS_COUNT, bag_menu_leave_maybe_2);
    gSpecialVar_Result = 0;
}

void sub_81AAC70(void)
{
    GoToBagMenu(RETURN_LOCATION_FIELD_5, POCKETS_COUNT, bag_menu_leave_maybe);
    gSpecialVar_Result = 0;
}

void GoToBagMenu(u8 bagMenuType, u8 pocketId, void ( *postExitMenuMainCallback2)())
{
    u8 temp;
    gUnknown_0203CE54 = AllocZeroed(sizeof(struct UnkBagStruct));
    if (gUnknown_0203CE54 == 0)
    {
        SetMainCallback2(postExitMenuMainCallback2);
    }
    else
    {
        if (bagMenuType != RETURN_LOCATION_UNCHANGED)
            gUnknown_0203CE58.location = bagMenuType;
        if (postExitMenuMainCallback2)
            gUnknown_0203CE58.bagCallback = postExitMenuMainCallback2;
        if (pocketId < POCKETS_COUNT)
            gUnknown_0203CE58.pocket = pocketId;
        temp = gUnknown_0203CE58.location - (POCKETS_COUNT - 1);
        if (temp <= 1)
            gUnknown_0203CE54->unk81B = 1;
        gUnknown_0203CE54->mainCallback2 = 0;
        gUnknown_0203CE54->unk81A = 0xFF;
        gUnknown_0203CE54->unk81E = -1;
        gUnknown_0203CE54->unk81F = -1;
        memset(gUnknown_0203CE54->spriteId, 0xFF, sizeof(gUnknown_0203CE54->spriteId));
        memset(gUnknown_0203CE54->windowPointers, 0xFF, 10);
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
        SetPocketListPositions();
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
        AddBagVisualSprite(gUnknown_0203CE58.pocket);
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
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
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
    memset(gUnknown_0203CE54->tilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_ItemMenu, 3);
    SetBgTilemapBuffer(2, gUnknown_0203CE54->tilemapBuffer);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
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
                LZDecompressWram(gUnknown_08D9A88C, gUnknown_0203CE54->tilemapBuffer);
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
                LoadCompressedSpriteSheet(&gUnknown_0857FB34);
            else
                LoadCompressedSpriteSheet(&gUnknown_0857FB3C);
            gUnknown_0203CE54->unk834++;
            break;
        case 4:
            LoadCompressedSpritePalette(&gUnknown_0857FB44);
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
    sListBuffer1 = Alloc(sizeof(struct ListBuffer1));
    sListBuffer2 = Alloc(sizeof(struct ListBuffer2));
}

void load_bag_item_list_buffers(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    struct ListMenuItem *subBuffer;

    if (!gUnknown_0203CE54->hideCloseBagText)
    {
        for (i = 0; i < gUnknown_0203CE54->numItemStacks[pocketId] - 1; i++)
        {
            get_name(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(sListBuffer2->name[i], gText_CloseBag);
        subBuffer = sListBuffer1->subBuffers;
        subBuffer[i].name = sListBuffer2->name[i];
        subBuffer[i].id = -2;
    }
    else
    {
        for (i = 0; i < gUnknown_0203CE54->numItemStacks[pocketId]; i++)
        {
            get_name(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = sItemListMenu;
    gMultiuseListMenuTemplate.totalItems = gUnknown_0203CE54->numItemStacks[pocketId];
    gMultiuseListMenuTemplate.items = sListBuffer1->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gUnknown_0203CE54->numShownItems[pocketId];
}

void get_name(s8 *dest, u16 itemId)
{
    switch (gUnknown_0203CE58.pocket)
    {
        case TMHM_POCKET:
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
        case BERRIES_POCKET:
            ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_CHERI_BERRY + 1, 2, 2);
            CopyItemName(itemId, gStringVar2);
            StringExpandPlaceholders(dest, gText_UnkF908Var1Clear7Var2);
            break;
        default:
            CopyItemName(itemId, dest);
            break;
    }
}

void bag_menu_change_item_callback(s32 a, bool8 b, struct ListMenu *unused)
{
    if (b != 1)
    {
        PlaySE(SE_SELECT);
        ShakeBagVisual();
    }
    if (gUnknown_0203CE54->unk81A == 0xFF)
    {
        RemoveBagItemIconSprite(1 ^ gUnknown_0203CE54->unk81B_1);
        if (a != -2)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, a), gUnknown_0203CE54->unk81B_1);
        else
           AddBagItemIconSprite(-1, gUnknown_0203CE54->unk81B_1);
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
        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
            BlitBitmapToWindow(rboxId, gBagMenuHMIcon_Gfx, 8, a - 1, 16, 16);
        if (gUnknown_0203CE58.pocket == BERRIES_POCKET)
        {
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, 1, 3);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(7, gStringVar4, 0x77);
            bag_menu_print(rboxId, 7, gStringVar4, offset, a, 0, 0, -1, 0);
        }
        else if (gUnknown_0203CE58.pocket != KEYITEMS_POCKET && (unique = ItemId_GetImportance(itemId)) == FALSE)
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
    const u8 *str;
    if (a != -2)
    {
        str = ItemId_GetDescription(BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, a));
    }
    else
    {
        StringCopy(gStringVar1, gReturnToXStringsTable[gUnknown_0203CE58.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
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
        gUnknown_0203CE54->unk81E = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 0xAC, 12, 0x94, gUnknown_0203CE54->numItemStacks[gUnknown_0203CE58.pocket] - gUnknown_0203CE54->numShownItems[gUnknown_0203CE58.pocket], 0x6E, 0x6E, &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket]);
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
        gUnknown_0203CE54->unk81F = AddScrollIndicatorArrowPair(&gUnknown_08614094, &gUnknown_0203CE58.unk6);
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
    Free(sListBuffer2);
    Free(sListBuffer1);
    FreeAllWindowBuffers();
    Free(gUnknown_0203CE54);
}

void unknown_ItemMenu_Confirm(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = task_close_bag_menu_2;
}

void task_close_bag_menu_2(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
        if (gUnknown_0203CE54->mainCallback2 != 0)
            SetMainCallback2(gUnknown_0203CE54->mainCallback2);
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
        case TMHM_POCKET:
        case BERRIES_POCKET:
            SortBerriesOrTMHMs(pocket);
            break;
        default:
            CompactItemsInBagPocket(pocket);
            break;
    }
    gUnknown_0203CE54->numItemStacks[pocketId] = 0;
    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gUnknown_0203CE54->numItemStacks[pocketId]++;

    if (!gUnknown_0203CE54->hideCloseBagText)
        gUnknown_0203CE54->numItemStacks[pocketId]++;

    if (gUnknown_0203CE54->numItemStacks[pocketId] > 8)
        gUnknown_0203CE54->numShownItems[pocketId] = 8;
    else
        gUnknown_0203CE54->numShownItems[pocketId] = gUnknown_0203CE54->numItemStacks[pocketId];
}

void sub_81ABA6C(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        sub_81AB9A8(i);
}

void SetInitialScrollAndCursorPositions(u8 pocketId)
{
    sub_812225C(&gUnknown_0203CE58.scrollPosition[pocketId], &gUnknown_0203CE58.cursorPosition[pocketId], gUnknown_0203CE54->numShownItems[pocketId], gUnknown_0203CE54->numItemStacks[pocketId]);
}

static void SetPocketListPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        SetInitialScrollAndCursorPositions(i);
}

void sub_81ABAE0(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        sub_8122298(&gUnknown_0203CE58.scrollPosition[i], &gUnknown_0203CE58.cursorPosition[i], gUnknown_0203CE54->numShownItems[i], gUnknown_0203CE54->numItemStacks[i], 8);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gUnknown_0203CE58.scrollPosition[pocketId] + gUnknown_0203CE58.cursorPosition[pocketId];
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void ( *callback)(u8 taskId))
{
    s16* data = gTasks[taskId].data;

    data[10] = AddItemMessageWindow(4);
    FillWindowPixelBuffer(data[10], 17);
    DisplayMessageAndContinueTask(taskId, data[10], 10, 13, fontId, GetPlayerTextSpeedDelay(), str, callback);
    schedule_bg_copy_tilemap_to_vram(1);
}

void bag_menu_inits_lists_menu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16* scrollPos = &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket];
    u16* cursorPos = &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket];
    bag_menu_RemoveBagItem_message_window(4);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    sub_81AB9A8(gUnknown_0203CE58.pocket);
    SetInitialScrollAndCursorPositions(gUnknown_0203CE58.pocket);
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
    u8 r3 = (gUnknown_0203CE58.pocket == BERRIES_POCKET) ? 3 : 2;
    ConvertIntToDecimalStringN(gStringVar1, b, 2, r3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(a, 1, gStringVar4, GetStringCenterAlignXOffset(1, gStringVar4, 0x28), 2, 0, 0);
}

void sub_81ABCC0(int a, int b, int c)
{
    u8 r3 = (gUnknown_0203CE58.pocket == BERRIES_POCKET) ? 3 : 2;
    ConvertIntToDecimalStringN(gStringVar1, b, 2, r3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(a, 1, gStringVar4, 0, 1, -1, 0);
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
                ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
                if ((*scrollPos + *cursorPos) != gUnknown_0203CE54->numItemStacks[gUnknown_0203CE58.pocket] - 1)
                {
                    PlaySE(SE_SELECT);
                    bag_menu_swap_items(taskId);
                }
            }
            return;
        }
        else
        {
            int listPosition = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
            switch (listPosition)
            {
                case LIST_NOTHING_CHOSEN:
                    break;
                case LIST_B_PRESSED:
                    if (gUnknown_0203CE58.location == 5)
                    {
                        PlaySE(SE_HAZURE);
                        break;
                    }
                    PlaySE(SE_SELECT);
                    gSpecialVar_ItemId = select;
                    gTasks[taskId].func = unknown_ItemMenu_Confirm;
                    break;
                default: // A_BUTTON
                    PlaySE(SE_SELECT);
                    sub_81AB824();
                    bag_menu_print_cursor_(data[0], 2);
                    data[1] = listPosition;
                    data[2] = BagGetQuantityByPocketPosition(gUnknown_0203CE58.pocket + 1, listPosition);
                    gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gUnknown_0203CE58.pocket + 1, listPosition);
                    gUnknown_08614054[gUnknown_0203CE58.location](taskId);
                    break;
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
    if (deltaBagPocketId == 1 && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == -1 && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

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
        DestroyListMenuTask(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
        schedule_bg_copy_tilemap_to_vram(0);
        gSprites[gUnknown_0203CE54->spriteId[2 + (gUnknown_0203CE54->unk81B_1 ^ 1)]].invisible = TRUE;
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
    RemoveBagSprite(1);
    AddSwitchPocketRotatingBallSprite(deltaBagPocketId);
    SetTaskFuncWithFollowupFunc(taskId, sub_81AC10C, gTasks[taskId].func);
}

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

    ListMenuSetUnkIndicatorsStructField(data[0], 16, 1);
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
    int input;

    if (sub_81221EC() != TRUE)
    {
        if (gMain.newKeys & SELECT_BUTTON)
        {
            PlaySE(SE_SELECT);
            ListMenuGetScrollAndRow(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            sub_81AC498(taskId);
        }
        else
        {
            input = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &gUnknown_0203CE58.scrollPosition[gUnknown_0203CE58.pocket], &gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            sub_80D4FC8(0);
            sub_80D4FEC(gUnknown_0203CE58.cursorPosition[gUnknown_0203CE58.pocket]);
            switch (input)
            {
                case LIST_NOTHING_CHOSEN:
                    break;
                case LIST_B_PRESSED:
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
    u16 realPos = (*scrollPos + *cursorPos);

    if (data[1] == realPos || data[1] == (realPos - 1))
        sub_81AC590(taskId);
    else
    {
        MoveItemSlotInList(gBagPockets[gUnknown_0203CE58.pocket].itemSlots, data[1], realPos);
        gUnknown_0203CE54->unk81A = -1;
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
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
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
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
                gUnknown_0203CE54->unk820 = &gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 4:
            gUnknown_0203CE54->unk820 = gUnknown_08614047;
            gUnknown_0203CE54->unk828 = 4;
            break;
        case 8:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404B;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = &gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 6:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404D;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = &gUnknown_08614046;
                gUnknown_0203CE54->unk828 = 1;
            }
            break;
        case 7:
            if (!ItemId_GetImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
            {
                gUnknown_0203CE54->unk820 = gUnknown_0861404F;
                gUnknown_0203CE54->unk828 = 2;
            }
            else
            {
                gUnknown_0203CE54->unk820 = &gUnknown_08614046;
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
                if (gUnknown_0203CE58.pocket == KEYITEMS_POCKET || !sub_8122148(gSpecialVar_ItemId))
                {
                    gUnknown_0203CE54->unk820 = &gUnknown_08614046;
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
                    case ITEMS_POCKET:
                        gUnknown_0203CE54->unk820 = &gUnknown_0203CE54->unk824;
                        gUnknown_0203CE54->unk828 = 4;
                        memcpy(&gUnknown_0203CE54->unk824, &gUnknown_0861402C, 4);
                        if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                            gUnknown_0203CE54->unk824 = 6;
                        break;
                    case KEYITEMS_POCKET:
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
                    case BALLS_POCKET:
                        gUnknown_0203CE54->unk820 = gUnknown_08614034;
                        gUnknown_0203CE54->unk828 = 4;
                        break;
                    case TMHM_POCKET:
                        gUnknown_0203CE54->unk820 = gUnknown_08614038;
                        gUnknown_0203CE54->unk828 = 4;
                        break;
                    case BERRIES_POCKET:
                        gUnknown_0203CE54->unk820 = gUnknown_0861403C;
                        gUnknown_0203CE54->unk828 = 6;
                        break;
                }
            }
    }
    if (gUnknown_0203CE58.pocket == TMHM_POCKET)
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
        sub_81ACAF8(bag_menu_add_window(1));
    else if (gUnknown_0203CE54->unk828 == 4)
        sub_81ACB54(bag_menu_add_window(2), 2, 2);
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
        s8 r4 = Menu_ProcessInputNoWrap();
        switch (r4)
        {
            case MENU_NOTHING_CHOSEN:
                break;
            case MENU_B_PRESSED:
                PlaySE(SE_SELECT);
                gUnknown_08613FB4[4].func.void_u8(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gUnknown_08613FB4[gUnknown_0203CE54->unk820[r4]].func.void_u8(taskId);
                break;
        }
    }
}

void Task_HandleOutOfBattleItemMenuInput(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        s8 cursorPos = Menu_GetCursorPos();
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
            gUnknown_08613FB4[gUnknown_0203CE54->unk820[cursorPos]].func.void_u8(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gUnknown_08613FB4[4].func.void_u8(taskId);
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
            if (gUnknown_0203CE58.pocket != BERRIES_POCKET)
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
    {
        BagMenuConfirmToss(taskId);
    }
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
    {
        sub_81ABC54(gUnknown_0203CE54->unk817, data[8]);
    }
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
        DestroyListMenuTask(data[0], scrollPos, cursorPos);
        sub_81AB9A8(gUnknown_0203CE58.pocket);
        SetInitialScrollAndCursorPositions(gUnknown_0203CE58.pocket);
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
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    load_bag_item_list_buffers(gUnknown_0203CE58.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    ItemMenu_Cancel(taskId);
}

void ItemMenu_Give(u8 taskId)
{
    bag_menu_remove_some_window();
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!ItemId_GetImportance(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
            bag_menu_print_there_is_no_pokemon(taskId);
        else
        {
            gUnknown_0203CE54->mainCallback2 = sub_81B7F60;
            unknown_ItemMenu_Confirm(taskId);
        }
    }
    else
    {
        bag_menu_print_cant_be_held_msg(taskId);
    }
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
    gUnknown_0203CE54->mainCallback2 = DoBerryTagScreen;
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
    GoToBagMenu(RETURN_LOCATION_UNCHANGED, POCKETS_COUNT, NULL);
}

void item_menu_type_2(u8 taskId)
{
    if (!itemid_80BF6D8_mail_related(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    }
    else if (!sub_8122148(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, 1, gStringVar4, sub_81AD350);
    }
    else if (gUnknown_0203CE58.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
    {
        unknown_ItemMenu_Confirm(taskId);
    }
    else
    {
        bag_menu_print_cant_be_held_msg(taskId);
    }
}

void item_menu_type_b(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, 1, gText_CantWriteMail, sub_81AD350);
    else if (gUnknown_0203CE58.pocket != KEYITEMS_POCKET && !ItemId_GetImportance(gSpecialVar_ItemId))
        gTasks[taskId].func = unknown_ItemMenu_Confirm;
    else
        bag_menu_print_cant_be_held_msg(taskId);
}

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() == TRUE || InBattlePyramid() || InBattlePike() || InMultiBattleRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, 0);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
        {
            ScriptContext2_Enable();
            FreezeEventObjects();
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
    return TRUE;
}

void display_sell_item_ask_str(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (ItemId_GetPrice(gSpecialVar_ItemId) == 0)
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

    ConvertIntToDecimalStringN(gStringVar1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * data[8], 0, 6);
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

    sub_81ABCC0(windowId, 1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * data[8]);
    bag_menu_AddMoney_window();
    gTasks[taskId].func = sub_81AD794;
}

void sub_81AD794(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&data[8], data[2]) == TRUE)
    {
        sub_81ABCC0(gUnknown_0203CE54->unk818, data[8], (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * data[8]);
    }
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
    ConvertIntToDecimalStringN(gStringVar1, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * data[8], 0, 6);
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
    AddMoney(&gSaveBlock1Ptr->money, (ItemId_GetPrice(gSpecialVar_ItemId) / 2) * data[8]);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    sub_81AB9A8(gUnknown_0203CE58.pocket);
    SetInitialScrollAndCursorPositions(gUnknown_0203CE58.pocket);
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
    {
        sub_81ADB14(taskId);
    }
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
    {
        sub_81ABC54(gUnknown_0203CE54->unk817, data[8]);
    }
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
    if (ItemId_GetImportance(gSpecialVar_ItemId))
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
    GoToBagMenu(RETURN_LOCATION_BATTLE_2, ITEMS_POCKET, SetCB2ToReshowScreenAfterMenu2);
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
                DestroyListMenuTask(data[0], 0, 0);
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
    gFieldCallback = Apprentice_EnableBothScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
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
    SetMainCallback2(CB2_ReturnToField);
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
    SetMainCallback2(CB2_ReturnToField);
}

void bag_menu_print_pocket_names(const u8 *pocketName1, const u8 *pocketName2)
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
    CpuCopy32((u8*)GetWindowAttribute(windowId, WINDOW_TILE_DATA), gUnknown_0203CE54->pocketNameBuffer, 0x400);
    RemoveWindow(windowId);
}

void bag_menu_copy_pocket_name_to_window(u32 a)
{
    u8 (* r4)[32][32];
    u8* windowAttribute;
    int b;
    if (a > 8)
        a = 8;
    r4 = &gUnknown_0203CE54->pocketNameBuffer;
    windowAttribute = (u8*)GetWindowAttribute(2, WINDOW_TILE_DATA);
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
    LoadUserWindowBorderGfx(0, 1, 0xE0);
    LoadMessageBoxGfx(0, 10, 0xD0);
    sub_819A2BC(0xC0, 1);
    LoadPalette(&gUnknown_0860F074, 0xF0, 0x20);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, 0);
        PutWindowTilemap(i);
    }
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
}

void bag_menu_print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 h)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[h], speed, str);
}

u8 sub_81AE124(u8 a)
{
    return gUnknown_0203CE54->windowPointers[a];
}

u8 bag_menu_add_window(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->windowPointers[a];
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
    u8 *ptr = &gUnknown_0203CE54->windowPointers[a];
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
    u8 *ptr = &gUnknown_0203CE54->windowPointers[a];
    if (*ptr == 0xFF)
        *ptr = AddWindow(&gUnknown_086141AC[a]);
    return *ptr;
}

void bag_menu_RemoveBagItem_message_window(u8 a)
{
    u8 *ptr = &gUnknown_0203CE54->windowPointers[a];
    if (*ptr != 0xFF)
    {
        sub_8197DF8(*ptr, 0);
        ClearWindowTilemap(*ptr);
        RemoveWindow(*ptr);
        schedule_bg_copy_tilemap_to_vram(1);
        *ptr = 0xFF;
    }
}

void bag_menu_yes_no(u8 a, u8 b, const struct YesNoFuncTable *funcTable)
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
    const u8* text;

    FillWindowPixelBuffer(4, 0);
    if (itemId == ITEM_NONE)
    {
        for (i = 0; i < 4; i++)
            bag_menu_print(4, 1, gText_ThreeDashes, 7, i * 12, 0, 0, -1, 4);
        CopyWindowToVram(4, 2);
    }
    else
    {
        moveId = ItemIdToBattleMoveId(itemId);
        blit_move_info_icon(4, gBattleMoves[moveId].type + 1, 0, 0);
        if (gBattleMoves[moveId].power <= 1)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveId].power, 1, 3);
            text = gStringVar1;
        }
        bag_menu_print(4, 1, text, 7, 12, 0, 0, -1, 4);
        if (gBattleMoves[moveId].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
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
