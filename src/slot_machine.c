#include "global.h"
#include "constants/songs.h"
#include "overworld.h"
#include "field_effect.h"
#include "random.h"
#include "sound.h"
#include "main.h"
#include "slot_machine.h"
#include "string_util.h"
#include "decompress.h"
#include "trig.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "text.h"
#include "menu.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "coins.h"
#include "tv.h"
#include "text_window.h"
#include "constants/rgb.h"
#include "main_menu.h"
#include "bg.h"
#include "window.h"

// Text
extern const u8 gText_YouDontHaveThreeCoins[];
extern const u8 gText_QuitTheGame[];
extern const u8 gText_YouveGot9999Coins[];
extern const u8 gText_YouveRunOutOfCoins[];
extern const u8 gText_ReelTimeHelp[];

enum
{
    SLOT_MACHINE_TAG_7_RED,
    SLOT_MACHINE_TAG_7_BLUE,
    SLOT_MACHINE_TAG_AZURILL,
    SLOT_MACHINE_TAG_LOTAD,
    SLOT_MACHINE_TAG_CHERRY,
    SLOT_MACHINE_TAG_POWER,
    SLOT_MACHINE_TAG_REPLAY
};

enum
{
    SLOT_MACHINE_MATCHED_1CHERRY,
    SLOT_MACHINE_MATCHED_2CHERRY,
    SLOT_MACHINE_MATCHED_REPLAY,
    SLOT_MACHINE_MATCHED_LOTAD,
    SLOT_MACHINE_MATCHED_AZURILL,
    SLOT_MACHINE_MATCHED_POWER,
    SLOT_MACHINE_MATCHED_777_MIXED,
    SLOT_MACHINE_MATCHED_777_RED,
    SLOT_MACHINE_MATCHED_777_BLUE,
    SLOT_MACHINE_MATCHED_NONE
};

struct SlotMachineEwramStruct
{
    /*0x00*/ u8 state;
    /*0x01*/ u8 machineId;
    /*0x02*/ u8 pikaPower;
    /*0x03*/ u8 luckyGame;
    /*0x04*/ u8 luckyFlags;
    /*0x05*/ u8 reelTimeDraw;
    /*0x06*/ u8 luckySpinsLeft;  // tentative
    /*0x07*/ u8 biasTag;
    /*0x08*/ u16 matchedSymbols;
    /*0x0A*/ u8 fairRollsLeft;  // only happens if you win reeltime
    /*0x0B*/ u8 fairRollsUsed;
    /*0x0C*/ s16 coins;
    /*0x0E*/ s16 payout;
    /*0x10*/ s16 netCoinLoss; // coins lost to machine (but never goes below 0)
    /*0x12*/ s16 bet;
    /*0x14*/ s16 reeltimePixelOffset;
    /*0x16*/ s16 reeltimePosition;
    /*0x18*/ s16 currReel;
    /*0x1A*/ s16 reelIncrement; // speed of reel
    /*0x1C*/ s16 reelPixelOffsets[3];
    /*0x22*/ u16 reelPixelOffsetsWhileStopping[3];
    /*0x28*/ s16 reelTagOffsets[3];
    /*0x2E*/ s16 reelExtraTurns[3];
    /*0x34*/ s16 winnerRows[3];
    /*0x3A*/ u8 slotReelTasks[3];
    /*0x3D*/ u8 unkTaskPointer3D;
    /*0x3E*/ u8 unkTaskPointer3E;
    /*0x3F*/ u8 reelTimeSprite3F;
    /*0x40*/ u8 unk40;
    /*0x41*/ u8 unk41;
    /*0x42*/ u8 unk42;
    /*0x43*/ u8 unk43;
    /*0x44*/ u8 unk44[5];
    /*0x49*/ u8 unk49[2];
    /*0x49*/ u8 unk4B[3];
    /*0x4E*/ u8 unk4E[2];
    /*0x50*/ u8 reelTimeSprites1[2];
    /*0x52*/ u8 reelTimeSprites2[2];
    /*0x54*/ u8 unk54[4];
    /*0x58*/ u16 win0h;
    /*0x5a*/ u16 win0v;
    /*0x5c*/ u16 winIn;
    /*0x5e*/ u16 winOut;
    /*0x60*/ u16 backupMapMusic;
    /*0x64*/ MainCallback prevMainCb;
};

struct UnkStruct1
{
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
};

#define SLOTMACHINE_GFX_TILES 233

static void CB2_SlotMachineSetup(void);
static void CB2_SlotMachineLoop(void);
static void PlaySlotMachine_Internal(u8 slotMachineIndex, MainCallback cb);
static void SlotMachineDummyTask(u8 taskId);
static void SlotMachineSetup_0_0(void);
static void SlotMachineSetup_6_2(void);
static void SlotMachineSetup_1_0(void);
static void SlotMachineSetup_2_0(void);
static void SlotMachineSetup_2_1(void);
static void SlotMachineSetup_0_1(void);
static void SlotMachineSetup_3_0(void);
static void SlotMachineSetup_4_0(void);
static void SlotMachineSetup_5_0(void);
static void SlotMachineSetup_6_0(void);
static void SlotMachineSetup_6_1(void);
static void SlotMachineSetup_8_0(void);
static void SlotMachineSetup_9_0(void);
static void SlotMachineSetup_10_0(void);
static void SlotMachineSetupGameplayTasks(void);
static void GameplayTasks_Slots(void);
static void sub_8104DA4(void);
static void RunSlotActions(u8 taskId);
static bool8 SlotAction_UnfadeScreen(struct Task *task);
static bool8 SlotAction_WaitForUnfade(struct Task *task);
static bool8 SlotAction_SetSlotMachineVars(struct Task *task);
static bool8 SlotAction3(struct Task *task);
static bool8 SlotAction4(struct Task *task);
static bool8 SlotAction_AwaitPlayerInput(struct Task *task);
static bool8 SlotAction_PrintYouDontHaveThreeCoins(struct Task *task);
static bool8 SlotAction_ExitYouDontHaveThreeCoinsMessage(struct Task *task);
static bool8 SlotAction_GivingInformation(struct Task *task);
static bool8 SlotAction9(struct Task *task);
static bool8 SlotAction10(struct Task *task);
static bool8 SlotAction_SetLuckySpins(struct Task *task);
static bool8 SlotAction_AwaitReelStop(struct Task *task);
static bool8 SlotAction_WaitForAllReelsToStop(struct Task *task);
static bool8 SlotAction_CheckMatches(struct Task *task);
static bool8 SlotAction_WaitForPayoutToBeAwarded(struct Task *task);
static bool8 SlotAction_EndOfRoll(struct Task *task);
static bool8 SlotAction_MatchedPower(struct Task *task);
static bool8 SlotAction18(struct Task *task);
static bool8 SlotAction_Loop(struct Task *task);
static bool8 SlotAction_NoMatches(struct Task *task);
static bool8 SlotAction_PrintQuitTheGame(struct Task *task);
static bool8 SlotAction_SeeIfPlayerQuits(struct Task *task);
static bool8 SlotAction_PrintMessage_9999Coins(struct Task *task);
static bool8 SlotAction_ExitMessage_9999Coins(struct Task *task);
static bool8 SlotAction_PrintMessage_NoMoreCoins(struct Task *task);
static bool8 SlotAction_ExitMessage_NoMoreCoins(struct Task *task);
static bool8 SlotAction_EndGame(struct Task *task);
static bool8 SlotAction_FreeDataStructures(struct Task *task);
static void DrawLuckyFlags(void);
static void SetLuckySpins(void);
static bool8 IsThisRoundLucky(void);
static u8 AttemptsAtLuckyFlags_Top3(void);
static u16 SlowReelSpeed(void);
static u8 AttemptsAtLuckyFlags_NotTop3(void);
static void CheckMatch(void);
static void CheckMatch_CenterRow(void);
static void CheckMatch_TopAndBottom(void);
static void CheckMatch_Diagonals(void);
static u8 GetMatchFromSymbolsInRow(u8 c1, u8 c2, u8 c3);
static void AwardPayout(void);
static void RunAwardPayoutActions(u8 taskId);
static bool8 IsFinalTask_RunAwardPayoutActions(void);
static bool8 AwardPayoutAction0(struct Task *task);
static bool8 AwardPayoutAction_GivePayoutToPlayer(struct Task *task);
static bool8 AwardPayoutAction_FreeTask(struct Task *task);
static u8 GetNearbyTag_Quantized(u8 x, s16 y);
static void GameplayTask_StopSlotReel(void);
static void ReelTasks_SetUnkTaskData(u8 a0);
static void sub_8102E1C(u8 a0);
static bool8 IsSlotReelMoving(u8 a0);
static void RunSlotReelActions(u8 taskId);
static bool8 SlotReelAction_StayStill(struct Task *task);
static bool8 SlotReelAction_Spin(struct Task *task);
static bool8 SlotReelAction_DecideWhereToStop(struct Task *task);
static bool8 SlotReelAction_MoveToStop(struct Task *task);
static bool8 SlotReelAction_OscillatingStop(struct Task *task);
static bool8 DecideReelTurns_BiasTag_Reel1(void);
static bool8 DecideReelTurns_BiasTag_Reel1_Bet1(u8 a0, u8 a1);
static bool8 DecideReelTurns_BiasTag_Reel1_Bet2or3(u8 a0, u8 a1);
static bool8 DecideReelTurns_BiasTag_Reel2(void);
static bool8 DecideReelTurns_BiasTag_Reel2_Bet1or2(void);
static bool8 DecideReelTurns_BiasTag_Reel2_Bet3(void);
static bool8 DecideReelTurns_BiasTag_Reel3(void);
static bool8 DecideReelTurns_BiasTag_Reel3_Bet1or2(u8 a0);
static bool8 DecideReelTurns_BiasTag_Reel3_Bet3(u8 a0);
static void DecideReelTurns_NoBiasTag_Reel1(void);
static void DecideReelTurns_NoBiasTag_Reel2(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet1(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet2(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet3(void);
static void DecideReelTurns_NoBiasTag_Reel3(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet1(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet2(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet3(void);
static void sub_8103C14(u8 a0);
static void sub_8103C48(u8 taskId);
static void LoadBetTiles(u8 a0);
static void sub_8103C78(struct Task *task, u8 taskId);
static void sub_8103CAC(struct Task *task, u8 taskId);
static void sub_8103CC8(struct Task *task, u8 taskId);
static void sub_8103D8C(u8 a0);
static void sub_8103DC8(void);
static void sub_8103E04(u8 a0);
static bool8 sub_8103E38(void);
static bool8 sub_8103E7C(void);
static bool8 sub_8103EAC(u8 spriteId);
static void sub_8103EE4(struct Sprite *sprite);
static void sub_8103F70(void);
static bool8 sub_8103FA0(void);
static void sub_8103FE8_(u8 taskId);
static void GameplayTask_PikaPower(void);
static void DisplayPikaPower(u8 pikaPower);
static bool8 sub_81040C8(void);
static void sub_81040E8(u8 taskId);
static void nullsub_68(struct Task *task);
static void sub_810411C(struct Task *task);
static void sub_8104144(struct Task *task);
static void sub_81041AC(struct Task *task);
static void ClearTaskDataFields_2orHigher(struct Task *task);
static void sub_810423C(u8 pikaPower);
static void BeginReeltime(void);
static bool8 IsFinalTask_RunReelTimeActions(void);
static void RunReeltimeActions(u8 taskId);
static void ReeltimeAction0(struct Task *task);
static void ReeltimeAction1(struct Task *task);
static void ReeltimeAction2(struct Task *task);
static void ReeltimeAction3(struct Task *task);
static void ReeltimeAction4(struct Task *task);
static void ReeltimeAction5(struct Task *task);
static void ReeltimeAction6(struct Task *task);
static void ReelTimeAction_LandOnOutcome(struct Task *task);
static void ReeltimeAction8(struct Task *task);
static void ReeltimeAction9(struct Task *task);
static void ReeltimeAction10(struct Task *task);
static void ReeltimeAction11(struct Task *task);
static void ReeltimeAction12(struct Task *task);
static void ReeltimeAction13(struct Task *task);
static void ReeltimeAction14(struct Task *task);
static void ReeltimeAction15(struct Task *task);
static void ReeltimeAction16(struct Task *task);
static void ReeltimeAction17(struct Task *task);
static void sub_8104A40(s16 a0, s16 a1);
static void sub_8104A88(s16 a0);
static void OpenInfoBox(u8 a0);
static bool8 IsInfoBoxClosed(void);
static void RunInfoBoxActions(u8 taskId);
static void InfoBox_FadeIn(struct Task *task);
static void InfoBox_WaitForFade(struct Task *task);
static void InfoBox_8104B80(struct Task *task);
static void InfoBox_AwaitPlayerInput(struct Task *task);
static void InfoBox_AddText(struct Task *task);
static void InfoBox_8104BFC(struct Task *task);
static void InfoBox_812DE14(struct Task *task);
static void InfoBox_812DE30(struct Task *task);
static void InfoBox_FreeTask(struct Task *task);
static void sub_8104C5C(void);
static void sub_8104CAC(u8 arg0);
static bool8 sub_8104E18(void);
static void nullsub_69(struct Task *task);
static void sub_8104E74_(u8 taskId);
static void sub_8104EA8(void);
static void sub_8104F8C(void);
static void sub_8104FF4(s16 x, s16 y, u8 a2, s16 a3);
static void sub_81050C4(void);
static void sub_8105100(void);
static void sub_810514C(void);
static void sub_81051C0(void);
static void sub_8105284_(void);
static void sub_81052EC(void);
static void sub_81053A0(void);
static void sub_810545C(void);
static void sub_81054B8(void);
static void sub_8105524(void);
static void sub_8105554(void);
static void CreateReelTimeSprites1(void);
static void sub_8105688(s16 a0);
static void sub_81056C0(void);
static void CreateReelTimeSprite2(void);
static void sub_81057E8(s16 a0);
static void sub_8105804(void);
static void sub_8105854(void);
static void sub_81058A0(void);
static void sub_81058C4(void);
static void sub_81059B8(void);
static void sub_81059E8(void);
static bool8 sub_8105ACC(void);
static void sub_8105AEC(void);
static u8 sub_8105B1C(s16 x, s16 y);
static void sub_8105B88(u8 spriteId);
static u8 sub_8105BF8(u8 templateIdx, void (*callback)(struct Sprite*), s16 x, s16 y, s16 a4);
static void sub_81063C0(void);
static void sub_8106404(void);
static void sub_8106448(void);
static void sub_81064B8(void);
static void sub_81065A8(s16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
static void sub_81065DC(void);
static void sub_812F958(void);
static void sub_812F968(void);
static void LoadSlotMachineWheelOverlay(void);
static u8 sub_8105BB4(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2);

// Ewram variables
static EWRAM_DATA u16 *sUnknown_0203AAC8 = NULL;
static EWRAM_DATA u16 *sSelectedPikaPowerTile = NULL;
static EWRAM_DATA u16 *sUnknown_0203AAD0 = NULL;
static EWRAM_DATA u8 *sUnknown_0203AAD4 = NULL;
static EWRAM_DATA u8 *sUnknown_0203AAD8 = NULL;
static EWRAM_DATA u16 *sUnknown_0203AADC = NULL;
static EWRAM_DATA u8 *sUnknown_0203AAE0 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAE4 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAE8 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAEC = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAF0 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAF4 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAF8 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AAFC = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB00 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB04 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB08 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB0C = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB10 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB14 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB18 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB1C = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB20 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB24 = NULL;
static EWRAM_DATA struct SpriteFrameImage *sUnknown_0203AB28 = NULL;
static EWRAM_DATA struct SpriteSheet *sUnknown_0203AB2C = NULL;
static EWRAM_DATA struct SpriteSheet *sUnknown_0203AB30 = NULL;
static EWRAM_DATA struct SlotMachineEwramStruct *sSlotMachine = NULL;

// IWRAM bss
static struct SpriteFrameImage *gUnknown_03001188[26];

// Const rom data.
extern const struct UnkStruct1 *const gUnknown_083ED048[];
extern const u16 gPalette_83EDE24[];
extern const u8 gLuckyRoundProbabilities[][3];
extern const u8 gBiasTags[];
extern const u16 gLuckyFlagSettings_Top3[];
extern const u16 gLuckyFlagSettings_NotTop3[];
extern const s16 gUnknown_083ECE7E[][2];
extern const SpriteCallback gUnknown_083ECF0C[];
extern const struct SpriteTemplate *const gUnknown_083EDB5C[];
extern const struct SubspriteTable *const gUnknown_083EDBC4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED6CC;
extern const struct SpriteTemplate gSpriteTemplate_83ED564;
extern const struct SpriteTemplate gSpriteTemplate_83ED54C;
extern const struct SpriteTemplate gSpriteTemplate_83ED534;
extern const u8 gUnknown_083ECC58[2];
extern const struct SpriteTemplate gSpriteTemplate_83ED51C;
extern const u16 gProbabilityTable_SkipToReeltimeAction14[];
extern const u16 *const gUnknown_083EDE10[];
extern const u16 gReelIncrementTable[][2];
extern const u16 gReelTimeBonusIncrementTable[];
extern const u16 gSlotMatchFlags[];
extern const u16 gSlotPayouts[];
extern const u8 *const gUnknown_083EDCE4;
extern const u8 *const gUnknown_083EDCDC;
extern const u32 gReelTimeGfx[];
extern const struct SpriteSheet gSlotMachineSpriteSheets[];
extern const struct SpritePalette gSlotMachineSpritePalettes[];
extern const u16 *const gUnknown_083EDE20;
extern const s16 gInitialReelPositions[][2];
extern const struct BgTemplate gUnknown_085A7424[4];
extern const struct WindowTemplate gUnknown_085A7434[];
extern const u8 gLuckyFlagProbabilities_Top3[][6];
extern const u8 gLuckyFlagProbabilities_NotTop3[][6];
extern const u8 gReeltimeProbabilities_UnluckyGame[][17];
extern const u8 gReelTimeProbabilities_LuckyGame[][17];
extern const u8 gSym2Match[];
extern const u8 gReelTimeTags[];
extern const u8 gReelSymbols[][REEL_NUM_TAGS];
extern const u16 *const gUnknown_083EDD08[];
extern const u16 *const gUnknown_083EDD1C[];
extern const u8 gUnknown_083EDD30[];
extern const u8 gBettingTilesId[][2];
extern const u8 gNumberBettingTiles[];
extern const u16 *const gUnknown_083EDDA0[];
extern const u16 *const gUnknown_083EDDAC;
extern const u16 gReelTimeWindowTilemap[];
extern const u16 gUnknown_085A9898[];
extern void (*const gUnknown_083ED064[])(void);

const struct BgTemplate gUnknown_085A7424[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

const struct WindowTemplate gUnknown_085A7434[] =
{
    {0, 2, 15, 0x1B, 4, 15, 0x194},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_085A7444 =
{
    0, 1, 3, 20, 13, 13, 1
};

const u8 gColors_ReeltimeHelp[] = {3, 1, 2, 0};

bool8 (*const SlotActions[])(struct Task *task) =
{
    SlotAction_UnfadeScreen,                        // 0
    SlotAction_WaitForUnfade,                       // 1
    SlotAction_SetSlotMachineVars,                  // 2
    SlotAction3,                                    // 3
    SlotAction4,                                    // 4
    SlotAction_AwaitPlayerInput,                    // 5
    SlotAction_PrintYouDontHaveThreeCoins,          // 6
    SlotAction_ExitYouDontHaveThreeCoinsMessage,    // 7
    SlotAction_GivingInformation,                   // 8
    SlotAction9,                                    // 9
    SlotAction10,                                   // 10
    SlotAction_SetLuckySpins,                       // 11
    SlotAction_AwaitReelStop,                       // 12
    SlotAction_WaitForAllReelsToStop,               // 13
    SlotAction_CheckMatches,                        // 14
    SlotAction_WaitForPayoutToBeAwarded,            // 15
    SlotAction_EndOfRoll,                           // 16
    SlotAction_MatchedPower,                        // 17
    SlotAction18,                                   // 18
    SlotAction_Loop,                                // 19
    SlotAction_NoMatches,                           // 20
    SlotAction_PrintQuitTheGame,                    // 21
    SlotAction_SeeIfPlayerQuits,                    // 22
    SlotAction_PrintMessage_9999Coins,                // 23
    SlotAction_ExitMessage_9999Coins,                 // 24
    SlotAction_PrintMessage_NoMoreCoins,                    // 25
    SlotAction_ExitMessage_NoMoreCoins,              // 26
    SlotAction_EndGame,                             // 27
    SlotAction_FreeDataStructures,                  // 28
};

bool8 (*const AwardPayoutActions[])(struct Task *task) =
{
    AwardPayoutAction0,
    AwardPayoutAction_GivePayoutToPlayer,
    AwardPayoutAction_FreeTask
};

bool8 (*const SlotReelActions[])(struct Task *task) =
{
    SlotReelAction_StayStill,
    SlotReelAction_Spin,
    SlotReelAction_DecideWhereToStop,
    SlotReelAction_MoveToStop,
    SlotReelAction_OscillatingStop
};

// returns True if a match with the biasTag is possible in that reel
// also modifies data in sSlotMachine reel arrays to indicate how to get to the matching state
bool8 (*const DecideReelTurns_BiasTag[])(void) =
{
    DecideReelTurns_BiasTag_Reel1,
    DecideReelTurns_BiasTag_Reel2,
    DecideReelTurns_BiasTag_Reel3
};

void (*const DecideReelTurns_NoBiasTag[])(void) =
{
    DecideReelTurns_NoBiasTag_Reel1,
    DecideReelTurns_NoBiasTag_Reel2,
    DecideReelTurns_NoBiasTag_Reel3
};

const u16 ReelStopShocks[] = {2, 4, 4, 4, 8};

bool8 (*const DecideReelTurns_BiasTag_Reel1_Bets[])(u8 tag1, u8 tag2) =
{
    DecideReelTurns_BiasTag_Reel1_Bet1,
    DecideReelTurns_BiasTag_Reel1_Bet2or3,
    DecideReelTurns_BiasTag_Reel1_Bet2or3
};

bool8 (*const DecideReelTurns_BiasTag_Reel2_Bets[])(void) =
{
    DecideReelTurns_BiasTag_Reel2_Bet1or2,
    DecideReelTurns_BiasTag_Reel2_Bet1or2,
    DecideReelTurns_BiasTag_Reel2_Bet3
};

bool8 (*const DecideReelTurns_BiasTag_Reel3_Bets[])(u8 biasTag) =
{
    DecideReelTurns_BiasTag_Reel3_Bet1or2,
    DecideReelTurns_BiasTag_Reel3_Bet1or2,
    DecideReelTurns_BiasTag_Reel3_Bet3
};

void (*const DecideReelTurns_NoBiasTag_Reel2_Bets[])(void) =
{
    DecideReelTurns_NoBiasTag_Reel2_Bet1,
    DecideReelTurns_NoBiasTag_Reel2_Bet2,
    DecideReelTurns_NoBiasTag_Reel2_Bet3
};

void (*const DecideReelTurns_NoBiasTag_Reel3_Bets[])(void) =
{
    DecideReelTurns_NoBiasTag_Reel3_Bet1,
    DecideReelTurns_NoBiasTag_Reel3_Bet2,
    DecideReelTurns_NoBiasTag_Reel3_Bet3
};

void (*const gUnknown_083ECBA0[])(struct Task *task, u8 taskId) =
{
    sub_8103C78,
    sub_8103CAC,
    sub_8103CC8
};

const s16 gUnknown_083ECBAC[] = {5, 10, 15};

void (*const gUnknown_083ECBB4[])(struct Task *task) =
{
    nullsub_68,
    sub_810411C,
    sub_8104144,
    sub_81041AC
};

const u16 pikaPowerTileTable[][2] =
{
    {0x9e, 0x6e},
    {0x9f, 0x6f},
    {0xaf, 0x7f},
};

void (*const ReeltimeActions[])(struct Task *task) =
{
    ReeltimeAction0,
    ReeltimeAction1,
    ReeltimeAction2,
    ReeltimeAction3,
    ReeltimeAction4,
    ReeltimeAction5,
    ReeltimeAction6,
    ReelTimeAction_LandOnOutcome,
    ReeltimeAction8,
    ReeltimeAction9,
    ReeltimeAction10,
    ReeltimeAction11,
    ReeltimeAction12,
    ReeltimeAction13,
    ReeltimeAction14,
    ReeltimeAction15,
    ReeltimeAction16,
    ReeltimeAction10,
    ReeltimeAction17
};

const u8 gUnknown_085A75C0[] = {1, 1, 2, 2};
const s16 gUnknown_085A75C4[] = {0x40, 0x30, 0x18, 0x08};
const s16 gUnknown_085A75CC[] = {10, 8, 6, 4};

void (*const InfoBoxActions[])(struct Task *task) =
{
    InfoBox_FadeIn,
    InfoBox_WaitForFade,
    InfoBox_8104B80,
    InfoBox_WaitForFade,
    InfoBox_AddText,
    InfoBox_WaitForFade,
    InfoBox_AwaitPlayerInput,
    InfoBox_WaitForFade,
    InfoBox_812DE14,
    InfoBox_WaitForFade,
    InfoBox_812DE30,
    InfoBox_WaitForFade,
    InfoBox_8104BFC,
    InfoBox_WaitForFade,
    InfoBox_FreeTask,
};

void (*const gUnknown_083ECC54[])(struct Task *task) =
{
    nullsub_69,
};

extern const struct SpriteTemplate gSpriteTemplate_83ED504;
extern const struct SpriteTemplate gSpriteTemplate_83ED4EC;
extern const struct SubspriteTable gSubspriteTables_83ED7D4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED4D4;
extern const struct SubspriteTable gSubspriteTables_83ED7B4[];
extern const struct SpriteTemplate gSpriteTemplate_83ED4BC;
extern const struct SpriteTemplate gSpriteTemplate_83ED4A4;
extern const struct SubspriteTable gSubspriteTables_83ED78C[];
extern const struct SpriteTemplate gSpriteTemplate_83ED474;
extern const struct SpriteTemplate gSpriteTemplate_83ED48C;
extern const struct SubspriteTable gSubspriteTables_83ED73C[];
extern const struct SubspriteTable gSubspriteTables_83ED75C[];
extern const struct SpriteTemplate gSpriteTemplate_83ED444;
extern const struct SubspriteTable gSubspriteTables_83ED704[];
extern const struct SpriteTemplate gSpriteTemplate_83ED42C;
extern const struct SpriteTemplate gSpriteTemplate_83ED414;
extern const struct SpriteTemplate gSpriteTemplate_83ED45C;

// code
#define tState data[0]

static void Task_FadeToSlotMachine(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_SlotMachineSetup);
            DestroyTask(taskId);
        }
        break;
    }
}

void PlaySlotMachine(u8 slotMachineIndex, MainCallback cb)
{
    u8 taskId;

    sSlotMachine = AllocZeroed(sizeof(*sSlotMachine));
    PlaySlotMachine_Internal(slotMachineIndex, cb);
    taskId = CreateTask(Task_FadeToSlotMachine, 0);
    gTasks[taskId].tState = 0;
}

#undef tState

static void CB2_SlotMachineSetup(void)
{
    switch (gMain.state)
    {
        case 0:
            SlotMachineSetup_0_0();
            SlotMachineSetup_0_1();
            gMain.state++;
            break;
        case 1:
            SlotMachineSetup_1_0();
            gMain.state++;
            break;
        case 2:
            SlotMachineSetup_2_0();
            SlotMachineSetup_2_1();
            gMain.state++;
            break;
        case 3:
            SlotMachineSetup_3_0();
            gMain.state++;
            break;
        case 4:
            SlotMachineSetup_4_0();
            gMain.state++;
            break;
        case 5:
            SlotMachineSetup_5_0();
            gMain.state++;
            break;
        case 6:
            SlotMachineSetup_6_0();
            gMain.state++;
            break;
        case 7:
            BeginNormalPaletteFade(-1, 0, 0x10, 0, RGB_BLACK);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gMain.state++;
            break;
        case 8:
            SlotMachineSetup_8_0();
            gMain.state++;
            break;
        case 9:
            SlotMachineSetup_9_0();
            gMain.state++;
            break;
        case 10:
            SlotMachineSetup_10_0();
            SlotMachineSetupGameplayTasks();
            gMain.state++;
            break;
        case 11:
            SetMainCallback2(CB2_SlotMachineLoop);
            break;
    }
}

static void CB2_SlotMachineLoop(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SlotMachine_VBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_WIN0H, sSlotMachine->win0h);
    SetGpuReg(REG_OFFSET_WIN0V, sSlotMachine->win0v);
    SetGpuReg(REG_OFFSET_WININ, sSlotMachine->winIn);
    SetGpuReg(REG_OFFSET_WINOUT, sSlotMachine->winOut);
}

static void PlaySlotMachine_Internal(u8 slotMachineIndex, MainCallback cb)
{
    struct Task *task = &gTasks[CreateTask(SlotMachineDummyTask, 0xFF)];
    task->data[0] = slotMachineIndex;
    StoreWordInTwoHalfwords(task->data + 1, (intptr_t)cb);
}


static void sub_81019EC(void)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(SlotMachineDummyTask)];
    sSlotMachine->machineId = task->data[0];
    LoadWordFromTwoHalfwords((u16 *)(task->data + 1), (u32 *)&sSlotMachine->prevMainCb);
}

static void SlotMachineDummyTask(u8 taskId)
{
}

static void SlotMachineSetup_0_0(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    CpuFill32(0, (void *)VRAM, VRAM_SIZE);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085A7424, ARRAY_COUNT(gUnknown_085A7424));
    InitWindows(gUnknown_085A7434);
    DeactivateAllTextPrinters();
}

static void SlotMachineSetup_6_0(void)
{
    SetVBlankCallback(SlotMachine_VBlankCallback);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
}

static void SlotMachineSetup_1_0(void)
{
    DmaClearLarge16(3, (u16 *)(BG_VRAM), BG_VRAM_SIZE, 0x1000);
}

static void SlotMachineSetup_2_0(void)
{
    DmaClear16(3, (u16 *)OAM, OAM_SIZE);
}

static void SlotMachineSetup_2_1(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 8));
}

