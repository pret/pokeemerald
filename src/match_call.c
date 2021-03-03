#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainers.h"

struct MatchCallState
{
    u32 minutes;
    u16 trainerId;
    u8 stepCounter;
    u8 triggeredFromScript;
};

struct MatchCallTrainerTextInfo
{
    u16 trainerId;
    u16 unused;
    u16 battleTopicTextIds[3];
    u16 generalTextId;
    u8 battleFrontierRecordStreakTextIndex;
    u16 sameRouteMatchCallTextId;
    u16 differentRouteMatchCallTextId;
};

struct MatchCallText
{
    const u8 *text;
    s8 stringVarFuncIds[3];
};

struct MultiTrainerMatchCallText
{
    u16 trainerId;
    const u8 *text;
};

struct BattleFrontierStreakInfo
{
    u16 facilityId;
    u16 streak;
};

EWRAM_DATA struct MatchCallState gMatchCallState = {0};
EWRAM_DATA struct BattleFrontierStreakInfo gBattleFrontierStreakInfo = {0};

static u32 GetCurrentTotalMinutes(struct Time *);
static u32 GetNumRegisteredNPCs(void);
static u32 GetActiveMatchCallTrainerId(u32);
static int GetTrainerMatchCallId(int);
static u16 GetRematchTrainerLocation(int);
static bool32 TrainerIsEligibleForRematch(int);
static void StartMatchCall(void);
static void ExecuteMatchCall(u8);
static void DrawMatchCallTextBoxBorder(u32, u32, u32);
static void sub_8196694(u8);
static void InitMatchCallTextPrinter(int, const u8 *);
static bool32 ExecuteMatchCallTextPrinter(int);
static const struct MatchCallText *GetSameRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetDifferentRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetBattleMatchCallText(int, u8 *);
static const struct MatchCallText *GetGeneralMatchCallText(int, u8 *);
static bool32 sub_8196D74(int);
static void BuildMatchCallString(int, const struct MatchCallText *, u8 *);
static u16 GetFrontierStreakInfo(u16, u32 *);
static void PopulateMatchCallStringVars(int, const s8 *);
static void PopulateMatchCallStringVar(int, int, u8 *);
static bool32 LoadMatchCallWindowGfx(u8);
static bool32 MoveMatchCallWindowToVram(u8);
static bool32 PrintMatchCallIntroEllipsis(u8);
static bool32 sub_81962B0(u8);
static bool32 sub_81962D8(u8);
static bool32 sub_8196330(u8);
static bool32 sub_8196390(u8);
static bool32 sub_81963F0(u8);
static void PopulateTrainerName(int, u8 *);
static void PopulateMapName(int, u8 *);
static void PopulateSpeciesFromTrainerLocation(int, u8 *);
static void PopulateSpeciesFromTrainerParty(int, u8 *);
static void PopulateBattleFrontierFacilityName(int, u8 *);
static void PopulateBattleFrontierStreak(int, u8 *);

#define TEXT_ID(topic, id) (((topic) << 8) | ((id) & 0xFF))

