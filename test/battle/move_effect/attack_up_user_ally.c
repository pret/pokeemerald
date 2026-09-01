#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Howl raises user's Attack by 1 stage", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_HOWL, attack: +1);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_HOWL); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Attack rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Howl raises user's and partner's Attack by 1 stage", s16 damageLeft, s16 damageRight)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HOWL) == TARGET_USER_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(15); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(13); }
        OPPONENT(SPECIES_WYNAUT) { Speed(12); }
    } WHEN {
        if (raiseAttack) TURN { MOVE(playerLeft, MOVE_HOWL); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Attack rose!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Wynaut's Attack rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damageLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentRight, captureDamage: &results[i].damageRight);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damageLeft, Q_4_12(1.5), results[1].damageLeft);
        EXPECT_MUL_EQ(results[0].damageRight, Q_4_12(1.5), results[1].damageRight);
    }
}

DOUBLE_BATTLE_TEST("Howl does not work on partner if it has Soundproof but doesn't fail on user with Soundproof")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HOWL) == TARGET_USER_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_EXPLOUD) { Speed(15); Ability(ABILITY_SOUNDPROOF); }
        PLAYER(SPECIES_VOLTORB) { Speed(10); Ability(ABILITY_SOUNDPROOF); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_HOWL); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_SOUNDPROOF);
            MESSAGE("It doesn't affect Exploud…");
        }
        ABILITY_POPUP(playerRight, ABILITY_SOUNDPROOF);
        MESSAGE("It doesn't affect Voltorb…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Exploud's Attack rose!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

DOUBLE_BATTLE_TEST("Howl ignores user's Substitute and partner's Substitute is ignored from Champions onwards")
{
    bool32 isChampionsOnwards = B_UPDATED_MOVE_FLAGS >= GEN_CHAMPIONS;

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HOWL) == TARGET_USER_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Speed(15); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(13); }
        OPPONENT(SPECIES_WYNAUT) { Speed(12); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SUBSTITUTE); MOVE(playerRight, MOVE_SUBSTITUTE); }
        TURN { MOVE(playerLeft, MOVE_HOWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (isChampionsOnwards)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        else
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);

    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        if (isChampionsOnwards)
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        else
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
