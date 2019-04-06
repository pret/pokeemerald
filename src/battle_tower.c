#include "global.h"
#include "battle_tower.h"
#include "apprentice.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "text.h"
#include "main.h"
#include "international_string_util.h"
#include "battle.h"
#include "frontier_util.h"
#include "strings.h"
#include "recorded_battle.h"
#include "easy_chat.h"
#include "gym_leader_rematch.h"
#include "battle_transition.h"
#include "trainer_see.h"
#include "new_game.h"
#include "string_util.h"
#include "data.h"
#include "link.h"
#include "field_message_box.h"
#include "tv.h"
#include "battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/items.h"
#include "constants/trainers.h"
#include "constants/event_objects.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/easy_chat.h"

extern const u8 MossdeepCity_SpaceCenter_2F_EventScript_224157[];
extern const u8 MossdeepCity_SpaceCenter_2F_EventScript_224166[];

// EWRAM vars.
EWRAM_DATA const struct BattleFrontierTrainer *gFacilityTrainers = NULL;
EWRAM_DATA const struct FacilityMon *gFacilityTrainerMons = NULL;

// IWRAM common
u16 gUnknown_03006298[4];

// This file's functions.
static void sub_8161F94(void);
static void sub_8162054(void);
static void sub_81620F4(void);
static void ChooseNextBattleTowerTrainer(void);
static void sub_81621C0(void);
static void AwardBattleTowerRibbons(void);
static void SaveBattleTowerProgress(void);
static void sub_8163914(void);
static void nullsub_61(void);
static void SpriteCB_Null6(void);
static void sub_81642A0(void);
static void sub_8164828(void);
static void sub_8164B74(void);
static void sub_8164DCC(void);
static void sub_8164DE4(void);
static void sub_8164E04(void);
static void ValidateBattleTowerRecordChecksums(void);
static void SaveCurrentWinStreak(void);
static void ValidateApprenticesChecksums(void);
static void sub_8165E18(void);
static void CopyEReaderTrainerFarewellMessage(void);
static void ClearBattleTowerRecord(struct EmeraldBattleTowerRecord *record);
static void FillTrainerParty(u16 trainerId, u8 firstMonId, u8 monCount);
static void FillTentTrainerParty_(u16 trainerId, u8 firstMonId, u8 monCount);
static void FillFactoryFrontierTrainerParty(u16 trainerId, u8 firstMonId);
static void FillFactoryTentTrainerParty(u16 trainerId, u8 firstMonId);
static u8 GetFrontierTrainerFixedIvs(u16 trainerId);
static void FillPartnerParty(u16 trainerId);
static void SetEReaderTrainerChecksum(struct BattleTowerEReaderTrainer *ereaderTrainer);
static u8 SetTentPtrsGetLevel(void);

// Const rom data.
const u16 gBattleFrontierHeldItems[] =
{
    ITEM_NONE,
    ITEM_KINGS_ROCK,
    ITEM_SITRUS_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_HARD_STONE,
    ITEM_FOCUS_BAND,
    ITEM_PERSIM_BERRY,
    ITEM_MIRACLE_SEED,
    ITEM_BERRY_JUICE,
    ITEM_MACHO_BRACE,
    ITEM_SILVER_POWDER,
    ITEM_CHERI_BERRY,
    ITEM_BLACK_GLASSES,
    ITEM_BLACK_BELT,
    ITEM_SOUL_DEW,
    ITEM_CHOICE_BAND,
    ITEM_MAGNET,
    ITEM_SILK_SCARF,
    ITEM_WHITE_HERB,
    ITEM_DEEP_SEA_SCALE,
    ITEM_DEEP_SEA_TOOTH,
    ITEM_MYSTIC_WATER,
    ITEM_SHARP_BEAK,
    ITEM_QUICK_CLAW,
    ITEM_LEFTOVERS,
    ITEM_RAWST_BERRY,
    ITEM_LIGHT_BALL,
    ITEM_POISON_BARB,
    ITEM_NEVER_MELT_ICE,
    ITEM_ASPEAR_BERRY,
    ITEM_SPELL_TAG,
    ITEM_BRIGHT_POWDER,
    ITEM_LEPPA_BERRY,
    ITEM_SCOPE_LENS,
    ITEM_TWISTED_SPOON,
    ITEM_METAL_COAT,
    ITEM_MENTAL_HERB,
    ITEM_CHARCOAL,
    ITEM_PECHA_BERRY,
    ITEM_SOFT_SAND,
    ITEM_LUM_BERRY,
    ITEM_DRAGON_SCALE,
    ITEM_DRAGON_FANG,
    ITEM_IAPAPA_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_SEA_INCENSE,
    ITEM_SHELL_BELL,
    ITEM_SALAC_BERRY,
    ITEM_LANSAT_BERRY,
    ITEM_APICOT_BERRY,
    ITEM_STARF_BERRY,
    ITEM_LIECHI_BERRY,
    ITEM_STICK,
    ITEM_LAX_INCENSE,
    ITEM_AGUAV_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_THICK_CLUB,
    ITEM_MAGO_BERRY,
    ITEM_METAL_POWDER,
    ITEM_PETAYA_BERRY,
    ITEM_LUCKY_PUNCH,
    ITEM_GANLON_BERRY
};

#include "data/battle_frontier/battle_frontier_trainer_mons.h"
#include "data/battle_frontier/battle_frontier_trainers.h"
#include "data/battle_frontier/battle_frontier_mons.h"

const u8 gTowerMaleFacilityClasses[30] =
{
    FACILITY_CLASS_RUIN_MANIAC,
    FACILITY_CLASS_TUBER_M,
    FACILITY_CLASS_COOLTRAINER_M,
    FACILITY_CLASS_RICH_BOY,
    FACILITY_CLASS_POKEMANIAC,
    FACILITY_CLASS_SWIMMER_M,
    FACILITY_CLASS_BLACK_BELT,
    FACILITY_CLASS_GUITARIST,
    FACILITY_CLASS_KINDLER,
    FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_BUG_MANIAC,
    FACILITY_CLASS_PSYCHIC_M,
    FACILITY_CLASS_GENTLEMAN,
    FACILITY_CLASS_SCHOOL_KID_M,
    FACILITY_CLASS_POKEFAN_M,
    FACILITY_CLASS_EXPERT_M,
    FACILITY_CLASS_YOUNGSTER,
    FACILITY_CLASS_FISHERMAN,
    FACILITY_CLASS_CYCLING_TRIATHLETE_M,
    FACILITY_CLASS_RUNNING_TRIATHLETE_M,
    FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
    FACILITY_CLASS_DRAGON_TAMER,
    FACILITY_CLASS_BIRD_KEEPER,
    FACILITY_CLASS_NINJA_BOY,
    FACILITY_CLASS_SAILOR,
    FACILITY_CLASS_COLLECTOR,
    FACILITY_CLASS_PKMN_BREEDER_M,
    FACILITY_CLASS_PKMN_RANGER_M,
    FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_HIKER
};

const u8 gTowerFemaleFacilityClasses[20] =
{
    FACILITY_CLASS_AROMA_LADY,
    FACILITY_CLASS_TUBER_F,
    FACILITY_CLASS_COOLTRAINER_F,
    FACILITY_CLASS_HEX_MANIAC,
    FACILITY_CLASS_LADY,
    FACILITY_CLASS_BEAUTY,
    FACILITY_CLASS_PSYCHIC_F,
    FACILITY_CLASS_SCHOOL_KID_F,
    FACILITY_CLASS_POKEFAN_F,
    FACILITY_CLASS_EXPERT_F,
    FACILITY_CLASS_CYCLING_TRIATHLETE_F,
    FACILITY_CLASS_RUNNING_TRIATHLETE_F,
    FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
    FACILITY_CLASS_BATTLE_GIRL,
    FACILITY_CLASS_PARASOL_LADY,
    FACILITY_CLASS_SWIMMER_F,
    FACILITY_CLASS_PICNICKER,
    FACILITY_CLASS_POKEMON_BREEDER_F,
    FACILITY_CLASS_PKMN_RANGER_F,
    FACILITY_CLASS_LASS
};

const u8 gTowerMaleTrainerGfxIds[30] =
{
    EVENT_OBJ_GFX_HIKER,
    EVENT_OBJ_GFX_TUBER_M,
    EVENT_OBJ_GFX_MAN_3,
    EVENT_OBJ_GFX_RICH_BOY,
    EVENT_OBJ_GFX_MANIAC,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M,
    EVENT_OBJ_GFX_BLACK_BELT,
    EVENT_OBJ_GFX_MAN_5,
    EVENT_OBJ_GFX_MAN_5,
    EVENT_OBJ_GFX_CAMPER,
    EVENT_OBJ_GFX_MANIAC,
    EVENT_OBJ_GFX_PSYCHIC_M,
    EVENT_OBJ_GFX_GENTLEMAN,
    EVENT_OBJ_GFX_SCHOOL_KID_M,
    EVENT_OBJ_GFX_POKEFAN_M,
    EVENT_OBJ_GFX_EXPERT_M,
    EVENT_OBJ_GFX_YOUNGSTER,
    EVENT_OBJ_GFX_FISHERMAN,
    EVENT_OBJ_GFX_CYCLING_TRIATHLETE_M,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M,
    EVENT_OBJ_GFX_MAN_3,
    EVENT_OBJ_GFX_MAN_5,
    EVENT_OBJ_GFX_NINJA_BOY,
    EVENT_OBJ_GFX_SAILOR,
    EVENT_OBJ_GFX_MANIAC,
    EVENT_OBJ_GFX_MAN_4,
    EVENT_OBJ_GFX_CAMPER,
    EVENT_OBJ_GFX_BUG_CATCHER,
    EVENT_OBJ_GFX_HIKER
};

const u8 gTowerFemaleTrainerGfxIds[20] =
{
    EVENT_OBJ_GFX_WOMAN_2,
    EVENT_OBJ_GFX_TUBER_F,
    EVENT_OBJ_GFX_WOMAN_5,
    EVENT_OBJ_GFX_HEX_MANIAC,
    EVENT_OBJ_GFX_WOMAN_2,
    EVENT_OBJ_GFX_BEAUTY,
    EVENT_OBJ_GFX_LASS,
    EVENT_OBJ_GFX_GIRL_3,
    EVENT_OBJ_GFX_POKEFAN_F,
    EVENT_OBJ_GFX_EXPERT_F,
    EVENT_OBJ_GFX_CYCLING_TRIATHLETE_F,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F,
    EVENT_OBJ_GFX_GIRL_3,
    EVENT_OBJ_GFX_WOMAN_5,
    EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F,
    EVENT_OBJ_GFX_PICNICKER,
    EVENT_OBJ_GFX_WOMAN_2,
    EVENT_OBJ_GFX_PICNICKER,
    EVENT_OBJ_GFX_LASS
};

