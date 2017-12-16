#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_transition.h"
#include "main.h"
#include "task.h"
#include "pokemon_3.h"
#include "safari_zone.h"
#include "script.h"
#include "constants/game_stat.h"
#include "event_data.h"
#include "constants/species.h"
#include "songs.h"
#include "metatile_behavior.h"
#include "constants/maps.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "trainer_classes.h"
#include "trainer_ids.h"
#include "random.h"
#include "starter_choose.h"
#include "script_pokemon_80F8.h"
#include "constants/items.h"
#include "palette.h"
#include "window.h"
#include "field_map_obj.h"
#include "event_scripts.h"
#include "trainer_see.h"
#include "field_message_box.h"
#include "trainer.h"
#include "sound.h"
#include "strings.h"
#include "secret_base.h"
#include "string_util.h"

enum
{
    TRAINER_PARAM_LOAD_VAL_8BIT,
    TRAINER_PARAM_LOAD_VAL_16BIT,
    TRAINER_PARAM_LOAD_VAL_32BIT,
    TRAINER_PARAM_CLEAR_VAL_8BIT,
    TRAINER_PARAM_CLEAR_VAL_16BIT,
    TRAINER_PARAM_CLEAR_VAL_32BIT,
    TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR,
};

struct TrainerBattleParameter
{
    void *varPtr;
    u8 ptrType;
};

extern bool8 InBattlePyramid(void);
extern bool8 InBattlePike(void);
extern bool32 InTrainerHill(void);
extern bool32 FieldPoisonEffectIsRunning(void);
extern void overworld_free_bg_tilemaps(void);
extern void prev_quest_postbuffer_cursor_backup_reset(void);
extern void ResetPoisonStepCounter(void);
extern void sub_81BE72C(void);
extern void FreezeMapObjects(void);
extern void sub_808BCF4(void);
extern void sub_80EECC8(void);
extern void c2_exit_to_overworld_1_continue_scripts_restart_music(void);
extern void c2_exit_to_overworld_2_switch(void);
extern void Overworld_ClearSavedMusic(void);
extern void CB2_WhiteOut(void);
extern void sub_80AF6F0(void);
extern void PlayBattleBGM(void);
extern void sub_81DA57C(void);
extern u8 GetSav1Weather(void);
extern u8 Overworld_GetFlashLevel(void);
extern u16 sub_81A9AA8(u8 localId);
extern u16 sub_81D6180(u8 localId);
extern bool8 GetBattlePyramidTrainerFlag(u8 mapObjId);
extern bool8 GetTrainerHillTrainerFlag(u8 mapObjId);
extern bool8 sub_81D5C18(void);
extern void sub_816306C(u8 a0);
extern void sub_8163048(u8 a0);
extern void sub_81A9B04(void);
extern void sub_81D639C(void);
extern void sub_81D6384(void);
extern void sub_81D61E8(void);
extern void sub_80982B8(void);
extern void sub_81A9EDC(u16 a0);
extern void sub_81D572C(u8 a0, u16 arg1);
extern void IncrementGameStat(u8 statId);
extern u32 GetGameStat(u8 statId);

extern u32 gBattleTypeFlags;
extern u8 gBattleOutcome;
extern void (*gFieldCallback)(void);
extern u8 gApproachingTrainerId;
extern u8 gNoOfApproachingTrainers;
extern u16 gUnknown_03006080;

// this file's functions
static void DoBattlePikeWildBattle(void);
static void DoSafariBattle(void);
static void DoStandardWildBattle(void);
static void CB2_EndWildBattle(void);
static void CB2_EndScriptedWildBattle(void);
static u8 GetWildBattleTransition(void);
static u8 GetTrainerBattleTransition(void);
static void sub_80B1218(void);
static void sub_80B1234(void);
static void CB2_GiveStarter(void);
static void CB2_StartFirstBattle(void);
static void CB2_EndFirstBattle(void);
static void CB2_EndTrainerBattle(void);
static bool32 IsPlayerDefeated(u32 battleOutcome);
static u16 GetRematchTrainerId(u16 trainerId);
static void RegisterTrainerInMatchCall(void);
static void HandleRematchVarsOnBattleEnd(void);
static const u8 *GetIntroSpeechOfApproachingTrainer(void);
static const u8 *GetTrainerCantBattleSpeech(void);

// ewram data
EWRAM_DATA static u16 sTrainerBattleMode = 0;
EWRAM_DATA u16 gTrainerBattleOpponent_A = 0;
EWRAM_DATA u16 gTrainerBattleOpponent_B = 0;
EWRAM_DATA u16 gPartnerTrainerId = 0;
EWRAM_DATA static u16 sTrainerMapObjectLocalId = 0;
EWRAM_DATA static u8 *sTrainerAIntroSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBIntroSpeech = NULL;
EWRAM_DATA static u8 *sTrainerADefeatSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBDefeatSpeech = NULL;
EWRAM_DATA static u8 *sTrainerVictorySpeech = NULL;
EWRAM_DATA static u8 *sTrainerCannotBattleSpeech = NULL;
EWRAM_DATA static u8 *sTrainerBattleEndScript = NULL;
EWRAM_DATA static u8 *sTrainerABattleScriptRetAddr = NULL;
EWRAM_DATA static u8 *sTrainerBBattleScriptRetAddr = NULL;
EWRAM_DATA static bool8 sShouldCheckTrainerBScript = FALSE;
EWRAM_DATA static u8 sNoOfPossibleTrainerRetScripts = 0;

// const rom data

// The first transition is used if the enemy pokemon are lower level than our pokemon.
// Otherwise, the second transition is used.
static const u8 sBattleTransitionTable_Wild[][2] =
{
    {B_TRANSITION_SLICE,               B_TRANSITION_WHITEFADE},     // Normal
    {B_TRANSITION_CLOCKWISE_BLACKFADE, B_TRANSITION_GRID_SQUARES},  // Cave
    {B_TRANSITION_BLUR,                B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_WAVE,                B_TRANSITION_RIPPLE},        // Water
};

static const u8 sBattleTransitionTable_Trainer[][2] =
{
    {B_TRANSITION_POKEBALLS_TRAIL, B_TRANSITION_SHARDS},        // Normal
    {B_TRANSITION_SHUFFLE,         B_TRANSITION_BIG_POKEBALL},  // Cave
    {B_TRANSITION_BLUR,            B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_SWIRL,           B_TRANSITION_RIPPLE},        // Water
};

static const u8 sUnknown_0854FE98[] =
{
    B_TRANSITION_29, B_TRANSITION_30, B_TRANSITION_31, B_TRANSITION_32,
    B_TRANSITION_34, B_TRANSITION_35, B_TRANSITION_36, B_TRANSITION_37,
    B_TRANSITION_38, B_TRANSITION_39, B_TRANSITION_40, B_TRANSITION_41
};

