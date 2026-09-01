#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flare Boost increases Sp. Attack by 50% when the Pokémon is burned", s16 damage)
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_NONE; }
    PARAMETRIZE { status1 = STATUS1_BURN; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_FLARE_BOOST); Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
