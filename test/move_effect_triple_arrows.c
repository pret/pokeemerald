#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TRIPLE_ARROWS].effect == EFFECT_TRIPLE_ARROWS);
}

SINGLE_BATTLE_TEST("Triple Arrows may lower Defense by one stage")
{
    u32 ability;
    u32 chance;
    PARAMETRIZE { ability = ABILITY_HUSTLE; chance = 50; }
    PARAMETRIZE { ability = ABILITY_SERENE_GRACE; chance = 100; }
    PASSES_RANDOMLY(chance, 100, RNG_TRIPLE_ARROWS_DEFENSE_DOWN);
    GIVEN {
        PLAYER(SPECIES_TOGEPI) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense fell!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows makes the foe flinch 30% of the time")
{
    u32 ability;
    u32 chance;
    PARAMETRIZE { ability = ABILITY_HUSTLE; chance = 30; }
    PARAMETRIZE { ability = ABILITY_SERENE_GRACE; chance = 60; }
    PASSES_RANDOMLY(chance, 100, RNG_TRIPLE_ARROWS_FLINCH);
    GIVEN {
        PLAYER(SPECIES_TOGEPI) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows lands a critical hit")
{
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    ASSUME(gBattleMoves[MOVE_TRIPLE_ARROWS].highCritRatio == TRUE);
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

SINGLE_BATTLE_TEST("Triple Arrows can lower Defense and cause flinch at the time")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense fell!");
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows's flinching is prevented by Inner Focus")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RIOLU) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS);
               MOVE(opponent, MOVE_TACKLE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        NONE_OF { MESSAGE("Foe Wobbuffet flinched!"); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}
