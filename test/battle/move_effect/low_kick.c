#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Low Kick's damage varies based on the target's weight", s16 damage)
{
    enum Species species;
    u32 weight;

    PARAMETRIZE { species = SPECIES_CUBONE;     weight = 65;   } //   0.1 - 9.9 kg   (20 power)
    PARAMETRIZE { species = SPECIES_SANDSHREW;  weight = 120;  } //  10.0 - 24.9 kg  (40 power)
    PARAMETRIZE { species = SPECIES_MAROWAK;    weight = 450;  } //  25.0 - 49.9 kg  (60 power)
    PARAMETRIZE { species = SPECIES_SANDACONDA; weight = 655;  } //  50.0 - 99.9 kg  (80 power)
    PARAMETRIZE { species = SPECIES_DONPHAN;    weight = 1200; } // 100.0 - 199.9 kg (100 power)
    PARAMETRIZE { species = SPECIES_HIPPOWDON;  weight = 3000; } // 200.0 kg or more (120 power)

    GIVEN {
        ASSUME(GetSpeciesWeight(species) == weight);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Defense(170); } // Cubone's Defense, the lowest one in hopes of avoid distorting the results.
    } WHEN {
        TURN { MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        // Since Low Kick increases by 20 each tier, multiply by tier number to compare with the first tier.
        if (i != 0)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(i + 1), results[i].damage);
    }
}
