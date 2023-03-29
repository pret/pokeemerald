#include "global.h"
#include "test_battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TRIPLE_ARROWS].effect == EFFECT_TRIPLE_ARROWS);
}

SINGLE_BATTLE_TEST("Triple Arrows lower's defense by one stage")
{
    PASSES_RANDOMLY(50, 100, RNG_TRIPLE_ARROWS);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's defense fell!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows flinch 30% of the time")
{
    PASSES_RANDOMLY(30, 100, RNG_TRIPLE_ARROWS);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Wobbuffet's defense fell!");
        }
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows lands a critical hit")
{
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    ASSUME(gBattleMoves[MOVE_TRIPLE_ARROWS].flags & FLAG_HIGH_CRIT);
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        MESSAGE("A critical hit!");
    }
}