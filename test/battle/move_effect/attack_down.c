#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
}

SINGLE_BATTLE_TEST("Growl lowers Attack", s16 damage)
{
    bool32 lowerAttack;
    PARAMETRIZE { lowerAttack = FALSE; }
    PARAMETRIZE { lowerAttack = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (lowerAttack) TURN { MOVE(player, MOVE_GROWL); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (lowerAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Wobbuffet's Attack fell!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
