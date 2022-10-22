#include "global.h"
#include "battle_main.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum
{
    PAGE_MAIN,
    PAGE_INFO,
    PAGE_SEARCH,
    PAGE_SEARCH_RESULTS,
    PAGE_UNK,
    PAGE_AREA,
    PAGE_CRY,
    PAGE_SIZE
};

enum
{
    AREA_SCREEN,
    CRY_SCREEN,
    SIZE_SCREEN,
    CANCEL_SCREEN,
    SCREEN_COUNT
};

enum
{
    SEARCH_NAME,
    SEARCH_COLOR,
    SEARCH_TYPE_LEFT,
    SEARCH_TYPE_RIGHT,
    SEARCH_ORDER,
    SEARCH_MODE,
    SEARCH_OK,
    SEARCH_COUNT
};

enum
{
    SEARCH_TOPBAR_SEARCH,
    SEARCH_TOPBAR_SHIFT,
    SEARCH_TOPBAR_CANCEL,
    SEARCH_TOPBAR_COUNT
};

enum
{
   ORDER_NUMERICAL,
   ORDER_ALPHABETICAL,
   ORDER_HEAVIEST,
   ORDER_LIGHTEST,
   ORDER_TALLEST,
   ORDER_SMALLEST
};

enum
{
    NAME_ABC = 1,
    NAME_DEF,
    NAME_GHI,
    NAME_JKL,
    NAME_MNO,
    NAME_PQR,
    NAME_STU,
    NAME_VWX,
    NAME_YZ,
};

// For scrolling search parameter
#define MAX_SEARCH_PARAM_ON_SCREEN   6
#define MAX_SEARCH_PARAM_CURSOR_POS  (MAX_SEARCH_PARAM_ON_SCREEN - 1)

#define MAX_MONS_ON_SCREEN 4

#define LIST_SCROLL_STEP         16

#define POKEBALL_ROTATION_TOP    64
#define POKEBALL_ROTATION_BOTTOM (POKEBALL_ROTATION_TOP - 16)

// Coordinates of the Pokémon sprite on its page (info/cry screens)
#define MON_PAGE_X 48
#define MON_PAGE_Y 56

static EWRAM_DATA struct PokedexView *sPokedexView = NULL;
static EWRAM_DATA u16 sLastSelectedPokemon = 0;
static EWRAM_DATA u8 sPokeBallRotation = 0;
static EWRAM_DATA struct PokedexListItem *sPokedexListItem = NULL;

// This is written to, but never read.
u8 gUnusedPokedexU8;
void (*gPokedexVBlankCB)(void);

struct SearchOptionText
{
    const u8 *description;
    const u8 *title;
};

struct SearchOption
{
    const struct SearchOptionText *texts;
    u8 taskDataCursorPos;
    u8 taskDataScrollOffset;
    u16 numOptions;
};

struct SearchMenuTopBarItem
{
    const u8 *description;
    u8 highlightX;
    u8 highlightY;
    u8 highlightWidth;
};

struct SearchMenuItem
{
    const u8 *description;
    u8 titleBgX;
    u8 titleBgY;
    u8 titleBgWidth;
    u8 selectionBgX;
    u8 selectionBgY;
    u8 selectionBgWidth;
};

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 selectedPokemonBackup;
    u16 dexMode;
    u16 dexModeBackup;
    u16 dexOrder;
    u16 dexOrderBackup;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 selectedMonSpriteId;
    u16 pokeBallRotationStep;
    u16 pokeBallRotationBackup;
    u8 pokeBallRotation;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u16 unkArr1[4]; // Cleared, never read
    u8 filler[8];
    u8 currentPage;
    u8 currentPageBackup;
    bool8 isSearchResults:1;
    u8 selectedScreen;
    u8 screenSwitchState;
    u8 menuIsOpen;
    u16 menuCursorPos;
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unkArr2[8]; // Cleared, never read
    u8 unkArr3[8]; // Cleared, never read
};

// this file's functions
static void CB2_Pokedex(void);
static void Task_OpenPokedexMainPage(u8);
static void Task_HandlePokedexInput(u8);
static void Task_WaitForScroll(u8);
static void Task_HandlePokedexStartMenuInput(u8);
static void Task_OpenInfoScreenAfterMonMovement(u8);
static void Task_WaitForExitInfoScreen(u8);
static void Task_WaitForExitSearch(u8);
static void Task_ClosePokedex(u8);
static void Task_OpenSearchResults(u8);
static void Task_HandleSearchResultsInput(u8);
static void Task_WaitForSearchResultsScroll(u8);
static void Task_HandleSearchResultsStartMenuInput(u8);
static void Task_OpenSearchResultsInfoScreenAfterMonMovement(u8);
static void Task_WaitForExitSearchResultsInfoScreen(u8);
static void Task_ReturnToPokedexFromSearchResults(u8);
static void Task_ClosePokedexFromSearchResultsStartMenu(u8);
static bool8 LoadPokedexListPage(u8);
static void LoadPokedexBgPalette(bool8);
static void FreeWindowAndBgBuffers(void);
static void CreatePokedexList(u8, u8);
static void CreateMonDexNum(u16, u8, u8, u16);
static void CreateCaughtBall(u16, u8, u8, u16);
static u8 CreateMonName(u16, u8, u8);
static void ClearMonListEntry(u8 x, u8 y, u16 unused);
static void CreateMonSpritesAtPos(u16, u16);
static bool8 UpdateDexListScroll(u8, u8, u8);
static u16 TryDoPokedexScroll(u16, u16);
static void UpdateSelectedMonSpriteId(void);
static bool8 TryDoInfoScreenScroll(void);
static u8 ClearMonSprites(void);
static u16 GetPokemonSpriteToDisplay(u16);
static u32 CreatePokedexMonSprite(u16, s16, s16);
static void CreateInterfaceSprites(u8);
static void SpriteCB_MoveMonForInfoScreen(struct Sprite *sprite);
static void SpriteCB_Scrollbar(struct Sprite *sprite);
static void SpriteCB_ScrollArrow(struct Sprite *sprite);
static void SpriteCB_DexListInterfaceText(struct Sprite *sprite);
static void SpriteCB_RotatingPokeBall(struct Sprite *sprite);
static void SpriteCB_SeenOwnInfo(struct Sprite *sprite);
static void SpriteCB_DexListStartMenuCursor(struct Sprite *sprite);
static void SpriteCB_PokedexListMonSprite(struct Sprite *sprite);
static u8 LoadInfoScreen(struct PokedexListItem *, u8 monSpriteId);
static bool8 IsInfoScreenScrolling(u8);
static u8 StartInfoScreenScroll(struct PokedexListItem *, u8);
static void Task_LoadInfoScreen(u8);
static void Task_HandleInfoScreenInput(u8);
static void Task_SwitchScreensFromInfoScreen(u8);
static void Task_LoadInfoScreenWaitForFade(u8);
static void Task_ExitInfoScreen(u8);
static void Task_LoadAreaScreen(u8);
static void Task_WaitForAreaScreenInput(u8 taskId);
static void Task_SwitchScreensFromAreaScreen(u8);
static void Task_LoadCryScreen(u8);
static void Task_HandleCryScreenInput(u8);
static void Task_SwitchScreensFromCryScreen(u8);
static void LoadPlayArrowPalette(bool8);
static void Task_LoadSizeScreen(u8);
static void Task_HandleSizeScreenInput(u8);
static void Task_SwitchScreensFromSizeScreen(u8);
static void LoadScreenSelectBarMain(u16);
static void LoadScreenSelectBarSubmenu(u16);
static void HighlightScreenSelectBarItem(u8, u16);
static void HighlightSubmenuScreenSelectBarItem(u8, u16);
static void Task_DisplayCaughtMonDexPage(u8);
static void Task_HandleCaughtMonPageInput(u8);
static void Task_ExitCaughtMonPage(u8);
static void SpriteCB_SlideCaughtMonToCenter(struct Sprite *sprite);
static void PrintMonInfo(u32 num, u32, u32 owned, u32 newEntry);
static void PrintMonHeight(u16 height, u8 left, u8 top);
static void PrintMonWeight(u16 weight, u8 left, u8 top);
static void ResetOtherVideoRegisters(u16);
static u8 PrintCryScreenSpeciesName(u8, u16, u8, u8);
static void PrintDecimalNum(u8 windowId, u16 num, u8 left, u8 top);
static void DrawFootprint(u8 windowId, u16 dexNum);
static u16 CreateSizeScreenTrainerPic(u16, s16, s16, s8);
static u16 GetNextPosition(u8, u16, u16, u16);
static u8 LoadSearchMenu(void);
static void Task_LoadSearchMenu(u8);
static void Task_SwitchToSearchMenuTopBar(u8);
static void Task_HandleSearchTopBarInput(u8);
static void Task_SwitchToSearchMenu(u8);
static void Task_HandleSearchMenuInput(u8);
static void Task_StartPokedexSearch(u8);
static void Task_WaitAndCompleteSearch(u8);
static void Task_SearchCompleteWaitForInput(u8);
static void Task_SelectSearchMenuItem(u8);
static void Task_HandleSearchParameterInput(u8);
static void Task_ExitSearch(u8);
static void Task_ExitSearchWaitForFade(u8);
static void HighlightSelectedSearchTopBarItem(u8);
static void HighlightSelectedSearchMenuItem(u8, u8);
static void PrintSelectedSearchParameters(u8);
static void DrawOrEraseSearchParameterBox(bool8);
static void PrintSearchParameterText(u8);
static u8 GetSearchModeSelection(u8 taskId, u8 option);
static void SetDefaultSearchModeAndOrder(u8);
static void CreateSearchParameterScrollArrows(u8);
static void EraseAndPrintSearchTextBox(const u8 *);
static void EraseSelectorArrow(u32);
static void PrintSelectorArrow(u32);
static void PrintSearchParameterTitle(u32, const u8 *);
static void ClearSearchParameterBoxText(void);

// const rom data
#include "data/pokemon/pokedex_orders.h"

static const struct OamData sOamData_ScrollBar =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_ScrollArrow =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

static const struct OamData sOamData_InterfaceText =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_RotatingPokeBall =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_WINDOW,
    .mosaic = FALSE,
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

