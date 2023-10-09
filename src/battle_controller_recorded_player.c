#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "bg.h"
#include "data.h"
#include "item_menu.h"
#include "item_use.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "recorded_battle.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"
#include "constants/trainers.h"

static void RecordedPlayerHandleLoadMonSprite(u32 battler);
static void RecordedPlayerHandleSwitchInAnim(u32 battler);
static void RecordedPlayerHandleDrawTrainerPic(u32 battler);
static void RecordedPlayerHandleTrainerSlideBack(u32 battler);
static void RecordedPlayerHandleMoveAnimation(u32 battler);
static void RecordedPlayerHandlePrintString(u32 battler);
static void RecordedPlayerHandleChooseAction(u32 battler);
static void RecordedPlayerHandleChooseMove(u32 battler);
static void RecordedPlayerHandleChooseItem(u32 battler);
static void RecordedPlayerHandleChoosePokemon(u32 battler);
static void RecordedPlayerHandleHealthBarUpdate(u32 battler);
static void RecordedPlayerHandleStatusIconUpdate(u32 battler);
static void RecordedPlayerHandleStatusAnimation(u32 battler);
static void RecordedPlayerHandleIntroTrainerBallThrow(u32 battler);
static void RecordedPlayerHandleDrawPartyStatusSummary(u32 battler);
static void RecordedPlayerHandleBattleAnimation(u32 battler);
static void RecordedPlayerHandleEndLinkBattle(u32 battler);

static void RecordedPlayerBufferRunCommand(u32 battler);
static void RecordedPlayerBufferExecCompleted(u32 battler);
static void SwitchIn_WaitAndEnd(u32 battler);

static void (*const sRecordedPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = RecordedPlayerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = RecordedPlayerHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = RecordedPlayerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = RecordedPlayerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = PlayerHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = RecordedPlayerHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = RecordedPlayerHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = RecordedPlayerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = RecordedPlayerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = RecordedPlayerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = RecordedPlayerHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = RecordedPlayerHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = RecordedPlayerHandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = RecordedPlayerHandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = BtlController_Empty,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BtlController_Empty,
    [CONTROLLER_PLAYBGM]                  = BtlController_Empty,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BtlController_Empty,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BtlController_Empty,
    [CONTROLLER_CLEARUNKVAR]              = BtlController_HandleClearUnkVar,
    [CONTROLLER_SETUNKVAR]                = BtlController_HandleSetUnkVar,
    [CONTROLLER_CLEARUNKFLAG]             = BtlController_HandleClearUnkFlag,
    [CONTROLLER_TOGGLEUNKFLAG]            = BtlController_HandleToggleUnkFlag,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = RecordedPlayerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = RecordedPlayerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = RecordedPlayerHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = RecordedPlayerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToRecordedPlayer(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = RecordedPlayerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = RecordedPlayerBufferRunCommand;
}

static void RecordedPlayerBufferRunCommand(u32 battler)
{
    if (gBattleControllerExecFlags & gBitTable[battler])
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sRecordedPlayerBufferCommands))
            sRecordedPlayerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            RecordedPlayerBufferExecCompleted(battler);
    }
}

static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        RecordedPlayerBufferExecCompleted(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool32 healthboxAnimDone = FALSE;

    if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
    {
        if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
        {
            if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
                healthboxAnimDone = TRUE;
        }
        else
        {
            if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
                && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
            && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim = FALSE;

            FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
            FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

            HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
            if (IsDoubleBattle())
                HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], BATTLE_PARTNER(battler));

            gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
            gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
        }
    }
    else
    {
        if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
        {
            if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
                healthboxAnimDone = TRUE;
        }
        else
        {
            if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
                && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (IsCryPlayingOrClearCrySongs())
            healthboxAnimDone = FALSE;

        if (healthboxAnimDone)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
            gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;

    if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
            TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);

        if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
            TryShinyAnimation(BATTLE_PARTNER(battler), &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]);
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], HEALTHBOX_ALL);
                StartHealthboxSlideIn(BATTLE_PARTNER(battler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && (gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
                    m4aMPlayContinue(&gMPlayInfo_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            }

        }
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    if (bgmRestored && gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);

        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;
        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void WaitForMonAnimAfterLoad(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].animEnded && gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        RecordedPlayerBufferExecCompleted(battler);
}

static void SwitchIn_ShowSubstitute(u32 battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(battler);
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[battler] = SwitchIn_WaitAndEnd;
    }
}

static void SwitchIn_WaitAndEnd(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        RecordedPlayerBufferExecCompleted(battler);
    }
}

static void SwitchIn_ShowHealthbox(u32 battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        gBattlerControllerFuncs[battler] = SwitchIn_ShowSubstitute;
    }
}

static void SwitchIn_TryShinyAnim(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);
    }

    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        gBattlerControllerFuncs[battler] = SwitchIn_ShowHealthbox;
    }
}

static void RecordedPlayerBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = RecordedPlayerBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, 2, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[battler];
    }
}

