#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "data2.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
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
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "walda_phrase.h"
#include "window.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

struct WallpaperTable
{
    const u32 *tiles;
    const u32 *tileMap;
    const u16 *palettes;
};

struct Struct_02039D80
{
    u8 field_0;
    u8 state;
    u8 fromRow;
    u8 fromColumn;
    u8 toRow;
    u8 toColumn;
    u8 field_6;
    u8 field_7;
    u8 minRow;
    u8 minColumn;
    u8 rowsTotal;
    u8 columsTotal;
    u16 bgX;
    u16 bgY;
    u16 field_10;
    struct BoxPokemon boxMons[IN_BOX_COUNT];
};

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
    PC_TEXT_FMT_NORMAL,
    PC_TEXT_FMT_MON_NAME_1,
    PC_TEXT_FMT_MON_NAME_2,
    PC_TEXT_FMT_MON_NAME_3,
    PC_TEXT_FMT_MON_NAME_4,
    PC_TEXT_FMT_MON_NAME_5,
    PC_TEXT_FMT_MON_NAME_6,
    PC_TEXT_FMT_ITEM_NAME,
};

enum
{
    SCREEN_CHANGE_EXIT_BOX,
    SCREEN_CHANGE_SUMMARY_SCREEN,
    SCREEN_CHANGE_NAME_BOX,
    SCREEN_CHANGE_ITEM_FROM_BAG,
};

enum
{
    MODE_PARTY,
    MODE_BOX,
    MODE_2,
};

enum
{
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
};

enum
{
    CURSOR_AREA_IN_BOX,
    CURSOR_AREA_IN_PARTY,
    CURSOR_AREA_BOX,
    CURSOR_AREA_BUTTONS, // Party Pokemon and Close Box
};

#define TAG_PAL_WAVEFORM    0xDACA
#define TAG_PAL_DAC8        0xDAC8
#define TAG_PAL_DAC6        0xDAC6
#define TAG_PAL_DACE        0xDACE
#define TAG_PAL_DAC7        0xDAC7
#define TAG_PAL_DAC9        0xDAC9

#define TAG_TILE_WAVEFORM   0x5
#define TAG_TILE_10         0x10
#define TAG_TILE_2          0x2
#define TAG_TILE_D          0xD
#define TAG_TILE_A          0xA
#define TAG_TILE_3          0x3
#define TAG_TILE_4          0x4

IWRAM_DATA u32 gUnknown_03000F78[98];

// EWRAM DATA
extern u8 sPreviousBoxOption;
extern u8 sCurrentBoxOption;
extern u8 sMovingMonOrigBoxPos;
extern u8 sMovingMonOrigBoxId;
extern s8 sBoxCursorPosition;
extern s8 sBoxCursorArea;
extern u8 gUnknown_02039D10;
extern u8 gUnknown_02039D7E;
extern u8 gUnknown_02039D0E;
extern bool8 sInPartyMenu;
extern bool8 sCanOnlyMove;
extern bool8 sIsMonBeingMoved;
extern u8 gUnknown_02039D0F;
extern u16 gUnknown_02039D12;
extern struct Pokemon gUnknown_02039D14;
extern struct Struct_02039D80 *gUnknown_02039D80;

extern void sub_80F9BCC(u16, u16, u8);
extern void sub_80F9BF4(u16, u16, u8);
extern bool8 sub_80F9C1C(void);
extern bool8 sub_80F9C30(void);

extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern const u8 gText_PartyFull[];
extern const u8 gText_Box[];
extern const u8 gText_JustOnePkmn[];

// This file's functions.
void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr);
void Cb2_EnterPSS(u8 boxOption);
u8 GetCurrentBoxOption(void);
static u8 HandleInput(void);
u8 sub_80CDC2C(void);
u8 sub_80CB9BC(void);
void LoadWallpaperGfx(u8 boxId, s8 direction);
static void sub_80CCCFC(u8 boxId, s8 direction);
static void sub_80CD0B8(s8 direction);
void SetBoxWallpaper(u8 boxId, u8 wallpaperId);
void SetCurrentBox(u8 boxId);
static void sub_80CC32C(u8 boxId);
void ZeroBoxMonAt(u8 boxId, u8 boxPos);
static void sub_80C7958(u8 curBox);
static void sub_80CCAE0(void *arg0);
void ResetWaldaWallpaper(void);
static void sub_80C7B14(void);
static void sub_80C7BB4(void);
void ScrollBackground(void);
static void sub_80C7B80(void);
void sub_80D2AA4(void);
static void sub_80C7BE4(void);
static void sub_80CAA14(void);
static void sub_80CFDC4(void);
static void sub_80CE790(void);
static void sub_80CE8E4(void);
void GiveChosenBagItem(void);
static void SetUpHidePartyMenu(void);
static void DestroyAllPartyMonIcons(void);
void sub_80D11CC(void);
void LoadPSSMenuGfx(void);
void LoadWaveformSpritePalette(void);
static void sub_80CDC18(void);
static void sub_80CD36C(void);
static void sub_80CD3EC(void);
static void sub_80CAC1C(void);
static void sub_80CEBDC(void);
static void SetScrollingBackground(void);
static void sub_80CABE0(void);
static void sub_80CAEAC(void);
void sub_80D0C60(void);
void sub_80CFEA8(void);
static void sub_80CDC0C(void);
static void sub_80CAF04(void);
static void sub_80CA0D8(void);
static void AddMenu(void);
static void sub_80CE250(void);
void InitCanRelaseMonVars(void);
void sub_80D01B8(void);
void ReleaseMon(void);
void sub_80D25F0(void);
void RefreshCursorMonData(void);
void LoadCursorMonSprite(void);
static void sub_80CA154(void);
static void sub_80CA1C4(void);
static void sub_80CC064(void);
static void sub_80CE324(void);
void ClearBottomWindow(void);
static void sub_80CA704(void);
void sub_80D013C(void);
static void sub_80CE00C(void);
void sub_80D1194(void);
static void PrintCursorMonInfo(void);
static void sub_80CA65C(void);
static void AddWallpaperSetsMenu(void);
static void sub_80CD02C(void);
static void InitMenu(void);
static void sub_80CD158(void);
void sub_80CFC14(void);
static void sub_80CEB40(void);
static void sub_80CCEE0(void);
void sub_80D1818(void);
static void sub_80CAA74(void);
void sub_80D17B4(void);
static void sub_80CE760(void);
static void sub_80CDBA0(void);
static void sub_80CE7E8(void);
void sub_80CFECC(void);
static void sub_80CA9EC(void);
void FreePSSData(void);
static void AddBoxMenu(void);
static void sub_80CCF9C(void);
void MoveMon(void);
void PlaceMon(void);
static void sub_80CAB20(void);
static void sub_80CE22C(void);
static void sub_80CDA68(void);
static void sub_80CB950(void);
static void sub_80CA9C0(void);
static void SetUpDoShowPartyMenu(void);
void BoxSetMosaic(void);
static void sub_80C7CF4(struct Sprite *sprite);
static void sub_80CC100(struct Sprite *sprite);
static void sub_80CB278(struct Sprite *sprite);
static void sub_80CD210(struct Sprite *sprite);
bool32 WaitForWallpaperGfxLoad(void);
bool8 InitPSSWindows(void);
static bool8 sub_80CC0A0(void);
static bool8 sub_80CE2A8(void);
bool8 sub_80D0164(void);
static bool8 sub_80CC35C(void);
bool8 sub_80D01E4(void);
static bool8 sub_80CDED4(void);
static bool8 sub_80CDF08(void);
bool8 sub_80D184C(void);
bool8 sub_80D18E4(void);
static bool8 DoShowPartyMenu(void);
bool8 sub_80D1218(void);
bool8 ScrollToBox(void);
bool8 sub_80CD554(void);
static bool8 HidePartyMenu(void);
bool8 sub_80D127C(void);
bool8 sub_80D0580(u8 arg0);
bool8 sub_80D0BC0(void);
static bool8 sub_80CA2B8(void);
static bool8 DoWallpaperGfxChange(void);
bool8 DoMonPlaceChange(void);
bool8 sub_80D00A8(void);
static bool8 CanMovePartyMon(void);
static bool8 CanShifMon(void);
static bool8 IsCursorOnCloseBox(void);
static bool8 IsCursorOnBox(void);
static bool8 IsCursorInBox(void);
static bool8 IsMonBeingMoved(void);
static bool8 TryStorePartyMonInBox(u8 boxId);
static void Cb_InitPSS(u8 taskId);
static void Cb_PlaceMon(u8 taskId);
static void Cb_ChangeScreen(u8 taskId);
static void Cb_ShowPSS(u8 taskId);
static void Cb_OnBPressed(u8 taskId);
static void Cb_HandleBoxOptions(u8 taskId);
static void Cb_OnSelectedMon(u8 taskId);
static void Cb_OnCloseBoxPressed(u8 taskId);
static void Cb_HidePartyPokemon(u8 taskId);
static void Cb_DepositMenu(u8 taskId);
static void Cb_MoveMon(u8 taskId);
static void Cb_GiveMovingItemToMon(u8 taskId);
static void Cb_SwitchSelectedItem(u8 taskId);
static void Cb_TakeItemForMoving(u8 taskId);
static void Cb_WithdrawMon(u8 taskId);
static void Cb_ShiftMon(u8 taskId);
static void Cb_ShowPartyPokemon(u8 taskId);
static void Cb_ShowItemInfo(u8 taskId);
static void Cb_GiveItemFromBag(u8 taskId);
static void Cb_ItemToBag(u8 taskId);
static void Cb_TakeItemForMoving(u8 taskId);
static void Cb_ShowMarkMenu(u8 taskId);
static void Cb_ShowMonSummary(u8 taskId);
static void Cb_ReleaseMon(u8 taskId);
static void Cb_ReshowPSS(u8 taskId);
static void Cb_MainPSS(u8 taskId);
static void Cb_JumpBox(u8 taskId);
static void Cb_HandleWallpapers(u8 taskId);
static void Cb_NameBox(u8 taskId);
static void Cb_PrintCantStoreMail(u8 taskId);
static void Cb_HandleMovingMonFromParty(u8 taskId);
void sub_80D2A90(struct UnkStruct_2000020 *arg0, struct UnkStruct_2000028 *arg1, u32 arg2);
void sub_80D259C(u8 arg0);
static void SetUpScrollToBox(u8 boxId);
void sub_80CFE54(u8 animNum);
void sub_80D2918(u8 arg0);
static void SetMovingMonPriority(u8 priority);
void InitMonPlaceChange(u8 arg0);
static void SetMonMarkings(u8 markings);
void ShowYesNoWindow(s8 cursorPos);
static void sub_80CDBF8(u8 cursorBoxPosition);
void sub_80D01D0(u8 arg0);
static void sub_80CD1A8(bool8 arg0);
static void sub_80CA984(bool8 arg0);
void CreatePartyMonsSprites(bool8 arg0);
void sub_80D2644(u8 arg0, u16 arg1, const void *arg2, u16 arg3, u16 arg4);
void sub_80D2770(u8 arg0, u16 arg1, u16 arg2);
void PrintStorageActionText(u8 id);
s16 sub_80D00AC(void);
s8 RunCanReleaseMon(void);
u8 GetBoxCursorPosition(void);
static void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos);
static void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos);
static void Item_TakeMons(u8 cursorArea, u8 cursorPos);
static void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos);
struct Sprite *sub_80CD2E8(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority);
static void SetWallpaperForCurrentBox(u8 wallpaperId);
static void AddWallpapersMenu(u8 wallpaperSet);
u16 GetMovingItem(void);
void SetCurrentBoxMonData(u8 monId, s32 request, const void *value);
s32 GetCurrentBoxMonData(u8 boxPosition, s32 request);
void LoadCursorMonGfx(u16 species, u32 pid);
static void sub_80CA2D0(struct Sprite *sprite);
static void sub_80CCF64(struct Sprite *sprite);
static void sub_80CBA3C(struct Sprite *sprite);
static void sub_80CCF30(struct Sprite *sprite);
void sub_80D27AC(u8 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
void sub_80D27F4(u8 arg0, u8 arg1, s8 arg2);
static void sub_80CBAF0(s16 yDelta);
static void sub_80CAAA8(u8 arg0, bool8 isPartyMon);
const u8 *GetMovingItemName(void);
bool32 IsWaldaWallpaperUnlocked(void);
static void SetMenuText(u8 textId);
void sub_80D0D8C(u8 cursorArea, u8 cursorPos);
void sub_80D0E50(u8 cursorArea, u8 cursorPos);
void sub_80D0F38(u16 item);
static struct Sprite *CreateMonIconSprite(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority);
static void DestroyBoxMonIcon(struct Sprite *sprite);
static void SetBoxSpeciesAndPersonalities(u8 boxId);
static void sub_80CB9D0(struct Sprite *sprite, u16 partyId);
static void sub_80CC370(u8 taskId);
static void sub_80CCB50(u8 boxId);
s8 sub_80CC644(u8 boxId);
u8 GetBoxWallpaper(u8 boxId);
u32 GetWaldaWallpaperPatternId(void);
u32 GetWaldaWallpaperIconId(void);
static void sub_80CCA3C(const void *tilemap, s8 direction, u8 arg2);
u16 *GetWaldaWallpaperColorsPtr(void);
void sub_80C6D80(u8 *arg0, void *arg1, u8 arg2, u8 arg3, s32 arg4);
static s16 sub_80CD00C(const u8 *string);
static bool8 MonPlaceChange_Shift(void);
static bool8 MonPlaceChange_Move(void);
static bool8 MonPlaceChange_Place(void);
static bool8 sub_80CDEC4(void);
static bool8 sub_80CDEB4(void);
void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y);
static void SetShiftedMonData(u8 boxId, u8 position);
static void SetMovedMonData(u8 boxId, u8 position);
static void SetPlacedMonData(u8 boxId, u8 position);
void PurgeMonOrBoxMon(u8 boxId, u8 position);
void BoxMonAtToMon(u8 boxId, u8 position, struct Pokemon *dst);
void SetBoxMonAt(u8 boxId, u8 position, struct BoxPokemon *src);
static void SetCursorMonData(void *pokemon, u8 mode);
bool32 AtLeastThreeUsableMons(void);
bool32 CheckBoxedMonSanity(s32 boxId, s32 boxPosition);
s32 GetAndCopyBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, void *dst);
static u8 InBoxInput_Normal(void);
static u8 InBoxInput_MovingMultiple(void);
static u8 InBoxInput_GrabbingMultiple(void);
s8 sub_80CFF98(u8 arg0);
u8 sub_80CFA5C(void);
u8 sub_80D0BA4(void);
static bool8 sub_80CFA84(void);
static bool8 sub_80CFB44(void);
bool8 sub_80D024C(void);
bool8 sub_80D0344(void);
bool8 sub_80D03B0(void);
bool8 sub_80D0420(void);
bool8 sub_80D04A0(void);
bool8 sub_80D04C8(void);
void sub_80D304C(u16 palIndex);
void sub_80D07B0(u8 arg0, u8 arg1);
void sub_80D0834(u8 arg0, u8 arg1);
void sub_80D0B5C(void);
void sub_80D062C(void);
void sub_80D0884(u16 arg0, u16 arg1, u16 arg2);
void sub_80D08CC(void);
void sub_80D09A4(void);
void sub_80D0A1C(void);
void sub_80D0AAC(void);
u8 sub_80D0894(void);
void sub_80D0778(u8 arg0, u8 arg1, u8 arg2);
void sub_80D0708(u8 arg0, u8 arg1, u8 arg2);
void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2);
void sub_80D0740(u8 arg0, u8 arg1, u8 arg2);

// static const rom data
static const struct PSS_MenuStringPtrs gUnknown_085716C0[] =
{
    {gText_WithdrawPokemon, gText_WithdrawMonDescription},
    {gText_DepositPokemon, gText_DepositMonDescription},
    {gText_MovePokemon, gText_MoveMonDescription},
    {gText_MoveItems, gText_MoveItemsDescription},
    {gText_SeeYa, gText_SeeYaDescription}
};

static const struct WindowTemplate gUnknown_085716E8 =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const union AnimCmd sSpriteAnim_85716F0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85716F8[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571700[] =
{
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8571708[] =
{
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8571710[] =
{
    sSpriteAnim_85716F0,
    sSpriteAnim_85716F8,
    sSpriteAnim_8571700,
    sSpriteAnim_8571708
};

static const union AffineAnimCmd sSpriteAffineAnim_8571720[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_8571730[] =
{
    sSpriteAffineAnim_8571720
};

static const u8 gUnknown_08571734[] = {4, 0xF, 0xE};
static const u8 gUnknown_08571737[] = _("/30");

static const u16 gBoxSelectionPopupPalette[] = INCBIN_U16("graphics/unknown/unknown_57173C.gbapal");
static const u8 gBoxSelectionPopupCenterTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_center.4bpp");
static const u8 gBoxSelectionPopupSidesTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_sides.4bpp");
static const u32 gPokemonStorageScrollingBGTileset[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.4bpp.lz");
static const u32 gPokemonStorageScrollingBGTilemap[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.bin.lz");
static const u32 gUnknown_08572280[] = INCBIN_U32("graphics/unknown/unknown_572280.gbapal");
static const u32 gUnknown_085722A0[] = INCBIN_U32("graphics/unknown/unknown_5722A0.bin.lz");

static const u16 gUnknown_0857239C[] =
{
    0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0111, 0x0112, 0x0113, 0x0114, 0x0115, 0x0116, 0x0117, 0x0118,
    0x2101, 0x2102, 0x2103, 0x2104, 0x2105, 0x2106, 0x2107, 0x2108, 0x2111, 0x2112, 0x2113, 0x2114, 0x2115, 0x2116, 0x2117, 0x2118,
};

static const u16 gUnknown_085723DC[] = INCBIN_U16("graphics/unknown/unknown_5723DC.gbapal"); // Left-most part and Close Box.
static const u16 gUnknown_085723FC[] = INCBIN_U16("graphics/unknown/unknown_5723FC.gbapal");
static const u16 gUnknown_0857241C[] = INCBIN_U16("graphics/unknown/unknown_57241C.gbapal");
static const u16 gUnknown_0857243C[] = INCBIN_U16("graphics/unknown/unknown_57243C.gbapal");

static const u16 gUnknown_0857245C[] =
{
    0x014c, 0x014d, 0x014e, 0x014f, 0x0170, 0x0171, 0x0172, 0x0173, 0x0174, 0x015c, 0x015d, 0x015e, 0x015f, 0x0180, 0x0181, 0x0182,
	0x0183, 0x0184, 0x0175, 0x0176, 0x0177, 0x0178, 0x0179, 0x017a, 0x017b, 0x017c, 0x017d, 0x0185, 0x0186, 0x0187, 0x0188, 0x0189,
	0x018a, 0x018b, 0x018c, 0x018d
};
static const u16 gUnknown_085724A4[] =
{
    0x1140, 0x1141, 0x1141, 0x1142, 0x1150, 0x1151, 0x1151, 0x1152, 0x1160, 0x1161, 0x1161, 0x1162,
};
static const u16 gUnknown_085724BC[] =
{
    0x1143, 0x1144, 0x1144, 0x1145, 0x1153, 0x1154, 0x1154, 0x1155, 0x1163, 0x1164, 0x1164, 0x1165,
};

static const u16 gWaveformPalette[] = INCBIN_U16("graphics/pokemon_storage/waveform.gbapal");
static const u32 gWaveformTiles[] = INCBIN_U32("graphics/pokemon_storage/waveform.4bpp");
static const u32 gUnknown_085726B4[] = INCBIN_U32("graphics/unused/unknown_5726B4.gbapal");
static const u32 gUnknown_085726F4[] = INCBIN_U32("graphics/unknown/unknown_5726F4.gbapal");

static const struct WindowTemplate gUnknown_08572714[] =
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

static const struct BgTemplate gUnknown_08572734[] =
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

static const struct SpritePalette gWaveformSpritePalette =
{
    gWaveformPalette, TAG_PAL_WAVEFORM
};

static const struct SpriteSheet gWaveformSpriteSheet =
{
    gWaveformTiles, sizeof(gWaveformTiles), TAG_TILE_WAVEFORM
};

static const struct OamData sOamData_857286C;
static const struct SpriteTemplate sSpriteTemplate_CursorMon =
{
    .tileTag = TAG_TILE_2,
    .paletteTag = TAG_PAL_DAC6,
    .oam = &sOamData_857286C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct StorageAction gPCStorageActionTexts[] =
{
    [PC_TEXT_EXIT_BOX] = {gText_ExitFromBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WHAT_YOU_DO] = {gText_WhatDoYouWantToDo, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PICK_A_THEME] = {gText_PleasePickATheme, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PICK_A_WALLPAPER] = {gText_PickTheWallpaper, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_IS_SELECTED] = {gText_PkmnIsSelected, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_JUMP_TO_WHICH_BOX] = {gText_JumpToWhichBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_DEPOSIT_IN_WHICH_BOX] = {gText_DepositInWhichBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WAS_DEPOSITED] = {gText_PkmnWasDeposited, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_BOX_IS_FULL] = {gText_BoxIsFull2, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_RELEASE_POKE] = {gText_ReleaseThisPokemon, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WAS_RELEASED] = {gText_PkmnWasReleased, PC_TEXT_FMT_MON_NAME_4},
    [PC_TEXT_BYE_BYE] = {gText_ByeByePkmn, PC_TEXT_FMT_MON_NAME_6},
    [PC_TEXT_MARK_POKE] = {gText_MarkYourPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_LAST_POKE] = {gText_ThatsYourLastPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PARTY_FULL] = {gText_YourPartysFull, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_HOLDING_POKE] = {gText_YoureHoldingAPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WHICH_ONE_WILL_TAKE] = {gText_WhichOneWillYouTake, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CANT_RELEASE_EGG] = {gText_YouCantReleaseAnEgg, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CONTINUE_BOX] = {gText_ContinueBoxOperations, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CAME_BACK] = {gText_PkmnCameBack, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_WORRIED] = {gText_WasItWorriedAboutYou, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_SURPRISE] = {gText_FourEllipsesExclamation, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PLEASE_REMOVE_MAIL] = {gText_PleaseRemoveTheMail, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_IS_SELECTED2] = {gText_PkmnIsSelected, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_GIVE_TO_MON] = {gText_GiveToAPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PLACED_IN_BAG] = {gText_PlacedItemInBag, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_BAG_FULL] = {gText_BagIsFull2, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PUT_IN_BAG] = {gText_PutItemInBag, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_ITEM_IS_HELD] = {gText_ItemIsNowHeld, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_CHANGED_TO_ITEM] = {gText_ChangedToNewItem, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_CANT_STORE_MAIL] = {gText_MailCantBeStored, PC_TEXT_FMT_NORMAL},
};

static const struct WindowTemplate sYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 11,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x5C,
};

static const struct OamData sOamData_857286C =
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

static const struct OamData sOamData_8572874 =
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

static const union AnimCmd sSpriteAnim_857287C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8572884[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_8572894[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857289C[] =
{
    ANIMCMD_FRAME(10, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_85728AC[] =
{
    sSpriteAnim_857287C,
    sSpriteAnim_8572884,
    sSpriteAnim_8572894,
    sSpriteAnim_857289C
};

static const struct SpriteTemplate gUnknown_085728BC =
{
    .tileTag = 5,
    .paletteTag = 0xDACA,
    .oam = &sOamData_8572874,
    .anims = sSpriteAnimTable_85728AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC;
static const struct SpriteTemplate gUnknown_085728D4 =
{
    .tileTag = 18,
    .paletteTag = 0xDAC0,
    .oam = &sOamData_85728EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC =
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

static const union AffineAnimCmd gSpriteAffineAnim_85728F4[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 120),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gSpriteAffineAnim_8572904[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_857291C[] =
{
    gSpriteAffineAnim_85728F4,
    gSpriteAffineAnim_8572904
};

static const u16 gWallpaperPalettes_Forest[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/forest_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/forest_bg.gbapal"),
};
static const u32 gWallpaperTiles_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.4bpp.lz");
static const u32 gWallpaperTilemap_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.bin.lz");

static const u16 gWallpaperPalettes_City[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/city_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/city_bg.gbapal"),
};
static const u32 gWallpaperTiles_City[] = INCBIN_U32("graphics/pokemon_storage/city.4bpp.lz");
static const u32 gWallpaperTilemap_City[] = INCBIN_U32("graphics/pokemon_storage/city.bin.lz");

static const u16 gWallpaperPalettes_Desert[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/desert_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/desert_bg.gbapal"),
};
static const u32 gWallpaperTiles_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.4bpp.lz");
static const u32 gWallpaperTilemap_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.bin.lz");

static const u16 gWallpaperPalettes_Savanna[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/savanna_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/savanna_bg.gbapal"),
};
static const u32 gWallpaperTiles_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.4bpp.lz");
static const u32 gWallpaperTilemap_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.bin.lz");

static const u16 gWallpaperPalettes_Crag[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/crag_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/crag_bg.gbapal"),
};
static const u32 gWallpaperTiles_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.4bpp.lz");
static const u32 gWallpaperTilemap_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.bin.lz");

static const u16 gWallpaperPalettes_Volcano[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/volcano_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/volcano_bg.gbapal"),
};
static const u32 gWallpaperTiles_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.4bpp.lz");
static const u32 gWallpaperTilemap_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.bin.lz");

static const u16 gWallpaperPalettes_Snow[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/snow_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/snow_bg.gbapal"),
};
static const u32 gWallpaperTiles_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.4bpp.lz");
static const u32 gWallpaperTilemap_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.bin.lz");

static const u16 gWallpaperPalettes_Cave[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/cave_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/cave_bg.gbapal"),
};
static const u32 gWallpaperTiles_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.4bpp.lz");
static const u32 gWallpaperTilemap_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.bin.lz");

static const u16 gWallpaperPalettes_Beach[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/beach_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/beach_bg.gbapal"),
};
static const u32 gWallpaperTiles_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.4bpp.lz");
static const u32 gWallpaperTilemap_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.bin.lz");

static const u16 gWallpaperPalettes_Seafloor[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/seafloor_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/seafloor_bg.gbapal"),
};
static const u32 gWallpaperTiles_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.4bpp.lz");
static const u32 gWallpaperTilemap_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.bin.lz");

static const u16 gWallpaperPalettes_River[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/river_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/river_bg.gbapal"),
};
static const u32 gWallpaperTiles_River[] = INCBIN_U32("graphics/pokemon_storage/river.4bpp.lz");
static const u32 gWallpaperTilemap_River[] = INCBIN_U32("graphics/pokemon_storage/river.bin.lz");
static const u16 gWallpaperPalettes_Sky[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/sky_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/sky_bg.gbapal"),
};
static const u32 gWallpaperTiles_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.4bpp.lz");
static const u32 gWallpaperTilemap_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.bin.lz");

static const u16 gWallpaperPalettes_PolkaDot[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/polkadot_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/polkadot_bg.gbapal"),
};
static const u32 gWallpaperTiles_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.4bpp.lz");
static const u32 gWallpaperTilemap_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.bin.lz");

static const u16 gWallpaperPalettes_Pokecenter[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/pokecenter_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/pokecenter_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.4bpp.lz");
static const u32 gWallpaperTilemap_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.bin.lz");

static const u16 gWallpaperPalettes_Machine[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/machine_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/machine_bg.gbapal"),
};
static const u32 gWallpaperTiles_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.4bpp.lz");
static const u32 gWallpaperTilemap_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.bin.lz");

static const u16 gWallpaperPalettes_Plain[][16] =
{
	INCBIN_U16("graphics/pokemon_storage/plain_frame.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/plain_bg.gbapal"),
};
static const u32 gWallpaperTiles_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.4bpp.lz");
static const u32 gWallpaperTilemap_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.bin.lz");

// 12×18 tilemap
static const u32 gUnknown_085773C4[] = INCBIN_U32("graphics/unused/tilemap_5773C4.bin");

static const u16 gUnknown_08577574[][2] =
{
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF}
};

#define WALLPAPER_ENTRY(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct WallpaperTable gWallpaperTable[] =
{
    [WALLPAPER_FOREST] = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY] = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT] = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA] = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG] = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO] = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW] = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE] = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH] = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR] = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER] = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY] = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT] = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE] = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN] = WALLPAPER_ENTRY(Plain),
};

