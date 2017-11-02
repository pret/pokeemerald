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

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gAbsentBankFlags;
extern u8 gNoOfAllBanks;
extern bool8 gDoingBattleAnim;
extern u8 gPlayerDpadHoldFrames;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern void (*gPreBattleCallback1)(void);
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
extern u8 gUnknown_0203CEE8;
extern u8 gUnknown_0203CEE9;
extern u8 gUnknown_0203CF00[];
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

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[];
extern const struct CompressedSpritePalette gTrainerBackPicPaletteTable[];
extern const u8 gTypeNames[][7];
extern const struct BattleMove gBattleMoves[];

extern const u8 gText_BattleSwitchWhich[];
extern const u8 gText_MoveInterfacePP[];
extern const u8 gText_MoveInterfaceType[];
extern const u8 gText_LinkStandby[];
extern const u8 gText_BattleMenu[];
extern const u8 gText_WhatWillPkmnDo[];
extern const u8 gText_BattleYesNoChoice[];

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_81B89AC(u8 arg0);
extern void sub_81AABB0(void);
extern void sub_806A068(u16, u8);
extern void sub_81A57E4(u8 bank, u16 stringId);
extern void sub_81851A8(u8 *);

// this file's functions
static void PlayerHandleGetMonData(void);
void PlayerHandleGetRawMonData(void);
static void PlayerHandleSetMonData(void);
static void PlayerHandleSetRawMonData(void);
static void PlayerHandleLoadMonSprite(void);
static void PlayerHandleSwitchInAnim(void);
static void PlayerHandleReturnMonToBall(void);
static void PlayerHandleDrawTrainerPic(void);
static void PlayerHandleTrainerSlide(void);
static void PlayerHandleTrainerSlideBack(void);
static void PlayerHandleFaintAnimation(void);
static void PlayerHandlePaletteFade(void);
static void PlayerHandleSuccessBallThrowAnim(void);
static void PlayerHandleBallThrowAnim(void);
static void PlayerHandlePause(void);
static void PlayerHandleMoveAnimation(void);
static void PlayerHandlePrintString(void);
static void PlayerHandlePrintStringPlayerOnly(void);
static void PlayerHandleChooseAction(void);
static void PlayerHandleUnknownYesNoBox(void);
static void PlayerHandleChooseMove(void);
static void PlayerHandleChooseItem(void);
static void PlayerHandleChoosePokemon(void);
static void PlayerHandleCmd23(void);
static void PlayerHandleHealthBarUpdate(void);
static void PlayerHandleExpUpdate(void);
static void PlayerHandleStatusIconUpdate(void);
static void PlayerHandleStatusAnimation(void);
static void PlayerHandleStatusXor(void);
static void PlayerHandleDataTransfer(void);
static void PlayerHandleDMA3Transfer(void);
static void PlayerHandlePlayBGM(void);
static void PlayerHandleCmd32(void);
static void PlayerHandleTwoReturnValues(void);
static void PlayerHandleChosenMonReturnValue(void);
static void PlayerHandleOneReturnValue(void);
static void PlayerHandleOneReturnValue_Duplicate(void);
static void PlayerHandleCmd37(void);
static void PlayerHandleCmd38(void);
static void PlayerHandleCmd39(void);
static void PlayerHandleCmd40(void);
static void PlayerHandleHitAnimation(void);
static void PlayerHandleCmd42(void);
static void PlayerHandleEffectivenessSound(void);
static void PlayerHandlePlayFanfareOrBGM(void);
static void PlayerHandleFaintingCry(void);
static void PlayerHandleIntroSlide(void);
static void PlayerHandleIntroTrainerBallThrow(void);
static void PlayerHandleDrawPartyStatusSummary(void);
static void PlayerHandleCmd49(void);
static void PlayerHandleCmd50(void);
static void PlayerHandleSpriteInvisibility(void);
static void PlayerHandleBattleAnimation(void);
static void PlayerHandleLinkStandbyMsg(void);
static void PlayerHandleResetActionMoveSelection(void);
static void PlayerHandleCmd55(void);
static void nullsub_22(void);

static void PlayerBufferRunCommand(void);
static void HandleInputChooseTarget(void);
static void HandleInputChooseMove(void);
static void MoveSelectionCreateCursorAt(u8 cursorPos, u8 arg1);
static void MoveSelectionDestroyCursorAt(u8 cursorPos);
static void MoveSelectionDisplayPpNumber(void);
static void MoveSelectionDisplayPpString(void);
static void MoveSelectionDisplayMoveType(void);
static void MoveSelectionDisplayMoveNames(void);
static void HandleMoveSwitchting(void);
static void sub_8058FC0(void);
static void sub_8059828(void);
static void CompleteWhenChoseItem(void);
static void sub_8059544(u8 taskId);
static void Task_PrepareToGiveExpWithExpBar(u8 taskId);
static void DestroyExpTaskAndCompleteOnInactiveTextPrinter(u8 taskId);
static void sub_8059400(u8 taskId);
static void sub_80595A4(u8 taskId);
static void PrintLinkStandbyMsg(void);
static u32 CopyPlayerMonData(u8 monId, u8 *dst);
static void SetPlayerMonData(u8 monId);
static void sub_805B258(u8 bank, bool8 dontClearSubstituteBit);
static void DoSwitchOutAnimation(void);
static void PlayerDoMoveAnimation(void);
static void task05_08033660(u8 taskId);
static void sub_805CE38(void);

static void (*const sPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(void) =
{
    PlayerHandleGetMonData,
    PlayerHandleGetRawMonData,
    PlayerHandleSetMonData,
    PlayerHandleSetRawMonData,
    PlayerHandleLoadMonSprite,
    PlayerHandleSwitchInAnim,
    PlayerHandleReturnMonToBall,
    PlayerHandleDrawTrainerPic,
    PlayerHandleTrainerSlide,
    PlayerHandleTrainerSlideBack,
    PlayerHandleFaintAnimation,
    PlayerHandlePaletteFade,
    PlayerHandleSuccessBallThrowAnim,
    PlayerHandleBallThrowAnim,
    PlayerHandlePause,
    PlayerHandleMoveAnimation,
    PlayerHandlePrintString,
    PlayerHandlePrintStringPlayerOnly,
    PlayerHandleChooseAction,
    PlayerHandleUnknownYesNoBox,
    PlayerHandleChooseMove,
    PlayerHandleChooseItem,
    PlayerHandleChoosePokemon,
    PlayerHandleCmd23,
    PlayerHandleHealthBarUpdate,
    PlayerHandleExpUpdate,
    PlayerHandleStatusIconUpdate,
    PlayerHandleStatusAnimation,
    PlayerHandleStatusXor,
    PlayerHandleDataTransfer,
    PlayerHandleDMA3Transfer,
    PlayerHandlePlayBGM,
    PlayerHandleCmd32,
    PlayerHandleTwoReturnValues,
    PlayerHandleChosenMonReturnValue,
    PlayerHandleOneReturnValue,
    PlayerHandleOneReturnValue_Duplicate,
    PlayerHandleCmd37,
    PlayerHandleCmd38,
    PlayerHandleCmd39,
    PlayerHandleCmd40,
    PlayerHandleHitAnimation,
    PlayerHandleCmd42,
    PlayerHandleEffectivenessSound,
    PlayerHandlePlayFanfareOrBGM,
    PlayerHandleFaintingCry,
    PlayerHandleIntroSlide,
    PlayerHandleIntroTrainerBallThrow,
    PlayerHandleDrawPartyStatusSummary,
    PlayerHandleCmd49,
    PlayerHandleCmd50,
    PlayerHandleSpriteInvisibility,
    PlayerHandleBattleAnimation,
    PlayerHandleLinkStandbyMsg,
    PlayerHandleResetActionMoveSelection,
    PlayerHandleCmd55,
    nullsub_22
};

static const u8 sTargetIdentities[] = {IDENTITY_PLAYER_MON1, IDENTITY_PLAYER_MON2, IDENTITY_OPPONENT_MON2, IDENTITY_OPPONENT_MON1};

// unknown unused data
static const u8 gUnknown_0831C5FC[] = {0x48, 0x48, 0x20, 0x5a, 0x50, 0x50, 0x50, 0x58};

void nullsub_21(void)
{
}

void SetControllerToPlayer(void)
{
    gBattleBankFunc[gActiveBank] = PlayerBufferRunCommand;
    gDoingBattleAnim = FALSE;
    gPlayerDpadHoldFrames = 0;
}

static void PlayerBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = PlayerBufferRunCommand;
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

static void PlayerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(sPlayerBufferCommands))
            sPlayerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            PlayerBufferExecCompleted();
    }
}