// set up initial state of slot machine
static void SlotMachineSetup_0_1(void)
{
    u8 i;

    sub_81019EC();  // assigns sSlotMachine->machineId, etc.
    sSlotMachine->state = 0;
    sSlotMachine->pikaPower = 0;
    sSlotMachine->luckyGame = Random() & 1;
    sSlotMachine->luckyFlags = 0;
    sSlotMachine->matchedSymbols = 0;
    sSlotMachine->fairRollsLeft = 0;
    sSlotMachine->fairRollsUsed = 0;
    sSlotMachine->coins = GetCoins();
    sSlotMachine->payout = 0;
    sSlotMachine->netCoinLoss = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currReel = 0;
    sSlotMachine->reelIncrement = 8;
    sSlotMachine->win0h = 0xf0;
    sSlotMachine->win0v = 0xa0;
    sSlotMachine->winIn = 0x3f;
    sSlotMachine->winOut = 0x3f;
    sSlotMachine->backupMapMusic = GetCurrentMapMusic();

    for (i = 0; i < NUM_REELS; i++)
    {
        sSlotMachine->reelPixelOffsetsWhileStopping[i] = 0;
        sSlotMachine->reelTagOffsets[i] = gInitialReelPositions[i][sSlotMachine->luckyGame] % REEL_NUM_TAGS;
        sSlotMachine->reelPixelOffsets[i] = REEL_NUM_TAGS * REEL_TAG_HEIGHT - sSlotMachine->reelTagOffsets[i] * REEL_TAG_HEIGHT;
        sSlotMachine->reelPixelOffsets[i] %= REEL_NUM_TAGS * REEL_TAG_HEIGHT;
    }
    AlertTVThatPlayerPlayedSlotMachine(GetCoins());
}

static void SlotMachineSetup_3_0(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    gOamLimit = 0x80;
    FreeAllSpritePalettes();
    ResetTasks();
}

static void SlotMachineSetup_4_0(void)
{
    sSelectedPikaPowerTile = Alloc(8);
    sUnknown_0203AAD0 = AllocZeroed(0xE);
    sUnknown_0203AADC = AllocZeroed(8);

    // several of these are 1 bit off from each other
    sUnknown_0203AAD0[0] = 0x2051;
    sUnknown_0203AAD0[1] = 0x2851;
    sUnknown_0203AAD0[2] = 0x2061;
    sUnknown_0203AAD0[3] = 0x2861;
    sUnknown_0203AAD0[4] = 0x20BE;
    sUnknown_0203AAD0[5] = 0x28BE;
    sUnknown_0203AAD0[6] = 0x20BF;
}

static void SlotMachineSetup_5_0(void)
{
    sub_8106448();
    sub_81064B8();
    sub_81063C0();
    LoadMessageBoxGfx(0, 0x200, 0xF0);
    LoadUserWindowBorderGfx(0, 0x214, 0xE0);
    PutWindowTilemap(0);
}

static void SlotMachineSetup_10_0(void)
{
    sub_8104EA8();
    sub_8104F8C();
    sub_8103DC8();
    sub_81050C4();
}

// create gameplay tasks
static void SlotMachineSetupGameplayTasks(void)
{
    GameplayTask_PikaPower();
    GameplayTask_StopSlotReel();
    sub_8104C5C();
    GameplayTasks_Slots();
}

static void GameplayTasks_Slots(void)
{
    RunSlotActions(CreateTask(RunSlotActions, 0));
}

// task->data[0] is a timer
static void RunSlotActions(u8 taskId)
{
    while (SlotActions[sSlotMachine->state](&gTasks[taskId]))
        ;
}

static bool8 SlotAction_UnfadeScreen(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    sub_810423C(sSlotMachine->pikaPower);
    sSlotMachine->state++;
    return FALSE;
}

