#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_WRAP, MOVE_EFFECT_WRAP));
    ASSUME(GetItemHoldEffect(ITEM_BINDING_BAND) == HOLD_EFFECT_BINDING_BAND);
}

SINGLE_BATTLE_TEST("Binding Band increases the damage taken from binding effects", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BINDING_BAND; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(item); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TURN_TRAP, player);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Binding Band increases the damage taken from binding effects even if holder's item gets nullified after", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BINDING_BAND; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(item); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); MOVE(player, MOVE_EMBARGO); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBARGO, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TURN_TRAP, player);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Binding Band (Hold Effect) test titles")