static const u8 sUnknown_0854FEA4[] =
{
    B_TRANSITION_31, B_TRANSITION_32, B_TRANSITION_33
};

static const u8 sUnknown_0854FEA7[] =
{
    B_TRANSITION_29, B_TRANSITION_31, B_TRANSITION_32, B_TRANSITION_33
};

static const struct TrainerBattleParameter sOrdinaryBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sOrdinaryNoIntroBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sTrainerBOrdinaryBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_B,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerBIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBBattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sTrainerBContinueScriptBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_B,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerMapObjectLocalId,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerBIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBDefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBBattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

const struct RematchTrainer gRematchTable[REMATCH_TABLE_ENTRIES] =
{
    {{0x0025, 0x0028, 0x0029, 0x002a, 0x002b}, 0x0000, 0x0021},
    {{0x02e1, 0x032c, 0x032d, 0x032e, 0x032f}, 0x0000, 0x0014},
    {{0x002c, 0x002f, 0x0030, 0x0031, 0x0032}, 0x0000, 0x001a},
    {{0x0039, 0x003c, 0x003d, 0x003e, 0x003f}, 0x0000, 0x0018},
    {{0x0040, 0x0043, 0x0044, 0x0045, 0x0046}, 0x0000, 0x0018},
    {{0x02af, 0x02b0, 0x02b1, 0x02b2, 0x02b3}, 0x0000, 0x0027},
    {{0x02ff, 0x033c, 0x033d, 0x033e, 0x033f}, 0x0000, 0x0024},
    {{0x005e, 0x0065, 0x0066, 0x0067, 0x0068}, 0x0000, 0x001a},
    {{0x004e, 0x0054, 0x0055, 0x0056, 0x0057}, 0x0000, 0x001a},
    {{0x006c, 0x006e, 0x006f, 0x0070, 0x0071}, 0x0018, 0x0014},
    {{0x0072, 0x0078, 0x0079, 0x007a, 0x007b}, 0x0000, 0x0013},
    {{0x0090, 0x034c, 0x034d, 0x034e, 0x034f}, 0x0018, 0x0038},
    {{0x007f, 0x0084, 0x0085, 0x0086, 0x0087}, 0x0000, 0x0024},
    {{0x0088, 0x008b, 0x008c, 0x008d, 0x008e}, 0x0000, 0x0013},
    {{0x008f, 0x0093, 0x0094, 0x0095, 0x0096}, 0x0000, 0x001d},
    {{0x009b, 0x00af, 0x00b0, 0x00b1, 0x00b2}, 0x0000, 0x0016},
    {{0x00b7, 0x00b8, 0x00b9, 0x00ba, 0x00bb}, 0x0000, 0x001e},
    {{0x02a0, 0x0338, 0x0339, 0x033a, 0x033b}, 0x0000, 0x002a},
    {{0x00c3, 0x0340, 0x0341, 0x0342, 0x0343}, 0x0000, 0x0026},
    {{0x00c4, 0x00c5, 0x00c6, 0x00c7, 0x00c8}, 0x0000, 0x0021},
    {{0x00ce, 0x00cf, 0x00d0, 0x00d1, 0x00d2}, 0x0000, 0x001d},
    {{0x00d8, 0x00db, 0x00dc, 0x00dd, 0x00de}, 0x0018, 0x000d},
    {{0x02a9, 0x02aa, 0x02ab, 0x02ac, 0x02ad}, 0x0018, 0x0001},
    {{0x00e2, 0x00e4, 0x00e5, 0x00e6, 0x00e7}, 0x0000, 0x0023},
    {{0x00ee, 0x00ef, 0x00f0, 0x00f1, 0x00f2}, 0x0000, 0x0026},
    {{0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd}, 0x0000, 0x0026},
    {{0x00fe, 0x0101, 0x0102, 0x0103, 0x0104}, 0x0000, 0x0024},
    {{0x0118, 0x011a, 0x011b, 0x011c, 0x011d}, 0x0000, 0x001f},
    {{0x0111, 0x0114, 0x0115, 0x0116, 0x0117}, 0x0000, 0x001f},
    {{0x011f, 0x0120, 0x0121, 0x0122, 0x0123}, 0x0000, 0x0020},
    {{0x012e, 0x012f, 0x0130, 0x0131, 0x0132}, 0x0000, 0x0019},
    {{0x0125, 0x0127, 0x0128, 0x0129, 0x012a}, 0x0000, 0x0012},
    {{0x0133, 0x0134, 0x0135, 0x0136, 0x0137}, 0x0000, 0x001e},
    {{0x0139, 0x013a, 0x013b, 0x013c, 0x013d}, 0x0018, 0x000c},
    {{0x013e, 0x0148, 0x0149, 0x014a, 0x014b}, 0x0000, 0x0011},
    {{0x0153, 0x015a, 0x015b, 0x015c, 0x015d}, 0x0000, 0x0015},
    {{0x0178, 0x017b, 0x017c, 0x017d, 0x017e}, 0x0000, 0x002b},
    {{0x0171, 0x0172, 0x0173, 0x0174, 0x0175}, 0x0000, 0x0020},
    {{0x0166, 0x0168, 0x0169, 0x016a, 0x016b}, 0x0000, 0x0019},
    {{0x016c, 0x016d, 0x016e, 0x016f, 0x0170}, 0x0000, 0x0020},
    {{0x0182, 0x0184, 0x0185, 0x0186, 0x0187}, 0x0000, 0x002b},
    {{0x0161, 0x0162, 0x0163, 0x0164, 0x0165}, 0x0000, 0x0019},
    {{0x0179, 0x0334, 0x0335, 0x0336, 0x0337}, 0x0000, 0x0029},
    {{0x0188, 0x0189, 0x018a, 0x018b, 0x018c}, 0x0018, 0x0001},
    {{0x0196, 0x0199, 0x019a, 0x019b, 0x019c}, 0x0000, 0x0023},
    {{0x01a3, 0x01a5, 0x01a6, 0x01a7, 0x01a8}, 0x0000, 0x001c},
    {{0x01ab, 0x01ae, 0x01af, 0x01b0, 0x01b1}, 0x0000, 0x001e},
    {{0x01b2, 0x01b5, 0x01b6, 0x01b7, 0x01b8}, 0x0000, 0x001c},
    {{0x01c1, 0x01d1, 0x01d2, 0x01d3, 0x01d4}, 0x0000, 0x0027},
    {{0x01da, 0x01dd, 0x01de, 0x01df, 0x01e0}, 0x0018, 0x000d},
    {{0x01e1, 0x01e2, 0x01e7, 0x01e8, 0x01e9}, 0x0000, 0x0012},
    {{0x01ec, 0x01f1, 0x01f2, 0x01f3, 0x01f4}, 0x0000, 0x0028},
    {{0x02e4, 0x0330, 0x0331, 0x0332, 0x0333}, 0x0000, 0x0017},
    {{0x0200, 0x0203, 0x0204, 0x0205, 0x0206}, 0x0000, 0x0019},
    {{0x0221, 0x0224, 0x0225, 0x0226, 0x0227}, 0x0000, 0x0020},
    {{0x021a, 0x021d, 0x021e, 0x021f, 0x0220}, 0x0000, 0x0020},
    {{0x0009, 0x0348, 0x0349, 0x034a, 0x034b}, 0x0018, 0x0011},
    {{0x022f, 0x0232, 0x0233, 0x0234, 0x0235}, 0x0000, 0x0022},
    {{0x0228, 0x022b, 0x022c, 0x022d, 0x022e}, 0x0000, 0x0022},
    {{0x025c, 0x025f, 0x0260, 0x0261, 0x0262}, 0x0000, 0x0013},
    {{0x026d, 0x026e, 0x026f, 0x0270, 0x0271}, 0x0018, 0x000b},
    {{0x0273, 0x027c, 0x027d, 0x027e, 0x027f}, 0x0000, 0x001b},
    {{0x0001, 0x0344, 0x0345, 0x0346, 0x0347}, 0x0018, 0x000c},
    {{0x0282, 0x0283, 0x0284, 0x0285, 0x0286}, 0x0018, 0x003e},
    {{0x0291, 0x0292, 0x0293, 0x0294, 0x0294}, 0x0018, 0x002b},
    {{0x0109, 0x0302, 0x0303, 0x0304, 0x0305}, 0x0000, 0x0003},
    {{0x010a, 0x0306, 0x0307, 0x0308, 0x0309}, 0x0000, 0x000b},
    {{0x010b, 0x030a, 0x030b, 0x030c, 0x030d}, 0x0000, 0x0002},
    {{0x010c, 0x030e, 0x030f, 0x0310, 0x0311}, 0x0000, 0x000c},
    {{0x010d, 0x0312, 0x0313, 0x0314, 0x0315}, 0x0000, 0x0000},
    {{0x010e, 0x0316, 0x0317, 0x0318, 0x0319}, 0x0000, 0x0004},
    {{0x010f, 0x031a, 0x031b, 0x031c, 0x031d}, 0x0000, 0x0006},
    {{0x0110, 0x031e, 0x031f, 0x0320, 0x0321}, 0x0000, 0x0007},
    {{0x0105, 0x0105, 0x0105, 0x0105, 0x0105}, 0x0000, 0x0008},
    {{0x0106, 0x0106, 0x0106, 0x0106, 0x0106}, 0x0000, 0x0008},
    {{0x0107, 0x0107, 0x0107, 0x0107, 0x0107}, 0x0000, 0x0008},
    {{0x0108, 0x0108, 0x0108, 0x0108, 0x0108}, 0x0000, 0x0008},
    {{0x014f, 0x014f, 0x014f, 0x014f, 0x014f}, 0x0000, 0x0008},
};

