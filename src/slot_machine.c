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

#define SYMBOLS_PER_REEL      21
#define REEL_SYMBOL_HEIGHT    24

// Lucky Flags
#define LUCKY_BIAS_REPLAY    (1 << 0)
#define LUCKY_BIAS_CHERRY    (1 << 1)
#define LUCKY_BIAS_LOTAD     (1 << 2)
#define LUCKY_BIAS_AZURILL   (1 << 3)
#define LUCKY_BIAS_POWER     (1 << 4)
#define LUCKY_BIAS_REELTIME  (1 << 5)
#define LUCKY_BIAS_MIXED_777 (1 << 6)
#define LUCKY_BIAS_777       (1 << 7)

enum {
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
    MATCHED_1CHERRY,
    MATCHED_2CHERRY,
    MATCHED_REPLAY,
    MATCHED_LOTAD,
    MATCHED_AZURILL,
    MATCHED_POWER,
    MATCHED_777_MIXED,
    MATCHED_777_RED,
    MATCHED_777_BLUE,
    MATCHED_NONE,
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
    SLOT_ACTION_UNFADE,
    SLOT_ACTION_WAIT_FADE,
    SLOT_ACTION_READY_NEW_SPIN,
    SLOT_ACTION_READY_NEW_RT_SPIN,
    SLOT_ACTION_ASK_INSERT_BET,
    SLOT_ACTION_BET_INPUT,
    SLOT_ACTION_MSG_NEED_3_COINS,
    SLOT_ACTION_WAIT_MSG_NEED_3_COINS,
    SLOT_ACTION_WAIT_INFO_BOX,
    SLOT_ACTION_START_SPIN,
    SLOT_ACTION_START_RT_SPIN,
    SLOT_ACTION_SET_LUCKY_SPINS,
    SLOT_ACTION_AWAIT_REEL_STOP,
    SLOT_ACTION_AWAIT_ALL_REELS_STOP,
    SLOT_ACTION_CHECK_MATCHES,
    SLOT_ACTION_WAIT_PAYOUT,
    SLOT_ACTION_END_PAYOUT,
    SLOT_ACTION_MATCHED_POWER,
    SLOT_ACTION_WAIT_RT_ANIM,
    SLOT_ACTION_RESET_BET_TILES,
    SLOT_ACTION_NO_MATCHES,
    SLOT_ACTION_ASK_QUIT,
    SLOT_ACTION_HANDLE_QUIT_INPUT,
    SLOT_ACTION_MSG_MAX_COINS,
    SLOT_ACTION_WAIT_MSG_MAX_COINS,
    SLOT_ACTION_MSG_NO_MORE_COINS,
    SLOT_ACTION_WAIT_MSG_NO_MORE_COINS,
    SLOT_ACTION_END,
    SLOT_ACTION_FREE,
};

