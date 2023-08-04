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

static void LinkPartnerHandleGetMonData(void);
static void LinkPartnerHandleGetRawMonData(void);
static void LinkPartnerHandleSetMonData(void);
static void LinkPartnerHandleSetRawMonData(void);
static void LinkPartnerHandleLoadMonSprite(void);
static void LinkPartnerHandleSwitchInAnim(void);
static void LinkPartnerHandleReturnMonToBall(void);
static void LinkPartnerHandleDrawTrainerPic(void);
static void LinkPartnerHandleTrainerSlide(void);
static void LinkPartnerHandleTrainerSlideBack(void);
static void LinkPartnerHandleFaintAnimation(void);
static void LinkPartnerHandlePaletteFade(void);
static void LinkPartnerHandleSuccessBallThrowAnim(void);
static void LinkPartnerHandleBallThrowAnim(void);
static void LinkPartnerHandlePause(void);
static void LinkPartnerHandleMoveAnimation(void);
static void LinkPartnerHandlePrintString(void);
static void LinkPartnerHandlePrintSelectionString(void);
static void LinkPartnerHandleChooseAction(void);
static void LinkPartnerHandleYesNoBox(void);
static void LinkPartnerHandleChooseMove(void);
static void LinkPartnerHandleChooseItem(void);
static void LinkPartnerHandleChoosePokemon(void);
static void LinkPartnerHandleCmd23(void);
static void LinkPartnerHandleHealthBarUpdate(void);
static void LinkPartnerHandleExpUpdate(void);
static void LinkPartnerHandleStatusIconUpdate(void);
static void LinkPartnerHandleStatusAnimation(void);
static void LinkPartnerHandleStatusXor(void);
static void LinkPartnerHandleDataTransfer(void);
static void LinkPartnerHandleDMA3Transfer(void);
static void LinkPartnerHandlePlayBGM(void);
static void LinkPartnerHandleCmd32(void);
static void LinkPartnerHandleTwoReturnValues(void);
static void LinkPartnerHandleChosenMonReturnValue(void);
static void LinkPartnerHandleOneReturnValue(void);
static void LinkPartnerHandleOneReturnValue_Duplicate(void);
static void LinkPartnerHandleClearUnkVar(void);
static void LinkPartnerHandleSetUnkVar(void);
static void LinkPartnerHandleClearUnkFlag(void);
static void LinkPartnerHandleToggleUnkFlag(void);
static void LinkPartnerHandleHitAnimation(void);
static void LinkPartnerHandleCantSwitch(void);
static void LinkPartnerHandlePlaySE(void);
static void LinkPartnerHandlePlayFanfareOrBGM(void);
static void LinkPartnerHandleFaintingCry(void);
static void LinkPartnerHandleIntroSlide(void);
static void LinkPartnerHandleIntroTrainerBallThrow(void);
static void LinkPartnerHandleDrawPartyStatusSummary(void);
static void LinkPartnerHandleHidePartyStatusSummary(void);
static void LinkPartnerHandleEndBounceEffect(void);
static void LinkPartnerHandleSpriteInvisibility(void);
static void LinkPartnerHandleBattleAnimation(void);
static void LinkPartnerHandleLinkStandbyMsg(void);
static void LinkPartnerHandleResetActionMoveSelection(void);
static void LinkPartnerHandleEndLinkBattle(void);
static void LinkPartnerHandleBattleDebug(void);
static void LinkPartnerCmdEnd(void);

static void LinkPartnerBufferRunCommand(void);
static void LinkPartnerBufferExecCompleted(void);
static void SwitchIn_WaitAndEnd(void);
static u32 CopyLinkPartnerMonData(u8 monId, u8 *dst);
static void SetLinkPartnerMonData(u8 monId);
static void DoSwitchOutAnimation(void);
static void LinkPartnerDoMoveAnimation(void);
static void Task_StartSendOutAnim(u8 taskId);
static void EndDrawPartyStatusSummary(void);