static const struct MatchCallTrainerTextInfo sMatchCallTrainers[] =
{
    {
        .trainerId = TRAINER_ROSE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 3),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_ANDRES_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 12), TEXT_ID(2, 12), TEXT_ID(3, 12) },
        .generalTextId = TEXT_ID(1, 62),
        .battleFrontierRecordStreakTextIndex = 12,
        .sameRouteMatchCallTextId = TEXT_ID(1, 12),
        .differentRouteMatchCallTextId = TEXT_ID(2, 12),
    },
    {
        .trainerId = TRAINER_DUSTY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 12), TEXT_ID(2, 12), TEXT_ID(3, 12) },
        .generalTextId = TEXT_ID(1, 4),
        .battleFrontierRecordStreakTextIndex = 12,
        .sameRouteMatchCallTextId = TEXT_ID(1, 12),
        .differentRouteMatchCallTextId = TEXT_ID(2, 12),
    },
    {
        .trainerId = TRAINER_LOLA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 2), TEXT_ID(2, 2), TEXT_ID(3, 2) },
        .generalTextId = TEXT_ID(1, 5),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(1, 2),
        .differentRouteMatchCallTextId = TEXT_ID(2, 2),
    },
    {
        .trainerId = TRAINER_RICKY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 6),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_LILA_AND_ROY_1,
        .unused = 4,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 61),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_CRISTIN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 10), TEXT_ID(2, 10), TEXT_ID(3, 10) },
        .generalTextId = TEXT_ID(1, 64),
        .battleFrontierRecordStreakTextIndex = 10,
        .sameRouteMatchCallTextId = TEXT_ID(1, 10),
        .differentRouteMatchCallTextId = TEXT_ID(2, 10),
    },
    {
        .trainerId = TRAINER_BROOKE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 8),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_WILTON_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 6), TEXT_ID(2, 6), TEXT_ID(3, 6) },
        .generalTextId = TEXT_ID(1, 7),
        .battleFrontierRecordStreakTextIndex = 6,
        .sameRouteMatchCallTextId = TEXT_ID(1, 6),
        .differentRouteMatchCallTextId = TEXT_ID(2, 6),
    },
    {
        .trainerId = TRAINER_VALERIE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 9),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_CINDY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 10),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_THALIA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 10), TEXT_ID(3, 10) },
        .generalTextId = TEXT_ID(1, 14),
        .battleFrontierRecordStreakTextIndex = 10,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 10),
    },
    {
        .trainerId = TRAINER_JESSICA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 10), TEXT_ID(2, 10), TEXT_ID(3, 10) },
        .generalTextId = TEXT_ID(1, 11),
        .battleFrontierRecordStreakTextIndex = 10,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 10),
    },
    {
        .trainerId = TRAINER_WINSTON_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 4), TEXT_ID(2, 4), TEXT_ID(3, 4) },
        .generalTextId = TEXT_ID(1, 12),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(1, 4),
        .differentRouteMatchCallTextId = TEXT_ID(2, 4),
    },
    {
        .trainerId = TRAINER_STEVE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 7), TEXT_ID(2, 7), TEXT_ID(3, 7) },
        .generalTextId = TEXT_ID(1, 13),
        .battleFrontierRecordStreakTextIndex = 7,
        .sameRouteMatchCallTextId = TEXT_ID(1, 7),
        .differentRouteMatchCallTextId = TEXT_ID(2, 7),
    },
    {
        .trainerId = TRAINER_TONY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 15),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_NOB_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 16),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_KOJI_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 59),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_FERNANDO_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 6), TEXT_ID(2, 6), TEXT_ID(3, 6) },
        .generalTextId = TEXT_ID(1, 17),
        .battleFrontierRecordStreakTextIndex = 6,
        .sameRouteMatchCallTextId = TEXT_ID(1, 6),
        .differentRouteMatchCallTextId = TEXT_ID(2, 6),
    },
    {
        .trainerId = TRAINER_DALTON_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 4), TEXT_ID(2, 4), TEXT_ID(3, 4) },
        .generalTextId = TEXT_ID(1, 18),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(1, 4),
        .differentRouteMatchCallTextId = TEXT_ID(2, 4),
    },
    {
        .trainerId = TRAINER_BERNIE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 11), TEXT_ID(2, 11), TEXT_ID(3, 11) },
        .generalTextId = TEXT_ID(1, 19),
        .battleFrontierRecordStreakTextIndex = 11,
        .sameRouteMatchCallTextId = TEXT_ID(1, 11),
        .differentRouteMatchCallTextId = TEXT_ID(2, 11),
    },
    {
        .trainerId = TRAINER_ETHAN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 20),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_JOHN_AND_JAY_1,
        .unused = 3,
        .battleTopicTextIds = { TEXT_ID(1, 12), TEXT_ID(2, 12), TEXT_ID(3, 12) },
        .generalTextId = TEXT_ID(1, 60),
        .battleFrontierRecordStreakTextIndex = 12,
        .sameRouteMatchCallTextId = TEXT_ID(1, 12),
        .differentRouteMatchCallTextId = TEXT_ID(2, 12),
    },
    {
        .trainerId = TRAINER_JEFFREY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 7), TEXT_ID(2, 7), TEXT_ID(3, 7) },
        .generalTextId = TEXT_ID(1, 21),
        .battleFrontierRecordStreakTextIndex = 7,
        .sameRouteMatchCallTextId = TEXT_ID(1, 7),
        .differentRouteMatchCallTextId = TEXT_ID(2, 7),
    },
    {
        .trainerId = TRAINER_CAMERON_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 4), TEXT_ID(2, 4), TEXT_ID(3, 4) },
        .generalTextId = TEXT_ID(1, 22),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 4),
        .differentRouteMatchCallTextId = TEXT_ID(2, 4),
    },
    {
        .trainerId = TRAINER_JACKI_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 23),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_WALTER_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 12), TEXT_ID(2, 12), TEXT_ID(3, 12) },
        .generalTextId = TEXT_ID(1, 24),
        .battleFrontierRecordStreakTextIndex = 12,
        .sameRouteMatchCallTextId = TEXT_ID(1, 12),
        .differentRouteMatchCallTextId = TEXT_ID(2, 12),
    },
    {
        .trainerId = TRAINER_KAREN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 2), TEXT_ID(2, 2), TEXT_ID(3, 2) },
        .generalTextId = TEXT_ID(1, 26),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(1, 2),
        .differentRouteMatchCallTextId = TEXT_ID(2, 2),
    },
    {
        .trainerId = TRAINER_JERRY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 25),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_ANNA_AND_MEG_1,
        .unused = 6,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 27),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_ISABEL_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 14), TEXT_ID(2, 14), TEXT_ID(3, 14) },
        .generalTextId = TEXT_ID(1, 29),
        .battleFrontierRecordStreakTextIndex = 14,
        .sameRouteMatchCallTextId = TEXT_ID(1, 14),
        .differentRouteMatchCallTextId = TEXT_ID(2, 14),
    },
    {
        .trainerId = TRAINER_MIGUEL_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 11), TEXT_ID(2, 11), TEXT_ID(3, 11) },
        .generalTextId = TEXT_ID(1, 28),
        .battleFrontierRecordStreakTextIndex = 11,
        .sameRouteMatchCallTextId = TEXT_ID(1, 11),
        .differentRouteMatchCallTextId = TEXT_ID(2, 11),
    },
    {
        .trainerId = TRAINER_TIMOTHY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 12), TEXT_ID(2, 12), TEXT_ID(3, 12) },
        .generalTextId = TEXT_ID(1, 30),
        .battleFrontierRecordStreakTextIndex = 12,
        .sameRouteMatchCallTextId = TEXT_ID(1, 12),
        .differentRouteMatchCallTextId = TEXT_ID(2, 12),
    },
    {
        .trainerId = TRAINER_SHELBY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 13), TEXT_ID(2, 13), TEXT_ID(3, 13) },
        .generalTextId = TEXT_ID(1, 31),
        .battleFrontierRecordStreakTextIndex = 13,
        .sameRouteMatchCallTextId = TEXT_ID(1, 13),
        .differentRouteMatchCallTextId = TEXT_ID(2, 13),
    },
    {
        .trainerId = TRAINER_CALVIN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 32),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_ELLIOT_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 33),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_ISAIAH_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 38),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_MARIA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 37),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_ABIGAIL_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 35),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_DYLAN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 36),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_KATELYN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 40),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_BENJAMIN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 34),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_PABLO_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 39),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_NICOLAS_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 4), TEXT_ID(2, 4), TEXT_ID(3, 4) },
        .generalTextId = TEXT_ID(1, 41),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(1, 4),
        .differentRouteMatchCallTextId = TEXT_ID(2, 4),
    },
    {
        .trainerId = TRAINER_ROBERT_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 6), TEXT_ID(2, 6), TEXT_ID(3, 6) },
        .generalTextId = TEXT_ID(1, 42),
        .battleFrontierRecordStreakTextIndex = 6,
        .sameRouteMatchCallTextId = TEXT_ID(1, 6),
        .differentRouteMatchCallTextId = TEXT_ID(2, 6),
    },
    {
        .trainerId = TRAINER_LAO_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 43),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_CYNDY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 44),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_MADELINE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 45),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_JENNY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 46),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_DIANA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 2), TEXT_ID(2, 2), TEXT_ID(3, 2) },
        .generalTextId = TEXT_ID(1, 47),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(1, 2),
        .differentRouteMatchCallTextId = TEXT_ID(2, 2),
    },
    {
        .trainerId = TRAINER_AMY_AND_LIV_1,
        .unused = 2,
        .battleTopicTextIds = { TEXT_ID(1, 2), TEXT_ID(2, 2), TEXT_ID(3, 2) },
        .generalTextId = TEXT_ID(1, 48),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 2),
        .differentRouteMatchCallTextId = TEXT_ID(2, 2),
    },
    {
        .trainerId = TRAINER_ERNEST_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 49),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_CORY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 63),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_EDWIN_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 7), TEXT_ID(2, 7), TEXT_ID(3, 7) },
        .generalTextId = TEXT_ID(1, 50),
        .battleFrontierRecordStreakTextIndex = 7,
        .sameRouteMatchCallTextId = TEXT_ID(1, 7),
        .differentRouteMatchCallTextId = TEXT_ID(2, 7),
    },
    {
        .trainerId = TRAINER_LYDIA_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 52),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_ISAAC_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 51),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_GABRIELLE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 8), TEXT_ID(2, 8), TEXT_ID(3, 8) },
        .generalTextId = TEXT_ID(1, 2),
        .battleFrontierRecordStreakTextIndex = 8,
        .sameRouteMatchCallTextId = TEXT_ID(1, 8),
        .differentRouteMatchCallTextId = TEXT_ID(2, 8),
    },
    {
        .trainerId = TRAINER_CATHERINE_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 54),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
    {
        .trainerId = TRAINER_JACKSON_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 5), TEXT_ID(2, 5), TEXT_ID(3, 5) },
        .generalTextId = TEXT_ID(1, 53),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(1, 5),
        .differentRouteMatchCallTextId = TEXT_ID(2, 5),
    },
    {
        .trainerId = TRAINER_HALEY_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 2), TEXT_ID(2, 2), TEXT_ID(3, 2) },
        .generalTextId = TEXT_ID(1, 55),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(1, 2),
        .differentRouteMatchCallTextId = TEXT_ID(2, 2),
    },
    {
        .trainerId = TRAINER_JAMES_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 1), TEXT_ID(2, 1), TEXT_ID(3, 1) },
        .generalTextId = TEXT_ID(1, 56),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(1, 1),
        .differentRouteMatchCallTextId = TEXT_ID(2, 1),
    },
    {
        .trainerId = TRAINER_TRENT_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 3), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 57),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_SAWYER_1,
        .unused = 0,
        .battleTopicTextIds = { TEXT_ID(1, 15), TEXT_ID(2, 3), TEXT_ID(3, 3) },
        .generalTextId = TEXT_ID(1, 1),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(1, 3),
        .differentRouteMatchCallTextId = TEXT_ID(2, 3),
    },
    {
        .trainerId = TRAINER_KIRA_AND_DAN_1,
        .unused = 1,
        .battleTopicTextIds = { TEXT_ID(1, 9), TEXT_ID(2, 9), TEXT_ID(3, 9) },
        .generalTextId = TEXT_ID(1, 58),
        .battleFrontierRecordStreakTextIndex = 9,
        .sameRouteMatchCallTextId = TEXT_ID(1, 9),
        .differentRouteMatchCallTextId = TEXT_ID(2, 9),
    },
};

