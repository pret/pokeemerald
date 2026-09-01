#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Mud Sport (Move Effect) test titles")

SINGLE_BATTLE_TEST("Mud Sport reduces the damage of Electric Type moves by 50% (Gen3-4) or 67% (Gen5+)")
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
        TURN { MOVE(player, MOVE_SHOCK_WAVE); MOVE(opponent, MOVE_SHOCK_WAVE); }
        TURN { MOVE(player, MOVE_MUD_SPORT); }
        TURN { MOVE(player, MOVE_SHOCK_WAVE); MOVE(opponent, MOVE_SHOCK_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, player);
        HP_BAR(opponent, captureDamage: &opponentDmg[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, opponent);
        HP_BAR(player, captureDamage: &playerDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SPORT, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, player);
        HP_BAR(opponent, captureDamage: &opponentDmg[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, opponent);
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
