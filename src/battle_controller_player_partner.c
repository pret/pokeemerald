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

static void PlayerPartnerHandleLoadMonSprite(u32 battler);
static void PlayerPartnerHandleSwitchInAnim(u32 battler);
static void PlayerPartnerHandleDrawTrainerPic(u32 battler);
static void PlayerPartnerHandleTrainerSlideBack(u32 battler);
static void PlayerPartnerHandleMoveAnimation(u32 battler);
static void PlayerPartnerHandlePrintString(u32 battler);
static void PlayerPartnerHandleChooseAction(u32 battler);
static void PlayerPartnerHandleChooseMove(u32 battler);
static void PlayerPartnerHandleChoosePokemon(u32 battler);
static void PlayerPartnerHandleHealthBarUpdate(u32 battler);
static void PlayerPartnerHandleIntroTrainerBallThrow(u32 battler);
static void PlayerPartnerHandleDrawPartyStatusSummary(u32 battler);
static void PlayerPartnerHandleBattleAnimation(u32 battler);
static void PlayerPartnerHandleEndLinkBattle(u32 battler);

static void PlayerPartnerBufferRunCommand(u32 battler);
static void PlayerPartnerBufferExecCompleted(u32 battler);
static void SwitchIn_WaitAndEnd(u32 battler);

static void (*const sPlayerPartnerBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
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

void SetControllerToPlayerPartner(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = PlayerPartnerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = PlayerPartnerBufferRunCommand;
}

static void PlayerPartnerBufferRunCommand(u32 battler)
{
    if (gBattleControllerExecFlags & gBitTable[battler])
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sPlayerPartnerBufferCommands))
            sPlayerPartnerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            PlayerPartnerBufferExecCompleted(battler);
    }
}

static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        BattleControllerComplete(battler);
    }
}

static void Intro_WaitForHealthbox(u32 battler)
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
            && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
        {
            finished = TRUE;
        }
    }

    if (IsCryPlayingOrClearCrySongs())
        finished = FALSE;

    if (finished)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
    }
}

// Also used by the link partner.
void Controller_PlayerPartnerShowIntroHealthbox(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive
        && gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
        && ++gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay != 1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        TryShinyAnimation(battler, &gPlayerParty[gBattlerPartyIndexes[battler]]);

        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(BATTLE_PARTNER(battler));
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
        }

        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForHealthbox;
    }
}

static void WaitForMonAnimAfterLoad(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].animEnded && gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        PlayerPartnerBufferExecCompleted(battler);
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
        PlayerPartnerBufferExecCompleted(battler);
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

static void PlayerPartnerBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = PlayerPartnerBufferRunCommand;
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

static void PlayerPartnerHandleLoadMonSprite(u32 battler)
{
    BtlController_HandleLoadMonSprite(battler, WaitForMonAnimAfterLoad);
}

static void PlayerPartnerHandleSwitchInAnim(u32 battler)
{
    BtlController_HandleSwitchInAnim(battler, TRUE, SwitchIn_TryShinyAnim);
}

// some explanation here
// in emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven) that use the back pic as well as animate it
static void PlayerPartnerHandleDrawTrainerPic(u32 battler)
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
    else if (IsAiVsAiBattle())
    {
        trainerPicId = gTrainers[gPartnerTrainerId].trainerPic;
        xPos = 60;
        yPos = (8 - gTrainerFrontPicCoords[trainerPicId].size) * 4 + 80;
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

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void PlayerPartnerHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void PlayerPartnerHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler, FALSE);
}

static void PlayerPartnerHandlePrintString(u32 battler)
{
    BtlController_HandlePrintString(battler, FALSE, FALSE);
}

static void PlayerPartnerHandleChooseAction(u32 battler)
{
    AI_TrySwitchOrUseItem(battler);
    PlayerPartnerBufferExecCompleted(battler);
}

