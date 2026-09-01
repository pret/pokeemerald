#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Toxic Boost increases Attack by 50% when the Pokémon is poisoned", s16 damage)
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_NONE; }
    PARAMETRIZE { status1 = STATUS1_POISON; }
    PARAMETRIZE { status1 = STATUS1_TOXIC_POISON; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_ZANGOOSE) { Ability(ABILITY_TOXIC_BOOST); Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
    }
}
