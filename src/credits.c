#include "global.h"
#include "palette.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "malloc.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/songs.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "constants/rgb.h"
#include "trainer_pokemon_sprites.h"
#include "starter_choose.h"
#include "decompress.h"
#include "intro_credits_graphics.h"
#include "sound.h"
#include "trig.h"
#include "graphics.h"
#include "pokedex.h"
#include "event_data.h"
#include "random.h"

enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_WORLD_DIRECTOR,
    PAGE_LEAD_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_PROGRAMMERS_4,
    PAGE_GRAPHIC_DESIGNERS_1,
    PAGE_GRAPHIC_DESIGNERS_2,
    PAGE_GRAPHIC_DESIGNERS_3,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_SCENARIO_PLOT,
    PAGE_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_BATTLE_FRONTIER_DATA,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1,
    PAGE_PKMN_DESIGNERS_1,
    PAGE_PKMN_DESIGNERS_2,
    PAGE_PKMN_DESIGNERS_3,
    PAGE_PKMN_DESIGNERS_4,
    PAGE_SUPPORT_PROGRAMMERS,
    PAGE_NCL_PRODUCT_TESTING,
    PAGE_PACKAGE_AND_MANUAL,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_ARTWORK_1,
    PAGE_ARTWORK_2,
    PAGE_ARTWORK_3,
    PAGE_COORDINATORS,
    PAGE_ENGLISH_VERSION,
    PAGE_TRANSLATOR,
    PAGE_TEXT_EDITOR,
    PAGE_NCL_COORDINATOR,
    PAGE_PROGRAMMERS_5,
    PAGE_GRAPHIC_DESIGNER,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2,
    PAGE_NOA_TESTING,
    PAGE_BRAILLE_CODE_CHECK_1,
    PAGE_BRAILLE_CODE_CHECK_2,
    PAGE_SPECIAL_THANKS_5,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_COUNT
};

#define COLOR_DARK_GREEN RGB(7, 11, 6)
#define COLOR_LIGHT_GREEN RGB(13, 20, 12)

enum
{
    TDA_0 = 0,
    TDA_TASK_C_ID = 1,
    TDA_TASK_E_ID = 2,
    TDA_TASK_D_ID = 3,
    TDA_4 = 4,
    TDA_PLAYER_CYCLIST = 5,
    TDA_RIVAL_CYCLIST = 6,
    TDA_7 = 7, // Has something to do with the bike scene
    TDA_11 = 11, // Gets set depending on whether the bike or the grass scene should be shown
    TDA_12 = 12,
    TDA_13 = 13,
    TDA_14 = 14,
    TDA_TASK_B_ID = 15,

    // Appears to be responsible for text
    TDB_0 = 0,
    TDB_TASK_A_ID = 1,
    TDB_CURRENT_PAGE = 2,
    TDB_3 = 3,

    TDC_0 = 0,
    TDC_1 = 1,
    TDC_2 = 2,
    TDC_3 = 3,
    TDC_4 = 4,
    TDC_5 = 5,

    TDD_STATE = 0,
    TDD_TASK_A_ID = 1,
    TDD_2 = 2,
    TDD_3 = 3,

    TDE_0 = 0,
    TDE_1 = 1,
    TDE_TASK_A_ID = 2,
};

#define NUM_MON_SLIDES 71
struct CreditsData
{
    u16 monToShow[NUM_MON_SLIDES]; // List of Pokemon species ids that will show during the credits
    u16 imgCounter; //how many mon images have been shown
    u16 nextImgPos; //if the next image spawns left/center/right
    u16 currShownMon; //index into monToShow
    u16 numMonToShow; //number of pokemon to show, always NUM_MON_SLIDES after determine function
    u16 caughtMonIds[NATIONAL_DEX_COUNT]; //temporary location to hold a condensed array of all caught pokemon
    u16 numCaughtMon; //count of filled spaces in caughtMonIds
    u16 unused[7];
};

struct CreditsEntry
{
    u8 var_0;
    bool8 isTitle;
    const u8 *text;
};

static EWRAM_DATA s16 gUnknown_0203BCE0 = 0;
static EWRAM_DATA u16 gUnknown_0203BCE2 = 0; // TASK A
EWRAM_DATA bool8 gHasHallOfFameRecords = 0;
static EWRAM_DATA u8 gUnknown_0203BCE5 = 0;
static EWRAM_DATA struct CreditsData *sCreditsData = {0};

static const u16 gUnknown_085E56F0[][16] =
{
    INCBIN_U16("graphics/credits/credits_1.gbapal"),
    INCBIN_U16("graphics/credits/credits_2.gbapal"),
    INCBIN_U16("graphics/credits/credits_3.gbapal"),
    INCBIN_U16("graphics/credits/credits_4.gbapal"),
};

static const u32 sCreditsCopyrightEnd_Gfx[] = INCBIN_U32("graphics/credits/the_end_copyright.4bpp.lz");

static void sub_81772B8(struct Sprite *sprite);

static const u8 sTheEnd_LetterTMap[] =
{
    0,    1, 0,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
};

static const u8 sTheEnd_LetterHMap[] =
{
    1, 0xFF, 1,
    1, 0xFF, 1,
    1, 2,    1,
    1, 0xFF, 1,
    1, 0xFF, 1,
};

static const u8 sTheEnd_LetterEMap[] =
{
    1, 0, 0,
    1, 0xFF, 0xFF,
    1, 2,    2,
    1, 0xFF, 0xFF,
    1, 0x80, 0x80,
};

static const u8 sTheEnd_LetterNMap[] =
{
    1, 3, 1,
    1, 4, 1,
    1, 5, 1,
    1, 0xC4, 1,
    1, 0xC3, 1,
};

static const u8 sTheEnd_LetterDMap[] =
{
    1, 6, 7,
    1, 8, 9,
    1, 0xFF, 1,
    1, 0x88, 0x89,
    1, 0x86, 0x87,
};