static void CompleteOnBankSpritePosX_0(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].pos2.x == 0)
        PlayerBufferExecCompleted();
}

static void HandleInputChooseAction(void)
{
    u16 itemId = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    dp11b_obj_instanciate(gActiveBank, 1, 7, 1);
    dp11b_obj_instanciate(gActiveBank, 0, 7, 1);

    if (gMain.newAndRepeatedKeys & DPAD_ANY && gSaveBlock2Ptr->optionsButtonMode == 2)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[gActiveBank])
        {
        case 0:
            EmitTwoReturnValues(1, ACTION_USE_MOVE, 0);
            break;
        case 1:
            EmitTwoReturnValues(1, ACTION_USE_ITEM, 0);
            break;
        case 2:
            EmitTwoReturnValues(1, ACTION_SWITCH, 0);
            break;
        case 3:
            EmitTwoReturnValues(1, ACTION_RUN, 0);
            break;
        }
        PlayerBufferExecCompleted();
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gActionSelectionCursor[gActiveBank] & 1) // if is ACTION_USE_ITEM or ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        if (!(gActionSelectionCursor[gActiveBank] & 1)) // if is ACTION_USE_MOVE or ACTION_SWITCH
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gActionSelectionCursor[gActiveBank] & 2) // if is ACTION_SWITCH or ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (!(gActionSelectionCursor[gActiveBank] & 2)) // if is ACTION_USE_MOVE or ACTION_USE_ITEM
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBank]);
            gActionSelectionCursor[gActiveBank] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
        }
    }
    else if (gMain.newKeys & B_BUTTON || gPlayerDpadHoldFrames > 59)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
         && GetBankIdentity(gActiveBank) == IDENTITY_PLAYER_MON2
         && !(gAbsentBankFlags & gBitTable[GetBankByIdentity(IDENTITY_PLAYER_MON1)])
         && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleBufferA[gActiveBank][1] == ACTION_USE_ITEM)
            {
                // Add item to bag if it is a ball
                if (itemId <= ITEM_PREMIER_BALL)
                    AddBagItem(itemId, 1);
                else
                    return;
            }
            PlaySE(SE_SELECT);
            EmitTwoReturnValues(1, ACTION_CANCEL_PARTNER, 0);
            PlayerBufferExecCompleted();
        }
    }
    else if (gMain.newKeys & START_BUTTON)
    {
        SwapHpBarsWithHpText();
    }
}

static void sub_80577F0(void) // unused
{
    dp11b_obj_free(gActiveBank, 1);
    dp11b_obj_free(gActiveBank, 0);
    gBattleBankFunc[gActiveBank] = HandleInputChooseTarget;
}

static void HandleInputChooseTarget(void)
{
    s32 i;
    u8 identities[4];
    memcpy(identities, sTargetIdentities, ARRAY_COUNT(sTargetIdentities));

    dp11b_obj_instanciate(gMultiUsePlayerCursor, 1, 0xF, 1);

    // what a weird loop
    i = 0;
    if (gNoOfAllBanks != 0)
    {
        do
        {
            if (i != gMultiUsePlayerCursor)
                dp11b_obj_free(i, 1);
            i++;
        } while (i < gNoOfAllBanks);
    }

    if (gMain.heldKeys & DPAD_ANY && gSaveBlock2Ptr->optionsButtonMode == 2)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;
        EmitTwoReturnValues(1, 10, gMoveSelectionCursor[gActiveBank] | (gMultiUsePlayerCursor << 8));
        dp11b_obj_free(gMultiUsePlayerCursor, 1);
        PlayerBufferExecCompleted();
    }
    else if (gMain.newKeys & B_BUTTON || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;
        gBattleBankFunc[gActiveBank] = HandleInputChooseMove;
        dp11b_obj_instanciate(gActiveBank, 1, 7, 1);
        dp11b_obj_instanciate(gActiveBank, 0, 7, 1);
        dp11b_obj_free(gMultiUsePlayerCursor, 1);
    }
    else if (gMain.newKeys & (DPAD_LEFT | DPAD_UP))
    {
        PlaySE(SE_SELECT);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;

        do
        {
            u8 currSelIdentity = GetBankIdentity(gMultiUsePlayerCursor);

            for (i = 0; i < BATTLE_BANKS_COUNT; i++)
            {
                if (currSelIdentity == identities[i])
                    break;
            }
            do
            {
                if (--i < 0)
                    i = 4; // UB: array out of range
                gMultiUsePlayerCursor = GetBankByIdentity(identities[i]);
            } while (gMultiUsePlayerCursor == gNoOfAllBanks);

            i = 0;
            switch (GetBankIdentity(gMultiUsePlayerCursor))
            {
            case IDENTITY_PLAYER_MON1:
            case IDENTITY_PLAYER_MON2:
                if (gActiveBank != gMultiUsePlayerCursor)
                    i++;
                else if (gBattleMoves[GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MOVE1 + gMoveSelectionCursor[gActiveBank])].target & MOVE_TARGET_USER)
                    i++;
                break;
            case IDENTITY_OPPONENT_MON1:
            case IDENTITY_OPPONENT_MON2:
                i++;
                break;
            }

            if (gAbsentBankFlags & gBitTable[gMultiUsePlayerCursor])
                i = 0;
        } while (i == 0);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039AD8;
    }
    else if (gMain.newKeys & (DPAD_RIGHT | DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;

        do
        {
            u8 currSelIdentity = GetBankIdentity(gMultiUsePlayerCursor);

            for (i = 0; i < BATTLE_BANKS_COUNT; i++)
            {
                if (currSelIdentity == identities[i])
                    break;
            }
            do
            {
                if (++i > 3)
                    i = 0;
                gMultiUsePlayerCursor = GetBankByIdentity(identities[i]);
            } while (gMultiUsePlayerCursor == gNoOfAllBanks);

            i = 0;
            switch (GetBankIdentity(gMultiUsePlayerCursor))
            {
            case IDENTITY_PLAYER_MON1:
            case IDENTITY_PLAYER_MON2:
                if (gActiveBank != gMultiUsePlayerCursor)
                    i++;
                else if (gBattleMoves[GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MOVE1 + gMoveSelectionCursor[gActiveBank])].target & MOVE_TARGET_USER)
                    i++;
                break;
            case IDENTITY_OPPONENT_MON1:
            case IDENTITY_OPPONENT_MON2:
                i++;
                break;
            }

            if (gAbsentBankFlags & gBitTable[gMultiUsePlayerCursor])
                i = 0;
        } while (i == 0);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039AD8;
    }
}