enum {
    REEL_ACTION_STILL,
    REEL_ACTION_SPIN,
    REEL_ACTION_STOP,
    REEL_ACTION_STOP_MOVE,
    REEL_ACTION_STOP_SHAKE,
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

struct SlotMachine
{
    /*0x00*/ u8 state;
    /*0x01*/ u8 machineId;
    /*0x02*/ u8 pikaPower;
    /*0x03*/ u8 luckyGame;
    /*0x04*/ u8 luckyFlags;
    /*0x05*/ u8 reelTimeDraw;
    /*0x06*/ u8 isLuckySpin;
    /*0x07*/ u8 biasTag;
    /*0x08*/ u16 matchedSymbols;
    /*0x0A*/ u8 reelTimeSpinsLeft;
    /*0x0B*/ u8 reelTimeSpinsUsed;
    /*0x0C*/ s16 coins;
    /*0x0E*/ s16 payout;
    /*0x10*/ s16 netCoinLoss; // coins lost to machine (but never goes below 0)
    /*0x12*/ s16 bet;
    /*0x14*/ s16 reeltimePixelOffset;
    /*0x16*/ s16 reeltimePosition;
    /*0x18*/ s16 currReel;
    /*0x1A*/ s16 reelIncrement; // speed of reel
    /*0x1C*/ s16 reelPixelOffsets[NUM_REELS];
    /*0x22*/ u16 reelPixelOffsetsWhileStopping[NUM_REELS];
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
static void SlotMachineSetup_InitSlotMachineStruct(void);
static void SlotMachineSetup_InitPalsSpritesTasks(void);
static void SlotMachineSetup_InitTilemaps(void);
static void SlotMachineSetup_LoadGfxAndTilemaps(void);
static void SlotMachineSetup_InitVBlank(void);
static void AllocDigitalDisplayGfx(void);
static void SetDigitalDisplayImagePtrs(void);
static void CreateSlotMachineSprites(void);
static void CreateGameplayTasks(void);
static void CreateSlotMachineTask(void);
static void DestroyDigitalDisplayScene(void);
static void Task_SlotMachine(u8);
static bool8 SlotAction_UnfadeScreen(struct Task *);
static bool8 SlotAction_WaitForUnfade(struct Task *);
static bool8 SlotAction_ReadyNewSpin(struct Task *);
static bool8 SlotAction_ReadyNewReelTimeSpin(struct Task *);
static bool8 SlotAction_AskInsertBet(struct Task *);
static bool8 SlotAction_HandleBetInput(struct Task *);
static bool8 SlotAction_PrintMsg_Need3Coins(struct Task *);
static bool8 SlotAction_WaitMsg_Need3Coins(struct Task *);
static bool8 SlotAction_WaitForInfoBox(struct Task *);
static bool8 SlotAction_StartSpin(struct Task *);
static bool8 SlotAction_StartReelTimeSpin(struct Task *);
static bool8 SlotAction_SetLuckySpins(struct Task *);
static bool8 SlotAction_AwaitReelStop(struct Task *);
static bool8 SlotAction_WaitForAllReelsToStop(struct Task *);
static bool8 SlotAction_CheckMatches(struct Task *);
static bool8 SlotAction_WaitForPayoutToBeAwarded(struct Task *);
static bool8 SlotAction_EndPayout(struct Task *);
static bool8 SlotAction_MatchedPower(struct Task *);
static bool8 SlotAction_WaitReelTimeAnim(struct Task *);
static bool8 SlotAction_ResetBetTiles(struct Task *);
static bool8 SlotAction_NoMatches(struct Task *);
static bool8 SlotAction_AskQuit(struct Task *);
static bool8 SlotAction_HandleQuitInput(struct Task *);
static bool8 SlotAction_PrintMsg_9999Coins(struct Task *);
static bool8 SlotAction_WaitMsg_9999Coins(struct Task *);
static bool8 SlotAction_PrintMsg_NoMoreCoins(struct Task *);
static bool8 SlotAction_WaitMsg_NoMoreCoins(struct Task *);
static bool8 SlotAction_EndGame(struct Task *);
static bool8 SlotAction_FreeDataStructures(struct Task *);
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
static u8 GetMatchFromSymbols(u8, u8, u8);
static void AwardPayout(void);
static void RunAwardPayoutActions(u8);
static bool8 IsFinalTask_RunAwardPayoutActions(void);
static bool8 AwardPayoutAction0(struct Task *);
static bool8 AwardPayoutAction_GivePayoutToPlayer(struct Task *);
static bool8 AwardPayoutAction_FreeTask(struct Task *);
static u8 GetTagAtRest(u8, s16);
static void CreateSlotReelTasks(void);
static void SpinSlotReel(u8);
static void StopSlotReel(u8);
static bool8 IsSlotReelMoving(u8);
static void Task_RunSlotReelActions(u8);
static bool8 SlotReelAction_StayStill(struct Task *);
static bool8 SlotReelAction_Spin(struct Task *);
static bool8 SlotReelAction_DecideWhereToStop(struct Task *);
static bool8 SlotReelAction_MoveToStop(struct Task *);
static bool8 SlotReelAction_OscillatingStop(struct Task *);
static bool8 DecideReelTurns_BiasTag_Reel1(void);
static bool8 DecideReelTurns_BiasTag_Reel1_Bet1(u8, u8);
static bool8 DecideReelTurns_BiasTag_Reel1_Bet2or3(u8, u8);
static bool8 DecideReelTurns_BiasTag_Reel2(void);
static bool8 DecideReelTurns_BiasTag_Reel2_Bet1or2(void);
static bool8 DecideReelTurns_BiasTag_Reel2_Bet3(void);
static bool8 DecideReelTurns_BiasTag_Reel3(void);
static bool8 DecideReelTurns_BiasTag_Reel3_Bet1or2(u8);
static bool8 DecideReelTurns_BiasTag_Reel3_Bet3(u8);
static void DecideReelTurns_NoBiasTag_Reel1(void);
static void DecideReelTurns_NoBiasTag_Reel2(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet1(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet2(void);
static void DecideReelTurns_NoBiasTag_Reel2_Bet3(void);
static void DecideReelTurns_NoBiasTag_Reel3(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet1(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet2(void);
static void DecideReelTurns_NoBiasTag_Reel3_Bet3(void);
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
static void ReelTime_SetReelIncrement(struct Task *);
static void ReelTime_EndSuccess(struct Task *);
static void ReelTime_ExplodeMachine(struct Task *);
static void ReelTime_WaitExplode(struct Task *);
static void ReelTime_WaitSmoke(struct Task *);
static void ReelTime_EndFailure(struct Task *);
static void LoadReelTimeWindowTilemap(s16, s16);
static void ClearReelTimeWindowTilemap(s16);
static void OpenInfoBox(u8);
static bool8 IsInfoBoxClosed(void);
static void RunInfoBoxActions(u8 );
static void InfoBox_FadeIn(struct Task *);
static void InfoBox_WaitForFade(struct Task *);
static void InfoBox_DrawWindow(struct Task *);
static void InfoBox_AwaitPlayerInput(struct Task *);
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
static u8 CreateDigitalDisplaySprite(u8, void (*callback)(struct Sprite*), s16, s16, s16);
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
static const u8 sLuckyRoundProbabilities[][3];
static const u8 sBiasTags[];
static const u16 sLuckyFlagSettings_Top3[];
static const u16 sLuckyFlagSettings_NotTop3[];
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
static const u16 sReelIncrementTable[][2];
static const u16 sReelTimeBonusIncrementTable[];
static const u16 sSlotMatchFlags[];
static const u16 sSlotPayouts[];
static const u8 *const sReelBackground_Tilemap;
static const u32 sReelTimeGfx[];
static const struct SpriteSheet sSlotMachineSpriteSheets[22];
static const struct SpritePalette sSlotMachineSpritePalettes[];
static const u16 *const sDigitalDisplay_Pal;
static const s16 sInitialReelPositions[NUM_REELS][2];
static const u8 sLuckyFlagProbabilities_Top3[][6];
static const u8 sLuckyFlagProbabilities_NotTop3[][6];
static const u8 sReeltimeProbabilities_UnluckyGame[][17];
static const u8 sReelTimeProbabilities_LuckyGame[][17];
static const u8 sSymToMatch[];
static const u8 sReelTimeTags[];
static const u8 sReelSymbolTileTags[NUM_REELS][SYMBOLS_PER_REEL];
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

static bool8 (*const sSlotActions[])(struct Task *task) =
{
    [SLOT_ACTION_UNFADE]                 = SlotAction_UnfadeScreen,
    [SLOT_ACTION_WAIT_FADE]              = SlotAction_WaitForUnfade,
    [SLOT_ACTION_READY_NEW_SPIN]         = SlotAction_ReadyNewSpin,
    [SLOT_ACTION_READY_NEW_RT_SPIN]      = SlotAction_ReadyNewReelTimeSpin,
    [SLOT_ACTION_ASK_INSERT_BET]         = SlotAction_AskInsertBet,
    [SLOT_ACTION_BET_INPUT]              = SlotAction_HandleBetInput,
    [SLOT_ACTION_MSG_NEED_3_COINS]       = SlotAction_PrintMsg_Need3Coins,
    [SLOT_ACTION_WAIT_MSG_NEED_3_COINS]  = SlotAction_WaitMsg_Need3Coins,
    [SLOT_ACTION_WAIT_INFO_BOX]          = SlotAction_WaitForInfoBox,
    [SLOT_ACTION_START_SPIN]             = SlotAction_StartSpin,
    [SLOT_ACTION_START_RT_SPIN]          = SlotAction_StartReelTimeSpin,
    [SLOT_ACTION_SET_LUCKY_SPINS]        = SlotAction_SetLuckySpins,
    [SLOT_ACTION_AWAIT_REEL_STOP]        = SlotAction_AwaitReelStop,
    [SLOT_ACTION_AWAIT_ALL_REELS_STOP]   = SlotAction_WaitForAllReelsToStop,
    [SLOT_ACTION_CHECK_MATCHES]          = SlotAction_CheckMatches,
    [SLOT_ACTION_WAIT_PAYOUT]            = SlotAction_WaitForPayoutToBeAwarded,
    [SLOT_ACTION_END_PAYOUT]             = SlotAction_EndPayout,
    [SLOT_ACTION_MATCHED_POWER]          = SlotAction_MatchedPower,
    [SLOT_ACTION_WAIT_RT_ANIM]           = SlotAction_WaitReelTimeAnim,
    [SLOT_ACTION_RESET_BET_TILES]        = SlotAction_ResetBetTiles,
    [SLOT_ACTION_NO_MATCHES]             = SlotAction_NoMatches,
    [SLOT_ACTION_ASK_QUIT]               = SlotAction_AskQuit,
    [SLOT_ACTION_HANDLE_QUIT_INPUT]      = SlotAction_HandleQuitInput,
    [SLOT_ACTION_MSG_MAX_COINS]          = SlotAction_PrintMsg_9999Coins,
    [SLOT_ACTION_WAIT_MSG_MAX_COINS]     = SlotAction_WaitMsg_9999Coins,
    [SLOT_ACTION_MSG_NO_MORE_COINS]      = SlotAction_PrintMsg_NoMoreCoins,
    [SLOT_ACTION_WAIT_MSG_NO_MORE_COINS] = SlotAction_WaitMsg_NoMoreCoins,
    [SLOT_ACTION_END]                    = SlotAction_EndGame,
    [SLOT_ACTION_FREE]                   = SlotAction_FreeDataStructures,
};

static bool8 (*const sAwardPayoutActions[])(struct Task *task) =
{
    AwardPayoutAction0,
    AwardPayoutAction_GivePayoutToPlayer,
    AwardPayoutAction_FreeTask
};

static bool8 (*const sSlotReelActions[])(struct Task *task) =
{
    [REEL_ACTION_STILL]      = SlotReelAction_StayStill,
    [REEL_ACTION_SPIN]       = SlotReelAction_Spin,
    [REEL_ACTION_STOP]       = SlotReelAction_DecideWhereToStop,
    [REEL_ACTION_STOP_MOVE]  = SlotReelAction_MoveToStop,
    [REEL_ACTION_STOP_SHAKE] = SlotReelAction_OscillatingStop
};

// returns True if a match with the biasTag is possible in that reel
// also modifies data in sSlotMachine reel arrays to indicate how to get to the matching state
static bool8 (*const sDecideReelTurns_BiasTag[NUM_REELS])(void) =
{
    DecideReelTurns_BiasTag_Reel1,
    DecideReelTurns_BiasTag_Reel2,
    DecideReelTurns_BiasTag_Reel3
};

static void (*const sDecideReelTurns_NoBiasTag[NUM_REELS])(void) =
{
    DecideReelTurns_NoBiasTag_Reel1,
    DecideReelTurns_NoBiasTag_Reel2,
    DecideReelTurns_NoBiasTag_Reel3
};

static const u16 sReelStopShocks[] = {2, 4, 4, 4, 8};

static bool8 (*const sDecideReelTurns_BiasTag_Reel1_Bets[MAX_BET])(u8 tag1, u8 tag2) =
{
    DecideReelTurns_BiasTag_Reel1_Bet1,
    DecideReelTurns_BiasTag_Reel1_Bet2or3,
    DecideReelTurns_BiasTag_Reel1_Bet2or3
};

static bool8 (*const sDecideReelTurns_BiasTag_Reel2_Bets[MAX_BET])(void) =
{
    DecideReelTurns_BiasTag_Reel2_Bet1or2,
    DecideReelTurns_BiasTag_Reel2_Bet1or2,
    DecideReelTurns_BiasTag_Reel2_Bet3
};

static bool8 (*const sDecideReelTurns_BiasTag_Reel3_Bets[MAX_BET])(u8 biasTag) =
{
    DecideReelTurns_BiasTag_Reel3_Bet1or2,
    DecideReelTurns_BiasTag_Reel3_Bet1or2,
    DecideReelTurns_BiasTag_Reel3_Bet3
};

static void (*const sDecideReelTurns_NoBiasTag_Reel2_Bets[MAX_BET])(void) =
{
    DecideReelTurns_NoBiasTag_Reel2_Bet1,
    DecideReelTurns_NoBiasTag_Reel2_Bet2,
    DecideReelTurns_NoBiasTag_Reel2_Bet3
};

static void (*const sDecideReelTurns_NoBiasTag_Reel3_Bets[MAX_BET])(void) =
{
    DecideReelTurns_NoBiasTag_Reel3_Bet1,
    DecideReelTurns_NoBiasTag_Reel3_Bet2,
    DecideReelTurns_NoBiasTag_Reel3_Bet3
};

static void (*const sReelStopButtonFuncs[])(struct Task *task, u8 taskId) =
{
    StopReelButton_Press,
    StopReelButton_Wait,
    StopReelButton_Unpress
};

static const s16 sReelButtonOffsets[NUM_REELS] = {5, 10, 15};

static void (*const sPikaPowerBoltFuncs[])(struct Task *task) =
{
    PikaPowerBolt_Idle,
    PikaPowerBolt_AddBolt,
    PikaPowerBolt_WaitAnim,
    PikaPowerBolt_ClearAll
};

static const u16 sPikaPowerTileTable[][2] =
{
    {0x9e, 0x6e},
    {0x9f, 0x6f},
    {0xaf, 0x7f},
};

static void (*const sReelTimeActions[])(struct Task *task) =
{
    ReelTime_Init,
    ReelTime_WindowEnter,
    ReelTime_WaitStartPikachu,
    ReelTime_PikachuSpeedUp1,
    ReelTime_PikachuSpeedUp2,
    ReelTime_WaitReel,
    ReelTime_CheckExplode,
    ReelTime_LandOnOutcome,
    ReelTime_PikachuReact,
    ReelTime_WaitClearPikaPower,
    ReelTime_CloseWindow,
    ReelTime_DestroySprites,
    ReelTime_SetReelIncrement,
    ReelTime_EndSuccess,
    ReelTime_ExplodeMachine,
    ReelTime_WaitExplode,
    ReelTime_WaitSmoke,
    ReelTime_CloseWindow,
    ReelTime_EndFailure
};

static const u8 sReelTimePikachuAnimIds[] = {1, 1, 2, 2};
static const s16 sReelTimeBoltDelays[] = {64, 48, 24, 8};
static const s16 sPikachuAuraFlashDelays[] = {10, 8, 6, 4};

static void (*const sInfoBoxActions[])(struct Task *task) =
{
    // Go to Info screen
    InfoBox_FadeIn,
    InfoBox_WaitForFade,
    InfoBox_DrawWindow,
    InfoBox_WaitForFade,
    InfoBox_AddText,
    InfoBox_WaitForFade,
    // On Info screen
    InfoBox_AwaitPlayerInput,
    // Exit Info screen
    InfoBox_WaitForFade,
    InfoBox_LoadSlotMachineTilemap,
    InfoBox_WaitForFade,
    InfoBox_CreateDigitalDisplay,
    InfoBox_WaitForFade,
    InfoBox_LoadPikaPowerMeter,
    InfoBox_WaitForFade,
    InfoBox_FreeTask,
};

// Just idles, digital display is handled by CreateDigitalDisplayScene and sprite callbacks
static void (*const sDigitalDisplayActions[])(struct Task *task) =
{
    DigitalDisplay_Idle,
};




// code
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

void PlaySlotMachine(u8 slotMachineIndex, MainCallback exitCallback)
{
    u8 taskId;

    sSlotMachine = AllocZeroed(sizeof(*sSlotMachine));
    PlaySlotMachine_Internal(slotMachineIndex, exitCallback);
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
            SlotMachineSetup_InitSlotMachineStruct();
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

static void PlaySlotMachine_Internal(u8 slotMachineIndex, MainCallback exitCallback)
{
    struct Task *task = &gTasks[CreateTask(SlotMachineDummyTask, 0xFF)];
    task->data[0] = slotMachineIndex;
    StoreWordInTwoHalfwords(&task->data[1], (intptr_t)exitCallback);
}


static void SlotMachineInitDummyTask(void)
{
    struct Task *task = &gTasks[FindTaskIdByFunc(SlotMachineDummyTask)];
    sSlotMachine->machineId = task->data[0];
    LoadWordFromTwoHalfwords((u16 *)&task->data[1], (u32 *)&sSlotMachine->prevMainCb);
}

static void SlotMachineDummyTask(u8 taskId)
{
}

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

// set up initial state of slot machine
static void SlotMachineSetup_InitSlotMachineStruct(void)
{
    u8 i;

    SlotMachineInitDummyTask();  // assigns sSlotMachine->machineId, etc.
    sSlotMachine->state = 0;
    sSlotMachine->pikaPower = 0;
    sSlotMachine->luckyGame = Random() & 1;
    sSlotMachine->luckyFlags = 0;
    sSlotMachine->matchedSymbols = 0;
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reelTimeSpinsUsed = 0;
    sSlotMachine->coins = GetCoins();
    sSlotMachine->payout = 0;
    sSlotMachine->netCoinLoss = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currReel = 0;
    sSlotMachine->reelIncrement = 8;
    sSlotMachine->win0h = DISPLAY_WIDTH;
    sSlotMachine->win0v = DISPLAY_HEIGHT;
    sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
    sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    sSlotMachine->backupMapMusic = GetCurrentMapMusic();

    for (i = 0; i < NUM_REELS; i++)
    {
        sSlotMachine->reelPixelOffsetsWhileStopping[i] = 0;
        sSlotMachine->reelPositions[i] = sInitialReelPositions[i][sSlotMachine->luckyGame] % SYMBOLS_PER_REEL;
        sSlotMachine->reelPixelOffsets[i] = SYMBOLS_PER_REEL * REEL_SYMBOL_HEIGHT - sSlotMachine->reelPositions[i] * REEL_SYMBOL_HEIGHT;
        sSlotMachine->reelPixelOffsets[i] %= SYMBOLS_PER_REEL * REEL_SYMBOL_HEIGHT;
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
    LoadMessageBoxGfx(0, 0x200, 0xF0);
    LoadUserWindowBorderGfx(0, 0x214, 0xE0);
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
    CreateSlotReelTasks();
    CreateDigitalDisplayTask();
    CreateSlotMachineTask();
}

static void CreateSlotMachineTask(void)
{
    Task_SlotMachine(CreateTask(Task_SlotMachine, 0));
}

// task->data[0] is a timer
static void Task_SlotMachine(u8 taskId)
{
    while (sSlotActions[sSlotMachine->state](&gTasks[taskId]))
        ;
}

// SLOT_ACTION_UNFADE
static bool8 SlotAction_UnfadeScreen(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB(0, 0, 0));
    LoadPikaPowerMeter(sSlotMachine->pikaPower);
    sSlotMachine->state++; // SLOT_ACTION_WAIT_FADE
    return FALSE;
}

// SLOT_ACTION_WAIT_FADE
static bool8 SlotAction_WaitForUnfade(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

// SLOT_ACTION_READY_NEW_SPIN
static bool8 SlotAction_ReadyNewSpin(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currReel = 0;
    sSlotMachine->luckyFlags &= (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
    sSlotMachine->state = SLOT_ACTION_ASK_INSERT_BET;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = SLOT_ACTION_MSG_NO_MORE_COINS;
    }
    else if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->state = SLOT_ACTION_READY_NEW_RT_SPIN;
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
    }
    return TRUE;
}

// SLOT_ACTION_READY_NEW_RT_SPIN
static bool8 SlotAction_ReadyNewReelTimeSpin(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
        sSlotMachine->state = SLOT_ACTION_ASK_INSERT_BET;
    return FALSE;
}

// SLOT_ACTION_ASK_INSERT_BET
static bool8 SlotAction_AskInsertBet(struct Task *task)
{
    CreateDigitalDisplayScene(DIG_DISPLAY_INSERT_BET);
    sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    if (sSlotMachine->coins >= MAX_COINS)
        sSlotMachine->state = SLOT_ACTION_MSG_MAX_COINS;
    return TRUE;
}

// SLOT_ACTION_BET_INPUT
static bool8 SlotAction_HandleBetInput(struct Task *task)
{
    s16 i;

    if (JOY_NEW(SELECT_BUTTON))
    {
        OpenInfoBox(DIG_DISPLAY_INSERT_BET);
        sSlotMachine->state = SLOT_ACTION_WAIT_INFO_BOX;
    }
    else if (JOY_NEW(R_BUTTON))  // bet the max amount
    {
        if (sSlotMachine->coins - (MAX_BET - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < MAX_BET; i++)
                LightenBetTiles(i);
            sSlotMachine->coins -= (MAX_BET - sSlotMachine->bet);
            sSlotMachine->bet = MAX_BET;
            sSlotMachine->state = SLOT_ACTION_START_SPIN;
            PlaySE(SE_SHOP);
        }
        else  // you didn't have enough coins to bet the max
        {
            sSlotMachine->state = SLOT_ACTION_MSG_NEED_3_COINS;
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
            sSlotMachine->state = SLOT_ACTION_START_SPIN;

        // Quit prompt
        if (JOY_NEW(B_BUTTON))
            sSlotMachine->state = SLOT_ACTION_ASK_QUIT;
    }
    return FALSE;
}

// SLOT_ACTION_NEED_3_COINS
static bool8 SlotAction_PrintMsg_Need3Coins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouDontHaveThreeCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_WAIT_MSG_NEED_3_COINS;
    return FALSE;
}

// SLOT_ACTION_WAIT_MSG_NEED_3_COINS
static bool8 SlotAction_WaitMsg_Need3Coins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    }
    return FALSE;
}

// SLOT_ACTION_WAIT_INFO_BOX
static bool8 SlotAction_WaitForInfoBox(struct Task *task)
{
    if (IsInfoBoxClosed())
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    return FALSE;
}

// SLOT_ACTION_START_SPIN
static bool8 SlotAction_StartSpin(struct Task *task)
{
    DrawLuckyFlags();
    DestroyDigitalDisplayScene();

    SpinSlotReel(LEFT_REEL);
    SpinSlotReel(MIDDLE_REEL);
    SpinSlotReel(RIGHT_REEL);

    IncrementDailySlotsUses();

    task->data[0] = 0;
    if (sSlotMachine->luckyFlags & LUCKY_BIAS_REELTIME)
    {
        BeginReelTime();
        sSlotMachine->state = SLOT_ACTION_START_RT_SPIN;
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->state = SLOT_ACTION_SET_LUCKY_SPINS;
    }
    sSlotMachine->reelIncrement = 8;
    if (sSlotMachine->reelTimeSpinsLeft)
        sSlotMachine->reelIncrement = SlowReelSpeed();
    return FALSE;
}

// SLOT_ACTION_START_RT_SPIN
static bool8 SlotAction_StartReelTimeSpin(struct Task *task)
{
    if (IsReelTimeTaskDone())
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->luckyFlags &= ~LUCKY_BIAS_REELTIME;
        sSlotMachine->state = SLOT_ACTION_SET_LUCKY_SPINS;
    }
    return FALSE;
}

// SLOT_ACTION_SET_LUCKY_SPINS
static bool8 SlotAction_SetLuckySpins(struct Task *task)
{
    if (++task->data[0] >= 30)
    {
        SetLuckySpins();
        sSlotMachine->state = SLOT_ACTION_AWAIT_REEL_STOP;
    }
    return FALSE;
}

// SLOT_ACTION_AWAIT_REEL_STOP
static bool8 SlotAction_AwaitReelStop(struct Task *task)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_CONTEST_PLACE);
        StopSlotReel(sSlotMachine->currReel);
        PressStopReelButton(sSlotMachine->currReel);
        sSlotMachine->state = SLOT_ACTION_AWAIT_ALL_REELS_STOP;
    }
    return FALSE;
}

// SLOT_ACTION_AWAIT_ALL_REELS_STOP
static bool8 SlotAction_WaitForAllReelsToStop(struct Task *task)
{
    if (!IsSlotReelMoving(sSlotMachine->currReel))
    {
        sSlotMachine->currReel++;
        sSlotMachine->state = SLOT_ACTION_AWAIT_REEL_STOP;
        if (sSlotMachine->currReel >= NUM_REELS)
        {
            sSlotMachine->state = SLOT_ACTION_CHECK_MATCHES;
        }
        return TRUE;
    }
    return FALSE;
}

// SLOT_ACTION_CHECK_MATCHES
static bool8 SlotAction_CheckMatches(struct Task *task)
{
    sSlotMachine->luckyFlags &= (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
    CheckMatch();
    if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->reelTimeSpinsLeft--;
        sSlotMachine->reelTimeSpinsUsed++;
    }

    if (sSlotMachine->matchedSymbols)
    {
        sSlotMachine->state = SLOT_ACTION_WAIT_PAYOUT;
        AwardPayout();
        FlashSlotMachineLights();
        if ((sSlotMachine->netCoinLoss -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->netCoinLoss = 0;
        }
        if (sSlotMachine->matchedSymbols & ((1 << MATCHED_777_BLUE) | (1 << MATCHED_777_RED)))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_BIG);
        }
        else if (sSlotMachine->matchedSymbols & (1 << MATCHED_777_MIXED))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_REG);
        }
        else
        {
            PlayFanfare(MUS_SLOTS_WIN);
            CreateDigitalDisplayScene(DIG_DISPLAY_WIN);
        }
        // if you matched 777...
        if (sSlotMachine->matchedSymbols & ((1 << MATCHED_777_MIXED) | (1 << MATCHED_777_BLUE) | (1 << MATCHED_777_RED)))
        {
            sSlotMachine->luckyFlags &= ~(LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
            if (sSlotMachine->matchedSymbols & ((1 << MATCHED_777_BLUE) | (1 << MATCHED_777_RED)))
            {
                sSlotMachine->reelTimeSpinsLeft = 0;
                sSlotMachine->reelTimeSpinsUsed = 0;
                sSlotMachine->luckyGame = FALSE;
                if (sSlotMachine->matchedSymbols & (1 << MATCHED_777_BLUE))
                    // this may be an error, but if you get blue 777, the game becomes lucky
                    sSlotMachine->luckyGame = TRUE;
            }
        }
        if (sSlotMachine->matchedSymbols & (1 << MATCHED_POWER) && sSlotMachine->pikaPower < 16)
        {
            sSlotMachine->pikaPower++;
            AddPikaPowerBolt(sSlotMachine->pikaPower);
        }
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_LOSE);
        sSlotMachine->state = SLOT_ACTION_NO_MATCHES;
        if ((sSlotMachine->netCoinLoss += sSlotMachine->bet) > MAX_COINS)
            sSlotMachine->netCoinLoss = MAX_COINS;
    }
    return FALSE;
}

