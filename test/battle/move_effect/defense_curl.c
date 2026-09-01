#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_DEFENSE_CURL, defense: +1);
}

SINGLE_BATTLE_TEST("Defense Curl raises Defense by 1 stage", s16 damage)
{
    bool32 raiseDefense;
    PARAMETRIZE { raiseDefense = FALSE; }
    PARAMETRIZE { raiseDefense = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseDefense) TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (raiseDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's Defense rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Defense Curl doubles the power of Rollout even if stat couldn't be changed", s16 damage)
{
    bool32 acidArmor = FALSE;

    PARAMETRIZE { acidArmor = TRUE; }
    PARAMETRIZE { acidArmor = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (acidArmor) {
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
            TURN { MOVE(player, MOVE_ACID_ARMOR); }
        }
        TURN { MOVE(player, MOVE_DEFENSE_CURL); }
        TURN { MOVE(player, MOVE_ROLLOUT); }
    } SCENE {
        if (acidArmor) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID_ARMOR, player);
        }

        if (acidArmor) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFENSE_CURL, player);
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Defense Curl doubles the power of Rollout and Ice Ball");
TO_DO_BATTLE_TEST("Defense Curl's effect cannot be stacked");
TO_DO_BATTLE_TEST("Defense Curl's effect is removed when switching out");
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Defense Curl's effect");
