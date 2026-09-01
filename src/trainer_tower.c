#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "battle_transition.h"
#include "easy_chat.h"
#include "event_data.h"
#include "item.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_tower.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/trainer_tower.h"

#define CURR_FLOOR sTrainerTowerState->data.floors[sTrainerTowerState->floorIdx]
#define TRAINER_TOWER gSaveBlock1Ptr->trainerTower[gSaveBlock1Ptr->towerChallengeId]

struct TrainerTowerOpponent
{
    /* 0x00 */ u8 name[11];
    /* 0x0C */ u16 speechWin[6];
    /* 0x18 */ u16 speechLose[6];
    /* 0x24 */ u16 speechWin2[6];
    /* 0x30 */ u16 speechLose2[6];
    /* 0x3C */ u8 battleType;
    /* 0x3D */ u8 facilityClass;
    /* 0x3E */ u8 textColor;
};

struct SinglesTrainerInfo
{
    u16 objGfx;
    u8 facilityClass;
    bool8 gender;
};

struct DoublesTrainerInfo
{
    u16 objGfx1;
    u16 objGfx2;
    u8 facilityClass;
    bool8 gender1;
    bool8 gender2;
};

struct TrainerEncounterMusicPairs
{
    u8 facilityClass;
    u8 musicId;
};

static EWRAM_DATA struct TrainerTowerState * sTrainerTowerState = NULL;
static EWRAM_DATA struct TrainerTowerOpponent * sTrainerTowerOpponent = NULL;

static void SetUpTrainerTowerDataStruct(void);
static void FreeTrainerTowerDataStruct(void);
static void InitTrainerTowerFloor(void);
static void SetTrainerTowerNPCGraphics(void);
static void TT_ConvertEasyChatMessageToString(u16 *ecWords, u8 *dest);
static void BufferTowerOpponentSpeech(void);
static void TrainerTowerGetOpponentTextColor(u8 battleType, u8 facilityClass);
static void DoTrainerTowerBattle(void);
static void TrainerTowerGetChallengeType(void);
static void TrainerTowerAddFloorCleared(void);
static void GetFloorAlreadyCleared(void);
static void StartTrainerTowerChallenge(void);
static void GetOwnerState(void);
static void GiveChallengePrize(void);
static void CheckFinalTime(void);
static void TrainerTowerResumeTimer(void);
static void TrainerTowerSetPlayerLost(void);
static void GetTrainerTowerChallengeStatus(void);
static void GetCurrentTime(void);
static void ShowResultsBoard(void);
static void CloseResultsBoard(void);
static void TrainerTowerGetDoublesEligiblity(void);
static void TrainerTowerGetNumFloors(void);
static void ShouldWarpToCounter(void);
static void PlayTrainerTowerEncounterMusic(void);
static void HasSpokenToOwner(void);
static void BuildEnemyParty(void);
static s32 GetPartyMaxLevel(void);
static void ValidateOrResetCurTrainerTowerRecord(void);
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
static u32 GetTrainerTowerRecordTime(u32 *);
static void SetTrainerTowerRecordTime(u32 *, u32);
#endif //FREE_TRAINER_TOWER

const u8 gText_XMinYZSec[] = _("{STR_VAR_1}MIN. {STR_VAR_2}.{STR_VAR_3}SEC.");

extern const u8 gText_TimeBoard[];


const u8 *const gTrainerTowerChallengeTypeTexts[NUM_TOWER_CHALLENGE_TYPES] =
{
    gText_Single,
    gText_Double,
    gText_Knockout,
    gText_Mixed
};