static const struct OamData sOamData_SeenOwnText =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Dex8x16 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_ScrollBar[] =
{
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_ScrollArrow[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_RotatingPokeBall[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StartButton[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SearchText[] =
{
    ANIMCMD_FRAME(40, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SelectButton[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_MenuText[] =
{
    ANIMCMD_FRAME(56, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SeenText[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_OwnText[] =
{
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennText[] =
{
    ANIMCMD_FRAME(160, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalText[] =
{
    ANIMCMD_FRAME(168, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit0[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit1[] =
{
    ANIMCMD_FRAME(130, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit2[] =
{
    ANIMCMD_FRAME(132, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit3[] =
{
    ANIMCMD_FRAME(134, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit4[] =
{
    ANIMCMD_FRAME(136, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit5[] =
{
    ANIMCMD_FRAME(138, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit6[] =
{
    ANIMCMD_FRAME(140, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit7[] =
{
    ANIMCMD_FRAME(142, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit8[] =
{
    ANIMCMD_FRAME(144, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_HoennSeenOwnDigit9[] =
{
    ANIMCMD_FRAME(146, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit0[] =
{
    ANIMCMD_FRAME(176, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit1[] =
{
    ANIMCMD_FRAME(178, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit2[] =
{
    ANIMCMD_FRAME(180, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit3[] =
{
    ANIMCMD_FRAME(182, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit4[] =
{
    ANIMCMD_FRAME(184, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit5[] =
{
    ANIMCMD_FRAME(186, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit6[] =
{
    ANIMCMD_FRAME(188, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit7[] =
{
    ANIMCMD_FRAME(190, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit8[] =
{
    ANIMCMD_FRAME(192, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_NationalSeenOwnDigit9[] =
{
    ANIMCMD_FRAME(194, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_DexListStartMenuCursor[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_ScrollBar[] =
{
    sSpriteAnim_ScrollBar
};

static const union AnimCmd *const sSpriteAnimTable_ScrollArrow[] =
{
    sSpriteAnim_ScrollArrow
};

static const union AnimCmd *const sSpriteAnimTable_RotatingPokeBall[] =
{
    sSpriteAnim_RotatingPokeBall
};

static const union AnimCmd *const sSpriteAnimTable_InterfaceText[] =
{
    sSpriteAnim_StartButton,
    sSpriteAnim_SearchText,
    sSpriteAnim_SelectButton,
    sSpriteAnim_MenuText
};

static const union AnimCmd *const sSpriteAnimTable_SeenOwnText[] =
{
    sSpriteAnim_SeenText,
    sSpriteAnim_OwnText
};

static const union AnimCmd *const sSpriteAnimTable_HoennNationalText[] =
{
    sSpriteAnim_HoennText,
    sSpriteAnim_NationalText
};

static const union AnimCmd *const sSpriteAnimTable_HoennSeenOwnNumber[] =
{
    sSpriteAnim_HoennSeenOwnDigit0,
    sSpriteAnim_HoennSeenOwnDigit1,
    sSpriteAnim_HoennSeenOwnDigit2,
    sSpriteAnim_HoennSeenOwnDigit3,
    sSpriteAnim_HoennSeenOwnDigit4,
    sSpriteAnim_HoennSeenOwnDigit5,
    sSpriteAnim_HoennSeenOwnDigit6,
    sSpriteAnim_HoennSeenOwnDigit7,
    sSpriteAnim_HoennSeenOwnDigit8,
    sSpriteAnim_HoennSeenOwnDigit9
};

static const union AnimCmd *const sSpriteAnimTable_NationalSeenOwnNumber[] =
{
    sSpriteAnim_NationalSeenOwnDigit0,
    sSpriteAnim_NationalSeenOwnDigit1,
    sSpriteAnim_NationalSeenOwnDigit2,
    sSpriteAnim_NationalSeenOwnDigit3,
    sSpriteAnim_NationalSeenOwnDigit4,
    sSpriteAnim_NationalSeenOwnDigit5,
    sSpriteAnim_NationalSeenOwnDigit6,
    sSpriteAnim_NationalSeenOwnDigit7,
    sSpriteAnim_NationalSeenOwnDigit8,
    sSpriteAnim_NationalSeenOwnDigit9
};

static const union AnimCmd *const sSpriteAnimTable_DexListStartMenuCursor[] =
{
    sSpriteAnim_DexListStartMenuCursor
};

#define TAG_DEX_INTERFACE 4096 // Tile and pal tag used for all interface sprites.

static const struct SpriteTemplate sScrollBarSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_ScrollBar,
    .anims = sSpriteAnimTable_ScrollBar,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Scrollbar,
};

static const struct SpriteTemplate sScrollArrowSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_ScrollArrow,
    .anims = sSpriteAnimTable_ScrollArrow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScrollArrow,
};

static const struct SpriteTemplate sInterfaceTextSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_InterfaceText,
    .anims = sSpriteAnimTable_InterfaceText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_DexListInterfaceText,
};

static const struct SpriteTemplate sRotatingPokeBallSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_RotatingPokeBall,
    .anims = sSpriteAnimTable_RotatingPokeBall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RotatingPokeBall,
};

static const struct SpriteTemplate sSeenOwnTextSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_SeenOwnText,
    .anims = sSpriteAnimTable_SeenOwnText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SeenOwnInfo,
};

static const struct SpriteTemplate sHoennNationalTextSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_InterfaceText,
    .anims = sSpriteAnimTable_HoennNationalText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SeenOwnInfo,
};

static const struct SpriteTemplate sHoennDexSeenOwnNumberSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_Dex8x16,
    .anims = sSpriteAnimTable_HoennSeenOwnNumber,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SeenOwnInfo,
};

static const struct SpriteTemplate sNationalDexSeenOwnNumberSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_Dex8x16,
    .anims = sSpriteAnimTable_NationalSeenOwnNumber,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SeenOwnInfo,
};

static const struct SpriteTemplate sDexListStartMenuCursorSpriteTemplate =
{
    .tileTag = TAG_DEX_INTERFACE,
    .paletteTag = TAG_DEX_INTERFACE,
    .oam = &sOamData_Dex8x16,
    .anims = sSpriteAnimTable_DexListStartMenuCursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_DexListStartMenuCursor,
};

static const struct CompressedSpriteSheet sInterfaceSpriteSheet[] =
{
    {gPokedexInterface_Gfx, 0x2000, TAG_DEX_INTERFACE},
    {0}
};

static const struct SpritePalette sInterfaceSpritePalette[] =
{
    {gPokedexBgHoenn_Pal, TAG_DEX_INTERFACE},
    {0}
};

// By scroll speed. Last element of each unused
static const u8 sScrollMonIncrements[] = {4, 8, 16, 32, 32};
static const u8 sScrollTimers[] = {8, 4, 2, 1, 1};

static const struct BgTemplate sPokedex_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sPokemonList_WindowTemplate[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 32,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_No000[] = _("{NO}000");
static const u8 sCaughtBall_Gfx[] = INCBIN_U8("graphics/pokedex/caught_ball.4bpp");
static const u8 sText_TenDashes[] = _("----------");

ALIGNED(4) static const u8 sExpandedPlaceholder_PokedexDescription[] = _("");

#include "data/pokemon/pokedex_text.h"
#include "data/pokemon/pokedex_entries.h"

static const u16 sSizeScreenSilhouette_Pal[] = INCBIN_U16("graphics/pokedex/size_silhouette.gbapal");

static const struct BgTemplate sInfoScreen_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

#define WIN_INFO 0
#define WIN_FOOTPRINT 1
#define WIN_CRY_WAVE 2
#define WIN_VU_METER 3

static const struct WindowTemplate sInfoScreen_WindowTemplates[] =
{
    [WIN_INFO] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    [WIN_FOOTPRINT] =
    {
        .bg = 2,
        .tilemapLeft = 25,
        .tilemapTop = 8,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 641,
    },
    [WIN_CRY_WAVE] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 12,
        .width = 32,
        .height = 7,
        .paletteNum = 8,
        .baseBlock = 645,
    },
    [WIN_VU_METER] =
    {
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 3,
        .width = 10,
        .height = 8,
        .paletteNum = 9,
        .baseBlock = 869,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sNewEntryInfoScreen_BgTemplate[] =
{
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sNewEntryInfoScreen_WindowTemplates[] =
{
    [WIN_INFO] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    [WIN_FOOTPRINT] =
    {
        .bg = 2,
        .tilemapLeft = 25,
        .tilemapTop = 8,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 641,
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sText_TenDashes2[] = _("----------");

#include "data/pokemon_graphics/footprint_table.h"

// First character in range followed by number of characters in range for upper and lowercase
static const u8 sLetterSearchRanges[][4] =
{
    {}, // Name not specified, shouldn't be reached
    [NAME_ABC] = {CHAR_A, 3, CHAR_a, 3},
    [NAME_DEF] = {CHAR_D, 3, CHAR_d, 3},
    [NAME_GHI] = {CHAR_G, 3, CHAR_g, 3},
    [NAME_JKL] = {CHAR_J, 3, CHAR_j, 3},
    [NAME_MNO] = {CHAR_M, 3, CHAR_m, 3},
    [NAME_PQR] = {CHAR_P, 3, CHAR_p, 3},
    [NAME_STU] = {CHAR_S, 3, CHAR_s, 3},
    [NAME_VWX] = {CHAR_V, 3, CHAR_v, 3},
    [NAME_YZ]  = {CHAR_Y, 2, CHAR_y, 2},
};

#define LETTER_IN_RANGE_UPPER(letter, range) \
    ((letter) >= sLetterSearchRanges[range][0]                                  \
  && (letter) < sLetterSearchRanges[range][0] + sLetterSearchRanges[range][1])  \

#define LETTER_IN_RANGE_LOWER(letter, range) \
    ((letter) >= sLetterSearchRanges[range][2]                                  \
  && (letter) < sLetterSearchRanges[range][2] + sLetterSearchRanges[range][3])  \

static const struct SearchMenuTopBarItem sSearchMenuTopBarItems[SEARCH_TOPBAR_COUNT] =
{
    [SEARCH_TOPBAR_SEARCH] =
    {
        .description = gText_SearchForPkmnBasedOnParameters,
        .highlightX = 0,
        .highlightY = 0,
        .highlightWidth = 5,
    },
    [SEARCH_TOPBAR_SHIFT] =
    {
        .description = gText_SwitchPokedexListings,
        .highlightX = 6,
        .highlightY = 0,
        .highlightWidth = 5,
    },
    [SEARCH_TOPBAR_CANCEL] =
    {
        .description = gText_ReturnToPokedex,
        .highlightX = 12,
        .highlightY = 0,
        .highlightWidth = 5,
    },
};

static const struct SearchMenuItem sSearchMenuItems[SEARCH_COUNT] =
{
    [SEARCH_NAME] =
    {
        .description = gText_ListByFirstLetter,
        .titleBgX = 0,
        .titleBgY = 2,
        .titleBgWidth = 5,
        .selectionBgX = 5,
        .selectionBgY = 2,
        .selectionBgWidth = 12,
    },
    [SEARCH_COLOR] =
    {
        .description = gText_ListByBodyColor,
        .titleBgX = 0,
        .titleBgY = 4,
        .titleBgWidth = 5,
        .selectionBgX = 5,
        .selectionBgY = 4,
        .selectionBgWidth = 12,
    },
    [SEARCH_TYPE_LEFT] =
    {
        .description = gText_ListByType,
        .titleBgX = 0,
        .titleBgY = 6,
        .titleBgWidth = 5,
        .selectionBgX = 5,
        .selectionBgY = 6,
        .selectionBgWidth = 6,
    },
    [SEARCH_TYPE_RIGHT] =
    {
        .description = gText_ListByType,
        .titleBgX = 0,
        .titleBgY = 6,
        .titleBgWidth = 5,
        .selectionBgX = 11,
        .selectionBgY = 6,
        .selectionBgWidth = 6,
    },
    [SEARCH_ORDER] =
    {
        .description = gText_SelectPokedexListingMode,
        .titleBgX = 0,
        .titleBgY = 8,
        .titleBgWidth = 5,
        .selectionBgX = 5,
        .selectionBgY = 8,
        .selectionBgWidth = 12,
    },
    [SEARCH_MODE] =
    {
        .description = gText_SelectPokedexMode,
        .titleBgX = 0,
        .titleBgY = 10,
        .titleBgWidth = 5,
        .selectionBgX = 5,
        .selectionBgY = 10,
        .selectionBgWidth = 12,
    },
    [SEARCH_OK] =
    {
        .description = gText_ExecuteSearchSwitch,
        .titleBgX = 0,
        .titleBgY = 12,
        .titleBgWidth = 5,
        .selectionBgX = 0,
        .selectionBgY = 0,
        .selectionBgWidth = 0,
    },
};

// Left, Right, Up, Down
static const u8 sSearchMovementMap_SearchNatDex[SEARCH_COUNT][4] =
{
    [SEARCH_NAME] =
    {
        0xFF,
        0xFF,
        0xFF,
        SEARCH_COLOR
    },
    [SEARCH_COLOR] =
    {
        0xFF,
        0xFF,
        SEARCH_NAME,
        SEARCH_TYPE_LEFT
    },
    [SEARCH_TYPE_LEFT] =
    {
        0xFF,
        SEARCH_TYPE_RIGHT,
        SEARCH_COLOR,
        SEARCH_ORDER
    },
    [SEARCH_TYPE_RIGHT] =
    {   SEARCH_TYPE_LEFT,
        0xFF,
        SEARCH_COLOR,
        SEARCH_ORDER
    },
    [SEARCH_ORDER] =
    {
        0xFF,
        0xFF,
        SEARCH_TYPE_LEFT,
        SEARCH_MODE
    },
    [SEARCH_MODE] =
    {
        0xFF,
        0xFF,
        SEARCH_ORDER,
        SEARCH_OK
    },
    [SEARCH_OK] =
    {
        0xFF,
        0xFF,
        SEARCH_MODE,
        0xFF
    },
};

// Left, Right, Up, Down
static const u8 sSearchMovementMap_ShiftNatDex[SEARCH_COUNT][4] =
{
    [SEARCH_NAME] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_COLOR] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_TYPE_LEFT] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_TYPE_RIGHT] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_ORDER] =
    {
        0xFF,
        0xFF,
        0xFF,
        SEARCH_MODE
    },
    [SEARCH_MODE] =
    {
        0xFF,
        0xFF,
        SEARCH_ORDER,
        SEARCH_OK
    },
    [SEARCH_OK] =
    {
        0xFF,
        0xFF,
        SEARCH_MODE,
        0xFF
    },
};

// Left, Right, Up, Down
static const u8 sSearchMovementMap_SearchHoennDex[SEARCH_COUNT][4] =
{
    [SEARCH_NAME] =
    {
        0xFF,
        0xFF,
        0xFF,
        SEARCH_COLOR
    },
    [SEARCH_COLOR] =
    {
        0xFF,
        0xFF,
        SEARCH_NAME,
        SEARCH_TYPE_LEFT
    },
    [SEARCH_TYPE_LEFT] =
    {
        0xFF,
        SEARCH_TYPE_RIGHT,
        SEARCH_COLOR,
        SEARCH_ORDER
    },
    [SEARCH_TYPE_RIGHT] =
    {   SEARCH_TYPE_LEFT,
        0xFF,
        SEARCH_COLOR,
        SEARCH_ORDER
    },
    [SEARCH_ORDER] =
    {
        0xFF,
        0xFF,
        SEARCH_TYPE_LEFT,
        SEARCH_OK
    },
    [SEARCH_MODE] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_OK] =
    {
        0xFF,
        0xFF,
        SEARCH_ORDER,
        0xFF
    },
};

// Left, Right, Up, Down
static const u8 sSearchMovementMap_ShiftHoennDex[SEARCH_COUNT][4] =
{
    [SEARCH_NAME] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_COLOR] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_TYPE_LEFT] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_TYPE_RIGHT] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_ORDER] =
    {
        0xFF,
        0xFF,
        0xFF,
        SEARCH_OK
    },
    [SEARCH_MODE] =
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    },
    [SEARCH_OK] =
    {
        0xFF,
        0xFF,
        SEARCH_ORDER,
        0xFF
    },
};

static const struct SearchOptionText sDexModeOptions[] =
{
    [DEX_MODE_HOENN]    = {gText_DexHoennDescription, gText_DexHoennTitle},
    [DEX_MODE_NATIONAL] = {gText_DexNatDescription,   gText_DexNatTitle},
    {},
};

static const struct SearchOptionText sDexOrderOptions[] =
{
    [ORDER_NUMERICAL]    = {gText_DexSortNumericalDescription, gText_DexSortNumericalTitle},
    [ORDER_ALPHABETICAL] = {gText_DexSortAtoZDescription,      gText_DexSortAtoZTitle},
    [ORDER_HEAVIEST]     = {gText_DexSortHeaviestDescription,  gText_DexSortHeaviestTitle},
    [ORDER_LIGHTEST]     = {gText_DexSortLightestDescription,  gText_DexSortLightestTitle},
    [ORDER_TALLEST]      = {gText_DexSortTallestDescription,   gText_DexSortTallestTitle},
    [ORDER_SMALLEST]     = {gText_DexSortSmallestDescription,  gText_DexSortSmallestTitle},
    {},
};

static const struct SearchOptionText sDexSearchNameOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    [NAME_ABC] = {gText_DexEmptyString, gText_DexSearchAlphaABC},
    [NAME_DEF] = {gText_DexEmptyString, gText_DexSearchAlphaDEF},
    [NAME_GHI] = {gText_DexEmptyString, gText_DexSearchAlphaGHI},
    [NAME_JKL] = {gText_DexEmptyString, gText_DexSearchAlphaJKL},
    [NAME_MNO] = {gText_DexEmptyString, gText_DexSearchAlphaMNO},
    [NAME_PQR] = {gText_DexEmptyString, gText_DexSearchAlphaPQR},
    [NAME_STU] = {gText_DexEmptyString, gText_DexSearchAlphaSTU},
    [NAME_VWX] = {gText_DexEmptyString, gText_DexSearchAlphaVWX},
    [NAME_YZ]  = {gText_DexEmptyString, gText_DexSearchAlphaYZ},
    {},
};

static const struct SearchOptionText sDexSearchColorOptions[] =
{
    {gText_DexEmptyString, gText_DexSearchDontSpecify},
    [BODY_COLOR_RED + 1]    = {gText_DexEmptyString, gText_DexSearchColorRed},
    [BODY_COLOR_BLUE + 1]   = {gText_DexEmptyString, gText_DexSearchColorBlue},
    [BODY_COLOR_YELLOW + 1] = {gText_DexEmptyString, gText_DexSearchColorYellow},
    [BODY_COLOR_GREEN + 1]  = {gText_DexEmptyString, gText_DexSearchColorGreen},
    [BODY_COLOR_BLACK + 1]  = {gText_DexEmptyString, gText_DexSearchColorBlack},
    [BODY_COLOR_BROWN + 1]  = {gText_DexEmptyString, gText_DexSearchColorBrown},
    [BODY_COLOR_PURPLE + 1] = {gText_DexEmptyString, gText_DexSearchColorPurple},
    [BODY_COLOR_GRAY + 1]   = {gText_DexEmptyString, gText_DexSearchColorGray},
    [BODY_COLOR_WHITE + 1]  = {gText_DexEmptyString, gText_DexSearchColorWhite},
    [BODY_COLOR_PINK + 1]   = {gText_DexEmptyString, gText_DexSearchColorPink},
    {},
};

static const struct SearchOptionText sDexSearchTypeOptions[NUMBER_OF_MON_TYPES + 1] = // + 2 for "None" and terminator, - 1 for Mystery
{
    {gText_DexEmptyString, gText_DexSearchTypeNone},
    {gText_DexEmptyString, gTypeNames[TYPE_NORMAL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIGHTING]},
    {gText_DexEmptyString, gTypeNames[TYPE_FLYING]},
    {gText_DexEmptyString, gTypeNames[TYPE_POISON]},
    {gText_DexEmptyString, gTypeNames[TYPE_GROUND]},
    {gText_DexEmptyString, gTypeNames[TYPE_ROCK]},
    {gText_DexEmptyString, gTypeNames[TYPE_BUG]},
    {gText_DexEmptyString, gTypeNames[TYPE_GHOST]},
    {gText_DexEmptyString, gTypeNames[TYPE_STEEL]},
    {gText_DexEmptyString, gTypeNames[TYPE_FIRE]},
    {gText_DexEmptyString, gTypeNames[TYPE_WATER]},
    {gText_DexEmptyString, gTypeNames[TYPE_GRASS]},
    {gText_DexEmptyString, gTypeNames[TYPE_ELECTRIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_PSYCHIC]},
    {gText_DexEmptyString, gTypeNames[TYPE_ICE]},
    {gText_DexEmptyString, gTypeNames[TYPE_DRAGON]},
    {gText_DexEmptyString, gTypeNames[TYPE_DARK]},
    {gText_DexEmptyString, gTypeNames[TYPE_FAIRY]},
    {},
};

static const u8 sPokedexModes[] = {DEX_MODE_HOENN, DEX_MODE_NATIONAL};
static const u8 sOrderOptions[] =
{
    ORDER_NUMERICAL,
    ORDER_ALPHABETICAL,
    ORDER_HEAVIEST,
    ORDER_LIGHTEST,
    ORDER_TALLEST,
    ORDER_SMALLEST,
};

static const u8 sDexSearchTypeIds[NUMBER_OF_MON_TYPES] =
{
    TYPE_NONE,
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_FAIRY,
};

// Number pairs are the task data for tracking the cursor pos and scroll offset of each option list
// See task data defines above Task_LoadSearchMenu
static const struct SearchOption sSearchOptions[] =
{
    [SEARCH_NAME]       = {sDexSearchNameOptions,  6,  7, ARRAY_COUNT(sDexSearchNameOptions) - 1},
    [SEARCH_COLOR]      = {sDexSearchColorOptions, 8,  9, ARRAY_COUNT(sDexSearchColorOptions) - 1},
    [SEARCH_TYPE_LEFT]  = {sDexSearchTypeOptions, 10, 11, ARRAY_COUNT(sDexSearchTypeOptions) - 1},
    [SEARCH_TYPE_RIGHT] = {sDexSearchTypeOptions, 12, 13, ARRAY_COUNT(sDexSearchTypeOptions) - 1},
    [SEARCH_ORDER]      = {sDexOrderOptions,       4,  5, ARRAY_COUNT(sDexOrderOptions) - 1},
    [SEARCH_MODE]       = {sDexModeOptions,        2,  3, ARRAY_COUNT(sDexModeOptions) - 1},
};

static const struct BgTemplate sSearchMenu_BgTemplate[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sSearchMenu_WindowTemplate[] =
{
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 0x0001,
    },
    DUMMY_WIN_TEMPLATE
};

// .text

void ResetPokedex(void)
{
    u16 i;

    sLastSelectedPokemon = 0;
    sPokeBallRotation = POKEBALL_ROTATION_TOP;
    gUnusedPokedexU8 = 0;
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
    gSaveBlock2Ptr->pokedex.order = 0;
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    gSaveBlock2Ptr->pokedex.unknown2 = 0;
    gSaveBlock2Ptr->pokedex.unownPersonality = 0;
    gSaveBlock2Ptr->pokedex.spindaPersonality = 0;
    gSaveBlock2Ptr->pokedex.unknown3 = 0;
    DisableNationalPokedex();
    for (i = 0; i < NUM_DEX_FLAG_BYTES; i++)
    {
        gSaveBlock1Ptr->dexCaught[i] = 0;
        gSaveBlock1Ptr->dexSeen[i] = 0;
    }
}

void ResetPokedexScrollPositions(void)
{
    sLastSelectedPokemon = 0;
    sPokeBallRotation = POKEBALL_ROTATION_TOP;
}

static void VBlankCB_Pokedex(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ResetPokedexView(struct PokedexView *pokedexView)
{
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        pokedexView->pokedexList[i].dexNum = 0xFFFF;
        pokedexView->pokedexList[i].seen = FALSE;
        pokedexView->pokedexList[i].owned = FALSE;
    }
    pokedexView->pokedexList[NATIONAL_DEX_COUNT].dexNum = 0;
    pokedexView->pokedexList[NATIONAL_DEX_COUNT].seen = FALSE;
    pokedexView->pokedexList[NATIONAL_DEX_COUNT].owned = FALSE;
    pokedexView->pokemonListCount = 0;
    pokedexView->selectedPokemon = 0;
    pokedexView->selectedPokemonBackup = 0;
    pokedexView->dexMode = DEX_MODE_HOENN;
    pokedexView->dexModeBackup = DEX_MODE_HOENN;
    pokedexView->dexOrder = ORDER_NUMERICAL;
    pokedexView->dexOrderBackup = ORDER_NUMERICAL;
    pokedexView->seenCount = 0;
    pokedexView->ownCount = 0;
    for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
        pokedexView->monSpriteIds[i] = 0xFFFF;
    pokedexView->pokeBallRotationStep = 0;
    pokedexView->pokeBallRotationBackup = 0;
    pokedexView->pokeBallRotation = 0;
    pokedexView->initialVOffset = 0;
    pokedexView->scrollTimer = 0;
    pokedexView->scrollDirection = 0;
    pokedexView->listVOffset = 0;
    pokedexView->listMovingVOffset = 0;
    pokedexView->scrollMonIncrement = 0;
    pokedexView->maxScrollTimer = 0;
    pokedexView->scrollSpeed = 0;
    for (i = 0; i < ARRAY_COUNT(pokedexView->unkArr1); i++)
        pokedexView->unkArr1[i] = 0;
    pokedexView->currentPage = PAGE_MAIN;
    pokedexView->currentPageBackup = PAGE_MAIN;
    pokedexView->isSearchResults = FALSE;
    pokedexView->selectedScreen = AREA_SCREEN;
    pokedexView->screenSwitchState = 0;
    pokedexView->menuIsOpen = 0;
    pokedexView->menuCursorPos = 0;
    pokedexView->menuY = 0;
    for (i = 0; i < ARRAY_COUNT(pokedexView->unkArr2); i++)
        pokedexView->unkArr2[i] = 0;
    for (i = 0; i < ARRAY_COUNT(pokedexView->unkArr3); i++)
        pokedexView->unkArr3[i] = 0;
}

void CB2_OpenPokedex(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        ResetOtherVideoRegisters(0);
        DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        ResetAllPicSprites();
        gMain.state++;
        break;
    case 2:
        sPokedexView = AllocZeroed(sizeof(struct PokedexView));
        ResetPokedexView(sPokedexView);
        CreateTask(Task_OpenPokedexMainPage, 0);
        sPokedexView->dexMode = gSaveBlock2Ptr->pokedex.mode;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = gSaveBlock2Ptr->pokedex.order;
        sPokedexView->selectedPokemon = sLastSelectedPokemon;
        sPokedexView->pokeBallRotation = sPokeBallRotation;
        sPokedexView->selectedScreen = AREA_SCREEN;
        if (!IsNationalPokedexEnabled())
        {
            sPokedexView->seenCount = GetHoennPokedexCount(FLAG_GET_SEEN);
            sPokedexView->ownCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
        }
        else
        {
            sPokedexView->seenCount = GetNationalPokedexCount(FLAG_GET_SEEN);
            sPokedexView->ownCount = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        }
        sPokedexView->initialVOffset = 8;
        gMain.state++;
        break;
    case 3:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB_Pokedex);
        SetMainCallback2(CB2_Pokedex);
        CreatePokedexList(sPokedexView->dexMode, sPokedexView->dexOrder);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x80);
        break;
    }
}

static void CB2_Pokedex(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void Task_OpenPokedexMainPage(u8 taskId)
{
    sPokedexView->isSearchResults = FALSE;
    if (LoadPokedexListPage(PAGE_MAIN))
        gTasks[taskId].func = Task_HandlePokedexInput;
}

#define tLoadScreenTaskId data[0]

static void Task_HandlePokedexInput(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
    }
    else
    {
        if (JOY_NEW(A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            UpdateSelectedMonSpriteId();
            BeginNormalPaletteFade(~(1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16)), 0, 0, 0x10, RGB_BLACK);
            gSprites[sPokedexView->selectedMonSpriteId].callback = SpriteCB_MoveMonForInfoScreen;
            gTasks[taskId].func = Task_OpenInfoScreenAfterMonMovement;
            PlaySE(SE_PIN);
            FreeWindowAndBgBuffers();
        }
        else if (JOY_NEW(START_BUTTON))
        {
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = TRUE;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = Task_HandlePokedexStartMenuInput;
            PlaySE(SE_SELECT);
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].tLoadScreenTaskId = LoadSearchMenu();
            sPokedexView->screenSwitchState = 0;
            sPokedexView->pokeBallRotationBackup = sPokedexView->pokeBallRotation;
            sPokedexView->selectedPokemonBackup = sPokedexView->selectedPokemon;
            sPokedexView->dexModeBackup = sPokedexView->dexMode;
            sPokedexView->dexOrderBackup = sPokedexView->dexOrder;
            gTasks[taskId].func = Task_WaitForExitSearch;
            PlaySE(SE_PC_LOGIN);
            FreeWindowAndBgBuffers();
        }
        else if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_ClosePokedex;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = TryDoPokedexScroll(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->scrollTimer)
                gTasks[taskId].func = Task_WaitForScroll;
        }
    }
}

static void Task_WaitForScroll(u8 taskId)
{
    if (UpdateDexListScroll(sPokedexView->scrollDirection, sPokedexView->scrollMonIncrement, sPokedexView->maxScrollTimer))
        gTasks[taskId].func = Task_HandlePokedexInput;
}

static void Task_HandlePokedexStartMenuInput(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    //If menu is not open, slide it up, on screen
    if (sPokedexView->menuY != 80)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            switch (sPokedexView->menuCursorPos)
            {
            case 0: //BACK TO LIST
            default:
                gMain.newKeys |= START_BUTTON;  //Exit menu
                break;
            case 1: //LIST TOP
                sPokedexView->selectedPokemon = 0;
                sPokedexView->pokeBallRotation = POKEBALL_ROTATION_TOP;
                ClearMonSprites();
                CreateMonSpritesAtPos(sPokedexView->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;  //Exit menu
                break;
            case 2: //LIST BOTTOM
                sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                sPokedexView->pokeBallRotation = sPokedexView->pokemonListCount * 16 + POKEBALL_ROTATION_BOTTOM;
                ClearMonSprites();
                CreateMonSpritesAtPos(sPokedexView->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;  //Exit menu
                break;
            case 3: //CLOSE POKEDEX
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = Task_ClosePokedex;
                PlaySE(SE_PC_OFF);
                break;
            }
        }

        //Exit menu when Start or B is pressed
        if (JOY_NEW(START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = FALSE;
            gTasks[taskId].func = Task_HandlePokedexInput;
            PlaySE(SE_SELECT);
        }
        else if (JOY_REPEAT(DPAD_UP) && sPokedexView->menuCursorPos != 0)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if (JOY_REPEAT(DPAD_DOWN) && sPokedexView->menuCursorPos < 3)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

// Opening the info screen from list view. Pokémon sprite is moving to its new position, wait for it to arrive
static void Task_OpenInfoScreenAfterMonMovement(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].x == MON_PAGE_X && gSprites[sPokedexView->selectedMonSpriteId].y == MON_PAGE_Y)
    {
        sPokedexView->currentPageBackup = sPokedexView->currentPage;
        gTasks[taskId].tLoadScreenTaskId = LoadInfoScreen(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        gTasks[taskId].func = Task_WaitForExitInfoScreen;
    }
}

static void Task_WaitForExitInfoScreen(u8 taskId)
{
    if (gTasks[gTasks[taskId].tLoadScreenTaskId].isActive)
    {
        // While active, handle scroll input
        if (sPokedexView->currentPage == PAGE_INFO && !IsInfoScreenScrolling(gTasks[taskId].tLoadScreenTaskId) && TryDoInfoScreenScroll())
            StartInfoScreenScroll(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].tLoadScreenTaskId);
    }
    else
    {
        // Exiting, back to list view
        sLastSelectedPokemon = sPokedexView->selectedPokemon;
        sPokeBallRotation = sPokedexView->pokeBallRotation;
        gTasks[taskId].func = Task_OpenPokedexMainPage;
    }
}

static void Task_WaitForExitSearch(u8 taskId)
{
    if (!gTasks[gTasks[taskId].tLoadScreenTaskId].isActive)
    {
        ClearMonSprites();

        // Search produced results
        if (sPokedexView->screenSwitchState != 0)
        {
            sPokedexView->selectedPokemon = 0;
            sPokedexView->pokeBallRotation = POKEBALL_ROTATION_TOP;
            gTasks[taskId].func = Task_OpenSearchResults;
        }
        // Search didn't produce results
        else
        {
            sPokedexView->pokeBallRotation = sPokedexView->pokeBallRotationBackup;
            sPokedexView->selectedPokemon = sPokedexView->selectedPokemonBackup;
            sPokedexView->dexMode = sPokedexView->dexModeBackup;
            if (!IsNationalPokedexEnabled())
                sPokedexView->dexMode = DEX_MODE_HOENN;
            sPokedexView->dexOrder = sPokedexView->dexOrderBackup;
            gTasks[taskId].func = Task_OpenPokedexMainPage;
        }
    }
}

static void Task_ClosePokedex(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSaveBlock2Ptr->pokedex.mode = sPokedexView->dexMode;
        if (!IsNationalPokedexEnabled())
            gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
        gSaveBlock2Ptr->pokedex.order = sPokedexView->dexOrder;
        ClearMonSprites();
        FreeWindowAndBgBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        Free(sPokedexView);
    }
}

static void Task_OpenSearchResults(u8 taskId)
{
    sPokedexView->isSearchResults = TRUE;
    if (LoadPokedexListPage(PAGE_SEARCH_RESULTS))
        gTasks[taskId].func = Task_HandleSearchResultsInput;
}

static void Task_HandleSearchResultsInput(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
    }
    else
    {
        if (JOY_NEW(A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            u32 a;

            UpdateSelectedMonSpriteId();
            a = (1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16));
            gSprites[sPokedexView->selectedMonSpriteId].callback = SpriteCB_MoveMonForInfoScreen;
            BeginNormalPaletteFade(~a, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_OpenSearchResultsInfoScreenAfterMonMovement;
            PlaySE(SE_PIN);
            FreeWindowAndBgBuffers();
        }
        else if (JOY_NEW(START_BUTTON))
        {
            sPokedexView->menuY = 0;
            sPokedexView->menuIsOpen = TRUE;
            sPokedexView->menuCursorPos = 0;
            gTasks[taskId].func = Task_HandleSearchResultsStartMenuInput;
            PlaySE(SE_SELECT);
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].tLoadScreenTaskId = LoadSearchMenu();
            sPokedexView->screenSwitchState = 0;
            gTasks[taskId].func = Task_WaitForExitSearch;
            PlaySE(SE_PC_LOGIN);
            FreeWindowAndBgBuffers();
        }
        else if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_ReturnToPokedexFromSearchResults;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            //Handle D-pad
            sPokedexView->selectedPokemon = TryDoPokedexScroll(sPokedexView->selectedPokemon, 0xE);
            if (sPokedexView->scrollTimer)
                gTasks[taskId].func = Task_WaitForSearchResultsScroll;
        }
    }
}

static void Task_WaitForSearchResultsScroll(u8 taskId)
{
    if (UpdateDexListScroll(sPokedexView->scrollDirection, sPokedexView->scrollMonIncrement, sPokedexView->maxScrollTimer))
        gTasks[taskId].func = Task_HandleSearchResultsInput;
}

static void Task_HandleSearchResultsStartMenuInput(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY != 96)
    {
        sPokedexView->menuY += 8;
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            switch (sPokedexView->menuCursorPos)
            {
            case 0: //BACK TO LIST
            default:
                gMain.newKeys |= START_BUTTON;
                break;
            case 1: //LIST TOP
                sPokedexView->selectedPokemon = 0;
                sPokedexView->pokeBallRotation = POKEBALL_ROTATION_TOP;
                ClearMonSprites();
                CreateMonSpritesAtPos(sPokedexView->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;
                break;
            case 2: //LIST BOTTOM
                sPokedexView->selectedPokemon = sPokedexView->pokemonListCount - 1;
                sPokedexView->pokeBallRotation = sPokedexView->pokemonListCount * 16 + POKEBALL_ROTATION_BOTTOM;
                ClearMonSprites();
                CreateMonSpritesAtPos(sPokedexView->selectedPokemon, 0xE);
                gMain.newKeys |= START_BUTTON;
                break;
            case 3: //BACK TO POKEDEX
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = Task_ReturnToPokedexFromSearchResults;
                PlaySE(SE_TRUCK_DOOR);
                break;
            case 4: //CLOSE POKEDEX
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = Task_ClosePokedexFromSearchResultsStartMenu;
                PlaySE(SE_PC_OFF);
                break;
            }
        }

        //Exit menu when Start or B is pressed
        if (JOY_NEW(START_BUTTON | B_BUTTON))
        {
            sPokedexView->menuIsOpen = FALSE;
            gTasks[taskId].func = Task_HandleSearchResultsInput;
            PlaySE(SE_SELECT);
        }
        else if (JOY_REPEAT(DPAD_UP) && sPokedexView->menuCursorPos)
        {
            sPokedexView->menuCursorPos--;
            PlaySE(SE_SELECT);
        }
        else if (JOY_REPEAT(DPAD_DOWN) && sPokedexView->menuCursorPos < 4)
        {
            sPokedexView->menuCursorPos++;
            PlaySE(SE_SELECT);
        }
    }
}

static void Task_OpenSearchResultsInfoScreenAfterMonMovement(u8 taskId)
{
    if (gSprites[sPokedexView->selectedMonSpriteId].x == MON_PAGE_X && gSprites[sPokedexView->selectedMonSpriteId].y == MON_PAGE_Y)
    {
        sPokedexView->currentPageBackup = sPokedexView->currentPage;
        gTasks[taskId].tLoadScreenTaskId = LoadInfoScreen(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], sPokedexView->selectedMonSpriteId);
        sPokedexView->selectedMonSpriteId = -1;
        gTasks[taskId].func = Task_WaitForExitSearchResultsInfoScreen;
    }
}

static void Task_WaitForExitSearchResultsInfoScreen(u8 taskId)
{
    if (gTasks[gTasks[taskId].tLoadScreenTaskId].isActive)
    {
        // While active, handle scroll input
        if (sPokedexView->currentPage == PAGE_INFO && !IsInfoScreenScrolling(gTasks[taskId].tLoadScreenTaskId) && TryDoInfoScreenScroll())
            StartInfoScreenScroll(&sPokedexView->pokedexList[sPokedexView->selectedPokemon], gTasks[taskId].tLoadScreenTaskId);
    }
    else
    {
        // Exiting, back to search results
        gTasks[taskId].func = Task_OpenSearchResults;
    }
}

static void Task_ReturnToPokedexFromSearchResults(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->pokeBallRotation = sPokedexView->pokeBallRotationBackup;
        sPokedexView->selectedPokemon = sPokedexView->selectedPokemonBackup;
        sPokedexView->dexMode = sPokedexView->dexModeBackup;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->dexOrderBackup;
        gTasks[taskId].func = Task_OpenPokedexMainPage;
        ClearMonSprites();
        FreeWindowAndBgBuffers();
    }
}

static void Task_ClosePokedexFromSearchResultsStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sPokedexView->pokeBallRotation = sPokedexView->pokeBallRotationBackup;
        sPokedexView->selectedPokemon = sPokedexView->selectedPokemonBackup;
        sPokedexView->dexMode = sPokedexView->dexModeBackup;
        if (!IsNationalPokedexEnabled())
            sPokedexView->dexMode = DEX_MODE_HOENN;
        sPokedexView->dexOrder = sPokedexView->dexOrderBackup;
        gTasks[taskId].func = Task_ClosePokedex;
    }
}

#undef tLoadScreenTaskId

// For loading main pokedex page or pokedex search results
static bool8 LoadPokedexListPage(u8 page)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (gPaletteFade.active)
            return 0;
        SetVBlankCallback(NULL);
        sPokedexView->currentPage = page;
        ResetOtherVideoRegisters(0);
        SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sPokedex_BgTemplate, ARRAY_COUNT(sPokedex_BgTemplate));
        SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(1, gPokedexList_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexListUnderlay_Tilemap, 0, 0);
        if (page == PAGE_MAIN)
            CopyToBgTilemapBuffer(0, gPokedexStartMenuMain_Tilemap, 0, 0x280);
        else
            CopyToBgTilemapBuffer(0, gPokedexStartMenuSearchResults_Tilemap, 0, 0x280);
        ResetPaletteFade();
        if (page == PAGE_MAIN)
            sPokedexView->isSearchResults = FALSE;
        else
            sPokedexView->isSearchResults = TRUE;
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        InitWindows(sPokemonList_WindowTemplate);
        DeactivateAllTextPrinters();
        PutWindowTilemap(0);
        CopyWindowToVram(0, COPYWIN_FULL);
        gMain.state = 1;
        break;
    case 1:
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LoadCompressedSpriteSheet(&sInterfaceSpriteSheet[0]);
        LoadSpritePalettes(sInterfaceSpritePalette);
        CreateInterfaceSprites(page);
        gMain.state++;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        if (page == PAGE_MAIN)
            CreatePokedexList(sPokedexView->dexMode, sPokedexView->dexOrder);
        CreateMonSpritesAtPos(sPokedexView->selectedPokemon, 0xE);
        sPokedexView->menuIsOpen = FALSE;
        sPokedexView->menuY = 0;
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_Pokedex);
        gMain.state++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL | WINOUT_WINOBJ_BG0 | WINOUT_WINOBJ_BG2 | WINOUT_WINOBJ_BG3 | WINOUT_WINOBJ_OBJ);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_OBJWIN_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            gMain.state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void LoadPokedexBgPalette(bool8 isSearchResults)
{
    if (isSearchResults == TRUE)
        LoadPalette(gPokedexSearchResults_Pal + 1, 1, 0xBE);
    else if (!IsNationalPokedexEnabled())
        LoadPalette(gPokedexBgHoenn_Pal + 1, 1, 0xBE);
    else
        LoadPalette(gPokedexBgNational_Pal + 1, 1, 0xBE);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
}

static void FreeWindowAndBgBuffers(void)
{
    void *tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

static void CreatePokedexList(u8 dexMode, u8 order)
{
    u32 vars[3]; //I have no idea why three regular variables are stored in an array, but whatever.
#define temp_dexCount   vars[0]
#define temp_isHoennDex vars[1]
#define temp_dexNum     vars[2]
    s32 i;

    sPokedexView->pokemonListCount = 0;

    switch (dexMode)
    {
    default:
    case DEX_MODE_HOENN:
        temp_dexCount = HOENN_DEX_COUNT;
        temp_isHoennDex = TRUE;
        break;
    case DEX_MODE_NATIONAL:
        if (IsNationalPokedexEnabled())
        {
            temp_dexCount = NATIONAL_DEX_COUNT;
            temp_isHoennDex = FALSE;
        }
        else
        {
            temp_dexCount = HOENN_DEX_COUNT;
            temp_isHoennDex = TRUE;
        }
        break;
    }

    switch (order)
    {
    case ORDER_NUMERICAL:
        if (temp_isHoennDex)
        {
            for (i = 0; i < temp_dexCount; i++)
            {
                temp_dexNum = HoennToNationalOrder(i + 1);
                sPokedexView->pokedexList[i].dexNum = temp_dexNum;
                sPokedexView->pokedexList[i].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                sPokedexView->pokedexList[i].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                if (sPokedexView->pokedexList[i].seen)
                    sPokedexView->pokemonListCount = i + 1;
            }
        }
        else
        {
            s16 r5, r10;
            for (i = 0, r5 = 0, r10 = 0; i < temp_dexCount; i++)
            {
                temp_dexNum = i + 1;
                if (GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
                    r10 = 1;
                if (r10)
                {
                    sPokedexView->pokedexList[r5].dexNum = temp_dexNum;
                    sPokedexView->pokedexList[r5].seen = GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN);
                    sPokedexView->pokedexList[r5].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                    if (sPokedexView->pokedexList[r5].seen)
                        sPokedexView->pokemonListCount = r5 + 1;
                    r5++;
                }
            }
        }
        break;
    case ORDER_ALPHABETICAL:
        for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Alphabetical); i++)
        {
            temp_dexNum = gPokedexOrder_Alphabetical[i];

            if (temp_dexNum <= NATIONAL_DEX_COUNT && (!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) != 0) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_HEAVIEST:
        for (i = ARRAY_COUNT(gPokedexOrder_Weight) - 1; i >= 0; i--)
        {
            temp_dexNum = gPokedexOrder_Weight[i];

            if (temp_dexNum <= NATIONAL_DEX_COUNT && (!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) != 0) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_LIGHTEST:
        for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Weight); i++)
        {
            temp_dexNum = gPokedexOrder_Weight[i];

            if (temp_dexNum <= NATIONAL_DEX_COUNT && (!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) != 0) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_TALLEST:
        for (i = ARRAY_COUNT(gPokedexOrder_Height) - 1; i >= 0; i--)
        {
            temp_dexNum = gPokedexOrder_Height[i];

            if (temp_dexNum <= NATIONAL_DEX_COUNT && (!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) != 0) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_SMALLEST:
        for (i = 0; i < ARRAY_COUNT(gPokedexOrder_Height); i++)
        {
            temp_dexNum = gPokedexOrder_Height[i];

            if (temp_dexNum <= NATIONAL_DEX_COUNT && (!temp_isHoennDex || NationalToHoennOrder(temp_dexNum) != 0) && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    }

    for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
    {
        sPokedexView->pokedexList[i].dexNum = 0xFFFF;
        sPokedexView->pokedexList[i].seen = FALSE;
        sPokedexView->pokedexList[i].owned = FALSE;
    }
}

static void PrintMonDexNumAndName(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top)
{
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;
    AddTextPrinterParameterized4(windowId, fontId, left * 8, (top * 8) + 1, 0, 0, color, TEXT_SKIP_DRAW, str);
}

// u16 ignored is passed but never used
static void CreateMonListEntry(u8 position, u16 b, u16 ignored)
{
    s16 entryNum;
    u16 i;
    u16 vOffset;

    switch (position)
    {
    case 0: // Initial
    default:
        entryNum = b - 5;
        for (i = 0; i <= 10; i++)
        {
            if (entryNum < 0 || entryNum >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[entryNum].dexNum == 0xFFFF)
            {
                ClearMonListEntry(17, i * 2, ignored);
            }
            else
            {
                ClearMonListEntry(17, i * 2, ignored);
                if (sPokedexView->pokedexList[entryNum].seen)
                {
                    CreateMonDexNum(entryNum, 0x12, i * 2, ignored);
                    CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, 0x11, i * 2, ignored);
                    CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, 0x16, i * 2);
                }
                else
                {
                    CreateMonDexNum(entryNum, 0x12, i * 2, ignored);
                    CreateCaughtBall(FALSE, 0x11, i * 2, ignored);
                    CreateMonName(0, 0x16, i * 2);
                }
            }
            entryNum++;
        }
        break;
    case 1: // Up
        entryNum = b - 5;
        if (entryNum < 0 || entryNum >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[entryNum].dexNum == 0xFFFF)
        {
            ClearMonListEntry(17, sPokedexView->listVOffset * 2, ignored);
        }
        else
        {
            ClearMonListEntry(17, sPokedexView->listVOffset * 2, ignored);
            if (sPokedexView->pokedexList[entryNum].seen)
            {
                CreateMonDexNum(entryNum, 18, sPokedexView->listVOffset * 2, ignored);
                CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, 0x11, sPokedexView->listVOffset * 2, ignored);
                CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, 0x16, sPokedexView->listVOffset * 2);
            }
            else
            {
                CreateMonDexNum(entryNum, 18, sPokedexView->listVOffset * 2, ignored);
                CreateCaughtBall(FALSE, 17, sPokedexView->listVOffset * 2, ignored);
                CreateMonName(0, 0x16, sPokedexView->listVOffset * 2);
            }
        }
        break;
    case 2: // Down
        entryNum = b + 5;
        vOffset = sPokedexView->listVOffset + 10;
        if (vOffset >= LIST_SCROLL_STEP)
            vOffset -= LIST_SCROLL_STEP;
        if (entryNum < 0 || entryNum >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[entryNum].dexNum == 0xFFFF)
            ClearMonListEntry(17, vOffset * 2, ignored);
        else
        {
            ClearMonListEntry(17, vOffset * 2, ignored);
            if (sPokedexView->pokedexList[entryNum].seen)
            {
                CreateMonDexNum(entryNum, 18, vOffset * 2, ignored);
                CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, 0x11, vOffset * 2, ignored);
                CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, 0x16, vOffset * 2);
            }
            else
            {
                CreateMonDexNum(entryNum, 18, vOffset * 2, ignored);
                CreateCaughtBall(FALSE, 0x11, vOffset * 2, ignored);
                CreateMonName(0, 0x16, vOffset * 2);
            }
        }
        break;
    }
    CopyWindowToVram(0, COPYWIN_GFX);
}

static void CreateMonDexNum(u16 entryNum, u8 left, u8 top, u16 unused)
{
    u8 text[6];
    u16 dexNum;

    memcpy(text, sText_No000, ARRAY_COUNT(text));
    dexNum = sPokedexView->pokedexList[entryNum].dexNum;
    if (sPokedexView->dexMode == DEX_MODE_HOENN)
        dexNum = NationalToHoennOrder(dexNum);
    text[2] = CHAR_0 + dexNum / 100;
    text[3] = CHAR_0 + (dexNum % 100) / 10;
    text[4] = CHAR_0 + (dexNum % 100) % 10;
    PrintMonDexNumAndName(0, FONT_NARROW, text, left, top);
}

static void CreateCaughtBall(bool16 owned, u8 x, u8 y, u16 unused)
{
    if (owned)
        BlitBitmapToWindow(0, sCaughtBall_Gfx, x * 8, y * 8, 8, 16);
    else
        FillWindowPixelRect(0, PIXEL_FILL(0), x * 8, y * 8, 8, 16);
}

static u8 CreateMonName(u16 num, u8 left, u8 top)
{
    const u8 *str;

    num = NationalPokedexNumToSpecies(num);
    if (num)
        str = gSpeciesNames[num];
    else
        str = sText_TenDashes;
    PrintMonDexNumAndName(0, FONT_NARROW, str, left, top);
    return StringLength(str);
}

static void ClearMonListEntry(u8 x, u8 y, u16 unused)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x * 8, y * 8, 0x60, 16);
}

// u16 ignored is passed but never used
static void CreateMonSpritesAtPos(u16 selectedMon, u16 ignored)
{
    u8 i;
    u16 dexNum;
    u8 spriteId;

    gPaletteFade.bufferTransferDisabled = TRUE;

    for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
        sPokedexView->monSpriteIds[i] = 0xFFFF;
    sPokedexView->selectedMonSpriteId = 0xFFFF;

    // Create top mon sprite
    dexNum = GetPokemonSpriteToDisplay(selectedMon - 1);
    if (dexNum != 0xFFFF)
    {
        spriteId = CreatePokedexMonSprite(dexNum, 0x60, 0x50);
        gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
        gSprites[spriteId].data[5] = -32;
    }

    // Create mid mon sprite
    dexNum = GetPokemonSpriteToDisplay(selectedMon);
    if (dexNum != 0xFFFF)
    {
        spriteId = CreatePokedexMonSprite(dexNum, 0x60, 0x50);
        gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
        gSprites[spriteId].data[5] = 0;
    }

    // Create bottom mon sprite
    dexNum = GetPokemonSpriteToDisplay(selectedMon + 1);
    if (dexNum != 0xFFFF)
    {
        spriteId = CreatePokedexMonSprite(dexNum, 0x60, 0x50);
        gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
        gSprites[spriteId].data[5] = 32;
    }

    CreateMonListEntry(0, selectedMon, ignored);
    SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset);

    sPokedexView->listVOffset = 0;
    sPokedexView->listMovingVOffset = 0;

    gPaletteFade.bufferTransferDisabled = FALSE;
}

static bool8 UpdateDexListScroll(u8 direction, u8 monMoveIncrement, u8 scrollTimerMax)
{
    u16 i;
    u8 step;

    if (sPokedexView->scrollTimer)
    {
        sPokedexView->scrollTimer--;
        switch (direction)
        {
        case 1: // Up
            for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
            {
                if (sPokedexView->monSpriteIds[i] != 0xFFFF)
                    gSprites[sPokedexView->monSpriteIds[i]].data[5] += monMoveIncrement;
            }
            step = LIST_SCROLL_STEP * (scrollTimerMax - sPokedexView->scrollTimer) / scrollTimerMax;
            SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->listMovingVOffset * LIST_SCROLL_STEP - step);
            sPokedexView->pokeBallRotation -= sPokedexView->pokeBallRotationStep;
            break;
        case 2: // Down
            for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
            {
                if (sPokedexView->monSpriteIds[i] != 0xFFFF)
                    gSprites[sPokedexView->monSpriteIds[i]].data[5] -= monMoveIncrement;
            }
            step = LIST_SCROLL_STEP * (scrollTimerMax - sPokedexView->scrollTimer) / scrollTimerMax;
            SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->listMovingVOffset * LIST_SCROLL_STEP + step);
            sPokedexView->pokeBallRotation += sPokedexView->pokeBallRotationStep;
            break;
        }
        return FALSE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, sPokedexView->initialVOffset + sPokedexView->listVOffset * LIST_SCROLL_STEP);
        return TRUE;
    }
}

static void CreateScrollingPokemonSprite(u8 direction, u16 selectedMon)
{
    u16 dexNum;
    u8 spriteId;

    sPokedexView->listMovingVOffset = sPokedexView->listVOffset;
    switch (direction)
    {
    case 1: // up
        dexNum = GetPokemonSpriteToDisplay(selectedMon - 1);
        if (dexNum != 0xFFFF)
        {
            spriteId = CreatePokedexMonSprite(dexNum, 0x60, 0x50);
            gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
            gSprites[spriteId].data[5] = -64;
        }
        if (sPokedexView->listVOffset > 0)
            sPokedexView->listVOffset--;
        else
            sPokedexView->listVOffset = LIST_SCROLL_STEP - 1;
        break;
    case 2: // down
        dexNum = GetPokemonSpriteToDisplay(selectedMon + 1);
        if (dexNum != 0xFFFF)
        {
            spriteId = CreatePokedexMonSprite(dexNum, 0x60, 0x50);
            gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
            gSprites[spriteId].data[5] = 64;
        }
        if (sPokedexView->listVOffset < LIST_SCROLL_STEP - 1)
            sPokedexView->listVOffset++;
        else
            sPokedexView->listVOffset = 0;
        break;
    }
}

// u16 ignored is passed but never used
static u16 TryDoPokedexScroll(u16 selectedMon, u16 ignored)
{
    u8 scrollTimer;
    u8 scrollMonIncrement;
    u8 i;
    u16 startingPos;
    u8 scrollDir = 0;

    if (JOY_HELD(DPAD_UP) && (selectedMon > 0))
    {
        scrollDir = 1;
        selectedMon = GetNextPosition(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateScrollingPokemonSprite(1, selectedMon);
        CreateMonListEntry(1, selectedMon, ignored);
        PlaySE(SE_DEX_SCROLL);
    }
    else if (JOY_HELD(DPAD_DOWN) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        scrollDir = 2;
        selectedMon = GetNextPosition(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateScrollingPokemonSprite(2, selectedMon);
        CreateMonListEntry(2, selectedMon, ignored);
        PlaySE(SE_DEX_SCROLL);
    }
    else if (JOY_NEW(DPAD_LEFT) && (selectedMon > 0))
    {
        startingPos = selectedMon;

        for (i = 0; i < 7; i++)
            selectedMon = GetNextPosition(1, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->pokeBallRotation += 16 * (selectedMon - startingPos);
        ClearMonSprites();
        CreateMonSpritesAtPos(selectedMon, 0xE);
        PlaySE(SE_DEX_PAGE);
    }
    else if (JOY_NEW(DPAD_RIGHT) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        startingPos = selectedMon;
        for (i = 0; i < 7; i++)
            selectedMon = GetNextPosition(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        sPokedexView->pokeBallRotation += 16 * (selectedMon - startingPos);
        ClearMonSprites();
        CreateMonSpritesAtPos(selectedMon, 0xE);
        PlaySE(SE_DEX_PAGE);
    }

    if (scrollDir == 0)
    {
        // Left/right input just snaps up/down, no scrolling
        sPokedexView->scrollSpeed = 0;
        return selectedMon;
    }

    scrollMonIncrement = sScrollMonIncrements[sPokedexView->scrollSpeed / 4];
    scrollTimer = sScrollTimers[sPokedexView->scrollSpeed / 4];
    sPokedexView->scrollTimer = scrollTimer;
    sPokedexView->maxScrollTimer = scrollTimer;
    sPokedexView->scrollMonIncrement = scrollMonIncrement;
    sPokedexView->scrollDirection = scrollDir;
    sPokedexView->pokeBallRotationStep = scrollMonIncrement / 2;
    UpdateDexListScroll(sPokedexView->scrollDirection, sPokedexView->scrollMonIncrement, sPokedexView->maxScrollTimer);
    if (sPokedexView->scrollSpeed < 12)
        sPokedexView->scrollSpeed++;
    return selectedMon;
}

static void UpdateSelectedMonSpriteId(void)
{
    u16 i;

    for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
    {
        u16 spriteId = sPokedexView->monSpriteIds[i];

        if (gSprites[spriteId].x2 == 0 && gSprites[spriteId].y2 == 0 && spriteId != 0xFFFF)
            sPokedexView->selectedMonSpriteId = spriteId;
    }
}

static bool8 TryDoInfoScreenScroll(void)
{
    u16 nextPokemon;
    u16 selectedPokemon = sPokedexView->selectedPokemon;

    if (JOY_NEW(DPAD_UP) && selectedPokemon)
    {
        nextPokemon = selectedPokemon;
        while (nextPokemon != 0)
        {
            nextPokemon = GetNextPosition(1, nextPokemon, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[nextPokemon].seen)
            {
                selectedPokemon = nextPokemon;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == selectedPokemon)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = selectedPokemon;
            sPokedexView->pokeBallRotation -= 16;
            return TRUE;
        }
    }
    else if (JOY_NEW(DPAD_DOWN) && selectedPokemon < sPokedexView->pokemonListCount - 1)
    {
        nextPokemon = selectedPokemon;
        while (nextPokemon < sPokedexView->pokemonListCount - 1)
        {
            nextPokemon = GetNextPosition(0, nextPokemon, 0, sPokedexView->pokemonListCount - 1);

            if (sPokedexView->pokedexList[nextPokemon].seen)
            {
                selectedPokemon = nextPokemon;
                break;
            }
        }

        if (sPokedexView->selectedPokemon == selectedPokemon)
            return FALSE;
        else
        {
            sPokedexView->selectedPokemon = selectedPokemon;
            sPokedexView->pokeBallRotation += 16;
            return TRUE;
        }
    }
    return FALSE;
}

static u8 ClearMonSprites(void)
{
    u16 i;

    for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
    {
        if (sPokedexView->monSpriteIds[i] != 0xFFFF)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[i]);
            sPokedexView->monSpriteIds[i] = 0xFFFF;
        }
    }
    return FALSE;
}

static u16 GetPokemonSpriteToDisplay(u16 species)
{
    if (species >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[species].dexNum == 0xFFFF)
        return 0xFFFF;
    else if (sPokedexView->pokedexList[species].seen)
        return sPokedexView->pokedexList[species].dexNum;
    else
        return 0;
}

static u32 CreatePokedexMonSprite(u16 num, s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < MAX_MONS_ON_SCREEN; i++)
    {
        if (sPokedexView->monSpriteIds[i] == 0xFFFF)
        {
            u8 spriteId = CreateMonSpriteFromNationalDexNumber(num, x, y, i);

            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].oam.priority = 3;
            gSprites[spriteId].data[0] = 0;
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = NationalPokedexNumToSpecies(num);
            sPokedexView->monSpriteIds[i] = spriteId;
            return spriteId;
        }
    }
    return 0xFFFF;
}

#define sIsDownArrow data[1]

static void CreateInterfaceSprites(u8 page)
{
    u8 spriteId;
    u16 digitNum;

    // Scroll arrows
    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 184, 4, 0);
    gSprites[spriteId].sIsDownArrow = FALSE;
    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 184, DISPLAY_HEIGHT - 4, 0);
    gSprites[spriteId].sIsDownArrow = TRUE;
    gSprites[spriteId].vFlip = TRUE;

    CreateSprite(&sScrollBarSpriteTemplate, 230, 20, 0);
    // Start button
    CreateSprite(&sInterfaceTextSpriteTemplate, 16, 120, 0);
    // Menu text
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, 120, 0);
    StartSpriteAnim(&gSprites[spriteId], 3);
    // Select button
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 16, DISPLAY_HEIGHT - 16, 0);
    StartSpriteAnim(&gSprites[spriteId], 2);
    gSprites[spriteId].data[2] = 0x80;
    // Search text
    spriteId = CreateSprite(&sInterfaceTextSpriteTemplate, 48, DISPLAY_HEIGHT - 16, 0);
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sRotatingPokeBallSpriteTemplate, 0, DISPLAY_HEIGHT / 2, 2);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 30;
    gSprites[spriteId].data[0] = 30;
    gSprites[spriteId].data[1] = 0;

    spriteId = CreateSprite(&sRotatingPokeBallSpriteTemplate, 0, DISPLAY_HEIGHT / 2, 2);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[spriteId].oam.matrixNum = 31;
    gSprites[spriteId].data[0] = 31;
    gSprites[spriteId].data[1] = 128;

    if (page == PAGE_MAIN)
    {
        bool32 drawNextDigit;

        if (!IsNationalPokedexEnabled())
        {
            // Seen text
            CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 40, 1);
            // Own text
            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 72, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            // Seen value - 100s
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 24, 48, 1);
            digitNum = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // Seen value - 10s
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 32, 48, 1);
            digitNum = (sPokedexView->seenCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // Seen value - 1s
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 40, 48, 1);
            digitNum = (sPokedexView->seenCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);

            // Owned value - 100s
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 24, 80, 1);
            digitNum = sPokedexView->ownCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // Owned value - 10s
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 32, 80, 1);
            digitNum = (sPokedexView->ownCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // Owned value - 1s
            spriteId = CreateSprite(&sHoennDexSeenOwnNumberSpriteTemplate, 40, 80, 1);
            digitNum = (sPokedexView->ownCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        }
        else
        {
            u16 seenOwnedCount;

            // Seen text
            CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 40, 1);
            // Own text
            spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, 32, 76, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            // Hoenn text (seen)
            CreateSprite(&sHoennNationalTextSpriteTemplate, 17, 45, 1);

            // National text (seen)
            spriteId = CreateSprite(&sHoennNationalTextSpriteTemplate, 17, 55, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            // Hoenn text (own)
            CreateSprite(&sHoennNationalTextSpriteTemplate, 17, 81, 1);

            // National text (own)
            spriteId = CreateSprite(&sHoennNationalTextSpriteTemplate, 17, 91, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);

            // Hoenn seen value - 100s
            seenOwnedCount = GetHoennPokedexCount(FLAG_GET_SEEN);
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 40, 45, 1);
            digitNum = seenOwnedCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // Hoenn seen value - 10s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 48, 45, 1);
            digitNum = (seenOwnedCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // Hoenn seen value - 1s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 56, 45, 1);
            digitNum = (seenOwnedCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);

            // National seen value - 100s
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 40, 55, 1);
            digitNum = sPokedexView->seenCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // National seen value - 10s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 48, 55, 1);
            digitNum = (sPokedexView->seenCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // National seen value - 1s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 56, 55, 1);
            digitNum = (sPokedexView->seenCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);

            seenOwnedCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);

            // Hoenn owned value - 100s
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 40, 81, 1);
            digitNum = seenOwnedCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // Hoenn owned value - 10s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 48, 81, 1);
            digitNum = (seenOwnedCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // Hoenn owned value - 1s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 56, 81, 1);
            digitNum = (seenOwnedCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);

            // National owned value - 100s
            drawNextDigit = FALSE;
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 40, 91, 1);
            digitNum = sPokedexView->ownCount / 100;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
            if (digitNum != 0)
                drawNextDigit = TRUE;
            else
                gSprites[spriteId].invisible = TRUE;

            // National owned value  - 10s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 48, 91, 1);
            digitNum = (sPokedexView->ownCount % 100) / 10;
            if (digitNum != 0 || drawNextDigit)
                StartSpriteAnim(&gSprites[spriteId], digitNum);
            else
                gSprites[spriteId].invisible = TRUE;

            // National owned value - 1s
            spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, 56, 91, 1);
            digitNum = (sPokedexView->ownCount % 100) % 10;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        }
        spriteId = CreateSprite(&sDexListStartMenuCursorSpriteTemplate, 136, 96, 1);
        gSprites[spriteId].invisible = TRUE;
    }
    else // PAGE_SEARCH_RESULTS
    {
        spriteId = CreateSprite(&sDexListStartMenuCursorSpriteTemplate, 136, 80, 1);
        gSprites[spriteId].invisible = TRUE;
    }
}

static void SpriteCB_EndMoveMonForInfoScreen(struct Sprite *sprite)
{
    // Once mon is done moving there's nothing left to do
}

static void SpriteCB_SeenOwnInfo(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN)
        DestroySprite(sprite);
}

void SpriteCB_MoveMonForInfoScreen(struct Sprite *sprite)
{
    sprite->oam.priority = 0;
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    sprite->x2 = 0;
    sprite->y2 = 0;
    if (sprite->x != MON_PAGE_X || sprite->y != MON_PAGE_Y)
    {
        if (sprite->x > MON_PAGE_X)
            sprite->x--;
        if (sprite->x < MON_PAGE_X)
            sprite->x++;

        if (sprite->y > MON_PAGE_Y)
            sprite->y--;
        if (sprite->y < MON_PAGE_Y)
            sprite->y++;
    }
    else
    {
        sprite->callback = SpriteCB_EndMoveMonForInfoScreen;
    }
}

static void SpriteCB_PokedexListMonSprite(struct Sprite *sprite)
{
    u8 monId = sprite->data[1];

    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[monId]);
        sPokedexView->monSpriteIds[monId] = 0xFFFF;
    }
    else
    {
        u32 var;
        sprite->y2 = gSineTable[(u8)sprite->data[5]] * 76 / 256;
        var = SAFE_DIV(0x10000, gSineTable[sprite->data[5] + 64]);
        if (var > 0xFFFF)
            var = 0xFFFF;
        SetOamMatrix(sprite->data[1] + 1, 0x100, 0, 0, var);
        sprite->oam.matrixNum = monId + 1;

        if (sprite->data[5] > -64 && sprite->data[5] < 64)
        {
            sprite->invisible = FALSE;
            sprite->data[0] = 1;
        }
        else
        {
            sprite->invisible = TRUE;
        }

        if ((sprite->data[5] <= -64 || sprite->data[5] >= 64) && sprite->data[0] != 0)
        {
            FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[monId]);
            sPokedexView->monSpriteIds[monId] = 0xFFFF;
        }
    }
}

static void SpriteCB_Scrollbar(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
        DestroySprite(sprite);
    else
        sprite->y2 = sPokedexView->selectedPokemon * 120 / (sPokedexView->pokemonListCount - 1);
}

static void SpriteCB_ScrollArrow(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 r0;

        if (sprite->sIsDownArrow)
        {
            if (sPokedexView->selectedPokemon == sPokedexView->pokemonListCount - 1)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2];
        }
        else
        {
            if (sPokedexView->selectedPokemon == 0)
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
            r0 = sprite->data[2] - 128;
        }
        sprite->y2 = gSineTable[r0] / 64;
        sprite->data[2] = sprite->data[2] + 8;
        if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 0 && sprite->invisible == FALSE)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
}

