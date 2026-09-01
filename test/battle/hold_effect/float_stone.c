#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_FLOAT_STONE) == HOLD_EFFECT_FLOAT_STONE);
}

SINGLE_BATTLE_TEST("Float Stone halves the holder's weight", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_FLOAT_STONE; } //  10.0 - 24.9 kg  (40 power)
    PARAMETRIZE { item = ITEM_NONE;        } //  25.0 - 49.9 kg  (60 power)

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        ASSUME(GetMoveArgType(MOVE_SOAK) == TYPE_WATER);
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOAK); } // To remove super-effectiveness, as it was messing with calculations.
        TURN { MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Float Stone doesn't affect Heavy Ball's multiplier")
