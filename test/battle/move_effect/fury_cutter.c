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

SINGLE_BATTLE_TEST("Fury Cutter counter is the same for both hits of Parental Bond")
{
    s16 damage[4];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_FURY_CUTTER); }
        TURN { MOVE(player, MOVE_FURY_CUTTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_CUTTER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_CUTTER, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
        HP_BAR(opponent, captureDamage: &damage[3]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], B_PARENTAL_BOND_DMG >= GEN_7 ? UQ_4_12(0.25) : UQ_4_12(0.5), damage[1]);
        EXPECT_MUL_EQ(damage[2], B_PARENTAL_BOND_DMG >= GEN_7 ? UQ_4_12(0.25) : UQ_4_12(0.5), damage[3]);
        EXPECT_NE(damage[0], damage[2]);
    }
}
