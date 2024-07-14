#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_UPPER_HAND].effect == EFFECT_UPPER_HAND);
    ASSUME(gMovesInfo[MOVE_UPPER_HAND].priority == 3);
    ASSUME(MoveHasAdditionalEffect(MOVE_UPPER_HAND, MOVE_EFFECT_FLINCH) == TRUE);
}

SINGLE_BATTLE_TEST("Upper Hand succeeds if the target is using a priority attacking move and causes it to flinch")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXTREME_SPEED].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_EXTREME_SPEED].priority == 2);
        PLAYER(SPECIES_MIENSHAO);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet flinched!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTREME_SPEED, opponent);
    }
}

SINGLE_BATTLE_TEST("Upper Hand fails if the target is using a status move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_BABY_DOLL_EYES].category == DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_BABY_DOLL_EYES].priority == 1);
        PLAYER(SPECIES_MIENSHAO);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BABY_DOLL_EYES); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        MESSAGE("Mienshao used Upper Hand!");
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BABY_DOLL_EYES, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Mienshao's Attack fell!");
    }
}

SINGLE_BATTLE_TEST("Upper Hand fails if the target is not using a priority move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].priority == 0);
        PLAYER(SPECIES_MIENSHAO);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAINING_KISS); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        MESSAGE("Mienshao used Upper Hand!");
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAINING_KISS, opponent);
        HP_BAR(player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Upper Hand succeeds if the target's move is boosted in priority by an Ability")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].priority == 0);
        PLAYER(SPECIES_MIENSHAO) { Speed(10); }
        OPPONENT(SPECIES_COMFEY) { Speed(5); Ability(ABILITY_TRIAGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAINING_KISS); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        HP_BAR(opponent);
        MESSAGE("Foe Comfey flinched!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAINING_KISS, opponent);
    }
}

SINGLE_BATTLE_TEST("Upper Hand fails if the target moves first")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_DRAINING_KISS].priority == 0);
        PLAYER(SPECIES_MIENSHAO) { Speed(5); }
        OPPONENT(SPECIES_COMFEY) { Speed(10); Ability(ABILITY_TRIAGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAINING_KISS); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAINING_KISS, opponent);
        HP_BAR(player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        MESSAGE("Mienshao used Upper Hand!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Upper Hand is boosted by Sheer Force")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXTREME_SPEED].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_EXTREME_SPEED].priority == 2);
        ASSUME(MoveIsAffectedBySheerForce(MOVE_UPPER_HAND) == TRUE);
        PLAYER(SPECIES_HARIYAMA) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPPER_HAND, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTREME_SPEED, opponent);
        HP_BAR(player);
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use Upper Hand unless it has seen a priority move")
{
    u16 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority == 1);
        PLAYER(SPECIES_WOBBUFFET) {Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_UPPER_HAND, MOVE_KARATE_CHOP); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, MOVE_KARATE_CHOP); }
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, move == MOVE_QUICK_ATTACK ? MOVE_UPPER_HAND : MOVE_KARATE_CHOP); }
    }
}
