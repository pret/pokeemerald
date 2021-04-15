#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fldeff_misc.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "mon_markings.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pc_screen_effect.h"
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
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum {
    BOX_OPTION_WITHDRAW,
    BOX_OPTION_DEPOSIT,
    BOX_OPTION_MOVE_MONS,
    BOX_OPTION_MOVE_ITEMS,
    BOX_OPTION_EXIT,
};

// IDs for messages to print with PrintMessage
enum {
    MSG_EXIT_BOX,
    MSG_WHAT_YOU_DO,
    MSG_PICK_A_THEME,
    MSG_PICK_A_WALLPAPER,
    MSG_IS_SELECTED,
    MSG_JUMP_TO_WHICH_BOX,
    MSG_DEPOSIT_IN_WHICH_BOX,
    MSG_WAS_DEPOSITED,
    MSG_BOX_IS_FULL,
    MSG_RELEASE_POKE,
    MSG_WAS_RELEASED,
    MSG_BYE_BYE,
    MSG_MARK_POKE,
    MSG_LAST_POKE,
    MSG_PARTY_FULL,
    MSG_HOLDING_POKE,
    MSG_WHICH_ONE_WILL_TAKE,
    MSG_CANT_RELEASE_EGG,
    MSG_CONTINUE_BOX,
    MSG_CAME_BACK,
    MSG_WORRIED,
    MSG_SURPRISE,
    MSG_PLEASE_REMOVE_MAIL,
    MSG_IS_SELECTED2,
    MSG_GIVE_TO_MON,
    MSG_PLACED_IN_BAG,
    MSG_BAG_FULL,
    MSG_PUT_IN_BAG,
    MSG_ITEM_IS_HELD,
    MSG_CHANGED_TO_ITEM,
    MSG_CANT_STORE_MAIL,
};

enum {
    MSG_FORMAT_NORMAL,
    MSG_FORMAT_MON_NAME_1,
    MSG_FORMAT_MON_NAME_2, // Unused
    MSG_FORMAT_MON_NAME_3, // Unused
    MSG_FORMAT_MON_NAME_4,
    MSG_FORMAT_MON_NAME_5, // Unused
    MSG_FORMAT_MON_NAME_6,
    MSG_FORMAT_ITEM_NAME,
};

// IDs for menu selection items. See SetMenuText, HandleMenuInput, etc
enum {
    MENU_CANCEL,
    MENU_STORE,
    MENU_WITHDRAW,
    MENU_MOVE,
    MENU_SHIFT,
    MENU_PLACE,
    MENU_SUMMARY,
    MENU_RELEASE,
    MENU_MARK,
    MENU_JUMP,
    MENU_WALLPAPER,
    MENU_NAME,
    MENU_TAKE,
    MENU_GIVE,
    MENU_GIVE_2,
    MENU_SWITCH,
    MENU_BAG,
    MENU_INFO,
    MENU_SCENERY_1,
    MENU_SCENERY_2,
    MENU_SCENERY_3,
    MENU_ETCETERA,
    MENU_FRIENDS,
    MENU_FOREST,
    MENU_CITY,
    MENU_DESERT,
    MENU_SAVANNA,
    MENU_CRAG,
    MENU_VOLCANO,
    MENU_SNOW,
    MENU_CAVE,
    MENU_BEACH,
    MENU_SEAFLOOR,
    MENU_RIVER,
    MENU_SKY,
    MENU_POLKADOT,
    MENU_POKECENTER,
    MENU_MACHINE,
    MENU_SIMPLE,
};
#define MENU_WALLPAPER_SETS_START MENU_SCENERY_1
#define MENU_WALLPAPERS_START MENU_FOREST

enum {
    SCREEN_CHANGE_EXIT_BOX,
    SCREEN_CHANGE_SUMMARY_SCREEN,
    SCREEN_CHANGE_NAME_BOX,
    SCREEN_CHANGE_ITEM_FROM_BAG,
};

enum {
    MODE_PARTY,
    MODE_BOX,
    MODE_MOVE,
};

enum {
    FRIENDS_ZIGZAGOON,
    FRIENDS_SCREEN,
    FRIENDS_HORIZONTAL,
    FRIENDS_DIAGONAL,
    FRIENDS_BLOCK,
    FRIENDS_RIBBON,
    FRIENDS_POKECENTER2,
    FRIENDS_FRAME,
    FRIENDS_BLANK,
    FRIENDS_CIRCLES,
    FRIENDS_AZUMARILL,
    FRIENDS_PIKACHU,
    FRIENDS_LEGENDARY,
    FRIENDS_DUSCLOPS,
    FRIENDS_LUDICOLO,
    FRIENDS_WHISCASH,
    FRIENDS_WALLPAPERS_COUNT
};

