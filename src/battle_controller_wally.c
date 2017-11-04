#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "battle_link_817C95C.h"
#include "pokemon.h"
#include "link.h"
#include "util.h"
#include "main.h"
#include "item.h"
#include "items.h"
#include "songs.h"
#include "sound.h"
#include "moves.h"
#include "window.h"
#include "m4a.h"
#include "palette.h"
#include "task.h"
#include "text.h"
#include "string_util.h"
#include "bg.h"
#include "reshow_battle_screen.h"
#include "rng.h"
#include "pokeball.h"
#include "data2.h"
#include "party_menu.h"

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gAbsentBankFlags;
extern u8 gNoOfAllBanks;
extern bool8 gDoingBattleAnim;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gMultiUsePlayerCursor;
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlay_BGM;
extern u16 gPartnerTrainerId;
extern struct SpriteTemplate gUnknown_0202499C;
extern u8 gBattleMonForms[BATTLE_BANKS_COUNT];
extern u16 gScriptItemId;
extern u8 gUnknown_03005D7C[BATTLE_BANKS_COUNT];
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];
extern u8 gBattleOutcome;
extern u8 gNumberOfMovesToChoose;
extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern s32 gUnknown_0203CD70;
extern u8 gBankInMenu;
extern u32 gBattlePalaceMoveSelectionRngValue;
extern u32 gTransformedPersonalities[BATTLE_BANKS_COUNT];
extern u8 gUnknown_020244B4[];
extern u16 gUnknown_020243FC;
extern struct UnusedControllerStruct gUnknown_02022D0C;

extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];

