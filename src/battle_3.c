#include "global.h"
#include "abilities.h"
#include "battle.h"
#include "moves.h"
//#include "item.h"
#include "items.h"
#include "hold_effects.h"
#include "species.h"
#include "pokemon.h"
//#include "data2.h"
#include "rng.h"
#include "text.h"
//#include "battle_move_effects.h"
#include "string_util.h"
//#include "flags.h"

struct ChoicedMoveSomething
{
    /*0x00*/ u8 turnEffectsTracker;
    /*0x01*/ u8 turnEffectsBank;
    u8 filler2[1];
    /*0x03*/ u8 turncountersTracker;
    /*0x04*/ u8 unk4[8];
    /*0x0C*/ u8 fillerC[0x4D-0xC];
            
            u8 unk4D;
            u8 unk4E;
            u8 filler4F[0xC8-0x4F];
    
    /*0xC8*/ u16 unkC8[4];
    u8 fillerD0[0xA];
    /*0xDA*/ u8 unkDA;
    /*0xDB*/ u8 turnSideTracker;
    u8 fillerDC[0xDF-0xDC];
    u8 unkDF;
    u8 fillerE0[0x1A0-0xE0];
    /*0x1A0*/ u8 unk1A0;
    /*0x1A1*/ u8 unk1A1;
};

struct UnknownStruct1
{
    u8 filler0[0x10];
    /*0x10*/ u8 animArg1;
    /*0x11*/ u8 animArg2;
    u8 filler12[5];
    /*0x17*/ u8 unk17;
};

extern u8* gBattlescriptCurrInstr;
extern u8 gActiveBank;
extern u8 gBattleBufferB[4][0x200];
extern struct ChoicedMoveSomething *gUnknown_0202449C;  // choiced move something?
extern struct UnknownStruct1 gUnknown_02024474;
extern u16 gCurrentMove;
extern struct BattlePokemon gBattleMons[4];
extern u32 gBattleTypeFlags;
extern u8 gStringBank;
extern const struct BattleMove gBattleMoves[];
extern u16 gLastUsedMove[];
extern u16 gLastUsedItem;
extern u8 gNoOfAllBanks;
extern u32 gStatuses3[];
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u16 gBattleWeather;
extern u8 gTurnOrder[];
extern u8 gBattleTextBuff1[];
extern u16 gSideAffecting[];
extern u8 gBattleCommunication[];
extern void (*gBattleMainFunc)(void);
extern s32 gBattleMoveDamage;

extern const u8 *gUnknown_02024220[];
extern const u8 *gUnknown_02024230[];

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

extern const u32 gBitTable[];

extern void BattleTurnPassed(void);
extern u8 ItemId_GetHoldEffect();
extern void CancelMultiTurnMoves(u8);
extern u8 GetBankSide(u8);

//array entries for battle communication
#define MOVE_EFFECT_BYTE    0x3
#define MULTISTRING_CHOOSER 0x5
#define MSG_DISPLAY         0x7

u8 IsImprisoned(u8 bank, u16 move);
u8 AbilityBattleEffects(u8 caseID, u8 bank, u8 ability, u8 special, u16 move);
u8 ItemBattleEffects(u8 caseID, u8 bank, bool8 moveTurn);

void b_movescr_stack_push(u8* bsPtr)
{
    gBattleStruct->unk8->ptr[gBattleStruct->unk8->size++] = bsPtr;
}

void b_movescr_stack_push_cursor(void)
{
    gBattleStruct->unk8->ptr[gBattleStruct->unk8->size++] = gBattlescriptCurrInstr;
}

void b_movescr_stack_pop_cursor(void)
{
    gBattlescriptCurrInstr = gBattleStruct->unk8->ptr[--gBattleStruct->unk8->size];
}

u8 sub_803FB4C(void)  //msg can't select a move
{
    u8 limitations = 0;
    u16 move = gBattleMons[gActiveBank].moves[gBattleBufferB[gActiveBank][2]];
    u8 holdEffect;
    u16* choicedMove = &gUnknown_0202449C->unkC8[gActiveBank];

    if (gDisableStructs[gActiveBank].disabledMove == move && move != 0)
    {
        gUnknown_02024474.unk17 = gActiveBank;
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DAE2A;
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DAE1F;
            limitations = 1;
        }
    }

    if (move == gLastUsedMove[gActiveBank] && move != MOVE_STRUGGLE && (gBattleMons[gActiveBank].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(gActiveBank);
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB098;
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DB089;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBank].tauntTimer1 != 0 && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB0AF;
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DB0A0;
            limitations++;
        }
    }

    if (IsImprisoned(gActiveBank, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gUnknown_02024230[gActiveBank] = gUnknown_082DB185;
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DB181;
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
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DB812;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBank].pp[gBattleBufferB[gActiveBank][2]] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_20000)
        {
            gProtectStructs[gActiveBank].unk2_4 = 1;
        }
        else
        {
            gUnknown_02024220[gActiveBank] = gUnknown_082DB076;
            limitations++;
        }
    }

    return limitations;
}

