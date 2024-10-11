#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh raises Attack by one stage after directly causing a Pokemon to faint")
{
    u32 species = 0, ability = 0, abilityPopUp = 0;
    PARAMETRIZE { species = SPECIES_SALAMENCE;         ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;         ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE_RIDER; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(species) { Ability(ability); }
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
            ABILITY_POPUP(playerLeft, abilityPopUp);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            if (species == SPECIES_SALAMENCE)
                MESSAGE("Salamence's Moxie raised its Attack!");
            else if (species == SPECIES_GLASTRIER)
                MESSAGE("Glastrier's Chilling Neigh raised its Attack!");
            else
                MESSAGE("Calyrex's Chilling Neigh raised its Attack!");
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
    }
}

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh does not trigger if Pokemon faint to indirect damage or damage from other Pokemon")
{
    u32 species = 0, ability = 0, abilityPopUp = 0;
    PARAMETRIZE { species = SPECIES_SALAMENCE;         ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;         ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE_RIDER; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
    GIVEN {
        PLAYER(species) { Ability(ability); }
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
                ABILITY_POPUP(playerLeft, abilityPopUp);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Salamence's Moxie raised its Attack!");
                MESSAGE("Glastrier's Chilling Neigh raised its Attack!");
                MESSAGE("Calyrex's Chilling Neigh raised its Attack!");
            }
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Moxie/Chilling Neigh does not trigger when already at maximum Attack stage")
{
    u32 species = 0, ability = 0, abilityPopUp = 0;
    PARAMETRIZE { species = SPECIES_SALAMENCE;         ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;         ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE_RIDER; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_BELLY_DRUM].effect == EFFECT_BELLY_DRUM);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_SNORUNT) { HP(1); }
        OPPONENT(SPECIES_SNORUNT);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        if (species == SPECIES_SALAMENCE)
            MESSAGE("Salamence cut its own HP and maximized ATTACK!");
        else if (species == SPECIES_GLASTRIER)
            MESSAGE("Glastrier cut its own HP and maximized ATTACK!");
        else
            MESSAGE("Calyrex cut its own HP and maximized ATTACK!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        MESSAGE("Foe Snorunt fainted!");
        NONE_OF {
            ABILITY_POPUP(player, abilityPopUp);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Salamence's Moxie raised its Attack!");
            MESSAGE("Glastrier's Chilling Neigh raised its Attack!");
            MESSAGE("Calyrex's Chilling Neigh raised its Attack!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh does not increase damage done by the same move that causes another Pokemon to faint")
{
    s16 damage[2];
    u32 species = 0, ability = 0, abilityPopUp = 0;
    PARAMETRIZE { species = SPECIES_SALAMENCE;         ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;         ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE_RIDER; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }

    KNOWN_FAILING; // Requires simultaneous damage implementation
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(species) { Ability(ability); }
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
        ABILITY_POPUP(playerLeft, abilityPopUp);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (species == SPECIES_SALAMENCE)
            MESSAGE("Salamence's Moxie raised its Attack!");
        else if (species == SPECIES_GLASTRIER)
            MESSAGE("Glastrier's Chilling Neigh raised its Attack!");
        else
            MESSAGE("Calyrex's Chilling Neigh raised its Attack!");
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(damage[0], damage[1]);
    }
}
