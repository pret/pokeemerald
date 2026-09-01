#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Solar Power increases a Sp. Attack by x1.5 in Sun", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_HYPER_VOICE) > 0);
        ASSUME(GetMoveCategory(MOVE_HYPER_VOICE) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_CHARIZARD) { Ability(ABILITY_SOLAR_POWER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (move == MOVE_SUNNY_DAY)
            HP_BAR(player);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Power doesn't increases a Sp. Attack if Cloud Nine/Air Lock is on the field", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_HYPER_VOICE) > 0);
        ASSUME(GetMoveCategory(MOVE_HYPER_VOICE) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_CHARIZARD) { Ability(ABILITY_SOLAR_POWER); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Solar Power causes the Pokémon to lose 1/8 max HP in Sun")
{
    GIVEN {
        PLAYER(SPECIES_CHARIZARD) { Ability(ABILITY_SOLAR_POWER); MaxHP(80); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET);
    } SCENE {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP - player->maxHP/8);
    }
}

SINGLE_BATTLE_TEST("Solar Power doesn't cause the Pokémon to lose 1/8 max HP if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_CHARIZARD) { Ability(ABILITY_SOLAR_POWER); MaxHP(80); HP(80); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}
