#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "field_screen.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "mon_markings.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "walda_phrase.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

enum
{
    BOX_OPTION_WITHDRAW,
    BOX_OPTION_DEPOSIT,
    BOX_OPTION_MOVE_MONS,
    BOX_OPTION_MOVE_ITEMS,
    BOX_OPTION_EXIT,
};

enum
{
    PC_TEXT_EXIT_BOX,
    PC_TEXT_WHAT_YOU_DO,
    PC_TEXT_PICK_A_THEME,
    PC_TEXT_PICK_A_WALLPAPER,
    PC_TEXT_IS_SELECTED,
    PC_TEXT_JUMP_TO_WHICH_BOX,
    PC_TEXT_DEPOSIT_IN_WHICH_BOX,
    PC_TEXT_WAS_DEPOSITED,
    PC_TEXT_BOX_IS_FULL,
    PC_TEXT_RELEASE_POKE,
    PC_TEXT_WAS_RELEASED,
    PC_TEXT_BYE_BYE,
    PC_TEXT_MARK_POKE,
    PC_TEXT_LAST_POKE,
    PC_TEXT_PARTY_FULL,
    PC_TEXT_HOLDING_POKE,
    PC_TEXT_WHICH_ONE_WILL_TAKE,
    PC_TEXT_CANT_RELEASE_EGG,
    PC_TEXT_CONTINUE_BOX,
    PC_TEXT_CAME_BACK,
    PC_TEXT_WORRIED,
    PC_TEXT_SURPRISE,
    PC_TEXT_PLEASE_REMOVE_MAIL,
    PC_TEXT_IS_SELECTED2,
    PC_TEXT_GIVE_TO_MON,
    PC_TEXT_PLACED_IN_BAG,
    PC_TEXT_BAG_FULL,
    PC_TEXT_PUT_IN_BAG,
    PC_TEXT_ITEM_IS_HELD,
    PC_TEXT_CHANGED_TO_ITEM,
    PC_TEXT_CANT_STORE_MAIL,
};

enum
{
    SCREEN_CHANGE_EXIT_BOX,
    SCREEN_CHANGE_SUMMARY_SCREEN,
    SCREEN_CHANGE_NAME_BOX,
    SCREEN_CHANGE_ITEM_FROM_BAG,
};

#define TAG_PAL_WAVEFORM    0xDACA
#define TAG_PAL_DAC8        0xDAC8
#define TAG_PAL_DAC6        0xDAC6
#define TAG_PAL_DACE        0xDACE
#define TAG_PAL_DAC7        0xDAC7

#define TAG_TILE_WAVEFORM   0x5
#define TAG_TILE_10         0x10
#define TAG_TILE_2          0x2
#define TAG_TILE_D          0xD
#define TAG_TILE_A          0xA

IWRAM_DATA u8 gUnknown_03000F78[0x188];

extern const u8 gText_PartyFull[];
extern const u8 gText_Box[];
extern const u8 gText_JustOnePkmn[];

extern u8 gUnknown_02039D00;
extern u8 sBoxOption;
extern u8 gUnknown_02039D10;
extern u8 gUnknown_02039D0E;
extern bool8 sInPartyMenu;
extern u8 gUnknown_02039D0F;
extern u16 gUnknown_02039D12;
extern struct Pokemon gUnknown_02039D14;

extern void sub_80F9BCC(u16, u16, u8);
extern void sub_80F9BF4(u16, u16, u8);
extern bool8 sub_80F9C1C(void);
extern bool8 sub_80F9C30(void);

// This file's functions.
void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr);
void Cb2_EnterPSS(u8 boxOption);
u8 sub_80CAEA0(void);
u8 sub_80CF9EC(void);
u8 sub_80CDC2C(void);
void SetBoxWallpaper(u8 boxId, u8 wallpaperId);
void SetCurrentBox(u8 boxId);
void sub_80CC32C(u8 boxId);
void ClearMonInBox(u8 boxId, u8 boxPos);
void sub_80C7958(u8 curBox);
void ResetWaldaWallpaper(void);
void sub_80C7B14(void);
void sub_80C7BB4(void);
void ScrollBackground(void);
void sub_80C7B80(void);
void sub_80D2AA4(void);
void sub_80C7BE4(void);
void sub_80CAA14(void);
void sub_80CE790(void);
void sub_80CE8E4(void);
void GiveChosenBagItem(void);
void sub_80CA888(void);
void LoadPSSMenuGfx(void);
void LoadWaveformSpritePalette(void);
void sub_80CDC18(void);
void sub_80CD36C(void);
void sub_80CD3EC(void);
void sub_80CAC1C(void);
void SetScrollingBackground(void);
void sub_80CABE0(void);
void sub_80CAEAC(void);
void sub_80D0C60(void);
void sub_80CFEA8(void);
void sub_80CDC0C(void);
void sub_80CAF04(void);
void sub_80CA0D8(void);
void sub_80CFFD0(void);
void sub_80CE250(void);
void sub_80CE3A0(void);
void sub_80D01B8(void);
void sub_80CE2D8(void);
void sub_80D25F0(void);
void sub_80CA230(void);
void sub_80CA318(void);
void sub_80CA154(void);
void sub_80CA1C4(void);
void sub_80CC064(void);
void sub_80CE324(void);
void ClearBottomWindow(void);
void sub_80CA704(void);
void sub_80D013C(void);
void sub_80CE00C(void);
void sub_80D1194(void);
void sub_80CA4FC(void);
void sub_80CADD8(void);
void sub_80D1818(void);
void sub_80D17B4(void);
void sub_80CE760(void);
void sub_80CE7E8(void);
void sub_80CFECC(void);
void sub_80CA9EC(void);
void FreePSSData(void);
void sub_80CAB20(void);
void sub_80CE22C(void);
void sub_80CB950(void);
void sub_80CA9C0(void);
void BoxSetMosaic(void);
void sub_80C7CF4(struct Sprite *sprite);
bool8 InitPSSWindows(void);
bool8 sub_80CC0A0(void);
bool8 sub_80CE2A8(void);
bool8 sub_80D0164(void);
bool8 sub_80CC35C(void);
bool8 sub_80D01E4(void);
bool8 sub_80CAB4C(void);
bool8 sub_80D184C(void);
bool8 sub_80D18E4(void);
bool8 sub_80CAB70(void);
bool8 sub_80D1218(void);
bool8 sub_80CB9BC(void);
bool8 ScrollToBox(void);
bool8 sub_80CD554(void);
bool8 sub_80CA8C8(void);
bool8 sub_80D127C(void);
bool8 sub_80CA2B8(void);
bool8 DoWallpaperGfxChange(void);
bool8 sub_80CDCAC(void);
bool8 sub_80D00A8(void);
bool8 CanMoveMon(void);
bool8 CanShifMon(void);
bool8 IsCursorOnCloseBox(void);
bool8 IsMonBeingMoved(void);
bool8 sub_80CE19C(u8 arg0);
void Cb_InitPSS(u8 taskId);
void Cb_PlaceMon(u8 taskId);
void Cb_ChangeScreen(u8 taskId);
void Cb_ShowPSS(u8 taskId);
void Cb_OnBPressed(u8 taskId);
void Cb_HandleBoxOptions(u8 taskId);
void Cb_OnSelectedMon(u8 taskId);
void Cb_OnCloseBoxPressed(u8 taskId);
void Cb_HidePartyPokemon(u8 taskId);
void Cb_DepositMenu(u8 taskId);
void Cb_MoveMon(u8 taskId);
void Cb_GiveMovingItemToMon(u8 taskId);
void Cb_SwitchSelectedItem(u8 taskId);
void Cb_TakeItemForMoving(u8 taskId);
void Cb_WithdrawMon(u8 taskId);
void Cb_ShiftMon(u8 taskId);
void Cb_ShowPartyPokemon(u8 taskId);
void Cb_ShowItemInfo(u8 taskId);
void Cb_GiveItemFromBag(u8 taskId);
void Cb_ItemToBag(u8 taskId);
void Cb_TakeItemForMoving(u8 taskId);
void Cb_ShowMarkMenu(u8 taskId);
void Cb_ShowMonSummary(u8 taskId);
void Cb_ReleaseMon(u8 taskId);
void task_pokemon_box_related(u8 taskId);
void Cb_ReshowPSSAfterChoosingBagItem(u8 taskId);
void Cb_MainPSS(u8 taskId);
void Cb_JumpBox(u8 taskId);
void Cb_HandleWallpapers(u8 taskId);
void Cb_NameBox(u8 taskId);
void Cb_PrintCantStoreMail(u8 taskId);
void Cb_HandleMovingMonFromParty(u8 taskId);
void sub_80D2A90(struct UnkStruct_2000020 *arg0, struct UnkStruct_2000028 *arg1, u32 arg2);
void sub_80D259C(u8 arg0);
void sub_80CC464(u8 arg0);
void sub_80CFE54(u8 arg0);
void sub_80CC0D4(u8 arg0);
void sub_80CDC38(u8 arg0);
void sub_80CE9A8(u8 markings);
void sub_80CAD9C(u8 arg0);
void sub_80CDBF8(u8 arg0);
void sub_80D01D0(u8 arg0);
void sub_80CD1A8(bool8 arg0);
void sub_80D2644(u8 arg0, u16 arg1, const u16 *arg2, u16 arg3, u16 arg4);
void sub_80D2770(u8 arg0, u16 arg1, u16 arg2);
void PrintStorageActionText(u8 id);
s16 sub_80D00AC(void);
s8 sub_80CE580(void);
u8 GetBoxCursorPosition(void);
void sub_80D0E90(bool8 inParty, u8 boxPosition);
void sub_80D1080(bool8 inParty, u8 boxPosition);
void sub_80D1114(bool8 inParty, u8 boxPosition);
void sub_80D0FAC(bool8 inParty, u8 boxPosition);
struct Sprite *sub_80CD2E8(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority);
void SetWallpaperForCurrentBox(u8 wallpaperId);
void sub_80CAE0C(u8 arg0);
u16 GetMovingItem(void);
void SetCurrentBoxMonData(s32 monId, s32 request, const void *value);

