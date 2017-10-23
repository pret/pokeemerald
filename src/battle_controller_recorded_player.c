#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "recorded_battle.h"
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
void RecordedPlayerHandleGetMonData(void);
void RecordedPlayerHandleGetRawMonData(void);
void RecordedPlayerHandleSetMonData(void);
void RecordedPlayerHandleSetRawMonData(void);
void RecordedPlayerHandleLoadMonSprite(void);
void RecordedPlayerHandleSwitchInAnim(void);
void RecordedPlayerHandleReturnMonToBall(void);
void RecordedPlayerHandleDrawTrainerPic(void);
void RecordedPlayerHandleTrainerSlide(void);
void RecordedPlayerHandleTrainerSlideBack(void);
void RecordedPlayerHandleFaintAnimation(void);
void RecordedPlayerHandlePaletteFade(void);
void RecordedPlayerHandleSuccessBallThrowAnim(void);
void RecordedPlayerHandleBallThrowAnim(void);
void RecordedPlayerHandlePause(void);
void RecordedPlayerHandleMoveAnimation(void);
void RecordedPlayerHandlePrintString(void);
void RecordedPlayerHandlePrintStringPlayerOnly(void);
void RecordedPlayerHandleChooseAction(void);
void RecordedPlayerHandleUnknownYesNoBox(void);
void RecordedPlayerHandleChooseMove(void);
void RecordedPlayerHandleChooseItem(void);
void RecordedPlayerHandleChoosePokemon(void);
void RecordedPlayerHandleCmd23(void);
void RecordedPlayerHandleHealthBarUpdate(void);
void RecordedPlayerHandleExpUpdate(void);
void RecordedPlayerHandleStatusIconUpdate(void);
void RecordedPlayerHandleStatusAnimation(void);
void RecordedPlayerHandleStatusXor(void);
void RecordedPlayerHandleDataTransfer(void);
void RecordedPlayerHandleDMA3Transfer(void);
void RecordedPlayerHandlePlayBGM(void);
void RecordedPlayerHandleCmd32(void);
void RecordedPlayerHandleTwoReturnValues(void);
void RecordedPlayerHandleChosenMonReturnValue(void);
void RecordedPlayerHandleOneReturnValue(void);
void RecordedPlayerHandleOneReturnValue_Duplicate(void);
void RecordedPlayerHandleCmd37(void);
void RecordedPlayerHandleCmd38(void);
void RecordedPlayerHandleCmd39(void);
void RecordedPlayerHandleCmd40(void);
void RecordedPlayerHandleHitAnimation(void);
void RecordedPlayerHandleCmd42(void);
void RecordedPlayerHandleEffectivenessSound(void);
void RecordedPlayerHandlePlayFanfareOrBGM(void);
void RecordedPlayerHandleFaintingCry(void);
void RecordedPlayerHandleIntroSlide(void);
void RecordedPlayerHandleIntroTrainerBallThrow(void);
void RecordedPlayerHandleDrawPartyStatusSummary(void);
void RecordedPlayerHandleCmd49(void);
void RecordedPlayerHandleCmd50(void);
void RecordedPlayerHandleSpriteInvisibility(void);
void RecordedPlayerHandleBattleAnimation(void);
void RecordedPlayerHandleLinkStandbyMsg(void);
void RecordedPlayerHandleResetActionMoveSelection(void);
void RecordedPlayerHandleCmd55(void);
void nullsub_121(void);

void RecordedPlayerBufferRunCommand(void);
void RecordedPlayerBufferExecCompleted(void);

void (*const gRecordedPlayerBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    RecordedPlayerHandleGetMonData,
    RecordedPlayerHandleGetRawMonData,
    RecordedPlayerHandleSetMonData,
    RecordedPlayerHandleSetRawMonData,
    RecordedPlayerHandleLoadMonSprite,
    RecordedPlayerHandleSwitchInAnim,
    RecordedPlayerHandleReturnMonToBall,
    RecordedPlayerHandleDrawTrainerPic,
    RecordedPlayerHandleTrainerSlide,
    RecordedPlayerHandleTrainerSlideBack,
    RecordedPlayerHandleFaintAnimation,
    RecordedPlayerHandlePaletteFade,
    RecordedPlayerHandleSuccessBallThrowAnim,
    RecordedPlayerHandleBallThrowAnim,
    RecordedPlayerHandlePause,
    RecordedPlayerHandleMoveAnimation,
    RecordedPlayerHandlePrintString,
    RecordedPlayerHandlePrintStringPlayerOnly,
    RecordedPlayerHandleChooseAction,
    RecordedPlayerHandleUnknownYesNoBox,
    RecordedPlayerHandleChooseMove,
    RecordedPlayerHandleChooseItem,
    RecordedPlayerHandleChoosePokemon,
    RecordedPlayerHandleCmd23,
    RecordedPlayerHandleHealthBarUpdate,
    RecordedPlayerHandleExpUpdate,
    RecordedPlayerHandleStatusIconUpdate,
    RecordedPlayerHandleStatusAnimation,
    RecordedPlayerHandleStatusXor,
    RecordedPlayerHandleDataTransfer,
    RecordedPlayerHandleDMA3Transfer,
    RecordedPlayerHandlePlayBGM,
    RecordedPlayerHandleCmd32,
    RecordedPlayerHandleTwoReturnValues,
    RecordedPlayerHandleChosenMonReturnValue,
    RecordedPlayerHandleOneReturnValue,
    RecordedPlayerHandleOneReturnValue_Duplicate,
    RecordedPlayerHandleCmd37,
    RecordedPlayerHandleCmd38,
    RecordedPlayerHandleCmd39,
    RecordedPlayerHandleCmd40,
    RecordedPlayerHandleHitAnimation,
    RecordedPlayerHandleCmd42,
    RecordedPlayerHandleEffectivenessSound,
    RecordedPlayerHandlePlayFanfareOrBGM,
    RecordedPlayerHandleFaintingCry,
    RecordedPlayerHandleIntroSlide,
    RecordedPlayerHandleIntroTrainerBallThrow,
    RecordedPlayerHandleDrawPartyStatusSummary,
    RecordedPlayerHandleCmd49,
    RecordedPlayerHandleCmd50,
    RecordedPlayerHandleSpriteInvisibility,
    RecordedPlayerHandleBattleAnimation,
    RecordedPlayerHandleLinkStandbyMsg,
    RecordedPlayerHandleResetActionMoveSelection,
    RecordedPlayerHandleCmd55,
    nullsub_121
};

void nullsub_120(void)
{
}

void SetBankFuncToRecordedPlayerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = RecordedPlayerBufferRunCommand;
}

void RecordedPlayerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gRecordedPlayerBufferCommands))
            gRecordedPlayerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            RecordedPlayerBufferExecCompleted();
    }
}
