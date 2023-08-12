#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_HOWL].effect == EFFECT_ATTACK_UP_USER_ALLY);
}

SINGLE_BATTLE_TEST("Howl raises user's Attack", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_HOWL); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Attack rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Howl raises user's and partner's Attack", s16 damageLeft, s16 damageRight)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(15); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(13); }
        OPPONENT(SPECIES_WYNAUT) { Speed(12); }
    } WHEN {
        if (raiseAttack) TURN { MOVE(playerLeft, MOVE_HOWL); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Attack rose!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Wynaut's Attack rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damageLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        HP_BAR(opponentRight, captureDamage: &results[i].damageRight);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damageLeft, Q_4_12(1.5), results[1].damageLeft);
        EXPECT_MUL_EQ(results[0].damageRight, Q_4_12(1.5), results[1].damageRight);
    }
}
