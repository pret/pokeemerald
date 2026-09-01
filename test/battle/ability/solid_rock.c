#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Solid Rock reduces damage to Super Effective moves by 0.75", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STURDY; }
    PARAMETRIZE { ability = ABILITY_SOLID_ROCK; }
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CARRACOSTA].types[0] == TYPE_WATER);
        ASSUME(gSpeciesInfo[SPECIES_CARRACOSTA].types[1] == TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_CLOSE_COMBAT) == TYPE_FIGHTING);
        ASSUME(gTypeEffectivenessTable[TYPE_FIGHTING][TYPE_ROCK] > UQ_4_12(1.0));
        ASSUME(gTypeEffectivenessTable[TYPE_FIGHTING][TYPE_WATER] == UQ_4_12(1.0));
        PLAYER(SPECIES_CARRACOSTA) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CLOSE_COMBAT); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
        MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}