extern const u8 gText_WhatWillWallyDo[];
extern const u8 gText_BattleMenu[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_806A068(u16, u8);

// this file's functions
static void WallyHandleGetMonData(void);
static void WallyHandleGetRawMonData(void);
static void WallyHandleSetMonData(void);
static void WallyHandleSetRawMonData(void);
static void WallyHandleLoadMonSprite(void);
static void WallyHandleSwitchInAnim(void);
static void WallyHandleReturnMonToBall(void);
static void WallyHandleDrawTrainerPic(void);
static void WallyHandleTrainerSlide(void);
static void WallyHandleTrainerSlideBack(void);
static void WallyHandleFaintAnimation(void);
static void WallyHandlePaletteFade(void);
static void WallyHandleSuccessBallThrowAnim(void);
static void WallyHandleBallThrowAnim(void);
static void WallyHandlePause(void);
static void WallyHandleMoveAnimation(void);
static void WallyHandlePrintString(void);
static void WallyHandlePrintStringPlayerOnly(void);
static void WallyHandleChooseAction(void);
static void WallyHandleUnknownYesNoBox(void);
static void WallyHandleChooseMove(void);
static void WallyHandleChooseItem(void);
static void WallyHandleChoosePokemon(void);
static void WallyHandleCmd23(void);
static void WallyHandleHealthBarUpdate(void);
static void WallyHandleExpUpdate(void);
static void WallyHandleStatusIconUpdate(void);
static void WallyHandleStatusAnimation(void);
static void WallyHandleStatusXor(void);
static void WallyHandleDataTransfer(void);
static void WallyHandleDMA3Transfer(void);
static void WallyHandlePlayBGM(void);
static void WallyHandleCmd32(void);
static void WallyHandleTwoReturnValues(void);
static void WallyHandleChosenMonReturnValue(void);
static void WallyHandleOneReturnValue(void);
static void WallyHandleOneReturnValue_Duplicate(void);
static void WallyHandleCmd37(void);
static void WallyHandleCmd38(void);
static void WallyHandleCmd39(void);
static void WallyHandleCmd40(void);
static void WallyHandleHitAnimation(void);
static void WallyHandleCmd42(void);
static void WallyHandleEffectivenessSound(void);
static void WallyHandlePlayFanfareOrBGM(void);
static void WallyHandleFaintingCry(void);
static void WallyHandleIntroSlide(void);
static void WallyHandleIntroTrainerBallThrow(void);
static void WallyHandleDrawPartyStatusSummary(void);
static void WallyHandleCmd49(void);
static void WallyHandleCmd50(void);
static void WallyHandleSpriteInvisibility(void);
static void WallyHandleBattleAnimation(void);
static void WallyHandleLinkStandbyMsg(void);
static void WallyHandleResetActionMoveSelection(void);
static void WallyHandleCmd55(void);
static void nullsub_118(void);

static void WallyBufferRunCommand(void);
static void WallyBufferExecCompleted(void);
static void CompleteOnChosenItem(void);
static void sub_8168818(void);
static u32 CopyWallyMonData(u8 monId, u8 *dst);
static void SetWallyMonData(u8 monId);
static void WallyDoMoveAnimation(void);
static void sub_816AC04(u8 taskId);

static void (*const sWallyBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    WallyHandleGetMonData,
    WallyHandleGetRawMonData,
    WallyHandleSetMonData,
    WallyHandleSetRawMonData,
    WallyHandleLoadMonSprite,
    WallyHandleSwitchInAnim,
    WallyHandleReturnMonToBall,
    WallyHandleDrawTrainerPic,
    WallyHandleTrainerSlide,
    WallyHandleTrainerSlideBack,
    WallyHandleFaintAnimation,
    WallyHandlePaletteFade,
    WallyHandleSuccessBallThrowAnim,
    WallyHandleBallThrowAnim,
    WallyHandlePause,
    WallyHandleMoveAnimation,
    WallyHandlePrintString,
    WallyHandlePrintStringPlayerOnly,
    WallyHandleChooseAction,
    WallyHandleUnknownYesNoBox,
    WallyHandleChooseMove,
    WallyHandleChooseItem,
    WallyHandleChoosePokemon,
    WallyHandleCmd23,
    WallyHandleHealthBarUpdate,
    WallyHandleExpUpdate,
    WallyHandleStatusIconUpdate,
    WallyHandleStatusAnimation,
    WallyHandleStatusXor,
    WallyHandleDataTransfer,
    WallyHandleDMA3Transfer,
    WallyHandlePlayBGM,
    WallyHandleCmd32,
    WallyHandleTwoReturnValues,
    WallyHandleChosenMonReturnValue,
    WallyHandleOneReturnValue,
    WallyHandleOneReturnValue_Duplicate,
    WallyHandleCmd37,
    WallyHandleCmd38,
    WallyHandleCmd39,
    WallyHandleCmd40,
    WallyHandleHitAnimation,
    WallyHandleCmd42,
    WallyHandleEffectivenessSound,
    WallyHandlePlayFanfareOrBGM,
    WallyHandleFaintingCry,
    WallyHandleIntroSlide,
    WallyHandleIntroTrainerBallThrow,
    WallyHandleDrawPartyStatusSummary,
    WallyHandleCmd49,
    WallyHandleCmd50,
    WallyHandleSpriteInvisibility,
    WallyHandleBattleAnimation,
    WallyHandleLinkStandbyMsg,
    WallyHandleResetActionMoveSelection,
    WallyHandleCmd55,
    nullsub_118
};

static void nullsub_117(void)
{
}

void SetControllerToWally(void)
{
    gBattleBankFunc[gActiveBank] = WallyBufferRunCommand;
    gBattleStruct->wallyBattleState = 0;
    gBattleStruct->wallyMovesState = 0;
    gBattleStruct->wallyWaitFrames = 0;
    gBattleStruct->wallyMoveFrames = 0;
}

static void WallyBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(sWallyBufferCommands))
            sWallyBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            WallyBufferExecCompleted();
    }
}