static const u8 sCreditsText_EmptyString[]                    = _("");
static const u8 sCreditsText_PkmnEmeraldVersion[]             = _("POKéMON EMERALD VERSION");
static const u8 sCreditsText_Credits[]                        = _("Credits");
static const u8 sCreditsText_ExecutiveDirector[]              = _("Executive Director");
static const u8 sCreditsText_Director[]                       = _("Director");
static const u8 sCreditsText_ArtDirector[]                    = _("Art Director");
static const u8 sCreditsText_BattleDirector[]                 = _("Battle Director");
static const u8 sCreditsText_MainProgrammer[]                 = _("Main Programmer");
static const u8 sCreditsText_BattleSystemPgrms[]              = _("Battle System Programmers");
static const u8 sCreditsText_FieldSystemPgrms[]               = _("Field System Programmer");
static const u8 sCreditsText_Programmers[]                    = _("Programmers");
static const u8 sCreditsText_MainGraphicDesigner[]            = _("Main Graphic Designer");
static const u8 sCreditsText_GraphicDesigners[]               = _("Graphic Designers");
static const u8 sCreditsText_PkmnDesigners[]                  = _("POKéMON Designers");
static const u8 sCreditsText_MusicComposition[]               = _("Music Composition");
static const u8 sCreditsText_SoundEffectsAndPkmnVoices[]      = _("Sound Effects & POKéMON Voices");
static const u8 sCreditsText_GameDesigners[]                  = _("Game Designers");
static const u8 sCreditsText_ScenarioPlot[]                   = _("Scenario Plot");
static const u8 sCreditsText_Scenario[]                       = _("Scenario");
static const u8 sCreditsText_ScriptDesigners[]                = _("Script Designers");
static const u8 sCreditsText_MapDesigners[]                   = _("Map Designers");
static const u8 sCreditsText_MapDataDesigners[]               = _("Map Data Designers");
static const u8 sCreditsText_ParametricDesigners[]            = _("Parametric Designers");
static const u8 sCreditsText_PokedexText[]                    = _("POKéDEX Text");
static const u8 sCreditsText_EnvAndToolPgrms[]                = _("Environment & Tool Programmers");
static const u8 sCreditsText_NCLProductTesting[]              = _("NCL Product Testing");
static const u8 sCreditsText_SpecialThanks[]                  = _("Special Thanks");
static const u8 sCreditsText_Coordinators[]                   = _("Coordinators");
static const u8 sCreditsText_Producers[]                      = _("Producers");
static const u8 sCreditsText_ExecProducers[]                  = _("Executive Producers");
static const u8 sCreditsText_InfoSupervisors[]                = _("Information Supervisors");
static const u8 sCreditsText_TaskManagers[]                   = _("Task Managers");
static const u8 sCreditsText_BrailleCodeCheck[]               = _("Braille Code Check");
static const u8 sCreditsText_WorldDirector[]                  = _("World Director");
static const u8 sCreditsText_BattleFrontierData[]             = _("Battle Frontier Data");
static const u8 sCreditsText_SupportProgrammers[]             = _("Support Programmers");
static const u8 sCreditsText_Artwork[]                        = _("Artwork");
static const u8 sCreditsText_LeadProgrammer[]                 = _("Lead Programmer");
static const u8 sCreditsText_LeadGraphicArtist[]              = _("Lead Graphic Artist");
static const u8 sCreditsText_SatoshiTajiri[]                  = _("Satoshi Tajiri");
static const u8 sCreditsText_JunichiMasuda[]                  = _("Junichi Masuda");
static const u8 sCreditsText_KenSugimori[]                    = _("Ken Sugimori");
static const u8 sCreditsText_ShigekiMorimoto[]                = _("Shigeki Morimoto");
static const u8 sCreditsText_TetsuyaWatanabe[]                = _("Tetsuya Watanabe");
static const u8 sCreditsText_HisashiSogabe[]                  = _("Hisashi Sogabe");
static const u8 sCreditsText_SosukeTamada[]                   = _("Sosuke Tamada");
static const u8 sCreditsText_AkitoMori[]                      = _("Akito Mori");
static const u8 sCreditsText_KeitaKagaya[]                    = _("Keita Kagaya");
static const u8 sCreditsText_YoshinoriMatsuda[]               = _("Yoshinori Matsuda");
static const u8 sCreditsText_HiroyukiNakamura[]               = _("Hiroyuki Nakamura");
static const u8 sCreditsText_MasaoTaya[]                      = _("Masao Taya");
static const u8 sCreditsText_SatoshiNohara[]                  = _("Satoshi Nohara");
static const u8 sCreditsText_TomomichiOhta[]                  = _("Tomomichi Ohta");
static const u8 sCreditsText_MiyukiIwasawa[]                  = _("Miyuki Iwasawa");
static const u8 sCreditsText_TakenoriOhta[]                   = _("Takenori Ohta");
static const u8 sCreditsText_HironobuYoshida[]                = _("Hironobu Yoshida");
static const u8 sCreditsText_MotofumiFujiwara[]               = _("Motofumi Fujiwara");
static const u8 sCreditsText_SatoshiOhta[]                    = _("Satoshi Ohta");
static const u8 sCreditsText_AsukaIwashita[]                  = _("Asuka Iwashita");
static const u8 sCreditsText_AimiTomita[]                     = _("Aimi Tomita");
static const u8 sCreditsText_TakaoUnno[]                      = _("Takao Unno");
static const u8 sCreditsText_KanakoEo[]                       = _("Kanako Eo");
static const u8 sCreditsText_JunOkutani[]                     = _("Jun Okutani");
static const u8 sCreditsText_AtsukoNishida[]                  = _("Atsuko Nishida");
static const u8 sCreditsText_MuneoSaito[]                     = _("Muneo Saito");
static const u8 sCreditsText_RenaYoshikawa[]                  = _("Rena Yoshikawa");
static const u8 sCreditsText_GoIchinose[]                     = _("Go Ichinose");
static const u8 sCreditsText_MorikazuAoki[]                   = _("Morikazu Aoki");
static const u8 sCreditsText_KojiNishino[]                    = _("Koji Nishino");
static const u8 sCreditsText_KenjiMatsushima[]                = _("Kenji Matsushima");
static const u8 sCreditsText_TetsujiOhta[]                    = _("Tetsuji Ohta");
static const u8 sCreditsText_HitomiSato[]                     = _("Hitomi Sato");
static const u8 sCreditsText_TakeshiKawachimaru[]             = _("Takeshi Kawachimaru");
static const u8 sCreditsText_TeruyukiShimoyamada[]            = _("Teruyuki Shimoyamada");
static const u8 sCreditsText_ShigeruOhmori[]                  = _("Shigeru Ohmori");
static const u8 sCreditsText_TadashiTakahashi[]               = _("Tadashi Takahashi");
static const u8 sCreditsText_ToshinobuMatsumiya[]             = _("Toshinobu Matsumiya");
static const u8 sCreditsText_AkihitoTomisawa[]                = _("Akihito Tomisawa");
static const u8 sCreditsText_HirokiEnomoto[]                  = _("Hiroki Enomoto");
static const u8 sCreditsText_KazuyukiTerada[]                 = _("Kazuyuki Terada");
static const u8 sCreditsText_YuriSakurai[]                    = _("Yuri Sakurai");
static const u8 sCreditsText_HiromiSagawa[]                   = _("Hiromi Sagawa");
static const u8 sCreditsText_KenjiTominaga[]                  = _("Kenji Tominaga");
static const u8 sCreditsText_YoshioTajiri[]                   = _("Yoshio Tajiri");
static const u8 sCreditsText_TeikoSasaki[]                    = _("Teiko Sasaki");
static const u8 sCreditsText_SachikoHamano[]                  = _("Sachiko Hamano");
static const u8 sCreditsText_ChieMatsumiya[]                  = _("Chie Matsumiya");
static const u8 sCreditsText_AkikoShinozaki[]                 = _("Akiko Shinozaki");
static const u8 sCreditsText_AstukoFujii[]                    = _("Astuko Fujii");
static const u8 sCreditsText_NozomuSaito[]                    = _("Nozomu Saito");
static const u8 sCreditsText_KenkichiToyama[]                 = _("Kenkichi Toyama");
static const u8 sCreditsText_SuguruNakatsui[]                 = _("Suguru Nakatsui");
static const u8 sCreditsText_YumiFunasaka[]                   = _("Yumi Funasaka");
static const u8 sCreditsText_NaokoYanase[]                    = _("Naoko Yanase");
static const u8 sCreditsText_NCLSuperMarioClub[]              = _("NCL Super Mario Club");
static const u8 sCreditsText_AtsushiTada[]                    = _("Atsushi Tada");
static const u8 sCreditsText_TakahiroOhnishi[]                = _("Takahiro Ohnishi");
static const u8 sCreditsText_NorihideOkamura[]                = _("Norihide Okamura");
static const u8 sCreditsText_HiroNakamura[]                   = _("Hiro Nakamura");
static const u8 sCreditsText_HiroyukiUesugi[]                 = _("Hiroyuki Uesugi");
static const u8 sCreditsText_TerukiMurakawa[]                 = _("Teruki Murakawa");
static const u8 sCreditsText_AkiraKinashi[]                   = _("Akira Kinashi");
static const u8 sCreditsText_MichikoTakizawa[]                = _("Michiko Takizawa");
static const u8 sCreditsText_MakikoTakada[]                   = _("Makiko Takada");
static const u8 sCreditsText_TakanaoKondo[]                   = _("Takanao Kondo");
static const u8 sCreditsText_AiMashima[]                      = _("Ai Mashima");
static const u8 sCreditsText_GakujiNomoto[]                   = _("Gakuji Nomoto");
static const u8 sCreditsText_TakehiroIzushi[]                 = _("Takehiro Izushi");
static const u8 sCreditsText_HitoshiYamagami[]                = _("Hitoshi Yamagami");
static const u8 sCreditsText_KyokoWatanabe[]                  = _("Kyoko Watanabe");
static const u8 sCreditsText_TakaoNakano[]                    = _("Takao Nakano");
static const u8 sCreditsText_HiroyukiJinnai[]                 = _("Hiroyuki Jinnai");
static const u8 sCreditsText_HiroakiTsuru[]                   = _("Hiroaki Tsuru");
static const u8 sCreditsText_TsunekazIshihara[]               = _("Tsunekaz Ishihara");
static const u8 sCreditsText_SatoruIwata[]                    = _("Satoru Iwata");
static const u8 sCreditsText_KazuyaSuyama[]                   = _("Kazuya Suyama");
static const u8 sCreditsText_SatoshiMitsuhara[]               = _("Satoshi Mitsuhara");
static const u8 sCreditsText_JapanBrailleLibrary[]            = _("Japan Braille Library");
static const u8 sCreditsText_TomotakaKomura[]                 = _("Tomotaka Komura");
static const u8 sCreditsText_MikikoOhhashi[]                  = _("Mikiko Ohhashi");
static const u8 sCreditsText_DaisukeHoshino[]                 = _("Daisuke Hoshino");
static const u8 sCreditsText_KenjiroIto[]                     = _("Kenjiro Ito");
static const u8 sCreditsText_RuiKawaguchi[]                   = _("Rui Kawaguchi");
static const u8 sCreditsText_ShunsukeKohori[]                 = _("Shunsuke Kohori");
static const u8 sCreditsText_SachikoNakamichi[]               = _("Sachiko Nakamichi");
static const u8 sCreditsText_FujikoNomura[]                   = _("Fujiko Nomura");
static const u8 sCreditsText_KazukiYoshihara[]                = _("Kazuki Yoshihara");
static const u8 sCreditsText_RetsujiNomoto[]                  = _("Retsuji Nomoto");
static const u8 sCreditsText_AzusaTajima[]                    = _("Azusa Tajima");
static const u8 sCreditsText_ShusakuEgami[]                   = _("Shusaku Egami");
static const u8 sCreditsText_PackageAndManual[]               = _("Package & Manual Illustration");
static const u8 sCreditsText_EnglishVersion[]                 = _("English Version Coordinators");
static const u8 sCreditsText_Translator[]                     = _("Translator");
static const u8 sCreditsText_TextEditor[]                     = _("Text Editor");
static const u8 sCreditsText_NCLCoordinator[]                 = _("NCL Coordinator");
static const u8 sCreditsText_GraphicDesigner[]                = _("Graphic Designer");
static const u8 sCreditsText_NOAProductTesting[]              = _("NOA Product Testing");
static const u8 sCreditsText_HideyukiNakajima[]               = _("Hideyuki Nakajima");
static const u8 sCreditsText_HidenoriSaeki[]                  = _("Hidenori Saeki");
static const u8 sCreditsText_YokoWatanabe[]                   = _("Yoko Watanabe");
static const u8 sCreditsText_SakaeKimura[]                    = _("Sakae Kimura");
static const u8 sCreditsText_ChiakiShinkai[]                  = _("Chiaki Shinkai");
static const u8 sCreditsText_SethMcMahill[]                   = _("Seth McMahill");
static const u8 sCreditsText_NobOgasawara[]                   = _("Nob Ogasawara");
static const u8 sCreditsText_TeresaLillygren[]                = _("Teresa Lillygren");
static const u8 sCreditsText_KimikoNakamichi[]                = _("Kimiko Nakamichi");
static const u8 sCreditsText_SouichiYamamoto[]                = _("Souichi Yamamoto");
static const u8 sCreditsText_YuichiroIto[]                    = _("Yuichiro Ito");
static const u8 sCreditsText_ThomasHertzog[]                  = _("Thomas Hertzog");
static const u8 sCreditsText_MikaKurosawa[]                   = _("Mika Kurosawa");
static const u8 sCreditsText_NationalFederationBlind[]        = _("National Federation of the Blind");
static const u8 sCreditsText_PatriciaAMaurer[]                = _("Patricia A. Maurer");
static const u8 sCreditsText_EuropeanBlindUnion[]             = _("European Blind Union");
static const u8 sCreditsText_AustralianBrailleAuthority[]     = _("Australian Braille Authority");
static const u8 sCreditsText_RoyalNewZealandFederationBlind[] = _("Royal New Zealand Federation for the Blind");
static const u8 sCreditsText_MotoyasuTojima[]                 = _("Motoyasu Tojima");
static const u8 sCreditsText_NicolaPrattBarlow[]              = _("Nicola Pratt-Barlow");
static const u8 sCreditsText_ShellieDow[]                     = _("Shellie Dow");
static const u8 sCreditsText_ErikJohnson[]                    = _("Erik Johnson");
static const struct CreditsEntry sCreditsEntry_EmptyString[]                    = { 0, FALSE, sCreditsText_EmptyString};
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion[]             = { 7,  TRUE, sCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry sCreditsEntry_Credits[]                        = {11,  TRUE, sCreditsText_Credits};
static const struct CreditsEntry sCreditsEntry_ExecutiveDirector[]              = { 8,  TRUE, sCreditsText_ExecutiveDirector};
static const struct CreditsEntry sCreditsEntry_Director[]                       = {12,  TRUE, sCreditsText_Director};
static const struct CreditsEntry sCreditsEntry_ArtDirector[]                    = {10,  TRUE, sCreditsText_ArtDirector};
static const struct CreditsEntry sCreditsEntry_BattleDirector[]                 = {10,  TRUE, sCreditsText_BattleDirector};
static const struct CreditsEntry sCreditsEntry_MainProgrammer[]                 = {10,  TRUE, sCreditsText_MainProgrammer};
static const struct CreditsEntry sCreditsEntry_BattleSystemPgrms[]              = { 8,  TRUE, sCreditsText_BattleSystemPgrms};
static const struct CreditsEntry sCreditsEntry_FieldSystemPgrms[]               = { 7,  TRUE, sCreditsText_FieldSystemPgrms};
static const struct CreditsEntry sCreditsEntry_Programmers[]                    = {12,  TRUE, sCreditsText_Programmers};
static const struct CreditsEntry sCreditsEntry_MainGraphicDesigner[]            = { 7,  TRUE, sCreditsText_MainGraphicDesigner};
static const struct CreditsEntry sCreditsEntry_GraphicDesigners[]               = { 9,  TRUE, sCreditsText_GraphicDesigners};
static const struct CreditsEntry sCreditsEntry_PkmnDesigners[]                  = {10,  TRUE, sCreditsText_PkmnDesigners};
static const struct CreditsEntry sCreditsEntry_MusicComposition[]               = {13,  TRUE, sCreditsText_MusicComposition};
static const struct CreditsEntry sCreditsEntry_SoundEffectsAndPkmnVoices[]      = { 4,  TRUE, sCreditsText_SoundEffectsAndPkmnVoices};
static const struct CreditsEntry sCreditsEntry_GameDesigners[]                  = {11,  TRUE, sCreditsText_GameDesigners};
static const struct CreditsEntry sCreditsEntry_ScenarioPlot[]                   = {11,  TRUE, sCreditsText_ScenarioPlot};
static const struct CreditsEntry sCreditsEntry_Scenario[]                       = {13,  TRUE, sCreditsText_Scenario};
static const struct CreditsEntry sCreditsEntry_ScriptDesigners[]                = {10,  TRUE, sCreditsText_ScriptDesigners};
static const struct CreditsEntry sCreditsEntry_MapDesigners[]                   = {11,  TRUE, sCreditsText_MapDesigners};
static const struct CreditsEntry sCreditsEntry_MapDataDesigners[]               = { 9,  TRUE, sCreditsText_MapDataDesigners};
static const struct CreditsEntry sCreditsEntry_ParametricDesigners[]            = { 9,  TRUE, sCreditsText_ParametricDesigners};
static const struct CreditsEntry sCreditsEntry_PokedexText[]                    = {11,  TRUE, sCreditsText_PokedexText};
static const struct CreditsEntry sCreditsEntry_EnvAndToolPgrms[]                = { 6,  TRUE, sCreditsText_EnvAndToolPgrms};
static const struct CreditsEntry sCreditsEntry_NCLProductTesting[]              = {11,  TRUE, sCreditsText_NCLProductTesting};
static const struct CreditsEntry sCreditsEntry_SpecialThanks[]                  = {10,  TRUE, sCreditsText_SpecialThanks};
static const struct CreditsEntry sCreditsEntry_Coordinators[]                   = {11,  TRUE, sCreditsText_Coordinators};
static const struct CreditsEntry sCreditsEntry_Producers[]                      = {11,  TRUE, sCreditsText_Producers};
static const struct CreditsEntry sCreditsEntry_ExecProducers[]                  = { 7,  TRUE, sCreditsText_ExecProducers};
static const struct CreditsEntry sCreditsEntry_InfoSupervisors[]                = {10,  TRUE, sCreditsText_InfoSupervisors};
static const struct CreditsEntry sCreditsEntry_TaskManagers[]                   = { 8,  TRUE, sCreditsText_TaskManagers};
static const struct CreditsEntry sCreditsEntry_BrailleCodeCheck[]               = {10,  TRUE, sCreditsText_BrailleCodeCheck};
static const struct CreditsEntry sCreditsEntry_WorldDirector[]                  = {10,  TRUE, sCreditsText_WorldDirector};
static const struct CreditsEntry sCreditsEntry_BattleFrontierData[]             = { 8,  TRUE, sCreditsText_BattleFrontierData};
static const struct CreditsEntry sCreditsEntry_SupportProgrammers[]             = {10,  TRUE, sCreditsText_SupportProgrammers};
static const struct CreditsEntry sCreditsEntry_Artwork[]                        = {12,  TRUE, sCreditsText_Artwork};
static const struct CreditsEntry sCreditsEntry_LeadProgrammer[]                 = {10,  TRUE, sCreditsText_LeadProgrammer};
static const struct CreditsEntry sCreditsEntry_LeadGraphicArtist[]              = { 9,  TRUE, sCreditsText_LeadGraphicArtist};
static const struct CreditsEntry sCreditsEntry_SatoshiTajiri[]                  = {11, FALSE, sCreditsText_SatoshiTajiri};
static const struct CreditsEntry sCreditsEntry_JunichiMasuda[]                  = {11, FALSE, sCreditsText_JunichiMasuda};
static const struct CreditsEntry sCreditsEntry_KenSugimori[]                    = {11, FALSE, sCreditsText_KenSugimori};
static const struct CreditsEntry sCreditsEntry_ShigekiMorimoto[]                = {11, FALSE, sCreditsText_ShigekiMorimoto};
static const struct CreditsEntry sCreditsEntry_TetsuyaWatanabe[]                = {11, FALSE, sCreditsText_TetsuyaWatanabe};
static const struct CreditsEntry sCreditsEntry_HisashiSogabe[]                  = {11, FALSE, sCreditsText_HisashiSogabe};
static const struct CreditsEntry sCreditsEntry_SosukeTamada[]                   = {11, FALSE, sCreditsText_SosukeTamada};
static const struct CreditsEntry sCreditsEntry_AkitoMori[]                      = {11, FALSE, sCreditsText_AkitoMori};
static const struct CreditsEntry sCreditsEntry_KeitaKagaya[]                    = {11, FALSE, sCreditsText_KeitaKagaya};
static const struct CreditsEntry sCreditsEntry_YoshinoriMatsuda[]               = {11, FALSE, sCreditsText_YoshinoriMatsuda};
static const struct CreditsEntry sCreditsEntry_HiroyukiNakamura[]               = {11, FALSE, sCreditsText_HiroyukiNakamura};
static const struct CreditsEntry sCreditsEntry_MasaoTaya[]                      = {11, FALSE, sCreditsText_MasaoTaya};
static const struct CreditsEntry sCreditsEntry_SatoshiNohara[]                  = {11, FALSE, sCreditsText_SatoshiNohara};
static const struct CreditsEntry sCreditsEntry_TomomichiOhta[]                  = {11, FALSE, sCreditsText_TomomichiOhta};
static const struct CreditsEntry sCreditsEntry_MiyukiIwasawa[]                  = {11, FALSE, sCreditsText_MiyukiIwasawa};
static const struct CreditsEntry sCreditsEntry_TakenoriOhta[]                   = {11, FALSE, sCreditsText_TakenoriOhta};
static const struct CreditsEntry sCreditsEntry_HironobuYoshida[]                = {11, FALSE, sCreditsText_HironobuYoshida};
static const struct CreditsEntry sCreditsEntry_MotofumiFujiwara[]               = {11, FALSE, sCreditsText_MotofumiFujiwara};
static const struct CreditsEntry sCreditsEntry_SatoshiOhta[]                    = {11, FALSE, sCreditsText_SatoshiOhta};
static const struct CreditsEntry sCreditsEntry_AsukaIwashita[]                  = {11, FALSE, sCreditsText_AsukaIwashita};
static const struct CreditsEntry sCreditsEntry_AimiTomita[]                     = {11, FALSE, sCreditsText_AimiTomita};
static const struct CreditsEntry sCreditsEntry_TakaoUnno[]                      = {11, FALSE, sCreditsText_TakaoUnno};
static const struct CreditsEntry sCreditsEntry_KanakoEo[]                       = {11, FALSE, sCreditsText_KanakoEo};
static const struct CreditsEntry sCreditsEntry_JunOkutani[]                     = {11, FALSE, sCreditsText_JunOkutani};
static const struct CreditsEntry sCreditsEntry_AtsukoNishida[]                  = {11, FALSE, sCreditsText_AtsukoNishida};
static const struct CreditsEntry sCreditsEntry_MuneoSaito[]                     = {11, FALSE, sCreditsText_MuneoSaito};
static const struct CreditsEntry sCreditsEntry_RenaYoshikawa[]                  = {11, FALSE, sCreditsText_RenaYoshikawa};
static const struct CreditsEntry sCreditsEntry_GoIchinose[]                     = {11, FALSE, sCreditsText_GoIchinose};
static const struct CreditsEntry sCreditsEntry_MorikazuAoki[]                   = {11, FALSE, sCreditsText_MorikazuAoki};
static const struct CreditsEntry sCreditsEntry_KojiNishino[]                    = {11, FALSE, sCreditsText_KojiNishino};
static const struct CreditsEntry sCreditsEntry_KenjiMatsushima[]                = {11, FALSE, sCreditsText_KenjiMatsushima};
static const struct CreditsEntry sCreditsEntry_TetsujiOhta[]                    = {11, FALSE, sCreditsText_TetsujiOhta};
static const struct CreditsEntry sCreditsEntry_HitomiSato[]                     = {11, FALSE, sCreditsText_HitomiSato};
static const struct CreditsEntry sCreditsEntry_TakeshiKawachimaru[]             = {11, FALSE, sCreditsText_TakeshiKawachimaru};
static const struct CreditsEntry sCreditsEntry_TeruyukiShimoyamada[]            = {11, FALSE, sCreditsText_TeruyukiShimoyamada};
static const struct CreditsEntry sCreditsEntry_ShigeruOhmori[]                  = {11, FALSE, sCreditsText_ShigeruOhmori};
static const struct CreditsEntry sCreditsEntry_TadashiTakahashi[]               = {11, FALSE, sCreditsText_TadashiTakahashi};
static const struct CreditsEntry sCreditsEntry_ToshinobuMatsumiya[]             = {11, FALSE, sCreditsText_ToshinobuMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkihitoTomisawa[]                = {11, FALSE, sCreditsText_AkihitoTomisawa};
static const struct CreditsEntry sCreditsEntry_HirokiEnomoto[]                  = {11, FALSE, sCreditsText_HirokiEnomoto};
static const struct CreditsEntry sCreditsEntry_KazuyukiTerada[]                 = {11, FALSE, sCreditsText_KazuyukiTerada};
static const struct CreditsEntry sCreditsEntry_YuriSakurai[]                    = {11, FALSE, sCreditsText_YuriSakurai};
static const struct CreditsEntry sCreditsEntry_HiromiSagawa[]                   = {11, FALSE, sCreditsText_HiromiSagawa};
static const struct CreditsEntry sCreditsEntry_KenjiTominaga[]                  = {11, FALSE, sCreditsText_KenjiTominaga};
static const struct CreditsEntry sCreditsEntry_YoshioTajiri[]                   = {11, FALSE, sCreditsText_YoshioTajiri};
static const struct CreditsEntry sCreditsEntry_TeikoSasaki[]                    = {11, FALSE, sCreditsText_TeikoSasaki};
static const struct CreditsEntry sCreditsEntry_SachikoHamano[]                  = {11, FALSE, sCreditsText_SachikoHamano};
static const struct CreditsEntry sCreditsEntry_ChieMatsumiya[]                  = {11, FALSE, sCreditsText_ChieMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkikoShinozaki[]                 = {11, FALSE, sCreditsText_AkikoShinozaki};
static const struct CreditsEntry sCreditsEntry_AstukoFujii[]                    = {11, FALSE, sCreditsText_AstukoFujii};
static const struct CreditsEntry sCreditsEntry_NozomuSaito[]                    = {11, FALSE, sCreditsText_NozomuSaito};
static const struct CreditsEntry sCreditsEntry_KenkichiToyama[]                 = {11, FALSE, sCreditsText_KenkichiToyama};
static const struct CreditsEntry sCreditsEntry_SuguruNakatsui[]                 = {11, FALSE, sCreditsText_SuguruNakatsui};
static const struct CreditsEntry sCreditsEntry_YumiFunasaka[]                   = {11, FALSE, sCreditsText_YumiFunasaka};
static const struct CreditsEntry sCreditsEntry_NaokoYanase[]                    = {11, FALSE, sCreditsText_NaokoYanase};
static const struct CreditsEntry sCreditsEntry_NCLSuperMarioClub[]              = {11, FALSE, sCreditsText_NCLSuperMarioClub};
static const struct CreditsEntry sCreditsEntry_AtsushiTada[]                    = {11, FALSE, sCreditsText_AtsushiTada};
static const struct CreditsEntry sCreditsEntry_TakahiroOhnishi[]                = {11, FALSE, sCreditsText_TakahiroOhnishi};
static const struct CreditsEntry sCreditsEntry_NorihideOkamura[]                = {11, FALSE, sCreditsText_NorihideOkamura};
static const struct CreditsEntry sCreditsEntry_HiroNakamura[]                   = {11, FALSE, sCreditsText_HiroNakamura};
static const struct CreditsEntry sCreditsEntry_HiroyukiUesugi[]                 = {11, FALSE, sCreditsText_HiroyukiUesugi};
static const struct CreditsEntry sCreditsEntry_TerukiMurakawa[]                 = {11, FALSE, sCreditsText_TerukiMurakawa};
static const struct CreditsEntry sCreditsEntry_AkiraKinashi[]                   = {11, FALSE, sCreditsText_AkiraKinashi};
static const struct CreditsEntry sCreditsEntry_MichikoTakizawa[]                = {11, FALSE, sCreditsText_MichikoTakizawa};
static const struct CreditsEntry sCreditsEntry_MakikoTakada[]                   = {11, FALSE, sCreditsText_MakikoTakada};
static const struct CreditsEntry sCreditsEntry_TakanaoKondo[]                   = {11, FALSE, sCreditsText_TakanaoKondo};
static const struct CreditsEntry sCreditsEntry_AiMashima[]                      = {11, FALSE, sCreditsText_AiMashima};
static const struct CreditsEntry sCreditsEntry_GakujiNomoto[]                   = {11, FALSE, sCreditsText_GakujiNomoto};
static const struct CreditsEntry sCreditsEntry_TakehiroIzushi[]                 = {11, FALSE, sCreditsText_TakehiroIzushi};
static const struct CreditsEntry sCreditsEntry_HitoshiYamagami[]                = {11, FALSE, sCreditsText_HitoshiYamagami};
static const struct CreditsEntry sCreditsEntry_KyokoWatanabe[]                  = {11, FALSE, sCreditsText_KyokoWatanabe};
static const struct CreditsEntry sCreditsEntry_TakaoNakano[]                    = {11, FALSE, sCreditsText_TakaoNakano};
static const struct CreditsEntry sCreditsEntry_HiroyukiJinnai[]                 = {11, FALSE, sCreditsText_HiroyukiJinnai};
static const struct CreditsEntry sCreditsEntry_HiroakiTsuru[]                   = {11, FALSE, sCreditsText_HiroakiTsuru};
static const struct CreditsEntry sCreditsEntry_TsunekazIshihara[]               = {11, FALSE, sCreditsText_TsunekazIshihara};
static const struct CreditsEntry sCreditsEntry_SatoruIwata[]                    = {11, FALSE, sCreditsText_SatoruIwata};
static const struct CreditsEntry sCreditsEntry_KazuyaSuyama[]                   = {11, FALSE, sCreditsText_KazuyaSuyama};
static const struct CreditsEntry sCreditsEntry_SatoshiMitsuhara[]               = {11, FALSE, sCreditsText_SatoshiMitsuhara};
static const struct CreditsEntry sCreditsEntry_JapanBrailleLibrary[]            = { 9, FALSE, sCreditsText_JapanBrailleLibrary};
static const struct CreditsEntry sCreditsEntry_TomotakaKomura[]                 = {11, FALSE, sCreditsText_TomotakaKomura};
static const struct CreditsEntry sCreditsEntry_MikikoOhhashi[]                  = {11, FALSE, sCreditsText_MikikoOhhashi};
static const struct CreditsEntry sCreditsEntry_DaisukeHoshino[]                 = {11, FALSE, sCreditsText_DaisukeHoshino};
static const struct CreditsEntry sCreditsEntry_KenjiroIto[]                     = {11, FALSE, sCreditsText_KenjiroIto};
static const struct CreditsEntry sCreditsEntry_RuiKawaguchi[]                   = {11, FALSE, sCreditsText_RuiKawaguchi};
static const struct CreditsEntry sCreditsEntry_ShunsukeKohori[]                 = {11, FALSE, sCreditsText_ShunsukeKohori};
static const struct CreditsEntry sCreditsEntry_SachikoNakamichi[]               = {11, FALSE, sCreditsText_SachikoNakamichi};
static const struct CreditsEntry sCreditsEntry_FujikoNomura[]                   = {11, FALSE, sCreditsText_FujikoNomura};
static const struct CreditsEntry sCreditsEntry_KazukiYoshihara[]                = {11, FALSE, sCreditsText_KazukiYoshihara};
static const struct CreditsEntry sCreditsEntry_RetsujiNomoto[]                  = {11, FALSE, sCreditsText_RetsujiNomoto};
static const struct CreditsEntry sCreditsEntry_AzusaTajima[]                    = {11, FALSE, sCreditsText_AzusaTajima};
static const struct CreditsEntry sCreditsEntry_ShusakuEgami[]                   = {11, FALSE, sCreditsText_ShusakuEgami};
static const struct CreditsEntry sCreditsEntry_PackageAndManual[]               = { 0,  TRUE, sCreditsText_PackageAndManual};
static const struct CreditsEntry sCreditsEntry_EnglishVersion[]                 = { 0,  TRUE, sCreditsText_EnglishVersion};
static const struct CreditsEntry sCreditsEntry_Translator[]                     = { 0,  TRUE, sCreditsText_Translator};
static const struct CreditsEntry sCreditsEntry_TextEditor[]                     = { 0,  TRUE, sCreditsText_TextEditor};
static const struct CreditsEntry sCreditsEntry_NCLCoordinator[]                 = { 0,  TRUE, sCreditsText_NCLCoordinator};
static const struct CreditsEntry sCreditsEntry_GraphicDesigner[]                = { 0,  TRUE, sCreditsText_GraphicDesigner};
static const struct CreditsEntry sCreditsEntry_NOAProductTesting[]              = { 0,  TRUE, sCreditsText_NOAProductTesting};
static const struct CreditsEntry sCreditsEntry_HideyukiNakajima[]               = { 0, FALSE, sCreditsText_HideyukiNakajima};
static const struct CreditsEntry sCreditsEntry_HidenoriSaeki[]                  = { 0, FALSE, sCreditsText_HidenoriSaeki};
static const struct CreditsEntry sCreditsEntry_YokoWatanabe[]                   = { 0, FALSE, sCreditsText_YokoWatanabe};
static const struct CreditsEntry sCreditsEntry_SakaeKimura[]                    = { 0, FALSE, sCreditsText_SakaeKimura};
static const struct CreditsEntry sCreditsEntry_ChiakiShinkai[]                  = { 0, FALSE, sCreditsText_ChiakiShinkai};
static const struct CreditsEntry sCreditsEntry_SethMcMahill[]                   = { 0, FALSE, sCreditsText_SethMcMahill};
static const struct CreditsEntry sCreditsEntry_NobOgasawara[]                   = { 0, FALSE, sCreditsText_NobOgasawara};
static const struct CreditsEntry sCreditsEntry_TeresaLillygren[]                = { 0, FALSE, sCreditsText_TeresaLillygren};
static const struct CreditsEntry sCreditsEntry_KimikoNakamichi[]                = { 0, FALSE, sCreditsText_KimikoNakamichi};
static const struct CreditsEntry sCreditsEntry_SouichiYamamoto[]                = { 0, FALSE, sCreditsText_SouichiYamamoto};
static const struct CreditsEntry sCreditsEntry_YuichiroIto[]                    = { 0, FALSE, sCreditsText_YuichiroIto};
static const struct CreditsEntry sCreditsEntry_ThomasHertzog[]                  = { 0, FALSE, sCreditsText_ThomasHertzog};
static const struct CreditsEntry sCreditsEntry_MikaKurosawa[]                   = { 0, FALSE, sCreditsText_MikaKurosawa};
static const struct CreditsEntry sCreditsEntry_NationalFederationBlind[]        = { 0, FALSE, sCreditsText_NationalFederationBlind};
static const struct CreditsEntry sCreditsEntry_PatriciaAMaurer[]                = { 0, FALSE, sCreditsText_PatriciaAMaurer};
static const struct CreditsEntry sCreditsEntry_EuropeanBlindUnion[]             = { 0, FALSE, sCreditsText_EuropeanBlindUnion};
static const struct CreditsEntry sCreditsEntry_AustralianBrailleAuthority[]     = { 0, FALSE, sCreditsText_AustralianBrailleAuthority};
static const struct CreditsEntry sCreditsEntry_RoyalNewZealandFederationBlind[] = { 0, FALSE, sCreditsText_RoyalNewZealandFederationBlind};
static const struct CreditsEntry sCreditsEntry_MotoyasuTojima[]                 = { 0, FALSE, sCreditsText_MotoyasuTojima};
static const struct CreditsEntry sCreditsEntry_NicolaPrattBarlow[]              = { 0, FALSE, sCreditsText_NicolaPrattBarlow};
static const struct CreditsEntry sCreditsEntry_ShellieDow[]                     = { 0, FALSE, sCreditsText_ShellieDow};
static const struct CreditsEntry sCreditsEntry_ErikJohnson[]                    = { 0, FALSE, sCreditsText_ErikJohnson};

#define _ sCreditsEntry_EmptyString
static const struct CreditsEntry *const gCreditsEntryPointerTable[][5] =
{
    {
        _,
        sCreditsEntry_PkmnEmeraldVersion,
        sCreditsEntry_Credits,
        _,
        _
    },
    {
        _,
        sCreditsEntry_Director,
        sCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_ArtDirector,
        sCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_WorldDirector,
        sCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    {
        sCreditsEntry_LeadProgrammer,
        sCreditsEntry_HisashiSogabe,
        sCreditsEntry_LeadGraphicArtist,
        sCreditsEntry_MotofumiFujiwara,
        _,
    },
    {
        sCreditsEntry_Programmers,
        sCreditsEntry_HisashiSogabe,
        sCreditsEntry_TomomichiOhta,
        sCreditsEntry_NozomuSaito,
        sCreditsEntry_EmptyString,
    },
    {
        sCreditsEntry_Programmers,
        sCreditsEntry_AkitoMori,
        sCreditsEntry_HiroyukiNakamura,
        sCreditsEntry_MasaoTaya,
        _,
    },
    {
        sCreditsEntry_Programmers,
        sCreditsEntry_SatoshiNohara,
        sCreditsEntry_MiyukiIwasawa,
        sCreditsEntry_YoshinoriMatsuda,
        sCreditsEntry_KeitaKagaya,
    },
    {
        sCreditsEntry_Programmers,
        sCreditsEntry_TetsuyaWatanabe,
        sCreditsEntry_SosukeTamada,
        sCreditsEntry_TakenoriOhta,
        _,
    },
    {
        _,
        sCreditsEntry_GraphicDesigners,
        sCreditsEntry_MotofumiFujiwara,
        sCreditsEntry_SatoshiOhta,
        _,
    },
    {
        sCreditsEntry_GraphicDesigners,
        sCreditsEntry_KenkichiToyama,
        sCreditsEntry_AsukaIwashita,
        sCreditsEntry_TakaoUnno,
        _,
    },
    {
        sCreditsEntry_GraphicDesigners,
        sCreditsEntry_KenSugimori,
        sCreditsEntry_HironobuYoshida,
        sCreditsEntry_AimiTomita,
        sCreditsEntry_KanakoEo,
    },
    {
        sCreditsEntry_MusicComposition,
        sCreditsEntry_GoIchinose,
        sCreditsEntry_JunichiMasuda,
        sCreditsEntry_MorikazuAoki,
        sCreditsEntry_HitomiSato,
    },
    {
        _,
        sCreditsEntry_SoundEffectsAndPkmnVoices,
        sCreditsEntry_GoIchinose,
        sCreditsEntry_MorikazuAoki,
        _,
    },
    {
        sCreditsEntry_GameDesigners,
        sCreditsEntry_ShigekiMorimoto,
        sCreditsEntry_TeruyukiShimoyamada,
        sCreditsEntry_TakeshiKawachimaru,
        sCreditsEntry_AkihitoTomisawa,
    },
    {
        sCreditsEntry_GameDesigners,
        sCreditsEntry_SuguruNakatsui,
        sCreditsEntry_TetsujiOhta,
        sCreditsEntry_HitomiSato,
        sCreditsEntry_KenjiMatsushima,
    },
    {
        sCreditsEntry_GameDesigners,
        sCreditsEntry_JunichiMasuda,
        sCreditsEntry_KojiNishino,
        sCreditsEntry_ShigeruOhmori,
        sCreditsEntry_TadashiTakahashi,
    },
    {
        sCreditsEntry_ScenarioPlot,
        sCreditsEntry_AkihitoTomisawa,
        sCreditsEntry_JunichiMasuda,
        sCreditsEntry_KojiNishino,
        _,
    },
    {
        sCreditsEntry_Scenario,
        sCreditsEntry_AkihitoTomisawa,
        sCreditsEntry_HitomiSato,
        sCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    {
        sCreditsEntry_ScriptDesigners,
        sCreditsEntry_TomomichiOhta,
        sCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    {
        sCreditsEntry_MapDesigners,
        sCreditsEntry_SuguruNakatsui,
        sCreditsEntry_TeruyukiShimoyamada,
        sCreditsEntry_ShigeruOhmori,
        sCreditsEntry_TetsujiOhta,
    },
    {
        _,
        sCreditsEntry_BattleFrontierData,
        sCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    {
        sCreditsEntry_ParametricDesigners,
        sCreditsEntry_TeruyukiShimoyamada,
        sCreditsEntry_ShigekiMorimoto,
        sCreditsEntry_TetsujiOhta,
        sCreditsEntry_KojiNishino,
    },
    {
        _,
        sCreditsEntry_PokedexText,
        sCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    {
        sCreditsEntry_EnvAndToolPgrms,
        sCreditsEntry_HisashiSogabe,
        sCreditsEntry_SosukeTamada,
        sCreditsEntry_HiroyukiNakamura,
        sCreditsEntry_AkitoMori,
    },
    {
        sCreditsEntry_PkmnDesigners,
        sCreditsEntry_KenSugimori,
        sCreditsEntry_MotofumiFujiwara,
        sCreditsEntry_ShigekiMorimoto,
        _,
    },
    {
        sCreditsEntry_PkmnDesigners,
        sCreditsEntry_HironobuYoshida,
        sCreditsEntry_SatoshiOhta,
        sCreditsEntry_AsukaIwashita,
        _,
    },
    {
        sCreditsEntry_PkmnDesigners,
        sCreditsEntry_TakaoUnno,
        sCreditsEntry_KanakoEo,
        sCreditsEntry_AimiTomita,
        _,
    },
    {
        sCreditsEntry_PkmnDesigners,
        sCreditsEntry_AtsukoNishida,
        sCreditsEntry_MuneoSaito,
        sCreditsEntry_RenaYoshikawa,
        sCreditsEntry_JunOkutani,
    },
    {
        _,
        sCreditsEntry_SupportProgrammers,
        sCreditsEntry_SatoshiMitsuhara,
        sCreditsEntry_DaisukeHoshino,
        _,
    },
    {
        _,
        sCreditsEntry_NCLProductTesting,
        sCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_PackageAndManual,
        sCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_KenjiTominaga,
        sCreditsEntry_HirokiEnomoto,
        _,
    },
    {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_KazuyaSuyama,
        sCreditsEntry_KenjiroIto,
        sCreditsEntry_MichikoTakizawa,
        sCreditsEntry_MakikoTakada,
    },
    {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_MikikoOhhashi,
        sCreditsEntry_TakanaoKondo,
        sCreditsEntry_RuiKawaguchi,
        _,
    },
    {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_TakahiroOhnishi,
        sCreditsEntry_NorihideOkamura,
        sCreditsEntry_ShunsukeKohori,
        _,
    },
    {
        sCreditsEntry_InfoSupervisors,
        sCreditsEntry_KazuyukiTerada,
        sCreditsEntry_YuriSakurai,
        sCreditsEntry_YumiFunasaka,
        sCreditsEntry_NaokoYanase,
    },
    {
        _,
        sCreditsEntry_Artwork,
        sCreditsEntry_SachikoNakamichi,
        sCreditsEntry_FujikoNomura,
        _,
    },
    {
        _,
        sCreditsEntry_Artwork,
        sCreditsEntry_HideyukiNakajima,
        sCreditsEntry_HidenoriSaeki,
        _,
    },
    {
        sCreditsEntry_Artwork,
        sCreditsEntry_YokoWatanabe,
        sCreditsEntry_SakaeKimura,
        sCreditsEntry_ChiakiShinkai,
        _,
    },
    {
        sCreditsEntry_Coordinators,
        sCreditsEntry_KazukiYoshihara,
        sCreditsEntry_AkiraKinashi,
        sCreditsEntry_RetsujiNomoto,
        _,
    },
    {
        _,
        sCreditsEntry_EnglishVersion,
        sCreditsEntry_HiroNakamura,
        sCreditsEntry_SethMcMahill,
        _,
    },
    {
        _,
        sCreditsEntry_Translator,
        sCreditsEntry_NobOgasawara,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_TextEditor,
        sCreditsEntry_TeresaLillygren,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_NCLCoordinator,
        sCreditsEntry_KimikoNakamichi,
        _,
        _,
    },
    {
        sCreditsEntry_Programmers,
        sCreditsEntry_TerukiMurakawa,
        sCreditsEntry_SouichiYamamoto,
        sCreditsEntry_YuichiroIto,
        sCreditsEntry_AkiraKinashi,
    },
    {
        _,
        sCreditsEntry_GraphicDesigner,
        sCreditsEntry_AkiraKinashi,
        _,
        _,
    },
    {
        sCreditsEntry_EnvAndToolPgrms,
        sCreditsEntry_TerukiMurakawa,
        sCreditsEntry_SouichiYamamoto,
        sCreditsEntry_KimikoNakamichi,
        _,
    },
    {
        sCreditsEntry_NOAProductTesting,
        sCreditsEntry_ThomasHertzog,
        sCreditsEntry_ErikJohnson,
        sCreditsEntry_MikaKurosawa,
        _,
    },
    {
        sCreditsEntry_BrailleCodeCheck,
        sCreditsEntry_NationalFederationBlind,
        sCreditsEntry_PatriciaAMaurer,
        sCreditsEntry_JapanBrailleLibrary,
        sCreditsEntry_EuropeanBlindUnion,
    },
    {
        _,
        sCreditsEntry_BrailleCodeCheck,
        sCreditsEntry_AustralianBrailleAuthority,
        sCreditsEntry_RoyalNewZealandFederationBlind,
        _,
    },
    {
        sCreditsEntry_SpecialThanks,
        sCreditsEntry_HiroyukiUesugi,
        sCreditsEntry_MotoyasuTojima,
        sCreditsEntry_NicolaPrattBarlow,
        sCreditsEntry_ShellieDow,
    },
    {
        _,
        sCreditsEntry_TaskManagers,
        sCreditsEntry_AzusaTajima,
        sCreditsEntry_ShusakuEgami,
        _,
    },
    {
        sCreditsEntry_Producers,
        sCreditsEntry_HiroyukiJinnai,
        sCreditsEntry_HitoshiYamagami,
        sCreditsEntry_GakujiNomoto,
        sCreditsEntry_HiroakiTsuru,
    },
    {
        _,
        sCreditsEntry_ExecutiveDirector,
        sCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_ExecProducers,
        sCreditsEntry_SatoruIwata,
        _,
        _,
    },
    {
        _,
        sCreditsEntry_ExecProducers,
        sCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _

static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};
static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 9,
        .width = 30,
        .height = 12,
        .paletteNum = 8,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE,
};
static const u8 sMonSpritePos[][2] =
{
    {104, 36},
    {120, 36},
    {136, 36},
};

static const union AnimCmd gUnknown_085E6F84[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gUnknown_085E6F98[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gUnknown_085E6FAC[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_FRAME(384, 4),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_085E6FBC[] =
{
    ANIMCMD_FRAME(384, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_085E6FD0[] =
{
    gUnknown_085E6F84,
    gUnknown_085E6F98,
    gUnknown_085E6FAC,
    gUnknown_085E6FBC,
};

static const union AnimCmd gUnknown_085E6FE0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gUnknown_085E6FF4[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gUnknown_085E7008[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_085E7010[] =
{
    gUnknown_085E6FE0,
    gUnknown_085E6FF4,
    gUnknown_085E7008,
};

static const struct SpriteSheet gUnknown_085E701C[] = {
    { gDecompressionBuffer, 6144, 1001 },
    { NULL },
};
static const struct SpritePalette gUnknown_085E702C[] = {
    { (const u16 *)(gDecompressionBuffer + 0x1800), 1001 },
    { NULL },
};

static const struct OamData gUnknown_085E703C =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gUnknown_085E7044[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_085E704C[] =
{
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_085E7054[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const gUnknown_085E705C[] =
{
    gUnknown_085E7044,
    gUnknown_085E704C,
    gUnknown_085E7054,
};

static const struct SpriteTemplate gUnknown_085E7068 =
{
    .tileTag = 1001,
    .paletteTag = 1001,
    .oam = &gUnknown_085E703C,
    .anims = gUnknown_085E705C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81772B8,
};

static void Task_WaitPaletteFade(u8 taskIdA);
static void Task_ProgressCreditTasks(u8 taskIdA);
static void sub_8175808(u8 taskIdA);
static void c2_080C9BFC(u8 taskIdA);
static void Task_CreditsLoadGrassScene(u8 taskIdA);
static void sub_81758A4(u8 taskIdA);
static void Task_CreditsTheEnd1(u8 taskIdA);
static void Task_CreditsTheEnd2(u8 taskIdA);
static void Task_CreditsTheEnd3(u8 taskIdA);
static void Task_CreditsTheEnd4(u8 taskIdA);
static void Task_CreditsTheEnd5(u8 taskIdA);
static void Task_CreditsTheEnd6(u8 taskIdA);
static void Task_CreditsSoftReset(u8 taskIdA);
static void ResetGpuAndVram(void);
static void sub_8175DA0(u8 taskIdB);
static u8 CheckChangeScene(u8 page, u8 taskIdA);
static void sub_81760FC(u8 taskIdA);
static void sub_817651C(u8 taskIdA);
static void sub_817624C(u8 taskIdA);
static bool8 sub_8176AB0(u8 data, u8 taskIdA);
static void ResetCreditsTasks(u8 taskIdA);
static void LoadTheEndScreen(u16, u16, u16);
static void sub_8176E40(u16 arg0, u16 palette);
static void sub_8176EE8(struct Sprite *sprite);
static void sub_8176F90(struct Sprite *sprite);
static u8 MakeMonSprite(u16 species, s16 x, s16 y, u16 position);
static void DeterminePokemonToShow(void);

static void CreditsVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_RunCreditsSequence(void)
{
    RunTasks();
    AnimateSprites();

    if ((JOY_HELD(B_BUTTON))
     && gHasHallOfFameRecords != 0
     && gTasks[gUnknown_0203BCE2].func == Task_ProgressCreditTasks)
    {
        CreditsVBlankCallback();
        RunTasks();
        AnimateSprites();
        gUnknown_0203BCE5 = 1;
    }
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void InitCreditsBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    LoadPalette(gUnknown_085E56F0, 0x80, 0x40);
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    ShowBg(0);
}

static void sub_81755A4(void)
{
    void *ptr;
    FreeAllWindowBuffers();
    ptr = GetBgTilemapBuffer(0);
    if (ptr)
        Free(ptr);
}

static void PrintCreditsText(const u8 *string, u8 y, bool8 isTitle)
{
    u8 x;
    u8 color[3];

    color[0] = 0;

    if (isTitle == TRUE)
    {
        color[1] = 3;
        color[2] = 4;
    }
    else
    {
        color[1] = 1;
        color[2] = 2;
    }

    x = GetStringCenterAlignXOffsetWithLetterSpacing(1, string, 0xF0, 1);
    AddTextPrinterParameterized4(0, 1, x, y, 1, 0, color, -1, string);
}

void CB2_StartCreditsSequence(void)
{
    u8 taskIdA;
    s16 taskIdC;
    u8 taskIdB;

    ResetGpuAndVram();
    SetVBlankCallback(NULL);
    InitHeap(gHeap, HEAP_SIZE);
    ResetPaletteFade();
    ResetTasks();
    InitCreditsBgsAndWindows();

    taskIdA = CreateTask(Task_WaitPaletteFade, 0);

    gTasks[taskIdA].data[TDA_4] = 0;
    gTasks[taskIdA].data[TDA_7] = 0;
    gTasks[taskIdA].data[TDA_11] = 0;
    gTasks[taskIdA].data[TDA_13] = 1;

    while (TRUE)
    {
        if (sub_8176AB0(0, taskIdA))
            break;
    }

    taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
    gTasks[taskIdC].data[TDC_0] = 40;

    SetGpuReg(REG_OFFSET_BG0VOFS, 0xFFFC);

    taskIdB = CreateTask(sub_8175DA0, 0);

    gTasks[taskIdB].data[TDB_TASK_A_ID] = taskIdA;
    gTasks[taskIdA].data[TDA_TASK_B_ID] = taskIdB;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(CreditsVBlankCallback);
    m4aSongNumStart(MUS_CREDITS);
    SetMainCallback2(CB2_RunCreditsSequence);
    gUnknown_0203BCE5 = 0;
    sCreditsData = AllocZeroed(sizeof(struct CreditsData));

    DeterminePokemonToShow();

    sCreditsData->imgCounter = 0;
    sCreditsData->nextImgPos = 0;
    sCreditsData->currShownMon = 0;

    gUnknown_0203BCE2 = taskIdA;
}

static void Task_WaitPaletteFade(u8 taskIdA)
{
    if (!gPaletteFade.active)
        gTasks[taskIdA].func = Task_ProgressCreditTasks;
}

static void Task_ProgressCreditTasks(u8 taskIdA)
{
    u16 data1;

    if (gTasks[taskIdA].data[TDA_4])
    {
        s16 taskIdC;

        taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
        gTasks[taskIdC].data[TDC_0] = 30;

        gTasks[taskIdA].data[TDA_12] = 0x100;
        gTasks[taskIdA].func = Task_CreditsTheEnd1;
        return;
    }

    gUnknown_0203BCE0 = 0;
    data1 = gTasks[taskIdA].data[TDA_11];

    if (gTasks[taskIdA].data[TDA_11] == 1)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_8175808;
    }
    else if (gTasks[taskIdA].data[TDA_11] == 2)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_81758A4;
    }
}

static void sub_8175808(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = c2_080C9BFC;
    }
}

static void c2_080C9BFC(u8 taskIdA)
{
    SetVBlankCallback(NULL);

    if (sub_8176AB0(gTasks[taskIdA].data[TDA_7], taskIdA))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(CreditsVBlankCallback);
        gTasks[taskIdA].func = Task_WaitPaletteFade;
    }
}

static void sub_81758A4(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = Task_CreditsLoadGrassScene;
    }
}

static void Task_CreditsLoadGrassScene(u8 taskIdA)
{
    switch (gMain.state)
    {
    default:
    case 0:
    {
        u16 i;
        u16 *temp;

        ResetSpriteData();
        ResetAllPicSprites();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
        LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));
        LoadPalette(gBirchBagGrassPal[0] + 1, 1, 31 * 2);

        for (i = 0; i < 0x800; i++)
            gDecompressionBuffer[i] = 0x11;
        for (i = 0; i < 0x800; i++)
            (gDecompressionBuffer + 0x800)[i] = 0x22;
        for (i = 0; i < 0x800; i++)
            (gDecompressionBuffer + 0x1000)[i] = 0x33;

        temp = (u16 *)(&gDecompressionBuffer[0x1800]);
        temp[0] = RGB_BLACK;
        temp[1] = RGB(31, 31, 20); // light yellow
        temp[2] = RGB(31, 20, 20); // light red
        temp[3] = RGB(20, 20, 31); // light blue

        LoadSpriteSheet(gUnknown_085E701C);
        LoadSpritePalette(gUnknown_085E702C);

        gMain.state += 1;
        break;
    }
    case 1:
        gTasks[taskIdA].data[TDA_TASK_D_ID] = CreateTask(sub_81760FC, 0);
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_STATE] = 1;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_TASK_A_ID] = taskIdA;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_2] = gTasks[taskIdA].data[TDA_7];

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 32);
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);

        gMain.state = 0;
        gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_MOVING;
        gTasks[taskIdA].func = Task_WaitPaletteFade;
        break;
    }
}

static void Task_CreditsTheEnd1(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_12])
    {
        gTasks[taskIdA].data[TDA_12] -= 1;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 12, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = Task_CreditsTheEnd2;
}

static void Task_CreditsTheEnd2(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = Task_CreditsTheEnd3;
    }
}

static void Task_CreditsTheEnd3(u8 taskIdA)
{
    ResetGpuAndVram();
    ResetPaletteFade();
    LoadTheEndScreen(0, 0x3800, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 8, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON);

    gTasks[taskIdA].data[TDA_0] = 235; //set this to 215 to actually show "THE END" in time to the last song beat
    gTasks[taskIdA].func = Task_CreditsTheEnd4;
}

static void Task_CreditsTheEnd4(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0])
    {
        gTasks[taskIdA].data[TDA_0] -= 1;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 6, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = Task_CreditsTheEnd5;
}

static void Task_CreditsTheEnd5(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        sub_8176E40(0x3800, 0);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0, RGB_BLACK);
        gTasks[taskIdA].data[TDA_0] = 7200;
        gTasks[taskIdA].func = Task_CreditsTheEnd6;
    }
}

static void Task_CreditsTheEnd6(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskIdA].data[TDA_0] == 0 || gMain.newKeys)
        {
            FadeOutBGM(4);
            BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_WHITEALPHA);
            gTasks[taskIdA].func = Task_CreditsSoftReset;
            return;
        }

        if (gTasks[taskIdA].data[TDA_0] == 7144)
            FadeOutBGM(8);

        if (gTasks[taskIdA].data[TDA_0] == 6840)
            m4aSongNumStart(MUS_END);

        gTasks[taskIdA].data[TDA_0] -= 1;
    }
}

