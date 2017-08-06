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
#include "battle_move_effects.h"
#include "string_util.h"
//#include "flags.h"

// TODO: move this to battle.h and fix battle_ai.c
struct SimpleUnknownStruct
{
    u32 unkArray[4]; // unknown size
};

struct ChoicedMoveSomething
{
    /*0x00*/ u8 turnEffectsTracker;
    /*0x01*/ u8 turnEffectsBank;
    u8 filler2[1];
    /*0x03*/ u8 turncountersTracker;
    /*0x04*/ u8 unk4[8];
    /*0x0C*/ u8 fillerC[0x13-0xC];

    /*0x13*/ u8 dynamicMoveType;
             u8 filler14[0x4D-0x14];
             
             u8 unk4D;
             u8 unk4E;
             u8 filler4F[0x5C-0x4F];
             
             u8 unk5C[4];
             u8 filler60[0x7F-0x60];
                        
    /*0x7F*/ u8 castformToChangeInto;

             u8 filler80[0xB2-0x80];
             
    /*0xB2*/ u8 synchroniseEffect;
             
             u8 fillerB3[0xC8-0xB3];;
             
    /*0xC8*/ u16 unkC8[4];
    u8 fillerD0[0xD8-0xD0];
    /*0xD8*/ u8 intimidateBank;
    u8 fillerD9[0xDA-0xD9];
    /*0xDA*/ u8 unkDA;
    /*0xDB*/ u8 turnSideTracker;
    u8 fillerDC[0xDF-0xDC];
    u8 unkDF;
    u8 fillerE0[0x1A0-0xE0];
    /*0x1A0*/ u8 unk1A0;
    /*0x1A1*/ u8 unk1A1;
    u8 filler1A2;
    /*0x1A3*/ u8 atkCancellerTracker;
};

struct UnknownStruct1
{
    u8 filler0[4];
    s32 bideDmg;
    u8 filler8[0x10-8];

    /*0x10*/ u8 animArg1;
    /*0x11*/ u8 animArg2;
    u8 filler12[5];
    /*0x17*/ u8 scriptingActive;
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
        gUnknown_02024474.scriptingActive = gActiveBank;
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

extern u8 GetBankIdentity(u8);

/*
struct UnknownStruct2
{
    u8 filler0[4];
    u32 unk4;
    u8 unk8[0xC];
};

extern struct UnknownStruct2 gSpecialStatuses[];
*/

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
                gSpecialStatuses[gBankTarget].moveturnLostHP = 0xFFFF;
                b_call_bc_move_exec(gUnknown_082DAFE4);

