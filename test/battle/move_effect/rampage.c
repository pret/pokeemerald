#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_THRASH].effect == EFFECT_RAMPAGE);
}

SINGLE_BATTLE_TEST("Thrash lasts for 2 or 3 turns")
{
    PASSES_RANDOMLY(1, 2, RNG_RAMPAGE_TURNS);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
    }
}

SINGLE_BATTLE_TEST("Thrash confuses the user after it finishes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}

SINGLE_BATTLE_TEST("Thrash does not confuse the user if it is canceled on turn 1 of 3")
{
    GIVEN {
        ASSUME(B_RAMPAGE_CANCELLING >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { MOVE(opponent, MOVE_PROTECT); SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}

SINGLE_BATTLE_TEST("Thrash does not confuse the user if it is canceled on turn 2 of 3")
{
    GIVEN {
        ASSUME(B_RAMPAGE_CANCELLING >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { MOVE(opponent, MOVE_PROTECT); SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}

SINGLE_BATTLE_TEST("Thrash confuses the user if it is canceled on turn 3 of 3")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(B_RAMPAGE_CANCELLING >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(opponent, MOVE_PROTECT); SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}
