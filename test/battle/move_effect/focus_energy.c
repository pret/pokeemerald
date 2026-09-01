#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOCUS_ENERGY) == EFFECT_FOCUS_ENERGY);
}

SINGLE_BATTLE_TEST("Focus Energy increases the user's critical hit ratio by 1 stage (Gen 1-2) or 2 stages (Gen 3+)")
{
    bool32 useFocusEnergy = 0;
    u32 genConfig = 0, chance = 0;
    for (u32 j = GEN_1; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = j; useFocusEnergy = FALSE; chance = j >= GEN_7 ? 24 : 16; } // ~4.16%/6.25% with Wobbuffet's base speed
        PARAMETRIZE { genConfig = j; useFocusEnergy = TRUE;
            if (j >= GEN_6)
                chance = 2; // 50% / 25%
            else if (j >= GEN_3)
                chance = 4; // 25%
            else
                chance = 8; // 12.5% with Wobbuffet's base speed
        }
    }
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, (genConfig == GEN_1)? GEN_2 : genConfig);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useFocusEnergy)
            TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (useFocusEnergy)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Focus Energy multiplies crit chance by 4 with gen 1 crit chance")
{
    bool32 useFocusEnergy = 0;
    u32 genConfig = 0, chance = 0;
    for (u32 j = GEN_1; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = j; useFocusEnergy = FALSE; chance = 16; }
        PARAMETRIZE { genConfig = j; useFocusEnergy = TRUE; chance = 4; }
    }
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_1);
        WITH_CONFIG(B_FOCUS_ENERGY_CRIT_RATIO, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useFocusEnergy)
            TURN { MOVE(player, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (useFocusEnergy)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_ENERGY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

TO_DO_BATTLE_TEST("Focus Energy fails if critical hit stage was already increased by Dragon Cheer")
TO_DO_BATTLE_TEST("Baton Pass passes Focus Energy's effect");
