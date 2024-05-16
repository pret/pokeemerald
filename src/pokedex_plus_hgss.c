#include "global.h"
#include "battle_main.h"
#include "battle_util.h"
#include "bg.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokedex_plus_hgss.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "pokemon.h"
#include "reset_rtc_screen.h"
#include "scanline_effect.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/form_change_types.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
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
    INFO_SCREEN,
    STATS_SCREEN,
    EVO_SCREEN,
    FORMS_SCREEN,
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

extern const u16 gPokedexOrder_Alphabetical[];
extern const u16 gPokedexOrder_Height[];
extern const u16 gPokedexOrder_Weight[];

// static .rodata strings

static const u8 sText_No0000[] = _("0000");
static const u8 sCaughtBall_Gfx[] = INCBIN_U8("graphics/pokedex/caught_ball.4bpp");
static const u8 sText_TenDashes[] = _("----------");
ALIGNED(4) static const u8 sExpandedPlaceholder_PokedexDescription[] = _("");
static const u16 sSizeScreenSilhouette_Pal[] = INCBIN_U16("graphics/pokedex/size_silhouette.gbapal");

static const u8 sText_Stats_Buttons[] = _("{A_BUTTON}TOGGLE   {DPAD_UPDOWN}MOVES");
static const u8 sText_Stats_Buttons_Decapped[] = _("{A_BUTTON}Toggle   {DPAD_UPDOWN}Moves");
static const u8 sText_Stats_HP[] = _("HP");
static const u8 sText_Stats_Attack[] = _("ATK");
static const u8 sText_Stats_Defense[] = _("DEF");
static const u8 sText_Stats_Speed[] = _("SPE");
static const u8 sText_Stats_SpAttack[] = _("SP.A");
static const u8 sText_Stats_SpDefense[] = _("SP.D");
static const u8 sText_Stats_EV_Plus1[] = _("{UP_ARROW_2}");
static const u8 sText_Stats_EV_Plus2[] = _("{UP_ARROW_2}{UP_ARROW_2}");
static const u8 sText_Stats_EV_Plus3[] = _("{UP_ARROW_2}{UP_ARROW_2}{UP_ARROW_2}");
static const u8 sText_Stats_EvStr1Str2[] = _("{STR_VAR_1}{STR_VAR_2}");
static const u8 sText_Stats_MoveSelectedMax[] = _("{STR_VAR_1} / {STR_VAR_2}");
static const u8 sText_Stats_MoveLevel[] = _("LVL");
static const u8 sText_Stats_Gender_0[] = _("♂");
static const u8 sText_Stats_Gender_12_5[] = _("♀ 1/7 ♂"); //_("♀ 12.5 / 87.5 ♂");
static const u8 sText_Stats_Gender_25[] = _("♀ 1/3 ♂");     //_("♀ 25 / 75 ♂");
static const u8 sText_Stats_Gender_50[] = _("♀ 1/1 ♂");     //_("♀ 50 / 50 ♂");
static const u8 sText_Stats_Gender_75[] = _("♀ 3/1 ♂");     //_("♀ 75 / 25 ♂");
static const u8 sText_Stats_Gender_87_5[] = _("♀ 7/1 ♂");
static const u8 sText_Stats_Gender_100[] = _("♀");
static const u8 sText_Stats_CatchRate[] = _("CATCH{0x5B}: ");
static const u8 sText_Stats_CatchRate_Legend[] = _("LEGENDARY");
static const u8 sText_Stats_CatchRate_VeryHard[] = _("VERY HARD");
static const u8 sText_Stats_CatchRate_Difficult[] = _("DIFFICULT");
static const u8 sText_Stats_CatchRate_Medium[] = _("MEDIUM");
static const u8 sText_Stats_CatchRate_Relaxed[] = _("RELAXED");
static const u8 sText_Stats_CatchRate_Easy[] = _("EASY");
static const u8 sText_Stats_ExpYield[] = _("EXP YIELD: ");
static const u8 sText_Stats_EggCycles[] = _("HATCH STEPS:");
static const u8 sText_Stats_EggCycles_VeryFast[] = _("{EMOJI_BOLT}{EMOJI_DIZZYEGG}");
static const u8 sText_Stats_EggCycles_Fast[] = _("{EMOJI_DIZZYEGG}");
static const u8 sText_Stats_EggCycles_Normal[] = _("{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}");
static const u8 sText_Stats_EggCycles_Slow[] = _("{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}{EMOJI_DIZZYEGG}");
static const u8 sText_Stats_Growthrate[] = _("GROW: ");
static const u8 sText_Stats_Friendship[] = _("FRIENDSHIP:");
static const u8 sText_Stats_Friendship_BigAnger[] = _("{EMOJI_BIGANGER}");
static const u8 sText_Stats_Friendship_Neutral[] = _("{EMOJI_NEUTRAL}");
static const u8 sText_Stats_Friendship_Happy[] = _("{EMOJI_HAPPY}");
static const u8 sText_Stats_Friendship_BigSmile[] = _("{EMOJI_BIGSMILE}");
static const u8 sText_Stats_MEDIUM_FAST[] = _("MED. FAST");
static const u8 sText_Stats_ERRATIC[] = _("ERRATIC");
static const u8 sText_Stats_FLUCTUATING[] = _("FLUCTUATING");
static const u8 sText_Stats_MEDIUM_SLOW[] = _("MED. SLOW");
static const u8 sText_Stats_FAST[] = _("FAST");
static const u8 sText_Stats_SLOW[] = _("SLOW");
static const u8 sText_Stats_ContestHeart[] = _("H");
static const u8 sText_Stats_Minus[] = _("-");
static const u8 sText_Stats_eggGroup[] = _("EGG G1:");
static const u8 sText_Stats_eggGroup_Groups[] = _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_Stats_eggGroup_MONSTER[] = _("MONSTER");
static const u8 sText_Stats_eggGroup_WATER_1[] = _("WATER {CIRCLE_1}");
static const u8 sText_Stats_eggGroup_BUG[] = _("BUG");
static const u8 sText_Stats_eggGroup_FLYING[] = _("FLYING");
static const u8 sText_Stats_eggGroup_FIELD[] = _("FIELD");
static const u8 sText_Stats_eggGroup_FAIRY[] = _("FAIRY");
static const u8 sText_Stats_eggGroup_GRASS[] = _("GRASS");
static const u8 sText_Stats_eggGroup_HUMAN_LIKE[] = _("HUMANE");
static const u8 sText_Stats_eggGroup_WATER_3[] = _("WATER {CIRCLE_3}");
static const u8 sText_Stats_eggGroup_MINERAL[] = _("MINERAL");
static const u8 sText_Stats_eggGroup_AMORPHOUS[] = _("AMORPHOUS");
static const u8 sText_Stats_eggGroup_WATER_2[] = _("WATER {CIRCLE_2}");
static const u8 sText_Stats_eggGroup_DITTO[] = _("DITTO");
static const u8 sText_Stats_eggGroup_DRAGON[] = _("DRAGON");
static const u8 sText_Stats_eggGroup_NO_EGGS_DISCOVERED[] = _("---");
static const u8 sText_Dex_SEEN[] = _("SEEN");
static const u8 sText_Dex_OWN[] = _("OWN");