static const u8 sRubyFacilityClassToEmerald[][2] =
{
    {0x00, FACILITY_CLASS_AQUA_LEADER_ARCHIE},
    {0x01, FACILITY_CLASS_AQUA_GRUNT_M},
    {0x02, FACILITY_CLASS_AQUA_GRUNT_F},
    {0x03, FACILITY_CLASS_AROMA_LADY},
    {0x04, FACILITY_CLASS_RUIN_MANIAC},
    {0x05, FACILITY_CLASS_INTERVIEWER},
    {0x06, FACILITY_CLASS_TUBER_F},
    {0x07, FACILITY_CLASS_TUBER_M},
    {0x08, FACILITY_CLASS_COOLTRAINER_M},
    {0x09, FACILITY_CLASS_COOLTRAINER_F},
    {0x0a, FACILITY_CLASS_HEX_MANIAC},
    {0x0b, FACILITY_CLASS_LADY},
    {0x0c, FACILITY_CLASS_BEAUTY},
    {0x0d, FACILITY_CLASS_RICH_BOY},
    {0x0e, FACILITY_CLASS_POKEMANIAC},
    {0x0f, FACILITY_CLASS_SWIMMER_M},
    {0x10, FACILITY_CLASS_BLACK_BELT},
    {0x11, FACILITY_CLASS_GUITARIST},
    {0x12, FACILITY_CLASS_KINDLER},
    {0x13, FACILITY_CLASS_CAMPER},
    {0x14, FACILITY_CLASS_BUG_MANIAC},
    {0x15, FACILITY_CLASS_PSYCHIC_M},
    {0x16, FACILITY_CLASS_PSYCHIC_F},
    {0x17, FACILITY_CLASS_GENTLEMAN},
    {0x18, FACILITY_CLASS_ELITE_FOUR_SIDNEY},
    {0x19, FACILITY_CLASS_ELITE_FOUR_PHOEBE},
    {0x1a, FACILITY_CLASS_LEADER_ROXANNE},
    {0x1b, FACILITY_CLASS_LEADER_BRAWLY},
    {0x1c, FACILITY_CLASS_LEADER_TATE_AND_LIZA},
    {0x1d, FACILITY_CLASS_SCHOOL_KID_M},
    {0x1e, FACILITY_CLASS_SCHOOL_KID_F},
    {0x1f, FACILITY_CLASS_SR_AND_JR},
    {0x20, FACILITY_CLASS_POKEFAN_M},
    {0x21, FACILITY_CLASS_POKEFAN_F},
    {0x22, FACILITY_CLASS_EXPERT_M},
    {0x23, FACILITY_CLASS_EXPERT_F},
    {0x24, FACILITY_CLASS_YOUNGSTER},
    {0x25, FACILITY_CLASS_CHAMPION_WALLACE},
    {0x26, FACILITY_CLASS_FISHERMAN},
    {0x27, FACILITY_CLASS_CYCLING_TRIATHLETE_M},
    {0x28, FACILITY_CLASS_CYCLING_TRIATHLETE_F},
    {0x29, FACILITY_CLASS_RUNNING_TRIATHLETE_M},
    {0x2a, FACILITY_CLASS_RUNNING_TRIATHLETE_F},
    {0x2b, FACILITY_CLASS_SWIMMING_TRIATHLETE_M},
    {0x2c, FACILITY_CLASS_SWIMMING_TRIATHLETE_F},
    {0x2d, FACILITY_CLASS_DRAGON_TAMER},
    {0x2e, FACILITY_CLASS_BIRD_KEEPER},
    {0x2f, FACILITY_CLASS_NINJA_BOY},
    {0x30, FACILITY_CLASS_BATTLE_GIRL},
    {0x31, FACILITY_CLASS_PARASOL_LADY},
    {0x32, FACILITY_CLASS_SWIMMER_F},
    {0x33, FACILITY_CLASS_PICNICKER},
    {0x34, FACILITY_CLASS_TWINS},
    {0x35, FACILITY_CLASS_SAILOR},
    {0x38, FACILITY_CLASS_COLLECTOR},
    {0x39, FACILITY_CLASS_WALLY},
    {0x3a, FACILITY_CLASS_BRENDAN},
    {0x3b, FACILITY_CLASS_BRENDAN_2},
    {0x3c, FACILITY_CLASS_BRENDAN_3},
    {0x3d, FACILITY_CLASS_MAY},
    {0x3e, FACILITY_CLASS_MAY_2},
    {0x3f, FACILITY_CLASS_MAY_3},
    {0x40, FACILITY_CLASS_PKMN_BREEDER_M},
    {0x41, FACILITY_CLASS_POKEMON_BREEDER_F},
    {0x42, FACILITY_CLASS_PKMN_RANGER_M},
    {0x43, FACILITY_CLASS_PKMN_RANGER_F},
    {0x44, FACILITY_CLASS_MAGMA_LEADER_MAXIE},
    {0x45, FACILITY_CLASS_MAGMA_GRUNT_M},
    {0x46, FACILITY_CLASS_MAGMA_GRUNT_F},
    {0x47, FACILITY_CLASS_LASS},
    {0x48, FACILITY_CLASS_BUG_CATCHER},
    {0x49, FACILITY_CLASS_HIKER},
    {0x4a, FACILITY_CLASS_YOUNG_COUPLE},
    {0x4b, FACILITY_CLASS_OLD_COUPLE},
    {0x4c, FACILITY_CLASS_SIS_AND_BRO},
};

static const u8 *const gUnknown_085DCFD8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244383,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2443E7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244413,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24444B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2444D6
};

static const u8 *const gUnknown_085DCFEC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2444EF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24451E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244549,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24459B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2445C5
};

static const u8 *const gUnknown_085DD000[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2445E8,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244618,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244643,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24468F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2446B4
};

static const u8 *const gUnknown_085DD014[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2446E5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24474D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24479E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24480C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2448A7
};

static const u8 *const gUnknown_085DD028[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2448CD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2448F5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244939,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244989,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2449E6
};

static const u8 *const gUnknown_085DD03C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244A23,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244AA9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244AD6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244B52,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244B93
};

static const u8 *const gUnknown_085DD050[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244BD2,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244C18,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244C6E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244CD6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244D07
};

static const u8 *const gUnknown_085DD064[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244D36,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244D82,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244DC6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244DFE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244E5B
};

static const u8 *const gUnknown_085DD078[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244E7E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244ECA,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244EF4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244F4F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244F98
};

static const u8 *const gUnknown_085DD08C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_244FD3,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245013,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24503D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245087,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2450C0
};

static const u8 *const gUnknown_085DD0A0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2450E6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245196,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2451BD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24522F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24529A
};

static const u8 *const gUnknown_085DD0B4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2452EF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2453B4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245406,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245464,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2454A3
};

static const u8 *const gUnknown_085DD0C8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2454D6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245535,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24555F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2455EC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245656
};

static const u8 *const gUnknown_085DD0DC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24568A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2456F5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245740,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2457D9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24581F
};

static const u8 *const gUnknown_085DD0F0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245851,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24589C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2458CE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245923,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24597F
};

static const u8 *const gUnknown_085DD104[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2459BE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2459F7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245A5F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245AB4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245B3E
};

static const u8 *const gUnknown_085DD118[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245B79,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245B91,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245BBD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245C05,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245C2D
};

static const u8 *const gUnknown_085DD12C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245C66,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245C7F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245CAC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245CE6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245D07
};

static const u8 *const gUnknown_085DD140[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245D4B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245D60,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245D8D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245DC7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245DF0
};

static const u8 *const gUnknown_085DD154[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245E20,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245E41,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245E78,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245EBD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245EEC
};

static const u8 *const gUnknown_085DD168[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245F2B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245F58,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245F87,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_245FC6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246002
};

static const u8 *const gUnknown_085DD17C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246020,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246051,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246082,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2460D5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24610D
};

static const u8 *const gUnknown_085DD190[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24614A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24615D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24617D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2461C7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2461F5
};

static const u8 *const gUnknown_085DD1A4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24622A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246244,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24626E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2462AA,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2462E4
};

static const u8 *const gUnknown_085DD1B8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24631F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24633C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24636B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2463C5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2463FF
};

static const u8 *const gUnknown_085DD1CC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246449,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246478,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24649D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2464EE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246529
};

static const u8 *const gUnknown_085DD1E0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246571,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24658C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2465B5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246605,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24662A
};

static const u8 *const gUnknown_085DD1F4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246662,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246686,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2466B4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2466E6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24670A
};

static const u8 *const gUnknown_085DD208[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246741,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246760,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246791,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2467C4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2467E6
};

static const u8 *const gUnknown_085DD21C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2467FF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246831,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246864,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2468A7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2468FE
};

static const u8 *const gUnknown_085DD230[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24692B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24694B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24697C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2469B4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2469F1
};

static const u8 *const gUnknown_085DD244[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246A22,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246A4E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246A85,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246ACF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246AF7
};

static const u8 *const gUnknown_085DD258[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246B2B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246B3F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246B6B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246BB2,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246BE9
};

static const u8 *const gUnknown_085DD26C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246C22,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246C35,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246C6C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246CB3,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246CE9
};

static const u8 *const gUnknown_085DD280[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246D2D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246D3F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246D6A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246D9E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246DD3
};

static const u8 *const gUnknown_085DD294[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246E1A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246E39,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246E64,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246EB6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246EEE
};

static const u8 *const gUnknown_085DD2A8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246F21,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246F4C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246F7B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_246FCC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247013
};

static const u8 *const gUnknown_085DD2BC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24705B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24707D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2470B2,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2470FD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24712A
};

static const u8 *const gUnknown_085DD2D0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24716C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24718D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2471C7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2471FB,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247238
};

static const u8 *const gUnknown_085DD2E4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247268,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247291,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2472C7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247313,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247348
};

static const u8 *const gUnknown_085DD2F8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24737A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24738F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2473C6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2473FB,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247438
};

static const u8 *const gUnknown_085DD30C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247470,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247484,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2474AF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2474EC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24751D
};

static const u8 *const gUnknown_085DD320[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24754A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24755C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24758B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2475BC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2475D5
};

static const u8 *const gUnknown_085DD334[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24760D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247629,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247655,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24769B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2476ED
};

static const u8 *const gUnknown_085DD348[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247724,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247749,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24777A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2477CE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247807
};

static const u8 *const gUnknown_085DD35C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247838,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247854,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247889,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2478DD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24790D
};

static const u8 *const gUnknown_085DD370[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247942,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24795F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247991,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2479CE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247A18
};

static const u8 *const gUnknown_085DD384[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247A51,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247A76,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247AA1,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247AE3,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247B16
};

static const u8 *const gUnknown_085DD398[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247B3E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247B62,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247B9B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247BE7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247C23
};

static const u8 *const gUnknown_085DD3AC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247C4E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247C8C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247CB2,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247D07,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247D4E
};

static const u8 *const gUnknown_085DD3C0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247D97,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247DC7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247DFE,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247E3E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247E7E
};

static const u8 *const gUnknown_085DD3D4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247EA1,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247EB5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247EE9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247F3F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247F6D
};

static const u8 *const gUnknown_085DD3E8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247FA3,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247FB7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_247FE9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248031,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24805E
};

static const u8 *const gUnknown_085DD3FC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24808D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2480AB,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2480DC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248128,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248151
};

static const u8 *const gUnknown_085DD410[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24818E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2481A9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2481E1,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248221,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24824F
};

static const u8 *const gUnknown_085DD424[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248297,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2482B1,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2482DC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248321,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24833D
};

static const u8 *const gUnknown_085DD438[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248369,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24838D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2483C1,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248401,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248431
};

static const u8 *const gUnknown_085DD44C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248467,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248477,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2484AC,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2484E7,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248517
};

static const u8 *const gUnknown_085DD460[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248553,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24856A,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24857D,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2485E5,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248614
};

static const u8 *const gUnknown_085DD474[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24864E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248661,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248671,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2486C6,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2486FF
};

static const u8 *const gUnknown_085DD488[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248725,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248751,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248781,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2487C9,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2487F7
};

static const u8 *const gUnknown_085DD49C[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248829,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24885B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248892,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2488D8,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248908
};

static const u8 *const gUnknown_085DD4B0[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24894B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24895F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_24896F,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2489BD,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_2489E7
};

static const u8 *const gUnknown_085DD4C4[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248A10,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248A40,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248A72,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248AC0,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248AEB
};

static const u8 *const gUnknown_085DD4D8[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248B22,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248B39,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248B4C,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248BB4,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248BEE
};

static const u8 *const gUnknown_085DD4EC[] =
{
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248C2E,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248C5B,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248C90,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248CCF,
    BattleFrontier_BattleTowerMultiBattleRoom_Text_248D04
};

