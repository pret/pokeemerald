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
#include "party_menu.h"
#include "pokeball.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "trainer.h"
#include "util.h"
#include "window.h"
#include "line_break.h"
#include "constants/battle_anim.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

static void SafariHandleDrawTrainerPic(enum BattlerId battler);
static void SafariHandleChooseAction(enum BattlerId battler);
static void SafariHandleChooseItem(enum BattlerId battler);
static void SafariHandleChoosePokemon(enum BattlerId battler);
static void SafariHandleFaintingCry(enum BattlerId battler);
static void SafariHandleIntroTrainerBallThrow(enum BattlerId battler);
static void SafariHandleEndLinkBattle(enum BattlerId battler);

static void SafariBufferRunCommand(enum BattlerId battler);
static void CompleteWhenChosePokeblock(enum BattlerId battler);
static void WaitForMonSelection(enum BattlerId battler);

static void (*const sSafariBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_Empty,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_Empty,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_Empty,
    [CONTROLLER_SWITCHINANIM]             = BtlController_Empty,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_Empty,
    [CONTROLLER_DRAWTRAINERPIC]           = SafariHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_Empty,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_HandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_Empty,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_HandlePrintStringPlayerOnly,
    [CONTROLLER_CHOOSEACTION]             = SafariHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = BtlController_Empty,
    [CONTROLLER_OPENBAG]                  = SafariHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = SafariHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_Empty,
    [CONTROLLER_EXPUPDATE]                = BtlController_Empty,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
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
    [CONTROLLER_HITANIMATION]             = BtlController_Empty,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = SafariHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = SafariHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = SafariHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToSafari(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_SAFARI;
    gBattlerControllerEndFuncs[battler] = SafariBufferExecCompleted;
    gBattlerControllerFuncs[battler] = SafariBufferRunCommand;
}

static void SafariBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sSafariBufferCommands))
            sSafariBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void HandleInputChooseAction(enum BattlerId battler)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[battler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SAFARI_BALL, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SAFARI_POKEBLOCK, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SAFARI_GO_NEAR, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SAFARI_RUN, 0);
            break;
        }
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[battler] & 1))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[battler] & 2)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[battler] & 2))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (B_QUICK_MOVE_CURSOR_TO_RUN && JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
        gActionSelectionCursor[battler] = 3;
        ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    }
}

static void Controller_WaitForHealthbox(enum BattlerId battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        BtlController_Complete(battler);
}

static void SafariSetBattleEndCallbacks(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

static void SafariOpenPokeblockCase(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChosePokeblock;
        CloseMainBattleScreen();
        OpenPokeblockCaseInBattle();
    }
}

static void CompleteWhenChosePokeblock(enum BattlerId battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        BtlController_Complete(battler);
    }
}

static void OpenPartyMenuToChooseMon(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        u8 caseId = gTasks[gBattleControllerData[battler]].data[0];
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
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, PARTY_SIZE, NULL);

        if ((gBattleResources->bufferA[battler][1] & 0xF) == 1)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                BattlePutTextOnWindow(gText_LinkStandby, B_WIN_MSG);
            }
        }

        SafariBufferExecCompleted(battler);
    }
}

void SafariBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = SafariBufferRunCommand;
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

static void SafariHandleDrawTrainerPic(enum BattlerId battler)
{
    enum TrainerPicID trainerPicId = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, FALSE,
                                       80, 80 + 4 * (8 - GetTrainerBackPicCoords(trainerPicId)->size),
                                       30);
}

static void HandleChooseActionAfterDma3(enum BattlerId battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
    }
}

static void SafariHandleChooseAction(enum BattlerId battler)
{
    s32 i;

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattlePutTextOnWindow(IS_FRLG ? gText_SafariZoneMenuFrlg : gText_SafariZoneMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo2);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void SafariHandleChooseItem(enum BattlerId battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = SafariOpenPokeblockCase;
    gBattlerInMenuId = battler;
}

static void SafariHandleChoosePokemon(enum BattlerId battler)
{
    for (s32 i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CANT_SWITCH
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CHOOSE_FAINTED_MON
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_SEND_MON_TO_BOX)
    {
        BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattlerPartyIndexes[battler] + 1, gBattlePartyCurrentOrder);
        SafariBufferExecCompleted(battler);
    }
    else
    {
        gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
        gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1] & 0xF;
        *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][1] >> 4;
        *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
        *(&gBattleStruct->abilityPreventingSwitchout) = (gBattleResources->bufferA[battler][3] & 0xFF) | (gBattleResources->bufferA[battler][7] << 8);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
        gBattlerInMenuId = battler;
    }
}

// All of the other controllers(except Wally's) use CRY_MODE_FAINT.
// Player is not a Pokémon, so it can't really faint in the Safari anyway.
static void SafariHandleFaintingCry(enum BattlerId battler)
{
    enum Species species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    BtlController_Complete(battler);
    BtlController_Complete(battler);
}

static void SafariHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_SAFARI_ALL_TEXT);
    StartHealthboxSlideIn(battler);
    SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
    gBattlerControllerFuncs[battler] = Controller_WaitForHealthbox;
}

static void SafariHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && !(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
        gBattlerControllerFuncs[battler] = SafariSetBattleEndCallbacks;
}
