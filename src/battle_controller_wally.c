#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tv.h"
#include "bg.h"
#include "data.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

static void WallyHandleDrawTrainerPic(enum BattlerId battler);
static void WallyHandleTrainerSlide(enum BattlerId battler);
static void WallyHandleChooseAction(enum BattlerId battler);
static void WallyHandleChooseMove(enum BattlerId battler);
static void WallyHandleChooseItem(enum BattlerId battler);
static void WallyHandleFaintingCry(enum BattlerId battler);
static void WallyHandleIntroTrainerBallThrow(enum BattlerId battler);
static void WallyHandleDrawPartyStatusSummary(enum BattlerId battler);
static void WallyHandleEndLinkBattle(enum BattlerId battler);

static void WallyBufferRunCommand(enum BattlerId battler);
static void CompleteOnChosenItem(enum BattlerId battler);
static void Intro_WaitForShinyAnimAndHealthbox(enum BattlerId battler);

static void (*const sWallyBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_Empty,
    [CONTROLLER_SWITCHINANIM]             = BtlController_Empty,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = WallyHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = WallyHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_Empty,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_HandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_HandlePrintStringPlayerOnly,
    [CONTROLLER_CHOOSEACTION]             = WallyHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = WallyHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = WallyHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = BtlController_Empty,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = BtlController_Empty,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_Empty,
    [CONTROLLER_STATUSANIMATION]          = BtlController_Empty,
    [CONTROLLER_STATUSXOR]                = BtlController_Empty,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BtlController_Empty,
    [CONTROLLER_PLAYBGM]                  = BtlController_Empty,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BtlController_Empty,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BtlController_Empty,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = WallyHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = WallyHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = WallyHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = WallyHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToWally(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_WALLY;
    gBattlerControllerEndFuncs[battler] = WallyBufferExecCompleted;
    gBattlerControllerFuncs[battler] = WallyBufferRunCommand;
    gBattleStruct->wallyBattleState = 0;
    gBattleStruct->wallyMovesState = 0;
    gBattleStruct->wallyWaitFrames = 0;
    gBattleStruct->wallyMoveFrames = 0;
}

static void WallyBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sWallyBufferCommands))
            sWallyBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void WallyHandleActions(enum BattlerId battler)
{
    switch (gBattleStruct->wallyBattleState)
    {
    case 0:
        gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        gBattleStruct->wallyBattleState++;
    case 1:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
            BtlController_Complete(battler);
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
            BtlController_Complete(battler);
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        }
        break;
    case 3:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_WALLY_THROW, 0);
            BtlController_Complete(battler);
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        }
        break;
    case 4:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(0);
            ActionSelectionCreateCursorAt(1, 0);
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
            gBattleStruct->wallyBattleState++;
        }
        break;
    case 5:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_ITEM, 0);
            BtlController_Complete(battler);
        }
        break;
    }
}

static void OpenBagAfterPaletteFade(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteOnChosenItem;
        ReshowBattleScreenDummy();
        CloseMainBattleScreen();
        DoWallyTutorialBagMenu();
    }
}

static void CompleteOnChosenItem(enum BattlerId battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        BtlController_Complete(battler);
    }
}

static void Intro_TryShinyAnimShowHealthbox(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    if (!gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive)
        TryShinyAnimation(GetPartnerBattler(battler), GetBattlerMon(GetPartnerBattler(battler)));

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive
        && gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[GetPartnerBattler(battler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[GetPartnerBattler(battler)], GetBattlerMon(GetPartnerBattler(battler)), HEALTHBOX_ALL);
            StartHealthboxSlideIn(GetPartnerBattler(battler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[GetPartnerBattler(battler)]);
        }
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(enum BattlerId battler)
{
    bool32 healthboxAnimDone = FALSE;

    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        healthboxAnimDone = TRUE;

    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

        gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim = FALSE;

        FreeShinyStars();

        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(GetBattlerMon(battler), battler);

        BtlController_Complete(battler);
    }
}

void WallyBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = WallyBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        MarkBattleControllerIdleOnLocal(battler);
    }
}

#define sSpeedX data[0]

static void WallyHandleDrawTrainerPic(enum BattlerId battler)
{
    BtlController_HandleDrawTrainerPic(battler, TRAINER_PIC_WALLY, FALSE,
                                       80, 80 + 4 * (8 - GetTrainerBackPicCoords(TRAINER_PIC_WALLY)->size),
                                       30);
}

static void WallyHandleTrainerSlide(enum BattlerId battler)
{
    BtlController_HandleTrainerSlide(battler, TRAINER_PIC_WALLY);
}

#undef sSpeedX

static void HandleChooseActionAfterDma3(enum BattlerId battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[battler] = WallyHandleActions;
    }
}

static void WallyHandleChooseAction(enum BattlerId battler)
{
    s32 i;

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillWallyDo);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void WallyHandleChooseMove(enum BattlerId battler)
{
    switch (gBattleStruct->wallyMovesState)
    {
    case 0:
        InitMoveSelectionsVarsAndStrings(battler);
        gBattleStruct->wallyMovesState++;
        gBattleStruct->wallyMoveFrames = 80;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattle_BG0_X = 0;
            gBattle_BG0_Y = DISPLAY_HEIGHT * 2;
            gBattleStruct->wallyMovesState++;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyMoveFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, 0x100);
            BtlController_Complete(battler);
        }
        break;
    }
}

static void WallyHandleChooseItem(enum BattlerId battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenBagAfterPaletteFade;
    gBattlerInMenuId = battler;
}

// All of the other controllers use CRY_MODE_FAINT.
// Wally's Pokémon during the tutorial is never intended to faint, so that's probably why it's different here.
static void WallyHandleFaintingCry(enum BattlerId battler)
{
    enum Species species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    BtlController_Complete(battler);
}

static void WallyHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    const u16 *trainerPal = GetTrainerBackPicPalette(TRAINER_PIC_WALLY);
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

static void WallyHandleDrawPartyStatusSummary(enum BattlerId battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, FALSE);
}

static void WallyHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);

    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
