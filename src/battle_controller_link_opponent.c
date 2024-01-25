#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_tv.h"
#include "bg.h"
#include "data.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "recorded_battle.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "recorded_battle.h"

static void LinkOpponentHandleLoadMonSprite(u32 battler);
static void LinkOpponentHandleSwitchInAnim(u32 battler);
static void LinkOpponentHandleDrawTrainerPic(u32 battler);
static void LinkOpponentHandleTrainerSlide(u32 battler);
static void LinkOpponentHandleTrainerSlideBack(u32 battler);
static void LinkOpponentHandleMoveAnimation(u32 battler);
static void LinkOpponentHandlePrintString(u32 battler);
static void LinkOpponentHandleHealthBarUpdate(u32 battler);
static void LinkOpponentHandleIntroTrainerBallThrow(u32 battler);
static void LinkOpponentHandleDrawPartyStatusSummary(u32 battler);
static void LinkOpponentHandleBattleAnimation(u32 battler);
static void LinkOpponentHandleLinkStandbyMsg(u32 battler);
static void LinkOpponentHandleEndLinkBattle(u32 battler);

static void LinkOpponentBufferRunCommand(u32 battler);
static void LinkOpponentBufferExecCompleted(u32 battler);
static void SwitchIn_HandleSoundAndEnd(u32 battler);

static void (*const sLinkOpponentBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = LinkOpponentHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = LinkOpponentHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = LinkOpponentHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = LinkOpponentHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = LinkOpponentHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_Empty,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = LinkOpponentHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = LinkOpponentHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = BtlController_Empty,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = BtlController_Empty,
    [CONTROLLER_OPENBAG]                  = BtlController_Empty,
    [CONTROLLER_CHOOSEPOKEMON]            = BtlController_Empty,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = LinkOpponentHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = BtlController_Empty,
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
    [CONTROLLER_INTROTRAINERBALLTHROW]    = LinkOpponentHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = LinkOpponentHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = LinkOpponentHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = LinkOpponentHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = LinkOpponentHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToLinkOpponent(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = LinkOpponentBufferExecCompleted;
    gBattlerControllerFuncs[battler] = LinkOpponentBufferRunCommand;
}

static void LinkOpponentBufferRunCommand(u32 battler)
{
    if (gBattleControllerExecFlags & gBitTable[battler])
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sLinkOpponentBufferCommands))
            sLinkOpponentBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            LinkOpponentBufferExecCompleted(battler);
    }
}

static void Intro_DelayAndEnd(u32 battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        LinkOpponentBufferExecCompleted(battler);
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool32 healthboxAnimDone = FALSE;
    bool32 twoMons = FALSE;

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
        twoMons = TRUE;
    }

    if (healthboxAnimDone)
    {
        if (twoMons || !IsBattlerSpriteVisible(BATTLE_PARTNER(battler)))
        {
            if (!gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
                return;
            if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
                return;

            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim = FALSE;

            FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
            FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        }
        else
        {
            if (!gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
                return;

            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

            if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_RIGHT)
            {
                FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
                FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
            }
        }

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = Intro_DelayAndEnd;
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
    {
        TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI)
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
    {
        TryShinyAnimation(BATTLE_PARTNER(battler), &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]);
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], HEALTHBOX_ALL);
                StartHealthboxSlideIn(BATTLE_PARTNER(battler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_LEFT)
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

    if (bgmRestored)
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && GetBattlerPosition(battler) == B_POSITION_OPPONENT_RIGHT)
            {
                if (++gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == 1)
                    return;
                gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
            }

            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
                SetBattlerShadowSpriteCallback(BATTLE_PARTNER(battler), GetMonData(&gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]], MON_DATA_SPECIES));
            }


            DestroySprite(&gSprites[gBattleControllerData[battler]]);
            SetBattlerShadowSpriteCallback(battler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES));

            gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

            gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
        }
    }
}

static void TryShinyAnimAfterMonAnim(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
     && gSprites[gBattlerSpriteIds[battler]].x2 == 0)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
        {
            TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);
        }
        else if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
            FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
            FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
            LinkOpponentBufferExecCompleted(battler);
        }
    }
}

static void SwitchIn_ShowSubstitute(u32 battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[battler] = SwitchIn_HandleSoundAndEnd;
    }
}

static void SwitchIn_HandleSoundAndEnd(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
            || gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy_2)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            LinkOpponentBufferExecCompleted(battler);
        }
    }
}

static void SwitchIn_ShowHealthbox(u32 battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;

        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);

        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        CopyBattleSpriteInvisibility(battler);
        gBattlerControllerFuncs[battler] = SwitchIn_ShowSubstitute;
    }
}

static void SwitchIn_TryShinyAnim(u32 battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
        && !gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
    {
        TryShinyAnimation(battler, &gEnemyParty[gBattlerPartyIndexes[battler]]);
    }

    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);
        SetBattlerShadowSpriteCallback(battler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES));
        gBattlerControllerFuncs[battler] = SwitchIn_ShowHealthbox;
    }
}