static void WallyHandleActions(void)
{
    switch (gBattleStruct->wallyBattleState)
    {
    case 0:
        gBattleStruct->wallyWaitFrames = 64;
        gBattleStruct->wallyBattleState++;
    case 1:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            EmitTwoReturnValues(1, ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            EmitTwoReturnValues(1, ACTION_USE_MOVE, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 3:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            EmitTwoReturnValues(1, 9, 0);
            WallyBufferExecCompleted();
            gBattleStruct->wallyBattleState++;
            gBattleStruct->wallyMovesState = 0;
            gBattleStruct->wallyWaitFrames = 64;
        }
        break;
    case 4:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(0);
            ActionSelectionCreateCursorAt(1, 0);
            gBattleStruct->wallyWaitFrames = 64;
            gBattleStruct->wallyBattleState++;
        }
        break;
    case 5:
        if (--gBattleStruct->wallyWaitFrames == 0)
        {
            PlaySE(SE_SELECT);
            EmitTwoReturnValues(1, ACTION_USE_ITEM, 0);
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        WallyBufferExecCompleted();
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        WallyBufferExecCompleted();
}

static void CompleteOnFinishedAnimation(void)
{
    if (!gDoingBattleAnim)
        WallyBufferExecCompleted();
}

static void OpenBagAfterPaletteFade(void)
{
    if (!gPaletteFade.active)
    {
        gBattleBankFunc[gActiveBank] = CompleteOnChosenItem;
        nullsub_35();
        FreeAllWindowBuffers();
        DoWallyTutorialBagMenu();
    }
}

static void CompleteOnChosenItem(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        EmitOneReturnValue(1, gScriptItemId);
        WallyBufferExecCompleted();
    }
}

static void sub_816864C(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
        sub_8172EF0(gActiveBank, &gPlayerParty[gBattlePartyID[gActiveBank]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8)
        sub_8172EF0(gActiveBank ^ BIT_MON, &gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8
        && gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
        && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]]);
            UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank ^ BIT_MON], &gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]], HEALTHBOX_ALL);
            sub_8076918(gActiveBank ^ BIT_MON);
            SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank ^ BIT_MON]);
        }
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
        sub_8076918(gActiveBank);
        SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);

        gBattleSpritesDataPtr->animationData->field_9_x1 = 0;
        gBattleBankFunc[gActiveBank] = sub_8168818;
    }

}

static void sub_8168818(void)
{
    bool32 r4 = FALSE;

    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
        r4 = TRUE;

    if (r4 && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1 = 0;

        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        CreateTask(c3_0802FDF4, 10);
        HandleLowHpMusicChange(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);

        WallyBufferExecCompleted();
    }
}

static void CompleteOnHealthbarDone(void)
{
    s16 hpValue = sub_8074AA0(gActiveBank, gHealthBoxesIds[gActiveBank], HEALTH_BAR, 0);

    SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);

    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthBoxesIds[gActiveBank], hpValue, HP_CURRENT);
    }
    else
    {
        HandleLowHpMusicChange(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        WallyBufferExecCompleted();
    }
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data1 == 32)
    {
        gSprites[spriteId].data1 = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        WallyBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data1 % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data1++;
    }
}

static void sub_8168A20(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        WallyBufferExecCompleted();
    }
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        WallyBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        WallyBufferExecCompleted();
}

static void WallyBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = WallyBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBank][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleExecBuffer &= ~gBitTable[gActiveBank];
    }
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        WallyBufferExecCompleted();
}

static void WallyHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += CopyWallyMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                size += CopyWallyMonData(i, monData + size);
            monToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    WallyBufferExecCompleted();
}

