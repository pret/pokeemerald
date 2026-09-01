#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_TRIPLE_ARROWS, defense: -1);
    ASSUME(MoveHasAdditionalEffect(MOVE_TRIPLE_ARROWS, MOVE_EFFECT_FLINCH) == TRUE);
}

SINGLE_BATTLE_TEST("Triple Arrows may lower Defense by one stage")
{
    enum Ability ability;
    u32 chance;
    PARAMETRIZE { ability = ABILITY_HUSTLE; chance = 50; }
    PARAMETRIZE { ability = ABILITY_SERENE_GRACE; chance = 100; }
    PASSES_RANDOMLY(chance, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_TOGEPI) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows makes the foe flinch 30% of the time")
{
    enum Ability ability;
    u32 chance;
    PARAMETRIZE { ability = ABILITY_HUSTLE; chance = 30; }
    PARAMETRIZE { ability = ABILITY_SERENE_GRACE; chance = 60; }
    PASSES_RANDOMLY(chance, 100, RNG_SECONDARY_EFFECT_2);
    GIVEN {
        PLAYER(SPECIES_TOGEPI) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows has an increased critical hit ratio")
{
    u32 j, genConfig = 0, passes = 0, trials = 0;

    PARAMETRIZE { genConfig = GEN_1; passes = 1; trials = 2; }     // 50% with Wobbuffet's base speed
    for (j = GEN_2; j <= GEN_9; j++) {
        PARAMETRIZE { genConfig = GEN_2; passes = 1; trials = 8; }
    }
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveCriticalHitStage(MOVE_TRIPLE_ARROWS) == 1);
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
        MESSAGE("The opposing Wobbuffet's Defense fell!");
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Triple Arrows's flinching is prevented by Inner Focus")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RIOLU) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_ARROWS);
               MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_ARROWS, player);
        NONE_OF { MESSAGE("The opposing Wobbuffet flinched and couldn't move!"); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}
