#include "global.h"
#include "palette.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "alloc.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/songs.h"
#include "constants/species.h"
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
#include "constants/vars.h"
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

struct Unk201C000
{
    u16 unk0[71];
    u16 unk8E;
    u16 unk90;
    u16 unk92;
    u16 unk94;
    u16 unk96[NATIONAL_DEX_COUNT];
    u16 unk39A;
    u16 unk39C[7];
};

struct CreditsEntry
{
    u8 var_0;
    u8 var_1;
    const u8 *text;
};

static EWRAM_DATA s16 gUnknown_0203BCE0 = 0;
static EWRAM_DATA u16 gUnknown_0203BCE2 = 0; // TASK A
EWRAM_DATA bool8 gHasHallOfFameRecords = 0;
static EWRAM_DATA u8 gUnknown_0203BCE5 = 0;
static EWRAM_DATA struct Unk201C000 *gUnknown_0203BCE8 = {0};

static const u16 gUnknown_085E56F0[][16] =
{
    INCBIN_U16("graphics/credits/credits_1.gbapal"),
    INCBIN_U16("graphics/credits/credits_2.gbapal"),
    INCBIN_U16("graphics/credits/credits_3.gbapal"),
    INCBIN_U16("graphics/credits/credits_4.gbapal"),
};

static const u32 gCreditsCopyrightEnd_Gfx[] = INCBIN_U32("graphics/credits/the_end_copyright.4bpp.lz");

static void sub_81772B8(struct Sprite *sprite);

static const u8 gUnknown_085E5BAC[] =
{
    0,    1, 0,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
};

static const u8 gUnknown_085E5BBB[] =
{
    1, 0xFF, 1,
    1, 0xFF, 1,
    1, 2,    1,
    1, 0xFF, 1,
    1, 0xFF, 1,
};

static const u8 gUnknown_085E5BCA[] =
{
    1, 0, 0,
    1, 0xFF, 0xFF,
    1, 2,    2,
    1, 0xFF, 0xFF,
    1, 0x80, 0x80,
};

static const u8 gUnknown_085E5BD9[] =
{
    1, 3, 1,
    1, 4, 1,
    1, 5, 1,
    1, 0xC4, 1,
    1, 0xC3, 1,
};

static const u8 gUnknown_085E5BE8[] =
{
    1, 6, 7,
    1, 8, 9,
    1, 0xFF, 1,
    1, 0x88, 0x89,
    1, 0x86, 0x87,
};

