#include "global.h"
#include "battle.h"
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
#include "trainer.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "test/battle.h"

static void RecordedPlayerHandleDrawTrainerPic(enum BattlerId battler);
static void RecordedPlayerHandleTrainerSlideBack(enum BattlerId battler);
static void RecordedPlayerHandleChooseAction(enum BattlerId battler);
static void RecordedPlayerHandleChooseMove(enum BattlerId battler);
static void RecordedPlayerHandleChooseItem(enum BattlerId battler);
static void RecordedPlayerHandleChoosePokemon(enum BattlerId battler);
static void RecordedPlayerHandleStatusAnimation(enum BattlerId battler);
static void RecordedPlayerHandleIntroTrainerBallThrow(enum BattlerId battler);
static void RecordedPlayerHandleDrawPartyStatusSummary(enum BattlerId battler);
static void RecordedPlayerHandleEndLinkBattle(enum BattlerId battler);
static void RecordedPlayerBufferRunCommand(enum BattlerId battler);

static void (*const sRecordedPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_HandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = BtlController_HandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = RecordedPlayerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = RecordedPlayerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_HandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = RecordedPlayerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = RecordedPlayerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = RecordedPlayerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = RecordedPlayerHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
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
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = RecordedPlayerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToRecordedPlayer(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_RECORDED_PLAYER;
    gBattlerControllerEndFuncs[battler] = RecordedPlayerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = RecordedPlayerBufferRunCommand;
}

static void RecordedPlayerBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sRecordedPlayerBufferCommands))
            sRecordedPlayerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(enum BattlerId battler)
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
                && gSprites[gHealthboxSpriteIds[GetPartnerBattler(battler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
            && gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

            gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].finishedShinyMonAnim = FALSE;

            FreeShinyStars();

            HandleLowHpMusicChange(GetBattlerMon(battler), battler);
            if (IsDoubleBattle())
                HandleLowHpMusicChange(GetBattlerMon(GetPartnerBattler(battler)), GetPartnerBattler(battler));

            gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
            gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;
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
                && gSprites[gHealthboxSpriteIds[GetPartnerBattler(battler)]].callback == SpriteCallbackDummy)
            {
                healthboxAnimDone = TRUE;
            }
        }

        if (IsCryPlayingOrClearCrySongs())
            healthboxAnimDone = FALSE;

        if (healthboxAnimDone)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
            gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(enum BattlerId battler)
{
    bool32 bgmRestored = FALSE;

    if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
            TryShinyAnimation(battler, GetBattlerMon(battler));

        if (!gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive)
            TryShinyAnimation(GetPartnerBattler(battler), GetBattlerMon(GetPartnerBattler(battler)));
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[GetPartnerBattler(battler)], GetBattlerMon(GetPartnerBattler(battler)), HEALTHBOX_ALL);
                StartHealthboxSlideIn(GetPartnerBattler(battler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[GetPartnerBattler(battler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].waitForCry
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
            DestroySprite(&gSprites[gBattleControllerData[GetPartnerBattler(battler)]]);

        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;
        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

void RecordedPlayerBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = RecordedPlayerBufferRunCommand;
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

static void RecordedPlayerHandleDrawTrainerPic(enum BattlerId battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    enum TrainerPicID trainerPicId;

    if (TESTING)
    {
        trainerPicId = TRAINER_PIC_BRENDAN;
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
            xPos = 32;
        else
            xPos = 80;
        yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
    }
    else
    {
        enum Gender gender;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                gender = GetBattlerLinkPlayerGender(battler);
            else
                gender = gLinkPlayers[gRecordedBattleMultiplayerId].gender;
        }
        else
            gender = gLinkPlayers[0].gender;

        trainerPicId = GetPlayerTrainerPic(gender, GAME_VERSION);
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if ((GetBattlerPosition(battler) & BIT_FLANK) != 0) // second mon
                xPos = 90;
            else // first mon
                xPos = 32;

            // !TESTING added as otherwise first test battle sprite is positioned incorrectly
            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && !TESTING)
            {
                xPos = 90;
                yPos = 80;
            }
            else
            {
                yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
            }
        }
        else
        {
            xPos = 80;
            yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && !TESTING)
        isFrontPic = TRUE;
    else
        isFrontPic = FALSE;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void RecordedPlayerHandleTrainerSlideBack(enum BattlerId battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void ChooseActionInBattlePalace(enum BattlerId battler)
{
    if (gBattleCommunication[4] >= gBattlersCount / 2)
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RecordedBattle_GetBattlerAction(RECORDED_BATTLE_PALACE_ACTION, battler), 0);
        BtlController_Complete(battler);
    }
}

static void RecordedPlayerHandleChooseAction(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gBattlerControllerFuncs[battler] = ChooseActionInBattlePalace;
    }
    else
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RecordedBattle_GetBattlerAction(RECORDED_ACTION_TYPE, battler), 0);
        BtlController_Complete(battler);
    }
}

