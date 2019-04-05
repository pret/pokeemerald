#include "global.h"
#include "main.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_specials.h"
#include "item.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "constants/items.h"
#include "constants/songs.h"

// multichoice lists
const struct MenuAction MultichoiceList_000[] =
{
    {gUnknown_085EAD37, NULL},
    {gUnknown_085EAD41, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_002[] =
{
    {gUnknown_085EAD67, NULL},
    {gUnknown_085EAD6D, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_003[] =
{
    {gUnknown_085EAD72, NULL},
    {gUnknown_085EAD84, NULL},
    {gUnknown_085EAD96, NULL},
    {gText_Cancel2, NULL},
};

const struct MenuAction MultichoiceList_004[] =
{
    {gUnknown_085EADA4, NULL},
    {gUnknown_085EADB5, NULL},
    {gUnknown_085EADC4, NULL},
    {gUnknown_085EADD5, NULL},
    {gUnknown_085EADE7, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_006[] =
{
    {gUnknown_085EADF9, NULL},
    {gUnknown_085EAE04, NULL},
    {gUnknown_085EAE12, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_005[] =
{
    {gUnknown_085EADF9, NULL},
    {gUnknown_085EAE04, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_007[] =
{
    {gMenuText_Register, NULL},
    {gUnknown_085EAE12, NULL},
    {gUnknown_085EAE1B, NULL},
    {gText_Cancel2, NULL},
};

const struct MenuAction MultichoiceList_012[] =
{
    {gUnknown_085EAE27, NULL},
    {gUnknown_085EAE2C, NULL},
};

const struct MenuAction MultichoiceList_013[] =
{
    {gUnknown_085EAE31, NULL},
    {gUnknown_085EAE35, NULL},
    {gUnknown_085EAE39, NULL},
    {gUnknown_085EAE3D, NULL},
    {gUnknown_085EAE41, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_014[] =
{
    {gUnknown_085EAD5F, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_016[] =
{
    {gUnknown_085EAE53, NULL},
    {gUnknown_085EAE5A, NULL},
};

const struct MenuAction MultichoiceList_020[] =
{
    {gText_Yes, NULL},
    {gText_No, NULL},
    {gUnknown_085EAD6D, NULL},
};

const struct MenuAction MultichoiceList_023[] =
{
    {gUnknown_085EAEA2, NULL},
    {gUnknown_085EAEAC, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_024[] =
{
    {gText_Lv50, NULL},
    {gText_OpenLevel, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_025[] =
{
    {gUnknown_0827ECBC, NULL},
    {gUnknown_0827ECC3, NULL},
    {gUnknown_0827ECCD, NULL},
};

const struct MenuAction MultichoiceList_026[] =
{
    {gUnknown_0827ECD5, NULL},
    {gUnknown_0827ECDD, NULL},
    {gUnknown_0827ECE3, NULL},
};

const struct MenuAction MultichoiceList_027[] =
{
    {gUnknown_0827ECEB, NULL},
    {gUnknown_0827ECF2, NULL},
    {gUnknown_0827ECF8, NULL},
};

const struct MenuAction MultichoiceList_028[] =
{
    {gUnknown_0827ED00, NULL},
    {gUnknown_0827ED06, NULL},
    {gUnknown_0827ED10, NULL},
};

const struct MenuAction MultichoiceList_029[] =
{
    {gUnknown_0827ED18, NULL},
    {gUnknown_0827ED22, NULL},
    {gUnknown_0827ED2C, NULL},
};

const struct MenuAction MultichoiceList_030[] =
{
    {gUnknown_0827ED36, NULL},
    {gUnknown_0827ED40, NULL},
    {gUnknown_0827ED46, NULL},
};

const struct MenuAction MultichoiceList_031[] =
{
    {gUnknown_0827ED4F, NULL},
    {gUnknown_0827ED59, NULL},
    {gUnknown_0827ED65, NULL},
};

const struct MenuAction MultichoiceList_032[] =
{
    {gUnknown_0827ED70, NULL},
    {gUnknown_0827ED74, NULL},
    {gUnknown_0827ED78, NULL},
};

const struct MenuAction MultichoiceList_033[] =
{
    {gUnknown_0827ED80, NULL},
    {gUnknown_0827ED95, NULL},
    {gUnknown_0827EDAA, NULL},
};

const struct MenuAction MultichoiceList_034[] =
{
    {gUnknown_0827EDB5, NULL},
    {gUnknown_0827EDBA, NULL},
    {gUnknown_0827EDC1, NULL},
};

const struct MenuAction MultichoiceList_035[] =
{
    {gUnknown_0827EDC9, NULL},
    {gUnknown_0827EDD5, NULL},
    {gUnknown_0827EDE4, NULL},
};

const struct MenuAction MultichoiceList_036[] =
{
    {gUnknown_0827EDF0, NULL},
    {gUnknown_0827EDF5, NULL},
    {gUnknown_0827EDF7, NULL},
};

const struct MenuAction MultichoiceList_037[] =
{
    {gUnknown_0827EDF9, NULL},
    {gUnknown_0827EDFB, NULL},
    {gUnknown_0827EDFD, NULL},
};

const struct MenuAction MultichoiceList_038[] =
{
    {gUnknown_0827EDFF, NULL},
    {gUnknown_0827EE01, NULL},
    {gUnknown_0827EE03, NULL},
};

const struct MenuAction MultichoiceList_039[] =
{
    {gUnknown_0827EE05, NULL},
    {gUnknown_0827EE07, NULL},
    {gUnknown_0827EE09, NULL},
};

const struct MenuAction MultichoiceList_042[] =
{
    {gUnknown_085EAEC3, NULL},
    {gUnknown_085EAED6, NULL},
    {gUnknown_085EAEE6, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_043[] =
{
    {gUnknown_085EAEF6, NULL},
    {gUnknown_085EAF02, NULL},
    {gUnknown_085EAF0E, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_044[] =
{
    {gUnknown_085EAF1B, NULL},
    {gUnknown_085EAF24, NULL},
    {gUnknown_085EAF2F, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_045[] =
{
    {gUnknown_085EAF34, NULL},
    {gUnknown_085EAF3E, NULL},
};

const struct MenuAction MultichoiceList_046[] =
{
    {gUnknown_085EAF4B, NULL},
    {gUnknown_085EAF58, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_047[] =
{
    {gUnknown_085EAF65, NULL},
    {gUnknown_085EAF70, NULL},
    {gUnknown_085EAF7D, NULL},
    {gUnknown_085EAF87, NULL},
    {gUnknown_085EAF93, NULL},
    {gUnknown_085EAF9F, NULL},
    {gUnknown_085EAFAB, NULL},
    {gText_Cancel2, NULL},
};

const struct MenuAction MultichoiceList_048[] =
{
    {gUnknown_085EAFB6, NULL},
    {gUnknown_085EAFCF, NULL},
    {gUnknown_085EAFE8, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_055[] =
{
    {gUnknown_085EB089, NULL},
    {gUnknown_085EB09C, NULL},
    {gUnknown_085EB0AF, NULL},
    {gUnknown_085EB0C2, NULL},
    {gUnknown_085EB0D5, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_049[] =
{
    {gUnknown_085EB002, NULL},
    {gUnknown_085EB017, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_050[] =
{
    {gUnknown_085EB02A, NULL},
    {gUnknown_085EB034, NULL},
};

const struct MenuAction MultichoiceList_052[] =
{
    {gText_LilycoveCity, NULL},
    {gText_BattleFrontier, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_053[] =
{
    {gText_SlateportCity, NULL},
    {gText_LilycoveCity, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_054[] =
{
    {gUnknown_085EB07E, NULL},
    {gUnknown_085EB084, NULL},
};

const struct MenuAction MultichoiceList_056[] =
{
    {gText_LilycoveCity, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_057[] =
{
    {gText_5F, NULL},
    {gText_4F, NULL},
    {gText_3F, NULL},
    {gText_2F, NULL},
    {gText_1F, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_058[] =
{
    {gUnknown_085EB040, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_059[] =
{
    {gUnknown_085EB04A, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_060[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB04A, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_061[] =
{
    {gUnknown_085EB057, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_062[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB057, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_063[] =
{
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB057, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_064[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB057, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_065[] =
{
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_066[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_067[] =
{
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_068[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_069[] =
{
    {gUnknown_085EB057, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_070[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB057, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_071[] =
{
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB057, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_072[] =
{
    {gUnknown_085EB040, NULL},
    {gUnknown_085EB04A, NULL},
    {gUnknown_085EB057, NULL},
    {gUnknown_085EB062, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_073[] =
{
    {gText_Opponent, NULL},
    {gText_Tourney_Tree, NULL},
    {gText_ReadyToStart, NULL},
    {gUnknown_085EB5BC, NULL},
    {gUnknown_085EB5C3, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_107[] =
{
    {gText_Opponent, NULL},
    {gText_Tourney_Tree, NULL},
    {gText_ReadyToStart, NULL},
    {gUnknown_085EB5C3, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_088[] =
{
    {gUnknown_085EB29A, NULL},
    {gUnknown_085EB2A3, NULL},
};

const struct MenuAction MultichoiceList_076[] =
{
    {gUnknown_085EB372, NULL},
    {gUnknown_085EB37F, NULL},
    {gUnknown_085EB389, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_017[] =
{
    {gText_Yes, NULL},
    {gText_No, NULL},
    {gUnknown_085EAD6D, NULL},
};

const struct MenuAction MultichoiceList_018[] =
{
    {gUnknown_085EAE6E, NULL},
    {gUnknown_085EAE7C, NULL},
    {gUnknown_085EAE8A, NULL},
    {gUnknown_085EAD6D, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_078[] =
{
    {gUnknown_085EB372, NULL},
    {gUnknown_085EB37F, NULL},
    {gUnknown_085EB397, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_079[] =
{
    {gUnknown_085EB372, NULL},
    {gUnknown_085EB37F, NULL},
    {gUnknown_085EB389, NULL},
    {gUnknown_085EB397, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_074[] =
{
    {gUnknown_085EB372, NULL},
    {gUnknown_085EB37F, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_080[] =
{
    {gUnknown_085EB3A4, NULL},
    {gUnknown_085EB3B1, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_081[] =
{
    {gUnknown_085EB3D4, NULL},
    {gUnknown_085EB3C6, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_082[] =
{
    {gText_NormalRank, NULL},
    {gText_SuperRank, NULL},
    {gText_HyperRank, NULL},
    {gText_MasterRank, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_083[] =
{
    {gText_BattleBag, NULL},
    {gText_HeldItem, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_084[] =
{
    {gText_LinkContest, NULL},
    {gText_AboutE_Mode, NULL},
    {gText_AboutG_Mode, NULL},
    {gText_Cancel2, NULL},
};

const struct MenuAction MultichoiceList_085[] =
{
    {gText_E_Mode, NULL},
    {gText_G_Mode, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_086[] =
{
    {gText_MenuOptionPokedex, NULL},
    {gText_MenuOptionPokemon, NULL},
    {gText_MenuOptionBag, NULL},
    {gText_MenuOptionPokenav, NULL},
    {gUnknown_085EB278, NULL},
    {gText_MenuOptionSave, NULL},
    {gText_MenuOptionOption, NULL},
    {gText_MenuOptionExit, NULL},
};

const struct MenuAction MultichoiceList_087[] =
{
    {gUnknown_085EB28A, NULL},
    {gUnknown_085EB290, NULL},
    {gUnknown_085EB295, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_089[] =
{
    {gText_SouthernIsland, NULL},
    {gText_BirthIsland, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_090[] =
{
    {gText_SouthernIsland, NULL},
    {gText_FarawayIsland, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_091[] =
{
    {gText_BirthIsland, NULL},
    {gText_FarawayIsland, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_092[] =
{
    {gText_SouthernIsland, NULL},
    {gText_BirthIsland, NULL},
    {gText_FarawayIsland, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_093[] =
{
    {gUnknown_085EB2E4, NULL},
    {gUnknown_085EB2F0, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_094[] =
{
    {gText_Yes, NULL},
    {gUnknown_085EB2FC, NULL},
};

const struct MenuAction MultichoiceList_095[] =
{
    {gUnknown_085EB3DF, NULL},
    {gUnknown_085EB3EA, NULL},
    {gUnknown_085EB3F1, NULL},
    {gUnknown_085EB3FC, NULL},
    {gUnknown_085EB40A, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_011[] =
{
    {gUnknown_085EB415, NULL},
    {gUnknown_085EB41D, NULL},
    {gUnknown_085EB424, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_096[] =
{
    {gUnknown_085EB45C, NULL},
    {gUnknown_085EB469, NULL},
    {gUnknown_085EB475, NULL},
    {gUnknown_085EB482, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_097[] =
{
    {gUnknown_085EB42F, NULL},
    {gUnknown_085EB43A, NULL},
    {gUnknown_085EB444, NULL},
    {gUnknown_085EB451, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_098[] =
{
    {gUnknown_085EB48E, NULL},
    {gUnknown_085EB496, NULL},
    {gUnknown_085EB4A3, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_099[] =
{
    {gUnknown_085EB4AD, NULL},
    {gUnknown_085EB4B9, NULL},
    {gUnknown_085EB4C7, NULL},
    {gUnknown_085EB4D4, NULL},
    {gUnknown_085EB4E0, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_100[] =
{
    {gText_BattleBasics, NULL},
    {gText_PokemonNature, NULL},
    {gText_PokemonMoves, NULL},
    {gText_Underpowered, NULL},
    {gText_WhenInDanger, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_101[] =
{
    {gUnknown_085EB532, NULL},
    {gUnknown_085EB543, NULL},
    {gUnknown_085EB555, NULL},
    {gUnknown_085EB563, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_102[] =
{
    {gUnknown_085EB56E, NULL},
    {gUnknown_085EB57E, NULL},
    {gUnknown_085EB589, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_103[] =
{
    {gUnknown_085EB5B6, NULL},
    {gUnknown_085EB5BC, NULL},
    {gUnknown_085EB5C3, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_104[] =
{
    {gUnknown_085EB5B6, NULL},
    {gUnknown_085EB5C3, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_105[] =
{
    {gUnknown_085EB5B6, NULL},
    {gUnknown_085EB5BC, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_106[] =
{
    {gUnknown_085EB5B6, NULL},
    {gUnknown_085EB5C8, NULL},
};

const struct MenuAction MultichoiceList_108[] =
{
    {gUnknown_085EE14B, NULL},
    {gUnknown_085EE14F, NULL},
};

const struct MenuAction MultichoiceList_109[] =
{
    {gUnknown_085EB2FF, NULL},
    {gUnknown_085EB310, NULL},
    {gUnknown_085EB317, NULL},
    {gUnknown_085EB31F, NULL},
};

const struct MenuAction MultichoiceList_110[] =
{
    {gText_CaveOfOrigin, NULL},
    {gText_MtPyre, NULL},
    {gText_SkyPillar, NULL},
    {gText_DontRemember, NULL},
};

const struct MenuAction MultichoiceList_111[] =
{
    {gUnknown_085EB4AD, NULL},
    {gUnknown_085EB4B9, NULL},
    {gUnknown_085EB4C7, NULL},
    {gUnknown_085EB4D4, NULL},
    {gUnknown_085EB597, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_112[] =
{
    {gText_BattleTrainers, NULL},
    {gUnknown_085EB45C, NULL},
    {gUnknown_085EB469, NULL},
    {gUnknown_085EB475, NULL},
    {gUnknown_085EB482, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_113[] =
{
    {gText_NormalTagMatch, NULL},
    {gText_VarietyTagMatch, NULL},
    {gText_UniqueTagMatch, NULL},
    {gText_ExpertTagMatch, NULL},
    {gText_Exit, NULL},
};

const struct MenuAction MultichoiceList_001[] =
{
    {gText_Exit, NULL},
};

struct MultichoiceListStruct
{
    const struct MenuAction *list;
    u8 count;
};

const struct MultichoiceListStruct gMultichoiceLists[] =
{
    {MultichoiceList_000, ARRAY_COUNT(MultichoiceList_000)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_002, ARRAY_COUNT(MultichoiceList_002)},
    {MultichoiceList_003, ARRAY_COUNT(MultichoiceList_003)},
    {MultichoiceList_004, ARRAY_COUNT(MultichoiceList_004)},
    {MultichoiceList_005, ARRAY_COUNT(MultichoiceList_005)},
    {MultichoiceList_006, ARRAY_COUNT(MultichoiceList_006)},
    {MultichoiceList_007, ARRAY_COUNT(MultichoiceList_007)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_011, ARRAY_COUNT(MultichoiceList_011)},
    {MultichoiceList_012, ARRAY_COUNT(MultichoiceList_012)},
    {MultichoiceList_013, ARRAY_COUNT(MultichoiceList_013)},
    {MultichoiceList_014, ARRAY_COUNT(MultichoiceList_014)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_016, ARRAY_COUNT(MultichoiceList_016)},
    {MultichoiceList_017, ARRAY_COUNT(MultichoiceList_017)},
    {MultichoiceList_018, ARRAY_COUNT(MultichoiceList_018)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_020, ARRAY_COUNT(MultichoiceList_020)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_023, ARRAY_COUNT(MultichoiceList_023)},
    {MultichoiceList_024, ARRAY_COUNT(MultichoiceList_024)},
    {MultichoiceList_025, ARRAY_COUNT(MultichoiceList_025)},
    {MultichoiceList_026, ARRAY_COUNT(MultichoiceList_026)},
    {MultichoiceList_027, ARRAY_COUNT(MultichoiceList_027)},
    {MultichoiceList_028, ARRAY_COUNT(MultichoiceList_028)},
    {MultichoiceList_029, ARRAY_COUNT(MultichoiceList_029)},
    {MultichoiceList_030, ARRAY_COUNT(MultichoiceList_030)},
    {MultichoiceList_031, ARRAY_COUNT(MultichoiceList_031)},
    {MultichoiceList_032, ARRAY_COUNT(MultichoiceList_032)},
    {MultichoiceList_033, ARRAY_COUNT(MultichoiceList_033)},
    {MultichoiceList_034, ARRAY_COUNT(MultichoiceList_034)},
    {MultichoiceList_035, ARRAY_COUNT(MultichoiceList_035)},
    {MultichoiceList_036, ARRAY_COUNT(MultichoiceList_036)},
    {MultichoiceList_037, ARRAY_COUNT(MultichoiceList_037)},
    {MultichoiceList_038, ARRAY_COUNT(MultichoiceList_038)},
    {MultichoiceList_039, ARRAY_COUNT(MultichoiceList_039)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_042, ARRAY_COUNT(MultichoiceList_042)},
    {MultichoiceList_043, ARRAY_COUNT(MultichoiceList_043)},
    {MultichoiceList_044, ARRAY_COUNT(MultichoiceList_044)},
    {MultichoiceList_045, ARRAY_COUNT(MultichoiceList_045)},
    {MultichoiceList_046, ARRAY_COUNT(MultichoiceList_046)},
    {MultichoiceList_047, ARRAY_COUNT(MultichoiceList_047)},
    {MultichoiceList_048, ARRAY_COUNT(MultichoiceList_048)},
    {MultichoiceList_049, ARRAY_COUNT(MultichoiceList_049)},
    {MultichoiceList_050, ARRAY_COUNT(MultichoiceList_050)},
    {MultichoiceList_001, ARRAY_COUNT(MultichoiceList_001)},
    {MultichoiceList_052, ARRAY_COUNT(MultichoiceList_052)},
    {MultichoiceList_053, ARRAY_COUNT(MultichoiceList_053)},
    {MultichoiceList_054, ARRAY_COUNT(MultichoiceList_054)},
    {MultichoiceList_055, ARRAY_COUNT(MultichoiceList_055)},
    {MultichoiceList_056, ARRAY_COUNT(MultichoiceList_056)},
    {MultichoiceList_057, ARRAY_COUNT(MultichoiceList_057)},
    {MultichoiceList_058, ARRAY_COUNT(MultichoiceList_058)},
    {MultichoiceList_059, ARRAY_COUNT(MultichoiceList_059)},
    {MultichoiceList_060, ARRAY_COUNT(MultichoiceList_060)},
    {MultichoiceList_061, ARRAY_COUNT(MultichoiceList_061)},
    {MultichoiceList_062, ARRAY_COUNT(MultichoiceList_062)},
    {MultichoiceList_063, ARRAY_COUNT(MultichoiceList_063)},
    {MultichoiceList_064, ARRAY_COUNT(MultichoiceList_064)},
    {MultichoiceList_065, ARRAY_COUNT(MultichoiceList_065)},
    {MultichoiceList_066, ARRAY_COUNT(MultichoiceList_066)},
    {MultichoiceList_067, ARRAY_COUNT(MultichoiceList_067)},
    {MultichoiceList_068, ARRAY_COUNT(MultichoiceList_068)},
    {MultichoiceList_069, ARRAY_COUNT(MultichoiceList_069)},
    {MultichoiceList_070, ARRAY_COUNT(MultichoiceList_070)},
    {MultichoiceList_071, ARRAY_COUNT(MultichoiceList_071)},
    {MultichoiceList_072, ARRAY_COUNT(MultichoiceList_072)},
    {MultichoiceList_073, ARRAY_COUNT(MultichoiceList_073)},
    {MultichoiceList_074, ARRAY_COUNT(MultichoiceList_074)},
    {MultichoiceList_074, ARRAY_COUNT(MultichoiceList_074)},
    {MultichoiceList_076, ARRAY_COUNT(MultichoiceList_076)},
    {MultichoiceList_076, ARRAY_COUNT(MultichoiceList_076)},
    {MultichoiceList_078, ARRAY_COUNT(MultichoiceList_078)},
    {MultichoiceList_079, ARRAY_COUNT(MultichoiceList_079)},
    {MultichoiceList_080, ARRAY_COUNT(MultichoiceList_080)},
    {MultichoiceList_081, ARRAY_COUNT(MultichoiceList_081)},
    {MultichoiceList_082, ARRAY_COUNT(MultichoiceList_082)},
    {MultichoiceList_083, ARRAY_COUNT(MultichoiceList_083)},
    {MultichoiceList_084, ARRAY_COUNT(MultichoiceList_084)},
    {MultichoiceList_085, ARRAY_COUNT(MultichoiceList_085)},
    {MultichoiceList_086, ARRAY_COUNT(MultichoiceList_086)},
    {MultichoiceList_087, ARRAY_COUNT(MultichoiceList_087)},
    {MultichoiceList_088, ARRAY_COUNT(MultichoiceList_088)},
    {MultichoiceList_089, ARRAY_COUNT(MultichoiceList_089)},
    {MultichoiceList_090, ARRAY_COUNT(MultichoiceList_090)},
    {MultichoiceList_091, ARRAY_COUNT(MultichoiceList_091)},
    {MultichoiceList_092, ARRAY_COUNT(MultichoiceList_092)},
    {MultichoiceList_093, ARRAY_COUNT(MultichoiceList_093)},
    {MultichoiceList_094, ARRAY_COUNT(MultichoiceList_094)},
    {MultichoiceList_095, ARRAY_COUNT(MultichoiceList_095)},
    {MultichoiceList_096, ARRAY_COUNT(MultichoiceList_096)},
    {MultichoiceList_097, ARRAY_COUNT(MultichoiceList_097)},
    {MultichoiceList_098, ARRAY_COUNT(MultichoiceList_098)},
    {MultichoiceList_099, ARRAY_COUNT(MultichoiceList_099)},
    {MultichoiceList_100, ARRAY_COUNT(MultichoiceList_100)},
    {MultichoiceList_101, ARRAY_COUNT(MultichoiceList_101)},
    {MultichoiceList_102, ARRAY_COUNT(MultichoiceList_102)},
    {MultichoiceList_103, ARRAY_COUNT(MultichoiceList_103)},
    {MultichoiceList_104, ARRAY_COUNT(MultichoiceList_104)},
    {MultichoiceList_105, ARRAY_COUNT(MultichoiceList_105)},
    {MultichoiceList_106, ARRAY_COUNT(MultichoiceList_106)},
    {MultichoiceList_107, ARRAY_COUNT(MultichoiceList_107)},
    {MultichoiceList_108, ARRAY_COUNT(MultichoiceList_108)},
    {MultichoiceList_109, ARRAY_COUNT(MultichoiceList_109)},
    {MultichoiceList_110, ARRAY_COUNT(MultichoiceList_110)},
    {MultichoiceList_111, ARRAY_COUNT(MultichoiceList_111)},
    {MultichoiceList_112, ARRAY_COUNT(MultichoiceList_112)},
    {MultichoiceList_113, ARRAY_COUNT(MultichoiceList_113)},
};

const u8 *const gUnknown_0858BAF0[] =
{
    gText_Cool,
    gText_Beauty,
    gText_Cute,
    gText_Smart,
    gText_Tough,
    gText_Normal,
    gText_Super,
    gText_Hyper,
    gText_Master,
    gText_Cool2,
    gText_Beauty2,
    gText_Cute2,
    gText_Smart2,
    gText_Tough2,
    gText_Items,
    gText_Key_Items,
    gText_Poke_Balls,
    gText_TMs_Hms,
    gText_Berries2,
    gText_Single2,
    gText_Double2,
    gText_Multi,
    gText_MultiLink,
    gText_BattleTower2,
    gText_BattleDome,
    gText_BattleFactory,
    gText_BattlePalace,
    gText_BattleArena,
    gText_BattlePike,
    gText_BattlePyramid,
};

const u8 gUnknown_0858BB68[] = { 74, 75, 76, 77, 78, 79 };

const u8 *const sPCNameStrings[] =
{
    gText_SomeonesPC,
    gText_LanettesPC,
    gText_PlayersPC,
    gText_LogOff,
};

const u8 *const gUnknown_0858BB80[] =
{
    gText_SlateportCity,
    gText_BattleFrontier,
    gText_SouthernIsland,
    gText_NavelRock,
    gText_BirthIsland,
    gText_FarawayIsland,
    gText_Exit,
};

const u8 *const gUnknown_0858BB9C[] =
{
    OldaleTown_PokemonCenter_2F_Text_277F1B,
    OldaleTown_PokemonCenter_2F_Text_277F5A,
    OldaleTown_PokemonCenter_2F_Text_277F96,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};
const u8 *const gUnknown_0858BBAC[] =
{
    OldaleTown_PokemonCenter_2F_Text_27879F,
    OldaleTown_PokemonCenter_2F_Text_2787D5,
    OldaleTown_PokemonCenter_2F_Text_278831,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};
const u8 *const gUnknown_0858BBBC[] =
{
    OldaleTown_PokemonCenter_2F_Text_27879F,
    OldaleTown_PokemonCenter_2F_Text_2787D5,
    OldaleTown_PokemonCenter_2F_Text_2787FC,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};
const u8 *const gUnknown_0858BBCC[] =
{
    OldaleTown_PokemonCenter_2F_Text_27879F,
    OldaleTown_PokemonCenter_2F_Text_2787D5,
    OldaleTown_PokemonCenter_2F_Text_278831,
    OldaleTown_PokemonCenter_2F_Text_2787FC,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};
const u8 *const gUnknown_0858BBE0[] =
{
    OldaleTown_PokemonCenter_2F_Text_277F1B,
    OldaleTown_PokemonCenter_2F_Text_277F5A,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};
const u8 *const gUnknown_0858BBEC[] =
{
    OldaleTown_PokemonCenter_2F_Text_27879F,
    OldaleTown_PokemonCenter_2F_Text_2787D5,
    OldaleTown_PokemonCenter_2F_Text_27889C,
};

EWRAM_DATA u8 gUnknown_02039F90 = 0;

IWRAM_DATA u8 gUnknown_03001124[7];
IWRAM_DATA u32 filler_0300112c;

static void Task_HandleMultichoiceInput(u8);
static void Task_HandleYesNoInput(u8);
static void Task_HandleMultichoiceGridInput(u8);
static void DrawMultichoiceMenu(u8, u8, u8, bool8, u8);
static void sub_80E1FBC(u8, u8, u8, u8);
static void sub_80E2A94(u8);
static void CreatePCMenu(void);
static void sub_80E2578(void);
static bool8 IsPicboxClosed(void);
static void CreateStartMenu(void);
static void sub_80E2CC4(u8, u8, u8, u8);

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

static u16 sub_80E1EB8(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == 1)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos)
{
    int i;
    u8 windowId;
    u8 count = gMultichoiceLists[multichoiceId].count;
    const struct MenuAction *actions = gMultichoiceLists[multichoiceId].list;
    int width = 0;
    u8 newWidth;

    for (i = 0; i < count; i++)
    {
        width = display_text_and_get_width(actions[i].text, width);
    }

    newWidth = convert_pixel_width_to_tile_width(width);
    left = sub_80E2D5C(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_80E1FBC(ignoreBPress, count, windowId, multichoiceId);
}

#define tLeft           data[0]
#define tTop            data[1]
#define tRight          data[2]
#define tBottom         data[3]
#define tIgnoreBPress   data[4]
#define tDoWrap         data[5]
#define tWindowId       data[6]
#define tMultichoiceId  data[7]

static void sub_80E1FBC(u8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    gUnknown_02039F90 = 2;

    for (i = 0; i < 6; i++)
    {
        if (gUnknown_0858BB68[i] == multichoiceId)
        {
            gUnknown_02039F90 = 12;
        }
    }

    taskId = CreateTask(Task_HandleMultichoiceInput, 80);

    gTasks[taskId].tIgnoreBPress = ignoreBPress;

    if (count > 3)
        gTasks[taskId].tDoWrap = TRUE;
    else
        gTasks[taskId].tDoWrap = FALSE;

    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;

    sub_80E2A94(multichoiceId);
}

static void Task_HandleMultichoiceInput(u8 taskId)
{
    s8 selection;
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (gUnknown_02039F90)
        {
            gUnknown_02039F90--;
        }
        else
        {
            if (!tDoWrap)
                selection = Menu_ProcessInputNoWrap();
            else
                selection = Menu_ProcessInput();

            if (gMain.newKeys & (DPAD_UP | DPAD_DOWN))
            {
                sub_80E2A94(tMultichoiceId);
            }

            if (selection != MENU_NOTHING_CHOSEN)
            {
                if (selection == MENU_B_PRESSED)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = 127;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                ClearToTransparentAndRemoveWindow(tWindowId);
                DestroyTask(taskId);
                EnableBothScriptContexts();
            }
        }
    }
}

bool8 ScriptMenu_YesNo(u8 left, u8 top)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_HandleYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayYesNoMenuDefaultYes();
        taskId = CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

static void Task_HandleYesNoInput(u8 taskId)
{
    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 columnCount)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 rowCount, newWidth;
        int i, width;

        gSpecialVar_Result = 0xFF;
        width = 0;

        for (i = 0; i < gMultichoiceLists[multichoiceId].count; i++)
        {
            width = display_text_and_get_width(gMultichoiceLists[multichoiceId].list[i].text, width);
        }

        newWidth = convert_pixel_width_to_tile_width(width);

        left = sub_80E2D5C(left, columnCount * newWidth);
        rowCount = gMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, rowCount * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 0);
        PrintMenuGridTable(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, gMultichoiceLists[multichoiceId].list);
        sub_8199944(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, 3);
        return TRUE;
    }
}

static void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessInputGridLayout();

    switch (selection)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tIgnoreBPress)
            return;
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0x7F;
        break;
    default:
        gSpecialVar_Result = selection;
        break;
    }

    ClearToTransparentAndRemoveWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

#undef tWindowId

bool16 ScrSpecial_CreatePCMenu(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreatePCMenu();
        return TRUE;
    }
}

static void CreatePCMenu(void)
{
    u8 y = 8;
    u32 pixelWidth = 0;
    u8 width;
    u8 numChoices;
    u8 windowId;
    int i;

    for (i = 0; i < ARRAY_COUNT(sPCNameStrings); i++)
    {
        pixelWidth = display_text_and_get_width(sPCNameStrings[i], pixelWidth);
    }

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        pixelWidth = display_text_and_get_width(gText_HallOfFame, pixelWidth);
    }

    width = convert_pixel_width_to_tile_width(pixelWidth);

    if (FlagGet(FLAG_SYS_GAME_CLEAR)) // player has cleared game?
    {
        numChoices = 4;
        windowId = CreateWindowFromRect(0, 0, width, 8);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_HallOfFame, y, 33, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 49, TEXT_SPEED_FF, NULL);
    }
    else
    {
        numChoices = 3;
        windowId = CreateWindowFromRect(0, 0, width, 6);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 33, TEXT_SPEED_FF, NULL);
    }

    if (FlagGet(FLAG_SYS_PC_LANETTE)) // player met lanette?
        AddTextPrinterParameterized(windowId, 1, gText_LanettesPC, y, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(windowId, 1, gText_SomeonesPC, y, 1, TEXT_SPEED_FF, NULL);

    StringExpandPlaceholders(gStringVar4, gText_PlayersPC);
    PrintPlayerNameOnWindow(windowId, gStringVar4, y, 17);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, numChoices, 0);
    CopyWindowToVram(windowId, 3);
    sub_80E1FBC(FALSE, numChoices, windowId, 1);
}

void ScriptMenu_DisplayPCStartupPrompt(void)
{
    sub_819786C(0, TRUE);
    AddTextPrinterParameterized2(0, 1, gText_WhichPCShouldBeAccessed, 0, NULL, 2, 1, 3);
}

bool8 sub_80E2548(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        sub_80E2578();
        return TRUE;
    }
}

static void sub_80E2578(void)
{
    u8 temp = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u32 j;

    for (i = 0; i < ARRAY_COUNT(gUnknown_03001124); i++)
    {
        gUnknown_03001124[i] = 0xFF;
    }

    GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);

    if (gSpecialVar_0x8004 == 0)
    {
        gUnknown_03001124[temp] = 0;
        temp++;
        if (FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
        {
            gUnknown_03001124[temp] = 1;
            temp++;
        }
    }

    if (CheckBagHasItem(ITEM_EON_TICKET, 1) == TRUE && FlagGet(FLAG_SYS_HAS_EON_TICKET) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 2;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_EON_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 2;
            temp++;
            FlagSet(FLAG_HAS_EON_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_NAVEL_ROCK) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 3;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_MYSTIC_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 3;
            temp++;
            FlagSet(FLAG_HAS_MYSTIC_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_BIRTH_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 4;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_AURORA_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 4;
            temp++;
            FlagSet(FLAG_HAS_AURORA_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_OLD_SEA_MAP, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_FARAWAY_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 5;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_OLD_SEA_MAP) == FALSE)
        {
            gUnknown_03001124[temp] = 5;
            temp++;
            FlagSet(FLAG_HAS_OLD_SEA_MAP);
        }
    }

    gUnknown_03001124[temp] = 6;
    temp++;

    if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
    {
        count = temp;
    }

    count = temp;
    if (count == 7)
    {
        gSpecialVar_0x8004 = 11;
        sub_813A128();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < ARRAY_COUNT(gUnknown_0858BB80); j++)
        {
            u8 test = gUnknown_03001124[j];
            if (test != 0xFF)
            {
                pixelWidth = display_text_and_get_width(gUnknown_0858BB80[test], pixelWidth);
            }
        }

        width = convert_pixel_width_to_tile_width(pixelWidth);
        windowId = CreateWindowFromRect(28 - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, 0);

        for (temp = 0, i = 0; i < ARRAY_COUNT(gUnknown_0858BB80); i++)
        {
            if (gUnknown_03001124[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, 1, gUnknown_0858BB80[gUnknown_03001124[i]], 8, temp * 16 + 1, TEXT_SPEED_FF, NULL);
                temp++;
            }
        }

        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, count - 1);
        CopyWindowToVram(windowId, 3);
        sub_80E1FBC(FALSE, count, windowId, 8);
    }
}

void sub_80E2878(void)
{
    if (gSpecialVar_Result != 0x7F)
    {
        gSpecialVar_Result = gUnknown_03001124[gSpecialVar_Result];
    }
}

#define tState       data[0]
#define tMonSpecies  data[1]
#define tMonSpriteId data[2]
#define tWindowX     data[3]
#define tWindowY     data[4]
#define tWindowId    data[5]

static void Task_PokemonPicWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y)
{
    u8 taskId;
    u8 spriteId;

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != 0xFF)
    {
        return FALSE;
    }
    else
    {
        spriteId = CreateMonSprite_PicBox(species, x * 8 + 40, y * 8 + 40, 0);
        taskId = CreateTask(Task_PokemonPicWindow, 0x50);
        gTasks[taskId].tWindowId = CreateWindowFromRect(x, y, 8, 8);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tMonSpecies = species;
        gTasks[taskId].tMonSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 1);
        schedule_bg_copy_tilemap_to_vram(0);
        return TRUE;
    }
}

bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);

    if (taskId == 0xFF)
        return NULL;
    gTasks[taskId].tState++;
    return IsPicboxClosed;
}

static bool8 IsPicboxClosed(void)
{
    if (FindTaskIdByFunc(Task_PokemonPicWindow) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

#undef tState
#undef tMonSpecies
#undef tMonSpriteId
#undef tWindowX
#undef tWindowY
#undef tWindowId

u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, width, height, 15, 100);
    u8 windowId = AddWindow(&template);
    PutWindowTilemap(windowId);
    return windowId;
}

void ClearToTransparentAndRemoveWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void sub_80E2A94(u8 multichoiceId)
{
    switch (multichoiceId)
    {
    case 77:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBAC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 76:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BB9C[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 78:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBBC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 79:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBCC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 75:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBEC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 74:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBE0[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    }
}

bool16 sp106_CreateStartMenu(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }

    gSpecialVar_Result = 0xFF;
    CreateStartMenu();
    return TRUE;
}

static void CreateStartMenu(void)
{
    u8 windowId = CreateWindowFromRect(21, 0, 7, 18);
    SetStandardWindowBorderStyle(windowId, 0);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokedex, 8, 9, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokemon, 8, 25, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionBag, 8, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokenav, 8, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gSaveBlock2Ptr->playerName, 8, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionSave, 8, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionOption, 8, 105, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionExit, 8, 121, TEXT_SPEED_FF, NULL);
    sub_81983AC(windowId, 1, 0, 9, 16, 8, 0);
    sub_80E2CC4(0, 8, windowId, 86);
    CopyWindowToVram(windowId, 3);
}

#define tWindowId       data[6]

static void sub_80E2CC4(bool8 ignoreBPress, u8 unused, u8 windowId, u8 multichoiceId)
{
    u8 taskId;
    gUnknown_02039F90 = 2;
    taskId = CreateTask(Task_HandleMultichoiceInput, 80);
    gTasks[taskId].tIgnoreBPress = ignoreBPress;
    gTasks[taskId].tDoWrap = 0;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

static int display_text_and_get_width_internal(const u8 *str)
{
    u8 temp[64];
    StringExpandPlaceholders(temp, str);
    return GetStringWidth(1, temp, 0);
}

int display_text_and_get_width(const u8 *str, int prevMaxWidth)
{
    int len = display_text_and_get_width_internal(str);
    if (len < prevMaxWidth)
    {
        len = prevMaxWidth;
    }
    return len;
}

int convert_pixel_width_to_tile_width(int width)
{
    return (((width + 9) / 8) + 1) > 28 ? 28 : (((width + 9) / 8) + 1);
}

int sub_80E2D5C(int a0, int a1)
{
    int ret = a0;

    if (a0 + a1 > 28)
    {
        if (28 - a1 < 0)
        {
            ret = 0;
        }
        else
        {
            ret = 28 - a1;
        }
    }
    else
    {
        ret = a0;
    }

    return ret;
}