static const u8 gCreditsText_EmptyString[] = _("");
static const u8 gCreditsText_PkmnEmeraldVersion[] = _("POKéMON EMERALD VERSION");
static const u8 gCreditsText_Credits[] = _("Credits");
static const u8 gCreditsText_ExecutiveDirector[] = _("Executive Director");
static const u8 gCreditsText_Director[] = _("Director");
static const u8 gCreditsText_ArtDirector[] = _("Art Director");
static const u8 gCreditsText_BattleDirector[] = _("Battle Director");
static const u8 gCreditsText_MainProgrammer[] = _("Main Programmer");
static const u8 gCreditsText_BattleSystemPgrms[] = _("Battle System Programmers");
static const u8 gCreditsText_FieldSystemPgrms[] = _("Field System Programmer");
static const u8 gCreditsText_Programmers[] = _("Programmers");
static const u8 gCreditsText_MainGraphicDesigner[] = _("Main Graphic Designer");
static const u8 gCreditsText_GraphicDesigners[] = _("Graphic Designers");
static const u8 gCreditsText_PkmnDesigners[] = _("POKéMON Designers");
static const u8 gCreditsText_MusicComposition[] = _("Music Composition");
static const u8 gCreditsText_SoundEffectsAndPkmnVoices[] = _("Sound Effects & POKéMON Voices");
static const u8 gCreditsText_GameDesigners[] = _("Game Designers");
static const u8 gCreditsText_ScenarioPlot[] = _("Scenario Plot");
static const u8 gCreditsText_Scenario[] = _("Scenario");
static const u8 gCreditsText_ScriptDesigners[] = _("Script Designers");
static const u8 gCreditsText_MapDesigners[] = _("Map Designers");
static const u8 gCreditsText_MapDataDesigners[] = _("Map Data Designers");
static const u8 gCreditsText_ParametricDesigners[] = _("Parametric Designers");
static const u8 gCreditsText_PokedexText[] = _("POKéDEX Text");
static const u8 gCreditsText_EnvAndToolPgrms[] = _("Environment & Tool Programmers");
static const u8 gCreditsText_NCLProductTesting[] = _("NCL Product Testing");
static const u8 gCreditsText_SpecialThanks[] = _("Special Thanks");
static const u8 gCreditsText_Coordinators[] = _("Coordinators");
static const u8 gCreditsText_Producers[] = _("Producers");
static const u8 gCreditsText_ExecProducers[] = _("Executive Producers");
static const u8 gCreditsText_InfoSupervisors[] = _("Information Supervisors");
static const u8 gCreditsText_TaskManagers[] = _("Task Managers");
static const u8 gCreditsText_BrailleCodeCheck[] = _("Braille Code Check");
static const u8 gCreditsText_WorldDirector[] = _("World Director");
static const u8 gCreditsText_BattleFrontierData[] = _("Battle Frontier Data");
static const u8 gCreditsText_SupportProgrammers[] = _("Support Programmers");
static const u8 gCreditsText_Artwork[] = _("Artwork");
static const u8 gCreditsText_LeadProgrammer[] = _("Lead Programmer");
static const u8 gCreditsText_LeadGraphicArtist[] = _("Lead Graphic Artist");
static const u8 gCreditsText_SatoshiTajiri[] = _("Satoshi Tajiri");
static const u8 gCreditsText_JunichiMasuda[] = _("Junichi Masuda");
static const u8 gCreditsText_KenSugimori[] = _("Ken Sugimori");
static const u8 gCreditsText_ShigekiMorimoto[] = _("Shigeki Morimoto");
static const u8 gCreditsText_TetsuyaWatanabe[] = _("Tetsuya Watanabe");
static const u8 gCreditsText_HisashiSogabe[] = _("Hisashi Sogabe");
static const u8 gCreditsText_SosukeTamada[] = _("Sosuke Tamada");
static const u8 gCreditsText_AkitoMori[] = _("Akito Mori");
static const u8 gCreditsText_KeitaKagaya[] = _("Keita Kagaya");
static const u8 gCreditsText_YoshinoriMatsuda[] = _("Yoshinori Matsuda");
static const u8 gCreditsText_HiroyukiNakamura[] = _("Hiroyuki Nakamura");
static const u8 gCreditsText_MasaoTaya[] = _("Masao Taya");
static const u8 gCreditsText_SatoshiNohara[] = _("Satoshi Nohara");
static const u8 gCreditsText_TomomichiOhta[] = _("Tomomichi Ohta");
static const u8 gCreditsText_MiyukiIwasawa[] = _("Miyuki Iwasawa");
static const u8 gCreditsText_TakenoriOhta[] = _("Takenori Ohta");
static const u8 gCreditsText_HironobuYoshida[] = _("Hironobu Yoshida");
static const u8 gCreditsText_MotofumiFujiwara[] = _("Motofumi Fujiwara");
static const u8 gCreditsText_SatoshiOhta[] = _("Satoshi Ohta");
static const u8 gCreditsText_AsukaIwashita[] = _("Asuka Iwashita");
static const u8 gCreditsText_AimiTomita[] = _("Aimi Tomita");
static const u8 gCreditsText_TakaoUnno[] = _("Takao Unno");
static const u8 gCreditsText_KanakoEo[] = _("Kanako Eo");
static const u8 gCreditsText_JunOkutani[] = _("Jun Okutani");
static const u8 gCreditsText_AtsukoNishida[] = _("Atsuko Nishida");
static const u8 gCreditsText_MuneoSaito[] = _("Muneo Saito");
static const u8 gCreditsText_RenaYoshikawa[] = _("Rena Yoshikawa");
static const u8 gCreditsText_GoIchinose[] = _("Go Ichinose");
static const u8 gCreditsText_MorikazuAoki[] = _("Morikazu Aoki");
static const u8 gCreditsText_KojiNishino[] = _("Koji Nishino");
static const u8 gCreditsText_KenjiMatsushima[] = _("Kenji Matsushima");
static const u8 gCreditsText_TetsujiOhta[] = _("Tetsuji Ohta");
static const u8 gCreditsText_HitomiSato[] = _("Hitomi Sato");
static const u8 gCreditsText_TakeshiKawachimaru[] = _("Takeshi Kawachimaru");
static const u8 gCreditsText_TeruyukiShimoyamada[] = _("Teruyuki Shimoyamada");
static const u8 gCreditsText_ShigeruOhmori[] = _("Shigeru Ohmori");
static const u8 gCreditsText_TadashiTakahashi[] = _("Tadashi Takahashi");
static const u8 gCreditsText_ToshinobuMatsumiya[] = _("Toshinobu Matsumiya");
static const u8 gCreditsText_AkihitoTomisawa[] = _("Akihito Tomisawa");
static const u8 gCreditsText_HirokiEnomoto[] = _("Hiroki Enomoto");
static const u8 gCreditsText_KazuyukiTerada[] = _("Kazuyuki Terada");
static const u8 gCreditsText_YuriSakurai[] = _("Yuri Sakurai");
static const u8 gCreditsText_HiromiSagawa[] = _("Hiromi Sagawa");
static const u8 gCreditsText_KenjiTominaga[] = _("Kenji Tominaga");
static const u8 gCreditsText_YoshioTajiri[] = _("Yoshio Tajiri");
static const u8 gCreditsText_TeikoSasaki[] = _("Teiko Sasaki");
static const u8 gCreditsText_SachikoHamano[] = _("Sachiko Hamano");
static const u8 gCreditsText_ChieMatsumiya[] = _("Chie Matsumiya");
static const u8 gCreditsText_AkikoShinozaki[] = _("Akiko Shinozaki");
static const u8 gCreditsText_AstukoFujii[] = _("Astuko Fujii");
static const u8 gCreditsText_NozomuSaito[] = _("Nozomu Saito");
static const u8 gCreditsText_KenkichiToyama[] = _("Kenkichi Toyama");
static const u8 gCreditsText_SuguruNakatsui[] = _("Suguru Nakatsui");
static const u8 gCreditsText_YumiFunasaka[] = _("Yumi Funasaka");
static const u8 gCreditsText_NaokoYanase[] = _("Naoko Yanase");
static const u8 gCreditsText_NCLSuperMarioClub[] = _("NCL Super Mario Club");
static const u8 gCreditsText_AtsushiTada[] = _("Atsushi Tada");
static const u8 gCreditsText_TakahiroOhnishi[] = _("Takahiro Ohnishi");
static const u8 gCreditsText_NorihideOkamura[] = _("Norihide Okamura");
static const u8 gCreditsText_HiroNakamura[] = _("Hiro Nakamura");
static const u8 gCreditsText_HiroyukiUesugi[] = _("Hiroyuki Uesugi");
static const u8 gCreditsText_TerukiMurakawa[] = _("Teruki Murakawa");
static const u8 gCreditsText_AkiraKinashi[] = _("Akira Kinashi");
static const u8 gCreditsText_MichikoTakizawa[] = _("Michiko Takizawa");
static const u8 gCreditsText_MakikoTakada[] = _("Makiko Takada");
static const u8 gCreditsText_TakanaoKondo[] = _("Takanao Kondo");
static const u8 gCreditsText_AiMashima[] = _("Ai Mashima");
static const u8 gCreditsText_GakujiNomoto[] = _("Gakuji Nomoto");
static const u8 gCreditsText_TakehiroIzushi[] = _("Takehiro Izushi");
static const u8 gCreditsText_HitoshiYamagami[] = _("Hitoshi Yamagami");
static const u8 gCreditsText_KyokoWatanabe[] = _("Kyoko Watanabe");
static const u8 gCreditsText_TakaoNakano[] = _("Takao Nakano");
static const u8 gCreditsText_HiroyukiJinnai[] = _("Hiroyuki Jinnai");
static const u8 gCreditsText_HiroakiTsuru[] = _("Hiroaki Tsuru");
static const u8 gCreditsText_TsunekazIshihara[] = _("Tsunekaz Ishihara");
static const u8 gCreditsText_SatoruIwata[] = _("Satoru Iwata");
static const u8 gCreditsText_KazuyaSuyama[] = _("Kazuya Suyama");
static const u8 gCreditsText_SatoshiMitsuhara[] = _("Satoshi Mitsuhara");
static const u8 gCreditsText_JapanBrailleLibrary[] = _("Japan Braille Library");
static const u8 gCreditsText_TomotakaKomura[] = _("Tomotaka Komura");
static const u8 gCreditsText_MikikoOhhashi[] = _("Mikiko Ohhashi");
static const u8 gCreditsText_DaisukeHoshino[] = _("Daisuke Hoshino");
static const u8 gCreditsText_KenjiroIto[] = _("Kenjiro Ito");
static const u8 gCreditsText_RuiKawaguchi[] = _("Rui Kawaguchi");
static const u8 gCreditsText_ShunsukeKohori[] = _("Shunsuke Kohori");
static const u8 gCreditsText_SachikoNakamichi[] = _("Sachiko Nakamichi");
static const u8 gCreditsText_FujikoNomura[] = _("Fujiko Nomura");
static const u8 gCreditsText_KazukiYoshihara[] = _("Kazuki Yoshihara");
static const u8 gCreditsText_RetsujiNomoto[] = _("Retsuji Nomoto");
static const u8 gCreditsText_AzusaTajima[] = _("Azusa Tajima");
static const u8 gCreditsText_ShusakuEgami[] = _("Shusaku Egami");
static const u8 gCreditsText_PackageAndManual[] = _("Package & Manual Illustration");
static const u8 gCreditsText_EnglishVersion[] = _("English Version Coordinators");
static const u8 gCreditsText_Translator[] = _("Translator");
static const u8 gCreditsText_TextEditor[] = _("Text Editor");
static const u8 gCreditsText_NCLCoordinator[] = _("NCL Coordinator");
static const u8 gCreditsText_GraphicDesigner[] = _("Graphic Designer");
static const u8 gCreditsText_NOAProductTesting[] = _("NOA Product Testing");
static const u8 gCreditsText_HideyukiNakajima[] = _("Hideyuki Nakajima");
static const u8 gCreditsText_HidenoriSaeki[] = _("Hidenori Saeki");
static const u8 gCreditsText_YokoWatanabe[] = _("Yoko Watanabe");
static const u8 gCreditsText_SakaeKimura[] = _("Sakae Kimura");
static const u8 gCreditsText_ChiakiShinkai[] = _("Chiaki Shinkai");
static const u8 gCreditsText_SethMcMahill[] = _("Seth McMahill");
static const u8 gCreditsText_NobOgasawara[] = _("Nob Ogasawara");
static const u8 gCreditsText_TeresaLillygren[] = _("Teresa Lillygren");
static const u8 gCreditsText_KimikoNakamichi[] = _("Kimiko Nakamichi");
static const u8 gCreditsText_SouichiYamamoto[] = _("Souichi Yamamoto");
static const u8 gCreditsText_YuichiroIto[] = _("Yuichiro Ito");
static const u8 gCreditsText_ThomasHertzog[] = _("Thomas Hertzog");
static const u8 gCreditsText_MikaKurosawa[] = _("Mika Kurosawa");
static const u8 gCreditsText_NationalFederationBlind[] = _("National Federation of the Blind");
static const u8 gCreditsText_PatriciaAMaurer[] = _("Patricia A. Maurer");
static const u8 gCreditsText_EuropeanBlindUnion[] = _("European Blind Union");
static const u8 gCreditsText_AustralianBrailleAuthority[] = _("Australian Braille Authority");
static const u8 gCreditsText_RoyalNewZealandFederationBlind[] = _("Royal New Zealand Federation for the Blind");
static const u8 gCreditsText_MotoyasuTojima[] = _("Motoyasu Tojima");
static const u8 gCreditsText_NicolaPrattBarlow[] = _("Nicola Pratt-Barlow");
static const u8 gCreditsText_ShellieDow[] = _("Shellie Dow");
static const u8 gCreditsText_ErikJohnson[] = _("Erik Johnson");
static const struct CreditsEntry gCreditsEntry_EmptyString[] = {0, 0, gCreditsText_EmptyString};
static const struct CreditsEntry gCreditsEntry_PkmnEmeraldVersion[] = {7, 1, gCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry gCreditsEntry_Credits[] = {11, 1, gCreditsText_Credits};
static const struct CreditsEntry gCreditsEntry_ExecutiveDirector[] = {8, 1, gCreditsText_ExecutiveDirector};
static const struct CreditsEntry gCreditsEntry_Director[] = {12, 1, gCreditsText_Director};
static const struct CreditsEntry gCreditsEntry_ArtDirector[] = {10, 1, gCreditsText_ArtDirector};
static const struct CreditsEntry gCreditsEntry_BattleDirector[] = {10, 1, gCreditsText_BattleDirector};
static const struct CreditsEntry gCreditsEntry_MainProgrammer[] = {10, 1, gCreditsText_MainProgrammer};
static const struct CreditsEntry gCreditsEntry_BattleSystemPgrms[] = {8, 1, gCreditsText_BattleSystemPgrms};
static const struct CreditsEntry gCreditsEntry_FieldSystemPgrms[] = {7, 1, gCreditsText_FieldSystemPgrms};
static const struct CreditsEntry gCreditsEntry_Programmers[] = {12, 1, gCreditsText_Programmers};
static const struct CreditsEntry gCreditsEntry_MainGraphicDesigner[] = {7, 1, gCreditsText_MainGraphicDesigner};
static const struct CreditsEntry gCreditsEntry_GraphicDesigners[] = {9, 1, gCreditsText_GraphicDesigners};
static const struct CreditsEntry gCreditsEntry_PkmnDesigners[] = {10, 1, gCreditsText_PkmnDesigners};
static const struct CreditsEntry gCreditsEntry_MusicComposition[] = {13, 1, gCreditsText_MusicComposition};
static const struct CreditsEntry gCreditsEntry_SoundEffectsAndPkmnVoices[] = {4, 1, gCreditsText_SoundEffectsAndPkmnVoices};
static const struct CreditsEntry gCreditsEntry_GameDesigners[] = {11, 1, gCreditsText_GameDesigners};
static const struct CreditsEntry gCreditsEntry_ScenarioPlot[] = {11, 1, gCreditsText_ScenarioPlot};
static const struct CreditsEntry gCreditsEntry_Scenario[] = {13, 1, gCreditsText_Scenario};
static const struct CreditsEntry gCreditsEntry_ScriptDesigners[] = {10, 1, gCreditsText_ScriptDesigners};
static const struct CreditsEntry gCreditsEntry_MapDesigners[] = {11, 1, gCreditsText_MapDesigners};
static const struct CreditsEntry gCreditsEntry_MapDataDesigners[] = {9, 1, gCreditsText_MapDataDesigners};
static const struct CreditsEntry gCreditsEntry_ParametricDesigners[] = {9, 1, gCreditsText_ParametricDesigners};
static const struct CreditsEntry gCreditsEntry_PokedexText[] = {11, 1, gCreditsText_PokedexText};
static const struct CreditsEntry gCreditsEntry_EnvAndToolPgrms[] = {6, 1, gCreditsText_EnvAndToolPgrms};
static const struct CreditsEntry gCreditsEntry_NCLProductTesting[] = {11, 1, gCreditsText_NCLProductTesting};
static const struct CreditsEntry gCreditsEntry_SpecialThanks[] = {10, 1, gCreditsText_SpecialThanks};
static const struct CreditsEntry gCreditsEntry_Coordinators[] = {11, 1, gCreditsText_Coordinators};
static const struct CreditsEntry gCreditsEntry_Producers[] = {11, 1, gCreditsText_Producers};
static const struct CreditsEntry gCreditsEntry_ExecProducers[] = {7, 1, gCreditsText_ExecProducers};
static const struct CreditsEntry gCreditsEntry_InfoSupervisors[] = {10, 1, gCreditsText_InfoSupervisors};
static const struct CreditsEntry gCreditsEntry_TaskManagers[] = {8, 1, gCreditsText_TaskManagers};
static const struct CreditsEntry gCreditsEntry_BrailleCodeCheck[] = {10, 1, gCreditsText_BrailleCodeCheck};
static const struct CreditsEntry gCreditsEntry_WorldDirector[] = {10, 1, gCreditsText_WorldDirector};
static const struct CreditsEntry gCreditsEntry_BattleFrontierData[] = {8, 1, gCreditsText_BattleFrontierData};
static const struct CreditsEntry gCreditsEntry_SupportProgrammers[] = {10, 1, gCreditsText_SupportProgrammers};
static const struct CreditsEntry gCreditsEntry_Artwork[] = {12, 1, gCreditsText_Artwork};
static const struct CreditsEntry gCreditsEntry_LeadProgrammer[] = {10, 1, gCreditsText_LeadProgrammer};
static const struct CreditsEntry gCreditsEntry_LeadGraphicArtist[] = {9, 1, gCreditsText_LeadGraphicArtist};
static const struct CreditsEntry gCreditsEntry_SatoshiTajiri[] = {11, 0, gCreditsText_SatoshiTajiri};
static const struct CreditsEntry gCreditsEntry_JunichiMasuda[] = {11, 0, gCreditsText_JunichiMasuda};
static const struct CreditsEntry gCreditsEntry_KenSugimori[] = {11, 0, gCreditsText_KenSugimori};
static const struct CreditsEntry gCreditsEntry_ShigekiMorimoto[] = {11, 0, gCreditsText_ShigekiMorimoto};
static const struct CreditsEntry gCreditsEntry_TetsuyaWatanabe[] = {11, 0, gCreditsText_TetsuyaWatanabe};
static const struct CreditsEntry gCreditsEntry_HisashiSogabe[] = {11, 0, gCreditsText_HisashiSogabe};
static const struct CreditsEntry gCreditsEntry_SosukeTamada[] = {11, 0, gCreditsText_SosukeTamada};
static const struct CreditsEntry gCreditsEntry_AkitoMori[] = {11, 0, gCreditsText_AkitoMori};
static const struct CreditsEntry gCreditsEntry_KeitaKagaya[] = {11, 0, gCreditsText_KeitaKagaya};
static const struct CreditsEntry gCreditsEntry_YoshinoriMatsuda[] = {11, 0, gCreditsText_YoshinoriMatsuda};
static const struct CreditsEntry gCreditsEntry_HiroyukiNakamura[] = {11, 0, gCreditsText_HiroyukiNakamura};
static const struct CreditsEntry gCreditsEntry_MasaoTaya[] = {11, 0, gCreditsText_MasaoTaya};
static const struct CreditsEntry gCreditsEntry_SatoshiNohara[] = {11, 0, gCreditsText_SatoshiNohara};
static const struct CreditsEntry gCreditsEntry_TomomichiOhta[] = {11, 0, gCreditsText_TomomichiOhta};
static const struct CreditsEntry gCreditsEntry_MiyukiIwasawa[] = {11, 0, gCreditsText_MiyukiIwasawa};
static const struct CreditsEntry gCreditsEntry_TakenoriOhta[] = {11, 0, gCreditsText_TakenoriOhta};
static const struct CreditsEntry gCreditsEntry_HironobuYoshida[] = {11, 0, gCreditsText_HironobuYoshida};
static const struct CreditsEntry gCreditsEntry_MotofumiFujiwara[] = {11, 0, gCreditsText_MotofumiFujiwara};
static const struct CreditsEntry gCreditsEntry_SatoshiOhta[] = {11, 0, gCreditsText_SatoshiOhta};
static const struct CreditsEntry gCreditsEntry_AsukaIwashita[] = {11, 0, gCreditsText_AsukaIwashita};
static const struct CreditsEntry gCreditsEntry_AimiTomita[] = {11, 0, gCreditsText_AimiTomita};
static const struct CreditsEntry gCreditsEntry_TakaoUnno[] = {11, 0, gCreditsText_TakaoUnno};
static const struct CreditsEntry gCreditsEntry_KanakoEo[] = {11, 0, gCreditsText_KanakoEo};
static const struct CreditsEntry gCreditsEntry_JunOkutani[] = {11, 0, gCreditsText_JunOkutani};
static const struct CreditsEntry gCreditsEntry_AtsukoNishida[] = {11, 0, gCreditsText_AtsukoNishida};
static const struct CreditsEntry gCreditsEntry_MuneoSaito[] = {11, 0, gCreditsText_MuneoSaito};
static const struct CreditsEntry gCreditsEntry_RenaYoshikawa[] = {11, 0, gCreditsText_RenaYoshikawa};
static const struct CreditsEntry gCreditsEntry_GoIchinose[] = {11, 0, gCreditsText_GoIchinose};
static const struct CreditsEntry gCreditsEntry_MorikazuAoki[] = {11, 0, gCreditsText_MorikazuAoki};
static const struct CreditsEntry gCreditsEntry_KojiNishino[] = {11, 0, gCreditsText_KojiNishino};
static const struct CreditsEntry gCreditsEntry_KenjiMatsushima[] = {11, 0, gCreditsText_KenjiMatsushima};
static const struct CreditsEntry gCreditsEntry_TetsujiOhta[] = {11, 0, gCreditsText_TetsujiOhta};
static const struct CreditsEntry gCreditsEntry_HitomiSato[] = {11, 0, gCreditsText_HitomiSato};
static const struct CreditsEntry gCreditsEntry_TakeshiKawachimaru[] = {11, 0, gCreditsText_TakeshiKawachimaru};
static const struct CreditsEntry gCreditsEntry_TeruyukiShimoyamada[] = {11, 0, gCreditsText_TeruyukiShimoyamada};
static const struct CreditsEntry gCreditsEntry_ShigeruOhmori[] = {11, 0, gCreditsText_ShigeruOhmori};
static const struct CreditsEntry gCreditsEntry_TadashiTakahashi[] = {11, 0, gCreditsText_TadashiTakahashi};
static const struct CreditsEntry gCreditsEntry_ToshinobuMatsumiya[] = {11, 0, gCreditsText_ToshinobuMatsumiya};
static const struct CreditsEntry gCreditsEntry_AkihitoTomisawa[] = {11, 0, gCreditsText_AkihitoTomisawa};
static const struct CreditsEntry gCreditsEntry_HirokiEnomoto[] = {11, 0, gCreditsText_HirokiEnomoto};
static const struct CreditsEntry gCreditsEntry_KazuyukiTerada[] = {11, 0, gCreditsText_KazuyukiTerada};
static const struct CreditsEntry gCreditsEntry_YuriSakurai[] = {11, 0, gCreditsText_YuriSakurai};
static const struct CreditsEntry gCreditsEntry_HiromiSagawa[] = {11, 0, gCreditsText_HiromiSagawa};
static const struct CreditsEntry gCreditsEntry_KenjiTominaga[] = {11, 0, gCreditsText_KenjiTominaga};
static const struct CreditsEntry gCreditsEntry_YoshioTajiri[] = {11, 0, gCreditsText_YoshioTajiri};
static const struct CreditsEntry gCreditsEntry_TeikoSasaki[] = {11, 0, gCreditsText_TeikoSasaki};
static const struct CreditsEntry gCreditsEntry_SachikoHamano[] = {11, 0, gCreditsText_SachikoHamano};
static const struct CreditsEntry gCreditsEntry_ChieMatsumiya[] = {11, 0, gCreditsText_ChieMatsumiya};
static const struct CreditsEntry gCreditsEntry_AkikoShinozaki[] = {11, 0, gCreditsText_AkikoShinozaki};
static const struct CreditsEntry gCreditsEntry_AstukoFujii[] = {11, 0, gCreditsText_AstukoFujii};
static const struct CreditsEntry gCreditsEntry_NozomuSaito[] = {11, 0, gCreditsText_NozomuSaito};
static const struct CreditsEntry gCreditsEntry_KenkichiToyama[] = {11, 0, gCreditsText_KenkichiToyama};
static const struct CreditsEntry gCreditsEntry_SuguruNakatsui[] = {11, 0, gCreditsText_SuguruNakatsui};
static const struct CreditsEntry gCreditsEntry_YumiFunasaka[] = {11, 0, gCreditsText_YumiFunasaka};
static const struct CreditsEntry gCreditsEntry_NaokoYanase[] = {11, 0, gCreditsText_NaokoYanase};
static const struct CreditsEntry gCreditsEntry_NCLSuperMarioClub[] = {11, 0, gCreditsText_NCLSuperMarioClub};
static const struct CreditsEntry gCreditsEntry_AtsushiTada[] = {11, 0, gCreditsText_AtsushiTada};
static const struct CreditsEntry gCreditsEntry_TakahiroOhnishi[] = {11, 0, gCreditsText_TakahiroOhnishi};
static const struct CreditsEntry gCreditsEntry_NorihideOkamura[] = {11, 0, gCreditsText_NorihideOkamura};
static const struct CreditsEntry gCreditsEntry_HiroNakamura[] = {11, 0, gCreditsText_HiroNakamura};
static const struct CreditsEntry gCreditsEntry_HiroyukiUesugi[] = {11, 0, gCreditsText_HiroyukiUesugi};
static const struct CreditsEntry gCreditsEntry_TerukiMurakawa[] = {11, 0, gCreditsText_TerukiMurakawa};
static const struct CreditsEntry gCreditsEntry_AkiraKinashi[] = {11, 0, gCreditsText_AkiraKinashi};
static const struct CreditsEntry gCreditsEntry_MichikoTakizawa[] = {11, 0, gCreditsText_MichikoTakizawa};
static const struct CreditsEntry gCreditsEntry_MakikoTakada[] = {11, 0, gCreditsText_MakikoTakada};
static const struct CreditsEntry gCreditsEntry_TakanaoKondo[] = {11, 0, gCreditsText_TakanaoKondo};
static const struct CreditsEntry gCreditsEntry_AiMashima[] = {11, 0, gCreditsText_AiMashima};
static const struct CreditsEntry gCreditsEntry_GakujiNomoto[] = {11, 0, gCreditsText_GakujiNomoto};
static const struct CreditsEntry gCreditsEntry_TakehiroIzushi[] = {11, 0, gCreditsText_TakehiroIzushi};
static const struct CreditsEntry gCreditsEntry_HitoshiYamagami[] = {11, 0, gCreditsText_HitoshiYamagami};
static const struct CreditsEntry gCreditsEntry_KyokoWatanabe[] = {11, 0, gCreditsText_KyokoWatanabe};
static const struct CreditsEntry gCreditsEntry_TakaoNakano[] = {11, 0, gCreditsText_TakaoNakano};
static const struct CreditsEntry gCreditsEntry_HiroyukiJinnai[] = {11, 0, gCreditsText_HiroyukiJinnai};
static const struct CreditsEntry gCreditsEntry_HiroakiTsuru[] = {11, 0, gCreditsText_HiroakiTsuru};
static const struct CreditsEntry gCreditsEntry_TsunekazIshihara[] = {11, 0, gCreditsText_TsunekazIshihara};
static const struct CreditsEntry gCreditsEntry_SatoruIwata[] = {11, 0, gCreditsText_SatoruIwata};
static const struct CreditsEntry gCreditsEntry_KazuyaSuyama[] = {11, 0, gCreditsText_KazuyaSuyama};
static const struct CreditsEntry gCreditsEntry_SatoshiMitsuhara[] = {11, 0, gCreditsText_SatoshiMitsuhara};
static const struct CreditsEntry gCreditsEntry_JapanBrailleLibrary[] = {9, 0, gCreditsText_JapanBrailleLibrary};
static const struct CreditsEntry gCreditsEntry_TomotakaKomura[] = {11, 0, gCreditsText_TomotakaKomura};
static const struct CreditsEntry gCreditsEntry_MikikoOhhashi[] = {11, 0, gCreditsText_MikikoOhhashi};
static const struct CreditsEntry gCreditsEntry_DaisukeHoshino[] = {11, 0, gCreditsText_DaisukeHoshino};
static const struct CreditsEntry gCreditsEntry_KenjiroIto[] = {11, 0, gCreditsText_KenjiroIto};
static const struct CreditsEntry gCreditsEntry_RuiKawaguchi[] = {11, 0, gCreditsText_RuiKawaguchi};
static const struct CreditsEntry gCreditsEntry_ShunsukeKohori[] = {11, 0, gCreditsText_ShunsukeKohori};
static const struct CreditsEntry gCreditsEntry_SachikoNakamichi[] = {11, 0, gCreditsText_SachikoNakamichi};
static const struct CreditsEntry gCreditsEntry_FujikoNomura[] = {11, 0, gCreditsText_FujikoNomura};
static const struct CreditsEntry gCreditsEntry_KazukiYoshihara[] = {11, 0, gCreditsText_KazukiYoshihara};
static const struct CreditsEntry gCreditsEntry_RetsujiNomoto[] = {11, 0, gCreditsText_RetsujiNomoto};
static const struct CreditsEntry gCreditsEntry_AzusaTajima[] = {11, 0, gCreditsText_AzusaTajima};
static const struct CreditsEntry gCreditsEntry_ShusakuEgami[] = {11, 0, gCreditsText_ShusakuEgami};
static const struct CreditsEntry gCreditsEntry_PackageAndManual[] = {0, 1, gCreditsText_PackageAndManual};
static const struct CreditsEntry gCreditsEntry_EnglishVersion[] = {0, 1, gCreditsText_EnglishVersion};
static const struct CreditsEntry gCreditsEntry_Translator[] = {0, 1, gCreditsText_Translator};
static const struct CreditsEntry gCreditsEntry_TextEditor[] = {0, 1, gCreditsText_TextEditor};
static const struct CreditsEntry gCreditsEntry_NCLCoordinator[] = {0, 1, gCreditsText_NCLCoordinator};
static const struct CreditsEntry gCreditsEntry_GraphicDesigner[] = {0, 1, gCreditsText_GraphicDesigner};
static const struct CreditsEntry gCreditsEntry_NOAProductTesting[] = {0, 1, gCreditsText_NOAProductTesting};
static const struct CreditsEntry gCreditsEntry_HideyukiNakajima[] = {0, 0, gCreditsText_HideyukiNakajima};
static const struct CreditsEntry gCreditsEntry_HidenoriSaeki[] = {0, 0, gCreditsText_HidenoriSaeki};
static const struct CreditsEntry gCreditsEntry_YokoWatanabe[] = {0, 0, gCreditsText_YokoWatanabe};
static const struct CreditsEntry gCreditsEntry_SakaeKimura[] = {0, 0, gCreditsText_SakaeKimura};
static const struct CreditsEntry gCreditsEntry_ChiakiShinkai[] = {0, 0, gCreditsText_ChiakiShinkai};
static const struct CreditsEntry gCreditsEntry_SethMcMahill[] = {0, 0, gCreditsText_SethMcMahill};
static const struct CreditsEntry gCreditsEntry_NobOgasawara[] = {0, 0, gCreditsText_NobOgasawara};
static const struct CreditsEntry gCreditsEntry_TeresaLillygren[] = {0, 0, gCreditsText_TeresaLillygren};
static const struct CreditsEntry gCreditsEntry_KimikoNakamichi[] = {0, 0, gCreditsText_KimikoNakamichi};
static const struct CreditsEntry gCreditsEntry_SouichiYamamoto[] = {0, 0, gCreditsText_SouichiYamamoto};
static const struct CreditsEntry gCreditsEntry_YuichiroIto[] = {0, 0, gCreditsText_YuichiroIto};
static const struct CreditsEntry gCreditsEntry_ThomasHertzog[] = {0, 0, gCreditsText_ThomasHertzog};
static const struct CreditsEntry gCreditsEntry_MikaKurosawa[] = {0, 0, gCreditsText_MikaKurosawa};
static const struct CreditsEntry gCreditsEntry_NationalFederationBlind[] = {0, 0, gCreditsText_NationalFederationBlind};
static const struct CreditsEntry gCreditsEntry_PatriciaAMaurer[] = {0, 0, gCreditsText_PatriciaAMaurer};
static const struct CreditsEntry gCreditsEntry_EuropeanBlindUnion[] = {0, 0, gCreditsText_EuropeanBlindUnion};
static const struct CreditsEntry gCreditsEntry_AustralianBrailleAuthority[] = {0, 0, gCreditsText_AustralianBrailleAuthority};
static const struct CreditsEntry gCreditsEntry_RoyalNewZealandFederationBlind[] = {0, 0, gCreditsText_RoyalNewZealandFederationBlind};
static const struct CreditsEntry gCreditsEntry_MotoyasuTojima[] = {0, 0, gCreditsText_MotoyasuTojima};
static const struct CreditsEntry gCreditsEntry_NicolaPrattBarlow[] = {0, 0, gCreditsText_NicolaPrattBarlow};
static const struct CreditsEntry gCreditsEntry_ShellieDow[] = {0, 0, gCreditsText_ShellieDow};
static const struct CreditsEntry gCreditsEntry_ErikJohnson[] = {0, 0, gCreditsText_ErikJohnson};

#define _ gCreditsEntry_EmptyString
static const struct CreditsEntry *const gCreditsEntryPointerTable[][5] =
{
    {
        _,
        gCreditsEntry_PkmnEmeraldVersion,
        gCreditsEntry_Credits,
        _,
        _
    },
    {
        _,
        gCreditsEntry_Director,
        gCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ArtDirector,
        gCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_WorldDirector,
        gCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    {
        gCreditsEntry_LeadProgrammer,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_LeadGraphicArtist,
        gCreditsEntry_MotofumiFujiwara,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_TomomichiOhta,
        gCreditsEntry_NozomuSaito,
        gCreditsEntry_EmptyString,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_AkitoMori,
        gCreditsEntry_HiroyukiNakamura,
        gCreditsEntry_MasaoTaya,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_SatoshiNohara,
        gCreditsEntry_MiyukiIwasawa,
        gCreditsEntry_YoshinoriMatsuda,
        gCreditsEntry_KeitaKagaya,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_TetsuyaWatanabe,
        gCreditsEntry_SosukeTamada,
        gCreditsEntry_TakenoriOhta,
        _,
    },
    {
        _,
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_MotofumiFujiwara,
        gCreditsEntry_SatoshiOhta,
        _,
    },
    {
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_KenkichiToyama,
        gCreditsEntry_AsukaIwashita,
        gCreditsEntry_TakaoUnno,
        _,
    },
    {
        gCreditsEntry_GraphicDesigners,
        gCreditsEntry_KenSugimori,
        gCreditsEntry_HironobuYoshida,
        gCreditsEntry_AimiTomita,
        gCreditsEntry_KanakoEo,
    },
    {
        gCreditsEntry_MusicComposition,
        gCreditsEntry_GoIchinose,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_MorikazuAoki,
        gCreditsEntry_HitomiSato,
    },
    {
        _,
        gCreditsEntry_SoundEffectsAndPkmnVoices,
        gCreditsEntry_GoIchinose,
        gCreditsEntry_MorikazuAoki,
        _,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_ShigekiMorimoto,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_TakeshiKawachimaru,
        gCreditsEntry_AkihitoTomisawa,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_SuguruNakatsui,
        gCreditsEntry_TetsujiOhta,
        gCreditsEntry_HitomiSato,
        gCreditsEntry_KenjiMatsushima,
    },
    {
        gCreditsEntry_GameDesigners,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_KojiNishino,
        gCreditsEntry_ShigeruOhmori,
        gCreditsEntry_TadashiTakahashi,
    },
    {
        gCreditsEntry_ScenarioPlot,
        gCreditsEntry_AkihitoTomisawa,
        gCreditsEntry_JunichiMasuda,
        gCreditsEntry_KojiNishino,
        _,
    },
    {
        gCreditsEntry_Scenario,
        gCreditsEntry_AkihitoTomisawa,
        gCreditsEntry_HitomiSato,
        gCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    {
        gCreditsEntry_ScriptDesigners,
        gCreditsEntry_TomomichiOhta,
        gCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    {
        gCreditsEntry_MapDesigners,
        gCreditsEntry_SuguruNakatsui,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_ShigeruOhmori,
        gCreditsEntry_TetsujiOhta,
    },
    {
        _,
        gCreditsEntry_BattleFrontierData,
        gCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    {
        gCreditsEntry_ParametricDesigners,
        gCreditsEntry_TeruyukiShimoyamada,
        gCreditsEntry_ShigekiMorimoto,
        gCreditsEntry_TetsujiOhta,
        gCreditsEntry_KojiNishino,
    },
    {
        _,
        gCreditsEntry_PokedexText,
        gCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    {
        gCreditsEntry_EnvAndToolPgrms,
        gCreditsEntry_HisashiSogabe,
        gCreditsEntry_SosukeTamada,
        gCreditsEntry_HiroyukiNakamura,
        gCreditsEntry_AkitoMori,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_KenSugimori,
        gCreditsEntry_MotofumiFujiwara,
        gCreditsEntry_ShigekiMorimoto,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_HironobuYoshida,
        gCreditsEntry_SatoshiOhta,
        gCreditsEntry_AsukaIwashita,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_TakaoUnno,
        gCreditsEntry_KanakoEo,
        gCreditsEntry_AimiTomita,
        _,
    },
    {
        gCreditsEntry_PkmnDesigners,
        gCreditsEntry_AtsukoNishida,
        gCreditsEntry_MuneoSaito,
        gCreditsEntry_RenaYoshikawa,
        gCreditsEntry_JunOkutani,
    },
    {
        _,
        gCreditsEntry_SupportProgrammers,
        gCreditsEntry_SatoshiMitsuhara,
        gCreditsEntry_DaisukeHoshino,
        _,
    },
    {
        _,
        gCreditsEntry_NCLProductTesting,
        gCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_PackageAndManual,
        gCreditsEntry_KenSugimori,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_KenjiTominaga,
        gCreditsEntry_HirokiEnomoto,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_KazuyaSuyama,
        gCreditsEntry_KenjiroIto,
        gCreditsEntry_MichikoTakizawa,
        gCreditsEntry_MakikoTakada,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_MikikoOhhashi,
        gCreditsEntry_TakanaoKondo,
        gCreditsEntry_RuiKawaguchi,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_TakahiroOhnishi,
        gCreditsEntry_NorihideOkamura,
        gCreditsEntry_ShunsukeKohori,
        _,
    },
    {
        gCreditsEntry_InfoSupervisors,
        gCreditsEntry_KazuyukiTerada,
        gCreditsEntry_YuriSakurai,
        gCreditsEntry_YumiFunasaka,
        gCreditsEntry_NaokoYanase,
    },
    {
        _,
        gCreditsEntry_Artwork,
        gCreditsEntry_SachikoNakamichi,
        gCreditsEntry_FujikoNomura,
        _,
    },
    {
        _,
        gCreditsEntry_Artwork,
        gCreditsEntry_HideyukiNakajima,
        gCreditsEntry_HidenoriSaeki,
        _,
    },
    {
        gCreditsEntry_Artwork,
        gCreditsEntry_YokoWatanabe,
        gCreditsEntry_SakaeKimura,
        gCreditsEntry_ChiakiShinkai,
        _,
    },
    {
        gCreditsEntry_Coordinators,
        gCreditsEntry_KazukiYoshihara,
        gCreditsEntry_AkiraKinashi,
        gCreditsEntry_RetsujiNomoto,
        _,
    },
    {
        _,
        gCreditsEntry_EnglishVersion,
        gCreditsEntry_HiroNakamura,
        gCreditsEntry_SethMcMahill,
        _,
    },
    {
        _,
        gCreditsEntry_Translator,
        gCreditsEntry_NobOgasawara,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_TextEditor,
        gCreditsEntry_TeresaLillygren,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_NCLCoordinator,
        gCreditsEntry_KimikoNakamichi,
        _,
        _,
    },
    {
        gCreditsEntry_Programmers,
        gCreditsEntry_TerukiMurakawa,
        gCreditsEntry_SouichiYamamoto,
        gCreditsEntry_YuichiroIto,
        gCreditsEntry_AkiraKinashi,
    },
    {
        _,
        gCreditsEntry_GraphicDesigner,
        gCreditsEntry_AkiraKinashi,
        _,
        _,
    },
    {
        gCreditsEntry_EnvAndToolPgrms,
        gCreditsEntry_TerukiMurakawa,
        gCreditsEntry_SouichiYamamoto,
        gCreditsEntry_KimikoNakamichi,
        _,
    },
    {
        gCreditsEntry_NOAProductTesting,
        gCreditsEntry_ThomasHertzog,
        gCreditsEntry_ErikJohnson,
        gCreditsEntry_MikaKurosawa,
        _,
    },
    {
        gCreditsEntry_BrailleCodeCheck,
        gCreditsEntry_NationalFederationBlind,
        gCreditsEntry_PatriciaAMaurer,
        gCreditsEntry_JapanBrailleLibrary,
        gCreditsEntry_EuropeanBlindUnion,
    },
    {
        _,
        gCreditsEntry_BrailleCodeCheck,
        gCreditsEntry_AustralianBrailleAuthority,
        gCreditsEntry_RoyalNewZealandFederationBlind,
        _,
    },
    {
        gCreditsEntry_SpecialThanks,
        gCreditsEntry_HiroyukiUesugi,
        gCreditsEntry_MotoyasuTojima,
        gCreditsEntry_NicolaPrattBarlow,
        gCreditsEntry_ShellieDow,
    },
    {
        _,
        gCreditsEntry_TaskManagers,
        gCreditsEntry_AzusaTajima,
        gCreditsEntry_ShusakuEgami,
        _,
    },
    {
        gCreditsEntry_Producers,
        gCreditsEntry_HiroyukiJinnai,
        gCreditsEntry_HitoshiYamagami,
        gCreditsEntry_GakujiNomoto,
        gCreditsEntry_HiroakiTsuru,
    },
    {
        _,
        gCreditsEntry_ExecutiveDirector,
        gCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ExecProducers,
        gCreditsEntry_SatoruIwata,
        _,
        _,
    },
    {
        _,
        gCreditsEntry_ExecProducers,
        gCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _

static const struct BgTemplate gUnknown_085E6F68[] =
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
static const struct WindowTemplate gUnknown_085E6F6C[] =
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
static const u8 gUnknown_085E6F7C[][2] =
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
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
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

static void sub_8175744(u8 taskIdA);
static void sub_8175774(u8 taskIdA);
static void sub_8175808(u8 taskIdA);
static void c2_080C9BFC(u8 taskIdA);
static void sub_81758E4(u8 taskIdA);
static void sub_81758A4(u8 taskIdA);
static void sub_8175A9C(u8 taskIdA);
static void sub_8175AE4(u8 taskIdA);
static void sub_8175B1C(u8 taskIdA);
static void sub_8175B90(u8 taskIdA);
static void sub_8175BD8(u8 taskIdA);
static void sub_8175C34(u8 taskIdA);
static void sub_8175CC8(u8 taskIdA);
static void sub_8175CE4(void);
static void sub_8175DA0(u8 taskIdB);
static u8 sub_817603C(u8 page, u8 taskIdA);
static void sub_81760FC(u8 taskIdA);
static void sub_817651C(u8 taskIdA);
static void sub_817624C(u8 taskIdA);
static bool8 sub_8176AB0(u8 data, u8 taskIdA);
static void sub_8176CA0(u8 taskIdA);
static void sub_8176D1C(u16, u16, u16);
static void sub_8176E40(u16 arg0, u16 palette);
static void sub_8176EE8(struct Sprite *sprite);
static void sub_8176F90(struct Sprite *sprite);
static u8 sub_8177224(u16 species, s16 x, s16 y, u16 position);
static void sub_8177388(void);

static void sub_81754C8(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_81754DC(void)
{
    RunTasks();
    AnimateSprites();

    if ((gMain.heldKeys & B_BUTTON)
     && gHasHallOfFameRecords != 0
     && gTasks[gUnknown_0203BCE2].func == sub_8175774)
    {
        sub_81754C8();
        RunTasks();
        AnimateSprites();
        gUnknown_0203BCE5 = 1;
    }
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_8175548(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085E6F68, 1);
    SetBgTilemapBuffer(0, AllocZeroed(0x800));
    LoadPalette(gUnknown_085E56F0, 0x80, 0x40);
    InitWindows(gUnknown_085E6F6C);
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

static void sub_81755BC(const u8 *string, u8 y, u8 a2)
{
    u8 x;
    u8 color[3];

    color[0] = 0;

    if (a2 == 1)
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

void sub_8175620(void)
{
    u8 taskIdA;
    s16 taskIdC;
    u8 taskIdB;

    sub_8175CE4();
    SetVBlankCallback(NULL);
    InitHeap(gHeap, HEAP_SIZE);
    ResetPaletteFade();
    ResetTasks();
    sub_8175548();

    taskIdA = CreateTask(sub_8175744, 0);

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

    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(sub_81754C8);
    m4aSongNumStart(MUS_THANKFOR);
    SetMainCallback2(sub_81754DC);
    gUnknown_0203BCE5 = 0;
    gUnknown_0203BCE8 = AllocZeroed(sizeof(struct Unk201C000));

    sub_8177388();

    gUnknown_0203BCE8->unk8E = 0;
    gUnknown_0203BCE8->unk90 = 0;
    gUnknown_0203BCE8->unk92 = 0;

    gUnknown_0203BCE2 = taskIdA;
}

static void sub_8175744(u8 taskIdA)
{
    if (!gPaletteFade.active)
        gTasks[taskIdA].func = sub_8175774;
}

static void sub_8175774(u8 taskIdA)
{
    u16 data1;

    if (gTasks[taskIdA].data[TDA_4])
    {
        s16 taskIdC;

        taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
        gTasks[taskIdC].data[TDC_0] = 30;

        gTasks[taskIdA].data[TDA_12] = 0x100;
        gTasks[taskIdA].func = sub_8175A9C;
        return;
    }

    gUnknown_0203BCE0 = 0;
    data1 = gTasks[taskIdA].data[TDA_11];

    if (gTasks[taskIdA].data[TDA_11] == 1)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_8175808;
    }
    else if (gTasks[taskIdA].data[TDA_11] == 2)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_81758A4;
    }
}

static void sub_8175808(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        sub_8176CA0(taskIdA);
        gTasks[taskIdA].func = c2_080C9BFC;
    }
}

static void c2_080C9BFC(u8 taskIdA)
{
    u16 backup;

    SetVBlankCallback(NULL);

    if (sub_8176AB0(gTasks[taskIdA].data[TDA_7], taskIdA))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(sub_81754C8);
        gTasks[taskIdA].func = sub_8175744;
    }
}

static void sub_81758A4(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        sub_8176CA0(taskIdA);
        gTasks[taskIdA].func = sub_81758E4;
    }
}

static void sub_81758E4(u8 taskIdA)
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

        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
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
        gUnknown_0203BD28 = 0;
        gTasks[taskIdA].func = sub_8175744;
        break;
    }
}

static void sub_8175A9C(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_12])
    {
        gTasks[taskIdA].data[TDA_12] -= 1;
        return;
    }

    BeginNormalPaletteFade(0xFFFFFFFF, 12, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = sub_8175AE4;
}

static void sub_8175AE4(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        sub_8176CA0(taskIdA);
        gTasks[taskIdA].func = sub_8175B1C;
    }
}

static void sub_8175B1C(u8 taskIdA)
{
    sub_8175CE4();
    ResetPaletteFade();
    sub_8176D1C(0, 0x3800, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(0xFFFFFFFF, 8, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON);

    gTasks[taskIdA].data[TDA_0] = 0xEB;
    gTasks[taskIdA].func = sub_8175B90;
}

static void sub_8175B90(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0])
    {
        gTasks[taskIdA].data[TDA_0] -= 1;
        return;
    }

    BeginNormalPaletteFade(0xFFFFFFFF, 6, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = sub_8175BD8;
}

static void sub_8175BD8(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        sub_8176E40(0x3800, 0);

        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0, RGB_BLACK);
        gTasks[taskIdA].data[TDA_0] = 7200;
        gTasks[taskIdA].func = sub_8175C34;
    }
}