static const u8 gPCGfx_Arrow[] = INCBIN_U8("graphics/pokemon_storage/arrow.4bpp");

static const u16 gWallpaperPalettes_Zigzagoon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 gWallpaperTiles_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/zigzagoon.4bpp.lz");
static const u32 gWallpaperTilemap_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/zigzagoon.bin.lz");

static const u16 gWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/screen_bg.gbapal"),
};
static const u32 gWallpaperTiles_Screen[] = INCBIN_U32("graphics/pokemon_storage/screen.4bpp.lz");
static const u32 gWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/screen.bin.lz");

static const u16 gWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/diagonal_bg.gbapal"),
};
static const u32 gWallpaperTiles_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/diagonal.4bpp.lz");
static const u32 gWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/diagonal.bin.lz");

static const u16 gWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
};
static const u32 gWallpaperTiles_Block[] = INCBIN_U32("graphics/pokemon_storage/block.4bpp.lz");
static const u32 gWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/block.bin.lz");

static const u16 gWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/pokecenter2.4bpp.lz");
static const u32 gWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/pokecenter2.bin.lz");

static const u16 gWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
};
static const u32 gWallpaperTiles_Frame[] = INCBIN_U32("graphics/pokemon_storage/frame.4bpp.lz");
static const u32 gWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/frame.bin.lz");

static const u16 gWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 gWallpaperTiles_Blank[] = INCBIN_U32("graphics/pokemon_storage/blank.4bpp.lz");
static const u32 gWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/blank.bin.lz");

static const u16 gWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/circles_bg.gbapal"),
};
static const u32 gWallpaperTiles_Circles[] = INCBIN_U32("graphics/pokemon_storage/circles.4bpp.lz");
static const u32 gWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/circles.bin.lz");

static const u16 gWallpaperPalettes_Azumarill[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/azumarill_bg.gbapal"),
};
static const u32 gWallpaperTiles_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/azumarill.4bpp.lz");
static const u32 gWallpaperTilemap_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/azumarill.bin.lz");

static const u16 gWallpaperPalettes_Pikachu[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/pikachu_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/pikachu.4bpp.lz");
static const u32 gWallpaperTilemap_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/pikachu.bin.lz");

static const u16 gWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/legendary_bg.gbapal"),
};
static const u32 gWallpaperTiles_Legendary[] = INCBIN_U32("graphics/pokemon_storage/legendary.4bpp.lz");
static const u32 gWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/legendary.bin.lz");

static const u16 gWallpaperPalettes_Dusclops[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/dusclops_bg.gbapal"),
};
static const u32 gWallpaperTiles_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/dusclops.4bpp.lz");
static const u32 gWallpaperTilemap_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/dusclops.bin.lz");

static const u16 gWallpaperPalettes_Ludicolo[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/ludicolo_bg.gbapal"),
};
static const u32 gWallpaperTiles_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/ludicolo.4bpp.lz");
static const u32 gWallpaperTilemap_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/ludicolo.bin.lz");

static const u16 gWallpaperPalettes_Whiscash[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
	INCBIN_U16("graphics/pokemon_storage/whiscash_bg.gbapal"),
};
static const u32 gWallpaperTiles_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/whiscash.4bpp.lz");
static const u32 gWallpaperTilemap_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/whiscash.bin.lz");

static const u32 gWallpaperIcon_Aqua[] = INCBIN_U32("graphics/pokemon_storage/aqua_icon.4bpp.lz");
static const u32 gWallpaperIcon_Heart[] = INCBIN_U32("graphics/pokemon_storage/heart_icon.4bpp.lz");
static const u32 gWallpaperIcon_FiveStar[] = INCBIN_U32("graphics/pokemon_storage/five_star_icon.4bpp.lz");
static const u32 gWallpaperIcon_Brick[] = INCBIN_U32("graphics/pokemon_storage/brick_icon.4bpp.lz");
static const u32 gWallpaperIcon_FourStar[] = INCBIN_U32("graphics/pokemon_storage/four_star_icon.4bpp.lz");
static const u32 gWallpaperIcon_Asterisk[] = INCBIN_U32("graphics/pokemon_storage/asterisk_icon.4bpp.lz");
static const u32 gWallpaperIcon_Dot[] = INCBIN_U32("graphics/pokemon_storage/dot_icon.4bpp.lz");
static const u32 gWallpaperIcon_LineCircle[] = INCBIN_U32("graphics/pokemon_storage/line_circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_PokeBall[] = INCBIN_U32("graphics/pokemon_storage/pokeball_icon.4bpp.lz");
static const u32 gWallpaperIcon_Maze[] = INCBIN_U32("graphics/pokemon_storage/maze_icon.4bpp.lz");
static const u32 gWallpaperIcon_Footprint[] = INCBIN_U32("graphics/pokemon_storage/footprint_icon.4bpp.lz");
static const u32 gWallpaperIcon_BigAsterisk[] = INCBIN_U32("graphics/pokemon_storage/big_asterisk_icon.4bpp.lz");
static const u32 gWallpaperIcon_Circle[] = INCBIN_U32("graphics/pokemon_storage/circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_Koffing[] = INCBIN_U32("graphics/pokemon_storage/koffing_icon.4bpp.lz");
static const u32 gWallpaperIcon_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon_icon.4bpp.lz");
static const u32 gWallpaperIcon_FourCircles[] = INCBIN_U32("graphics/pokemon_storage/four_circles_icon.4bpp.lz");
static const u32 gWallpaperIcon_Lotad[] = INCBIN_U32("graphics/pokemon_storage/lotad_icon.4bpp.lz");
static const u32 gWallpaperIcon_Crystal[] = INCBIN_U32("graphics/pokemon_storage/crystal_icon.4bpp.lz");
static const u32 gWallpaperIcon_Pichu[] = INCBIN_U32("graphics/pokemon_storage/pichu_icon.4bpp.lz");
static const u32 gWallpaperIcon_Diglett[] = INCBIN_U32("graphics/pokemon_storage/diglett_icon.4bpp.lz");
static const u32 gWallpaperIcon_Luvdisc[] = INCBIN_U32("graphics/pokemon_storage/luvdisc_icon.4bpp.lz");
static const u32 gWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/star_in_circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_Spinda[] = INCBIN_U32("graphics/pokemon_storage/spinda_icon.4bpp.lz");
static const u32 gWallpaperIcon_Latis[] = INCBIN_U32("graphics/pokemon_storage/latis_icon.4bpp.lz");
static const u32 gWallpaperIcon_Minun[] = INCBIN_U32("graphics/pokemon_storage/minun_icon.4bpp.lz");
static const u32 gWallpaperIcon_Togepi[] = INCBIN_U32("graphics/pokemon_storage/togepi_icon.4bpp.lz");
static const u32 gWallpaperIcon_Magma[] = INCBIN_U32("graphics/pokemon_storage/magma_icon.4bpp.lz");

static const struct WallpaperTable gFriendsWallpaperTable[] =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const gFriendsIcons[] =
{
    gWallpaperIcon_Aqua,
    gWallpaperIcon_Heart,
    gWallpaperIcon_FiveStar,
    gWallpaperIcon_Brick,
    gWallpaperIcon_FourStar,
    gWallpaperIcon_Asterisk,
    gWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    gWallpaperIcon_LineCircle,
    gWallpaperIcon_PokeBall,
    gWallpaperIcon_Maze,
    gWallpaperIcon_Footprint,
    gWallpaperIcon_BigAsterisk,
    gWallpaperIcon_Circle,
    gWallpaperIcon_Koffing,
    gWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    gWallpaperIcon_FourCircles,
    gWallpaperIcon_Lotad,
    gWallpaperIcon_Crystal,
    gWallpaperIcon_Pichu,
    gWallpaperIcon_Diglett,
    gWallpaperIcon_Luvdisc,
    gWallpaperIcon_StarInCircle,
    gWallpaperIcon_Spinda,
    gWallpaperIcon_Latis,
    gWallpaperIcon_Plusle,
    gWallpaperIcon_Minun,
    gWallpaperIcon_Togepi,
    gWallpaperIcon_Magma,
};

// Unknown Unused data.
static const u16 gUnknown_0857B07C = 0x23BA;

static const struct SpriteSheet gUnknown_0857B080 = {gPCGfx_Arrow, 0x80, 6};

static const struct OamData gOamData_83BB298 =
{
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2
};

static const union AnimCmd gSpriteAnim_83BB2A0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_83BB2A8[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_83BB2B0[] =
{
    gSpriteAnim_83BB2A0,
    gSpriteAnim_83BB2A8
};

static const struct SpriteTemplate gSpriteTemplate_857B0A8 =
{
    TAG_TILE_3,
    TAG_PAL_DAC9,
    &gOamData_83BB298,
    gSpriteAnimTable_83BB2B0,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const struct OamData gOamData_83BB2D0 =
{
    .shape = ST_OAM_V_RECTANGLE,
    .priority = 2
};

static const union AnimCmd gSpriteAnim_83BB2D8[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_83BB2E0[] =
{
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_83BB2E8[] =
{
    gSpriteAnim_83BB2D8,
    gSpriteAnim_83BB2E0
};

static const struct SpriteTemplate gUnknown_0857B0E0 =
{
    6,
    0xDACA,
    &gOamData_83BB2D0,
    gSpriteAnimTable_83BB2E8,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_80CD210
};

const u16 gHandCursorPalette[] = INCBIN_U16("graphics/pokemon_storage/hand_cursor.gbapal");
const u8 gHandCursorTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor.4bpp");
const u8 gHandCursorShadowTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor_shadow.4bpp");

// code
u8 CountMonsInBox(u8 boxId)
{
    u16 i, count;

    for (i = 0, count = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) != SPECIES_NONE)
            count++;
    }

    return count;
}

s16 GetFirstFreeBoxSpot(u8 boxId)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) == SPECIES_NONE)
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

static void sub_80C7128(u16 *dest, u16 dest_left, u16 dest_top, const u16 *src, u16 src_left, u16 src_top, u16 dest_width, u16 dest_height, u16 src_width)
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

static void sub_80C71A4(u16 *dest, u16 dest_left, u16 dest_top, u16 width, u16 height)
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
            Menu_MoveCursor(-1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, 0x11);
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (++task->data[1] > 3)
                task->data[1] = 0;
            Menu_MoveCursor(1);
            task->data[1] = Menu_GetCursorPos();
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
    gTasks[taskId].data[1] = sPreviousBoxOption;
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
    sPreviousBoxOption = GetCurrentBoxOption();
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
    u16 boxId, boxPosition;

    SetCurrentBox(0);
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
            ZeroBoxMonAt(boxId, boxPosition);
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

static void sub_80C77E8(struct UnkPSSStruct_2002370 *a0, u16 tileTag, u16 palTag, u8 a3, bool32 loadPal)
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

static void sub_80C7890(void)
{
    if (gUnknown_02039D04->unk_023c)
        FreeSpritePaletteByTag(gUnknown_02039D04->unk_0242);
    FreeSpriteTilesByTag(gUnknown_02039D04->unk_0240);
    FreeSpriteTilesByTag(gUnknown_02039D04->unk_0240 + 1);
}

static void sub_80C78D4(u8 curBox)
{
    sub_80C7958(curBox);
}

static void sub_80C78E4(void)
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

static void sub_80C7958(u8 curBox)
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

static void sub_80C7B14(void)
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

static void sub_80C7B80(void)
{
    if (++gUnknown_02039D04->curBox >= TOTAL_BOXES_COUNT)
        gUnknown_02039D04->curBox = 0;
    sub_80C7BE4();
}

static void sub_80C7BB4(void)
{
    gUnknown_02039D04->curBox = (gUnknown_02039D04->curBox == 0 ? TOTAL_BOXES_COUNT - 1 : gUnknown_02039D04->curBox - 1);
    sub_80C7BE4();
}

static void sub_80C7BE4(void)
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

static void sub_80C7CF4(struct Sprite *sprite)
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
    sCurrentBoxOption = boxOption;
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
        gUnknown_02039D08->boxOption = sCurrentBoxOption;
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

static void sub_80C7E98(void)
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

static void sub_80C7F1C(void)
{
    sub_80CDC0C();
    sInPartyMenu = (gUnknown_02039D08->boxOption == BOX_OPTION_DEPOSIT);
    gUnknown_02039D0E = 0;
}

static void sub_80C7F4C(void)
{
    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));
    }
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
}

static void SetPSSCallback(TaskFunc newFunc)
{
    gTasks[gUnknown_02039D08->taskId].func = newFunc;
    gUnknown_02039D08->state = 0;
}

static void Cb_InitPSS(u8 taskId)
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
            SetPSSCallback(Cb_ReshowPSS);
        }
        SetVBlankCallback(VblankCb_PSS);
        return;
    default:
        return;
    }

    gUnknown_02039D08->state++;
}

static void Cb_ShowPSS(u8 taskId)
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

static void Cb_ReshowPSS(u8 taskId)
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

static void Cb_MainPSS(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        switch (HandleInput())
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
                if (IsMonBeingMoved() && ItemIsMail(gUnknown_02039D08->cursorMonItem))
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
                SetUpScrollToBox(gUnknown_02039D08->newCurrBoxId);
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
                SetUpScrollToBox(gUnknown_02039D08->newCurrBoxId);
                gUnknown_02039D08->state = 2;
            }
            else
            {
                sub_80CFEA8();
                gUnknown_02039D08->state = 10;
            }
            break;
        case 11:
            if (!CanMovePartyMon())
            {
                if (ItemIsMail(gUnknown_02039D08->cursorMonItem))
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
            if (CanMovePartyMon())
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
            SetUpScrollToBox(gUnknown_02039D08->newCurrBoxId);
            gUnknown_02039D08->state = 2;
        }
        break;
    case 11:
        if (!sub_80D1218())
            gUnknown_02039D08->state = 0;
        break;
    }
}

static void Cb_ShowPartyPokemon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        SetUpDoShowPartyMenu();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!DoShowPartyMenu())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

static void Cb_HidePartyPokemon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        SetUpHidePartyMenu();
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!HidePartyMenu())
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

