#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "bw_summary_screen.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if BW_SUMMARY_SCREEN == TRUE
enum BWPSSPage
{
    PSS_PAGE_INFO,
    PSS_PAGE_SKILLS,
    PSS_PAGE_BATTLE_MOVES,
    PSS_PAGE_CONTEST_MOVES,
    PSS_PAGE_COUNT,
    PSS_BUFFER_BATTLE_EFFECTS = PSS_PAGE_COUNT,
    PSS_BUFFER_CONTEST_EFFECTS,
    PSS_BUFFER_COUNT
};

enum BWSkillsPageState
{
    SKILL_STATE_STATS,
    SKILL_STATE_IVS,
    SKILL_STATE_EVS,
};

// Screen titles (upper left)
#define PSS_LABEL_WINDOW_POKEMON_INFO_TITLE 0
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE 1
#define PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE 2
#define PSS_LABEL_WINDOW_CONTEST_MOVES_TITLE 3

// Button control text (upper right)
#define PSS_LABEL_WINDOW_PROMPT_CANCEL 4
#define PSS_LABEL_WINDOW_PROMPT_INFO 5
#define PSS_LABEL_WINDOW_PROMPT_SWITCH 6

// Info screen
#define PSS_LABEL_WINDOW_POKEMON_INFO_TYPE 7

// Skills screen
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP 8 // EXP Next Level

// Moves screen
#define PSS_LABEL_WINDOW_MOVES_POWER_ACC 9 // Also contains the power and accuracy values

// Above/below the pokemon's portrait (right)
#define PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL 10

// additional button prompts for IVs and EVs
#define PSS_LABEL_WINDOW_PROMPT_IVS 11
#define PSS_LABEL_WINDOW_PROMPT_EVS 12
#define PSS_LABEL_WINDOW_PROMPT_STATS 13

#define PSS_LABEL_WINDOW_END 14

// Dynamic fields for the Pokémon Info page
#define PSS_DATA_WINDOW_INFO_OT_OTID_ITEM 0
#define PSS_DATA_WINDOW_INFO_MEMO 1
#define PSS_DATA_WINDOW_INFO_DEX_NUMBER_NAME 2

// Dynamic fields for the Pokémon Skills page
#define PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT 0 //ravetodo handle ribbons
#define PSS_DATA_WINDOW_SKILLS_STATS_HP 1
#define PSS_DATA_WINDOW_SKILLS_STATS_NON_HP 2 //  Attack, Defense, Sp. Attack, Sp. Defense, Speed
#define PSS_DATA_WINDOW_EXP 3 // Exp
#define PSS_DATA_WINDOW_EXP_NEXT_LEVEL 4 // Exp next level
#define PSS_DATA_WINDOW_SKILLS_ABILITY 5

// Dynamic fields for the Battle Moves and Contest Moves pages.
#define PSS_DATA_WINDOW_MOVE_NAMES_PP 0
#define PSS_DATA_WINDOW_MOVE_DESCRIPTION 1

#define MOVE_SELECTOR_SPRITES_COUNT 15
#define TYPE_ICON_SPRITE_COUNT (MAX_MON_MOVES + 1)
// for the spriteIds field in PokemonSummaryScreenData
enum BWSummarySprites
{
    SPRITE_ARR_ID_MON,
    SPRITE_ARR_ID_BALL,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_SHINY,
    SPRITE_ARR_ID_POKERUS_CURED,
    SPRITE_ARR_ID_FRIENDSHIP,
    SPRITE_ARR_ID_CATEGORY,
    SPRITE_ARR_ID_HP_GRADE,
    SPRITE_ARR_ID_ATK_GRADE,
    SPRITE_ARR_ID_DEF_GRADE,
    SPRITE_ARR_ID_SPA_GRADE,
    SPRITE_ARR_ID_SPD_GRADE,
    SPRITE_ARR_ID_SPE_GRADE,
    SPRITE_ARR_ID_TERA_TYPE,
    SPRITE_ARR_ID_TYPE, // 2 for mon types, 5 for move types(4 moves and 1 to learn), used interchangeably, because mon types and move types aren't shown on the same screen
    SPRITE_ARR_ID_MOVE_SELECTOR1 = SPRITE_ARR_ID_TYPE + TYPE_ICON_SPRITE_COUNT, // 10 sprites that make up the selector
    SPRITE_ARR_ID_MOVE_SELECTOR2 = SPRITE_ARR_ID_MOVE_SELECTOR1 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_COUNT = SPRITE_ARR_ID_MOVE_SELECTOR2 + MOVE_SELECTOR_SPRITES_COUNT
};

static EWRAM_DATA struct PokemonSummaryScreenData
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species; // 0x0
        u16 species2; // 0x2
        u8 isEgg:1; // 0x4
        u8 isShiny:1;
        u8 padding:6;
        u8 level; // 0x5
        u8 ribbonCount; // 0x6
        u8 ailment; // 0x7
        u8 abilityNum; // 0x8
        u8 metLocation; // 0x9
        u8 metLevel; // 0xA
        u8 metGame; // 0xB
        u32 pid; // 0xC
        u32 exp; // 0x10
        u16 moves[MAX_MON_MOVES]; // 0x14
        u8 pp[MAX_MON_MOVES]; // 0x1C
        u16 currentHP; // 0x20
        u16 maxHP; // 0x22
        u16 atk; // 0x24
        u16 def; // 0x26
        u16 spatk; // 0x28
        u16 spdef; // 0x2A
        u16 speed; // 0x2C
        u16 item; // 0x2E
        u16 friendship; // 0x30
        u8 OTGender; // 0x32
        u8 nature; // 0x33
        u8 ppBonuses; // 0x34
        u8 sanity; // 0x35
        u8 OTName[17]; // 0x36
        u32 OTID; // 0x48  
        u8 teraType;
        u8 mintNature;
        u8 ivHp;
        u8 ivAtk;
        u8 ivDef;
        u8 ivSpatk;
        u8 ivSpdef;
        u8 ivSpeed;
        u8 evHp;
        u8 evAtk;
        u8 evDef;
        u8 evSpatk;
        u8 evSpdef;
        u8 evSpeed; // 0x56
    } summary;
    u16 bgTilemapBuffers[PSS_BUFFER_COUNT][2][0x400];
    u8 mode;
    bool8 isBoxMon;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    bool8 lockMonFlag; // This is used to prevent the player from changing Pokémon in the move deleter select, etc, but it is not needed because the input is handled differently there
    u16 newMove;
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    bool8 lockMovesFlag; // This is used to prevent the player from changing position of moves in a battle or when trading.
    u8 bgDisplayOrder; // Determines the order page backgrounds are loaded while scrolling between them
    u8 filler40CA;
    u8 windowIds[8];
    u8 spriteIds[SPRITE_ARR_ID_COUNT];
    bool8 handleDeoxys;
    s16 switchCounter; // Used for various switch statement cases that decompress/load graphics or Pokémon data
    u8 unk_filler4[6];
} *sMonSummaryScreen = NULL;

static EWRAM_DATA u8 sMoveSlotToReplace = 0;
ALIGNED(4) static EWRAM_DATA u8 sAnimDelayTaskId = 0;
static EWRAM_DATA u8 sStringVar5[0x4] = {0};

// forward declarations
static bool8 LoadGraphics(void);
static void CB2_InitSummaryScreen(void);
static void InitBGs(void);
static bool8 DecompressGraphics(void);
static void CopyMonToSummaryStruct(struct Pokemon *);
static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *);
static void SetSelectMoveTilemaps(void);
static void CloseSummaryScreen(u8);
static void Task_HandleInput(u8);
static void ChangeSummaryPokemon(u8, s8);
static void Task_ChangeSummaryMon(u8);
static s8 AdvanceMonIndex(s8);
static s8 AdvanceMultiBattleMonIndex(s8);
static bool8 IsValidToViewInMulti(struct Pokemon *);
static void ChangePage(u8, s8);
static void PssScrollRight(u8);
static void PssScrollRightEnd(u8);
static void PssScrollLeft(u8);
static void PssScrollLeftEnd(u8);
static void TryDrawExperienceProgressBar(void);
static void TryDrawHPBar(void);
static void SwitchToMoveSelection(u8);
static void Task_HandleInput_MoveSelect(u8);
static bool8 HasMoreThanOneMove(void);
static void ChangeSelectedMove(s16 *, s8, u8 *);
static void CloseMoveSelectMode(u8);
static void SwitchToMovePositionSwitchMode(u8);
static void Task_HandleInput_MovePositionSwitch(u8);
static void ExitMovePositionSwitchMode(u8, bool8);
static void SwapMonMoves(struct Pokemon *, u8, u8);
static void SwapBoxMonMoves(struct BoxPokemon *, u8, u8);
static void Task_SetHandleReplaceMoveInput(u8);
static void Task_HandleReplaceMoveInput(u8);
static bool8 CanReplaceMove(void);
static void ShowCantForgetHMsWindow(u8);
static void Task_HandleInputCantForgetHMsMoves(u8);
static void HandleAppealJamTilemap(u16);
static void DrawExperienceProgressBar(struct Pokemon *);
static void DrawHPBar(struct Pokemon *);
static void OverrideHPBarPalette(void);
static void LimitEggSummaryPageDisplay(void);
static void ResetWindows(void);
static void PrintMonPortraitInfo(void);
static void PrintNotEggInfo(void);
static void PrintEggInfo(void);
static void PrintGenderSymbol(struct Pokemon *, u16);
static void PrintPageNamesAndStats(void);
static void PutPageWindowTilemaps(u8);
static void ClearPageWindowTilemaps(u8);
static void RemoveWindowByIndex(u8);
static void PrintPageSpecificText(u8);
static void CreateTextPrinterTask(u8);
static void PrintInfoPageText(void);
static void Task_PrintInfoPage(u8);
static void PrintMonOTName(void);
static void PrintMonOTID(void);
static void PrintMonDexNumberSpecies(void);
static void PrintMonAbilityName(void);
static void PrintMonAbilityDescription(void);
static void BufferMonTrainerMemo(void);
static void PrintMonTrainerMemo(void);
static void BufferNatureString(void);
static void GetMetLevelString(u8 *);
static bool8 DoesMonOTMatchOwner(void);
static bool8 DidMonComeFromGBAGames(void);
static bool8 IsInGamePartnerMon(void);
static void PrintEggOTName(void);
static void PrintEggOTID(void);
static void PrintEggState(void);
static void PrintEggMemo(void);
static void Task_PrintSkillsPage(u8);
static void PrintHeldItemName(void);
static void PrintSkillsPageText(void);
static void PrintRibbonCount(void);
static void BufferHPStats(void);
static void PrintHPStats(u8);
static void BufferNonHPStats(void);
static void PrintNonHPStats(void);
static void PrintExpPointsNextLevel(void);
static void PrintBattleMoves(void);
static void Task_PrintBattleMoves(u8);
static void PrintMoveNameAndPP(u8);
static void PrintContestMoves(void);
static void Task_PrintContestMoves(u8);
static void PrintContestMoveDescription(u8);
static void PrintMoveDetails(u16);
static void PrintNewMoveDetailsOrCancelText(void);
static void SwapMovesNamesPP(u8, u8);
static void PrintHMMovesCantBeForgotten(void);
static void ResetSpriteIds(void);
static void SetSpriteInvisibility(u8, bool8);
static void HidePageSpecificSprites(void);
static void SetTypeIcons(void);
static void CreateMoveTypeIcons(void);
static void SetMonTypeIcons(void);
static void SetMoveTypeIcons(void);
static void SetContestMoveTypeIcons(void);
static void SetNewMoveTypeIcon(void);
static void SwapMovesTypeSprites(u8, u8);
static u8 LoadMonGfxAndSprite(struct Pokemon *, s16 *);
static u8 CreateMonSprite(struct Pokemon *);
static void SpriteCB_Pokemon(struct Sprite *);
static void StopPokemonAnimations(void);
static void CreateMonMarkingsSprite(struct Pokemon *);
static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *);
static void CreateCaughtBallSprite(struct Pokemon *);
static void CreateSetStatusSprite(void);
static void CreateMoveSelectorSprites(u8);
static void SpriteCB_MoveSelector(struct Sprite *);
static void DestroyMoveSelectorSprites(u8);
static void SetMainMoveSelectorColor(u8);
static void KeepMoveSelectorVisible(u8);
static void SummaryScreen_DestroyAnimDelayTask(void);
static void CreateMonShinySprite(struct Pokemon *);
static void SetPokerusCuredSprite(void);
static void HandleMonShinyIcon(bool8);
static void HandleStatusSprite(struct Pokemon *);
static u8 AddWindowFromTemplateList(const struct WindowTemplate*, u8);
static void ClearCancelText(void);
static void FormatTextByWidth(u8*, s32, u8, const u8*, s16);
static void Task_ShowBattleMovesTilemap(u8);
static void Task_ShowContestMovesTilemap(u8);
static void Task_HideBattleMovesTilemap(u8);
static void Task_HideContestMovesTilemap(u8);
static void HideInactivePageDots(void);
static void RestoreSummaryPageDisplay(void);
static void ShowCategoryIcon(u16);
static void DestroyCategoryIcon(void);
static void ShowGradeIcons(u8);
static void DestroyGradeIcons(void);
static void ChangeSummaryState(s16*, u8);
static void DrawNextSkillsButtonPrompt(u8);
static void BufferAndPrintStats_HandleState(u8);
static void SetFriendshipSprite(void);
static void TrySetInfoPageIcons(void);

// const rom data

static const u8 sMemoNatureTextColor[]                      = _("{COLOR DYNAMIC_COLOR2}{SHADOW DYNAMIC_COLOR3}");
static const u8 sMemoMiscTextColor[]                        = _("{COLOR WHITE}{SHADOW DARK_GRAY}");
static const u8 sStatsHPLayout[]                            = _("{DYNAMIC 0}/{DYNAMIC 1}");
static const u8 sStatsHPIVEVLayout[]                        = _("{DYNAMIC 0}");
static const u8 sStatsNonHPLayout[]                         = _("{DYNAMIC 0}\n{DYNAMIC 1}\n{DYNAMIC 2}\n{DYNAMIC 3}\n{DYNAMIC 4}");
static const u8 sMovesPPLayout[]                            = _("{PP}{CLEAR_TO 31}{DYNAMIC 0}/{DYNAMIC 1}");

#if BW_SUMMARY_DECAP == TRUE
static const u8 sText_Cancel[]                              = _("Cancel");
static const u8 sText_Switch[]                              = _("Switch");
static const u8 sText_PkmnInfo[]                            = _("Pokémon Info");
static const u8 sText_PkmnSkills[]                          = _("Pokémon Skills");
static const u8 sText_BattleMoves[]                         = _("Battle Moves");
static const u8 sText_ContestMoves[]                        = _("Contest Moves");
static const u8 sText_Info[]                                = _("Info");
static const u8 sText_ViewIVs[]                             = _("View IV");
static const u8 sText_ViewEVs[]                             = _("View EV");
static const u8 sText_ViewStats[]                           = _("View Stats");
static const u8 sText_ViewIVs_Graded[]                      = _("See Innate");
static const u8 sText_ViewEVs_Graded[]                      = _("See Effort");
static const u8 sText_NextLv[]                              = _("Next Lv.");
static const u8 sText_RentalPkmn[]                          = _("Rental Pokémon");
static const u8 sText_None[]                                = _("None");
#else
static const u8 sText_Cancel[]                              = _("CANCEL");
static const u8 sText_Switch[]                              = _("SWITCH");
static const u8 sText_PkmnInfo[]                            = _("POKéMON INFO");
static const u8 sText_PkmnSkills[]                          = _("POKéMON SKILLS");
static const u8 sText_BattleMoves[]                         = _("BATTLE MOVES");
static const u8 sText_ContestMoves[]                        = _("CONTEST MOVES");
static const u8 sText_Info[]                                = _("INFO");
static const u8 sText_ViewIVs[]                             = _("VIEW IV");
static const u8 sText_ViewEVs[]                             = _("VIEW EV");
static const u8 sText_ViewStats[]                           = _("VIEW STATS");
static const u8 sText_ViewIVs_Graded[]                      = _("SEE INNATE");
static const u8 sText_ViewEVs_Graded[]                      = _("SEE EFFORT");
static const u8 sText_NextLv[]                              = _("NEXT LV.");
static const u8 sText_RentalPkmn[]                          = _("RENTAL POKéMON");
static const u8 sText_None[]                                = _("NONE");
#endif

