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

#define REEL_NUM_TAGS      21
#define REEL_TAG_HEIGHT    24

// Lucky Flags
#define LUCKY_BIAS_REPLAY    (1 << 0)
#define LUCKY_BIAS_CHERRY    (1 << 1)
#define LUCKY_BIAS_LOTAD     (1 << 2)
#define LUCKY_BIAS_AZURILL   (1 << 3)
#define LUCKY_BIAS_POWER     (1 << 4)
#define LUCKY_BIAS_REELTIME  (1 << 5)
#define LUCKY_BIAS_MIXED_777 (1 << 6)
#define LUCKY_BIAS_777       (1 << 7)

#define SLOT_MACHINE_TAG_7_RED   0
#define SLOT_MACHINE_TAG_7_BLUE  1
#define SLOT_MACHINE_TAG_AZURILL 2
#define SLOT_MACHINE_TAG_LOTAD   3
#define SLOT_MACHINE_TAG_CHERRY  4
#define SLOT_MACHINE_TAG_POWER   5
#define SLOT_MACHINE_TAG_REPLAY  6

#define SLOT_MACHINE_MATCHED_1CHERRY   0
#define SLOT_MACHINE_MATCHED_2CHERRY   1
#define SLOT_MACHINE_MATCHED_REPLAY    2
#define SLOT_MACHINE_MATCHED_LOTAD     3
#define SLOT_MACHINE_MATCHED_AZURILL   4
#define SLOT_MACHINE_MATCHED_POWER     5
#define SLOT_MACHINE_MATCHED_777_MIXED 6
#define SLOT_MACHINE_MATCHED_777_RED   7
#define SLOT_MACHINE_MATCHED_777_BLUE  8
#define SLOT_MACHINE_MATCHED_NONE      9

#define LEFT_REEL   0
#define MIDDLE_REEL 1
#define RIGHT_REEL  2
#define NUM_REELS   3

enum {
    SLOT_ACTION_UNFADE,
    SLOT_ACTION_1,
    SLOT_ACTION_2,
    SLOT_ACTION_3,
    SLOT_ACTION_4,
    SLOT_ACTION_BET_INPUT,
    SLOT_ACTION_6,
    SLOT_ACTION_7,
    SLOT_ACTION_8,
    SLOT_ACTION_9,
    SLOT_ACTION_10,
    SLOT_ACTION_11,
    SLOT_ACTION_12,
    SLOT_ACTION_13,
    SLOT_ACTION_14,
    SLOT_ACTION_15,
    SLOT_ACTION_16,
    SLOT_ACTION_17,
    SLOT_ACTION_18,
    SLOT_ACTION_19,
    SLOT_ACTION_20,
    SLOT_ACTION_ASK_QUIT,
    SLOT_ACTION_HANDLE_QUIT_INPUT,
    SLOT_ACTION_MSG_MAX_COINS,
    SLOT_ACTION_WAIT_MSG_MAX_COINS,
    SLOT_ACTION_MSG_NO_MORE_COINS,
    SLOT_ACTION_WAIT_MSG_NO_MORE_COINS,
    SLOT_ACTION_END,
    SLOT_ACTION_FREE,
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
    /*0x06*/ u8 luckySpinsLeft;  // tentative
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
    /*0x2E*/ s16 reelExtraTurns[3];
    /*0x34*/ s16 winnerRows[3];
    /*0x3A*/ u8 slotReelTasks[3];
    /*0x3D*/ u8 unkTaskPointer3D;
    /*0x3E*/ u8 unkTaskPointer3E;
    /*0x3F*/ u8 reelTimePikachuSpriteId;
    /*0x40*/ u8 unk40;
    /*0x41*/ u8 reelTimeExplosionSpriteId;
    /*0x42*/ u8 reelTimeBrokenMachineSpriteId;
    /*0x43*/ u8 reelTimeSmokeSpriteId;
    /*0x44*/ u8 unk44[5];
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
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
};

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
static void SlotMachineSetup_AllocDigDisplayGfx(void);
static void SlotMachineSetup_SetDigDisplayImagePtrs(void);
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
static bool8 SlotAction_HandleBetInput(struct Task *task);
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
static bool8 SlotAction_HandleQuitGameInput(struct Task *task);
static bool8 SlotAction_PrintMessage_9999Coins(struct Task *task);
static bool8 SlotAction_WaitMessage_9999Coins(struct Task *task);
static bool8 SlotAction_PrintMessage_NoMoreCoins(struct Task *task);
static bool8 SlotAction_WaitMessage_NoMoreCoins(struct Task *task);
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
static u8 GetTagAtRest(u8 x, s16 y);
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
static void Task_CreatePikaPowerBolt(u8 taskId);
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
static void ReeltimeAction13(struct Task *);
static void ReeltimeAction14(struct Task *);
static void ReeltimeAction15(struct Task *);
static void ReeltimeAction16(struct Task *);
static void ReeltimeAction17(struct Task *);
static void sub_8104A40(s16, s16);
static void sub_8104A88(s16);
static void OpenInfoBox(u8);
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
static void CreateDigitalDisplayScene(u8 arg0);
static bool8 sub_8104E18(void);
static void nullsub_69(struct Task *task);
static void sub_8104E74_(u8 taskId);
static void CreateReelSymbolSprites(void);
static void CreateCreditPayoutNumberSprites(void);
static void CreateCoinNumberSprite(s16 x, s16 y, u8 a2, s16 a3);
static void CreateReelBackgroundSprite(void);
static void CreateReelTimePikachuSprite(void);
static void DestroyReelTimePikachuSprite(void);
static void CreateReelTimeMachineSprites(void);
static void CreateBrokenReelTimeMachineSprite(void);
static void CreateReelTimeNumberSprites(void);
static void CreateReelTimeShadowSprites(void);
static void sub_810545C(void);
static void DestroyReelTimeMachineSprites(void);
static void DestroyReelTimeShadowSprites(void);
static void DestroyBrokenReelTimeMachineSprite(void);
static void CreateReelTimeBoltSprites(void);
static void sub_8105688(s16 a0);
static void DestroyReelTimeBoltSprites(void);
static void CreateReelTimePikachuAuraSprites(void);
static void sub_81057E8(s16 a0);
static void DestroyReelTimePikachuAuraSprites(void);
static void CreateReelTimeExplosionSprite(void);
static void DestroyReelTimeExplosionSprite(void);
static void CreateReelTimeDuckSprites(void);
static void DestroyReelTimeDuckSprites(void);
static void CreateReelTimeSmokeSprite(void);
static bool8 sub_8105ACC(void);
static void DestroyReelTimeSmokeSprite(void);
static u8 CreatePikaPowerBoltSprite(s16 x, s16 y);
static void sub_8105B88(u8 spriteId);
static u8 CreateDigitalDisplaySprite(u8 templateIdx, void (*callback)(struct Sprite*), s16 x, s16 y, s16 a4);
static void sub_81063C0(void);
static void sub_8106404(void);
static void sub_8106448(void);
static void sub_81064B8(void);
static void sub_81065A8(s16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
static void sub_81065DC(void);
static void sub_812F958(void);
static void sub_812F968(void);
static void LoadSlotMachineWheelOverlay(void);
static u8 CreateStdDigitalDisplaySprite(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2);
static void sub_8105C64(struct Sprite *sprite);
static void sub_8105F54(struct Sprite *sprite);
static void sub_8105F9C(struct Sprite *sprite);
static void sub_8105EB4(struct Sprite *sprite);
static void sub_8105C6C(struct Sprite *sprite);
static void sub_8105CF0(struct Sprite *sprite);
static void sub_8105D08(struct Sprite *sprite);
static void sub_8105D20(struct Sprite *sprite);
static void sub_8105D3C(struct Sprite *sprite);
static void sub_8105DA4(struct Sprite *sprite);
static void sub_8105E08(struct Sprite *sprite);
static void sub_8106058(struct Sprite *sprite);
static void sub_81060FC(struct Sprite *sprite);
static void sub_81061C8(struct Sprite *sprite);
static void sub_8106230(struct Sprite *sprite);
static void sub_810639C(void);
static void sub_8106364(void);
static void sub_8106370(void);
static void nullsub_70(void);
static void SpriteCB_ReelSymbol(struct Sprite *sprite);
static void SpriteCB_CoinNumber(struct Sprite *sprite);
static void SpriteCB_ReelTimePikachu(struct Sprite *sprite);
static void SpriteCB_ReelTimeNumbers(struct Sprite *sprite);
static void SpriteCB_ReelTimeBolt(struct Sprite *sprite);
static void SpriteCB_ReelTimePikachuAura(struct Sprite *sprite);
static void SpriteCB_ReelTimeExplosion(struct Sprite *sprite);
static void SpriteCB_ReelTimeDuck(struct Sprite *sprite);
static void SpriteCB_ReelTimeSmoke(struct Sprite *sprite);
static void SpriteCB_PikaPowerBolt(struct Sprite *sprite);

// Ewram variables
static EWRAM_DATA u16 *sUnknown_0203AAC8 = NULL;
static EWRAM_DATA u16 *sSelectedPikaPowerTile = NULL;
static EWRAM_DATA u16 *sUnknown_0203AAD0 = NULL;
static EWRAM_DATA u8 *sDigitalDisplayGfxPtr = NULL;
static EWRAM_DATA u8 *sReelTimeGfxPtr = NULL;
static EWRAM_DATA u16 *sUnknown_0203AADC = NULL;
static EWRAM_DATA u8 *sUnknown_0203AAE0 = NULL;
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
static EWRAM_DATA struct SpriteSheet *sUnknown_0203AB2C = NULL;
static EWRAM_DATA struct SpriteSheet *sUnknown_0203AB30 = NULL; // Mix of digital display spritesheets and reel spritesheets
static EWRAM_DATA struct SlotMachine *sSlotMachine = NULL;

// IWRAM bss
static struct SpriteFrameImage *sImageTables_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];