static void sub_8175C34(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskIdA].data[TDA_0] == 0 || gMain.newKeys)
        {
            FadeOutBGM(4);
            BeginNormalPaletteFade(0xFFFFFFFF, 8, 0, 16, RGB_WHITEALPHA);
            gTasks[taskIdA].func = sub_8175CC8;
            return;
        }

        if (gTasks[taskIdA].data[TDA_0] == 7144)
            FadeOutBGM(8);

        if (gTasks[taskIdA].data[TDA_0] == 6840)
            m4aSongNumStart(MUS_END);

        gTasks[taskIdA].data[TDA_0] -= 1;
    }
}

static void sub_8175CC8(u8 taskIdA)
{
    if (!gPaletteFade.active)
        SoftReset(0xFF);
}

static void sub_8175CE4(void)
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
        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].func == sub_8175774)
        {
            if (gTasks[taskIdB].data[TDB_CURRENT_PAGE] < PAGE_COUNT)
            {
                for (i = 0; i < 5; i++)
                    sub_81755BC(gCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->text, 5 + i * 16, gCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->var_1);

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

        if (sub_817603C((u8)gTasks[taskIdB].data[TDB_CURRENT_PAGE], (u8)gTasks[taskIdB].data[TDB_TASK_A_ID]))
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
        FREE_AND_SET_NULL(gUnknown_0203BCE8);
        return;
    }
}