static void Task_CreditsSoftReset(u8 taskIdA)
{
    if (!gPaletteFade.active)
        SoftReset(0xFF);
}

static void ResetGpuAndVram(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
}

static void sub_8175DA0(u8 taskIdB)
{
    int i;

    switch (gTasks[taskIdB].data[TDB_0])
    {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        if (!gPaletteFade.active)
        {
            gTasks[taskIdB].data[TDB_0] = 1;
            gTasks[taskIdB].data[TDB_3] = 0x48;
            gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
            gUnknown_0203BCE0 = 0;
        }
        return;
    case 1:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3] -= 1;
            return;
        }
        gTasks[taskIdB].data[TDB_0] += 1;
        return;
    case 2:
        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].func == Task_ProgressCreditTasks)
        {
            if (gTasks[taskIdB].data[TDB_CURRENT_PAGE] < PAGE_COUNT)
            {
                for (i = 0; i < 5; i++)
                    PrintCreditsText(
                        gCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->text,
                         5 + i * 16, 
                         gCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->isTitle);

                CopyWindowToVram(0, 2);

                gTasks[taskIdB].data[TDB_CURRENT_PAGE] += 1;
                gTasks[taskIdB].data[TDB_0] += 1;

                gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 1;

                if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
                    BeginNormalPaletteFade(0x00000300, 0, 16, 0, COLOR_LIGHT_GREEN);
                else
                    BeginNormalPaletteFade(0x00000300, 0, 16, 0, COLOR_DARK_GREEN);
                return;
            }
            gTasks[taskIdB].data[TDB_0] = 10;
            return;
        }
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
        return;
    case 3:
        if (!gPaletteFade.active)
        {
            gTasks[taskIdB].data[TDB_3] = 0x73;
            gTasks[taskIdB].data[TDB_0] += 1;
        }
        return;
    case 4:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3] -= 1;
            return;
        }

        if (CheckChangeScene((u8)gTasks[taskIdB].data[TDB_CURRENT_PAGE], (u8)gTasks[taskIdB].data[TDB_TASK_A_ID]))
        {
            gTasks[taskIdB].data[TDB_0] += 1;
            return;
        }
        gTasks[taskIdB].data[TDB_0] += 1;
        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
            BeginNormalPaletteFade(0x00000300, 0, 0, 16, COLOR_LIGHT_GREEN);
        else
            BeginNormalPaletteFade(0x00000300, 0, 0, 16, COLOR_DARK_GREEN);
        return;
    case 5:
        if (!gPaletteFade.active)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            CopyWindowToVram(0, 2);
            gTasks[taskIdB].data[TDB_0] = 2;
        }
        return;
    case 10:
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_4] = 1;
        DestroyTask(taskIdB);
        sub_81755A4();
        FREE_AND_SET_NULL(sCreditsData);
        return;
    }
}

