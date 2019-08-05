#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "constants/region_map_sections.h"

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

struct UnkStruct_08625388 {
    u16 idx;
    u16 v2;
    u32 v4;
    const u8 *v8[4];
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

static bool32 sub_81D1840(match_call_t);
static bool32 sub_81D1844(match_call_t);
static bool32 sub_81D1848(match_call_t);
static bool32 sub_81D184C(match_call_t);
static bool32 sub_81D1850(match_call_t);

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

extern const u8 gText_MrStone_Pokenav_2B60C0[];
extern const u8 gText_MrStone_Pokenav_2B61E6[];
extern const u8 gText_MrStone_Pokenav_2B6302[];
extern const u8 gText_MrStone_Pokenav_2B63A0[];
extern const u8 gText_MrStone_Pokenav_2B64A2[];
extern const u8 gText_MrStone_Pokenav_2B6526[];
extern const u8 gText_MrStone_Pokenav_2B65BB[];
extern const u8 gText_MrStone_Pokenav_2B6664[];
extern const u8 gText_MrStone_Pokenav_2B66B1[];
extern const u8 gText_MrStone_Pokenav_2B6703[];
extern const u8 gText_MrStone_Pokenav_2B67ED[];

extern const u8 gMrStoneMatchCallDesc[];
extern const u8 gMrStoneMatchCallName[];

extern const u8 gText_Norman_Pokenav_2B5719[];
extern const u8 gText_Norman_Pokenav_2B5795[];
extern const u8 gText_Norman_Pokenav_2B584D[];
extern const u8 gText_Norman_Pokenav_2B58E3[];
extern const u8 gText_Norman_Pokenav_2B5979[];
extern const u8 gText_Norman_Pokenav_2B5A07[];
extern const u8 gText_Norman_Pokenav_2B5A69[];
extern const u8 gText_Norman_Pokenav_2B5ACF[];
extern const u8 gText_Norman_Pokenav_2B5B5E[];

extern const u8 gNormanMatchCallDesc[];
extern const u8 gNormanMatchCallName[];

extern const u8 gProfBirchMatchCallDesc[];
extern const u8 gProfBirchMatchCallName[];

extern const u8 gText_Mom_Pokenav_2B227B[];
extern const u8 gText_Mom_Pokenav_2B2310[];
extern const u8 gText_Mom_Pokenav_2B23F3[];

extern const u8 gMomMatchCallDesc[];
extern const u8 gMomMatchCallName[];

extern const u8 gText_Steven_Pokenav_2B5B95[];
extern const u8 gText_Steven_Pokenav_2B5C53[];
extern const u8 gText_Steven_Pokenav_2B5CC9[];
extern const u8 gText_Steven_Pokenav_2B5DB4[];
extern const u8 gText_Steven_Pokenav_2B5E26[];
extern const u8 gText_Steven_Pokenav_2B5EA2[];
extern const u8 gText_Steven_Pokenav_2B5ED9[];

extern const u8 gStevenMatchCallDesc[];
extern const u8 gStevenMatchCallName[];

extern const u8 gText_May_Pokenav_2B3AB3[];
extern const u8 gText_May_Pokenav_2B3B3F[];
extern const u8 gText_May_Pokenav_2B3C13[];
extern const u8 gText_May_Pokenav_2B3CF3[];
extern const u8 gText_May_Pokenav_2B3D4B[];
extern const u8 gText_May_Pokenav_2B3DD1[];
extern const u8 gText_May_Pokenav_2B3E69[];
extern const u8 gText_May_Pokenav_2B3ECD[];
extern const u8 gText_May_Pokenav_2B3F2B[];
extern const u8 gText_May_Pokenav_2B3FFB[];
extern const u8 gText_May_Pokenav_2B402B[];
extern const u8 gText_May_Pokenav_2B414B[];
extern const u8 gText_May_Pokenav_2B4228[];
extern const u8 gText_May_Pokenav_2B42E0[];
extern const u8 gText_May_Pokenav_2B4350[];
extern const u8 gMayBrendanMatchCallDesc[];
extern const u8 gExpandedPlaceholder_May[];
extern const u8 gText_Brendan_Pokenav_2B43EF[];
extern const u8 gText_Brendan_Pokenav_2B4486[];
extern const u8 gText_Brendan_Pokenav_2B4560[];
extern const u8 gText_Brendan_Pokenav_2B463F[];
extern const u8 gText_Brendan_Pokenav_2B46B7[];
extern const u8 gText_Brendan_Pokenav_2B4761[];
extern const u8 gText_Brendan_Pokenav_2B47F4[];
extern const u8 gText_Brendan_Pokenav_2B4882[];
extern const u8 gText_Brendan_Pokenav_2B4909[];
extern const u8 gText_Brendan_Pokenav_2B49C4[];
extern const u8 gText_Brendan_Pokenav_2B4A44[];
extern const u8 gText_Brendan_Pokenav_2B4B28[];
extern const u8 gText_Brendan_Pokenav_2B4C15[];
extern const u8 gText_Brendan_Pokenav_2B4CD8[];
extern const u8 gText_Brendan_Pokenav_2B4D46[];
extern const u8 gExpandedPlaceholder_Brendan[];
extern const u8 gText_Wally_Pokenav_2B4DE2[];
extern const u8 gText_Wally_Pokenav_2B4E57[];
extern const u8 gText_Wally_Pokenav_2B4EA5[];
extern const u8 gText_Wally_Pokenav_2B4F41[];
extern const u8 gText_Wally_Pokenav_2B4FF3[];
extern const u8 gText_Wally_Pokenav_2B50B1[];
extern const u8 gText_Wally_Pokenav_2B5100[];
extern const u8 gWallyMatchCallDesc[];
extern const u8 gText_Scott_Pokenav_2B5184[];
extern const u8 gText_Scott_Pokenav_2B5275[];
extern const u8 gText_Scott_Pokenav_2B5323[];
extern const u8 gText_Scott_Pokenav_2B53DB[];
extern const u8 gText_Scott_Pokenav_2B54A5[];
extern const u8 gText_Scott_Pokenav_2B5541[];
extern const u8 gText_Scott_Pokenav_2B56CA[];
extern const u8 gScottMatchCallDesc[];
extern const u8 gScottMatchCallName[];
extern const u8 gText_Roxanne_Pokenav_2B2456[];
extern const u8 gText_Roxanne_Pokenav_2B250E[];
extern const u8 gText_Roxanne_Pokenav_2B25C1[];
extern const u8 gText_Roxanne_Pokenav_2B2607[];
extern const u8 gRoxanneMatchCallDesc[];
extern const u8 gText_Brawly_Pokenav_2B2659[];
extern const u8 gText_Brawly_Pokenav_2B275D[];
extern const u8 gText_Brawly_Pokenav_2B286F[];
extern const u8 gText_Brawly_Pokenav_2B28D1[];
extern const u8 gBrawlyMatchCallDesc[];
extern const u8 gText_Wattson_Pokenav_2B2912[];
extern const u8 gText_Wattson_Pokenav_2B29CA[];
extern const u8 gText_Wattson_Pokenav_2B2AB6[];
extern const u8 gText_Wattson_Pokenav_2B2B01[];
extern const u8 gWattsonMatchCallDesc[];
extern const u8 gText_Flannery_Pokenav_2B2B4D[];
extern const u8 gText_Flannery_Pokenav_2B2C0E[];
extern const u8 gText_Flannery_Pokenav_2B2CF1[];
extern const u8 gText_Flannery_Pokenav_2B2D54[];
extern const u8 gFlanneryMatchCallDesc[];
extern const u8 gText_Winona_Pokenav_2B2DA4[];
extern const u8 gText_Winona_Pokenav_2B2E2B[];
extern const u8 gText_Winona_Pokenav_2B2EC2[];
extern const u8 gText_Winona_Pokenav_2B2F16[];
extern const u8 gWinonaMatchCallDesc[];
extern const u8 gText_TateLiza_Pokenav_2B2F97[];
extern const u8 gText_TateLiza_Pokenav_2B306E[];
extern const u8 gText_TateLiza_Pokenav_2B3158[];
extern const u8 gText_TateLiza_Pokenav_2B31CD[];
extern const u8 gTateLizaMatchCallDesc[];
extern const u8 gText_Juan_Pokenav_2B3249[];
extern const u8 gText_Juan_Pokenav_2B32EC[];
extern const u8 gText_Juan_Pokenav_2B33AA[];
extern const u8 gText_Juan_Pokenav_2B341E[];
extern const u8 gJuanMatchCallDesc[];
extern const u8 gText_Sidney_Pokenav_2B34CC[];
extern const u8 gEliteFourMatchCallDesc[];
extern const u8 gText_Phoebe_Pokenav_2B3561[];
extern const u8 gText_Glacia_Pokenav_2B35E4[];
extern const u8 gText_Drake_Pokenav_2B368B[];
extern const u8 gText_Wallace_Pokenav_2B3790[];
extern const u8 gChampionMatchCallDesc[];
extern const u8 gMatchCallStevenStrategyText[];
extern const u8 gMatchCall_StevenTrainersPokemonText[];
extern const u8 gMatchCall_StevenSelfIntroductionText_Line1_BeforeMeteorFallsBattle[];
extern const u8 gMatchCall_StevenSelfIntroductionText_Line2_BeforeMeteorFallsBattle[];
extern const u8 gMatchCall_StevenSelfIntroductionText_Line1_AfterMeteorFallsBattle[];
extern const u8 gMatchCall_StevenSelfIntroductionText_Line2_AfterMeteorFallsBattle[];
extern const u8 gMatchCall_BrendanStrategyText[];
extern const u8 gMatchCall_BrendanTrainersPokemonText[];
extern const u8 gMatchCall_BrendanSelfIntroductionText_Line1[];
extern const u8 gMatchCall_BrendanSelfIntroductionText_Line2[];
extern const u8 gMatchCall_MayStrategyText[];
extern const u8 gMatchCall_MayTrainersPokemonText[];
extern const u8 gMatchCall_MaySelfIntroductionText_Line1[];
extern const u8 gMatchCall_MaySelfIntroductionText_Line2[];
// .rodata

static const match_call_text_data_t sMrStoneTextScripts[] = {
    { gText_MrStone_Pokenav_2B60C0, 0xFFFF,              FLAG_ENABLE_MR_STONE_POKENAV },
    { gText_MrStone_Pokenav_2B61E6, FLAG_ENABLE_MR_STONE_POKENAV,          0xFFFF },
    { gText_MrStone_Pokenav_2B6302, FLAG_DELIVERED_STEVEN_LETTER,          0xFFFF },
    { gText_MrStone_Pokenav_2B63A0, FLAG_RECEIVED_EXP_SHARE,          0xFFFF },
    { gText_MrStone_Pokenav_2B64A2, FLAG_RECEIVED_HM04,          0xFFFF },
    { gText_MrStone_Pokenav_2B6526, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    { gText_MrStone_Pokenav_2B65BB, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_MrStone_Pokenav_2B6664, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    { gText_MrStone_Pokenav_2B66B1, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_MrStone_Pokenav_2B6703, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_MrStone_Pokenav_2B67ED, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct0 sMrStoneMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = 0xFFFF,
    .desc = gMrStoneMatchCallDesc,
    .name = gMrStoneMatchCallName,
    .textData = sMrStoneTextScripts
};

static const match_call_text_data_t sNormanTextScripts[] = {
    { gText_Norman_Pokenav_2B5719, FLAG_ENABLE_NORMAN_MATCH_CALL,           0xFFFF },
    { gText_Norman_Pokenav_2B5795, FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
    { gText_Norman_Pokenav_2B584D, FLAG_DEFEATED_LAVARIDGE_GYM,           0xFFFF },
    { gText_Norman_Pokenav_2B58E3, FLAG_DEFEATED_PETALBURG_GYM,           0xFFFF },
    { gText_Norman_Pokenav_2B5979, FLAG_RECEIVED_RED_OR_BLUE_ORB,           0xFFFF },
    { gText_Norman_Pokenav_2B5A07, 0xFFFE,               0xFFFF },
    { gText_Norman_Pokenav_2B5A69, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { gText_Norman_Pokenav_2B5ACF, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { gText_Norman_Pokenav_2B5B5E, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { NULL,                        0xFFFF,               0xFFFF }
};

static const struct MatchCallStruct5 sNormanMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_PETALBURG_CITY,
    .flag = FLAG_ENABLE_NORMAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_NORMAN,
    .desc = gNormanMatchCallDesc,
    .name = gNormanMatchCallName,
    .textData = sNormanTextScripts
};

static const struct MatchCallStruct3 sProfBirchMatchCallHeader =
{
    .type = 3,
    .mapSec = 0,
    .flag = FLAG_ENABLE_PROF_BIRCH_MATCH_CALL,
    .desc = gProfBirchMatchCallDesc,
    .name = gProfBirchMatchCallName
};

static const match_call_text_data_t sMomTextScripts[] = {
    { gText_Mom_Pokenav_2B227B, 0xffff,              0xffff },
    { gText_Mom_Pokenav_2B2310, FLAG_DEFEATED_PETALBURG_GYM,          0xffff },
    { gText_Mom_Pokenav_2B23F3, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                     0xffff,              0xffff }
};

static const struct MatchCallStruct0 sMomMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_LITTLEROOT_TOWN,
    .flag = FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = gMomMatchCallDesc,
    .name = gMomMatchCallName,
    .textData = sMomTextScripts
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { gText_Steven_Pokenav_2B5B95, 0xffff,              0xffff },
    { gText_Steven_Pokenav_2B5C53, FLAG_RUSTURF_TUNNEL_OPENED,          0xffff },
    { gText_Steven_Pokenav_2B5CC9, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xffff },
    { gText_Steven_Pokenav_2B5DB4, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xffff },
    { gText_Steven_Pokenav_2B5E26, FLAG_DEFEATED_MOSSDEEP_GYM,          0xffff },
    { gText_Steven_Pokenav_2B5EA2, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xffff },
    { gText_Steven_Pokenav_2B5ED9, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                        0xffff,              0xffff },
};

static const struct MatchCallStruct0 sStevenMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = gStevenMatchCallDesc,
    .name = gStevenMatchCallName,
    .textData = sStevenTextScripts
};

static const match_call_text_data_t sMayTextScripts[] = {
    { gText_May_Pokenav_2B3AB3, 0xFFFF,              0xFFFF },
    { gText_May_Pokenav_2B3B3F, FLAG_DEFEATED_DEWFORD_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3C13, FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { gText_May_Pokenav_2B3CF3, FLAG_HIDE_MAUVILLE_CITY_WALLY,          0xFFFF },
    { gText_May_Pokenav_2B3D4B, FLAG_RECEIVED_HM04,          0xFFFF },
    { gText_May_Pokenav_2B3DD1, FLAG_DEFEATED_LAVARIDGE_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3E69, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3ECD, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_May_Pokenav_2B3F2B, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_May_Pokenav_2B3FFB, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    { gText_May_Pokenav_2B402B, FLAG_MET_TEAM_AQUA_HARBOR,          0xFFFF },
    { gText_May_Pokenav_2B414B, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_May_Pokenav_2B4228, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xFFFF },
    { gText_May_Pokenav_2B42E0, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_May_Pokenav_2B4350, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct4 sBrendanMatchCallHeader =
{
    .type = 4,
    .gender = MALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gMayBrendanMatchCallDesc,
    .name = gExpandedPlaceholder_May,
    .textData = sMayTextScripts
};

static const match_call_text_data_t sBrendanTextScripts[] = {
    { gText_Brendan_Pokenav_2B43EF, 0xFFFF,              0xFFFF },
    { gText_Brendan_Pokenav_2B4486, FLAG_DEFEATED_DEWFORD_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4560, FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { gText_Brendan_Pokenav_2B463F, FLAG_HIDE_MAUVILLE_CITY_WALLY,          0xFFFF },
    { gText_Brendan_Pokenav_2B46B7, FLAG_RECEIVED_HM04,          0xFFFF },
    { gText_Brendan_Pokenav_2B4761, FLAG_DEFEATED_LAVARIDGE_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B47F4, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4882, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4909, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_Brendan_Pokenav_2B49C4, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    { gText_Brendan_Pokenav_2B4A44, FLAG_MET_TEAM_AQUA_HARBOR,          0xFFFF },
    { gText_Brendan_Pokenav_2B4B28, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_Brendan_Pokenav_2B4C15, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xFFFF },
    { gText_Brendan_Pokenav_2B4CD8, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4D46, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct4 sMayMatchCallHeader =
{
    .type = 4,
    .gender = FEMALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gMayBrendanMatchCallDesc,
    .name = gExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts
};

static const match_call_text_data_t sWallyTextScripts[] = {
    { gText_Wally_Pokenav_2B4DE2, 0xFFFF,     0xFFFF },
    { gText_Wally_Pokenav_2B4E57, FLAG_RUSTURF_TUNNEL_OPENED, 0xFFFF },
    { gText_Wally_Pokenav_2B4EA5, FLAG_DEFEATED_LAVARIDGE_GYM, 0xFFFF },
    { gText_Wally_Pokenav_2B4F41, FLAG_RECEIVED_CASTFORM, 0xFFFF },
    { gText_Wally_Pokenav_2B4FF3, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { gText_Wally_Pokenav_2B50B1, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { gText_Wally_Pokenav_2B5100, FLAG_DEFEATED_WALLY_VICTORY_ROAD, 0xFFFF },
    { NULL,                       0xFFFF,     0xFFFF }
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
    .desc = gWallyMatchCallDesc,
    .textData = sWallyTextScripts,
    .v10 = sWallyAdditionalData
};

static const match_call_text_data_t sScottTextScripts[] = {
    { gText_Scott_Pokenav_2B5184, 0xFFFF,              0xFFFF },
    { gText_Scott_Pokenav_2B5275, FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY,          0xFFFF },
    { gText_Scott_Pokenav_2B5323, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_Scott_Pokenav_2B53DB, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_Scott_Pokenav_2B54A5, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_Scott_Pokenav_2B5541, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_Scott_Pokenav_2B56CA, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                       0xFFFF,              0xFFFF }
};


static const struct MatchCallStruct0 sScottMatchCallHeader =
{
    .type = 0,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = gScottMatchCallDesc,
    .name = gScottMatchCallName,
    .textData = sScottTextScripts
};

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { gText_Roxanne_Pokenav_2B2456, 0xFFFE,              0xFFFF },
    { gText_Roxanne_Pokenav_2B250E, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B25C1, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B2607, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sRoxanneMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = REMATCH_ROXANNE,
    .desc = gRoxanneMatchCallDesc,
    .name = NULL,
    .textData = sRoxanneTextScripts
};

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { gText_Brawly_Pokenav_2B2659, 0xFFFE,              0xFFFF },
    { gText_Brawly_Pokenav_2B275D, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B286F, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B28D1, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sBrawlyMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_DEWFORD_TOWN,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_BRAWLY,
    .desc = gBrawlyMatchCallDesc,
    .name = NULL,
    .textData = sBrawlyTextScripts
};

static const match_call_text_data_t sWattsonTextScripts[] = {
    { gText_Wattson_Pokenav_2B2912, 0xFFFE,              0xFFFF },
    { gText_Wattson_Pokenav_2B29CA, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2AB6, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2B01, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sWattsonMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_MAUVILLE_CITY,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = REMATCH_WATTSON,
    .desc = gWattsonMatchCallDesc,
    .name = NULL,
    .textData = sWattsonTextScripts
};

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { gText_Flannery_Pokenav_2B2B4D, 0xFFFE,              0xFFFF },
    { gText_Flannery_Pokenav_2B2C0E, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2CF1, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2D54, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sFlanneryMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_LAVARIDGE_TOWN,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = REMATCH_FLANNERY,
    .desc = gFlanneryMatchCallDesc,
    .name = NULL,
    .textData = sFlanneryTextScripts
};

static const match_call_text_data_t sWinonaTextScripts[] = {
    { gText_Winona_Pokenav_2B2DA4, 0xFFFE,              0xFFFF },
    { gText_Winona_Pokenav_2B2E2B, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2EC2, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2F16, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sWinonaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_FORTREE_CITY,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = REMATCH_WINONA,
    .desc = gWinonaMatchCallDesc,
    .name = NULL,
    .textData = sWinonaTextScripts
};

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { gText_TateLiza_Pokenav_2B2F97, 0xFFFE,              0xFFFF },
    { gText_TateLiza_Pokenav_2B306E, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B3158, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B31CD, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sTateLizaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_MOSSDEEP_CITY,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = REMATCH_TATE_AND_LIZA,
    .desc = gTateLizaMatchCallDesc,
    .name = NULL,
    .textData = sTateLizaTextScripts
};

static const match_call_text_data_t sJuanTextScripts[] = {
    { gText_Juan_Pokenav_2B3249, 0xFFFE,              0xFFFF },
    { gText_Juan_Pokenav_2B32EC, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B33AA, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B341E, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                      0xFFFF,              0xFFFF }
};

static const struct MatchCallStruct5 sJuanMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_SOOTOPOLIS_CITY,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_JUAN,
    .desc = gJuanMatchCallDesc,
    .name = NULL,
    .textData = sJuanTextScripts
};

static const match_call_text_data_t sSidneyTextScripts[] = {
    { gText_Sidney_Pokenav_2B34CC, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sSidneyMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_SIDNEY,
    .rematchTableIdx = REMATCH_SIDNEY,
    .desc = gEliteFourMatchCallDesc,
    .name = NULL,
    .textData = sSidneyTextScripts
};

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { gText_Phoebe_Pokenav_2B3561, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sPhoebeMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_PHOEBE,
    .rematchTableIdx = REMATCH_PHOEBE,
    .desc = gEliteFourMatchCallDesc,
    .name = NULL,
    .textData = sPhoebeTextScripts
};

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { gText_Glacia_Pokenav_2B35E4, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sGlaciaMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_GLACIA,
    .rematchTableIdx = REMATCH_GLACIA,
    .desc = gEliteFourMatchCallDesc,
    .name = NULL,
    .textData = sGlaciaTextScripts
};

static const match_call_text_data_t sDrakeTextScripts[] = {
    { gText_Drake_Pokenav_2B368B, 0xFFFF, 0xFFFF },
    { NULL,                       0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sDrakeMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_DRAKE,
    .rematchTableIdx = REMATCH_DRAKE,
    .desc = gEliteFourMatchCallDesc,
    .name = NULL,
    .textData = sDrakeTextScripts
};

static const match_call_text_data_t sWallaceTextScripts[] = {
    { gText_Wallace_Pokenav_2B3790, 0xFFFF, 0xFFFF },
    { NULL,                         0xFFFF, 0xFFFF }
};

static const struct MatchCallStruct5 sWallaceMatchCallHeader =
{
    .type = 5,
    .mapSec = MAPSEC_EVER_GRANDE_CITY,
    .flag = FLAG_REMATCH_WALLACE,
    .rematchTableIdx = REMATCH_WALLACE,
    .desc = gChampionMatchCallDesc,
    .name = NULL,
    .textData = sWallaceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    {.type0 = &sMrStoneMatchCallHeader},
    {.type3 = &sProfBirchMatchCallHeader},
    {.type4 = &sMayMatchCallHeader},
    {.type4 = &sBrendanMatchCallHeader},
    {.type2 = &sWallyMatchCallHeader},
    {.type5 = &sNormanMatchCallHeader},
    {.type0 = &sMomMatchCallHeader},
    {.type0 = &sStevenMatchCallHeader},
    {.type0 = &sScottMatchCallHeader},
    {.type5 = &sRoxanneMatchCallHeader},
    {.type5 = &sBrawlyMatchCallHeader},
    {.type5 = &sWattsonMatchCallHeader},
    {.type5 = &sFlanneryMatchCallHeader},
    {.type5 = &sWinonaMatchCallHeader},
    {.type5 = &sTateLizaMatchCallHeader},
    {.type5 = &sJuanMatchCallHeader},
    {.type5 = &sSidneyMatchCallHeader},
    {.type5 = &sPhoebeMatchCallHeader},
    {.type5 = &sGlaciaMatchCallHeader},
    {.type5 = &sDrakeMatchCallHeader},
    {.type5 = &sWallaceMatchCallHeader}
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

static bool32 (*const gUnknown_08625338[])(match_call_t) = {
    sub_81D1840,
    sub_81D1844,
    sub_81D1848,
    sub_81D184C,
    sub_81D1850
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

static const struct UnkStruct_08625388 sMatchCallCheckPageOverrides[] = {
    { 7, 0x4B, 0xffff, { gMatchCallStevenStrategyText, gMatchCall_StevenTrainersPokemonText, gMatchCall_StevenSelfIntroductionText_Line1_BeforeMeteorFallsBattle, gMatchCall_StevenSelfIntroductionText_Line2_BeforeMeteorFallsBattle } }, // STEVEN
    { 7, 0x4B, FLAG_DEFEATED_MOSSDEEP_GYM, { gMatchCallStevenStrategyText, gMatchCall_StevenTrainersPokemonText, gMatchCall_StevenSelfIntroductionText_Line1_AfterMeteorFallsBattle, gMatchCall_StevenSelfIntroductionText_Line2_AfterMeteorFallsBattle } }, // STEVEN
    { 2, 0x3c, 0xffff, { gMatchCall_BrendanStrategyText, gMatchCall_BrendanTrainersPokemonText, gMatchCall_BrendanSelfIntroductionText_Line1, gMatchCall_BrendanSelfIntroductionText_Line2 } }, // Brendan
    { 3, 0x3f, 0xffff, { gMatchCall_MayStrategyText, gMatchCall_MayTrainersPokemonText, gMatchCall_MaySelfIntroductionText_Line1, gMatchCall_MaySelfIntroductionText_Line2 } } // May
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
    if (matchCall.type0->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type0->flag);
}

static bool32 MatchCallGetFlag_Type1(match_call_t matchCall)
{
    if (matchCall.type1->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type1->flag);
}

static bool32 MatchCallGetFlag_Type2(match_call_t matchCall)
{
    if (matchCall.type2->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type2->flag);
}

static bool32 MatchCallGetFlag_Type4(match_call_t matchCall)
{
    if (matchCall.type4->gender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xffff)
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

    for (i = 0; matchCall.type2->v10[i].flag != 0xffff; i++)
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

bool32 sub_81D17E8(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (gUnknown_08625338[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 sub_81D1840(match_call_t matchCall)
{
    return FALSE;
}

static bool32 sub_81D1844(match_call_t matchCall)
{
    return TRUE;
}

static bool32 sub_81D1848(match_call_t matchCall)
{
    return TRUE;
}

static bool32 sub_81D184C(match_call_t matchCall)
{
    return FALSE;
}

static bool32 sub_81D1850(match_call_t matchCall)
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
        if (sub0[i].flag != 0xffff && FlagGet(sub0[i].flag) == TRUE)
            break;
        i--;
    }
    if (sub0[i].flag2 != 0xffff)
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
        if (sub0[i].flag != 0xffff && !FlagGet(sub0[i].flag))
            break;
    }
    if (sub0[i].flag != 0xfffe)
    {
        if (i)
            i--;
        if (sub0[i].flag2 != 0xffff)
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

const u8 *sub_81D1B40(u32 idx, u32 offset)
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
                if (!FlagGet(sMatchCallCheckPageOverrides[i + 1].v4))
                    break;
                i++;
            }
            return sMatchCallCheckPageOverrides[i].v8[offset];
        }
    }
    return NULL;
}

int sub_81D1BD0(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sMatchCallCheckPageOverrides); i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
            return sMatchCallCheckPageOverrides[i].v2;
    }
    return -1;
}

bool32 sub_81D1BF8(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 r0 = MatchCall_GetRematchTableIdx(i);
        if (r0 != REMATCH_TABLE_ENTRIES && r0 == idx)
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
