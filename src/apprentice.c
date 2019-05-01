#include "global.h"
#include "apprentice.h"
#include "battle.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "alloc.h"
#include "menu.h"
#include "new_game.h"
#include "party_menu.h"
#include "random.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "constants/apprentice.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/moves.h"

#define PLAYER_APPRENTICE gSaveBlock2Ptr->playerApprentice

struct Unk030062ECStruct
{
    u8 unk0;
    u16 unk2[3][5];
    u8 unk20[3][5];
};

struct Unk030062F0Struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

// data/scripts/apprentice.inc
extern const u8 gText_082B7229[];
extern const u8 gText_082B731C[];
extern const u8 gText_082B735B[];
extern const u8 gText_082B7423[];
extern const u8 gText_082B74C1[];
extern const u8 gText_082B756F[];
extern const u8 gText_082B75B2[];
extern const u8 gText_082B763F[];
extern const u8 gText_082B76AC[];
extern const u8 gText_082B7772[];
extern const u8 gText_082B77CE[];
extern const u8 gText_082B7871[];
extern const u8 gText_082B78D4[];
extern const u8 gText_082B7B1A[];
extern const u8 gText_082B7C13[];
extern const u8 gText_082B7D18[];
extern const u8 gText_082B7DD4[];
extern const u8 gText_082B7EE5[];
extern const u8 gText_082B7F35[];
extern const u8 gText_082B7FE8[];
extern const u8 gText_082B8087[];
extern const u8 gText_082B822B[];
extern const u8 gText_082B8286[];
extern const u8 gText_082B8356[];
extern const u8 gText_082B83CE[];
extern const u8 gText_082B84FC[];
extern const u8 gText_082B8559[];
extern const u8 gText_082B8656[];
extern const u8 gText_082B86EA[];
extern const u8 gText_082B87DA[];
extern const u8 gText_082B887C[];
extern const u8 gText_082B8957[];
extern const u8 gText_082B89C6[];
extern const u8 gText_082B8ACF[];
extern const u8 gText_082B8B66[];
extern const u8 gText_082B8C20[];
extern const u8 gText_082B8CAA[];
extern const u8 gText_082B8DD3[];
extern const u8 gText_082B8E24[];
extern const u8 gText_082B8ED5[];
extern const u8 gText_082B8F45[];
extern const u8 gText_082B905F[];
extern const u8 gText_082B910E[];
extern const u8 gText_082B9204[];
extern const u8 gText_082B929C[];
extern const u8 gText_082B9438[];
extern const u8 gText_082B9488[];
extern const u8 gText_082B9564[];
extern const u8 gText_082B95D8[];
extern const u8 gText_082B9763[];
extern const u8 gText_082B97E5[];
extern const u8 gText_082B989A[];
extern const u8 gText_082B992D[];
extern const u8 gText_082B9A84[];
extern const u8 gText_082B9AB9[];
extern const u8 gText_082B9B76[];
extern const u8 gText_082B9BF2[];
extern const u8 gText_082B9D83[];
extern const u8 gText_082B9DF9[];
extern const u8 gText_082B9EAA[];
extern const u8 gText_082B9F55[];
extern const u8 gText_082BA084[];
extern const u8 gText_082BA11D[];
extern const u8 gText_082BA1F3[];

extern const u8 gText_082BE50D[];
extern const u8 gText_082BE5F5[];
extern const u8 gText_082BE679[];
extern const u8 gText_082BE71E[];
extern const u8 gText_082BE762[];
extern const u8 gText_082BE7F8[];
extern const u8 gText_082BE850[];
extern const u8 gText_082BE99C[];
extern const u8 gText_082BEA1B[];
extern const u8 gText_082BEAE9[];
extern const u8 gText_082BEB72[];
extern const u8 gText_082BEC8E[];
extern const u8 gText_082BED16[];
extern const u8 gText_082BEE29[];
extern const u8 gText_082BEEB4[];
extern const u8 gText_082BEFE2[];
extern const u8 gText_082BF04E[];
extern const u8 gText_082BF11D[];
extern const u8 gText_082BF1A8[];
extern const u8 gText_082BF268[];
extern const u8 gText_082BF2D1[];
extern const u8 gText_082BF3CF[];
extern const u8 gText_082BF46A[];
extern const u8 gText_082BF551[];
extern const u8 gText_082BF5C3[];
extern const u8 gText_082BF6E5[];
extern const u8 gText_082BF773[];
extern const u8 gText_082BF869[];
extern const u8 gText_082BF8DD[];
extern const u8 gText_082BF9BA[];
extern const u8 gText_082BFA5A[];
extern const u8 gText_082BFB4E[];

extern const u8 gText_082BA2A3[];
extern const u8 gText_082BA34E[];
extern const u8 gText_082BA380[];
extern const u8 gText_082BA3D2[];
extern const u8 gText_082BA448[];
extern const u8 gText_082BA4D3[];
extern const u8 gText_082BA58C[];
extern const u8 gText_082BA5BF[];
extern const u8 gText_082BA5F3[];
extern const u8 gText_082BA635[];
extern const u8 gText_082BA6E6[];
extern const u8 gText_082BA742[];
extern const u8 gText_082BA770[];
extern const u8 gText_082BA78F[];
extern const u8 gText_082BA7D8[];
extern const u8 gText_082BA867[];
extern const u8 gText_082BA96B[];
extern const u8 gText_082BA9B7[];
extern const u8 gText_082BAA1B[];
extern const u8 gText_082BAA81[];
extern const u8 gText_082BAB22[];
extern const u8 gText_082BAC43[];
extern const u8 gText_082BAC78[];
extern const u8 gText_082BAD17[];
extern const u8 gText_082BADB6[];
extern const u8 gText_082BAE36[];
extern const u8 gText_082BAF4E[];
extern const u8 gText_082BAF8F[];
extern const u8 gText_082BAFDB[];
extern const u8 gText_082BB05F[];
extern const u8 gText_082BB0D4[];
extern const u8 gText_082BB18C[];
extern const u8 gText_082BB1CE[];
extern const u8 gText_082BB242[];
extern const u8 gText_082BB2D9[];
extern const u8 gText_082BB370[];
extern const u8 gText_082BB4C3[];
extern const u8 gText_082BB4FB[];
extern const u8 gText_082BB575[];
extern const u8 gText_082BB5E1[];
extern const u8 gText_082BB656[];
extern const u8 gText_082BB6E5[];
extern const u8 gText_082BB72C[];
extern const u8 gText_082BB7A2[];
extern const u8 gText_082BB84A[];
extern const u8 gText_082BB8CD[];
extern const u8 gText_082BB970[];
extern const u8 gText_082BB9AE[];
extern const u8 gText_082BBA05[];
extern const u8 gText_082BBA6C[];
extern const u8 gText_082BBB01[];
extern const u8 gText_082BBC1C[];
extern const u8 gText_082BBC4B[];
extern const u8 gText_082BBCF6[];
extern const u8 gText_082BBD90[];
extern const u8 gText_082BBE0B[];
extern const u8 gText_082BBEE5[];
extern const u8 gText_082BBF25[];
extern const u8 gText_082BBFA4[];
extern const u8 gText_082BC024[];
extern const u8 gText_082BC0C8[];
extern const u8 gText_082BC213[];
extern const u8 gText_082BC247[];
extern const u8 gText_082BC2DD[];
extern const u8 gText_082BC373[];
extern const u8 gText_082BC40E[];
extern const u8 gText_082BC514[];
extern const u8 gText_082BC555[];
extern const u8 gText_082BC5CE[];
extern const u8 gText_082BC666[];
extern const u8 gText_082BC714[];
extern const u8 gText_082BC808[];
extern const u8 gText_082BC84D[];
extern const u8 gText_082BC8EA[];
extern const u8 gText_082BC984[];
extern const u8 gText_082BCA4D[];
extern const u8 gText_082BCB75[];
extern const u8 gText_082BCBA6[];
extern const u8 gText_082BCBFC[];
extern const u8 gText_082BCCA4[];

extern const u8 gText_082BFBF2[];
extern const u8 gText_082BFCAE[];
extern const u8 gText_082BFD26[];
extern const u8 gText_082BFDB1[];
extern const u8 gText_082BFE24[];
extern const u8 gText_082BFEAD[];
extern const u8 gText_082BFF0A[];
extern const u8 gText_082C0032[];
extern const u8 gText_082C0090[];
extern const u8 gText_082C016E[];
extern const u8 gText_082C01F7[];
extern const u8 gText_082C034C[];
extern const u8 gText_082C03CA[];
extern const u8 gText_082C046E[];
extern const u8 gText_082C04F9[];
extern const u8 gText_082C0598[];
extern const u8 gText_082C0602[];
extern const u8 gText_082C06D8[];
extern const u8 gText_082C074A[];
extern const u8 gText_082C0809[];
extern const u8 gText_082C086E[];
extern const u8 gText_082C0982[];
extern const u8 gText_082C0A1D[];
extern const u8 gText_082C0AFD[];
extern const u8 gText_082C0B6F[];
extern const u8 gText_082C0C7D[];
extern const u8 gText_082C0D0B[];
extern const u8 gText_082C0DFE[];
extern const u8 gText_082C0E71[];
extern const u8 gText_082C0F6D[];
extern const u8 gText_082C1003[];
extern const u8 gText_082C1122[];

extern const u8 gText_082BCD68[];
extern const u8 gText_082BCE64[];
extern const u8 gText_082BCEF2[];
extern const u8 gText_082BCF61[];
extern const u8 gText_082BCFA1[];
extern const u8 gText_082BD03C[];
extern const u8 gText_082BD06D[];
extern const u8 gText_082BD18A[];
extern const u8 gText_082BD222[];
extern const u8 gText_082BD325[];
extern const u8 gText_082BD3B1[];
extern const u8 gText_082BD493[];
extern const u8 gText_082BD51C[];
extern const u8 gText_082BD609[];
extern const u8 gText_082BD697[];
extern const u8 gText_082BD797[];
extern const u8 gText_082BD806[];
extern const u8 gText_082BD8F5[];
extern const u8 gText_082BD9BE[];
extern const u8 gText_082BDAE1[];
extern const u8 gText_082BDB4E[];
extern const u8 gText_082BDC6B[];
extern const u8 gText_082BDD0D[];
extern const u8 gText_082BDDEC[];
extern const u8 gText_082BDE68[];
extern const u8 gText_082BDF4D[];
extern const u8 gText_082BDFD8[];
extern const u8 gText_082BE0FD[];
extern const u8 gText_082BE189[];
extern const u8 gText_082BE2A5[];
extern const u8 gText_082BE33E[];
extern const u8 gText_082BE46C[];