static const u8 sText_EVO_Buttons[] = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK");
static const u8 sText_EVO_Buttons_Decapped[] = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check");
static const u8 sText_EVO_Buttons_PE[] = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK  {START_BUTTON}FORMs");
static const u8 sText_EVO_Buttons_Decapped_PE[] = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check  {START_BUTTON}Forms");
static const u8 sText_EVO_Name[] = _("{STR_VAR_3}:");
static const u8 sText_EVO_PreEvo[] = _("{STR_VAR_1} evolves from {STR_VAR_2}");
static const u8 sText_EVO_PreEvo_PE_Mega[] = _("{STR_VAR_1} Mega Evolves with {STR_VAR_2}");
static const u8 sText_EVO_FRIENDSHIP[] = _("{LV}{UP_ARROW}, high friendship");
static const u8 sText_EVO_FRIENDSHIP_DAY[] = _("{LV}{UP_ARROW}, high friendship, day");
static const u8 sText_EVO_FRIENDSHIP_NIGHT[] = _("{LV}{UP_ARROW}, high friendship, night");
static const u8 sText_EVO_FRIENDSHIP_MOVE_TYPE[] = _("{LV}{UP_ARROW}, high friendship, {STR_VAR_2} move");
static const u8 sText_EVO_LEVEL[] = _("{LV}{UP_ARROW} to {STR_VAR_2}");
static const u8 sText_EVO_TRADE[] = _("Trading");
static const u8 sText_EVO_TRADE_ITEM[] = _("Trading, holding {STR_VAR_2}");
static const u8 sText_EVO_ITEM[] = _("{STR_VAR_2} is used");
static const u8 sText_EVO_LEVEL_ATK_GT_DEF[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Atk > Def");
static const u8 sText_EVO_LEVEL_ATK_EQ_DEF[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Atk = Def");
static const u8 sText_EVO_LEVEL_ATK_LT_DEF[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Atk < Def");
static const u8 sText_EVO_LEVEL_SILCOON[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Silcoon persona");
static const u8 sText_EVO_LEVEL_CASCOON[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Cascoon persona");
static const u8 sText_EVO_LEVEL_NINJASK[] = _("{LV}{UP_ARROW} to {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_SHEDINJA[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, party<6, 1x POKéBALL");
static const u8 sText_EVO_BEAUTY[] = _("{LV}{UP_ARROW}, high beauty");
static const u8 sText_EVO_LEVEL_FEMALE[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, is female");
static const u8 sText_EVO_LEVEL_MALE[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, is male");
static const u8 sText_EVO_LEVEL_NIGHT[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, night");
static const u8 sText_EVO_LEVEL_DAY[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, day");
static const u8 sText_EVO_LEVEL_DUSK[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, dusk (5-6PM)");
static const u8 sText_EVO_ITEM_HOLD_DAY[] = _("{LV}{UP_ARROW}, holds {STR_VAR_2}, day");
static const u8 sText_EVO_ITEM_HOLD_NIGHT[] = _("{LV}{UP_ARROW}, holds {STR_VAR_2}, night");
static const u8 sText_EVO_MOVE[] = _("{LV}{UP_ARROW}, knows {STR_VAR_2}");
static const u8 sText_EVO_MAPSEC[] = _("{LV}{UP_ARROW} on {STR_VAR_2}");
static const u8 sText_EVO_ITEM_MALE[] = _("{STR_VAR_2} used on male");
static const u8 sText_EVO_ITEM_FEMALE[] = _("{STR_VAR_2} used on female");
static const u8 sText_EVO_LEVEL_RAIN[] = _("{LV}{UP_ARROW} to {STR_VAR_2} while raining");
static const u8 sText_EVO_SPECIFIC_MON_IN_PARTY[] = _("{LV}{UP_ARROW} with {STR_VAR_2} in party");
static const u8 sText_EVO_LEVEL_DARK_TYPE_MON_IN_PARTY[] = _("{LV}{UP_ARROW} with dark type in party");
static const u8 sText_EVO_TRADE_SPECIFIC_MON[] = _("Traded for {STR_VAR_2}");
static const u8 sText_EVO_SPECIFIC_MAP[] = _("{LV}{UP_ARROW} on {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_NATURE_AMPED[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Amped natures");
static const u8 sText_EVO_LEVEL_NATURE_LOW_KEY[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Low Key natures");
static const u8 sText_EVO_CRITICAL_HITS[] = _("Land {STR_VAR_2} critical hits in\nsingle battle");
static const u8 sText_EVO_SCRIPT_TRIGGER_DMG[] = _("Takes at least {STR_VAR_2} HP in damage");
static const u8 sText_EVO_DARK_SCROLL[] = _("ScrllOfDrknss is used");
static const u8 sText_EVO_WATER_SCROLL[] = _("ScrollOfWatrs is used");
static const u8 sText_EVO_ITEM_NIGHT[] = _("{STR_VAR_2} is used, night");
static const u8 sText_EVO_ITEM_DAY[] = _("{STR_VAR_2} is used, day");
static const u8 sText_EVO_ITEM_HOLD[] = _("{LV}{UP_ARROW}, holds {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_MOVE_TWENTY_TIMES[] = _("{LV}{UP_ARROW} after 20x {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_RECOIL_DAMAGE_MALE[] = _("{LV}{UP_ARROW} with {STR_VAR_2} recoil, male");
static const u8 sText_EVO_LEVEL_RECOIL_DAMAGE_FEMALE[] = _("{LV}{UP_ARROW} with {STR_VAR_2} recoil, female");
static const u8 sText_EVO_LEVEL_ITEM_COUNT_999[] = _("{LV}{UP_ARROW} with 999 {STR_VAR_2} in bag");
static const u8 sText_EVO_UNKNOWN[] = _("Method unknown");
static const u8 sText_EVO_NONE[] = _("{STR_VAR_1} has no evolution.");

static const u8 sText_FORMS_Buttons_PE[] = _("{A_BUTTON}FORM MODE  {START_BUTTON}EVOs");
static const u8 sText_FORMS_Buttons_Decapped_PE[] = _("{START_BUTTON}Evos");
static const u8 sText_FORMS_Buttons_Submenu_PE[] = _("{DPAD_NONE}FORMs {A_BUTTON}CHECK {START_BUTTON}EVOs");
static const u8 sText_FORMS_Buttons_Submenu_Decapped_PE[] = _("{START_BUTTON}Evos");
static const u8 sText_FORMS_NONE[] = _("{STR_VAR_1} has no alternate forms.");
static const u8 sText_PlusSymbol[] = _("+");

// static .rodata graphics

static const u16 sPokedexPlusHGSS_Default_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_default.gbapal");
static const u16 sPokedexPlusHGSS_National_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_national.gbapal");
static const u16 sPokedexPlusHGSS_MenuSearch_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_search_menu.gbapal");
static const u16 sPokedexPlusHGSS_SearchResults_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_search_results.gbapal");
static const u16 sPokedexPlusHGSS_Default_dark_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_default_dark.gbapal");
static const u16 sPokedexPlusHGSS_National_dark_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_national_dark.gbapal");
static const u16 sPokedexPlusHGSS_MenuSearch_dark_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_search_menu_dark.gbapal");
static const u16 sPokedexPlusHGSS_SearchResults_dark_Pal[] = INCBIN_U16("graphics/pokedex/hgss/palette_search_results_dark.gbapal");
static const u32 sPokedexPlusHGSS_MenuList_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu_list.4bpp.lz");
static const u32 sPokedexPlusHGSS_MenuList_DECA_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu_list_DECA.4bpp.lz");
static const u32 sPokedexPlusHGSS_Interface_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_interface.4bpp.lz");
static const u32 sPokedexPlusHGSS_Interface_DECA_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_interface_DECA.4bpp.lz");
static const u32 sPokedexPlusHGSS_Menu_1_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu1.4bpp.lz");
static const u32 sPokedexPlusHGSS_Menu_2_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu2.4bpp.lz");
static const u32 sPokedexPlusHGSS_Menu_3_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu3.4bpp.lz");
static const u32 sPokedexPlusHGSS_MenuSearch_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu_search.4bpp.lz");
static const u32 sPokedexPlusHGSS_MenuSearch_DECA_Gfx[] = INCBIN_U32("graphics/pokedex/hgss/tileset_menu_search_DECA.4bpp.lz");
static const u32 sPokedexPlusHGSS_StartMenuMain_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_start_menu.bin.lz");
static const u32 sPokedexPlusHGSS_StartMenuSearchResults_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_start_menu_search_results.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/SelectBar.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap_Clear[] = INCBIN_U32("graphics/pokedex/hgss/SelectBar_clear.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenList_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_list_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenListUnderlay_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_list_screen_underlay.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenInfo_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_info_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenStats_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_stats_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenEvolution_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_evo_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenEvolution_Tilemap_PE[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_evo_screen_PE.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenForms_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_forms_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenCry_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_cry_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenSize_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_size_screen.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenSearchHoenn_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_search_screen_hoenn.bin.lz");
static const u32 sPokedexPlusHGSS_ScreenSearchNational_Tilemap[] = INCBIN_U32("graphics/pokedex/hgss/tilemap_search_screen_national.bin.lz");

#define SCROLLING_MON_X 146
#define HGSS_DECAPPED FALSE
#define HGSS_DARK_MODE FALSE
#define HGSS_HIDE_UNSEEN_EVOLUTION_NAMES FALSE

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
//Pokedex Plus HGSS_Ui
#define MOVES_COUNT_TOTAL (EGG_MOVES_ARRAY_COUNT + MAX_LEVEL_UP_MOVES + NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES)
EWRAM_DATA static u16 sStatsMoves[MOVES_COUNT_TOTAL] = {0};
EWRAM_DATA static u16 sStatsMovesTMHM_ID[NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES] = {0};


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


struct PokemonStats
{
    u16 species;
    u8  genderRatio;
    u8  baseHP;
    u8  baseSpeed;
    u8  baseAttack;
    u8  baseSpAttack;
    u8  baseDefense;
    u8  baseSpDefense;
    u8  differentEVs;
    u8  evYield_HP;
    u8  evYield_Speed;
    u8  evYield_Attack;
    u8  evYield_SpAttack;
    u8  evYield_Defense;
    u8  evYield_SpDefense;
    u8  catchRate;
    u8  growthRate;
    u8  eggGroup1;
    u8  eggGroup2;
    u8  eggCycles;
    u16 expYield;
    u8  friendship;
    u16 ability0;
    u16 ability1;
    u16 abilityHidden;
};

struct EvoScreenData
{
    bool8 fromEvoPage;
    u8 numAllEvolutions;
    u16 targetSpecies[10];
    u8 numSeen;
    bool8 seen[10];
    u8 menuPos;
    u8 arrowSpriteId;
    bool8 isMega;
};

struct FromScreenData
{
    u8 numForms;
    u16 formIds[30];
    bool8 inSubmenu;
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
    u8 typeIconSpriteIds[2];
    u16 moveSelected;
    u8 movesTotal;
    u8 statBarsSpriteId;
    u8 statBarsBgSpriteId;
    bool8 justScrolled;
    u8 categoryIconSpriteId; //Physical/Special/Status category
    u8 numEggMoves;
    u8 numLevelUpMoves;
    u8 numTMHMMoves;
    u8 numTutorMoves;
    u8 numPreEvolutions;
    struct PokemonStats sPokemonStats;
    struct EvoScreenData sEvoScreenData;
    struct FromScreenData sFormScreenData;
    u16 formSpecies;
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

static void ResetPokedexView(struct PokedexView *pokedexView);
static void VBlankCB_Pokedex(void);
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
static void HighlightScreenSelectBarItem(u8, u16);
static void Task_HandleCaughtMonPageInput(u8);
static void Task_ExitCaughtMonPage(u8);
static void SpriteCB_SlideCaughtMonToCenter(struct Sprite *sprite);
static void PrintMonInfo(u32 num, u32, u32 owned, u32 newEntry);
static void ResetOtherVideoRegisters(u16);
static u8 PrintCryScreenSpeciesName(u8, u16, u8, u8);
static void PrintDecimalNum(u8 windowId, u16 num, u8 left, u8 top);
static u16 CreateMonSpriteFromNationalDexNumberHGSS(u16 nationalNum, s16 x, s16 y, u16 paletteSlot);
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
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void CreateTypeIconSprites(void);
static void SetSearchRectHighlight(u8 flags, u8 x, u8 y, u8 width);
static void PrintInfoSubMenuText(u8 windowId, const u8 *str, u8 left, u8 top);

//Stats screen HGSS_Ui

static void LoadTilesetTilemapHGSS(u8 page);
static void Task_HandleStatsScreenInput(u8 taskId);
static void Task_LoadStatsScreen(u8 taskId);
static void Task_SwitchScreensFromStatsScreen(u8 taskId);
static void Task_ExitStatsScreen(u8 taskId);
static bool8 CalculateMoves(void);
static void PrintStatsScreen_NameGender(u8 taskId, u32 num, u32 value);
static void PrintStatsScreen_DestroyMoveItemIcon(u8 taskId);
static void PrintStatsScreen_Moves_Top(u8 taskId);
static void PrintStatsScreen_Moves_Description(u8 taskId);
static void PrintStatsScreen_Moves_BottomText(u8 taskId);
static void PrintStatsScreen_Moves_Bottom(u8 taskId);
static void PrintStatsScreen_Left(u8 taskId);
static void PrintStatsScreen_Abilities(u8 taskId);
static void PrintInfoScreenTextWhite(const u8* str, u8 left, u8 top);
static void PrintInfoScreenTextSmall(const u8* str, u8 left, u8 top);
static void PrintInfoScreenTextSmallWhite(const u8* str, u8 left, u8 top);
static void Task_LoadEvolutionScreen(u8 taskId);
static void Task_HandleEvolutionScreenInput(u8 taskId);
static void Task_SwitchScreensFromEvolutionScreen(u8 taskId);
static void Task_ExitEvolutionScreen(u8 taskId);
static u8 PrintEvolutionTargetSpeciesAndMethod(u8 taskId, u16 species, u8 depth, u8 depth_i);
static u8 PrintPreEvolutions(u8 taskId, u16 species);
//Stat bars on scrolling screens
static void TryDestroyStatBars(void);
static void TryDestroyStatBarsBg(void);
static void CreateStatBars(struct PokedexListItem *dexMon);
static void CreateStatBarsBg(void);
static void SpriteCB_StatBars(struct Sprite *sprite);
static void SpriteCB_StatBarsBg(struct Sprite *sprite);

//Forms screen
static void Task_LoadFormsScreen(u8 taskId);
static void Task_HandleFormsScreenInput(u8 taskId);
static void PrintForms(u8 taskId, u16 species);
static void Task_SwitchScreensFromFormsScreen(u8 taskId);
static void Task_ExitFormsScreen(u8 taskId);

//Physical/Special/Status category icon
static u8 ShowCategoryIcon(u32 category);
static void DestroyCategoryIcon(void);

static u16 NationalPokedexNumToSpeciesHGSS(u16 nationalNum);

#define TAG_CATEGORY_ICONS 30004

static const u16 sCategoryIcons_Pal[] = INCBIN_U16("graphics/interface/category_icons.gbapal");
static const u32 sCategoryIcons_Gfx[] = INCBIN_U32("graphics/interface/category_icons.4bpp.lz");

static const struct OamData sOamData_CategoryIcons =
{
    .size = SPRITE_SIZE(16x16),
    .shape = SPRITE_SHAPE(16x16),
    .priority = 0,
};
static const struct CompressedSpriteSheet sSpriteSheet_CategoryIcons =
{
    .data = sCategoryIcons_Gfx,
    .size = 16*16*3/2,
    .tag = TAG_CATEGORY_ICONS,
};
static const struct SpritePalette sSpritePal_CategoryIcons =
{
    .data = sCategoryIcons_Pal,
    .tag = TAG_CATEGORY_ICONS
};
static const union AnimCmd sSpriteAnim_CategoryIcon0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryIcon1[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryIcon2[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_CategoryIcons[] =
{
    sSpriteAnim_CategoryIcon0,
    sSpriteAnim_CategoryIcon1,
    sSpriteAnim_CategoryIcon2,
};
static const struct SpriteTemplate sSpriteTemplate_CategoryIcons =
{
    .tileTag = TAG_CATEGORY_ICONS,
    .paletteTag = TAG_CATEGORY_ICONS,
    .oam = &sOamData_CategoryIcons,
    .anims = sSpriteAnimTable_CategoryIcons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

//Stat bars by DizzyEgg
#define TAG_STAT_BAR 4097
#define TAG_STAT_BAR_BG 4098
static const struct OamData sOamData_StatBar =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
};
static const struct OamData sOamData_StatBarBg =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
};
static const struct SpriteTemplate sStatBarSpriteTemplate =
{
    .tileTag = TAG_STAT_BAR,
    .paletteTag = TAG_STAT_BAR,
    .oam = &sOamData_StatBar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_StatBars,
};
static const struct SpriteTemplate sStatBarBgSpriteTemplate =
{
    .tileTag = TAG_STAT_BAR_BG,
    .paletteTag = TAG_STAT_BAR_BG,
    .oam = &sOamData_StatBarBg,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_StatBarsBg,
};
enum
{
    COLOR_ID_ALPHA,
    COLOR_ID_BAR_WHITE,
    // These are repeated 6 times
    COLOR_ID_FILL,
    COLOR_ID_FILL_SHADOW,
    COLOR_ID_FONT = 14,
    COLOR_ID_FONT_SHADOW = 15,
};
enum
{
    COLOR_BEST, // Light blue
    COLOR_VERY_GOOD, // Green
    COLOR_GOOD, // Light Green
    COLOR_AVERAGE, // Yellow
    COLOR_BAD, // Orange
    COLOR_WORST, // Red
};
static const u8 sStatBarsGfx[] = INCBIN_U8("graphics/pokedex/hgss/stat_bars.4bpp");
static const u16 sStatBarPalette[16] = {
    [COLOR_ID_ALPHA] = RGB(0, 0, 10),
    [COLOR_ID_BAR_WHITE] = RGB_WHITE,

    [COLOR_ID_FILL + COLOR_BEST * 2] = RGB(2, 25, 25),
    [COLOR_ID_FILL_SHADOW + COLOR_BEST * 2] = RGB(13, 27, 27),

    [COLOR_ID_FILL + COLOR_VERY_GOOD * 2] = RGB(11, 25, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_VERY_GOOD * 2] = RGB(19, 27, 13),

    [COLOR_ID_FILL + COLOR_GOOD * 2] = RGB(22, 25, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_GOOD * 2] = RGB(26, 27, 13),

    [COLOR_ID_FILL + COLOR_AVERAGE * 2] = RGB(25, 22, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_AVERAGE * 2] = RGB(27, 26, 13),

    [COLOR_ID_FILL + COLOR_BAD * 2] = RGB(25, 17, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_BAD * 2] = RGB(27, 22, 13),

    [COLOR_ID_FILL + COLOR_WORST * 2] = RGB(25, 4, 2),
    [COLOR_ID_FILL_SHADOW + COLOR_WORST * 2] = RGB(27, 15, 13),

    [COLOR_ID_FONT] = RGB_BLACK,
    [COLOR_ID_FONT_SHADOW] = RGB(22, 22, 22),
};
static const struct SpritePalette sStatBarSpritePal[] = //{sStatBarPalette, TAG_STAT_BAR};
{
    {sStatBarPalette, TAG_STAT_BAR},
    {sStatBarPalette, TAG_STAT_BAR_BG},
    {0}
};

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
    {sPokedexPlusHGSS_Interface_Gfx, 0x2000, TAG_DEX_INTERFACE},
    {sPokedexPlusHGSS_Interface_DECA_Gfx, 0x2000, TAG_DEX_INTERFACE},
    {0}
};

static const struct SpritePalette sInterfaceSpritePalette[] =
{
    {sPokedexPlusHGSS_Default_Pal, TAG_DEX_INTERFACE},
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
#define WIN_NAVIGATION_BUTTONS 4

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
        .tilemapLeft = 15, //HGSSS_Ui
        .tilemapTop = 7, //HGSSS_Ui
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
    [WIN_NAVIGATION_BUTTONS] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 20,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 641,
    },

    DUMMY_WIN_TEMPLATE
};

#define WIN_STATS_TOPBAR 0
#define WIN_STATS_SIDEBAR 1
#define WIN_STATS_NAME_GENDER 2
#define WIN_STATS_LEFT 3
#define WIN_STATS_NAVIGATION_BUTTONS 4
#define WIN_STATS_MOVES_TOP 5
#define WIN_STATS_MOVES_DESCRIPTION 7
#define WIN_STATS_MOVES_BOTTOM 8
#define WIN_STATS_ABILITIES 9
#define WIN_STATS_LEFT_UNUSED 10
#define WIN_STATS_END WIN_STATS_LEFT_UNUSED
static const struct WindowTemplate sStatsScreen_WindowTemplates[] =
{
    [WIN_STATS_TOPBAR] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 1,
    },
    [WIN_STATS_SIDEBAR] =
    {
        .bg = 2,
        .tilemapLeft = 30,
        .tilemapTop = 0,
        .width = 2,
        .height = 20,
        .paletteNum = 0,
        .baseBlock = 1 + 60,
    },
    [WIN_STATS_NAME_GENDER] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 12,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40,
    },
    [WIN_STATS_LEFT] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 6,
        .width = 12,
        .height = 8,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48,
    },
    [WIN_STATS_NAVIGATION_BUTTONS] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1 + 60 + 40 + 48 + 96,
    },
    [WIN_STATS_MOVES_TOP] =
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 18,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48 + 96 + 24,
    },
    [WIN_STATS_MOVES_DESCRIPTION] =
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 6,
        .width = 18,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48 + 96 + 24 + 72,
    },
    [WIN_STATS_MOVES_BOTTOM] =
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 10,
        .width = 18,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48 + 96 + 24 + 72 + 72,
    },
    [WIN_STATS_ABILITIES] =
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 12,
        .width = 18,
        .height = 8,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48 + 96 + 24 + 72 + 72 + 36,
    },
    [WIN_STATS_LEFT_UNUSED] =
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 14,
        .width = 12,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 1 + 60 + 40 + 48 + 96 + 24 + 72 + 72 + 36 + 144,
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
        .tilemapLeft = 15, //HGSSS_Ui
        .tilemapTop = 7, //HGSSS_Ui
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 641,
    },
    DUMMY_WIN_TEMPLATE
};

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

static const struct SearchOptionText sDexSearchTypeOptions[NUMBER_OF_MON_TYPES] = // + 2 for "None" and terminator, - 2 for Mystery and Stellar
{
    {gText_DexEmptyString, gText_DexSearchTypeNone},
    {gText_DexEmptyString, gTypesInfo[TYPE_NORMAL].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_FIGHTING].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_FLYING].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_POISON].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_GROUND].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_ROCK].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_BUG].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_GHOST].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_STEEL].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_FIRE].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_WATER].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_GRASS].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_ELECTRIC].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_PSYCHIC].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_ICE].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_DRAGON].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_DARK].name},
    {gText_DexEmptyString, gTypesInfo[TYPE_FAIRY].name},
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