enum {
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
#define PALTAG_BOX_TITLE        0xDAC9
#define TAG_PAL_DAC0        0xDAC0
#define TAG_PAL_DACB        0xDACB

#define TAG_TILE_0           0
#define TAG_TILE_1           1
#define TAG_TILE_2           2
#define GFXTAG_BOX_TITLE     3
#define GFXTAG_BOX_TITLE_ALT 4
#define TAG_TILE_WAVEFORM    5
#define GFXTAG_ARROW         6
#define TAG_TILE_7           7
#define TAG_TILE_A          10
#define TAG_TILE_D          13
#define TAG_TILE_10         16
#define TAG_TILE_12         18


struct Wallpaper
{
    const u32 *tiles;
    const u32 *tilemap;
    const u16 *palettes;
};

struct PokemonStorageSystemFunc
{
    u8 (*func)(void);
    s8 unk4;
};

struct StorageMessage
{
    const u8 *text;
    u8 format;
};

struct StorageMenu
{
    const u8 *text;
    int textId;
};

struct PSS_MenuStringPtrs
{
    const u8 *text;
    const u8 *desc;
};

struct UnkStruct_2000028
{
    const u8 *unk_00;
    u8 *unk_04;
    u16 unk_08;
    u16 unk_0a;
    u16 newField;
    void (*unk_0c)(struct UnkStruct_2000028 *data);
};

struct UnkStruct_2000020
{
    struct UnkStruct_2000028 *unk_00;
    u8 unk_04;
    u8 unk_05;
};

struct UnkPSSStruct_2002370
{
    struct Sprite *unk_0000;
    struct Sprite *unk_0004[4];
    u32 unk_0014[3];
    struct Sprite *arrowSprites[2];
    u8 filler_0028[0x214];
    u32 unk_023c;
    u16 unk_0240;
    u16 unk_0242;
    u8 curBox;
    u8 unk_0245;
    u8 unk_0246;
};

struct UnkStorageStruct
{
    struct Sprite *sprite;
    u8 *tiles;
    u16 palIndex;
    u8 unk8;
    u8 unk9;
    u8 unk10;
};

struct PokemonStorageSystemData
{
    u8 state;
    u8 boxOption;
    u8 screenChangeType;
    bool8 isReshowingPSS;
    u8 taskId;
    struct UnkStruct_2000020 unk_0020;
    struct UnkStruct_2000028 unk_0028[8];
    u16 field_B0[528 / 2];
    u16 field_2C0;
    u16 field_2C2;
    u8 field_2C4; // Unused
    u8 field_2C5;
    u8 showPartyMenuState;
    u8 unk_02C7;
    u8 unk_02C8;
    bool8 unk_02C9;
    s16 newCurrBoxId;
    u16 bg2_X;
    s16 wallpaperScrollSpeed;
    u16 field_2D0;
    u8 wallpaperOffset;
    u8 field_2D3; // Written to, but never read.
    u8 scrollToBoxIdUnused; // Written to, but never read.
    u16 field_2D6; // Written to, but never read.
    s16 scrollDirectionUnused; // Written to, but never read.
    u16 field_2DA; // Written to, but never read.
    u16 field_2DC; // Written to, but never read.
    u16 field_2DE; // Written to, but never read.
    u16 field_2E0; // Written to, but never read.
    u8 filler[22];
    u8 boxTitleTiles[1024];
    u8 boxTitleCycleId;
    u8 wallpaperLoadState; // Written to, but never read.
    u8 wallpaperLoadBoxId;
    s8 wallpaperLoadDir;
    u16 boxTitlePal[16];
    u16 boxTitlePalOffset;
    u16 boxTitleAltPalOffset;
    struct Sprite *curBoxTitleSprites[2];
    struct Sprite *nextBoxTitleSprites[2];
    struct Sprite *arrowSprites[2];
    u32 boxTitlePalBits;
    u8 field_73C[80]; // Unused
    u16 field_78C; // Written to, but never read.
    s16 wallpaperSetId;
    s16 wallpaperId;
    u16 wallpaperTilemap[360];
    u8 wallpaperChangeState;
    u8 scrollState;
    u8 scrollToBoxId;
    s8 scrollDirection;
    u8 *wallpaperTiles;
    struct Sprite *movingMonSprite;
    struct Sprite *partySprites[PARTY_SIZE];
    struct Sprite *boxMonsSprites[IN_BOX_COUNT];
    struct Sprite **field_B00;
    struct Sprite **field_B04;
    u16 field_B08[40];
    u16 field_B58[40];
    u16 boxSpecies[IN_BOX_COUNT];
    u32 boxPersonalities[IN_BOX_COUNT];
    u8 field_C5C;
    u8 field_C5D;
    u8 field_C5E;
    u16 field_C60;
    s16 field_C62;
    s16 field_C64;
    u16 field_C66;
    u8 field_C68;
    s8 field_C69;
    u8 field_C6A;
    u8 field_C6B; // Written to, but never read.
    struct WindowTemplate menuWindow;
    struct StorageMenu menuItems[7];
    u8 menuItemsCount;
    u8 menuWidth;
    u8 field_CAE; // Written to, but never read.
    u16 menuWindowId;
    struct Sprite *field_CB4;
    struct Sprite *field_CB8;
    s32 field_CBC;
    s32 field_CC0;
    u32 field_CC4;
    u32 field_CC8;
    s16 field_CCC;
    s16 field_CCE;
    u16 field_CD0;
    s8 field_CD2;
    s8 field_CD3;
    u8 field_CD4;
    u8 field_CD5;
    u8 field_CD6;
    u8 field_CD7;
    u8 field_CD8[2];
    const u32 *cursorMonPalette;
    u32 cursorMonPersonality;
    u16 cursorMonSpecies;
    u16 cursorMonItem;
    u16 field_CE8;
    bool8 setMosaic;
    u8 cursorMonMarkings;
    u8 cursorMonLevel;
    bool8 cursorMonIsEgg;
    u8 cursorMonNick[POKEMON_NAME_LENGTH + 1];
    u8 cursorMonNickText[36];
    u8 cursorMonSpeciesName[36];
    u8 cursorMonGenderLvlText[36];
    u8 cursorMonItemName[36];
    bool8 (*monPlaceChangeFunc)(void);
    u8 monPlaceChangeState;
    u8 field_D91;
    struct Sprite *field_D94;
    struct Sprite *field_D98[2];
    u16 *field_DA0;
    struct MonMarkingsMenu markMenu;
    struct UnkPSSStruct_2002370 field_1E5C;
    struct Pokemon movingMon;
    struct Pokemon field_2108;
    s8 field_216C;
    u8 field_216D;
    s8 field_216E;
    s8 field_216F;
    s8 field_2170;
    s8 field_2171;
    u16 field_2172;
    u16 field_2174;
    u16 field_2176[8];
    u8 field_2186;
    u8 field_2187;
    u8 pokemonSummaryScreenMode;
    union
    {
        struct Pokemon *mon;
        struct BoxPokemon *box;
    } field_218C;
    u8 field_2190[40];
    u8 boxTitleText[40];
    u8 field_21E0[POKEMON_NAME_LENGTH + 1];
    u8 itemName[20];
    u8 inBoxMovingMode;
    u16 field_2200;
    struct UnkStorageStruct field_2204[3];
    u16 movingItem;
    u16 field_2236;
    u8 field_2238; // Unused
    u16 field_223A;
    u16 *field_223C;
    struct Sprite *cursorMonSprite;
    u16 field_2244[0x40];
    u8 field_22C4[0x800];
    u8 field_2AC4[0x1800]; // Unused
    u8 field_42C4[0x800];
    u8 wallpaperBgTilemapBuffer[0x1000];
    u8 field_5AC4[0x800];
};

struct UnkSubStruct_2039D84
{
    s16 field_0;
    s16 field_2;
    u16 field_4;
    u16 field_6;
    s16 field_8;
    s16 field_A;
};

struct UnkStruct_2039D84
{
    struct UnkSubStruct_2039D84 field_0[2];
    const void *field_18;
    const void *field_1C;
    u16 field_20;
    u16 field_22;
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u8 field_2A;
    u8 field_2B;
    u8 field_2C;
    u8 field_2D;
};

// IWRAM bss
static u32 gUnknown_03000F78[98];

// EWRAM DATA
EWRAM_DATA static u8 sPreviousBoxOption = 0;
EWRAM_DATA static struct UnkPSSStruct_2002370 *gUnknown_02039D04 = NULL;
EWRAM_DATA static struct PokemonStorageSystemData *sPSSData = NULL;
EWRAM_DATA static bool8 sInPartyMenu = 0;
EWRAM_DATA static u8 sCurrentBoxOption = 0;
EWRAM_DATA static u8 gUnknown_02039D0E = 0;
EWRAM_DATA static u8 sWhichToReshow = 0;
EWRAM_DATA static u8 sLastUsedBox = 0;
EWRAM_DATA static u16 sMovingItemId = 0;
EWRAM_DATA static struct Pokemon gUnknown_02039D14 = {0};
EWRAM_DATA static s8 sBoxCursorArea = 0;
EWRAM_DATA static s8 sBoxCursorPosition = 0;
EWRAM_DATA static bool8 sIsMonBeingMoved = 0;
EWRAM_DATA static u8 sMovingMonOrigBoxId = 0;
EWRAM_DATA static u8 sMovingMonOrigBoxPos = 0;
EWRAM_DATA static bool8 sCanOnlyMove = 0;

// This file's functions.
static void CreatePCMenu(u8, s16 *);
static void Cb2_EnterPSS(u8);
static u8 GetCurrentBoxOption(void);
static u8 HandleInput(void);
static u8 sub_80CDC2C(void);
static u8 sub_80CB9BC(void);
static void LoadWallpaperGfx(u8, s8);
static void CreateIncomingBoxTitle(u8, s8);
static void StartBoxScrollArrowsSlide(s8);
static void SetCurrentBox(u8);
static void CreateInitBoxTask(u8);
static void sub_80C7958(u8);
static void TrimOldWallpaper(void *);
static void sub_80C7B14(void);
static void sub_80C7BB4(void);
static void ScrollBackground(void);
static void sub_80C7B80(void);
static void sub_80C7BE4(void);
static void sub_80CAA14(void);
static void sub_80CFDC4(void);
static void sub_80CE790(void);
static void sub_80CE8E4(void);
static void GiveChosenBagItem(void);
static void SetUpHidePartyMenu(void);
static void DestroyAllPartyMonIcons(void);
static void sub_80D11CC(void);
static void LoadPSSMenuGfx(void);
static void LoadWaveformSpritePalette(void);
static void sub_80CDC18(void);
static void sub_80CD36C(void);
static void sub_80CD3EC(void);
static void sub_80CAC1C(void);
static void sub_80CEBDC(void);
static void SetScrollingBackground(void);
static void sub_80CABE0(void);
static void sub_80CAEAC(void);
static void sub_80D0C60(void);
static void sub_80CFEA8(void);
static void sub_80CDC0C(void);
static void sub_80CAF04(void);
static void sub_80CA0D8(void);
static void AddMenu(void);
static void sub_80CE250(void);
static void InitCanRelaseMonVars(void);
static void sub_80D01B8(void);
static void ReleaseMon(void);
static void RefreshCursorMonData(void);
static void LoadCursorMonSprite(void);
static void sub_80CA154(void);
static void sub_80CA1C4(void);
static void sub_80CC064(void);
static void sub_80CE324(void);
static void ClearBottomWindow(void);
static void sub_80CA704(void);
static void RemoveMenu(void);
static void sub_80CE00C(void);
static void sub_80D1194(void);
static void PrintCursorMonInfo(void);
static void sub_80CA65C(void);
static void AddWallpaperSetsMenu(void);
static void CreateBoxScrollArrows(void);
static void InitMenu(void);
static void StopBoxScrollArrowsSlide(void);
static void sub_80CFC14(void);
static void sub_80CEB40(void);
static void CycleBoxTitleSprites(void);
static void sub_80D1818(void);
static void sub_80D19B4(u32);
static void sub_80CAA74(void);
static void PrintItemDescription(void);
static void sub_80CE760(void);
static void sub_80CDBA0(void);
static void sub_80CE7E8(void);
static void sub_80CFECC(void);
static void sub_80CA9EC(void);
static void FreePSSData(void);
static void AddBoxMenu(void);
static void CycleBoxTitleColor(void);
static void MoveMon(void);
static void PlaceMon(void);
static void sub_80CAB20(void);
static void sub_80CE22C(void);
static void sub_80CDA68(void);
static void sub_80CB950(void);
static void sub_80CA9C0(void);
static void SetUpDoShowPartyMenu(void);
static void BoxSetMosaic(void);
static void SpriteCB_JumpBoxArrow(struct Sprite *);
static void sub_80CC100(struct Sprite *);
static void sub_80CB278(struct Sprite *);
static void SpriteCB_Arrow(struct Sprite *);
static bool32 WaitForWallpaperGfxLoad(void);
static bool8 InitPSSWindows(void);
static bool8 sub_80CC0A0(void);
static bool8 sub_80CE2A8(void);
static bool8 sub_80D0164(void);
static bool8 IsInitBoxActive(void);
static bool8 sub_80D01E4(void);
static bool8 sub_80CDED4(void);
static bool8 sub_80CDF08(void);
static bool8 sub_80D184C(void);
static bool8 sub_80D18E4(void);
static bool8 DoShowPartyMenu(void);
static bool8 sub_80D1218(void);
static bool8 ScrollToBox(void);
static bool8 sub_80CD554(void);
static bool8 HidePartyMenu(void);
static bool8 IsActiveItemMoving(void);
static bool8 sub_80D0580(u8 arg0);
static bool8 sub_80D0BC0(void);
static bool8 sub_80CA2B8(void);
static bool8 DoWallpaperGfxChange(void);
static bool8 DoMonPlaceChange(void);
static bool8 IsMenuLoading(void);
static bool8 CanMovePartyMon(void);
static bool8 CanShiftMon(void);
static bool8 IsCursorOnCloseBox(void);
static bool8 IsCursorOnBox(void);
static bool8 IsCursorInBox(void);
static bool8 IsMonBeingMoved(void);
static bool8 TryStorePartyMonInBox(u8);
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
static void SetUpScrollToBox(u8);
static void sub_80CFE54(u8);
static void SetMovingMonPriority(u8);
static void InitMonPlaceChange(u8);
static void SetMonMarkings(u8);
static void ShowYesNoWindow(s8);
static void sub_80CDBF8(u8);
static void sub_80D01D0(u8);
static void AnimateBoxScrollArrows(bool8);
static void sub_80CA984(bool8);
static void CreatePartyMonsSprites(bool8);
static void PrintMessage(u8 id);
static s16 HandleMenuInput(void);
static s8 RunCanReleaseMon(void);
static u8 GetBoxCursorPosition(void);
static void Item_FromMonToMoving(u8, u8);
static void Item_GiveMovingToMon(u8, u8);
static void Item_TakeMons(u8, u8);
static void Item_SwitchMonsWithMoving(u8, u8);
static struct Sprite *CreateJumpBoxArrows(u16, u16, u8, u8, u8);
static void SetWallpaperForCurrentBox(u8);
static void AddWallpapersMenu(u8);
static u16 GetMovingItem(void);
static void LoadCursorMonGfx(u16 species, u32 pid);
static void sub_80CA2D0(struct Sprite *sprite);
static void SpriteCB_OutgoingBoxTitle(struct Sprite *);
static void sub_80CBA3C(struct Sprite *sprite);
static void SpriteCB_IncomingBoxTitle(struct Sprite *);
static void sub_80CBAF0(s16 yDelta);
static void sub_80CAAA8(u8 arg0, bool8 isPartyMon);
static const u8 *GetMovingItemName(void);
static void SetMenuText(u8 textId);
static void sub_80D0D8C(u8 cursorArea, u8 cursorPos);
static void sub_80D0E50(u8 cursorArea, u8 cursorPos);
static void sub_80D0F38(u16 item);
static struct Sprite *CreateMonIconSprite(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority);
static void DestroyBoxMonIcon(struct Sprite *sprite);
static void SetBoxSpeciesAndPersonalities(u8);
static void sub_80CB9D0(struct Sprite *, u16);
static void Task_InitBox(u8 taskId);
static void InitBoxTitle(u8 boxId);
static s8 DetermineBoxScrollDirection(u8 boxId);
static void DrawWallpaper(const void *, s8, u8);
static s16 GetBoxTitleBaseX(const u8 *);
static bool8 MonPlaceChange_Shift(void);
static bool8 MonPlaceChange_Move(void);
static bool8 MonPlaceChange_Place(void);
static bool8 sub_80CDEC4(void);
static bool8 sub_80CDEB4(void);
static void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y);
static void SetShiftedMonData(u8 boxId, u8 position);
static void SetMovedMonData(u8 boxId, u8 position);
static void SetPlacedMonData(u8 boxId, u8 position);
static void PurgeMonOrBoxMon(u8 boxId, u8 position);
static void SetCursorMonData(void *pokemon, u8 mode);
static bool32 AtLeastThreeUsableMons(void);
static u8 InBoxInput_Normal(void);
static u8 InBoxInput_MovingMultiple(void);
static u8 InBoxInput_GrabbingMultiple(void);
static s8 GetMenuItemTextId(u8);
static u8 sub_80CFA5C(void);
static u8 sub_80D0BA4(void);
static bool8 sub_80CFA84(void);
static bool8 sub_80CFB44(void);
static bool8 sub_80D024C(void);
static bool8 sub_80D0344(void);
static bool8 sub_80D03B0(void);
static bool8 sub_80D0420(void);
static bool8 sub_80D04A0(void);
static bool8 sub_80D04C8(void);
static void sub_80D07B0(u8 arg0, u8 arg1);
static void sub_80D0834(u8 arg0, u8 arg1);
static void sub_80D0B5C(void);
static void sub_80D062C(void);
static void sub_80D0884(u16 arg0, u16 arg1, u16 arg2);
static void sub_80D08CC(void);
static void sub_80D09A4(void);
static void sub_80D0A1C(void);
static void sub_80D0AAC(void);
static u8 sub_80D0894(void);
static void sub_80D0778(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D0708(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D0740(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D27AC(u8 id, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
static void sub_80D27F4(u8 id, u8 arg1, s8 arg2);
static void sub_80D2644(u8 id, u8 bg, const void *arg2, u16 arg3, u16 arg4);
static void sub_80D2770(u8 id, u16 arg1, u16 arg2);
static void sub_80D259C(u8 count);
static void sub_80D25F0(void);
static void sub_80D2918(u8 id);
static void sub_80D2960(u8 id);
static void sub_80D29F8(u8 id);
static void sub_80D2A90(struct UnkStruct_2000020 *arg0, struct UnkStruct_2000028 *arg1, u32 arg2);
static void sub_80D2AA4(void);
static void sub_80D2B88(struct UnkStruct_2000028 *unkStruct);
static void sub_80D2C1C(struct UnkStruct_2000028 *unkStruct);
static u8 GetBoxWallpaper(u8);
static void SetBoxWallpaper(u8, u8);

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

static const u8 sBoxInfoTextColors[] = {TEXT_COLOR_RED, TEXT_DYNAMIC_COLOR_6, TEXT_DYNAMIC_COLOR_5};
static const u8 sText_OutOf30[] = _("/30");

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

static const struct StorageMessage sMessages[] =
{
    [MSG_EXIT_BOX]             = {gText_ExitFromBox, MSG_FORMAT_NORMAL},
    [MSG_WHAT_YOU_DO]          = {gText_WhatDoYouWantToDo, MSG_FORMAT_NORMAL},
    [MSG_PICK_A_THEME]         = {gText_PleasePickATheme, MSG_FORMAT_NORMAL},
    [MSG_PICK_A_WALLPAPER]     = {gText_PickTheWallpaper, MSG_FORMAT_NORMAL},
    [MSG_IS_SELECTED]          = {gText_PkmnIsSelected, MSG_FORMAT_MON_NAME_1},
    [MSG_JUMP_TO_WHICH_BOX]    = {gText_JumpToWhichBox, MSG_FORMAT_NORMAL},
    [MSG_DEPOSIT_IN_WHICH_BOX] = {gText_DepositInWhichBox, MSG_FORMAT_NORMAL},
    [MSG_WAS_DEPOSITED]        = {gText_PkmnWasDeposited, MSG_FORMAT_MON_NAME_1},
    [MSG_BOX_IS_FULL]          = {gText_BoxIsFull2, MSG_FORMAT_NORMAL},
    [MSG_RELEASE_POKE]         = {gText_ReleaseThisPokemon, MSG_FORMAT_NORMAL},
    [MSG_WAS_RELEASED]         = {gText_PkmnWasReleased, MSG_FORMAT_MON_NAME_4},
    [MSG_BYE_BYE]              = {gText_ByeByePkmn, MSG_FORMAT_MON_NAME_6},
    [MSG_MARK_POKE]            = {gText_MarkYourPkmn, MSG_FORMAT_NORMAL},
    [MSG_LAST_POKE]            = {gText_ThatsYourLastPkmn, MSG_FORMAT_NORMAL},
    [MSG_PARTY_FULL]           = {gText_YourPartysFull, MSG_FORMAT_NORMAL},
    [MSG_HOLDING_POKE]         = {gText_YoureHoldingAPkmn, MSG_FORMAT_NORMAL},
    [MSG_WHICH_ONE_WILL_TAKE]  = {gText_WhichOneWillYouTake, MSG_FORMAT_NORMAL},
    [MSG_CANT_RELEASE_EGG]     = {gText_YouCantReleaseAnEgg, MSG_FORMAT_NORMAL},
    [MSG_CONTINUE_BOX]         = {gText_ContinueBoxOperations, MSG_FORMAT_NORMAL},
    [MSG_CAME_BACK]            = {gText_PkmnCameBack, MSG_FORMAT_MON_NAME_1},
    [MSG_WORRIED]              = {gText_WasItWorriedAboutYou, MSG_FORMAT_NORMAL},
    [MSG_SURPRISE]             = {gText_FourEllipsesExclamation, MSG_FORMAT_NORMAL},
    [MSG_PLEASE_REMOVE_MAIL]   = {gText_PleaseRemoveTheMail, MSG_FORMAT_NORMAL},
    [MSG_IS_SELECTED2]         = {gText_PkmnIsSelected, MSG_FORMAT_ITEM_NAME},
    [MSG_GIVE_TO_MON]          = {gText_GiveToAPkmn, MSG_FORMAT_NORMAL},
    [MSG_PLACED_IN_BAG]        = {gText_PlacedItemInBag, MSG_FORMAT_ITEM_NAME},
    [MSG_BAG_FULL]             = {gText_BagIsFull2, MSG_FORMAT_NORMAL},
    [MSG_PUT_IN_BAG]           = {gText_PutItemInBag, MSG_FORMAT_NORMAL},
    [MSG_ITEM_IS_HELD]         = {gText_ItemIsNowHeld, MSG_FORMAT_ITEM_NAME},
    [MSG_CHANGED_TO_ITEM]      = {gText_ChangedToNewItem, MSG_FORMAT_ITEM_NAME},
    [MSG_CANT_STORE_MAIL]      = {gText_MailCantBeStored, MSG_FORMAT_NORMAL},
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
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_8572874 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
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

static const struct SpriteTemplate sSpriteTemplate_Waveform =
{
    .tileTag = TAG_TILE_WAVEFORM,
    .paletteTag = TAG_PAL_WAVEFORM,
    .oam = &sOamData_8572874,
    .anims = sSpriteAnimTable_85728AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC;
static const struct SpriteTemplate gUnknown_085728D4 =
{
    .tileTag = TAG_TILE_12,
    .paletteTag = TAG_PAL_DAC0,
    .oam = &sOamData_85728EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
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

#include "data/wallpapers.h"

// Unknown Unused data.
static const u16 gUnknown_0857B07C = 0x23BA;

static const struct SpriteSheet sSpriteSheet_Arrow = {sArrow_Gfx, 0x80, GFXTAG_ARROW};

static const struct OamData sOamData_BoxTitle =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2
};

static const union AnimCmd sAnim_BoxTitle_Left[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_BoxTitle_Right[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_BoxTitle[] =
{
    sAnim_BoxTitle_Left,
    sAnim_BoxTitle_Right
};

static const struct SpriteTemplate sSpriteTemplate_BoxTitle =
{
    .tileTag = GFXTAG_BOX_TITLE,
    .paletteTag = PALTAG_BOX_TITLE,
    .oam = &sOamData_BoxTitle,
    .anims = sAnims_BoxTitle,
    .images NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_Arrow =
{
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 2
};

static const union AnimCmd sAnim_Arrow_Left[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Arrow_Right[] =
{
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Arrow[] =
{
    sAnim_Arrow_Left,
    sAnim_Arrow_Right
};

static const struct SpriteTemplate sSpriteTemplate_Arrow =
{
    .tileTag = GFXTAG_ARROW,
    .paletteTag = TAG_PAL_WAVEFORM,
    .oam = &sOamData_Arrow,
    .anims = sAnims_Arrow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Arrow
};

static const u16 gHandCursorPalette[] = INCBIN_U16("graphics/pokemon_storage/hand_cursor.gbapal");
static const u8 gHandCursorTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor.4bpp");
static const u8 gHandCursorShadowTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor_shadow.4bpp");

// code
void DrawTextWindowAndBufferTiles(const u8 *string, void *dst, u8 zero1, u8 zero2, s32 bytesToBuffer)
{
    s32 i, tileBytesToBuffer, remainingBytes;
    u16 windowId;
    u8 txtColor[3];
    u8 *tileData1, *tileData2;
    struct WindowTemplate winTemplate = {0};

    winTemplate.width = 24;
    winTemplate.height = 2;
    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(zero2));
    tileData1 = (u8*) GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    tileData2 = (winTemplate.width * 32) + tileData1;

    if (!zero1)
        txtColor[0] = TEXT_COLOR_TRANSPARENT;
    else
        txtColor[0] = zero2;
    txtColor[1] = TEXT_DYNAMIC_COLOR_6;
    txtColor[2] = TEXT_DYNAMIC_COLOR_5;
    AddTextPrinterParameterized4(windowId, 1, 0, 1, 0, 0, txtColor, -1, string);

    tileBytesToBuffer = bytesToBuffer;
    if (tileBytesToBuffer > 6u)
        tileBytesToBuffer = 6;
    remainingBytes = bytesToBuffer - 6;
    if (tileBytesToBuffer > 0)
    {
        for (i = tileBytesToBuffer; i != 0; i--)
        {
            CpuCopy16(tileData1, dst, 0x80);
            CpuCopy16(tileData2, dst + 0x80, 0x80);
            tileData1 += 0x80;
            tileData2 += 0x80;
            dst += 0x100;
        }
    }

    // Never used. bytesToBuffer is always passed <= 6, so remainingBytes is always <= 0 here
    if (remainingBytes > 0)
        CpuFill16((zero2 << 4) | zero2, dst, (u32)(remainingBytes) * 0x100);

    RemoveWindow(windowId);
}

// Unused
void sub_80C6EAC(const u8 *string, void *dst, u16 arg2, u8 arg3, u8 clr2, u8 clr3)
{
    u32 var;
    u8 windowId;
    u8 txtColor[3];
    u8 *tileData1, *tileData2;
    struct WindowTemplate winTemplate = {0};

    winTemplate.width = StringLength_Multibyte(string);
    winTemplate.height = 2;
    var = winTemplate.width * 32;
    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(arg3));
    tileData1 = (u8*) GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    tileData2 = (winTemplate.width * 32) + tileData1;
    txtColor[0] = arg3;
    txtColor[1] = clr2;
    txtColor[2] = clr3;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, txtColor, -1, string);
    CpuCopy16(tileData1, dst, var);
    CpuCopy16(tileData2, dst + arg2, var);
    RemoveWindow(windowId);
}

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

static void sub_80C71A4(u16 *dest, u16 dest_left, u16 dest_top, u16 width, u16 height)
{
    u16 i;

    dest += dest_top * 0x20 + dest_left;
    width *= 2;
    for (i = 0; i < height; dest += 0x20, i++)
        Dma3FillLarge16_(0, dest, width);
}

static void Task_PokemonStorageSystemPC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        CreatePCMenu(task->data[1], &task->data[15]);
        LoadMessageBoxAndBorderGfx();
        DrawDialogueFrame(0, 0);
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
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
        case MENU_NOTHING_CHOSEN:
            task->data[3] = task->data[1];
            if (JOY_NEW(DPAD_UP) && --task->data[3] < 0)
                task->data[3] = 4;

            if (JOY_NEW(DPAD_DOWN) && ++task->data[3] > 4)
                task->data[3] = 0;
            if (task->data[1] != task->data[3])
            {
                task->data[1] = task->data[3];
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            }
            break;
        case MENU_B_PRESSED:
        case  4:
            ClearStdWindowAndFrame(task->data[15], TRUE);
            ScriptContext2_Disable();
            EnableBothScriptContexts();
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
            break;
        default:
            if (task->data[2] == 0 && CountPartyMons() == PARTY_SIZE)
            {
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gText_PartyFull, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else if (task->data[2] == 1 && CountPartyMons() == 1)
            {
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gText_JustOnePkmn, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else
            {
                FadeScreen(FADE_TO_BLACK, 0);
                task->data[0] = 4;
            }
            break;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (--task->data[1] < 0)
                task->data[1] = 4;
            Menu_MoveCursor(-1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (++task->data[1] > 3)
                task->data[1] = 0;
            Menu_MoveCursor(1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_085716C0[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            CleanupOverworldWindowsAndTilemaps();
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

static void FieldCb_ReturnToPcMenu(void)
{
    u8 taskId;
    MainCallback vblankCb = gMain.vblankCallback;

    SetVBlankCallback(NULL);
    taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = sPreviousBoxOption;
    Task_PokemonStorageSystemPC(taskId);
    SetVBlankCallback(vblankCb);
    FadeInFromBlack();
}

static void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr)
{
    s16 windowId;
    struct WindowTemplate winTemplate = gUnknown_085716E8;
    winTemplate.width = GetMaxWidthInMenuTable((void *)gUnknown_085716C0, ARRAY_COUNT(gUnknown_085716C0));
    windowId = AddWindow(&winTemplate);

    DrawStdWindowFrame(windowId, FALSE);
    PrintMenuTable(windowId, ARRAY_COUNT(gUnknown_085716C0), (void *)gUnknown_085716C0);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, ARRAY_COUNT(gUnknown_085716C0), whichMenu);
    *windowIdPtr = windowId;
}

static void Cb2_ExitPSS(void)
{
    sPreviousBoxOption = GetCurrentBoxOption();
    gFieldCallback = FieldCb_ReturnToPcMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static s16 StorageSystemGetNextMonIndex(struct BoxPokemon *box, s8 startIdx, u8 stopIdx, u8 mode)
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
        SetBoxWallpaper(boxId, boxId % (MAX_DEFAULT_WALLPAPER + 1));

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

static u8 HandleBoxChooseSelectionInput(void)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return 201;
    }
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return gUnknown_02039D04->curBox;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        sub_80C7BB4();
    }
    else if (JOY_NEW(DPAD_RIGHT))
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
    oamData.size = SPRITE_SIZE(64x64);
    oamData.paletteNum = 1;
    template = (struct SpriteTemplate){
        0, 0, &oamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
    };

    gUnknown_02039D04->curBox = curBox;
    template.tileTag = gUnknown_02039D04->unk_0240;
    template.paletteTag = gUnknown_02039D04->unk_0242;

    spriteId = CreateSprite(&template, 160, 96, 0);
    gUnknown_02039D04->unk_0000 = gSprites + spriteId;

    oamData.shape = SPRITE_SHAPE(8x32);
    oamData.size = SPRITE_SIZE(8x32);
    template.tileTag = gUnknown_02039D04->unk_0240 + 1;
    template.anims = sSpriteAnimTable_8571710;
    for (i = 0; i < 4; i++)
    {
        u16 r5;
        spriteId = CreateSprite(&template, 124, 80, gUnknown_02039D04->unk_0246);
        gUnknown_02039D04->unk_0004[i] = gSprites + spriteId;
        r5 = 0;
        if (i & 2)
        {
            gUnknown_02039D04->unk_0004[i]->pos1.x = 196;
            r5 = 2;
        }
        if (i & 1)
        {
            gUnknown_02039D04->unk_0004[i]->pos1.y = 112;
            gUnknown_02039D04->unk_0004[i]->oam.size = 0;
            r5++;
        }
        StartSpriteAnim(gUnknown_02039D04->unk_0004[i], r5);
    }
    for (i = 0; i < 2; i++)
    {
        gUnknown_02039D04->arrowSprites[i] = CreateJumpBoxArrows(72 * i + 124, 88, i, 0, gUnknown_02039D04->unk_0246);
        if (gUnknown_02039D04->arrowSprites[i])
        {
            gUnknown_02039D04->arrowSprites[i]->data[0] = (i == 0 ? -1 : 1);
            gUnknown_02039D04->arrowSprites[i]->callback = SpriteCB_JumpBoxArrow;
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
        if (gUnknown_02039D04->arrowSprites[i])
            DestroySprite(gUnknown_02039D04->arrowSprites[i]);
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
    u8 numBoxMonsText[16];
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
    FillWindowPixelBuffer(windowId, PIXEL_FILL(4));

    center = GetStringCenterAlignXOffset(1, boxName, 64);
    AddTextPrinterParameterized3(windowId, 1, center, 1, sBoxInfoTextColors, TEXT_SPEED_FF, boxName);

    ConvertIntToDecimalStringN(numBoxMonsText, nPokemonInBox, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringAppend(numBoxMonsText, sText_OutOf30);
    center = GetStringCenterAlignXOffset(1, numBoxMonsText, 64);
    AddTextPrinterParameterized3(windowId, 1, center, 17, sBoxInfoTextColors, TEXT_SPEED_FF, numBoxMonsText);

    winTileData = GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    CpuCopy32((void *)winTileData, (void *)OBJ_VRAM0 + 0x100 + (GetSpriteTileStartByTag(gUnknown_02039D04->unk_0240) * 32), 0x400);

    RemoveWindow(windowId);
}

static void SpriteCB_JumpBoxArrow(struct Sprite *sprite)
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

static void VblankCb_PSS(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    sub_80D2AA4();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG2HOFS, sPSSData->bg2_X);
}

static void Cb2_PSS(void)
{
    RunTasks();
    DoScheduledBgTilemapCopiesToVram();
    ScrollBackground();
    sub_80CAA14();
    AnimateSprites();
    BuildOamBuffer();
}

static void Cb2_EnterPSS(u8 boxOption)
{
    ResetTasks();
    sCurrentBoxOption = boxOption;
    sPSSData = Alloc(sizeof(*sPSSData));
    if (sPSSData == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        sPSSData->boxOption = boxOption;
        sPSSData->isReshowingPSS = FALSE;
        sMovingItemId = ITEM_NONE;
        sPSSData->state = 0;
        sPSSData->taskId = CreateTask(Cb_InitPSS, 3);
        sLastUsedBox = StorageGetCurrentBox();
        SetMainCallback2(Cb2_PSS);
    }
}

static void Cb2_ReturnToPSS(void)
{
    ResetTasks();
    sPSSData = Alloc(sizeof(*sPSSData));
    if (sPSSData == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        sPSSData->boxOption = sCurrentBoxOption;
        sPSSData->isReshowingPSS = TRUE;
        sPSSData->state = 0;
        sPSSData->taskId = CreateTask(Cb_InitPSS, 3);
        SetMainCallback2(Cb2_PSS);
    }
}

static void ResetAllBgCoords(void)
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
    sub_80D2A90(&sPSSData->unk_0020, sPSSData->unk_0028, 8);
    gKeyRepeatStartDelay = 20;
    ClearScheduledBgCopiesToVram();
    sub_80D259C(3);
    sub_80D2644(0, 1, gUnknown_0857239C, 8, 4);
    sub_80D2770(0, 1, 0);
    sPSSData->unk_02C7 = 0;
}

static void sub_80C7F1C(void)
{
    sub_80CDC0C();
    sInPartyMenu = (sPSSData->boxOption == BOX_OPTION_DEPOSIT);
    gUnknown_02039D0E = 0;
}

static void SetMonIconTransparency(void)
{
    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));
    }
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
}

static void SetPSSCallback(TaskFunc newFunc)
{
    gTasks[sPSSData->taskId].func = newFunc;
    sPSSData->state = 0;
}

static void Cb_InitPSS(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        sub_80C7E98();
        if (sPSSData->isReshowingPSS)
        {
            switch (sWhichToReshow)
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
        if (!sPSSData->isReshowingPSS)
            sub_80C7F1C();
        break;
    case 4:
        sub_80CAF04();
        if (!sPSSData->isReshowingPSS)
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
        CreateInitBoxTask(StorageGetCurrentBox());
        break;
    case 9:
        if (IsInitBoxActive())
            return;

        if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        {
            sPSSData->markMenu.baseTileTag = TAG_TILE_D;
            sPSSData->markMenu.basePaletteTag = TAG_PAL_DACE;
            InitMonMarkingsMenu(&sPSSData->markMenu);
            BufferMonMarkingsMenuTiles();
        }
        else
        {
            sub_80D0C60();
            sub_80CAEAC();
        }
        break;
    case 10:
        SetMonIconTransparency();
        if (!sPSSData->isReshowingPSS)
        {
            BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
            SetPSSCallback(Cb_ShowPSS);
        }
        else
        {
            BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
            SetPSSCallback(Cb_ReshowPSS);
        }
        SetVBlankCallback(VblankCb_PSS);
        return;
    default:
        return;
    }

    sPSSData->state++;
}

static void Cb_ShowPSS(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PlaySE(SE_PC_LOGIN);
        ComputerScreenOpenEffect(20, 0, 1);
        sPSSData->state++;
        break;
    case 1:
        if (!IsComputerScreenOpenEffectActive())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

static void Cb_ReshowPSS(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0x10, 0, RGB_BLACK);
        sPSSData->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            if (sWhichToReshow == 2 && gSpecialVar_ItemId != 0)
            {
                PrintMessage(MSG_ITEM_IS_HELD);
                sPSSData->state++;
            }
            else
            {
                SetPSSCallback(Cb_MainPSS);
            }
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy() && JOY_NEW(A_BUTTON | B_BUTTON))
        {
            ClearBottomWindow();
            sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        switch (HandleInput())
        {
        case 1:
            PlaySE(SE_SELECT);
            sPSSData->state = 1;
            break;
        case 5:
            if (sPSSData->boxOption != BOX_OPTION_MOVE_MONS && sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                PrintMessage(MSG_WHICH_ONE_WILL_TAKE);
                sPSSData->state = 3;
            }
            else
            {
                sub_80CDC0C();
                SetPSSCallback(Cb_ShowPartyPokemon);
            }
            break;
        case 6:
            if (sPSSData->boxOption == BOX_OPTION_MOVE_MONS)
            {
                if (IsMonBeingMoved() && ItemIsMail(sPSSData->cursorMonItem))
                    sPSSData->state = 5;
                else
                    SetPSSCallback(Cb_HidePartyPokemon);
            }
            else if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
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
            sPSSData->newCurrBoxId = StorageGetCurrentBox() + 1;
            if (sPSSData->newCurrBoxId >= TOTAL_BOXES_COUNT)
                sPSSData->newCurrBoxId = 0;
            if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sPSSData->newCurrBoxId);
                sPSSData->state = 2;
            }
            else
            {
                sub_80CFEA8();
                sPSSData->state = 10;
            }
            break;
        case 10:
            PlaySE(SE_SELECT);
            sPSSData->newCurrBoxId = StorageGetCurrentBox() - 1;
            if (sPSSData->newCurrBoxId < 0)
                sPSSData->newCurrBoxId = TOTAL_BOXES_COUNT - 1;
            if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sPSSData->newCurrBoxId);
                sPSSData->state = 2;
            }
            else
            {
                sub_80CFEA8();
                sPSSData->state = 10;
            }
            break;
        case 11:
            if (!CanMovePartyMon())
            {
                if (ItemIsMail(sPSSData->cursorMonItem))
                {
                    sPSSData->state = 5;
                }
                else
                {
                    PlaySE(SE_SELECT);
                    SetPSSCallback(Cb_DepositMenu);
                }
            }
            else
            {
                sPSSData->state = 4;
            }
            break;
        case 13:
            if (CanMovePartyMon())
            {
                sPSSData->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case 14:
            if (!CanShiftMon())
            {
                sPSSData->state = 4;
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
            sPSSData->state = 7;
            break;
        case 22:
            sub_80D01D0(1);
            sPSSData->state = 8;
            break;
        case 21:
            PlaySE(SE_SELECT);
            sub_80D01D0(2);
            sPSSData->state = 9;
            break;
        case 23:
            sub_80D01D0(3);
            sPSSData->state = 7;
            break;
        case 25:
            PlaySE(SE_SELECT);
            sub_80D01D0(4);
            sPSSData->state = 9;
            break;
        case 26:
            PlaySE(SE_SELECT);
            sub_80D01D0(5);
            sPSSData->state = 7;
            break;
        case 24:
            PlaySE(SE_FAILURE);
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

            if (sPSSData->setMosaic)
                BoxSetMosaic();
            sPSSData->state = 0;
        }
        break;
    case 2:
        if (!ScrollToBox())
        {
            SetCurrentBox(sPSSData->newCurrBoxId);
            if (!sInPartyMenu && !IsMonBeingMoved())
            {
                sub_80CE00C();
                BoxSetMosaic();
            }

            if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
            {
                sub_80CFECC();
                sPSSData->state = 11;
            }
            else
            {
                sPSSData->state = 0;
            }
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sPSSData->state = 0;
        }
        break;
    case 4:
        PlaySE(SE_FAILURE);
        PrintMessage(MSG_LAST_POKE);
        sPSSData->state = 6;
        break;
    case 5:
        PlaySE(SE_FAILURE);
        PrintMessage(MSG_PLEASE_REMOVE_MAIL);
        sPSSData->state = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 7:
        if (!sub_80D01E4())
            sPSSData->state = 0;
        break;
    case 8:
        if (!sub_80D01E4())
            SetPSSCallback(Cb_MoveMon);
        break;
    case 9:
        if (!sub_80D01E4())
        {
            if (sPSSData->setMosaic)
                BoxSetMosaic();
            sPSSData->state = 0;
        }
        break;
    case 10:
        if (!sub_80D1218())
        {
            SetUpScrollToBox(sPSSData->newCurrBoxId);
            sPSSData->state = 2;
        }
        break;
    case 11:
        if (!sub_80D1218())
            sPSSData->state = 0;
        break;
    }
}

static void Cb_ShowPartyPokemon(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        SetUpDoShowPartyMenu();
        sPSSData->state++;
        break;
    case 1:
        if (!DoShowPartyMenu())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

static void Cb_HidePartyPokemon(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        SetUpHidePartyMenu();
        sPSSData->state++;
        break;
    case 1:
        if (!HidePartyMenu())
        {
            sub_80CDBF8(sub_80CDC2C());
            sPSSData->state++;
        }
        break;
    case 2:
        if (!sub_80CD554())
        {
            if (sPSSData->setMosaic)
                BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_OnSelectedMon(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        if (!sub_80CA2B8())
        {
            PlaySE(SE_SELECT);
            if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
                PrintMessage(MSG_IS_SELECTED);
            else if (IsActiveItemMoving() || sPSSData->cursorMonItem != 0)
                PrintMessage(MSG_IS_SELECTED2);
            else
                PrintMessage(MSG_GIVE_TO_MON);

            AddMenu();
            sPSSData->state = 1;
        }
        break;
    case 1:
        if (!IsMenuLoading())
            sPSSData->state = 2;
        break;
    case 2:
        switch (HandleMenuInput())
        {
        case MENU_B_PRESSED:
        case MENU_CANCEL:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case MENU_MOVE:
            if (CanMovePartyMon())
            {
                sPSSData->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case MENU_PLACE:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_PlaceMon);
            break;
        case MENU_SHIFT:
            if (!CanShiftMon())
            {
                sPSSData->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_ShiftMon);
            }
            break;
        case MENU_WITHDRAW:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_WithdrawMon);
            break;
        case MENU_STORE:
            if (CanMovePartyMon())
            {
                sPSSData->state = 3;
            }
            else if (ItemIsMail(sPSSData->cursorMonItem))
            {
                sPSSData->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPSSCallback(Cb_DepositMenu);
            }
            break;
        case MENU_RELEASE:
            if (CanMovePartyMon())
            {
                sPSSData->state = 3;
            }
            else if (sPSSData->cursorMonIsEgg)
            {
                sPSSData->state = 5; // Cannot release an Egg.
            }
            else if (ItemIsMail(sPSSData->cursorMonItem))
            {
                sPSSData->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_ReleaseMon);
            }
            break;
        case MENU_SUMMARY:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_ShowMonSummary);
            break;
        case MENU_MARK:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_ShowMarkMenu);
            break;
        case MENU_TAKE:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_TakeItemForMoving);
            break;
        case MENU_GIVE:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveMovingItemToMon);
            break;
        case MENU_BAG:
            SetPSSCallback(Cb_ItemToBag);
            break;
        case MENU_SWITCH:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_SwitchSelectedItem);
            break;
        case MENU_GIVE_2:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveItemFromBag);
            break;
        case MENU_INFO:
            SetPSSCallback(Cb_ShowItemInfo);
            break;
        }
        break;
    case 3:
        PlaySE(SE_FAILURE);
        PrintMessage(MSG_LAST_POKE);
        sPSSData->state = 6;
        break;
    case 5:
        PlaySE(SE_FAILURE);
        PrintMessage(MSG_CANT_RELEASE_EGG);
        sPSSData->state = 6;
        break;
    case 4:
        PlaySE(SE_FAILURE);
        PrintMessage(MSG_PLEASE_REMOVE_MAIL);
        sPSSData->state = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_MoveMon(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        InitMonPlaceChange(0);
        sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        InitMonPlaceChange(1);
        sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        InitMonPlaceChange(2);
        sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
        {
            PrintMessage(MSG_PARTY_FULL);
            sPSSData->state = 1;
        }
        else
        {
            sub_80CDC18();
            InitMonPlaceChange(0);
            sPSSData->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
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
            sPSSData->state++;
        }
        break;
    case 3:
        if (!DoShowPartyMenu())
        {
            InitMonPlaceChange(1);
            sPSSData->state++;
        }
        break;
    case 4:
        if (!DoMonPlaceChange())
        {
            sub_80CAB20();
            sPSSData->state++;
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

    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_DEPOSIT_IN_WHICH_BOX);
        sub_80C77E8(&sPSSData->field_1E5C, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(gUnknown_02039D0E);
        sPSSData->state++;
        break;
    case 1:
        boxId = HandleBoxChooseSelectionInput();
        if (boxId == 200)
        {
            // no box chosen yet
        }
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
                sPSSData->state = 2;
            }
            else
            {
                PrintMessage(MSG_BOX_IS_FULL);
                sPSSData->state = 4;
            }
        }
        break;
    case 2:
        CompactPartySlots();
        sub_80CB950();
        sPSSData->state++;
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
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(MSG_DEPOSIT_IN_WHICH_BOX);
            sPSSData->state = 1;
        }
        break;
    }
}