static void (*const sLinkPartnerBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    [CONTROLLER_GETMONDATA]               = LinkPartnerHandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = LinkPartnerHandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = LinkPartnerHandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = LinkPartnerHandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = LinkPartnerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = LinkPartnerHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = LinkPartnerHandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = LinkPartnerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = LinkPartnerHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = LinkPartnerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = LinkPartnerHandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = LinkPartnerHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = LinkPartnerHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = LinkPartnerHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = LinkPartnerHandlePause,
    [CONTROLLER_MOVEANIMATION]            = LinkPartnerHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = LinkPartnerHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = LinkPartnerHandlePrintSelectionString,
    [CONTROLLER_CHOOSEACTION]             = LinkPartnerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = LinkPartnerHandleYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = LinkPartnerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = LinkPartnerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = LinkPartnerHandleChoosePokemon,
    [CONTROLLER_23]                       = LinkPartnerHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = LinkPartnerHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = LinkPartnerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = LinkPartnerHandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = LinkPartnerHandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = LinkPartnerHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = LinkPartnerHandleDataTransfer,
    [CONTROLLER_DMA3TRANSFER]             = LinkPartnerHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = LinkPartnerHandlePlayBGM,
    [CONTROLLER_32]                       = LinkPartnerHandleCmd32,
    [CONTROLLER_TWORETURNVALUES]          = LinkPartnerHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = LinkPartnerHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = LinkPartnerHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = LinkPartnerHandleOneReturnValue_Duplicate,
    [CONTROLLER_CLEARUNKVAR]              = LinkPartnerHandleClearUnkVar,
    [CONTROLLER_SETUNKVAR]                = LinkPartnerHandleSetUnkVar,
    [CONTROLLER_CLEARUNKFLAG]             = LinkPartnerHandleClearUnkFlag,
    [CONTROLLER_TOGGLEUNKFLAG]            = LinkPartnerHandleToggleUnkFlag,
    [CONTROLLER_HITANIMATION]             = LinkPartnerHandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = LinkPartnerHandleCantSwitch,
    [CONTROLLER_PLAYSE]                   = LinkPartnerHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = LinkPartnerHandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = LinkPartnerHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = LinkPartnerHandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = LinkPartnerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = LinkPartnerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = LinkPartnerHandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = LinkPartnerHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = LinkPartnerHandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = LinkPartnerHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = LinkPartnerHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = LinkPartnerHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = LinkPartnerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = LinkPartnerHandleBattleDebug,
    [CONTROLLER_TERMINATOR_NOP]           = LinkPartnerCmdEnd
};

static void SpriteCB_Null2(void)
{
}

void SetControllerToLinkPartner(void)
{
    gBattlerControllerFuncs[gActiveBattler] = LinkPartnerBufferRunCommand;
}

static void LinkPartnerBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleResources->bufferA[gActiveBattler][0] < ARRAY_COUNT(sLinkPartnerBufferCommands))
            sLinkPartnerBufferCommands[gBattleResources->bufferA[gActiveBattler][0]]();
        else
            LinkPartnerBufferExecCompleted();
    }
}

static void CompleteOnBattlerSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        LinkPartnerBufferExecCompleted();
}

static void FreeTrainerSpriteAfterSlide(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
    {
        BattleGfxSfxDummy3(MALE);
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        LinkPartnerBufferExecCompleted();
    }
}

static void Intro_DelayAndEnd(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].introEndDelay = 0;
        LinkPartnerBufferExecCompleted();
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

static void Intro_ShowHealthbox(void)
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
        LinkPartnerBufferExecCompleted();
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
        LinkPartnerBufferExecCompleted();
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
        LinkPartnerBufferExecCompleted();
    }
}

static void FreeMonSpriteAfterSwitchOutAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        DestroySprite(&gSprites[gBattlerSpriteIds[gActiveBattler]]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
        LinkPartnerBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(B_WIN_MSG))
        LinkPartnerBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBattlerSpriteIds[gActiveBattler];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = FALSE;
        gDoingBattleAnim = FALSE;
        LinkPartnerBufferExecCompleted();
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
        LinkPartnerBufferExecCompleted();
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

static void LinkPartnerBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = LinkPartnerBufferRunCommand;
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
        LinkPartnerBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animFromTableActive)
        LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleGetMonData(void)
{
    BtlController_HandleGetMonData(gActiveBattler, gPlayerParty, LinkPartnerBufferExecCompleted);
}