static const struct MatchCallText sMatchCallWildBattleTexts[] =
{
    { .text = MatchCall_WildBattleText1,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText2,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText3,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText4,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText5,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText6,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText7,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText8,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText9,  .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText10, .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText11, .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText12, .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText13, .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText14, .stringVarFuncIds = { 0, 2, -1 } },
    { .text = MatchCall_WildBattleText15, .stringVarFuncIds = { 0, 2, -1 } },
};

 static const struct MatchCallText sMatchCallNegativeBattleTexts[] =
 {
    { .text = MatchCall_NegativeBattleText1,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText2,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText3,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText4,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText5,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText6,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText7,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText8,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText9,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText10, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText11, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText12, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText13, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_NegativeBattleText14, .stringVarFuncIds = { 0, -1, -1 } },
};

static const struct MatchCallText sMatchCallPositiveBattleTexts[] =
{
    { .text = MatchCall_PositiveBattleText1,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText2,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText3,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText4,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText5,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText6,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText7,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText8,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText9,  .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText10, .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText11, .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText12, .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText13, .stringVarFuncIds = { 0, 3, -1 } },
    { .text = MatchCall_PositiveBattleText14, .stringVarFuncIds = { 0, 3, -1 } },
};

static const struct MatchCallText sMatchCallSameRouteBattleRequestTexts[] =
{
    { .text = MatchCall_SameRouteBattleRequestText1,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText2,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText3,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText4,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText5,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText6,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText7,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText8,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText9,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText10, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText11, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText12, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText13, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_SameRouteBattleRequestText14, .stringVarFuncIds = { 0, 1, -1 } },
};

static const struct MatchCallText sMatchCallDifferentRouteBattleRequestTexts[] =
{
    { .text = MatchCall_DifferentRouteBattleRequestText1,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText2,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText3,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText4,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText5,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText6,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText7,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText8,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText9,  .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText10, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText11, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText12, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText13, .stringVarFuncIds = { 0, 1, -1 } },
    { .text = MatchCall_DifferentRouteBattleRequestText14, .stringVarFuncIds = { 0, 1, -1 } },
};

