#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "bg.h"
#include "data.h"
#include "item_use.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"
#include "constants/party_menu.h"
#include "constants/trainers.h"

static void PlayerPartnerHandleLoadMonSprite(void);
static void PlayerPartnerHandleSwitchInAnim(void);
static void PlayerPartnerHandleDrawTrainerPic(void);
static void PlayerPartnerHandleTrainerSlideBack(void);
static void PlayerPartnerHandleMoveAnimation(void);
static void PlayerPartnerHandlePrintString(void);
static void PlayerPartnerHandleChooseAction(void);
static void PlayerPartnerHandleChooseMove(void);
static void PlayerPartnerHandleChoosePokemon(void);
static void PlayerPartnerHandleHealthBarUpdate(void);
static void PlayerPartnerHandleIntroTrainerBallThrow(void);
static void PlayerPartnerHandleDrawPartyStatusSummary(void);
static void PlayerPartnerHandleBattleAnimation(void);
static void PlayerPartnerHandleEndLinkBattle(void);

static void PlayerPartnerBufferRunCommand(void);
static void PlayerPartnerBufferExecCompleted(void);
static void Task_LaunchLvlUpAnim(u8 taskId);
static void DestroyExpTaskAndCompleteOnInactiveTextPrinter(u8 taskId);
static void Task_PrepareToGiveExpWithExpBar(u8 taskId);
static void Task_GiveExpWithExpBar(u8 taskId);
static void Task_UpdateLvlInHealthbox(u8 taskId);
static void SwitchIn_WaitAndEnd(void);

static void (*const sPlayerPartnerBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = PlayerPartnerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = PlayerPartnerHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = PlayerPartnerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = PlayerPartnerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_Empty,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = PlayerPartnerHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = PlayerPartnerHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = PlayerPartnerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = PlayerPartnerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = BtlController_Empty,
    [CONTROLLER_CHOOSEPOKEMON]            = PlayerPartnerHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = PlayerPartnerHandleHealthBarUpdate,
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
    [CONTROLLER_INTROTRAINERBALLTHROW]    = PlayerPartnerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = PlayerPartnerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = PlayerPartnerHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = PlayerPartnerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToPlayerPartner(void)
{
    gBattlerControllerEndFuncs[gActiveBattler] = PlayerPartnerBufferExecCompleted;
    gBattlerControllerFuncs[gActiveBattler] = PlayerPartnerBufferRunCommand;
}

static void PlayerPartnerBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleResources->bufferA[gActiveBattler][0] < ARRAY_COUNT(sPlayerPartnerBufferCommands))
            sPlayerPartnerBufferCommands[gBattleResources->bufferA[gActiveBattler][0]]();
        else
            PlayerPartnerBufferExecCompleted();
    }
}

static void Intro_DelayAndEnd(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 0;
        BattleControllerComplete(gActiveBattler);
    }
}

static void Intro_WaitForHealthbox(void)
{
    bool32 finished = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
            finished = TRUE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
            && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy)
        {
            finished = TRUE;
        }
    }

    if (IsCryPlayingOrClearCrySongs())
        finished = FALSE;

    if (finished)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 3;
        gBattlerControllerFuncs[gActiveBattler] = Intro_DelayAndEnd;
    }
}

// Also used by the link partner.
void Controller_PlayerPartnerShowIntroHealthbox(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive
        && gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
        && ++gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay != 1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 0;

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

        gBattlerControllerFuncs[gActiveBattler] = Intro_WaitForHealthbox;
    }
}

static void WaitForMonAnimAfterLoad(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].animEnded && gSprites[gBattlerSpriteIds[gActiveBattler]].x2 == 0)
        PlayerPartnerBufferExecCompleted();
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
        PlayerPartnerBufferExecCompleted();
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

static void PlayerPartnerBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = PlayerPartnerBufferRunCommand;
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

static void PlayerPartnerHandleLoadMonSprite(void)
{
    BtlController_HandleLoadMonSprite(gActiveBattler, gPlayerParty, WaitForMonAnimAfterLoad);
}

static void PlayerPartnerHandleSwitchInAnim(void)
{
    BtlController_HandleSwitchInAnim(gActiveBattler, TRUE, SwitchIn_TryShinyAnim);
}