static const u16 sBadgeFlags[8] =
{
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};

#define tState data[0]
#define tTransition data[1]

static void Task_BattleStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!FieldPoisonEffectIsRunning()) // is poison not active?
        {
            BattleTransition_StartOnField(tTransition);
            sub_81BE72C();
            tState++; // go to case 1.
        }
        break;
    case 1:
        if (IsBattleTransitionDone() == TRUE)
        {
            overworld_free_bg_tilemaps();
            SetMainCallback2(CB2_InitBattle);
            prev_quest_postbuffer_cursor_backup_reset();
            ResetPoisonStepCounter();
            DestroyTask(taskId);
        }
        break;
    }
}

static void CreateBattleStartTask(u8 transition, u16 song)
{
    u8 taskId = CreateTask(Task_BattleStart, 1);

    gTasks[taskId].tTransition = transition;
    PlayMapChosenOrBattleBGM(song);
}

#undef tState
#undef tTransition

void BattleSetup_StartWildBattle(void)
{
    if (GetSafariZoneFlag())
        DoSafariBattle();
    else
        DoStandardWildBattle();
}

void BattleSetup_StartBattlePikeWildBattle(void)
{
    DoBattlePikeWildBattle();
}

static void DoStandardWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = 0;
    if (InBattlePyramid())
    {
        VarSet(VAR_0x400E, 0);
        gBattleTypeFlags |= BATTLE_TYPE_PYRAMID;
    }
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartRoamerBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_ROAMER;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

static void DoSafariBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndSafariBattle;
    gBattleTypeFlags = BATTLE_TYPE_SAFARI;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

static void DoBattlePikeWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_PIKE;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

static void DoTrainerBattle(void)
{
    CreateBattleStartTask(GetTrainerBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    sub_80B1234();
}

static void sub_80B0828(void)
{
    if (InBattlePyramid())
        CreateBattleStartTask(sub_80B100C(10), 0);
    else
        CreateBattleStartTask(sub_80B100C(11), 0);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    sub_80B1234();
}

// Initiates battle where Wally catches Ralts
void StartWallyTutorialBattle(void)
{
    CreateMaleMon(&gEnemyParty[0], SPECIES_RALTS, 5);
    ScriptContext2_Enable();
    gMain.savedCallback = c2_exit_to_overworld_1_continue_scripts_restart_music;
    gBattleTypeFlags = BATTLE_TYPE_WALLY_TUTORIAL;
    CreateBattleStartTask(B_TRANSITION_SLICE, 0);
}

void BattleSetup_StartScriptedWildBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartLatiBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartLegendaryBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;

    switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
    {
    default:
    case SPECIES_GROUDON:
        gBattleTypeFlags |= BATTLE_TYPE_GROUDON;
        CreateBattleStartTask(B_TRANSITION_GROUDON, BGM_BATTLE34);
        break;
    case SPECIES_KYOGRE:
        gBattleTypeFlags |= BATTLE_TYPE_KYORGE;
        CreateBattleStartTask(B_TRANSITION_KYORGE, BGM_BATTLE34);
        break;
    case SPECIES_RAYQUAZA:
        gBattleTypeFlags |= BATTLE_TYPE_RAYQUAZA;
        CreateBattleStartTask(B_TRANSITION_RAYQUAZA, BGM_BATTLE_LEGENDARY);
        break;
    case SPECIES_DEOXYS:
        CreateBattleStartTask(B_TRANSITION_BLUR, BGM_FRLG_BATTLE_DEOXYS);
        break;
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
        CreateBattleStartTask(B_TRANSITION_BLUR, BGM_FRLG_BATTLE_LEGENDARY);
        break;
    case SPECIES_MEW:
        CreateBattleStartTask(B_TRANSITION_GRID_SQUARES, BGM_BATTLE_MEW);
        break;
    }

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void StartGroudonKyogreBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_KYOGRE_GROUDON;

    if (gGameVersion == VERSION_RUBY)
        CreateBattleStartTask(B_TRANSITION_SHARDS, BGM_BATTLE34); // GROUDON
    else
        CreateBattleStartTask(B_TRANSITION_RIPPLE, BGM_BATTLE34); // KYOGRE

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void StartRegiBattle(void)
{
    u8 transitionId;
    u16 species;

    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI;

    species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    switch (species)
    {
    case SPECIES_REGIROCK:
        transitionId = B_TRANSITION_REGIROCK;
        break;
    case SPECIES_REGICE:
        transitionId = B_TRANSITION_REGICE;
        break;
    case SPECIES_REGISTEEL:
        transitionId = B_TRANSITION_REGISTEEL;
        break;
    default:
        transitionId = B_TRANSITION_GRID_SQUARES;
        break;
    }
    CreateBattleStartTask(transitionId, BGM_BATTLE36);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

static void CB2_EndWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE && !InBattlePyramid() && !InBattlePike())
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_2_switch);
        gFieldCallback = sub_80AF6F0;
    }
}

