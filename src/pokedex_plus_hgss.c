#include "global.h"
#include "battle_main.h"
#include "battle_util.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "debug.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "line_break.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokedex_common.h"
#include "pokedex_plus_hgss.h"
#include "pokedex_area_screen.h"
#include "pokedex_cry_screen.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "pokemon.h"
#include "reset_rtc_screen.h"
#include "rtc.h"
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
#include "config/pokedex_plus_hgss.h"

// static .rodata strings

static const u8 sText_TenDashes[] = _("----------");
ALIGNED(4) static const u8 sExpandedPlaceholder_PokedexDescription[] = _("");

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
static const u8 sText_Stats_eggGroup_UNKNOWN[] = _("???");
static const u8 sText_Dex_SEEN[] = _("SEEN");
static const u8 sText_Dex_OWN[] = _("OWN");

static const u8 sText_EVO_Buttons[] = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK");
static const u8 sText_EVO_Buttons_Decapped[] = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check");
static const u8 sText_EVO_Buttons_PE[] = _("{DPAD_UPDOWN}EVOs  {A_BUTTON}CHECK  {START_BUTTON}FORMs");
static const u8 sText_EVO_Buttons_Decapped_PE[] = _("{DPAD_UPDOWN}Evos  {A_BUTTON}Check  {START_BUTTON}Forms");
static const u8 sText_EVO_Name[] = _("{STR_VAR_3}:");
static const u8 sText_EVO_PreEvo[] = _("{STR_VAR_1} evolves from {STR_VAR_2}");
static const u8 sText_EVO_PreEvo_PE_Mega[] = _("{STR_VAR_1} Mega Evolves with {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_SILCOON[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Silcoon persona");
static const u8 sText_EVO_LEVEL_CASCOON[] = _("{LV}{UP_ARROW} to {STR_VAR_2}, Cascoon persona");
static const u8 sText_EVO_MOVE[] = _("{LV}{UP_ARROW}, knows {STR_VAR_2}");
static const u8 sText_EVO_LEVEL_RAIN[] = _("{LV}{UP_ARROW} to {STR_VAR_2} while raining");
static const u8 sText_EVO_TRADE_SPECIFIC_MON[] = _("Traded for {STR_VAR_2}");
static const u8 sText_EVO_CRITICAL_HITS[] = _("Land {STR_VAR_2} critical hits in\nsingle battle");
static const u8 sText_EVO_SCRIPT_TRIGGER_DMG[] = _("Takes at least {STR_VAR_2} HP in damage");
static const u8 sText_EVO_DARK_SCROLL[] = _("ScrllOfDrknss is used");
static const u8 sText_EVO_WATER_SCROLL[] = _("ScrollOfWatrs is used");
static const u8 sText_EVO_USE_MOVE_TWENTY_TIMES[] = _("{LV}{UP_ARROW} after 20x {STR_VAR_2}");
static const u8 sText_EVO_RECOIL_DAMAGE_MALE[] = _("{LV}{UP_ARROW} with {STR_VAR_2} recoil, male");
static const u8 sText_EVO_RECOIL_DAMAGE_FEMALE[] = _("{LV}{UP_ARROW} with {STR_VAR_2} recoil, female");
static const u8 sText_EVO_DEFEAT_THREE_WITH_ITEM[] = _("{LV}{UP_ARROW} defeating 3 {STR_VAR_3} holding {STR_VAR_2}");
static const u8 sText_EVO_NONE[] = _("{STR_VAR_1} has no evolution.");

static const u8 sText_FORMS_Buttons_PE[] = _("{A_BUTTON}FORM MODE  {START_BUTTON}EVOs");
static const u8 sText_FORMS_Buttons_Decapped_PE[] = _("{A_BUTTON}Form Mode  {START_BUTTON}Evos");
static const u8 sText_FORMS_Buttons_Submenu_PE[] = _("{DPAD_NONE}FORMs {A_BUTTON}CHECK {START_BUTTON}EVOs");
static const u8 sText_FORMS_Buttons_Submenu_Decapped_PE[] = _("{DPAD_NONE}Forms {A_BUTTON}Check {START_BUTTON}Evos");
static const u8 sText_FORMS_NONE[] = _("{STR_VAR_1} has no alternate forms.");
static const u8 sText_PlusSymbol[] = _("+");

// static .rodata graphics

static const u16 sPokedexPlusHGSS_Default_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_default.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_National_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_national.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_MenuSearch_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_search_menu.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_SearchResults_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_search_results.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_Default_dark_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_default_dark.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_National_dark_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_national_dark.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_MenuSearch_dark_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_search_menu_dark.pal", ".gbapal");
static const u16 sPokedexPlusHGSS_SearchResults_dark_Pal[] = INCGFX_U16("graphics/pokedex/hgss/palette_search_results_dark.pal", ".gbapal");
static const u32 sPokedexPlusHGSS_MenuList_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu_list.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_MenuList_DECA_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu_list_DECA.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_Interface_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_interface.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_Interface_DECA_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_interface_DECA.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_Menu_1_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu1.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_Menu_2_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu2.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_Menu_3_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu3.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_MenuSearch_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu_search.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_MenuSearch_DECA_Gfx[] = INCGFX_U32("graphics/pokedex/hgss/tileset_menu_search_DECA.png", ".4bpp.smol");
static const u32 sPokedexPlusHGSS_StartMenuMain_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_start_menu.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_StartMenuSearchResults_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_start_menu_search_results.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/SelectBar.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenSelectBarSubmenu_Tilemap_Clear[] = INCGFX_U32("graphics/pokedex/hgss/SelectBar_clear.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenList_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_list_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenListUnderlay_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_list_screen_underlay.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenInfo_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_info_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenStats_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_stats_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenEvolution_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_evo_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenEvolution_Tilemap_PE[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_evo_screen_PE.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenForms_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_forms_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenCry_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_cry_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenSize_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_size_screen.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenSearchHoenn_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_search_screen_hoenn.bin", ".smolTM");
static const u32 sPokedexPlusHGSS_ScreenSearchNational_Tilemap[] = INCGFX_U32("graphics/pokedex/hgss/tilemap_search_screen_national.bin", ".smolTM");

#define MAX_EVOLUTION_ICONS 8

// for evolution method listings
#define MAX_EVO_METHOD_LINES 10

// Width of pixels one line of text in the species box can be
#define STATS_PAGE_SPECIES_MAX_WIDTH 55

extern EWRAM_DATA struct PokedexView *sPokedexView;
extern EWRAM_DATA struct PokedexListItem *sPokedexListItem;
//Pokedex Plus HGSS_Ui


static bool8 LoadPokedexListPage(u8);
static void CreateInterfaceSprites(u8);
static void LoadScreenSelectBarMain(u16);
static void PrintMonInfo(u32 num, u32, u32 owned, u32 newEntry);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void CreateTypeIconSprites(void);

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
static void PrintInfoScreenTextSmall(const u8* str, u8 fontId, u8 left, u8 top);
static void Task_LoadEvolutionScreen(u8 taskId);
static void Task_HandleEvolutionScreenInput(u8 taskId);
static void Task_SwitchScreensFromEvolutionScreen(u8 taskId);
static void Task_ExitEvolutionScreen(u8 taskId);
static void PrintEvolutionTargetSpeciesAndMethod(u8 taskId, enum Species species, u8 depth, u32 *depth_i, u32 alreadyPrintedIcons[], u32 *icon_depth_i, u32 numLines);
static u8 PrintPreEvolutions(u8 taskId, enum Species species);
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
static void PrintForms(u8 taskId, enum Species species);
static void Task_SwitchScreensFromFormsScreen(u8 taskId);
static void Task_ExitFormsScreen(u8 taskId);

//Physical/Special/Status category icon
static u8 ShowCategoryIcon(enum DamageCategory category);
static void DestroyCategoryIcon(void);

//Evo screen
static u32 GetSpeciesNameFontId(u32 nameWidth);
static u32 GetSpeciesNameWidthInChars(const u8 *speciesName);
static bool32 IsSpeciesAlcremie(enum Species targetSpecies);
static bool32 IsItemSweet(enum Item item);
static void TryLoadDarkModeArrowPalette(void);

//Cry screen
static void FillCryMeterWindowTilemapWithBg(void);

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
    .callback = SpriteCB_StatBars,
};
static const struct SpriteTemplate sStatBarBgSpriteTemplate =
{
    .tileTag = TAG_STAT_BAR_BG,
    .paletteTag = TAG_STAT_BAR_BG,
    .oam = &sOamData_StatBarBg,
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
static const u8 sStatBarsGfx[] = INCGFX_U8("graphics/pokedex/hgss/stat_bars.png", ".4bpp");
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

static const struct CompressedSpriteSheet sInterfaceSpriteSheet[] =
{
    {sPokedexPlusHGSS_Interface_Gfx, 0x2000, TAG_DEX_INTERFACE},
    {sPokedexPlusHGSS_Interface_DECA_Gfx, 0x2000, TAG_DEX_INTERFACE},
    {0}
};

static const struct SpritePalette sInterfaceSpritePalette[] =
{
    {sPokedexPlusHGSS_Default_Pal, TAG_DEX_INTERFACE},
    {sPokedexPlusHGSS_Default_dark_Pal, TAG_DEX_INTERFACE},
    {0}
};

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

bool32 TryInitWindows_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    InitWindows(sInfoScreen_WindowTemplates);
    return TRUE;
}

