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

static void RecordedPlayerHandleGetMonData(void);
static void RecordedPlayerHandleGetRawMonData(void);
static void RecordedPlayerHandleSetMonData(void);
static void RecordedPlayerHandleSetRawMonData(void);
static void RecordedPlayerHandleLoadMonSprite(void);
static void RecordedPlayerHandleSwitchInAnim(void);
static void RecordedPlayerHandleReturnMonToBall(void);
static void RecordedPlayerHandleDrawTrainerPic(void);
static void RecordedPlayerHandleTrainerSlide(void);
static void RecordedPlayerHandleTrainerSlideBack(void);
static void RecordedPlayerHandleFaintAnimation(void);
static void RecordedPlayerHandlePaletteFade(void);
static void RecordedPlayerHandleSuccessBallThrowAnim(void);
static void RecordedPlayerHandleBallThrowAnim(void);
static void RecordedPlayerHandlePause(void);
static void RecordedPlayerHandleMoveAnimation(void);
static void RecordedPlayerHandlePrintString(void);
static void RecordedPlayerHandlePrintSelectionString(void);
static void RecordedPlayerHandleChooseAction(void);
static void RecordedPlayerHandleYesNoBox(void);
static void RecordedPlayerHandleChooseMove(void);
static void RecordedPlayerHandleChooseItem(void);
static void RecordedPlayerHandleChoosePokemon(void);
static void RecordedPlayerHandleCmd23(void);
static void RecordedPlayerHandleHealthBarUpdate(void);
static void RecordedPlayerHandleExpUpdate(void);
static void RecordedPlayerHandleStatusIconUpdate(void);
static void RecordedPlayerHandleStatusAnimation(void);
static void RecordedPlayerHandleStatusXor(void);
static void RecordedPlayerHandleDataTransfer(void);
static void RecordedPlayerHandleDMA3Transfer(void);
static void RecordedPlayerHandlePlayBGM(void);
static void RecordedPlayerHandleCmd32(void);
static void RecordedPlayerHandleTwoReturnValues(void);
static void RecordedPlayerHandleChosenMonReturnValue(void);
static void RecordedPlayerHandleOneReturnValue(void);
static void RecordedPlayerHandleOneReturnValue_Duplicate(void);
static void RecordedPlayerHandleClearUnkVar(void);
static void RecordedPlayerHandleSetUnkVar(void);
static void RecordedPlayerHandleClearUnkFlag(void);
static void RecordedPlayerHandleToggleUnkFlag(void);
static void RecordedPlayerHandleHitAnimation(void);
static void RecordedPlayerHandleCantSwitch(void);
static void RecordedPlayerHandlePlaySE(void);
static void RecordedPlayerHandlePlayFanfareOrBGM(void);
static void RecordedPlayerHandleFaintingCry(void);
static void RecordedPlayerHandleIntroSlide(void);
static void RecordedPlayerHandleIntroTrainerBallThrow(void);
static void RecordedPlayerHandleDrawPartyStatusSummary(void);
static void RecordedPlayerHandleHidePartyStatusSummary(void);
static void RecordedPlayerHandleEndBounceEffect(void);
static void RecordedPlayerHandleSpriteInvisibility(void);
static void RecordedPlayerHandleBattleAnimation(void);
static void RecordedPlayerHandleLinkStandbyMsg(void);
static void RecordedPlayerHandleResetActionMoveSelection(void);
static void RecordedPlayerHandleEndLinkBattle(void);
static void RecordedPlayerCmdEnd(void);

