#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "bg.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trainer.h"
#include "util.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void OakOldManHandleDrawTrainerPic(enum BattlerId battler);
static void OakOldManHandleTrainerSlide(enum BattlerId battler);
static void OakOldManHandlePrintString(enum BattlerId battler);
static void OakOldManHandlePrintSelectionString(enum BattlerId battler);
static void OakOldManHandleChooseAction(enum BattlerId battler);
static void OakOldManHandleChooseMove(enum BattlerId battler);
static void OakOldManHandleChooseItem(enum BattlerId battler);
static void OakOldManHandleChoosePokemon(enum BattlerId battler);
static void OakOldManHandlePlaySE(enum BattlerId battler);
static void OakOldManHandleFaintingCry(enum BattlerId battler);
static void OakOldManHandleIntroTrainerBallThrow(enum BattlerId battler);
static void OakOldManHandleDrawPartyStatusSummary(enum BattlerId battler);
static void OakOldManHandleEndBounceEffect(enum BattlerId battler);
static void OakOldManHandleLinkStandbyMsg(enum BattlerId battler);
static void OakOldManHandleEndLinkBattle(enum BattlerId battler);

static void OakOldManBufferRunCommand(enum BattlerId battler);
static void WaitForMonSelection(enum BattlerId battler);
static void CompleteWhenChoseItem(enum BattlerId battler);
static void PrintOakText_KeepAnEyeOnHP(enum BattlerId battler);
static void Intro_WaitForShinyAnimAndHealthbox(enum BattlerId battler);
static void PrintOakText_ForPetesSake(enum BattlerId battler);
static void PrintOakTextWithMainBgDarkened(enum BattlerId battler, const u8 *text, u8 delay);
static void HandleInputChooseAction(enum BattlerId battler);

static const u8 sText_ForPetesSake[] = _("OAK: Oh, for Pete's sake…\nSo pushy, as always.\p{B_PLAYER_NAME}.\pYou've never had a POKéMON battle\nbefore, have you?\pA POKéMON battle is when TRAINERS\npit their POKéMON against each\lother.\p");
static const u8 sText_HowDissapointing[] = _("OAK: Hm…\nHow disappointing…\pIf you win, you earn prize money,\nand your POKéMON grow.\pBut if you lose, {B_PLAYER_NAME}, you end\nup paying prize money…\pHowever, since you had no warning\nthis time, I'll pay for you.\pBut things won't be this way once\nyou step outside these doors.\pThat's why you must strengthen your\nPOKéMON by battling wild POKéMON.\p");
static const u8 sText_InflictingDamageIsKey[] = _("OAK: Inflicting damage on the foe\nis the key to any battle.\p");
static const u8 sText_KeepAnEyeOnHP[] = _("OAK: Keep your eyes on your\nPOKéMON's HP.\pIt will faint if the HP drops to\n“0.”\p");
static const u8 sText_LoweringStats[] = _("OAK: Lowering the foe's stats\nwill put you at an advantage.\p");
static const u8 sText_OakNoRunningFromATrainer[] = _("OAK: No! There's no running away\nfrom a TRAINER POKéMON battle!\p");
static const u8 sText_TheTrainerThat[] = _("The TRAINER that makes the other\nTRAINER's POKéMON faint by lowering\ltheir HP to “0,” wins.\p");
static const u8 sText_TryBattling[] = _("But rather than talking about it,\nyou'll learn more from experience.\pTry battling and see for yourself.\p");
static const u8 sText_WinEarnsPrizeMoney[] = _("OAK: Hm! Excellent!\pIf you win, you earn prize money,\nand your POKéMON will grow!\pBattle other TRAINERS and make\nyour POKéMON strong!\p");
static const u8 gText_WhatWillOldManDo[] = _("What will the\nold man do?");

static void (*const sOakOldManBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_Empty,
    [CONTROLLER_SWITCHINANIM]             = BtlController_Empty,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = OakOldManHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = OakOldManHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_HandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = OakOldManHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = OakOldManHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = OakOldManHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = OakOldManHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = OakOldManHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = OakOldManHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_HandleStatusAnimation,
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
    [CONTROLLER_PLAYSE]                   = OakOldManHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = OakOldManHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = OakOldManHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = OakOldManHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = OakOldManHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = OakOldManHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = OakOldManHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop,
};

#define simulatedInputState0 wallyBattleState
#define simulatedInputState1 wallyMovesState
#define simulatedInputState2 wallyWaitFrames
#define simulatedInputState3 wallyMoveFrames

