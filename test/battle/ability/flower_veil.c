#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
    ASSUME(GetMoveEffect(MOVE_POISON_GAS) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_GAS) == MOVE_EFFECT_POISON);
    ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
    ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
    ASSUME(GetMoveEffect(MOVE_HYPNOSIS) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_HYPNOSIS) == MOVE_EFFECT_SLEEP);
}

DOUBLE_BATTLE_TEST("Flower Veil prevents status on allied Grass-types - right target")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_GAS; }
    PARAMETRIZE { move = MOVE_WILL_O_WISP; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentRight); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        MESSAGE("The opposing Chikorita surrounded itself with a veil of petals!");
    }
}

DOUBLE_BATTLE_TEST("Flower Veil prevents status on allied Grass-types - left target")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISON_GAS; }
    PARAMETRIZE { move = MOVE_WILL_O_WISP; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CHIKORITA);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_FLOWER_VEIL);
        MESSAGE("The opposing Chikorita surrounded itself with a veil of petals!");
    }
}

DOUBLE_BATTLE_TEST("Flower Veil's stat reduction protection considers Contrary") // Eg. If a move would reduce stats due to Contrary, it will be protected by Mist.
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SWAGGER) == EFFECT_SWAGGER);
        ASSUME(GetSpeciesType(SPECIES_SNIVY, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_SNIVY, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWAGGER, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWAGGER, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        MESSAGE("The opposing Snivy surrounded itself with a veil of petals!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Flower Veil does not prevent self-inflicted stat drops - moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_LEAF_STORM; }
    PARAMETRIZE { move = MOVE_CURSE; }

    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_LEAF_STORM, self: TRUE, spAtk: -2);
        ASSUME_STAT_CHANGE(MOVE_CURSE, attack: +1, defense: +1, speed: -1);
        PLAYER(SPECIES_CHIKORITA);
        PLAYER(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        NOT ABILITY_POPUP(playerRight, ABILITY_FLOWER_VEIL);
    } THEN {
        if (move == MOVE_LEAF_STORM)
        {
            EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
        }
        else
        {
            EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
            EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        }
    }
}

DOUBLE_BATTLE_TEST("Flower Veil does not prevent self-inflicted stat drops - abilities")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FORESTS_CURSE) == EFFECT_THIRD_TYPE);
        ASSUME(GetMoveArgType(MOVE_FORESTS_CURSE) == TYPE_GRASS);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        PLAYER(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FORESTS_CURSE, target: playerLeft); }
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FORESTS_CURSE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_WEAK_ARMOR);
        NOT ABILITY_POPUP(playerRight, ABILITY_FLOWER_VEIL);
    } THEN {
        EXPECT_EQ(playerLeft->types[2], TYPE_GRASS);
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}