//************************************
//*                                  *
//*        MAIN                      *
//*                                  *
//************************************
void CB2_OpenPokedexPlusHGSS(void)
{
    if (!POKEDEX_PLUS_HGSS) return; // prevents the compiler from emitting static .rodata
                                    // if the feature is disabled
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

static void VBlankCB_Pokedex(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_Pokedex(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_OpenPokedexMainPage(u8 taskId)
{
    sPokedexView->isSearchResults = FALSE;
    sPokedexView->sEvoScreenData.fromEvoPage = FALSE;
    sPokedexView->formSpecies = 0;
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
        if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 8)
        {
            CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
            CreateStatBarsBg();
        }
    }
    else
    {
        if (JOY_NEW(A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            TryDestroyStatBars();
            UpdateSelectedMonSpriteId();
            BeginNormalPaletteFade(~(1 << (gSprites[sPokedexView->selectedMonSpriteId].oam.paletteNum + 16)), 0, 0, 0x10, RGB_BLACK);
            gSprites[sPokedexView->selectedMonSpriteId].callback = SpriteCB_MoveMonForInfoScreen;
            gTasks[taskId].func = Task_OpenInfoScreenAfterMonMovement;
            PlaySE(SE_PIN);
            FreeWindowAndBgBuffers();
        }
        else if (JOY_NEW(START_BUTTON))
        {
            TryDestroyStatBars();
            TryDestroyStatBarsBg();
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
            TryDestroyStatBars();
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
            else if (!sPokedexView->scrollTimer && !sPokedexView->scrollSpeed &&sPokedexView->justScrolled)
                CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
        }
    }
}

static void Task_WaitForScroll(u8 taskId)
{
    TryDestroyStatBars();
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

static void LoadPokedexBgPalette(bool8 isSearchResults)
{
    if (!HGSS_DARK_MODE)
    {
        if (isSearchResults == TRUE)
            LoadPalette(sPokedexPlusHGSS_SearchResults_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else if (!IsNationalPokedexEnabled())
            LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else
            LoadPalette(sPokedexPlusHGSS_National_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
    }
    else
    {
        if (isSearchResults == TRUE)
            LoadPalette(sPokedexPlusHGSS_SearchResults_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else if (!IsNationalPokedexEnabled())
            LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else
            LoadPalette(sPokedexPlusHGSS_National_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        LoadPalette(GetOverworldTextboxPalettePtr(), 0xF0, 32);
    }

}


//************************************
//*                                  *
//*    Main scrolling list screen    *
//*                                  *
//************************************

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
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_MenuList_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_MenuList_DECA_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(1, sPokedexPlusHGSS_ScreenList_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenListUnderlay_Tilemap, 0, 0);
        if (page == PAGE_MAIN)
            CopyToBgTilemapBuffer(0, sPokedexPlusHGSS_StartMenuMain_Tilemap, 0, 0x280);
        else
            CopyToBgTilemapBuffer(0, sPokedexPlusHGSS_StartMenuSearchResults_Tilemap, 0, 0x280);
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
        LoadCompressedSpriteSheet(&sInterfaceSpriteSheet[HGSS_DECAPPED]);
        LoadSpritePalettes(sInterfaceSpritePalette);
        LoadSpritePalettes(sStatBarSpritePal);
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
        sPokedexView->statBarsSpriteId = 0xFF;  //stat bars
        CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]); //stat bars
        sPokedexView->statBarsBgSpriteId = 0xFF;  //stat bars background
        CreateStatBarsBg(); //stat bars background
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

static void CreatePokedexList(u8 dexMode, u8 order)
{
    u16 vars[3]; //I have no idea why three regular variables are stored in an array, but whatever.
#define temp_dexCount   vars[0]
#define temp_isHoennDex vars[1]
#define temp_dexNum     vars[2]
    s16 i;

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
        for (i = 0; i < NUM_SPECIES - 1; i++)
        {
            temp_dexNum = gPokedexOrder_Alphabetical[i];

            if (NationalToHoennOrder(temp_dexNum) <= temp_dexCount && GetSetPokedexFlag(temp_dexNum, FLAG_GET_SEEN))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT);
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_HEAVIEST:
        for (i = NATIONAL_DEX_COUNT - 1; i >= 0; i--)
        {
            temp_dexNum = gPokedexOrder_Weight[i];

            if (NationalToHoennOrder(temp_dexNum) <= temp_dexCount && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_LIGHTEST:
        for (i = 0; i < NATIONAL_DEX_COUNT; i++)
        {
            temp_dexNum = gPokedexOrder_Weight[i];

            if (NationalToHoennOrder(temp_dexNum) <= temp_dexCount && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_TALLEST:
        for (i = NATIONAL_DEX_COUNT - 1; i >= 0; i--)
        {
            temp_dexNum = gPokedexOrder_Height[i];

            if (NationalToHoennOrder(temp_dexNum) <= temp_dexCount && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
            {
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].dexNum = temp_dexNum;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].seen = TRUE;
                sPokedexView->pokedexList[sPokedexView->pokemonListCount].owned = TRUE;
                sPokedexView->pokemonListCount++;
            }
        }
        break;
    case ORDER_SMALLEST:
        for (i = 0; i < NATIONAL_DEX_COUNT; i++)
        {
            temp_dexNum = gPokedexOrder_Height[i];

            if (NationalToHoennOrder(temp_dexNum) <= temp_dexCount && GetSetPokedexFlag(temp_dexNum, FLAG_GET_CAUGHT))
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
    AddTextPrinterParameterized4(windowId, fontId, left * 8 - 4, (top * 8) + 1, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static void PrintMonDexNumAndName_2(u8 windowId, u8 fontId, const u8* str, u8 left, u8 top) //offset for closer numer + text
{
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;
    AddTextPrinterParameterized4(windowId, fontId, left * 8 - 13, (top * 8) + 1, 0, 0, color, -1, str);
}

// u16 ignored is passed but never used
#define MON_LIST_X 2
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
                ClearMonListEntry(MON_LIST_X, i * 2, ignored);
            }
            else
            {
                ClearMonListEntry(MON_LIST_X, i * 2, ignored);
                if (sPokedexView->pokedexList[entryNum].seen)
                {
                    CreateMonDexNum(entryNum, MON_LIST_X+1, i * 2, ignored);
                    CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, MON_LIST_X, i * 2, ignored);
                    CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, MON_LIST_X + 5, i * 2);
                }
                else
                {
                    CreateMonDexNum(entryNum, MON_LIST_X+1, i * 2, ignored);
                    CreateCaughtBall(FALSE, MON_LIST_X, i * 2, ignored);
                    CreateMonName(0, MON_LIST_X + 5, i * 2);
                }
            }
            entryNum++;
        }
        break;
    case 1: // Up
        entryNum = b - 5;
        if (entryNum < 0 || entryNum >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[entryNum].dexNum == 0xFFFF)
        {
            ClearMonListEntry(MON_LIST_X, sPokedexView->listVOffset * 2, ignored);
        }
        else
        {
            ClearMonListEntry(MON_LIST_X, sPokedexView->listVOffset * 2, ignored);
            if (sPokedexView->pokedexList[entryNum].seen)
            {
                CreateMonDexNum(entryNum, MON_LIST_X+1, sPokedexView->listVOffset * 2, ignored);
                CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, MON_LIST_X, sPokedexView->listVOffset * 2, ignored);
                CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, MON_LIST_X + 5, sPokedexView->listVOffset * 2);
            }
            else
            {
                CreateMonDexNum(entryNum, MON_LIST_X+1, sPokedexView->listVOffset * 2, ignored);
                CreateCaughtBall(FALSE, MON_LIST_X, sPokedexView->listVOffset * 2, ignored);
                CreateMonName(0, MON_LIST_X + 5, sPokedexView->listVOffset * 2);
            }
        }
        break;
    case 2: // Down
        entryNum = b + 5;
        vOffset = sPokedexView->listVOffset + 10;
        if (vOffset >= LIST_SCROLL_STEP)
            vOffset -= LIST_SCROLL_STEP;
        if (entryNum < 0 || entryNum >= NATIONAL_DEX_COUNT || sPokedexView->pokedexList[entryNum].dexNum == 0xFFFF)
            ClearMonListEntry(MON_LIST_X, vOffset * 2, ignored);
        else
        {
            ClearMonListEntry(MON_LIST_X, vOffset * 2, ignored);
            if (sPokedexView->pokedexList[entryNum].seen)
            {
                CreateMonDexNum(entryNum, MON_LIST_X+1, vOffset * 2, ignored);
                CreateCaughtBall(sPokedexView->pokedexList[entryNum].owned, MON_LIST_X, vOffset * 2, ignored);
                CreateMonName(sPokedexView->pokedexList[entryNum].dexNum, MON_LIST_X + 5, vOffset * 2);
            }
            else
            {
                CreateMonDexNum(entryNum, MON_LIST_X+1, vOffset * 2, ignored);
                CreateCaughtBall(FALSE, MON_LIST_X, vOffset * 2, ignored);
                CreateMonName(0, MON_LIST_X + 5, vOffset * 2);
            }
        }
        break;
    }
    CopyWindowToVram(0, COPYWIN_GFX);
}

static void CreateMonDexNum(u16 entryNum, u8 left, u8 top, u16 unused)
{
    u8 text[5];
    u16 dexNum, offset = 0;

    dexNum = sPokedexView->pokedexList[entryNum].dexNum;
    if (sPokedexView->dexMode == DEX_MODE_HOENN)
        dexNum = NationalToHoennOrder(dexNum);
    memcpy(text, sText_No0000, ARRAY_COUNT(sText_No0000));
    if (NATIONAL_DEX_COUNT > 999 && sPokedexView->dexMode != DEX_MODE_HOENN)
    {
        text[0] = CHAR_0 + dexNum / 1000;
        offset++;
    }
    text[offset++] = CHAR_0 + (dexNum % 1000) / 100;
    text[offset++] = CHAR_0 + ((dexNum % 1000) % 100) / 10;
    text[offset++] = CHAR_0 + ((dexNum % 1000) % 100) % 10;
    text[offset++] = EOS;
    PrintMonDexNumAndName(0, FONT_NARROW, text, left, top);
}

static void CreateCaughtBall(bool16 owned, u8 x, u8 y, u16 unused)
{
    if (owned)
        BlitBitmapToWindow(0, sCaughtBall_Gfx, x * 6, y * 8, 8, 16);
    else
        FillWindowPixelRect(0, PIXEL_FILL(0), x * 6, y * 8, 8, 16);
}

static u8 CreateMonName(u16 num, u8 left, u8 top)
{
    const u8 *str;

    num = NationalPokedexNumToSpecies(num);
    if (num)
        str = GetSpeciesName(num);
    else
        str = sText_TenDashes;
    PrintMonDexNumAndName_2(0, FONT_NARROW, str, left, top);
    return StringLength(str);
}

static void ClearMonListEntry(u8 x, u8 y, u16 unused)
{
    FillWindowPixelRect(0, PIXEL_FILL(0), x * 6, y * 8, 0x60, 16);
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
        spriteId = CreatePokedexMonSprite(dexNum, SCROLLING_MON_X, 0x50);
        gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
        gSprites[spriteId].data[5] = -32;
    }

    // Create mid mon sprite
    dexNum = GetPokemonSpriteToDisplay(selectedMon);
    if (dexNum != 0xFFFF)
    {
        spriteId = CreatePokedexMonSprite(dexNum, SCROLLING_MON_X, 0x50);
        gSprites[spriteId].callback = SpriteCB_PokedexListMonSprite;
        gSprites[spriteId].data[5] = 0;
    }

    // Create bottom mon sprite
    dexNum = GetPokemonSpriteToDisplay(selectedMon + 1);
    if (dexNum != 0xFFFF)
    {
        spriteId = CreatePokedexMonSprite(dexNum, SCROLLING_MON_X, 0x50);
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
            spriteId = CreatePokedexMonSprite(dexNum, SCROLLING_MON_X, 0x50);
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
            spriteId = CreatePokedexMonSprite(dexNum, SCROLLING_MON_X, 0x50);
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
        sPokedexView->justScrolled = TRUE;
        PlaySE(SE_DEX_SCROLL);
    }
    else if (JOY_HELD(DPAD_DOWN) && (selectedMon < sPokedexView->pokemonListCount - 1))
    {
        scrollDir = 2;
        selectedMon = GetNextPosition(0, selectedMon, 0, sPokedexView->pokemonListCount - 1);
        CreateScrollingPokemonSprite(2, selectedMon);
        CreateMonListEntry(2, selectedMon, ignored);
        sPokedexView->justScrolled = TRUE;
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
        sPokedexView->justScrolled = TRUE;
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
        sPokedexView->justScrolled = TRUE;
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

    if (sPokedexView->sEvoScreenData.fromEvoPage)
        return FALSE;

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
            u8 spriteId = CreateMonSpriteFromNationalDexNumberHGSS(num, x, y, i);

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
#define LIST_RIGHT_SIDE_TEXT_X 204
#define LIST_RIGHT_SIDE_TEXT_X_OFFSET 13
#define LIST_RIGHT_SIDE_TEXT_Y_OFFSET 13
static void CreateInterfaceSprites(u8 page)
{
    u8 spriteId;
    u16 digitNum;
    bool32 drawNextDigit;

    // Scroll arrows
    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 10, 4, 0);
    gSprites[spriteId].sIsDownArrow = FALSE;
    spriteId = CreateSprite(&sScrollArrowSpriteTemplate, 10, 156, 0);
    gSprites[spriteId].sIsDownArrow = TRUE;
    gSprites[spriteId].vFlip = TRUE;

    CreateSprite(&sScrollBarSpriteTemplate, 6, 20, 0);

    if (!IsNationalPokedexEnabled() && page == PAGE_MAIN)
    {
        // Hoenn text
        CreateSprite(&sHoennNationalTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        // Hoenn seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // Hoenn own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // Hoenn seen value - 100s
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = sPokedexView->seenCount / 100;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->seenCount % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->seenCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);


        // Hoenn owned value - 100s
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = sPokedexView->ownCount / 100;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn owned value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 8, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->ownCount % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn owned value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->ownCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
    }
    else if (page == PAGE_MAIN)
    {
        u16 seenOwnedCount;
        u8 counterXDist  = 6;
        u8 counterX1s    = LIST_RIGHT_SIDE_TEXT_X + LIST_RIGHT_SIDE_TEXT_X_OFFSET + 16 - (sPokedexView->seenCount > 999 ? 0 : 1);
        u8 counterX10s   = counterX1s - counterXDist;
        u8 counterX100s  = counterX10s - counterXDist;
        u8 counterX1000s = counterX100s - counterXDist;

        // Hoenn text
        CreateSprite(&sHoennNationalTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 40 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        // Hoenn seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // Hoenn own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 7, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // National text
        spriteId = CreateSprite(&sHoennNationalTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 73 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET - 6, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);
        // National seen
        CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        // National own
        spriteId = CreateSprite(&sSeenOwnTextSpriteTemplate, LIST_RIGHT_SIDE_TEXT_X, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET + 6, 1);
        StartSpriteAnim(&gSprites[spriteId], 1);

        // Hoenn seen value - 100s
        seenOwnedCount = GetHoennPokedexCount(FLAG_GET_SEEN);
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX100s, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = seenOwnedCount / 100;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX10s, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (seenOwnedCount % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn seen value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1s, 45 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (seenOwnedCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);

        seenOwnedCount = GetHoennPokedexCount(FLAG_GET_CAUGHT);
        // Hoenn owned value - 100s
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX100s, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = seenOwnedCount / 100;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn owned value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX10s, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (seenOwnedCount % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // Hoenn owned value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1s, 55 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (seenOwnedCount % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);

        //****************************
        // National seen value - 1000s
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1000s, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = sPokedexView->seenCount / 1000;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // National seen value - 100s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX100s, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->seenCount % 1000) / 100;
        if (digitNum != 0 || drawNextDigit)
        {
            drawNextDigit = TRUE;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        }
        else
            gSprites[spriteId].invisible = TRUE;

        // National seen value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX10s, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = ((sPokedexView->seenCount % 1000) % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // National seen value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1s, 78 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = ((sPokedexView->seenCount % 1000) % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);

        // National owned value - 1000s
        drawNextDigit = FALSE;
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1000s, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = sPokedexView->ownCount / 1000;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
        if (digitNum != 0)
            drawNextDigit = TRUE;
        else
            gSprites[spriteId].invisible = TRUE;

        // National owned value - 100s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX100s, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = (sPokedexView->ownCount % 1000) / 100;
        if (digitNum != 0 || drawNextDigit)
        {
            drawNextDigit = TRUE;
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        }
        else
            gSprites[spriteId].invisible = TRUE;

        // National owned value - 10s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX10s, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = ((sPokedexView->ownCount % 1000) % 100) / 10;
        if (digitNum != 0 || drawNextDigit)
            StartSpriteAnim(&gSprites[spriteId], digitNum);
        else
            gSprites[spriteId].invisible = TRUE;

        // National owned value - 1s
        spriteId = CreateSprite(&sNationalDexSeenOwnNumberSpriteTemplate, counterX1s, 88 - LIST_RIGHT_SIDE_TEXT_Y_OFFSET, 1);
        digitNum = ((sPokedexView->ownCount % 1000) % 100) % 10;
        StartSpriteAnim(&gSprites[spriteId], digitNum);
    }

    if (page == PAGE_MAIN)
    {
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
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
        DestroySprite(sprite);
}

static void SpriteCB_MoveMonForInfoScreen(struct Sprite *sprite)
{
    sprite->oam.priority = 0;
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    sprite->x2 = 0;
    sprite->y2 = 0;
    if (sprite->x != MON_PAGE_X || sprite->y != MON_PAGE_Y)
    {
        if (sprite->x > 48)
            sprite->x -= 4;
        if (sprite->x < 48)
            sprite->x = 48;

        if (sprite->y > 56)
            sprite->y -= 4;
        if (sprite->y < 56)
            sprite->y = 56;
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



//************************************
//*                                  *
//*        STATS BARS                *
//*                                  *
//************************************

//Stat bars on main screen, code by DizzyEgg, idea by Jaizu
#define PIXEL_COORDS_TO_OFFSET(x, y)(			\
/*Add tiles by X*/								\
((y / 8) * 32 * 8)								\
/*Add tiles by X*/								\
+ ((x / 8) * 32)								\
/*Add pixels by Y*/								\
+ ((((y) - ((y / 8) * 8))) * 4)				    \
/*Add pixels by X*/								\
+ ((((x) - ((x / 8) * 8)) / 2)))

static inline void WritePixel(u8 *dst, u32 x, u32 y, u32 value)
{
    if (x & 1)
    {
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] &= ~0xF0;
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] |= (value << 4);
    }
    else
    {
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] &= ~0xF;
        dst[PIXEL_COORDS_TO_OFFSET(x, y)] |= (value);
    }
}
#define STAT_BAR_X_OFFSET 10
static void CreateStatBar(u8 *dst, u32 y, u32 width)
{
    u32 i, color;

    switch (width)
    {
    case 0 ... 5:
        color = COLOR_WORST;
        break;
    case 6 ... 15:
        color = COLOR_BAD;
        break;
    case 16 ... 25:
        color = COLOR_AVERAGE;
        break;
    case 26 ... 31:
        color = COLOR_GOOD;
        break;
    case 32 ... 37:
        color = COLOR_VERY_GOOD;
        break;
    default:
        color = COLOR_BEST;
        break;
    }

    // white pixes left side
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 0, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 1, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 2, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 3, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET, y + 4, COLOR_ID_BAR_WHITE);

    // white pixels right side
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 0, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 1, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 2, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 3, COLOR_ID_BAR_WHITE);
    WritePixel(dst, STAT_BAR_X_OFFSET + width - 1, y + 4, COLOR_ID_BAR_WHITE);

    // Fill
    for (i = 1; i < width - 1; i++)
    {
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 0, COLOR_ID_BAR_WHITE);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 1, COLOR_ID_FILL_SHADOW + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 2, COLOR_ID_FILL + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 3, COLOR_ID_FILL + color * 2);
        WritePixel(dst, STAT_BAR_X_OFFSET + i, y + 4, COLOR_ID_BAR_WHITE);
    }
}
static const u8 sBaseStatOffsets[] =
{
    offsetof(struct SpeciesInfo, baseHP),
    offsetof(struct SpeciesInfo, baseAttack),
    offsetof(struct SpeciesInfo, baseDefense),
    offsetof(struct SpeciesInfo, baseSpAttack),
    offsetof(struct SpeciesInfo, baseSpDefense),
    offsetof(struct SpeciesInfo, baseSpeed),
};
static void TryDestroyStatBars(void)
{
    if (sPokedexView->statBarsSpriteId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR);
        //FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsSpriteId]);
        sPokedexView->statBarsSpriteId = 0xFF;
    }
}
static void TryDestroyStatBarsBg(void)
{
    if (sPokedexView->statBarsBgSpriteId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR_BG);
        //FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsBgSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsBgSpriteId]);
        sPokedexView->statBarsBgSpriteId = 0xFF;
    }
}
static void CreateStatBars(struct PokedexListItem *dexMon)
{
    u8 offset_x = 184; //Moves the complete stat box left/right
    u8 offset_y = 16; //Moves the complete stat box up/down
    TryDestroyStatBars();

    sPokedexView->justScrolled = FALSE;

    if (dexMon->owned) // Show filed bars
    {
        u8 i;
        u32 width, statValue;
        u8 *gfx = Alloc(64 * 64);
        static const u8 sBarsYOffset[] = {3, 13, 23, 33, 43, 53};
        struct SpriteSheet sheet = {gfx, 64 * 64, TAG_STAT_BAR};
        u32 species = NationalPokedexNumToSpecies(dexMon->dexNum);

        memcpy(gfx, sStatBarsGfx, sizeof(sStatBarsGfx));
        for (i = 0; i < NUM_STATS; i++)
        {
            statValue = *((u8*)(&gSpeciesInfo[species]) + sBaseStatOffsets[i]);
            if (statValue <= 100)
            {
                width = statValue / 3;
                if (width >= 33)
                    width -= 1;
            }
            else
                width = (100 / 3) + ((statValue - 100) / 14);

            if (width > 39) // Max pixels
                width = 39;
            if (width < 3)
                width = 3;

            CreateStatBar(gfx, sBarsYOffset[i], width);
        }

        LoadSpriteSheet(&sheet);
        Free(gfx);
    }
    else if (dexMon->seen) // Just HP/ATK/DEF
    {
        static const struct SpriteSheet sheet = {sStatBarsGfx, 64 * 64, TAG_STAT_BAR};

        LoadSpriteSheet(&sheet);
    }
    else // neither seen nor owned
    {
        return;
    }
    sPokedexView->statBarsSpriteId = CreateSprite(&sStatBarSpriteTemplate, 36+offset_x, 107+offset_y, 10);
}
static void CreateStatBarsBg(void) //stat bars background text
{
    static const struct SpriteSheet sheetStatBarsBg = {sStatBarsGfx, 64 * 64, TAG_STAT_BAR_BG};
    u8 offset_x = 184; //Moves the complete stat box left/right
    u8 offset_y = 16; //Moves the complete stat box up/down

    TryDestroyStatBarsBg();

    LoadSpriteSheet(&sheetStatBarsBg);
    sPokedexView->statBarsBgSpriteId = CreateSprite(&sStatBarBgSpriteTemplate, 36+offset_x, 107+offset_y, 0);
}
// Hack to destroy sprites when a pokemon data is being loaded in
static bool32 IsMonInfoBeingLoaded(void)
{
    return (gSprites[sPokedexView->selectedMonSpriteId].callback == SpriteCB_MoveMonForInfoScreen);
}
static void SpriteCB_StatBars(struct Sprite *sprite)
{
    if (IsMonInfoBeingLoaded())
        sprite->invisible = TRUE;
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsSpriteId]);
        sPokedexView->statBarsSpriteId = 0xFF;
    }
}
static void SpriteCB_StatBarsBg(struct Sprite *sprite)
{
    if (IsMonInfoBeingLoaded())
        sprite->invisible = TRUE;
    if (sPokedexView->currentPage != PAGE_MAIN && sPokedexView->currentPage != PAGE_SEARCH_RESULTS)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR_BG);
        FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsBgSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsBgSpriteId]);
        sPokedexView->statBarsBgSpriteId = 0xFF;
    }
}