static void HandleInputChooseMove(void)
{
    bool32 canSelectTarget = FALSE;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);

    if (gMain.heldKeys & DPAD_ANY && gSaveBlock2Ptr->optionsButtonMode == 2)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        u8 moveTarget;

        PlaySE(SE_SELECT);
        if (moveInfo->moves[gMoveSelectionCursor[gActiveBank]] == MOVE_CURSE)
        {
            if (moveInfo->monType1 != TYPE_GHOST && moveInfo->monType2 != TYPE_GHOST)
                moveTarget = MOVE_TARGET_x10;
            else
                moveTarget = MOVE_TARGET_SELECTED;
        }
        else
        {
            moveTarget = gBattleMoves[moveInfo->moves[gMoveSelectionCursor[gActiveBank]]].target;
        }

        if (moveTarget & MOVE_TARGET_x10)
            gMultiUsePlayerCursor = gActiveBank;
        else
            gMultiUsePlayerCursor = GetBankByIdentity((GetBankIdentity(gActiveBank) & BIT_SIDE) ^ BIT_SIDE);

        if (!gBattleBufferA[gActiveBank][1]) // not a double battle
        {
            if (moveTarget & MOVE_TARGET_USER && !gBattleBufferA[gActiveBank][2])
                canSelectTarget++;
        }
        else // double battle
        {
            if (!(moveTarget & (MOVE_TARGET_RANDOM | MOVE_TARGET_BOTH | MOVE_TARGET_DEPENDS | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_x10)))
                canSelectTarget++; // either selected or user

            if (moveInfo->currentPp[gMoveSelectionCursor[gActiveBank]] == 0)
            {
                canSelectTarget = FALSE;
            }
            else if (!(moveTarget & (MOVE_TARGET_x10 | MOVE_TARGET_USER)) && CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ACTIVE) <= 1)
            {
                gMultiUsePlayerCursor = GetDefaultMoveTarget(gActiveBank);
                canSelectTarget = FALSE;
            }
        }

        if (!canSelectTarget)
        {
            EmitTwoReturnValues(1, 10, gMoveSelectionCursor[gActiveBank] | (gMultiUsePlayerCursor << 8));
            PlayerBufferExecCompleted();
        }
        else
        {
            gBattleBankFunc[gActiveBank] = HandleInputChooseTarget;

            if (moveTarget & (MOVE_TARGET_x10 | MOVE_TARGET_USER))
                gMultiUsePlayerCursor = gActiveBank;
            else if (gAbsentBankFlags & gBitTable[GetBankByIdentity(IDENTITY_OPPONENT_MON1)])
                gMultiUsePlayerCursor = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
            else
                gMultiUsePlayerCursor = GetBankByIdentity(IDENTITY_OPPONENT_MON1);

            gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039AD8;
        }
    }
    else if (gMain.newKeys & B_BUTTON || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        EmitTwoReturnValues(1, 10, 0xFFFF);
        PlayerBufferExecCompleted();
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gMoveSelectionCursor[gActiveBank] & 1)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
            gMoveSelectionCursor[gActiveBank] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
            MoveSelectionDisplayPpNumber();
            MoveSelectionDisplayMoveType();
        }
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        if (!(gMoveSelectionCursor[gActiveBank] & 1)
         && (gMoveSelectionCursor[gActiveBank] ^ 1) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
            gMoveSelectionCursor[gActiveBank] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
            MoveSelectionDisplayPpNumber();
            MoveSelectionDisplayMoveType();
        }
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gMoveSelectionCursor[gActiveBank] & 2)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
            gMoveSelectionCursor[gActiveBank] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
            MoveSelectionDisplayPpNumber();
            MoveSelectionDisplayMoveType();
        }
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (!(gMoveSelectionCursor[gActiveBank] & 2)
         && (gMoveSelectionCursor[gActiveBank] ^ 2) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
            gMoveSelectionCursor[gActiveBank] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
            MoveSelectionDisplayPpNumber();
            MoveSelectionDisplayMoveType();
        }
    }
    else if (gMain.newKeys & SELECT_BUTTON)
    {
        if (gNumberOfMovesToChoose > 1 && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
        {
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 29);

            if (gMoveSelectionCursor[gActiveBank] != 0)
                gMultiUsePlayerCursor = 0;
            else
                gMultiUsePlayerCursor = gMoveSelectionCursor[gActiveBank] + 1;

            MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
            BattleHandleAddTextPrinter(gText_BattleSwitchWhich, 0xB);
            gBattleBankFunc[gActiveBank] = HandleMoveSwitchting;
        }
    }
}

u32 sub_8057FBC(void) // unused
{
    u32 var = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        var = 1;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0x140;
        var = 0xFF;
    }
    if (gMain.newKeys & DPAD_LEFT && gMoveSelectionCursor[gActiveBank] & 1)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
        gMoveSelectionCursor[gActiveBank] ^= 1;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
    }
    if (gMain.newKeys & DPAD_RIGHT && !(gMoveSelectionCursor[gActiveBank] & 1)
        && (gMoveSelectionCursor[gActiveBank] ^ 1) < gNumberOfMovesToChoose)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
        gMoveSelectionCursor[gActiveBank] ^= 1;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
    }
    if (gMain.newKeys & DPAD_UP && gMoveSelectionCursor[gActiveBank] & 2)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
        gMoveSelectionCursor[gActiveBank] ^= 2;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
    }
    if (gMain.newKeys & DPAD_DOWN && !(gMoveSelectionCursor[gActiveBank] & 2)
        && (gMoveSelectionCursor[gActiveBank] ^ 2) < gNumberOfMovesToChoose)
    {
        MoveSelectionDestroyCursorAt(gMoveSelectionCursor[gActiveBank]);
        gMoveSelectionCursor[gActiveBank] ^= 2;
        PlaySE(SE_SELECT);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
    }

    return var;
}

static void HandleMoveSwitchting(void)
{
    u8 perMovePPBonuses[4];
    struct ChooseMoveStruct moveStruct;
    u8 totalPPBonuses;

    if (gMain.newKeys & (A_BUTTON | SELECT_BUTTON))
    {
        PlaySE(SE_SELECT);

        if (gMoveSelectionCursor[gActiveBank] != gMultiUsePlayerCursor)
        {
            struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);
            s32 i;

            // swap moves and pp
            i = moveInfo->moves[gMoveSelectionCursor[gActiveBank]];
            moveInfo->moves[gMoveSelectionCursor[gActiveBank]] = moveInfo->moves[gMultiUsePlayerCursor];
            moveInfo->moves[gMultiUsePlayerCursor] = i;

            i = moveInfo->currentPp[gMoveSelectionCursor[gActiveBank]];
            moveInfo->currentPp[gMoveSelectionCursor[gActiveBank]] = moveInfo->currentPp[gMultiUsePlayerCursor];
            moveInfo->currentPp[gMultiUsePlayerCursor] = i;

            i = moveInfo->maxPp[gMoveSelectionCursor[gActiveBank]];
            moveInfo->maxPp[gMoveSelectionCursor[gActiveBank]] = moveInfo->maxPp[gMultiUsePlayerCursor];
            moveInfo->maxPp[gMultiUsePlayerCursor] = i;

            if (gDisableStructs[gActiveBank].unk18_b & gBitTable[gMoveSelectionCursor[gActiveBank]])
            {
                gDisableStructs[gActiveBank].unk18_b &= (~gBitTable[gMoveSelectionCursor[gActiveBank]]);
                gDisableStructs[gActiveBank].unk18_b |= gBitTable[gMultiUsePlayerCursor];
            }

            MoveSelectionDisplayMoveNames();

            for (i = 0; i < 4; i++)
                perMovePPBonuses[i] = (gBattleMons[gActiveBank].ppBonuses & (3 << (i * 2))) >> (i * 2);

            totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[gActiveBank]];
            perMovePPBonuses[gMoveSelectionCursor[gActiveBank]] = perMovePPBonuses[gMultiUsePlayerCursor];
            perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

            totalPPBonuses = 0;
            for (i = 0; i < 4; i++)
                totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

            gBattleMons[gActiveBank].ppBonuses = totalPPBonuses;

            for (i = 0; i < 4; i++)
            {
                gBattleMons[gActiveBank].moves[i] = moveInfo->moves[i];
                gBattleMons[gActiveBank].pp[i] = moveInfo->currentPp[i];
            }

            if (!(gBattleMons[gActiveBank].status2 & STATUS2_TRANSFORMED))
            {
                for (i = 0; i < 4; i++)
                {
                    moveStruct.moves[i] = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MOVE1 + i);
                    moveStruct.currentPp[i] = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_PP1 + i);
                }

                totalPPBonuses = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_PP_BONUSES);
                for (i = 0; i < 4; i++)
                    perMovePPBonuses[i] = (totalPPBonuses & (3 << (i * 2))) >> (i * 2);

                i = moveStruct.moves[gMoveSelectionCursor[gActiveBank]];
                moveStruct.moves[gMoveSelectionCursor[gActiveBank]] = moveStruct.moves[gMultiUsePlayerCursor];
                moveStruct.moves[gMultiUsePlayerCursor] = i;

                i = moveStruct.currentPp[gMoveSelectionCursor[gActiveBank]];
                moveStruct.currentPp[gMoveSelectionCursor[gActiveBank]] = moveStruct.currentPp[gMultiUsePlayerCursor];
                moveStruct.currentPp[gMultiUsePlayerCursor] = i;

                totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[gActiveBank]];
                perMovePPBonuses[gMoveSelectionCursor[gActiveBank]] = perMovePPBonuses[gMultiUsePlayerCursor];
                perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

                totalPPBonuses = 0;
                for (i = 0; i < 4; i++)
                    totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

                for (i = 0; i < 4; i++)
                {
                    SetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_MOVE1 + i, &moveStruct.moves[i]);
                    SetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_PP1 + i, &moveStruct.currentPp[i]);
                }

                SetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_PP_BONUSES, &totalPPBonuses);
            }
        }

        gBattleBankFunc[gActiveBank] = HandleInputChooseMove;
        gMoveSelectionCursor[gActiveBank] = gMultiUsePlayerCursor;
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
        MoveSelectionDisplayPpString();
        MoveSelectionDisplayPpNumber();
        MoveSelectionDisplayMoveType();
    }
    else if (gMain.newKeys & (B_BUTTON | SELECT_BUTTON))
    {
        PlaySE(SE_SELECT);
        MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);
        MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
        gBattleBankFunc[gActiveBank] = HandleInputChooseMove;
        MoveSelectionDisplayPpString();
        MoveSelectionDisplayPpNumber();
        MoveSelectionDisplayMoveType();
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        if (gMultiUsePlayerCursor & 1)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        if (!(gMultiUsePlayerCursor & 1) && (gMultiUsePlayerCursor ^ 1) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if (gMultiUsePlayerCursor & 2)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if (!(gMultiUsePlayerCursor & 2) && (gMultiUsePlayerCursor ^ 2) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[gActiveBank])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
}