// const rom data
const struct PSS_MenuStringPtrs gUnknown_085716C0[] =
{
    {gText_WithdrawPokemon, gText_WithdrawMonDescription},
    {gText_DepositPokemon, gText_DepositMonDescription},
    {gText_MovePokemon, gText_MoveMonDescription},
    {gText_MoveItems, gText_MoveItemsDescription},
    {gText_SeeYa, gText_SeeYaDescription}
};

const struct WindowTemplate gUnknown_085716E8 =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

const union AnimCmd sSpriteAnim_85716F0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_85716F8[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_8571700[] =
{
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_8571708[] =
{
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_END
};

const union AnimCmd *const sSpriteAnimTable_8571710[] =
{
    sSpriteAnim_85716F0,
    sSpriteAnim_85716F8,
    sSpriteAnim_8571700,
    sSpriteAnim_8571708
};

const union AffineAnimCmd sSpriteAffineAnim_8571720[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd *const sSpriteAffineAnimTable_8571730[] =
{
    sSpriteAffineAnim_8571720
};

const u8 gUnknown_08571734[] = {4, 0xF, 0xE};
const u8 gUnknown_08571737[] = _("/30");

const u16 gBoxSelectionPopupPalette[] = INCBIN_U16("graphics/unknown/unknown_57173C.gbapal");
const u8 gBoxSelectionPopupCenterTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_center.4bpp");
const u8 gBoxSelectionPopupSidesTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_sides.4bpp");
const u32 gPokemonStorageScrollingBGTileset[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.4bpp.lz");
const u32 gPokemonStorageScrollingBGTilemap[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.bin.lz");
const u32 gUnknown_08572280[] = INCBIN_U32("graphics/unknown/unknown_572280.gbapal");
const u32 gUnknown_085722A0[] = INCBIN_U32("graphics/unknown/unknown_5722A0.bin.lz");

const u16 gUnknown_0857239C[] =
{
    0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0111, 0x0112, 0x0113, 0x0114, 0x0115, 0x0116, 0x0117, 0x0118,
    0x2101, 0x2102, 0x2103, 0x2104, 0x2105, 0x2106, 0x2107, 0x2108, 0x2111, 0x2112, 0x2113, 0x2114, 0x2115, 0x2116, 0x2117, 0x2118,
};

const u16 gUnknown_085723DC[] = INCBIN_U16("graphics/unknown/unknown_5723DC.gbapal"); // Left-most part and Close Box.
const u16 gUnknown_085723FC[] = INCBIN_U16("graphics/unknown/unknown_5723FC.gbapal");
const u16 gUnknown_0857241C[] = INCBIN_U16("graphics/unknown/unknown_57241C.gbapal");
const u16 gUnknown_0857243C[] = INCBIN_U16("graphics/unknown/unknown_57243C.gbapal");

const u16 gUnknown_0857245C[] =
{
    0x014c, 0x014d, 0x014e, 0x014f, 0x0170, 0x0171, 0x0172, 0x0173, 0x0174, 0x015c, 0x015d, 0x015e, 0x015f, 0x0180, 0x0181, 0x0182,
	0x0183, 0x0184, 0x0175, 0x0176, 0x0177, 0x0178, 0x0179, 0x017a, 0x017b, 0x017c, 0x017d, 0x0185, 0x0186, 0x0187, 0x0188, 0x0189,
	0x018a, 0x018b, 0x018c, 0x018d
};
const u16 gUnknown_085724A4[] =
{
    0x1140, 0x1141, 0x1141, 0x1142, 0x1150, 0x1151, 0x1151, 0x1152, 0x1160, 0x1161, 0x1161, 0x1162,
};
const u16 gUnknown_085724BC[] =
{
    0x1143, 0x1144, 0x1144, 0x1145, 0x1153, 0x1154, 0x1154, 0x1155, 0x1163, 0x1164, 0x1164, 0x1165,
};

const u16 gWaveformPalette[] = INCBIN_U16("graphics/pokemon_storage/waveform.gbapal");
const u32 gWaveformTiles[] = INCBIN_U32("graphics/pokemon_storage/waveform.4bpp");
const u32 gUnknown_085726B4[] = INCBIN_U32("graphics/unused/unknown_5726B4.gbapal");
const u32 gUnknown_085726F4[] = INCBIN_U32("graphics/unknown/unknown_5726F4.gbapal");

const struct WindowTemplate gUnknown_08572714[] =
{
    { // 0
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 11,
        .width = 9,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0xC0,
    },
    { // 1
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 17,
        .width = 18,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    { // 2
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 21,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    DUMMY_WIN_TEMPLATE
};

const struct BgTemplate gUnknown_08572734[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x100
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

const struct SpritePalette gWaveformSpritePalette =
{
    gWaveformPalette, TAG_PAL_WAVEFORM
};

const struct SpriteSheet gWaveformSpriteSheet =
{
    gWaveformTiles, sizeof(gWaveformTiles), TAG_TILE_WAVEFORM
};

const struct OamData sOamData_857286C;
const struct SpriteTemplate gUnknown_08572754 =
{
    .tileTag = TAG_TILE_2,
    .paletteTag = TAG_PAL_DAC6,
    .oam = &sOamData_857286C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct StorageAction gPCStorageActionTexts[] =
{
    [PC_TEXT_EXIT_BOX] = {gText_ExitFromBox, 0},
    [PC_TEXT_WHAT_YOU_DO] = {gText_WhatDoYouWantToDo, 0},
    [PC_TEXT_PICK_A_THEME] = {gText_PleasePickATheme, 0},
    [PC_TEXT_PICK_A_WALLPAPER] = {gText_PickTheWallpaper, 0},
    [PC_TEXT_IS_SELECTED] = {gText_PkmnIsSelected, 1},
    [PC_TEXT_JUMP_TO_WHICH_BOX] = {gText_JumpToWhichBox, 0},
    [PC_TEXT_DEPOSIT_IN_WHICH_BOX] = {gText_DepositInWhichBox, 0},
    [PC_TEXT_WAS_DEPOSITED] = {gText_PkmnWasDeposited, 1},
    [PC_TEXT_BOX_IS_FULL] = {gText_BoxIsFull2, 0},
    [PC_TEXT_RELEASE_POKE] = {gText_ReleaseThisPokemon, 0},
    [PC_TEXT_WAS_RELEASED] = {gText_PkmnWasReleased, 4},
    [PC_TEXT_BYE_BYE] = {gText_ByeByePkmn, 6},
    [PC_TEXT_MARK_POKE] = {gText_MarkYourPkmn, 0},
    [PC_TEXT_LAST_POKE] = {gText_ThatsYourLastPkmn, 0},
    [PC_TEXT_PARTY_FULL] = {gText_YourPartysFull, 0},
    [PC_TEXT_HOLDING_POKE] = {gText_YoureHoldingAPkmn, 0},
    [PC_TEXT_WHICH_ONE_WILL_TAKE] = {gText_WhichOneWillYouTake, 0},
    [PC_TEXT_CANT_RELEASE_EGG] = {gText_YouCantReleaseAnEgg, 0},
    [PC_TEXT_CONTINUE_BOX] = {gText_ContinueBoxOperations, 0},
    [PC_TEXT_CAME_BACK] = {gText_PkmnCameBack, 1},
    [PC_TEXT_WORRIED] = {gText_WasItWorriedAboutYou, 0},
    [PC_TEXT_SURPRISE] = {gText_FourEllipsesExclamation, 0},
    [PC_TEXT_PLEASE_REMOVE_MAIL] = {gText_PleaseRemoveTheMail, 0},
    [PC_TEXT_IS_SELECTED2] = {gText_PkmnIsSelected, 7},
    [PC_TEXT_GIVE_TO_MON] = {gText_GiveToAPkmn, 0},
    [PC_TEXT_PLACED_IN_BAG] = {gText_PlacedItemInBag, 7},
    [PC_TEXT_BAG_FULL] = {gText_BagIsFull2, 0},
    [PC_TEXT_PUT_IN_BAG] = {gText_PutItemInBag, 0},
    [PC_TEXT_ITEM_IS_HELD] = {gText_ItemIsNowHeld, 7},
    [PC_TEXT_CHANGED_TO_ITEM] = {gText_ChangedToNewItem, 7},
    [PC_TEXT_CANT_STORE_MAIL] = {gText_MailCantBeStored, 0},
};

const struct WindowTemplate gUnknown_08572864 =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 11,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x5C,
};

const struct OamData sOamData_857286C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

const struct OamData sOamData_8572874 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

const union AnimCmd sSpriteAnim_857287C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_8572884[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_JUMP(0)
};

const union AnimCmd sSpriteAnim_8572894[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_857289C[] =
{
    ANIMCMD_FRAME(10, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_JUMP(0)
};

const union AnimCmd *const sSpriteAnimTable_85728AC[] =
{
    sSpriteAnim_857287C,
    sSpriteAnim_8572884,
    sSpriteAnim_8572894,
    sSpriteAnim_857289C
};

const struct SpriteTemplate gUnknown_085728BC =
{
    .tileTag = 5,
    .paletteTag = 0xDACA,
    .oam = &sOamData_8572874,
    .anims = sSpriteAnimTable_85728AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct OamData sOamData_85728EC;
const struct SpriteTemplate gUnknown_085728D4 =
{
    .tileTag = 18,
    .paletteTag = 0xDAC0,
    .oam = &sOamData_85728EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct OamData sOamData_85728EC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

const union AffineAnimCmd gSpriteAffineAnim_85728F4[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 120),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd gSpriteAffineAnim_8572904[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_857291C[] =
{
    gSpriteAffineAnim_85728F4,
    gSpriteAffineAnim_8572904
};

// code
u8 CountMonsInBox(u8 boxId)
{
    u16 i, count;

    for (i = 0, count = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataFromAnyBox(boxId, i, MON_DATA_SPECIES) != SPECIES_NONE)
            count++;
    }

    return count;
}

s16 GetFirstFreeBoxSpot(u8 boxId)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataFromAnyBox(boxId, i, MON_DATA_SPECIES) == SPECIES_NONE)
            return i;
    }

    return -1; // all spots are taken
}

u8 CountPartyNonEggMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            count++;
        }
    }

    return count;
}

u8 CountPartyAliveNonEggMonsExcept(u8 slotToIgnore)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (i != slotToIgnore
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            count++;
        }
    }

    return count;
}

u16 CountPartyAliveNonEggMons_IgnoreVar0x8004Slot(void)
{
    return CountPartyAliveNonEggMonsExcept(gSpecialVar_0x8004);
}

u8 CountPartyMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            count++;
        }
    }

    return count;
}

u8 *StringCopyAndFillWithSpaces(u8 *dst, const u8 *src, u16 n)
{
    u8 *str;

    for (str = StringCopy(dst, src); str < dst + n; str++)
        *str = CHAR_SPACE;

    *str = EOS;
    return str;
}

void sub_80C7128(u16 *dest, u16 dest_left, u16 dest_top, const u16 *src, u16 src_left, u16 src_top, u16 dest_width, u16 dest_height, u16 src_width)
{
    u16 i;

    dest_width *= 2;
    dest += dest_top * 0x20 + dest_left;
    src += src_top * src_width + src_left;
    for (i = 0; i < dest_height; i++)
    {
        CpuCopy16(src, dest, dest_width);
        dest += 0x20;
        src += src_width;
    }
}

#define MAX_DMA_BLOCK_SIZE 0x1000
#define Dma3FillLarge_(value, dest, size, bit)             \
{                                                          \
    void *_dest = dest;                                    \
    u32 _size = size;                                      \
    while (1)                                              \
    {                                                      \
        if (_size <= MAX_DMA_BLOCK_SIZE)                   \
        {                                                  \
            DmaFill##bit(3, value, _dest, _size);          \
            break;                                         \
        }                                                  \
        DmaFill##bit(3, value, _dest, MAX_DMA_BLOCK_SIZE); \
        _dest += MAX_DMA_BLOCK_SIZE;                       \
        _size -= MAX_DMA_BLOCK_SIZE;                       \
    }                                                      \
}

#define Dma3FillLarge16_(value, dest, size) Dma3FillLarge_(value, dest, size, 16)
#define Dma3FillLarge32_(value, dest, size) Dma3FillLarge_(value, dest, size, 32)

void sub_80C71A4(u16 *dest, u16 dest_left, u16 dest_top, u16 width, u16 height)
{
    u16 i;

    dest += dest_top * 0x20 + dest_left;
    width *= 2;
    for (i = 0; i < height; dest += 0x20, i++)
        Dma3FillLarge16_(0, dest, width);
}

void Task_PokemonStorageSystemPC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        CreatePCMenu(task->data[1], &task->data[15]);
        sub_81973A4();
        NewMenuHelpers_DrawDialogueFrame(0, 0);
        FillWindowPixelBuffer(0, 0x11);
        AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, TEXT_SPEED_FF, NULL, 2, 1, 3);
        CopyWindowToVram(0, 3);
        CopyWindowToVram(task->data[15], 3);
        task->data[0]++;
        break;
    case 1:
        if (IsWeatherNotFadingIn())
        {
            task->data[0]++;
        }
        break;
    case 2:
        task->data[2] = Menu_ProcessInput();
        switch(task->data[2])
        {
        case -2:
            task->data[3] = task->data[1];
            if (gMain.newKeys & DPAD_UP && --task->data[3] < 0)
                task->data[3] = 4;

            if (gMain.newKeys & DPAD_DOWN && ++task->data[3] > 4)
                task->data[3] = 0;
            if (task->data[1] != task->data[3])
            {
                task->data[1] = task->data[3];
                FillWindowPixelBuffer(0, 0x11);
                AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            }
            break;
        case -1:
        case  4:
            sub_819746C(task->data[15], TRUE);
            ScriptContext2_Disable();
            EnableBothScriptContexts();
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
            break;
        default:
            if (task->data[2] == 0 && CountPartyMons() == PARTY_SIZE)
            {
                FillWindowPixelBuffer(0, 0x11);
                AddTextPrinterParameterized2(0, 1, gText_PartyFull, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else if (task->data[2] == 1 && CountPartyMons() == 1)
            {
                FillWindowPixelBuffer(0, 0x11);
                AddTextPrinterParameterized2(0, 1, gText_JustOnePkmn, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else
            {
                FadeScreen(1, 0);
                task->data[0] = 4;
            }
            break;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            FillWindowPixelBuffer(0, 0x11);
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_UP)
        {
            if (--task->data[1] < 0)
                task->data[1] = 4;
            MoveMenuCursor(-1);
            task->data[1] = GetMenuCursorPos();
            FillWindowPixelBuffer(0, 0x11);
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (++task->data[1] > 3)
                task->data[1] = 0;
            MoveMenuCursor(1);
            task->data[1] = GetMenuCursorPos();
            FillWindowPixelBuffer(0, 0x11);
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            overworld_free_bg_tilemaps();
            Cb2_EnterPSS(task->data[2]);
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
        }
        break;
    }
}

void ShowPokemonStorageSystemPC(void)
{
    u8 taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    ScriptContext2_Enable();
}

void FieldCb_ReturnToPcMenu(void)
{
    u8 taskId;
    MainCallback vblankCb = gMain.vblankCallback;

    SetVBlankCallback(NULL);
    taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gUnknown_02039D00;
    Task_PokemonStorageSystemPC(taskId);
    SetVBlankCallback(vblankCb);
    pal_fill_black();
}

void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr)
{
    s16 windowId;
    struct WindowTemplate winTemplate = gUnknown_085716E8;
    winTemplate.width = GetMaxWidthInMenuTable((void *)gUnknown_085716C0, ARRAY_COUNT(gUnknown_085716C0));
    windowId = AddWindow(&winTemplate);

    NewMenuHelpers_DrawStdWindowFrame(windowId, FALSE);
    PrintMenuTable(windowId, ARRAY_COUNT(gUnknown_085716C0), (void *)gUnknown_085716C0);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, ARRAY_COUNT(gUnknown_085716C0), whichMenu);
    *windowIdPtr = windowId;
}