//************************************
//*                                  *
//*        Info screen               *
//*                                  *
//************************************
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
        LoadTilesetTilemapHGSS(INFO_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_FOOTPRINT);
        DrawFootprint(WIN_FOOTPRINT, NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum));
        CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        sPokedexView->typeIconSpriteIds[0] = 0xFF;
        sPokedexView->typeIconSpriteIds[1] = 0xFF;
        CreateTypeIconSprites();
        gMain.state++;
        break;
    case 4:
        PrintMonInfo(sPokedexListItem->dexNum, sPokedexView->dexMode == DEX_MODE_HOENN ? FALSE : TRUE, sPokedexListItem->owned, 0);
        if (!sPokedexListItem->owned)
            LoadPalette(gPlttBufferUnfaded + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(16 - 1));
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 5:
        if (!gTasks[taskId].tMonSpriteDone)
        {
            gTasks[taskId].tMonSpriteId = (u16)CreateMonSpriteFromNationalDexNumberHGSS(sPokedexListItem->dexNum, MON_PAGE_X, MON_PAGE_Y, 0);
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
        }
        break;
    case 9:
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

    if ((JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        sPokedexView->selectedScreen = AREA_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 1;
        gTasks[taskId].func = Task_SwitchScreensFromInfoScreen;
        PlaySE(SE_PIN);
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

#undef tMonSpriteId

//************************************
//*                                  *
//*        Area screen               *
//*                                  *
//************************************
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
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(13) | BGCNT_16COLOR | BGCNT_TXT256x256);
        gMain.state++;
        break;
    case 2:
        ShowPokedexAreaScreen(NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum), &sPokedexView->screenSwitchState);
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
            if (!sPokedexListItem->owned)
                PlaySE(SE_FAILURE);
            else
                gTasks[taskId].func = Task_LoadStatsScreen;
            break;
        }
    }
}



//************************************
//*                                  *
//*        Select bar                *
//*                                  *
//************************************
static void LoadScreenSelectBarMain(u16 unused)
{
    CopyToBgTilemapBuffer(1, sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap_Clear, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

static void UNUSED HighlightScreenSelectBarItem(u8 selectedScreen, u16 unused)
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

//************************************
//*                                  *
//*        CAUGHT MON                *
//*                                  *
//************************************
#define tState         data[0]
#define tSpecies       data[1]
#define tPalTimer      data[2]
#define tMonSpriteId   data[3]
#define tOtIdLo        data[12]
#define tOtIdHi        data[13]
#define tPersonalityLo data[14]
#define tPersonalityHi data[15]

void Task_DisplayCaughtMonDexPageHGSS(u8 taskId)
{
    u8 spriteId;
    u16 species;
    u16 dexNum;

    if (!POKEDEX_PLUS_HGSS) return; // prevents the compiler from emitting static .rodata
                                    // if the feature is disabled

    species = gTasks[taskId].tSpecies;
    dexNum = SpeciesToNationalPokedexNum(species);
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
        sPokedexView = AllocZeroed(sizeof(struct PokedexView)); //for type icons
        ResetPokedexView(sPokedexView);

        if (GetSpeciesFormTable(species) != NULL)
            sPokedexView->formSpecies = species;
        else
            sPokedexView->formSpecies = 0;

        LoadTilesetTilemapHGSS(INFO_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_FOOTPRINT);
        DrawFootprint(WIN_FOOTPRINT, species);
        CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);
        ResetPaletteFade();
        LoadPokedexBgPalette(FALSE);
        gTasks[taskId].tState++;
        break;
    case 2:
        sPokedexView->typeIconSpriteIds[0] = 0xFF;
        sPokedexView->typeIconSpriteIds[1] = 0xFF;
        CreateTypeIconSprites();
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
        spriteId = CreateMonSpriteFromNationalDexNumberHGSS(dexNum, MON_PAGE_X, MON_PAGE_Y, 0);
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
            PlayCry_Normal(species, 0);
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
        SetSpriteInvisibility(0, TRUE);
        SetSpriteInvisibility(1, TRUE);
        gSprites[gTasks[taskId].tMonSpriteId].callback = SpriteCB_SlideCaughtMonToCenter;
        gTasks[taskId].func = Task_ExitCaughtMonPage;
    }
    // Flicker caught screen color
    else if (++gTasks[taskId].tPalTimer & 16)
    {
        if (!HGSS_DARK_MODE)
            LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
        else
            LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
    }
    else
    {
        if (!HGSS_DARK_MODE)
            LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
        else
            LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
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

        species = gTasks[taskId].tSpecies;
        otId = ((u16)gTasks[taskId].tOtIdHi << 16) | (u16)gTasks[taskId].tOtIdLo;
        personality = ((u16)gTasks[taskId].tPersonalityHi << 16) | (u16)gTasks[taskId].tPersonalityLo;
        paletteNum = gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum;
        lzPaletteData = GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality);
        LoadCompressedPalette(lzPaletteData, OBJ_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);
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







//************************************
//*                                  *
//*        Print data                *
//*                                  *
//************************************
static void PrintInfoScreenText(const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(0, 1, left, top, 0, 0, color, -1, str);
}
static void PrintInfoScreenTextWhite(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(0, FONT_NORMAL, left, top, 0, 0, color, TEXT_SKIP_DRAW, str);
}
static void PrintInfoScreenTextSmall(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(0, 0, left, top, 0, 0, color, 0, str);
}
static void UNUSED PrintInfoScreenTextSmallWhite(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(0, 0, left, top, 0, 0, color, 0, str);
}
//Stats screen
static void PrintStatsScreenTextSmall(u8 windowId, const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(windowId, 0, left, top, 0, 0, color, 0, str);
}
static void PrintStatsScreenTextSmallWhite(u8 windowId, const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(windowId, 0, left, top, 0, 0, color, 0, str);
}

//Type Icon
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]].invisible = invisible;
}
static const u8 sContestCategoryToOamPaletteNum[CONTEST_CATEGORIES_COUNT] =
{
    [CONTEST_CATEGORY_COOL] = 13,
    [CONTEST_CATEGORY_BEAUTY] = 14,
    [CONTEST_CATEGORY_CUTE] = 14,
    [CONTEST_CATEGORY_SMART] = 15,
    [CONTEST_CATEGORY_TOUGH] = 13,
};
static void SetTypeIconPosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite;

    sprite = &gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    if (typeId < NUMBER_OF_MON_TYPES)
        sprite->oam.paletteNum = gTypesInfo[typeId].palette;
    else
        sprite->oam.paletteNum = sContestCategoryToOamPaletteNum[typeId - NUMBER_OF_MON_TYPES];
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}
static void PrintCurrentSpeciesTypeInfo(u8 newEntry, u16 species)
{
    u8 type1, type2;

    if (!newEntry)
    {
        species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
    }
    //type icon(s)
    #ifdef TX_RANDOMIZER_AND_CHALLENGES
        type1 = GetTypeBySpecies(species, 1);
        type2 = GetTypeBySpecies(species, 2);
    #else
        type1 = gSpeciesInfo[species].types[0];
        type2 = gSpeciesInfo[species].types[1];
    #endif
    if (species == SPECIES_NONE)
        type1 = type2 = TYPE_MYSTERY;

    if (type1 == type2)
    {
        SetTypeIconPosAndPal(type1, 147, 48, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(type1, 147, 48, 0);
        SetTypeIconPosAndPal(type2, 147 + 33, 48, 1);
    }

}
static void CreateTypeIconSprites(void)
{
    u8 i;

    LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
    LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
    for (i = 0; i < 2; i++)
    {
        if (sPokedexView->typeIconSpriteIds[i] == 0xFF)
            sPokedexView->typeIconSpriteIds[i] = CreateSprite(&gSpriteTemplate_MoveTypes, 10, 10, 2);

        SetSpriteInvisibility(i, TRUE);
    }
}

// u32 value is re-used, but passed as a bool that's TRUE if national dex is enabled
static void PrintMonInfo(u32 num, u32 value, u32 owned, u32 newEntry)
{
    u8 str[16];
    u8 str2[32];
    u16 species;
    const u8 *name;
    const u8 *category;
    const u8 *description;
    u8 digitCount = (NATIONAL_DEX_COUNT > 999 && value != 0) ? 4 : 3;

    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, digitCount);
    PrintInfoScreenTextWhite(str, 123, 17);
    species = NationalPokedexNumToSpeciesHGSS(num);
    if (species)
        name = GetSpeciesName(species);
    else
        name = sText_TenDashes;
    PrintInfoScreenTextWhite(name, 139 + (6 * digitCount), 17);
    if (owned)
    {
        CopyMonCategoryText(species, str2);
        category = str2;
    }
    else
    {
        category = gText_5MarksPokemon;
    }
    PrintInfoScreenText(category, 123, 31);
    PrintMonMeasurements(species,owned);
    if (owned)
        description = GetSpeciesPokedexDescription(species);
    else
        description = sExpandedPlaceholder_PokedexDescription;
    PrintInfoScreenText(description, GetStringCenterAlignXOffset(FONT_NORMAL, description, 0xF0), 93);

    //Type Icon(s)
    if (owned)
        PrintCurrentSpeciesTypeInfo(newEntry, species);
}

// Unused in the English version, used to print height/weight in versions which use metric system.
static void UNUSED PrintDecimalNum(u8 windowId, u16 num, u8 left, u8 top)
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

static void PrintInfoSubMenuText(u8 windowId, const u8 *str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(windowId, FONT_NORMAL, left, top, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static u8 PrintCryScreenSpeciesName(u8 windowId, u16 num, u8 left, u8 top)
{
    u8 str[POKEMON_NAME_LENGTH + 1];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(str); i++)
        str[i] = EOS;
    num = NationalPokedexNumToSpeciesHGSS(num);
    switch (num)
    {
    default:
        for (i = 0; GetSpeciesName(num)[i] != EOS && i < POKEMON_NAME_LENGTH; i++)
            str[i] = GetSpeciesName(num)[i];
        break;
    case 0:
        for (i = 0; i < 5; i++)
            str[i] = CHAR_HYPHEN;
        break;
    }
    PrintInfoSubMenuText(windowId, str, left, top);
    return i;
}

#define MALE_PERSONALITY 0xFE

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
        return MALE_PERSONALITY;
    }
}

static u16 CreateMonSpriteFromNationalDexNumberHGSS(u16 nationalNum, s16 x, s16 y, u16 paletteSlot)
{
    nationalNum = NationalPokedexNumToSpeciesHGSS(nationalNum);
    return CreateMonPicSprite(nationalNum, FALSE, GetPokedexMonPersonality(nationalNum), TRUE, x, y, paletteSlot, TAG_NONE);
}

static u16 GetPokemonScaleFromNationalDexNumber(u16 nationalNum)
{
    nationalNum = NationalPokedexNumToSpeciesHGSS(nationalNum);
    return gSpeciesInfo[nationalNum].pokemonScale;
}

static u16 GetPokemonOffsetFromNationalDexNumber(u16 nationalNum)
{
    nationalNum = NationalPokedexNumToSpeciesHGSS(nationalNum);
    return gSpeciesInfo[nationalNum].pokemonOffset;
}

static u16 GetTrainerScaleFromNationalDexNumber(u16 nationalNum)
{
    nationalNum = NationalPokedexNumToSpeciesHGSS(nationalNum);
    return gSpeciesInfo[nationalNum].trainerScale;
}

static u16 GetTrainerOffsetFromNationalDexNumber(u16 nationalNum)
{
    nationalNum = NationalPokedexNumToSpeciesHGSS(nationalNum);
    return gSpeciesInfo[nationalNum].trainerOffset;
}

static u16 CreateSizeScreenTrainerPic(u16 species, s16 x, s16 y, s8 paletteSlot)
{
    return CreateTrainerPicSprite(species, TRUE, x, y, paletteSlot, TAG_NONE);
}


//************************************
//*                                  *
//*        Helper functions          *
//*                                  *
//************************************

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



//************************************
//*                                  *
//*        HGSS                      *
//*                                  *
//************************************
static u16 NationalPokedexNumToSpeciesHGSS(u16 nationalNum)
{
    if (!nationalNum)
        return 0;

    if (sPokedexView->formSpecies != 0)
        return sPokedexView->formSpecies;
    else
        return NationalPokedexNumToSpecies(nationalNum);
}

static void LoadTilesetTilemapHGSS(u8 page)
{
    switch (page)
    {
    case INFO_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenInfo_Tilemap, 0, 0);
        break;
    case STATS_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenStats_Tilemap, 0, 0);
        break;
    case EVO_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
            CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenEvolution_Tilemap_PE, 0, 0);
        break;
    case FORMS_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenForms_Tilemap, 0, 0);
        break;
    case CRY_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenCry_Tilemap, 0, 0);
        break;
    case SIZE_SCREEN:
        if (!HGSS_DECAPPED)
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        else
            DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenSize_Tilemap, 0, 0);
        break;
    }
}

//Physical/Special/Status category
static u8 ShowCategoryIcon(u32 category)
{
    if (sPokedexView->categoryIconSpriteId == 0xFF)
        sPokedexView->categoryIconSpriteId = CreateSprite(&sSpriteTemplate_CategoryIcons, 139, 90, 0);

    gSprites[sPokedexView->categoryIconSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sPokedexView->categoryIconSpriteId], category);
    return sPokedexView->categoryIconSpriteId;
}

static void DestroyCategoryIcon(void)
{
    if (sPokedexView->categoryIconSpriteId != 0xFF)
        DestroySprite(&gSprites[sPokedexView->categoryIconSpriteId]);
    sPokedexView->categoryIconSpriteId = 0xFF;
}

//************************************
//*                                  *
//*        STATS                     *
//*                                  *
//************************************
static const u8 sStatsPageNavigationTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static void StatsPage_PrintNavigationButtons(void)
{
    u8 x = 9;
    u8 y = 0;
    if (!HGSS_DECAPPED)
        AddTextPrinterParameterized3(WIN_STATS_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_Stats_Buttons);
    else
        AddTextPrinterParameterized3(WIN_STATS_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_Stats_Buttons_Decapped);

    PutWindowTilemap(WIN_STATS_NAVIGATION_BUTTONS);
    CopyWindowToVram(WIN_STATS_NAVIGATION_BUTTONS, 3);
}

static void ResetStatsWindows(void)
{
    u8 i;

    FreeAllWindowBuffers();
    InitWindows(sStatsScreen_WindowTemplates);

    for (i = 0; i < WIN_STATS_END + 1; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static void SaveMonDataInStruct(void)
{
    u16 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
    u8 evs[NUM_STATS] =
    {
        [STAT_HP]    = gSpeciesInfo[species].evYield_HP,
        [STAT_ATK]   = gSpeciesInfo[species].evYield_Speed,
        [STAT_DEF]   = gSpeciesInfo[species].evYield_Attack,
        [STAT_SPEED] = gSpeciesInfo[species].evYield_SpAttack,
        [STAT_SPATK] = gSpeciesInfo[species].evYield_Defense,
        [STAT_SPDEF] = gSpeciesInfo[species].evYield_SpDefense
    };
    u8 differentEVs = 0;
    u8 i;

    //Count how many different EVs
    for (i = 0; i < NUM_STATS; i++)
    {
        if (evs[i] > 0) //HP//Speed//Attack//Special Attack//Defense//Special Defense
            differentEVs++;
    }

    sPokedexView->sPokemonStats.species             = species;
    sPokedexView->sPokemonStats.genderRatio         = gSpeciesInfo[species].genderRatio;
    sPokedexView->sPokemonStats.baseHP              = gSpeciesInfo[species].baseHP;
    sPokedexView->sPokemonStats.baseSpeed           = gSpeciesInfo[species].baseSpeed;
    sPokedexView->sPokemonStats.baseAttack          = gSpeciesInfo[species].baseAttack;
    sPokedexView->sPokemonStats.baseSpAttack        = gSpeciesInfo[species].baseSpAttack;
    sPokedexView->sPokemonStats.baseDefense         = gSpeciesInfo[species].baseDefense;
    sPokedexView->sPokemonStats.baseSpDefense       = gSpeciesInfo[species].baseSpDefense;
    sPokedexView->sPokemonStats.differentEVs        = differentEVs;
    sPokedexView->sPokemonStats.evYield_HP          = evs[STAT_HP];
    sPokedexView->sPokemonStats.evYield_Speed       = evs[STAT_ATK];
    sPokedexView->sPokemonStats.evYield_Attack      = evs[STAT_DEF];
    sPokedexView->sPokemonStats.evYield_SpAttack    = evs[STAT_SPEED];
    sPokedexView->sPokemonStats.evYield_Defense     = evs[STAT_SPATK];
    sPokedexView->sPokemonStats.evYield_SpDefense   = evs[STAT_SPDEF];
    sPokedexView->sPokemonStats.catchRate           = gSpeciesInfo[species].catchRate;
    sPokedexView->sPokemonStats.growthRate          = gSpeciesInfo[species].growthRate;
    sPokedexView->sPokemonStats.eggGroup1           = gSpeciesInfo[species].eggGroups[0];
    sPokedexView->sPokemonStats.eggGroup2           = gSpeciesInfo[species].eggGroups[1];
    sPokedexView->sPokemonStats.eggCycles           = gSpeciesInfo[species].eggCycles;
    sPokedexView->sPokemonStats.expYield            = gSpeciesInfo[species].expYield;
    sPokedexView->sPokemonStats.friendship          = gSpeciesInfo[species].friendship;
    sPokedexView->sPokemonStats.ability0            = GetAbilityBySpecies(species, 0);
    sPokedexView->sPokemonStats.ability1            = GetAbilityBySpecies(species, 1);
    sPokedexView->sPokemonStats.abilityHidden       = GetAbilityBySpecies(species, 2);
}

#define tMonSpriteId data[4]

static void Task_LoadStatsScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->currentPage = STATS_SCREEN;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].data[1] != 0)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].data[2] != 0)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        LoadTilesetTilemapHGSS(STATS_SCREEN);

        ResetStatsWindows();

        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        sPokedexView->typeIconSpriteIds[0] = 0xFF;
        sPokedexView->typeIconSpriteIds[1] = 0xFF;
        CreateTypeIconSprites();
        sPokedexView->categoryIconSpriteId = 0xFF;
        LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
        LoadCompressedSpriteSheet(&sSpriteSheet_CategoryIcons);
        LoadSpritePalette(&sSpritePal_CategoryIcons);
        gMain.state++;
        break;
    case 4:
        SaveMonDataInStruct();
        sPokedexView->moveSelected = 0;
        sPokedexView->movesTotal = 0;
        sPokedexView->numEggMoves = 0;
        sPokedexView->numLevelUpMoves = 0;
        sPokedexView->numTMHMMoves = 0;
        if (CalculateMoves())
            gMain.state++;
        break;
    case 5:
        if (gTasks[taskId].data[1] == 0)
        {
            //Icon
            u32 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            gTasks[taskId].data[6] = CreateMonIcon(species, SpriteCB_MonIcon, 18, 31, 4, personality); //Create pokemon sprite
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 6:
        gTasks[taskId].data[5] = 0;
        PrintStatsScreen_NameGender(taskId, sPokedexListItem->dexNum, sPokedexView->dexMode == DEX_MODE_HOENN ? FALSE : TRUE);
        PrintStatsScreen_Left(taskId);
        PrintStatsScreen_Abilities(taskId);
        PrintStatsScreen_Moves_Top(taskId);
        PrintStatsScreen_Moves_Description(taskId);
        PrintStatsScreen_Moves_BottomText(taskId);
        PrintStatsScreen_Moves_Bottom(taskId);
        if (!sPokedexListItem->owned)
            LoadPalette(gPlttBufferUnfaded + 1, 0x31, 0x1E);
        StatsPage_PrintNavigationButtons(); //sText_Stats_Buttons
        gMain.state++;
        break;
    case 7:
        {
        u32 preservedPalettes = 0;

        if (gTasks[taskId].data[2] != 0)
            preservedPalettes = 0x14; // each bit represents a palette index
        if (gTasks[taskId].data[1] != 0)
            preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
        BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gMain.state++;
        }
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
            gMain.state++;
        break;
    case 10:
        gMain.state++;
        break;
    case 11:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].func = Task_HandleStatsScreenInput;
        gMain.state = 0;
        break;
    }
}

