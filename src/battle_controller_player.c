#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_anim.h"
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

extern u32 gBattleExecBuffer;
extern u8 gActiveBank;
extern u8 gBankSpriteIds[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gAbsentBankFlags;
extern u8 gNoOfAllBanks;
extern bool8 gDoingBattleAnim;
extern u8 gUnknown_020244CC;
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern void (*gPreBattleCallback1)(void);
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gMultiUsePlayerCursor;
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern struct MusicPlayerInfo gMPlay_BGM;

extern const struct BattleMove gBattleMoves[];

extern void dp11b_obj_instanciate(u8, u8, s8, s8);
extern void dp11b_obj_free(u8, u8);
extern void sub_800AC34(void);

// this file's functions
void PlayerHandleGetMonData(void);
void PlayerHandleGetRawMonData(void);
void PlayerHandleSetMonData(void);
void PlayerHandleSetRawMonData(void);
void PlayerHandleLoadMonSprite(void);
void PlayerHandleSwitchInAnim(void);
void PlayerHandleReturnMonToBall(void);
void PlayerHandleDrawTrainerPic(void);
void PlayerHandleTrainerSlide(void);
void PlayerHandleTrainerSlideBack(void);
void PlayerHandleFaintAnimation(void);
void PlayerHandleCmd11(void);
void PlayerHandleCmd12(void);
void PlayerHandleBallThrow(void);
void PlayerHandlePause(void);
void PlayerHandleMoveAnimation(void);
void PlayerHandlePrintString(void);
void PlayerHandlePrintStringPlayerOnly(void);
void PlayerHandleChooseAction(void);
void PlayerHandleCmd19(void);
void PlayerHandleChooseMove(void);
void PlayerHandleOpenBag(void);
void PlayerHandleChoosePokemon(void);
void PlayerHandleCmd23(void);
void PlayerHandleHealthBarUpdate(void);
void PlayerHandleExpUpdate(void);
void PlayerHandleStatusIconUpdate(void);
void PlayerHandleStatusAnimation(void);
void PlayerHandleStatusXor(void);
void PlayerHandleDataTransfer(void);
void PlayerHandleDMA3Transfer(void);
void PlayerHandlePlayBGM(void);
void PlayerHandleCmd32(void);
void PlayerHandleCmd33(void);
void PlayerHandleCmd34(void);
void PlayerHandleCmd35(void);
void PlayerHandleCmd36(void);
void PlayerHandleCmd37(void);
void PlayerHandleCmd38(void);
void PlayerHandleCmd39(void);
void PlayerHandleCmd40(void);
void PlayerHandleHitAnimation(void);
void PlayerHandleCmd42(void);
void PlayerHandleEffectivenessSound(void);
void PlayerHandlePlayFanfareOrBGM(void);
void PlayerHandleFaintingCry(void);
void PlayerHandleIntroSlide(void);
void PlayerHandleIntroTrainerBallThrow(void);
void PlayerHandleDrawPartyStatusSummary(void);
void PlayerHandleCmd49(void);
void PlayerHandleCmd50(void);
void PlayerHandleSpriteInvisibility(void);
void PlayerHandleBattleAnimation(void);
void PlayerHandleLinkStandbyMsg(void);
void PlayerHandleResetActionMoveSelection(void);
void PlayerHandleCmd55(void);
void nullsub_22(void);

void PlayerBufferRunCommand(void);
void HandleInputChooseTarget(void);
void HandleInputChooseMove(void);
void MoveSelectionCreateCursorAt(u8 cursorPos, u8 arg1);
void MoveSelectionDestroyCursorAt(u8 cursorPos);
void MoveSelectionDisplayPpNumber(void);
void MoveSelectionDisplayPpString(void);
void MoveSelectionDisplayMoveType(void);
void MoveSelectionDisplayMoveNames(void);
void HandleMoveSwitchting(void);
void sub_8058FC0(void);
void sub_8059828(void);
void sub_80598E0(void);
void sub_8059544(u8 taskId);
void sub_8059330(u8 taskId);
void DestroyExpTaskAndCompleteOnInactiveTextPrinter(u8 taskId);
void sub_8059400(u8 taskId);
void sub_80595A4(u8 taskId);
void PrintLinkStandbyMsg(void);

void (*const gPlayerBufferCommands[CONTOLLER_CMDS_COUNT])(void) =
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
    PlayerHandleCmd11,
    PlayerHandleCmd12,
    PlayerHandleBallThrow,
    PlayerHandlePause,
    PlayerHandleMoveAnimation,
    PlayerHandlePrintString,
    PlayerHandlePrintStringPlayerOnly,
    PlayerHandleChooseAction,
    PlayerHandleCmd19,
    PlayerHandleChooseMove,
    PlayerHandleOpenBag,
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
    PlayerHandleCmd33,
    PlayerHandleCmd34,
    PlayerHandleCmd35,
    PlayerHandleCmd36,
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

void SetBankFuncToPlayerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = PlayerBufferRunCommand;
    gDoingBattleAnim = FALSE;
    gUnknown_020244CC = 0;
}