static bool8 SlotAction_WaitForUnfade(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

static bool8 SlotAction_SetSlotMachineVars(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currReel = 0;
    sSlotMachine->luckyFlags &= (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
    sSlotMachine->state = 4;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = 25;
    }
    else if (sSlotMachine->fairRollsLeft)
    {
        sSlotMachine->state = 3;
        sub_8104CAC(4);
    }
    return TRUE;
}

static bool8 SlotAction3(struct Task *task)
{
    if (sub_8104E18())
        sSlotMachine->state = 4;
    return FALSE;
}

static bool8 SlotAction4(struct Task *task)
{
    sub_8104CAC(0);
    sSlotMachine->state = 5;
    if (sSlotMachine->coins >= 9999)
        sSlotMachine->state = 23;
    return TRUE;
}

static bool8 SlotAction_AwaitPlayerInput(struct Task *task)
{
    s16 i;

    if (gMain.newKeys & SELECT_BUTTON)
    {
        OpenInfoBox(0);
        sSlotMachine->state = 8;
    }
    else if (gMain.newKeys & R_BUTTON)  // bet the max amount
    {
        if (sSlotMachine->coins - (3 - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < 3; i++)
                LoadBetTiles(i);
            sSlotMachine->coins -= (3 - sSlotMachine->bet);
            sSlotMachine->bet = 3;
            sSlotMachine->state = 9;
            PlaySE(SE_REGI);
        }
        else  // you didn't have enough coins to bet the max
        {
            sSlotMachine->state = 6;
        }
    }
    else
    {
        if (gMain.newKeys & DPAD_DOWN && sSlotMachine->coins != 0)
        {
            PlaySE(SE_REGI);
            LoadBetTiles(sSlotMachine->bet);
            sSlotMachine->coins--;
            sSlotMachine->bet++;
        }
        // player maxed out or finished betting
        if (sSlotMachine->bet >= 3 || (sSlotMachine->bet != 0 && gMain.newKeys & A_BUTTON))
            sSlotMachine->state = 9;
        // player wants to quit
        if (gMain.newKeys & B_BUTTON)
            sSlotMachine->state = 21;
    }
    return FALSE;
}

static bool8 SlotAction_PrintYouDontHaveThreeCoins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouDontHaveThreeCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 7;
    return FALSE;
}

static bool8 SlotAction_ExitYouDontHaveThreeCoinsMessage(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

static bool8 SlotAction_GivingInformation(struct Task *task)
{
    if (IsInfoBoxClosed())
        sSlotMachine->state = 5;
    return FALSE;
}

// probably make all the slots roll
static bool8 SlotAction9(struct Task *task)
{
    DrawLuckyFlags();
    sub_8104DA4();

    // for each reel...
    ReelTasks_SetUnkTaskData(0);
    ReelTasks_SetUnkTaskData(1);
    ReelTasks_SetUnkTaskData(2);

    IncrementDailySlotsUses();

    task->data[0] = 0;
    if (sSlotMachine->luckyFlags & LUCKY_BIAS_REELTIME)
    {
        BeginReeltime();
        sSlotMachine->state = 10;
    }
    else
    {
        sub_8104CAC(1);
        sSlotMachine->state = 11;
    }
    sSlotMachine->reelIncrement = 8;
    if (sSlotMachine->fairRollsLeft)
        sSlotMachine->reelIncrement = SlowReelSpeed();
    return FALSE;
}

static bool8 SlotAction10(struct Task *task)
{
    if (IsFinalTask_RunReelTimeActions())
    {
        sub_8104CAC(1);
        sSlotMachine->luckyFlags &= ~LUCKY_BIAS_REELTIME;
        sSlotMachine->state = 11;
    }
    return FALSE;
}

static bool8 SlotAction_SetLuckySpins(struct Task *task)
{
    if (++task->data[0] >= 30)
    {
        SetLuckySpins();
        sSlotMachine->state = 12;
    }
    return FALSE;
}

static bool8 SlotAction_AwaitReelStop(struct Task *task)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_JYUNI);
        sub_8102E1C(sSlotMachine->currReel);
        sub_8103C14(sSlotMachine->currReel);
        sSlotMachine->state = 13;
    }
    return FALSE;
}

static bool8 SlotAction_WaitForAllReelsToStop(struct Task *task)
{
    if (!IsSlotReelMoving(sSlotMachine->currReel))
    {
        sSlotMachine->currReel++;
        sSlotMachine->state = 12;
        if (sSlotMachine->currReel > 2)
        {
            sSlotMachine->state = 14;
        }
        return TRUE;
    }
    return FALSE;
}

// once all reels have stopped
static bool8 SlotAction_CheckMatches(struct Task *task)
{
    sSlotMachine->luckyFlags &= (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
    CheckMatch();
    if (sSlotMachine->fairRollsLeft)
    {
        sSlotMachine->fairRollsLeft--;
        sSlotMachine->fairRollsUsed++;
    }

    if (sSlotMachine->matchedSymbols)
    {
        sSlotMachine->state = 15;
        AwardPayout();
        sub_8103F70();
        if ((sSlotMachine->netCoinLoss -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->netCoinLoss = 0;
        }
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            PlayFanfare(MUS_ME_B_BIG);
            sub_8104CAC(6);
        }
        else if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_777_MIXED))
        {
            PlayFanfare(MUS_ME_B_BIG);
            sub_8104CAC(5);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            sub_8104CAC(2);
        }
        // if you matched 777...
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_MIXED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            sSlotMachine->luckyFlags &= ~(LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
            if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
            {
                sSlotMachine->fairRollsLeft = 0;
                sSlotMachine->fairRollsUsed = 0;
                sSlotMachine->luckyGame = FALSE;
                if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_777_BLUE))
                    // this may be an error, but if you get blue 777, the game becomes lucky
                    sSlotMachine->luckyGame = TRUE;
            }
        }
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_POWER) && sSlotMachine->pikaPower < 16)
        {
            sSlotMachine->pikaPower++;
            DisplayPikaPower(sSlotMachine->pikaPower);
        }
    }
    else
    {
        sub_8104CAC(3);
        sSlotMachine->state = 20;
        if ((sSlotMachine->netCoinLoss += sSlotMachine->bet) > 9999)
            sSlotMachine->netCoinLoss = 9999;
    }
    return FALSE;
}

static bool8 SlotAction_WaitForPayoutToBeAwarded(struct Task *task)
{
    if (IsFinalTask_RunAwardPayoutActions())
        sSlotMachine->state = 16;
    return FALSE;
}

static bool8 SlotAction_EndOfRoll(struct Task *task)
{
    if (sub_8103FA0())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_RED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->currReel = 0;
            sSlotMachine->state = 9;
        }
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_POWER))
            sSlotMachine->state = 17;
        if (sSlotMachine->fairRollsLeft && sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sub_8104CAC(4);
            sSlotMachine->state = 18;
        }
    }
    return FALSE;
}

static bool8 SlotAction_MatchedPower(struct Task *task)
{
    if (!sub_81040C8())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = 9;
            if (sSlotMachine->fairRollsLeft)
            {
                sub_8104CAC(4);
                sSlotMachine->state = 18;
            }
        }
    }
    return FALSE;
}

static bool8 SlotAction18(struct Task *task)
{
    if (sub_8104E18())
    {
        sSlotMachine->state = 19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = 9;
        }
    }
    return FALSE;
}

static bool8 SlotAction_Loop(struct Task *task)
{
    sub_8103D8C(0);
    sub_8103D8C(1);
    sub_8103D8C(2);
    sSlotMachine->state = 2;
    return FALSE;
}

static bool8 SlotAction_NoMatches(struct Task *task)
{
    if (++task->data[1] > 64)
    {
        task->data[1] = 0;
        sSlotMachine->state = 19;
    }
    return FALSE;
}

static bool8 SlotAction_PrintQuitTheGame(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_QuitTheGame, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x180, 0xE, 0xF);
    sSlotMachine->state = 22;
    return FALSE;
}

static bool8 SlotAction_SeeIfPlayerQuits(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0) // player chooses to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sub_8103D8C(0);
        sub_8103D8C(1);
        sub_8103D8C(2);
        sSlotMachine->coins += sSlotMachine->bet;
        sSlotMachine->state = 27;
    }
    else if (input == 1 || input == -1) // player chooses not to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

static bool8 SlotAction_PrintMessage_9999Coins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveGot9999Coins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 24;
    return FALSE;
}

static bool8 SlotAction_ExitMessage_9999Coins(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = 5;
    }
    return FALSE;
}

static bool8 SlotAction_PrintMessage_NoMoreCoins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveRunOutOfCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = 26;
    return FALSE;
}

static bool8 SlotAction_ExitMessage_NoMoreCoins(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = 27;
    }
    return FALSE;
}

static bool8 SlotAction_EndGame(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    AlertTVOfNewCoinTotal(GetCoins());
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    sSlotMachine->state++;
    return FALSE;
}

static bool8 SlotAction_FreeDataStructures(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSlotMachine->prevMainCb);
        FREE_AND_SET_NULL(sUnknown_0203AAF4);
        FREE_AND_SET_NULL(sUnknown_0203AAF8);
        FREE_AND_SET_NULL(sUnknown_0203AAFC);
        FREE_AND_SET_NULL(sUnknown_0203AB00);
        FREE_AND_SET_NULL(sUnknown_0203AB04);
        FREE_AND_SET_NULL(sUnknown_0203AB08);
        FREE_AND_SET_NULL(sUnknown_0203AB0C);
        FREE_AND_SET_NULL(sUnknown_0203AB10);
        FREE_AND_SET_NULL(sUnknown_0203AB14);
        FREE_AND_SET_NULL(sUnknown_0203AB18);
        FREE_AND_SET_NULL(sUnknown_0203AB1C);
        FREE_AND_SET_NULL(sUnknown_0203AB20);
        FREE_AND_SET_NULL(sUnknown_0203AB24);
        FREE_AND_SET_NULL(sUnknown_0203AB28);
        if (sUnknown_0203AAE4 != NULL)
            FREE_AND_SET_NULL(sUnknown_0203AAE4);
        if (sUnknown_0203AAE8 != NULL)
            FREE_AND_SET_NULL(sUnknown_0203AAE8);
        if (sUnknown_0203AAEC != NULL)
            FREE_AND_SET_NULL(sUnknown_0203AAEC);
        if (sUnknown_0203AAF0 != NULL)
            FREE_AND_SET_NULL(sUnknown_0203AAF0);
        FREE_AND_SET_NULL(sUnknown_0203AAC8);
        FREE_AND_SET_NULL(sSelectedPikaPowerTile);
        FREE_AND_SET_NULL(sUnknown_0203AAD0);
        FREE_AND_SET_NULL(sUnknown_0203AAD4);
        FREE_AND_SET_NULL(sUnknown_0203AAD8);
        FREE_AND_SET_NULL(sUnknown_0203AADC);
        FREE_AND_SET_NULL(sUnknown_0203AAE0);
        FREE_AND_SET_NULL(sUnknown_0203AB2C);
        FREE_AND_SET_NULL(sUnknown_0203AB30);

        FREE_AND_SET_NULL(sSlotMachine);
    }
    return FALSE;
}

static void DrawLuckyFlags(void)
{
    u8 attempts;

    if (sSlotMachine->fairRollsLeft == 0)
    {
        if (!(sSlotMachine->luckyFlags & (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777)))
        {
            if (IsThisRoundLucky())
            {
                attempts = AttemptsAtLuckyFlags_Top3();
                if (attempts != 3) // if you found a lucky number
                {
                    // attempts == 1:  reelTime flag set
                    sSlotMachine->luckyFlags |= gLuckyFlagSettings_Top3[attempts];
                    if (attempts != 1)
                    {
                        return;
                    }
                }
            }
            // if it's not a lucky round or you got reel time, roll for the lower lucky flags
            attempts = AttemptsAtLuckyFlags_NotTop3();
            if (attempts != 5)  // if you found a lucky number
            {
                sSlotMachine->luckyFlags |= gLuckyFlagSettings_NotTop3[attempts];
            }
        }
    }
}

static void SetLuckySpins(void)
{
    sSlotMachine->luckySpinsLeft = 0;
    if (sSlotMachine->luckyFlags)
        sSlotMachine->luckySpinsLeft = 1;
}

static u8 GetBiasTag(u8 luckyFlags)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        if (luckyFlags & 1)
            return gBiasTags[i];
        luckyFlags >>= 1;
    }
    return 0;
}

// you have way more luck betting 3 coins than anything lower
static bool8 IsThisRoundLucky(void)
{
    u8 rval = Random();
    if (gLuckyRoundProbabilities[sSlotMachine->machineId][sSlotMachine->bet - 1] > rval)
        return TRUE;
    return FALSE;
}

static u8 AttemptsAtLuckyFlags_Top3(void)
{
    s16 count;

    for (count = 0; count < 3; count++)
    {
        s16 rval = Random() & 0xff;
        s16 value = gLuckyFlagProbabilities_Top3[count][sSlotMachine->machineId];
        if (value > rval)
            break;
    }
    return count;
}

static u8 AttemptsAtLuckyFlags_NotTop3(void)
{
    s16 count;

    for (count = 0; count < 5; count++)
    {
        s16 rval = Random() & 0xff; // random byte
        s16 value = gLuckyFlagProbabilities_NotTop3[count][sSlotMachine->machineId];
        // make first attempt easier if it's a lucky game
        if (count == 0 && sSlotMachine->luckyGame == TRUE)
        {
            value += 10;
            if (value > 0x100)
                value = 0x100;
        }
        // make last attempt harder if it's a lucky game
        else if (count == 4 && sSlotMachine->luckyGame == TRUE)
        {
            value -= 10;
            if (value < 0)
                value = 0;
        }
        if (value > rval)
            break;
    }
    return count;
}

static u8 GetReelTimeProbability(u8 reelTimeDraw)
{
    if (sSlotMachine->luckyGame == FALSE)
        return gReeltimeProbabilities_UnluckyGame[reelTimeDraw][sSlotMachine->pikaPower];
    else
        return gReelTimeProbabilities_LuckyGame[reelTimeDraw][sSlotMachine->pikaPower];
}

static void GetReeltimeDraw(void)
{
    u8 rval;
    s16 reelTimeDraw;

    sSlotMachine->reelTimeDraw = 0;
    rval = Random();
    if (rval < GetReelTimeProbability(0))
        return;
    for (reelTimeDraw = 5; reelTimeDraw > 0; reelTimeDraw--)
    {
        rval = Random();
        if (rval < GetReelTimeProbability(reelTimeDraw))
            break;
    }
    sSlotMachine->reelTimeDraw = reelTimeDraw;
}

static bool8 SkipToReeltimeAction14(u16 i)
{
    u16 rval = Random() & 0xff;
    if (rval < gProbabilityTable_SkipToReeltimeAction14[i])
        return TRUE;
    else
        return FALSE;
}

static u16 SlowReelSpeed(void)
{
    u8 i = 0;
    u8 rval;
    u8 value;
    if (sSlotMachine->netCoinLoss >= 300)
        i = 4;
    else if (sSlotMachine->netCoinLoss >= 250)
        i = 3;
    else if (sSlotMachine->netCoinLoss >= 200)
        i = 2;
    else if (sSlotMachine->netCoinLoss >= 150)
        i = 1;
    rval = Random() % 100;
    value = gReelIncrementTable[i][0];
    if (rval < value)
        return 4;
    rval = Random() % 100;
    value = gReelIncrementTable[i][1] + gReelTimeBonusIncrementTable[sSlotMachine->fairRollsUsed];
    if (rval < value)
        return 2;
    return 8;
}

static void CheckMatch(void)
{
    sSlotMachine->matchedSymbols = 0;
    CheckMatch_CenterRow();
    if (sSlotMachine->bet > 1)
        CheckMatch_TopAndBottom();
    if (sSlotMachine->bet > 2)
        CheckMatch_Diagonals();
}

static void CheckMatch_CenterRow(void)
{
    u8 c1, c2, c3, match;

    c1 = GetNearbyTag_Quantized(0, 2);
    c2 = GetNearbyTag_Quantized(1, 2);
    c3 = GetNearbyTag_Quantized(2, 2);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        sSlotMachine->payout += gSlotPayouts[match];
        sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        sub_8103E04(0);
    }
}

static void CheckMatch_TopAndBottom(void)
{
    u8 c1, c2, c3, match;

    c1 = GetNearbyTag_Quantized(0, 1);
    c2 = GetNearbyTag_Quantized(1, 1);
    c3 = GetNearbyTag_Quantized(2, 1);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match == SLOT_MACHINE_MATCHED_1CHERRY)
            match = SLOT_MACHINE_MATCHED_2CHERRY;
        sSlotMachine->payout += gSlotPayouts[match];
        sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        sub_8103E04(1);
    }
    c1 = GetNearbyTag_Quantized(0, 3);
    c2 = GetNearbyTag_Quantized(1, 3);
    c3 = GetNearbyTag_Quantized(2, 3);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match == SLOT_MACHINE_MATCHED_1CHERRY)
            match = SLOT_MACHINE_MATCHED_2CHERRY;
        sSlotMachine->payout += gSlotPayouts[match];
        sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        sub_8103E04(2);
    }
}

static void CheckMatch_Diagonals(void)
{
    u8 c1, c2, c3, match;

    c1 = GetNearbyTag_Quantized(0, 1);
    c2 = GetNearbyTag_Quantized(1, 2);
    c3 = GetNearbyTag_Quantized(2, 3);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match != SLOT_MACHINE_MATCHED_1CHERRY)
        {
            sSlotMachine->payout += gSlotPayouts[match];
            sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        }
        sub_8103E04(3);
    }
    c1 = GetNearbyTag_Quantized(0, 3);
    c2 = GetNearbyTag_Quantized(1, 2);
    c3 = GetNearbyTag_Quantized(2, 1);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match != SLOT_MACHINE_MATCHED_1CHERRY)
        {
            sSlotMachine->payout += gSlotPayouts[match];
            sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        }
        sub_8103E04(4);
    }
}

