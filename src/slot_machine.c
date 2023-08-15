#include "global.h"
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
#include "strings.h"
#include "tv.h"
#include "text_window.h"
#include "main_menu.h"
#include "bg.h"
#include "window.h"
#include "constants/coins.h"
#include "constants/rgb.h"
#include "constants/slot_machine.h"
#include "constants/songs.h"

#define SLOTMACHINE_GFX_TILES 233
#define MAX_BET 3

#define SYMBOLS_PER_REEL   21
#define REEL_SYMBOL_HEIGHT 24
#define REEL_HEIGHT        (SYMBOLS_PER_REEL * REEL_SYMBOL_HEIGHT)

#define REELTIME_SYMBOLS       6
#define REELTIME_SYMBOL_HEIGHT 20
#define REELTIME_REEL_HEIGHT   (REELTIME_SYMBOLS * REELTIME_SYMBOL_HEIGHT)

// There are three categories of biases: 7's, ReelTime, Regular
//  - 7's: BIAS_STRAIGHT_7, BIAS_MIXED_7
//  - ReelTime: BIAS_REELTIME
//  - Regular: everything else
//
// The 7's and ReelTime biases can be grouped together as 'Special' biases.
//
// There can be at most two biases at a time. If there are two, one bias will be
// ReelTime and the other will be one of the Regular biases.
//
// A new bias is drawn every round, except during ReelTime. Bias towards 7's
// persists across rounds until you match 7's. All other biases are reset after
// the round.
#define BIAS_REPLAY     (1 << 0)
#define BIAS_CHERRY     (1 << 1)
#define BIAS_LOTAD      (1 << 2)
#define BIAS_AZURILL    (1 << 3)
#define BIAS_POWER      (1 << 4)
#define BIAS_REELTIME   (1 << 5)
#define BIAS_MIXED_7    (1 << 6)
#define BIAS_STRAIGHT_7 (1 << 7)

#define BIAS_7       (BIAS_STRAIGHT_7 | BIAS_MIXED_7)
#define BIAS_SPECIAL (BIAS_7 | BIAS_REELTIME)
#define BIAS_REGULAR (BIAS_REPLAY | BIAS_CHERRY | BIAS_LOATAD | BIAS_AZURILL | BIAS_POWER)

// The slot machine will try to manipulate the outcome by adding up to 4 extra
// turns to the reel after you press stop.
//
// The only exception is when it is stopping the third reel and it has decided
// you will lose. In this case, it adds as many turns as necessary to prevent a
// match.
#define MAX_EXTRA_TURNS 4

enum {
    SYMBOL_7_RED,
    SYMBOL_7_BLUE,
    SYMBOL_AZURILL,
    SYMBOL_LOTAD,
    SYMBOL_CHERRY,
    SYMBOL_POWER,
    SYMBOL_REPLAY,
};

enum
{
    GFXTAG_7_RED,
    GFXTAG_7_BLUE,
    GFXTAG_AZURILL,
    GFXTAG_LOTAD,
    GFXTAG_CHERRY,
    GFXTAG_POWER,
    GFXTAG_REPLAY,
    GFXTAG_NUM_0,
    GFXTAG_NUM_1,
    GFXTAG_NUM_2,
    GFXTAG_NUM_3,
    GFXTAG_NUM_4,
    GFXTAG_NUM_5,
    GFXTAG_NUM_6,
    GFXTAG_NUM_7,
    GFXTAG_NUM_8,
    GFXTAG_NUM_9,
    GFXTAG_REEL_BG,
    GFXTAG_STOP,
    GFXTAG_BONUS,
    GFXTAG_BIG,
    GFXTAG_REG,
};

#define GFXTAG_SYMBOLS_START (GFXTAG_7_RED)
#define GFXTAG_NUMBERS_START (GFXTAG_NUM_0)

#define REEL_NORMAL_SPEED  8
#define REEL_HALF_SPEED    4
#define REEL_QUARTER_SPEED 2

enum {
    PALTAG_REEL,
    PALTAG_REEL_TIME_PIKACHU,
    PALTAG_REEL_TIME_MISC,
    PALTAG_REEL_TIME_MACHINE,
    PALTAG_MISC,
    PALTAG_EXPLOSION,
    PALTAG_DIG_DISPLAY,
    PALTAG_PIKA_AURA,
};

enum {
    MATCH_CHERRY,        // Cherry in center of first reel
    MATCH_TOPBOT_CHERRY, // Cherry in top/bottom of first reel
    MATCH_REPLAY,
    MATCH_LOTAD,
    MATCH_AZURILL,
    MATCH_POWER,
    MATCH_MIXED_7,       // First two 7's are same color; last is other color
    MATCH_RED_7,
    MATCH_BLUE_7,
    MATCH_NONE,
};

enum {
    MATCH_MIDDLE_ROW,
    MATCH_TOP_ROW,
    MATCH_BOTTOM_ROW,
    MATCH_NWSE_DIAG,
    MATCH_NESW_DIAG,
    NUM_MATCH_LINES,
};

enum {
    LEFT_REEL,
    MIDDLE_REEL,
    RIGHT_REEL,
    NUM_REELS,
};

enum {
    SLOTTASK_UNFADE,
    SLOTTASK_WAIT_FADE,
    SLOTTASK_READY_NEW_SPIN,
    SLOTTASK_READY_NEW_RT_SPIN,
    SLOTTASK_ASK_INSERT_BET,
    SLOTTASK_BET_INPUT,
    SLOTTASK_MSG_NEED_3_COINS,
    SLOTTASK_WAIT_MSG_NEED_3_COINS,
    SLOTTASK_WAIT_INFO_BOX,
    SLOTTASK_START_SPIN,
    SLOTTASK_START_RT_SPIN,
    SLOTTASK_RESET_BIAS_FAILURE,
    SLOTTASK_WAIT_REEL_STOP,
    SLOTTASK_WAIT_ALL_REELS_STOP,
    SLOTTASK_CHECK_MATCHES,
    SLOTTASK_WAIT_PAYOUT,
    SLOTTASK_END_PAYOUT,
    SLOTTASK_MATCHED_POWER,
    SLOTTASK_WAIT_RT_ANIM,
    SLOTTASK_RESET_BET_TILES,
    SLOTTASK_NO_MATCHES,
    SLOTTASK_ASK_QUIT,
    SLOTTASK_HANDLE_QUIT_INPUT,
    SLOTTASK_MSG_MAX_COINS,
    SLOTTASK_WAIT_MSG_MAX_COINS,
    SLOTTASK_MSG_NO_MORE_COINS,
    SLOTTASK_WAIT_MSG_NO_MORE_COINS,
    SLOTTASK_END,
    SLOTTASK_FREE,
};
enum
{
    PAYOUT_TASK_INIT,
    PAYOUT_TASK_GIVE_PAYOUT,
    PAYOUT_TASK_FREE,
};

enum {
    REEL_TASK_STILL,
    REEL_TASK_SPIN,
    REEL_TASK_DECIDE_STOP,
    REEL_TASK_STOP_MOVE,
    REEL_TASK_STOP_SHAKE,
};

enum {
    PIKABOLT_TASK_IDLE,
    PIKABOLT_TASK_ADD_BOLT,
    PIKABOLT_TASK_WAIT_ANIM,
    PIKABOLT_TASK_CLEAR_ALL,
};

enum {
    RT_TASK_INIT,
    RT_TASK_WINDOW_ENTER,
    RT_TASK_WAIT_START_PIKA,
    RT_TASK_PIKA_SPEEDUP1,
    RT_TASK_PIKA_SPEEDUP2,
    RT_TASK_WAIT_REEL,
    RT_TASK_CHECK_EXPLODE,
    RT_TASK_LAND,
    RT_TASK_PIKA_REACT,
    RT_TASK_WAIT_CLEAR_POWER,
    RT_TASK_CLOSE_WINDOW_SUCCESS,
    RT_TASK_DESTROY_SPRITES,
    RT_TASK_SET_REEL_SPEED,
    RT_TASK_END_SUCCESS,
    RT_TASK_EXPLODE,
    RT_TASK_WAIT_EXPLODE,
    RT_TASK_WAIT_SMOKE,
    RT_TASK_CLOSE_WINDOW_FAILURE,
    RT_TASK_END_FAILURE,
};

#define DIG_SPRITE_DUMMY {255, 0, 0}

// Sprite template IDs for the digital display in the right panel
enum {
    DIG_SPRITE_REEL,
    DIG_SPRITE_TIME,
    DIG_SPRITE_INSERT,
    DIG_SPRITE_WIN,
    DIG_SPRITE_LOSE,
    DIG_SPRITE_A_BUTTON,
    DIG_SPRITE_SMOKE,
    DIG_SPRITE_NUMBER,
    DIG_SPRITE_POKE_BALL,
    DIG_SPRITE_D_PAD,
    DIG_SPRITE_STOP_S,
    DIG_SPRITE_STOP_T,
    DIG_SPRITE_STOP_O,
    DIG_SPRITE_STOP_P,
    DIG_SPRITE_BONUS_B,
    DIG_SPRITE_BONUS_O,
    DIG_SPRITE_BONUS_N,
    DIG_SPRITE_BONUS_U,
    DIG_SPRITE_BONUS_S,
    DIG_SPRITE_BIG_B,
    DIG_SPRITE_BIG_I,
    DIG_SPRITE_BIG_G,
    DIG_SPRITE_REG_R,
    DIG_SPRITE_REG_E,
    DIG_SPRITE_REG_G,
    DIG_SPRITE_EMPTY,
    NUM_DIG_DISPLAY_SPRITES
};

// IDs used by the digital display to set coords and callbacks for its sprites
enum {
    DIG_DISPINFO_INSERT,
    DIG_DISPINFO_STOP_S,
    DIG_DISPINFO_STOP_T,
    DIG_DISPINFO_STOP_O,
    DIG_DISPINFO_STOP_P,
    DIG_DISPINFO_A_BUTTON_STOP,
    DIG_DISPINFO_POKE_BALL_ROCKING,
    DIG_DISPINFO_WIN,
    DIG_DISPINFO_LOSE,
    DIG_DISPINFO_SMOKE_NW,
    DIG_DISPINFO_SMOKE_NE,
    DIG_DISPINFO_SMOKE_SW,
    DIG_DISPINFO_SMOKE_SE,
    DIG_DISPINFO_REEL,
    DIG_DISPINFO_TIME,
    DIG_DISPINFO_NUMBER,
    DIG_DISPINFO_DPAD,
    DIG_DISPINFO_POKE_BALL_SHINING,
    DIG_DISPINFO_REG_R,
    DIG_DISPINFO_REG_E,
    DIG_DISPINFO_REG_G,
    DIG_DISPINFO_REG_BONUS_B,
    DIG_DISPINFO_REG_BONUS_O,
    DIG_DISPINFO_REG_BONUS_N,
    DIG_DISPINFO_REG_BONUS_U,
    DIG_DISPINFO_REG_BONUS_S,
    DIG_DISPINFO_BIG_B,
    DIG_DISPINFO_BIG_I,
    DIG_DISPINFO_BIG_G,
    DIG_DISPINFO_BIG_BONUS_B,
    DIG_DISPINFO_BIG_BONUS_O,
    DIG_DISPINFO_BIG_BONUS_N,
    DIG_DISPINFO_BIG_BONUS_U,
    DIG_DISPINFO_BIG_BONUS_S,
    DIG_DISPINFO_A_BUTTON_START
};

// IDs for digital display "scenes", i.e. each of the screens it can show made up of sprites
enum {
    DIG_DISPLAY_INSERT_BET,
    DIG_DISPLAY_STOP_REEL,
    DIG_DISPLAY_WIN,
    DIG_DISPLAY_LOSE,
    DIG_DISPLAY_REEL_TIME,
    DIG_DISPLAY_BONUS_REG,
    DIG_DISPLAY_BONUS_BIG
};


// How ReelTime works
// ==================
// Entering ReelTime:
//  - If the bias you draw at the start of the round is BIAS_REELTIME, the
//    ReelTime lottery begins.
//  - At the start of the lottery, the game selects how many ReelTime spins you
//    will get, based on how many Power bolts you've collected and whether it
//    is a lucky game.
//  - The lottery machine rolls until it lands on the selected number. If it
//    selected 0 spins, the lottery machine will mostly likely explode before
//    landing on 0.
//  - If you win:
//     - You receive the selected number of ReelTime spins
//     - You lose all the Power bolts you've collected thus far
//     - The lottery window closes and ReelTime officially begins
//
// During ReelTime:
//  - You still have to pay coins for bets.
//  - The slot reels may spin slower than usual in ReelTime. The machine draws a
//    reel speed at the beginning of each ReelTime spin. The more coins you've
//    lost to the machine, and the more consecutive ReelTime spins you've done,
//    the higher your chances of getting a slower reel speed.
//  - In ReelTime, the reel stops exactly on your input. That is, it won't add
//    extra turns to manipulate the outcome.
//  - ReelTime ends early if you win red 7's or blue 7's.


// SlotMachine field explanations:
//
// luckyGame:
//   Determined at random when you start playing. Some events modify this:
//    - Blue 7 match: game becomes lucky
//    - Red 7 match: game becomes normal
//
//   Effectively, a lucky game inreases the odds of getting more ReelTime spins.
//   If the game is lucky, you have a slightly higher chance of matching Power
//   bolts (at the expense of Replays). This helps you fill your Power bolt
//   gauge faster.
//
//   During ReelTime, the more Power bolts you have, the greater your chances
//   of drawing more ReelTime spins. In a lucky game, you have greater odds of
//   drawing high yields (3+ RT spins). You also have greater odds of drawing 0
//   RT spins. But drawing 0 lets you keep all your Power bolts, allowing you to
//   fill your gauge further.
struct SlotMachine
{
    /*0x00*/ u8 state;
    /*0x01*/ u8 machineId;
    /*0x02*/ u8 pikaPowerBolts;
    /*0x03*/ bool8 luckyGame;
    /*0x04*/ u8 machineBias;
    /*0x05*/ u8 reelTimeDraw;
    /*0x06*/ bool8 didNotFailBias;
    /*0x07*/ u8 biasSymbol;
    /*0x08*/ u16 matches;
    /*0x0A*/ u8 reelTimeSpinsLeft;
    /*0x0B*/ u8 reelTimeSpinsUsed;
    /*0x0C*/ s16 coins;
    /*0x0E*/ s16 payout;
    /*0x10*/ s16 netCoinLoss; // never negative
    /*0x12*/ s16 bet;
    /*0x14*/ s16 reeltimePixelOffset;
    /*0x16*/ s16 reeltimePosition;
    /*0x18*/ s16 currentReel;
    /*0x1A*/ s16 reelSpeed;
    /*0x1C*/ s16 reelPixelOffsets[NUM_REELS];
    /*0x22*/ u16 reelShockOffsets[NUM_REELS];
    /*0x28*/ s16 reelPositions[NUM_REELS];
    /*0x2E*/ s16 reelExtraTurns[NUM_REELS];
    /*0x34*/ s16 winnerRows[NUM_REELS];
    /*0x3A*/ u8 slotReelTasks[NUM_REELS];
    /*0x3D*/ u8 digDisplayTaskId;
    /*0x3E*/ u8 pikaPowerBoltTaskId;
    /*0x3F*/ u8 reelTimePikachuSpriteId;
    /*0x40*/ u8 reelTimeNumberGapSpriteId;
    /*0x41*/ u8 reelTimeExplosionSpriteId;
    /*0x42*/ u8 reelTimeBrokenMachineSpriteId;
    /*0x43*/ u8 reelTimeSmokeSpriteId;
    /*0x44*/ u8 flashMatchLineSpriteIds[NUM_MATCH_LINES];
    /*0x49*/ u8 reelTimeMachineSpriteIds[2];
    /*0x49*/ u8 reelTimeNumberSpriteIds[3];
    /*0x4E*/ u8 reelTimeShadowSpriteIds[2];
    /*0x50*/ u8 reelTimeBoltSpriteIds[2];
    /*0x52*/ u8 reelTimePikachuAuraSpriteIds[2];
    /*0x54*/ u8 reelTimeDuckSpriteIds[4];
    /*0x58*/ u16 win0h;
    /*0x5a*/ u16 win0v;
    /*0x5c*/ u16 winIn;
    /*0x5e*/ u16 winOut;
    /*0x60*/ u16 backupMapMusic;
    /*0x64*/ MainCallback prevMainCb;
};

struct DigitalDisplaySprite
{
    /*0x00*/ u8 spriteTemplateId;
    /*0x01*/ u8 dispInfoId;
    /*0x02*/ s16 spriteId;
};

static void CB2_SlotMachineSetup(void);
static void CB2_SlotMachine(void);
static void PlaySlotMachine_Internal(u8, MainCallback);
static void SlotMachineDummyTask(u8);
static void SlotMachineSetup_InitBgsWindows(void);
static void SlotMachineSetup_InitVRAM(void);
static void SlotMachineSetup_InitOAM(void);
static void SlotMachineSetup_InitGpuRegs(void);
static void InitSlotMachine(void);
static void SlotMachineSetup_InitPalsSpritesTasks(void);
static void SlotMachineSetup_InitTilemaps(void);
static void SlotMachineSetup_LoadGfxAndTilemaps(void);
static void SlotMachineSetup_InitVBlank(void);
static void AllocDigitalDisplayGfx(void);
static void SetDigitalDisplayImagePtrs(void);
static void CreateSlotMachineSprites(void);
static void CreateGameplayTasks(void);
static void CreateSlotMachineTasks(void);
static void DestroyDigitalDisplayScene(void);
static void Task_SlotMachine(u8);
static bool8 SlotTask_UnfadeScreen(struct Task *);
static bool8 SlotTask_WaitUnfade(struct Task *);
static bool8 SlotTask_ReadyNewSpin(struct Task *);
static bool8 SlotTask_ReadyNewReelTimeSpin(struct Task *);
static bool8 SlotTask_AskInsertBet(struct Task *);
static bool8 SlotTask_HandleBetInput(struct Task *);
static bool8 SlotTask_PrintMsg_Need3Coins(struct Task *);
static bool8 SlotTask_WaitMsg_Need3Coins(struct Task *);
static bool8 SlotTask_WaitInfoBox(struct Task *);
static bool8 SlotTask_StartSpin(struct Task *);
static bool8 SlotTask_StartReelTimeSpin(struct Task *);
static bool8 SlotTask_ResetBiasFailure(struct Task *);
static bool8 SlotTask_WaitReelStop(struct Task *);
static bool8 SlotTask_WaitAllReelsStop(struct Task *);
static bool8 SlotTask_CheckMatches(struct Task *);
static bool8 SlotTask_WaitPayout(struct Task *);
static bool8 SlotTask_EndPayout(struct Task *);
static bool8 SlotTask_MatchedPower(struct Task *);
static bool8 SlotTask_WaitReelTimeAnim(struct Task *);
static bool8 SlotTask_ResetBetTiles(struct Task *);
static bool8 SlotTask_NoMatches(struct Task *);
static bool8 SlotTask_AskQuit(struct Task *);
static bool8 SlotTask_HandleQuitInput(struct Task *);
static bool8 SlotTask_PrintMsg_MaxCoins(struct Task *);
static bool8 SlotTask_WaitMsg_MaxCoins(struct Task *);
static bool8 SlotTask_PrintMsg_NoMoreCoins(struct Task *);
static bool8 SlotTask_WaitMsg_NoMoreCoins(struct Task *);
static bool8 SlotTask_EndGame(struct Task *);
static bool8 SlotTask_FreeDataStructures(struct Task *);
static void DrawMachineBias(void);
static void ResetBiasFailure(void);
static bool8 ShouldTrySpecialBias(void);
static u8 TrySelectBias_Special(void);
static u16 ReelTimeSpeed(void);
static u8 TrySelectBias_Regular(void);
static void CheckMatch(void);
static void CheckMatch_CenterRow(void);
static void CheckMatch_TopAndBottom(void);
static void CheckMatch_Diagonals(void);
static u8 GetMatchFromSymbols(u8, u8, u8);
static void AwardPayout(void);
static void Task_Payout(u8);
static bool8 IsFinalTask_Task_Payout(void);
static bool8 PayoutTask_Init(struct Task *);
static bool8 PayoutTask_GivePayout(struct Task *);
static bool8 PayoutTask_Free(struct Task *);
static u8 GetSymbolAtRest(u8, s16);
static void CreateReelTasks(void);
static void SpinSlotReel(u8);
static void StopSlotReel(u8);
static bool8 IsSlotReelMoving(u8);
static void Task_Reel(u8);
static bool8 ReelTask_StayStill(struct Task *);
static bool8 ReelTask_Spin(struct Task *);
static bool8 ReelTask_DecideStop(struct Task *);
static bool8 ReelTask_MoveToStop(struct Task *);
static bool8 ReelTask_ShakingStop(struct Task *);
static bool8 DecideStop_Bias_Reel1(void);
static bool8 DecideStop_Bias_Reel1_Bet1(u8, u8);
static bool8 DecideStop_Bias_Reel1_Bet2or3(u8, u8);
static bool8 DecideStop_Bias_Reel2(void);
static bool8 DecideStop_Bias_Reel2_Bet1or2(void);
static bool8 DecideStop_Bias_Reel2_Bet3(void);
static bool8 DecideStop_Bias_Reel3(void);
static bool8 DecideStop_Bias_Reel3_Bet1or2(u8);
static bool8 DecideStop_Bias_Reel3_Bet3(u8);
static void DecideStop_NoBias_Reel1(void);
static void DecideStop_NoBias_Reel2(void);
static void DecideStop_NoBias_Reel2_Bet1(void);
static void DecideStop_NoBias_Reel2_Bet2(void);
static void DecideStop_NoBias_Reel2_Bet3(void);
static void DecideStop_NoBias_Reel3(void);
static void DecideStop_NoBias_Reel3_Bet1(void);
static void DecideStop_NoBias_Reel3_Bet2(void);
static void DecideStop_NoBias_Reel3_Bet3(void);
static void PressStopReelButton(u8);
static void Task_PressStopReelButton(u8);
static void LightenBetTiles(u8);
static void StopReelButton_Press(struct Task *, u8);
static void StopReelButton_Wait(struct Task *, u8);
static void StopReelButton_Unpress(struct Task *, u8);
static void DarkenBetTiles(u8);
static void CreateInvisibleFlashMatchLineSprites(void);
static void FlashMatchLine(u8);
static bool8 IsMatchLineDoneFlashingBeforePayout(void);
static bool8 TryStopMatchLinesFlashing(void);
static bool8 TryStopMatchLineFlashing(u8);
static void SpriteCB_FlashMatchingLines(struct Sprite *);
static void FlashSlotMachineLights(void);
static bool8 TryStopSlotMachineLights(void);
static void Task_FlashSlotMachineLights(u8);
static void CreatePikaPowerBoltTask(void);
static void AddPikaPowerBolt(u8);
static bool8 IsPikaPowerBoltAnimating(void);
static void Task_CreatePikaPowerBolt(u8);
static void PikaPowerBolt_Idle(struct Task *);
static void PikaPowerBolt_AddBolt(struct Task *);
static void PikaPowerBolt_WaitAnim(struct Task *);
static void PikaPowerBolt_ClearAll(struct Task *);
static void ResetPikaPowerBoltTask(struct Task *);
static void LoadPikaPowerMeter(u8 );
static void BeginReelTime(void);
static bool8 IsReelTimeTaskDone(void);
static void Task_ReelTime(u8 );
static void ReelTime_Init(struct Task *);
static void ReelTime_WindowEnter(struct Task *);
static void ReelTime_WaitStartPikachu(struct Task *);
static void ReelTime_PikachuSpeedUp1(struct Task *);
static void ReelTime_PikachuSpeedUp2(struct Task *);
static void ReelTime_WaitReel(struct Task *);
static void ReelTime_CheckExplode(struct Task *);
static void ReelTime_LandOnOutcome(struct Task *);
static void ReelTime_PikachuReact(struct Task *);
static void ReelTime_WaitClearPikaPower(struct Task *);
static void ReelTime_CloseWindow(struct Task *);
static void ReelTime_DestroySprites(struct Task *);
static void ReelTime_SetReelSpeed(struct Task *);
static void ReelTime_EndSuccess(struct Task *);
static void ReelTime_ExplodeMachine(struct Task *);
static void ReelTime_WaitExplode(struct Task *);
static void ReelTime_WaitSmoke(struct Task *);
static void ReelTime_EndFailure(struct Task *);
static void LoadReelTimeWindowTilemap(s16, s16);
static void ClearReelTimeWindowTilemap(s16);
static void OpenInfoBox(u8);
static bool8 IsInfoBoxClosed(void);
static void Task_InfoBox(u8 );
static void InfoBox_FadeIn(struct Task *);
static void InfoBox_WaitFade(struct Task *);
static void InfoBox_DrawWindow(struct Task *);
static void InfoBox_WaitInput(struct Task *);
static void InfoBox_AddText(struct Task *);
static void InfoBox_LoadPikaPowerMeter(struct Task *);
static void InfoBox_LoadSlotMachineTilemap(struct Task *);
static void InfoBox_CreateDigitalDisplay(struct Task *);
static void InfoBox_FreeTask(struct Task *);
static void CreateDigitalDisplayTask(void);
static void CreateDigitalDisplayScene(u8 );
static bool8 IsDigitalDisplayAnimFinished(void);
static void DigitalDisplay_Idle(struct Task *);
static void Task_DigitalDisplay(u8);
static void CreateReelSymbolSprites(void);
static void CreateCreditPayoutNumberSprites(void);
static void CreateCoinNumberSprite(s16, s16, u8, s16);
static void CreateReelBackgroundSprite(void);
static void CreateReelTimePikachuSprite(void);
static void DestroyReelTimePikachuSprite(void);
static void CreateReelTimeMachineSprites(void);
static void CreateBrokenReelTimeMachineSprite(void);
static void CreateReelTimeNumberSprites(void);
static void CreateReelTimeShadowSprites(void);
static void CreateReelTimeNumberGapSprite(void);
static void DestroyReelTimeMachineSprites(void);
static void DestroyReelTimeShadowSprites(void);
static void DestroyBrokenReelTimeMachineSprite(void);
static void CreateReelTimeBoltSprites(void);
static void SetReelTimeBoltDelay(s16);
static void DestroyReelTimeBoltSprites(void);
static void CreateReelTimePikachuAuraSprites(void);
static void SetReelTimePikachuAuraFlashDelay(s16);
static void DestroyReelTimePikachuAuraSprites(void);
static void CreateReelTimeExplosionSprite(void);
static void DestroyReelTimeExplosionSprite(void);
static void CreateReelTimeDuckSprites(void);
static void DestroyReelTimeDuckSprites(void);
static void CreateReelTimeSmokeSprite(void);
static bool8 IsReelTimeSmokeAnimFinished(void);
static void DestroyReelTimeSmokeSprite(void);
static u8 CreatePikaPowerBoltSprite(s16, s16);
static void DestroyPikaPowerBoltSprite(u8);
static u8 CreateDigitalDisplaySprite(u8, void (*callback)(struct Sprite *), s16, s16, s16);
static void LoadSlotMachineGfx(void);
static void LoadReelBackground(void);
static void LoadMenuGfx(void);
static void LoadMenuAndReelOverlayTilemaps(void);
static void SetReelButtonTilemap(s16, u16, u16, u16, u16);
static void LoadInfoBoxTilemap(void);
static void LoadSlotMachineMenuTilemap(void);
static void LoadSlotMachineReelOverlay(void);
static u8 CreateStdDigitalDisplaySprite(u8, u8, s16);
static void SpriteCB_DigitalDisplay_Static(struct Sprite *);
static void SpriteCB_DigitalDisplay_Stop(struct Sprite *);
static void SpriteCB_DigitalDisplay_AButtonStop(struct Sprite *);
static void SpriteCB_DigitalDisplay_PokeballRocking(struct Sprite *);
static void SpriteCB_DigitalDisplay_Smoke(struct Sprite *);
static void SpriteCB_DigitalDisplay_SmokeNE(struct Sprite *);
static void SpriteCB_DigitalDisplay_SmokeSW(struct Sprite *);
static void SpriteCB_DigitalDisplay_SmokeSE(struct Sprite *);
static void SpriteCB_DigitalDisplay_Reel(struct Sprite *);
static void SpriteCB_DigitalDisplay_Time(struct Sprite *);
static void SpriteCB_DigitalDisplay_ReelTimeNumber(struct Sprite *);
static void SpriteCB_DigitalDisplay_PokeballShining(struct Sprite *);
static void SpriteCB_DigitalDisplay_RegBonus(struct Sprite *);
static void SpriteCB_DigitalDisplay_BigBonus(struct Sprite *);
static void SpriteCB_DigitalDisplay_AButtonStart(struct Sprite *);
static void EndDigitalDisplayScene_InsertBet(void);
static void EndDigitalDisplayScene_StopReel(void);
static void EndDigitalDisplayScene_Win(void);
static void EndDigitalDisplayScene_Dummy(void);
static void SpriteCB_ReelSymbol(struct Sprite *);
static void SpriteCB_CoinNumber(struct Sprite *);
static void SpriteCB_ReelTimePikachu(struct Sprite *);
static void SpriteCB_ReelTimeNumbers(struct Sprite *);
static void SpriteCB_ReelTimeBolt(struct Sprite *);
static void SpriteCB_ReelTimePikachuAura(struct Sprite *);
static void SpriteCB_ReelTimeExplosion(struct Sprite *);
static void SpriteCB_ReelTimeDuck(struct Sprite *);
static void SpriteCB_ReelTimeSmoke(struct Sprite *);
static void SpriteCB_PikaPowerBolt(struct Sprite *);