void PlayerBufferExecCompleted(void)
{
    gBattleBankFunc[gActiveBank] = PlayerBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(2, 4, &playerId);
        gBattleBufferA[gActiveBank][0] = CONTOLLER_CMDS_COUNT - 1;
    }
    else
    {
        gBattleExecBuffer &= ~gBitTable[gActiveBank];
    }
}

void PlayerBufferRunCommand(void)
{
    if (gBattleExecBuffer & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] < ARRAY_COUNT(gPlayerBufferCommands))
            gPlayerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        else
            PlayerBufferExecCompleted();
    }
}

void CompleteOnBankSpritePosX_0(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].pos2.x == 0)
        PlayerBufferExecCompleted();
}

void HandleInputChooseAction(void)
{
    u16 itemId = gBattleBufferA[gActiveBank][2] | (gBattleBufferA[gActiveBank][3] << 8);

    dp11b_obj_instanciate(gActiveBank, 1, 7, 1);
    dp11b_obj_instanciate(gActiveBank, 0, 7, 1);

    if (gMain.newAndRepeatedKeys & DPAD_ANY && gSaveBlock2Ptr->optionsButtonMode == 2)
        gUnknown_020244CC++;
    else
        gUnknown_020244CC = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[gActiveBank])
        {
        case ACTION_USE_MOVE:
            EmitCmd33(1, ACTION_USE_MOVE, 0);
            break;
        case ACTION_USE_ITEM:
            EmitCmd33(1, ACTION_USE_ITEM, 0);
            break;
        case ACTION_SWITCH:
            EmitCmd33(1, ACTION_SWITCH, 0);
            break;
        case ACTION_RUN:
            EmitCmd33(1, ACTION_RUN, 0);
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
    else if (gMain.newKeys & B_BUTTON || gUnknown_020244CC > 59)
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
            EmitCmd33(1, ACTION_CANCEL_PARTNER, 0);
            PlayerBufferExecCompleted();
        }
    }
    else if (gMain.newKeys & START_BUTTON)
    {
        SwapHpBarsWithHpText();
    }
}

void sub_80577F0(void) // unused
{
    dp11b_obj_free(gActiveBank, 1);
    dp11b_obj_free(gActiveBank, 0);
    gBattleBankFunc[gActiveBank] = HandleInputChooseTarget;
}

void HandleInputChooseTarget(void)
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
        gUnknown_020244CC++;
    else
        gUnknown_020244CC = 0;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gSprites[gBankSpriteIds[gMultiUsePlayerCursor]].callback = sub_8039B2C;
        EmitCmd33(1, 10, gMoveSelectionCursor[gActiveBank] | (gMultiUsePlayerCursor << 8));
        dp11b_obj_free(gMultiUsePlayerCursor, 1);
        PlayerBufferExecCompleted();
    }
    else if (gMain.newKeys & B_BUTTON || gUnknown_020244CC > 59)
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

extern u8 gNumberOfMovesToChoose;
extern const u8 gText_BattleSwitchWhich[];

void HandleInputChooseMove(void)
{
    bool32 canSelectTarget = FALSE;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);

    if (gMain.heldKeys & DPAD_ANY && gSaveBlock2Ptr->optionsButtonMode == 2)
        gUnknown_020244CC++;
    else
        gUnknown_020244CC = 0;

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
            EmitCmd33(1, 10, gMoveSelectionCursor[gActiveBank] | (gMultiUsePlayerCursor << 8));
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
    else if (gMain.newKeys & B_BUTTON || gUnknown_020244CC > 59)
    {
        PlaySE(SE_SELECT);
        EmitCmd33(1, 10, 0xFFFF);
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
            sub_814F9EC(gText_BattleSwitchWhich, 0xB);
            gBattleBankFunc[gActiveBank] = HandleMoveSwitchting;
        }
    }
}

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;

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

void HandleMoveSwitchting(void)
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

