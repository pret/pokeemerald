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
#include "data2.h"

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

extern const u8 gText_SafariZoneMenu[];
extern const u8 gText_WhatWillPkmnDo2[];

extern void sub_81358F4(void);

// this file's functions
static void SafariHandleGetMonData(void);
static void SafariHandleGetRawMonData(void);
static void SafariHandleSetMonData(void);
static void SafariHandleSetRawMonData(void);
static void SafariHandleLoadMonSprite(void);
static void SafariHandleSwitchInAnim(void);
static void SafariHandleReturnMonToBall(void);
static void SafariHandleDrawTrainerPic(void);
static void SafariHandleTrainerSlide(void);
static void SafariHandleTrainerSlideBack(void);
static void SafariHandleFaintAnimation(void);
static void SafariHandlePaletteFade(void);
static void SafariHandleSuccessBallThrowAnim(void);
static void SafariHandleBallThrowAnim(void);
static void SafariHandlePause(void);
static void SafariHandleMoveAnimation(void);
static void SafariHandlePrintString(void);
static void SafariHandlePrintStringPlayerOnly(void);
static void SafariHandleChooseAction(void);
static void SafariHandleUnknownYesNoBox(void);
static void SafariHandleChooseMove(void);
static void SafariHandleChooseItem(void);
static void SafariHandleChoosePokemon(void);
static void SafariHandleCmd23(void);
static void SafariHandleHealthBarUpdate(void);
static void SafariHandleExpUpdate(void);
static void SafariHandleStatusIconUpdate(void);
static void SafariHandleStatusAnimation(void);
static void SafariHandleStatusXor(void);
static void SafariHandleDataTransfer(void);
static void SafariHandleDMA3Transfer(void);
static void SafariHandlePlayBGM(void);
static void SafariHandleCmd32(void);
static void SafariHandleTwoReturnValues(void);
static void SafariHandleChosenMonReturnValue(void);
static void SafariHandleOneReturnValue(void);
static void SafariHandleOneReturnValue_Duplicate(void);
static void SafariHandleCmd37(void);
static void SafariHandleCmd38(void);
static void SafariHandleCmd39(void);
static void SafariHandleCmd40(void);
static void SafariHandleHitAnimation(void);
static void SafariHandleCmd42(void);
static void SafariHandleEffectivenessSound(void);
static void SafariHandlePlayFanfareOrBGM(void);
static void SafariHandleFaintingCry(void);
static void SafariHandleIntroSlide(void);
static void SafariHandleIntroTrainerBallThrow(void);
static void SafariHandleDrawPartyStatusSummary(void);
static void SafariHandleCmd49(void);
static void SafariHandleCmd50(void);
static void SafariHandleSpriteInvisibility(void);
static void SafariHandleBattleAnimation(void);
static void SafariHandleLinkStandbyMsg(void);
static void SafariHandleResetActionMoveSelection(void);
static void SafariHandleCmd55(void);
static void nullsub_115(void);

static void SafariBufferRunCommand(void);
static void SafariBufferExecCompleted(void);
static void CompleteWhenChosePokeblock(void);

static void (*const sSafariBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    SafariHandleGetMonData,
    SafariHandleGetRawMonData,
    SafariHandleSetMonData,
    SafariHandleSetRawMonData,
    SafariHandleLoadMonSprite,
    SafariHandleSwitchInAnim,
    SafariHandleReturnMonToBall,
    SafariHandleDrawTrainerPic,
    SafariHandleTrainerSlide,
    SafariHandleTrainerSlideBack,
    SafariHandleFaintAnimation,
    SafariHandlePaletteFade,
    SafariHandleSuccessBallThrowAnim,
    SafariHandleBallThrowAnim,
    SafariHandlePause,
    SafariHandleMoveAnimation,
    SafariHandlePrintString,
    SafariHandlePrintStringPlayerOnly,
    SafariHandleChooseAction,
    SafariHandleUnknownYesNoBox,
    SafariHandleChooseMove,
    SafariHandleChooseItem,
    SafariHandleChoosePokemon,
    SafariHandleCmd23,
    SafariHandleHealthBarUpdate,
    SafariHandleExpUpdate,
    SafariHandleStatusIconUpdate,
    SafariHandleStatusAnimation,
    SafariHandleStatusXor,
    SafariHandleDataTransfer,
    SafariHandleDMA3Transfer,
    SafariHandlePlayBGM,
    SafariHandleCmd32,
    SafariHandleTwoReturnValues,
    SafariHandleChosenMonReturnValue,
    SafariHandleOneReturnValue,
    SafariHandleOneReturnValue_Duplicate,
    SafariHandleCmd37,
    SafariHandleCmd38,
    SafariHandleCmd39,
    SafariHandleCmd40,
    SafariHandleHitAnimation,
    SafariHandleCmd42,
    SafariHandleEffectivenessSound,
    SafariHandlePlayFanfareOrBGM,
    SafariHandleFaintingCry,
    SafariHandleIntroSlide,
    SafariHandleIntroTrainerBallThrow,
    SafariHandleDrawPartyStatusSummary,
    SafariHandleCmd49,
    SafariHandleCmd50,
    SafariHandleSpriteInvisibility,
    SafariHandleBattleAnimation,
    SafariHandleLinkStandbyMsg,
    SafariHandleResetActionMoveSelection,
    SafariHandleCmd55,
    nullsub_115
};

