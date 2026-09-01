#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Terrain Boost: Expanding Force's power increases by 50% if the user is affected by Psychic Terrain", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EXPANDING_FORCE) == EFFECT_TERRAIN_BOOST);
        ASSUME(GetMoveTerrainBoost_Percent(MOVE_EXPANDING_FORCE) == 50);
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_EXPANDING_FORCE) == GROUND_CHECK_USER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_EXPANDING_FORCE); }
    } SCENE {
        MESSAGE("Wobbuffet used Expanding Force!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_TERRAIN_TYPE_BOOST >= GEN_8)
            // 1.3 Terrain boost x 1.5 effect boost = 1.95 boost
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.95), results[1].damage);
        else
            // 1.5 Terrain boost x 1.5 effect boost = 2.25 boost
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.25), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Terrain Boost: Expanding Force hits both foes in Psychic Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EXPANDING_FORCE) == EFFECT_TERRAIN_BOOST);
        ASSUME(GetMoveTerrainBoost_HitsBothFoes(MOVE_EXPANDING_FORCE));
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_EXPANDING_FORCE) == GROUND_CHECK_USER);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPANDING_FORCE, target: opponentLeft); MOVE(playerRight, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(playerLeft, MOVE_EXPANDING_FORCE, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPANDING_FORCE, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPANDING_FORCE, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Terrain Boost: Rising Voltage doubles in power if target is grounded")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RISING_VOLTAGE) == EFFECT_TERRAIN_BOOST);
        ASSUME(GetMoveTerrainBoost_Percent(MOVE_RISING_VOLTAGE) == 100);
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_RISING_VOLTAGE) == GROUND_CHECK_TARGET);
        PLAYER(SPECIES_PIDGEY); // User flying type so there is no 30% electric terrain boost
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RISING_VOLTAGE); MOVE(opponent, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_RISING_VOLTAGE); MOVE(opponent, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_RISING_VOLTAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RISING_VOLTAGE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_RISING_VOLTAGE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_RISING_VOLTAGE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(2.0), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("Terrain Boost: Misty Explosion increases in power by 50% when affected by Misty Terrain")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MISTY_EXPLOSION) == EFFECT_TERRAIN_BOOST);
        ASSUME(GetMoveTerrainBoost_Percent(MOVE_MISTY_EXPLOSION) == 50);
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_MISTY_EXPLOSION) == GROUND_CHECK_USER);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_EXPLOSION); SEND_OUT(player, 1); MOVE(opponent, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_MISTY_EXPLOSION); SEND_OUT(player, 2); }
        TURN { MOVE(player, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_MISTY_EXPLOSION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_EXPLOSION, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_EXPLOSION, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_EXPLOSION, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.5), damage[1]);
        EXPECT_EQ(damage[0], damage[2]);
    }
}

SINGLE_BATTLE_TEST("Terrain Boost: Psyblade power increases by 50% regardless if user is grounded or not")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYBLADE) == EFFECT_TERRAIN_BOOST);
        ASSUME(GetMoveTerrainBoost_Percent(MOVE_PSYBLADE) == 50);
        ASSUME(GetMoveTerrainBoost_GroundCheck(MOVE_PSYBLADE) == GROUND_CHECK_NONE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYBLADE); MOVE(opponent, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_PSYBLADE); MOVE(opponent, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_PSYBLADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYBLADE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYBLADE, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYBLADE, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.5), damage[1]);
        EXPECT_EQ(damage[1], damage[2]);
    }
}