extern const u8 gText_082C11D1[];
extern const u8 gText_082C12D5[];
extern const u8 gText_082C13AB[];
extern const u8 gText_082C1444[];
extern const u8 gText_082C1501[];
extern const u8 gText_082C15B6[];
extern const u8 gText_082C165E[];
extern const u8 gText_082C174F[];
extern const u8 gText_082C1862[];
extern const u8 gText_082C19A0[];
extern const u8 gText_082C1A76[];
extern const u8 gText_082C1C16[];
extern const u8 gText_082C1CF5[];
extern const u8 gText_082C1DC1[];
extern const u8 gText_082C1EDC[];
extern const u8 gText_082C1FEC[];
extern const u8 gText_082C20D1[];
extern const u8 gText_082C21FF[];
extern const u8 gText_082C231C[];
extern const u8 gText_082C2407[];
extern const u8 gText_082C24B5[];
extern const u8 gText_082C25B1[];
extern const u8 gText_082C2707[];
extern const u8 gText_082C27D4[];
extern const u8 gText_082C28D6[];
extern const u8 gText_082C2A0B[];
extern const u8 gText_082C2B50[];
extern const u8 gText_082C2C77[];
extern const u8 gText_082C2D67[];
extern const u8 gText_082C2E41[];
extern const u8 gText_082C2EF5[];
extern const u8 gText_082C3023[];

extern const u8 gText_082B6EA5[];
extern const u8 gText_082B6EEC[];
extern const u8 gText_082B6F16[];
extern const u8 gText_082B6F4C[];
extern const u8 gText_082B6F92[];
extern const u8 gText_082B6FC9[];
extern const u8 gText_082B700C[];
extern const u8 gText_082B703A[];
extern const u8 gText_082B706A[];
extern const u8 gText_082B709C[];
extern const u8 gText_082B70CC[];
extern const u8 gText_082B710A[];
extern const u8 gText_082B714D[];
extern const u8 gText_082B7185[];
extern const u8 gText_082B71C1[];
extern const u8 gText_082B71F9[];

// IWRAM common
struct Unk030062ECStruct *gUnknown_030062EC;
struct Unk030062F0Struct *gUnknown_030062F0;
void (*gUnknown_030062F4)(void);

// This file's functions.
static u16 sub_819FF98(u8 arg0);
static bool8 sub_81A0194(u8 arg0, u16 moveId);
static void CreateChooseAnswerTask(bool8 noBButton, u8 itemsCount, u8 windowId);
static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height);
static void RemoveAndHideWindow(u8 windowId);
static void ExecuteFuncAfterButtonPress(void (*func)(void));

static void Script_IsPlayersApprenticeActive(void);
static void Script_SetPlayersApprenticeLvlMode(void);
static void sub_81A0978(void);
static void sub_819FC60(void);
static void sub_81A0984(void);
static void sub_81A0990(void);
static void sub_81A09D0(void);
static void Script_CreateApprenticeMenu(void);
static void Script_PrintMessage(void);
static void Script_ResetPlayerApprentice(void);
static void sub_81A1638(void);
static void sub_81A0CC0(void);
static void sub_81A09B4(void);
static void sub_81A0D40(void);
static void sub_81A0DD4(void);
static void sub_81A0FE4(void);
static void sub_81A0FFC(void);
static void sub_81A0D80(void);
static void sub_81A11F8(void);
static void sub_81A1218(void);
static void sub_81A1224(void);
static void sub_81A1438(void);
static void sub_81A150C(void);
static void Script_SetPlayerApprenticeTrainerGfxId(void);
static void sub_81A1644(void);
static void sub_81A1370(void);

// rodata

const struct ApprenticeTrainer gApprentices[] =
{
    {
        .name = {_("サダヒロ"), _("ALANN"), _("ALAIN"), _("ADELFO"), _("CLAUS"), _("TEO")},
        .otId = 0xBDC9,
        .facilityClass = 0x43,
        .species = {SPECIES_BEAUTIFLY, SPECIES_DUSTOX, SPECIES_ILLUMISE, SPECIES_SHIFTRY, SPECIES_BRELOOM, SPECIES_NINJASK, SPECIES_SHEDINJA, SPECIES_PINSIR, SPECIES_HERACROSS, SPECIES_VOLBEAT},
        .id = 0,
        .easyChatWords = {0x81D, 0x143E, 0xC00, 0xA01, 0x630, 0x1444},
    },
    {
        .name = {_("ヒロオ"), _("LIONEL"), _("LIONEL"), _("CAIO"), _("LUDWIG"), _("LEO")},
        .otId = 0xCF09,
        .facilityClass = 0x2B,
        .species = {SPECIES_SWELLOW, SPECIES_SWALOT, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_TORKOAL, SPECIES_HARIYAMA, SPECIES_MIGHTYENA, SPECIES_LUDICOLO, SPECIES_CRAWDAUNT, SPECIES_WHISCASH},
        .id = 1,
        .easyChatWords = {0xC38, 0xA01, 0x630, 0xA06, 0x1020, 0x2213},
    },
    {
        .name = {_("ケイジ"), _("SONNY"), _("HERVE"), _("FEDRO"), _("WENZEL"), _("SANTI")},
        .otId = 0x2E34,
        .facilityClass = 0x26,
        .species = {SPECIES_LINOONE, SPECIES_MIGHTYENA, SPECIES_WHISCASH, SPECIES_ZANGOOSE, SPECIES_SEVIPER, SPECIES_NINETALES, SPECIES_KECLEON, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_MACHAMP},
        .id = 2,
        .easyChatWords = {0xA01, 0x160A, 0xE15, 0x630, 0xC3B, 0xC04},
    },
    {
        .name = {_("ユラ"), _("LAYLA"), _("LAYLA"), _("ASTRID"), _("SONJA"), _("LOLA")},
        .otId = 0x84EF,
        .facilityClass = 0x47,
        .species = {SPECIES_SWALOT, SPECIES_XATU, SPECIES_ALTARIA, SPECIES_GOLDUCK, SPECIES_FLYGON, SPECIES_ALAKAZAM, SPECIES_GARDEVOIR, SPECIES_WAILORD, SPECIES_GRUMPIG, SPECIES_MIGHTYENA},
        .id = 3,
        .easyChatWords = {0x100B, 0x1E0F, 0x1039, 0x1421, 0xC03, 0xFFFF},
    },
    {
        .name = {_("ヨウカ"), _("MACY"), _("AMELIE"), _("CLEO"), _("MARIA"), _("ELISA")},
        .otId = 0x1E43,
        .facilityClass = 0x27,
        .species = {SPECIES_WIGGLYTUFF, SPECIES_LINOONE, SPECIES_KINGDRA, SPECIES_DELCATTY, SPECIES_RAICHU, SPECIES_FEAROW, SPECIES_STARMIE, SPECIES_MEDICHAM, SPECIES_SHIFTRY, SPECIES_BEAUTIFLY},
        .id = 4,
        .easyChatWords = {0x1E0F, 0x1014, 0x1006, 0x280F, 0x1C1C, 0x1C13},
    },
    {
        .name = {_("ヤスシ"), _("DONTE"), _("BRAHIM"), _("GLAUCO"), _("JOSEF"), _("ROQUE")},
        .otId = 0x379F,
        .facilityClass = 0x30,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_AGGRON, SPECIES_MAGNETON, SPECIES_MACHAMP, SPECIES_ARMALDO, SPECIES_HERACROSS, SPECIES_NOSEPASS, SPECIES_EXPLOUD, SPECIES_MIGHTYENA},
        .id = 5,
        .easyChatWords = {0xA29, 0x1408, 0x102F, 0x1638, 0x820, 0xC00},
    },
    {
        .name = {_("ミサオ"), _("AMIRA"), _("LAURE"), _("DAFNE"), _("AMELIE"), _("LARA")},
        .otId = 0xF555,
        .facilityClass = 0x31,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_MAGNETON, SPECIES_MEDICHAM, SPECIES_MIGHTYENA, SPECIES_GLALIE, SPECIES_GOLEM, SPECIES_ELECTRODE, SPECIES_PELIPPER, SPECIES_SHARPEDO},
        .id = 6,
        .easyChatWords = {0xC0B, 0x123E, 0xC00, 0xA31, 0x1430, 0xC00},
    },
    {
        .name = {_("カズサ"), _("KALI"), _("JODIE"), _("ILENIA"), _("KARO"), _("ELSA")},
        .otId = 0x8D26,
        .facilityClass = 0x14,
        .species = {SPECIES_NINETALES, SPECIES_ALAKAZAM, SPECIES_SCEPTILE, SPECIES_SALAMENCE, SPECIES_GOLDUCK, SPECIES_MAWILE, SPECIES_WEEZING, SPECIES_LANTURN, SPECIES_GARDEVOIR, SPECIES_MILOTIC},
        .id = 7,
        .easyChatWords = {0xA06, 0x620, 0xA1F, 0xA02, 0xC03, 0xFFFF},
    },
    {
        .name = {_("スミレ"), _("ANNIE"), _("ANNIE"), _("IMELDA"), _("INES"), _("ROSA")},
        .otId = 0x800C,
        .facilityClass = 0xD,
        .species = {SPECIES_SCEPTILE, SPECIES_VILEPLUME, SPECIES_BELLOSSOM, SPECIES_ROSELIA, SPECIES_CORSOLA, SPECIES_FLYGON, SPECIES_BRELOOM, SPECIES_MILOTIC, SPECIES_ALTARIA, SPECIES_CRADILY},
        .id = 8,
        .easyChatWords = {0x1E22, 0x433, 0x20E, 0xA02, 0x101E, 0xC00},
    },
    {
        .name = {_("アキノリ"), _("DILLEN"), _("RENE"), _("INDRO"), _("DETLEF"), _("PEDRO")},
        .otId = 0x469f,
        .facilityClass = 0,
        .species = {SPECIES_SKARMORY, SPECIES_GOLEM, SPECIES_BLAZIKEN, SPECIES_CAMERUPT, SPECIES_DONPHAN, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_TROPIUS, SPECIES_SOLROCK, SPECIES_RHYDON},
        .id = 9,
        .easyChatWords = {0xA3D, 0x1011, 0xE1E, 0x201C, 0xC04, 0xFFFF},
    },
    {
        .name = {_("トウゾウ"), _("DALLAS"), _("BRUNO"), _("LEARCO"), _("ANSGAR"), _("MANOLO")},
        .otId = 0x71FC,
        .facilityClass = 0x2D,
        .species = {SPECIES_SEAKING, SPECIES_STARMIE, SPECIES_GOLDUCK, SPECIES_TENTACRUEL, SPECIES_OCTILLERY, SPECIES_GOREBYSS, SPECIES_GLALIE, SPECIES_WAILORD, SPECIES_SHARPEDO, SPECIES_KINGDRA},
        .id = 10,
        .easyChatWords = {0xA05, 0x606, 0x160E, 0xA14, 0xC00, 0xFFFF},
    },
    {
        .name = {_("セイヤ"), _("FRANK"), _("FRANK"), _("OLINDO"), _("FRANK"), _("MAURO")},
        .otId = 0xA39E,
        .facilityClass = 0x3A,
        .species = {SPECIES_QUAGSIRE, SPECIES_STARMIE, SPECIES_PELIPPER, SPECIES_CRAWDAUNT, SPECIES_WAILORD, SPECIES_GYARADOS, SPECIES_SWAMPERT, SPECIES_LANTURN, SPECIES_WHISCASH, SPECIES_SHUCKLE},
        .id = 11,
        .easyChatWords = {0x280E, 0x103D, 0x240F, 0xA14, 0x1E23, 0x1024},
    },
    {
        .name = {_("リュウジ"), _("LAMONT"), _("XAV"), _("ORFEO"), _("JÜRGEN"), _("JORGE")},
        .otId = 0xE590,
        .facilityClass = 0x19,
        .species = {SPECIES_ABSOL, SPECIES_CROBAT, SPECIES_EXPLOUD, SPECIES_MAGNETON, SPECIES_SHARPEDO, SPECIES_MANECTRIC, SPECIES_METAGROSS, SPECIES_ELECTRODE, SPECIES_NOSEPASS, SPECIES_WEEZING},
        .id = 12,
        .easyChatWords = {0x1020, 0x62E, 0x100B, 0x1E22, 0x1E0F, 0x100B},
    },
    {
        .name = {_("カツアキ"), _("TYRESE"), _("ANDY"), _("PARIDE"), _("DAVID"), _("CHICHO")},
        .otId = 0xD018,
        .facilityClass = 10,
        .species = {SPECIES_BLAZIKEN, SPECIES_GOLEM, SPECIES_MACHAMP, SPECIES_RHYDON, SPECIES_HARIYAMA, SPECIES_AGGRON, SPECIES_MEDICHAM, SPECIES_ZANGOOSE, SPECIES_VIGOROTH, SPECIES_SLAKING},
        .id = 13,
        .easyChatWords = {0xA29, 0x63A, 0xE15, 0x1435, 0x1034, 0x61E},
    },
    {
        .name = {_("トシミツ"), _("DANTE"), _("DANTE"), _("RAOUL"), _("LOTHAR"), _("PABLO")},
        .otId = 0xBC75,
        .facilityClass = 14,
        .species = {SPECIES_SCEPTILE, SPECIES_SANDSLASH, SPECIES_FLYGON, SPECIES_CLAYDOL, SPECIES_ARMALDO, SPECIES_CROBAT, SPECIES_CRADILY, SPECIES_SOLROCK, SPECIES_LUNATONE, SPECIES_GOLEM},
        .id = 14,
        .easyChatWords = {0xA01, 0x1017, 0x1243, 0x1E22, 0x100B, 0x280F},
    },
    {
        .name = {_("ローウェン"), _("ARTURO"), _("ARTURO"), _("ROMOLO"), _("BRIAN"), _("ARTURO")},
        .otId = 0xFA02,
        .facilityClass = 0x20,
        .species = {SPECIES_ABSOL, SPECIES_MIGHTYENA, SPECIES_ALAKAZAM, SPECIES_BANETTE, SPECIES_NINETALES, SPECIES_CLAYDOL, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_WALREIN, SPECIES_DUSCLOPS},
        .id = 15,
        .easyChatWords = {0x1E0F, 0x1404, 0x102F, 0x1006, 0x1020, 0xE03},
    },
};