static void sub_80586F8(void)
{
    if (gLinkVSyncDisabled == 0)
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            m4aSongNumStop(SE_HINSI);
            gMain.inBattle = 0;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(sub_8038D64);
            if (gBattleOutcome == BATTLE_WON)
                sub_817E3F4();
            FreeAllWindowBuffers();
        }
    }
    else
    {
        if (sub_800A520())
        {
            m4aSongNumStop(SE_HINSI);
            gMain.inBattle = 0;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(sub_8038D64);
            if (gBattleOutcome == BATTLE_WON)
                sub_817E3F4();
            FreeAllWindowBuffers();
        }
    }
}

void sub_80587B0(void)
{
    if (!gPaletteFade.active)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (sub_800A520())
            {
                if (gLinkVSyncDisabled == 0)
                    sub_800AC34();
                else
                    sub_800ADF8();

                gBattleBankFunc[gActiveBank] = sub_80586F8;
            }
        }
        else
        {
            m4aSongNumStop(SE_HINSI);
            gMain.inBattle = 0;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(gMain.savedCallback);
        }
    }
}

static void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        PlayerBufferExecCompleted();
}

static void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        PlayerBufferExecCompleted();
}

static void sub_80588B4(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        nullsub_25(gSaveBlock2Ptr->playerGender);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        PlayerBufferExecCompleted();
    }
}

static void sub_8058924(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        PlayerBufferExecCompleted();
    }
}

static void sub_805896C(void)
{
    bool8 var = FALSE;

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy)
            var = TRUE;
    }
    else
    {
        if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
         && gSprites[gHealthBoxesIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
            var = TRUE;
    }

    if (var && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x1 = 0;
        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);

        if (IsDoubleBattle())
            sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]], gActiveBank ^ BIT_MON);

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 3;
        gBattleBankFunc[gActiveBank] = sub_8058924;
    }
}

static void sub_8058B40(void)
{
    bool32 r9 = FALSE;
    bool32 r8 = FALSE;

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
        sub_8172EF0(gActiveBank, &gPlayerParty[gBattlePartyID[gActiveBank]]);
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x80 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8)
        sub_8172EF0(gActiveBank ^ BIT_MON, &gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]]);

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8 && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].flag_x8)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80)
        {
            if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank ^ BIT_MON], &gPlayerParty[gBattlePartyID[gActiveBank ^ BIT_MON]], HEALTHBOX_ALL);
                sub_8076918(gActiveBank ^ BIT_MON);
                SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank ^ BIT_MON]);
            }
            UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
            sub_8076918(gActiveBank);
            SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80 = 1;
    }

    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x40
        && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank ^ BIT_MON].field_1_x40
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                m4aMPlayContinue(&gMPlay_BGM);
            else
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 1;
        r9 = TRUE;
    }

    if (!IsDoubleBattle() || (IsDoubleBattle() && (gBattleTypeFlags & BATTLE_TYPE_MULTI)))
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        {
            r8 = TRUE;
        }
    }
    else
    {
        if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy
            && gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy
            && gSprites[gBankSpriteIds[gActiveBank ^ BIT_MON]].callback == SpriteCallbackDummy)
        {
            r8 = TRUE;
        }
    }

    if (r9 && r8)
    {
        if (IsDoubleBattle() && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank ^ BIT_MON]]);
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);

        gBattleSpritesDataPtr->animationData->field_9_x1 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x20 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x80 = 0;

        gBattleBankFunc[gActiveBank] = sub_805896C;
    }
}

static void sub_8058EDC(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1
     && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(gActiveBank);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);

        gBattleBankFunc[gActiveBank] = sub_8058FC0;
    }
}

static void sub_8058FC0(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive
        && !IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        PlayerBufferExecCompleted();
    }
}

static void sub_805902C(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80
        && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        sub_8172EF0(gActiveBank, &gPlayerParty[gBattlePartyID[gActiveBank]]);
    }

    if (gSprites[gUnknown_03005D7C[gActiveBank]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x8)
    {
        DestroySprite(&gSprites[gUnknown_03005D7C[gActiveBank]]);
        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_ALL);
        sub_8076918(gActiveBank);
        SetHealthboxSpriteVisible(gHealthBoxesIds[gActiveBank]);
        gBattleBankFunc[gActiveBank] = sub_8058EDC;
    }
}

void c3_0802FDF4(u8 taskId)
{
    if (!IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        DestroyTask(taskId);
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
        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        PlayerBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        PlayerBufferExecCompleted();
}

#define tExpTask_monId      data[0]
#define tExpTask_gainedExp  data[1]
#define tExpTask_bank       data[2]
#define tExpTask_frames     data[10]

static void Task_GiveExpToMon(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].tExpTask_monId);
    u8 bank = gTasks[taskId].tExpTask_bank;
    s16 gainedExp = gTasks[taskId].tExpTask_gainedExp;

    if (IsDoubleBattle() == TRUE || monId != gBattlePartyID[bank]) // give exp without the expbar
    {
        struct Pokemon *mon = &gPlayerParty[monId];
        u16 species = GetMonData(mon, MON_DATA_SPECIES);
        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        u32 currExp = GetMonData(mon, MON_DATA_EXP);
        u32 nextLvlExp = gExperienceTables[gBaseStats[species].growthRate][level + 1];

        if (currExp + gainedExp >= nextLvlExp)
        {
            u8 savedActiveBank;

            SetMonData(mon, MON_DATA_EXP, &nextLvlExp);
            CalculateMonStats(mon);
            gainedExp -= nextLvlExp - currExp;
            savedActiveBank = gActiveBank;
            gActiveBank = bank;
            EmitTwoReturnValues(1, RET_VALUE_LEVELLED_UP, gainedExp);
            gActiveBank = savedActiveBank;

            if (IsDoubleBattle() == TRUE
             && ((u16)(monId) == gBattlePartyID[bank] || (u16)(monId) == gBattlePartyID[bank ^ BIT_MON]))
                gTasks[taskId].func = sub_8059544;
            else
                gTasks[taskId].func = DestroyExpTaskAndCompleteOnInactiveTextPrinter;
        }
        else
        {
            currExp += gainedExp;
            SetMonData(mon, MON_DATA_EXP, &currExp);
            gBattleBankFunc[bank] = CompleteOnInactiveTextPrinter;
            DestroyTask(taskId);
        }
    }
    else
    {
        gTasks[taskId].func = Task_PrepareToGiveExpWithExpBar;
    }
}

static void Task_PrepareToGiveExpWithExpBar(u8 taskId)
{
    u8 monIndex = gTasks[taskId].tExpTask_monId;
    s32 gainedExp = gTasks[taskId].tExpTask_gainedExp;
    u8 bank = gTasks[taskId].tExpTask_bank;
    struct Pokemon *mon = &gPlayerParty[monIndex];
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 exp = GetMonData(mon, MON_DATA_EXP);
    u32 currLvlExp = gExperienceTables[gBaseStats[species].growthRate][level];
    u32 expToNextLvl;

    exp -= currLvlExp;
    expToNextLvl = gExperienceTables[gBaseStats[species].growthRate][level + 1] - currLvlExp;
    SetBattleBarStruct(bank, gHealthBoxesIds[bank], expToNextLvl, exp, -gainedExp);
    PlaySE(SE_EXP);
    gTasks[taskId].func = sub_8059400;
}