static const struct SinglesTrainerInfo sSingleBattleTrainerInfo[] = {
    {OBJ_EVENT_GFX_POKE_MANIAC_FRLG, FACILITY_CLASS_HEX_MANIAC,         MALE},
    {OBJ_EVENT_GFX_BOY,              FACILITY_CLASS_RICH_BOY,           MALE},
    {OBJ_EVENT_GFX_ROCKER,           FACILITY_CLASS_GUITARIST,          MALE},
    {OBJ_EVENT_GFX_ROCKER,           FACILITY_CLASS_KINDLER,            MALE},
    {OBJ_EVENT_GFX_POKE_MANIAC_FRLG, FACILITY_CLASS_BUG_MANIAC,         MALE},
    {OBJ_EVENT_GFX_BOY,              FACILITY_CLASS_SCHOOL_KID_M,       MALE},
    {OBJ_EVENT_GFX_WOMAN_1_FRLG,     FACILITY_CLASS_SCHOOL_KID_F,       FEMALE},
    {OBJ_EVENT_GFX_BALDING_MAN,      FACILITY_CLASS_POKEFAN_M,          MALE},
    {OBJ_EVENT_GFX_WOMAN_3_FRLG,     FACILITY_CLASS_POKEFAN_F,          FEMALE},
    {OBJ_EVENT_GFX_OLD_MAN_1,        FACILITY_CLASS_EXPERT_M,           MALE},
    {OBJ_EVENT_GFX_OLD_WOMAN_FRLG,   FACILITY_CLASS_EXPERT_F,           FEMALE},
    {OBJ_EVENT_GFX_COOLTRAINER_M,    FACILITY_CLASS_DRAGON_TAMER,       MALE},
    {OBJ_EVENT_GFX_LITTLE_BOY_FRLG,  FACILITY_CLASS_NINJA_BOY,          MALE},
    {OBJ_EVENT_GFX_CRUSH_GIRL,       FACILITY_CLASS_BATTLE_GIRL,        FEMALE},
    {OBJ_EVENT_GFX_BEAUTY_FRLG,      FACILITY_CLASS_PARASOL_LADY,       FEMALE},
    {OBJ_EVENT_GFX_FAT_MAN_FRLG,     FACILITY_CLASS_COLLECTOR,          MALE},
    {OBJ_EVENT_GFX_YOUNGSTER_FRLG,   FACILITY_CLASS_YOUNGSTER_FRLG,     MALE},
    {OBJ_EVENT_GFX_BUG_CATCHER_FRLG, FACILITY_CLASS_BUG_CATCHER_FRLG,   MALE},
    {OBJ_EVENT_GFX_LASS_FRLG,        FACILITY_CLASS_LASS_FRLG,          FEMALE},
    {OBJ_EVENT_GFX_SAILOR_FRLG,      FACILITY_CLASS_SAILOR_FRLG,        MALE},
    {OBJ_EVENT_GFX_CAMPER_FRLG,      FACILITY_CLASS_CAMPER_FRLG,        MALE},
    {OBJ_EVENT_GFX_PICNICKER_FRLG,   FACILITY_CLASS_PICNICKER_FRLG,     FEMALE},
    {OBJ_EVENT_GFX_POKE_MANIAC_FRLG, FACILITY_CLASS_POKEMANIAC,         MALE},
    {OBJ_EVENT_GFX_POKE_MANIAC_FRLG, FACILITY_CLASS_SUPER_NERD_FRLG,    MALE},
    {OBJ_EVENT_GFX_HIKER_FRLG,       FACILITY_CLASS_HIKER_FRLG,         MALE},
    {OBJ_EVENT_GFX_BIKER,            FACILITY_CLASS_BIKER_FRLG,         MALE},
    {OBJ_EVENT_GFX_POKE_MANIAC_FRLG, FACILITY_CLASS_BURGLAR_FRLG,       MALE},
    {OBJ_EVENT_GFX_BALDING_MAN,      FACILITY_CLASS_ENGINEER_FRLG,      MALE},
    {OBJ_EVENT_GFX_FISHER,           FACILITY_CLASS_FISHERMAN_FRLG,     MALE},
    {OBJ_EVENT_GFX_SWIMMER_M_LAND,   FACILITY_CLASS_SWIMMER_M_FRLG,     MALE},
    {OBJ_EVENT_GFX_BIKER,            FACILITY_CLASS_CUE_BALL_FRLG,      MALE},
    {OBJ_EVENT_GFX_BEAUTY_FRLG,      FACILITY_CLASS_BEAUTY_FRLG,        FEMALE},
    {OBJ_EVENT_GFX_SWIMMER_F_LAND,   FACILITY_CLASS_SWIMMER_F_FRLG,     FEMALE},
    {OBJ_EVENT_GFX_BOY,              FACILITY_CLASS_PSYCHIC_M_FRLG,     MALE},
    {OBJ_EVENT_GFX_ROCKER,           FACILITY_CLASS_ROCKER_FRLG,        MALE},
    {OBJ_EVENT_GFX_ROCKER,           FACILITY_CLASS_JUGGLER_FRLG,       MALE},
    {OBJ_EVENT_GFX_ROCKER,           FACILITY_CLASS_BIRD_KEEPER,        MALE},
    {OBJ_EVENT_GFX_BLACK_BELT_FRLG,  FACILITY_CLASS_BLACK_BELT_FRLG,    MALE},
    {OBJ_EVENT_GFX_SCIENTIST,        FACILITY_CLASS_SCIENTIST_FRLG,     MALE},
    {OBJ_EVENT_GFX_COOLTRAINER_M,    FACILITY_CLASS_COOLTRAINER_M_FRLG, MALE},
    {OBJ_EVENT_GFX_COOLTRAINER_F,    FACILITY_CLASS_COOLTRAINER_F_FRLG, FEMALE},
    {OBJ_EVENT_GFX_GENTLEMAN,        FACILITY_CLASS_GENTLEMAN_FRLG,     MALE},
    {OBJ_EVENT_GFX_WOMAN_1_FRLG,     FACILITY_CLASS_PSYCHIC_F_FRLG,     FEMALE},
    {OBJ_EVENT_GFX_CRUSH_GIRL,       FACILITY_CLASS_CRUSH_GIRL_FRLG,    FEMALE},
    {OBJ_EVENT_GFX_TUBER_F_FRLG,     FACILITY_CLASS_TUBER_FRLG,         FEMALE},
    {OBJ_EVENT_GFX_WOMAN_2_FRLG,     FACILITY_CLASS_PKMN_BREEDER_FRLG,  FEMALE},
    {OBJ_EVENT_GFX_CAMPER_FRLG,      FACILITY_CLASS_PKMN_RANGER_M_FRLG, MALE},
    {OBJ_EVENT_GFX_PICNICKER_FRLG,   FACILITY_CLASS_PKMN_RANGER_F_FRLG, FEMALE},
    {OBJ_EVENT_GFX_WOMAN_2_FRLG,     FACILITY_CLASS_AROMA_LADY_FRLG,    FEMALE},
    {OBJ_EVENT_GFX_HIKER_FRLG,       FACILITY_CLASS_RUIN_MANIAC,        MALE},
    {OBJ_EVENT_GFX_WOMAN_2_FRLG,     FACILITY_CLASS_LADY_FRLG,          FEMALE}
};

static const struct DoublesTrainerInfo sDoubleBattleTrainerInfo[] = {
    {OBJ_EVENT_GFX_BEAUTY_FRLG,      OBJ_EVENT_GFX_WOMAN_1_FRLG,     FACILITY_CLASS_SR_AND_JR,         FEMALE, FEMALE},
    {OBJ_EVENT_GFX_OLD_MAN_1,        OBJ_EVENT_GFX_OLD_WOMAN_FRLG,   FACILITY_CLASS_OLD_COUPLE,        MALE,   FEMALE},
    {OBJ_EVENT_GFX_LITTLE_GIRL_FRLG, OBJ_EVENT_GFX_LITTLE_GIRL_FRLG, FACILITY_CLASS_TWINS_FRLG,        FEMALE, FEMALE},
    {OBJ_EVENT_GFX_COOLTRAINER_M,    OBJ_EVENT_GFX_COOLTRAINER_F,    FACILITY_CLASS_COOL_COUPLE_FRLG,  MALE,   FEMALE},
    {OBJ_EVENT_GFX_BEAUTY_FRLG,      OBJ_EVENT_GFX_MAN,              FACILITY_CLASS_YOUNG_COUPLE_FRLG, FEMALE, MALE},
    {OBJ_EVENT_GFX_CRUSH_GIRL,       OBJ_EVENT_GFX_BLACK_BELT_FRLG,  FACILITY_CLASS_CRUSH_KIN_FRLG,    FEMALE, MALE},
    {OBJ_EVENT_GFX_SWIMMER_F_LAND,   OBJ_EVENT_GFX_TUBER_M_LAND,     FACILITY_CLASS_SIS_AND_BRO_FRLG,  FEMALE, MALE}
};