                if (gWishFutureKnock.futureSightCounter[gActiveBank] == 0
                 && gWishFutureKnock.futureSightCounter[gActiveBank ^ 2] == 0)
                {
                    gSideAffecting[GetBankIdentity(gBankTarget) & 1] &= ~SIDE_STATUS_FUTUREATTACK;
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

extern u8 BattleScript_MoveUsedWokeUp[];
extern u8 BattleScript_MoveUsedIsAsleep[];
extern u8 BattleScript_MoveUsedIsFrozen[];
extern u8 BattleScript_MoveUsedUnfroze[];
extern u8 BattleScript_MoveUsedLoafingAround[];
extern u8 BattleScript_MoveUsedMustRecharge[];
extern u8 BattleScript_MoveUsedFlinched[];
extern u8 BattleScript_MoveUsedIsDisabled[];
extern u8 BattleScript_MoveUsedIsTaunted[];
extern u8 BattleScript_MoveUsedIsImprisoned[];
extern u8 BattleScript_MoveUsedIsConfused[];
extern u8 BattleScript_MoveUsedIsConfusedNoMore[];
extern u8 BattleScript_MoveUsedIsParalyzed[];
extern u8 BattleScript_MoveUsedIsParalyzedCantAttack[];
extern u8 BattleScript_MoveUsedIsInLove[];
extern u8 BattleScript_BideStoringEnergy[];
extern u8 BattleScript_BideAttack[];
extern u8 BattleScript_BideNoEnergyToAttack[];
extern u8 BattleScript_MoveUsedUnfroze[];

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

extern u8 gBattleMoveFlags;
extern s32 gTakenDmg[];
extern u8 gTakenDmgBanks[4];

s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 a4, u16 powerOverride, u8 typeOverride, u8 bank_atk, u8 bank_def);
u8 CountTrailingZeroBits(u32 a);
u8 GetMoveTarget(u16 move, u8 useMoveTarget);

#define ATKCANCELLER_MAX_CASE 14

u8 AtkCanceller_UnableToUseMove(void)
{
    u8 effect = 0;
    s32* bideDmg = &gUnknown_02024474.bideDmg;
    do
    {
        switch (gUnknown_0202449C->atkCancellerTracker)
        {
        case 0: // flags clear
            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_DESTINY_BOND);
            gStatuses3[gBankAttacker] &= ~(STATUS3_GRUDGE);
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 1: // check being asleep
            if (gBattleMons[gBankAttacker].status1 & STATUS_SLEEP)
            {
                if (UproarWakeUpCheck(gBankAttacker))
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_SLEEP);
                    gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
                    b_movescr_stack_push_cursor();
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
                        b_movescr_stack_push_cursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
                        gUnknown_0202449C->atkCancellerTracker++;
                        break;
                    }
                }
                else // unfreeze
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_FREEZE);
                    b_movescr_stack_push_cursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                effect = 2;
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 6: // disabled move
            if (gDisableStructs[gBankAttacker].disabledMove == gCurrentMove && gDisableStructs[gBankAttacker].disabledMove != 0)
            {
                gProtectStructs[gBankAttacker].usedDisabledMove = 1;
                gUnknown_02024474.scriptingActive = gBankAttacker;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 8: // imprisoned
            if (IsImprisoned(gBankAttacker, gCurrentMove))
            {
                gProtectStructs[gBankAttacker].usedImprisionedMove = 1;
                CancelMultiTurnMoves(gBankAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
                        b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 11: // infatuation
            if (gBattleMons[gBankAttacker].status2 & STATUS2_INFATUATION)
            {
                gUnknown_02024474.scriptingActive = CountTrailingZeroBits((gBattleMons[gBankAttacker].status2 & STATUS2_INFATUATION) >> 0x10);
                if (Random() & 1)
                    b_movescr_stack_push_cursor();
                else
                {
                    b_movescr_stack_push(BattleScript_MoveUsedIsParalyzedCantAttack);
                    gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    gProtectStructs[gBankAttacker].loveImmobility = 1;
                    CancelMultiTurnMoves(gBankAttacker);
                }
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
                effect = 1;
            }
            gUnknown_0202449C->atkCancellerTracker++;
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
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 13: // move thawing
            if (gBattleMons[gBankAttacker].status1 & STATUS_FREEZE)
            {
                if (gBattleMoves[gCurrentMove].effect == EFFECT_THAW_HIT)
                {
                    gBattleMons[gBankAttacker].status1 &= ~(STATUS_FREEZE);
                    b_movescr_stack_push_cursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                }
                effect = 2;
            }
            gUnknown_0202449C->atkCancellerTracker++;
            break;
        case 14: // last case
            break;
        }

    } while (gUnknown_0202449C->atkCancellerTracker != ATKCANCELLER_MAX_CASE && effect == 0);

    if (effect == 2)
    {
        gActiveBank = gBankAttacker;
        EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
        MarkBufferBankForExecution(gActiveBank);
    }
    return effect;
}

extern u8 GetBankByPlayerAI(u8);
extern u8 sub_806D864(u8);
extern u8 sub_806D82C(u8);

