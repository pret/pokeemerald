#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Magic Guard prevents recoil damage to the user")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_EDGE].recoil == 33);
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_EDGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_EDGE, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    } 
}