static void SpriteCB_DexListInterfaceText(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
        DestroySprite(sprite);
}

static void SpriteCB_RotatingPokeBall(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        DestroySprite(sprite);
    }
    else
    {
        u8 val;
        s16 r3;
        s16 r0;

        val = sPokedexView->pokeBallRotation + sprite->data[1];
        r3 = gSineTable[val];
        r0 = gSineTable[val + 64];
        SetOamMatrix(sprite->data[0], r0, r3, -r3, r0);

        val = sPokedexView->pokeBallRotation + (sprite->data[1] + 64);
        r3 = gSineTable[val];
        r0 = gSineTable[val + 64];
        sprite->x2 = r0 * 40 / 256;
        sprite->y2 = r3 * 40 / 256;
    }
}

static void SpriteCB_DexListStartMenuCursor(struct Sprite *sprite)
{
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 r1 = sPokedexView->currentPage == PAGE_MAIN ? 80 : 96;

        if (sPokedexView->menuIsOpen && sPokedexView->menuY == r1)
        {
            sprite->invisible = FALSE;
            sprite->y2 = sPokedexView->menuCursorPos * 16;
            sprite->x2 = gSineTable[(u8)sprite->data[2]] / 64;
            sprite->data[2] += 8;
        }
        else
        {
            sprite->invisible = TRUE;
        }
    }
}