struct
{
    u32 facilityClass;
    const u8 *const *strings;
} const gUnknown_085DD500[] =
{
    {FACILITY_CLASS_LASS,                  gUnknown_085DD118},
    {FACILITY_CLASS_YOUNGSTER,             gUnknown_085DD12C},
    {FACILITY_CLASS_HIKER,                 gUnknown_085DD140},
    {FACILITY_CLASS_BEAUTY,                gUnknown_085DD154},
    {FACILITY_CLASS_FISHERMAN,             gUnknown_085DD168},
    {FACILITY_CLASS_LADY,                  gUnknown_085DD17C},
    {FACILITY_CLASS_CYCLING_TRIATHLETE_F,  gUnknown_085DD190},
    {FACILITY_CLASS_BUG_CATCHER,           gUnknown_085DD1A4},
    {FACILITY_CLASS_SCHOOL_KID_M,          gUnknown_085DD1B8},
    {FACILITY_CLASS_RICH_BOY,              gUnknown_085DD1CC},
    {FACILITY_CLASS_BLACK_BELT,            gUnknown_085DD1E0},
    {FACILITY_CLASS_TUBER_F,               gUnknown_085DD1F4},
    {FACILITY_CLASS_HEX_MANIAC,            gUnknown_085DD208},
    {FACILITY_CLASS_PKMN_BREEDER_M,        gUnknown_085DD21C},
    {FACILITY_CLASS_RUNNING_TRIATHLETE_F,  gUnknown_085DD230},
    {FACILITY_CLASS_RUNNING_TRIATHLETE_M,  gUnknown_085DD244},
    {FACILITY_CLASS_BATTLE_GIRL,           gUnknown_085DD258},
    {FACILITY_CLASS_CYCLING_TRIATHLETE_M,  gUnknown_085DD26C},
    {FACILITY_CLASS_TUBER_M,               gUnknown_085DD280},
    {FACILITY_CLASS_GUITARIST,             gUnknown_085DD294},
    {FACILITY_CLASS_GENTLEMAN,             gUnknown_085DD2A8},
    {FACILITY_CLASS_POKEFAN_M,             gUnknown_085DD2BC},
    {FACILITY_CLASS_EXPERT_M,              gUnknown_085DD2D0},
    {FACILITY_CLASS_EXPERT_F,              gUnknown_085DD2E4},
    {FACILITY_CLASS_DRAGON_TAMER,          gUnknown_085DD2F8},
    {FACILITY_CLASS_BIRD_KEEPER,           gUnknown_085DD30C},
    {FACILITY_CLASS_NINJA_BOY,             gUnknown_085DD320},
    {FACILITY_CLASS_PARASOL_LADY,          gUnknown_085DD334},
    {FACILITY_CLASS_BUG_MANIAC,            gUnknown_085DD348},
    {FACILITY_CLASS_SAILOR,                gUnknown_085DD35C},
    {FACILITY_CLASS_COLLECTOR,             gUnknown_085DD370},
    {FACILITY_CLASS_PKMN_RANGER_M,         gUnknown_085DD384},
    {FACILITY_CLASS_PKMN_RANGER_F,         gUnknown_085DD398},
    {FACILITY_CLASS_AROMA_LADY,            gUnknown_085DD3AC},
    {FACILITY_CLASS_RUIN_MANIAC,           gUnknown_085DD3C0},
    {FACILITY_CLASS_COOLTRAINER_M,         gUnknown_085DD3D4},
    {FACILITY_CLASS_COOLTRAINER_F,         gUnknown_085DD3E8},
    {FACILITY_CLASS_POKEMANIAC,            gUnknown_085DD3FC},
    {FACILITY_CLASS_KINDLER,               gUnknown_085DD410},
    {FACILITY_CLASS_CAMPER,                gUnknown_085DD424},
    {FACILITY_CLASS_PICNICKER,             gUnknown_085DD438},
    {FACILITY_CLASS_PSYCHIC_M,             gUnknown_085DD44C},
    {FACILITY_CLASS_PSYCHIC_F,             gUnknown_085DD460},
    {FACILITY_CLASS_SCHOOL_KID_F,          gUnknown_085DD474},
    {FACILITY_CLASS_POKEMON_BREEDER_F,     gUnknown_085DD488},
    {FACILITY_CLASS_POKEFAN_F,             gUnknown_085DD49C},
    {FACILITY_CLASS_SWIMMER_F,             gUnknown_085DD4B0},
    {FACILITY_CLASS_SWIMMING_TRIATHLETE_M, gUnknown_085DD4C4},
    {FACILITY_CLASS_SWIMMING_TRIATHLETE_F, gUnknown_085DD4D8},
    {FACILITY_CLASS_SWIMMER_M,             gUnknown_085DD4EC}
};

static const u8 *const *const gUnknown_085DD690[] =
{
    gUnknown_085DCFD8,
    gUnknown_085DCFEC,
    gUnknown_085DD000,
    gUnknown_085DD014,
    gUnknown_085DD028,
    gUnknown_085DD03C,
    gUnknown_085DD050,
    gUnknown_085DD064,
    gUnknown_085DD078,
    gUnknown_085DD08C,
    gUnknown_085DD0A0,
    gUnknown_085DD0B4,
    gUnknown_085DD0C8,
    gUnknown_085DD0DC,
    gUnknown_085DD0F0,
    gUnknown_085DD104
};

struct
{
    u16 species;
    u8 fixedIV;
    u8 level;
    u8 nature;
    u8 evs[6];
    u16 moves[4];
} const sStevenMons[3] =
{
    {
        .species = SPECIES_METANG,
        .fixedIV = 31,
        .level = 42,
        .nature = NATURE_BRAVE,
        .evs = {0, 252, 252, 0, 6, 0},
        .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW}
    },
    {
        .species = SPECIES_SKARMORY,
        .fixedIV = 31,
        .level = 43,
        .nature = NATURE_IMPISH,
        .evs = {252, 0, 0, 0, 6, 252},
        .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING}
    },
    {
        .species = SPECIES_AGGRON,
        .fixedIV = 31,
        .level = 44,
        .nature = NATURE_ADAMANT,
        .evs = {0, 252, 0, 0, 252, 6},
        .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW}
    }
};

#include "data/battle_frontier/battle_tent.h"

static void (* const gUnknown_085DF96C[])(void) =
{
    sub_8161F94,
    sub_8162054,
    sub_81620F4,
    ChooseNextBattleTowerTrainer,
    sub_81621C0,
    AwardBattleTowerRibbons,
    SaveBattleTowerProgress,
    sub_8163914,
    nullsub_61,
    SpriteCB_Null6,
    sub_81642A0,
    sub_8164828,
    sub_8164B74,
    sub_8164DCC,
    sub_8164DE4,
    sub_8164E04,
};

static const u32 gUnknown_085DF9AC[][2] =
{
    {0x00000001, 0x00000002},
    {0x00004000, 0x00008000},
    {0x00010000, 0x00020000},
    {0x00040000, 0x00080000},
};

static const u32 gUnknown_085DF9CC[][2] =
{
    {0xfffffffe, 0xfffffffd},
    {0xffffbfff, 0xffff7fff},
    {0xfffeffff, 0xfffdffff},
    {0xfffbffff, 0xfff7ffff},
};

static const u8 gUnknown_085DF9EC[] =
{
    0x01, 0x02, 0x03, 0x04, 0x05, 0x08, 0x09, 0x0a, 0x0b, 0x0c
};

static const u8 gUnknown_085DF9F6[] =
{
    [FRONTIER_MODE_SINGLES] = 3,
    [FRONTIER_MODE_DOUBLES] = 4,
    [FRONTIER_MODE_MULTIS] = 2,
    [FRONTIER_MODE_LINK_MULTIS] = 2,
};

static const u16 gUnknown_085DF9FA[][2] =
{
    {0x0000, 0x0063},
    {0x0050, 0x0077},
    {0x0064, 0x008b},
    {0x0078, 0x009f},
    {0x008c, 0x00b3},
    {0x00a0, 0x00c7},
    {0x00b4, 0x00db},
    {0x00c8, 0x012b},
};

static const u16 gUnknown_085DFA1A[][2] =
{
    {0x0064, 0x0077},
    {0x0078, 0x008b},
    {0x008c, 0x009f},
    {0x00a0, 0x00b3},
    {0x00b4, 0x00c7},
    {0x00c8, 0x00db},
    {0x00dc, 0x00ef},
    {0x00c8, 0x012b},
    {0x00b3, 0x008d},
    {0x00c8, 0x00b7},
};

static const u8 gUnknown_085DFA42[4] =
{
    [FRONTIER_MODE_SINGLES] = 3,
    [FRONTIER_MODE_DOUBLES] = 4,
    [FRONTIER_MODE_MULTIS] = 2,
    [FRONTIER_MODE_LINK_MULTIS] = 2,
};

static const u16 gUnknown_085DFA46[] =
{
    0x0c3a, 0x0c3a, 0x0c01, 0x0a2a, 0x0607, 0x0c01
};

static const u16 gUnknown_085DFA52[] =
{
    0x1039, 0x122e, 0x0c04, 0x0a3d, 0x0630, 0x0c04
};

// code
void sub_8161F74(void)
{
    gUnknown_085DF96C[gSpecialVar_0x8004]();
}

static void sub_8161F94(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 1;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    sub_81A3ACC();
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = 0;

    ValidateBattleTowerRecordChecksums();
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

static void sub_8162054(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSpecialVar_Result = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);
        break;
    case 2:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]) != 0);
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}

static void sub_81620F4(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_085DF9AC[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_085DF9CC[battleMode][lvlMode];
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}

static void sub_81621C0(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_EREADER)
        ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);

    if (gSaveBlock2Ptr->frontier.field_D04 < 9999)
        gSaveBlock2Ptr->frontier.field_D04++;

    gSaveBlock2Ptr->frontier.curChallengeBattleNum++;
    SaveCurrentWinStreak();
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
}

static bool8 ChooseSpecialBattleTowerTrainer(void)
{
    s32 i, j, validMons;
    s32 trainerIds[9];
    s32 idsCount = 0;
    s32 winStreak = 0;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (VarGet(VAR_FRONTIER_FACILITY) != FRONTIER_FACILITY_TOWER)
        return FALSE;

    winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);
    for (i = 0; i < 5; i++)
    {
        u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[i]);
        u32 recordHasData = 0;
        u32 checksum = 0;
        for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
        {
            recordHasData |= record[j];
            checksum += record[j];
        }
        validMons = 0;
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species != 0
                && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].level <= GetFrontierEnemyMonLevel(lvlMode))
                validMons++;
        }

        if (validMons >= gUnknown_085DF9F6[battleMode]
            && gSaveBlock2Ptr->frontier.towerRecords[i].winStreak == winStreak
            && gSaveBlock2Ptr->frontier.towerRecords[i].lvlMode == lvlMode
            && recordHasData
            && gSaveBlock2Ptr->frontier.towerRecords[i].checksum == checksum)
        {
            trainerIds[idsCount] = i + TRAINER_RECORD_MIXING_FRIEND;
            idsCount++;
        }
    }

    if (battleMode == FRONTIER_MODE_SINGLES)
    {
        ValidateApprenticesChecksums();
        for (i = 0; i < 4; i++)
        {
            if (gSaveBlock2Ptr->apprentices[i].lvlMode != 0
                && gUnknown_085DF9EC[gSaveBlock2Ptr->apprentices[i].field_1] == winStreak
                && gSaveBlock2Ptr->apprentices[i].lvlMode - 1 == lvlMode)
            {
                trainerIds[idsCount] = i + TRAINER_RECORD_MIXING_APPRENTICE;
                idsCount++;
            }
        }
    }

    if (idsCount != 0)
    {
        gTrainerBattleOpponent_A = trainerIds[Random() % idsCount];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void ChooseNextBattleTowerTrainer(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    if (lvlMode == FRONTIER_LVL_TENT)
    {
        sub_8165E18();
    }
    else
    {
        u16 id;
        u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u16 winStreak = GetCurrentFacilityWinStreak();
        u32 challengeNum = winStreak / 7;
        SetFacilityPtrsGetLevel();

        if (battleMode == FRONTIER_MODE_MULTIS || battleMode == FRONTIER_MODE_LINK_MULTIS)
        {
            id = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            gTrainerBattleOpponent_A = gSaveBlock2Ptr->frontier.trainerIds[id * 2];
            gTrainerBattleOpponent_B = gSaveBlock2Ptr->frontier.trainerIds[id * 2 + 1];
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_B, 1);
        }
        else if (ChooseSpecialBattleTowerTrainer())
        {
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;
        }
        else
        {
            s32 i;
            while (1)
            {
                id = sub_8162548(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);

                // Ensure trainer wasn't previously fought in this challenge.
                for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
                {
                    if (gSaveBlock2Ptr->frontier.trainerIds[i] == id)
                        break;
                }
                if (i == gSaveBlock2Ptr->frontier.curChallengeBattleNum)
                    break;
            }

            gTrainerBattleOpponent_A = id;
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            if (gSaveBlock2Ptr->frontier.curChallengeBattleNum + 1 < 7)
                gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;
        }
    }
}

u16 sub_8162548(u8 challengeNum, u8 battleNum)
{
    u16 trainerId;

    if (challengeNum <= 7)
    {
        if (battleNum == 6)
        {
            trainerId = (gUnknown_085DFA1A[challengeNum][1] - gUnknown_085DFA1A[challengeNum][0]) + 1;
            trainerId = gUnknown_085DFA1A[challengeNum][0] + (Random() % trainerId);
        }
        else
        {
            trainerId = (gUnknown_085DF9FA[challengeNum][1] - gUnknown_085DF9FA[challengeNum][0]) + 1;
            trainerId = gUnknown_085DF9FA[challengeNum][0] + (Random() % trainerId);
        }
    }
    else
    {
        trainerId = (gUnknown_085DF9FA[7][1] - gUnknown_085DF9FA[7][0]) + 1;
        trainerId = gUnknown_085DF9FA[7][0] + (Random() % trainerId);
    }

    return trainerId;
}

