#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_COSMIC_POWER, defense: +1, spDef: +1);
}

SINGLE_BATTLE_TEST("Cosmic Power increases the user's Defense and Sp. Defense by 1 stage each")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COSMIC_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COSMIC_POWER, player);
        MESSAGE("Wobbuffet's Defense rose!");
        MESSAGE("Wobbuffet's Sp. Def rose!");
    }
}