static void sub_8059400(u8 taskId)
{
    if (gTasks[taskId].tExpTask_frames < 13)
    {
        gTasks[taskId].tExpTask_frames++;
    }
    else
    {
        u8 monId = gTasks[taskId].tExpTask_monId;
        s16 gainedExp = gTasks[taskId].tExpTask_gainedExp;
        u8 bank = gTasks[taskId].tExpTask_bank;
        s16 r4;

        r4 = sub_8074AA0(bank, gHealthBoxesIds[bank], EXP_BAR, 0);
        SetHealthboxSpriteVisible(gHealthBoxesIds[bank]);
        if (r4 == -1)
        {
            u8 level;
            s32 currExp;
            u16 species;
            s32 expOnNextLvl;

            m4aSongNumStop(SE_EXP);
            level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
            currExp = GetMonData(&gPlayerParty[monId], MON_DATA_EXP);
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);
            expOnNextLvl = gExperienceTables[gBaseStats[species].growthRate][level + 1];

            if (currExp + gainedExp >= expOnNextLvl)
            {
                u8 savedActiveBank;

                SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &expOnNextLvl);
                CalculateMonStats(&gPlayerParty[monId]);
                gainedExp -= expOnNextLvl - currExp;
                savedActiveBank = gActiveBank;
                gActiveBank = bank;
                EmitTwoReturnValues(1, RET_VALUE_LEVELLED_UP, gainedExp);
                gActiveBank = savedActiveBank;
                gTasks[taskId].func = sub_8059544;
            }
            else
            {
                currExp += gainedExp;
                SetMonData(&gPlayerParty[monId], MON_DATA_EXP, &currExp);
                gBattleBankFunc[bank] = CompleteOnInactiveTextPrinter;
                DestroyTask(taskId);
            }
        }
    }
}

static void sub_8059544(u8 taskId)
{
    u8 bank = gTasks[taskId].tExpTask_bank;
    u8 monIndex = gTasks[taskId].tExpTask_monId;

    if (IsDoubleBattle() == TRUE && monIndex == gBattlePartyID[bank ^ BIT_MON])
        bank ^= BIT_MON;

    DoSpecialBattleAnimation(bank, bank, bank, B_ANIM_LVL_UP);
    gTasks[taskId].func = sub_80595A4;
}

static void sub_80595A4(u8 taskId)
{
    u8 bank = gTasks[taskId].tExpTask_bank;

    if (!gBattleSpritesDataPtr->healthBoxesData[bank].specialAnimActive)
    {
        u8 monIndex = gTasks[taskId].tExpTask_monId;

        GetMonData(&gPlayerParty[monIndex], MON_DATA_LEVEL);  // Unused return value

        if (IsDoubleBattle() == TRUE && monIndex == gBattlePartyID[bank ^ BIT_MON])
            UpdateHealthboxAttribute(gHealthBoxesIds[bank ^ BIT_MON], &gPlayerParty[monIndex], HEALTHBOX_ALL);
        else
            UpdateHealthboxAttribute(gHealthBoxesIds[bank], &gPlayerParty[monIndex], HEALTHBOX_ALL);

        gTasks[taskId].func = DestroyExpTaskAndCompleteOnInactiveTextPrinter;
    }
}

static void DestroyExpTaskAndCompleteOnInactiveTextPrinter(u8 taskId)
{
    u8 monIndex;
    u8 bank;

    monIndex = gTasks[taskId].tExpTask_monId;
    GetMonData(&gPlayerParty[monIndex], MON_DATA_LEVEL);  // Unused return value
    bank = gTasks[taskId].tExpTask_bank;
    gBattleBankFunc[bank] = CompleteOnInactiveTextPrinter;
    DestroyTask(taskId);
}

static void sub_80596A8(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].pos1.y + gSprites[gBankSpriteIds[gActiveBank]].pos2.y > DISPLAY_HEIGHT)
    {
        u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

        nullsub_24(species);
        FreeOamMatrix(gSprites[gBankSpriteIds[gActiveBank]].oam.matrixNum);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        PlayerBufferExecCompleted();
    }
}

static void sub_8059744(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        PlayerBufferExecCompleted();
    }
}

static void CompleteOnInactiveTextPrinter2(void)
{
    if (!IsTextPrinterActive(0))
        PlayerBufferExecCompleted();
}

static void sub_80597CC(void)
{
    if (!gPaletteFade.active)
    {
        u8 r4;

        gBattleBankFunc[gActiveBank] = sub_8059828;
        r4 = gTasks[gUnknown_03005D7C[gActiveBank]].data[0];
        DestroyTask(gUnknown_03005D7C[gActiveBank]);
        FreeAllWindowBuffers();
        sub_81B89AC(r4);
    }
}

static void sub_8059828(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gUnknown_0203CEE8 == 1)
            EmitChosenMonReturnValue(1, gUnknown_0203CEE9, gUnknown_0203CF00);
        else
            EmitChosenMonReturnValue(1, 6, NULL);

        if ((gBattleBufferA[gActiveBank][1] & 0xF) == 1)
            PrintLinkStandbyMsg();

        PlayerBufferExecCompleted();
    }
}

static void OpenBagAndChooseItem(void)
{
    if (!gPaletteFade.active)
    {
        gBattleBankFunc[gActiveBank] = CompleteWhenChoseItem;
        nullsub_35();
        FreeAllWindowBuffers();
        sub_81AABB0();
    }
}

static void CompleteWhenChoseItem(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        EmitOneReturnValue(1, gScriptItemId);
        PlayerBufferExecCompleted();
    }
}

static void CompleteOnSpecialAnimDone(void)
{
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        PlayerBufferExecCompleted();
}

static void DoHitAnimBlinkSpriteEffect(void)
{
    u8 spriteId = gBankSpriteIds[gActiveBank];

    if (gSprites[spriteId].data1 == 32)
    {
        gSprites[spriteId].data1 = 0;
        gSprites[spriteId].invisible = 0;
        gDoingBattleAnim = FALSE;
        PlayerBufferExecCompleted();
    }
    else
    {
        if ((gSprites[spriteId].data1 % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data1++;
    }
}

static void PlayerHandleUnknownYesNoInput(void)
{
    if (gMain.newKeys & DPAD_UP && gMultiUsePlayerCursor != 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 0;
        BattleCreateYesNoCursorAt(0);
    }
    if (gMain.newKeys & DPAD_DOWN && gMultiUsePlayerCursor == 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
    }
    if (gMain.newKeys & A_BUTTON)
    {
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
        PlaySE(SE_SELECT);

        if (gMultiUsePlayerCursor != 0)
            EmitTwoReturnValues(1, 0xE, 0);
        else
            EmitTwoReturnValues(1, 0xD, 0);

        PlayerBufferExecCompleted();
    }
    if (gMain.newKeys & B_BUTTON)
    {
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
        PlaySE(SE_SELECT);
        PlayerBufferExecCompleted();
    }
}

static void MoveSelectionDisplayMoveNames(void)
{
    s32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);
    gNumberOfMovesToChoose = 0;

    for (i = 0; i < 4; i++)
    {
        MoveSelectionDestroyCursorAt(i);
        StringCopy(gDisplayedStringBattle, gMoveNames[moveInfo->moves[i]]);
        BattleHandleAddTextPrinter(gDisplayedStringBattle, i + 3);
        if (moveInfo->moves[i] != MOVE_NONE)
            gNumberOfMovesToChoose++;
    }
}

static void MoveSelectionDisplayPpString(void)
{
    StringCopy(gDisplayedStringBattle, gText_MoveInterfacePP);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 7);
}

static void MoveSelectionDisplayPpNumber(void)
{
    u8 *txtPtr;
    struct ChooseMoveStruct *moveInfo;

    if (gBattleBufferA[gActiveBank][2] == TRUE) // check if we didn't want to display pp number
        return;

    SetPpNumbersPaletteInMoveSelection();
    moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, moveInfo->currentPp[gMoveSelectionCursor[gActiveBank]], STR_CONV_MODE_RIGHT_ALIGN, 2);
    txtPtr[0] = CHAR_SLASH;
    txtPtr++;
    ConvertIntToDecimalStringN(txtPtr, moveInfo->maxPp[gMoveSelectionCursor[gActiveBank]], STR_CONV_MODE_RIGHT_ALIGN, 2);

    BattleHandleAddTextPrinter(gDisplayedStringBattle, 9);
}

static void MoveSelectionDisplayMoveType(void)
{
    u8 *txtPtr;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);

    txtPtr = StringCopy(gDisplayedStringBattle, gText_MoveInterfaceType);
    txtPtr[0] = EXT_CTRL_CODE_BEGIN;
    txtPtr++;
    txtPtr[0] = 6;
    txtPtr++;
    txtPtr[0] = 1;
    txtPtr++;

    StringCopy(txtPtr, gTypeNames[gBattleMoves[moveInfo->moves[gMoveSelectionCursor[gActiveBank]]].type]);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 10);
}

