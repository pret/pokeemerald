#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "bg.h"
#include "data.h"
#include "frontier_util.h"
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
#include "constants/battle_partner.h"
#include "constants/songs.h"
#include "constants/party_menu.h"
#include "constants/trainers.h"

static void RecordedPartnerHandleDrawTrainerPic(enum BattlerId battler);
static void RecordedPartnerHandleTrainerSlide(enum BattlerId battler);
static void RecordedPartnerHandleTrainerSlideBack(enum BattlerId battler);
static void RecordedPartnerHandleChooseAction(enum BattlerId battler);
static void RecordedPartnerHandleChooseMove(enum BattlerId battler);
static void RecordedPartnerHandleChoosePokemon(enum BattlerId battler);
static void RecordedPartnerHandleIntroTrainerBallThrow(enum BattlerId battler);
static void RecordedPartnerHandleDrawPartyStatusSummary(enum BattlerId battler);
static void RecordedPartnerHandleEndLinkBattle(enum BattlerId battler);
static void RecordedPartnerBufferRunCommand(enum BattlerId battler);

static void (*const sRecordedPartnerBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_HandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = BtlController_HandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = RecordedPartnerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = RecordedPartnerHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = RecordedPartnerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_Empty,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = RecordedPartnerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = RecordedPartnerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = BtlController_Empty,
    [CONTROLLER_CHOOSEPOKEMON]            = RecordedPartnerHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate, // Partner's player gets experience the same way as the player.
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
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = RecordedPartnerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = RecordedPartnerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = RecordedPartnerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToRecordedPartner(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_RECORDED_PARTNER;
    gBattlerControllerEndFuncs[battler] = RecordedPartnerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = RecordedPartnerBufferRunCommand;
}

static void RecordedPartnerBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sRecordedPartnerBufferCommands))
            sRecordedPartnerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void Intro_WaitForHealthbox(enum BattlerId battler)
{
    bool32 finished = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
            finished = TRUE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
            && gSprites[gHealthboxSpriteIds[GetPartnerBattler(battler)]].callback == SpriteCallbackDummy)
        {
            finished = TRUE;
        }
    }

    if (IsCryPlayingOrClearCrySongs())
        finished = FALSE;

    if (finished)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;
    }
}

void Controller_RecordedPartnerShowIntroHealthbox(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[GetPartnerBattler(battler)].ballAnimActive
        && gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
        && ++gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay != 1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        TryShinyAnimation(battler, GetBattlerMon(battler));

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

        gBattlerControllerFuncs[battler] = Intro_WaitForHealthbox;
    }
}

void RecordedPartnerBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = RecordedPartnerBufferRunCommand;
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

static enum TrainerPicID RecordedPartnerGetTrainerBackPicId(enum DifficultyLevel difficulty)
{
    enum TrainerPicID trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        trainerPicId = gBattlePartners[difficulty][gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerPic;
    else
        trainerPicId = GetPlayerTrainerPic(gSaveBlock2Ptr->playerGender, GAME_VERSION);

    return trainerPicId;
}

// some explanation here
// in emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven) that use the back pic as well as animate it
static void RecordedPartnerHandleDrawTrainerPic(enum BattlerId battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    enum TrainerPicID trainerPicId;

    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);

    if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        trainerPicId = gBattlePartners[difficulty][gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerPic;
        xPos = 90;
        yPos = (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80;
    }
    else if (IsAiVsAiBattle())
    {
        trainerPicId = GetTrainerPicFromId(gPartnerTrainerId);
        xPos = 60;
        yPos = 80;
    }
    else
    {
        trainerPicId = GetFrontierTrainerFrontSpriteId(gPartnerTrainerId);
        xPos = 32;
        yPos = 80;
    }

    // Use back pic only if the partner Steven or is custom.
    if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
        isFrontPic = FALSE;
    else
        isFrontPic = TRUE;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void RecordedPartnerHandleTrainerSlide(enum BattlerId battler)
{
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);
    enum TrainerPicID trainerPicId = RecordedPartnerGetTrainerBackPicId(difficulty);
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void RecordedPartnerHandleTrainerSlideBack(enum BattlerId battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void RecordedPartnerHandleChooseAction(enum BattlerId battler)
{
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RecordedBattle_GetBattlerAction(RECORDED_ACTION_TYPE, battler), 0);
    BtlController_Complete(battler);
}

static void RecordedPartnerHandleChooseMove(enum BattlerId battler)
{
    u8 moveIndex = RecordedBattle_GetBattlerAction(RECORDED_MOVE_SLOT, battler);
    u8 target = RecordedBattle_GetBattlerAction(RECORDED_MOVE_TARGET, battler);
    if (target == RECORDED_TARGET_DEFAULT)
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
        target = GetDefaultSelectionTarget(battler, GetBattlerMoveSelectionTargetType(battler, moveInfo->moves[moveIndex]));
    }
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, moveIndex | (target << 8));

    BtlController_Complete(battler);
}

static void RecordedPartnerHandleChoosePokemon(enum BattlerId battler)
{
    gBattleStruct->monToSwitchIntoId[battler] = RecordedBattle_GetBattlerAction(RECORDED_PARTY_INDEX, battler);
    gSelectedMonPartyId = gBattleStruct->monToSwitchIntoId[battler]; // Revival Blessing
    BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattleStruct->monToSwitchIntoId[battler], NULL);
    BtlController_Complete(battler);
}

static void RecordedPartnerHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    const u16 *trainerPal;
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(gPartnerTrainerId);

    if (gPartnerTrainerId > TRAINER_PARTNER(PARTNER_NONE))
        trainerPal = GetTrainerBackPicPalette(gBattlePartners[difficulty][gPartnerTrainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerPic);
    else if (IsAiVsAiBattle())
        trainerPal = GetTrainerFrontPicPalette(GetTrainerPicFromId(gPartnerTrainerId));
    else
        trainerPal = GetTrainerFrontPicPalette(GetFrontierTrainerFrontSpriteId(gPartnerTrainerId)); // 2 vs 2 multi battle in Battle Frontier, load front sprite and pal.

    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F9, trainerPal, 24, Controller_RecordedPartnerShowIntroHealthbox);
}

static void RecordedPartnerHandleDrawPartyStatusSummary(enum BattlerId battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void RecordedPartnerHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