static void Cb_ReleaseMon(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_RELEASE_POKE);
        ShowYesNoWindow(1);
        sPSSData->state++;
        // fallthrough
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case  1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case  0:
            ClearBottomWindow();
            InitCanRelaseMonVars();
            sub_80CE250();
            sPSSData->state++;
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
                    sPSSData->state++;
                    break;
                }
                else if (r0 == 0)
                {
                    sPSSData->state = 8; // Can't release the mon.
                    break;
                }
            }
        }
        break;
    case 3:
        ReleaseMon();
        RefreshCursorMonData();
        PrintMessage(MSG_WAS_RELEASED);
        sPSSData->state++;
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(MSG_BYE_BYE);
            sPSSData->state++;
        }
        break;
    case 5:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            if (sInPartyMenu)
            {
                CompactPartySlots();
                sub_80CB950();
                sPSSData->state++;
            }
            else
            {
                sPSSData->state = 7;
            }
        }
        break;
    case 6:
        if (!sub_80CB9BC())
        {
            sub_80CE00C();
            BoxSetMosaic();
            sub_80CAB20();
            sPSSData->state++;
        }
        break;
    case 7:
        SetPSSCallback(Cb_MainPSS);
        break;
    case 8:
        PrintMessage(MSG_WAS_RELEASED);
        sPSSData->state++;
        break;
    case 9:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(MSG_SURPRISE);
            sPSSData->state++;
        }
        break;
    case 10:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_80CC064();
            sPSSData->state++;
        }
        break;
    case 11:
        if (!sub_80CC0A0())
        {
            sub_80CE324();
            PrintMessage(MSG_CAME_BACK);
            sPSSData->state++;
        }
        break;
    case 12:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(MSG_WORRIED);
            sPSSData->state++;
        }
        break;
    case 13:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_ShowMarkMenu(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_MARK_POKE);
        sPSSData->markMenu.markings = sPSSData->cursorMonMarkings;
        OpenMonMarkingsMenu(sPSSData->cursorMonMarkings, 0xb0, 0x10);
        sPSSData->state++;
        break;
    case 1:
        if (!HandleMonMarkingsMenuInput())
        {
            FreeMonMarkingsMenu();
            ClearBottomWindow();
            SetMonMarkings(sPSSData->markMenu.markings);
            RefreshCursorMonData();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_TakeItemForMoving(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        if (!ItemIsMail(sPSSData->cursorMonItem))
        {
            ClearBottomWindow();
            sPSSData->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        Item_FromMonToMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sPSSData->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            ClearBottomWindow();
            sub_80CE00C();
            PrintCursorMonInfo();
            sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        ClearBottomWindow();
        sPSSData->state++;
        break;
    case 1:
        sub_80CFE54(2);
        Item_GiveMovingToMon((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sPSSData->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            sub_80CE00C();
            PrintCursorMonInfo();
            PrintMessage(MSG_ITEM_IS_HELD);
            sPSSData->state++;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        if (!AddBagItem(sPSSData->cursorMonItem, 1))
        {
            PlaySE(SE_FAILURE);
            PrintMessage(MSG_BAG_FULL);
            sPSSData->state = 3;
        }
        else
        {
            PlaySE(SE_SELECT);
            Item_TakeMons((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
            sPSSData->state = 1;
        }
        break;
    case 1:
        if (!sub_80D1218())
        {
            PrintMessage(MSG_PLACED_IN_BAG);
            sPSSData->state = 2;
        }
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_80CE00C();
            PrintCursorMonInfo();
            sPSSData->state = 4;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_SwitchSelectedItem(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        if (!ItemIsMail(sPSSData->cursorMonItem))
        {
            ClearBottomWindow();
            sPSSData->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        Item_SwitchMonsWithMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sPSSData->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            sub_80CE00C();
            PrintCursorMonInfo();
            PrintMessage(MSG_CHANGED_TO_ITEM);
            sPSSData->state++;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        ClearBottomWindow();
        sPSSData->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_WIN_OPEN);
            PrintItemDescription();
            sub_80D1818();
            sPSSData->state++;
        }
        break;
    case 2:
        if (!sub_80D184C())
            sPSSData->state++;
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPSSData->state++;
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PlaySE(SE_WIN_OPEN);
            sPSSData->state++;
        }
        break;
    case 5:
        if (!sub_80D18E4())
            sPSSData->state++;
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

static void Cb_CloseBoxWhileHoldingItem(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintMessage(MSG_PUT_IN_BAG);
        ShowYesNoWindow(0);
        sPSSData->state = 1;
        break;
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            if (AddBagItem(sPSSData->movingItem, 1) == TRUE)
            {
                ClearBottomWindow();
                sPSSData->state = 3;
            }
            else
            {
                PrintMessage(MSG_BAG_FULL);
                sPSSData->state = 2;
            }
            break;
        }
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sPSSData->state = 5;
        }
        break;
    case 3:
        sub_80D1194();
        sPSSData->state = 4;
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
    switch (sPSSData->state)
    {
    case 0:
        CompactPartySlots();
        sub_80CB950();
        sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_CANT_STORE_MAIL);
        sPSSData->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPSSData->state++;
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sPSSData->state++;
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
    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_WHAT_YOU_DO);
        AddMenu();
        sPSSData->state++;
        break;
    case 1:
        if (IsMenuLoading())
            return;
        sPSSData->state++;
    case 2:
        switch (HandleMenuInput())
        {
        case MENU_B_PRESSED:
        case MENU_CANCEL:
            AnimateBoxScrollArrows(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case MENU_NAME:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_NameBox);
            break;
        case MENU_WALLPAPER:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_HandleWallpapers);
            break;
        case MENU_JUMP:
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
    switch (sPSSData->state)
    {
    case 0:
        AddWallpaperSetsMenu();
        PrintMessage(MSG_PICK_A_THEME);
        sPSSData->state++;
        break;
    case 1:
        if (!IsMenuLoading())
             sPSSData->state++;
        break;
    case 2:
        sPSSData->wallpaperSetId = HandleMenuInput();
        switch (sPSSData->wallpaperSetId)
        {
        case MENU_B_PRESSED:
            AnimateBoxScrollArrows(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case MENU_SCENERY_1:
        case MENU_SCENERY_2:
        case MENU_SCENERY_3:
        case MENU_ETCETERA:
            PlaySE(SE_SELECT);
            RemoveMenu();
            sPSSData->wallpaperSetId -= MENU_WALLPAPER_SETS_START;
            sPSSData->state++;
            break;
        case MENU_FRIENDS:
            // New wallpaper from Walda.
            PlaySE(SE_SELECT);
            sPSSData->wallpaperId = WALLPAPER_FRIENDS;
            RemoveMenu();
            ClearBottomWindow();
            sPSSData->state = 6;
            break;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            AddWallpapersMenu(sPSSData->wallpaperSetId);
            PrintMessage(MSG_PICK_A_WALLPAPER);
            sPSSData->state++;
        }
        break;
    case 4:
        sPSSData->wallpaperId = HandleMenuInput();
        switch (sPSSData->wallpaperId)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            ClearBottomWindow();
            sPSSData->state = 0;
            break;
        default:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            sPSSData->wallpaperId -= MENU_WALLPAPERS_START;
            SetWallpaperForCurrentBox(sPSSData->wallpaperId);
            sPSSData->state++;
            break;
        }
        break;
    case 5:
        if (!DoWallpaperGfxChange())
        {
            AnimateBoxScrollArrows(TRUE);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetWallpaperForCurrentBox(sPSSData->wallpaperId);
            sPSSData->state = 5;
        }
        break;
    }
}

static void Cb_JumpBox(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        PrintMessage(MSG_JUMP_TO_WHICH_BOX);
        sub_80C77E8(&sPSSData->field_1E5C, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(StorageGetCurrentBox());
        sPSSData->state++;
        break;
    case 1:
        sPSSData->newCurrBoxId = HandleBoxChooseSelectionInput();
        switch (sPSSData->newCurrBoxId)
        {
        case 200:
            break;
        default:
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            if (sPSSData->newCurrBoxId == 201 || sPSSData->newCurrBoxId == StorageGetCurrentBox())
            {
                AnimateBoxScrollArrows(TRUE);
                SetPSSCallback(Cb_MainPSS);
            }
            else
            {
                sPSSData->state++;
            }
            break;
        }
        break;
    case 2:
        SetUpScrollToBox(sPSSData->newCurrBoxId);
        sPSSData->state++;
        break;
    case 3:
        if (!ScrollToBox())
        {
            SetCurrentBox(sPSSData->newCurrBoxId);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

static void Cb_NameBox(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        sub_80CE760();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sPSSData->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 1;
            sPSSData->screenChangeType = SCREEN_CHANGE_NAME_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_ShowMonSummary(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        sub_80CE7E8();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sPSSData->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 0;
            sPSSData->screenChangeType = SCREEN_CHANGE_SUMMARY_SCREEN;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_GiveItemFromBag(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sPSSData->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 2;
            sPSSData->screenChangeType = SCREEN_CHANGE_ITEM_FROM_BAG;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_OnCloseBoxPressed(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintMessage(MSG_HOLDING_POKE);
            sPSSData->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintMessage(MSG_EXIT_BOX);
            ShowYesNoWindow(0);
            sPSSData->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sPSSData->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 1);
        sPSSData->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            sub_80CABE0();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sPSSData->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_OnBPressed(u8 taskId)
{
    switch (sPSSData->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintMessage(MSG_HOLDING_POKE);
            sPSSData->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintMessage(MSG_CONTINUE_BOX);
            ShowYesNoWindow(0);
            sPSSData->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
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
        case MENU_B_PRESSED:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sPSSData->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 0);
        sPSSData->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            sub_80CABE0();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sPSSData->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPSSCallback(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_ChangeScreen(u8 taskId)
{
    struct BoxPokemon *boxMons;
    u8 mode, monIndex, maxMonIndex;
    u8 screenChangeType = sPSSData->screenChangeType;

    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS && IsActiveItemMoving() == TRUE)
        sMovingItemId = GetMovingItem();
    else
        sMovingItemId = ITEM_NONE;

    switch (screenChangeType)
    {
    case SCREEN_CHANGE_EXIT_BOX:
    default:
        FreePSSData();
        SetMainCallback2(Cb2_ExitPSS);
        break;
    case SCREEN_CHANGE_SUMMARY_SCREEN:
        boxMons = sPSSData->field_218C.box;
        monIndex = sPSSData->field_2187;
        maxMonIndex = sPSSData->field_2186;
        mode = sPSSData->pokemonSummaryScreenMode;
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
        GoToBagMenu(ITEMMENULOCATION_PCBOX, 0, Cb2_ReturnToPSS);
        break;
    }

    DestroyTask(taskId);
}

static void GiveChosenBagItem(void)
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

static void FreePSSData(void)
{
    sub_80D25F0();
    sub_80D01B8();
    FREE_AND_SET_NULL(sPSSData);
    FreeAllWindowBuffers();
}

static void SetScrollingBackground(void)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(31));
    DecompressAndLoadBgGfxUsingHeap(3, gPokemonStorageScrollingBGTileset, 0, 0, 0);
    LZ77UnCompVram(gPokemonStorageScrollingBGTilemap, (void *)BG_SCREEN_ADDR(31));
}

static void ScrollBackground(void)
{
    ChangeBgX(3, 128, 1);
    ChangeBgY(3, 128, 2);
}

static void LoadPSSMenuGfx(void)
{
    InitBgsFromTemplates(0, gUnknown_08572734, ARRAY_COUNT(gUnknown_08572734));
    DecompressAndLoadBgGfxUsingHeap(1, gPSSMenu_Gfx, 0, 0, 0);
    LZ77UnCompWram(gUnknown_085722A0, sPSSData->field_5AC4);
    SetBgTilemapBuffer(1, sPSSData->field_5AC4);
    ShowBg(1);
    ScheduleBgCopyTilemapToVram(1);
}

static bool8 InitPSSWindows(void)
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

static void LoadWaveformSpritePalette(void)
{
    LoadSpritePalette(&gWaveformSpritePalette);
}

static void sub_80CA0D8(void)
{
    LoadPalette(gUnknown_085723DC, 0, 0x20);
    LoadPalette(gUnknown_085723FC, 0x20, 0x20);
    LoadPalette(gUnknown_085726F4, 0xF0, 0x20);
    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
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
    sPSSData->field_D94 = CreateMonMarkingComboSprite(TAG_TILE_10, TAG_PAL_DAC8, NULL);
    sPSSData->field_D94->oam.priority = 1;
    sPSSData->field_D94->subpriority = 1;
    sPSSData->field_D94->pos1.x = 40;
    sPSSData->field_D94->pos1.y = 150;
    sPSSData->field_DA0 = (void*) OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_TILE_10);
}

static void sub_80CA1C4(void)
{
    u16 i;
    struct SpriteSheet sheet = gWaveformSpriteSheet;

    LoadSpriteSheet(&sheet);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_Waveform, i * 63 + 8, 9, 2);
        sPSSData->field_D98[i] = &gSprites[spriteId];
    }
}

static void RefreshCursorMonData(void)
{
    LoadCursorMonGfx(sPSSData->cursorMonSpecies, sPSSData->cursorMonPersonality);
    PrintCursorMonInfo();
    sub_80CA65C();
    ScheduleBgCopyTilemapToVram(0);
}

static void BoxSetMosaic(void)
{
    RefreshCursorMonData();
    if (sPSSData->cursorMonSprite)
    {
        sPSSData->cursorMonSprite->oam.mosaic = TRUE;
        sPSSData->cursorMonSprite->data[0] = 10;
        sPSSData->cursorMonSprite->data[1] = 1;
        sPSSData->cursorMonSprite->callback = sub_80CA2D0;
        SetGpuReg(REG_OFFSET_MOSAIC, (sPSSData->cursorMonSprite->data[0] << 12) | (sPSSData->cursorMonSprite->data[0] << 8));
    }
}

static u8 sub_80CA2B8(void)
{
    return sPSSData->cursorMonSprite->oam.mosaic;
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

static void LoadCursorMonSprite(void)
{
    u16 i;
    u16 tileStart;
    u8 palSlot;
    u8 spriteId;
    struct SpriteSheet sheet = {sPSSData->field_22C4, MON_PIC_SIZE, TAG_TILE_2};
    struct SpritePalette palette = {sPSSData->field_2244, TAG_PAL_DAC6};
    struct SpriteTemplate template = sSpriteTemplate_CursorMon;

    for (i = 0; i < MON_PIC_SIZE; i++)
        sPSSData->field_22C4[i] = 0;
    for (i = 0; i < 0x10; i++)
        sPSSData->field_2244[i] = 0;

    sPSSData->cursorMonSprite = NULL;

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

        sPSSData->cursorMonSprite = &gSprites[spriteId];
        sPSSData->field_223A = palSlot * 16 + 0x100;
        sPSSData->field_223C = (void*) OBJ_VRAM0 + tileStart * 32;
    } while (0);

    if (sPSSData->cursorMonSprite == NULL)
    {
        FreeSpriteTilesByTag(TAG_TILE_2);
        FreeSpritePaletteByTag(TAG_PAL_DAC6);
    }
}

static void LoadCursorMonGfx(u16 species, u32 pid)
{
    if (sPSSData->cursorMonSprite == NULL)
        return;

    if (species != SPECIES_NONE)
    {
        LoadSpecialPokePic(&gMonFrontPicTable[species], sPSSData->field_22C4, species, pid, TRUE);
        LZ77UnCompWram(sPSSData->cursorMonPalette, sPSSData->field_2244);
        CpuCopy32(sPSSData->field_22C4, sPSSData->field_223C, MON_PIC_SIZE);
        LoadPalette(sPSSData->field_2244, sPSSData->field_223A, 0x20);
        sPSSData->cursorMonSprite->invisible = FALSE;
    }
    else
    {
        sPSSData->cursorMonSprite->invisible = TRUE;
    }
}

static void PrintCursorMonInfo(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        AddTextPrinterParameterized(0, 1, sPSSData->cursorMonNickText, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sPSSData->cursorMonSpeciesName, 6, 15, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sPSSData->cursorMonGenderLvlText, 10, 29, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 0, sPSSData->cursorMonItemName, 6, 43, TEXT_SPEED_FF, NULL);
    }
    else
    {
        AddTextPrinterParameterized(0, 0, sPSSData->cursorMonItemName, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 1, sPSSData->cursorMonNickText, 6, 13, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sPSSData->cursorMonSpeciesName, 6, 28, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sPSSData->cursorMonGenderLvlText, 10, 42, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(0, 2);
    if (sPSSData->cursorMonSpecies != SPECIES_NONE)
    {
        UpdateMonMarkingTiles(sPSSData->cursorMonMarkings, sPSSData->field_DA0);
        sPSSData->field_D94->invisible = FALSE;
    }
    else
    {
        sPSSData->field_D94->invisible = TRUE;
    }
}

static void sub_80CA65C(void)
{
    u16 i;

    if (sPSSData->cursorMonSpecies != SPECIES_NONE)
    {
        sub_80D27AC(0, 0, 0, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnimIfDifferent(sPSSData->field_D98[i], i * 2 + 1);
    }
    else
    {
        sub_80D27AC(0, 0, 2, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnim(sPSSData->field_D98[i], i * 2);
    }

    sub_80D2918(0);
    ScheduleBgCopyTilemapToVram(1);
}

static void sub_80CA704(void)
{
    LZ77UnCompWram(gUnknown_08DD36C8, sPSSData->field_B0);
    LoadPalette(gPSSMenu_Pal, 0x10, 0x20);
    sub_80D2644(1, 1, sPSSData->field_B0, 12, 22);
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

    ScheduleBgCopyTilemapToVram(1);
    sPSSData->unk_02C7 = 0;
}

static void SetUpShowPartyMenu(void)
{
    sPSSData->field_2C0 = 20;
    sPSSData->field_2C2 = 2;
    sPSSData->field_2C5 = 0;
    CreatePartyMonsSprites(FALSE);
}

static bool8 ShowPartyMenu(void)
{
    if (sPSSData->field_2C5 == 20)
        return FALSE;

    sPSSData->field_2C0--;
    sPSSData->field_2C2++;
    sub_80D27F4(1, 3, 1);
    sub_80D2918(1);
    ScheduleBgCopyTilemapToVram(1);
    sub_80CBAF0(8);
    if (++sPSSData->field_2C5 == 20)
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
    sPSSData->field_2C0 = 0;
    sPSSData->field_2C2 = 22;
    sPSSData->field_2C5 = 0;
    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
        sub_80D11CC();
}

static bool8 HidePartyMenu(void)
{
    if (sPSSData->field_2C5 != 20)
    {
        sPSSData->field_2C0++;
        sPSSData->field_2C2--;
        sub_80D27F4(1, 3, -1);
        sub_80D2918(1);
        FillBgTilemapBufferRect_Palette0(1, 0x100, 10, sPSSData->field_2C2, 12, 1);
        sub_80CBAF0(-8);
        if (++sPSSData->field_2C5 != 20)
        {
            ScheduleBgCopyTilemapToVram(1);
            return TRUE;
        }
        else
        {
            sInPartyMenu = FALSE;
            DestroyAllPartyMonIcons();
            CompactPartySlots();
            sub_80D27AC(2, 0, 0, 9, 2);
            sub_80D2918(2);
            ScheduleBgCopyTilemapToVram(1);
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
    ScheduleBgCopyTilemapToVram(1);
}

static void sub_80CA9C0(void)
{
    sPSSData->unk_02C7 = 1;
    sPSSData->unk_02C8 = 30;
    sPSSData->unk_02C9 = TRUE;
}

static void sub_80CA9EC(void)
{
    if (sPSSData->unk_02C7)
    {
        sPSSData->unk_02C7 = 0;
        sub_80CA984(TRUE);
    }
}

static void sub_80CAA14(void)
{
    if (sPSSData->unk_02C7 && ++sPSSData->unk_02C8 > 30)
    {
        sPSSData->unk_02C8 = 0;
        sPSSData->unk_02C9 = (sPSSData->unk_02C9 == FALSE);
        sub_80CA984(sPSSData->unk_02C9);
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
            sPSSData->field_B0[index + j] = data[j];
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
    ScheduleBgCopyTilemapToVram(1);
}

static void SetUpDoShowPartyMenu(void)
{
    sPSSData->showPartyMenuState = 0;
    PlaySE(SE_WIN_OPEN);
    SetUpShowPartyMenu();
}

static bool8 DoShowPartyMenu(void)
{
    switch (sPSSData->showPartyMenuState)
    {
    case 0:
        if (!ShowPartyMenu())
        {
            sub_80CDBA0();
            sPSSData->showPartyMenuState++;
        }
        break;
    case 1:
        if (!sub_80CD554())
        {
            if (sPSSData->setMosaic)
                BoxSetMosaic();
            sPSSData->showPartyMenuState++;
        }
        break;
    case 2:
        return FALSE;
    }
    return TRUE;
}

static void sub_80CABE0(void)
{
    if (sLastUsedBox != StorageGetCurrentBox())
    {
        FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
        VarSet(VAR_PC_BOX_TO_SEND_MON, StorageGetCurrentBox());
    }
}

static void sub_80CAC1C(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(29));
    LoadUserWindowBorderGfx(1, 2, 208);
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 17);
    CopyBgTilemapBufferToVram(0);
}

static void PrintMessage(u8 id)
{
    u8 *txtPtr;

    DynamicPlaceholderTextUtil_Reset();
    switch (sMessages[id].format)
    {
    case MSG_FORMAT_NORMAL:
        break;
    case MSG_FORMAT_MON_NAME_1:
    case MSG_FORMAT_MON_NAME_2:
    case MSG_FORMAT_MON_NAME_3:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPSSData->cursorMonNick);
        break;
    case MSG_FORMAT_MON_NAME_4:
    case MSG_FORMAT_MON_NAME_5:
    case MSG_FORMAT_MON_NAME_6:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPSSData->field_21E0);
        break;
    case MSG_FORMAT_ITEM_NAME:
        if (IsActiveItemMoving())
            txtPtr = StringCopy(sPSSData->itemName, GetMovingItemName());
        else
            txtPtr = StringCopy(sPSSData->itemName, sPSSData->cursorMonItemName);

        while (*(txtPtr - 1) == CHAR_SPACE)
            txtPtr--;

        *txtPtr = EOS;
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPSSData->itemName);
        break;
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPSSData->field_2190, sMessages[id].text);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    AddTextPrinterParameterized(1, 1, sPSSData->field_2190, 0, 1, TEXT_SPEED_FF, NULL);
    DrawTextBorderOuter(1, 2, 14);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
    ScheduleBgCopyTilemapToVram(0);
}

static void ShowYesNoWindow(s8 cursorPos)
{
    CreateYesNoMenu(&sYesNoWindowTemplate, 11, 14, 0);
    Menu_MoveCursorNoWrapAround(cursorPos);
}

static void ClearBottomWindow(void)
{
    ClearStdWindowAndFrameToTransparent(1, FALSE);
    ScheduleBgCopyTilemapToVram(0);
}

static void AddWallpaperSetsMenu(void)
{
    InitMenu();
    SetMenuText(MENU_SCENERY_1);
    SetMenuText(MENU_SCENERY_2);
    SetMenuText(MENU_SCENERY_3);
    SetMenuText(MENU_ETCETERA);
    if (IsWaldaWallpaperUnlocked())
        SetMenuText(MENU_FRIENDS);
    AddMenu();
}

static void AddWallpapersMenu(u8 wallpaperSet)
{
    InitMenu();
    switch (wallpaperSet)
    {
    case MENU_SCENERY_1 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_FOREST);
        SetMenuText(MENU_CITY);
        SetMenuText(MENU_DESERT);
        SetMenuText(MENU_SAVANNA);
        break;
    case MENU_SCENERY_2 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_CRAG);
        SetMenuText(MENU_VOLCANO);
        SetMenuText(MENU_SNOW);
        SetMenuText(MENU_CAVE);
        break;
    case MENU_SCENERY_3 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_BEACH);
        SetMenuText(MENU_SEAFLOOR);
        SetMenuText(MENU_RIVER);
        SetMenuText(MENU_SKY);
        break;
    case MENU_ETCETERA - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_POLKADOT);
        SetMenuText(MENU_POKECENTER);
        SetMenuText(MENU_MACHINE);
        SetMenuText(MENU_SIMPLE);
        break;
    }
    AddMenu();
}

static u8 GetCurrentBoxOption(void)
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

    if (sMovingItemId != ITEM_NONE)
    {
        sub_80D0F38(sMovingItemId);
        sub_80CFE54(3);
    }
}

static void sub_80CAF04(void)
{
    u16 i;

    LoadMonIconPalettes();
    for (i = 0; i < 40; i++)
        sPSSData->field_B08[i] = 0;
    for (i = 0; i < 40; i++)
        sPSSData->field_B58[i] = 0;
    for (i = 0; i < PARTY_SIZE; i++)
        sPSSData->partySprites[i] = NULL;
    for (i = 0; i < IN_BOX_COUNT; i++)
        sPSSData->boxMonsSprites[i] = NULL;

    sPSSData->movingMonSprite = NULL;
    sPSSData->field_78C = 0;
}

static u8 sub_80CAFAC(void)
{
    return (IsCursorInBox() ? 2 : 1);
}

static void CreateMovingMonIcon(void)
{
    u32 personality = GetMonData(&sPSSData->movingMon, MON_DATA_PERSONALITY);
    u16 species = GetMonData(&sPSSData->movingMon, MON_DATA_SPECIES2);
    u8 priority = sub_80CAFAC();

    sPSSData->movingMonSprite = CreateMonIconSprite(species, personality, 0, 0, priority, 7);
    sPSSData->movingMonSprite->callback = sub_80CC100;
}

static void InitBoxMonSprites(u8 boxId)
{
    u8 boxPosition;
    u16 i, j, count;
    u16 species;
    u32 personality;

    count = 0;
    boxPosition = 0;

    // For each box slot, create a Pokémon icon if a species is present
    for (i = 0; i < IN_BOX_COLUMNS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            species = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            if (species != SPECIES_NONE)
            {
                personality = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
                sPSSData->boxMonsSprites[count] = CreateMonIconSprite(species, personality, 8 * (3 * j) + 100, 8 * (3 * i) + 44, 2, 19 - j);
            }
            else
            {
                sPSSData->boxMonsSprites[count] = NULL;
            }
            boxPosition++;
            count++;
        }
    }

    // If in item mode, set all Pokémon icons with no item to be transparent
    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (GetBoxMonDataAt(boxId, boxPosition, MON_DATA_HELD_ITEM) == ITEM_NONE)
                sPSSData->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}