void Cb2_ExitPSS(void)
{
    gUnknown_02039D00 = sub_80CAEA0();
    gFieldCallback = FieldCb_ReturnToPcMenu;
    SetMainCallback2(CB2_ReturnToField);
}

s16 StorageSystemGetNextMonIndex(struct BoxPokemon *box, s8 startIdx, u8 stopIdx, u8 mode)
{
    s16 i;
    s16 direction;
    if (mode == 0 || mode == 1)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }
    if (mode == 1 || mode == 3)
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0)
                return i;
        }
    }
    else
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0 && !GetBoxMonData(box + i, MON_DATA_IS_EGG))
                return i;
        }
    }
    return -1;
}

void ResetPokemonStorageSystem(void)
{
    u16 boxId;
    u16 boxMon;

    SetCurrentBox(0);
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxMon = 0; boxMon < IN_BOX_COUNT; boxMon++)
            ClearMonInBox(boxId, boxMon);
    }
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        u8 *dest = StringCopy(GetBoxNamePtr(boxId), gText_Box);
        ConvertIntToDecimalStringN(dest, boxId + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
    }
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        SetBoxWallpaper(boxId, boxId % 4);
    }
    ResetWaldaWallpaper();
}

void sub_80C77E8(struct UnkPSSStruct_2002370 *a0, u16 tileTag, u16 palTag, u8 a3, bool32 loadPal)
{
    struct SpritePalette palette =
    {
        gBoxSelectionPopupPalette, palTag
    };
    struct SpriteSheet sheets[] =
    {
        {gBoxSelectionPopupCenterTiles, 0x800, tileTag},
        {gBoxSelectionPopupSidesTiles,  0x180, tileTag + 1},
        {}
    };

    if (loadPal)
        LoadSpritePalette(&palette);

    LoadSpriteSheets(sheets);
    gUnknown_02039D04 = a0;
    a0->unk_0240 = tileTag;
    a0->unk_0242 = palTag;
    a0->unk_0246 = a3;
    a0->unk_023c = loadPal;
}

