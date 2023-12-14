#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_IVY_CUDGEL].effect == EFFECT_CHANGE_TYPE_ON_ITEM);
    ASSUME(gBattleMoves[MOVE_IVY_CUDGEL].argument == HOLD_EFFECT_MASK);
}

SINGLE_BATTLE_TEST("Ivy Gudgel changes the move type depending on the mask the user holds")
{
    u16 species;
    u16 item;

    PARAMETRIZE { species = SPECIES_BLASTOISE; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_CHARIZARD; item = ITEM_CORNERSTONE_MASK; }
    PARAMETRIZE { species = SPECIES_CHARIZARD; item = ITEM_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_VENUSAUR; item = ITEM_HEARTHFLAME_MASK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_IVY_CUDGEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IVY_CUDGEL, player);
        HP_BAR(opponent);
        MESSAGE("It's super effective!");
    }
}
