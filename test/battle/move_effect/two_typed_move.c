#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sky Plate doesn't boost Flying Press' power", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_SKY_PLATE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLYING_PRESS) == EFFECT_TWO_TYPED_MOVE);
        ASSUME(GetMoveType(MOVE_FLYING_PRESS) == TYPE_FIGHTING);
        ASSUME(GetMoveArgType(MOVE_FLYING_PRESS) == TYPE_FLYING);
        ASSUME(gItemsInfo[ITEM_SKY_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_SKY_PLATE].secondaryId == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLYING_PRESS); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Flying Press does both Fighting and Flying-type for type effectiveness")
TO_DO_BATTLE_TEST("Flying-type Pokémon don't receive STAB on Flying Press")
TO_DO_BATTLE_TEST("Sharp Beak doesn't boost Flying Press' power") // Check Black Belt for comparison
TO_DO_BATTLE_TEST("Flying Gem doesn't trigger when using Flying Press") // Check Fighting Gem for comparison
TO_DO_BATTLE_TEST("Coba Berry doesn't trigger when the user is attacked by Flying Press")
TO_DO_BATTLE_TEST("Flying Press triggers Chople Berry, even when it wouldn't be super effective with regular Fighting-type moves")
TO_DO_BATTLE_TEST("Flying Press under Electrify does both Electric and Flying-type for type effectiveness") // Check Electric 1/4 effectiveness
TO_DO_BATTLE_TEST("Flying Press under Normalize does both Normal and Flying-type for type effectiveness") // Check Rock/Steel 1/4 effectiveness