extern u8 gBattleOutcome;
extern void sub_817E3F4(void); // battle_link_817C95C

void sub_80586F8(void)
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

void CompleteOnBankSpriteCallbackDummy(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        PlayerBufferExecCompleted();
}

void CompleteOnBankSpriteCallbackDummy2(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
        PlayerBufferExecCompleted();
}

void sub_80588B4(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        nullsub_25(gSaveBlock2Ptr->playerGender);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        PlayerBufferExecCompleted();
    }
}

void sub_8058924(void)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 == 0xFF)
    {
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_9 = 0;
        PlayerBufferExecCompleted();
    }
}

extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];

extern bool8 IsDoubleBattle(void);

void sub_805896C(void)
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

extern void sub_8172EF0(u8 bank, struct Pokemon *mon);
extern void sub_8076918(u8 bank);
extern u8 gUnknown_03005D7C[];

void sub_8058B40(void)
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

extern void sub_805E408(u8 bank);
extern void move_anim_start_t4(u8 arg0, u8 atkBank, u8 defBank, u8 tableId);

void sub_8058EDC(void)
{
    if (gSprites[gHealthBoxesIds[gActiveBank]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1
     && gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        sub_805E408(gActiveBank);
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x80 = 0;
        gBattleSpritesDataPtr->healthBoxesData[gActiveBank].field_1_x1 = 0;
        FreeSpriteTilesByTag(0x27F9);
        FreeSpritePaletteByTag(0x27F9);

        if (gBattleSpritesDataPtr->bankData[gActiveBank].behindSubstitute)
            move_anim_start_t4(gActiveBank, gActiveBank, gActiveBank, 6);

        gBattleBankFunc[gActiveBank] = sub_8058FC0;
    }
}

void sub_8058FC0(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x40
        && !IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);
        PlayerBufferExecCompleted();
    }
}

void sub_805902C(void)
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

void bx_t1_healthbar_update(void)
{
    s16 hpValue = sub_8074AA0(gActiveBank, gHealthBoxesIds[gActiveBank], 0, 0);

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

void CompleteOnInactiveTextPrinter(void)
{
    if (!IsTextPrinterActive(0))
        PlayerBufferExecCompleted();
}

void sub_80591B8(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].data[0]);
    u8 bank = gTasks[taskId].data[2];
    s16 gainedExp = gTasks[taskId].data[1];

    if (IsDoubleBattle() == TRUE || monId != gBattlePartyID[bank])
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
            EmitCmd33(1, 11, gainedExp);
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
        gTasks[taskId].func = sub_8059330;
    }
}

void sub_8059330(u8 taskId)
{
    u8 monIndex = gTasks[taskId].data[0];
    s32 gainedExp = gTasks[taskId].data[1];
    u8 bank = gTasks[taskId].data[2];
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

void sub_8059400(u8 taskId)
{
    if (gTasks[taskId].data[10] < 13)
    {
        gTasks[taskId].data[10]++;
    }
    else
    {
        u8 monId = gTasks[taskId].data[0];
        s16 gainedExp = gTasks[taskId].data[1];
        u8 bank = gTasks[taskId].data[2];
        s16 r4;

        r4 = sub_8074AA0(bank, gHealthBoxesIds[bank], 1, 0);
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
                EmitCmd33(1, 11, gainedExp);
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

void sub_8059544(u8 taskId)
{
    u8 bank = gTasks[taskId].data[2];
    u8 monIndex = gTasks[taskId].data[0];

    if (IsDoubleBattle() == TRUE && monIndex == gBattlePartyID[bank ^ BIT_MON])
        bank ^= BIT_MON;

    move_anim_start_t4(bank, bank, bank, 0);
    gTasks[taskId].func = sub_80595A4;
}

void sub_80595A4(u8 taskId)
{
    u8 bank = gTasks[taskId].data[2];

    if (!gBattleSpritesDataPtr->healthBoxesData[bank].flag_x40)
    {
        u8 monIndex = gTasks[taskId].data[0];

        GetMonData(&gPlayerParty[monIndex], MON_DATA_LEVEL);  // Unused return value

        if (IsDoubleBattle() == TRUE && monIndex == gBattlePartyID[bank ^ BIT_MON])
            UpdateHealthboxAttribute(gHealthBoxesIds[bank ^ BIT_MON], &gPlayerParty[monIndex], HEALTHBOX_ALL);
        else
            UpdateHealthboxAttribute(gHealthBoxesIds[bank], &gPlayerParty[monIndex], HEALTHBOX_ALL);

        gTasks[taskId].func = DestroyExpTaskAndCompleteOnInactiveTextPrinter;
    }
}

void DestroyExpTaskAndCompleteOnInactiveTextPrinter(u8 taskId)
{
    u8 monIndex;
    u8 bank;

    monIndex = gTasks[taskId].data[0];
    GetMonData(&gPlayerParty[monIndex], MON_DATA_LEVEL);  // Unused return value
    bank = gTasks[taskId].data[2];
    gBattleBankFunc[bank] = CompleteOnInactiveTextPrinter;
    DestroyTask(taskId);
}

void sub_80596A8(void)
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

void sub_8059744(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x40)
    {
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        SetHealthboxSpriteInvisible(gHealthBoxesIds[gActiveBank]);
        PlayerBufferExecCompleted();
    }
}

void CompleteOnInactiveTextPrinter2(void)
{
    if (!IsTextPrinterActive(0))
        PlayerBufferExecCompleted();
}

extern void sub_81B89AC(u8 arg0);

void sub_80597CC(void)
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

extern u8 gUnknown_0203CEE8;
extern u8 gUnknown_0203CEE9;
extern u8 gUnknown_0203CF00[];

void sub_8059828(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gUnknown_0203CEE8 == 1)
            EmitCmd34(1, gUnknown_0203CEE9, gUnknown_0203CF00);
        else
            EmitCmd34(1, 6, NULL);

        if ((gBattleBufferA[gActiveBank][1] & 0xF) == 1)
            PrintLinkStandbyMsg();

        PlayerBufferExecCompleted();
    }
}