// bg gfx
const u32 sSummaryScreen_Gfx_BW[]                           = INCBIN_U32("graphics/summary_screen/bw/tiles.4bpp.lz");
const u32 sSummaryScreen_Pal_BW[]                           = INCBIN_U32("graphics/summary_screen/bw/tiles.gbapal.lz");
const u32 sSummaryPage_Info_Tilemap_BW[]                    = INCBIN_U32("graphics/summary_screen/bw/page_info.bin.lz");
const u32 sSummaryPage_Skills_Tilemap_BW[]                  = INCBIN_U32("graphics/summary_screen/bw/page_skills.bin.lz");
const u32 sSummaryPage_BattleMoves_Tilemap_BW[]             = INCBIN_U32("graphics/summary_screen/bw/page_battle_moves.bin.lz");
const u32 sSummaryPage_ContestMoves_Tilemap_BW[]            = INCBIN_U32("graphics/summary_screen/bw/page_contest_moves.bin.lz");
const u32 sSummaryPage_InfoEgg_Tilemap_BW[]                 = INCBIN_U32("graphics/summary_screen/bw/page_info_egg.bin.lz");
const u32 sSummaryPage_EffectBattle_Tilemap_BW[]            = INCBIN_U32("graphics/summary_screen/bw/effect_battle.bin.lz");
const u32 sSummaryPage_EffectContest_Tilemap_BW[]           = INCBIN_U32("graphics/summary_screen/bw/effect_contest.bin.lz");
const u16 sSummaryScreen_PPTextPalette_BW[]                 = INCBIN_U16("graphics/summary_screen/bw/text_pp.gbapal");

// sprite gfx
static const u8 sButtons_Gfx[][4 * TILE_SIZE_4BPP] = {
    INCBIN_U8("graphics/summary_screen/bw/a_button.4bpp"),
    INCBIN_U8("graphics/summary_screen/bw/b_button.4bpp"),
};

#if BW_SUMMARY_BW_TYPE_ICONS == TRUE
static const u32 sMoveTypes_Gfx_BW[]                        = INCBIN_U32("graphics/types_bw/move_types_bw.4bpp.lz");
static const u32 sMoveTypes_Pal_BW[]                        = INCBIN_U32("graphics/types_bw/move_types_bw.gbapal.lz");
#endif
static const u32 sTeraTypes_Gfx[]                           = INCBIN_U32("graphics/types_bw/tera/tera_types_bw.4bpp.lz");
static const u32 sSummaryMoveSelect_Gfx_BW[]                = INCBIN_U32("graphics/summary_screen/bw/move_select.4bpp.lz");
static const u32 sSummaryMoveSelect_Pal_BW[]                = INCBIN_U32("graphics/summary_screen/bw/move_select.gbapal.lz");
static const u16 sMarkings_Pal_BW[]                         = INCBIN_U16("graphics/summary_screen/bw/markings.gbapal");
static const u32 sShinyIcon_Gfx_BW[]                        = INCBIN_U32("graphics/summary_screen/bw/shiny_icon.4bpp.lz");
static const u32 sPokerusCuredIcon_Gfx_BW[]                 = INCBIN_U32("graphics/summary_screen/bw/pokerus_cured_icon.4bpp.lz");
static const u16 sCategoryIcons_Pal[]                       = INCBIN_U16("graphics/summary_screen/bw/category_icons.gbapal");
static const u32 sCategoryIcons_Gfx[]                       = INCBIN_U32("graphics/summary_screen/bw/category_icons.4bpp.lz");
static const u16 sStatGrades_Pal[]                          = INCBIN_U16("graphics/summary_screen/bw/stat_grades.gbapal");
static const u32 sStatGrades_Gfx[]                          = INCBIN_U32("graphics/summary_screen/bw/stat_grades.4bpp.lz");
static const u16 sFriendshipIcon_Pal[]                      = INCBIN_U16("graphics/summary_screen/bw/heart.gbapal");
static const u32 sFriendshipIcon_Gfx[]                      = INCBIN_U32("graphics/summary_screen/bw/heart.4bpp.lz");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};
static const struct WindowTemplate sSummaryTemplate[] =
{
    [PSS_LABEL_WINDOW_POKEMON_INFO_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 1,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 23,
    },
    [PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 45,
    },
    [PSS_LABEL_WINDOW_CONTEST_MOVES_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 67,
    },
    [PSS_LABEL_WINDOW_PROMPT_CANCEL] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 0,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 89,
    },
    [PSS_LABEL_WINDOW_PROMPT_INFO] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 0,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 105,
    },
    [PSS_LABEL_WINDOW_PROMPT_SWITCH] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 0,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 121,
    },
    [PSS_LABEL_WINDOW_POKEMON_INFO_TYPE] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 6,
        .width = 18,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 137,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 13,
        .width = 11,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 173,
    },
    [PSS_LABEL_WINDOW_MOVES_POWER_ACC] = {
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 10,
        .width = 7,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 217,
    },
    [PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 2,
        .width = 10,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 245,
    },
    [PSS_LABEL_WINDOW_PROMPT_IVS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 0,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 275,
    },
    [PSS_LABEL_WINDOW_PROMPT_EVS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 0,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 295,
    },
    [PSS_LABEL_WINDOW_PROMPT_STATS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 0,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 315,
    },
    [PSS_LABEL_WINDOW_END] = DUMMY_WIN_TEMPLATE
};
static const struct WindowTemplate sPageInfoTemplate[] =
{
    [PSS_DATA_WINDOW_INFO_OT_OTID_ITEM] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 7,
        .width = 12,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 335,
    },
    [PSS_DATA_WINDOW_INFO_MEMO] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = 26,
        .height = 7,
        .paletteNum = 6,
        .baseBlock = 407,
    },
    [PSS_DATA_WINDOW_INFO_DEX_NUMBER_NAME] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 3,
        .width = 9,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 589,
    },
};
static const struct WindowTemplate sPageSkillsTemplate[] =
{
    [PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT] = { // currently unused
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 4,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 335,
    },
    [PSS_DATA_WINDOW_SKILLS_STATS_HP] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 355,
    },
    [PSS_DATA_WINDOW_SKILLS_STATS_NON_HP] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 4,
        .width = 10,
        .height = 8,
        .paletteNum = 6,
        .baseBlock = 371,
    },
    [PSS_DATA_WINDOW_EXP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 451,
    },
    [PSS_DATA_WINDOW_EXP_NEXT_LEVEL] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 13,
        .width = 9,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 473,
    },
    [PSS_DATA_WINDOW_SKILLS_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 5,
        .paletteNum = 6,
        .baseBlock = 491,
    },
};
static const struct WindowTemplate sPageMovesTemplate[] = // This is used for both battle and contest moves
{
    [PSS_DATA_WINDOW_MOVE_NAMES_PP] = {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 9,
        .height = 20,
        .paletteNum = 8,
        .baseBlock = 335,
    },
    [PSS_DATA_WINDOW_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 14,
        .width = 15,
        .height = 9,
        .paletteNum = 6,
        .baseBlock = 515,
    },
};
static const u8 sTextColors[][3] =
{
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
    {0, 9, 10},
    {0, 11, 12},
    {0, 13, 14},
    {0, 7, 8},
    {13, 15, 14},
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
};

static void (*const sTextPrinterFunctions[])(void) =
{
    [PSS_PAGE_INFO] = PrintInfoPageText,
    [PSS_PAGE_SKILLS] = PrintSkillsPageText,
    [PSS_PAGE_BATTLE_MOVES] = PrintBattleMoves,
    [PSS_PAGE_CONTEST_MOVES] = PrintContestMoves
};

static void (*const sTextPrinterTasks[])(u8 taskId) =
{
    [PSS_PAGE_INFO] = Task_PrintInfoPage,
    [PSS_PAGE_SKILLS] = Task_PrintSkillsPage,
    [PSS_PAGE_BATTLE_MOVES] = Task_PrintBattleMoves,
    [PSS_PAGE_CONTEST_MOVES] = Task_PrintContestMoves
};

#define TAG_MOVE_SELECTOR 30000
#define TAG_MON_STATUS 30001
#define TAG_MOVE_TYPES 30002
#define TAG_MON_MARKINGS 30003
#define TAG_MON_SHINY_ICON 30004
#define TAG_MON_POKERUS_CURED_ICON 30005
#define TAG_CATEGORY_ICONS 30006
#define TAG_STAT_GRADES 30007
#define TAG_FRIENDSHIP_ICON 30008
#define TAG_TERA_TYPE 30009

enum BWCategoryIcon
{
    CATEGORY_ICON_PHYSICAL,
    CATEGORY_ICON_SPECIAL,
    CATEGORY_ICON_STATUS,
};

