#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Rollout (Move Effect) test titles")

SINGLE_BATTLE_TEST("Rollout's power doubles after each hit and resest after the 5th hit")
{
    s16 damage[6];
    int turn;
    int maxTurns = 6;

    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_STEELIX);
    } WHEN {
        TURN { MOVE(player, MOVE_ROLLOUT); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        for (turn = 0; turn < maxTurns; turn++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
            HP_BAR(opponent, captureDamage: &damage[turn]);
        }
    } THEN {
        for (turn = 1; turn < maxTurns - 1; turn++)
            EXPECT_MUL_EQ(damage[turn - 1], UQ_4_12(2.0), damage[turn]);
        EXPECT_EQ(damage[0], damage[maxTurns - 1]);
    }
}

SINGLE_BATTLE_TEST("Rollout's base power resets if the chain has been broken")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ROLLOUT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROLLOUT); }
        TURN { MOVE(opponent, MOVE_PROTECT); SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Rollout resets if original user is forced to switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ROLLOUT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_ROLLOUT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLLOUT); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
