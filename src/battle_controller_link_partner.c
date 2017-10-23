#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
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
#include "string_util.h"
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
extern u8 gUnknown_03005D7C[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u16 gPartnerTrainerId;
extern u8 GetFrontierTrainerFrontSpriteId(u16 trainerId);
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gUnknown_020244B4[];
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern struct UnusedControllerStruct gUnknown_02022D0C;

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const struct BattleMove gBattleMoves[];

extern void sub_81358F4(void);
extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);

// this file's functions
void LinkPartnerHandleGetMonData(void);
void LinkPartnerHandleGetRawMonData(void);
void LinkPartnerHandleSetMonData(void);
void LinkPartnerHandleSetRawMonData(void);
void LinkPartnerHandleLoadMonSprite(void);
void LinkPartnerHandleSwitchInAnim(void);
void LinkPartnerHandleReturnMonToBall(void);
void LinkPartnerHandleDrawTrainerPic(void);
void LinkPartnerHandleTrainerSlide(void);
void LinkPartnerHandleTrainerSlideBack(void);
void LinkPartnerHandleFaintAnimation(void);
void LinkPartnerHandlePaletteFade(void);
void LinkPartnerHandleSuccessBallThrowAnim(void);
void LinkPartnerHandleBallThrowAnim(void);
void LinkPartnerHandlePause(void);
void LinkPartnerHandleMoveAnimation(void);
void LinkPartnerHandlePrintString(void);
void LinkPartnerHandlePrintStringPlayerOnly(void);
void LinkPartnerHandleChooseAction(void);
void LinkPartnerHandleUnknownYesNoBox(void);
void LinkPartnerHandleChooseMove(void);
void LinkPartnerHandleChooseItem(void);
void LinkPartnerHandleChoosePokemon(void);
void LinkPartnerHandleCmd23(void);
void LinkPartnerHandleHealthBarUpdate(void);
void LinkPartnerHandleExpUpdate(void);
void LinkPartnerHandleStatusIconUpdate(void);
void LinkPartnerHandleStatusAnimation(void);
void LinkPartnerHandleStatusXor(void);
void LinkPartnerHandleDataTransfer(void);
void LinkPartnerHandleDMA3Transfer(void);
void LinkPartnerHandlePlayBGM(void);
void LinkPartnerHandleCmd32(void);
void LinkPartnerHandleTwoReturnValues(void);
void LinkPartnerHandleChosenMonReturnValue(void);
void LinkPartnerHandleOneReturnValue(void);
void LinkPartnerHandleOneReturnValue_Duplicate(void);
void LinkPartnerHandleCmd37(void);
void LinkPartnerHandleCmd38(void);
void LinkPartnerHandleCmd39(void);
void LinkPartnerHandleCmd40(void);
void LinkPartnerHandleHitAnimation(void);
void LinkPartnerHandleCmd42(void);
void LinkPartnerHandleEffectivenessSound(void);
void LinkPartnerHandlePlayFanfareOrBGM(void);
void LinkPartnerHandleFaintingCry(void);
void LinkPartnerHandleIntroSlide(void);
void LinkPartnerHandleIntroTrainerBallThrow(void);
void LinkPartnerHandleDrawPartyStatusSummary(void);
void LinkPartnerHandleCmd49(void);
void LinkPartnerHandleCmd50(void);
void LinkPartnerHandleSpriteInvisibility(void);
void LinkPartnerHandleBattleAnimation(void);
void LinkPartnerHandleLinkStandbyMsg(void);
void LinkPartnerHandleResetActionMoveSelection(void);
void LinkPartnerHandleCmd55(void);
void nullsub_113(void);

void LinkPartnerBufferRunCommand(void);
void LinkPartnerBufferExecCompleted(void);

void (*const gLinkPartnerBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    LinkPartnerHandleGetMonData,
    LinkPartnerHandleGetRawMonData,
    LinkPartnerHandleSetMonData,
    LinkPartnerHandleSetRawMonData,
    LinkPartnerHandleLoadMonSprite,
    LinkPartnerHandleSwitchInAnim,
    LinkPartnerHandleReturnMonToBall,
    LinkPartnerHandleDrawTrainerPic,
    LinkPartnerHandleTrainerSlide,
    LinkPartnerHandleTrainerSlideBack,
    LinkPartnerHandleFaintAnimation,
    LinkPartnerHandlePaletteFade,
    LinkPartnerHandleSuccessBallThrowAnim,
    LinkPartnerHandleBallThrowAnim,
    LinkPartnerHandlePause,
    LinkPartnerHandleMoveAnimation,
    LinkPartnerHandlePrintString,
    LinkPartnerHandlePrintStringPlayerOnly,
    LinkPartnerHandleChooseAction,
    LinkPartnerHandleUnknownYesNoBox,
    LinkPartnerHandleChooseMove,
    LinkPartnerHandleChooseItem,
    LinkPartnerHandleChoosePokemon,
    LinkPartnerHandleCmd23,
    LinkPartnerHandleHealthBarUpdate,
    LinkPartnerHandleExpUpdate,
    LinkPartnerHandleStatusIconUpdate,
    LinkPartnerHandleStatusAnimation,
    LinkPartnerHandleStatusXor,
    LinkPartnerHandleDataTransfer,
    LinkPartnerHandleDMA3Transfer,
    LinkPartnerHandlePlayBGM,
    LinkPartnerHandleCmd32,
    LinkPartnerHandleTwoReturnValues,
    LinkPartnerHandleChosenMonReturnValue,
    LinkPartnerHandleOneReturnValue,
    LinkPartnerHandleOneReturnValue_Duplicate,
    LinkPartnerHandleCmd37,
    LinkPartnerHandleCmd38,
    LinkPartnerHandleCmd39,
    LinkPartnerHandleCmd40,
    LinkPartnerHandleHitAnimation,
    LinkPartnerHandleCmd42,
    LinkPartnerHandleEffectivenessSound,
    LinkPartnerHandlePlayFanfareOrBGM,
    LinkPartnerHandleFaintingCry,
    LinkPartnerHandleIntroSlide,
    LinkPartnerHandleIntroTrainerBallThrow,
    LinkPartnerHandleDrawPartyStatusSummary,
    LinkPartnerHandleCmd49,
    LinkPartnerHandleCmd50,
    LinkPartnerHandleSpriteInvisibility,
    LinkPartnerHandleBattleAnimation,
    LinkPartnerHandleLinkStandbyMsg,
    LinkPartnerHandleResetActionMoveSelection,
    LinkPartnerHandleCmd55,
    nullsub_113
};

void nullsub_112(void)
{
}

void SetBankFuncToLinkPartnerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = LinkPartnerBufferRunCommand;
}

void LinkPartnerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gLinkPartnerBufferCommands))
            gLinkPartnerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            LinkPartnerBufferExecCompleted();
    }
}