enum
{
    WIN_STATS_TOPBAR,
    WIN_STATS_SIDEBAR,
    WIN_STATS_NAME_GENDER,
    WIN_STATS_LEFT,
    WIN_STATS_NAVIGATION_BUTTONS,
    WIN_STATS_MOVES_TOP,
    WIN_STATS_MOVES_DESCRIPTION,
    WIN_STATS_MOVES_BOTTOM,
    WIN_STATS_ABILITIES,
};
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
    DUMMY_WIN_TEMPLATE
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


//************************************
//*                                  *
//*        MAIN                      *
//*                                  *
//************************************
bool32 TryOpenPokedexPage_HGSS(u8 taskId, u8 page)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;
    
    if (LoadPokedexListPage(page))
        gTasks[taskId].func = Task_HandlePokedexInput;

    return TRUE;
}

#define tLoadScreenTaskId data[0]

bool32 TryLoadPokedexBgPalette_HGSS(bool8 isSearchResults)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    if (!HGSS_DARK_MODE)
    {
        if (isSearchResults == TRUE)
            LoadPalette(sPokedexPlusHGSS_SearchResults_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else if (!IsNationalPokedexEnabled())
            LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else
            LoadPalette(sPokedexPlusHGSS_National_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
    }
    else
    {
        if (isSearchResults == TRUE)
            LoadPalette(sPokedexPlusHGSS_SearchResults_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else if (!IsNationalPokedexEnabled())
            LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
        else
            LoadPalette(sPokedexPlusHGSS_National_dark_Pal + 1, BG_PLTT_ID(0) + 1, PLTT_SIZEOF(6 * 16 - 1));
    }

    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    return TRUE;
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
        LoadSpritePalette(&sInterfaceSpritePalette[HGSS_DARK_MODE]);
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
        if (sPokedexView->originalSearchSelectionNum != 0)
        {
            // when returning to search results after selecting an evo, we have to restore
            // the original dexNum because the search results page doesn't rebuild the list
            sPokedexListItem->dexNum = sPokedexView->originalSearchSelectionNum;
            sPokedexListItem->seen   = GetSetPokedexFlag(sPokedexView->originalSearchSelectionNum, FLAG_GET_SEEN);
            sPokedexListItem->owned  = GetSetPokedexFlag(sPokedexView->originalSearchSelectionNum, FLAG_GET_CAUGHT);
            sPokedexView->originalSearchSelectionNum = 0;
        }
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

// u16 ignored is passed but never used
#define MON_LIST_X 2
bool32 TryCreateMonListEntry_HGSS(u8 position, u16 b, u16 ignored)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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

    return TRUE;
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
        seenOwnedCount = GetRegionalPokedexCount(FLAG_GET_SEEN);
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

        seenOwnedCount = GetRegionalPokedexCount(FLAG_GET_CAUGHT);
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

bool32 TryMoveMonForInfoScreen_HGSS(struct Sprite *sprite)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    if (sprite->x > MON_PAGE_X)
        sprite->x -= 4;
    if (sprite->x < MON_PAGE_X)
        sprite->x = MON_PAGE_X;

    if (sprite->y > MON_PAGE_Y)
        sprite->y -= 4;
    if (sprite->y < MON_PAGE_Y)
        sprite->y = MON_PAGE_Y;

    return TRUE;
}



//************************************
//*                                  *
//*        STATS BARS                *
//*                                  *
//************************************

//Stat bars on main screen, code by DizzyEgg, idea by Jaizu
#define PIXEL_COORDS_TO_OFFSET(x, y)(           \
/*Add tiles by X*/                              \
((y / 8) * 32 * 8)                              \
/*Add tiles by X*/                              \
+ ((x / 8) * 32)                                \
/*Add pixels by Y*/                             \
+ ((((y) - ((y / 8) * 8))) * 4)                 \
/*Add pixels by X*/                             \
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
void TryDestroyStatBars(void)
{
    if (sPokedexView->statBarsSpriteId != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_STAT_BAR);
        //FreeSpriteOamMatrix(&gSprites[sPokedexView->statBarsSpriteId]);
        DestroySprite(&gSprites[sPokedexView->statBarsSpriteId]);
        sPokedexView->statBarsSpriteId = 0xFF;
    }
}
void TryDestroyStatBarsBg(void)
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
        enum Species species = NationalPokedexNumToSpecies(dexMon->dexNum);

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
// Hack to destroy sprites when a Pokémon data is being loaded in
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

bool32 Task_TryLoadInfoScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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
        DrawFootprint(WIN_FOOTPRINT, NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum));
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
        break;
    }
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

    return TRUE;
}

bool32 TryHandleInfoScreenInput_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    if (POKEDEX_PLUS_HGSS && ((JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))))
    {
        sPokedexView->selectedScreen = AREA_SCREEN;
        BeginNormalPaletteFade(0xFFFFFFEB, 0, 0, 0x10, RGB_BLACK);
        sPokedexView->screenSwitchState = 1;
        gTasks[taskId].func = Task_SwitchScreensFromInfoScreen;
        PlaySE(SE_PIN);
    }

    return TRUE;
}

#undef tMonSpriteId

//************************************
//*                                  *
//*        Area screen               *
//*                                  *
//************************************
bool32 TryLoadAreaScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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
        DisplayPokedexAreaScreen(NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum), &sPokedexView->screenSwitchState, gAreaTimeOfDay, DEX_SHOW_AREA_SCREEN);
        SetVBlankCallback(gPokedexVBlankCB);
        sPokedexView->screenSwitchState = 0;
        gMain.state = 0;
        gTasks[taskId].func = Task_WaitForAreaScreenInput;
        break;
    }

    return TRUE;
}

bool32 TrySwitchScreensFromAreaScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    switch (sPokedexView->screenSwitchState)
    {
    case 1:
    default:
        gTasks[taskId].func = Task_LoadInfoScreen;
        break;
    case 2:
        if (sPokedexListItem->owned)
            gTasks[taskId].func = Task_LoadStatsScreen;
        else
            PlaySE(SE_FAILURE);
        break;
    case 3:
        gTasks[taskId].func = Task_ReloadAreaScreen;
        break;
    }

    return TRUE;
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

// Types palettes need to be loaded at a different slot than anticipated by gTypesInfo
// to avoid overlapping with caught mon sprite palette slot
// Normal type info palette slots: 13, 14 and 15
// Caught mon palette slot: 15
#define TYPE_INFO_PALETTE_NUM_OFFSET -1

void Task_DisplayCaughtMonDexPageHGSS(u8 taskId)
{
    u8 spriteId;
    enum Species species;
    enum NationalDexOrder dexNum;

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
    {
        u32 personality = ((u16)gTasks[taskId].tPersonalityHi << 16) | (u16)gTasks[taskId].tPersonalityLo;
        const u16 *paletteData = GetMonSpritePalFromSpeciesAndPersonality(species, FALSE, personality);

        spriteId = Pokedex_CreateCaughtMonSprite(species, MON_PAGE_X, MON_PAGE_Y);
        LoadPalette(paletteData, OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(gPokedexVBlankCB);
        gTasks[taskId].tMonSpriteId = spriteId;
        gTasks[taskId].tState++;
        break;
    }
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
static void PrintInfoScreenTextWhite(const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_DYNAMIC_COLOR_6;

    AddTextPrinterParameterized4(0, FONT_NORMAL, left, top, 0, 0, color, TEXT_SKIP_DRAW, str);
}
static void PrintInfoScreenTextSmall(const u8* str, u8 fontId, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(0, fontId, left, top, 0, 0, color, 0, str);
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
static void PrintStatsScreenTextSmallNarrower(u8 windowId, const u8* str, u8 left, u8 top)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_6;
    color[2] = TEXT_COLOR_LIGHT_GRAY;

    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, left, top, 0, 0, color, 0, str);
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
void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]].invisible = invisible;
}