static u8 CheckChangeScene(u8 page, u8 taskIdA)
{
    // Starts with bike + ocean + morning

    if (page == 6)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 12)
    {
        // Bike + ocean + sunset
        gTasks[taskIdA].data[TDA_7] = 1;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 18)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 24)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 2;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 30)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 36)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 3;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 42)
    {
        // Grass patch
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 48)
    {
        // Bike + town + night
        gTasks[taskIdA].data[TDA_7] = 4;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (gTasks[taskIdA].data[TDA_11] != 0)
    {
        // Returns true if changed?
        return TRUE;
    }

    return FALSE;
}

static void sub_81760FC(u8 taskIdD)
{
    u8 r2;

    switch (gTasks[taskIdD].data[TDD_STATE])
    {
    case 0:
        break;
    case 1:
        if (sCreditsData->nextImgPos == 0 && gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].data[TDA_14] == 0)
            break;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 2:
        if (sCreditsData->imgCounter == NUM_MON_SLIDES || gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].func != Task_ProgressCreditTasks)
            break;
        r2 = MakeMonSprite(sCreditsData->monToShow[sCreditsData->currShownMon], sMonSpritePos[sCreditsData->nextImgPos][0], sMonSpritePos[sCreditsData->nextImgPos][1], sCreditsData->nextImgPos);
        if (sCreditsData->currShownMon < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->currShownMon++;
            gSprites[r2].data[3] = 50;
        }
        else
        {
            sCreditsData->currShownMon = 0;
            gSprites[r2].data[3] = 512;
        }
        sCreditsData->imgCounter++;
        if (sCreditsData->nextImgPos == 2)
            sCreditsData->nextImgPos = 0;
        else
            sCreditsData->nextImgPos++;
        gTasks[taskIdD].data[TDD_3] = 50;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 3:
        if (gTasks[taskIdD].data[TDD_3] != 0)
            gTasks[taskIdD].data[TDD_3]--;
        else
            gTasks[taskIdD].data[TDD_STATE] = 1;
        break;
    }
}