static void CB2_EndScriptedWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        if (InBattlePyramid())
            SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        else
            SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
}

u8 BattleSetup_GetTerrainId(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsTallGrass(tileBehavior))
        return BATTLE_TERRAIN_GRASS;
    if (MetatileBehavior_IsLongGrass(tileBehavior))
        return BATTLE_TERRAIN_LONG_GRASS;
    if (MetatileBehavior_IsSandOrDeepSand(tileBehavior))
        return BATTLE_TERRAIN_SAND;

    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
        break;
    case MAP_TYPE_UNDERGROUND:
        if (MetatileBehavior_IsMB_0B(tileBehavior))
            return BATTLE_TERRAIN_BUILDING;
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_POND;
        return BATTLE_TERRAIN_CAVE;
    case MAP_TYPE_INDOOR:
    case MAP_TYPE_SECRET_BASE:
        return BATTLE_TERRAIN_BUILDING;
    case MAP_TYPE_UNDERWATER:
        return BATTLE_TERRAIN_UNDERWATER;
    case MAP_TYPE_6:
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_WATER;
        return BATTLE_TERRAIN_PLAIN;
    }
    if (MetatileBehavior_IsDeepOrOceanWater(tileBehavior))
        return BATTLE_TERRAIN_WATER;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
        return BATTLE_TERRAIN_POND;
    if (MetatileBehavior_IsMountain(tileBehavior))
        return BATTLE_TERRAIN_MOUNTAIN;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (MetatileBehavior_GetBridgeSth(tileBehavior))
            return BATTLE_TERRAIN_POND;
        if (MetatileBehavior_IsBridge(tileBehavior) == TRUE)
            return BATTLE_TERRAIN_WATER;
    }
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE113) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE113))
        return BATTLE_TERRAIN_SAND;
    if (GetSav1Weather() == 8)
        return BATTLE_TERRAIN_SAND;

    return BATTLE_TERRAIN_PLAIN;
}

static u8 GetBattleTransitionTypeByMap(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (Overworld_GetFlashLevel())
        return B_TRANSITION_SHUFFLE;
    if (!MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
            return B_TRANSITION_SWIRL;
        case MAP_TYPE_UNDERWATER:
            return B_TRANSITION_BIG_POKEBALL;
        default:
            return B_TRANSITION_BLUR;
        }
    }
    return B_TRANSITION_BIG_POKEBALL;
}

static u16 GetSumOfPlayerPartyLevel(u8 numMons)
{
    u8 sum = 0;
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);

        if (species != SPECIES_EGG && species != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            sum += GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            if (--numMons == 0)
                break;
        }
    }
    return sum;
}

static u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u8 i;
    u8 sum;
    u32 count = numMons;

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;

    sum = 0;

    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;
            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_CUSTOM_MOVES:
        {
            const struct TrainerMonNoItemCustomMoves *party;
            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_HAS_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;
            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_CUSTOM_MOVES | PARTY_FLAG_HAS_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;
            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    }

    return sum;
}

static u8 GetWildBattleTransition(void)
{
    u8 transitionType = GetBattleTransitionTypeByMap();
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
    {
        if (InBattlePyramid())
            return B_TRANSITION_BLUR;
        else
            return sBattleTransitionTable_Wild[transitionType][0];
    }
    else
    {
        if (InBattlePyramid())
            return B_TRANSITION_GRID_SQUARES;
        else
            return sBattleTransitionTable_Wild[transitionType][1];
    }
}

static u8 GetTrainerBattleTransition(void)
{
    u8 minPartyCount;
    u8 transitionType;
    u8 enemyLevel;
    u8 playerLevel;

    if (gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
        return B_TRANSITION_CHAMPION;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_ELITE_FOUR)
    {
        if (gTrainerBattleOpponent_A == TRAINER_ID_SIDNEY)
            return B_TRANSITION_SYDNEY;
        if (gTrainerBattleOpponent_A == TRAINER_ID_PHOEBE)
            return B_TRANSITION_PHOEBE;
        if (gTrainerBattleOpponent_A == TRAINER_ID_GLACIA)
            return B_TRANSITION_GLACIA;
        if (gTrainerBattleOpponent_A == TRAINER_ID_DRAKE)
            return B_TRANSITION_DRAKE;
        return B_TRANSITION_CHAMPION;
    }

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_CHAMPION)
        return B_TRANSITION_CHAMPION;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_TEAM_MAGMA
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_MAGMA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_MAGMA_ADMIN)
        return B_TRANSITION_MAGMA;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_TEAM_AQUA
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_AQUA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_AQUA_ADMIN)
        return B_TRANSITION_AQUA;

    if (gTrainers[gTrainerBattleOpponent_A].doubleBattle == TRUE)
        minPartyCount = 2; // double battles always at least have 2 pokemon.
    else
        minPartyCount = 1;

    transitionType = GetBattleTransitionTypeByMap();
    enemyLevel = GetSumOfEnemyPartyLevel(gTrainerBattleOpponent_A, minPartyCount);
    playerLevel = GetSumOfPlayerPartyLevel(minPartyCount);

    if (enemyLevel < playerLevel)
        return sBattleTransitionTable_Trainer[transitionType][0];
    else
        return sBattleTransitionTable_Trainer[transitionType][1];
}