static void SetTypeIconPosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite;

    sprite = &gSprites[sPokedexView->typeIconSpriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    if (typeId < NUMBER_OF_MON_TYPES)
        sprite->oam.paletteNum = gTypesInfo[typeId].palette + TYPE_INFO_PALETTE_NUM_OFFSET;
    else
        sprite->oam.paletteNum = gContestCategoryInfo[typeId - NUMBER_OF_MON_TYPES].palette  + TYPE_INFO_PALETTE_NUM_OFFSET;
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}
static void PrintCurrentSpeciesTypeInfo(u8 newEntry, enum Species species)
{
    enum Type type1, type2;

    if (!newEntry)
    {
        species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
    }
    //type icon(s)
    #ifdef TX_RANDOMIZER_AND_CHALLENGES
        type1 = GetTypeBySpecies(species, 1);
        type2 = GetTypeBySpecies(species, 2);
    #else
        type1 = GetSpeciesType(species, 0);
        type2 = GetSpeciesType(species, 1);
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
    u32 paletteNum = gTypesInfo[TYPE_NORMAL].palette + TYPE_INFO_PALETTE_NUM_OFFSET;
    LoadPalette(gMoveTypes_Pal, OBJ_PLTT_ID(paletteNum), 3 * PLTT_SIZE_4BPP);
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
    enum Species species;
    const u8 *name;
    const u8 *category;
    const u8 *description;
    u8 digitCount = (NATIONAL_DEX_COUNT > 999 && value != 0) ? 4 : 3;

    if (value == 0)
        value = NationalToRegionalOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, digitCount);
    PrintInfoScreenTextWhite(str, 123, 17);
    species = NationalPokedexNumToSpeciesForm(num);
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

#define MALE_PERSONALITY 0xFE

// Unown and Spinda use the personality of the first seen individual of that species
// All others use personality 0
static u32 GetPokedexMonPersonality(enum Species species)
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

#undef TYPE_INFO_PALETTE_NUM_OFFSET



//************************************
//*                                  *
//*        HGSS                      *
//*                                  *
//************************************
static void LoadTilesetTilemapHGSS(u8 page)
{
    switch (page)
    {
    case INFO_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenInfo_Tilemap, 0, 0);
        break;
    case STATS_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_1_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenStats_Tilemap, 0, 0);
        break;
    case EVO_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenEvolution_Tilemap_PE, 0, 0);
        break;
    case FORMS_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_2_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenForms_Tilemap, 0, 0);
        break;
    case CRY_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenCry_Tilemap, 0, 0);
        break;
    case SIZE_SCREEN:
        DecompressAndLoadBgGfxUsingHeap(3, sPokedexPlusHGSS_Menu_3_Gfx, 0x2000, 0, 0);
        CopyToBgTilemapBuffer(3, sPokedexPlusHGSS_ScreenSize_Tilemap, 0, 0);
        break;
    }
}

//Physical/Special/Status category
static u8 ShowCategoryIcon(enum DamageCategory category)
{
    if (sPokedexView->categoryIconSpriteId == 0xFF)
        sPokedexView->categoryIconSpriteId = CreateSprite(&gSpriteTemplate_CategoryIcons, 139, 90, 0);

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

    ClearWindowTilemap(WIN_INFO);
    FreeAllWindowBuffers();
    InitWindows(sStatsScreen_WindowTemplates);

    for (i = 0; i < ARRAY_COUNT(sStatsScreen_WindowTemplates); i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static void SaveMonDataInStruct(void)
{
    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
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
    sPokedexView->sPokemonStats.baseHP              = GetSpeciesBaseHP(species);
    sPokedexView->sPokemonStats.baseSpeed           = GetSpeciesBaseSpeed(species);
    sPokedexView->sPokemonStats.baseAttack          = GetSpeciesBaseAttack(species);
    sPokedexView->sPokemonStats.baseSpAttack        = GetSpeciesBaseSpAttack(species);
    sPokedexView->sPokemonStats.baseDefense         = GetSpeciesBaseDefense(species);
    sPokedexView->sPokemonStats.baseSpDefense       = GetSpeciesBaseSpDefense(species);
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
        LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
        LoadSpritePalette(&gSpritePal_CategoryIcons);
        gMain.state++;
        break;
    case 4:
        SaveMonDataInStruct();
        sPokedexView->moveSelected = 0;
        sPokedexView->movesTotal = 0;
        sPokedexView->numEggMoves = 0;
        sPokedexView->numLevelUpMoves = 0;
        sPokedexView->numTeachableMoves = 0;
        if (CalculateMoves())
            gMain.state++;
        break;
    case 5:
        if (gTasks[taskId].data[1] == 0)
        {
            //Icon
            enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            gTasks[taskId].data[6] = CreateMonIcon(species, SpriteCB_MonIcon, 18, 31, 4, personality); //Create Pokémon sprite
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
            LoadPalette(gPlttBufferUnfaded + 1, BG_PLTT_ID(3) + 1, 30);
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
        break;
    }
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

static u32 CountSpeciesEggMoves(enum Species species)
{
    u32 numEggMoves = 0;
    const u16 *eggMoveLearnset = GetSpeciesEggMoves(species);
    for (u32 i = 0; eggMoveLearnset[i] != MOVE_UNAVAILABLE; i++)
        numEggMoves++;

    return numEggMoves;
}

static bool8 CalculateMoves(void)
{
    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);

    u32 numEggMoves = 0;
    u32 numLevelUpMoves = 0;
    u32 numTeachableMoves = 0;
    u32 i;

    // Mega and Gmax Pokémon don't have distinct learnsets from their base form; so use base species for calculation
    if (gSpeciesInfo[species].isMegaEvolution || gSpeciesInfo[species].isGigantamax)
        species = GetFormSpeciesId(species, 0);

    // Egg moves
    if (HGSS_SHOW_EGG_MOVES_FOR_EVOS)
        numEggMoves = CountSpeciesEggMoves(GetEggSpecies(species));
    else
        numEggMoves = CountSpeciesEggMoves(species);

    // Level up moves
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
        numLevelUpMoves++;

    // TM and Tutor moves
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);
    for (i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
        numTeachableMoves++;

    sPokedexView->numEggMoves = numEggMoves;
    sPokedexView->numLevelUpMoves = numLevelUpMoves;
    sPokedexView->numTeachableMoves = numTeachableMoves;
    sPokedexView->movesTotal = (numEggMoves + numLevelUpMoves + numTeachableMoves);

    return TRUE;
}

static enum Move GetSelectedMove(enum Species species, u32 selected)
{
    if (selected < sPokedexView->numEggMoves)
    {
        if (!HGSS_SHOW_EGG_MOVES_FOR_EVOS)
            return GetSpeciesEggMoves(species)[selected];
        enum Species preSpecies = species;
        while (GetSpeciesPreEvolution(preSpecies) != SPECIES_NONE)
            preSpecies = GetSpeciesPreEvolution(preSpecies);
        return GetSpeciesEggMoves(preSpecies)[selected];
    }
    selected -= sPokedexView->numEggMoves;
    if (selected < sPokedexView->numLevelUpMoves)
        return GetSpeciesLevelUpLearnset(species)[selected].move;
    selected -= sPokedexView->numLevelUpMoves;
    if (selected < sPokedexView->numTeachableMoves)
        return GetSpeciesTeachableLearnset(species)[selected];
    return MOVE_NONE; //It should never get here but it allows us to visually see errors
}

static void PrintStatsScreen_Moves_Top(u8 taskId)
{
    u8 moves_x = 5;
    u8 moves_y = 3;

    enum Item item = ITEM_MASTER_BALL;
    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
    u32 selected = sPokedexView->moveSelected;
    enum Move move = GetSelectedMove(species, selected);
    //Moves selected from move max
    ConvertIntToDecimalStringN(gStringVar1, (selected+1), STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, sPokedexView->movesTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar1, sText_Stats_MoveSelectedMax);
    PrintStatsScreenTextSmallWhite(WIN_STATS_MOVES_TOP, gStringVar1, moves_x-1, moves_y+1);

    //Calculate and retrieve correct move from the arrays
    if (selected < sPokedexView->numEggMoves)
    {
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gText_ThreeDashes, moves_x + 113, moves_y + 9);
        item = ITEM_LUCKY_EGG;
    }
    else if (selected < (sPokedexView->numLevelUpMoves + sPokedexView->numEggMoves))
    {
        u32 level = GetSpeciesLevelUpLearnset(species)[selected - sPokedexView->numEggMoves].level;
        ConvertIntToDecimalStringN(gStringVar1, level, STR_CONV_MODE_LEFT_ALIGN, 3); //Move learn lvl
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, sText_Stats_MoveLevel, moves_x + 113, moves_y + 3); //Level text
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar1, moves_x + 113, moves_y + 14); //Print level
        item = ITEM_RARE_CANDY;
    }
    else if (move)
    {
        enum Item TMHMItemId = ITEM_NONE;
        for (u32 i = 0; i < NUM_ALL_MACHINES; i++)
        {
            if (move == GetTMHMMoveId(i + 1))
                TMHMItemId = GetTMHMItemId(i + 1);
        }
        if (TMHMItemId)
        {
            CopyItemName(TMHMItemId, gStringVar1); //TM name
            PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar1, moves_x + 113, moves_y + 9);
            item = TMHMItemId;
        }
        else
        {
            PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gText_ThreeDashes, moves_x + 113, moves_y + 9);
            item = ITEM_TEACHY_TV;
        }
    }
    else
    {
        StringCopy(gStringVar4, gText_CommunicationError);
    }

    //Move name
    StringCopy(gStringVar3, GetMoveName(move));
    StringCopyPadded(gStringVar3, gStringVar3, CHAR_SPACE, 20);
    PrintStatsScreenTextSmall(WIN_STATS_MOVES_TOP, gStringVar3, moves_x, moves_y + 17);

    //Draw move type icon
    if (gTasks[taskId].data[5] == 0)
    {
        SetTypeIconPosAndPal(GetMoveType(move), moves_x + 146, moves_y + 17, 0);
        SetSpriteInvisibility(1, TRUE);
    }
    else
    {
        SetTypeIconPosAndPal(NUMBER_OF_MON_TYPES + GetMoveContestCategory(move), moves_x + 146, moves_y + 17, 1);
        SetSpriteInvisibility(0, TRUE);
    }

    //Egg/TM/Level/Tutor Item Icon
    gTasks[taskId].data[3] = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