static const struct TrainerEncounterMusicPairs sTrainerEncounterMusicLUT[] = {
    {FACILITY_CLASS_AQUA_GRUNT_F,           TRAINER_ENCOUNTER_MUSIC_AQUA},
    {FACILITY_CLASS_RUNNING_TRIATHLETE_F,   TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_LEADER_BRAWLY,          TRAINER_ENCOUNTER_MUSIC_TWINS},
    {FACILITY_CLASS_MAGMA_LEADER_MAXIE,     TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_POKEFAN_F,              TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_PSYCHIC_M_FRLG,         TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_PICNICKER_FRLG,         TRAINER_ENCOUNTER_MUSIC_COOL},
    {FACILITY_CLASS_GUITARIST,              TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_RUNNING_TRIATHLETE_M,   TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_CAMPER_FRLG,            TRAINER_ENCOUNTER_MUSIC_TWINS},
    {FACILITY_CLASS_CYCLING_TRIATHLETE_F,   TRAINER_ENCOUNTER_MUSIC_TWINS},
    {FACILITY_CLASS_BEAUTY_FRLG,            TRAINER_ENCOUNTER_MUSIC_HIKER},
    {FACILITY_CLASS_INTERVIEWER,            TRAINER_ENCOUNTER_MUSIC_HIKER},
    {FACILITY_CLASS_YOUNGSTER_FRLG,         TRAINER_ENCOUNTER_MUSIC_RICH},
    {FACILITY_CLASS_MAGMA_GRUNT_F,          TRAINER_ENCOUNTER_MUSIC_SWIMMER},
    {FACILITY_CLASS_SUPER_NERD_FRLG,        TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_ENGINEER_FRLG,          TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_SAILOR_FRLG,            TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_BUG_MANIAC,             TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_KINDLER,                TRAINER_ENCOUNTER_MUSIC_HIKER},
    {FACILITY_CLASS_BATTLE_GIRL,            TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {FACILITY_CLASS_COLLECTOR,              TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {FACILITY_CLASS_NINJA_BOY,              TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {FACILITY_CLASS_PARASOL_LADY,           TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_EXPERT_F,               TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_RICH_BOY,               TRAINER_ENCOUNTER_MUSIC_RICH},
    {FACILITY_CLASS_HEX_MANIAC,             TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_SWIMMER_F_FRLG,         TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_CYCLING_TRIATHLETE_M,   TRAINER_ENCOUNTER_MUSIC_GIRL},
    {FACILITY_CLASS_SWIMMER_M_FRLG,         TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_DRAGON_TAMER,           TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_BIKER_FRLG,             TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_SWIMMING_TRIATHLETE_M,  TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {FACILITY_CLASS_CUE_BALL_FRLG,          TRAINER_ENCOUNTER_MUSIC_COOL},
    {FACILITY_CLASS_SWIMMING_TRIATHLETE_F,  TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_POKEMANIAC,             TRAINER_ENCOUNTER_MUSIC_GIRL},
    {FACILITY_CLASS_BUG_CATCHER_FRLG,       TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_OLD_COUPLE,             TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_LEADER_ROXANNE,         TRAINER_ENCOUNTER_MUSIC_TWINS},
    {FACILITY_CLASS_BURGLAR_FRLG,           TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_SCHOOL_KID_M,           TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_LEADER_TATE_AND_LIZA,   TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {FACILITY_CLASS_POKEFAN_M,              TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_EXPERT_M,               TRAINER_ENCOUNTER_MUSIC_COOL},
    {FACILITY_CLASS_MAGMA_GRUNT_M,          TRAINER_ENCOUNTER_MUSIC_HIKER},
    {FACILITY_CLASS_SR_AND_JR,              TRAINER_ENCOUNTER_MUSIC_HIKER},
    {FACILITY_CLASS_LASS_FRLG,              TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_SCHOOL_KID_F,           TRAINER_ENCOUNTER_MUSIC_MALE},
    {FACILITY_CLASS_FISHERMAN_FRLG,         TRAINER_ENCOUNTER_MUSIC_GIRL},
    {FACILITY_CLASS_HIKER_FRLG,             TRAINER_ENCOUNTER_MUSIC_SWIMMER},
    {FACILITY_CLASS_ELITE_FOUR_SIDNEY,      TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {FACILITY_CLASS_ELITE_FOUR_PHOEBE,      TRAINER_ENCOUNTER_MUSIC_MALE}
};

static const struct WindowTemplate sTimeBoardWindowTemplate[] = {
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 1,
        .width = 27,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x001
    }, DUMMY_WIN_TEMPLATE
};

static const u32 sUnusedValue = 112;

static const u8 sTextColors[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

static void (*const sTrainerTowerFunctions[])(void) = {
    [TRAINER_TOWER_FUNC_INIT_FLOOR]             = InitTrainerTowerFloor,
    [TRAINER_TOWER_FUNC_GET_SPEECH]             = BufferTowerOpponentSpeech,
    [TRAINER_TOWER_FUNC_DO_BATTLE]              = DoTrainerTowerBattle,
    [TRAINER_TOWER_FUNC_GET_CHALLENGE_TYPE]     = TrainerTowerGetChallengeType,
    [TRAINER_TOWER_FUNC_CLEARED_FLOOR]          = TrainerTowerAddFloorCleared,
    [TRAINER_TOWER_FUNC_GET_FLOOR_CLEARED]      = GetFloorAlreadyCleared,
    [TRAINER_TOWER_FUNC_START_CHALLENGE]        = StartTrainerTowerChallenge,
    [TRAINER_TOWER_FUNC_GET_OWNER_STATE]        = GetOwnerState,
    [TRAINER_TOWER_FUNC_GIVE_PRIZE]             = GiveChallengePrize,
    [TRAINER_TOWER_FUNC_CHECK_FINAL_TIME]       = CheckFinalTime,
    [TRAINER_TOWER_FUNC_RESUME_TIMER]           = TrainerTowerResumeTimer,
    [TRAINER_TOWER_FUNC_SET_LOST]               = TrainerTowerSetPlayerLost,
    [TRAINER_TOWER_FUNC_GET_CHALLENGE_STATUS]   = GetTrainerTowerChallengeStatus,
    [TRAINER_TOWER_FUNC_GET_TIME]               = GetCurrentTime,
    [TRAINER_TOWER_FUNC_SHOW_RESULTS]           = ShowResultsBoard,
    [TRAINER_TOWER_FUNC_CLOSE_RESULTS]          = CloseResultsBoard,
    [TRAINER_TOWER_FUNC_CHECK_DOUBLES]          = TrainerTowerGetDoublesEligiblity,
    [TRAINER_TOWER_FUNC_GET_NUM_FLOORS]         = TrainerTowerGetNumFloors,
    [TRAINER_TOWER_FUNC_SHOULD_WARP_TO_COUNTER] = ShouldWarpToCounter,
    [TRAINER_TOWER_FUNC_ENCOUNTER_MUSIC]        = PlayTrainerTowerEncounterMusic,
    [TRAINER_TOWER_FUNC_GET_BEAT_CHALLENGE]     = HasSpokenToOwner
};

// - 1 excludes Mixed challenge, which just uses one of the 3 other types
static const u16 sFloorLayouts[MAX_TRAINER_TOWER_FLOORS][NUM_TOWER_CHALLENGE_TYPES - 1] = {
    {LAYOUT_TRAINER_TOWER_1F, LAYOUT_TRAINER_TOWER_1F_DOUBLES, LAYOUT_TRAINER_TOWER_1F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_2F, LAYOUT_TRAINER_TOWER_2F_DOUBLES, LAYOUT_TRAINER_TOWER_2F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_3F, LAYOUT_TRAINER_TOWER_3F_DOUBLES, LAYOUT_TRAINER_TOWER_3F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_4F, LAYOUT_TRAINER_TOWER_4F_DOUBLES, LAYOUT_TRAINER_TOWER_4F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_5F, LAYOUT_TRAINER_TOWER_5F_DOUBLES, LAYOUT_TRAINER_TOWER_5F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_6F, LAYOUT_TRAINER_TOWER_6F_DOUBLES, LAYOUT_TRAINER_TOWER_6F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_7F, LAYOUT_TRAINER_TOWER_7F_DOUBLES, LAYOUT_TRAINER_TOWER_7F_KNOCKOUT},
    {LAYOUT_TRAINER_TOWER_8F, LAYOUT_TRAINER_TOWER_8F_DOUBLES, LAYOUT_TRAINER_TOWER_8F_KNOCKOUT}
};

static const u16 sPrizeList[] = {
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CARBOS,
    ITEM_CALCIUM,
    ITEM_ZINC,
    ITEM_BRIGHT_POWDER,
    ITEM_WHITE_HERB,
    ITEM_MENTAL_HERB,
    ITEM_CHOICE_BAND,
    ITEM_KINGS_ROCK,
    ITEM_SCOPE_LENS,
    ITEM_METAL_COAT,
    ITEM_DRAGON_SCALE,
    ITEM_UP_GRADE
};

static const u16 sTrainerTowerEncounterMusic[] = {
    [TRAINER_ENCOUNTER_MUSIC_MALE]        = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_FEMALE]      = MUS_RG_ENCOUNTER_GIRL,
    [TRAINER_ENCOUNTER_MUSIC_GIRL]        = MUS_RG_ENCOUNTER_GIRL,
    [TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS]  = MUS_RG_ENCOUNTER_ROCKET,
    [TRAINER_ENCOUNTER_MUSIC_INTENSE]     = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_COOL]        = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_AQUA]        = MUS_RG_ENCOUNTER_ROCKET,
    [TRAINER_ENCOUNTER_MUSIC_MAGMA]       = MUS_RG_ENCOUNTER_ROCKET,
    [TRAINER_ENCOUNTER_MUSIC_SWIMMER]     = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_TWINS]       = MUS_RG_ENCOUNTER_GIRL,
    [TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR]  = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_HIKER]       = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_INTERVIEWER] = MUS_RG_ENCOUNTER_BOY,
    [TRAINER_ENCOUNTER_MUSIC_RICH]        = MUS_RG_ENCOUNTER_BOY
};