static void sub_81625B4(u8 challengeNum, u8 battleNum, u16 *trainerIdPtr, u8 *arg3) // Unused
{
    u16 trainerId, count;

    if (challengeNum <= 7)
    {
        if (battleNum == 6)
        {
            count = (gUnknown_085DFA1A[challengeNum][1] - gUnknown_085DFA1A[challengeNum][0]) + 1;
            trainerId = gUnknown_085DFA1A[challengeNum][0];
        }
        else
        {
            count = (gUnknown_085DF9FA[challengeNum][1] - gUnknown_085DF9FA[challengeNum][0]) + 1;
            trainerId = gUnknown_085DF9FA[challengeNum][0];
        }
    }
    else
    {
        count = (gUnknown_085DF9FA[7][1] - gUnknown_085DF9FA[7][0]) + 1;
        trainerId = gUnknown_085DF9FA[7][0];
    }

    *trainerIdPtr = trainerId;
    *arg3 = count;
}

void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId)
{
    u32 i;
    u8 facilityClass;
    u8 trainerObjectGfxId;

    SetFacilityPtrsGetLevel();
    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        SetFrontierBrainEventObjGfx_2();
        return;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleTrainerGfxIds[i];
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    switch (tempVarId)
    {
    case 0:
    default:
        VarSet(VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_BOY_1);
        return;
    case 1:
        VarSet(VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_BOY_1);
        return;
    case 15:
        VarSet(VAR_OBJ_GFX_ID_E, EVENT_OBJ_GFX_BOY_1);
        return;
    }
}

void SetEReaderTrainerGfxId(void)
{
    SetBattleFacilityTrainerGfxId(TRAINER_EREADER, 0);
}

u8 GetBattleFacilityTrainerGfxId(u16 trainerId)
{
    u32 i;
    u8 facilityClass;
    u8 trainerObjectGfxId;

    SetFacilityPtrsGetLevel();
    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }
    else
    {
        return EVENT_OBJ_GFX_BOY_1;
    }
}

void PutNewBattleTowerRecord(struct EmeraldBattleTowerRecord *newRecordEm)
{
    u16 slotValues[6];
    u16 slotIds[6];
    s32 i, j, k;
    s32 slotsCount = 0;
    struct EmeraldBattleTowerRecord *newRecord = newRecordEm; // Needed to match.

    // Find a record slot of the same player and replace it.
    for (i = 0; i < 5; i++)
    {
        k = 0;
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[i].trainerId[j] != newRecord->trainerId[j])
                break;
        }
        if (j == 4)
        {
            for (k = 0; k < PLAYER_NAME_LENGTH; k++)
            {
                // BUG: Wrong variable used, 'j' instead of 'k'.
                if (gSaveBlock2Ptr->frontier.towerRecords[i].name[j] != newRecord->name[j])
                    break;
                if (newRecord->name[j] == EOS)
                {
                    k = PLAYER_NAME_LENGTH;
                    break;
                }
            }
        }

        if (k == PLAYER_NAME_LENGTH)
            break;
    }
    if (i < 5)
    {
        gSaveBlock2Ptr->frontier.towerRecords[i] = *newRecord;
        return;
    }

    // Find an empty record slot.
    for (i = 0; i < 5; i++)
    {
        if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak == 0)
            break;
    }
    if (i < 5)
    {
        gSaveBlock2Ptr->frontier.towerRecords[i] = *newRecord;
        return;
    }

    // Find possible slots to replace the record.
    slotValues[0] = gSaveBlock2Ptr->frontier.towerRecords[0].winStreak;
    slotIds[0] = 0;
    slotsCount++;

    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < slotsCount; j++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak < slotValues[j])
            {
                j = 0;
                slotsCount = 1;
                slotValues[0] = gSaveBlock2Ptr->frontier.towerRecords[i].winStreak;
                slotIds[0] = i;
                break;
            }
            else if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak > slotValues[j])
            {
                break;
            }
        }

        if (j == slotsCount)
        {
            slotValues[slotsCount] = gSaveBlock2Ptr->frontier.towerRecords[i].winStreak;
            slotIds[slotsCount] = i;
            slotsCount++;
        }
    }

    i = Random() % slotsCount;
    gSaveBlock2Ptr->frontier.towerRecords[slotIds[i]] = *newRecord;
}

u8 GetFrontierTrainerFrontSpriteId(u16 trainerId)
{
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
        return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        return GetFrontierBrainTrainerPicIndex();
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        return gFacilityClassToPicIndex[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[GetRecordedBattleRecordMixFriendClass()];
        else
            return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass];
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[gApprentices[GetRecordedBattleApprenticeId()].facilityClass];
        else
            return gFacilityClassToPicIndex[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass];
    }
}

u8 GetFrontierOpponentClass(u16 trainerId)
{
    u8 trainerClass = 0;
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
        trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        trainerClass = GetFrontierBrainTrainerClass();
    }
    else if (trainerId == TRAINER_STEVEN_PARTNER)
    {
        trainerClass = gTrainers[TRAINER_STEVEN].trainerClass;
    }
    else if (trainerId >= TRAINER_CUSTOM_PARTNER)
    {
        trainerClass = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].trainerClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        trainerClass = gFacilityClassToTrainerClass[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[GetRecordedBattleRecordMixFriendClass()];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass];
            asm("");
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[GetRecordedBattleApprenticeId()].facilityClass];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass];
            asm("");
        }
    }

    return trainerClass;
}

static u8 GetFrontierTrainerFacilityClass(u16 trainerId)
{
    u8 facilityClass;
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = GetRecordedBattleRecordMixFriendClass();
        else
            facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = gApprentices[GetRecordedBattleApprenticeId()].facilityClass;
        else
            facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    return facilityClass;
}

void GetFrontierTrainerName(u8 *dst, u16 trainerId)
{
    s32 i = 0;
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gSaveBlock2Ptr->frontier.ereaderTrainer.name[i];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(dst);
        return;
    }
    else if (trainerId == TRAINER_STEVEN_PARTNER)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gTrainers[TRAINER_STEVEN].trainerName[i];
    }
    else if (trainerId >= TRAINER_CUSTOM_PARTNER)
    {
        for (i = 0; gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].trainerName[i] != EOS; i++)
            dst[i] = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].trainerName[i];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gFacilityTrainers[trainerId].trainerName[i];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            sub_8186468(dst);
            return;
        }
        else
        {
            struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND];
            TVShowConvertInternationalString(dst, record->name, record->language);
            return;
        }
    }
    else
    {
        u8 id, language;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            id = GetRecordedBattleApprenticeId();
            language = GetRecordedBattleApprenticeLanguage();
        }
        else
        {
            struct Apprentice *apprentice = &gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE];
            id = apprentice->id;
            language = apprentice->language;
        }
        TVShowConvertInternationalString(dst, GetApprenticeNameInLanguage(id, language), language);
        return;
    }

    dst[i] = EOS;
}

static bool8 IsFrontierTrainerFemale(u16 trainerId)
{
    u32 i;
    u8 facilityClass;

    SetFacilityPtrsGetLevel();
    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        return IsFrontierBrainFemale();
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
        return TRUE;
    else
        return FALSE;
}

void FillFrontierTrainerParty(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(gTrainerBattleOpponent_A, 0, monsCount);
}

void FillFrontierTrainersParties(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(gTrainerBattleOpponent_A, 0, monsCount);
    FillTrainerParty(gTrainerBattleOpponent_B, 3, monsCount);
}

static void FillTentTrainerParty(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTentTrainerParty_(gTrainerBattleOpponent_A, 0, monsCount);
}

static void FillTrainerParty(u16 trainerId, u8 firstMonId, u8 monCount)
{
    s32 i, j;
    u16 chosenMonIndices[4];
    u8 friendship = 0xFF;
    u8 level = SetFacilityPtrsGetLevel();
    u8 fixedIV = 0;
    u8 bfMonCount;
    const u16 *monSets = NULL;
    u32 otID = 0;

    if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        // Normal battle frontier trainer.
        fixedIV = GetFrontierTrainerFixedIvs(trainerId);
        monSets = gFacilityTrainers[gTrainerBattleOpponent_A].monSets;
    }
    else if (trainerId == TRAINER_EREADER)
    {
        for (i = firstMonId; i < firstMonId + 3; i++)
            CreateBattleTowerMon(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CreateFrontierBrainPokemon();
        return;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        // Record mixed player.
        for (j = 0, i = firstMonId; i < firstMonId + monCount; j++, i++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].species != 0
                && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].level <= level)
            {
                CreateBattleTowerMon2(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j], FALSE);
            }
        }
        return;
    }
    else
    {
        // Apprentice.
        for (i = firstMonId; i < firstMonId + 3; i++)
            CreateApprenticeMon(&gEnemyParty[i], &gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE], i - firstMonId);
        return;
    }

    // Regular battle frontier trainer.
    // Attempt to fill the trainer's party with random Pokemon until 3 have been
    // successfully chosen. The trainer's party may not have duplicate pokemon species
    // or duplicate held items.
    for (bfMonCount = 0; monSets[bfMonCount] != 0xFFFF; bfMonCount++)
        ;
    i = 0;
    otID = Random32();
    while (i != monCount)
    {
        u16 monSetId = monSets[Random() % bfMonCount];
        if ((level == 50 || level == 20) && monSetId > 849)
            continue;

        // Ensure this pokemon species isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_SPECIES, NULL) == gFacilityTrainerMons[monSetId].species)
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this Pokemon's held item isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) != 0
             && GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this exact pokemon index isn't a duplicate. This check doesn't seem necessary
        // because the species and held items were already checked directly above.
        for (j = 0; j < i; j++)
        {
            if (chosenMonIndices[j] == monSetId)
                break;
        }
        if (j != i)
            continue;

        chosenMonIndices[i] = monSetId;

        // Place the chosen pokemon into the trainer's party.
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[i + firstMonId],
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otID);

        friendship = 255;
        // Give the chosen pokemon its specified moves.
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[i + firstMonId], gFacilityTrainerMons[monSetId].moves[j], j);
            if (gFacilityTrainerMons[monSetId].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;  // Frustration is more powerful the lower the pokemon's friendship is.
        }

        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);

        // The pokemon was successfully added to the trainer's party, so it's safe to move on to
        // the next party slot.
        i++;
    }
}

// Probably an early draft before the 'CreateApprenticeMon' was written.
static void Unused_CreateApprenticeMons(u16 trainerId, u8 firstMonId)
{
    s32 i, j;
    u8 friendship = 0xFF;
    u8 level = 0;
    u8 fixedIV = 0;
    struct Apprentice *apprentice = &gSaveBlock2Ptr->apprentices[0];

    if (apprentice->field_1 < 5)
        fixedIV = 6;
    else
        fixedIV = 9;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = 100;
    else
        level = 50;

    for (i = 0; i != 3; i++)
    {
        CreateMonWithEVSpread(&gEnemyParty[firstMonId + i], apprentice->party[i].species, level, fixedIV, 8);
        friendship = 0xFF;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (apprentice->party[i].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &apprentice->party[i].item);
    }
}

u16 RandomizeFacilityTrainerMonSet(u16 trainerId)
{
    u8 level = SetFacilityPtrsGetLevel();
    const u16 *monSets = gFacilityTrainers[trainerId].monSets;
    u8 bfMonCount = 0;
    u32 monSetId = monSets[bfMonCount];

    while (monSetId != 0xFFFF)
    {
        bfMonCount++;
        monSetId = monSets[bfMonCount];
        if (monSetId == 0xFFFF)
            break;
    }

    do
    {
        monSetId = monSets[Random() % bfMonCount];
    } while((level == 50 || level == 20) && monSetId > 849);

    return monSetId;
}

static void FillFactoryTrainerParty(void)
{
    ZeroEnemyPartyMons();
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        FillFactoryFrontierTrainerParty(gTrainerBattleOpponent_A, 0);
    else
        FillFactoryTentTrainerParty(gTrainerBattleOpponent_A, 0);
}

static void FillFactoryFrontierTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i, j;
    u8 friendship;
    u8 level;
    u8 fixedIV;
    u32 otID;

    if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode; // Unused variable.
        u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        u8 challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][0] / 7;
        if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 6)
            fixedIV = GetFactoryMonFixedIV(challengeNum, 0);
        else
            fixedIV = GetFactoryMonFixedIV(challengeNum, 1);
    }
    else if (trainerId == TRAINER_EREADER)
    {
        for (i = firstMonId; i < firstMonId + 3; i++)
            CreateBattleTowerMon(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i - firstMonId]);
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        FillFactoryBrainParty();
        return;
    }
    else
    {
        fixedIV = 31;
    }

    level = SetFacilityPtrsGetLevel();
    otID = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);
    for (i = 0; i < 3; i++)
    {
        u16 monSetId = gUnknown_03006298[i];
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[firstMonId + i],
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otID);

        friendship = 0;
        for (j = 0; j < MAX_MON_MOVES; j++)
            SetMonMoveAvoidReturn(&gEnemyParty[firstMonId + i], gFacilityTrainerMons[monSetId].moves[j], j);

        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