// Const rom data.
static const struct DigitalDisplaySprite *const sDigitalDisplayScenes[];
static const u16 gPalette_83EDE24[];
static const u8 gLuckyRoundProbabilities[][3];
static const u8 gBiasTags[];
static const u16 gLuckyFlagSettings_Top3[];
static const u16 gLuckyFlagSettings_NotTop3[];
static const s16 gUnknown_083ECE7E[][2];
static const SpriteCallback gUnknown_083ECF0C[];
static const struct SpriteTemplate *const sSpriteTemplates_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];
static const struct SubspriteTable *const sSubspriteTables_DigitalDisplay[NUM_DIG_DISPLAY_SPRITES];
static const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion;
static const u8 gUnknown_083ECC58[2];
static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura;
static const u16 gProbabilityTable_SkipToReeltimeAction14[];
static const u16 *const gUnknown_083EDE10[];
static const u16 gReelIncrementTable[][2];
static const u16 gReelTimeBonusIncrementTable[];
static const u16 gSlotMatchFlags[];
static const u16 gSlotPayouts[];
static const u8 *const gUnknown_083EDCE4;
static const u8 *const gUnknown_083EDCDC;
static const u32 sReelTimeGfx[];
static const struct SpriteSheet gSlotMachineSpriteSheets[22];
static const struct SpritePalette gSlotMachineSpritePalettes[];
static const u16 *const gUnknown_083EDE20;
static const s16 gInitialReelPositions[][2];
static const u8 gLuckyFlagProbabilities_Top3[][6];
static const u8 gLuckyFlagProbabilities_NotTop3[][6];
static const u8 gReeltimeProbabilities_UnluckyGame[][17];
static const u8 gReelTimeProbabilities_LuckyGame[][17];
static const u8 gSym2Match[];
static const u8 gReelTimeTags[];
static const u8 sReelSymbols[NUM_REELS][REEL_NUM_TAGS];
static const u8 *const gUnknown_083EDD08[];
static const u16 *const gUnknown_083EDD1C[];
static const u8 gUnknown_083EDD30[];
static const u8 gBettingTilesId[][2];
static const u8 gNumberBettingTiles[];
static const u16 *const gUnknown_083EDDA0[];
static const u16 *const gUnknown_083EDDAC;
static const u16 gReelTimeWindowTilemap[];
static const u16 gUnknown_085A9898[];
static void (*const gUnknown_083ED064[])(void);
static const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt;
static const struct SpriteTemplate gSpriteTemplate_83ED4EC; // reel time. machine number background?
static const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers;
static const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae;
static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine;
static const struct SpriteTemplate sSpriteTemplate_ReelBackground;
static const struct SpriteTemplate sSpriteTemplate_CoinNumber;
static const struct SpriteTemplate sSpriteTemplate_ReelSymbol;
static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachu;
static const struct SubspriteTable gSubspriteTables_83ED7D4[];
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

static const struct WindowTemplate gUnknown_085A7444 =
{
    .bg = 0, 
    .tilemapLeft = 1, 
    .tilemapTop = 3, 
    .width = 20, 
    .height = 13, 
    .paletteNum = 13, 
    .baseBlock = 1
};

static const u8 sColors_ReeltimeHelp[] = {TEXT_COLOR_LIGHT_GREY, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};