void SetControllerToOakOrOldMan(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_OAK_OLD_MAN;
    gBattlerControllerEndFuncs[battler] = OakOldManBufferExecCompleted;
    gBattlerControllerFuncs[battler] = OakOldManBufferRunCommand;
    gBattleStruct->simulatedInputState0 = 0;
    gBattleStruct->simulatedInputState1 = 0;
    gBattleStruct->simulatedInputState2 = 0;
    gBattleStruct->simulatedInputState3 = 0;
}

static void OakOldManBufferRunCommand(enum BattlerId battler)
{
    if (gBattleControllerExecFlags & (1u << battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sOakOldManBufferCommands))
            sOakOldManBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            OakOldManBufferExecCompleted(battler);
    }
}

static void HandleInputChooseAction(enum BattlerId battler)
{
    // Like player, but specifically for Rival in Oak's Lab
    enum Item itemId = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);

    DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
    DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[battler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_MOVE, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_ITEM, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_RUN, 0);
            break;
        }
        OakOldManBufferExecCompleted(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1) // if is B_ACTION_USE_ITEM or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[battler] & 1)) // if is B_ACTION_USE_MOVE or B_ACTION_SWITCH
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[battler] & 2) // if is B_ACTION_SWITCH or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[battler] & 2)) // if is B_ACTION_USE_MOVE or B_ACTION_USE_ITEM
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
         && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT
         && !(gAbsentBattlerFlags & (1 << GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
         && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleResources->bufferA[battler][1] == B_ACTION_USE_ITEM)
            {
                // Add item to bag if it is a ball
                if (GetItemPocket(itemId) == POCKET_POKE_BALLS)
                    AddBagItem(itemId, 1);
                else
                    return;
            }
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_CANCEL_PARTNER, 0);
            OakOldManBufferExecCompleted(battler);
        }
    }
    else if (JOY_NEW(START_BUTTON))
    {
        SwapHpBarsWithHpText();
    }
}

static void SimulateInputChooseAction(enum BattlerId battler)
{
    // Old Man
    switch (gBattleStruct->simulatedInputState0)
    {
    case 0:
        gBattleStruct->simulatedInputState2 = 64;
        ++gBattleStruct->simulatedInputState0;
        // fall through
    case 1:
        if (--gBattleStruct->simulatedInputState2 == 0)
        {
            // Move cursor to BAG
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(0);
            ActionSelectionCreateCursorAt(1, 0);
            gBattleStruct->simulatedInputState2 = 64;
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 2:
        if (--gBattleStruct->simulatedInputState2 == 0)
        {
            // Open bag
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_USE_ITEM, 0);
            OakOldManBufferExecCompleted(battler);
        }
        break;
    }
}

static void CompleteOnInactiveTextPrinter(enum BattlerId battler)
{
    if (!IsTextPrinterActiveOnWindow(0))
        OakOldManBufferExecCompleted(battler);
}

static void OakOldManSetBattleEndCallbacks(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

void OakOldManHandleInputChooseMove(enum BattlerId battler)
{
    HandleInputChooseMove(battler);
    if (!(gBattleControllerExecFlags & (1u << battler)))
        OakOldManBufferExecCompleted(battler);
}

static void OpenPartyMenuToChooseMon(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        u8 caseId;

        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        caseId = gTasks[gBattleControllerData[battler]].data[0];
        DestroyTask(gBattleControllerData[battler]);
        CloseMainBattleScreen();
        OpenPartyMenuInBattle(caseId);
    }
}

static void WaitForMonSelection(enum BattlerId battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gPartyMenuUseExitCallback == TRUE)
            BtlController_EmitChosenMonReturnValue(battler, 1, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            BtlController_EmitChosenMonReturnValue(battler, 1, 6, NULL);
        OakOldManBufferExecCompleted(battler);
    }
}

static void OpenBagAndChooseItem(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChoseItem;
        ReshowBattleScreenDummy();
        CloseMainBattleScreen();
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
            CB2_BagMenuFromBattle();
        else
            InitOldManBag();
    }
}

