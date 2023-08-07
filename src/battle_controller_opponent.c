#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "constants/battle_ai.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_tv.h"
#include "battle_z_move.h"
#include "bg.h"
#include "data.h"
#include "frontier_util.h"
#include "item.h"
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
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "trainer_hill.h"

static void OpponentHandleLoadMonSprite(void);
static void OpponentHandleSwitchInAnim(void);
static void OpponentHandleDrawTrainerPic(void);
static void OpponentHandleTrainerSlide(void);
static void OpponentHandleTrainerSlideBack(void);
static void OpponentHandleMoveAnimation(void);
static void OpponentHandlePrintString(void);
static void OpponentHandleChooseAction(void);
static void OpponentHandleChooseMove(void);
static void OpponentHandleChooseItem(void);
static void OpponentHandleChoosePokemon(void);
static void OpponentHandleHealthBarUpdate(void);
static void OpponentHandleIntroTrainerBallThrow(void);
static void OpponentHandleDrawPartyStatusSummary(void);
static void OpponentHandleBattleAnimation(void);
static void OpponentHandleEndLinkBattle(void);
static u8 CountAIAliveNonEggMonsExcept(u8 slotToIgnore);

static void OpponentBufferRunCommand(void);
static void OpponentBufferExecCompleted(void);
static void SwitchIn_HandleSoundAndEnd(void);

static void (*const sOpponentBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = OpponentHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = OpponentHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = OpponentHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = OpponentHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = OpponentHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_Empty,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = OpponentHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = OpponentHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_Empty,
    [CONTROLLER_CHOOSEACTION]             = OpponentHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = OpponentHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = OpponentHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = OpponentHandleChoosePokemon,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = OpponentHandleHealthBarUpdate,
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
    [CONTROLLER_INTROTRAINERBALLTHROW]    = OpponentHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = OpponentHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = OpponentHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = OpponentHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToOpponent(void)
{
    gBattlerControllerEndFuncs[gActiveBattler] = OpponentBufferExecCompleted;
    gBattlerControllerFuncs[gActiveBattler] = OpponentBufferRunCommand;
}

static void OpponentBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleResources->bufferA[gActiveBattler][0] < ARRAY_COUNT(sOpponentBufferCommands))
            sOpponentBufferCommands[gBattleResources->bufferA[gActiveBattler][0]]();
        else
            OpponentBufferExecCompleted();
    }
}

static void Intro_DelayAndEnd(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 0;
        OpponentBufferExecCompleted();
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(void)
{
    bool8 healthboxAnimDone = FALSE;
    bool8 twoMons;

    twoMons = TwoOpponentIntroMons(gActiveBattler);
    if (!twoMons || ((twoMons && (gBattleTypeFlags & BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT) || (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)))
    {
        if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
        twoMons = FALSE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
         && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
        twoMons = TRUE;
    }

    gBattleControllerOpponentHealthboxData = &gBattleSpritesDataPtr->healthBoxesData[gActiveBattler];
    gBattleControllerOpponentFlankHealthboxData = &gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)];

    if (healthboxAnimDone)
    {
        if (twoMons == TRUE)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim
             && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim)
            {
                gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim = FALSE;
                FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
                FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
            }
            else
                return;
        }
        else if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim)
        {
            if (GetBattlerPosition(gActiveBattler) == 3)
            {
                if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim
                 && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim)
                {
                    FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
                    FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
                }
                else
                    return;
            }
                gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
                gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;
        }
        else
            return;

        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 3;
        gBattlerControllerFuncs[gActiveBattler] = Intro_DelayAndEnd;
    }
}