bool8 (*const SlotActions[])(struct Task *task) =
{
    [SLOT_ACTION_UNFADE] = SlotAction_UnfadeScreen,
    [SLOT_ACTION_1] = SlotAction_WaitForUnfade,
    [SLOT_ACTION_2] = SlotAction_SetSlotMachineVars,
    [SLOT_ACTION_3] = SlotAction3,
    [SLOT_ACTION_4] = SlotAction4,
    [SLOT_ACTION_BET_INPUT] = SlotAction_HandleBetInput,
    [SLOT_ACTION_6] = SlotAction_PrintYouDontHaveThreeCoins,
    [SLOT_ACTION_7] = SlotAction_ExitYouDontHaveThreeCoinsMessage,
    [SLOT_ACTION_8] = SlotAction_GivingInformation,
    [SLOT_ACTION_9] = SlotAction9,
    [SLOT_ACTION_10] = SlotAction10,
    [SLOT_ACTION_11] = SlotAction_SetLuckySpins,
    [SLOT_ACTION_12] = SlotAction_AwaitReelStop,
    [SLOT_ACTION_13] = SlotAction_WaitForAllReelsToStop,
    [SLOT_ACTION_14] = SlotAction_CheckMatches,
    [SLOT_ACTION_15] = SlotAction_WaitForPayoutToBeAwarded,
    [SLOT_ACTION_16] = SlotAction_EndOfRoll,
    [SLOT_ACTION_17] = SlotAction_MatchedPower,
    [SLOT_ACTION_18] = SlotAction18,
    [SLOT_ACTION_19] = SlotAction_Loop,
    [SLOT_ACTION_20] = SlotAction_NoMatches,
    [SLOT_ACTION_ASK_QUIT] = SlotAction_PrintQuitTheGame,
    [SLOT_ACTION_HANDLE_QUIT_INPUT] = SlotAction_HandleQuitGameInput,
    [SLOT_ACTION_MSG_MAX_COINS] = SlotAction_PrintMessage_9999Coins,
    [SLOT_ACTION_WAIT_MSG_MAX_COINS] = SlotAction_WaitMessage_9999Coins,
    [SLOT_ACTION_MSG_NO_MORE_COINS] = SlotAction_PrintMessage_NoMoreCoins,
    [SLOT_ACTION_WAIT_MSG_NO_MORE_COINS] = SlotAction_WaitMessage_NoMoreCoins,
    [SLOT_ACTION_END] = SlotAction_EndGame,
    [SLOT_ACTION_FREE] = SlotAction_FreeDataStructures,
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

void (*const sPikaPowerBoltFuncs[])(struct Task *task) =
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
            SlotMachineSetup_AllocDigDisplayGfx();
            gMain.state++;
            break;
        case 9:
            SlotMachineSetup_SetDigDisplayImagePtrs();
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

static void PlaySlotMachine_Internal(u8 slotMachineIndex, MainCallback exitCallback)
{
    struct Task *task = &gTasks[CreateTask(SlotMachineDummyTask, 0xFF)];
    task->data[0] = slotMachineIndex;
    StoreWordInTwoHalfwords(task->data + 1, (intptr_t)exitCallback);
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
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
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
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reelTimeSpinsUsed = 0;
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
        sSlotMachine->reelPositions[i] = gInitialReelPositions[i][sSlotMachine->luckyGame] % REEL_NUM_TAGS;
        sSlotMachine->reelPixelOffsets[i] = REEL_NUM_TAGS * REEL_TAG_HEIGHT - sSlotMachine->reelPositions[i] * REEL_TAG_HEIGHT;
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
    CreateReelSymbolSprites();
    CreateCreditPayoutNumberSprites();
    sub_8103DC8();
    CreateReelBackgroundSprite();
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

// SLOT_ACTION_1
static bool8 SlotAction_WaitForUnfade(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

// SLOT_ACTION_2
static bool8 SlotAction_SetSlotMachineVars(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currReel = 0;
    sSlotMachine->luckyFlags &= (LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
    sSlotMachine->state = SLOT_ACTION_4;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = SLOT_ACTION_MSG_NO_MORE_COINS;
    }
    else if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->state = SLOT_ACTION_3;
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
    }
    return TRUE;
}

// SLOT_ACTION_3
static bool8 SlotAction3(struct Task *task)
{
    if (sub_8104E18())
        sSlotMachine->state = SLOT_ACTION_4;
    return FALSE;
}

// SLOT_ACTION_4
static bool8 SlotAction4(struct Task *task)
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
        sSlotMachine->state = SLOT_ACTION_8;
    }
    else if (JOY_NEW(R_BUTTON))  // bet the max amount
    {
        if (sSlotMachine->coins - (MAX_BET - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < MAX_BET; i++)
                LoadBetTiles(i);
            sSlotMachine->coins -= (MAX_BET - sSlotMachine->bet);
            sSlotMachine->bet = MAX_BET;
            sSlotMachine->state = SLOT_ACTION_9;
            PlaySE(SE_REGI);
        }
        else  // you didn't have enough coins to bet the max
        {
            sSlotMachine->state = SLOT_ACTION_6;
        }
    }
    else
    {
        // Increase bet
        if (JOY_NEW(DPAD_DOWN) && sSlotMachine->coins != 0)
        {
            PlaySE(SE_REGI);
            LoadBetTiles(sSlotMachine->bet);
            sSlotMachine->coins--;
            sSlotMachine->bet++;
        }

        // Maxed bet or finished betting
        if (sSlotMachine->bet >= MAX_BET || (sSlotMachine->bet != 0 && JOY_NEW(A_BUTTON)))
            sSlotMachine->state = SLOT_ACTION_9;

        // Quit prompt
        if (JOY_NEW(B_BUTTON))
            sSlotMachine->state = SLOT_ACTION_ASK_QUIT;
    }
    return FALSE;
}

static bool8 SlotAction_PrintYouDontHaveThreeCoins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouDontHaveThreeCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_7;
    return FALSE;
}

static bool8 SlotAction_ExitYouDontHaveThreeCoinsMessage(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    }
    return FALSE;
}

static bool8 SlotAction_GivingInformation(struct Task *task)
{
    if (IsInfoBoxClosed())
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
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
        sSlotMachine->state = SLOT_ACTION_10;
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->state = SLOT_ACTION_11;
    }
    sSlotMachine->reelIncrement = 8;
    if (sSlotMachine->reelTimeSpinsLeft)
        sSlotMachine->reelIncrement = SlowReelSpeed();
    return FALSE;
}

static bool8 SlotAction10(struct Task *task)
{
    if (IsFinalTask_RunReelTimeActions())
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->luckyFlags &= ~LUCKY_BIAS_REELTIME;
        sSlotMachine->state = SLOT_ACTION_11;
    }
    return FALSE;
}

static bool8 SlotAction_SetLuckySpins(struct Task *task)
{
    if (++task->data[0] >= 30)
    {
        SetLuckySpins();
        sSlotMachine->state = SLOT_ACTION_12;
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
        sSlotMachine->state = SLOT_ACTION_13;
    }
    return FALSE;
}

static bool8 SlotAction_WaitForAllReelsToStop(struct Task *task)
{
    if (!IsSlotReelMoving(sSlotMachine->currReel))
    {
        sSlotMachine->currReel++;
        sSlotMachine->state = SLOT_ACTION_12;
        if (sSlotMachine->currReel > 2)
        {
            sSlotMachine->state = SLOT_ACTION_14;
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
    if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->reelTimeSpinsLeft--;
        sSlotMachine->reelTimeSpinsUsed++;
    }

    if (sSlotMachine->matchedSymbols)
    {
        sSlotMachine->state = SLOT_ACTION_15;
        AwardPayout();
        sub_8103F70();
        if ((sSlotMachine->netCoinLoss -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->netCoinLoss = 0;
        }
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            PlayFanfare(MUS_ME_B_BIG);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_BIG);
        }
        else if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_777_MIXED))
        {
            PlayFanfare(MUS_ME_B_BIG);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_REG);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            CreateDigitalDisplayScene(DIG_DISPLAY_WIN);
        }
        // if you matched 777...
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_MIXED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
        {
            sSlotMachine->luckyFlags &= ~(LUCKY_BIAS_777 | LUCKY_BIAS_MIXED_777);
            if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_BLUE) | (1 << SLOT_MACHINE_MATCHED_777_RED)))
            {
                sSlotMachine->reelTimeSpinsLeft = 0;
                sSlotMachine->reelTimeSpinsUsed = 0;
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
        CreateDigitalDisplayScene(DIG_DISPLAY_LOSE);
        sSlotMachine->state = SLOT_ACTION_20;
        if ((sSlotMachine->netCoinLoss += sSlotMachine->bet) > MAX_COINS)
            sSlotMachine->netCoinLoss = MAX_COINS;
    }
    return FALSE;
}