static void RecordedPlayerHandleLoadMonSprite(u32 battler)
{
    BtlController_HandleLoadMonSprite(battler, WaitForMonAnimAfterLoad);
}

static void RecordedPlayerHandleSwitchInAnim(u32 battler)
{
    BtlController_HandleSwitchInAnim(battler, TRUE, SwitchIn_TryShinyAnim);
}

static void RecordedPlayerHandleDrawTrainerPic(u32 battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            trainerPicId = GetBattlerLinkPlayerGender(battler);
        else
            trainerPicId = gLinkPlayers[gRecordedBattleMultiplayerId].gender;
    }
    else
    {
        trainerPicId = gLinkPlayers[0].gender;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBattlerPosition(battler) & BIT_FLANK) != 0) // second mon
            xPos = 90;
        else // first mon
            xPos = 32;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            xPos = 90;
            yPos = (8 - gTrainerFrontPicCoords[trainerPicId].size) * 4 + 80;
        }
        else
        {
            yPos = (8 - gTrainerBackPicCoords[trainerPicId].size) * 4 + 80;
        }

    }
    else
    {
        xPos = 80;
        yPos = (8 - gTrainerBackPicCoords[trainerPicId].size) * 4 + 80;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        isFrontPic = TRUE;
    else
        isFrontPic = FALSE;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void RecordedPlayerHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void RecordedPlayerHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler, FALSE);
}

static void RecordedPlayerHandlePrintString(u32 battler)
{
    BtlController_HandlePrintString(battler, FALSE, FALSE);
}

static void ChooseActionInBattlePalace(u32 battler)
{
    if (gBattleCommunication[4] >= gBattlersCount / 2)
    {
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, RecordedBattle_GetBattlerAction(RECORDED_BATTLE_PALACE_ACTION, battler), 0);
        RecordedPlayerBufferExecCompleted(battler);
    }
}

static void RecordedPlayerHandleChooseAction(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gBattlerControllerFuncs[battler] = ChooseActionInBattlePalace;
    }
    else
    {
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, RecordedBattle_GetBattlerAction(RECORDED_ACTION_TYPE, battler), 0);
        RecordedPlayerBufferExecCompleted(battler);
    }
}

static void RecordedPlayerHandleChooseMove(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, ChooseMoveAndTargetInBattlePalace(battler));
    }
    else
    {
        u8 moveId = RecordedBattle_GetBattlerAction(RECORDED_MOVE_SLOT, battler);
        u8 target = RecordedBattle_GetBattlerAction(RECORDED_MOVE_TARGET, battler);
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, moveId | (target << 8));
    }

    RecordedPlayerBufferExecCompleted(battler);
}

static void RecordedPlayerHandleChooseItem(u32 battler)
{
    u8 byte1 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, battler);
    u8 byte2 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, battler);
    gBattleStruct->chosenItem[battler] = (byte1 << 8) | byte2;
    gBattleStruct->itemPartyIndex[battler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_TARGET, battler);
    gBattleStruct->itemMoveIndex[battler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_MOVE, battler);
    BtlController_EmitOneReturnValue(battler, BUFFER_B, gBattleStruct->chosenItem[battler]);
    RecordedPlayerBufferExecCompleted(battler);
}

static void RecordedPlayerHandleChoosePokemon(u32 battler)
{
    *(gBattleStruct->monToSwitchIntoId + battler) = RecordedBattle_GetBattlerAction(RECORDED_PARTY_INDEX, battler);
    gSelectedMonPartyId = gBattleStruct->monToSwitchIntoId[battler]; // Revival Blessing
    BtlController_EmitChosenMonReturnValue(battler, BUFFER_B, *(gBattleStruct->monToSwitchIntoId + battler), NULL);
    RecordedPlayerBufferExecCompleted(battler);
}

static void RecordedPlayerHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler, TRUE);
}

static void RecordedPlayerHandleStatusIconUpdate(u32 battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        DoStatusIconUpdate(battler);
        if (gTestRunnerEnabled)
            TestRunner_Battle_RecordStatus1(battler, GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_STATUS));
    }
}

static void RecordedPlayerHandleStatusAnimation(u32 battler)
{
    BtlController_HandleStatusAnimation(battler);
}

static void RecordedPlayerHandleIntroTrainerBallThrow(u32 battler)
{
    u32 trainerPicId;
    const u32 *trainerPal;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(battler)].gender + TRAINER_BACK_PIC_BRENDAN;
    else
        trainerPicId = gSaveBlock2Ptr->playerGender + TRAINER_BACK_PIC_BRENDAN;

    trainerPal = gTrainerFrontPicPaletteTable[trainerPicId].data;
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F9, trainerPal, 24, Intro_TryShinyAnimShowHealthbox);
}

static void RecordedPlayerHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void RecordedPlayerHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, FALSE, FALSE);
}

static void RecordedPlayerHandleEndLinkBattle(u32 battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    RecordedPlayerBufferExecCompleted(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