static void FillFactoryTentTrainerParty(u16 trainerId, u8 firstMonId)
{
    u8 i, j;
    u8 friendship;
    u8 level = 30;
    u8 fixedIV = 0;
    u32 otID = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < 3; i++)
    {
        u16 monSetId = gUnknown_03006298[i];
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[firstMonId + i],
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otID);

        friendship = 0;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveAvoidReturn(&gEnemyParty[firstMonId + i], gFacilityTrainerMons[monSetId].moves[j], j);
            if (gFacilityTrainerMons[monSetId].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }

        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[firstMonId + i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

void FrontierSpeechToString(const u16 *words)
{
    ConvertEasyChatWordsToString(gStringVar4, words, 3, 2);
    if (GetStringWidth(1, gStringVar4, -1) > 204u)
    {
        s32 i = 0;

        ConvertEasyChatWordsToString(gStringVar4, words, 2, 3);
        while (gStringVar4[i++] != CHAR_NEWLINE)
            ;
        while (gStringVar4[i] != CHAR_NEWLINE)
            i++;

        gStringVar4[i] = CHAR_PROMPT_SCROLL;
    }
}

static void sub_8163914(void)
{
    u16 trainerId;
    SetFacilityPtrsGetLevel();

    if (gSpecialVar_0x8005)
        trainerId = gTrainerBattleOpponent_B;
    else
        trainerId = gTrainerBattleOpponent_A;

    if (trainerId == TRAINER_EREADER)
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].greeting);
    else
        CopyFriendsApprenticeChallengeText(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
}

static void HandleSpecialTrainerBattleEnd(void)
{
    s32 i;

    RecordedBattle_SaveBattleOutcome();
    switch (gBattleScripting.specialTrainerBattleType)
    {
    case SPECIAL_BATTLE_TOWER:
    case SPECIAL_BATTLE_DOME:
    case SPECIAL_BATTLE_PALACE:
    case SPECIAL_BATTLE_ARENA:
    case SPECIAL_BATTLE_FACTORY:
    case SPECIAL_BATTLE_PIKE_SINGLE:
    case SPECIAL_BATTLE_PIKE_DOUBLE:
    case SPECIAL_BATTLE_PYRAMID:
        if (gSaveBlock2Ptr->frontier.battlesCount < 0xFFFFFF)
        {
            gSaveBlock2Ptr->frontier.battlesCount++;
            if (gSaveBlock2Ptr->frontier.battlesCount % 20 == 0)
                UpdateGymLeaderRematch();
        }
        else
        {
            gSaveBlock2Ptr->frontier.battlesCount = 0xFFFFFF;
        }
        break;
    case SPECIAL_BATTLE_SECRET_BASE:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 itemBefore = GetMonData(&gSaveBlock1Ptr->playerParty[i], MON_DATA_HELD_ITEM);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &itemBefore);
        }
        break;
    case SPECIAL_BATTLE_EREADER:
        CopyEReaderTrainerFarewellMessage();
        break;
    case SPECIAL_BATTLE_MULTI:
        for (i = 0; i < 3; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
                gSaveBlock1Ptr->playerParty[i] = gPlayerParty[i];
        }
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_StartBattleAfterTransition(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = HandleSpecialTrainerBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

void DoSpecialTrainerBattle(void)
{
    s32 i;

    gBattleScripting.specialTrainerBattleType = gSpecialVar_0x8004;
    switch (gSpecialVar_0x8004)
    {
    case SPECIAL_BATTLE_TOWER:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
        {
        case FRONTIER_MODE_SINGLES:
            FillFrontierTrainerParty(3);
            break;
        case FRONTIER_MODE_DOUBLES:
            FillFrontierTrainerParty(4);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
            break;
        case FRONTIER_MODE_MULTIS:
            FillFrontierTrainersParties(2);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.trainerIds[17];
            FillPartnerParty(gPartnerTrainerId);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
            break;
        case FRONTIER_MODE_LINK_MULTIS:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_MULTI | BATTLE_TYPE_x800000;
            FillFrontierTrainersParties(2);
            break;
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(0));
        break;
    case SPECIAL_BATTLE_SECRET_BASE:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 itemBefore = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
            SetMonData(&gSaveBlock1Ptr->playerParty[i], MON_DATA_HELD_ITEM, &itemBefore);
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(12));
        break;
    case SPECIAL_BATTLE_EREADER:
        ZeroEnemyPartyMons();
        for (i = 0; i < 3; i++)
            CreateBattleTowerMon(&gEnemyParty[i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i]);
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_EREADER_TRAINER;
        gTrainerBattleOpponent_A = 0;
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(13));
        break;
    case SPECIAL_BATTLE_DOME:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOME;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            FillFrontierTrainerParty(2);
        CreateTask(Task_StartBattleAfterTransition, 1);
        sub_806E694(0);
        BattleTransition_StartOnField(sub_80B100C(3));
        break;
    case SPECIAL_BATTLE_PALACE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
            FillFrontierTrainerParty(3);
        else
            FillTentTrainerParty(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(4));
        break;
    case SPECIAL_BATTLE_ARENA:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_ARENA;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
            FillFrontierTrainerParty(3);
        else
            FillTentTrainerParty(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(5));
        break;
    case SPECIAL_BATTLE_FACTORY:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_FACTORY;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        FillFactoryTrainerParty();
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(6));
        break;
    case SPECIAL_BATTLE_PIKE_SINGLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        FillFrontierTrainerParty(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(7));
        break;
    case SPECIAL_BATTLE_PYRAMID:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID;
        FillFrontierTrainerParty(3);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(10));
        break;
    case SPECIAL_BATTLE_PIKE_DOUBLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        FillFrontierTrainersParties(1);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(sub_80B100C(7));
        break;
    case SPECIAL_BATTLE_STEVEN:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        FillPartnerParty(TRAINER_STEVEN_PARTNER);
        gApproachingTrainerId = 0;
        BattleSetup_ConfigureTrainerBattle(MossdeepCity_SpaceCenter_2F_EventScript_224157 + 1);
        gApproachingTrainerId = 1;
        BattleSetup_ConfigureTrainerBattle(MossdeepCity_SpaceCenter_2F_EventScript_224166 + 1);
        gPartnerTrainerId = TRAINER_STEVEN_PARTNER;
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(B_TRANSITION_MAGMA);
        break;
    case SPECIAL_BATTLE_MULTI:
        if (gSpecialVar_0x8005 & 1) // Player + AI against wild mon
        {
            gBattleTypeFlags = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        }
        else if (gSpecialVar_0x8005 & 2) // Player + AI against one trainer
        {
            gTrainerBattleOpponent_B = 0xFFFF;
            gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        }
        else
        {
            gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER;
        }

        gPartnerSpriteId = gSpecialVar_0x8007;
        FillPartnerParty(gSpecialVar_0x8006 + TRAINER_CUSTOM_PARTNER);
        gPartnerTrainerId = gSpecialVar_0x8006 + TRAINER_CUSTOM_PARTNER;
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        if (gSpecialVar_0x8005 & 1)
            BattleTransition_StartOnField(GetWildBattleTransition());
        else
            BattleTransition_StartOnField(GetTrainerBattleTransition());

        if (gSpecialVar_0x8005 & 0x80) // Skip mons restoring(done in the script)
            gBattleScripting.specialTrainerBattleType = 0xFF;
        break;
    }
}

static void SaveCurrentWinStreak(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);

    if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] < winStreak)
        gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = winStreak;
}

static void sub_8163EE4(void)
{
    s32 i;
    u8 lvlMode, battleMode, class;
    struct EmeraldBattleTowerRecord *playerRecord = &gSaveBlock2Ptr->frontier.towerPlayer;

    ClearBattleTowerRecord(playerRecord);
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        class = gTowerFemaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] +
                                       gSaveBlock2Ptr->playerTrainerId[1] +
                                       gSaveBlock2Ptr->playerTrainerId[2] +
                                       gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerFemaleFacilityClasses)];
    }
    else
    {
        class = gTowerMaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] +
                                     gSaveBlock2Ptr->playerTrainerId[1] +
                                     gSaveBlock2Ptr->playerTrainerId[2] +
                                     gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerMaleFacilityClasses)];
    }
    playerRecord->lvlMode = lvlMode;
    playerRecord->facilityClass = class;
    CopyTrainerId(playerRecord->trainerId, gSaveBlock2Ptr->playerTrainerId);
    StringCopy7(playerRecord->name, gSaveBlock2Ptr->playerName);
    playerRecord->winStreak = GetCurrentBattleTowerWinStreak(lvlMode, battleMode);

    for (i = 0; i < 6; i++)
    {
        playerRecord->greeting[i] = gSaveBlock1Ptr->easyChatBattleStart[i];
        playerRecord->speechWon[i] = gSaveBlock1Ptr->easyChatBattleWon[i];
        playerRecord->speechLost[i] = gSaveBlock1Ptr->easyChatBattleLost[i];
    }

    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] != 0)
            sub_80686FC(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], &playerRecord->party[i]);
    }

    playerRecord->language = gGameLanguage;
    CalcEmeraldBattleTowerChecksum(&gSaveBlock2Ptr->frontier.towerPlayer);
    SaveCurrentWinStreak();
}

static void SaveBattleTowerProgress(void)
{
    u16 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 challengeNum = (signed)(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7);

    if (gSpecialVar_0x8005 == 0 && (challengeNum > 1 || gSaveBlock2Ptr->frontier.curChallengeBattleNum != 0))
        sub_8163EE4();

    gSaveBlock2Ptr->frontier.field_CA8 =gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

static void nullsub_61(void)
{

}

static void SpriteCB_Null6(void)
{

}

static void sub_81640E0(u16 trainerId)
{
    s32 i, count;
    u32 validSpecies[3];
    u16 species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    u16 species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);

    count = 0;
    for (i = 0; i < 3; i++)
    {
        u16 apprenticeSpecies = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].party[i].species;
        if (apprenticeSpecies != species1 && apprenticeSpecies != species2)
        {
            validSpecies[count] = i;
            count++;
        }
    }

    gUnknown_03006298[0] = validSpecies[Random() % count];
    do
    {
        gUnknown_03006298[1] = validSpecies[Random() % count];
    } while (gUnknown_03006298[0] == gUnknown_03006298[1]);
}

static void sub_8164188(u16 trainerId)
{
    s32 i, count;
    u32 validSpecies[3];
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    u16 species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);

    count = 0;
    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[i].species != species1
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[i].species != species2
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[i].level <= GetFrontierEnemyMonLevel(lvlMode)
            && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[i].species != 0)
        {
            validSpecies[count] = i;
            count++;
        }
    }

    gUnknown_03006298[2] = validSpecies[Random() % count];
    do
    {
        gUnknown_03006298[3] = validSpecies[Random() % count];
    } while (gUnknown_03006298[2] == gUnknown_03006298[3]);
}

