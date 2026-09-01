#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(MoveMakesContact(MOVE_FIRE_PUNCH));
    ASSUME(GetMoveType(MOVE_FIRE_PUNCH) == TYPE_FIRE);
}

SINGLE_BATTLE_TEST("Fluffy halves damage taken from moves that make direct contact", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fluffy doubles damage taken from fire type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fluffy does not alter damage of fire-type moves that make direct contact", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fluffy halves damage taken from moves that make direct contact even if protected by Protective Pads", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_THUNDER_PUNCH));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fluffy does not halve damage taken from moves that make direct contact but are ignored by Punching Glove", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_THUNDER_PUNCH));
        ASSUME(IsPunchingMove(MOVE_THUNDER_PUNCH));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PUNCHING_GLOVE); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fluffy does not halve damage taken from moves that make direct contact but are ignored by Long Reach", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_THUNDER_PUNCH));
        PLAYER(SPECIES_ROWLET) { Ability(ABILITY_LONG_REACH); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