// SLOT_ACTION_WAIT_PAYOUT
static bool8 SlotAction_WaitForPayoutToBeAwarded(struct Task *task)
{
    if (IsFinalTask_RunAwardPayoutActions())
        sSlotMachine->state = SLOT_ACTION_END_PAYOUT;
    return FALSE;
}

// SLOT_ACTION_END_PAYOUT
static bool8 SlotAction_EndPayout(struct Task *task)
{
    if (TryStopSlotMachineLights())
    {
        sSlotMachine->state = SLOT_ACTION_RESET_BET_TILES;

        if (sSlotMachine->matchedSymbols & ((1 << MATCHED_777_RED) | (1 << MATCHED_777_BLUE)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);

        if (sSlotMachine->matchedSymbols & (1 << MATCHED_REPLAY))
        {
            sSlotMachine->currReel = 0;
            sSlotMachine->state = SLOT_ACTION_START_SPIN;
        }

        if (sSlotMachine->matchedSymbols & (1 << MATCHED_POWER))
            sSlotMachine->state = SLOT_ACTION_MATCHED_POWER;

        if (sSlotMachine->reelTimeSpinsLeft && sSlotMachine->matchedSymbols & (1 << MATCHED_REPLAY))
        {
            CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
            sSlotMachine->state = SLOT_ACTION_WAIT_RT_ANIM;
        }
    }
    return FALSE;
}

// SLOT_ACTION_MATCHED_POWER
static bool8 SlotAction_MatchedPower(struct Task *task)
{
    if (!IsPikaPowerBoltAnimating())
    {
        sSlotMachine->state = SLOT_ACTION_RESET_BET_TILES;
        if (sSlotMachine->matchedSymbols & (1 << MATCHED_REPLAY))
        {
            sSlotMachine->state = SLOT_ACTION_START_SPIN;
            if (sSlotMachine->reelTimeSpinsLeft)
            {
                CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
                sSlotMachine->state = SLOT_ACTION_WAIT_RT_ANIM;
            }
        }
    }
    return FALSE;
}

// SLOT_ACTION_WAIT_RT_ANIM
static bool8 SlotAction_WaitReelTimeAnim(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
    {
        sSlotMachine->state = SLOT_ACTION_RESET_BET_TILES;
        if (sSlotMachine->matchedSymbols & (1 << MATCHED_REPLAY))
        {
            sSlotMachine->state = SLOT_ACTION_START_SPIN;
        }
    }
    return FALSE;
}

// SLOT_ACTION_RESET_BET_TILES
static bool8 SlotAction_ResetBetTiles(struct Task *task)
{
    DarkenBetTiles(0);
    DarkenBetTiles(1);
    DarkenBetTiles(2);
    sSlotMachine->state = SLOT_ACTION_READY_NEW_SPIN;
    return FALSE;
}

// SLOT_ACTION_NO_MATCHES
static bool8 SlotAction_NoMatches(struct Task *task)
{
    if (++task->data[1] > 64)
    {
        task->data[1] = 0;
        sSlotMachine->state = SLOT_ACTION_RESET_BET_TILES;
    }
    return FALSE;
}

// SLOT_ACTION_ASK_QUIT
static bool8 SlotAction_AskQuit(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_QuitTheGame, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x180, 0xE, 0xF);
    sSlotMachine->state = SLOT_ACTION_HANDLE_QUIT_INPUT;
    return FALSE;
}