static void sub_81642A0(void)
{
    s32 i, j, k;
    u32 spArray[5];
    s32 r10;
    u16 trainerId;
    u16 monSetId;
    u32 lvlMode, battleMode;
    s32 challengeNum;
    u32 species1, species2;
    u32 level;
    struct EventObjectTemplate *eventObjTemplates;

    eventObjTemplates = gSaveBlock1Ptr->eventObjectTemplates;
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7;
    species1 = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES, NULL);
    species2 = GetMonData(&gPlayerParty[1], MON_DATA_SPECIES, NULL);
    level = SetFacilityPtrsGetLevel();

    j = 0;
    do
    {
        do
        {
            trainerId = sub_8162548(challengeNum, 0);
            for (i = 0; i < j; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
                if (gFacilityTrainers[gSaveBlock2Ptr->frontier.trainerIds[i]].facilityClass == gFacilityTrainers[trainerId].facilityClass)
                    break;
            }
        } while (i != j);
        gSaveBlock2Ptr->frontier.trainerIds[j] = trainerId;
        j++;
    } while (j < 6);

    r10 = 8;
    for (i = 0; i < 6; i++)
    {
        trainerId = gSaveBlock2Ptr->frontier.trainerIds[i];
        eventObjTemplates[i + 1].graphicsId = GetBattleFacilityTrainerGfxId(trainerId);
        for (j = 0; j < 2; j++)
        {
            while (1)
            {
                monSetId = RandomizeFacilityTrainerMonSet(trainerId);
                if (j % 2 != 0 && gFacilityTrainerMons[gSaveBlock2Ptr->frontier.trainerIds[r10 - 1]].itemTableId == gFacilityTrainerMons[monSetId].itemTableId)
                    continue;

                for (k = 8; k < r10; k++)
                {
                    if (gFacilityTrainerMons[gSaveBlock2Ptr->frontier.trainerIds[k]].species == gFacilityTrainerMons[monSetId].species)
                        break;
                    if (species1 == gFacilityTrainerMons[monSetId].species)
                        break;
                    if (species2 == gFacilityTrainerMons[monSetId].species)
                        break;
                }
                if (k == r10)
                    break;
            }

            gSaveBlock2Ptr->frontier.trainerIds[r10] = monSetId;
            r10++;
        }
    }

    r10 = 0;
    ValidateApprenticesChecksums();
    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->apprentices[i].lvlMode != 0
            && gUnknown_085DF9EC[gSaveBlock2Ptr->apprentices[i].field_1] / 7 <= challengeNum
            && gSaveBlock2Ptr->apprentices[i].lvlMode - 1 == lvlMode)
        {
            k = 0;
            for (j = 0; j < 3; j++)
            {
                if (species1 != gSaveBlock2Ptr->apprentices[i].party[j].species
                    && species2 != gSaveBlock2Ptr->apprentices[i].party[j].species)
                {
                    k++;
                }
            }
            if (k > 2)
            {
                spArray[r10] = i + TRAINER_RECORD_MIXING_APPRENTICE;
                r10++;
            }
        }
    }
    if (r10 != 0)
    {
        gSaveBlock2Ptr->frontier.trainerIds[6] = spArray[Random() % r10];
        eventObjTemplates[7].graphicsId = GetBattleFacilityTrainerGfxId(gSaveBlock2Ptr->frontier.trainerIds[6]);
        FlagClear(FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1);
        sub_81640E0(gSaveBlock2Ptr->frontier.trainerIds[6]);
    }

    r10 = 0;
    for (i = 0; i < 5; i++)
    {
        u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[i]);
        u32 recordHasData = 0;
        u32 checksum = 0;
        for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
        {
            recordHasData |= record[j];
            checksum += record[j];
        }

        if (gSaveBlock2Ptr->frontier.towerRecords[i].winStreak / 7 <= challengeNum
            && gSaveBlock2Ptr->frontier.towerRecords[i].lvlMode == lvlMode
            && recordHasData
            && gSaveBlock2Ptr->frontier.towerRecords[i].checksum == checksum)
        {
            k = 0;
            for (j = 0; j < 4; j++)
            {
                if (species1 != gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species
                    && species2 != gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species
                    && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].level <= GetFrontierEnemyMonLevel(lvlMode)
                    && gSaveBlock2Ptr->frontier.towerRecords[i].party[j].species != 0)
                {
                    k++;
                }
            }
            if (k > 1)
            {
                spArray[r10] = i + TRAINER_RECORD_MIXING_FRIEND;
                r10++;
            }
        }
    }
    if (r10 != 0)
    {
        gSaveBlock2Ptr->frontier.trainerIds[7] = spArray[Random() % r10];
        eventObjTemplates[8].graphicsId = GetBattleFacilityTrainerGfxId(gSaveBlock2Ptr->frontier.trainerIds[7]);
        FlagClear(FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2);
        sub_8164188(gSaveBlock2Ptr->frontier.trainerIds[7]);
    }
}

static void sub_81646BC(u16 trainerId, u16 monSetId)
{
    u16 move = 0;
    u16 species = 0;
    SetFacilityPtrsGetLevel();

    if (trainerId != TRAINER_EREADER)
    {
        if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        {
            move = gFacilityTrainerMons[monSetId].moves[0];
            species = gFacilityTrainerMons[monSetId].species;
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            move = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[gUnknown_03006298[gSpecialVar_0x8005 + 1]].moves[0];
            species = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[gUnknown_03006298[gSpecialVar_0x8005 + 1]].species;
        }
        else
        {
            s32 i;

            move = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].party[gUnknown_03006298[gSpecialVar_0x8005 - 1]].moves[0];
            species = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].party[gUnknown_03006298[gSpecialVar_0x8005 - 1]].species;
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                gStringVar3[i] = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].playerName[i];
            gStringVar3[i] = EOS;
            ConvertInternationalString(gStringVar3, gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].language);
        }
    }

    StringCopy(gStringVar1, gMoveNames[move]);
    StringCopy(gStringVar2, gSpeciesNames[species]);
}

static void sub_8164828(void)
{
    s32 i, j, arrId;
    s32 monSetId;
    s32 level = SetFacilityPtrsGetLevel();
    u16 winStreak = GetCurrentFacilityWinStreak();
    s32 challengeNum = winStreak / 7;
    s32 k = gSpecialVar_LastTalked - 2;
    s32 trainerId = gSaveBlock2Ptr->frontier.trainerIds[k];

    for (arrId = 0; arrId < ARRAY_COUNT(gUnknown_085DD500); arrId++)
    {
        if (gUnknown_085DD500[arrId].facilityClass == GetFrontierTrainerFacilityClass(trainerId))
            break;
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
        if (trainerId == TRAINER_EREADER)
            return;
        if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        {
            GetFrontierTrainerName(gStringVar1, trainerId);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            GetFrontierTrainerName(gStringVar1, trainerId);
        }
        else
        {
            s32 i;
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                gStringVar1[i] = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].playerName[i];
            gStringVar1[i] = EOS;
            ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].language);
            ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].number, STR_CONV_MODE_LEFT_ALIGN, 3);
            GetFrontierTrainerName(gStringVar3, trainerId);
        }
        break;
    case 1:
        monSetId = gSaveBlock2Ptr->frontier.trainerIds[8 + k * 2];
        sub_81646BC(trainerId, monSetId);
        break;
    case 2:
        monSetId = gSaveBlock2Ptr->frontier.trainerIds[9 + k * 2];
        sub_81646BC(trainerId, monSetId);
        break;
    case 3:
        gPartnerTrainerId = trainerId;
        if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        {
            gSaveBlock2Ptr->frontier.trainerIds[18] = gSaveBlock2Ptr->frontier.trainerIds[8 + k * 2];
            gSaveBlock2Ptr->frontier.trainerIds[19] = gSaveBlock2Ptr->frontier.trainerIds[9 + k * 2];
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            gSaveBlock2Ptr->frontier.trainerIds[18] = gUnknown_03006298[2];
            gSaveBlock2Ptr->frontier.trainerIds[19] = gUnknown_03006298[3];
        }
        else
        {
            gSaveBlock2Ptr->frontier.trainerIds[18] = gUnknown_03006298[0];
            gSaveBlock2Ptr->frontier.trainerIds[19] = gUnknown_03006298[1];
        }
        for (k = 0; k < 14; k++)
        {
            while (1)
            {
                i = sub_8162548(challengeNum, k / 2);
                if (gPartnerTrainerId == i)
                    continue;

                for (j = 0; j < k; j++)
                {
                    if (gSaveBlock2Ptr->frontier.trainerIds[j] == i)
                        break;
                }
                if (j == k)
                    break;
            }
            gSaveBlock2Ptr->frontier.trainerIds[k] = i;
        }
        gSaveBlock2Ptr->frontier.trainerIds[17] = trainerId;
        break;
    case 4:
        break;
    }

    if (trainerId == TRAINER_EREADER)
        return;

    if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        ShowFieldMessage(gUnknown_085DD500[arrId].strings[gSpecialVar_0x8005]);
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        ShowFieldMessage(gUnknown_085DD500[arrId].strings[gSpecialVar_0x8005]);
    }
    else
    {
        u8 id = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;
        ShowFieldMessage(gUnknown_085DD690[id][gSpecialVar_0x8005]);
    }
}

static void sub_8164B74(void)
{
    s32 challengeNum;
    s32 i, j;
    s32 trainerId = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 battleNum = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    GetMultiplayerId(); // Yet another pointless function call.

    switch (gSpecialVar_Result)
    {
    case 0:
        if (battleMode == FRONTIER_MODE_LINK_MULTIS)
        {
            challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7;
            if (IsLinkTaskFinished())
            {
                SendBlock(bitmask_all_link_players_but_self(), &challengeNum, sizeof(challengeNum));
                gSpecialVar_Result = 1;
            }
        }
        else
        {
            gSpecialVar_Result = 6;
        }
        break;
    case 1:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (gBlockRecvBuffer[0][0] > gBlockRecvBuffer[1][0])
                challengeNum = gBlockRecvBuffer[0][0];
            else
                challengeNum = gBlockRecvBuffer[1][0];
            for (i = 0; i < 14; i++)
            {
                do
                {
                    trainerId = sub_8162548(challengeNum, i / 2);
                    for (j = 0; j < i; j++)
                    {
                        if (gSaveBlock2Ptr->frontier.trainerIds[j] == trainerId)
                            break;
                    }
                } while (i != j);
                if (i == j) // This condition is always true, because of the loop above.
                    gSaveBlock2Ptr->frontier.trainerIds[i] = trainerId;
            }
            gSpecialVar_Result = 2;
        }
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            SendBlock(bitmask_all_link_players_but_self(), &gSaveBlock2Ptr->frontier.trainerIds, sizeof(gSaveBlock2Ptr->frontier.trainerIds));
            gSpecialVar_Result = 3;
        }
        break;
    case 3:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            memcpy(&gSaveBlock2Ptr->frontier.trainerIds, gBlockRecvBuffer, sizeof(gSaveBlock2Ptr->frontier.trainerIds));
            gTrainerBattleOpponent_A = gSaveBlock2Ptr->frontier.trainerIds[battleNum * 2];
            gTrainerBattleOpponent_B = gSaveBlock2Ptr->frontier.trainerIds[battleNum * 2 + 1];
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
            SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_B, 1);
            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType == 0)
                gSpecialVar_Result = 4;
            else
                gSpecialVar_Result = 6;
        }
        break;
    case 4:
        sub_800AC34();
        gSpecialVar_Result = 5;
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            gSpecialVar_Result = 6;
        }
        break;
    case 6:
        return;
    }
}

static void sub_8164DCC(void)
{
    if (gWirelessCommType != 0)
        sub_800AC34();
}

static void sub_8164DE4(void)
{
    SetBattleFacilityTrainerGfxId(gSaveBlock2Ptr->frontier.trainerIds[17], 0xF);
}

static void sub_8164E04(void)
{
    s32 i;
    u8 text[32];

    if (VarGet(VAR_FRONTIER_BATTLE_MODE) != FRONTIER_MODE_SINGLES)
        return;

    GetFrontierTrainerName(text, gTrainerBattleOpponent_A);
    StripExtCtrlCodes(text);
    StringCopy(gSaveBlock2Ptr->frontier.field_BD8, text);
    GetBattleTowerTrainerLanguage(&gSaveBlock2Ptr->frontier.field_BEB, gTrainerBattleOpponent_A);
    gSaveBlock2Ptr->frontier.field_BD6 = GetMonData(&gEnemyParty[gBattlerPartyIndexes[1]], MON_DATA_SPECIES, NULL);
    gSaveBlock2Ptr->frontier.field_BD4 = GetMonData(&gPlayerParty[gBattlerPartyIndexes[0]], MON_DATA_SPECIES, NULL);
    for (i = 0; i < POKEMON_NAME_LENGTH + 1; i++)
        gSaveBlock2Ptr->frontier.field_BE0[i] = gBattleMons[0].nickname[i];
    gSaveBlock2Ptr->frontier.field_D06 = gBattleOutcome;
}

static void ValidateBattleTowerRecordChecksums(void)
{
    s32 i, j;
    u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerPlayer);
    u32 checksum = 0;

    for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
    {
        checksum += record[j];
    }
    if (gSaveBlock2Ptr->frontier.towerPlayer.checksum != checksum)
        ClearBattleTowerRecord(&gSaveBlock2Ptr->frontier.towerPlayer);

    for (i = 0; i < 5; i++)
    {
        record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[i]);
        checksum = 0;
        for (j = 0; j < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; j++) // - 4, because of the last field being the checksum itself.
        {
            checksum += record[j];
        }
        if (gSaveBlock2Ptr->frontier.towerRecords[i].checksum != checksum)
            ClearBattleTowerRecord(&gSaveBlock2Ptr->frontier.towerRecords[i]);
    }
}

void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *record)
{
    u32 i;

    record->checksum = 0;
    for (i = 0; i < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; i++) // - 4, because of the last field being the checksum itself.
        record->checksum += ((u32 *)record)[i];
}

void CalcRubyBattleTowerChecksum(struct RSBattleTowerRecord *record)
{
    u32 i;

    record->checksum = 0;
    for (i = 0; i < (sizeof(struct RSBattleTowerRecord) - 4) / 4; i++) // - 4, because of the last field being the checksum itself.
        record->checksum += ((u32 *)record)[i];
}

