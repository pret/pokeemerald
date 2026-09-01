#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Super Luck increases the critical hit ratio by 1 stage")
{
    u32 j, genConfig = 0, passes = 0, trials = 0;

    PARAMETRIZE { genConfig = GEN_1; passes = 5; trials = 32; } // ~15.6% with Togepi's base speed
    for (j = GEN_2; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; passes = 1; trials = 8; }  // 12.5%
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(GetSpeciesBaseSpeed(SPECIES_TOGEPI) == 20);
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SUPER_LUCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

TO_DO_BATTLE_TEST("Super Luck increases the chances of wild Pokémon holding items (Gen8+)");