// Ewram variables
static EWRAM_DATA u16 *sMenuGfx = NULL;
static EWRAM_DATA u16 *sSelectedPikaPowerTile = NULL;
static EWRAM_DATA u16 *sReelOverlay_Tilemap = NULL;
static EWRAM_DATA u8 *sDigitalDisplayGfxPtr = NULL;
static EWRAM_DATA u8 *sReelTimeGfxPtr = NULL;
static EWRAM_DATA u16 *sReelButtonPress_Tilemap = NULL;
static EWRAM_DATA u8 *sReelBackground_Gfx = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_ReelTimePikachu = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_ReelTimeMachineAntennae = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_ReelTimeMachine = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_BrokenReelTimeMachine = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Reel = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Time = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Insert = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Stop = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Win = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Lose = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Bonus = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Big = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Reg = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_AButton = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Smoke = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Number = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_Pokeball = NULL;
static EWRAM_DATA struct SpriteFrameImage *sImageTable_DigitalDisplay_DPad = NULL;
static EWRAM_DATA struct SpriteSheet *sReelBackgroundSpriteSheet = NULL;
static EWRAM_DATA struct SpriteSheet *sSlotMachineSpritesheetsPtr = NULL;
static EWRAM_DATA struct SlotMachine *sSlotMachine = NULL;

// IWRAM bss
static struct SpriteFrameImage *sImageTables_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];

// Const rom data.
static const struct DigitalDisplaySprite *const sDigitalDisplayScenes[];
static const u16 sUnkPalette[];
static const u8 sSpecialDrawOdds[NUM_SLOT_MACHINE_IDS][MAX_BET];
static const u8 sBiasSymbols[];
static const u16 sBiasesSpecial[3];
static const u16 sBiasesRegular[5];
static const s16 sDigitalDisplay_SpriteCoords[][2];
static const SpriteCallback sDigitalDisplay_SpriteCallbacks[];
static const struct SpriteTemplate *const sSpriteTemplates_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];
static const struct SubspriteTable *const sSubspriteTables_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];
static const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion;
static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura;
static const u16 sReelTimeExplodeProbability[];
static const u16 *const sPokeballShiningPalTable[];
static const u16 sReelTimeSpeed_Probabilities[][2];
static const u16 sQuarterSpeed_ProbabilityBoost[];
static const u16 sSlotMatchFlags[];
static const u16 sSlotPayouts[];
static const u8 *const sReelBackground_Tilemap;
static const u32 sReelTimeGfx[];
static const struct SpriteSheet sSlotMachineSpriteSheets[22];
static const struct SpritePalette sSlotMachineSpritePalettes[];
static const u16 *const sDigitalDisplay_Pal;
static const s16 sInitialReelPositions[NUM_REELS][2];
static const u8 sBiasProbabilities_Special[][NUM_SLOT_MACHINE_IDS];
static const u8 sBiasProbabilities_Regular[][NUM_SLOT_MACHINE_IDS];
static const u8 sReelTimeProbabilities_NormalGame[][17];
static const u8 sReelTimeProbabilities_LuckyGame[][17];
static const u8 sSymbolToMatch[];
static const u8 sReelTimeSymbols[];
static const u8 sReelSymbols[NUM_REELS][SYMBOLS_PER_REEL];
static const u16 *const sLitMatchLinePalTable[NUM_MATCH_LINES];
static const u16 *const sDarkMatchLinePalTable[NUM_MATCH_LINES];
static const u8 sMatchLinePalOffsets[NUM_MATCH_LINES];
static const u8 sBetToMatchLineIds[MAX_BET][2];
static const u8 sMatchLinesPerBet[MAX_BET];
static const u16 *const sFlashingLightsPalTable[];
static const u16 *const sSlotMachineMenu_Pal;
static const u16 sReelTimeWindow_Tilemap[];
static const u16 sEmptyTilemap[];
static void (*const sDigitalDisplaySceneExitCallbacks[])(void);
static const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumberGap;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers;
static const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine;
static const struct SpriteTemplate sSpriteTemplate_ReelBackground;
static const struct SpriteTemplate sSpriteTemplate_CoinNumber;
static const struct SpriteTemplate sSpriteTemplate_ReelSymbol;
static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachu;
static const struct SubspriteTable sSubspriteTable_ReelTimeNumberGap[];
static const struct SubspriteTable sSubspriteTable_ReelTimeShadow[];
static const struct SubspriteTable sSubspriteTable_BrokenReelTimeMachine[];
static const struct SubspriteTable sSubspriteTable_ReelTimeMachineAntennae[];
static const struct SubspriteTable sSubspriteTable_ReelTimeMachine[];
static const struct SubspriteTable sSubspriteTable_ReelBackground[];

static const struct BgTemplate sBgTemplates[] =
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

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sWindowTemplate_InfoBox =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 20,
    .height = 13,
    .paletteNum = 13,
    .baseBlock = 1
};

static const u8 sColors_ReeltimeHelp[] = {TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static bool8 (*const sSlotTasks[])(struct Task *task) =
{
    [SLOTTASK_UNFADE]                 = SlotTask_UnfadeScreen,
    [SLOTTASK_WAIT_FADE]              = SlotTask_WaitUnfade,
    [SLOTTASK_READY_NEW_SPIN]         = SlotTask_ReadyNewSpin,
    [SLOTTASK_READY_NEW_RT_SPIN]      = SlotTask_ReadyNewReelTimeSpin,
    [SLOTTASK_ASK_INSERT_BET]         = SlotTask_AskInsertBet,
    [SLOTTASK_BET_INPUT]              = SlotTask_HandleBetInput,
    [SLOTTASK_MSG_NEED_3_COINS]       = SlotTask_PrintMsg_Need3Coins,
    [SLOTTASK_WAIT_MSG_NEED_3_COINS]  = SlotTask_WaitMsg_Need3Coins,
    [SLOTTASK_WAIT_INFO_BOX]          = SlotTask_WaitInfoBox,
    [SLOTTASK_START_SPIN]             = SlotTask_StartSpin,
    [SLOTTASK_START_RT_SPIN]          = SlotTask_StartReelTimeSpin,
    [SLOTTASK_RESET_BIAS_FAILURE]     = SlotTask_ResetBiasFailure,
    [SLOTTASK_WAIT_REEL_STOP]         = SlotTask_WaitReelStop,
    [SLOTTASK_WAIT_ALL_REELS_STOP]    = SlotTask_WaitAllReelsStop,
    [SLOTTASK_CHECK_MATCHES]          = SlotTask_CheckMatches,
    [SLOTTASK_WAIT_PAYOUT]            = SlotTask_WaitPayout,
    [SLOTTASK_END_PAYOUT]             = SlotTask_EndPayout,
    [SLOTTASK_MATCHED_POWER]          = SlotTask_MatchedPower,
    [SLOTTASK_WAIT_RT_ANIM]           = SlotTask_WaitReelTimeAnim,
    [SLOTTASK_RESET_BET_TILES]        = SlotTask_ResetBetTiles,
    [SLOTTASK_NO_MATCHES]             = SlotTask_NoMatches,
    [SLOTTASK_ASK_QUIT]               = SlotTask_AskQuit,
    [SLOTTASK_HANDLE_QUIT_INPUT]      = SlotTask_HandleQuitInput,
    [SLOTTASK_MSG_MAX_COINS]          = SlotTask_PrintMsg_MaxCoins,
    [SLOTTASK_WAIT_MSG_MAX_COINS]     = SlotTask_WaitMsg_MaxCoins,
    [SLOTTASK_MSG_NO_MORE_COINS]      = SlotTask_PrintMsg_NoMoreCoins,
    [SLOTTASK_WAIT_MSG_NO_MORE_COINS] = SlotTask_WaitMsg_NoMoreCoins,
    [SLOTTASK_END]                    = SlotTask_EndGame,
    [SLOTTASK_FREE]                   = SlotTask_FreeDataStructures,
};

static bool8 (*const sPayoutTasks[])(struct Task *task) =
{
    [PAYOUT_TASK_INIT]        = PayoutTask_Init,
    [PAYOUT_TASK_GIVE_PAYOUT] = PayoutTask_GivePayout,
    [PAYOUT_TASK_FREE]        = PayoutTask_Free,
};

static bool8 (*const sReelTasks[])(struct Task *task) =
{
    [REEL_TASK_STILL]        = ReelTask_StayStill,
    [REEL_TASK_SPIN]         = ReelTask_Spin,
    [REEL_TASK_DECIDE_STOP]  = ReelTask_DecideStop,
    [REEL_TASK_STOP_MOVE]    = ReelTask_MoveToStop,
    [REEL_TASK_STOP_SHAKE] = ReelTask_ShakingStop,
};

// Returns true if it is possible to match the bias symbol in the reel.
//
// Modifies the winnerRows and reelExtraTurns to indicate how to match the bias
// symbol.
static bool8 (*const sDecideStop_Bias[NUM_REELS])(void) =
{
    DecideStop_Bias_Reel1,
    DecideStop_Bias_Reel2,
    DecideStop_Bias_Reel3,
};

// The player will always lose (barring a few rare circumstances that were not
// accounted for in implementation).
//
// Modifies the winnerRows and reelExtraTurns to indicate how to make the player
// lose.
static void (*const sDecideStop_NoBias[NUM_REELS])(void) =
{
    DecideStop_NoBias_Reel1,
    DecideStop_NoBias_Reel2,
    DecideStop_NoBias_Reel3,
};

// The magnitude of the shock depends on how many extra turns are added.
static const u16 sReelStopShocks[] = {2, 4, 4, 4, 8};

static bool8 (*const sDecideStop_Bias_Reel1_Bets[MAX_BET])(u8 sym1, u8 sym2) =
{
    DecideStop_Bias_Reel1_Bet1,
    DecideStop_Bias_Reel1_Bet2or3,
    DecideStop_Bias_Reel1_Bet2or3,
};

static bool8 (*const sDecideStop_Bias_Reel2_Bets[MAX_BET])(void) =
{
    DecideStop_Bias_Reel2_Bet1or2,
    DecideStop_Bias_Reel2_Bet1or2,
    DecideStop_Bias_Reel2_Bet3,
};

static bool8 (*const sDecideStop_Bias_Reel3_Bets[MAX_BET])(u8 biasSymbol) =
{
    DecideStop_Bias_Reel3_Bet1or2,
    DecideStop_Bias_Reel3_Bet1or2,
    DecideStop_Bias_Reel3_Bet3,
};

static void (*const sDecideStop_NoBias_Reel2_Bets[MAX_BET])(void) =
{
    DecideStop_NoBias_Reel2_Bet1,
    DecideStop_NoBias_Reel2_Bet2,
    DecideStop_NoBias_Reel2_Bet3,
};

static void (*const sDecideStop_NoBias_Reel3_Bets[MAX_BET])(void) =
{
    DecideStop_NoBias_Reel3_Bet1,
    DecideStop_NoBias_Reel3_Bet2,
    DecideStop_NoBias_Reel3_Bet3,
};

static void (*const sReelStopButtonTasks[])(struct Task *task, u8 taskId) =
{
    StopReelButton_Press,
    StopReelButton_Wait,
    StopReelButton_Unpress,
};

static const s16 sReelButtonOffsets[NUM_REELS] = {5, 10, 15};

static void (*const sPikaPowerBoltTasks[])(struct Task *task) =
{
    PikaPowerBolt_Idle,
    PikaPowerBolt_AddBolt,
    PikaPowerBolt_WaitAnim,
    PikaPowerBolt_ClearAll,
};

static const u16 sPikaPowerTileTable[][2] =
{
    {0x9e, 0x6e},
    {0x9f, 0x6f},
    {0xaf, 0x7f},
};

static void (*const sReelTimeTasks[])(struct Task *task) =
{
    [RT_TASK_INIT]                 = ReelTime_Init,
    [RT_TASK_WINDOW_ENTER]         = ReelTime_WindowEnter,
    [RT_TASK_WAIT_START_PIKA]      = ReelTime_WaitStartPikachu,
    [RT_TASK_PIKA_SPEEDUP1]        = ReelTime_PikachuSpeedUp1,
    [RT_TASK_PIKA_SPEEDUP2]        = ReelTime_PikachuSpeedUp2,
    [RT_TASK_WAIT_REEL]            = ReelTime_WaitReel,
    [RT_TASK_CHECK_EXPLODE]        = ReelTime_CheckExplode,
    [RT_TASK_LAND]                 = ReelTime_LandOnOutcome,
    [RT_TASK_PIKA_REACT]           = ReelTime_PikachuReact,
    [RT_TASK_WAIT_CLEAR_POWER]     = ReelTime_WaitClearPikaPower,
    [RT_TASK_CLOSE_WINDOW_SUCCESS] = ReelTime_CloseWindow,
    [RT_TASK_DESTROY_SPRITES]      = ReelTime_DestroySprites,
    [RT_TASK_SET_REEL_SPEED]       = ReelTime_SetReelSpeed,
    [RT_TASK_END_SUCCESS]          = ReelTime_EndSuccess,
    [RT_TASK_EXPLODE]              = ReelTime_ExplodeMachine,
    [RT_TASK_WAIT_EXPLODE]         = ReelTime_WaitExplode,
    [RT_TASK_WAIT_SMOKE]           = ReelTime_WaitSmoke,
    [RT_TASK_CLOSE_WINDOW_FAILURE] = ReelTime_CloseWindow,
    [RT_TASK_END_FAILURE]          = ReelTime_EndFailure,
};

static const u8 sReelTimePikachuAnimIds[] = {1, 1, 2, 2};
static const s16 sReelTimeBoltDelays[] = {64, 48, 24, 8};
static const s16 sPikachuAuraFlashDelays[] = {10, 8, 6, 4};

static void (*const sInfoBoxTasks[])(struct Task *task) =
{
    // Go to Info screen
    InfoBox_FadeIn,
    InfoBox_WaitFade,
    InfoBox_DrawWindow,
    InfoBox_WaitFade,
    InfoBox_AddText,
    InfoBox_WaitFade,
    // On Info screen
    InfoBox_WaitInput,
    // Exit Info screen
    InfoBox_WaitFade,
    InfoBox_LoadSlotMachineTilemap,
    InfoBox_WaitFade,
    InfoBox_CreateDigitalDisplay,
    InfoBox_WaitFade,
    InfoBox_LoadPikaPowerMeter,
    InfoBox_WaitFade,
    InfoBox_FreeTask,
};

// Just idles, digital display is handled by CreateDigitalDisplayScene and sprite callbacks
static void (*const sDigitalDisplayTasks[])(struct Task *task) =
{
    DigitalDisplay_Idle,
};

#define tState data[0]

static void Task_FadeToSlotMachine(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
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

void PlaySlotMachine(u8 machineId, MainCallback exitCallback)
{
    u8 taskId;

    sSlotMachine = AllocZeroed(sizeof(*sSlotMachine));
    PlaySlotMachine_Internal(machineId, exitCallback);
    taskId = CreateTask(Task_FadeToSlotMachine, 0);
    gTasks[taskId].tState = 0;
}

#undef tState

static void CB2_SlotMachineSetup(void)
{
    switch (gMain.state)
    {
        case 0:
            SlotMachineSetup_InitBgsWindows();
            InitSlotMachine();
            gMain.state++;
            break;
        case 1:
            SlotMachineSetup_InitVRAM();
            gMain.state++;
            break;
        case 2:
            SlotMachineSetup_InitOAM();
            SlotMachineSetup_InitGpuRegs();
            gMain.state++;
            break;
        case 3:
            SlotMachineSetup_InitPalsSpritesTasks();
            gMain.state++;
            break;
        case 4:
            SlotMachineSetup_InitTilemaps();
            gMain.state++;
            break;
        case 5:
            SlotMachineSetup_LoadGfxAndTilemaps();
            gMain.state++;
            break;
        case 6:
            SlotMachineSetup_InitVBlank();
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
            AllocDigitalDisplayGfx();
            gMain.state++;
            break;
        case 9:
            SetDigitalDisplayImagePtrs();
            gMain.state++;
            break;
        case 10:
            CreateSlotMachineSprites();
            CreateGameplayTasks();
            gMain.state++;
            break;
        case 11:
            SetMainCallback2(CB2_SlotMachine);
            break;
    }
}

static void CB2_SlotMachine(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SlotMachine_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_WIN0H, sSlotMachine->win0h);
    SetGpuReg(REG_OFFSET_WIN0V, sSlotMachine->win0v);
    SetGpuReg(REG_OFFSET_WININ, sSlotMachine->winIn);
    SetGpuReg(REG_OFFSET_WINOUT, sSlotMachine->winOut);
}

#define tMachineId    data[0]
#define tExitCallback data[1]

static void PlaySlotMachine_Internal(u8 machineId, MainCallback exitCallback)
{
    struct Task *task = &gTasks[CreateTask(SlotMachineDummyTask, 0xFF)];
    task->tMachineId = machineId;
    StoreWordInTwoHalfwords(&task->tExitCallback, (intptr_t)exitCallback);
}

// Extracts and assigns machineId and exit callback from task.
static void SlotMachine_InitFromTask(void)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(SlotMachineDummyTask)];
    sSlotMachine->machineId = task->tMachineId;
    LoadWordFromTwoHalfwords((u16 *)&task->tExitCallback, (u32 *)&sSlotMachine->prevMainCb);
}

static void SlotMachineDummyTask(u8 taskId)
{
}

#undef tMachineId
#undef tExitCallback

static void SlotMachineSetup_InitBgsWindows(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    CpuFill32(0, (void *)VRAM, VRAM_SIZE);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
}

static void SlotMachineSetup_InitVBlank(void)
{
    SetVBlankCallback(SlotMachine_VBlankCB);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
}

static void SlotMachineSetup_InitVRAM(void)
{
    DmaClearLarge16(3, (u16 *)(BG_VRAM), BG_VRAM_SIZE, 0x1000);
}

static void SlotMachineSetup_InitOAM(void)
{
    DmaClear16(3, (u16 *)OAM, OAM_SIZE);
}

static void SlotMachineSetup_InitGpuRegs(void)
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
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 8));
}

// Set up initial state of slot machine
static void InitSlotMachine(void)
{
    u8 i;

    SlotMachine_InitFromTask();
    sSlotMachine->state = SLOTTASK_UNFADE;
    sSlotMachine->pikaPowerBolts = 0;
    sSlotMachine->luckyGame = Random() & 1;
    sSlotMachine->machineBias = 0;
    sSlotMachine->matches = 0;
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reelTimeSpinsUsed = 0;
    sSlotMachine->coins = GetCoins();
    sSlotMachine->payout = 0;
    sSlotMachine->netCoinLoss = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currentReel = LEFT_REEL;
    sSlotMachine->reelSpeed = REEL_NORMAL_SPEED;
    sSlotMachine->win0h = DISPLAY_WIDTH;
    sSlotMachine->win0v = DISPLAY_HEIGHT;
    sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
    sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    sSlotMachine->backupMapMusic = GetCurrentMapMusic();

    for (i = 0; i < NUM_REELS; i++)
    {
        sSlotMachine->reelShockOffsets[i] = 0;
        sSlotMachine->reelPositions[i] = sInitialReelPositions[i][sSlotMachine->luckyGame] % SYMBOLS_PER_REEL;
        sSlotMachine->reelPixelOffsets[i] = REEL_HEIGHT - sSlotMachine->reelPositions[i] * REEL_SYMBOL_HEIGHT;
        sSlotMachine->reelPixelOffsets[i] %= REEL_HEIGHT;
    }
    AlertTVThatPlayerPlayedSlotMachine(GetCoins());
}

static void SlotMachineSetup_InitPalsSpritesTasks(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    gOamLimit = 0x80;
    FreeAllSpritePalettes();
    ResetTasks();
}

static void SlotMachineSetup_InitTilemaps(void)
{
    sSelectedPikaPowerTile = Alloc(8);
    sReelOverlay_Tilemap = AllocZeroed(14);
    sReelButtonPress_Tilemap = AllocZeroed(8);

    // several of these are 1 bit off from each other
    sReelOverlay_Tilemap[0] = 0x2051;
    sReelOverlay_Tilemap[1] = 0x2851;
    sReelOverlay_Tilemap[2] = 0x2061;
    sReelOverlay_Tilemap[3] = 0x2861;
    sReelOverlay_Tilemap[4] = 0x20BE;
    sReelOverlay_Tilemap[5] = 0x28BE;
    sReelOverlay_Tilemap[6] = 0x20BF;
}

static void SlotMachineSetup_LoadGfxAndTilemaps(void)
{
    LoadMenuGfx();
    LoadMenuAndReelOverlayTilemaps();
    LoadSlotMachineGfx();
    LoadMessageBoxGfx(0, 0x200, BG_PLTT_ID(15));
    LoadUserWindowBorderGfx(0, 0x214, BG_PLTT_ID(14));
    PutWindowTilemap(0);
}

static void CreateSlotMachineSprites(void)
{
    CreateReelSymbolSprites();
    CreateCreditPayoutNumberSprites();
    CreateInvisibleFlashMatchLineSprites();
    CreateReelBackgroundSprite();
}

static void CreateGameplayTasks(void)
{
    CreatePikaPowerBoltTask();
    CreateReelTasks();
    CreateDigitalDisplayTask();
    CreateSlotMachineTasks();
}

static void CreateSlotMachineTasks(void)
{
    Task_SlotMachine(CreateTask(Task_SlotMachine, 0));
}

static void Task_SlotMachine(u8 taskId)
{
    while (sSlotTasks[sSlotMachine->state](&gTasks[taskId]))
        ;
}

#define tTimer  data[0]
#define tTimer2 data[1]

// SLOTTASK_UNFADE
static bool8 SlotTask_UnfadeScreen(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    LoadPikaPowerMeter(sSlotMachine->pikaPowerBolts);
    sSlotMachine->state++; // SLOTTASK_WAIT_FADE
    return FALSE;
}

// SLOTTASK_WAIT_FADE
static bool8 SlotTask_WaitUnfade(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

// SLOTTASK_READY_NEW_SPIN
static bool8 SlotTask_ReadyNewSpin(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currentReel = LEFT_REEL;
    sSlotMachine->machineBias &= (BIAS_STRAIGHT_7 | BIAS_MIXED_7);
    sSlotMachine->state = SLOTTASK_ASK_INSERT_BET;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = SLOTTASK_MSG_NO_MORE_COINS;
    }
    else if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->state = SLOTTASK_READY_NEW_RT_SPIN;
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
    }
    return TRUE;
}

// SLOTTASK_READY_NEW_RT_SPIN
static bool8 SlotTask_ReadyNewReelTimeSpin(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
        sSlotMachine->state = SLOTTASK_ASK_INSERT_BET;
    return FALSE;
}

// SLOTTASK_ASK_INSERT_BET
static bool8 SlotTask_AskInsertBet(struct Task *task)
{
    CreateDigitalDisplayScene(DIG_DISPLAY_INSERT_BET);
    sSlotMachine->state = SLOTTASK_BET_INPUT;
    if (sSlotMachine->coins >= MAX_COINS)
        sSlotMachine->state = SLOTTASK_MSG_MAX_COINS;
    return TRUE;
}

// SLOTTASK_BET_INPUT
static bool8 SlotTask_HandleBetInput(struct Task *task)
{
    s16 i;

    if (JOY_NEW(SELECT_BUTTON))
    {
        OpenInfoBox(DIG_DISPLAY_INSERT_BET);
        sSlotMachine->state = SLOTTASK_WAIT_INFO_BOX;
    }
    // Try to bet the max amount
    else if (JOY_NEW(R_BUTTON))
    {
        if (sSlotMachine->coins - (MAX_BET - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < MAX_BET; i++)
                LightenBetTiles(i);
            sSlotMachine->coins -= (MAX_BET - sSlotMachine->bet);
            sSlotMachine->bet = MAX_BET;
            sSlotMachine->state = SLOTTASK_START_SPIN;
            PlaySE(SE_SHOP);
        }
        // Not enough coins
        else
        {
            sSlotMachine->state = SLOTTASK_MSG_NEED_3_COINS;
        }
    }
    else
    {
        // Increase bet
        if (JOY_NEW(DPAD_DOWN) && sSlotMachine->coins != 0)
        {
            PlaySE(SE_SHOP);
            LightenBetTiles(sSlotMachine->bet);
            sSlotMachine->coins--;
            sSlotMachine->bet++;
        }

        // Maxed bet or finished betting
        if (sSlotMachine->bet >= MAX_BET || (sSlotMachine->bet != 0 && JOY_NEW(A_BUTTON)))
            sSlotMachine->state = SLOTTASK_START_SPIN;

        // Quit prompt
        if (JOY_NEW(B_BUTTON))
            sSlotMachine->state = SLOTTASK_ASK_QUIT;
    }
    return FALSE;
}

// SLOTTASK_MSG_NEED_3_COINS
static bool8 SlotTask_PrintMsg_Need3Coins(struct Task *task)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_YouDontHaveThreeCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_NEED_3_COINS;
    return FALSE;
}

// SLOTTASK_WAIT_MSG_NEED_3_COINS
static bool8 SlotTask_WaitMsg_Need3Coins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

// SLOTTASK_WAIT_INFO_BOX
static bool8 SlotTask_WaitInfoBox(struct Task *task)
{
    if (IsInfoBoxClosed())
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    return FALSE;
}

// SLOTTASK_START_SPIN
static bool8 SlotTask_StartSpin(struct Task *task)
{
    DrawMachineBias();
    DestroyDigitalDisplayScene();

    SpinSlotReel(LEFT_REEL);
    SpinSlotReel(MIDDLE_REEL);
    SpinSlotReel(RIGHT_REEL);

    IncrementDailySlotsUses();

    task->tTimer = 0;
    if (sSlotMachine->machineBias & BIAS_REELTIME)
    {
        BeginReelTime();
        sSlotMachine->state = SLOTTASK_START_RT_SPIN;
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->state = SLOTTASK_RESET_BIAS_FAILURE;
    }
    sSlotMachine->reelSpeed = REEL_NORMAL_SPEED;
    if (sSlotMachine->reelTimeSpinsLeft)
        sSlotMachine->reelSpeed = ReelTimeSpeed();
    return FALSE;
}