static void ClearBattleTowerRecord(struct EmeraldBattleTowerRecord *record)
{
    u32 i;

    for (i = 0; i < sizeof(struct EmeraldBattleTowerRecord) / 4; i++)
        ((u32 *)record)[i] = 0;
}

u16 GetCurrentBattleTowerWinStreak(u8 lvlMode, u8 battleMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];

    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static u8 GetMonCountForBattleMode(u8 battleMode)
{
    u8 sp[ARRAY_COUNT(gUnknown_085DFA42)];
    memcpy(sp, gUnknown_085DFA42, sizeof(gUnknown_085DFA42));

    if (battleMode < ARRAY_COUNT(gUnknown_085DFA42))
        return sp[battleMode];
    else
        return 3;
}

struct RibbonCounter
{
    u8 partyIndex;
    u8 count;
};

static void AwardBattleTowerRibbons(void)
{
    s32 i;
    u32 partyIndex;
    struct RibbonCounter ribbons[3]; // BUG: 4 Pokemon can receive ribbons in a double battle mode.
    u8 ribbonType = 0;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 monCount = GetMonCountForBattleMode(battleMode);

    if (lvlMode != FRONTIER_LVL_50)
        ribbonType = MON_DATA_VICTORY_RIBBON;
    else
        ribbonType = MON_DATA_WINNING_RIBBON;

    gSpecialVar_Result = FALSE;

    if (GetCurrentBattleTowerWinStreak(lvlMode, battleMode) > 55)
    {
        for (i = 0; i < monCount; i++)
        {
            partyIndex = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
            ribbons[i].partyIndex = partyIndex;
            ribbons[i].count = 0;
            if (!GetMonData(&gSaveBlock1Ptr->playerParty[partyIndex], ribbonType))
            {
                gSpecialVar_Result = TRUE;
                SetMonData(&gSaveBlock1Ptr->playerParty[partyIndex], ribbonType, &gSpecialVar_Result);
                ribbons[i].count = GetRibbonCount(&gSaveBlock1Ptr->playerParty[partyIndex]);
            }
        }
    }

    if (gSpecialVar_Result)
    {
        IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
        for (i = 1; i < monCount; i++)
        {
            if (ribbons[i].count > ribbons[0].count)
            {
                struct RibbonCounter prevBest = ribbons[0];
                ribbons[0] = ribbons[i];
                ribbons[i] = prevBest;
            }
        }
        if (ribbons[0].count > 4)
        {
            sub_80EE4DC(&gSaveBlock1Ptr->playerParty[ribbons[0].partyIndex], ribbonType);
        }
    }
}

// This is a leftover debugging function that is used to populate the E-Reader
// trainer with the player's current data.
static void FillEReaderTrainerWithPlayerData(void)
{
    struct BattleTowerEReaderTrainer *ereaderTrainer = &gSaveBlock2Ptr->frontier.ereaderTrainer;
    s32 i, j;

    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        ereaderTrainer->facilityClass = gTowerFemaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] + gSaveBlock2Ptr->playerTrainerId[1]
                                                        + gSaveBlock2Ptr->playerTrainerId[2] + gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerFemaleFacilityClasses)];
    }
    else
    {
        ereaderTrainer->facilityClass = gTowerMaleFacilityClasses[(gSaveBlock2Ptr->playerTrainerId[0] + gSaveBlock2Ptr->playerTrainerId[1]
                                                        + gSaveBlock2Ptr->playerTrainerId[2] + gSaveBlock2Ptr->playerTrainerId[3]) % ARRAY_COUNT(gTowerMaleFacilityClasses)];
    }

    CopyTrainerId(ereaderTrainer->trainerId, gSaveBlock2Ptr->playerTrainerId);
    StringCopy7(ereaderTrainer->name, gSaveBlock2Ptr->playerName);

    ereaderTrainer->winStreak = 1;

    j = 7;
    for (i = 0; i < 6; i++)
    {
        ereaderTrainer->greeting[i] = gSaveBlock1Ptr->easyChatBattleStart[i];
        ereaderTrainer->farewellPlayerLost[i] = j;
        ereaderTrainer->farewellPlayerWon[i] = j + 6;
        j++;
    }

    for (i = 0; i < 3; i++)
        sub_80686FC(&gPlayerParty[i], &ereaderTrainer->party[i]);

    SetEReaderTrainerChecksum(ereaderTrainer);
}

u8 GetEreaderTrainerFrontSpriteId(void)
{
    return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
}

u8 GetEreaderTrainerClassId(void)
{
    return gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
}

void GetEreaderTrainerName(u8 *dst)
{
    s32 i;

    for (i = 0; i < 5; i++)
        dst[i] = gSaveBlock2Ptr->frontier.ereaderTrainer.name[i];

    dst[i] = EOS;
}

// Checks if the saved E-Reader trainer is valid.
void ValidateEReaderTrainer(void)
{
    u32 i;
    u32 checksum;
    struct BattleTowerEReaderTrainer *ereaderTrainer;

    gSpecialVar_Result = FALSE;
    ereaderTrainer = &gSaveBlock2Ptr->frontier.ereaderTrainer;

    checksum = 0;
    for (i = 0; i < (sizeof(struct BattleTowerEReaderTrainer) - 4) / 4; i++) // - 4, because of the last field being the checksum itself.
        checksum |= ((u32 *)ereaderTrainer)[i];

    if (checksum == 0)
    {
        gSpecialVar_Result = TRUE;
        return;
    }

    checksum = 0;
    for (i = 0; i < (sizeof(struct BattleTowerEReaderTrainer) - 4) / 4; i++) // - 4, because of the last field being the checksum itself.
        checksum += ((u32 *)ereaderTrainer)[i];

    if (gSaveBlock2Ptr->frontier.ereaderTrainer.checksum != checksum)
    {
        ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);
        gSpecialVar_Result = TRUE;
    }
}

static void SetEReaderTrainerChecksum(struct BattleTowerEReaderTrainer *ereaderTrainer)
{
    s32 i;

    ereaderTrainer->checksum = 0;
    for (i = 0; i < (sizeof(struct BattleTowerEReaderTrainer) - 4) / 4; i++) // - 4, because of the last field being the checksum itself.
        ereaderTrainer->checksum += ((u32 *)ereaderTrainer)[i];
}

void ClearEReaderTrainer(struct BattleTowerEReaderTrainer *ereaderTrainer)
{
    u32 i;

    for (i = 0; i < (sizeof(struct BattleTowerEReaderTrainer)) / 4; i++)
        ((u32 *)ereaderTrainer)[i] = 0;
}

void CopyEReaderTrainerGreeting(void)
{
    FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
}

static void CopyEReaderTrainerFarewellMessage(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
        gStringVar4[0] = EOS;
    else if (gBattleOutcome == B_OUTCOME_WON)
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerWon);
    else
        FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerLost);
}

void sub_81653CC(void)
{
    if (gSaveBlock2Ptr->frontier.field_CA8 == 1)
        sub_80F01B8();
    if (FlagGet(FLAG_CANCEL_BATTLE_ROOM_CHALLENGE) == TRUE)
    {
        sub_80F01B8();
        FlagClear(FLAG_CANCEL_BATTLE_ROOM_CHALLENGE);
    }
}

#define STEVEN_OTID 61226

static void FillPartnerParty(u16 trainerId)
{
    s32 i, j;
    u32 ivs, level;
    u32 friendship;
    u16 monSetId;
    u32 otID;
    u8 trainerName[(PLAYER_NAME_LENGTH * 3) + 1];
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_STEVEN_PARTNER)
    {
        for (i = 0; i < 3; i++)
        {
            do
            {
                j = Random32();
            } while (IsShinyOtIdPersonality(STEVEN_OTID, j) || sStevenMons[i].nature != GetNatureFromPersonality(j));
            CreateMon(&gPlayerParty[3 + i],
                      sStevenMons[i].species,
                      sStevenMons[i].level,
                      sStevenMons[i].fixedIV,
                      TRUE, i, // BUG: personality was stored in the 'j' variable. As a result, Steven's pokemon do not have the intended natures.
                      TRUE, STEVEN_OTID);
            for (j = 0; j < 6; j++)
                SetMonData(&gPlayerParty[3 + i], MON_DATA_HP_EV + j, &sStevenMons[i].evs[j]);
            for (j = 0; j < MAX_MON_MOVES; j++)
                SetMonMoveSlot(&gPlayerParty[3 + i], sStevenMons[i].moves[j], j);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_NAME, gTrainers[TRAINER_STEVEN].trainerName);
            j = MALE;
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_GENDER, &j);
            CalculateMonStats(&gPlayerParty[3 + i]);
        }
    }
    else if (trainerId >= TRAINER_CUSTOM_PARTNER)
    {
        otID = Random32();

        for (i = 0; i < 3; i++)
            ZeroMonData(&gPlayerParty[i + 3]);

        for (i = 0; i < 3 && i < gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].partySize; i++)
        {
            do
            {
                j = Random32();
            } while (IsShinyOtIdPersonality(otID, j));

            switch (gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].partyFlags)
            {
            case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *partyData = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].party.NoItemDefaultMoves;

                CreateMon(&gPlayerParty[i + 3], partyData[i].species, partyData[i].lvl, partyData[i].iv * 31 / 255, TRUE, j, TRUE, otID);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *partyData = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].party.NoItemCustomMoves;

                CreateMon(&gPlayerParty[i + 3], partyData[i].species, partyData[i].lvl, partyData[i].iv * 31 / 255, TRUE, j, TRUE, otID);

                for (j = 0; j < 4; j++)
                {
                    SetMonData(&gPlayerParty[i + 3], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&gPlayerParty[i + 3], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *partyData = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].party.ItemDefaultMoves;

                CreateMon(&gPlayerParty[i + 3], partyData[i].species, partyData[i].lvl, partyData[i].iv * 31 / 255, TRUE, j, TRUE, otID);

                SetMonData(&gPlayerParty[i + 3], MON_DATA_HELD_ITEM, &partyData[i].heldItem);
                break;
            }
            case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *partyData = gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].party.ItemCustomMoves;

                CreateMon(&gPlayerParty[i + 3], partyData[i].species, partyData[i].lvl, partyData[i].iv * 31 / 255, TRUE, j, TRUE, otID);

                SetMonData(&gPlayerParty[i + 3], MON_DATA_HELD_ITEM, &partyData[i].heldItem);

                for (j = 0; j < 4; j++)
                {
                    SetMonData(&gPlayerParty[i + 3], MON_DATA_MOVE1 + j, &partyData[i].moves[j]);
                    SetMonData(&gPlayerParty[i + 3], MON_DATA_PP1 + j, &gBattleMoves[partyData[i].moves[j]].pp);
                }
                break;
            }
            }

            StringCopy(trainerName, gTrainers[trainerId - TRAINER_CUSTOM_PARTNER].trainerName);
            SetMonData(&gPlayerParty[i + 3], MON_DATA_OT_NAME, trainerName);
        }
    }
    else if (trainerId == TRAINER_EREADER)
    {
        // Scrapped, lol.
        trainerName[0] = gGameLanguage;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        level = SetFacilityPtrsGetLevel();
        ivs = GetFrontierTrainerFixedIvs(trainerId);
        otID = Random32();
        for (i = 0; i < 2; i++)
        {
            monSetId = gSaveBlock2Ptr->frontier.trainerIds[i + 18];
            CreateMonWithEVSpreadNatureOTID(&gPlayerParty[3 + i],
                                                 gFacilityTrainerMons[monSetId].species,
                                                 level,
                                                 gFacilityTrainerMons[monSetId].nature,
                                                 ivs,
                                                 gFacilityTrainerMons[monSetId].evSpread,
                                                 otID);
            friendship = 0xFF;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                SetMonMoveSlot(&gPlayerParty[3 + i], gFacilityTrainerMons[monSetId].moves[j], j);
                if (gFacilityTrainerMons[monSetId].moves[j] == MOVE_FRUSTRATION)
                    friendship = 0;
            }
            SetMonData(&gPlayerParty[3 + i], MON_DATA_FRIENDSHIP, &friendship);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
            for (j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
                trainerName[j] = gFacilityTrainers[trainerId].trainerName[j];
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_NAME, &trainerName);
            j = IsFrontierTrainerFemale(trainerId);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_GENDER, &j);
        }
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        trainerId -= TRAINER_RECORD_MIXING_FRIEND;
        for (i = 0; i < 2; i++)
        {
            struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[trainerId];
            struct BattleTowerPokemon monData = record->party[gSaveBlock2Ptr->frontier.trainerIds[18 + i]];
            StringCopy(trainerName, record->name);
            if (record->language == LANGUAGE_JAPANESE)
            {
                if (monData.nickname[0] != EXT_CTRL_CODE_BEGIN || monData.nickname[1] != EXT_CTRL_CODE_JPN)
                {
                    monData.nickname[5] = EOS;
                    ConvertInternationalString(monData.nickname, LANGUAGE_JAPANESE);
                }
            }
            else
            {
                if (monData.nickname[0] == EXT_CTRL_CODE_BEGIN && monData.nickname[1] == EXT_CTRL_CODE_JPN)
                    trainerName[5] = EOS;
            }
            CreateBattleTowerMon2(&gPlayerParty[3 + i], &monData, TRUE);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_NAME, trainerName);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_FRIEND);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_GENDER, &j);
        }
    }
    else
    {
        trainerId -= TRAINER_RECORD_MIXING_APPRENTICE;
        for (i = 0; i < 2; i++)
        {
            CreateApprenticeMon(&gPlayerParty[3 + i], &gSaveBlock2Ptr->apprentices[trainerId], gSaveBlock2Ptr->frontier.trainerIds[18 + i]);
            j = IsFrontierTrainerFemale(trainerId + TRAINER_RECORD_MIXING_APPRENTICE);
            SetMonData(&gPlayerParty[3 + i], MON_DATA_OT_GENDER, &j);
        }
    }
}