static u32 CopyWallyMonData(u8 monId, u8 *dst)
{
    struct BattlePokemon battleMon;
    struct MovePpInfo moveData;
    u8 nickname[20];
    u8 *src;
    s16 data16;
    u32 data32;
    s32 size = 0;

    switch (gBattleBufferA[gActiveBank][1])
    {
    case REQUEST_ALL_BATTLE:
        battleMon.species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        battleMon.item = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
        for (size = 0; size < 4; size++)
        {
            battleMon.moves[size] = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + size);
            battleMon.pp[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        }
        battleMon.ppBonuses = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        battleMon.friendship = GetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP);
        battleMon.experience = GetMonData(&gPlayerParty[monId], MON_DATA_EXP);
        battleMon.hpIV = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        battleMon.attackIV = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        battleMon.defenseIV = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        battleMon.speedIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV);
        battleMon.spAttackIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        battleMon.spDefenseIV = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        battleMon.personality = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
        battleMon.status1 = GetMonData(&gPlayerParty[monId], MON_DATA_STATUS);
        battleMon.level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
        battleMon.hp = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
        battleMon.maxHP = GetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP);
        battleMon.attack = GetMonData(&gPlayerParty[monId], MON_DATA_ATK);
        battleMon.defense = GetMonData(&gPlayerParty[monId], MON_DATA_DEF);
        battleMon.speed = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED);
        battleMon.spAttack = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK);
        battleMon.spDefense = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF);
        battleMon.isEgg = GetMonData(&gPlayerParty[monId], MON_DATA_IS_EGG);
        battleMon.altAbility = GetMonData(&gPlayerParty[monId], MON_DATA_ALT_ABILITY);
        battleMon.otId = GetMonData(&gPlayerParty[monId], MON_DATA_OT_ID);
        GetMonData(&gPlayerParty[monId], MON_DATA_NICKNAME, nickname);
        StringCopy10(battleMon.nickname, nickname);
        GetMonData(&gPlayerParty[monId], MON_DATA_OT_NAME, battleMon.otName);
        src = (u8 *)&battleMon;
        for (size = 0; size < sizeof(battleMon); size++)
            dst[size] = src[size];
        break;
    case REQUEST_SPECIES_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_HELDITEM_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (size = 0; size < 4; size++)
        {
            moveData.moves[size] = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + size);
            moveData.pp[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        }
        moveData.ppBonuses = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        src = (u8*)(&moveData);
        for (size = 0; size < sizeof(moveData); size++)
            dst[size] = src[size];
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_PP_DATA_BATTLE:
        for (size = 0; size < 4; size++)
            dst[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + size);
        dst[size] = GetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES);
        size++;
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE);
        size = 1;
        break;
    case REQUEST_OTID_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_OT_ID);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_EXP_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_EXP);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_HP_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_EV);
        size = 1;
        break;
    case REQUEST_ATK_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_EV);
        size = 1;
        break;
    case REQUEST_DEF_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_EV);
        size = 1;
        break;
    case REQUEST_SPEED_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED_EV);
        size = 1;
        break;
    case REQUEST_SPATK_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_EV);
        size = 1;
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_EV);
        size = 1;
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP);
        size = 1;
        break;
    case REQUEST_POKERUS_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_POKERUS);
        size = 1;
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_LOCATION);
        size = 1;
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_LEVEL);
        size = 1;
        break;
    case REQUEST_MET_GAME_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_MET_GAME);
        size = 1;
        break;
    case REQUEST_POKEBALL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_POKEBALL);
        size = 1;
        break;
    case REQUEST_ALL_IVS_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        dst[1] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        dst[2] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        dst[3] = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV);
        dst[4] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        dst[5] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        size = 6;
        break;
    case REQUEST_HP_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_HP_IV);
        size = 1;
        break;
    case REQUEST_ATK_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV);
        size = 1;
        break;
    case REQUEST_DEF_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV);
        size = 1;
        break;
    case REQUEST_SPEED_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV);
        size = 1;
        break;
    case REQUEST_SPATK_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV);
        size = 1;
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV);
        size = 1;
        break;
    case REQUEST_PERSONALITY_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_CHECKSUM_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_CHECKSUM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_STATUS_BATTLE:
        data32 = GetMonData(&gPlayerParty[monId], MON_DATA_STATUS);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_LEVEL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
        size = 1;
        break;
    case REQUEST_HP_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MAX_HP_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_ATK_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_ATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_DEF_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_DEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPEED_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPEED);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPATK_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPDEF_BATTLE:
        data16 = GetMonData(&gPlayerParty[monId], MON_DATA_SPDEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_COOL_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_COOL);
        size = 1;
        break;
    case REQUEST_BEAUTY_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY);
        size = 1;
        break;
    case REQUEST_CUTE_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_CUTE);
        size = 1;
        break;
    case REQUEST_SMART_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SMART);
        size = 1;
        break;
    case REQUEST_TOUGH_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_TOUGH);
        size = 1;
        break;
    case REQUEST_SHEEN_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SHEEN);
        size = 1;
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_COOL_RIBBON);
        size = 1;
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY_RIBBON);
        size = 1;
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_CUTE_RIBBON);
        size = 1;
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_SMART_RIBBON);
        size = 1;
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        dst[0] = GetMonData(&gPlayerParty[monId], MON_DATA_TOUGH_RIBBON);
        size = 1;
        break;
    }

    return size;
}

static void WallyHandleGetRawMonData(void)
{
    PlayerHandleGetRawMonData();
}

static void WallyHandleSetMonData(void)
{
    u8 monToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetWallyMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                SetWallyMonData(i);
            monToCheck >>= 1;
        }
    }
    WallyBufferExecCompleted();
}