static u8 GetMatchFromSymbolsInRow(u8 c1, u8 c2, u8 c3)
{
    if (c1 == c2 && c1 == c3)
        return gSym2Match[c1];
    if (c1 == SLOT_MACHINE_TAG_7_RED && c2 == SLOT_MACHINE_TAG_7_RED && c3 == SLOT_MACHINE_TAG_7_BLUE)
        return SLOT_MACHINE_MATCHED_777_MIXED;
    if (c1 == SLOT_MACHINE_TAG_7_BLUE && c2 == SLOT_MACHINE_TAG_7_BLUE && c3 == SLOT_MACHINE_TAG_7_RED)
        return SLOT_MACHINE_MATCHED_777_MIXED;
    if (c1 == SLOT_MACHINE_TAG_CHERRY)
        return SLOT_MACHINE_MATCHED_1CHERRY;
    return SLOT_MACHINE_MATCHED_NONE;
}

static void AwardPayout(void)
{
    RunAwardPayoutActions(CreateTask(RunAwardPayoutActions, 4));
}

static bool8 IsFinalTask_RunAwardPayoutActions(void)
{
    if (FindTaskIdByFunc(RunAwardPayoutActions) == TAIL_SENTINEL)
        return TRUE;
    else
        return FALSE;
}

static void RunAwardPayoutActions(u8 taskId)
{
    while (AwardPayoutActions[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

static bool8 AwardPayoutAction0(struct Task *task)
{
    if (sub_8103E38())
    {
        task->data[0]++;
        if (sSlotMachine->payout == 0)
        {
            task->data[0] = 2;
            return TRUE;
        }
    }
    return FALSE;
}
// task->data[1]: timer
static bool8 AwardPayoutAction_GivePayoutToPlayer(struct Task *task)
{
    if (!task->data[1]--)
    {
        if (IsFanfareTaskInactive())
            PlaySE(SE_PIN);
        sSlotMachine->payout--;
        if (sSlotMachine->coins < 9999)
            sSlotMachine->coins++;
        task->data[1] = 8;
        if (gMain.heldKeys & A_BUTTON)
            task->data[1] = 4;
    }
    if (IsFanfareTaskInactive() && gMain.newKeys & START_BUTTON)
    {
        PlaySE(SE_PIN);
        sSlotMachine->coins += sSlotMachine->payout;
        if (sSlotMachine->coins > 9999)
            sSlotMachine->coins = 9999;
        sSlotMachine->payout = 0;
    }
    if (sSlotMachine->payout == 0)
        task->data[0]++;
    return FALSE;
}

static bool8 AwardPayoutAction_FreeTask(struct Task *task)
{
    if (sub_8103E7C())
        DestroyTask(FindTaskIdByFunc(RunAwardPayoutActions));
    return FALSE;
}


// Returns the tag that is posOffset below the tag at the top of reelIndex's tape
static u8 GetNearbyTag_Quantized(u8 reelIndex, s16 posOffset)
{
    s16 tagIndex = (sSlotMachine->reelTagOffsets[reelIndex] + posOffset) % REEL_NUM_TAGS;
    if (tagIndex < 0)
        tagIndex += REEL_NUM_TAGS;
    return gReelSymbols[reelIndex][tagIndex];
}


// Calculates GetNearbyTag_Quantized as if the reel was snapped downwards into place
static u8 GetNearbyTag(u8 reelIndex, s16 posOffset)
{
    s16 tagOffset = 0;
    s16 result = sSlotMachine->reelPixelOffsets[reelIndex] % 24;
    if (result != 0)
        tagOffset = -1;
    return GetNearbyTag_Quantized(reelIndex, posOffset + tagOffset);
}

static u8 GetNearbyReelTimeTag(s16 n)
{
    s16 newPosition = (sSlotMachine->reeltimePosition + n) % 6;
    if (newPosition < 0)
        newPosition += 6;
    return gReelTimeTags[newPosition];
}

static void AdvanceSlotReel(u8 reelIndex, s16 value)
{
    sSlotMachine->reelPixelOffsets[reelIndex] += value;
    sSlotMachine->reelPixelOffsets[reelIndex] %= 504;
    sSlotMachine->reelTagOffsets[reelIndex] = REEL_NUM_TAGS - sSlotMachine->reelPixelOffsets[reelIndex] / 24;
}

s16 AdvanceSlotReelToNextTag(u8 reelIndex, s16 value)
{
    s16 offset = sSlotMachine->reelPixelOffsets[reelIndex] % 24;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceSlotReel(reelIndex, value);
        offset = sSlotMachine->reelPixelOffsets[reelIndex] % 24;
    }
    return offset;
}

static void AdvanceReeltimeReel(s16 value)
{
    sSlotMachine->reeltimePixelOffset += value;
    sSlotMachine->reeltimePixelOffset %= 120;
    sSlotMachine->reeltimePosition = 6 - sSlotMachine->reeltimePixelOffset / 20;
}

s16 AdvanceReeltimeReelToNextTag(s16 value)
{
    s16 offset = sSlotMachine->reeltimePixelOffset % 20;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceReeltimeReel(value);
        offset = sSlotMachine->reeltimePixelOffset % 20;
    }
    return offset;
}

static void GameplayTask_StopSlotReel(void)
{
    u8 i;
    for (i = 0; i < 3; i++)
    {
        u8 taskId = CreateTask(RunSlotReelActions, 2);
        gTasks[taskId].data[15] = i;
        sSlotMachine->slotReelTasks[i] = taskId;
        RunSlotReelActions(taskId);
    }
}

static void ReelTasks_SetUnkTaskData(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].data[0] = 1;
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].data[14] = 1;
}

static void sub_8102E1C(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].data[0] = 2;
}

static bool8 IsSlotReelMoving(u8 reelIndex)
{
    return gTasks[sSlotMachine->slotReelTasks[reelIndex]].data[14];
}

