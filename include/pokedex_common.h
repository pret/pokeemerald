#ifndef GUARD_POKEDEX_COMMON_H
#define GUARD_POKEDEX_COMMON_H

// Common Pokédex Definitions and Functions
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
    SCREEN_COUNT,
    INFO_SCREEN = SCREEN_COUNT,
    STATS_SCREEN,
    EVO_SCREEN,
    FORMS_SCREEN,
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

enum
{
    WIN_INFO,
    WIN_FOOTPRINT,
    WIN_CRY_WAVE,
    WIN_VU_METER,
    WIN_NAVIGATION_BUTTONS,
};

// For scrolling search parameter
#define MAX_SEARCH_PARAM_ON_SCREEN      6
#define MAX_SEARCH_PARAM_CURSOR_POS     (MAX_SEARCH_PARAM_ON_SCREEN - 1)

#define LIST_SCROLL_STEP                16

#define POKEBALL_ROTATION_TOP           64
#define POKEBALL_ROTATION_BOTTOM        (POKEBALL_ROTATION_TOP - 16)

#define MAX_MONS_ON_SCREEN              4

// Coordinates of the Pokémon sprite on its page (info/cry screens)
#define MON_PAGE_X                      48
#define MON_PAGE_Y                      56

// Number of background templates in different screens.
#define NUM_POKEDEX_BG_TEMPLATES        4
#define NUM_INFO_SCREEN_BG_TEMPLATES    4
#define NUM_NEW_ENTRY_INFO_BG_TEMPLATES 2
#define NUM_SEARCH_MENU_BG_TEMPLATES    4

// Tile and pal tag used for all interface sprites.
#define TAG_DEX_INTERFACE               4096

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokemonStats
{
    enum Species species;
    enum Ability ability0;
    enum Ability ability1;
    enum Ability abilityHidden;
    enum GrowthRate growthRate;
    u16 expYield;
    u8 genderRatio;
    u8 baseHP;
    u8 baseSpeed;
    u8 baseAttack;
    u8 baseSpAttack;
    u8 baseDefense;
    u8 baseSpDefense;
    u8 differentEVs;
    u8 evYield_HP;
    u8 evYield_Speed;
    u8 evYield_Attack;
    u8 evYield_SpAttack;
    u8 evYield_Defense;
    u8 evYield_SpDefense;
    u8 catchRate;
    u8 eggGroup1;
    u8 eggGroup2;
    u8 eggCycles;
    u8 friendship;
};

struct EvoScreenData
{
    u32 arrowSpriteDist[10];
    enum Species targetSpecies[10];
    bool8 seen[10];
    bool8 fromEvoPage;
    bool8 isMega;
    u8 numAllEvolutions;
    u8 numSeen;
    u8 menuPos;
    u8 arrowSpriteId;
};

struct FromScreenData
{
    u16 formIds[30];
    bool8 inSubmenu;
    u8 numForms;
    u8 menuPos;
    u8 arrowSpriteId;
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

    // HGSS
    struct PokemonStats sPokemonStats;
    struct EvoScreenData sEvoScreenData;
    struct FromScreenData sFormScreenData;
    enum Species formSpecies;
    u16 originalSearchSelectionNum;
    u16 moveSelected;
    u16 movesTotal;
    u16 numTeachableMoves;
    bool8 justScrolled;
    u8 typeIconSpriteIds[2];
    u8 statBarsSpriteId;
    u8 statBarsBgSpriteId;
    u8 categoryIconSpriteId; //Physical/Special/Status category
    u8 numEggMoves;
    u8 numLevelUpMoves;
    u8 numPreEvolutions;
};

extern const u8 sCaughtBall_Gfx[];

extern const struct SpriteTemplate sScrollBarSpriteTemplate;
extern const struct SpriteTemplate sScrollArrowSpriteTemplate;
extern const struct SpriteTemplate sSeenOwnTextSpriteTemplate;
extern const struct SpriteTemplate sHoennNationalTextSpriteTemplate;
extern const struct SpriteTemplate sHoennDexSeenOwnNumberSpriteTemplate;
extern const struct SpriteTemplate sNationalDexSeenOwnNumberSpriteTemplate;
extern const struct SpriteTemplate sDexListStartMenuCursorSpriteTemplate;

extern const struct BgTemplate sSearchMenu_BgTemplate[NUM_SEARCH_MENU_BG_TEMPLATES];
extern const struct WindowTemplate sSearchMenu_WindowTemplate[2];
extern const u8 sScrollMonIncrements[];
extern const u8 sScrollTimers[];
extern const struct BgTemplate sPokedex_BgTemplate[NUM_POKEDEX_BG_TEMPLATES];
extern const struct WindowTemplate sPokemonList_WindowTemplate[2];
extern const struct BgTemplate sInfoScreen_BgTemplate[NUM_INFO_SCREEN_BG_TEMPLATES];
extern const struct BgTemplate sNewEntryInfoScreen_BgTemplate[NUM_NEW_ENTRY_INFO_BG_TEMPLATES];

void Task_HandlePokedexInput(u8);
void LoadPokedexBgPalette(bool8);
void CreatePokedexList(u8, u8);
void CreateMonDexNum(u16, u8, u8, u16);
void CreateCaughtBall(u16, u8, u8, u16);
u8 CreateMonName(u16, u8, u8);
void ClearMonListEntry(u8 x, u8 y, u16 unused);
void CreateMonSpritesAtPos(u16, u16);
void SpriteCB_MoveMonForInfoScreen(struct Sprite *sprite);
void Task_LoadInfoScreen(u8);
void Task_HandleInfoScreenInput(u8);
void Task_SwitchScreensFromInfoScreen(u8);
void Task_LoadInfoScreenWaitForFade(u8);
void Task_LoadAreaScreen(u8 taskId);
void Task_ReloadAreaScreen(u8 taskId);
void Task_WaitForAreaScreenInput(u8 taskId);
void Task_LoadCryScreen(u8);
void Task_HandleCryScreenInput(u8);
void Task_LoadSizeScreen(u8);
void Task_HandleSizeScreenInput(u8);
void Task_HandleCaughtMonPageInput(u8);
void ResetOtherVideoRegisters(u16);
u8 PrintCryScreenSpeciesName(u8, u16, u8, u8);
u16 GetPokemonScaleFromNationalDexNumber(u16 nationalNum);
u16 GetPokemonOffsetFromNationalDexNumber(u16 nationalNum);
u16 GetTrainerScaleFromNationalDexNumber(u16 nationalNum);
u16 GetTrainerOffsetFromNationalDexNumber(u16 nationalNum);
u16 CreateSizeScreenTrainerPic(u16, s16, s16, s8);
void Task_SwitchToSearchMenuTopBar(u8);
void HighlightSelectedSearchTopBarItem(u8);
void PrintSelectedSearchParameters(u8);
void SetDefaultSearchModeAndOrder(u8);
void CreateSearchParameterScrollArrows(u8);
u32 Pokedex_CreateCaughtMonSprite(enum Species species, s32 x, s32 y);

void VBlankCB_Pokedex(void);
void ResetPokedexView(struct PokedexView *pokedexView);
void PrintInfoScreenText(const u8 *str, u8 left, u8 top);
void FreeInfoScreenWindowAndBgBuffers(void);
enum Species NationalPokedexNumToSpeciesForm(enum NationalDexOrder nationalNum);
void LoadSpriteSilhouettePalette(u32 spriteId);

#endif // GUARD_POKEDEX_COMMON_H