// The associated sprite gets cleared a bunch below - I assume that's still okay if it is MAX_SPRITES?
    if (gTasks[taskId].data[3] != MAX_SPRITES)
    {
        gSprites[gTasks[taskId].data[3]].x2 = 203;
        gSprites[gTasks[taskId].data[3]].y2 = 39;
        gSprites[gTasks[taskId].data[3]].oam.priority = 0;
    }
}

static void PrintStatsScreen_Moves_Description(u8 taskId)
{
    u8 moves_x = 5;
    u8 moves_y = 5;

    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
    enum Move move = GetSelectedMove(species, sPokedexView->moveSelected);

    //Move description
    if (gTasks[taskId].data[5] == 0)
    {
        StringCopy(gStringVar4, GetMoveDescription(move));
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_DESCRIPTION, gStringVar4, moves_x, moves_y);
    }
    else
    {
        StringCopy(gStringVar4, gContestEffects[GetMoveContestEffect(move)].description);
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

    //Contest
    u8 contest_effectValue;
    u8 contest_appeal = 0;
    u8 contest_jam = 0;

    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
    enum Move move = GetSelectedMove(species, sPokedexView->moveSelected);

    //Power + Accuracy
    if (gTasks[taskId].data[5] == 0)
    {
        //Power
        u32 power = GetMovePower(move);
        if (power < 2)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, power, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar1, moves_x + 45, moves_y);
        //Physical/Special/Status Category
        DestroyCategoryIcon();
        ShowCategoryIcon(GetMoveCategory(move));
        //Accuracy
        u32 accuracy = GetMoveAccuracy(move);
        if (accuracy == 0)
            StringCopy(gStringVar1, gText_ThreeDashes);
        else
            ConvertIntToDecimalStringN(gStringVar1, accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar1,  moves_x + 114, moves_y);
    }
    else //Appeal + Jam
    {
        DestroyCategoryIcon();
        //Appeal
        contest_effectValue = gContestEffects[GetMoveContestEffect(move)].appeal;
        if (contest_effectValue != 0xFF)
            contest_appeal = contest_effectValue / 10;
        ConvertIntToDecimalStringN(gStringVar1, contest_appeal, STR_CONV_MODE_RIGHT_ALIGN, 1);
        StringCopy(gStringVar2, sText_PlusSymbol);
        StringAppend(gStringVar2, gStringVar1);
        PrintStatsScreenTextSmall(WIN_STATS_MOVES_BOTTOM, gStringVar2, moves_x + 45, moves_y);

        //Jam
        contest_effectValue = gContestEffects[GetMoveContestEffect(move)].jam;
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
    enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);

    u8 base_x = 38;
    u8 base_y = 0;
    u8 gender_x, gender_y;

    //Name
    const u8 *name = GetSpeciesName(species);
    if (GetStringWidth(FONT_SMALL, name, 0) <= STATS_PAGE_SPECIES_MAX_WIDTH)
        PrintStatsScreenTextSmall(WIN_STATS_NAME_GENDER, name, base_x, base_y);
    else
        PrintStatsScreenTextSmallNarrower(WIN_STATS_NAME_GENDER, name, base_x, base_y);

    //Number
    if (value == 0)
        value = NationalToRegionalOrder(num);
    else
        value = num;
    ConvertIntToDecimalStringN(StringCopy(str, gText_NumberClear01), value, STR_CONV_MODE_LEADING_ZEROS, 4);
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
        enum GrowthRate growthRate = sPokedexView->sPokemonStats.growthRate;

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
        case EGG_GROUP_MONSTER:
            StringCopy(gStringVar1, sText_Stats_eggGroup_MONSTER);
            break;
        case EGG_GROUP_WATER_1:
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_1);
            break;
        case EGG_GROUP_BUG:
            StringCopy(gStringVar1, sText_Stats_eggGroup_BUG);
            break;
        case EGG_GROUP_FLYING:
            StringCopy(gStringVar1, sText_Stats_eggGroup_FLYING);
            break;
        case EGG_GROUP_FIELD:
            StringCopy(gStringVar1, sText_Stats_eggGroup_FIELD);
            break;
        case EGG_GROUP_FAIRY:
            StringCopy(gStringVar1, sText_Stats_eggGroup_FAIRY);
            break;
        case EGG_GROUP_GRASS:
            StringCopy(gStringVar1, sText_Stats_eggGroup_GRASS);
            break;
        case EGG_GROUP_HUMAN_LIKE:
            StringCopy(gStringVar1, sText_Stats_eggGroup_HUMAN_LIKE);
            break;
        case EGG_GROUP_WATER_3:
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_3);
            break;
        case EGG_GROUP_MINERAL:
            StringCopy(gStringVar1, sText_Stats_eggGroup_MINERAL);
            break;
        case EGG_GROUP_AMORPHOUS:
            StringCopy(gStringVar1, sText_Stats_eggGroup_AMORPHOUS);
            break;
        case EGG_GROUP_WATER_2:
            StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_2);
            break;
        case EGG_GROUP_DITTO:
            StringCopy(gStringVar1, sText_Stats_eggGroup_DITTO);
            break;
        case EGG_GROUP_DRAGON:
            StringCopy(gStringVar1, sText_Stats_eggGroup_DRAGON);
            break;
        case EGG_GROUP_NO_EGGS_DISCOVERED:
            StringCopy(gStringVar1, sText_Stats_eggGroup_NO_EGGS_DISCOVERED);
            break;
        default:
            StringCopy(gStringVar1, sText_Stats_eggGroup_UNKNOWN);
            break;
        }
        //Egg group 2
        if (sPokedexView->sPokemonStats.eggGroup1 != sPokedexView->sPokemonStats.eggGroup2)
        {
            switch (sPokedexView->sPokemonStats.eggGroup2)
            {
            case EGG_GROUP_MONSTER:
                StringCopy(gStringVar2, sText_Stats_eggGroup_MONSTER);
                break;
            case EGG_GROUP_WATER_1:
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_1);
                break;
            case EGG_GROUP_BUG:
                StringCopy(gStringVar2, sText_Stats_eggGroup_BUG);
                break;
            case EGG_GROUP_FLYING:
                StringCopy(gStringVar2, sText_Stats_eggGroup_FLYING);
                break;
            case EGG_GROUP_FIELD:
                StringCopy(gStringVar2, sText_Stats_eggGroup_FIELD);
                break;
            case EGG_GROUP_FAIRY:
                StringCopy(gStringVar2, sText_Stats_eggGroup_FAIRY);
                break;
            case EGG_GROUP_GRASS:
                StringCopy(gStringVar2, sText_Stats_eggGroup_GRASS);
                break;
            case EGG_GROUP_HUMAN_LIKE:
                StringCopy(gStringVar2, sText_Stats_eggGroup_HUMAN_LIKE);
                break;
            case EGG_GROUP_WATER_3:
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_3);
                break;
            case EGG_GROUP_MINERAL:
                StringCopy(gStringVar2, sText_Stats_eggGroup_MINERAL);
                break;
            case EGG_GROUP_AMORPHOUS:
                StringCopy(gStringVar2, sText_Stats_eggGroup_AMORPHOUS);
                break;
            case EGG_GROUP_WATER_2:
                StringCopy(gStringVar2, sText_Stats_eggGroup_WATER_2);
                break;
            case EGG_GROUP_DITTO:
                StringCopy(gStringVar2, sText_Stats_eggGroup_DITTO);
                break;
            case EGG_GROUP_DRAGON:
                StringCopy(gStringVar2, sText_Stats_eggGroup_DRAGON);
                break;
            case EGG_GROUP_NO_EGGS_DISCOVERED:
                StringCopy(gStringVar2, sText_Stats_eggGroup_NO_EGGS_DISCOVERED);
                break;
            default:
                StringCopy(gStringVar2, sText_Stats_eggGroup_UNKNOWN);
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
    enum Ability ability0;
    enum Ability ability1;
    enum Ability abilityHidden;

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
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite

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
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite

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
    enum Species species;
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
            enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            sPokedexView->selectedScreen = EVO_SCREEN;
            ResetEvoScreenDataStruct();
            //Icon
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            PrintPreEvolutions(taskId, species);
            gTasks[taskId].data[4] = CreateMonIcon(species, SpriteCB_MonIcon, 18 + 32*sPokedexView->numPreEvolutions, 31, 4, personality); //Create Pokémon sprite
            EvoFormsPage_PrintNavigationButtons(); // Navigation buttons
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        gMain.state++;
        break;
    case 4:
    {
        u32 alreadyPrintedIcons[MAX_EVOLUTION_ICONS] = {0};
        u32 depth = sPokedexView->numPreEvolutions;
        u32 iconDepth = depth;
        //Print evo info and icons
        gTasks[taskId].data[3] = 0;
        PrintEvolutionTargetSpeciesAndMethod(taskId, NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum), 0, &depth, alreadyPrintedIcons, &iconDepth, 0);
        LoadSpritePalette(&gSpritePalette_Arrow);
        TryLoadDarkModeArrowPalette();
        GetSeenFlagTargetSpecies();
        if (sPokedexView->sEvoScreenData.numAllEvolutions > 0 && sPokedexView->sEvoScreenData.numSeen > 0)
        {
            u32 pos;
            for (pos = 0; !sPokedexView->sEvoScreenData.seen[pos]; pos++)
                ;
            sPokedexView->sEvoScreenData.menuPos = pos;
            sPokedexView->sEvoScreenData.arrowSpriteId = CreateSprite(&gSpriteTemplate_Arrow, 7, 58 + 9 * pos, 0);
            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].animNum = 2;
        }
        gMain.state++;
        break;
    }
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
        break;
    }
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

    if (sPokedexView->sEvoScreenData.numAllEvolutions > 0 && sPokedexView->sEvoScreenData.numSeen > 0)
    {
        u8 base_y = 58;
        u8 base_y_offset = 9;
        u8 pos = sPokedexView->sEvoScreenData.menuPos;
        u8 max = sPokedexView->sEvoScreenData.numAllEvolutions - 1;
        if (JOY_NEW(DPAD_DOWN))
        {
            do
            {
                if (pos < max)
                    pos++;
                else
                    pos = 0;
            } while (!sPokedexView->sEvoScreenData.seen[pos]);
            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].y = sPokedexView->sEvoScreenData.arrowSpriteDist[pos] + base_y + base_y_offset * pos;
            sPokedexView->sEvoScreenData.menuPos = pos;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            do
            {
                if (pos > 0)
                    pos--;
                else
                    pos = max;
            } while (!sPokedexView->sEvoScreenData.seen[pos]);

            gSprites[sPokedexView->sEvoScreenData.arrowSpriteId].y = sPokedexView->sEvoScreenData.arrowSpriteDist[pos] + base_y + base_y_offset * pos;
            sPokedexView->sEvoScreenData.menuPos = pos;
        }

        if (JOY_NEW(A_BUTTON))
        {
            enum Species targetSpecies   = sPokedexView->sEvoScreenData.targetSpecies[sPokedexView->sEvoScreenData.menuPos];
            enum NationalDexOrder dexNum = SpeciesToNationalPokedexNum(targetSpecies);
            if (sPokedexView->isSearchResults && sPokedexView->originalSearchSelectionNum == 0)
                sPokedexView->originalSearchSelectionNum = sPokedexListItem->dexNum;

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

static void HandleTargetSpeciesPrintText(enum Species targetSpecies, u32 base_x, u32 base_y, u32 base_y_offset, u32 base_i, u32 numLines)
{
    bool32 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_SEEN);
    u32 fontId = GetSpeciesNameFontId(GetSpeciesNameWidthInChars(GetSpeciesName(targetSpecies)));

    if (seen || !HGSS_HIDE_UNSEEN_EVOLUTION_NAMES)
        StringCopy(gStringVar3, GetSpeciesName(targetSpecies)); //evolution mon name
    else
        StringCopy(gStringVar3, gText_ThreeQuestionMarks); //show questionmarks instead of name
    StringExpandPlaceholders(gStringVar3, sText_EVO_Name); //evolution mon name
    PrintInfoScreenTextSmall(gStringVar3, fontId, base_x, base_y + base_y_offset * base_i + numLines); //evolution mon name
}

