#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SPIN_OUT, self: TRUE, speed: -2);
}

SINGLE_BATTLE_TEST("Spin Out lowers speed by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIN_OUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIN_OUT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed harshly fell!");
    }
}