static const u8 *const gUnknown_08610EF0[][4] =
{
    {gText_082B7229, gText_082B731C, gText_082B735B, gText_082B7423},
    {gText_082B74C1, gText_082B756F, gText_082B75B2, gText_082B763F},
    {gText_082B76AC, gText_082B7772, gText_082B77CE, gText_082B7871},
    {gText_082B78D4, gText_082B7B1A, gText_082B7C13, gText_082B7D18},
    {gText_082B7DD4, gText_082B7EE5, gText_082B7F35, gText_082B7FE8},
    {gText_082B8087, gText_082B822B, gText_082B8286, gText_082B8356},
    {gText_082B83CE, gText_082B84FC, gText_082B8559, gText_082B8656},
    {gText_082B86EA, gText_082B87DA, gText_082B887C, gText_082B8957},
    {gText_082B89C6, gText_082B8ACF, gText_082B8B66, gText_082B8C20},
    {gText_082B8CAA, gText_082B8DD3, gText_082B8E24, gText_082B8ED5},
    {gText_082B8F45, gText_082B905F, gText_082B910E, gText_082B9204},
    {gText_082B929C, gText_082B9438, gText_082B9488, gText_082B9564},
    {gText_082B95D8, gText_082B9763, gText_082B97E5, gText_082B989A},
    {gText_082B992D, gText_082B9A84, gText_082B9AB9, gText_082B9B76},
    {gText_082B9BF2, gText_082B9D83, gText_082B9DF9, gText_082B9EAA},
    {gText_082B9F55, gText_082BA084, gText_082BA11D, gText_082BA1F3},
};

static const u8 *const gUnknown_08610FF0[][2] =
{
    {gText_082BE50D, gText_082BE5F5},
    {gText_082BE679, gText_082BE71E},
    {gText_082BE762, gText_082BE7F8},
    {gText_082BE850, gText_082BE99C},
    {gText_082BEA1B, gText_082BEAE9},
    {gText_082BEB72, gText_082BEC8E},
    {gText_082BED16, gText_082BEE29},
    {gText_082BEEB4, gText_082BEFE2},
    {gText_082BF04E, gText_082BF11D},
    {gText_082BF1A8, gText_082BF268},
    {gText_082BF2D1, gText_082BF3CF},
    {gText_082BF46A, gText_082BF551},
    {gText_082BF5C3, gText_082BF6E5},
    {gText_082BF773, gText_082BF869},
    {gText_082BF8DD, gText_082BF9BA},
    {gText_082BFA5A, gText_082BFB4E},
};

static const u8 *const gUnknown_08611070[][5] =
{
    {gText_082BA2A3, gText_082BA34E, gText_082BA380, gText_082BA3D2, gText_082BA448},
    {gText_082BA4D3, gText_082BA58C, gText_082BA5BF, gText_082BA5F3, gText_082BA635},
    {gText_082BA6E6, gText_082BA742, gText_082BA770, gText_082BA78F, gText_082BA7D8},
    {gText_082BA867, gText_082BA96B, gText_082BA9B7, gText_082BAA1B, gText_082BAA81},
    {gText_082BAB22, gText_082BAC43, gText_082BAC78, gText_082BAD17, gText_082BADB6},
    {gText_082BAE36, gText_082BAF4E, gText_082BAF8F, gText_082BAFDB, gText_082BB05F},
    {gText_082BB0D4, gText_082BB18C, gText_082BB1CE, gText_082BB242, gText_082BB2D9},
    {gText_082BB370, gText_082BB4C3, gText_082BB4FB, gText_082BB575, gText_082BB5E1},
    {gText_082BB656, gText_082BB6E5, gText_082BB72C, gText_082BB7A2, gText_082BB84A},
    {gText_082BB8CD, gText_082BB970, gText_082BB9AE, gText_082BBA05, gText_082BBA6C},
    {gText_082BBB01, gText_082BBC1C, gText_082BBC4B, gText_082BBCF6, gText_082BBD90},
    {gText_082BBE0B, gText_082BBEE5, gText_082BBF25, gText_082BBFA4, gText_082BC024},
    {gText_082BC0C8, gText_082BC213, gText_082BC247, gText_082BC2DD, gText_082BC373},
    {gText_082BC40E, gText_082BC514, gText_082BC555, gText_082BC5CE, gText_082BC666},
    {gText_082BC714, gText_082BC808, gText_082BC84D, gText_082BC8EA, gText_082BC984},
    {gText_082BCA4D, gText_082BCB75, gText_082BCBA6, gText_082BCBFC, gText_082BCCA4},
};

static const u8 *const gUnknown_086111B0[][2] =
{
    {gText_082BFBF2, gText_082BFCAE},
    {gText_082BFD26, gText_082BFDB1},
    {gText_082BFE24, gText_082BFEAD},
    {gText_082BFF0A, gText_082C0032},
    {gText_082C0090, gText_082C016E},
    {gText_082C01F7, gText_082C034C},
    {gText_082C03CA, gText_082C046E},
    {gText_082C04F9, gText_082C0598},
    {gText_082C0602, gText_082C06D8},
    {gText_082C074A, gText_082C0809},
    {gText_082C086E, gText_082C0982},
    {gText_082C0A1D, gText_082C0AFD},
    {gText_082C0B6F, gText_082C0C7D},
    {gText_082C0D0B, gText_082C0DFE},
    {gText_082C0E71, gText_082C0F6D},
    {gText_082C1003, gText_082C1122},
};

static const u8 *const gUnknown_08611230[][2] =
{
    {gText_082BCD68, gText_082BCE64},
    {gText_082BCEF2, gText_082BCF61},
    {gText_082BCFA1, gText_082BD03C},
    {gText_082BD06D, gText_082BD18A},
    {gText_082BD222, gText_082BD325},
    {gText_082BD3B1, gText_082BD493},
    {gText_082BD51C, gText_082BD609},
    {gText_082BD697, gText_082BD797},
    {gText_082BD806, gText_082BD8F5},
    {gText_082BD9BE, gText_082BDAE1},
    {gText_082BDB4E, gText_082BDC6B},
    {gText_082BDD0D, gText_082BDDEC},
    {gText_082BDE68, gText_082BDF4D},
    {gText_082BDFD8, gText_082BE0FD},
    {gText_082BE189, gText_082BE2A5},
    {gText_082BE33E, gText_082BE46C},
};

