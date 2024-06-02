#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Earthquake's and Bulldoze's damage is halved when Grassy Terrain is in effect", s16 damage)
{
    bool32 terrain;
    u16 move;
    PARAMETRIZE { terrain = FALSE; move = MOVE_EARTHQUAKE; } // 0
    PARAMETRIZE { terrain = TRUE; move = MOVE_EARTHQUAKE; } // 1
    PARAMETRIZE { terrain = FALSE; move = MOVE_BULLDOZE; } // 2
    PARAMETRIZE { terrain = TRUE; move = MOVE_BULLDOZE; } // 3
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].effect == EFFECT_EARTHQUAKE);
        ASSUME(gMovesInfo[MOVE_BULLDOZE].effect == EFFECT_EARTHQUAKE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.5), results[3].damage);
    }
}