static void RunSlotReelActions(u8 taskId)
{
    while (SlotReelActions[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

// task->data[1]  reel turns
// task->data[15]  reelIndex
static bool8 SlotReelAction_StayStill(struct Task *task)
{
    return FALSE;
}

static bool8 SlotReelAction_Spin(struct Task *task)
{
    AdvanceSlotReel(task->data[15], sSlotMachine->reelIncrement);
    return FALSE;
}

// As in previous generations, the slot machine often doesn't stop exactly when you press stop
static bool8 SlotReelAction_DecideWhereToStop(struct Task *task)
{
    task->data[0]++;
    // initialize data for that reel --> these will be changed if gBiasTags can be lined up
    sSlotMachine->winnerRows[task->data[15]] = 0;
    sSlotMachine->reelExtraTurns[task->data[15]] = 0;

    if (sSlotMachine->fairRollsLeft == 0 && (sSlotMachine->luckyFlags == 0 || sSlotMachine->luckySpinsLeft == 0 || !DecideReelTurns_BiasTag[task->data[15]]()))
    {
        sSlotMachine->luckySpinsLeft = 0;
        DecideReelTurns_NoBiasTag[task->data[15]]();
    }
    task->data[1] = sSlotMachine->reelExtraTurns[task->data[15]];
    return TRUE;
}

// go to next tag and then do any additional turns
static bool8 SlotReelAction_MoveToStop(struct Task *task)
{
    u16 reelStopShocks[ARRAY_COUNT(ReelStopShocks)];
    s16 reelPixelPos;

    memcpy(reelStopShocks, ReelStopShocks, sizeof(ReelStopShocks));
    reelPixelPos = sSlotMachine->reelPixelOffsets[task->data[15]] % 24;
    if (reelPixelPos != 0)
        reelPixelPos = AdvanceSlotReelToNextTag(task->data[15], sSlotMachine->reelIncrement);
    else if (sSlotMachine->reelExtraTurns[task->data[15]])
    {
        sSlotMachine->reelExtraTurns[task->data[15]]--;
        AdvanceSlotReel(task->data[15], sSlotMachine->reelIncrement);
        reelPixelPos = sSlotMachine->reelPixelOffsets[task->data[15]] % 24;
    }
    if (reelPixelPos == 0 && sSlotMachine->reelExtraTurns[task->data[15]] == 0)
    {
        task->data[0]++;
        task->data[1] = reelStopShocks[task->data[1]];
        task->data[2] = 0;
    }
    return FALSE;
}

// make selected tag oscillate before it becomes still
static bool8 SlotReelAction_OscillatingStop(struct Task *task)
{
    sSlotMachine->reelPixelOffsetsWhileStopping[task->data[15]] = task->data[1];
    task->data[1] = -task->data[1];
    task->data[2]++;
    if ((task->data[2] & 0x3) == 0)
        task->data[1] >>= 1;
    if (task->data[1] == 0)
    {
        task->data[0] = 0;
        task->data[14] = 0;
        sSlotMachine->reelPixelOffsetsWhileStopping[task->data[15]] = 0;
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel1(void)
{
    u8 tag2 = GetBiasTag(sSlotMachine->luckyFlags);
    u8 tag1 = tag2;
    if (sSlotMachine->luckyFlags & (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777))
    {
        tag1 = SLOT_MACHINE_TAG_7_RED;
        tag2 = SLOT_MACHINE_TAG_7_BLUE;
    }
    return DecideReelTurns_BiasTag_Reel1_Bets[sSlotMachine->bet - 1](tag1, tag2);
}

static bool8 AreTagsAtPosition_Reel1(s16 pos, u8 tag1, u8 tag2)
{
    u8 tag = GetNearbyTag(0, pos);
    if (tag == tag1 || tag == tag2)
    {
        sSlotMachine->biasTag = tag;
        return TRUE;
    }
    return FALSE;
}

static bool8 AreCherriesOnScreen_Reel1(s16 offsetFromCenter)
{
    if (GetNearbyTag(0, 1 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY || GetNearbyTag(0, 2 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY || GetNearbyTag(0, 3 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsBiasTowardsCherryOr7s(void)
{
    if (sSlotMachine->luckyFlags & (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777 | LUCKY_BIAS_CHERRY))
        return TRUE;
    else
        return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel1_Bet1(u8 tag1, u8 tag2)
{
    s16 i;

    for (i = 0; i < 5; i++)
    {
        // if a lucky tag appears in the center row within 4 turns
        if (AreTagsAtPosition_Reel1(2 - i, tag1, tag2))
        {
            sSlotMachine->winnerRows[0] = 2;
            sSlotMachine->reelExtraTurns[0] = i;
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel1_Bet2or3(u8 tag1, u8 tag2)
{
    s16 i;
    bool8 biased = IsBiasTowardsCherryOr7s();
    // if lucky numbers or no cherries are currently on screen in reel 1...
    if (biased || !AreCherriesOnScreen_Reel1(0))
    {
        for (i = 1; i < 4; i++)
        {
            // if a bias tag is currently on the screen
            if (AreTagsAtPosition_Reel1(i, tag1, tag2))
            {
                sSlotMachine->winnerRows[0] = i;
                sSlotMachine->reelExtraTurns[0] = 0;
                return TRUE;
            }
        }
    }
    for (i = 1; i < 5; i++)
    {
        bool8 biasedCopy = biased;  // redundant
        // if biased or if in the next 4 turns there is a screen with no cherries...
        if (biasedCopy || !AreCherriesOnScreen_Reel1(i))
        {
            //...and if a bias tag is in top row of that screen
            if (AreTagsAtPosition_Reel1(1 - i, tag1, tag2))
            {
                //...and if it only took 1 turn and the lucky tag could also be the bottom row of a screen with no cherries...
                if (i == 1 && (biasedCopy || !AreCherriesOnScreen_Reel1(3)))
                {
                    sSlotMachine->winnerRows[0] = 3;
                    sSlotMachine->reelExtraTurns[0] = 3;
                    return TRUE;
                }
                //...or if it isn't the last turn and the lucky tag could be in the center row of a screen with no cherries...
                if (i < 4 && (biasedCopy || !AreCherriesOnScreen_Reel1(i + 1)))
                {
                    sSlotMachine->winnerRows[0] = 2;
                    sSlotMachine->reelExtraTurns[0] = i + 1;
                    return TRUE;
                }
                //...else
                sSlotMachine->winnerRows[0] = 1;
                sSlotMachine->reelExtraTurns[0] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel2(void)
{
    return DecideReelTurns_BiasTag_Reel2_Bets[sSlotMachine->bet - 1]();
}

static bool8 DecideReelTurns_BiasTag_Reel2_Bet1or2(void)
{
    s16 i;
    s16 biasTagLocation_Reel1 = sSlotMachine->winnerRows[0];

    for (i = 0; i < 5; i++)
    {
        // if biasTag appears in the same row within 4 turns
        if (GetNearbyTag(1, biasTagLocation_Reel1 - i) == sSlotMachine->biasTag)
        {
            sSlotMachine->winnerRows[1] = biasTagLocation_Reel1;
            sSlotMachine->reelExtraTurns[1] = i;
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel2_Bet3(void)
{
    s16 i;
    // if biasTag appears in the same row within 4 turns...
    if (DecideReelTurns_BiasTag_Reel2_Bet1or2())
    {
        //...and if the biasTag is not in middle row of reel 1 and if biasTag appears in middle row of reel 2 in 2 or 3 turns...
        if (sSlotMachine->winnerRows[0] != 2 && sSlotMachine->reelExtraTurns[1] > 1 && sSlotMachine->reelExtraTurns[1] != 4)
        {
            for (i = 0; i < 5; i++)
            {
                //...and if the bias tag will appear in the middle row within 4 turns
                if (GetNearbyTag(1, 2 - i) == sSlotMachine->biasTag)
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
        return TRUE;
    }
    // else if the biasTag is not in middle row of reel 1...
    if (sSlotMachine->winnerRows[0] != 2)
    {
        for (i = 0; i < 5; i++)
        {
            //...and if the biasTag will appear in the center row of reel 2 within 4 turns
            if (GetNearbyTag(1, 2 - i) == sSlotMachine->biasTag)
            {
                sSlotMachine->winnerRows[1] = 2;
                sSlotMachine->reelExtraTurns[1] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel3(void)
{
    u8 biasTag = sSlotMachine->biasTag;
    if (sSlotMachine->luckyFlags & LUCKY_BIAS_MIXED_777)
    {
        biasTag = SLOT_MACHINE_TAG_7_RED;
        if (sSlotMachine->biasTag == SLOT_MACHINE_TAG_7_RED)
        {
            biasTag = SLOT_MACHINE_TAG_7_BLUE;
        }
    }
    return DecideReelTurns_BiasTag_Reel3_Bets[sSlotMachine->bet - 1](biasTag);
}

static bool8 DecideReelTurns_BiasTag_Reel3_Bet1or2(u8 biasTag)
{
    s16 i;
    s16 biasTagLocation_Reel2 = sSlotMachine->winnerRows[1];

    for (i = 0; i < 5; i++)
    {
        // if the biasTag appears in the same row as in reel 2 within 4 turns
        if (GetNearbyTag(2, biasTagLocation_Reel2 - i) == biasTag)
        {
            sSlotMachine->winnerRows[2] = biasTagLocation_Reel2;
            sSlotMachine->reelExtraTurns[2] = i;
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 DecideReelTurns_BiasTag_Reel3_Bet3(u8 biasTag)
{
    s16 i;
    s16 biasTagFinalPos;
    // if the final position of the biasTag matches in reel 1 and reel 2...
    if (sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1])
        //...then try to line it up in reel 3
        return DecideReelTurns_BiasTag_Reel3_Bet1or2(biasTag);
    // else place it in the row opposite reel 1's
    if (sSlotMachine->winnerRows[0] == 1)
        biasTagFinalPos = 3;
    else
        biasTagFinalPos = 1;
    for (i = 0; i < 5; i++)
    {
        // if the biasTag lands in that position within 4 turns
        if (GetNearbyTag(2, biasTagFinalPos - i) == biasTag)
        {
            sSlotMachine->reelExtraTurns[2] = i;
            sSlotMachine->winnerRows[2] = biasTagFinalPos;
            return TRUE;
        }
    }
    return FALSE;
}

// Advance until there are no cherries on screen in reel 1

static void DecideReelTurns_NoBiasTag_Reel1(void)
{
    s16 i = 0;

    while (AreCherriesOnScreen_Reel1(i) != 0)
        i++;
    sSlotMachine->reelExtraTurns[0] = i;
}

static bool8 IsBiasTag777_SwitchColor(u8 *biasTagPtr)
{
    if (*biasTagPtr == SLOT_MACHINE_TAG_7_RED)
    {
        *biasTagPtr = SLOT_MACHINE_TAG_7_BLUE;
        return TRUE;
    }
    if (*biasTagPtr == SLOT_MACHINE_TAG_7_BLUE)
    {
        *biasTagPtr = SLOT_MACHINE_TAG_7_RED;
        return TRUE;
    }
    return FALSE;
}

static void DecideReelTurns_NoBiasTag_Reel2(void)
{
    DecideReelTurns_NoBiasTag_Reel2_Bets[sSlotMachine->bet - 1]();
}

// only does stuff if the biasTag is one of the 7's, plus other conditions
static void DecideReelTurns_NoBiasTag_Reel2_Bet1(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        u8 biasTag = GetNearbyTag(0, 2 - sSlotMachine->reelExtraTurns[0]);
        //...and if biasTag is one of the 7's...
        if (IsBiasTag777_SwitchColor(&biasTag))
        //...swap color of biasTag...
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                //...and if the biasTag appears within 4 turns
                if (biasTag == GetNearbyTag(1, 2 - i))
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}

static void DecideReelTurns_NoBiasTag_Reel2_Bet2(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        u8 biasTag = GetNearbyTag(0, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        //...and if biasTag is one of the 7's...
        if (IsBiasTag777_SwitchColor(&biasTag))
        //...swap color of biasTag...
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                //...and if the biasTag appears in same row in reel 2 within 4 turns
                if (biasTag == GetNearbyTag(1, sSlotMachine->winnerRows[0] - i))
                {
                    sSlotMachine->winnerRows[1] = sSlotMachine->winnerRows[0];
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}

static void DecideReelTurns_NoBiasTag_Reel2_Bet3(void)
{
    s16 i;
    s16 j;
    // if reel 1 has a biasTag and bit 7 is set in luckyFlags...
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        //...and if biasTag appeared in the center row of reel 1
        if (sSlotMachine->winnerRows[0] == 2)
        {
            DecideReelTurns_NoBiasTag_Reel2_Bet2();
        }
        else
        {
            u8 biasTag = GetNearbyTag(0, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
            //...and if biasTag is one of the 7's...
            if (IsBiasTag777_SwitchColor(&biasTag))
            //...swap the color of the 7...
            {
                j = 2;
                if (sSlotMachine->winnerRows[0] == 3)
                    j = 3;
                for (i = 0; i < 2; i++, j--)
                {
                    if (biasTag == GetNearbyTag(1, j))
                    {
                        sSlotMachine->winnerRows[1] = j;
                        sSlotMachine->reelExtraTurns[1] = 0;
                        return;
                    }
                }
                for (j = 1; j < 5; j++)
                {
                    if (biasTag == GetNearbyTag(1, sSlotMachine->winnerRows[0] - j))
                    {
                        if (sSlotMachine->winnerRows[0] == 1)
                        {
                            if (j < 3)
                            {
                                sSlotMachine->winnerRows[1] = 2;
                                sSlotMachine->reelExtraTurns[1] = j + 1;
                            }
                            else
                            {
                                sSlotMachine->winnerRows[1] = 1;
                                sSlotMachine->reelExtraTurns[1] = j;
                            }
                        }
                        else
                        {
                            if (j < 3)
                            {
                                sSlotMachine->winnerRows[1] = 3;
                                sSlotMachine->reelExtraTurns[1] = j;
                            }
                            else
                            {
                                sSlotMachine->winnerRows[1] = 2;
                                sSlotMachine->reelExtraTurns[1] = j - 1;
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
}

static bool8 AreTagsMixed77(u8 tag1, u8 tag2)
{
    if ((tag1 == SLOT_MACHINE_TAG_7_RED && tag2 == SLOT_MACHINE_TAG_7_BLUE) || (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag2 == SLOT_MACHINE_TAG_7_RED))
        return TRUE;
    else
        return FALSE;
}

static bool8 AreTagsMixed777(u8 tag1, u8 tag2, u8 tag3)
{
    if ((tag1 == SLOT_MACHINE_TAG_7_RED && tag2 == SLOT_MACHINE_TAG_7_BLUE && tag3 == SLOT_MACHINE_TAG_7_RED) ||
        (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag2 == SLOT_MACHINE_TAG_7_RED && tag3 == SLOT_MACHINE_TAG_7_BLUE))
        return TRUE;
    else
        return FALSE;
}

static bool8 TagsDontMatchOrHaveAny7s(u8 tag1, u8 tag2, u8 tag3)
{
    if ((tag1 == SLOT_MACHINE_TAG_7_RED && tag2 == SLOT_MACHINE_TAG_7_BLUE && tag3 == SLOT_MACHINE_TAG_7_RED) ||
        (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag2 == SLOT_MACHINE_TAG_7_RED && tag3 == SLOT_MACHINE_TAG_7_BLUE) ||
        (tag1 == SLOT_MACHINE_TAG_7_RED && tag2 == SLOT_MACHINE_TAG_7_RED && tag3 == SLOT_MACHINE_TAG_7_BLUE) ||
        (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag2 == SLOT_MACHINE_TAG_7_BLUE && tag3 == SLOT_MACHINE_TAG_7_RED) ||
        (tag1 == tag2 && tag1 == tag3))
    {
        return FALSE;
    }
    return TRUE;
}

static void DecideReelTurns_NoBiasTag_Reel3(void)
{
    DecideReelTurns_NoBiasTag_Reel3_Bets[sSlotMachine->bet - 1]();
}

static void DecideReelTurns_NoBiasTag_Reel3_Bet1(void)
{
    s16 i = 0;
    u8 tag1 = GetNearbyTag(0, 2 - sSlotMachine->reelExtraTurns[0]);
    u8 tag2 = GetNearbyTag(1, 2 - sSlotMachine->reelExtraTurns[1]);
    // if tags match in first 2 reels...
    if (tag1 == tag2)
    {
        //...spin until you get non-matching tag
        while (1)
        {
            u8 tag3;
            if (!(tag1 == (tag3 = GetNearbyTag(2, 2 - i)) || (tag1 == SLOT_MACHINE_TAG_7_RED && tag3 == SLOT_MACHINE_TAG_7_BLUE) || (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag3 == SLOT_MACHINE_TAG_7_RED)))
                break;
            i++;
        }
    }
    else if (AreTagsMixed77(tag1, tag2))
    {
        if (sSlotMachine->luckyFlags & LUCKY_BIAS_777)
        {
            //...see if you can match with reel 1 within 4 turns
            for (i = 0; i < 5; i++)
            {
                if (tag1 == GetNearbyTag(2, 2 - i))
                {
                    sSlotMachine->reelExtraTurns[2] = i;
                    return;
                }
            }
        }
        // turn until you aren't matching with reel 1
        i = 0;
        while (1)
        {
            if (tag1 != GetNearbyTag(2, 2 - i))
                break;
            i++;
        }
    }
    sSlotMachine->reelExtraTurns[2] = i;
}

static void DecideReelTurns_NoBiasTag_Reel3_Bet2(void)
{
    s16 extraTurns = 0;
    s16 i;
    u8 tag1;
    u8 tag2;
    u8 tag3;
    if (sSlotMachine->winnerRows[1] != 0 && sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1] && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        tag1 = GetNearbyTag(0, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetNearbyTag(1, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);
        //...and if tags are mixed 7s...
        if (AreTagsMixed77(tag1, tag2))
        {
            //...try to match with reel 1 within 4 turns
            for (i = 0; i < 5; i++)
            {
                tag3 = GetNearbyTag(2, sSlotMachine->winnerRows[1] - i);
                if (tag1 == tag3)
                {
                    extraTurns = i;
                    break;
                }
            }
        }
    }
    // GUESS: spin until there's no possible match within 4 turns of you stopping
    while (1)
    {
        s16 loopExit;
        for (i = 1, loopExit = 0; i < 4; i++)
        {
            tag1 = GetNearbyTag(0, i - sSlotMachine->reelExtraTurns[0]);  // why does this update with i
            tag2 = GetNearbyTag(1, i - sSlotMachine->reelExtraTurns[1]);
            tag3 = GetNearbyTag(2, i - extraTurns);
            // if bit 7 of luckyFlags is unset...
            //...and if all 3 tags match and they're not mixed 7s
            if (!TagsDontMatchOrHaveAny7s(tag1, tag2, tag3) && (!AreTagsMixed777(tag1, tag2, tag3) || !(sSlotMachine->luckyFlags & LUCKY_BIAS_777)))
            {
                loopExit++;
                break;
            }
        }
        if (loopExit == 0)
            break;
        extraTurns++;
    }
    sSlotMachine->reelExtraTurns[2] = extraTurns;
}

static void DecideReelTurns_NoBiasTag_Reel3_Bet3(void)
{
    u8 tag1;
    u8 tag2;
    u8 tag3;
    s16 j;
    s16 i;

    DecideReelTurns_NoBiasTag_Reel3_Bet2();
    if (sSlotMachine->winnerRows[1] != 0 && sSlotMachine->winnerRows[0] != sSlotMachine->winnerRows[1] && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        tag1 = GetNearbyTag(0, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetNearbyTag(1, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);
        //..and if tags are mixed 7s...
        if (AreTagsMixed77(tag1, tag2))
        {
            j = 1;
            if (sSlotMachine->winnerRows[0] == 1)
                j = 3;
            for (i = 0; i < 5; i++)
            {
                tag3 = GetNearbyTag(2, j - (sSlotMachine->reelExtraTurns[2] + i));
                if (tag1 == tag3)
                {
                    sSlotMachine->reelExtraTurns[2] += i;
                    break;
                }
            }
        }
    }
    while (1)
    {
        tag1 = GetNearbyTag(0, 1 - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetNearbyTag(1, 2 - sSlotMachine->reelExtraTurns[1]);
        tag3 = GetNearbyTag(2, 3 - sSlotMachine->reelExtraTurns[2]);
        if (TagsDontMatchOrHaveAny7s(tag1, tag2, tag3) || (AreTagsMixed777(tag1, tag2, tag3) && sSlotMachine->luckyFlags & LUCKY_BIAS_777))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }
    while (1)
    {
        tag1 = GetNearbyTag(0, 3 - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetNearbyTag(1, 2 - sSlotMachine->reelExtraTurns[1]);
        tag3 = GetNearbyTag(2, 1 - sSlotMachine->reelExtraTurns[2]);
        if (TagsDontMatchOrHaveAny7s(tag1, tag2, tag3) || (AreTagsMixed777(tag1, tag2, tag3) && sSlotMachine->luckyFlags & LUCKY_BIAS_777))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }
}

static void sub_8103C14(u8 a0)
{
    u8 taskId = CreateTask(sub_8103C48, 5);
    gTasks[taskId].data[15] = a0;
    sub_8103C48(taskId);
}

static void sub_8103C48(u8 taskId)
{
    gUnknown_083ECBA0[gTasks[taskId].data[0]](&gTasks[taskId], taskId);
}

static void sub_8103C78(struct Task *task, u8 taskId)
{
    sub_81065A8(gUnknown_083ECBAC[task->data[15]], 0x62, 0x63, 0x72, 0x73);
    task->data[0]++;
}

static void sub_8103CAC(struct Task *task, u8 taskId)
{
    if (++task->data[1] > 11)
        task->data[0]++;
}

static void sub_8103CC8(struct Task *task, u8 taskId)
{
    sub_81065A8(gUnknown_083ECBAC[task->data[15]], 0x42, 0x43, 0x52, 0x53);
    DestroyTask(taskId);
}

static void LoadLitTile(u8 tileId)
{
    LoadPalette(gUnknown_083EDD08[tileId], gUnknown_083EDD30[tileId], 2);
}

static void sub_8103D28(u8 a0)
{
    LoadPalette(gUnknown_083EDD1C[a0], gUnknown_083EDD30[a0], 2);
}

// light up the value bet by the player
static void LoadBetTiles(u8 betVal)
{
    u8 i;
    for (i = 0; i < gNumberBettingTiles[betVal]; i++)
        LoadLitTile(gBettingTilesId[betVal][i]);
}

static void sub_8103D8C(u8 a0)
{
    u8 i;
    for (i = 0; i < gNumberBettingTiles[a0]; i++)
        sub_8103D28(gBettingTilesId[a0][i]);
}

static void sub_8103DC8(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        u8 spriteId = CreateInvisibleSprite(sub_8103EE4);
        gSprites[spriteId].data[0] = i;
        sSlotMachine->unk44[i] = spriteId;
    }
}

static void sub_8103E04(u8 a0)
{
    struct Sprite *sprite = gSprites + sSlotMachine->unk44[a0];
    sprite->data[1] = 1;
    sprite->data[2] = 4;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 2;
    sprite->data[7] = 0;
}

// something with payout digits
static bool8 sub_8103E38(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        struct Sprite *sprite = &gSprites[sSlotMachine->unk44[i]];
        if (sprite->data[1] && sprite->data[2])
            return FALSE;
    }
    return TRUE;
}

static bool8 sub_8103E7C(void)
{
    u8 i;
    for (i = 0; i < 5; i++)
    {
        if (!sub_8103EAC(sSlotMachine->unk44[i]))
            return FALSE;
    }
    return TRUE;
}

static bool8 sub_8103EAC(u8 spriteId)
{
    struct Sprite *sprite = gSprites + spriteId;
    if (!sprite->data[1])
        return TRUE;
    if (sprite->data[7])
        sprite->data[1] = 0;
    return sprite->data[7];
}

static void sub_8103EE4(struct Sprite *sprite)
{
    s16 r4;
    if (sprite->data[1])
    {
        if (!sprite->data[3]--)
        {
            sprite->data[7] = 0;
            sprite->data[3] = 1;
            sprite->data[4] += sprite->data[5];
            r4 = 4;
            if (sprite->data[2])
                r4 = 8;
            if (sprite->data[4] <= 0)
            {
                sprite->data[7] = 1;
                sprite->data[5] = -sprite->data[5];
                if (sprite->data[2])
                    sprite->data[2]--;
            }
            else if (sprite->data[4] >= r4)
                sprite->data[5] = -sprite->data[5];
            if (sprite->data[2])
                sprite->data[3] <<= 1;
        }
        MultiplyPaletteRGBComponents(gUnknown_083EDD30[sprite->data[0]], sprite->data[4], sprite->data[4], sprite->data[4]);
    }
}

static void sub_8103F70(void)
{
    u8 taskId = CreateTask(sub_8103FE8_, 6);
    gTasks[taskId].data[3] = 1;
    sub_8103FE8_(taskId);
}

static bool8 sub_8103FA0(void)
{
    u8 taskId = FindTaskIdByFunc(sub_8103FE8_);
    if (!gTasks[taskId].data[2])
    {
        DestroyTask(taskId);
        LoadPalette(gUnknown_083EDDAC, 0x10, 0x20);
        return TRUE;
    }
    return FALSE;
}

static void sub_8103FE8_(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->data[1]--)
    {
        task->data[1] = 4;
        task->data[2] += task->data[3];
        if (task->data[2] == 0 || task->data[2] == 2)
            task->data[3] = -task->data[3];
    }
    LoadPalette(gUnknown_083EDDA0[task->data[2]], 0x10, 0x20);
}

static void GameplayTask_PikaPower(void)
{
    sSlotMachine->unkTaskPointer3E = CreateTask(sub_81040E8, 8);
}

static void DisplayPikaPower(u8 pikaPower)
{
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3E];
    ClearTaskDataFields_2orHigher(task);
    task->data[0] = 1;
    task->data[1]++;
    task->data[15] = 1; // points to a reelIndex
}

static void sub_8104098(void)
{
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3E];
    ClearTaskDataFields_2orHigher(task);
    task->data[0] = 3;
    task->data[15] = 1; // points to a reelIndex
}

static bool8 sub_81040C8(void)
{
    return gTasks[sSlotMachine->unkTaskPointer3E].data[15];
}

static void sub_81040E8(u8 taskId)
{
    gUnknown_083ECBB4[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void nullsub_68(struct Task *task)
{
}

static void sub_810411C(struct Task *task)
{
    task->data[2] = sub_8105B1C((task->data[1] << 3) + 20, 20);
    task->data[0]++;
}

static void sub_8104144(struct Task *task)
{
    if (gSprites[task->data[2]].data[7])
    {
        s16 r5 = task->data[1] + 2;
        s16 r3 = 0;
        s16 r2 = 0;
        if (task->data[1] == 1)
            r3 = 1, r2 = 1;
        else if (task->data[1] == 16)
            r3 = 2, r2 = 2;
        sSelectedPikaPowerTile[r2] = pikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, r5 + 0x40);
        sub_8105B88(task->data[2]);
        task->data[0] = 0;
        task->data[15] = 0; // points to a reelIndex
    }
}

static void sub_81041AC(struct Task *task)
{
    s16 r5 = task->data[1] + 2;
    s16 r3 = 0;
    s16 r2 = 3;
    if (task->data[1] == 1)
        r3 = 1, r2 = 1;
    else if (task->data[1] == 16)
        r3 = 2, r2 = 2;
    if (task->data[2] == 0)
    {
        sSelectedPikaPowerTile[r2] = pikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, r5 + 0x40);
        task->data[1]--;
    }
    if (++task->data[2] >= 20)
        task->data[2] = 0;
    if (task->data[1] == 0)
    {
        task->data[0] = 0;
        task->data[15] = 0;
    }
}

static void ClearTaskDataFields_2orHigher(struct Task *task)
{
    u8 i;

    for (i = 2; i < 16; i++)
        task->data[i] = 0;
}

// possibly load tiles for pika power meter
static void sub_810423C(u8 pikaPower)
{
    s16 i;
    s16 r3 = 0, r1 = 0;
    s16 r4 = 3;
    for (i = 0; i < pikaPower; i++, r4++)
    {
        r3 = 0, r1 = 0;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15) // pikaPower meter is full
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = pikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, r4 + 0x40);
    }
    for (; i < 16; i++, r4++)
    {
        r3 = 0, r1 = 3;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15)
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = pikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, r4 + 0x40);
    }
    gTasks[sSlotMachine->unkTaskPointer3E].data[1] = pikaPower;
}

static void BeginReeltime(void)
{
    u8 taskId = CreateTask(RunReeltimeActions, 7);
    RunReeltimeActions(taskId);
}

static bool8 IsFinalTask_RunReelTimeActions(void)
{
    if (FindTaskIdByFunc(RunReeltimeActions) == TAIL_SENTINEL)
        return TRUE;
    return FALSE;
}

static void RunReeltimeActions(u8 taskId)
{
    // task.data[0] points to which ReelTimeAction to do, and starts at 0
    // task.data[1] has something to do with the threshold
    // task.data[4] says how many pixels to advance the reel
    // task.data[5] is a timer
    ReeltimeActions[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void ReeltimeAction0(struct Task *task)
{
    sSlotMachine->fairRollsLeft = 0;
    sSlotMachine->reeltimePixelOffset = 0;
    sSlotMachine->reeltimePosition = 0;
    task->data[0]++;
    task->data[1] = 0;
    task->data[2] = 30;
    task->data[4] = 1280; // reel speed
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    sub_8104A40(REG_OFFSET_BG3VOFS, 0);
    sub_81051C0();
    sub_8105100();
    sub_81052EC();
    sub_81053A0();
    sub_810545C();
    GetReeltimeDraw();
    StopMapMusic();
    PlayNewMapMusic(MUS_BD_TIME);
}

static void ReeltimeAction1(struct Task *task)
{
    s16 r3;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    r3 = ((task->data[1] + 240) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (r3 != task->data[2] && task->data[3] <= 18)
    {
        task->data[2] = r3;
        task->data[3] = task->data[1] >> 3;
        sub_8104A40(r3, task->data[3]);
    }
    if (task->data[1] >= 200)
    {
        task->data[0]++;
        task->data[3] = 0;
    }
    AdvanceReeltimeReel(task->data[4] >> 8);
}

static void ReeltimeAction2(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    if (++task->data[5] >= 60)
    {
        task->data[0]++;
        CreateReelTimeSprites1();
        CreateReelTimeSprite2();
    }
}

static void ReeltimeAction3(struct Task *task)
{
    int r5;
    u8 sp0[ARRAY_COUNT(gUnknown_085A75C0)];
    s16 sp4[ARRAY_COUNT(gUnknown_085A75C4)];
    s16 spC[ARRAY_COUNT(gUnknown_085A75CC)];

    memcpy(sp0, gUnknown_085A75C0, sizeof(gUnknown_085A75C0));
    memcpy(sp4, gUnknown_085A75C4, sizeof(gUnknown_085A75C4));
    memcpy(spC, gUnknown_085A75CC, sizeof(gUnknown_085A75CC));

    AdvanceReeltimeReel(task->data[4] >> 8);
    // gradually slow down the reel
    task->data[4] -= 4;
    r5 = 4 - (task->data[4] >> 8);
    sub_8105688(sp4[r5]);
    sub_81057E8(spC[r5]);
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimeSprite3F, sp0[r5]);
    // once speed goes below 256, go to next ReelTimeAction and keep the speed level
    if (task->data[4] <= 0x100)
    {
        task->data[0]++;
        task->data[4] = 0x100;
        task->data[5] = 0;
    }
}

static void ReeltimeAction4(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    if (++task->data[5] >= 80)
    {
        task->data[0]++;
        task->data[5] = 0;
        sub_81057E8(2);
        StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimeSprite3F, 3);
    }
}

static void ReeltimeAction5(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x80;
    if (++task->data[5] >= 80)
    {
        task->data[0]++;
        task->data[5] = 0;
    }
}

static void ReeltimeAction6(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x40;
    if (++task->data[5] >= 40)
    {
        task->data[5] = 0;
        if (sSlotMachine->reelTimeDraw)
        {
            if (sSlotMachine->fairRollsLeft <= task->data[6])
                task->data[0]++;
        }
        else if (task->data[6] > 3)
        {
            task->data[0]++;
        }
        else if (SkipToReeltimeAction14(task->data[6]))
        {
            task->data[0] = 14;
        }
        task->data[6]++;
    }
}

static void ReelTimeAction_LandOnOutcome(struct Task *task)
{
    s16 reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
    if (reeltimePixelOffset)
    {
        reeltimePixelOffset = AdvanceReeltimeReelToNextTag(task->data[4] >> 8);
        task->data[4] = (u8)task->data[4] + 0x40;
    }
    else if (GetNearbyReelTimeTag(1) != sSlotMachine->reelTimeDraw)
    {
        AdvanceReeltimeReel(task->data[4] >> 8);
        reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
        task->data[4] = (u8)task->data[4] + 0x40;
    }
    if (reeltimePixelOffset == 0 && GetNearbyReelTimeTag(1) == sSlotMachine->reelTimeDraw)
    {
        task->data[4] = 0;  // stop moving
        task->data[0]++;
    }
}

static void ReeltimeAction8(struct Task *task)
{
    if (++task->data[4] >= 60)
    {
        StopMapMusic();
        sub_81056C0();
        sub_8105804();
        task->data[0]++;
        if(sSlotMachine->reelTimeDraw == 0)
        {
            task->data[4] = 0xa0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimeSprite3F, 5);
            PlayFanfare(MUS_ME_ZANNEN);
        }
        else
        {
            task->data[4] = 0xc0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimeSprite3F, 4);
            gSprites[sSlotMachine->reelTimeSprite3F].animCmdIndex = 0;
            if (sSlotMachine->pikaPower)
            {
                sub_8104098();
                sSlotMachine->pikaPower = 0;
            }
            PlayFanfare(MUS_ME_B_SMALL);
        }
    }
}

static void ReeltimeAction9(struct Task *task)
{
    if ((task->data[4] == 0 || --task->data[4] == 0) && !sub_81040C8())
        task->data[0]++;
}

static void ReeltimeAction10(struct Task *task)
{
    s16 r4;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    task->data[3] += 8;
    r4 = ((task->data[1] - 8) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (task->data[3] >> 3 <= 25)
        sub_8104A88(r4);
    else
        task->data[0]++;
}

static void ReeltimeAction11(struct Task *task)
{
    sSlotMachine->fairRollsUsed = 0;
    sSlotMachine->fairRollsLeft = sSlotMachine->reelTimeDraw;
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    sSlotMachine->reelIncrement = 8;
    sub_810514C();
    sub_81054B8();
    sub_8105524();
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    if (sSlotMachine->fairRollsLeft == 0)
    {
        DestroyTask(FindTaskIdByFunc(RunReeltimeActions));
    }
    else
    {
        sub_8104CAC(4);
        task->data[1] = SlowReelSpeed();
        task->data[2] = 0;
        task->data[3] = 0;
        task->data[0]++;
    }
}

static void ReeltimeAction12(struct Task *task)
{
    if (sSlotMachine->reelIncrement == task->data[1])
        task->data[0]++;
    else if (sSlotMachine->reelPixelOffsets[0] % 24 == 0 && (++task->data[2]& 0x07) == 0)
        sSlotMachine->reelIncrement >>= 1;
}

static void ReeltimeAction13(struct Task *task)
{
    if (sub_8104E18())
        DestroyTask(FindTaskIdByFunc(RunReeltimeActions));
}

static void ReeltimeAction14(struct Task *task)
{
    sub_81054B8();
    sub_81056C0();
    sub_8105804();
    sub_8105854();
    gSprites[sSlotMachine->unk4E[0]].invisible = TRUE;
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimeSprite3F, 5);
    task->data[0]++;
    task->data[4] = 4;
    task->data[5] = 0;
    StopMapMusic();
    PlayFanfare(MUS_ME_ZANNEN);
    PlaySE(SE_W153);
}

static void ReeltimeAction15(struct Task *task)
{
    gSpriteCoordOffsetY = task->data[4];
    SetGpuReg(REG_OFFSET_BG1VOFS, task->data[4]);
    if (task->data[5] & 0x01)
        task->data[4] = -task->data[4];
    if ((++task->data[5] & 0x1f) == 0)
        task->data[4] >>= 1;
    if (task->data[4] == 0)
    {
        sub_81058A0();
        sub_81058C4();
        sub_8105284_();
        sub_81059E8();
        gSprites[sSlotMachine->unk4E[0]].invisible = FALSE;
        task->data[0]++;
        task->data[5] = 0;
    }
}

static void ReeltimeAction16(struct Task *task)
{
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    if (sub_8105ACC())
    {
        task->data[0]++;
        sub_8105AEC();
    }
}

static void ReeltimeAction17(struct Task *task)
{
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    sub_810514C();
    sub_8105554();
    sub_8105524();
    sub_81059B8();
    DestroyTask(FindTaskIdByFunc(RunReeltimeActions));
}

static void sub_8104A40(s16 a0, s16 a1)
{
    s16 i;

    for (i = 4; i < 15; i++)
    {
        LoadBgTilemap(1, &gReelTimeWindowTilemap[a1 + (i - 4) * 20], 2, 32 * i + a0);
    }
}

static void sub_8104A88(s16 a0)
{
    u8 i;

    for (i = 4; i < 15; i++)
    {
        LoadBgTilemap(1, gUnknown_085A9898, 2, 32 * i + a0);
    }
}

static void OpenInfoBox(u8 seemsUnused)
{
    u8 taskId = CreateTask(RunInfoBoxActions, 1);
    gTasks[taskId].data[1] = seemsUnused;
    RunInfoBoxActions(taskId);
}

static bool8 IsInfoBoxClosed(void)
{
    if (FindTaskIdByFunc(RunInfoBoxActions) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

static void RunInfoBoxActions(u8 taskId)
{
    InfoBoxActions[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void InfoBox_FadeIn(struct Task *task)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    task->data[0]++;
}

static void InfoBox_WaitForFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->data[0]++;
}

static void InfoBox_8104B80(struct Task *task)
{
    sub_8104DA4();
    sub_81065DC();
    AddWindow(&gUnknown_085A7444);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    task->data[0]++;
}

static void InfoBox_AddText(struct Task *task)
{
    AddTextPrinterParameterized3(1, 1, 2, 5, gColors_ReeltimeHelp, 0, gText_ReelTimeHelp);
    CopyWindowToVram(1, 3);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    task->data[0]++;
}

static void InfoBox_AwaitPlayerInput(struct Task *task)
{
    if (gMain.newKeys & (B_BUTTON | SELECT_BUTTON))
    {
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        ClearWindowTilemap(1);
        CopyWindowToVram(1, 1);
        RemoveWindow(1);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
        task->data[0]++;
    }
}

static void InfoBox_812DE14(struct Task *task)
{
    sub_812F968();
    ShowBg(3);
    task->data[0]++;
}

static void InfoBox_812DE30(struct Task *task)
{
    sub_8104CAC(task->data[1]);
    task->data[0]++;
}

static void InfoBox_8104BFC(struct Task *task)
{
    sub_810423C(sSlotMachine->pikaPower);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB(0, 0, 0));
    task->data[0]++;
}

static void InfoBox_FreeTask(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(RunInfoBoxActions));
}

static void sub_8104C5C(void)
{
    u8 i;
    struct Task *task;
    i = CreateTask(sub_8104E74_, 3);
    sSlotMachine->unkTaskPointer3D = i;
    task = &gTasks[i];
    task->data[1] = -1;
    for (i = 4; i < 16; i++)
        task->data[i] = MAX_SPRITES;
}

// possibly initialize each wheel
static void sub_8104CAC(u8 arg0)
{
    u8 i;
    struct Task *task;

    sub_8104DA4();

    task = &gTasks[sSlotMachine->unkTaskPointer3D];
    task->data[1] = arg0;

    for (i = 0; gUnknown_083ED048[arg0][i].unk00 != 0xFF; i++)
    {
        u8 spriteId;
        spriteId = sub_8105BB4(
                gUnknown_083ED048[arg0][i].unk00,
                gUnknown_083ED048[arg0][i].unk01,
                gUnknown_083ED048[arg0][i].unk02
        );
        task->data[4 + i] = spriteId;
    }
}

static void sub_8104D30(u8 a0, SpriteCallback a1, s16 a2, s16 a3, s16 a4)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3D];
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] == MAX_SPRITES)
        {
            task->data[i] = sub_8105BF8(a0, a1, a2, a3, a4);
            break;
        }
    }
}

static void sub_8104DA4(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3D];
    if ((u16)task->data[1] != 0xFFFF)
        gUnknown_083ED064[task->data[1]]();
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[task->data[i]]);
            task->data[i] = MAX_SPRITES;
        }
    }
}

static bool8 sub_8104E18(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3D];
    for (i = 4; i < 16; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            if (gSprites[task->data[i]].data[7])
                return FALSE;
        }
    }
    return TRUE;
}

static void sub_8104E74_(u8 taskId)
{
    gUnknown_083ECC54[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void nullsub_69(struct Task *task)
{
}

static void sub_8104EA8(void)
{
    s16 i;
    s16 j;
    s16 x;
    for (i = 0, x = 0x30; i < 3; i++, x += 0x28)
    {
        for (j = 0; j < 120; j += 24)
        {
            struct Sprite *sprite = gSprites + CreateSprite(&gSpriteTemplate_83ED414, x, 0, 14);
            sprite->oam.priority = 3;
            sprite->data[0] = i;
            sprite->data[1] = j;
            sprite->data[3] = -1;
        }
    }
}

/*static */void sub_8104F18(struct Sprite *sprite)
{
    sprite->data[2] = sSlotMachine->reelPixelOffsets[sprite->data[0]] + sprite->data[1];
    sprite->data[2] %= 120;
    sprite->pos1.y = sSlotMachine->reelPixelOffsetsWhileStopping[sprite->data[0]] + 28 + sprite->data[2];
    sprite->sheetTileStart = GetSpriteTileStartByTag(GetNearbyTag_Quantized(sprite->data[0], sprite->data[2] / 24));
    SetSpriteSheetFrameTileNum(sprite);
}

static void sub_8104F8C(void)
{
    s16 i;
    s16 x;

    for (x = 203, i = 1; i < 10000; i *= 10, x -= 7)
        sub_8104FF4(x, 23, 0, i);
    for (x = 235, i = 1; i < 10000; i *= 10, x -= 7)
        sub_8104FF4(x, 23, 1, i);
}

static void sub_8104FF4(s16 x, s16 y, u8 a2, s16 a3)
{
    struct Sprite *sprite = gSprites + CreateSprite(&gSpriteTemplate_83ED42C, x, y, 13);
    sprite->oam.priority = 2;
    sprite->data[0] = a2;
    sprite->data[1] = a3;
    sprite->data[2] = a3 * 10;
    sprite->data[3] = -1;
}

/*static */void sub_810506C(struct Sprite *sprite)
{
    u16 tag = sSlotMachine->coins;
    if (sprite->data[0])
        tag = sSlotMachine->payout;
    if (sprite->data[3] != tag)
    {
        sprite->data[3] = tag;
        tag %= (u16)sprite->data[2];
        tag /= (u16)sprite->data[1];
        tag += 7;
        sprite->sheetTileStart = GetSpriteTileStartByTag(tag);
        SetSpriteSheetFrameTileNum(sprite);
    }
}

static void sub_81050C4(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED444, 0x58, 0x48, 15);
    gSprites[spriteId].oam.priority = 3;
    SetSubspriteTables(gSprites + spriteId, gSubspriteTables_83ED704);
}

static void sub_8105100(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    if (sUnknown_0203AAE4 == NULL)
        sUnknown_0203AAE4 = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);

    sUnknown_0203AAE4[0].data = sUnknown_0203AAD8 + (0 * 0x800);
    sUnknown_0203AAE4[0].size = 0x800;
    sUnknown_0203AAE4[1].data = sUnknown_0203AAD8 + (1 * 0x800);
    sUnknown_0203AAE4[1].size = 0x800;
    sUnknown_0203AAE4[2].data = sUnknown_0203AAD8 + (2 * 0x800);
    sUnknown_0203AAE4[2].size = 0x800;
    sUnknown_0203AAE4[3].data = sUnknown_0203AAD8 + (3 * 0x800);
    sUnknown_0203AAE4[3].size = 0x800;
    sUnknown_0203AAE4[4].data = sUnknown_0203AAD8 + (4 * 0x800);
    sUnknown_0203AAE4[4].size = 0x800;

    spriteTemplate = gSpriteTemplate_83ED45C;
    spriteTemplate.images = sUnknown_0203AAE4;
    spriteId = CreateSprite(&spriteTemplate, 280, 80, 1);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    sSlotMachine->reelTimeSprite3F = spriteId;
}

static void sub_810514C(void)
{
    DestroySprite(gSprites + sSlotMachine->reelTimeSprite3F);
    if (sUnknown_0203AAE4 != NULL)
        FREE_AND_SET_NULL(sUnknown_0203AAE4);
}

/*static */void sub_8105170(struct Sprite *sprite)
{
    sprite->pos2.y = sprite->pos2.x = 0;
    if (sprite->animNum == 4)
    {
        sprite->pos2.y = sprite->pos2.x = 8;
        if ((sprite->animCmdIndex != 0 && sprite->animDelayCounter != 0) || (sprite->animCmdIndex == 0 && sprite->animDelayCounter == 0))
            sprite->pos2.y = -8;
    }
}

static void sub_81051C0(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sUnknown_0203AAE8 == NULL)
        sUnknown_0203AAE8 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sUnknown_0203AAE8[0].data = sUnknown_0203AAD8 + 0x2800;
    sUnknown_0203AAE8[0].size = 0x300;
    spriteTemplate = gSpriteTemplate_83ED474;
    spriteTemplate.images = sUnknown_0203AAE8;
    spriteId = CreateSprite(&spriteTemplate, 368, 52, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED73C);
    sSlotMachine->unk49[0] = spriteId;

    if (sUnknown_0203AAEC == NULL)
        sUnknown_0203AAEC = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sUnknown_0203AAEC[0].data = sUnknown_0203AAD8 + 0x2800 + 0x300;
    sUnknown_0203AAEC[0].size = 0x500;
    spriteTemplate = gSpriteTemplate_83ED48C;
    spriteTemplate.images = sUnknown_0203AAEC;
    spriteId = CreateSprite(&spriteTemplate, 368, 84, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED75C);
    sSlotMachine->unk49[1] = spriteId;
}

static void sub_8105284_(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sUnknown_0203AAF0 == NULL)
        sUnknown_0203AAF0 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sUnknown_0203AAF0[0].data = sUnknown_0203AAD8 + 0x3000;
    sUnknown_0203AAF0[0].size = 0x600;
    spriteTemplate = gSpriteTemplate_83ED4A4;
    spriteTemplate.images = sUnknown_0203AAF0;
    spriteId = CreateSprite(&spriteTemplate, 0xa8 - gSpriteCoordOffsetX, 0x50, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, gSubspriteTables_83ED78C);
    sSlotMachine->unk42 = spriteId;
}

static void sub_81052EC(void)
{
    u8 i;
    s16 r5;
    for (i = 0, r5 = 0; i < 3; i++, r5 += 20)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4BC, 0x170, 0, 10);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[7] = r5;
        sSlotMachine->unk4B[i] = spriteId;
    }
}

/*static */void sub_810535C(struct Sprite *sprite)
{
    s16 r0 = (u16)(sSlotMachine->reeltimePixelOffset + sprite->data[7]);
    r0 %= 40;
    sprite->pos1.y = r0 + 59;
    StartSpriteAnimIfDifferent(sprite, GetNearbyReelTimeTag(r0 / 20));
}

static void sub_81053A0(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4D4, 0x170, 0x64, 9);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7B4);
    sSlotMachine->unk4E[0] = spriteId;

    spriteId = CreateSprite(&gSpriteTemplate_83ED4D4, 0x120, 0x68, 4);
    sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7B4);
    sSlotMachine->unk4E[1] = spriteId;
}

static void sub_810545C(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED4EC, 0x170, 0x4c, 11);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, gSubspriteTables_83ED7D4);
    sSlotMachine->unk40 = spriteId;
}

static void sub_81054B8(void)
{
    u8 i;

    DestroySprite(&gSprites[sSlotMachine->unk40]);
    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk49[i]]);

    if (sUnknown_0203AAE8 != NULL)
        FREE_AND_SET_NULL(sUnknown_0203AAE8);
    if (sUnknown_0203AAEC != NULL)
        FREE_AND_SET_NULL(sUnknown_0203AAEC);

    for (i = 0; i < 3; i++)
        DestroySprite(&gSprites[sSlotMachine->unk4B[i]]);
}

static void sub_8105524(void)
{
    u8 i;

    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->unk4E[i]]);
}

static void sub_8105554(void)
{
    DestroySprite(&gSprites[sSlotMachine->unk42]);
    if (sUnknown_0203AAF0 != NULL)
        FREE_AND_SET_NULL(sUnknown_0203AAF0);
}

// TODO: check if this is true
static void CreateReelTimeSprites1(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED504, 0x98, 0x20, 5);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->hFlip = TRUE;
    sSlotMachine->reelTimeSprites1[0] = spriteId;
    sprite->data[0] = 8;
    sprite->data[1] = -1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;

    spriteId = CreateSprite(&gSpriteTemplate_83ED504, 0xb8, 0x20, 5);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sSlotMachine->reelTimeSprites1[1] = spriteId;
    sprite->data[1] = 1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;
}

/*static */void sub_810562C(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
    {
        sprite->data[0]--;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->pos2.x += sprite->data[1];
        sprite->pos2.y += sprite->data[2];
        if (++sprite->data[3] >= 8)
        {
            sprite->data[0] = sprite->data[7];
            sprite->data[3] = 0;
        }
    }
}

static void sub_8105688(s16 a0)
{
    gSprites[sSlotMachine->reelTimeSprites1[0]].data[7] = a0;
    gSprites[sSlotMachine->reelTimeSprites1[1]].data[7] = a0;
}

static void sub_81056C0(void)
{
    u8 i;

    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeSprites1[i]]);
}

static void CreateReelTimeSprite2(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED51C, 0x48, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].data[0] = 1;
    gSprites[spriteId].data[5] = 0;
    gSprites[spriteId].data[6] = 16;
    gSprites[spriteId].data[7] = 8;
    sSlotMachine->reelTimeSprites2[0] = spriteId;

    spriteId = CreateSprite(&gSpriteTemplate_83ED51C, 0x68, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].hFlip = TRUE;
    sSlotMachine->reelTimeSprites2[1] = spriteId;
}

/*static */void sub_8105784(struct Sprite *sprite)
{
    u8 sp[] = {16, 0};
    if (sprite->data[0] && --sprite->data[6] <= 0)
    {
        MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(7) << 4) + 0x103, sp[sprite->data[5]], sp[sprite->data[5]], sp[sprite->data[5]]);
        ++sprite->data[5];
        sprite->data[5] &= 1;
        sprite->data[6] = sprite->data[7];
    }
}

static void sub_81057E8(s16 a0)
{
    gSprites[sSlotMachine->reelTimeSprites2[0]].data[7] = a0;
}

static void sub_8105804(void)
{
    u8 i;
    MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(7) << 4) + 0x103, 0, 0, 0);
    for (i = 0; i < 2; i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeSprites2[i]]);
}

