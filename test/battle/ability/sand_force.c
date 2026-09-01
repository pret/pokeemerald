#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sand Force prevents damage from sandstorm")
{
    enum Type type1 = GetSpeciesType(SPECIES_SHELLOS, 0);
    enum Type type2 = GetSpeciesType(SPECIES_SHELLOS, 1);
    GIVEN {
        ASSUME(type1 != TYPE_ROCK && type2 != TYPE_ROCK);
        ASSUME(type1 != TYPE_GROUND && type2 != TYPE_GROUND);
        ASSUME(type1 != TYPE_STEEL && type2 != TYPE_STEEL);
        PLAYER(SPECIES_SHELLOS) { Ability(ABILITY_SAND_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Sand Force increases the power of Rock-, Ground- and Steel-type moves by 30% in sandstorm", s16 damage)
{
    enum Move moveOpponent, movePlayer;
    PARAMETRIZE { moveOpponent = MOVE_CELEBRATE; movePlayer = MOVE_ROCK_THROW; }
    PARAMETRIZE { moveOpponent = MOVE_SANDSTORM; movePlayer = MOVE_ROCK_THROW; }
    PARAMETRIZE { moveOpponent = MOVE_CELEBRATE; movePlayer = MOVE_EARTHQUAKE; }
    PARAMETRIZE { moveOpponent = MOVE_SANDSTORM; movePlayer = MOVE_EARTHQUAKE; }
    PARAMETRIZE { moveOpponent = MOVE_CELEBRATE; movePlayer = MOVE_IRON_HEAD; }
    PARAMETRIZE { moveOpponent = MOVE_SANDSTORM; movePlayer = MOVE_IRON_HEAD; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_IRON_HEAD) == TYPE_STEEL);
        PLAYER(SPECIES_SHELLOS) { Ability(ABILITY_SAND_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, moveOpponent); MOVE(player, movePlayer); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.3), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.3), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Sand Force don't increase move power if Cloud Nine/Air Lock is on the field", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
        PLAYER(SPECIES_SHELLOS) { Ability(ABILITY_SAND_FORCE); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
