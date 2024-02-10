#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Opportunist only copies foe's positive stat changes in a turn", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_FRISK; }
    PARAMETRIZE { ability = ABILITY_OPPORTUNIST; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_ESPATHRA) { Speed(5); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_FRISK) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SMASH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        }
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        // stat boosts should be the same
        EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
        EXPECT_EQ(player->statStages[STAT_SPATK], opponent->statStages[STAT_SPATK]);
        EXPECT_EQ(player->statStages[STAT_SPEED], opponent->statStages[STAT_SPEED]);
        // opportunist should not copy stat drops from shell smash
        EXPECT_LT(player->statStages[STAT_DEF], opponent->statStages[STAT_DEF]);
        EXPECT_LT(player->statStages[STAT_SPDEF], opponent->statStages[STAT_SPDEF]);
    }
}


DOUBLE_BATTLE_TEST("Opportunist raises Attack only once when partner has Intimidate against Contrary foe in a double battle", s16 damageLeft, s16 damageRight)
{
    u32 abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_CONTRARY; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_CONTRARY; }

    GIVEN {
        PLAYER(SPECIES_MIGHTYENA) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_SPINDA) { Ability(abilityLeft); }
        OPPONENT(SPECIES_SPINDA) { Ability(abilityRight); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(opponentRight, MOVE_TACKLE, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        if (abilityLeft == ABILITY_CONTRARY) {
            ABILITY_POPUP(opponentLeft, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Mightyena's Intimidate cuts Foe Spinda's attack!");
        }
        if (abilityRight == ABILITY_CONTRARY) {
            ABILITY_POPUP(opponentRight, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("Foe Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("Mightyena's Intimidate cuts Foe Spinda's attack!");
        }

        if ((abilityLeft == ABILITY_CONTRARY && abilityRight != ABILITY_CONTRARY)
                || (abilityLeft != ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY)) {
            ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
            MESSAGE("Espathra copied its opponent's stat changes!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Espathra's Attack rose!");
        } else if (abilityLeft == ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY) {
            ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
            MESSAGE("Espathra copied its opponent's stat changes!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Espathra's Attack sharply rose!");
        }

        HP_BAR(playerLeft, captureDamage: &results[i].damageLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damageRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK],  DEFAULT_STAT_STAGE + (abilityLeft  == ABILITY_CONTRARY ? 1 : - 1));
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (abilityRight == ABILITY_CONTRARY ? 1 : - 1));
        if ((abilityLeft == ABILITY_CONTRARY && abilityRight != ABILITY_CONTRARY)
                || (abilityLeft != ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY)) {
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        } else if (abilityLeft == ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY) {
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        }
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damageLeft, Q_4_12(2.25), results[0].damageLeft);
        EXPECT_MUL_EQ(results[1].damageRight, Q_4_12(2.25), results[0].damageRight);
    }
}

SINGLE_BATTLE_TEST("Opportunist does not accumulate opposing mon's stat changes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 4);
    }
}

TO_DO_BATTLE_TEST("Opportunist doesn't copy ally stat increases");
TO_DO_BATTLE_TEST("Opportunist doesn't copy foe stat increases gained via Opportunist");
TO_DO_BATTLE_TEST("Opportunist copies foe stat increased gained via Swagger and Flatter");