static void Intro_TryShinyAnimShowHealthbox(void)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;
    bool32 twoMons;

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim)
        TryShinyAnimation(gActiveBattler, &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]]);

    twoMons = TwoOpponentIntroMons(gActiveBattler);
    if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
     && (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) || BATTLE_TWO_VS_ONE_OPPONENT)
     && twoMons
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].finishedShinyMonAnim)
        TryShinyAnimation(BATTLE_PARTNER(gActiveBattler), &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted)
        {
            if (twoMons && (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) || BATTLE_TWO_VS_ONE_OPPONENT))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)], &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]], HEALTHBOX_ALL);
                StartHealthboxSlideIn(BATTLE_PARTNER(gActiveBattler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(gActiveBattler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
            StartHealthboxSlideIn(gActiveBattler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted = TRUE;
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(gActiveBattler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                if (GetBattlerPosition(gActiveBattler) == 1)
                    m4aMPlayContinue(&gMPlayInfo_BGM);
            }
            else
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    if (!twoMons || (twoMons && gBattleTypeFlags & BATTLE_TYPE_MULTI && !BATTLE_TWO_VS_ONE_OPPONENT))
    {
        if (gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }
    else
    {
        if (gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
            && gSprites[gBattleControllerData[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[BATTLE_PARTNER(gActiveBattler)]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }

    if (bgmRestored && battlerAnimsDone)
    {
        if (twoMons && (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) || BATTLE_TWO_VS_ONE_OPPONENT))
        {
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(gActiveBattler)]]);
            SetBattlerShadowSpriteCallback(BATTLE_PARTNER(gActiveBattler), GetMonData(&gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]], MON_DATA_SPECIES));
        }

        DestroySprite(&gSprites[gBattleControllerData[gActiveBattler]]);
        SetBattlerShadowSpriteCallback(gActiveBattler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES));
        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[gActiveBattler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void TryShinyAnimAfterMonAnim(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].x2 == 0
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim)
        TryShinyAnimation(gActiveBattler, &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]]);

    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        OpponentBufferExecCompleted();
    }
}

static void SwitchIn_ShowSubstitute(void)
{
    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        if (gBattleSpritesDataPtr->battlerData[gActiveBattler].behindSubstitute)
            InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, gActiveBattler, B_ANIM_MON_TO_SUBSTITUTE);
        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_HandleSoundAndEnd;
    }
}

static void SwitchIn_HandleSoundAndEnd(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy
         || gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy_2)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            OpponentBufferExecCompleted();
        }
    }
}

static void SwitchIn_ShowHealthbox(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].finishedShinyMonAnim = FALSE;
        FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
        FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[gActiveBattler]], 0);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_ALL);
        StartHealthboxSlideIn(gActiveBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);
        CopyBattleSpriteInvisibility(gActiveBattler);
        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_ShowSubstitute;
    }
}

static void SwitchIn_TryShinyAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
        TryShinyAnimation(gActiveBattler, &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]]);

    if (gSprites[gBattleControllerData[gActiveBattler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[gActiveBattler]]);
        SetBattlerShadowSpriteCallback(gActiveBattler, GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES));
        gBattlerControllerFuncs[gActiveBattler] = SwitchIn_ShowHealthbox;
    }
}

static void OpponentBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = OpponentBufferRunCommand;
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

static void OpponentHandleLoadMonSprite(void)
{
    BtlController_HandleLoadMonSprite(gActiveBattler, gEnemyParty, TryShinyAnimAfterMonAnim);
}

static void OpponentHandleSwitchInAnim(void)
{
    gBattleStruct->monToSwitchIntoId[gActiveBattler] = PARTY_SIZE;
    BtlController_HandleSwitchInAnim(gActiveBattler, FALSE, SwitchIn_TryShinyAnim);
}

static u32 OpponentGetTrainerPicId(u32 battlerId)
{
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        trainerPicId = GetSecretBaseTrainerPicIndex();
    }
    else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
    {
        trainerPicId = GetFrontierBrainTrainerPicIndex();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (battlerId == 1)
                trainerPicId = GetTrainerHillTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetTrainerHillTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = GetTrainerHillTrainerFrontSpriteId(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
        {
            if (battlerId == 1)
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
            else
                trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_B);
        }
        else
        {
            trainerPicId = GetFrontierTrainerFrontSpriteId(gTrainerBattleOpponent_A);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        trainerPicId = GetEreaderTrainerFrontSpriteId();
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (battlerId != 1)
            trainerPicId = gTrainers[gTrainerBattleOpponent_B].trainerPic;
        else
            trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }
    else
    {
        trainerPicId = gTrainers[gTrainerBattleOpponent_A].trainerPic;
    }

    return trainerPicId;
}

