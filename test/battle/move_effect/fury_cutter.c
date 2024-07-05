#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_FURY_CUTTER].effect == EFFECT_FURY_CUTTER);
}

SINGLE_BATTLE_TEST("Fury Cutter power doubles with each use, up to 160 power")
{
    s16 damage[6];
    int turn;
    int maxTurns;

    if (B_UPDATED_MOVE_DATA >= GEN_6)
        maxTurns = 4;
    else if (B_UPDATED_MOVE_DATA == GEN_5)
        maxTurns = 5;
    else
        maxTurns = 6;

    GIVEN {
        PLAYER(SPECIES_CROBAT);
        OPPONENT(SPECIES_LINOONE) { HP(900); }
    } WHEN {
        for (turn = 0; turn < maxTurns; turn++)
            TURN { MOVE(player, MOVE_FURY_CUTTER); }
    } SCENE {
        for (turn = 0; turn < maxTurns; turn++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_CUTTER, player);
            HP_BAR(opponent, captureDamage: &damage[turn]);
        }
    } THEN {
        for (turn = 1; turn < maxTurns - 1; turn++)
            EXPECT_MUL_EQ(damage[turn - 1], UQ_4_12(2.0), damage[turn]);
        EXPECT_EQ(damage[maxTurns - 2], damage[maxTurns - 1]);
    }
}