static const u8 *const gUnknown_086112B0[][2] =
{
    {gText_082C11D1, gText_082C12D5},
    {gText_082C13AB, gText_082C1444},
    {gText_082C1501, gText_082C15B6},
    {gText_082C165E, gText_082C174F},
    {gText_082C1862, gText_082C19A0},
    {gText_082C1A76, gText_082C1C16},
    {gText_082C1CF5, gText_082C1DC1},
    {gText_082C1EDC, gText_082C1FEC},
    {gText_082C20D1, gText_082C21FF},
    {gText_082C231C, gText_082C2407},
    {gText_082C24B5, gText_082C25B1},
    {gText_082C2707, gText_082C27D4},
    {gText_082C28D6, gText_082C2A0B},
    {gText_082C2B50, gText_082C2C77},
    {gText_082C2D67, gText_082C2E41},
    {gText_082C2EF5, gText_082C3023},
};

static const u8 *const gUnknown_08611330[] =
{
    gText_082B6EA5,
    gText_082B6EEC,
    gText_082B6F16,
    gText_082B6F4C,
    gText_082B6F92,
    gText_082B6FC9,
    gText_082B700C,
    gText_082B703A,
    gText_082B706A,
    gText_082B709C,
    gText_082B70CC,
    gText_082B710A,
    gText_082B714D,
    gText_082B7185,
    gText_082B71C1,
    gText_082B71F9,
};

