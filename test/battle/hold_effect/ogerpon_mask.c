#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_CORNERSTONE_MASK].holdEffect == HOLD_EFFECT_OGERPON_MASK);
    ASSUME(gItemsInfo[ITEM_WELLSPRING_MASK].holdEffect == HOLD_EFFECT_OGERPON_MASK);
    ASSUME(gItemsInfo[ITEM_HEARTHFLAME_MASK].holdEffect == HOLD_EFFECT_OGERPON_MASK);
    ASSUME(gItemsInfo[ITEM_CORNERSTONE_MASK].holdEffectParam == 20);
    ASSUME(gItemsInfo[ITEM_WELLSPRING_MASK].holdEffectParam == 20);
    ASSUME(gItemsInfo[ITEM_HEARTHFLAME_MASK].holdEffectParam == 20);
}

SINGLE_BATTLE_TEST("Ogerpon Masks increase the base power of moves by 20%", s16 damage)
{
    u32 species;
    u32 item;
    PARAMETRIZE { species = SPECIES_OGERPON_TEAL_MASK; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING_MASK; item = ITEM_CORNERSTONE_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME_MASK; item = ITEM_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE_MASK; item = ITEM_HEARTHFLAME_MASK; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[3].damage);
    }
}