static u8 sub_817603C(u8 page, u8 taskIdA)
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
        if (gUnknown_0203BCE8->unk90 == 0 && gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].data[TDA_14] == 0)
            break;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 2:
        if (gUnknown_0203BCE8->unk8E == 71 || gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].func != sub_8175774)
            break;
        r2 = sub_8177224(gUnknown_0203BCE8->unk0[gUnknown_0203BCE8->unk92], gUnknown_085E6F7C[gUnknown_0203BCE8->unk90][0], gUnknown_085E6F7C[gUnknown_0203BCE8->unk90][1], gUnknown_0203BCE8->unk90);
        if (gUnknown_0203BCE8->unk92 < gUnknown_0203BCE8->unk94 - 1)
        {
            gUnknown_0203BCE8->unk92++;
            gSprites[r2].data[3] = 50;
        }
        else
        {
            gUnknown_0203BCE8->unk92 = 0;
            gSprites[r2].data[3] = 512;
        }
        gUnknown_0203BCE8->unk8E++;
        if (gUnknown_0203BCE8->unk90 == 2)
            gUnknown_0203BCE8->unk90 = 0;
        else
            gUnknown_0203BCE8->unk90++;
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
        gUnknown_0203BD26 = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
        gTasks[taskIdC].data[TDC_5]++;
        break;
    case 1:
        if (gUnknown_0203BD26 != 0)
        {
            gUnknown_0203BD26 = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
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
            gUnknown_0203BD26 = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
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
            gUnknown_0203BD26 = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
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
        sub_817B540(0);
        break;
    case 1:
        sub_817B540(0);
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
        sub_817B540(1);
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
        sub_817B540(1);
        break;
    case 4:
        sub_817B540(2);
        break;
    }
}