static const bool8 gUnknown_08611370[MOVES_COUNT] =
{
    [MOVE_NONE] = FALSE,
    [MOVE_POUND] = FALSE,
    [MOVE_KARATE_CHOP] = TRUE,
    [MOVE_DOUBLE_SLAP] = TRUE,
    [MOVE_COMET_PUNCH] = FALSE,
    [MOVE_MEGA_PUNCH] = TRUE,
    [MOVE_PAY_DAY] = FALSE,
    [MOVE_FIRE_PUNCH] = TRUE,
    [MOVE_ICE_PUNCH] = TRUE,
    [MOVE_THUNDER_PUNCH] = TRUE,
    [MOVE_SCRATCH] = FALSE,
    [MOVE_VICE_GRIP] = FALSE,
    [MOVE_GUILLOTINE] = TRUE,
    [MOVE_RAZOR_WIND] = FALSE,
    [MOVE_SWORDS_DANCE] = TRUE,
    [MOVE_CUT] = FALSE,
    [MOVE_GUST] = FALSE,
    [MOVE_WING_ATTACK] = FALSE,
    [MOVE_WHIRLWIND] = TRUE,
    [MOVE_FLY] = TRUE,
    [MOVE_BIND] = TRUE,
    [MOVE_SLAM] = TRUE,
    [MOVE_VINE_WHIP] = FALSE,
    [MOVE_STOMP] = TRUE,
    [MOVE_DOUBLE_KICK] = TRUE,
    [MOVE_MEGA_KICK] = TRUE,
    [MOVE_JUMP_KICK] = TRUE,
    [MOVE_ROLLING_KICK] = TRUE,
    [MOVE_SAND_ATTACK] = TRUE,
    [MOVE_HEADBUTT] = TRUE,
    [MOVE_HORN_ATTACK] = FALSE,
    [MOVE_FURY_ATTACK] = FALSE,
    [MOVE_HORN_DRILL] = TRUE,
    [MOVE_TACKLE] = FALSE,
    [MOVE_BODY_SLAM] = TRUE,
    [MOVE_WRAP] = TRUE,
    [MOVE_TAKE_DOWN] = TRUE,
    [MOVE_THRASH] = TRUE,
    [MOVE_DOUBLE_EDGE] = TRUE,
    [MOVE_TAIL_WHIP] = FALSE,
    [MOVE_POISON_STING] = FALSE,
    [MOVE_TWINEEDLE] = TRUE,
    [MOVE_PIN_MISSILE] = FALSE,
    [MOVE_LEER] = FALSE,
    [MOVE_BITE] = TRUE,
    [MOVE_GROWL] = FALSE,
    [MOVE_ROAR] = TRUE,
    [MOVE_SING] = TRUE,
    [MOVE_SUPERSONIC] = TRUE,
    [MOVE_SONIC_BOOM] = TRUE,
    [MOVE_DISABLE] = TRUE,
    [MOVE_ACID] = FALSE,
    [MOVE_EMBER] = FALSE,
    [MOVE_FLAMETHROWER] = TRUE,
    [MOVE_MIST] = TRUE,
    [MOVE_WATER_GUN] = FALSE,
    [MOVE_HYDRO_PUMP] = TRUE,
    [MOVE_SURF] = TRUE,
    [MOVE_ICE_BEAM] = TRUE,
    [MOVE_BLIZZARD] = TRUE,
    [MOVE_PSYBEAM] = TRUE,
    [MOVE_BUBBLE_BEAM] = FALSE,
    [MOVE_AURORA_BEAM] = FALSE,
    [MOVE_HYPER_BEAM] = TRUE,
    [MOVE_PECK] = FALSE,
    [MOVE_DRILL_PECK] = TRUE,
    [MOVE_SUBMISSION] = TRUE,
    [MOVE_LOW_KICK] = TRUE,
    [MOVE_COUNTER] = TRUE,
    [MOVE_SEISMIC_TOSS] = TRUE,
    [MOVE_STRENGTH] = TRUE,
    [MOVE_ABSORB] = FALSE,
    [MOVE_MEGA_DRAIN] = FALSE,
    [MOVE_LEECH_SEED] = TRUE,
    [MOVE_GROWTH] = TRUE,
    [MOVE_RAZOR_LEAF] = TRUE,
    [MOVE_SOLAR_BEAM] = TRUE,
    [MOVE_POISON_POWDER] = TRUE,
    [MOVE_STUN_SPORE] = TRUE,
    [MOVE_SLEEP_POWDER] = TRUE,
    [MOVE_PETAL_DANCE] = TRUE,
    [MOVE_STRING_SHOT] = FALSE,
    [MOVE_DRAGON_RAGE] = TRUE,
    [MOVE_FIRE_SPIN] = TRUE,
    [MOVE_THUNDER_SHOCK] = FALSE,
    [MOVE_THUNDERBOLT] = TRUE,
    [MOVE_THUNDER_WAVE] = TRUE,
    [MOVE_THUNDER] = TRUE,
    [MOVE_ROCK_THROW] = FALSE,
    [MOVE_EARTHQUAKE] = TRUE,
    [MOVE_FISSURE] = TRUE,
    [MOVE_DIG] = TRUE,
    [MOVE_TOXIC] = TRUE,
    [MOVE_CONFUSION] = FALSE,
    [MOVE_PSYCHIC] = TRUE,
    [MOVE_HYPNOSIS] = TRUE,
    [MOVE_MEDITATE] = TRUE,
    [MOVE_AGILITY] = TRUE,
    [MOVE_QUICK_ATTACK] = TRUE,
    [MOVE_RAGE] = FALSE,
    [MOVE_TELEPORT] = FALSE,
    [MOVE_NIGHT_SHADE] = TRUE,
    [MOVE_MIMIC] = TRUE,
    [MOVE_SCREECH] = TRUE,
    [MOVE_DOUBLE_TEAM] = TRUE,
    [MOVE_RECOVER] = TRUE,
    [MOVE_HARDEN] = TRUE,
    [MOVE_MINIMIZE] = TRUE,
    [MOVE_SMOKESCREEN] = TRUE,
    [MOVE_CONFUSE_RAY] = TRUE,
    [MOVE_WITHDRAW] = TRUE,
    [MOVE_DEFENSE_CURL] = TRUE,
    [MOVE_BARRIER] = TRUE,
    [MOVE_LIGHT_SCREEN] = TRUE,
    [MOVE_HAZE] = TRUE,
    [MOVE_REFLECT] = TRUE,
    [MOVE_FOCUS_ENERGY] = TRUE,
    [MOVE_BIDE] = FALSE,
    [MOVE_METRONOME] = TRUE,
    [MOVE_MIRROR_MOVE] = TRUE,
    [MOVE_SELF_DESTRUCT] = TRUE,
    [MOVE_EGG_BOMB] = TRUE,
    [MOVE_LICK] = TRUE,
    [MOVE_SMOG] = FALSE,
    [MOVE_SLUDGE] = FALSE,
    [MOVE_BONE_CLUB] = FALSE,
    [MOVE_FIRE_BLAST] = TRUE,
    [MOVE_WATERFALL] = TRUE,
    [MOVE_CLAMP] = TRUE,
    [MOVE_SWIFT] = TRUE,
    [MOVE_SKULL_BASH] = TRUE,
    [MOVE_SPIKE_CANNON] = FALSE,
    [MOVE_CONSTRICT] = FALSE,
    [MOVE_AMNESIA] = TRUE,
    [MOVE_KINESIS] = TRUE,
    [MOVE_SOFT_BOILED] = TRUE,
    [MOVE_HI_JUMP_KICK] = TRUE,
    [MOVE_GLARE] = TRUE,
    [MOVE_DREAM_EATER] = TRUE,
    [MOVE_POISON_GAS] = FALSE,
    [MOVE_BARRAGE] = FALSE,
    [MOVE_LEECH_LIFE] = FALSE,
    [MOVE_LOVELY_KISS] = TRUE,
    [MOVE_SKY_ATTACK] = TRUE,
    [MOVE_TRANSFORM] = TRUE,
    [MOVE_BUBBLE] = FALSE,
    [MOVE_DIZZY_PUNCH] = TRUE,
    [MOVE_SPORE] = TRUE,
    [MOVE_FLASH] = TRUE,
    [MOVE_PSYWAVE] = TRUE,
    [MOVE_SPLASH] = FALSE,
    [MOVE_ACID_ARMOR] = TRUE,
    [MOVE_CRABHAMMER] = TRUE,
    [MOVE_EXPLOSION] = TRUE,
    [MOVE_FURY_SWIPES] = FALSE,
    [MOVE_BONEMERANG] = TRUE,
    [MOVE_REST] = TRUE,
    [MOVE_ROCK_SLIDE] = TRUE,
    [MOVE_HYPER_FANG] = TRUE,
    [MOVE_SHARPEN] = TRUE,
    [MOVE_CONVERSION] = TRUE,
    [MOVE_TRI_ATTACK] = TRUE,
    [MOVE_SUPER_FANG] = TRUE,
    [MOVE_SLASH] = TRUE,
    [MOVE_SUBSTITUTE] = TRUE,
    [MOVE_STRUGGLE] = TRUE,
    [MOVE_SKETCH] = TRUE,
    [MOVE_TRIPLE_KICK] = TRUE,
    [MOVE_THIEF] = TRUE,
    [MOVE_SPIDER_WEB] = TRUE,
    [MOVE_MIND_READER] = TRUE,
    [MOVE_NIGHTMARE] = TRUE,
    [MOVE_FLAME_WHEEL] = FALSE,
    [MOVE_SNORE] = TRUE,
    [MOVE_CURSE] = TRUE,
    [MOVE_FLAIL] = TRUE,
    [MOVE_CONVERSION_2] = TRUE,
    [MOVE_AEROBLAST] = TRUE,
    [MOVE_COTTON_SPORE] = TRUE,
    [MOVE_REVERSAL] = TRUE,
    [MOVE_SPITE] = TRUE,
    [MOVE_POWDER_SNOW] = FALSE,
    [MOVE_PROTECT] = TRUE,
    [MOVE_MACH_PUNCH] = TRUE,
    [MOVE_SCARY_FACE] = TRUE,
    [MOVE_FAINT_ATTACK] = TRUE,
    [MOVE_SWEET_KISS] = TRUE,
    [MOVE_BELLY_DRUM] = TRUE,
    [MOVE_SLUDGE_BOMB] = TRUE,
    [MOVE_MUD_SLAP] = TRUE,
    [MOVE_OCTAZOOKA] = TRUE,
    [MOVE_SPIKES] = TRUE,
    [MOVE_ZAP_CANNON] = TRUE,
    [MOVE_FORESIGHT] = TRUE,
    [MOVE_DESTINY_BOND] = TRUE,
    [MOVE_PERISH_SONG] = TRUE,
    [MOVE_ICY_WIND] = TRUE,
    [MOVE_DETECT] = TRUE,
    [MOVE_BONE_RUSH] = FALSE,
    [MOVE_LOCK_ON] = TRUE,
    [MOVE_OUTRAGE] = TRUE,
    [MOVE_SANDSTORM] = TRUE,
    [MOVE_GIGA_DRAIN] = TRUE,
    [MOVE_ENDURE] = TRUE,
    [MOVE_CHARM] = TRUE,
    [MOVE_ROLLOUT] = TRUE,
    [MOVE_FALSE_SWIPE] = TRUE,
    [MOVE_SWAGGER] = TRUE,
    [MOVE_MILK_DRINK] = TRUE,
    [MOVE_SPARK] = FALSE,
    [MOVE_FURY_CUTTER] = TRUE,
    [MOVE_STEEL_WING] = TRUE,
    [MOVE_MEAN_LOOK] = TRUE,
    [MOVE_ATTRACT] = TRUE,
    [MOVE_SLEEP_TALK] = TRUE,
    [MOVE_HEAL_BELL] = TRUE,
    [MOVE_RETURN] = TRUE,
    [MOVE_PRESENT] = TRUE,
    [MOVE_FRUSTRATION] = TRUE,
    [MOVE_SAFEGUARD] = TRUE,
    [MOVE_PAIN_SPLIT] = TRUE,
    [MOVE_SACRED_FIRE] = TRUE,
    [MOVE_MAGNITUDE] = FALSE,
    [MOVE_DYNAMIC_PUNCH] = TRUE,
    [MOVE_MEGAHORN] = TRUE,
    [MOVE_DRAGON_BREATH] = TRUE,
    [MOVE_BATON_PASS] = TRUE,
    [MOVE_ENCORE] = TRUE,
    [MOVE_PURSUIT] = TRUE,
    [MOVE_RAPID_SPIN] = TRUE,
    [MOVE_SWEET_SCENT] = TRUE,
    [MOVE_IRON_TAIL] = TRUE,
    [MOVE_METAL_CLAW] = TRUE,
    [MOVE_VITAL_THROW] = TRUE,
    [MOVE_MORNING_SUN] = TRUE,
    [MOVE_SYNTHESIS] = TRUE,
    [MOVE_MOONLIGHT] = TRUE,
    [MOVE_HIDDEN_POWER] = TRUE,
    [MOVE_CROSS_CHOP] = TRUE,
    [MOVE_TWISTER] = FALSE,
    [MOVE_RAIN_DANCE] = TRUE,
    [MOVE_SUNNY_DAY] = TRUE,
    [MOVE_CRUNCH] = TRUE,
    [MOVE_MIRROR_COAT] = TRUE,
    [MOVE_PSYCH_UP] = TRUE,
    [MOVE_EXTREME_SPEED] = TRUE,
    [MOVE_ANCIENT_POWER] = TRUE,
    [MOVE_SHADOW_BALL] = TRUE,
    [MOVE_FUTURE_SIGHT] = TRUE,
    [MOVE_ROCK_SMASH] = TRUE,
    [MOVE_WHIRLPOOL] = TRUE,
    [MOVE_BEAT_UP] = TRUE,
    [MOVE_FAKE_OUT] = TRUE,
    [MOVE_UPROAR] = TRUE,
    [MOVE_STOCKPILE] = TRUE,
    [MOVE_SPIT_UP] = TRUE,
    [MOVE_SWALLOW] = TRUE,
    [MOVE_HEAT_WAVE] = TRUE,
    [MOVE_HAIL] = TRUE,
    [MOVE_TORMENT] = TRUE,
    [MOVE_FLATTER] = TRUE,
    [MOVE_WILL_O_WISP] = TRUE,
    [MOVE_MEMENTO] = TRUE,
    [MOVE_FACADE] = TRUE,
    [MOVE_FOCUS_PUNCH] = TRUE,
    [MOVE_SMELLING_SALT] = TRUE,
    [MOVE_FOLLOW_ME] = TRUE,
    [MOVE_NATURE_POWER] = TRUE,
    [MOVE_CHARGE] = TRUE,
    [MOVE_TAUNT] = TRUE,
    [MOVE_HELPING_HAND] = TRUE,
    [MOVE_TRICK] = TRUE,
    [MOVE_ROLE_PLAY] = TRUE,
    [MOVE_WISH] = TRUE,
    [MOVE_ASSIST] = TRUE,
    [MOVE_INGRAIN] = TRUE,
    [MOVE_SUPERPOWER] = TRUE,
    [MOVE_MAGIC_COAT] = TRUE,
    [MOVE_RECYCLE] = TRUE,
    [MOVE_REVENGE] = TRUE,
    [MOVE_BRICK_BREAK] = TRUE,
    [MOVE_YAWN] = TRUE,
    [MOVE_KNOCK_OFF] = TRUE,
    [MOVE_ENDEAVOR] = TRUE,
    [MOVE_ERUPTION] = TRUE,
    [MOVE_SKILL_SWAP] = TRUE,
    [MOVE_IMPRISON] = TRUE,
    [MOVE_REFRESH] = TRUE,
    [MOVE_GRUDGE] = TRUE,
    [MOVE_SNATCH] = TRUE,
    [MOVE_SECRET_POWER] = TRUE,
    [MOVE_DIVE] = TRUE,
    [MOVE_ARM_THRUST] = FALSE,
    [MOVE_CAMOUFLAGE] = TRUE,
    [MOVE_TAIL_GLOW] = TRUE,
    [MOVE_LUSTER_PURGE] = TRUE,
    [MOVE_MIST_BALL] = TRUE,
    [MOVE_FEATHER_DANCE] = TRUE,
    [MOVE_TEETER_DANCE] = TRUE,
    [MOVE_BLAZE_KICK] = TRUE,
    [MOVE_MUD_SPORT] = TRUE,
    [MOVE_ICE_BALL] = FALSE,
    [MOVE_NEEDLE_ARM] = TRUE,
    [MOVE_SLACK_OFF] = TRUE,
    [MOVE_HYPER_VOICE] = TRUE,
    [MOVE_POISON_FANG] = FALSE,
    [MOVE_CRUSH_CLAW] = TRUE,
    [MOVE_BLAST_BURN] = TRUE,
    [MOVE_HYDRO_CANNON] = TRUE,
    [MOVE_METEOR_MASH] = TRUE,
    [MOVE_ASTONISH] = TRUE,
    [MOVE_WEATHER_BALL] = TRUE,
    [MOVE_AROMATHERAPY] = TRUE,
    [MOVE_FAKE_TEARS] = TRUE,
    [MOVE_AIR_CUTTER] = TRUE,
    [MOVE_OVERHEAT] = TRUE,
    [MOVE_ODOR_SLEUTH] = TRUE,
    [MOVE_ROCK_TOMB] = TRUE,
    [MOVE_SILVER_WIND] = TRUE,
    [MOVE_METAL_SOUND] = TRUE,
    [MOVE_GRASS_WHISTLE] = TRUE,
    [MOVE_TICKLE] = TRUE,
    [MOVE_COSMIC_POWER] = TRUE,
    [MOVE_WATER_SPOUT] = TRUE,
    [MOVE_SIGNAL_BEAM] = TRUE,
    [MOVE_SHADOW_PUNCH] = TRUE,
    [MOVE_EXTRASENSORY] = TRUE,
    [MOVE_SKY_UPPERCUT] = TRUE,
    [MOVE_SAND_TOMB] = TRUE,
    [MOVE_SHEER_COLD] = TRUE,
    [MOVE_MUDDY_WATER] = TRUE,
    [MOVE_BULLET_SEED] = FALSE,
    [MOVE_AERIAL_ACE] = TRUE,
    [MOVE_ICICLE_SPEAR] = FALSE,
    [MOVE_IRON_DEFENSE] = TRUE,
    [MOVE_BLOCK] = TRUE,
    [MOVE_HOWL] = TRUE,
    [MOVE_DRAGON_CLAW] = TRUE,
    [MOVE_FRENZY_PLANT] = TRUE,
    [MOVE_BULK_UP] = TRUE,
    [MOVE_BOUNCE] = TRUE,
    [MOVE_MUD_SHOT] = FALSE,
    [MOVE_POISON_TAIL] = TRUE,
    [MOVE_COVET] = TRUE,
    [MOVE_VOLT_TACKLE] = TRUE,
    [MOVE_MAGICAL_LEAF] = TRUE,
    [MOVE_WATER_SPORT] = TRUE,
    [MOVE_CALM_MIND] = TRUE,
    [MOVE_LEAF_BLADE] = TRUE,
    [MOVE_DRAGON_DANCE] = TRUE,
    [MOVE_ROCK_BLAST] = FALSE,
    [MOVE_SHOCK_WAVE] = TRUE,
    [MOVE_WATER_PULSE] = TRUE,
    [MOVE_DOOM_DESIRE] = TRUE,
    [MOVE_PSYCHO_BOOST] = TRUE,
};

