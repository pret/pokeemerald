#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dragon's Maw increases Dragon-type move damage", s16 damage)
{
    enum Move move;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_DRAGONS_MAW; }
    PARAMETRIZE { move = MOVE_DRAGON_CLAW; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_DRAGON_CLAW; ability = ABILITY_DRAGONS_MAW; }
    PARAMETRIZE { move = MOVE_DRAGON_BREATH; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_DRAGON_BREATH; ability = ABILITY_DRAGONS_MAW; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_DRAGON);
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        ASSUME(GetMoveType(MOVE_DRAGON_BREATH) == TYPE_DRAGON);
        ASSUME(GetMoveCategory(MOVE_DRAGON_CLAW) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_DRAGON_BREATH) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_REGIDRAGO) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Dragon Claw should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Dragon Breath should be affected
    }
}
