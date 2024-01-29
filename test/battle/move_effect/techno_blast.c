#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TECHNO_BLAST].effect == EFFECT_CHANGE_TYPE_ON_ITEM);
    ASSUME(gMovesInfo[MOVE_TECHNO_BLAST].argument == HOLD_EFFECT_DRIVE);
}


SINGLE_BATTLE_TEST("Techno Blast changes the move type depending on the mask the user holds")
{
    u16 species;
    u16 item;

    PARAMETRIZE { species = SPECIES_CHARIZARD; item = ITEM_DOUSE_DRIVE; }
    PARAMETRIZE { species = SPECIES_BLASTOISE; item = ITEM_SHOCK_DRIVE; }
    PARAMETRIZE { species = SPECIES_VENUSAUR; item = ITEM_BURN_DRIVE; }
    PARAMETRIZE { species = SPECIES_DRATINI; item = ITEM_CHILL_DRIVE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TECHNO_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TECHNO_BLAST, player);
        HP_BAR(opponent);
        MESSAGE("It's super effective!");
    }
}
