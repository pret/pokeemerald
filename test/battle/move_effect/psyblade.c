#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PSYBLADE) == EFFECT_TERRAIN_BOOST);
}

SINGLE_BATTLE_TEST("Psyblade's power increases by 50% on Electric Terrain even if the user is not grounded", s16 damage)
{
    bool32 terrain, airBalloon;

    PARAMETRIZE { terrain = FALSE; airBalloon = FALSE; }
    PARAMETRIZE { terrain = TRUE;  airBalloon = FALSE; }
    PARAMETRIZE { terrain = FALSE; airBalloon = TRUE; }
    PARAMETRIZE { terrain = TRUE;  airBalloon = TRUE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        ASSUME(GetMoveEffect(MOVE_ELECTRIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        ASSUME(GetMoveTerrainBoost_Terrain(MOVE_PSYBLADE) == B_TERRAIN_ELECTRIC);
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_PSYBLADE) == GROUND_CHECK_NONE);
        PLAYER(SPECIES_SLOWKING) { Moves(MOVE_ELECTRIC_TERRAIN, MOVE_PSYBLADE); Item(airBalloon ? ITEM_AIR_BALLOON : ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_PSYBLADE); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYBLADE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}
