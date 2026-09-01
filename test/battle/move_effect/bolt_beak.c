#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bolt Beak's base power is doubled if it attacks before the target", s16 damage)
{
    u32 speed;
    PARAMETRIZE { speed = 1; }
    PARAMETRIZE { speed = 3; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BOLT_BEAK) == EFFECT_BOLT_BEAK);
        PLAYER(SPECIES_DRACOZOLT) { Speed(speed); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_BOLT_BEAK); }
    } SCENE {
        if (speed == 1) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BOLT_BEAK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (speed == 3) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Bolt Beak's base power is doubled the target switches out", s16 damage)
{
    bool32 switchOut;
    PARAMETRIZE { switchOut = FALSE; }
    PARAMETRIZE { switchOut = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BOLT_BEAK) == EFFECT_BOLT_BEAK);
        PLAYER(SPECIES_DRACOZOLT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_BOLT_BEAK);
            if (switchOut)
                SWITCH(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BOLT_BEAK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