static void sub_8105854(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED534, 0xa8, 0x50, 6);
    gSprites[spriteId].oam.priority = 1;
    sSlotMachine->unk41 = spriteId;
}

/*static */void sub_8105894(struct Sprite *sprite)
{
    sprite->pos2.y = gSpriteCoordOffsetY;
}

static void sub_81058A0(void)
{
    DestroySprite(&gSprites[sSlotMachine->unk41]);
}

static void sub_81058C4(void)
{
    u8 i;
    u16 sp[] = {0x0, 0x40, 0x80, 0xC0};
    for (i = 0; i < 4; i++)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_83ED54C, 0x50 - gSpriteCoordOffsetX, 0x44, 0);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = sp[i];
        sSlotMachine->unk54[i] = spriteId;
    }
}

/*static */void sub_810594C(struct Sprite *sprite)
{
    sprite->data[0] -= 2;
    sprite->data[0] &= 0xff;
    sprite->pos2.x = Cos(sprite->data[0], 20);
    sprite->pos2.y = Sin(sprite->data[0], 6);
    sprite->subpriority = 0;
    if (sprite->data[0] >= 0x80)
    {
        sprite->subpriority = 2;
    }
    if (++sprite->data[1] >= 16)
    {
        sprite->hFlip ^= 1;
        sprite->data[1] = 0;
    }
}

