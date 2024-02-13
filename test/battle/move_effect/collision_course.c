#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_COLLISION_COURSE].effect == EFFECT_COLLISION_COURSE);
}

SINGLE_BATTLE_TEST("Collision Course damage is increased by 33 Percent if super effective", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_HAMMER_ARM; }
    PARAMETRIZE { move = MOVE_COLLISION_COURSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3333), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Collision Course does normal damage if not super effective", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_HAMMER_ARM; }
    PARAMETRIZE { move = MOVE_COLLISION_COURSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