#define MOVE_LIMITATION_ZEROMOVE    (1 << 0)
#define MOVE_LIMITATION_PP          (1 << 1)
#define MOVE_LIMITATION_DISABLED    (1 << 2)
#define MOVE_LIMITATION_TORMENTED   (1 << 3)
#define MOVE_LIMITATION_TAUNT       (1 << 4)
#define MOVE_LIMITATION_IMPRISION   (1 << 5)

u8 CheckMoveLimitations(u8 bank, u8 unusableMoves, u8 check)
{
    u8 holdEffect;
    u16* choicedMove = &gUnknown_0202449C->unkC8[bank];
    s32 i;
    if (gBattleMons[bank].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[bank].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(gBattleMons[bank].item);
    gStringBank = bank;
    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[bank].moves[i] == 0 && check & MOVE_LIMITATION_ZEROMOVE)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].pp[i] == 0 && check & MOVE_LIMITATION_PP)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].moves[i] == gDisableStructs[bank].disabledMove && check & MOVE_LIMITATION_DISABLED)
            unusableMoves |= gBitTable[i];
        if (gBattleMons[bank].moves[i] == gLastUsedMove[bank] && check & MOVE_LIMITATION_TORMENTED && gBattleMons[bank].status2 & STATUS2_TORMENT)
            unusableMoves |= gBitTable[i];
        if (gDisableStructs[bank].tauntTimer1 && check & MOVE_LIMITATION_TAUNT && gBattleMoves[gBattleMons[bank].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        if (IsImprisoned(bank, gBattleMons[bank].moves[i]) && check & MOVE_LIMITATION_IMPRISION)
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
    if (unusable == 0xF) //all moves are unusable
    {
        gProtectStructs[gActiveBank].onlyStruggle = 1;
        gUnknown_02024220[gActiveBank] = BattleScript_NoMovesLeft;
    }
    else
        gProtectStructs[gActiveBank].onlyStruggle = 0;
    return (unusable == 0xF);
}

u8 IsImprisoned(u8 bank, u16 move)
{
    u8 imprisionedMoves = 0;
    u8 bankSide = GetBankSide(bank);
    s32 i;
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (bankSide != GetBankSide(i) && gStatuses3[i] & STATUS3_IMPRISIONED)
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

extern u8 b_first_side(u8, u8, u8);
extern void sub_803CEDC(u8, u8);
extern void b_call_bc_move_exec(const u8 *);

// TODO: make these const
extern u8 gUnknown_082DACFA[];
extern u8 gUnknown_082DAD0B[];
extern u8 gUnknown_082DACC9[];
extern u8 gUnknown_082DAC47[];
extern u8 gUnknown_082DACE0[];
extern u8 gUnknown_082DACD2[];
extern u8 BattleScript_WishComesTrue[];
extern u8 gUnknown_082DACC9[];
extern u8 gUnknown_082DAC2C[];

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

        switch (gUnknown_0202449C->turncountersTracker)
        {
        case 0:
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                gTurnOrder[i] = i;
            }
            for (i = 0; i < gNoOfAllBanks - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gNoOfAllBanks; j++)
                {
                    if (b_first_side(gTurnOrder[i], gTurnOrder[j], 0))
                        sub_803CEDC(i, j);
                }
            }
            gUnknown_0202449C->turncountersTracker++;
            // TODO: get rid of this asm
            {
                register u8 zero asm("r1") = 0;
                gUnknown_0202449C->turnSideTracker = zero;
            }
            // fall through
        case 1:
            while (gUnknown_0202449C->turnSideTracker < 2)
            {
                sideBank = gUnknown_0202449C->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimer[sideBank].reflectBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimer[sideBank].reflectTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_REFLECT;
                        b_call_bc_move_exec(gUnknown_082DACFA);
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = MOVE_REFLECT;
                        gBattleTextBuff1[3] = MOVE_REFLECT >> 8;
                        gBattleTextBuff1[4] = EOS;
                        effect++;
                    }
                }
                gUnknown_0202449C->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gUnknown_0202449C->turncountersTracker++;
                gUnknown_0202449C->turnSideTracker = 0;
            }
            break;
        case 2:
            while (gUnknown_0202449C->turnSideTracker < 2)
            {
                sideBank = gUnknown_0202449C->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimer[sideBank].lightscreenBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimer[sideBank].lightscreenTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_LIGHTSCREEN;
                        b_call_bc_move_exec(gUnknown_082DACFA);
                        gBattleCommunication[MULTISTRING_CHOOSER] = sideBank;
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = MOVE_LIGHT_SCREEN;
                        gBattleTextBuff1[3] = MOVE_LIGHT_SCREEN >> 8;
                        gBattleTextBuff1[4] = EOS;
                        effect++;
                    }
                }
                gUnknown_0202449C->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gUnknown_0202449C->turncountersTracker++;
                gUnknown_0202449C->turnSideTracker = 0;
            }
            break;
        case 3:
            while (gUnknown_0202449C->turnSideTracker < 2)
            {
                sideBank = gUnknown_0202449C->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimer[sideBank].mistBank;
                if (gSideTimer[sideBank].mistTimer != 0
                 && --gSideTimer[sideBank].mistTimer == 0)
                {
                    gSideAffecting[sideBank] &= ~SIDE_STATUS_MIST;
                    b_call_bc_move_exec(gUnknown_082DACFA);
                    gBattleCommunication[MULTISTRING_CHOOSER] = sideBank;
                    gBattleTextBuff1[0] = 0xFD;
                    gBattleTextBuff1[1] = 2;
                    gBattleTextBuff1[2] = MOVE_MIST;
                    gBattleTextBuff1[3] = MOVE_MIST >> 8;
                    gBattleTextBuff1[4] = EOS;
                    effect++;
                }
                gUnknown_0202449C->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gUnknown_0202449C->turncountersTracker++;
                gUnknown_0202449C->turnSideTracker = 0;
            }
            break;
        case 4:
            while (gUnknown_0202449C->turnSideTracker < 2)
            {
                sideBank = gUnknown_0202449C->turnSideTracker;
                gActiveBank = gBankAttacker = gSideTimer[sideBank].safeguardBank;
                if (gSideAffecting[sideBank] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimer[sideBank].safeguardTimer == 0)
                    {
                        gSideAffecting[sideBank] &= ~SIDE_STATUS_SAFEGUARD;
                        b_call_bc_move_exec(gUnknown_082DAD0B);
                        effect++;
                    }
                }
                gUnknown_0202449C->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gUnknown_0202449C->turncountersTracker++;
                gUnknown_0202449C->turnSideTracker = 0;
            }
            break;
        case 5:
            while (gUnknown_0202449C->turnSideTracker < gNoOfAllBanks)
            {
                gActiveBank = gTurnOrder[gUnknown_0202449C->turnSideTracker];
                if (gWishFutureKnock.wishCounter[gActiveBank] != 0
                 && --gWishFutureKnock.wishCounter[gActiveBank] == 0
                 && gBattleMons[gActiveBank].hp != 0)
                {
                    gBankTarget = gActiveBank;
                    b_call_bc_move_exec(BattleScript_WishComesTrue);
                    effect++;
                }
                gUnknown_0202449C->turnSideTracker++;
                if (effect)
                    break;
            }
            if (!effect)
            {
                gUnknown_0202449C->turncountersTracker++;
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
                b_call_bc_move_exec(gUnknown_082DAC2C);
                effect++;
            }
            gUnknown_0202449C->turncountersTracker++;
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

                gUnknown_02024474.animArg1 = 0xC;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                b_call_bc_move_exec(gBattlescriptCurrInstr);
                effect++;
            }
            gUnknown_0202449C->turncountersTracker++;
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

                b_call_bc_move_exec(gBattlescriptCurrInstr);
                effect++;
            }
            gUnknown_0202449C->turncountersTracker++;
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

                gUnknown_02024474.animArg1 = 0xD;
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                b_call_bc_move_exec(gBattlescriptCurrInstr);
                effect++;
            }
            gUnknown_0202449C->turncountersTracker++;
            break;
        case 10:
            effect++;
            break;
        }
    } while (effect == 0);
    return (gBattleMainFunc != BattleTurnPassed);
}

