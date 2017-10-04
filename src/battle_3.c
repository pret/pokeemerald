#include "global.h"
#include "battle.h"
#include "abilities.h"
#include "moves.h"
#include "hold_effects.h"
#include "pokemon.h"
#include "species.h"
#include "item.h"
#include "items.h"
#include "util.h"
#include "battle_move_effects.h"
#include "rng.h"
#include "text.h"
#include "string_util.h"
#include "battle_message.h"
#include "battle_ai_script_commands.h"
#include "battle_controllers.h"
#include "event_data.h"
#include "calculate_base_damage.h"

extern const u8* gBattlescriptCurrInstr;
extern const u8* gBattlescriptPtrsForSelection[BATTLE_BANKS_COUNT];
extern const u8* gUnknown_02024230[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u8 gActiveBank;
extern u8 gStringBank;
extern u16 gCurrentMove;
extern u16 gLastUsedItem;
extern u8 gNoOfAllBanks;
extern u32 gStatuses3[BATTLE_BANKS_COUNT];
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u16 gBattleWeather;
extern u8 gBanksByTurnOrder[BATTLE_BANKS_COUNT];
extern u16 gSideAffecting[];
extern u8 gBattleCommunication[];
extern void (*gBattleMainFunc)(void);
extern s32 gBattleMoveDamage;
extern struct BattleEnigmaBerry gEnigmaBerries[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u32 gBattleTypeFlags;
extern u16 gLastUsedMovesByBanks[BATTLE_BANKS_COUNT];
extern u32 gHitMarker;
extern u8 gEffectBank;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBank1;
extern u16 gChosenMovesByBanks[];
extern u8 gBattleMoveFlags;
extern s32 gTakenDmg[BATTLE_BANKS_COUNT];
extern u8 gTakenDmgBanks[BATTLE_BANKS_COUNT];
extern u8 gLastUsedAbility;
extern u8 gFightStateTracker;
extern u32 gBattleExecBuffer;
extern u16 gRandomMove;
extern u8 gCurrMovePos;
extern u8 gUnknown_020241E9;

extern const struct BattleMove gBattleMoves[];

// scripts
extern const u8 gUnknown_082DAE2A[];
extern const u8 gUnknown_082DAE1F[];
extern const u8 gUnknown_082DB089[];
extern const u8 gUnknown_082DB098[];
extern const u8 gUnknown_082DB0AF[];
extern const u8 gUnknown_082DB0A0[];
extern const u8 gUnknown_082DB185[];
extern const u8 gUnknown_082DB181[];
extern const u8 gUnknown_082DB812[];
extern const u8 gUnknown_082DB076[];
extern const u8 BattleScript_NoMovesLeft[];
extern const u8 gUnknown_082DACFA[];
extern const u8 gUnknown_082DAD0B[];
extern const u8 gUnknown_082DACC9[];
extern const u8 gUnknown_082DAC47[];
extern const u8 gUnknown_082DACE0[];
extern const u8 gUnknown_082DACD2[];
extern const u8 BattleScript_WishComesTrue[];
extern const u8 gUnknown_082DACC9[];
extern const u8 gUnknown_082DAC2C[];
extern const u8 BattleScript_IngrainTurnHeal[];
extern const u8 BattleScript_LeechSeedTurnDrain[];
extern const u8 BattleScript_PoisonTurnDmg[];
extern const u8 BattleScript_BurnTurnDmg[];
extern const u8 BattleScript_NightmareTurnDmg[];
extern const u8 BattleScript_CurseTurnDmg[];
extern const u8 BattleScript_WrapTurnDmg[];
extern const u8 BattleScript_WrapEnds[];
extern const u8 gUnknown_082DB234[];
extern const u8 gUnknown_082DB2A6[];
extern const u8 BattleScript_ThrashConfuses[];
extern const u8 BattleScript_DisabledNoMore[];
extern const u8 BattleScript_EncoredNoMore[];
extern const u8 BattleScript_YawnMakesAsleep[];
extern const u8 gUnknown_082DAFE4[];
extern const u8 gUnknown_082DB8F3[];
extern const u8 gUnknown_082DAF05[];
extern const u8 gUnknown_082DAF20[];
extern const u8 gUnknown_082DA7C4[];
extern const u8 gUnknown_082DA7CD[];
extern const u8 BattleScript_MoveUsedWokeUp[];
extern const u8 BattleScript_MoveUsedIsAsleep[];
extern const u8 BattleScript_MoveUsedIsFrozen[];
extern const u8 BattleScript_MoveUsedUnfroze[];
extern const u8 BattleScript_MoveUsedLoafingAround[];
extern const u8 BattleScript_MoveUsedMustRecharge[];
extern const u8 BattleScript_MoveUsedFlinched[];
extern const u8 BattleScript_MoveUsedIsDisabled[];
extern const u8 BattleScript_MoveUsedIsTaunted[];
extern const u8 BattleScript_MoveUsedIsImprisoned[];
extern const u8 BattleScript_MoveUsedIsConfused[];
extern const u8 BattleScript_MoveUsedIsConfusedNoMore[];
extern const u8 BattleScript_MoveUsedIsParalyzed[];
extern const u8 BattleScript_MoveUsedIsParalyzedCantAttack[];
extern const u8 BattleScript_MoveUsedIsInLove[];
extern const u8 BattleScript_BideStoringEnergy[];
extern const u8 BattleScript_BideAttack[];
extern const u8 BattleScript_BideNoEnergyToAttack[];
extern const u8 gUnknown_082DACE7[];
extern const u8 BattleScript_DrizzleActivates[];
extern const u8 BattleScript_SandstreamActivates[];
extern const u8 BattleScript_DroughtActivates[];
extern const u8 BattleScript_CastformChange[];
extern const u8 BattleScript_RainDishActivates[];
extern const u8 BattleScript_ShedSkinActivates[];
extern const u8 BattleScript_SpeedBoostActivates[];
extern const u8 BattleScript_SoundproofProtected[];
extern const u8 BattleScript_MoveHPDrain[];
extern const u8 BattleScript_MoveHPDrain_PPLoss[];
extern const u8 BattleScript_FlashFireBoost[];
extern const u8 BattleScript_FlashFireBoost_PPLoss[];
extern const u8 BattleScript_ColorChangeActivates[];
extern const u8 BattleScript_RoughSkinActivates[];
extern const u8 BattleScript_ApplySecondaryEffect[];
extern const u8 BattleScript_CuteCharmActivates[];
extern const u8 gUnknown_082DB68C[];
extern const u8 BattleScript_SynchronizeActivates[];
extern const u8 gUnknown_082DB4B8[];
extern const u8 gUnknown_082DB4C1[];
extern const u8 BattleScript_TraceActivates[];

extern const u8 BattleScript_WhiteHerbEnd2[];
extern const u8 BattleScript_WhiteHerbRet[];
extern const u8 BattleScript_ItemHealHP_RemoveItem[];
extern const u8 BattleScript_BerryPPHealEnd2[];
extern const u8 BattleScript_ItemHealHP_End2[];
extern const u8 BattleScript_BerryConfuseHealEnd2[];
extern const u8 BattleScript_BerryStatRaiseEnd2[];
extern const u8 BattleScript_BerryFocusEnergyEnd2[];
extern const u8 BattleScript_BerryCurePrlzEnd2[];
extern const u8 BattleScript_BerryCurePsnEnd2[];
extern const u8 BattleScript_BerryCureBrnEnd2[];
extern const u8 BattleScript_BerryCureFrzEnd2[];
extern const u8 BattleScript_BerryCureSlpEnd2[];
extern const u8 BattleScript_BerryCureConfusionEnd2[];
extern const u8 BattleScript_BerryCureChosenStatusEnd2[];
extern const u8 BattleScript_BerryCureParRet[];
extern const u8 BattleScript_BerryCurePsnRet[];
extern const u8 BattleScript_BerryCureBrnRet[];
extern const u8 BattleScript_BerryCureFrzRet[];
extern const u8 BattleScript_BerryCureSlpRet[];
extern const u8 BattleScript_BerryCureConfusionRet[];
extern const u8 BattleScript_BerryCureChosenStatusRet[];
extern const u8 BattleScript_ItemHealHP_Ret[];

extern const u8 gUnknown_082DB695[]; //disobedient while asleep
extern const u8 gUnknown_082DB6A5[]; //disobedient, uses a random move
extern const u8 gUnknown_082DB6D9[]; //disobedient, went to sleep
extern const u8 gUnknown_082DB6F0[]; //disobedient, hits itself

extern const u8 gStatusConditionString_PoisonJpn[];
extern const u8 gStatusConditionString_SleepJpn[];
extern const u8 gStatusConditionString_ParalysisJpn[];
extern const u8 gStatusConditionString_BurnJpn[];
extern const u8 gStatusConditionString_IceJpn[];
extern const u8 gStatusConditionString_ConfusionJpn[];
extern const u8 gStatusConditionString_LoveJpn[];
extern const u16 gSoundMovesTable[];

extern void sub_803F9EC();
extern bool8 sub_80423F4(u8 bank, u8, u8);
extern u8 weather_get_current(void);
extern void sub_803E08C(void);
extern void bc_move_exec_returning(void);
extern s8 GetFlavourRelationByPersonality(u32 personality, u8 flavor);

void BattleScriptPush(const u8* bsPtr)
{
    BATTLESCRIPTS_STACK->ptr[BATTLESCRIPTS_STACK->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    BATTLESCRIPTS_STACK->ptr[BATTLESCRIPTS_STACK->size++] = gBattlescriptCurrInstr;
}

void BattleScriptPop(void)
{
    gBattlescriptCurrInstr = BATTLESCRIPTS_STACK->ptr[--BATTLESCRIPTS_STACK->size];
}

u8 TrySetCantSelectMoveBattleScript(void)
{
    u8 limitations = 0;
    u16 move = gBattleMons[gActiveBank].moves[gBattleBufferB[gActiveBank][2]];
    u8 holdEffect;
    u16* choicedMove = &gBattleStruct->choicedMove[gActiveBank];

    if (gDisableStructs[gActiveBank].disabledMove == move && move != 0)
    {
        gBattleScripting.bank = gActiveBank;
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DAE2A;
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DAE1F;
            limitations = 1;
        }
    }

    if (move == gLastUsedMovesByBanks[gActiveBank] && move != MOVE_STRUGGLE && (gBattleMons[gActiveBank].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(gActiveBank);
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB098;
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB089;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBank].tauntTimer1 != 0 && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB0AF;
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB0A0;
            limitations++;
        }
    }

    if (GetImprisonedMovesCount(gActiveBank, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB185;
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB181;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBank].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gActiveBank].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gActiveBank].item);

    gStringBank = gActiveBank;

    if (holdEffect == HOLD_EFFECT_CHOICE_BAND && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[gActiveBank].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB812;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBank].pp[gBattleBufferB[gActiveBank][2]] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBank].flag_x10 = 1;
        }
        else
        {
            gBattlescriptPtrsForSelection[gActiveBank] = gUnknown_082DB076;
            limitations++;
        }
    }

    return limitations;
}

u8 CheckMoveLimitations(u8 bank, u8 unusableMoves, u8 check)
{
    u8 holdEffect;
    u16* choicedMove = &gBattleStruct->choicedMove[bank];
    s32 i;

    if (gBattleMons[bank].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[bank].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[bank].item);

    gStringBank = bank;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        if (gBattleMons[bank].moves[i] == 0 && check & MOVE_LIMITATION_ZEROMOVE)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].pp[i] == 0 && check & MOVE_LIMITATION_PP)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].moves[i] == gDisableStructs[bank].disabledMove && check & MOVE_LIMITATION_DISABLED)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].moves[i] == gLastUsedMovesByBanks[bank] && check & MOVE_LIMITATION_TORMENTED && gBattleMons[bank].status2 & STATUS2_TORMENT)
            unusableMoves |= gBitTable[i];
        if (gDisableStructs[bank].tauntTimer1 && check & MOVE_LIMITATION_TAUNT && gBattleMoves[gBattleMons[bank].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        if (GetImprisonedMovesCount(bank, gBattleMons[bank].moves[i]) && check & MOVE_LIMITATION_IMPRISION)
            unusableMoves |= gBitTable[i];
        if (gDisableStructs[bank].encoreTimer1 && gDisableStructs[bank].encoredMove != gBattleMons[bank].moves[i])
            unusableMoves |= gBitTable[i];
        if (holdEffect == HOLD_EFFECT_CHOICE_BAND && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != gBattleMons[bank].moves[i])
            unusableMoves |= gBitTable[i];
    }
    return unusableMoves;
}

bool8 AreAllMovesUnusable(void)
{
    u8 unusable;
    unusable = CheckMoveLimitations(gActiveBank, 0, 0xFF);

    if (unusable == 0xF) // all moves are unusable
    {
        gProtectStructs[gActiveBank].onlyStruggle = 1;
        gBattlescriptPtrsForSelection[gActiveBank] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[gActiveBank].onlyStruggle = 0;
    }

    return (unusable == 0xF);
}

u8 GetImprisonedMovesCount(u8 bank, u16 move)
{
    s32 i;
    u8 imprisionedMoves = 0;
    u8 bankSide = GetBankSide(bank);

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (bankSide != GetBankSide(i) && gStatuses3[i] & STATUS3_IMPRISONED_OTHERS)
        {
            s32 j;
            for (j = 0; j < 4; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < 4)
                imprisionedMoves++;
        }
    }

    return imprisionedMoves;
}