static const struct OamData sOamData_CategoryIcons =
{
    .size = SPRITE_SIZE(32x16),
    .shape = SPRITE_SHAPE(32x16),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_CategoryIcons =
{
    .data = sCategoryIcons_Gfx,
    .size = 32*16*3/2,
    .tag = TAG_CATEGORY_ICONS,
};

static const struct SpritePalette sSpritePal_CategoryIcons =
{
    .data = sCategoryIcons_Pal,
    .tag = TAG_CATEGORY_ICONS
};

static const union AnimCmd sSpriteAnim_CategoryPhysical[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategorySpecial[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategoryStatus[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_CategoryIcons[] =
{
    [CATEGORY_ICON_PHYSICAL] = sSpriteAnim_CategoryPhysical,
    [CATEGORY_ICON_SPECIAL] = sSpriteAnim_CategorySpecial,
    [CATEGORY_ICON_STATUS] = sSpriteAnim_CategoryStatus,
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

enum BWStatGrades 
{
    STAT_GRADE_EMINUS,
    STAT_GRADE_E,
    STAT_GRADE_EPLUS,
    STAT_GRADE_DMINUS,
    STAT_GRADE_D,
    STAT_GRADE_DPLUS,
    STAT_GRADE_CMINUS,
    STAT_GRADE_C,
    STAT_GRADE_CPLUS,
    STAT_GRADE_BMINUS,
    STAT_GRADE_B,
    STAT_GRADE_BPLUS,
    STAT_GRADE_AMINUS,
    STAT_GRADE_A,
    STAT_GRADE_APLUS,
    STAT_GRADE_S,
    STAT_GRADE_COUNT,
};

static const struct OamData sOamData_StatGrades =
{
    .size = SPRITE_SIZE(16x8),
    .shape = SPRITE_SHAPE(16x8),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_StatGrades =
{
    .data = sStatGrades_Gfx,
    .size = STAT_GRADE_COUNT * (16 * 8),
    .tag = TAG_STAT_GRADES,
};

static const struct SpritePalette sSpritePal_StatGrades =
{
    .data = sStatGrades_Pal,
    .tag = TAG_STAT_GRADES
};

static const union AnimCmd sSpriteAnim_StatGradeEMinus[] = {
    ANIMCMD_FRAME(STAT_GRADE_EMINUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeE[] = {
    ANIMCMD_FRAME(STAT_GRADE_E * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeEPlus[] = {
    ANIMCMD_FRAME(STAT_GRADE_EPLUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeDMinus[] = {
    ANIMCMD_FRAME(STAT_GRADE_DMINUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeD[] = {
    ANIMCMD_FRAME(STAT_GRADE_D * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeDPlus[] = {
    ANIMCMD_FRAME(STAT_GRADE_DPLUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeCMinus[] = {
    ANIMCMD_FRAME(STAT_GRADE_CMINUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeC[] = {
    ANIMCMD_FRAME(STAT_GRADE_C * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeCPlus[] = {
    ANIMCMD_FRAME(STAT_GRADE_CPLUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeBMinus[] = {
    ANIMCMD_FRAME(STAT_GRADE_BMINUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeB[] = {
    ANIMCMD_FRAME(STAT_GRADE_B * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeBPlus[] = {
    ANIMCMD_FRAME(STAT_GRADE_BPLUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeAMinus[] = {
    ANIMCMD_FRAME(STAT_GRADE_AMINUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeA[] = {
    ANIMCMD_FRAME(STAT_GRADE_A * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeAPlus[] = {
    ANIMCMD_FRAME(STAT_GRADE_APLUS * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatGradeS[] = {
    ANIMCMD_FRAME(STAT_GRADE_S * 2, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_StatGrades[STAT_GRADE_COUNT] = {
    [STAT_GRADE_EMINUS] = sSpriteAnim_StatGradeEMinus,
    [STAT_GRADE_E]      = sSpriteAnim_StatGradeE,
    [STAT_GRADE_EPLUS]  = sSpriteAnim_StatGradeEPlus,
    [STAT_GRADE_DMINUS] = sSpriteAnim_StatGradeDMinus,
    [STAT_GRADE_D]      = sSpriteAnim_StatGradeD,
    [STAT_GRADE_DPLUS]  = sSpriteAnim_StatGradeDPlus,
    [STAT_GRADE_CMINUS] = sSpriteAnim_StatGradeCMinus,
    [STAT_GRADE_C]      = sSpriteAnim_StatGradeC,
    [STAT_GRADE_CPLUS]  = sSpriteAnim_StatGradeCPlus,
    [STAT_GRADE_BMINUS] = sSpriteAnim_StatGradeBMinus,
    [STAT_GRADE_B]      = sSpriteAnim_StatGradeB,
    [STAT_GRADE_BPLUS]  = sSpriteAnim_StatGradeBPlus,
    [STAT_GRADE_AMINUS] = sSpriteAnim_StatGradeAMinus,
    [STAT_GRADE_A]      = sSpriteAnim_StatGradeA,
    [STAT_GRADE_APLUS]  = sSpriteAnim_StatGradeAPlus,
    [STAT_GRADE_S]      = sSpriteAnim_StatGradeS,
};

static const struct SpriteTemplate sSpriteTemplate_StatGrades =
{
    .tileTag = TAG_STAT_GRADES,
    .paletteTag = TAG_STAT_GRADES,
    .oam = &sOamData_StatGrades,
    .anims = sSpriteAnimTable_StatGrades,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

enum FriendshipLevels
{
    FRIENDSHIP_LEVEL_0,
    FRIENDSHIP_LEVEL_1,
    FRIENDSHIP_LEVEL_2,
    FRIENDSHIP_LEVEL_3,
    FRIENDSHIP_LEVEL_4,
    FRIENDSHIP_LEVEL_5,
    FRIENDSHIP_LEVEL_MAX,
    FRIENDSHIP_LEVEL_COUNT,
};

// edit these to change what friendship value the heart icon changes at
static const u8 sFriendshipLevelToThreshold[FRIENDSHIP_LEVEL_COUNT] = 
{
    [FRIENDSHIP_LEVEL_0]    = 0,
    [FRIENDSHIP_LEVEL_1]    = 44,
    [FRIENDSHIP_LEVEL_2]    = 88,
    [FRIENDSHIP_LEVEL_3]    = 132,
    [FRIENDSHIP_LEVEL_4]    = 176,
    [FRIENDSHIP_LEVEL_5]    = 220,
    [FRIENDSHIP_LEVEL_MAX]  = MAX_FRIENDSHIP,
};

static const struct OamData sOamData_FriendshipIcon =
{
    .size = SPRITE_SIZE(8x8),
    .shape = SPRITE_SHAPE(8x8),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_FriendshipIcon =
{
    .data = sFriendshipIcon_Gfx,
    .size = FRIENDSHIP_LEVEL_COUNT * (8 * 8),
    .tag = TAG_FRIENDSHIP_ICON,
};

static const struct SpritePalette sSpritePal_FriendshipIcon =
{
    .data = sFriendshipIcon_Pal,
    .tag = TAG_FRIENDSHIP_ICON
};

static const union AnimCmd sSpriteAnim_FriendshipIcon0[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon1[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_1, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon2[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon3[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_3, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon4[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon5[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_5, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIconMax[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_MAX, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_FriendshipIcon[FRIENDSHIP_LEVEL_COUNT] = {
    [FRIENDSHIP_LEVEL_0]    = sSpriteAnim_FriendshipIcon0,
    [FRIENDSHIP_LEVEL_1]    = sSpriteAnim_FriendshipIcon1,
    [FRIENDSHIP_LEVEL_2]    = sSpriteAnim_FriendshipIcon2,
    [FRIENDSHIP_LEVEL_3]    = sSpriteAnim_FriendshipIcon3,
    [FRIENDSHIP_LEVEL_4]    = sSpriteAnim_FriendshipIcon4,
    [FRIENDSHIP_LEVEL_5]    = sSpriteAnim_FriendshipIcon5,
    [FRIENDSHIP_LEVEL_MAX]  = sSpriteAnim_FriendshipIconMax,
};

static const struct SpriteTemplate sSpriteTemplate_FriendshipIcon =
{
    .tileTag = TAG_FRIENDSHIP_ICON,
    .paletteTag = TAG_FRIENDSHIP_ICON,
    .oam = &sOamData_FriendshipIcon,
    .anims = sSpriteAnimTable_FriendshipIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_TypeNone[] = {
    ANIMCMD_FRAME(TYPE_NONE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeStellar[] = {
    ANIMCMD_FRAME(TYPE_STELLAR * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCool[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_COOL + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryBeauty[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_BEAUTY + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCute[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_CUTE + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategorySmart[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_SMART + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryTough[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_TOUGH + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] = {
    [TYPE_NONE] = sSpriteAnim_TypeNone,
    [TYPE_NORMAL] = sSpriteAnim_TypeNormal,
    [TYPE_FIGHTING] = sSpriteAnim_TypeFighting,
    [TYPE_FLYING] = sSpriteAnim_TypeFlying,
    [TYPE_POISON] = sSpriteAnim_TypePoison,
    [TYPE_GROUND] = sSpriteAnim_TypeGround,
    [TYPE_ROCK] = sSpriteAnim_TypeRock,
    [TYPE_BUG] = sSpriteAnim_TypeBug,
    [TYPE_GHOST] = sSpriteAnim_TypeGhost,
    [TYPE_STEEL] = sSpriteAnim_TypeSteel,
    [TYPE_MYSTERY] = sSpriteAnim_TypeMystery,
    [TYPE_FIRE] = sSpriteAnim_TypeFire,
    [TYPE_WATER] = sSpriteAnim_TypeWater,
    [TYPE_GRASS] = sSpriteAnim_TypeGrass,
    [TYPE_ELECTRIC] = sSpriteAnim_TypeElectric,
    [TYPE_PSYCHIC] = sSpriteAnim_TypePsychic,
    [TYPE_ICE] = sSpriteAnim_TypeIce,
    [TYPE_DRAGON] = sSpriteAnim_TypeDragon,
    [TYPE_DARK] = sSpriteAnim_TypeDark,
    [TYPE_FAIRY] = sSpriteAnim_TypeFairy,
    [TYPE_STELLAR] = sSpriteAnim_TypeStellar,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_COOL] = sSpriteAnim_CategoryCool,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_BEAUTY] = sSpriteAnim_CategoryBeauty,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_CUTE] = sSpriteAnim_CategoryCute,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_SMART] = sSpriteAnim_CategorySmart,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_TOUGH] = sSpriteAnim_CategoryTough,
};

static const struct CompressedSpriteSheet sSpriteSheet_MoveTypes =
{
#if BW_SUMMARY_BW_TYPE_ICONS == TRUE
    .data = sMoveTypes_Gfx_BW,
#else
    .data = gMoveTypes_Gfx,
#endif
    .size = (NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT) * 0x100,
    .tag = TAG_MOVE_TYPES
};

static const struct SpriteTemplate sSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u8 sContestCategoryToOamPaletteNum[CONTEST_CATEGORIES_COUNT] =
{
    [CONTEST_CATEGORY_COOL] = 13,
    [CONTEST_CATEGORY_BEAUTY] = 14,
    [CONTEST_CATEGORY_CUTE] = 14,
    [CONTEST_CATEGORY_SMART] = 15,
    [CONTEST_CATEGORY_TOUGH] = 13,
};

static const union AnimCmd sSpriteAnim_TeraTypeNone[] = {
    ANIMCMD_FRAME(TYPE_NONE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeStellar[] = {
    ANIMCMD_FRAME(TYPE_STELLAR * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_TeraType[NUMBER_OF_MON_TYPES] = {
    [TYPE_NONE] = sSpriteAnim_TeraTypeNone,
    [TYPE_NORMAL] = sSpriteAnim_TeraTypeNormal,
    [TYPE_FIGHTING] = sSpriteAnim_TeraTypeFighting,
    [TYPE_FLYING] = sSpriteAnim_TeraTypeFlying,
    [TYPE_POISON] = sSpriteAnim_TeraTypePoison,
    [TYPE_GROUND] = sSpriteAnim_TeraTypeGround,
    [TYPE_ROCK] = sSpriteAnim_TeraTypeRock,
    [TYPE_BUG] = sSpriteAnim_TeraTypeBug,
    [TYPE_GHOST] = sSpriteAnim_TeraTypeGhost,
    [TYPE_STEEL] = sSpriteAnim_TeraTypeSteel,
    [TYPE_MYSTERY] = sSpriteAnim_TeraTypeMystery,
    [TYPE_FIRE] = sSpriteAnim_TeraTypeFire,
    [TYPE_WATER] = sSpriteAnim_TeraTypeWater,
    [TYPE_GRASS] = sSpriteAnim_TeraTypeGrass,
    [TYPE_ELECTRIC] = sSpriteAnim_TeraTypeElectric,
    [TYPE_PSYCHIC] = sSpriteAnim_TeraTypePsychic,
    [TYPE_ICE] = sSpriteAnim_TeraTypeIce,
    [TYPE_DRAGON] = sSpriteAnim_TeraTypeDragon,
    [TYPE_DARK] = sSpriteAnim_TeraTypeDark,
    [TYPE_FAIRY] = sSpriteAnim_TeraTypeFairy,
    [TYPE_STELLAR] = sSpriteAnim_TeraTypeStellar
};

static const struct OamData sOamData_TeraType =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_TeraType =
{
    .data = sTeraTypes_Gfx,
    .size = NUMBER_OF_MON_TYPES * (16 * 16),
    .tag = TAG_TERA_TYPE
};

static const struct SpriteTemplate sSpriteTemplate_TeraType =
{
    .tileTag = TAG_TERA_TYPE,
    .paletteTag = TAG_TERA_TYPE,
    .oam = &sOamData_TeraType,
    .anims = sSpriteAnimTable_TeraType,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_MoveSelectorUnused0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused1[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused2[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused3[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeft[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRight[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorMiddle[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftAlt[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorMiddleAlt[] = {
    ANIMCMD_FRAME(8, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightAlt[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};

// anims 0 - 3 are unused but be careful because
// removing them will mess up the StartAnim calls :)
static const union AnimCmd *const sSpriteAnimTable_MoveSelector[] = {
    sSpriteAnim_MoveSelectorUnused0,
    sSpriteAnim_MoveSelectorUnused1,
    sSpriteAnim_MoveSelectorUnused2,
    sSpriteAnim_MoveSelectorUnused3,
    sSpriteAnim_MoveSelectorLeft,
    sSpriteAnim_MoveSelectorRight,
    sSpriteAnim_MoveSelectorMiddle,
    sSpriteAnim_MoveSelectorLeftAlt,
    sSpriteAnim_MoveSelectorMiddleAlt,
    sSpriteAnim_MoveSelectorRightAlt,
};

static const struct CompressedSpriteSheet sMoveSelectorSpriteSheet =
{
    .data = sSummaryMoveSelect_Gfx_BW,
    .size = 8*128,
    .tag = TAG_MOVE_SELECTOR
};

static const struct CompressedSpritePalette sMoveSelectorSpritePal =
{
    .data = sSummaryMoveSelect_Pal_BW,
    .tag = TAG_MOVE_SELECTOR
};

static const struct SpriteTemplate sMoveSelectorSpriteTemplate =
{
    .tileTag = TAG_MOVE_SELECTOR,
    .paletteTag = TAG_MOVE_SELECTOR,
    .oam = &sOamData_MoveSelector,
    .anims = sSpriteAnimTable_MoveSelector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrostbite[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFrostbite,
};

static const struct CompressedSpriteSheet sStatusIconsSpriteSheet =
{
    .data = gStatusGfx_Icons,
    .size = 0x400,
    .tag = TAG_MON_STATUS
};

static const struct CompressedSpritePalette sStatusIconsSpritePalette =
{
    .data = gStatusPal_Icons,
    .tag = TAG_MON_STATUS
};

static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_ShinyIcon =
{
    .y = 0,
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
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sShinyIconSpriteSheet =
{
    .data = sShinyIcon_Gfx_BW,
    .size = 8*8,
    .tag = TAG_MON_SHINY_ICON
};

static const struct SpriteTemplate sSpriteTemplate_ShinyIcon =
{
    .tileTag = TAG_MON_SHINY_ICON,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_ShinyIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_PokerusCuredIcon =
{
    .y = 0,
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
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sPokerusCuredIconSpriteSheet =
{
    .data = sPokerusCuredIcon_Gfx_BW,
    .size = 8*8,
    .tag = TAG_MON_POKERUS_CURED_ICON
};

static const struct SpriteTemplate sSpriteTemplate_PokerusCuredIcon =
{
    .tileTag = TAG_MON_POKERUS_CURED_ICON,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_PokerusCuredIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// code
void ShowPokemonSummaryScreen_BW(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    sMonSummaryScreen = AllocZeroed(sizeof(*sMonSummaryScreen));
    sMonSummaryScreen->mode = mode;
    sMonSummaryScreen->monList.mons = mons;
    sMonSummaryScreen->curMonIndex = monIndex;
    sMonSummaryScreen->maxMonIndex = maxMonIndex;
    sMonSummaryScreen->callback = callback;

    if (mode == BW_SUMMARY_MODE_BOX)
        sMonSummaryScreen->isBoxMon = TRUE;
    else
        sMonSummaryScreen->isBoxMon = FALSE;

    switch (mode)
    {
    case BW_SUMMARY_MODE_NORMAL:
    case BW_SUMMARY_MODE_BOX:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 1;
        break;
    case BW_SUMMARY_MODE_LOCK_MOVES:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 1;
        sMonSummaryScreen->lockMovesFlag = TRUE;
        break;
    case BW_SUMMARY_MODE_SELECT_MOVE:
        sMonSummaryScreen->minPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 1;
        sMonSummaryScreen->lockMonFlag = TRUE;
        break;
    }

    sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;
    SummaryScreen_SetAnimDelayTaskId_BW(TASK_NONE);

    if (gMonSpritesGfxPtr == NULL)
        CreateMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A, MON_SPR_GFX_MODE_NORMAL);

    SetMainCallback2(CB2_InitSummaryScreen);
}

void ShowSelectMovePokemonSummaryScreen_BW(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen_BW(BW_SUMMARY_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->newMove = newMove;
}

void ShowPokemonSummaryScreenHandleDeoxys_BW(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen_BW(mode, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->handleDeoxys = TRUE;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_InitSummaryScreen(void)
{
    while (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && LoadGraphics() != TRUE && MenuHelpers_IsLinkActive() != TRUE);
}

static bool8 LoadGraphics(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 6:
        if (DecompressGraphics() != FALSE)
            gMain.state++;
        break;
    case 7:
        ResetWindows();
        gMain.state++;
        break;
    case 8:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 9:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) != 0)
            gMain.state++;
        break;
    case 10:
        PrintMonPortraitInfo();
        gMain.state++;
        break;
    case 11:
        PrintPageNamesAndStats();
        gMain.state++;
        break;
    case 12:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 13:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            SetSelectMoveTilemaps();
        gMain.state++;
        break;
    case 14:
        PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 15:
        ResetSpriteIds();
        CreateMoveTypeIcons();
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE && BW_SUMMARY_CATEGORY_ICONS)
            ShowCategoryIcon(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 16:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != SPRITE_NONE)
        {
            sMonSummaryScreen->switchCounter = 0;
            gMain.state++;
        }
        break;
    case 17:
        CreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 18:
        CreateMonShinySprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 19:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 20:
        CreateSetStatusSprite();
        gMain.state++;
        break;
    case 21:
        if (sMonSummaryScreen->summary.isEgg)
            LimitEggSummaryPageDisplay();

        gMain.state++;
        break;
    case 22:
        SetTypeIcons();
        TrySetInfoPageIcons();
        gMain.state++;
        break;
    case 23:
        if (sMonSummaryScreen->mode != BW_SUMMARY_MODE_SELECT_MOVE)
            CreateTask(Task_HandleInput, 0);
        else
            CreateTask(Task_SetHandleReplaceMoveInput, 0);
        gMain.state++;
        break;
    case 24:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 25:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlank);
        SetMainCallback2(MainCB2);
        return TRUE;
    }
    return FALSE;
}

static void InitBGs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
    SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][0]);
    SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 DecompressGraphics(void)
{
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, &sSummaryScreen_Gfx_BW, 0, 0, 0);
        sMonSummaryScreen->switchCounter++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != 1)
        {
            LZDecompressWram(sSummaryPage_Info_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0]);
            sMonSummaryScreen->switchCounter++;
        }
        break;
    case 2:
        LZDecompressWram(sSummaryPage_InfoEgg_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 3:
        LZDecompressWram(sSummaryPage_Skills_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 4:
        LZDecompressWram(sSummaryPage_BattleMoves_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 5:
        LZDecompressWram(sSummaryPage_ContestMoves_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 6:
        LZDecompressWram(sSummaryPage_EffectBattle_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_BATTLE_EFFECTS][0]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 7:
        LZDecompressWram(sSummaryPage_EffectContest_Tilemap_BW, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 8:
        LoadCompressedPalette(sSummaryScreen_Pal_BW, BG_PLTT_ID(0), 8 * PLTT_SIZE_4BPP);
        LoadPalette(&sSummaryScreen_PPTextPalette_BW, BG_PLTT_ID(8) + 1, PLTT_SIZEOF(16 - 1));
        sMonSummaryScreen->switchCounter++;
        break;
    case 9:
        LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
        sMonSummaryScreen->switchCounter++;
        break;
    case 10:
        LoadCompressedSpriteSheet(&sMoveSelectorSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 11:
        LoadCompressedSpriteSheet(&sStatusIconsSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 12:
        LoadCompressedSpritePalette(&sStatusIconsSpritePalette);
        sMonSummaryScreen->switchCounter++;
        break;
    case 13:
        LoadCompressedSpriteSheet(&sShinyIconSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 14:
        LoadCompressedSpriteSheet(&sPokerusCuredIconSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 15:
        LoadCompressedSpritePalette(&sMoveSelectorSpritePal);
        sMonSummaryScreen->switchCounter++;
        break;
    case 16:
        if (BW_SUMMARY_CATEGORY_ICONS)
            LoadCompressedSpriteSheet(&sSpriteSheet_CategoryIcons);
        sMonSummaryScreen->switchCounter++;
        break;
    case 17:
        if (BW_SUMMARY_CATEGORY_ICONS)
            LoadSpritePalette(&sSpritePal_CategoryIcons);
        sMonSummaryScreen->switchCounter++;
        break;
    case 18:
        if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            LoadCompressedSpriteSheet(&sSpriteSheet_StatGrades);
        sMonSummaryScreen->switchCounter++;
        break;
    case 19:
        if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            LoadSpritePalette(&sSpritePal_StatGrades);
        sMonSummaryScreen->switchCounter++;
        break;
    case 20:
        if (BW_SUMMARY_SHOW_FRIENDSHIP)
            LoadCompressedSpriteSheet(&sSpriteSheet_FriendshipIcon);
        sMonSummaryScreen->switchCounter++;
        break;
    case 21:
        if (BW_SUMMARY_SHOW_FRIENDSHIP)
            LoadSpritePalette(&sSpritePal_FriendshipIcon);
        sMonSummaryScreen->switchCounter++;
        break;
    case 22:
    #if BW_SUMMARY_BW_TYPE_ICONS == TRUE
        LoadCompressedPalette(sMoveTypes_Pal_BW, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
    #else
        LoadCompressedPalette(gMoveTypes_Pal, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
    #endif
        sMonSummaryScreen->switchCounter++;
        break;
    case 23:
        if (P_SHOW_TERA_TYPE >= GEN_9)
            LoadCompressedSpriteSheet(&sSpriteSheet_TeraType);
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    }
    return FALSE;
}

static void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon *partyMon = sMonSummaryScreen->monList.mons;
        *mon = partyMon[sMonSummaryScreen->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMon[sMonSummaryScreen->curMonIndex], mon);
    }
}

static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *mon)
{
    u32 i;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    // Spread the data extraction over multiple frames.
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        sum->species = GetMonData(mon, MON_DATA_SPECIES);
        sum->species2 = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
        sum->exp = GetMonData(mon, MON_DATA_EXP);
        sum->level = GetMonData(mon, MON_DATA_LEVEL);
        sum->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
        sum->item = GetMonData(mon, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(mon, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sum->sanity)
            sum->isEgg = TRUE;
        else
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);

        break;
    case 1:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            sum->moves[i] = GetMonData(mon, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(mon, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == BW_SUMMARY_MODE_BOX || sMonSummaryScreen->handleDeoxys == TRUE)
        {
            sum->nature = GetNature(mon);
            sum->mintNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK);
            sum->def = GetMonData(mon, MON_DATA_DEF);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF);
            sum->speed = GetMonData(mon, MON_DATA_SPEED);
        }
        else
        {
            sum->nature = GetNature(mon);
            sum->mintNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK2);
            sum->def = GetMonData(mon, MON_DATA_DEF2);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK2);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF2);
            sum->speed = GetMonData(mon, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(mon, MON_DATA_OT_NAME, sum->OTName);
        ConvertInternationalString(sum->OTName, GetMonData(mon, MON_DATA_LANGUAGE));
        sum->ailment = GetMonAilment(mon);
        sum->OTGender = GetMonData(mon, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(mon, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(mon, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(mon, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
        break;
    case 4:
        sum->ivHp = GetMonData(mon, MON_DATA_HP_IV);
        sum->ivAtk = GetMonData(mon, MON_DATA_ATK_IV);
        sum->ivDef = GetMonData(mon, MON_DATA_DEF_IV);
        sum->ivSpatk = GetMonData(mon, MON_DATA_SPATK_IV);
        sum->ivSpdef = GetMonData(mon, MON_DATA_SPDEF_IV);
        sum->ivSpeed = GetMonData(mon, MON_DATA_SPEED_IV);
        break;
    case 5:
        sum->evHp = GetMonData(mon, MON_DATA_HP_EV);
        sum->evAtk = GetMonData(mon, MON_DATA_ATK_EV);
        sum->evDef = GetMonData(mon, MON_DATA_DEF_EV);
        sum->evSpatk = GetMonData(mon, MON_DATA_SPATK_EV);
        sum->evSpdef = GetMonData(mon, MON_DATA_SPDEF_EV);
        sum->evSpeed = GetMonData(mon, MON_DATA_SPEED_EV);
        break;
    default:
        sum->ribbonCount = GetMonData(mon, MON_DATA_RIBBON_COUNT);        
        sum->teraType = GetMonData(mon, MON_DATA_TERA_TYPE);
        sum->isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
        return TRUE;
    }
    sMonSummaryScreen->switchCounter++;
    return FALSE;
}

static void SetSelectMoveTilemaps(void)
{
    SetBgTilemapBuffer(1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0]);
    SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
    SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_BATTLE_EFFECTS][0]);
    HideInactivePageDots();
    ChangeBgX(2, 0x10000, BG_COORD_ADD);
    SetBgAttribute(3, BG_ATTR_PRIORITY, 1);
    ShowBg(2);
    ShowBg(3);
}

#define TILEMAP_PAGE_DOT_1_TILE_1   0x000D
#define TILEMAP_PAGE_DOT_1_TILE_2   0x002D
#define TILEMAP_PAGE_DOT_2_TILE_1   0x000F
#define TILEMAP_PAGE_DOT_2_TILE_2   0x002F
#define TILEMAP_PAGE_DOT_3_TILE_1   0x0011
#define TILEMAP_PAGE_DOT_3_TILE_2   0x0031
#define TILEMAP_PAGE_DOT_4_TILE_1   0x0013
#define TILEMAP_PAGE_DOT_4_TILE_2   0x0033

#define TILE_BLACK_SQUARE           0x0122
#define TILE_INACTIVE_SQUARE_TOP    0x0002
#define TILE_INACTIVE_SQUARE_BOTTOM BG_TILE_V_FLIP(TILE_INACTIVE_SQUARE_TOP)

static void HideInactivePageDots(void)
{
    u32 i;
    for (i = 0; i < 2; i++)
    {
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][i][TILEMAP_PAGE_DOT_1_TILE_1] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][i][TILEMAP_PAGE_DOT_1_TILE_2] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][i][TILEMAP_PAGE_DOT_2_TILE_1] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][i][TILEMAP_PAGE_DOT_2_TILE_2] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][i][TILEMAP_PAGE_DOT_1_TILE_1] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][i][TILEMAP_PAGE_DOT_1_TILE_2] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][i][TILEMAP_PAGE_DOT_2_TILE_1] = TILE_BLACK_SQUARE;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][i][TILEMAP_PAGE_DOT_2_TILE_2] = TILE_BLACK_SQUARE;
    }
}

static void LimitEggSummaryPageDisplay(void)
{
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_2_TILE_1] = TILE_BLACK_SQUARE;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_2_TILE_2] = TILE_BLACK_SQUARE;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_3_TILE_1] = TILE_BLACK_SQUARE;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_3_TILE_2] = TILE_BLACK_SQUARE;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_4_TILE_1] = TILE_BLACK_SQUARE;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_4_TILE_2] = TILE_BLACK_SQUARE;
    ScheduleBgCopyTilemapToVram(3);
}

static void RestoreSummaryPageDisplay(void)
{
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_2_TILE_1] = TILE_INACTIVE_SQUARE_TOP;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_2_TILE_2] = TILE_INACTIVE_SQUARE_BOTTOM;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_3_TILE_1] = TILE_INACTIVE_SQUARE_TOP;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_3_TILE_2] = TILE_INACTIVE_SQUARE_BOTTOM;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_4_TILE_1] = TILE_INACTIVE_SQUARE_TOP;
    sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][TILEMAP_PAGE_DOT_4_TILE_2] = TILE_INACTIVE_SQUARE_BOTTOM;
    ScheduleBgCopyTilemapToVram(3);
}

static void FreeSummaryScreen(void)
{
    FreeAllWindowBuffers();
    Free(sMonSummaryScreen);
}

static void BeginCloseSummaryScreen(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = CloseSummaryScreen;
}

static void CloseSummaryScreen(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        SetMainCallback2(sMonSummaryScreen->callback);
        gLastViewedMonIndex = sMonSummaryScreen->curMonIndex;
        SummaryScreen_DestroyAnimDelayTask();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        if (gMonSpritesGfxPtr == NULL)
            DestroyMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A);
        FreeSummaryScreen();
        DestroyTask(taskId);
    }
}

#define tSkillsState data[3]

// Cycle summary page between stats, IVs and EVs
static void ChangeSummaryState(s16 *data, u8 taskId)
{
    switch (tSkillsState)
    {
    case SKILL_STATE_STATS:
        tSkillsState = SKILL_STATE_IVS;
        break;
    case SKILL_STATE_IVS:
        tSkillsState = SKILL_STATE_EVS;
        break;
    case SKILL_STATE_EVS:
        if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            tSkillsState = SKILL_STATE_IVS;
        else
            tSkillsState = SKILL_STATE_STATS;
        break;
    }

    gTasks[taskId].func = Task_HandleInput;
}

// draw button prompts when cycling between stats, IVs and EVs
static void DrawNextSkillsButtonPrompt(u8 mode)
{
    switch (mode)
    {
        case SKILL_STATE_STATS:
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
            break;
        case SKILL_STATE_IVS:
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
            break;
        case SKILL_STATE_EVS:
            if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            {
                ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
                PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
            }
            else
            {
                ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
                PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            }
            break;
    }
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 defaultSkillsState = (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED) ? SKILL_STATE_IVS : SKILL_STATE_STATS;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        if (JOY_NEW(DPAD_UP))
        {
            tSkillsState = defaultSkillsState;
            ChangeSummaryPokemon(taskId, -1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            tSkillsState = defaultSkillsState;
            ChangeSummaryPokemon(taskId, 1);
        }
        else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            tSkillsState = defaultSkillsState;
            ChangePage(taskId, -1);
        }
        else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            tSkillsState = defaultSkillsState;
            ChangePage(taskId, 1);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_SKILLS)
            {
                if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    BeginCloseSummaryScreen(taskId);
                }
                else // Contest or Battle Moves
                {
                    PlaySE(SE_SELECT);
                    SwitchToMoveSelection(taskId);
                }
            }
            else
            {
                if (BW_SUMMARY_IV_EV_DISPLAY != BW_IV_EV_HIDDEN)
                {
                    // Cycle through IVs/EVs/stats on pressing A
                    ChangeSummaryState(data, taskId);
                    DrawNextSkillsButtonPrompt(tSkillsState);
                    PlaySE(SE_SELECT);
                    if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
                        ShowGradeIcons(tSkillsState);
                    else
                        BufferAndPrintStats_HandleState(tSkillsState);
                }
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            BeginCloseSummaryScreen(taskId);
        }  
    #if DEBUG_POKEMON_SPRITE_VISUALIZER == TRUE
        else if (JOY_NEW(SELECT_BUTTON) && !gMain.inBattle)
        {
            sMonSummaryScreen->callback = CB2_Pokemon_Sprite_Visualizer;
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            CloseSummaryScreen(taskId);
        }
    #endif
    }
}

#undef tSkillsState

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
{
    s8 monId;

    if (!sMonSummaryScreen->lockMonFlag)
    {
        if (sMonSummaryScreen->isBoxMon == TRUE)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
            {
                if (delta == 1)
                    delta = 0;
                else
                    delta = 2;
            }
            else
            {
                if (delta == 1)
                    delta = 1;
                else
                    delta = 3;
            }
            monId = AdvanceStorageMonIndex(sMonSummaryScreen->monList.boxMons, sMonSummaryScreen->curMonIndex, sMonSummaryScreen->maxMonIndex, delta);
        }
        else if (IsMultiBattle() == TRUE)
        {
            monId = AdvanceMultiBattleMonIndex(delta);
        }
        else
        {
            monId = AdvanceMonIndex(delta);
        }

        if (monId != -1)
        {
            PlaySE(SE_SELECT);
            if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
            {
                SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            }
            sMonSummaryScreen->curMonIndex = monId;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = Task_ChangeSummaryMon;
        }
    }
}

static void Task_ChangeSummaryMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyAnimDelayTask();
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]]);
        break;
    case 3:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        break;
    case 4:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) == FALSE)
            return;
        break;
    case 5:
        RemoveAndCreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        CreateMonShinySprite(&sMonSummaryScreen->currentMon);
        break;
    case 6:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        break;
    case 7:
        HandleStatusSprite(&sMonSummaryScreen->currentMon);
        data[1] = 0;
        break;
    case 8:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1]);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] == SPRITE_NONE)
            return;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 1;
        TryDrawHPBar();
        TryDrawExperienceProgressBar();
        data[1] = 0;
        break;
    case 9:
        SetTypeIcons();
        TrySetInfoPageIcons();
        break;
    case 10:
        PrintMonPortraitInfo();
        break;
    case 11:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
        { 
            if (sMonSummaryScreen->summary.isEgg)
                LimitEggSummaryPageDisplay();
            else
                RestoreSummaryPageDisplay();
        } 
        else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        {
            if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_PRECISE)
                DrawNextSkillsButtonPrompt(SKILL_STATE_STATS);
            else if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
                DrawNextSkillsButtonPrompt(SKILL_STATE_IVS);
        }
        break;
    case 12:
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS && BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            ShowGradeIcons(SKILL_STATE_IVS);
        break;
    case 13:
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 0;
        break;
    default:
        if (!MenuHelpers_ShouldWaitForLinkRecv())
        {
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput;
        }
        return;
    }
    data[0]++;
}

static s8 AdvanceMonIndex(s8 delta)
{
    struct Pokemon *mon = sMonSummaryScreen->monList.mons;
    u8 index = sMonSummaryScreen->curMonIndex;
    u8 numMons = sMonSummaryScreen->maxMonIndex + 1;
    delta += numMons;

    index = (index + delta) % numMons;

    // skip over any Eggs unless on the Info Page
    if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
        while (GetMonData(&mon[index], MON_DATA_IS_EGG))
            index = (index + delta) % numMons;

    // to avoid "scrolling" to the same Pokemon
    if (index == sMonSummaryScreen->curMonIndex)
        return -1;
    else
        return index;
}

static s8 AdvanceMultiBattleMonIndex(s8 delta)
{
    struct Pokemon *mons = sMonSummaryScreen->monList.mons;
    s8 index, arrId = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattleOrder[i] == sMonSummaryScreen->curMonIndex)
        {
            arrId = i;
            break;
        }
    }

    while (TRUE)
    {
        const s8 *order = sMultiBattleOrder;

        arrId += delta;
        if (arrId < 0 || arrId >= PARTY_SIZE)
            return -1;
        index = order[arrId];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static bool8 IsValidToViewInMulti(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    else if (sMonSummaryScreen->curMonIndex != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    else
        return FALSE;
}

static void ChangePage(u8 taskId, s8 delta)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    s16 *data = gTasks[taskId].data;

    if (summary->isEgg)
        return;
    else if (delta == -1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->minPageIndex)
        return;
    else if (delta == 1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->maxPageIndex)
        return;

    PlaySE(SE_SELECT);
    ClearPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    sMonSummaryScreen->currPageIndex += delta;
    data[0] = 0;
    if (delta == 1)
        SetTaskFuncWithFollowupFunc(taskId, PssScrollRight, gTasks[taskId].func);
    else
        SetTaskFuncWithFollowupFunc(taskId, PssScrollLeft, gTasks[taskId].func);
    CreateTextPrinterTask(sMonSummaryScreen->currPageIndex);
    HidePageSpecificSprites();
}

static void PssScrollRight(u8 taskId) // Scroll right
{
    s16 *data = gTasks[taskId].data;
    u8 bg1Priority, bg2Priority;

    if (data[0] == 0)
    {
        if (sMonSummaryScreen->bgDisplayOrder == 0)
        {
            data[1] = 1;
            bg1Priority = 1;
            bg2Priority = 2;
            if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            {
                bg1Priority++;
                bg2Priority++;
            }
            SetBgAttribute(1, BG_ATTR_PRIORITY, bg1Priority);
            SetBgAttribute(2, BG_ATTR_PRIORITY, bg2Priority);
            ScheduleBgCopyTilemapToVram(1);
        }
        else
        {
            data[1] = 2;
            bg1Priority = 2;
            bg2Priority = 1;
            if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            {
                bg1Priority++;
                bg2Priority++;
            }
            SetBgAttribute(2, BG_ATTR_PRIORITY, bg2Priority);
            SetBgAttribute(1, BG_ATTR_PRIORITY, bg1Priority);
            ScheduleBgCopyTilemapToVram(2);
        }
        ChangeBgX(data[1], 0, BG_COORD_SET);
        SetBgTilemapBuffer(data[1], sMonSummaryScreen->bgTilemapBuffers[sMonSummaryScreen->currPageIndex][0]);
        ShowBg(1);
        ShowBg(2);
    }
    ChangeBgX(data[1], 0x2000, BG_COORD_ADD);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = PssScrollRightEnd;
}

static void PssScrollRightEnd(u8 taskId) // display right
{
    s16 *data = gTasks[taskId].data;
    sMonSummaryScreen->bgDisplayOrder ^= 1;
    data[1] = 0;
    data[0] = 0;
    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
    {
        SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0]);
        ScheduleBgCopyTilemapToVram(3);
        HandleAppealJamTilemap(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
    }

    PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    SetTypeIcons();
    TrySetInfoPageIcons();
    TryDrawHPBar();
    TryDrawExperienceProgressBar();
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS && BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
        ShowGradeIcons(SKILL_STATE_IVS);
    SwitchTaskToFollowupFunc(taskId);
}

static void PssScrollLeft(u8 taskId) // Scroll left
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (sMonSummaryScreen->bgDisplayOrder == 0)
            data[1] = 2;
        else
            data[1] = 1;
        ChangeBgX(data[1], 0x10000, BG_COORD_SET);
    }
    ChangeBgX(data[1], 0x2000, BG_COORD_SUB);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = PssScrollLeftEnd;
}

static void PssScrollLeftEnd(u8 taskId) // display left
{
    s16 *data = gTasks[taskId].data;
    u8 bg1Priority, bg2Priority;

    if (sMonSummaryScreen->bgDisplayOrder == 0)
    {
        bg1Priority = 1;
        bg2Priority = 2;
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            bg1Priority++;
            bg2Priority++;
        }
        SetBgAttribute(1, BG_ATTR_PRIORITY, bg1Priority);
        SetBgAttribute(2, BG_ATTR_PRIORITY, bg2Priority);
        ScheduleBgCopyTilemapToVram(2);
    }
    else
    {
        bg1Priority = 2;
        bg2Priority = 1;
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            bg1Priority++;
            bg2Priority++;
        }
        SetBgAttribute(2, BG_ATTR_PRIORITY, bg2Priority);
        SetBgAttribute(1, BG_ATTR_PRIORITY, bg1Priority);
        ScheduleBgCopyTilemapToVram(1);
    }
    if (sMonSummaryScreen->currPageIndex > 1)
    {
        SetBgTilemapBuffer(data[1], sMonSummaryScreen->bgTilemapBuffers[sMonSummaryScreen->currPageIndex - 1][0]);
        ChangeBgX(data[1], 0x10000, BG_COORD_SET);
    }
    ShowBg(1);
    ShowBg(2);
    sMonSummaryScreen->bgDisplayOrder ^= 1;
    data[1] = 0;
    data[0] = 0;

    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
    {
        SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_BATTLE_EFFECTS][0]);
        ScheduleBgCopyTilemapToVram(3);
    }

    PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    SetTypeIcons();
    TrySetInfoPageIcons();
    TryDrawHPBar();
    TryDrawExperienceProgressBar();
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS && BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
        ShowGradeIcons(SKILL_STATE_IVS);
    SwitchTaskToFollowupFunc(taskId);
}

static void TryDrawExperienceProgressBar(void)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        DrawExperienceProgressBar(&sMonSummaryScreen->currentMon);
}

static void TryDrawHPBar(void)
{
    OverrideHPBarPalette();
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        DrawHPBar(&sMonSummaryScreen->currentMon);
}

static void SwitchToMoveSelection(u8 taskId)
{
    sMonSummaryScreen->firstMoveIndex = 0;

    if (!sMonSummaryScreen->lockMovesFlag)
    {
        ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
        PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_SWITCH);
    }

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
    {
        CreateTask(Task_ShowBattleMovesTilemap, 1);
    }
    else
    {
        CreateTask(Task_ShowContestMovesTilemap, 1);
    }

    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void Task_HandleInput_MoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 4;
            ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 4;
            ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->lockMovesFlag == TRUE
             || (sMonSummaryScreen->newMove == MOVE_NONE && sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES))
            {
                PlaySE(SE_SELECT);
                CloseMoveSelectMode(taskId);
            }
            else if (HasMoreThanOneMove() == TRUE)
            {
                PlaySE(SE_SELECT);
                SwitchToMovePositionSwitchMode(taskId);
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseMoveSelectMode(taskId);
        }
    }
}

static bool8 HasMoreThanOneMove(void)
{
    u8 i;
    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (sMonSummaryScreen->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr)
{
    s8 i, newMoveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    newMoveIndex = *moveIndexPtr;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        newMoveIndex += direction;
        if (newMoveIndex > taskData[0])
            newMoveIndex = 0;
        else if (newMoveIndex < 0)
            newMoveIndex = taskData[0];

        if (newMoveIndex == MAX_MON_MOVES)
        {
            move = sMonSummaryScreen->newMove;
            break;
        }
        move = sMonSummaryScreen->summary.moves[newMoveIndex];
        if (move != 0)
            break;
    }

    PrintMoveDetails(move);

    *moveIndexPtr = newMoveIndex;
    // Get rid of the 'flicker' effect(while idle) when scrolling.
    if (moveIndexPtr == &sMonSummaryScreen->firstMoveIndex)
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR1);
    else
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR2);
}

static void CloseMoveSelectMode(u8 taskId)
{
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_SWITCH);
    PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
    PrintMoveDetails(MOVE_NONE);
    sMonSummaryScreen->mode = BW_SUMMARY_MODE_NORMAL;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        CreateTask(Task_HideBattleMovesTilemap, 1);
    else
        CreateTask(Task_HideContestMovesTilemap, 1);

    ShowBg(1);
    ShowBg(2);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);

    gTasks[taskId].func = Task_HandleInput;
}

static void SwitchToMovePositionSwitchMode(u8 taskId)
{
    sMonSummaryScreen->secondMoveIndex = sMonSummaryScreen->firstMoveIndex;
    SetMainMoveSelectorColor(1);
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);
    gTasks[taskId].func = Task_HandleInput_MovePositionSwitch;
}

static void Task_HandleInput_MovePositionSwitch(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->firstMoveIndex == sMonSummaryScreen->secondMoveIndex)
                ExitMovePositionSwitchMode(taskId, FALSE);
            else
                ExitMovePositionSwitchMode(taskId, TRUE);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ExitMovePositionSwitchMode(taskId, FALSE);
        }
    }
}

static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves)
{
    u16 move;

    PlaySE(SE_SELECT);
    SetMainMoveSelectorColor(0);
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);

    if (swapMoves == TRUE)
    {
        if (!sMonSummaryScreen->isBoxMon)
        {
            struct Pokemon *mon = sMonSummaryScreen->monList.mons;
            SwapMonMoves(&mon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
            SwapBoxMonMoves(&boxMon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        SwapMovesNamesPP(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        SwapMovesTypeSprites(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        sMonSummaryScreen->firstMoveIndex = sMonSummaryScreen->secondMoveIndex;
    }

    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
    PrintMoveDetails(move);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void Task_SetHandleReplaceMoveInput(u8 taskId)
{
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleReplaceMoveInput;
}

static void Task_HandleReplaceMoveInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (gPaletteFade.active != TRUE)
        {
            if (JOY_NEW(DPAD_UP))
            {
                data[0] = 4;
                ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                data[0] = 4;
                ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
            {
                ChangePage(taskId, -1);
            }
            else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
            {
                ChangePage(taskId, 1);
            }
            else if (JOY_NEW(A_BUTTON))
            {
                if (CanReplaceMove() == TRUE)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    sMoveSlotToReplace = sMonSummaryScreen->firstMoveIndex;
                    gSpecialVar_0x8005 = sMoveSlotToReplace;
                    BeginCloseSummaryScreen(taskId);
                }
                else
                {
                    PlaySE(SE_FAILURE);
                    ShowCantForgetHMsWindow(taskId);
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                sMoveSlotToReplace = MAX_MON_MOVES;
                gSpecialVar_0x8005 = MAX_MON_MOVES;
                BeginCloseSummaryScreen(taskId);
            }
        }
    }
}

static bool8 CanReplaceMove(void)
{
    if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES
        || sMonSummaryScreen->newMove == MOVE_NONE
        || IsMoveHM(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]) != TRUE)
        return TRUE;
    else
        return FALSE;
}

static void ShowCantForgetHMsWindow(u8 taskId)
{
    PrintHMMovesCantBeForgotten();
    gTasks[taskId].func = Task_HandleInputCantForgetHMsMoves;
}

// This redraws the power/accuracy window when the player scrolls out of the "HM Moves can't be forgotten" message
static void Task_HandleInputCantForgetHMsMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 move;
    if (FuncIsActiveTask(Task_ShowBattleMovesTilemap) != 1 && FuncIsActiveTask(Task_ShowContestMovesTilemap) != 1)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_BATTLE_MOVES)
            {
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, -1);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_CONTEST_MOVES)
            {
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, 1);
            }
        }
        else if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
            PrintMoveDetails(move);
            ScheduleBgCopyTilemapToVram(0);
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
    }
}

u8 GetMoveSlotToReplace_BW(void)
{
    return sMoveSlotToReplace;
}

#define tMoveTaskState data[2]

static void Task_ShowBattleMovesTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    // switch new map into buffer
    if (tMoveTaskState == 0)
    {
        SetBgTilemapBuffer(1, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_BATTLE_EFFECTS][0]);
        ShowBg(1);
        ScheduleBgCopyTilemapToVram(1);
        tMoveTaskState++;
    }
    // change bg offset and priorities
    else if (tMoveTaskState == 1)
    {
        ChangeBgX(1, 0x10000, BG_COORD_SET);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.priority = 2;
        ShowBg(1);
        ShowBg(2);
        ScheduleBgCopyTilemapToVram(2);
        tMoveTaskState++;
    }
    // slide into frame
    else if (tMoveTaskState <= 9)
    {
        ChangeBgX(1, 0x2000, BG_COORD_ADD);
        tMoveTaskState++;
    }
    // finish sliding and print info
    else
    {
        PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        PrintNewMoveDetailsOrCancelText();
        SetNewMoveTypeIcon();
        PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        DestroyTask(taskId);
    }
}

static void Task_HideBattleMovesTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowId;

    // wait for showing task to finish
    if (FuncIsActiveTask(Task_ShowBattleMovesTilemap))
        return;

    // clean up the windows and text on the first pass
    if (tMoveTaskState == 0)
    {
        ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
        ClearWindowTilemap(windowId);
        ClearCancelText();
        if (BW_SUMMARY_CATEGORY_ICONS)
            DestroyCategoryIcon();
    }

    // slide out of frame
    if (tMoveTaskState < 8)
    {
        ChangeBgX(1, 0x2000, BG_COORD_SUB);
        tMoveTaskState++;
    }
    // finish sliding out, buffer tilemap and reset priorities
    else if (tMoveTaskState == 8)
    {
        SetBgTilemapBuffer(1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][0]);
        ChangeBgX(1, 0x10000, BG_COORD_SET);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 1);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.priority = 1;
        tMoveTaskState++;
    }
    // show bgs and end task
    else
    {
        ScheduleBgCopyTilemapToVram(1);
        ShowBg(1);
        ShowBg(2);
        DestroyTask(taskId);
    }
}