static void CompleteWhenChoseItem(enum BattlerId battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (IS_FRLG && !BtlCtrl_OakOldMan_TestState2Flag(FIRST_BATTLE_MSG_FLAG_HP_RESTORE)
         && gSpecialVar_ItemId == ITEM_POTION
         && gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        {
            BtlCtrl_OakOldMan_SetState2Flag(FIRST_BATTLE_MSG_FLAG_HP_RESTORE);
            gBattlerControllerFuncs[battler] = PrintOakText_KeepAnEyeOnHP;
        }
        else
        {
            BtlController_EmitOneReturnValue(battler, 1, gSpecialVar_ItemId);
            OakOldManBufferExecCompleted(battler);
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(enum BattlerId battler)
{
    struct Pokemon *party = GetBattlerParty(battler);

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, &party[gBattlerPartyIndexes[battler]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive)
        TryShinyAnimation(GetPartnerBattler(battler), &party[gBattlerPartyIndexes[GetPartnerBattler(battler)]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[GetPartnerBattler(battler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[GetPartnerBattler(battler)],
                                     &party[gBattlerPartyIndexes[GetPartnerBattler(battler)]],
                                     HEALTHBOX_ALL);
            StartHealthboxSlideIn(GetPartnerBattler(battler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[GetPartnerBattler(battler)]);
        }
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler],
                                 &party[gBattlerPartyIndexes[battler]],
                                 HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(enum BattlerId battler)
{
    bool32 r4 = FALSE;
    struct Pokemon *party = GetBattlerParty(battler);

    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        r4 = TRUE;
    if (r4
     && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(&party[gBattlerPartyIndexes[battler]], battler);
        gBattlerControllerFuncs[battler] = PrintOakText_ForPetesSake;
    }
}

static void PrintOakText_ForPetesSake(enum BattlerId battler)
{
    u32 mask;

    switch (gBattleStruct->simulatedInputState0)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            LoadHealthboxPalsForLevelUp(&gBattleStruct->simulatedInputState1, &gBattleStruct->simulatedInputState3, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 2:
        BattleStringExpandPlaceholdersToDisplayedString(sText_ForPetesSake);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_OLD_MAN);
        ++gBattleStruct->simulatedInputState0;
        break;
    case 3:
        if (!IsTextPrinterActiveOnWindow(B_WIN_OAK_OLD_MAN))
        {
            mask = ((1 << gBattleStruct->simulatedInputState1) | (1 << gBattleStruct->simulatedInputState3)) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            BattleStringExpandPlaceholdersToDisplayedString(sText_TheTrainerThat);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_OLD_MAN);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 5:
        if (!IsTextPrinterActiveOnWindow(B_WIN_OAK_OLD_MAN))
        {
            mask = ((1 << gBattleStruct->simulatedInputState1) | (1 << gBattleStruct->simulatedInputState3)) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            BattleStringExpandPlaceholdersToDisplayedString(sText_TryBattling);
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_OLD_MAN);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 7:
        if (!IsTextPrinterActiveOnWindow(B_WIN_OAK_OLD_MAN))
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 8:
        if (!gPaletteFade.active)
        {
            FreeHealthboxPalsForLevelUp(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
            BtlCtrl_RemoveVoiceoverMessageFrame();
            gBattleStruct->simulatedInputState0 = 0;
            OakOldManBufferExecCompleted(battler);
        }
        break;
    }
}

void PrintOakText_InflictingDamageIsKey(enum BattlerId battler)
{
    PrintOakTextWithMainBgDarkened(battler, sText_InflictingDamageIsKey, 1);
}

static void PrintOakText_LoweringStats(enum BattlerId battler)
{
    PrintOakTextWithMainBgDarkened(battler, sText_LoweringStats, 64);
}

void PrintOakText_OakNoRunningFromATrainer(enum BattlerId battler)
{
    PrintOakTextWithMainBgDarkened(battler, sText_OakNoRunningFromATrainer, 1);
}

static void PrintOakText_WinEarnsPrizeMoney(enum BattlerId battler)
{
    PrintOakTextWithMainBgDarkened(battler, sText_WinEarnsPrizeMoney, 64);
}

void PrintOakText_HowDisappointing(enum BattlerId battler)
{
    PrintOakTextWithMainBgDarkened(battler, sText_HowDissapointing, 64);
}

static void PrintOakTextWithMainBgDarkened(enum BattlerId battler, const u8 *text, u8 delay)
{
    // If delay is 0, it's treated as 256.
    switch (gBattleStruct->simulatedInputState0)
    {
    case 0:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            gBattleStruct->simulatedInputState3 = delay;
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 1:
        if (--gBattleStruct->simulatedInputState3 == 0)
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 3:
        BattleStringExpandPlaceholdersToDisplayedString(text);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_OLD_MAN);
        ++gBattleStruct->simulatedInputState0;
        break;
    case 4:
        if (!IsTextPrinterActiveOnWindow(B_WIN_OAK_OLD_MAN))
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            BtlCtrl_RemoveVoiceoverMessageFrame();
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                OakOldManBufferExecCompleted(battler);
            else
                OpponentBufferExecCompleted(battler);
            gBattleCommunication[MSG_DISPLAY] = MSG_DISPLAY_CONTINUE;
            gBattleStruct->simulatedInputState0 = 0;
        }
        break;
    }
}

static void PrintOakText_KeepAnEyeOnHP(enum BattlerId battler)
{
    u32 mask;

    switch (gBattleStruct->simulatedInputState0)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            LoadHealthboxPalsForLevelUp(&gBattleStruct->simulatedInputState1, &gBattleStruct->simulatedInputState3, battler);
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            mask = ((1 << gBattleStruct->simulatedInputState1) | (1 << gBattleStruct->simulatedInputState3)) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            BtlCtrl_DrawVoiceoverMessageFrame();
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 3:
        BattleStringExpandPlaceholdersToDisplayedString(sText_KeepAnEyeOnHP);
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_OAK_OLD_MAN);
        ++gBattleStruct->simulatedInputState0;
        break;
    case 4:
        if (!IsTextPrinterActiveOnWindow(B_WIN_OAK_OLD_MAN))
        {
            mask = ((1 << gBattleStruct->simulatedInputState1) | (1 << gBattleStruct->simulatedInputState3)) << 16;
            BeginNormalPaletteFade(mask,
                                   4,
                                   0,
                                   8,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0xFFFFFF7E,
                                   4,
                                   8,
                                   0,
                                   RGB_BLACK);
            ++gBattleStruct->simulatedInputState0;
        }
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            BtlCtrl_RemoveVoiceoverMessageFrame();
            BtlController_EmitOneReturnValue(battler, 1, gSpecialVar_ItemId);
            OakOldManBufferExecCompleted(battler);
            gBattleStruct->simulatedInputState0 = 0;
        }
        break;
    }
}

void OakOldManBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = OakOldManBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, 2, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~(1u << battler);
    }
}