static void RecordedPlayerBufferRunCommand(void);
static void RecordedPlayerBufferExecCompleted(void);
static void SwitchIn_WaitAndEnd(void);
static u32 CopyRecordedPlayerMonData(u8 monId, u8 *dst);
static void SetRecordedPlayerMonData(u8 monId);
static void StartSendOutAnim(u8 battlerId, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void RecordedPlayerDoMoveAnimation(void);
static void Task_StartSendOutAnim(u8 taskId);
static void EndDrawPartyStatusSummary(void);

static void (*const sRecordedPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    [CONTROLLER_GETMONDATA]               = RecordedPlayerHandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = RecordedPlayerHandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = RecordedPlayerHandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = RecordedPlayerHandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = RecordedPlayerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = RecordedPlayerHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = RecordedPlayerHandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = RecordedPlayerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = RecordedPlayerHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = RecordedPlayerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = RecordedPlayerHandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = RecordedPlayerHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = RecordedPlayerHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = RecordedPlayerHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = RecordedPlayerHandlePause,
    [CONTROLLER_MOVEANIMATION]            = RecordedPlayerHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = RecordedPlayerHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = RecordedPlayerHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = RecordedPlayerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = RecordedPlayerHandleYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = RecordedPlayerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = RecordedPlayerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = RecordedPlayerHandleChoosePokemon,
    [CONTROLLER_23]                       = RecordedPlayerHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = RecordedPlayerHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = RecordedPlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = RecordedPlayerHandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = RecordedPlayerHandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = RecordedPlayerHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = RecordedPlayerHandleDataTransfer,
    [CONTROLLER_DMA3TRANSFER]             = RecordedPlayerHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = RecordedPlayerHandlePlayBGM,
    [CONTROLLER_32]                       = RecordedPlayerHandleCmd32,
    [CONTROLLER_TWORETURNVALUES]          = RecordedPlayerHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = RecordedPlayerHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = RecordedPlayerHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = RecordedPlayerHandleOneReturnValue_Duplicate,
    [CONTROLLER_CLEARUNKVAR]              = RecordedPlayerHandleClearUnkVar,
    [CONTROLLER_SETUNKVAR]                = RecordedPlayerHandleSetUnkVar,
    [CONTROLLER_CLEARUNKFLAG]             = RecordedPlayerHandleClearUnkFlag,
    [CONTROLLER_TOGGLEUNKFLAG]            = RecordedPlayerHandleToggleUnkFlag,
    [CONTROLLER_HITANIMATION]             = RecordedPlayerHandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = RecordedPlayerHandleCantSwitch,
    [CONTROLLER_PLAYSE]                   = RecordedPlayerHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = RecordedPlayerHandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = RecordedPlayerHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = RecordedPlayerHandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = RecordedPlayerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = RecordedPlayerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = RecordedPlayerHandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = RecordedPlayerHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = RecordedPlayerHandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = RecordedPlayerHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = RecordedPlayerHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = RecordedPlayerHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = RecordedPlayerHandleEndLinkBattle,
    [CONTROLLER_TERMINATOR_NOP]           = RecordedPlayerCmdEnd
};

static void RecordedPlayerDummy(void)
{
}

void SetControllerToRecordedPlayer(void)
{
    gBattlerControllerFuncs[gActiveBattler] = RecordedPlayerBufferRunCommand;
}

static void RecordedPlayerBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleResources->bufferA[gActiveBattler][0] < ARRAY_COUNT(sRecordedPlayerBufferCommands))
            sRecordedPlayerBufferCommands[gBattleResources->bufferA[gActiveBattler][0]]();
        else
            RecordedPlayerBufferExecCompleted();
    }
}

static void CompleteOnBattlerSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        RecordedPlayerBufferExecCompleted();
}

static void FreeTrainerSpriteAfterSlide(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        BattleGfxSfxDummy3(MALE);
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        RecordedPlayerBufferExecCompleted();
    }
}

static void Intro_DelayAndEnd(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 0;
        RecordedPlayerBufferExecCompleted();
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(void)
{
    bool32 healthboxAnimDone = FALSE;

    if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT)
    {
        if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
        {
            if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
                healthboxAnimDone = TRUE;
        }
        else
        {
            if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
                && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim
            && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;

            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim = FALSE;

            FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
            FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

            HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
            if (IsDoubleBattle())
                HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]], BATTLE_PARTNER(gActiveBattler));

            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 3;
            gBattlerControllerFuncs[gActiveBattler] = Intro_DelayAndEnd;
        }
    }
    else
    {
        if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
        {
            if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
                healthboxAnimDone = TRUE;
        }
        else
        {
            if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
                && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (IsCryPlayingOrClearCrySongs())
            healthboxAnimDone = FALSE;

        if (healthboxAnimDone)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 3;
            gBattlerControllerFuncs[gActiveBattler] = Intro_DelayAndEnd;
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(void)
{
    bool32 bgmRestored = FALSE;

    if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
            TryShinyAnimation(gActiveBattler, &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]]);

        if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive)
            TryShinyAnimation(BATTLE_PARTNER(gActiveBattler), &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]]);
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)], &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]], HEALTHBOX_ALL);
                StartHealthboxSlideIn(BATTLE_PARTNER(gActiveBattler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(gActiveBattler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted = TRUE;
    }

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].waitForCry
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && (gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT)
                    m4aMPlayContinue(&gMPlayInfo_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            }

        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    if (bgmRestored && gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(gActiveBattler)]]);

        DestroySprite(&gSprites[gBattleControllerData[gActiveBattler]]);
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted = FALSE;
        gBattlerControllerFuncs[gActiveBattler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void WaitForMonAnimAfterLoad(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].animEnded && gSprites[gBattlerSpriteIds[gActiveBattler]].x2 == 0)
        RecordedPlayerBufferExecCompleted();
}

