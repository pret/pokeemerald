#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("criticalHitStage set to 1 increases critical hits occur at a 1/8 rate (Gen 2+) or x8 times more likely (Gen 1)")
{
    u32 j, genConfig = 0, passes = 0, trials = 0;

    PARAMETRIZE { genConfig = GEN_1; passes = 1; trials = 2; }     // 50% with Wobbuffet's base speed
    for (j = GEN_2; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = GEN_2; passes = 1; trials = 8; }
    }
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveCriticalHitStage(MOVE_SLASH) == 1);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLASH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("Critical hits mention each affected target")
{
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_9);
        ASSUME(GetMoveCriticalHitStage(MOVE_SLASH) == 1);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_DRAGONITE) { Item(ITEM_SCOPE_LENS); SpAttack(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_DRAGON_CHEER); MOVE(playerLeft, MOVE_SURF); }
        TURN { MOVE(playerLeft, MOVE_SURF); }
        TURN { MOVE(playerLeft, MOVE_DAZZLING_GLEAM); }
    } SCENE {
        // Surf against all targets
        MESSAGE("A critical hit on the opposing Wynaut!");
        MESSAGE("A critical hit on Wobbuffet!");
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        // Surf against one opponent and one partner
        MESSAGE("A critical hit on Wobbuffet!");
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        // Dazzling Gleam against one target
        MESSAGE("A critical hit!");
    }
}