static void SetWallyMonData(u8 monId)
{
    struct BattlePokemon *battlePokemon = (struct BattlePokemon *)&gBattleBufferA[gActiveBank][3];
    struct MovePpInfo *moveData = (struct MovePpInfo *)&gBattleBufferA[gActiveBank][3];
    s32 i;

    switch (gBattleBufferA[gActiveBank][1])
    {
    case REQUEST_ALL_BATTLE:
        {
            u8 iv;

            SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &battlePokemon->species);
            SetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM, &battlePokemon->item);
            for (i = 0; i < 4; i++)
            {
                SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + i, &battlePokemon->moves[i]);
                SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + i, &battlePokemon->pp[i]);
            }
            SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &battlePokemon->ppBonuses);
            SetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP, &battlePokemon->friendship);
            SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &battlePokemon->experience);
            iv = battlePokemon->hpIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &iv);
            iv = battlePokemon->attackIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &iv);
            iv = battlePokemon->defenseIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &iv);
            iv = battlePokemon->speedIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV, &iv);
            iv = battlePokemon->spAttackIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &iv);
            iv = battlePokemon->spDefenseIV;
            SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &iv);
            SetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY, &battlePokemon->personality);
            SetMonData(&gPlayerParty[monId], MON_DATA_STATUS, &battlePokemon->status1);
            SetMonData(&gPlayerParty[monId], MON_DATA_LEVEL, &battlePokemon->level);
            SetMonData(&gPlayerParty[monId], MON_DATA_HP, &battlePokemon->hp);
            SetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP, &battlePokemon->maxHP);
            SetMonData(&gPlayerParty[monId], MON_DATA_ATK, &battlePokemon->attack);
            SetMonData(&gPlayerParty[monId], MON_DATA_DEF, &battlePokemon->defense);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPEED, &battlePokemon->speed);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPATK, &battlePokemon->spAttack);
            SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF, &battlePokemon->spDefense);
        }
        break;
    case REQUEST_SPECIES_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HELDITEM_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (i = 0; i < 4; i++)
        {
            SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + i, &moveData->moves[i]);
            SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + i, &moveData->pp[i]);
        }
        SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &moveData->ppBonuses);
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MOVE1 + gBattleBufferA[gActiveBank][1] - REQUEST_MOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PP_DATA_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PP1, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP2, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP3, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP4, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gPlayerParty[monId], MON_DATA_PP_BONUSES, &gBattleBufferA[gActiveBank][7]);
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PP1 + gBattleBufferA[gActiveBank][1] - REQUEST_PPMOVE1_BATTLE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_OTID_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_OT_ID, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_EXP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPEED_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_EV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_FRIENDSHIP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKERUS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_POKERUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_LOCATION, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MET_GAME_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MET_GAME, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_POKEBALL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_POKEBALL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ALL_IVS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][4]);
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][5]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV, &gBattleBufferA[gActiveBank][6]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][7]);
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][8]);
        break;
    case REQUEST_HP_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPEED_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF_IV, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_PERSONALITY_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_PERSONALITY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CHECKSUM_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CHECKSUM, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_STATUS_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_STATUS, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_LEVEL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_LEVEL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_HP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_MAX_HP_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_MAX_HP, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_ATK_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_ATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_DEF_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_DEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPEED_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPEED, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPATK_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPATK, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SPDEF_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SPDEF, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_COOL, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CUTE, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SMART, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_TOUGH, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SHEEN_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SHEEN, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_COOL_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_BEAUTY_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_CUTE_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_SMART_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        SetMonData(&gPlayerParty[monId], MON_DATA_TOUGH_RIBBON, &gBattleBufferA[gActiveBank][3]);
        break;
    }

    HandleLowHpMusicChange(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
}