static void OpponentHandleDrawTrainerPic(void)
{
    s16 xPos;
    u32 trainerPicId = OpponentGetTrainerPicId(gActiveBattler);

    if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS) && !BATTLE_TWO_VS_ONE_OPPONENT)
    {
        if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != 0) // second mon
            xPos = 152;
        else // first mon
            xPos = 200;
    }
    else
    {
        xPos = 176;
    }

    BtlController_HandleDrawTrainerPic(gActiveBattler, trainerPicId, TRUE,
                                       xPos, 40 + 4 * (8 - gTrainerFrontPicCoords[trainerPicId].size),
                                       -1);
}

static void OpponentHandleTrainerSlide(void)
{
    u32 trainerPicId = OpponentGetTrainerPicId(gActiveBattler);
    BtlController_HandleTrainerSlide(gActiveBattler, trainerPicId);
}

static void OpponentHandleTrainerSlideBack(void)
{
    BtlController_HandleTrainerSlideBack(gActiveBattler, 35, FALSE);
}

static void OpponentHandleMoveAnimation(void)
{
    BtlController_HandleMoveAnimation(gActiveBattler, FALSE);
}

static void OpponentHandlePrintString(void)
{
    BtlController_HandlePrintString(gActiveBattler, FALSE, TRUE);
}

static void OpponentHandleChooseAction(void)
{
    AI_TrySwitchOrUseItem();
    OpponentBufferExecCompleted();
}

static void OpponentHandleChooseMove(void)
{
    u8 chosenMoveId;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[gActiveBattler][4]);

    if (gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_SAFARI | BATTLE_TYPE_ROAMER)
     || IsWildMonSmart())
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            BtlController_EmitTwoReturnValues(BUFFER_B, 10, ChooseMoveAndTargetInBattlePalace());
        }
        else
        {
            chosenMoveId = gBattleStruct->aiMoveOrAction[gActiveBattler];
            gBattlerTarget = gBattleStruct->aiChosenTarget[gActiveBattler];
            switch (chosenMoveId)
            {
            case AI_CHOICE_WATCH:
                BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SAFARI_WATCH_CAREFULLY, 0);
                break;
            case AI_CHOICE_FLEE:
                BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_RUN, 0);
                break;
            case AI_CHOICE_SWITCH:
                BtlController_EmitTwoReturnValues(BUFFER_B, 10, 0xFFFF);
                break;
            case 6:
                BtlController_EmitTwoReturnValues(BUFFER_B, 15, gBattlerTarget);
                break;
            default:
                {
                    u16 chosenMove = moveInfo->moves[chosenMoveId];

                    if (GetBattlerMoveTargetType(gActiveBattler, chosenMove) & (MOVE_TARGET_USER_OR_SELECTED | MOVE_TARGET_USER))
                        gBattlerTarget = gActiveBattler;
                    if (GetBattlerMoveTargetType(gActiveBattler, chosenMove) & MOVE_TARGET_BOTH)
                    {
                        gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
                        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                            gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
                    }
                    if (ShouldUseZMove(gActiveBattler, gBattlerTarget, chosenMove))
                        QueueZMove(gActiveBattler, chosenMove);
                    if (CanMegaEvolve(gActiveBattler)) // If opponent can mega evolve, do it.
                        BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (RET_MEGA_EVOLUTION) | (gBattlerTarget << 8));
                    else
                        BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (gBattlerTarget << 8));
                }
                break;
            }
        }
        OpponentBufferExecCompleted();
    }
    else // Wild pokemon - use random move
    {
        u16 move;
        u8 target;
        do
        {
            chosenMoveId = Random() & 3;
            move = moveInfo->moves[chosenMoveId];
        } while (move == MOVE_NONE);

        if (GetBattlerMoveTargetType(gActiveBattler, move) & (MOVE_TARGET_USER_OR_SELECTED | MOVE_TARGET_USER))
            BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (gActiveBattler << 8));
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            do {
                target = GetBattlerAtPosition(Random() & 2);
            } while (!CanTargetBattler(gActiveBattler, target, move));

        #if B_WILD_NATURAL_ENEMIES == TRUE
            // Don't bother to loop through table if the move can't attack ally
            if (!(gBattleMoves[move].target & MOVE_TARGET_BOTH))
            {
                u16 i, speciesAttacker, speciesTarget, isPartnerEnemy = FALSE;
                static const u16 naturalEnemies[][2] =
                {
                    // Attacker         Target
                    {SPECIES_ZANGOOSE,  SPECIES_SEVIPER},
                    {SPECIES_SEVIPER,   SPECIES_ZANGOOSE},
                    {SPECIES_HEATMOR,   SPECIES_DURANT},
                    {SPECIES_DURANT,    SPECIES_HEATMOR},
                    {SPECIES_SABLEYE,   SPECIES_CARBINK},
                    {SPECIES_MAREANIE,  SPECIES_CORSOLA},
                };
                speciesAttacker = gBattleMons[gActiveBattler].species;
                speciesTarget = gBattleMons[GetBattlerAtPosition(BATTLE_PARTNER(gActiveBattler))].species;

                for (i = 0; i < ARRAY_COUNT(naturalEnemies); i++)
                {
                    if (speciesAttacker == naturalEnemies[i][0] && speciesTarget == naturalEnemies[i][1])
                    {
                        isPartnerEnemy = TRUE;
                        break;
                    }
                }
                if (isPartnerEnemy && CanTargetBattler(gActiveBattler, target, move))
                    BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (GetBattlerAtPosition(BATTLE_PARTNER(gActiveBattler)) << 8));
                else
                    BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (target << 8));
            }
            else
        #endif
                BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (target << 8));
        }
        else
            BtlController_EmitTwoReturnValues(BUFFER_B, 10, (chosenMoveId) | (GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) << 8));

        OpponentBufferExecCompleted();
    }
}

