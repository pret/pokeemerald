#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveCantBeUsedTwice(MOVE_GIGATON_HAMMER) == TRUE);
    ASSUME(MoveCantBeUsedTwice(MOVE_BLOOD_MOON) == TRUE);
}

SINGLE_BATTLE_TEST("Struggle will be used if slow Encore is used on moves with the cantUseTwice flag")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GIGATON_HAMMER; }
    PARAMETRIZE { move = MOVE_BLOOD_MOON; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_ENCORE); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Moves with the cantUseTwice flag strike again if fast encore is used")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GIGATON_HAMMER; }
    PARAMETRIZE { move = MOVE_BLOOD_MOON; }
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_3);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_ENCORE); FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Moves with the cantUseTwice flag alternate with Struggle if it is the only usable move left")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GIGATON_HAMMER; }
    PARAMETRIZE { move = MOVE_BLOOD_MOON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(move, MOVE_NONE, MOVE_NONE, MOVE_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, move); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

SINGLE_BATTLE_TEST("Moves with the cantUseTwice flag can alternate between each other")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_GIGATON_HAMMER, MOVE_BLOOD_MOON, MOVE_NONE, MOVE_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
        TURN { MOVE(player, MOVE_BLOOD_MOON); }
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
        TURN { MOVE(player, MOVE_BLOOD_MOON); }
        TURN { MOVE(player, MOVE_GIGATON_HAMMER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLOOD_MOON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLOOD_MOON, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGATON_HAMMER, player);
    }
}