static const u8 gUnknown_086114D3[] = {0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00};

static void (* const sApprenticeFunctions[])(void) =
{
    Script_IsPlayersApprenticeActive,
    Script_SetPlayersApprenticeLvlMode,
    sub_81A0978,
    sub_819FC60,
    sub_81A0984,
    sub_81A0990,
    sub_81A09D0,
    Script_CreateApprenticeMenu,
    Script_PrintMessage,
    Script_ResetPlayerApprentice,
    sub_81A1638,
    sub_81A0CC0,
    sub_81A09B4,
    sub_81A0D40,
    sub_81A0DD4,
    sub_81A0FE4,
    sub_81A0FFC,
    sub_81A0D80,
    sub_81A11F8,
    sub_81A1218,
    sub_81A1224,
    sub_81A1438,
    sub_81A150C,
    Script_SetPlayerApprenticeTrainerGfxId,
    sub_81A1644,
    sub_81A1370,
};

static const u8 gUnknown_08611548[8] = {0x00, 0x01, 0x02, 0x03, 0x06, 0x07, 0x08, 0x09};

// text
extern const u8 gText_Give[];
extern const u8 gText_NoNeed[];
extern const u8 gText_Yes[];
extern const u8 gText_No[];

void CopyFriendsApprenticeChallengeText(u8 saveblockApprenticeId)
{
    u8 i, var;
    const u8 *str;

    var = gSaveBlock2Ptr->apprentices[saveblockApprenticeId].number;
    for (i = 0; var != 0 && i < 4; var /= 10, i++)
        ;

    StringCopy7(gStringVar1, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].playerName);
    ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].language);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].number, STR_CONV_MODE_RIGHT_ALIGN, i);
    str = gUnknown_08611330[gSaveBlock2Ptr->apprentices[saveblockApprenticeId].id];
    StringExpandPlaceholders(gStringVar4, str);
}

void Apprentice_EnableBothScriptContexts(void)
{
    EnableBothScriptContexts();
}

void ResetApprenticeStruct(struct Apprentice *apprentice)
{
    u8 i;

    for (i = 0; i < 6; i++)
        apprentice->easyChatWords[i] = 0xFFFF;

    apprentice->playerName[0] = EOS;
    apprentice->id = 16;
}

void ResetAllApprenticeData(void)
{
    u8 i, j;

    PLAYER_APPRENTICE.field_B2_1 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->apprentices[i].easyChatWords[j] = 0xFFFF;
        gSaveBlock2Ptr->apprentices[i].id = 16;
        gSaveBlock2Ptr->apprentices[i].playerName[0] = EOS;
        gSaveBlock2Ptr->apprentices[i].lvlMode = 0;
        gSaveBlock2Ptr->apprentices[i].number = 0;
        gSaveBlock2Ptr->apprentices[i].field_1 = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->apprentices[i].playerId[j] = 0;
        gSaveBlock2Ptr->apprentices[i].language = gGameLanguage;
        gSaveBlock2Ptr->apprentices[i].checksum = 0;
    }

    Script_ResetPlayerApprentice();
}

static bool8 IsPlayersApprenticeActive(void)
{
    return (PLAYER_APPRENTICE.activeLvlMode != 0);
}

static void sub_819FBC8(void)
{
    if (gSaveBlock2Ptr->apprentices[0].number == 0)
    {
        do
        {
            PLAYER_APPRENTICE.id = gUnknown_08611548[Random() % ARRAY_COUNT(gUnknown_08611548)];
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
    else
    {
        do
        {
            PLAYER_APPRENTICE.id = Random() % 16;
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
}

static void SetPlayersApprenticeLvlMode(u8 mode)
{
    PLAYER_APPRENTICE.activeLvlMode = mode;
}

static void sub_819FC60(void)
{
    u8 array[APPRENTICE_SPECIES_COUNT];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(array); i++)
        array[i] = i;

    for (i = 0; i < 50; i++)
    {
        u8 temp;
        u8 var1 = Random() % ARRAY_COUNT(array);
        u8 var2 = Random() % ARRAY_COUNT(array);
        SWAP(array[var1], array[var2], temp);
    }

    for (i = 0; i < 3; i++)
        PLAYER_APPRENTICE.monIds[i] = ((array[i * 2] & 0xF) << 4) | ((array[i * 2 + 1]) & 0xF);
}

static u8 sub_819FCF8(u8 val, u8 *arg1, u8 *arg2)
{
    u8 i, count;
    u8 ret = 0;

    if (val == 2)
    {
        do
        {
            ret = Random() % 3;
            for (count = 0, i = 0; i < 5; i++)
            {
                if (gUnknown_030062EC->unk2[ret][i] != 0)
                    count++;
            }
        } while (count > 3);
    }
    else if (val == 1)
    {
        ret = arg1[*arg2];
        (*arg2)++;
    }

    return ret;
}

static void sub_819FD64(void)
{
    u8 sp_0[10];
    u8 sp_C[3];
    u8 sp_10;
    u8 i, j;
    u8 rand1, rand2;
    u8 id;

    for (i = 0; i < 3; i++)
        sp_C[i] = i;
    for (i = 0; i < 10; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(sp_C);
        rand2 = Random() % ARRAY_COUNT(sp_C);
        SWAP(sp_C[rand1], sp_C[rand2], temp);
    }

    for (i = 0; i < 10; i++)
        sp_0[i] = gUnknown_086114D3[i];
    for (i = 0; i < 50; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(sp_0);
        rand2 = Random() % ARRAY_COUNT(sp_0);
        SWAP(sp_0[rand1], sp_0[rand2], temp);
    }

    gUnknown_030062EC = AllocZeroed(sizeof(*gUnknown_030062EC));
    gUnknown_030062EC->unk0 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
            gUnknown_030062EC->unk20[j][i] = 4;
    }

    sp_10 = 0;
    for (i = 0; i < 9; i++)
    {
        PLAYER_APPRENTICE.field_B8[i].unk0_0 = sp_0[i];
        if (sp_0[i] != 3)
        {
            PLAYER_APPRENTICE.field_B8[i].unk0_1 = sub_819FCF8(sp_0[i], sp_C, &sp_10);
            id = PLAYER_APPRENTICE.field_B8[i].unk0_1;
            if (sp_0[i] == 2)
            {
                do
                {
                    rand1 = Random() % 4;
                    for (j = 0; j < gUnknown_030062EC->unk0 + 1; j++)
                    {
                        if (gUnknown_030062EC->unk20[id][j] == rand1)
                            break;
                    }
                } while (j != gUnknown_030062EC->unk0 + 1);

                gUnknown_030062EC->unk20[id][gUnknown_030062EC->unk0] = rand1;
                PLAYER_APPRENTICE.field_B8[i].unk0_2 = rand1;
                PLAYER_APPRENTICE.field_B8[i].unk2 = sub_819FF98(PLAYER_APPRENTICE.field_B8[i].unk0_1);
            }
        }
    }

    FREE_AND_SET_NULL(gUnknown_030062EC);
}

// No idea why a do-while loop is needed, but it will not match without it.

#define APPRENTICE_SPECIES_ID(speciesArrId, monId) speciesArrId = (PLAYER_APPRENTICE.monIds[monId] >> \
                                                                  (((PLAYER_APPRENTICE.field_B2_0 >> monId) & 1) << 2)) & 0xF; \
                                                   do {} while (0)

// Why the need to have two macros do the exact thing differently?
#define APPRENTICE_SPECIES_ID_2(speciesArrId, monId) {  u8 a0 = ((PLAYER_APPRENTICE.field_B2_0 >> monId) & 1);\
                                                        speciesArrId = PLAYER_APPRENTICE.monIds[monId];     \
                                                        speciesArrId = ((speciesArrId) >> (a0 << 2)) & 0xF; \
                                                     }

static u16 sub_819FF98(u8 arg0)
{
    u8 i, j;
    u8 id;
    u8 knownMovesCount;
    u16 species;
    const struct LevelUpMove *learnset;
    bool32 var_24 = FALSE;
    u16 moveId = 0;
    bool32 valid;
    u8 level;

    if (arg0 < 3)
    {
        APPRENTICE_SPECIES_ID(id, arg0);
    }
    else
    {
        id = 0;
    }

    species = gApprentices[PLAYER_APPRENTICE.id].species[id];
    learnset = gLevelUpLearnsets[species];
    j = 0;
    if (PLAYER_APPRENTICE.activeLvlMode == 1)
        level = 50;
    else
        level = 60;

    for (j = 0; learnset[j].move != 0xFFFF; j++)
    {
        if (learnset[j].level > level)
            break;
    }

    knownMovesCount = j;
    i = 0;
    while (i <= MAX_MON_MOVES)
    {
        if (Random() % 2 == 0 || var_24 == TRUE)
        {
            do
            {
                do
                {
                    id = Random() % (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES);
                    valid = CanSpeciesLearnTMHM(species, id);
                }
                while (!valid);

                moveId = ItemIdToBattleMoveId(ITEM_TM01 + id);
                valid = TRUE;

                if (knownMovesCount < 5)
                    j = 0;
                else
                    j = knownMovesCount - MAX_MON_MOVES;

                for (; j < knownMovesCount; j++)
                {
                    if ((learnset[j].move) == moveId)
                    {
                        valid = FALSE;
                        break;
                    }
                }
            } while (valid != TRUE);
        }
        else
        {
            if (knownMovesCount <= MAX_MON_MOVES)
            {
                var_24 = TRUE;
                continue;
            }
            else
            {
                do
                {
                    u8 learnsetId = Random() % (knownMovesCount - 4);
                    moveId = learnset[learnsetId].move;
                    valid = TRUE;
                    for (j = knownMovesCount - MAX_MON_MOVES; j < knownMovesCount; j++)
                    {
                        if ((learnset[j].move) == moveId)
                        {
                            valid = FALSE;
                            break;
                        }
                    }
                } while (valid != TRUE);
            }
        }

        if (sub_81A0194(arg0, moveId))
        {
            if (gUnknown_08611370[moveId])
                break;
            i++;
        }
    }

    gUnknown_030062EC->unk0++;
    return moveId;
}

static bool8 sub_81A0194(u8 arg0, u16 moveId)
{
    u8 i;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_030062EC->unk2[arg0][i] == moveId)
            return FALSE;
    }

    gUnknown_030062EC->unk2[arg0][gUnknown_030062EC->unk0] = moveId;
    return TRUE;
}

