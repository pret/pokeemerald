#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SECRET_POWER, MOVE_EFFECT_SECRET_POWER) == TRUE);
}

SINGLE_BATTLE_TEST("Secret Power inflicts paralysis in Electric Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power inflicts sleep in Grassy Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Speed in Psychic Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Secret Power lowers Sp. Atk in Misty Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MISTY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_MISTY_TERRAIN) == B_TERRAIN_MISTY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MISTY_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SECRET_POWER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
    }
}

TO_DO_BATTLE_TEST("Secret Power doesn't inflict secondary effects when user fainted");