static void UNUSED FreeStatsScreenWindowAndBgBuffers(void)
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

static void Task_HandleStatsScreenInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_DEX_PAGE);
        if (gTasks[taskId].data[5] == 0)
            gTasks[taskId].data[5] = 1;
        else
            gTasks[taskId].data[5] = 0;

        FillWindowPixelBuffer(WIN_STATS_LEFT, PIXEL_FILL(0));
        PrintStatsScreen_Left(taskId);

        FillWindowPixelBuffer(WIN_STATS_MOVES_DESCRIPTION, PIXEL_FILL(0));
        PrintStatsScreen_Moves_Description(taskId);

        FillWindowPixelBuffer(WIN_STATS_MOVES_BOTTOM, PIXEL_FILL(0));
        PrintStatsScreen_Moves_BottomText(taskId);
        PrintStatsScreen_Moves_Bottom(taskId);

        FillWindowPixelBuffer(WIN_STATS_ABILITIES, PIXEL_FILL(0));
        PrintStatsScreen_Abilities(taskId);
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitStatsScreen;
        PlaySE(SE_PC_OFF);
        return;
    }

    //Change moves
    if (JOY_REPEAT(DPAD_UP) && sPokedexView->moveSelected > 0)
    {
        sPokedexView->moveSelected -= 1;
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(WIN_STATS_MOVES_TOP, PIXEL_FILL(0));
        PrintStatsScreen_DestroyMoveItemIcon(taskId);
        PrintStatsScreen_Moves_Top(taskId);

        FillWindowPixelBuffer(WIN_STATS_MOVES_DESCRIPTION, PIXEL_FILL(0));
        PrintStatsScreen_Moves_Description(taskId);

        FillWindowPixelRect(WIN_STATS_MOVES_BOTTOM, PIXEL_FILL(0), 50, 0, 20, 16);
        FillWindowPixelRect(WIN_STATS_MOVES_BOTTOM, PIXEL_FILL(0), 120, 0, 20, 16);
        PrintStatsScreen_Moves_Bottom(taskId);
    }
    if (JOY_REPEAT(DPAD_DOWN) && sPokedexView->moveSelected < sPokedexView->movesTotal -1 )
    {
        sPokedexView->moveSelected = sPokedexView->moveSelected + 1;
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(WIN_STATS_MOVES_TOP, PIXEL_FILL(0));
        PrintStatsScreen_DestroyMoveItemIcon(taskId);
        PrintStatsScreen_Moves_Top(taskId);

        FillWindowPixelBuffer(WIN_STATS_MOVES_DESCRIPTION, PIXEL_FILL(0));
        PrintStatsScreen_Moves_Description(taskId);

        FillWindowPixelRect(WIN_STATS_MOVES_BOTTOM, PIXEL_FILL(0), 50, 0, 20, 16);
        FillWindowPixelRect(WIN_STATS_MOVES_BOTTOM, PIXEL_FILL(0), 120, 0, 20, 16);
        PrintStatsScreen_Moves_Bottom(taskId);
    }

    //Switch screens
    if ((JOY_NEW(DPAD_LEFT) || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        sPokedexView->selectedScreen = INFO_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 1;
        gTasks[taskId].func = Task_SwitchScreensFromStatsScreen;
        PlaySE(SE_PIN);
    }
    if ((JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        if (!sPokedexListItem->owned)
            PlaySE(SE_FAILURE);
        else
        {
            sPokedexView->selectedScreen = EVO_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            sPokedexView->screenSwitchState = 3;
            gTasks[taskId].func = Task_SwitchScreensFromStatsScreen;
            PlaySE(SE_PIN);
        }
    }
}

#define ITEM_TAG 0xFDF3

static void PrintStatsScreen_DestroyMoveItemIcon(u8 taskId)
{
    FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
    FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
    FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
    DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
}

static bool8 CalculateMoves(void)
{
    u16 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

    u16 statsMovesEgg[EGG_MOVES_ARRAY_COUNT] = {0};
    u16 statsMovesLevelUp[MAX_LEVEL_UP_MOVES] = {0};
    u16 move;

    u8 numEggMoves = 0;
    u8 numLevelUpMoves = 0;
    u8 numTMHMMoves = 0;
    u8 numTutorMoves = 0;
    u16 movesTotal = 0;
    u8 i,j;

    // Mega pokemon don't have distinct learnsets from their base form; so use base species for calculation
    if (species >= SPECIES_VENUSAUR_MEGA && species <= SPECIES_GROUDON_PRIMAL)
        species = GetFormSpeciesId(species, 0);

    //Calculate amount of Egg and LevelUp moves
    numEggMoves = GetEggMovesSpecies(species, statsMovesEgg);
    numLevelUpMoves = GetLevelUpMovesBySpecies(species, statsMovesLevelUp);

    //Egg moves
    for (i=0; i < numEggMoves; i++)
    {
        sStatsMoves[movesTotal] = statsMovesEgg[i];
        movesTotal++;
    }

    //Level up moves
    for (i=0; i < numLevelUpMoves; i++)
    {
        sStatsMoves[movesTotal] = statsMovesLevelUp[i];
        movesTotal++;
    }

    for (i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
    {
        move = teachableLearnset[i];
        for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
        {
            if (ItemIdToBattleMoveId(ITEM_TM01 + j) == move)
            {
                sStatsMovesTMHM_ID[numTMHMMoves] = (ITEM_TM01 + j);
                numTMHMMoves++;

                sStatsMoves[movesTotal] = move;
                movesTotal++;
                break;
            }
        }
    }

    for (i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
    {
        move = teachableLearnset[i];
        for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
        {
            if (ItemIdToBattleMoveId(ITEM_TM01 + j) == move)
                break;
        }

        if (j >= NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES)
        {
            numTutorMoves++;

            sStatsMoves[movesTotal] = move;
            movesTotal++;
        }
    }

    sPokedexView->numEggMoves = numEggMoves;
    sPokedexView->numLevelUpMoves = numLevelUpMoves;
    sPokedexView->numTMHMMoves = numTMHMMoves;
    sPokedexView->numTutorMoves = numTutorMoves;
    sPokedexView->movesTotal = movesTotal;

    return TRUE;
}

static void PrintStatsScreen_Moves_Top(u8 taskId)
{
    u8 numEggMoves      = sPokedexView->numEggMoves;
    u8 numLevelUpMoves  = sPokedexView->numLevelUpMoves;
    u8 numTMHMMoves     = sPokedexView->numTMHMMoves;
    u8 numTutorMoves    = sPokedexView->numTutorMoves;
    u8 movesTotal       = sPokedexView->movesTotal;
    u8 selected         = sPokedexView->moveSelected;
    u8 level;
    u8 moves_x = 5;
    u8 moves_y = 3;
    u16 move;
    u16 item;

    u16 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);

    //Move
    move = sStatsMoves[selected];

    //Moves selected from move max
    ConvertIntToDecimalStringN(gStringVar1, (selected+1), STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, movesTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar1, sText_Stats_MoveSelectedMax);
    PrintStatsScreenTextSmallWhite(WIN_STATS_MOVES_TOP, gStringVar1, moves_x-1, moves_y+1);

    //Move name
    StringCopy(gStringVar3, GetMoveName(move));
    StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 20);
    PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar3, moves_x, moves_y + 17);

    //Draw move type icon
    if (gTasks[taskId].data[5] == 0)
    {
        SetTypeIconPosAndPal(gMovesInfo[move].type, moves_x + 146, moves_y + 17, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(NUMBER_OF_MON_TYPES + gMovesInfo[move].contestCategory, moves_x + 146, moves_y + 17, 1);
        SetSpriteInvisibility(0, TRUE);
    }

    //Calculate and retrieve correct move from the arrays
    if (selected < numEggMoves)
    {
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gText_ThreeDashes, moves_x + 113, moves_y + 9);
        item = ITEM_LUCKY_EGG;
    }
    else if (selected < (numEggMoves + numLevelUpMoves))
    {
        level = GetSpeciesLevelUpLearnset(species)[(selected-numEggMoves)].level;
        ConvertIntToDecimalStringN(gStringVar1, level, STR_CONV_MODE_LEFT_ALIGN, 3); //Move learn lvl
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, sText_Stats_MoveLevel, moves_x + 113, moves_y + 3); //Level text
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar1, moves_x + 113, moves_y + 14); //Print level
        item = ITEM_RARE_CANDY;
    }
    else if (selected < (numEggMoves + numLevelUpMoves + numTMHMMoves))
    {
        CopyItemName(sStatsMovesTMHM_ID[(selected-numEggMoves-numLevelUpMoves)], gStringVar1); //TM name
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar1, moves_x + 113, moves_y + 9);
        item = sStatsMovesTMHM_ID[(selected-numEggMoves-numLevelUpMoves)];
    }
    else if (selected < (numEggMoves + numLevelUpMoves + numTMHMMoves + numTutorMoves))
    {
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gText_ThreeDashes, moves_x + 113, moves_y + 9);
        item = ITEM_TEACHY_TV;
    }
    else
    {
        StringCopy(gStringVar4, gText_CommunicationError);
        item = ITEM_MASTER_BALL;
    }

    //Egg/TM/Level/Tutor Item Icon
    gTasks[taskId].data[3] = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    gSprites[gTasks[taskId].data[3]].x2 = 203;
    gSprites[gTasks[taskId].data[3]].y2 = 39;
    gSprites[gTasks[taskId].data[3]].oam.priority = 0;

}

static void PrintStatsScreen_Moves_Description(u8 taskId)
{
    u8 selected = sPokedexView->moveSelected;
    u16 move;
    u8 moves_x = 5;
    u8 moves_y = 5;

    //Move
    move = sStatsMoves[selected];

    //Move description
    if (gTasks[taskId].data[5] == 0)
    {
        StringCopy(gStringVar4, gMovesInfo[move].description);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_DESCRIPTION, gStringVar4, moves_x, moves_y);
    }
    else
    {
        StringCopy(gStringVar4, gContestEffectDescriptionPointers[gMovesInfo[move].contestEffect]);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_DESCRIPTION, gStringVar4, moves_x, moves_y);
    }
}

static void PrintStatsScreen_Moves_BottomText(u8 taskId)
{
    u8 moves_x = 8;
    u8 moves_y = 3;
    if (gTasks[taskId].data[5] == 0)
    {
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gText_Power,  moves_x, moves_y);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gText_Accuracy2,  moves_x + 66, moves_y);
    }
    else
    {
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gText_Appeal,  moves_x, moves_y);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gText_Jam,  moves_x + 66, moves_y);
    }
}

static void PrintStatsScreen_Moves_Bottom(u8 taskId)
{
    u8 moves_x = 8;
    u8 moves_y = 3;
    u8 selected = sPokedexView->moveSelected;
    u16 move;
    //Contest
    u8 contest_effectValue;
    u8 contest_appeal = 0;
    u8 contest_jam = 0;

    //Move
    move = sStatsMoves[selected];

    //Power + Accuracy
    if (gTasks[taskId].data[5] == 0)
    {
        //Power
        if (gMovesInfo[move].power < 2)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar1, moves_x + 45, moves_y);
        //Physical/Special/Status Category
        DestroyCategoryIcon();
        ShowCategoryIcon(GetBattleMoveCategory(move));
        //Accuracy
        if (gMovesInfo[move].accuracy == 0)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar1,  moves_x + 114, moves_y);
    }
    else //Appeal + Jam
    {
        DestroyCategoryIcon();
        gSprites[sPokedexView->categoryIconSpriteId].invisible = TRUE;
        //Appeal
        contest_effectValue = gContestEffects[gMovesInfo[move].contestEffect].appeal;
        if (contest_effectValue != 0xFF)
            contest_appeal = contest_effectValue / 10;
        ConvertIntToDecimalStringN(gStringVar1, contest_appeal, STR_CONV_MODE_RIGHT_ALIGN, 1);
        StringCopy(gStringVar2, sText_PlusSymbol);
        StringAppend(gStringVar2, gStringVar1);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar2, moves_x + 45, moves_y);

        //Jam
        contest_effectValue = gContestEffects[gMovesInfo[move].contestEffect].jam;
        if (contest_effectValue != 0xFF)
            contest_jam = contest_effectValue / 10;
        ConvertIntToDecimalStringN(gStringVar1, contest_jam, STR_CONV_MODE_RIGHT_ALIGN, 1);
        StringCopy(gStringVar2, sText_Stats_Minus);
        StringAppend(gStringVar2, gStringVar1);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar2,  moves_x + 119, moves_y);
    }
}

static void PrintStatsScreen_NameGender(u8 taskId, u32 num, u32 value)
{
    u8 str[16];
    u16 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);

    u8 base_x = 38;
    u8 base_y = 0;
    u8 gender_x, gender_y;

    //Name
    PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, GetSpeciesName(species), base_x, base_y);

    //Number
    if (value == 0)
        value = NationalToHoennOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, 3);
    PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, str, base_x, base_y + 10);

    //Gender ratio //MON_GENDERLESS == 0xFF
    gender_x = base_x;
    gender_y = base_y + 20;
    switch (sPokedexView->sPokemonStats.genderRatio)
    {
    case 0:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_0, gender_x, gender_y);
        break;
    case 31:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_12_5, gender_x, gender_y);
        break;
    case 63:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_25, gender_x, gender_y);
        break;
    case 127:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_50, gender_x, gender_y);
        break;
    case 191:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_75, gender_x, gender_y);
        break;
    case 223:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_87_5, gender_x, gender_y);
        break;
    case 254:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, sText_Stats_Gender_100, gender_x, gender_y);
        break;
    default:
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, gText_ThreeDashes, gender_x, gender_y);
        break;
    }
}

static u8 PrintMonStatsToggle_DifferentEVsColumn(u8 differentEVs)
{
    if (differentEVs == 1 || differentEVs == 3)
        return 0;
    else
        return 1;
}

static u8 PrintMonStatsToggle_DifferentEVsRow(u8 differentEVs)
{
    if (differentEVs == 1 || differentEVs == 2)
        return 0;
    else
        return 1;
}

static u8* PrintMonStatsToggle_EV_Arrows(u8 *dest, u8 value)
{
    switch (value)
    {
        case 1:
            StringCopy(dest, sText_Stats_EV_Plus1);
            break;
        case 2:
            StringCopy(dest, sText_Stats_EV_Plus2);
            break;
        case 3:
            StringCopy(dest, sText_Stats_EV_Plus3);
            break;
    }
    return dest;
}

