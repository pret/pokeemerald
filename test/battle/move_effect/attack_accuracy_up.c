#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hone Claws increases Attack and Accuracy by one stage each")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_HONE_CLAWS, attack: +1, accuracy: +1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HONE_CLAWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HONE_CLAWS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose!");
        MESSAGE("Wobbuffet's accuracy rose!");
    }
}