static void sub_80CB140(u8 boxPosition)
{
    u16 species = GetCurrentBoxMonData(boxPosition, MON_DATA_SPECIES2);

    if (species != SPECIES_NONE)
    {
        s16 x = 8 * (3 * (boxPosition % IN_BOX_ROWS)) + 100;
        s16 y = 8 * (3 * (boxPosition / IN_BOX_ROWS)) + 44;
        u32 personality = GetCurrentBoxMonData(boxPosition, MON_DATA_PERSONALITY);

        sPSSData->boxMonsSprites[boxPosition] = CreateMonIconSprite(species, personality, x, y, 2, 19 - (boxPosition % IN_BOX_ROWS));
        if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
            sPSSData->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
    }
}

static void sub_80CB1F0(s16 arg0)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (sPSSData->boxMonsSprites[i] != NULL)
        {
            sPSSData->boxMonsSprites[i]->data[2] = arg0;
            sPSSData->boxMonsSprites[i]->data[4] = 1;
            sPSSData->boxMonsSprites[i]->callback = sub_80CB278;
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
        sPSSData->field_C66--;
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

    for (column = 0; column < IN_BOX_COLUMNS; column++)
    {
        if (sPSSData->boxMonsSprites[boxPosition] != NULL)
        {
            DestroyBoxMonIcon(sPSSData->boxMonsSprites[boxPosition]);
            sPSSData->boxMonsSprites[boxPosition] = NULL;
        }
        boxPosition += IN_BOX_ROWS;
    }
}

static u8 sub_80CB2F8(u8 row, u16 times, s16 xDelta)
{
    s32 i;
    u16 y = 44;
    s16 xDest = 8 * (3 * row) + 100;
    u16 x = xDest - ((times + 1) * xDelta);
    u8 subpriority = 19 - row;
    u8 count = 0;
    u8 boxPosition = row;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < IN_BOX_COLUMNS; i++)
        {
            if (sPSSData->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                sPSSData->boxMonsSprites[boxPosition] = CreateMonIconSprite(sPSSData->boxSpecies[boxPosition],
                                                                                        sPSSData->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority);
                if (sPSSData->boxMonsSprites[boxPosition] != NULL)
                {
                    sPSSData->boxMonsSprites[boxPosition]->data[1] = times;
                    sPSSData->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    sPSSData->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sPSSData->boxMonsSprites[boxPosition]->callback = sub_80CB234;
                    count++;
                }
            }
            boxPosition += IN_BOX_ROWS;
            y += 24;
        }
    }
    else
    {
        for (i = 0; i < IN_BOX_COLUMNS; i++)
        {
            if (sPSSData->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                sPSSData->boxMonsSprites[boxPosition] = CreateMonIconSprite(sPSSData->boxSpecies[boxPosition],
                                                                                        sPSSData->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority);
                if (sPSSData->boxMonsSprites[boxPosition] != NULL)
                {
                    sPSSData->boxMonsSprites[boxPosition]->data[1] = times;
                    sPSSData->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    sPSSData->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sPSSData->boxMonsSprites[boxPosition]->callback = sub_80CB234;
                    if (GetBoxMonDataAt(sPSSData->field_C5C, boxPosition, MON_DATA_HELD_ITEM) == 0)
                        sPSSData->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
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
    sPSSData->field_C6A = 0;
    sPSSData->field_C6B = boxId;
    sPSSData->field_C69 = direction;
    sPSSData->field_C60 = 32;
    sPSSData->field_C64 = -(6 * direction);
    sPSSData->field_C66 = 0;
    SetBoxSpeciesAndPersonalities(boxId);
    if (direction > 0)
        sPSSData->field_C68 = 0;
    else
        sPSSData->field_C68 = IN_BOX_ROWS - 1;

    sPSSData->field_C62 = (24 * sPSSData->field_C68) + 100;
    sub_80CB1F0(sPSSData->field_C64);
}

static bool8 sub_80CB584(void)
{
    if (sPSSData->field_C60 != 0)
        sPSSData->field_C60--;

    switch (sPSSData->field_C6A)
    {
    case 0:
        sPSSData->field_C62 += sPSSData->field_C64;
        if (sPSSData->field_C62 <= 64 || sPSSData->field_C62 >= 252)
        {
            DestroyAllIconsInRow(sPSSData->field_C68);
            sPSSData->field_C62 += sPSSData->field_C69 * 24;
            sPSSData->field_C6A++;
        }
        break;
    case 1:
        sPSSData->field_C62 += sPSSData->field_C64;
        sPSSData->field_C66 += sub_80CB2F8(sPSSData->field_C68, sPSSData->field_C60, sPSSData->field_C64);
        if ((sPSSData->field_C69 > 0 && sPSSData->field_C68 == IN_BOX_ROWS - 1)
            || (sPSSData->field_C69 < 0 && sPSSData->field_C68 == 0))
        {
            sPSSData->field_C6A++;
        }
        else
        {
            sPSSData->field_C68 += sPSSData->field_C69;
            sPSSData->field_C6A = 0;
        }
        break;
    case 2:
        if (sPSSData->field_C66 == 0)
        {
            sPSSData->field_C60++;
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
    for (i = 0; i < IN_BOX_COLUMNS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            sPSSData->boxSpecies[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            if (sPSSData->boxSpecies[boxPosition] != SPECIES_NONE)
                sPSSData->boxPersonalities[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
            boxPosition++;
        }
    }

    sPSSData->field_C5C = boxId;
}

static void DestroyBoxMonIconAtPosition(u8 boxPosition)
{
    if (sPSSData->boxMonsSprites[boxPosition] != NULL)
    {
        DestroyBoxMonIcon(sPSSData->boxMonsSprites[boxPosition]);
        sPSSData->boxMonsSprites[boxPosition] = NULL;
    }
}

static void SetBoxMonIconObjMode(u8 boxPosition, u8 objMode)
{
    if (sPSSData->boxMonsSprites[boxPosition] != NULL)
    {
        sPSSData->boxMonsSprites[boxPosition]->oam.objMode = objMode;
    }
}

static void CreatePartyMonsSprites(bool8 arg0)
{
    u16 i, count;
    u16 species = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2);
    u32 personality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);

    sPSSData->partySprites[0] = CreateMonIconSprite(species, personality, 104, 64, 1, 12);
    count = 1;
    for (i = 1; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (species != SPECIES_NONE)
        {
            personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            sPSSData->partySprites[i] = CreateMonIconSprite(species, personality, 152,  8 * (3 * (i - 1)) + 16, 1, 12);
            count++;
        }
        else
        {
            sPSSData->partySprites[i] = NULL;
        }
    }

    if (!arg0)
    {
        for (i = 0; i < count; i++)
        {
            sPSSData->partySprites[i]->pos1.y -= 160;
            sPSSData->partySprites[i]->invisible = TRUE;
        }
    }

    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sPSSData->partySprites[i] != NULL && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == 0)
                sPSSData->partySprites[i]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}

static void sub_80CB950(void)
{
    u16 i, count;

    sPSSData->field_C5E = 0;
    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (sPSSData->partySprites[i] != NULL)
        {
            if (i != count)
            {
                sub_80CB9D0(sPSSData->partySprites[i], count);
                sPSSData->partySprites[i] = NULL;
                sPSSData->field_C5E++;
            }
            count++;
        }
    }
}

static u8 sub_80CB9BC(void)
{
    return sPSSData->field_C5E;
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
        sPSSData->partySprites[sprite->data[1]] = sprite;
        sPSSData->field_C5E--;
    }
}

static void DestroyMovingMonIcon(void)
{
    if (sPSSData->movingMonSprite != NULL)
    {
        DestroyBoxMonIcon(sPSSData->movingMonSprite);
        sPSSData->movingMonSprite = NULL;
    }
}

static void sub_80CBAF0(s16 yDelta)
{
    u16 i, posY;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sPSSData->partySprites[i] != NULL)
        {
            sPSSData->partySprites[i]->pos1.y += yDelta;
            posY = sPSSData->partySprites[i]->pos1.y + sPSSData->partySprites[i]->pos2.y + sPSSData->partySprites[i]->centerToCornerVecY;
            posY += 16;
            if (posY > 192)
                sPSSData->partySprites[i]->invisible = TRUE;
            else
                sPSSData->partySprites[i]->invisible = FALSE;
        }
    }
}

static void DestroyPartyMonIcon(u8 partyId)
{
    if (sPSSData->partySprites[partyId] != NULL)
    {
        DestroyBoxMonIcon(sPSSData->partySprites[partyId]);
        sPSSData->partySprites[partyId] = NULL;
    }
}

static void DestroyAllPartyMonIcons(void)
{
    u16 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sPSSData->partySprites[i] != NULL)
        {
            DestroyBoxMonIcon(sPSSData->partySprites[i]);
            sPSSData->partySprites[i] = NULL;
        }
    }
}

static void SetPartyMonIconObjMode(u8 partyId, u8 objMode)
{
    if (sPSSData->partySprites[partyId] != NULL)
    {
        sPSSData->partySprites[partyId]->oam.objMode = objMode;
    }
}

static void sub_80CBC14(u8 mode, u8 id)
{
    if (mode == MODE_PARTY)
    {
        sPSSData->movingMonSprite = sPSSData->partySprites[id];
        sPSSData->partySprites[id] = NULL;
    }
    else if (mode == MODE_BOX)
    {
        sPSSData->movingMonSprite = sPSSData->boxMonsSprites[id];
        sPSSData->boxMonsSprites[id] = NULL;
    }
    else
    {
        return;
    }

    sPSSData->movingMonSprite->callback = sub_80CC100;
    sPSSData->movingMonSprite->oam.priority = sub_80CAFAC();
    sPSSData->movingMonSprite->subpriority = 7;
}

static void sub_80CBCAC(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
    {
        sPSSData->partySprites[position] = sPSSData->movingMonSprite;
        sPSSData->partySprites[position]->oam.priority = 1;
        sPSSData->partySprites[position]->subpriority = 12;
    }
    else
    {
        sPSSData->boxMonsSprites[position] = sPSSData->movingMonSprite;
        sPSSData->boxMonsSprites[position]->oam.priority = 2;
        sPSSData->boxMonsSprites[position]->subpriority = 19 - (position % IN_BOX_ROWS);
    }
    sPSSData->movingMonSprite->callback = SpriteCallbackDummy;
    sPSSData->movingMonSprite = NULL;
}

static void sub_80CBD5C(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
        sPSSData->field_B00 = &sPSSData->partySprites[position];
    else
        sPSSData->field_B00 = &sPSSData->boxMonsSprites[position];

    sPSSData->movingMonSprite->callback = SpriteCallbackDummy;
    sPSSData->field_C5D = 0;
}

static bool8 sub_80CBDC4(void)
{
    if (sPSSData->field_C5D == 16)
        return FALSE;

    sPSSData->field_C5D++;
    if (sPSSData->field_C5D & 1)
    {
        (*sPSSData->field_B00)->pos1.y--;
        sPSSData->movingMonSprite->pos1.y++;
    }

    (*sPSSData->field_B00)->pos2.x = gSineTable[sPSSData->field_C5D * 8] / 16;
    sPSSData->movingMonSprite->pos2.x = -(gSineTable[sPSSData->field_C5D * 8] / 16);
    if (sPSSData->field_C5D == 8)
    {
        sPSSData->movingMonSprite->oam.priority = (*sPSSData->field_B00)->oam.priority;
        sPSSData->movingMonSprite->subpriority = (*sPSSData->field_B00)->subpriority;
        (*sPSSData->field_B00)->oam.priority = sub_80CAFAC();
        (*sPSSData->field_B00)->subpriority = 7;
    }

    if (sPSSData->field_C5D == 16)
    {
        struct Sprite *sprite = sPSSData->movingMonSprite;
        sPSSData->movingMonSprite = (*sPSSData->field_B00);
        *sPSSData->field_B00 = sprite;

        sPSSData->movingMonSprite->callback = sub_80CC100;
        (*sPSSData->field_B00)->callback = SpriteCallbackDummy;
    }

    return TRUE;
}

static void sub_80CBF14(u8 mode, u8 position)
{
    switch (mode)
    {
    case MODE_PARTY:
        sPSSData->field_B04 = &sPSSData->partySprites[position];
        break;
    case MODE_BOX:
        sPSSData->field_B04 = &sPSSData->boxMonsSprites[position];
        break;
    case MODE_MOVE:
        sPSSData->field_B04 = &sPSSData->movingMonSprite;
        break;
    default:
        return;
    }

    if (*sPSSData->field_B04 != NULL)
    {
        InitSpriteAffineAnim(*sPSSData->field_B04);
        (*sPSSData->field_B04)->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        (*sPSSData->field_B04)->affineAnims = gSpriteAffineAnimTable_857291C;
        StartSpriteAffineAnim(*sPSSData->field_B04, 0);
    }
}

static bool8 sub_80CBFD8(void)
{
    if (*sPSSData->field_B04 == NULL || (*sPSSData->field_B04)->invisible)
        return FALSE;

    if ((*sPSSData->field_B04)->affineAnimEnded)
        (*sPSSData->field_B04)->invisible = TRUE;

    return TRUE;
}

static void sub_80CC020(void)
{
    if (*sPSSData->field_B04 != NULL)
    {
        FreeOamMatrix((*sPSSData->field_B04)->oam.matrixNum);
        DestroyBoxMonIcon(*sPSSData->field_B04);
        *sPSSData->field_B04 = NULL;
    }
}

static void sub_80CC064(void)
{
    if (*sPSSData->field_B04 != NULL)
    {
        (*sPSSData->field_B04)->invisible = FALSE;
        StartSpriteAffineAnim(*sPSSData->field_B04, 1);
    }
}

static bool8 sub_80CC0A0(void)
{
    if (sPSSData->field_B04 == NULL)
        return FALSE;

    if ((*sPSSData->field_B04)->affineAnimEnded)
        sPSSData->field_B04 = NULL;

    return TRUE;
}

static void SetMovingMonPriority(u8 priority)
{
    sPSSData->movingMonSprite->oam.priority = priority;
}

static void sub_80CC100(struct Sprite *sprite)
{
    sprite->pos1.x = sPSSData->field_CB4->pos1.x;
    sprite->pos1.y = sPSSData->field_CB4->pos1.y + sPSSData->field_CB4->pos2.y + 4;
}

static u16 sub_80CC124(u16 species)
{
    u16 i, var;

    for (i = 0; i < 40; i++)
    {
        if (sPSSData->field_B58[i] == species)
            break;
    }

    if (i == 40)
    {
        for (i = 0; i < 40; i++)
        {
            if (sPSSData->field_B58[i] == 0)
                break;
        }
        if (i == 40)
            return 0xFFFF;
    }

    sPSSData->field_B58[i] = species;
    sPSSData->field_B08[i]++;
    var = 16 * i;
    CpuCopy32(GetMonIconTiles(species, TRUE), (void*)(OBJ_VRAM0) + var * 32, 0x200);

    return var;
}

static void sub_80CC1E0(u16 species)
{
    u16 i;

    for (i = 0; i < 40; i++)
    {
        if (sPSSData->field_B58[i] == species)
        {
            if (--sPSSData->field_B08[i] == 0)
                sPSSData->field_B58[i] = 0;
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

#define tState  data[0]
#define tDmaIdx data[1]
#define tBoxId  data[2]

static void CreateInitBoxTask(u8 boxId)
{
    u8 taskId = CreateTask(Task_InitBox, 2);

    gTasks[taskId].tBoxId = boxId;
}

static bool8 IsInitBoxActive(void)
{
    return FuncIsActiveTask(Task_InitBox);
}

static void Task_InitBox(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        sPSSData->wallpaperOffset = 0;
        sPSSData->bg2_X = 0;
        task->tDmaIdx = RequestDma3Fill(0, sPSSData->wallpaperBgTilemapBuffer, sizeof(sPSSData->wallpaperBgTilemapBuffer), 1);
        break;
    case 1:
        if (CheckForSpaceForDma3Request(task->tDmaIdx) == -1)
            return;

        SetBgTilemapBuffer(2, sPSSData->wallpaperBgTilemapBuffer);
        ShowBg(2);
        break;
    case 2:
        LoadWallpaperGfx(task->tBoxId, 0);
        break;
    case 3:
        if (!WaitForWallpaperGfxLoad())
            return;

        InitBoxTitle(task->tBoxId);
        CreateBoxScrollArrows();
        InitBoxMonSprites(task->tBoxId);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(27) | BGCNT_TXT512x256);
        break;
    case 4:
        DestroyTask(taskId);
        break;
    default:
        task->tState = 0;
        return;
    }

    task->tState++;
}

#undef tState
#undef tDmaIdx
#undef tBoxId

static void SetUpScrollToBox(u8 boxId)
{
    s8 direction = DetermineBoxScrollDirection(boxId);

    sPSSData->wallpaperScrollSpeed = (direction > 0) ? 6 : -6;
    sPSSData->field_2D3 = (direction > 0) ? 1 : 2;
    sPSSData->field_2D0 = 32;
    sPSSData->scrollToBoxIdUnused = boxId;
    sPSSData->field_2D6 = (direction <= 0) ? 5 : 0;
    sPSSData->scrollDirectionUnused = direction;

    sPSSData->field_2DA = (direction > 0) ? 264 : 56;
    sPSSData->field_2DC = (direction <= 0) ? 5 : 0;
    sPSSData->field_2DE = 0;
    sPSSData->field_2E0 = 2;
    sPSSData->scrollToBoxId = boxId;
    sPSSData->scrollDirection = direction;
    sPSSData->scrollState = 0;
}

static bool8 ScrollToBox(void)
{
    bool8 var;

    switch (sPSSData->scrollState)
    {
    case 0:
        LoadWallpaperGfx(sPSSData->scrollToBoxId, sPSSData->scrollDirection);
        sPSSData->scrollState++;
    case 1:
        if (!WaitForWallpaperGfxLoad())
            return TRUE;

        sub_80CB4CC(sPSSData->scrollToBoxId, sPSSData->scrollDirection);
        CreateIncomingBoxTitle(sPSSData->scrollToBoxId, sPSSData->scrollDirection);
        StartBoxScrollArrowsSlide(sPSSData->scrollDirection);
        break;
    case 2:
        var = sub_80CB584();
        if (sPSSData->field_2D0 != 0)
        {
            sPSSData->bg2_X += sPSSData->wallpaperScrollSpeed;
            if (--sPSSData->field_2D0 != 0)
                return TRUE;
            CycleBoxTitleSprites();
            StopBoxScrollArrowsSlide();
        }
        return var;
    }

    sPSSData->scrollState++;
    return TRUE;
}

static s8 DetermineBoxScrollDirection(u8 boxId)
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
    sPSSData->wallpaperChangeState = 0;
}