static void Task_ShowContestMovesTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    // switch new map into buffer
    if (tMoveTaskState == 0)
    {
        SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0]);
        ShowBg(2);
        ScheduleBgCopyTilemapToVram(2);
        tMoveTaskState++;
    }
    // change bg offset and priorities
    else if (tMoveTaskState == 1)
    {
        ChangeBgX(2, 0x10000, BG_COORD_SET);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.priority = 2;
        ShowBg(1);
        ShowBg(2);
        ScheduleBgCopyTilemapToVram(1);
        tMoveTaskState++;
    }
    // slide into frame
    else if (tMoveTaskState <= 9)
    {
        ChangeBgX(2, 0x2000, BG_COORD_ADD);
        tMoveTaskState++;
    }
    // finish sliding and print info
    else
    {
        PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        PrintNewMoveDetailsOrCancelText();
        SetNewMoveTypeIcon();
        DestroyTask(taskId);
    }
}

static void Task_HideContestMovesTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowId;
    
    // wait for showing task to finish
    if (FuncIsActiveTask(Task_ShowContestMovesTilemap))
        return;

    // clean up the windows and text on the first pass
    if (tMoveTaskState == 0)
    {
        windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
        ClearWindowTilemap(windowId);
        ClearCancelText();
    }

    // slide out of frame
    if (tMoveTaskState < 8)
    {
        ChangeBgX(2, 0x2000, BG_COORD_SUB);
        tMoveTaskState++;
    }
    // change bg offset and priorities
    else if (tMoveTaskState == 8)
    {
        SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
        ChangeBgX(2, 0x10000, BG_COORD_SET);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.priority = 1;
        tMoveTaskState++;
    }
    // finish sliding out and reset bgs
    else
    {
        ScheduleBgCopyTilemapToVram(2);
        ShowBg(1);
        ShowBg(2);
        DestroyTask(taskId);
    }
}

