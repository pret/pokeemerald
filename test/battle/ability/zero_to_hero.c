#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Zero to Hero transforms Palafin when it switches out")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Palafin, that's enough! Come back!");
        MESSAGE("Go! Wobbuffet!");
        MESSAGE("Wobbuffet, that's enough! Come back!");
        MESSAGE("Go! Palafin!");
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Zero to Hero can't be surpressed by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Zero to Hero transforms both player and opponent")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(player, 0); SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
        MESSAGE("Foe Palafin underwent a heroic transformation!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO);
        EXPECT_EQ(opponent->species, SPECIES_PALAFIN_HERO);
        }
}

SINGLE_BATTLE_TEST("Zero to Hero will activate if a switch move is used")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FLIP_TURN].effect == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLIP_TURN); SEND_OUT(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLIP_TURN, player);
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Gastro Acid, Worry Seed, and Simple Beam fail if the target has the Ability Zero to Hero")
{
    u16 move;

    PARAMETRIZE { move = MOVE_GASTRO_ACID; }
    PARAMETRIZE { move = MOVE_WORRY_SEED; }
    PARAMETRIZE { move = MOVE_SIMPLE_BEAM; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_GASTRO_ACID].effect == EFFECT_GASTRO_ACID);
        ASSUME(gBattleMoves[MOVE_WORRY_SEED].effect == EFFECT_WORRY_SEED);
        ASSUME(gBattleMoves[MOVE_SIMPLE_BEAM].effect == EFFECT_SIMPLE_BEAM);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Role Play, Skill Swap, and Entrainment fail if either Pokémon has Zero to Hero")
{
    u16 move;

    PARAMETRIZE { move = MOVE_ROLE_PLAY; }
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    PARAMETRIZE { move = MOVE_ENTRAINMENT; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_ROLE_PLAY].effect == EFFECT_ROLE_PLAY);
        ASSUME(gBattleMoves[MOVE_SKILL_SWAP].effect == EFFECT_SKILL_SWAP);
        ASSUME(gBattleMoves[MOVE_ENTRAINMENT].effect == EFFECT_ENTRAINMENT);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Transform doesn't apply the heroic transformation message when copying Palafin")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        MESSAGE("Foe Wobbuffet transformed into Palafin!");
        NOT ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Imposter doesn't apply the heroic transformation message when copying Palafin")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(player, 0); SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ABILITY_POPUP(opponent, ABILITY_IMPOSTER);
        MESSAGE("Foe Ditto transformed into Palafin using Imposter!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
            MESSAGE("Foe Ditto underwent a heroic transformation!");
        }
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

// Write Trace test and move this one to that file (including every other ability that can't be copied)
SINGLE_BATTLE_TEST("Zero to Hero cannot be copied by Trace")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_TRACE);
            MESSAGE("Foe Ralts Traced Palafin's Zero to Hero!");
        }
    }
}