static void WallyHandleSetRawMonData(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleLoadMonSprite(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSwitchInAnim(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleReturnMonToBall(void)
{
    if (gBattleBufferA[gActiveBank][1] == 0)
    {
        InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SWITCH_OUT_PLAYER_MON);
        gBattleBankFunc[gActiveBank] = sub_8168A20;
    }
    else
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        WallyBufferExecCompleted();
    }
}

static void WallyHandleDrawTrainerPic(void)
{
    DecompressTrainerBackPic(BACK_PIC_WALLY, gActiveBank);
    sub_806A12C(BACK_PIC_WALLY, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               80,
                                               80 + 4 * (8 - gTrainerBackPicCoords[BACK_PIC_WALLY].coords),
                                               30);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 240;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;
    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void WallyHandleTrainerSlide(void)
{
    DecompressTrainerBackPic(BACK_PIC_WALLY, gActiveBank);
    sub_806A12C(BACK_PIC_WALLY, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C,
                                               80,
                                               80 + 4 * (8 - gTrainerBackPicCoords[BACK_PIC_WALLY].coords),
                                               30);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -96;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 2;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;
    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy2;
}

static void WallyHandleTrainerSlideBack(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleFaintAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePaletteFade(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSuccessBallThrowAnim(void)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_SAFARI_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnFinishedAnimation;
}

static void WallyHandleBallThrowAnim(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBank][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gDoingBattleAnim = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_SAFARI_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnFinishedAnimation;
}

static void WallyHandlePause(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleMoveAnimation(void)
{
    u16 move = gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8);

    gAnimMoveTurn = gBattleBufferA[gActiveBank][3];
    gAnimMovePower = gBattleBufferA[gActiveBank][4] | (gBattleBufferA[gActiveBank][5] << 8);
    gAnimMoveDmg = gBattleBufferA[gActiveBank][6] | (gBattleBufferA[gActiveBank][7] << 8) | (gBattleBufferA[gActiveBank][8] << 16) | (gBattleBufferA[gActiveBank][9] << 24);
    gAnimFriendship = gBattleBufferA[gActiveBank][10];
    gWeatherMoveAnim = gBattleBufferA[gActiveBank][12] | (gBattleBufferA[gActiveBank][13] << 8);
    gAnimDisableStructPtr = (struct DisableStruct *)&gBattleBufferA[gActiveBank][16];
    gTransformedPersonalities[gActiveBank] = gAnimDisableStructPtr->transformedMonPersonality;
    if (IsMoveWithoutAnimation(move, gAnimMoveTurn)) // always returns FALSE
    {
        WallyBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
        gBattleBankFunc[gActiveBank] = WallyDoMoveAnimation;
    }

}

static void WallyDoMoveAnimation(void)
{
    u16 move = gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8);

    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
        {
            InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            sub_805EB9C(0);
            DoMoveAnim(move);
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 2;
        }
        break;
    case 2:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            sub_805EB9C(1);
            if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            {
                InitAndLaunchSpecialAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);
            }
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            CopyAllBattleSpritesInvisibilities();
            TrySetBehindSubstituteSpriteBit(gActiveBank, gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void WallyHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter;
}

static void WallyHandlePrintStringPlayerOnly(void)
{
    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        WallyHandlePrintString();
    else
        WallyBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        gBattleBankFunc[gActiveBank] = WallyHandleActions;
    }
}

static void WallyHandleChooseAction(void)
{
    s32 i;

    gBattleBankFunc[gActiveBank] = HandleChooseActionAfterDma3;
    BattleHandleAddTextPrinter(gText_BattleMenu, 2);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillWallyDo);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 1);
}

static void WallyHandleUnknownYesNoBox(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleChooseMove(void)
{
    switch (gBattleStruct->wallyMovesState)
    {
    case 0:
        InitMoveSelectionsVarsAndStrings();
        gBattleStruct->wallyMovesState++;
        gBattleStruct->wallyMoveFrames = 80;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattle_BG0_X = 0;
            gBattle_BG0_Y = 0x140;
            gBattleStruct->wallyMovesState++;
        }
        break;
    case 2:
        if (--gBattleStruct->wallyMoveFrames == 0)
        {
            PlaySE(SE_SELECT);
            EmitTwoReturnValues(1, 10, 0x100);
            WallyBufferExecCompleted();
        }
        break;
    }
}

static void WallyHandleChooseItem(void)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gBattleBankFunc[gActiveBank] = OpenBagAfterPaletteFade;
    gBankInMenu = gActiveBank;
}

static void WallyHandleChoosePokemon(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd23(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);
        u32 curHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, curHP, hpVal);
    }
    else
    {
        u32 maxHP = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MAX_HP);

        SetBattleBarStruct(gActiveBank, gHealthBoxesIds[gActiveBank], maxHP, 0, hpVal);
        UpdateHpTextInHealthbox(gHealthBoxesIds[gActiveBank], 0, HP_CURRENT);
    }

    gBattleBankFunc[gActiveBank] = CompleteOnHealthbarDone;
}

