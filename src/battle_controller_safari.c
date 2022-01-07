#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "bg.h"
#include "data.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokeball.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"
#include "constants/rgb.h"

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
static void SafariHandlePrintSelectionString(void);
static void SafariHandleChooseAction(void);
static void SafariHandleYesNoBox(void);
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
static void SafariHandleClearUnkVar(void);
static void SafariHandleSetUnkVar(void);
static void SafariHandleClearUnkFlag(void);
static void SafariHandleToggleUnkFlag(void);
static void SafariHandleHitAnimation(void);
static void SafariHandleCantSwitch(void);
static void SafariHandlePlaySE(void);
static void SafariHandlePlayFanfareOrBGM(void);
static void SafariHandleFaintingCry(void);
static void SafariHandleIntroSlide(void);
static void SafariHandleIntroTrainerBallThrow(void);
static void SafariHandleDrawPartyStatusSummary(void);
static void SafariHandleHidePartyStatusSummary(void);
static void SafariHandleEndBounceEffect(void);
static void SafariHandleSpriteInvisibility(void);
static void SafariHandleBattleAnimation(void);
static void SafariHandleLinkStandbyMsg(void);
static void SafariHandleResetActionMoveSelection(void);
static void SafariHandleEndLinkBattle(void);
static void SafariCmdEnd(void);

static void SafariBufferRunCommand(void);
static void SafariBufferExecCompleted(void);
static void CompleteWhenChosePokeblock(void);

static void (*const sSafariBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    [CONTROLLER_GETMONDATA]               = SafariHandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = SafariHandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = SafariHandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = SafariHandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = SafariHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = SafariHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = SafariHandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = SafariHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = SafariHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = SafariHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = SafariHandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = SafariHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = SafariHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = SafariHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = SafariHandlePause,
    [CONTROLLER_MOVEANIMATION]            = SafariHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = SafariHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = SafariHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = SafariHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = SafariHandleYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = SafariHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = SafariHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = SafariHandleChoosePokemon,
    [CONTROLLER_23]                       = SafariHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = SafariHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = SafariHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = SafariHandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = SafariHandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = SafariHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = SafariHandleDataTransfer,
    [CONTROLLER_DMA3TRANSFER]             = SafariHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = SafariHandlePlayBGM,
    [CONTROLLER_32]                       = SafariHandleCmd32,
    [CONTROLLER_TWORETURNVALUES]          = SafariHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = SafariHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = SafariHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = SafariHandleOneReturnValue_Duplicate,
    [CONTROLLER_CLEARUNKVAR]              = SafariHandleClearUnkVar,
    [CONTROLLER_SETUNKVAR]                = SafariHandleSetUnkVar,
    [CONTROLLER_CLEARUNKFLAG]             = SafariHandleClearUnkFlag,
    [CONTROLLER_TOGGLEUNKFLAG]            = SafariHandleToggleUnkFlag,
    [CONTROLLER_HITANIMATION]             = SafariHandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = SafariHandleCantSwitch,
    [CONTROLLER_PLAYSE]                   = SafariHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = SafariHandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = SafariHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = SafariHandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = SafariHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = SafariHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = SafariHandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = SafariHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = SafariHandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = SafariHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = SafariHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = SafariHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = SafariHandleEndLinkBattle,
    [CONTROLLER_TERMINATOR_NOP]           = SafariCmdEnd
};

static void SpriteCB_Null4(void)
{
}

void SetControllerToSafari(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
}

static void SafariBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleBufferA[gActiveBattler][0] < ARRAY_COUNT(sSafariBufferCommands))
            sSafariBufferCommands[gBattleBufferA[gActiveBattler][0]]();
        else
            SafariBufferExecCompleted();
    }
}

static void HandleInputChooseAction(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[gActiveBattler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SAFARI_BALL, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SAFARI_POKEBLOCK, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SAFARI_GO_NEAR, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SAFARI_RUN, 0);
            break;
        }
        SafariBufferExecCompleted();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[gActiveBattler] & 1)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 1))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[gActiveBattler] & 2)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 2))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
}

