#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sharpness increases the power of slicing moves", s16 damage)
{
    u32 move;
    u16 ability;
    PARAMETRIZE { move = MOVE_AERIAL_ACE; ability = ABILITY_SHARPNESS; }
    PARAMETRIZE { move = MOVE_AERIAL_ACE; ability = ABILITY_STEADFAST; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_SHARPNESS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_STEADFAST; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_AERIAL_ACE].slicingMove);
        ASSUME(!gBattleMoves[MOVE_SCRATCH].slicingMove);
        PLAYER(SPECIES_GALLADE) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage); // Sharpness affects slicing moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Sharpness does not affect non-slicing moves
    }
}