static void nullsub_114(void)
{
}

void SetControllerToSafari(void)
{
    gBattleBankFunc[gActiveBank] = SafariBufferRunCommand;
}

static void SafariBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(sSafariBufferCommands))
            sSafariBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            SafariBufferExecCompleted();
    }
}

static void HandleInputChooseAction(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[gActiveBank])
        {
        case 0:
            EmitTwoReturnValues(1, ACTION_SAFARI_ZONE_BALL, 0);
            break;
        case 1:
            EmitTwoReturnValues(1, ACTION_POKEBLOCK_CASE, 0);
            break;
        case 2:
            EmitTwoReturnValues(1, ACTION_GO_NEAR, 0);
            break;
        case 3:
            EmitTwoReturnValues(1, ACTION_SAFARI_ZONE_RUN, 0);
            break;
        }
        SafariBufferExecCompleted();
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gActionSelectionCursor[gActiveBank] & 1)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        if (!(gActionSelectionCursor[gActiveBank] & 1))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gActionSelectionCursor[gActiveBank] & 2)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (!(gActionSelectionCursor[gActiveBank] & 2))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        SafariBufferExecCompleted();
}

static void CompleteOnHealthboxSpriteCallbackDummy(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

static void sub_81595E4(void)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

static void CompleteOnSpecialAnimDone(void)
{
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        SafariBufferExecCompleted();
}

static void OpenPokeblockCase(void)
{
    if (!gPaletteFade.active)
    {
        gBattleBankFunc[gActiveBank] = CompleteWhenChosePokeblock;
        FreeAllWindowBuffers();
        sub_81358F4();
    }
}

static void CompleteWhenChosePokeblock(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        EmitOneReturnValue(1, gScriptItemId);
        SafariBufferExecCompleted();
    }
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        SafariBufferExecCompleted();
}

static void SafariBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = SafariBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBank][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleExecBuffer &= ~gBitTable[gActiveBank];
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        SafariBufferExecCompleted();
}

static void SafariHandleGetMonData(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleGetRawMonData(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSetMonData(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSetRawMonData(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleLoadMonSprite(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSwitchInAnim(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleReturnMonToBall(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleDrawTrainerPic(void)
{
    DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, gActiveBank);
    sub_806A12C(gSaveBlock2Ptr->playerGender, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(
      &gUnknown_0202499C,
      80,
      (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].coords) * 4 + 80,
      30);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;
    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void SafariHandleTrainerSlide(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleTrainerSlideBack(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleFaintAnimation(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandlePaletteFade(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSuccessBallThrowAnim(void)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_SAFARI_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnSpecialAnimDone;
}

static void SafariHandleBallThrowAnim(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBank][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_SAFARI_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnSpecialAnimDone;
}

static void SafariHandlePause(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleMoveAnimation(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter;
}

static void SafariHandlePrintStringPlayerOnly(void)
{
    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        SafariHandlePrintString();
    else
        SafariBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        gBattleBankFunc[gActiveBank] = HandleInputChooseAction;
    }
}

static void SafariHandleChooseAction(void)
{
    s32 i;

    gBattleBankFunc[gActiveBank] = HandleChooseActionAfterDma3;
    BattleHandleAddTextPrinter(gText_SafariZoneMenu, 2);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo2);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 1);
}

static void SafariHandleUnknownYesNoBox(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleChooseMove(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleChooseItem(void)
{
    s32 i;

    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gBattleBankFunc[gActiveBank] = OpenPokeblockCase;
    gBankInMenu = gActiveBank;
}

static void SafariHandleChoosePokemon(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd23(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleHealthBarUpdate(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleExpUpdate(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleStatusIconUpdate(void)
{
    UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_SAFARI_BALLS_TEXT);
    SafariBufferExecCompleted();
}

static void SafariHandleStatusAnimation(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleStatusXor(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleDataTransfer(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleDMA3Transfer(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandlePlayBGM(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd32(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleTwoReturnValues(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleChosenMonReturnValue(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleOneReturnValue(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleOneReturnValue_Duplicate(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd37(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd38(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd39(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd40(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleHitAnimation(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd42(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    SafariBufferExecCompleted();
}

static void SafariHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBank][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }

    SafariBufferExecCompleted();
}

static void SafariHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry1(species, 25);
    SafariBufferExecCompleted();
}

static void SafariHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    SafariBufferExecCompleted();
}

static void SafariHandleIntroTrainerBallThrow(void)
{
    UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_SAFARI_ALL_TEXT);
    sub_8076918(gActiveBank);
    SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
    gBattleBankFunc[gActiveBank] = CompleteOnHealthboxSpriteCallbackDummy;
}

static void SafariHandleDrawPartyStatusSummary(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd49(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd50(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSpriteInvisibility(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleBattleAnimation(void)
{
    u8 animationId = gBattleBufferA[gActiveBank][1];
    u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    if (TryHandleLaunchBattleTableAnimation(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
        SafariBufferExecCompleted();
    else
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;
}

static void SafariHandleLinkStandbyMsg(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleResetActionMoveSelection(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCmd55(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBank][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    SafariBufferExecCompleted();
    if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && !(gBattleTypeFlags & BATTLE_TYPE_WILD))
        gBattleBankFunc[gActiveBank] = sub_81595E4;
}

static void nullsub_115(void)
{
}