// SLOTTASK_START_RT_SPIN
static bool8 SlotTask_StartReelTimeSpin(struct Task *task)
{
    if (IsReelTimeTaskDone())
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->machineBias &= ~BIAS_REELTIME;
        sSlotMachine->state = SLOTTASK_RESET_BIAS_FAILURE;
    }
    return FALSE;
}

// SLOTTASK_RESET_BIAS_FAILURE
static bool8 SlotTask_ResetBiasFailure(struct Task *task)
{
    if (++task->tTimer >= 30)
    {
        ResetBiasFailure();
        sSlotMachine->state = SLOTTASK_WAIT_REEL_STOP;
    }
    return FALSE;
}

// SLOTTASK_WAIT_REEL_STOP
static bool8 SlotTask_WaitReelStop(struct Task *task)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_CONTEST_PLACE);
        StopSlotReel(sSlotMachine->currentReel);
        PressStopReelButton(sSlotMachine->currentReel);
        sSlotMachine->state = SLOTTASK_WAIT_ALL_REELS_STOP;
    }
    return FALSE;
}

// SLOTTASK_WAIT_ALL_REELS_STOP
static bool8 SlotTask_WaitAllReelsStop(struct Task *task)
{
    if (!IsSlotReelMoving(sSlotMachine->currentReel))
    {
        sSlotMachine->currentReel++;
        sSlotMachine->state = SLOTTASK_WAIT_REEL_STOP;
        if (sSlotMachine->currentReel >= NUM_REELS)
        {
            sSlotMachine->state = SLOTTASK_CHECK_MATCHES;
        }
        return TRUE;
    }
    return FALSE;
}

// SLOTTASK_CHECK_MATCHES
static bool8 SlotTask_CheckMatches(struct Task *task)
{
    sSlotMachine->machineBias &= (BIAS_STRAIGHT_7 | BIAS_MIXED_7);
    CheckMatch();
    if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->reelTimeSpinsLeft--;
        sSlotMachine->reelTimeSpinsUsed++;
    }

    if (sSlotMachine->matches)
    {
        sSlotMachine->state = SLOTTASK_WAIT_PAYOUT;
        AwardPayout();
        FlashSlotMachineLights();
        if ((sSlotMachine->netCoinLoss -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->netCoinLoss = 0;
        }
        if (sSlotMachine->matches & ((1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_BIG);
        }
        else if (sSlotMachine->matches & (1 << MATCH_MIXED_7))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_REG);
        }
        else
        {
            PlayFanfare(MUS_SLOTS_WIN);
            CreateDigitalDisplayScene(DIG_DISPLAY_WIN);
        }

        if (sSlotMachine->matches & ((1 << MATCH_MIXED_7) | (1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
        {
            sSlotMachine->machineBias &= ~(BIAS_STRAIGHT_7 | BIAS_MIXED_7);
            if (sSlotMachine->matches & ((1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
            {
                // ReelTime ends if it was ongoing
                sSlotMachine->reelTimeSpinsLeft = 0;
                sSlotMachine->reelTimeSpinsUsed = 0;
                sSlotMachine->luckyGame = FALSE;
                if (sSlotMachine->matches & (1 << MATCH_BLUE_7))
                    sSlotMachine->luckyGame = TRUE;
            }
        }
        if (sSlotMachine->matches & (1 << MATCH_POWER) && sSlotMachine->pikaPowerBolts < 16)
        {
            sSlotMachine->pikaPowerBolts++;
            AddPikaPowerBolt(sSlotMachine->pikaPowerBolts);
        }
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_LOSE);
        sSlotMachine->state = SLOTTASK_NO_MATCHES;
        if ((sSlotMachine->netCoinLoss += sSlotMachine->bet) > MAX_COINS)
            sSlotMachine->netCoinLoss = MAX_COINS;
    }
    return FALSE;
}

// SLOTTASK_WAIT_PAYOUT
static bool8 SlotTask_WaitPayout(struct Task *task)
{
    if (IsFinalTask_Task_Payout())
        sSlotMachine->state = SLOTTASK_END_PAYOUT;
    return FALSE;
}

// SLOTTASK_END_PAYOUT
static bool8 SlotTask_EndPayout(struct Task *task)
{
    if (TryStopSlotMachineLights())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;

        if (sSlotMachine->matches & ((1 << MATCH_RED_7) | (1 << MATCH_BLUE_7)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);

        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->currentReel = LEFT_REEL;
            sSlotMachine->state = SLOTTASK_START_SPIN;
        }

        if (sSlotMachine->matches & (1 << MATCH_POWER))
            sSlotMachine->state = SLOTTASK_MATCHED_POWER;

        if (sSlotMachine->reelTimeSpinsLeft && sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
            sSlotMachine->state = SLOTTASK_WAIT_RT_ANIM;
        }
    }
    return FALSE;
}

// SLOTTASK_MATCHED_POWER
static bool8 SlotTask_MatchedPower(struct Task *task)
{
    if (!IsPikaPowerBoltAnimating())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->state = SLOTTASK_START_SPIN;
            if (sSlotMachine->reelTimeSpinsLeft)
            {
                CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
                sSlotMachine->state = SLOTTASK_WAIT_RT_ANIM;
            }
        }
    }
    return FALSE;
}

// SLOTTASK_WAIT_RT_ANIM
static bool8 SlotTask_WaitReelTimeAnim(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->state = SLOTTASK_START_SPIN;
        }
    }
    return FALSE;
}

// SLOTTASK_RESET_BET_TILES
static bool8 SlotTask_ResetBetTiles(struct Task *task)
{
    DarkenBetTiles(0);
    DarkenBetTiles(1);
    DarkenBetTiles(2);
    sSlotMachine->state = SLOTTASK_READY_NEW_SPIN;
    return FALSE;
}

// SLOTTASK_NO_MATCHES
static bool8 SlotTask_NoMatches(struct Task *task)
{
    if (++task->tTimer2 > 64)
    {
        task->tTimer2 = 0;
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
    }
    return FALSE;
}

// SLOTTASK_ASK_QUIT
static bool8 SlotTask_AskQuit(struct Task *task)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_QuitTheGame, 0, 1, 0, 0);
    CopyWindowToVram(0, COPYWIN_FULL);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x180, 0xE, 0xF);
    sSlotMachine->state = SLOTTASK_HANDLE_QUIT_INPUT;
    return FALSE;
}

// SLOTTASK_HANDLE_QUIT_INPUT
static bool8 SlotTask_HandleQuitInput(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0) // Chose to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        DarkenBetTiles(0);
        DarkenBetTiles(1);
        DarkenBetTiles(2);
        sSlotMachine->coins += sSlotMachine->bet;
        sSlotMachine->state = SLOTTASK_END;
    }
    else if (input == 1 || input == -1) // Chose not to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

// SLOTTASK_MSG_MAX_COINS
static bool8 SlotTask_PrintMsg_MaxCoins(struct Task *task)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_YouveGot9999Coins, 0, 1, 0, 0);
    CopyWindowToVram(0, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_MAX_COINS;
    return FALSE;
}

// SLOTTASK_WAIT_MSG_MAX_COINS
static bool8 SlotTask_WaitMsg_MaxCoins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

// SLOTTASK_MSG_NO_MORE_COINS
static bool8 SlotTask_PrintMsg_NoMoreCoins(struct Task *task)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_YouveRunOutOfCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_NO_MORE_COINS;
    return FALSE;
}

// SLOTTASK_WAIT_MSG_NO_MORE_COINS
static bool8 SlotTask_WaitMsg_NoMoreCoins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOTTASK_END;
    }
    return FALSE;
}

// SLOTTASK_END
static bool8 SlotTask_EndGame(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    TryPutFindThatGamerOnAir(GetCoins());
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    sSlotMachine->state++; // SLOTTASK_FREE
    return FALSE;
}

// SLOTTASK_FREE
static bool8 SlotTask_FreeDataStructures(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSlotMachine->prevMainCb);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Reel);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Time);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Insert);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Stop);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Win);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Lose);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Bonus);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Big);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Reg);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_AButton);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Smoke);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Number);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Pokeball);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_DPad);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);
        TRY_FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
        FREE_AND_SET_NULL(sMenuGfx);
        FREE_AND_SET_NULL(sSelectedPikaPowerTile);
        FREE_AND_SET_NULL(sReelOverlay_Tilemap);
        FREE_AND_SET_NULL(sDigitalDisplayGfxPtr);
        FREE_AND_SET_NULL(sReelTimeGfxPtr);
        FREE_AND_SET_NULL(sReelButtonPress_Tilemap);
        FREE_AND_SET_NULL(sReelBackground_Gfx);
        FREE_AND_SET_NULL(sReelBackgroundSpriteSheet);
        FREE_AND_SET_NULL(sSlotMachineSpritesheetsPtr);
        FREE_AND_SET_NULL(sSlotMachine);
    }
    return FALSE;
}

# undef tTimer
# undef tTimer2

// Determine the biases for this round. There can be at most two biases, one of
// which would need to be a ReelTime bias.
//
// HOW IT WORKS:
//   If the machine is already biased toward 7's, keep this bias.
//
//   Otherwise, there are up to three draws. You first draw to see if you'll get
//   to draw a Special bias. If so, then you draw for the Special bias (and can
//   still potentially miss).
//
//   If you didn't get to draw a Special bias, missed a Special bias, or drew a
//   ReelTime bias, then you can still try to draw a Regular bias.
static void DrawMachineBias(void)
{
    u8 whichBias;

    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        if (!(sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7)))
        {
            if (ShouldTrySpecialBias())
            {
                whichBias = TrySelectBias_Special();
                if (whichBias != ARRAY_COUNT(sBiasesSpecial)) // A bias was selected
                {
                    sSlotMachine->machineBias |= sBiasesSpecial[whichBias];

                    // ReelTime was not selected; don't add other biases
                    if (whichBias != 1) return;
                }
            }

            whichBias = TrySelectBias_Regular();
            if (whichBias != ARRAY_COUNT(sBiasesRegular)) // A bias was selected
                sSlotMachine->machineBias |= sBiasesRegular[whichBias];
        }
    }
}

// Reset `didNotFailBias` to match `machineBias`.
static void ResetBiasFailure(void)
{
    sSlotMachine->didNotFailBias = FALSE;
    if (sSlotMachine->machineBias)
        sSlotMachine->didNotFailBias = TRUE;
}

// See sBiasSymbols for each bias's corresponding symbol.
static u8 GetBiasSymbol(u8 machineBias)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        if (machineBias & 1)
            return sBiasSymbols[i];
        machineBias >>= 1;
    }
    return 0;
}

// Decides whether you will be given the opportunity to draw for a Special bias.
// Depends on your bet and the machine you're using.
//
// The probability of getting to draw a Special is miniscule if you don't bet 3
// coins: barely 1% even on the luckiest machine.
//
// The odds increase to roughly ~5% if you bet 3 coins.
static bool8 ShouldTrySpecialBias(void)
{
    u8 rval = Random();
    if (sSpecialDrawOdds[sSlotMachine->machineId][sSlotMachine->bet - 1] > rval)
        return TRUE;
    return FALSE;
}

// Draws for a Special bias. Note that even when you're given the opportunity to
// draw a Special bias, you can still miss.
//
// On the luckiest machine, there's a 61% chance of drawing no Special bias. On
// the unluckiest, a 73% chance.
static u8 TrySelectBias_Special(void)
{
    s16 whichBias;

    for (whichBias = 0; whichBias < (int)ARRAY_COUNT(sBiasesSpecial); whichBias++)
    {
        s16 rval = Random() & 0xff;
        s16 value = sBiasProbabilities_Special[whichBias][sSlotMachine->machineId];
        if (value > rval)
            break;
    }
    return whichBias;
}

static u8 TrySelectBias_Regular(void)
{
    s16 whichBias;

    for (whichBias = 0; whichBias < (int)ARRAY_COUNT(sBiasesRegular); whichBias++)
    {
        s16 rval = Random() & 0xff;
        s16 value = sBiasProbabilities_Regular[whichBias][sSlotMachine->machineId];

        // Boost odds of BIAS_POWER if it's a lucky game.
        if (whichBias == 0 && sSlotMachine->luckyGame == TRUE)
        {
            value += 10;
            if (value > 0x100)
                value = 0x100;
        }
        // Reduce odds of BIAS_REPLAY if it's a lucky game
        else if (whichBias == 4 && sSlotMachine->luckyGame == TRUE)
        {
            value -= 10;
            if (value < 0)
                value = 0;
        }
        if (value > rval)
            break;
    }
    return whichBias;
}

// Return the probability of drawing the given number of ReelTime spins.
//
// This depends on whether it is a lucky game and the number of Power bolts you
// have collected.
static u8 GetReelTimeSpinProbability(u8 spins)
{
    if (sSlotMachine->luckyGame == FALSE)
        return sReelTimeProbabilities_NormalGame[spins][sSlotMachine->pikaPowerBolts];
    else
        return sReelTimeProbabilities_LuckyGame[spins][sSlotMachine->pikaPowerBolts];
}

// The way this is computed skews the odds much more toward drawing a 0 than
// intended. It initially checks whether you draw a 0 (using the intended
// probability). It then tries to draw positive values, but if these draws all
// miss, you'll still draw a 0.
//
// As a result, even when the power gauge is maxed out, you still have a ~30%
// chance of drawing 0 spins. See sReelTimeProbabilities for more details.
//
// Drawing a random number via a cumulative pdf would have prevented this.
static void GetReelTimeDraw(void)
{
    u8 rval;
    s16 spins;

    sSlotMachine->reelTimeDraw = 0;
    rval = Random();
    if (rval < GetReelTimeSpinProbability(0))
        return;
    for (spins = 5; spins > 0; spins--)
    {
        rval = Random();
        if (rval < GetReelTimeSpinProbability(spins))
            break;
    }
    sSlotMachine->reelTimeDraw = spins;
}

// Returns true if the ReelTime machine should explode. Each time we check,
// the odds of explosion increase.
static bool8 ShouldReelTimeMachineExplode(u16 check)
{
    u16 rval = Random() & 0xff;
    if (rval < sReelTimeExplodeProbability[check])
        return TRUE;
    else
        return FALSE;
}

static u16 ReelTimeSpeed(void)
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
    value = sReelTimeSpeed_Probabilities[i][0];
    if (rval < value)
        return REEL_HALF_SPEED;

    rval = Random() % 100;
    value = sReelTimeSpeed_Probabilities[i][1] + sQuarterSpeed_ProbabilityBoost[sSlotMachine->reelTimeSpinsUsed];
    if (rval < value)
        return REEL_QUARTER_SPEED;

    return REEL_NORMAL_SPEED;
}

static void CheckMatch(void)
{
    sSlotMachine->matches = 0;
    CheckMatch_CenterRow();
    if (sSlotMachine->bet > 1)
        CheckMatch_TopAndBottom();
    if (sSlotMachine->bet > 2)
        CheckMatch_Diagonals();
}

static void CheckMatch_CenterRow(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 2);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 2);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_MIDDLE_ROW);
    }
}

static void CheckMatch_TopAndBottom(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 1);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 1);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        if (match == MATCH_CHERRY)
            match = MATCH_TOPBOT_CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_TOP_ROW);
    }
    sym1 = GetSymbolAtRest(LEFT_REEL, 3);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 3);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        if (match == MATCH_CHERRY)
            match = MATCH_TOPBOT_CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_BOTTOM_ROW);
    }
}

static void CheckMatch_Diagonals(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 1);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        // Don't add payout for cherry, since it's already counted in
        // CheckMatch_TopAndBottom().
        if (match != MATCH_CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matches |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NWSE_DIAG);
    }
    sym1 = GetSymbolAtRest(LEFT_REEL, 3);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        // Don't add payout for cherry, since it's already counted in
        // CheckMatch_TopAndBottom().
        if (match != MATCH_CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matches |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NESW_DIAG);
    }
}

static u8 GetMatchFromSymbols(u8 sym1, u8 sym2, u8 sym3)
{
    if (sym1 == sym2 && sym1 == sym3)
        return sSymbolToMatch[sym1];
    if (sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        return MATCH_MIXED_7;
    if (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        return MATCH_MIXED_7;
    if (sym1 == SYMBOL_CHERRY)
        return MATCH_CHERRY;
    return MATCH_NONE;
}

static void AwardPayout(void)
{
    Task_Payout(CreateTask(Task_Payout, 4));
}

static bool8 IsFinalTask_Task_Payout(void)
{
    if (FindTaskIdByFunc(Task_Payout) == TAIL_SENTINEL)
        return TRUE;
    else
        return FALSE;
}

static void Task_Payout(u8 taskId)
{
    while (sPayoutTasks[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

#define tState data[0]
#define tTimer data[1]

static bool8 PayoutTask_Init(struct Task *task)
{
    if (IsMatchLineDoneFlashingBeforePayout())
    {
        task->tState++; // PAYOUT_TASK_GIVE_PAYOUT
        if (sSlotMachine->payout == 0)
        {
            task->tState = PAYOUT_TASK_FREE;
            return TRUE;
        }
    }
    return FALSE;
}
static bool8 PayoutTask_GivePayout(struct Task *task)
{
    if (!task->tTimer--)
    {
        if (IsFanfareTaskInactive())
            PlaySE(SE_PIN);
        sSlotMachine->payout--;
        if (sSlotMachine->coins < MAX_COINS)
            sSlotMachine->coins++;
        task->tTimer = 8;
        if (JOY_HELD(A_BUTTON))
            task->tTimer = 4;
    }
    if (IsFanfareTaskInactive() && JOY_NEW(START_BUTTON))
    {
        PlaySE(SE_PIN);
        sSlotMachine->coins += sSlotMachine->payout;
        if (sSlotMachine->coins > MAX_COINS)
            sSlotMachine->coins = MAX_COINS;
        sSlotMachine->payout = 0;
    }
    if (sSlotMachine->payout == 0)
        task->tState++; // PAYOUT_TASK_FREE
    return FALSE;
}

static bool8 PayoutTask_Free(struct Task *task)
{
    if (TryStopMatchLinesFlashing())
        DestroyTask(FindTaskIdByFunc(Task_Payout));
    return FALSE;
}

#undef tState
#undef tTimer

// Get the symbol at position `offset` below the top of the reel's tape. Note
// that if `offset` is negative, it wraps around to the bottom of the tape.
//           .-----------------.
//           | [ ] | [ ] | [ ] | <- offset = 0
//           /-----|-----|-----\
// screen -> | [ ] | [ ] | [ ] | <- offset = 1
//           | [ ] | [ ] | [ ] | <- offset = 2
//           | [ ] | [ ] | [ ] | <- offset = 3
//           \-----|-----|-----/
//           | ... | ... | ... |
//           | [ ] | [ ] | [ ] | <- offset = 20
//           .-----------------.
static u8 GetSymbolAtRest(u8 reel, s16 offset)
{
    s16 pos = (sSlotMachine->reelPositions[reel] + offset) % SYMBOLS_PER_REEL;
    if (pos < 0)
        pos += SYMBOLS_PER_REEL;
    return sReelSymbols[reel][pos];
}

// Calculates GetSymbolAtRest as if the reel were snapped downwards into place.
static u8 GetSymbol(u8 reel, s16 offset)
{
    s16 inc = 0;
    s16 pixelOffset = sSlotMachine->reelPixelOffsets[reel] % REEL_SYMBOL_HEIGHT;
    if (pixelOffset != 0)
        inc = -1;
    return GetSymbolAtRest(reel, offset + inc);
}

static u8 GetReelTimeSymbol(s16 offset)
{
    s16 newPosition = (sSlotMachine->reeltimePosition + offset) % REELTIME_SYMBOLS;
    if (newPosition < 0)
        newPosition += REELTIME_SYMBOLS;
    return sReelTimeSymbols[newPosition];
}

static void AdvanceSlotReel(u8 reelIndex, s16 value)
{
    sSlotMachine->reelPixelOffsets[reelIndex] += value;
    sSlotMachine->reelPixelOffsets[reelIndex] %= REEL_HEIGHT;
    sSlotMachine->reelPositions[reelIndex] = SYMBOLS_PER_REEL - sSlotMachine->reelPixelOffsets[reelIndex] / REEL_SYMBOL_HEIGHT;
}

// Advances the reel no further than the next symbol. Returns the remaining
// pixels until the next symbol.
s16 AdvanceSlotReelToNextSymbol(u8 reelIndex, s16 value)
{
    s16 offset = sSlotMachine->reelPixelOffsets[reelIndex] % REEL_SYMBOL_HEIGHT;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceSlotReel(reelIndex, value);
        offset = sSlotMachine->reelPixelOffsets[reelIndex] % REEL_SYMBOL_HEIGHT;
    }
    return offset;
}

static void AdvanceReeltimeReel(s16 value)
{
    sSlotMachine->reeltimePixelOffset += value;
    sSlotMachine->reeltimePixelOffset %= REELTIME_REEL_HEIGHT;
    sSlotMachine->reeltimePosition = REELTIME_SYMBOLS - sSlotMachine->reeltimePixelOffset / REELTIME_SYMBOL_HEIGHT;
}

// Advances the reel no further than the next symbol. Returns the remaining
// pixels until the next symbol.
s16 AdvanceReeltimeReelToNextSymbol(s16 value)
{
    s16 offset = sSlotMachine->reeltimePixelOffset % REELTIME_SYMBOL_HEIGHT;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceReeltimeReel(value);
        offset = sSlotMachine->reeltimePixelOffset % REELTIME_SYMBOL_HEIGHT;
    }
    return offset;
}

#define tState          data[0]
#define tExtraTurns     data[1]
#define tShockMagnitude data[1]
#define tTimer          data[2]
#define tMoving         data[14]
#define tReelId         data[15]

static void CreateReelTasks(void)
{
    u8 i;
    for (i = 0; i < NUM_REELS; i++)
    {
        u8 taskId = CreateTask(Task_Reel, 2);
        gTasks[taskId].tReelId = i;
        sSlotMachine->slotReelTasks[i] = taskId;
        Task_Reel(taskId);
    }
}

static void SpinSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_TASK_SPIN;
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving = TRUE;
}

static void StopSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_TASK_DECIDE_STOP;
}

static bool8 IsSlotReelMoving(u8 reelIndex)
{
    return gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving;
}

static void Task_Reel(u8 taskId)
{
    while (sReelTasks[gTasks[taskId].tState](&gTasks[taskId]))
        ;
}

static bool8 ReelTask_StayStill(struct Task *task)
{
    return FALSE;
}

static bool8 ReelTask_Spin(struct Task *task)
{
    AdvanceSlotReel(task->tReelId, sSlotMachine->reelSpeed);
    return FALSE;
}

// In ReelTime, the reel stops immediately. Otherwise, the game may manipulate
// the results by stopping after at most 4 extra turns. The exact behavior
// differs depending on whether the machine has a bias.
//
// If the machine has a bias, it will try to match the bias symbol in each reel.
//
// Otherwise, if the machine doesn't have a bias or it could not line up the
// bias symbol in any of the previous reels, it will perform the NoBias stopping
// routine, which manipulates the outcome so the player loses.
static bool8 ReelTask_DecideStop(struct Task *task)
{
    task->tState++; // REEL_TASK_STOP_MOVE
    sSlotMachine->winnerRows[task->tReelId] = 0;
    sSlotMachine->reelExtraTurns[task->tReelId] = 0;

    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        if (sSlotMachine->machineBias == 0 || !sSlotMachine->didNotFailBias || !sDecideStop_Bias[task->tReelId]())
        {
            sSlotMachine->didNotFailBias = FALSE;
            sDecideStop_NoBias[task->tReelId]();
        }
    }
    task->tExtraTurns = sSlotMachine->reelExtraTurns[task->tReelId];
    return TRUE;
}

// Go to the next symbol, then add any extra turns.
static bool8 ReelTask_MoveToStop(struct Task *task)
{
    u16 reelStopShocks[ARRAY_COUNT(sReelStopShocks)];
    s16 reelPixelPos;

    memcpy(reelStopShocks, sReelStopShocks, sizeof(sReelStopShocks));
    reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    if (reelPixelPos != 0)
        reelPixelPos = AdvanceSlotReelToNextSymbol(task->tReelId, sSlotMachine->reelSpeed);
    else if (sSlotMachine->reelExtraTurns[task->tReelId])
    {
        sSlotMachine->reelExtraTurns[task->tReelId]--;
        AdvanceSlotReel(task->tReelId, sSlotMachine->reelSpeed);
        reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    }

    if (reelPixelPos == 0 && sSlotMachine->reelExtraTurns[task->tReelId] == 0)
    {
        task->tState++; // REEL_TASK_STOP_SHAKE
        task->tShockMagnitude = reelStopShocks[task->tExtraTurns];
        task->tTimer = 0;
    }
    return FALSE;
}

// The reel shakes a little at the selected symbol before settling.
static bool8 ReelTask_ShakingStop(struct Task *task)
{
    sSlotMachine->reelShockOffsets[task->tReelId] = task->tShockMagnitude;
    task->tShockMagnitude = -task->tShockMagnitude;
    task->tTimer++;
    if ((task->tTimer & 0x3) == 0)
        task->tShockMagnitude >>= 1;
    if (task->tShockMagnitude == 0)
    {
        task->tState = 0;
        task->tMoving = FALSE;
        sSlotMachine->reelShockOffsets[task->tReelId] = 0;
    }
    return FALSE;
}

#undef tState
#undef tExtraTurns
#undef tShockMagnitude
#undef tTimer
#undef tMoving
#undef tReelId

// We pass along two symbols to bias toward. If the machine is biased toward
// 7's, we pass both the 7 symbols. Otherwise, we just pass the bias symbol
// twice.
static bool8 DecideStop_Bias_Reel1(void)
{
    u8 sym2 = GetBiasSymbol(sSlotMachine->machineBias);
    u8 sym1 = sym2;
    if (sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7))
    {
        sym1 = SYMBOL_7_RED;
        sym2 = SYMBOL_7_BLUE;
    }
        return sDecideStop_Bias_Reel1_Bets[sSlotMachine->bet - 1](sym1, sym2);
}

// The biasSymbol for subsequent reels is determined based on which of the bias
// symbols can be found in reel 1. This really only matters when the machine is
// biased toward 7's. It will try to match a 7 of the same color as reel 1.
static bool8 EitherSymbolAtPos_Reel1(s16 pos, u8 sym1, u8 sym2)
{
    u8 sym = GetSymbol(LEFT_REEL, pos);
    if (sym == sym1 || sym == sym2)
    {
        sSlotMachine->biasSymbol = sym;
        return TRUE;
    }
    return FALSE;
}

// Returns true if there are cherries on screen in reel 1 after the given number
// of turns.
static bool8 AreCherriesOnScreen_Reel1(s16 turns)
{
    if (GetSymbol(LEFT_REEL, 1 - turns) == SYMBOL_CHERRY
        || GetSymbol(LEFT_REEL, 2 - turns) == SYMBOL_CHERRY
        || GetSymbol(LEFT_REEL, 3 - turns) == SYMBOL_CHERRY)
        return TRUE;
    else
        return FALSE;
}

static bool8 BiasedTowardCherryOr7s(void)
{
    if (sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7 | BIAS_CHERRY))
        return TRUE;
    else
        return FALSE;
}