static void HandleTargetSpeciesPrintIcon(u8 taskId, enum Species targetSpecies, u8 base_i, u8 iterations)
{
    u32 personality = GetPokedexMonPersonality(targetSpecies);
    LoadMonIconPalettePersonality(targetSpecies, personality); //Loads pallete for current mon
    if (iterations > 6) // Print icons closer to each other if there are many evolutions
        gTasks[taskId].data[4+base_i] = CreateMonIcon(targetSpecies, SpriteCB_MonIcon, 45 + 26*base_i, 31, 4, personality);
    else
        gTasks[taskId].data[4+base_i] = CreateMonIcon(targetSpecies, SpriteCB_MonIcon, 50 + 32*base_i, 31, 4, personality);
    gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
}

static void CreateCaughtBallEvolutionScreen(enum Species targetSpecies, u8 x, u8 y, u16 unused)
{
    bool32 owned = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_CAUGHT);
    if (owned)
        BlitBitmapToWindow(0, sCaughtBall_Gfx, x, y-1, 8, 16);
    else
    {
        //FillWindowPixelRect(0, PIXEL_FILL(0), x, y, 8, 16); //not sure why this was even here
        PrintInfoScreenTextSmall(gText_OneDash, FONT_SMALL, x+1, y-1);
    }
}

static void HandlePreEvolutionSpeciesPrint(u8 taskId, enum Species preSpecies, enum Species species, u8 base_x, u8 base_y, u8 base_y_offset, u8 base_i)
{
    bool32 seen = GetSetPokedexFlag(SpeciesToNationalPokedexNum(preSpecies), FLAG_GET_SEEN);

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

    PrintInfoScreenTextSmall(gStringVar3, FONT_SMALL, base_x, base_y + base_y_offset*base_i); //evolution mon name

    if (base_i < 3)
    {
        u32 personality = GetPokedexMonPersonality(preSpecies);
        LoadMonIconPalettePersonality(preSpecies, personality); //Loads pallete for current mon
        gTasks[taskId].data[4+base_i] = CreateMonIcon(preSpecies, SpriteCB_MonIcon, 18 + 32*base_i, 31, 4, personality); //Create Pokémon sprite
        gSprites[gTasks[taskId].data[4+base_i]].oam.priority = 0;
    }
}

static bool32 HasTwoPreEvolutions(enum Species species)
{
    switch (species)
    {
    case SPECIES_GHOLDENGO:
        return TRUE;
    default:
        return FALSE;
    }
}