static void CompleteOnHealthbarDone(void)
{
    s16 hpValue = MoveBattleBar(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], HEALTH_BAR, 0);

    SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);

    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthboxSpriteIds[gActiveBattler], HP_CURRENT, hpValue, gBattleMons[gActiveBattler].maxHP);
    }
    else
    {
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
        RecordedPlayerBufferExecCompleted();
    }
}

static void FreeMonSpriteAfterFaintAnim(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].y + gSprites[gBattlerSpriteIds[gActiveBattler]].y2 > DISPLAY_HEIGHT)
    {
        u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

        BattleGfxSfxDummy2(species);
        FreeOamMatrix(gSprites[gBattlerSpriteIds[gActiveBattler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
        RecordedPlayerBufferExecCompleted();
    }
}

static void FreeMonSpriteAfterSwitchOutAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
        RecordedPlayerBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(B_WIN_MSG))
        RecordedPlayerBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBattlerSpriteIds[gActiveBattler];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = FALSE;
        gDoingBattleAnim = FALSE;
        RecordedPlayerBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data[1] % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data[1]++;
    }
}

static void SwitchIn_ShowSubstitute(void)
{
    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(gActiveBattler);
        if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_WaitAndEnd;
    }
}

static void SwitchIn_WaitAndEnd(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive
        && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        RecordedPlayerBufferExecCompleted();
    }
}

static void SwitchIn_ShowHealthbox(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;

        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[gActiveBattler]], 0);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(gActiveBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);

        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_ShowSubstitute;
    }
}

static void SwitchIn_TryShinyAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
    {
        TryShinyAnimation(gActiveBattler, &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]]);
    }

    if (gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[gActiveBattler]]);
        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_ShowHealthbox;
    }
}

static void RecordedPlayerBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = RecordedPlayerBufferRunCommand;
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

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive)
        RecordedPlayerBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animFromTableActive)
        RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleGetMonData(void)
{
    BtlController_HandleGetMonData(gActiveBattler, gPlayerParty, RecordedPlayerBufferExecCompleted);
}

static void RecordedPlayerHandleGetRawMonData(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleSetMonData(void)
{
    BtlController_HandleSetMonData(gActiveBattler, gPlayerParty, RecordedPlayerBufferExecCompleted);
}

static void RecordedPlayerHandleSetRawMonData(void)
{
    BtlController_HandleSetRawMonData(gActiveBattler, gPlayerParty, RecordedPlayerBufferExecCompleted);
}

static void RecordedPlayerHandleLoadMonSprite(void)
{
    BtlController_HandleLoadMonSprite(gActiveBattler, gPlayerParty, WaitForMonAnimAfterLoad);
}

static void RecordedPlayerHandleSwitchInAnim(void)
{
    ClearTemporarySpeciesSpriteData(gActiveBattler, gBattleResources->bufferA[gActiveBattler][2]);
    gBattlerPartyIndexes[gActiveBattler] = gBattleResources->bufferA[gActiveBattler][1];
    BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
    StartSendOutAnim(gActiveBattler, gBattleResources->bufferA[gActiveBattler][2]);
    gBattlerControllerFuncs[gActiveBattler] = SwitchIn_TryShinyAnim;
}

static void StartSendOutAnim(u8 battlerId, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(battlerId, dontClearSubstituteBit);
    gBattlerPartyIndexes[battlerId] = gBattleResources->bufferA[battlerId][1];
    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
    gBattleControllerData[battlerId] = CreateInvisibleSpriteWithCallback(SpriteCB_WaitForBattlerBallReleaseAnim);
    SetMultiuseSpriteTemplateToPokemon(species, GetBattlerPosition(battlerId));

    gBattlerSpriteIds[battlerId] = CreateSprite(
      &gMultiuseSpriteTemplate,
      GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X_2),
      GetBattlerSpriteDefault_Y(battlerId),
      GetBattlerSpriteSubpriority(battlerId));

    gSprites[gBattleControllerData[battlerId]].data[1] = gBattlerSpriteIds[battlerId];
    gSprites[gBattleControllerData[battlerId]].data[2] = battlerId;

    gSprites[gBattlerSpriteIds[battlerId]].data[0] = battlerId;
    gSprites[gBattlerSpriteIds[battlerId]].data[2] = species;
    gSprites[gBattlerSpriteIds[battlerId]].oam.paletteNum = battlerId;

    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battlerId]], 0);

    gSprites[gBattlerSpriteIds[battlerId]].invisible = TRUE;
    gSprites[gBattlerSpriteIds[battlerId]].callback = SpriteCallbackDummy;

    gSprites[gBattleControllerData[battlerId]].data[0] = DoPokeballSendOutAnimation(0, POKEBALL_PLAYER_SENDOUT);
}

