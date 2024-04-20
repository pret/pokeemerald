#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_PROTECTIVE_PADS].holdEffect == HOLD_EFFECT_PROTECTIVE_PADS);
    ASSUME(gMovesInfo[MOVE_TACKLE].makesContact == TRUE);
}

SINGLE_BATTLE_TEST("Protective Pads protected moves still make direct contact", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_KLUTZ; }
    PARAMETRIZE { ability = ABILITY_FLUFFY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_STUFFUL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Protective Pads doesn't reduce tough claws damage", s16 damage)
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    GIVEN {
        PLAYER(SPECIES_BINACLE) { Ability(ABILITY_TOUGH_CLAWS); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Binacle used Tackle!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Protective Pads doesn't invalid unseen fist")
{
    GIVEN {
        PLAYER(SPECIES_URSHIFU_RAPID_STRIKE_STYLE) { Ability(ABILITY_UNSEEN_FIST); Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Protective Pads protects from Rocly Helmet Damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Rocky Helmet!");
        }
    }
}
