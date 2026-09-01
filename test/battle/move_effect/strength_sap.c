#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STRENGTH_SAP) == EFFECT_STRENGTH_SAP);
}

SINGLE_BATTLE_TEST("Strength Sap lowers Attack by 1 and restores HP based on target's Attack Stat", s16 hp)
{
    u32 atkStat = 0;

    PARAMETRIZE { atkStat = 100; }
    PARAMETRIZE { atkStat = 50; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atkStat); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        MESSAGE("The opposing Wobbuffet had its energy drained!");
    } THEN {
        EXPECT_EQ(results[i].hp * -1, atkStat);
    }
}

// Same as above, but Substitute is used before Strength Sap.
SINGLE_BATTLE_TEST("Strength Sap works exactly the same when attacker is behind substitute", s16 hp)
{
    u32 atkStat = 0;

    PARAMETRIZE { atkStat = 100; }
    PARAMETRIZE { atkStat = 50; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atkStat); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        NOT MESSAGE("The substitute took damage for the opposing Wobbuffet!");
        MESSAGE("The opposing Wobbuffet had its energy drained!");
    } THEN {
        EXPECT_EQ(results[i].hp * -1, atkStat);
    }
}

// This test checks all stat stages from -6 to +6.
SINGLE_BATTLE_TEST("Strength Sap lowers Attack by 1 and restores HP based on target's Attack Stat and stat Change", s16 hp)
{
    s32 j = 0, statStage = 0;

    for (j = 0; j <= MAX_STAT_STAGE; j++) {
        if (j == DEFAULT_STAT_STAGE - 1) { continue; } // Ignore -6, because Strength Sap won't work otherwise
        PARAMETRIZE { statStage = j; }
    }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_WORK_UP, attack: +1, spAtk: +1);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(60); }
    } WHEN {
        if (statStage > DEFAULT_STAT_STAGE) { // +
            for (j = statStage; j > DEFAULT_STAT_STAGE; j--) {
                TURN { MOVE(opponent, MOVE_HOWL); }
            }
        } else if (statStage < DEFAULT_STAT_STAGE) { // -
            for (j = statStage; j < DEFAULT_STAT_STAGE - 1; j++) { // - 1 because Strength Sap always lowers Attack
                TURN { MOVE(player, MOVE_GROWL); }
            }
        }
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        if (statStage > DEFAULT_STAT_STAGE) { // +
            for (j = statStage; j > DEFAULT_STAT_STAGE; j--) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_HOWL, opponent);
            }
        } else if (statStage < DEFAULT_STAT_STAGE) { // -
            for (j = statStage; j < DEFAULT_STAT_STAGE - 1; j++) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
            }
        }
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        MESSAGE("The opposing Wobbuffet had its energy drained!");
    } THEN {
        if (statStage < DEFAULT_STAT_STAGE) {
            EXPECT_EQ(results[i].hp * -1, (60 * gStatStageRatios[statStage + 1][0] / gStatStageRatios[statStage + 1][1]));
        } else {
            EXPECT_EQ(results[i].hp * -1, (60 * gStatStageRatios[statStage][0] / gStatStageRatios[statStage][1]));
        }
    } FINALLY {
        // This makes sure gStatStageRatios works correctly and the lower the attack stage the lower hp obtained.
        for (j = 0; j < MAX_STAT_STAGE - 1; j++) {
            EXPECT_GT(abs(results[j + 1].hp), abs(results[j].hp));
        }
    }
}

SINGLE_BATTLE_TEST("Strength Sap fails if target is at -6 Atk")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        MESSAGE("Wobbuffet used Strength Sap!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Attack fell!");
            HP_BAR(player);
            MESSAGE("The opposing Wobbuffet had its energy drained!");
        }
        MESSAGE("The opposing Wobbuffet's Attack won't go any lower!");
    }
}

SINGLE_BATTLE_TEST("Strength Sap will restore hp if target has Contrary and is at +6 Atk")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, opponent);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Strength Sap restores more HP if Big Root is held", s16 hp)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_BIG_ROOT].holdEffect == HOLD_EFFECT_BIG_ROOT);
        PLAYER(SPECIES_WOBBUFFET) { HP(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        MESSAGE("The opposing Wobbuffet had its energy drained!");
    } FINALLY {
        EXPECT_GT(abs(results[1].hp), abs(results[0].hp));
    }
}

SINGLE_BATTLE_TEST("Strength Sap will not drain users hp due to Liquid Ooze if user is Magic Guard protected")
{
    GIVEN {
        PLAYER(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
        OPPONENT(SPECIES_CLEFAIRY) { HP(1); Ability(ABILITY_MAGIC_GUARD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, opponent);
        ABILITY_POPUP(player, ABILITY_LIQUID_OOZE);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Strength Sap does not fail if target has Contrary and is at +6 Atk")
{
    GIVEN {
        PLAYER(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, opponent);
    }
}

SINGLE_BATTLE_TEST("Strength Sap does not fail if user is at full hp and target has Clear Body")
{
    GIVEN {
        PLAYER(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, opponent);
    }
}

SINGLE_BATTLE_TEST("Strength Sap fails if Heal Block applies")
{
    GIVEN {
        ASSUME(B_HEAL_BLOCKING >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
    }
}

SINGLE_BATTLE_TEST("Strength Sap will drain users HP if target has Liquid Ooze")
{
    s16 lostHp;
    s32 atkStat;

    PARAMETRIZE { atkStat = 100; }
    PARAMETRIZE { atkStat = 490; } // Checks that attacker can faint with no problems.

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Attack(atkStat); Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH_SAP); if (atkStat == 490) { SEND_OUT(player, 1); } }
    } SCENE {
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Tentacool's Attack fell!");
        ABILITY_POPUP(opponent, ABILITY_LIQUID_OOZE);
        HP_BAR(player, captureDamage: &lostHp);
        MESSAGE("Wobbuffet sucked up the liquid ooze!");
        if (atkStat >= 490) {
            MESSAGE("Wobbuffet fainted!");
            SEND_IN_MESSAGE("Wobbuffet");
        }
    } THEN {
        EXPECT_EQ(lostHp, atkStat);
    }
}

SINGLE_BATTLE_TEST("Strength Sap fails if move missed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); };
    } WHEN {
        TURN {  MOVE(player, MOVE_STRENGTH_SAP, hit: FALSE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
            HP_BAR(player);
        }
    }
}
