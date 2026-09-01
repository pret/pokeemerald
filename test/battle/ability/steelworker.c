#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Steelworker increases Steel-type move damage", s16 damage)
{
    enum Move move;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_STEELWORKER; }
    PARAMETRIZE { move = MOVE_ANCHOR_SHOT; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_ANCHOR_SHOT; ability = ABILITY_STEELWORKER; }
    PARAMETRIZE { move = MOVE_FLASH_CANNON; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_FLASH_CANNON; ability = ABILITY_STEELWORKER; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_STEEL);
        ASSUME(GetMoveType(MOVE_ANCHOR_SHOT) == TYPE_STEEL);
        ASSUME(GetMoveType(MOVE_FLASH_CANNON) == TYPE_STEEL);
        ASSUME(GetMoveCategory(MOVE_ANCHOR_SHOT) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_FLASH_CANNON) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_DHELMISE) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Anchor Shot should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Flash Cannon should be affected
    }
}
