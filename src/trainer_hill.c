#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "battle_setup.h"
#include "ereader_helpers.h"
#include "event_data.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_message_box.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "util.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/easy_chat.h"
#include "constants/trainer_hill.h"

#define HILL_TAG_NORMAL 0
#define HILL_TAG_VARIETY 1
#define HILL_TAG_UNIQUE 2
#define HILL_TAG_EXPERT 3

#define HILL_TRAINER_NAME_LENGTH 11
#define HILL_MAX_TIME 215999 // 60 * 60 * 60 - 1

struct TrHillRoomTrainers
{
    u8 name[2][HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass[2];
};

struct TrainerHillTrainer
{
    u8 name[HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass;
    u32 unused;
    u16 speechBefore[6];
    u16 speechWin[6];
    u16 speechLose[6];
    u16 speechAfter[6];
    struct BattleTowerPokemon mons[PARTY_SIZE];
};

struct TrHillFloor
{
    u8 unk0;
    u8 unk1;
    struct TrainerHillTrainer trainers[2];
    u8 data[0x100];
    u16 unk3A0[16];
    u8 coords[2]; // x first 4 bits, y last 4 bits
    u8 direction; // array of 4 bits for each trainer
    u8 range; // array of 4 bits for each trainer
};

struct TrHillTag
{
    u8 unkField_0;
    u8 unused1;
    u8 unkField_2;
    u8 unused3;
    u8 unused4;
    u8 unused5;
    u8 unused6;
    struct TrHillFloor floors[4];
};

struct TrHillStruct2
{
    u8 floorId;
    struct TrHillTag tag;
};

// EWRAM
static EWRAM_DATA struct TrHillStruct2 *sHillData = NULL;
static EWRAM_DATA struct TrHillRoomTrainers *sRoomTrainers = NULL;
EWRAM_DATA u32 *gTrainerHillVBlankCounter = NULL;

// This file's functions.
static void TrainerHillStartChallenge(void);
static void sub_81D58D8(void);
static void sub_81D5924(void);
static void sub_81D59D0(void);
static void TrainerHillResumeTimer(void);
static void TrainerHillSetPlayerLost(void);
static void TrainerHillGetChallengeStatus(void);
static void sub_81D5B2C(void);
static void sub_81D5BBC(void);
static void sub_81D5C00(void);
static void sub_81D5C5C(void);
static void sub_81D62B4(void);
static void sub_81D64AC(void);
static void sub_81D64DC(void);
static void sub_81D64FC(void);
static void sub_81D6518(void);
static void sub_81D6568(void);
static void TrainerHillSetTag(void);
static void SetUpDataStruct(void);
static void FreeDataStruct(void);
static void nullsub_2(void);
static void SetTimerValue(u32 *dst, u32 val);
static u32 GetTimerValue(u32 *src);
static void sub_81D642C(struct Pokemon *mon, u8 level);
static u16 sub_81D6640(void);

// const data
#include "data/battle_frontier/trainer_hill.h"

struct
{
    u8 trainerClass;
    u8 musicId;
} static const gUnknown_0862A3B4[] =
{
    {TRAINER_CLASS_TEAM_AQUA, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_ADMIN, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_LEADER, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AROMA_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BATTLE_GIRL, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SWIMMER_F, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEFAN, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_DRAGON_TAMER, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_COOLTRAINER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_GUITARIST, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SAILOR, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TWINS, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_INTERVIEWER, TRAINER_ENCOUNTER_MUSIC_INTERVIEWER},
    {TRAINER_CLASS_RUIN_MANIAC, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_GENTLEMAN, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_SWIMMER_M, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEMANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BLACK_BELT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_OLD_COUPLE, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_BUG_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_CAMPER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_KINDLER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_TEAM_MAGMA, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_ADMIN, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_LEADER, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_LASS, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BUG_CATCHER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_NINJA_BOY, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_RICH_BOY, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_HEX_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BEAUTY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PARASOL_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PICNICKER, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PKMN_BREEDER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_COLLECTOR, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_PKMN_RANGER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_PKMN_TRAINER_3, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_YOUNG_COUPLE, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PSYCHIC, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SR_AND_JR, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_ELITE_FOUR, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_YOUNGSTER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_EXPERT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_TRIATHLETE, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_BIRD_KEEPER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_FISHERMAN, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_CHAMPION, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_M, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_F, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_SIS_AND_BRO, TRAINER_ENCOUNTER_MUSIC_SWIMMER},
    {TRAINER_CLASS_HIKER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_LEADER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_SCHOOL_KID, TRAINER_ENCOUNTER_MUSIC_MALE},
};

static const u16 gUnknown_0862A48C[] = {ITEM_RARE_CANDY, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A498[] = {ITEM_LUXURY_BALL, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4A4[] = {ITEM_MAX_REVIVE, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4B0[] = {ITEM_MAX_ETHER, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4BC[] = {ITEM_ELIXIR, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4C8[] = {ITEM_TM05_ROAR, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4D4[] = {ITEM_TM36_SLUDGE_BOMB, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4E0[] = {ITEM_TM06_TOXIC, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4EC[] = {ITEM_TM11_SUNNY_DAY, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A4F8[] = {ITEM_TM26_EARTHQUAKE, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A504[] = {ITEM_RARE_CANDY, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A510[] = {ITEM_LUXURY_BALL, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A51C[] = {ITEM_MAX_REVIVE, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A528[] = {ITEM_MAX_ETHER, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A534[] = {ITEM_ELIXIR, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A540[] = {ITEM_TM31_BRICK_BREAK, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A54C[] = {ITEM_TM41_TORMENT, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A558[] = {ITEM_TM48_SKILL_SWAP, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A564[] = {ITEM_TM19_GIGA_DRAIN, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 gUnknown_0862A570[] = {ITEM_TM45_ATTRACT, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};

static const u16 *const gUnknown_0862A57C[] =
{
	gUnknown_0862A48C,
	gUnknown_0862A498,
	gUnknown_0862A4A4,
	gUnknown_0862A4B0,
	gUnknown_0862A4BC,
	gUnknown_0862A4C8,
	gUnknown_0862A4D4,
	gUnknown_0862A4E0,
	gUnknown_0862A4EC,
	gUnknown_0862A4F8
};

static const u16 *const gUnknown_0862A5A4[] =
{
	gUnknown_0862A504,
	gUnknown_0862A510,
	gUnknown_0862A51C,
	gUnknown_0862A528,
	gUnknown_0862A534,
	gUnknown_0862A540,
	gUnknown_0862A54C,
	gUnknown_0862A558,
	gUnknown_0862A564,
	gUnknown_0862A570
};

static const u16 *const *const gUnknown_0862A5CC[] =
{
    gUnknown_0862A57C,
    gUnknown_0862A5A4
};

static const u16 gUnknown_0862A5D4[] = INCBIN_U16("graphics/pokenav/862A5D4.gbapal");
static const u8 sRecordWinColors[] = {0, 2, 3};

static const struct TrHillTag *const sDataPerTag[] =
{
    &sDataTagNormal,
    &sDataTagVariety,
    &sDataTagUnique,
    &sDataTagExpert,
};

// Unused.
static const u8 *const sFloorStrings[] =
{
    gText_TrainerHill1F,
    gText_TrainerHill2F,
    gText_TrainerHill3F,
    gText_TrainerHill4F,
};

static void (* const sHillFunctions[])(void) =
{
    TrainerHillStartChallenge,
    sub_81D58D8,
    sub_81D5924,
    sub_81D59D0,
    TrainerHillResumeTimer,
    TrainerHillSetPlayerLost,
    TrainerHillGetChallengeStatus,
    sub_81D5B2C,
    sub_81D5BBC,
    sub_81D5C00,
    sub_81D5C5C,
    sub_81D62B4,
    sub_81D64AC,
    sub_81D64DC,
    sub_81D64FC,
    sub_81D6518,
    sub_81D6568,
    TrainerHillSetTag,
};

static const u8 *const sTagMatchStrings[] =
{
    gText_NormalTagMatch,
    gText_VarietyTagMatch,
    gText_UniqueTagMatch,
    gText_ExpertTagMatch,
};

static const struct EventObjectTemplate gUnknown_0862A670 =
{
    .graphicsId = EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL,
    .elevation = 3,
    .movementType = MOVEMENT_TYPE_LOOK_AROUND,
    .movementRangeX = 1,
    .movementRangeY = 1,
    .trainerType = 1,
};

static const u32 gUnknown_0862A688[] = {MAP_NUM(TRAINER_HILL_2F), MAP_NUM(TRAINER_HILL_3F), MAP_NUM(TRAINER_HILL_4F), MAP_NUM(TRAINER_HILL_ROOF)};
static const u8 gUnknown_0862A698[][3] = {{0, 1, 2}, {3, 4, 5}};

// code
void CallTrainerHillFunction(void)
{
    SetUpDataStruct();
    sHillFunctions[gSpecialVar_0x8004]();
    FreeDataStruct();
}

void ResetTrainerHillResults(void)
{
    s32 i;

    gSaveBlock2Ptr->frontier.field_EF9_1 = 0;
    gSaveBlock2Ptr->frontier.field_EF9_0 = 0;
    gSaveBlock1Ptr->trainerHill.bestTime = 0;
    for (i = 0; i < 4; i++)
        SetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i], HILL_MAX_TIME);
}

static u8 GetFloorId(void)
{
    return gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
}

u8 GetTrainerHillOpponentClass(u16 trainerId)
{
    u8 id = trainerId - 1;

    return gFacilityClassToTrainerClass[sRoomTrainers->facilityClass[id]];
}

void GetTrainerHillTrainerName(u8 *dst, u16 trainerId)
{
    s32 i;
    u8 id = trainerId - 1;

    for (i = 0; i < HILL_TRAINER_NAME_LENGTH; i++)
        dst[i] = sRoomTrainers->name[id][i];
}

u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId)
{
    u8 id, facilityClass;

    SetUpDataStruct();
    id = trainerId - 1;
    facilityClass = sHillData->tag.floors[sHillData->floorId].trainers[id].facilityClass;
    FreeDataStruct();

    return gFacilityClassToPicIndex[facilityClass];
}

void InitTrainerHillBattleStruct(void)
{
    s32 i, j;

    SetUpDataStruct();
    sRoomTrainers = AllocZeroed(sizeof(*sRoomTrainers));

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < HILL_TRAINER_NAME_LENGTH; j++)
        {
            sRoomTrainers->name[i][j] = sHillData->tag.floors[sHillData->floorId].trainers[i].name[j];
        }
        sRoomTrainers->facilityClass[i] = sHillData->tag.floors[sHillData->floorId].trainers[i].facilityClass;
    }
    SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    FreeDataStruct();
}

void FreeTrainerHillBattleStruct(void)
{
    if (sRoomTrainers != NULL)
        FREE_AND_SET_NULL(sRoomTrainers);
}

static void SetUpDataStruct(void)
{
    if (sHillData == NULL)
    {
        sHillData = AllocZeroed(sizeof(*sHillData));
        sHillData->floorId = gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
        CpuCopy32(sDataPerTag[gSaveBlock1Ptr->trainerHill.tag], &sHillData->tag, sizeof(sHillData->tag));
        nullsub_2();
    }
}

static void FreeDataStruct(void)
{
    if (sHillData != NULL)
        FREE_AND_SET_NULL(sHillData);
}

void CopyTrainerHillTrainerText(u8 which, u16 trainerId)
{
    u8 id, floorId;

    SetUpDataStruct();
    floorId = GetFloorId();
    id = trainerId - 1;

    switch (which)
    {
    case 2:
        FrontierSpeechToString(sHillData->tag.floors[floorId].trainers[id].speechBefore);
        break;
    case 3:
        FrontierSpeechToString(sHillData->tag.floors[floorId].trainers[id].speechWin);
        break;
    case 4:
        FrontierSpeechToString(sHillData->tag.floors[floorId].trainers[id].speechLose);
        break;
    case 5:
        FrontierSpeechToString(sHillData->tag.floors[floorId].trainers[id].speechAfter);
        break;
    }

    FreeDataStruct();
}

static void TrainerHillStartChallenge(void)
{
    nullsub_2();
    if (!ReadTrainerHillAndValidate())
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 1;
    else
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 0;

    gSaveBlock1Ptr->trainerHill.field_3D6C = 0;
    SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    gSaveBlock1Ptr->trainerHill.timer = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0c = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0b = 0;
    gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
    gSaveBlock2Ptr->frontier.field_EE0 = 0;
    gBattleOutcome = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0a = 0;
}

static void sub_81D58D8(void)
{
    ClearTrainerHillVBlankCounter();
    gSpecialVar_Result = 0;
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
        gSpecialVar_Result++;
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0a && gSaveBlock1Ptr->trainerHill.field_3D6E_0b)
        gSpecialVar_Result++;

    gSaveBlock1Ptr->trainerHill.field_3D6E_0c = 1;
}

static void sub_81D5924(void)
{
    u16 itemId = sub_81D6640();

    if (sHillData->tag.unkField_2 != 4 || gSaveBlock1Ptr->trainerHill.field_3D6E_0a)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        gSaveBlock1Ptr->trainerHill.field_3D6E_0a = 1;
        gSaveBlock2Ptr->frontier.field_EF9_0 = 0;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
}

static void sub_81D59D0(void)
{
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0b)
    {
        gSpecialVar_Result = 2;
    }
    else if (GetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime) > gSaveBlock1Ptr->trainerHill.timer)
    {
        SetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime, gSaveBlock1Ptr->trainerHill.timer);
        gSaveBlock1Ptr->trainerHillTimes[gSaveBlock1Ptr->trainerHill.tag] = gSaveBlock1Ptr->trainerHill.bestTime;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    gSaveBlock1Ptr->trainerHill.field_3D6E_0b = 1;
}

static void TrainerHillResumeTimer(void)
{
    if (!gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
    {
        if (gSaveBlock1Ptr->trainerHill.timer >= HILL_MAX_TIME)
            gSaveBlock1Ptr->trainerHill.timer = HILL_MAX_TIME;
        else
            SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    }
}

static void TrainerHillSetPlayerLost(void)
{
    gSaveBlock1Ptr->trainerHill.hasLost = 1;
}

static void TrainerHillGetChallengeStatus(void)
{
    if (gSaveBlock1Ptr->trainerHill.hasLost)
    {
        // The player lost their last match.
        gSaveBlock1Ptr->trainerHill.hasLost = 0;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_LOST;
    }
    else if (gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge)
    {
        // Unreachable code. Something relating to eCards?
        gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED;
    }
    else
    {
        // Continue playing.
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_NORMAL;
    }
}

static void sub_81D5B2C(void)
{
    s32 total, minutes, secondsWhole, secondsFraction;

    total = gSaveBlock1Ptr->trainerHill.timer;
    if (total >= HILL_MAX_TIME)
        total = HILL_MAX_TIME;

    minutes = total / (60 * 60);
    total %= (60 * 60);
    secondsWhole = total / 60;
    total %= 60;
    secondsFraction = (total * 168) / 100;

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
}

static void sub_81D5BBC(void)
{
    SetUpDataStruct();
    if (sHillData->tag.unkField_2 != 4)
    {
        ConvertIntToDecimalStringN(gStringVar1, sHillData->tag.unkField_2, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    FreeDataStruct();
}

static void sub_81D5C00(void)
{
    SetUpDataStruct();
    gSpecialVar_Result = 0;
    FreeDataStruct();
}

bool8 sub_81D5C18(void)
{
    if (VarGet(VAR_TRAINER_HILL_IS_ACTIVE) == 0)
        return FALSE;
    else if (gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
        return FALSE;
    else if (GetCurrentTrainerHillMapId() != 0)
        return TRUE;
    else
        return FALSE;
}

static void sub_81D5C5C(void)
{
    if (!sub_81D5C18())
        gSpecialVar_Result = 0;
    else
        gSpecialVar_Result = 1;
}

void nullsub_129(void)
{

}

static void nullsub_2(void)
{

}

void PrintOnTrainerHillRecordsWindow(void)
{
    s32 i, x, y;
    u32 total, minutes, secondsWhole, secondsFraction;

    SetUpDataStruct();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffset(1, gText_TimeBoard, 0xD0);
    AddTextPrinterParameterized3(0, 1, x, 2, sRecordWinColors, TEXT_SPEED_FF, gText_TimeBoard);

    y = 18;
    for (i = 0; i < 4; i++)
    {
        AddTextPrinterParameterized3(0, 1, 0, y, sRecordWinColors, TEXT_SPEED_FF, sTagMatchStrings[i]);
        y += 15;
        total = GetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i]);
        minutes = total / (60 * 60);
        total %= (60 * 60);
        ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsWhole = total / 60;
        total %= 60;
        ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsFraction = (total * 168) / 100;
        ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(StringCopy(gStringVar4, gText_TimeCleared), gText_XMinYDotZSec);
        x = GetStringRightAlignXOffset(1, gStringVar4, 0xD0);
        AddTextPrinterParameterized3(0, 1, x, y, sRecordWinColors, TEXT_SPEED_FF, gStringVar4);
        y += 17;
    }

    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    FreeDataStruct();
}

// Leftover from Fire Red / Leaf Green as in these games,
// the timer had to be xored by the encryption key in Sav2.
static u32 GetTimerValue(u32 *src)
{
    return *src;
}

static void SetTimerValue(u32 *dst, u32 val)
{
    *dst = val;
}

void sub_81D5DF8(void)
{
    u8 i, floorId;
    struct EventObjectTemplate *eventTemplates = gSaveBlock1Ptr->eventObjectTemplates;

    if (!sub_81D5F48())
        return;

    SetUpDataStruct();
    for (i = 0; i < 2; i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
    CpuFill32(0, gSaveBlock1Ptr->eventObjectTemplates, sizeof(gSaveBlock1Ptr->eventObjectTemplates));

    floorId = GetFloorId();
    for (i = 0; i < 2; i++)
    {
        u8 bits;

        eventTemplates[i] = gUnknown_0862A670;
        eventTemplates[i].localId = i + 1;
        eventTemplates[i].graphicsId = FacilityClassToGraphicsId(sHillData->tag.floors[floorId].trainers[i].facilityClass);
        eventTemplates[i].x = sHillData->tag.floors[floorId].coords[i] & 0xF;
        eventTemplates[i].y = ((sHillData->tag.floors[floorId].coords[i] >> 4) & 0xF) + 5;
        bits = i << 2;
        eventTemplates[i].movementType = ((sHillData->tag.floors[floorId].direction >> bits) & 0xF) + MOVEMENT_TYPE_FACE_UP;
        eventTemplates[i].trainerRange_berryTreeId = (sHillData->tag.floors[floorId].range >> bits) & 0xF;
        eventTemplates[i].script = EventScript_2C83F0;
        gSaveBlock2Ptr->frontier.trainerIds[i] = i + 1;
    }

    FreeDataStruct();
}

bool32 sub_81D5F48(void)
{
    SetUpDataStruct();
    FreeDataStruct();
    return TRUE;
}

// Functionally equivalent.
#ifdef NONMATCHING
static u32 sub_81D5F58(u8 floorId, u32 bit, u32 arg2, u32 arg3)
{
    u32 var0, var1, var2, var3;

    var0 = (sHillData->tag.floors[floorId].unk3A0[arg2] >> (15 - bit)) & 1;
    var1 = sHillData->tag.floors[floorId].data[arg2 * arg3 + bit];
    var3 = 0x200;
    var2 = 0x3000;

    return ((var0 << 10) | var2) | (var1 | var3);
}
#else
NAKED
static u32 sub_81D5F58(u8 floorId, u32 bit, u32 arg2, u32 arg3)
{
    asm_unified("\n\
    push {r4,r5,lr}\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	ldr r4, =sHillData\n\
	ldr r4, [r4]\n\
	mov r12, r4\n\
	lsls r4, r2, 1\n\
	lsls r5, r0, 4\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	adds r4, r5\n\
	movs r0, 0xE8\n\
	lsls r0, 2\n\
	add r0, r12\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r4, 0xF\n\
	subs r4, r1\n\
	asrs r0, r4\n\
	movs r4, 0x1\n\
	ands r0, r4\n\
	muls r2, r3\n\
	adds r2, r1\n\
	adds r2, r5\n\
	movs r1, 0xA8\n\
	lsls r1, 2\n\
	add r1, r12\n\
	adds r1, r2\n\
	ldrb r1, [r1]\n\
	movs r2, 0x80\n\
	lsls r2, 2\n\
	adds r3, r2, 0\n\
	movs r2, 0xC0\n\
	lsls r2, 6\n\
	lsls r0, 10\n\
	orrs r0, r2\n\
	orrs r1, r3\n\
	orrs r0, r1\n\
	pop {r4,r5}\n\
	pop {r1}\n\
	bx r1\n\
	.pool");
}
#endif // NONMATCHING

void sub_81D5FB4(u16 *mapArg)
{
    s32 i, j;
    u16 *src, *dst;
    u8 mapId = GetCurrentTrainerHillMapId();

    if (mapId == 6)
    {
        InitMapFromSavedGame();
        return;
    }

    SetUpDataStruct();
    if (mapId == 5)
    {
        InitMapFromSavedGame();
        FreeDataStruct();
        return;
    }

    mapId = GetFloorId();
    src = gMapHeader.mapLayout->map;
    gBackupMapLayout.map = mapArg;
    gBackupMapLayout.width = 31;
    gBackupMapLayout.height = 35;
    dst = mapArg + 224;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = src[j];
        dst += 31;
        src += 16;
    }

    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = sub_81D5F58(mapId, j, i, 0x10);
        dst += 31;
    }

    RunOnLoadMapScript();
    FreeDataStruct();
}

bool32 InTrainerHill(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F
            || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F
            || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F
            || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

u8 GetCurrentTrainerHillMapId(void)
{
    u8 ret;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F)
        ret = 1;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F)
        ret = 2;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F)
        ret = 3;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F)
        ret = 4;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ROOF)
        ret = 5;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ENTRANCE)
        ret = 6;
    else
        ret = 0;

    return ret;
}

static bool32 sub_81D6100(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ROOF)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

const struct WarpEvent* sub_81D6120(void)
{
    const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), MAP_NUM(TRAINER_HILL_4F));

    return &header->events->warps[1];
}

const struct WarpEvent* sub_81D6134(u8 warpEventId)
{
    u8 id;
    const struct MapHeader *header;

    if (warpEventId == 1)
        return &gMapHeader.events->warps[1];

    id = sub_81D6490();
    if (id == 0 || id >= 5)
        id = 4;

    header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), gUnknown_0862A688[id - 1]);
    return &header->events->warps[0];
}

u16 LocalIdToHillTrainerId(u8 localId)
{
    return gSaveBlock2Ptr->frontier.trainerIds[localId - 1];
}

bool8 GetHillTrainerFlag(u8 eventObjectId)
{
    u32 floorId = GetFloorId() * 2;
    u8 bitId = gEventObjects[eventObjectId].localId - 1 + floorId;

    return gSaveBlock2Ptr->frontier.field_EE0 & gBitTable[bitId];
}

void SetHillTrainerFlag(void)
{
    u8 i;
    u8 floorId = GetFloorId() * 2;

    for (i = 0; i < 2; i++)
    {
        if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_A)
        {
            gSaveBlock2Ptr->frontier.field_EE0 |= gBitTable[floorId + i];
            break;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        for (i = 0; i < 2; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_B)
            {
                gSaveBlock2Ptr->frontier.field_EE0 |= gBitTable[floorId + i];
                break;
            }
        }
    }
}

const u8 *sub_81D62AC(void)
{
    return EventScript_2C83F0;
}

static void sub_81D62B4(void)
{
    CopyTrainerHillTrainerText(5, gSpecialVar_LastTalked);
    sub_80982B8();
}

static void sub_81D62CC(u16 trainerId, u8 firstMonId)
{
    u8 trId, level;
    s32 i, floorId, arrId;

    if (trainerId == 0 || trainerId > 2)
        return;

    trId = trainerId - 1;
    SetUpDataStruct();
    level = GetHighestLevelInPlayerParty();
    floorId = GetFloorId();
    for (i = firstMonId, arrId = 0; i < firstMonId + 3; i++, arrId++)
    {
        u8 id = gUnknown_0862A698[trId][arrId];
        struct Pokemon *mon = &gEnemyParty[i];

        CreateBattleTowerMon(mon, &sHillData->tag.floors[floorId].trainers[trId].mons[id]);
        sub_81D642C(mon, level);
    }

    FreeDataStruct();
}

void FillHillTrainerParty(void)
{
    ZeroEnemyPartyMons();
    sub_81D62CC(gTrainerBattleOpponent_A, 0);
}

void FillHillTrainersParties(void)
{
    ZeroEnemyPartyMons();
    sub_81D62CC(gTrainerBattleOpponent_A, 0);
    sub_81D62CC(gTrainerBattleOpponent_B, 3);
}

// This function is unused, but my best guess is
// it was supposed to return AI scripts for trainer
// hill trainers.
u32 sub_81D63C4(void)
{
    return 7;
}

u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId)
{
    s32 i;
    u8 trId, facilityClass;

    SetUpDataStruct();
    trId = trainerId - 1;
    facilityClass = sHillData->tag.floors[sHillData->floorId].trainers[trId].facilityClass;
    FreeDataStruct();

    for (i = 0; i < ARRAY_COUNT(gUnknown_0862A3B4); i++)
    {
        if (gUnknown_0862A3B4[i].trainerClass == gFacilityClassToTrainerClass[facilityClass])
            return gUnknown_0862A3B4[i].musicId;
    }

    return 0;
}

static void sub_81D642C(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = gExperienceTables[gBaseStats[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    CalculateMonStats(mon);
}

u8 sub_81D6490(void)
{
    u8 ret;

    SetUpDataStruct();
    ret = sHillData->tag.unkField_2;
    FreeDataStruct();

    return ret;
}

static void sub_81D64AC(void)
{
    gSaveBlock2Ptr->frontier.field_EE0 = 0xFF;
}

void sub_81D64C0(void)
{
    if (sub_81D6534() == TRUE)
        LoadPalette(gUnknown_0862A5D4, 0x70, 0x20);
}

static void sub_81D64DC(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_EF9_1;
}

static void sub_81D64FC(void)
{
    gSaveBlock2Ptr->frontier.field_EF9_1 = 1;
}

static void sub_81D6518(void)
{
    gSaveBlock2Ptr->frontier.field_EF9_1 = 0;
}

bool32 sub_81D6534(void)
{
    if (!sub_81D5C18() || GetCurrentTrainerHillMapId() == 6)
        return FALSE;

    sub_81D5C00();
    if (gSpecialVar_Result == 0)
        return FALSE;
    else
        return TRUE;
}

static void sub_81D6568(void)
{
    if (gSaveBlock1Ptr->trainerHill.hasLost)
        gSpecialVar_Result = 0;
    else
        gSpecialVar_Result = 1;
}

static void TrainerHillSetTag(void)
{
    gSaveBlock1Ptr->trainerHill.tag = gSpecialVar_0x8005;
    gSaveBlock1Ptr->trainerHill.bestTime = gSaveBlock1Ptr->trainerHillTimes[gSpecialVar_0x8005];
}

static u8 sub_81D65E8(u8 arg0)
{
    u8 var, i, modBy;

    var = 0;
    for (i = 0; i < 4; i++)
    {
        var ^= sHillData->tag.floors[i].unk0 & 0x1F;
        var ^= sHillData->tag.floors[i].unk1 & 0x1F;
    }

    if (arg0)
        modBy = 10;
    else
        modBy = 5;

    var %= modBy;
    return var;
}

static u16 sub_81D6640(void)
{
    u8 i;
    const u16 *ptr;
    s32 var = 0, var2, minutes, id;

    for (i = 0; i < 4; i++)
    {
        var += sHillData->tag.floors[i].unk0;
        var += sHillData->tag.floors[i].unk1;
    }

    var2 = var / 256;
    var2 %= 2;
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && sHillData->tag.unkField_0 == 8)
        i = sub_81D65E8(1);
    else
        i = sub_81D65E8(0);

    if (gSaveBlock1Ptr->trainerHill.tag == HILL_TAG_EXPERT)
        i = (i + 1) % 10;

    ptr = gUnknown_0862A5CC[var2][i];
    minutes = (signed)(gSaveBlock1Ptr->trainerHill.timer) / (60 * 60);
    if (minutes < 12)
        id = 0;
    else if (minutes < 13)
        id = 1;
    else if (minutes < 14)
        id = 2;
    else if (minutes < 16)
        id = 3;
    else if (minutes < 18)
        id = 4;
    else
        id = 5;

    return ptr[id];
}