static bool8 SlotAction_WaitForPayoutToBeAwarded(struct Task *task)
{
    if (IsFinalTask_RunAwardPayoutActions())
        sSlotMachine->state = SLOT_ACTION_16;
    return FALSE;
}

static bool8 SlotAction_EndOfRoll(struct Task *task)
{
    if (sub_8103FA0())
    {
        sSlotMachine->state = SLOT_ACTION_19;
        if (sSlotMachine->matchedSymbols & ((1 << SLOT_MACHINE_MATCHED_777_RED) | (1 << SLOT_MACHINE_MATCHED_777_BLUE)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->currReel = 0;
            sSlotMachine->state = SLOT_ACTION_9;
        }
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_POWER))
            sSlotMachine->state = SLOT_ACTION_17;
        if (sSlotMachine->reelTimeSpinsLeft && sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
            sSlotMachine->state = SLOT_ACTION_18;
        }
    }
    return FALSE;
}

static bool8 SlotAction_MatchedPower(struct Task *task)
{
    if (!sub_81040C8())
    {
        sSlotMachine->state = SLOT_ACTION_19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = SLOT_ACTION_9;
            if (sSlotMachine->reelTimeSpinsLeft)
            {
                CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
                sSlotMachine->state = SLOT_ACTION_18;
            }
        }
    }
    return FALSE;
}

static bool8 SlotAction18(struct Task *task)
{
    if (sub_8104E18())
    {
        sSlotMachine->state = SLOT_ACTION_19;
        if (sSlotMachine->matchedSymbols & (1 << SLOT_MACHINE_MATCHED_REPLAY))
        {
            sSlotMachine->state = SLOT_ACTION_9;
        }
    }
    return FALSE;
}

static bool8 SlotAction_Loop(struct Task *task)
{
    sub_8103D8C(0);
    sub_8103D8C(1);
    sub_8103D8C(2);
    sSlotMachine->state = SLOT_ACTION_2;
    return FALSE;
}

static bool8 SlotAction_NoMatches(struct Task *task)
{
    if (++task->data[1] > 64)
    {
        task->data[1] = 0;
        sSlotMachine->state = SLOT_ACTION_19;
    }
    return FALSE;
}

static bool8 SlotAction_PrintQuitTheGame(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_QuitTheGame, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x180, 0xE, 0xF);
    sSlotMachine->state = SLOT_ACTION_HANDLE_QUIT_INPUT;
    return FALSE;
}

static bool8 SlotAction_HandleQuitGameInput(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0) // player chooses to quit
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sub_8103D8C(0);
        sub_8103D8C(1);
        sub_8103D8C(2);
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

static bool8 SlotAction_PrintMessage_9999Coins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveGot9999Coins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_WAIT_MSG_MAX_COINS;
    return FALSE;
}

static bool8 SlotAction_WaitMessage_9999Coins(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_BET_INPUT;
    }
    return FALSE;
}

static bool8 SlotAction_PrintMessage_NoMoreCoins(struct Task *task)
{
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized(0, 1, gText_YouveRunOutOfCoins, 0, 1, 0, 0);
    CopyWindowToVram(0, 3);
    sSlotMachine->state = SLOT_ACTION_WAIT_MSG_NO_MORE_COINS;
    return FALSE;
}

static bool8 SlotAction_WaitMessage_NoMoreCoins(struct Task *task)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(0, TRUE);
        sSlotMachine->state = SLOT_ACTION_END;
    }
    return FALSE;
}

static bool8 SlotAction_EndGame(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    AlertTVOfNewCoinTotal(GetCoins());
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    sSlotMachine->state++; // SLOT_ACTION_FREE
    return FALSE;
}

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
        FREE_AND_SET_NULL(sUnknown_0203AAC8);
        FREE_AND_SET_NULL(sSelectedPikaPowerTile);
        FREE_AND_SET_NULL(sUnknown_0203AAD0);
        FREE_AND_SET_NULL(sDigitalDisplayGfxPtr);
        FREE_AND_SET_NULL(sReelTimeGfxPtr);
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
    value = gReelIncrementTable[i][1] + gReelTimeBonusIncrementTable[sSlotMachine->reelTimeSpinsUsed];
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

    c1 = GetTagAtRest(LEFT_REEL, 1);
    c2 = GetTagAtRest(MIDDLE_REEL, 1);
    c3 = GetTagAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbolsInRow(c1, c2, c3);
    if (match != SLOT_MACHINE_MATCHED_NONE)
    {
        if (match == SLOT_MACHINE_MATCHED_1CHERRY)
            match = SLOT_MACHINE_MATCHED_2CHERRY;
        sSlotMachine->payout += gSlotPayouts[match];
        sSlotMachine->matchedSymbols |= gSlotMatchFlags[match];
        sub_8103E04(1);
    }
    c1 = GetTagAtRest(LEFT_REEL, 3);
    c2 = GetTagAtRest(MIDDLE_REEL, 3);
    c3 = GetTagAtRest(RIGHT_REEL, 3);
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

    c1 = GetTagAtRest(LEFT_REEL, 1);
    c2 = GetTagAtRest(MIDDLE_REEL, 2);
    c3 = GetTagAtRest(RIGHT_REEL, 3);
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
    c1 = GetTagAtRest(LEFT_REEL, 3);
    c2 = GetTagAtRest(MIDDLE_REEL, 2);
    c3 = GetTagAtRest(RIGHT_REEL, 1);
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
        if (sSlotMachine->coins < MAX_COINS)
            sSlotMachine->coins++;
        task->data[1] = 8;
        if (gMain.heldKeys & A_BUTTON)
            task->data[1] = 4;
    }
    if (IsFanfareTaskInactive() && gMain.newKeys & START_BUTTON)
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
    if (sub_8103E7C())
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
    s16 pos = (sSlotMachine->reelPositions[reel] + offset) % REEL_NUM_TAGS;
    if (pos < 0)
        pos += REEL_NUM_TAGS;
    return sReelSymbols[reel][pos];
}

