#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "pokemon.h"
#include "link.h"
#include "util.h"
#include "main.h"
#include "songs.h"
#include "sound.h"
#include "window.h"
#include "m4a.h"
#include "palette.h"
#include "task.h"
#include "text.h"
#include "bg.h"
#include "reshow_battle_screen.h"
#include "pokeball.h"

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern bool8 gDoingBattleAnim;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern void (*gPreBattleCallback1)(void);
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern struct SpriteTemplate gUnknown_0202499C;
extern u16 gScriptItemId;
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern u8 gBattleOutcome;
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u8 gBankInMenu;
extern u16 gUnknown_020243FC;

extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];

extern void sub_81358F4(void);

// this file's functions
void PlayerPartnerHandleGetMonData(void);
void PlayerPartnerHandleGetRawMonData(void);
void PlayerPartnerHandleSetMonData(void);
void PlayerPartnerHandleSetRawMonData(void);
void PlayerPartnerHandleLoadMonSprite(void);
void PlayerPartnerHandleSwitchInAnim(void);
void PlayerPartnerHandleReturnMonToBall(void);
void PlayerPartnerHandleDrawTrainerPic(void);
void PlayerPartnerHandleTrainerSlide(void);
void PlayerPartnerHandleTrainerSlideBack(void);
void PlayerPartnerHandleFaintAnimation(void);
void PlayerPartnerHandlePaletteFade(void);
void PlayerPartnerHandleSuccessBallThrowAnim(void);
void PlayerPartnerHandleBallThrowAnim(void);
void PlayerPartnerHandlePause(void);
void PlayerPartnerHandleMoveAnimation(void);
void PlayerPartnerHandlePrintString(void);
void PlayerPartnerHandlePrintStringPlayerOnly(void);
void PlayerPartnerHandleChooseAction(void);
void PlayerPartnerHandleUnknownYesNoBox(void);
void PlayerPartnerHandleChooseMove(void);
void PlayerPartnerHandleChooseItem(void);
void PlayerPartnerHandleChoosePokemon(void);
void PlayerPartnerHandleCmd23(void);
void PlayerPartnerHandleHealthBarUpdate(void);
void PlayerPartnerHandleExpUpdate(void);
void PlayerPartnerHandleStatusIconUpdate(void);
void PlayerPartnerHandleStatusAnimation(void);
void PlayerPartnerHandleStatusXor(void);
void PlayerPartnerHandleDataTransfer(void);
void PlayerPartnerHandleDMA3Transfer(void);
void PlayerPartnerHandlePlayBGM(void);
void PlayerPartnerHandleCmd32(void);
void PlayerPartnerHandleTwoReturnValues(void);
void PlayerPartnerHandleChosenMonReturnValue(void);
void PlayerPartnerHandleOneReturnValue(void);
void PlayerPartnerHandleOneReturnValue_Duplicate(void);
void PlayerPartnerHandleCmd37(void);
void PlayerPartnerHandleCmd38(void);
void PlayerPartnerHandleCmd39(void);
void PlayerPartnerHandleCmd40(void);
void PlayerPartnerHandleHitAnimation(void);
void PlayerPartnerHandleCmd42(void);
void PlayerPartnerHandleEffectivenessSound(void);
void PlayerPartnerHandlePlayFanfareOrBGM(void);
void PlayerPartnerHandleFaintingCry(void);
void PlayerPartnerHandleIntroSlide(void);
void PlayerPartnerHandleIntroTrainerBallThrow(void);
void PlayerPartnerHandleDrawPartyStatusSummary(void);
void PlayerPartnerHandleCmd49(void);
void PlayerPartnerHandleCmd50(void);
void PlayerPartnerHandleSpriteInvisibility(void);
void PlayerPartnerHandleBattleAnimation(void);
void PlayerPartnerHandleLinkStandbyMsg(void);
void PlayerPartnerHandleResetActionMoveSelection(void);
void PlayerPartnerHandleCmd55(void);
void nullsub_128(void);