// SLOT_ACTION_HANDLE_QUIT_INPUT
static bool8 SlotAction_HandleQuitInput(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0) // player chooses to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        DarkenBetTiles(0);
        DarkenBetTiles(1);
        DarkenBetTiles(2);
        sSlotMachine->coins += sSlotMachine->bet;
        sSlotMachine->state = SLOT_ACTION_END;
    }
    else if (input == 1 || input == -1) // player chooses not to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    }
    return FALSE;
}

// SLOT_ACTION_MSG_MAX_COINS
static bool8 SlotAction_PrintMsg_9999Coins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveGot9999Coins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_WAIT_MSG_MAX_COINS;
    return FALSE;
}

// SLOT_ACTION_WAIT_MSG_MAX_COINS
static bool8 SlotAction_WaitMsg_9999Coins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    }
    return FALSE;
}

// SLOT_ACTION_MSG_NO_MORE_COINS
static bool8 SlotAction_PrintMsg_NoMoreCoins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveRunOutOfCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_WAIT_MSG_NO_MORE_COINS;
    return FALSE;
}

// SLOT_ACTION_WAIT_MSG_NO_MORE_COINS
static bool8 SlotAction_WaitMsg_NoMoreCoins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_END;
    }
    return FALSE;
}

// SLOT_ACTION_END
static bool8 SlotAction_EndGame(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    TryPutFindThatGamerOnAir(GetCoins());
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB(0, 0, 0));
    sSlotMachine->state++; // SLOT_ACTION_FREE
    return FALSE;
}

// SLOT_ACTION_FREE
static bool8 SlotAction_FreeDataStructures(struct Task *task)
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
        if (sImageTable_ReelTimePikachu != NULL)
            FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
        if (sImageTable_ReelTimeMachineAntennae != NULL)
            FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
        if (sImageTable_ReelTimeMachine != NULL)
            FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);
        if (sImageTable_BrokenReelTimeMachine != NULL)
            FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
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

static void DrawLuckyFlags(void)
{
    u8 attempts;

    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        if (!(sSlotMachine->luckyFlags & (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777)))
        {
            if (IsThisRoundLucky())
            {
                attempts = AttemptsAtLuckyFlags_Top3();
                if (attempts != 3) // if you found a lucky number
                {
                    // attempts == 1:  reelTime flag set
                    sSlotMachine->luckyFlags |= sLuckyFlagSettings_Top3[attempts];
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
                sSlotMachine->luckyFlags |= sLuckyFlagSettings_NotTop3[attempts];
            }
        }
    }
}

static void SetLuckySpins(void)
{
    sSlotMachine->isLuckySpin = FALSE;
    if (sSlotMachine->luckyFlags)
        sSlotMachine->isLuckySpin = TRUE;
}

static u8 GetBiasTag(u8 luckyFlags)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        if (luckyFlags & 1)
            return sBiasTags[i];
        luckyFlags >>= 1;
    }
    return 0;
}

// you have way more luck betting 3 coins than anything lower
static bool8 IsThisRoundLucky(void)
{
    u8 rval = Random();
    if (sLuckyRoundProbabilities[sSlotMachine->machineId][sSlotMachine->bet - 1] > rval)
        return TRUE;
    return FALSE;
}

static u8 AttemptsAtLuckyFlags_Top3(void)
{
    s16 count;

    for (count = 0; count < 3; count++)
    {
        s16 rval = Random() & 0xff;
        s16 value = sLuckyFlagProbabilities_Top3[count][sSlotMachine->machineId];
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
        s16 value = sLuckyFlagProbabilities_NotTop3[count][sSlotMachine->machineId];
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
        return sReeltimeProbabilities_UnluckyGame[reelTimeDraw][sSlotMachine->pikaPower];
    else
        return sReelTimeProbabilities_LuckyGame[reelTimeDraw][sSlotMachine->pikaPower];
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

static bool8 ShouldReelTimeMachineExplode(u16 i)
{
    u16 rval = Random() & 0xff;
    if (rval < sReelTimeExplodeProbability[i])
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
    value = sReelIncrementTable[i][0];
    if (rval < value)
        return 4;
    rval = Random() % 100;
    value = sReelIncrementTable[i][1] + sReelTimeBonusIncrementTable[sSlotMachine->reelTimeSpinsUsed];
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

    c1 = GetTagAtRest(LEFT_REEL, 2);
    c2 = GetTagAtRest(MIDDLE_REEL, 2);
    c3 = GetTagAtRest(RIGHT_REEL, 2);
    match = GetMatchFromSymbols(c1, c2, c3);
    if (match != MATCHED_NONE)
    {
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_MIDDLE_ROW);
    }
}

static void CheckMatch_TopAndBottom(void)
{
    u8 c1, c2, c3, match;

    c1 = GetTagAtRest(LEFT_REEL, 1);
    c2 = GetTagAtRest(MIDDLE_REEL, 1);
    c3 = GetTagAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(c1, c2, c3);
    if (match != MATCHED_NONE)
    {
        if (match == MATCHED_1CHERRY)
            match = MATCHED_2CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_TOP_ROW);
    }
    c1 = GetTagAtRest(LEFT_REEL, 3);
    c2 = GetTagAtRest(MIDDLE_REEL, 3);
    c3 = GetTagAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(c1, c2, c3);
    if (match != MATCHED_NONE)
    {
        if (match == MATCHED_1CHERRY)
            match = MATCHED_2CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_BOTTOM_ROW);
    }
}