void sub_80C7890(void)
{
    if (gUnknown_02039D04->unk_023c)
        FreeSpritePaletteByTag(gUnknown_02039D04->unk_0242);
    FreeSpriteTilesByTag(gUnknown_02039D04->unk_0240);
    FreeSpriteTilesByTag(gUnknown_02039D04->unk_0240 + 1);
}

void sub_80C78D4(u8 curBox)
{
    sub_80C7958(curBox);
}

void sub_80C78E4(void)
{
    sub_80C7B14();
}

u8 sub_80C78F0(void)
{
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        return 201;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_02039D04->curBox;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        sub_80C7BB4();
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        sub_80C7B80();
    }
    return 200;
}

void sub_80C7958(u8 curBox)
{
    u16 i;
    u8 spriteId;
    struct SpriteTemplate template;
    struct OamData oamData = {};
    oamData.size = 3;
    oamData.paletteNum = 1;
    template = (struct SpriteTemplate){
        0, 0, &oamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
    };

    gUnknown_02039D04->curBox = curBox;
    template.tileTag = gUnknown_02039D04->unk_0240;
    template.paletteTag = gUnknown_02039D04->unk_0242;

    spriteId = CreateSprite(&template, 0xA0, 0x60, 0);
    gUnknown_02039D04->unk_0000 = gSprites + spriteId;

    oamData.shape = ST_OAM_V_RECTANGLE;
    oamData.size = 1;
    template.tileTag = gUnknown_02039D04->unk_0240 + 1;
    template.anims = sSpriteAnimTable_8571710;
    for (i = 0; i < 4; i++)
    {
        u16 r5;
        spriteId = CreateSprite(&template, 0x7c, 0x50, gUnknown_02039D04->unk_0246);
        gUnknown_02039D04->unk_0004[i] = gSprites + spriteId;
        r5 = 0;
        if (i & 2)
        {
            gUnknown_02039D04->unk_0004[i]->pos1.x = 0xc4;
            r5 = 2;
        }
        if (i & 1)
        {
            gUnknown_02039D04->unk_0004[i]->pos1.y = 0x70;
            gUnknown_02039D04->unk_0004[i]->oam.size = 0;
            r5++;
        }
        StartSpriteAnim(gUnknown_02039D04->unk_0004[i], r5);
    }
    for (i = 0; i < 2; i++)
    {
        gUnknown_02039D04->unk_0020[i] = sub_80CD2E8(72 * i + 0x7c, 0x58, i, 0, gUnknown_02039D04->unk_0246);
        if (gUnknown_02039D04->unk_0020[i])
        {
            gUnknown_02039D04->unk_0020[i]->data[0] = (i == 0 ? -1 : 1);
            gUnknown_02039D04->unk_0020[i]->callback = sub_80C7CF4;
        }
    }
    sub_80C7BE4();
}

void sub_80C7B14(void)
{
    u16 i;
    if (gUnknown_02039D04->unk_0000)
    {
        DestroySprite(gUnknown_02039D04->unk_0000);
        gUnknown_02039D04->unk_0000 = NULL;
    }
    for (i = 0; i < 4; i++)
    {
        if (gUnknown_02039D04->unk_0004[i])
        {
            DestroySprite(gUnknown_02039D04->unk_0004[i]);
            gUnknown_02039D04->unk_0004[i] = NULL;
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (gUnknown_02039D04->unk_0020[i])
            DestroySprite(gUnknown_02039D04->unk_0020[i]);
    }
}

void sub_80C7B80(void)
{
    if (++gUnknown_02039D04->curBox >= TOTAL_BOXES_COUNT)
        gUnknown_02039D04->curBox = 0;
    sub_80C7BE4();
}

void sub_80C7BB4(void)
{
    gUnknown_02039D04->curBox = (gUnknown_02039D04->curBox == 0 ? TOTAL_BOXES_COUNT - 1 : gUnknown_02039D04->curBox - 1);
    sub_80C7BE4();
}

void sub_80C7BE4(void)
{
    u8 text[16];
    struct WindowTemplate winTemplate;
    u8 windowId;
    u8 *boxName = GetBoxNamePtr(gUnknown_02039D04->curBox);
    u8 nPokemonInBox = CountMonsInBox(gUnknown_02039D04->curBox);
    u32 winTileData;
    s32 center;

    memset(&winTemplate, 0, sizeof(winTemplate));
    winTemplate.width = 8;
    winTemplate.height = 4;

    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, 0x44);

    center = GetStringCenterAlignXOffset(1, boxName, 0x40);
    AddTextPrinterParameterized3(windowId, 1, center, 1, gUnknown_08571734, TEXT_SPEED_FF, boxName);

    ConvertIntToDecimalStringN(text, nPokemonInBox, 1, 2);
    StringAppend(text, gUnknown_08571737);
    center = GetStringCenterAlignXOffset(1, text, 0x40);
    AddTextPrinterParameterized3(windowId, 1, center, 0x11, gUnknown_08571734, TEXT_SPEED_FF, text);

    winTileData = GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    CpuCopy32((void *)winTileData, (void *)OBJ_VRAM0 + 0x100 + (GetSpriteTileStartByTag(gUnknown_02039D04->unk_0240) * 32), 0x400);

    RemoveWindow(windowId);
}