void PlayerPartnerBufferRunCommand(void);
void PlayerPartnerBufferExecCompleted(void);

void (*const gPlayerPartnerBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    PlayerPartnerHandleGetMonData,
    PlayerPartnerHandleGetRawMonData,
    PlayerPartnerHandleSetMonData,
    PlayerPartnerHandleSetRawMonData,
    PlayerPartnerHandleLoadMonSprite,
    PlayerPartnerHandleSwitchInAnim,
    PlayerPartnerHandleReturnMonToBall,
    PlayerPartnerHandleDrawTrainerPic,
    PlayerPartnerHandleTrainerSlide,
    PlayerPartnerHandleTrainerSlideBack,
    PlayerPartnerHandleFaintAnimation,
    PlayerPartnerHandlePaletteFade,
    PlayerPartnerHandleSuccessBallThrowAnim,
    PlayerPartnerHandleBallThrowAnim,
    PlayerPartnerHandlePause,
    PlayerPartnerHandleMoveAnimation,
    PlayerPartnerHandlePrintString,
    PlayerPartnerHandlePrintStringPlayerOnly,
    PlayerPartnerHandleChooseAction,
    PlayerPartnerHandleUnknownYesNoBox,
    PlayerPartnerHandleChooseMove,
    PlayerPartnerHandleChooseItem,
    PlayerPartnerHandleChoosePokemon,
    PlayerPartnerHandleCmd23,
    PlayerPartnerHandleHealthBarUpdate,
    PlayerPartnerHandleExpUpdate,
    PlayerPartnerHandleStatusIconUpdate,
    PlayerPartnerHandleStatusAnimation,
    PlayerPartnerHandleStatusXor,
    PlayerPartnerHandleDataTransfer,
    PlayerPartnerHandleDMA3Transfer,
    PlayerPartnerHandlePlayBGM,
    PlayerPartnerHandleCmd32,
    PlayerPartnerHandleTwoReturnValues,
    PlayerPartnerHandleChosenMonReturnValue,
    PlayerPartnerHandleOneReturnValue,
    PlayerPartnerHandleOneReturnValue_Duplicate,
    PlayerPartnerHandleCmd37,
    PlayerPartnerHandleCmd38,
    PlayerPartnerHandleCmd39,
    PlayerPartnerHandleCmd40,
    PlayerPartnerHandleHitAnimation,
    PlayerPartnerHandleCmd42,
    PlayerPartnerHandleEffectivenessSound,
    PlayerPartnerHandlePlayFanfareOrBGM,
    PlayerPartnerHandleFaintingCry,
    PlayerPartnerHandleIntroSlide,
    PlayerPartnerHandleIntroTrainerBallThrow,
    PlayerPartnerHandleDrawPartyStatusSummary,
    PlayerPartnerHandleCmd49,
    PlayerPartnerHandleCmd50,
    PlayerPartnerHandleSpriteInvisibility,
    PlayerPartnerHandleBattleAnimation,
    PlayerPartnerHandleLinkStandbyMsg,
    PlayerPartnerHandleResetActionMoveSelection,
    PlayerPartnerHandleCmd55,
    nullsub_128
};

// unknown unused data
static const u8 gUnknown_08617254[] =
{
    0x83, 0x4d, 0xf3, 0x5f, 0x6f, 0x4f, 0xeb, 0x3e,
    0x67, 0x2e, 0x10, 0x46, 0x8c, 0x3d, 0x28, 0x35,
    0xc5, 0x2c, 0x15, 0x7f, 0xb5, 0x56, 0x9d, 0x53,
    0x3b, 0x43, 0xda, 0x36, 0x79, 0x2a, 0x0e, 0x53,
};

void nullsub_77(void)
{
}

void SetBankFuncToPlayerPartnerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = PlayerPartnerBufferRunCommand;
}

void PlayerPartnerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gPlayerPartnerBufferCommands))
            gPlayerPartnerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            PlayerPartnerBufferExecCompleted();
    }
}