static void MoveSelectionCreateCursorAt(u8 cursorPosition, u8 arg1)
{
    u16 src[2];
    src[0] = arg1 + 1;
    src[1] = arg1 + 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

static void MoveSelectionDestroyCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void ActionSelectionCreateCursorAt(u8 cursorPosition, u8 arg1)
{
    u16 src[2];
    src[0] = 1;
    src[1] = 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 7 * (cursorPosition & 1) + 16, 35 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void ActionSelectionDestroyCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 7 * (cursorPosition & 1) + 16, 35 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void SetCB2ToReshowScreenAfterMenu(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

void SetCB2ToReshowScreenAfterMenu2(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

static void CompleteOnFinishedStatusAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].statusAnimActive)
        PlayerBufferExecCompleted();
}

static void CompleteOnFinishedBattleAnimation(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animFromTableActive)
        PlayerBufferExecCompleted();
}

static void PrintLinkStandbyMsg(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        BattleHandleAddTextPrinter(gText_LinkStandby, 0);
    }
}

static void PlayerHandleGetMonData(void)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two pokemon, trying to get more will result in overwriting data
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        size += CopyPlayerMonData(gBattlePartyID[gActiveBank], monData);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                size += CopyPlayerMonData(i, monData + size);
            monToCheck >>= 1;
        }
    }
    EmitDataTransfer(1, size, monData);
    PlayerBufferExecCompleted();
}

static u32 CopyPlayerMonData(u8 monId, u8 *dst)
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

void PlayerHandleGetRawMonData(void)
{
    struct BattlePokemon battleMon;
    u8 *src = (u8 *)&gPlayerParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 *dst = (u8 *)&battleMon + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = src[i];

    EmitDataTransfer(1, gBattleBufferA[gActiveBank][2], dst);
    PlayerBufferExecCompleted();
}

static void PlayerHandleSetMonData(void)
{
    u8 monToCheck;
    u8 i;

    if (gBattleBufferA[gActiveBank][2] == 0)
    {
        SetPlayerMonData(gBattlePartyID[gActiveBank]);
    }
    else
    {
        monToCheck = gBattleBufferA[gActiveBank][2];
        for (i = 0; i < 6; i++)
        {
            if (monToCheck & 1)
                SetPlayerMonData(i);
            monToCheck >>= 1;
        }
    }
    PlayerBufferExecCompleted();
}

static void SetPlayerMonData(u8 monId)
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

    sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
}

static void PlayerHandleSetRawMonData(void)
{
    u8 *dst = (u8 *)&gPlayerParty[gBattlePartyID[gActiveBank]] + gBattleBufferA[gActiveBank][1];
    u8 i;

    for (i = 0; i < gBattleBufferA[gActiveBank][2]; i++)
        dst[i] = gBattleBufferA[gActiveBank][3 + i];

    PlayerBufferExecCompleted();
}

static void PlayerHandleLoadMonSprite(void)
{
    BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gBattleBankFunc[gActiveBank] = CompleteOnBankSpritePosX_0;
}

static void PlayerHandleSwitchInAnim(void)
{
    ClearTemporarySpeciesSpriteData(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattlePartyID[gActiveBank] = gBattleBufferA[gActiveBank][1];
    BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
    gActionSelectionCursor[gActiveBank] = 0;
    gMoveSelectionCursor[gActiveBank] = 0;
    sub_805B258(gActiveBank, gBattleBufferA[gActiveBank][2]);
    gBattleBankFunc[gActiveBank] = sub_805902C;
}

static void sub_805B258(u8 bank, bool8 dontClearSubstituteBit)
{
    u16 species;

    ClearTemporarySpeciesSpriteData(bank, dontClearSubstituteBit);
    gBattlePartyID[bank] = gBattleBufferA[bank][1];
    species = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES);
    gUnknown_03005D7C[bank] = CreateInvisibleSpriteWithCallback(sub_805D714);
    sub_806A068(species, GetBankIdentity(bank));

    gBankSpriteIds[bank] = CreateSprite(
      &gUnknown_0202499C,
      sub_80A5C6C(bank, 2),
      sub_80A6138(bank),
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

static void PlayerHandleReturnMonToBall(void)
{
    if (gBattleBufferA[gActiveBank][1] == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
        gBattleBankFunc[gActiveBank] = DoSwitchOutAnimation;
    }
    else
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        PlayerBufferExecCompleted();
    }
}

static void DoSwitchOutAnimation(void)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SWITCH_OUT_PLAYER_MON);
            gBattleBankFunc[gActiveBank] = sub_8059744;
        }
        break;
    }
}

// some explanation here
// in emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven) that use the back pic as well as animate it
static void PlayerHandleDrawTrainerPic(void)
{
    s16 xPos, yPos;
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
            || (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_RED;
        }
        else if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_RUBY
                 || (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_SAPPHIRE)
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_RS_BRENDAN;
        }
        else
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
        }
    }
    else
    {
        trainerPicId = gSaveBlock2Ptr->playerGender;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if ((GetBankIdentity(gActiveBank) & BIT_MON) != 0) // second mon
            xPos = 90;
        else // first mon
            xPos = 32;

        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != STEVEN_PARTNER_ID)
        {
            xPos = 90;
            yPos = (8 - gTrainerFrontPicCoords[trainerPicId].coords) * 4 + 80;
        }
        else
        {
            yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
        }

    }
    else
    {
        xPos = 80;
        yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
    }

    // Use front pic table for any tag battles unless your partner is Steven.
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != STEVEN_PARTNER_ID)
    {
        trainerPicId = PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender);
        DecompressTrainerFrontPic(trainerPicId, gActiveBank);
        sub_806A1C0(trainerPicId, GetBankIdentity(gActiveBank));
        gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, xPos, yPos, sub_80A82E4(gActiveBank));

        gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = IndexOfSpritePaletteTag(gTrainerFrontPicPaletteTable[trainerPicId].tag);
        gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 240;
        gSprites[gBankSpriteIds[gActiveBank]].pos2.y = 48;
        gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
        gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;
        gSprites[gBankSpriteIds[gActiveBank]].oam.affineMode = 0;
        gSprites[gBankSpriteIds[gActiveBank]].hFlip = 1;
    }
    // use the back pic in any other scenario
    else
    {
        DecompressTrainerBackPic(trainerPicId, gActiveBank);
        sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
        gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, xPos, yPos, sub_80A82E4(gActiveBank));

        gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
        gSprites[gBankSpriteIds[gActiveBank]].pos2.x = 240;
        gSprites[gBankSpriteIds[gActiveBank]].data0 = -2;
        gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;
    }

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy;
}

static void PlayerHandleTrainerSlide(void)
{
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
            || (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_RED;
        }
        else if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_RUBY
                 || (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_SAPPHIRE)
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_RS_BRENDAN;
        }
        else
        {
            trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
        }
    }
    else
    {
        trainerPicId = gSaveBlock2Ptr->playerGender;
    }

    DecompressTrainerBackPic(trainerPicId, gActiveBank);
    sub_806A12C(trainerPicId, GetBankIdentity(gActiveBank));
    gBankSpriteIds[gActiveBank] = CreateSprite(&gUnknown_0202499C, 80, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, 30);

    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = gActiveBank;
    gSprites[gBankSpriteIds[gActiveBank]].pos2.x = -96;
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 2;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_805D7AC;

    gBattleBankFunc[gActiveBank] = CompleteOnBankSpriteCallbackDummy2;
}

static void PlayerHandleTrainerSlideBack(void)
{
    oamt_add_pos2_onto_pos1(&gSprites[gBankSpriteIds[gActiveBank]]);
    gSprites[gBankSpriteIds[gActiveBank]].data0 = 50;
    gSprites[gBankSpriteIds[gActiveBank]].data2 = -40;
    gSprites[gBankSpriteIds[gActiveBank]].data4 = gSprites[gBankSpriteIds[gActiveBank]].pos1.y;
    gSprites[gBankSpriteIds[gActiveBank]].callback = sub_80A6EEC;
    StoreSpriteCallbackInData6(&gSprites[gBankSpriteIds[gActiveBank]], SpriteCallbackDummy);
    StartSpriteAnim(&gSprites[gBankSpriteIds[gActiveBank]], 1);
    gBattleBankFunc[gActiveBank] = sub_80588B4;
}