static void PrintInfoScreenText(const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(0, FONT_NORMAL, left, top, 0, 0, color, TEXT_SKIP_DRAW, str);
}

#define tScrolling       data[0]
#define tMonSpriteDone   data[1]
#define tBgLoaded        data[2]
#define tSkipCry         data[3]
#define tMonSpriteId     data[4]
#define tTrainerSpriteId data[5]

static u8 LoadInfoScreen(struct PokedexListItem *item, u8 monSpriteId)
{
    u8 taskId;

    sPokedexListItem = item;
    taskId = CreateTask(Task_LoadInfoScreen, 0);
    gTasks[taskId].tScrolling = FALSE;
    gTasks[taskId].tMonSpriteDone = TRUE; // Already has sprite from list view
    gTasks[taskId].tBgLoaded = FALSE;
    gTasks[taskId].tSkipCry = FALSE;
    gTasks[taskId].tMonSpriteId = monSpriteId;
    gTasks[taskId].tTrainerSpriteId = SPRITE_NONE;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sInfoScreen_BgTemplate, ARRAY_COUNT(sInfoScreen_BgTemplate));
    SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    InitWindows(sInfoScreen_WindowTemplates);
    DeactivateAllTextPrinters();

    return taskId;
}

static bool8 IsInfoScreenScrolling(u8 taskId)
{
    if (!gTasks[taskId].tScrolling && gTasks[taskId].func == Task_HandleInfoScreenInput)
        return FALSE;
    else
        return TRUE;
}

