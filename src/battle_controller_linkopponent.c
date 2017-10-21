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
void LinkOpponentHandleGetMonData(void);
void LinkOpponentHandleGetRawMonData(void);
void LinkOpponentHandleSetMonData(void);
void LinkOpponentHandleSetRawMonData(void);
void LinkOpponentHandleLoadMonSprite(void);
void LinkOpponentHandleSwitchInAnim(void);
void LinkOpponentHandleReturnMonToBall(void);
void LinkOpponentHandleDrawTrainerPic(void);
void LinkOpponentHandleTrainerSlide(void);
void LinkOpponentHandleTrainerSlideBack(void);
void LinkOpponentHandleFaintAnimation(void);
void LinkOpponentHandleCmd11(void);
void LinkOpponentHandleCmd12(void);
void LinkOpponentHandleBallThrow(void);
void LinkOpponentHandlePause(void);
void LinkOpponentHandleMoveAnimation(void);
void LinkOpponentHandlePrintString(void);
void LinkOpponentHandlePrintStringPlayerOnly(void);
void LinkOpponentHandleChooseAction(void);
void LinkOpponentHandleCmd19(void);
void LinkOpponentHandleChooseMove(void);
void LinkOpponentHandleOpenBag(void);
void LinkOpponentHandleChoosePokemon(void);
void LinkOpponentHandleCmd23(void);
void LinkOpponentHandleHealthBarUpdate(void);
void LinkOpponentHandleExpUpdate(void);
void LinkOpponentHandleStatusIconUpdate(void);
void LinkOpponentHandleStatusAnimation(void);
void LinkOpponentHandleStatusXor(void);
void LinkOpponentHandleDataTransfer(void);
void LinkOpponentHandleDMA3Transfer(void);
void LinkOpponentHandlePlayBGM(void);
void LinkOpponentHandleCmd32(void);
void LinkOpponentHandleCmd33(void);
void LinkOpponentHandleCmd34(void);
void LinkOpponentHandleCmd35(void);
void LinkOpponentHandleCmd36(void);
void LinkOpponentHandleCmd37(void);
void LinkOpponentHandleCmd38(void);
void LinkOpponentHandleCmd39(void);
void LinkOpponentHandleCmd40(void);
void LinkOpponentHandleHitAnimation(void);
void LinkOpponentHandleCmd42(void);
void LinkOpponentHandleEffectivenessSound(void);
void LinkOpponentHandlePlayFanfareOrBGM(void);
void LinkOpponentHandleFaintingCry(void);
void LinkOpponentHandleIntroSlide(void);
void LinkOpponentHandleIntroTrainerBallThrow(void);
void LinkOpponentHandleDrawPartyStatusSummary(void);
void LinkOpponentHandleCmd49(void);
void LinkOpponentHandleCmd50(void);
void LinkOpponentHandleSpriteInvisibility(void);
void LinkOpponentHandleBattleAnimation(void);
void LinkOpponentHandleLinkStandbyMsg(void);
void LinkOpponentHandleResetActionMoveSelection(void);
void LinkOpponentHandleCmd55(void);
void nullsub_92(void);

void LinkOpponentBufferRunCommand(void);

void (*const gLinkOpponentBufferCommands[CONTOLLER_CMDS_CONT])(void) =
{
    LinkOpponentHandleGetMonData,
    LinkOpponentHandleGetRawMonData,
    LinkOpponentHandleSetMonData,
    LinkOpponentHandleSetRawMonData,
    LinkOpponentHandleLoadMonSprite,
    LinkOpponentHandleSwitchInAnim,
    LinkOpponentHandleReturnMonToBall,
    LinkOpponentHandleDrawTrainerPic,
    LinkOpponentHandleTrainerSlide,
    LinkOpponentHandleTrainerSlideBack,
    LinkOpponentHandleFaintAnimation,
    LinkOpponentHandleCmd11,
    LinkOpponentHandleCmd12,
    LinkOpponentHandleBallThrow,
    LinkOpponentHandlePause,
    LinkOpponentHandleMoveAnimation,
    LinkOpponentHandlePrintString,
    LinkOpponentHandlePrintStringPlayerOnly,
    LinkOpponentHandleChooseAction,
    LinkOpponentHandleCmd19,
    LinkOpponentHandleChooseMove,
    LinkOpponentHandleOpenBag,
    LinkOpponentHandleChoosePokemon,
    LinkOpponentHandleCmd23,
    LinkOpponentHandleHealthBarUpdate,
    LinkOpponentHandleExpUpdate,
    LinkOpponentHandleStatusIconUpdate,
    LinkOpponentHandleStatusAnimation,
    LinkOpponentHandleStatusXor,
    LinkOpponentHandleDataTransfer,
    LinkOpponentHandleDMA3Transfer,
    LinkOpponentHandlePlayBGM,
    LinkOpponentHandleCmd32,
    LinkOpponentHandleCmd33,
    LinkOpponentHandleCmd34,
    LinkOpponentHandleCmd35,
    LinkOpponentHandleCmd36,
    LinkOpponentHandleCmd37,
    LinkOpponentHandleCmd38,
    LinkOpponentHandleCmd39,
    LinkOpponentHandleCmd40,
    LinkOpponentHandleHitAnimation,
    LinkOpponentHandleCmd42,
    LinkOpponentHandleEffectivenessSound,
    LinkOpponentHandlePlayFanfareOrBGM,
    LinkOpponentHandleFaintingCry,
    LinkOpponentHandleIntroSlide,
    LinkOpponentHandleIntroTrainerBallThrow,
    LinkOpponentHandleDrawPartyStatusSummary,
    LinkOpponentHandleCmd49,
    LinkOpponentHandleCmd50,
    LinkOpponentHandleSpriteInvisibility,
    LinkOpponentHandleBattleAnimation,
    LinkOpponentHandleLinkStandbyMsg,
    LinkOpponentHandleResetActionMoveSelection,
    LinkOpponentHandleCmd55,
    nullsub_92
};

void nullsub_28(void)
{
}

void SetBankFuncToLinkOpponentBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = LinkOpponentBufferRunCommand;
}