// some explanation here
// in emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven) that use the back pic as well as animate it
static void PlayerPartnerHandleDrawTrainerPic(void)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    u32 trainerPicId;

    if (gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
    {
        trainerPicId = TRAINER_BACK_PIC_STEVEN;
        xPos = 90;
        yPos = (8 - gTrainerBackPicCoords[trainerPicId].size) * 4 + 80;
    }
    else if (gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER)
    {
        trainerPicId = gPartnerSpriteId;
        xPos = 90;
        yPos = (8 - gTrainerBackPicCoords[trainerPicId].size) * 4 + 80;
    }
    else
    {
        trainerPicId = GetFrontierTrainerFrontSpriteId(gPartnerTrainerId);
        xPos = 32;
        yPos = (8 - gTrainerFrontPicCoords[trainerPicId].size) * 4 + 80;
    }

    // Use back pic only if the partner is Steven or a custom partner.
    if (gPartnerTrainerId == TRAINER_STEVEN_PARTNER || gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER)
        isFrontPic = FALSE;
    else
        isFrontPic = TRUE;

    BtlController_HandleDrawTrainerPic(gActiveBattler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void PlayerPartnerHandleTrainerSlideBack(void)
{
    BtlController_HandleTrainerSlideBack(gActiveBattler, 35, FALSE);
}

static void PlayerPartnerHandleMoveAnimation(void)
{
    BtlController_HandleMoveAnimation(gActiveBattler, FALSE);
}

static void PlayerPartnerHandlePrintString(void)
{
    BtlController_HandlePrintString(gActiveBattler, FALSE, FALSE);
}

static void PlayerPartnerHandleChooseAction(void)
{
    AI_TrySwitchOrUseItem();
    PlayerPartnerBufferExecCompleted();
}

static void PlayerPartnerHandleChooseMove(void)
{
    u8 chosenMoveId;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[gActiveBattler][4]);

    chosenMoveId = gBattleStruct->aiMoveOrAction[gActiveBattler];
    gBattlerTarget = gBattleStruct->aiChosenTarget[gActiveBattler];

    if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & (MOVE_TARGET_USER | MOVE_TARGET_USER_OR_SELECTED))
        gBattlerTarget = gActiveBattler;
    if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & MOVE_TARGET_BOTH)
    {
        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
    }

    if (ShouldUseZMove(gActiveBattler, gBattlerTarget, moveInfo->moves[chosenMoveId]))
        QueueZMove(gActiveBattler, moveInfo->moves[chosenMoveId]);

    // If partner can mega evolve, do it.
    if (CanMegaEvolve(gActiveBattler))
        BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (RET_MEGA_EVOLUTION) | (gBattlerTarget << 8));
    else
        BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (gBattlerTarget << 8));

    PlayerPartnerBufferExecCompleted();
}

static void PlayerPartnerHandleChoosePokemon(void)
{
    s32 chosenMonId;
    // Choosing Revival Blessing target
    if ((gBattleResources->bufferA[gActiveBattler][1] & 0xF) == PARTY_ACTION_CHOOSE_FAINTED_MON)
    {
        chosenMonId = gSelectedMonPartyId = GetFirstFaintedPartyIndex(gActiveBattler);
    }
    // Switching out
    else
    {
        chosenMonId = GetMostSuitableMonToSwitchInto();
        if (chosenMonId == PARTY_SIZE) // just switch to the next mon
        {
            u8 playerMonIdentity = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            u8 selfIdentity = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);

            for (chosenMonId = PARTY_SIZE / 2; chosenMonId < PARTY_SIZE; chosenMonId++)
            {
                if (GetMonData(&gPlayerParty[chosenMonId], MON_DATA_HP) != 0
                    && chosenMonId != gBattlerPartyIndexes[playerMonIdentity]
                    && chosenMonId != gBattlerPartyIndexes[selfIdentity])
                {
                    break;
                }
            }
        }
        *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = chosenMonId;
    }
    BtlController_EmitChosenMonReturnValue(BUFFER_B, chosenMonId, NULL);
    PlayerPartnerBufferExecCompleted();
}

static void PlayerPartnerHandleHealthBarUpdate(void)
{
    BtlController_HandleHealthBarUpdate(gActiveBattler, FALSE);
}

static void PlayerPartnerHandleIntroTrainerBallThrow(void)
{
    const u32 *trainerPal;

    if (gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
        trainerPal = gTrainerBackPicPaletteTable[TRAINER_STEVEN_PARTNER].data;
    else if (gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER) // Custom multi battle.
        trainerPal = gTrainerBackPicPaletteTable[gPartnerSpriteId].data;
    else
        trainerPal = gTrainerFrontPicPaletteTable[GetFrontierTrainerFrontSpriteId(gPartnerTrainerId)].data; // 2 vs 2 multi battle in Battle Frontier, load front sprite and pal.

    BtlController_HandleIntroTrainerBallThrow(gActiveBattler, 0xD6F9, trainerPal, 24, Controller_PlayerPartnerShowIntroHealthbox);
}

static void PlayerPartnerHandleDrawPartyStatusSummary(void)
{
    BtlController_HandleDrawPartyStatusSummary(gActiveBattler, B_SIDE_PLAYER, TRUE);
}

static void PlayerPartnerHandleBattleAnimation(void)
{
    BtlController_HandleBattleAnimation(gActiveBattler, FALSE, FALSE);
}

static void PlayerPartnerHandleEndLinkBattle(void)
{
    gBattleOutcome = gBattleResources->bufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    PlayerPartnerBufferExecCompleted();
    gBattlerControllerFuncs[gActiveBattler] = SetBattleEndCallbacks;
}