static void OakOldManHandleDrawTrainerPic(enum BattlerId battler)
{
    enum TrainerPicID trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        trainerPicId = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);
    else
        trainerPicId = TRAINER_PIC_OLD_MAN;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, FALSE, 80, (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80, 30);
}

static void OakOldManHandleTrainerSlide(enum BattlerId battler)
{
    enum TrainerPicID trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        trainerPicId = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);
    else
        trainerPicId = TRAINER_PIC_OLD_MAN;

    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void OakOldManHandlePrintString(enum BattlerId battler)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16 *)(&gBattleResources->bufferA[battler][2]);
    if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL && *stringId == 1)
    {
        OakOldManBufferExecCompleted(battler);
    }
    else
    {
        BufferStringBattle(*stringId, battler);
        // if (BattleStringShouldBeColored(*stringId))
        //     BattlePutTextOnWindow(gDisplayedStringBattle, (B_WIN_MSG | B_TEXT_FLAG_NPC_CONTEXT_FONT));
        // else
            BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        {
            switch (*stringId)
            {
            case STRINGID_STATFELL:
                if (gBattlerTarget == battler && IS_FRLG && !BtlCtrl_OakOldMan_TestState2Flag(FIRST_BATTLE_MSG_FLAG_STAT_CHG))
                {
                    BtlCtrl_OakOldMan_SetState2Flag(FIRST_BATTLE_MSG_FLAG_STAT_CHG);
                    gBattlerControllerFuncs[battler] = PrintOakText_LoweringStats;
                    return;
                }
                break;
            case STRINGID_PLAYERGOTMONEY:
                gBattlerControllerFuncs[battler] = PrintOakText_WinEarnsPrizeMoney;
                return;
            case STRINGID_TRAINER1WINTEXT:
                gBattlerControllerFuncs[battler] = PrintOakText_HowDisappointing;
                return;
            case STRINGID_DONTLEAVEBIRCH:
                gBattlerControllerFuncs[battler] = PrintOakText_OakNoRunningFromATrainer;
                return;
            }
        }
        gBattlerControllerFuncs[battler] = CompleteOnInactiveTextPrinter;
    }
}

static void OakOldManHandlePrintSelectionString(enum BattlerId battler)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        OakOldManHandlePrintString(battler);
    else
        OakOldManBufferExecCompleted(battler);
}

static void HandleChooseActionAfterDma3(enum BattlerId battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
            gBattlerControllerFuncs[battler] = HandleInputChooseAction;
        else
            gBattlerControllerFuncs[battler] = SimulateInputChooseAction;
    }
}