static void sub_817624C(u8 taskIdC)
{
    switch (gTasks[taskIdC].data[TDC_0])
    {
    case 0:
        gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
        gTasks[taskIdC].data[TDC_5]++;
        break;
    case 1:
        if (gIntroCredits_MovingSceneryVOffset != 0)
        {
            gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
            gTasks[taskIdC].data[TDC_5]++;
        }
        else
        {
            gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 2;
            gTasks[taskIdC].data[TDC_5] = 0;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 2:
        if (gTasks[taskIdC].data[TDC_5] < 64)
        {
            gTasks[taskIdC].data[TDC_5]++;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
        }
        else
        {
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 3:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 3;
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 1;
        gTasks[taskIdC].data[TDC_4] = 120;
        gTasks[taskIdC].data[TDC_0]++;
        break;
    case 4:
        if (gTasks[taskIdC].data[TDC_4] != 0)
        {
            gTasks[taskIdC].data[TDC_4]--;
        }
        else
        {
            gTasks[taskIdC].data[TDC_5] = 64;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 5:
        if (gTasks[taskIdC].data[TDC_5] > 0)
        {
            gTasks[taskIdC].data[TDC_5]--;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
        }
        else
        {
            gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 1;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 6:
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 10:
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 2;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 20:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 4;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 30:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 5;
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 3;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 50:
        gTasks[taskIdC].data[TDC_0] = 0;
        break;
    }
}

static void sub_817651C(u8 taskIdE)
{
    s16 taskIdC;

    switch (gTasks[taskIdE].data[TDE_0])
    {
    default:
    case 0:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_B_ID]].data[TDB_CURRENT_PAGE] == 2)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 20;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }
        CycleSceneryPalette(0);
        break;
    case 1:
        CycleSceneryPalette(0);
        break;
    case 2:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {
            taskIdC = gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID];

            // Floor to multiple of 128
            if ((gTasks[taskIdC].data[TDC_5] & -128) == 640)
            {
                gTasks[taskIdC].data[TDC_0] = 1;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }
        CycleSceneryPalette(1);
        break;
    case 3:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[taskIdE].data[TDE_1] == 0x248)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 10;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
            else
            {
                gTasks[taskIdE].data[TDE_1] += 1;
            }
        }
        CycleSceneryPalette(1);
        break;
    case 4:
        CycleSceneryPalette(2);
        break;
    }
}