static void PlayerHandleFaintAnimation(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState == 0)
    {
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
            PlaySE12WithPanning(SE_POKE_DEAD, PAN_SIDE_PLAYER);
            gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
            gSprites[gBankSpriteIds[gActiveBank]].data2 = 5;
            gSprites[gBankSpriteIds[gActiveBank]].callback = sub_8039C00;
            gBattleBankFunc[gActiveBank] = sub_80596A8;
        }
    }
}

static void PlayerHandlePaletteFade(void)
{
    BeginNormalPaletteFade(-1, 2, 0, 16, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleSuccessBallThrowAnim(void)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    gDoingBattleAnim = TRUE;
    DoSpecialBattleAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnSpecialAnimDone;
}

static void PlayerHandleBallThrowAnim(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBank][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gDoingBattleAnim = TRUE;
    DoSpecialBattleAnimation(gActiveBank, gActiveBank, GetBankByIdentity(IDENTITY_OPPONENT_MON1), B_ANIM_BALL_THROW);
    gBattleBankFunc[gActiveBank] = CompleteOnSpecialAnimDone;
}

static void PlayerHandlePause(void)
{
    u8 var = gBattleBufferA[gActiveBank][1];

    // WTF is this??
    while (var != 0)
        var--;

    PlayerBufferExecCompleted();
}

static void PlayerHandleMoveAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
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
            PlayerBufferExecCompleted();
        }
        else
        {
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            gBattleBankFunc[gActiveBank] = PlayerDoMoveAnimation;
            sub_817E0FC(move, gWeatherMoveAnim, gAnimDisableStructPtr);
        }
    }
}

static void PlayerDoMoveAnimation(void)
{
    u16 move = gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8);
    u8 multihit = gBattleBufferA[gActiveBank][11];

    switch (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute
            && !gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8)
        {
            gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8 = 1;
            DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_SUBSTITUTE_TO_MON);
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
            if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute && multihit < 2)
            {
                DoSpecialBattleAnimation(gActiveBank, gActiveBank, gActiveBank, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->bankData[gActiveBank].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].specialAnimActive)
        {
            sub_805E394();
            TrySetBehindSubstituteSpriteBit(gActiveBank, gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].animationState = 0;
            PlayerBufferExecCompleted();
        }
        break;
    }
}

static void PlayerHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16*)(&gBattleBufferA[gActiveBank][2]);
    BufferStringBattle(*stringId);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 0);
    gBattleBankFunc[gActiveBank] = CompleteOnInactiveTextPrinter2;
    sub_817C95C(*stringId);
    sub_81A57E4(gActiveBank, *stringId);
}

static void PlayerHandlePrintStringPlayerOnly(void)
{
    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        PlayerHandlePrintString();
    else
        PlayerBufferExecCompleted();
}

static void HandleChooseActionAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 160;
        gBattleBankFunc[gActiveBank] = HandleInputChooseAction;
    }
}

static void PlayerHandleChooseAction(void)
{
    s32 i;

    gBattleBankFunc[gActiveBank] = HandleChooseActionAfterDma3;
    sub_817F2A8();
    BattleHandleAddTextPrinter(gText_BattleMenu, 2);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[gActiveBank], 0);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo);
    BattleHandleAddTextPrinter(gDisplayedStringBattle, 1);
}

static void PlayerHandleUnknownYesNoBox(void)
{
    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
        BattleHandleAddTextPrinter(gText_BattleYesNoChoice, 12);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
        gBattleBankFunc[gActiveBank] = PlayerHandleUnknownYesNoInput;
    }
    else
    {
        PlayerBufferExecCompleted();
    }
}

static void HandleChooseMoveAfterDma3(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 320;
        gBattleBankFunc[gActiveBank] = HandleInputChooseMove;
    }
}

static void PlayerChooseMoveInBattlePalace(void)
{
    if (--*(gBattleStruct->field_298 + gActiveBank) == 0)
    {
        gBattlePalaceMoveSelectionRngValue = gRngValue;
        EmitTwoReturnValues(1, 10, ChooseMoveAndTargetInBattlePalace());
        PlayerBufferExecCompleted();
    }
}

static void PlayerHandleChooseMove(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        *(gBattleStruct->field_298 + gActiveBank) = 8;
        gBattleBankFunc[gActiveBank] = PlayerChooseMoveInBattlePalace;
    }
    else
    {
        InitMoveSelectionsVarsAndStrings();
        gBattleBankFunc[gActiveBank] = HandleChooseMoveAfterDma3;
    }
}

void InitMoveSelectionsVarsAndStrings(void)
{
    MoveSelectionDisplayMoveNames();
    gMultiUsePlayerCursor = 0xFF;
    MoveSelectionCreateCursorAt(gMoveSelectionCursor[gActiveBank], 0);
    MoveSelectionDisplayPpString();
    MoveSelectionDisplayPpNumber();
    MoveSelectionDisplayMoveType();
}

static void PlayerHandleChooseItem(void)
{
    s32 i;

    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gBattleBankFunc[gActiveBank] = OpenBagAndChooseItem;
    gBankInMenu = gActiveBank;

    for (i = 0; i < 3; i++)
        gUnknown_0203CF00[i] = gBattleBufferA[gActiveBank][1 + i];
}

static void PlayerHandleChoosePokemon(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
        gUnknown_0203CF00[i] = gBattleBufferA[gActiveBank][4 + i];

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA && (gBattleBufferA[gActiveBank][1] & 0xF) != 2)
    {
        EmitChosenMonReturnValue(1, gBattlePartyID[gActiveBank] + 1, gUnknown_0203CF00);
        PlayerBufferExecCompleted();
    }
    else
    {
        gUnknown_03005D7C[gActiveBank] = CreateTask(TaskDummy, 0xFF);
        gTasks[gUnknown_03005D7C[gActiveBank]].data[0] = gBattleBufferA[gActiveBank][1] & 0xF;
        *(&gBattleStruct->field_49) = gBattleBufferA[gActiveBank][1] >> 4;
        *(&gBattleStruct->field_8B) = gBattleBufferA[gActiveBank][2];
        *(&gBattleStruct->field_B0) = gBattleBufferA[gActiveBank][3];
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gBattleBankFunc[gActiveBank] = sub_80597CC;
        gBankInMenu = gActiveBank;
    }
}

static void PlayerHandleCmd23(void)
{
    BattleMusicStop();
    BeginNormalPaletteFade(-1, 2, 0, 16, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleHealthBarUpdate(void)
{
    s16 hpVal;

    LoadBattleBarGfx(0);
    hpVal = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    if (hpVal > 0)
        gUnknown_0203CD70 += hpVal;

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

static void PlayerHandleExpUpdate(void)
{
    u8 monId = gBattleBufferA[gActiveBank][1];

    if (GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL) >= MAX_MON_LEVEL)
    {
        PlayerBufferExecCompleted();
    }
    else
    {
        s16 expPointsToGive;
        u8 taskId;

        LoadBattleBarGfx(1);
        GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES);  // unused return value
        expPointsToGive = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);
        taskId = CreateTask(Task_GiveExpToMon, 10);
        gTasks[taskId].tExpTask_monId = monId;
        gTasks[taskId].tExpTask_gainedExp = expPointsToGive;
        gTasks[taskId].tExpTask_bank = gActiveBank;
        gBattleBankFunc[gActiveBank] = nullsub_21;
    }
}

#undef tExpTask_monId
#undef tExpTask_gainedExp
#undef tExpTask_bank
#undef tExpTask_frames

static void PlayerHandleStatusIconUpdate(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 bank;

        UpdateHealthboxAttribute(gHealthBoxesIds[gActiveBank], &gPlayerParty[gBattlePartyID[gActiveBank]], HEALTHBOX_STATUS_ICON);
        bank = gActiveBank;
        gBattleSpritesDataPtr->healthBoxesData[bank].statusAnimActive = 0;
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void PlayerHandleStatusAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        DoStatusAnimation(gBattleBufferA[gActiveBank][1],
                        gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8) | (gBattleBufferA[gActiveBank][4] << 16) | (gBattleBufferA[gActiveBank][5] << 24));
        gBattleBankFunc[gActiveBank] = CompleteOnFinishedStatusAnimation;
    }
}

static void PlayerHandleStatusXor(void)
{
    u8 val = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_STATUS) ^ gBattleBufferA[gActiveBank][1];

    SetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_STATUS, &val);
    PlayerBufferExecCompleted();
}

