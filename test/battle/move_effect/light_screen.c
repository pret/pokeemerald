#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_LIGHT_SCREEN) == EFFECT_LIGHT_SCREEN);
}

SINGLE_BATTLE_TEST("Light Screen reduces special damage", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Light Screen applies for 5 turns")
{
    s16 damage[6];
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LIGHT_SCREEN); MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[2]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[3]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[4]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[5]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.0), damage[1]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.0), damage[2]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.0), damage[3]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.0), damage[4]);
        EXPECT_LT(damage[0], damage[5]);
    }
}

SINGLE_BATTLE_TEST("Light Screen fails if already active")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(player, MOVE_LIGHT_SCREEN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, player);
        MESSAGE("Wobbuffet used Light Screen!");
        MESSAGE("But it failed!");
    }
}
