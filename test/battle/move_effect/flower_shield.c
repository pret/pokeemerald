#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FLOWER_SHIELD) == EFFECT_FLOWER_SHIELD);
    ASSUME_STAT_CHANGE(MOVE_FLOWER_SHIELD, defense: +1);
}

DOUBLE_BATTLE_TEST("Flower Shield raises the defense of all Grass-type Pokémon")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_TANGELA, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_TANGROWTH, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_SUNKERN, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_SUNFLORA, 0) == TYPE_GRASS);
        PLAYER(SPECIES_TANGELA);
        PLAYER(SPECIES_TANGROWTH);
        OPPONENT(SPECIES_SUNKERN);
        OPPONENT(SPECIES_SUNFLORA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLOWER_SHIELD); MOVE(playerRight, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Tangela used Flower Shield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Tangela's Defense rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Tangrowth's Defense rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Sunkern's Defense rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Sunflora's Defense rose!");
    }
}

SINGLE_BATTLE_TEST("Flower Shield fails if there's no Grass-type Pokémon on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLOWER_SHIELD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, player);
    }
}

DOUBLE_BATTLE_TEST("Flower Shield doesn't affect Grass-type Pokémon that are in a semi-invulnerable position")
{
    GIVEN {
        PLAYER(SPECIES_BULBASAUR);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_FLY, target: playerLeft);
            MOVE(playerLeft, MOVE_FLOWER_SHIELD);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Flower Shield")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_TANGELA, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_GRASS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_TANGELA) { Moves(MOVE_FLOWER_SHIELD, MOVE_POUND); }
        OPPONENT(SPECIES_TANGELA);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_FLOWER_SHIELD); }
    }
}