static void Cb_OnSelectedMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!sub_80CA2B8())
        {
            PlaySE(SE_SELECT);
            if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
                PrintStorageActionText(PC_TEXT_IS_SELECTED);
            else if (sub_80D127C() || gUnknown_02039D08->cursorMonItem != 0)
                PrintStorageActionText(PC_TEXT_IS_SELECTED2);
            else
                PrintStorageActionText(PC_TEXT_GIVE_TO_MON);

            AddMenu();
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
            if (CanMovePartyMon())
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
            if (CanMovePartyMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else if (ItemIsMail(gUnknown_02039D08->cursorMonItem))
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
            if (CanMovePartyMon())
            {
                gUnknown_02039D08->state = 3;
            }
            else if (gUnknown_02039D08->cursorMonIsEgg)
            {
                gUnknown_02039D08->state = 5; // Cannot release an Egg.
            }
            else if (ItemIsMail(gUnknown_02039D08->cursorMonItem))
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

static void Cb_MoveMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        InitMonPlaceChange(0);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (sInPartyMenu)
                SetPSSCallback(Cb_HandleMovingMonFromParty);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_PlaceMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        InitMonPlaceChange(1);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (sInPartyMenu)
                SetPSSCallback(Cb_HandleMovingMonFromParty);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_ShiftMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        InitMonPlaceChange(2);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_WithdrawMon(u8 taskId)
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
            InitMonPlaceChange(0);
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
        if (!DoMonPlaceChange())
        {
            SetMovingMonPriority(1);
            SetUpDoShowPartyMenu();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!DoShowPartyMenu())
        {
            InitMonPlaceChange(1);
            gUnknown_02039D08->state++;
        }
        break;
    case 4:
        if (!DoMonPlaceChange())
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

static void Cb_DepositMenu(u8 taskId)
{
    u8 boxId;

    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_DEPOSIT_IN_WHICH_BOX);
        sub_80C77E8(&gUnknown_02039D08->field_1E5C, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(gUnknown_02039D0E);
        gUnknown_02039D08->state++;
        break;
    case 1:
        boxId = sub_80C78F0();
        if (boxId == 200);
        else if (boxId == 201)
        {
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            SetPSSCallback(Cb_MainPSS);
        }
        else
        {
            if (TryStorePartyMonInBox(boxId))
            {
                gUnknown_02039D0E = boxId;
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

static void Cb_ReleaseMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_RELEASE_POKE);
        ShowYesNoWindow(1);
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
            InitCanRelaseMonVars();
            sub_80CE250();
            gUnknown_02039D08->state++;
            break;
        }
        break;
    case 2:
        RunCanReleaseMon();
        if (!sub_80CE2A8())
        {
            while (1)
            {
                s8 r0 = RunCanReleaseMon();
                if (r0 == 1)
                {
                    gUnknown_02039D08->state++;
                    break;
                }
                else if (r0 == 0)
                {
                    gUnknown_02039D08->state = 8; // Can't release the mon.
                    break;
                }
            }
        }
        break;
    case 3:
        ReleaseMon();
        RefreshCursorMonData();
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

static void Cb_ShowMarkMenu(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_MARK_POKE);
        gUnknown_02039D08->field_DA4.markings = gUnknown_02039D08->cursorMonMarkings;
        sub_811FAA4(gUnknown_02039D08->cursorMonMarkings, 0xb0, 0x10);
        gUnknown_02039D08->state++;
        break;
    case 1:
        if (!sub_811FBA4())
        {
            sub_811FAF8();
            ClearBottomWindow();
            SetMonMarkings(gUnknown_02039D08->field_DA4.markings);
            RefreshCursorMonData();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_TakeItemForMoving(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!ItemIsMail(gUnknown_02039D08->cursorMonItem))
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
        Item_FromMonToMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            ClearBottomWindow();
            sub_80CE00C();
            PrintCursorMonInfo();
            gUnknown_02039D08->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

static void Cb_GiveMovingItemToMon(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        ClearBottomWindow();
        gUnknown_02039D08->state++;
        break;
    case 1:
        sub_80CFE54(2);
        Item_GiveMovingToMon((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            sub_80CE00C();
            PrintCursorMonInfo();
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

static void Cb_ItemToBag(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!AddBagItem(gUnknown_02039D08->cursorMonItem, 1))
        {
            PlaySE(SE_HAZURE);
            PrintStorageActionText(PC_TEXT_BAG_FULL);
            gUnknown_02039D08->state = 3;
        }
        else
        {
            PlaySE(SE_SELECT);
            Item_TakeMons((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
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
            PrintCursorMonInfo();
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

static void Cb_SwitchSelectedItem(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        if (!ItemIsMail(gUnknown_02039D08->cursorMonItem))
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
        Item_SwitchMonsWithMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        gUnknown_02039D08->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            sub_80CE00C();
            PrintCursorMonInfo();
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

static void Cb_ShowItemInfo(u8 taskId)
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

static void Cb_CloseBoxWhileHoldingItem(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintStorageActionText(PC_TEXT_PUT_IN_BAG);
        ShowYesNoWindow(0);
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

static void Cb_HandleMovingMonFromParty(u8 taskId)
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

static void Cb_PrintCantStoreMail(u8 taskId)
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

static void Cb_HandleBoxOptions(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        PrintStorageActionText(PC_TEXT_WHAT_YOU_DO);
        AddMenu();
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

static void Cb_HandleWallpapers(u8 taskId)
{
    switch (gUnknown_02039D08->state)
    {
    case 0:
        AddWallpaperSetsMenu();
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
            AddWallpapersMenu(gUnknown_02039D08->wallpaperSetId);
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

static void Cb_JumpBox(u8 taskId)
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
        SetUpScrollToBox(gUnknown_02039D08->newCurrBoxId);
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

static void Cb_NameBox(u8 taskId)
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

static void Cb_ShowMonSummary(u8 taskId)
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

static void Cb_GiveItemFromBag(u8 taskId)
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

static void Cb_OnCloseBoxPressed(u8 taskId)
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
            ShowYesNoWindow(0);
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

static void Cb_OnBPressed(u8 taskId)
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
            ShowYesNoWindow(0);
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

static void Cb_ChangeScreen(u8 taskId)
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
        boxMons = gUnknown_02039D08->field_218C.box;
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

static void SetScrollingBackground(void)
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

static void sub_80CA0D8(void)
{
    LoadPalette(gUnknown_085723DC, 0, 0x20);
    LoadPalette(gUnknown_085723FC, 0x20, 0x20);
    LoadPalette(gUnknown_085726F4, 0xF0, 0x20);
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        LoadPalette(gUnknown_0857241C, 0x30, 0x20);
    else
        LoadPalette(gUnknown_0857243C, 0x30, 0x20);

    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(30));
    LoadCursorMonSprite();
    sub_80CA154();
    sub_80CA1C4();
    RefreshCursorMonData();
}

static void sub_80CA154(void)
{
    gUnknown_02039D08->field_D94 = sub_811FFB4(TAG_TILE_10, TAG_PAL_DAC8, NULL);
    gUnknown_02039D08->field_D94->oam.priority = 1;
    gUnknown_02039D08->field_D94->subpriority = 1;
    gUnknown_02039D08->field_D94->pos1.x = 40;
    gUnknown_02039D08->field_D94->pos1.y = 150;
    gUnknown_02039D08->field_DA0 = (void*) OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_TILE_10);
}

static void sub_80CA1C4(void)
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

void RefreshCursorMonData(void)
{
    LoadCursorMonGfx(gUnknown_02039D08->cursorMonSpecies, gUnknown_02039D08->cursorMonPersonality);
    PrintCursorMonInfo();
    sub_80CA65C();
    schedule_bg_copy_tilemap_to_vram(0);
}

void BoxSetMosaic(void)
{
    RefreshCursorMonData();
    if (gUnknown_02039D08->cursorMonSprite)
    {
        gUnknown_02039D08->cursorMonSprite->oam.mosaic = TRUE;
        gUnknown_02039D08->cursorMonSprite->data[0] = 10;
        gUnknown_02039D08->cursorMonSprite->data[1] = 1;
        gUnknown_02039D08->cursorMonSprite->callback = sub_80CA2D0;
        SetGpuReg(REG_OFFSET_MOSAIC, (gUnknown_02039D08->cursorMonSprite->data[0] << 12) | (gUnknown_02039D08->cursorMonSprite->data[0] << 8));
    }
}

u8 sub_80CA2B8(void)
{
    return gUnknown_02039D08->cursorMonSprite->oam.mosaic;
}

static void sub_80CA2D0(struct Sprite *sprite)
{
    sprite->data[0] -= sprite->data[1];
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;
    SetGpuReg(REG_OFFSET_MOSAIC, (sprite->data[0] << 12) | (sprite->data[0] << 8));
    if (sprite->data[0] == 0)
    {
        sprite->oam.mosaic = FALSE;
        sprite->callback = SpriteCallbackDummy;
    }
}

void LoadCursorMonSprite(void)
{
    u16 i;
    u16 tileStart;
    u8 palSlot;
    u8 spriteId;
    struct SpriteSheet sheet = {gUnknown_02039D08->field_22C4, 0x800, TAG_TILE_2};
    struct SpritePalette palette = {gUnknown_02039D08->field_2244, TAG_PAL_DAC6};
    struct SpriteTemplate template = sSpriteTemplate_CursorMon;

    for (i = 0; i < 0x800; i++)
        gUnknown_02039D08->field_22C4[i] = 0;
    for (i = 0; i < 0x10; i++)
        gUnknown_02039D08->field_2244[i] = 0;

    gUnknown_02039D08->cursorMonSprite = NULL;

    do
    {
        tileStart = LoadSpriteSheet(&sheet);
        if (tileStart == 0)
            break;

        palSlot = LoadSpritePalette(&palette);
        if (palSlot == 0xFF)
            break;

        spriteId = CreateSprite(&template, 40, 48, 0);
        if (spriteId == MAX_SPRITES)
            break;

        gUnknown_02039D08->cursorMonSprite = &gSprites[spriteId];
        gUnknown_02039D08->field_223A = palSlot * 16 + 0x100;
        gUnknown_02039D08->field_223C = (void*) OBJ_VRAM0 + tileStart * 32;
    } while (0);

    if (gUnknown_02039D08->cursorMonSprite == NULL)
    {
        FreeSpriteTilesByTag(TAG_TILE_2);
        FreeSpritePaletteByTag(TAG_PAL_DAC6);
    }
}

void LoadCursorMonGfx(u16 species, u32 pid)
{
    if (gUnknown_02039D08->cursorMonSprite == NULL)
        return;

    if (species != SPECIES_NONE)
    {
        LoadSpecialPokePic(&gMonFrontPicTable[species], gUnknown_02039D08->field_22C4, species, pid, TRUE);
        LZ77UnCompWram(gUnknown_02039D08->cursorMonPalette, gUnknown_02039D08->field_2244);
        CpuCopy32(gUnknown_02039D08->field_22C4, gUnknown_02039D08->field_223C, 0x800);
        LoadPalette(gUnknown_02039D08->field_2244, gUnknown_02039D08->field_223A, 0x20);
        gUnknown_02039D08->cursorMonSprite->invisible = FALSE;
    }
    else
    {
        gUnknown_02039D08->cursorMonSprite->invisible = TRUE;
    }
}

static void PrintCursorMonInfo(void)
{
    FillWindowPixelBuffer(0, 0x11);
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        AddTextPrinterParameterized(0, 1, gUnknown_02039D08->cursorMonNickText, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, gUnknown_02039D08->cursorMonSpeciesName, 6, 15, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, gUnknown_02039D08->cursorMonGenderLvlText, 10, 29, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 0, gUnknown_02039D08->cursorMonItemName, 6, 43, TEXT_SPEED_FF, NULL);
    }
    else
    {
        AddTextPrinterParameterized(0, 0, gUnknown_02039D08->cursorMonItemName, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 1, gUnknown_02039D08->cursorMonNickText, 6, 13, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, gUnknown_02039D08->cursorMonSpeciesName, 6, 28, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, gUnknown_02039D08->cursorMonGenderLvlText, 10, 42, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(0, 2);
    if (gUnknown_02039D08->cursorMonSpecies != SPECIES_NONE)
    {
        sub_8120084(gUnknown_02039D08->cursorMonMarkings, gUnknown_02039D08->field_DA0);
        gUnknown_02039D08->field_D94->invisible = FALSE;
    }
    else
    {
        gUnknown_02039D08->field_D94->invisible = TRUE;
    }
}

static void sub_80CA65C(void)
{
    u16 i;

    if (gUnknown_02039D08->cursorMonSpecies != SPECIES_NONE)
    {
        sub_80D27AC(0, 0, 0, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnimIfDifferent(gUnknown_02039D08->field_D98[i], i * 2 + 1);
    }
    else
    {
        sub_80D27AC(0, 0, 2, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnim(gUnknown_02039D08->field_D98[i], i * 2);
    }

    sub_80D2918(0);
    schedule_bg_copy_tilemap_to_vram(1);
}

static void sub_80CA704(void)
{
    LZ77UnCompWram(gUnknown_08DD36C8, gUnknown_02039D08->field_B0);
    LoadPalette(gPSSMenu_Pal, 0x10, 0x20);
    sub_80D2644(1, 1, gUnknown_02039D08->field_B0, 12, 22);
    sub_80D2644(2, 1, gUnknown_0857245C, 9, 4);
    sub_80D2770(1, 10, 0);
    sub_80D2770(2, 21, 0);
    sub_80CAA74();
    if (sInPartyMenu)
    {
        sub_80CA984(TRUE);
        CreatePartyMonsSprites(TRUE);
        sub_80D2918(2);
        sub_80D2918(1);
    }
    else
    {
        sub_80D27AC(1, 0, 20, 12, 2);
        sub_80CA984(TRUE);
        sub_80D2918(1);
        sub_80D2918(2);
    }

    schedule_bg_copy_tilemap_to_vram(1);
    gUnknown_02039D08->unk_02C7 = 0;
}

static void SetUpShowPartyMenu(void)
{
    gUnknown_02039D08->field_2C0 = 20;
    gUnknown_02039D08->field_2C2 = 2;
    gUnknown_02039D08->field_2C5 = 0;
    CreatePartyMonsSprites(FALSE);
}

static bool8 ShowPartyMenu(void)
{
    if (gUnknown_02039D08->field_2C5 == 20)
        return FALSE;

    gUnknown_02039D08->field_2C0--;
    gUnknown_02039D08->field_2C2++;
    sub_80D27F4(1, 3, 1);
    sub_80D2918(1);
    schedule_bg_copy_tilemap_to_vram(1);
    sub_80CBAF0(8);
    if (++gUnknown_02039D08->field_2C5 == 20)
    {
        sInPartyMenu = TRUE;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

static void SetUpHidePartyMenu(void)
{
    gUnknown_02039D08->field_2C0 = 0;
    gUnknown_02039D08->field_2C2 = 22;
    gUnknown_02039D08->field_2C5 = 0;
    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
        sub_80D11CC();
}

static bool8 HidePartyMenu(void)
{
    if (gUnknown_02039D08->field_2C5 != 20)
    {
        gUnknown_02039D08->field_2C0++;
        gUnknown_02039D08->field_2C2--;
        sub_80D27F4(1, 3, -1);
        sub_80D2918(1);
        FillBgTilemapBufferRect_Palette0(1, 0x100, 10, gUnknown_02039D08->field_2C2, 12, 1);
        sub_80CBAF0(-8);
        if (++gUnknown_02039D08->field_2C5 != 20)
        {
            schedule_bg_copy_tilemap_to_vram(1);
            return TRUE;
        }
        else
        {
            sInPartyMenu = FALSE;
            DestroyAllPartyMonIcons();
            CompactPartySlots();
            sub_80D27AC(2, 0, 0, 9, 2);
            sub_80D2918(2);
            schedule_bg_copy_tilemap_to_vram(1);
            return FALSE;
        }
    }

    return FALSE;
}

static void sub_80CA984(bool8 arg0)
{
    if (arg0)
        sub_80D27AC(2, 0, 0, 9, 2);
    else
        sub_80D27AC(2, 0, 2, 9, 2);

    sub_80D2918(2);
    schedule_bg_copy_tilemap_to_vram(1);
}

static void sub_80CA9C0(void)
{
    gUnknown_02039D08->unk_02C7 = 1;
    gUnknown_02039D08->unk_02C8 = 30;
    gUnknown_02039D08->unk_02C9 = TRUE;
}

static void sub_80CA9EC(void)
{
    if (gUnknown_02039D08->unk_02C7)
    {
        gUnknown_02039D08->unk_02C7 = 0;
        sub_80CA984(TRUE);
    }
}

static void sub_80CAA14(void)
{
    if (gUnknown_02039D08->unk_02C7 && ++gUnknown_02039D08->unk_02C8 > 30)
    {
        gUnknown_02039D08->unk_02C8 = 0;
        gUnknown_02039D08->unk_02C9 = (gUnknown_02039D08->unk_02C9 == FALSE);
        sub_80CA984(gUnknown_02039D08->unk_02C9);
    }
}

static void sub_80CAA74(void)
{
    u8 i;

    for (i = 1; i < PARTY_SIZE; i++)
    {
        s32 species = GetMonData(gPlayerParty + i, MON_DATA_SPECIES);
        sub_80CAAA8(i, (species != SPECIES_NONE));
    }
}

static void sub_80CAAA8(u8 arg0, bool8 isPartyMon)
{
    u16 i, j, index;
    const u16 *data;

    if (isPartyMon)
        data = gUnknown_085724A4;
    else
        data = gUnknown_085724BC;

    index = 3 * (3 * (arg0 - 1) + 1);
    index *= 4;
    index += 7;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            gUnknown_02039D08->field_B0[index + j] = data[j];
        }
        data += 4;
        index += 12;
    }
}

static void sub_80CAB20(void)
{
    sub_80CAA74();
    sub_80D27AC(1, 0, 0, 12, 22);
    sub_80D2918(1);
    schedule_bg_copy_tilemap_to_vram(1);
}

static void SetUpDoShowPartyMenu(void)
{
    gUnknown_02039D08->showPartyMenuState = 0;
    PlaySE(SE_WIN_OPEN);
    SetUpShowPartyMenu();
}

static bool8 DoShowPartyMenu(void)
{
    switch (gUnknown_02039D08->showPartyMenuState)
    {
    case 0:
        if (!ShowPartyMenu())
        {
            sub_80CDBA0();
            gUnknown_02039D08->showPartyMenuState++;
        }
        break;
    case 1:
        if (!sub_80CD554())
        {
            if (gUnknown_02039D08->field_CEA)
                BoxSetMosaic();
            gUnknown_02039D08->showPartyMenuState++;
        }
        break;
    case 2:
        return FALSE;
    }
    return TRUE;
}

static void sub_80CABE0(void)
{
    if (gUnknown_02039D10 != StorageGetCurrentBox())
    {
        FlagClear(FLAG_SYS_STORAGE_UNKNOWN_FLAG);
        VarSet(VAR_STORAGE_UNKNOWN, StorageGetCurrentBox());
    }
}

static void sub_80CAC1C(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(29));
    LoadUserWindowBorderGfx(1, 2, 208);
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 17);
    CopyBgTilemapBufferToVram(0);
}

void PrintStorageActionText(u8 id)
{
    u8 *txtPtr;

    DynamicPlaceholderTextUtil_Reset();
    switch (gPCStorageActionTexts[id].format)
    {
    case PC_TEXT_FMT_NORMAL:
        break;
    case PC_TEXT_FMT_MON_NAME_1:
    case PC_TEXT_FMT_MON_NAME_2:
    case PC_TEXT_FMT_MON_NAME_3:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02039D08->cursorMonNick);
        break;
    case PC_TEXT_FMT_MON_NAME_4:
    case PC_TEXT_FMT_MON_NAME_5:
    case PC_TEXT_FMT_MON_NAME_6:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02039D08->field_21E0);
        break;
    case PC_TEXT_FMT_ITEM_NAME:
        if (sub_80D127C())
            txtPtr = StringCopy(gUnknown_02039D08->field_21EB, GetMovingItemName());
        else
            txtPtr = StringCopy(gUnknown_02039D08->field_21EB, gUnknown_02039D08->cursorMonItemName);

        while (*(txtPtr - 1) == CHAR_SPACE)
            txtPtr--;

        *txtPtr = EOS;
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02039D08->field_21EB);
        break;
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(gUnknown_02039D08->field_2190, gPCStorageActionTexts[id].text);
    FillWindowPixelBuffer(1, 0x11);
    AddTextPrinterParameterized(1, 1, gUnknown_02039D08->field_2190, 0, 1, TEXT_SPEED_FF, NULL);
    sub_8098858(1, 2, 14);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
    schedule_bg_copy_tilemap_to_vram(0);
}

void ShowYesNoWindow(s8 cursorPos)
{
    CreateYesNoMenu(&sYesNoWindowTemplate, 11, 14, 0);
    Menu_MoveCursorNoWrapAround(cursorPos);
}

void ClearBottomWindow(void)
{
    sub_8198070(1, FALSE);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void AddWallpaperSetsMenu(void)
{
    InitMenu();
    SetMenuText(18);
    SetMenuText(19);
    SetMenuText(20);
    SetMenuText(21);
    if (IsWaldaWallpaperUnlocked())
        SetMenuText(22);
    AddMenu();
}

static void AddWallpapersMenu(u8 wallpaperSet)
{
    InitMenu();
    switch (wallpaperSet)
    {
    case 0:
        SetMenuText(23);
        SetMenuText(24);
        SetMenuText(25);
        SetMenuText(26);
        break;
    case 1:
        SetMenuText(27);
        SetMenuText(28);
        SetMenuText(29);
        SetMenuText(30);
        break;
    case 2:
        SetMenuText(31);
        SetMenuText(32);
        SetMenuText(33);
        SetMenuText(34);
        break;
    case 3:
        SetMenuText(35);
        SetMenuText(36);
        SetMenuText(37);
        SetMenuText(38);
        break;
    }
    AddMenu();
}

u8 GetCurrentBoxOption(void)
{
    return sCurrentBoxOption;
}

static void sub_80CAEAC(void)
{
    if (!IsCursorOnBox())
    {
        if (sInPartyMenu)
            sub_80D0D8C(CURSOR_AREA_IN_PARTY, GetBoxCursorPosition());
        else
            sub_80D0D8C(CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
    }

    if (gUnknown_02039D12 != 0)
    {
        sub_80D0F38(gUnknown_02039D12);
        sub_80CFE54(3);
    }
}

static void sub_80CAF04(void)
{
    u16 i;

    LoadMonIconPalettes();
    for (i = 0; i < 40; i++)
        gUnknown_02039D08->field_B08[i] = 0;
    for (i = 0; i < 40; i++)
        gUnknown_02039D08->field_B58[i] = 0;
    for (i = 0; i < PARTY_SIZE; i++)
        gUnknown_02039D08->partySprites[i] = NULL;
    for (i = 0; i < IN_BOX_COUNT; i++)
        gUnknown_02039D08->boxMonsSprites[i] = NULL;

    gUnknown_02039D08->movingMonSprite = NULL;
    gUnknown_02039D08->field_78C = 0;
}

u8 sub_80CAFAC(void)
{
    return (IsCursorInBox() ? 2 : 1);
}

void CreateMovingMonIcon(void)
{
    u32 personality = GetMonData(&gUnknown_02039D08->movingMon, MON_DATA_PERSONALITY);
    u16 species = GetMonData(&gUnknown_02039D08->movingMon, MON_DATA_SPECIES2);
    u8 priority = sub_80CAFAC();

    gUnknown_02039D08->movingMonSprite = CreateMonIconSprite(species, personality, 0, 0, priority, 7);
    gUnknown_02039D08->movingMonSprite->callback = sub_80CC100;
}

static void sub_80CB028(u8 boxId)
{
    u8 boxPosition;
    u16 i, j, count;
    u16 species;
    u32 personality;

    count = 0;
    boxPosition = 0;
    for (i = 0; i < IN_BOX_COLUMS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            species = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            if (species != SPECIES_NONE)
            {
                personality = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
                gUnknown_02039D08->boxMonsSprites[count] = CreateMonIconSprite(species, personality, 8 * (3 * j) + 100, 8 * (3 * i) + 44, 2, 19 - j);
            }
            else
            {
                gUnknown_02039D08->boxMonsSprites[count] = NULL;
            }
            boxPosition++;
            count++;
        }
    }

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (GetBoxMonDataAt(boxId, boxPosition, MON_DATA_HELD_ITEM) == 0)
                gUnknown_02039D08->boxMonsSprites[boxPosition]->oam.objMode = 1;
        }
    }
}

void sub_80CB140(u8 boxPosition)
{
    u16 species = GetCurrentBoxMonData(boxPosition, MON_DATA_SPECIES2);

    if (species != SPECIES_NONE)
    {
        s16 x = 8 * (3 * (boxPosition % IN_BOX_ROWS)) + 100;
        s16 y = 8 * (3 * (boxPosition / IN_BOX_ROWS)) + 44;
        u32 personality = GetCurrentBoxMonData(boxPosition, MON_DATA_PERSONALITY);

        gUnknown_02039D08->boxMonsSprites[boxPosition] = CreateMonIconSprite(species, personality, x, y, 2, 19 - (boxPosition % IN_BOX_ROWS));
        if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
            gUnknown_02039D08->boxMonsSprites[boxPosition]->oam.objMode = 1;
    }
}

static void sub_80CB1F0(s16 arg0)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (gUnknown_02039D08->boxMonsSprites[i] != NULL)
        {
            gUnknown_02039D08->boxMonsSprites[i]->data[2] = arg0;
            gUnknown_02039D08->boxMonsSprites[i]->data[4] = 1;
            gUnknown_02039D08->boxMonsSprites[i]->callback = sub_80CB278;
        }
    }
}

static void sub_80CB234(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
        sprite->pos1.x += sprite->data[2];
    }
    else
    {
        gUnknown_02039D08->field_C66--;
        sprite->pos1.x = sprite->data[3];
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_80CB278(struct Sprite *sprite)
{
    if (sprite->data[4] != 0)
    {
        sprite->data[4]--;
    }
    else
    {
        sprite->pos1.x += sprite->data[2];
        sprite->data[5] = sprite->pos1.x + sprite->pos2.x;
        if (sprite->data[5] <= 68 || sprite->data[5] >= 252)
            sprite->callback = SpriteCallbackDummy;
    }
}

static void DestroyAllIconsInRow(u8 row)
{
    u16 column;
    u8 boxPosition = row;

    for (column = 0; column < IN_BOX_COLUMS; column++)
    {
        if (gUnknown_02039D08->boxMonsSprites[boxPosition] != NULL)
        {
            DestroyBoxMonIcon(gUnknown_02039D08->boxMonsSprites[boxPosition]);
            gUnknown_02039D08->boxMonsSprites[boxPosition] = NULL;
        }
        boxPosition += IN_BOX_ROWS;
    }
}

u8 sub_80CB2F8(u8 row, u16 times, s16 xDelta)
{
    s32 i;
    u16 y = 44;
    s16 xDest = 8 * (3 * row) + 100;
    u16 x = xDest - ((times + 1) * xDelta);
    u8 subpriority = 19 - row;
    u8 count = 0;
    u8 boxPosition = row;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < IN_BOX_COLUMS; i++)
        {
            if (gUnknown_02039D08->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                gUnknown_02039D08->boxMonsSprites[boxPosition] = CreateMonIconSprite(gUnknown_02039D08->boxSpecies[boxPosition],
                                                                                        gUnknown_02039D08->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority);
                if (gUnknown_02039D08->boxMonsSprites[boxPosition] != NULL)
                {
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[1] = times;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[3] = xDest;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->callback = sub_80CB234;
                    count++;
                }
            }
            boxPosition += IN_BOX_ROWS;
            y += 24;
        }
    }
    else
    {
        for (i = 0; i < IN_BOX_COLUMS; i++)
        {
            if (gUnknown_02039D08->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                gUnknown_02039D08->boxMonsSprites[boxPosition] = CreateMonIconSprite(gUnknown_02039D08->boxSpecies[boxPosition],
                                                                                        gUnknown_02039D08->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority);
                if (gUnknown_02039D08->boxMonsSprites[boxPosition] != NULL)
                {
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[1] = times;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->data[3] = xDest;
                    gUnknown_02039D08->boxMonsSprites[boxPosition]->callback = sub_80CB234;
                    if (GetBoxMonDataAt(gUnknown_02039D08->field_C5C, boxPosition, MON_DATA_HELD_ITEM) == 0)
                        gUnknown_02039D08->boxMonsSprites[boxPosition]->oam.objMode = 1;
                    count++;
                }
            }
            boxPosition += IN_BOX_ROWS;
            y += 24;
        }
    }

    return count;
}

static void sub_80CB4CC(u8 boxId, s8 direction)
{
    gUnknown_02039D08->field_C6A = 0;
    gUnknown_02039D08->field_C6B = boxId;
    gUnknown_02039D08->field_C69 = direction;
    gUnknown_02039D08->field_C60 = 32;
    gUnknown_02039D08->field_C64 = -(6 * direction);
    gUnknown_02039D08->field_C66 = 0;
    SetBoxSpeciesAndPersonalities(boxId);
    if (direction > 0)
        gUnknown_02039D08->field_C68 = 0;
    else
        gUnknown_02039D08->field_C68 = IN_BOX_ROWS - 1;

    gUnknown_02039D08->field_C62 = (24 * gUnknown_02039D08->field_C68) + 100;
    sub_80CB1F0(gUnknown_02039D08->field_C64);
}

static bool8 sub_80CB584(void)
{
    if (gUnknown_02039D08->field_C60 != 0)
        gUnknown_02039D08->field_C60--;

    switch (gUnknown_02039D08->field_C6A)
    {
    case 0:
        gUnknown_02039D08->field_C62 += gUnknown_02039D08->field_C64;
        if (gUnknown_02039D08->field_C62 <= 64 || gUnknown_02039D08->field_C62 >= 252)
        {
            DestroyAllIconsInRow(gUnknown_02039D08->field_C68);
            gUnknown_02039D08->field_C62 += gUnknown_02039D08->field_C69 * 24;
            gUnknown_02039D08->field_C6A++;
        }
        break;
    case 1:
        gUnknown_02039D08->field_C62 += gUnknown_02039D08->field_C64;
        gUnknown_02039D08->field_C66 += sub_80CB2F8(gUnknown_02039D08->field_C68, gUnknown_02039D08->field_C60, gUnknown_02039D08->field_C64);
        if ((gUnknown_02039D08->field_C69 > 0 && gUnknown_02039D08->field_C68 == IN_BOX_ROWS - 1)
            || (gUnknown_02039D08->field_C69 < 0 && gUnknown_02039D08->field_C68 == 0))
        {
            gUnknown_02039D08->field_C6A++;
        }
        else
        {
            gUnknown_02039D08->field_C68 += gUnknown_02039D08->field_C69;
            gUnknown_02039D08->field_C6A = 0;
        }
        break;
    case 2:
        if (gUnknown_02039D08->field_C66 == 0)
        {
            gUnknown_02039D08->field_C60++;
            return FALSE;
        }
        break;
    default:
        return FALSE;
    }

    return TRUE;
}

static void SetBoxSpeciesAndPersonalities(u8 boxId)
{
    s32 i, j, boxPosition;

    boxPosition = 0;
    for (i = 0; i < IN_BOX_COLUMS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            gUnknown_02039D08->boxSpecies[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            if (gUnknown_02039D08->boxSpecies[boxPosition] != SPECIES_NONE)
                gUnknown_02039D08->boxPersonalities[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
            boxPosition++;
        }
    }

    gUnknown_02039D08->field_C5C = boxId;
}

void DestroyBoxMonIconAtPosition(u8 boxPosition)
{
    if (gUnknown_02039D08->boxMonsSprites[boxPosition] != NULL)
    {
        DestroyBoxMonIcon(gUnknown_02039D08->boxMonsSprites[boxPosition]);
        gUnknown_02039D08->boxMonsSprites[boxPosition] = NULL;
    }
}

void SetBoxMonIconObjMode(u8 boxPosition, u8 objMode)
{
    if (gUnknown_02039D08->boxMonsSprites[boxPosition] != NULL)
    {
        gUnknown_02039D08->boxMonsSprites[boxPosition]->oam.objMode = objMode;
    }
}

void CreatePartyMonsSprites(bool8 arg0)
{
    u16 i, count;
    u16 species = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2);
    u32 personality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);

    gUnknown_02039D08->partySprites[0] = CreateMonIconSprite(species, personality, 104, 64, 1, 12);
    count = 1;
    for (i = 1; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (species != SPECIES_NONE)
        {
            personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            gUnknown_02039D08->partySprites[i] = CreateMonIconSprite(species, personality, 152,  8 * (3 * (i - 1)) + 16, 1, 12);
            count++;
        }
        else
        {
            gUnknown_02039D08->partySprites[i] = NULL;
        }
    }

    if (!arg0)
    {
        for (i = 0; i < count; i++)
        {
            gUnknown_02039D08->partySprites[i]->pos1.y -= 160;
            gUnknown_02039D08->partySprites[i]->invisible = TRUE;
        }
    }

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gUnknown_02039D08->partySprites[i] != NULL && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == 0)
                gUnknown_02039D08->partySprites[i]->oam.objMode = 1;
        }
    }
}

static void sub_80CB950(void)
{
    u16 i, count;

    gUnknown_02039D08->field_C5E = 0;
    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_02039D08->partySprites[i] != NULL)
        {
            if (i != count)
            {
                sub_80CB9D0(gUnknown_02039D08->partySprites[i], count);
                gUnknown_02039D08->partySprites[i] = NULL;
                gUnknown_02039D08->field_C5E++;
            }
            count++;
        }
    }
}

u8 sub_80CB9BC(void)
{
    return gUnknown_02039D08->field_C5E;
}

static void sub_80CB9D0(struct Sprite *sprite, u16 partyId)
{
    s16 x, y;

    sprite->data[1] = partyId;
    if (partyId == 0)
        x = 104, y = 64;
    else
        x = 152, y = 8 * (3 * (partyId - 1)) + 16;

    sprite->data[2] = (u16)(sprite->pos1.x) * 8;
    sprite->data[3] = (u16)(sprite->pos1.y) * 8;
    sprite->data[4] = ((x * 8) - sprite->data[2]) / 8;
    sprite->data[5] = ((y * 8) - sprite->data[3]) / 8;
    sprite->data[6] = 8;
    sprite->callback = sub_80CBA3C;
}

static void sub_80CBA3C(struct Sprite *sprite)
{
    if (sprite->data[6] != 0)
    {
        s16 x = sprite->data[2] += sprite->data[4];
        s16 y = sprite->data[3] += sprite->data[5];
        sprite->pos1.x = x / 8u;
        sprite->pos1.y = y / 8u;
        sprite->data[6]--;
    }
    else
    {
        if (sprite->data[1] == 0)
        {
            sprite->pos1.x = 104;
            sprite->pos1.y = 64;
        }
        else
        {
            sprite->pos1.x = 152;
            sprite->pos1.y = 8 * (3 * (sprite->data[1] - 1)) + 16;
        }
        sprite->callback = SpriteCallbackDummy;
        gUnknown_02039D08->partySprites[sprite->data[1]] = sprite;
        gUnknown_02039D08->field_C5E--;
    }
}

static void DestroyMovingMonIcon(void)
{
    if (gUnknown_02039D08->movingMonSprite != NULL)
    {
        DestroyBoxMonIcon(gUnknown_02039D08->movingMonSprite);
        gUnknown_02039D08->movingMonSprite = NULL;
    }
}

static void sub_80CBAF0(s16 yDelta)
{
    u16 i, posY;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_02039D08->partySprites[i] != NULL)
        {
            gUnknown_02039D08->partySprites[i]->pos1.y += yDelta;
            posY = gUnknown_02039D08->partySprites[i]->pos1.y + gUnknown_02039D08->partySprites[i]->pos2.y + gUnknown_02039D08->partySprites[i]->centerToCornerVecY;
            posY += 16;
            if (posY > 192)
                gUnknown_02039D08->partySprites[i]->invisible = TRUE;
            else
                gUnknown_02039D08->partySprites[i]->invisible = FALSE;
        }
    }
}

