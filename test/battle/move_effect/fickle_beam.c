#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_FICKLE_BEAM].effect == EFFECT_FICKLE_BEAM);
}

SINGLE_BATTLE_TEST("Fickle Beam deals double damage 30% of the time")
{
    s16 damage[2];

    PASSES_RANDOMLY(30, 100, RNG_FICKLE_BEAM);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_POWER_GEM].power == 80);
        ASSUME(gMovesInfo[MOVE_FICKLE_BEAM].power == 80);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_GEM); }
        TURN { MOVE(player, MOVE_FICKLE_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_GEM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FICKLE_BEAM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}