u8 sub_80B100C(s32 arg0)
{
    u16 var;
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
    {
        switch (arg0)
        {
        case 11:
        case 12:
        case 13:
            return B_TRANSITION_POKEBALLS_TRAIL;
        case 10:
            return sUnknown_0854FEA4[Random() % ARRAY_COUNT(sUnknown_0854FEA4)];
        case 3:
            return sUnknown_0854FEA7[Random() % ARRAY_COUNT(sUnknown_0854FEA7)];
        }

        if (VarGet(VAR_0x40CE) != 3)
            return sUnknown_0854FE98[Random() % ARRAY_COUNT(sUnknown_0854FE98)];
    }
    else
    {
        switch (arg0)
        {
        case 11:
        case 12:
        case 13:
            return B_TRANSITION_BIG_POKEBALL;
        case 10:
            return sUnknown_0854FEA4[Random() % ARRAY_COUNT(sUnknown_0854FEA4)];
        case 3:
            return sUnknown_0854FEA7[Random() % ARRAY_COUNT(sUnknown_0854FEA7)];
        }

        if (VarGet(VAR_0x40CE) != 3)
            return sUnknown_0854FE98[Random() % ARRAY_COUNT(sUnknown_0854FE98)];
    }

    var = gSaveBlock2Ptr->field_CB4[gSaveBlock2Ptr->battlePyramidWildHeaderId * 2 + 0]
        + gSaveBlock2Ptr->field_CB4[gSaveBlock2Ptr->battlePyramidWildHeaderId * 2 + 1];

    return sUnknown_0854FE98[var % ARRAY_COUNT(sUnknown_0854FE98)];
}

void ChooseStarter(void)
{
    SetMainCallback2(CB2_ChooseStarter);
    gMain.savedCallback = CB2_GiveStarter;
}

static void CB2_GiveStarter(void)
{
    u16 starterMon;

    *GetVarPointer(VAR_FIRST_POKE) = gSpecialVar_Result;
    starterMon = GetStarterPokemon(gSpecialVar_Result);
    ScriptGiveMon(starterMon, 5, 0, 0, 0, 0);
    ResetTasks();
    PlayBattleBGM();
    SetMainCallback2(CB2_StartFirstBattle);
    BattleTransition_Start(B_TRANSITION_BLUR);
}

static void CB2_StartFirstBattle(void)
{
    UpdatePaletteFade();
    RunTasks();

    if (IsBattleTransitionDone() == TRUE)
    {
        gBattleTypeFlags = BATTLE_TYPE_FIRST_BATTLE;
        gMain.savedCallback = CB2_EndFirstBattle;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitBattle);
        prev_quest_postbuffer_cursor_backup_reset();
        ResetPoisonStepCounter();
        IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
        IncrementGameStat(GAME_STAT_WILD_BATTLES);
        sub_80EECC8();
        sub_80B1218();
    }
}

static void CB2_EndFirstBattle(void)
{
    Overworld_ClearSavedMusic();
    SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
}

static void sub_80B1218(void)
{
    if (GetGameStat(GAME_STAT_WILD_BATTLES) % 60 == 0)
        sub_81DA57C();
}

static void sub_80B1234(void)
{
    if (GetGameStat(GAME_STAT_TRAINER_BATTLES) % 20 == 0)
        sub_81DA57C();
}

// why not just use the macros? maybe its because they didnt want to uncast const every time?
static u32 TrainerBattleLoadArg32(const u8 *ptr)
{
    return T1_READ_32(ptr);
}

static u16 TrainerBattleLoadArg16(const u8 *ptr)
{
    return T1_READ_16(ptr);
}

static u8 TrainerBattleLoadArg8(const u8 *ptr)
{
    return T1_READ_8(ptr);
}

static u16 GetTrainerAFlag(void)
{
    return FLAG_TRAINER_FLAG_START + gTrainerBattleOpponent_A;
}

static u16 GetTrainerBFlag(void)
{
    return FLAG_TRAINER_FLAG_START + gTrainerBattleOpponent_B;
}

static bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case BATTLE_LOST:
    case BATTLE_DREW:
        return TRUE;
    case BATTLE_WON:
    case BATTLE_RAN:
    case BATTLE_PLAYER_TELEPORTED:
    case BATTLE_POKE_FLED:
    case BATTLE_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

void ResetTrainerOpponentIds(void)
{
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
}

static void InitTrainerBattleVariables(void)
{
    sTrainerBattleMode = 0;
    if (gApproachingTrainerId == 0)
    {
        sTrainerAIntroSpeech = NULL;
        sTrainerADefeatSpeech = NULL;
        sTrainerABattleScriptRetAddr = NULL;
    }
    else
    {
        sTrainerBIntroSpeech = NULL;
        sTrainerBDefeatSpeech = NULL;
        sTrainerBBattleScriptRetAddr = NULL;
    }
    sTrainerMapObjectLocalId = 0;
    sTrainerVictorySpeech = NULL;
    sTrainerCannotBattleSpeech = NULL;
    sTrainerBattleEndScript = NULL;
}

static inline void SetU8(void *ptr, u8 value)
{
    *(u8*)(ptr) = value;
}

static inline void SetU16(void *ptr, u16 value)
{
    *(u16*)(ptr) = value;
}

static inline void SetU32(void *ptr, u32 value)
{
    *(u32*)(ptr) = value;
}

static inline void SetPtr(const void *ptr, const void* value)
{
    *(const void**)(ptr) = value;
}

