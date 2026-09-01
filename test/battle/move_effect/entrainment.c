#include "global.h"
#include "test/battle.h"

AI_DOUBLE_BATTLE_TEST("AI prefers Entrainment'ing good abilities onto partner with bad ability")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_QUAXWELL) { Level(18); Ability(ABILITY_TORRENT); Moves(MOVE_WATER_GUN); }
        PLAYER(SPECIES_CORPHISH) { Level(18); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_SMEARGLE) { Level(17); Ability(ABILITY_TECHNICIAN); Moves(MOVE_AERIAL_ACE, MOVE_ENTRAINMENT, MOVE_FLAME_WHEEL, MOVE_MAGICAL_LEAF); }
        OPPONENT(SPECIES_ARCHEN) { Level(17); Ability(ABILITY_DEFEATIST); Moves(MOVE_DUAL_WINGBEAT, MOVE_ROCK_TOMB); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_ENTRAINMENT); EXPECT_MOVE(opponentRight, MOVE_DUAL_WINGBEAT); MOVE(playerLeft, MOVE_WATER_GUN); MOVE(playerRight, MOVE_WATER_GUN); }
    }
}

SINGLE_BATTLE_TEST("Entrainment changes the target's Ability to match the user's")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); }
    } THEN {
        EXPECT(opponent->ability == ABILITY_TELEPATHY);
    }
}

SINGLE_BATTLE_TEST("Entrainment fails if the user's ability has cantBeCopied flag")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_MULTITYPE].cantBeCopied);
        PLAYER(SPECIES_ARCEUS)   { Ability(ABILITY_MULTITYPE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->ability == ABILITY_MULTITYPE);
        EXPECT(opponent->ability == ABILITY_SHADOW_TAG);
    }
}

SINGLE_BATTLE_TEST("Entrainment fails if the target's ability has cantBeOverwritten flag")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_MULTITYPE].cantBeOverwritten);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_ARCEUS)  { Ability(ABILITY_MULTITYPE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->ability   == ABILITY_TELEPATHY);
        EXPECT(opponent->ability == ABILITY_MULTITYPE);
    }
}

SINGLE_BATTLE_TEST("Entrainment causes primal weather to revert")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, player);
        MESSAGE("The extremely harsh sunlight faded!");
    } THEN {
        EXPECT(opponent->ability == ABILITY_TELEPATHY);
    }
}

TO_DO_BATTLE_TEST("Entrainment fails on Dynamaxed Pokémon");