static void sub_817664C(u8 data, u8 taskIdA)
{
    switch (data)
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
        gTasks[taskIdA].data[TDA_0] = CreateBicycleAnimationTask(0, 0x2000, 0x20, 8);
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
        gTasks[taskIdA].data[TDA_0] = CreateBicycleAnimationTask(0, 0x2000, 0x20, 8);
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
        gTasks[taskIdA].data[TDA_0] = CreateBicycleAnimationTask(1, 0x2000, 0x200, 8);
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
        gTasks[taskIdA].data[TDA_0] = CreateBicycleAnimationTask(1, 0x2000, 0x200, 8);
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
        gTasks[taskIdA].data[TDA_0] = CreateBicycleAnimationTask(2, 0x2000, 0x200, 8);
        break;
    }

    gTasks[taskIdA].data[TDA_TASK_E_ID] = CreateTask(sub_817651C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_0] = data;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_1] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_TASK_A_ID] = taskIdA;

    gTasks[taskIdA].data[TDA_TASK_C_ID] = CreateTask(sub_817624C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_0] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_1] = taskIdA;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_2] = gTasks[taskIdA].data[TDA_PLAYER_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_3] = gTasks[taskIdA].data[TDA_RIVAL_CYCLIST];
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_4] = 0;

    if (data == 2)
        gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_5] = 0x45;
}