#undef tMoveTaskState

#define POINTS_PER_HEART            10

#define TILEMAP_APPEAL_ROW_START    0x176
#define TILEMAP_JAM_ROW_1_START     0x196
#define TILEMAP_JAM_ROW_2_START     0x1B6

#define TILE_EMPTY_HEART_TOP        0x00FE
#define TILE_EMPTY_HEART_MIDDLE     0x0102
#define TILE_EMPTY_HEART_BOTTOM     0x010A

#define TILE_APPEAL_HEART_TOP       0x4123

#define TILE_JAM_HEART_MIDDLE       0x40E0
#define TILE_JAM_HEART_BOTTOM       0x40EB


static void HandleAppealJamTilemap(u16 move)
{
    u16 *dst1, *dst2;
    u8 i;
    u8 appeal = 0;
    u8 jam = 0;

    if (move != MOVE_NONE)
    {
        appeal = gContestEffects[gMovesInfo[move].contestEffect].appeal;
        jam = gContestEffects[gMovesInfo[move].contestEffect].jam;
    }

    // handle appeal
    dst1 = &sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0][TILEMAP_APPEAL_ROW_START];
    for (i = 0; i < MAX_CONTEST_MOVE_HEARTS; i++)
    {
        if (appeal > 0)
        {
            dst1[i] = TILE_APPEAL_HEART_TOP;
            appeal -= POINTS_PER_HEART;
        }
        else
        {
            dst1[i] = TILE_EMPTY_HEART_TOP;
        }
    }

    // handle jam
    dst1 = &sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0][TILEMAP_JAM_ROW_1_START];
    dst2 = &sMonSummaryScreen->bgTilemapBuffers[PSS_BUFFER_CONTEST_EFFECTS][0][TILEMAP_JAM_ROW_2_START];
    for (i = 0; i < MAX_CONTEST_MOVE_HEARTS; i++)
    {
        if (jam > 0)
        {
            dst1[i] = TILE_JAM_HEART_MIDDLE;
            dst2[i] = TILE_JAM_HEART_BOTTOM;
            jam -= POINTS_PER_HEART;
        }
        else
        {
            dst1[i] = TILE_EMPTY_HEART_MIDDLE;
            dst2[i] = TILE_EMPTY_HEART_BOTTOM;
        }
    }

    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        ScheduleBgCopyTilemapToVram(3);
    else
        ScheduleBgCopyTilemapToVram(2);
}

#define HP_BAR_TILEMAP_START_ROW_1 0x069
#define HP_BAR_TILEMAP_START_ROW_2 0x089
#define HP_BAR_TILE_EMPTY_ROW_1    0x50C7
#define HP_BAR_TILE_FULL_ROW_1     0x50CF
#define HP_BAR_TILE_EMPTY_ROW_2    0x50D7
#define HP_BAR_TILE_FULL_ROW_2     0x50DF

static void DrawHPBar(struct Pokemon *unused)
{
    s64 numHPBarTicks;
    u16 *dst1, *dst2;
    u8 i;

    if (sMonSummaryScreen->summary.currentHP > 0)
    {
        // Calculate the number of 1-pixel "ticks" to illuminate in the HP bar.
        // There are 8 tiles that make up the bar, and each tile has 8 "ticks". Hence, the numerator
        // is multiplied by 64.
        numHPBarTicks = sMonSummaryScreen->summary.currentHP * 64 / sMonSummaryScreen->summary.maxHP;
        if (numHPBarTicks == 0 && sMonSummaryScreen->summary.currentHP != 0)
            numHPBarTicks = 1;
    }
    else
    {
        numHPBarTicks = 0;
    }

    dst1 = &sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][1][HP_BAR_TILEMAP_START_ROW_1];
    dst2 = &sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][1][HP_BAR_TILEMAP_START_ROW_2];
    for (i = 0; i < 8; i++)
    {
        if (numHPBarTicks > 7)
        {
            dst1[i] = HP_BAR_TILE_FULL_ROW_1;
            dst2[i] = HP_BAR_TILE_FULL_ROW_2;
        }
        else
        {
            dst1[i] = HP_BAR_TILE_EMPTY_ROW_1 + (numHPBarTicks % 8);
            dst2[i] = HP_BAR_TILE_EMPTY_ROW_2 + (numHPBarTicks % 8);
        }

        numHPBarTicks -= 8;
        if (numHPBarTicks < 0)
            numHPBarTicks = 0;
    }

    if (GetBgTilemapBuffer(1) == sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][0])
        ScheduleBgCopyTilemapToVram(1);
    else
        ScheduleBgCopyTilemapToVram(2);

}

#define HP_BAR_TILE_PAL                 5
#define HP_BAR_PAL_SLOT_LIGHT_COLOR     3
#define HP_BAR_PAL_SLOT_DARK_COLOR      4
#define HP_BAR_LIGHT_GREEN              RGB(14, 31, 21)
#define HP_BAR_DARK_GREEN               RGB(11, 26, 16)
#define HP_BAR_LIGHT_YELLOW             RGB(31, 28,  7)
#define HP_BAR_DARK_YELLOW              RGB(25, 21,  1)
#define HP_BAR_LIGHT_RED                RGB(31, 11,  7)
#define HP_BAR_DARK_RED                 RGB(21,  8,  9)

static void OverrideHPBarPalette(void)
{
    u16 palColor;
    u16 hpRatio = (sMonSummaryScreen->summary.currentHP * 100) / (sMonSummaryScreen->summary.maxHP);

    if (hpRatio <= 20)
    {
        palColor = HP_BAR_LIGHT_RED;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_LIGHT_COLOR, PLTT_SIZEOF(1));
        palColor = HP_BAR_DARK_RED;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_DARK_COLOR, PLTT_SIZEOF(1));
    }
    else if (hpRatio <= 50)
    {
        palColor = HP_BAR_LIGHT_YELLOW;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_LIGHT_COLOR, PLTT_SIZEOF(1));
        palColor = HP_BAR_DARK_YELLOW;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_DARK_COLOR, PLTT_SIZEOF(1));
    } else {
        palColor = HP_BAR_LIGHT_GREEN;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_LIGHT_COLOR, PLTT_SIZEOF(1));
        palColor = HP_BAR_DARK_GREEN;
        LoadPalette(&palColor, BG_PLTT_ID(HP_BAR_TILE_PAL) + HP_BAR_PAL_SLOT_DARK_COLOR, PLTT_SIZEOF(1));
    }
}

#define EXP_BAR_TILEMAP_START 0x1F4
#define EXP_BAR_TILE_EMPTY    0x20E1
#define EXP_BAR_TILE_FULL     0x20E9

static void DrawExperienceProgressBar(struct Pokemon *unused)
{
    s64 numExpProgressBarTicks;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 *dst;
    u8 i;

    if (summary->level < MAX_LEVEL)
    {
        u32 expBetweenLevels = gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level + 1] - gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level];
        u32 expSinceLastLevel = summary->exp - gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level];

        // Calculate the number of 1-pixel "ticks" to illuminate in the experience progress bar.
        // There are 8 tiles that make up the bar, and each tile has 8 "ticks". Hence, the numerator
        // is multiplied by 64.
        numExpProgressBarTicks = expSinceLastLevel * 64 / expBetweenLevels;
        if (numExpProgressBarTicks == 0 && expSinceLastLevel != 0)
            numExpProgressBarTicks = 1;
    }
    else
    {
        numExpProgressBarTicks = 0;
    }

    dst = &sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][1][EXP_BAR_TILEMAP_START];
    for (i = 0; i < 8; i++)
    {
        if (numExpProgressBarTicks > 7)
            dst[i] = EXP_BAR_TILE_FULL;
        else
            dst[i] = EXP_BAR_TILE_EMPTY + (numExpProgressBarTicks % 8);
        numExpProgressBarTicks -= 8;
        if (numExpProgressBarTicks < 0)
            numExpProgressBarTicks = 0;
    }

    if (GetBgTilemapBuffer(1) == sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][0])
        ScheduleBgCopyTilemapToVram(1);
    else
        ScheduleBgCopyTilemapToVram(2);
}