static void TrainerBattleLoadArgs(const struct TrainerBattleParameter *specs, const u8 *data)
{
    while (1)
    {
        switch (specs->ptrType)
        {
        case TRAINER_PARAM_LOAD_VAL_8BIT:
            SetU8(specs->varPtr, TrainerBattleLoadArg8(data));
            data += 1;
            break;
        case TRAINER_PARAM_LOAD_VAL_16BIT:
            SetU16(specs->varPtr, TrainerBattleLoadArg16(data));
            data += 2;
            break;
        case TRAINER_PARAM_LOAD_VAL_32BIT:
            SetU32(specs->varPtr, TrainerBattleLoadArg32(data));
            data += 4;
            break;
        case TRAINER_PARAM_CLEAR_VAL_8BIT:
            SetU8(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_16BIT:
            SetU16(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_32BIT:
            SetU32(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR:
            SetPtr(specs->varPtr, data);
            return;
        }
        specs++;
    }
}

void SetMapVarsToTrainer(void)
{
    if (sTrainerMapObjectLocalId != 0)
    {
        gSpecialVar_LastTalked = sTrainerMapObjectLocalId;
        gSelectedMapObject = GetFieldObjectIdByLocalIdAndMap(sTrainerMapObjectLocalId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
}

const u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data)
{
    InitTrainerBattleVariables();
    sTrainerBattleMode = TrainerBattleLoadArg8(data);

    switch (sTrainerBattleMode)
    {
    case 3:
        TrainerBattleLoadArgs(sOrdinaryNoIntroBattleParams, data);
        return EventScript_2713C2;
    case 4:
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case 2:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sContinueScriptBattleParams, data);
            SetMapVarsToTrainer();
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBContinueScriptBattleParams, data);
        }
        return EventScript_271362;
    case 1:
        TrainerBattleLoadArgs(sContinueScriptBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_271362;
    case 6:
    case 8:
        TrainerBattleLoadArgs(sContinueScriptDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case 7:
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_TryDoDoubleRematchBattle;
    case 5:
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_2713D1;
    case 9:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
            gTrainerBattleOpponent_A = sub_81A9AA8(gSpecialVar_LastTalked);
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
            gTrainerBattleOpponent_B = sub_81A9AA8(gSpecialVar_LastTalked);
        }
        return EventScript_271362;
    case 10:
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        return NULL;
    case 11:
        TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
        return NULL;
    case 12:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
            gTrainerBattleOpponent_A = sub_81D6180(gSpecialVar_LastTalked);
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
            gTrainerBattleOpponent_B = sub_81D6180(gSpecialVar_LastTalked);
        }
        return EventScript_271362;
    default:
        if (gApproachingTrainerId == 0)
        {
            TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
            SetMapVarsToTrainer();
        }
        else
        {
            TrainerBattleLoadArgs(sTrainerBOrdinaryBattleParams, data);
        }
        return EventScript_271362;
    }
}

void ConfigureAndSetUpOneTrainerBattle(u8 trainerMapObjId, const u8 *trainerScript)
{
    gSelectedMapObject = trainerMapObjId;
    gSpecialVar_LastTalked = gMapObjects[trainerMapObjId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
    ScriptContext1_SetupScript(EventScript_271354);
    ScriptContext2_Enable();
}

void ConfigureTwoTrainersBattle(u8 trainerMapObjId, const u8 *trainerScript)
{
    gSelectedMapObject = trainerMapObjId;
    gSpecialVar_LastTalked = gMapObjects[trainerMapObjId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
}

void SetUpTwoTrainersBattle(void)
{
    ScriptContext1_SetupScript(EventScript_271354);
    ScriptContext2_Enable();
}

bool32 GetTrainerFlagFromScriptPointer(const u8 *data)
{
    u32 flag = TrainerBattleLoadArg16(data + 2);
    return FlagGet(FLAG_TRAINER_FLAG_START + flag);
}

void sub_80B16D8(void)
{
    struct MapObject *mapObject = &gMapObjects[gSelectedMapObject];

    npc_set_running_behaviour_etc(mapObject, npc_running_behaviour_by_direction(mapObject->mapobj_unk_18));
}

u8 GetTrainerBattleMode(void)
{
    return sTrainerBattleMode;
}

bool8 GetTrainerFlag(void)
{
    if (InBattlePyramid())
        return GetBattlePyramidTrainerFlag(gSelectedMapObject);
    else if (InTrainerHill())
        return GetTrainerHillTrainerFlag(gSelectedMapObject);
    else
        return FlagGet(GetTrainerAFlag());
}

static void SetBattledTrainersFlags(void)
{
    if (gTrainerBattleOpponent_B != 0)
        FlagSet(GetTrainerBFlag());
    FlagSet(GetTrainerAFlag());
}

static void SetBattledTrainerFlag(void)
{
    FlagSet(GetTrainerAFlag());
}

bool8 HasTrainerBeenFought(u16 trainerId)
{
    return FlagGet(FLAG_TRAINER_FLAG_START + trainerId);
}

void SetTrainerFlag(u16 trainerId)
{
    FlagSet(FLAG_TRAINER_FLAG_START + trainerId);
}

void ClearTrainerFlag(u16 trainerId)
{
    FlagClear(FLAG_TRAINER_FLAG_START + trainerId);
}

void BattleSetup_StartTrainerBattle(void)
{
    if (gNoOfApproachingTrainers == 2)
        gBattleTypeFlags = (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER);
    else
        gBattleTypeFlags = (BATTLE_TYPE_TRAINER);

    if (InBattlePyramid())
    {
        VarSet(VAR_0x400E, 0);
        gBattleTypeFlags |= BATTLE_TYPE_PYRAMID;

        if (gNoOfApproachingTrainers == 2)
        {
            sub_816306C(1);
            ZeroMonData(&gEnemyParty[1]);
            ZeroMonData(&gEnemyParty[2]);
            ZeroMonData(&gEnemyParty[4]);
            ZeroMonData(&gEnemyParty[5]);
        }
        else
        {
            sub_8163048(1);
            ZeroMonData(&gEnemyParty[1]);
            ZeroMonData(&gEnemyParty[2]);
        }

        sub_81A9B04();
    }
    else if (sub_81D5C18())
    {
        gBattleTypeFlags |= BATTLE_TYPE_x4000000;

        if (gNoOfApproachingTrainers == 2)
            sub_81D639C();
        else
            sub_81D6384();

        sub_81D61E8();
    }

    sNoOfPossibleTrainerRetScripts = gNoOfApproachingTrainers;
    gNoOfApproachingTrainers = 0;
    sShouldCheckTrainerBScript = FALSE;
    gUnknown_03006080 = 0;
    gMain.savedCallback = CB2_EndTrainerBattle;

    if (InBattlePyramid() || sub_81D5C18())
        sub_80B0828();
    else
        DoTrainerBattle();

    ScriptContext1_Stop();
}

static void CB2_EndTrainerBattle(void)
{
    if (gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        if (InBattlePyramid() || sub_81D5C18())
            SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        else
            SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        if (!InBattlePyramid() && !sub_81D5C18())
        {
            RegisterTrainerInMatchCall();
            SetBattledTrainersFlags();
        }
    }
}

static void CB2_EndRematchBattle(void)
{
    if (gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        RegisterTrainerInMatchCall();
        SetBattledTrainersFlags();
        HandleRematchVarsOnBattleEnd();
    }
}

void BattleSetup_StartRematchBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    gMain.savedCallback = CB2_EndRematchBattle;
    DoTrainerBattle();
    ScriptContext1_Stop();
}

void ShowTrainerIntroSpeech(void)
{
    if (InBattlePyramid())
    {
        if (gNoOfApproachingTrainers == 0 || gNoOfApproachingTrainers == 1)
            sub_81A9EDC(sub_81A9AA8(gSpecialVar_LastTalked));
        else
            sub_81A9EDC(sub_81A9AA8(gMapObjects[gApproachingTrainers[gApproachingTrainerId].mapObjectId].localId));

        sub_80982B8();
    }
    else if (sub_81D5C18())
    {
        if (gNoOfApproachingTrainers == 0 || gNoOfApproachingTrainers == 1)
            sub_81D572C(2, sub_81D6180(gSpecialVar_LastTalked));
        else
            sub_81D572C(2, sub_81D6180(gMapObjects[gApproachingTrainers[gApproachingTrainerId].mapObjectId].localId));

        sub_80982B8();
    }
    else
    {
        ShowFieldMessage(GetIntroSpeechOfApproachingTrainer());
    }
}

const u8 *BattleSetup_GetScriptAddrAfterBattle(void)
{
    if (sTrainerBattleEndScript != NULL)
        return sTrainerBattleEndScript;
    else
        return EventScript_TestSignpostMsg;
}

const u8 *BattleSetup_GetTrainerPostBattleScript(void)
{
    if (sShouldCheckTrainerBScript)
    {
        sShouldCheckTrainerBScript = FALSE;
        if (sTrainerBBattleScriptRetAddr != NULL)
        {
            gUnknown_03006080 = 1;
            return sTrainerBBattleScriptRetAddr;
        }
    }
    else
    {
        if (sTrainerABattleScriptRetAddr != NULL)
        {
            gUnknown_03006080 = 0;
            return sTrainerABattleScriptRetAddr;
        }
    }

    return EventScript_TryGetTrainerScript;
}

void ShowTrainerCantBattleSpeech(void)
{
    ShowFieldMessage(GetTrainerCantBattleSpeech());
}

void SetUpTrainerEncounterMusic(void)
{
    u16 trainerId;
    u16 music;

    if (gApproachingTrainerId == 0)
        trainerId = gTrainerBattleOpponent_A;
    else
        trainerId = gTrainerBattleOpponent_B;

    if (sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
        && sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC)
    {
        switch (GetTrainerEncounterMusicId(trainerId))
        {
        case TRAINER_ENCOUNTER_MUSIC_MALE:
            music = BGM_BOYEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_FEMALE:
            music = BGM_GIRLEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_GIRL:
            music = BGM_SYOUJOEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_INTENSE:
            music = BGM_HAGESHII;
            break;
        case TRAINER_ENCOUNTER_MUSIC_COOL:
            music = BGM_KAKKOII;
            break;
        case TRAINER_ENCOUNTER_MUSIC_AQUA:
            music = BGM_AQA_0;
            break;
        case TRAINER_ENCOUNTER_MUSIC_MAGMA:
            music = BGM_MGM0;
            break;
        case TRAINER_ENCOUNTER_MUSIC_SWIMMER:
            music = BGM_SWIMEYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_TWINS:
            music = BGM_HUTAGO;
            break;
        case TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR:
            music = BGM_SITENNOU;
            break;
        case TRAINER_ENCOUNTER_MUSIC_HIKER:
            music = BGM_YAMA_EYE;
            break;
        case TRAINER_ENCOUNTER_MUSIC_INTERVIEWER:
            music = BGM_INTER_V;
            break;
        case TRAINER_ENCOUNTER_MUSIC_RICH:
            music = BGM_TEST;
            break;
        default:
            music = BGM_AYASII;
        }
        PlayNewMapMusic(music);
    }
}

static const u8 *ReturnEmptyStringIfNull(const u8 *string)
{
    if (string == NULL)
        return gText_EmptyString2;
    else
        return string;
}

static const u8 *GetIntroSpeechOfApproachingTrainer(void)
{
    if (gApproachingTrainerId == 0)
        return ReturnEmptyStringIfNull(sTrainerAIntroSpeech);
    else
        return ReturnEmptyStringIfNull(sTrainerBIntroSpeech);
}

const u8 *GetTrainerALoseText(void)
{
    const u8 *string;

    if (gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
        string = GetSecretBaseTrainerLoseText();
    else
        string = sTrainerADefeatSpeech;

    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(string));
    return gStringVar4;
}

const u8 *GetTrainerBLoseText(void)
{
    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(sTrainerBDefeatSpeech));
    return gStringVar4;
}

const u8 *GetTrainerWonSpeech(void)
{
    return ReturnEmptyStringIfNull(sTrainerVictorySpeech);
}

static const u8 *GetTrainerCantBattleSpeech(void)
{
    return ReturnEmptyStringIfNull(sTrainerCannotBattleSpeech);
}

static s32 FirstBattleTrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].trainerIds[0] == trainerId)
            return i;
    }

    return -1;
}