static void sub_81059B8(void)
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        DestroySprite(&gSprites[sSlotMachine->unk54[i]]);
    }
}

static void sub_81059E8(void)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED564, 0xa8, 0x3c, 8);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sSlotMachine->unk43 = spriteId;
}

/*static */void sub_8105A38(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
    }
    else if (sprite->data[0] == 1)
    {
        sprite->invisible ^= 1;
        if (++sprite->data[2] >= 24)
        {
            sprite->data[0]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        sprite->invisible = TRUE;
        if (++sprite->data[2] >= 16)
            sprite->data[7] = 1;
    }
    sprite->data[1] &= 0xff;
    sprite->data[1] += 16;
    sprite->pos2.y -= (sprite->data[1] >> 8);
}

static u8 sub_8105ACC(void)
{
    return gSprites[sSlotMachine->unk43].data[7];
}

static void sub_8105AEC(void)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->unk43];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

static u8 sub_8105B1C(s16 x, s16 y)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_83ED6CC, x, y, 12);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 2;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    return spriteId;
}

/*static */void sub_8105B70(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        sprite->data[7] = 1;
}

static void sub_8105B88(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

static u8 sub_8105BB4(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2)
{
    return sub_8105BF8(templateIdx, gUnknown_083ECF0C[cbAndCoordsIdx], gUnknown_083ECE7E[cbAndCoordsIdx][0], gUnknown_083ECE7E[cbAndCoordsIdx][1], a2);
}

static u8 sub_8105BF8(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 a4)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    spriteTemplate = *gUnknown_083EDB5C[templateIdx];
    spriteTemplate.images = gUnknown_03001188[templateIdx];
    spriteId = CreateSprite(&spriteTemplate, x, y, 16);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 3;
    sprite->callback = callback;
    sprite->data[6] = a4;
    sprite->data[7] = 1;
    if (gUnknown_083EDBC4[templateIdx])
        SetSubspriteTables(sprite, gUnknown_083EDBC4[templateIdx]);
    return spriteId;
}

static void sub_8105C64(struct Sprite *sprite)
{
    sprite->data[7] = 0;
}

static void sub_8105C6C(struct Sprite *sprite)
{
    s16 sp0[] = {4, -4, 4, -4};
    s16 sp8[] = {4, 4, -4, -4};

    if (sprite->data[1]++ >= 16)
    {
        sprite->subspriteTableNum ^= 1;
        sprite->data[1] = 0;
    }
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    if (sprite->subspriteTableNum != 0)
    {
        sprite->pos2.x = sp0[sprite->data[6]];
        sprite->pos2.y = sp8[sprite->data[6]];
    }
}

static void sub_8105CF0(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sub_8105C6C(sprite);
}

static void sub_8105D08(struct Sprite *sprite)
{
    sprite->vFlip = TRUE;
    sub_8105C6C(sprite);
}

static void sub_8105D20(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sprite->vFlip = TRUE;
    sub_8105C6C(sprite);
}

static void sub_8105D3C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 2:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0x110)
            sprite->data[0]++;
        break;
    case 3:
        sprite->data[7] = 0;
        break;
    }
}

static void sub_8105DA4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos1.x -= 4;
        if (sprite->pos1.x <= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 2:
        sprite->pos1.x -= 4;
        if (sprite->pos1.x <= 0x90)
            sprite->data[0]++;
        break;
    case 3:
        sprite->data[7] = 0;
        break;
    }
}

static void sub_8105E08(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnim(sprite, sSlotMachine->fairRollsLeft - 1);
        sprite->data[0]++;
        // fallthrough
    case 1:
        if (++sprite->data[1] >= 4)
        {
            sprite->data[0]++;
            sprite->data[1] = 0;
        }
        break;
    case 2:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xd0)
        {
            sprite->pos1.x = 0xd0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] > 90)
            sprite->data[0]++;
        break;
    case 4:
        sprite->pos1.x += 4;
        if (sprite->pos1.x >= 0xf8)
            sprite->data[0]++;
        break;
    case 5:
        sprite->data[7] = 0;
        break;
    }
}

static void sub_8105EB4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->animPaused = TRUE;
        sprite->data[0]++;
        // fallthrough
    case 1:
        sprite->pos1.y += 8;
        if (sprite->pos1.y >= 0x70)
        {
            sprite->pos1.y = 0x70;
            sprite->data[1] = 16;
            sprite->data[0]++;
        }
        break;
    case 2:
        if (sprite->data[2] == 0)
        {
            sprite->pos1.y -= sprite->data[1];
            sprite->data[1] = -sprite->data[1];
            if (++sprite->data[3] >= 2)
            {
                sprite->data[1] >>= 2;
                sprite->data[3] = 0;
                if (sprite->data[1] == 0)
                {
                    sprite->data[0]++;
                    sprite->data[7] = 0;
                    sprite->animPaused = FALSE;
                }
            }
        }
        sprite->data[2]++;
        sprite->data[2] &= 0x07;
        break;
    }
}

static void sub_8105F54(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 8)
            sprite->data[0]++;
        break;
    case 1:
        sprite->pos1.y += 2;
        if (sprite->pos1.y >= 0x30)
        {
            sprite->pos1.y = 0x30;
            sprite->data[0]++;
            sprite->data[7] = 0;
        }
        break;
    }
}

static void sub_8105F9C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->invisible = TRUE;
        if (++sprite->data[1] > 0x20)
        {
            sprite->data[0]++;
            sprite->data[1] = 5;
            sprite->oam.mosaic = TRUE;
            sprite->invisible = FALSE;
            StartSpriteAnim(sprite, 1);
            SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->data[1] << 4) | sprite->data[1]) << 8);
        }
        break;
    case 1:
        sprite->data[1] -= (sprite->data[2] >> 8);
        if (sprite->data[1] < 0)
            sprite->data[1] = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->data[1] << 4) | sprite->data[1]) << 8);
        sprite->data[2] &= 0xff;
        sprite->data[2] += 0x80;
        if (sprite->data[1] == 0)
        {
            sprite->data[0]++;
            sprite->data[7] = 0;
            sprite->oam.mosaic = FALSE;
            StartSpriteAnim(sprite, 0);
        }
        break;
    }
}

static void sub_8106058(struct Sprite *sprite)
{
    if (sprite->data[1] < 3)
    {
        LoadPalette(gUnknown_083EDE10[sprite->data[1]], (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
        if (++sprite->data[2] >= 4)
        {
            sprite->data[1]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        LoadPalette(gUnknown_083EDE10[sprite->data[1]], (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
        if (++sprite->data[2] >= 25)
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
    }
    StartSpriteAnimIfDifferent(sprite, 1);
    sprite->data[7] = 0;
}

static void sub_81060FC(struct Sprite *sprite)
{
    s16 sp00[] = {0, -40, 0, 0, 48, 0, 24, 0};
    s16 sp10[] = {-32, 0, -32, -48, 0, -48, 0, -48};
    s16 sp20[] = {16, 12, 16, 0, 0, 4, 8, 8};

    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.x = sp00[sprite->data[6]];
        sprite->pos2.y = sp10[sprite->data[6]];
        sprite->data[1] = sp20[sprite->data[6]];
        sprite->data[0]++;
        // fallthrough
    case 1:
        if (sprite->data[1]-- == 0)
            sprite->data[0]++;
        break;
    case 2:
        if (sprite->pos2.x > 0)
            sprite->pos2.x -= 4;
        else if (sprite->pos2.x < 0)
            sprite->pos2.x += 4;

        if (sprite->pos2.y > 0)
            sprite->pos2.y -= 4;
        else if (sprite->pos2.y < 0)
            sprite->pos2.y += 4;

        if (sprite->pos2.x == 0 && sprite->pos2.y == 0)
            sprite->data[0]++;
        break;
    }
}

static void sub_81061C8(struct Sprite *sprite)
{
    s16 sp0[] = {160, 192, 224, 104, 80, 64, 48, 24};

    if (sprite->data[0] == 0)
    {
        sprite->data[0]++;
        sprite->data[1] = 12;
    }
    sprite->pos2.x = Cos(sp0[sprite->data[6]], sprite->data[1]);
    sprite->pos2.y = Sin(sp0[sprite->data[6]], sprite->data[1]);
    if (sprite->data[1] != 0)
        sprite->data[1]--;
}

static void sub_8106230(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
        case 0:
            sSlotMachine->winIn = 0x2f;
            sSlotMachine->winOut = 0x3f;
            sSlotMachine->win0v = 0x2088;
            sprite->invisible = TRUE;
            sprite->data[0]++;
            // fallthrough
        case 1:
            sprite->data[1] += 2;
            sprite->data[2] = sprite->data[1] + 0xb0;
            sprite->data[3] = 0xf0 - sprite->data[1];
            if (sprite->data[2] > 0xd0)
                sprite->data[2] = 0xd0;
            if (sprite->data[3] < 0xd0)
                sprite->data[3] = 0xd0;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->data[1] > 0x33)
            {
                sprite->data[0]++;
                sSlotMachine->winIn = 0x3f;
            }
            break;
        case 2:
            if (sSlotMachine->bet == 0)
                break;
            sub_8104D30(5, SpriteCallbackDummy, 0xd0, 0x74, 0);
            sSlotMachine->win0h = 0xc0e0;
            sSlotMachine->win0v = 0x6880;
            sSlotMachine->winIn = 0x2f;
            sprite->data[0]++;
            sprite->data[1] = 0;
            // fallthrough
        case 3:
            sprite->data[1] += 2;
            sprite->data[2] = sprite->data[1] + 0xc0;
            sprite->data[3] = 0xe0 - sprite->data[1];
            if (sprite->data[2] > 0xd0)
                sprite->data[2] = 0xd0;
            if (sprite->data[3] < 0xd0)
                sprite->data[3] = 0xd0;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->data[1] > 0x0f)
            {
                sprite->data[0]++;
                sSlotMachine->winIn = 0x3f;
            }
            break;
    }
}

static void nullsub_70(void)
{
}

static void sub_8106364(void)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
}

static void sub_8106370(void)
{
    LoadPalette(gUnknown_083EDE20, (IndexOfSpritePaletteTag(6) << 4) + 0x100, 0x20);
}

static void sub_810639C(void)
{
    sSlotMachine->win0h = 0xf0;
    sSlotMachine->win0v = 0xa0;
    sSlotMachine->winIn = 0x3f;
    sSlotMachine->winOut = 0x3f;
}

static void sub_81063C0(void)
{
    u8 i;

    sub_8106404();
    sUnknown_0203AAD4 = Alloc(0x3200);
    LZDecompressWram(gSlotMachineReelTime_Gfx, sUnknown_0203AAD4);
    sUnknown_0203AAD8 = Alloc(0x3600);
    LZDecompressWram(gReelTimeGfx, sUnknown_0203AAD8);
    sUnknown_0203AB30 = AllocZeroed(sizeof(struct SpriteSheet) * 22);
    for (i = 0; i < 22; i++)
    {
        sUnknown_0203AB30[i].data = gSlotMachineSpriteSheets[i].data;
        sUnknown_0203AB30[i].size = gSlotMachineSpriteSheets[i].size;
        sUnknown_0203AB30[i].tag = gSlotMachineSpriteSheets[i].tag;
    }
    sUnknown_0203AB30[17].data = sUnknown_0203AAD4 + 0xA00;
    sUnknown_0203AB30[18].data = sUnknown_0203AAD4 + 0x1400;
    sUnknown_0203AB30[19].data = sUnknown_0203AAD4 + 0x1600;
    sUnknown_0203AB30[20].data = sUnknown_0203AAD4 + 0x1900;
    LoadSpriteSheets(sUnknown_0203AB30);
    LoadSpritePalettes(gSlotMachineSpritePalettes);
}

