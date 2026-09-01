#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Critical hits without modifiers occur at different rates by generation")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_1; passes = 1;  trials = 16; }   //  6.25% with Wobbuffet's base speed
    PARAMETRIZE { genConfig = GEN_2; passes = 17; trials = 256; }  // ~6.64%
    for (u32 j = GEN_3; j <= GEN_6; j++)
        PARAMETRIZE { genConfig = j; passes = 1,  trials = 16;  }  //  6.25%
    for (u32 j = GEN_7; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; passes = 1,  trials = 24;  }  // ~4.17%

    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_WOBBUFFET) == 33);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Crit Chance: Raising critical hit rate to 3 guarantees a critical hit (Gen 6+)")
{
    u32 genConfig = 0, passes, trials;
    PARAMETRIZE { genConfig = GEN_1; passes = 255; trials = 256; } // ~99.6%
    PARAMETRIZE { genConfig = GEN_2; passes = 85;  trials = 256; } // ~33.2%
    for (u32 j = GEN_3; j <= GEN_5; j++)
        PARAMETRIZE { genConfig = j; passes = 1,   trials = 3; }   // ~33.3%
    for (u32 j = GEN_6; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; passes = 1,   trials = 1; }   // 100%
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveCriticalHitStage(MOVE_SLASH) == 1);
        ASSUME(gItemsInfo[ITEM_SCOPE_LENS].holdEffect == HOLD_EFFECT_SCOPE_LENS);
        PLAYER(SPECIES_TOGEKISS) { Ability(ABILITY_SUPER_LUCK); Item(ITEM_SCOPE_LENS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLASH, player);
        MESSAGE("A critical hit!");
    }
}

#define CRIT_MESSAGE "A critical hit!"
SINGLE_BATTLE_TEST("Crit Change: Fixed damage moves don't print a crit message")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LASER_FOCUS); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_SCRATCH) {
            MESSAGE(CRIT_MESSAGE);
        }
        else {
            NOT MESSAGE(CRIT_MESSAGE);
        }
    }
}
#undef CRIT_MESSAGE