static void ResetWindows(void)
{
    u8 i;

    InitWindows(sSummaryTemplate);
    DeactivateAllTextPrinters();
    for (i = 0; i < PSS_LABEL_WINDOW_END; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        sMonSummaryScreen->windowIds[i] = WINDOW_NONE;
}

static void PrintTextOnWindowWithFont(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 fontId)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, FONT_SHORT);
}

// a different variation of FONT_SHORT (FONT_BW_SUMMARY_SCREEN) is used in places where the lines
// need to be compressed more vertically
static void PrintTextOnWindow_BW_Font(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, FONT_BW_SUMMARY_SCREEN);
}

static void PrintTextOnWindowToFitPx(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 width)
{
    u32 fontId = GetFontIdToFit(string, FONT_SHORT, 0, width);
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, fontId);
}

static void PrintTextOnWindowToFitPx_WithFont(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 fontId, u32 width)
{
    u32 font = GetFontIdToFit(string, fontId, 0, width);
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, font);
}

static void PrintMonPortraitInfo(void)
{
    FillWindowPixelBuffer(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, PIXEL_FILL(0));
    if (!sMonSummaryScreen->summary.isEgg)
        PrintNotEggInfo();
    else
        PrintEggInfo();
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNotEggInfo(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    // print nickname
    GetMonNickname(mon, gStringVar1);
    PrintTextOnWindowToFitPx(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, gStringVar1, 5, 2, 0, 0, WindowWidthPx(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL) - 9);

    //print gender
    PrintGenderSymbol(mon, summary->species2);

    // print level
    StringCopy(gStringVar1, gText_LevelSymbol);
    ConvertIntToDecimalStringN(gStringVar2, summary->level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar1, gStringVar2);

    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, gStringVar1, 5, 13, 0, 0);
    PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL);
}

static void PrintEggInfo(void)
{
    GetMonNickname(&sMonSummaryScreen->currentMon, gStringVar1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, gStringVar1, 5, 2, 0, 0);
    PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL);
}

static void PrintGenderSymbol(struct Pokemon *mon, u16 species)
{
    if (species != SPECIES_NIDORAN_M && species != SPECIES_NIDORAN_F)
    {
        switch (GetMonGender(mon))
        {
        case MON_MALE:
            PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, gText_MaleSymbol, 70, 1, 0, 3);
            break;
        case MON_FEMALE:
            PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME_GENDER_LEVEL, gText_FemaleSymbol, 70, 1, 0, 4);
            break;
        }
    }
}

static void PrintAOrBButtonIcon(u8 windowId, bool8 bButton, u32 x)
{
    const u8 *button;
    if (!bButton)
        button = sButtons_Gfx[0];
    else
        button = sButtons_Gfx[1];

    BlitBitmapToWindow(windowId, button, x, 0, 16, 16);
}

static void PrintPageNamesAndStats(void)
{
    int stringXPos;
    int iconXPos;
    int skillsLabelWidth = 78;

    PrintTextOnWindow(PSS_LABEL_WINDOW_POKEMON_INFO_TITLE, sText_PkmnInfo, 2, 1, 0, 1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE, sText_PkmnSkills, 2, 1, 0, 1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE, sText_BattleMoves, 2, 1, 0, 1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_CONTEST_MOVES_TITLE, sText_ContestMoves, 2, 1, 0, 1);

    stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_Cancel, 62);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_CANCEL, FALSE, iconXPos);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_CANCEL, sText_Cancel, stringXPos, 1, 0, 1);

    stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_Info, 62);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_INFO, FALSE, iconXPos);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_INFO, sText_Info, stringXPos, 1, 0, 1);

    stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_Switch, 62);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_SWITCH, FALSE, iconXPos);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_SWITCH, sText_Switch, stringXPos, 1, 0, 1);

    if (BW_SUMMARY_IV_EV_DISPLAY != BW_IV_EV_HIDDEN)
    {
        if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
        {
            stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_ViewIVs_Graded, skillsLabelWidth);
            iconXPos = stringXPos - 16;
            if (iconXPos < 0)
                iconXPos = 0;
            PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_IVS, FALSE, iconXPos);
            PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_IVS, sText_ViewIVs_Graded, stringXPos, 1, 0, 1);

            stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_ViewEVs_Graded, skillsLabelWidth);
            iconXPos = stringXPos - 16;
            if (iconXPos < 0)
                iconXPos = 0;
            PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_EVS, FALSE, iconXPos);
            PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_EVS, sText_ViewEVs_Graded, stringXPos, 1, 0, 1);
        }
        else // precise display
        {
            stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_ViewIVs, skillsLabelWidth);
            iconXPos = stringXPos - 16;
            if (iconXPos < 0)
                iconXPos = 0;
            PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_IVS, FALSE, iconXPos);
            PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_IVS, sText_ViewIVs, stringXPos, 1, 0, 1);

            stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_ViewEVs, skillsLabelWidth);
            iconXPos = stringXPos - 16;
            if (iconXPos < 0)
                iconXPos = 0;
            PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_EVS, FALSE, iconXPos);
            PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_EVS, sText_ViewEVs, stringXPos, 1, 0, 1);
        }

        stringXPos = GetStringRightAlignXOffset(FONT_NORMAL, sText_ViewStats, skillsLabelWidth);
        iconXPos = stringXPos - 16;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintAOrBButtonIcon(PSS_LABEL_WINDOW_PROMPT_STATS, FALSE, iconXPos);
        PrintTextOnWindow(PSS_LABEL_WINDOW_PROMPT_STATS, sText_ViewStats, stringXPos, 1, 0, 1);
    }

    PrintTextOnWindow(PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP, sText_NextLv, 0, 4, 0, 0);
}

static void PutPageWindowTilemaps(u8 page)
{
    u8 i;

    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_INFO_TITLE);
    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE);
    ClearWindowTilemap(PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE);
    ClearWindowTilemap(PSS_LABEL_WINDOW_CONTEST_MOVES_TITLE);

    switch (page)
    {
    case PSS_PAGE_INFO:
        PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_INFO_TITLE);
        PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_CANCEL);
        break;
    case PSS_PAGE_SKILLS:
        PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE);
        PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP);
        if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_PRECISE)
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
        else if (BW_SUMMARY_IV_EV_DISPLAY == BW_IV_EV_GRADED)
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
        break;
    case PSS_PAGE_BATTLE_MOVES:
        PutWindowTilemap(PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE);
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        }
        else
        {
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
        }
        break;
    case PSS_PAGE_CONTEST_MOVES:
        PutWindowTilemap(PSS_LABEL_WINDOW_CONTEST_MOVES_TITLE);
        if (sMonSummaryScreen->mode != BW_SUMMARY_MODE_SELECT_MOVE)
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        PutWindowTilemap(sMonSummaryScreen->windowIds[i]);

    ScheduleBgCopyTilemapToVram(0);
}

static void ClearPageWindowTilemaps(u8 page)
{
    u8 i;

    switch (page)
    {
    case PSS_PAGE_INFO:
        ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_CANCEL);
        break;
    case PSS_PAGE_SKILLS:
        ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP);
        if (BW_SUMMARY_IV_EV_DISPLAY != BW_IV_EV_HIDDEN)
        {
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
        }
        break;
    case PSS_PAGE_BATTLE_MOVES:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        }
        else
        {
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
        }
        break;
    case PSS_PAGE_CONTEST_MOVES:
        if (sMonSummaryScreen->mode != BW_SUMMARY_MODE_SELECT_MOVE)
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_INFO);
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        RemoveWindowByIndex(i);

    ScheduleBgCopyTilemapToVram(0);
}

static u8 AddWindowFromTemplateList(const struct WindowTemplate *template, u8 templateId)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[templateId];
    if (*windowIdPtr == WINDOW_NONE)
    {
        *windowIdPtr = AddWindow(&template[templateId]);
        FillWindowPixelBuffer(*windowIdPtr, PIXEL_FILL(0));
    }
    return *windowIdPtr;
}

static void RemoveWindowByIndex(u8 windowIndex)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[windowIndex];
    if (*windowIdPtr != WINDOW_NONE)
    {
        ClearWindowTilemap(*windowIdPtr);
        RemoveWindow(*windowIdPtr);
        *windowIdPtr = WINDOW_NONE;
    }
}

static void PrintPageSpecificText(u8 pageIndex)
{
    u16 i;
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
    {
        if (sMonSummaryScreen->windowIds[i] != WINDOW_NONE)
            FillWindowPixelBuffer(sMonSummaryScreen->windowIds[i], PIXEL_FILL(0));
    }
    sTextPrinterFunctions[pageIndex]();
}

static void CreateTextPrinterTask(u8 pageIndex)
{
    CreateTask(sTextPrinterTasks[pageIndex], 16);
}

static void PrintInfoPageText(void)
{
    if (sMonSummaryScreen->summary.isEgg)
    {
        PrintEggOTName();
        PrintEggOTID();
        PrintMonDexNumberSpecies();
        PrintEggState();
        PrintEggMemo();
    }
    else
    {
        PrintMonOTName();
        PrintMonOTID();
        PrintMonDexNumberSpecies();
        PrintHeldItemName();
        BufferMonTrainerMemo();
        PrintMonTrainerMemo();
    }
}

static void Task_PrintInfoPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 1:
        PrintMonOTName();
        break;
    case 2:
        PrintMonOTID();
        break;
    case 3:
        PrintMonDexNumberSpecies();
        break;
    case 4:
        PrintHeldItemName();
        break;
    case 5:
        BufferMonTrainerMemo();
        break;
    case 6:
        PrintMonTrainerMemo();
        break;
    case 7:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintMonDexNumberSpecies(void)
{
    int windowId;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    u16 dexNum = SpeciesToPokedexNum(summary->species);
    windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_DEX_NUMBER_NAME);

    if (sMonSummaryScreen->summary.isEgg)
    {
        PrintTextOnWindow(windowId, gText_FiveMarks, 4, 12, 0, 0);
        PrintTextOnWindow(windowId, gText_FiveMarks, 4, 0, 0, 0);
    }
    else
    {
        PrintTextOnWindowToFitPx(windowId, GetSpeciesName(summary->species2), 4, 12, 0, 0, WindowWidthPx(windowId) - 9);

        if (dexNum != 0xFFFF)
        {
            u8 digitCount = (NATIONAL_DEX_COUNT > 999 && IsNationalPokedexEnabled()) ? 4 : 3;

            StringCopy(gStringVar1, &gText_NumberClear01[0]);
            ConvertIntToDecimalStringN(gStringVar2, dexNum, STR_CONV_MODE_LEADING_ZEROS, digitCount);
            StringAppend(gStringVar1, gStringVar2);
            ConvertIntToDecimalStringN(gStringVar1, dexNum, STR_CONV_MODE_LEADING_ZEROS, digitCount);

            if (!IsMonShiny(mon))
            {
                PrintTextOnWindow(windowId, gStringVar1, 4, 0, 0, 0);
                HandleMonShinyIcon(FALSE);
            }
            else
            {
                PrintTextOnWindow(windowId, gStringVar1, 4, 0, 0, 6);
                HandleMonShinyIcon(TRUE);
            }
        }
    }

}

static void HandleMonShinyIcon(bool8 isShiny)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY] != SPRITE_NONE)
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY]].invisible = !isShiny;
}

static void PrintMonOTName(void)
{
    int windowId;
    if (InBattleFactory() != TRUE && InSlateportBattleTent() != TRUE)
    {
        windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM);
        if (sMonSummaryScreen->summary.OTGender == 0)
            PrintTextOnWindow(windowId, sMonSummaryScreen->summary.OTName, 12, 4, 0, 5);
        else
            PrintTextOnWindow(windowId, sMonSummaryScreen->summary.OTName, 12, 4, 0, 6);
    }
    else
    {
        StringCopy(gStringVar1, sText_RentalPkmn);
        PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM), gStringVar1, 12, 4, 0, 0);
    }
}

static void PrintMonOTID(void)
{
    if (InBattleFactory() != TRUE && InSlateportBattleTent() != TRUE)
    {
        ConvertIntToDecimalStringN(gStringVar1, (u16)sMonSummaryScreen->summary.OTID, STR_CONV_MODE_LEADING_ZEROS, 5);
        PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM), gStringVar1, 12, 16, 0, 0);
    }
    else
    {
        StringCopy(gStringVar1, gText_FiveMarks);
        PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM), gStringVar1, 12, 16, 0, 0);
    }
}

static void PrintMonAbilityName(void)
{
    u16 ability = GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum);
    PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_ABILITY), gAbilitiesInfo[ability].name, 4, 2, 0, 0);
}

static void PrintMonAbilityDescription(void)
{
    u16 ability = GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum);
    PrintTextOnWindow_BW_Font(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_ABILITY), gAbilitiesInfo[ability].description, 4, 15, 0, 0);
}

static void BufferMonTrainerMemo(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    const u8 *text;
    bool32 locationFound = sum->metLocation < MAPSEC_NONE;

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sMemoNatureTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sMemoMiscTextColor);
    BufferNatureString();

    if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE || IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
    }
    else
    {
        u8 *metLevelString = Alloc(32);
        u8 *metLocationString = Alloc(32);
        GetMetLevelString(metLevelString);

        if (locationFound)
        {
            GetMapNameHandleAquaHideout(metLocationString, sum->metLocation);
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
        }

        text = gText_XNature;

        if (DoesMonOTMatchOwner() == TRUE)
        {
            if (sum->metLevel == 0)
                text = (!locationFound) ? gText_XNatureHatchedSomewhereAt : gText_XNatureHatchedAtYZ;
            else
                text = (!locationFound) ? gText_XNatureMetSomewhereAt : gText_XNatureMetAtYZ;
        }
        else if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            text = gText_XNatureFatefulEncounter;
        }
        else if (sum->metLocation != METLOC_IN_GAME_TRADE && DidMonComeFromGBAGames())
        {
            text = (!locationFound) ? gText_XNatureObtainedInTrade : gText_XNatureProbablyMetAt;
        }
        else
        {
            text = gText_XNatureObtainedInTrade;
        }

        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);

        Free(metLevelString);
        Free(metLocationString);
    }
}

static void PrintMonTrainerMemo(void)
{
    PrintTextOnWindow_BW_Font(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), gStringVar4, 16, 4, 0, 0);
}

static void BufferNatureString(void)
{
    struct PokemonSummaryScreenData *sumStruct = sMonSummaryScreen;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNaturesInfo[sumStruct->summary.nature].name);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gText_EmptyString5);
}

static void GetMetLevelString(u8 *output)
{
    u8 level = sMonSummaryScreen->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u32 trainerId;
    u8 gender;

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
        return FALSE;
    else
        return TRUE;
}

static bool8 DidMonComeFromGBAGames(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromRSE(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

static bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

static void PrintEggOTName(void)
{
    u32 windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM);
    PrintTextOnWindow(windowId, gText_FiveMarks, 12, 4, 0, 0);
}

static void PrintEggOTID(void)
{
    StringCopy(gStringVar1, gText_FiveMarks);
    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM), gStringVar1, 12, 16, 0, 0);
}

static void PrintEggState(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    if (sMonSummaryScreen->summary.sanity == TRUE)
        text = gText_EggWillTakeALongTime;
    else if (sum->friendship <= 5)
        text = gText_EggAboutToHatch;
    else if (sum->friendship <= 10)
        text = gText_EggWillHatchSoon;
    else if (sum->friendship <= 40)
        text = gText_EggWillTakeSomeTime;
    else
        text = gText_EggWillTakeALongTime;

    PrintTextOnWindow_BW_Font(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), text, 16, 4, 0, 0);
}

static void PrintEggMemo(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    if (sMonSummaryScreen->summary.sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
            text = gText_PeculiarEggNicePlace;
        else if (DidMonComeFromGBAGames() == FALSE || DoesMonOTMatchOwner() == FALSE)
            text = gText_PeculiarEggTrade;
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
            text = (DidMonComeFromRSE() == TRUE) ? gText_EggFromHotSprings : gText_EggFromTraveler;
        else
            text = gText_OddEggFoundByCouple;
    }
    else
    {
        text = gText_OddEggFoundByCouple;
    }

    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), text, 16, 28, 0, 0);
}

static void PrintSkillsPageText(void)
{
    //ravetodo handle ribbons
    //PrintRibbonCount();
    PrintMonAbilityName();
    PrintMonAbilityDescription();
    BufferHPStats();
    PrintHPStats(SKILL_STATE_STATS);
    BufferNonHPStats();
    PrintNonHPStats();
    PrintExpPointsNextLevel();
}