static void RecordedPlayerHandleReturnMonToBall(void)
{
    if (gBattleResources->bufferA[gActiveBattler][1] == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 0;
        gBattlerControllerFuncs[gActiveBattler] = DoSwitchOutAnimation;
    }
    else
    {
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
        RecordedPlayerBufferExecCompleted();
    }
}

static void DoSwitchOutAnimation(void)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 0;
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_SWITCH_OUT_PLAYER_MON);
            gBattlerControllerFuncs[gActiveBattler] = FreeMonSpriteAfterSwitchOutAnim;
        }
        break;
    }
}

#define sSpeedX data[0]

static void RecordedPlayerHandleDrawTrainerPic(void)
{
    s16 xPos, yPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            trainerPicId = GetActiveBattlerLinkPlayerGender();
        else
            trainerPicId = gLinkPlayers[gRecordedBattleMultiplayerId].gender;
    }
    else
    {
        trainerPicId = gLinkPlayers[0].gender;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != 0) // second mon
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
    {
        trainerPicId = PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender);
        DecompressTrainerFrontPic(trainerPicId, gActiveBattler);
        SetMultiuseSpriteTemplateToTrainerFront(trainerPicId, GetBattlerPosition(gActiveBattler));
        gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate, xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

        gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
        gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = DISPLAY_WIDTH;
        gSprites[gBattlerSpriteIds[gActiveBattler]].y2 = 48;
        gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = -2;
        gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;
        gSprites[gBattlerSpriteIds[gActiveBattler]].oam.affineMode = ST_OAM_AFFINE_OFF;
        gSprites[gBattlerSpriteIds[gActiveBattler]].hFlip = 1;
    }
    else
    {
        DecompressTrainerBackPic(trainerPicId, gActiveBattler);
        SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
        gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate, xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

        gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
        gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = DISPLAY_WIDTH;
        gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = -2;
        gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;
    }

    gBattlerControllerFuncs[gActiveBattler] = CompleteOnBattlerSpriteCallbackDummy;
}

#undef sSpeedX

static void RecordedPlayerHandleTrainerSlide(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleTrainerSlideBack(void)
{
    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 35;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[2] = -40;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[4] = gSprites[gBattlerSpriteIds[gActiveBattler]].y;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[gActiveBattler]], SpriteCallbackDummy);
    gBattlerControllerFuncs[gActiveBattler] = FreeTrainerSpriteAfterSlide;
}

#define sSpeedX data[1]
#define sSpeedY data[2]

static void RecordedPlayerHandleFaintAnimation(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState == 0)
    {
        if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 0;
            HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
            PlaySE12WithPanning(SE_FAINT, -64);
            gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = 0;
            gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedY = 5;
            gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_FaintSlideAnim;
            gBattlerControllerFuncs[gActiveBattler] = FreeMonSpriteAfterFaintAnim;
        }
    }
}

#undef sSpeedX
#undef sSpeedY