static void sub_817664C(u8 scene, u8 taskIdA)
{
    switch (scene)
    {
    case 0:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data[0] = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case 1:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data[0] = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case 2:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 272;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data[0] = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case 3:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 120;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = -32;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data[0] = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case 4:
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].invisible = FALSE;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.x = 88;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.x = 152;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].pos1.y = 46;
        gSprites[gTasks[taskIdA].data[TDA_PLAYER_CYCLIST]].data[0] = 0;
        gSprites[gTasks[taskIdA].data[TDA_RIVAL_CYCLIST]].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(2, 0x2000, 0x200, 8);
        break;
    }

    gTasks[taskIdA].data[TDA_TASK_E_ID] = CreateTask(sub_817651C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_0] = scene;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_1] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_TASK_A_ID] = taskIdA;

    gTasks[taskIdA].data[TDA_TASK_C_ID] = CreateTask(sub_817624C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_0] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_1] = taskIdA;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_2] = gTasks[taskIdA].data[TDA_PLAYER_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_3] = gTasks[taskIdA].data[TDA_RIVAL_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_4] = 0;

    if (scene == 2)
        gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_5] = 0x45;
}

static bool8 sub_8176AB0(u8 scene, u8 taskIdA)
{
    u8 spriteId;

    switch (gMain.state)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 8);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state = 1;
        break;
    case 1:
        gIntroCredits_MovingSceneryVBase = 34;
        gIntroCredits_MovingSceneryVOffset = 0;
        LoadCreditsSceneGraphics(scene);
        gMain.state += 1;
        break;
    case 2:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroBrendanSprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176EE8;
            gSprites[spriteId].anims = gUnknown_085E6FD0;

            spriteId = CreateIntroMaySprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176F90;
            gSprites[spriteId].anims = gUnknown_085E7010;
        }
        else
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroMaySprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176EE8;
            gSprites[spriteId].anims = gUnknown_085E6FD0;

            spriteId = CreateIntroBrendanSprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176F90;
            gSprites[spriteId].anims = gUnknown_085E7010;
        };
        gMain.state += 1;
        break;
    case 3:
        sub_817664C(scene, taskIdA);
        SetCreditsSceneBgCnt(scene);
        gMain.state = 0;
        return TRUE;
    }
    return FALSE;
}

