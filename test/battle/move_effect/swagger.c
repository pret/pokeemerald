#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SWAGGER) == EFFECT_SWAGGER);
}

SINGLE_BATTLE_TEST("Swagger increases the target's Attack by 2 stages and confuses them")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWAGGER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWAGGER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT(opponent->volatiles.confusionTimer > 0);
    }
}

TO_DO_BATTLE_TEST("Swagger raises the target's Attack even if they're already confused")
TO_DO_BATTLE_TEST("Swagger raises the target's Attack even when protected by Safeguard")

SINGLE_BATTLE_TEST("Swagger raises the target's Attack even when protected Own Tempo")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWBRO) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWAGGER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWAGGER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT(opponent->volatiles.confusionTimer == 0);
    }
}

TO_DO_BATTLE_TEST("Swagger doesn't confuse the target when they have their Attack maxed (Gen2)")
TO_DO_BATTLE_TEST("Swagger confuses the target even when they have their Attack maxed (Gen3+)")
TO_DO_BATTLE_TEST("Swagger confuses the target even when at -6 Attack and has Contrary")