static s32 TrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId)
{
    s32 i, j;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        for (j = 0; j < REMATCHES_COUNT; j++)
        {
            if (table[i].trainerIds[j] == 0)
                break;
            if (table[i].trainerIds[j] == trainerId)
                return i;
        }
    }

    return -1;
}

static bool32 sub_80B1D94(s32 rematchTableId)
{
    if (rematchTableId >= REMATCH_ELITE_FOUR_ENTRIES)
        return TRUE;
    else if (rematchTableId == REMATCH_WALLY_ENTRY)
        return (FlagGet(FLAG_0x07E) == FALSE);
    else
        return FALSE;
}

static void SetRematchIdForTrainer(const struct RematchTrainer *table, u32 tableId)
{
    s32 i;

    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        u16 trainerId = table[tableId].trainerIds[i];

        if (trainerId == 0)
            break;
        if (!HasTrainerBeenFought(trainerId))
            break;
    }

    gSaveBlock1Ptr->trainerRematches[tableId] = i;
}

static bool32 UpdateRandomTrainerRematches(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;
    bool32 ret = FALSE;

    for (i = 0; i <= REMATCH_WALLY_ENTRY; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum && !sub_80B1D94(i))
        {
            if (gSaveBlock1Ptr->trainerRematches[i] != 0)
            {
                // Trainer already wants a rematch. Don't bother updating it
                ret = TRUE;
            }
            else if (FlagGet(FLAG_MATCH_CALL_REGISTERED + i)
             && (Random() % 100) <= 30)  // 31% chance of getting a rematch
            {
                SetRematchIdForTrainer(table, i);
                ret = TRUE;
            }
        }
    }

    return ret;
}

void UpdateRematchIfDefeated(s32 rematchTableId)
{
    if (HasTrainerBeenFought(gRematchTable[rematchTableId].trainerIds[0]) == TRUE)
        SetRematchIdForTrainer(gRematchTable, rematchTableId);
}

static bool32 DoesSomeoneWantRematchIn_(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum && gSaveBlock1Ptr->trainerRematches[i] != 0)
            return TRUE;
    }

    return FALSE;
}