// The trainer only uses two Pokemon from the encoded pool, based on the current floor
static const u8 sSingleBattleChallengeMonIdxs[MAX_TRAINER_TOWER_FLOORS][2] = {
    {0, 2},
    {1, 3},
    {2, 4},
    {3, 5},
    {4, 1},
    {5, 2},
    {0, 3},
    {1, 4}
};

// Each trainer only uses one Pokemon from the encoded pool, based on the current floor
static const u8 sDoubleBattleChallengeMonIdxs[MAX_TRAINER_TOWER_FLOORS][2] = {
    {0, 1},
    {1, 3},
    {2, 0},
    {3, 4},
    {4, 2},
    {5, 2},
    {0, 3},
    {1, 5}
};

// Each trainer only uses one Pokemon from the encoded pool, based on the current floor
static const u8 sKnockoutChallengeMonIdxs[MAX_TRAINER_TOWER_FLOORS][3] = {
    {0, 2, 4},
    {1, 3, 5},
    {2, 3, 1},
    {3, 4, 0},
    {4, 1, 2},
    {5, 0, 3},
    {0, 5, 2},
    {1, 4, 5}
};

extern const struct EReaderTrainerTowerSetSubstruct gTrainerTowerLocalHeader;
extern const struct TrainerTowerFloor *const gTrainerTowerFloors[][MAX_TRAINER_TOWER_FLOORS];

void CallTrainerTowerFunc(void)
{
    SetUpTrainerTowerDataStruct();
    sTrainerTowerFunctions[gSpecialVar_0x8004]();
    FreeTrainerTowerDataStruct();
}

u8 GetTrainerTowerOpponentClass(void)
{
    return gFacilityClassToTrainerClass[sTrainerTowerOpponent->facilityClass];
}

void GetTrainerTowerOpponentName(u8 *dest)
{
    StringCopyN(dest, sTrainerTowerOpponent->name, 11);
}

u8 GetTrainerTowerTrainerFrontSpriteId(void)
{
    return gFacilityClassToPicIndex[sTrainerTowerOpponent->facilityClass];
}