static bool8 sub_8176AB0(u8 data, u8 taskIdA)
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
        gUnknown_0203BD24 = 34;
        gUnknown_0203BD26 = 0;
        sub_817B1C8(data);
        gMain.state += 1;
        break;
    case 2:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            LoadCompressedSpriteSheet(gUnknown_085F5334);
            LoadCompressedSpriteSheet(gUnknown_085F53BC);
            LoadCompressedSpriteSheet(gUnknown_085F5354);
            LoadSpritePalettes(gUnknown_085F5384);

            spriteId = intro_create_brendan_sprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176EE8;
            gSprites[spriteId].anims = gUnknown_085E6FD0;

            spriteId = intro_create_may_sprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176F90;
            gSprites[spriteId].anims = gUnknown_085E7010;
        }
        else
        {
            LoadCompressedSpriteSheet(gUnknown_085F5344);
            LoadCompressedSpriteSheet(gUnknown_085F53AC);
            LoadCompressedSpriteSheet(gUnknown_085F5354);
            LoadSpritePalettes(gUnknown_085F5384);

            spriteId = intro_create_may_sprite(120, 46);
            gTasks[taskIdA].data[TDA_PLAYER_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176EE8;
            gSprites[spriteId].anims = gUnknown_085E6FD0;

            spriteId = intro_create_brendan_sprite(272, 46);
            gTasks[taskIdA].data[TDA_RIVAL_CYCLIST] = spriteId;
            gSprites[spriteId].callback = sub_8176F90;
            gSprites[spriteId].anims = gUnknown_085E7010;
        };
        gMain.state += 1;
        break;
    case 3:
        sub_817664C(data, taskIdA);
        sub_817B3A8(data);
        gMain.state = 0;
        return TRUE;
    }
    return FALSE;
}