static bool32 IsRematchTrainerIn_(const struct RematchTrainer *table, u16 mapGroup, u16 mapNum)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (table[i].mapGroup == mapGroup && table[i].mapNum == mapNum)
            return TRUE;
    }

    return FALSE;
}

static bool8 IsFirstTrainerIdReadyForRematch(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;
    if (tableId >= 100)
        return FALSE;
    if (gSaveBlock1Ptr->trainerRematches[tableId] == 0)
        return FALSE;

    return TRUE;
}

static bool8 IsTrainerReadyForRematch_(const struct RematchTrainer *table, u16 trainerId)
{
    s32 tableId = TrainerIdToRematchTableId(table, trainerId);

    if (tableId == -1)
        return FALSE;
    if (tableId >= 100)
        return FALSE;
    if (gSaveBlock1Ptr->trainerRematches[tableId] == 0)
        return FALSE;

    return TRUE;
}

static u16 GetRematchTrainerIdFromTable(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    const struct RematchTrainer *trainerEntry;
    s32 i;
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;

    trainerEntry = &table[tableId];
    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (trainerEntry->trainerIds[i] == 0) // previous entry was this trainer's last one
            return trainerEntry->trainerIds[i - 1];
        if (!HasTrainerBeenFought(trainerEntry->trainerIds[i]))
            return trainerEntry->trainerIds[i];
    }

    return trainerEntry->trainerIds[REMATCHES_COUNT - 1]; // already beaten at max stage
}

static u16 GetLastBeatenRematchTrainerIdFromTable(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    const struct RematchTrainer *trainerEntry;
    s32 i;
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;

    trainerEntry = &table[tableId];
    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (trainerEntry->trainerIds[i] == 0) // previous entry was this trainer's last one
            return trainerEntry->trainerIds[i - 1];
        if (!HasTrainerBeenFought(trainerEntry->trainerIds[i]))
            return trainerEntry->trainerIds[i - 1];
    }

    return trainerEntry->trainerIds[REMATCHES_COUNT - 1]; // already beaten at max stage
}

static void ClearTrainerWantRematchState(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = TrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId != -1)
        gSaveBlock1Ptr->trainerRematches[tableId] = 0;
}

static u32 GetTrainerMatchCallFlag(u32 trainerId)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (gRematchTable[i].trainerIds[0] == trainerId)
            return FLAG_MATCH_CALL_REGISTERED + i;
    }

    return 0xFFFF;
}

static void RegisterTrainerInMatchCall(void)
{
    if (FlagGet(FLAG_HAS_MATCH_CALL))
    {
        u32 matchCallFlagId = GetTrainerMatchCallFlag(gTrainerBattleOpponent_A);
        if (matchCallFlagId != 0xFFFF)
            FlagSet(matchCallFlagId);
    }
}

static bool8 WasSecondRematchWon(const struct RematchTrainer *table, u16 firstBattleTrainerId)
{
    s32 tableId = FirstBattleTrainerIdToRematchTableId(table, firstBattleTrainerId);

    if (tableId == -1)
        return FALSE;
    if (!HasTrainerBeenFought(table[tableId].trainerIds[1]))
        return FALSE;

    return TRUE;
}

static bool32 HasAtLeastFiveBadges(void)
{
    s32 i, count;

    for (count = 0, i = 0; i < ARRAY_COUNT(sBadgeFlags); i++)
    {
        if (FlagGet(sBadgeFlags[i]) == TRUE)
        {
            if (++count >= 5)
                return TRUE;
        }
    }

    return FALSE;
}

#define STEP_COUNTER_MAX 255

void IncrementRematchStepCounter(void)
{
    if (HasAtLeastFiveBadges())
    {
        if (gSaveBlock1Ptr->trainerRematchStepCounter >= STEP_COUNTER_MAX)
            gSaveBlock1Ptr->trainerRematchStepCounter = STEP_COUNTER_MAX;
        else
            gSaveBlock1Ptr->trainerRematchStepCounter++;
    }
}

static bool32 IsRematchStepCounterMaxed(void)
{
    if (HasAtLeastFiveBadges() && gSaveBlock1Ptr->trainerRematchStepCounter >= STEP_COUNTER_MAX)
        return TRUE;
    else
        return FALSE;
}

void TryUpdateRandomTrainerRematches(u16 mapGroup, u16 mapNum)
{
    if (IsRematchStepCounterMaxed() && UpdateRandomTrainerRematches(gRematchTable, mapGroup, mapNum) == TRUE)
        gSaveBlock1Ptr->trainerRematchStepCounter = 0;
}

bool32 DoesSomeoneWantRematchIn(u16 mapGroup, u16 mapNum)
{
    return DoesSomeoneWantRematchIn_(gRematchTable, mapGroup, mapNum);
}

bool32 IsRematchTrainerIn(u16 mapGroup, u16 mapNum)
{
    return IsRematchTrainerIn_(gRematchTable, mapGroup, mapNum);
}

static u16 GetRematchTrainerId(u16 trainerId)
{
    return GetRematchTrainerIdFromTable(gRematchTable, trainerId);
}

u16 GetLastBeatenRematchTrainerId(u16 trainerId)
{
    return GetLastBeatenRematchTrainerIdFromTable(gRematchTable, trainerId);
}

bool8 ShouldTryRematchBattle(void)
{
    if (IsFirstTrainerIdReadyForRematch(gRematchTable, gTrainerBattleOpponent_A))
        return TRUE;

    return WasSecondRematchWon(gRematchTable, gTrainerBattleOpponent_A);
}

bool8 IsTrainerReadyForRematch(void)
{
    return IsTrainerReadyForRematch_(gRematchTable, gTrainerBattleOpponent_A);
}

static void HandleRematchVarsOnBattleEnd(void)
{
    ClearTrainerWantRematchState(gRematchTable, gTrainerBattleOpponent_A);
    SetBattledTrainersFlags();
}

void ShouldTryGetTrainerScript(void)
{
    if (sNoOfPossibleTrainerRetScripts > 1)
    {
        sNoOfPossibleTrainerRetScripts = 0;
        sShouldCheckTrainerBScript = TRUE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        sShouldCheckTrainerBScript = FALSE;
        gSpecialVar_Result = FALSE;
    }
}

u16 CountBattledRematchTeams(u16 trainerId)
{
    s32 i;

    if (HasTrainerBeenFought(gRematchTable[trainerId].trainerIds[0]) != TRUE)
        return 0;

    for (i = 1; i < REMATCHES_COUNT; i++)
    {
        if (gRematchTable[trainerId].trainerIds[i] == 0)
            break;
        if (!HasTrainerBeenFought(gRematchTable[trainerId].trainerIds[i]))
            break;
    }

    return i;
}