#define TURNBASED_MAX_CASE 19

extern u32 gHitMarker;
extern u8 gEffectBank;

extern u8 BattleScript_IngrainTurnHeal[];
extern u8 BattleScript_LeechSeedTurnDrain[];
extern u8 BattleScript_PoisonTurnDmg[];
extern u8 BattleScript_BurnTurnDmg[];
extern u8 BattleScript_NightmareTurnDmg[];
extern u8 BattleScript_CurseTurnDmg[];
extern u8 BattleScript_WrapTurnDmg[];
extern u8 BattleScript_WrapEnds[];
extern u8 gUnknown_082DB234[];
extern u8 gUnknown_082DB2A6[];
extern u8 BattleScript_ThrashConfuses[];
extern u8 BattleScript_DisabledNoMore[];
extern u8 BattleScript_EncoredNoMore[];
extern u8 BattleScript_YawnMakesAsleep[];

extern void EmitSetAttributes(u8 a, u8 request, u8 c, u8 bytes, void *data);
extern void SetMoveEffect(bool8 primary, u8 certainArg);
extern bool8 UproarWakeUpCheck(u8 bank);
extern void MarkBufferBankForExecution(u8 bank);
extern u8 sub_803F90C();

u8 TurnBasedEffects(void)
{
    u8 effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);
    while (gUnknown_0202449C->turnEffectsBank < gNoOfAllBanks && gUnknown_0202449C->turnEffectsTracker <= TURNBASED_MAX_CASE)
    {
        gActiveBank = gBankAttacker = gTurnOrder[gUnknown_0202449C->turnEffectsBank];
        if (gAbsentBankFlags & gBitTable[gActiveBank])
        {
            gUnknown_0202449C->turnEffectsBank++;
        }
        else
        {
            switch (gUnknown_0202449C->turnEffectsTracker)
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
                    b_call_bc_move_exec(BattleScript_IngrainTurnHeal);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 1:  // end turn abilities
                if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, gActiveBank, 0, 0, 0))
                    effect++;
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 2:  // item effects
                if (ItemBattleEffects(1, gActiveBank, 0))
                    effect++;
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 18:  // item effects again
                if (ItemBattleEffects(1, gActiveBank, 1))
                    effect++;
                gUnknown_0202449C->turnEffectsTracker++;
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
                    gUnknown_02024474.animArg1 = gBankTarget;
                    gUnknown_02024474.animArg2 = gBankAttacker;
                    b_call_bc_move_exec(BattleScript_LeechSeedTurnDrain);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 4:  // poison
                if ((gBattleMons[gActiveBank].status1 & STATUS_POISON) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    b_call_bc_move_exec(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
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
                    b_call_bc_move_exec(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 6:  // burn
                if ((gBattleMons[gActiveBank].status1 & STATUS_BURN) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    b_call_bc_move_exec(BattleScript_BurnTurnDmg);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
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
                        b_call_bc_move_exec(BattleScript_NightmareTurnDmg);
                        effect++;
                    }
                    else
                    {
                        gBattleMons[gActiveBank].status2 &= ~STATUS2_NIGHTMARE;
                    }
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 8:  // curse
                if ((gBattleMons[gActiveBank].status2 & STATUS2_CURSED) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    b_call_bc_move_exec(BattleScript_CurseTurnDmg);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 9:  // wrap
                if ((gBattleMons[gActiveBank].status2 & STATUS2_WRAPPED) && gBattleMons[gActiveBank].hp != 0)
                {
                    gBattleMons[gActiveBank].status2 -= 0x2000;
                    if (gBattleMons[gActiveBank].status2 & STATUS2_WRAPPED)  // damaged by wrap
                    {
                        // This is the only way I could get this array access to match.
                        gUnknown_02024474.animArg1 = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 0);
                        gUnknown_02024474.animArg2 = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 1);
                        gBattleTextBuff1[0] = 0xFD;
                        gBattleTextBuff1[1] = 2;
                        gBattleTextBuff1[2] = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 0);
                        gBattleTextBuff1[3] = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 1);
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
                        gBattleTextBuff1[2] = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 0);
                        gBattleTextBuff1[3] = *(gUnknown_0202449C->unk4 + gActiveBank * 2 + 1);
                        gBattleTextBuff1[4] = EOS;
                        gBattlescriptCurrInstr = BattleScript_WrapEnds;
                    }
                    b_call_bc_move_exec(gBattlescriptCurrInstr);
                    effect++;
                }
                gUnknown_0202449C->turnEffectsTracker++;
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
                            b_call_bc_move_exec(gUnknown_082DB234);
                            gActiveBank = gBankAttacker;
                            EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
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
                        if (sub_803F90C(gActiveBank))
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
                        b_call_bc_move_exec(gUnknown_082DB2A6);
                        effect = 1;
                    }
                }
                if (effect != 2)
                    gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 11:  // thrash
                if (gBattleMons[gActiveBank].status2 & STATUS2_LOCK_CONFUSE)
                {
                    gBattleMons[gActiveBank].status2 -= 0x400;
                    if (sub_803F90C(gActiveBank))
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
                                b_call_bc_move_exec(BattleScript_ThrashConfuses);
                            effect++;
                        }
                    }
                }
                gUnknown_0202449C->turnEffectsTracker++;
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
                        b_call_bc_move_exec(BattleScript_DisabledNoMore);
                        effect++;
                    }
                }
                gUnknown_0202449C->turnEffectsTracker++;
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
                        b_call_bc_move_exec(BattleScript_EncoredNoMore);
                        effect++;
                    }
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 14:  // lock-on decrement
                if (gStatuses3[gActiveBank] & STATUS3_ALWAYS_HITS)
                    gStatuses3[gActiveBank] -= 0x8;
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 15:  // charge
                if (gDisableStructs[gActiveBank].chargeTimer1 && --gDisableStructs[gActiveBank].chargeTimer1 == 0)
                    gStatuses3[gActiveBank] &= ~STATUS3_CHARGED_UP;
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 16:  // taunt
                if (gDisableStructs[gActiveBank].tauntTimer1)
                    gDisableStructs[gActiveBank].tauntTimer1--;
                gUnknown_0202449C->turnEffectsTracker++;
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
                        EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                        MarkBufferBankForExecution(gActiveBank);
                        gEffectBank = gActiveBank;
                        b_call_bc_move_exec(BattleScript_YawnMakesAsleep);
                        effect++;
                    }
                }
                gUnknown_0202449C->turnEffectsTracker++;
                break;
            case 19:  // done
                gUnknown_0202449C->turnEffectsTracker = 0;
                gUnknown_0202449C->turnEffectsBank++;
                break;
            }
            if (effect != 0)
                return effect;
        }
    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);
    return 0;
}