static void RecordedPlayerHandlePaletteFade(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleSuccessBallThrowAnim(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleBallThrowAnim(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandlePause(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleMoveAnimation(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        u16 move = gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8);

        gAnimMoveTurn = gBattleResources->bufferA[gActiveBattler][3];
        gAnimMovePower = gBattleResources->bufferA[gActiveBattler][4] | (gBattleResources->bufferA[gActiveBattler][5] << 8);
        gAnimMoveDmg = gBattleResources->bufferA[gActiveBattler][6] | (gBattleResources->bufferA[gActiveBattler][7] << 8) | (gBattleResources->bufferA[gActiveBattler][8] << 16) | (gBattleResources->bufferA[gActiveBattler][9] << 24);
        gAnimFriendship = gBattleResources->bufferA[gActiveBattler][10];
        gWeatherMoveAnim = gBattleResources->bufferA[gActiveBattler][12] | (gBattleResources->bufferA[gActiveBattler][13] << 8);
        gAnimDisableStructPtr = (struct DisableStruct *)&gBattleResources->bufferA[gActiveBattler][16];
        gTransformedPersonalities[gActiveBattler] = gAnimDisableStructPtr->transformedMonPersonality;
        gTransformedOtIds[gActiveBattler] = gAnimDisableStructPtr->transformedMonOtId;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 0;
        gBattlerControllerFuncs[gActiveBattler] = RecordedPlayerDoMoveAnimation;
    }
}

static void RecordedPlayerDoMoveAnimation(void)
{
    u16 move = gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8);
    u8 multihit = gBattleResources->bufferA[gActiveBattler][11];

    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute
            && !gBattleSpritesDataPtr->battlerData[gActiveBattler].flag_x8)
        {
            gBattleSpritesDataPtr->battlerData[gActiveBattler].flag_x8 = 1;
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_SUBSTITUTE_TO_MON);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        {
            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_OFF);
            DoMoveAnim(move);
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 2;
        }
        break;
    case 2:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_NORMAL);
            if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute && multihit < 2)
            {
                InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->battlerData[gActiveBattler].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        {
            CopyAllBattleSpritesInvisibilities();
            TrySetBehindSubstituteSpriteBit(gActiveBattler, gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animationState = 0;
            RecordedPlayerBufferExecCompleted();
        }
        break;
    }
}

static void RecordedPlayerHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16 *)(&gBattleResources->bufferA[gActiveBattler][2]);
    BufferStringBattle(*stringId);

    if (gTestRunnerEnabled)
    {
        TestRunner_Battle_RecordMessage(gDisplayedStringBattle);
        if (gTestRunnerHeadless)
        {
            RecordedPlayerBufferExecCompleted();
            return;
        }
    }

    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnInactiveTextPrinter;
}

static void RecordedPlayerHandlePrintSelectionString(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void ChooseActionInBattlePalace(void)
{
    if (gBattleCommunication[4] >= gBattlersCount / 2)
    {
        BtlController_EmitTwoReturnValues(BUFFER_B, RecordedBattle_GetBattlerAction(RECORDED_BATTLE_PALACE_ACTION, gActiveBattler), 0);
        RecordedPlayerBufferExecCompleted();
    }
}

static void RecordedPlayerHandleChooseAction(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gBattlerControllerFuncs[gActiveBattler] = ChooseActionInBattlePalace;
    }
    else
    {
        BtlController_EmitTwoReturnValues(BUFFER_B, RecordedBattle_GetBattlerAction(RECORDED_ACTION_TYPE, gActiveBattler), 0);
        RecordedPlayerBufferExecCompleted();
    }
}