static void WallyHandleExpUpdate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusIconUpdate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusAnimation(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleStatusXor(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleDataTransfer(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleDMA3Transfer(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandlePlayBGM(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd32(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleTwoReturnValues(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleChosenMonReturnValue(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleOneReturnValue(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleOneReturnValue_Duplicate(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd37(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd38(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd39(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd40(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        WallyBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void WallyHandleCmd42(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleEffectivenessSound(void)
{
    PlaySE(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    WallyBufferExecCompleted();
}

static void WallyHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBank][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }

    WallyBufferExecCompleted();
}

static void WallyHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry1(species, 25);
    WallyBufferExecCompleted();
}

static void WallyHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    WallyBufferExecCompleted();
}

static void WallyHandleIntroTrainerBallThrow(void)
{
    u8 paletteNum;
    u8 taskId;

    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);

    gSprites[gBankSpriteIds[gActiveBank]].data0 = 50;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = -40;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    gSprites[gBankSpriteIds[gActiveBank]].data5 = gActiveBank;

    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], sub_805CC00);
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], 1);

    paletteNum = AllocSpritePalette(0xD6F8);
    LoadCompressedPalette(gTrainerBackPicPaletteTable[BACK_PIC_WALLY].data, 0x100 + paletteNum * 16, 32);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = paletteNum;

    taskId = CreateTask(sub_816AC04, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_21;
}

static void sub_816AA80(u8 bank)
{
    u16 species;

    gBattleSpritesDataPtr->bankData[bank].transformSpecies = 0;
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
    sub_806A068(species, GetBankIdentity(bank));
    gBankSpriteIds[bank] = CreateSprite(&gUnknown_0202499C,
                                        sub_80A5C6C(bank, 2),
                                        GetBankSpriteDefault_Y(bank),
                                        sub_80A82E4(bank));

    gSprites[gUnknown_03005D7C[bank]].data1 = gBankSpriteIds[bank];
    gSprites[gUnknown_03005D7C[bank]].data2 = bank;

    gSprites[gBankSpriteIds[bank]].data0 = bank;
    gSprites[gBankSpriteIds[bank]].data2 = species;
    gSprites[gBankSpriteIds[bank]].oam.paletteNum = bank;

    StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], gBattleMonForms[bank]);
    gSprites[gBankSpriteIds[bank]].invisible = TRUE;
    gSprites[gBankSpriteIds[bank]].callback = SpriteCallbackDummy;
    gSprites[gUnknown_03005D7C[bank]].data0 = sub_80753E8(0, 0xFF);
}

static void sub_816AC04(u8 taskId)
{
    if (gTasks[taskId].data[1] < 31)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        u8 savedActiveBank = gActiveBank;

        gActiveBank = gTasks[taskId].data[0];
        gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
        sub_816AA80(gActiveBank);
        gBattleBankFunc[gActiveBank] = sub_816864C;
        gActiveBank = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void WallyHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        WallyBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1 = 1;
        gUnknown_020244B4[gActiveBank] = CreatePartyStatusSummarySprites(gActiveBank, (struct HpAndStatus *)&gBattleBufferA[gActiveBank][4], gBattleBufferA[gActiveBank][1], gBattleBufferA[gActiveBank][2]);
        WallyBufferExecCompleted();
    }
}

static void WallyHandleCmd49(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd50(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleSpriteInvisibility(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleBattleAnimation(void)
{
    u8 animationId = gBattleBufferA[gActiveBank][1];
    u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    if (TryHandleLaunchBattleTableAnimation(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
        WallyBufferExecCompleted();
    else
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;
}

static void WallyHandleLinkStandbyMsg(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleResetActionMoveSelection(void)
{
    WallyBufferExecCompleted();
}

static void WallyHandleCmd55(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBank][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    WallyBufferExecCompleted();

    if (!(gBattleTypeFlags & BATTLE_TYPE_WILD) && gBattleTypeFlags & BATTLE_TYPE_LINK)
        gBattleBankFunc[gActiveBank] = sub_80587B0;
}

static void nullsub_118(void)
{
}
