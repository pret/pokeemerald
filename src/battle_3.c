#include "global.h"
#include "abilities.h"
#include "battle.h"
//#include "moves.h"
//#include "item.h"
//#include "items.h"
//#include "hold_effects.h"
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

struct BattleEnigmaBerry
{
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 holdEffect;
    /*0x08*/ u8 itemEffect[18];
    /*0x1A*/ u8 holdEffectParam;
};

extern struct BattleEnigmaBerry gEnigmaBerries[];

struct UnknownStruct1
{
    u8 filler0[0x17];
    u8 unk17;
};

extern u8* gBattlescriptCurrInstr;
extern u8 gActiveBank;
extern u8 gBattleBufferB[4][0x200];
//extern u16 gUnknown_0202449C[];  // choiced move something?
extern struct ChoicedMoveSomething *gUnknown_0202449C;  // choiced move something?
extern struct UnknownStruct1 gUnknown_02024474;
extern u16 gCurrentMove;
extern struct BattlePokemon gBattleMons[4];
extern u32 gBattleTypeFlags;
extern u8 gStringBank;
extern const struct BattleMove gBattleMoves[];
extern u16 gUnknown_02024248[];
extern u16 gLastUsedItem;

// Don't know what this stuff is

extern const u8 *gUnknown_02024220[];
extern const u8 *gUnknown_02024230[];

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

extern u8 itemid_get_x12();
extern u8 sub_8040130();
extern void b_cancel_multi_turn_move_maybe();

u8 sub_803FB4C(void)
{
    u8 limitations = 0;
    u16 move = gBattleMons[gActiveBank].moves[gBattleBufferB[gActiveBank][2]];
    u8 holdEffect;
    u16* choicedMove = &gUnknown_0202449C->unkC8[gActiveBank];
    
    if (gDisableStructs[gActiveBank].disabledMove == move && move != 0)
    {
        gUnknown_02024474.unk17 = gActiveBank;
        gCurrentMove = move;
        if (gBattleTypeFlags & 0x20000)
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

    if (move == gUnknown_02024248[gActiveBank] && move != 0xA5 && (gBattleMons[gActiveBank].status2 & (1 << 31)))
    {
        b_cancel_multi_turn_move_maybe(gActiveBank);
        if (gBattleTypeFlags & 0x20000)
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
        if (gBattleTypeFlags & 0x20000)
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
    
    if (sub_8040130(gActiveBank, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & 0x20000)
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
    
    if (gBattleMons[gActiveBank].item == 0xAF)
        holdEffect = gEnigmaBerries[gActiveBank].holdEffect;
    else
        holdEffect = itemid_get_x12(gBattleMons[gActiveBank].item);
    gStringBank = gActiveBank;
    if (holdEffect == 0x1D && *choicedMove != 0 && *choicedMove != 0xFFFF && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[gActiveBank].item;
        if (gBattleTypeFlags & 0x20000)
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
        if (gBattleTypeFlags & 0x20000)
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