static void RecordedPlayerHandleYesNoBox(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleChooseMove(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        BtlController_EmitTwoReturnValues(BUFFER_B, 10, ChooseMoveAndTargetInBattlePalace());
    }
    else
    {
        u8 moveId = RecordedBattle_GetBattlerAction(RECORDED_MOVE_SLOT, gActiveBattler);
        u8 target = RecordedBattle_GetBattlerAction(RECORDED_MOVE_TARGET, gActiveBattler);
        BtlController_EmitTwoReturnValues(BUFFER_B, 10, moveId | (target << 8));
    }

    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleChooseItem(void)
{
    u8 byte1 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, gActiveBattler);
    u8 byte2 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, gActiveBattler);
    gBattleStruct->chosenItem[gActiveBattler] = (byte1 << 8) | byte2;
    gBattleStruct->itemPartyIndex[gActiveBattler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_TARGET, gActiveBattler);
    gBattleStruct->itemMoveIndex[gActiveBattler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_MOVE, gActiveBattler);
    BtlController_EmitOneReturnValue(BUFFER_B, gBattleStruct->chosenItem[gActiveBattler]);
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleChoosePokemon(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = RecordedBattle_GetBattlerAction(RECORDED_PARTY_INDEX, gActiveBattler);
    gSelectedMonPartyId = gBattleStruct->monToSwitchIntoId[gActiveBattler]; // Revival Blessing
    BtlController_EmitChosenMonReturnValue(BUFFER_B, *(gBattleStruct->monToSwitchIntoId + gActiveBattler), NULL);
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleCmd23(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleHealthBarUpdate(void)
{
    s16 hpVal;
    s32 maxHP, curHP;

    LoadBattleBarGfx(0);
    hpVal = gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8);

    maxHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_MAX_HP);
    curHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_HP);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        SetBattleBarStruct(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], maxHP, curHP, hpVal);
        TestRunner_Battle_RecordHP(gActiveBattler, curHP, min(maxHP, max(0, curHP - hpVal)));
    }
    else
    {
        SetBattleBarStruct(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], maxHP, 0, hpVal);
        UpdateHpTextInHealthbox(gHealthboxSpriteIds[gActiveBattler], HP_CURRENT, 0, maxHP);
        TestRunner_Battle_RecordHP(gActiveBattler, curHP, 0);
    }

    gBattlerControllerFuncs[gActiveBattler] = CompleteOnHealthbarDone;
}

static void RecordedPlayerHandleExpUpdate(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleStatusIconUpdate(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        u8 battlerId;

        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_STATUS_ICON);
        battlerId = gActiveBattler;
        gBattleSpritesDataPtr->healthBoxesData[battlerId].statusAnimActive = 0;
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedStatusAnimation;

        if (gTestRunnerEnabled)
            TestRunner_Battle_RecordStatus1(battlerId, GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_STATUS));
    }
}

static void RecordedPlayerHandleStatusAnimation(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        InitAndLaunchChosenStatusAnimation(gBattleResources->bufferA[gActiveBattler][1],
                        gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8) | (gBattleResources->bufferA[gActiveBattler][4] << 16) | (gBattleResources->bufferA[gActiveBattler][5] << 24));
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedStatusAnimation;
    }
}