u8 UpdateTurnCounters(void)
{
    u8 effect = 0;
    s32 i;

    for (gBankAttacker = 0; gBankAttacker < gNoOfAllBanks && gAbsentBankFlags & gBitTable[gBankAttacker]; gBankAttacker++)
    {
    }
    for (gBankTarget = 0; gBankTarget < gNoOfAllBanks && gAbsentBankFlags & gBitTable[gBankTarget]; gBankTarget++)
    {
    }

    do
    {
        u8 sideBank;

        switch (gBattleStruct->turncountersTracker)
        {
        case 0:
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                gBanksByTurnOrder[i] = i;
            }
            for (i = 0; i < gNoOfAllBanks - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gNoOfAllBanks; j++)
                {
                    if (GetWhoStrikesFirst(gBanksByTurnOrder[i], gBanksByTurnOrder[j], 0))
                        SwapTurnOrder(i, j);
                }
            }

            // It's stupid, but won't match without it
            {
                u8* var = &gBattleStruct->turncountersTracker;
                (*var)++;
                gBattleStruct->turnSideTracker = 0;
            }
            // fall through
        case 1:
            while (gBattleStruct->turnSideTracker < 2)
            {
                sideBank = gBattleStruct->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimers[sideBank].reflectBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimers[sideBank].reflectTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_REFLECT;
                        BattleScriptExecute(gUnknown_082DACFA);
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = MOVE_REFLECT;
                        gBattleTextBuff1[3] = MOVE_REFLECT >> 8;
                        gBattleTextBuff1[4] = EOS;
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turncountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case 2:
            while (gBattleStruct->turnSideTracker < 2)
            {
                sideBank = gBattleStruct->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimers[sideBank].lightscreenBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimers[sideBank].lightscreenTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_LIGHTSCREEN;
                        BattleScriptExecute(gUnknown_082DACFA);
                        gBattleCommunication[MULTISTRING_CHOOSER] = sideBank;
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = MOVE_LIGHT_SCREEN;
                        gBattleTextBuff1[3] = MOVE_LIGHT_SCREEN >> 8;
                        gBattleTextBuff1[4] = EOS;
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turncountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case 3:
            while (gBattleStruct->turnSideTracker < 2)
            {
                sideBank = gBattleStruct->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimers[sideBank].mistBank;
                if (gSideTimers[sideBank].mistTimer != 0
                 && --gSideTimers[sideBank].mistTimer == 0)
                {
                    gSideAffecting[sideBank] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(gUnknown_082DACFA);
                    gBattleCommunication[MULTISTRING_CHOOSER] = sideBank;
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 2;
                    gBattleTextBuff1[2] = MOVE_MIST;
                    gBattleTextBuff1[3] = MOVE_MIST >> 8;
                    gBattleTextBuff1[4] = EOS;
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turncountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case 4:
            while (gBattleStruct->turnSideTracker < 2)
            {
                sideBank = gBattleStruct->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimers[sideBank].safeguardBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimers[sideBank].safeguardTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_SAFEGUARD;
                        BattleScriptExecute(gUnknown_082DAD0B);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turncountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case 5:
            while (gBattleStruct->turnSideTracker < gNoOfAllBanks)
            {
                gActiveBank = gBanksByTurnOrder[gBattleStruct->turnSideTracker];
                if (gWishFutureKnock.wishCounter[gActiveBank] != 0
                 && --gWishFutureKnock.wishCounter[gActiveBank] == 0
                 && gBattleMons[gActiveBank].hp != 0)
                {
                    gBankTarget = gActiveBank;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gBattleStruct->turncountersTracker++;
            }
            break;
        case 6:
            if (gBattleWeather & WEATHER_RAIN_ANY)
            {
                if (!(gBattleWeather & WEATHER_RAIN_PERMANENT))
                {
                    if (--gWishFutureKnock.weatherDuration == 0)
                    {
                        gBattleWeather &= ~WEATHER_RAIN_TEMPORARY;
                        gBattleWeather &= ~WEATHER_RAIN_DOWNPOUR;
                        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                    }
                    else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                else if (gBattleWeather & WEATHER_RAIN_DOWNPOUR)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                BattleScriptExecute(gUnknown_082DAC2C);
                effect++;
            }
            gBattleStruct->turncountersTracker++;
            break;
        case 7:
            if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            {
                if (!(gBattleWeather & WEATHER_SANDSTORM_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SANDSTORM_TEMPORARY;
                    gBattlescriptCurrInstr = gUnknown_082DACC9;
                }
                else
                    gBattlescriptCurrInstr = gUnknown_082DAC47;

                gBattleScripting.animArg1 = 0xC;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turncountersTracker++;
            break;
        case 8:
            if (gBattleWeather & WEATHER_SUN_ANY)
            {
                if (!(gBattleWeather & WEATHER_SUN_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_SUN_TEMPORARY;
                    gBattlescriptCurrInstr = gUnknown_082DACE0;
                }
                else
                    gBattlescriptCurrInstr = gUnknown_082DACD2;

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turncountersTracker++;
            break;
        case 9:
            if (gBattleWeather & WEATHER_HAIL)
            {
                if (--gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~WEATHER_HAIL;
                    gBattlescriptCurrInstr = gUnknown_082DACC9;
                }
                else
                    gBattlescriptCurrInstr = gUnknown_082DAC47;

                gBattleScripting.animArg1 = 0xD;
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turncountersTracker++;
            break;
        case 10:
            effect++;
            break;
        }
    } while (effect == 0);
    return (gBattleMainFunc != BattleTurnPassed);
}

#define TURNBASED_MAX_CASE 19

u8 TurnBasedEffects(void)
{
    u8 effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);
    while (gBattleStruct->turnEffectsBank < gNoOfAllBanks && gBattleStruct->turnEffectsTracker <= TURNBASED_MAX_CASE)
    {
        gActiveBank = gBankAttacker = gBanksByTurnOrder[gBattleStruct->turnEffectsBank];
        if (gAbsentBankFlags & gBitTable[gActiveBank])
        {
            gBattleStruct->turnEffectsBank++;
        }
        else
        {
            switch (gBattleStruct->turnEffectsTracker)
            {
            case 0:  // ingrain
                if ((gStatuses3[gActiveBank] & STATUS3_ROOTED)
                 && gBattleMons[gActiveBank].hp != gBattleMons[gActiveBank].maxHP
                 && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_IngrainTurnHeal);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 1:  // end turn abilities
                if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, gActiveBank, 0, 0, 0))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 2:  // item effects
                if (ItemBattleEffects(1, gActiveBank, 0))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 18:  // item effects again
                if (ItemBattleEffects(1, gActiveBank, 1))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 3:  // leech seed
                if ((gStatuses3[gActiveBank] & STATUS3_LEECHSEED)
                 && gBattleMons[gStatuses3[gActiveBank] & STATUS3_LEECHSEED_BANK].hp != 0
                 && gBattleMons[gActiveBank].hp != 0)
                {
                    gBankTarget = gStatuses3[gActiveBank] & STATUS3_LEECHSEED_BANK; //funny how the 'target' is actually the bank that receives HP
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleScripting.animArg1 = gBankTarget;
                    gBattleScripting.animArg2 = gBankAttacker;
                    BattleScriptExecute(BattleScript_LeechSeedTurnDrain);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 4:  // poison
                if ((gBattleMons[gActiveBank].status1 & STATUS_POISON) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 5:  // toxic poison
                if ((gBattleMons[gActiveBank].status1 & STATUS_TOXIC_POISON) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if ((gBattleMons[gActiveBank].status1 & 0xF00) != 0xF00) //not 16 turns
                        gBattleMons[gActiveBank].status1 += 0x100;
                    gBattleMoveDamage *= (gBattleMons[gActiveBank].status1 & 0xF00) >> 8;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 6:  // burn
                if ((gBattleMons[gActiveBank].status1 & STATUS_BURN) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_BurnTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 7:  // spooky nightmares
                if ((gBattleMons[gActiveBank].status2 & STATUS2_NIGHTMARE) && gBattleMons[gActiveBank].hp != 0)
                {
                    // R/S does not perform this sleep check, which causes the nighmare effect to
                    // persist even after the affected Pokemon has been awakened by Shed Skin
                    if (gBattleMons[gActiveBank].status1 & STATUS_SLEEP)
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        BattleScriptExecute(BattleScript_NightmareTurnDmg);
                        effect++;
                    }
                    else
                    {
                        gBattleMons[gActiveBank].status2 &= ~STATUS2_NIGHTMARE;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 8:  // curse
                if ((gBattleMons[gActiveBank].status2 & STATUS2_CURSED) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_CurseTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 9:  // wrap
                if ((gBattleMons[gActiveBank].status2 & STATUS2_WRAPPED) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMons[gActiveBank].status2 -= 0x2000;
                    if (gBattleMons[gActiveBank].status2 & STATUS2_WRAPPED)  // damaged by wrap
                    {
                        // This is the only way I could get this array access to match.
                        gBattleScripting.animArg1 = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 0);
                        gBattleScripting.animArg2 = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 1);
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 0);
                        gBattleTextBuff1[3] = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 1);
                        gBattleTextBuff1[4] = EOS;
                        gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;
                        gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 16;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    else  // broke free
                    {
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 0);
                        gBattleTextBuff1[3] = *(gBattleStruct->wrappedMove + gActiveBank * 2 + 1);
                        gBattleTextBuff1[4] = EOS;
                        gBattlescriptCurrInstr = BattleScript_WrapEnds;
                    }
                    BattleScriptExecute(gBattlescriptCurrInstr);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 10:  // uproar
                if (gBattleMons[gActiveBank].status2 & STATUS2_UPROAR)
                {
                    for (gBankAttacker = 0; gBankAttacker < gNoOfAllBanks; gBankAttacker++)
                    {
                        if ((gBattleMons[gBankAttacker].status1 & STATUS_SLEEP)
                         && gBattleMons[gBankAttacker].ability != ABILITY_SOUNDPROOF)
                        {
                            gBattleMons[gBankAttacker].status1 &= ~(STATUS_SLEEP);
                            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                            BattleScriptExecute(gUnknown_082DB234);
                            gActiveBank = gBankAttacker;
                            EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                            MarkBufferBankForExecution(gActiveBank);
                            break;
                        }
                    }
                    if (gBankAttacker != gNoOfAllBanks)
                    {
                        effect = 2;  // a pokemon was awaken
                        break;
                    }
                    else
                    {
                        gBankAttacker = gActiveBank;
                        gBattleMons[gActiveBank].status2 -= 0x10;  // uproar timer goes down
                        if (HasMoveFailed(gActiveBank))
                        {
                            CancelMultiTurnMoves(gActiveBank);
                            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        }
                        else if (gBattleMons[gActiveBank].status2 & STATUS2_UPROAR)
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                            gBattleMons[gActiveBank].status2 |= STATUS2_MULTIPLETURNS;
                        }
                        else
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                            CancelMultiTurnMoves(gActiveBank);
                        }
                        BattleScriptExecute(gUnknown_082DB2A6);
                        effect = 1;
                    }
                }
                if (effect != 2)
                    gBattleStruct->turnEffectsTracker++;
                break;
            case 11:  // thrash
                if (gBattleMons[gActiveBank].status2 & STATUS2_LOCK_CONFUSE)
                {
                    gBattleMons[gActiveBank].status2 -= 0x400;
                    if (HasMoveFailed(gActiveBank))
                        CancelMultiTurnMoves(gActiveBank);
                    else if (!(gBattleMons[gActiveBank].status2 & STATUS2_LOCK_CONFUSE)
                     && (gBattleMons[gActiveBank].status2 & STATUS2_MULTIPLETURNS))
                    {
                        gBattleMons[gActiveBank].status2 &= ~(STATUS2_MULTIPLETURNS);
                        if (!(gBattleMons[gActiveBank].status2 & STATUS2_CONFUSION))
                        {
                            gBattleCommunication[MOVE_EFFECT_BYTE] = 0x47;
                            SetMoveEffect(1, 0);
                            if (gBattleMons[gActiveBank].status2 & STATUS2_CONFUSION)
                                BattleScriptExecute(BattleScript_ThrashConfuses);
                            effect++;
                        }
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 12:  // disable
                if (gDisableStructs[gActiveBank].disableTimer1 != 0)
                {
                    int i;
                    for (i = 0; i < 4; i++)
                    {
                        if (gDisableStructs[gActiveBank].disabledMove == gBattleMons[gActiveBank].moves[i])
                            break;
                    }
                    if (i == 4)  // pokemon does not have the disabled move anymore
                    {
                        gDisableStructs[gActiveBank].disabledMove = 0;
                        gDisableStructs[gActiveBank].disableTimer1 = 0;
                    }
                    else if (--gDisableStructs[gActiveBank].disableTimer1 == 0)  // disable ends
                    {
                        gDisableStructs[gActiveBank].disabledMove = 0;
                        BattleScriptExecute(BattleScript_DisabledNoMore);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 13:  // encore
                if (gDisableStructs[gActiveBank].encoreTimer1 != 0)
                {
                    if (gBattleMons[gActiveBank].moves[gDisableStructs[gActiveBank].encoredMovePos] != gDisableStructs[gActiveBank].encoredMove)  // pokemon does not have the encored move anymore
                    {
                        gDisableStructs[gActiveBank].encoredMove = 0;
                        gDisableStructs[gActiveBank].encoreTimer1 = 0;
                    }
                    else if (--gDisableStructs[gActiveBank].encoreTimer1 == 0
                     || gBattleMons[gActiveBank].pp[gDisableStructs[gActiveBank].encoredMovePos] == 0)
                    {
                        gDisableStructs[gActiveBank].encoredMove = 0;
                        gDisableStructs[gActiveBank].encoreTimer1 = 0;
                        BattleScriptExecute(BattleScript_EncoredNoMore);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 14:  // lock-on decrement
                if (gStatuses3[gActiveBank] & STATUS3_ALWAYS_HITS)
                    gStatuses3[gActiveBank] -= 0x8;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 15:  // charge
                if (gDisableStructs[gActiveBank].chargeTimer1 && --gDisableStructs[gActiveBank].chargeTimer1 == 0)
                    gStatuses3[gActiveBank] &= ~STATUS3_CHARGED_UP;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 16:  // taunt
                if (gDisableStructs[gActiveBank].tauntTimer1)
                    gDisableStructs[gActiveBank].tauntTimer1--;
                gBattleStruct->turnEffectsTracker++;
                break;
            case 17:  // yawn
                if (gStatuses3[gActiveBank] & STATUS3_YAWN)
                {
                    gStatuses3[gActiveBank] -= 0x800;
                    if (!(gStatuses3[gActiveBank] & STATUS3_YAWN) && !(gBattleMons[gActiveBank].status1 & STATUS_ANY)
                     && gBattleMons[gActiveBank].ability != ABILITY_VITAL_SPIRIT
                     && gBattleMons[gActiveBank].ability != ABILITY_INSOMNIA && !UproarWakeUpCheck(gActiveBank))
                    {
                        CancelMultiTurnMoves(gActiveBank);
                        gBattleMons[gActiveBank].status1 |= (Random() & 3) + 2;
                        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                        MarkBufferBankForExecution(gActiveBank);
                        gEffectBank = gActiveBank;
                        BattleScriptExecute(BattleScript_YawnMakesAsleep);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case 19:  // done
                gBattleStruct->turnEffectsTracker = 0;
                gBattleStruct->turnEffectsBank++;
                break;
            }
            if (effect != 0)
                return effect;
        }
    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);
    return 0;
}

bool8 sub_8041364(void)
{
    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);

    switch (gBattleStruct->field_1A0)
    {
    case 0:
        while (gBattleStruct->field_1A1 < gNoOfAllBanks)
        {
            gActiveBank = gBattleStruct->field_1A1;
            if (gAbsentBankFlags & gBitTable[gActiveBank])
            {
                gBattleStruct->field_1A1++;
                continue;
            }

            gBattleStruct->field_1A1++;
            if (gWishFutureKnock.futureSightCounter[gActiveBank] != 0
             && --gWishFutureKnock.futureSightCounter[gActiveBank] == 0
             && gBattleMons[gActiveBank].hp != 0)
            {
                if (gWishFutureKnock.futureSightMove[gActiveBank] == MOVE_FUTURE_SIGHT)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;

                gBattleTextBuff1[0] = 0xFD;
                gBattleTextBuff1[1] = 2;
                gBattleTextBuff1[2] = gWishFutureKnock.futureSightMove[gActiveBank];
                gBattleTextBuff1[3] = gWishFutureKnock.futureSightMove[gActiveBank] >> 8;
                gBattleTextBuff1[4] = EOS;
                gBankTarget = gActiveBank;
                gBankAttacker = gWishFutureKnock.futureSightAttacker[gActiveBank];
                gBattleMoveDamage = gWishFutureKnock.futureSightDmg[gActiveBank];
                gSpecialStatuses[gBankTarget].moveturnLostHP = 0xFFFF;
                BattleScriptExecute(gUnknown_082DAFE4);

                if (gWishFutureKnock.futureSightCounter[gActiveBank] == 0
                 && gWishFutureKnock.futureSightCounter[gActiveBank ^ 2] == 0)
                {
                    gSideAffecting[GetBankIdentity(gBankTarget) & 1] &= ~SIDE_STATUS_FUTUREATTACK;
                }
                return 1;
            }
        }
        // Why do I have to keep doing this to match?
        {
            u8* var = &gBattleStruct->field_1A0;
            *var = 1;
            gBattleStruct->field_1A1 = 0;
        }
        // fall through
    case 1:
        while (gBattleStruct->field_1A1 < gNoOfAllBanks)
        {
            gActiveBank = gBankAttacker = gBanksByTurnOrder[gBattleStruct->field_1A1];
            if (gAbsentBankFlags & gBitTable[gActiveBank])
            {
                gBattleStruct->field_1A1++;
                continue;
            }
            gBattleStruct->field_1A1++;
            if (gStatuses3[gActiveBank] & STATUS3_PERISH_SONG)
            {
                gBattleTextBuff1[0] = 0xFD;
                gBattleTextBuff1[1] = 1;
                gBattleTextBuff1[2] = 1;
                gBattleTextBuff1[3] = 1;
                gBattleTextBuff1[4] = gDisableStructs[gActiveBank].perishSong1;
                gBattleTextBuff1[5] = EOS;
                if (gDisableStructs[gActiveBank].perishSong1 == 0)
                {
                    gStatuses3[gActiveBank] &= ~STATUS3_PERISH_SONG;
                    gBattleMoveDamage = gBattleMons[gActiveBank].hp;
                    gBattlescriptCurrInstr = gUnknown_082DAF05;
                }
                else
                {
                    gDisableStructs[gActiveBank].perishSong1--;
                    gBattlescriptCurrInstr = gUnknown_082DAF20;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                return 1;
            }
        }
        // Hm...
        {
            u8* var = &gBattleStruct->field_1A0;
            *var = 2;
            gBattleStruct->field_1A1 = 0;
        }
        // fall through
    case 2:
        if ((gBattleTypeFlags & BATTLE_TYPE_ARENA)
         && gBattleStruct->field_DA == 2
         && gBattleMons[0].hp != 0 && gBattleMons[1].hp != 0)
        {
            s32 i;

            for (i = 0; i < 2; i++)
                CancelMultiTurnMoves(i);

            gBattlescriptCurrInstr = gUnknown_082DB8F3;
            BattleScriptExecute(gUnknown_082DB8F3);
            gBattleStruct->field_1A0++;
            return 1;
        }
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);

    return 0;
}

#define sub_8041728_MAX_CASE 7

bool8 sub_8041728(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;
    do
    {
        int i;
        switch (gBattleStruct->field_4D)
        {
        case 0:
            gBattleStruct->field_4E = 0;
            gBattleStruct->field_4D++;
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gAbsentBankFlags & gBitTable[i] && !sub_80423F4(i, 6, 6))
                    gAbsentBankFlags &= ~(gBitTable[i]);
            }
            // fall through
        case 1:
            do
            {
                gBank1 = gBankTarget = gBattleStruct->field_4E;
                if (gBattleMons[gBattleStruct->field_4E].hp == 0
                 && !(gBattleStruct->field_DF & gBitTable[gBattlePartyID[gBattleStruct->field_4E]])
                 && !(gAbsentBankFlags & gBitTable[gBattleStruct->field_4E]))
                {
                    BattleScriptExecute(gUnknown_082DA7C4);
                    gBattleStruct->field_4D = 2;
                    return TRUE;
                }
            } while (++gBattleStruct->field_4E != gNoOfAllBanks);
            gBattleStruct->field_4D = 3;
            break;
        case 2:
            sub_803F9EC(gBank1);
            if (++gBattleStruct->field_4E == gNoOfAllBanks)
                gBattleStruct->field_4D = 3;
            else
                gBattleStruct->field_4D = 1;
            break;
        case 3:
            gBattleStruct->field_4E = 0;
            gBattleStruct->field_4D++;
            // fall through
        case 4:
            do
            {
                gBank1 = gBankTarget = gBattleStruct->field_4E; //or should banks be switched?
                if (gBattleMons[gBattleStruct->field_4E].hp == 0
                 && !(gAbsentBankFlags & gBitTable[gBattleStruct->field_4E]))
                {
                    BattleScriptExecute(gUnknown_082DA7CD);
                    gBattleStruct->field_4D = 5;
                    return TRUE;
                }
            } while (++gBattleStruct->field_4E != gNoOfAllBanks);
            gBattleStruct->field_4D = 6;
            break;
        case 5:
            if (++gBattleStruct->field_4E == gNoOfAllBanks)
                gBattleStruct->field_4D = 6;
            else
                gBattleStruct->field_4D = 4;
            break;
        case 6:
            if (AbilityBattleEffects(ABILITYEFFECT_INTIMIDATE1, 0, 0, 0, 0) || AbilityBattleEffects(ABILITYEFFECT_TRACE, 0, 0, 0, 0) || ItemBattleEffects(1, 0, 1) || AbilityBattleEffects(ABILITYEFFECT_FORECAST, 0, 0, 0, 0))
                return TRUE;
            gBattleStruct->field_4D++;
            break;
        case 7:
            break;
        }
    } while (gBattleStruct->field_4D != sub_8041728_MAX_CASE);
    return FALSE;
}

void b_clear_atk_up_if_hit_flag_unless_enraged(void)
{
    int i;
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gChosenMovesByBanks[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~(STATUS2_RAGE);
    }
}

#define ATKCANCELLER_MAX_CASE 14

u8 AtkCanceller_UnableToUseMove(void)
{
    u8 effect = 0;
    s32* bideDmg = &gBattleScripting.bideDmg;
    do
    {
        switch (gBattleStruct->atkCancellerTracker)
        {
        case 0: // flags clear
            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_DESTINY_BOND);
            gStatuses3[gBankAttacker] &= ~(STATUS3_GRUDGE);
            gBattleStruct->atkCancellerTracker++;
            break;
        case 1: // check being asleep
            if (gBattleMons[gBankAttacker].status1 & STATUS_SLEEP)
            {
                if (UproarWakeUpCheck(gBankAttacker))
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_SLEEP);
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u8 toSub;
                    if (gBattleMons[gBankAttacker].ability == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;
                    if ((gBattleMons[gBankAttacker].status1 & STATUS_SLEEP) < toSub)
                        gBattleMons[gBankAttacker].status1 &= ~(STATUS_SLEEP);
                    else
                        gBattleMons[gBankAttacker].status1 -= toSub;
                    if (gBattleMons[gBankAttacker].status1 & STATUS_SLEEP)
                    {
                        if (gCurrentMove != MOVE_SNORE && gCurrentMove != MOVE_SLEEP_TALK)
                        {
                            gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                            effect = 2;
                        }
                    }
                    else
                    {
                        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                        BattleScriptPushCursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 2: // check being frozen
            if (gBattleMons[gBankAttacker].status1 & STATUS_FREEZE)
            {
                if (Random() % 5)
                {
                    if (gBattleMoves[gCurrentMove].effect != EFFECT_THAW_HIT) // unfreezing via a move effect happens in case 13
                    {
                        gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                        gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                    }
                    else
                    {
                        gBattleStruct->atkCancellerTracker++;
                        break;
                    }
                }
                else // unfreeze
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 3: // truant
            if (gBattleMons[gBankAttacker].ability == ABILITY_TRUANT && gDisableStructs[gBankAttacker].truantCounter)
            {
                CancelMultiTurnMoves(gBankAttacker);
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
                gBattleMoveFlags |= MOVESTATUS_MISSED;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 4: // recharge
            if (gBattleMons[gBankAttacker].status2 & STATUS2_RECHARGE)
            {
                gBattleMons[gBankAttacker].status2 &= ~(STATUS2_RECHARGE);
                gDisableStructs[gBankAttacker].rechargeCounter = 0;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 5: // flinch
            if (gBattleMons[gBankAttacker].status2 & STATUS2_FLINCHED)
            {
                gBattleMons[gBankAttacker].status2 &= ~(STATUS2_FLINCHED);
                gProtectStructs[gBankAttacker].flinchImmobility = 1;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 6: // disabled move
            if (gDisableStructs[gBankAttacker].disabledMove == gCurrentMove && gDisableStructs[gBankAttacker].disabledMove != 0)
            {
                gProtectStructs[gBankAttacker].usedDisabledMove = 1;
                gBattleScripting.bank = gBankAttacker;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 7: // taunt
            if (gDisableStructs[gBankAttacker].tauntTimer1 && gBattleMoves[gCurrentMove].power == 0)
            {
                gProtectStructs[gBankAttacker].usedTauntedMove = 1;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 8: // imprisoned
            if (GetImprisonedMovesCount(gBankAttacker, gCurrentMove))
            {
                gProtectStructs[gBankAttacker].usedImprisionedMove = 1;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 9: // confusion
            if (gBattleMons[gBankAttacker].status2 & STATUS2_CONFUSION)
            {
                gBattleMons[gBankAttacker].status2--;
                if (gBattleMons[gBankAttacker].status2 & STATUS2_CONFUSION)
                {
                    if (Random() & 1)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                        BattleScriptPushCursor();
                    }
                    else // confusion dmg
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        gBankTarget = gBankAttacker;
                        gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankAttacker], MOVE_POUND, 0, 40, 0, gBankAttacker, gBankAttacker);
                        gProtectStructs[gBankAttacker].confusionSelfDmg = 1;
                        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    }
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                }
                else // snapped out of confusion
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 10: // paralysis
            if ((gBattleMons[gBankAttacker].status1 & STATUS_PARALYSIS) && (Random() % 4) == 0)
            {
                gProtectStructs[gBankAttacker].prlzImmobility = 1;
                // This is removed in Emerald for some reason
                //CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 11: // infatuation
            if (gBattleMons[gBankAttacker].status2 & STATUS2_INFATUATION)
            {
                gBattleScripting.bank = CountTrailingZeroBits((gBattleMons[gBankAttacker].status2 & STATUS2_INFATUATION) >> 0x10);
                if (Random() & 1)
                    BattleScriptPushCursor();
                else
                {
                    BattleScriptPush(BattleScript_MoveUsedIsParalyzedCantAttack);
                    gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    gProtectStructs[gBankAttacker].loveImmobility = 1;
                    CancelMultiTurnMoves(gBankAttacker);
                }
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 12: // bide
            if (gBattleMons[gBankAttacker].status2 & STATUS2_BIDE)
            {
                gBattleMons[gBankAttacker].status2 -= 0x100;
                if (gBattleMons[gBankAttacker].status2 & STATUS2_BIDE)
                    gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
                else
                {
                    // This is removed in Emerald for some reason
                    //gBattleMons[gBankAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
                    if (gTakenDmg[gBankAttacker])
                    {
                        gCurrentMove = MOVE_BIDE;
                        *bideDmg = gTakenDmg[gBankAttacker] * 2;
                        gBankTarget = gTakenDmgBanks[gBankAttacker];
                        if (gAbsentBankFlags & gBitTable[gBankTarget])
                            gBankTarget = GetMoveTarget(MOVE_BIDE, 1);
                        gBattlescriptCurrInstr = BattleScript_BideAttack;
                    }
                    else
                        gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
                }
                effect = 1;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 13: // move thawing
            if (gBattleMons[gBankAttacker].status1 & STATUS_FREEZE)
            {
                if (gBattleMoves[gCurrentMove].effect == EFFECT_THAW_HIT)
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                }
                effect = 2;
            }
            gBattleStruct->atkCancellerTracker++;
            break;
        case 14: // last case
            break;
        }

    } while (gBattleStruct->atkCancellerTracker != ATKCANCELLER_MAX_CASE && effect == 0);

    if (effect == 2)
    {
        gActiveBank = gBankAttacker;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
        MarkBufferBankForExecution(gActiveBank);
    }
    return effect;
}

bool8 sub_80423F4(u8 bank, u8 r1, u8 r2)
{
    struct Pokemon* party;
    u8 r7;
    u8 r6;
    s32 i;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;
        r6 = ((bank & 2) / 2);
        for (i = r6 * 3; i < r6 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == r6 * 3 + 3);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x800000)
        {
            if (GetBankSide(bank) == SIDE_PLAYER)
            {
                party = gPlayerParty;
                r7 = sub_806D864(bank);
                r6 = sub_806D82C(r7);
            }
            else
            {
                // FIXME: Compiler insists on moving r4 into r1 before doing the eor
                #ifndef NONMATCHING
                register u32 var asm("r1");
                #else
                u32 var;
                #endif // NONMATCHING

                party = gEnemyParty;
                var = bank ^ 1;
                r6 = (var != 0) ? 1 : 0;
            }
        }
        else
        {
            r7 = sub_806D864(bank);
            if (GetBankSide(bank) == SIDE_PLAYER)
                party = gPlayerParty;
            else
                party = gEnemyParty;
            r6 = sub_806D82C(r7);
        }
        for (i = r6 * 3; i < r6 * 3 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == r6 * 3 + 3);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && GetBankSide(bank) == SIDE_OPPONENT)
    {
        party = gEnemyParty;

        if (bank == 1)
            r6 = 0;
        else
            r6 = 3;
        for (i = r6; i < r6 + 3; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
                break;
        }
        return (i == r6 + 3);
    }
    else
    {
        if (GetBankSide(bank) == SIDE_OPPONENT)
        {
            r7 = GetBankByIdentity(1);
            r6 = GetBankByIdentity(3);
            party = gEnemyParty;
        }
        else
        {
            r7 = GetBankByIdentity(0);
            r6 = GetBankByIdentity(2);
            party = gPlayerParty;
        }
        if (r1 == 6)
            r1 = gBattlePartyID[r7];
        if (r2 == 6)
            r2 = gBattlePartyID[r6];
        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG
            // FIXME: Using index[array] instead of array[index] is BAD!
             && i != r1 && i != r2 && i != r7[gBattleStruct->field_5C] && i != r6[gBattleStruct->field_5C])
                break;
        }
        return (i == 6);
    }
}

enum
{
    CASTFORM_NO_CHANGE, //0
    CASTFORM_TO_NORMAL, //1
    CASTFORM_TO_FIRE,   //2
    CASTFORM_TO_WATER,  //3
    CASTFORM_TO_ICE,    //4
};

u8 CastformDataTypeChange(u8 bank)
{
    u8 formChange = 0;
    if (gBattleMons[bank].species != SPECIES_CASTFORM || gBattleMons[bank].ability != ABILITY_FORECAST || gBattleMons[bank].hp == 0)
        return CASTFORM_NO_CHANGE;
    if (!WEATHER_HAS_EFFECT && gBattleMons[bank].type1 != TYPE_NORMAL && gBattleMons[bank].type2 != TYPE_NORMAL)
    {
        gBattleMons[bank].type1 = TYPE_NORMAL;
        gBattleMons[bank].type2 = TYPE_NORMAL;
        return CASTFORM_TO_NORMAL;
    }
    if (!WEATHER_HAS_EFFECT)
        return CASTFORM_NO_CHANGE;
    if (!(gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SUN_ANY | WEATHER_HAIL)) && gBattleMons[bank].type1 != TYPE_NORMAL && gBattleMons[bank].type2 != TYPE_NORMAL)
    {
        gBattleMons[bank].type1 = TYPE_NORMAL;
        gBattleMons[bank].type2 = TYPE_NORMAL;
        formChange = CASTFORM_TO_NORMAL;
    }
    if (gBattleWeather & WEATHER_SUN_ANY && gBattleMons[bank].type1 != TYPE_FIRE && gBattleMons[bank].type2 != TYPE_FIRE)
    {
        gBattleMons[bank].type1 = TYPE_FIRE;
        gBattleMons[bank].type2 = TYPE_FIRE;
        formChange = CASTFORM_TO_FIRE;
    }
    if (gBattleWeather & WEATHER_RAIN_ANY && gBattleMons[bank].type1 != TYPE_WATER && gBattleMons[bank].type2 != TYPE_WATER)
    {
        gBattleMons[bank].type1 = TYPE_WATER;
        gBattleMons[bank].type2 = TYPE_WATER;
        formChange = CASTFORM_TO_WATER;
    }
    if (gBattleWeather & WEATHER_HAIL && gBattleMons[bank].type1 != TYPE_ICE && gBattleMons[bank].type2 != TYPE_ICE)
    {
        gBattleMons[bank].type1 = TYPE_ICE;
        gBattleMons[bank].type2 = TYPE_ICE;
        formChange = CASTFORM_TO_ICE;
    }
    return formChange;
}

// We meet again, ABE.
#ifdef NONMATCHING
u8 AbilityBattleEffects(u8 caseID, u8 bank, u8 ability, u8 special, u16 moveArg)
{
    u8 effect = 0;
    struct Pokemon* pokeAtk;
    struct Pokemon* pokeDef;
    u16 speciesAtk;
    u16 speciesDef;
    u32 pidAtk;
    u32 pidDef;

    if (gBankAttacker >= gNoOfAllBanks)
        gBankAttacker = bank;
    if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        pokeAtk = &gPlayerParty[gBattlePartyID[gBankAttacker]];
    else
        pokeAtk = &gEnemyParty[gBattlePartyID[gBankAttacker]];

    if (gBankTarget >= gNoOfAllBanks)
        gBankTarget = bank;
    if (GetBankSide(gBankTarget) == SIDE_PLAYER)
        pokeDef = &gPlayerParty[gBattlePartyID[gBankTarget]];
    else
        pokeDef = &gEnemyParty[gBattlePartyID[gBankTarget]];

    speciesAtk = GetMonData(pokeAtk, MON_DATA_SPECIES);
    pidAtk = GetMonData(pokeAtk, MON_DATA_PERSONALITY);

    speciesDef = GetMonData(pokeDef, MON_DATA_SPECIES);
    pidDef = GetMonData(pokeDef, MON_DATA_PERSONALITY);

    if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI)) // why isn't that check done at the beginning?
    {
        int i;  // r4
        u16 move;
        // Hmm...
        #define moveType moveArg
        //u16 moveType;
        u8 side;

        if (special)
            gLastUsedAbility = special;
        else
            gLastUsedAbility = gBattleMons[bank].ability;

        if (moveArg)
            move = moveArg;
        else
            move = gCurrentMove;

        if (gBattleStruct->dynamicMoveType)
            moveType = gBattleStruct->dynamicMoveType & 0x3F;
        else
            moveType = gBattleMoves[move].type;

        switch (caseID)
        {
        case ABILITYEFFECT_ON_SWITCHIN: // 0
        //_08042A18
            if (gBankAttacker >= gNoOfAllBanks)
                gBankAttacker = bank;
            switch (gLastUsedAbility)
            {
            case ABILITYEFFECT_SWITCH_IN_WEATHER:
            //_08042A86
                switch (weather_get_current())
                {
                case 3:
                case 5:
                case 13:
                    if (!(gBattleWeather & WEATHER_RAIN_ANY))
                    {
                        gBattleWeather = (WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_PERMANENT);
                        gBattleScripting.animArg1 = 0xA;
                        gBattleScripting.bank = bank;
                        effect++;
                    }
                    break;
                case 8:
                    if (!(gBattleWeather & WEATHER_SANDSTORM_ANY))
                    {
                        gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                        gBattleScripting.animArg1 = 0xC;
                        gBattleScripting.bank = bank;
                        effect++;
                    }
                    break;
                case 12:
                    if (!(gBattleWeather & WEATHER_SUN_ANY))
                    {
                        gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                        gBattleScripting.animArg1 = 0xB;
                        gBattleScripting.bank = bank;
                        effect++;
                    }
                    break;
                }
                if (effect)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = weather_get_current();
                    BattleScriptPushCursorAndCallback(gUnknown_082DACE7);
                }
                break;
            case ABILITY_DRIZZLE:
            //_08042B78
                if (!(gBattleWeather & WEATHER_RAIN_PERMANENT))
                {
                    gBattleWeather = (WEATHER_RAIN_PERMANENT | WEATHER_RAIN_TEMPORARY);
                    BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
                    gBattleScripting.bank = bank;
                    effect++;
                }
                break;
            case ABILITY_SAND_STREAM:
            //_08042BA8
                if (!(gBattleWeather & WEATHER_SANDSTORM_PERMANENT))
                {
                    gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                    BattleScriptPushCursorAndCallback(BattleScript_SandstreamActivates);
                    gBattleScripting.bank = bank;
                    effect++;
                }
                break;
            case ABILITY_DROUGHT:
            //_08042BD8
                if (!(gBattleWeather & WEATHER_SUN_PERMANENT))
                {
                    gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                    BattleScriptPushCursorAndCallback(BattleScript_DroughtActivates);
                    gBattleScripting.bank = bank;
                    effect++;
                }
                break;
            case ABILITY_INTIMIDATE:
            //_08042C08
                if (!(gSpecialStatuses[bank].intimidatedPoke))
                {
                    gStatuses3[bank] |= STATUS3_INTIMIDATE_POKES;
                    gSpecialStatuses[bank].intimidatedPoke = 1;
                }
                break;
            case ABILITY_FORECAST:
            //_08042C3C
                effect = CastformDataTypeChange(bank);
                if (effect != 0)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                    gBattleScripting.bank = bank;
                    gBattleStruct->formToChangeInto = effect - 1;
                }
                break;
            case ABILITY_TRACE:
                if (!(gSpecialStatuses[bank].traced))
                {
                    gStatuses3[bank] |= STATUS3_TRACE;
                    gSpecialStatuses[bank].traced = 1;
                }
                break;
            case ABILITY_CLOUD_NINE:
            case ABILITY_AIR_LOCK:
                {
                    u8 i;

                    for (i = 0; i < gNoOfAllBanks; i++)
                    {
                        // TODO: i should be in r6 here
                        //asm("":::"r4","r5");
                        effect = CastformDataTypeChange(i);
                        if (effect != 0)
                        {
                            BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                            gBattleScripting.bank = i;
                            gBattleStruct->formToChangeInto = effect - 1;
                            break;
                        }
                    }
                }
                break;
            }
            break;
        case ABILITYEFFECT_ENDTURN: // 1
        //_08042CDC
            if (gBattleMons[bank].hp != 0)
            {
                gBankAttacker = bank;
                switch (gLastUsedAbility)
                {
                case ABILITY_RAIN_DISH:
                //_08042D22
                    if (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY)
                     && gBattleMons[bank].maxHP > gBattleMons[bank].hp)
                    {
                        gLastUsedAbility = ABILITY_RAIN_DISH; //why
                        BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                        gBattleMoveDamage = gBattleMons[bank].maxHP / 16;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        effect++;
                    }
                    break;
                case ABILITY_SHED_SKIN:
                //_08042DA0
                    if ((gBattleMons[bank].status1 & STATUS_ANY) && (Random() % 3) == 0)
                    {
                        if (gBattleMons[bank].status1 & (STATUS_POISON | STATUS_TOXIC_POISON))
                            StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        if (gBattleMons[bank].status1 & STATUS_SLEEP)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        if (gBattleMons[bank].status1 & STATUS_PARALYSIS)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        if (gBattleMons[bank].status1 & STATUS_BURN)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        if (gBattleMons[bank].status1 & STATUS_FREEZE)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        gBattleMons[bank].status1 = 0;
                        gBattleMons[bank].status2 &= ~(STATUS2_NIGHTMARE);  // fix nighmare glitch
                        gBattleScripting.bank = gActiveBank = bank;
                        BattleScriptPushCursorAndCallback(BattleScript_ShedSkinActivates);
                        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[bank].status1);
                        MarkBufferBankForExecution(gActiveBank);
                        effect++;
                    }
                    break;
                case ABILITY_SPEED_BOOST:
                //_08042E84
                    if (gBattleMons[bank].statStages[STAT_STAGE_SPEED] < 0xC && gDisableStructs[bank].isFirstTurn != 2)
                    {
                        gBattleMons[bank].statStages[STAT_STAGE_SPEED]++;
                        gBattleScripting.animArg1 = 0x11;
                        gBattleScripting.animArg2 = 0;
                        BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                        gBattleScripting.bank = bank;
                        effect++;
                    }
                    break;
                case ABILITY_TRUANT:
                    gDisableStructs[gBankAttacker].truantCounter ^= 1;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_MOVES_BLOCK: // 2
        //_08042EF8
            if (gLastUsedAbility == ABILITY_SOUNDPROOF)
            {
                for (i = 0; gSoundMovesTable[i] != 0xFFFF; i++)
                {
                    if (gSoundMovesTable[i] == move)
                        break;
                }
                if (gSoundMovesTable[i] != 0xFFFF)
                {
                    if (gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS)
                        gHitMarker |= HITMARKER_NO_PPDEDUCT;
                    gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
                    effect = 1;
                }
            }
            break;
        case ABILITYEFFECT_ABSORBING: // 3
            if (move)
            {
                switch (gLastUsedAbility)
                {
                case ABILITY_VOLT_ABSORB:
                    if (moveType == TYPE_ELECTRIC && gBattleMoves[move].power != 0)
                    {
                        if (gProtectStructs[gBankAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                        else
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;
                        effect = 1;
                    }
                    break;
                case ABILITY_WATER_ABSORB:
                    if (moveType == TYPE_WATER && gBattleMoves[move].power != 0)
                    {
                        if (gProtectStructs[gBankAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                        else
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;
                        effect = 1;
                    }
                    break;
                case ABILITY_FLASH_FIRE:
                //_0804305C
                    if (moveType == TYPE_FIRE && !(gBattleMons[bank].status1 & STATUS_FREEZE))
                    {
                        if (!(gBattleResources->flags->flags[bank] & UNKNOWN_FLAG_FLASH_FIRE))
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                            if (gProtectStructs[gBankAttacker].notFirstStrike)
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                            else
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                            gBattleResources->flags->flags[bank] |= UNKNOWN_FLAG_FLASH_FIRE;
                            effect = 2;
                        }
                        else
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                            if (gProtectStructs[gBankAttacker].notFirstStrike)
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                            else
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                            effect = 2;
                        }
                    }
                    break;
                }
                if (effect == 1)
                {
                    if (gBattleMons[bank].maxHP == gBattleMons[bank].hp)
                    {
                        if ((gProtectStructs[gBankAttacker].notFirstStrike))
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                        else
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;
                    }
                    else
                    {
                        gBattleMoveDamage = gBattleMons[bank].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                    }
                }
            }
            break;
        case ABILITYEFFECT_CONTACT: // 4
        //_080431AC
            switch (gLastUsedAbility)
            {
            case ABILITY_COLOR_CHANGE:
            //_08043288
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && move != MOVE_STRUGGLE
                 && gBattleMoves[move].power != 0
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && gBattleMons[bank].type1 != moveType
                 && gBattleMons[bank].type2 != moveType
                 && gBattleMons[bank].hp != 0)
                {
                    gBattleMons[bank].type1 = moveType;
                    gBattleMons[bank].type2 = moveType;
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 3;
                    gBattleTextBuff1[2] = moveType;
                    gBattleTextBuff1[3] = 0xFF;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ColorChangeActivates;
                    effect++;
                }
                break;
            case ABILITY_ROUGH_SKIN:
            //_08043350
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
                {
                    gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                    effect++;
                }
                break;
            case ABILITY_EFFECT_SPORE:
            //_08043410
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 10) == 0)
                {
                    do
                    {
                        gBattleCommunication[MOVE_EFFECT_BYTE] = Random() & 3;
                    } while (gBattleCommunication[MOVE_EFFECT_BYTE] == 0);
                    if (gBattleCommunication[MOVE_EFFECT_BYTE] == 3)
                        gBattleCommunication[MOVE_EFFECT_BYTE] += 2;
                    gBattleCommunication[MOVE_EFFECT_BYTE] += 0x40;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
                break;
            case ABILITY_POISON_POINT:
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = 0x42;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
                break;
            case ABILITY_STATIC:
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = 0x45;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
                break;
            case ABILITY_FLAME_BODY:
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = 0x43;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                    effect++;
                }
                break;
            case ABILITY_CUTE_CHARM:
            //_0804379C
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                 && gBattleMons[gBankAttacker].hp != 0
                 && !gProtectStructs[gBankAttacker].confusionSelfDmg
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                 && gBattleMons[gBankTarget].hp != 0
                 && (Random() % 3) == 0
                 && gBattleMons[gBankAttacker].ability != ABILITY_OBLIVIOUS
                 && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
                 && !(gBattleMons[gBankAttacker].status2 & STATUS2_INFATUATION)
                 && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != 0xFF
                 && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != 0xFF)
                {
                    gBattleMons[gBankAttacker].status2 |= (gBitTable[gBankTarget] << 0x10);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                    effect++;
                }
                break;
            }
            break;
        case ABILITYEFFECT_IMMUNITY: // 5
            {
            #define i bank
                for (i = 0; i < gNoOfAllBanks; i++)
                {
                    switch (gBattleMons[i].ability)
                    {
                    case ABILITY_IMMUNITY:
                        if (gBattleMons[i].status1 & (STATUS_POISON | STATUS_TOXIC_POISON | 0xF00))  // TODO: what is 0xF00?
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                            effect = 1;
                        }
                        break;
                    case ABILITY_OWN_TEMPO:
                    //_08043A7C
                        if (gBattleMons[i].status2 & STATUS2_CONFUSION)
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                            effect = 2;
                        }
                        break;
                    case ABILITY_LIMBER:
                        if (gBattleMons[i].status1 & STATUS_PARALYSIS)
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                            effect = 1;
                        }
                        break;
                    case ABILITY_INSOMNIA:
                    case ABILITY_VITAL_SPIRIT:
                        if (gBattleMons[i].status1 & STATUS_SLEEP)
                        {
                            gBattleMons[i].status2 &= ~(STATUS2_NIGHTMARE);
                            StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                            effect = 1;
                        }
                        break;
                    case ABILITY_WATER_VEIL:
                        if (gBattleMons[i].status1 & STATUS_BURN)
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                            effect = 1;
                        }
                        break;
                    case ABILITY_MAGMA_ARMOR:
                        if (gBattleMons[i].status1 & STATUS_FREEZE)
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                            effect = 1;
                        }
                        break;
                    case ABILITY_OBLIVIOUS:
                    //_08043B70
                        if (gBattleMons[i].status2 & STATUS2_INFATUATION)
                        {
                            StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                            effect = 3;
                        }
                        break;
                    }
                    if (effect)
                    {
                        switch (effect)
                        {
                        case 1: // status cleared
                            gBattleMons[i].status1 = 0;
                            break;
                        case 2: // get rid of confusion
                            gBattleMons[i].status2 &= ~(STATUS2_CONFUSION);
                            break;
                        case 3: // get rid of infatuation
                            gBattleMons[i].status2 &= ~(STATUS2_INFATUATION);
                            break;
                        }
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = gUnknown_082DB68C;
                        gBattleScripting.bank = i;
                        gActiveBank = i;
                        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                        MarkBufferBankForExecution(gActiveBank);
                        return effect;
                    }
                }
            #undef i
            }
            break;
        case ABILITYEFFECT_FORECAST: // 6
            {
            #define i bank
                for (i = 0; i < gNoOfAllBanks; i++)
                {
                    if (gBattleMons[i].ability == ABILITY_FORECAST)
                    {
                        effect = CastformDataTypeChange(i);
                        if (effect)
                        {
                            BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                            gBattleScripting.bank = i;
                            gBattleStruct->formToChangeInto = effect - 1;
                            return effect;
                        }
                    }
                }
            #undef i
            }
            break;
        case ABILITYEFFECT_SYNCHRONIZE: // 7
        //_08043CBC
            if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
            {
                gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
                gBattleStruct->synchronizeMoveEffect &= 0x3F;
                if (gBattleStruct->synchronizeMoveEffect == 6)
                    gBattleStruct->synchronizeMoveEffect = 2;
                gBattleCommunication[MOVE_EFFECT_BYTE] = gBattleStruct->synchronizeMoveEffect + 0x40;
                gBattleScripting.bank = gBankTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITYEFFECT_ATK_SYNCHRONIZE: // 8
            if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
            {
                gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
                gBattleStruct->synchronizeMoveEffect &= 0x3F;
                if (gBattleStruct->synchronizeMoveEffect == 6)
                    gBattleStruct->synchronizeMoveEffect = 2;
                gBattleCommunication[MOVE_EFFECT_BYTE] = gBattleStruct->synchronizeMoveEffect;
                gBattleScripting.bank = gBankAttacker;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITYEFFECT_INTIMIDATE1: // 9
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ABILITY_INTIMIDATE && gStatuses3[i] & STATUS3_INTIMIDATE_POKES)
                {
                    gLastUsedAbility = ABILITY_INTIMIDATE;
                    gStatuses3[i] &= ~(STATUS3_INTIMIDATE_POKES);
                    BattleScriptPushCursorAndCallback(gUnknown_082DB4B8);
                    gBattleStruct->intimidateBank = i;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_TRACE: // 11
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ABILITY_TRACE && (gStatuses3[i] & STATUS3_TRACE))
                {
                    u8 opposite = (GetBankIdentity(i) ^ 1) & 1;
                    u8 target1 = GetBankByIdentity(opposite);
                    u8 target2 = GetBankByIdentity(opposite + 2);
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (gBattleMons[target1].ability != 0 && gBattleMons[target1].hp != 0
                         && gBattleMons[target2].ability != 0 && gBattleMons[target2].hp != 0)
                        {
                            gActiveBank = GetBankByIdentity(((Random() & 1) * 2) | opposite);
                            gBattleMons[i].ability = gBattleMons[gActiveBank].ability;
                            gLastUsedAbility = gBattleMons[gActiveBank].ability;
                            effect++;
                        }
                        else if (gBattleMons[target1].ability != 0 && gBattleMons[target1].hp != 0)
                        {
                            gActiveBank = target1;
                            gBattleMons[i].ability = gBattleMons[gActiveBank].ability;
                            gLastUsedAbility = gBattleMons[gActiveBank].ability;
                            effect++;
                        }
                        else if (gBattleMons[target2].ability != 0 && gBattleMons[target2].hp != 0)
                        {
                            gActiveBank = target2;
                            gBattleMons[i].ability = gBattleMons[gActiveBank].ability;
                            gLastUsedAbility = gBattleMons[gActiveBank].ability;
                            effect++;
                        }
                    }
                    else
                    {
                        gActiveBank = target1;
                        if (gBattleMons[target1].ability && gBattleMons[target1].hp)
                        {
                            gBattleMons[i].ability = gBattleMons[target1].ability;
                            gLastUsedAbility = gBattleMons[target1].ability;
                            effect++;
                        }
                    }
                    if (effect)
                    {
                        BattleScriptPushCursorAndCallback(BattleScript_TraceActivates);
                        gStatuses3[i] &= ~(STATUS3_TRACE);
                        gBattleScripting.bank = i;

                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 4;
                        gBattleTextBuff1[2] = gActiveBank;
                        gBattleTextBuff1[3] = gBattlePartyID[gActiveBank];
                        gBattleTextBuff1[4] = EOS;

                        gBattleTextBuff2[0] = 0xFD;
                        gBattleTextBuff2[1] = 9;
                        gBattleTextBuff2[2] = gLastUsedAbility;
                        gBattleTextBuff2[3] = EOS;
                        break;
                    }
                }
            }
            break;
        case ABILITYEFFECT_INTIMIDATE2: // 10
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ABILITY_INTIMIDATE && (gStatuses3[i] & STATUS3_INTIMIDATE_POKES))
                {
                    gLastUsedAbility = ABILITY_INTIMIDATE;
                    gStatuses3[i] &= ~(STATUS3_INTIMIDATE_POKES);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = gUnknown_082DB4C1;
                    gBattleStruct->intimidateBank = i;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_OTHER_SIDE: // 12
            side = GetBankSide(bank);
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (GetBankSide(i) != side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_BANK_SIDE: // 13
            side = GetBankSide(bank);
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (GetBankSide(i) == side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_FIELD_SPORT: // 14
            switch (gLastUsedAbility)
            {
            case 0xFD:
                for (i = 0; i < gNoOfAllBanks; i++)
                {
                    if (gStatuses3[i] & STATUS3_MUDSPORT)
                        effect = i + 1;
                }
                break;
            case 0xFE:
                for (i = 0; i < gNoOfAllBanks; i++)
                {
                    if (gStatuses3[i] & STATUS3_WATERSPORT)
                        effect = i + 1;
                }
                break;
            default:
                for (i = 0; i < gNoOfAllBanks; i++)
                {
                    if (gBattleMons[i].ability == ability)
                    {
                        gLastUsedAbility = ability;
                        effect = i + 1;
                    }
                }
                break;
            }
            break;
        case ABILITYEFFECT_CHECK_ON_FIELD: // 19
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ability && gBattleMons[i].hp != 0)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_FIELD_EXCEPT_BANK: // 15
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ability && i != bank)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_OTHER_SIDE: // 16
            side = GetBankSide(bank);
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (GetBankSide(i) != side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_BANK_SIDE: // 17
            side = GetBankSide(bank);
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (GetBankSide(i) == side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_ON_FIELD: // 18
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].ability == ability && i != bank)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        }
        if (effect && caseID < 0xC && gLastUsedAbility != 0xFF)
            RecordAbilityBattle(bank, gLastUsedAbility);
    }

    return effect;
}
#else
__attribute__((naked))
u8 AbilityBattleEffects(u8 caseID, u8 bank, u8 ability, u8 special, u16 moveArg)
{
    asm(
    "\n\
	.syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x28\n\
	ldr r4, [sp, 0x48]\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	str r0, [sp, 0x4]\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r10, r1\n\
	lsls r2, 24\n\
	lsrs r6, r2, 24\n\
	lsls r3, 24\n\
	lsrs r3, 24\n\
	mov r8, r3\n\
	lsls r4, 16\n\
	lsrs r4, 16\n\
	movs r0, 0\n\
	mov r9, r0\n\
	ldr r5, =gBankAttacker\n\
	ldr r1, =gNoOfAllBanks\n\
	ldrb r0, [r5]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bcc _08042864\n\
	mov r1, r10\n\
	strb r1, [r5]\n\
_08042864:\n\
	ldrb r0, [r5]\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	bne _08042894\n\
	ldr r1, =gBattlePartyID\n\
	ldrb r0, [r5]\n\
	lsls r0, 1\n\
	adds r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, 0x64\n\
	muls r1, r0\n\
	ldr r0, =gPlayerParty\n\
	b _080428A4\n\
	.pool\n\
_08042894:\n\
	ldr r1, =gBattlePartyID\n\
	ldrb r0, [r5]\n\
	lsls r0, 1\n\
	adds r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, 0x64\n\
	muls r1, r0\n\
	ldr r0, =gEnemyParty\n\
_080428A4:\n\
	adds r7, r1, r0\n\
	ldr r5, =gBankTarget\n\
	ldr r1, =gNoOfAllBanks\n\
	ldrb r0, [r5]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bcc _080428B6\n\
	mov r2, r10\n\
	strb r2, [r5]\n\
_080428B6:\n\
	ldrb r0, [r5]\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	bne _080428E8\n\
	ldr r1, =gBattlePartyID\n\
	ldrb r0, [r5]\n\
	lsls r0, 1\n\
	adds r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, 0x64\n\
	muls r1, r0\n\
	ldr r0, =gPlayerParty\n\
	b _080428F8\n\
	.pool\n\
_080428E8:\n\
	ldr r1, =gBattlePartyID\n\
	ldrb r0, [r5]\n\
	lsls r0, 1\n\
	adds r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, 0x64\n\
	muls r1, r0\n\
	ldr r0, =gEnemyParty\n\
_080428F8:\n\
	adds r5, r1, r0\n\
	adds r0, r7, 0\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [sp, 0x8]\n\
	adds r0, r7, 0\n\
	movs r1, 0\n\
	bl GetMonData\n\
	str r0, [sp, 0x10]\n\
	adds r0, r5, 0\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	str r0, [sp, 0xC]\n\
	adds r0, r5, 0\n\
	movs r1, 0\n\
	bl GetMonData\n\
	str r0, [sp, 0x14]\n\
	ldr r0, =gBattleTypeFlags\n\
	ldr r0, [r0]\n\
	movs r1, 0x80\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0804293A\n\
	bl _0804443A\n\
_0804293A:\n\
	mov r3, r8\n\
	cmp r3, 0\n\
	beq _08042958\n\
	ldr r0, =gLastUsedAbility\n\
	strb r3, [r0]\n\
	adds r7, r0, 0\n\
	b _0804296E\n\
	.pool\n\
_08042958:\n\
	ldr r2, =gLastUsedAbility\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r5, r10\n\
	muls r5, r0\n\
	adds r0, r5, 0\n\
	adds r0, r1\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	strb r0, [r2]\n\
	adds r7, r2, 0\n\
_0804296E:\n\
	cmp r4, 0\n\
	beq _08042980\n\
	adds r5, r4, 0\n\
	b _08042984\n\
	.pool\n\
_08042980:\n\
	ldr r0, =gCurrentMove\n\
	ldrh r5, [r0]\n\
_08042984:\n\
	ldr r1, =gBattleStruct\n\
	ldr r0, [r1]\n\
	ldrb r0, [r0, 0x13]\n\
	mov r8, r1\n\
	cmp r0, 0\n\
	beq _080429A0\n\
	movs r3, 0x3F\n\
	ands r3, r0\n\
	b _080429AC\n\
	.pool\n\
_080429A0:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r3, [r0, 0x2]\n\
_080429AC:\n\
	ldr r0, [sp, 0x4]\n\
	cmp r0, 0x13\n\
	bls _080429B6\n\
	bl _0804441E\n\
_080429B6:\n\
	lsls r0, 2\n\
	ldr r1, =_080429C8\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_080429C8:\n\
	.4byte _08042A18\n\
	.4byte _08042CDC\n\
	.4byte _08042EF8\n\
	.4byte _08042F8C\n\
	.4byte _080431AC\n\
	.4byte _08043908\n\
	.4byte _08043C6C\n\
	.4byte _08043CBC\n\
	.4byte _08043D40\n\
	.4byte _08043DC4\n\
	.4byte _08043FE4\n\
	.4byte _08043E08\n\
	.4byte _08044028\n\
	.4byte _08044084\n\
	.4byte _080440E0\n\
	.4byte _080441DC\n\
	.4byte _08044220\n\
	.4byte _0804427C\n\
	.4byte _080443EC\n\
	.4byte _08044196\n\
_08042A18:\n\
	ldr r2, =gBankAttacker\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r1, [r2]\n\
	adds r5, r0, 0\n\
	ldrb r3, [r5]\n\
	cmp r1, r3\n\
	bcc _08042A2A\n\
	mov r0, r10\n\
	strb r0, [r2]\n\
_08042A2A:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0x2D\n\
	bne _08042A32\n\
	b _08042BA8\n\
_08042A32:\n\
	cmp r0, 0x2D\n\
	bgt _08042A64\n\
	cmp r0, 0xD\n\
	bne _08042A3C\n\
	b _08042CA4\n\
_08042A3C:\n\
	cmp r0, 0xD\n\
	bgt _08042A54\n\
	cmp r0, 0x2\n\
	bne _08042A46\n\
	b _08042B78\n\
_08042A46:\n\
	bl _0804441E\n\
	.pool\n\
_08042A54:\n\
	cmp r0, 0x16\n\
	bne _08042A5A\n\
	b _08042C08\n\
_08042A5A:\n\
	cmp r0, 0x24\n\
	bne _08042A60\n\
	b _08042C68\n\
_08042A60:\n\
	bl _0804441E\n\
_08042A64:\n\
	cmp r0, 0x46\n\
	bne _08042A6A\n\
	b _08042BD8\n\
_08042A6A:\n\
	cmp r0, 0x46\n\
	bgt _08042A78\n\
	cmp r0, 0x3B\n\
	bne _08042A74\n\
	b _08042C3C\n\
_08042A74:\n\
	bl _0804441E\n\
_08042A78:\n\
	cmp r0, 0x4D\n\
	bne _08042A7E\n\
	b _08042CA4\n\
_08042A7E:\n\
	cmp r0, 0xFF\n\
	beq _08042A86\n\
	bl _0804441E\n\
_08042A86:\n\
	ldr r0, =gBattleTypeFlags\n\
	ldr r0, [r0]\n\
	movs r1, 0x80\n\
	lsls r1, 17\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08042B4C\n\
	bl weather_get_current\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	subs r0, 0x3\n\
	cmp r0, 0xA\n\
	bhi _08042B4C\n\
	lsls r0, 2\n\
	ldr r1, =_08042AB4\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_08042AB4:\n\
	.4byte _08042AE0\n\
	.4byte _08042B4C\n\
	.4byte _08042AE0\n\
	.4byte _08042B4C\n\
	.4byte _08042B4C\n\
	.4byte _08042B04\n\
	.4byte _08042B4C\n\
	.4byte _08042B4C\n\
	.4byte _08042B4C\n\
	.4byte _08042B28\n\
	.4byte _08042AE0\n\
_08042AE0:\n\
	ldr r2, =gBattleWeather\n\
	ldrh r1, [r2]\n\
	movs r0, 0x7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08042B4C\n\
	movs r0, 0x5\n\
	strh r0, [r2]\n\
	ldr r1, =gBattleScripting\n\
	movs r0, 0xA\n\
	strb r0, [r1, 0x10]\n\
	mov r2, r10\n\
	strb r2, [r1, 0x17]\n\
	b _08042B42\n\
	.pool\n\
_08042B04:\n\
	ldr r3, =gBattleWeather\n\
	ldrh r1, [r3]\n\
	movs r2, 0x18\n\
	adds r0, r2, 0\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08042B4C\n\
	strh r2, [r3]\n\
	ldr r1, =gBattleScripting\n\
	movs r0, 0xC\n\
	strb r0, [r1, 0x10]\n\
	mov r3, r10\n\
	strb r3, [r1, 0x17]\n\
	b _08042B42\n\
	.pool\n\
_08042B28:\n\
	ldr r3, =gBattleWeather\n\
	ldrh r1, [r3]\n\
	movs r2, 0x60\n\
	adds r0, r2, 0\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08042B4C\n\
	strh r2, [r3]\n\
	ldr r1, =gBattleScripting\n\
	movs r0, 0xB\n\
	strb r0, [r1, 0x10]\n\
	mov r5, r10\n\
	strb r5, [r1, 0x17]\n\
_08042B42:\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_08042B4C:\n\
	mov r0, r9\n\
	cmp r0, 0\n\
	bne _08042B56\n\
	bl _0804443A\n\
_08042B56:\n\
	bl weather_get_current\n\
	ldr r1, =gBattleCommunication\n\
	strb r0, [r1, 0x5]\n\
	ldr r0, =gUnknown_082DACE7\n\
	bl BattleScriptPushCursorAndCallback\n\
	bl _0804441E\n\
	.pool\n\
_08042B78:\n\
	ldr r2, =gBattleWeather\n\
	ldrh r1, [r2]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042B88\n\
	bl _0804441E\n\
_08042B88:\n\
	movs r0, 0x5\n\
	strh r0, [r2]\n\
	ldr r0, =BattleScript_DrizzleActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	mov r1, r10\n\
	strb r1, [r0, 0x17]\n\
	bl _080443D0\n\
	.pool\n\
_08042BA8:\n\
	ldr r2, =gBattleWeather\n\
	ldrh r1, [r2]\n\
	movs r0, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042BB8\n\
	bl _0804441E\n\
_08042BB8:\n\
	movs r0, 0x18\n\
	strh r0, [r2]\n\
	ldr r0, =BattleScript_SandstreamActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	mov r2, r10\n\
	strb r2, [r0, 0x17]\n\
	bl _080443D0\n\
	.pool\n\
_08042BD8:\n\
	ldr r2, =gBattleWeather\n\
	ldrh r1, [r2]\n\
	movs r0, 0x40\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042BE8\n\
	bl _0804441E\n\
_08042BE8:\n\
	movs r0, 0x60\n\
	strh r0, [r2]\n\
	ldr r0, =BattleScript_DroughtActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	mov r3, r10\n\
	strb r3, [r0, 0x17]\n\
	bl _080443D0\n\
	.pool\n\
_08042C08:\n\
	ldr r0, =gSpecialStatuses\n\
	mov r5, r10\n\
	lsls r2, r5, 2\n\
	adds r1, r2, r5\n\
	lsls r1, 2\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _08042C20\n\
	bl _0804441E\n\
_08042C20:\n\
	ldr r1, =gStatuses3\n\
	adds r1, r2, r1\n\
	ldr r0, [r1]\n\
	movs r2, 0x80\n\
	lsls r2, 12\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
	ldrb r0, [r3]\n\
	movs r1, 0x8\n\
	b _08042C92\n\
	.pool\n\
_08042C3C:\n\
	mov r0, r10\n\
	bl CastformDataTypeChange\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	cmp r0, 0\n\
	bne _08042C50\n\
	bl _0804443A\n\
_08042C50:\n\
	ldr r0, =BattleScript_CastformChange\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	mov r1, r10\n\
	strb r1, [r0, 0x17]\n\
	bl _080442E2\n\
	.pool\n\
_08042C68:\n\
	ldr r0, =gSpecialStatuses\n\
	mov r3, r10\n\
	lsls r2, r3, 2\n\
	adds r1, r2, r3\n\
	lsls r1, 2\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3]\n\
	lsls r0, 27\n\
	cmp r0, 0\n\
	bge _08042C80\n\
	bl _0804441E\n\
_08042C80:\n\
	ldr r1, =gStatuses3\n\
	adds r1, r2, r1\n\
	ldr r0, [r1]\n\
	movs r2, 0x80\n\
	lsls r2, 13\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
	ldrb r0, [r3]\n\
	movs r1, 0x10\n\
_08042C92:\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	bl _0804441E\n\
	.pool\n\
_08042CA4:\n\
	movs r6, 0\n\
	ldrb r5, [r5]\n\
	cmp r6, r5\n\
	bcc _08042CB0\n\
	bl _0804441E\n\
_08042CB0:\n\
	adds r0, r6, 0\n\
	bl CastformDataTypeChange\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	cmp r0, 0\n\
	beq _08042CC4\n\
	bl _080442D8\n\
_08042CC4:\n\
	adds r0, r6, 0x1\n\
	lsls r0, 24\n\
	lsrs r6, r0, 24\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r6, r0\n\
	bcc _08042CB0\n\
	bl _0804441E\n\
	.pool\n\
_08042CDC:\n\
	ldr r5, =gBattleMons\n\
	mov r8, r5\n\
	movs r0, 0x58\n\
	mov r6, r10\n\
	muls r6, r0\n\
	adds r4, r6, r5\n\
	ldrh r0, [r4, 0x28]\n\
	cmp r0, 0\n\
	bne _08042CF2\n\
	bl _0804441E\n\
_08042CF2:\n\
	ldr r0, =gBankAttacker\n\
	mov r1, r10\n\
	strb r1, [r0]\n\
	ldrb r5, [r7]\n\
	cmp r5, 0x2C\n\
	beq _08042D22\n\
	cmp r5, 0x2C\n\
	bgt _08042D14\n\
	cmp r5, 0x3\n\
	bne _08042D08\n\
	b _08042E84\n\
_08042D08:\n\
	bl _0804441E\n\
	.pool\n\
_08042D14:\n\
	cmp r5, 0x36\n\
	bne _08042D1A\n\
	b _08042ED0\n\
_08042D1A:\n\
	cmp r5, 0x3D\n\
	beq _08042DA0\n\
	bl _0804441E\n\
_08042D22:\n\
	movs r0, 0\n\
	str r0, [sp]\n\
	movs r0, 0x13\n\
	movs r1, 0\n\
	movs r2, 0xD\n\
	movs r3, 0\n\
	bl AbilityBattleEffects\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0\n\
	beq _08042D3E\n\
	bl _0804441E\n\
_08042D3E:\n\
	str r0, [sp]\n\
	movs r0, 0x13\n\
	movs r1, 0\n\
	movs r2, 0x4D\n\
	movs r3, 0\n\
	bl AbilityBattleEffects\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _08042D56\n\
	bl _0804441E\n\
_08042D56:\n\
	ldr r0, =gBattleWeather\n\
	ldrh r1, [r0]\n\
	movs r0, 0x7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08042D66\n\
	bl _0804441E\n\
_08042D66:\n\
	ldrh r0, [r4, 0x2C]\n\
	ldrh r2, [r4, 0x28]\n\
	cmp r0, r2\n\
	bhi _08042D72\n\
	bl _0804441E\n\
_08042D72:\n\
	strb r5, [r7]\n\
	ldr r0, =BattleScript_RainDishActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r1, =gBattleMoveDamage\n\
	ldrh r0, [r4, 0x2C]\n\
	lsrs r0, 4\n\
	str r0, [r1]\n\
	cmp r0, 0\n\
	bne _08042D8A\n\
	movs r0, 0x1\n\
	str r0, [r1]\n\
_08042D8A:\n\
	ldr r0, [r1]\n\
	negs r0, r0\n\
	str r0, [r1]\n\
	bl _080443D0\n\
	.pool\n\
_08042DA0:\n\
	mov r0, r8\n\
	adds r0, 0x4C\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, 0\n\
	bne _08042DB0\n\
	bl _0804441E\n\
_08042DB0:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x3\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
	cmp r4, 0\n\
	beq _08042DCA\n\
	bl _0804441E\n\
_08042DCA:\n\
	ldr r0, [r5]\n\
	movs r1, 0x88\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042DDC\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_PoisonJpn\n\
	bl StringCopy\n\
_08042DDC:\n\
	ldr r0, [r5]\n\
	movs r1, 0x7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042DEE\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_SleepJpn\n\
	bl StringCopy\n\
_08042DEE:\n\
	ldr r0, [r5]\n\
	movs r1, 0x40\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042E00\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_ParalysisJpn\n\
	bl StringCopy\n\
_08042E00:\n\
	ldr r0, [r5]\n\
	movs r1, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042E12\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_BurnJpn\n\
	bl StringCopy\n\
_08042E12:\n\
	ldr r0, [r5]\n\
	movs r1, 0x20\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042E24\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_IceJpn\n\
	bl StringCopy\n\
_08042E24:\n\
	str r4, [r5]\n\
	mov r1, r8\n\
	adds r1, 0x50\n\
	adds r1, r6, r1\n\
	ldr r0, [r1]\n\
	ldr r2, =0xf7ffffff\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	ldr r0, =gBattleScripting\n\
	ldr r4, =gActiveBank\n\
	mov r3, r10\n\
	strb r3, [r4]\n\
	strb r3, [r0, 0x17]\n\
	ldr r0, =BattleScript_ShedSkinActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	str r5, [sp]\n\
	movs r0, 0\n\
	movs r1, 0x28\n\
	movs r2, 0\n\
	movs r3, 0x4\n\
	bl EmitSetMonData\n\
	ldrb r0, [r4]\n\
	bl MarkBufferBankForExecution\n\
	bl _080443D0\n\
	.pool\n\
_08042E84:\n\
	ldrb r2, [r4, 0x1B]\n\
	movs r0, 0x1B\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0xB\n\
	ble _08042E92\n\
	bl _0804441E\n\
_08042E92:\n\
	ldr r0, =gDisableStructs\n\
	mov r5, r10\n\
	lsls r1, r5, 3\n\
	subs r1, r5\n\
	lsls r1, 2\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x16]\n\
	cmp r0, 0x2\n\
	bne _08042EA8\n\
	bl _0804441E\n\
_08042EA8:\n\
	adds r0, r2, 0x1\n\
	movs r1, 0\n\
	strb r0, [r4, 0x1B]\n\
	ldr r4, =gBattleScripting\n\
	movs r0, 0x11\n\
	strb r0, [r4, 0x10]\n\
	strb r1, [r4, 0x11]\n\
	ldr r0, =BattleScript_SpeedBoostActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	strb r5, [r4, 0x17]\n\
	bl _080443D0\n\
	.pool\n\
_08042ED0:\n\
	ldr r2, =gDisableStructs\n\
	ldrb r0, [r0]\n\
	lsls r1, r0, 3\n\
	subs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r2\n\
	ldrb r3, [r1, 0x18]\n\
	lsls r0, r3, 31\n\
	lsrs r0, 31\n\
	movs r2, 0x1\n\
	eors r2, r0\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	ands r0, r3\n\
	orrs r0, r2\n\
	strb r0, [r1, 0x18]\n\
	bl _0804441E\n\
	.pool\n\
_08042EF8:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0x2B\n\
	beq _08042F02\n\
	bl _0804441E\n\
_08042F02:\n\
	movs r4, 0\n\
	ldr r0, =gSoundMovesTable\n\
	ldrh r2, [r0]\n\
	ldr r3, =0x0000ffff\n\
	adds r1, r0, 0\n\
	cmp r2, r3\n\
	bne _08042F14\n\
	bl _0804441E\n\
_08042F14:\n\
	cmp r2, r5\n\
	beq _08042F2C\n\
	adds r2, r1, 0\n\
_08042F1A:\n\
	adds r2, 0x2\n\
	adds r4, 0x1\n\
	ldrh r0, [r2]\n\
	cmp r0, r3\n\
	bne _08042F28\n\
	bl _0804441E\n\
_08042F28:\n\
	cmp r0, r5\n\
	bne _08042F1A\n\
_08042F2C:\n\
	lsls r0, r4, 1\n\
	adds r0, r1\n\
	ldrh r1, [r0]\n\
	ldr r0, =0x0000ffff\n\
	cmp r1, r0\n\
	bne _08042F3C\n\
	bl _0804441E\n\
_08042F3C:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r1, 0x50\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x80\n\
	lsls r1, 5\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08042F62\n\
	ldr r0, =gHitMarker\n\
	ldr r1, [r0]\n\
	movs r2, 0x80\n\
	lsls r2, 4\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_08042F62:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_SoundproofProtected\n\
	str r0, [r1]\n\
	movs r0, 0x1\n\
	mov r9, r0\n\
	bl _08044424\n\
	.pool\n\
_08042F8C:\n\
	cmp r5, 0\n\
	bne _08042F94\n\
	bl _0804441E\n\
_08042F94:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0xB\n\
	beq _08043004\n\
	cmp r0, 0xB\n\
	bgt _08042FA4\n\
	cmp r0, 0xA\n\
	beq _08042FAA\n\
	b _08043126\n\
_08042FA4:\n\
	cmp r0, 0x12\n\
	beq _0804305C\n\
	b _08043126\n\
_08042FAA:\n\
	cmp r3, 0xD\n\
	beq _08042FB0\n\
	b _08043126\n\
_08042FB0:\n\
	ldr r0, =gBattleMoves\n\
	lsls r1, r5, 1\n\
	adds r1, r5\n\
	lsls r1, 2\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	cmp r0, 0\n\
	bne _08042FC2\n\
	b _08043126\n\
_08042FC2:\n\
	ldr r1, =gProtectStructs\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _08042FF0\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_MoveHPDrain\n\
	b _08042FF4\n\
	.pool\n\
_08042FF0:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_MoveHPDrain_PPLoss\n\
_08042FF4:\n\
	str r0, [r1]\n\
	movs r1, 0x1\n\
	b _08043124\n\
	.pool\n\
_08043004:\n\
	cmp r3, 0xB\n\
	beq _0804300A\n\
	b _08043126\n\
_0804300A:\n\
	ldr r0, =gBattleMoves\n\
	lsls r1, r5, 1\n\
	adds r1, r5\n\
	lsls r1, 2\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	cmp r0, 0\n\
	bne _0804301C\n\
	b _08043126\n\
_0804301C:\n\
	ldr r1, =gProtectStructs\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _08043048\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_MoveHPDrain\n\
	b _0804304C\n\
	.pool\n\
_08043048:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_MoveHPDrain_PPLoss\n\
_0804304C:\n\
	str r0, [r1]\n\
	movs r2, 0x1\n\
	mov r9, r2\n\
	b _08043126\n\
	.pool\n\
_0804305C:\n\
	cmp r3, 0xA\n\
	bne _08043126\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r1, 0x4C\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x20\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043126\n\
	ldr r2, =gBattleResources\n\
	ldr r0, [r2]\n\
	ldr r0, [r0, 0x4]\n\
	mov r5, r10\n\
	lsls r1, r5, 2\n\
	adds r0, r1\n\
	ldr r3, [r0]\n\
	movs r4, 0x1\n\
	ands r3, r4\n\
	adds r5, r1, 0\n\
	cmp r3, 0\n\
	bne _080430EC\n\
	ldr r0, =gBattleCommunication\n\
	strb r3, [r0, 0x5]\n\
	ldr r1, =gProtectStructs\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _080430C8\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_FlashFireBoost\n\
	b _080430CC\n\
	.pool\n\
_080430C8:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_FlashFireBoost_PPLoss\n\
_080430CC:\n\
	str r0, [r1]\n\
	ldr r0, [r2]\n\
	ldr r1, [r0, 0x4]\n\
	adds r1, r5\n\
	ldr r0, [r1]\n\
	movs r2, 0x1\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
	movs r0, 0x2\n\
	mov r9, r0\n\
	b _08043126\n\
	.pool\n\
_080430EC:\n\
	ldr r0, =gBattleCommunication\n\
	strb r4, [r0, 0x5]\n\
	ldr r1, =gProtectStructs\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _0804311C\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_FlashFireBoost\n\
	b _08043120\n\
	.pool\n\
_0804311C:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_FlashFireBoost_PPLoss\n\
_08043120:\n\
	str r0, [r1]\n\
	movs r1, 0x2\n\
_08043124:\n\
	mov r9, r1\n\
_08043126:\n\
	mov r2, r9\n\
	cmp r2, 0x1\n\
	beq _08043130\n\
	bl _0804441E\n\
_08043130:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r1, r0, r1\n\
	ldrh r0, [r1, 0x2C]\n\
	ldrh r5, [r1, 0x28]\n\
	cmp r0, r5\n\
	bne _0804318C\n\
	ldr r1, =gProtectStructs\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x2]\n\
	lsls r0, 28\n\
	cmp r0, 0\n\
	bge _08043178\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =gUnknown_082DB592\n\
	str r0, [r1]\n\
	bl _0804441E\n\
	.pool\n\
_08043178:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =gUnknown_082DB591\n\
	str r0, [r1]\n\
	bl _0804441E\n\
	.pool\n\
_0804318C:\n\
	ldr r2, =gBattleMoveDamage\n\
	ldrh r0, [r1, 0x2C]\n\
	lsrs r0, 2\n\
	str r0, [r2]\n\
	cmp r0, 0\n\
	bne _0804319C\n\
	mov r0, r9\n\
	str r0, [r2]\n\
_0804319C:\n\
	ldr r0, [r2]\n\
	negs r0, r0\n\
	str r0, [r2]\n\
	bl _0804441E\n\
	.pool\n\
_080431AC:\n\
	ldrb r0, [r7]\n\
	subs r0, 0x9\n\
	cmp r0, 0x2F\n\
	bls _080431B8\n\
	bl _0804441E\n\
_080431B8:\n\
	lsls r0, 2\n\
	ldr r1, =_080431C8\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_080431C8:\n\
	.4byte _080435E4\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _08043288\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _08043350\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _08043410\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _08043508\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _080436C0\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804441E\n\
	.4byte _0804379C\n\
_08043288:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043298\n\
	bl _0804441E\n\
_08043298:\n\
	cmp r5, 0xA5\n\
	bne _080432A0\n\
	bl _0804441E\n\
_080432A0:\n\
	ldr r0, =gBattleMoves\n\
	lsls r1, r5, 1\n\
	adds r1, r5\n\
	lsls r1, 2\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	cmp r0, 0\n\
	bne _080432B4\n\
	bl _0804441E\n\
_080432B4:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _080432DC\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _080432DC\n\
	bl _0804441E\n\
_080432DC:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r2, r10\n\
	muls r2, r0\n\
	adds r0, r2, 0\n\
	adds r1, r0, r1\n\
	adds r4, r1, 0\n\
	adds r4, 0x21\n\
	ldrb r0, [r4]\n\
	cmp r0, r3\n\
	bne _080432F6\n\
	bl _0804441E\n\
_080432F6:\n\
	adds r2, r1, 0\n\
	adds r2, 0x22\n\
	ldrb r0, [r2]\n\
	cmp r0, r3\n\
	bne _08043304\n\
	bl _0804441E\n\
_08043304:\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	bne _0804330E\n\
	bl _0804441E\n\
_0804330E:\n\
	strb r3, [r4]\n\
	strb r3, [r2]\n\
	ldr r1, =gBattleTextBuff1\n\
	movs r0, 0xFD\n\
	strb r0, [r1]\n\
	movs r0, 0x3\n\
	strb r0, [r1, 0x1]\n\
	strb r3, [r1, 0x2]\n\
	movs r0, 0xFF\n\
	strb r0, [r1, 0x3]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_ColorChangeActivates\n\
	str r0, [r1]\n\
	bl _080443D0\n\
	.pool\n\
_08043350:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043360\n\
	bl _0804441E\n\
_08043360:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r3, r0, r1\n\
	ldrh r0, [r3, 0x28]\n\
	cmp r0, 0\n\
	bne _08043376\n\
	bl _0804441E\n\
_08043376:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, r2, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _08043388\n\
	bl _0804441E\n\
_08043388:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _080433B0\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _080433B0\n\
	bl _0804441E\n\
_080433B0:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r2, 0x1\n\
	adds r0, r2, 0\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _080433CA\n\
	bl _0804441E\n\
_080433CA:\n\
	ldr r1, =gBattleMoveDamage\n\
	ldrh r0, [r3, 0x2C]\n\
	lsrs r0, 4\n\
	str r0, [r1]\n\
	cmp r0, 0\n\
	bne _080433D8\n\
	str r2, [r1]\n\
_080433D8:\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_RoughSkinActivates\n\
	str r0, [r1]\n\
	bl _080443D0\n\
	.pool\n\
_08043410:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043420\n\
	bl _0804441E\n\
_08043420:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r0, r1\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _08043436\n\
	bl _0804441E\n\
_08043436:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, r2, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _08043448\n\
	bl _0804441E\n\
_08043448:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043470\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043470\n\
	bl _0804441E\n\
_08043470:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043488\n\
	bl _0804441E\n\
_08043488:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0xA\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _080434A0\n\
	bl _0804441E\n\
_080434A0:\n\
	ldr r5, =gBattleCommunication\n\
	movs r4, 0x3\n\
_080434A4:\n\
	bl Random\n\
	ands r0, r4\n\
	strb r0, [r5, 0x3]\n\
	cmp r0, 0\n\
	beq _080434A4\n\
	ldr r1, =gBattleCommunication\n\
	ldrb r0, [r1, 0x3]\n\
	cmp r0, 0x3\n\
	bne _080434BC\n\
	adds r0, 0x2\n\
	strb r0, [r1, 0x3]\n\
_080434BC:\n\
	ldrb r0, [r1, 0x3]\n\
	adds r0, 0x40\n\
	strb r0, [r1, 0x3]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_ApplySecondaryEffect\n\
	str r0, [r1]\n\
	ldr r2, =gHitMarker\n\
	ldr r0, [r2]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	bl _080443D0\n\
	.pool\n\
_08043508:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043518\n\
	bl _0804441E\n\
_08043518:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r0, r1\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _0804352E\n\
	bl _0804441E\n\
_0804352E:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, r2, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _08043540\n\
	bl _0804441E\n\
_08043540:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043568\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043568\n\
	bl _0804441E\n\
_08043568:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043580\n\
	bl _0804441E\n\
_08043580:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x3\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _08043598\n\
	bl _0804441E\n\
_08043598:\n\
	ldr r1, =gBattleCommunication\n\
	movs r0, 0x42\n\
	strb r0, [r1, 0x3]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_ApplySecondaryEffect\n\
	str r0, [r1]\n\
	ldr r2, =gHitMarker\n\
	ldr r0, [r2]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	bl _080443D0\n\
	.pool\n\
_080435E4:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080435F4\n\
	bl _0804441E\n\
_080435F4:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r0, r1\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _0804360A\n\
	bl _0804441E\n\
_0804360A:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, r2, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _0804361C\n\
	bl _0804441E\n\
_0804361C:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043644\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043644\n\
	bl _0804441E\n\
_08043644:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _0804365C\n\
	bl _0804441E\n\
_0804365C:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x3\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _08043674\n\
	bl _0804441E\n\
_08043674:\n\
	ldr r1, =gBattleCommunication\n\
	movs r0, 0x45\n\
	strb r0, [r1, 0x3]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_ApplySecondaryEffect\n\
	str r0, [r1]\n\
	ldr r2, =gHitMarker\n\
	ldr r0, [r2]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	bl _080443D0\n\
	.pool\n\
_080436C0:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080436D0\n\
	bl _0804441E\n\
_080436D0:\n\
	ldr r1, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r0, r1\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _080436E6\n\
	bl _0804441E\n\
_080436E6:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, r2, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _080436F8\n\
	bl _0804441E\n\
_080436F8:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043710\n\
	bl _0804441E\n\
_08043710:\n\
	ldr r2, =gSpecialStatuses\n\
	ldr r0, =gBankTarget\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r1, r0, 2\n\
	adds r0, r2, 0\n\
	adds r0, 0x8\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043738\n\
	adds r0, r2, 0\n\
	adds r0, 0xC\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043738\n\
	bl _0804441E\n\
_08043738:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x3\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _08043750\n\
	bl _0804441E\n\
_08043750:\n\
	ldr r1, =gBattleCommunication\n\
	movs r0, 0x43\n\
	strb r0, [r1, 0x3]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_ApplySecondaryEffect\n\
	str r0, [r1]\n\
	ldr r2, =gHitMarker\n\
	ldr r0, [r2]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	bl _080443D0\n\
	.pool\n\
_0804379C:\n\
	ldr r0, =gBattleMoveFlags\n\
	ldrb r1, [r0]\n\
	movs r0, 0x29\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _080437AC\n\
	bl _0804441E\n\
_080437AC:\n\
	ldr r6, =gBattleMons\n\
	ldr r3, =gBankAttacker\n\
	mov r8, r3\n\
	ldrb r1, [r3]\n\
	movs r7, 0x58\n\
	adds r0, r1, 0\n\
	muls r0, r7\n\
	adds r0, r6\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _080437C6\n\
	bl _0804441E\n\
_080437C6:\n\
	ldr r0, =gProtectStructs\n\
	lsls r1, 4\n\
	adds r1, r0\n\
	ldrb r0, [r1, 0x1]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _080437D8\n\
	bl _0804441E\n\
_080437D8:\n\
	ldr r1, =gBattleMoves\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldrb r1, [r0, 0x8]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _080437F0\n\
	bl _0804441E\n\
_080437F0:\n\
	ldr r3, =gSpecialStatuses\n\
	ldr r5, =gBankTarget\n\
	ldrb r1, [r5]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r2, r0, 2\n\
	adds r0, r3, 0\n\
	adds r0, 0x8\n\
	adds r0, r2, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043818\n\
	adds r0, r3, 0\n\
	adds r0, 0xC\n\
	adds r0, r2, r0\n\
	ldr r0, [r0]\n\
	cmp r0, 0\n\
	bne _08043818\n\
	bl _0804441E\n\
_08043818:\n\
	adds r0, r1, 0\n\
	muls r0, r7\n\
	adds r0, r6\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	bne _08043828\n\
	bl _0804441E\n\
_08043828:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x3\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	cmp r0, 0\n\
	beq _08043840\n\
	bl _0804441E\n\
_08043840:\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	muls r0, r7\n\
	adds r0, r6\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0xC\n\
	bne _08043854\n\
	bl _0804441E\n\
_08043854:\n\
	ldr r0, [sp, 0x8]\n\
	ldr r1, [sp, 0x10]\n\
	bl GetGenderFromSpeciesAndPersonality\n\
	adds r4, r0, 0\n\
	ldr r0, [sp, 0xC]\n\
	ldr r1, [sp, 0x14]\n\
	bl GetGenderFromSpeciesAndPersonality\n\
	lsls r4, 24\n\
	lsls r0, 24\n\
	cmp r4, r0\n\
	bne _08043872\n\
	bl _0804441E\n\
_08043872:\n\
	mov r2, r8\n\
	ldrb r0, [r2]\n\
	muls r0, r7\n\
	adds r4, r6, 0\n\
	adds r4, 0x50\n\
	adds r0, r4\n\
	ldr r0, [r0]\n\
	movs r1, 0xF0\n\
	lsls r1, 12\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0804388E\n\
	bl _0804441E\n\
_0804388E:\n\
	ldr r0, [sp, 0x8]\n\
	ldr r1, [sp, 0x10]\n\
	bl GetGenderFromSpeciesAndPersonality\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0xFF\n\
	bne _080438A2\n\
	bl _0804441E\n\
_080438A2:\n\
	ldr r0, [sp, 0xC]\n\
	ldr r1, [sp, 0x14]\n\
	bl GetGenderFromSpeciesAndPersonality\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0xFF\n\
	bne _080438B6\n\
	bl _0804441E\n\
_080438B6:\n\
	mov r3, r8\n\
	ldrb r0, [r3]\n\
	adds r2, r0, 0\n\
	muls r2, r7\n\
	adds r2, r4\n\
	ldr r1, =gBitTable\n\
	ldrb r0, [r5]\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldr r1, [r0]\n\
	lsls r1, 16\n\
	ldr r0, [r2]\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_CuteCharmActivates\n\
	str r0, [r1]\n\
	bl _080443D0\n\
	.pool\n\
_08043908:\n\
	movs r5, 0\n\
	mov r10, r5\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r10, r0\n\
	bcc _08043918\n\
	bl _0804441E\n\
_08043918:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r2, r10\n\
	muls r2, r0\n\
	adds r0, r2, 0\n\
	adds r0, r1\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	subs r0, 0x7\n\
	adds r2, r1, 0\n\
	cmp r0, 0x41\n\
	bls _08043932\n\
	b _08043B96\n\
_08043932:\n\
	lsls r0, 2\n\
	ldr r1, =_08043948\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.pool\n\
	.align 2, 0\n\
_08043948:\n\
	.4byte _08043AAC\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B70\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043AD4\n\
	.4byte _08043B96\n\
	.4byte _08043A50\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043A7C\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B40\n\
	.4byte _08043B10\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043B96\n\
	.4byte _08043AD4\n\
_08043A50:\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x4C\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, =0x00000f88\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043A6A\n\
	b _08043B96\n\
_08043A6A:\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_PoisonJpn\n\
	b _08043B5C\n\
	.pool\n\
_08043A7C:\n\
	movs r0, 0x58\n\
	mov r1, r10\n\
	muls r1, r0\n\
	adds r0, r1, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x50\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043A96\n\
	b _08043B96\n\
_08043A96:\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_ConfusionJpn\n\
	bl StringCopy\n\
	movs r2, 0x2\n\
	mov r9, r2\n\
	b _08043B9C\n\
	.pool\n\
_08043AAC:\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x4C\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x40\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043B96\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_ParalysisJpn\n\
	b _08043B5C\n\
	.pool\n\
_08043AD4:\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r2, 0\n\
	adds r0, 0x4C\n\
	adds r0, r3, r0\n\
	ldr r0, [r0]\n\
	movs r1, 0x7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043B96\n\
	adds r2, 0x50\n\
	adds r2, r3, r2\n\
	ldr r0, [r2]\n\
	ldr r1, =0xf7ffffff\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_SleepJpn\n\
	bl StringCopy\n\
	movs r0, 0x1\n\
	mov r9, r0\n\
	b _08043B9C\n\
	.pool\n\
_08043B10:\n\
	movs r0, 0x58\n\
	mov r1, r10\n\
	muls r1, r0\n\
	adds r0, r1, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x4C\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043B96\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_BurnJpn\n\
	bl StringCopy\n\
	movs r2, 0x1\n\
	mov r9, r2\n\
	b _08043B9C\n\
	.pool\n\
_08043B40:\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x4C\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x20\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043B96\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_IceJpn\n\
_08043B5C:\n\
	bl StringCopy\n\
	movs r5, 0x1\n\
	mov r9, r5\n\
	b _08043B9C\n\
	.pool\n\
_08043B70:\n\
	movs r0, 0x58\n\
	mov r1, r10\n\
	muls r1, r0\n\
	adds r0, r1, 0\n\
	adds r1, r2, 0\n\
	adds r1, 0x50\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0xF0\n\
	lsls r1, 12\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08043B96\n\
	ldr r0, =gBattleTextBuff1\n\
	ldr r1, =gStatusConditionString_LoveJpn\n\
	bl StringCopy\n\
	movs r2, 0x3\n\
	mov r9, r2\n\
_08043B96:\n\
	mov r3, r9\n\
	cmp r3, 0\n\
	beq _08043C50\n\
_08043B9C:\n\
	mov r5, r9\n\
	cmp r5, 0x2\n\
	beq _08043BD0\n\
	cmp r5, 0x2\n\
	bgt _08043BB4\n\
	cmp r5, 0x1\n\
	beq _08043BBC\n\
	b _08043BFC\n\
	.pool\n\
_08043BB4:\n\
	mov r0, r9\n\
	cmp r0, 0x3\n\
	beq _08043BE8\n\
	b _08043BFC\n\
_08043BBC:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r2, r10\n\
	muls r2, r0\n\
	adds r1, 0x4C\n\
	adds r2, r1\n\
	movs r0, 0\n\
	b _08043BFA\n\
	.pool\n\
_08043BD0:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r2, r10\n\
	muls r2, r0\n\
	adds r1, 0x50\n\
	adds r2, r1\n\
	ldr r0, [r2]\n\
	movs r1, 0x8\n\
	negs r1, r1\n\
	b _08043BF8\n\
	.pool\n\
_08043BE8:\n\
	ldr r1, =gBattleMons\n\
	movs r0, 0x58\n\
	mov r2, r10\n\
	muls r2, r0\n\
	adds r1, 0x50\n\
	adds r2, r1\n\
	ldr r0, [r2]\n\
	ldr r1, =0xfff0ffff\n\
_08043BF8:\n\
	ands r0, r1\n\
_08043BFA:\n\
	str r0, [r2]\n\
_08043BFC:\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =gUnknown_082DB68C\n\
	str r0, [r1]\n\
	ldr r0, =gBattleScripting\n\
	mov r1, r10\n\
	strb r1, [r0, 0x17]\n\
	ldr r4, =gActiveBank\n\
	strb r1, [r4]\n\
	ldrb r1, [r4]\n\
	movs r0, 0x58\n\
	muls r0, r1\n\
	ldr r1, =gBattleMons + 0x4C\n\
	adds r0, r1\n\
	str r0, [sp]\n\
	movs r0, 0\n\
	movs r1, 0x28\n\
	movs r2, 0\n\
	movs r3, 0x4\n\
	bl EmitSetMonData\n\
	ldrb r0, [r4]\n\
	bl MarkBufferBankForExecution\n\
	bl _0804443A\n\
	.pool\n\
_08043C50:\n\
	mov r0, r10\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r10, r0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r10, r0\n\
	bcs _08043C64\n\
	b _08043918\n\
_08043C64:\n\
	bl _0804441E\n\
	.pool\n\
_08043C6C:\n\
	movs r2, 0\n\
	mov r10, r2\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r10, r0\n\
	bcc _08043C7A\n\
	b _0804441E\n\
_08043C7A:\n\
	ldr r4, =gBattleMons\n\
_08043C7C:\n\
	movs r0, 0x58\n\
	mov r3, r10\n\
	muls r3, r0\n\
	adds r0, r3, 0\n\
	adds r0, r4\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x3B\n\
	bne _08043CA0\n\
	mov r0, r10\n\
	bl CastformDataTypeChange\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	cmp r0, 0\n\
	beq _08043CA0\n\
	b _080442FC\n\
_08043CA0:\n\
	mov r0, r10\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r10, r0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r10, r0\n\
	bcc _08043C7C\n\
	b _0804441E\n\
	.pool\n\
_08043CBC:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0x1C\n\
	beq _08043CC4\n\
	b _0804441E\n\
_08043CC4:\n\
	ldr r4, =gHitMarker\n\
	ldr r1, [r4]\n\
	movs r0, 0x80\n\
	lsls r0, 7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043CD4\n\
	b _0804441E\n\
_08043CD4:\n\
	ldr r0, =0xffffbfff\n\
	ands r1, r0\n\
	str r1, [r4]\n\
	mov r5, r8\n\
	ldr r1, [r5]\n\
	adds r1, 0xB2\n\
	ldrb r2, [r1]\n\
	movs r0, 0x3F\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	ldr r0, [r5]\n\
	adds r1, r0, 0\n\
	adds r1, 0xB2\n\
	ldrb r0, [r1]\n\
	cmp r0, 0x6\n\
	bne _08043CF8\n\
	movs r0, 0x2\n\
	strb r0, [r1]\n\
_08043CF8:\n\
	ldr r1, =gBattleCommunication\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, 0xB2\n\
	ldrb r0, [r0]\n\
	adds r0, 0x40\n\
	strb r0, [r1, 0x3]\n\
	ldr r1, =gBattleScripting\n\
	ldr r0, =gBankTarget\n\
	ldrb r0, [r0]\n\
	strb r0, [r1, 0x17]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_SynchronizeActivates\n\
	str r0, [r1]\n\
	ldr r0, [r4]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r4]\n\
	b _080443D0\n\
	.pool\n\
_08043D40:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0x1C\n\
	beq _08043D48\n\
	b _0804441E\n\
_08043D48:\n\
	ldr r4, =gHitMarker\n\
	ldr r1, [r4]\n\
	movs r0, 0x80\n\
	lsls r0, 7\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _08043D58\n\
	b _0804441E\n\
_08043D58:\n\
	ldr r0, =0xffffbfff\n\
	ands r1, r0\n\
	str r1, [r4]\n\
	mov r3, r8\n\
	ldr r1, [r3]\n\
	adds r1, 0xB2\n\
	ldrb r2, [r1]\n\
	movs r0, 0x3F\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	ldr r0, [r3]\n\
	adds r1, r0, 0\n\
	adds r1, 0xB2\n\
	ldrb r0, [r1]\n\
	cmp r0, 0x6\n\
	bne _08043D7C\n\
	movs r0, 0x2\n\
	strb r0, [r1]\n\
_08043D7C:\n\
	ldr r1, =gBattleCommunication\n\
	mov r3, r8\n\
	ldr r0, [r3]\n\
	adds r0, 0xB2\n\
	ldrb r0, [r0]\n\
	strb r0, [r1, 0x3]\n\
	ldr r1, =gBattleScripting\n\
	ldr r0, =gBankAttacker\n\
	ldrb r0, [r0]\n\
	strb r0, [r1, 0x17]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =BattleScript_SynchronizeActivates\n\
	str r0, [r1]\n\
	ldr r0, [r4]\n\
	movs r1, 0x80\n\
	lsls r1, 6\n\
	orrs r0, r1\n\
	str r0, [r4]\n\
	b _080443D0\n\
	.pool\n\
_08043DC4:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r1, [r0]\n\
	cmp r4, r1\n\
	blt _08043DD0\n\
	b _0804441E\n\
_08043DD0:\n\
	ldr r0, =gBattleMons\n\
	adds r5, r1, 0\n\
	ldr r2, =gStatuses3\n\
	adds r3, r0, 0\n\
	adds r3, 0x20\n\
	movs r6, 0x80\n\
	lsls r6, 12\n\
_08043DDE:\n\
	ldrb r1, [r3]\n\
	cmp r1, 0x16\n\
	bne _08043DEE\n\
	ldr r0, [r2]\n\
	ands r0, r6\n\
	cmp r0, 0\n\
	beq _08043DEE\n\
	b _08044324\n\
_08043DEE:\n\
	adds r2, 0x4\n\
	adds r3, 0x58\n\
	adds r4, 0x1\n\
	cmp r4, r5\n\
	blt _08043DDE\n\
	b _0804441E\n\
	.pool\n\
_08043E08:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08043E14\n\
	b _0804441E\n\
_08043E14:\n\
	ldr r5, =gActiveBank\n\
	mov r8, r5\n\
	ldr r0, =gBattleMons\n\
	adds r0, 0x20\n\
	str r0, [sp, 0x1C]\n\
	movs r1, 0\n\
	str r1, [sp, 0x20]\n\
_08043E22:\n\
	ldr r2, [sp, 0x1C]\n\
	ldrb r0, [r2]\n\
	cmp r0, 0x24\n\
	beq _08043E2C\n\
	b _08043FBE\n\
_08043E2C:\n\
	ldr r0, =gStatuses3\n\
	ldr r3, [sp, 0x20]\n\
	adds r0, r3, r0\n\
	ldr r1, [r0]\n\
	movs r0, 0x80\n\
	lsls r0, 13\n\
	ands r1, r0\n\
	str r3, [sp, 0x18]\n\
	cmp r1, 0\n\
	bne _08043E42\n\
	b _08043FBE\n\
_08043E42:\n\
	lsls r0, r4, 24\n\
	lsrs r0, 24\n\
	bl GetBankIdentity\n\
	movs r1, 0x1\n\
	adds r5, r0, 0\n\
	eors r5, r1\n\
	ands r5, r1\n\
	adds r0, r5, 0\n\
	bl GetBankByIdentity\n\
	lsls r0, 24\n\
	lsrs r6, r0, 24\n\
	adds r0, r5, 0x2\n\
	bl GetBankByIdentity\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
	ldr r0, =gBattleTypeFlags\n\
	ldr r0, [r0]\n\
	movs r2, 0x1\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	bne _08043E74\n\
	b _08043F84\n\
_08043E74:\n\
	movs r1, 0x58\n\
	adds r0, r6, 0\n\
	muls r0, r1\n\
	ldr r3, =gBattleMons\n\
	adds r1, r0, r3\n\
	adds r0, r1, 0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _08043F40\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	beq _08043EFC\n\
	movs r1, 0x58\n\
	adds r0, r7, 0\n\
	muls r0, r1\n\
	adds r1, r0, r3\n\
	adds r0, r1, 0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _08043EFC\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	beq _08043EFC\n\
	str r2, [sp, 0x24]\n\
	bl Random\n\
	ldr r2, [sp, 0x24]\n\
	adds r1, r2, 0\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	orrs r5, r1\n\
	adds r0, r5, 0\n\
	bl GetBankByIdentity\n\
	mov r2, r8\n\
	strb r0, [r2]\n\
	ldrb r0, [r2]\n\
	movs r3, 0x58\n\
	muls r0, r3\n\
	ldr r5, =gBattleMons\n\
	adds r0, r5\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	ldr r1, [sp, 0x1C]\n\
	strb r0, [r1]\n\
	ldrb r0, [r2]\n\
	muls r0, r3\n\
	adds r0, r5\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	ldr r2, =gLastUsedAbility\n\
	strb r0, [r2]\n\
	b _08043FAC\n\
	.pool\n\
_08043EFC:\n\
	ldr r3, =gBattleMons\n\
	movs r2, 0x58\n\
	adds r0, r6, 0\n\
	muls r0, r2\n\
	adds r1, r0, r3\n\
	adds r0, r1, 0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _08043F40\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	beq _08043F40\n\
	mov r5, r8\n\
	strb r6, [r5]\n\
	adds r1, r4, 0\n\
	muls r1, r2\n\
	adds r1, r3\n\
	ldrb r0, [r5]\n\
	muls r0, r2\n\
	adds r0, r3\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	adds r1, 0x20\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	muls r0, r2\n\
	adds r0, r3\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	b _08043FA8\n\
	.pool\n\
_08043F40:\n\
	ldr r3, =gBattleMons\n\
	movs r2, 0x58\n\
	adds r0, r7, 0\n\
	muls r0, r2\n\
	adds r1, r0, r3\n\
	adds r0, r1, 0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _08043FB6\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	beq _08043FB6\n\
	mov r5, r8\n\
	strb r7, [r5]\n\
	adds r1, r4, 0\n\
	muls r1, r2\n\
	adds r1, r3\n\
	ldrb r0, [r5]\n\
	muls r0, r2\n\
	adds r0, r3\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	adds r1, 0x20\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	muls r0, r2\n\
	adds r0, r3\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	b _08043FA8\n\
	.pool\n\
_08043F84:\n\
	mov r2, r8\n\
	strb r6, [r2]\n\
	movs r3, 0x58\n\
	adds r0, r6, 0\n\
	muls r0, r3\n\
	ldr r5, =gBattleMons\n\
	adds r0, r5\n\
	adds r2, r0, 0\n\
	adds r2, 0x20\n\
	ldrb r1, [r2]\n\
	cmp r1, 0\n\
	beq _08043FB6\n\
	ldrh r0, [r0, 0x28]\n\
	cmp r0, 0\n\
	beq _08043FB6\n\
	ldr r0, [sp, 0x1C]\n\
	strb r1, [r0]\n\
	ldrb r0, [r2]\n\
_08043FA8:\n\
	ldr r1, =gLastUsedAbility\n\
	strb r0, [r1]\n\
_08043FAC:\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_08043FB6:\n\
	mov r2, r9\n\
	cmp r2, 0\n\
	beq _08043FBE\n\
	b _08044340\n\
_08043FBE:\n\
	ldr r3, [sp, 0x1C]\n\
	adds r3, 0x58\n\
	str r3, [sp, 0x1C]\n\
	ldr r5, [sp, 0x20]\n\
	adds r5, 0x4\n\
	str r5, [sp, 0x20]\n\
	adds r4, 0x1\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	bge _08043FD6\n\
	b _08043E22\n\
_08043FD6:\n\
	b _0804441E\n\
	.pool\n\
_08043FE4:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r1, [r0]\n\
	cmp r4, r1\n\
	blt _08043FF0\n\
	b _0804441E\n\
_08043FF0:\n\
	ldr r0, =gBattleMons\n\
	adds r5, r1, 0\n\
	ldr r2, =gStatuses3\n\
	adds r3, r0, 0\n\
	adds r3, 0x20\n\
	movs r6, 0x80\n\
	lsls r6, 12\n\
_08043FFE:\n\
	ldrb r1, [r3]\n\
	cmp r1, 0x16\n\
	bne _0804400E\n\
	ldr r0, [r2]\n\
	ands r0, r6\n\
	cmp r0, 0\n\
	beq _0804400E\n\
	b _080443B4\n\
_0804400E:\n\
	adds r2, 0x4\n\
	adds r3, 0x58\n\
	adds r4, 0x1\n\
	cmp r4, r5\n\
	blt _08043FFE\n\
	b _0804441E\n\
	.pool\n\
_08044028:\n\
	mov r0, r10\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _0804403E\n\
	b _0804441E\n\
_0804403E:\n\
	ldr r7, =gBattleMons\n\
_08044040:\n\
	lsls r0, r4, 24\n\
	lsrs r0, 24\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	adds r3, r4, 0x1\n\
	cmp r0, r5\n\
	beq _0804406A\n\
	movs r0, 0x58\n\
	muls r0, r4\n\
	adds r0, r7\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, r6\n\
	bne _0804406A\n\
	ldr r0, =gLastUsedAbility\n\
	strb r6, [r0]\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_0804406A:\n\
	adds r4, r3, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044040\n\
	b _0804441E\n\
	.pool\n\
_08044084:\n\
	mov r0, r10\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _0804409A\n\
	b _0804441E\n\
_0804409A:\n\
	ldr r7, =gBattleMons\n\
_0804409C:\n\
	lsls r0, r4, 24\n\
	lsrs r0, 24\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	adds r3, r4, 0x1\n\
	cmp r0, r5\n\
	bne _080440C6\n\
	movs r0, 0x58\n\
	muls r0, r4\n\
	adds r0, r7\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, r6\n\
	bne _080440C6\n\
	ldr r0, =gLastUsedAbility\n\
	strb r6, [r0]\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_080440C6:\n\
	adds r4, r3, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _0804409C\n\
	b _0804441E\n\
	.pool\n\
_080440E0:\n\
	ldrb r0, [r7]\n\
	cmp r0, 0xFD\n\
	beq _08044104\n\
	cmp r0, 0xFE\n\
	beq _0804413C\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	adds r5, r0, 0\n\
	ldrb r0, [r5]\n\
	cmp r4, r0\n\
	blt _080440F8\n\
	b _0804441E\n\
_080440F8:\n\
	ldr r2, =gBattleMons\n\
	b _08044174\n\
	.pool\n\
_08044104:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044110\n\
	b _0804441E\n\
_08044110:\n\
	ldr r5, =gStatuses3\n\
	movs r2, 0x80\n\
	lsls r2, 9\n\
	adds r1, r0, 0\n\
_08044118:\n\
	lsls r0, r4, 2\n\
	adds r0, r5\n\
	ldr r0, [r0]\n\
	ands r0, r2\n\
	adds r3, r4, 0x1\n\
	cmp r0, 0\n\
	beq _0804412C\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_0804412C:\n\
	adds r4, r3, 0\n\
	cmp r4, r1\n\
	blt _08044118\n\
	b _0804441E\n\
	.pool\n\
_0804413C:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044148\n\
	b _0804441E\n\
_08044148:\n\
	ldr r5, =gStatuses3\n\
	movs r2, 0x80\n\
	lsls r2, 10\n\
	adds r1, r0, 0\n\
_08044150:\n\
	lsls r0, r4, 2\n\
	adds r0, r5\n\
	ldr r0, [r0]\n\
	ands r0, r2\n\
	adds r3, r4, 0x1\n\
	cmp r0, 0\n\
	beq _08044164\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_08044164:\n\
	adds r4, r3, 0\n\
	cmp r4, r1\n\
	blt _08044150\n\
	b _0804441E\n\
	.pool\n\
_08044174:\n\
	movs r0, 0x58\n\
	muls r0, r4\n\
	adds r0, r2\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	adds r3, r4, 0x1\n\
	cmp r0, r6\n\
	bne _0804418C\n\
	strb r6, [r7]\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_0804418C:\n\
	adds r4, r3, 0\n\
	ldrb r1, [r5]\n\
	cmp r4, r1\n\
	blt _08044174\n\
	b _0804441E\n\
_08044196:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _080441A2\n\
	b _0804441E\n\
_080441A2:\n\
	ldr r2, =gBattleMons\n\
	mov r8, r2\n\
	adds r2, r0, 0\n\
	movs r5, 0x58\n\
_080441AA:\n\
	adds r0, r4, 0\n\
	muls r0, r5\n\
	mov r3, r8\n\
	adds r1, r0, r3\n\
	adds r0, r1, 0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	adds r3, r4, 0x1\n\
	cmp r0, r6\n\
	bne _080441CC\n\
	ldrh r0, [r1, 0x28]\n\
	cmp r0, 0\n\
	beq _080441CC\n\
	strb r6, [r7]\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_080441CC:\n\
	adds r4, r3, 0\n\
	cmp r4, r2\n\
	blt _080441AA\n\
	b _0804441E\n\
	.pool\n\
_080441DC:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _080441E8\n\
	b _0804441E\n\
_080441E8:\n\
	ldr r7, =gBattleMons\n\
	adds r1, r0, 0\n\
	movs r5, 0x58\n\
	ldr r2, =gLastUsedAbility\n\
_080441F0:\n\
	adds r0, r4, 0\n\
	muls r0, r5\n\
	adds r0, r7\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	adds r3, r4, 0x1\n\
	cmp r0, r6\n\
	bne _0804420C\n\
	cmp r4, r10\n\
	beq _0804420C\n\
	strb r6, [r2]\n\
	lsls r0, r3, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_0804420C:\n\
	adds r4, r3, 0\n\
	cmp r4, r1\n\
	blt _080441F0\n\
	b _0804441E\n\
	.pool\n\
_08044220:\n\
	mov r0, r10\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044236\n\
	b _0804441E\n\
_08044236:\n\
	ldr r7, =gBattleMons\n\
_08044238:\n\
	lsls r0, r4, 24\n\
	lsrs r0, 24\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, r5\n\
	beq _08044264\n\
	movs r0, 0x58\n\
	muls r0, r4\n\
	adds r0, r7\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, r6\n\
	bne _08044264\n\
	ldr r0, =gLastUsedAbility\n\
	strb r6, [r0]\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_08044264:\n\
	adds r4, 0x1\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044238\n\
	b _0804441E\n\
	.pool\n\
_0804427C:\n\
	mov r0, r10\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044292\n\
	b _0804441E\n\
_08044292:\n\
	ldr r7, =gBattleMons\n\
_08044294:\n\
	lsls r0, r4, 24\n\
	lsrs r0, 24\n\
	bl GetBankSide\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, r5\n\
	bne _080442C0\n\
	movs r0, 0x58\n\
	muls r0, r4\n\
	adds r0, r7\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, r6\n\
	bne _080442C0\n\
	ldr r0, =gLastUsedAbility\n\
	strb r6, [r0]\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_080442C0:\n\
	adds r4, 0x1\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _08044294\n\
	b _0804441E\n\
	.pool\n\
_080442D8:\n\
	ldr r0, =BattleScript_CastformChange\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	strb r6, [r0, 0x17]\n\
_080442E2:\n\
	ldr r0, =gBattleStruct\n\
	ldr r0, [r0]\n\
	adds r0, 0x7F\n\
	mov r1, r9\n\
	subs r1, 0x1\n\
	strb r1, [r0]\n\
	b _0804441E\n\
	.pool\n\
_080442FC:\n\
	ldr r0, =BattleScript_CastformChange\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r0, =gBattleScripting\n\
	mov r5, r10\n\
	strb r5, [r0, 0x17]\n\
	ldr r0, =gBattleStruct\n\
	ldr r0, [r0]\n\
	adds r0, 0x7F\n\
	mov r1, r9\n\
	subs r1, 0x1\n\
	strb r1, [r0]\n\
	b _0804443A\n\
	.pool\n\
_08044324:\n\
	strb r1, [r7]\n\
	ldr r0, [r2]\n\
	ldr r1, =0xfff7ffff\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	ldr r0, =gUnknown_082DB4B8\n\
	bl BattleScriptPushCursorAndCallback\n\
	b _080443C8\n\
	.pool\n\
_08044340:\n\
	ldr r0, =BattleScript_TraceActivates\n\
	bl BattleScriptPushCursorAndCallback\n\
	ldr r1, =gStatuses3\n\
	ldr r0, [sp, 0x18]\n\
	adds r1, r0, r1\n\
	ldr r0, [r1]\n\
	ldr r2, =0xffefffff\n\
	ands r0, r2\n\
	str r0, [r1]\n\
	ldr r0, =gBattleScripting\n\
	strb r4, [r0, 0x17]\n\
	ldr r1, =gBattleTextBuff1\n\
	movs r4, 0xFD\n\
	strb r4, [r1]\n\
	movs r0, 0x4\n\
	strb r0, [r1, 0x1]\n\
	ldr r2, =gActiveBank\n\
	ldrb r0, [r2]\n\
	strb r0, [r1, 0x2]\n\
	ldr r3, =gBattlePartyID\n\
	ldrb r0, [r2]\n\
	lsls r0, 1\n\
	adds r0, r3\n\
	ldrh r0, [r0]\n\
	strb r0, [r1, 0x3]\n\
	movs r0, 0xFF\n\
	strb r0, [r1, 0x4]\n\
	ldr r1, =gBattleTextBuff2\n\
	strb r4, [r1]\n\
	movs r0, 0x9\n\
	strb r0, [r1, 0x1]\n\
	ldr r0, =gLastUsedAbility\n\
	ldrb r0, [r0]\n\
	strb r0, [r1, 0x2]\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	strb r0, [r1, 0x3]\n\
	b _0804441E\n\
	.pool\n\
_080443B4:\n\
	strb r1, [r7]\n\
	ldr r0, [r2]\n\
	ldr r1, =0xfff7ffff\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	bl BattleScriptPushCursor\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, =gUnknown_082DB4C1\n\
	str r0, [r1]\n\
_080443C8:\n\
	ldr r0, =gBattleStruct\n\
	ldr r0, [r0]\n\
	adds r0, 0xD8\n\
	strb r4, [r0]\n\
_080443D0:\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	b _0804441E\n\
	.pool\n\
_080443EC:\n\
	movs r4, 0\n\
	ldr r0, =gNoOfAllBanks\n\
	ldrb r1, [r0]\n\
	cmp r4, r1\n\
	bge _0804441E\n\
	ldr r0, =gBattleMons\n\
	adds r2, r1, 0\n\
	adds r1, r0, 0\n\
	adds r1, 0x20\n\
	ldr r3, =gLastUsedAbility\n\
_08044400:\n\
	ldrb r0, [r1]\n\
	cmp r0, r6\n\
	bne _08044416\n\
	cmp r4, r10\n\
	beq _08044416\n\
	strb r6, [r3]\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
_08044416:\n\
	adds r1, 0x58\n\
	adds r4, 0x1\n\
	cmp r4, r2\n\
	blt _08044400\n\
_0804441E:\n\
	mov r1, r9\n\
	cmp r1, 0\n\
	beq _0804443A\n\
_08044424:\n\
	ldr r2, [sp, 0x4]\n\
	cmp r2, 0xB\n\
	bhi _0804443A\n\
	ldr r1, =gLastUsedAbility\n\
	ldrb r0, [r1]\n\
	cmp r0, 0xFF\n\
	beq _0804443A\n\
	adds r1, r0, 0\n\
	mov r0, r10\n\
	bl RecordAbilityBattle\n\
_0804443A:\n\
	mov r0, r9\n\
	add sp, 0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
	.pool\n\
	.syntax divided");
}
#endif // NONMATCHING

void BattleScriptExecute(const u8* BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    BATTLE_CALLBACKS_STACK->function[BATTLE_CALLBACKS_STACK->size++] = gBattleMainFunc;
    gBattleMainFunc = bc_move_exec_returning;
    gFightStateTracker = 0;
}

void BattleScriptPushCursorAndCallback(const u8* BS_ptr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BS_ptr;
    BATTLE_CALLBACKS_STACK->function[BATTLE_CALLBACKS_STACK->size++] = gBattleMainFunc;
    gBattleMainFunc = sub_803E08C;
}

enum
{
    ITEM_NO_EFFECT, // 0
    ITEM_STATUS_CHANGE, // 1
    ITEM_EFFECT_OTHER, // 2
    ITEM_PP_CHANGE, // 3
    ITEM_HP_CHANGE, // 4
    ITEM_STATS_CHANGE, // 5
};

enum
{
    FLAVOR_SPICY, // 0
    FLAVOR_DRY, // 1
    FLAVOR_SWEET, // 2
    FLAVOR_BITTER, // 3
    FLAVOR_SOUR, // 4
};

u8 ItemBattleEffects(u8 caseID, u8 bank, bool8 moveTurn)
{
    int i = 0;
    u8 effect = ITEM_NO_EFFECT;
    u8 changedPP = 0;
    u8 bankHoldEffect, atkHoldEffect, defHoldEffect;
    u8 bankQuality, atkQuality, defQuality;
    u16 atkItem, defItem;

    gLastUsedItem = gBattleMons[bank].item;
    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
    {
        bankHoldEffect = gEnigmaBerries[bank].holdEffect;
        bankQuality = gEnigmaBerries[bank].holdEffectParam;
    }
    else
    {
        bankHoldEffect = ItemId_GetHoldEffect(gLastUsedItem);
        bankQuality = ItemId_GetHoldEffectParam(gLastUsedItem);
    }

    atkItem = gBattleMons[gBankAttacker].item;
    if (atkItem == ITEM_ENIGMA_BERRY)
    {
        atkHoldEffect = gEnigmaBerries[gBankAttacker].holdEffect;
        atkQuality = gEnigmaBerries[gBankAttacker].holdEffectParam;
    }
    else
    {
        atkHoldEffect = ItemId_GetHoldEffect(atkItem);
        atkQuality = ItemId_GetHoldEffectParam(atkItem);
    }

    // def variables are unused
    defItem = gBattleMons[gBankTarget].item;
    if (defItem == ITEM_ENIGMA_BERRY)
    {
        defHoldEffect = gEnigmaBerries[gBankTarget].holdEffect;
        defQuality = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        defHoldEffect = ItemId_GetHoldEffect(defItem);
        defQuality = ItemId_GetHoldEffectParam(defItem);
    }

    switch (caseID)
    {
    case 0:
        switch (bankHoldEffect)
        {
        case HOLD_EFFECT_DOUBLE_PRIZE:
            if (GetBankSide(bank) == SIDE_PLAYER)
                gBattleStruct->moneyMultiplier = 2;
            break;
        case HOLD_EFFECT_RESTORE_STATS:
            for (i = 0; i < 8; i++)
            {
                if (gBattleMons[bank].statStages[i] < 6)
                {
                    gBattleMons[bank].statStages[i] = 6;
                    effect = ITEM_STATS_CHANGE;
                }
            }
            if (effect)
            {
                gBattleScripting.bank = bank;
                gStringBank = bank;
                gActiveBank = gBankAttacker = bank;
                BattleScriptExecute(BattleScript_WhiteHerbEnd2);
            }
            break;
        }
        break;
    case 1:
        if (gBattleMons[bank].hp)
        {
            switch (bankHoldEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleMoveDamage = bankQuality;
                    if (gBattleMons[bank].hp + bankQuality > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = 4;
                }
                break;
            case HOLD_EFFECT_RESTORE_PP:
                if (!moveTurn)
                {
                    struct Pokemon* poke;
                    u8 ppBonuses;
                    u16 move;

                    if (GetBankSide(bank) == SIDE_PLAYER)
                        poke = &gPlayerParty[gBattlePartyID[bank]];
                    else
                        poke = &gEnemyParty[gBattlePartyID[bank]];
                    for (i = 0; i < 4; i++)
                    {
                        move = GetMonData(poke, MON_DATA_MOVE1 + i);
                        changedPP = GetMonData(poke, MON_DATA_PP1 + i);
                        ppBonuses = GetMonData(poke, MON_DATA_PP_BONUSES);
                        if (move && changedPP == 0)
                            break;
                    }
                    if (i != 4)
                    {
                        u8 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
                        if (changedPP + bankQuality > maxPP)
                            changedPP = maxPP;
                        else
                            changedPP = changedPP + bankQuality;
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = move;
                        gBattleTextBuff1[3] = move >> 8;
                        gBattleTextBuff1[4] = 0xFF;
                        BattleScriptExecute(BattleScript_BerryPPHealEnd2);
                        EmitSetMonData(0, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
                        MarkBufferBankForExecution(gActiveBank);
                        effect = ITEM_PP_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < 8; i++)
                {
                    if (gBattleMons[bank].statStages[i] < 6)
                    {
                        gBattleMons[bank].statStages[i] = 6;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.bank = bank;
                    gStringBank = bank;
                    gActiveBank = gBankAttacker = bank;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_LEFTOVERS:
                if (gBattleMons[bank].hp < gBattleMons[bank].maxHP && !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[bank].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_End2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(bank, bankHoldEffect);
                }
                break;
            // nice copy/paste there gamefreak, making a function for confuse berries was too much eh?
            case HOLD_EFFECT_CONFUSE_SPICY:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 8;
                    gBattleTextBuff1[2] = FLAVOR_SPICY;
                    gBattleTextBuff1[3] = EOS;
                    gBattleMoveDamage = gBattleMons[bank].maxHP / bankQuality;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    if (GetFlavourRelationByPersonality(gBattleMons[bank].personality, FLAVOR_SPICY) < 0)
                        BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
                    else
                        BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 8;
                    gBattleTextBuff1[2] = FLAVOR_DRY;
                    gBattleTextBuff1[3] = EOS;
                    gBattleMoveDamage = gBattleMons[bank].maxHP / bankQuality;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    if (GetFlavourRelationByPersonality(gBattleMons[bank].personality, FLAVOR_DRY) < 0)
                        BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
                    else
                        BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 8;
                    gBattleTextBuff1[2] = FLAVOR_SWEET;
                    gBattleTextBuff1[3] = EOS;
                    gBattleMoveDamage = gBattleMons[bank].maxHP / bankQuality;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    if (GetFlavourRelationByPersonality(gBattleMons[bank].personality, FLAVOR_SWEET) < 0)
                        BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
                    else
                        BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 8;
                    gBattleTextBuff1[2] = FLAVOR_BITTER;
                    gBattleTextBuff1[3] = EOS;
                    gBattleMoveDamage = gBattleMons[bank].maxHP / bankQuality;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    if (GetFlavourRelationByPersonality(gBattleMons[bank].personality, FLAVOR_BITTER) < 0)
                        BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
                    else
                        BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / 2 && !moveTurn)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 8;
                    gBattleTextBuff1[2] = FLAVOR_SOUR;
                    gBattleTextBuff1[3] = EOS;
                    gBattleMoveDamage = gBattleMons[bank].maxHP / bankQuality;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[bank].hp + gBattleMoveDamage > gBattleMons[bank].maxHP)
                        gBattleMoveDamage = gBattleMons[bank].maxHP - gBattleMons[bank].hp;
                    gBattleMoveDamage *= -1;
                    if (GetFlavourRelationByPersonality(gBattleMons[bank].personality, FLAVOR_SOUR) < 0)
                        BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);
                    else
                        BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            // copy/paste again, smh
            case HOLD_EFFECT_ATTACK_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && gBattleMons[bank].statStages[STAT_STAGE_ATK] < 0xC)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 5;
                    gBattleTextBuff1[2] = STAT_STAGE_ATK;
                    gBattleTextBuff1[3] = EOS;

                    gBattleTextBuff2[0] = 0xFD;
                    gBattleTextBuff2[1] = 0;
                    gBattleTextBuff2[2] = 0xD2;
                    gBattleTextBuff2[3] = 0xD2 >> 8;
                    gBattleTextBuff2[4] = EOS;

                    gEffectBank = bank;
                    gBattleScripting.statChanger = 0x10 + STAT_STAGE_ATK;
                    gBattleScripting.animArg1 = 0xE + STAT_STAGE_ATK;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && gBattleMons[bank].statStages[STAT_STAGE_DEF] < 0xC)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 5;
                    gBattleTextBuff1[2] = STAT_STAGE_DEF;
                    gBattleTextBuff1[3] = EOS;

                    gEffectBank = bank;
                    gBattleScripting.statChanger = 0x10 + STAT_STAGE_DEF;
                    gBattleScripting.animArg1 = 0xE + STAT_STAGE_DEF;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SPEED_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && gBattleMons[bank].statStages[STAT_STAGE_SPEED] < 0xC)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 5;
                    gBattleTextBuff1[2] = STAT_STAGE_SPEED;
                    gBattleTextBuff1[3] = EOS;

                    gEffectBank = bank;
                    gBattleScripting.statChanger = 0x10 + STAT_STAGE_SPEED;
                    gBattleScripting.animArg1 = 0xE + STAT_STAGE_SPEED;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && gBattleMons[bank].statStages[STAT_STAGE_SPATK] < 0xC)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 5;
                    gBattleTextBuff1[2] = STAT_STAGE_SPATK;
                    gBattleTextBuff1[3] = EOS;

                    gEffectBank = bank;
                    gBattleScripting.statChanger = 0x10 + STAT_STAGE_SPATK;
                    gBattleScripting.animArg1 = 0xE + STAT_STAGE_SPATK;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && gBattleMons[bank].statStages[STAT_STAGE_SPDEF] < 0xC)
                {
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 5;
                    gBattleTextBuff1[2] = STAT_STAGE_SPDEF;
                    gBattleTextBuff1[3] = EOS;

                    gEffectBank = bank;
                    gBattleScripting.statChanger = 0x10 + STAT_STAGE_SPDEF;
                    gBattleScripting.animArg1 = 0xE + STAT_STAGE_SPDEF;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality && !moveTurn && !(gBattleMons[bank].status2 & STATUS2_FOCUS_ENERGY))
                {
                    gBattleMons[bank].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (!moveTurn && gBattleMons[bank].hp <= gBattleMons[bank].maxHP / bankQuality)
                {
                    for (i = 0; i < 5; i++)
                    {
                        if (gBattleMons[bank].statStages[STAT_STAGE_ATK + i] < 0xC)
                            break;
                    }
                    if (i != 5)
                    {
                        do
                        {
                            i = Random() % 5;
                        } while (gBattleMons[bank].statStages[STAT_STAGE_ATK + i] == 0xC);

                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 5;
                        gBattleTextBuff1[2] = i + 1;
                        gBattleTextBuff1[3] = EOS;

                        gBattleTextBuff2[0] = 0xFD;
                        gBattleTextBuff2[1] = 0;
                        gBattleTextBuff2[2] = 0xD1;
                        gBattleTextBuff2[3] = 0xD1 >> 8;
                        gBattleTextBuff2[4] = 0;
                        gBattleTextBuff2[5] = 0xD2;
                        gBattleTextBuff2[6] = 0xD2 >> 8;
                        gBattleTextBuff2[7] = EOS;

                        gEffectBank = bank;
                        gBattleScripting.statChanger = 0x21 + i;
                        gBattleScripting.animArg1 = 0x21 + i + 6;
                        gBattleScripting.animArg2 = 0;
                        BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[bank].status1 & STATUS_PARALYSIS)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_PARALYSIS);
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[bank].status1 & STATUS_PSN_ANY)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_PSN_ANY | STATUS_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[bank].status1 & STATUS_BURN)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_BURN);
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[bank].status1 & STATUS_FREEZE)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_FREEZE);
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[bank].status1 & STATUS_SLEEP)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_SLEEP);
                    gBattleMons[bank].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[bank].status2 & STATUS2_CONFUSION)
                {
                    gBattleMons[bank].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureConfusionEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (gBattleMons[bank].status1 & STATUS_ANY || gBattleMons[bank].status2 & STATUS2_CONFUSION)
                {
                    i = 0;
                    if (gBattleMons[bank].status1 & STATUS_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[bank].status1 & STATUS_SLEEP)
                    {
                        gBattleMons[bank].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[bank].status1 & STATUS_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[bank].status1 & STATUS_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[bank].status1 & STATUS_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[bank].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (!(i > 1))
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gBattleMons[bank].status1 = 0;
                    gBattleMons[bank].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_ATTRACT:
                if (gBattleMons[bank].status2 & STATUS2_INFATUATION)
                {
                    gBattleMons[bank].status2 &= ~(STATUS2_INFATUATION);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            }
            if (effect)
            {
                gBattleScripting.bank = bank;
                gStringBank = bank;
                gActiveBank = gBankAttacker = bank;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[bank].status1);
                    MarkBufferBankForExecution(gActiveBank);
                    break;
                case ITEM_PP_CHANGE:
                    if (!(gBattleMons[bank].status2 & STATUS2_TRANSFORMED) && !(gDisableStructs[bank].unk18_b & gBitTable[i]))
                        gBattleMons[bank].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case 2:
        break;
    case 3:
        for (bank = 0; bank < gNoOfAllBanks; bank++)
        {
            gLastUsedItem = gBattleMons[bank].item;
            if (gBattleMons[bank].item == ITEM_ENIGMA_BERRY)
            {
                bankHoldEffect = gEnigmaBerries[bank].holdEffect;
                bankQuality = gEnigmaBerries[bank].holdEffectParam;
            }
            else
            {
                bankHoldEffect = ItemId_GetHoldEffect(gLastUsedItem);
                bankQuality = ItemId_GetHoldEffectParam(gLastUsedItem);
            }
            switch (bankHoldEffect)
            {
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[bank].status1 & STATUS_PARALYSIS)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_PARALYSIS);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureParRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[bank].status1 & STATUS_PSN_ANY)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_PSN_ANY | STATUS_TOXIC_COUNTER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCurePsnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[bank].status1 & STATUS_BURN)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_BURN);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureBrnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[bank].status1 & STATUS_FREEZE)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_FREEZE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[bank].status1 & STATUS_SLEEP)
                {
                    gBattleMons[bank].status1 &= ~(STATUS_SLEEP);
                    gBattleMons[bank].status2 &= ~(STATUS2_NIGHTMARE);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureSlpRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[bank].status2 & STATUS2_CONFUSION)
                {
                    gBattleMons[bank].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureConfusionRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_ATTRACT:
                if (gBattleMons[bank].status2 & STATUS2_INFATUATION)
                {
                    gBattleMons[bank].status2 &= ~(STATUS2_INFATUATION);
                    StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (gBattleMons[bank].status1 & STATUS_ANY || gBattleMons[bank].status2 & STATUS2_CONFUSION)
                {
                    if (gBattleMons[bank].status1 & STATUS_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                    }
                    if (gBattleMons[bank].status1 & STATUS_SLEEP)
                    {
                        gBattleMons[bank].status2 &= ~(STATUS2_NIGHTMARE);
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    }
                    if (gBattleMons[bank].status1 & STATUS_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                    }
                    if (gBattleMons[bank].status1 & STATUS_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                    }
                    if (gBattleMons[bank].status1 & STATUS_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                    }
                    if (gBattleMons[bank].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                    }
                    gBattleMons[bank].status1 = 0;
                    gBattleMons[bank].status2 &= ~(STATUS2_CONFUSION);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < 8; i++)
                {
                    if (gBattleMons[bank].statStages[i] < 6)
                    {
                        gBattleMons[bank].statStages[i] = 6;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect)
                {
                    gBattleScripting.bank = bank;
                    gStringBank = bank;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WhiteHerbRet;
                    return effect; // unnecessary return
                }
                break;
            }
            if (effect)
            {
                gBattleScripting.bank = bank;
                gStringBank = bank;
                gActiveBank = bank;
                EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                MarkBufferBankForExecution(gActiveBank);
                break;
            }
        }
        break;
    case 4:
        if (gBattleMoveDamage)
        {
            switch (atkHoldEffect)
            {
            case HOLD_EFFECT_FLINCH:
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                    && (gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)
                    && (Random() % 100) < atkQuality
                    && gBattleMoves[gCurrentMove].flags & FLAG_KINGSROCK_AFFECTED
                    && gBattleMons[gBankTarget].hp)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = 8;
                    BattleScriptPushCursor();
                    SetMoveEffect(0, 0);
                    BattleScriptPop();
                }
                break;
            case HOLD_EFFECT_SHELL_BELL:
                if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT)
                    && gSpecialStatuses[gBankTarget].moveturnLostHP != 0
                    && gSpecialStatuses[gBankTarget].moveturnLostHP != 0xFFFF
                    && gBankAttacker != gBankTarget
                    && gBattleMons[gBankAttacker].hp != gBattleMons[gBankAttacker].maxHP
                    && gBattleMons[gBankAttacker].hp != 0)
                {
                    gLastUsedItem = atkItem;
                    gStringBank = gBankAttacker;
                    gBattleScripting.bank = gBankAttacker;
                    gBattleMoveDamage = (gSpecialStatuses[gBankTarget].moveturnLostHP / atkQuality) * -1;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = -1;
                    gSpecialStatuses[gBankTarget].moveturnLostHP = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ItemHealHP_Ret;
                    effect++;
                }
                break;
            }
        }
        break;
    }

    return effect;
}

