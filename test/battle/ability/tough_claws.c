#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Tough Claws (Ability) test titles")

SINGLE_BATTLE_TEST("Tough Claws boosts contact moves when user has Protective Pads, but not with Punching Glove", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_BARBARACLE) { Ability(ABILITY_TOUGH_CLAWS); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.18), results[0].damage); // 1.3 / 1.1 ~= 1.18
    }
}