static void PrintStatsScreen_Left(u8 taskId)
{
    u8 base_x = 8;
    u8 x_offset_column = 43;
    u8 column = 0;
    u8 base_x_offset = 70;
    u8 base_x_first_row = 23;
    u8 base_x_second_row = 43;
    u8 base_y_offset = 11;
    u8 base_i = 0;
    u8 base_y = 5;
    u32 align_x;
    u8 total_x = 93;
    u8 strEV[25];
    u8 strBase[14];
    u8 EVs[6] = {sPokedexView->sPokemonStats.evYield_HP, sPokedexView->sPokemonStats.evYield_Speed, sPokedexView->sPokemonStats.evYield_Attack, sPokedexView->sPokemonStats.evYield_SpAttack, sPokedexView->sPokemonStats.evYield_Defense, sPokedexView->sPokemonStats.evYield_SpDefense};
    u8 differentEVs = 0;

    //Base stats
    if (gTasks[taskId].data[5] == 0)
    {
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_HP, base_x, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_first_row, base_y + base_y_offset*base_i);

        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_Speed, base_x+base_x_second_row, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseSpeed, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_offset, base_y + base_y_offset*base_i);

        base_i++;
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_Attack, base_x, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseAttack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_first_row, base_y + base_y_offset*base_i);

        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_SpAttack, base_x+base_x_second_row, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseSpAttack, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_offset, base_y + base_y_offset*base_i);

        base_i++;
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_Defense, base_x, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseDefense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_first_row, base_y + base_y_offset*base_i);

        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_SpDefense, base_x+base_x_second_row, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(strBase, sPokedexView->sPokemonStats.baseSpDefense, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strBase, base_x+base_x_offset, base_y + base_y_offset*base_i);
        base_i++;
    }
    else //EV increases
    {
        //If 1 or 2 EVs display with the same layout as the base stats
        if (sPokedexView->sPokemonStats.differentEVs < 3)
        {
            differentEVs = 0;
            //HP
            if (EVs[0] > 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_HP);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[0]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
            //Speed
            if (EVs[1]> 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_Speed);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[1]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
            //Attack
            if (EVs[2] > 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_Attack);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[2]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
            //Special Attack
            if (EVs[3] > 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_SpAttack);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[3]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
            //Defense
            if (EVs[4] > 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_Defense);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[4]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
            //Special Defense
            if (EVs[5] > 0)
            {
                differentEVs++;
                column = PrintMonStatsToggle_DifferentEVsColumn(differentEVs);
                base_i = PrintMonStatsToggle_DifferentEVsRow(differentEVs);
                StringCopy(gStringVar1, sText_Stats_SpDefense);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[5]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + x_offset_column*column, base_y + base_y_offset*base_i);
            }
        }
        else //3 different EVs in 1 row
        {
            column = 0;
            //HP
            if (EVs[0] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_HP);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[0]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
            //Speed
            if (EVs[1] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_Speed);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[1]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
            //Attack
            if (EVs[2] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_Attack);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[2]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
            //Special Attack
            if (EVs[3] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_SpAttack);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[3]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
            //Defense
            if (EVs[4] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_Defense);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[4]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
            //Special Defense
            if (EVs[5] > 0)
            {
                StringCopy(gStringVar1, sText_Stats_SpDefense);
                PrintMonStatsToggle_EV_Arrows(gStringVar2, EVs[5]);
                StringExpandPlaceholders(gStringVar3, sText_Stats_EvStr1Str2);
                PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x + 29*column, base_y + base_y_offset*base_i);
                column++;
            }
        }
        base_i++;
    }

    //TOGGLE--------------------------------------
    if (gTasks[taskId].data[5] == 0)
    {
        u32 catchRate = sPokedexView->sPokemonStats.catchRate;
        u32 growthRate = sPokedexView->sPokemonStats.growthRate;

        //Catch rate
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate, base_x, base_y + base_y_offset*base_i);
        if (catchRate <= 10)
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_Legend, base_x + x_offset_column, base_y + base_y_offset*base_i);
        else if (catchRate <= 70)
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_VeryHard, base_x + x_offset_column, base_y + base_y_offset*base_i);
        else if (catchRate <= 100)
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_Difficult, base_x + x_offset_column, base_y + base_y_offset*base_i);
        else if (catchRate <= 150)
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_Medium, base_x + x_offset_column, base_y + base_y_offset*base_i);
        else if (catchRate <= 200)
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_Relaxed, base_x + x_offset_column, base_y + base_y_offset*base_i);
        else
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_CatchRate_Easy, base_x + x_offset_column, base_y + base_y_offset*base_i);
        base_i++;

        //Growth rate
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_Growthrate, base_x, base_y + base_y_offset*base_i);
        switch (growthRate)
        {
        case GROWTH_MEDIUM_FAST:
            StringCopy(strEV, sText_Stats_MEDIUM_FAST);
            break;
        case GROWTH_ERRATIC:
            StringCopy(strEV, sText_Stats_ERRATIC);
            break;
        case GROWTH_FLUCTUATING:
            StringCopy(strEV, sText_Stats_FLUCTUATING);
            break;
        case GROWTH_MEDIUM_SLOW:
            StringCopy(strEV, sText_Stats_MEDIUM_SLOW);
            break;
        case GROWTH_FAST:
            StringCopy(strEV, sText_Stats_FAST);
            break;
        case GROWTH_SLOW:
            StringCopy(strEV, sText_Stats_SLOW);
            break;
        default:
            break;
        }
        align_x = GetStringRightAlignXOffset(0, strEV, total_x);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strEV, align_x, base_y + base_y_offset*base_i);
    }
    else
    {
        //Exp Yield
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_ExpYield, base_x, base_y + base_y_offset*base_i);
        ConvertIntToDecimalStringN(gStringVar1, sPokedexView->sPokemonStats.expYield, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar1, base_x + base_x_offset, base_y + base_y_offset*base_i);
        base_i++;

        //Friendship
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_Friendship, base_x, base_y + base_y_offset*base_i);
        switch (sPokedexView->sPokemonStats.friendship)
        {
        case 35:
            StringCopy(strEV, sText_Stats_Friendship_BigAnger);
            break;
        case 70:
            StringCopy(strEV, sText_Stats_Friendship_Neutral);
            break;
        case 90:
            StringCopy(strEV, sText_Stats_Friendship_Happy);
            break;
        case 100:
            StringCopy(strEV, sText_Stats_Friendship_Happy);
            break;
        case 140:
            StringCopy(strEV, sText_Stats_Friendship_BigSmile);
            break;
        default:
            ConvertIntToDecimalStringN(strEV, sPokedexView->sPokemonStats.friendship, STR_CONV_MODE_RIGHT_ALIGN, 3);
            break;
        }
        align_x = GetStringRightAlignXOffset(0, strEV, total_x);
        PrintStatsScreenTextSmall(WIN_STATS_LEFT, strEV, align_x, base_y + base_y_offset*base_i);
        base_i++;

        //Egg cycles
        if (sPokedexView->sPokemonStats.eggGroup1 == EGG_GROUP_NO_EGGS_DISCOVERED || sPokedexView->sPokemonStats.eggGroup2 == EGG_GROUP_NO_EGGS_DISCOVERED) //Species without eggs (legendaries etc)
        {
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_EggCycles, base_x, base_y + base_y_offset*base_i);
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, gText_ThreeDashes, 78, base_y + base_y_offset*base_i);
        }
        else
        {
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, sText_Stats_EggCycles, base_x, base_y + base_y_offset*base_i);
            if (sPokedexView->sPokemonStats.eggCycles <= 10)
            {
                StringCopy(strEV, sText_Stats_EggCycles_VeryFast);
                align_x = 76;
            }
            else if (sPokedexView->sPokemonStats.eggCycles <= 20)
            {
                StringCopy(strEV, sText_Stats_EggCycles_Fast);
                align_x = 85;
            }
            else if (sPokedexView->sPokemonStats.eggCycles <= 30)
            {
                StringCopy(strEV, sText_Stats_EggCycles_Normal);
                align_x = 76;
            }
            else
            {
                StringCopy(strEV, sText_Stats_EggCycles_Slow);
                align_x = 67;
            }
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, strEV, align_x, base_y + base_y_offset*base_i);
        }
        base_i++;

        //Egg group 1
        switch (sPokedexView->sPokemonStats.eggGroup1)
        {
        case EGG_GROUP_MONSTER     :
            StringCopy(gStringVar1, sText_Stats_eggGroup_MONSTER);
            break;
        case EGG_GROUP_WATER_1     :
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_1);
            break;
        case EGG_GROUP_BUG         :
            StringCopy(gStringVar1, sText_Stats_eggGroup_BUG);
            break;
        case EGG_GROUP_FLYING      :
            StringCopy(gStringVar1, sText_Stats_eggGroup_FLYING);
            break;
        case EGG_GROUP_FIELD       :
            StringCopy(gStringVar1, sText_Stats_eggGroup_FIELD);
            break;
        case EGG_GROUP_FAIRY       :
            StringCopy(gStringVar1, sText_Stats_eggGroup_FAIRY);
            break;
        case EGG_GROUP_GRASS       :
            StringCopy(gStringVar1, sText_Stats_eggGroup_GRASS);
            break;
        case EGG_GROUP_HUMAN_LIKE  :
            StringCopy(gStringVar1, sText_Stats_eggGroup_HUMAN_LIKE);
            break;
        case EGG_GROUP_WATER_3     :
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_3);
            break;
        case EGG_GROUP_MINERAL     :
            StringCopy(gStringVar1, sText_Stats_eggGroup_MINERAL);
            break;
        case EGG_GROUP_AMORPHOUS   :
            StringCopy(gStringVar1, sText_Stats_eggGroup_AMORPHOUS);
            break;
        case EGG_GROUP_WATER_2     :
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_2);
            break;
        case EGG_GROUP_DITTO       :
            StringCopy(gStringVar1, sText_Stats_eggGroup_DITTO);
            break;
        case EGG_GROUP_DRAGON      :
            StringCopy(gStringVar1, sText_Stats_eggGroup_DRAGON);
            break;
        case EGG_GROUP_NO_EGGS_DISCOVERED:
            StringCopy(gStringVar1, sText_Stats_eggGroup_NO_EGGS_DISCOVERED);
            break;
        }
        //Egg group 2
        if (sPokedexView->sPokemonStats.eggGroup1 != sPokedexView->sPokemonStats.eggGroup2)
        {
            switch (sPokedexView->sPokemonStats.eggGroup2)
            {
            case EGG_GROUP_MONSTER     :
                StringCopy(gStringVar2, sText_Stats_eggGroup_MONSTER);
                break;
            case EGG_GROUP_WATER_1     :
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_1);
                break;
            case EGG_GROUP_BUG         :
                StringCopy(gStringVar2, sText_Stats_eggGroup_BUG);
                break;
            case EGG_GROUP_FLYING      :
                StringCopy(gStringVar2, sText_Stats_eggGroup_FLYING);
                break;
            case EGG_GROUP_FIELD       :
                StringCopy(gStringVar2, sText_Stats_eggGroup_FIELD);
                break;
            case EGG_GROUP_FAIRY       :
                StringCopy(gStringVar2, sText_Stats_eggGroup_FAIRY);
                break;
            case EGG_GROUP_GRASS       :
                StringCopy(gStringVar2, sText_Stats_eggGroup_GRASS);
                break;
            case EGG_GROUP_HUMAN_LIKE  :
                StringCopy(gStringVar2, sText_Stats_eggGroup_HUMAN_LIKE);
                break;
            case EGG_GROUP_WATER_3     :
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_3);
                break;
            case EGG_GROUP_MINERAL     :
                StringCopy(gStringVar2, sText_Stats_eggGroup_MINERAL);
                break;
            case EGG_GROUP_AMORPHOUS   :
                StringCopy(gStringVar2, sText_Stats_eggGroup_AMORPHOUS);
                break;
            case EGG_GROUP_WATER_2     :
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_2);
                break;
            case EGG_GROUP_DITTO       :
                StringCopy(gStringVar2, sText_Stats_eggGroup_DITTO);
                break;
            case EGG_GROUP_DRAGON      :
                StringCopy(gStringVar2, sText_Stats_eggGroup_DRAGON);
                break;
            case EGG_GROUP_NO_EGGS_DISCOVERED:
                StringCopy(gStringVar2, sText_Stats_eggGroup_NO_EGGS_DISCOVERED);
                break;
            }
            StringExpandPlaceholders(gStringVar3, sText_Stats_eggGroup_Groups);
            align_x = GetStringRightAlignXOffset(0, gStringVar3, total_x);
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar3, base_x, base_y + base_y_offset*base_i);
        }
        else
        {
            align_x = GetStringRightAlignXOffset(0, gStringVar1, total_x);
            PrintStatsScreenTextSmall(WIN_STATS_LEFT, gStringVar1, base_x, base_y + base_y_offset*base_i);
        }
        base_i++;
    }
}

static void PrintStatsScreen_Abilities(u8 taskId)
{
    u8 abilities_x = 5;
    u8 abilities_y = 3;
    u16 ability0;
    u16 ability1;
    u16 abilityHidden;

    //Abilitie(s)

    if (gTasks[taskId].data[5] == 0)
    {
        ability0 = sPokedexView->sPokemonStats.ability0;
        PrintStatsScreenTextSmallWhite(WIN_STATS_ABILITIES, gAbilitiesInfo[ability0].name, abilities_x, abilities_y);
        PrintStatsScreenTextSmall(WIN_STATS_ABILITIES, gAbilitiesInfo[ability0].description, abilities_x, abilities_y + 14);

        ability1 = sPokedexView->sPokemonStats.ability1;
        if (ability1 != ABILITY_NONE && ability1 != ability0)
        {
            PrintStatsScreenTextSmallWhite(WIN_STATS_ABILITIES, gAbilitiesInfo[ability1].name, abilities_x, abilities_y + 30);
            PrintStatsScreenTextSmall(WIN_STATS_ABILITIES, gAbilitiesInfo[ability1].description, abilities_x, abilities_y + 44);
        }
    }
    else //Hidden abilities
    {
        abilityHidden = sPokedexView->sPokemonStats.abilityHidden;
        PrintStatsScreenTextSmallWhite(WIN_STATS_ABILITIES, gAbilitiesInfo[abilityHidden].name, abilities_x, abilities_y);
        PrintStatsScreenTextSmall(WIN_STATS_ABILITIES, gAbilitiesInfo[abilityHidden].description, abilities_x, abilities_y + 14);
    }
}

static void Task_SwitchScreensFromStatsScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
        FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
        FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
        DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite

        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        switch (sPokedexView->screenSwitchState)
        {
        case 1:
            FreeAllWindowBuffers();
            InitWindows(sInfoScreen_WindowTemplates);
            gTasks[taskId].func = Task_LoadAreaScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadCryScreen;
            break;
        case 3:
            FreeAllWindowBuffers();
            InitWindows(sInfoScreen_WindowTemplates);
            gTasks[taskId].func = Task_LoadEvolutionScreen;
            break;
        default:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        }
    }
}

static void Task_ExitStatsScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeSpriteTilesByTag(ITEM_TAG);                         //Destroy item icon
        FreeSpritePaletteByTag(ITEM_TAG);                       //Destroy item icon
        FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]); //Destroy item icon
        DestroySprite(&gSprites[gTasks[taskId].data[3]]);       //Destroy item icon
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite

        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        FreeInfoScreenWindowAndBgBuffers();
        DestroyTask(taskId);
    }
}


//************************************
//*                                  *
//*        EVOS                      *
//*                                  *
//************************************
static const u8 sEvoFormsPageNavigationTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static void EvoFormsPage_PrintNavigationButtons(void)
{
    u8 x = 6;
    u8 y = 0;

    FillWindowPixelBuffer(WIN_NAVIGATION_BUTTONS, PIXEL_FILL(0));

        if (sPokedexView->selectedScreen == EVO_SCREEN)
        {
            if (!HGSS_DECAPPED)
                AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x+9, y, sStatsPageNavigationTextColor, 0, sText_EVO_Buttons_PE);
            else
                AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x+9, y, sStatsPageNavigationTextColor, 0, sText_EVO_Buttons_Decapped_PE);
        }
        else if (sPokedexView->selectedScreen == FORMS_SCREEN)
        {
            if (sPokedexView->sFormScreenData.inSubmenu)
            {
                if (!HGSS_DECAPPED)
                    AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_FORMS_Buttons_Submenu_PE);
                else
                    AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_FORMS_Buttons_Submenu_Decapped_PE);
            }
            else
            {
                if (!HGSS_DECAPPED)
                    AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_FORMS_Buttons_PE);
                else
                    AddTextPrinterParameterized3(WIN_NAVIGATION_BUTTONS, 0, x, y, sStatsPageNavigationTextColor, 0, sText_FORMS_Buttons_Decapped_PE);
            }
        }

    PutWindowTilemap(WIN_NAVIGATION_BUTTONS);
    CopyWindowToVram(WIN_NAVIGATION_BUTTONS, COPYWIN_FULL);
}

static void ResetEvoScreenDataStruct(void)
{
    u8 i;
    sPokedexView->sEvoScreenData.numAllEvolutions = 0;
    sPokedexView->sEvoScreenData.numSeen = 0;
    sPokedexView->sEvoScreenData.menuPos = 0;
    for (i = 0; i < 10; i++)
    {
        sPokedexView->sEvoScreenData.targetSpecies[i] = 0;
        sPokedexView->sEvoScreenData.seen[i] = 0;
    }

}

static void GetSeenFlagTargetSpecies(void)
{
    u8 i;
    u16 species;
    for (i = 0; i < sPokedexView->sEvoScreenData.numAllEvolutions; i++)
    {
        species = sPokedexView->sEvoScreenData.targetSpecies[i];
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
        {
            sPokedexView->sEvoScreenData.seen[i] = TRUE;
            sPokedexView->sEvoScreenData.numSeen += 1;
        }

    }
}

static void Task_LoadEvolutionScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->currentPage = EVO_SCREEN;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].data[1] != 0)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].data[2] != 0)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        LoadTilesetTilemapHGSS(EVO_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        FillWindowPixelBuffer(WIN_NAVIGATION_BUTTONS, PIXEL_FILL(0));
        PutWindowTilemap(WIN_NAVIGATION_BUTTONS);
        CopyWindowToVram(WIN_NAVIGATION_BUTTONS, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        if (gTasks[taskId].data[1] == 0)
        {
            u32 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            sPokedexView->selectedScreen = EVO_SCREEN;
            ResetEvoScreenDataStruct();
            //Icon
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            PrintPreEvolutions(taskId, species);
            gTasks[taskId].data[4] = CreateMonIcon(species, SpriteCB_MonIcon, 18 + 32*sPokedexView->numPreEvolutions, 31, 4, personality); //Create pokemon sprite
            EvoFormsPage_PrintNavigationButtons(); // Navigation buttons
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 4:
        //Print evo info and icons
        gTasks[taskId].data[3] = 0;
        PrintEvolutionTargetSpeciesAndMethod(taskId, NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum), 0, sPokedexView->numPreEvolutions);
        LoadSpritePalette(&gSpritePalette_Arrow);
        GetSeenFlagTargetSpecies();
        if (sPokedexView->sEvoScreenData.numAllEvolutions != 0 && sPokedexView->sEvoScreenData.numSeen != 0)
        {
            sPokedexView->sEvoScreenData.arrowSpriteId = CreateSprite(&gSpriteTemplate_Arrow, 7, 58, 0);
            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].animNum = 2;
        }
        gMain.state++;
        break;
    case 5:
        {
        u32 preservedPalettes = 0;

        if (gTasks[taskId].data[2] != 0)
            preservedPalettes = 0x14; // each bit represents a palette index
        if (gTasks[taskId].data[1] != 0)
            preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
        BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gMain.state++;
        }
        break;
    case 6:
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
    case 7:
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    case 8:
        gMain.state++;
        break;
    case 9:
        sPokedexView->screenSwitchState = 0;
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].func = Task_HandleEvolutionScreenInput;
        gMain.state = 0;
        break;
    }
}