static void DestroyPartyMonIcon(u8 partyId)
{
    if (gUnknown_02039D08->partySprites[partyId] != NULL)
    {
        DestroyBoxMonIcon(gUnknown_02039D08->partySprites[partyId]);
        gUnknown_02039D08->partySprites[partyId] = NULL;
    }
}

static void DestroyAllPartyMonIcons(void)
{
    u16 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_02039D08->partySprites[i] != NULL)
        {
            DestroyBoxMonIcon(gUnknown_02039D08->partySprites[i]);
            gUnknown_02039D08->partySprites[i] = NULL;
        }
    }
}

void SetPartyMonIconObjMode(u8 partyId, u8 objMode)
{
    if (gUnknown_02039D08->partySprites[partyId] != NULL)
    {
        gUnknown_02039D08->partySprites[partyId]->oam.objMode = objMode;
    }
}

static void sub_80CBC14(u8 mode, u8 id)
{
    if (mode == MODE_PARTY)
    {
        gUnknown_02039D08->movingMonSprite = gUnknown_02039D08->partySprites[id];
        gUnknown_02039D08->partySprites[id] = NULL;
    }
    else if (mode == MODE_BOX)
    {
        gUnknown_02039D08->movingMonSprite = gUnknown_02039D08->boxMonsSprites[id];
        gUnknown_02039D08->boxMonsSprites[id] = NULL;
    }
    else
    {
        return;
    }

    gUnknown_02039D08->movingMonSprite->callback = sub_80CC100;
    gUnknown_02039D08->movingMonSprite->oam.priority = sub_80CAFAC();
    gUnknown_02039D08->movingMonSprite->subpriority = 7;
}

static void sub_80CBCAC(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
    {
        gUnknown_02039D08->partySprites[position] = gUnknown_02039D08->movingMonSprite;
        gUnknown_02039D08->partySprites[position]->oam.priority = 1;
        gUnknown_02039D08->partySprites[position]->subpriority = 12;
    }
    else
    {
        gUnknown_02039D08->boxMonsSprites[position] = gUnknown_02039D08->movingMonSprite;
        gUnknown_02039D08->boxMonsSprites[position]->oam.priority = 2;
        gUnknown_02039D08->boxMonsSprites[position]->subpriority = 19 - (position % IN_BOX_ROWS);
    }
    gUnknown_02039D08->movingMonSprite->callback = SpriteCallbackDummy;
    gUnknown_02039D08->movingMonSprite = NULL;
}

static void sub_80CBD5C(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
        gUnknown_02039D08->field_B00 = &gUnknown_02039D08->partySprites[position];
    else
        gUnknown_02039D08->field_B00 = &gUnknown_02039D08->boxMonsSprites[position];

    gUnknown_02039D08->movingMonSprite->callback = SpriteCallbackDummy;
    gUnknown_02039D08->field_C5D = 0;
}

static bool8 sub_80CBDC4(void)
{
    if (gUnknown_02039D08->field_C5D == 16)
        return FALSE;

    gUnknown_02039D08->field_C5D++;
    if (gUnknown_02039D08->field_C5D & 1)
    {
        (*gUnknown_02039D08->field_B00)->pos1.y--;
        gUnknown_02039D08->movingMonSprite->pos1.y++;
    }

    (*gUnknown_02039D08->field_B00)->pos2.x = gSineTable[gUnknown_02039D08->field_C5D * 8] / 16;
    gUnknown_02039D08->movingMonSprite->pos2.x = -(gSineTable[gUnknown_02039D08->field_C5D * 8] / 16);
    if (gUnknown_02039D08->field_C5D == 8)
    {
        gUnknown_02039D08->movingMonSprite->oam.priority = (*gUnknown_02039D08->field_B00)->oam.priority;
        gUnknown_02039D08->movingMonSprite->subpriority = (*gUnknown_02039D08->field_B00)->subpriority;
        (*gUnknown_02039D08->field_B00)->oam.priority = sub_80CAFAC();
        (*gUnknown_02039D08->field_B00)->subpriority = 7;
    }

    if (gUnknown_02039D08->field_C5D == 16)
    {
        struct Sprite *sprite = gUnknown_02039D08->movingMonSprite;
        gUnknown_02039D08->movingMonSprite = (*gUnknown_02039D08->field_B00);
        *gUnknown_02039D08->field_B00 = sprite;

        gUnknown_02039D08->movingMonSprite->callback = sub_80CC100;
        (*gUnknown_02039D08->field_B00)->callback = SpriteCallbackDummy;
    }

    return TRUE;
}

static void sub_80CBF14(u8 mode, u8 position)
{
    switch (mode)
    {
    case MODE_PARTY:
        gUnknown_02039D08->field_B04 = &gUnknown_02039D08->partySprites[position];
        break;
    case MODE_BOX:
        gUnknown_02039D08->field_B04 = &gUnknown_02039D08->boxMonsSprites[position];
        break;
    case MODE_2:
        gUnknown_02039D08->field_B04 = &gUnknown_02039D08->movingMonSprite;
        break;
    default:
        return;
    }

    if (*gUnknown_02039D08->field_B04 != NULL)
    {
        InitSpriteAffineAnim(*gUnknown_02039D08->field_B04);
        (*gUnknown_02039D08->field_B04)->oam.affineMode = 1;
        (*gUnknown_02039D08->field_B04)->affineAnims = gSpriteAffineAnimTable_857291C;
        StartSpriteAffineAnim(*gUnknown_02039D08->field_B04, 0);
    }
}

static bool8 sub_80CBFD8(void)
{
    if (*gUnknown_02039D08->field_B04 == NULL || (*gUnknown_02039D08->field_B04)->invisible)
        return FALSE;

    if ((*gUnknown_02039D08->field_B04)->affineAnimEnded)
        (*gUnknown_02039D08->field_B04)->invisible = TRUE;

    return TRUE;
}

static void sub_80CC020(void)
{
    if (*gUnknown_02039D08->field_B04 != NULL)
    {
        FreeOamMatrix((*gUnknown_02039D08->field_B04)->oam.matrixNum);
        DestroyBoxMonIcon(*gUnknown_02039D08->field_B04);
        *gUnknown_02039D08->field_B04 = NULL;
    }
}

static void sub_80CC064(void)
{
    if (*gUnknown_02039D08->field_B04 != NULL)
    {
        (*gUnknown_02039D08->field_B04)->invisible = FALSE;
        StartSpriteAffineAnim(*gUnknown_02039D08->field_B04, 1);
    }
}

static bool8 sub_80CC0A0(void)
{
    if (gUnknown_02039D08->field_B04 == NULL)
        return FALSE;

    if ((*gUnknown_02039D08->field_B04)->affineAnimEnded)
        gUnknown_02039D08->field_B04 = NULL;

    return TRUE;
}

static void SetMovingMonPriority(u8 priority)
{
    gUnknown_02039D08->movingMonSprite->oam.priority = priority;
}

static void sub_80CC100(struct Sprite *sprite)
{
    sprite->pos1.x = gUnknown_02039D08->field_CB4->pos1.x;
    sprite->pos1.y = gUnknown_02039D08->field_CB4->pos1.y + gUnknown_02039D08->field_CB4->pos2.y + 4;
}

static u16 sub_80CC124(u16 species)
{
    u16 i, var;

    for (i = 0; i < 40; i++)
    {
        if (gUnknown_02039D08->field_B58[i] == species)
            break;
    }

    if (i == 40)
    {
        for (i = 0; i < 40; i++)
        {
            if (gUnknown_02039D08->field_B58[i] == 0)
                break;
        }
        if (i == 40)
            return 0xFFFF;
    }

    gUnknown_02039D08->field_B58[i] = species;
    gUnknown_02039D08->field_B08[i]++;
    var = 16 * i;
    CpuCopy32(GetMonIconTiles(species, TRUE), (void*)(OBJ_VRAM0) + var * 32, 0x200);

    return var;
}

static void sub_80CC1E0(u16 species)
{
    u16 i;

    for (i = 0; i < 40; i++)
    {
        if (gUnknown_02039D08->field_B58[i] == species)
        {
            if (--gUnknown_02039D08->field_B08[i] == 0)
                gUnknown_02039D08->field_B58[i] = 0;
            break;
        }
    }
}

static struct Sprite *CreateMonIconSprite(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority)
{
    u16 tileNum;
    u8 spriteId;
    struct SpriteTemplate tempalte = gUnknown_085728D4;

    species = GetIconSpecies(species, personality);
    tempalte.paletteTag = 0xDAC0 + gMonIconPaletteIndices[species];
    tileNum = sub_80CC124(species);
    if (tileNum == 0xFFFF)
        return NULL;

    spriteId = CreateSprite(&tempalte, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
    {
        sub_80CC1E0(species);
        return NULL;
    }

    gSprites[spriteId].oam.tileNum = tileNum;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].data[0] = species;
    return &gSprites[spriteId];
}

static void DestroyBoxMonIcon(struct Sprite *sprite)
{
    sub_80CC1E0(sprite->data[0]);
    DestroySprite(sprite);
}

static void sub_80CC32C(u8 boxId)
{
    u8 taskId = CreateTask(sub_80CC370, 2);

    gTasks[taskId].data[2] = boxId;
}

static bool8 sub_80CC35C(void)
{
    return FuncIsActiveTask(sub_80CC370);
}

static void sub_80CC370(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gUnknown_02039D08->field_2D2 = 0;
        gUnknown_02039D08->bg2_X = 0;
        task->data[1] = RequestDma3Fill(0, gUnknown_02039D08->field_4AC4, 0x1000, 1);
        break;
    case 1:
        if (CheckForSpaceForDma3Request(task->data[1]) == -1)
            return;

        SetBgTilemapBuffer(2, gUnknown_02039D08->field_4AC4);
        ShowBg(2);
        break;
    case 2:
        LoadWallpaperGfx(task->data[2], 0);
        break;
    case 3:
        if (!WaitForWallpaperGfxLoad())
            return;

        sub_80CCB50(task->data[2]);
        sub_80CD02C();
        sub_80CB028(task->data[2]);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(27) | BGCNT_TXT512x256);
        break;
    case 4:
        DestroyTask(taskId);
        break;
    default:
        task->data[0] = 0;
        return;
    }

    task->data[0]++;
}

static void SetUpScrollToBox(u8 boxId)
{
    s8 direction = sub_80CC644(boxId);

    gUnknown_02039D08->field_2CE = (direction > 0) ? 6 : -6;
    gUnknown_02039D08->field_2D3 = (direction > 0) ? 1 : 2;
    gUnknown_02039D08->field_2D0 = 32;
    gUnknown_02039D08->field_2D4 = boxId;
    gUnknown_02039D08->field_2D6 = (direction <= 0) ? 5 : 0;
    gUnknown_02039D08->field_2D8 = direction;
    gUnknown_02039D08->field_2DA = (direction > 0) ? 264 : 56;
    gUnknown_02039D08->field_2DC = (direction <= 0) ? 5 : 0;
    gUnknown_02039D08->field_2DE = 0;
    gUnknown_02039D08->field_2E0 = 2;
    gUnknown_02039D08->field_A64 = boxId;
    gUnknown_02039D08->field_A65 = direction;
    gUnknown_02039D08->field_A63 = 0;
}

bool8 ScrollToBox(void)
{
    bool8 var;

    switch (gUnknown_02039D08->field_A63)
    {
    case 0:
        LoadWallpaperGfx(gUnknown_02039D08->field_A64, gUnknown_02039D08->field_A65);
        gUnknown_02039D08->field_A63++;
    case 1:
        if (!WaitForWallpaperGfxLoad())
            return TRUE;

        sub_80CB4CC(gUnknown_02039D08->field_A64, gUnknown_02039D08->field_A65);
        sub_80CCCFC(gUnknown_02039D08->field_A64, gUnknown_02039D08->field_A65);
        sub_80CD0B8(gUnknown_02039D08->field_A65);
        break;
    case 2:
        var = sub_80CB584();
        if (gUnknown_02039D08->field_2D0 != 0)
        {
            gUnknown_02039D08->bg2_X += gUnknown_02039D08->field_2CE;
            if (--gUnknown_02039D08->field_2D0 != 0)
                return TRUE;
            sub_80CCEE0();
            sub_80CD158();
        }
        return var;
    }

    gUnknown_02039D08->field_A63++;
    return TRUE;
}

s8 sub_80CC644(u8 boxId)
{
    u8 i;
    u8 currentBox = StorageGetCurrentBox();

    for (i = 0; currentBox != boxId; i++)
    {
        currentBox++;
        if (currentBox >= TOTAL_BOXES_COUNT)
            currentBox = 0;
    }

    return (i < TOTAL_BOXES_COUNT / 2) ? 1 : -1;
}

static void SetWallpaperForCurrentBox(u8 wallpaperId)
{
    u8 boxId = StorageGetCurrentBox();
    SetBoxWallpaper(boxId, wallpaperId);
    gUnknown_02039D08->wallpaperChangeState = 0;
}

static bool8 DoWallpaperGfxChange(void)
{
    switch (gUnknown_02039D08->wallpaperChangeState)
    {
    case 0:
        BeginNormalPaletteFade(gUnknown_02039D08->field_738, 1, 0, 16, RGB_WHITEALPHA);
        gUnknown_02039D08->wallpaperChangeState++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            u8 curBox = StorageGetCurrentBox();
            LoadWallpaperGfx(curBox, 0);
            gUnknown_02039D08->wallpaperChangeState++;
        }
        break;
    case 2:
        if (WaitForWallpaperGfxLoad() == TRUE)
        {
            sub_80CCF9C();
            BeginNormalPaletteFade(gUnknown_02039D08->field_738, 1, 16, 0, RGB_WHITEALPHA);
            gUnknown_02039D08->wallpaperChangeState++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
            gUnknown_02039D08->wallpaperChangeState++;
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

void LoadWallpaperGfx(u8 boxId, s8 direction)
{
    u8 wallpaperId;
    const struct WallpaperTable *wallpaperGfx;
    void *iconGfx;
    u32 size1, size2;

    gUnknown_02039D08->field_6F9 = 0;
    gUnknown_02039D08->field_6FA = boxId;
    gUnknown_02039D08->field_6FB = direction;
    if (gUnknown_02039D08->field_6FB != 0)
    {
        gUnknown_02039D08->field_2D2 = (gUnknown_02039D08->field_2D2 == 0);
        sub_80CCAE0(gUnknown_02039D08->field_4AC4);
    }

    wallpaperId = GetBoxWallpaper(gUnknown_02039D08->field_6FA);
    if (wallpaperId != WALLPAPER_FRIENDS)
    {
        wallpaperGfx = &gWallpaperTable[wallpaperId];
        LZ77UnCompWram(wallpaperGfx->tileMap, gUnknown_02039D08->field_792);
        sub_80CCA3C(gUnknown_02039D08->field_792, gUnknown_02039D08->field_6FB, gUnknown_02039D08->field_2D2);

        if (gUnknown_02039D08->field_6FB != 0)
            LoadPalette(wallpaperGfx->palettes, (gUnknown_02039D08->field_2D2 * 32) + 0x40, 0x40);
        else
            CpuCopy16(wallpaperGfx->palettes, &gPlttBufferUnfaded[(gUnknown_02039D08->field_2D2 * 32) + 0x40], 0x40);

        gUnknown_02039D08->wallpaperTiles = malloc_and_decompress(wallpaperGfx->tiles, &size1);
        LoadBgTiles(2, gUnknown_02039D08->wallpaperTiles, size1, gUnknown_02039D08->field_2D2 << 8);
    }
    else
    {
        wallpaperGfx = &gFriendsWallpaperTable[GetWaldaWallpaperPatternId()];
        LZ77UnCompWram(wallpaperGfx->tileMap, gUnknown_02039D08->field_792);
        sub_80CCA3C(gUnknown_02039D08->field_792, gUnknown_02039D08->field_6FB, gUnknown_02039D08->field_2D2);

        CpuCopy16(wallpaperGfx->palettes, gUnknown_02039D08->field_792, 0x40);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &gUnknown_02039D08->field_792[1], 4);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &gUnknown_02039D08->field_792[17], 4);

        if (gUnknown_02039D08->field_6FB != 0)
            LoadPalette(gUnknown_02039D08->field_792, (gUnknown_02039D08->field_2D2 * 32) + 0x40, 0x40);
        else
            CpuCopy16(gUnknown_02039D08->field_792, &gPlttBufferUnfaded[(gUnknown_02039D08->field_2D2 * 32) + 0x40], 0x40);

        gUnknown_02039D08->wallpaperTiles = malloc_and_decompress(wallpaperGfx->tiles, &size1);
        iconGfx = malloc_and_decompress(gFriendsIcons[GetWaldaWallpaperIconId()], &size2);
        CpuCopy32(iconGfx, gUnknown_02039D08->wallpaperTiles + 0x800, size2);
        Free(iconGfx);
        LoadBgTiles(2, gUnknown_02039D08->wallpaperTiles, size1, gUnknown_02039D08->field_2D2 << 8);
    }

    CopyBgTilemapBufferToVram(2);
}

bool32 WaitForWallpaperGfxLoad(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return FALSE;

    if (gUnknown_02039D08->wallpaperTiles != NULL)
    {
        Free(gUnknown_02039D08->wallpaperTiles);
        gUnknown_02039D08->wallpaperTiles = NULL;
    }
    return TRUE;
}

static void sub_80CCA3C(const void *tilemap, s8 direction, u8 arg2)
{
    s16 var = (arg2 * 2) + 3;
    s16 x = ((gUnknown_02039D08->bg2_X / 8 + 10) + (direction * 24)) & 0x3F;

    CopyRectToBgTilemapBufferRect(2, tilemap, 0, 0, 0x14, 0x12, x, 2, 0x14, 0x12, 0x11, arg2 << 8, var);

    if (direction == 0)
        return;
    else if (direction > 0)
        x *= 1, x += 0x14; // x * 1 is needed to match, but can be safely removed as it makes no functional difference
    else
        x -= 4;

    FillBgTilemapBufferRect(2, 0, x, 2, 4, 0x12, 0x11);
}

static void sub_80CCAE0(void *arg0)
{
    u16 i;
    u16 *dest = arg0;
    s16 r3 = ((gUnknown_02039D08->bg2_X / 8) + 30) & 0x3F;

    if (r3 <= 31)
        dest += r3 + 0x260;
    else
        dest += r3 + 0x640;

    for (i = 0; i < 0x2C; i++)
    {
        *dest++ = 0;
        r3 = (r3 + 1) & 0x3F;
        if (r3 == 0)
            dest -= 0x420;
        if (r3 == 0x20)
            dest += 0x3e0;
    }
}

static void sub_80CCB50(u8 boxId)
{
    u8 tagIndex;
    s16 r6;
    u16 i;

    struct SpriteSheet spriteSheet = {gUnknown_02039D08->field_2F8, 0x200, TAG_TILE_3};
    struct SpritePalette palettes[] = {
        {gUnknown_02039D08->field_6FC, TAG_PAL_DAC9},
        {}
    };

    u16 wallpaperId = GetBoxWallpaper(boxId);

    gUnknown_02039D08->field_6FC[14] = gUnknown_08577574[wallpaperId][0];
    gUnknown_02039D08->field_6FC[15] = gUnknown_08577574[wallpaperId][1];
    LoadSpritePalettes(palettes);
    gUnknown_02039D08->field_738 = 0x3f0;

    tagIndex = IndexOfSpritePaletteTag(TAG_PAL_DAC9);
    gUnknown_02039D08->field_71C = 0x10e + 16 * tagIndex;
    gUnknown_02039D08->field_738 |= 0x10000 << tagIndex;

    tagIndex = IndexOfSpritePaletteTag(TAG_PAL_DAC9);
    gUnknown_02039D08->field_71E = 0x10e + 16 * tagIndex;
    gUnknown_02039D08->field_738 |= 0x10000 << tagIndex;

    StringCopyPadded(gUnknown_02039D08->field_21B8, GetBoxNamePtr(boxId), 0, 8);
    sub_80C6D80(gUnknown_02039D08->field_21B8, gUnknown_02039D08->field_2F8, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    r6 = sub_80CD00C(GetBoxNamePtr(boxId));

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_857B0A8, r6 + i * 32, 28, 24);
        gUnknown_02039D08->field_720[i] = &gSprites[spriteId];
        StartSpriteAnim(gUnknown_02039D08->field_720[i], i);
    }
    gUnknown_02039D08->field_6F8 = 0;
}

static void sub_80CCCFC(u8 boxId, s8 direction)
{
    u16 r8;
    s16 x, x2;
    u16 i;
    struct SpriteSheet spriteSheet = {gUnknown_02039D08->field_2F8, 0x200, TAG_TILE_3};
    struct SpriteTemplate template = gSpriteTemplate_857B0A8;

    gUnknown_02039D08->field_6F8 = (gUnknown_02039D08->field_6F8 == 0);
    if (gUnknown_02039D08->field_6F8 == 0)
    {
        spriteSheet.tag = TAG_TILE_3;
        r8 = gUnknown_02039D08->field_71C;
    }
    else
    {
        spriteSheet.tag = TAG_TILE_4;
        r8 = gUnknown_02039D08->field_71C;
        template.tileTag = 4;
        template.paletteTag = TAG_PAL_DAC9;
    }

    StringCopyPadded(gUnknown_02039D08->field_21B8, GetBoxNamePtr(boxId), 0, 8);
    sub_80C6D80(gUnknown_02039D08->field_21B8, gUnknown_02039D08->field_2F8, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    LoadPalette(gUnknown_08577574[GetBoxWallpaper(boxId)], r8, 4);
    x = sub_80CD00C(GetBoxNamePtr(boxId));
    x2 = x;
    x2 += direction * 192;

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&template, i * 32 + x2, 28, 24);

        gUnknown_02039D08->field_728[i] = &gSprites[spriteId];
        gUnknown_02039D08->field_728[i]->data[0] = (-direction) * 6;
        gUnknown_02039D08->field_728[i]->data[1] = i * 32 + x;
        gUnknown_02039D08->field_728[i]->data[2] = 0;
        gUnknown_02039D08->field_728[i]->callback = sub_80CCF30;
        StartSpriteAnim(gUnknown_02039D08->field_728[i], i);

        gUnknown_02039D08->field_720[i]->data[0] = (-direction) * 6;
        gUnknown_02039D08->field_720[i]->data[1] = 1;
        gUnknown_02039D08->field_720[i]->callback = sub_80CCF64;
    }
}

static void sub_80CCEE0(void)
{
    if (gUnknown_02039D08->field_6F8 == 0)
        FreeSpriteTilesByTag(TAG_TILE_4);
    else
        FreeSpriteTilesByTag(TAG_TILE_3);

    gUnknown_02039D08->field_720[0] = gUnknown_02039D08->field_728[0];
    gUnknown_02039D08->field_720[1] = gUnknown_02039D08->field_728[1];
}

static void sub_80CCF30(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
        sprite->data[2]--;
    else if ((sprite->pos1.x += sprite->data[0]) == sprite->data[1])
        sprite->callback = SpriteCallbackDummy;
}

static void sub_80CCF64(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
    }
    else
    {
        sprite->pos1.x += sprite->data[0];
        sprite->data[2] = sprite->pos1.x + sprite->pos2.x;
        if (sprite->data[2] < 0x40 || sprite->data[2] > 0x100)
            DestroySprite(sprite);
    }
}

static void sub_80CCF9C(void)
{
    u8 boxId = StorageGetCurrentBox();
    u8 wallpaperId = GetBoxWallpaper(boxId);
    if (gUnknown_02039D08->field_6F8 == 0)
        CpuCopy16(gUnknown_08577574[wallpaperId], gPlttBufferUnfaded + gUnknown_02039D08->field_71C, 4);
    else
        CpuCopy16(gUnknown_08577574[wallpaperId], gPlttBufferUnfaded + gUnknown_02039D08->field_71E, 4);
}

static s16 sub_80CD00C(const u8 *string)
{
    return 0xB0 - GetStringWidth(1, string, 0) / 2;
}