static void sub_8176CA0(u8 taskIdA)
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

    gUnknown_0203BD28 = 1;
}

static void sub_8176D1C(u16 arg0, u16 arg1, u16 arg2)
{
    u16 baseTile;
    u16 i;

    LZ77UnCompVram(gCreditsCopyrightEnd_Gfx, (void *)(VRAM + arg0));
    LoadPalette(gIntroCopyright_Pal, arg2, sizeof(gIntroCopyright_Pal));

    baseTile = (arg2 / 16) << 12;

    for (i = 0; i < 32 * 32; i++)
        ((u16 *) (VRAM + arg1))[i] = baseTile + 1;
}

static u16 sub_8176D78(u8 arg0)
{
    u16 out = (arg0 & 0x3F) + 80;

    if (arg0 == 0xFF)
        return 1;

    if (arg0 & (1 << 7))
        out |= 1 << 11;
    if (arg0 & (1 << 6))
        out |= 1 << 10;

    return out;
}

static void sub_8176DBC(const u8 arg0[], u8 baseX, u8 baseY, u16 arg3, u16 palette)
{
    u8 y, x;
    const u16 tileOffset = (palette / 16) << 12;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 3; x++)
            ((u16 *) (VRAM + arg3 + (baseY + y) * 64))[baseX + x] = tileOffset + sub_8176D78(arg0[y * 3 + x]);
    }
}