static void Task_PrintSkillsPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMonAbilityName();
        break;
    case 2:
        PrintMonAbilityDescription();
        break;
    case 3:
        BufferHPStats();
        break;
    case 4:
        PrintHPStats(SKILL_STATE_STATS);
        break;
    case 5:
        BufferNonHPStats();
        break;
    case 6:
        PrintNonHPStats();
        break;
    case 7:
        PrintExpPointsNextLevel();
        break;
    case 8:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintHeldItemName(void)
{
    const u8 *text;
    u32 fontId;

    if (sMonSummaryScreen->summary.item == ITEM_ENIGMA_BERRY_E_READER
        && IsMultiBattle() == TRUE
        && (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5))
    {
        text = ItemId_GetName(ITEM_ENIGMA_BERRY_E_READER);
    }
    else if (sMonSummaryScreen->summary.item == ITEM_NONE)
    {
        text = sText_None;
    }
    else
    {
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);
        text = gStringVar1;
    }

    fontId = GetFontIdToFit(text, FONT_SHORT, 0, WindowTemplateWidthPx(&sPageSkillsTemplate[PSS_DATA_WINDOW_INFO_OT_OTID_ITEM]) - 8);
    PrintTextOnWindowWithFont(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_INFO_OT_OTID_ITEM), text, 12, 28, 0, 0, fontId);
}

static void UNUSED PrintRibbonCount(void)
{
    const u8 *text;
    int x;

    if (sMonSummaryScreen->summary.ribbonCount == 0)
    {
        text = sText_None;
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, sMonSummaryScreen->summary.ribbonCount, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_RibbonsVar1);
        text = gStringVar4;
    }

    x = GetStringCenterAlignXOffset(FONT_NORMAL, text, 70) + 6;
    PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT), text, x, 1, 0, 0);
}

static void BufferStat(u8 *dst, s8 statIndex, u32 stat, u32 strId, u32 align)
{
    static const u8 sTextNatureDown[] = _("{COLOR}{08}");
    static const u8 sTextNatureUp[] = _("{COLOR}{05}");
    static const u8 sTextNatureNeutral[] = _("{COLOR}{01}");
    static const u8 sTextUpArrow[] = _(" {UP_ARROW}");
    static const u8 sTextDownArrow[] = _(" {DOWN_ARROW}");
    u8 *txtPtr;

    if (statIndex == 0 
        || !BW_SUMMARY_NATURE_COLORS 
        || gNaturesInfo[sMonSummaryScreen->summary.mintNature].statUp == gNaturesInfo[sMonSummaryScreen->summary.mintNature].statDown)
        txtPtr = StringCopy(dst, sTextNatureNeutral);
    else if (statIndex == gNaturesInfo[sMonSummaryScreen->summary.mintNature].statUp)
        txtPtr = StringCopy(dst, sTextNatureUp);
    else if (statIndex == gNaturesInfo[sMonSummaryScreen->summary.mintNature].statDown)
        txtPtr = StringCopy(dst, sTextNatureDown);
    else
        txtPtr = StringCopy(dst, sTextNatureNeutral);

    ConvertIntToDecimalStringN(txtPtr, stat, STR_CONV_MODE_RIGHT_ALIGN, align);

    if (statIndex != 0 
        && BW_SUMMARY_NATURE_ARROWS 
        && gNaturesInfo[sMonSummaryScreen->summary.mintNature].statUp != gNaturesInfo[sMonSummaryScreen->summary.mintNature].statDown)
    {
        if (statIndex == gNaturesInfo[sMonSummaryScreen->summary.mintNature].statUp)
            StringAppend(txtPtr, sTextUpArrow);
        else if (statIndex == gNaturesInfo[sMonSummaryScreen->summary.mintNature].statDown)
            StringAppend(txtPtr, sTextDownArrow);
    }

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(strId, dst);
}


static void BufferAndPrintStats_HandleState(u8 mode)
{
    u16 hp, hp2, atk, def, spA, spD, spe;
    u8 *currentHPString = Alloc(20);
    u8 *maxHPString = Alloc(20);

    switch (mode)
    {
    case SKILL_STATE_STATS:
    default:
        hp = sMonSummaryScreen->summary.currentHP;
        hp2 = sMonSummaryScreen->summary.maxHP;
        atk = sMonSummaryScreen->summary.atk;
        def = sMonSummaryScreen->summary.def;
        spA = sMonSummaryScreen->summary.spatk;
        spD = sMonSummaryScreen->summary.spdef;
        spe = sMonSummaryScreen->summary.speed;
        break;
    case SKILL_STATE_IVS:
        hp = sMonSummaryScreen->summary.ivHp;
        atk = sMonSummaryScreen->summary.ivAtk;
        def = sMonSummaryScreen->summary.ivDef;
        spA = sMonSummaryScreen->summary.ivSpatk;
        spD = sMonSummaryScreen->summary.ivSpdef;
        spe = sMonSummaryScreen->summary.ivSpeed;
        break;
    case SKILL_STATE_EVS:
        hp = sMonSummaryScreen->summary.evHp;
        atk = sMonSummaryScreen->summary.evAtk;
        def = sMonSummaryScreen->summary.evDef;
        spA = sMonSummaryScreen->summary.evSpatk;
        spD = sMonSummaryScreen->summary.evSpdef;
        spe = sMonSummaryScreen->summary.evSpeed;
        break;
    }

    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[PSS_DATA_WINDOW_SKILLS_STATS_HP], 0);
    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[PSS_DATA_WINDOW_SKILLS_STATS_NON_HP], 0);

    if (mode == SKILL_STATE_STATS)
    {
        ConvertIntToDecimalStringN(currentHPString, hp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(maxHPString, hp2, STR_CONV_MODE_RIGHT_ALIGN, 3);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currentHPString);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, maxHPString);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPLayout);
        PrintHPStats(mode);

        DynamicPlaceholderTextUtil_Reset();
        BufferStat(gStringVar1, STAT_ATK, atk, 0, 3);
        BufferStat(gStringVar2, STAT_DEF, def, 1, 3);
        BufferStat(gStringVar3, STAT_SPATK, spA, 2, 3);
        BufferStat(gStringVar4, STAT_SPDEF, spD, 3, 3);
        BufferStat(sStringVar5, STAT_SPEED, spe, 4, 3);
        PrintNonHPStats();
    }
    else
    {
        BufferStat(maxHPString, 0, hp, 0, 7);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, maxHPString);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPIVEVLayout);
        PrintHPStats(mode);

        BufferStat(gStringVar1, 0, atk, 0, 3);
        BufferStat(gStringVar2, 0, def, 1, 3);
        BufferStat(gStringVar3, 0, spA, 2, 3);
        BufferStat(gStringVar4, 0, spD, 3, 3);
        BufferStat(sStringVar5, 0, spe, 4, 3);
        PrintNonHPStats();
    }

    Free(currentHPString); 
    Free(maxHPString); 
}

static void BufferHPStats(void)
{
    u8 *currentHPString = Alloc(8);
    u8 *maxHPString = Alloc(8);

    ConvertIntToDecimalStringN(currentHPString, sMonSummaryScreen->summary.currentHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(maxHPString, sMonSummaryScreen->summary.maxHP, STR_CONV_MODE_RIGHT_ALIGN, 3);

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currentHPString);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, maxHPString);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPLayout);

    Free(currentHPString);
    Free(maxHPString);
}

static void PrintHPStats(u8 mode)
{
    if (mode == SKILL_STATE_STATS)
        PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS_HP), gStringVar4, 19, 0, 0, 0);
    else
        PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS_HP), gStringVar4, 6, 0, 0, 0);
}


static void BufferNonHPStats(void)
{
    DynamicPlaceholderTextUtil_Reset();
    BufferStat(gStringVar1, STAT_ATK, sMonSummaryScreen->summary.atk, 0, 3);
    BufferStat(gStringVar2, STAT_DEF, sMonSummaryScreen->summary.def, 1, 3);
    BufferStat(gStringVar3, STAT_SPATK, sMonSummaryScreen->summary.spatk, 2, 3);
    BufferStat(gStringVar4, STAT_SPDEF, sMonSummaryScreen->summary.spdef, 3, 3);
    BufferStat(sStringVar5, STAT_SPEED, sMonSummaryScreen->summary.speed, 4, 3);
}

static void PrintNonHPStats(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS_NON_HP);
    PrintTextOnWindow(windowId, gStringVar1, 30, 4, 0, 0);
    PrintTextOnWindow(windowId, gStringVar2, 30, 16, 0, 0);
    PrintTextOnWindow(windowId, gStringVar3, 30, 28, 0, 0);
    PrintTextOnWindow(windowId, gStringVar4, 30, 40, 0, 0);
    PrintTextOnWindow(windowId, sStringVar5, 30, 52, 0, 0);
}

static void PrintExpPointsNextLevel(void)
{
    u32 expToNextLevel;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u8 windowIdExp = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_EXP);
    u8 windowIdNextLvl = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_EXP_NEXT_LEVEL);

    // print exp
    ConvertIntToDecimalStringN(gStringVar1, sum->exp, STR_CONV_MODE_RIGHT_ALIGN, 7);
    PrintTextOnWindow(windowIdExp, gStringVar1, 45, 4, 0, 0);

    // print exp to next level
    if (sum->level < MAX_LEVEL)
        expToNextLevel = gExperienceTables[gSpeciesInfo[sum->species].growthRate][sum->level + 1] - sum->exp;
    else
        expToNextLevel = 0;

    ConvertIntToDecimalStringN(gStringVar1, expToNextLevel, STR_CONV_MODE_RIGHT_ALIGN, 6);

    PrintTextOnWindow(windowIdNextLvl, gStringVar1, 1, 4, 0, 0);
}

static void PrintBattleMoves(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE)
                PrintMoveDetails(sMonSummaryScreen->newMove);
        }
        else
        {
            PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        }
    }
}

static void Task_PrintBattleMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMoveNameAndPP(0);
        break;
    case 2:
        PrintMoveNameAndPP(1);
        break;
    case 3:
        PrintMoveNameAndPP(2);
        break;
    case 4:
        PrintMoveNameAndPP(3);
        break;
    case 5:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            PrintNewMoveDetailsOrCancelText();
        break;
    case 6:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                data[1] = sMonSummaryScreen->newMove;
            else
                data[1] = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
        }
        break;
    case 7:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PrintMoveDetails(data[1]);
        }
        break;
    case 8:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintMoveNameAndPP(u8 moveIndex)
{
    u8 pp;
    int ppState;
    const u8 *text;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 moveNameWindowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);
    u32 fontId = B_EXPANDED_MOVE_NAMES ? FONT_SMALL : FONT_SHORT;

    u16 move = summary->moves[moveIndex];

    if (move != 0)
    {
        PrintTextOnWindowToFitPx_WithFont(moveNameWindowId, GetMoveName(move), 3, moveIndex * 28 + 2, 0, 12, fontId, WindowWidthPx(moveNameWindowId) - 3);
        pp = CalculatePPWithBonus(move, summary->ppBonuses, moveIndex);
        ConvertIntToDecimalStringN(gStringVar1, summary->pp[moveIndex], STR_CONV_MODE_RIGHT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sMovesPPLayout);
        text = gStringVar4;
        ppState = GetCurrentPpToMaxPpState(summary->pp[moveIndex], pp) + 9;
    }
    else
    {
        PrintTextOnWindow(moveNameWindowId, gText_OneDash, 3, moveIndex * 28 + 2, 0, 12);
        text = gText_TwoDashes;
        ppState = 12;
    }

    PrintTextOnWindowWithFont(moveNameWindowId, text, 8, moveIndex * 28 + 16, 0, ppState, fontId);
}

static void PrintMovePowerAndAccuracy(u16 moveIndex)
{
    const u8 *text;
    FillWindowPixelRect(PSS_LABEL_WINDOW_MOVES_POWER_ACC, PIXEL_FILL(0), 2, 0, 19, 32);

    if (moveIndex != MOVE_NONE)
    {
        if (gMovesInfo[moveIndex].power < 2)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[moveIndex].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }

        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, 2, 4, 0, 0);

        if (gMovesInfo[moveIndex].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[moveIndex].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }

        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, 2, 16, 0, 0);
    } else {
        text = gText_ThreeDashes;
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, 2, 4, 0, 0);
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, 2, 16, 0, 0);
    }
}

static void PrintContestMoves(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        PrintContestMoveDescription(sMonSummaryScreen->firstMoveIndex);
    }
}

static void Task_PrintContestMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMoveNameAndPP(0);
        break;
    case 2:
        PrintMoveNameAndPP(1);
        break;
    case 3:
        PrintMoveNameAndPP(2);
        break;
    case 4:
        PrintMoveNameAndPP(3);
        break;
    case 5:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            PrintNewMoveDetailsOrCancelText();
        break;
    case 6:
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PrintContestMoveDescription(sMonSummaryScreen->firstMoveIndex);
        }
        break;
    case 7:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintContestMoveDescription(u8 moveSlot)
{
    u16 move;
    u8 desc[BW_MAX_MOVE_DESCRIPTION_LENGTH];
    u8 windowId;

    if (moveSlot == MAX_MON_MOVES)
        move = sMonSummaryScreen->newMove;
    else
        move = sMonSummaryScreen->summary.moves[moveSlot];

    if (move != MOVE_NONE)
    {
        windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
        FormatTextByWidth(desc, 119, FONT_BW_SUMMARY_SCREEN, gContestEffectDescriptionPointers[gMovesInfo[move].contestEffect], GetFontAttribute(FONT_BW_SUMMARY_SCREEN, FONTATTR_LETTER_SPACING));
        PrintTextOnWindow_BW_Font(windowId, desc, 2, 0, 0, 0);
    }
}

static void PrintMoveDetails(u16 move)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
    u8 desc[BW_MAX_MOVE_DESCRIPTION_LENGTH];
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    if (move != MOVE_NONE)
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            if (BW_SUMMARY_CATEGORY_ICONS)
                ShowCategoryIcon(move);

            PrintMovePowerAndAccuracy(move);

            if (BW_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS)
            {
                if (gMovesInfo[move].effect != EFFECT_PLACEHOLDER)
                    FormatTextByWidth(desc, 119, FONT_BW_SUMMARY_SCREEN, gMovesInfo[move].description, GetFontAttribute(FONT_BW_SUMMARY_SCREEN, FONTATTR_LETTER_SPACING));
                else
                    FormatTextByWidth(desc, 119, FONT_BW_SUMMARY_SCREEN, gNotDoneYetDescription, GetFontAttribute(FONT_BW_SUMMARY_SCREEN, FONTATTR_LETTER_SPACING));

                PrintTextOnWindow_BW_Font(windowId, desc, 2, 0, 0, 0);
            }
            else
            {
                if (gMovesInfo[move].effect != EFFECT_PLACEHOLDER)
                    PrintTextOnWindow_BW_Font(windowId, gMovesInfo[move].description, 2, 0, 0, 0);
                else
                    PrintTextOnWindow_BW_Font(windowId, gNotDoneYetDescription, 2, 0, 0, 0);
            }

        }
        else
        {
            HandleAppealJamTilemap(move);
            if (BW_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS)
            {
                FormatTextByWidth(desc, 119, FONT_BW_SUMMARY_SCREEN, gContestEffectDescriptionPointers[gMovesInfo[move].contestEffect], GetFontAttribute(FONT_BW_SUMMARY_SCREEN, FONTATTR_LETTER_SPACING));
                PrintTextOnWindow_BW_Font(windowId, desc, 2, 0, 0, 0);
            }
            else
            {
                PrintTextOnWindow_BW_Font(windowId, gContestEffectDescriptionPointers[gMovesInfo[move].contestEffect], 2, 0, 0, 0);
            }
        }
        PutWindowTilemap(windowId);
    }
    else
    {
        if (BW_SUMMARY_CATEGORY_ICONS)
            DestroyCategoryIcon();

        ClearWindowTilemap(windowId);
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            PrintMovePowerAndAccuracy(MOVE_NONE);
        else
            HandleAppealJamTilemap(MOVE_NONE);
    }

    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNewMoveDetailsOrCancelText(void)
{
    u8 windowId1 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);
    u32 fontId = B_EXPANDED_MOVE_NAMES ? FONT_SMALL : FONT_SHORT;

    if (sMonSummaryScreen->newMove == MOVE_NONE)
    {
        PrintTextOnWindow(windowId1, sText_Cancel, 0, 116, 0, 12);
    }
    else
    {
        u16 move = sMonSummaryScreen->newMove;

        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            PrintTextOnWindowToFitPx_WithFont(windowId1, GetMoveName(move), 3, 114, 0, 12, fontId, WindowWidthPx(windowId1) - 3);
        else
            PrintTextOnWindowToFitPx_WithFont(windowId1, GetMoveName(move), 3, 114, 0, 12, fontId, WindowWidthPx(windowId1) - 3);

        ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[move].pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar1);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sMovesPPLayout);
        PrintTextOnWindowWithFont(windowId1, gStringVar4, 8, 128, 0, 12, fontId);
    }
}