static u8 StartInfoScreenScroll(struct PokedexListItem *item, u8 taskId)
{
    sPokedexListItem = item;
    gTasks[taskId].tScrolling = TRUE;
    gTasks[taskId].tMonSpriteDone = FALSE;
    gTasks[taskId].tBgLoaded = FALSE;
    gTasks[taskId].tSkipCry = FALSE;
    return taskId;
}

static void Task_LoadInfoScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->currentPage = PAGE_INFO;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].tMonSpriteDone)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].tBgLoaded)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexInfoScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_FOOTPRINT);
        DrawFootprint(WIN_FOOTPRINT, sPokedexListItem->dexNum);
        CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
        HighlightScreenSelectBarItem(sPokedexView->selectedScreen, 0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        PrintMonInfo(sPokedexListItem->dexNum, sPokedexView->dexMode == DEX_MODE_HOENN ? FALSE : TRUE, sPokedexListItem->owned, 0);
        if (!sPokedexListItem->owned)
            LoadPalette(gPlttBufferUnfaded + 1, 0x31, 0x1E);
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 5:
        if (!gTasks[taskId].tMonSpriteDone)
        {
            gTasks[taskId].tMonSpriteId = (u16)CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, MON_PAGE_X, MON_PAGE_Y, 0);
            gSprites[gTasks[taskId].tMonSpriteId].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 6:
        {
            u32 preservedPalettes = 0;

            if (gTasks[taskId].tBgLoaded)
                preservedPalettes = 0x14; // each bit represents a palette index
            if (gTasks[taskId].tMonSpriteDone)
                preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
            BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(gPokedexVBlankCB);
            gMain.state++;
        }
        break;
    case 7:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        HideBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 8:
        if (!gPaletteFade.active)
        {
            gMain.state++;
            if (!gTasks[taskId].tSkipCry)
            {
                StopCryAndClearCrySongs();
                PlayCry_NormalNoDucking(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), 0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
            }
            else
            {
                gMain.state++;
            }
        }
        break;
    case 9:
        if (!IsCryPlayingOrClearCrySongs())
            gMain.state++;
        break;
    case 10:
        gTasks[taskId].tScrolling = FALSE;
        gTasks[taskId].tMonSpriteDone = FALSE; // Reload next time screen comes up
        gTasks[taskId].tBgLoaded = TRUE;
        gTasks[taskId].tSkipCry = TRUE;
        gTasks[taskId].func = Task_HandleInfoScreenInput;
        gMain.state = 0;
        break;
    }
}

static void FreeInfoScreenWindowAndBgBuffers(void)
{
    void *tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

static void Task_HandleInfoScreenInput(u8 taskId)
{
    if (gTasks[taskId].tScrolling)
    {
        // Scroll up/down
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_LoadInfoScreenWaitForFade;
        PlaySE(SE_DEX_SCROLL);
        return;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitInfoScreen;
        PlaySE(SE_PC_OFF);
        return;
    }
    if (JOY_NEW(A_BUTTON))
    {
        switch (sPokedexView->selectedScreen)
        {
        case AREA_SCREEN:
            BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 16, RGB_BLACK);
            sPokedexView->screenSwitchState = 1;
            gTasks[taskId].func = Task_SwitchScreensFromInfoScreen;
            PlaySE(SE_PIN);
            break;
        case CRY_SCREEN:
            BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
            sPokedexView->screenSwitchState = 2;
            gTasks[taskId].func = Task_SwitchScreensFromInfoScreen;
            PlaySE(SE_PIN);
            break;
        case SIZE_SCREEN:
            if (!sPokedexListItem->owned)
            {
                PlaySE(SE_FAILURE);
            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
                sPokedexView->screenSwitchState = 3;
                gTasks[taskId].func = Task_SwitchScreensFromInfoScreen;
                PlaySE(SE_PIN);
            }
            break;
        case CANCEL_SCREEN:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Task_ExitInfoScreen;
            PlaySE(SE_PC_OFF);
            break;
        }
        return;
    }
    if ((JOY_NEW(DPAD_LEFT)
     || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen > 0)
    {
        sPokedexView->selectedScreen--;
        HighlightScreenSelectBarItem(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_DEX_PAGE);
        return;
    }
    if ((JOY_NEW(DPAD_RIGHT)
     || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
     && sPokedexView->selectedScreen < CANCEL_SCREEN)
    {
        sPokedexView->selectedScreen++;
        HighlightScreenSelectBarItem(sPokedexView->selectedScreen, 0xD);
        PlaySE(SE_DEX_PAGE);
        return;
    }
}

static void Task_SwitchScreensFromInfoScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->screenSwitchState)
        {
        case 1:
        default:
            gTasks[taskId].func = Task_LoadAreaScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadCryScreen;
            break;
        case 3:
            gTasks[taskId].func = Task_LoadSizeScreen;
            break;
        }
    }
}

static void Task_LoadInfoScreenWaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        gTasks[taskId].func = Task_LoadInfoScreen;
    }
}

static void Task_ExitInfoScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeInfoScreenWindowAndBgBuffers();
        DestroyTask(taskId);
    }
}

static void Task_LoadAreaScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            sPokedexView->currentPage = PAGE_AREA;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            ResetOtherVideoRegisters(DISPCNT_BG1_ON);
            sPokedexView->selectedScreen = AREA_SCREEN;
            gMain.state = 1;
        }
        break;
    case 1:
        LoadScreenSelectBarSubmenu(0xD);
        HighlightSubmenuScreenSelectBarItem(0, 0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(13) | BGCNT_16COLOR | BGCNT_TXT256x256);
        gMain.state++;
        break;
    case 2:
        ShowPokedexAreaScreen(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), &sPokedexView->screenSwitchState);
        SetVBlankCallback(gPokedexVBlankCB);
        sPokedexView->screenSwitchState = 0;
        gMain.state = 0;
        gTasks[taskId].func = Task_WaitForAreaScreenInput;
        break;
    }
}

static void Task_WaitForAreaScreenInput(u8 taskId)
{
// See Task_HandlePokedexAreaScreenInput() in pokedex_area_screen.c
    if (sPokedexView->screenSwitchState != 0)
        gTasks[taskId].func = Task_SwitchScreensFromAreaScreen;
}

static void Task_SwitchScreensFromAreaScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (sPokedexView->screenSwitchState)
        {
        case 1:
        default:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadCryScreen;
            break;
        }
    }
}

static void Task_LoadCryScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            sPokedexView->currentPage = PAGE_CRY;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            ResetOtherVideoRegisters(DISPCNT_BG1_ON);
            sPokedexView->selectedScreen = CRY_SCREEN;
            gMain.state = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, &gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, &gPokedexCryScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_VU_METER);
        PutWindowTilemap(WIN_CRY_WAVE);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarSubmenu(0xD);
        HighlightSubmenuScreenSelectBarItem(1, 0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        PrintInfoScreenText(gText_CryOf, 82, 33);
        PrintCryScreenSpeciesName(0, sPokedexListItem->dexNum, 82, 49);
        gMain.state++;
        break;
    case 5:
        gTasks[taskId].tMonSpriteId = CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, MON_PAGE_X, MON_PAGE_Y, 0);
        gSprites[gTasks[taskId].tMonSpriteId].oam.priority = 0;
        gDexCryScreenState = 0;
        gMain.state++;
        break;
    case 6:
        {
            struct CryScreenWindow waveformWindow;

            waveformWindow.unk0 = 0x4020;
            waveformWindow.unk2 = 31;
            waveformWindow.paletteNo = 8;
            waveformWindow.yPos = 30;
            waveformWindow.xPos = 12;
            if (LoadCryWaveformWindow(&waveformWindow, 2))
            {
                gMain.state++;
                gDexCryScreenState = 0;
            }
        }
        break;
    case 7:
        {
            struct CryScreenWindow cryMeter;

            cryMeter.paletteNo = 9;
            cryMeter.xPos = 18;
            cryMeter.yPos = 3;
            if (LoadCryMeter(&cryMeter, 3))
                gMain.state++;
            CopyWindowToVram(WIN_VU_METER, COPYWIN_GFX);
            CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
        }
        break;
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gMain.state++;
        break;
    case 9:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 10:
        sPokedexView->screenSwitchState = 0;
        gMain.state = 0;
        gTasks[taskId].func = Task_HandleCryScreenInput;
        break;
    }
}