void InitTrainerTowerBattleStruct(void)
{
    u16 trainerId;
    int i;

    SetUpTrainerTowerDataStruct();
    sTrainerTowerOpponent = AllocZeroed(sizeof(*sTrainerTowerOpponent));
    trainerId = VarGet(VAR_TEMP_1);
    StringCopyN(sTrainerTowerOpponent->name, CURR_FLOOR.trainers[trainerId].name, 11);

    for (i = 0; i < 6; i++)
    {
        sTrainerTowerOpponent->speechWin[i] = CURR_FLOOR.trainers[trainerId].speechWin[i];
        sTrainerTowerOpponent->speechLose[i] = CURR_FLOOR.trainers[trainerId].speechLose[i];

        if (CURR_FLOOR.challengeType == CHALLENGE_TYPE_DOUBLE)
        {
            sTrainerTowerOpponent->speechWin2[i] = CURR_FLOOR.trainers[trainerId + 1].speechWin[i];
            sTrainerTowerOpponent->speechLose2[i] = CURR_FLOOR.trainers[trainerId + 1].speechLose[i];
        }
    }

    sTrainerTowerOpponent->battleType = CURR_FLOOR.challengeType;
    sTrainerTowerOpponent->facilityClass = CURR_FLOOR.trainers[trainerId].facilityClass;
    sTrainerTowerOpponent->textColor = CURR_FLOOR.trainers[trainerId].textColor;
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    SetTrainerHillVBlankCounter(&TRAINER_TOWER.timer);
#endif //FREE_TRAINER_TOWER
    FreeTrainerTowerDataStruct();
}

void FreeTrainerTowerBattleStruct(void)
{
    FREE_AND_SET_NULL(sTrainerTowerOpponent);
}

void GetTrainerTowerOpponentWinText(u8 *dest, u8 opponentIdx)
{
    VarSet(VAR_TEMP_3, opponentIdx);
    TrainerTowerGetOpponentTextColor(sTrainerTowerOpponent->battleType, sTrainerTowerOpponent->facilityClass);
    if (opponentIdx == 0)
        TT_ConvertEasyChatMessageToString(sTrainerTowerOpponent->speechWin, dest);
    else
        TT_ConvertEasyChatMessageToString(sTrainerTowerOpponent->speechWin2, dest);
}

void GetTrainerTowerOpponentLoseText(u8 *dest, u8 opponentIdx)
{
    VarSet(VAR_TEMP_3, opponentIdx);
    TrainerTowerGetOpponentTextColor(sTrainerTowerOpponent->battleType, sTrainerTowerOpponent->facilityClass);
    if (opponentIdx == 0)
        TT_ConvertEasyChatMessageToString(sTrainerTowerOpponent->speechLose, dest);
    else
        TT_ConvertEasyChatMessageToString(sTrainerTowerOpponent->speechLose2, dest);
}

static void SetUpTrainerTowerDataStruct(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    u32 challengeType = gSaveBlock1Ptr->towerChallengeId;
#else
    u32 challengeType = CHALLENGE_TYPE_SINGLE;
#endif // FREE_TRAINER_TOWER
    s32 i;
    const struct TrainerTowerFloor *const * floors_p;

    sTrainerTowerState = AllocZeroed(sizeof(*sTrainerTowerState));
    sTrainerTowerState->floorIdx = gMapHeader.mapLayoutId - LAYOUT_TRAINER_TOWER_1F;
    // if (ReadTrainerTowerAndValidate() == TRUE)
    //     CEReaderTool_LoadTrainerTower(&sTrainerTowerState->data);
    // else
    // {
        struct TrainerTowerState * ttstate_p = sTrainerTowerState;
        const struct EReaderTrainerTowerSetSubstruct * header_p = &gTrainerTowerLocalHeader;
        memcpy(&ttstate_p->data, header_p, sizeof(struct EReaderTrainerTowerSetSubstruct));
        floors_p = gTrainerTowerFloors[challengeType];
        for (i = 0; i < MAX_TRAINER_TOWER_FLOORS; i++)
        {
            *(sTrainerTowerState->data.floors + i) = *(floors_p[i]); // manual pointer arithmetic needed to match
        }
        sTrainerTowerState->data.checksum = CalcByteArraySum((void *)sTrainerTowerState->data.floors, sizeof(sTrainerTowerState->data.floors));
        ValidateOrResetCurTrainerTowerRecord();
    // }
}

static void FreeTrainerTowerDataStruct(void)
{
    TRY_FREE_AND_SET_NULL(sTrainerTowerState);
}

static void InitTrainerTowerFloor(void)
{
    if (gMapHeader.mapLayoutId - LAYOUT_TRAINER_TOWER_LOBBY > sTrainerTowerState->data.numFloors)
    {
        gSpecialVar_Result = 3; // Skip past usable challenge types
        SetCurrentMapLayout(LAYOUT_TRAINER_TOWER_ROOF);
    }
    else
    {
        gSpecialVar_Result = CURR_FLOOR.challengeType;
        SetCurrentMapLayout(sFloorLayouts[sTrainerTowerState->floorIdx][gSpecialVar_Result]);
        SetTrainerTowerNPCGraphics();
    }
}

static void SetTrainerTowerNPCGraphics(void)
{
    s32 i, j;
    u16 trainerGfx1, trainerGfx2, facilityClass;
    switch (CURR_FLOOR.challengeType)
    {
    case CHALLENGE_TYPE_SINGLE:
        facilityClass = CURR_FLOOR.trainers[0].facilityClass;
        for (i = 0; i < NELEMS(sSingleBattleTrainerInfo); i++)
        {
            if (sSingleBattleTrainerInfo[i].facilityClass == facilityClass)
                break;
        }

        if (i != NELEMS(sSingleBattleTrainerInfo))
            trainerGfx1 = sSingleBattleTrainerInfo[i].objGfx;
        else
            trainerGfx1 = OBJ_EVENT_GFX_YOUNGSTER_FRLG;

        VarSet(VAR_OBJ_GFX_ID_1, trainerGfx1);
        break;
    case CHALLENGE_TYPE_DOUBLE:
        facilityClass = CURR_FLOOR.trainers[0].facilityClass;
        for (i = 0; i < NELEMS(sDoubleBattleTrainerInfo); i++)
        {
            if (sDoubleBattleTrainerInfo[i].facilityClass == facilityClass)
                break;
        }
        if (i != NELEMS(sDoubleBattleTrainerInfo))
        {
            trainerGfx1  = sDoubleBattleTrainerInfo[i].objGfx1;
            trainerGfx2 = sDoubleBattleTrainerInfo[i].objGfx2;
        }
        else
        {
            trainerGfx1  = OBJ_EVENT_GFX_YOUNGSTER_FRLG;
            trainerGfx2 = OBJ_EVENT_GFX_YOUNGSTER_FRLG;
        }
        VarSet(VAR_OBJ_GFX_ID_0, trainerGfx1);
        VarSet(VAR_OBJ_GFX_ID_3, trainerGfx2);
        break;
    case CHALLENGE_TYPE_KNOCKOUT:
        for (j = 0; j < MAX_TRAINERS_PER_FLOOR; j++)
        {
            facilityClass = CURR_FLOOR.trainers[j].facilityClass;
            for (i = 0; i < NELEMS(sSingleBattleTrainerInfo); i++)
            {
                if (sSingleBattleTrainerInfo[i].facilityClass == facilityClass)
                    break;
            }

            if (i != NELEMS(sSingleBattleTrainerInfo))
                trainerGfx1 = sSingleBattleTrainerInfo[i].objGfx;
            else
                trainerGfx1 = OBJ_EVENT_GFX_YOUNGSTER;

            switch (j)
            {
            case 0:
                VarSet(VAR_OBJ_GFX_ID_2, trainerGfx1);
                break;
            case 1:
                VarSet(VAR_OBJ_GFX_ID_0, trainerGfx1);
                break;
            case 2:
                VarSet(VAR_OBJ_GFX_ID_1, trainerGfx1);
                break;
            }
        }
    }
}