static void ClearCancelText(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);
    FillWindowPixelRect(windowId, PIXEL_FILL(0), 0, 116, 72, 16);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2)
{
    u8 windowId1 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);

    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 1, moveIndex1 * 28 + 3, 72, 24);
    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 1, moveIndex2 * 28 + 3, 72, 24);

    PrintMoveNameAndPP(moveIndex1);
    PrintMoveNameAndPP(moveIndex2);
}

static void PrintHMMovesCantBeForgotten(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    PrintTextOnWindow_BW_Font(windowId, gText_HMMovesCantBeForgotten2, 2, 0, 0, 0);
}

static void ShowCategoryIcon(u16 move)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] = CreateSprite(&sSpriteTemplate_CategoryIcons, 223, 96, 0);
    
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]].invisible = FALSE;

    if (IS_MOVE_SPECIAL(move))
        StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]], CATEGORY_ICON_SPECIAL);
    else if (IS_MOVE_PHYSICAL(move))
        StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]], CATEGORY_ICON_PHYSICAL);
    else
        StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]], CATEGORY_ICON_STATUS);
}

static void DestroyCategoryIcon(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] != SPRITE_NONE)
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]]);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] = SPRITE_NONE;
}

static void ShowGradeIcons(u8 mode)
{
    u32 i, y, divisor;
    u8 hp, atk, def, spatk, spdef, speed;

    for (i = SPRITE_ARR_ID_HP_GRADE; i <= SPRITE_ARR_ID_SPE_GRADE; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == SPRITE_NONE)
        {
            if (i == SPRITE_ARR_ID_HP_GRADE)
                y = 22;
            else
                y = 42 + (i - (SPRITE_ARR_ID_HP_GRADE + 1)) * 12;

            sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_StatGrades, 74, y, 0);

        }
        gSprites[sMonSummaryScreen->spriteIds[i]].invisible = FALSE;
    }

    if (mode == SKILL_STATE_IVS)
    {
        divisor = 2;
        hp = sMonSummaryScreen->summary.ivHp;
        atk = sMonSummaryScreen->summary.ivAtk;
        def = sMonSummaryScreen->summary.ivDef;
        spatk = sMonSummaryScreen->summary.ivSpatk;
        spdef = sMonSummaryScreen->summary.ivSpdef;
        speed = sMonSummaryScreen->summary.ivSpeed;
    }
    else
    {
        divisor = 16;
        hp = sMonSummaryScreen->summary.evHp;
        atk = sMonSummaryScreen->summary.evAtk;
        def = sMonSummaryScreen->summary.evDef;
        spatk = sMonSummaryScreen->summary.evSpatk;
        spdef = sMonSummaryScreen->summary.evSpdef;
        speed = sMonSummaryScreen->summary.evSpeed;
    }
    
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_HP_GRADE]], hp / divisor);
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ATK_GRADE]], atk / divisor);
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_DEF_GRADE]], def / divisor);
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPA_GRADE]], spatk / divisor);
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPD_GRADE]], spdef / divisor);
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPE_GRADE]], speed / divisor);
}

// idk, might need this, who knows :)
static void UNUSED DestroyGradeIcons(void)
{
    u32 i;
    for (i = SPRITE_ARR_ID_HP_GRADE; i <= SPRITE_ARR_ID_SPE_GRADE; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[i]]);
            sMonSummaryScreen->spriteIds[i] = SPRITE_NONE;
        }
    }
}

static void ResetSpriteIds(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        sMonSummaryScreen->spriteIds[i] = SPRITE_NONE;
}

static void DestroySpriteInArray(u8 spriteArrayId)
{
    if (sMonSummaryScreen->spriteIds[spriteArrayId] != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]]);
        sMonSummaryScreen->spriteIds[spriteArrayId] = SPRITE_NONE;
    }
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]].invisible = invisible;
}

static void HidePageSpecificSprites(void)
{
    // Keeps Pokemon, caught ball, and status sprites visible.
    u8 i;

    for (i = SPRITE_ARR_ID_POKERUS_CURED; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
    {
        if (sMonSummaryScreen->spriteIds[i] != SPRITE_NONE)
            SetSpriteInvisibility(i, TRUE);
    }
}

static void SetTypeIcons(void)
{
    switch (sMonSummaryScreen->currPageIndex)
    {
    case PSS_PAGE_INFO:
        SetMonTypeIcons();
        break;
    case PSS_PAGE_BATTLE_MOVES:
        SetMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    case PSS_PAGE_CONTEST_MOVES:
        SetContestMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    }
}

static void TrySetInfoPageIcons(void)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
    { 
        SetPokerusCuredSprite();
        if (BW_SUMMARY_SHOW_FRIENDSHIP)
            SetFriendshipSprite();
    }
}

static void CreateMoveTypeIcons(void)
{
    u8 i;

    for (i = SPRITE_ARR_ID_TERA_TYPE; i < SPRITE_ARR_ID_TYPE + TYPE_ICON_SPRITE_COUNT; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == SPRITE_NONE)
        {
            if (i == SPRITE_ARR_ID_TERA_TYPE)
            {
                if (P_SHOW_TERA_TYPE >= GEN_9)
                    sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_TeraType, 0, 0, 2);
            }
            else
            {
                sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_MoveTypes, 0, 0, 2);
            }
        }

        SetSpriteInvisibility(i, TRUE);
    }
}

static void SetTypeSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    if (typeId < NUMBER_OF_MON_TYPES)
        sprite->oam.paletteNum = gTypesInfo[typeId].palette;
    else
        sprite->oam.paletteNum = sContestCategoryToOamPaletteNum[typeId - NUMBER_OF_MON_TYPES];
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void SetMonTypeIcons(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    if (summary->isEgg)
    {
        SetTypeSpritePosAndPal(TYPE_MYSTERY, 68, 46, SPRITE_ARR_ID_TYPE);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        if (P_SHOW_TERA_TYPE >= GEN_9)
            SetSpriteInvisibility(SPRITE_ARR_ID_TERA_TYPE, TRUE);
    }
    else
    {
        SetTypeSpritePosAndPal(gSpeciesInfo[summary->species].types[0], 68, 46, SPRITE_ARR_ID_TYPE);
        if (gSpeciesInfo[summary->species].types[0] != gSpeciesInfo[summary->species].types[1])
        {
            SetTypeSpritePosAndPal(gSpeciesInfo[summary->species].types[1], 106, 46, SPRITE_ARR_ID_TYPE + 1);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
        }
        else
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        }
        if (P_SHOW_TERA_TYPE >= GEN_9)
        {
            SetTypeSpritePosAndPal(summary->teraType, 36, 47, SPRITE_ARR_ID_TERA_TYPE);
        }
    }
}

static void SetMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(gMovesInfo[summary->moves[i]].type, 8, 16 + (i * 28), i + SPRITE_ARR_ID_TYPE);
        else
            SetSpriteInvisibility(i + SPRITE_ARR_ID_TYPE, TRUE);
    }
}

static void SetContestMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gMovesInfo[summary->moves[i]].contestCategory, 8, 16 + (i * 28), i + SPRITE_ARR_ID_TYPE);
        else
            SetSpriteInvisibility(i + SPRITE_ARR_ID_TYPE, TRUE);
    }
}

static void SetNewMoveTypeIcon(void)
{
    if (sMonSummaryScreen->newMove == MOVE_NONE)
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 4, TRUE);
    }
    else
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            SetTypeSpritePosAndPal(gMovesInfo[sMonSummaryScreen->newMove].type, 8, 128, SPRITE_ARR_ID_TYPE + 4);
        else
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gMovesInfo[sMonSummaryScreen->newMove].contestCategory, 8, 128, SPRITE_ARR_ID_TYPE + 4);
    }
}

static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2)
{
    struct Sprite *sprite1 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex1 + SPRITE_ARR_ID_TYPE]];
    struct Sprite *sprite2 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex2 + SPRITE_ARR_ID_TYPE]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}

static u8 LoadMonGfxAndSprite(struct Pokemon *mon, s16 *state)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    switch (*state)
    {
    default:
        return CreateMonSprite(mon);
    case 0:
        if (gMain.inBattle)
        {
            HandleLoadSpecialPokePic(TRUE,
                                     gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_LEFT],
                                     summary->species2,
                                     summary->pid);
        }
        else
        {
            if (gMonSpritesGfxPtr != NULL)
            {
                HandleLoadSpecialPokePic(TRUE,
                                         gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_LEFT],
                                         summary->species2,
                                         summary->pid);
            }
            else
            {
                HandleLoadSpecialPokePic(TRUE,
                                         MonSpritesGfxManager_GetSpritePtr(MON_SPR_GFX_MANAGER_A, B_POSITION_OPPONENT_LEFT),
                                         summary->species2,
                                         summary->pid);
            }
        }
        (*state)++;
        return 0xFF;
    case 1:
        LoadCompressedSpritePaletteWithTag(GetMonSpritePalFromSpeciesAndPersonality(summary->species2, summary->isShiny, summary->pid), summary->species2);
        SetMultiuseSpriteTemplateToPokemon(summary->species2, B_POSITION_OPPONENT_LEFT);
        (*state)++;
        return 0xFF;
    }
}

static void PlayMonCry(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    if (!summary->isEgg)
    {
        if (ShouldPlayNormalMonCry(&sMonSummaryScreen->currentMon) == TRUE)
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_NORMAL);
        else
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_WEAK);
    }
}

static u8 CreateMonSprite(struct Pokemon *unused)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 204, 76, 5);

    FreeSpriteOamMatrix(&gSprites[spriteId]);
    gSprites[spriteId].data[0] = summary->species2;
    gSprites[spriteId].data[2] = 0;
    gSprites[spriteId].callback = SpriteCB_Pokemon;
    if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
        gSprites[spriteId].oam.priority = 2;
    else
        gSprites[spriteId].oam.priority = 0;

    if (!IsMonSpriteNotFlipped(summary->species2))
        gSprites[spriteId].hFlip = FALSE;
    else
        gSprites[spriteId].hFlip = TRUE;

    return spriteId;
}

static void SpriteCB_Pokemon(struct Sprite *sprite)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (!gPaletteFade.active && sprite->data[2] != 1)
    {
        sprite->data[1] = !IsMonSpriteNotFlipped(sprite->data[0]);
        PlayMonCry();
        PokemonSummaryDoMonAnimation(sprite, sprite->data[0], summary->isEgg);
    }
}

// Track and then destroy Task_PokemonSummaryAnimateAfterDelay
// Normally destroys itself but it can be interrupted before the animation starts
void SummaryScreen_SetAnimDelayTaskId_BW(u8 taskId)
{
    sAnimDelayTaskId = taskId;
}

static void SummaryScreen_DestroyAnimDelayTask(void)
{
    if (sAnimDelayTaskId != TASK_NONE)
    {
        DestroyTask(sAnimDelayTaskId);
        sAnimDelayTaskId = TASK_NONE;
    }
}

static bool32 UNUSED IsMonAnimationFinished(void)
{
    if (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

static void StopPokemonAnimations(void)  // A subtle effect, this function stops Pokémon animations when leaving the PSS
{
    u16 i;
    u16 paletteIndex;

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].animPaused = TRUE;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCallbackDummy;
    StopPokemonAnimationDelayTask();

    paletteIndex = OBJ_PLTT_ID(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.paletteNum);

    for (i = 0; i < 16; i++)
    {
        u16 id = i + paletteIndex;
        gPlttBufferUnfaded[id] = gPlttBufferFaded[id];
    }
}


static void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    struct Sprite *sprite = CreateMonMarkingAllCombosSprite(TAG_MON_MARKINGS, TAG_MON_MARKINGS, sMarkings_Pal_BW);

    sMonSummaryScreen->markingsSprite = sprite;
    if (sprite != NULL)
    {
        StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
        sMonSummaryScreen->markingsSprite->x = 19;
        sMonSummaryScreen->markingsSprite->y = 102;
        sMonSummaryScreen->markingsSprite->oam.priority = 3;
        if (sMonSummaryScreen->mode == BW_SUMMARY_MODE_SELECT_MOVE)
            sMonSummaryScreen->markingsSprite->invisible = TRUE;
    }
}

static void SetPokerusCuredSprite(void)
{
    struct Pokemon *mon;
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED] = CreateSprite(&sSpriteTemplate_PokerusCuredIcon, 40, 102, 0);

    mon = &sMonSummaryScreen->currentMon;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED]].invisible = (CheckPartyPokerus(mon, 0) || !CheckPartyHasHadPokerus(mon, 0));
}

static void SetFriendshipSprite(void)
{
    u8 level = FRIENDSHIP_LEVEL_0;
    
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP] = CreateSprite(&sSpriteTemplate_FriendshipIcon, 153, 25, 0);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP]].invisible = FALSE;
    
    // don't even think about swapping the order of the conditions here or the compiler will smite you for your arrogance
    // I have no idea why it works that way
    while (level < FRIENDSHIP_LEVEL_MAX && sMonSummaryScreen->summary.friendship >= sFriendshipLevelToThreshold[level + 1])
        level++;

    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP]], level);
}

static void CreateMonShinySprite(struct Pokemon *mon)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY] = CreateSprite(&sSpriteTemplate_ShinyIcon, 166, 48, 0);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY]].invisible = !IsMonShiny(mon);
}

static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(sMonSummaryScreen->markingsSprite);
    FreeSpriteTilesByTag(TAG_MON_MARKINGS);
    CreateMonMarkingsSprite(mon);
}

static void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = ItemIdToBallId(GetMonData(mon, MON_DATA_POKEBALL));

    LoadBallGfx(ball);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL] = CreateSprite(&gBallSpriteTemplates[ball], 233, 38, 0);
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].oam.priority = 1;
}

static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, 213, 38, 0);

    statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void HandleStatusSprite(struct Pokemon *mon)
{
    u8 statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void CreateMoveSelectorSprites(u8 idArrayStart)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[idArrayStart];

    if (sMonSummaryScreen->currPageIndex >= PSS_PAGE_BATTLE_MOVES)
    {
        u8 subpriority = 0;
        if (idArrayStart == SPRITE_ARR_ID_MOVE_SELECTOR1)
            subpriority = 1;

        for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        {
            spriteIds[i] = CreateSprite(&sMoveSelectorSpriteTemplate, i * 8 + 4, 34, subpriority);
            if (i == 0)
                StartSpriteAnim(&gSprites[spriteIds[i]], 4); // left
            else if (i == MOVE_SELECTOR_SPRITES_COUNT - 1)
                StartSpriteAnim(&gSprites[spriteIds[i]], 5); // right, actually the same as left, but flipped
            else
                StartSpriteAnim(&gSprites[spriteIds[i]], 6); // middle

            gSprites[spriteIds[i]].callback = SpriteCB_MoveSelector;
            gSprites[spriteIds[i]].data[0] = idArrayStart;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

static void SpriteCB_MoveSelector(struct Sprite *sprite)
{
    if (sprite->animNum > 3 && sprite->animNum < 7)
    {
        sprite->data[1] = (sprite->data[1] + 1) & 0x1F;
        if (sprite->data[1] > 24)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[1] = 0;
        sprite->invisible = FALSE;
    }

    if (sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR1)
        sprite->y2 = sMonSummaryScreen->firstMoveIndex * 28;
    else
        sprite->y2 = sMonSummaryScreen->secondMoveIndex * 28;
}

static void DestroyMoveSelectorSprites(u8 firstArrayId)
{
    u8 i;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        DestroySpriteInArray(firstArrayId + i);
}

static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];

    which *= 3;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        if (i == 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 4);
        else if (i == MOVE_SELECTOR_SPRITES_COUNT - 1)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 5);
        else
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 6);
    }
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[firstSpriteId];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}

// Shoutout to Vexx for this :)
static void FormatTextByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing)
{
    u8 *end, *ptr, *curLine, *lastSpace;

    end = result;
    // copy string, replacing all space and line breaks with EOS
    while (*str != EOS)
    {
        if (*str == CHAR_SPACE || *str == CHAR_NEWLINE)
            *end = EOS;
        else
            *end = *str;

        end++;
        str++;
    }
    *end = EOS; // now end points to the true end of the string

    ptr = result;
    curLine = ptr;

    while (*ptr != EOS)
        ptr++;
    // now ptr is the first EOS char

    while (ptr != end)
    {
        // all the EOS chars (except *end) must be replaced by either ' ' or '\n'
        lastSpace = ptr++; // this points at the EOS

        // check that adding the next word this line still fits
        *lastSpace = CHAR_SPACE;
        if (GetStringWidth(fontId, curLine, letterSpacing) > maxWidth)
        {
            *lastSpace = CHAR_NEWLINE;

            curLine = ptr;
        }

        while (*ptr != EOS)
            ptr++;
        // now ptr is the next EOS char
    }
}

#endif
