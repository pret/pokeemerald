#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Contrary raises Attack when Intimidated in a single battle", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        PLAYER(SPECIES_MIGHTYENA) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        if (ability == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack fell!");
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], (ability == ABILITY_CONTRARY) ? DEFAULT_STAT_STAGE + 1 : DEFAULT_STAT_STAGE - 1);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.25), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Contrary raises Attack when Intimidated in a double battle", s16 damageLeft, s16 damageRight)
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_CONTRARY; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_CONTRARY; }

    GIVEN {
        PLAYER(SPECIES_MIGHTYENA) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SPINDA) { Ability(abilityLeft); }
        OPPONENT(SPECIES_SPINDA) { Ability(abilityRight); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        if (abilityLeft == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Spinda's Attack fell!");
        }
        if (abilityRight == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Spinda's Attack fell!");
        }
        HP_BAR(playerLeft, captureDamage: &results[i].damageLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damageRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK],  (abilityLeft == ABILITY_CONTRARY)  ? DEFAULT_STAT_STAGE+1 : DEFAULT_STAT_STAGE-1);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], (abilityRight == ABILITY_CONTRARY) ? DEFAULT_STAT_STAGE+1 : DEFAULT_STAT_STAGE-1);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damageLeft, Q_4_12(2.25), results[0].damageLeft);
        EXPECT_MUL_EQ(results[1].damageRight, Q_4_12(2.25), results[0].damageRight);
    }
}

SINGLE_BATTLE_TEST("Contrary raises stats after using a move which would normally lower them: Overheat", s16 damageBefore, s16 damageAfter)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_OVERHEAT, self: TRUE, spAtk: -2);
        ASSUME(GetMoveCategory(MOVE_OVERHEAT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SPINDA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_OVERHEAT); }
        TURN { MOVE(opponent, MOVE_OVERHEAT); }
    } SCENE {
        MESSAGE("The opposing Spinda used Overheat!");
        HP_BAR(player, captureDamage: &results[i].damageBefore);
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Sp. Atk rose sharply!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Sp. Atk harshly fell!");
        }

        // MESSAGE("The opposing Spinda used Overheat!");
        HP_BAR(player, captureDamage: &results[i].damageAfter);
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Sp. Atk rose sharply!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Sp. Atk harshly fell!");
        }
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, Q_4_12(2.0), results[0].damageAfter);
        EXPECT_MUL_EQ(results[1].damageBefore,  Q_4_12(0.5), results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Contrary lowers a stat after using a move which would normally raise it: Swords Dance", s16 damageBefore, s16 damageAfter)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET) { Defense(102); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); Attack(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The opposing Spinda used Scratch!");
        HP_BAR(player, captureDamage: &results[i].damageBefore);

        //MESSAGE("The opposing Spinda used Swords Dance!");
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack harshly fell!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack rose sharply!");
        }

        // MESSAGE("The opposing Spinda used Scratch!");
        HP_BAR(player, captureDamage: &results[i].damageAfter);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, Q_4_12(0.5), results[0].damageAfter);
        EXPECT_MUL_EQ(results[1].damageBefore,  Q_4_12(2.0), results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Contrary raises a stat after using a move which would normally lower it: Growl", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_SPINDA) { Ability(ability); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Growl!");
        if (ability == ABILITY_CONTRARY) {
            // ABILITY_POPUP(opponent, ABILITY_CONTRARY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack rose!");
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda's Attack fell!");
        }

        MESSAGE("The opposing Spinda used Scratch!");
        HP_BAR(player, captureDamage: &results[i].damage);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2.125), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Contrary lowers a stat after using a move which would normally raise it: Belly Drum", s16 damageBefore, s16 damageAfter)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    PARAMETRIZE { ability = ABILITY_TANGLED_FEET; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SPINDA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_BELLY_DRUM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The opposing Spinda used Scratch!");
        HP_BAR(player, captureDamage: &results[i].damageBefore);

        if (ability == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda cut its own HP and maximized its Attack!"); //Message stays the same
        }
        else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Spinda cut its own HP and maximized its Attack!");
        }

        HP_BAR(player, captureDamage: &results[i].damageAfter);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, UQ_4_12(0.25), results[0].damageAfter);
        EXPECT_MUL_EQ(results[1].damageBefore, UQ_4_12(4.0), results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Sticky Web raises Speed by 1 for Contrary mon on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        MESSAGE("A sticky web has been laid out on the ground on the opposing side!");
        MESSAGE("2 sent out Snivy!");
        MESSAGE("The opposing Snivy was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Speed rose!");
    }
}

AI_SINGLE_BATTLE_TEST("AI sees Contrary-effected moves correctly in MoveEffectInPlus instead of as a neutral effect")
{
    GIVEN{
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_HERACROSS) {
            Level(44);
            HP(1);
            Speed(5);
            Nature(NATURE_ADAMANT);
            Item(ITEM_LOADED_DICE);
            Moves(MOVE_PIN_MISSILE);
        }
        OPPONENT(SPECIES_SERPERIOR) {
            Level(44);
            Speed(10);
            Nature(NATURE_TIMID);
            Ability(ABILITY_CONTRARY);
            Moves(MOVE_DRAGON_PULSE, MOVE_SPIN_OUT, MOVE_HIDDEN_POWER, MOVE_GLARE);
        }
    } WHEN {
        TURN {
            MOVE(player, MOVE_PIN_MISSILE);
            EXPECT_MOVE(opponent, MOVE_SPIN_OUT); // previously all 107, now sees speed can rise w/ Contrary
        }
    }
}

SINGLE_BATTLE_TEST("Contrary does not invert stat changes that have been Baton-passed")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Snivy!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

TO_DO_BATTLE_TEST("Contrary inverts stat changes from X Attack and other stat-boosting items.")
