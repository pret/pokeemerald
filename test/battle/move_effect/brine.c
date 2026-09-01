#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Brine's power doubles if the target is at 50% or below max HP", s16 damage)
{
    bool32 halfHP;
    PARAMETRIZE { halfHP = FALSE; }
    PARAMETRIZE { halfHP = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BRINE) == EFFECT_BRINE);
        PLAYER(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_BLISSEY){
            if (halfHP) {
                HP((GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP) / 2) - 1);
            }
        }
    } WHEN {
        TURN { MOVE(player, MOVE_BRINE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BRINE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