static void OakOldManHandleChooseAction(enum BattlerId battler)
{
    s32 i;

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(gText_EmptyString3, B_WIN_MSG);
    BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);
    for (i = 0; i < MAX_MON_MOVES; ++i)
        ActionSelectionDestroyCursorAt((u8)i);
    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo);
    }
    else
        BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillOldManDo);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void OakHandleChooseMove_WaitDma3(enum BattlerId battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 320;
        gBattlerControllerFuncs[battler] = OakOldManHandleInputChooseMove;
    }
}

static void OakOldManHandleChooseMove(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        InitMoveSelectionsVarsAndStrings(battler);
        gBattlerControllerFuncs[battler] = OakHandleChooseMove_WaitDma3;
    }
    else
    {
        switch (gBattleStruct->simulatedInputState1)
        {
        case 0:
            InitMoveSelectionsVarsAndStrings(battler);
            ++gBattleStruct->simulatedInputState1;
            gBattleStruct->simulatedInputState3 = 80;
            // fall through
        case 1:
            if (--gBattleStruct->simulatedInputState3 == 0)
            {
                PlaySE(SE_SELECT);
                BtlController_EmitTwoReturnValues(battler, 1, 10, 0x100);
                OakOldManBufferExecCompleted(battler);
            }
            break;
        }
    }
}

static void OakOldManHandleChooseItem(enum BattlerId battler)
{
    s32 i;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenBagAndChooseItem;
    gBattlerInMenuId = battler;
    for (i = 0; i < 3; ++i)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][i + 1];
}

static void OakOldManHandleChoosePokemon(enum BattlerId battler)
{
    s32 i;

    gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
    gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1];
    *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][8];
    *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
    *(&gBattleStruct->abilityPreventingSwitchout) = (gBattleResources->bufferA[battler][3] & 0xFF) | (gBattleResources->bufferA[battler][7] << 8);
    for (i = 0; i < 3; ++i)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
    gBattlerInMenuId = battler;
}

static void OakOldManHandlePlaySE(enum BattlerId battler)
{
    PlaySE(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleFaintingCry(enum BattlerId battler)
{
    struct Pokemon *party = GetBattlerParty(battler);
    enum Species species = GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        enum TrainerPicID trainerPicID = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);
        const u16 *trainerPal = GetTrainerBackPicPalette(trainerPicID);
        BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
    }
    else
    {
        if (gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown)
            gTasks[gBattlerStatusSummaryTaskId[battler]].func = Task_HidePartyStatusSummary;
        OakOldManBufferExecCompleted(battler);
    }
}

static void OakOldManHandleDrawPartyStatusSummary(enum BattlerId battler)
{
    if (gBattleResources->bufferA[battler][1] != 0
     && GetBattlerSide(battler) == B_SIDE_PLAYER)
    {
        OakOldManBufferExecCompleted(battler);
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown = TRUE;
        gBattlerStatusSummaryTaskId[battler] = CreatePartyStatusSummarySprites(battler,
                                                                                      (struct HpAndStatus *)&gBattleResources->bufferA[battler][4],
                                                                                      gBattleResources->bufferA[battler][1],
                                                                                      gBattleResources->bufferA[battler][2]);
        OakOldManBufferExecCompleted(battler);
    }
}

static void OakOldManHandleEndBounceEffect(enum BattlerId battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleLinkStandbyMsg(enum BattlerId battler)
{
    switch (gBattleResources->bufferA[battler][1])
    {
    case LINK_STANDBY_MSG_STOP_BOUNCE:
    case LINK_STANDBY_STOP_BOUNCE_ONLY:
        EndBounceEffect(battler, BOUNCE_HEALTHBOX);
        EndBounceEffect(battler, BOUNCE_MON);
        break;
    case LINK_STANDBY_MSG_ONLY:
        break;
    }
    OakOldManBufferExecCompleted(battler);
}

static void OakOldManHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    OakOldManBufferExecCompleted(battler);
    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[battler] = OakOldManSetBattleEndCallbacks;
}

bool8 BtlCtrl_OakOldMan_TestState2Flag(u8 mask)
{
    return gBattleStruct->simulatedInputState2 & mask;
}

void BtlCtrl_OakOldMan_SetState2Flag(u8 mask)
{
    gBattleStruct->simulatedInputState2 |= mask;
}

// uses values for emerald frames
void BtlCtrl_DrawVoiceoverMessageFrame(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

// uses values for emerald frames
void BtlCtrl_RemoveVoiceoverMessageFrame(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}
