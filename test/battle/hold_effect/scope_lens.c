#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Scope Lens increases the critical hit ratio by 1 stage")
{
    u32 genConfig = 0, passes, trials;
    PARAMETRIZE { genConfig = GEN_1; passes = 1; trials = 4; } // 25% with Wobbuffet's base speed
    for (u32 j = GEN_2; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; passes = 1; trials = 8; } // 12.5%
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(gItemsInfo[ITEM_SCOPE_LENS].holdEffect == HOLD_EFFECT_SCOPE_LENS);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SCOPE_LENS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}