static bool8 DoWallpaperGfxChange(void)
{
    switch (sPSSData->wallpaperChangeState)
    {
    case 0:
        BeginNormalPaletteFade(sPSSData->boxTitlePalBits, 1, 0, 16, RGB_WHITEALPHA);
        sPSSData->wallpaperChangeState++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            u8 curBox = StorageGetCurrentBox();
            LoadWallpaperGfx(curBox, 0);
            sPSSData->wallpaperChangeState++;
        }
        break;
    case 2:
        if (WaitForWallpaperGfxLoad() == TRUE)
        {
            CycleBoxTitleColor();
            BeginNormalPaletteFade(sPSSData->boxTitlePalBits, 1, 16, 0, RGB_WHITEALPHA);
            sPSSData->wallpaperChangeState++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
            sPSSData->wallpaperChangeState++;
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

static void LoadWallpaperGfx(u8 boxId, s8 direction)
{
    u8 wallpaperId;
    const struct Wallpaper *wallpaper;
    void *iconGfx;
    u32 tilesSize, iconSize;

    sPSSData->wallpaperLoadState = 0;
    sPSSData->wallpaperLoadBoxId = boxId;
    sPSSData->wallpaperLoadDir = direction;
    if (sPSSData->wallpaperLoadDir != 0)
    {
        sPSSData->wallpaperOffset = (sPSSData->wallpaperOffset == 0);
        TrimOldWallpaper(sPSSData->wallpaperBgTilemapBuffer);
    }

    wallpaperId = GetBoxWallpaper(sPSSData->wallpaperLoadBoxId);
    if (wallpaperId != WALLPAPER_FRIENDS)
    {
        wallpaper = &sWallpapers[wallpaperId];
        LZ77UnCompWram(wallpaper->tilemap, sPSSData->wallpaperTilemap);
        DrawWallpaper(sPSSData->wallpaperTilemap, sPSSData->wallpaperLoadDir, sPSSData->wallpaperOffset);

        if (sPSSData->wallpaperLoadDir != 0)
            LoadPalette(wallpaper->palettes, (sPSSData->wallpaperOffset * 32) + 0x40, 0x40);
        else
            CpuCopy16(wallpaper->palettes, &gPlttBufferUnfaded[(sPSSData->wallpaperOffset * 32) + 0x40], 0x40);

        sPSSData->wallpaperTiles = malloc_and_decompress(wallpaper->tiles, &tilesSize);
        LoadBgTiles(2, sPSSData->wallpaperTiles, tilesSize, sPSSData->wallpaperOffset << 8);
    }
    else
    {
        wallpaper = &sWaldaWallpapers[GetWaldaWallpaperPatternId()];
        LZ77UnCompWram(wallpaper->tilemap, sPSSData->wallpaperTilemap);
        DrawWallpaper(sPSSData->wallpaperTilemap, sPSSData->wallpaperLoadDir, sPSSData->wallpaperOffset);

        CpuCopy16(wallpaper->palettes, sPSSData->wallpaperTilemap, 0x40);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sPSSData->wallpaperTilemap[1], 4);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sPSSData->wallpaperTilemap[17], 4);

        if (sPSSData->wallpaperLoadDir != 0)
            LoadPalette(sPSSData->wallpaperTilemap, (sPSSData->wallpaperOffset * 32) + 0x40, 0x40);
        else
            CpuCopy16(sPSSData->wallpaperTilemap, &gPlttBufferUnfaded[(sPSSData->wallpaperOffset * 32) + 0x40], 0x40);

        sPSSData->wallpaperTiles = malloc_and_decompress(wallpaper->tiles, &tilesSize);
        iconGfx = malloc_and_decompress(sWaldaWallpaperIcons[GetWaldaWallpaperIconId()], &iconSize);
        CpuCopy32(iconGfx, sPSSData->wallpaperTiles + 0x800, iconSize);
        Free(iconGfx);
        LoadBgTiles(2, sPSSData->wallpaperTiles, tilesSize, sPSSData->wallpaperOffset << 8);
    }

    CopyBgTilemapBufferToVram(2);
}

static bool32 WaitForWallpaperGfxLoad(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return FALSE;

    if (sPSSData->wallpaperTiles != NULL)
    {
        Free(sPSSData->wallpaperTiles);
        sPSSData->wallpaperTiles = NULL;
    }
    return TRUE;
}

static void DrawWallpaper(const void *tilemap, s8 direction, u8 offset)
{
    s16 var = (offset * 2) + 3;
    s16 x = ((sPSSData->bg2_X / 8 + 10) + (direction * 24)) & 0x3F;

    CopyRectToBgTilemapBufferRect(2, tilemap, 0, 0, 0x14, 0x12, x, 2, 0x14, 0x12, 0x11, offset << 8, var);

    if (direction == 0)
        return;
    if (direction > 0)
        x *= 1, x += 0x14; // x * 1 is needed to match, but can be safely removed as it makes no functional difference
    else
        x -= 4;

    FillBgTilemapBufferRect(2, 0, x, 2, 4, 0x12, 0x11);
}

static void TrimOldWallpaper(void *tilemap)
{
    u16 i;
    u16 *dest = tilemap;
    s16 r3 = ((sPSSData->bg2_X / 8) + 30) & 0x3F;

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

static void InitBoxTitle(u8 boxId)
{
    u8 tagIndex;
    s16 x;
    u16 i;

    struct SpriteSheet spriteSheet = {sPSSData->boxTitleTiles, 0x200, GFXTAG_BOX_TITLE};
    struct SpritePalette palettes[] = {
        {sPSSData->boxTitlePal, PALTAG_BOX_TITLE},
        {}
    };

    u16 wallpaperId = GetBoxWallpaper(boxId);

    sPSSData->boxTitlePal[14] = sBoxTitleColors[wallpaperId][0]; // Shadow color
    sPSSData->boxTitlePal[15] = sBoxTitleColors[wallpaperId][1]; // Text Color
    LoadSpritePalettes(palettes);
    sPSSData->boxTitlePalBits = 0x3f0;

    tagIndex = IndexOfSpritePaletteTag(PALTAG_BOX_TITLE);
    sPSSData->boxTitlePalOffset = 0x10e + 16 * tagIndex;
    sPSSData->boxTitlePalBits |= 0x10000 << tagIndex;

    // The below seems intended to have separately tracked
    // the incoming wallpaper title's palette, but as they now
    // share a palette tag, all colors (and fields in some cases)
    // this is redundant along with the use of boxTitleAltPalOffset
    tagIndex = IndexOfSpritePaletteTag(PALTAG_BOX_TITLE);
    sPSSData->boxTitleAltPalOffset = 0x10e + 16 * tagIndex;
    sPSSData->boxTitlePalBits |= 0x10000 << tagIndex;

    StringCopyPadded(sPSSData->boxTitleText, GetBoxNamePtr(boxId), 0, 8);
    DrawTextWindowAndBufferTiles(sPSSData->boxTitleText, sPSSData->boxTitleTiles, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    x = GetBoxTitleBaseX(GetBoxNamePtr(boxId));

    // Title is split across two sprites
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_BoxTitle, x + i * 32, 28, 24);
        sPSSData->curBoxTitleSprites[i] = &gSprites[spriteId];
        StartSpriteAnim(sPSSData->curBoxTitleSprites[i], i);
    }
    sPSSData->boxTitleCycleId = 0;
}

// Sprite data for moving title text
#define sSpeed data[0]
// Flipped between incoming/outgoing for some reason
#define sIncomingX     data[1]
#define sIncomingDelay data[2]
#define sOutgoingDelay data[1]
#define sOutgoingX     data[2]

static void CreateIncomingBoxTitle(u8 boxId, s8 direction)
{
    u16 palOffset;
    s16 x, adjustedX;
    u16 i;
    struct SpriteSheet spriteSheet = {sPSSData->boxTitleTiles, 0x200, GFXTAG_BOX_TITLE};
    struct SpriteTemplate template = sSpriteTemplate_BoxTitle;

    sPSSData->boxTitleCycleId = (sPSSData->boxTitleCycleId == 0);
    if (sPSSData->boxTitleCycleId == 0)
    {
        spriteSheet.tag = GFXTAG_BOX_TITLE;
        palOffset = sPSSData->boxTitlePalOffset;
    }
    else
    {
        spriteSheet.tag = GFXTAG_BOX_TITLE_ALT;
        palOffset = sPSSData->boxTitlePalOffset;
        template.tileTag = GFXTAG_BOX_TITLE_ALT;
        template.paletteTag = PALTAG_BOX_TITLE;
    }

    StringCopyPadded(sPSSData->boxTitleText, GetBoxNamePtr(boxId), 0, 8);
    DrawTextWindowAndBufferTiles(sPSSData->boxTitleText, sPSSData->boxTitleTiles, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    LoadPalette(sBoxTitleColors[GetBoxWallpaper(boxId)], palOffset, 4);
    x = GetBoxTitleBaseX(GetBoxNamePtr(boxId));
    adjustedX = x;
    adjustedX += direction * 192;

    // Title is split across two sprites
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&template, i * 32 + adjustedX, 28, 24);

        sPSSData->nextBoxTitleSprites[i] = &gSprites[spriteId];
        sPSSData->nextBoxTitleSprites[i]->sSpeed = (-direction) * 6;
        sPSSData->nextBoxTitleSprites[i]->sIncomingX = i * 32 + x;
        sPSSData->nextBoxTitleSprites[i]->sIncomingDelay = 0;
        sPSSData->nextBoxTitleSprites[i]->callback = SpriteCB_IncomingBoxTitle;
        StartSpriteAnim(sPSSData->nextBoxTitleSprites[i], i);

        sPSSData->curBoxTitleSprites[i]->sSpeed = (-direction) * 6;
        sPSSData->curBoxTitleSprites[i]->sOutgoingDelay = 1;
        sPSSData->curBoxTitleSprites[i]->callback = SpriteCB_OutgoingBoxTitle;
    }
}

static void CycleBoxTitleSprites(void)
{
    if (sPSSData->boxTitleCycleId == 0)
        FreeSpriteTilesByTag(GFXTAG_BOX_TITLE_ALT);
    else
        FreeSpriteTilesByTag(GFXTAG_BOX_TITLE);

    sPSSData->curBoxTitleSprites[0] = sPSSData->nextBoxTitleSprites[0];
    sPSSData->curBoxTitleSprites[1] = sPSSData->nextBoxTitleSprites[1];
}

static void SpriteCB_IncomingBoxTitle(struct Sprite *sprite)
{
    if (sprite->sIncomingDelay != 0)
        sprite->sIncomingDelay--;
    else if ((sprite->pos1.x += sprite->sSpeed) == sprite->sIncomingX)
        sprite->callback = SpriteCallbackDummy;
}

static void SpriteCB_OutgoingBoxTitle(struct Sprite *sprite)
{
    if (sprite->sOutgoingDelay != 0)
    {
        sprite->sOutgoingDelay--;
    }
    else
    {
        sprite->pos1.x += sprite->sSpeed;
        sprite->sOutgoingX = sprite->pos1.x + sprite->pos2.x;
        if (sprite->sOutgoingX < 64 || sprite->sOutgoingX > DISPLAY_WIDTH + 16)
            DestroySprite(sprite);
    }
}

#undef sSpeed
#undef sIncomingX
#undef sIncomingDelay
#undef sOutgoingDelay
#undef sOutgoingX

static void CycleBoxTitleColor(void)
{
    u8 boxId = StorageGetCurrentBox();
    u8 wallpaperId = GetBoxWallpaper(boxId);
    if (sPSSData->boxTitleCycleId == 0)
        CpuCopy16(sBoxTitleColors[wallpaperId], gPlttBufferUnfaded + sPSSData->boxTitlePalOffset, 4);
    else
        CpuCopy16(sBoxTitleColors[wallpaperId], gPlttBufferUnfaded + sPSSData->boxTitleAltPalOffset, 4);
}

static s16 GetBoxTitleBaseX(const u8 *string)
{
    return DISPLAY_WIDTH - 64 - GetStringWidth(1, string, 0) / 2;
}

// Sprite data for box scroll arrows
#define sState data[0]
#define sTimer data[1]
#define sSpeed data[3]

static void CreateBoxScrollArrows(void)
{
    u16 i;

    LoadSpriteSheet(&sSpriteSheet_Arrow);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_Arrow, 92 + i * 136, 28, 22);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            StartSpriteAnim(sprite, i);
            sprite->sSpeed = (i == 0) ? -1 : 1;
            sPSSData->arrowSprites[i] = sprite;
        }
    }
    if (IsCursorOnBox())
        AnimateBoxScrollArrows(TRUE);
}

// Slide box scroll arrows horizontally for box change
static void StartBoxScrollArrowsSlide(s8 direction)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sPSSData->arrowSprites[i]->pos2.x = 0;
        sPSSData->arrowSprites[i]->sState = 2;
    }
    if (direction < 0)
    {
        sPSSData->arrowSprites[0]->sTimer = 29;
        sPSSData->arrowSprites[1]->sTimer = 5;
        sPSSData->arrowSprites[0]->data[2] = 72;
        sPSSData->arrowSprites[1]->data[2] = 72;
    }
    else
    {
        sPSSData->arrowSprites[0]->sTimer = 5;
        sPSSData->arrowSprites[1]->sTimer = 29;
        sPSSData->arrowSprites[0]->data[2] = DISPLAY_WIDTH + 8;
        sPSSData->arrowSprites[1]->data[2] = DISPLAY_WIDTH + 8;
    }
    sPSSData->arrowSprites[0]->data[7] = 0;
    sPSSData->arrowSprites[1]->data[7] = 1;
}

// New box's scroll arrows have entered, stop sliding and set their position
static void StopBoxScrollArrowsSlide(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sPSSData->arrowSprites[i]->pos1.x = 136 * i + 92;
        sPSSData->arrowSprites[i]->pos2.x = 0;
        sPSSData->arrowSprites[i]->invisible = FALSE;
    }
    AnimateBoxScrollArrows(TRUE);
}

// Bounce scroll arrows while title is selected
static void AnimateBoxScrollArrows(bool8 animate)
{
    u16 i;

    if (animate)
    {
        // Start arrows moving
        for (i = 0; i < 2; i++)
        {
            sPSSData->arrowSprites[i]->sState = 1;
            sPSSData->arrowSprites[i]->sTimer = 0;
            sPSSData->arrowSprites[i]->data[2] = 0;
            sPSSData->arrowSprites[i]->data[4] = 0;
        }
    }
    else
    {
        // Stop arrows moving
        for (i = 0; i < 2; i++)
            sPSSData->arrowSprites[i]->sState = 0;
    }
}

static void SpriteCB_Arrow(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->pos2.x = 0;
        break;
    case 1:
        if (++sprite->sTimer > 3)
        {
            sprite->sTimer = 0;
            sprite->pos2.x += sprite->sSpeed;
            if (++sprite->data[2] > 5)
            {
                sprite->data[2] = 0;
                sprite->pos2.x = 0;
            }
        }
        break;
    case 2:
        sprite->sState = 3;
        break;
    case 3:
        sprite->pos1.x -= sPSSData->wallpaperScrollSpeed;
        if (sprite->pos1.x <= 72 || sprite->pos1.x >= DISPLAY_WIDTH + 8)
            sprite->invisible = TRUE;
        if (--sprite->sTimer == 0)
        {
            sprite->pos1.x = sprite->data[2];
            sprite->invisible = FALSE;
            sprite->sState = 4;
        }
        break;
    case 4:
        sprite->pos1.x -= sPSSData->wallpaperScrollSpeed;
        break;
    }
}

#undef sState
#undef sSpeed

static struct Sprite *CreateJumpBoxArrows(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Arrow, x, y, subpriority);
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
    if (sPSSData->boxOption != BOX_OPTION_DEPOSIT)
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
    sPSSData->field_CD6 = 1;
    sPSSData->inBoxMovingMode = 0;
    sub_80CEB40();
}

static void sub_80CD3EC(void)
{
    sub_80CFC14();
    sub_80CEBDC();
    sPSSData->field_CD6 = 1;
    sPSSData->inBoxMovingMode = 0;
    if (sIsMonBeingMoved)
    {
        sPSSData->movingMon = gUnknown_02039D14;
        CreateMovingMonIcon();
    }
}

static void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y)
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

static bool8 sub_80CD554(void)
{
    s16 tmp;

    if (sPSSData->field_CD0 == 0)
    {
        if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
            return FALSE;
        else
            return sub_80D1218();
    }
    else if (--sPSSData->field_CD0 != 0)
    {
        sPSSData->field_CBC += sPSSData->field_CC4;
        sPSSData->field_CC0 += sPSSData->field_CC8;
        sPSSData->field_CB4->pos1.x = sPSSData->field_CBC >> 8;
        sPSSData->field_CB4->pos1.y = sPSSData->field_CC0 >> 8;
        if (sPSSData->field_CB4->pos1.x > DISPLAY_WIDTH + 16)
        {
            tmp = sPSSData->field_CB4->pos1.x - (DISPLAY_WIDTH + 16);
            sPSSData->field_CB4->pos1.x = tmp + 64;
        }
        if (sPSSData->field_CB4->pos1.x < 64)
        {
            tmp = 64 - sPSSData->field_CB4->pos1.x;
            sPSSData->field_CB4->pos1.x = DISPLAY_WIDTH + 16 - tmp;
        }
        if (sPSSData->field_CB4->pos1.y > DISPLAY_HEIGHT + 16)
        {
            tmp = sPSSData->field_CB4->pos1.y - (DISPLAY_HEIGHT + 16);
            sPSSData->field_CB4->pos1.y = tmp - 16;
        }
        if (sPSSData->field_CB4->pos1.y < -16)
        {
            tmp = -16 - sPSSData->field_CB4->pos1.y;
            sPSSData->field_CB4->pos1.y = DISPLAY_HEIGHT + 16 - tmp;
        }
        if (sPSSData->field_CD7 && --sPSSData->field_CD7 == 0)
            sPSSData->field_CB4->vFlip = (sPSSData->field_CB4->vFlip == FALSE);
    }
    else
    {
        sPSSData->field_CB4->pos1.x = sPSSData->field_CCC;
        sPSSData->field_CB4->pos1.y = sPSSData->field_CCE;
        sub_80CDA68();
    }

    return TRUE;
}

static void sub_80CD6AC(u8 newCursorArea, u8 newCursorPosition)
{
    u16 x, y;

    sub_80CD444(newCursorArea, newCursorPosition, &x, &y);
    sPSSData->field_CD4 = newCursorArea;
    sPSSData->field_CD5 = newCursorPosition;
    sPSSData->field_CCC = x;
    sPSSData->field_CCE = y;
}

static void sub_80CD70C(void)
{
    int r7, r0;

    if (sPSSData->field_CD2 != 0 || sPSSData->field_CD3 != 0)
        sPSSData->field_CD0 = 12;
    else
        sPSSData->field_CD0 = 6;

    if (sPSSData->field_CD7)
        sPSSData->field_CD7 = sPSSData->field_CD0 >> 1;

    switch (sPSSData->field_CD2)
    {
        default:
            r7 = sPSSData->field_CCE - sPSSData->field_CB4->pos1.y;
            break;
        case -1:
            r7 = sPSSData->field_CCE - 0xc0 - sPSSData->field_CB4->pos1.y;
            break;
        case 1:
            r7 = sPSSData->field_CCE + 0xc0 - sPSSData->field_CB4->pos1.y;
            break;
    }

    switch (sPSSData->field_CD3)
    {
        default:
            r0 = sPSSData->field_CCC - sPSSData->field_CB4->pos1.x;
            break;
        case -1:
            r0 = sPSSData->field_CCC - 0xc0 - sPSSData->field_CB4->pos1.x;
            break;
        case 1:
            r0 = sPSSData->field_CCC + 0xc0 - sPSSData->field_CB4->pos1.x;
            break;
    }

    r7 <<= 8;
    r0 <<= 8;
    sPSSData->field_CC4 = r0 / sPSSData->field_CD0;
    sPSSData->field_CC8 = r7 / sPSSData->field_CD0;
    sPSSData->field_CBC = sPSSData->field_CB4->pos1.x << 8;
    sPSSData->field_CC0 = sPSSData->field_CB4->pos1.y << 8;
}

static void sub_80CD894(u8 newCursorArea, u8 newCursorPosition)
{
    sub_80CD6AC(newCursorArea, newCursorPosition);
    sub_80CD70C();
    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        if (sPSSData->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(sPSSData->field_CB4, 1);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sPSSData->field_CB4, 1);
    }

    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
        else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            sub_80D0E50(CURSOR_AREA_IN_PARTY, sBoxCursorPosition);

        if (newCursorArea == CURSOR_AREA_IN_BOX)
            sub_80D0D8C(newCursorArea, newCursorPosition);
        else if (newCursorArea == CURSOR_AREA_IN_PARTY)
            sub_80D0D8C(newCursorArea, newCursorPosition);
    }

    if (newCursorArea == CURSOR_AREA_IN_PARTY && sBoxCursorArea != CURSOR_AREA_IN_PARTY)
    {
        sPSSData->field_CD6 = newCursorArea;
        sPSSData->field_CB8->invisible = TRUE;
    }

    switch (newCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
    case CURSOR_AREA_BOX:
    case CURSOR_AREA_BUTTONS:
        sPSSData->field_CB4->oam.priority = 1;
        sPSSData->field_CB8->invisible = TRUE;
        sPSSData->field_CB8->oam.priority = 1;
        break;
    case CURSOR_AREA_IN_BOX:
        if (sPSSData->inBoxMovingMode != 0)
        {
            sPSSData->field_CB4->oam.priority = 0;
            sPSSData->field_CB8->invisible = TRUE;
        }
        else
        {
            sPSSData->field_CB4->oam.priority = 2;
            if (sBoxCursorArea == CURSOR_AREA_IN_BOX && sIsMonBeingMoved)
                SetMovingMonPriority(2);
        }
        break;
    }
}

static void sub_80CDA68(void)
{
    sBoxCursorArea = sPSSData->field_CD4;
    sBoxCursorPosition = sPSSData->field_CD5;
    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
    {
        if (sPSSData->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(sPSSData->field_CB4, 0);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sPSSData->field_CB4, 0);
    }

    sub_80CEB40();
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_BUTTONS:
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_BOX:
        AnimateBoxScrollArrows(TRUE);
        break;
    case CURSOR_AREA_IN_PARTY:
        sPSSData->field_CB8->subpriority = 13;
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sPSSData->inBoxMovingMode == 0)
        {
            sPSSData->field_CB4->oam.priority = 1;
            sPSSData->field_CB8->oam.priority = 2;
            sPSSData->field_CB8->subpriority = 21;
            sPSSData->field_CB8->invisible = FALSE;
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
    if (sPSSData->field_CB4->vFlip)
        sPSSData->field_CD7 = 1;
    sub_80CD894(CURSOR_AREA_IN_PARTY, partyCount);
}

static void sub_80CDBF8(u8 cursorBoxPosition)
{
    sub_80CD894(CURSOR_AREA_IN_BOX, cursorBoxPosition);
}

EWRAM_DATA static u8 gUnknown_02039D7E = 0;

static void sub_80CDC0C(void)
{
    gUnknown_02039D7E = 0;
}

static void sub_80CDC18(void)
{
    gUnknown_02039D7E = sBoxCursorPosition;
}

static u8 sub_80CDC2C(void)
{
    return gUnknown_02039D7E;
}

static void InitMonPlaceChange(u8 a0)
{
    static bool8 (*const placeChangeFuncs[])(void) =
    {
        MonPlaceChange_Move,
        MonPlaceChange_Place,
        MonPlaceChange_Shift,
    };

    sPSSData->monPlaceChangeFunc = placeChangeFuncs[a0];
    sPSSData->monPlaceChangeState = 0;
}

static void sub_80CDC64(bool8 arg0)
{
    if (!arg0)
        sPSSData->monPlaceChangeFunc = sub_80CDEB4;
    else
        sPSSData->monPlaceChangeFunc = sub_80CDEC4;

    sPSSData->monPlaceChangeState = 0;
}

