#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_LIGHT_BALL) == HOLD_EFFECT_LIGHT_BALL);
}

static const enum Species speciesToCheck[] = {
    SPECIES_PICHU,
    SPECIES_PIKACHU,
    SPECIES_PIKACHU_COSPLAY,
    SPECIES_PIKACHU_ROCK_STAR,
    SPECIES_PIKACHU_BELLE,
    SPECIES_PIKACHU_POP_STAR,
    SPECIES_PIKACHU_PHD,
    SPECIES_PIKACHU_LIBRE,
    SPECIES_PIKACHU_ORIGINAL,
    SPECIES_PIKACHU_HOENN,
    SPECIES_PIKACHU_SINNOH,
    SPECIES_PIKACHU_UNOVA,
    SPECIES_PIKACHU_KALOS,
    SPECIES_PIKACHU_ALOLA,
    SPECIES_PIKACHU_PARTNER,
    SPECIES_PIKACHU_WORLD,
    SPECIES_PIKACHU_GMAX,
};

SINGLE_BATTLE_TEST("Light Ball doubles Pikachu's Special Attack", s16 damage)
{
    enum Species species = SPECIES_NONE;
    enum Item item = ITEM_NONE;

    for (u32 j = 0; j < ARRAY_COUNT(speciesToCheck); j++) {
        PARAMETRIZE { item = ITEM_NONE;       species = speciesToCheck[j]; }
        PARAMETRIZE { item = ITEM_LIGHT_BALL; species = speciesToCheck[j]; }
    }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_THUNDERSHOCK) == DAMAGE_CATEGORY_SPECIAL);
        if (species == SPECIES_PIKACHU_GMAX) {
            PLAYER(SPECIES_PIKACHU) { Item(item); GigantamaxFactor(TRUE); }
        } else {
            PLAYER(species) { Item(item); }
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (species == SPECIES_PIKACHU_GMAX) {
            TURN { MOVE(player, MOVE_THUNDERSHOCK, gimmick: GIMMICK_DYNAMAX); }
        } else {
            TURN { MOVE(player, MOVE_THUNDERSHOCK); }
        }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1) { // First check to avoid boosting other species
            EXPECT_EQ(results[i - 1].damage, results[i].damage);
        } else if (i % 2 == 1) { // Every 2nd test afterwards
            EXPECT_MUL_EQ(results[i - 1].damage, Q_4_12(2.0), results[i].damage);
        }
    }
}

SINGLE_BATTLE_TEST("Light Ball doubles Pikachu's Attack (Gen4+)", s16 damage)
{
    enum Species species = SPECIES_NONE;
    enum Item item = ITEM_NONE;
    u32 config = 0;

    for (u32 j = 0; j < ARRAY_COUNT(speciesToCheck); j++) {
        PARAMETRIZE { item = ITEM_NONE;       config = GEN_3; species = speciesToCheck[j]; }
        PARAMETRIZE { item = ITEM_LIGHT_BALL; config = GEN_3; species = speciesToCheck[j]; }
        PARAMETRIZE { item = ITEM_LIGHT_BALL; config = GEN_4; species = speciesToCheck[j]; }
    }

    GIVEN {
        WITH_CONFIG(B_LIGHT_BALL_ATTACK_BOOST, config);
        ASSUME(GetMoveCategory(MOVE_SPARK) == DAMAGE_CATEGORY_PHYSICAL);
        if (species == SPECIES_PIKACHU_GMAX) {
            PLAYER(SPECIES_PIKACHU) { Item(item); GigantamaxFactor(TRUE); }
        } else {
            PLAYER(species) { Item(item); }
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (species == SPECIES_PIKACHU_GMAX) {
            TURN { MOVE(player, MOVE_SPARK, gimmick: GIMMICK_DYNAMAX); }
        } else {
            TURN { MOVE(player, MOVE_SPARK); }
        }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 2) { // First check to avoid boosting other species
            EXPECT_EQ(results[i - 2].damage, results[i].damage); // No item vs Light Ball
            EXPECT_EQ(results[i - 1].damage, results[i].damage); // Gen 3 vs Gen 4
        } else if (i % 3 == 2) { // Every 3rd test afterwards
            EXPECT_MUL_EQ(results[i - 2].damage, Q_4_12(2.0), results[i].damage); // No item vs Light Ball
            EXPECT_MUL_EQ(results[i - 1].damage, Q_4_12(2.0), results[i].damage); // Gen 3 vs Gen 4
        }
    }
}