// Calculates GetTagAtRest as if the reel were snapped downwards into place.
static u8 GetTag(u8 reel, s16 offset)
{
    s16 inc = 0;
    s16 pixelOffset = sSlotMachine->reelPixelOffsets[reel] % REEL_TAG_HEIGHT;
    if (pixelOffset != 0)
        inc = -1;
    return GetTagAtRest(reel, offset + inc);
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
    sSlotMachine->reelPositions[reelIndex] = REEL_NUM_TAGS - sSlotMachine->reelPixelOffsets[reelIndex] / 24;
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

    if (sSlotMachine->reelTimeSpinsLeft == 0 && (sSlotMachine->luckyFlags == 0 || sSlotMachine->luckySpinsLeft == 0 || !DecideReelTurns_BiasTag[task->data[15]]()))
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
    if (GetTag(LEFT_REEL, 1 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY || GetTag(LEFT_REEL, 2 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY || GetTag(LEFT_REEL, 3 - offsetFromCenter) == SLOT_MACHINE_TAG_CHERRY)
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
    u8 tag1 = GetTag(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
    u8 tag2 = GetTag(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
    // if tags match in first 2 reels...
    if (tag1 == tag2)
    {
        //...spin until you get non-matching tag
        while (1)
        {
            u8 tag3;
            if (!(tag1 == (tag3 = GetTag(RIGHT_REEL, 2 - i)) || (tag1 == SLOT_MACHINE_TAG_7_RED && tag3 == SLOT_MACHINE_TAG_7_BLUE) || (tag1 == SLOT_MACHINE_TAG_7_BLUE && tag3 == SLOT_MACHINE_TAG_7_RED)))
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
    sSlotMachine->unkTaskPointer3E = CreateTask(Task_CreatePikaPowerBolt, 8);
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

static void Task_CreatePikaPowerBolt(u8 taskId)
{
    sPikaPowerBoltFuncs[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void nullsub_68(struct Task *task)
{
}

static void sub_810411C(struct Task *task)
{
    task->data[2] = CreatePikaPowerBoltSprite((task->data[1] << 3) + 20, 20);
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

    for (i = 2; i < NUM_TASK_DATA; i++)
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
    sSlotMachine->reelTimeSpinsLeft = 0;
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
    CreateReelTimeMachineSprites();
    CreateReelTimePikachuSprite();
    CreateReelTimeNumberSprites();
    CreateReelTimeShadowSprites();
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
        CreateReelTimeBoltSprites();
        CreateReelTimePikachuAuraSprites();
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
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimePikachuSpriteId, sp0[r5]);
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
        StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimePikachuSpriteId, 3);
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
            if (sSlotMachine->reelTimeSpinsLeft <= task->data[6])
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
        DestroyReelTimeBoltSprites();
        DestroyReelTimePikachuAuraSprites();
        task->data[0]++;
        if(sSlotMachine->reelTimeDraw == 0)
        {
            task->data[4] = 0xa0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimePikachuSpriteId, 5);
            PlayFanfare(MUS_ME_ZANNEN);
        }
        else
        {
            task->data[4] = 0xc0;
            StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimePikachuSpriteId, 4);
            gSprites[sSlotMachine->reelTimePikachuSpriteId].animCmdIndex = 0;
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
        DestroyTask(FindTaskIdByFunc(RunReeltimeActions));
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
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
    DestroyReelTimeMachineSprites();
    DestroyReelTimeBoltSprites();
    DestroyReelTimePikachuAuraSprites();
    CreateReelTimeExplosionSprite();
    gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = TRUE;
    StartSpriteAnimIfDifferent(gSprites + sSlotMachine->reelTimePikachuSpriteId, 5);
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
        DestroyReelTimeExplosionSprite();
        CreateReelTimeDuckSprites();
        CreateBrokenReelTimeMachineSprite();
        CreateReelTimeSmokeSprite();
        gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = FALSE;
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
        DestroyReelTimeSmokeSprite();
    }
}

static void ReeltimeAction17(struct Task *task)
{
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    DestroyReelTimePikachuSprite();
    DestroyBrokenReelTimeMachineSprite();
    DestroyReelTimeShadowSprites();
    DestroyReelTimeDuckSprites();
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

static void OpenInfoBox(u8 digDisplayId)
{
    u8 taskId = CreateTask(RunInfoBoxActions, 1);
    gTasks[taskId].data[1] = digDisplayId;
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
    AddTextPrinterParameterized3(1, 1, 2, 5, sColors_ReeltimeHelp, 0, gText_ReelTimeHelp);
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
    CreateDigitalDisplayScene(task->data[1]);
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
    for (i = 4; i < NUM_TASK_DATA; i++)
        task->data[i] = MAX_SPRITES;
}

// For the panel on the right side of the slot screen
static void CreateDigitalDisplayScene(u8 id)
{
    u8 i;
    struct Task *task;

    sub_8104DA4();

    task = &gTasks[sSlotMachine->unkTaskPointer3D];
    task->data[1] = id;

    for (i = 0; sDigitalDisplayScenes[id][i].spriteTemplateId != 255; i++)
    {
        u8 spriteId;
        spriteId = CreateStdDigitalDisplaySprite(
                sDigitalDisplayScenes[id][i].spriteTemplateId,
                sDigitalDisplayScenes[id][i].unk01,
                sDigitalDisplayScenes[id][i].unk02
        );
        task->data[4 + i] = spriteId;
    }
}

static void sub_8104D30(u8 templateIdx, SpriteCallback a1, s16 a2, s16 a3, s16 a4)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->unkTaskPointer3D];
    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] == MAX_SPRITES)
        {
            task->data[i] = CreateDigitalDisplaySprite(templateIdx, a1, a2, a3, a4);
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
    for (i = 4; i < NUM_TASK_DATA; i++)
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
    for (i = 4; i < NUM_TASK_DATA; i++)
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
    sprite->pos1.y = sSlotMachine->reelPixelOffsetsWhileStopping[sprite->data[0]] + 28 + sprite->data[2];
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
    struct Sprite *sprite = gSprites + CreateSprite(&sSpriteTemplate_CoinNumber, x, y, 13);
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
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelBackground, 0x58, 0x48, 15);
    gSprites[spriteId].oam.priority = 3;
    SetSubspriteTables(gSprites + spriteId, sSubspriteTable_ReelBackground);
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
    DestroySprite(gSprites + sSlotMachine->reelTimePikachuSpriteId);
    if (sImageTable_ReelTimePikachu != NULL)
        FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
}

static void SpriteCB_ReelTimePikachu(struct Sprite *sprite)
{
    sprite->pos2.y = sprite->pos2.x = 0;
    if (sprite->animNum == 4)
    {
        sprite->pos2.y = sprite->pos2.x = 8;
        if ((sprite->animCmdIndex != 0 && sprite->animDelayCounter != 0) || (sprite->animCmdIndex == 0 && sprite->animDelayCounter == 0))
            sprite->pos2.y = -8;
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
    spriteId = CreateSprite(&spriteTemplate, 0xa8 - gSpriteCoordOffsetX, 0x50, 7);
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
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeNumbers, 0x170, 0, 10);
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
    sprite->pos1.y = r0 + 59;
    StartSpriteAnimIfDifferent(sprite, GetNearbyReelTimeTag(r0 / 20));
}

static void CreateReelTimeShadowSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 0x170, 0x64, 9);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[0] = spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 0x120, 0x68, 4);
    sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[1] = spriteId;
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

static void DestroyReelTimeMachineSprites(void)
{
    u8 i;

    DestroySprite(&gSprites[sSlotMachine->unk40]);
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

static void CreateReelTimeBoltSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 0x98, 0x20, 5);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->hFlip = TRUE;
    sSlotMachine->reelTimeBoltSpriteIds[0] = spriteId;
    sprite->data[0] = 8;
    sprite->data[1] = -1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 0xb8, 0x20, 5);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sSlotMachine->reelTimeBoltSpriteIds[1] = spriteId;
    sprite->data[1] = 1;
    sprite->data[2] = -1;
    sprite->data[7] = 0x20;
}

static void SpriteCB_ReelTimeBolt(struct Sprite *sprite)
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
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[0]].data[7] = a0;
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[1]].data[7] = a0;
}

static void DestroyReelTimeBoltSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeBoltSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeBoltSpriteIds[i]]);
}