static void OpponentHandleChooseItem(void)
{
    BtlController_EmitOneReturnValue(BUFFER_B, gBattleStruct->chosenItem[gActiveBattler]);
    OpponentBufferExecCompleted();
}

static void OpponentHandleChoosePokemon(void)
{
    s32 chosenMonId;
    s32 pokemonInBattle = 1;

    // Choosing Revival Blessing target
    if ((gBattleResources->bufferA[gActiveBattler][1] & 0xF) == PARTY_ACTION_CHOOSE_FAINTED_MON)
    {
        chosenMonId = gSelectedMonPartyId = GetFirstFaintedPartyIndex(gActiveBattler);
    }
    // Switching out
    else if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) == PARTY_SIZE)
    {
        chosenMonId = GetMostSuitableMonToSwitchInto();

        if (chosenMonId == PARTY_SIZE)
        {
            s32 battler1, battler2, firstId, lastId;

            if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
            {
                battler2 = battler1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            }
            else
            {
                battler1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                battler2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                pokemonInBattle = 2;

            }

            GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

            for (chosenMonId = (lastId-1); chosenMonId >= firstId; chosenMonId--)
            {
                if (GetMonData(&gEnemyParty[chosenMonId], MON_DATA_HP) != 0
                    && chosenMonId != gBattlerPartyIndexes[battler1]
                    && chosenMonId != gBattlerPartyIndexes[battler2]
                    && (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_ACE_POKEMON)
                        || chosenMonId != CalculateEnemyPartyCount() - 1
                        || CountAIAliveNonEggMonsExcept(PARTY_SIZE) == pokemonInBattle))
                {
                    break;
                }
            }
        }
        *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = chosenMonId;
    }
    else
    {
        chosenMonId = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler);
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = chosenMonId;
    }
    BtlController_EmitChosenMonReturnValue(BUFFER_B, chosenMonId, NULL);
    OpponentBufferExecCompleted();

}

static u8 CountAIAliveNonEggMonsExcept(u8 slotToIgnore)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (i != slotToIgnore
            && GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG)
            && GetMonData(&gEnemyParty[i], MON_DATA_HP) != 0)
        {
            count++;
        }
    }

    return count;
}

static void OpponentHandleHealthBarUpdate(void)
{
    BtlController_HandleHealthBarUpdate(gActiveBattler, FALSE);
}

static void OpponentHandleIntroTrainerBallThrow(void)
{
    BtlController_HandleIntroTrainerBallThrow(gActiveBattler, 0, NULL, 0, Intro_TryShinyAnimShowHealthbox);
}

static void OpponentHandleDrawPartyStatusSummary(void)
{
    BtlController_HandleDrawPartyStatusSummary(gActiveBattler, B_SIDE_OPPONENT, TRUE);
}

static void OpponentHandleBattleAnimation(void)
{
    BtlController_HandleBattleAnimation(gActiveBattler, FALSE, FALSE);
}

static void OpponentHandleEndLinkBattle(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK && !(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
    {
        gMain.inBattle = 0;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
    OpponentBufferExecCompleted();
}