static void Task_HandleCryScreenInput(u8 taskId)
{
    UpdateCryWaveformWindow(2);

    if (IsCryPlaying())
        LoadPlayArrowPalette(TRUE);
    else
        LoadPlayArrowPalette(FALSE);

    if (JOY_NEW(A_BUTTON))
    {
        LoadPlayArrowPalette(TRUE);
        CryScreenPlayButton(NationalPokedexNumToSpecies(sPokedexListItem->dexNum));
        return;
    }
    else if (!gPaletteFade.active)
    {
        if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->screenSwitchState = 1;
            gTasks[taskId].func = Task_SwitchScreensFromCryScreen;
            PlaySE(SE_PC_OFF);
            return;
        }
        if (JOY_NEW(DPAD_LEFT)
         || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
            m4aMPlayContinue(&gMPlayInfo_BGM);
            sPokedexView->screenSwitchState = 2;
            gTasks[taskId].func = Task_SwitchScreensFromCryScreen;
            PlaySE(SE_DEX_PAGE);
            return;
        }
        if (JOY_NEW(DPAD_RIGHT)
         || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            if (!sPokedexListItem->owned)
            {
                PlaySE(SE_FAILURE);
            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
                m4aMPlayContinue(&gMPlayInfo_BGM);
                sPokedexView->screenSwitchState = 3;
                gTasks[taskId].func = Task_SwitchScreensFromCryScreen;
                PlaySE(SE_DEX_PAGE);
            }
            return;
        }
    }
}

static void Task_SwitchScreensFromCryScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeCryScreen();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->screenSwitchState)
        {
        default:
        case 1:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadAreaScreen;
            break;
        case 3:
            gTasks[taskId].func = Task_LoadSizeScreen;
            break;
        }
    }
}

static void LoadPlayArrowPalette(bool8 cryPlaying)
{
    u16 color;

    if (cryPlaying)
        color = RGB(18, 28, 0);
    else
        color = RGB(15, 21, 0);
    LoadPalette(&color, 0x5D, 2);
}

static void Task_LoadSizeScreen(u8 taskId)
{
    u8 spriteId;

    switch (gMain.state)
    {
    default:
    case 0:
        if (!gPaletteFade.active)
        {
            sPokedexView->currentPage = PAGE_SIZE;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            ResetOtherVideoRegisters(DISPCNT_BG1_ON);
            sPokedexView->selectedScreen = SIZE_SCREEN;
            gMain.state = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexSizeScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarSubmenu(0xD);
        HighlightSubmenuScreenSelectBarItem(2, 0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        {
            u8 string[64];

            StringCopy(string, gText_SizeComparedTo);
            StringAppend(string, gSaveBlock2Ptr->playerName);
            PrintInfoScreenText(string, GetStringCenterAlignXOffset(FONT_NORMAL, string, 0xF0), 0x79);
            gMain.state++;
        }
        break;
    case 4:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 5:
        spriteId = CreateSizeScreenTrainerPic(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 152, 56, 0);
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 1;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].y2 = gPokedexEntries[sPokedexListItem->dexNum].trainerOffset;
        SetOamMatrix(1, gPokedexEntries[sPokedexListItem->dexNum].trainerScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].trainerScale);
        LoadPalette(sSizeScreenSilhouette_Pal, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
        gTasks[taskId].tTrainerSpriteId = spriteId;
        gMain.state++;
        break;
    case 6:
        spriteId = CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, 88, 56, 1);
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 2;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].y2 = gPokedexEntries[sPokedexListItem->dexNum].pokemonOffset;
        SetOamMatrix(2, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale, 0, 0, gPokedexEntries[sPokedexListItem->dexNum].pokemonScale);
        LoadPalette(sSizeScreenSilhouette_Pal, (gSprites[spriteId].oam.paletteNum + 16) * 16, 0x20);
        gTasks[taskId].tMonSpriteId = spriteId;
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gMain.state++;
        break;
    case 8:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        HideBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 9:
        if (!gPaletteFade.active)
        {
            sPokedexView->screenSwitchState = 0;
            gMain.state = 0;
            gTasks[taskId].func = Task_HandleSizeScreenInput;
        }
        break;
    }
}

static void Task_HandleSizeScreenInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 1;
        gTasks[taskId].func = Task_SwitchScreensFromSizeScreen;
        PlaySE(SE_PC_OFF);
    }
    else if (JOY_NEW(DPAD_LEFT)
     || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
    {
        BeginNormalPaletteFade(PALETTES_ALL & ~(0x14), 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 2;
        gTasks[taskId].func = Task_SwitchScreensFromSizeScreen;
        PlaySE(SE_DEX_PAGE);
    }
}

static void Task_SwitchScreensFromSizeScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeAndDestroyTrainerPicSprite(gTasks[taskId].tTrainerSpriteId);
        switch (sPokedexView->screenSwitchState)
        {
        default:
        case 1:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadCryScreen;
            break;
        }
    }
}

#undef tScrolling
#undef tMonSpriteDone
#undef tBgLoaded
#undef tSkipCry
#undef tMonSpriteId
#undef tTrainerSpriteId

static void LoadScreenSelectBarMain(u16 unused)
{
    CopyToBgTilemapBuffer(1, gPokedexScreenSelectBarMain_Tilemap, 0, 0);
}

static void LoadScreenSelectBarSubmenu(u16 unused)
{
    CopyToBgTilemapBuffer(1, gPokedexScreenSelectBarSubmenu_Tilemap, 0, 0);
}

static void HighlightScreenSelectBarItem(u8 selectedScreen, u16 unused)
{
    u8 i;
    u8 j;
    u16 *ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < SCREEN_COUNT; i++)
    {
        u8 row = (i * 7) + 1;
        u16 newPalette;

        do
        {
            newPalette = 0x4000;
            if (i == selectedScreen)
                newPalette = 0x2000;
        } while (0);

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}

static void HighlightSubmenuScreenSelectBarItem(u8 a, u16 b)
{
    u8 i;
    u8 j;
    u16 *ptr = GetBgTilemapBuffer(1);

    for (i = 0; i < 4; i++)
    {
        u8 row = i * 7 + 1;
        u32 newPalette;

        do
        {
            if (i == a || i == 3)
                newPalette = 0x2000;
            else
                newPalette = 0x4000;
        } while (0);

        for (j = 0; j < 7; j++)
        {
            ptr[row + j] = (ptr[row + j] % 0x1000) | newPalette;
            ptr[row + j + 0x20] = (ptr[row + j + 0x20] % 0x1000) | newPalette;
        }
    }
    CopyBgTilemapBufferToVram(1);
}

#define tState         data[0]
#define tDexNum        data[1]
#define tPalTimer      data[2]
#define tMonSpriteId   data[3]
#define tOtIdLo        data[12]
#define tOtIdHi        data[13]
#define tPersonalityLo data[14]
#define tPersonalityHi data[15]

u8 DisplayCaughtMonDexPage(u16 dexNum, u32 otId, u32 personality)
{
    u8 taskId = CreateTask(Task_DisplayCaughtMonDexPage, 0);

    gTasks[taskId].tState = 0;
    gTasks[taskId].tDexNum = dexNum;
    gTasks[taskId].tOtIdLo = otId;
    gTasks[taskId].tOtIdHi = otId >> 16;
    gTasks[taskId].tPersonalityLo = personality;
    gTasks[taskId].tPersonalityHi = personality >> 16;
    return taskId;
}

static void Task_DisplayCaughtMonDexPage(u8 taskId)
{
    u8 spriteId;
    u16 dexNum = gTasks[taskId].tDexNum;

    switch (gTasks[taskId].tState)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            ResetOtherVideoRegisters(DISPCNT_BG0_ON);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sNewEntryInfoScreen_BgTemplate, ARRAY_COUNT(sNewEntryInfoScreen_BgTemplate));
            SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
            SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
            InitWindows(sNewEntryInfoScreen_WindowTemplates);
            DeactivateAllTextPrinters();
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        DecompressAndLoadBgGfxUsingHeap(3, gPokedexMenu_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, gPokedexInfoScreen_Tilemap, 0, 0);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_FOOTPRINT);
        DrawFootprint(WIN_FOOTPRINT, gTasks[taskId].tDexNum);
        CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);
        ResetPaletteFade();
        LoadPokedexBgPalette(FALSE);
        gTasks[taskId].tState++;
        break;
    case 2:
        gTasks[taskId].tState++;
        break;
    case 3:
        PrintMonInfo(dexNum, IsNationalPokedexEnabled(), 1, 1);
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gTasks[taskId].tState++;
        break;
    case 4:
        spriteId = CreateMonPicSprite(NationalPokedexNumToSpecies(dexNum), 0, ((u16)gTasks[taskId].tPersonalityHi << 16) | (u16)gTasks[taskId].tPersonalityLo, TRUE, MON_PAGE_X, MON_PAGE_Y, 0, TAG_NONE);
        gSprites[spriteId].oam.priority = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gTasks[taskId].tMonSpriteId = spriteId;
        gTasks[taskId].tState++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(2);
        ShowBg(3);
        gTasks[taskId].tState++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            PlayCry_Normal(NationalPokedexNumToSpecies(dexNum), 0);
            gTasks[taskId].tPalTimer = 0;
            gTasks[taskId].func = Task_HandleCaughtMonPageInput;
        }
        break;
    }
}

static void Task_HandleCaughtMonPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_BG, 0, 0, 16, RGB_BLACK);
        gSprites[gTasks[taskId].tMonSpriteId].callback = SpriteCB_SlideCaughtMonToCenter;
        gTasks[taskId].func = Task_ExitCaughtMonPage;
    }
    // Flicker caught screen color
    else if (++gTasks[taskId].tPalTimer & 16)
    {
        LoadPalette(gPokedexBgHoenn_Pal + 1, 0x31, 14);
    }
    else
    {
        LoadPalette(gPokedexCaughtScreen_Pal + 1, 0x31, 14);
    }
}

static void Task_ExitCaughtMonPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 species;
        u32 otId;
        u32 personality;
        u8 paletteNum;
        const u32 *lzPaletteData;
        void *buffer;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        FreeAllWindowBuffers();
        buffer = GetBgTilemapBuffer(2);
        if (buffer)
            Free(buffer);
        buffer = GetBgTilemapBuffer(3);
        if (buffer)
            Free(buffer);

        species = NationalPokedexNumToSpecies(gTasks[taskId].tDexNum);
        otId = ((u16)gTasks[taskId].tOtIdHi << 16) | (u16)gTasks[taskId].tOtIdLo;
        personality = ((u16)gTasks[taskId].tPersonalityHi << 16) | (u16)gTasks[taskId].tPersonalityLo;
        paletteNum = gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum;
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality);
        LoadCompressedPalette(lzPaletteData, 0x100 | paletteNum * 16, 32);
        DestroyTask(taskId);
    }
}

static void SpriteCB_SlideCaughtMonToCenter(struct Sprite *sprite)
{
    if (sprite->x < 0x78)
        sprite->x += 2;
    if (sprite->x > 0x78)
        sprite->x -= 2;

    if (sprite->y < 0x50)
        sprite->y += 1;
    if (sprite->y > 0x50)
        sprite->y -= 1;
}

#undef tState
#undef tDexNum
#undef tPalTimer
#undef tMonSpriteId
#undef tOtIdLo
#undef tOtIdHi
#undef tPersonalityLo
#undef tPersonalityHi

// u32 value is re-used, but passed as a bool that's TRUE if national dex is enabled
static void PrintMonInfo(u32 num, u32 value, u32 owned, u32 newEntry)
{
    u8 str[0x10];
    u8 str2[0x30];
    u16 natNum;
    const u8 *name;
    const u8 *category;
    const u8 *description;

    if (newEntry)
        PrintInfoScreenText(gText_PokedexRegistration, GetStringCenterAlignXOffset(FONT_NORMAL, gText_PokedexRegistration, 0xF0), 0);
    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, 3);
    PrintInfoScreenText(str, 0x60, 0x19);
    natNum = NationalPokedexNumToSpecies(num);
    if (natNum)
        name = gSpeciesNames[natNum];
    else
        name = sText_TenDashes2;
    PrintInfoScreenText(name, 0x84, 0x19);
    if (owned)
    {
        CopyMonCategoryText(num, str2);
        category = str2;
    }
    else
    {
        category = gText_5MarksPokemon;
    }
    PrintInfoScreenText(category, 0x64, 0x29);
    PrintInfoScreenText(gText_HTHeight, 0x60, 0x39);
    PrintInfoScreenText(gText_WTWeight, 0x60, 0x49);
    if (owned)
    {
        PrintMonHeight(gPokedexEntries[num].height, 0x81, 0x39);
        PrintMonWeight(gPokedexEntries[num].weight, 0x81, 0x49);
    }
    else
    {
        PrintInfoScreenText(gText_UnkHeight, 0x81, 0x39);
        PrintInfoScreenText(gText_UnkWeight, 0x81, 0x49);
    }
    if (owned)
        description = gPokedexEntries[num].description;
    else
        description = sExpandedPlaceholder_PokedexDescription;
    PrintInfoScreenText(description, GetStringCenterAlignXOffset(FONT_NORMAL, description, 0xF0), 0x5F);
}

static void PrintMonHeight(u16 height, u8 left, u8 top)
{
    u8 buffer[16];
    u32 inches, feet;
    u8 i = 0;

    inches = (height * 10000) / 254;
    if (inches % 10 >= 5)
        inches += 10;
    feet = inches / 120;
    inches = (inches - (feet * 120)) / 10;

    buffer[i++] = EXT_CTRL_CODE_BEGIN;
    buffer[i++] = EXT_CTRL_CODE_CLEAR_TO;
    if (feet / 10 == 0)
    {
        buffer[i++] = 18;
        buffer[i++] = feet + CHAR_0;
    }
    else
    {
        buffer[i++] = 12;
        buffer[i++] = feet / 10 + CHAR_0;
        buffer[i++] = (feet % 10) + CHAR_0;
    }
    buffer[i++] = CHAR_SGL_QUOTE_RIGHT;
    buffer[i++] = (inches / 10) + CHAR_0;
    buffer[i++] = (inches % 10) + CHAR_0;
    buffer[i++] = CHAR_DBL_QUOTE_RIGHT;
    buffer[i++] = EOS;
    PrintInfoScreenText(buffer, left, top);
}