static void CreateReelTimePikachuAuraSprites(void)
{
    // Left half of electricity orb
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 0x48, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].data[0] = 1;
    gSprites[spriteId].data[5] = 0;
    gSprites[spriteId].data[6] = 16;
    gSprites[spriteId].data[7] = 8;
    sSlotMachine->reelTimePikachuAuraSpriteIds[0] = spriteId;

    // Right half
    spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 0x68, 0x50, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].hFlip = TRUE;
    sSlotMachine->reelTimePikachuAuraSpriteIds[1] = spriteId;
}

static void SpriteCB_ReelTimePikachuAura(struct Sprite *sprite)
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
    gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[0]].data[7] = a0;
}

static void DestroyReelTimePikachuAuraSprites(void)
{
    u8 i;
    MultiplyInvertedPaletteRGBComponents((IndexOfSpritePaletteTag(7) << 4) + 0x103, 0, 0, 0);
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimePikachuAuraSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[i]]);
}

static void CreateReelTimeExplosionSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeExplosion, 0xa8, 0x50, 6);
    gSprites[spriteId].oam.priority = 1;
    sSlotMachine->reelTimeExplosionSpriteId = spriteId;
}

static void SpriteCB_ReelTimeExplosion(struct Sprite *sprite)
{
    sprite->pos2.y = gSpriteCoordOffsetY;
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
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeDuck, 0x50 - gSpriteCoordOffsetX, 0x44, 0);
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

static void DestroyReelTimeDuckSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeDuckSpriteIds); i++)
    {
        DestroySprite(&gSprites[sSlotMachine->reelTimeDuckSpriteIds[i]]);
    }
}

static void CreateReelTimeSmokeSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeSmoke, 0xa8, 0x3c, 8);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sSlotMachine->reelTimeSmokeSpriteId = spriteId;
}

static void SpriteCB_ReelTimeSmoke(struct Sprite *sprite)
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
    return gSprites[sSlotMachine->reelTimeSmokeSpriteId].data[7];
}

static void DestroyReelTimeSmokeSprite(void)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->reelTimeSmokeSpriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

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
        sprite->data[7] = 1;
}

static void sub_8105B88(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

static u8 CreateStdDigitalDisplaySprite(u8 templateIdx, u8 cbAndCoordsIdx, s16 a2)
{
    return CreateDigitalDisplaySprite(templateIdx, gUnknown_083ECF0C[cbAndCoordsIdx], gUnknown_083ECE7E[cbAndCoordsIdx][0], gUnknown_083ECE7E[cbAndCoordsIdx][1], a2);
}

static u8 CreateDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 a4)
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
    sprite->data[6] = a4;
    sprite->data[7] = 1;
    if (sSubspriteTables_DigitalDisplay[templateIdx])
        SetSubspriteTables(sprite, sSubspriteTables_DigitalDisplay[templateIdx]);
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
        StartSpriteAnim(sprite, sSlotMachine->reelTimeSpinsLeft - 1);
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
            sub_8104D30(DIG_SPRITE_A_BUTTON, SpriteCallbackDummy, 0xd0, 0x74, 0);
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
    sDigitalDisplayGfxPtr = Alloc(0x3200);
    LZDecompressWram(gSlotMachineDigitalDisplay_Gfx, sDigitalDisplayGfxPtr);
    sReelTimeGfxPtr = Alloc(0x3600);
    LZDecompressWram(sReelTimeGfx, sReelTimeGfxPtr);
    sUnknown_0203AB30 = AllocZeroed(sizeof(struct SpriteSheet) * ARRAY_COUNT(gSlotMachineSpriteSheets));
    for (i = 0; i < ARRAY_COUNT(gSlotMachineSpriteSheets); i++)
    {
        sUnknown_0203AB30[i].data = gSlotMachineSpriteSheets[i].data;
        sUnknown_0203AB30[i].size = gSlotMachineSpriteSheets[i].size;
        sUnknown_0203AB30[i].tag = gSlotMachineSpriteSheets[i].tag;
    }
    sUnknown_0203AB30[17].data = sDigitalDisplayGfxPtr + 0xA00; // STOP
    sUnknown_0203AB30[18].data = sDigitalDisplayGfxPtr + 0x1400; // BONUS
    sUnknown_0203AB30[19].data = sDigitalDisplayGfxPtr + 0x1600; // BIG
    sUnknown_0203AB30[20].data = sDigitalDisplayGfxPtr + 0x1900; // REG
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

static void SlotMachineSetup_SetDigDisplayImagePtrs(void)
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

static void SlotMachineSetup_AllocDigDisplayGfx(void)
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

static const u8 sReelSymbols[NUM_REELS][REEL_NUM_TAGS] =
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

static const u8 gReelTimeTags[] = {
    1, 0, 5, 4, 3, 2
};

static const s16 gInitialReelPositions[NUM_REELS][2] = {
    {0,  6},
    {0, 10},
    {0,  2}
};

static const u8 gLuckyRoundProbabilities[][3] = {
    {1, 1, 12},
    {1, 1, 14},
    {2, 2, 14},
    {2, 2, 14},
    {2, 3, 16},
    {3, 3, 16}
};

static const u8 gLuckyFlagProbabilities_Top3[][6] = {
    {25, 25, 30, 40, 40, 50},
    {25, 25, 30, 30, 35, 35},
    {25, 25, 30, 25, 25, 30}
};

static const u8 gLuckyFlagProbabilities_NotTop3[][6] = {
    {20, 25, 25, 20, 25, 25},
    {12, 15, 15, 18, 19, 22},
    {25, 25, 25, 30, 30, 40},
    {25, 25, 20, 20, 15, 15},
    {40, 40, 35, 35, 40, 40}
};

static const u8 gReeltimeProbabilities_UnluckyGame[][17] = {
    {243, 243, 243,  80,  80,  80,  80,  40,  40,  40,  40,  40,  40,   5,   5,   5,   5},
    {  5,   5,   5, 150, 150, 150, 150, 130, 130, 130, 130, 130, 130, 100, 100, 100,   5},
    {  4,   4,   4,  20,  20,  20,  20,  80,  80,  80,  80,  80,  80, 100, 100, 100,  40},
    {  2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,  45,  45,  45, 100},
    {  1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   5,   5,   5, 100},
    {  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   6}
};

static const u8 gReelTimeProbabilities_LuckyGame[][17] = {
    { 243, 243, 243, 200, 200, 200, 200, 160, 160, 160, 160, 160, 160,  70,  70,  70,   5},
    {   5,   5,   5,  25,  25,  25,  25,   5,   5,   5,   5,   5,   5,   2,   2,   2,   6},
    {   4,   4,   4,  25,  25,  25,  25,  30,  30,  30,  30,  30,  30,  40,  40,  40,  35},
    {   2,   2,   2,   3,   3,   3,   3,  30,  30,  30,  30,  30,  30, 100, 100, 100,  50},
    {   1,   1,   1,   2,   2,   2,   2,  30,  30,  30,  30,  30,  30,  40,  40,  40, 100},
    {   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   4,  60}
};

static const u16 gProbabilityTable_SkipToReeltimeAction14[] = {
    128, 175, 200, 225, 256
};

static const u16 gReelIncrementTable[][2] = {
    {10,  5},
    {10, 10},
    {10, 15},
    {10, 25},
    {10, 35}
};

static const u16 gReelTimeBonusIncrementTable[] = {
    0, 5, 10, 15, 20
};

