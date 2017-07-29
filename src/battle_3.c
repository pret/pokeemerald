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

extern u8* gBattlescriptCurrInstr;

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