static void LinkPartnerHandleGetRawMonData(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSetMonData(void)
{
    BtlController_HandleSetMonData(gActiveBattler, gPlayerParty, LinkPartnerBufferExecCompleted);
}

static void LinkPartnerHandleSetRawMonData(void)
{
    BtlController_HandleSetRawMonData(gActiveBattler, gPlayerParty, LinkPartnerBufferExecCompleted);
}

static void LinkPartnerHandleLoadMonSprite(void)
{
    BtlController_HandleLoadMonSprite(gActiveBattler, gPlayerParty, WaitForMonAnimAfterLoad);
}

static void LinkPartnerHandleSwitchInAnim(void)
{
    BtlController_HandleSwitchInAnim(gActiveBattler, TRUE, SwitchIn_TryShinyAnim);
}

static void LinkPartnerHandleReturnMonToBall(void)
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
        LinkPartnerBufferExecCompleted();
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

static void LinkPartnerHandleDrawTrainerPic(void)
{
    s16 xPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != 0) // second mon
            xPos = 90;
        else // first mon
            xPos = 32;
    }
    else
    {
        xPos = 80;
    }

    if ((gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_FIRE_RED
        || (gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_LEAF_GREEN)
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender + TRAINER_BACK_PIC_RED;
    }
    else if ((gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_RUBY
             || (gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_SAPPHIRE)
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender + TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN;
    }
    else
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender;
    }

    DecompressTrainerBackPic(trainerPicId, gActiveBattler);
    SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate, xPos, (8 - gTrainerBackPicCoords[trainerPicId].size) * 4 + 80, GetBattlerSpriteSubpriority(gActiveBattler));

    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = DISPLAY_WIDTH;
    gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = -2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;

    gBattlerControllerFuncs[gActiveBattler] = CompleteOnBattlerSpriteCallbackDummy;
}

#undef sSpeedX

static void LinkPartnerHandleTrainerSlide(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleTrainerSlideBack(void)
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

static void LinkPartnerHandleFaintAnimation(void)
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
            PlaySE12WithPanning(SE_FAINT, SOUND_PAN_ATTACKER);
            gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedX = 0;
            gSprites[gBattlerSpriteIds[gActiveBattler]].sSpeedY = 5;
            gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_FaintSlideAnim;
            gBattlerControllerFuncs[gActiveBattler] = FreeMonSpriteAfterFaintAnim;
        }
    }
}

#undef sSpeedX
#undef sSpeedY

static void LinkPartnerHandlePaletteFade(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSuccessBallThrowAnim(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleBallThrowAnim(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePause(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleMoveAnimation(void)
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
        gBattlerControllerFuncs[gActiveBattler] = LinkPartnerDoMoveAnimation;
        BattleTv_SetDataBasedOnMove(move, gWeatherMoveAnim, gAnimDisableStructPtr);
    }
}

static void LinkPartnerDoMoveAnimation(void)
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
            LinkPartnerBufferExecCompleted();
        }
        break;
    }
}

static void LinkPartnerHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16 *)(&gBattleResources->bufferA[gActiveBattler][2]);
    BufferStringBattle(*stringId);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnInactiveTextPrinter;
    BattleTv_SetDataBasedOnString(*stringId);
}

static void LinkPartnerHandlePrintSelectionString(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseAction(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleYesNoBox(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseMove(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChooseItem(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChoosePokemon(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd23(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_MAX_HP);
        u32 curHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_HP);

        SetBattleBarStruct(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], maxHP, curHP, hpVal);
    }
    else
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_MAX_HP);

        SetBattleBarStruct(gActiveBattler, gHealthboxSpriteIds[gActiveBattler], maxHP, 0, hpVal);
    }

    gBattlerControllerFuncs[gActiveBattler] = CompleteOnHealthbarDone;
}

static void LinkPartnerHandleExpUpdate(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleStatusIconUpdate(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        u8 battlerId;

        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_STATUS_ICON);
        battlerId = gActiveBattler;
        gBattleSpritesDataPtr->healthBoxesData[battlerId].statusAnimActive = 0;
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedStatusAnimation;
    }
}

static void LinkPartnerHandleStatusAnimation(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        InitAndLaunchChosenStatusAnimation(gBattleResources->bufferA[gActiveBattler][1],
                        gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8) | (gBattleResources->bufferA[gActiveBattler][4] << 16) | (gBattleResources->bufferA[gActiveBattler][5] << 24));
        gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedStatusAnimation;
    }
}

