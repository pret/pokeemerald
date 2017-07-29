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
    u8 filler0[0xC8];
    u16 unkC8[4];
};


struct UnknownStruct1
{
    u8 filler0[0x17];
    u8 unk17;
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

extern u8 ItemId_GetHoldEffect();
extern void b_cancel_multi_turn_move_maybe();
extern u8 GetBankSide(u8);

u8 IsImprisoned(u8 bank, u16 move);

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
        b_cancel_multi_turn_move_maybe(gActiveBank);
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