void sub_80C7CF4(struct Sprite *sprite)
{
    if (++sprite->data[1] > 3)
    {
        sprite->data[1] = 0;
        sprite->pos2.x += sprite->data[0];
        if (++sprite->data[2] > 5)
        {
            sprite->data[2] = 0;
            sprite->pos2.x = 0;
        }
    }
}

void VblankCb_PSS(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    sub_80D2AA4();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_02039D08->bg2_X);
}

void Cb2_PSS(void)
{
    RunTasks();
    do_scheduled_bg_tilemap_copies_to_vram();
    ScrollBackground();
    sub_80CAA14();
    AnimateSprites();
    BuildOamBuffer();
}

void Cb2_EnterPSS(u8 boxOption)
{
    ResetTasks();
    sBoxOption = boxOption;
    gUnknown_02039D08 = Alloc(sizeof(*gUnknown_02039D08));
    if (gUnknown_02039D08 == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        gUnknown_02039D08->boxOption = boxOption;
        gUnknown_02039D08->isReshowingPSS = FALSE;
        gUnknown_02039D12 = 0;
        gUnknown_02039D08->state = 0;
        gUnknown_02039D08->taskId = CreateTask(Cb_InitPSS, 3);
        gUnknown_02039D10 = StorageGetCurrentBox();
        SetMainCallback2(Cb2_PSS);
    }
}

void Cb2_ReturnToPSS(void)
{
    ResetTasks();
    gUnknown_02039D08 = Alloc(sizeof(*gUnknown_02039D08));
    if (gUnknown_02039D08 == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        gUnknown_02039D08->boxOption = sBoxOption;
        gUnknown_02039D08->isReshowingPSS = TRUE;
        gUnknown_02039D08->state = 0;
        gUnknown_02039D08->taskId = CreateTask(Cb_InitPSS, 3);
        SetMainCallback2(Cb2_PSS);
    }
}

void ResetAllBgCoords(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
}

void sub_80C7E98(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
    ClearDma3Requests();
    gReservedSpriteTileCount = 0x280;
    sub_80D2A90(&gUnknown_02039D08->unk_0020, gUnknown_02039D08->unk_0028, 8);
    gKeyRepeatStartDelay = 20;
    clear_scheduled_bg_copies_to_vram();
    sub_80D259C(3);
    sub_80D2644(0, 1, gUnknown_0857239C, 8, 4);
    sub_80D2770(0, 1, 0);
    gUnknown_02039D08->unk_02C7 = 0;
}

void sub_80C7F1C(void)
{
    sub_80CDC0C();
    sInPartyMenu = (gUnknown_02039D08->boxOption == BOX_OPTION_DEPOSIT);
    gUnknown_02039D0E = 0;
}

void sub_80C7F4C(void)
{
    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));
    }
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
}

void SetPSSCallback(TaskFunc newFunc)
{
    gTasks[gUnknown_02039D08->taskId].func = newFunc;
    gUnknown_02039D08->state = 0;
}

void Cb_InitPSS(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        sub_80C7E98();
        if (gUnknown_02039D08->isReshowingPSS)
        {
            switch (gUnknown_02039D0F)
            {
            case 1:
                sub_80CE790();
                break;
            case 0:
                sub_80CE8E4();
                break;
            case 2:
                GiveChosenBagItem();
                break;
            }
        }
        LoadPSSMenuGfx();
        LoadWaveformSpritePalette();
        break;
    case 1:
        if (!InitPSSWindows())
        {
            SetPSSCallback(Cb_ChangeScreen);
            return;
        }
        break;
    case 2:
        PutWindowTilemap(0);
        ClearWindowTilemap(1);
        CpuFill32(0, (void *)VRAM, 0x200);
        LoadUserWindowBorderGfx(1, 0xB, 0xE0);
        break;
    case 3:
        ResetAllBgCoords();
        if (!gUnknown_02039D08->isReshowingPSS)
            sub_80C7F1C();
        break;
    case 4:
        sub_80CAF04();
        if (!gUnknown_02039D08->isReshowingPSS)
            sub_80CD36C();
        else
            sub_80CD3EC();
        break;
    case 5:
        if (!sub_80D0164())
        {
            SetPSSCallback(Cb_ChangeScreen);
            return;
        }
        else
        {
            SetScrollingBackground();
            sub_80CAC1C();
        }
        break;
    case 6:
        sub_80CA0D8();
        break;
    case 7:
        sub_80CA704();
        break;
    case 8:
        sub_80CC32C(StorageGetCurrentBox());
        break;
    case 9:
        if (sub_80CC35C())
            return;

        if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        {
            gUnknown_02039D08->field_DA4.baseTileTag = TAG_TILE_D;
            gUnknown_02039D08->field_DA4.basePaletteTag = TAG_PAL_DACE;
            sub_811F90C(&gUnknown_02039D08->field_DA4);
            sub_811FA90();
        }
        else
        {
            sub_80D0C60();
            sub_80CAEAC();
        }
        break;
    case 10:
        sub_80C7F4C();
        if (!gUnknown_02039D08->isReshowingPSS)
        {
            BlendPalettes(0xFFFFFFFF, 0x10, 0);
            SetPSSCallback(Cb_ShowPSS);
        }
        else
        {
            BlendPalettes(0xFFFFFFFF, 0x10, 0);
            SetPSSCallback(Cb_ReshowPSSAfterChoosingBagItem);
        }
        SetVBlankCallback(VblankCb_PSS);
        return;
    default:
        return;
    }

    gUnknown_02039D08->state++;
}