static void sub_8106404(void)
{
    u8 *dest;
    u8 i, j;

    sUnknown_0203AB2C = AllocZeroed(sizeof(struct SpriteSheet));
    sUnknown_0203AAE0 = AllocZeroed(0x2000);
    dest = sUnknown_0203AAE0;
    for (i = 0; i < 0x40; i++)
    {
        for (j = 0; j < 0x20; j++, dest++)
            *dest = gUnknown_083EDCDC[j];
    }
    sUnknown_0203AB2C->data = sUnknown_0203AAE0;
    sUnknown_0203AB2C->size = 0x800;
    sUnknown_0203AB2C->tag  = 0x11;
    LoadSpriteSheet(sUnknown_0203AB2C);
}

extern const u32 gSlotMachineMenu_Gfx[];
extern const u16 gSlotMachineMenu_Tilemap[];
extern const u16 gUnknown_08DCEC70[];
extern const u16 gSlotMachineMenu_Pal[];

static void sub_8106448(void)
{
    sUnknown_0203AAC8 = Alloc(0x2200);
    LZDecompressWram(gSlotMachineMenu_Gfx, sUnknown_0203AAC8);
    LoadBgTiles(2, sUnknown_0203AAC8, 0x2200, 0);
    LoadPalette(gSlotMachineMenu_Pal, 0, 160);
    LoadPalette(gPalette_83EDE24, 208, 32);
}

static void sub_81064B8(void)
{
    sub_812F968();
    LoadSlotMachineWheelOverlay();
}

static void sub_812F968(void)
{
    LoadBgTilemap(2, gSlotMachineMenu_Tilemap, 0x500, 0);
}

static void LoadSlotMachineWheelOverlay(void)
{
    s16 x, y, dx;

    for (x = 4; x < 18; x += 5)
    {
        for (dx = 0; dx < 4; dx++)
        {
            LoadBgTilemap(3, sUnknown_0203AAD0,     2, x + dx + 5  * 32);
            LoadBgTilemap(3, sUnknown_0203AAD0 + 1, 2, x + dx + 13 * 32);
            LoadBgTilemap(3, sUnknown_0203AAD0 + 2, 2, x + dx + 6  * 32);
            LoadBgTilemap(3, sUnknown_0203AAD0 + 3, 2, x + dx + 12 * 32);
        }

        LoadBgTilemap(3, sUnknown_0203AAD0 + 4, 2, x + 6 * 32);
        LoadBgTilemap(3, sUnknown_0203AAD0 + 5, 2, x + 12 * 32);

        for (y = 7; y <= 11; y++)
            LoadBgTilemap(3, sUnknown_0203AAD0 + 6, 2, x + y * 32);
    }
}

static void sub_81065A8(s16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    sUnknown_0203AADC[0] = arg1;
    sUnknown_0203AADC[1] = arg2;
    sUnknown_0203AADC[2] = arg3;
    sUnknown_0203AADC[3] = arg4;

    LoadBgTilemap(2, sUnknown_0203AADC,     2, 15 * 32 + arg0);
    LoadBgTilemap(2, sUnknown_0203AADC + 1, 2, 15 * 32 + 1 + arg0);
    LoadBgTilemap(2, sUnknown_0203AADC + 2, 2, 16 * 32 + arg0);
    LoadBgTilemap(2, sUnknown_0203AADC + 3, 2, 16 * 32 + 1 + arg0);
}

static void sub_81065DC(void)
{
    LoadBgTilemap(2, gUnknown_08DCEC70, 0x500, 0);
    HideBg(3);
}

static void SlotMachineSetup_9_0(void)
{
    gUnknown_03001188[0]  = sUnknown_0203AAF4;
    gUnknown_03001188[1]  = sUnknown_0203AAF8;
    gUnknown_03001188[2]  = sUnknown_0203AAFC;
    gUnknown_03001188[3]  = sUnknown_0203AB04;
    gUnknown_03001188[4]  = sUnknown_0203AB08;
    gUnknown_03001188[5]  = sUnknown_0203AB18;
    gUnknown_03001188[6]  = sUnknown_0203AB1C;
    gUnknown_03001188[7]  = sUnknown_0203AB20;
    gUnknown_03001188[8]  = sUnknown_0203AB24;
    gUnknown_03001188[9]  = sUnknown_0203AB28;
    gUnknown_03001188[10] = sUnknown_0203AB00;
    gUnknown_03001188[11] = sUnknown_0203AB00;
    gUnknown_03001188[12] = sUnknown_0203AB00;
    gUnknown_03001188[13] = sUnknown_0203AB00;
    gUnknown_03001188[14] = sUnknown_0203AB0C;
    gUnknown_03001188[15] = sUnknown_0203AB0C;
    gUnknown_03001188[16] = sUnknown_0203AB0C;
    gUnknown_03001188[17] = sUnknown_0203AB0C;
    gUnknown_03001188[18] = sUnknown_0203AB0C;
    gUnknown_03001188[19] = sUnknown_0203AB10;
    gUnknown_03001188[20] = sUnknown_0203AB10;
    gUnknown_03001188[21] = sUnknown_0203AB10;
    gUnknown_03001188[22] = sUnknown_0203AB14;
    gUnknown_03001188[23] = sUnknown_0203AB14;
    gUnknown_03001188[24] = sUnknown_0203AB14;
    gUnknown_03001188[25] = NULL;
}

static void SlotMachineSetup_8_0(void)
{
    sUnknown_0203AAF4 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AAF4[0].data = sUnknown_0203AAD4;
    sUnknown_0203AAF4[0].size = 0x600;

    sUnknown_0203AAF8 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AAF8[0].data = sUnknown_0203AAD4 + 0x600;
    sUnknown_0203AAF8[0].size = 0x200;

    sUnknown_0203AAFC = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AAFC[0].data = sUnknown_0203AAD4 + 0x800;
    sUnknown_0203AAFC[0].size = 0x200;

    sUnknown_0203AB00 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB00[0].data = sUnknown_0203AAD4 + 0xA00;
    sUnknown_0203AB00[0].size = 0x200;

    sUnknown_0203AB04 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB04[0].data = sUnknown_0203AAD4 + 0xC00;
    sUnknown_0203AB04[0].size = 0x300;

    sUnknown_0203AB08 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB08[0].data = sUnknown_0203AAD4 + 0x1000;
    sUnknown_0203AB08[0].size = 0x400;

    sUnknown_0203AB0C = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB0C[0].data = sUnknown_0203AAD4 + 0x1400;
    sUnknown_0203AB0C[0].size = 0x200;

    sUnknown_0203AB10 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB10[0].data = sUnknown_0203AAD4 + 0x1600;
    sUnknown_0203AB10[0].size = 0x300;

    sUnknown_0203AB14 = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB14[0].data = sUnknown_0203AAD4 + 0x1900;
    sUnknown_0203AB14[0].size = 0x300;

    sUnknown_0203AB18 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sUnknown_0203AB18[0].data = sUnknown_0203AAD4 + 0x1C00;
    sUnknown_0203AB18[0].size = 0x200;
    sUnknown_0203AB18[1].data = sUnknown_0203AAD4 + 0x1E00;
    sUnknown_0203AB18[1].size = 0x200;

    sUnknown_0203AB1C = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sUnknown_0203AB1C[0].data = sUnknown_0203AAD4 + 0x2000;
    sUnknown_0203AB1C[0].size = 640;

    sUnknown_0203AB20 = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);
    sUnknown_0203AB20[0].data = sUnknown_0203AAD4 + 0x2280;
    sUnknown_0203AB20[0].size = 0x80;
    sUnknown_0203AB20[1].data = sUnknown_0203AAD4 + 0x2300;
    sUnknown_0203AB20[1].size = 0x80;
    sUnknown_0203AB20[2].data = sUnknown_0203AAD4 + 0x2380;
    sUnknown_0203AB20[2].size = 0x80;
    sUnknown_0203AB20[3].data = sUnknown_0203AAD4 + 0x2400;
    sUnknown_0203AB20[3].size = 0x80;
    sUnknown_0203AB20[4].data = sUnknown_0203AAD4 + 0x2480;
    sUnknown_0203AB20[4].size = 0x80;

    sUnknown_0203AB24 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sUnknown_0203AB24[0].data = sUnknown_0203AAD4 + 0x2600;
    sUnknown_0203AB24[0].size = 0x480;
    sUnknown_0203AB24[1].data = sUnknown_0203AAD4 + 10880;
    sUnknown_0203AB24[1].size = 0x480;

    sUnknown_0203AB28 = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sUnknown_0203AB28[0].data = sUnknown_0203AAD4 + 0x2F00;
    sUnknown_0203AB28[0].size = 0x180;
    sUnknown_0203AB28[1].data = sUnknown_0203AAD4 + 0x3080;
    sUnknown_0203AB28[1].size = 0x180;
}

const u8 gReelSymbols[][REEL_NUM_TAGS] =
{
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY
    },
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_CHERRY
    },
    {
        SLOT_MACHINE_TAG_7_RED,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_7_BLUE,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_AZURILL,
        SLOT_MACHINE_TAG_POWER,
        SLOT_MACHINE_TAG_REPLAY,
        SLOT_MACHINE_TAG_LOTAD,
        SLOT_MACHINE_TAG_CHERRY
    },
};

const u8 gReelTimeTags[] = {
    1, 0, 5, 4, 3, 2
};

const s16 gInitialReelPositions[][2] = {
    {0,  6},
    {0, 10},
    {0,  2}
};

const u8 gLuckyRoundProbabilities[][3] = {
    {1, 1, 12},
    {1, 1, 14},
    {2, 2, 14},
    {2, 2, 14},
    {2, 3, 16},
    {3, 3, 16}
};

const u8 gLuckyFlagProbabilities_Top3[][6] = {
    {25, 25, 30, 40, 40, 50},
    {25, 25, 30, 30, 35, 35},
    {25, 25, 30, 25, 25, 30}
};

const u8 gLuckyFlagProbabilities_NotTop3[][6] = {
    {20, 25, 25, 20, 25, 25},
    {12, 15, 15, 18, 19, 22},
    {25, 25, 25, 30, 30, 40},
    {25, 25, 20, 20, 15, 15},
    {40, 40, 35, 35, 40, 40}
};

const u8 gReeltimeProbabilities_UnluckyGame[][17] = {
    {243, 243, 243,  80,  80,  80,  80,  40,  40,  40,  40,  40,  40,   5,   5,   5,   5},
    {  5,   5,   5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100,   5},
    {  4,   4,   4,  20,  20,  20,  20,  80,  80,  80,  80,  80,  80, 100, 100, 100,  40},
    {  2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  45,  45,  45, 100},
    {  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   5,   5,   5, 100},
    {  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   6}
};

const u8 gReelTimeProbabilities_LuckyGame[][17] = {
    { 243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160,  70,  70,  70,   5},
    {   5,   5,   5,  25,  25,  25,  25,   5,   5,   5,   5,   5,   5,   2,   2,   2,   6},
    {   4,   4,   4,  25,  25,  25,  25,  30,  30,  30,  30,  30,  30,  40,  40,  40,  35},
    {   2,   2,   2,   3,   3,   3,   3,  30,  30,  30,  30,  30,  30, 100, 100, 100,  50},
    {   1,   1,   1,   2,   2,   2,   2,  30,  30,  30,  30,  30,  30,  40,  40,  40, 100},
    {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   4,  60}
};

const u16 gProbabilityTable_SkipToReeltimeAction14[] = {
    128, 175, 200, 225, 256
};

const u16 gReelIncrementTable[][2] = {
    {10,  5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35}
};

const u16 gReelTimeBonusIncrementTable[] = {
    0, 5, 10, 15, 20
};

// tentative name
const u8 gBiasTags[] = {
  SLOT_MACHINE_TAG_REPLAY, SLOT_MACHINE_TAG_CHERRY, SLOT_MACHINE_TAG_LOTAD, SLOT_MACHINE_TAG_AZURILL, SLOT_MACHINE_TAG_POWER, SLOT_MACHINE_TAG_7_RED, SLOT_MACHINE_TAG_7_RED, SLOT_MACHINE_TAG_7_RED
};

const u16 gLuckyFlagSettings_Top3[] = {
    LUCKY_BIAS_777, LUCKY_BIAS_REELTIME, LUCKY_BIAS_MIXED_777
};

const u16 gLuckyFlagSettings_NotTop3[] = {
    LUCKY_BIAS_POWER, LUCKY_BIAS_AZURILL, LUCKY_BIAS_LOTAD, LUCKY_BIAS_CHERRY, LUCKY_BIAS_REPLAY
};

const u8 gSym2Match[] = {
    SLOT_MACHINE_MATCHED_777_RED,
    SLOT_MACHINE_MATCHED_777_BLUE,
    SLOT_MACHINE_MATCHED_AZURILL,
    SLOT_MACHINE_MATCHED_LOTAD,
    SLOT_MACHINE_MATCHED_1CHERRY,
    SLOT_MACHINE_MATCHED_POWER,
    SLOT_MACHINE_MATCHED_REPLAY
};

const u16 gSlotMatchFlags[] = {
    1 << SLOT_MACHINE_MATCHED_1CHERRY,
    1 << SLOT_MACHINE_MATCHED_2CHERRY,
    1 << SLOT_MACHINE_MATCHED_REPLAY,
    1 << SLOT_MACHINE_MATCHED_LOTAD,
    1 << SLOT_MACHINE_MATCHED_AZURILL,
    1 << SLOT_MACHINE_MATCHED_POWER,
    1 << SLOT_MACHINE_MATCHED_777_MIXED,
    1 << SLOT_MACHINE_MATCHED_777_RED,
    1 << SLOT_MACHINE_MATCHED_777_BLUE
};

const u16 gSlotPayouts[] = {
    2, 4, 0, 6, 12, 3, 90, 300, 300
};

const s16 gUnknown_083ECE7E[][2] = {
    { 0xd0, 0x38},
    { 0xb8, 0x00},
    { 0xc8, 0x08},
    { 0xd8, 0x10},
    { 0xe8, 0x18},
    { 0xd0, 0x48},
    { 0xd0, 0x08},
    { 0xd0, 0x40},
    { 0xd0, 0x38},
    { 0xc0, 0x58},
    { 0xe0, 0x58},
    { 0xc0, 0x78},
    { 0xe0, 0x78},
    { 0x90, 0x38},
    {0x110, 0x58},
    { 0xa8, 0x70},
    { 0xd0, 0x54},
    { 0xd0, 0x70},
    { 0xbc, 0x34},
    { 0xd0, 0x34},
    { 0xe4, 0x34},
    { 0xb8, 0x48},
    { 0xc4, 0x48},
    { 0xd0, 0x48},
    { 0xdc, 0x48},
    { 0xe8, 0x48},
    { 0xbc, 0x34},
    { 0xd0, 0x34},
    { 0xe4, 0x34},
    { 0xb8, 0x48},
    { 0xc4, 0x48},
    { 0xd0, 0x48},
    { 0xdc, 0x48},
    { 0xe8, 0x48},
    { 0x00, 0x00}
};

const SpriteCallback gUnknown_083ECF0C[] = {
    sub_8105C64,
    sub_8105F54,
    sub_8105F54,
    sub_8105F54,
    sub_8105F54,
    sub_8105F9C,
    sub_8105EB4,
    sub_8105C64,
    sub_8105C64,
    sub_8105C6C,
    sub_8105CF0,
    sub_8105D08,
    sub_8105D20,
    sub_8105D3C,
    sub_8105DA4,
    sub_8105E08,
    sub_8105C64,
    sub_8106058,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81060FC,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_81061C8,
    sub_8106230
};

const struct UnkStruct1 Unknown_83ECF98[] = {
    {25, 34, 0},
    {2, 0, 0},
    {9, 16, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFA8[] = {
    {10, 1, 0},
    {11, 2, 0},
    {12, 3, 0},
    {13, 4, 0},
    {5, 5, 0},
    {8, 6, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFC4[] = {
    {3, 7, 0},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFD0[] = {
    {4, 8, 0},
    {6, 9, 0},
    {6, 10, 1},
    {6, 11, 2},
    {6, 12, 3},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFE8[] = {
    {0, 13, 0},
    {1, 14, 0},
    {7, 15, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ECFF8[] = {
    {19, 26, 0},
    {20, 27, 1},
    {21, 28, 2},
    {14, 29, 3},
    {15, 30, 4},
    {16, 31, 5},
    {17, 32, 6},
    {18, 33, 7},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 Unknown_83ED020[] = {
    {22, 18, 0},
    {23, 19, 1},
    {24, 20, 2},
    {14, 21, 3},
    {15, 22, 4},
    {16, 23, 5},
    {17, 24, 6},
    {18, 25, 7},
    {8, 17, 0},
    {255, 0, 0}
};

const struct UnkStruct1 *const gUnknown_083ED048[] = {
    Unknown_83ECF98,
    Unknown_83ECFA8,
    Unknown_83ECFC4,
    Unknown_83ECFD0,
    Unknown_83ECFE8,
    Unknown_83ED020,
    Unknown_83ECFF8
};

void (*const gUnknown_083ED064[])(void) = {
    sub_810639C,
    sub_8106364,
    sub_8106370,
    nullsub_70,
    nullsub_70,
    sub_8106370,
    sub_8106370
};
