#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Pressure causes opponent's moves to use up 1 additional PP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_POUND, 35}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } THEN {
        EXPECT_EQ(player->pp[0], 33);
    }
}

DOUBLE_BATTLE_TEST("Pressure's effect stacks with multiple Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_SWIFT, 20}); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); }
        OPPONENT(SPECIES_WYNAUT) { Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWIFT); }
    } THEN {
        EXPECT_EQ(playerLeft->pp[0], 17);
    }
}

SINGLE_BATTLE_TEST("Pressure's effect applies to Imprison and Snatch")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_IMPRISON, 10}, {MOVE_SNATCH, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(player, MOVE_IMPRISON); }
        TURN { MOVE(player, MOVE_SNATCH); }
    } THEN {
        EXPECT_EQ(player->pp[0], 8);
        EXPECT_EQ(player->pp[1], 8);
    }
}

SINGLE_BATTLE_TEST("Pressure's effect applies to Spikes, Stealth Rock and Toxic Spikes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_SPIKES, 20}, {MOVE_STEALTH_ROCK, 20}, {MOVE_TOXIC_SPIKES, 20}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
    } THEN {
        EXPECT_EQ(player->pp[0], 18);
        EXPECT_EQ(player->pp[1], 18);
        EXPECT_EQ(player->pp[2], 18);
    }
}

SINGLE_BATTLE_TEST("Pressure's effect doesn't apply to Sticky Web")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_STICKY_WEB, 20}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
    } THEN {
        EXPECT_EQ(player->pp[0], 19);
    }
}