static bool8 DoMonPlaceChange(void)
{
    return sPSSData->monPlaceChangeFunc();
}

static bool8 MonPlaceChange_Move(void)
{
    switch (sPSSData->monPlaceChangeState)
    {
    case 0:
        if (sIsMonBeingMoved)
            return FALSE;
        StartSpriteAnim(sPSSData->field_CB4, 2);
        sPSSData->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(sPSSData->field_CB4, 3);
            MoveMon();
            sPSSData->monPlaceChangeState++;
        }
        break;
    case 2:
        if (!sub_80CDF08())
            sPSSData->monPlaceChangeState++;
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Place(void)
{
    switch (sPSSData->monPlaceChangeState)
    {
    case 0:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(sPSSData->field_CB4, 2);
            PlaceMon();
            sPSSData->monPlaceChangeState++;
        }
        break;
    case 1:
        if (!sub_80CDF08())
        {
            StartSpriteAnim(sPSSData->field_CB4, 0);
            sPSSData->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Shift(void)
{
    switch (sPSSData->monPlaceChangeState)
    {
    case 0:
        switch (sBoxCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            sPSSData->field_D91 = TOTAL_BOXES_COUNT;
            break;
        case CURSOR_AREA_IN_BOX:
            sPSSData->field_D91 = StorageGetCurrentBox();
            break;
        default:
            return FALSE;
        }
        StartSpriteAnim(sPSSData->field_CB4, 2);
        sub_80CBD5C(sPSSData->field_D91, sBoxCursorPosition);
        sPSSData->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_80CBDC4())
        {
            StartSpriteAnim(sPSSData->field_CB4, 3);
            SetShiftedMonData(sPSSData->field_D91, sBoxCursorPosition);
            sPSSData->monPlaceChangeState++;
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
    switch (sPSSData->field_CB4->pos2.y)
    {
    default:
        sPSSData->field_CB4->pos2.y++;
        break;
    case 0:
        sPSSData->field_CB4->pos2.y++;
        break;
    case 8:
        return FALSE;
    }

    return TRUE;
}

static bool8 sub_80CDF08(void)
{
    switch (sPSSData->field_CB4->pos2.y)
    {
    case 0:
        return FALSE;
    default:
        sPSSData->field_CB4->pos2.y--;
        break;
    }

    return TRUE;
}

static void MoveMon(void)
{
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        SetMovedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        sub_80CBC14(MODE_PARTY, sBoxCursorPosition);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sPSSData->inBoxMovingMode == 0)
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

static void PlaceMon(void)
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
        sPSSData->movingMon = gPlayerParty[sBoxCursorPosition];
    else
        BoxMonAtToMon(boxId, position, &sPSSData->movingMon);

    PurgeMonOrBoxMon(boxId, position);
    sMovingMonOrigBoxId = boxId;
    sMovingMonOrigBoxPos = position;
}

static void SetPlacedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
    {
        gPlayerParty[position] = sPSSData->movingMon;
    }
    else
    {
        BoxMonRestorePP(&sPSSData->movingMon.box);
        SetBoxMonAt(boxId, position, &sPSSData->movingMon.box);
    }
}

static void PurgeMonOrBoxMon(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        ZeroMonData(&gPlayerParty[position]);
    else
        ZeroBoxMonAt(boxId, position);
}

static void SetShiftedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sPSSData->field_2108 = gPlayerParty[position];
    else
        BoxMonAtToMon(boxId, position, &sPSSData->field_2108);

    SetPlacedMonData(boxId, position);
    sPSSData->movingMon = sPSSData->field_2108;
    SetCursorMonData(&sPSSData->movingMon, MODE_PARTY);
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

    StartSpriteAnim(sPSSData->field_CB4, 1);
    return TRUE;
}

static void sub_80CE22C(void)
{
    StartSpriteAnim(sPSSData->field_CB4, 0);
    sub_80CEB40();
}

static void sub_80CE250(void)
{
    u8 mode;

    if (sIsMonBeingMoved)
        mode = MODE_MOVE;
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        mode = MODE_PARTY;
    else
        mode = MODE_BOX;

    sub_80CBF14(mode, sBoxCursorPosition);
    StringCopy(sPSSData->field_21E0, sPSSData->cursorMonNick);
}

static bool8 sub_80CE2A8(void)
{
    if (!sub_80CBFD8())
    {
        StartSpriteAnim(sPSSData->field_CB4, 0);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

static void ReleaseMon(void)
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
        StartSpriteAnim(sPSSData->field_CB4, 3);
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

static void InitCanRelaseMonVars(void)
{
    if (!AtLeastThreeUsableMons())
    {
        sPSSData->field_216D = 1;
        sPSSData->field_216C = 0;
        return;
    }

    if (sIsMonBeingMoved)
    {
        sPSSData->field_2108 = sPSSData->movingMon;
        sPSSData->field_2170 = -1;
        sPSSData->field_2171 = -1;
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        {
            sPSSData->field_2108 = gPlayerParty[sBoxCursorPosition];
            sPSSData->field_2170 = TOTAL_BOXES_COUNT;
        }
        else
        {
            BoxMonAtToMon(StorageGetCurrentBox(), sBoxCursorPosition, &sPSSData->field_2108);
            sPSSData->field_2170 = StorageGetCurrentBox();
        }
        sPSSData->field_2171 = sBoxCursorPosition;
    }

    sub_80CE350(sPSSData->field_2176);
    sPSSData->field_2174 = GetMonData(&sPSSData->field_2108, MON_DATA_KNOWN_MOVES, (u8*)sPSSData->field_2176);
    if (sPSSData->field_2174 != 0)
    {
        sPSSData->field_216D = 0;
    }
    else
    {
        sPSSData->field_216D = 1;
        sPSSData->field_216C = 1;
    }

    sPSSData->field_2172 = 0;
}

static bool32 AtLeastThreeUsableMons(void)
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
            if (CheckBoxMonSanityAt(i, j))
            {
                if (++count >= 3)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static s8 RunCanReleaseMon(void)
{
    u16 i;
    u16 knownMoves;

    if (sPSSData->field_216D)
        return sPSSData->field_216C;

    switch (sPSSData->field_2172)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sPSSData->field_2170 != TOTAL_BOXES_COUNT || sPSSData->field_2171 != i)
            {
                knownMoves = GetMonData(gPlayerParty + i, MON_DATA_KNOWN_MOVES, (u8*)sPSSData->field_2176);
                sPSSData->field_2174 &= ~(knownMoves);
            }
        }
        if (sPSSData->field_2174 == 0)
        {
            sPSSData->field_216D = 1;
            sPSSData->field_216C = 1;
        }
        else
        {
            sPSSData->field_216E = 0;
            sPSSData->field_216F = 0;
            sPSSData->field_2172++;
        }
        break;
    case 1:
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            knownMoves = GetAndCopyBoxMonDataAt(sPSSData->field_216E, sPSSData->field_216F, MON_DATA_KNOWN_MOVES, (u8*)sPSSData->field_2176);
            if (knownMoves != 0
                && !(sPSSData->field_2170 == sPSSData->field_216E && sPSSData->field_2171 == sPSSData->field_216F))
            {
                sPSSData->field_2174 &= ~(knownMoves);
                if (sPSSData->field_2174 == 0)
                {
                    sPSSData->field_216D = 1;
                    sPSSData->field_216C = 1;
                    break;
                }
            }
            if (++sPSSData->field_216F >= IN_BOX_COUNT)
            {
                sPSSData->field_216F = 0;
                if (++sPSSData->field_216E >= TOTAL_BOXES_COUNT)
                {
                    sPSSData->field_216D = 1;
                    sPSSData->field_216C = 0;
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
        gUnknown_02039D14 = sPSSData->movingMon;
}

static void sub_80CE790(void)
{
    if (sIsMonBeingMoved)
    {
        if (sMovingMonOrigBoxId == TOTAL_BOXES_COUNT)
            sPSSData->movingMon = gUnknown_02039D14;
        else
            sPSSData->movingMon.box = gUnknown_02039D14.box;
    }
}

static void sub_80CE7E8(void)
{
    if (sIsMonBeingMoved)
    {
        sub_80CE760();
        sPSSData->field_218C.mon = &gUnknown_02039D14;
        sPSSData->field_2187 = 0;
        sPSSData->field_2186 = 0;
        sPSSData->pokemonSummaryScreenMode = PSS_MODE_NORMAL;
    }
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
    {
        sPSSData->field_218C.mon = gPlayerParty;
        sPSSData->field_2187 = sBoxCursorPosition;
        sPSSData->field_2186 = CountPartyMons() - 1;
        sPSSData->pokemonSummaryScreenMode = PSS_MODE_NORMAL;
    }
    else
    {
        sPSSData->field_218C.box = GetBoxedMonPtr(StorageGetCurrentBox(), 0);
        sPSSData->field_2187 = sBoxCursorPosition;
        sPSSData->field_2186 = IN_BOX_COUNT - 1;
        sPSSData->pokemonSummaryScreenMode = PSS_MODE_BOX;
    }
}

static void sub_80CE8E4(void)
{
    if (sIsMonBeingMoved)
        sub_80CE790();
    else
        sBoxCursorPosition = gLastViewedMonIndex;
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
        {
            retVal = i;
        }
    }
    for (; last < PARTY_SIZE; last++)
        ZeroMonData(gPlayerParty + last);

    return retVal;
}

static void SetMonMarkings(u8 markings)
{
    sPSSData->cursorMonMarkings = markings;
    if (sIsMonBeingMoved)
    {
        SetMonData(&sPSSData->movingMon, MON_DATA_MARKINGS, &markings);
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

static bool8 CanShiftMon(void)
{
    if (sIsMonBeingMoved)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY && CountPartyAliveNonEggMonsExcept(sBoxCursorPosition) == 0)
        {
            if (sPSSData->cursorMonIsEgg || GetMonData(&sPSSData->movingMon, MON_DATA_HP) == 0)
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
    sPSSData->setMosaic = (sIsMonBeingMoved == FALSE);
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
            SetCursorMonData(NULL, MODE_MOVE);
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
    bool8 sanityIsBadEgg;

    sPSSData->cursorMonItem = 0;
    gender = MON_MALE;
    sanityIsBadEgg = FALSE;
    if (mode == MODE_PARTY)
    {
        struct Pokemon *mon = (struct Pokemon *)pokemon;

        sPSSData->cursorMonSpecies = GetMonData(mon, MON_DATA_SPECIES2);
        if (sPSSData->cursorMonSpecies != SPECIES_NONE)
        {
            sanityIsBadEgg = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBadEgg)
                sPSSData->cursorMonIsEgg = TRUE;
            else
                sPSSData->cursorMonIsEgg = GetMonData(mon, MON_DATA_IS_EGG);

            GetMonData(mon, MON_DATA_NICKNAME, sPSSData->cursorMonNick);
            StringGetEnd10(sPSSData->cursorMonNick);
            sPSSData->cursorMonLevel = GetMonData(mon, MON_DATA_LEVEL);
            sPSSData->cursorMonMarkings = GetMonData(mon, MON_DATA_MARKINGS);
            sPSSData->cursorMonPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
            sPSSData->cursorMonPalette = GetMonFrontSpritePal(mon);
            gender = GetMonGender(mon);
            sPSSData->cursorMonItem = GetMonData(mon, MON_DATA_HELD_ITEM);
        }
    }
    else if (mode == MODE_BOX)
    {
        struct BoxPokemon *boxMon = (struct BoxPokemon *)pokemon;

        sPSSData->cursorMonSpecies = GetBoxMonData(pokemon, MON_DATA_SPECIES2);
        if (sPSSData->cursorMonSpecies != SPECIES_NONE)
        {
            u32 otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
            sanityIsBadEgg = GetBoxMonData(boxMon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBadEgg)
                sPSSData->cursorMonIsEgg = TRUE;
            else
                sPSSData->cursorMonIsEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG);


            GetBoxMonData(boxMon, MON_DATA_NICKNAME, sPSSData->cursorMonNick);
            StringGetEnd10(sPSSData->cursorMonNick);
            sPSSData->cursorMonLevel = GetLevelFromBoxMonExp(boxMon);
            sPSSData->cursorMonMarkings = GetBoxMonData(boxMon, MON_DATA_MARKINGS);
            sPSSData->cursorMonPersonality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
            sPSSData->cursorMonPalette = GetMonSpritePalFromSpeciesAndPersonality(sPSSData->cursorMonSpecies, otId, sPSSData->cursorMonPersonality);
            gender = GetGenderFromSpeciesAndPersonality(sPSSData->cursorMonSpecies, sPSSData->cursorMonPersonality);
            sPSSData->cursorMonItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
        }
    }
    else
    {
        sPSSData->cursorMonSpecies = SPECIES_NONE;
        sPSSData->cursorMonItem = 0;
    }

    if (sPSSData->cursorMonSpecies == SPECIES_NONE)
    {
        StringFill(sPSSData->cursorMonNick, CHAR_SPACE, 5);
        StringFill(sPSSData->cursorMonNickText, CHAR_SPACE, 8);
        StringFill(sPSSData->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sPSSData->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sPSSData->cursorMonItemName, CHAR_SPACE, 8);
    }
    else if (sPSSData->cursorMonIsEgg)
    {
        if (sanityIsBadEgg)
            StringCopyPadded(sPSSData->cursorMonNickText, sPSSData->cursorMonNick, CHAR_SPACE, 5);
        else
            StringCopyPadded(sPSSData->cursorMonNickText, gText_EggNickname, CHAR_SPACE, 8);

        StringFill(sPSSData->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sPSSData->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sPSSData->cursorMonItemName, CHAR_SPACE, 8);
    }
    else
    {
        if (sPSSData->cursorMonSpecies == SPECIES_NIDORAN_F || sPSSData->cursorMonSpecies == SPECIES_NIDORAN_M)
            gender = MON_GENDERLESS;

        StringCopyPadded(sPSSData->cursorMonNickText, sPSSData->cursorMonNick, CHAR_SPACE, 5);

        txtPtr = sPSSData->cursorMonSpeciesName;
        *(txtPtr)++ = CHAR_SLASH;
        StringCopyPadded(txtPtr, gSpeciesNames[sPSSData->cursorMonSpecies], CHAR_SPACE, 5);

        txtPtr = sPSSData->cursorMonGenderLvlText;
        *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
        *(txtPtr)++ = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        switch (gender)
        {
        case MON_MALE:
            *(txtPtr)++ = TEXT_COLOR_RED;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_RED;
            *(txtPtr)++ = CHAR_MALE;
            break;
        case MON_FEMALE:
            *(txtPtr)++ = TEXT_COLOR_GREEN;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GREEN;
            *(txtPtr)++ = CHAR_FEMALE;
            break;
        default:
            *(txtPtr)++ = TEXT_COLOR_DARK_GRAY;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GRAY;
            *(txtPtr)++ = CHAR_UNK_SPACER;
            break;
        }

        *(txtPtr++) = EXT_CTRL_CODE_BEGIN;
        *(txtPtr++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        *(txtPtr++) = TEXT_COLOR_DARK_GRAY;
        *(txtPtr++) = TEXT_COLOR_WHITE;
        *(txtPtr++) = TEXT_COLOR_LIGHT_GRAY;
        *(txtPtr++) = CHAR_SPACE;
        *(txtPtr++) = CHAR_EXTRA_SYMBOL;
        *(txtPtr++) = CHAR_LV_2;

        txtPtr = ConvertIntToDecimalStringN(txtPtr, sPSSData->cursorMonLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        txtPtr[0] = CHAR_SPACE;
        txtPtr[1] = EOS;

        if (sPSSData->cursorMonItem != 0)
            StringCopyPadded(sPSSData->cursorMonItemName, ItemId_GetName(sPSSData->cursorMonItem), CHAR_SPACE, 8);
        else
            StringFill(sPSSData->cursorMonItemName, CHAR_SPACE, 8);
    }
}

static u8 HandleInput_InBox(void)
{
    switch (sPSSData->inBoxMovingMode)
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

static u8 InBoxInput_Normal(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sPSSData->field_CD2 = 0;
        sPSSData->field_CD3 = 0;
        sPSSData->field_CD7 = 0;

        if (JOY_REPEAT(DPAD_UP))
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
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = TRUE;
            cursorPosition += IN_BOX_ROWS;
            if (cursorPosition >= IN_BOX_COUNT)
            {
                cursorArea = CURSOR_AREA_BUTTONS;
                cursorPosition -= IN_BOX_COUNT;
                cursorPosition /= 3;
                sPSSData->field_CD2 = 1;
                sPSSData->field_CD7 = 1;
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = TRUE;
            if (sBoxCursorPosition % IN_BOX_ROWS != 0)
            {
                cursorPosition--;
            }
            else
            {
                sPSSData->field_CD3 = -1;
                cursorPosition += (IN_BOX_ROWS - 1);
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = TRUE;
            if ((sBoxCursorPosition + 1) % IN_BOX_ROWS != 0)
            {
                cursorPosition++;
            }
            else
            {
                sPSSData->field_CD3 = 1;
                cursorPosition -= (IN_BOX_ROWS - 1);
            }
            break;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            retVal = TRUE;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
            break;
        }

        if ((JOY_NEW(A_BUTTON)) && sub_80CFA5C())
        {
            if (!sCanOnlyMove)
                return 8;

            if (sPSSData->boxOption != BOX_OPTION_MOVE_MONS || sIsMonBeingMoved == TRUE)
            {
                switch (GetMenuItemTextId(0))
                {
                case MENU_STORE:
                    return 11;
                case MENU_WITHDRAW:
                    return 12;
                case MENU_MOVE:
                    return 13;
                case MENU_SHIFT:
                    return 14;
                case MENU_PLACE:
                    return 15;
                case MENU_TAKE:
                    return 16;
                case MENU_GIVE:
                    return 17;
                case MENU_SWITCH:
                    return 18;
                }
            }
            else
            {
                sPSSData->inBoxMovingMode = 1;
                return 20;
            }
        }

        if (JOY_NEW(B_BUTTON))
            return 19;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;

    } while (0);

    if (retVal)
        sub_80CD894(cursorArea, cursorPosition);

    return retVal;
}

static u8 InBoxInput_GrabbingMultiple(void)
{
    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_REPEAT(DPAD_UP))
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
        else if (JOY_REPEAT(DPAD_DOWN))
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
        else if (JOY_REPEAT(DPAD_LEFT))
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
        else if (JOY_REPEAT(DPAD_RIGHT))
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
            sPSSData->inBoxMovingMode = 0;
            sPSSData->field_CB8->invisible = FALSE;
            return 22;
        }
        else
        {
            sIsMonBeingMoved = (sPSSData->cursorMonSpecies != SPECIES_NONE);
            sPSSData->inBoxMovingMode = 2;
            sMovingMonOrigBoxId = StorageGetCurrentBox();
            return 23;
        }
    }
}

static u8 InBoxInput_MovingMultiple(void)
{
    if (JOY_REPEAT(DPAD_UP))
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
    else if (JOY_REPEAT(DPAD_DOWN))
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
    else if (JOY_REPEAT(DPAD_LEFT))
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
    else if (JOY_REPEAT(DPAD_RIGHT))
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
    else if (JOY_NEW(A_BUTTON))
    {
        if (sub_80D0BC0())
        {
            sIsMonBeingMoved = FALSE;
            sPSSData->inBoxMovingMode = 0;
            return 26;
        }
        else
        {
            return 24;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return 24;
    }
    else
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        return 0;
    }
}

static u8 HandleInput_InParty(void)
{
    u8 retVal;
    bool8 gotoBox;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sPSSData->field_CD3 = 0;
        sPSSData->field_CD2 = 0;
        sPSSData->field_CD7 = 0;
        gotoBox = FALSE;
        retVal = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            if (--cursorPosition < 0)
                cursorPosition = PARTY_SIZE;
            if (cursorPosition != sBoxCursorPosition)
                retVal = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            if (++cursorPosition > PARTY_SIZE)
                cursorPosition = 0;
            if (cursorPosition != sBoxCursorPosition)
                retVal = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT) && sBoxCursorPosition != 0)
        {
            retVal = 1;
            sPSSData->field_CD6 = sBoxCursorPosition;
            cursorPosition = 0;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            if (sBoxCursorPosition == 0)
            {
                retVal = 1;
                cursorPosition = sPSSData->field_CD6;
            }
            else
            {
                retVal = 6;
                cursorArea = CURSOR_AREA_IN_BOX;
                cursorPosition = 0;
            }
            break;
        }

        if (JOY_NEW(A_BUTTON))
        {
            if (sBoxCursorPosition == PARTY_SIZE)
            {
                if (sPSSData->boxOption == BOX_OPTION_DEPOSIT)
                    return 4;

                gotoBox = TRUE;
            }
            else if (sub_80CFA5C())
            {
                if (!sCanOnlyMove)
                    return 8;

                switch (GetMenuItemTextId(0))
                {
                case MENU_STORE:
                    return 11;
                case MENU_WITHDRAW:
                    return 12;
                case MENU_MOVE:
                    return 13;
                case MENU_SHIFT:
                    return 14;
                case MENU_PLACE:
                    return 15;
                case MENU_TAKE:
                    return 16;
                case MENU_GIVE:
                    return 17;
                case MENU_SWITCH:
                    return 18;
                }
            }
        }

        if (JOY_NEW(B_BUTTON))
        {
            if (sPSSData->boxOption == BOX_OPTION_DEPOSIT)
                return 19;

            gotoBox = TRUE;
        }

        if (gotoBox)
        {
            retVal = 6;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 0;
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

    } while (0);

    if (retVal != 0)
    {
        if (retVal != 6)
            sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}

static u8 HandleInput_OnBox(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        sPSSData->field_CD3 = 0;
        sPSSData->field_CD2 = 0;
        sPSSData->field_CD7 = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_BUTTONS;
            cursorPosition = 0;
            sPSSData->field_CD7 = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 2;
            break;
        }

        if (JOY_HELD(DPAD_LEFT))
            return 10;
        if (JOY_HELD(DPAD_RIGHT))
            return 9;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        if (JOY_NEW(A_BUTTON))
        {
            AnimateBoxScrollArrows(FALSE);
            AddBoxMenu();
            return 7;
        }

        if (JOY_NEW(B_BUTTON))
            return 19;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;

    } while (0);

    if (retVal)
    {
        if (cursorArea != CURSOR_AREA_BOX)
            AnimateBoxScrollArrows(FALSE);
        sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}

static u8 HandleInput_OnButtons(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sPSSData->field_CD3 = 0;
        sPSSData->field_CD2 = 0;
        sPSSData->field_CD7 = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_IN_BOX;
            sPSSData->field_CD2 = -1;
            if (sBoxCursorPosition == 0)
                cursorPosition = IN_BOX_COUNT - 1 - 5;
            else 
                cursorPosition = IN_BOX_COUNT - 1;
            sPSSData->field_CD7 = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_DOWN | START_BUTTON))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
            sPSSData->field_CD7 = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = 1;
            if (--cursorPosition < 0)
                cursorPosition = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = 1;
            if (++cursorPosition > 1)
                cursorPosition = 0;
            break;
        }

        if (JOY_NEW(A_BUTTON))
            return (cursorPosition == 0) ? 5 : 4;
        if (JOY_NEW(B_BUTTON))
            return 19;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;
    } while (0);

    if (retVal != 0)
        sub_80CD894(cursorArea, cursorPosition);

    return retVal;
}

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

static void AddBoxMenu(void)
{
    InitMenu();
    SetMenuText(MENU_JUMP);
    SetMenuText(MENU_WALLPAPER);
    SetMenuText(MENU_NAME);
    SetMenuText(MENU_CANCEL);
}

static u8 sub_80CFA5C(void)
{
    InitMenu();
    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        return sub_80CFA84();
    else
        return sub_80CFB44();
}