static void LinkPartnerHandleStatusXor(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleDataTransfer(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleDMA3Transfer(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePlayBGM(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleCmd32(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleTwoReturnValues(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleChosenMonReturnValue(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleOneReturnValue(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleOneReturnValue_Duplicate(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleClearUnkVar(void)
{
    gUnusedControllerStruct.unk = 0;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSetUnkVar(void)
{
    gUnusedControllerStruct.unk = gBattleResources->bufferA[gActiveBattler][1];
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleClearUnkFlag(void)
{
    gUnusedControllerStruct.flag = 0;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleToggleUnkFlag(void)
{
    gUnusedControllerStruct.flag ^= 1;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleHitAnimation(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].invisible == TRUE)
    {
        LinkPartnerBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBattlerSpriteIds[gActiveBattler]].data[1] = 0;
        DoHitAnimHealthboxEffect(gActiveBattler);
        gBattlerControllerFuncs[gActiveBattler] = DoHitAnimBlinkSpriteEffect;
    }
}

static void LinkPartnerHandleCantSwitch(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePlaySE(void)
{
    s8 pan;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        pan = SOUND_PAN_ATTACKER;
    else
        pan = SOUND_PAN_TARGET;

    PlaySE12WithPanning(gBattleResources->bufferA[gActiveBattler][1] | (gBattleResources->bufferA[gActiveBattler][2] << 8), pan);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandlePlayFanfareOrBGM(void)
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

    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry_ByMode(species, -25, CRY_MODE_FAINT);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleResources->bufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleIntroTrainerBallThrow(void)
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

    if ((gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_FIRE_RED
        || (gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_LEAF_GREEN)
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender + TRAINER_BACK_PIC_RED;
    }
    else if ((gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_RUBY
             || (gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].version & 0xFF) == VERSION_SAPPHIRE)
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender + TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN;
    }
    else
    {
        trainerPicId = gLinkPlayers[GetBattlerMultiplayerId(gActiveBattler)].gender;
    }

    LoadCompressedPalette(gTrainerBackPicPaletteTable[trainerPicId].data, OBJ_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);

    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = paletteNum;

    taskId = CreateTask(Task_StartSendOutAnim, 5);
    gTasks[taskId].data[0] = gActiveBattler;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[gActiveBattler]].func = Task_HidePartyStatusSummary;

    gBattleSpritesDataPtr->animationData->introAnimActive = TRUE;
    gBattlerControllerFuncs[gActiveBattler] = SpriteCB_Null2;
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
        gBattlerControllerFuncs[gActiveBattler] = Intro_ShowHealthbox;
        gActiveBattler = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void LinkPartnerHandleDrawPartyStatusSummary(void)
{
    if (gBattleResources->bufferA[gActiveBattler][1] != 0 && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
    {
        LinkPartnerBufferExecCompleted();
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
        LinkPartnerBufferExecCompleted();
    }
}

static void LinkPartnerHandleHidePartyStatusSummary(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[gActiveBattler]].func = Task_HidePartyStatusSummary;
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleEndBounceEffect(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleSpriteInvisibility(void)
{
    if (IsBattlerSpritePresent(gActiveBattler))
    {
        gSprites[gBattlerSpriteIds[gActiveBattler]].invisible = gBattleResources->bufferA[gActiveBattler][1];
        CopyBattleSpriteInvisibility(gActiveBattler);
    }
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleBattleAnimation(void)
{
    if (!IsBattleSEPlaying(gActiveBattler))
    {
        u8 animationId = gBattleResources->bufferA[gActiveBattler][1];
        u16 argument = gBattleResources->bufferA[gActiveBattler][2] | (gBattleResources->bufferA[gActiveBattler][3] << 8);

        if (TryHandleLaunchBattleTableAnimation(gActiveBattler, gActiveBattler, gActiveBattler, animationId, argument))
            LinkPartnerBufferExecCompleted();
        else
            gBattlerControllerFuncs[gActiveBattler] = CompleteOnFinishedBattleAnimation;

        BattleTv_SetDataBasedOnAnimation(animationId);
    }
}

static void LinkPartnerHandleLinkStandbyMsg(void)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[gActiveBattler][2]);
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleResetActionMoveSelection(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerHandleEndLinkBattle(void)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[gActiveBattler][4]);
    gBattleOutcome = gBattleResources->bufferA[gActiveBattler][1];
    gSaveBlock2Ptr->frontier.disableRecordBattle = gBattleResources->bufferA[gActiveBattler][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    LinkPartnerBufferExecCompleted();
    gBattlerControllerFuncs[gActiveBattler] = SetBattleEndCallbacks;
}

static void LinkPartnerHandleBattleDebug(void)
{
    LinkPartnerBufferExecCompleted();
}

static void LinkPartnerCmdEnd(void)
{
}