static void LinkOpponentBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = LinkOpponentBufferRunCommand;
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

static void LinkOpponentHandleLoadMonSprite(u32 battler)
{
    BtlController_HandleLoadMonSprite(battler, TryShinyAnimAfterMonAnim);
}

static void LinkOpponentHandleSwitchInAnim(u32 battler)
{
    BtlController_HandleSwitchInAnim(battler, FALSE, SwitchIn_TryShinyAnim);
}

static void LinkOpponentHandleDrawTrainerPic(u32 battler)
{
    s16 xPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBattlerPosition(battler) & BIT_FLANK) != 0) // second mon
            xPos = 152;
        else // first mon
            xPos = 200;

        if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        {
            if (battler == B_POSITION_OPPONENT_LEFT)
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            if ((gLinkPlayers[GetBattlerMultiplayerId(battler)].version & 0xFF) == VERSION_FIRE_RED
            || (gLinkPlayers[GetBattlerMultiplayerId(battler)].version & 0xFF) == VERSION_LEAF_GREEN)
            {
                if (gLinkPlayers[GetBattlerMultiplayerId(battler)].gender != MALE)
                    trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_LEAF];
                else
                    trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RED];
            }
            else if ((gLinkPlayers[GetBattlerMultiplayerId(battler)].version & 0xFF) == VERSION_RUBY
                     || (gLinkPlayers[GetBattlerMultiplayerId(battler)].version & 0xFF) == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[GetBattlerMultiplayerId(battler)].gender != MALE)
                    trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RS_MAY];
                else
                    trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RS_BRENDAN];
            }
            else
            {
                trainerPicId = PlayerGenderToFrontTrainerPicId(gLinkPlayers[GetBattlerMultiplayerId(battler)].gender);
            }
        }
    }
    else
    {
        xPos = 176;
        if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
        {
            trainerPicId = GetUnionRoomTrainerPic();
        }
        else if ((gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_FIRE_RED
                 || (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_LEAF_GREEN)
        {
            if (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender != MALE)
                trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_LEAF];
            else
                trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RED];
        }
        else if ((gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_RUBY
                 || (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].version & 0xFF) == VERSION_SAPPHIRE)
        {
            if (gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender != MALE)
                trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RS_MAY];
            else
                trainerPicId = gFacilityClassToPicIndex[FACILITY_CLASS_RS_BRENDAN];
        }
        else
        {
            trainerPicId = PlayerGenderToFrontTrainerPicId(gLinkPlayers[GetMultiplayerId() ^ BIT_SIDE].gender);
        }
    }

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, TRUE,
                                       xPos, 40 + 4 * (8 - gTrainerFrontPicCoords[trainerPicId].size),
                                       -1);
}

static void LinkOpponentHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId;

    if (battler == B_POSITION_OPPONENT_LEFT)
        trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
    else
        trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);

    BtlController_HandleTrainerSlide(battler, trainerPicId);
    LinkOpponentBufferExecCompleted(battler); // Possibly a bug, because execution should be completed after the slide in finishes. See Controller_WaitForTrainerPic.
}

static void LinkOpponentHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 35, FALSE);
}

static void LinkOpponentHandleMoveAnimation(u32 battler)
{
    BtlController_HandleMoveAnimation(battler, TRUE);
}

static void LinkOpponentHandlePrintString(u32 battler)
{
    BtlController_HandlePrintString(battler, TRUE, FALSE);
}

static void LinkOpponentHandleHealthBarUpdate(u32 battler)
{
    BtlController_HandleHealthBarUpdate(battler, FALSE);
}

static void LinkOpponentHandleIntroTrainerBallThrow(u32 battler)
{
    BtlController_HandleIntroTrainerBallThrow(battler, 0, NULL, 0, Intro_TryShinyAnimShowHealthbox);
}

static void LinkOpponentHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_OPPONENT, TRUE);
}

static void LinkOpponentHandleBattleAnimation(u32 battler)
{
    BtlController_HandleBattleAnimation(battler, FALSE, TRUE);
}

static void LinkOpponentHandleLinkStandbyMsg(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][2]);
    LinkOpponentBufferExecCompleted(battler);
}

static void LinkOpponentHandleEndLinkBattle(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][4]);

    if (gBattleResources->bufferA[battler][1] == B_OUTCOME_DREW)
        gBattleOutcome = gBattleResources->bufferA[battler][1];
    else
        gBattleOutcome = gBattleResources->bufferA[battler][1] ^ B_OUTCOME_DREW;

    gSaveBlock2Ptr->frontier.disableRecordBattle = gBattleResources->bufferA[battler][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    LinkOpponentBufferExecCompleted(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}