bool8 sub_80423F4(u8 bank, u8 r1, u8 r2)
{
    struct Pokemon* party;
    u8 r7;
    u8 r6;
    s32 i;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return 0;
    if (gBattleTypeFlags & BATTLE_TYPE_400000)
    {
        if (GetBankSide(bank) == 0)
            party = gPlayerParty;
        else
            party = gEnemyParty;
        r6 = ((bank & 2) >> 1);
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
        if (gBattleTypeFlags & BATTLE_TYPE_800000)
        {
            if (GetBankSide(bank) == 0)
            {
                party = gPlayerParty;
                r7 = sub_806D864(bank);
                r6 = sub_806D82C(r7);
            }
            else
            {
                // FIXME: Compiler insists on moving r4 into r1 before doing the eor
                register u32 r1 asm("r1");

                party = gEnemyParty;
                r1 = bank ^ 1;
                r6 = (r1 != 0) ? 1 : 0;
            }
        }
        else
        {
            r7 = sub_806D864(bank);
            if (GetBankSide(bank) == 0)
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
    else if ((gBattleTypeFlags & BATTLE_TYPE_8000) && GetBankSide(bank) == 1)
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
        if (GetBankSide(bank) == 1)
        {
            r7 = GetBankByPlayerAI(1);
            r6 = GetBankByPlayerAI(3);
            party = gEnemyParty;
        }
        else
        {
            r7 = GetBankByPlayerAI(0);
            r6 = GetBankByPlayerAI(2);
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
             && i != r1 && i != r2 && i != r7[gUnknown_0202449C->unk5C] && i != r6[gUnknown_0202449C->unk5C])
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

extern u8 gBattleTextBuff2[];
u8 weather_get_current(void);
void b_push_move_exec(u8* BS_ptr);
void RecordAbilityBattle(u8 bank, u8 ability);
extern u8 gLastUsedAbility;
extern u8 gUnknown_082DACE7[];
extern u8 BattleScript_DrizzleActivates[];
extern u8 BattleScript_SandstreamActivates[];
extern u8 BattleScript_DroughtActivates[];
extern u8 BattleScript_CastformChange[];
extern u8 BattleScript_RainDishActivates[];
extern u8 BattleScript_ShedSkinActivates[];
extern u8 BattleScript_SpeedBoostActivates[];
extern u8 BattleScript_SoundproofProtected[];
extern u8 BattleScript_MoveHPDrain[];
extern u8 BattleScript_MoveHPDrain_PPLoss[];
extern u8 BattleScript_FlashFireBoost[];
extern u8 BattleScript_FlashFireBoost_PPLoss[];
extern u8 BattleScript_ColorChangeActivates[];
extern u8 BattleScript_RoughSkinActivates[];
extern u8 BattleScript_ApplySecondaryEffect[];
extern u8 BattleScript_CuteCharmActivates[];
extern u8 gUnknown_082DB68C[];
extern u8 BattleScript_SynchronizeActivates[];
extern u8 gUnknown_082DB4B8[];
extern u8 gUnknown_082DB4C1[];
extern u8 BattleScript_TraceActivates[];
extern const u8 gStatusConditionString_PoisonJpn[];
extern const u8 gStatusConditionString_SleepJpn[];
extern const u8 gStatusConditionString_ParalysisJpn[];
extern const u8 gStatusConditionString_BurnJpn[];
extern const u8 gStatusConditionString_IceJpn[];
extern const u8 gStatusConditionString_ConfusionJpn[];
extern const u8 gStatusConditionString_LoveJpn[];
extern const u16 gSoundMovesTable[];

/*
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
    if (GetBankSide(gBankAttacker) == 0)
        pokeAtk = &gPlayerParty[gBattlePartyID[gBankAttacker]];
    else
        pokeAtk = &gEnemyParty[gBattlePartyID[gBankAttacker]];

    if (gBankTarget >= gNoOfAllBanks)
        gBankTarget = bank;
    if (GetBankSide(gBankTarget) == 0)
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

        if (gUnknown_0202449C->dynamicMoveType)
            moveType = gUnknown_0202449C->dynamicMoveType & 0x3F;
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
			case 0xFF: //weather from overworld
            //_08042A86
				switch (weather_get_current())
				{
                case 3:
                case 5:
                case 13:
                    if (!(gBattleWeather & WEATHER_RAIN_ANY))
                    {
                        gBattleWeather = (WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_PERMANENT);
                        gUnknown_02024474.animArg1 = 0xA;
                        gUnknown_02024474.scriptingActive = bank;
                        effect++;
                    }
                    break;
                case 8:
                    if (!(gBattleWeather & WEATHER_SANDSTORM_ANY))
                    {
                        gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                        gUnknown_02024474.animArg1 = 0xC;
                        gUnknown_02024474.scriptingActive = bank;
                        effect++;
                    }
                    break;
                case 12:
                    if (!(gBattleWeather & WEATHER_SUN_ANY))
                    {
                        gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                        gUnknown_02024474.animArg1 = 0xB;
                        gUnknown_02024474.scriptingActive = bank;
                        effect++;
                    }
                    break;
				}
				if (effect)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = weather_get_current();
                    b_push_move_exec(gUnknown_082DACE7);
                }
				break;
			case ABILITY_DRIZZLE:
            //_08042B78
			    if (!(gBattleWeather & WEATHER_RAIN_PERMANENT))
                {
                    gBattleWeather = (WEATHER_RAIN_PERMANENT | WEATHER_RAIN_TEMPORARY);
                    b_push_move_exec(BattleScript_DrizzleActivates);
                    gUnknown_02024474.scriptingActive = bank;
                    effect++;
                }
				break;
			case ABILITY_SAND_STREAM:
            //_08042BA8
			    if (!(gBattleWeather & WEATHER_SANDSTORM_PERMANENT))
                {
                    gBattleWeather = (WEATHER_SANDSTORM_PERMANENT | WEATHER_SANDSTORM_TEMPORARY);
                    b_push_move_exec(BattleScript_SandstreamActivates);
                    gUnknown_02024474.scriptingActive = bank;
                    effect++;
                }
				break;
			case ABILITY_DROUGHT:
            //_08042BD8
                if (!(gBattleWeather & WEATHER_SUN_PERMANENT))
                {
                    gBattleWeather = (WEATHER_SUN_PERMANENT | WEATHER_SUN_TEMPORARY);
                    b_push_move_exec(BattleScript_DroughtActivates);
                    gUnknown_02024474.scriptingActive = bank;
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
                    b_push_move_exec(BattleScript_CastformChange);
                    gUnknown_02024474.scriptingActive = bank;
                    gUnknown_0202449C->castformToChangeInto = effect - 1;
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
                            b_push_move_exec(BattleScript_CastformChange);
                            gUnknown_02024474.scriptingActive = i;
                            gUnknown_0202449C->castformToChangeInto = effect - 1;
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
                        b_push_move_exec(BattleScript_RainDishActivates);
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
                        gUnknown_02024474.scriptingActive = gActiveBank = bank;
                        b_push_move_exec(BattleScript_ShedSkinActivates);
                        EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[bank].status1);
                        MarkBufferBankForExecution(gActiveBank);
                        effect++;
                    }
                    break;
                case ABILITY_SPEED_BOOST:
                //_08042E84
                    if (gBattleMons[bank].statStages[STAT_STAGE_SPEED] < 0xC && gDisableStructs[bank].isFirstTurn != 2)
                    {
                        gBattleMons[bank].statStages[STAT_STAGE_SPEED]++;
                        gUnknown_02024474.animArg1 = 0x11;
                        gUnknown_02024474.animArg2 = 0;
                        b_push_move_exec(BattleScript_SpeedBoostActivates);
                        gUnknown_02024474.scriptingActive = bank;
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
                        //if (!(ewram17100.arr[bank] & 1))
                        if (!(gBattleStruct->unk4->unkArray[bank] & 1))
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                            if (gProtectStructs[gBankAttacker].notFirstStrike)
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                            else
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;
                            //ewram17100.arr[bank] |= 1;
                            gBattleStruct->unk4->unkArray[bank] |= 1;
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                    b_movescr_stack_push_cursor();
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
                        b_movescr_stack_push_cursor();
                        gBattlescriptCurrInstr = gUnknown_082DB68C;
                        gUnknown_02024474.scriptingActive = i;
                        gActiveBank = i;
                        EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
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
                            b_push_move_exec(BattleScript_CastformChange);
                            gUnknown_02024474.scriptingActive = i;
                            gUnknown_0202449C->castformToChangeInto = effect - 1;
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
                gUnknown_0202449C->synchroniseEffect &= 0x3F;
                if (gUnknown_0202449C->synchroniseEffect == 6)
                    gUnknown_0202449C->synchroniseEffect = 2;
                gBattleCommunication[MOVE_EFFECT_BYTE] = gUnknown_0202449C->synchroniseEffect + 0x40;
                gUnknown_02024474.scriptingActive = gBankTarget;
                b_movescr_stack_push_cursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_IGNORE_SAFEGUARD;
                effect++;
            }
            break;
        case ABILITYEFFECT_ATK_SYNCHRONIZE: // 8
            if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONISE_EFFECT))
            {
                gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
                gUnknown_0202449C->synchroniseEffect &= 0x3F;
                if (gUnknown_0202449C->synchroniseEffect == 6)
                    gUnknown_0202449C->synchroniseEffect = 2;
                gBattleCommunication[MOVE_EFFECT_BYTE] = gUnknown_0202449C->synchroniseEffect;
                gUnknown_02024474.scriptingActive = gBankAttacker;
                b_movescr_stack_push_cursor();
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
                    b_push_move_exec(gUnknown_082DB4B8);
                    gUnknown_0202449C->intimidateBank = i;
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
                    u8 target1 = GetBankByPlayerAI(opposite);
                    u8 target2 = GetBankByPlayerAI(opposite + 2);
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (gBattleMons[target1].ability != 0 && gBattleMons[target1].hp != 0
                         && gBattleMons[target2].ability != 0 && gBattleMons[target2].hp != 0)
                        {
                            gActiveBank = GetBankByPlayerAI(((Random() & 1) * 2) | opposite);
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
                        b_push_move_exec(BattleScript_TraceActivates);
                        gStatuses3[i] &= ~(STATUS3_TRACE);
                        gUnknown_02024474.scriptingActive = i;

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
                    b_movescr_stack_push_cursor();
                    gBattlescriptCurrInstr = gUnknown_082DB4C1;
                    gUnknown_0202449C->intimidateBank = i;
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
        case ABILITYEFFECT_COUNT_OTHER_SIZE: // 16
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
*/