static void CompleteOnBattlerSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(B_WIN_MSG))
        SafariBufferExecCompleted();
}

static void CompleteOnHealthboxSpriteCallbackDummy(void)
{
    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

static void SafariSetBattleEndCallbacks(void)
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
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        SafariBufferExecCompleted();
}

static void SafariOpenPokeblockCase(void)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[gActiveBattler] = CompleteWhenChosePokeblock;
        FreeAllWindowBuffers();
        OpenPokeblockCaseInBattle();
    }
}

static void CompleteWhenChosePokeblock(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(BUFFER_B, gSpecialVar_ItemId);
        SafariBufferExecCompleted();
    }
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animFromTableActive)
        SafariBufferExecCompleted();
}

static void SafariBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBattler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[gActiveBattler];
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive)
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

#define sSpeedX data[0]

static void SafariHandleDrawTrainerPic(void)
{
    DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, gActiveBattler);
    SetMultiuseSpriteTemplateToTrainerBack(gSaveBlock2Ptr->playerGender, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(
      &gMultiuseSpriteTemplate,
      80,
      (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].size) * 4 + 80,
      30);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = DISPLAY_WIDTH;
    gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = -2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnBattlerSpriteCallbackDummy;
}

#undef sSpeedX

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
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnSpecialAnimDone;
}

static void SafariHandleBallThrowAnim(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBattler][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnSpecialAnimDone;
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
    stringId = (u16*)(&gBattleBufferA[gActiveBattler][2]);
    BufferStringBattle(*stringId);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnInactiveTextPrinter;
}

static void SafariHandlePrintSelectionString(void)
{
    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        SafariHandlePrintString();
    else
        SafariBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[gActiveBattler] = HandleInputChooseAction;
    }
}

static void SafariHandleChooseAction(void)
{
    s32 i;

    gBattlerControllerFuncs[gActiveBattler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_SafariZoneMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo2);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void SafariHandleYesNoBox(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleChooseMove(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleChooseItem(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[gActiveBattler] = SafariOpenPokeblockCase;
    gBattlerInMenuId = gActiveBattler;
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
    UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_SAFARI_BALLS_TEXT);
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

static void SafariHandleClearUnkVar(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSetUnkVar(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleClearUnkFlag(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleToggleUnkFlag(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleHitAnimation(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleCantSwitch(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandlePlaySE(void)
{
    s8 pan;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        pan = SOUND_PAN_ATTACKER;
    else
        pan = SOUND_PAN_TARGET;

    PlaySE12WithPanning(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8), pan);
    SafariBufferExecCompleted();
}

static void SafariHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBattler][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }

    SafariBufferExecCompleted();
}

static void SafariHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    SafariBufferExecCompleted();
}

static void SafariHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    SafariBufferExecCompleted();
}

static void SafariHandleIntroTrainerBallThrow(void)
{
    UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_SAFARI_ALL_TEXT);
    StartHealthboxSlideIn(gActiveBattler);
    SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnHealthboxSpriteCallbackDummy;
}

static void SafariHandleDrawPartyStatusSummary(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleHidePartyStatusSummary(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleEndBounceEffect(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleSpriteInvisibility(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleBattleAnimation(void)
{
    u8 animationId = gBattleBufferA[gActiveBattler][1];
    u16 argument = gBattleBufferA[gActiveBattler][2] | (gBattleBufferA[gActiveBattler][3] << 8);

    if (TryHandleLaunchBattleTableAnimation(gActiveBattler, gActiveBattler, gActiveBattler, animationId, argument))
        SafariBufferExecCompleted();
    else
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedBattleAnimation;
}

static void SafariHandleLinkStandbyMsg(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleResetActionMoveSelection(void)
{
    SafariBufferExecCompleted();
}

static void SafariHandleEndLinkBattle(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    SafariBufferExecCompleted();
    if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && !(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
        gBattlerControllerFuncs[gActiveBattler] = SafariSetBattleEndCallbacks;
}

static void SafariCmdEnd(void)
{
}
