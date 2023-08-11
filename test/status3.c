#include "global.h"
#include "test_battle.h"

ASSUMPTIONS {
    ASSUME(gBattleMoves[MOVE_MINIMIZE].effect == EFFECT_MINIMIZE);
    ASSUME(gBattleMoves[MOVE_STEAMROLLER].minimizeDoubleDamage);
    ASSUME(gBattleMoves[MOVE_EARTHQUAKE].damagesUnderground);
    ASSUME(gBattleMoves[MOVE_SURF].damagesUnderwater);
    ASSUME(gBattleMoves[MOVE_TWISTER].damagesAirborneDoubleDamage);
}

SINGLE_BATTLE_TEST("Minimize causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useMinimize;
    PARAMETRIZE { useMinimize = FALSE; }
    PARAMETRIZE { useMinimize = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useMinimize)
            TURN { MOVE(opponent, MOVE_MINIMIZE); MOVE(player, MOVE_STEAMROLLER); }
        else
            TURN { MOVE(player, MOVE_STEAMROLLER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Being underground causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useDig;
    PARAMETRIZE { useDig = FALSE; }
    PARAMETRIZE { useDig = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useDig)
            TURN { MOVE(opponent, MOVE_DIG); MOVE(player, MOVE_EARTHQUAKE); }
        else
            TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Being underwater causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useDive;
    PARAMETRIZE { useDive = FALSE; }
    PARAMETRIZE { useDive = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useDive)
            TURN { MOVE(opponent, MOVE_DIVE); MOVE(player, MOVE_SURF); }
        else
            TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Being airborne causes the target to take double damage from certain moves", s16 damage)
{
    bool32 useDive;
    PARAMETRIZE { useDive = FALSE; }
    PARAMETRIZE { useDive = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        if (useDive)
            TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_TWISTER); }
        else
            TURN { MOVE(player, MOVE_TWISTER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}
