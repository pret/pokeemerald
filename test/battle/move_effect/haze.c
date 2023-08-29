#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_HAZE].effect == EFFECT_HAZE);
}

SINGLE_BATTLE_TEST("Haze resets stat changes", s16 damage)
{
    bool32 haze;
    PARAMETRIZE { haze = FALSE; }
    PARAMETRIZE { haze = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MEDITATE].effect == EFFECT_ATTACK_UP);
        ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (haze) TURN { MOVE(player, MOVE_MEDITATE); MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (haze) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponent);
            MESSAGE("All stat changes were eliminated!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