static void ResetCreditsTasks(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_0]);
        gTasks[taskIdA].data[TDA_0] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_C_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_C_ID]);
        gTasks[taskIdA].data[TDA_TASK_C_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_E_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_E_ID]);
        gTasks[taskIdA].data[TDA_TASK_E_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_D_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_D_ID]);
        gTasks[taskIdA].data[TDA_TASK_D_ID] = 0;
    }

    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_DESTROY;
}

static void LoadTheEndScreen(u16 arg0, u16 arg1, u16 arg2)
{
    u16 baseTile;
    u16 i;

    LZ77UnCompVram(sCreditsCopyrightEnd_Gfx, (void *)(VRAM + arg0));
    LoadPalette(gIntroCopyright_Pal, arg2, sizeof(gIntroCopyright_Pal));

    baseTile = (arg2 / 16) << 12;

    for (i = 0; i < 32 * 32; i++)
        ((u16 *) (VRAM + arg1))[i] = baseTile + 1;
}

static u16 sub_8176D78(u8 baseTiles)
{
    u16 out = (baseTiles & 0x3F) + 80;

    if (baseTiles == 0xFF)
        return 1;

    if (baseTiles & (1 << 7))
        out |= 1 << 11;
    if (baseTiles & (1 << 6))
        out |= 1 << 10;

    return out;
}