// If a bias symbol appears in the center of reel 1 within the next 4 turns,
// stop there. That symbol becomes the biasSymbol for the subsequent reels.
static bool8 DecideStop_Bias_Reel1_Bet1(u8 sym1, u8 sym2)
{
    s16 i;

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (EitherSymbolAtPos_Reel1(2 - i, sym1, sym2))
        {
            sSlotMachine->winnerRows[LEFT_REEL] = 2;
            sSlotMachine->reelExtraTurns[LEFT_REEL] = i;
            return TRUE;
        }
    }
    return FALSE;
}

// There is slightly different behavior depending on the machine's bias.
//
// Bias toward cherry or 7s:
//  - Check if a cherry or 7 is currently on screen. If so, stop immediately.
//  - Roll up to 4 extra turns to see if a cherry or 7 enters the screen:
//     - If it enters after 1 turn, stop the reel when it gets the bottom row.
//     - Otherwise, if it enters before the 4th turn, stop the reel when it gets
//       to the middle row.
//     - If it enters on the 4th turn, stop here. It will be in the top row.
//
// Other bias:
//  - This is very similar, except the game is checking for the bias symbol
//    rather than cherries / 7s.
//
//    However, the game adds an additional constraint: it will not stop if there
//    will be any cherries on screen. Presumably, this ensures that you will not
//    get any matches if you fail to line up the bias symbol in the remaining
//    reels.
//
//    This is programmed in such a way that it excludes more options than
//    necessary. If there are cherries in the two positions below the bias symbol,
//    it will skip over this option, even if those cherries would not have ended
//    up on screen.
static bool8 DecideStop_Bias_Reel1_Bet2or3(u8 sym1, u8 sym2)
{
    s16 i;
    bool8 cherry7Bias = BiasedTowardCherryOr7s();
    if (cherry7Bias || !AreCherriesOnScreen_Reel1(0))
    {
        // Check the current screen
        for (i = 1; i <= 3; i++)
        {
            if (EitherSymbolAtPos_Reel1(i, sym1, sym2))
            {
                sSlotMachine->winnerRows[0] = i;
                sSlotMachine->reelExtraTurns[0] = 0;
                return TRUE;
            }
        }
    }

    // Check the next 4 turns
    for (i = 1; i <= MAX_EXTRA_TURNS; i++)
    {
        bool8 cherry7BiasCopy = cherry7Bias; // redundant
        if (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(i))
        {
            if (EitherSymbolAtPos_Reel1(1 - i, sym1, sym2))
            {
                if (i == 1 && (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(3)))
                {
                    sSlotMachine->winnerRows[0] = 3;
                    sSlotMachine->reelExtraTurns[0] = 3;
                    return TRUE;
                }
                if (i <= 3 && (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(i + 1)))
                {
                    sSlotMachine->winnerRows[0] = 2;
                    sSlotMachine->reelExtraTurns[0] = i + 1;
                    return TRUE;
                }
                sSlotMachine->winnerRows[0] = 1;
                sSlotMachine->reelExtraTurns[0] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

static bool8 DecideStop_Bias_Reel2(void)
{
    return sDecideStop_Bias_Reel2_Bets[sSlotMachine->bet - 1]();
}

// Turn at most 4 extra turns to try to line up the bias symbol in the same row
// as reel 1.
static bool8 DecideStop_Bias_Reel2_Bet1or2(void)
{
    s16 i;
    s16 reel1BiasRow = sSlotMachine->winnerRows[0];

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(MIDDLE_REEL, reel1BiasRow - i) == sSlotMachine->biasSymbol)
        {
            sSlotMachine->winnerRows[1] = reel1BiasRow;
            sSlotMachine->reelExtraTurns[1] = i;
            return TRUE;
        }
    }
    return FALSE;
}

// Checks whether it can match the bias symbol diagonally, and sometimes skews
// toward this type of match rather than a match straight across.
//
// The behavior is different depending on where the bias symbol landed in
// reel 1:
//
// Landed in middle row:
//   A diagonal match is impossible. Just try to match the bias symbol in the
//   middle row of reel 2 within 4 turns.
//
// Landed in top/bottom row:
//  - If it would take 2 or 3 turns to get the bias symbol into the same row as
//    reel 1, force a diagonal match by stopping it in the middle row instead.
//  - Check if the bias symbol is already in the same row as reel 1, or if it
//    takes 1 or 4 turns to get it there. If so, stop when it reaches that row.
//  - Otherwise, check if the bias symbol is already in the middle row of
//    reel 2. If so, stop here.
//
// So in how many more cases would betting 3 coins let you win compared to
// betting 2?
//   Not many. Most of the time, the game would have matched the symbol in the
//   same row as reel 1 if you had bet 2 coins. Betting 3 effectively adds
//   coverage for only two additional cases:
//    - Bias symbol is in top row of reel 1 and bias symbol is currently in
//      middle row of reel 2.
//    - Bias symbol is in bottom row of reel 1 and bias symbol could get to the
//      middle row of reel 2 in 4 turns.
//
// Assuming this is the implementation Game Freak intended, the game effectively
// turns straight matches into diagonal matches with 2/5 probability.
// Presumably, this makes the player feel fortunate that they bet 3 coins rather
// than 2, even though most times the game would have still forced a match with
// only 2 coins.
static bool8 DecideStop_Bias_Reel2_Bet3(void)
{
    s16 i;
    // If you can line up the bias symbol in the same row as reel 1 within 4
    // turns
    if (DecideStop_Bias_Reel2_Bet1or2())
    {
        // If bias symbol is not in the middle row of reel 1 and it takes either
        // 2 or 3 turns to get it in the same row for reel 2
        if (sSlotMachine->winnerRows[0] != 2 && sSlotMachine->reelExtraTurns[1] > 1 && sSlotMachine->reelExtraTurns[1] != 4)
        {
            // Try turning this into a diagonal match by lining up the bias
            // symbol in the middle row of reel 2 within 4 turns.
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (GetSymbol(MIDDLE_REEL, 2 - i) == sSlotMachine->biasSymbol)
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
        return TRUE;
    }

    // If you can't line up the bias symbol in the same row in 4 turns, and the
    // bias symbol is not in the middle row of reel 1
    if (sSlotMachine->winnerRows[0] != 2)
    {
        // Try to match the bias symbol in middle row of reel 2 within 4 turns.
        // Adds coverage for the two cases mentioned above.
        for (i = 0; i <= MAX_EXTRA_TURNS; i++)
        {
            if (GetSymbol(MIDDLE_REEL, 2 - i) == sSlotMachine->biasSymbol)
            {
                sSlotMachine->winnerRows[1] = 2;
                sSlotMachine->reelExtraTurns[1] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

// If the machine is biased toward mixed 7's, swap the color of the bias symbol
// from red 7 to blue 7, or vice versa.
static bool8 DecideStop_Bias_Reel3(void)
{
    u8 biasSymbol = sSlotMachine->biasSymbol;
    if (sSlotMachine->machineBias & BIAS_MIXED_7)
    {
        biasSymbol = SYMBOL_7_RED;
        if (sSlotMachine->biasSymbol == SYMBOL_7_RED)
        {
            biasSymbol = SYMBOL_7_BLUE;
        }
    }
    return sDecideStop_Bias_Reel3_Bets[sSlotMachine->bet - 1](biasSymbol);
}

// Turn at most 4 extra turns to try to line up the bias symbol in the same
// row as reel 2.
static bool8 DecideStop_Bias_Reel3_Bet1or2(u8 biasSymbol)
{
    s16 i;
    s16 reel2BiasRow = sSlotMachine->winnerRows[1];

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(RIGHT_REEL, reel2BiasRow - i) == biasSymbol)
        {
            sSlotMachine->winnerRows[2] = reel2BiasRow;
            sSlotMachine->reelExtraTurns[2] = i;
            return TRUE;
        }
    }
    return FALSE;
}

// Try to complete a match in reel 3 by lining up a bias symbol with the bias
// symbols from the first two reels.
static bool8 DecideStop_Bias_Reel3_Bet3(u8 biasSymbol)
{
    s16 i;
    s16 biasRow;

    // First two bias symbols in the same row. Try to line up bias symbol in
    // same the row here too
    if (sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1])
        return DecideStop_Bias_Reel3_Bet1or2(biasSymbol);

    // Otherwise, try to line up the bias symbol diagonally
    if (sSlotMachine->winnerRows[0] == 1)
        biasRow = 3;
    else
        biasRow = 1;
    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(RIGHT_REEL, biasRow - i) == biasSymbol)
        {
            sSlotMachine->reelExtraTurns[2] = i;
            sSlotMachine->winnerRows[2] = biasRow;
            return TRUE;
        }
    }
    return FALSE;
}

// Advance as many turns as needed until there are no cherries on screen in
// reel 1, as cherries would cause a match.
//
// Based on the distribution of reel 1, this will add at most 3 extra turns.
static void DecideStop_NoBias_Reel1(void)
{
    s16 i = 0;

    while (AreCherriesOnScreen_Reel1(i) != 0)
        i++;
    sSlotMachine->reelExtraTurns[0] = i;
}

// If the bias symbol is one of the 7's, switch to the opposite color and return
// true. Otherwise, return false.
static bool8 IfSymbol7_SwitchColor(u8 *symbol)
{
    if (*symbol == SYMBOL_7_RED)
    {
        *symbol = SYMBOL_7_BLUE;
        return TRUE;
    }
    if (*symbol == SYMBOL_7_BLUE)
    {
        *symbol = SYMBOL_7_RED;
        return TRUE;
    }
    return FALSE;
}

// If the machine doesn't have a bias, the reel stops immediately.
//
// Otherwise, the machine tries to taunt the player if it is biased toward
// straight 7's. This would only happen if the player did not stop near the
// correct-color 7, so the machine couldn't force a match.
//
// Instead, the machine now tries to line up the opposite-color 7, which is not
// a valid match.
static void DecideStop_NoBias_Reel2(void)
{
    sDecideStop_NoBias_Reel2_Bets[sSlotMachine->bet - 1]();
}

// If the machine has no bias, stop immediately.
//
// Otherwise, the machine manipulates the results if all the following
// conditions are met:
// If
//  - The machine is biased toward straight 7's
//  - The machine managed to match a 7 in the middle of reel 1
//  - The machine could not line up a 7 of the same color in reel 2
// Then
//    The machine will try to line up a 7 of the opposite color in reel 2
static void DecideStop_NoBias_Reel2_Bet1(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        // Note here and in other NoBias functions, reelExtraTurns is 0 if it
        // corresponds to a previous reel. That reel has already stopped and any
        // extra turns were applied.
        u8 reel1MiddleSym = GetSymbol(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1MiddleSym))
        {
            s16 i;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (reel1MiddleSym == GetSymbol(MIDDLE_REEL, 2 - i))
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}

// If the machine has no bias, stop immediately.
//
// Otherwise, the machine manipulates the results if all the following
// conditions are met:
// If
//  - The machine is biased toward straight 7's
//  - The machine managed to match a 7 anywhere in reel 1
//  - The machine could not line up a 7 of the same color in reel 2
// Then
//    The machine will try to line up a 7 of the opposite color in reel 2
static void DecideStop_NoBias_Reel2_Bet2(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        u8 reel1BiasSym = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1BiasSym))
        {
            s16 i;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[0] - i))
                {
                    sSlotMachine->winnerRows[1] = sSlotMachine->winnerRows[0];
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}

// If the machine has no bias, stop immediately.
//
// Otherwise, the machine manipulates the results if all the following
// conditions are met:
// If
//  - The machine is biased toward straight 7's
//  - The machine managed to match a 7 anywhere in reel 1
//  - The machine could not line up a 7 of the same color in reel 2
// Then
//    The machine will try to line up a 7 of the opposite color in reel 2
//
// The way it tries to line up an opposite-color 7 differs depending on where
// the 7 is in reel 1:
//
// Middle row:
//   Try to line up an opposite-color 7 in the middle of reel 2 within 4 turns.
//
// Top row:
//  - First check for an opposite-color 7 in the top and middle rows of the
//    current screen. If found, stop immediately.
//  - Otherwise, check if an opposite-color 7 will enter the top row within 4
//    turns.
//     - If one enters in 1 or 2 turns, stop the reel when it gets to the middle
//       row.
//     - If one enters in 3 or 4 turns, stop the reel when it gets to the top
//       row.
//
// Bottom row:
//  - First check for an opposite-color 7 in the middle and bottom rows of the
//    current screen. If found, stop immediately.
//  - Otherwise, check if an opposite-color 7 will enter the bottom row within 4
//    turns.
//     - If one enters in 1 or 2 turns, stop the reel when it gets to the bottom
//       row.
//     - If one enters in 3 or 4 turns, stop the reel when it gets to the middle
//       row.
//
// BUG: This procedure misses an opportunity to line up an opposite-color 7 in
// one scenario, when:
//  - There is a 7 in the bottom row of reel 1
//  - And, you can get an opposite-color 7 in the middle row of reel 2 in 4
//    turns
static void DecideStop_NoBias_Reel2_Bet3(void)
{
    s16 i;
    s16 j;
    u8 reel1BiasSym;

    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        // Lined up 7 in middle of reel 1
        if (sSlotMachine->winnerRows[0] == 2)
        {
            DecideStop_NoBias_Reel2_Bet2();
            return;
        }

        reel1BiasSym = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1BiasSym))
        {
            // Check current screen to see if there is already an opposite-color
            // 7 lined up for a match.
            j = 2;
            if (sSlotMachine->winnerRows[0] == 3)
                j = 3;
            for (i = 0; i < 2; i++, j--)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, j))
                {
                    sSlotMachine->winnerRows[1] = j;
                    sSlotMachine->reelExtraTurns[1] = 0;
                    return;
                }
            }

            // Check if opposite-color 7 will appear in same row as reel 1 in
            // over the next 4 turns
            for (j = 1; j <= MAX_EXTRA_TURNS; j++)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[0] - j))
                {
                    // If 7 appeared in top row of reel 1
                    if (sSlotMachine->winnerRows[0] == 1)
                    {
                        if (j <= 2)
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
                    // If 7 appeared in bottom row of reel 1
                    else
                    {
                        if (j <= 2)
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

// Returns true if the reel 1 and reel 2 symbols are opposite-color 7's.
//
// Note that if true, this does not constitue a MATCH_MIXED_7, as the first two
// reels are not the same color.
static bool8 MismatchedSyms_77(u8 sym1, u8 sym2)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE) || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED))
        return TRUE;
    else
        return FALSE;
}

// Returns true if the reel 1, reel 2 and reel 3 symbolss form a 7 mismatch,
// i.e. {7R, 7B, 7R} or {7B, 7R, 7B}.
static bool8 MismatchedSyms_777(u8 sym1, u8 sym2, u8 sym3)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED) ||
        (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE))
        return TRUE;
    else
        return FALSE;
}

// Returns false if either:
//  - The symbols form a match (including MATCH_MIXED_7)
//  - Or, the symbols form a 7 mismatch (i.e., {7R, 7B, 7R} or {7B, 7R, 7B})
//
// Note, this does not account for cherry matches.
static bool8 NeitherMatchNor7Mismatch(u8 sym1, u8 sym2, u8 sym3)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        || (sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        || (sym1 == sym2 && sym1 == sym3))
    {
        return FALSE;
    }
    return TRUE;
}

// Spin until there's no match, or try to taunt the player with a 7 mismatch if
// they failed the straight 7 bias.
static void DecideStop_NoBias_Reel3(void)
{
    sDecideStop_NoBias_Reel3_Bets[sSlotMachine->bet - 1]();
}

// Spin until there is no match in reel 3. Additionally, if the player failed a
// straight 7 bias, try to taunt them with a 7 mismatch.
//
// The way this plays out depends on the first two matched symbols.
//
// If first two symbols are the same:
//   Spin until you get a symbol that won't complete a match.
//
// Otherwise, if the first two symbols are opposite-color 7's:
//  - If the machine is biased toward straight 7's, then the player must have
//    failed with this bias. The machine tries to taunt the player by turning
//    up to 4 turns to complete a 7 mismatch (i.e., {7R, 7B, 7R} or
//    {7B, 7R, 7B}).
//  - Otherwise, spin until you get a symbol that won't complete a match.
static void DecideStop_NoBias_Reel3_Bet1(void)
{
    s16 i = 0;
    u8 sym1 = GetSymbol(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
    u8 sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);

    // If first two symbols match, spin until you get a non-matching symbol
    if (sym1 == sym2)
    {
        while (TRUE)
        {
            u8 sym3;
            if (!((sym1 == (sym3 = GetSymbol(RIGHT_REEL, 2 - i)))
                  || (sym1 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
                  || (sym1 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)))
                break;
            i++;
        }
    }
    // First two symbols are opposite-color 7's
    else if (MismatchedSyms_77(sym1, sym2))
    {
        // If biased toward straight 7's, try to complete the 7 mismatch in 4
        // turns
        if (sSlotMachine->machineBias & BIAS_STRAIGHT_7)
        {
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (sym1 == GetSymbol(RIGHT_REEL, 2 - i))
                {
                    sSlotMachine->reelExtraTurns[2] = i;
                    return;
                }
            }
        }

        // Otherwise, just spin until you get a non-matching symbol
        i = 0;
        while (TRUE)
        {
            if (sym1 != GetSymbol(RIGHT_REEL, 2 - i))
                break;
            i++;
        }
    }
    sSlotMachine->reelExtraTurns[2] = i;
}

// Spin until there is no match in reel 3. Additionally, if the player failed a
// straight 7 bias, try to taunt them with a 7 mismatch.
//
// There are up to two stages, depending on the first two matched symbols:
//
// 1. [Optional] If first two symbols are opposite-color 7's in the same row and
//    the machine is biased toward straight 7's:
//      Check if a 7 with the same color as reel 1 appears in the same row
//      within 4 turns. If so, initially advance to that position.
//
// 2. Check rows. Keep advancing the reel a turn at a time as long as:
//     - There is a match in any row
//     - Or, there is a 7 mismatch in any row and the machine isn't biased
//       toward straight 7's
//
// Note, stage 2 is not limited to 4 turns. The reel keeps spinning until you
// lose.
static void DecideStop_NoBias_Reel3_Bet2(void)
{
    s16 extraTurns = 0;
    s16 i;
    u8 sym1;
    u8 sym2;
    u8 sym3;

    // Effectively, if you lined up two 7's in the same row
    if (sSlotMachine->winnerRows[1] != 0 &&
        sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1] &&
        sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        sym1 = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);

        // If the first two 7's are opposite colors, see if you can line up a 7
        // mismatch in the same row. If so, advance initially to that position.
        // More turns may be added further below.
        if (MismatchedSyms_77(sym1, sym2))
        {
            // Iterate over the next 4 turns
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                sym3 = GetSymbol(RIGHT_REEL, sSlotMachine->winnerRows[1] - i);
                if (sym1 == sym3)
                {
                    extraTurns = i;
                    break;
                }
            }
        }
    }

    while (TRUE)
    {
        s16 numMatches;
        // Iterate over the rows of the screen after `extraTurns` turns
        for (i = 1, numMatches = 0; i <= 3; i++)
        {
            sym1 = GetSymbol(LEFT_REEL, i - sSlotMachine->reelExtraTurns[0]);
            sym2 = GetSymbol(MIDDLE_REEL, i - sSlotMachine->reelExtraTurns[1]);
            sym3 = GetSymbol(RIGHT_REEL, i - extraTurns);

            // This boils down to:
            //   If there's a match on screen, keep spinning. Otherwise, if
            //   there's a 7 mismatch on screen, keep spinning if the machine
            //   isn't biased toward straight 7's.
            if (!NeitherMatchNor7Mismatch(sym1, sym2, sym3) &&
                !(MismatchedSyms_777(sym1, sym2, sym3) && (sSlotMachine->machineBias & BIAS_STRAIGHT_7)))
            {
                numMatches++;
                break;
            }
        }

        // If no matches were found, stop here. Otherwise, add an extra spin and
        // check again.
        if (numMatches == 0)
            break;
        extraTurns++;
    }
    sSlotMachine->reelExtraTurns[2] = extraTurns;
}

// Try to spin until there is no match in reel 3. Additionally, if the player
// failed a straight 7 bias, try to taunt them with a 7 mismatch.
//
// There are up to four stages:
//
// 1. Advance the reel as if 2 coins were bet: to mildly oversimplify, spin
//    until there's no matches straight across in any rows.
//
// 2. [Optional] If you've lined up two opposite-color 7's diagonally and the
//    machine is biased toward straight 7's:
//      Check if a 7 with the same color as reel 1 appears in the final diagonal
//      position within 4 turns. If so, advance to that position.
//
// 3. Check NWSE diagonal. Keep advancing the reel a turn at a time as long as:
//     - There is a match in the diagonal
//     - Or, there is a 7 mismatch in the diagonal and the machine isn't
//       biased toward straight 7's
//
// 3. Check NESW diagonal. Keep advancing the reel a turn at a time as long as:
//     - There is a match in the diagonal
//     - Or, there is a 7 mismatch in the diagonal and the machine isn't
//       biased toward straight 7's
//
// Note that stages 3 and 4 are not limited to 4 turns.
//
// Also, note that it actually is possible to win a match here. After stage 1,
// the game never again checks whether it will be matching any rows straight
// across. So any extra turns added in stages 2-4 could result in a match
// occurring straight across.
static void DecideStop_NoBias_Reel3_Bet3(void)
{
    u8 sym1;
    u8 sym2;
    u8 sym3;
    s16 row;
    s16 i;

    // Spin until there's no matches in any row straight across, potentially
    // skewing toward a 7 mismatch. Consider this the new starting position for
    // this function.
    DecideStop_NoBias_Reel3_Bet2();

    // Essentially, if you lined up two 7's diagonally
    if (sSlotMachine->winnerRows[1] != 0 &&
        sSlotMachine->winnerRows[0] != sSlotMachine->winnerRows[1] &&
        sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        sym1 = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);

        // If the first two 7's are opposite colors, try advancing up to 4
        // additional turns to line up a diagonal 7 mismatch. More turns may be
        // added further below.
        if (MismatchedSyms_77(sym1, sym2))
        {
            row = 1;
            if (sSlotMachine->winnerRows[0] == 1)
                row = 3;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                sym3 = GetSymbol(RIGHT_REEL, row - (sSlotMachine->reelExtraTurns[2] + i));
                if (sym1 == sym3)
                {
                    sSlotMachine->reelExtraTurns[2] += i;
                    break;
                }
            }
        }
    }

    while (TRUE)
    {
        // Check NWSE diagonal
        sym1 = GetSymbol(LEFT_REEL, 1 - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        sym3 = GetSymbol(RIGHT_REEL, 3 - sSlotMachine->reelExtraTurns[2]);
        if (NeitherMatchNor7Mismatch(sym1, sym2, sym3)
            || (MismatchedSyms_777(sym1, sym2, sym3) && sSlotMachine->machineBias & BIAS_STRAIGHT_7))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }

    while (TRUE)
    {
        // Check NESW diagonal
        sym1 = GetSymbol(LEFT_REEL, 3 - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        sym3 = GetSymbol(RIGHT_REEL, 1 - sSlotMachine->reelExtraTurns[2]);
        if (NeitherMatchNor7Mismatch(sym1, sym2, sym3)
            || (MismatchedSyms_777(sym1, sym2, sym3) && sSlotMachine->machineBias & BIAS_STRAIGHT_7))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }
}

static void PressStopReelButton(u8 reelNum)
{
    u8 taskId = CreateTask(Task_PressStopReelButton, 5);
    gTasks[taskId].data[15] = reelNum;
    Task_PressStopReelButton(taskId);
}

static void Task_PressStopReelButton(u8 taskId)
{
    sReelStopButtonTasks[gTasks[taskId].data[0]](&gTasks[taskId], taskId);
}

static void StopReelButton_Press(struct Task *task, u8 taskId)
{
    SetReelButtonTilemap(sReelButtonOffsets[task->data[15]], 0x62, 0x63, 0x72, 0x73);
    task->data[0]++;
}

static void StopReelButton_Wait(struct Task *task, u8 taskId)
{
    if (++task->data[1] > 11)
        task->data[0]++;
}

static void StopReelButton_Unpress(struct Task *task, u8 taskId)
{
    SetReelButtonTilemap(sReelButtonOffsets[task->data[15]], 0x42, 0x43, 0x52, 0x53);
    DestroyTask(taskId);
}

static void LightenMatchLine(u8 matchLineId)
{
    LoadPalette(sLitMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], PLTT_SIZEOF(1));
}

static void DarkenMatchLine(u8 matchLineId)
{
    LoadPalette(sDarkMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], PLTT_SIZEOF(1));
}

// light up the match line for each bet by the player
static void LightenBetTiles(u8 betVal)
{
    u8 i;
    for (i = 0; i < sMatchLinesPerBet[betVal]; i++)
        LightenMatchLine(sBetToMatchLineIds[betVal][i]);
}

static void DarkenBetTiles(u8 betVal)
{
    u8 i;
    for (i = 0; i < sMatchLinesPerBet[betVal]; i++)
        DarkenMatchLine(sBetToMatchLineIds[betVal][i]);
}

#define sMatchLineId     data[0]
#define sFlashing        data[1]
#define sNumFullFlashes  data[2]
#define sDelayTimer      data[3]
#define sColor           data[4]
#define sColorIncr       data[5]
#define sAtOriginalColor data[7]

// Creates invisible sprites that flash the bet lines/numbers where a match occurs
// 5 are created, 1 for each possible match line (3 rows, 2 diagonals)
static void CreateInvisibleFlashMatchLineSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        u8 spriteId = CreateInvisibleSprite(SpriteCB_FlashMatchingLines);
        gSprites[spriteId].sMatchLineId = i;
        sSlotMachine->flashMatchLineSpriteIds[i] = spriteId;
    }
}

static void FlashMatchLine(u8 matchLineId)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->flashMatchLineSpriteIds[matchLineId]];
    sprite->sFlashing = TRUE;
    sprite->sNumFullFlashes = 4;
    sprite->sDelayTimer = 0;
    sprite->sColor = 0;
    sprite->sColorIncr = 2;
    sprite->sAtOriginalColor = FALSE;
}

// Match line flashes 4 times before the payout begins
// After this it does half-brightness flashes until the payout finishes
static bool8 IsMatchLineDoneFlashingBeforePayout(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        struct Sprite *sprite = &gSprites[sSlotMachine->flashMatchLineSpriteIds[i]];
        if (sprite->sFlashing && sprite->sNumFullFlashes)
            return FALSE;
    }
    return TRUE;
}

// When payout is finished, stop lines flashing (but not if they're in the middle of a flash)
static bool8 TryStopMatchLinesFlashing(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        if (!TryStopMatchLineFlashing(sSlotMachine->flashMatchLineSpriteIds[i]))
            return FALSE;
    }
    return TRUE;
}

static bool8 TryStopMatchLineFlashing(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    if (!sprite->sFlashing)
        return TRUE;
    if (sprite->sAtOriginalColor)
        sprite->sFlashing = FALSE;

    return sprite->sAtOriginalColor;
}

static void SpriteCB_FlashMatchingLines(struct Sprite *sprite)
{
    s16 maxColorChange;
    if (sprite->sFlashing)
    {
        if (!sprite->sDelayTimer--)
        {
            sprite->sAtOriginalColor = FALSE;
            sprite->sDelayTimer = 1;
            sprite->sColor += sprite->sColorIncr;
            maxColorChange = 4;
            if (sprite->sNumFullFlashes)
                maxColorChange = 8;
            if (sprite->sColor <= 0)
            {
                // Returned to original color, reverse
                sprite->sAtOriginalColor = TRUE;
                sprite->sColorIncr = -sprite->sColorIncr;
                if (sprite->sNumFullFlashes)
                    sprite->sNumFullFlashes--;
            }
            else if (sprite->sColor >= maxColorChange) {
                // Reached peak darkness, reverse
                sprite->sColorIncr = -sprite->sColorIncr;
            }
            if (sprite->sNumFullFlashes)
                sprite->sDelayTimer <<= 1;
        }
        MultiplyPaletteRGBComponents(sMatchLinePalOffsets[sprite->sMatchLineId], sprite->sColor, sprite->sColor, sprite->sColor);
    }
}