void Cb_ShowPSS(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PlaySE(SE_PC_LOGIN);
        sub_80F9BCC(0x14, 0, 1);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80F9C1C())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ReshowPSSAfterChoosingBagItem(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, -1, 0x10, 0, RGB_BLACK);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            if (gUnknown_02039D0F == 2 && gSpecialVar_ItemId != 0)
            {
                PrintStorageActionText(PC_TEXT_ITEM_IS_HELD);
                gUnknown_02039D08->state++;
            }
            else
            {
                SetPSSCallback(Cb_MainPSS);
            }
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy() && gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_MainPSS(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        switch (sub_80CF9EC())
        {
        case 1:
            PlaySE(SE_SELECT);
            gUnknown_02039D08->state = 1;
            break;
        case 5:
            if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_MONS && gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                PrintStorageActionText(PC_TEXT_WHICH_ONE_WILL_TAKE);
                gUnknown_02039D08->state = 3;
            }
            else
            {
                sub_80CDC0C();
                SetPSSCallback(Cb_ShowPartyPokemon);
            }
            break;
        case 6:
            if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_MONS)
            {
                if (IsMonBeingMoved() && ItemIsMail(gUnknown_02039D08->selectedItem))
                    gUnknown_02039D08->state = 5;
                else
                    SetPSSCallback(Cb_HidePartyPokemon);
            }
            else if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
            {
                SetPSSCallback(Cb_HidePartyPokemon);
            }
            break;
        case 4:
            SetPSSCallback(Cb_OnCloseBoxPressed);
            break;
        case 19:
            SetPSSCallback(Cb_OnBPressed);
            break;
        case 7:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_HandleBoxOptions);
            break;
        case 8:
            SetPSSCallback(Cb_OnSelectedMon);
            break;
        case 9:
            PlaySE(SE_SELECT);
            gUnknown_02039D08->newCurrBoxId = StorageGetCurrentBox() + 1;
            if (gUnknown_02039D08->newCurrBoxId >= TOTAL_BOXES_COUNT)
                gUnknown_02039D08->newCurrBoxId = 0;
            if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                sub_80CC464(gUnknown_02039D08->newCurrBoxId);
                gUnknown_02039D08->state = 2;
            }
            else
            {
                sub_80CFEA8();
                gUnknown_02039D08->state = 10;
            }
            break;
        case 10:
            PlaySE(SE_SELECT);
            gUnknown_02039D08->newCurrBoxId = StorageGetCurrentBox() - 1;
            if (gUnknown_02039D08->newCurrBoxId < 0)
                gUnknown_02039D08->newCurrBoxId = TOTAL_BOXES_COUNT - 1;
            if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                sub_80CC464(gUnknown_02039D08->newCurrBoxId);
                gUnknown_02039D08->state = 2;
            }
            else
            {
                sub_80CFEA8();
                gUnknown_02039D08->state = 10;
            }
            break;
        case 11:
            if (!CanMoveMon())
            {
                if (ItemIsMail(gUnknown_02039D08->selectedItem))
                {
                    gUnknown_02039D08->state = 5;
                }
                else
                {
                    PlaySE(SE_SELECT);
                    SetPSSCallback(Cb_DepositMenu);
                }
            }
            else
            {
                gUnknown_02039D08->state = 4;
            }
            break;
        case 13:
            if (CanMoveMon())
            {
                gUnknown_02039D08->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case 14:
            if (!CanShifMon())
            {
                gUnknown_02039D08->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_ShiftMon);
            }
            break;
        case 12:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_WithdrawMon);
            break;
        case 15:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_PlaceMon);
            break;
        case 16:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_TakeItemForMoving);
            break;
        case 17:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveMovingItemToMon);
            break;
        case 18:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_SwitchSelectedItem);
            break;
        case 20:
            PlaySE(SE_SELECT);
            sub_80D01D0(0);
            gUnknown_02039D08->state = 7;
            break;
        case 22:
            sub_80D01D0(1);
            gUnknown_02039D08->state = 8;
            break;
        case 21:
            PlaySE(SE_SELECT);
            sub_80D01D0(2);
            gUnknown_02039D08->state = 9;
            break;
        case 23:
            sub_80D01D0(3);
            gUnknown_02039D08->state = 7;
            break;
        case 25:
            PlaySE(SE_SELECT);
            sub_80D01D0(4);
            gUnknown_02039D08->state = 9;
            break;
        case 26:
            PlaySE(SE_SELECT);
            sub_80D01D0(5);
            gUnknown_02039D08->state = 7;
            break;
        case 24:
            PlaySE(SE_HAZURE);
            break;
        }
        break;
    case 1:
        if (!sub_80CD554())
        {
            if (IsCursorOnCloseBox())
                sub_80CA9C0();
            else
                sub_80CA9EC();

            if (gUnknown_02039D08->field_CEA)
                BoxSetMosaic();
            gUnknown_02039D08->state = 0;
        }
        break;
    case 2:
        if (!ScrollToBox())
        {
            SetCurrentBox(gUnknown_02039D08->newCurrBoxId);
            if (!sInPartyMenu && !IsMonBeingMoved())
            {
                sub_80CE00C();
                BoxSetMosaic();
            }

            if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
            {
                sub_80CFECC();
                gUnknown_02039D08->state = 11;
            }
            else
            {
                gUnknown_02039D08->state = 0;
            }
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state = 0;
        }
        break;
    case 4:
        PlaySE(SE_HAZURE);
        PrintStorageActionText(PC_TEXT_LAST_POKE);
        gUnknown_02039D08->state = 6;
        break;
    case 5:
        PlaySE(SE_HAZURE);
        PrintStorageActionText(PC_TEXT_PLEASE_REMOVE_MAIL);
        gUnknown_02039D08->state = 6;
        break;
    case 6:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 7:
        if (!sub_80D01E4())
            gUnknown_02039D08->state = 0;
        break;
    case 8:
        if (!sub_80D01E4())
            SetPSSCallback(Cb_MoveMon);
        break;
    case 9:
        if (!sub_80D01E4())
        {
            if (gUnknown_02039D08->field_CEA)
                BoxSetMosaic();
            gUnknown_02039D08->state = 0;
        }
        break;
    case 10:
        if (!sub_80D1218())
        {
            sub_80CC464(gUnknown_02039D08->newCurrBoxId);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 11:
        if (!sub_80D1218())
            gUnknown_02039D08->state = 0;
        break;
    }
}

void Cb_ShowPartyPokemon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CAB4C();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CAB70())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_HidePartyPokemon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_80CA888();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CA8C8())
        {
            sub_80CDBF8(sub_80CDC2C());
            gUnknown_02039D08->state++;
        }
        break;
    case 2:
        if (!sub_80CD554())
        {
            if (gUnknown_02039D08->field_CEA)
                BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_OnSelectedMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!sub_80CA2B8())
        {
            PlaySE(SE_SELECT);
            if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
                PrintStorageActionText(PC_TEXT_IS_SELECTED);
            else if (sub_80D127C() || gUnknown_02039D08->selectedItem != 0)
                PrintStorageActionText(PC_TEXT_IS_SELECTED2);
            else
                PrintStorageActionText(PC_TEXT_GIVE_TO_MON);

            sub_80CFFD0();
            gUnknown_02039D08->state = 1;
        }
        break;
    case 1: // debug?
        if (!sub_80D00A8())
            gUnknown_02039D08->state = 2;
        break;
    case 2:
        switch (sub_80D00AC())
        {
        case -1:
        case  0:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 3:
            if (CanMoveMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case 5:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_PlaceMon);
            break;
        case 4:
            if (!CanShifMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_ShiftMon);
            }
            break;
        case 2:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_WithdrawMon);
            break;
        case 1:
            if (CanMoveMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else if (ItemIsMail(gUnknown_02039D08->selectedItem))
            {
                gUnknown_02039D08->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_DepositMenu);
            }
            break;
        case 7:
            if (CanMoveMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else if (gUnknown_02039D08->field_CED)
            {
                gUnknown_02039D08->state = 5; // Cannot release an Egg.
            }
            else if (ItemIsMail(gUnknown_02039D08->selectedItem))
            {
                gUnknown_02039D08->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_ReleaseMon);
            }
            break;
        case 6:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_ShowMonSummary);
            break;
        case 8:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_ShowMarkMenu);
            break;
        case 12:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_TakeItemForMoving);
            break;
        case 13:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveMovingItemToMon);
            break;
        case 16:
            SetPSSCallback(Cb_ItemToBag);
            break;
        case 15:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_SwitchSelectedItem);
            break;
        case 14:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveItemFromBag);
            break;
        case 17:
            SetPSSCallback(Cb_ShowItemInfo);
            break;
        }
        break;
    case 3:
        PlaySE(SE_HAZURE);
        PrintStorageActionText(PC_TEXT_LAST_POKE);
        gUnknown_02039D08->state = 6;
        break;
    case 5:
        PlaySE(SE_HAZURE);
        PrintStorageActionText(PC_TEXT_CANT_RELEASE_EGG);
        gUnknown_02039D08->state = 6;
        break;
    case 4:
        PlaySE(SE_HAZURE);
        PrintStorageActionText(PC_TEXT_PLEASE_REMOVE_MAIL);
        gUnknown_02039D08->state = 6;
        break;
    case 6:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_MoveMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CDC38(0);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CDCAC())
        {
            if (sInPartyMenu)
                SetPSSCallback(Cb_HandleMovingMonFromParty);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_PlaceMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CDC38(1);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CDCAC())
        {
            if (sInPartyMenu)
                SetPSSCallback(Cb_HandleMovingMonFromParty);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_ShiftMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CDC38(2);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CDCAC())
        {
            BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_WithdrawMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
        {
            PrintStorageActionText(PC_TEXT_PARTY_FULL);
            gUnknown_02039D08->state = 1;
        }
        else
        {
            sub_80CDC18();
            sub_80CDC38(0);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        if (!sub_80CDCAC())
        {
            sub_80CC0D4(1);
            sub_80CAB4C();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!sub_80CAB70())
        {
            sub_80CDC38(1);
            gUnknown_02039D08->state++;
        }
        break;
    case 4:
        if (!sub_80CDCAC())
        {
            sub_80CAB20();
            gUnknown_02039D08->state++;
        }
        break;
    case 5:
        SetPSSCallback(Cb_HidePartyPokemon);
        break;
    }
}