static void PrintMonWeight(u16 weight, u8 left, u8 top)
{
    u8 buffer[16];
    bool8 output;
    u8 i;
    u32 lbs = (weight * 100000) / 4536;

    if (lbs % 10u >= 5)
        lbs += 10;
    i = 0;
    output = FALSE;

    if ((buffer[i] = (lbs / 100000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = CHAR_SPACER;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 100000;
    if ((buffer[i] = (lbs / 10000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = CHAR_SPACER;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 10000;
    if ((buffer[i] = (lbs / 1000) + CHAR_0) == CHAR_0 && !output)
    {
        buffer[i++] = CHAR_SPACER;
    }
    else
    {
        output = TRUE;
        i++;
    }

    lbs %= 1000;
    buffer[i++] = (lbs / 100) + CHAR_0;
    lbs %= 100;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = (lbs / 10) + CHAR_0;
    buffer[i++] = CHAR_SPACE;
    buffer[i++] = CHAR_l;
    buffer[i++] = CHAR_b;
    buffer[i++] = CHAR_s;
    buffer[i++] = CHAR_PERIOD;
    buffer[i++] = EOS;
    PrintInfoScreenText(buffer, left, top);
}

const u8 *GetPokedexCategoryName(u16 dexNum) // unused
{
    return gPokedexEntries[dexNum].categoryName;
}

u16 GetPokedexHeightWeight(u16 dexNum, u8 data)
{
    switch (data)
    {
    case 0:  // height
        return gPokedexEntries[dexNum].height;
    case 1:  // weight
        return gPokedexEntries[dexNum].weight;
    default:
        return 1;
    }
}

s8 GetSetPokedexFlag(u16 nationalDexNo, u8 caseID)
{
    u32 index, bit, mask;
    s8 retVal = 0;

    nationalDexNo--;
    index = nationalDexNo / 8;
    bit = nationalDexNo % 8;
    mask = 1 << bit;

    switch (caseID)
    {
    case FLAG_GET_SEEN:
        retVal = ((gSaveBlock1Ptr->dexSeen[index] & mask) != 0);
        break;
    case FLAG_GET_CAUGHT:
         retVal = ((gSaveBlock1Ptr->dexCaught[index] & mask) != 0);
        break;
    case FLAG_SET_SEEN:
        gSaveBlock1Ptr->dexSeen[index] |= mask;
        break;
    case FLAG_SET_CAUGHT:
        gSaveBlock1Ptr->dexCaught[index] |= mask;
        break;
    }

    return retVal;
}

u16 GetNationalPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 GetHoennPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < HOENN_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

u16 GetKantoPokedexCount(u8 caseID)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < KANTO_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
                count++;
            break;
        }
    }
    return count;
}

bool16 HasAllHoennMons(void)
{
    u16 i;

    // -2 excludes Jirachi and Deoxys
    for (i = 0; i < HOENN_DEX_COUNT - 2; i++)
    {
        if (!GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

bool8 HasAllKantoMons(void)
{
    u16 i;

    // -1 excludes Mew
    for (i = 0; i < KANTO_DEX_COUNT - 1; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllMons(void)
{
    u16 i;

    for (i = 1; i < NATIONAL_DEX_COUNT + 1; i++)
    {
        if (!(gBaseStats[i].flags & SPECIES_FLAG_MYTHICAL) && !GetSetPokedexFlag(i, FLAG_GET_CAUGHT))
            return FALSE;
    }

    return TRUE;
}

static void ResetOtherVideoRegisters(u16 regBits)
{
    if (!(regBits & DISPCNT_BG0_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    }
    if (!(regBits & DISPCNT_BG1_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG1_ON);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
    if (!(regBits & DISPCNT_BG2_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    }
    if (!(regBits & DISPCNT_BG3_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    }
    if (!(regBits & DISPCNT_OBJ_ON))
    {
        ClearGpuRegBits(0, DISPCNT_OBJ_ON);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
    }
}

static void PrintInfoSubMenuText(u8 windowId, const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(windowId, FONT_NORMAL, left, top, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static void UnusedPrintNum(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[4];

    str[0] = CHAR_0 + num / 100;
    str[1] = CHAR_0 + (num % 100) / 10;
    str[2] = CHAR_0 + (num % 100) % 10;
    str[3] = EOS;
    PrintInfoSubMenuText(windowId, str, left, top);
}

static u8 PrintCryScreenSpeciesName(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[POKEMON_NAME_LENGTH + 1];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(str); i++)
        str[i] = EOS;
    num = NationalPokedexNumToSpecies(num);
    switch (num)
    {
    default:
        for (i = 0; gSpeciesNames[num][i] != EOS && i < POKEMON_NAME_LENGTH; i++)
            str[i] = gSpeciesNames[num][i];
        break;
    case 0:
        for (i = 0; i < 5; i++)
            str[i] = CHAR_HYPHEN;
        break;
    }
    PrintInfoSubMenuText(windowId, str, left, top);
    return i;
}

static void UnusedPrintMonName(u8 windowId, const u8 *name, u8 left, u8 top)
{
    u8 str[POKEMON_NAME_LENGTH + 1];
    u8 i;
    u8 nameLength;

    for (i = 0; i < ARRAY_COUNT(str); i++)
        str[i] = CHAR_SPACE;
    for (nameLength = 0; name[nameLength] != CHAR_SPACE && nameLength < ARRAY_COUNT(str); nameLength++)
        ;
    for (i = 0; i < nameLength; i++)
        str[ARRAY_COUNT(str) - nameLength + i] = name[i];
#ifdef UBFIX
    str[ARRAY_COUNT(str) - 1] = EOS;
#else
    str[ARRAY_COUNT(str)] = EOS;
#endif
    PrintInfoSubMenuText(windowId, str, left, top);
}

// Unused in the English version, used to print height/weight in versions which use metric system.
static void PrintDecimalNum(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[6];
    bool8 outputted = FALSE;
    u8 result;

    result = num / 1000;
    if (result == 0)
    {
        str[0] = CHAR_SPACER;
        outputted = FALSE;
    }
    else
    {
        str[0] = CHAR_0 + result;
        outputted = TRUE;
    }

    result = (num % 1000) / 100;
    if (result == 0 && !outputted)
    {
        str[1] = CHAR_SPACER;
        outputted = FALSE;
    }
    else
    {
        str[1] = CHAR_0 + result;
        outputted = TRUE;
    }

    str[2] = CHAR_0 + ((num % 1000) % 100) / 10;
    str[3] = CHAR_DEC_SEPARATOR;
    str[4] = CHAR_0 + ((num % 1000) % 100) % 10;
    str[5] = EOS;
    PrintInfoSubMenuText(windowId, str, left, top);
}

static void DrawFootprint(u8 windowId, u16 dexNum)
{
    u8 footprint[32 * 4] = {0};
    const u8 *footprintGfx = gMonFootprintTable[NationalPokedexNumToSpecies(dexNum)];
    u32 i, j, tileIdx = 0;

    if (footprintGfx != NULL)
    {
        for (i = 0; i < 32; i++)
        {
            u8 tile = footprintGfx[i];
            for (j = 0; j < 4; j++)
            {
                u8 value = ((tile >> (2 * j)) & 1 ? 2 : 0);
                if (tile & (2 << (2 * j)))
                    value |= 0x20;
                footprint[tileIdx] = value;
                tileIdx++;
            }
        }
    }
    CopyToWindowPixelBuffer(windowId, footprint, sizeof(footprint), 0);
}

// Unused Ruby/Sapphire function.
static void RS_DrawFootprint(u16 offset, u16 tileNum)
{
    *(u16 *)(VRAM + offset * 0x800 + 0x232) = 0xF000 + tileNum + 0;
    *(u16 *)(VRAM + offset * 0x800 + 0x234) = 0xF000 + tileNum + 1;
    *(u16 *)(VRAM + offset * 0x800 + 0x272) = 0xF000 + tileNum + 2;
    *(u16 *)(VRAM + offset * 0x800 + 0x274) = 0xF000 + tileNum + 3;
}

static u16 GetNextPosition(u8 direction, u16 position, u16 min, u16 max)
{
    switch (direction)
    {
    case 1: // Up/Left
        if (position > min)
            position--;
        break;
    case 0: // Down/Right
        if (position < max)
            position++;
        break;
    case 3: // Up/Left with loop (unused)
        if (position > min)
            position--;
        else
            position = max;
        break;
    case 2: // Down/Right with loop (unused)
        if (position < max)
            position++;
        else
            position = min;
        break;
    }
    return position;
}

// Unown and Spinda use the personality of the first seen individual of that species
// All others use personality 0
static u32 GetPokedexMonPersonality(u16 species)
{
    if (species == SPECIES_UNOWN || species == SPECIES_SPINDA)
    {
        if (species == SPECIES_UNOWN)
            return gSaveBlock2Ptr->pokedex.unownPersonality;
        else
            return gSaveBlock2Ptr->pokedex.spindaPersonality;
    }
    else
    {
        return 0xFF; //Changed from 0 to make it so the Pokédex shows the default mon pics instead of the female versions.
    }
}

u16 CreateMonSpriteFromNationalDexNumber(u16 nationalNum, s16 x, s16 y, u16 paletteSlot)
{
    nationalNum = NationalPokedexNumToSpecies(nationalNum);
    return CreateMonPicSprite(nationalNum, SHINY_ODDS, GetPokedexMonPersonality(nationalNum), TRUE, x, y, paletteSlot, TAG_NONE);
}

static u16 CreateSizeScreenTrainerPic(u16 species, s16 x, s16 y, s8 paletteSlot)
{
    return CreateTrainerPicSprite(species, TRUE, x, y, paletteSlot, TAG_NONE);
}

static int DoPokedexSearch(u8 dexMode, u8 order, u8 abcGroup, u8 bodyColor, u8 type1, u8 type2)
{
    u16 species;
    u16 i;
    u16 resultsCount;
    u8 types[2];

    CreatePokedexList(dexMode, order);

    for (i = 0, resultsCount = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        if (sPokedexView->pokedexList[i].seen)
        {
            sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
            resultsCount++;
        }
    }
    sPokedexView->pokemonListCount = resultsCount;

    // Search by name
    if (abcGroup != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            u8 firstLetter;

            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);
            firstLetter = gSpeciesNames[species][0];
            if (LETTER_IN_RANGE_UPPER(firstLetter, abcGroup) || LETTER_IN_RANGE_LOWER(firstLetter, abcGroup))
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by body color
    if (bodyColor != 0xFF)
    {
        for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
        {
            species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

            if (bodyColor == gBaseStats[species].bodyColor)
            {
                sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                resultsCount++;
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    // Search by type
    if (type1 != TYPE_NONE || type2 != TYPE_NONE)
    {
        if (type1 == TYPE_NONE)
        {
            type1 = type2;
            type2 = TYPE_NONE;
        }

        if (type2 == TYPE_NONE)
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if (types[0] == type1 || types[1] == type1)
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        else
        {
            for (i = 0, resultsCount = 0; i < sPokedexView->pokemonListCount; i++)
            {
                if (sPokedexView->pokedexList[i].owned)
                {
                    species = NationalPokedexNumToSpecies(sPokedexView->pokedexList[i].dexNum);

                    types[0] = gBaseStats[species].type1;
                    types[1] = gBaseStats[species].type2;
                    if ((types[0] == type1 && types[1] == type2) || (types[0] == type2 && types[1] == type1))
                    {
                        sPokedexView->pokedexList[resultsCount] = sPokedexView->pokedexList[i];
                        resultsCount++;
                    }
                }
            }
        }
        sPokedexView->pokemonListCount = resultsCount;
    }

    if (sPokedexView->pokemonListCount != 0)
    {
        for (i = sPokedexView->pokemonListCount; i < NATIONAL_DEX_COUNT; i++)
        {
            sPokedexView->pokedexList[i].dexNum = 0xFFFF;
            sPokedexView->pokedexList[i].seen = FALSE;
            sPokedexView->pokedexList[i].owned = FALSE;
        }
    }

    return resultsCount;
}

static u8 LoadSearchMenu(void)
{
    return CreateTask(Task_LoadSearchMenu, 0);
}

static void PrintSearchText(const u8 *str, u32 x, u32 y)
{
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_DARK_GRAY;
    AddTextPrinterParameterized4(0, FONT_NORMAL, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static void ClearSearchMenuRect(u32 x, u32 y, u32 width, u32 height)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x, y, width, height);
}

// Search task data
#define tTopBarItem             data[0]
#define tMenuItem               data[1]
#define tCursorPos_Mode         data[2]
#define tScrollOffset_Mode      data[3]
#define tCursorPos_Order        data[4]
#define tScrollOffset_Order     data[5]
#define tCursorPos_Name         data[6]
#define tScrollOffset_Name      data[7]
#define tCursorPos_Color        data[8]
#define tScrollOffset_Color     data[9]
#define tCursorPos_TypeLeft     data[10]
#define tScrollOffset_TypeLeft  data[11]
#define tCursorPos_TypeRight    data[12]
#define tScrollOffset_TypeRight data[13]
#define tCursorPos              data[14]
#define tScrollOffset           data[15]

static void Task_LoadSearchMenu(u8 taskId)
{
    u16 i;

    switch (gMain.state)
    {
    default:
    case 0:
        if (!gPaletteFade.active)
        {
            sPokedexView->currentPage = PAGE_SEARCH;
            ResetOtherVideoRegisters(0);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sSearchMenu_BgTemplate, ARRAY_COUNT(sSearchMenu_BgTemplate));
            SetBgTilemapBuffer(3, AllocZeroed(BG_SCREEN_SIZE));
            SetBgTilemapBuffer(2, AllocZeroed(BG_SCREEN_SIZE));
            SetBgTilemapBuffer(1, AllocZeroed(BG_SCREEN_SIZE));
            SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
            InitWindows(sSearchMenu_WindowTemplate);
            DeactivateAllTextPrinters();
            PutWindowTilemap(0);
            DecompressAndLoadBgGfxUsingHeap(3, gPokedexSearchMenu_Gfx, 0x2000, 0, 0);

            if (!IsNationalPokedexEnabled())
                CopyToBgTilemapBuffer(3, gPokedexSearchMenuHoenn_Tilemap, 0, 0);
            else
                CopyToBgTilemapBuffer(3, gPokedexSearchMenuNational_Tilemap, 0, 0);
            LoadPalette(gPokedexSearchMenu_Pal + 1, 1, 0x7E);
            gMain.state = 1;
        }
        break;
    case 1:
        LoadCompressedSpriteSheet(sInterfaceSpriteSheet);
        LoadSpritePalettes(sInterfaceSpritePalette);
        CreateSearchParameterScrollArrows(taskId);
        for (i = 0; i < NUM_TASK_DATA; i++)
            gTasks[taskId].data[i] = 0;
        SetDefaultSearchModeAndOrder(taskId);
        HighlightSelectedSearchTopBarItem(SEARCH_TOPBAR_SEARCH);
        PrintSelectedSearchParameters(taskId);
        CopyWindowToVram(0, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 3:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        HideBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gMain.state++;
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].func = Task_SwitchToSearchMenuTopBar;
            gMain.state = 0;
        }
        break;
    }
}

static void FreeSearchWindowAndBgBuffers(void)
{
    void *tilemapBuffer;

    FreeAllWindowBuffers();
    tilemapBuffer = GetBgTilemapBuffer(0);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(1);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(2);
    if (tilemapBuffer)
        Free(tilemapBuffer);
    tilemapBuffer = GetBgTilemapBuffer(3);
    if (tilemapBuffer)
        Free(tilemapBuffer);
}

static void Task_SwitchToSearchMenuTopBar(u8 taskId)
{
    HighlightSelectedSearchTopBarItem(gTasks[taskId].tTopBarItem);
    PrintSelectedSearchParameters(taskId);
    CopyWindowToVram(0, COPYWIN_GFX);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = Task_HandleSearchTopBarInput;
}

static void Task_HandleSearchTopBarInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        gTasks[taskId].func = Task_ExitSearch;
        return;
    }
    if (JOY_NEW(A_BUTTON))
    {
        switch (gTasks[taskId].tTopBarItem)
        {
        case SEARCH_TOPBAR_SEARCH:
            PlaySE(SE_PIN);
            gTasks[taskId].tMenuItem = SEARCH_NAME;
            gTasks[taskId].func = Task_SwitchToSearchMenu;
            break;
        case SEARCH_TOPBAR_SHIFT:
            PlaySE(SE_PIN);
            gTasks[taskId].tMenuItem = SEARCH_ORDER;
            gTasks[taskId].func = Task_SwitchToSearchMenu;
            break;
        case SEARCH_TOPBAR_CANCEL:
            PlaySE(SE_PC_OFF);
            gTasks[taskId].func = Task_ExitSearch;
            break;
        }
        return;
    }
    if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tTopBarItem > SEARCH_TOPBAR_SEARCH)
    {
        PlaySE(SE_DEX_PAGE);
        gTasks[taskId].tTopBarItem--;
        HighlightSelectedSearchTopBarItem(gTasks[taskId].tTopBarItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
    if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tTopBarItem < SEARCH_TOPBAR_CANCEL)
    {
        PlaySE(SE_DEX_PAGE);
        gTasks[taskId].tTopBarItem++;
        HighlightSelectedSearchTopBarItem(gTasks[taskId].tTopBarItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
}

static void Task_SwitchToSearchMenu(u8 taskId)
{
    HighlightSelectedSearchMenuItem(gTasks[taskId].tTopBarItem, gTasks[taskId].tMenuItem);
    PrintSelectedSearchParameters(taskId);
    CopyWindowToVram(0, COPYWIN_GFX);
    CopyBgTilemapBufferToVram(3);
    gTasks[taskId].func = Task_HandleSearchMenuInput;
}

// Input for main search menu
static void Task_HandleSearchMenuInput(u8 taskId)
{
    const u8 (*movementMap)[4];

    if (gTasks[taskId].tTopBarItem != SEARCH_TOPBAR_SEARCH)
    {
        if (!IsNationalPokedexEnabled())
            movementMap = sSearchMovementMap_ShiftHoennDex;
        else
            movementMap = sSearchMovementMap_ShiftNatDex;
    }
    else
    {
        if (!IsNationalPokedexEnabled())
            movementMap = sSearchMovementMap_SearchHoennDex;
        else
            movementMap = sSearchMovementMap_SearchNatDex;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_BALL);
        SetDefaultSearchModeAndOrder(taskId);
        gTasks[taskId].func = Task_SwitchToSearchMenuTopBar;
        return;
    }
    if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuItem == SEARCH_OK)
        {
            if (gTasks[taskId].tTopBarItem != SEARCH_TOPBAR_SEARCH)
            {
                sPokeBallRotation = POKEBALL_ROTATION_TOP;
                sPokedexView->pokeBallRotationBackup = POKEBALL_ROTATION_TOP;
                sLastSelectedPokemon = 0;
                sPokedexView->selectedPokemonBackup = 0;
                gSaveBlock2Ptr->pokedex.mode = GetSearchModeSelection(taskId, SEARCH_MODE);
                if (!IsNationalPokedexEnabled())
                    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_HOENN;
                sPokedexView->dexModeBackup = gSaveBlock2Ptr->pokedex.mode;
                gSaveBlock2Ptr->pokedex.order = GetSearchModeSelection(taskId, SEARCH_ORDER);
                sPokedexView->dexOrderBackup = gSaveBlock2Ptr->pokedex.order;
                PlaySE(SE_PC_OFF);
                gTasks[taskId].func = Task_ExitSearch;
            }
            else
            {
                EraseAndPrintSearchTextBox(gText_SearchingPleaseWait);
                gTasks[taskId].func = Task_StartPokedexSearch;
                PlaySE(SE_DEX_SEARCH);
                CopyWindowToVram(0, COPYWIN_GFX);
            }
        }
        else
        {
            PlaySE(SE_PIN);
            gTasks[taskId].func = Task_SelectSearchMenuItem;
        }
        return;
    }

    if (JOY_NEW(DPAD_LEFT) && movementMap[gTasks[taskId].tMenuItem][0] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].tMenuItem = movementMap[gTasks[taskId].tMenuItem][0];
        HighlightSelectedSearchMenuItem(gTasks[taskId].tTopBarItem, gTasks[taskId].tMenuItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
    if (JOY_NEW(DPAD_RIGHT) && movementMap[gTasks[taskId].tMenuItem][1] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].tMenuItem = movementMap[gTasks[taskId].tMenuItem][1];
        HighlightSelectedSearchMenuItem(gTasks[taskId].tTopBarItem, gTasks[taskId].tMenuItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
    if (JOY_NEW(DPAD_UP) && movementMap[gTasks[taskId].tMenuItem][2] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].tMenuItem = movementMap[gTasks[taskId].tMenuItem][2];
        HighlightSelectedSearchMenuItem(gTasks[taskId].tTopBarItem, gTasks[taskId].tMenuItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
    if (JOY_NEW(DPAD_DOWN) && movementMap[gTasks[taskId].tMenuItem][3] != 0xFF)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].tMenuItem = movementMap[gTasks[taskId].tMenuItem][3];
        HighlightSelectedSearchMenuItem(gTasks[taskId].tTopBarItem, gTasks[taskId].tMenuItem);
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
    }
}

static void Task_StartPokedexSearch(u8 taskId)
{
    u8 dexMode = GetSearchModeSelection(taskId, SEARCH_MODE);
    u8 order = GetSearchModeSelection(taskId, SEARCH_ORDER);
    u8 abcGroup = GetSearchModeSelection(taskId, SEARCH_NAME);
    u8 bodyColor = GetSearchModeSelection(taskId, SEARCH_COLOR);
    u8 type1 = GetSearchModeSelection(taskId, SEARCH_TYPE_LEFT);
    u8 type2 = GetSearchModeSelection(taskId, SEARCH_TYPE_RIGHT);

    DoPokedexSearch(dexMode, order, abcGroup, bodyColor, type1, type2);
    gTasks[taskId].func = Task_WaitAndCompleteSearch;
}

static void Task_WaitAndCompleteSearch(u8 taskId)
{
    if (!IsSEPlaying())
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            PlaySE(SE_SUCCESS);
            EraseAndPrintSearchTextBox(gText_SearchCompleted);
        }
        else
        {
            PlaySE(SE_FAILURE);
            EraseAndPrintSearchTextBox(gText_NoMatchingPkmnWereFound);
        }
        gTasks[taskId].func = Task_SearchCompleteWaitForInput;
        CopyWindowToVram(0, COPYWIN_GFX);
    }
}

static void Task_SearchCompleteWaitForInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (sPokedexView->pokemonListCount != 0)
        {
            // Return to dex list and show search results
            sPokedexView->screenSwitchState = 1;
            sPokedexView->dexMode = GetSearchModeSelection(taskId, SEARCH_MODE);
            sPokedexView->dexOrder = GetSearchModeSelection(taskId, SEARCH_ORDER);
            gTasks[taskId].func = Task_ExitSearch;
            PlaySE(SE_PC_OFF);
        }
        else
        {
            gTasks[taskId].func = Task_SwitchToSearchMenu;
            PlaySE(SE_BALL);
        }
    }
}

static void Task_SelectSearchMenuItem(u8 taskId)
{
    u8 menuItem;
    u16 *cursorPos;
    u16 *scrollOffset;

    DrawOrEraseSearchParameterBox(FALSE);
    menuItem = gTasks[taskId].tMenuItem;
    cursorPos = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataCursorPos];
    scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
    gTasks[taskId].tCursorPos = *cursorPos;
    gTasks[taskId].tScrollOffset = *scrollOffset;
    PrintSearchParameterText(taskId);
    PrintSelectorArrow(*cursorPos);
    gTasks[taskId].func = Task_HandleSearchParameterInput;
    CopyWindowToVram(0, COPYWIN_GFX);
    CopyBgTilemapBufferToVram(3);
}

// Input for scrolling parameter box in right column
static void Task_HandleSearchParameterInput(u8 taskId)
{
    u8 menuItem;
    const struct SearchOptionText *texts;
    u16 *cursorPos;
    u16 *scrollOffset;
    u16 maxOption;
    bool8 moved;

    menuItem = gTasks[taskId].tMenuItem;
    texts = sSearchOptions[menuItem].texts;
    cursorPos = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataCursorPos];
    scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
    maxOption = sSearchOptions[menuItem].numOptions - 1;
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_PIN);
        ClearSearchParameterBoxText();
        DrawOrEraseSearchParameterBox(TRUE);
        gTasks[taskId].func = Task_SwitchToSearchMenu;
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_BALL);
        ClearSearchParameterBoxText();
        DrawOrEraseSearchParameterBox(TRUE);
        *cursorPos = gTasks[taskId].tCursorPos;
        *scrollOffset = gTasks[taskId].tScrollOffset;
        gTasks[taskId].func = Task_SwitchToSearchMenu;
        CopyWindowToVram(0, COPYWIN_GFX);
        CopyBgTilemapBufferToVram(3);
        return;
    }
    moved = FALSE;
    if (JOY_REPEAT(DPAD_UP))
    {
        if (*cursorPos != 0)
        {
            // Move cursor up
            EraseSelectorArrow(*cursorPos);
            (*cursorPos)--;
            PrintSelectorArrow(*cursorPos);
            moved = TRUE;
        }
        else if (*scrollOffset != 0)
        {
            // Scroll up
            (*scrollOffset)--;
            PrintSearchParameterText(taskId);
            PrintSelectorArrow(*cursorPos);
            moved = TRUE;
        }
        if (moved)
        {
            PlaySE(SE_SELECT);
            EraseAndPrintSearchTextBox(texts[*cursorPos + *scrollOffset].description);
            CopyWindowToVram(0, COPYWIN_GFX);
        }
        return;
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        if (*cursorPos < MAX_SEARCH_PARAM_CURSOR_POS && *cursorPos < maxOption)
        {
            // Move cursor down
            EraseSelectorArrow(*cursorPos);
            (*cursorPos)++;
            PrintSelectorArrow(*cursorPos);
            moved = TRUE;
        }
        else if (maxOption > MAX_SEARCH_PARAM_CURSOR_POS && *scrollOffset < maxOption - MAX_SEARCH_PARAM_CURSOR_POS)
        {
            // Scroll down
            (*scrollOffset)++;
            PrintSearchParameterText(taskId);
            PrintSelectorArrow(5);
            moved = TRUE;
        }
        if (moved)
        {
            PlaySE(SE_SELECT);
            EraseAndPrintSearchTextBox(texts[*cursorPos + *scrollOffset].description);
            CopyWindowToVram(0, COPYWIN_GFX);
        }
        return;
    }
}

static void Task_ExitSearch(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitSearchWaitForFade;
}

static void Task_ExitSearchWaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeSearchWindowAndBgBuffers();
        DestroyTask(taskId);
    }
}

void SetSearchRectHighlight(u8 flags, u8 x, u8 y, u8 width)
{
    u16 i;
    u16 temp; //should be a pointer, but does not match as one
    u32 ptr = (u32)GetBgTilemapBuffer(3); //same as above

    for (i = 0; i < width; i++)
    {
        temp = *(u16 *)(ptr + (y + 0) * 64 + (x + i) * 2);
        temp &= 0x0fff;
        temp |= (flags << 12);
        *(u16 *)(ptr + (y + 0) * 64 + (x + i) * 2) = temp;

        temp = *(u16 *)(ptr + (y + 1) * 64 + (x + i) * 2);
        temp &= 0x0fff;
        temp |= (flags << 12);
        *(u16 *)(ptr + (y + 1) * 64 + (x + i) * 2) = temp;
    }
}

#define SEARCH_BG_SEARCH                SEARCH_TOPBAR_SEARCH
#define SEARCH_BG_SHIFT                 SEARCH_TOPBAR_SHIFT
#define SEARCH_BG_CANCEL                SEARCH_TOPBAR_CANCEL
#define SEARCH_BG_NAME                  (SEARCH_NAME + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_COLOR                 (SEARCH_COLOR + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_TYPE_SELECTION_LEFT   (SEARCH_TYPE_LEFT + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_TYPE_SELECTION_RIGHT  (SEARCH_TYPE_RIGHT + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_ORDER                 (SEARCH_ORDER + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_MODE                  (SEARCH_MODE + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_OK                    (SEARCH_OK + SEARCH_TOPBAR_COUNT)
#define SEARCH_BG_TYPE_TITLE            (SEARCH_COUNT + SEARCH_TOPBAR_COUNT)

static void DrawSearchMenuItemBgHighlight(u8 searchBg, bool8 unselected, bool8 disabled)
{
    u8 highlightFlags = (unselected & 1) | ((disabled & 1) << 1);

    switch (searchBg)
    {
    case SEARCH_BG_SEARCH:
    case SEARCH_BG_SHIFT:
    case SEARCH_BG_CANCEL:
        SetSearchRectHighlight(highlightFlags, sSearchMenuTopBarItems[searchBg].highlightX, sSearchMenuTopBarItems[searchBg].highlightY, sSearchMenuTopBarItems[searchBg].highlightWidth);
        break;
    case SEARCH_BG_NAME:
    case SEARCH_BG_COLOR:
    case SEARCH_BG_ORDER:
    case SEARCH_BG_MODE:
        SetSearchRectHighlight(highlightFlags, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgX, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgY, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgWidth);
        // fall through, draw selectionBg for above
    case SEARCH_BG_TYPE_SELECTION_LEFT:
    case SEARCH_BG_TYPE_SELECTION_RIGHT:
        SetSearchRectHighlight(highlightFlags, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].selectionBgX, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].selectionBgY, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].selectionBgWidth);
        break;
    case SEARCH_BG_TYPE_TITLE:
        SetSearchRectHighlight(highlightFlags, sSearchMenuItems[SEARCH_TYPE_LEFT].titleBgX, sSearchMenuItems[SEARCH_TYPE_LEFT].titleBgY, sSearchMenuItems[SEARCH_TYPE_LEFT].titleBgWidth);
        break;
    case SEARCH_BG_OK:
        if (!IsNationalPokedexEnabled())
            SetSearchRectHighlight(highlightFlags, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgX, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgY - 2, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgWidth);
        else
            SetSearchRectHighlight(highlightFlags, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgX, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgY, sSearchMenuItems[searchBg - SEARCH_TOPBAR_COUNT].titleBgWidth);
        break;
    }
}

