#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CRUSH_GRIP) == EFFECT_POWER_BASED_ON_TARGET_HP);
}

SINGLE_BATTLE_TEST("Crush Grip's damage is affected by the target's current HP", s16 damage)
{
    s16 hp, maxHp = 256;

    PARAMETRIZE { hp = maxHp; }
    PARAMETRIZE { hp = maxHp / 2; }
    PARAMETRIZE { hp = maxHp / 8; }
    PARAMETRIZE { hp = 1; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(maxHp); }
    } WHEN {
        TURN { MOVE(player, MOVE_CRUSH_GRIP); }
    } SCENE {
        MESSAGE("Wobbuffet used Crush Grip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUSH_GRIP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.125), results[2].damage);
        EXPECT_EQ(results[3].damage, 1);
    }
}