static void PlayerHandleDataTransfer(void)
{
    PlayerBufferExecCompleted();
}

static void PlayerHandleDMA3Transfer(void)
{
    u32 dstArg = gBattleBufferA[gActiveBank][1]
            | (gBattleBufferA[gActiveBank][2] << 8)
            | (gBattleBufferA[gActiveBank][3] << 16)
            | (gBattleBufferA[gActiveBank][4] << 24);
    u16 sizeArg = gBattleBufferA[gActiveBank][5] | (gBattleBufferA[gActiveBank][6] << 8);

    const u8 *src = &gBattleBufferA[gActiveBank][7];
    u8 *dst = (u8*)(dstArg);
    u32 size = sizeArg;

    while (1)
    {
        if (size <= 0x1000)
        {
            DmaCopy16(3, src, dst, size);
            break;
        }
        DmaCopy16(3, src, dst, 0x1000);
        src += 0x1000;
        dst += 0x1000;
        size -= 0x1000;
    }
    PlayerBufferExecCompleted();
}

static void PlayerHandlePlayBGM(void)
{
    PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd32(void)
{
    PlayerBufferExecCompleted();
}

static void PlayerHandleTwoReturnValues(void)
{
    EmitTwoReturnValues(1, 0, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleChosenMonReturnValue(void)
{
    EmitChosenMonReturnValue(1, 0, NULL);
    PlayerBufferExecCompleted();
}

static void PlayerHandleOneReturnValue(void)
{
    EmitOneReturnValue(1, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleOneReturnValue_Duplicate(void)
{
    EmitOneReturnValue_Duplicate(1, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd37(void)
{
    gUnknown_02022D0C.field_0 = 0;
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd38(void)
{
    gUnknown_02022D0C.field_0 = gBattleBufferA[gActiveBank][1];
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd39(void)
{
    gUnknown_02022D0C.flag_x80 = 0;
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd40(void)
{
    gUnknown_02022D0C.flag_x80 ^= 1;
    PlayerBufferExecCompleted();
}

static void PlayerHandleHitAnimation(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].invisible == TRUE)
    {
        PlayerBufferExecCompleted();
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBankSpriteIds[gActiveBank]].data1 = 0;
        DoHitAnimHealthboxEffect(gActiveBank);
        gBattleBankFunc[gActiveBank] = DoHitAnimBlinkSpriteEffect;
    }
}

static void PlayerHandleCmd42(void)
{
    PlayerBufferExecCompleted();
}

static void PlayerHandleEffectivenessSound(void)
{
    s8 pan;

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        pan = PAN_SIDE_PLAYER;
    else
        pan = PAN_SIDE_OPPONENT;

    PlaySE12WithPanning(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8), pan);
    PlayerBufferExecCompleted();
}

static void PlayerHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBank][3])
    {
        BattleMusicStop();
        PlayBGM(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBank][1] | (gBattleBufferA[gActiveBank][2] << 8));
    }

    PlayerBufferExecCompleted();
}

static void PlayerHandleFaintingCry(void)
{
    u16 species = GetMonData(&gPlayerParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES);

    PlayCry3(species, -25, 5);
    PlayerBufferExecCompleted();
}

static void PlayerHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBank][1]);
    gUnknown_020243FC |= 1;
    PlayerBufferExecCompleted();
}

static void PlayerHandleIntroTrainerBallThrow(void)
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
    LoadCompressedPalette(gTrainerBackPicPaletteTable[gSaveBlock2Ptr->playerGender].data, 0x100 + paletteNum * 16, 32);
    gSprites[gBankSpriteIds[gActiveBank]].oam.paletteNum = paletteNum;

    taskId = CreateTask(task05_08033660, 5);
    gTasks[taskId].data[0] = gActiveBank;

    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;

    gBattleSpritesDataPtr->animationData->field_9_x1 = 1;
    gBattleBankFunc[gActiveBank] = nullsub_21;
}

void sub_805CC00(struct Sprite *sprite)
{
    u8 bank = sprite->data5;

    FreeSpriteOamMatrix(sprite);
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));
    DestroySprite(sprite);
    BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[bank]], bank);
    StartSpriteAnim(&gSprites[gBankSpriteIds[bank]], 0);
}

static void task05_08033660(u8 taskId)
{
    if (gTasks[taskId].data[1] < 31)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        u8 savedActiveBank = gActiveBank;

        gActiveBank = gTasks[taskId].data[0];
        if (!IsDoubleBattle() || (gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            sub_805B258(gActiveBank, FALSE);
        }
        else
        {
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            sub_805B258(gActiveBank, FALSE);
            gActiveBank ^= BIT_MON;
            gBattleBufferA[gActiveBank][1] = gBattlePartyID[gActiveBank];
            BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
            sub_805B258(gActiveBank, FALSE);
            gActiveBank ^= BIT_MON;
        }
        gBattleBankFunc[gActiveBank] = sub_8058B40;
        gActiveBank = savedActiveBank;
        DestroyTask(taskId);
    }
}

static void PlayerHandleDrawPartyStatusSummary(void)
{
    if (gBattleBufferA[gActiveBank][1] != 0 && GetBankSide(gActiveBank) == SIDE_PLAYER)
    {
        PlayerBufferExecCompleted();
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1 = 1;
        gUnknown_020244B4[gActiveBank] = CreatePartyStatusSummarySprites(gActiveBank, (struct HpAndStatus *)&gBattleBufferA[gActiveBank][4], gBattleBufferA[gActiveBank][1], gBattleBufferA[gActiveBank][2]);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;

        if (gBattleBufferA[gActiveBank][2] != 0)
            gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0x5D;

        gBattleBankFunc[gActiveBank] = sub_805CE38;
    }
}

static void sub_805CE38(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5++ > 0x5C)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_5 = 0;
        PlayerBufferExecCompleted();
    }
}

static void PlayerHandleCmd49(void)
{
    if (gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x1)
        gTasks[gUnknown_020244B4[gActiveBank]].func = sub_8073C30;
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd50(void)
{
    dp11b_obj_free(gActiveBank, 1);
    dp11b_obj_free(gActiveBank, 0);
    PlayerBufferExecCompleted();
}

static void PlayerHandleSpriteInvisibility(void)
{
    if (IsBankSpritePresent(gActiveBank))
    {
        gSprites[gBankSpriteIds[gActiveBank]].invisible = gBattleBufferA[gActiveBank][1];
        CopyBattleSpriteInvisibility(gActiveBank);
    }
    PlayerBufferExecCompleted();
}

static void PlayerHandleBattleAnimation(void)
{
    if (!mplay_80342A4(gActiveBank))
    {
        u8 animationId = gBattleBufferA[gActiveBank][1];
        u16 argument = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

        if (DoBattleAnimationFromTable(gActiveBank, gActiveBank, gActiveBank, animationId, argument))
            PlayerBufferExecCompleted();
        else
            gBattleBankFunc[gActiveBank] = CompleteOnFinishedBattleAnimation;

        sub_817E32C(animationId);
    }
}

static void PlayerHandleLinkStandbyMsg(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][2]);
    switch (gBattleBufferA[gActiveBank][1])
    {
    case 0:
        PrintLinkStandbyMsg();
        // fall through
    case 1:
        dp11b_obj_free(gActiveBank, 1);
        dp11b_obj_free(gActiveBank, 0);
        break;
    case 2:
        PrintLinkStandbyMsg();
        break;
    }
    PlayerBufferExecCompleted();
}

static void PlayerHandleResetActionMoveSelection(void)
{
    switch (gBattleBufferA[gActiveBank][1])
    {
    case RESET_ACTION_MOVE_SELECTION:
        gActionSelectionCursor[gActiveBank] = 0;
        gMoveSelectionCursor[gActiveBank] = 0;
        break;
    case RESET_ACTION_SELECTION:
        gActionSelectionCursor[gActiveBank] = 0;
        break;
    case RESET_MOVE_SELECTION:
        gMoveSelectionCursor[gActiveBank] = 0;
        break;
    }
    PlayerBufferExecCompleted();
}

static void PlayerHandleCmd55(void)
{
    sub_81851A8(&gBattleBufferA[gActiveBank][4]);
    gBattleOutcome = gBattleBufferA[gActiveBank][1];
    gSaveBlock2Ptr->field_CA9_b = gBattleBufferA[gActiveBank][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    PlayerBufferExecCompleted();
    gBattleBankFunc[gActiveBank] = sub_80587B0;
}

static void nullsub_22(void)
{
}
