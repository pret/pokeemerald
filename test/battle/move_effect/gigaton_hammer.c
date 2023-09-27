#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_GIGATON_HAMMER].effect == EFFECT_GIGATON_HAMMER);
}

SINGLE_BATTLE_TEST("Struggle will be used if slow Encore is used on Gigaton Hammer")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_ENCORE].effect == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); MOVE(opponent, MOVE_ENCORE); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Gigaton Hammer strikes again if fast encore is used")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_ENCORE].effect == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
        TURN { MOVE(opponent, MOVE_ENCORE); FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Gigaton Hammer alternates with Struggle if it is the only usable move left")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_GIGATON_HAMMER, MOVE_NONE, MOVE_NONE, MOVE_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
    }
}