static void CheckMatch_Diagonals(void)
{
    u8 c1, c2, c3, match;

    c1 = GetTagAtRest(LEFT_REEL, 1);
    c2 = GetTagAtRest(MIDDLE_REEL, 2);
    c3 = GetTagAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(c1, c2, c3);
    if (match != MATCHED_NONE)
    {
        if (match != MATCHED_1CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NWSE_DIAG);
    }
    c1 = GetTagAtRest(LEFT_REEL, 3);
    c2 = GetTagAtRest(MIDDLE_REEL, 2);
    c3 = GetTagAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(c1, c2, c3);
    if (match != MATCHED_NONE)
    {
        if (match != MATCHED_1CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matchedSymbols |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NESW_DIAG);
    }
}

static u8 GetMatchFromSymbols(u8 c1, u8 c2, u8 c3)
{
    if (c1 == c2 && c1 == c3)
        return sSymToMatch[c1];
    if (c1 == GFXTAG_7_RED && c2 == GFXTAG_7_RED && c3 == GFXTAG_7_BLUE)
        return MATCHED_777_MIXED;
    if (c1 == GFXTAG_7_BLUE && c2 == GFXTAG_7_BLUE && c3 == GFXTAG_7_RED)
        return MATCHED_777_MIXED;
    if (c1 == GFXTAG_CHERRY)
        return MATCHED_1CHERRY;
    return MATCHED_NONE;
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
    while (sAwardPayoutActions[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

static bool8 AwardPayoutAction0(struct Task *task)
{
    if (IsMatchLineDoneFlashingBeforePayout())
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
        if (sSlotMachine->coins < MAX_COINS)
            sSlotMachine->coins++;
        task->data[1] = 8;
        if (JOY_HELD(A_BUTTON))
            task->data[1] = 4;
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
        task->data[0]++;
    return FALSE;
}

static bool8 AwardPayoutAction_FreeTask(struct Task *task)
{
    if (TryStopMatchLinesFlashing())
        DestroyTask(FindTaskIdByFunc(RunAwardPayoutActions));
    return FALSE;
}

// Get the tag at position `offset` below the top of the reel's tape. Note that
// if `offset` is negative, it wraps around to the bottom of the tape.
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
static u8 GetTagAtRest(u8 reel, s16 offset)
{
    s16 pos = (sSlotMachine->reelPositions[reel] + offset) % SYMBOLS_PER_REEL;
    if (pos < 0)
        pos += SYMBOLS_PER_REEL;
    return sReelSymbolTileTags[reel][pos];
}

// Calculates GetTagAtRest as if the reel were snapped downwards into place.
static u8 GetTag(u8 reel, s16 offset)
{
    s16 inc = 0;
    s16 pixelOffset = sSlotMachine->reelPixelOffsets[reel] % REEL_SYMBOL_HEIGHT;
    if (pixelOffset != 0)
        inc = -1;
    return GetTagAtRest(reel, offset + inc);
}

static u8 GetNearbyReelTimeTag(s16 n)
{
    s16 newPosition = (sSlotMachine->reeltimePosition + n) % 6;
    if (newPosition < 0)
        newPosition += 6;
    return sReelTimeTags[newPosition];
}

static void AdvanceSlotReel(u8 reelIndex, s16 value)
{
    sSlotMachine->reelPixelOffsets[reelIndex] += value;
    sSlotMachine->reelPixelOffsets[reelIndex] %= 504;
    sSlotMachine->reelPositions[reelIndex] = SYMBOLS_PER_REEL - sSlotMachine->reelPixelOffsets[reelIndex] / REEL_SYMBOL_HEIGHT;
}

s16 AdvanceSlotReelToNextTag(u8 reelIndex, s16 value)
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

#define tState  data[0]
#define tMoving data[14]
#define tReelId data[15]

static void CreateSlotReelTasks(void)
{
    u8 i;
    for (i = 0; i < NUM_REELS; i++)
    {
        u8 taskId = CreateTask(Task_RunSlotReelActions, 2);
        gTasks[taskId].tReelId = i;
        sSlotMachine->slotReelTasks[i] = taskId;
        Task_RunSlotReelActions(taskId);
    }
}

static void SpinSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_ACTION_SPIN;
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving = TRUE;
}

static void StopSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_ACTION_STOP;
}

static bool8 IsSlotReelMoving(u8 reelIndex)
{
    return gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving;
}

static void Task_RunSlotReelActions(u8 taskId)
{
    while (sSlotReelActions[gTasks[taskId].tState](&gTasks[taskId]))
        ;
}

// task->data[1]  reel turns
static bool8 SlotReelAction_StayStill(struct Task *task)
{
    return FALSE;
}

static bool8 SlotReelAction_Spin(struct Task *task)
{
    AdvanceSlotReel(task->tReelId, sSlotMachine->reelIncrement);
    return FALSE;
}

// As in previous generations, the slot machine often doesn't stop exactly when you press stop
static bool8 SlotReelAction_DecideWhereToStop(struct Task *task)
{
    task->tState++;
    // initialize data for that reel --> these will be changed if sBiasTags can be lined up
    sSlotMachine->winnerRows[task->tReelId] = 0;
    sSlotMachine->reelExtraTurns[task->tReelId] = 0;

    if (sSlotMachine->reelTimeSpinsLeft == 0 && (sSlotMachine->luckyFlags == 0 || !sSlotMachine->isLuckySpin || !sDecideReelTurns_BiasTag[task->tReelId]()))
    {
        sSlotMachine->isLuckySpin = FALSE;
        sDecideReelTurns_NoBiasTag[task->tReelId]();
    }
    task->data[1] = sSlotMachine->reelExtraTurns[task->tReelId];
    return TRUE;
}

// go to next tag and then do any additional turns
static bool8 SlotReelAction_MoveToStop(struct Task *task)
{
    u16 reelStopShocks[ARRAY_COUNT(sReelStopShocks)];
    s16 reelPixelPos;

    memcpy(reelStopShocks, sReelStopShocks, sizeof(sReelStopShocks));
    reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    if (reelPixelPos != 0)
        reelPixelPos = AdvanceSlotReelToNextTag(task->tReelId, sSlotMachine->reelIncrement);
    else if (sSlotMachine->reelExtraTurns[task->tReelId])
    {
        sSlotMachine->reelExtraTurns[task->tReelId]--;
        AdvanceSlotReel(task->tReelId, sSlotMachine->reelIncrement);
        reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    }
    if (reelPixelPos == 0 && sSlotMachine->reelExtraTurns[task->tReelId] == 0)
    {
        task->tState++;
        task->data[1] = reelStopShocks[task->data[1]];
        task->data[2] = 0;
    }
    return FALSE;
}

// make selected tag oscillate before it becomes still
static bool8 SlotReelAction_OscillatingStop(struct Task *task)
{
    sSlotMachine->reelPixelOffsetsWhileStopping[task->tReelId] = task->data[1];
    task->data[1] = -task->data[1];
    task->data[2]++;
    if ((task->data[2] & 0x3) == 0)
        task->data[1] >>= 1;
    if (task->data[1] == 0)
    {
        task->tState = 0;
        task->tMoving = FALSE;
        sSlotMachine->reelPixelOffsetsWhileStopping[task->tReelId] = 0;
    }
    return FALSE;
}

#undef tState
#undef tMoving
#undef tReelId

static bool8 DecideReelTurns_BiasTag_Reel1(void)
{
    u8 tag2 = GetBiasTag(sSlotMachine->luckyFlags);
    u8 tag1 = tag2;
    if (sSlotMachine->luckyFlags & (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777))
    {
        tag1 = GFXTAG_7_RED;
        tag2 = GFXTAG_7_BLUE;
    }
    return sDecideReelTurns_BiasTag_Reel1_Bets[sSlotMachine->bet - 1](tag1, tag2);
}

static bool8 AreTagsAtPosition_Reel1(s16 pos, u8 tag1, u8 tag2)
{
    u8 tag = GetTag(LEFT_REEL, pos);
    if (tag == tag1 || tag == tag2)
    {
        sSlotMachine->biasTag = tag;
        return TRUE;
    }
    return FALSE;
}

static bool8 AreCherriesOnScreen_Reel1(s16 offsetFromCenter)
{
    if (GetTag(LEFT_REEL, 1 - offsetFromCenter) == GFXTAG_CHERRY
     || GetTag(LEFT_REEL, 2 - offsetFromCenter) == GFXTAG_CHERRY
     || GetTag(LEFT_REEL, 3 - offsetFromCenter) == GFXTAG_CHERRY)
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
            sSlotMachine->winnerRows[LEFT_REEL] = 2;
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
    return sDecideReelTurns_BiasTag_Reel2_Bets[sSlotMachine->bet - 1]();
}

static bool8 DecideReelTurns_BiasTag_Reel2_Bet1or2(void)
{
    s16 i;
    s16 biasTagLocation_Reel1 = sSlotMachine->winnerRows[0];

    for (i = 0; i < 5; i++)
    {
        // if biasTag appears in the same row within 4 turns
        if (GetTag(MIDDLE_REEL, biasTagLocation_Reel1 - i) == sSlotMachine->biasTag)
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
                if (GetTag(MIDDLE_REEL, 2 - i) == sSlotMachine->biasTag)
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
            if (GetTag(MIDDLE_REEL, 2 - i) == sSlotMachine->biasTag)
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
        biasTag = GFXTAG_7_RED;
        if (sSlotMachine->biasTag == GFXTAG_7_RED)
        {
            biasTag = GFXTAG_7_BLUE;
        }
    }
    return sDecideReelTurns_BiasTag_Reel3_Bets[sSlotMachine->bet - 1](biasTag);
}

static bool8 DecideReelTurns_BiasTag_Reel3_Bet1or2(u8 biasTag)
{
    s16 i;
    s16 biasTagLocation_Reel2 = sSlotMachine->winnerRows[1];

    for (i = 0; i < 5; i++)
    {
        // if the biasTag appears in the same row as in reel 2 within 4 turns
        if (GetTag(RIGHT_REEL, biasTagLocation_Reel2 - i) == biasTag)
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
        if (GetTag(RIGHT_REEL, biasTagFinalPos - i) == biasTag)
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
    if (*biasTagPtr == GFXTAG_7_RED)
    {
        *biasTagPtr = GFXTAG_7_BLUE;
        return TRUE;
    }
    if (*biasTagPtr == GFXTAG_7_BLUE)
    {
        *biasTagPtr = GFXTAG_7_RED;
        return TRUE;
    }
    return FALSE;
}

static void DecideReelTurns_NoBiasTag_Reel2(void)
{
    sDecideReelTurns_NoBiasTag_Reel2_Bets[sSlotMachine->bet - 1]();
}

// only does stuff if the biasTag is one of the 7's, plus other conditions
static void DecideReelTurns_NoBiasTag_Reel2_Bet1(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->luckyFlags & LUCKY_BIAS_777)
    {
        u8 biasTag = GetTag(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
        //...and if biasTag is one of the 7's...
        if (IsBiasTag777_SwitchColor(&biasTag))
        //...swap color of biasTag...
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                //...and if the biasTag appears within 4 turns
                if (biasTag == GetTag(MIDDLE_REEL, 2 - i))
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
        u8 biasTag = GetTag(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        //...and if biasTag is one of the 7's...
        if (IsBiasTag777_SwitchColor(&biasTag))
        //...swap color of biasTag...
        {
            s16 i;
            for (i = 0; i < 5; i++)
            {
                //...and if the biasTag appears in same row in reel 2 within 4 turns
                if (biasTag == GetTag(MIDDLE_REEL, sSlotMachine->winnerRows[0] - i))
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
            u8 biasTag = GetTag(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
            //...and if biasTag is one of the 7's...
            if (IsBiasTag777_SwitchColor(&biasTag))
            //...swap the color of the 7...
            {
                j = 2;
                if (sSlotMachine->winnerRows[0] == 3)
                    j = 3;
                for (i = 0; i < 2; i++, j--)
                {
                    if (biasTag == GetTag(MIDDLE_REEL, j))
                    {
                        sSlotMachine->winnerRows[1] = j;
                        sSlotMachine->reelExtraTurns[1] = 0;
                        return;
                    }
                }
                for (j = 1; j < 5; j++)
                {
                    if (biasTag == GetTag(MIDDLE_REEL, sSlotMachine->winnerRows[0] - j))
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
    if ((tag1 == GFXTAG_7_RED && tag2 == GFXTAG_7_BLUE) || (tag1 == GFXTAG_7_BLUE && tag2 == GFXTAG_7_RED))
        return TRUE;
    else
        return FALSE;
}

static bool8 AreTagsMixed777(u8 tag1, u8 tag2, u8 tag3)
{
    if ((tag1 == GFXTAG_7_RED && tag2 == GFXTAG_7_BLUE && tag3 == GFXTAG_7_RED) ||
        (tag1 == GFXTAG_7_BLUE && tag2 == GFXTAG_7_RED && tag3 == GFXTAG_7_BLUE))
        return TRUE;
    else
        return FALSE;
}

static bool8 TagsDontMatchOrHaveAny7s(u8 tag1, u8 tag2, u8 tag3)
{
    if ((tag1 == GFXTAG_7_RED && tag2 == GFXTAG_7_BLUE && tag3 == GFXTAG_7_RED) ||
        (tag1 == GFXTAG_7_BLUE && tag2 == GFXTAG_7_RED && tag3 == GFXTAG_7_BLUE) ||
        (tag1 == GFXTAG_7_RED && tag2 == GFXTAG_7_RED && tag3 == GFXTAG_7_BLUE) ||
        (tag1 == GFXTAG_7_BLUE && tag2 == GFXTAG_7_BLUE && tag3 == GFXTAG_7_RED) ||
        (tag1 == tag2 && tag1 == tag3))
    {
        return FALSE;
    }
    return TRUE;
}

static void DecideReelTurns_NoBiasTag_Reel3(void)
{
    sDecideReelTurns_NoBiasTag_Reel3_Bets[sSlotMachine->bet - 1]();
}

static void DecideReelTurns_NoBiasTag_Reel3_Bet1(void)
{
    s16 i = 0;
    u8 tag1 = GetTag(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
    u8 tag2 = GetTag(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
    // if tags match in first 2 reels...
    if (tag1 == tag2)
    {
        //...spin until you get non-matching tag
        while (1)
        {
            u8 tag3;
            if (!(tag1 == (tag3 = GetTag(RIGHT_REEL, 2 - i)) || (tag1 == GFXTAG_7_RED && tag3 == GFXTAG_7_BLUE) || (tag1 == GFXTAG_7_BLUE && tag3 == GFXTAG_7_RED)))
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
                if (tag1 == GetTag(RIGHT_REEL, 2 - i))
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
            if (tag1 != GetTag(RIGHT_REEL, 2 - i))
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
        tag1 = GetTag(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetTag(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);
        //...and if tags are mixed 7s...
        if (AreTagsMixed77(tag1, tag2))
        {
            //...try to match with reel 1 within 4 turns
            for (i = 0; i < 5; i++)
            {
                tag3 = GetTag(RIGHT_REEL, sSlotMachine->winnerRows[1] - i);
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
            tag1 = GetTag(LEFT_REEL, i - sSlotMachine->reelExtraTurns[0]);  // why does this update with i
            tag2 = GetTag(MIDDLE_REEL, i - sSlotMachine->reelExtraTurns[1]);
            tag3 = GetTag(RIGHT_REEL, i - extraTurns);
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
        tag1 = GetTag(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetTag(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);
        //..and if tags are mixed 7s...
        if (AreTagsMixed77(tag1, tag2))
        {
            j = 1;
            if (sSlotMachine->winnerRows[0] == 1)
                j = 3;
            for (i = 0; i < 5; i++)
            {
                tag3 = GetTag(RIGHT_REEL, j - (sSlotMachine->reelExtraTurns[2] + i));
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
        tag1 = GetTag(LEFT_REEL, 1 - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetTag(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        tag3 = GetTag(RIGHT_REEL, 3 - sSlotMachine->reelExtraTurns[2]);
        if (TagsDontMatchOrHaveAny7s(tag1, tag2, tag3) || (AreTagsMixed777(tag1, tag2, tag3) && sSlotMachine->luckyFlags & LUCKY_BIAS_777))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }
    while (1)
    {
        tag1 = GetTag(LEFT_REEL, 3 - sSlotMachine->reelExtraTurns[0]);
        tag2 = GetTag(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        tag3 = GetTag(RIGHT_REEL, 1 - sSlotMachine->reelExtraTurns[2]);
        if (TagsDontMatchOrHaveAny7s(tag1, tag2, tag3) || (AreTagsMixed777(tag1, tag2, tag3) && sSlotMachine->luckyFlags & LUCKY_BIAS_777))
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
    sReelStopButtonFuncs[gTasks[taskId].data[0]](&gTasks[taskId], taskId);
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
    LoadPalette(sLitMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], 2);
}

static void DarkenMatchLine(u8 matchLineId)
{
    LoadPalette(sDarkMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], 2);
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
        LoadPalette(sSlotMachineMenu_Pal, 0x10, 0x20);
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
    LoadPalette(sFlashingLightsPalTable[task->sFlashState], 0x10, 0x20);
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

static void AddPikaPowerBolt(u8 pikaPower)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = 1;
    task->tNumBolts++;
    task->tAnimating = TRUE;
}

static void ResetPikaPowerBolts(void)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = 3;
    task->tAnimating = TRUE;
}

static bool8 IsPikaPowerBoltAnimating(void)
{
    return gTasks[sSlotMachine->pikaPowerBoltTaskId].tAnimating;
}

static void Task_CreatePikaPowerBolt(u8 taskId)
{
    sPikaPowerBoltFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void PikaPowerBolt_Idle(struct Task *task)
{
}

static void PikaPowerBolt_AddBolt(struct Task *task)
{
    task->tSpriteId = CreatePikaPowerBoltSprite((task->tNumBolts << 3) + 20, 20);
    task->tState++;
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
        task->tState = 0;
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
        task->tState = 0;
        task->tAnimating = 0;
    }
}

static void ResetPikaPowerBoltTask(struct Task *task)
{
    u8 i;

    for (i = 2; i < NUM_TASK_DATA; i++)
        task->data[i] = 0;
}

static void LoadPikaPowerMeter(u8 pikaPower)
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
    gTasks[sSlotMachine->pikaPowerBoltTaskId].data[1] = pikaPower;
}

#undef tState
#undef tNumBolts
#undef tSpriteId
#undef tTimer
#undef tAnimating

#define tState data[0]

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
    // task.data[1] has something to do with the threshold
    // task.data[4] says how many pixels to advance the reel
    // task.data[5] is a timer
    sReelTimeActions[gTasks[taskId].tState](&gTasks[taskId]);
}

static void ReelTime_Init(struct Task *task)
{
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reeltimePixelOffset = 0;
    sSlotMachine->reeltimePosition = 0;
    task->tState++;
    task->data[1] = 0;
    task->data[2] = 30;
    task->data[4] = 1280; // reel speed
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
    GetReeltimeDraw();
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
        task->tState++;
        task->data[3] = 0;
    }
    AdvanceReeltimeReel(task->data[4] >> 8);
}

static void ReelTime_WaitStartPikachu(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    if (++task->data[5] >= 60)
    {
        task->tState++;
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

    AdvanceReeltimeReel(task->data[4] >> 8);
    // gradually slow down the reel
    task->data[4] -= 4;
    i = 4 - (task->data[4] >> 8);
    SetReelTimeBoltDelay(reelTimeBoltDelays[i]);
    SetReelTimePikachuAuraFlashDelay(pikachuAuraFlashDelays[i]);
    StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], pikachuAnimIds[i]);
    // once speed goes below 256, go to next ReelTimeAction and keep the speed level
    if (task->data[4] <= 0x100)
    {
        task->tState++;
        task->data[4] = 0x100;
        task->data[5] = 0;
    }
}

static void ReelTime_PikachuSpeedUp2(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    if (++task->data[5] >= 80)
    {
        task->tState++;
        task->data[5] = 0;
        SetReelTimePikachuAuraFlashDelay(2);
        StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 3);
    }
}

static void ReelTime_WaitReel(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x80;
    if (++task->data[5] >= 80)
    {
        task->tState++;
        task->data[5] = 0;
    }
}

static void ReelTime_CheckExplode(struct Task *task)
{
    AdvanceReeltimeReel(task->data[4] >> 8);
    task->data[4] = (u8)task->data[4] + 0x40;
    if (++task->data[5] >= 40)
    {
        task->data[5] = 0;
        if (sSlotMachine->reelTimeDraw)
        {
            if (sSlotMachine->reelTimeSpinsLeft <= task->data[6])
                task->tState++;
        }
        else if (task->data[6] > 3)
        {
            task->tState++;
        }
        else if (ShouldReelTimeMachineExplode(task->data[6]))
        {
            task->tState = 14; // ReelTime_ExplodeMachine
        }
        task->data[6]++;
    }
}

static void ReelTime_LandOnOutcome(struct Task *task)
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
        task->tState++;
    }
}

static void ReelTime_PikachuReact(struct Task *task)
{
    if (++task->data[4] >= 60)
    {
        StopMapMusic();
        DestroyReelTimeBoltSprites();
        DestroyReelTimePikachuAuraSprites();
        task->tState++;
        if(sSlotMachine->reelTimeDraw == 0)
        {
            task->data[4] = 0xa0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 5);
            PlayFanfare(MUS_TOO_BAD);
        }
        else
        {
            task->data[4] = 0xc0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 4);
            gSprites[sSlotMachine->reelTimePikachuSpriteId].animCmdIndex = 0;
            if (sSlotMachine->pikaPower)
            {
                ResetPikaPowerBolts();
                sSlotMachine->pikaPower = 0;
            }
            PlayFanfare(MUS_SLOTS_WIN);
        }
    }
}

static void ReelTime_WaitClearPikaPower(struct Task *task)
{
    if ((task->data[4] == 0 || --task->data[4] == 0) && !IsPikaPowerBoltAnimating())
        task->tState++;
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
        task->tState++;
}

static void ReelTime_DestroySprites(struct Task *task)
{
    sSlotMachine->reelTimeSpinsUsed = 0;
    sSlotMachine->reelTimeSpinsLeft = sSlotMachine->reelTimeDraw;
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    sSlotMachine->reelIncrement = 8;
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
        task->data[1] = SlowReelSpeed();
        task->data[2] = 0;
        task->data[3] = 0;
        task->tState++;
    }
}

static void ReelTime_SetReelIncrement(struct Task *task)
{
    if (sSlotMachine->reelIncrement == task->data[1])
        task->tState++;
    else if (sSlotMachine->reelPixelOffsets[0] % REEL_SYMBOL_HEIGHT == 0 && (++task->data[2]& 0x07) == 0)
        sSlotMachine->reelIncrement >>= 1;
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
    task->tState++;
    task->data[4] = 4;
    task->data[5] = 0;
    StopMapMusic();
    PlayFanfare(MUS_TOO_BAD);
    PlaySE(SE_M_EXPLOSION);
}

static void ReelTime_WaitExplode(struct Task *task)
{
    gSpriteCoordOffsetY = task->data[4];
    SetGpuReg(REG_OFFSET_BG1VOFS, task->data[4]);
    if (task->data[5] & 0x01)
        task->data[4] = -task->data[4];
    if ((++task->data[5] & 0x1f) == 0)
        task->data[4] >>= 1;
    if (task->data[4] == 0)
    {
        DestroyReelTimeExplosionSprite();
        CreateReelTimeDuckSprites();
        CreateBrokenReelTimeMachineSprite();
        CreateReelTimeSmokeSprite();
        gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = FALSE;
        task->tState++;
        task->data[5] = 0;
    }
}

static void ReelTime_WaitSmoke(struct Task *task)
{
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    if (IsReelTimeSmokeAnimFinished())
    {
        task->tState++;
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
    {
        LoadBgTilemap(1, &sReelTimeWindow_Tilemap[a1 + (i - 4) * 20], 2, 32 * i + a0);
    }
}

static void ClearReelTimeWindowTilemap(s16 a0)
{
    u8 i;

    for (i = 4; i < 15; i++)
    {
        LoadBgTilemap(1, sEmptyTilemap, 2, 32 * i + a0);
    }
}

#undef tState

#define tState data[0]

// Info Box is the screen shown when Select is pressed
static void OpenInfoBox(u8 digDisplayId)
{
    u8 taskId = CreateTask(RunInfoBoxActions, 1);
    gTasks[taskId].data[1] = digDisplayId;
    RunInfoBoxActions(taskId);
}

static bool8 IsInfoBoxClosed(void)
{
    if (FindTaskIdByFunc(RunInfoBoxActions) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void RunInfoBoxActions(u8 taskId)
{
    sInfoBoxActions[gTasks[taskId].tState](&gTasks[taskId]);
}

static void InfoBox_FadeIn(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB(0, 0, 0));
    task->tState++;
}

static void InfoBox_WaitForFade(struct Task *task)
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
    AddTextPrinterParameterized3(1, 1, 2, 5, sColors_ReeltimeHelp, 0, gText_ReelTimeHelp);
    CopyWindowToVram(1, 3);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB(0, 0, 0));
    task->tState++;
}

static void InfoBox_AwaitPlayerInput(struct Task *task)
{
    if (JOY_NEW(B_BUTTON | SELECT_BUTTON))
    {
        FillWindowPixelBuffer(1, PIXEL_FILL(0));
        ClearWindowTilemap(1);
        CopyWindowToVram(1, 1);
        RemoveWindow(1);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB(0, 0, 0));
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
    LoadPikaPowerMeter(sSlotMachine->pikaPower);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB(0, 0, 0));
    task->tState++;
}

static void InfoBox_FreeTask(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(RunInfoBoxActions));
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
    sDigitalDisplayActions[gTasks[taskId].data[0]](&gTasks[taskId]);
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
    sprite->y = sSlotMachine->reelPixelOffsetsWhileStopping[sprite->data[0]] + 28 + sprite->data[2];
    sprite->sheetTileStart = GetSpriteTileStartByTag(GetTagAtRest(sprite->data[0], sprite->data[2] / 24));
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

static void CreateCoinNumberSprite(s16 x, s16 y, bool8 isPayout, s16 a3)
{
    struct Sprite *sprite = &gSprites[CreateSprite(&sSpriteTemplate_CoinNumber, x, y, 13)];
    sprite->oam.priority = 2;
    sprite->data[0] = isPayout;
    sprite->data[1] = a3;
    sprite->data[2] = a3 * 10;
    sprite->data[3] = -1;
}

static void SpriteCB_CoinNumber(struct Sprite *sprite)
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
    if (sImageTable_ReelTimePikachu != NULL)
        FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
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
    StartSpriteAnimIfDifferent(sprite, GetNearbyReelTimeTag(r0 / 20));
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

    if (sImageTable_ReelTimeMachineAntennae != NULL)
        FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
    if (sImageTable_ReelTimeMachine != NULL)
        FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);

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
    if (sImageTable_BrokenReelTimeMachine != NULL)
        FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
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
        MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(PALTAG_PIKA_AURA) << 4) + 0x103, colors[sprite->sColorIdx], colors[sprite->sColorIdx], colors[sprite->sColorIdx]);
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
    MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(PALTAG_PIKA_AURA) << 4) + 0x103, 0, 0, 0);
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
        if (sprite->x >= 0xd0)
        {
            sprite->x = 0xd0;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x += 4;
        if (sprite->x >= 0x110)
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
        if (sprite->x <= 0xd0)
        {
            sprite->x = 0xd0;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x -= 4;
        if (sprite->x <= 0x90)
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
        if (sprite->x >= 0xd0)
        {
            sprite->x = 0xd0;
            sprite->sState++;
        }
        break;
    case 3:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 4:
        sprite->x += 4;
        if (sprite->x >= 0xf8)
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
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], (IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY) << 4) + 0x100, 32);
        if (++sprite->data[2] >= 4)
        {
            sprite->data[1]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], (IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY) << 4) + 0x100, 32);
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
    LoadPalette(sDigitalDisplay_Pal, (IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY) << 4) + 0x100, 0x20);
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
    LoadPalette(gSlotMachineMenu_Pal, 0, 160);
    LoadPalette(sUnkPalette, 208, 32);
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