static void RecordedPlayerHandleChooseMove(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, ChooseMoveAndTargetInBattlePalace(battler));
    }
    else
    {
        u8 moveIndex = RecordedBattle_GetBattlerAction(RECORDED_MOVE_SLOT, battler);
        u8 target = RecordedBattle_GetBattlerAction(RECORDED_MOVE_TARGET, battler);
        if (target == RECORDED_TARGET_DEFAULT)
        {
            struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
            target = GetDefaultSelectionTarget(battler, GetBattlerMoveSelectionTargetType(battler, moveInfo->moves[moveIndex]));
        }
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, moveIndex | (target << 8));
    }

    BtlController_Complete(battler);
}

static void RecordedPlayerHandleChooseItem(enum BattlerId battler)
{
    u8 byte1 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, battler);
    u8 byte2 = RecordedBattle_GetBattlerAction(RECORDED_ITEM_ID, battler);
    gBattleStruct->chosenItem[battler] = (byte1 << 8) | byte2;

    if (TESTING)
    {
        assertf(CheckBagHasItem(gBattleStruct->chosenItem[battler], 1), "Tried to used an item not present in bag");
        if (!GetItemImportance(gBattleStruct->chosenItem[battler]))
            RemoveBagItem(gBattleStruct->chosenItem[battler], 1);
    }

    gBattleStruct->itemPartyIndex[battler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_TARGET, battler);
    gBattleStruct->itemMoveIndex[battler] = RecordedBattle_GetBattlerAction(RECORDED_ITEM_MOVE, battler);
    BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gBattleStruct->chosenItem[battler]);
    BtlController_Complete(battler);
}

static void RecordedPlayerHandleChoosePokemon(enum BattlerId battler)
{
    gBattleStruct->monToSwitchIntoId[battler] = RecordedBattle_GetBattlerAction(RECORDED_PARTY_INDEX, battler);
    gSelectedMonPartyId = gBattleStruct->monToSwitchIntoId[battler]; // Revival Blessing
    BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattleStruct->monToSwitchIntoId[battler], NULL);
    BtlController_Complete(battler);
}

static void RecordedPlayerHandleStatusAnimation(enum BattlerId battler)
{
    BtlController_HandleStatusAnimation(battler);
}

static void RecordedPlayerHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    enum TrainerPicID trainerPicId;
    const u16 *trainerPal;
    enum Gender gender;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        gender = gLinkPlayers[GetBattlerMultiplayerId(battler)].gender;
    else
        gender = gSaveBlock2Ptr->playerGender;

    trainerPicId = GetPlayerTrainerPic(gender, GAME_VERSION);
    trainerPal = GetTrainerBackPicPalette(trainerPicId);
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F9, trainerPal, 24, Intro_TryShinyAnimShowHealthbox);
}

static void RecordedPlayerHandleDrawPartyStatusSummary(enum BattlerId battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void RecordedPlayerHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