// tentative name
static const u8 gBiasTags[] = {
  SLOT_MACHINE_TAG_REPLAY, SLOT_MACHINE_TAG_CHERRY, SLOT_MACHINE_TAG_LOTAD, SLOT_MACHINE_TAG_AZURILL, SLOT_MACHINE_TAG_POWER, SLOT_MACHINE_TAG_7_RED, SLOT_MACHINE_TAG_7_RED, SLOT_MACHINE_TAG_7_RED
};

static const u16 gLuckyFlagSettings_Top3[] = {
    LUCKY_BIAS_777, LUCKY_BIAS_REELTIME, LUCKY_BIAS_MIXED_777
};

static const u16 gLuckyFlagSettings_NotTop3[] = {
    LUCKY_BIAS_POWER, LUCKY_BIAS_AZURILL, LUCKY_BIAS_LOTAD, LUCKY_BIAS_CHERRY, LUCKY_BIAS_REPLAY
};

static const u8 gSym2Match[] = {
    SLOT_MACHINE_MATCHED_777_RED,
    SLOT_MACHINE_MATCHED_777_BLUE,
    SLOT_MACHINE_MATCHED_AZURILL,
    SLOT_MACHINE_MATCHED_LOTAD,
    SLOT_MACHINE_MATCHED_1CHERRY,
    SLOT_MACHINE_MATCHED_POWER,
    SLOT_MACHINE_MATCHED_REPLAY
};

