
// Includes
#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"

extern void sub_8197080(u8 *dest);
extern const u8 gTrainerClassNames[][13];

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 v1;
    u16 flag;
};

struct MatchCallStruct0 {
    u8 type;
    u8 v1;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallStruct1 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallSubstruct2 {
    u16 flag;
    u8 v2;
};

struct MatchCallStruct2 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallSubstruct2 *v10;
};

struct MatchCallStruct3 {
    u8 type;
    u8 v1;
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

struct MatchCallStruct5 {
    u8 type;
    u8 v1;
    u16 flag;
    u16 v4;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

#define MATCHCALLDEF(name, type_, ...) \
static const struct MatchCallStruct##type_ name = { \
    .type = type_, \
    __VA_ARGS__ \
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
    u16 v4;
    const u8 *v8[4];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCallGetFlag_Type0(match_call_t);
static bool32 MatchCallGetFlag_Type1(match_call_t);
static bool32 MatchCallGetFlag_Type2(match_call_t);
static bool32 MatchCallGetFlag_Type3(match_call_t);
static bool32 MatchCallGetFlag_Type4(match_call_t);

static u8 sub_81D1714(match_call_t);
static u8 sub_81D1718(match_call_t);
static u8 sub_81D171C(match_call_t);
static u8 sub_81D1750(match_call_t);
static u8 sub_81D1754(match_call_t);

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

MATCHCALLDEF(sMrStoneMatchCallHeader, 0, 10, 0xffff, gMrStoneMatchCallDesc, gMrStoneMatchCallName, sMrStoneTextScripts);

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

MATCHCALLDEF(sNormanMatchCallHeader, 5, 7, FLAG_ENABLE_NORMAN_MATCH_CALL, 0x45, gNormanMatchCallDesc, gNormanMatchCallName, sNormanTextScripts);

MATCHCALLDEF(sProfBirchMatchCallHeader, 3, 0, FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, gProfBirchMatchCallDesc, gProfBirchMatchCallName)

static const match_call_text_data_t sMomTextScripts[] = {
    { gText_Mom_Pokenav_2B227B, 0xffff,              0xffff },
    { gText_Mom_Pokenav_2B2310, FLAG_DEFEATED_PETALBURG_GYM,          0xffff },
    { gText_Mom_Pokenav_2B23F3, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                     0xffff,              0xffff }
};

MATCHCALLDEF(sMomMatchCallHeader, 0, 0, FLAG_ENABLE_MOM_MATCH_CALL, gMomMatchCallDesc, gMomMatchCallName, sMomTextScripts);

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

MATCHCALLDEF(sStevenMatchCallHeader, 0, 0xd5, FLAG_REGISTERED_STEVEN_POKENAV, gStevenMatchCallDesc, gStevenMatchCallName, sStevenTextScripts);

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

MATCHCALLDEF(sMayMatchCallHeader, 4, MALE, FLAG_ENABLE_RIVAL_MATCH_CALL, gMayBrendanMatchCallDesc, gExpandedPlaceholder_May, sMayTextScripts);

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

MATCHCALLDEF(sBrendanMatchCallHeader, 4, FEMALE, FLAG_ENABLE_RIVAL_MATCH_CALL, gMayBrendanMatchCallDesc, gExpandedPlaceholder_Brendan, sBrendanTextScripts);

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
    { FLAG_HIDE_MAUVILLE_CITY_WALLY, 0x05 },
    { FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xD5 },
    { FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY, 0x46 },
    { 0xFFFF,     0xD5 }
};

MATCHCALLDEF(sWallyMatchCallHeader, 2, 0, FLAG_ENABLE_WALLY_MATCH_CALL, REMATCH_WALLY_3, gWallyMatchCallDesc, sWallyTextScripts, sWallyAdditionalData);

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


MATCHCALLDEF(sScottMatchCallHeader, 0, 0xD5, FLAG_ENABLE_SCOTT_MATCH_CALL, gScottMatchCallDesc, gScottMatchCallName, sScottTextScripts);

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { gText_Roxanne_Pokenav_2B2456, 0xFFFE,              0xFFFF },
    { gText_Roxanne_Pokenav_2B250E, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B25C1, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B2607, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sRoxanneMatchCallHeader, 5, 10, FLAG_ENABLE_ROXANNE_MATCH_CALL, 0x41, gRoxanneMatchCallDesc, NULL, sRoxanneTextScripts);

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { gText_Brawly_Pokenav_2B2659, 0xFFFE,              0xFFFF },
    { gText_Brawly_Pokenav_2B275D, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B286F, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B28D1, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sBrawlyMatchCallHeader, 5, 2, FLAG_ENABLE_BRAWLY_MATCH_CALL, 0x42, gBrawlyMatchCallDesc, NULL, sBrawlyTextScripts);

static const match_call_text_data_t sWattsonTextScripts[] = {
    { gText_Wattson_Pokenav_2B2912, 0xFFFE,              0xFFFF },
    { gText_Wattson_Pokenav_2B29CA, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2AB6, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2B01, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sWattsonMatchCallHeader, 5, 9, FLAG_ENABLE_WATTSON_MATCH_CALL, 0x43, gWattsonMatchCallDesc, NULL, sWattsonTextScripts);

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { gText_Flannery_Pokenav_2B2B4D, 0xFFFE,              0xFFFF },
    { gText_Flannery_Pokenav_2B2C0E, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2CF1, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2D54, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sFlanneryMatchCallHeader, 5, 3, FLAG_ENABLE_FLANNERY_MATCH_CALL, 0x44, gFlanneryMatchCallDesc, NULL, sFlanneryTextScripts);

static const match_call_text_data_t sWinonaTextScripts[] = {
    { gText_Winona_Pokenav_2B2DA4, 0xFFFE,              0xFFFF },
    { gText_Winona_Pokenav_2B2E2B, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2EC2, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2F16, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sWinonaMatchCallHeader, 5, 11, FLAG_ENABLE_WINONA_MATCH_CALL, 0x46, gWinonaMatchCallDesc, NULL, sWinonaTextScripts);

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { gText_TateLiza_Pokenav_2B2F97, 0xFFFE,              0xFFFF },
    { gText_TateLiza_Pokenav_2B306E, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B3158, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B31CD, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sTateLizaMatchCallHeader, 5, 13, FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL, 0x47, gTateLizaMatchCallDesc, NULL, sTateLizaTextScripts);

static const match_call_text_data_t sJuanTextScripts[] = {
    { gText_Juan_Pokenav_2B3249, 0xFFFE,              0xFFFF },
    { gText_Juan_Pokenav_2B32EC, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B33AA, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B341E, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                      0xFFFF,              0xFFFF }
};

MATCHCALLDEF(sJuanMatchCallHeader, 5, 14, FLAG_ENABLE_JUAN_MATCH_CALL, 0x48, gJuanMatchCallDesc, NULL, sJuanTextScripts);

static const match_call_text_data_t sSidneyTextScripts[] = {
    { gText_Sidney_Pokenav_2B34CC, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

MATCHCALLDEF(sSidneyMatchCallHeader, 5, 15, FLAG_REMATCH_JUAN, 0x49, gEliteFourMatchCallDesc, NULL, sSidneyTextScripts);

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { gText_Phoebe_Pokenav_2B3561, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

MATCHCALLDEF(sPhoebeMatchCallHeader, 5, 15, FLAG_REMATCH_SIDNEY, 0x4A, gEliteFourMatchCallDesc, NULL, sPhoebeTextScripts);

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { gText_Glacia_Pokenav_2B35E4, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

MATCHCALLDEF(sGlaciaMatchCallHeader, 5, 15, FLAG_REMATCH_PHOEBE, 0x4B, gEliteFourMatchCallDesc, NULL, sGlaciaTextScripts);

static const match_call_text_data_t sDrakeTextScripts[] = {
    { gText_Drake_Pokenav_2B368B, 0xFFFF, 0xFFFF },
    { NULL,                       0xFFFF, 0xFFFF }
};

MATCHCALLDEF(sDrakeMatchCallHeader, 5, 15, FLAG_REMATCH_GLACIA, 0x4C, gEliteFourMatchCallDesc, NULL, sDrakeTextScripts);

static const match_call_text_data_t sWallaceTextScripts[] = {
    { gText_Wallace_Pokenav_2B3790, 0xFFFF, 0xFFFF },
    { NULL,                         0xFFFF, 0xFFFF }
};

MATCHCALLDEF(sWallaceMatchCallHeader, 5, 15, FLAG_REMATCH_DRAKE, 0x4D, gChampionMatchCallDesc, NULL, sWallaceTextScripts);

static const match_call_t sMatchCallHeaders[] = {
    {.type0 = &sMrStoneMatchCallHeader},
    {.type3 = &sProfBirchMatchCallHeader},
    {.type4 = &sBrendanMatchCallHeader},
    {.type4 = &sMayMatchCallHeader},
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
    MatchCallGetFlag_Type3,
    MatchCallGetFlag_Type4
};

static u8 (*const gUnknown_08625310[])(match_call_t) = {
    sub_81D1714,
    sub_81D1718,
    sub_81D171C,
    sub_81D1750,
    sub_81D1754
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_Type0,
    MatchCall_IsRematchable_Type1,
    MatchCall_IsRematchable_Type2,
    MatchCall_IsRematchable_Type3,
    MatchCall_IsRematchable_Type4
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
    MatchCall_GetRematchTableIdx_Type3,
    MatchCall_GetRematchTableIdx_Type4
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_Type0,
    MatchCall_GetMessage_Type1,
    MatchCall_GetMessage_Type2,
    MatchCall_GetMessage_Type3,
    MatchCall_GetMessage_Type4
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_Type0,
    MatchCall_GetNameAndDesc_Type1,
    MatchCall_GetNameAndDesc_Type2,
    MatchCall_GetNameAndDesc_Type3,
    MatchCall_GetNameAndDesc_Type4
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

    if (idx > 20)
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

static bool32 MatchCallGetFlag_Type3(match_call_t matchCall)
{
    if (matchCall.type4->gender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.type4->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.type4->flag);
}

static bool32 MatchCallGetFlag_Type4(match_call_t matchCall)
{
    return FlagGet(matchCall.type3->flag);
}

u8 sub_81D16DC(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return gUnknown_08625310[i](matchCall);
}

static u8 sub_81D1714(match_call_t matchCall)
{
    return matchCall.type0->v1;
}

static u8 sub_81D1718(match_call_t matchCall)
{
    return matchCall.type1->v1;
}

static u8 sub_81D171C(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.type2->v10[i].flag != 0xffff; i++)
    {
        if (!FlagGet(matchCall.type2->v10[i].flag))
            break;
    }
    return matchCall.type2->v10[i].v2;
}

static u8 sub_81D1750(match_call_t matchCall)
{
    return 0xd5;
}

static u8 sub_81D1754(match_call_t matchCall)
{
    return 0xd5;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
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

static bool32 MatchCall_IsRematchable_Type3(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Type4(match_call_t matchCall)
{
    return FALSE;
}

bool32 sub_81D17E8(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (gUnknown_08625338[i](matchCall))
        return TRUE;
    for (i = 0; i < 4; i++)
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

    if (idx > 20)
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

static u32 MatchCall_GetRematchTableIdx_Type3(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Type4(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
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
        sub_81D1920(matchCall.type5->textData, dest);
    else
        sub_81D199C(matchCall.type1->textData, matchCall.type1->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Type2(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type2->textData, dest);
}

static void MatchCall_GetMessage_Type3(match_call_t matchCall, u8 *dest)
{
    sub_81D1920(matchCall.type4->textData, dest);
}

static void MatchCall_GetMessage_Type4(match_call_t matchCall, u8 *dest)
{
    sub_8197080(dest);
}

void sub_81D1920(const match_call_text_data_t *sub0, u8 *dest)
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

#ifdef NONMATCHING
// There's some weird upmerge going on that I cannot replicate at this time.
static void sub_81D199C(const match_call_text_data_t *sub0, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; sub0[i].text != NULL; i++)
    {
        if (sub0[i].flag == 0xfffe)
            break;
        if (sub0[i].flag == 0xffff && !FlagGet(sub0[i].flag))
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
        if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            ;
        else if (gSaveBlock1Ptr->trainerRematches[idx])
            i += 2;
        else if (CountBattledRematchTeams(idx) >= 2)
            i += 3;
        else
            i++;
        StringExpandPlaceholders(dest, sub0[i].text);
    }
}
#else
static NAKED void sub_81D199C(const match_call_text_data_t *sub0, u16 idx, u8 *dest)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmov r10, r2\n"
                    "\tlsls r1, 16\n"
                    "\tlsrs r7, r1, 16\n"
                    "\tmovs r5, 0\n"
                    "\tldr r0, [r6]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r6, 0x4]\n"
                    "\tldr r1, =0x0000fffe\n"
                    "\tcmp r0, r1\n"
                    "\tbeq _081D1A24\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tmov r9, r0\n"
                    "\tmov r8, r1\n"
                    "\tadds r4, r6, 0\n"
                    "_081D19C6:\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r9\n"
                    "\tbeq _081D19D6\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "_081D19D6:\n"
                    "\tadds r4, 0x8\n"
                    "\tadds r5, 0x1\n"
                    "\tldr r0, [r4]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D19E6\n"
                    "\tldrh r0, [r4, 0x4]\n"
                    "\tcmp r0, r8\n"
                    "\tbne _081D19C6\n"
                    "_081D19E6:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldrh r1, [r0, 0x4]\n"
                    "\tldr r0, =0x0000fffe\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A24\n"
                    "\tcmp r5, 0\n"
                    "\tbeq _081D19F8\n"
                    "\tsubs r5, 0x1\n"
                    "_081D19F8:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r4, r0, r6\n"
                    "\tldrh r1, [r4, 0x6]\n"
                    "\tldr r0, =0x0000ffff\n"
                    "\tcmp r1, r0\n"
                    "\tbeq _081D1A0A\n"
                    "\tadds r0, r1, 0\n"
                    "\tbl FlagSet\n"
                    "_081D1A0A:\n"
                    "\tldr r1, [r4]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "\tb _081D1A5C\n"
                    "\t.pool\n"
                    "_081D1A1C:\n"
                    "\tadds r5, 0x2\n"
                    "\tb _081D1A50\n"
                    "_081D1A20:\n"
                    "\tadds r5, 0x3\n"
                    "\tb _081D1A50\n"
                    "_081D1A24:\n"
                    "\tldr r0, =0x00000864\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1A50\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r0]\n"
                    "\tldr r1, =0x000009ca\n"
                    "\tadds r0, r1\n"
                    "\tadds r0, r7\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _081D1A1C\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl CountBattledRematchTeams\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _081D1A20\n"
                    "\tadds r5, 0x1\n"
                    "_081D1A50:\n"
                    "\tlsls r0, r5, 3\n"
                    "\tadds r0, r6\n"
                    "\tldr r1, [r0]\n"
                    "\tmov r0, r10\n"
                    "\tbl StringExpandPlaceholders\n"
                    "_081D1A5C:\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_81D1A78(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx > 20)
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

static void MatchCall_GetNameAndDesc_Type3(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.type4->desc;
    *name = matchCall.type4->name;
}

static void MatchCall_GetNameAndDesc_Type4(match_call_t matchCall, const u8 **desc, const u8 **name)
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

#ifdef NONMATCHING
const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
        {
            for (; i + 1 < 4 && sMatchCallCheckPageOverrides[i + 1].idx == idx; i++)
            {
                if (!FlagGet(sMatchCallCheckPageOverrides[i + 1].v4))
                    break;
            }
            return sMatchCallCheckPageOverrides[i].v8[offset];
        }
    }
    return NULL;
}
#else
NAKED const u8 *sub_81D1B40(u32 idx, u32 offset)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r9\n"
                    "\tmov r6, r8\n"
                    "\tpush {r6,r7}\n"
                    "\tadds r6, r0, 0\n"
                    "\tmovs r5, 0\n"
                    "\tldr r2, =sMatchCallCheckPageOverrides\n"
                    "\tmovs r0, 0x8\n"
                    "\tadds r0, r2\n"
                    "\tmov r9, r0\n"
                    "_081D1B54:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BBC\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tlsls r1, 2\n"
                    "\tmov r8, r1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r2\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbne _081D1BA8\n"
                    "\tldr r7, =sMatchCallCheckPageOverrides\n"
                    "_081D1B7C:\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r1, r7, 0x4\n"
                    "\tadds r0, r1\n"
                    "\tldrh r0, [r0]\n"
                    "\tbl FlagGet\n"
                    "\tlsls r0, 24\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _081D1BA8\n"
                    "\tadds r5, r4, 0\n"
                    "\tadds r4, r5, 0x1\n"
                    "\tcmp r4, 0x3\n"
                    "\tbhi _081D1BA8\n"
                    "\tlsls r0, r4, 1\n"
                    "\tadds r0, r4\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r7\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, r6\n"
                    "\tbeq _081D1B7C\n"
                    "_081D1BA8:\n"
                    "\tlsls r0, r5, 1\n"
                    "\tadds r0, r5\n"
                    "\tlsls r0, 3\n"
                    "\tadd r0, r8\n"
                    "\tadd r0, r9\n"
                    "\tldr r0, [r0]\n"
                    "\tb _081D1BC4\n"
                    "\t.pool\n"
                    "_081D1BBC:\n"
                    "\tadds r5, 0x1\n"
                    "\tcmp r5, 0x3\n"
                    "\tbls _081D1B54\n"
                    "\tmovs r0, 0\n"
                    "_081D1BC4:\n"
                    "\tpop {r3,r4}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r1}\n"
                    "\tbx r1");
}
#endif

s32 sub_81D1BD0(u32 idx)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (sMatchCallCheckPageOverrides[i].idx == idx)
            return sMatchCallCheckPageOverrides[i].v2;
    }
    return -1;
}

bool32 sub_81D1BF8(u32 idx)
{
    s32 i;

    for (i = 0; i < 21; i++)
    {
        u32 r0 = MatchCall_GetRematchTableIdx(i);
        if (r0 != REMATCH_TABLE_ENTRIES && r0 == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    s32 r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