static void TT_ConvertEasyChatMessageToString(u16 *ecWords, u8 *dest)
{
    s32 i;
    ConvertEasyChatWordsToString(dest, ecWords, 3, 2);
    if ((unsigned)GetStringWidth(FONT_NORMAL, dest, -1) > 196)
    {
        // Has to be printed 2x3
        ConvertEasyChatWordsToString(dest, ecWords, 2, 3);
        // Skip line 1
        i = 0;
        while (dest[i++] != CHAR_NEWLINE)
            ;
        // Skip line 2
        while (dest[i] != CHAR_NEWLINE)
            i++;
        // Replace \n with \l at the end of line 2
        dest[i] = CHAR_PROMPT_SCROLL;
    }
}

static void BufferTowerOpponentSpeech(void)
{
    u16 trainerId = gSpecialVar_0x8006;
    u8 facilityClass;
    u8 challengeType = CURR_FLOOR.challengeType;

    if (challengeType != CHALLENGE_TYPE_DOUBLE)
        facilityClass = CURR_FLOOR.trainers[trainerId].facilityClass;
    else
        facilityClass = CURR_FLOOR.trainers[0].facilityClass;

    switch (gSpecialVar_0x8005)
    {
    case TRAINER_TOWER_TEXT_INTRO:
        TrainerTowerGetOpponentTextColor(challengeType, facilityClass);
        TT_ConvertEasyChatMessageToString(CURR_FLOOR.trainers[trainerId].speechBefore, gStringVar4);
        break;
    case TRAINER_TOWER_TEXT_PLAYER_LOST:
        TrainerTowerGetOpponentTextColor(challengeType, facilityClass);
        TT_ConvertEasyChatMessageToString(CURR_FLOOR.trainers[trainerId].speechWin, gStringVar4);
        break;
    case TRAINER_TOWER_TEXT_PLAYER_WON:
        TrainerTowerGetOpponentTextColor(challengeType, facilityClass);
        TT_ConvertEasyChatMessageToString(CURR_FLOOR.trainers[trainerId].speechLose, gStringVar4);
        break;
    case TRAINER_TOWER_TEXT_AFTER:
        TT_ConvertEasyChatMessageToString(CURR_FLOOR.trainers[trainerId].speechAfter, gStringVar4);
        break;
    }
}

static void TrainerTowerGetOpponentTextColor(u8 challengeType, u8 facilityClass)
{
    // u16 gender = MALE;
    // int i;
    // switch (challengeType)
    // {
    // case CHALLENGE_TYPE_SINGLE:
    // case CHALLENGE_TYPE_KNOCKOUT:
    //     for (i = 0; i < NELEMS(sSingleBattleTrainerInfo); i++)
    //     {
    //         if (sSingleBattleTrainerInfo[i].facilityClass == facilityClass)
    //             break;
    //     }
    //     if (i != NELEMS(sSingleBattleTrainerInfo))
    //         gender = sSingleBattleTrainerInfo[i].gender;
    //     break;
    // case CHALLENGE_TYPE_DOUBLE:
    //     for (i = 0; i < NELEMS(sDoubleBattleTrainerInfo); i++)
    //     {
    //         if (sDoubleBattleTrainerInfo[i].facilityClass == facilityClass)
    //             break;
    //     }
    //     if (i != NELEMS(sDoubleBattleTrainerInfo))
    //     {
    //         if (VarGet(VAR_TEMP_3))
    //             gender = sDoubleBattleTrainerInfo[i].gender2;
    //         else
    //             gender = sDoubleBattleTrainerInfo[i].gender1;
    //     }
    //     break;
    // }
    // gSpecialVar_PrevTextColor = gSpecialVar_TextColor;
    // gSpecialVar_TextColor = gender;
}

static void CB2_EndTrainerTowerBattle(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_DoTrainerTowerBattle(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = CB2_EndTrainerTowerBattle;
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

static void DoTrainerTowerBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_TRAINER_TOWER;

    if (CURR_FLOOR.challengeType == CHALLENGE_TYPE_DOUBLE)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;

    TRAINER_BATTLE_PARAM.opponentA = 0;
    BuildEnemyParty();
    CreateTask(Task_DoTrainerTowerBattle, 1);
    PlayMapChosenOrBattleBGM(0);
    BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_TRAINER_HILL));
}

static void TrainerTowerGetChallengeType(void)
{
    if (!gSpecialVar_0x8005)
        gSpecialVar_Result = CURR_FLOOR.challengeType;
}

static void TrainerTowerAddFloorCleared(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    TRAINER_TOWER.floorsCleared++;
#endif //FREE_TRAINER_TOWER
}

// So the player can safely go back through defeated floors to use the Poke Center (or exit challenge)
static void GetFloorAlreadyCleared(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    u16 mapLayoutId = gMapHeader.mapLayoutId;
    if (mapLayoutId - LAYOUT_TRAINER_TOWER_1F == TRAINER_TOWER.floorsCleared
     && mapLayoutId - LAYOUT_TRAINER_TOWER_LOBBY <= CURR_FLOOR.floorIdx)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
#else
    gSpecialVar_Result = TRUE;
#endif //FREE_TRAINER_TOWER
}