extern u8 battle_get_per_side_status(u8);

struct UnknownStruct2
{
    u8 filler0[4];
    u32 unk4;
    u8 unk8[0xC];
};

extern struct UnknownStruct2 gUnknown_0202437C[];

extern u8 gUnknown_082DAFE4[];
extern u8 gUnknown_082DB8F3[];
extern u8 gUnknown_082DAF05[];
extern u8 gUnknown_082DAF20[];

u8 sub_8041364(void)
{
    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_x20);

    switch (gUnknown_0202449C->unk1A0)
    {
    case 0:
        while (gUnknown_0202449C->unk1A1 < gNoOfAllBanks)
        {
            gActiveBank = gUnknown_0202449C->unk1A1;
            if (gAbsentBankFlags & gBitTable[gActiveBank])
            {
                gUnknown_0202449C->unk1A1++;
                continue;
            }

            gUnknown_0202449C->unk1A1++;
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
                gUnknown_0202437C[gBankTarget].unk4 = 0xFFFF;
                b_call_bc_move_exec(gUnknown_082DAFE4);

                if (gWishFutureKnock.futureSightCounter[gActiveBank] == 0
                 && gWishFutureKnock.futureSightCounter[gActiveBank ^ 2] == 0)
                {
                    gSideAffecting[battle_get_per_side_status(gBankTarget) & 1] &= ~SIDE_STATUS_FUTUREATTACK;
                }
                return 1;
            }
        }
        gUnknown_0202449C->unk1A0 = 1;
        // Why do I have to keep doing this to match?
        {
            register u8 zero asm("r0") = 0;
            gUnknown_0202449C->unk1A1 = zero;
        }
        // fall through
    case 1:
        while (gUnknown_0202449C->unk1A1 < gNoOfAllBanks)
        {
            gActiveBank = gBankAttacker = gTurnOrder[gUnknown_0202449C->unk1A1];
            if (gAbsentBankFlags & gBitTable[gActiveBank])
            {
                gUnknown_0202449C->unk1A1++;
                continue;
            }
            gUnknown_0202449C->unk1A1++;
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
                b_call_bc_move_exec(gBattlescriptCurrInstr);
                return 1;
            }
        }
        gUnknown_0202449C->unk1A0 = 2;
        {
            register u8 zero asm("r0") = 0;
            gUnknown_0202449C->unk1A1 = zero;
        }
        // fall through
    case 2:
        if ((gBattleTypeFlags & BATTLE_TYPE_40000)
         && gUnknown_0202449C->unkDA == 2
         && gBattleMons[0].hp != 0 && gBattleMons[1].hp != 0)
        {
            s32 i;

            for (i = 0; i < 2; i++)
                CancelMultiTurnMoves(i);
            gBattlescriptCurrInstr = gUnknown_082DB8F3;
            b_call_bc_move_exec(gUnknown_082DB8F3);
            gUnknown_0202449C->unk1A0++;
            return 1;
        }
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_x20);

    return 0;
}