bool32 RubyBattleTowerRecordToEmerald(struct RSBattleTowerRecord *src, struct EmeraldBattleTowerRecord *dst)
{
    s32 i, validMons = 0;

    for (i = 0; i < 3; i++)
    {
        if (src->party[i].species)
            validMons++;
    }

    if (validMons != 3)
    {
        memset(dst, 0, sizeof(*dst));
        return FALSE;
    }
    else
    {
        dst->lvlMode = src->lvlMode;
        dst->winStreak = src->winStreak;
        // BUG: Reading outside the array. sRubyFacilityClassToEmerald has less than FACILITY_CLASSES_COUNT entries.
        for (i = 0; i < FACILITY_CLASSES_COUNT; i++)
        {
            if (sRubyFacilityClassToEmerald[i][0] == src->facilityClass)
                break;
        }
        if (i != FACILITY_CLASSES_COUNT)
            dst->facilityClass = sRubyFacilityClassToEmerald[i][1];
        else
            dst->facilityClass = FACILITY_CLASS_YOUNGSTER;

        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            dst->name[i] = src->name[i];
        for (i = 0; i < 4; i++)
            dst->trainerId[i] = src->trainerId[i];
        for (i = 0; i < 6; i++)
            dst->greeting[i] = src->greeting[i];
        for (i = 0; i < 6; i++)
            dst->speechWon[i] = gUnknown_085DFA46[i];
        for (i = 0; i < 6; i++)
            dst->speechLost[i] = gUnknown_085DFA52[i];
        for (i = 0; i < 3; i++)
            dst->party[i] = src->party[i];

        CpuFill32(0, &dst->party[3], sizeof(dst->party[3]));
        CalcEmeraldBattleTowerChecksum(dst);
        return TRUE;
    }
}

bool32 EmeraldBattleTowerRecordToRuby(struct EmeraldBattleTowerRecord *src, struct RSBattleTowerRecord *dst)
{
    s32 i, validMons = 0;

    for (i = 0; i < 3; i++)
    {
        if (src->party[i].species)
            validMons++;
    }

    if (validMons != 3)
    {
        memset(dst, 0, sizeof(*dst));
        return FALSE;
    }
    else
    {
        dst->lvlMode = src->lvlMode;
        dst->winStreak = src->winStreak;
        // BUG: Reading outside the array. sRubyFacilityClassToEmerald has less than FACILITY_CLASSES_COUNT entries.
        for (i = 0; i < FACILITY_CLASSES_COUNT; i++)
        {
            if (sRubyFacilityClassToEmerald[i][1] == src->facilityClass)
                break;
        }
        if (i != FACILITY_CLASSES_COUNT)
            dst->facilityClass = sRubyFacilityClassToEmerald[i][0];
        else
            dst->facilityClass = 0x24; // FACILITY_CLASS_YOUNGSTER in Ruby/Sapphire.

        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            dst->name[i] = src->name[i];
        for (i = 0; i < 4; i++)
            dst->trainerId[i] = src->trainerId[i];
        for (i = 0; i < 6; i++)
            dst->greeting[i] = src->greeting[i];
        for (i = 0; i < 3; i++)
            dst->party[i] = src->party[i];

        CalcRubyBattleTowerChecksum(dst);
        return TRUE;
    }
}

void CalcApprenticeChecksum(struct Apprentice *apprentice)
{
    s32 i;

    apprentice->checksum = 0;
    for (i = 0; i < (sizeof(struct Apprentice) - 4) / 4; i++)
        apprentice->checksum += ((u32 *)apprentice)[i];
}

static void ClearApprentice(struct Apprentice *apprentice)
{
    s32 i;

    for (i = 0; i < (sizeof(struct Apprentice)) / 4; i++)
        ((u32 *)apprentice)[i] = 0;
    ResetApprenticeStruct(apprentice);
}

static void ValidateApprenticesChecksums(void)
{
    s32 i, j;

    for (i = 0; i < 4; i++)
    {
        u32 *data = (u32*) &gSaveBlock2Ptr->apprentices[i];
        u32 checksum = 0;
        for (j = 0; j < (sizeof(struct Apprentice) - 4) / 4; j++)
            checksum += data[j];
        if (gSaveBlock2Ptr->apprentices[i].checksum != checksum)
            ClearApprentice(&gSaveBlock2Ptr->apprentices[i]);
    }
}

void GetBattleTowerTrainerLanguage(u8 *dst, u16 trainerId)
{
    if (trainerId == TRAINER_EREADER)
    {
        *dst = gGameLanguage;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
    {
        *dst = gGameLanguage;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            *dst = GetRecordedBattleRecordMixFriendLanguage();
        else
            *dst = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].language;
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            *dst = GetRecordedBattleApprenticeLanguage();
        else
            *dst = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].language;
    }
}

u8 SetFacilityPtrsGetLevel(void)
{
    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        return SetTentPtrsGetLevel();
    }
    else
    {
        gFacilityTrainers = gBattleFrontierTrainers;
        gFacilityTrainerMons = gBattleFrontierMons;
        return GetFrontierEnemyMonLevel(gSaveBlock2Ptr->frontier.lvlMode);
    }
}

u8 GetFrontierEnemyMonLevel(u8 lvlMode)
{
    u8 level;

    switch (lvlMode)
    {
    default:
    case FRONTIER_LVL_50:
        level = 50;
        break;
    case FRONTIER_LVL_OPEN:
        level = GetHighestLevelInPlayerParty();
        if (level < 60)
            level = 60;
        break;
    }

    return level;
}

s32 GetHighestLevelInPlayerParty(void)
{
    s32 highestLevel = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL)
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_EGG)
        {
            s32 level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, NULL);
            if (level > highestLevel)
                highestLevel = level;
        }
    }

    return highestLevel;
}

static u8 GetFrontierTrainerFixedIvs(u16 trainerId)
{
    u8 fixedIV = 0;

    if (trainerId < 100)
        fixedIV = 3;
    else if (trainerId < 120)
        fixedIV = 6;
    else if (trainerId < 140)
        fixedIV = 9;
    else if (trainerId < 160)
        fixedIV = 12;
    else if (trainerId < 180)
        fixedIV = 15;
    else if (trainerId < 200)
        fixedIV = 18;
    else if (trainerId < 220)
        fixedIV = 21;
    else
        fixedIV = 31;

    return fixedIV;
}

static u16 sub_8165D40(void)
{
    u32 facility = VarGet(VAR_FRONTIER_FACILITY);

    if (facility == FRONTIER_FACILITY_PALACE)
        return Random() % 30;
    else if (facility == FRONTIER_FACILITY_ARENA)
        return Random() % 30;
    else if (facility == FRONTIER_FACILITY_FACTORY)
        return Random() % 30;
    else if (facility == FRONTIER_FACILITY_TOWER)
        return 0;
    else
        return 0;
}

static u8 SetTentPtrsGetLevel(void)
{
    u8 level = 30;
    u32 tentFacility = VarGet(VAR_FRONTIER_FACILITY);

    if (tentFacility == TENT_SLATEPORT)
    {
        gFacilityTrainers = gSlateportBattleTentTrainers;
        gFacilityTrainerMons = gSlateportBattleTentMons;
    }
    else if (tentFacility == TENT_VERDANTURF)
    {
        gFacilityTrainers = gVerdanturfBattleTentTrainers;
        gFacilityTrainerMons = gVerdanturfBattleTentMons;
    }
    else if (tentFacility == TENT_FALLARBOR)
    {
        gFacilityTrainers = gFallarborBattleTentTrainers;
        gFacilityTrainerMons = gFallarborBattleTentMons;
    }
    else
    {
        gFacilityTrainers = gBattleFrontierTrainers;
        gFacilityTrainerMons = gBattleFrontierMons;
    }

    level = GetHighestLevelInPlayerParty();
    if (level < 30)
        level = 30;

    return level;
}

static void sub_8165E18(void)
{
    s32 i;
    u16 trainerId;

    do
    {
        trainerId = sub_8165D40();
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_A = trainerId;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum + 1 < 3)
       gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;
}

static void FillTentTrainerParty_(u16 trainerId, u8 firstMonId, u8 monCount)
{
    s32 i, j;
    u16 chosenMonIndices[4];
    u8 friendship;
    u8 level = SetTentPtrsGetLevel();
    u8 fixedIV = 0;
    u8 bfMonCount;
    const u16 *monSets = NULL;
    u32 otID = 0;
    u16 monSetId;

    monSets = gFacilityTrainers[gTrainerBattleOpponent_A].monSets;

    bfMonCount = 0;
    monSetId = monSets[bfMonCount];
    while (monSetId != 0xFFFF)
    {
        bfMonCount++;
        monSetId = monSets[bfMonCount];
        if (monSetId == 0xFFFF)
            break;
    }

    i = 0;
    otID = Random32();
    while (i != monCount)
    {
        u16 monSetId = monSets[Random() % bfMonCount];

        // Ensure this pokemon species isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_SPECIES, NULL) == gFacilityTrainerMons[monSetId].species)
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this Pokemon's held item isn't a duplicate.
        for (j = 0; j < i + firstMonId; j++)
        {
            if (GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) != 0
             && GetMonData(&gEnemyParty[j], MON_DATA_HELD_ITEM, NULL) == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
                break;
        }
        if (j != i + firstMonId)
            continue;

        // Ensure this exact pokemon index isn't a duplicate. This check doesn't seem necessary
        // because the species and held items were already checked directly above.
        for (j = 0; j < i; j++)
        {
            if (chosenMonIndices[j] == monSetId)
                break;
        }
        if (j != i)
            continue;

        chosenMonIndices[i] = monSetId;

        // Place the chosen pokemon into the trainer's party.
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[i + firstMonId],
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otID);

        friendship = 255;
        // Give the chosen pokemon its specified moves.
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[i + firstMonId], gFacilityTrainerMons[monSetId].moves[j], j);
            if (gFacilityTrainerMons[monSetId].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;  // Frustration is more powerful the lower the pokemon's friendship is.
        }

        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i + firstMonId], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);

        // The pokemon was successfully added to the trainer's party, so it's safe to move on to
        // the next party slot.
        i++;
    }
}

u8 FacilityClassToGraphicsId(u8 facilityClass)
{
    u8 trainerObjectGfxId;
    u8 i;

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i] == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        return trainerObjectGfxId;
    }
    else
    {
        return EVENT_OBJ_GFX_BOY_1;
    }
}

bool32 ValidateBattleTowerRecord(u8 recordId) // unused
{
    s32 i;
    u32 *record = (u32*)(&gSaveBlock2Ptr->frontier.towerRecords[recordId]);
    u32 checksum = 0;
    u32 hasData = 0;
    for (i = 0; i < (sizeof(struct EmeraldBattleTowerRecord) - 4) / 4; i++) // - 4, because of the last fjeld bejng the checksum jtself.
    {
        checksum += record[i];
        hasData |= record[i];
    }

    if (checksum == 0 && hasData == 0)
    {
        return FALSE;
    }
    else if (gSaveBlock2Ptr->frontier.towerRecords[recordId].checksum != checksum)
    {
        ClearBattleTowerRecord(&gSaveBlock2Ptr->frontier.towerRecords[recordId]);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void sub_8166188(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
    {
        s32 i;
        u8 enemyLevel = SetFacilityPtrsGetLevel();

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES, NULL);
            if (species)
            {
                SetMonData(&gEnemyParty[i], MON_DATA_EXP, &gExperienceTables[gBaseStats[species].growthRate][enemyLevel]);
                CalculateMonStats(&gEnemyParty[i]);
            }
        }
    }
}