static u8 PrintPreEvolutions(u8 taskId, enum Species species)
{
    u16 i;
    u16 j;

    u8 base_x = 13+8;
    u8 base_y = 51;
    u8 base_y_offset = 9;

    u16 preEvolutionOne = 0;
    u16 preEvolutionTwo = 0;
    u8 numPreEvolutions = 0;

    enum Species baseFormSpecies;
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
        if (!IsSpeciesEnabled(i))
            continue;

        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;

        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (evolutions[j].targetSpecies == species)
            {
                if (numPreEvolutions == 0)
                {
                    preEvolutionOne = i;
                    numPreEvolutions += 1;
                    if (!HasTwoPreEvolutions(species))
                        break;
                }
                else
                {
                    preEvolutionTwo = i;
                    numPreEvolutions += 1;
                    break;
                }
            }
        }
    }

    if (HasTwoPreEvolutions(species))
    {
        CreateCaughtBallEvolutionScreen(preEvolutionOne, base_x - 9, base_y + base_y_offset*0, 0);
        HandlePreEvolutionSpeciesPrint(taskId, preEvolutionOne, species, base_x, base_y, base_y_offset, 0);

        CreateCaughtBallEvolutionScreen(preEvolutionTwo, base_x - 9, base_y + base_y_offset*(numPreEvolutions - 1), 0);
        HandlePreEvolutionSpeciesPrint(taskId, preEvolutionTwo, species, base_x, base_y, base_y_offset, numPreEvolutions - 1);

        sPokedexView->sEvoScreenData.targetSpecies[0] = preEvolutionOne;
        sPokedexView->sEvoScreenData.targetSpecies[1] = preEvolutionTwo;

        sPokedexView->numPreEvolutions = numPreEvolutions;
        sPokedexView->sEvoScreenData.numAllEvolutions += numPreEvolutions;
        return numPreEvolutions;
    }

    //Calculate if previous evolution also has a previous evolution
    if (numPreEvolutions != 0)
    {
        for (i = 0; i < NUM_SPECIES; i++)
        {
            if (!IsSpeciesEnabled(i))
                continue;

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

static u32 GetSpeciesNameFontId(u32 nameWidth)
{
    if (nameWidth <= 8)
        return FONT_SMALL;
    else if (nameWidth > 7 && nameWidth < 11)
        return FONT_SMALL;//_NARROW;
    else
        return FONT_SMALL;//_NARROWER;
}

static u32 GetSpeciesNameWidthInChars(const u8 *speciesName)
{
    u32 i = 0;

    while (speciesName[i] != EOS) i++;

    return i;
}

static bool32 IsSpeciesAlcremie(enum Species targetSpecies)
{
    return GET_BASE_SPECIES_ID(targetSpecies) == SPECIES_ALCREMIE;
}

static bool32 IsItemSweet(enum Item item)
{
    return item >= ITEM_STRAWBERRY_SWEET && item <= ITEM_RIBBON_SWEET;
}

static void PrintEvolutionTargetSpeciesAndMethod(u8 taskId, enum Species species, u8 depth, u32 *depth_i, u32 alreadyPrintedIcons[], u32 *icon_depth_i, u32 numLines)
{
    int i;
    u32 depth_x = 4;
    u32 depth_offset = 8 * (depth + 1);
    int fontId;
    enum Species targetSpecies = 0;
    bool8 left = TRUE;
    u32 base_x = 21;
    u32 base_y = 51;
    u32 base_y_offset = 9;
    u32 times = 0;
    u32 arg; // shorthand for some of the more mathy evolutions
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (sPokedexView->sEvoScreenData.isMega)
        return;

    StringCopy(gStringVar1, GetSpeciesName(species));

    sPokedexView->sEvoScreenData.arrowSpriteDist[*depth_i] = numLines;

    //If there are no evolutions print text and return
    if (evolutions == NULL)
    {
        if (depth == 0)
        {
            StringExpandPlaceholders(gStringVar4, sText_EVO_NONE);
            PrintInfoScreenTextSmall(gStringVar4, FONT_SMALL, base_x-7-7, base_y + base_y_offset*(*depth_i) + numLines);
        }
        return;
    }

    //Calculate number of possible direct evolutions (e.g. Eevee has 5 but torchic has 1)
    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        times += 1;

    if (times > 9 && species == SPECIES_MILCERY)
        times = 9;
    else if (times > 10)
        times = 10;

    gTasks[taskId].data[3] = times;
    sPokedexView->sEvoScreenData.numAllEvolutions += times;

    //If there are evolutions find out which and print them 1 by 1
    for (i = 0; i < times; i++)
    {
        targetSpecies = evolutions[i].targetSpecies;
        if (!IsSpeciesEnabled(targetSpecies))
            continue;

        left = !left;

        bool32 isAlcremie = IsSpeciesAlcremie(targetSpecies);

        u32 speciesNameWidthInChars = GetSpeciesNameWidthInChars(GetSpeciesName(targetSpecies));
        u32 speciesNameCharWidth = GetFontAttribute(GetSpeciesNameFontId(speciesNameWidthInChars), FONTATTR_MAX_LETTER_WIDTH);

        u32 speciesNameWidth = (speciesNameWidthInChars * speciesNameCharWidth);
        u32 base_x_offset = speciesNameWidth + base_x + depth_offset; // for evo method info
        u32 maxScreenWidth = 230 - base_x_offset;

        sPokedexView->sEvoScreenData.targetSpecies[*depth_i] = targetSpecies;
        CreateCaughtBallEvolutionScreen(targetSpecies, base_x + depth_x*depth-9, base_y + base_y_offset*(*depth_i) + numLines, 0);
        HandleTargetSpeciesPrintText(targetSpecies, base_x + depth_x*depth, base_y, base_y_offset, *depth_i, numLines); //evolution mon name

        for (u32 j = 0; j < MAX_EVOLUTION_ICONS; j++)
        {
            if (alreadyPrintedIcons[j] == targetSpecies)
                break;
            if (alreadyPrintedIcons[j] == SPECIES_NONE)
            {
                HandleTargetSpeciesPrintIcon(taskId, targetSpecies, *icon_depth_i, times);
                alreadyPrintedIcons[j] = targetSpecies;
                (*icon_depth_i)++;
                break;
            }
        }

        bool32 caught = GetSetPokedexFlag(SpeciesToNationalPokedexNum(targetSpecies), FLAG_GET_CAUGHT);
        if (HGSS_HIDE_UNOWNED_EVOLUTION_METHODS == TRUE && !caught)
        {
            StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("Unknown"));
        }
        else
        {
            switch ((enum EvolutionMethods)evolutions[i].method)
            {
            case EVO_SCRIPT_TRIGGER:
            case EVO_NONE:
                StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("Unknown"));
                break;
            case EVO_LEVEL:
            case EVO_LEVEL_BATTLE_ONLY:
                StringCopy(gStringVar4, COMPOUND_STRING("{LV}{UP_ARROW}"));
                if (evolutions[i].param > 1)
                {
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].param, STR_CONV_MODE_LEFT_ALIGN, EVO_SCREEN_LVL_DIGITS); //level
                    StringAppend(gStringVar4, gStringVar2);
                }
                if ((enum EvolutionMethods)evolutions[i].method == EVO_LEVEL_BATTLE_ONLY)
                    StringAppend(gStringVar4, COMPOUND_STRING(", in battle"));
                break;
            case EVO_TRADE:
                StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("Trading"));
                break;
            case EVO_ITEM:
                CopyItemName(evolutions[i].param, gStringVar2);
                StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("{STR_VAR_2} is used"));
                break;
            case EVO_SPLIT_FROM_EVO:
                StringCopy(gStringVar4, COMPOUND_STRING("Splits from "));
                StringAppend(gStringVar4, GetSpeciesName(evolutions[i].param)); //mon name
                break;
            case EVO_BATTLE_END:
                StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("End battle"));
                break;
            case EVO_SPIN:
                StringCopy(gStringVar4, COMPOUND_STRING("Spin "));
                if (evolutions[i].param == SPIN_CW_SHORT)
                    StringAppend(gStringVar4, COMPOUND_STRING("CW <5s"));
                else if (evolutions[i].param == SPIN_CW_LONG)
                    StringAppend(gStringVar4, COMPOUND_STRING("CW >5s"));
                else if (evolutions[i].param == SPIN_CCW_SHORT)
                    StringAppend(gStringVar4, COMPOUND_STRING("CCW <5s"));
                else if (evolutions[i].param == SPIN_CCW_LONG)
                    StringAppend(gStringVar4, COMPOUND_STRING("CCW >5s"));
                else
                    StringAppend(gStringVar4, COMPOUND_STRING("CW/CCW >10s"));
                break;
            }//Switch end

            // Check for additional conditions. Skips if there's no additional conditions.
            for (u32 j = 0; evolutions[i].params != NULL && evolutions[i].params[j].condition != CONDITIONS_END; j++)
            {
                if (j == 0)
                {
                    StringAppend(gStringVar4, COMPOUND_STRING(", "));
                }

                enum EvolutionConditions condition = evolutions[i].params[j].condition;
                switch (condition)
                {
                // Gen 2
                case IF_GENDER:
                    switch (evolutions[i].params[j].arg1)
                    {
                    case MON_MALE:   StringAppend(gStringVar4, COMPOUND_STRING("Male"));   break;
                    case MON_FEMALE: StringAppend(gStringVar4, COMPOUND_STRING("Female")); break;
                    }
                    break;
                case IF_MIN_FRIENDSHIP:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}friendship"));
                    break;
                case IF_ATK_GT_DEF:
                    StringAppend(gStringVar4, COMPOUND_STRING("Atk > Def"));
                    break;
                case IF_ATK_EQ_DEF:
                    StringAppend(gStringVar4, COMPOUND_STRING("Atk = Def"));
                    break;
                case IF_ATK_LT_DEF:
                    StringAppend(gStringVar4, COMPOUND_STRING("Atk < Def"));
                    break;
                case IF_TIME:
                    switch (evolutions[i].params[j].arg1)
                    {
                    case TIME_MORNING: StringAppend(gStringVar4, COMPOUND_STRING("Morning")); break;
                    case TIME_DAY:     StringAppend(gStringVar4, COMPOUND_STRING("Day"));     break;
                    case TIME_EVENING: StringAppend(gStringVar4, COMPOUND_STRING("Evening")); break;
                    case TIME_NIGHT:   StringAppend(gStringVar4, COMPOUND_STRING("Night"));   break;
                    }
                    break;
                case IF_NOT_TIME:
                    switch (evolutions[i].params[j].arg1)
                    {
                    case TIME_MORNING: StringAppend(gStringVar4, COMPOUND_STRING("NOT Morning")); break;
                    case TIME_DAY:     StringAppend(gStringVar4, COMPOUND_STRING("NOT Day"));     break;
                    case TIME_EVENING: StringAppend(gStringVar4, COMPOUND_STRING("NOT Evening")); break;
                    case TIME_NIGHT:   StringAppend(gStringVar4, COMPOUND_STRING("Day"));         break; // More intuitive than "NOT Night"
                    }
                    break;
                case IF_HOLD_ITEM:
                    StringAppend(gStringVar4, COMPOUND_STRING("holds "));
                    if (isAlcremie && IsItemSweet(evolutions[i].params[j].arg1))
                    {
                        StringAppend(gStringVar4, COMPOUND_STRING("Sweet")); //item
                    }
                    else
                    {
                        CopyItemName(evolutions[i].params[j].arg1, gStringVar2); //item
                        StringAppend(gStringVar4, gStringVar2);
                    }
                    break;
                // Gen 3
                case IF_PID_UPPER_MODULO_10_GT:
                case IF_PID_UPPER_MODULO_10_EQ:
                case IF_PID_UPPER_MODULO_10_LT:
                    arg = evolutions[i].params[j].arg1;
                        if (condition == IF_PID_UPPER_MODULO_10_GT
                            && arg < 10 && arg >= 0)
                            arg = 9 - arg;
                        else if (condition == IF_PID_UPPER_MODULO_10_EQ
                             && arg < 10 && arg >= 0)
                            arg = 1;
                    ConvertIntToDecimalStringN(gStringVar2, arg * 10, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, COMPOUND_STRING("random %"));
                    StringAppend(gStringVar4, gStringVar2);
                    break;
                case IF_MIN_BEAUTY:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}beauty"));
                    break;
                case IF_MIN_COOLNESS:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}coolness"));
                    break;
                case IF_MIN_SMARTNESS:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}smartness"));
                    break;
                case IF_MIN_TOUGHNESS:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}toughness"));
                    break;
                case IF_MIN_CUTENESS:
                    StringAppend(gStringVar4, COMPOUND_STRING("{UP_ARROW_2}cuteness"));
                    break;
                // Gen 4
                case IF_SPECIES_IN_PARTY:
                    StringAppend(gStringVar4, GetSpeciesName(evolutions[i].params[j].arg1)); //mon name
                    StringAppend(gStringVar4, COMPOUND_STRING(" in party"));
                    break;
                case IF_IN_MAPSEC:
                    StringAppend(gStringVar4, COMPOUND_STRING("in "));
                    StringCopy(gStringVar2, gRegionMapEntries[evolutions[i].params[j].arg1].name);
                    StringAppend(gStringVar4, gStringVar2);
                    break;
                case IF_IN_MAP:
                    StringAppend(gStringVar4, COMPOUND_STRING("in "));
                    GetMapName(gStringVar2, Overworld_GetMapHeaderByGroupAndId(evolutions[i].params[j].arg1 >> 8, evolutions[i].params[j].arg1 & 0xFF)->regionMapSectionId, 0);
                    StringAppend(gStringVar4, gStringVar2);
                    break;
                case IF_KNOWS_MOVE:
                    StringAppend(gStringVar4, COMPOUND_STRING("knows "));
                    StringAppend(gStringVar4, GetMoveName(evolutions[i].params[j].arg1));
                    break;
                // Gen 5
                case IF_TRADE_PARTNER_SPECIES:
                    StringAppend(gStringVar4, COMPOUND_STRING("traded with "));
                    StringAppend(gStringVar4, GetSpeciesName(evolutions[i].params[j].arg1));
                    break;
                // Gen 6
                case IF_TYPE_IN_PARTY:
                    StringAppend(gStringVar4, gTypesInfo[evolutions[i].params[j].arg1].name); //type name
                    StringAppend(gStringVar4, COMPOUND_STRING("-type in party"));
                    break;
                case IF_WEATHER:
                    StringAppend(gStringVar4, COMPOUND_STRING("weather "));
                    StringAppend(gStringVar4, GetWeatherName(evolutions[i].params[j].arg1));
                    break;
                case IF_KNOWS_MOVE_TYPE:
                    StringAppend(gStringVar4, gTypesInfo[evolutions[i].params[j].arg1].name);
                    StringAppend(gStringVar4, COMPOUND_STRING(" move"));
                    break;
                case IF_REGION:
                case IF_NOT_REGION:
                {
                    if (condition == IF_REGION)
                        StringAppend(gStringVar4, COMPOUND_STRING("in "));
                    else if (condition == IF_NOT_REGION)
                        StringAppend(gStringVar4, COMPOUND_STRING("out of "));

                    switch ((enum Region)evolutions[i].params[j].arg1)
                    {
                    case REGION_NONE:
                    case REGIONS_COUNT:
                        StringAppend(gStringVar4, COMPOUND_STRING("???"));
                        break;
                    case REGION_KANTO: StringAppend(gStringVar4, COMPOUND_STRING("Kanto")); break;
                    case REGION_JOHTO: StringAppend(gStringVar4, COMPOUND_STRING("Johto")); break;
                    case REGION_HOENN: StringAppend(gStringVar4, COMPOUND_STRING("Hoenn")); break;
                    case REGION_SINNOH: StringAppend(gStringVar4, COMPOUND_STRING("Sinnoh")); break;
                    case REGION_UNOVA: StringAppend(gStringVar4, COMPOUND_STRING("Unova")); break;
                    case REGION_KALOS: StringAppend(gStringVar4, COMPOUND_STRING("Kalos")); break;
                    case REGION_ALOLA: StringAppend(gStringVar4, COMPOUND_STRING("Alola")); break;
                    case REGION_GALAR: StringAppend(gStringVar4, COMPOUND_STRING("Galar")); break;
                    case REGION_HISUI: StringAppend(gStringVar4, COMPOUND_STRING("Hisui")); break;
                    case REGION_PALDEA: StringAppend(gStringVar4, COMPOUND_STRING("Paldea")); break;
                    }
                    break;
                }
                // Gen 8
                case IF_NATURE:
                    StringCopy(gStringVar2, gNaturesInfo[evolutions[i].params[j].arg1].name);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" nature"));
                    break;
                case IF_AMPED_NATURE:
                    StringAppend(gStringVar4, COMPOUND_STRING("amped natures"));
                    break;
                case IF_LOW_KEY_NATURE:
                    StringAppend(gStringVar4, COMPOUND_STRING("low-Key natures"));
                    break;
                case IF_RECOIL_DAMAGE_GE:
                    StringAppend(gStringVar4, COMPOUND_STRING("takes >= "));
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg1, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" recoil dmg"));
                    break;
                case IF_CURRENT_DAMAGE_GE:
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg1, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" current dmg"));
                    break;
                case IF_CRITICAL_HITS_GE:
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg1, STR_CONV_MODE_LEFT_ALIGN, 2);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" critical hits"));
                    break;
                case IF_USED_MOVE_X_TIMES:
                    StringAppend(gStringVar4, COMPOUND_STRING("use move "));
                    StringAppend(gStringVar4, GetMoveName(evolutions[i].params[j].arg1));
                    StringAppend(gStringVar4, COMPOUND_STRING(" "));
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg2, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" times"));
                    break;
                // Gen 9
                case IF_DEFEAT_X_WITH_ITEMS:
                    StringAppend(gStringVar4, COMPOUND_STRING("defeat "));
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg3, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" "));
                    StringAppend(gStringVar4, GetSpeciesName(evolutions[i].params[j].arg1));
                    StringAppend(gStringVar4, COMPOUND_STRING(" that hold "));
                    CopyItemName(evolutions[i].params[j].arg2, gStringVar2);
                    StringAppend(gStringVar4, gStringVar2);
                    break;
                case IF_PID_MODULO_100_GT:
                case IF_PID_MODULO_100_EQ:
                case IF_PID_MODULO_100_LT:
                    arg = evolutions[i].params[j].arg1;
                        if (condition == IF_PID_MODULO_100_GT
                            && arg < 100 && arg >= 0)
                            arg = 99 - arg;
                        else if (condition == IF_PID_MODULO_100_EQ
                                 && arg < 100 && arg >= 0)
                            arg = 1;
                    ConvertIntToDecimalStringN(gStringVar2, arg, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, COMPOUND_STRING("%"));
                    StringAppend(gStringVar4, gStringVar2);
                    break;
                case IF_MIN_OVERWORLD_STEPS:
                    StringAppend(gStringVar4, COMPOUND_STRING("after "));
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg1, STR_CONV_MODE_LEFT_ALIGN, 4);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" steps"));
                    break;
                case IF_BAG_ITEM_COUNT:
                    ConvertIntToDecimalStringN(gStringVar2, evolutions[i].params[j].arg2, STR_CONV_MODE_LEFT_ALIGN, 3);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" "));
                    CopyItemNameHandlePlural(evolutions[i].params[j].arg1, gStringVar2, evolutions[i].params[j].arg2);
                    StringAppend(gStringVar4, gStringVar2);
                    StringAppend(gStringVar4, COMPOUND_STRING(" in bag"));
                    break;
                case CONDITIONS_END:
                    break;
                }

                if (evolutions[i].params[j+1].condition != CONDITIONS_END)
                {
                    StringAppend(gStringVar4, COMPOUND_STRING(", "));
                }
            }
        }

        if (isAlcremie)
            fontId = FONT_SMALL_NARROWER;
        else
            fontId = GetFontIdToFit(gStringVar4, FONT_SMALL, 0, maxScreenWidth);

        u32 fontHeight = GetFontAttribute(fontId, FONTATTR_MAX_LETTER_HEIGHT);

        StringAppend(gStringVar4, COMPOUND_STRING("."));
        BreakStringAutomatic(gStringVar4, maxScreenWidth, MAX_EVO_METHOD_LINES, fontId, HIDE_SCROLL_PROMPT);

        PrintInfoScreenTextSmall(gStringVar4, fontId, base_x_offset, base_y + base_y_offset*(*depth_i) + numLines); //Print actual instructions
        (*depth_i)++;

        numLines = CountLineBreaks(gStringVar4) * fontHeight;

        sPokedexView->sEvoScreenData.arrowSpriteDist[*depth_i + 1] = numLines;

        PrintEvolutionTargetSpeciesAndMethod(taskId, targetSpecies, depth+1, depth_i, alreadyPrintedIcons, icon_depth_i, numLines);
    }//For loop end
}

static void Task_SwitchScreensFromEvolutionScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy Pokémon icon sprite
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
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy Pokémon icon sprite
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
            enum Species species = NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum);
            u32 personality = GetPokedexMonPersonality(species);
            FreeMonIconPalettes(); //Free space for new pallete
            LoadMonIconPalettePersonality(species, personality); //Loads pallete for current mon
            gTasks[taskId].data[4] = CreateMonIcon(species, SpriteCB_MonIcon, 18, 31, 4, personality); //Create Pokémon sprite
            gSprites[gTasks[taskId].data[4]].oam.priority = 0;
        }
        EvoFormsPage_PrintNavigationButtons(); // Navigation buttons
        sPokedexView->sFormScreenData.menuPos = 1;
        gMain.state++;
        break;
    case 4:
        //Print form icons
        gTasks[taskId].data[3] = 0;
        PrintForms(taskId, NationalPokedexNumToSpeciesForm(sPokedexListItem->dexNum));
        LoadSpritePalette(&gSpritePalette_Arrow);
        TryLoadDarkModeArrowPalette();
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
        break;
    }
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
            enum Species formSpecies = GetFormSpeciesId(NationalPokedexNumToSpecies(sPokedexListItem->dexNum), formId);
            if (sPokedexView->isSearchResults && sPokedexView->originalSearchSelectionNum == 0)
                sPokedexView->originalSearchSelectionNum = sPokedexListItem->dexNum;

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

