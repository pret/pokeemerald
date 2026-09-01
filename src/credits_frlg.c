#include "global.h"
#include "bg.h"
#include "credits_frlg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"
#include "constants/field_weather.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/sound.h"

#if IS_FRLG

#if defined(FIRERED)
#define TITLE_TEXT gString_PokemonFireRed_Staff
#else
#define TITLE_TEXT gString_PokemonLeafGreen_Staff
#endif

enum CreditsSceneIdx
{
    CREDITSSCENE_INIT_WIN0 = 0,
    CREDITSSCENE_SETUP_DARKEN_EFFECT,
    CREDITSSCENE_OPEN_WIN0,
    CREDITSSCENE_LOAD_PLAYER_SPRITE_AT_INDIGO,
    CREDITSSCENE_PRINT_TITLE_STAFF,
    CREDITSSCENE_WAIT_TITLE_STAFF,
    CREDITSSCENE_EXEC_CMD,
    CREDITSSCENE_PRINT_ADDPRINTER1,
    CREDITSSCENE_PRINT_ADDPRINTER2,
    CREDITSSCENE_PRINT_DELAY,
    CREDITSSCENE_MAPNEXT_DESTROYWINDOW,
    CREDITSSCENE_MAPNEXT_LOADMAP,
    CREDITSSCENE_MAP_LOADMAP_CREATESPRITES,
    CREDITSSCENE_MON_DESTROY_ASSETS,
    CREDITSSCENE_MON_SHOW,
    CREDITSSCENE_THEEND_DESTROY_ASSETS,
    CREDITSSCENE_THEEND_SHOW,
    CREDITSSCENE_WAITBUTTON,
    CREDITSSCENE_TERMINATE,
};

enum CreditsScrCmd
{
    CREDITSSCRCMD_PRINT = 0,
    CREDITSSCRCMD_MAPNEXT,
    CREDITSSCRCMD_MAP,
    CREDITSSCRCMD_MON,
    CREDITSSCRCMD_THEENDGFX,
    CREDITSSCRCMD_WAITBUTTON
};

enum CreditsMon
{
    CREDITSMON_CHARIZARD = 0,
    CREDITSMON_VENUSAUR,
    CREDITSMON_BLASTOISE,
    CREDITSMON_PIKACHU
};

enum CreditsClosingText
{
    CREDITSCLOSING_ALLRIGHTSRESERVED = 0,
    CREDITSCLOSING_THEEND
};

enum CreditsString
{
    CREDITS_STRING_DIRECTOR = 0,
    CREDITS_STRING_ART_DIRECTOR_BATTLE_DIRECTOR,
    CREDITS_STRING_PROGRAM_LEADER_PLANNING_LEADER_GRAPHIC_DESIGN_LEADER,
    CREDITS_STRING_PROGRAMMERS,
    CREDITS_STRING_SYSTEM_PROGRAMMERS,
    CREDITS_STRING_GRAPHIC_DESIGNERS,
    CREDITS_STRING_GRAPHIC_DESIGNERS_2,
    CREDITS_STRING_MUSIC_COMPOSITION,
    CREDITS_STRING_SOUND_EFFECTS,
    CREDITS_STRING_GAME_DESIGNERS,
    CREDITS_STRING_GAME_DESIGNERS_2,
    CREDITS_STRING_GAME_SCENARIO,
    CREDITS_STRING_SCRIPT_DESIGNER_MAP_DESIGNER,
    CREDITS_STRING_PARAMETRIC_DESIGNERS,
    CREDITS_STRING_POKEDEX_TEXT,
    CREDITS_STRING_POKEMON_DESIGNERS,
    CREDITS_STRING_POKEMON_DESIGNERS_2,
    CREDITS_STRING_POKEMON_DESIGNERS_3,
    CREDITS_STRING_SUPPORTING_PROGRAMMERS,
    CREDITS_STRING_NCL_PRODUCT_TESTING,
    CREDITS_STRING_SPECIAL_THANKS,
    CREDITS_STRING_SPECIAL_THANKS_2,
    CREDITS_STRING_SPECIAL_THANKS_3,
    CREDITS_STRING_BRAILLE_CODE_CHECK,
    CREDITS_STRING_INFORMATION_SUPERVISORS,
    CREDITS_STRING_COORDINATORS,
    CREDITS_STRING_TASK_MANAGERS,
    CREDITS_STRING_PRODUCERS,
    CREDITS_STRING_EXECUTIVE_DIRECTOR,
    CREDITS_STRING_EXECUTIVE_PRODUCER,
    CREDITS_STRING_EXECUTIVE_PRODUCER_2,
    CREDITS_STRING_ENGLISH_VERSION_COORDINATORS,
    CREDITS_STRING_TRANSLATOR_TEXT_EDITOR,
    CREDITS_STRING_PROGRAMMERS_2,
    CREDITS_STRING_ENVIRONMENT_TOOL_PROGRAMMERS,
    CREDITS_STRING_NOA_PRODUCT_TESTING,
    CREDITS_STRING_BRAILLE_CODE_CHECK_2,
    CREDITS_STRING_BRAILLE_CODE_CHECK_3,
    CREDITS_STRING_SPECIAL_THANKS_4,
    CREDITS_STRING_SPECIAL_THANKS_5,
    CREDITS_STRING_BRAILLE_CODE_CHECK_4,
    CREDITS_STRING_GRAPHIC_DESIGNER,
    CREDITS_STRING_END
};

enum CreditsMap
{
    CREDITS_MAP_ROUTE23 = 0,
    CREDITS_MAP_VIRIDIAN_CITY,
    CREDITS_MAP_PEWTER_CITY,
    CREDITS_MAP_CERULEAN_CITY,
    CREDITS_MAP_ROUTE25,
    CREDITS_MAP_VERMILION_CITY,
    CREDITS_MAP_ROUTE10,
    CREDITS_MAP_CELADON_CITY,
    CREDITS_MAP_SAFFRON_CITY,
    CREDITS_MAP_ROUTE17,
    CREDITS_MAP_FUCHSIA_CITY,
    CREDITS_MAP_CINNABAR_ISLAND,
    CREDITS_MAP_ROUTE21_NORTH
};

enum {
    GFXTAG_CHARACTER = 0x2000, // Player/Rival
    GFXTAG_GROUND,
};

struct CreditsResources
{
    u8 mainseqno;
    u8 subseqno;
    u8 taskId;
    u16 timer;
    u16 scrcmdidx;
    u8 canSpeedThrough;
    u8 whichMon;
    u8 windowId;
    bool8 windowIsActive;
    u16 creditsMonTimer;
    u16 unk_0E;
    u8 filler_10[12];
    u8 ovwldseqno;
    u8 unk_1D;
};

struct CreditsScrcmd
{
    u8 cmd;
    u8 param;
    u16 duration;
};

struct CreditsTextHeader
{
    const u8 * title;
    const u8 * names;
    bool8 unused;
};

struct CompressedGraphicsHeader
{
    const u8 * tiles;
    const u8 * map;
    const u16 * palette;
};

struct CreditsTaskData
{
    u8 spriteMoveCmd;
    u8 characterSpriteId; // Player or rival
    u16 characterTilesTag;
    u16 characterPalTag;
    u8 groundSpriteId;
    u16 groundTilesTag;
    u16 groundPalTag;
};

EWRAM_DATA bool8 gHasHallOfFameRecords = 0;
static EWRAM_DATA struct CreditsResources * sCreditsMgr = NULL;

static void CB2_Credits(void);
static s32 RollCredits(void);
static bool32 DoCreditsMonScene(void);
static bool32 DoCopyrightOrTheEndGfxScene(void);
static void DestroyPlayerOrRivalSprite(void);
static void LoadPlayerOrRivalSprite(u8 a0);

static const struct BgTemplate sBgTemplates_MonSceneOrTheEnd[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = FALSE,
        .priority = 0,
        .baseTile = 0x0
    }, {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = FALSE,
        .priority = 1,
        .baseTile = 0x0
    }, {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 1,
        .paletteMode = TRUE,
        .priority = 2,
        .baseTile = 0x0
    }
};

static const struct WindowTemplate sWindowTemplates_Charizard[] = {
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 6,
        .width = 8,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0008
    }, {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 5,
        .width = 10,
        .height = 10,
        .paletteNum = 10,
        .baseBlock = 0x0048
    }, {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 3,
        .width = 12,
        .height = 13,
        .paletteNum = 10,
        .baseBlock = 0x00ac
    }, DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplates_Venusaur[] = {
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 6,
        .width = 8,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0008
    }, {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 5,
        .width = 10,
        .height = 10,
        .paletteNum = 10,
        .baseBlock = 0x0048
    }, {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 5,
        .width = 12,
        .height = 10,
        .paletteNum = 10,
        .baseBlock = 0x00ac
    }, DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplates_Blastoise[] = {
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 6,
        .width = 8,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0008
    }, {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 5,
        .width = 10,
        .height = 10,
        .paletteNum = 10,
        .baseBlock = 0x0048
    }, {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 4,
        .width = 10,
        .height = 12,
        .paletteNum = 10,
        .baseBlock = 0x00ac
    }, DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplates_Pikachu[] = {
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 6,
        .width = 8,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0008
    }, {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 5,
        .width = 10,
        .height = 10,
        .paletteNum = 10,
        .baseBlock = 0x0048
    }, {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 4,
        .width = 12,
        .height = 12,
        .paletteNum = 10,
        .baseBlock = 0x00ac
    }, DUMMY_WIN_TEMPLATE
};