static void GetLatestLearnedMoves(u16 species, u16 *moves)
{
    u8 i, j;
    u8 level, knownMovesCount;
    const struct LevelUpMove *learnset;

    if (PLAYER_APPRENTICE.activeLvlMode == 1)
        level = 50;
    else
        level = 60;

    learnset = gLevelUpLearnsets[species];
    for (i = 0; learnset[i].move != 0xFFFF; i++)
    {
        if ((learnset[i].level) > (level))
            break;
    }

    knownMovesCount = i;
    if (knownMovesCount > MAX_MON_MOVES)
        knownMovesCount = MAX_MON_MOVES;

    for (j = 0; j < knownMovesCount; j++)
        moves[j] = learnset[(i - 1) - j].move;
}

static u16 sub_81A0284(u8 arg0, u8 speciesTableId, u8 arg2)
{
    u16 moves[4];
    u8 i, count;

    if (PLAYER_APPRENTICE.field_B1_1 < 3)
        return 0;

    count = 0;
    for (i = 0; i < 9; i++)
    {
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 0)
            break;
        count++;
    }

    GetLatestLearnedMoves(gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId], moves);
    for (i = 0; i < count && i < PLAYER_APPRENTICE.field_B1_1 - 3; i++)
    {
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 2
            && PLAYER_APPRENTICE.field_B8[i].unk0_1 == arg0
            && PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
        {
            moves[PLAYER_APPRENTICE.field_B8[i].unk0_2] = PLAYER_APPRENTICE.field_B8[i].unk2;
        }
    }

    return moves[arg2];
}

static void sub_81A0390(u8 arg0)
{
    struct ApprenticeMon *apprenticeMons[3];
    u8 i, j;
    u32 speciesTableId;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->apprentices[0].party[i].species = 0;
        gSaveBlock2Ptr->apprentices[0].party[i].item = 0;
        for (j = 0; j < MAX_MON_MOVES; j++)
            gSaveBlock2Ptr->apprentices[0].party[i].moves[j] = 0;
    }

    j = PLAYER_APPRENTICE.field_B1_2;
    for (i = 0; i < 3; i++)
    {
        apprenticeMons[j] = &gSaveBlock2Ptr->apprentices[0].party[i];
        j = (j + 1) % 3;
    }

    for (i = 0; i < 3; i++)
    {
        APPRENTICE_SPECIES_ID(speciesTableId, i);
        apprenticeMons[i]->species = gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
        GetLatestLearnedMoves(apprenticeMons[i]->species, apprenticeMons[i]->moves);
    }

    for (i = 0; i < arg0; i++)
    {
        u8 var1 = PLAYER_APPRENTICE.field_B8[i].unk0_0;
        u8 monId = PLAYER_APPRENTICE.field_B8[i].unk0_1;
        if (var1 == 1)
        {
            if (PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
                apprenticeMons[monId]->item = PLAYER_APPRENTICE.field_B8[i].unk2;
        }
        else if (var1 == 2)
        {
            if (PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
            {
                u32 moveSlot = PLAYER_APPRENTICE.field_B8[i].unk0_2;
                apprenticeMons[monId]->moves[moveSlot] = PLAYER_APPRENTICE.field_B8[i].unk2;
            }
        }
    }
}

static void CreateMenuWithAnswers(u8 arg0)
{
    u8 i;
    u8 windowId;
    const u8 *strings[3];
    u8 count = 2;
    u8 width;
    u8 left;
    u8 top;
    s32 pixelWidth;

    switch (arg0)
    {
    case APPRENTICE_ASK_WHICH_LEVEL:
        left = 0x12;
        top = 8;
        strings[0] = gText_Lv50;
        strings[1] = gText_OpenLevel;
        break;
    case APPRENTICE_ASK_3SPECIES:
        count = 3;
        left = 0x12;
        top = 6;
        for (i = 0; i < 3; i++)
        {
            u16 species;
            u32 speciesTableId;

            APPRENTICE_SPECIES_ID(speciesTableId, i);
            species =  gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
            strings[i] = gSpeciesNames[species];
        }
        break;
    case APPRENTICE_ASK_2SPECIES:
        left = 0x12;
        top = 8;
        if (PLAYER_APPRENTICE.field_B1_1 > 2)
            return;
        strings[1] = gSpeciesNames[gUnknown_030062F0->unk2];
        strings[0] = gSpeciesNames[gUnknown_030062F0->unk0];
        break;
    case APPRENTICE_ASK_MOVES:
        left = 0x11;
        top = 8;
        strings[0] = gMoveNames[gUnknown_030062F0->unk4];
        strings[1] = gMoveNames[gUnknown_030062F0->unk6];
        break;
    case APPRENTICE_ASK_GIVE:
        left = 0x12;
        top = 8;
        strings[0] = gText_Give;
        strings[1] = gText_NoNeed;
        break;
    case APPRENTICE_ASK_YES_NO:
        left = 0x14;
        top = 8;
        strings[0] = gText_Yes;
        strings[1] = gText_No;
        break;
    default:
        left = 0;
        top = 0;
        break;
    }

    pixelWidth = 0;
    for (i = 0; i < count; i++)
    {
        s32 width = GetStringWidth(1, strings[i], 0);
        if (width > pixelWidth)
            pixelWidth = width;
    }

    width = convert_pixel_width_to_tile_width(pixelWidth);
    left = sub_80E2D5C(left, width);
    windowId = CreateAndShowWindow(left, top, width, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);

    for (i = 0; i < count; i++)
        AddTextPrinterParameterized(windowId, 1, strings[i], 8, (i * 16) + 1, TEXT_SPEED_FF, NULL);

    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, 0);
    CreateChooseAnswerTask(TRUE, count, windowId);
}

#define tNoBButton data[4]
#define tWrapAround data[5]
#define tWindowId data[6]

static void Task_ChooseAnswer(u8 taskId)
{
    s8 input;
    s16 *data = gTasks[taskId].data;

    if (!tWrapAround)
        input = Menu_ProcessInputNoWrap();
    else
        input = Menu_ProcessInput();

    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tNoBButton)
            return;

        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0x7F;
        break;
    default:
        gSpecialVar_Result = input;
        break;
    }

    RemoveAndHideWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height)
{
    u8 windowId;
    struct WindowTemplate winTemplate = CreateWindowTemplate(0, left + 1, top + 1, width, height, 15, 100);

    windowId = AddWindow(&winTemplate);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
    return windowId;
}

static void RemoveAndHideWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void CreateChooseAnswerTask(bool8 noBButton, u8 itemsCount, u8 windowId)
{
    u8 taskId = CreateTask(Task_ChooseAnswer, 80);
    gTasks[taskId].tNoBButton = noBButton;

    if (itemsCount > 3)
        gTasks[taskId].tWrapAround = TRUE;
    else
        gTasks[taskId].tWrapAround = FALSE;

    gTasks[taskId].tWindowId = windowId;
}

#undef tNoBButton
#undef tWrapAround
#undef tWindowId

void CallApprenticeFunction(void)
{
    sApprenticeFunctions[gSpecialVar_0x8004]();
}

static void Script_ResetPlayerApprentice(void)
{
    u8 i;

    sub_819FBC8();
    PLAYER_APPRENTICE.activeLvlMode = 0;
    PLAYER_APPRENTICE.field_B1_1 = 0;
    PLAYER_APPRENTICE.field_B1_2 = 0;
    PLAYER_APPRENTICE.field_B2_0 = 0;

    for (i = 0; i < 3; i++)
        PLAYER_APPRENTICE.monIds[i] = 0;

    for (i = 0; i < 9; i++)
    {
        PLAYER_APPRENTICE.field_B8[i].unk0_0 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_1 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_2 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_3 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk2 = 0;
    }
}

static void Script_IsPlayersApprenticeActive(void)
{
    if (!IsPlayersApprenticeActive())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

static void Script_SetPlayersApprenticeLvlMode(void)
{
    SetPlayersApprenticeLvlMode(gSpecialVar_0x8005);
}

static void sub_81A0978(void)
{
    sub_819FBC8();
}

static void sub_81A0984(void)
{
    sub_819FD64();
}

static void sub_81A0990(void)
{
    PLAYER_APPRENTICE.field_B1_1++;
}

static void sub_81A09B4(void)
{
    gSpecialVar_Result = PLAYER_APPRENTICE.field_B1_1;
}

static void sub_81A09D0(void)
{
    s32 var = PLAYER_APPRENTICE.field_B1_1 - 3;
    if (var < 0)
    {
        gSpecialVar_Result = FALSE;
    }
    else
    {
        if (var > 8)
            gSpecialVar_Result = TRUE;

        if (!PLAYER_APPRENTICE.field_B8[var].unk0_0)
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
    }
}

static void Script_CreateApprenticeMenu(void)
{
    CreateMenuWithAnswers(gSpecialVar_0x8005);
}

static void Task_WaitForPrintingMessage(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        DestroyTask(taskId);
        if (gSpecialVar_0x8005)
            ExecuteFuncAfterButtonPress(EnableBothScriptContexts);
        else
            EnableBothScriptContexts();
    }
}

static void PrintMessage(void)
{
    const u8 *string;

    if (gSpecialVar_0x8006 == 6)
    {
        string = gUnknown_08610FF0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 7)
    {
        string = gUnknown_08610FF0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 8)
    {
        string = gUnknown_086111B0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 9)
    {
        string = gUnknown_086111B0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 4)
    {
        string = gUnknown_08611230[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 5)
    {
        string = gUnknown_08611230[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 10)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 11)
    {
        string = gUnknown_086112B0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 12)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][3];
    }
    else if (gSpecialVar_0x8006 == 13)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 16)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][4];
    }
    else if (gSpecialVar_0x8006 == 14)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == 15)
    {
        string = gUnknown_086112B0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 0)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 1)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 2)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == 3)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][3];
    }
    else
    {
        EnableBothScriptContexts();
        return;
    }

    StringExpandPlaceholders(gStringVar4, string);
    AddTextPrinterForMessage(TRUE);
    CreateTask(Task_WaitForPrintingMessage, 1);
}

static void Script_PrintMessage(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_808B864();
    sub_808BCF4();
    DrawDialogueFrame(0, 1);
    PrintMessage();
}