#undef sMatchLineId
#undef sFlashing
#undef sNumFullFlashes
#undef sDelayTimer
#undef sColor
#undef sColorIncr
#undef sAtOriginalColor

#define sDelayTimer data[1]
#define sFlashState data[2]
#define sFlashDir   data[3]

static void FlashSlotMachineLights(void)
{
    u8 taskId = CreateTask(Task_FlashSlotMachineLights, 6);
    gTasks[taskId].sFlashDir = 1;
    Task_FlashSlotMachineLights(taskId);
}

static bool8 TryStopSlotMachineLights(void)
{
    u8 taskId = FindTaskIdByFunc(Task_FlashSlotMachineLights);
    if (gTasks[taskId].sFlashState == 0)
    {
        DestroyTask(taskId);
        LoadPalette(sSlotMachineMenu_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        return TRUE;
    }
    return FALSE;
}

static void Task_FlashSlotMachineLights(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->sDelayTimer--)
    {
        task->sDelayTimer = 4;
        task->sFlashState += task->sFlashDir;
        if (task->sFlashState == 0 || task->sFlashState == 2)
            task->sFlashDir = -task->sFlashDir;
    }
    LoadPalette(sFlashingLightsPalTable[task->sFlashState], BG_PLTT_ID(1), PLTT_SIZE_4BPP);
}

#undef sDelayTimer
#undef sFlashState
#undef sFlashDir

#define tState     data[0]
#define tNumBolts  data[1]
#define tSpriteId  data[2]
#define tTimer     data[2] // re-used
#define tAnimating data[15]

static void CreatePikaPowerBoltTask(void)
{
    sSlotMachine->pikaPowerBoltTaskId = CreateTask(Task_CreatePikaPowerBolt, 8);
}

static void AddPikaPowerBolt(u8 bolts)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = PIKABOLT_TASK_ADD_BOLT;
    task->tNumBolts++;
    task->tAnimating = TRUE;
}

static void ResetPikaPowerBolts(void)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = PIKABOLT_TASK_CLEAR_ALL;
    task->tAnimating = TRUE;
}

static bool8 IsPikaPowerBoltAnimating(void)
{
    return gTasks[sSlotMachine->pikaPowerBoltTaskId].tAnimating;
}

static void Task_CreatePikaPowerBolt(u8 taskId)
{
    sPikaPowerBoltTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void PikaPowerBolt_Idle(struct Task *task)
{
}

static void PikaPowerBolt_AddBolt(struct Task *task)
{
    task->tSpriteId = CreatePikaPowerBoltSprite((task->tNumBolts << 3) + 20, 20);
    task->tState++; // PIKABOLT_TASK_WAIT_ANIM
}

// The bolt sprite spins around as it appears
// Once the anim is done, destroy the sprite and set the bolt in the tilemap instead
static void PikaPowerBolt_WaitAnim(struct Task *task)
{
    if (gSprites[task->tSpriteId].data[7])
    {
        s16 r5 = task->tNumBolts + 2;
        s16 r3 = 0;
        s16 r2 = 0;
        if (task->tNumBolts == 1)
            r3 = 1, r2 = 1;
        else if (task->tNumBolts == 16)
            r3 = 2, r2 = 2;
        sSelectedPikaPowerTile[r2] = sPikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, r5 + 0x40);
        DestroyPikaPowerBoltSprite(task->tSpriteId);
        task->tState = PIKABOLT_TASK_IDLE;
        task->tAnimating = 0;
    }
}

static void PikaPowerBolt_ClearAll(struct Task *task)
{
    s16 r5 = task->tNumBolts + 2;
    s16 r3 = 0;
    s16 r2 = 3;
    if (task->tNumBolts == 1)
        r3 = 1, r2 = 1;
    else if (task->tNumBolts == 16)
        r3 = 2, r2 = 2;
    if (task->tTimer == 0)
    {
        sSelectedPikaPowerTile[r2] = sPikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, r5 + 0x40);
        task->tNumBolts--;
    }
    if (++task->tTimer >= 20)
        task->tTimer = 0;
    if (task->tNumBolts == 0)
    {
        task->tState = PIKABOLT_TASK_IDLE;
        task->tAnimating = 0;
    }
}

static void ResetPikaPowerBoltTask(struct Task *task)
{
    u8 i;

    for (i = 2; i < NUM_TASK_DATA; i++)
        task->data[i] = 0;
}

static void LoadPikaPowerMeter(u8 bolts)
{
    s16 i;
    s16 r3 = 0, r1 = 0;
    s16 r4 = 3;
    for (i = 0; i < bolts; i++, r4++)
    {
        r3 = 0, r1 = 0;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15) // meter is full
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = sPikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, r4 + 0x40);
    }
    for (; i < 16; i++, r4++)
    {
        r3 = 0, r1 = 3;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15)
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = sPikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, r4 + 0x40);
    }
    gTasks[sSlotMachine->pikaPowerBoltTaskId].data[1] = bolts;
}

#undef tState
#undef tNumBolts
#undef tSpriteId
#undef tTimer
#undef tAnimating

#define tState         data[0]
#define tReelSpeed     data[1]
#define tTimer3        data[2]
#define tRtReelSpeed   data[4]
#define tTimer2        data[4]
#define tTimer1        data[5]
#define tExplodeChecks data[6]

static void BeginReelTime(void)
{
    u8 taskId = CreateTask(Task_ReelTime, 7);
    Task_ReelTime(taskId);
}

static bool8 IsReelTimeTaskDone(void)
{
    if (FindTaskIdByFunc(Task_ReelTime) == TAIL_SENTINEL)
        return TRUE;
    return FALSE;
}

static void Task_ReelTime(u8 taskId)
{
    sReelTimeTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void ReelTime_Init(struct Task *task)
{
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reeltimePixelOffset = 0;
    sSlotMachine->reeltimePosition = 0;
    task->tState++; // RT_TASK_WINDOW_ENTER
    task->data[1] = 0;
    task->data[2] = 30;
    task->tRtReelSpeed = 1280;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    LoadReelTimeWindowTilemap(REG_OFFSET_BG3VOFS, 0);
    CreateReelTimeMachineSprites();
    CreateReelTimePikachuSprite();
    CreateReelTimeNumberSprites();
    CreateReelTimeShadowSprites();
    CreateReelTimeNumberGapSprite();
    GetReelTimeDraw();
    StopMapMusic();
    PlayNewMapMusic(MUS_ROULETTE);
}

static void ReelTime_WindowEnter(struct Task *task)
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
        LoadReelTimeWindowTilemap(r3, task->data[3]);
    }
    if (task->data[1] >= 200)
    {
        task->tState++; // RT_TASK_WAIT_START_PIKA
        task->data[3] = 0;
    }
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
}

static void ReelTime_WaitStartPikachu(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    if (++task->tTimer1 >= 60)
    {
        task->tState++; // RT_TASK_PIKA_SPEEDUP1
        CreateReelTimeBoltSprites();
        CreateReelTimePikachuAuraSprites();
    }
}

static void ReelTime_PikachuSpeedUp1(struct Task *task)
{
    int i;
    u8 pikachuAnimIds[ARRAY_COUNT(sReelTimePikachuAnimIds)];
    s16 reelTimeBoltDelays[ARRAY_COUNT(sReelTimeBoltDelays)];
    s16 pikachuAuraFlashDelays[ARRAY_COUNT(sPikachuAuraFlashDelays)];

    memcpy(pikachuAnimIds, sReelTimePikachuAnimIds, sizeof(sReelTimePikachuAnimIds));
    memcpy(reelTimeBoltDelays, sReelTimeBoltDelays, sizeof(sReelTimeBoltDelays));
    memcpy(pikachuAuraFlashDelays, sPikachuAuraFlashDelays, sizeof(sPikachuAuraFlashDelays));

    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    // gradually slow down the reel
    task->tRtReelSpeed -= 4;
    i = 4 - (task->tRtReelSpeed >> 8);
    SetReelTimeBoltDelay(reelTimeBoltDelays[i]);
    SetReelTimePikachuAuraFlashDelay(pikachuAuraFlashDelays[i]);
    StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], pikachuAnimIds[i]);
    // once speed goes below 256, go to next ReelTime task and keep the speed level
    if (task->tRtReelSpeed <= 0x100)
    {
        task->tState++; // RT_TASK_PIKA_SPEEDUP2
        task->tRtReelSpeed = 0x100;
        task->tTimer1 = 0;
    }
}

static void ReelTime_PikachuSpeedUp2(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    if (++task->tTimer1 >= 80)
    {
        task->tState++; // RT_TASK_WAIT_REEL
        task->tTimer1 = 0;
        SetReelTimePikachuAuraFlashDelay(2);
        StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 3);
    }
}

static void ReelTime_WaitReel(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x80;
    if (++task->tTimer1 >= 80)
    {
        task->tState++; // RT_TASK_CHECK_EXPLODE
        task->tTimer1 = 0;
    }
}

// Check whether the ReelTime machine should explode.
//
// The ReelTime machine displays 0 when this task starts. If there is a positive
// ReelTime draw, the machine keeps spinning until it lands on that number.
//
// Otherwise, it checks every 40 frames whether it should explode. If so, it
// explodes immediately. After 4 checks, the machine won't explode but continues
// to spin until it lands on 0.
static void ReelTime_CheckExplode(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    if (++task->tTimer1 >= 40)
    {
        task->tTimer1 = 0;
        if (sSlotMachine->reelTimeDraw)
        {
            if (sSlotMachine->reelTimeSpinsLeft <= task->tExplodeChecks)
                task->tState++; // RT_TASK_LAND
        }
        else if (task->tExplodeChecks > 3)
        {
            task->tState++; // RT_TASK_LAND
        }
        else if (ShouldReelTimeMachineExplode(task->tExplodeChecks))
        {
            task->tState = RT_TASK_EXPLODE;
        }
        task->tExplodeChecks++;
    }
}

// Reel spins until it lands on the selected outcome.
static void ReelTime_LandOnOutcome(struct Task *task)
{
    s16 reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
    if (reeltimePixelOffset)
    {
        reeltimePixelOffset = AdvanceReeltimeReelToNextSymbol(task->tRtReelSpeed >> 8);
        task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    }
    else if (GetReelTimeSymbol(1) != sSlotMachine->reelTimeDraw)
    {
        AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
        reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
        task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    }
    if (reeltimePixelOffset == 0 && GetReelTimeSymbol(1) == sSlotMachine->reelTimeDraw)
    {
        task->tRtReelSpeed = 0; // Also initializes task->tTimer2
        task->tState++; // RT_TASK_PIKA_REACT
    }
}

// Animate Pikachu reaction. Clear any power bolts the player may have won if
// they got a positive ReelTime draw.
static void ReelTime_PikachuReact(struct Task *task)
{
    if (++task->tTimer2 >= 60)
    {
        StopMapMusic();
        DestroyReelTimeBoltSprites();
        DestroyReelTimePikachuAuraSprites();
        task->tState++; // RT_TASK_WAIT_CLEAR_POWER
        if(sSlotMachine->reelTimeDraw == 0)
        {
            task->tTimer2 = 0xa0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 5);
            PlayFanfare(MUS_TOO_BAD);
        }
        else
        {
            task->tTimer2 = 0xc0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 4);
            gSprites[sSlotMachine->reelTimePikachuSpriteId].animCmdIndex = 0;
            if (sSlotMachine->pikaPowerBolts)
            {
                ResetPikaPowerBolts();
                sSlotMachine->pikaPowerBolts = 0;
            }
            PlayFanfare(MUS_SLOTS_WIN);
        }
    }
}

static void ReelTime_WaitClearPikaPower(struct Task *task)
{
    if ((task->tTimer2 == 0 || --task->tTimer2 == 0) && !IsPikaPowerBoltAnimating())
        task->tState++; // RT_TASK_CLOSE_WINDOW_SUCCESS
}

static void ReelTime_CloseWindow(struct Task *task)
{
    s16 r4;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    task->data[3] += 8;
    r4 = ((task->data[1] - 8) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (task->data[3] >> 3 <= 25)
        ClearReelTimeWindowTilemap(r4);
    else
        task->tState++; // RT_TASK_DESTROY_SPRITES
}

// Destroy sprites and wrap up the ReelTime task.
//
// If the player got a positive ReelTime draw, select the speed that the slot
// reels will initially move at.
static void ReelTime_DestroySprites(struct Task *task)
{
    sSlotMachine->reelTimeSpinsUsed = 0;
    sSlotMachine->reelTimeSpinsLeft = sSlotMachine->reelTimeDraw;
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    sSlotMachine->reelSpeed = REEL_NORMAL_SPEED;
    DestroyReelTimePikachuSprite();
    DestroyReelTimeMachineSprites();
    DestroyReelTimeShadowSprites();
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        DestroyTask(FindTaskIdByFunc(Task_ReelTime));
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
        task->tReelSpeed = ReelTimeSpeed();
        task->tTimer3 = 0;
        task->data[3] = 0;
        task->tState++; // RT_TASK_SET_REEL_SPEED
    }
}

// Slow the slot reels down until they match the selected speed.
static void ReelTime_SetReelSpeed(struct Task *task)
{
    if (sSlotMachine->reelSpeed == task->tReelSpeed)
        task->tState++; // RT_TASK_END_SUCCESS
    else if (sSlotMachine->reelPixelOffsets[0] % REEL_SYMBOL_HEIGHT == 0 && (++task->tTimer3 & 0x07) == 0)
        sSlotMachine->reelSpeed >>= 1;
}

static void ReelTime_EndSuccess(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
        DestroyTask(FindTaskIdByFunc(Task_ReelTime));
}

static void ReelTime_ExplodeMachine(struct Task *task)
{
    DestroyReelTimeMachineSprites();
    DestroyReelTimeBoltSprites();
    DestroyReelTimePikachuAuraSprites();
    CreateReelTimeExplosionSprite();
    gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = TRUE;
    StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 5);
    task->tState++; // RT_TASK_WAIT_EXPLODE
    task->data[4] = 4;
    task->tTimer1 = 0;
    StopMapMusic();
    PlayFanfare(MUS_TOO_BAD);
    PlaySE(SE_M_EXPLOSION);
}

static void ReelTime_WaitExplode(struct Task *task)
{
    gSpriteCoordOffsetY = task->data[4];
    SetGpuReg(REG_OFFSET_BG1VOFS, task->data[4]);
    if (task->tTimer1 & 0x01)
        task->data[4] = -task->data[4];
    if ((++task->tTimer1 & 0x1f) == 0)
        task->data[4] >>= 1;
    if (task->data[4] == 0)
    {
        DestroyReelTimeExplosionSprite();
        CreateReelTimeDuckSprites();
        CreateBrokenReelTimeMachineSprite();
        CreateReelTimeSmokeSprite();
        gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = FALSE;
        task->tState++; // RT_TASK_WAIT_SMOKE
        task->tTimer1 = 0;
    }
}

static void ReelTime_WaitSmoke(struct Task *task)
{
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    if (IsReelTimeSmokeAnimFinished())
    {
        task->tState++; // RT_TASK_CLOSE_WINDOW_FAILURE
        DestroyReelTimeSmokeSprite();
    }
}

static void ReelTime_EndFailure(struct Task *task)
{
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    DestroyReelTimePikachuSprite();
    DestroyBrokenReelTimeMachineSprite();
    DestroyReelTimeShadowSprites();
    DestroyReelTimeDuckSprites();
    DestroyTask(FindTaskIdByFunc(Task_ReelTime));
}

static void LoadReelTimeWindowTilemap(s16 a0, s16 a1)
{
    s16 i;
    for (i = 4; i < 15; i++)
        LoadBgTilemap(1, &sReelTimeWindow_Tilemap[a1 + (i - 4) * 20], 2, 32 * i + a0);
}

static void ClearReelTimeWindowTilemap(s16 a0)
{
    u8 i;
    for (i = 4; i < 15; i++)
        LoadBgTilemap(1, sEmptyTilemap, 2, 32 * i + a0);
}

#undef tState
#undef tReelSpeed
#undef tRtReelSpeed
#undef tTimer2
#undef tTimer1
#undef tExplodeChecks

#define tState data[0]

// Info Box is the screen shown when Select is pressed
static void OpenInfoBox(u8 digDisplayId)
{
    u8 taskId = CreateTask(Task_InfoBox, 1);
    gTasks[taskId].data[1] = digDisplayId;
    Task_InfoBox(taskId);
}

static bool8 IsInfoBoxClosed(void)
{
    if (FindTaskIdByFunc(Task_InfoBox) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_InfoBox(u8 taskId)
{
    sInfoBoxTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void InfoBox_FadeIn(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    task->tState++;
}

static void InfoBox_WaitFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->tState++;
}

static void InfoBox_DrawWindow(struct Task *task)
{
    DestroyDigitalDisplayScene();
    LoadInfoBoxTilemap();
    AddWindow(&sWindowTemplate_InfoBox);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    task->tState++;
}

static void InfoBox_AddText(struct Task *task)
{
    AddTextPrinterParameterized3(1, FONT_NORMAL, 2, 5, sColors_ReeltimeHelp, 0, gText_ReelTimeHelp);
    CopyWindowToVram(1, COPYWIN_FULL);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    task->tState++;
}

static void InfoBox_WaitInput(struct Task *task)
{
    if (JOY_NEW(B_BUTTON | SELECT_BUTTON))
    {
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        ClearWindowTilemap(1);
        CopyWindowToVram(1, COPYWIN_MAP);
        RemoveWindow(1);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        task->tState++;
    }
}

static void InfoBox_LoadSlotMachineTilemap(struct Task *task)
{
    LoadSlotMachineMenuTilemap();
    ShowBg(3);
    task->tState++;
}

static void InfoBox_CreateDigitalDisplay(struct Task *task)
{
    CreateDigitalDisplayScene(task->data[1]);
    task->tState++;
}

static void InfoBox_LoadPikaPowerMeter(struct Task *task)
{
    LoadPikaPowerMeter(sSlotMachine->pikaPowerBolts);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    task->tState++;
}

static void InfoBox_FreeTask(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(Task_InfoBox));
}

#undef tState

#define sWaitForAnim data[7]

static void CreateDigitalDisplayTask(void)
{
    u8 i;
    struct Task *task;
    i = CreateTask(Task_DigitalDisplay, 3);
    sSlotMachine->digDisplayTaskId = i;
    task = &gTasks[i];
    task->data[1] = -1;
    for (i = 4; i < NUM_TASK_DATA; i++)
        task->data[i] = MAX_SPRITES;
}

// For the panel on the right side of the slot screen
static void CreateDigitalDisplayScene(u8 id)
{
    u8 i;
    struct Task *task;

    DestroyDigitalDisplayScene();

    task = &gTasks[sSlotMachine->digDisplayTaskId];
    task->data[1] = id;

    for (i = 0; sDigitalDisplayScenes[id][i].spriteTemplateId != 255; i++)
    {
        u8 spriteId;
        spriteId = CreateStdDigitalDisplaySprite(
                sDigitalDisplayScenes[id][i].spriteTemplateId,
                sDigitalDisplayScenes[id][i].dispInfoId,
                sDigitalDisplayScenes[id][i].spriteId
        );
        task->data[4 + i] = spriteId;
    }
}

static void AddDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 spriteId)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];
    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] == MAX_SPRITES)
        {
            task->data[i] = CreateDigitalDisplaySprite(templateIdx, callback, x, y, spriteId);
            break;
        }
    }
}

static void DestroyDigitalDisplayScene(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];

    if ((u16)task->data[1] != 0xFFFF)
        sDigitalDisplaySceneExitCallbacks[task->data[1]]();

    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[task->data[i]]);
            task->data[i] = MAX_SPRITES;
        }
    }
}

static bool8 IsDigitalDisplayAnimFinished(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];
    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            if (gSprites[task->data[i]].sWaitForAnim)
                return FALSE;
        }
    }
    return TRUE;
}

static void Task_DigitalDisplay(u8 taskId)
{
    sDigitalDisplayTasks[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void DigitalDisplay_Idle(struct Task *task)
{
}

static void CreateReelSymbolSprites(void)
{
    s16 i;
    s16 j;
    s16 x;
    for (i = 0, x = 0x30; i < 3; i++, x += 0x28)
    {
        for (j = 0; j < 120; j += 24)
        {
            struct Sprite *sprite = gSprites + CreateSprite(&sSpriteTemplate_ReelSymbol, x, 0, 14);
            sprite->oam.priority = 3;
            sprite->data[0] = i;
            sprite->data[1] = j;
            sprite->data[3] = -1;
        }
    }
}

static void SpriteCB_ReelSymbol(struct Sprite *sprite)
{
    sprite->data[2] = sSlotMachine->reelPixelOffsets[sprite->data[0]] + sprite->data[1];
    sprite->data[2] %= 120;
    sprite->y = sSlotMachine->reelShockOffsets[sprite->data[0]] + 28 + sprite->data[2];
    sprite->sheetTileStart = GetSpriteTileStartByTag(GetSymbolAtRest(sprite->data[0], sprite->data[2] / 24));
    SetSpriteSheetFrameTileNum(sprite);
}

static void CreateCreditPayoutNumberSprites(void)
{
    s16 i;
    s16 x;

    // Credit number sprite
    for (x = 203, i = 1; i <= MAX_COINS; i *= 10, x -= 7)
        CreateCoinNumberSprite(x, 23, FALSE, i);

    // Payout number sprite
    for (x = 235, i = 1; i <= MAX_COINS; i *= 10, x -= 7)
        CreateCoinNumberSprite(x, 23, TRUE, i);
}

#define sIsPayout data[0]
#define sDigitMin data[1]
#define sDigitMax data[2]
#define sCurNum   data[3] // Only used to determine whether the sprite has already been updated to show the correct digit

static void CreateCoinNumberSprite(s16 x, s16 y, bool8 isPayout, s16 digitMult)
{
    struct Sprite *sprite = &gSprites[CreateSprite(&sSpriteTemplate_CoinNumber, x, y, 13)];
    sprite->oam.priority = 2;
    sprite->sIsPayout = isPayout;
    sprite->sDigitMin = digitMult;
    sprite->sDigitMax = digitMult * 10;
    sprite->sCurNum = -1;
}

static void SpriteCB_CoinNumber(struct Sprite *sprite)
{
    u16 tag = sSlotMachine->coins;
    if (sprite->sIsPayout)
        tag = sSlotMachine->payout;
    if (sprite->sCurNum != tag)
    {
        // Convert total to current digit
        sprite->sCurNum = tag;
        tag %= (u16)sprite->sDigitMax;
        tag /= (u16)sprite->sDigitMin;

        tag += GFXTAG_NUM_0;
        sprite->sheetTileStart = GetSpriteTileStartByTag(tag);
        SetSpriteSheetFrameTileNum(sprite);
    }
}

#undef sIsPayout
#undef sDigitMin
#undef sDigitMax
#undef sCurNum

static void CreateReelBackgroundSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelBackground, 88, 72, 15);
    gSprites[spriteId].oam.priority = 3;
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_ReelBackground);
}

static void CreateReelTimePikachuSprite(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    if (sImageTable_ReelTimePikachu == NULL)
        sImageTable_ReelTimePikachu = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);

    sImageTable_ReelTimePikachu[0].data = sReelTimeGfxPtr + (0 * 0x800);
    sImageTable_ReelTimePikachu[0].size = 0x800;
    sImageTable_ReelTimePikachu[1].data = sReelTimeGfxPtr + (1 * 0x800);
    sImageTable_ReelTimePikachu[1].size = 0x800;
    sImageTable_ReelTimePikachu[2].data = sReelTimeGfxPtr + (2 * 0x800);
    sImageTable_ReelTimePikachu[2].size = 0x800;
    sImageTable_ReelTimePikachu[3].data = sReelTimeGfxPtr + (3 * 0x800);
    sImageTable_ReelTimePikachu[3].size = 0x800;
    sImageTable_ReelTimePikachu[4].data = sReelTimeGfxPtr + (4 * 0x800);
    sImageTable_ReelTimePikachu[4].size = 0x800;

    spriteTemplate = sSpriteTemplate_ReelTimePikachu;
    spriteTemplate.images = sImageTable_ReelTimePikachu;
    spriteId = CreateSprite(&spriteTemplate, 280, 80, 1);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    sSlotMachine->reelTimePikachuSpriteId = spriteId;
}

static void DestroyReelTimePikachuSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimePikachuSpriteId]);
    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
}

static void SpriteCB_ReelTimePikachu(struct Sprite *sprite)
{
    sprite->y2 = sprite->x2 = 0;
    if (sprite->animNum == 4)
    {
        sprite->y2 = sprite->x2 = 8;
        if ((sprite->animCmdIndex != 0 && sprite->animDelayCounter != 0) || (sprite->animCmdIndex == 0 && sprite->animDelayCounter == 0))
            sprite->y2 = -8;
    }
}

static void CreateReelTimeMachineSprites(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sImageTable_ReelTimeMachineAntennae == NULL)
        sImageTable_ReelTimeMachineAntennae = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_ReelTimeMachineAntennae[0].data = sReelTimeGfxPtr + 0x2800;
    sImageTable_ReelTimeMachineAntennae[0].size = 0x300;
    spriteTemplate = sSpriteTemplate_ReelTimeMachineAntennae;
    spriteTemplate.images = sImageTable_ReelTimeMachineAntennae;
    spriteId = CreateSprite(&spriteTemplate, 368, 52, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeMachineAntennae);
    sSlotMachine->reelTimeMachineSpriteIds[0] = spriteId;

    if (sImageTable_ReelTimeMachine == NULL)
        sImageTable_ReelTimeMachine = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_ReelTimeMachine[0].data = sReelTimeGfxPtr + 0x2800 + 0x300;
    sImageTable_ReelTimeMachine[0].size = 0x500;
    spriteTemplate = sSpriteTemplate_ReelTimeMachine;
    spriteTemplate.images = sImageTable_ReelTimeMachine;
    spriteId = CreateSprite(&spriteTemplate, 368, 84, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeMachine);
    sSlotMachine->reelTimeMachineSpriteIds[1] = spriteId;
}

static void CreateBrokenReelTimeMachineSprite(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sImageTable_BrokenReelTimeMachine == NULL)
        sImageTable_BrokenReelTimeMachine = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_BrokenReelTimeMachine[0].data = sReelTimeGfxPtr + 0x3000;
    sImageTable_BrokenReelTimeMachine[0].size = 0x600;
    spriteTemplate = sSpriteTemplate_BrokenReelTimeMachine;
    spriteTemplate.images = sImageTable_BrokenReelTimeMachine;
    spriteId = CreateSprite(&spriteTemplate, 168 - gSpriteCoordOffsetX, 80, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_BrokenReelTimeMachine);
    sSlotMachine->reelTimeBrokenMachineSpriteId = spriteId;
}

static void CreateReelTimeNumberSprites(void)
{
    u8 i;
    s16 r5;
    for (i = 0, r5 = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeNumberSpriteIds); i++, r5 += 20)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeNumbers, 368, 0, 10);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[7] = r5;
        sSlotMachine->reelTimeNumberSpriteIds[i] = spriteId;
    }
}

static void SpriteCB_ReelTimeNumbers(struct Sprite *sprite)
{
    s16 r0 = (u16)(sSlotMachine->reeltimePixelOffset + sprite->data[7]);
    r0 %= 40;
    sprite->y = r0 + 59;
    StartSpriteAnimIfDifferent(sprite, GetReelTimeSymbol(r0 / 20));
}

static void CreateReelTimeShadowSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 368, 100, 9);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[0] = spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 288, 104, 4);
    sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[1] = spriteId;
}