static const struct MatchCallText sMatchCallPersonalizedTexts[] =
{
    { .text = MatchCall_PersonalizedText1,  .stringVarFuncIds = { 0,  1, -1 } },
    { .text = MatchCall_PersonalizedText2,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText3,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText4,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText5,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText6,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText7,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText8,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText9,  .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText10, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText11, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText12, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText13, .stringVarFuncIds = { 0,  2, -1 } },
    { .text = MatchCall_PersonalizedText14, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText15, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText16, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText17, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText18, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText19, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText20, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText21, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText22, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText23, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText24, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText25, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText26, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText27, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText28, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText29, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText30, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText31, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText32, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText33, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText34, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText35, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText36, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText37, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText38, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText39, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText40, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText41, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText42, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText43, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText44, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText45, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText46, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText47, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText48, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText49, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText50, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText51, .stringVarFuncIds = { 0,  1, -1 } },
    { .text = MatchCall_PersonalizedText52, .stringVarFuncIds = { 0,  3, -1 } },
    { .text = MatchCall_PersonalizedText53, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText54, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText55, .stringVarFuncIds = { 0,  1, -1 } },
    { .text = MatchCall_PersonalizedText56, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText57, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText58, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText59, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText60, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText61, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText62, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText63, .stringVarFuncIds = { 0, -1, -1 } },
    { .text = MatchCall_PersonalizedText64, .stringVarFuncIds = { 0, -1, -1 } },
};

static const struct MatchCallText sMatchCallBattleFrontierStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierStreakText1,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText2,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText3,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText4,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText5,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText6,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText7,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText8,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText9,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText10, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText11, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText12, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText13, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierStreakText14, .stringVarFuncIds = { 0, 4, 5 } },
};

static const struct MatchCallText sMatchCallBattleFrontierRecordStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierRecordStreakText1,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText2,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText3,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText4,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText5,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText6,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText7,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText8,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText9,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText10, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText11, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText12, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText13, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleFrontierRecordStreakText14, .stringVarFuncIds = { 0, 4, 5 } },
};

static const struct MatchCallText sMatchCallBattleDomeTexts[] =
{
    { .text = MatchCall_BattleDomeText1,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText2,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText3,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText4,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText5,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText6,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText7,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText8,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText9,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText10, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText11, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText12, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText13, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattleDomeText14, .stringVarFuncIds = { 0, 4, 5 } },
};

static const struct MatchCallText sMatchCallBattlePikeTexts[] =
{
    { .text = MatchCall_BattlePikeText1,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText2,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText3,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText4,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText5,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText6,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText7,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText8,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText9,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText10, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText11, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText12, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText13, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePikeText14, .stringVarFuncIds = { 0, 4, 5 } },
};

static const struct MatchCallText sMatchCallBattlePyramidTexts[] =
{
    { .text = MatchCall_BattlePyramidText1,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText2,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText3,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText4,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText5,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText6,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText7,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText8,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText9,  .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText10, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText11, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText12, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText13, .stringVarFuncIds = { 0, 4, 5 } },
    { .text = MatchCall_BattlePyramidText14, .stringVarFuncIds = { 0, 4, 5 } },
};

static const struct MatchCallText *const sMatchCallBattleTopics[] =
{
    sMatchCallWildBattleTexts,
    sMatchCallNegativeBattleTexts,
    sMatchCallPositiveBattleTexts,
};

static const struct MatchCallText *const sMatchCallBattleRequestTopics[] =
{
    sMatchCallSameRouteBattleRequestTexts,
    sMatchCallDifferentRouteBattleRequestTexts,
};

static const struct MatchCallText *const sMatchCallGeneralTopics[] =
{
    sMatchCallPersonalizedTexts,
    sMatchCallBattleFrontierStreakTexts,
    sMatchCallBattleFrontierRecordStreakTexts,
    sMatchCallBattleDomeTexts,
    sMatchCallBattlePikeTexts,
    sMatchCallBattlePyramidTexts,
};

extern const u8 gBirchDexRatingText_AreYouCurious[];
extern const u8 gBirchDexRatingText_SoYouveSeenAndCaught[];
extern const u8 gBirchDexRatingText_OnANationwideBasis[];

void InitMatchCallCounters(void)
{
    RtcCalcLocalTime();
    gMatchCallState.minutes = GetCurrentTotalMinutes(&gLocalTime) + 10;
    gMatchCallState.stepCounter = 0;
}

static u32 GetCurrentTotalMinutes(struct Time *time)
{
    return time->days * 1440 + time->hours * 60 + time->minutes;
}

static bool32 UpdateMatchCallMinutesCounter(void)
{
    int curMinutes;
    RtcCalcLocalTime();
    curMinutes = GetCurrentTotalMinutes(&gLocalTime);
    if (gMatchCallState.minutes > curMinutes || curMinutes - gMatchCallState.minutes > 9)
    {
        gMatchCallState.minutes = curMinutes;
        return TRUE;
    }

    return FALSE;
}

static bool32 CheckMatchCallChance(void)
{
    int callChance = 1;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG) && GetMonAbility(&gPlayerParty[0]) == ABILITY_LIGHTNING_ROD)
        callChance = 2;
    
    if (Random() % 10 < callChance * 3) 
        return TRUE;
    else
        return FALSE;
}