static void PlayerPartnerHandleChooseMove(u32 battler)
{
    u8 chosenMoveId;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

    chosenMoveId = gBattleStruct->aiMoveOrAction[battler];
    gBattlerTarget = gBattleStruct->aiChosenTarget[battler];

    if (chosenMoveId == AI_CHOICE_SWITCH)
    {
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, 0xFFFF);
    }
    else
    {
        if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & (MOVE_TARGET_USER | MOVE_TARGET_USER_OR_SELECTED))
            gBattlerTarget = battler;
        if (gBattleMoves[moveInfo->moves[chosenMoveId]].target & MOVE_TARGET_BOTH)
        {
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }

        if (ShouldUseZMove(battler, gBattlerTarget, moveInfo->moves[chosenMoveId]))
            QueueZMove(battler, moveInfo->moves[chosenMoveId]);

        // If partner can mega evolve, do it.
        if (CanMegaEvolve(battler))
            BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, (chosenMoveId) | (RET_MEGA_EVOLUTION) | (gBattlerTarget << 8));
        else if (CanUltraBurst(battler))
            BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, (chosenMoveId) | (RET_ULTRA_BURST) | (gBattlerTarget << 8));
        else
            BtlController_EmitTwoReturnValues(battler, BUFFER_B, 10, (chosenMoveId) | (gBattlerTarget << 8));
    }

    PlayerPartnerBufferExecCompleted(battler);
}

static void PlayerPartnerHandleChoosePokemon(u32 battler)
{
    s32 chosenMonId;
    // Choosing Revival Blessing target
    if ((gBattleResources->bufferA[battler][1] & 0xF) == PARTY_ACTION_CHOOSE_FAINTED_MON)
    {
        chosenMonId = gSelectedMonPartyId = GetFirstFaintedPartyIndex(battler);
    }
    // Switching out
    else if (gBattleStruct->monToSwitchIntoId[battler] >= PARTY_SIZE || !IsValidForBattle(&gPlayerParty[gBattleStruct->monToSwitchIntoId[battler]]))
    {
        chosenMonId = GetMostSuitableMonToSwitchInto(battler, TRUE);

        if (chosenMonId == PARTY_SIZE || !IsValidForBattle(&gPlayerParty[chosenMonId])) // just switch to the next mon
        {
            s32 firstId = (IsAiVsAiBattle()) ? 0 : (PARTY_SIZE / 2);
            u32 battler1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            u32 battler2 = IsDoubleBattle() ? GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT) : battler1;

            for (chosenMonId = firstId; chosenMonId < PARTY_SIZE; chosenMonId++)
            {
                if (GetMonData(&gPlayerParty[chosenMonId], MON_DATA_HP) != 0
                    && chosenMonId != gBattlerPartyIndexes[battler1]
                    && chosenMonId != gBattlerPartyIndexes[battler2])
                {
                    break;
                }
            }
        }
        *(gBattleStruct->monToSwitchIntoId + battler) = chosenMonId;
    }
    else // Mon to switch out has been already chosen.
    {
        chosenMonId = gBattleStruct->monToSwitchIntoId[battler];
        gBattleStruct->AI_monToSwitchIntoId[battler] = PARTY_SIZE;
        gBattleStruct->monToSwitchIntoId[battler] = chosenMonId;
    }
    BtlController_EmitChosenMonReturnValue(battler, BUFFER_B, chosenMonId, NULL);
    PlayerPartnerBufferExecCompleted(battler);
}

static void PlayerPartnerHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler, FALSE);
}

static void PlayerPartnerHandleIntroTrainerBallThrow(u32 battler)
{
    const u32 *trainerPal;

    if (gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
        trainerPal = gTrainerBackPicPaletteTable[TRAINER_BACK_PIC_STEVEN].data;
    else if (gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER) // Custom multi battle.
        trainerPal = gTrainerBackPicPaletteTable[gPartnerSpriteId].data;
    else if (IsAiVsAiBattle())
        trainerPal = gTrainerFrontPicPaletteTable[gTrainers[gPartnerTrainerId].trainerPic].data;
    else
        trainerPal = gTrainerFrontPicPaletteTable[GetFrontierTrainerFrontSpriteId(gPartnerTrainerId)].data; // 2 vs 2 multi battle in Battle Frontier, load front sprite and pal.

    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F9, trainerPal, 24, Controller_PlayerPartnerShowIntroHealthbox);
}

static void PlayerPartnerHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void PlayerPartnerHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, FALSE, FALSE);
}

static void PlayerPartnerHandleEndLinkBattle(u32 battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    PlayerPartnerBufferExecCompleted(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
