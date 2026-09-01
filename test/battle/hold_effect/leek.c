#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Leek increases critical hit ratio by 2 stages for the Farfetch'd Family")
{
    enum Species species;
    u32 genConfig, passes, trials;

    PARAMETRIZE { genConfig = GEN_1; passes = 15; trials = 16; species = SPECIES_FARFETCHD; }       // ~93.8% with Farfetch'd's base speed
    PARAMETRIZE { genConfig = GEN_1; passes = 27; trials = 32; species = SPECIES_FARFETCHD_GALAR; } // ~84.4% with Galarian Farfetch'd's base speed
    PARAMETRIZE { genConfig = GEN_1; passes = 1;  trials = 1;  species = SPECIES_SIRFETCHD; }       // 100% with Sirfetch'd's base speed
    for (u32 j = GEN_2; j <= GEN_5; j++) {
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 4;  species = SPECIES_FARFETCHD; }       // 25%
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 4;  species = SPECIES_FARFETCHD_GALAR; } // 25%
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 4;  species = SPECIES_SIRFETCHD; }       // 25%
    }
    for (u32 j = GEN_6; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 2;  species = SPECIES_FARFETCHD; }       // 50%
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 2;  species = SPECIES_FARFETCHD_GALAR; } // 50%
        PARAMETRIZE { genConfig = j; passes = 1;  trials = 2;  species = SPECIES_SIRFETCHD; }       // 50%
    }
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_FARFETCHD) == 60);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_FARFETCHD_GALAR) == 55);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_SIRFETCHD) == 65);
        ASSUME(gItemsInfo[ITEM_LEEK].holdEffect == HOLD_EFFECT_LEEK);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(ITEM_LEEK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("A critical hit!");
    }
}