static const u8 sReelSymbolTileTags[NUM_REELS][SYMBOLS_PER_REEL] =
{
    [LEFT_REEL] = {
        GFXTAG_7_RED,
        GFXTAG_CHERRY,
        GFXTAG_AZURILL,
        GFXTAG_REPLAY,
        GFXTAG_POWER,
        GFXTAG_LOTAD,
        GFXTAG_7_BLUE,
        GFXTAG_LOTAD,
        GFXTAG_CHERRY,
        GFXTAG_POWER,
        GFXTAG_REPLAY,
        GFXTAG_AZURILL,
        GFXTAG_7_RED,
        GFXTAG_POWER,
        GFXTAG_LOTAD,
        GFXTAG_REPLAY,
        GFXTAG_AZURILL,
        GFXTAG_7_BLUE,
        GFXTAG_POWER,
        GFXTAG_LOTAD,
        GFXTAG_REPLAY
    },
    [MIDDLE_REEL] = {
        GFXTAG_7_RED,
        GFXTAG_CHERRY,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_AZURILL,
        GFXTAG_CHERRY,
        GFXTAG_REPLAY,
        GFXTAG_POWER,
        GFXTAG_POWER,
        GFXTAG_LOTAD,
        GFXTAG_7_BLUE,
        GFXTAG_LOTAD,
        GFXTAG_REPLAY,
        GFXTAG_CHERRY,
        GFXTAG_AZURILL,
        GFXTAG_LOTAD,
        GFXTAG_REPLAY,
        GFXTAG_CHERRY,
        GFXTAG_LOTAD,
        GFXTAG_REPLAY,
        GFXTAG_CHERRY
    },
    [RIGHT_REEL] = {
        GFXTAG_7_RED,
        GFXTAG_POWER,
        GFXTAG_7_BLUE,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_AZURILL,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_POWER,
        GFXTAG_AZURILL,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_AZURILL,
        GFXTAG_POWER,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_AZURILL,
        GFXTAG_POWER,
        GFXTAG_REPLAY,
        GFXTAG_LOTAD,
        GFXTAG_CHERRY
    },
};

