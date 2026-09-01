#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Gorilla Tactics boosts physical damage by 50%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics stacks with Choice Band to reach 2.25x Attack", s16 damage)
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE;         item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS;  item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS;  item = ITEM_CHOICE_BAND; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5),  results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.25), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics does not boost damage while Dynamaxed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics does not lock moves while Dynamaxed")
{
    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ABILITY_GORILLA_TACTICS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_FLAME_CHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_FLARE, player);
    }
}
