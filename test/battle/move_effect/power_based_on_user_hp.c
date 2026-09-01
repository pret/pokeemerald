#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ERUPTION) == EFFECT_POWER_BASED_ON_USER_HP);
}

SINGLE_BATTLE_TEST("Eruption's damage is affected by the user's current HP", s16 damage)
{
    s16 hp, maxHp = 256;

    PARAMETRIZE { hp = maxHp; }
    PARAMETRIZE { hp = maxHp / 2; }
    PARAMETRIZE { hp = maxHp / 8; }
    PARAMETRIZE { hp = 1; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); MaxHP(maxHp); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ERUPTION); }
    } SCENE {
        MESSAGE("Wobbuffet used Eruption!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ERUPTION, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.125), results[2].damage);
        EXPECT_EQ(results[3].damage, 1);
    }
}