static const u8 sReelTimeTags[] = {
    1, 0, 5, 4, 3, 2
};

static const s16 sInitialReelPositions[NUM_REELS][2] = {
    [LEFT_REEL]   = {0,  6},
    [MIDDLE_REEL] = {0, 10},
    [RIGHT_REEL]  = {0,  2}
};

static const u8 sLuckyRoundProbabilities[][3] = {
    {1, 1, 12},
    {1, 1, 14},
    {2, 2, 14},
    {2, 2, 14},
    {2, 3, 16},
    {3, 3, 16}
};

static const u8 sLuckyFlagProbabilities_Top3[][6] = {
    {25, 25, 30, 40, 40, 50},
    {25, 25, 30, 30, 35, 35},
    {25, 25, 30, 25, 25, 30}
};

static const u8 sLuckyFlagProbabilities_NotTop3[][6] = {
    {20, 25, 25, 20, 25, 25},
    {12, 15, 15, 18, 19, 22},
    {25, 25, 25, 30, 30, 40},
    {25, 25, 20, 20, 15, 15},
    {40, 40, 35, 35, 40, 40}
};

static const u8 sReeltimeProbabilities_UnluckyGame[][17] = {
    {243, 243, 243,  80,  80,  80,  80,  40,  40,  40,  40,  40,  40,   5,   5,   5,   5},
    {  5,   5,   5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100,   5},
    {  4,   4,   4,  20,  20,  20,  20,  80,  80,  80,  80,  80,  80, 100, 100, 100,  40},
    {  2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  45,  45,  45, 100},
    {  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   5,   5,   5, 100},
    {  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   6}
};