static bool32 MapAllowsMatchCall(void)
{
    if (!Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) || gMapHeader.regionMapSectionId == MAPSEC_SAFARI_ZONE)
        return FALSE;
    
    if (gMapHeader.regionMapSectionId == MAPSEC_SOOTOPOLIS_CITY
     && FlagGet(FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA) == TRUE
     && FlagGet(FLAG_NEVER_SET_0x0DC) == FALSE)
        return FALSE;

    if (gMapHeader.regionMapSectionId == MAPSEC_MT_CHIMNEY
     && FlagGet(FLAG_MET_ARCHIE_METEOR_FALLS) == TRUE
     && FlagGet(FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY) == FALSE)
        return FALSE;

    return TRUE;
}

static bool32 UpdateMatchCallStepCounter(void)
{
    if (++gMatchCallState.stepCounter >= 10)
    {
        gMatchCallState.stepCounter = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 SelectMatchCallTrainer(void)
{
    u32 matchCallId;
    u32 numRegistered = GetNumRegisteredNPCs();
    if (!numRegistered)
        return FALSE;

    gMatchCallState.trainerId = GetActiveMatchCallTrainerId(Random() % numRegistered);
    gMatchCallState.triggeredFromScript = 0;
    if (gMatchCallState.trainerId == REMATCH_TABLE_ENTRIES)
        return FALSE;

    matchCallId = GetTrainerMatchCallId(gMatchCallState.trainerId);
    if (GetRematchTrainerLocation(matchCallId) == gMapHeader.regionMapSectionId && !TrainerIsEligibleForRematch(matchCallId))
        return FALSE;

    return TRUE;
}

static u32 GetNumRegisteredNPCs(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + i))
            count++;
    }

    return count;
}

static u32 GetActiveMatchCallTrainerId(u32 activeMatchCallId)
{
    u32 i;
    for (i = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + i))
        {
            if (!activeMatchCallId)
                return gRematchTable[i].trainerIds[0];

            activeMatchCallId--;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

bool32 TryStartMatchCall(void)
{
    if (FlagGet(FLAG_HAS_MATCH_CALL) && UpdateMatchCallStepCounter() && UpdateMatchCallMinutesCounter()
     && CheckMatchCallChance() && MapAllowsMatchCall() && SelectMatchCallTrainer())
    {
        StartMatchCall();
        return TRUE;
    }

    return FALSE;
}

void StartMatchCallFromScript(const u8 *message)
{
    gMatchCallState.triggeredFromScript = 1;
    StartMatchCall();
}

bool32 IsMatchCallTaskActive(void)
{
    return FuncIsActiveTask(ExecuteMatchCall);
}

static void StartMatchCall(void)
{
    if (!gMatchCallState.triggeredFromScript)
    {
        ScriptContext2_Enable();
        FreezeObjectEvents();
        sub_808B864();
        sub_808BCF4();
    }

    PlaySE(SE_POKENAV_CALL);
    CreateTask(ExecuteMatchCall, 1);
}

static const u16 sUnknown_0860EA4C[] = INCBIN_U16("graphics/unknown/unknown_60EA4C.gbapal");
static const u8 sUnknown_0860EA6C[] = INCBIN_U8("graphics/interface/menu_border.4bpp");
static const u16 sPokeNavIconPalette[] = INCBIN_U16("graphics/pokenav/icon.gbapal");
static const u32 sPokeNavIconGfx[] = INCBIN_U32("graphics/pokenav/icon.4bpp.lz");

static const u8 sText_PokenavCallEllipsis[] = _("………………\p");

static bool32 (*const sMatchCallTaskFuncs[])(u8) =
{
    LoadMatchCallWindowGfx,
    MoveMatchCallWindowToVram,
    PrintMatchCallIntroEllipsis,
    sub_81962B0,
    sub_81962D8,
    sub_8196330,
    sub_8196390,
    sub_81963F0,
};

static void ExecuteMatchCall(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (sMatchCallTaskFuncs[taskData[0]](taskId))
    {
        taskData[0]++;
        taskData[1] = 0;
        if ((u16)taskData[0] > 7)
            DestroyTask(taskId);
    }
}

static const struct WindowTemplate sMatchCallTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x200
};

static bool32 LoadMatchCallWindowGfx(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    taskData[2] = AddWindow(&sMatchCallTextWindow);
    if (taskData[2] == 0xFF)
    {
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, sUnknown_0860EA6C, sizeof(sUnknown_0860EA6C), 0x270) == 0xFFFF)
    {
        RemoveWindow(taskData[2]);
        DestroyTask(taskId);
        return FALSE;
    }

    if (!DecompressAndCopyTileDataToVram(0, sPokeNavIconGfx, 0, 0x279, 0))
    {
        RemoveWindow(taskData[2]);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
    LoadPalette(sUnknown_0860EA4C, 0xE0, 0x20);
    LoadPalette(sPokeNavIconPalette, 0xF0, 0x20);
    ChangeBgY(0, -0x2000, 0);
    return TRUE;
}

static bool32 MoveMatchCallWindowToVram(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;

    PutWindowTilemap(taskData[2]);
    DrawMatchCallTextBoxBorder(taskData[2], 0x270, 14);
    WriteSequenceToBgTilemapBuffer(0, 0xF279, 1, 15, 4, 4, 17, 1);
    taskData[5] = CreateTask(sub_8196694, 10);
    CopyWindowToVram(taskData[2], 2);
    CopyBgTilemapBufferToVram(0);
    return TRUE;
}