static void SetInitialSearchMenuBgHighlights(u8 topBarItem)
{
    switch (topBarItem)
    {
    case SEARCH_TOPBAR_SEARCH:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SEARCH, FALSE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SHIFT, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_CANCEL, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_NAME, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_COLOR, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_TITLE, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_LEFT, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_RIGHT, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_ORDER, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_MODE, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_OK, TRUE, FALSE);
        break;
    case SEARCH_TOPBAR_SHIFT:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SEARCH, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SHIFT, FALSE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_CANCEL, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_NAME, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_COLOR, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_TITLE, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_LEFT, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_RIGHT, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_ORDER, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_MODE, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_OK, TRUE, FALSE);
        break;
    case SEARCH_TOPBAR_CANCEL:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SEARCH, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_SHIFT, TRUE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_CANCEL, FALSE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_NAME, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_COLOR, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_TITLE, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_LEFT, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_RIGHT, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_ORDER, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_MODE, TRUE, TRUE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_OK, TRUE, TRUE);
        break;
    }
}

static void HighlightSelectedSearchTopBarItem(u8 topBarItem)
{
    SetInitialSearchMenuBgHighlights(topBarItem);
    EraseAndPrintSearchTextBox(sSearchMenuTopBarItems[topBarItem].description);
}

static void HighlightSelectedSearchMenuItem(u8 topBarItem, u8 menuItem)
{
    SetInitialSearchMenuBgHighlights(topBarItem);
    switch (menuItem)
    {
    case SEARCH_NAME:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_NAME, FALSE, FALSE);
        break;
    case SEARCH_COLOR:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_COLOR, FALSE, FALSE);
        break;
    case SEARCH_TYPE_LEFT:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_TITLE, FALSE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_LEFT, FALSE, FALSE);
        break;
    case SEARCH_TYPE_RIGHT:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_TITLE, FALSE, FALSE);
        DrawSearchMenuItemBgHighlight(SEARCH_BG_TYPE_SELECTION_RIGHT, FALSE, FALSE);
        break;
    case SEARCH_ORDER:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_ORDER, FALSE, FALSE);
        break;
    case SEARCH_MODE:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_MODE, FALSE, FALSE);
        break;
    case SEARCH_OK:
        DrawSearchMenuItemBgHighlight(SEARCH_BG_OK, FALSE, FALSE);
        break;
    }
    EraseAndPrintSearchTextBox(sSearchMenuItems[menuItem].description);
}

// Prints the currently selected search parameters in the search menu selection boxes
static void PrintSelectedSearchParameters(u8 taskId)
{
    u16 searchParamId;

    ClearSearchMenuRect(40, 16, 96, 80);

    searchParamId = gTasks[taskId].tCursorPos_Name + gTasks[taskId].tScrollOffset_Name;
    PrintSearchText(sDexSearchNameOptions[searchParamId].title, 0x2D, 0x11);

    searchParamId = gTasks[taskId].tCursorPos_Color + gTasks[taskId].tScrollOffset_Color;
    PrintSearchText(sDexSearchColorOptions[searchParamId].title, 0x2D, 0x21);

    searchParamId = gTasks[taskId].tCursorPos_TypeLeft + gTasks[taskId].tScrollOffset_TypeLeft;
    PrintSearchText(sDexSearchTypeOptions[searchParamId].title, 0x2D, 0x31);

    searchParamId = gTasks[taskId].tCursorPos_TypeRight + gTasks[taskId].tScrollOffset_TypeRight;
    PrintSearchText(sDexSearchTypeOptions[searchParamId].title, 0x5D, 0x31);

    searchParamId = gTasks[taskId].tCursorPos_Order + gTasks[taskId].tScrollOffset_Order;
    PrintSearchText(sDexOrderOptions[searchParamId].title, 0x2D, 0x41);

    if (IsNationalPokedexEnabled())
    {
        searchParamId = gTasks[taskId].tCursorPos_Mode + gTasks[taskId].tScrollOffset_Mode;
        PrintSearchText(sDexModeOptions[searchParamId].title, 0x2D, 0x51);
    }
}

static void DrawOrEraseSearchParameterBox(bool8 erase)
{
    u16 i;
    u16 j;
    u16 *ptr = GetBgTilemapBuffer(3);

    if (!erase)
    {
        *(ptr + 0x11) = 0xC0B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + i) = 0x80D;
        for (j = 1; j < 13; j++)
        {
            *(ptr + 0x11 + j * 32) = 0x40A;
            for (i = 0x12; i < 0x1F; i++)
                *(ptr + j * 32 + i) = 2;
        }
        *(ptr + 0x1B1) = 0x40B;
        for (i = 0x12; i < 0x1F; i++)
            *(ptr + 0x1A0 + i) = 0xD;
    }
    else
    {
        for (j = 0; j < 14; j++)
        {
            for (i = 0x11; i < 0x1E; i++)
            {
                *(ptr + j * 32 + i) = 0x4F;
            }
        }
    }
}

// Prints the currently viewable search parameter titles in the right-hand text box
// and the currently selected search parameter description in the bottom text box
static void PrintSearchParameterText(u8 taskId)
{
    const struct SearchOptionText *texts = sSearchOptions[gTasks[taskId].tMenuItem].texts;
    const u16 *cursorPos = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].tMenuItem].taskDataCursorPos];
    const u16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].tMenuItem].taskDataScrollOffset];
    u16 i;
    u16 j;

    ClearSearchParameterBoxText();

    for (i = 0, j = *scrollOffset; i < MAX_SEARCH_PARAM_ON_SCREEN && texts[j].title != NULL; i++, j++)
        PrintSearchParameterTitle(i, texts[j].title);

    EraseAndPrintSearchTextBox(texts[*cursorPos + *scrollOffset].description);
}

static u8 GetSearchModeSelection(u8 taskId, u8 option)
{
    const u16 *cursorPos = &gTasks[taskId].data[sSearchOptions[option].taskDataCursorPos];
    const u16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[option].taskDataScrollOffset];
    u16 id = *cursorPos + *scrollOffset;

    switch (option)
    {
    default:
        return 0;
    case SEARCH_MODE:
        return sPokedexModes[id];
    case SEARCH_ORDER:
        return sOrderOptions[id];
    case SEARCH_NAME:
        if (id == 0)
            return 0xFF;
        else
            return id;
    case SEARCH_COLOR:
        if (id == 0)
            return 0xFF;
        else
            return id - 1;
    case SEARCH_TYPE_LEFT:
    case SEARCH_TYPE_RIGHT:
        return sDexSearchTypeIds[id];
    }
}

static void SetDefaultSearchModeAndOrder(u8 taskId)
{
    u16 selected;

    switch (sPokedexView->dexModeBackup)
    {
    default:
    case DEX_MODE_HOENN:
        selected = DEX_MODE_HOENN;
        break;
    case DEX_MODE_NATIONAL:
        selected = DEX_MODE_NATIONAL;
        break;
    }
    gTasks[taskId].tCursorPos_Mode = selected;

    switch (sPokedexView->dexOrderBackup)
    {
    default:
    case ORDER_NUMERICAL:
        selected = ORDER_NUMERICAL;
        break;
    case ORDER_ALPHABETICAL:
        selected = ORDER_ALPHABETICAL;
        break;
    case ORDER_HEAVIEST:
        selected = ORDER_HEAVIEST;
        break;
    case ORDER_LIGHTEST:
        selected = ORDER_LIGHTEST;
        break;
    case ORDER_TALLEST:
        selected = ORDER_TALLEST;
        break;
    case ORDER_SMALLEST:
        selected = ORDER_SMALLEST;
        break;
    }
    gTasks[taskId].tCursorPos_Order = selected;
}

static bool8 SearchParamCantScrollUp(u8 taskId)
{
    u8 menuItem = gTasks[taskId].tMenuItem;
    const u16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
    u16 lastOption = sSearchOptions[menuItem].numOptions - 1;

    if (lastOption > MAX_SEARCH_PARAM_CURSOR_POS && *scrollOffset != 0)
        return FALSE;
    else
        return TRUE;
}

static bool8 SearchParamCantScrollDown(u8 taskId)
{
    u8 menuItem = gTasks[taskId].tMenuItem;
    const u16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
    u16 lastOption = sSearchOptions[menuItem].numOptions - 1;

    if (lastOption > MAX_SEARCH_PARAM_CURSOR_POS && *scrollOffset < lastOption - MAX_SEARCH_PARAM_CURSOR_POS)
        return FALSE;
    else
        return TRUE;
}

#define sTaskId      data[0]

static void SpriteCB_SearchParameterScrollArrow(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].func == Task_HandleSearchParameterInput)
    {
        u8 val;

        if (sprite->sIsDownArrow)
        {
            if (SearchParamCantScrollDown(sprite->sTaskId))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        else
        {
            if (SearchParamCantScrollUp(sprite->sTaskId))
                sprite->invisible = TRUE;
            else
                sprite->invisible = FALSE;
        }
        val = sprite->data[2] + sprite->sIsDownArrow * 128;
        sprite->y2 = gSineTable[val] / 128;
        sprite->data[2] += 8;
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

static void CreateSearchParameterScrollArrows(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 184, 4, 0);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sIsDownArrow = FALSE;
    gSprites[spriteId].callback = SpriteCB_SearchParameterScrollArrow;

    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 184, 108, 0);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sIsDownArrow = TRUE;
    gSprites[spriteId].vFlip = TRUE;
    gSprites[spriteId].callback = SpriteCB_SearchParameterScrollArrow;
}

#undef sTaskId
#undef sIsDownArrow

static void EraseAndPrintSearchTextBox(const u8 *str)
{
    ClearSearchMenuRect(8, 120, 224, 32);
    PrintSearchText(str, 8, 121);
}

static void EraseSelectorArrow(u32 y)
{
    ClearSearchMenuRect(144, y * 16 + 8, 8, 16);
}

static void PrintSelectorArrow(u32 y)
{
    PrintSearchText(gText_SelectorArrow, 144, y * 16 + 9);
}

static void PrintSearchParameterTitle(u32 y, const u8 *str)
{
    PrintSearchText(str, 152, y * 16 + 9);
}

static void ClearSearchParameterBoxText(void)
{
    ClearSearchMenuRect(144, 8, 96, 96);
}
