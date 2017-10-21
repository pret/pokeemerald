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
void WallyHandleGetMonData(void);
void WallyHandleGetRawMonData(void);
void WallyHandleSetMonData(void);
void WallyHandleSetRawMonData(void);
void WallyHandleLoadMonSprite(void);
void WallyHandleSwitchInAnim(void);
void WallyHandleReturnMonToBall(void);
void WallyHandleDrawTrainerPic(void);
void WallyHandleTrainerSlide(void);
void WallyHandleTrainerSlideBack(void);
void WallyHandleFaintAnimation(void);
void WallyHandleCmd11(void);
void WallyHandleCmd12(void);
void WallyHandleBallThrow(void);
void WallyHandlePause(void);
void WallyHandleMoveAnimation(void);
void WallyHandlePrintString(void);
void WallyHandlePrintStringPlayerOnly(void);
void WallyHandleChooseAction(void);
void WallyHandleCmd19(void);
void WallyHandleChooseMove(void);
void WallyHandleOpenBag(void);
void WallyHandleChoosePokemon(void);
void WallyHandleCmd23(void);
void WallyHandleHealthBarUpdate(void);
void WallyHandleExpUpdate(void);
void WallyHandleStatusIconUpdate(void);
void WallyHandleStatusAnimation(void);
void WallyHandleStatusXor(void);
void WallyHandleDataTransfer(void);
void WallyHandleDMA3Transfer(void);
void WallyHandlePlayBGM(void);
void WallyHandleCmd32(void);
void WallyHandleCmd33(void);
void WallyHandleCmd34(void);
void WallyHandleCmd35(void);
void WallyHandleCmd36(void);
void WallyHandleCmd37(void);
void WallyHandleCmd38(void);
void WallyHandleCmd39(void);
void WallyHandleCmd40(void);
void WallyHandleHitAnimation(void);
void WallyHandleCmd42(void);
void WallyHandleEffectivenessSound(void);
void WallyHandlePlayFanfareOrBGM(void);
void WallyHandleFaintingCry(void);
void WallyHandleIntroSlide(void);
void WallyHandleIntroTrainerBallThrow(void);
void WallyHandleDrawPartyStatusSummary(void);
void WallyHandleCmd49(void);
void WallyHandleCmd50(void);
void WallyHandleSpriteInvisibility(void);
void WallyHandleBattleAnimation(void);
void WallyHandleLinkStandbyMsg(void);
void WallyHandleResetActionMoveSelection(void);
void WallyHandleCmd55(void);
void nullsub_118(void);

void WallyBufferRunCommand(void);

void (*const gWallyBufferCommands[CONTOLLER_CMDS_CONT])(void) =
{
    WallyHandleGetMonData,
    WallyHandleGetRawMonData,
    WallyHandleSetMonData,
    WallyHandleSetRawMonData,
    WallyHandleLoadMonSprite,
    WallyHandleSwitchInAnim,
    WallyHandleReturnMonToBall,
    WallyHandleDrawTrainerPic,
    WallyHandleTrainerSlide,
    WallyHandleTrainerSlideBack,
    WallyHandleFaintAnimation,
    WallyHandleCmd11,
    WallyHandleCmd12,
    WallyHandleBallThrow,
    WallyHandlePause,
    WallyHandleMoveAnimation,
    WallyHandlePrintString,
    WallyHandlePrintStringPlayerOnly,
    WallyHandleChooseAction,
    WallyHandleCmd19,
    WallyHandleChooseMove,
    WallyHandleOpenBag,
    WallyHandleChoosePokemon,
    WallyHandleCmd23,
    WallyHandleHealthBarUpdate,
    WallyHandleExpUpdate,
    WallyHandleStatusIconUpdate,
    WallyHandleStatusAnimation,
    WallyHandleStatusXor,
    WallyHandleDataTransfer,
    WallyHandleDMA3Transfer,
    WallyHandlePlayBGM,
    WallyHandleCmd32,
    WallyHandleCmd33,
    WallyHandleCmd34,
    WallyHandleCmd35,
    WallyHandleCmd36,
    WallyHandleCmd37,
    WallyHandleCmd38,
    WallyHandleCmd39,
    WallyHandleCmd40,
    WallyHandleHitAnimation,
    WallyHandleCmd42,
    WallyHandleEffectivenessSound,
    WallyHandlePlayFanfareOrBGM,
    WallyHandleFaintingCry,
    WallyHandleIntroSlide,
    WallyHandleIntroTrainerBallThrow,
    WallyHandleDrawPartyStatusSummary,
    WallyHandleCmd49,
    WallyHandleCmd50,
    WallyHandleSpriteInvisibility,
    WallyHandleBattleAnimation,
    WallyHandleLinkStandbyMsg,
    WallyHandleResetActionMoveSelection,
    WallyHandleCmd55,
    nullsub_118
};

void nullsub_117(void)
{
}

void SetBankFuncToWallyBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = WallyBufferRunCommand;
    gBattleStruct->field_94 = 0;
    gBattleStruct->field_95 = 0;
    gBattleStruct->field_96 = 0;
    gBattleStruct->field_97 = 0;
}