void sub_8045868(u8 bank)
{
    gDisableStructs[bank].furyCutterCounter = 0;
    gBattleMons[bank].status2 &= ~(STATUS2_DESTINY_BOND);
    gStatuses3[bank] &= ~(STATUS3_GRUDGE);
}

void sub_80458B4(void)
{
    if (gBattleExecBuffer == 0)
        gBattleScriptingCommandsTable[*gBattlescriptCurrInstr]();
}

u8 GetMoveTarget(u16 move, u8 useMoveTarget)
{
    u8 targetBank = 0;
    u8 moveTarget;
    u8 side;

    if (useMoveTarget)
        moveTarget = useMoveTarget - 1;
    else
        moveTarget = gBattleMoves[move].target;

    switch (moveTarget)
    {
    case MOVE_TARGET_SELECTED:
        side = GetBankSide(gBankAttacker) ^ 1;
        if (gSideTimers[side].followmeTimer && gBattleMons[gSideTimers[side].followmeTarget].hp)
            targetBank = gSideTimers[side].followmeTarget;
        else
        {
            side = GetBankSide(gBankAttacker);
            do
            {
                targetBank = Random() % gNoOfAllBanks;
            } while (targetBank == gBankAttacker || side == GetBankSide(targetBank) || gAbsentBankFlags & gBitTable[targetBank]);
            if (gBattleMoves[move].type == TYPE_ELECTRIC
                && AbilityBattleEffects(ABILITYEFFECT_COUNT_OTHER_SIDE, gBankAttacker, ABILITY_LIGHTNING_ROD, 0, 0)
                && gBattleMons[targetBank].ability != ABILITY_LIGHTNING_ROD)
            {
                targetBank ^= 2;
                RecordAbilityBattle(targetBank, gBattleMons[targetBank].ability);
                gSpecialStatuses[targetBank].lightningRodRedirected = 1;
            }
        }
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    case MOVE_TARGET_OPPONENTS_FIELD:
        targetBank = GetBankByIdentity((GetBankIdentity(gBankAttacker) & 1) ^ 1);
        if (gAbsentBankFlags & gBitTable[targetBank])
            targetBank ^= 2;
        break;
    case MOVE_TARGET_RANDOM:
        side = GetBankSide(gBankAttacker) ^ 1;
        if (gSideTimers[side].followmeTimer && gBattleMons[gSideTimers[side].followmeTarget].hp)
            targetBank = gSideTimers[side].followmeTarget;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && moveTarget & MOVE_TARGET_RANDOM)
        {
            if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
            {
                if (Random() & 1)
                    targetBank = GetBankByIdentity(1);
                else
                    targetBank = GetBankByIdentity(3);
            }
            else
            {
                if (Random() & 1)
                    targetBank = GetBankByIdentity(0);
                else
                    targetBank = GetBankByIdentity(2);
            }
            if (gAbsentBankFlags & gBitTable[targetBank])
                targetBank ^= 2;
        }
        else
            targetBank = GetBankByIdentity((GetBankIdentity(gBankAttacker) & 1) ^ 1);
        break;
    case MOVE_TARGET_USER:
    case MOVE_TARGET_x10:
        targetBank = gBankAttacker;
        break;
    }

    #ifndef NONMATCHING
        MEME_ACCESS_U8(BattleStruct, gBattleStruct, gBankAttacker, moveTarget, targetBank);
    #else
        gBattleStruct->moveTarget[gBankAttacker] = targetBank;
    #endif // NONMATCHING

    return targetBank;
}