static void sub_81A0CC0(void)
{
    if (PLAYER_APPRENTICE.field_B1_1 < 3)
    {
        gSpecialVar_Result = 2;
    }
    else if (PLAYER_APPRENTICE.field_B1_1 > 11)
    {
        gSpecialVar_Result = 5;
    }
    else
    {
        s32 id = PLAYER_APPRENTICE.field_B1_1 - 3;
        switch (PLAYER_APPRENTICE.field_B8[id].unk0_0)
        {
        case 1:
            gSpecialVar_Result = 4;
            break;
        case 2:
            gSpecialVar_Result = 3;
            break;
        case 3:
            gSpecialVar_Result = 1;
            break;
        default:
            gSpecialVar_Result = 5;
            break;
        }
    }
}

static void sub_81A0D40(void)
{
    if (gSpecialVar_0x8005)
    {
        u8 bitNo = gSpecialVar_0x8006;
        PLAYER_APPRENTICE.field_B2_0 |= 1 << bitNo;
    }
}

static void sub_81A0D80(void)
{
    if (PLAYER_APPRENTICE.field_B1_1 >= 3)
    {
        u8 id = PLAYER_APPRENTICE.field_B1_1 - 3;
        if (gSpecialVar_0x8005)
            PLAYER_APPRENTICE.field_B8[id].unk0_3 = 1;
        else
            PLAYER_APPRENTICE.field_B8[id].unk0_3 = 0;
    }
}

static void sub_81A0DD4(void)
{
    u8 i;
    u8 count = 0;
    u8 id1, id2;

    for (i = 0; i < 9 && PLAYER_APPRENTICE.field_B8[i].unk0_0; count++, i++)
        ;

    gUnknown_030062F0 = AllocZeroed(sizeof(*gUnknown_030062F0));
    if (gSpecialVar_0x8005 == 2)
    {
        if (PLAYER_APPRENTICE.field_B1_1 < 3)
        {
            id1 = PLAYER_APPRENTICE.monIds[PLAYER_APPRENTICE.field_B1_1] >> 4;
            gUnknown_030062F0->unk2 = gApprentices[PLAYER_APPRENTICE.id].species[id1];

            id2 = PLAYER_APPRENTICE.monIds[PLAYER_APPRENTICE.field_B1_1] & 0xF;
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
    else if (gSpecialVar_0x8005 == 3)
    {
        if (PLAYER_APPRENTICE.field_B1_1 >= 3
            && PLAYER_APPRENTICE.field_B1_1 < count + 3
            && PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_0 == 2)
        {
            count = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_1;
            APPRENTICE_SPECIES_ID_2(id1, count);
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id1];
            gUnknown_030062F0->unk4 = sub_81A0284(count, id1, PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_2);
            gUnknown_030062F0->unk6 = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2;
        }
    }
    else if (gSpecialVar_0x8005 == 4)
    {
        if (PLAYER_APPRENTICE.field_B1_1 >= 3
            && PLAYER_APPRENTICE.field_B1_1 < count + 3
            && PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_0 == 1)
        {
            count = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_1;
            APPRENTICE_SPECIES_ID_2(id2, count);
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
}

static void sub_81A0FE4(void)
{
    FREE_AND_SET_NULL(gUnknown_030062F0);
}

static void sub_81A0FFC(void)
{
    u8 *stringDst;
    u8 text[16];
    u32 speciesArrayId;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        stringDst = gStringVar1;
        break;
    case 1:
        stringDst = gStringVar2;
        break;
    case 2:
        stringDst = gStringVar3;
        break;
    default:
        return;
    }

    switch (gSpecialVar_0x8006)
    {
    case APPRENTICE_BUFF_SPECIES1:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk0]);
        break;
    case APPRENTICE_BUFF_SPECIES2:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk2]);
        break;
    case APPRENTICE_BUFF_SPECIES3:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk0]);
        break;
    case APPRENTICE_BUFF_MOVE1:
        StringCopy(stringDst, gMoveNames[gUnknown_030062F0->unk4]);
        break;
    case APPRENTICE_BUFF_MOVE2:
        StringCopy(stringDst, gMoveNames[gUnknown_030062F0->unk6]);
        break;
    case APPRENTICE_BUFF_ITEM:
        StringCopy(stringDst, ItemId_GetName(PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2));
        break;
    case APPRENTICE_BUFF_NAME:
        TVShowConvertInternationalString(text, GetApprenticeNameInLanguage(PLAYER_APPRENTICE.id, LANGUAGE_ENGLISH), LANGUAGE_ENGLISH);
        StringCopy(stringDst, text);
        break;
    case APPRENTICE_BUFF_LEVEL:
        if (PLAYER_APPRENTICE.activeLvlMode == 1)
            StringCopy(stringDst, gText_Lv50);
        else
            StringCopy(stringDst, gText_OpenLevel);
        break;
    case APPRENTICE_BUFF_EASY_CHAT:
        FrontierSpeechToString(gSaveBlock2Ptr->apprentices[0].easyChatWords);
        StringCopy(stringDst, gStringVar4);
        break;
    case APPRENTICE_BUFF_SPECIES4:
        if (PLAYER_APPRENTICE.field_B1_2 < 3)
        {
            APPRENTICE_SPECIES_ID(speciesArrayId, PLAYER_APPRENTICE.field_B1_2);
        }
        else
        {
            speciesArrayId = 0;
        }
        StringCopy(stringDst, gSpeciesNames[gApprentices[PLAYER_APPRENTICE.id].species[speciesArrayId]]);
        break;
    }
}

static void sub_81A11F8(void)
{
    PLAYER_APPRENTICE.field_B1_2 = gSpecialVar_0x8005;
}

static void sub_81A1218(void)
{
    sub_81AAC28();
}

static void sub_81A1224(void)
{
    u8 i, j;
    u8 count;

    if (PLAYER_APPRENTICE.field_B1_1 < 3)
        return;

    for (count = 0, j = 0; j < 9 && PLAYER_APPRENTICE.field_B8[j].unk0_0; count++, j++)
        ;

    for (i = 0; i < count && i < PLAYER_APPRENTICE.field_B1_1 - 3; i++)
    {
        do {} while(0);
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 1
            && PLAYER_APPRENTICE.field_B8[i].unk0_3
            && PLAYER_APPRENTICE.field_B8[i].unk2 == gSpecialVar_0x8005)
        {
            PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_3 = 0;
            PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2 = gSpecialVar_0x8005;
            gSpecialVar_Result = 0;
            return;
        }
    }

    PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_3 = 1;
    PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2 = gSpecialVar_0x8005;
    gSpecialVar_Result = 1;
}

static void sub_81A1370(void)
{
    s32 i;
    s32 r10;
    s32 r9;

    if (gSaveBlock2Ptr->apprentices[0].playerName[0] == EOS)
        return;

    for (i = 0; i < 3; i++)
    {
        if (gSaveBlock2Ptr->apprentices[i + 1].playerName[0] == EOS)
        {
            gSaveBlock2Ptr->apprentices[i + 1] = gSaveBlock2Ptr->apprentices[0];
            return;
        }
    }

    r10 = 0xFFFF;
    r9 = -1;
    for (i = 1; i < 4; i++)
    {
        if (GetTrainerId(gSaveBlock2Ptr->apprentices[i].playerId) == GetTrainerId(gSaveBlock2Ptr->playerTrainerId)
            && gSaveBlock2Ptr->apprentices[i].number < r10)
        {
            r10 = gSaveBlock2Ptr->apprentices[i].number;
            r9 = i;
        }
    }

    if (r9 > 0)
        gSaveBlock2Ptr->apprentices[r9] = gSaveBlock2Ptr->apprentices[0];
}

static void sub_81A1438(void)
{
    u8 i;

    gSaveBlock2Ptr->apprentices[0].id = PLAYER_APPRENTICE.id;
    gSaveBlock2Ptr->apprentices[0].lvlMode = PLAYER_APPRENTICE.activeLvlMode;

    for (i = 0; i < 9 && PLAYER_APPRENTICE.field_B8[i].unk0_0; i++)
        ;

    gSaveBlock2Ptr->apprentices[0].field_1 = i;
    if (gSaveBlock2Ptr->apprentices[0].number < 255)
        gSaveBlock2Ptr->apprentices[0].number++;

    sub_81A0390(gSaveBlock2Ptr->apprentices[0].field_1);
    for (i = 0; i < 4; i++)
        gSaveBlock2Ptr->apprentices[0].playerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    StringCopy(gSaveBlock2Ptr->apprentices[0].playerName, gSaveBlock2Ptr->playerName);
    gSaveBlock2Ptr->apprentices[0].language = gGameLanguage;
    CalcApprenticeChecksum(&gSaveBlock2Ptr->apprentices[0]);
}

static void sub_81A150C(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[gSaveBlock2Ptr->apprentices[0].id].facilityClass;

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses) && gTowerMaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        mapObjectGfxId = gTowerMaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses) && gTowerFemaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        mapObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
}

static void Script_SetPlayerApprenticeTrainerGfxId(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[PLAYER_APPRENTICE.id].facilityClass;

    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses) && gTowerMaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        mapObjectGfxId = gTowerMaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses) && gTowerFemaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        mapObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
}

static void sub_81A1638(void)
{
    gSpecialVar_0x8004 = 1;
}

static void sub_81A1644(void)
{
    gSpecialVar_0x8004 = 1;
}

const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language)
{
    const struct ApprenticeTrainer *apprentice = &gApprentices[apprenticeId];

    switch (language)
    {
    case LANGUAGE_JAPANESE:
        return apprentice->name[0];
    case LANGUAGE_ENGLISH:
        return apprentice->name[1];
    case LANGUAGE_FRENCH:
        return apprentice->name[2];
    case LANGUAGE_ITALIAN:
        return apprentice->name[3];
    case LANGUAGE_GERMAN:
        return apprentice->name[4];
    case LANGUAGE_SPANISH:
    default:
        return apprentice->name[5];
    }
}

static void sub_81A16B4(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
        SwitchTaskToFollowupFunc(taskId);
}

static void Task_ExecuteFuncAfterButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        gUnknown_030062F4 = (void*)(u32)(((u16)gTasks[taskId].data[0] | (gTasks[taskId].data[1] << 0x10)));
        gUnknown_030062F4();
        DestroyTask(taskId);
    }
}

static void ExecuteFuncAfterButtonPress(void (*func)(void))
{
    u8 taskId = CreateTask(Task_ExecuteFuncAfterButtonPress, 1);
    gTasks[taskId].data[0] = (u32)(func);
    gTasks[taskId].data[1] = (u32)(func) >> 16;
}

static void sub_81A175C(TaskFunc taskFunc)
{
    u8 taskId = CreateTask(sub_81A16B4, 1);
    SetTaskFuncWithFollowupFunc(taskId, sub_81A16B4, taskFunc);
}
