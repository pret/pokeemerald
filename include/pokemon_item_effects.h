#ifndef GUARD_POKEMON_ITEM_EFFECTS
#define GUARD_POKEMON_ITEM_EFFECTS

#include "pokemon.h"

// TODO once pokemon item effects is decompiled
/*
struct PokemonItemEffect
{
    //field 0
    u8 xAtk : 4; // x1, x2, x4, x8 = xF
    u8 field_0_x10 : 1; // x10
    u8 critRatioUp : 1; // x20
    u8 field_0_x40 : 1; // x40
    u8 cureInfatuation : 1; // x80

    /*field 1
    u8 xSpeed : 4; // x1, x2, x4, x8 = xF
    u8 xDefense : 4; // x10, x20, x40, xF0

    /*field 2
    u8 xSpAtk : 4; // x1, x2, x4, x8 = xF
    u8 xAccuracy : 4; // x10, x20, x40, xF0

    /*field 3
    u8 cureConfusion : 1; // x1
    u8 cureParalysis : 1; // x2
    u8 cureFreeze : 1; // x4
    u8 cureBurn : 1; // x8
    u8 curePoison : 1; // x10
    u8 cureSleep : 1; // x20
    u8 field_3_x40 : 1; // x40
    u8 cantLowerStats : 1; // x80

    /*field 4
    u8 hpEv : 1; // x1
    u8 attackEv : 1; // x2
    u8 healHp : 1; // x4
    u8 field_4_x8 : 1; // x8
    u8 field_4_x10 : 1; // x10
    u8 ppUp : 1; // x20
    u8 levelUp : 1; // x40
    u8 evolutionStone : 1; // x80

    /*field 5
    u8 defEv:  1; // x1
    u8 speedEv : 1; // x2
    u8 spDefEv : 1; // x4
    u8 spAtkEv : 1; // x8
    u8 ppMax : 1; // x10
    u8 field_5_x20 : 1; // x20
    u8 field_5_x40 : 1; // x40
    u8 field_5_x80 : 1; // x80

    /*field 6
    u8 value;
};
*/

bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 itemId, u8 partyId, u8 monMoveIndex, u8 a5);

#endif // GUARD_POKEMON_ITEM_EFFECTS