static void StartTrainerTowerChallenge(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    gSaveBlock1Ptr->towerChallengeId = gSpecialVar_0x8005;
    if (gSaveBlock1Ptr->towerChallengeId >= NUM_TOWER_CHALLENGE_TYPES)
        gSaveBlock1Ptr->towerChallengeId = 0;
    ValidateOrResetCurTrainerTowerRecord();
    TRAINER_TOWER.validated = TRUE;
    TRAINER_TOWER.floorsCleared = 0;
    SetTrainerHillVBlankCounter(&TRAINER_TOWER.timer);
    TRAINER_TOWER.timer = 0;
    TRAINER_TOWER.spokeToOwner = FALSE;
    TRAINER_TOWER.checkedFinalTime = FALSE;
#endif //FREE_TRAINER_TOWER
}

static void GetOwnerState(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    ClearTrainerHillVBlankCounter();
    gSpecialVar_Result = 0;

    if (TRAINER_TOWER.spokeToOwner)
        gSpecialVar_Result++;
    if (TRAINER_TOWER.receivedPrize && TRAINER_TOWER.checkedFinalTime)
        gSpecialVar_Result++;

    TRAINER_TOWER.spokeToOwner = TRUE;
#else
    gSpecialVar_Result = 2;
#endif //FREE_TRAINER_TOWER
}

static void GiveChallengePrize(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    enum Item itemId = sPrizeList[sTrainerTowerState->data.floors->prize];

    if (TRAINER_TOWER.receivedPrize)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        TRAINER_TOWER.receivedPrize = TRUE;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
#else
    gSpecialVar_Result = 0;
#endif //FREE_TRAINER_TOWER
}

static void CheckFinalTime(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    if (TRAINER_TOWER.checkedFinalTime)
    {
        gSpecialVar_Result = 2;
    }
    else if (GetTrainerTowerRecordTime(&TRAINER_TOWER.bestTime) > TRAINER_TOWER.timer)
    {
        SetTrainerTowerRecordTime(&TRAINER_TOWER.bestTime, TRAINER_TOWER.timer);
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    TRAINER_TOWER.checkedFinalTime = TRUE;
#else
    gSpecialVar_Result = 0;
#endif //FREE_TRAINER_TOWER
}

static void TrainerTowerResumeTimer(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    if (!TRAINER_TOWER.spokeToOwner)
    {
        if (TRAINER_TOWER.timer >= TRAINER_TOWER_MAX_TIME)
            TRAINER_TOWER.timer = TRAINER_TOWER_MAX_TIME;
        else
            SetTrainerHillVBlankCounter(&TRAINER_TOWER.timer);
    }
#endif //FREE_TRAINER_TOWER
}

static void TrainerTowerSetPlayerLost(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    TRAINER_TOWER.hasLost = TRUE;
#endif //FREE_TRAINER_TOWER
}

static void GetTrainerTowerChallengeStatus(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    if (TRAINER_TOWER.hasLost)
    {
        TRAINER_TOWER.hasLost = FALSE;
        gSpecialVar_Result = TT_CHALLENGE_STATUS_LOST;
    }
    else if (TRAINER_TOWER.unkA_4)
    {
        TRAINER_TOWER.unkA_4 = FALSE;
        gSpecialVar_Result = TT_CHALLENGE_STATUS_UNK;
    }
    else
    {
        gSpecialVar_Result = TT_CHALLENGE_STATUS_NORMAL;
    }
#else
    gSpecialVar_Result = TT_CHALLENGE_STATUS_NORMAL;
#endif //FREE_TRAINER_TOWER
}

#define PRINT_TOWER_TIME(src) ({                                                           \
    s32 minutes, seconds, centiseconds, frames;                                            \
                                                                                           \
    frames = (src);                                                                        \
                                                                                           \
    minutes = frames / (60 * 60);                                                          \
    frames %= (60 * 60);                                                                   \
    seconds = frames / 60;                                                                 \
    frames %= 60;                                                                          \
    centiseconds = frames * 168 / 100;                                                     \
                                                                                           \
    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);        \
    ConvertIntToDecimalStringN(gStringVar2, seconds, STR_CONV_MODE_RIGHT_ALIGN, 2);        \
    ConvertIntToDecimalStringN(gStringVar3, centiseconds, STR_CONV_MODE_LEADING_ZEROS, 2); \
})

static void GetCurrentTime(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    if (TRAINER_TOWER.timer >= TRAINER_TOWER_MAX_TIME)
    {
        ClearTrainerHillVBlankCounter();
        TRAINER_TOWER.timer = TRAINER_TOWER_MAX_TIME;
    }

    PRINT_TOWER_TIME(TRAINER_TOWER.timer);
#else
    ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, 0, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, 0, STR_CONV_MODE_LEADING_ZEROS, 2);
#endif //FREE_TRAINER_TOWER
}

static void ShowResultsBoard(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    u8 windowId;
    s32 i;

    ValidateOrResetCurTrainerTowerRecord();
    windowId = AddWindow(sTimeBoardWindowTemplate);
    LoadMessageBoxAndBorderGfx();
    DrawStdWindowFrame(windowId, FALSE);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_TimeBoard, 74, 0, TEXT_SKIP_DRAW, NULL);

    for (i = 0; i < NUM_TOWER_CHALLENGE_TYPES; i++)
    {
        PRINT_TOWER_TIME(GetTrainerTowerRecordTime(&TRAINER_TOWER.bestTime));

        StringExpandPlaceholders(gStringVar4, gText_XMinYZSec);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gTrainerTowerChallengeTypeTexts[i - 1], 24, 36 + 20 * i, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, 96, 46 + 20 * i, TEXT_SKIP_DRAW, NULL);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    VarSet(VAR_TEMP_1, windowId);
#endif //FREE_TRAINER_TOWER
}

static void CloseResultsBoard(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    u8 windowId = VarGet(VAR_TEMP_1);
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
#endif //FREE_TRAINER_TOWER
}

static void TrainerTowerGetDoublesEligiblity(void)
{
    gSpecialVar_Result = GetMonsStateToDoubles();
}