static void sub_80CD02C(void)
{
    u16 i;

    LoadSpriteSheet(&gUnknown_0857B080);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_0857B0E0, 0x5c + i * 0x88, 28, 22);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            StartSpriteAnim(sprite, i);
            sprite->data[3] = (i == 0) ? -1 : 1;
            gUnknown_02039D08->field_730[i] = sprite;
        }
    }
    if (IsCursorOnBox())
        sub_80CD1A8(TRUE);
}

static void sub_80CD0B8(s8 direction)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        gUnknown_02039D08->field_730[i]->pos2.x = 0;
        gUnknown_02039D08->field_730[i]->data[0] = 2;
    }
    if (direction < 0)
    {
        gUnknown_02039D08->field_730[0]->data[1] = 29;
        gUnknown_02039D08->field_730[1]->data[1] = 5;
        gUnknown_02039D08->field_730[0]->data[2] = 0x48;
        gUnknown_02039D08->field_730[1]->data[2] = 0x48;
    }
    else
    {
        gUnknown_02039D08->field_730[0]->data[1] = 5;
        gUnknown_02039D08->field_730[1]->data[1] = 29;
        gUnknown_02039D08->field_730[0]->data[2] = 0xF8;
        gUnknown_02039D08->field_730[1]->data[2] = 0xF8;
    }
    gUnknown_02039D08->field_730[0]->data[7] = 0;
    gUnknown_02039D08->field_730[1]->data[7] = 1;
}

static void sub_80CD158(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        gUnknown_02039D08->field_730[i]->pos1.x = 0x88 * i + 0x5c;
        gUnknown_02039D08->field_730[i]->pos2.x = 0;
        gUnknown_02039D08->field_730[i]->invisible = FALSE;
    }
    sub_80CD1A8(TRUE);
}

static void sub_80CD1A8(bool8 a0)
{
    u16 i;

    if (a0)
    {
        for (i = 0; i < 2; i++)
        {
            gUnknown_02039D08->field_730[i]->data[0] = 1;
            gUnknown_02039D08->field_730[i]->data[1] = 0;
            gUnknown_02039D08->field_730[i]->data[2] = 0;
            gUnknown_02039D08->field_730[i]->data[4] = 0;
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gUnknown_02039D08->field_730[i]->data[0] = 0;
        }
    }
}

static void sub_80CD210(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.x = 0;
        break;
    case 1:
        if (++sprite->data[1] > 3)
        {
            sprite->data[1] = 0;
            sprite->pos2.x += sprite->data[3];
            if (++sprite->data[2] > 5)
            {
                sprite->data[2] = 0;
                sprite->pos2.x = 0;
            }
        }
        break;
    case 2:
        sprite->data[0] = 3;
        break;
    case 3:
        sprite->pos1.x -= gUnknown_02039D08->field_2CE;
        if (sprite->pos1.x < 0x49 || sprite->pos1.x > 0xf7)
            sprite->invisible = TRUE;
        if (--sprite->data[1] == 0)
        {
            sprite->pos1.x = sprite->data[2];
            sprite->invisible = FALSE;
            sprite->data[0] = 4;
        }
        break;
    case 4:
        sprite->pos1.x -= gUnknown_02039D08->field_2CE;
        break;
    }
}

struct Sprite *sub_80CD2E8(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority)
{
    u8 spriteId = CreateSprite(&gUnknown_0857B0E0, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
        return NULL;

    animId %= 2;
    StartSpriteAnim(&gSprites[spriteId], animId);
    gSprites[spriteId].oam.priority = priority;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    return &gSprites[spriteId];
}

static void sub_80CD36C(void)
{
    if (gUnknown_02039D08->boxOption != BOX_OPTION_DEPOSIT)
        sBoxCursorArea = CURSOR_AREA_IN_BOX;
    else
        sBoxCursorArea = CURSOR_AREA_IN_PARTY;

    sBoxCursorPosition = 0;
    sIsMonBeingMoved = FALSE;
    sMovingMonOrigBoxId = 0;
    sMovingMonOrigBoxPos = 0;
    sCanOnlyMove = FALSE;
    sub_80CDC0C();
    sub_80CFC14();
    gUnknown_02039D08->field_CD6 = 1;
    gUnknown_02039D08->inBoxMovingMode = 0;
    sub_80CEB40();
}

static void sub_80CD3EC(void)
{
    sub_80CFC14();
    sub_80CEBDC();
    gUnknown_02039D08->field_CD6 = 1;
    gUnknown_02039D08->inBoxMovingMode = 0;
    if (sIsMonBeingMoved)
    {
        gUnknown_02039D08->movingMon = gUnknown_02039D14;
        CreateMovingMonIcon();
    }
}

void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y)
{
    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        *x = (cursorPosition % IN_BOX_ROWS) * 24 + 100;
        *y = (cursorPosition / IN_BOX_ROWS) * 24 +  32;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPosition == 0)
        {
            *x = 0x68;
            *y = 0x34;
        }
        else if (cursorPosition == PARTY_SIZE)
        {
            *x = 0x98;
            *y = 0x84;
        }
        else
        {
            *x = 0x98;
            *y = (cursorPosition - 1) * 24 + 4;
        }
        break;
    case CURSOR_AREA_BOX:
        *x = 0xa2;
        *y = 0x0c;
        break;
    case CURSOR_AREA_BUTTONS:
        *y = sIsMonBeingMoved ? 8 : 14;
        *x = cursorPosition * 0x58 + 0x78;
        break;
    case 4:
        *x = 0xa0;
        *y = 0x60;
        break;
    }
}

static u16 sub_80CD504(void)
{
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        return GetMonData(&gPlayerParty[sBoxCursorPosition], MON_DATA_SPECIES);
    case CURSOR_AREA_IN_BOX:
        return GetCurrentBoxMonData(sBoxCursorPosition, MON_DATA_SPECIES);
    default:
        return SPECIES_NONE;
    }
}

bool8 sub_80CD554(void)
{
    s16 tmp;

    if (gUnknown_02039D08->field_CD0 == 0)
    {
        if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
            return FALSE;
        else
            return sub_80D1218();
    }
    else if (--gUnknown_02039D08->field_CD0 != 0)
    {
        gUnknown_02039D08->field_CBC += gUnknown_02039D08->field_CC4;
        gUnknown_02039D08->field_CC0 += gUnknown_02039D08->field_CC8;
        gUnknown_02039D08->field_CB4->pos1.x = gUnknown_02039D08->field_CBC >> 8;
        gUnknown_02039D08->field_CB4->pos1.y = gUnknown_02039D08->field_CC0 >> 8;
        if (gUnknown_02039D08->field_CB4->pos1.x > 0x100)
        {
            tmp = gUnknown_02039D08->field_CB4->pos1.x - 0x100;
            gUnknown_02039D08->field_CB4->pos1.x = tmp + 0x40;
        }
        if (gUnknown_02039D08->field_CB4->pos1.x < 0x40)
        {
            tmp = 0x40 - gUnknown_02039D08->field_CB4->pos1.x;
            gUnknown_02039D08->field_CB4->pos1.x = 0x100 - tmp;
        }
        if (gUnknown_02039D08->field_CB4->pos1.y > 0xb0)
        {
            tmp = gUnknown_02039D08->field_CB4->pos1.y - 0xb0;
            gUnknown_02039D08->field_CB4->pos1.y = tmp - 0x10;
        }
        if (gUnknown_02039D08->field_CB4->pos1.y < -0x10)
        {
            tmp = -0x10 - gUnknown_02039D08->field_CB4->pos1.y;
            gUnknown_02039D08->field_CB4->pos1.y = 0xb0 - tmp;
        }
        if (gUnknown_02039D08->field_CD7 && --gUnknown_02039D08->field_CD7 == 0)
            gUnknown_02039D08->field_CB4->vFlip = (gUnknown_02039D08->field_CB4->vFlip == FALSE);
    }
    else
    {
        gUnknown_02039D08->field_CB4->pos1.x = gUnknown_02039D08->field_CCC;
        gUnknown_02039D08->field_CB4->pos1.y = gUnknown_02039D08->field_CCE;
        sub_80CDA68();
    }

    return TRUE;
}

static void sub_80CD6AC(u8 newCurosrArea, u8 newCursorPosition)
{
    u16 x, y;

    sub_80CD444(newCurosrArea, newCursorPosition, &x, &y);
    gUnknown_02039D08->field_CD4 = newCurosrArea;
    gUnknown_02039D08->field_CD5 = newCursorPosition;
    gUnknown_02039D08->field_CCC = x;
    gUnknown_02039D08->field_CCE = y;
}

static void sub_80CD70C(void)
{
    int r7, r0;

    if (gUnknown_02039D08->field_CD2 != 0 || gUnknown_02039D08->field_CD3 != 0)
        gUnknown_02039D08->field_CD0 = 12;
    else
        gUnknown_02039D08->field_CD0 = 6;

    if (gUnknown_02039D08->field_CD7)
        gUnknown_02039D08->field_CD7 = gUnknown_02039D08->field_CD0 >> 1;

    switch (gUnknown_02039D08->field_CD2)
    {
        default:
            r7 = gUnknown_02039D08->field_CCE - gUnknown_02039D08->field_CB4->pos1.y;
            break;
        case -1:
            r7 = gUnknown_02039D08->field_CCE - 0xc0 - gUnknown_02039D08->field_CB4->pos1.y;
            break;
        case 1:
            r7 = gUnknown_02039D08->field_CCE + 0xc0 - gUnknown_02039D08->field_CB4->pos1.y;
            break;
    }

    switch (gUnknown_02039D08->field_CD3)
    {
        default:
            r0 = gUnknown_02039D08->field_CCC - gUnknown_02039D08->field_CB4->pos1.x;
            break;
        case -1:
            r0 = gUnknown_02039D08->field_CCC - 0xc0 - gUnknown_02039D08->field_CB4->pos1.x;
            break;
        case 1:
            r0 = gUnknown_02039D08->field_CCC + 0xc0 - gUnknown_02039D08->field_CB4->pos1.x;
            break;
    }

    r7 <<= 8;
    r0 <<= 8;
    gUnknown_02039D08->field_CC4 = r0 / gUnknown_02039D08->field_CD0;
    gUnknown_02039D08->field_CC8 = r7 / gUnknown_02039D08->field_CD0;
    gUnknown_02039D08->field_CBC = gUnknown_02039D08->field_CB4->pos1.x << 8;
    gUnknown_02039D08->field_CC0 = gUnknown_02039D08->field_CB4->pos1.y << 8;
}

static void sub_80CD894(u8 newCurosrArea, u8 newCursorPosition)
{
    sub_80CD6AC(newCurosrArea, newCursorPosition);
    sub_80CD70C();
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        if (gUnknown_02039D08->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 1);
    }
    else
    {
        if (!sub_80D127C())
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 1);
    }

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
        else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            sub_80D0E50(CURSOR_AREA_IN_PARTY, sBoxCursorPosition);

        if (newCurosrArea == CURSOR_AREA_IN_BOX)
            sub_80D0D8C(newCurosrArea, newCursorPosition);
        else if (newCurosrArea == CURSOR_AREA_IN_PARTY)
            sub_80D0D8C(newCurosrArea, newCursorPosition);
    }

    if (newCurosrArea == CURSOR_AREA_IN_PARTY && sBoxCursorArea != CURSOR_AREA_IN_PARTY)
    {
        gUnknown_02039D08->field_CD6 = newCurosrArea;
        gUnknown_02039D08->field_CB8->invisible = TRUE;
    }

    switch (newCurosrArea)
    {
    case CURSOR_AREA_IN_PARTY:
    case CURSOR_AREA_BOX:
    case CURSOR_AREA_BUTTONS:
        gUnknown_02039D08->field_CB4->oam.priority = 1;
        gUnknown_02039D08->field_CB8->invisible = TRUE;
        gUnknown_02039D08->field_CB8->oam.priority = 1;
        break;
    case CURSOR_AREA_IN_BOX:
        if (gUnknown_02039D08->inBoxMovingMode != 0)
        {
            gUnknown_02039D08->field_CB4->oam.priority = 0;
            gUnknown_02039D08->field_CB8->invisible = TRUE;
        }
        else
        {
            gUnknown_02039D08->field_CB4->oam.priority = 2;
            if (sBoxCursorArea == CURSOR_AREA_IN_BOX && sIsMonBeingMoved)
                SetMovingMonPriority(2);
        }
        break;
    }
}

static void sub_80CDA68(void)
{
    sBoxCursorArea = gUnknown_02039D08->field_CD4;
    sBoxCursorPosition = gUnknown_02039D08->field_CD5;
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        if (gUnknown_02039D08->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 0);
    }
    else
    {
        if (!sub_80D127C())
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 0);
    }

    sub_80CEB40();
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_BUTTONS:
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_BOX:
        sub_80CD1A8(TRUE);
        break;
    case CURSOR_AREA_IN_PARTY:
        gUnknown_02039D08->field_CB8->subpriority = 13;
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_IN_BOX:
        if (gUnknown_02039D08->inBoxMovingMode == 0)
        {
            gUnknown_02039D08->field_CB4->oam.priority = 1;
            gUnknown_02039D08->field_CB8->oam.priority = 2;
            gUnknown_02039D08->field_CB8->subpriority = 21;
            gUnknown_02039D08->field_CB8->invisible = FALSE;
            SetMovingMonPriority(2);
        }
        break;
    }
}

static void sub_80CDBA0(void)
{
    u8 partyCount;

    if (!sIsMonBeingMoved)
    {
        partyCount = 0;
    }
    else
    {
        partyCount = CalculatePlayerPartyCount();
        if (partyCount >= PARTY_SIZE)
            partyCount = PARTY_SIZE - 1;
    }
    if (gUnknown_02039D08->field_CB4->vFlip)
        gUnknown_02039D08->field_CD7 = 1;
    sub_80CD894(CURSOR_AREA_IN_PARTY, partyCount);
}

static void sub_80CDBF8(u8 cursorBoxPosition)
{
    sub_80CD894(CURSOR_AREA_IN_BOX, cursorBoxPosition);
}

static void sub_80CDC0C(void)
{
    gUnknown_02039D7E = 0;
}

static void sub_80CDC18(void)
{
    gUnknown_02039D7E = sBoxCursorPosition;
}

u8 sub_80CDC2C(void)
{
    return gUnknown_02039D7E;
}

void InitMonPlaceChange(u8 a0)
{
    static bool8 (*const placeChangeFuncs[])(void) =
    {
        MonPlaceChange_Move,
        MonPlaceChange_Place,
        MonPlaceChange_Shift,
    };

    gUnknown_02039D08->monPlaceChangeFunc = placeChangeFuncs[a0];
    gUnknown_02039D08->monPlaceChangeState = 0;
}

void sub_80CDC64(bool8 arg0)
{
    if (!arg0)
        gUnknown_02039D08->monPlaceChangeFunc = sub_80CDEB4;
    else
        gUnknown_02039D08->monPlaceChangeFunc = sub_80CDEC4;

    gUnknown_02039D08->monPlaceChangeState = 0;
}

bool8 DoMonPlaceChange(void)
{
    return gUnknown_02039D08->monPlaceChangeFunc();
}

static bool8 MonPlaceChange_Move(void)
{
    switch (gUnknown_02039D08->monPlaceChangeState)
    {
    case 0:
        if (sIsMonBeingMoved)
            return FALSE;
        StartSpriteAnim(gUnknown_02039D08->field_CB4, 2);
        gUnknown_02039D08->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 3);
            MoveMon();
            gUnknown_02039D08->monPlaceChangeState++;
        }
        break;
    case 2:
        if (!sub_80CDF08())
            gUnknown_02039D08->monPlaceChangeState++;
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Place(void)
{
    switch (gUnknown_02039D08->monPlaceChangeState)
    {
    case 0:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 2);
            PlaceMon();
            gUnknown_02039D08->monPlaceChangeState++;
        }
        break;
    case 1:
        if (!sub_80CDF08())
        {
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 0);
            gUnknown_02039D08->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Shift(void)
{
    switch (gUnknown_02039D08->monPlaceChangeState)
    {
    case 0:
        switch (sBoxCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            gUnknown_02039D08->field_D91 = TOTAL_BOXES_COUNT;
            break;
        case CURSOR_AREA_IN_BOX:
            gUnknown_02039D08->field_D91 = StorageGetCurrentBox();
            break;
        default:
            return FALSE;
        }
        StartSpriteAnim(gUnknown_02039D08->field_CB4, 2);
        sub_80CBD5C(gUnknown_02039D08->field_D91, sBoxCursorPosition);
        gUnknown_02039D08->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_80CBDC4())
        {
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 3);
            SetShiftedMonData(gUnknown_02039D08->field_D91, sBoxCursorPosition);
            gUnknown_02039D08->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool8 sub_80CDEB4(void)
{
    return sub_80CDED4();
}

static bool8 sub_80CDEC4(void)
{
    return sub_80CDF08();
}

static bool8 sub_80CDED4(void)
{
    switch (gUnknown_02039D08->field_CB4->pos2.y)
    {
    default:
        gUnknown_02039D08->field_CB4->pos2.y++;
        break;
    case 0:
        gUnknown_02039D08->field_CB4->pos2.y++;
        break;
    case 8:
        return FALSE;
    }

    return TRUE;
}

static bool8 sub_80CDF08(void)
{
    switch (gUnknown_02039D08->field_CB4->pos2.y)
    {
    case 0:
        return FALSE;
    default:
        gUnknown_02039D08->field_CB4->pos2.y--;
        break;
    }

    return TRUE;
}

void MoveMon(void)
{
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        SetMovedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        sub_80CBC14(MODE_PARTY, sBoxCursorPosition);
        break;
    case CURSOR_AREA_IN_BOX:
        if (gUnknown_02039D08->inBoxMovingMode == 0)
        {
            SetMovedMonData(StorageGetCurrentBox(), sBoxCursorPosition);
            sub_80CBC14(MODE_BOX, sBoxCursorPosition);
        }
        break;
    default:
        return;
    }

    sIsMonBeingMoved = TRUE;
}

void PlaceMon(void)
{
    u8 boxId;

    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        SetPlacedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        sub_80CBCAC(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        break;
    case CURSOR_AREA_IN_BOX:
        boxId = StorageGetCurrentBox();
        SetPlacedMonData(boxId, sBoxCursorPosition);
        sub_80CBCAC(boxId, sBoxCursorPosition);
        break;
    default:
        return;
    }

    sIsMonBeingMoved = FALSE;
}

static void sub_80CE00C(void)
{
    sub_80CEB40();
}

static void SetMovedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        gUnknown_02039D08->movingMon = gPlayerParty[sBoxCursorPosition];
    else
        BoxMonAtToMon(boxId, position, &gUnknown_02039D08->movingMon);

    PurgeMonOrBoxMon(boxId, position);
    sMovingMonOrigBoxId = boxId;
    sMovingMonOrigBoxPos = position;
}

static void SetPlacedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
    {
        gPlayerParty[position] = gUnknown_02039D08->movingMon;
    }
    else
    {
        BoxMonRestorePP(&gUnknown_02039D08->movingMon.box);
        SetBoxMonAt(boxId, position, &gUnknown_02039D08->movingMon.box);
    }
}

void PurgeMonOrBoxMon(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        ZeroMonData(&gPlayerParty[position]);
    else
        ZeroBoxMonAt(boxId, position);
}

static void SetShiftedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        gUnknown_02039D08->field_2108 = gPlayerParty[position];
    else
        BoxMonAtToMon(boxId, position, &gUnknown_02039D08->field_2108);

    SetPlacedMonData(boxId, position);
    gUnknown_02039D08->movingMon = gUnknown_02039D08->field_2108;
    SetCursorMonData(&gUnknown_02039D08->movingMon, MODE_PARTY);
    sMovingMonOrigBoxId = boxId;
    sMovingMonOrigBoxPos = position;
}

static bool8 TryStorePartyMonInBox(u8 boxId)
{
    s16 boxPosition = GetFirstFreeBoxSpot(boxId);
    if (boxPosition == -1)
        return FALSE;

    if (sIsMonBeingMoved)
    {
        SetPlacedMonData(boxId, boxPosition);
        DestroyMovingMonIcon();
        sIsMonBeingMoved = FALSE;
    }
    else
    {
        SetMovedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        SetPlacedMonData(boxId, boxPosition);
        DestroyPartyMonIcon(sBoxCursorPosition);
    }

    if (boxId == StorageGetCurrentBox())
        sub_80CB140(boxPosition);

    StartSpriteAnim(gUnknown_02039D08->field_CB4, 1);
    return TRUE;
}

static void sub_80CE22C(void)
{
    StartSpriteAnim(gUnknown_02039D08->field_CB4, 0);
    sub_80CEB40();
}

static void sub_80CE250(void)
{
    u8 mode;

    if (sIsMonBeingMoved)
        mode = MODE_2;
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        mode = MODE_PARTY;
    else
        mode = MODE_BOX;

    sub_80CBF14(mode, sBoxCursorPosition);
    StringCopy(gUnknown_02039D08->field_21E0, gUnknown_02039D08->cursorMonNick);
}

static bool8 sub_80CE2A8(void)
{
    if (!sub_80CBFD8())
    {
        StartSpriteAnim(gUnknown_02039D08->field_CB4, 0);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void ReleaseMon(void)
{
    u8 boxId;

    sub_80CC020();
    if (sIsMonBeingMoved)
    {
        sIsMonBeingMoved = FALSE;
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            boxId = TOTAL_BOXES_COUNT;
        else
            boxId = StorageGetCurrentBox();

        PurgeMonOrBoxMon(boxId, sBoxCursorPosition);
    }
    sub_80CEB40();
}

static void sub_80CE324(void)
{
    if (sIsMonBeingMoved)
        StartSpriteAnim(gUnknown_02039D08->field_CB4, 3);
}

struct
{
    s8 mapGroup;
    s8 mapNum;
    u16 move;
} static const gUnknown_0857B9A4[] =
{
    {MAP_GROUPS_COUNT, 0, MOVE_SURF},
    {MAP_GROUPS_COUNT, 0, MOVE_DIVE},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MOVE_STRENGTH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MOVE_ROCK_SMASH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MOVE_STRENGTH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MOVE_ROCK_SMASH},
};

static void sub_80CE350(u16 *moves)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_0857B9A4); i++)
    {
        if (gUnknown_0857B9A4[i].mapGroup == MAP_GROUPS_COUNT
            || (gUnknown_0857B9A4[i].mapGroup == gSaveBlock1Ptr->location.mapGroup && gUnknown_0857B9A4[i].mapNum == gSaveBlock1Ptr->location.mapNum))
        {
            *moves = gUnknown_0857B9A4[i].move;
            moves++;
        }
    }

    *moves = MOVES_COUNT;
}

void InitCanRelaseMonVars(void)
{
    if (!AtLeastThreeUsableMons())
    {
        gUnknown_02039D08->field_216D = 1;
        gUnknown_02039D08->field_216C = 0;
        return;
    }

    if (sIsMonBeingMoved)
    {
        gUnknown_02039D08->field_2108 = gUnknown_02039D08->movingMon;
        gUnknown_02039D08->field_2170 = -1;
        gUnknown_02039D08->field_2171 = -1;
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        {
            gUnknown_02039D08->field_2108 = gPlayerParty[sBoxCursorPosition];
            gUnknown_02039D08->field_2170 = TOTAL_BOXES_COUNT;
        }
        else
        {
            BoxMonAtToMon(StorageGetCurrentBox(), sBoxCursorPosition, &gUnknown_02039D08->field_2108);
            gUnknown_02039D08->field_2170 = StorageGetCurrentBox();
        }
        gUnknown_02039D08->field_2171 = sBoxCursorPosition;
    }

    sub_80CE350(gUnknown_02039D08->field_2176);
    gUnknown_02039D08->field_2174 = GetMonData(&gUnknown_02039D08->field_2108, MON_DATA_KNOWN_MOVES, gUnknown_02039D08->field_2176);
    if (gUnknown_02039D08->field_2174 != 0)
    {
        gUnknown_02039D08->field_216D = 0;
    }
    else
    {
        gUnknown_02039D08->field_216D = 1;
        gUnknown_02039D08->field_216C = 1;
    }

    gUnknown_02039D08->field_2172 = 0;
}

bool32 AtLeastThreeUsableMons(void)
{
    s32 i, j, count;

    count = (sIsMonBeingMoved != FALSE);
    for (j = 0; j < PARTY_SIZE; j++)
    {
        if (GetMonData(&gPlayerParty[j], MON_DATA_SANITY_HAS_SPECIES))
            count++;
    }

    if (count >= 3)
        return TRUE;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (CheckBoxedMonSanity(i, j))
            {
                if (++count >= 3)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

s8 RunCanReleaseMon(void)
{
    u16 i;
    u16 knownMoves;

    if (gUnknown_02039D08->field_216D)
        return gUnknown_02039D08->field_216C;

    switch (gUnknown_02039D08->field_2172)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gUnknown_02039D08->field_2170 != TOTAL_BOXES_COUNT || gUnknown_02039D08->field_2171 != i)
            {
                knownMoves = GetMonData(gPlayerParty + i, MON_DATA_KNOWN_MOVES, gUnknown_02039D08->field_2176);
                gUnknown_02039D08->field_2174 &= ~(knownMoves);
            }
        }
        if (gUnknown_02039D08->field_2174 == 0)
        {
            gUnknown_02039D08->field_216D = 1;
            gUnknown_02039D08->field_216C = 1;
        }
        else
        {
            gUnknown_02039D08->field_216E = 0;
            gUnknown_02039D08->field_216F = 0;
            gUnknown_02039D08->field_2172++;
        }
        break;
    case 1:
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            knownMoves = GetAndCopyBoxMonDataAt(gUnknown_02039D08->field_216E, gUnknown_02039D08->field_216F, MON_DATA_KNOWN_MOVES, gUnknown_02039D08->field_2176);
            if (knownMoves != 0
                && !(gUnknown_02039D08->field_2170 == gUnknown_02039D08->field_216E && gUnknown_02039D08->field_2171 == gUnknown_02039D08->field_216F))
            {
                gUnknown_02039D08->field_2174 &= ~(knownMoves);
                if (gUnknown_02039D08->field_2174 == 0)
                {
                    gUnknown_02039D08->field_216D = 1;
                    gUnknown_02039D08->field_216C = 1;
                    break;
                }
            }
            if (++gUnknown_02039D08->field_216F >= IN_BOX_COUNT)
            {
                gUnknown_02039D08->field_216F = 0;
                if (++gUnknown_02039D08->field_216E >= TOTAL_BOXES_COUNT)
                {
                    gUnknown_02039D08->field_216D = 1;
                    gUnknown_02039D08->field_216C = 0;
                }
            }
        }
        break;
    }

    return -1;
}

