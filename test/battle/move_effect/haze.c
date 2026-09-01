#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HAZE) == EFFECT_HAZE);
}

SINGLE_BATTLE_TEST("Haze resets stat changes", s16 damage)
{
    bool32 haze;
    PARAMETRIZE { haze = FALSE; }
    PARAMETRIZE { haze = TRUE; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_MEDITATE, attack: +1);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (haze) TURN { MOVE(player, MOVE_MEDITATE); MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (haze) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
            MESSAGE("All stat changes were eliminated!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Haze resets Focus Energy (Gen 1 and 4)")
TO_DO_BATTLE_TEST("Haze doesn't reset Focus Energy (Gen 2-3 and 5+)")