extern u16 gBattlePartyID[];
extern u8 gBank1;

extern u8 gUnknown_082DA7C4[];
extern u8 gUnknown_082DA7CD[];

extern void sub_803F9EC();
extern bool8 sub_80423F4(u8 bank, u8, u8);

#define sub_8041728_MAX_CASE 7

bool8 sub_8041728(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return 0;
    do
    {
        int i;
        switch (gUnknown_0202449C->unk4D)
        {
        case 0:
            gUnknown_0202449C->unk4E = 0;
            gUnknown_0202449C->unk4D++;
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gAbsentBankFlags & gBitTable[i] && !sub_80423F4(i, 6, 6))
                    gAbsentBankFlags &= ~(gBitTable[i]);
            }
            // fall through
        case 1:
            do
            {
                gBank1 = gBankTarget = gUnknown_0202449C->unk4E;
                if (gBattleMons[gUnknown_0202449C->unk4E].hp == 0
                 && !(gUnknown_0202449C->unkDF & gBitTable[gBattlePartyID[gUnknown_0202449C->unk4E]])
                 && !(gAbsentBankFlags & gBitTable[gUnknown_0202449C->unk4E]))
                {
                    b_call_bc_move_exec(gUnknown_082DA7C4);
                    gUnknown_0202449C->unk4D = 2;
                    return 1;
                }
            } while (++gUnknown_0202449C->unk4E != gNoOfAllBanks);
            gUnknown_0202449C->unk4D = 3;
            break;
        case 2:
            sub_803F9EC(gBank1);
            if (++gUnknown_0202449C->unk4E == gNoOfAllBanks)
                gUnknown_0202449C->unk4D = 3;
            else
                gUnknown_0202449C->unk4D = 1;
            break;
        case 3:
            gUnknown_0202449C->unk4E = 0;
            gUnknown_0202449C->unk4D++;
            // fall through
        case 4:
            do
            {
                gBank1 = gBankTarget = gUnknown_0202449C->unk4E; //or should banks be switched?
                if (gBattleMons[gUnknown_0202449C->unk4E].hp == 0
                 && !(gAbsentBankFlags & gBitTable[gUnknown_0202449C->unk4E]))
                {
                    b_call_bc_move_exec(gUnknown_082DA7CD);
                    gUnknown_0202449C->unk4D = 5;
                    return 1;
                }
            } while (++gUnknown_0202449C->unk4E != gNoOfAllBanks);
            gUnknown_0202449C->unk4D = 6;
            break;
        case 5:
            if (++gUnknown_0202449C->unk4E == gNoOfAllBanks)
                gUnknown_0202449C->unk4D = 6;
            else
                gUnknown_0202449C->unk4D = 4;
            break;
        case 6:
            if (AbilityBattleEffects(9, 0, 0, 0, 0) || AbilityBattleEffects(0xB, 0, 0, 0, 0) || ItemBattleEffects(1, 0, 1) || AbilityBattleEffects(6, 0, 0, 0, 0))
                return 1;
            gUnknown_0202449C->unk4D++;
            break;
        case 7:
            break;
        }
    } while (gUnknown_0202449C->unk4D != sub_8041728_MAX_CASE);
    return 0;
}

extern u16 gChosenMovesByBanks[];

void b_clear_atk_up_if_hit_flag_unless_enraged(void)
{
    int i;
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gChosenMovesByBanks[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~(STATUS2_RAGE);
    }
}
