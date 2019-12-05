#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallStruct1 {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallSubstruct2 {
    u16 flag;
    u8 mapSec;
};

struct MatchCallStruct2 {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallStruct4 {
    u8 type;
    u8 gender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Note: Type1 and Type5 have identical struct layouts.
struct MatchCallStruct5 {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStruct0 *type0;
    const struct MatchCallStruct1 *type1;
    const struct MatchCallStruct2 *type2;
    const struct MatchCallStruct3 *type3;
    const struct MatchCallStruct4 *type4;
    const struct MatchCallStruct5 *type5;
} match_call_t;

struct MatchCallOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCallGetFlag_Type0(match_call_t);
static bool32 MatchCallGetFlag_Type1(match_call_t);
static bool32 MatchCallGetFlag_Type2(match_call_t);
static bool32 MatchCallGetFlag_Type3(match_call_t);
static bool32 MatchCallGetFlag_Type4(match_call_t);

static u8 MatchCallGetMapSec_Type0(match_call_t);
static u8 MatchCallGetMapSec_Type1(match_call_t);
static u8 MatchCallGetMapSec_Type2(match_call_t);
static u8 MatchCallGetMapSec_Type3(match_call_t);
static u8 MatchCallGetMapSec_Type4(match_call_t);

static bool32 MatchCall_IsRematchable_Type0(match_call_t);
static bool32 MatchCall_IsRematchable_Type1(match_call_t);
static bool32 MatchCall_IsRematchable_Type2(match_call_t);
static bool32 MatchCall_IsRematchable_Type3(match_call_t);
static bool32 MatchCall_IsRematchable_Type4(match_call_t);

static bool32 MatchCall_HasCheckPage_Type0(match_call_t);
static bool32 MatchCall_HasCheckPage_Type1(match_call_t);
static bool32 MatchCall_HasCheckPage_Type2(match_call_t);
static bool32 MatchCall_HasCheckPage_Type3(match_call_t);
static bool32 MatchCall_HasCheckPage_Type4(match_call_t);

static u32 MatchCall_GetRematchTableIdx_Type0(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Type1(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Type2(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Type3(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Type4(match_call_t);

static void MatchCall_GetMessage_Type0(match_call_t, u8 *);
static void MatchCall_GetMessage_Type1(match_call_t, u8 *);
static void MatchCall_GetMessage_Type2(match_call_t, u8 *);
static void MatchCall_GetMessage_Type3(match_call_t, u8 *);
static void MatchCall_GetMessage_Type4(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_Type0(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Type1(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Type2(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Type3(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Type4(match_call_t, const u8 **, const u8 **);

static void sub_81D1920(const match_call_text_data_t *, u8 *);
static void sub_81D199C(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

extern const u8 MatchCall_Text_MrStone1[];
extern const u8 MatchCall_Text_MrStone2[];
extern const u8 MatchCall_Text_MrStone3[];
extern const u8 MatchCall_Text_MrStone4[];
extern const u8 MatchCall_Text_MrStone5[];
extern const u8 MatchCall_Text_MrStone6[];
extern const u8 MatchCall_Text_MrStone7[];
extern const u8 MatchCall_Text_MrStone8[];
extern const u8 MatchCall_Text_MrStone9[];
extern const u8 MatchCall_Text_MrStone10[];
extern const u8 MatchCall_Text_MrStone11[];

extern const u8 MatchCall_Text_Norman1[];
extern const u8 MatchCall_Text_Norman2[];
extern const u8 MatchCall_Text_Norman3[];
extern const u8 MatchCall_Text_Norman4[];
extern const u8 MatchCall_Text_Norman5[];
extern const u8 MatchCall_Text_Norman6[];
extern const u8 MatchCall_Text_Norman7[];
extern const u8 MatchCall_Text_Norman8[];
extern const u8 MatchCall_Text_Norman9[];

extern const u8 MatchCall_Text_Mom1[];
extern const u8 MatchCall_Text_Mom2[];
extern const u8 MatchCall_Text_Mom3[];

extern const u8 MatchCall_Text_Steven1[];
extern const u8 MatchCall_Text_Steven2[];
extern const u8 MatchCall_Text_Steven3[];
extern const u8 MatchCall_Text_Steven4[];
extern const u8 MatchCall_Text_Steven5[];
extern const u8 MatchCall_Text_Steven6[];
extern const u8 MatchCall_Text_Steven7[];

extern const u8 MatchCall_Text_May1[];
extern const u8 MatchCall_Text_May2[];
extern const u8 MatchCall_Text_May3[];
extern const u8 MatchCall_Text_May4[];
extern const u8 MatchCall_Text_May5[];
extern const u8 MatchCall_Text_May6[];
extern const u8 MatchCall_Text_May7[];
extern const u8 MatchCall_Text_May8[];
extern const u8 MatchCall_Text_May9[];
extern const u8 MatchCall_Text_May10[];
extern const u8 MatchCall_Text_May11[];
extern const u8 MatchCall_Text_May12[];
extern const u8 MatchCall_Text_May13[];
extern const u8 MatchCall_Text_May14[];
extern const u8 MatchCall_Text_May15[];

extern const u8 MatchCall_Text_Brendan1[];
extern const u8 MatchCall_Text_Brendan2[];
extern const u8 MatchCall_Text_Brendan3[];
extern const u8 MatchCall_Text_Brendan4[];
extern const u8 MatchCall_Text_Brendan5[];
extern const u8 MatchCall_Text_Brendan6[];
extern const u8 MatchCall_Text_Brendan7[];
extern const u8 MatchCall_Text_Brendan8[];
extern const u8 MatchCall_Text_Brendan9[];
extern const u8 MatchCall_Text_Brendan10[];
extern const u8 MatchCall_Text_Brendan11[];
extern const u8 MatchCall_Text_Brendan12[];
extern const u8 MatchCall_Text_Brendan13[];
extern const u8 MatchCall_Text_Brendan14[];
extern const u8 MatchCall_Text_Brendan15[];

extern const u8 MatchCall_Text_Wally1[];
extern const u8 MatchCall_Text_Wally2[];
extern const u8 MatchCall_Text_Wally3[];
extern const u8 MatchCall_Text_Wally4[];
extern const u8 MatchCall_Text_Wally5[];
extern const u8 MatchCall_Text_Wally6[];
extern const u8 MatchCall_Text_Wally7[];

extern const u8 MatchCall_Text_Scott1[];
extern const u8 MatchCall_Text_Scott2[];
extern const u8 MatchCall_Text_Scott3[];
extern const u8 MatchCall_Text_Scott4[];
extern const u8 MatchCall_Text_Scott5[];
extern const u8 MatchCall_Text_Scott6[];
extern const u8 MatchCall_Text_Scott7[];

extern const u8 MatchCall_Text_Roxanne1[];
extern const u8 MatchCall_Text_Roxanne2[];
extern const u8 MatchCall_Text_Roxanne3[];
extern const u8 MatchCall_Text_Roxanne4[];

extern const u8 MatchCall_Text_Brawly1[];
extern const u8 MatchCall_Text_Brawly2[];
extern const u8 MatchCall_Text_Brawly3[];
extern const u8 MatchCall_Text_Brawly4[];

extern const u8 MatchCall_Text_Wattson1[];
extern const u8 MatchCall_Text_Wattson2[];
extern const u8 MatchCall_Text_Wattson3[];
extern const u8 MatchCall_Text_Wattson4[];

extern const u8 MatchCall_Text_Flannery1[];
extern const u8 MatchCall_Text_Flannery2[];
extern const u8 MatchCall_Text_Flannery3[];
extern const u8 MatchCall_Text_Flannery4[];

extern const u8 MatchCall_Text_Winona1[];
extern const u8 MatchCall_Text_Winona2[];
extern const u8 MatchCall_Text_Winona3[];
extern const u8 MatchCall_Text_Winona4[];

extern const u8 MatchCall_Text_TateLiza1[];
extern const u8 MatchCall_Text_TateLiza2[];
extern const u8 MatchCall_Text_TateLiza3[];
extern const u8 MatchCall_Text_TateLiza4[];

extern const u8 MatchCall_Text_Juan1[];
extern const u8 MatchCall_Text_Juan2[];
extern const u8 MatchCall_Text_Juan3[];
extern const u8 MatchCall_Text_Juan4[];

extern const u8 MatchCall_Text_Sidney[];
extern const u8 MatchCall_Text_Phoebe[];
extern const u8 MatchCall_Text_Glacia[];
extern const u8 MatchCall_Text_Drake[];
extern const u8 MatchCall_Text_Wallace[];

// .rodata

static const match_call_text_data_t sMrStoneTextScripts[] = {
    { MatchCall_Text_MrStone1,  0xFFFF,                              FLAG_ENABLE_MR_STONE_POKENAV },
    { MatchCall_Text_MrStone2,  FLAG_ENABLE_MR_STONE_POKENAV,        0xFFFF },
    { MatchCall_Text_MrStone3,  FLAG_DELIVERED_STEVEN_LETTER,        0xFFFF },
    { MatchCall_Text_MrStone4,  FLAG_RECEIVED_EXP_SHARE,             0xFFFF },
    { MatchCall_Text_MrStone5,  FLAG_RECEIVED_HM04,                  0xFFFF },
    { MatchCall_Text_MrStone6,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_MrStone7,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_MrStone8,  FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_MrStone9,  FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_MrStone10, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_MrStone11, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStruct0 sMrStoneMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = 0xFFFF,
    .desc = gText_MrStoneMatchCallDesc,
    .name = gText_MrStoneMatchCallName,
    .textData = sMrStoneTextScripts
};

static const match_call_text_data_t sNormanTextScripts[] = {
    { MatchCall_Text_Norman1, FLAG_ENABLE_NORMAN_MATCH_CALL, 0xFFFF },
    { MatchCall_Text_Norman2, FLAG_DEFEATED_DEWFORD_GYM,     0xFFFF },
    { MatchCall_Text_Norman3, FLAG_DEFEATED_LAVARIDGE_GYM,   0xFFFF },
    { MatchCall_Text_Norman4, FLAG_DEFEATED_PETALBURG_GYM,   0xFFFF },
    { MatchCall_Text_Norman5, FLAG_RECEIVED_RED_OR_BLUE_ORB, 0xFFFF },
    { MatchCall_Text_Norman6, 0xFFFE,                        0xFFFF },
    { MatchCall_Text_Norman7, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman8, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { MatchCall_Text_Norman9, FLAG_SYS_GAME_CLEAR,           0xFFFF },
    { NULL,                   0xFFFF,                        0xFFFF }
};

static const struct MatchCallStruct5 sNormanMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_PETALBURG_CITY,
    .flag = FLAG_ENABLE_NORMAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_NORMAN,
    .desc = gText_NormanMatchCallDesc,
    .name = gText_NormanMatchCallName,
    .textData = sNormanTextScripts
};

static const struct MatchCallStruct3 sProfBirchMatchCallHeader =
{
    .type = 3,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_BIRCH_MATCH_CALL,
    .desc = gText_ProfBirchMatchCallDesc,
    .name = gText_ProfBirchMatchCallName
};

static const match_call_text_data_t sMomTextScripts[] = {
    { MatchCall_Text_Mom1, 0xFFFF,                      0xFFFF },
    { MatchCall_Text_Mom2, FLAG_DEFEATED_PETALBURG_GYM, 0xFFFF },
    { MatchCall_Text_Mom3, FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                0xFFFF,                      0xFFFF }
};

static const struct MatchCallStruct0 sMomMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_LITTLEROOT_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = gText_MomMatchCallDesc,
    .name = gText_MomMatchCallName,
    .textData = sMomTextScripts
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { MatchCall_Text_Steven1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Steven2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Steven3, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Steven4, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Steven5, FLAG_DEFEATED_MOSSDEEP_GYM,          0xFFFF },
    { MatchCall_Text_Steven6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Steven7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                   0xFFFF,                              0xFFFF },
};

static const struct MatchCallStruct0 sStevenMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = gText_StevenMatchCallDesc,
    .name = gText_StevenMatchCallName,
    .textData = sStevenTextScripts
};

static const match_call_text_data_t sMayTextScripts[] = {
    { MatchCall_Text_May1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_May2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_May3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_May4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_May5,  FLAG_RECEIVED_HM04,                  0xFFFF },
    { MatchCall_Text_May6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_May7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_May8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_May9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_May10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_May11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_May12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_May13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_May14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_May15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                 0xFFFF,                              0xFFFF }
};

static const struct MatchCallStruct4 sMayMatchCallHeader =
{
    .type = 4,
    .gender = MALE, //Gender of player
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_May,
    .textData = sMayTextScripts
};

static const match_call_text_data_t sBrendanTextScripts[] = {
    { MatchCall_Text_Brendan1,  0xFFFF,                              0xFFFF },
    { MatchCall_Text_Brendan2,  FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { MatchCall_Text_Brendan3,  FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { MatchCall_Text_Brendan4,  FLAG_HIDE_MAUVILLE_CITY_WALLY,       0xFFFF },
    { MatchCall_Text_Brendan5,  FLAG_RECEIVED_HM04,                  0xFFFF },
    { MatchCall_Text_Brendan6,  FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Brendan7,  FLAG_DEFEATED_PETALBURG_GYM,         0xFFFF },
    { MatchCall_Text_Brendan8,  FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Brendan9,  FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Brendan10, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Brendan11, FLAG_MET_TEAM_AQUA_HARBOR,           0xFFFF },
    { MatchCall_Text_Brendan12, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Brendan13, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Brendan14, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Brendan15, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                     0xFFFF,                              0xFFFF }
};

static const struct MatchCallStruct4 sBrendanMatchCallHeader =
{
    .type = 4,
    .gender = FEMALE, //Gender of player
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gText_MayBrendanMatchCallDesc,
    .name = gText_ExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts
};

static const match_call_text_data_t sWallyTextScripts[] = {
    { MatchCall_Text_Wally1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Wally2, FLAG_RUSTURF_TUNNEL_OPENED,          0xFFFF },
    { MatchCall_Text_Wally3, FLAG_DEFEATED_LAVARIDGE_GYM,         0xFFFF },
    { MatchCall_Text_Wally4, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Wally5, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { MatchCall_Text_Wally6, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { MatchCall_Text_Wally7, FLAG_DEFEATED_WALLY_VICTORY_ROAD,    0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};

const struct MatchCallSubstruct2 sWallyAdditionalData[] = {
    { FLAG_HIDE_MAUVILLE_CITY_WALLY,          MAPSEC_VERDANTURF_TOWN },
    { FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,    MAPSEC_NONE },
    { FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY,  MAPSEC_VICTORY_ROAD },
    { 0xFFFF,                                 MAPSEC_NONE }
};

static const struct MatchCallStruct2 sWallyMatchCallHeader =
{
    .type = 2,
    .mapSec = 0,
    .flag = FLAG_ENABLE_WALLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_WALLY_3,
    .desc = gText_WallyMatchCallDesc,
    .textData = sWallyTextScripts,
    .v10 = sWallyAdditionalData
};

static const match_call_text_data_t sScottTextScripts[] = {
    { MatchCall_Text_Scott1, 0xFFFF,                              0xFFFF },
    { MatchCall_Text_Scott2, FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY,  0xFFFF },
    { MatchCall_Text_Scott3, FLAG_RECEIVED_CASTFORM,              0xFFFF },
    { MatchCall_Text_Scott4, FLAG_RECEIVED_RED_OR_BLUE_ORB,       0xFFFF },
    { MatchCall_Text_Scott5, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 0xFFFF },
    { MatchCall_Text_Scott6, FLAG_DEFEATED_SOOTOPOLIS_GYM,        0xFFFF },
    { MatchCall_Text_Scott7, FLAG_SYS_GAME_CLEAR,                 0xFFFF },
    { NULL,                  0xFFFF,                              0xFFFF }
};


static const struct MatchCallStruct0 sScottMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = gText_ScottMatchCallDesc,
    .name = gText_ScottMatchCallName,
    .textData = sScottTextScripts
};

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { MatchCall_Text_Roxanne1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Roxanne2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Roxanne4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sRoxanneMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = REMATCH_ROXANNE,
    .desc = gText_RoxanneMatchCallDesc,
    .name = NULL,
    .textData = sRoxanneTextScripts
};

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { MatchCall_Text_Brawly1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Brawly2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Brawly4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sBrawlyMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_DEWFORD_TOWN,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_BRAWLY,
    .desc = gText_BrawlyMatchCallDesc,
    .name = NULL,
    .textData = sBrawlyTextScripts
};

static const match_call_text_data_t sWattsonTextScripts[] = {
    { MatchCall_Text_Wattson1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Wattson2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Wattson4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                    0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sWattsonMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_MAUVILLE_CITY,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = REMATCH_WATTSON,
    .desc = gText_WattsonMatchCallDesc,
    .name = NULL,
    .textData = sWattsonTextScripts
};

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { MatchCall_Text_Flannery1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Flannery2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Flannery4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sFlanneryMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_LAVARIDGE_TOWN,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = REMATCH_FLANNERY,
    .desc = gText_FlanneryMatchCallDesc,
    .name = NULL,
    .textData = sFlanneryTextScripts
};

static const match_call_text_data_t sWinonaTextScripts[] = {
    { MatchCall_Text_Winona1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Winona2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Winona4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                   0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sWinonaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_FORTREE_CITY,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = REMATCH_WINONA,
    .desc = gText_WinonaMatchCallDesc,
    .name = NULL,
    .textData = sWinonaTextScripts
};

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { MatchCall_Text_TateLiza1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_TateLiza2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_TateLiza4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sTateLizaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_MOSSDEEP_CITY,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = REMATCH_TATE_AND_LIZA,
    .desc = gText_TateLizaMatchCallDesc,
    .name = NULL,
    .textData = sTateLizaTextScripts
};

static const match_call_text_data_t sJuanTextScripts[] = {
    { MatchCall_Text_Juan1, 0xFFFE,              0xFFFF },
    { MatchCall_Text_Juan2, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan3, 0xFFFF,              0xFFFF },
    { MatchCall_Text_Juan4, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                 0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sJuanMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_SOOTOPOLIS_CITY,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_JUAN,
    .desc = gText_JuanMatchCallDesc,
    .name = NULL,
    .textData = sJuanTextScripts
};

static const match_call_text_data_t sSidneyTextScripts[] = {
    { MatchCall_Text_Sidney, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sSidneyMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_SIDNEY,
    .rematchTableIdx = REMATCH_SIDNEY,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sSidneyTextScripts
};

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { MatchCall_Text_Phoebe, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sPhoebeMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_PHOEBE,
    .rematchTableIdx = REMATCH_PHOEBE,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sPhoebeTextScripts
};

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { MatchCall_Text_Glacia, 0xFFFF, 0xFFFF },
    { NULL,                  0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sGlaciaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_GLACIA,
    .rematchTableIdx = REMATCH_GLACIA,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sGlaciaTextScripts
};

static const match_call_text_data_t sDrakeTextScripts[] = {
    { MatchCall_Text_Drake, 0xFFFF, 0xFFFF },
    { NULL,                 0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sDrakeMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_DRAKE,
    .rematchTableIdx = REMATCH_DRAKE,
    .desc = gText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sDrakeTextScripts
};

static const match_call_text_data_t sWallaceTextScripts[] = {
    { MatchCall_Text_Wallace, 0xFFFF, 0xFFFF },
    { NULL,                   0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sWallaceMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_WALLACE,
    .rematchTableIdx = REMATCH_WALLACE,
    .desc = gText_ChampionMatchCallDesc,
    .name = NULL,
    .textData = sWallaceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    [MC_HEADER_MR_STONE]   = {.type0 = &sMrStoneMatchCallHeader},
    [MC_HEADER_PROF_BIRCH] = {.type3 = &sProfBirchMatchCallHeader},
    [MC_HEADER_BRENDAN]    = {.type4 = &sBrendanMatchCallHeader},
    [MC_HEADER_MAY]        = {.type4 = &sMayMatchCallHeader},
    [MC_HEADER_WALLY]      = {.type2 = &sWallyMatchCallHeader},
    [MC_HEADER_NORMAN]     = {.type5 = &sNormanMatchCallHeader},
    [MC_HEADER_MOM]        = {.type0 = &sMomMatchCallHeader},
    [MC_HEADER_STEVEN]     = {.type0 = &sStevenMatchCallHeader},
    [MC_HEADER_SCOTT]      = {.type0 = &sScottMatchCallHeader},
    [MC_HEADER_ROXANNE]    = {.type5 = &sRoxanneMatchCallHeader},
    [MC_HEADER_BRAWLY]     = {.type5 = &sBrawlyMatchCallHeader},
    [MC_HEADER_WATTSON]    = {.type5 = &sWattsonMatchCallHeader},
    [MC_HEADER_FLANNERY]   = {.type5 = &sFlanneryMatchCallHeader},
    [MC_HEADER_WINONA]     = {.type5 = &sWinonaMatchCallHeader},
    [MC_HEADER_TATE_LIZA]  = {.type5 = &sTateLizaMatchCallHeader},
    [MC_HEADER_JUAN]       = {.type5 = &sJuanMatchCallHeader},
    [MC_HEADER_SIDNEY]     = {.type5 = &sSidneyMatchCallHeader},
    [MC_HEADER_PHOEBE]     = {.type5 = &sPhoebeMatchCallHeader},
    [MC_HEADER_GLACIA]     = {.type5 = &sGlaciaMatchCallHeader},
    [MC_HEADER_DRAKE]      = {.type5 = &sDrakeMatchCallHeader},
    [MC_HEADER_WALLACE]    = {.type5 = &sWallaceMatchCallHeader}
};

static bool32 (*const sMatchCallGetFlagFuncs[])(match_call_t) = {
    MatchCallGetFlag_Type0,
    MatchCallGetFlag_Type1,
    MatchCallGetFlag_Type2,
    MatchCallGetFlag_Type4,
    MatchCallGetFlag_Type3
};

static u8 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCallGetMapSec_Type0,
    MatchCallGetMapSec_Type1,
    MatchCallGetMapSec_Type2,
    MatchCallGetMapSec_Type4,
    MatchCallGetMapSec_Type3
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_Type0,
    MatchCall_IsRematchable_Type1,
    MatchCall_IsRematchable_Type2,
    MatchCall_IsRematchable_Type4,
    MatchCall_IsRematchable_Type3
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_Type0,
    MatchCall_HasCheckPage_Type1,
    MatchCall_HasCheckPage_Type2,
    MatchCall_HasCheckPage_Type4,
    MatchCall_HasCheckPage_Type3
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_Type0,
    MatchCall_GetRematchTableIdx_Type1,
    MatchCall_GetRematchTableIdx_Type2,
    MatchCall_GetRematchTableIdx_Type4,
    MatchCall_GetRematchTableIdx_Type3
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_Type0,
    MatchCall_GetMessage_Type1,
    MatchCall_GetMessage_Type2,
    MatchCall_GetMessage_Type4,
    MatchCall_GetMessage_Type3
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_Type0,
    MatchCall_GetNameAndDesc_Type1,
    MatchCall_GetNameAndDesc_Type2,
    MatchCall_GetNameAndDesc_Type4,
    MatchCall_GetNameAndDesc_Type3
};

static const struct MatchCallOverride sMatchCallCheckPageOverrides[] = {
    { 
        .idx = MC_HEADER_STEVEN,  
        .facilityClass = FACILITY_CLASS_STEVEN,  
        .flag = 0xFFFF,                     
        .flavorTexts = { 
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy, 
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon, 
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle, 
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle 
        } 
    },
    { 
        .idx = MC_HEADER_STEVEN,  
        .facilityClass = FACILITY_CLASS_STEVEN,  
        .flag = FLAG_DEFEATED_MOSSDEEP_GYM, 
        .flavorTexts = { 
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy, 
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon, 
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle, 
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle 
        } 
    },
    { 
        .idx = MC_HEADER_BRENDAN, 
        .facilityClass = FACILITY_CLASS_BRENDAN, 
        .flag = 0xFFFF,                     
        .flavorTexts = MCFLAVOR(Brendan)
    },
    { 
        .idx = MC_HEADER_MAY,     
        .facilityClass = FACILITY_CLASS_MAY,     
        .flag = 0xFFFF,                     
        .flavorTexts = MCFLAVOR(May)
    }
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCallFlagGetByIndex(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetFlagFuncs[i](matchCall);
}

static bool32 MatchCallGetFlag_Type0(match_call_t matchCall)
{
    if (matchCall.type0->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.type0->flag);
}

static bool32 MatchCallGetFlag_Type1(match_call_t matchCall)
{
    if (matchCall.type1->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.type1->flag);
}

static bool32 MatchCallGetFlag_Type2(match_call_t matchCall)
{
    if (matchCall.type2->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.type2->flag);
}

static bool32 MatchCallGetFlag_Type4(match_call_t matchCall)
{
    if (matchCall.type4->gender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.type4->flag);
}

static bool32 MatchCallGetFlag_Type3(match_call_t matchCall)
{
    return FlagGet(matchCall.type3->flag);
}

u8 MatchCallMapSecGetByIndex(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u8 MatchCallGetMapSec_Type0(match_call_t matchCall)
{
    return matchCall.type0->mapSec;
}

static u8 MatchCallGetMapSec_Type1(match_call_t matchCall)
{
    return matchCall.type1->mapSec;
}

static u8 MatchCallGetMapSec_Type2(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.type2->v10[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.type2->v10[i].flag))
            break;
    }
    return matchCall.type2->v10[i].mapSec;
}

static u8 MatchCallGetMapSec_Type4(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

static u8 MatchCallGetMapSec_Type3(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_Type0(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Type1(match_call_t matchCall)
{
    if (matchCall.type1->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.type1->rematchTableIdx] ? TRUE : FALSE;
}

static bool32 MatchCall_IsRematchable_Type2(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.type2->rematchTableIdx] ? TRUE : FALSE;
}

static bool32 MatchCall_IsRematchable_Type4(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Type3(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Type0(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Type1(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Type2(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Type4(match_call_t matchCall) 
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Type3(match_call_t matchCall) 
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_Type0(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Type1(match_call_t matchCall)
{
    return matchCall.type1->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Type2(match_call_t matchCall)
{
    return matchCall.type2->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Type4(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Type3(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_Type0(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type0->textData, dest);
}

static void MatchCall_GetMessage_Type1(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != 5)
        sub_81D1920(matchCall.type1->textData, dest);
    else
        sub_81D199C(matchCall.type5->textData, matchCall.type5->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Type2(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type2->textData, dest);
}

static void MatchCall_GetMessage_Type4(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type4->textData, dest);
}

static void MatchCall_GetMessage_Type3(match_call_t matchCall, u8 *dest)
{
    sub_8197080(dest);
}

static void sub_81D1920(const match_call_text_data_t *sub0, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (sub0[i].flag != 0xFFFF && FlagGet(sub0[i].flag) == TRUE)
            break;
        i--;
    }
    if (sub0[i].flag2 != 0xFFFF)
        FlagSet(sub0[i].flag2);
    StringExpandPlaceholders(dest, sub0[i].text);
}

static void sub_81D199C(const match_call_text_data_t *sub0, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
    {
        if (sub0[i].flag == 0xfffe)
            break;
        if (sub0[i].flag != 0xFFFF && !FlagGet(sub0[i].flag))
            break;
    }
    if (sub0[i].flag != 0xfffe)
    {
        if (i)
            i--;
        if (sub0[i].flag2 != 0xFFFF)
            FlagSet(sub0[i].flag2);
        StringExpandPlaceholders(dest, sub0[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, sub0[i].text);
    }
}

void sub_81D1A78(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_Type0(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.type0->desc;
    *name = matchCall.type0->name;
}

static void MatchCall_GetNameAndDesc_Type1(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.type1->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.type1->rematchTableIdx, desc, name);
    else
        *name = _matchCall.type1->name;
    *desc = _matchCall.type1->desc;
}

static void MatchCall_GetNameAndDesc_Type2(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    MatchCall_GetNameAndDescByRematchIdx(matchCall.type2->rematchTableIdx, desc, name);
    *desc = matchCall.type2->desc;
}

static void MatchCall_GetNameAndDesc_Type4(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.type4->desc;
    *name = matchCall.type4->name;
}

static void MatchCall_GetNameAndDesc_Type3(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.type3->desc;
    *name = matchCall.type3->name;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
        {
            while (1)
            {
                if (i + 1 >= ARRAY_COUNT(sMatchCallCheckPageOverrides))
                    break;
                if (sMatchCallCheckPageOverrides[i + 1].idx != idx)
                    break;
                if (!FlagGet(sMatchCallCheckPageOverrides[i + 1].flag))
                    break;
                i++;
            }
            return sMatchCallCheckPageOverrides[i].flavorTexts[offset];
        }
    }
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
            return sMatchCallCheckPageOverrides[i].facilityClass;
    }
    return -1;
}

bool32 sub_81D1BF8(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