void Cb_DepositMenu(u8 taskId)
{
    u8 r4;

    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_DEPOSIT_IN_WHICH_BOX);
        sub_80C77E8(&gUnknown_02039D08->field_1E5C, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(gUnknown_02039D0E);
        gUnknown_02039D08->state++;
        break;
    case 1:
        r4 = sub_80C78F0();
        if (r4 == 200);
        else if (r4 == 201)
        {
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            SetPSSCallback(Cb_MainPSS);
        }
        else
        {
            if (sub_80CE19C(r4))
            {
                gUnknown_02039D0E = r4;
                ClearBottomWindow();
                sub_80C78E4();
                sub_80C7890();
                gUnknown_02039D08->state = 2;
            }
            else
            {
                PrintStorageActionText(PC_TEXT_BOX_IS_FULL);
                gUnknown_02039D08->state = 4;
            }
        }
        break;
    case 2:
        CompactPartySlots();
        sub_80CB950();
        gUnknown_02039D08->state++;
        break;
    case 3:
        if (!sub_80CB9BC())
        {
            sub_80CE22C();
            BoxSetMosaic();
            sub_80CAB20();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(PC_TEXT_DEPOSIT_IN_WHICH_BOX);
            gUnknown_02039D08->state = 1;
        }
        break;
    }
}

void Cb_ReleaseMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_RELEASE_POKE);
        sub_80CAD9C(1);
        gUnknown_02039D08->state++;
        // fallthrough
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
            case -1:
            case  1:
                ClearBottomWindow();
                SetPSSCallback(Cb_MainPSS);
                break;
            case  0:
                ClearBottomWindow();
                sub_80CE3A0();
                sub_80CE250();
                gUnknown_02039D08->state++;
                break;
        }
        break;
    case 2:
        sub_80CE580();
        if (!sub_80CE2A8())
        {
            while (1)
            {
                s8 r0 = sub_80CE580();
                if (r0 == 1)
                {
                    gUnknown_02039D08->state++;
                    break;
                }
                if (r0 == 0)
                {
                    gUnknown_02039D08->state = 8;
                    break;
                }
            }
        }
        break;
    case 3:
        sub_80CE2D8();
        sub_80CA230();
        PrintStorageActionText(PC_TEXT_WAS_RELEASED);
        gUnknown_02039D08->state++;
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(PC_TEXT_BYE_BYE);
            gUnknown_02039D08->state++;
        }
        break;
    case 5:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            if (sInPartyMenu)
            {
                CompactPartySlots();
                sub_80CB950();
                gUnknown_02039D08->state++;
            }
            else
            {
                gUnknown_02039D08->state = 7;
            }
        }
        break;
    case 6:
        if (!sub_80CB9BC())
        {
            sub_80CE00C();
            BoxSetMosaic();
            sub_80CAB20();
            gUnknown_02039D08->state++;
        }
        break;
    case 7:
        SetPSSCallback(Cb_MainPSS);
        break;
    case 8:
        PrintStorageActionText(PC_TEXT_WAS_RELEASED);
        gUnknown_02039D08->state++;
        break;
    case 9:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(PC_TEXT_SURPRISE);
            gUnknown_02039D08->state++;
        }
        break;
    case 10:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_80CC064();
            gUnknown_02039D08->state++;
        }
        break;
    case 11:
        if (!sub_80CC0A0())
        {
            sub_80CE324();
            PrintStorageActionText(PC_TEXT_CAME_BACK);
            gUnknown_02039D08->state++;
        }
        break;
    case 12:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(PC_TEXT_WORRIED);
            gUnknown_02039D08->state++;
        }
        break;
    case 13:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_ShowMarkMenu(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_MARK_POKE);
        gUnknown_02039D08->field_DA4.markings = gUnknown_02039D08->field_CEB;
        sub_811FAA4(gUnknown_02039D08->field_CEB, 0xb0, 0x10);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_811FBA4())
        {
            sub_811FAF8();
            ClearBottomWindow();
            sub_80CE9A8(gUnknown_02039D08->field_DA4.markings);
            sub_80CA230();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_TakeItemForMoving(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!ItemIsMail(gUnknown_02039D08->selectedItem))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        sub_80D0E90((sInPartyMenu != FALSE), GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            ClearBottomWindow();
            sub_80CE00C();
            sub_80CA4FC();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_GiveMovingItemToMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        ClearBottomWindow();
        gUnknown_02039D08->state++;
        break;
    case 1:
        sub_80CFE54(2);
        sub_80D1080((sInPartyMenu != FALSE), GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            sub_80CE00C();
            sub_80CA4FC();
            PrintStorageActionText(PC_TEXT_ITEM_IS_HELD);
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ItemToBag(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!AddBagItem(gUnknown_02039D08->selectedItem, 1))
        {
            PlaySE(SE_HAZURE);
            PrintStorageActionText(PC_TEXT_BAG_FULL);
            gUnknown_02039D08->state = 3;
        }
        else
        {
            PlaySE(SE_SELECT);
            sub_80D1114((sInPartyMenu != FALSE), GetBoxCursorPosition());
            gUnknown_02039D08->state = 1;
        }
        break;
    case 1:
        if (!sub_80D1218())
        {
            PrintStorageActionText(PC_TEXT_PLACED_IN_BAG);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_80CE00C();
            sub_80CA4FC();
            gUnknown_02039D08->state = 4;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_SwitchSelectedItem(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!ItemIsMail(gUnknown_02039D08->selectedItem))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        sub_80D0FAC((sInPartyMenu != FALSE), GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            sub_80CE00C();
            sub_80CA4FC();
            PrintStorageActionText(PC_TEXT_CHANGED_TO_ITEM);
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ShowItemInfo(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        ClearBottomWindow();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_WIN_OPEN);
            sub_80D17B4();
            sub_80D1818();
            gUnknown_02039D08->state++;
        }
        break;
    case 2:
        if (!sub_80D184C())
            gUnknown_02039D08->state++;
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02039D08->state++;
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PlaySE(SE_WIN_OPEN);
            gUnknown_02039D08->state++;
        }
        break;
    case 5:
        if (!sub_80D18E4())
            gUnknown_02039D08->state++;
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_CloseBoxWhileHoldingItem(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintStorageActionText(PC_TEXT_PUT_IN_BAG);
        sub_80CAD9C(0);
        gUnknown_02039D08->state = 1;
        break;
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case -1:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            if (AddBagItem(gUnknown_02039D08->movingItem, 1) == TRUE)
            {
                ClearBottomWindow();
                gUnknown_02039D08->state = 3;
            }
            else
            {
                PrintStorageActionText(PC_TEXT_BAG_FULL);
                gUnknown_02039D08->state = 2;
            }
            break;
        }
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state = 5;
        }
        break;
    case 3:
        sub_80D1194();
        gUnknown_02039D08->state = 4;
        break;
    case 4:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_HandleMovingMonFromParty(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        CompactPartySlots();
        sub_80CB950();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80CB9BC())
        {
            sub_80CAB20();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_PrintCantStoreMail(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_CANT_STORE_MAIL);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02039D08->state++;
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_HandleBoxOptions(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_WHAT_YOU_DO);
        sub_80CFFD0();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (sub_80D00A8())
            return;
        gUnknown_02039D08->state++;
    case 2:
        switch (sub_80D00AC())
        {
        case -1:
        case  0:
            sub_80CD1A8(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 11:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_NameBox);
            break;
        case 10:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_HandleWallpapers);
            break;
        case 9:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_JumpBox);
            break;
        }
        break;
    }
}

void Cb_HandleWallpapers(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CADD8();
        PrintStorageActionText(PC_TEXT_PICK_A_THEME);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_80D00A8())
             gUnknown_02039D08->state++;
        break;
    case 2:
        gUnknown_02039D08->wallpaperSetId = sub_80D00AC();
        switch (gUnknown_02039D08->wallpaperSetId)
        {
        case -1:
            sub_80CD1A8(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 18 ... 21:
            PlaySE(SE_SELECT);
            sub_80D013C();
            gUnknown_02039D08->wallpaperSetId -= 18;
            gUnknown_02039D08->state++;
            break;
        // New wallpaper from Walda.
        case 22:
            PlaySE(SE_SELECT);
            gUnknown_02039D08->wallpaperId = 16;
            sub_80D013C();
            ClearBottomWindow();
            gUnknown_02039D08->state = 6;
            break;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80CAE0C(gUnknown_02039D08->wallpaperSetId);
            PrintStorageActionText(PC_TEXT_PICK_A_WALLPAPER);
            gUnknown_02039D08->state++;
        }
        break;
    case 4:
        gUnknown_02039D08->wallpaperId = sub_80D00AC();
        switch (gUnknown_02039D08->wallpaperId)
        {
        case -2:
            break;
        case -1:
            ClearBottomWindow();
            gUnknown_02039D08->state = 0;
            break;
        default:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            gUnknown_02039D08->wallpaperId -= 23;
            SetWallpaperForCurrentBox(gUnknown_02039D08->wallpaperId);
            gUnknown_02039D08->state++;
            break;
        }
        break;
    case 5:
        if (!DoWallpaperGfxChange())
        {
            sub_80CD1A8(TRUE);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetWallpaperForCurrentBox(gUnknown_02039D08->wallpaperId);
            gUnknown_02039D08->state = 5;
        }
        break;
    }
}