static void sub_8176E40(u16 arg0, u16 palette)
{
    u16 pos;
    u16 baseTile = (palette / 16) << 12;

    for (pos = 0; pos < 32 * 32; pos++)
        ((u16 *) (VRAM + arg0))[pos] = baseTile + 1;

    sub_8176DBC(gUnknown_085E5BAC, 3, 7, arg0, palette);
    sub_8176DBC(gUnknown_085E5BBB, 7, 7, arg0, palette);
    sub_8176DBC(gUnknown_085E5BCA, 11, 7, arg0, palette);
    sub_8176DBC(gUnknown_085E5BCA, 16, 7, arg0, palette);
    sub_8176DBC(gUnknown_085E5BD9, 20, 7, arg0, palette);
    sub_8176DBC(gUnknown_085E5BE8, 24, 7, arg0, palette);
}

static void sub_8176EE8(struct Sprite *sprite)
{
    if (gUnknown_0203BD28 != 0)
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
    if (gUnknown_0203BD28 != 0)
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
        sprite->pos2.y = -gUnknown_0203BD26;
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
    if (gUnknown_0203BD28)
    {
        FreeAndDestroyMonPicSprite(sprite->data[6]);
        return;
    }

    sprite->data[7] += 1;
    switch (sprite->data[0])
    {
    case 0:
    default:
        sprite->oam.affineMode = 1;
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
            sprite->oam.objMode = 1;
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

static u8 sub_8177224(u16 nationalDexNum, s16 x, s16 y, u16 position)
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
    if (gSprites[sprite->data[0]].data[0] == 10 || gUnknown_0203BD28)
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

static void sub_8177388(void)
{
    u16 starter = SpeciesToNationalPokedexNum(GetStarterPokemon(VarGet(VAR_STARTER_MON)));
    u16 page;
    u16 dexNum;
    u16 j;

    for (dexNum = 1, j = 0; dexNum < NATIONAL_DEX_COUNT; dexNum++)
    {
        if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
        {
            gUnknown_0203BCE8->unk96[j] = dexNum;
            j++;
        }
    }

    for (dexNum = j; dexNum < NATIONAL_DEX_COUNT; dexNum++)
        gUnknown_0203BCE8->unk96[dexNum] = 0;

    gUnknown_0203BCE8->unk39A = j;
    if (gUnknown_0203BCE8->unk39A < 71)
        gUnknown_0203BCE8->unk94 = j;
    else
        gUnknown_0203BCE8->unk94 = 71;

    j = 0;
    do
    {
        page = Random() % gUnknown_0203BCE8->unk39A;
        gUnknown_0203BCE8->unk0[j] = gUnknown_0203BCE8->unk96[page];

        j++;
        gUnknown_0203BCE8->unk96[page] = 0;
        gUnknown_0203BCE8->unk39A--;
        if (page != gUnknown_0203BCE8->unk39A)
        {
            gUnknown_0203BCE8->unk96[page] = gUnknown_0203BCE8->unk96[gUnknown_0203BCE8->unk39A];
            gUnknown_0203BCE8->unk96[gUnknown_0203BCE8->unk39A] = 0;
        }
    }
    while (gUnknown_0203BCE8->unk39A != 0 && j < 71);

    if (gUnknown_0203BCE8->unk94 < 71)
    {
        for (j = gUnknown_0203BCE8->unk94, page = 0; j < 71; j++)
        {
            gUnknown_0203BCE8->unk0[j] = gUnknown_0203BCE8->unk0[page];

            page++;
            if (page == gUnknown_0203BCE8->unk94)
                page = 0;
        }
        gUnknown_0203BCE8->unk0[70] = starter;
    }
    else
    {
        for (dexNum = 0; gUnknown_0203BCE8->unk0[dexNum] != starter && dexNum < 71; dexNum++);

        if (dexNum < gUnknown_0203BCE8->unk94 - 1)
        {
            gUnknown_0203BCE8->unk0[dexNum] = gUnknown_0203BCE8->unk0[70];
            gUnknown_0203BCE8->unk0[70] = starter;
        }
        else
        {
            gUnknown_0203BCE8->unk0[70] = starter;
        }
    }
    gUnknown_0203BCE8->unk94 = 71;
}