static bool32 PrintMatchCallIntroEllipsis(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        InitMatchCallTextPrinter(taskData[2], sText_PokenavCallEllipsis);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81962B0(u8 taskId)
{
    if (ChangeBgY(0, 0x600, 1) >= 0)
    {
        ChangeBgY(0, 0, 0);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81962D8(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!ExecuteMatchCallTextPrinter(taskData[2]))
    {
        FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
        if (!gMatchCallState.triggeredFromScript)
            SelectMatchCallMessage(gMatchCallState.trainerId, gStringVar4);

        InitMatchCallTextPrinter(taskData[2], gStringVar4);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_8196330(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (!ExecuteMatchCallTextPrinter(taskData[2]) && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        FillWindowPixelBuffer(taskData[2], PIXEL_FILL(8));
        CopyWindowToVram(taskData[2], 2);
        PlaySE(SE_POKENAV_HANG_UP);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_8196390(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (ChangeBgY(0, 0x600, 2) <= -0x2000)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        DestroyTask(taskData[5]);
        RemoveWindow(taskData[2]);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
    }

    return FALSE;
}

static bool32 sub_81963F0(u8 taskId)
{
    u8 playerObjectId;
    if (!IsDma3ManagerBusyWithBgCopy() && !IsSEPlaying())
    {
        ChangeBgY(0, 0, 0);
        if (!gMatchCallState.triggeredFromScript)
        {
            LoadMessageBoxAndBorderGfx();
            playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
            ScriptMovement_UnfreezeObjectEvents();
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
        }

        return TRUE;
    }

    return FALSE;
}

static void DrawMatchCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

static void InitMatchCallTextPrinter(int windowId, const u8 *str)
{
    struct TextPrinterTemplate printerTemplate;
    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = 1;
    printerTemplate.x = 32;
    printerTemplate.y = 1;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 10;
    printerTemplate.bgColor = 8;
    printerTemplate.shadowColor = 14;
    gTextFlags.useAlternateDownArrow = 0;

    AddTextPrinter(&printerTemplate, GetPlayerTextSpeedDelay(), NULL);
}

static bool32 ExecuteMatchCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = 1;
    else
        gTextFlags.canABSpeedUpPrint = 0;

    RunTextPrinters();
    return IsTextPrinterActive(windowId);
}

static void sub_8196694(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (++taskData[0] > 8)
    {
        taskData[0] = 0;
        if (++taskData[1] > 7)
            taskData[1] = 0;

        taskData[2] = (taskData[1] * 16) + 0x279;
        WriteSequenceToBgTilemapBuffer(0, taskData[2] | ~0xFFF, 1, 15, 4, 4, 17, 1);
        CopyBgTilemapBufferToVram(0);
    }
}

static bool32 TrainerIsEligibleForRematch(int matchCallId)
{
    return gSaveBlock1Ptr->trainerRematches[matchCallId] > 0;
}

static u16 GetRematchTrainerLocation(int matchCallId)
{
    const struct MapHeader *mapHeader = Overworld_GetMapHeaderByGroupAndId(gRematchTable[matchCallId].mapGroup, gRematchTable[matchCallId].mapNum);
    return mapHeader->regionMapSectionId;
}

static u32 GetNumRematchTrainersFought(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
            count++;
    }

    return count;
}

static u32 sub_8196774(int arg0)
{
    u32 i, count;

    for (i = 0, count = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
        {
            if (count == arg0)
                return i;

            count++;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

bool32 SelectMatchCallMessage(int trainerId, u8 *str)
{
    u32 matchCallId;
    const struct MatchCallText *matchCallText;
    bool32 retVal = FALSE;

    matchCallId = GetTrainerMatchCallId(trainerId);
    gBattleFrontierStreakInfo.facilityId = 0;
    if (TrainerIsEligibleForRematch(matchCallId)
     && GetRematchTrainerLocation(matchCallId) == gMapHeader.regionMapSectionId)
    {
        matchCallText = GetSameRouteMatchCallText(matchCallId, str);
    }
    else if (sub_8196D74(matchCallId))
    {
        matchCallText = GetDifferentRouteMatchCallText(matchCallId, str);
        retVal = TRUE;
        UpdateRematchIfDefeated(matchCallId);
    }
    else if (Random() % 3)
    {
        matchCallText = GetBattleMatchCallText(matchCallId, str);
    }
    else
    {
        matchCallText = GetGeneralMatchCallText(matchCallId, str);
    }

    BuildMatchCallString(matchCallId, matchCallText, str);
    return retVal;
}

static int GetTrainerMatchCallId(int trainerId)
{
    int i = 0;
    while (1)
    {
        if (sMatchCallTrainers[i].trainerId == trainerId)
            return i;
        else
            i++;
    }
}

static const struct MatchCallText *GetSameRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].sameRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetDifferentRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].differentRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetBattleMatchCallText(int matchCallId, u8 *str)
{
    int mask;
    u32 textId, topic, id;
    
    topic = Random() % 3;
    textId = sMatchCallTrainers[matchCallId].battleTopicTextIds[topic];
    if (!textId)
        SpriteCallbackDummy(NULL); // leftover debugging ???

    mask = 0xFF;
    topic = (textId >> 8) - 1;
    id = (textId & mask) - 1;
    return &sMatchCallBattleTopics[topic][id];
}

static const struct MatchCallText *GetGeneralMatchCallText(int matchCallId, u8 *str)
{
    int i;
    int count;
    u32 topic, id;
    u16 rand;

    rand = Random();
    if (!(rand & 1))
    {
        for (count = 0, i = 0; i < NUM_FRONTIER_FACILITIES; i++)
        {
            if (GetFrontierStreakInfo(i, &topic) > 1)
                count++;
        }

        if (count)
        {
            count = Random() % count;
            for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
            {
                gBattleFrontierStreakInfo.streak = GetFrontierStreakInfo(i, &topic);
                if (gBattleFrontierStreakInfo.streak < 2)
                    continue;

                if (!count)
                    break;

                count--;
            }

            gBattleFrontierStreakInfo.facilityId = i;
            id = sMatchCallTrainers[matchCallId].battleFrontierRecordStreakTextIndex - 1;
            return &sMatchCallGeneralTopics[topic][id];
        }
    }

    topic = (sMatchCallTrainers[matchCallId].generalTextId >> 8) - 1;
    id = (sMatchCallTrainers[matchCallId].generalTextId & 0xFF) - 1;
    return &sMatchCallGeneralTopics[topic][id];
}

static void BuildMatchCallString(int matchCallId, const struct MatchCallText *matchCallText, u8 *str)
{
    PopulateMatchCallStringVars(matchCallId, matchCallText->stringVarFuncIds);
    StringExpandPlaceholders(str, matchCallText->text);
}

static u8 *const sMatchCallTextStringVars[] = { gStringVar1, gStringVar2, gStringVar3 };

static void PopulateMatchCallStringVars(int matchCallId, const s8 *stringVarFuncIds)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (stringVarFuncIds[i] >= 0)
            PopulateMatchCallStringVar(matchCallId, stringVarFuncIds[i], sMatchCallTextStringVars[i]);
    }
}

static void (*const sPopulateMatchCallStringVarFuncs[])(int, u8 *) =
{
    PopulateTrainerName,
    PopulateMapName,
    PopulateSpeciesFromTrainerLocation,
    PopulateSpeciesFromTrainerParty,
    PopulateBattleFrontierFacilityName,
    PopulateBattleFrontierStreak,
};

static void PopulateMatchCallStringVar(int matchCallId, int funcId, u8 *destStr)
{
    sPopulateMatchCallStringVarFuncs[funcId](matchCallId, destStr);
}

static const struct MultiTrainerMatchCallText sMultiTrainerMatchCallTexts[] =
{
    { .trainerId = TRAINER_KIRA_AND_DAN_1, .text = gText_Kira },
    { .trainerId = TRAINER_AMY_AND_LIV_1,  .text = gText_Amy },
    { .trainerId = TRAINER_JOHN_AND_JAY_1, .text = gText_John },
    { .trainerId = TRAINER_LILA_AND_ROY_1, .text = gText_Roy },
    { .trainerId = TRAINER_GABBY_AND_TY_1, .text = gText_Gabby },
    { .trainerId = TRAINER_ANNA_AND_MEG_1, .text = gText_Anna },
};

static void PopulateTrainerName(int matchCallId, u8 *destStr)
{
    u32 i;
    u16 trainerId = sMatchCallTrainers[matchCallId].trainerId;
    for (i = 0; i < 6; i++)
    {
        if (sMultiTrainerMatchCallTexts[i].trainerId == trainerId)
        {
            StringCopy(destStr, sMultiTrainerMatchCallTexts[i].text);
            return;
        }
    }

    StringCopy(destStr, gTrainers[trainerId].trainerName);
}

static void PopulateMapName(int matchCallId, u8 *destStr)
{
    GetMapName(destStr, GetRematchTrainerLocation(matchCallId), 0);
}

static u8 GetLandEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 20)
        return 0;
    else if (rand >= 20 && rand < 40)
        return 1;
    else if (rand >= 40 && rand < 50)
        return 2;
    else if (rand >= 50 && rand < 60)
        return 3;
    else if (rand >= 60 && rand < 70)
        return 4;
    else if (rand >= 70 && rand < 80)
        return 5;
    else if (rand >= 80 && rand < 85)
        return 6;
    else if (rand >= 85 && rand < 90)
        return 7;
    else if (rand >= 90 && rand < 94)
        return 8;
    else if (rand >= 94 && rand < 98)
        return 9;
    else if (rand >= 98 && rand < 99)
        return 10;
    else
        return 11;
}