static void sub_80CE760(void)
{
    if (sIsMonBeingMoved)
        gUnknown_02039D14 = gUnknown_02039D08->movingMon;
}

static void sub_80CE790(void)
{
    if (sIsMonBeingMoved)
    {
        if (sMovingMonOrigBoxId == TOTAL_BOXES_COUNT)
            gUnknown_02039D08->movingMon = gUnknown_02039D14;
        else
            gUnknown_02039D08->movingMon.box = gUnknown_02039D14.box;
    }
}

static void sub_80CE7E8(void)
{
    if (sIsMonBeingMoved)
    {
        sub_80CE760();
        gUnknown_02039D08->field_218C.mon = &gUnknown_02039D14;
        gUnknown_02039D08->field_2187 = 0;
        gUnknown_02039D08->field_2186 = 0;
        gUnknown_02039D08->field_2188 = 0;
    }
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
    {
        gUnknown_02039D08->field_218C.mon = gPlayerParty;
        gUnknown_02039D08->field_2187 = sBoxCursorPosition;
        gUnknown_02039D08->field_2186 = CountPartyMons() - 1;
        gUnknown_02039D08->field_2188 = 0;
    }
    else
    {
        gUnknown_02039D08->field_218C.box = GetBoxedMonPtr(StorageGetCurrentBox(), 0);
        gUnknown_02039D08->field_2187 = sBoxCursorPosition;
        gUnknown_02039D08->field_2186 = IN_BOX_COUNT - 1;
        gUnknown_02039D08->field_2188 = 2;
    }
}

static void sub_80CE8E4(void)
{
    if (sIsMonBeingMoved)
        sub_80CE790();
    else
        sBoxCursorPosition = gUnknown_0203CF20;
}

s16 CompactPartySlots(void)
{
    s16 retVal = -1;
    u16 i, last;

    for (i = 0, last = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(gPlayerParty + i, MON_DATA_SPECIES);
        if (species != SPECIES_NONE)
        {
            if (i != last)
                gPlayerParty[last] = gPlayerParty[i];
            last++;
        }
        else if (retVal == -1)
            retVal = i;
    }
    for (; last < PARTY_SIZE; last++)
        ZeroMonData(gPlayerParty + last);

    return retVal;
}

static void SetMonMarkings(u8 markings)
{
    gUnknown_02039D08->cursorMonMarkings = markings;
    if (sIsMonBeingMoved)
    {
        SetMonData(&gUnknown_02039D08->movingMon, MON_DATA_MARKINGS, &markings);
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            SetMonData(gPlayerParty + sBoxCursorPosition, MON_DATA_MARKINGS, &markings);
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            SetCurrentBoxMonData(sBoxCursorPosition, MON_DATA_MARKINGS, &markings);
    }
}

static bool8 CanMovePartyMon(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_PARTY && !sIsMonBeingMoved && CountPartyAliveNonEggMonsExcept(sBoxCursorPosition) == 0)
        return TRUE;
    else
        return FALSE;
}

static bool8 CanShifMon(void)
{
    if (sIsMonBeingMoved)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY && CountPartyAliveNonEggMonsExcept(sBoxCursorPosition) == 0)
        {
            if (gUnknown_02039D08->cursorMonIsEgg || GetMonData(&gUnknown_02039D08->movingMon, MON_DATA_HP) == 0)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

static bool8 IsMonBeingMoved(void)
{
    return sIsMonBeingMoved;
}

static bool8 IsCursorOnBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_BOX);
}

static bool8 IsCursorOnCloseBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_BUTTONS && sBoxCursorPosition == 1);
}

static bool8 IsCursorInBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_IN_BOX);
}

static void sub_80CEB40(void)
{
    gUnknown_02039D08->field_CEA = (sIsMonBeingMoved == FALSE);
    if (!sIsMonBeingMoved)
    {
        switch (sBoxCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            if (sBoxCursorPosition < PARTY_SIZE)
            {
                SetCursorMonData(&gPlayerParty[sBoxCursorPosition], MODE_PARTY);
                break;
            }
            // fallthrough
        case CURSOR_AREA_BUTTONS:
        case CURSOR_AREA_BOX:
            SetCursorMonData(NULL, MODE_2);
            break;
        case CURSOR_AREA_IN_BOX:
            SetCursorMonData(GetBoxedMonPtr(StorageGetCurrentBox(), sBoxCursorPosition), MODE_BOX);
            break;
        }
    }
}

static void sub_80CEBDC(void)
{
    if (sIsMonBeingMoved)
        SetCursorMonData(&gUnknown_02039D14, MODE_PARTY);
    else
        sub_80CEB40();
}

static void SetCursorMonData(void *pokemon, u8 mode)
{
    u8 *txtPtr;
    u16 gender;
    bool8 sanityIsBagEgg;

    gUnknown_02039D08->cursorMonItem = 0;
    gender = MON_MALE;
    sanityIsBagEgg = FALSE;
    if (mode == MODE_PARTY)
    {
        struct Pokemon *mon = (struct Pokemon *)pokemon;

        gUnknown_02039D08->cursorMonSpecies = GetMonData(mon, MON_DATA_SPECIES2);
        if (gUnknown_02039D08->cursorMonSpecies != SPECIES_NONE)
        {
            sanityIsBagEgg = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBagEgg)
                gUnknown_02039D08->cursorMonIsEgg = TRUE;
            else
                gUnknown_02039D08->cursorMonIsEgg = GetMonData(mon, MON_DATA_IS_EGG);

            GetMonData(mon, MON_DATA_NICKNAME, gUnknown_02039D08->cursorMonNick);
            StringGetEnd10(gUnknown_02039D08->cursorMonNick);
            gUnknown_02039D08->cursorMonLevel = GetMonData(mon, MON_DATA_LEVEL);
            gUnknown_02039D08->cursorMonMarkings = GetMonData(mon, MON_DATA_MARKINGS);
            gUnknown_02039D08->cursorMonPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
            gUnknown_02039D08->cursorMonPalette = GetMonFrontSpritePal(mon);
            gender = GetMonGender(mon);
            gUnknown_02039D08->cursorMonItem = GetMonData(mon, MON_DATA_HELD_ITEM);
        }
    }
    else if (mode == MODE_BOX)
    {
        struct BoxPokemon *boxMon = (struct BoxPokemon *)pokemon;

        gUnknown_02039D08->cursorMonSpecies = GetBoxMonData(pokemon, MON_DATA_SPECIES2);
        if (gUnknown_02039D08->cursorMonSpecies != SPECIES_NONE)
        {
            u32 otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
            sanityIsBagEgg = GetBoxMonData(boxMon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBagEgg)
                gUnknown_02039D08->cursorMonIsEgg = TRUE;
            else
                gUnknown_02039D08->cursorMonIsEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG);


            GetBoxMonData(boxMon, MON_DATA_NICKNAME, gUnknown_02039D08->cursorMonNick);
            StringGetEnd10(gUnknown_02039D08->cursorMonNick);
            gUnknown_02039D08->cursorMonLevel = GetLevelFromBoxMonExp(boxMon);
            gUnknown_02039D08->cursorMonMarkings = GetBoxMonData(boxMon, MON_DATA_MARKINGS);
            gUnknown_02039D08->cursorMonPersonality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
            gUnknown_02039D08->cursorMonPalette = GetFrontSpritePalFromSpeciesAndPersonality(gUnknown_02039D08->cursorMonSpecies, otId, gUnknown_02039D08->cursorMonPersonality);
            gender = GetGenderFromSpeciesAndPersonality(gUnknown_02039D08->cursorMonSpecies, gUnknown_02039D08->cursorMonPersonality);
            gUnknown_02039D08->cursorMonItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
        }
    }
    else
    {
        gUnknown_02039D08->cursorMonSpecies = SPECIES_NONE;
        gUnknown_02039D08->cursorMonItem = 0;
    }

    if (gUnknown_02039D08->cursorMonSpecies == SPECIES_NONE)
    {
        StringFill(gUnknown_02039D08->cursorMonNick, CHAR_SPACE, 5);
        StringFill(gUnknown_02039D08->cursorMonNickText, CHAR_SPACE, 8);
        StringFill(gUnknown_02039D08->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(gUnknown_02039D08->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(gUnknown_02039D08->cursorMonItemName, CHAR_SPACE, 8);
    }
    else if (gUnknown_02039D08->cursorMonIsEgg)
    {
        if (sanityIsBagEgg)
            StringCopyPadded(gUnknown_02039D08->cursorMonNickText, gUnknown_02039D08->cursorMonNick, CHAR_SPACE, 5);
        else
            StringCopyPadded(gUnknown_02039D08->cursorMonNickText, gText_EggNickname, CHAR_SPACE, 8);

        StringFill(gUnknown_02039D08->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(gUnknown_02039D08->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(gUnknown_02039D08->cursorMonItemName, CHAR_SPACE, 8);
    }
    else
    {
        if (gUnknown_02039D08->cursorMonSpecies == SPECIES_NIDORAN_F || gUnknown_02039D08->cursorMonSpecies == SPECIES_NIDORAN_M)
            gender = MON_GENDERLESS;

        StringCopyPadded(gUnknown_02039D08->cursorMonNickText, gUnknown_02039D08->cursorMonNick, CHAR_SPACE, 5);

        txtPtr = gUnknown_02039D08->cursorMonSpeciesName;
        *(txtPtr)++ = CHAR_SLASH;
        StringCopyPadded(txtPtr, gSpeciesNames[gUnknown_02039D08->cursorMonSpecies], CHAR_SPACE, 5);

        txtPtr = gUnknown_02039D08->cursorMonGenderLvlText;
        *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
        *(txtPtr)++ = 4;
        switch (gender)
        {
        case MON_MALE:
            *(txtPtr)++ = 4;
            *(txtPtr)++ = 1;
            *(txtPtr)++ = 5;
            *(txtPtr)++ = CHAR_MALE;
            break;
        case MON_FEMALE:
            *(txtPtr)++ = 6;
            *(txtPtr)++ = 1;
            *(txtPtr)++ = 7;
            *(txtPtr)++ = CHAR_FEMALE;
            break;
        default:
            *(txtPtr)++ = 2;
            *(txtPtr)++ = 1;
            *(txtPtr)++ = 3;
            *(txtPtr)++ = 0x77;
            break;
        }

        *(txtPtr++) = EXT_CTRL_CODE_BEGIN;
        *(txtPtr++) = 4;
        *(txtPtr++) = 2;
        *(txtPtr++) = 1;
        *(txtPtr++) = 3;
        *(txtPtr++) = 0;
        *(txtPtr++) = CHAR_SPECIAL_F9;
        *(txtPtr++) = 5;

        txtPtr = ConvertIntToDecimalStringN(txtPtr, gUnknown_02039D08->cursorMonLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        txtPtr[0] = CHAR_SPACE;
        txtPtr[1] = EOS;

        if (gUnknown_02039D08->cursorMonItem != 0)
            StringCopyPadded(gUnknown_02039D08->cursorMonItemName, ItemId_GetName(gUnknown_02039D08->cursorMonItem), CHAR_SPACE, 8);
        else
            StringFill(gUnknown_02039D08->cursorMonItemName, CHAR_SPACE, 8);
    }
}

static u8 HandleInput_InBox(void)
{
    switch (gUnknown_02039D08->inBoxMovingMode)
    {
    case 0:
    default:
        return InBoxInput_Normal();
    case 1:
        return InBoxInput_GrabbingMultiple();
    case 2:
        return InBoxInput_MovingMultiple();
    }
}

// This group of four functions handling input simply CANNOT be matched.
// GF must have written them in a really weird way, a way not a sane person could dream to reproduce.
#ifdef NONMATCHING
static u8 InBoxInput_Normal(void)
{
    u8 retVal;
    s8 cursorArea = sBoxCursorArea;
    s8 cursorPosition = sBoxCursorPosition;

    gUnknown_02039D08->field_CD2 = 0;
    gUnknown_02039D08->field_CD3 = 0;
    gUnknown_02039D08->field_CD7 = 0;
    retVal = 0;
    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            retVal = TRUE;
            cursorPosition += IN_BOX_ROWS;
            if (cursorPosition >= IN_BOX_COUNT)
            {
                cursorArea = CURSOR_AREA_BUTTONS;
                cursorPosition -= IN_BOX_COUNT;
                cursorPosition /= 3;
                gUnknown_02039D08->field_CD2 = 1;
                gUnknown_02039D08->field_CD7 = 1;
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        {
            retVal = TRUE;
            if (sBoxCursorPosition % IN_BOX_ROWS != 0)
            {
                cursorPosition--;
            }
            else
            {
                gUnknown_02039D08->field_CD3 = -1;
                cursorPosition += (IN_BOX_ROWS - 1);
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        {
            retVal = TRUE;
            if ((sBoxCursorPosition + 1) % IN_BOX_ROWS != 0)
            {
                cursorPosition++;
            }
            else
            {
                gUnknown_02039D08->field_CD3 = 1;
                cursorPosition -= (IN_BOX_ROWS - 1);
            }
        }
        else if (gMain.newKeys & START_BUTTON)
        {
            retVal = TRUE;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
        }
        else
        {
            if ((gMain.newKeys & A_BUTTON) && sub_80CFA5C())
            {
                if (!sCanOnlyMove)
                    return 8;

                if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_MONS || sIsMonBeingMoved == TRUE)
                {
                    switch (sub_80CFF98(0))
                    {
                    case 1:
                        return 11;
                    case 2:
                        return 12;
                    case 3:
                        return 13;
                    case 4:
                        return 14;
                    case 5:
                        return 15;
                    case 12:
                        return 16;
                    case 13:
                        return 17;
                    case 15:
                        return 18;
                    }
                }
                else
                {
                    gUnknown_02039D08->inBoxMovingMode = 1;
                    return 20;
                }
            }

            if (gMain.newKeys & B_BUTTON)
                return 19;

            if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
            {
                if (gMain.heldKeys & L_BUTTON)
                    return 10;
                if (gMain.heldKeys & R_BUTTON)
                    return 9;
            }

            if (gMain.newKeys & SELECT_BUTTON)
            {
                sub_80CFDC4();
                return 0;
            }
            retVal = FALSE;
        }
    }
    else
    {
        retVal = TRUE;
        if (sBoxCursorPosition >= IN_BOX_ROWS)
        {
            cursorPosition -= IN_BOX_ROWS;
        }
        else
        {
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
        }
    }

    if (retVal)
        sub_80CD894(cursorArea, cursorPosition);

    return retVal;
}
#else
NAKED
static u8 InBoxInput_Normal(void)
{
    asm_unified("\n\
                	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	ldr r0, =sBoxCursorArea\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldr r2, =sBoxCursorPosition\n\
	ldrb r4, [r2]\n\
	ldr r5, =gUnknown_02039D08\n\
	ldr r0, [r5]\n\
	ldr r1, =0x00000cd2\n\
	mov r10, r1\n\
	add r0, r10\n\
	movs r1, 0\n\
	strb r1, [r0]\n\
	ldr r0, [r5]\n\
	ldr r7, =0x00000cd3\n\
	adds r0, r7\n\
	strb r1, [r0]\n\
	ldr r0, [r5]\n\
	ldr r3, =0x00000cd7\n\
	mov r9, r3\n\
	add r0, r9\n\
	strb r1, [r0]\n\
	ldr r6, =gMain\n\
	ldrh r1, [r6, 0x30]\n\
	movs r0, 0x40\n\
	ands r0, r1\n\
	adds r3, r2, 0\n\
	cmp r0, 0\n\
	beq _080CF14C\n\
	b _080CF33C\n\
_080CF14C:\n\
	movs r0, 0x80\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF1A8\n\
	movs r6, 0x1\n\
	lsls r0, r4, 24\n\
	movs r1, 0xC0\n\
	lsls r1, 19\n\
	adds r0, r1\n\
	lsrs r4, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x1D\n\
	bgt _080CF168\n\
	b _080CF358\n\
_080CF168:\n\
	movs r2, 0x3\n\
	mov r8, r2\n\
	subs r0, 0x1E\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	movs r1, 0x3\n\
	bl __divsi3\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	ldr r0, [r5]\n\
	add r0, r10\n\
	strb r6, [r0]\n\
	ldr r0, [r5]\n\
	add r0, r9\n\
	strb r6, [r0]\n\
	b _080CF358\n\
	.pool\n\
_080CF1A8:\n\
	movs r0, 0x20\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF1DE\n\
	movs r6, 0x1\n\
	movs r0, 0\n\
	ldrsb r0, [r3, r0]\n\
	movs r1, 0x6\n\
	bl __modsi3\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080CF1CA\n\
	lsls r0, r4, 24\n\
	movs r3, 0xFF\n\
	lsls r3, 24\n\
	b _080CF34C\n\
_080CF1CA:\n\
	ldr r0, [r5]\n\
	adds r0, r7\n\
	movs r1, 0xFF\n\
	strb r1, [r0]\n\
	lsls r0, r4, 24\n\
	movs r1, 0xA0\n\
	lsls r1, 19\n\
	adds r0, r1\n\
	lsrs r4, r0, 24\n\
	b _080CF358\n\
_080CF1DE:\n\
	movs r0, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF212\n\
	movs r6, 0x1\n\
	movs r0, 0\n\
	ldrsb r0, [r3, r0]\n\
	adds r0, 0x1\n\
	movs r1, 0x6\n\
	bl __modsi3\n\
	cmp r0, 0\n\
	beq _080CF204\n\
	lsls r0, r4, 24\n\
	movs r2, 0x80\n\
	lsls r2, 17\n\
	adds r0, r2\n\
	lsrs r4, r0, 24\n\
	b _080CF358\n\
_080CF204:\n\
	ldr r0, [r5]\n\
	adds r0, r7\n\
	strb r6, [r0]\n\
	lsls r0, r4, 24\n\
	movs r3, 0xFB\n\
	lsls r3, 24\n\
	b _080CF34C\n\
_080CF212:\n\
	ldrh r1, [r6, 0x2E]\n\
	movs r0, 0x8\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF220\n\
	movs r6, 0x1\n\
	b _080CF352\n\
_080CF220:\n\
	movs r4, 0x1\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF2E4\n\
	bl sub_80CFA5C\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080CF2E4\n\
	ldr r0, =sCanOnlyMove\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	bne _080CF244\n\
	movs r0, 0x8\n\
	b _080CF366\n\
	.pool\n\
_080CF244:\n\
	ldr r1, [r5]\n\
	ldrb r0, [r1, 0x1]\n\
	cmp r0, 0x2\n\
	bne _080CF254\n\
	ldr r0, =sIsMonBeingMoved\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x1\n\
	bne _080CF2D4\n\
_080CF254:\n\
	movs r0, 0\n\
	bl sub_80CFF98\n\
	subs r0, 0x1\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0xE\n\
	bhi _080CF2E4\n\
	lsls r0, 2\n\
	ldr r1, =_080CF278\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_080CF278:\n\
	.4byte _080CF2B4\n\
	.4byte _080CF2B8\n\
	.4byte _080CF2BC\n\
	.4byte _080CF2C0\n\
	.4byte _080CF2C4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2C8\n\
	.4byte _080CF2CC\n\
	.4byte _080CF2E4\n\
	.4byte _080CF2D0\n\
_080CF2B4:\n\
	movs r0, 0xB\n\
	b _080CF366\n\
_080CF2B8:\n\
	movs r0, 0xC\n\
	b _080CF366\n\
_080CF2BC:\n\
	movs r0, 0xD\n\
	b _080CF366\n\
_080CF2C0:\n\
	movs r0, 0xE\n\
	b _080CF366\n\
_080CF2C4:\n\
	movs r0, 0xF\n\
	b _080CF366\n\
_080CF2C8:\n\
	movs r0, 0x10\n\
	b _080CF366\n\
_080CF2CC:\n\
	movs r0, 0x11\n\
	b _080CF366\n\
_080CF2D0:\n\
	movs r0, 0x12\n\
	b _080CF366\n\
_080CF2D4:\n\
	ldr r2, =0x000021ff\n\
	adds r0, r1, r2\n\
	strb r4, [r0]\n\
	movs r0, 0x14\n\
	b _080CF366\n\
	.pool\n\
_080CF2E4:\n\
	ldr r2, =gMain\n\
	ldrh r1, [r2, 0x2E]\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF2F8\n\
	movs r0, 0x13\n\
	b _080CF366\n\
	.pool\n\
_080CF2F8:\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x13]\n\
	cmp r0, 0x1\n\
	bne _080CF326\n\
	ldrh r1, [r2, 0x2C]\n\
	movs r0, 0x80\n\
	lsls r0, 2\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF318\n\
	movs r0, 0xA\n\
	b _080CF366\n\
	.pool\n\
_080CF318:\n\
	movs r0, 0x80\n\
	lsls r0, 1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF326\n\
	movs r0, 0x9\n\
	b _080CF366\n\
_080CF326:\n\
	ldrh r1, [r2, 0x2E]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF338\n\
	bl sub_80CFDC4\n\
	movs r0, 0\n\
	b _080CF366\n\
_080CF338:\n\
	movs r6, 0\n\
	b _080CF364\n\
_080CF33C:\n\
	movs r6, 0x1\n\
	movs r0, 0\n\
	ldrsb r0, [r2, r0]\n\
	cmp r0, 0x5\n\
	ble _080CF352\n\
	lsls r0, r4, 24\n\
	movs r3, 0xFA\n\
	lsls r3, 24\n\
_080CF34C:\n\
	adds r0, r3\n\
	lsrs r4, r0, 24\n\
	b _080CF358\n\
_080CF352:\n\
	movs r0, 0x2\n\
	mov r8, r0\n\
	movs r4, 0\n\
_080CF358:\n\
	cmp r6, 0\n\
	beq _080CF364\n\
	mov r0, r8\n\
	adds r1, r4, 0\n\
	bl sub_80CD894\n\
_080CF364:\n\
	adds r0, r6, 0\n\
_080CF366:\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
                ");
}
#endif

static u8 InBoxInput_GrabbingMultiple(void)
{
    if (gMain.heldKeys & A_BUTTON)
    {
        if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            if (sBoxCursorPosition / IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - IN_BOX_ROWS);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            if (sBoxCursorPosition + IN_BOX_ROWS < IN_BOX_COUNT)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + IN_BOX_ROWS);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        {
            if (sBoxCursorPosition % IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - 1);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        {
            if ((sBoxCursorPosition + 1) % IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + 1);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (sub_80D0BA4() == sBoxCursorPosition)
        {
            gUnknown_02039D08->inBoxMovingMode = 0;
            gUnknown_02039D08->field_CB8->invisible = FALSE;
            return 22;
        }
        else
        {
            sIsMonBeingMoved = (gUnknown_02039D08->cursorMonSpecies != SPECIES_NONE);
            gUnknown_02039D08->inBoxMovingMode = 2;
            sMovingMonOrigBoxId = StorageGetCurrentBox();
            return 23;
        }
    }
}

static u8 InBoxInput_MovingMultiple(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        if (sub_80D0580(0))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - IN_BOX_ROWS);
            return 25;
        }
        else
        {
            return 24;
        }
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        if (sub_80D0580(1))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + IN_BOX_ROWS);
            return 25;
        }
        else
        {
            return 24;
        }
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        if (sub_80D0580(2))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - 1);
            return 25;
        }
        else
        {
            return 10;
        }
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        if (sub_80D0580(3))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + 1);
            return 25;
        }
        else
        {
            return 9;
        }
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        if (sub_80D0BC0())
        {
            sIsMonBeingMoved = FALSE;
            gUnknown_02039D08->inBoxMovingMode = 0;
            return 26;
        }
        else
        {
            return 24;
        }
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return 24;
    }
    else
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (gMain.heldKeys & L_BUTTON)
                return 10;
            if (gMain.heldKeys & R_BUTTON)
                return 9;
        }

        return 0;
    }
}