static const u16 gSlotMatchFlags[] = {
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

static const u16 gSlotPayouts[] = {
    2, 4, 0, 6, 12, 3, 90, 300, 300
};

static const s16 gUnknown_083ECE7E[][2] = {
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

static const SpriteCallback gUnknown_083ECF0C[] = {
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

static const struct DigitalDisplaySprite sDigitalDisplay_InsertBet[] = {
    {DIG_SPRITE_EMPTY, 34, 0}, // Replaced with DIG_SPRITE_A_BUTTON after first bet
    {DIG_SPRITE_INSERT, 0, 0},
    {DIG_SPRITE_D_PAD, 16, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_StopReel[] = {
    {DIG_SPRITE_STOP_S, 1, 0},
    {DIG_SPRITE_STOP_T, 2, 0},
    {DIG_SPRITE_STOP_O, 3, 0},
    {DIG_SPRITE_STOP_P, 4, 0},
    {DIG_SPRITE_A_BUTTON, 5, 0},
    {DIG_SPRITE_POKE_BALL, 6, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_Win[] = {
    {DIG_SPRITE_WIN, 7, 0},
    {DIG_SPRITE_POKE_BALL, 17, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_Lose[] = {
    {DIG_SPRITE_LOSE, 8, 0},
    {DIG_SPRITE_SMOKE, 9, 0},
    {DIG_SPRITE_SMOKE, 10, 1},
    {DIG_SPRITE_SMOKE, 11, 2},
    {DIG_SPRITE_SMOKE, 12, 3},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_ReelTime[] = {
    {DIG_SPRITE_REEL, 13, 0},
    {DIG_SPRITE_TIME, 14, 0},
    {DIG_SPRITE_NUMBER, 15, 0}, // Number of reel time spins left
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_BonusBig[] = {
    {DIG_SPRITE_BIG_B, 26, 0},
    {DIG_SPRITE_BIG_I, 27, 1},
    {DIG_SPRITE_BIG_G, 28, 2},
    {DIG_SPRITE_BONUS_B, 29, 3},
    {DIG_SPRITE_BONUS_O, 30, 4},
    {DIG_SPRITE_BONUS_N, 31, 5},
    {DIG_SPRITE_BONUS_U, 32, 6},
    {DIG_SPRITE_BONUS_S, 33, 7},
    {DIG_SPRITE_POKE_BALL, 17, 0},
    DIG_SPRITE_DUMMY
};

static const struct DigitalDisplaySprite sDigitalDisplay_BonusRegular[] = {
    {DIG_SPRITE_REG_R, 18, 0},
    {DIG_SPRITE_REG_E, 19, 1},
    {DIG_SPRITE_REG_G, 20, 2},
    {DIG_SPRITE_BONUS_B, 21, 3},
    {DIG_SPRITE_BONUS_O, 22, 4},
    {DIG_SPRITE_BONUS_N, 23, 5},
    {DIG_SPRITE_BONUS_U, 24, 6},
    {DIG_SPRITE_BONUS_S, 25, 7},
    {DIG_SPRITE_POKE_BALL, 17, 0},
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

static void (*const gUnknown_083ED064[])(void) = {
    sub_810639C,
    sub_8106364,
    sub_8106370,
    nullsub_70,
    nullsub_70,
    sub_8106370,
    sub_8106370
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
static const struct SpriteFrameImage gUnknown_085A7AB4[] = { gUnknown_08DD1A18, 0x40 };

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

static const union AnimCmd gUnknown_085A7AFC[] = 
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_085A7B04[] = 
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

static const union AnimCmd *const gUnknown_085A7BF8[] =
{
    gUnknown_085A7AFC
};

static const union AnimCmd *const gUnknown_085A7BFC[] =
{
    gUnknown_085A7B04
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
    .tileTag = 0, 
    .paletteTag = 0, 
    .oam = &sOam_32x32, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelSymbol
};

static const struct SpriteTemplate sSpriteTemplate_CoinNumber =
{
    .tileTag = 7, 
    .paletteTag = 4, 
    .oam = &sOam_8x16, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_CoinNumber
};

static const struct SpriteTemplate sSpriteTemplate_ReelBackground =
{
    .tileTag = 17, 
    .paletteTag = 0, 
    .oam = &sOam_64x64, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachu =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 1, 
    .oam = &sOam_64x64, 
    .anims = sAnims_ReelTimePikachu, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimePikachu
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 2, 
    .oam = &sOam_8x16, 
    .anims = gUnknown_085A7BF8,
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 3, 
    .oam = &sOam_8x16, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 3, 
    .oam = &sOam_8x16, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_16x16, 
    .anims = sAnims_ReelTimeNumbers, 
    .images = sImageTable_ReelTimeNumbers, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimeNumbers
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_16x16, 
    .anims = gUnknown_085A7BF8, 
    .images = sImageTable_ReelTimeShadow, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gSpriteTemplate_83ED4EC =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_16x16, 
    .anims = gUnknown_085A7BF8, 
    .images = gUnknown_085A7AB4, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_16x32, 
    .anims = sAnims_ReelTimeBolt, 
    .images = sImageTable_ReelTimeBolt, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimeBolt
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 7, 
    .oam = &sOam_32x64, 
    .anims = gUnknown_085A7BF8, 
    .images = sImageTable_ReelTimePikachuAura, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimePikachuAura
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 5, 
    .oam = &sOam_32x32, 
    .anims = sAnims_ReelTimeExplosion, 
    .images = sImageTable_ReelTimeExplosion, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimeExplosion
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BFC, 
    .images = sImageTable_ReelTimeDuck, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_ReelTimeDuck
};

static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_16x16, 
    .anims = gUnknown_085A7BF8, 
    .images = sImageTable_ReelTimeSmoke, 
    .affineAnims = sAffineAnims_ReelTimeSmoke, 
    .callback = SpriteCB_ReelTimeSmoke
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reel =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Time =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Insert =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Stop =
{
    .tileTag = 18, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Win =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_64x32, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Lose =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_64x32, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Bonus =
{
    .tileTag = 19, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Big =
{
    .tileTag = 20, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Reg =
{
    .tileTag = 21, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_AButton =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_32x32, 
    .anims = sAnims_DigitalDisplay_AButton, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Smoke =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Number =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_16x16, 
    .anims = sAnims_DigitalDisplay_Number, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_Pokeball =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = sAnims_DigitalDisplay_Pokeball, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_DigitalDisplay_DPad =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 6, 
    .oam = &sOam_8x8, 
    .anims = sAnims_DigitalDisplay_DPad, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt =
{
    .tileTag = 0xFFFF, 
    .paletteTag = 4, 
    .oam = &sOam_8x8, 
    .anims = gUnknown_085A7BF8, 
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

static const struct Subsprite gUnknown_085A8030[] =
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

static const struct SubspriteTable gSubspriteTables_83ED7D4[] =
{
    ARRAY_COUNT(gUnknown_085A8030), gUnknown_085A8030
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

static const struct SpriteSheet gSlotMachineSpriteSheets[22] =
{
    { .data = gSlotMachineReelSymbol1Tiles, .size = 0x200, .tag = 0 },
    { .data = gSlotMachineReelSymbol2Tiles, .size = 0x200, .tag = 1 },
    { .data = gSlotMachineReelSymbol3Tiles, .size = 0x200, .tag = 2 },
    { .data = gSlotMachineReelSymbol4Tiles, .size = 0x200, .tag = 3 },
    { .data = gSlotMachineReelSymbol5Tiles, .size = 0x200, .tag = 4 },
    { .data = gSlotMachineReelSymbol6Tiles, .size = 0x200, .tag = 5 },
    { .data = gSlotMachineReelSymbol7Tiles, .size = 0x200, .tag = 6 },
    { .data = gSlotMachineNumber0Tiles, .size = 0x40, .tag = 7 },
    { .data = gSlotMachineNumber1Tiles, .size = 0x40, .tag = 8 },
    { .data = gSlotMachineNumber2Tiles, .size = 0x40, .tag = 9 },
    { .data = gSlotMachineNumber3Tiles, .size = 0x40, .tag = 10 },
    { .data = gSlotMachineNumber4Tiles, .size = 0x40, .tag = 11 },
    { .data = gSlotMachineNumber5Tiles, .size = 0x40, .tag = 12 },
    { .data = gSlotMachineNumber6Tiles, .size = 0x40, .tag = 13 },
    { .data = gSlotMachineNumber7Tiles, .size = 0x40, .tag = 14 },
    { .data = gSlotMachineNumber8Tiles, .size = 0x40, .tag = 15 },
    { .data = gSlotMachineNumber9Tiles, .size = 0x40, .tag = 16 },
    // the data for these sheets is determined at runtime
    { .data = NULL, .size = 0x200, .tag = 18 },
    { .data = NULL, .size = 0x200, .tag = 19 },
    { .data = NULL, .size = 0x300, .tag = 20 },
    { .data = NULL, .size = 0x300, .tag = 21 },
    {},
};

static const u8 *const gUnknown_083EDCDC = gUnknown_08DD19F8;

static const u8 sUnused2[][2] = 
{
    {0x7B, 0x6F}, 
    {0x68, 0x69}, 
    {0xAB, 0x36}, 
    {0xFF, 0x7F}, 
    {0x50, 0x57}, 
    {0xC0, 0x7E}, 
    {0xBA, 2}, 
    {0xBA, 2}, 
    {0xFD, 1}, 
    {0xFD, 1}
};

static const u8 gUnknown_085A83FC[] = {0x91, 0x7F};
static const u8 gUnknown_085A83FE[] = {0xBF, 0x43};
static const u8 gUnknown_085A8400[] = {0xBF, 0x43};
static const u8 gUnknown_085A8402[] = {0xBF, 0x4A};
static const u8 gUnknown_085A8404[] = {0xBF, 0x4A};

static const u8 *const gUnknown_083EDD08[] =
{
    gUnknown_085A83FC,
    gUnknown_085A83FE,
    gUnknown_085A8400,
    gUnknown_085A8402,
    gUnknown_085A8404,
};

static const u16 *const gUnknown_083EDD1C[] =
{
    gSlotMachineMenu_Pal + 0x4A,
    gSlotMachineMenu_Pal + 0x4B,
    gSlotMachineMenu_Pal + 0x4C,
    gSlotMachineMenu_Pal + 0x4D,
    gSlotMachineMenu_Pal + 0x4E,
};

static const u8 gUnknown_083EDD30[] = {0x4A, 0x4B, 0x4C, 0x4E, 0x4D};

static const u8 gBettingTilesId[][2] =
{
    {0, 0},
    {1, 2},
    {3, 4},
};

static const u8 gNumberBettingTiles[] = { 1, 2, 2 };

static const u16 gUnknown_085A843E[] = INCBIN_U16("graphics/slot_machine/85A843E.gbapal");
static const u16 gUnknown_085A845E[] = INCBIN_U16("graphics/slot_machine/85A845E.gbapal");
static const u16 gUnknown_085A847E[] = INCBIN_U16("graphics/slot_machine/85A847E.gbapal");

static const u16 *const gUnknown_083EDDA0[] =
{
    gUnknown_085A843E,
    gUnknown_085A845E,
    gUnknown_085A847E,
};

static const u16 *const gUnknown_083EDDAC = {gSlotMachineMenu_Pal + 0x10};

static const u16 gUnknown_085A84B0[] = INCBIN_U16("graphics/slot_machine/85A84B0.gbapal");
static const u16 gUnknown_085A84D0[] = INCBIN_U16("graphics/slot_machine/85A84D0.gbapal");
static const u16 gUnknown_085A84F0[] = INCBIN_U16("graphics/slot_machine/85A84F0.gbapal");

static const u16 *const gUnknown_083EDE10[] =
{
    gUnknown_085A84B0,
    gUnknown_085A84D0,
    gUnknown_085A84F0,
    gUnknown_08DCF230,
};

static const u16 *const gUnknown_083EDE20 = gUnknown_08DCF230;
static const u16 gPalette_83EDE24[] = INCBIN_U16("graphics/slot_machine/85A8524.bin");

static const struct SpritePalette gSlotMachineSpritePalettes[] =
{
    { .data = gUnknown_08DCF170, .tag = 0},
    { .data = gUnknown_08DCF190, .tag = 1},
    { .data = gUnknown_08DCF1B0, .tag = 2},
    { .data = gSlotMachineDigitalDisplay_Pal, .tag = 3},
    { .data = gUnknown_08DCF1F0, .tag = 4},
    { .data = gUnknown_08DCF210, .tag = 5},
    { .data = gUnknown_08DCF230, .tag = 6},
    { .data = gUnknown_08DCF1F0, .tag = 7},
    {}
};

static const u32 sReelTimeGfx[] = INCBIN_U32("graphics/slot_machine/reel_time_gfx.4bpp.lz"); // reel_time_machine and reel_time_pikachu
static const u16 gReelTimeWindowTilemap[] = INCBIN_U16("graphics/slot_machine/85A96E0.bin");
static const u16 gUnknown_085A9898[] =  {0};