// Creates a small black bar on the Reel Time machine to fill the gap between the numbers
static void CreateReelTimeNumberGapSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeNumberGap, 368, 76, 11);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeNumberGap);
    sSlotMachine->reelTimeNumberGapSpriteId = spriteId;
}

static void DestroyReelTimeMachineSprites(void)
{
    u8 i;

    DestroySprite(&gSprites[sSlotMachine->reelTimeNumberGapSpriteId]);
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeMachineSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeMachineSpriteIds[i]]);

    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeNumberSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeNumberSpriteIds[i]]);
}

static void DestroyReelTimeShadowSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeShadowSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeShadowSpriteIds[i]]);
}

static void DestroyBrokenReelTimeMachineSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimeBrokenMachineSpriteId]);
    TRY_FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
}

#define sDelayTimer data[0]
#define sXDir       data[1]
#define sYDir       data[2]
#define sCounter    data[3]
#define sDelay      data[7]

static void CreateReelTimeBoltSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 152, 32, 5);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->hFlip = TRUE;
    sSlotMachine->reelTimeBoltSpriteIds[0] = spriteId;
    sprite->sDelayTimer = 8;
    sprite->sXDir = -1;
    sprite->sYDir = -1;
    sprite->sDelay = 32;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 184, 32, 5);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sSlotMachine->reelTimeBoltSpriteIds[1] = spriteId;
    sprite->sXDir = 1;
    sprite->sYDir = -1;
    sprite->sDelay = 32;
}

static void SpriteCB_ReelTimeBolt(struct Sprite *sprite)
{
    if (sprite->sDelayTimer != 0)
    {
        sprite->sDelayTimer--;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x2 += sprite->sXDir;
        sprite->y2 += sprite->sYDir;
        if (++sprite->sCounter >= 8)
        {
            sprite->sDelayTimer = sprite->sDelay;
            sprite->sCounter = 0;
        }
    }
}

static void SetReelTimeBoltDelay(s16 delay)
{
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[0]].sDelay = delay;
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[1]].sDelay = delay;
}

static void DestroyReelTimeBoltSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeBoltSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeBoltSpriteIds[i]]);
}

#undef sDelayTimer
#undef sXDir
#undef sYDir
#undef sCounter
#undef sDelay

#define sFlashPal   data[0]
#define sColorIdx   data[5]
#define sDelayTimer data[6]
#define sDelay      data[7]

static void CreateReelTimePikachuAuraSprites(void)
{
    // Left half of electricity orb
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 72, 80, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].sFlashPal = TRUE; // Only one of them needs to do the flashing, they share the palette
    gSprites[spriteId].sColorIdx = 0;
    gSprites[spriteId].sDelayTimer = 16;
    gSprites[spriteId].sDelay = 8;
    sSlotMachine->reelTimePikachuAuraSpriteIds[0] = spriteId;

    // Right half
    spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 104, 80, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].hFlip = TRUE;
    sSlotMachine->reelTimePikachuAuraSpriteIds[1] = spriteId;
}

static void SpriteCB_ReelTimePikachuAura(struct Sprite *sprite)
{
    u8 colors[] = {16, 0};
    if (sprite->sFlashPal && --sprite->sDelayTimer <= 0)
    {
        MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_PIKA_AURA)) + 3, colors[sprite->sColorIdx], colors[sprite->sColorIdx], colors[sprite->sColorIdx]);
        ++sprite->sColorIdx;
        sprite->sColorIdx &= 1;
        sprite->sDelayTimer = sprite->sDelay;
    }
}

static void SetReelTimePikachuAuraFlashDelay(s16 delay)
{
    gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[0]].sDelay = delay;
}

static void DestroyReelTimePikachuAuraSprites(void)
{
    u8 i;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_PIKA_AURA)) + 3, 0, 0, 0);
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimePikachuAuraSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[i]]);
}

#undef sFlashPal
#undef sColorIdx
#undef sDelayTimer
#undef sDelay

static void CreateReelTimeExplosionSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeExplosion, 168, 80, 6);
    gSprites[spriteId].oam.priority = 1;
    sSlotMachine->reelTimeExplosionSpriteId = spriteId;
}

static void SpriteCB_ReelTimeExplosion(struct Sprite *sprite)
{
    sprite->y2 = gSpriteCoordOffsetY;
}

static void DestroyReelTimeExplosionSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimeExplosionSpriteId]);
}

// The "confusion" ducks that circle Pikachu if the Reel Time machine explodes
static void CreateReelTimeDuckSprites(void)
{
    u8 i;
    u16 sp[] = {0x0, 0x40, 0x80, 0xC0};
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeDuckSpriteIds); i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeDuck, 80 - gSpriteCoordOffsetX, 68, 0);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = sp[i];
        sSlotMachine->reelTimeDuckSpriteIds[i] = spriteId;
    }
}

static void SpriteCB_ReelTimeDuck(struct Sprite *sprite)
{
    sprite->data[0] -= 2;
    sprite->data[0] &= 0xff;
    sprite->x2 = Cos(sprite->data[0], 20);
    sprite->y2 = Sin(sprite->data[0], 6);
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

static void DestroyReelTimeDuckSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeDuckSpriteIds); i++)
    {
        DestroySprite(&gSprites[sSlotMachine->reelTimeDuckSpriteIds[i]]);
    }
}

#define sState        data[0]
#define sMoveY        data[1]
#define sTimer        data[2]
#define sAnimFinished data[7]

static void CreateReelTimeSmokeSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeSmoke, 168, 60, 8);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sSlotMachine->reelTimeSmokeSpriteId = spriteId;
}

static void SpriteCB_ReelTimeSmoke(struct Sprite *sprite)
{
    if (sprite->sState == 0)
    {
        if (sprite->affineAnimEnded)
            sprite->sState++;
    }
    else if (sprite->sState == 1)
    {
        sprite->invisible ^= 1;
        if (++sprite->sTimer >= 24)
        {
            sprite->sState++;
            sprite->sTimer = 0;
        }
    }
    else
    {
        sprite->invisible = TRUE;
        if (++sprite->sTimer >= 16)
            sprite->sAnimFinished = TRUE;
    }
    sprite->sMoveY &= 0xff;
    sprite->sMoveY += 16;
    sprite->y2 -= (sprite->sMoveY >> 8);
}

static u8 IsReelTimeSmokeAnimFinished(void)
{
    return gSprites[sSlotMachine->reelTimeSmokeSpriteId].sAnimFinished;
}

static void DestroyReelTimeSmokeSprite(void)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->reelTimeSmokeSpriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

#undef sState
#undef sMoveY
#undef sTimer
#undef sAnimFinished

static u8 CreatePikaPowerBoltSprite(s16 x, s16 y)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_PikaPowerBolt, x, y, 12);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 2;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    return spriteId;
}

static void SpriteCB_PikaPowerBolt(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        sprite->data[7] = TRUE;
}

static void DestroyPikaPowerBoltSprite(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

static u8 CreateStdDigitalDisplaySprite(u8 templateIdx, u8 dispInfoId, s16 spriteId)
{
    return CreateDigitalDisplaySprite(templateIdx, sDigitalDisplay_SpriteCallbacks[dispInfoId], sDigitalDisplay_SpriteCoords[dispInfoId][0], sDigitalDisplay_SpriteCoords[dispInfoId][1], spriteId);
}

#define sState       data[0]
#define sCounter     data[1]
#define sSpriteId    data[6]

static u8 CreateDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 internalSpriteId)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    spriteTemplate = *sSpriteTemplates_DigitalDisplay[templateIdx];
    spriteTemplate.images = sImageTables_DigitalDisplay[templateIdx];
    spriteId = CreateSprite(&spriteTemplate, x, y, 16);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 3;
    sprite->callback = callback;
    sprite->sSpriteId = internalSpriteId;
    sprite->sWaitForAnim = TRUE;
    if (sSubspriteTables_DigitalDisplay[templateIdx])
        SetSubspriteTables(sprite, sSubspriteTables_DigitalDisplay[templateIdx]);
    return spriteId;
}

static void SpriteCB_DigitalDisplay_Static(struct Sprite *sprite)
{
    sprite->sWaitForAnim = FALSE;
}

static void SpriteCB_DigitalDisplay_Smoke(struct Sprite *sprite)
{
    s16 targetX[] = {4, -4, 4, -4};
    s16 targetY[] = {4, 4, -4, -4};

    if (sprite->sCounter++ >= 16)
    {
        sprite->subspriteTableNum ^= 1;
        sprite->sCounter = 0;
    }
    sprite->x2 = 0;
    sprite->y2 = 0;
    if (sprite->subspriteTableNum != 0)
    {
        sprite->x2 = targetX[sprite->sSpriteId];
        sprite->y2 = targetY[sprite->sSpriteId];
    }
}

static void SpriteCB_DigitalDisplay_SmokeNE(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

static void SpriteCB_DigitalDisplay_SmokeSW(struct Sprite *sprite)
{
    sprite->vFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

static void SpriteCB_DigitalDisplay_SmokeSE(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sprite->vFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

// The word "Reel" in Reel Time
static void SpriteCB_DigitalDisplay_Reel(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH + 32)
            sprite->sState++;
        break;
    case 3:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

// The word "Time" in Reel Time
static void SpriteCB_DigitalDisplay_Time(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->x -= 4;
        if (sprite->x <= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x -= 4;
        if (sprite->x <= 144)
            sprite->sState++;
        break;
    case 3:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

static void SpriteCB_DigitalDisplay_ReelTimeNumber(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        StartSpriteAnim(sprite, sSlotMachine->reelTimeSpinsLeft - 1);
        sprite->sState++;
        // fallthrough
    case 1:
        if (++sprite->sCounter >= 4)
        {
            sprite->sState++;
            sprite->sCounter = 0;
        }
        break;
    case 2:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 3:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 4:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH + 8)
            sprite->sState++;
        break;
    case 5:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

static void SpriteCB_DigitalDisplay_PokeballRocking(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->animPaused = TRUE;
        sprite->sState++;
        // fallthrough
    case 1:
        sprite->y += 8;
        if (sprite->y >= 0x70)
        {
            sprite->y = 0x70;
            sprite->sCounter = 16;
            sprite->sState++;
        }
        break;
    case 2:
        if (sprite->data[2] == 0)
        {
            sprite->y -= sprite->sCounter;
            sprite->sCounter = -sprite->sCounter;
            if (++sprite->data[3] >= 2)
            {
                sprite->sCounter >>= 2;
                sprite->data[3] = 0;
                if (sprite->sCounter == 0)
                {
                    sprite->sState++;
                    sprite->sWaitForAnim = FALSE;
                    sprite->animPaused = FALSE;
                }
            }
        }
        sprite->data[2]++;
        sprite->data[2] &= 0x07;
        break;
    }
}

static void SpriteCB_DigitalDisplay_Stop(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sCounter > 8)
            sprite->sState++;
        break;
    case 1:
        sprite->y += 2;
        if (sprite->y >= 0x30)
        {
            sprite->y = 0x30;
            sprite->sState++;
            sprite->sWaitForAnim = FALSE;
        }
        break;
    }
}

static void SpriteCB_DigitalDisplay_AButtonStop(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->invisible = TRUE;
        if (++sprite->sCounter > 0x20)
        {
            sprite->sState++;
            sprite->sCounter = 5;
            sprite->oam.mosaic = TRUE;
            sprite->invisible = FALSE;
            StartSpriteAnim(sprite, 1);
            SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->sCounter << 4) | sprite->sCounter) << 8);
        }
        break;
    case 1:
        sprite->sCounter -= (sprite->data[2] >> 8);
        if (sprite->sCounter < 0)
            sprite->sCounter = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->sCounter << 4) | sprite->sCounter) << 8);
        sprite->data[2] &= 0xff;
        sprite->data[2] += 0x80;
        if (sprite->sCounter == 0)
        {
            sprite->sState++;
            sprite->sWaitForAnim = FALSE;
            sprite->oam.mosaic = FALSE;
            StartSpriteAnim(sprite, 0);
        }
        break;
    }
}

static void SpriteCB_DigitalDisplay_PokeballShining(struct Sprite *sprite)
{
    if (sprite->sCounter < 3)
    {
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
        if (++sprite->data[2] >= 4)
        {
            sprite->data[1]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
        if (++sprite->data[2] >= 25)
        {
            sprite->sCounter = 0;
            sprite->data[2] = 0;
        }
    }
    StartSpriteAnimIfDifferent(sprite, 1);
    sprite->sWaitForAnim = FALSE;
}

static void SpriteCB_DigitalDisplay_RegBonus(struct Sprite *sprite)
{
    // Elements in array correspond to R E G B O N U S
    s16 letterXOffset[] = {  0, -40,   0,   0, 48,   0,  24,   0};
    s16 letterYOffset[] = {-32,   0, -32, -48,  0, -48,   0, -48};
    s16 letterDelay[]   = { 16,  12,  16,   0,  0,   4,   8,   8};

    switch (sprite->sState)
    {
    case 0:
        sprite->x2 = letterXOffset[sprite->sSpriteId];
        sprite->y2 = letterYOffset[sprite->sSpriteId];
        sprite->sCounter = letterDelay[sprite->sSpriteId];
        sprite->sState++;
        // fallthrough
    case 1:
        if (sprite->sCounter-- == 0)
            sprite->sState++;
        break;
    case 2:
        if (sprite->x2 > 0)
            sprite->x2 -= 4;
        else if (sprite->x2 < 0)
            sprite->x2 += 4;

        if (sprite->y2 > 0)
            sprite->y2 -= 4;
        else if (sprite->y2 < 0)
            sprite->y2 += 4;

        if (sprite->x2 == 0 && sprite->y2 == 0)
            sprite->sState++;
        break;
    }
}

static void SpriteCB_DigitalDisplay_BigBonus(struct Sprite *sprite)
{
    s16 sp0[] = {160, 192, 224, 104, 80, 64, 48, 24};

    if (sprite->sState == 0)
    {
        sprite->sState++;
        sprite->sCounter = 12;
    }
    sprite->x2 = Cos(sp0[sprite->sSpriteId], sprite->sCounter);
    sprite->y2 = Sin(sp0[sprite->sSpriteId], sprite->sCounter);
    if (sprite->sCounter != 0)
        sprite->sCounter--;
}

// For the A Button prompt when inserting bet
// Initially no sprite until after the first bet
static void SpriteCB_DigitalDisplay_AButtonStart(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
        case 0:
            sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_CLR;
            sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
            sSlotMachine->win0v = WIN_RANGE(32, 136);
            sprite->invisible = TRUE;
            sprite->sState++;
            // fallthrough
        case 1:
            sprite->sCounter += 2;
            sprite->data[2] = sprite->sCounter + 176;
            sprite->data[3] = DISPLAY_WIDTH - sprite->sCounter;
            if (sprite->data[2] > 208)
                sprite->data[2] = 208;
            if (sprite->data[3] < 208)
                sprite->data[3] = 208;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->sCounter > 51)
            {
                sprite->sState++;
                sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
            }
            break;
        case 2:
            if (sSlotMachine->bet == 0)
                break;
            AddDigitalDisplaySprite(DIG_SPRITE_A_BUTTON, SpriteCallbackDummy, 208, 116, 0);
            sSlotMachine->win0h = WIN_RANGE(192, 224);
            sSlotMachine->win0v = WIN_RANGE(104, 128);
            sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_CLR;
            sprite->sState++;
            sprite->sCounter = 0;
            // fallthrough
        case 3:
            sprite->sCounter += 2;
            sprite->data[2] = sprite->sCounter + 192;
            sprite->data[3] = DISPLAY_WIDTH - 16 - sprite->sCounter;
            if (sprite->data[2] > 208)
                sprite->data[2] = 208;
            if (sprite->data[3] < 208)
                sprite->data[3] = 208;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->sCounter > 15)
            {
                sprite->sState++;
                sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
            }
            break;
    }
}

static void EndDigitalDisplayScene_Dummy(void)
{
}

static void EndDigitalDisplayScene_StopReel(void)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
}

static void EndDigitalDisplayScene_Win(void)
{
    LoadPalette(sDigitalDisplay_Pal, OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
}

static void EndDigitalDisplayScene_InsertBet(void)
{
    sSlotMachine->win0h = DISPLAY_WIDTH;
    sSlotMachine->win0v = DISPLAY_HEIGHT;
    sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
    sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
}

static void LoadSlotMachineGfx(void)
{
    u8 i;

    LoadReelBackground();
    sDigitalDisplayGfxPtr = Alloc(0x3200);
    LZDecompressWram(gSlotMachineDigitalDisplay_Gfx, sDigitalDisplayGfxPtr);
    sReelTimeGfxPtr = Alloc(0x3600);
    LZDecompressWram(sReelTimeGfx, sReelTimeGfxPtr);
    sSlotMachineSpritesheetsPtr = AllocZeroed(sizeof(struct SpriteSheet) * ARRAY_COUNT(sSlotMachineSpriteSheets));
    for (i = 0; i < ARRAY_COUNT(sSlotMachineSpriteSheets); i++)
    {
        sSlotMachineSpritesheetsPtr[i].data = sSlotMachineSpriteSheets[i].data;
        sSlotMachineSpritesheetsPtr[i].size = sSlotMachineSpriteSheets[i].size;
        sSlotMachineSpritesheetsPtr[i].tag = sSlotMachineSpriteSheets[i].tag;
    }
    sSlotMachineSpritesheetsPtr[GFXTAG_STOP - 1].data = sDigitalDisplayGfxPtr + 0xA00;
    sSlotMachineSpritesheetsPtr[GFXTAG_BONUS - 1].data = sDigitalDisplayGfxPtr + 0x1400;
    sSlotMachineSpritesheetsPtr[GFXTAG_BIG - 1].data = sDigitalDisplayGfxPtr + 0x1600;
    sSlotMachineSpritesheetsPtr[GFXTAG_REG - 1].data = sDigitalDisplayGfxPtr + 0x1900;
    LoadSpriteSheets(sSlotMachineSpritesheetsPtr);
    LoadSpritePalettes(sSlotMachineSpritePalettes);
}

static void LoadReelBackground(void)
{
    u8 *dest;
    u8 i, j;

    sReelBackgroundSpriteSheet = AllocZeroed(sizeof(struct SpriteSheet));
    sReelBackground_Gfx = AllocZeroed(0x2000); // Background is plain white
    dest = sReelBackground_Gfx;
    for (i = 0; i < 0x40; i++)
    {
        for (j = 0; j < 0x20; j++, dest++)
            *dest = sReelBackground_Tilemap[j];
    }
    sReelBackgroundSpriteSheet->data = sReelBackground_Gfx;
    sReelBackgroundSpriteSheet->size = 0x800;
    sReelBackgroundSpriteSheet->tag  = GFXTAG_REEL_BG;
    LoadSpriteSheet(sReelBackgroundSpriteSheet);
}

static void LoadMenuGfx(void)
{
    sMenuGfx = Alloc(0x2200);
    LZDecompressWram(gSlotMachineMenu_Gfx, sMenuGfx);
    LoadBgTiles(2, sMenuGfx, 0x2200, 0);
    LoadPalette(gSlotMachineMenu_Pal, BG_PLTT_ID(0), 5 * PLTT_SIZE_4BPP);
    LoadPalette(sUnkPalette, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
}

static void LoadMenuAndReelOverlayTilemaps(void)
{
    LoadSlotMachineMenuTilemap();
    LoadSlotMachineReelOverlay();
}

static void LoadSlotMachineMenuTilemap(void)
{
    LoadBgTilemap(2, gSlotMachineMenu_Tilemap, 0x500, 0);
}

static void LoadSlotMachineReelOverlay(void)
{
    s16 x, y, dx;

    for (x = 4; x < 18; x += 5)
    {
        for (dx = 0; dx < 4; dx++)
        {
            LoadBgTilemap(3, sReelOverlay_Tilemap,     2, x + dx + 5  * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 1, 2, x + dx + 13 * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 2, 2, x + dx + 6  * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 3, 2, x + dx + 12 * 32);
        }

        LoadBgTilemap(3, sReelOverlay_Tilemap + 4, 2, x + 6 * 32);
        LoadBgTilemap(3, sReelOverlay_Tilemap + 5, 2, x + 12 * 32);

        for (y = 7; y <= 11; y++)
            LoadBgTilemap(3, sReelOverlay_Tilemap + 6, 2, x + y * 32);
    }
}

// For (un)shading the gray button at the bottom of a reel when A is pressed. The button is colored in quadrants
static void SetReelButtonTilemap(s16 offset, u16 topLeft, u16 topRight, u16 bottomLeft, u16 bottomRight)
{
    sReelButtonPress_Tilemap[0] = topLeft;
    sReelButtonPress_Tilemap[1] = topRight;
    sReelButtonPress_Tilemap[2] = bottomLeft;
    sReelButtonPress_Tilemap[3] = bottomRight;

    LoadBgTilemap(2, sReelButtonPress_Tilemap,     2, 15 * 32 + offset);     // Top left
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 1, 2, 15 * 32 + 1 + offset); // Top right
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 2, 2, 16 * 32 + offset);     // Bottom left
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 3, 2, 16 * 32 + 1 + offset); // Bottom Right
}

static void LoadInfoBoxTilemap(void)
{
    LoadBgTilemap(2, gSlotMachineInfoBox_Tilemap, 0x500, 0);
    HideBg(3);
}

static void SetDigitalDisplayImagePtrs(void)
{
    sImageTables_DigitalDisplay[DIG_SPRITE_REEL]      = sImageTable_DigitalDisplay_Reel;
    sImageTables_DigitalDisplay[DIG_SPRITE_TIME]      = sImageTable_DigitalDisplay_Time;
    sImageTables_DigitalDisplay[DIG_SPRITE_INSERT]    = sImageTable_DigitalDisplay_Insert;
    sImageTables_DigitalDisplay[DIG_SPRITE_WIN]       = sImageTable_DigitalDisplay_Win;
    sImageTables_DigitalDisplay[DIG_SPRITE_LOSE]      = sImageTable_DigitalDisplay_Lose;
    sImageTables_DigitalDisplay[DIG_SPRITE_A_BUTTON]  = sImageTable_DigitalDisplay_AButton;
    sImageTables_DigitalDisplay[DIG_SPRITE_SMOKE]     = sImageTable_DigitalDisplay_Smoke;
    sImageTables_DigitalDisplay[DIG_SPRITE_NUMBER]    = sImageTable_DigitalDisplay_Number;
    sImageTables_DigitalDisplay[DIG_SPRITE_POKE_BALL] = sImageTable_DigitalDisplay_Pokeball;
    sImageTables_DigitalDisplay[DIG_SPRITE_D_PAD]     = sImageTable_DigitalDisplay_DPad;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_S]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_T]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_O]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_P]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_B]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_O]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_N]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_U]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_S]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_B]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_I]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_G]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_R]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_E]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_G]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_EMPTY]     = NULL;
}

static void AllocDigitalDisplayGfx(void)
{
    sImageTable_DigitalDisplay_Reel = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Reel[0].data = sDigitalDisplayGfxPtr;
    sImageTable_DigitalDisplay_Reel[0].size = 0x600;

    sImageTable_DigitalDisplay_Time = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Time[0].data = sDigitalDisplayGfxPtr + 0x600;
    sImageTable_DigitalDisplay_Time[0].size = 0x200;

    sImageTable_DigitalDisplay_Insert = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Insert[0].data = sDigitalDisplayGfxPtr + 0x800;
    sImageTable_DigitalDisplay_Insert[0].size = 0x200;

    sImageTable_DigitalDisplay_Stop = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Stop[0].data = sDigitalDisplayGfxPtr + 0xA00;
    sImageTable_DigitalDisplay_Stop[0].size = 0x200;

    sImageTable_DigitalDisplay_Win = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Win[0].data = sDigitalDisplayGfxPtr + 0xC00;
    sImageTable_DigitalDisplay_Win[0].size = 0x300;

    sImageTable_DigitalDisplay_Lose = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Lose[0].data = sDigitalDisplayGfxPtr + 0x1000;
    sImageTable_DigitalDisplay_Lose[0].size = 0x400;

    sImageTable_DigitalDisplay_Bonus = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Bonus[0].data = sDigitalDisplayGfxPtr + 0x1400;
    sImageTable_DigitalDisplay_Bonus[0].size = 0x200;

    sImageTable_DigitalDisplay_Big = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Big[0].data = sDigitalDisplayGfxPtr + 0x1600;
    sImageTable_DigitalDisplay_Big[0].size = 0x300;

    sImageTable_DigitalDisplay_Reg = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Reg[0].data = sDigitalDisplayGfxPtr + 0x1900;
    sImageTable_DigitalDisplay_Reg[0].size = 0x300;

    sImageTable_DigitalDisplay_AButton = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_AButton[0].data = sDigitalDisplayGfxPtr + 0x1C00;
    sImageTable_DigitalDisplay_AButton[0].size = 0x200;
    sImageTable_DigitalDisplay_AButton[1].data = sDigitalDisplayGfxPtr + 0x1E00;
    sImageTable_DigitalDisplay_AButton[1].size = 0x200;

    sImageTable_DigitalDisplay_Smoke = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Smoke[0].data = sDigitalDisplayGfxPtr + 0x2000;
    sImageTable_DigitalDisplay_Smoke[0].size = 640;

    sImageTable_DigitalDisplay_Number = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);
    sImageTable_DigitalDisplay_Number[0].data = sDigitalDisplayGfxPtr + 0x2280;
    sImageTable_DigitalDisplay_Number[0].size = 0x80;
    sImageTable_DigitalDisplay_Number[1].data = sDigitalDisplayGfxPtr + 0x2300;
    sImageTable_DigitalDisplay_Number[1].size = 0x80;
    sImageTable_DigitalDisplay_Number[2].data = sDigitalDisplayGfxPtr + 0x2380;
    sImageTable_DigitalDisplay_Number[2].size = 0x80;
    sImageTable_DigitalDisplay_Number[3].data = sDigitalDisplayGfxPtr + 0x2400;
    sImageTable_DigitalDisplay_Number[3].size = 0x80;
    sImageTable_DigitalDisplay_Number[4].data = sDigitalDisplayGfxPtr + 0x2480;
    sImageTable_DigitalDisplay_Number[4].size = 0x80;

    sImageTable_DigitalDisplay_Pokeball = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_Pokeball[0].data = sDigitalDisplayGfxPtr + 0x2600;
    sImageTable_DigitalDisplay_Pokeball[0].size = 0x480;
    sImageTable_DigitalDisplay_Pokeball[1].data = sDigitalDisplayGfxPtr + 10880;
    sImageTable_DigitalDisplay_Pokeball[1].size = 0x480;

    sImageTable_DigitalDisplay_DPad = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_DPad[0].data = sDigitalDisplayGfxPtr + 0x2F00;
    sImageTable_DigitalDisplay_DPad[0].size = 0x180;
    sImageTable_DigitalDisplay_DPad[1].data = sDigitalDisplayGfxPtr + 0x3080;
    sImageTable_DigitalDisplay_DPad[1].size = 0x180;
}