#ifdef NONMATCHING
static u8 HandleInput_InParty(void)
{
    u8 retVal;
    bool8 gotoBox;
    s8 cursorArea = sBoxCursorArea;
    s8 cursorPosition = sBoxCursorPosition;

    gUnknown_02039D08->field_CD3 = 0;
    gUnknown_02039D08->field_CD2 = 0;
    gUnknown_02039D08->field_CD7 = 0;
    gotoBox = FALSE;
    retVal = 0;

    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            if (++cursorPosition > PARTY_SIZE)
                cursorPosition = 0;
            if (cursorPosition != sBoxCursorPosition)
                retVal = 1;
        }
        else if ((gMain.newAndRepeatedKeys & DPAD_LEFT) && sBoxCursorPosition != 0)
        {
            retVal = 1;
            gUnknown_02039D08->field_CD6 = sBoxCursorPosition;
            cursorPosition = 0;
        }
        else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        {
            if (sBoxCursorPosition == 0)
            {
                retVal = 1;
                cursorPosition = gUnknown_02039D08->field_CD6;
            }
            else
            {
                retVal = 6;
                cursorArea = CURSOR_AREA_IN_BOX;
                cursorPosition = 0;
            }
        }
        else
        {
            if (gMain.newKeys & A_BUTTON)
            {
                if (sBoxCursorPosition == PARTY_SIZE)
                {
                    if (gUnknown_02039D08->boxOption == BOX_OPTION_DEPOSIT)
                        return 4;

                    gotoBox = TRUE;
                }
                else if (sub_80CFA5C())
                {
                    if (!sCanOnlyMove)
                        return 8;

                    switch (sub_80CFF98(0))
                    {
                    case 1:
                        return 11;
                    case 2:
                        return 12;
                    case 3:
                        return 13;
                    case 4:
                        return 14;
                    case 5:
                        return 15;
                    case 12:
                        return 16;
                    case 13:
                        return 17;
                    case 15:
                        return 18;
                    }
                }
            }

            if (gMain.newKeys & B_BUTTON)
            {
                if (gUnknown_02039D08->boxOption == BOX_OPTION_DEPOSIT)
                    return 19;

                gotoBox = TRUE;
            }

            if (gotoBox)
            {
                retVal = 6;
                cursorArea = CURSOR_AREA_IN_BOX;
                cursorPosition = 0;
            }
            else if (gMain.newKeys & SELECT_BUTTON)
            {
                sub_80CFDC4();
                return 0;
            }
        }
    }
    else
    {
        if (--cursorPosition < 0)
            cursorPosition = PARTY_SIZE;
        if (cursorPosition != sBoxCursorPosition)
            retVal = 1;
    }
	if (retVal != 0)
    {
        if (retVal != 6)
            sub_80CD894(cursorArea, cursorPosition);
    }

	return retVal;
}
#else
NAKED
static u8 HandleInput_InParty(void)
{
    asm_unified("\n\
                	push {r4-r7,lr}\n\
	mov r7, r9\n\
	mov r6, r8\n\
	push {r6,r7}\n\
	ldr r0, =sBoxCursorArea\n\
	ldrb r0, [r0]\n\
	mov r9, r0\n\
	ldr r6, =sBoxCursorPosition\n\
	ldrb r4, [r6]\n\
	ldr r2, =gUnknown_02039D08\n\
	ldr r0, [r2]\n\
	ldr r1, =0x00000cd3\n\
	adds r0, r1\n\
	movs r1, 0\n\
	strb r1, [r0]\n\
	ldr r0, [r2]\n\
	ldr r3, =0x00000cd2\n\
	adds r0, r3\n\
	strb r1, [r0]\n\
	ldr r0, [r2]\n\
	adds r3, 0x5\n\
	adds r0, r3\n\
	strb r1, [r0]\n\
	mov r8, r1\n\
	movs r7, 0\n\
	ldr r1, =gMain\n\
	ldrh r3, [r1, 0x30]\n\
	movs r0, 0x40\n\
	ands r0, r3\n\
	adds r5, r6, 0\n\
	mov r12, r1\n\
	cmp r0, 0\n\
	beq _080CF608\n\
	b _080CF7A8\n\
_080CF608:\n\
	movs r0, 0x80\n\
	ands r0, r3\n\
	cmp r0, 0\n\
	beq _080CF64C\n\
	lsls r0, r4, 24\n\
	movs r1, 0x80\n\
	lsls r1, 17\n\
	adds r0, r1\n\
	lsrs r4, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x6\n\
	ble _080CF622\n\
	movs r4, 0\n\
_080CF622:\n\
	lsls r0, r4, 24\n\
	asrs r0, 24\n\
	movs r1, 0\n\
	ldrsb r1, [r5, r1]\n\
	cmp r0, r1\n\
	bne _080CF630\n\
	b _080CF7C6\n\
_080CF630:\n\
	movs r7, 0x1\n\
	b _080CF7CA\n\
	.pool\n\
_080CF64C:\n\
	movs r0, 0x20\n\
	ands r0, r3\n\
	cmp r0, 0\n\
	beq _080CF670\n\
	ldrb r1, [r5]\n\
	movs r0, 0\n\
	ldrsb r0, [r5, r0]\n\
	cmp r0, 0\n\
	beq _080CF670\n\
	movs r7, 0x1\n\
	ldr r0, [r2]\n\
	ldr r2, =0x00000cd6\n\
	adds r0, r2\n\
	strb r1, [r0]\n\
	movs r4, 0\n\
	b _080CF7C6\n\
	.pool\n\
_080CF670:\n\
	mov r3, r12\n\
	ldrh r1, [r3, 0x30]\n\
	movs r0, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF69E\n\
	movs r0, 0\n\
	ldrsb r0, [r5, r0]\n\
	cmp r0, 0\n\
	bne _080CF694\n\
	movs r7, 0x1\n\
	ldr r0, [r2]\n\
	ldr r1, =0x00000cd6\n\
	adds r0, r1\n\
	ldrb r4, [r0]\n\
	b _080CF7C6\n\
	.pool\n\
_080CF694:\n\
	movs r7, 0x6\n\
	movs r2, 0\n\
	mov r9, r2\n\
	movs r4, 0\n\
	b _080CF7C6\n\
_080CF69E:\n\
	mov r3, r12\n\
	ldrh r1, [r3, 0x2E]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF75C\n\
	movs r0, 0\n\
	ldrsb r0, [r5, r0]\n\
	cmp r0, 0x6\n\
	bne _080CF6C4\n\
	ldr r0, [r2]\n\
	ldrb r0, [r0, 0x1]\n\
	cmp r0, 0x1\n\
	bne _080CF6BE\n\
	movs r0, 0x4\n\
	b _080CF7D8\n\
_080CF6BE:\n\
	movs r0, 0x1\n\
	mov r8, r0\n\
	b _080CF75C\n\
_080CF6C4:\n\
	bl sub_80CFA5C\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _080CF75C\n\
	ldr r0, =sCanOnlyMove\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	bne _080CF6E0\n\
	movs r0, 0x8\n\
	b _080CF7D8\n\
	.pool\n\
_080CF6E0:\n\
	movs r0, 0\n\
	bl sub_80CFF98\n\
	subs r0, 0x1\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0xE\n\
	bhi _080CF75C\n\
	lsls r0, 2\n\
	ldr r1, =_080CF700\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_080CF700:\n\
	.4byte _080CF73C\n\
	.4byte _080CF740\n\
	.4byte _080CF744\n\
	.4byte _080CF748\n\
	.4byte _080CF74C\n\
	.4byte _080CF75C\n\
	.4byte _080CF75C\n\
	.4byte _080CF75C\n\
	.4byte _080CF75C\n\
	.4byte _080CF75C\n\
	.4byte _080CF75C\n\
	.4byte _080CF750\n\
	.4byte _080CF754\n\
	.4byte _080CF75C\n\
	.4byte _080CF758\n\
_080CF73C:\n\
	movs r0, 0xB\n\
	b _080CF7D8\n\
_080CF740:\n\
	movs r0, 0xC\n\
	b _080CF7D8\n\
_080CF744:\n\
	movs r0, 0xD\n\
	b _080CF7D8\n\
_080CF748:\n\
	movs r0, 0xE\n\
	b _080CF7D8\n\
_080CF74C:\n\
	movs r0, 0xF\n\
	b _080CF7D8\n\
_080CF750:\n\
	movs r0, 0x10\n\
	b _080CF7D8\n\
_080CF754:\n\
	movs r0, 0x11\n\
	b _080CF7D8\n\
_080CF758:\n\
	movs r0, 0x12\n\
	b _080CF7D8\n\
_080CF75C:\n\
	ldr r2, =gMain\n\
	ldrh r1, [r2, 0x2E]\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	mov r12, r2\n\
	cmp r0, 0\n\
	beq _080CF784\n\
	ldr r0, =gUnknown_02039D08\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x1]\n\
	cmp r0, 0x1\n\
	bne _080CF780\n\
	movs r0, 0x13\n\
	b _080CF7D8\n\
	.pool\n\
_080CF780:\n\
	movs r1, 0x1\n\
	mov r8, r1\n\
_080CF784:\n\
	mov r2, r8\n\
	cmp r2, 0\n\
	beq _080CF794\n\
	movs r7, 0x6\n\
	movs r3, 0\n\
	mov r9, r3\n\
	movs r4, 0\n\
	b _080CF7C6\n\
_080CF794:\n\
	mov r0, r12\n\
	ldrh r1, [r0, 0x2E]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF7C6\n\
	bl sub_80CFDC4\n\
	movs r0, 0\n\
	b _080CF7D8\n\
_080CF7A8:\n\
	lsls r0, r4, 24\n\
	movs r1, 0xFF\n\
	lsls r1, 24\n\
	adds r0, r1\n\
	lsrs r4, r0, 24\n\
	cmp r0, 0\n\
	bge _080CF7B8\n\
	movs r4, 0x6\n\
_080CF7B8:\n\
	lsls r0, r4, 24\n\
	asrs r0, 24\n\
	movs r1, 0\n\
	ldrsb r1, [r6, r1]\n\
	cmp r0, r1\n\
	beq _080CF7C6\n\
	movs r7, 0x1\n\
_080CF7C6:\n\
	cmp r7, 0\n\
	beq _080CF7D6\n\
_080CF7CA:\n\
	cmp r7, 0x6\n\
	beq _080CF7D6\n\
	mov r0, r9\n\
	adds r1, r4, 0\n\
	bl sub_80CD894\n\
_080CF7D6:\n\
	adds r0, r7, 0\n\
_080CF7D8:\n\
	pop {r3,r4}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1");
}
#endif

#ifdef NONMATCHING
static u8 HandleInput_OnBox(void)
{
    u8 retVal;
    s8 cursorArea = sBoxCursorArea;
    s8 cursorPosition = sBoxCursorPosition;

    gUnknown_02039D08->field_CD3 = 0;
    gUnknown_02039D08->field_CD2 = 0;
    gUnknown_02039D08->field_CD7 = 0;
    retVal = 0;

    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 2;
        }
        else
        {
            if (gMain.heldKeys & DPAD_LEFT)
                return 10;
            if (gMain.heldKeys & DPAD_RIGHT)
                return 9;

            if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
            {
                if (gMain.heldKeys & L_BUTTON)
                    return 10;
                if (gMain.heldKeys & R_BUTTON)
                    return 9;
            }

            if (gMain.newKeys & A_BUTTON)
            {
                sub_80CD1A8(FALSE);
                AddBoxMenu();
                return 7;
            }

            if (gMain.newKeys & B_BUTTON)
                return 19;

            if (gMain.newKeys & SELECT_BUTTON)
            {
                sub_80CFDC4();
                return 0;
            }

            retVal = 0;
        }
    }
    else
    {
        retVal = 1;
        cursorArea = CURSOR_AREA_BUTTONS;
        cursorPosition = 0;
        gUnknown_02039D08->field_CD7 = 1;
    }

    if (retVal)
    {
        if (cursorArea != CURSOR_AREA_BOX)
            sub_80CD1A8(FALSE);
        sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}
#else
NAKED
static u8 HandleInput_OnBox(void)
{
    asm_unified("\n\
                	push {r4-r6,lr}\n\
	ldr r3, =gUnknown_02039D08\n\
	ldr r0, [r3]\n\
	ldr r1, =0x00000cd3\n\
	adds r0, r1\n\
	movs r1, 0\n\
	strb r1, [r0]\n\
	ldr r0, [r3]\n\
	ldr r2, =0x00000cd2\n\
	adds r0, r2\n\
	strb r1, [r0]\n\
	ldr r0, [r3]\n\
	ldr r5, =0x00000cd7\n\
	adds r0, r5\n\
	strb r1, [r0]\n\
	ldr r1, =gMain\n\
	ldrh r2, [r1, 0x30]\n\
	movs r0, 0x40\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	bne _080CF8AA\n\
	movs r0, 0x80\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _080CF834\n\
	movs r4, 0x1\n\
	movs r1, 0\n\
	movs r6, 0x2\n\
	b _080CF8B6\n\
	.pool\n\
_080CF834:\n\
	ldrh r2, [r1, 0x2C]\n\
	movs r0, 0x20\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	bne _080CF85A\n\
	movs r0, 0x10\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	bne _080CF86E\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x13]\n\
	cmp r0, 0x1\n\
	bne _080CF872\n\
	movs r0, 0x80\n\
	lsls r0, 2\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _080CF864\n\
_080CF85A:\n\
	movs r0, 0xA\n\
	b _080CF8D2\n\
	.pool\n\
_080CF864:\n\
	movs r0, 0x80\n\
	lsls r0, 1\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _080CF872\n\
_080CF86E:\n\
	movs r0, 0x9\n\
	b _080CF8D2\n\
_080CF872:\n\
	ldrh r1, [r1, 0x2E]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF88A\n\
	movs r0, 0\n\
	bl sub_80CD1A8\n\
	bl AddBoxMenu\n\
	movs r0, 0x7\n\
	b _080CF8D2\n\
_080CF88A:\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF896\n\
	movs r0, 0x13\n\
	b _080CF8D2\n\
_080CF896:\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF8A6\n\
	bl sub_80CFDC4\n\
	movs r0, 0\n\
	b _080CF8D2\n\
_080CF8A6:\n\
	movs r4, 0\n\
	b _080CF8D0\n\
_080CF8AA:\n\
	movs r4, 0x1\n\
	movs r1, 0x3\n\
	movs r6, 0\n\
	ldr r0, [r3]\n\
	adds r0, r5\n\
	strb r4, [r0]\n\
_080CF8B6:\n\
	cmp r4, 0\n\
	beq _080CF8D0\n\
	lsls r5, r1, 24\n\
	cmp r1, 0x2\n\
	beq _080CF8C6\n\
	movs r0, 0\n\
	bl sub_80CD1A8\n\
_080CF8C6:\n\
	lsrs r0, r5, 24\n\
	lsls r1, r6, 24\n\
	lsrs r1, 24\n\
	bl sub_80CD894\n\
_080CF8D0:\n\
	adds r0, r4, 0\n\
_080CF8D2:\n\
	pop {r4-r6}\n\
	pop {r1}\n\
	bx r1\n\
                ");
}
#endif

#ifdef NONMATCHING
static u8 HandleInput_OnButtons(void)
{
    u8 retVal;
    s8 cursorArea = sBoxCursorArea;
    s8 cursorPosition = sBoxCursorPosition;

    gUnknown_02039D08->field_CD3 = 0;
    gUnknown_02039D08->field_CD2 = 0;
    gUnknown_02039D08->field_CD7 = 0;

    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & (DPAD_DOWN | START_BUTTON))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
            gUnknown_02039D08->field_CD7 = 1;
        }
        else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        {
            retVal = 1;
            if (--cursorPosition < 0)
            {
                cursorPosition = 1;
            }
        }
        else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        {
            retVal = 1;
            if (++cursorPosition > 1)
            {
                cursorPosition = 0;
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            return (cursorPosition == 0) ? 5 : 4;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            return 19;
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            sub_80CFDC4();
            return 0;
        }
        else
        {
            retVal = 0;
        }
    }
    else
    {
        retVal = 1;
        cursorArea = CURSOR_AREA_IN_BOX;
        gUnknown_02039D08->field_CD2 = -1;
        cursorPosition = (sBoxCursorPosition == 0) ? IN_BOX_COUNT - 1 - 5 : IN_BOX_COUNT - 1;
        gUnknown_02039D08->field_CD7 = 1;
    }

    if (retVal != 0)
    {
        sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}
#else
NAKED
static u8 HandleInput_OnButtons(void)
{
    asm_unified("\n\
                	push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r0, =sBoxCursorArea\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldr r0, =sBoxCursorPosition\n\
	mov r12, r0\n\
	ldrb r2, [r0]\n\
	ldr r3, =gUnknown_02039D08\n\
	ldr r0, [r3]\n\
	ldr r1, =0x00000cd3\n\
	adds r0, r1\n\
	movs r1, 0\n\
	strb r1, [r0]\n\
	ldr r0, [r3]\n\
	ldr r6, =0x00000cd2\n\
	adds r0, r6\n\
	strb r1, [r0]\n\
	ldr r0, [r3]\n\
	ldr r5, =0x00000cd7\n\
	adds r0, r5\n\
	strb r1, [r0]\n\
	ldr r7, =gMain\n\
	ldrh r1, [r7, 0x30]\n\
	movs r0, 0x40\n\
	ands r0, r1\n\
	adds r4, r3, 0\n\
	cmp r0, 0\n\
	bne _080CF9B2\n\
	movs r0, 0x88\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF944\n\
	movs r7, 0x1\n\
	movs r0, 0x2\n\
	mov r8, r0\n\
	movs r2, 0\n\
	ldr r0, [r4]\n\
	b _080CF9D0\n\
	.pool\n\
_080CF944:\n\
	movs r0, 0x20\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF960\n\
	movs r7, 0x1\n\
	lsls r0, r2, 24\n\
	movs r1, 0xFF\n\
	lsls r1, 24\n\
	adds r0, r1\n\
	lsrs r2, r0, 24\n\
	cmp r0, 0\n\
	bge _080CF9D4\n\
	movs r2, 0x1\n\
	b _080CF9D4\n\
_080CF960:\n\
	movs r0, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF97E\n\
	movs r7, 0x1\n\
	lsls r0, r2, 24\n\
	movs r1, 0x80\n\
	lsls r1, 17\n\
	adds r0, r1\n\
	lsrs r2, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x1\n\
	ble _080CF9D4\n\
	movs r2, 0\n\
	b _080CF9D4\n\
_080CF97E:\n\
	ldrh r1, [r7, 0x2E]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF992\n\
	movs r0, 0x4\n\
	cmp r2, 0\n\
	bne _080CF9E2\n\
	movs r0, 0x5\n\
	b _080CF9E2\n\
_080CF992:\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF99E\n\
	movs r0, 0x13\n\
	b _080CF9E2\n\
_080CF99E:\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080CF9AE\n\
	bl sub_80CFDC4\n\
	movs r0, 0\n\
	b _080CF9E2\n\
_080CF9AE:\n\
	movs r7, 0\n\
	b _080CF9E0\n\
_080CF9B2:\n\
	movs r7, 0x1\n\
	movs r0, 0\n\
	mov r8, r0\n\
	ldr r0, [r3]\n\
	adds r0, r6\n\
	movs r1, 0xFF\n\
	strb r1, [r0]\n\
	mov r1, r12\n\
	movs r0, 0\n\
	ldrsb r0, [r1, r0]\n\
	movs r2, 0x1D\n\
	cmp r0, 0\n\
	bne _080CF9CE\n\
	movs r2, 0x18\n\
_080CF9CE:\n\
	ldr r0, [r3]\n\
_080CF9D0:\n\
	adds r0, r5\n\
	strb r7, [r0]\n\
_080CF9D4:\n\
	cmp r7, 0\n\
	beq _080CF9E0\n\
	mov r0, r8\n\
	adds r1, r2, 0\n\
	bl sub_80CD894\n\
_080CF9E0:\n\
	adds r0, r7, 0\n\
_080CF9E2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1");
}
#endif

static u8 HandleInput(void)
{
    struct
    {
        u8 (*func)(void);
        s8 area;
    }
    static const inputFuncs[] =
    {
        {HandleInput_InBox, CURSOR_AREA_IN_BOX},
        {HandleInput_InParty, CURSOR_AREA_IN_PARTY},
        {HandleInput_OnBox, CURSOR_AREA_BOX},
        {HandleInput_OnButtons, CURSOR_AREA_BUTTONS},
        {NULL, 0},
    };

    u16 i = 0;
    while (inputFuncs[i].func != NULL)
    {
        if (inputFuncs[i].area == sBoxCursorArea)
            return inputFuncs[i].func();
        i++;
    }

    return 0;
}

void AddBoxMenu(void)
{
    InitMenu();
    SetMenuText(9);
    SetMenuText(10);
    SetMenuText(11);
    SetMenuText(0);
}

u8 sub_80CFA5C(void)
{
    InitMenu();
    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return sub_80CFA84();
    else
        return sub_80CFB44();
}

static bool8 sub_80CFA84(void)
{
    u16 var0 = sub_80CD504();

    switch (gUnknown_02039D08->boxOption)
    {
    case BOX_OPTION_DEPOSIT:
        if (var0)
            SetMenuText(1);
        else
            return FALSE;
        break;
    case BOX_OPTION_WITHDRAW:
        if (var0)
            SetMenuText(2);
        else
            return FALSE;
        break;
    case BOX_OPTION_MOVE_MONS:
        if (sIsMonBeingMoved)
        {
            if (var0)
                SetMenuText(4);
            else
                SetMenuText(5);
        }
        else
        {
            if (var0)
                SetMenuText(3);
            else
                return FALSE;
        }
        break;
    case BOX_OPTION_MOVE_ITEMS:
    default:
        return FALSE;
    }

    SetMenuText(6);
    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_MONS)
    {
        if (!sBoxCursorArea)
            SetMenuText(2);
        else
            SetMenuText(1);
    }

    SetMenuText(8);
    SetMenuText(7);
    SetMenuText(0);
    return TRUE;
}

