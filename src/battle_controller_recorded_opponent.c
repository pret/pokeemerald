#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_link_817C95C.h"
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
extern u16 gUnknown_020243FC;
extern u8 gUnknown_03005D7C[BATTLE_BANKS_COUNT];
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u16 gPartnerTrainerId;
extern u8 GetFrontierTrainerFrontSpriteId(u16 trainerId);
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gUnknown_020244B4[];
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlay_BGM;
extern struct UnusedControllerStruct gUnknown_02022D0C;
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const struct BattleMove gBattleMoves[];
extern const u8 gUnknown_0831F578[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);
extern void sub_81851A8(u8 *);
extern u16 sub_8068B48(void);

// this file's functions
void RecordedOpponentHandleGetMonData(void);
void RecordedOpponentHandleGetRawMonData(void);
void RecordedOpponentHandleSetMonData(void);
void RecordedOpponentHandleSetRawMonData(void);
void RecordedOpponentHandleLoadMonSprite(void);
void RecordedOpponentHandleSwitchInAnim(void);
void RecordedOpponentHandleReturnMonToBall(void);
void RecordedOpponentHandleDrawTrainerPic(void);
void RecordedOpponentHandleTrainerSlide(void);
void RecordedOpponentHandleTrainerSlideBack(void);
void RecordedOpponentHandleFaintAnimation(void);
void RecordedOpponentHandlePaletteFade(void);
void RecordedOpponentHandleSuccessBallThrowAnim(void);
void RecordedOpponentHandleBallThrowAnim(void);
void RecordedOpponentHandlePause(void);
void RecordedOpponentHandleMoveAnimation(void);
void RecordedOpponentHandlePrintString(void);
void RecordedOpponentHandlePrintStringPlayerOnly(void);
void RecordedOpponentHandleChooseAction(void);
void RecordedOpponentHandleUnknownYesNoBox(void);
void RecordedOpponentHandleChooseMove(void);
void RecordedOpponentHandleChooseItem(void);
void RecordedOpponentHandleChoosePokemon(void);
void RecordedOpponentHandleCmd23(void);
void RecordedOpponentHandleHealthBarUpdate(void);
void RecordedOpponentHandleExpUpdate(void);
void RecordedOpponentHandleStatusIconUpdate(void);
void RecordedOpponentHandleStatusAnimation(void);
void RecordedOpponentHandleStatusXor(void);
void RecordedOpponentHandleDataTransfer(void);
void RecordedOpponentHandleDMA3Transfer(void);
void RecordedOpponentHandlePlayBGM(void);
void RecordedOpponentHandleCmd32(void);
void RecordedOpponentHandleTwoReturnValues(void);
void RecordedOpponentHandleChosenMonReturnValue(void);
void RecordedOpponentHandleOneReturnValue(void);
void RecordedOpponentHandleOneReturnValue_Duplicate(void);
void RecordedOpponentHandleCmd37(void);
void RecordedOpponentHandleCmd38(void);
void RecordedOpponentHandleCmd39(void);
void RecordedOpponentHandleCmd40(void);
void RecordedOpponentHandleHitAnimation(void);
void RecordedOpponentHandleCmd42(void);
void RecordedOpponentHandleEffectivenessSound(void);
void RecordedOpponentHandlePlayFanfareOrBGM(void);
void RecordedOpponentHandleFaintingCry(void);
void RecordedOpponentHandleIntroSlide(void);
void RecordedOpponentHandleIntroTrainerBallThrow(void);
void RecordedOpponentHandleDrawPartyStatusSummary(void);
void RecordedOpponentHandleCmd49(void);
void RecordedOpponentHandleCmd50(void);
void RecordedOpponentHandleSpriteInvisibility(void);
void RecordedOpponentHandleBattleAnimation(void);
void RecordedOpponentHandleLinkStandbyMsg(void);
void RecordedOpponentHandleResetActionMoveSelection(void);
void RecordedOpponentHandleCmd55(void);
void nullsub_119(void);

void RecordedOpponentBufferRunCommand(void);
void RecordedOpponentBufferExecCompleted(void);

void (*const gRecordedOpponentBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
{
    RecordedOpponentHandleGetMonData,
    RecordedOpponentHandleGetRawMonData,
    RecordedOpponentHandleSetMonData,
    RecordedOpponentHandleSetRawMonData,
    RecordedOpponentHandleLoadMonSprite,
    RecordedOpponentHandleSwitchInAnim,
    RecordedOpponentHandleReturnMonToBall,
    RecordedOpponentHandleDrawTrainerPic,
    RecordedOpponentHandleTrainerSlide,
    RecordedOpponentHandleTrainerSlideBack,
    RecordedOpponentHandleFaintAnimation,
    RecordedOpponentHandlePaletteFade,
    RecordedOpponentHandleSuccessBallThrowAnim,
    RecordedOpponentHandleBallThrowAnim,
    RecordedOpponentHandlePause,
    RecordedOpponentHandleMoveAnimation,
    RecordedOpponentHandlePrintString,
    RecordedOpponentHandlePrintStringPlayerOnly,
    RecordedOpponentHandleChooseAction,
    RecordedOpponentHandleUnknownYesNoBox,
    RecordedOpponentHandleChooseMove,
    RecordedOpponentHandleChooseItem,
    RecordedOpponentHandleChoosePokemon,
    RecordedOpponentHandleCmd23,
    RecordedOpponentHandleHealthBarUpdate,
    RecordedOpponentHandleExpUpdate,
    RecordedOpponentHandleStatusIconUpdate,
    RecordedOpponentHandleStatusAnimation,
    RecordedOpponentHandleStatusXor,
    RecordedOpponentHandleDataTransfer,
    RecordedOpponentHandleDMA3Transfer,
    RecordedOpponentHandlePlayBGM,
    RecordedOpponentHandleCmd32,
    RecordedOpponentHandleTwoReturnValues,
    RecordedOpponentHandleChosenMonReturnValue,
    RecordedOpponentHandleOneReturnValue,
    RecordedOpponentHandleOneReturnValue_Duplicate,
    RecordedOpponentHandleCmd37,
    RecordedOpponentHandleCmd38,
    RecordedOpponentHandleCmd39,
    RecordedOpponentHandleCmd40,
    RecordedOpponentHandleHitAnimation,
    RecordedOpponentHandleCmd42,
    RecordedOpponentHandleEffectivenessSound,
    RecordedOpponentHandlePlayFanfareOrBGM,
    RecordedOpponentHandleFaintingCry,
    RecordedOpponentHandleIntroSlide,
    RecordedOpponentHandleIntroTrainerBallThrow,
    RecordedOpponentHandleDrawPartyStatusSummary,
    RecordedOpponentHandleCmd49,
    RecordedOpponentHandleCmd50,
    RecordedOpponentHandleSpriteInvisibility,
    RecordedOpponentHandleBattleAnimation,
    RecordedOpponentHandleLinkStandbyMsg,
    RecordedOpponentHandleResetActionMoveSelection,
    RecordedOpponentHandleCmd55,
    nullsub_119
};

void nullsub_70(void)
{
}

void SetBankFuncToRecordedOpponentBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = RecordedOpponentBufferRunCommand;
}

void RecordedOpponentBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gRecordedOpponentBufferCommands))
            gRecordedOpponentBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            RecordedOpponentBufferExecCompleted();
    }
}
