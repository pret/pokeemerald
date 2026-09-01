#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Fur Coat doubles Defense", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FUR_COAT; }
    PARAMETRIZE { ability = ABILITY_RATTLED; }

    GIVEN {
        PLAYER(SPECIES_PERSIAN_ALOLA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Fur Coat has no effect on self-inflicted confusion damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FUR_COAT; }
    PARAMETRIZE { ability = ABILITY_RATTLED; }

    GIVEN {
        PLAYER(SPECIES_PERSIAN_ALOLA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_POUND, WITH_RNG(RNG_CONFUSION, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