static void Task_HandleEvolutionScreenInput(u8 taskId)
{
    //Switch to forms screen, Pokemon Expansion only (rhh)
    if (JOY_NEW(START_BUTTON))
    {
        sPokedexView->selectedScreen = FORMS_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 3;
        gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
        PlaySE(SE_PIN);
    }

    if (sPokedexView->sEvoScreenData.numAllEvolutions != 0 && sPokedexView->sEvoScreenData.numSeen != 0)
    {
        u8 base_y = 58;
        u8 base_y_offset = 9;
        u8 pos = sPokedexView->sEvoScreenData.menuPos;
        u8 max = sPokedexView->sEvoScreenData.numAllEvolutions;
        if (JOY_NEW(DPAD_DOWN))
        {
            while (TRUE)
            {
                pos += 1;
                if (pos >= max)
                    pos = 0;

                if (sPokedexView->sEvoScreenData.seen[pos] == TRUE)
                    break;
            }
            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].y = base_y + base_y_offset * pos;
            sPokedexView->sEvoScreenData.menuPos = pos;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (sPokedexView->sEvoScreenData.menuPos == 0)
                sPokedexView->sEvoScreenData.menuPos = sPokedexView->sEvoScreenData.numAllEvolutions - 1;
            else
                sPokedexView->sEvoScreenData.menuPos -= 1;

            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].y = base_y + base_y_offset * sPokedexView->sEvoScreenData.menuPos;
        }

        if (JOY_NEW(A_BUTTON))
        {
            u16 targetSpecies   = sPokedexView->sEvoScreenData.targetSpecies[sPokedexView->sEvoScreenData.menuPos];
            u16 dexNum          = SpeciesToNationalPokedexNum(targetSpecies);
            sPokedexListItem->dexNum = dexNum;
            sPokedexListItem->seen   = GetSetPokedexFlag(dexNum, FLAG_GET_SEEN);
            sPokedexListItem->owned  = GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT);

                if (GetSpeciesFormTable(targetSpecies) != NULL)
                    sPokedexView->formSpecies = targetSpecies;
                else
                    sPokedexView->formSpecies = 0;

            sPokedexView->sEvoScreenData.fromEvoPage = TRUE;
            PlaySE(SE_PIN);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_LoadInfoScreenWaitForFade;
        }
    }

    //Exit to overview
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitEvolutionScreen;
        PlaySE(SE_PC_OFF);
        return;
    }

    //Switch screens
    if ((JOY_NEW(DPAD_LEFT) || (JOY_NEW(L_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        sPokedexView->selectedScreen = STATS_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 1;
        gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
        PlaySE(SE_PIN);
    }
    if ((JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)))
    {
        if (!sPokedexListItem->owned)
            PlaySE(SE_FAILURE);
        else
        {
            sPokedexView->selectedScreen = CRY_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            sPokedexView->screenSwitchState = 2;
            gTasks[taskId].func = Task_SwitchScreensFromEvolutionScreen;
            PlaySE(SE_PIN);
        }
    }
}

static void HandleTargetSpeciesPrint(u8 taskId, u16 targetSpecies, u16 previousTargetSpecies, u8 base_x, u8 base_y, u8 base_y_offset, u8 base_i, bool8 isEevee)
{
    u8 iterations = 6;
    bool8 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_SEEN);

    if (seen || !HGSS_HIDE_UNSEEN_EVOLUTION_NAMES)
        StringCopy(gStringVar3, GetSpeciesName(targetSpecies)); //evolution mon name
    else
        StringCopy(gStringVar3, gText_ThreeQuestionMarks); //show questionmarks instead of name
    StringExpandPlaceholders(gStringVar3, sText_EVO_Name); //evolution mon name
    PrintInfoScreenTextSmall(gStringVar3, base_x, base_y + base_y_offset*base_i); //evolution mon name

    //Print mon icon in the top row
    if (isEevee)
    {
        iterations = 9;
        if (targetSpecies == previousTargetSpecies)
            return;
            else if (targetSpecies == SPECIES_GLACEON)
                base_i -= 1;
            else if (targetSpecies == SPECIES_SYLVEON)
                base_i -= 2;
    }

    if (base_i < iterations)
    {
        u32 personality = GetPokedexMonPersonality(targetSpecies);
        LoadMonIconPalettePersonality(targetSpecies, personality); //Loads pallete for current mon
            if (isEevee)
                gTasks[taskId].data[4+base_i] = CreateMonIcon(targetSpecies, SpriteCB_MonIcon, 45 + 26*base_i, 31, 4, personality); //Create pokemon sprite
            else
                gTasks[taskId].data[4+base_i] = CreateMonIcon(targetSpecies, SpriteCB_MonIcon, 50 + 32*base_i, 31, 4, personality); //Create pokemon sprite
        gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
    }
}

static void CreateCaughtBallEvolutionScreen(u16 targetSpecies, u8 x, u8 y, u16 unused)
{
    bool8 owned = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_CAUGHT);
    if (owned)
        BlitBitmapToWindow(0, sCaughtBall_Gfx, x, y-1, 8, 16);
    else
    {
        //FillWindowPixelRect(0, PIXEL_FILL(0), x, y, 8, 16); //not sure why this was even here
        PrintInfoScreenTextSmall(gText_OneDash, x+1, y-1);
    }
}

static void HandlePreEvolutionSpeciesPrint(u8 taskId, u16 preSpecies, u16 species, u8 base_x, u8 base_y, u8 base_y_offset, u8 base_i)
{
    bool8 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(preSpecies), FLAG_GET_SEEN);

    StringCopy(gStringVar1, GetSpeciesName(species)); //evolution mon name

    if (sPokedexView->sEvoScreenData.isMega)
        StringExpandPlaceholders(gStringVar3, sText_EVO_PreEvo_PE_Mega);
    else
    {

        if (seen || !HGSS_HIDE_UNSEEN_EVOLUTION_NAMES)
            StringCopy(gStringVar2, GetSpeciesName(preSpecies)); //evolution mon name
        else
            StringCopy(gStringVar2, gText_ThreeQuestionMarks); //show questionmarks instead of name

        StringExpandPlaceholders(gStringVar3, sText_EVO_PreEvo); //evolution mon name

    }

    PrintInfoScreenTextSmall(gStringVar3, base_x, base_y + base_y_offset*base_i); //evolution mon name

    if (base_i < 3)
    {
        u32 personality = GetPokedexMonPersonality(preSpecies);
        LoadMonIconPalettePersonality(preSpecies, personality); //Loads pallete for current mon
        gTasks[taskId].data[4+base_i] = CreateMonIcon(preSpecies, SpriteCB_MonIcon, 18 + 32*base_i, 31, 4, personality); //Create pokemon sprite
        gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
    }
}

static u8 PrintPreEvolutions(u8 taskId, u16 species)
{
    u16 i;
    u16 j;

    u8 base_x = 13+8;
    u8 base_y = 51;
    u8 base_y_offset = 9;

    u16 preEvolutionOne = 0;
    u16 preEvolutionTwo = 0;
    u8 numPreEvolutions = 0;

    u16 baseFormSpecies;
    sPokedexView->sEvoScreenData.isMega = FALSE;

    //Check if it's a mega
    baseFormSpecies = GetFormSpeciesId(species, 0);
    if (baseFormSpecies != species)
    {
        const struct FormChange *formChanges = GetSpeciesFormChanges(baseFormSpecies);
        for (i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM
                && formChanges[i].targetSpecies == species)
            {
                preEvolutionOne = baseFormSpecies;
                numPreEvolutions += 1;
                sPokedexView->numPreEvolutions = numPreEvolutions;
                sPokedexView->sEvoScreenData.numAllEvolutions += numPreEvolutions;
                sPokedexView->sEvoScreenData.isMega = TRUE;

                CopyItemName(GetSpeciesFormChanges(species)->param1, gStringVar2); //item
                CreateCaughtBallEvolutionScreen(preEvolutionOne, base_x - 9 - 8, base_y + base_y_offset*(numPreEvolutions - 1), 0);
                HandlePreEvolutionSpeciesPrint(taskId, preEvolutionOne, species, base_x - 8, base_y, base_y_offset, numPreEvolutions - 1);
                return numPreEvolutions;
            }
        }
    }

    //Calculate previous evolution
    for (i = 0; i < NUM_SPECIES; i++)
    {
        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;

        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (evolutions[j].targetSpecies == species)
            {
                preEvolutionOne = i;
                numPreEvolutions += 1;
                break;
            }
        }
    }

    //Calculate if previous evolution also has a previous evolution
    if (numPreEvolutions != 0)
    {
        for (i = 0; i < NUM_SPECIES; i++)
        {
            const struct Evolution *evolutions = GetSpeciesEvolutions(i);
            if (evolutions == NULL)
                continue;

            for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
            {
                if (evolutions[j].targetSpecies == preEvolutionOne)
                {
                    preEvolutionTwo = i;
                    numPreEvolutions += 1;
                    CreateCaughtBallEvolutionScreen(preEvolutionTwo, base_x - 9, base_y + base_y_offset*0, 0);
                    HandlePreEvolutionSpeciesPrint(taskId, preEvolutionTwo, preEvolutionOne, base_x, base_y, base_y_offset, 0);
                    break;
                }
            }
        }
    }

    //Print ball and name
    if (preEvolutionOne != 0)
    {
        CreateCaughtBallEvolutionScreen(preEvolutionOne, base_x - 9, base_y + base_y_offset*(numPreEvolutions - 1), 0);
        HandlePreEvolutionSpeciesPrint(taskId, preEvolutionOne, species, base_x, base_y, base_y_offset, numPreEvolutions - 1);
    }

    if (preEvolutionTwo != 0)
    {
        sPokedexView->sEvoScreenData.targetSpecies[0] = preEvolutionTwo;
        sPokedexView->sEvoScreenData.targetSpecies[1] = preEvolutionOne;
    }
    else if (preEvolutionOne != 0)
    {
        sPokedexView->sEvoScreenData.targetSpecies[0] = preEvolutionOne;
    }

    //vertical line
    //FillWindowPixelRect(0, PIXEL_FILL(5), 33 + 32*numPreEvolutions, 18, 1, 32); //PIXEL_FILL(15) for black

    sPokedexView->numPreEvolutions = numPreEvolutions;
    sPokedexView->sEvoScreenData.numAllEvolutions += numPreEvolutions;

    return numPreEvolutions;
}

#define EVO_SCREEN_LVL_DIGITS 2
#define EVO_SCREEN_CRITS_DIGITS 1
#define EVO_SCREEN_DMG_DIGITS 2

static u8 PrintEvolutionTargetSpeciesAndMethod(u8 taskId, u16 species, u8 depth, u8 depth_i)
{
    u16 i;
    const struct MapHeader *mapHeader;
    u16 targetSpecies = 0;
    u16 previousTargetSpecies = 0;

    u16 item;

    bool8 left = TRUE;
    u8 base_x = 13+8;
    u8 base_x_offset = 54+8;
    u8 base_y = 51;
    u8 base_y_offset = 9;
    u8 base_i = 0;
    u8 times = 0;
    u8 depth_x = 16;
    bool8 isEevee = FALSE;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (sPokedexView->sEvoScreenData.isMega)
        return 0;
    if (evolutions == NULL)
        return 0;

    StringCopy(gStringVar1, GetSpeciesName(species));

    if (species == SPECIES_EEVEE)
        isEevee = TRUE;

    //Calculate number of possible direct evolutions (e.g. Eevee has 5 but torchic has 1)
    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].method != 0)
            times += 1;
    }
    gTasks[taskId].data[3] = times;
    sPokedexView->sEvoScreenData.numAllEvolutions += times;

    //If there are no evolutions print text
    if (times == 0 && depth == 0)
    {
        StringExpandPlaceholders(gStringVar4, sText_EVO_NONE);
        PrintInfoScreenTextSmall(gStringVar4, base_x-7-7, base_y + base_y_offset*depth_i);
    }

    //If there are evolutions find out which and print them 1 by 1
    for (i = 0; i < times; i++)
    {
        base_i = i + depth_i;
        left = !left;

        previousTargetSpecies = targetSpecies;
        targetSpecies = evolutions[i].targetSpecies;
        sPokedexView->sEvoScreenData.targetSpecies[base_i] = targetSpecies;
        CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_y_offset*base_i, 0);
        HandleTargetSpeciesPrint(taskId, targetSpecies, previousTargetSpecies, base_x + depth_x*depth, base_y, base_y_offset, base_i, isEevee); //evolution mon name

        switch (evolutions[i].method)
        {
        case EVO_FRIENDSHIP:
            ConvertIntToDecimalStringN(gStringVar2, 220, STR_CONV_MODE_LEADING_ZEROS, 3); //friendship value
            StringExpandPlaceholders(gStringVar4, sText_EVO_FRIENDSHIP );
            break;
        case EVO_FRIENDSHIP_DAY:
            StringExpandPlaceholders(gStringVar4, sText_EVO_FRIENDSHIP_DAY );
            break;
        case EVO_FRIENDSHIP_NIGHT:
            StringExpandPlaceholders(gStringVar4, sText_EVO_FRIENDSHIP_NIGHT );
            break;
        case EVO_LEVEL:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL );
            break;
        case EVO_TRADE:
            StringExpandPlaceholders(gStringVar4, sText_EVO_TRADE );
            break;
        case EVO_TRADE_ITEM:
            item = evolutions[i].param; //item
            CopyItemName(item, gStringVar2); //item
            StringExpandPlaceholders(gStringVar4, sText_EVO_TRADE_ITEM );
            break;
        case EVO_ITEM:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM );
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_ATK_GT_DEF );
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_ATK_EQ_DEF );
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_ATK_LT_DEF );
            break;
        case EVO_LEVEL_SILCOON:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_SILCOON );
            break;
        case EVO_LEVEL_CASCOON:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_CASCOON );
            break;
        case EVO_LEVEL_NINJASK:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_NINJASK );
            break;
        case EVO_LEVEL_SHEDINJA:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_SHEDINJA );
            break;
        case EVO_BEAUTY:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, 3); //beauty
            StringExpandPlaceholders(gStringVar4, sText_EVO_BEAUTY );
            break;
        case EVO_LEVEL_FEMALE:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_FEMALE );
            break;
        case EVO_LEVEL_MALE:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_MALE );
            break;
        case EVO_LEVEL_NIGHT:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_NIGHT );
            break;
        case EVO_LEVEL_DAY:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_DAY );
            break;
        case EVO_LEVEL_DUSK:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_DUSK );
            break;
        case EVO_ITEM_HOLD_DAY:
            item = evolutions[i].param; //item
            CopyItemName(item, gStringVar2); //item
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_HOLD_DAY );
            break;
        case EVO_ITEM_HOLD_NIGHT:
            item = evolutions[i].param; //item
            CopyItemName(item, gStringVar2); //item
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_HOLD_NIGHT );
            break;
        case EVO_MOVE:
            StringCopy(gStringVar2, GetMoveName(evolutions[i].param));
            StringExpandPlaceholders(gStringVar4, sText_EVO_MOVE );
            break;
        case EVO_FRIENDSHIP_MOVE_TYPE:
            StringCopy(gStringVar2, gTypesInfo[evolutions[i].param].name);
            StringExpandPlaceholders(gStringVar4, sText_EVO_FRIENDSHIP_MOVE_TYPE );
            break;
        case EVO_MAPSEC:
            StringCopy(gStringVar2, gRegionMapEntries[evolutions[i].param].name);
            StringExpandPlaceholders(gStringVar4, sText_EVO_MAPSEC );
            break;
        case EVO_ITEM_MALE:
            item = evolutions[i].param; //item
            CopyItemName(item, gStringVar2); //item
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_MALE );
            break;
        case EVO_ITEM_FEMALE:
            item = evolutions[i].param; //item
            CopyItemName(item, gStringVar2); //item
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_FEMALE );
            break;
        case EVO_LEVEL_RAIN:
            //if (j == WEATHER_RAIN || j == WEATHER_RAIN_THUNDERSTORM || j == WEATHER_DOWNPOUR)
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_RAIN );
            break;
        case EVO_SPECIFIC_MON_IN_PARTY:
            StringCopy(gStringVar2, GetSpeciesName(evolutions[i].param)); //mon name
            StringExpandPlaceholders(gStringVar4, sText_EVO_SPECIFIC_MON_IN_PARTY );
            break;
        case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_DARK_TYPE_MON_IN_PARTY );
            break;
        case EVO_TRADE_SPECIFIC_MON:
            StringCopy(gStringVar2, GetSpeciesName(evolutions[i].param)); //mon name
            StringExpandPlaceholders(gStringVar4, sText_EVO_TRADE_SPECIFIC_MON );
            break;
        case EVO_SPECIFIC_MAP:
            mapHeader = Overworld_GetMapHeaderByGroupAndId(evolutions[i].param >> 8, evolutions[i].param & 0xFF);
            GetMapName(gStringVar2, mapHeader->regionMapSectionId, 0);
            StringExpandPlaceholders(gStringVar4, sText_EVO_SPECIFIC_MAP );
            break;
        case EVO_LEVEL_NATURE_AMPED:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_NATURE_AMPED);
            break;
        case EVO_LEVEL_NATURE_LOW_KEY:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_LVL_DIGITS); //level
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_NATURE_LOW_KEY);
            break;
        case EVO_CRITICAL_HITS:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_CRITS_DIGITS); //crits
            StringExpandPlaceholders(gStringVar4, sText_EVO_CRITICAL_HITS);
            break;
        case EVO_SCRIPT_TRIGGER_DMG:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, EVO_SCREEN_DMG_DIGITS); //damage
            StringExpandPlaceholders(gStringVar4, sText_EVO_SCRIPT_TRIGGER_DMG);
            break;
        case EVO_DARK_SCROLL:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_DARK_SCROLL );
            break;
        case EVO_WATER_SCROLL:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_WATER_SCROLL );
            break;
        case EVO_ITEM_NIGHT:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_NIGHT );
            break;
        case EVO_ITEM_DAY:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_DAY );
            break;
        case EVO_ITEM_HOLD:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_ITEM_HOLD );
            break;
        case EVO_LEVEL_MOVE_TWENTY_TIMES:
            StringCopy(gStringVar2, GetMoveName(evolutions[i].param));
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_MOVE_TWENTY_TIMES );
            break;
        case EVO_LEVEL_RECOIL_DAMAGE_MALE:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, 3);
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_RECOIL_DAMAGE_MALE);
            break;
        case EVO_LEVEL_RECOIL_DAMAGE_FEMALE:
            ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEADING_ZEROS, 3);
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_RECOIL_DAMAGE_FEMALE);
            break;
        case EVO_LEVEL_ITEM_COUNT_999:
            item = evolutions[i].param;
            CopyItemName(item, gStringVar2);
            StringExpandPlaceholders(gStringVar4, sText_EVO_LEVEL_ITEM_COUNT_999);
            break;
        default:
            StringExpandPlaceholders(gStringVar4, sText_EVO_UNKNOWN );
            break;
        }//Switch end
        PrintInfoScreenTextSmall(gStringVar4, base_x + depth_x*depth+base_x_offset, base_y + base_y_offset*base_i); //Print actual instructions

        depth_i += PrintEvolutionTargetSpeciesAndMethod(taskId, targetSpecies, depth+1, base_i+1);
    }//For loop end

    return times;
}

static void Task_SwitchScreensFromEvolutionScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);

        switch (sPokedexView->screenSwitchState)
        {
        case 1:
            gTasks[taskId].func = Task_LoadStatsScreen;
            break;
        case 2:
            gTasks[taskId].func = Task_LoadCryScreen;
            break;
        case 3:
                gTasks[taskId].func = Task_LoadFormsScreen;
                break;
        default:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        }
    }
}

static void Task_ExitEvolutionScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);

        FreeInfoScreenWindowAndBgBuffers();
        DestroyTask(taskId);
    }
}


//************************************
//*                                  *
//*        FORMS                      *
//*                                  *
//************************************

static void Task_LoadFormsScreen(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
    default:
        if (!gPaletteFade.active)
        {
            u16 r2;

            sPokedexView->currentPage = FORMS_SCREEN;
            gPokedexVBlankCB = gMain.vblankCallback;
            SetVBlankCallback(NULL);
            r2 = 0;
            if (gTasks[taskId].data[1] != 0)
                r2 += DISPCNT_OBJ_ON;
            if (gTasks[taskId].data[2] != 0)
                r2 |= DISPCNT_BG1_ON;
            ResetOtherVideoRegisters(r2);
            gMain.state = 1;
        }
        break;
    case 1:
        LoadTilesetTilemapHGSS(FORMS_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
        FillWindowPixelBuffer(WIN_NAVIGATION_BUTTONS, PIXEL_FILL(0));
        PutWindowTilemap(WIN_NAVIGATION_BUTTONS);
        CopyWindowToVram(WIN_NAVIGATION_BUTTONS, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
        LoadPokedexBgPalette(sPokedexView->isSearchResults);
        gMain.state++;
        break;
    case 3:
        if (gTasks[taskId].data[1] == 0)
        {
            //Icon
            u32 species = NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            gTasks[taskId].data[4] = CreateMonIcon(species, SpriteCB_MonIcon, 18, 31, 4, personality); //Create pokemon sprite
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        EvoFormsPage_PrintNavigationButtons(); // Navigation buttons
        sPokedexView->sFormScreenData.menuPos = 1;
        gMain.state++;
        break;
    case 4:
        //Print form icons
        gTasks[taskId].data[3] = 0;
        PrintForms(taskId, NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum));
        LoadSpritePalette(&gSpritePalette_Arrow);
        gMain.state++;
        break;
    case 5:
        {
        u32 preservedPalettes = 0;

        if (gTasks[taskId].data[2] != 0)
            preservedPalettes = 0x14; // each bit represents a palette index
        if (gTasks[taskId].data[1] != 0)
            preservedPalettes |= (1 << (gSprites[gTasks[taskId].tMonSpriteId].oam.paletteNum + 16));
        BeginNormalPaletteFade(~preservedPalettes, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gMain.state++;
        }
        break;
    case 6:
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
    case 7:
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    case 8:
        gMain.state++;
        break;
    case 9:
        sPokedexView->screenSwitchState = 0;
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].func = Task_HandleFormsScreenInput;
        gMain.state = 0;
        break;
    }
}

static void Task_HandleFormsScreenInput(u8 taskId)
{
    u8 base_x = 5;
    u8 base_y = 34;
    u8 offset_x = 34;
    u8 offset_y = 34;
    if (!sPokedexView->sFormScreenData.inSubmenu)
    {
        if (JOY_NEW(A_BUTTON) && sPokedexView->sFormScreenData.numForms != 0)
        {
            sPokedexView->sFormScreenData.inSubmenu = TRUE;
            sPokedexView->sFormScreenData.arrowSpriteId = CreateSprite(&gSpriteTemplate_Arrow, base_x + offset_x, base_y, 0);
            gSprites[sPokedexView->sFormScreenData.arrowSpriteId].animNum = 2;
            EvoFormsPage_PrintNavigationButtons();
        }

        if (JOY_NEW(START_BUTTON))
        {
            sPokedexView->selectedScreen = EVO_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
            sPokedexView->screenSwitchState = 1;
            gTasks[taskId].func = Task_SwitchScreensFromFormsScreen;
            PlaySE(SE_PIN);
        }

        //Exit to overview
        if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ExitFormsScreen;
            PlaySE(SE_PC_OFF);
            return;
        }
    }
    else //inSubmenu
    {
        u8 row = 0;
        u8 column = 0;
        u8 menuPos = sPokedexView->sFormScreenData.menuPos;
        //Grid navigation
        if (JOY_NEW(DPAD_RIGHT))
            menuPos += 1;
        else if (JOY_NEW(DPAD_LEFT))
            menuPos -= 1;
        else if (JOY_NEW(DPAD_DOWN))
            menuPos += 7;
        else if (JOY_NEW(DPAD_UP))
        {
            if (menuPos > 7)
                menuPos -= 7;
            else
                menuPos = 1;
        }

        if (menuPos <= 0)
            menuPos = 1;
        else if (menuPos >= sPokedexView->sFormScreenData.numForms)
            menuPos = sPokedexView->sFormScreenData.numForms;

        row = menuPos / 7;
        column = menuPos % 7;
        gSprites[sPokedexView->sFormScreenData.arrowSpriteId].x = base_x + offset_x * column;
        gSprites[sPokedexView->sFormScreenData.arrowSpriteId].y = base_y + offset_y * row;

        sPokedexView->sFormScreenData.menuPos = menuPos;


        if (JOY_NEW(A_BUTTON))
        {
            u8 formId = sPokedexView->sFormScreenData.formIds[menuPos];
            u16 formSpecies = GetFormSpeciesId(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), formId);
            if (formSpecies == GetFormSpeciesId(formSpecies, 0))
                sPokedexView->formSpecies = 0;
            else
                sPokedexView->formSpecies = formSpecies;

            sPokedexView->sEvoScreenData.fromEvoPage = TRUE;
            sPokedexView->sFormScreenData.inSubmenu = FALSE;
            PlaySE(SE_PIN);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_LoadInfoScreenWaitForFade;
        }

        if (JOY_NEW(B_BUTTON))
        {
            DestroySprite(&gSprites[sPokedexView->sFormScreenData.arrowSpriteId]);
            sPokedexView->sFormScreenData.inSubmenu = FALSE;
            EvoFormsPage_PrintNavigationButtons();
        }
    }
}

#define FORM_SPECIES_END (0xffff)

static void PrintForms(u8 taskId, u16 species)
{
    u8 i;
    u8 j = 1;
    u16 speciesForm;

    u8 base_x = 5;
    u8 base_y = 52;
    u8 base_y_offset = 9;
    u8 times = 0;
    u8 y_offset_icons = 0; //For unown only

    if (species == SPECIES_UNOWN)
        y_offset_icons = 8;

    if (GetFormSpeciesId(species, 0) == SPECIES_UNOWN)
        y_offset_icons = 8;

    StringCopy(gStringVar1, GetSpeciesName(species));

    for (i=0; i < 30; i++)
    {
        speciesForm = GetFormSpeciesId(species, i);
        if (speciesForm == FORM_SPECIES_END)
            break;
        else if (speciesForm == species)
            continue;
        else
        {
            u32 personality = GetPokedexMonPersonality(speciesForm);
            sPokedexView->sFormScreenData.formIds[j++] = i;
            times += 1;
            LoadMonIconPalettePersonality(speciesForm, personality); //Loads pallete for current mon
            if (times < 7)
                gTasks[taskId].data[4+times] = CreateMonIcon(speciesForm, SpriteCB_MonIcon, 52 + 34*(times-1), 31, 4, personality); //Create pokemon sprite
            else if (times < 14)
                gTasks[taskId].data[4+times] = CreateMonIcon(speciesForm, SpriteCB_MonIcon, 18 + 34*(times-7), 70 - y_offset_icons, 4, personality); //Create pokemon sprite
            gSprites[gTasks[taskId].data[4+times]].oam.priority = 0;
        }
    }
    gTasks[taskId].data[3] = times;
    sPokedexView->sFormScreenData.numForms = times;

    //If there are no forms print text
    if (times == 0)
    {
        StringExpandPlaceholders(gStringVar4, sText_FORMS_NONE);
        PrintInfoScreenTextSmall(gStringVar4, base_x, base_y + base_y_offset*times);
    }
}

static void Task_SwitchScreensFromFormsScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);

        switch (sPokedexView->screenSwitchState)
        {
        case 1:
            gTasks[taskId].func = Task_LoadEvolutionScreen;
            break;
        default:
            gTasks[taskId].func = Task_LoadInfoScreen;
            break;
        }
    }
}

static void Task_ExitFormsScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy pokemon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy pokemon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy pokemon icon sprite
        }
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);

        FreeInfoScreenWindowAndBgBuffers();
        DestroyTask(taskId);
    }
}

#undef tMonSpriteId


//************************************
//*                                  *
//*        Cry screen                *
//*                                  *
//************************************
#define tScrolling       data[0]
#define tMonSpriteDone   data[1]
#define tBgLoaded        data[2]
#define tSkipCry         data[3]
#define tMonSpriteId     data[4]
#define tTrainerSpriteId data[5]

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
        LoadTilesetTilemapHGSS(CRY_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        PutWindowTilemap(WIN_VU_METER);
        PutWindowTilemap(WIN_CRY_WAVE);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
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
        gTasks[taskId].tMonSpriteId = CreateMonSpriteFromNationalDexNumberHGSS(sPokedexListItem->dexNum, MON_PAGE_X, MON_PAGE_Y, 0);
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
        CryScreenPlayButton(NationalPokedexNumToSpeciesHGSS(sPokedexListItem->dexNum));
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
            gTasks[taskId].func = Task_LoadEvolutionScreen;
            break;
        case 3:
            gTasks[taskId].func = Task_LoadSizeScreen;
            break;
        }
    }
}


//************************************
//*                                  *
//*        Size screen               *
//*                                  *
//************************************
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
        LoadTilesetTilemapHGSS(SIZE_SCREEN);
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        PutWindowTilemap(WIN_INFO);
        gMain.state++;
        break;
    case 2:
        LoadScreenSelectBarMain(0xD);
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
        gSprites[spriteId].y2 = GetTrainerOffsetFromNationalDexNumber(sPokedexListItem->dexNum);
        SetOamMatrix(1, GetTrainerScaleFromNationalDexNumber(sPokedexListItem->dexNum), 0, 0, GetTrainerScaleFromNationalDexNumber(sPokedexListItem->dexNum));
        LoadPalette(sSizeScreenSilhouette_Pal, OBJ_PLTT_ID2(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
        gTasks[taskId].tTrainerSpriteId = spriteId;
        gMain.state++;
        break;
    case 6:
        spriteId = CreateMonSpriteFromNationalDexNumberHGSS(sPokedexListItem->dexNum, 88, 56, 1);
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 2;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].y2 = GetPokemonOffsetFromNationalDexNumber(sPokedexListItem->dexNum);
        SetOamMatrix(2, GetPokemonScaleFromNationalDexNumber(sPokedexListItem->dexNum), 0, 0, GetPokemonScaleFromNationalDexNumber(sPokedexListItem->dexNum));
        LoadPalette(sSizeScreenSilhouette_Pal, OBJ_PLTT_ID2(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
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

static void LoadPlayArrowPalette(bool8 cryPlaying)
{
    u16 color;

    if (cryPlaying)
        color = RGB(18, 28, 0);
    else
        color = RGB(15, 21, 0);
    LoadPalette(&color, BG_PLTT_ID(5) + 13, PLTT_SIZEOF(1));
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



//************************************
//*                                  *
//*        Search Screen             *
//*                                  *
//************************************
static void Task_WaitForExitSearch(u8 taskId)
{
    if (!gTasks[gTasks[taskId].tLoadScreenTaskId].isActive)
    {
        ClearMonSprites();
        TryDestroyStatBars();
        TryDestroyStatBarsBg();

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

static void Task_OpenSearchResults(u8 taskId)
{
    sPokedexView->isSearchResults = TRUE;
    sPokedexView->sEvoScreenData.fromEvoPage = FALSE;
    sPokedexView->formSpecies = 0;
    if (LoadPokedexListPage(PAGE_SEARCH_RESULTS))
        gTasks[taskId].func = Task_HandleSearchResultsInput;
}

static void Task_HandleSearchResultsInput(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BG0VOFS, sPokedexView->menuY);

    if (sPokedexView->menuY)
    {
        sPokedexView->menuY -= 8;
        if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 8)
        {
            CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
            CreateStatBarsBg();
        }
    }
    else
    {
        if (JOY_NEW(A_BUTTON) && sPokedexView->pokedexList[sPokedexView->selectedPokemon].seen)
        {
            u32 a;

            TryDestroyStatBars();
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
            TryDestroyStatBars();
            TryDestroyStatBarsBg();
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
            TryDestroyStatBars();
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
            else if (!sPokedexView->scrollTimer && !sPokedexView->scrollSpeed && sPokedexView->justScrolled)
                CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
        }
    }
}

static void Task_WaitForSearchResultsScroll(u8 taskId)
{
    TryDestroyStatBars();
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


//************************************
//*                                  *
//*        Search code               *
//*                                  *
//************************************
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
            firstLetter = GetSpeciesName(species)[0];
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

            if (bodyColor == gSpeciesInfo[species].bodyColor)
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

                    types[0] = gSpeciesInfo[species].types[0];
                    types[1] = gSpeciesInfo[species].types[1];
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

                    types[0] = gSpeciesInfo[species].types[0];
                    types[1] = gSpeciesInfo[species].types[1];
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
            if (!HGSS_DECAPPED)
                DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_MenuSearch_Gfx, 0x2000, 0, 0);
            else
                DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_MenuSearch_DECA_Gfx, 0x2000, 0, 0);
            if (!IsNationalPokedexEnabled())
                CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenSearchHoenn_Tilemap, 0, 0);
            else
                CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenSearchNational_Tilemap, 0, 0);
            if (!HGSS_DARK_MODE)
                LoadPalette(sPokedexPlusHGSS_MenuSearch_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(4 * 16 - 1));
            else
                LoadPalette(sPokedexPlusHGSS_MenuSearch_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(4 * 16 - 1));
            gMain.state = 1;
        }
        break;
    case 1:
        LoadCompressedSpriteSheet(&sInterfaceSpriteSheet[HGSS_DECAPPED]);
        LoadSpritePalettes(sInterfaceSpritePalette);
        LoadSpritePalettes(sStatBarSpritePal);
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
        sPokedexView->statBarsSpriteId = 0xFF;
        CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
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
    s16 *cursorPos;
    s16 *scrollOffset;

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
    s16 *cursorPos;
    s16 *scrollOffset;
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

static void SetSearchRectHighlight(u8 flags, u8 x, u8 y, u8 width)
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
    const s16 *cursorPos = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].tMenuItem].taskDataCursorPos];
    const s16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[gTasks[taskId].tMenuItem].taskDataScrollOffset];
    u16 i;
    u16 j;

    ClearSearchParameterBoxText();

    for (i = 0, j = *scrollOffset; i < MAX_SEARCH_PARAM_ON_SCREEN && texts[j].title != NULL; i++, j++)
        PrintSearchParameterTitle(i, texts[j].title);

    EraseAndPrintSearchTextBox(texts[*cursorPos + *scrollOffset].description);
}

static u8 GetSearchModeSelection(u8 taskId, u8 option)
{
    const s16 *cursorPos = &gTasks[taskId].data[sSearchOptions[option].taskDataCursorPos];
    const s16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[option].taskDataScrollOffset];
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
    const s16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
    u16 lastOption = sSearchOptions[menuItem].numOptions - 1;

    if (lastOption > MAX_SEARCH_PARAM_CURSOR_POS && *scrollOffset != 0)
        return FALSE;
    else
        return TRUE;
}

static bool8 SearchParamCantScrollDown(u8 taskId)
{
    u8 menuItem = gTasks[taskId].tMenuItem;
    const s16 *scrollOffset = &gTasks[taskId].data[sSearchOptions[menuItem].taskDataScrollOffset];
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