static bool8 sub_80CFA84(void)
{
    u16 var0 = sub_80CD504();

    switch (sPSSData->boxOption)
    {
    case BOX_OPTION_DEPOSIT:
        if (var0)
            SetMenuText(MENU_STORE);
        else
            return FALSE;
        break;
    case BOX_OPTION_WITHDRAW:
        if (var0)
            SetMenuText(MENU_WITHDRAW);
        else
            return FALSE;
        break;
    case BOX_OPTION_MOVE_MONS:
        if (sIsMonBeingMoved)
        {
            if (var0)
                SetMenuText(MENU_SHIFT);
            else
                SetMenuText(MENU_PLACE);
        }
        else
        {
            if (var0)
                SetMenuText(MENU_MOVE);
            else
                return FALSE;
        }
        break;
    case BOX_OPTION_MOVE_ITEMS:
    default:
        return FALSE;
    }

    SetMenuText(MENU_SUMMARY);
    if (sPSSData->boxOption == BOX_OPTION_MOVE_MONS)
    {
        if (!sBoxCursorArea)
            SetMenuText(MENU_WITHDRAW);
        else
            SetMenuText(MENU_STORE);
    }

    SetMenuText(MENU_MARK);
    SetMenuText(MENU_RELEASE);
    SetMenuText(MENU_CANCEL);
    return TRUE;
}

static bool8 sub_80CFB44(void)
{
    if (sPSSData->cursorMonSpecies == SPECIES_EGG)
        return FALSE;

    if (!IsActiveItemMoving())
    {
        if (sPSSData->cursorMonItem == 0)
        {
            if (sPSSData->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(MENU_GIVE_2);
        }
        else
        {
            if (!ItemIsMail(sPSSData->cursorMonItem))
            {
                SetMenuText(MENU_TAKE);
                SetMenuText(MENU_BAG);
            }
            SetMenuText(MENU_INFO);
        }
    }
    else
    {
        if (sPSSData->cursorMonItem == 0)
        {
            if (sPSSData->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(MENU_GIVE);
        }
        else
        {
            if (ItemIsMail(sPSSData->cursorMonItem) == TRUE)
                return FALSE;

            SetMenuText(MENU_SWITCH);
        }
    }

    SetMenuText(MENU_CANCEL);
    return TRUE;
}

static void sub_80CFBF4(struct Sprite *sprite)
{
    sprite->pos1.x = sPSSData->field_CB4->pos1.x;
    sprite->pos1.y = sPSSData->field_CB4->pos1.y + 20;
}

static void sub_80CFC14(void)
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
        {gHandCursorPalette, TAG_PAL_DAC7},
        {}
    };

    static const struct OamData sOamData_857BA0C =
    {
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .priority = 1,
    };
    static const struct OamData sOamData_857BA14 =
    {
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
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
        .tileTag = TAG_TILE_0,
        .paletteTag = TAG_PAL_WAVEFORM,
        .oam = &sOamData_857BA0C,
        .anims = sSpriteAnimTable_857BA40,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    static const struct SpriteTemplate gSpriteTemplate_857BA68 =
    {
        .tileTag = TAG_TILE_1,
        .paletteTag = TAG_PAL_WAVEFORM,
        .oam = &sOamData_857BA14,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80CFBF4,
    };

    LoadSpriteSheets(spriteSheets);
    LoadSpritePalettes(spritePalettes);
    sPSSData->field_CD8[0] = IndexOfSpritePaletteTag(TAG_PAL_WAVEFORM);
    sPSSData->field_CD8[1] = IndexOfSpritePaletteTag(TAG_PAL_DAC7);

    sub_80CD444(sBoxCursorArea, sBoxCursorPosition, &x, &y);
    spriteId = CreateSprite(&gSpriteTemplate_857BA50, x, y, 6);
    if (spriteId != MAX_SPRITES)
    {
        sPSSData->field_CB4 = &gSprites[spriteId];
        sPSSData->field_CB4->oam.paletteNum = sPSSData->field_CD8[sCanOnlyMove];
        sPSSData->field_CB4->oam.priority = 1;
        if (sIsMonBeingMoved)
            StartSpriteAnim(sPSSData->field_CB4, 3);
    }
    else
    {
        sPSSData->field_CB4 = NULL;
    }

    if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
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
        sPSSData->field_CB8 = &gSprites[spriteId];
        sPSSData->field_CB8->oam.priority = priority;
        if (sBoxCursorArea)
            sPSSData->field_CB8->invisible = 1;
    }
    else
    {
        sPSSData->field_CB8 = NULL;
    }
}

static void sub_80CFDC4(void)
{
    sCanOnlyMove = !sCanOnlyMove;
    sPSSData->field_CB4->oam.paletteNum = sPSSData->field_CD8[sCanOnlyMove];
}

static u8 GetBoxCursorPosition(void)
{
    return sBoxCursorPosition;
}

static void sub_80CFE14(u8 *arg0, u8 *arg1)
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

static void sub_80CFE54(u8 animNum)
{
    StartSpriteAnim(sPSSData->field_CB4, animNum);
}

static u8 sub_80CFE78(void)
{
    return sMovingMonOrigBoxId;
}

static void sub_80CFE84(void)
{
    sPSSData->field_CB4->oam.priority = 1;
}

static void sub_80CFEA8(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

static void sub_80CFECC(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0D8C(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

static void InitMenu(void)
{
    sPSSData->menuItemsCount = 0;
    sPSSData->menuWidth = 0;
    sPSSData->menuWindow.bg = 0;
    sPSSData->menuWindow.paletteNum = 15;
    sPSSData->menuWindow.baseBlock = 92;
}

static const u8 *const sMenuTexts[] =
{
    [MENU_CANCEL]     = gPCText_Cancel,
    [MENU_STORE]      = gPCText_Store,
    [MENU_WITHDRAW]   = gPCText_Withdraw,
    [MENU_MOVE]       = gPCText_Move,
    [MENU_SHIFT]      = gPCText_Shift,
    [MENU_PLACE]      = gPCText_Place,
    [MENU_SUMMARY]    = gPCText_Summary,
    [MENU_RELEASE]    = gPCText_Release,
    [MENU_MARK]       = gPCText_Mark,
    [MENU_JUMP]       = gPCText_Jump,
    [MENU_WALLPAPER]  = gPCText_Wallpaper,
    [MENU_NAME]       = gPCText_Name,
    [MENU_TAKE]       = gPCText_Take,
    [MENU_GIVE]       = gPCText_Give,
    [MENU_GIVE_2]     = gPCText_Give,
    [MENU_SWITCH]     = gPCText_Switch,
    [MENU_BAG]        = gPCText_Bag,
    [MENU_INFO]       = gPCText_Info,
    [MENU_SCENERY_1]  = gPCText_Scenery1,
    [MENU_SCENERY_2]  = gPCText_Scenery2,
    [MENU_SCENERY_3]  = gPCText_Scenery3,
    [MENU_ETCETERA]   = gPCText_Etcetera,
    [MENU_FRIENDS]    = gPCText_Friends,
    [MENU_FOREST]     = gPCText_Forest,
    [MENU_CITY]       = gPCText_City,
    [MENU_DESERT]     = gPCText_Desert,
    [MENU_SAVANNA]    = gPCText_Savanna,
    [MENU_CRAG]       = gPCText_Crag,
    [MENU_VOLCANO]    = gPCText_Volcano,
    [MENU_SNOW]       = gPCText_Snow,
    [MENU_CAVE]       = gPCText_Cave,
    [MENU_BEACH]      = gPCText_Beach,
    [MENU_SEAFLOOR]   = gPCText_Seafloor,
    [MENU_RIVER]      = gPCText_River,
    [MENU_SKY]        = gPCText_Sky,
    [MENU_POLKADOT]   = gPCText_PolkaDot,
    [MENU_POKECENTER] = gPCText_Pokecenter,
    [MENU_MACHINE]    = gPCText_Machine,
    [MENU_SIMPLE]     = gPCText_Simple,
};

static void SetMenuText(u8 textId)
{
    if (sPSSData->menuItemsCount < ARRAY_COUNT(sPSSData->menuItems))
    {
        u8 len;
        struct StorageMenu *menu = &sPSSData->menuItems[sPSSData->menuItemsCount];

        menu->text = sMenuTexts[textId];
        menu->textId = textId;
        len = StringLength(menu->text);
        if (len > sPSSData->menuWidth)
            sPSSData->menuWidth = len;

        sPSSData->menuItemsCount++;
    }
}

static s8 GetMenuItemTextId(u8 menuIdx)
{
    if (menuIdx >= sPSSData->menuItemsCount)
        return -1;
    else
        return sPSSData->menuItems[menuIdx].textId;
}

static void AddMenu(void)
{
    sPSSData->menuWindow.width = sPSSData->menuWidth + 2;
    sPSSData->menuWindow.height = 2 * sPSSData->menuItemsCount;
    sPSSData->menuWindow.tilemapLeft = 29 - sPSSData->menuWindow.width;
    sPSSData->menuWindow.tilemapTop = 15 - sPSSData->menuWindow.height;
    sPSSData->menuWindowId = AddWindow(&sPSSData->menuWindow);
    ClearWindowTilemap(sPSSData->menuWindowId);
    DrawStdFrameWithCustomTileAndPalette(sPSSData->menuWindowId, FALSE, 11, 14);
    PrintMenuTable(sPSSData->menuWindowId, sPSSData->menuItemsCount, (void*)sPSSData->menuItems);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sPSSData->menuWindowId, sPSSData->menuItemsCount, 0);
    ScheduleBgCopyTilemapToVram(0);
    sPSSData->field_CAE = 0;
}

// Called after AddMenu to determine whether or not the handler callback should
// wait to move on to the next state. Evidently there was no need to wait, and
// now it always returns FALSE
static bool8 IsMenuLoading(void)
{
    return FALSE;
}

static s16 HandleMenuInput(void)
{
    s32 input = MENU_NOTHING_CHOSEN;

    do
    {
        if (JOY_NEW(A_BUTTON))
        {
            input = Menu_GetCursorPos();
            break;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            input = MENU_B_PRESSED;
        }

        if (JOY_NEW(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(-1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(1);
        }
    } while (0);

    if (input != MENU_NOTHING_CHOSEN)
        RemoveMenu();

    if (input >= 0)
        input = sPSSData->menuItems[input].textId;

    return input;
}

static void RemoveMenu(void)
{
    ClearStdWindowAndFrameToTransparent(sPSSData->menuWindowId, TRUE);
    RemoveWindow(sPSSData->menuWindowId);
}

// The functions below handle moving and grabbing multiple mons at once.
// The icons are converted to background 0 which coordinates are changed while moving mons.
// There is also a bit of math involved in determining how many column/rows of mons to grab/move.

static const struct WindowTemplate gUnknown_0857BB1C =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 3,
    .width = 20,
    .height = 18,
    .paletteNum = 9,
    .baseBlock = 0xA,
};

EWRAM_DATA static struct
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
}
*sMoveMonsPtr = NULL;

static bool8 sub_80D0164(void)
{
    sMoveMonsPtr = Alloc(sizeof(*sMoveMonsPtr));
    if (sMoveMonsPtr != NULL)
    {
        sPSSData->field_2200 = AddWindow8Bit(&gUnknown_0857BB1C);
        if (sPSSData->field_2200 != 0xFF)
        {
            FillWindowPixelBuffer(sPSSData->field_2200, PIXEL_FILL(0));
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_80D01B8(void)
{
    if (sMoveMonsPtr != NULL)
        Free(sMoveMonsPtr);
}

static void sub_80D01D0(u8 arg0)
{
    sMoveMonsPtr->field_0 = arg0;
    sMoveMonsPtr->state = 0;
}

static bool8 sub_80D01E4(void)
{
    switch (sMoveMonsPtr->field_0)
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

static bool8 sub_80D024C(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        HideBg(0);
        sub_80D304C(0x80);
        sMoveMonsPtr->state++;
        break;
    case 1:
        sub_80CFE14(&sMoveMonsPtr->fromRow, &sMoveMonsPtr->fromColumn);
        sMoveMonsPtr->toRow = sMoveMonsPtr->fromRow;
        sMoveMonsPtr->toColumn = sMoveMonsPtr->fromColumn;
        ChangeBgX(0, -1024, 0);
        ChangeBgY(0, -1024, 0);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillWindowPixelBuffer8Bit(sPSSData->field_2200, PIXEL_FILL(0));
        sub_80D07B0(sMoveMonsPtr->fromRow, sMoveMonsPtr->fromColumn);
        SetBgAttribute(0, BG_ATTR_PALETTEMODE, 1);
        PutWindowTilemap(sPSSData->field_2200);
        CopyWindowToVram8Bit(sPSSData->field_2200, 3);
        BlendPalettes(0x3F00, 8, RGB_WHITE);
        sub_80CFE54(2);
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
        sMoveMonsPtr->state++;
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

static bool8 sub_80D0344(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        HideBg(0);
        sMoveMonsPtr->state++;
        break;
    case 1:
        sub_80D0B5C();
        sub_80CFE54(0);
        sMoveMonsPtr->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80CFE84();
            LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool8 sub_80D03B0(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        if (!sub_80CD554())
        {
            sub_80CFE14(&sMoveMonsPtr->field_6, &sMoveMonsPtr->field_7);
            sub_80D062C();
            sMoveMonsPtr->toRow = sMoveMonsPtr->field_6;
            sMoveMonsPtr->toColumn = sMoveMonsPtr->field_7;
            CopyWindowToVram8Bit(sPSSData->field_2200, 2);
            sMoveMonsPtr->state++;
        }
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool8 sub_80D0420(void)
{
    u8 var1, var2;

    switch (sMoveMonsPtr->state)
    {
    case 0:
        sub_80D08CC();
        sub_80D09A4();
        sub_80CDC64(FALSE);
        sMoveMonsPtr->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(3);
            sub_80D0884(0, 256, 8);
            sub_80CDC64(TRUE);
            sMoveMonsPtr->state++;
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

static bool8 sub_80D04A0(void)
{
    u8 var1 = sub_80CD554();
    u8 var2 = sub_80D0894();

    if (!var1 && !var2)
        return FALSE;
    else
        return TRUE;
}

static bool8 sub_80D04C8(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        sub_80D0AAC();
        sub_80D0884(0, -256, 8);
        sub_80CDC64(FALSE);
        sMoveMonsPtr->state++;
        break;
    case 1:
        if (!DoMonPlaceChange() && !sub_80D0894())
        {
            sub_80D0A1C();
            sub_80CFE54(2);
            sub_80CDC64(TRUE);
            HideBg(0);
            sMoveMonsPtr->state++;
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(0);
            sub_80D0B5C();
            sMoveMonsPtr->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
            sub_80CFE84();
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool8 sub_80D0580(u8 arg0)
{
    switch (arg0)
    {
    case 0:
        if (sMoveMonsPtr->minColumn == 0)
            return FALSE;
        sMoveMonsPtr->minColumn--;
        sub_80D0884(0, 1024, 6);
        break;
    case 1:
        if (sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal >= 5)
            return FALSE;
        sMoveMonsPtr->minColumn++;
        sub_80D0884(0, -1024, 6);
        break;
    case 2:
        if (sMoveMonsPtr->minRow == 0)
            return FALSE;
        sMoveMonsPtr->minRow--;
        sub_80D0884(1024, 0, 6);
        break;
    case 3:
        if (sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal > 5)
            return FALSE;
        sMoveMonsPtr->minRow++;
        sub_80D0884(-1024, 0, 6);
        break;
    }

    return TRUE;
}

static void sub_80D062C(void)
{
    s16 var = (abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->field_6)) - (abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->toRow));
    s16 var2 = (abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->field_7)) - (abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->toColumn));

    if (var > 0)
        sub_80D06D0(sMoveMonsPtr->field_6, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);

    if (var < 0)
    {
        sub_80D0740(sMoveMonsPtr->toRow, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
        sub_80D06D0(sMoveMonsPtr->field_6, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
    }

    if (var2 > 0)
        sub_80D0708(sMoveMonsPtr->field_7, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);

    if (var2 < 0)
    {
        sub_80D0778(sMoveMonsPtr->toColumn, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
        sub_80D0708(sMoveMonsPtr->field_7, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
    }
}

static void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2)
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

static void sub_80D0708(u8 arg0, u8 arg1, u8 arg2)
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

static void sub_80D0740(u8 arg0, u8 arg1, u8 arg2)
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

static void sub_80D0778(u8 arg0, u8 arg1, u8 arg2)
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

static void sub_80D07B0(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);
    u32 personality = GetCurrentBoxMonData(position, MON_DATA_PERSONALITY);

    if (species != SPECIES_NONE)
    {
        const u8 *iconGfx = GetMonIconPtr(species, personality, 1);
        u8 index = GetValidMonIconPalIndex(species) + 8;

        BlitBitmapRectToWindow4BitTo8Bit(sPSSData->field_2200,
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

static void sub_80D0834(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);

    if (species != SPECIES_NONE)
    {
        FillWindowPixelRect8Bit(sPSSData->field_2200,
                                PIXEL_FILL(0),
                                24 * arg0,
                                24 * arg1,
                                32,
                                32);
    }
}

static void sub_80D0884(u16 arg0, u16 arg1, u16 arg2)
{
    sMoveMonsPtr->bgX = arg0;
    sMoveMonsPtr->bgY = arg1;
    sMoveMonsPtr->field_10 = arg2;
}

static u8 sub_80D0894(void)
{
    if (sMoveMonsPtr->field_10 != 0)
    {
        ChangeBgX(0, sMoveMonsPtr->bgX, 1);
        ChangeBgY(0, sMoveMonsPtr->bgY, 1);
        sMoveMonsPtr->field_10--;
    }

    return sMoveMonsPtr->field_10;
}

static void sub_80D08CC(void)
{
    s32 i, j;
    s32 rowCount, columnCount;
    u8 boxId;
    u8 monArrayId;

    sMoveMonsPtr->minRow = min(sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
    sMoveMonsPtr->minColumn = min(sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
    sMoveMonsPtr->rowsTotal = abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->toRow) + 1;
    sMoveMonsPtr->columsTotal = abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->toColumn) + 1;
    boxId = StorageGetCurrentBox();
    monArrayId = 0;
    rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);
            // UB: possible null dereference
#ifdef UBFIX
            if (boxMon != NULL)
                sMoveMonsPtr->boxMons[monArrayId] = *boxMon;
#else
            sMoveMonsPtr->boxMons[monArrayId] = *boxMon;
#endif
            monArrayId++;
            boxPosition++;
        }
    }
}

static void sub_80D09A4(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 boxId = StorageGetCurrentBox();

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            DestroyBoxMonIconAtPosition(boxPosition);
            ZeroBoxMonAt(boxId, boxPosition);
            boxPosition++;
        }
    }
}

static void sub_80D0A1C(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                sub_80CB140(boxPosition);
            monArrayId++;
            boxPosition++;
        }
    }
}

static void sub_80D0AAC(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 boxId = StorageGetCurrentBox();
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                SetBoxMonAt(boxId, boxPosition, &sMoveMonsPtr->boxMons[monArrayId]);
            boxPosition++;
            monArrayId++;
        }
    }
}

static void sub_80D0B5C(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgAttribute(0, BG_ATTR_PALETTEMODE, 0);
    ClearGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

static u8 sub_80D0BA4(void)
{
    return (IN_BOX_ROWS * sMoveMonsPtr->fromColumn) + sMoveMonsPtr->fromRow;
}

static bool8 sub_80D0BC0(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES)
                && GetCurrentBoxMonData(boxPosition, MON_DATA_SANITY_HAS_SPECIES))
                return FALSE;

            monArrayId++;
            boxPosition++;
        }
    }

    return TRUE;
}

static const u32 gUnknown_0857BB24[] = INCBIN_U32("graphics/pokemon_storage/unknown_frame.4bpp");

static const struct OamData sOamData_857BBA4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
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

static const struct SpriteTemplate gSpriteTemplate_857BC70 =
{
    .tileTag = TAG_TILE_7,
    .paletteTag = TAG_PAL_DACB,
    .oam = &sOamData_857BBA4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_857BC44,
    .callback = SpriteCallbackDummy,
};

static void sub_80D0C60(void)
{
    s32 i;
    u8 spriteId;
    struct CompressedSpriteSheet spriteSheet;
    struct SpriteTemplate spriteTemplate;

    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        spriteSheet.data = gUnknown_03000F78;
        spriteSheet.size = 0x200;
        spriteTemplate = gSpriteTemplate_857BC70;

        for (i = 0; i < 3; i++)
        {
            spriteSheet.tag = TAG_TILE_7 + i;
            LoadCompressedSpriteSheet(&spriteSheet);
            sPSSData->field_2204[i].tiles = GetSpriteTileStartByTag(spriteSheet.tag) * 32 + (void*)(OBJ_VRAM0);
            sPSSData->field_2204[i].palIndex = AllocSpritePalette(TAG_PAL_DACB + i);
            sPSSData->field_2204[i].palIndex *= 16;
            sPSSData->field_2204[i].palIndex += 0x100;
            spriteTemplate.tileTag = TAG_TILE_7 + i;
            spriteTemplate.paletteTag = TAG_PAL_DACB + i;
            spriteId = CreateSprite(&spriteTemplate, 0, 0, 11);
            sPSSData->field_2204[i].sprite = &gSprites[spriteId];
            sPSSData->field_2204[i].sprite->invisible = TRUE;
            sPSSData->field_2204[i].unk10 = 0;
        }
    }
    sPSSData->movingItem = 0;
}

// The functions below handle new features of MOVE_ITEMS box option.
static bool32 sub_80D1324(u8 cursorArea, u8 cursorPos);
static const u32 *GetItemIconPic(u16 itemId);
static const u32 *GetItemIconPalette(u16 itemId);
static u8 sub_80D12E8(void);
static void sub_80D140C(u8 id, u8 cursorArea, u8 cursorPos);
static void sub_80D1524(u8 id, const u32 *itemTiles, const u32 *itemPal);
static void sub_80D15D4(u8 id, u8 animNum);
static void sub_80D1740(u8 id, bool8 arg1);
static u8 sub_80D1370(u8 cursorArea, u8 cursorPos);
static void sub_80D1604(u8 id, u8 arg1, u8 arg2, u8 arg3);
static void sub_80D1AD8(struct Sprite *sprite);
static void sub_80D1A48(struct Sprite *sprite);
static void sub_80D1A74(struct Sprite *sprite);
static void sub_80D1B14(struct Sprite *sprite);
static void sub_80D1B94(struct Sprite *sprite);
static void sub_80D1CCC(struct Sprite *sprite);
static void sub_80D1C30(struct Sprite *sprite);

static void sub_80D0D8C(u8 cursorArea, u8 cursorPos)
{
    u16 heldItem;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
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
        const u32 *pal = GetItemIconPalette(heldItem);
        u8 id = sub_80D12E8();

        sub_80D140C(id, cursorArea, cursorPos);
        sub_80D1524(id, tiles, pal);
        sub_80D15D4(id, 1);
        sub_80D1740(id, TRUE);
    }
}

static void sub_80D0E50(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 2);
    sub_80D1604(id, 0, cursorArea, cursorPos);
}

static void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
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

    sPSSData->movingItem = sPSSData->cursorMonItem;
}

static void sub_80D0F38(u16 item)
{
    const u32 *tiles = GetItemIconPic(item);
    const u32 *pal = GetItemIconPalette(item);
    u8 id = sub_80D12E8();

    sub_80D1524(id, tiles, pal);
    sub_80D15D4(id, 6);
    sub_80D1604(id, 1, 0, 0);
    sub_80D140C(id, 2, 0);
    sub_80D1740(id, TRUE);
    sPSSData->movingItem = item;
}

static void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 3);
    sub_80D1604(id, 3, 2, 0);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        item = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sPSSData->movingItem);
        sPSSData->movingItem = item;
    }
    else
    {
        item = GetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sPSSData->movingItem);
        sPSSData->movingItem = item;
    }

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 4, cursorArea, cursorPos);
}

static void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 2, cursorArea, cursorPos);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sPSSData->movingItem);
        SetBoxMonIconObjMode(cursorPos, 0);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sPSSData->movingItem);
        SetPartyMonIconObjMode(cursorPos, 0);
    }
}

static void Item_TakeMons(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
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

static void sub_80D1194(void)
{
    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        u8 id = sub_80D1370(2, 0);
        sub_80D15D4(id, 5);
        sub_80D1604(id, 0, 2, 0);
    }
}

static void sub_80D11CC(void)
{
    s32 i;

    if (sPSSData->boxOption != BOX_OPTION_MOVE_ITEMS)
        return;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10 && sPSSData->field_2204[i].unk8 == 1)
            sub_80D1604(i, 7, 2, 0);
    }
}