static void PrintForms(u8 taskId, enum Species species)
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
                gTasks[taskId].data[4+times] = CreateMonIcon(speciesForm, SpriteCB_MonIcon, 52 + 34*(times-1), 31, 4, personality); //Create Pokémon sprite
            else if (times < 14)
                gTasks[taskId].data[4+times] = CreateMonIcon(speciesForm, SpriteCB_MonIcon, 18 + 34*(times-7), 70 - y_offset_icons, 4, personality); //Create Pokémon sprite
            gSprites[gTasks[taskId].data[4+times]].oam.priority = 0;
        }
    }
    gTasks[taskId].data[3] = times;
    sPokedexView->sFormScreenData.numForms = times;

    //If there are no forms print text
    if (times == 0)
    {
        StringExpandPlaceholders(gStringVar4, sText_FORMS_NONE);
        PrintInfoScreenTextSmall(gStringVar4, FONT_SMALL, base_x, base_y + base_y_offset*times);
    }
}

static void Task_SwitchScreensFromFormsScreen(u8 taskId)
{
    u8 i;
    if (!gPaletteFade.active)
    {
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy Pokémon icon sprite
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
        FreeMonIconPalettes();                                          //Destroy Pokémon icon sprite
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4]]); //Destroy Pokémon icon sprite
        for (i = 1; i <= gTasks[taskId].data[3]; i++)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].data[4+i]]); //Destroy Pokémon icon sprite
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

bool32 TryLoadCryScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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
        break;
    }
    case 7:
    {
            struct CryScreenWindow cryMeter;

            cryMeter.paletteNo = 9;
            cryMeter.xPos = 18;
            cryMeter.yPos = 3;
            if (LoadCryMeter(&cryMeter, 3))
                gMain.state++;
            FillCryMeterWindowTilemapWithBg();
            CopyWindowToVram(WIN_VU_METER, COPYWIN_GFX);
            CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
        break;
    }
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

    return TRUE;
}

bool32 TrySwitchScreensFromCryScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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

    return TRUE;
}


//************************************
//*                                  *
//*        Size screen               *
//*                                  *
//************************************
bool32 TryLoadSizeScreen_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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
        break;
    }
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
        LoadSpriteSilhouettePalette(spriteId);
        gTasks[taskId].tTrainerSpriteId = spriteId;
        gMain.state++;
        break;
    case 6:
        spriteId = CreateMonSpriteFromNationalDexNumber(sPokedexListItem->dexNum, 88, 56, 1);
        gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteId].oam.matrixNum = 2;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].y2 = GetPokemonOffsetFromNationalDexNumber(sPokedexListItem->dexNum);
        SetOamMatrix(2, GetPokemonScaleFromNationalDexNumber(sPokedexListItem->dexNum), 0, 0, GetPokemonScaleFromNationalDexNumber(sPokedexListItem->dexNum));
        LoadSpriteSilhouettePalette(spriteId);
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

    return TRUE;
}

bool32 TryLoadPlayArrowPalette_HGSS(bool8 cryPlaying)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    u16 color;

    if (!HGSS_DARK_MODE)
    {
        if (cryPlaying)
            color = RGB(29, 9, 4);
        else
            color = RGB(18, 2, 4);
    }
    else
    {
        if (cryPlaying)
            color = RGB(9, 9, 9);
        else
            color = RGB(3, 3, 3);
    }

    LoadPalette(&color, BG_PLTT_ID(0) + 11, PLTT_SIZEOF(1));
    return TRUE;
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

#undef tLoadScreenTaskId


//************************************
//*                                  *
//*        Search code               *
//*                                  *
//************************************
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

bool32 TryLoadSearchMenu_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

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
        LoadSpritePalette(&sInterfaceSpritePalette[HGSS_DARK_MODE]);
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

    return TRUE;
}

#undef sIsDownArrow

void HandleDestroyStatBars_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return;

    TryDestroyStatBars();
}

void HandleDestroyStatBarsBg_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return;

    TryDestroyStatBarsBg();
}

void HandleCreateStatBars_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return;

    if (sPokedexView->menuIsOpen == FALSE && sPokedexView->menuY == 8)
    {
        CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
        CreateStatBarsBg();
    }
}

void HandleCreateStatBarsDPAD_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return;

    if (!sPokedexView->scrollTimer && !sPokedexView->scrollSpeed &&sPokedexView->justScrolled)
        CreateStatBars(&sPokedexView->pokedexList[sPokedexView->selectedPokemon]);
}

void HandleCaughtMonPageTypeIcons_HGSS(void)
{
    if (!POKEDEX_PLUS_HGSS)
        return;

    SetSpriteInvisibility(0, TRUE);
    SetSpriteInvisibility(1, TRUE);
}

bool32 TryHandleCaughtMonPageFlicker_HGSS(u8 taskId)
{
    if (!POKEDEX_PLUS_HGSS)
        return FALSE;

    // Implementation of HGSS screen flickering like vanilla did not
    // work. However, it is preserved in case it is to be implemented.

    // if (++gTasks[taskId].tPalTimer & 16)
    // {
    //     if (!HGSS_DARK_MODE)
    //         LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
    //     else
    //         LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
    // }
    // else
    // {
    //     if (!HGSS_DARK_MODE)
    //         LoadPalette(sPokedexPlusHGSS_Default_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
    //     else
    //         LoadPalette(sPokedexPlusHGSS_Default_dark_Pal + 1, BG_PLTT_ID(3) + 1, PLTT_SIZEOF(7));
    // }

    return TRUE;
}

static void TryLoadDarkModeArrowPalette(void)
{
    if (!HGSS_DARK_MODE)
        return;

    u32 index = IndexOfSpritePaletteTag(gSpritePalette_Arrow.tag);
    u32 colorArrow = RGB2GBA(72, 72, 72);
    u32 colorOutline = RGB2GBA(24, 24, 24);

    LoadPalette(&colorArrow, OBJ_PLTT_ID(index) + 1, sizeof(colorArrow));
    LoadPalette(&colorOutline, OBJ_PLTT_ID(index) + 2, sizeof(colorOutline));
}

static void FillCryMeterWindowTilemapWithBg(void)
{
    // This fills the window behind the 'VU' text on the cry meter.
    // It is filled with blank tiles, showing as black.

    struct Window windowLocal = gWindows[WIN_VU_METER];

    FillBgTilemapBufferRect(
        3,
        0,
        windowLocal.window.tilemapLeft,
        windowLocal.window.tilemapTop,
        windowLocal.window.width,
        windowLocal.window.height,
        windowLocal.window.paletteNum);
}