static const u8 sReelTimeProbabilities_LuckyGame[][17] = {
    { 243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160,  70,  70,  70,   5},
    {   5,   5,   5,  25,  25,  25,  25,   5,   5,   5,   5,   5,   5,   2,   2,   2,   6},
    {   4,   4,   4,  25,  25,  25,  25,  30,  30,  30,  30,  30,  30,  40,  40,  40,  35},
    {   2,   2,   2,   3,   3,   3,   3,  30,  30,  30,  30,  30,  30, 100, 100, 100,  50},
    {   1,   1,   1,   2,   2,   2,   2,  30,  30,  30,  30,  30,  30,  40,  40,  40, 100},
    {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   4,  60}
};

static const u16 sReelTimeExplodeProbability[] = {
    128, 175, 200, 225, 256
};

static const u16 sReelIncrementTable[][2] = {
    {10,  5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35}
};

static const u16 sReelTimeBonusIncrementTable[] = {
    0, 5, 10, 15, 20
};

// tentative name
static const u8 sBiasTags[] = {
  GFXTAG_REPLAY, GFXTAG_CHERRY, GFXTAG_LOTAD, GFXTAG_AZURILL, GFXTAG_POWER, GFXTAG_7_RED, GFXTAG_7_RED, GFXTAG_7_RED
};

static const u16 sLuckyFlagSettings_Top3[] = {
    LUCKY_BIAS_777, LUCKY_BIAS_REELTIME, LUCKY_BIAS_MIXED_777
};

static const u16 sLuckyFlagSettings_NotTop3[] = {
    LUCKY_BIAS_POWER, LUCKY_BIAS_AZURILL, LUCKY_BIAS_LOTAD, LUCKY_BIAS_CHERRY, LUCKY_BIAS_REPLAY
};

static const u8 sSymToMatch[] = {
    [GFXTAG_7_RED]   = MATCHED_777_RED,
    [GFXTAG_7_BLUE]  = MATCHED_777_BLUE,
    [GFXTAG_AZURILL] = MATCHED_AZURILL,
    [GFXTAG_LOTAD]   = MATCHED_LOTAD,
    [GFXTAG_CHERRY]  = MATCHED_1CHERRY,
    [GFXTAG_POWER]   = MATCHED_POWER,
    [GFXTAG_REPLAY]  = MATCHED_REPLAY
};

static const u16 sSlotMatchFlags[] = {
    [MATCHED_1CHERRY]   = 1 << MATCHED_1CHERRY,
    [MATCHED_2CHERRY]   = 1 << MATCHED_2CHERRY,
    [MATCHED_REPLAY]    = 1 << MATCHED_REPLAY,
    [MATCHED_LOTAD]     = 1 << MATCHED_LOTAD,
    [MATCHED_AZURILL]   = 1 << MATCHED_AZURILL,
    [MATCHED_POWER]     = 1 << MATCHED_POWER,
    [MATCHED_777_MIXED] = 1 << MATCHED_777_MIXED,
    [MATCHED_777_RED]   = 1 << MATCHED_777_RED,
    [MATCHED_777_BLUE]  = 1 << MATCHED_777_BLUE
};

static const u16 sSlotPayouts[] = {
    [MATCHED_1CHERRY]   = 2,
    [MATCHED_2CHERRY]   = 4,
    [MATCHED_REPLAY]    = 0,
    [MATCHED_LOTAD]     = 6,
    [MATCHED_AZURILL]   = 12,
    [MATCHED_POWER]     = 3,
    [MATCHED_777_MIXED] = 90,
    [MATCHED_777_RED]   = 300,
    [MATCHED_777_BLUE]  = 300
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .mosaic = 0,
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
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_REEL_TIME_PIKACHU,
    .oam = &sOam_64x64,
    .anims = sAnims_ReelTimePikachu,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimePikachu
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_REEL_TIME_MISC,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_REEL_TIME_MACHINE,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_REEL_TIME_MACHINE,
    .oam = &sOam_8x16,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_ReelTimeNumbers,
    .images = sImageTable_ReelTimeNumbers,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeNumbers
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeShadow,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumberGap =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeNumberGap,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x32,
    .anims = sAnims_ReelTimeBolt,
    .images = sImageTable_ReelTimeBolt,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeBolt
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_PIKA_AURA,
    .oam = &sOam_32x64,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimePikachuAura,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimePikachuAura
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_EXPLOSION,
    .oam = &sOam_32x32,
    .anims = sAnims_ReelTimeExplosion,
    .images = sImageTable_ReelTimeExplosion,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeExplosion
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_8x8,
    .anims = sAnims_ReelTimeDuck,
    .images = sImageTable_ReelTimeDuck,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ReelTimeDuck
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_16x16,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_ReelTimeSmoke,
    .affineAnims = sAffineAnims_ReelTimeSmoke,
    .callback = SpriteCB_ReelTimeSmoke
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reel =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Time =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Insert =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Stop =
{
    .tileTag = 18,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Win =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_64x32,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Lose =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_64x32,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Bonus =
{
    .tileTag = 19,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Big =
{
    .tileTag = 20,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reg =
{
    .tileTag = 21,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_AButton =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_32x32,
    .anims = sAnims_DigitalDisplay_AButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Smoke =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Number =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_16x16,
    .anims = sAnims_DigitalDisplay_Number,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Pokeball =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_DigitalDisplay_Pokeball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_DPad =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_DIG_DISPLAY,
    .oam = &sOam_8x8,
    .anims = sAnims_DigitalDisplay_DPad,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt =
{
    .tileTag = 0xFFFF,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_8x8,
    .anims = sAnims_SingleFrame,
    .images = sImageTable_PikaPowerBolt,
    .affineAnims = sAffineAnims_PikaPowerBolt,
    .callback = SpriteCB_PikaPowerBolt
};

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
        -24,
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

static const u16 sUnused[] =
{
    0x6F7B,
    0x6968,
    0x36AB,
    0x7FFF,
    0x5750,
    0x7EC0,
    0x02BA,
    0x02BA,
    0x01FD,
    0x01FD,
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
    [MATCH_MIDDLE_ROW] = &gSlotMachineMenu_Pal[74],
    [MATCH_TOP_ROW]    = &gSlotMachineMenu_Pal[75],
    [MATCH_BOTTOM_ROW] = &gSlotMachineMenu_Pal[76],
    [MATCH_NWSE_DIAG]  = &gSlotMachineMenu_Pal[77],
    [MATCH_NESW_DIAG]  = &gSlotMachineMenu_Pal[78],
};

static const u8 sMatchLinePalOffsets[NUM_MATCH_LINES] = {
    [MATCH_MIDDLE_ROW] = 74,
    [MATCH_TOP_ROW]    = 75,
    [MATCH_BOTTOM_ROW] = 76,
    [MATCH_NWSE_DIAG]  = 78, // Diag colors flipped for some reason
    [MATCH_NESW_DIAG]  = 77  // Doesn't matter as both are identical
};

static const u8 sBetToMatchLineIds[MAX_BET][2] =
{
    {MATCH_MIDDLE_ROW, MATCH_MIDDLE_ROW}, // Bet 1
    {MATCH_TOP_ROW, MATCH_BOTTOM_ROW},    // Bet 2
    {MATCH_NWSE_DIAG, MATCH_NESW_DIAG},   // Bet 3
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
static const u16 sUnkPalette[] = INCBIN_U16("graphics/slot_machine/85A8524.bin");

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