extern void sub_81AABB0(void);
extern void nullsub_35(void);

void sub_80598A4(void)
{
    if (!gPaletteFade.active)
    {
        gBattleBankFunc[gActiveBank] = sub_80598E0;
        nullsub_35();
        FreeAllWindowBuffers();
        sub_81AABB0();
    }
}

extern u16 gScriptItemId;

void sub_80598E0(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        EmitCmd35(1, gScriptItemId);
        PlayerBufferExecCompleted();
    }
}

void sub_805991C(void)
{
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x40)
        PlayerBufferExecCompleted();
}

void DoHitAnimBlinkEffect(void)
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

void sub_80599D4(void)
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
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
        PlaySE(SE_SELECT);

        if (gMultiUsePlayerCursor != 0)
            EmitCmd33(1, 0xE, 0);
        else
            EmitCmd33(1, 0xD, 0);

        PlayerBufferExecCompleted();
    }
    if (gMain.newKeys & B_BUTTON)
    {
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
        PlaySE(SE_SELECT);
        PlayerBufferExecCompleted();
    }
}

extern const u8 gText_MoveInterfacePP[];
extern const u8 gText_MoveInterfaceType[];

void MoveSelectionDisplayMoveNames(void)
{
    s32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleBufferA[gActiveBank][4]);
    gNumberOfMovesToChoose = 0;

    for (i = 0; i < 4; i++)
    {
        MoveSelectionDestroyCursorAt(i);
        StringCopy(gDisplayedStringBattle, gMoveNames[moveInfo->moves[i]]);
        sub_814F9EC(gDisplayedStringBattle, i + 3);
        if (moveInfo->moves[i] != MOVE_NONE)
            gNumberOfMovesToChoose++;
    }
}

void MoveSelectionDisplayPpString(void)
{
    StringCopy(gDisplayedStringBattle, gText_MoveInterfacePP);
    sub_814F9EC(gDisplayedStringBattle, 7);
}

void MoveSelectionDisplayPpNumber(void)
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

    sub_814F9EC(gDisplayedStringBattle, 9);
}

extern const u8 gTypeNames[][7];

void MoveSelectionDisplayMoveType(void)
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
    sub_814F9EC(gDisplayedStringBattle, 10);
}

void MoveSelectionCreateCursorAt(u8 cursorPosition, u8 arg1)
{
    u16 src[2];
    src[0] = arg1 + 1;
    src[1] = arg1 + 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void MoveSelectionDestroyCursorAt(u8 cursorPosition)
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

void sub_8059D60(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x10)
        PlayerBufferExecCompleted();
}

void sub_8059D90(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBank].flag_x20)
        PlayerBufferExecCompleted();
}

extern const u8 gText_LinkStandby[];

void PrintLinkStandbyMsg(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        sub_814F9EC(gText_LinkStandby, 0);
    }
}