static u8 GetWaterEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 60)
        return 0;
    else if (rand >= 60 && rand < 90)
        return 1;
    else if (rand >= 90 && rand < 95)
        return 2;
    else if (rand >= 95 && rand < 99)
        return 3;
    else
        return 4;
}

static void PopulateSpeciesFromTrainerLocation(int matchCallId, u8 *destStr)
{
    u16 species[2];
    int numSpecies;
    u8 slot;
    int i = 0;

    if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED)) // ??? This check is nonsense.
    {
        while (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            if (gWildMonHeaders[i].mapGroup == gRematchTable[matchCallId].mapGroup
             && gWildMonHeaders[i].mapNum == gRematchTable[matchCallId].mapNum)
                break;

            i++;
        }

        if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            numSpecies = 0;
            if (gWildMonHeaders[i].landMonsInfo)
            {
                slot = GetLandEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].landMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (gWildMonHeaders[i].waterMonsInfo)
            {
                slot = GetWaterEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].waterMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (numSpecies)
            {
                StringCopy(destStr, gSpeciesNames[species[Random() % numSpecies]]);
                return;
            }
        }
    }

    destStr[0] = EOS;
}

static void PopulateSpeciesFromTrainerParty(int matchCallId, u8 *destStr)
{
    u16 trainerId;
    union TrainerMonPtr party;
    u8 monId;
    const u8 *speciesName;

    trainerId = GetLastBeatenRematchTrainerId(sMatchCallTrainers[matchCallId].trainerId);
    party = gTrainers[trainerId].party;
    monId = Random() % gTrainers[trainerId].partySize;

    switch (gTrainers[trainerId].partyFlags)
    {
    case 0:
    default:
        speciesName = gSpeciesNames[party.NoItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        speciesName = gSpeciesNames[party.NoItemCustomMoves[monId].species];
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemCustomMoves[monId].species];
        break;
    }

    StringCopy(destStr, speciesName);
}

static const u8 *const sBattleFrontierFacilityNames[] =
{
    gText_BattleTower2,
    gText_BattleDome,
    gText_BattlePalace,
    gText_BattleArena,
    gText_BattlePike,
    gText_BattleFactory,
    gText_BattlePyramid,
};

static void PopulateBattleFrontierFacilityName(int matchCallId, u8 *destStr)
{
    StringCopy(destStr, sBattleFrontierFacilityNames[gBattleFrontierStreakInfo.facilityId]);
}

static void PopulateBattleFrontierStreak(int matchCallId, u8 *destStr)
{
    int i = 0;
    int streak = gBattleFrontierStreakInfo.streak;
    while (streak != 0)
    {
        streak /= 10;
        i++;
    }
    
    ConvertIntToDecimalStringN(destStr, gBattleFrontierStreakInfo.streak, STR_CONV_MODE_LEFT_ALIGN, i);
}

static const u16 sBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static int GetNumOwnedBadges(void)
{
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (!FlagGet(sBadgeFlags[i]))
            break;
    }

    return i;
}

