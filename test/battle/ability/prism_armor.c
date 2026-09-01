#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Prism Armor reduces damage to Super Effective moves by 0.75", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_NECROZMA].types[0] == TYPE_PSYCHIC);
        ASSUME(gSpeciesInfo[SPECIES_NECROZMA].types[1] == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_DARK_PULSE) == TYPE_DARK);
        ASSUME(gTypeEffectivenessTable[TYPE_POISON][TYPE_FAIRY] > UQ_4_12(1.0));
        ASSUME(gTypeEffectivenessTable[TYPE_POISON][TYPE_PSYCHIC] == UQ_4_12(1.0));
        PLAYER(SPECIES_NECROZMA);
        OPPONENT(SPECIES_WEEZING) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DARK_PULSE); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
        MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}
