#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_THRASH, MOVE_EFFECT_THRASH) == TRUE);
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
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_THRASH, 10}); }
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
    } THEN {
        // Check that PP has been consumed correctly
        EXPECT_EQ(player->pp[0], 9);
    }
}

SINGLE_BATTLE_TEST("Thrash does not confuse the user if it is canceled on turn 1 of 3")
{
    GIVEN {
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

SINGLE_BATTLE_TEST("Thrash confuses the user if it is canceled on turn 3 of 3, Protect")
{
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

SINGLE_BATTLE_TEST("Thrash confuses the user if it is canceled on turn 3 of 3, Immunity")
{
    GIVEN {
        ASSUME(B_RAMPAGE_CANCELLING >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { SWITCH(opponent, 1); SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}

SINGLE_BATTLE_TEST("Petal Dance does not lock mons that copy the move with Dancer")
{
    GIVEN {
        PLAYER(SPECIES_VILEPLUME);
        OPPONENT(SPECIES_ORICORIO);
    } WHEN {
        TURN { MOVE(player, MOVE_PETAL_DANCE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        // How do you actually test locking?
        EXPECT(!(opponent->status2 & STATUS2_MULTIPLETURNS));
    }
}