static bool8 sub_80CFB44(void)
{
    if (gUnknown_02039D08->cursorMonSpecies == SPECIES_EGG)
        return FALSE;

    if (!sub_80D127C())
    {
        if (gUnknown_02039D08->cursorMonItem == 0)
        {
            if (gUnknown_02039D08->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(14);
        }
        else
        {
            if (!ItemIsMail(gUnknown_02039D08->cursorMonItem))
            {
                SetMenuText(12);
                SetMenuText(16);
            }
            SetMenuText(17);
        }
    }
    else
    {
        if (gUnknown_02039D08->cursorMonItem == 0)
        {
            if (gUnknown_02039D08->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(13);
        }
        else
        {
            if (ItemIsMail(gUnknown_02039D08->cursorMonItem) == TRUE)
                return FALSE;

            SetMenuText(15);
        }
    }

    SetMenuText(0);
    return TRUE;
}

void sub_80CFBF4(struct Sprite *sprite)
{
    sprite->pos1.x = gUnknown_02039D08->field_CB4->pos1.x;
    sprite->pos1.y = gUnknown_02039D08->field_CB4->pos1.y + 20;
}

void sub_80CFC14(void)
{
    u16 x, y;
    u8 spriteId;
    u8 priority, subpriority;
    struct SpriteSheet spriteSheets[] =
    {
        {gHandCursorTiles, 0x800, 0},
        {gHandCursorShadowTiles, 0x80, 1},
        {}
    };

    struct SpritePalette spritePalettes[] =
    {
        {gHandCursorPalette, 0xDAC7},
        {}
    };

static const struct OamData sOamData_857BA0C =
{
    .size = 2,
    .priority = 1,
};
static const struct OamData sOamData_857BA14 =
{
    .size = 1,
    .priority = 1,
};

static const union AnimCmd sSpriteAnim_857BA1C[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sSpriteAnim_857BA28[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_857BA30[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_857BA38[] =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_857BA40[] =
{
    sSpriteAnim_857BA1C,
    sSpriteAnim_857BA28,
    sSpriteAnim_857BA30,
    sSpriteAnim_857BA38
};

static const struct SpriteTemplate gSpriteTemplate_857BA50 =
{
    .tileTag = 0,
    .paletteTag = 0xDACA,
    .oam = &sOamData_857BA0C,
    .anims = sSpriteAnimTable_857BA40,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteTemplate_857BA68 =
{
    .tileTag = 1,
    .paletteTag = 0xDACA,
    .oam = &sOamData_857BA14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80CFBF4,
};

    LoadSpriteSheets(spriteSheets);
    LoadSpritePalettes(spritePalettes);
    gUnknown_02039D08->field_CD8[0] = IndexOfSpritePaletteTag(0xDACA);
    gUnknown_02039D08->field_CD8[1] = IndexOfSpritePaletteTag(0xDAC7);

    sub_80CD444(sBoxCursorArea, sBoxCursorPosition, &x, &y);
    spriteId = CreateSprite(&gSpriteTemplate_857BA50, x, y, 6);
    if (spriteId != MAX_SPRITES)
    {
        gUnknown_02039D08->field_CB4 = &gSprites[spriteId];
        gUnknown_02039D08->field_CB4->oam.paletteNum = gUnknown_02039D08->field_CD8[sCanOnlyMove];
        gUnknown_02039D08->field_CB4->oam.priority = 1;
        if (sIsMonBeingMoved)
            StartSpriteAnim(gUnknown_02039D08->field_CB4, 3);
    }
    else
    {
        gUnknown_02039D08->field_CB4 = NULL;
    }

    if (sBoxCursorArea == 1)
    {
        subpriority = 13;
        priority = 1;
    }
    else
    {
        subpriority = 21;
        priority = 2;
    }

    spriteId = CreateSprite(&gSpriteTemplate_857BA68, 0, 0, subpriority);
    if (spriteId != MAX_SPRITES)
    {
        gUnknown_02039D08->field_CB8 = &gSprites[spriteId];
        gUnknown_02039D08->field_CB8->oam.priority = priority;
        if (sBoxCursorArea)
            gUnknown_02039D08->field_CB8->invisible = 1;
    }
    else
    {
        gUnknown_02039D08->field_CB8 = NULL;
    }
}

void sub_80CFDC4(void)
{
    sCanOnlyMove = !sCanOnlyMove;
    gUnknown_02039D08->field_CB4->oam.paletteNum = gUnknown_02039D08->field_CD8[sCanOnlyMove];
}

u8 GetBoxCursorPosition(void)
{
    return sBoxCursorPosition;
}

void sub_80CFE14(u8 *arg0, u8 *arg1)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
    {
        *arg0 = sBoxCursorPosition % IN_BOX_ROWS;
        *arg1 = sBoxCursorPosition / IN_BOX_ROWS;
    }
    else
    {
        *arg0 = 0;
        *arg1 = 0;
    }
}

void sub_80CFE54(u8 animNum)
{
    StartSpriteAnim(gUnknown_02039D08->field_CB4, animNum);
}

u8 sub_80CFE78(void)
{
    return sMovingMonOrigBoxId;
}

void sub_80CFE84(void)
{
    gUnknown_02039D08->field_CB4->oam.priority = 1;
}

void sub_80CFEA8(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

void sub_80CFECC(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0D8C(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

static void InitMenu(void)
{
    gUnknown_02039D08->menuItemsCount = 0;
    gUnknown_02039D08->menuWidth = 0;
    gUnknown_02039D08->menuWindow.bg = 0;
    gUnknown_02039D08->menuWindow.paletteNum = 15;
    gUnknown_02039D08->menuWindow.baseBlock = 92;
}

static const u8 *const gUnknown_0857BA80[] =
{
    gPCText_Cancel,
    gPCText_Store,
    gPCText_Withdraw,
    gPCText_Move,
    gPCText_Shift,
    gPCText_Place,
    gPCText_Summary,
    gPCText_Release,
    gPCText_Mark,
    gPCText_Jump,
    gPCText_Wallpaper,
    gPCText_Name,
    gPCText_Take,
    gPCText_Give,
    gPCText_Give,
    gPCText_Switch,
    gPCText_Bag,
    gPCText_Info,
    gPCText_Scenery1,
    gPCText_Scenery2,
    gPCText_Scenery3,
    gPCText_Etcetera,
    gPCText_Friends,
    gPCText_Forest,
    gPCText_City,
    gPCText_Desert,
    gPCText_Savanna,
    gPCText_Crag,
    gPCText_Volcano,
    gPCText_Snow,
    gPCText_Cave,
    gPCText_Beach,
    gPCText_Seafloor,
    gPCText_River,
    gPCText_Sky,
    gPCText_PolkaDot,
    gPCText_Pokecenter,
    gPCText_Machine,
    gPCText_Simple,
};

static void SetMenuText(u8 textId)
{
    if (gUnknown_02039D08->menuItemsCount < 7)
    {
        u8 len;
        struct StorageMenu *menu = &gUnknown_02039D08->menuItems[gUnknown_02039D08->menuItemsCount];

        menu->text = gUnknown_0857BA80[textId];
        menu->textId = textId;
        len = StringLength(menu->text);
        if (len > gUnknown_02039D08->menuWidth)
            gUnknown_02039D08->menuWidth = len;

        gUnknown_02039D08->menuItemsCount++;
    }
}

s8 sub_80CFF98(u8 arg0)
{
    if (arg0 >= gUnknown_02039D08->menuItemsCount)
        return -1;
    else
        return gUnknown_02039D08->menuItems[arg0].textId;
}

static void AddMenu(void)
{
    gUnknown_02039D08->menuWindow.width = gUnknown_02039D08->menuWidth + 2;
    gUnknown_02039D08->menuWindow.height = 2 * gUnknown_02039D08->menuItemsCount;
    gUnknown_02039D08->menuWindow.tilemapLeft = 29 - gUnknown_02039D08->menuWindow.width;
    gUnknown_02039D08->menuWindow.tilemapTop = 15 - gUnknown_02039D08->menuWindow.height;
    gUnknown_02039D08->field_CB0 = AddWindow(&gUnknown_02039D08->menuWindow);
    ClearWindowTilemap(gUnknown_02039D08->field_CB0);
    SetWindowBorderStyle(gUnknown_02039D08->field_CB0, FALSE, 11, 14);
    PrintMenuTable(gUnknown_02039D08->field_CB0, gUnknown_02039D08->menuItemsCount, (void*)gUnknown_02039D08->menuItems);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gUnknown_02039D08->field_CB0, gUnknown_02039D08->menuItemsCount, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gUnknown_02039D08->field_CAE = 0;
}

bool8 sub_80D00A8(void)
{
    return 0;
}

s16 sub_80D00AC(void)
{
    s32 textId = -2;

    if (!(gMain.newKeys & A_BUTTON))
    {
        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            textId = -1;
        }

        if (gMain.newKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(-1);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(1);
        }
    }
    else
    {
        textId = Menu_GetCursorPos();
    }

    if (textId != -2)
        sub_80D013C();

    if (textId >= 0)
        textId = gUnknown_02039D08->menuItems[textId].textId;

    #ifndef NONMATCHING
    asm("":::"r4");
    #endif // NONMATCHING
    return textId;
}

void sub_80D013C(void)
{
    sub_8198070(gUnknown_02039D08->field_CB0, TRUE);
    RemoveWindow(gUnknown_02039D08->field_CB0);
}

// The functions below handle moving and grabbing multiple mons at once.
// The icons are converted to background 0 which coordinates are changed while moving mons.
// There is also a bit of math involved in determining how many column/rows of mons to grab/move.

const struct WindowTemplate gUnknown_0857BB1C =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 3,
    .width = 20,
    .height = 18,
    .paletteNum = 9,
    .baseBlock = 0xA,
};

bool8 sub_80D0164(void)
{
    gUnknown_02039D80 = Alloc(sizeof(*gUnknown_02039D80));
    if (gUnknown_02039D80 != NULL)
    {
        gUnknown_02039D08->field_2200 = AddWindow8Bit(&gUnknown_0857BB1C);
        if (gUnknown_02039D08->field_2200 != 0xFF)
        {
            FillWindowPixelBuffer(gUnknown_02039D08->field_2200, 0);
            return TRUE;
        }
    }

    return FALSE;
}

void sub_80D01B8(void)
{
    if (gUnknown_02039D80 != NULL)
        Free(gUnknown_02039D80);
}

void sub_80D01D0(u8 arg0)
{
    gUnknown_02039D80->field_0 = arg0;
    gUnknown_02039D80->state = 0;
}

bool8 sub_80D01E4(void)
{
    switch (gUnknown_02039D80->field_0)
    {
    case 0:
        return sub_80D024C();
    case 1:
        return sub_80D0344();
    case 2:
        return sub_80D03B0();
    case 3:
        return sub_80D0420();
    case 4:
        return sub_80D04A0();
    case 5:
        return sub_80D04C8();
    }

    return FALSE;
}

bool8 sub_80D024C(void)
{
    switch (gUnknown_02039D80->state)
    {
    case 0:
        HideBg(0);
        sub_80D304C(0x80);
        gUnknown_02039D80->state++;
        break;
    case 1:
        sub_80CFE14(&gUnknown_02039D80->fromRow, &gUnknown_02039D80->fromColumn);
        gUnknown_02039D80->toRow = gUnknown_02039D80->fromRow;
        gUnknown_02039D80->toColumn = gUnknown_02039D80->fromColumn;
        ChangeBgX(0, -1024, 0);
        ChangeBgY(0, -1024, 0);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillWindowPixelBuffer8Bit(gUnknown_02039D08->field_2200, 0);
        sub_80D07B0(gUnknown_02039D80->fromRow, gUnknown_02039D80->fromColumn);
        SetBgAttribute(0, 4, 1);
        PutWindowTilemap(gUnknown_02039D08->field_2200);
        CopyWindowToVram8Bit(gUnknown_02039D08->field_2200, 3);
        BlendPalettes(0x3F00, 8, 0x7FFF);
        sub_80CFE54(2);
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
        gUnknown_02039D80->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool8 sub_80D0344(void)
{
    switch (gUnknown_02039D80->state)
    {
    case 0:
        HideBg(0);
        gUnknown_02039D80->state++;
        break;
    case 1:
        sub_80D0B5C();
        sub_80CFE54(0);
        gUnknown_02039D80->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80CFE84();
            LoadPalette(stdpal_get(3), 0xD0, 0x20);
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool8 sub_80D03B0(void)
{
    switch (gUnknown_02039D80->state)
    {
    case 0:
        if (!sub_80CD554())
        {
            sub_80CFE14(&gUnknown_02039D80->field_6, &gUnknown_02039D80->field_7);
            sub_80D062C();
            gUnknown_02039D80->toRow = gUnknown_02039D80->field_6;
            gUnknown_02039D80->toColumn = gUnknown_02039D80->field_7;
            CopyWindowToVram8Bit(gUnknown_02039D08->field_2200, 2);
            gUnknown_02039D80->state++;
        }
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool8 sub_80D0420(void)
{
    u8 var1, var2;

    switch (gUnknown_02039D80->state)
    {
    case 0:
        sub_80D08CC();
        sub_80D09A4();
        sub_80CDC64(FALSE);
        gUnknown_02039D80->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(3);
            sub_80D0884(0, 256, 8);
            sub_80CDC64(TRUE);
            gUnknown_02039D80->state++;
        }
        break;
    case 2:
        var1 = sub_80D0894();
        var2 = DoMonPlaceChange();
        if (!var1 && !var2)
            return FALSE;
        break;
    }

    return TRUE;
}

bool8 sub_80D04A0(void)
{
    u8 var1 = sub_80CD554();
    u8 var2 = sub_80D0894();

    if (!var1 && !var2)
        return FALSE;
    else
        return TRUE;
}

bool8 sub_80D04C8(void)
{
    switch (gUnknown_02039D80->state)
    {
    case 0:
        sub_80D0AAC();
        sub_80D0884(0, -256, 8);
        sub_80CDC64(FALSE);
        gUnknown_02039D80->state++;
        break;
    case 1:
        if (!DoMonPlaceChange() && !sub_80D0894())
        {
            sub_80D0A1C();
            sub_80CFE54(2);
            sub_80CDC64(TRUE);
            HideBg(0);
            gUnknown_02039D80->state++;
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(0);
            sub_80D0B5C();
            gUnknown_02039D80->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LoadPalette(stdpal_get(3), 0xD0, 0x20);
            sub_80CFE84();
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool8 sub_80D0580(u8 arg0)
{
    switch (arg0)
    {
    case 0:
        if (gUnknown_02039D80->minColumn == 0)
            return FALSE;
        gUnknown_02039D80->minColumn--;
        sub_80D0884(0, 1024, 6);
        break;
    case 1:
        if (gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal >= 5)
            return FALSE;
        gUnknown_02039D80->minColumn++;
        sub_80D0884(0, -1024, 6);
        break;
    case 2:
        if (gUnknown_02039D80->minRow == 0)
            return FALSE;
        gUnknown_02039D80->minRow--;
        sub_80D0884(1024, 0, 6);
        break;
    case 3:
        if (gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal > 5)
            return FALSE;
        gUnknown_02039D80->minRow++;
        sub_80D0884(-1024, 0, 6);
        break;
    }

    return TRUE;
}

void sub_80D062C(void)
{
    s16 var = (abs(gUnknown_02039D80->fromRow - gUnknown_02039D80->field_6)) - (abs(gUnknown_02039D80->fromRow - gUnknown_02039D80->toRow));
    s16 var2 = (abs(gUnknown_02039D80->fromColumn - gUnknown_02039D80->field_7)) - (abs(gUnknown_02039D80->fromColumn - gUnknown_02039D80->toColumn));

    if (var > 0)
        sub_80D06D0(gUnknown_02039D80->field_6, gUnknown_02039D80->fromColumn, gUnknown_02039D80->toColumn);

    if (var < 0)
    {
        sub_80D0740(gUnknown_02039D80->toRow, gUnknown_02039D80->fromColumn, gUnknown_02039D80->toColumn);
        sub_80D06D0(gUnknown_02039D80->field_6, gUnknown_02039D80->fromColumn, gUnknown_02039D80->toColumn);
    }

    if (var2 > 0)
        sub_80D0708(gUnknown_02039D80->field_7, gUnknown_02039D80->fromRow, gUnknown_02039D80->toRow);

    if (var2 < 0)
    {
        sub_80D0778(gUnknown_02039D80->toColumn, gUnknown_02039D80->fromRow, gUnknown_02039D80->toRow);
        sub_80D0708(gUnknown_02039D80->field_7, gUnknown_02039D80->fromRow, gUnknown_02039D80->toRow);
    }
}

void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D07B0(arg0, arg1++);
}

void sub_80D0708(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D07B0(arg1++, arg0);
}

void sub_80D0740(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D0834(arg0, arg1++);
}

void sub_80D0778(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D0834(arg1++, arg0);
}

void sub_80D07B0(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);
    u32 personality = GetCurrentBoxMonData(position, MON_DATA_PERSONALITY);

    if (species != SPECIES_NONE)
    {
        const u8 *iconGfx = GetMonIconPtr(species, personality, 1);
        u8 index = GetValidMonIconPalIndex(species) + 8;

        BlitBitmapRectToWindow4BitTo8Bit(gUnknown_02039D08->field_2200,
                                         iconGfx,
                                         0,
                                         0,
                                         32,
                                         32,
                                         24 * arg0,
                                         24 * arg1,
                                         32,
                                         32,
                                         index);
    }
}

void sub_80D0834(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);

    if (species != SPECIES_NONE)
    {
        FillWindowPixelRect8Bit(gUnknown_02039D08->field_2200,
                                0,
                                24 * arg0,
                                24 * arg1,
                                32,
                                32);
    }
}

void sub_80D0884(u16 arg0, u16 arg1, u16 arg2)
{
    gUnknown_02039D80->bgX = arg0;
    gUnknown_02039D80->bgY = arg1;
    gUnknown_02039D80->field_10 = arg2;
}

u8 sub_80D0894(void)
{
    if (gUnknown_02039D80->field_10 != 0)
    {
        ChangeBgX(0, gUnknown_02039D80->bgX, 1);
        ChangeBgY(0, gUnknown_02039D80->bgY, 1);
        gUnknown_02039D80->field_10--;
    }

    return gUnknown_02039D80->field_10;
}

void sub_80D08CC(void)
{
    s32 i, j, r8, r9;
    s32 rowCount, columnCount;
    u8 boxId;
    u8 monArrayId;

    gUnknown_02039D80->minRow = min(gUnknown_02039D80->fromRow, gUnknown_02039D80->toRow);
    gUnknown_02039D80->minColumn = min(gUnknown_02039D80->fromColumn, gUnknown_02039D80->toColumn);
    gUnknown_02039D80->rowsTotal = abs(gUnknown_02039D80->fromRow - gUnknown_02039D80->toRow) + 1;
    gUnknown_02039D80->columsTotal = abs(gUnknown_02039D80->fromColumn - gUnknown_02039D80->toColumn) + 1;
    boxId = StorageGetCurrentBox();
    monArrayId = 0;
    rowCount = gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal;
    columnCount = gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal;
    for (i = gUnknown_02039D80->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + gUnknown_02039D80->minRow;
        for (j = gUnknown_02039D80->minRow; j < rowCount; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);

            gUnknown_02039D80->boxMons[monArrayId] = *boxMon;
            monArrayId++;
            boxPosition++;
        }
    }
}

void sub_80D09A4(void)
{
    s32 i, j;
    s32 rowCount = gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal;
    s32 columnCount = gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal;
    u8 boxId = StorageGetCurrentBox();

    for (i = gUnknown_02039D80->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + gUnknown_02039D80->minRow;
        for (j = gUnknown_02039D80->minRow; j < rowCount; j++)
        {
            DestroyBoxMonIconAtPosition(boxPosition);
            ZeroBoxMonAt(boxId, boxPosition);
            boxPosition++;
        }
    }
}

void sub_80D0A1C(void)
{
    s32 i, j;
    s32 rowCount = gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal;
    s32 columnCount = gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal;
    u8 monArrayId = 0;

    for (i = gUnknown_02039D80->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + gUnknown_02039D80->minRow;
        for (j = gUnknown_02039D80->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&gUnknown_02039D80->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                sub_80CB140(boxPosition);
            monArrayId++;
            boxPosition++;
        }
    }
}

void sub_80D0AAC(void)
{
    s32 i, j;
    s32 rowCount = gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal;
    s32 columnCount = gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal;
    u8 boxId = StorageGetCurrentBox();
    u8 monArrayId = 0;

    for (i = gUnknown_02039D80->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + gUnknown_02039D80->minRow;
        for (j = gUnknown_02039D80->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&gUnknown_02039D80->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                SetBoxMonAt(boxId, boxPosition, &gUnknown_02039D80->boxMons[monArrayId]);
            boxPosition++;
            monArrayId++;
        }
    }
}

void sub_80D0B5C(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgAttribute(0, 4, 0);
    ClearGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

u8 sub_80D0BA4(void)
{
    return (IN_BOX_ROWS * gUnknown_02039D80->fromColumn) + gUnknown_02039D80->fromRow;
}

bool8 sub_80D0BC0(void)
{
    s32 i, j;
    s32 rowCount = gUnknown_02039D80->minRow + gUnknown_02039D80->rowsTotal;
    s32 columnCount = gUnknown_02039D80->minColumn + gUnknown_02039D80->columsTotal;
    u8 monArrayId = 0;

    for (i = gUnknown_02039D80->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + gUnknown_02039D80->minRow;
        for (j = gUnknown_02039D80->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&gUnknown_02039D80->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES)
                && GetCurrentBoxMonData(boxPosition, MON_DATA_SANITY_HAS_SPECIES))
                return FALSE;

            monArrayId++;
            boxPosition++;
        }
    }

    return TRUE;
}

const u32 gUnknown_0857BB24[] = INCBIN_U32("graphics/pokemon_storage/unknown_frame.4bpp");

static const struct OamData sOamData_857BBA4 =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBAC[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBBC[] =
{
    AFFINEANIMCMD_FRAME(88, 88, 0, 0),
    AFFINEANIMCMD_FRAME(5, 5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBD4[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBEC[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(10, 10, 0, 12),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC0C[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-10, -10, 0, 12),
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC2C[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC44[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_857BC44[] =
{
    sSpriteAffineAnim_857BBAC,
    sSpriteAffineAnim_857BBBC,
    sSpriteAffineAnim_857BBD4,
    sSpriteAffineAnim_857BBEC,
    sSpriteAffineAnim_857BC0C,
    sSpriteAffineAnim_857BC2C,
    sSpriteAffineAnim_857BC44
};

const struct SpriteTemplate gSpriteTemplate_857BC70 =
{
    .tileTag = 7,
    .paletteTag = 0xdacb,
    .oam = &sOamData_857BBA4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_857BC44,
    .callback = SpriteCallbackDummy,
};

void sub_80D0C60(void)
{
    s32 i;
    u8 spriteId;
    struct CompressedSpriteSheet spriteSheet;
    struct SpriteTemplate spriteTemplate;

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        spriteSheet.data = gUnknown_03000F78;
        spriteSheet.size = 0x200;
        spriteTemplate = gSpriteTemplate_857BC70;

        for (i = 0; i < 3; i++)
        {
            spriteSheet.tag = 7 + i;
            LoadCompressedSpriteSheet(&spriteSheet);
            gUnknown_02039D08->field_2204[i].tiles = GetSpriteTileStartByTag(spriteSheet.tag) * 32 + (void*)(OBJ_VRAM0);
            gUnknown_02039D08->field_2204[i].palIndex = AllocSpritePalette(0xDACB + i);
            gUnknown_02039D08->field_2204[i].palIndex *= 16;
            gUnknown_02039D08->field_2204[i].palIndex += 0x100;
            spriteTemplate.tileTag = 7 + i;
            spriteTemplate.paletteTag = 0xDACB + i;
            spriteId = CreateSprite(&spriteTemplate, 0, 0, 11);
            gUnknown_02039D08->field_2204[i].sprite = &gSprites[spriteId];
            gUnknown_02039D08->field_2204[i].sprite->invisible = TRUE;
            gUnknown_02039D08->field_2204[i].unk10 = 0;
        }
    }
    gUnknown_02039D08->movingItem = 0;
}

// The functions below handle new features of MOVE_ITEMS box option.

bool32 sub_80D1324(u8 cursorArea, u8 cursorPos);
const u32 *GetItemIconPic(u16 itemId);
const u16 *GetItemIconPalette(u16 itemId);
u8 sub_80D12E8(void);
void sub_80D140C(u8 id, u8 cursorArea, u8 cursorPos);
void sub_80D1524(u8 id, const u32 *itemTiles, const u16 *itemPal);
void sub_80D15D4(u8 id, u8 animNum);
void sub_80D1740(u8 id, bool8 arg1);
u8 sub_80D1370(u8 cursorArea, u8 cursorPos);
void sub_80D1604(u8 id, u8 arg1, u8 cursorArea, u8 cursorPos);
void sub_80D1AD8(struct Sprite *sprite);

void sub_80D0D8C(u8 cursorArea, u8 cursorPos)
{
    u16 heldItem;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;
    if (sub_80D1324(cursorArea, cursorPos))
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        if (!GetCurrentBoxMonData(cursorPos, MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos >= PARTY_SIZE || !GetMonData(&gPlayerParty[cursorPos], MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        break;
    default:
        return;
    }

    if (heldItem != 0)
    {
        const u32 *tiles = GetItemIconPic(heldItem);
        const u16 *pal = GetItemIconPalette(heldItem);
        u8 id = sub_80D12E8();

        sub_80D140C(id, cursorArea, cursorPos);
        sub_80D1524(id, tiles, pal);
        sub_80D15D4(id, 1);
        sub_80D1740(id, TRUE);
    }
}

void sub_80D0E50(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 2);
    sub_80D1604(id, 0, cursorArea, cursorPos);
}

static void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    item = 0;
    sub_80D15D4(id, 3);
    sub_80D1604(id, 1, cursorArea, cursorPos);
    sub_80D140C(id, 2, 0);
    if (cursorArea  == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &item);
        SetBoxMonIconObjMode(cursorPos, 1);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &item);
        SetPartyMonIconObjMode(cursorPos, 1);
    }

    gUnknown_02039D08->movingItem = gUnknown_02039D08->cursorMonItem;
}

void sub_80D0F38(u16 item)
{
    const u32 *tiles = GetItemIconPic(item);
    const u16 *pal = GetItemIconPalette(item);
    u8 id = sub_80D12E8();

    sub_80D1524(id, tiles, pal);
    sub_80D15D4(id, 6);
    sub_80D1604(id, 1, 0, 0);
    sub_80D140C(id, 2, 0);
    sub_80D1740(id, TRUE);
    gUnknown_02039D08->movingItem = item;
}

static void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 3);
    sub_80D1604(id, 3, 2, 0);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        item = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &gUnknown_02039D08->movingItem);
        gUnknown_02039D08->movingItem = item;
    }
    else
    {
        item = GetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &gUnknown_02039D08->movingItem);
        gUnknown_02039D08->movingItem = item;
    }

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 4, cursorArea, cursorPos);
}

static void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 2, cursorArea, cursorPos);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &gUnknown_02039D08->movingItem);
        SetBoxMonIconObjMode(cursorPos, 0);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &gUnknown_02039D08->movingItem);
        SetPartyMonIconObjMode(cursorPos, 0);
    }
}

static void Item_TakeMons(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    item = 0;
    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 2);
    sub_80D1604(id, 0, cursorArea, cursorPos);
    if (cursorArea  == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &item);
        SetBoxMonIconObjMode(cursorPos, 1);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &item);
        SetPartyMonIconObjMode(cursorPos, 1);
    }
}

void sub_80D1194(void)
{
    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        u8 id = sub_80D1370(2, 0);
        sub_80D15D4(id, 5);
        sub_80D1604(id, 0, 2, 0);
    }
}

void sub_80D11CC(void)
{
    s32 i;

    if (gUnknown_02039D08->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10 && gUnknown_02039D08->field_2204[i].unk8 == 1)
            sub_80D1604(i, 7, 2, 0);
    }
}

bool8 sub_80D1218(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10)
        {
            if (!gUnknown_02039D08->field_2204[i].sprite->affineAnimEnded && gUnknown_02039D08->field_2204[i].sprite->affineAnimBeginning)
                return TRUE;
            if (gUnknown_02039D08->field_2204[i].sprite->callback != SpriteCallbackDummy && gUnknown_02039D08->field_2204[i].sprite->callback != sub_80D1AD8)
                return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_80D127C(void)
{
    s32 i;

    if (gUnknown_02039D08->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < 3; i++)
        {
            if (gUnknown_02039D08->field_2204[i].unk10 && gUnknown_02039D08->field_2204[i].unk8 == 2)
                return TRUE;
        }
    }

    return FALSE;
}

const u8 *GetMovingItemName(void)
{
    return ItemId_GetName(gUnknown_02039D08->movingItem);
}

u16 GetMovingItem(void)
{
    return gUnknown_02039D08->movingItem;
}

u8 sub_80D12E8(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10 == 0)
        {
            gUnknown_02039D08->field_2204[i].unk10 = 1;
            return i;
        }
    }

    return 3;
}

bool32 sub_80D1324(u8 cursorArea, u8 cursorPos)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10
            && gUnknown_02039D08->field_2204[i].unk8 == cursorArea
            && gUnknown_02039D08->field_2204[i].unk9 == cursorPos)
            return TRUE;
    }

    return FALSE;
}

u8 sub_80D1370(u8 cursorArea, u8 cursorPos)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10
            && gUnknown_02039D08->field_2204[i].unk8 == cursorArea
            && gUnknown_02039D08->field_2204[i].unk9 == cursorPos)
            return i;
    }

    return 3;
}

u8 sub_80D13C4(struct Sprite *sprite)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (gUnknown_02039D08->field_2204[i].unk10
            && gUnknown_02039D08->field_2204[i].sprite == sprite)
            return i;
    }

    return 3;
}
