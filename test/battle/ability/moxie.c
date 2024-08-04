#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Moxie raises Attack by one stage after directly causing a Pokemon to faint")
{
    ASSUME(gMovesInfo[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);

    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); }
        PLAYER(SPECIES_SNORUNT) { HP(1); }
        OPPONENT(SPECIES_GLALIE) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); SEND_OUT(opponentLeft, 2);  }
    } SCENE {
        int i;

        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        for (i = 0; i < 3; i++) {
            ONE_OF {
                MESSAGE("Snorunt fainted!");
                MESSAGE("Foe Glalie fainted!");
                MESSAGE("Foe Abra fainted!");
            }
            ABILITY_POPUP(playerLeft, ABILITY_MOXIE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Salamence's Moxie raised its Attack!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
    }
}

DOUBLE_BATTLE_TEST("Moxie does not trigger if Pokemon faint to indirect damage or damage from other Pokemon")
{
    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); }
        PLAYER(SPECIES_SNORUNT) { HP(1); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_GLALIE) { HP(1); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentRight); SEND_OUT(opponentLeft, 2);  }
    } SCENE {
        int i;

        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
        for (i = 0; i < 3; i++) {
            ONE_OF {
                MESSAGE("Snorunt fainted!");
                MESSAGE("Foe Glalie fainted!");
                MESSAGE("Foe Abra fainted!");
            }
            NONE_OF {
                ABILITY_POPUP(playerLeft, ABILITY_MOXIE);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Salamence's Moxie raised its Attack!");
            }
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Moxie does not trigger when already at maximum Attack stage")
{
    ASSUME(gMovesInfo[MOVE_BELLY_DRUM].effect == EFFECT_BELLY_DRUM);

    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); }
        OPPONENT(SPECIES_SNORUNT) { HP(1); }
        OPPONENT(SPECIES_SNORUNT);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Salamence cut its own HP and maximized ATTACK!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        MESSAGE("Foe Snorunt fainted!");
        NONE_OF {    
            ABILITY_POPUP(player, ABILITY_MOXIE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Salamence's Moxie raised its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Moxie does not increase damage done by the same move that causes another Pokemon to faint")
{
    s16 damage[2];

    ASSUME(gMovesInfo[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);

    KNOWN_FAILING; // Requires simultaneous damage implementation
    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Ability(ABILITY_MOXIE); }
        PLAYER(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_GLALIE);
        OPPONENT(SPECIES_GLALIE);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(playerRight);
        MESSAGE("Abra fainted!");
        ABILITY_POPUP(playerLeft, ABILITY_MOXIE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Salamence's Moxie raised its Attack!");
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(damage[0], damage[1]);
    }
}