static const u8 sReelSymbols[NUM_REELS][SYMBOLS_PER_REEL] =
{
    [LEFT_REEL] = {
        SYMBOL_7_RED,
        SYMBOL_CHERRY,
        SYMBOL_AZURILL,
        SYMBOL_REPLAY,
        SYMBOL_POWER,
        SYMBOL_LOTAD,
        SYMBOL_7_BLUE,
        SYMBOL_LOTAD,
        SYMBOL_CHERRY,
        SYMBOL_POWER,
        SYMBOL_REPLAY,
        SYMBOL_AZURILL,
        SYMBOL_7_RED,
        SYMBOL_POWER,
        SYMBOL_LOTAD,
        SYMBOL_REPLAY,
        SYMBOL_AZURILL,
        SYMBOL_7_BLUE,
        SYMBOL_POWER,
        SYMBOL_LOTAD,
        SYMBOL_REPLAY
    },
    [MIDDLE_REEL] = {
        SYMBOL_7_RED,
        SYMBOL_CHERRY,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_AZURILL,
        SYMBOL_CHERRY,
        SYMBOL_REPLAY,
        SYMBOL_POWER,
        SYMBOL_POWER,
        SYMBOL_LOTAD,
        SYMBOL_7_BLUE,
        SYMBOL_LOTAD,
        SYMBOL_REPLAY,
        SYMBOL_CHERRY,
        SYMBOL_AZURILL,
        SYMBOL_LOTAD,
        SYMBOL_REPLAY,
        SYMBOL_CHERRY,
        SYMBOL_LOTAD,
        SYMBOL_REPLAY,
        SYMBOL_CHERRY
    },
    [RIGHT_REEL] = {
        SYMBOL_7_RED,
        SYMBOL_POWER,
        SYMBOL_7_BLUE,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_AZURILL,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_POWER,
        SYMBOL_AZURILL,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_AZURILL,
        SYMBOL_POWER,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_AZURILL,
        SYMBOL_POWER,
        SYMBOL_REPLAY,
        SYMBOL_LOTAD,
        SYMBOL_CHERRY
    },
};

static const u8 sReelTimeSymbols[] = {
    1, 0, 5, 4, 3, 2
};

// Column 0: Normal game
// Column 1: Lucky game
static const s16 sInitialReelPositions[NUM_REELS][2] = {
    [LEFT_REEL]   = {0,  6},
    [MIDDLE_REEL] = {0, 10},
    [RIGHT_REEL]  = {0,  2}
};

static const u8 sSpecialDrawOdds[NUM_SLOT_MACHINE_IDS][MAX_BET] = {
    [SLOT_MACHINE_UNLUCKIEST] = {1, 1, 12},
    [SLOT_MACHINE_UNLUCKIER]  = {1, 1, 14},
    [SLOT_MACHINE_UNLUCKY]    = {2, 2, 14},
    [SLOT_MACHINE_LUCKY]      = {2, 2, 14},
    [SLOT_MACHINE_LUCKIER]    = {2, 3, 16},
    [SLOT_MACHINE_LUCKIEST]   = {3, 3, 16}
};

static const u8 sBiasProbabilities_Special[][NUM_SLOT_MACHINE_IDS] = {
    {
        // Probabilities for BIAS_STRAIGHT_7
        [SLOT_MACHINE_UNLUCKIEST] = 25,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 30,
        [SLOT_MACHINE_LUCKY]      = 40,
        [SLOT_MACHINE_LUCKIER]    = 40,
        [SLOT_MACHINE_LUCKIEST]   = 50
    },
    {
        // Probabilities for BIAS_REELTIME
        [SLOT_MACHINE_UNLUCKIEST] = 25,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 30,
        [SLOT_MACHINE_LUCKY]      = 30,
        [SLOT_MACHINE_LUCKIER]    = 35,
        [SLOT_MACHINE_LUCKIEST]   = 35
    },
    {
        // Probabilities for BIAS_MIXED_7
        [SLOT_MACHINE_UNLUCKIEST] = 25,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 30,
        [SLOT_MACHINE_LUCKY]      = 25,
        [SLOT_MACHINE_LUCKIER]    = 25,
        [SLOT_MACHINE_LUCKIEST]   = 30
    }
};

static const u8 sBiasProbabilities_Regular[][NUM_SLOT_MACHINE_IDS] = {
    {
        // Probabilities for BIAS_POWER
        [SLOT_MACHINE_UNLUCKIEST] = 20,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 25,
        [SLOT_MACHINE_LUCKY]      = 20,
        [SLOT_MACHINE_LUCKIER]    = 25,
        [SLOT_MACHINE_LUCKIEST]   = 25
    },
    {
        // Probabilities for BIAS_AZURILL
        [SLOT_MACHINE_UNLUCKIEST] = 12,
        [SLOT_MACHINE_UNLUCKIER]  = 15,
        [SLOT_MACHINE_UNLUCKY]    = 15,
        [SLOT_MACHINE_LUCKY]      = 18,
        [SLOT_MACHINE_LUCKIER]    = 19,
        [SLOT_MACHINE_LUCKIEST]   = 22
    },
    {
        // Probabilities for BIAS_LOTAD
        [SLOT_MACHINE_UNLUCKIEST] = 25,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 25,
        [SLOT_MACHINE_LUCKY]      = 30,
        [SLOT_MACHINE_LUCKIER]    = 30,
        [SLOT_MACHINE_LUCKIEST]   = 40
    },
    {
        // Probabilities for BIAS_CHERRY
        [SLOT_MACHINE_UNLUCKIEST] = 25,
        [SLOT_MACHINE_UNLUCKIER]  = 25,
        [SLOT_MACHINE_UNLUCKY]    = 20,
        [SLOT_MACHINE_LUCKY]      = 20,
        [SLOT_MACHINE_LUCKIER]    = 15,
        [SLOT_MACHINE_LUCKIEST]   = 15
    },
    {
        // Probabilities for BIAS_REPLAY
        [SLOT_MACHINE_UNLUCKIEST] = 40,
        [SLOT_MACHINE_UNLUCKIER]  = 40,
        [SLOT_MACHINE_UNLUCKY]    = 35,
        [SLOT_MACHINE_LUCKY]      = 35,
        [SLOT_MACHINE_LUCKIER]    = 40,
        [SLOT_MACHINE_LUCKIEST]   = 40
    }
};

// INTENTION:
//   As you get more Power bolts, the odds of getting higher yields (3+ spins)
//   increases modestly. There's a high chance of getting at least 1 spin, which
//   will clear your Power bolts.
//
// NOTE: The way these probabilities are drawn significantly skews the odds
//       toward drawing 0 spins:
//
//       | Up to N bolts | Prob intended | Prob actual |
//       |---------------|---------------|-------------|
//       |  2            | 94%           | 99%         |
//       |  6            | 31%           | 57%         |
//       | 12            | 16%           | 44%         |
//       | 15            |  2%           | 31%         |
//       | 16            |  2%           | 31%         |
static const u8 sReelTimeProbabilities_NormalGame[][17] = {
    {243, 243, 243,  80,  80,  80,  80,  40,  40,  40,  40,  40,  40,   5,   5,   5,   5},  // 0 spins
    {  5,   5,   5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100,   5},  // 1 spin
    {  4,   4,   4,  20,  20,  20,  20,  80,  80,  80,  80,  80,  80, 100, 100, 100,  40},  // 2 spins
    {  2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  45,  45,  45, 100},  // 3 spins
    {  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   5,   5,   5, 100},  // 4 spins
    {  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   6}   // 5 spins
};

// INTENTION:
//   As you get more Power bolts, the odds of getting higher yields (3+ spins)
//   increases substantially. There is always a high chance of getting no spins,
//   which lets you keep your Power bolts.
//
// NOTE: The way these probabilities are drawn significantly skews the odds
//       toward drawing 0 spins:
//
//       | Up to N bolts | Prob intended | Prob actual |
//       |---------------|---------------|-------------|
//       |  2            | 94%           | 99%         |
//       |  6            | 78%           | 96%         |
//       | 12            | 63%           | 88%         |
//       | 15            | 27%           | 58%         |
//       | 16            |  2%           | 33%         |
static const u8 sReelTimeProbabilities_LuckyGame[][17] = {
    { 243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160,  70,  70,  70,   5},  // 0 spins
    {   5,   5,   5,  25,  25,  25,  25,   5,   5,   5,   5,   5,   5,   2,   2,   2,   6},  // 1 spin
    {   4,   4,   4,  25,  25,  25,  25,  30,  30,  30,  30,  30,  30,  40,  40,  40,  35},  // 2 spins
    {   2,   2,   2,   3,   3,   3,   3,  30,  30,  30,  30,  30,  30, 100, 100, 100,  50},  // 3 spins
    {   1,   1,   1,   2,   2,   2,   2,  30,  30,  30,  30,  30,  30,  40,  40,  40, 100},  // 4 spins
    {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   4,  60}   // 5 spins
};

static const u16 sReelTimeExplodeProbability[] = {
    128, 175, 200, 225, 256
};

// Column 0: Probability of half-speed
// Column 1: Base probability of quarter-speed
static const u16 sReelTimeSpeed_Probabilities[][2] = {
    {10,  5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35}
};

// Boosted odds of quarter speed during ReelTime
static const u16 sQuarterSpeed_ProbabilityBoost[] = {
    0, 5, 10, 15, 20
};

static const u8 sBiasSymbols[] = {
  SYMBOL_REPLAY,  // BIAS_REPLAY
  SYMBOL_CHERRY,  // BIAS_CHERRY
  SYMBOL_LOTAD,   // BIAS_LOTAD
  SYMBOL_AZURILL, // BIAS_AZURILL
  SYMBOL_POWER,   // BIAS_POWER
  SYMBOL_7_RED,   // BIAS_REELTIME
  SYMBOL_7_RED,   // BIAS_MIXED_7
  SYMBOL_7_RED    // BIAS_STRAIGHT_7
};

static const u16 sBiasesSpecial[] = {
    BIAS_STRAIGHT_7, BIAS_REELTIME, BIAS_MIXED_7
};

static const u16 sBiasesRegular[] = {
    BIAS_POWER, BIAS_AZURILL, BIAS_LOTAD, BIAS_CHERRY, BIAS_REPLAY
};

static const u8 sSymbolToMatch[] = {
    [SYMBOL_7_RED]   = MATCH_RED_7,
    [SYMBOL_7_BLUE]  = MATCH_BLUE_7,
    [SYMBOL_AZURILL] = MATCH_AZURILL,
    [SYMBOL_LOTAD]   = MATCH_LOTAD,
    [SYMBOL_CHERRY]  = MATCH_CHERRY,
    [SYMBOL_POWER]   = MATCH_POWER,
    [SYMBOL_REPLAY]  = MATCH_REPLAY
};

static const u16 sSlotMatchFlags[] = {
    [MATCH_CHERRY]        = 1 << MATCH_CHERRY,
    [MATCH_TOPBOT_CHERRY] = 1 << MATCH_TOPBOT_CHERRY,
    [MATCH_REPLAY]        = 1 << MATCH_REPLAY,
    [MATCH_LOTAD]         = 1 << MATCH_LOTAD,
    [MATCH_AZURILL]       = 1 << MATCH_AZURILL,
    [MATCH_POWER]         = 1 << MATCH_POWER,
    [MATCH_MIXED_7]       = 1 << MATCH_MIXED_7,
    [MATCH_RED_7]         = 1 << MATCH_RED_7,
    [MATCH_BLUE_7]        = 1 << MATCH_BLUE_7
};

static const u16 sSlotPayouts[] = {
    [MATCH_CHERRY]        = 2,
    [MATCH_TOPBOT_CHERRY] = 4,
    [MATCH_REPLAY]        = 0,
    [MATCH_LOTAD]         = 6,
    [MATCH_AZURILL]       = 12,
    [MATCH_POWER]         = 3,
    [MATCH_MIXED_7]       = 90,
    [MATCH_RED_7]         = 300,
    [MATCH_BLUE_7]        = 300
};

static const s16 sDigitalDisplay_SpriteCoords[][2] = {
    [DIG_DISPINFO_INSERT] = { 208, 56},
    [DIG_DISPINFO_STOP_S] = { 184,  0},
    [DIG_DISPINFO_STOP_T] = { 200,  8},
    [DIG_DISPINFO_STOP_O] = { 216, 16},
    [DIG_DISPINFO_STOP_P] = { 232, 24},
    [DIG_DISPINFO_A_BUTTON_STOP] = { 208, 72},
    [DIG_DISPINFO_POKE_BALL_ROCKING] = { 208, 8},
    [DIG_DISPINFO_WIN] = { 208, 64},
    [DIG_DISPINFO_LOSE] = { 208, 56},
    [DIG_DISPINFO_SMOKE_NW] = { 192,  88},
    [DIG_DISPINFO_SMOKE_NE] = { 224,  88},
    [DIG_DISPINFO_SMOKE_SW] = { 192, 120},
    [DIG_DISPINFO_SMOKE_SE] = { 224, 120},
    [DIG_DISPINFO_REEL] = { 144, 56},
    [DIG_DISPINFO_TIME] = { 272, 88},
    [DIG_DISPINFO_NUMBER] = { 168, 112},
    [DIG_DISPINFO_DPAD] = { 208, 84},
    [DIG_DISPINFO_POKE_BALL_SHINING] = { 208, 112},
    [DIG_DISPINFO_REG_R] = { 188, 52},
    [DIG_DISPINFO_REG_E] = { 208, 52},
    [DIG_DISPINFO_REG_G] = { 228, 52},
    [DIG_DISPINFO_REG_BONUS_B] = { 184, 72},
    [DIG_DISPINFO_REG_BONUS_O] = { 196, 72},
    [DIG_DISPINFO_REG_BONUS_N] = { 208, 72},
    [DIG_DISPINFO_REG_BONUS_U] = { 220, 72},
    [DIG_DISPINFO_REG_BONUS_S] = { 232, 72},
    [DIG_DISPINFO_BIG_B] = { 188, 52},
    [DIG_DISPINFO_BIG_I] = { 208, 52},
    [DIG_DISPINFO_BIG_G] = { 228, 52},
    [DIG_DISPINFO_BIG_BONUS_B] = { 184, 72},
    [DIG_DISPINFO_BIG_BONUS_O] = { 196, 72},
    [DIG_DISPINFO_BIG_BONUS_N] = { 208, 72},
    [DIG_DISPINFO_BIG_BONUS_U] = { 220, 72},
    [DIG_DISPINFO_BIG_BONUS_S] = { 232, 72},
    [DIG_DISPINFO_A_BUTTON_START] = { 0, 0} // Initially offscreen
};

static const SpriteCallback sDigitalDisplay_SpriteCallbacks[] = {
    [DIG_DISPINFO_INSERT]            = SpriteCB_DigitalDisplay_Static,
    [DIG_DISPINFO_STOP_S]            = SpriteCB_DigitalDisplay_Stop,
    [DIG_DISPINFO_STOP_T]            = SpriteCB_DigitalDisplay_Stop,
    [DIG_DISPINFO_STOP_O]            = SpriteCB_DigitalDisplay_Stop,
    [DIG_DISPINFO_STOP_P]            = SpriteCB_DigitalDisplay_Stop,
    [DIG_DISPINFO_A_BUTTON_STOP]     = SpriteCB_DigitalDisplay_AButtonStop,
    [DIG_DISPINFO_POKE_BALL_ROCKING] = SpriteCB_DigitalDisplay_PokeballRocking,
    [DIG_DISPINFO_WIN]               = SpriteCB_DigitalDisplay_Static,
    [DIG_DISPINFO_LOSE]              = SpriteCB_DigitalDisplay_Static,
    [DIG_DISPINFO_SMOKE_NW]          = SpriteCB_DigitalDisplay_Smoke,
    [DIG_DISPINFO_SMOKE_NE]          = SpriteCB_DigitalDisplay_SmokeNE,
    [DIG_DISPINFO_SMOKE_SW]          = SpriteCB_DigitalDisplay_SmokeSW,
    [DIG_DISPINFO_SMOKE_SE]          = SpriteCB_DigitalDisplay_SmokeSE,
    [DIG_DISPINFO_REEL]              = SpriteCB_DigitalDisplay_Reel,
    [DIG_DISPINFO_TIME]              = SpriteCB_DigitalDisplay_Time,
    [DIG_DISPINFO_NUMBER]            = SpriteCB_DigitalDisplay_ReelTimeNumber,
    [DIG_DISPINFO_DPAD]              = SpriteCB_DigitalDisplay_Static,
    [DIG_DISPINFO_POKE_BALL_SHINING] = SpriteCB_DigitalDisplay_PokeballShining,
    [DIG_DISPINFO_REG_R]             = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_E]             = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_G]             = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_BONUS_B]       = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_BONUS_O]       = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_BONUS_N]       = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_BONUS_U]       = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_REG_BONUS_S]       = SpriteCB_DigitalDisplay_RegBonus,
    [DIG_DISPINFO_BIG_B]             = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_I]             = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_G]             = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_BONUS_B]       = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_BONUS_O]       = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_BONUS_N]       = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_BONUS_U]       = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_BIG_BONUS_S]       = SpriteCB_DigitalDisplay_BigBonus,
    [DIG_DISPINFO_A_BUTTON_START]    = SpriteCB_DigitalDisplay_AButtonStart
};