static void sub_8176DBC(const u8 baseTiles[], u8 baseX, u8 baseY, u16 arg3, u16 palette)
{
    u8 y, x;
    const u16 tileOffset = (palette / 16) << 12;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 3; x++)
            ((u16 *) (VRAM + arg3 + (baseY + y) * 64))[baseX + x] = tileOffset + sub_8176D78(baseTiles[y * 3 + x]);
    }
}

static void sub_8176E40(u16 arg0, u16 palette)
{
    u16 pos;
    u16 baseTile = (palette / 16) << 12;

    for (pos = 0; pos < 32 * 32; pos++)
        ((u16 *) (VRAM + arg0))[pos] = baseTile + 1;

    sub_8176DBC(sTheEnd_LetterTMap, 3, 7, arg0, palette);
    sub_8176DBC(sTheEnd_LetterHMap, 7, 7, arg0, palette);
    sub_8176DBC(sTheEnd_LetterEMap, 11, 7, arg0, palette);
    sub_8176DBC(sTheEnd_LetterEMap, 16, 7, arg0, palette);
    sub_8176DBC(sTheEnd_LetterNMap, 20, 7, arg0, palette);
    sub_8176DBC(sTheEnd_LetterDMap, 24, 7, arg0, palette);
}

static void sub_8176EE8(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_MOVING)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        StartSpriteAnimIfDifferent(sprite, 1);
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 1;
        break;
    case 2:
        StartSpriteAnimIfDifferent(sprite, 2);
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 3);
        break;
    case 4:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > 120)
            sprite->pos1.x -= 1;
        break;
    case 5:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 1;
        break;
    }
}

static void sub_8176F90(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_MOVING)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.y = 0;
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        if (sprite->pos1.x > 200)
            StartSpriteAnimIfDifferent(sprite, 1);
        else
            StartSpriteAnimIfDifferent(sprite, 2);
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 2;
        sprite->pos2.y = -gIntroCredits_MovingSceneryVOffset;
        break;
    case 2:
        sprite->data[7] += 1;
        StartSpriteAnimIfDifferent(sprite, 0);
        if ((sprite->data[7] & 3) == 0)
            sprite->pos1.x += 1;
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 1;
        break;
    }
}

static void sub_8177050(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_MOVING)
    {
        FreeAndDestroyMonPicSprite(sprite->data[6]);
        return;
    }

    sprite->data[7] += 1;
    switch (sprite->data[0])
    {
    case 0:
    default:
        sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        sprite->oam.matrixNum = sprite->data[1];
        sprite->data[2] = 16;
        SetOamMatrix(sprite->data[1], 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        sprite->invisible = FALSE;
        sprite->data[0] = 1;
        break;
    case 1:
        if (sprite->data[2] < 256)
        {
            sprite->data[2] += 8;
            SetOamMatrix(sprite->data[1], 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        }
        else
        {
            sprite->data[0] += 1;
        }
        switch (sprite->data[1])
        {
        case 1:
            if ((sprite->data[7] & 3) == 0)
                sprite->pos1.y += 1;
            sprite->pos1.x -= 2;
            break;
        case 2:
            break;
        case 3:
            if ((sprite->data[7] & 3) == 0)
                sprite->pos1.y += 1;
            sprite->pos1.x += 2;
            break;
        }
        break;
    case 2:
        if (sprite->data[3] != 0)
        {
            sprite->data[3] -= 1;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            sprite->oam.objMode = ST_OAM_OBJ_BLEND;
            sprite->data[3] = 16;
            sprite->data[0] += 1;
        }
        break;
    case 3:
        if (sprite->data[3] != 0)
        {
            int data3;

            sprite->data[3] -= 1;

            data3 = 16 - sprite->data[3];
            SetGpuReg(REG_OFFSET_BLDALPHA, (data3 << 8) + sprite->data[3]);
        }
        else
        {
            sprite->invisible = TRUE;
            sprite->data[0] = 9;
        }
        break;
    case 9:
        sprite->data[0] += 1;
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        FreeAndDestroyMonPicSprite(sprite->data[6]);
        break;
    }
}

static u8 MakeMonSprite(u16 nationalDexNum, s16 x, s16 y, u16 position)
{
    u8 spriteId;
    u8 spriteId2;

    spriteId = CreateMonSpriteFromNationalDexNumber(nationalDexNum, x, y, position);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].data[1] = position + 1;
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].callback = sub_8177050;
    gSprites[spriteId].data[6] = spriteId;

    spriteId2 = CreateSprite(&gUnknown_085E7068, gSprites[spriteId].pos1.x, gSprites[spriteId].pos1.y, 1);
    gSprites[spriteId2].data[0] = spriteId;

    StartSpriteAnimIfDifferent(&gSprites[spriteId2], position);

    return spriteId;
}

static void sub_81772B8(struct Sprite *sprite)
{
    if (gSprites[sprite->data[0]].data[0] == 10 || gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_MOVING)
    {
        DestroySprite(sprite);
        return;
    }

    sprite->invisible = gSprites[sprite->data[0]].invisible;
    sprite->oam.objMode = gSprites[sprite->data[0]].oam.objMode;
    sprite->oam.affineMode = gSprites[sprite->data[0]].oam.affineMode;
    sprite->oam.matrixNum = gSprites[sprite->data[0]].oam.matrixNum;
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
}

static void DeterminePokemonToShow(void)
{
    u16 starter = SpeciesToNationalPokedexNum(GetStarterPokemon(VarGet(VAR_STARTER_MON)));
    u16 page;
    u16 dexNum;
    u16 j;
    
    // Go through the Pokedex, and anything that has gotten caught we put into our massive array.
    // This basically packs all of the caught pokemon into the front of the array
    for (dexNum = 1, j = 0; dexNum < NATIONAL_DEX_COUNT; dexNum++)
    {
        if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
        {
            sCreditsData->caughtMonIds[j] = dexNum;
            j++;
        }
    }

    // Fill the rest of the array with zeroes
    for (dexNum = j; dexNum < NATIONAL_DEX_COUNT; dexNum++)
        sCreditsData->caughtMonIds[dexNum] = NATIONAL_DEX_NONE;

    // Cap the number of pokemon we care about to NUM_MON_SLIDES, the max we show in the credits scene (-1 for the starter)
    sCreditsData->numCaughtMon = j;
    if (sCreditsData->numCaughtMon < NUM_MON_SLIDES)
        sCreditsData->numMonToShow = j;
    else
        sCreditsData->numMonToShow = NUM_MON_SLIDES;

    // Loop through our list of caught pokemon and select randomly from it to fill the images to show
    j = 0;
    do
    {
        // Select a random mon, insert into array
        page = Random() % sCreditsData->numCaughtMon;
        sCreditsData->monToShow[j] = sCreditsData->caughtMonIds[page];
        
        // Remove the select mon from the array, and condense array entries
        j++;
        sCreditsData->caughtMonIds[page] = 0;
        sCreditsData->numCaughtMon--;
        if (page != sCreditsData->numCaughtMon)
        {
            // Instead of looping through and moving everything down, just take from the end. Order doesn't matter after all.
            sCreditsData->caughtMonIds[page] = sCreditsData->caughtMonIds[sCreditsData->numCaughtMon];
            sCreditsData->caughtMonIds[sCreditsData->numCaughtMon] = 0;
        }
    }
    while (sCreditsData->numCaughtMon != 0 && j < NUM_MON_SLIDES);

    // If we don't have enough pokemon in the dex to fill everything, copy the selected mon into the end of the array, so it loops
    if (sCreditsData->numMonToShow < NUM_MON_SLIDES)
    {
        for (j = sCreditsData->numMonToShow, page = 0; j < NUM_MON_SLIDES; j++)
        {
            sCreditsData->monToShow[j] = sCreditsData->monToShow[page];

            page++;
            if (page == sCreditsData->numMonToShow)
                page = 0;
        }
        // Ensure the last pokemon is our starter
        sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
    }
    else
    {
        // Check to see if our starter has already appeared in this list, break if it has
        for (dexNum = 0; sCreditsData->monToShow[dexNum] != starter && dexNum < NUM_MON_SLIDES; dexNum++);

        // If it has, swap it with the last pokemon, to ensure our starter is the last image
        if (dexNum < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->monToShow[dexNum] = sCreditsData->monToShow[NUM_MON_SLIDES-1];
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
        else
        {
            // Ensure the last pokemon is our starter
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
    }
    sCreditsData->numMonToShow = NUM_MON_SLIDES;
}