static bool32 sub_8196D74(int matchCallId)
{
    int dayCount;
    int otId;
    u16 easyChatWord;
    int numRematchTrainersFought;
    int var0, var1, var2;

    if (GetNumOwnedBadges() < 5)
        return FALSE;

    dayCount = RtcGetLocalDayCount();
    otId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId) & 0xFFFF;

    easyChatWord = gSaveBlock1Ptr->easyChatPairs[0].unk2;
    numRematchTrainersFought = GetNumRematchTrainersFought();
    var0 = (numRematchTrainersFought * 13) / 10;
    var1 = ((dayCount ^ easyChatWord) + (easyChatWord ^ GetGameStat(GAME_STAT_TRAINER_BATTLES))) ^ otId;
    var2 = var1 % var0;
    if (var2 < numRematchTrainersFought)
    {
        if (sub_8196774(var2) == matchCallId)
            return TRUE;
    }

    return FALSE;
}

static u16 GetFrontierStreakInfo(u16 facilityId, u32 *topicTextId)
{
    int i;
    int j;
    u16 streak = 0;

    switch (facilityId)
    {
    case FRONTIER_FACILITY_DOME:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.domeRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 3;
        break;
    #ifdef BUGFIX
    case FRONTIER_FACILITY_PIKE:
    #else
    case FRONTIER_FACILITY_FACTORY:
    #endif
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.pikeRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pikeRecordStreaks[i];
        }
        *topicTextId = 4;
        break;
    case FRONTIER_FACILITY_TOWER:
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_PALACE:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    #ifdef BUGFIX
    case FRONTIER_FACILITY_FACTORY:
    #else
    case FRONTIER_FACILITY_PIKE:
    #endif
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j];
            }
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_ARENA:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.arenaRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.arenaRecordStreaks[i];
        }
        *topicTextId = 2;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        for (i = 0; i < 2; i++)
        {
            if (streak < gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i])
                streak = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i];
        }
        *topicTextId = 5;
        break;
    }

    return streak;
}

static u8 GetPokedexRatingLevel(u16 numSeen)
{
    if (numSeen < 10)
        return 0;
    if (numSeen < 20)
        return 1;
    if (numSeen < 30)
        return 2;
    if (numSeen < 40)
        return 3;
    if (numSeen < 50)
        return 4;
    if (numSeen < 60)
        return 5;
    if (numSeen < 70)
        return 6;
    if (numSeen < 80)
        return 7;
    if (numSeen < 90)
        return 8;
    if (numSeen < 100)
        return 9;
    if (numSeen < 110)
        return 10;
    if (numSeen < 120)
        return 11;
    if (numSeen < 130)
        return 12;
    if (numSeen < 140)
        return 13;
    if (numSeen < 150)
        return 14;
    if (numSeen < 160)
        return 15;
    if (numSeen < 170)
        return 16;
    if (numSeen < 180)
        return 17;
    if (numSeen < 190)
        return 18;
    if (numSeen < 200)
        return 19;
    
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DEOXYS), FLAG_GET_CAUGHT))
        numSeen--;
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_JIRACHI), FLAG_GET_CAUGHT))
        numSeen--;

    if (numSeen < 200)
        return 19;
    else
        return 20;
}

static const u8 *const sBirchDexRatingTexts[] =
{
    gBirchDexRatingText_LessThan10,
    gBirchDexRatingText_LessThan20,
    gBirchDexRatingText_LessThan30,
    gBirchDexRatingText_LessThan40,
    gBirchDexRatingText_LessThan50,
    gBirchDexRatingText_LessThan60,
    gBirchDexRatingText_LessThan70,
    gBirchDexRatingText_LessThan80,
    gBirchDexRatingText_LessThan90,
    gBirchDexRatingText_LessThan100,
    gBirchDexRatingText_LessThan110,
    gBirchDexRatingText_LessThan120,
    gBirchDexRatingText_LessThan130,
    gBirchDexRatingText_LessThan140,
    gBirchDexRatingText_LessThan150,
    gBirchDexRatingText_LessThan160,
    gBirchDexRatingText_LessThan170,
    gBirchDexRatingText_LessThan180,
    gBirchDexRatingText_LessThan190,
    gBirchDexRatingText_LessThan200,
    gBirchDexRatingText_DexCompleted,
};

void BufferPokedexRatingForMatchCall(u8 *destStr)
{
    int numSeen, numCaught;
    u8 *str;
    u8 dexRatingLevel;

    u8 *buffer = Alloc(0x3E8);
    if (!buffer)
    {
        destStr[0] = EOS;
        return;
    }

    numSeen = GetHoennPokedexCount(FLAG_GET_SEEN);
    numCaught = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
    dexRatingLevel = GetPokedexRatingLevel(numCaught);
    str = StringCopy(buffer, gBirchDexRatingText_AreYouCurious);
    str[0] = CHAR_PROMPT_CLEAR;
    str++;
    str = StringCopy(str, gBirchDexRatingText_SoYouveSeenAndCaught);
    str[0] = CHAR_PROMPT_CLEAR;
    str++;
    StringCopy(str, sBirchDexRatingTexts[dexRatingLevel]);
    str = StringExpandPlaceholders(destStr, buffer);

    if (IsNationalPokedexEnabled())
    {
        str[0] = CHAR_PROMPT_CLEAR;
        str++;
        numSeen = GetNationalPokedexCount(FLAG_GET_SEEN);
        numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(str, gBirchDexRatingText_OnANationwideBasis);
    }

    Free(buffer);
}

void sub_8197184(u32 windowId, u32 destOffset, u32 paletteId)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    LoadBgTiles(bg, sUnknown_0860EA6C, 0x100, destOffset);
    LoadPalette(sUnknown_0860EA4C, paletteId << 4, 0x20);
}

void sub_81971C4(u32 windowId, u32 tileOffset, u32 paletteId)
{
    DrawMatchCallTextBoxBorder(windowId, tileOffset, paletteId);
}