static bool32 HasObedientBitSet(u8 bank)
{
    if (GetBankSide(bank) == SIDE_OPPONENT)
        return TRUE;
    if (GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS
        && GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_SPECIES, NULL) != SPECIES_MEW)
            return TRUE;
    return GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_OBEDIENCE, NULL);
}

u8 IsPokeDisobedient(void)
{
    s32 rnd;
    s32 calc;
    u8 obedienceLevel = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return 0;
    if (GetBankSide(gBankAttacker) == SIDE_OPPONENT)
        return 0;

    if (HasObedientBitSet(gBankAttacker)) // only if species is Mew or Deoxys
    {
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBankIdentity(gBankAttacker) == 2)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            return 0;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return 0;
        if (!IsOtherTrainer(gBattleMons[gBankAttacker].otId, gBattleMons[gBankAttacker].otName))
            return 0;
        if (FlagGet(BADGE08_GET))
            return 0;

        obedienceLevel = 10;

        if (FlagGet(BADGE02_GET))
            obedienceLevel = 30;
        if (FlagGet(BADGE04_GET))
            obedienceLevel = 50;
        if (FlagGet(BADGE06_GET))
            obedienceLevel = 70;
    }

    if (gBattleMons[gBankAttacker].level <= obedienceLevel)
        return 0;
    rnd = (Random() & 255);
    calc = (gBattleMons[gBankAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
        return 0;

    // is not obedient
    if (gCurrentMove == MOVE_RAGE)
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_RAGE);
    if (gBattleMons[gBankAttacker].status1 & STATUS_SLEEP && (gCurrentMove == MOVE_SNORE || gCurrentMove == MOVE_SLEEP_TALK))
    {
        gBattlescriptCurrInstr = gUnknown_082DB695;
        return 1;
    }

    rnd = (Random() & 255);
    calc = (gBattleMons[gBankAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
    {
        calc = CheckMoveLimitations(gBankAttacker, gBitTable[gCurrMovePos], 0xFF);
        if (calc == 0xF) // all moves cannot be used
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & 3;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
        else // use a random move
        {
            do
            {
                gCurrMovePos = gUnknown_020241E9 = Random() & 3;
            } while (gBitTable[gCurrMovePos] & calc);

            gRandomMove = gBattleMons[gBankAttacker].moves[gCurrMovePos];
            gBattlescriptCurrInstr = gUnknown_082DB6A5;
            gBankTarget = GetMoveTarget(gRandomMove, 0);
            gHitMarker |= HITMARKER_x200000;
            return 2;
        }
    }
    else
    {
        obedienceLevel = gBattleMons[gBankAttacker].level - obedienceLevel;

        calc = (Random() & 255);
        if (calc < obedienceLevel && !(gBattleMons[gBankAttacker].status1 & STATUS_ANY) && gBattleMons[gBankAttacker].ability != ABILITY_VITAL_SPIRIT && gBattleMons[gBankAttacker].ability != ABILITY_INSOMNIA)
        {
            // try putting asleep
            int i;
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gBattleMons[i].status2 & STATUS2_UPROAR)
                    break;
            }
            if (i == gNoOfAllBanks)
            {
                gBattlescriptCurrInstr = gUnknown_082DB6D9;
                return 1;
            }
        }
        calc -= obedienceLevel;
        if (calc < obedienceLevel)
        {
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankAttacker], MOVE_POUND, 0, 40, 0, gBankAttacker, gBankAttacker);
            gBankTarget = gBankAttacker;
            gBattlescriptCurrInstr = gUnknown_082DB6F0;
            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
            return 2;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = Random() & 3;
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return 1;
        }
    }
}
