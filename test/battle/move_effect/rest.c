#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
}

SINGLE_BATTLE_TEST("Rest causes the user to fall asleep and restores HP to full")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(player->status1 & STATUS1_SLEEP);
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Rest fails if the user is at full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(300); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(!(player->status1 & STATUS1_SLEEP));
    }
}

SINGLE_BATTLE_TEST("Rest fails if the user is protected by Leaf Guard")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUNNY_DAY) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SUNNY_DAY) == BATTLE_WEATHER_SUN);
        ASSUME(B_LEAF_GUARD_PREVENTS_REST >= GEN_5);
        PLAYER(SPECIES_CHIKORITA) { Ability(ABILITY_LEAF_GUARD); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(!(player->status1 & STATUS1_SLEEP));
    }
}

SINGLE_BATTLE_TEST("Rest fails if the user is protected by Shields Down")
{
    GIVEN {
        PLAYER(SPECIES_MINIOR_METEOR) { Ability(ABILITY_SHIELDS_DOWN); HP(299); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(!(player->status1 & STATUS1_SLEEP));
    }
}

SINGLE_BATTLE_TEST("Rest fails if the user is protected by Electric/Misty Terrain")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN; }
    GIVEN {
        ASSUME(GetMoveEffect(move) == EFFECT_TERRAIN);

        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        ASSUME(GetMoveTerrainType(MOVE_MISTY_TERRAIN) == B_TERRAIN_MISTY);

        ASSUME(GetSpeciesType(SPECIES_WYNAUT, 0) != TYPE_FLYING && GetSpeciesType(SPECIES_WYNAUT, 1) != TYPE_FLYING);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(!(player->status1 & STATUS1_SLEEP));
    }
}

SINGLE_BATTLE_TEST("Rest fails if the user is protected by Sweet Veil")
{
    GIVEN {
        PLAYER(SPECIES_BOUNSWEET) { Ability(ABILITY_SWEET_VEIL); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(!(player->status1 & STATUS1_SLEEP));
    }
}

DOUBLE_BATTLE_TEST("Rest fails if the user is protected by ally's Sweet Veil")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_BOUNSWEET) { Ability(ABILITY_SWEET_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_REST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, playerLeft);
    } THEN {
        EXPECT(!(playerLeft->status1 & STATUS1_SLEEP));
    }
}

SINGLE_BATTLE_TEST("Rest doesn't fail if the user is protected by Safeguard")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SAFEGUARD); }
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
    } THEN {
        EXPECT(player->status1 & STATUS1_SLEEP);
    }
}

DOUBLE_BATTLE_TEST("Rest doesn't fail if the user is protected by Flower Veil")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CHIKORITA, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_CHIKORITA, 1) == TYPE_GRASS);
        PLAYER(SPECIES_CHIKORITA) { HP(1); }
        PLAYER(SPECIES_FLORGES) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_REST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, playerLeft);
    } THEN {
        EXPECT(playerLeft->status1 & STATUS1_SLEEP);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Rest (Move Effect) test titles")
