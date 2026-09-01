#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Water Sport (Move Effect) test titles")

SINGLE_BATTLE_TEST("Water Sport reduces the damage of Fire Type moves by 50% (Gen3-4) or 67% (Gen5+)")
{
    u32 config;
    s16 playerDmg[2];
    s16 opponentDmg[2];
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_SPORT_DMG_REDUCTION, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_PLEDGE); MOVE(opponent, MOVE_FIRE_PLEDGE); }
        TURN { MOVE(player, MOVE_WATER_SPORT); }
        TURN { MOVE(player, MOVE_FIRE_PLEDGE); MOVE(opponent, MOVE_FIRE_PLEDGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, player);
        HP_BAR(opponent, captureDamage: &opponentDmg[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponent);
        HP_BAR(player, captureDamage: &playerDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_SPORT, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, player);
        HP_BAR(opponent, captureDamage: &opponentDmg[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponent);
        HP_BAR(player, captureDamage: &playerDmg[1]);

    } THEN {
        if (config >= GEN_5) {
            EXPECT_MUL_EQ(opponentDmg[0], Q_4_12(0.33), opponentDmg[1]);
            EXPECT_MUL_EQ(playerDmg[0], Q_4_12(0.33), playerDmg[1]);
        }
        else {
            EXPECT_MUL_EQ(opponentDmg[0], Q_4_12(0.5), opponentDmg[1]);
            EXPECT_MUL_EQ(playerDmg[0], Q_4_12(0.5), playerDmg[1]);
        }
    }
}