static const struct DigitalDisplaySprite sDigitalDisplay_InsertBet[] = {
    {DIG_SPRITE_EMPTY, DIG_DISPINFO_A_BUTTON_START, 0}, // Sprite replaced with DIG_SPRITE_A_BUTTON after first bet
    {DIG_SPRITE_INSERT, DIG_DISPINFO_INSERT, 0},
    {DIG_SPRITE_D_PAD, DIG_DISPINFO_DPAD, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_StopReel[] = {
    {DIG_SPRITE_STOP_S, DIG_DISPINFO_STOP_S, 0},
    {DIG_SPRITE_STOP_T, DIG_DISPINFO_STOP_T, 0},
    {DIG_SPRITE_STOP_O, DIG_DISPINFO_STOP_O, 0},
    {DIG_SPRITE_STOP_P, DIG_DISPINFO_STOP_P, 0},
    {DIG_SPRITE_A_BUTTON, DIG_DISPINFO_A_BUTTON_STOP, 0},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_ROCKING, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_Win[] = {
    {DIG_SPRITE_WIN, DIG_DISPINFO_WIN, 0},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_Lose[] = {
    {DIG_SPRITE_LOSE, DIG_DISPINFO_LOSE, 0},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_NW, 0},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_NE, 1},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_SW, 2},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_SE, 3},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_ReelTime[] = {
    {DIG_SPRITE_REEL, DIG_DISPINFO_REEL, 0},
    {DIG_SPRITE_TIME, DIG_DISPINFO_TIME, 0},
    {DIG_SPRITE_NUMBER, DIG_DISPINFO_NUMBER, 0}, // Number of reel time spins left
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_BonusBig[] = {
    {DIG_SPRITE_BIG_B, DIG_DISPINFO_BIG_B, 0},
    {DIG_SPRITE_BIG_I, DIG_DISPINFO_BIG_I, 1},
    {DIG_SPRITE_BIG_G, DIG_DISPINFO_BIG_G, 2},
    {DIG_SPRITE_BONUS_B, DIG_DISPINFO_BIG_BONUS_B, 3},
    {DIG_SPRITE_BONUS_O, DIG_DISPINFO_BIG_BONUS_O, 4},
    {DIG_SPRITE_BONUS_N, DIG_DISPINFO_BIG_BONUS_N, 5},
    {DIG_SPRITE_BONUS_U, DIG_DISPINFO_BIG_BONUS_U, 6},
    {DIG_SPRITE_BONUS_S, DIG_DISPINFO_BIG_BONUS_S, 7},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_BonusRegular[] = {
    {DIG_SPRITE_REG_R, DIG_DISPINFO_REG_R, 0},
    {DIG_SPRITE_REG_E, DIG_DISPINFO_REG_E, 1},
    {DIG_SPRITE_REG_G, DIG_DISPINFO_REG_G, 2},
    {DIG_SPRITE_BONUS_B, DIG_DISPINFO_REG_BONUS_B, 3},
    {DIG_SPRITE_BONUS_O, DIG_DISPINFO_REG_BONUS_O, 4},
    {DIG_SPRITE_BONUS_N, DIG_DISPINFO_REG_BONUS_N, 5},
    {DIG_SPRITE_BONUS_U, DIG_DISPINFO_REG_BONUS_U, 6},
    {DIG_SPRITE_BONUS_S, DIG_DISPINFO_REG_BONUS_S, 7},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite *const sDigitalDisplayScenes[] = {
    [DIG_DISPLAY_INSERT_BET] = sDigitalDisplay_InsertBet,
    [DIG_DISPLAY_STOP_REEL]  = sDigitalDisplay_StopReel,
    [DIG_DISPLAY_WIN]        = sDigitalDisplay_Win,
    [DIG_DISPLAY_LOSE]       = sDigitalDisplay_Lose,
    [DIG_DISPLAY_REEL_TIME]  = sDigitalDisplay_ReelTime,
    [DIG_DISPLAY_BONUS_REG]  = sDigitalDisplay_BonusRegular,
    [DIG_DISPLAY_BONUS_BIG]  = sDigitalDisplay_BonusBig
};

static void (*const sDigitalDisplaySceneExitCallbacks[])(void) = {
    [DIG_DISPLAY_INSERT_BET] = EndDigitalDisplayScene_InsertBet,
    [DIG_DISPLAY_STOP_REEL]  = EndDigitalDisplayScene_StopReel,
    [DIG_DISPLAY_WIN]        = EndDigitalDisplayScene_Win,
    [DIG_DISPLAY_LOSE]       = EndDigitalDisplayScene_Dummy,
    [DIG_DISPLAY_REEL_TIME]  = EndDigitalDisplayScene_Dummy,
    [DIG_DISPLAY_BONUS_REG]  = EndDigitalDisplayScene_Win,
    [DIG_DISPLAY_BONUS_BIG]  = EndDigitalDisplayScene_Win
};

static const struct OamData sOam_8x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_8x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_16x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_32x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_32x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sImageTable_ReelTimeNumbers[] =
{
    { gSlotMachineReelTimeNumber0, 0x80 },
    { gSlotMachineReelTimeNumber1, 0x80 },
    { gSlotMachineReelTimeNumber2, 0x80 },
    { gSlotMachineReelTimeNumber3, 0x80 },
    { gSlotMachineReelTimeNumber4, 0x80 },
    { gSlotMachineReelTimeNumber5, 0x80 },
};

static const struct SpriteFrameImage sImageTable_ReelTimeShadow[] = { gSlotMachineReelTimeShadow, 0x200 };
static const struct SpriteFrameImage sImageTable_ReelTimeNumberGap[] = { gSlotMachineReelTimeNumberGap_Gfx, 0x40 };

static const struct SpriteFrameImage sImageTable_ReelTimeBolt[] =
{
    { gSlotMachineReelTimeBolt0, 0x100 },
    { gSlotMachineReelTimeBolt1, 0x100 },
};

static const struct SpriteFrameImage sImageTable_ReelTimePikachuAura[] = { gSlotMachineReelTimePikaAura, 0x400 };

static const struct SpriteFrameImage sImageTable_ReelTimeExplosion[] =
{
    { gSlotMachineReelTimeExplosion0, 0x200 },
    { gSlotMachineReelTimeExplosion1, 0x200 },
};

static const struct SpriteFrameImage sImageTable_ReelTimeDuck[] = { gSlotMachineReelTimeDuck, 0x20};
static const struct SpriteFrameImage sImageTable_ReelTimeSmoke[] = { gSlotMachineReelTimeSmoke, 0x80};
static const struct SpriteFrameImage sImageTable_PikaPowerBolt[] = { gSlotMachinePikaPowerBolt, 0x20};

static const union AnimCmd sAnim_SingleFrame[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeDuck[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimePikachu_Still[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimePikachu_ChargingSlow[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimePikachu_ChargingMedium[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimePikachu_ChargingFast[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimePikachu_Cheering[] =
{
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_FRAME(3, 32),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimePikachu_FellOver[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_1[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_2[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_3[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_4[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ReelTimeNumber_5[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END
};


static const union AnimCmd sAnim_ReelTimeBolt[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_ReelTimeExplosion[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DigitalDisplay_AButton_Flashing[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DigitalDisplay_AButton_Static[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_DPad_Flashing[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DigitalDisplay_Pokeball_Rocking[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_DigitalDisplay_Pokeball_Static[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_Number_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_Number_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_Number_3[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_Number_4[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_DigitalDisplay_Number_5[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_SingleFrame[] =
{
    sAnim_SingleFrame
};

static const union AnimCmd *const sAnims_ReelTimeDuck[] =
{
    sAnim_ReelTimeDuck
};

static const union AnimCmd *const sAnims_ReelTimePikachu[] =
{
    sAnim_ReelTimePikachu_Still,
    sAnim_ReelTimePikachu_ChargingSlow,
    sAnim_ReelTimePikachu_ChargingMedium,
    sAnim_ReelTimePikachu_ChargingFast,
    sAnim_ReelTimePikachu_Cheering,
    sAnim_ReelTimePikachu_FellOver
};

static const union AnimCmd *const sAnims_ReelTimeNumbers[] =
{
    sAnim_ReelTimeNumber_0,
    sAnim_ReelTimeNumber_1,
    sAnim_ReelTimeNumber_2,
    sAnim_ReelTimeNumber_3,
    sAnim_ReelTimeNumber_4,
    sAnim_ReelTimeNumber_5
};

static const union AnimCmd *const sAnims_ReelTimeBolt[] =
{
    sAnim_ReelTimeBolt
};

static const union AnimCmd *const sAnims_ReelTimeExplosion[] =
{
    sAnim_ReelTimeExplosion
};

static const union AnimCmd *const sAnims_DigitalDisplay_AButton[] =
{
    sAnim_DigitalDisplay_AButton_Flashing,
    sAnim_DigitalDisplay_AButton_Static
};

static const union AnimCmd *const sAnims_DigitalDisplay_DPad[] =
{
    sAnim_DigitalDisplay_DPad_Flashing
};

static const union AnimCmd *const sAnims_DigitalDisplay_Pokeball[] =
{
    sAnim_DigitalDisplay_Pokeball_Rocking,
    sAnim_DigitalDisplay_Pokeball_Static
};

static const union AnimCmd *const sAnims_DigitalDisplay_Number[] =
{
    sAnim_DigitalDisplay_Number_1,
    sAnim_DigitalDisplay_Number_2,
    sAnim_DigitalDisplay_Number_3,
    sAnim_DigitalDisplay_Number_4,
    sAnim_DigitalDisplay_Number_5
};


static const union AffineAnimCmd sAffineAnim_ReelTimeSmoke[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_LOOP(0),
    AFFINEANIMCMD_FRAME(1, 1, 0, 1),
    AFFINEANIMCMD_LOOP(0xFF),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_ReelTimeSmoke[] =
{
    sAffineAnim_ReelTimeSmoke
};

// Spin as it appears
static const union AffineAnimCmd sAffineAnim_PikaPowerBolt[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 8, 32),
    AFFINEANIMCMD_FRAME(0, 0, 6, 32),
    AFFINEANIMCMD_FRAME(0, 0, 4, 16),
    AFFINEANIMCMD_FRAME(0, 0, 12, 2),
    AFFINEANIMCMD_FRAME(0, 0, -12, 4),
    AFFINEANIMCMD_FRAME(0, 0, 12, 2),
    AFFINEANIMCMD_FRAME(0, 0, 12, 2),
    AFFINEANIMCMD_FRAME(0, 0, -12, 4),
    AFFINEANIMCMD_FRAME(0, 0, 12, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_PikaPowerBolt[] =
{
    sAffineAnim_PikaPowerBolt
};

static const struct SpriteTemplate sSpriteTemplate_ReelSymbol =
{
    .tileTag = GFXTAG_SYMBOLS_START,
    .paletteTag = PALTAG_REEL,
    .oam = &sOam_32x32,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelSymbol
};

static const struct SpriteTemplate sSpriteTemplate_CoinNumber =
{
    .tileTag = GFXTAG_NUMBERS_START,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CoinNumber
};

static const struct SpriteTemplate sSpriteTemplate_ReelBackground =
{
    .tileTag = GFXTAG_REEL_BG,
    .paletteTag = PALTAG_REEL,
    .oam = &sOam_64x64,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachu =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_REEL_TIME_PIKACHU,
    .oam = &sOam_64x64,
    .anims = sAnims_ReelTimePikachu,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimePikachu
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_REEL_TIME_MISC,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_REEL_TIME_MACHINE,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_REEL_TIME_MACHINE,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_ReelTimeNumbers,
    .images = sImageTable_ReelTimeNumbers,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeNumbers
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeShadow,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumberGap =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeNumberGap,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x32,
    .anims = sAnims_ReelTimeBolt,
    .images = sImageTable_ReelTimeBolt,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeBolt
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_PIKA_AURA,
    .oam = &sOam_32x64,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimePikachuAura,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimePikachuAura
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_EXPLOSION,
    .oam = &sOam_32x32,
    .anims = sAnims_ReelTimeExplosion,
    .images = sImageTable_ReelTimeExplosion,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeExplosion
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_8x8,
    .anims = sAnims_ReelTimeDuck,
    .images = sImageTable_ReelTimeDuck,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeDuck
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeSmoke,
    .affineAnims = sAffineAnims_ReelTimeSmoke,
    .callback = SpriteCB_ReelTimeSmoke
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reel =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Time =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Insert =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Stop =
{
    .tileTag = GFXTAG_STOP,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Win =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_64x32,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Lose =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_64x32,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Bonus =
{
    .tileTag = GFXTAG_BONUS,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Big =
{
    .tileTag = GFXTAG_BIG,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reg =
{
    .tileTag = GFXTAG_REG,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_AButton =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_32x32,
    .anims = sAnims_DigitalDisplay_AButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Smoke =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Number =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_16x16,
    .anims = sAnims_DigitalDisplay_Number,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Pokeball =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_DigitalDisplay_Pokeball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_DPad =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_DigitalDisplay_DPad,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_PikaPowerBolt,
    .affineAnims = sAffineAnims_PikaPowerBolt,
    .callback = SpriteCB_PikaPowerBolt
};

/*
[0             ][1             ]
[              ][              ]
[              ][              ]
[              ][              ]
[              ][              ]
[______________][______________]   128x128
[              ]+ <- Origin    ]
[              ][              ]
[              ][              ]
[              ][              ]
[              ][              ]
[2             ][3             ]
*/
static const struct Subsprite sSubsprites_ReelBackground[] =
{
    {
        .x = -64,
        .y = -64,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -64,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = -64,
        .y = 0,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(64x64),
        .size = SPRITE_SIZE(64x64),
        .tileOffset = 0,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_ReelBackground[] =
{
    ARRAY_COUNT(sSubsprites_ReelBackground), sSubsprites_ReelBackground
};

/*      v-- Origin on 3
[0_____][1_____]
[2_____][3_____]   64x24
[4     ][5     ]
*/
static const struct Subsprite sSubsprites_ReelTimeMachineAntennae[] =
{
    {
        .x = -32,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = 0,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1,
    },
    {
        .x = -32,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1,
    },
    {
        .x = 0,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1,
    },
    {
        .x = -32,
        .y = 4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 1,
    },
    {
        .x = 0,
        .y = 4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 1
    }
};

static const struct SubspriteTable sSubspriteTable_ReelTimeMachineAntennae[] =
{
    ARRAY_COUNT(sSubsprites_ReelTimeMachineAntennae), sSubsprites_ReelTimeMachineAntennae
};

/*
[0             ]
[              ]
[      + Origin]
[______________]   64x40
[1     ][2     ]
*/
static const struct Subsprite sSubsprites_ReelTimeMachine[] =
{
    {
        .x = -32,
        .y = -20,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = -32,
        .y = 12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 1,
    },
    {
        .x = 0,
        .y = 12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 1,
    }
};

static const struct SubspriteTable sSubspriteTable_ReelTimeMachine[] =
{
    ARRAY_COUNT(sSubsprites_ReelTimeMachine), sSubsprites_ReelTimeMachine
};

/*
[0             ]
[              ]
[      + Origin]
[______________]   64x48
[1     ][2     ]
[3     ][4     ]
*/
static const struct Subsprite sSubsprites_BrokenReelTimeMachine[] =
{
    {
        .x = -32,
        .y = -24,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = -32,
        .y = 8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 1,
    },
    {
        .x = 0,
        .y = 8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 1,
    },
    {
        .x = -32,
        .y = 16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 1,
    },
    {
        .x = 0,
        .y = 16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 1,
    }
};

static const struct SubspriteTable sSubspriteTable_BrokenReelTimeMachine[] =
{
    ARRAY_COUNT(sSubsprites_BrokenReelTimeMachine), sSubsprites_BrokenReelTimeMachine
};

/*      v-- Origin on 3
[0_____][1_____]
[2     ][3     ]   64x16
*/
static const struct Subsprite sSubsprites_ReelTimeShadow[] =
{
    {
        .x = -32,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = 0,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1,
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 1,
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 1,
    }
};

static const struct SubspriteTable sSubspriteTable_ReelTimeShadow[] =
{
    ARRAY_COUNT(sSubsprites_ReelTimeShadow), sSubsprites_ReelTimeShadow
};

/*
[0_]    16x24
[1+] <--Origin
[2_]
*/
static const struct Subsprite sSubsprites_ReelTimeNumberGap[] =
{
    {
        .x = -8,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = -8,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 1,
    },
    {
        .x = -8,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 1,
    }
};

static const struct SubspriteTable sSubspriteTable_ReelTimeNumberGap[] =
{
    ARRAY_COUNT(sSubsprites_ReelTimeNumberGap), sSubsprites_ReelTimeNumberGap
};

/*
[0             ]
[              ]
[      + Origin]
[______________]   64x48
[1     ][2     ]
[3     ][4     ]
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Reel[] =
{
    {
        .x = -32,
        .y = -24,
        .shape = SPRITE_SHAPE(64x32),
        .size = SPRITE_SIZE(64x32),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 32,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 36,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 40,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 44,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Reel[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Reel), sSubsprites_DigitalDisplay_Reel
};

/*      v-- Origin on 3
[0_____][1_____]
[2     ][3     ]   64x16
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Time[] =
{
    {
        .x = -32,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Time[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Time), sSubsprites_DigitalDisplay_Time
};

/*      v-- Origin on 3
[0_____][1_____]
[2     ][3     ]   64x16
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Insert[] =
{
    {
        .x = -32,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Insert[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Insert), sSubsprites_DigitalDisplay_Insert
};

/*      v-- Origin on 3
[0_____][1_____]
[2     ][3     ]   64x16
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Unused1[] =
{
    {
        .x = -32,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Unused1[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Unused1), sSubsprites_DigitalDisplay_Unused1
};

/*      v-- Origin on 3
[0_____][1_____]
[2_____][3_____]
[4     ][5     ]   64x24
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Win[] =
{
    {
        .x = -32,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -12,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -32,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 0,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3,
    },
    {
        .x = -32,
        .y = 4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 16,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 20,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Win[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Win), sSubsprites_DigitalDisplay_Win
};

static const struct Subsprite sSubsprites_DigitalDisplay_Smoke[] =
{
    {
        .x = -16,
        .y = -16,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .tileOffset = 0,
        .priority = 3,
    }
};

static const struct Subsprite sSubsprites_DigitalDisplay_Unused2[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 16,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Smoke[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Smoke), sSubsprites_DigitalDisplay_Smoke
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Unused2[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Unused2), sSubsprites_DigitalDisplay_Unused2
};

/*
[0_____][1_]
[2_____][3_]
[4_____][5_]
[6_____][7+] <-- Origin
[8_____][9_]
[10____][11]
*/
static const struct Subsprite sSubsprites_DigitalDisplay_Pokeball[] =
{
    {
        .x = -24,
        .y = -24,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 8,
        .y = -24,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -24,
        .y = -16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 6,
        .priority = 3,
    },
    {
        .x = 8,
        .y = -16,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 10,
        .priority = 3,
    },
    {
        .x = -24,
        .y = -8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 12,
        .priority = 3,
    },
    {
        .x = 8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 16,
        .priority = 3,
    },
    {
        .x = -24,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 18,
        .priority = 3,
    },
    {
        .x = 8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 22,
        .priority = 3,
    },
    {
        .x = -24,
        .y = 8,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 24,
        .priority = 3,
    },
    {
        .x = 8,
        .y = 8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 28,
        .priority = 3,
    },
    {
        .x = -24,
        .y = 16,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 30,
        .priority = 3,
    },
    {
        .x = 8,
        .y = 16,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 34,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_Pokeball[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_Pokeball), sSubsprites_DigitalDisplay_Pokeball
};

/*
[0     ]   32x24
[   +  ] <- Origin
[1 ][2 ]
*/
static const struct Subsprite sSubsprites_DigitalDisplay_DPad[] =
{
    {
        .x = -16,
        .y = -12,
        .shape = SPRITE_SHAPE(32x16),
        .size = SPRITE_SIZE(32x16),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = -16,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 0,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 10,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_DPad[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_DPad), sSubsprites_DigitalDisplay_DPad
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_StopS[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_StopS[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_StopS), sSubsprites_DigitalDisplay_StopS
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_StopT[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 2,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 10,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_StopT[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_StopT), sSubsprites_DigitalDisplay_StopT
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_StopO[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 4,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 12,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_StopO[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_StopO), sSubsprites_DigitalDisplay_StopO
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_StopP[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 6,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 14,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_StopP[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_StopP), sSubsprites_DigitalDisplay_StopP
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BonusB[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BonusB[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BonusB), sSubsprites_DigitalDisplay_BonusB
};

/*
[]<-0   16x16
[]<-1 <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BonusO[] =
{
    {
        .x = -4,
        .y = -8,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 2,
        .priority = 3,
    },
    {
        .x = -4,
        .y = 0,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BonusO[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BonusO), sSubsprites_DigitalDisplay_BonusO
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BonusN[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 3,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 11,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BonusN[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BonusN), sSubsprites_DigitalDisplay_BonusN
};

/*
[]<-0   16x16
[]<-1 <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BonusU[] =
{
    {
        .x = -4,
        .y = -8,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 5,
        .priority = 3,
    },
    {
        .x = -4,
        .y = 0,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 13,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BonusU[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BonusU), sSubsprites_DigitalDisplay_BonusU
};

/*
[0 ]   16x16
[1+] <- Origin
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BonusS[] =
{
    {
        .x = -8,
        .y = -8,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 6,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 0,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 14,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BonusS[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BonusS), sSubsprites_DigitalDisplay_BonusS
};

/*
[0_][] <-1
[2_][] <-3
[4_][] <-5
    ^-- Origin on 3
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BigB[] =
{
    {
        .x = -12,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 2,
        .priority = 3,
    },
    {
        .x = -12,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 3,
    },
    {
        .x = -12,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 16,
        .priority = 3,
    },
    {
        .x = 4,
        .y = 4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 18,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BigB[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BigB), sSubsprites_DigitalDisplay_BigB
};

/*
[0_]    16x24
[1+] <--Origin
[2_]
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BigI[] =
{
    {
        .x = -8,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 3,
        .priority = 3,
    },
    {
        .x = -8,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 11,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BigI[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BigI), sSubsprites_DigitalDisplay_BigI
};

/*
[0_][] <-1
[2_][] <-3
[4_][] <-5
    ^-- Origin on 3
*/
static const struct Subsprite sSubsprites_DigitalDisplay_BigG[] =
{
    {
        .x = -12,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 5,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 7,
        .priority = 3,
    },
    {
        .x = -12,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 13,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 15,
        .priority = 3,
    },
    {
        .x = -12,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 21,
        .priority = 3,
    },
    {
        .x = 4,
        .y = 4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 23,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_BigG[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_BigG), sSubsprites_DigitalDisplay_BigG
};

/*
[0_][] <-1
[2_][] <-3
[4_][] <-5
    ^-- Origin on 3
*/
static const struct Subsprite sSubsprites_DigitalDisplay_RegR[] =
{
    {
        .x = -12,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 2,
        .priority = 3,
    },
    {
        .x = -12,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 8,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 10,
        .priority = 3,
    },
    {
        .x = -12,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 16,
        .priority = 3,
    },
    {
        .x = 4,
        .y = 4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 18,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_RegR[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_RegR), sSubsprites_DigitalDisplay_RegR
};

/*
[0_]    16x24
[1+] <--Origin
[2_]
*/
static const struct Subsprite sSubsprites_DigitalDisplay_RegE[] =
{
    {
        .x = -8,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 3,
        .priority = 3,
    },
    {
        .x = -8,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 11,
        .priority = 3,
    },
    {
        .x = -8,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 19,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_RegE[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_RegE), sSubsprites_DigitalDisplay_RegE
};

/*
[0_][] <-1
[2_][] <-3
[4_][] <-5
    ^-- Origin on 3
*/
static const struct Subsprite sSubsprites_DigitalDisplay_RegG[] =
{
    {
        .x = -12,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 5,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -12,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 7,
        .priority = 3,
    },
    {
        .x = -12,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 13,
        .priority = 3,
    },
    {
        .x = 4,
        .y = -4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 15,
        .priority = 3,
    },
    {
        .x = -12,
        .y = 4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 21,
        .priority = 3,
    },
    {
        .x = 4,
        .y = 4,
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .tileOffset = 23,
        .priority = 3,
    }
};

static const struct SubspriteTable sSubspriteTable_DigitalDisplay_RegG[] =
{
    ARRAY_COUNT(sSubsprites_DigitalDisplay_RegG), sSubsprites_DigitalDisplay_RegG
};

static const struct SpriteTemplate *const sSpriteTemplates_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES] =
{
    [DIG_SPRITE_REEL]      = &sSpriteTemplate_DigitalDisplay_Reel,
    [DIG_SPRITE_TIME]      = &sSpriteTemplate_DigitalDisplay_Time,
    [DIG_SPRITE_INSERT]    = &sSpriteTemplate_DigitalDisplay_Insert,
    [DIG_SPRITE_WIN]       = &sSpriteTemplate_DigitalDisplay_Win,
    [DIG_SPRITE_LOSE]      = &sSpriteTemplate_DigitalDisplay_Lose,
    [DIG_SPRITE_A_BUTTON]  = &sSpriteTemplate_DigitalDisplay_AButton,
    [DIG_SPRITE_SMOKE]     = &sSpriteTemplate_DigitalDisplay_Smoke,
    [DIG_SPRITE_NUMBER]    = &sSpriteTemplate_DigitalDisplay_Number,
    [DIG_SPRITE_POKE_BALL] = &sSpriteTemplate_DigitalDisplay_Pokeball,
    [DIG_SPRITE_D_PAD]     = &sSpriteTemplate_DigitalDisplay_DPad,
    [DIG_SPRITE_STOP_S]    = &sSpriteTemplate_DigitalDisplay_Stop,
    [DIG_SPRITE_STOP_T]    = &sSpriteTemplate_DigitalDisplay_Stop,
    [DIG_SPRITE_STOP_O]    = &sSpriteTemplate_DigitalDisplay_Stop,
    [DIG_SPRITE_STOP_P]    = &sSpriteTemplate_DigitalDisplay_Stop,
    [DIG_SPRITE_BONUS_B]   = &sSpriteTemplate_DigitalDisplay_Bonus,
    [DIG_SPRITE_BONUS_O]   = &sSpriteTemplate_DigitalDisplay_Bonus,
    [DIG_SPRITE_BONUS_N]   = &sSpriteTemplate_DigitalDisplay_Bonus,
    [DIG_SPRITE_BONUS_U]   = &sSpriteTemplate_DigitalDisplay_Bonus,
    [DIG_SPRITE_BONUS_S]   = &sSpriteTemplate_DigitalDisplay_Bonus,
    [DIG_SPRITE_BIG_B]     = &sSpriteTemplate_DigitalDisplay_Big,
    [DIG_SPRITE_BIG_I]     = &sSpriteTemplate_DigitalDisplay_Big,
    [DIG_SPRITE_BIG_G]     = &sSpriteTemplate_DigitalDisplay_Big,
    [DIG_SPRITE_REG_R]     = &sSpriteTemplate_DigitalDisplay_Reg,
    [DIG_SPRITE_REG_E]     = &sSpriteTemplate_DigitalDisplay_Reg,
    [DIG_SPRITE_REG_G]     = &sSpriteTemplate_DigitalDisplay_Reg,
    [DIG_SPRITE_EMPTY]     = &gDummySpriteTemplate
};

static const struct SubspriteTable *const sSubspriteTables_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES] =
{
    [DIG_SPRITE_REEL]      = sSubspriteTable_DigitalDisplay_Reel,
    [DIG_SPRITE_TIME]      = sSubspriteTable_DigitalDisplay_Time,
    [DIG_SPRITE_INSERT]    = sSubspriteTable_DigitalDisplay_Insert,
    [DIG_SPRITE_WIN]       = sSubspriteTable_DigitalDisplay_Win,
    [DIG_SPRITE_LOSE]      = NULL,
    [DIG_SPRITE_A_BUTTON]  = NULL,
    [DIG_SPRITE_SMOKE]     = sSubspriteTable_DigitalDisplay_Smoke,
    [DIG_SPRITE_NUMBER]    = NULL,
    [DIG_SPRITE_POKE_BALL] = sSubspriteTable_DigitalDisplay_Pokeball,
    [DIG_SPRITE_D_PAD]     = sSubspriteTable_DigitalDisplay_DPad,
    [DIG_SPRITE_STOP_S]    = sSubspriteTable_DigitalDisplay_StopS,
    [DIG_SPRITE_STOP_T]    = sSubspriteTable_DigitalDisplay_StopT,
    [DIG_SPRITE_STOP_O]    = sSubspriteTable_DigitalDisplay_StopO,
    [DIG_SPRITE_STOP_P]    = sSubspriteTable_DigitalDisplay_StopP,
    [DIG_SPRITE_BONUS_B]   = sSubspriteTable_DigitalDisplay_BonusB,
    [DIG_SPRITE_BONUS_O]   = sSubspriteTable_DigitalDisplay_BonusO,
    [DIG_SPRITE_BONUS_N]   = sSubspriteTable_DigitalDisplay_BonusN,
    [DIG_SPRITE_BONUS_U]   = sSubspriteTable_DigitalDisplay_BonusU,
    [DIG_SPRITE_BONUS_S]   = sSubspriteTable_DigitalDisplay_BonusS,
    [DIG_SPRITE_BIG_B]     = sSubspriteTable_DigitalDisplay_BigB,
    [DIG_SPRITE_BIG_I]     = sSubspriteTable_DigitalDisplay_BigI,
    [DIG_SPRITE_BIG_G]     = sSubspriteTable_DigitalDisplay_BigG,
    [DIG_SPRITE_REG_R]     = sSubspriteTable_DigitalDisplay_RegR,
    [DIG_SPRITE_REG_E]     = sSubspriteTable_DigitalDisplay_RegE,
    [DIG_SPRITE_REG_G]     = sSubspriteTable_DigitalDisplay_RegG,
    [DIG_SPRITE_EMPTY]     = NULL
};

static const struct SpriteSheet sSlotMachineSpriteSheets[22] =
{
    { .data = gSlotMachineReelSymbol1Tiles, .size = 0x200, .tag = GFXTAG_7_RED },
    { .data = gSlotMachineReelSymbol2Tiles, .size = 0x200, .tag = GFXTAG_7_BLUE },
    { .data = gSlotMachineReelSymbol3Tiles, .size = 0x200, .tag = GFXTAG_AZURILL },
    { .data = gSlotMachineReelSymbol4Tiles, .size = 0x200, .tag = GFXTAG_LOTAD },
    { .data = gSlotMachineReelSymbol5Tiles, .size = 0x200, .tag = GFXTAG_CHERRY },
    { .data = gSlotMachineReelSymbol6Tiles, .size = 0x200, .tag = GFXTAG_POWER },
    { .data = gSlotMachineReelSymbol7Tiles, .size = 0x200, .tag = GFXTAG_REPLAY },
    { .data = gSlotMachineNumber0Tiles, .size = 0x40, .tag = GFXTAG_NUM_0 },
    { .data = gSlotMachineNumber1Tiles, .size = 0x40, .tag = GFXTAG_NUM_1 },
    { .data = gSlotMachineNumber2Tiles, .size = 0x40, .tag = GFXTAG_NUM_2 },
    { .data = gSlotMachineNumber3Tiles, .size = 0x40, .tag = GFXTAG_NUM_3 },
    { .data = gSlotMachineNumber4Tiles, .size = 0x40, .tag = GFXTAG_NUM_4 },
    { .data = gSlotMachineNumber5Tiles, .size = 0x40, .tag = GFXTAG_NUM_5 },
    { .data = gSlotMachineNumber6Tiles, .size = 0x40, .tag = GFXTAG_NUM_6 },
    { .data = gSlotMachineNumber7Tiles, .size = 0x40, .tag = GFXTAG_NUM_7 },
    { .data = gSlotMachineNumber8Tiles, .size = 0x40, .tag = GFXTAG_NUM_8 },
    { .data = gSlotMachineNumber9Tiles, .size = 0x40, .tag = GFXTAG_NUM_9 },
    // skips GFXTAG_REEL_BG, which has its own spritesheet
    // the data for these sheets is determined at runtime
    { .data = NULL, .size = 0x200, .tag = GFXTAG_STOP },
    { .data = NULL, .size = 0x200, .tag = GFXTAG_BONUS },
    { .data = NULL, .size = 0x300, .tag = GFXTAG_BIG },
    { .data = NULL, .size = 0x300, .tag = GFXTAG_REG },
    {},
};

static const u8 *const sReelBackground_Tilemap = gSlotMachineReelBackground_Tilemap;

static const u16 sUnusedColors[] =
{
    RGB(27, 27, 27),
    RGB(8, 11, 26),
    RGB(11, 21, 13),
    RGB_WHITE,
    RGB(16, 26, 21),
    RGB(0, 22, 31),
    RGB(26, 21, 0),
    RGB(26, 21, 0),
    RGB(29, 15, 0),
    RGB(29, 15, 0),
};

// The Bet 2 and 3 match line palettes are duplicated unnecessarily
static const u16 sMiddleRowLit_Pal[] = {RGB(17, 28, 31)};
static const u16 sTopRowLit_Pal[]  = {RGB(31, 29, 16)};
static const u16 sBottomRowt_Pal[] = {RGB(31, 29, 16)};
static const u16 sNWSEDiagLit_Pal[] = {RGB(31, 21, 18)};
static const u16 sNESWDiagLit_Pal[] = {RGB(31, 21, 18)};
static const u16 *const sLitMatchLinePalTable[NUM_MATCH_LINES] =
{
    [MATCH_MIDDLE_ROW] = sMiddleRowLit_Pal,
    [MATCH_TOP_ROW]    = sTopRowLit_Pal,
    [MATCH_BOTTOM_ROW] = sBottomRowt_Pal,
    [MATCH_NWSE_DIAG]  = sNWSEDiagLit_Pal,
    [MATCH_NESW_DIAG]  = sNESWDiagLit_Pal,
};

static const u16 *const sDarkMatchLinePalTable[NUM_MATCH_LINES] =
{
    [MATCH_MIDDLE_ROW] = &gSlotMachineMenu_Pal[BG_PLTT_ID(4) + 10],
    [MATCH_TOP_ROW]    = &gSlotMachineMenu_Pal[BG_PLTT_ID(4) + 11],
    [MATCH_BOTTOM_ROW] = &gSlotMachineMenu_Pal[BG_PLTT_ID(4) + 12],
    [MATCH_NWSE_DIAG]  = &gSlotMachineMenu_Pal[BG_PLTT_ID(4) + 13],
    [MATCH_NESW_DIAG]  = &gSlotMachineMenu_Pal[BG_PLTT_ID(4) + 14],
};

static const u8 sMatchLinePalOffsets[NUM_MATCH_LINES] = {
    [MATCH_MIDDLE_ROW] = BG_PLTT_ID(4) + 10,
    [MATCH_TOP_ROW]    = BG_PLTT_ID(4) + 11,
    [MATCH_BOTTOM_ROW] = BG_PLTT_ID(4) + 12,
    [MATCH_NWSE_DIAG]  = BG_PLTT_ID(4) + 14, // Diag colors flipped for some reason
    [MATCH_NESW_DIAG]  = BG_PLTT_ID(4) + 13  // Doesn't matter as both are identical
};

static const u8 sBetToMatchLineIds[MAX_BET][2] =
{
    {MATCH_MIDDLE_ROW, MATCH_MIDDLE_ROW}, // Bet 1
    {MATCH_TOP_ROW,    MATCH_BOTTOM_ROW}, // Bet 2
    {MATCH_NWSE_DIAG,  MATCH_NESW_DIAG},  // Bet 3
};

static const u8 sMatchLinesPerBet[MAX_BET] = { 1, 2, 2 };

// Flashing lights at top of slot machine, brightest point inside light goes from toward center of machine, to middle, to toward edges
static const u16 sFlashingLightsInside_Pal[] = INCBIN_U16("graphics/slot_machine/flashing_lights_inside.gbapal");
static const u16 sFlashingLightsMiddle_Pal[] = INCBIN_U16("graphics/slot_machine/flashing_lights_middle.gbapal");
static const u16 sFlashingLightsOutside_Pal[] = INCBIN_U16("graphics/slot_machine/flashing_lights_outside.gbapal");
static const u16 *const sFlashingLightsPalTable[] =
{
    sFlashingLightsInside_Pal,
    sFlashingLightsMiddle_Pal,
    sFlashingLightsOutside_Pal,
};

static const u16 *const sSlotMachineMenu_Pal = {gSlotMachineMenu_Pal + 16};

static const u16 sPokeballShining0_Pal[] = INCBIN_U16("graphics/slot_machine/pokeball_shining_0.gbapal");
static const u16 sPokeballShining1_Pal[] = INCBIN_U16("graphics/slot_machine/pokeball_shining_1.gbapal");
static const u16 sPokeballShining2_Pal[] = INCBIN_U16("graphics/slot_machine/pokeball_shining_2.gbapal");
static const u16 *const sPokeballShiningPalTable[] =
{
    sPokeballShining0_Pal,          // Streak on left side of ball
    sPokeballShining1_Pal,          // Streak in middle of ball
    sPokeballShining2_Pal,          // Streak on right side of ball
    gSlotMachineDigitalDisplay_Pal, // Back to normal
};

static const u16 *const sDigitalDisplay_Pal = gSlotMachineDigitalDisplay_Pal;
static const u16 sUnkPalette[16] = {
    [1] = RGB_WHITEALPHA,
    [3] = RGB(8, 8, 8),
};

static const struct SpritePalette sSlotMachineSpritePalettes[] =
{
    { .data = gSlotMachineReelSymbols_Pal,       .tag = PALTAG_REEL},
    { .data = gSlotMachineReelTimePikachu_Pal,   .tag = PALTAG_REEL_TIME_PIKACHU},
    { .data = gSlotMachineReelTimeMisc_Pal,      .tag = PALTAG_REEL_TIME_MISC},
    { .data = gSlotMachineReelTimeMachine_Pal,   .tag = PALTAG_REEL_TIME_MACHINE},
    { .data = gSlotMachineMisc_Pal,              .tag = PALTAG_MISC},
    { .data = gSlotMachineReelTimeExplosion_Pal, .tag = PALTAG_EXPLOSION},
    { .data = gSlotMachineDigitalDisplay_Pal,    .tag = PALTAG_DIG_DISPLAY},
    { .data = gSlotMachineMisc_Pal,              .tag = PALTAG_PIKA_AURA},
    {}
};

static const u32 sReelTimeGfx[] = INCBIN_U32("graphics/slot_machine/reel_time_gfx.4bpp.lz"); // reel_time_machine and reel_time_pikachu
static const u16 sReelTimeWindow_Tilemap[] = INCBIN_U16("graphics/slot_machine/reel_time_window.bin");
static const u16 sEmptyTilemap[] =  {0};
