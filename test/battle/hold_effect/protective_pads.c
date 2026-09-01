#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_PROTECTIVE_PADS].holdEffect == HOLD_EFFECT_PROTECTIVE_PADS);
    ASSUME(MoveMakesContact(MOVE_SCRATCH) == TRUE);
}

SINGLE_BATTLE_TEST("Protective Pads protected moves still make direct contact", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Protective Pads doesn't reduce tough claws damage", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    GIVEN {
        PLAYER(SPECIES_BINACLE) { Ability(ABILITY_TOUGH_CLAWS); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Binacle used Scratch!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Protective Pads doesn't invalid unseen fist")
{
    GIVEN {
        PLAYER(SPECIES_URSHIFU_RAPID_STRIKE) { Ability(ABILITY_UNSEEN_FIST); Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Protective Pads protects from Rocly Helmet Damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rocky Helmet!");
        }
    }
}

SINGLE_BATTLE_TEST("Protective Pads protects from Protect's secondary effects")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            if (move == MOVE_SPIKY_SHIELD) {
                HP_BAR(player);
            } else if (move == MOVE_BANEFUL_BUNKER) {
                STATUS_ICON(player, STATUS1_POISON);
            } else if (move == MOVE_BURNING_BULWARK) {
                STATUS_ICON(player, STATUS1_BURN);
            } else if (move == MOVE_KINGS_SHIELD) {
                MESSAGE("Wobbuffet's Attack fell!");
            } else if (move == MOVE_SILK_TRAP) {
                MESSAGE("Wobbuffet's Speed fell!");
            } else if (move == MOVE_OBSTRUCT) {
                MESSAGE("Wobbuffet's Defense harshly fell!");
            }
        }
    }
}
