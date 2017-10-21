#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "link.h"

extern u8 gActiveBank;
extern bool8 gDoingBattleAnim;
extern u8 gUnknown_020244CC;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);

// this file's functions
void OpponentHandleGetMonData(void);
void OpponentHandleGetRawMonData(void);
void OpponentHandleSetMonData(void);
void OpponentHandleSetRawMonData(void);
void OpponentHandleLoadMonSprite(void);
void OpponentHandleSwitchInAnim(void);
void OpponentHandleReturnMonToBall(void);
void OpponentHandleDrawTrainerPic(void);
void OpponentHandleTrainerSlide(void);
void OpponentHandleTrainerSlideBack(void);
void OpponentHandleFaintAnimation(void);
void OpponentHandleCmd11(void);
void OpponentHandleCmd12(void);
void OpponentHandleBallThrow(void);
void OpponentHandlePause(void);
void OpponentHandleMoveAnimation(void);
void OpponentHandlePrintString(void);
void OpponentHandlePrintStringPlayerOnly(void);
void OpponentHandleChooseAction(void);
void OpponentHandleCmd19(void);
void OpponentHandleChooseMove(void);
void OpponentHandleOpenBag(void);
void OpponentHandleChoosePokemon(void);
void OpponentHandleCmd23(void);
void OpponentHandleHealthBarUpdate(void);
void OpponentHandleExpUpdate(void);
void OpponentHandleStatusIconUpdate(void);
void OpponentHandleStatusAnimation(void);
void OpponentHandleStatusXor(void);
void OpponentHandleDataTransfer(void);
void OpponentHandleDMA3Transfer(void);
void OpponentHandlePlayBGM(void);
void OpponentHandleCmd32(void);
void OpponentHandleCmd33(void);
void OpponentHandleCmd34(void);
void OpponentHandleCmd35(void);
void OpponentHandleCmd36(void);
void OpponentHandleCmd37(void);
void OpponentHandleCmd38(void);
void OpponentHandleCmd39(void);
void OpponentHandleCmd40(void);
void OpponentHandleHitAnimation(void);
void OpponentHandleCmd42(void);
void OpponentHandleEffectivenessSound(void);
void OpponentHandlePlayFanfareOrBGM(void);
void OpponentHandleFaintingCry(void);
void OpponentHandleIntroSlide(void);
void OpponentHandleIntroTrainerBallThrow(void);
void OpponentHandleDrawPartyStatusSummary(void);
void OpponentHandleCmd49(void);
void OpponentHandleCmd50(void);
void OpponentHandleSpriteInvisibility(void);
void OpponentHandleBattleAnimation(void);
void OpponentHandleLinkStandbyMsg(void);
void OpponentHandleResetActionMoveSelection(void);
void OpponentHandleCmd55(void);
void nullsub_91(void);

void OpponentBufferRunCommand(void);

void (*const gOpponentBufferCommands[CONTOLLER_CMDS_CONT])(void) =
{
    OpponentHandleGetMonData,
    OpponentHandleGetRawMonData,
    OpponentHandleSetMonData,
    OpponentHandleSetRawMonData,
    OpponentHandleLoadMonSprite,
    OpponentHandleSwitchInAnim,
    OpponentHandleReturnMonToBall,
    OpponentHandleDrawTrainerPic,
    OpponentHandleTrainerSlide,
    OpponentHandleTrainerSlideBack,
    OpponentHandleFaintAnimation,
    OpponentHandleCmd11,
    OpponentHandleCmd12,
    OpponentHandleBallThrow,
    OpponentHandlePause,
    OpponentHandleMoveAnimation,
    OpponentHandlePrintString,
    OpponentHandlePrintStringPlayerOnly,
    OpponentHandleChooseAction,
    OpponentHandleCmd19,
    OpponentHandleChooseMove,
    OpponentHandleOpenBag,
    OpponentHandleChoosePokemon,
    OpponentHandleCmd23,
    OpponentHandleHealthBarUpdate,
    OpponentHandleExpUpdate,
    OpponentHandleStatusIconUpdate,
    OpponentHandleStatusAnimation,
    OpponentHandleStatusXor,
    OpponentHandleDataTransfer,
    OpponentHandleDMA3Transfer,
    OpponentHandlePlayBGM,
    OpponentHandleCmd32,
    OpponentHandleCmd33,
    OpponentHandleCmd34,
    OpponentHandleCmd35,
    OpponentHandleCmd36,
    OpponentHandleCmd37,
    OpponentHandleCmd38,
    OpponentHandleCmd39,
    OpponentHandleCmd40,
    OpponentHandleHitAnimation,
    OpponentHandleCmd42,
    OpponentHandleEffectivenessSound,
    OpponentHandlePlayFanfareOrBGM,
    OpponentHandleFaintingCry,
    OpponentHandleIntroSlide,
    OpponentHandleIntroTrainerBallThrow,
    OpponentHandleDrawPartyStatusSummary,
    OpponentHandleCmd49,
    OpponentHandleCmd50,
    OpponentHandleSpriteInvisibility,
    OpponentHandleBattleAnimation,
    OpponentHandleLinkStandbyMsg,
    OpponentHandleResetActionMoveSelection,
    OpponentHandleCmd55,
    nullsub_91
};

// unknown unused data
static const u8 gUnknown_0831C7AC[] = {0xB0, 0xB0, 0xC8, 0x98, 0x28, 0x28, 0x28, 0x20};

void nullsub_26(void)
{
}

void SetBankFuncToOpponentBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = OpponentBufferRunCommand;
}
