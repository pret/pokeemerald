#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write No Guard (Ability) test titles")

SINGLE_BATTLE_TEST("No Guard makes opposing status moves hit")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SCREECH) < 100);
        ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}