static bool8 sub_80D1218(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10)
        {
            if (!sPSSData->field_2204[i].sprite->affineAnimEnded && sPSSData->field_2204[i].sprite->affineAnimBeginning)
                return TRUE;
            if (sPSSData->field_2204[i].sprite->callback != SpriteCallbackDummy && sPSSData->field_2204[i].sprite->callback != sub_80D1AD8)
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 IsActiveItemMoving(void)
{
    s32 i;

    if (sPSSData->boxOption == BOX_OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < 3; i++)
        {
            if (sPSSData->field_2204[i].unk10 && sPSSData->field_2204[i].unk8 == 2)
                return TRUE;
        }
    }

    return FALSE;
}

static const u8 *GetMovingItemName(void)
{
    return ItemId_GetName(sPSSData->movingItem);
}

static u16 GetMovingItem(void)
{
    return sPSSData->movingItem;
}

static u8 sub_80D12E8(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10 == 0)
        {
            sPSSData->field_2204[i].unk10 = 1;
            return i;
        }
    }

    return 3;
}

static bool32 sub_80D1324(u8 cursorArea, u8 cursorPos)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10
            && sPSSData->field_2204[i].unk8 == cursorArea
            && sPSSData->field_2204[i].unk9 == cursorPos)
            return TRUE;
    }

    return FALSE;
}

static u8 sub_80D1370(u8 cursorArea, u8 cursorPos)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10
            && sPSSData->field_2204[i].unk8 == cursorArea
            && sPSSData->field_2204[i].unk9 == cursorPos)
            return i;
    }

    return 3;
}

static u8 sub_80D13C4(struct Sprite *sprite)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sPSSData->field_2204[i].unk10
            && sPSSData->field_2204[i].sprite == sprite)
            return i;
    }

    return 3;
}

static void sub_80D140C(u8 id, u8 cursorArea, u8 cursorPos)
{
    u8 row, column;

    if (id >= 3)
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        row = cursorPos % IN_BOX_ROWS;
        column = cursorPos / IN_BOX_ROWS;
        sPSSData->field_2204[id].sprite->pos1.x = (24 * row) + 112;
        sPSSData->field_2204[id].sprite->pos1.y = (24 * column) + 56;
        sPSSData->field_2204[id].sprite->oam.priority = 2;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos == 0)
        {
            sPSSData->field_2204[id].sprite->pos1.x = 116;
            sPSSData->field_2204[id].sprite->pos1.y = 76;
        }
        else
        {
            sPSSData->field_2204[id].sprite->pos1.x = 164;
            sPSSData->field_2204[id].sprite->pos1.y = 24 * (cursorPos - 1) + 28;
        }
        sPSSData->field_2204[id].sprite->oam.priority = 1;
        break;
    }

    sPSSData->field_2204[id].unk8 = cursorArea;
    sPSSData->field_2204[id].unk9 = cursorPos;
}

static void sub_80D1524(u8 id, const u32 *itemTiles, const u32 *itemPal)
{
    s32 i;

    if (id >= 3)
        return;

    CpuFastFill(0, sPSSData->field_42C4, 0x200);
    LZ77UnCompWram(itemTiles, sPSSData->field_22C4);
    for (i = 0; i < 3; i++)
        CpuFastCopy(sPSSData->field_22C4 + (i * 0x60), sPSSData->field_42C4 + (i * 0x80), 0x60);

    CpuFastCopy(sPSSData->field_42C4, sPSSData->field_2204[id].tiles, 0x200);
    LZ77UnCompWram(itemPal, sPSSData->field_42C4);
    LoadPalette(sPSSData->field_42C4, sPSSData->field_2204[id].palIndex, 0x20);
}

static void sub_80D15D4(u8 id, u8 animNum)
{
    if (id >= 3)
        return;

    StartSpriteAffineAnim(sPSSData->field_2204[id].sprite, animNum);
}

static void sub_80D1604(u8 id, u8 arg1, u8 arg2, u8 arg3)
{
    if (id >= 3)
        return;

    switch (arg1)
    {
    case 0:
        sPSSData->field_2204[id].sprite->data[0] = id;
        sPSSData->field_2204[id].sprite->callback = sub_80D1A48;
        break;
    case 1:
        sPSSData->field_2204[id].sprite->data[0] = 0;
        sPSSData->field_2204[id].sprite->callback = sub_80D1A74;
        break;
    case 2:
        sPSSData->field_2204[id].sprite->data[0] = 0;
        sPSSData->field_2204[id].sprite->data[6] = arg2;
        sPSSData->field_2204[id].sprite->data[7] = arg3;
        sPSSData->field_2204[id].sprite->callback = sub_80D1B14;
        break;
    case 3:
        sPSSData->field_2204[id].sprite->data[0] = 0;
        sPSSData->field_2204[id].sprite->callback = sub_80D1B94;
        sPSSData->field_2204[id].sprite->data[6] = arg2;
        sPSSData->field_2204[id].sprite->data[7] = arg3;
        break;
    case 4:
        sPSSData->field_2204[id].sprite->data[0] = 0;
        sPSSData->field_2204[id].sprite->data[6] = arg2;
        sPSSData->field_2204[id].sprite->data[7] = arg3;
        sPSSData->field_2204[id].sprite->callback = sub_80D1C30;
        break;
    case 7:
        sPSSData->field_2204[id].sprite->callback = sub_80D1CCC;
        break;
    }
}

static void sub_80D1740(u8 id, bool8 arg1)
{
    if (id >= 3)
        return;

    sPSSData->field_2204[id].unk10 = arg1;
    sPSSData->field_2204[id].sprite->invisible = (arg1 == FALSE);
}

static const u32 *GetItemIconPic(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 0);
}

static const u32 *GetItemIconPalette(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 1);
}

static void PrintItemDescription(void)
{
    const u8 *description;

    if (IsActiveItemMoving())
        description = ItemId_GetDescription(sPSSData->movingItem);
    else
        description = ItemId_GetDescription(sPSSData->cursorMonItem);

    FillWindowPixelBuffer(2, PIXEL_FILL(1));
    AddTextPrinterParameterized5(2, 1, description, 4, 0, 0, NULL, 0, 1);
}

static void sub_80D1818(void)
{
    sPSSData->field_2236 = 0x15;
    LoadBgTiles(0, gUnknown_0857BB24, 0x80, 0x13A);
    sub_80D19B4(0);
}

static bool8 sub_80D184C(void)
{
    s32 i, var;

    if (sPSSData->field_2236 == 0)
        return FALSE;

    sPSSData->field_2236--;
    var = 0x15 - sPSSData->field_2236;
    for (i = 0; i < var; i++)
    {
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sPSSData->field_2236 + i, i, 13, 1, 7, 15, 21);
    }

    sub_80D19B4(var);
    return (sPSSData->field_2236 != 0);
}

static bool8 sub_80D18E4(void)
{
    s32 i, var;

    if (sPSSData->field_2236 == 0x16)
        return FALSE;

    if (sPSSData->field_2236 == 0)
        FillBgTilemapBufferRect(0, 0, 21, 12, 1, 9, 17);

    sPSSData->field_2236++;
    var = 0x15 - sPSSData->field_2236;
    for (i = 0; i < var; i++)
    {
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sPSSData->field_2236 + i, i, 13, 1, 7, 15, 21);
    }

    if (var >= 0)
        sub_80D19B4(var);

    FillBgTilemapBufferRect(0, 0, var + 1, 12, 1, 9, 0x11);
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

static void sub_80D19B4(u32 arg0)
{
    if (arg0 != 0)
    {
        FillBgTilemapBufferRect(0, 0x13A, 0, 0xC, arg0, 1, 0xFu);
        FillBgTilemapBufferRect(0, 0x93A, 0, 0x14, arg0, 1, 0xFu);
    }
    FillBgTilemapBufferRect(0, 0x13B, arg0, 0xD, 1, 7, 0xFu);
    FillBgTilemapBufferRect(0, 0x13C, arg0, 0xC, 1, 1, 0xFu);
    FillBgTilemapBufferRect(0, 0x13D, arg0, 0x14, 1, 1, 0xFu);
    ScheduleBgCopyTilemapToVram(0);
}

static void sub_80D1A48(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sub_80D1740(sprite->data[0], FALSE);
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_80D1A74(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
            sprite->callback = sub_80D1AD8;
        break;
    }
}

static void sub_80D1AD8(struct Sprite *sprite)
{
    sprite->pos1.x = sPSSData->field_CB4->pos1.x + 4;
    sprite->pos1.y = sPSSData->field_CB4->pos1.y + sPSSData->field_CB4->pos2.y + 8;
    sprite->oam.priority = sPSSData->field_CB4->oam.priority;
}

static void sub_80D1B14(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void sub_80D1B94(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        sprite->pos2.x = gSineTable[sprite->data[5] * 8] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->pos2.x = 0;
            sprite->callback = sub_80D1AD8;
        }
        break;
    }
}

static void sub_80D1C30(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        sprite->pos2.x = -(gSineTable[sprite->data[5] * 8] >> 4);
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
            sprite->pos2.x = 0;
        }
        break;
    }
}

static void sub_80D1CCC(struct Sprite *sprite)
{
    sprite->pos1.y -= 8;
    if (sprite->pos1.y + sprite->pos2.y < -16)
    {
        sprite->callback = SpriteCallbackDummy;
        sub_80D1740(sub_80D13C4(sprite), FALSE);
    }
}

void nullsub_pss(void)
{

}

void nullsub_98(void)
{

}

// Functions here are general utility functions.
u8 StorageGetCurrentBox(void)
{
    return gPokemonStoragePtr->currentBox;
}

static void SetCurrentBox(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        gPokemonStoragePtr->currentBox = boxId;
}

u32 GetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request);
    else
        return 0;
}

void SetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, const void *value)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, value);
}

u32 GetCurrentBoxMonData(u8 boxPosition, s32 request)
{
    return GetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request);
}

void SetCurrentBoxMonData(u8 boxPosition, s32 request, const void *value)
{
    SetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request, value);
}

void GetBoxMonNickAt(u8 boxId, u8 boxPosition, u8 *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, dst);
    else
        *dst = EOS;
}

u32 GetBoxMonLevelAt(u8 boxId, u8 boxPosition)
{
    u32 lvl;

    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
        lvl = GetLevelFromBoxMonExp(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
    #ifdef BUGFIX
    else
    #endif
        lvl = 0;

    return lvl;
}

void SetBoxMonNickAt(u8 boxId, u8 boxPosition, const u8 *nick)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, nick);
}

u32 GetAndCopyBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, void *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, dst);
    else
        return 0;
}

void SetBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *src)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        gPokemonStoragePtr->boxes[boxId][boxPosition] = *src;
}

void CopyBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        *dst = gPokemonStoragePtr->boxes[boxId][boxPosition];
}

void CreateBoxMonAt(u8 boxId, u8 boxPosition, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 personality, u8 otIDType, u32 otID)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
    {
        CreateBoxMon(&gPokemonStoragePtr->boxes[boxId][boxPosition],
                     species,
                     level,
                     fixedIV,
                     hasFixedPersonality, personality,
                     otIDType, otID);
    }
}

void ZeroBoxMonAt(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        ZeroBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
}

void BoxMonAtToMon(u8 boxId, u8 boxPosition, struct Pokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        BoxMonToMon(&gPokemonStoragePtr->boxes[boxId][boxPosition], dst);
}

struct BoxPokemon *GetBoxedMonPtr(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return &gPokemonStoragePtr->boxes[boxId][boxPosition];
    else
        return NULL;
}

u8 *GetBoxNamePtr(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxNames[boxId];
    else
        return NULL;
}

static u8 GetBoxWallpaper(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxWallpapers[boxId];
    else
        return 0;
}

static void SetBoxWallpaper(u8 boxId, u8 wallpaperId)
{
    if (boxId < TOTAL_BOXES_COUNT && wallpaperId < WALLPAPER_COUNT)
        gPokemonStoragePtr->boxWallpapers[boxId] = wallpaperId;
}

s16 sub_80D214C(struct BoxPokemon *boxMons, u8 currIndex, u8 maxIndex, u8 arg3)
{
    s16 i;
    s16 adder = -1;

    if (arg3 < 2)
        adder = 1;

    if (arg3 == 1 || arg3 == 3)
    {
        for (i = (s8)currIndex + adder; i >= 0 && i <= maxIndex; i += adder)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE)
                return i;
        }
    }
    else
    {
        for (i = (s8)currIndex + adder; i >= 0 && i <= maxIndex; i += adder)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE
                && !GetBoxMonData(&boxMons[i], MON_DATA_IS_EGG))
                return i;
        }
    }

    return -1;
}

bool8 CheckFreePokemonStorageSpace(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES))
                return TRUE;
        }
    }

    return FALSE;
}

bool32 CheckBoxMonSanityAt(u32 boxId, u32 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT
        && boxPosition < IN_BOX_COUNT
        && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_EGG)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_BAD_EGG))
        return TRUE;
    else
        return FALSE;
}

u32 CountStorageNonEggMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

u32 CountAllStorageMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                || GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

bool32 AnyStorageMonWithMove(u16 moveId)
{
    u16 moves[] = {moveId, MOVES_COUNT};
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG)
                && GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_KNOWN_MOVES, (u8*)moves))
                return TRUE;
        }
    }

    return FALSE;
}

void ResetWaldaWallpaper(void)
{
    gSaveBlock1Ptr->waldaPhrase.iconId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = FALSE;
    gSaveBlock1Ptr->waldaPhrase.colors[0] = RGB(21, 25, 30);
    gSaveBlock1Ptr->waldaPhrase.colors[1] = RGB(6, 12, 24);
    gSaveBlock1Ptr->waldaPhrase.text[0] = EOS;
}

void SetWaldaWallpaperLockedOrUnlocked(bool32 unlocked)
{
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = unlocked;
}

bool32 IsWaldaWallpaperUnlocked(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternUnlocked;
}

u32 GetWaldaWallpaperPatternId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternId;
}

void SetWaldaWallpaperPatternId(u8 id)
{
    if (id < FRIENDS_WALLPAPERS_COUNT)
        gSaveBlock1Ptr->waldaPhrase.patternId = id;
}

u32 GetWaldaWallpaperIconId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.iconId;
}

void SetWaldaWallpaperIconId(u8 id)
{
    if (id < ARRAY_COUNT(sWaldaWallpaperIcons))
        gSaveBlock1Ptr->waldaPhrase.iconId = id;
}

u16 *GetWaldaWallpaperColorsPtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.colors;
}

void SetWaldaWallpaperColors(u16 color1, u16 color2)
{
    gSaveBlock1Ptr->waldaPhrase.colors[0] = color1;
    gSaveBlock1Ptr->waldaPhrase.colors[1] = color2;
}

u8 *GetWaldaPhrasePtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.text;
}

void SetWaldaPhrase(const u8 *src)
{
    StringCopy(gSaveBlock1Ptr->waldaPhrase.text, src);
}

bool32 IsWaldaPhraseEmpty(void)
{
    return (gSaveBlock1Ptr->waldaPhrase.text[0] == EOS);
}

// Not sure what the purpose of these functions is.
// They seem to only be called while PSS is initialized.

EWRAM_DATA static struct UnkStruct_2039D84 *gUnknown_02039D84 = NULL;
EWRAM_DATA static u16 gUnknown_02039D88 = 0;

static void sub_80D259C(u8 count)
{
    u16 i;

    gUnknown_02039D84 = Alloc(sizeof(*gUnknown_02039D84) * count);
    gUnknown_02039D88 = (gUnknown_02039D84 == NULL) ? 0 : count;
    for (i = 0; i < gUnknown_02039D88; i++)
    {
        gUnknown_02039D84[i].field_18 = NULL;
        gUnknown_02039D84[i].field_2C = 0;
    }
}

static void sub_80D25F0(void)
{
    Free(gUnknown_02039D84);
}

static void sub_80D2604(void)
{
    s32 i;

    for (i = 0; i < gUnknown_02039D88; i++)
    {
        if (gUnknown_02039D84[i].field_2C == 1)
            sub_80D2918(i);
    }
}

struct
{
    u16 a;
    u16 b;
}
static const sUnkVars[][4] =
{
    {
        {0x0100, 0x0100},
        {0x0200, 0x0100},
        {0x0100, 0x0200},
        {0x0200, 0x0200},
    },
    {
        {0x0080, 0x0080},
        {0x0100, 0x0100},
        {0x0200, 0x0200},
        {0x0400, 0x0400},
    },
};

static void sub_80D2644(u8 id, u8 bg, const void *arg2, u16 arg3, u16 arg4)
{
    u16 bgScreenSize, bgType;

    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_18 = NULL;
    gUnknown_02039D84[id].field_1C = arg2;
    gUnknown_02039D84[id].field_2B = bg;
    gUnknown_02039D84[id].field_24 = arg3;
    gUnknown_02039D84[id].field_26 = arg4;

    bgScreenSize = GetBgAttribute(bg, BG_ATTR_SCREENSIZE);
    bgType = GetBgAttribute(bg, BG_ATTR_TYPE);
    gUnknown_02039D84[id].field_20 = sUnkVars[bgType][bgScreenSize].a;
    gUnknown_02039D84[id].field_22 = sUnkVars[bgType][bgScreenSize].b;
    if (bgType != 0)
        gUnknown_02039D84[id].field_2A = 1;
    else
        gUnknown_02039D84[id].field_2A = 2;

    gUnknown_02039D84[id].field_28 = gUnknown_02039D84[id].field_2A * arg3;
    gUnknown_02039D84[id].field_0[1].field_4 = arg3;
    gUnknown_02039D84[id].field_0[1].field_6 = arg4;
    gUnknown_02039D84[id].field_0[1].field_0 = 0;
    gUnknown_02039D84[id].field_0[1].field_2 = 0;
    gUnknown_02039D84[id].field_0[1].field_8 = 0;
    gUnknown_02039D84[id].field_0[1].field_A = 0;
    gUnknown_02039D84[id].field_0[0] = gUnknown_02039D84[id].field_0[1];
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D2740(u8 id, const void *arg1)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_18 = arg1;
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D2770(u8 id, u16 arg1, u16 arg2)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_0[1].field_8 = arg1;
    gUnknown_02039D84[id].field_0[1].field_A = arg2;
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D27AC(u8 id, u16 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_0[1].field_0 = arg1;
    gUnknown_02039D84[id].field_0[1].field_2 = arg2;
    gUnknown_02039D84[id].field_0[1].field_4 = arg3;
    gUnknown_02039D84[id].field_0[1].field_6 = arg4;
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D27F4(u8 id, u8 arg1, s8 arg2)
{
    if (id >= gUnknown_02039D88)
        return;

    switch (arg1)
    {
    case 0:
        gUnknown_02039D84[id].field_0[1].field_8 += arg2;
        gUnknown_02039D84[id].field_0[1].field_4 -= arg2;
        break;
    case 1:
        gUnknown_02039D84[id].field_0[1].field_0 += arg2;
        gUnknown_02039D84[id].field_0[1].field_4 += arg2;
        break;
    case 2:
        gUnknown_02039D84[id].field_0[1].field_A += arg2;
        gUnknown_02039D84[id].field_0[1].field_6 -= arg2;
        break;
    case 3:
        gUnknown_02039D84[id].field_0[1].field_2 -= arg2;
        gUnknown_02039D84[id].field_0[1].field_6 += arg2;
        break;
    case 4:
        gUnknown_02039D84[id].field_0[1].field_8 += arg2;
        break;
    case 5:
        gUnknown_02039D84[id].field_0[1].field_A += arg2;
        break;
    }

    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D2918(u8 id)
{
    if (id >= gUnknown_02039D88)
        return;

    if (gUnknown_02039D84[id].field_18 != NULL)
        sub_80D2960(id);

    sub_80D29F8(id);
    gUnknown_02039D84[id].field_0[0] = gUnknown_02039D84[id].field_0[1];
}

static void sub_80D2960(u8 id)
{
    s32 i;
    u32 adder = gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_20;
    const void *tiles = (gUnknown_02039D84[id].field_18 + (adder * gUnknown_02039D84[id].field_0[0].field_A))
                      + (gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_0[0].field_8);

    for (i = 0; i < gUnknown_02039D84[id].field_0[0].field_6; i++)
    {
        CopyToBgTilemapBufferRect(gUnknown_02039D84[id].field_2B,
                                  tiles,
                                  gUnknown_02039D84[id].field_0[0].field_8,
                                  gUnknown_02039D84[id].field_0[0].field_A + i,
                                  gUnknown_02039D84[id].field_0[0].field_4,
                                  1);
        tiles += adder;
    }
}

static void sub_80D29F8(u8 id)
{
    s32 i;
    u32 adder = gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_24;
    const void *tiles = (gUnknown_02039D84[id].field_1C + (adder * gUnknown_02039D84[id].field_0[1].field_2))
                      + (gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_0[1].field_0);

    for (i = 0; i < gUnknown_02039D84[id].field_0[1].field_6; i++)
    {
        CopyToBgTilemapBufferRect(gUnknown_02039D84[id].field_2B,
                                  tiles,
                                  gUnknown_02039D84[id].field_0[1].field_8,
                                  gUnknown_02039D84[id].field_0[1].field_A + i,
                                  gUnknown_02039D84[id].field_0[1].field_4,
                                  1);
        tiles += adder;
    }
}

EWRAM_DATA static struct UnkStruct_2000020 *gUnknown_02039D8C = NULL;

static void sub_80D2A90(struct UnkStruct_2000020 *arg0, struct UnkStruct_2000028 *arg1, u32 arg2)
{
    gUnknown_02039D8C = arg0;
    arg0->unk_00 = arg1;
    arg0->unk_05 = arg2;
    arg0->unk_04 = 0;
}

static void sub_80D2AA4(void)
{
    u16 i;

    if (gUnknown_02039D8C->unk_04)
    {
        for (i = 0; i < gUnknown_02039D8C->unk_04; i++)
        {
            struct UnkStruct_2000028 *unkStruct = &gUnknown_02039D8C->unk_00[i];
            unkStruct->unk_0c(unkStruct);
        }

        gUnknown_02039D8C->unk_04 = 0;
    }
}

static bool8 sub_80D2AEC(u8 *dest, u16 dLeft, u16 dTop, const u8 *src, u16 sLeft, u16 sTop, u16 width, u16 height, u16 unkArg)
{
    struct UnkStruct_2000028 *unkStruct;

    if (gUnknown_02039D8C->unk_04 >= gUnknown_02039D8C->unk_05)
        return FALSE;

    unkStruct = &gUnknown_02039D8C->unk_00[gUnknown_02039D8C->unk_04++];
    unkStruct->unk_08 = width * 2;
    unkStruct->unk_04 = dest + 2 * (dTop * 32 + dLeft);
    unkStruct->unk_00 = src + 2 * (sTop * unkArg + sLeft);
    unkStruct->newField = height;
    unkStruct->unk_0a = unkArg;
    unkStruct->unk_0c = sub_80D2B88;
    return TRUE;
}

static void sub_80D2B88(struct UnkStruct_2000028 *unkStruct)
{
    u16 i;

    for (i = 0; i < unkStruct->newField; i++)
    {
        CpuSet(unkStruct->unk_00, unkStruct->unk_04, (unkStruct->unk_08 / 2));
        unkStruct->unk_04 += 64;
        unkStruct->unk_00 += (unkStruct->unk_0a * 2);
    }
}

static bool8 sub_80D2BC0(void *dest, u16 dLeft, u16 dTop, u16 width, u16 height)
{
    struct UnkStruct_2000028 *unkStruct;

    if (gUnknown_02039D8C->unk_04 >= gUnknown_02039D8C->unk_05)
        return FALSE;

    unkStruct = &gUnknown_02039D8C->unk_00[gUnknown_02039D8C->unk_04++];
    unkStruct->unk_08 = width * 2;
    unkStruct->unk_04 = dest + ((dTop * 32) + dLeft) * 2;
    unkStruct->newField = height;
    unkStruct->unk_0c = sub_80D2C1C;
    return TRUE;
}

static void sub_80D2C1C(struct UnkStruct_2000028 *unkStruct)
{
    u16 i;

    for (i = 0; i < unkStruct->newField; i++)
    {
        Dma3FillLarge_(0, unkStruct->unk_04, unkStruct->unk_08, 16);
        unkStruct->unk_04 += 64;
    }
}
