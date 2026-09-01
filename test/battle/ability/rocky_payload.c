#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rocky Payload increases Rock-type move damage", s16 damage)
{
    enum Move move;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_ROCKY_PAYLOAD; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; ability = ABILITY_ROCKY_PAYLOAD; }
    PARAMETRIZE { move = MOVE_POWER_GEM; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_POWER_GEM; ability = ABILITY_ROCKY_PAYLOAD; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_POWER_GEM) == TYPE_ROCK);
        ASSUME(GetMoveCategory(MOVE_ROCK_THROW) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_POWER_GEM) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_BOMBIRDIER) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Rock Throw should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Power Gem should be affected
    }
}