static void RecordedPlayerHandleStatusXor(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleDataTransfer(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleDMA3Transfer(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandlePlayBGM(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleCmd32(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleTwoReturnValues(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleChosenMonReturnValue(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleOneReturnValue(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleOneReturnValue_Duplicate(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleClearUnkVar(void)
{
    gUnusedControllerStruct.unk = 0;
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleSetUnkVar(void)
{
    gUnusedControllerStruct.unk = gBattleResources->bufferA[gActiveBattler][1];
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleClearUnkFlag(void)
{
    gUnusedControllerStruct.flag = 0;
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleToggleUnkFlag(void)
{
    gUnusedControllerStruct.flag ^= 1;
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleHitAnimation(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].invisible == TRUE)
    {
        RecordedPlayerBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBattlerSpriteIds[gActiveBattler]].data[1] = 0;
        DoHitAnimHealthboxEffect(gActiveBattler);
        gBattlerControllerFuncs[gActiveBattler] = DoHitAnimBlinkSpriteEffect;
    }
}

static void RecordedPlayerHandleCantSwitch(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandlePlaySE(void)
{
    s8 pan;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        pan = SOUND_PAN_ATTACKER;
    else
        pan = SOUND_PAN_TARGET;

    PlaySE12WithPanning(gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8), pan);
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandlePlayFanfareOrBGM(void)
{
    if (gBattleResources->bufferA[gActiveBattler][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8));
    }

    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry_ByMode(species, -25, CRY_MODE_FAINT);
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleResources->bufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;
    u32 trainerPicId;

    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattlerSpriteIds[gActiveBattler]]);

    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 50;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[2] = -40;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[4] = gSprites[gBattlerSpriteIds[gActiveBattler]].y;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = StartAnimLinearTranslation;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[5] = gActiveBattler;

    StoreSpriteCallbackInData6(&gSprites[gBattlerSpriteIds[gActiveBattler]], SpriteCB_FreePlayerSpriteLoadMonSprite);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[gActiveBattler]], 1);

    paletteNum = AllocSpritePalette(0xD6F9);
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender;
    else
        trainerPicId = gSaveBlock2Ptr->playerGender;

    LoadCompressedPalette(gTrainerBackPicPaletteTable[trainerPicId].data, OBJ_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);

    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = paletteNum;

    taskId = CreateTask(Task_StartSendOutAnim, 5);
    gTasks[taskId].data[0] = gActiveBattler;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[gActiveBattler]].func = Task_HidePartyStatusSummary;

    gBattleSpritesDataPtr->animationData->introAnimActive = TRUE;
    gBattlerControllerFuncs[gActiveBattler] = RecordedPlayerDummy;
}

static void Task_StartSendOutAnim(u8 taskId)
{
    if (gTasks[taskId].data[1] < 24)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        u8 savedActiveBank = gActiveBattler;

        gActiveBattler = gTasks[taskId].data[0];
        if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            gBattleResources->bufferA[gActiveBattler][1] = gBattlerPartyIndexes[gActiveBattler];
            StartSendOutAnim(gActiveBattler, FALSE);
        }
        else
        {
            gBattleResources->bufferA[gActiveBattler][1] = gBattlerPartyIndexes[gActiveBattler];
            StartSendOutAnim(gActiveBattler, FALSE);
            gActiveBattler ^= BIT_FLANK;
            gBattleResources->bufferA[gActiveBattler][1] = gBattlerPartyIndexes[gActiveBattler];
            BattleLoadMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
            StartSendOutAnim(gActiveBattler, FALSE);
            gActiveBattler ^= BIT_FLANK;
        }
        gBattlerControllerFuncs[gActiveBattler] = Intro_TryShinyAnimShowHealthbox;
        gActiveBattler = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void RecordedPlayerHandleDrawPartyStatusSummary(void)
{
    if (gBattleResources->bufferA[gActiveBattler][1] != 0 && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
    {
        RecordedPlayerBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown = 1;
        gBattlerStatusSummaryTaskId[gActiveBattler] = CreatePartyStatusSummarySprites(gActiveBattler, (struct HpAndStatus *)&gBattleResources->bufferA[gActiveBattler][4], gBattleResources->bufferA[gActiveBattler][1], gBattleResources->bufferA[gActiveBattler][2]);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusDelayTimer = 0;

        if (gBattleResources->bufferA[gActiveBattler][2] != 0)
            gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusDelayTimer = 93;

        gBattlerControllerFuncs[gActiveBattler] = EndDrawPartyStatusSummary;
    }
}

static void EndDrawPartyStatusSummary(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusDelayTimer++ > 92)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusDelayTimer = 0;
        RecordedPlayerBufferExecCompleted();
    }
}

static void RecordedPlayerHandleHidePartyStatusSummary(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[gActiveBattler]].func = Task_HidePartyStatusSummary;
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleEndBounceEffect(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleSpriteInvisibility(void)
{
    if (IsBattlerSpritePresent(gActiveBattler))
    {
        gSprites[gBattlerSpriteIds[gActiveBattler]].invisible = gBattleResources->bufferA[gActiveBattler][1];
        CopyBattleSpriteInvisibility(gActiveBattler);
    }
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleBattleAnimation(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        u8 animationId = gBattleResources->bufferA[gActiveBattler][1];
        u16 argument = gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8);

        if (TryHandleLaunchBattleTableAnimation(gActiveBattler, gActiveBattler, gActiveBattler, animationId, argument))
            RecordedPlayerBufferExecCompleted();
        else
            gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedBattleAnimation;
    }
}

static void RecordedPlayerHandleLinkStandbyMsg(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleResetActionMoveSelection(void)
{
    RecordedPlayerBufferExecCompleted();
}

static void RecordedPlayerHandleEndLinkBattle(void)
{
    gBattleOutcome = gBattleResources->bufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    RecordedPlayerBufferExecCompleted();
    gBattlerControllerFuncs[gActiveBattler] = SetBattleEndCallbacks;
}

static void RecordedPlayerCmdEnd(void)
{
}