ALIGNED(4) const u8 gString_PokemonFireRed_Staff[] = _("Pokémon FireRed Version\nStaff");
ALIGNED(4) const u8 gString_PokemonLeafGreen_Staff[] = _("Pokémon LeafGreen Version\nStaff");
ALIGNED(4) const u8 gCreditsString_Director[] = _("\n\nDirector\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Junichi_Masuda[] = _("\n\n\nJunichi Masuda\n\n\n");
ALIGNED(4) const u8 gCreditsString_Art_Director_Battle_Director[] = _("\nArt Director\n\nBattle Director\n\n\n");
ALIGNED(4) const u8 gCreditsString_Ken_Sugimori_Shigeki_Morimoto[] = _("\n\nKen Sugimori\n\nShigeki Morimoto\n\n");
ALIGNED(4) const u8 gCreditsString_Program_Leader_Planning_Leader_Graphic_Design_Leader[] = _("Program Leader\n\nPlanning Leader\n\nGraphic Design Leader\n\n");
ALIGNED(4) const u8 gCreditsString_Tetsuya_Watanabe_Koji_Nishino_Takao_Unno[] = _("\nTetsuya Watanabe\n\nKoji Nishino\n\nTakao Unno\n");
ALIGNED(4) const u8 gCreditsString_Programmers[] = _("Programmers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hiroyuki_Nakamura_Masao_Taya_Satoshi_Nohara_Miyuki_Iwasawa_Daisuke_Goto[] = _("\nHiroyuki Nakamura\nMasao Taya\nSatoshi Nohara\nMiyuki Iwasawa\nDaisuke Goto\n");
ALIGNED(4) const u8 gCreditsString_System_Programmers[] = _("System Programmers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Tetsuya_Watanabe_Akito_Mori_Hisashi_Sogabe_Sousuke_Tamada[] = _("\nTetsuya Watanabe\nAkito Mori\nHisashi Sogabe\nSousuke Tamada\n\n");
ALIGNED(4) const u8 gCreditsString_Graphic_Designers[] = _("Graphic Designers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Takao_Unno_Asuka_Iwashita_Kanako_Eo_Hiroki_Fuchino[] = _("\nTakao Unno\nAsuka Iwashita\nKanako Eo\nHiroki Fuchino\n\n");
ALIGNED(4) const u8 gCreditsString_Graphic_Designers_2[] = _("\nGraphic Designers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Ken_Sugimori_Hironobu_Yoshida[] = _("\n\nKen Sugimori\nHironobu Yoshida\n\n\n");
ALIGNED(4) const u8 gCreditsString_Music_Composition[] = _("\nMusic Composition\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Go_Ichinose_Junichi_Masuda[] = _("\n\nGo Ichinose\nJunichi Masuda\n\n\n");
ALIGNED(4) const u8 gCreditsString_Sound_Effects[] = _("\n\nSound Effects\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Go_Ichinose[] = _("\n\n\nGo Ichinose\n\n\n");
ALIGNED(4) const u8 gCreditsString_Game_Designers[] = _("\nGame Designers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Junichi_Masuda_Koji_Nishino_Tetsuji_Ohta[] = _("\n\nJunichi Masuda\nKoji Nishino\nTetsuji Ohta\n\n");
ALIGNED(4) const u8 gCreditsString_Game_Designers_2[] = _("\nGame Designers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hitomi_Sato_Shigeru_Ohmori_Tadashi_Takahashi[] = _("\n\nHitomi Sato\nShigeru Ohmori\nTadashi Takahashi\n\n");
ALIGNED(4) const u8 gCreditsString_Game_Scenario[] = _("\nGame Scenario\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hitomi_Sato_Satoshi_Tajiri[] = _("\n\nHitomi Sato\nSatoshi Tajiri\n\n\n");
ALIGNED(4) const u8 gCreditsString_Script_Designer_Map_Designer[] = _("\nScript Designer\n\nMap Designer\n\n\n");
ALIGNED(4) const u8 gCreditsString_Satoshi_Nohara_Shigeru_Ohmori[] = _("\n\nSatoshi Nohara\n\nShigeru Ohmori\n\n");
ALIGNED(4) const u8 gCreditsString_Parametric_Designers[] = _("\nParametric Designers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Koji_Nishino_Tetsuji_Ohta_Shigeki_Morimoto[] = _("\n\nKoji Nishino\nTetsuji Ohta\nShigeki Morimoto\n\n");
ALIGNED(4) const u8 gCreditsString_POKeDEX_Text[] = _("\n\nPOKéDEX Text\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Kenji_Matsushima[] = _("\n\n\nKenji Matsushima\n\n\n");
ALIGNED(4) const u8 gCreditsString_POKeMON_Designers[] = _("POKéMON Designers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Ken_Sugimori_Motofumi_Fujiwara_Shigeki_Morimoto_Hironobu_Yoshida[] = _("\nKen Sugimori\nMotofumi Fujiwara\nShigeki Morimoto\nHironobu Yoshida\n\n");
ALIGNED(4) const u8 gCreditsString_POKeMON_Designers_2[] = _("POKéMON Designers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Satoshi_Ohta_Asuka_Iwashita_Takao_Unno_Kanako_Eo_Aimi_Tomita[] = _("\nSatoshi Ohta\nAsuka Iwashita\nTakao Unno\nKanako Eo\nAimi Tomita\n");
ALIGNED(4) const u8 gCreditsString_POKeMON_Designers_3[] = _("POKéMON Designers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Atsuko_Nishida_Muneo_Saito_Rena_Yoshikawa_Jun_Okutani[] = _("\nAtsuko Nishida\nMuneo Saito\nRena Yoshikawa\nJun Okutani\n\n");
ALIGNED(4) const u8 gCreditsString_Supporting_Programmers[] = _("Supporting Programmers\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Teruyuki_Yoshioka_Takao_Nakano_Satoshi_Mitsuhara_Daisuke_Hoshino[] = _("\nTeruyuki Yoshioka\nTakao Nakano\n\nSatoshi Mitsuhara\nDaisuke Hoshino\n");
ALIGNED(4) const u8 gCreditsString_NCL_Product_Testing[] = _("\n\nNCL Product Testing\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_NCL_Super_Mario_Club[] = _("\n\n\nNCL Super Mario Club\n\n\n");
ALIGNED(4) const u8 gCreditsString_Special_Thanks[] = _("Special Thanks\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hiro_Nakamura_Hiroyuki_Uesugi_Teruki_Murakawa_Kazuya_Suyama[] = _("\nHiro Nakamura\nHiroyuki Uesugi\nTeruki Murakawa\n\nKazuya Suyama\n");
ALIGNED(4) const u8 gCreditsString_Special_Thanks_2[] = _("Special Thanks\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Kenji_Tominaga_Kenjiro_Ito_Tomotaka_Komura_Michiko_Takizawa[] = _("\nKenji Tominaga\n\nKenjiro Ito\nTomotaka Komura\nMichiko Takizawa\n");
ALIGNED(4) const u8 gCreditsString_Special_Thanks_3[] = _("Special Thanks\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Makiko_Takada_Mikiko_Ohashi_Shusaku_Egami_Takanao_Kondo_Rui_Kawaguchi[] = _("\nMakiko Takada\nMikiko Ohashi\nShusaku Egami\nTakanao Kondo\nRui Kawaguchi\n");
ALIGNED(4) const u8 gCreditsString_Braille_Code_Check[] = _("\n\nBraille Code Check\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Japan_Braille_Library[] = _("\n\n\nJapan Braille Library\n\n\n");
ALIGNED(4) const u8 gCreditsString_Information_Supervisors[] = _("Information Supervisors\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hiroki_Enomoto_Kazuyuki_Terada_Yuri_Sakurai_Yumi_Funasaka_Naoko_Yanase[] = _("\nHiroki Enomoto\nKazuyuki Terada\nYuri Sakurai\nYumi Funasaka\nNaoko Yanase\n");
ALIGNED(4) const u8 gCreditsString_Coordinators[] = _("Coordinators\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Azusa_Tajima_Akira_Kinashi_Kazuki_Yoshihara_Retsuji_Nomoto[] = _("\nAzusa Tajima\nAkira Kinashi\nKazuki Yoshihara\n\nRetsuji Nomoto\n");
ALIGNED(4) const u8 gCreditsString_Task_Managers[] = _("\nTask Managers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hitoshi_Yamagami_Gakuji_Nomoto[] = _("\n\nHitoshi Yamagami\nGakuji Nomoto\n\n\n");
ALIGNED(4) const u8 gCreditsString_Producers[] = _("\nProducers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hiroyuki_Jinnai_Takehiro_Izushi_Hiroaki_Tsuru[] = _("\n\nHiroyuki Jinnai\nTakehiro Izushi\nHiroaki Tsuru\n\n");
ALIGNED(4) const u8 gCreditsString_Executive_Director[] = _("\n\nExecutive Director\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Satoshi_Tajiri[] = _("\n\n\nSatoshi Tajiri\n\n\n");
ALIGNED(4) const u8 gCreditsString_Executive_Producer[] = _("\n\nExecutive Producer\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Satoru_Iwata[] = _("\n\n\nSatoru Iwata\n\n\n");
ALIGNED(4) const u8 gCreditsString_Executive_Producer_2[] = _("\n\nExecutive Producer\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Tsunekaz_Ishihara[] = _("\n\n\nTsunekaz Ishihara\n\n\n");
ALIGNED(4) const u8 gCreditsString_English_Version_Coordinators[] = _("\nEnglish Version Coordinators\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Hiro_Nakamura_Seth_McMahill[] = _("\n\nHiro Nakamura\nSeth McMahill\n\n\n");
ALIGNED(4) const u8 gCreditsString_Translator_Text_Editor[] = _("\nTranslator\n\nText Editor\n\n\n");
ALIGNED(4) const u8 gCreditsString_Nob_Ogasawara_Teresa_Lillygren[] = _("\n\nNob Ogasawara\n\nTeresa Lillygren\n\n");
ALIGNED(4) const u8 gCreditsString_Programmers_2[] = _("Programmers\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Teruki_Murakawa_Souichi_Yamamoto_Yuichiro_Ito_Akira_Kinashi[] = _("\nTeruki Murakawa\nSouichi Yamamoto\nYuichiro Ito\nAkira Kinashi\n\n");
ALIGNED(4) const u8 gCreditsString_Environment_Tool_Programmers[] = _("\nEnvironment & Tool Programmers\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Teruki_Murakawa_Souichi_Yamamoto_Kimiko_Nakamichi[] = _("\n\nTeruki Murakawa\nSouichi Yamamoto\nKimiko Nakamichi\n\n");
ALIGNED(4) const u8 gCreditsString_NOA_Product_Testing[] = _("NOA Product Testing\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Thomas_Hertzog_Kathy_Huguenard_Mika_Kurosawa[] = _("\nThomas Hertzog\nKathy Huguenard\nMika Kurosawa\n\n\n");
ALIGNED(4) const u8 gCreditsString_Braille_Code_Check_2[] = _("Braille Code Check\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_National_Federation_of_the_Blind_Patricia_A_Maurer_Japan_Braille_Library_European_Blind_Union[] = _("\nNational Federation\n{CLEAR_TO 19}of the Blind\nPatricia A. Maurer\nJapan Braille Library\nEuropean Blind Union\n");
ALIGNED(4) const u8 gCreditsString_Braille_Code_Check_3[] = _("\nBraille Code Check\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_National_Information_Library_Service_Margaret_Campion[] = _("\n\nNational Information Library\n{CLEAR_TO 45}Service\nMargaret Campion\n\n");
ALIGNED(4) const u8 gCreditsString_Special_Thanks_4[] = _("Special Thanks\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Takehiro_Izushi_Motoyasu_Tojima_Hitoshi_Yamagami_Hiroyuki_Uesugi[] = _("\nTakehiro Izushi\nMotoyasu Tojima\nHitoshi Yamagami\nHiroyuki Uesugi\n\n");
ALIGNED(4) const u8 gCreditsString_Special_Thanks_5[] = _("Special Thanks\n\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Nicola_Pratt_Barlow_Shellie_Dow_Anthony_Howitt_Naoko_Saeki_Kyoko_Onishi[] = _("\nNicola Pratt-Barlow\nShellie Dow\nAnthony Howitt\nNaoko Saeki\nKyoko Onishi\n");
ALIGNED(4) const u8 gCreditsString_Braille_Code_Check_4[] = _("\nBraille Code Check\n\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_The_Royal_New_Zealand_Foundation_of_the_Blind_Greg_Moran[] = _("\n\nThe Royal New Zealand\nFoundation of the Blind\nGreg Moran\n\n");
ALIGNED(4) const u8 gCreditsString_Graphic_Designer[] = _("\n\nGraphic Designer\n\n\n\n");
ALIGNED(4) const u8 gCreditsString_Akira_Kinashi[] = _("\n\n\nAkira Kinashi\n\n\n");

static const u16 sCreditsMonCircle_Pal[] = INCGFX_U16("graphics/credits_frlg/white_circle.pal", ".gbapal");
static const u32 sCreditsMonCircle_Tiles[] = INCGFX_U32("graphics/credits_frlg/white_circle.png", ".8bpp.smol");
static const u32 sCreditsMonCircle_Tilemap[] = INCGFX_U32("graphics/credits_frlg/white_circle.bin", ".smolTM");

static const u32 sCharizard1_Tiles[] = INCGFX_U32("graphics/credits_frlg/charizard_1.png", ".4bpp.smol");
static const u32 sCharizard2_Tiles[] = INCGFX_U32("graphics/credits_frlg/charizard_2.png", ".4bpp.smol");

static const u32 sVenusaurUnused_Tiles[] = INCGFX_U32("graphics/credits_frlg/venusaur_unused.png", ".4bpp.smol");
static const u32 sVenusaur1_Tiles[] = INCGFX_U32("graphics/credits_frlg/venusaur_1.png", ".4bpp.smol");
static const u32 sVenusaur2_Tiles[] = INCGFX_U32("graphics/credits_frlg/venusaur_2.png", ".4bpp.smol");

static const u32 sBlastoise1_Tiles[] = INCGFX_U32("graphics/credits_frlg/blastoise_1.png", ".4bpp.smol");
static const u32 sBlastoise2_Tiles[] = INCGFX_U32("graphics/credits_frlg/blastoise_2.png", ".4bpp.smol");

static const u32 sPikachu1_Tiles[] = INCGFX_U32("graphics/credits_frlg/pikachu_1.png", ".4bpp.smol");
static const u32 sPikachu2_Tiles[] = INCGFX_U32("graphics/credits_frlg/pikachu_2.png", ".4bpp.smol");

static const u32 sUnused = 0xF0;

static const u16 sTheEnd_Pal[] = INCGFX_U16("graphics/credits_frlg/the_end.png", ".gbapal");
static const u8 sTheEnd_Tiles[] = INCGFX_U8("graphics/credits_frlg/the_end.png", ".4bpp.smol");
static const u8 sTheEnd_Tilemap[] = INCBIN_U8("graphics/credits_frlg/the_end.bin.smolTM");

const u16 gCreditsCopyright_Pal[] = INCGFX_U16("graphics/credits_frlg/copyright.png", ".gbapal");
const u8 gCreditsCopyright_Tiles[] = INCGFX_U8("graphics/credits_frlg/copyright.png", ".4bpp.smol");
const u8 gCreditsCopyright_Tilemap[] = INCBIN_U8("graphics/credits_frlg/copyright.bin.smolTM");

const u16 gCreditsMonPokeball_Pals[][16] =
{
    INCGFX_U16("graphics/credits_frlg/pokeball_charizard.pal", ".gbapal"),
    INCGFX_U16("graphics/credits_frlg/pokeball_venusaur.pal", ".gbapal"),
    INCGFX_U16("graphics/credits_frlg/pokeball_blastoise.pal", ".gbapal"),
    INCGFX_U16("graphics/credits_frlg/pokeball_pikachu.pal", ".gbapal"),
};

const u32 gCreditsMonPokeball_Tiles[] = INCGFX_U32("graphics/credits_frlg/pokeball.png", ".4bpp.smol");
const u32 gCreditsMonPokeball_Tilemap[] = INCGFX_U32("graphics/credits_frlg/pokeball.bin", ".smolTM");

static const struct CompressedGraphicsHeader sCopyrightOrTheEndGfxHeaders[] = {
    {
        .tiles = gCreditsCopyright_Tiles,
        .map = gCreditsCopyright_Tilemap,
        .palette = gCreditsCopyright_Pal
    }, {
        .tiles = sTheEnd_Tiles,
        .map = sTheEnd_Tilemap,
        .palette = sTheEnd_Pal
    }
};

#define CREDITS_PRINT(text, duration) { CREDITSSCRCMD_PRINT, CREDITS_STRING_##text, duration }
#define CREDITS_MAPNEXT(map, duration) { CREDITSSCRCMD_MAPNEXT, CREDITS_MAP_##map, duration }
#define CREDITS_MAP(map, duration) { CREDITSSCRCMD_MAP, CREDITS_MAP_##map, duration }
#define CREDITS_MON(mon) { CREDITSSCRCMD_MON, CREDITSMON_##mon }
#define CREDITS_THEENDGFX(idx, duration) { CREDITSSCRCMD_THEENDGFX, CREDITSCLOSING_##idx, duration }
#define CREDITS_WAITBUTTON(time) { CREDITSSCRCMD_WAITBUTTON, .duration = time }

static const struct CreditsScrcmd sCreditsScript[] = {
    CREDITS_MAPNEXT(ROUTE23, 16),
    CREDITS_PRINT(DIRECTOR, 300),
    CREDITS_PRINT(ART_DIRECTOR_BATTLE_DIRECTOR, 300),
    CREDITS_PRINT(PROGRAM_LEADER_PLANNING_LEADER_GRAPHIC_DESIGN_LEADER, 300),
    CREDITS_PRINT(END, 60),
    CREDITS_MAPNEXT(VIRIDIAN_CITY, 0),
    CREDITS_PRINT(PROGRAMMERS, 211),
    CREDITS_PRINT(SYSTEM_PROGRAMMERS, 211),
    CREDITS_PRINT(GRAPHIC_DESIGNERS, 211),
    CREDITS_MAPNEXT(PEWTER_CITY, 0),
    CREDITS_PRINT(GRAPHIC_DESIGNERS_2, 211),
    CREDITS_PRINT(MUSIC_COMPOSITION, 210),
    CREDITS_PRINT(SOUND_EFFECTS, 210),
    CREDITS_MON(CHARIZARD),
    CREDITS_MAP(CERULEAN_CITY, 16),
    CREDITS_PRINT(GAME_DESIGNERS, 211),
    CREDITS_PRINT(GAME_DESIGNERS_2, 210),
    CREDITS_PRINT(GAME_SCENARIO, 210),
    CREDITS_MAPNEXT(ROUTE25, 16),
    CREDITS_PRINT(SCRIPT_DESIGNER_MAP_DESIGNER, 211),
    CREDITS_PRINT(PARAMETRIC_DESIGNERS, 210),
    CREDITS_PRINT(POKEDEX_TEXT, 210),
    CREDITS_MAPNEXT(VERMILION_CITY, 16),
    CREDITS_PRINT(POKEMON_DESIGNERS, 211),
    CREDITS_PRINT(POKEMON_DESIGNERS_2, 210),
    CREDITS_PRINT(POKEMON_DESIGNERS_3, 210),
    CREDITS_MON(VENUSAUR),
    CREDITS_MAP(ROUTE10, 16),
    CREDITS_PRINT(SUPPORTING_PROGRAMMERS, 211),
    CREDITS_PRINT(NCL_PRODUCT_TESTING, 210),
    CREDITS_PRINT(SPECIAL_THANKS, 210),
    CREDITS_MAPNEXT(CELADON_CITY, 16),
    CREDITS_PRINT(SPECIAL_THANKS_2, 221),
    CREDITS_PRINT(SPECIAL_THANKS_3, 221),
    CREDITS_PRINT(BRAILLE_CODE_CHECK, 221),
    CREDITS_PRINT(INFORMATION_SUPERVISORS, 221),
    CREDITS_PRINT(END, 51),
    CREDITS_MAPNEXT(SAFFRON_CITY, 16),
    CREDITS_PRINT(COORDINATORS, 211),
    CREDITS_PRINT(TASK_MANAGERS, 210),
    CREDITS_PRINT(PRODUCERS, 210),
    CREDITS_MON(BLASTOISE),
    CREDITS_MAP(ROUTE17, 16),
    CREDITS_PRINT(EXECUTIVE_DIRECTOR, 331),
    CREDITS_PRINT(EXECUTIVE_PRODUCER, 331),
    CREDITS_PRINT(EXECUTIVE_PRODUCER_2, 331),
    CREDITS_MAPNEXT(FUCHSIA_CITY, 16),
    CREDITS_PRINT(ENGLISH_VERSION_COORDINATORS, 221),
    CREDITS_PRINT(TRANSLATOR_TEXT_EDITOR, 221),
    CREDITS_PRINT(PROGRAMMERS_2, 221),
    CREDITS_PRINT(ENVIRONMENT_TOOL_PROGRAMMERS, 221),
    CREDITS_PRINT(END, 52),
    CREDITS_MAPNEXT(CINNABAR_ISLAND, 16),
    CREDITS_PRINT(GRAPHIC_DESIGNER, 210),
    CREDITS_PRINT(NOA_PRODUCT_TESTING, 210),
    CREDITS_PRINT(BRAILLE_CODE_CHECK_2, 211),
    CREDITS_MON(PIKACHU),
    CREDITS_MAP(ROUTE21_NORTH, 16),
    CREDITS_PRINT(BRAILLE_CODE_CHECK_3, 221),
    CREDITS_PRINT(BRAILLE_CODE_CHECK_4, 221),
    CREDITS_PRINT(SPECIAL_THANKS_4, 221),
    CREDITS_PRINT(SPECIAL_THANKS_5, 221),
    CREDITS_PRINT(END, 52),
    CREDITS_THEENDGFX(ALLRIGHTSRESERVED, 224),
    CREDITS_THEENDGFX(THEEND, 240),
    CREDITS_WAITBUTTON(600)
};

static const ALIGNED(4) u8 sTextColor_Unused[3] = {0, 1, 2};
static const ALIGNED(4) u8 sTextColor_Header[3] = {0, 5, 2};
static const ALIGNED(4) u8 sTextColor_Regular[3] = {0, 1, 2};

static const struct WindowTemplate sCreditsWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 4,
    .width = 30,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x008
};

static const u16 sPlayerMale_Pal[]     = INCGFX_U16("graphics/credits_frlg/player_male.png", ".gbapal");
static const u32 sPlayerMale_Tiles[]   = INCGFX_U32("graphics/credits_frlg/player_male.png", ".4bpp.smol");
static const u16 sPlayerFemale_Pal[]   = INCGFX_U16("graphics/credits_frlg/player_female.png", ".gbapal");
static const u32 sPlayerFemale_Tiles[] = INCGFX_U32("graphics/credits_frlg/player_female.png", ".4bpp.smol");
static const u16 sRival_Pal[]          = INCGFX_U16("graphics/credits_frlg/rival.png", ".gbapal");
static const u32 sRival_Tiles[]        = INCGFX_U32("graphics/credits_frlg/rival.png", ".4bpp.smol");
static const u16 sGround_Grass_Pal[]   = INCGFX_U16("graphics/credits_frlg/ground_grass.png", ".gbapal");
static const u32 sGround_Grass_Tiles[] = INCGFX_U32("graphics/credits_frlg/ground_grass.png", ".4bpp.smol");
static const u16 sGround_Dirt_Pal[]    = INCGFX_U16("graphics/credits_frlg/ground_dirt.png", ".gbapal");
static const u32 sGround_Dirt_Tiles[]  = INCGFX_U32("graphics/credits_frlg/ground_dirt.png", ".4bpp.smol");
static const u16 sGround_City_Pal[]    = INCGFX_U16("graphics/credits_frlg/ground_city.png", ".gbapal");
static const u32 sGround_City_Tiles[]  = INCGFX_U32("graphics/credits_frlg/ground_city.png", ".4bpp.smol");

static const u16 sPlayerRivalSpriteParams[][3] = {
    { 0, 3, 1 },
    { 0, 2, 0 },
    { 0, 3, 0 },
    { 1, 1, 2 },
    { 0, 0, 3 }
};

static const struct OamData sOamData_PlayerOrRival = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .mosaic = FALSE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .size = ST_OAM_SIZE_3,
    .tileNum = 0x000,
    .priority = 0,
    .paletteNum = 15
};

const union AnimCmd sAnimCmds_PlayerOrRival[] = {
    ANIMCMD_FRAME(0x000, 8),
    ANIMCMD_FRAME(0x040, 8),
    ANIMCMD_FRAME(0x080, 8),
    ANIMCMD_FRAME(0x0C0, 8),
    ANIMCMD_FRAME(0x100, 8),
    ANIMCMD_FRAME(0x140, 8),
    ANIMCMD_JUMP(0)
};

const union AnimCmd *const sAnimCmdTable_PlayerOrRival[] = {
    sAnimCmds_PlayerOrRival
};

static const struct SpriteTemplate sPlayerOrRivalSpriteTemplate = {
    .oam = &sOamData_PlayerOrRival,
    .anims = sAnimCmdTable_PlayerOrRival,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_Ground = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .mosaic = FALSE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_H_RECTANGLE,
    .size = ST_OAM_SIZE_3,
    .tileNum = 0x000,
    .priority = 0,
    .paletteNum = 14
};

const union AnimCmd sAnimCmds_GroundRunning[] = {
    ANIMCMD_FRAME(0x00, 8),
    ANIMCMD_FRAME(0x20, 8),
    ANIMCMD_FRAME(0x40, 8),
    ANIMCMD_FRAME(0x60, 8),
    ANIMCMD_FRAME(0x80, 8),
    ANIMCMD_FRAME(0xA0, 8),
    ANIMCMD_FRAME(0xC0, 8),
    ANIMCMD_FRAME(0xE0, 8),
    ANIMCMD_JUMP(0)
};

const union AnimCmd sAnimCmds_GroundStatic[] = {
    ANIMCMD_FRAME(0x00, 8),
    ANIMCMD_JUMP(0)
};

const union AnimCmd *const sAnimCmdTable_GroundRunning[] = {
    sAnimCmds_GroundRunning
};

const union AnimCmd *const sAnimCmdTable_GroundStatic[] = {
    sAnimCmds_GroundStatic
};

static const struct SpriteTemplate sGroundSpriteTemplate_Running = {
    .oam = &sOamData_Ground,
    .anims = sAnimCmdTable_GroundRunning,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sGroundSpriteTemplate_Static = {
    .oam = &sOamData_Ground,
    .anims = sAnimCmdTable_GroundStatic,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CreditsOverworldCmd sOverworldCmd_Route23[] = {
    CREDITSOVWLDLOADMAP(MAP_ROUTE23, 11, 107, 1),
    CREDITSOVWLDSCROLL(0, 1, 0x0500), // Scroll down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_ViridianCity[] = {
    CREDITSOVWLDLOADMAP(MAP_VIRIDIAN_CITY, 30, 34, 1),
    CREDITSOVWLDSCROLL(0, -1, 0x0500), // Scroll up
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_PewterCity[] = {
    CREDITSOVWLDLOADMAP(MAP_PEWTER_CITY, 20, 26, 1),
    CREDITSOVWLDSCROLL(0, -1, 0x0500), // Scroll up
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_CeruleanCity[] = {
    CREDITSOVWLDLOADMAP(MAP_CERULEAN_CITY, 8, 6, 1),
    CREDITSOVWLDSCROLL(1, 1, 0x0500), // Scroll right and down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_Route25[] = {
    CREDITSOVWLDLOADMAP(MAP_ROUTE25, 25, 6, 1),
    CREDITSOVWLDSCROLL(1, 0, 0x0500), // Scroll right
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_VermilionCity[] = {
    CREDITSOVWLDLOADMAP(MAP_VERMILION_CITY, 9, 7, 1),
    CREDITSOVWLDSCROLL(1, 1, 0x0500), // Scroll right and down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_Route10[] = {
    CREDITSOVWLDLOADMAP(MAP_ROUTE10, 11, 68, 1),
    CREDITSOVWLDSCROLL(0, 1, 0x0500), // Scroll down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_CeladonCity[] = {
    CREDITSOVWLDLOADMAP(MAP_CELADON_CITY, 48, 16, 1),
    CREDITSOVWLDSCROLL(-1, 0, 0x0500), // Scroll left
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_SaffronCity[] = {
    CREDITSOVWLDLOADMAP(MAP_SAFFRON_CITY, 39, 5, 1),
    CREDITSOVWLDSCROLL(0, 1, 0x0500), // Scroll down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_Route17[] = {
    CREDITSOVWLDLOADMAP(MAP_ROUTE17, 7, 43, 1),
    CREDITSOVWLDSCROLL(0, 1, 0x0500), // Scroll down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_FuchsiaCity[] = {
    CREDITSOVWLDLOADMAP(MAP_FUCHSIA_CITY, 28, 5, 1),
    CREDITSOVWLDSCROLL(0, 1, 0x0500), // Scroll down
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_CinnabarIsland[] = {
    CREDITSOVWLDLOADMAP(MAP_CINNABAR_ISLAND, 13, 17, 1),
    CREDITSOVWLDSCROLL(0, -1, 0x0500), // Scroll up
    CREDITSOVWLDEND
};

static const struct CreditsOverworldCmd sOverworldCmd_Route21[] = {
    CREDITSOVWLDLOADMAP(MAP_ROUTE21_NORTH, 8, 20, 1),
    CREDITSOVWLDSCROLL(0, -1, 0x0500), // Scroll up
    CREDITSOVWLDEND,
};

static const struct CreditsOverworldCmd *const sOverworldMapScenes[] = {
    sOverworldCmd_Route23,
    sOverworldCmd_ViridianCity,
    sOverworldCmd_PewterCity,
    sOverworldCmd_CeruleanCity,
    sOverworldCmd_Route25,
    sOverworldCmd_VermilionCity,
    sOverworldCmd_Route10,
    sOverworldCmd_CeladonCity,
    sOverworldCmd_SaffronCity,
    sOverworldCmd_Route17,
    sOverworldCmd_FuchsiaCity,
    sOverworldCmd_CinnabarIsland,
    sOverworldCmd_Route21
};

static const struct CreditsTextHeader sCreditsTexts[] = {
    { gCreditsString_Director, gCreditsString_Junichi_Masuda, FALSE },
    { gCreditsString_Art_Director_Battle_Director, gCreditsString_Ken_Sugimori_Shigeki_Morimoto, FALSE },
    { gCreditsString_Program_Leader_Planning_Leader_Graphic_Design_Leader, gCreditsString_Tetsuya_Watanabe_Koji_Nishino_Takao_Unno, FALSE },
    { gCreditsString_Programmers, gCreditsString_Hiroyuki_Nakamura_Masao_Taya_Satoshi_Nohara_Miyuki_Iwasawa_Daisuke_Goto, FALSE },
    { gCreditsString_System_Programmers, gCreditsString_Tetsuya_Watanabe_Akito_Mori_Hisashi_Sogabe_Sousuke_Tamada, TRUE  },
    { gCreditsString_Graphic_Designers, gCreditsString_Takao_Unno_Asuka_Iwashita_Kanako_Eo_Hiroki_Fuchino, TRUE  },
    { gCreditsString_Graphic_Designers_2, gCreditsString_Ken_Sugimori_Hironobu_Yoshida, TRUE  },
    { gCreditsString_Music_Composition, gCreditsString_Go_Ichinose_Junichi_Masuda, TRUE  },
    { gCreditsString_Sound_Effects, gCreditsString_Go_Ichinose, FALSE },
    { gCreditsString_Game_Designers, gCreditsString_Junichi_Masuda_Koji_Nishino_Tetsuji_Ohta, FALSE },
    { gCreditsString_Game_Designers_2, gCreditsString_Hitomi_Sato_Shigeru_Ohmori_Tadashi_Takahashi, FALSE },
    { gCreditsString_Game_Scenario, gCreditsString_Hitomi_Sato_Satoshi_Tajiri, TRUE  },
    { gCreditsString_Script_Designer_Map_Designer, gCreditsString_Satoshi_Nohara_Shigeru_Ohmori, FALSE },
    { gCreditsString_Parametric_Designers, gCreditsString_Koji_Nishino_Tetsuji_Ohta_Shigeki_Morimoto, FALSE },
    { gCreditsString_POKeDEX_Text, gCreditsString_Kenji_Matsushima, FALSE },
    { gCreditsString_POKeMON_Designers, gCreditsString_Ken_Sugimori_Motofumi_Fujiwara_Shigeki_Morimoto_Hironobu_Yoshida, TRUE  },
    { gCreditsString_POKeMON_Designers_2, gCreditsString_Satoshi_Ohta_Asuka_Iwashita_Takao_Unno_Kanako_Eo_Aimi_Tomita, FALSE },
    { gCreditsString_POKeMON_Designers_3, gCreditsString_Atsuko_Nishida_Muneo_Saito_Rena_Yoshikawa_Jun_Okutani, TRUE  },
    { gCreditsString_Supporting_Programmers, gCreditsString_Teruyuki_Yoshioka_Takao_Nakano_Satoshi_Mitsuhara_Daisuke_Hoshino, FALSE },
    { gCreditsString_NCL_Product_Testing, gCreditsString_NCL_Super_Mario_Club, FALSE },
    { gCreditsString_Special_Thanks, gCreditsString_Hiro_Nakamura_Hiroyuki_Uesugi_Teruki_Murakawa_Kazuya_Suyama, FALSE },
    { gCreditsString_Special_Thanks_2, gCreditsString_Kenji_Tominaga_Kenjiro_Ito_Tomotaka_Komura_Michiko_Takizawa, FALSE },
    { gCreditsString_Special_Thanks_3, gCreditsString_Makiko_Takada_Mikiko_Ohashi_Shusaku_Egami_Takanao_Kondo_Rui_Kawaguchi, FALSE },
    { gCreditsString_Braille_Code_Check, gCreditsString_Japan_Braille_Library, FALSE },
    { gCreditsString_Information_Supervisors, gCreditsString_Hiroki_Enomoto_Kazuyuki_Terada_Yuri_Sakurai_Yumi_Funasaka_Naoko_Yanase, FALSE },
    { gCreditsString_Coordinators, gCreditsString_Azusa_Tajima_Akira_Kinashi_Kazuki_Yoshihara_Retsuji_Nomoto, FALSE },
    { gCreditsString_Task_Managers, gCreditsString_Hitoshi_Yamagami_Gakuji_Nomoto, TRUE  },
    { gCreditsString_Producers, gCreditsString_Hiroyuki_Jinnai_Takehiro_Izushi_Hiroaki_Tsuru, FALSE },
    { gCreditsString_Executive_Director, gCreditsString_Satoshi_Tajiri, FALSE },
    { gCreditsString_Executive_Producer, gCreditsString_Satoru_Iwata, FALSE },
    { gCreditsString_Executive_Producer_2, gCreditsString_Tsunekaz_Ishihara, FALSE },
    { gCreditsString_English_Version_Coordinators, gCreditsString_Hiro_Nakamura_Seth_McMahill, FALSE },
    { gCreditsString_Translator_Text_Editor, gCreditsString_Nob_Ogasawara_Teresa_Lillygren, FALSE },
    { gCreditsString_Programmers_2, gCreditsString_Teruki_Murakawa_Souichi_Yamamoto_Yuichiro_Ito_Akira_Kinashi, FALSE },
    { gCreditsString_Environment_Tool_Programmers, gCreditsString_Teruki_Murakawa_Souichi_Yamamoto_Kimiko_Nakamichi, TRUE  },
    { gCreditsString_NOA_Product_Testing, gCreditsString_Thomas_Hertzog_Kathy_Huguenard_Mika_Kurosawa, TRUE  },
    { gCreditsString_Braille_Code_Check_2, gCreditsString_National_Federation_of_the_Blind_Patricia_A_Maurer_Japan_Braille_Library_European_Blind_Union, TRUE  },
    { gCreditsString_Braille_Code_Check_3, gCreditsString_National_Information_Library_Service_Margaret_Campion, TRUE  },
    { gCreditsString_Special_Thanks_4, gCreditsString_Takehiro_Izushi_Motoyasu_Tojima_Hitoshi_Yamagami_Hiroyuki_Uesugi, FALSE },
    { gCreditsString_Special_Thanks_5, gCreditsString_Nicola_Pratt_Barlow_Shellie_Dow_Anthony_Howitt_Naoko_Saeki_Kyoko_Onishi, FALSE },
    { gCreditsString_Braille_Code_Check_4, gCreditsString_The_Royal_New_Zealand_Foundation_of_the_Blind_Greg_Moran, FALSE },
    { gCreditsString_Graphic_Designer, gCreditsString_Akira_Kinashi, FALSE },
    { gText_EmptyString2, gText_EmptyString2, FALSE }
};

void CB2_StartCreditsSequence(void)
{
    sCreditsMgr = AllocZeroed(sizeof(*sCreditsMgr));
    ResetTasks();
    sCreditsMgr->taskId = TASK_NONE;
    sCreditsMgr->unk_1D = 0;
    ResetSpriteData();
    SetMainCallback2(CB2_Credits);
}

static void CB2_Credits(void)
{
    switch (RollCredits())
    {
    case 0:
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        break;
    case 1:
        if (sCreditsMgr->unk_1D & 1)
        {
            Overworld_CreditsMainCB();
        }
        else
        {
            RunTasks();
            AnimateSprites();
            BuildOamBuffer();
            UpdatePaletteFade();
        }
        sCreditsMgr->unk_1D++;
        break;
    case 2:
        FlagClear(FLAG_HIDE_MAP_NAME_POPUP);
        gDisableMapMusicChangeOnMapLoad = MUSIC_DISABLE_OFF;
        Free(sCreditsMgr);
        SoftReset(RESET_ALL);
        // noreturn
    }
}

static void SwitchWin1OffWin0On(void)
{
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WININ, 0x1F3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x000E);
}

static void InitBgDarkenEffect(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
    SetGpuReg(REG_OFFSET_BLDY, 10);
}

static void CreateCreditsWindow(void)
{
    sCreditsMgr->windowId = AddWindow(&sCreditsWindowTemplate);
    FillWindowPixelBuffer(sCreditsMgr->windowId, PIXEL_FILL(0));
    PutWindowTilemap(sCreditsMgr->windowId);
    CopyWindowToVram(sCreditsMgr->windowId, COPYWIN_FULL);
    sCreditsMgr->windowIsActive = TRUE;
}

static void DestroyCreditsWindow(void)
{
    if (sCreditsMgr->windowIsActive)
    {
        RemoveWindow(sCreditsMgr->windowId);
        CleanupOverworldWindowsAndTilemaps();
        sCreditsMgr->windowIsActive = FALSE;
    }
}

static bool32 DoOverworldMapScrollScene(u8 whichMon)
{
    switch (sCreditsMgr->subseqno)
    {
    case 0:
        FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
        gDisableMapMusicChangeOnMapLoad = MUSIC_DISABLE_KEEP;
        sCreditsMgr->ovwldseqno = 0;
        sCreditsMgr->subseqno++;
        // fallthrough
    case 1:
        if (!Overworld_DoScrollSceneForCredits(&sCreditsMgr->ovwldseqno, sOverworldMapScenes[sCreditsMgr->whichMon]))
            return FALSE;
        CreateCreditsWindow();
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(36, DISPLAY_HEIGHT - 36));
        SwitchWin1OffWin0On();
        InitBgDarkenEffect();
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        gPlttBufferUnfaded[BG_PLTT_ID(15) + 15] = RGB_BLACK;
        gPlttBufferFaded[BG_PLTT_ID(15) + 15] = RGB_BLACK;
        return TRUE;
    default:
        return FALSE;
    }
}

static s32 RollCredits(void)
{
    u16 win0v[8];

    switch (sCreditsMgr->mainseqno)
    {
    case CREDITSSCENE_INIT_WIN0:
        SwitchWin1OffWin0On();
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2 - 1, DISPLAY_HEIGHT / 2 + 1));
        sCreditsMgr->mainseqno = CREDITSSCENE_SETUP_DARKEN_EFFECT;
        return 0;
    case CREDITSSCENE_SETUP_DARKEN_EFFECT:
        InitBgDarkenEffect();
        CreateCreditsWindow();
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        gPlttBufferUnfaded[BG_PLTT_ID(15) + 15] = RGB_BLACK;
        gPlttBufferFaded[BG_PLTT_ID(15) + 15] = RGB_BLACK;
        sCreditsMgr->mainseqno = CREDITSSCENE_OPEN_WIN0;
        return 0;
    case CREDITSSCENE_OPEN_WIN0:
        win0v[0] = GetGpuReg(REG_OFFSET_WIN0V) >> 8;
        win0v[1] = GetGpuReg(REG_OFFSET_WIN0V) & 0xFF;
        if (win0v[0] == 0x24)
        {
            sCreditsMgr->timer = 0;
            sCreditsMgr->mainseqno = CREDITSSCENE_LOAD_PLAYER_SPRITE_AT_INDIGO;
        }
        else
        {
            win0v[0]--;
            win0v[1]++;
            SetGpuReg(REG_OFFSET_WIN0V, (win0v[0] << 8) + win0v[1]);
        }
        return 0;
    case CREDITSSCENE_LOAD_PLAYER_SPRITE_AT_INDIGO:
        if (sCreditsMgr->timer)
        {
            sCreditsMgr->timer--;
            return 0;
        }
        LoadPlayerOrRivalSprite(0);
        sCreditsMgr->timer = 100;
        sCreditsMgr->mainseqno = CREDITSSCENE_PRINT_TITLE_STAFF;
        return 0;
    case CREDITSSCENE_PRINT_TITLE_STAFF:
        if (sCreditsMgr->timer)
        {
            sCreditsMgr->timer--;
            return 0;
            
        }
        sCreditsMgr->timer = 360;
        AddTextPrinterParameterized4(sCreditsMgr->windowId, FONT_NORMAL, 0x08, 0x29, 1, 2, sTextColor_Header, 0, TITLE_TEXT);
        sCreditsMgr->mainseqno = CREDITSSCENE_WAIT_TITLE_STAFF;
        return 0;
    case CREDITSSCENE_WAIT_TITLE_STAFF:
        if (sCreditsMgr->timer)
        {
            sCreditsMgr->timer--;
            return 0;
        }
        DestroyCreditsWindow();
        sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        sCreditsMgr->timer = 0;
        sCreditsMgr->scrcmdidx = 0;
        return 0;
    case CREDITSSCENE_EXEC_CMD:
        if (sCreditsMgr->timer != 0)
        {
            sCreditsMgr->timer--;
            return sCreditsMgr->canSpeedThrough;
        }
        switch (sCreditsScript[sCreditsMgr->scrcmdidx].cmd)
        {
        case CREDITSSCRCMD_PRINT:
            BeginNormalPaletteFade(0x00008000, 0, 0, 16, RGB_BLACK);
            sCreditsMgr->mainseqno = CREDITSSCENE_PRINT_ADDPRINTER1;
            FillWindowPixelBuffer(sCreditsMgr->windowId, PIXEL_FILL(0));
            return sCreditsMgr->canSpeedThrough;
        case CREDITSSCRCMD_MAPNEXT:
            sCreditsMgr->mainseqno = CREDITSSCENE_MAPNEXT_DESTROYWINDOW;
            sCreditsMgr->whichMon = sCreditsScript[sCreditsMgr->scrcmdidx].param;
            FadeSelectedPals(1, 0, 0x3FFFFFFF);
            break;
        case CREDITSSCRCMD_MAP:
            sCreditsMgr->mainseqno = CREDITSSCENE_MAP_LOADMAP_CREATESPRITES;
            sCreditsMgr->whichMon = sCreditsScript[sCreditsMgr->scrcmdidx].param;
            break;
        case CREDITSSCRCMD_MON:
            sCreditsMgr->mainseqno = CREDITSSCENE_MON_DESTROY_ASSETS;
            sCreditsMgr->whichMon = sCreditsScript[sCreditsMgr->scrcmdidx].param;
            FadeScreen(FADE_TO_BLACK, 0);
            break;
        case CREDITSSCRCMD_THEENDGFX:
            sCreditsMgr->mainseqno = CREDITSSCENE_THEEND_DESTROY_ASSETS;
            sCreditsMgr->whichMon = sCreditsScript[sCreditsMgr->scrcmdidx].param;
            BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 16, RGB_BLACK);
            break;
        case CREDITSSCRCMD_WAITBUTTON:
            sCreditsMgr->mainseqno = CREDITSSCENE_WAITBUTTON;
            break;
        }
        sCreditsMgr->timer = sCreditsScript[sCreditsMgr->scrcmdidx].duration;
        sCreditsMgr->scrcmdidx++;
        return 0;
    case CREDITSSCENE_PRINT_ADDPRINTER1:
        if (gPaletteFade.active)
            return sCreditsMgr->canSpeedThrough;
        win0v[0] = sCreditsTexts[sCreditsScript[sCreditsMgr->scrcmdidx].param].unused;
        AddTextPrinterParameterized4(sCreditsMgr->windowId, FONT_NORMAL, 2, 6, 0, 0, sTextColor_Header, -1, sCreditsTexts[sCreditsScript[sCreditsMgr->scrcmdidx].param].title);
        sCreditsMgr->mainseqno = CREDITSSCENE_PRINT_ADDPRINTER2;
        return sCreditsMgr->canSpeedThrough;
    case CREDITSSCENE_PRINT_ADDPRINTER2:
        win0v[0] = sCreditsTexts[sCreditsScript[sCreditsMgr->scrcmdidx].param].unused;
        AddTextPrinterParameterized4(sCreditsMgr->windowId, FONT_NORMAL, 8, 6, 0, 0, sTextColor_Regular, -1, sCreditsTexts[sCreditsScript[sCreditsMgr->scrcmdidx].param].names);
        sCreditsMgr->mainseqno = CREDITSSCENE_PRINT_DELAY;
        return sCreditsMgr->canSpeedThrough;
    case CREDITSSCENE_PRINT_DELAY:
        CopyWindowToVram(sCreditsMgr->windowId, COPYWIN_GFX);
        sCreditsMgr->timer = sCreditsScript[sCreditsMgr->scrcmdidx].duration;
        sCreditsMgr->scrcmdidx++;
        BeginNormalPaletteFade(0x00008000, 0, 16, 0, RGB_BLACK);
        sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        return sCreditsMgr->canSpeedThrough;
    case CREDITSSCENE_MAPNEXT_DESTROYWINDOW:
        if (!gPaletteFade.active)
        {
            DestroyCreditsWindow();
            sCreditsMgr->subseqno = 0;
            sCreditsMgr->mainseqno = CREDITSSCENE_MAPNEXT_LOADMAP;
        }
        return 0;
    case CREDITSSCENE_MAPNEXT_LOADMAP:
        if (DoOverworldMapScrollScene(sCreditsMgr->whichMon))
        {
            sCreditsMgr->canSpeedThrough = 1;
            sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        }
        return 0;
    case CREDITSSCENE_MAP_LOADMAP_CREATESPRITES:
        if (!gPaletteFade.active)
        {
            DestroyCreditsWindow();
            sCreditsMgr->subseqno = 0;
            while (!DoOverworldMapScrollScene(sCreditsMgr->whichMon))
            {}
            switch (sCreditsMgr->whichMon)
            {
            case 3:
            default:
                win0v[0] = 1;
                break;
            case 6:
                win0v[0] = 2;
                break;
            case 9:
                win0v[0] = 3;
                break;
            case 12:
                win0v[0] = 4;
                break;
            }
            LoadPlayerOrRivalSprite(win0v[0]);
            sCreditsMgr->canSpeedThrough = 1;
            sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        }
        return 0;
    case CREDITSSCENE_MON_DESTROY_ASSETS:
        if (!gPaletteFade.active)
        {
            DestroyPlayerOrRivalSprite();
            DestroyCreditsWindow();
            sCreditsMgr->subseqno = 0;
            sCreditsMgr->canSpeedThrough = 0;
            sCreditsMgr->mainseqno = CREDITSSCENE_MON_SHOW;
        }
        return 0;
    case CREDITSSCENE_MON_SHOW:
        if (DoCreditsMonScene())
        {
            sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        }
        return 0;
    case CREDITSSCENE_THEEND_DESTROY_ASSETS:
        if (!gPaletteFade.active)
        {
            DestroyCreditsWindow();
            sCreditsMgr->subseqno = 0;
            sCreditsMgr->canSpeedThrough = 0;
            sCreditsMgr->mainseqno = CREDITSSCENE_THEEND_SHOW;
        }
        return 0;
    case CREDITSSCENE_THEEND_SHOW:
        if (DoCopyrightOrTheEndGfxScene())
        {
            sCreditsMgr->mainseqno = CREDITSSCENE_EXEC_CMD;
        }
        return 0;
    case CREDITSSCENE_WAITBUTTON:
        if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITE);
            sCreditsMgr->mainseqno = CREDITSSCENE_TERMINATE;
            return 0;
        }
        if (sCreditsMgr->timer)
        {
            sCreditsMgr->timer--;
        }
        else
        {
            sCreditsMgr->mainseqno = CREDITSSCENE_TERMINATE;
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITE);
        }
        return 0;
    case CREDITSSCENE_TERMINATE:
        if (!gPaletteFade.active)
            DestroyCreditsWindow();
        break;
    }
    return 2;
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void LoadCreditsMonPic(u8 whichMon)
{
    switch (whichMon)
    {
    case CREDITSMON_CHARIZARD:
        InitWindows(sWindowTemplates_Charizard);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CreateTrainerCardMonIconSprite(SPECIES_CHARIZARD, FALSE, 0, TRUE, 0, 0, 10, 0);
        CopyToWindowPixelBuffer(1, (const void *)sCharizard1_Tiles, 0, 0);
        CopyToWindowPixelBuffer(2, (const void *)sCharizard2_Tiles, 0, 0);
        break;
    case CREDITSMON_VENUSAUR:
        InitWindows(sWindowTemplates_Venusaur);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CreateTrainerCardMonIconSprite(SPECIES_VENUSAUR, FALSE, 0, TRUE, 0, 0, 10, 0);
        CopyToWindowPixelBuffer(1, (const void *)sVenusaur1_Tiles, 0, 0);
        CopyToWindowPixelBuffer(2, (const void *)sVenusaur2_Tiles, 0, 0);
        break;
    case CREDITSMON_BLASTOISE:
        InitWindows(sWindowTemplates_Blastoise);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CreateTrainerCardMonIconSprite(SPECIES_BLASTOISE, FALSE, 0, TRUE, 0, 0, 10, 0);
        CopyToWindowPixelBuffer(1, (const void *)sBlastoise1_Tiles, 0, 0);
        CopyToWindowPixelBuffer(2, (const void *)sBlastoise2_Tiles, 0, 0);
        break;
    case CREDITSMON_PIKACHU:
        InitWindows(sWindowTemplates_Pikachu);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CreateTrainerCardMonIconSprite(SPECIES_PIKACHU, FALSE, 0, TRUE, 0, 0, 10, 0);
        CopyToWindowPixelBuffer(1, (const void *)sPikachu1_Tiles, 0, 0);
        CopyToWindowPixelBuffer(2, (const void *)sPikachu2_Tiles, 0, 0);
        break;
    }
    CopyWindowToVram(0, COPYWIN_GFX);
    CopyWindowToVram(1, COPYWIN_GFX);
    CopyWindowToVram(2, COPYWIN_GFX);
}

static enum Species GetCreditsMonSpecies(u8 whichMon)
{
    switch (whichMon)
    {
    case CREDITSMON_CHARIZARD:
        return SPECIES_CHARIZARD;
    case CREDITSMON_VENUSAUR:
        return SPECIES_VENUSAUR;
    case CREDITSMON_BLASTOISE:
        return SPECIES_BLASTOISE;
    case CREDITSMON_PIKACHU:
        return SPECIES_PIKACHU;
    default:
        return SPECIES_NONE;
    }
}

static bool32 DoCreditsMonScene(void)
{
    switch (sCreditsMgr->subseqno)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ResetBgsAndClearDma3BusyFlags(1);
        InitBgsFromTemplates(1, sBgTemplates_MonSceneOrTheEnd, NELEMS(sBgTemplates_MonSceneOrTheEnd));
        SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        sCreditsMgr->creditsMonTimer = 0;
        sCreditsMgr->unk_0E = 0;
        SetBgAffine(2, 0x8000, 0x8000, 0x78, 0x50, sCreditsMgr->creditsMonTimer, sCreditsMgr->creditsMonTimer, 0);
        DecompressAndLoadBgGfxUsingHeap(1, gCreditsMonPokeball_Tiles, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, sCreditsMonCircle_Tiles, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(1, gCreditsMonPokeball_Tilemap, 0x500, 0, 1);
        DecompressAndLoadBgGfxUsingHeap(2, sCreditsMonCircle_Tilemap, 0x400, 0, 1);
        LoadPalette(gCreditsMonPokeball_Pals[sCreditsMgr->whichMon], BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(sCreditsMonCircle_Pal, BG_PLTT_ID(15), sizeof(sCreditsMonCircle_Pal));
        LoadCreditsMonPic(sCreditsMgr->whichMon);
        SetVBlankCallback(VBlankCB);
        EnableInterrupts(INTR_FLAG_VBLANK);
        sCreditsMgr->subseqno++;
        break;
    case 1:
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 17);
        PutWindowTilemap(0);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);
        sCreditsMgr->subseqno++;
        break;
    case 2:
        ShowBg(2);
        ShowBg(0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sCreditsMgr->creditsMonTimer = 40;
        sCreditsMgr->subseqno++;
        break;
    case 3:
        if (sCreditsMgr->creditsMonTimer != 0)
            sCreditsMgr->creditsMonTimer--;
        else
            sCreditsMgr->subseqno++;
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            sCreditsMgr->creditsMonTimer = 8;
            sCreditsMgr->unk_0E = 1;
            sCreditsMgr->subseqno++;
        }
        break;
    case 5:
        if (sCreditsMgr->creditsMonTimer != 0)
            sCreditsMgr->creditsMonTimer--;
        else
        {
            if (sCreditsMgr->unk_0E < 3)
            {
                PutWindowTilemap(sCreditsMgr->unk_0E);
                CopyBgTilemapBufferToVram(0);
                sCreditsMgr->creditsMonTimer = 4;
                sCreditsMgr->unk_0E++;
            }
            else
                sCreditsMgr->subseqno++;
        }
        break;
    case 6:
        if (sCreditsMgr->creditsMonTimer < 256)
        {
            sCreditsMgr->creditsMonTimer += 16;
            SetBgAffine(2, 0x8000, 0x8000, 0x78, 0x50, sCreditsMgr->creditsMonTimer, sCreditsMgr->creditsMonTimer, 0);
        }
        else
        {
            SetBgAffine(2, 0x8000, 0x8000, 0x78, 0x50, 0x100, 0x100, 0);
            sCreditsMgr->creditsMonTimer = 32;
            sCreditsMgr->subseqno++;
        }
        break;
    case 7:
        if (sCreditsMgr->creditsMonTimer != 0)
            sCreditsMgr->creditsMonTimer--;
        else
        {
            HideBg(2);
            ShowBg(1);
            PlayCry_NormalNoDucking(GetCreditsMonSpecies(sCreditsMgr->whichMon), 0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
            sCreditsMgr->creditsMonTimer = 128;
            sCreditsMgr->subseqno++;
        }
        break;
    case 8:
        if (sCreditsMgr->creditsMonTimer != 0)
            sCreditsMgr->creditsMonTimer--;
        else
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sCreditsMgr->subseqno++;
        }
        break;
    case 9:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            Free(GetBgTilemapBuffer(0));
            sCreditsMgr->subseqno = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 DoCopyrightOrTheEndGfxScene(void)
{
    switch (sCreditsMgr->subseqno)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ResetBgsAndClearDma3BusyFlags(1);
        InitBgsFromTemplates(0, sBgTemplates_MonSceneOrTheEnd, 1);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        DecompressAndLoadBgGfxUsingHeap(0, sCopyrightOrTheEndGfxHeaders[sCreditsMgr->whichMon].tiles, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(0, sCopyrightOrTheEndGfxHeaders[sCreditsMgr->whichMon].map, 0x800, 0, 1);
        LoadPalette(sCopyrightOrTheEndGfxHeaders[sCreditsMgr->whichMon].palette, BG_PLTT_ID(0), 16 * PLTT_SIZE_4BPP);
        SetVBlankCallback(VBlankCB);
        EnableInterrupts(INTR_FLAG_VBLANK);
        sCreditsMgr->subseqno++;
        break;
    case 1:
        CopyBgTilemapBufferToVram(0);
        sCreditsMgr->subseqno++;
        break;
    case 2:
        ShowBg(0);
        if (sCreditsMgr->whichMon != 0)
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0, RGB_BLACK);
        else
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sCreditsMgr->subseqno++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            sCreditsMgr->subseqno = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void Task_MovePlayerAndGroundSprites(u8 taskId)
{
    struct CreditsTaskData * data = (void *)gTasks[taskId].data;
    switch (data->spriteMoveCmd)
    {
    case 0:
        break;
    case 1:
        if (gSprites[data->characterSpriteId].x != 0xD0)
        {
            gSprites[data->characterSpriteId].x--;
            gSprites[data->groundSpriteId].x--;
        }
        else
        {
            data->spriteMoveCmd = 0;
        }
        break;
    case 2:
        if (sCreditsMgr->unk_1D & 1)
        {
            if (gSprites[data->characterSpriteId].y != 0x50)
            {
                gSprites[data->characterSpriteId].y--;
                gSprites[data->groundSpriteId].y--;
            }
            else
            {
                data->spriteMoveCmd = 0;
            }
        }
        break;
    case 3:
        if (sCreditsMgr->mainseqno == 15)
        {
            gSprites[data->characterSpriteId].x--;
            gSprites[data->groundSpriteId].x--;
        }
        break;
    }
}

static void DestroyPlayerOrRivalSprite(void)
{
    if (sCreditsMgr->taskId != TASK_NONE)
    {
        struct CreditsTaskData * data = (void *)gTasks[sCreditsMgr->taskId].data;
        FreeSpriteTilesByTag(data->characterTilesTag);
        DestroySprite(&gSprites[data->characterSpriteId]);
        FreeSpriteTilesByTag(data->groundTilesTag);
        DestroySprite(&gSprites[data->groundSpriteId]);
        DestroyTask(sCreditsMgr->taskId);
        sCreditsMgr->taskId = TASK_NONE;
    }
}

static void LoadPlayerOrRivalSprite(u8 whichScene)
{
    u8 taskId;
    struct CreditsTaskData * data;
    s32 x, y;
    struct SpriteTemplate sprTemplate;
    struct CompressedSpriteSheet sprSheet;

    if (sCreditsMgr->taskId == TASK_NONE)
    {
        taskId = CreateTask(Task_MovePlayerAndGroundSprites, 0);
        data = (void *)gTasks[taskId].data;
        sCreditsMgr->taskId = taskId;
        switch (sPlayerRivalSpriteParams[whichScene][2])
        {
        default:
        case 0:
            x = DISPLAY_WIDTH - 32;
            y = DISPLAY_HEIGHT / 2;
            break;
        case 1:
            x = DISPLAY_WIDTH + 32;
            y = DISPLAY_HEIGHT / 2;
            break;
        case 2:
            x = DISPLAY_WIDTH - 32;
            y = DISPLAY_HEIGHT;
            break;
        }
        data->spriteMoveCmd = sPlayerRivalSpriteParams[whichScene][2];
        data->characterTilesTag = GFXTAG_CHARACTER;
        data->characterPalTag = TAG_NONE;
        switch (sPlayerRivalSpriteParams[whichScene][0])
        {
        case 0:
            // Player
            if (gSaveBlock2Ptr->playerGender == MALE)
            {
                sprSheet.data = sPlayerMale_Tiles;
                sprSheet.size = 0x3000;
                sprSheet.tag = data->characterTilesTag;
                LoadCompressedSpriteSheet(&sprSheet);
                LoadPalette(sPlayerMale_Pal, OBJ_PLTT_ID(15), sizeof(sPlayerMale_Pal));
            }
            else
            {
                sprSheet.data = sPlayerFemale_Tiles;
                sprSheet.size = 0x3000;
                sprSheet.tag = data->characterTilesTag;
                LoadCompressedSpriteSheet(&sprSheet);
                LoadPalette(sPlayerFemale_Pal, OBJ_PLTT_ID(15), sizeof(sPlayerFemale_Pal));
            }
            break;
        case 1:
            // Rival
            sprSheet.data = sRival_Tiles;
            sprSheet.size = 0x3000;
            sprSheet.tag = data->characterTilesTag;
            LoadCompressedSpriteSheet(&sprSheet);
            LoadPalette(sRival_Pal, OBJ_PLTT_ID(15), sizeof(sRival_Pal));
            break;
        }
        sprTemplate = sPlayerOrRivalSpriteTemplate;
        sprTemplate.tileTag = data->characterTilesTag;
        data->characterSpriteId = CreateSprite(&sprTemplate, x, y, 0);
        gSprites[data->characterSpriteId].oam.paletteNum = 15;
        gSprites[data->characterSpriteId].subpriority = 0;

        data->groundTilesTag = GFXTAG_GROUND;
        data->groundPalTag = TAG_NONE;
        switch (sPlayerRivalSpriteParams[whichScene][1])
        {
        case 0:
            sprSheet.data = sGround_Grass_Tiles;
            sprSheet.size = 0x3000;
            sprSheet.tag = data->groundTilesTag;
            LoadCompressedSpriteSheet(&sprSheet);
            LoadPalette(sGround_Grass_Pal, OBJ_PLTT_ID(14), sizeof(sGround_Grass_Pal));
            sprTemplate = sGroundSpriteTemplate_Running;
            break;
        case 1:
            sprSheet.data = sGround_Grass_Tiles;
            sprSheet.size = 0x3000;
            sprSheet.tag = data->groundTilesTag;
            LoadCompressedSpriteSheet(&sprSheet);
            LoadPalette(sGround_Grass_Pal, OBJ_PLTT_ID(14), sizeof(sGround_Grass_Pal));
            sprTemplate = sGroundSpriteTemplate_Static;
            break;
        case 2:
            sprSheet.data = sGround_Dirt_Tiles;
            sprSheet.size = 0x3000;
            sprSheet.tag = data->groundTilesTag;
            LoadCompressedSpriteSheet(&sprSheet);
            LoadPalette(sGround_Dirt_Pal, OBJ_PLTT_ID(14), sizeof(sGround_Dirt_Pal));
            sprTemplate = sGroundSpriteTemplate_Running;
            break;
        case 3:
            sprSheet.data = sGround_City_Tiles;
            sprSheet.size = 0x3000;
            sprSheet.tag = data->groundTilesTag;
            LoadCompressedSpriteSheet(&sprSheet);
            LoadPalette(sGround_City_Pal, OBJ_PLTT_ID(14), sizeof(sGround_City_Pal));
            sprTemplate = sGroundSpriteTemplate_Running;
            break;
        }
        sprTemplate.tileTag = data->groundTilesTag;
        data->groundSpriteId = CreateSprite(&sprTemplate, x, y + 38, 0);
        gSprites[data->groundSpriteId].oam.paletteNum = 14;
        gSprites[data->groundSpriteId].subpriority = 1;
    }
}

#endif // IS_FRLG