void Cb_JumpBox(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_JUMP_TO_WHICH_BOX);
        sub_80C77E8(&gUnknown_02039D08->field_1E5C, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(StorageGetCurrentBox());
        gUnknown_02039D08->state++;
        break;
    case 1:
        gUnknown_02039D08->newCurrBoxId = sub_80C78F0();
        switch (gUnknown_02039D08->newCurrBoxId)
        {
        case 200:
            break;
        default:
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            if (gUnknown_02039D08->newCurrBoxId == 201 || gUnknown_02039D08->newCurrBoxId == StorageGetCurrentBox())
            {
                sub_80CD1A8(TRUE);
                SetPSSCallback(Cb_MainPSS);
            }
            else
            {
                gUnknown_02039D08->state++;
            }
            break;
        }
        break;
    case 2:
        sub_80CC464(gUnknown_02039D08->newCurrBoxId);
        gUnknown_02039D08->state++;
        break;
    case 3:
        if (!ScrollToBox())
        {
            SetCurrentBox(gUnknown_02039D08->newCurrBoxId);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_NameBox(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CE760();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_02039D0F = 1;
            gUnknown_02039D08->screenChangeType = SCREEN_CHANGE_NAME_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_ShowMonSummary(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        sub_80CE7E8();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_02039D0F = 0;
            gUnknown_02039D08->screenChangeType = SCREEN_CHANGE_SUMMARY_SCREEN;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_GiveItemFromBag(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_02039D0F = 2;
            gUnknown_02039D08->screenChangeType = SCREEN_CHANGE_ITEM_FROM_BAG;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_OnCloseBoxPressed(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_HAZURE);
            PrintStorageActionText(PC_TEXT_HOLDING_POKE);
            gUnknown_02039D08->state = 1;
        }
        else if (sub_80D127C())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintStorageActionText(PC_TEXT_EXIT_BOX);
            sub_80CAD9C(0);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 1:
        case -1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            gUnknown_02039D08->state++;
            break;
        }
        break;
    case 3:
        sub_80F9BF4(0x14, 0, 1);
        gUnknown_02039D08->state++;
        break;
    case 4:
        if (!sub_80F9C30())
        {
            sub_80CABE0();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            gUnknown_02039D08->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_OnBPressed(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_HAZURE);
            PrintStorageActionText(PC_TEXT_HOLDING_POKE);
            gUnknown_02039D08->state = 1;
        }
        else if (sub_80D127C())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintStorageActionText(PC_TEXT_CONTINUE_BOX);
            sub_80CAD9C(0);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 0:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 1:
        case -1:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            gUnknown_02039D08->state++;
            break;
        }
        break;
    case 3:
        sub_80F9BF4(0x14, 0, 0);
        gUnknown_02039D08->state++;
        break;
    case 4:
        if (!sub_80F9C30())
        {
            sub_80CABE0();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            gUnknown_02039D08->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_ChangeScreen(u8 taskId)
{
    struct BoxPokemon *boxMons;
    u8 mode, monIndex, maxMonIndex;
    u8 screenChangeType = gUnknown_02039D08->screenChangeType;

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS && sub_80D127C() == TRUE)
        gUnknown_02039D12 = GetMovingItem();
    else
        gUnknown_02039D12 = 0;

    switch (screenChangeType)
    {
    case SCREEN_CHANGE_EXIT_BOX:
    default:
        FreePSSData();
        SetMainCallback2(Cb2_ExitPSS);
        break;
    case SCREEN_CHANGE_SUMMARY_SCREEN:
        boxMons = gUnknown_02039D08->field_218C;
        monIndex = gUnknown_02039D08->field_2187;
        maxMonIndex = gUnknown_02039D08->field_2186;
        mode = gUnknown_02039D08->field_2188;
        FreePSSData();
        if (mode == PSS_MODE_NORMAL && boxMons == &gUnknown_02039D14.box)
            ShowPokemonSummaryScreenSet40EF(mode, boxMons, monIndex, maxMonIndex, Cb2_ReturnToPSS);
        else
            ShowPokemonSummaryScreen(mode, boxMons, monIndex, maxMonIndex, Cb2_ReturnToPSS);
        break;
    case SCREEN_CHANGE_NAME_BOX:
        FreePSSData();
        DoNamingScreen(NAMING_SCREEN_BOX, GetBoxNamePtr(StorageGetCurrentBox()), 0, 0, 0, Cb2_ReturnToPSS);
        break;
    case SCREEN_CHANGE_ITEM_FROM_BAG:
        FreePSSData();
        GoToBagMenu(11, 0, Cb2_ReturnToPSS);
        break;
    }

    DestroyTask(taskId);
}

void GiveChosenBagItem(void)
{
    u16 item = gSpecialVar_ItemId;

    if (item != 0)
    {
        u8 id = GetBoxCursorPosition();

        if (sInPartyMenu)
            SetMonData(&gPlayerParty[id], MON_DATA_HELD_ITEM, &item);
        else
            SetCurrentBoxMonData(id, MON_DATA_HELD_ITEM, &item);

        RemoveBagItem(item, 1);
    }
}

void FreePSSData(void)
{
    sub_80D25F0();
    sub_80D01B8();
    FREE_AND_SET_NULL(gUnknown_02039D08);
    FreeAllWindowBuffers();
}

void SetScrollingBackground(void)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(31));
    DecompressAndLoadBgGfxUsingHeap(3, gPokemonStorageScrollingBGTileset, 0, 0, 0);
    LZ77UnCompVram(gPokemonStorageScrollingBGTilemap, (void *)VRAM + 0xF800);
}

void ScrollBackground(void)
{
    ChangeBgX(3, 128, 1);
    ChangeBgY(3, 128, 2);
}

void LoadPSSMenuGfx(void)
{
    InitBgsFromTemplates(0, gUnknown_08572734, ARRAY_COUNT(gUnknown_08572734));
    DecompressAndLoadBgGfxUsingHeap(1, gPSSMenu_Gfx, 0, 0, 0);
    LZ77UnCompWram(gUnknown_085722A0, gUnknown_02039D08->field_5AC4);
    SetBgTilemapBuffer(1, gUnknown_02039D08->field_5AC4);
    ShowBg(1);
    schedule_bg_copy_tilemap_to_vram(1);
}

bool8 InitPSSWindows(void)
{
    if (!InitWindows(gUnknown_08572714))
    {
        return FALSE;
    }
    else
    {
        DeactivateAllTextPrinters();
        return TRUE;
    }
}

void LoadWaveformSpritePalette(void)
{
    LoadSpritePalette(&gWaveformSpritePalette);
}

void sub_80CA0D8(void)
{
    LoadPalette(gUnknown_085723DC, 0, 0x20);
    LoadPalette(gUnknown_085723FC, 0x20, 0x20);
    LoadPalette(gUnknown_085726F4, 0xF0, 0x20);
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        LoadPalette(gUnknown_0857241C, 0x30, 0x20);
    else
        LoadPalette(gUnknown_0857243C, 0x30, 0x20);

    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(30));
    sub_80CA318();
    sub_80CA154();
    sub_80CA1C4();
    sub_80CA230();
}

void sub_80CA154(void)
{
    gUnknown_02039D08->field_D94 = sub_811FFB4(TAG_TILE_10, TAG_PAL_DAC8, NULL);
    gUnknown_02039D08->field_D94->oam.priority = 1;
    gUnknown_02039D08->field_D94->subpriority = 1;
    gUnknown_02039D08->field_D94->pos1.x = 40;
    gUnknown_02039D08->field_D94->pos1.y = 150;
    gUnknown_02039D08->field_DA0 = (void*) OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_TILE_10);
}

void sub_80CA1C4(void)
{
    u16 i;
    struct SpriteSheet sheet = gWaveformSpriteSheet;

    LoadSpriteSheet(&sheet);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_085728BC, i * 63 + 8, 9, 2);
        gUnknown_02039D08->field_D98[i] = &gSprites[spriteId];
    }
}