static void TrainerTowerGetNumFloors(void)
{
    if (sTrainerTowerState->data.numFloors != sTrainerTowerState->data.floors[0].floorIdx)
    {
        ConvertIntToDecimalStringN(gStringVar1, sTrainerTowerState->data.numFloors, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

// Dummied? equivalent to gSpecialVar_Result = FALSE
// If it were to return TRUE the player would be warped back to the lobby
static void ShouldWarpToCounter(void)
{
    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_TOWER_LOBBY && VarGet(VAR_MAP_SCENE_TRAINER_TOWER) == 0)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = FALSE;
}

static void PlayTrainerTowerEncounterMusic(void)
{
    s32 i;
    u16 idx = VarGet(VAR_TEMP_1);
    u8 facilityClass = CURR_FLOOR.trainers[idx].facilityClass;

    for (i = 0; i < ARRAY_COUNT(sTrainerEncounterMusicLUT); i++)
    {
        if (sTrainerEncounterMusicLUT[i].facilityClass == gFacilityClassToTrainerClass[facilityClass])
            break;
    }

    if (i != ARRAY_COUNT(sTrainerEncounterMusicLUT))
    {
        idx = sTrainerEncounterMusicLUT[i].musicId;
    }
    else
    {
        idx = 0;
    }
    PlayNewMapMusic(sTrainerTowerEncounterMusic[idx]);
}

static void HasSpokenToOwner(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    gSpecialVar_Result = TRAINER_TOWER.spokeToOwner;
#endif //FREE_TRAINER_TOWER
}

static void BuildEnemyParty(void)
{
    u16 trainerIdx = VarGet(VAR_TEMP_1);
    s32 level = GetPartyMaxLevel();
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    u8 floorIdx = TRAINER_TOWER.floorsCleared;
#else
    u8 floorIdx = gMapHeader.mapLayoutId - LAYOUT_TRAINER_TOWER_1F;
#endif //FREE_TRAINER_TOWER
    s32 i;
    u8 monIdx;

    ZeroEnemyPartyMons();

    switch (CURR_FLOOR.challengeType)
    {
    case CHALLENGE_TYPE_SINGLE:
    default:
        for (i = 0; i < 2; i++)
        {
            monIdx = sSingleBattleChallengeMonIdxs[floorIdx][i];
            CURR_FLOOR.trainers[trainerIdx].mons[monIdx].level = level;
            CreateBattleTowerMon(&gParties[B_TRAINER_OPPONENT_A][i], &CURR_FLOOR.trainers[trainerIdx].mons[monIdx]);
        }
        break;
    case CHALLENGE_TYPE_DOUBLE:
        monIdx = sDoubleBattleChallengeMonIdxs[floorIdx][0];
        CURR_FLOOR.trainers[0].mons[monIdx].level = level;
        CreateBattleTowerMon(&gParties[B_TRAINER_OPPONENT_A][0], &CURR_FLOOR.trainers[0].mons[monIdx]);

        monIdx = sDoubleBattleChallengeMonIdxs[floorIdx][1];
        CURR_FLOOR.trainers[1].mons[monIdx].level = level;
        CreateBattleTowerMon(&gParties[B_TRAINER_OPPONENT_A][1], &CURR_FLOOR.trainers[1].mons[monIdx]);
        break;
    case CHALLENGE_TYPE_KNOCKOUT:
        monIdx = sKnockoutChallengeMonIdxs[floorIdx][trainerIdx];
        CURR_FLOOR.trainers[trainerIdx].mons[monIdx].level = level;
        CreateBattleTowerMon(&gParties[B_TRAINER_OPPONENT_A][0], &CURR_FLOOR.trainers[trainerIdx].mons[monIdx]);
        break;
    }
}

static s32 GetPartyMaxLevel(void)
{
    s32 topLevel = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES, NULL) != 0 && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG)
        {
            s32 currLevel = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_LEVEL, NULL);
            if (currLevel > topLevel)
                topLevel = currLevel;
        }
    }

    return topLevel;
}

static void ValidateOrResetCurTrainerTowerRecord(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    if (TRAINER_TOWER.unk9 != sTrainerTowerState->data.id)
    {
        TRAINER_TOWER.unk9 = sTrainerTowerState->data.id;
        SetTrainerTowerRecordTime(&TRAINER_TOWER.bestTime, TRAINER_TOWER_MAX_TIME);
        TRAINER_TOWER.receivedPrize = FALSE;
    }
#endif //FREE_TRAINER_TOWER
}

void PrintTrainerTowerRecords(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    s32 i;
    u8 windowId = 0;

    SetUpTrainerTowerDataStruct();
    FillWindowPixelRect(0, PIXEL_FILL(0), 0, 0, 216, 144);
    ValidateOrResetCurTrainerTowerRecord();
    AddTextPrinterParameterized3(0, FONT_NORMAL, 0x4a, 0, sTextColors, 0, gText_TimeBoard);

    for (i = 0; i < NUM_TOWER_CHALLENGE_TYPES; i++)
    {
        PRINT_TOWER_TIME(GetTrainerTowerRecordTime(&gSaveBlock1Ptr->trainerTower[i].bestTime));
        StringExpandPlaceholders(gStringVar4, gText_XMinYZSec);
        AddTextPrinterParameterized3(windowId, FONT_NORMAL, 0x18, 0x24 + 0x14 * i, sTextColors, 0, gTrainerTowerChallengeTypeTexts[i]);
        AddTextPrinterParameterized3(windowId, FONT_NORMAL, 0x60, 0x24 + 0x14 * i, sTextColors, 0, gStringVar4);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    FreeTrainerTowerDataStruct();
#endif //FREE_TRAINER_TOWER
}

#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
static u32 GetTrainerTowerRecordTime(u32 *counter)
{
    return *counter;
}

static void SetTrainerTowerRecordTime(u32 *counter, u32 value)
{
    *counter = value;
}
#endif //FREE_TRAINER_TOWER

void ResetTrainerTowerResults(void)
{
#if FREE_TRAINER_TOWER == FALSE && IS_FRLG
    s32 i;

    for (i = 0; i < NUM_TOWER_CHALLENGE_TYPES; i++)
    {
        SetTrainerTowerRecordTime(&gSaveBlock1Ptr->trainerTower[i].bestTime, TRAINER_TOWER_MAX_TIME);
    }
#endif //FREE_TRAINER_TOWER
}
