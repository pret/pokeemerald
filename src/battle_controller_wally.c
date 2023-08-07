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

static void WallyHandleDrawTrainerPic(void);
static void WallyHandleTrainerSlide(void);
static void WallyHandleSuccessBallThrowAnim(void);
static void WallyHandleBallThrowAnim(void);
static void WallyHandleMoveAnimation(void);
static void WallyHandlePrintString(void);
static void WallyHandlePrintSelectionString(void);
static void WallyHandleChooseAction(void);
static void WallyHandleChooseMove(void);
static void WallyHandleChooseItem(void);
static void WallyHandleHealthBarUpdate(void);
static void WallyHandlePlaySE(void);
static void WallyHandleFaintingCry(void);
static void WallyHandleIntroTrainerBallThrow(void);
static void WallyHandleDrawPartyStatusSummary(void);
static void WallyHandleBattleAnimation(void);
static void WallyHandleEndLinkBattle(void);

static void WallyBufferRunCommand(void);
static void WallyBufferExecCompleted(void);
static void CompleteOnChosenItem(void);
static void Intro_WaitForShinyAnimAndHealthbox(void);

static void (*const sWallyBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
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
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = WallyHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = WallyHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = WallyHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = WallyHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = WallyHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = WallyHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = WallyHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = WallyHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = BtlController_Empty,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = WallyHandleHealthBarUpdate,
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
    [CONTROLLER_CLEARUNKVAR]              = BtlController_Empty,
    [CONTROLLER_SETUNKVAR]                = BtlController_Empty,
    [CONTROLLER_CLEARUNKFLAG]             = BtlController_Empty,
    [CONTROLLER_TOGGLEUNKFLAG]            = BtlController_Empty,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = WallyHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = WallyHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = WallyHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = WallyHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = WallyHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = WallyHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToWally(void)
{
    gBattlerControllerEndFuncs[gActiveBattler] = WallyBufferExecCompleted;
    gBattlerControllerFuncs[gActiveBattler] = WallyBufferRunCommand;
    gBattleStruct->wallyBattleState = 0;
    gBattleStruct->wallyMovesState = 0;
    gBattleStruct->wallyWaitFrames = 0;
    gBattleStruct->wallyMoveFrames = 0;
}

static void WallyBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleResources->bufferA[gActiveBattler][0] < ARRAY_COUNT(sWallyBufferCommands))
            sWallyBufferCommands[gBattleResources->bufferA[gActiveBattler][0]]();
        else
            WallyBufferExecCompleted();
    }
}

static void WallyHandleActions(void)
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
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = B_WAIT_TIME_LONG;
        }
        break;
    case 3:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_WALLY_THROW, 0);
            WallyBufferExecCompleted();
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
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_USE_ITEM, 0);
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void CompleteOnBattlerSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        WallyBufferExecCompleted();
}

static void OpenBagAfterPaletteFade(void)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnChosenItem;
        ReshowBattleScreenDummy();
        FreeAllWindowBuffers();
        DoWallyTutorialBagMenu();
    }
}

static void CompleteOnChosenItem(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(BUFFER_B, gSpecialVar_ItemId);
        WallyBufferExecCompleted();
    }
}

static void Intro_TryShinyAnimShowHealthbox(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
        TryShinyAnimation(gActiveBattler, &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive)
        TryShinyAnimation(BATTLE_PARTNER(gActiveBattler), &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive
        && gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(gActiveBattler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)], &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(BATTLE_PARTNER(gActiveBattler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]);
        }
        DestroySprite(&gSprites[gBattleControllerData[gActiveBattler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(gActiveBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattlerControllerFuncs[gActiveBattler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(void)
{
    bool32 healthboxAnimDone = FALSE;

    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        healthboxAnimDone = TRUE;

    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;

        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim = FALSE;

        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);

        WallyBufferExecCompleted();
    }
}

static void WallyBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = WallyBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleResources->bufferA[gActiveBattler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[gActiveBattler];
    }
}

#define sSpeedX data[0]

static void WallyHandleDrawTrainerPic(void)
{
    BtlController_HandleDrawTrainerPic(gActiveBattler, TRAINER_BACK_PIC_WALLY, FALSE,
                                       80, 80 + 4 * (8 - gTrainerBackPicCoords[TRAINER_BACK_PIC_WALLY].size),
                                       30);
}

static void WallyHandleTrainerSlide(void)
{
    BtlController_HandleTrainerSlide(gActiveBattler, TRAINER_BACK_PIC_WALLY);
}

#undef sSpeedX

static void WallyHandleSuccessBallThrowAnim(void)
{
    BtlController_HandleSuccessBallThrowAnim(gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER, FALSE);
}

static void WallyHandleBallThrowAnim(void)
{
    BtlController_HandleBallThrowAnim(gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER, FALSE);
}

static void WallyHandleMoveAnimation(void)
{
    BtlController_HandleMoveAnimation(gActiveBattler, FALSE);
}

static void WallyHandlePrintString(void)
{
    BtlController_HandlePrintString(gActiveBattler, FALSE, FALSE);
}

static void WallyHandlePrintSelectionString(void)
{
    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        WallyHandlePrintString();
    else
        WallyBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[gActiveBattler] = WallyHandleActions;
    }
}

static void WallyHandleChooseAction(void)
{
    s32 i;

    gBattlerControllerFuncs[gActiveBattler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBattler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillWallyDo);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void WallyHandleChooseMove(void)
{
    switch (gBattleStruct->wallyMovesState)
    {
    case 0:
        InitMoveSelectionsVarsAndStrings();
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
            BtlController_EmitTwoReturnValues(BUFFER_B, 10, 0x100);
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void WallyHandleChooseItem(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[gActiveBattler] = OpenBagAfterPaletteFade;
    gBattlerInMenuId = gActiveBattler;
}

static void WallyHandleHealthBarUpdate(void)
{
    BtlController_HandleHealthBarUpdate(gActiveBattler, TRUE);
}

// For some reason Wally's SE don't take side into account and pan is always the same. Possibly a bug
static void WallyHandlePlaySE(void)
{
    PlaySE(gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8));
    WallyBufferExecCompleted();
}

// All of the other controllers use CRY_MODE_FAINT.
// Wally's Pokémon during the tutorial is never intended to faint, so that's probably why it's different here.
static void WallyHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    WallyBufferExecCompleted();
}

static void WallyHandleIntroTrainerBallThrow(void)
{
    const u32 *trainerPal = gTrainerBackPicPaletteTable[TRAINER_BACK_PIC_WALLY].data;
    BtlController_HandleIntroTrainerBallThrow(gActiveBattler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

static void WallyHandleDrawPartyStatusSummary(void)
{
    BtlController_HandleDrawPartyStatusSummary(gActiveBattler, B_SIDE_PLAYER, FALSE);
}

static void WallyHandleBattleAnimation(void)
{
    BtlController_HandleBattleAnimation(gActiveBattler, TRUE, FALSE);
}

static void WallyHandleEndLinkBattle(void)
{
    gBattleOutcome = gBattleResources->bufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    WallyBufferExecCompleted();

    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[gActiveBattler] = SetBattleEndCallbacks;
}
