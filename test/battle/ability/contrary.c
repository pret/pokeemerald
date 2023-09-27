#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Contrary raises Attack when Intimidated", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        PLAYER(SPECIES_MIGHTYENA) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        if (ability == ABILITY_CONTRARY) {
            ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Attack rose!");
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.25), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Contrary raises stats after using a move which would normally lower them: Overheat", s16 damageBefore, s16 damageAfter)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_OVERHEAT].effect == EFFECT_OVERHEAT);
        ASSUME(gBattleMoves[MOVE_OVERHEAT].split == SPLIT_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SPINDA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_OVERHEAT); }
        TURN { MOVE(opponent, MOVE_OVERHEAT); }
    } SCENE {
        MESSAGE("Foe Spinda used Overheat!");
        HP_BAR(player, captureDamage: &results[i].damageBefore);
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Sp. Atk sharply rose!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Sp. Atk harshly fell!");
        }

        // MESSAGE("Foe Spinda used Overheat!");
        HP_BAR(player, captureDamage: &results[i].damageAfter);
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Sp. Atk sharply rose!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Sp. Atk harshly fell!");
        }
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, Q_4_12(2.0), results[0].damageAfter);
        EXPECT_MUL_EQ(results[1].damageBefore,  Q_4_12(0.5), results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Contrary lowers a stat after using a move which would normally raise it: Swords Dance", s16 damageBefore, s16 damageAfter)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SWORDS_DANCE].effect == EFFECT_ATTACK_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Defense(102); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); Attack(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Foe Spinda used Tackle!");
        HP_BAR(player, captureDamage: &results[i].damageBefore);

        //MESSAGE("Foe Spinda used Swords Dance!");
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Attack harshly fell!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Attack sharply rose!");
        }

        // MESSAGE("Foe Spinda used Tackle!");
        HP_BAR(player, captureDamage: &results[i].damageAfter);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, Q_4_12(0.5), results[0].damageAfter);
        EXPECT_MUL_EQ(results[1].damageBefore,  Q_4_12(2.0), results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Contrary raises a stat after using a move which would normally lower it: Growl", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Growl!");
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Attack rose!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Spinda's Attack fell!");
        }

        MESSAGE("Foe Spinda used Tackle!");
        HP_BAR(player, captureDamage: &results[i].damage);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.125), results[0].damage);
    }
}
