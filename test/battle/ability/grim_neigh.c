#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Grim Neigh raises Sp. Attack by one stage after directly causing a Pokemon to faint")
{
    enum Species species = SPECIES_NONE;
    enum Ability abilityPopUp = ABILITY_NONE, ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SPECTRIER;      ability = ABILITY_GRIM_NEIGH;          abilityPopUp = ABILITY_GRIM_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; abilityPopUp = ABILITY_GRIM_NEIGH; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_SNORUNT) { HP(1); }
        OPPONENT(SPECIES_GLALIE) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        MESSAGE("The opposing Glalie fainted!");
        MESSAGE("Snorunt fainted!");
        MESSAGE("The opposing Abra fainted!");
        ABILITY_POPUP(playerLeft, abilityPopUp);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (species == SPECIES_SPECTRIER)
            MESSAGE("Spectrier's Sp. Atk rose drastically!");
        else
            MESSAGE("Calyrex's Sp. Atk rose drastically!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 3);
    }
}

DOUBLE_BATTLE_TEST("Grim Neigh does not trigger if Pokemon faint to indirect damage or damage from other Pokemon")
{
    enum Species species = SPECIES_NONE;
    enum Ability abilityPopUp = ABILITY_NONE, ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SPECTRIER;            ability = ABILITY_GRIM_NEIGH;          abilityPopUp = ABILITY_GRIM_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; abilityPopUp = ABILITY_GRIM_NEIGH; }
    GIVEN {
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_SNORUNT) { HP(1); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_GLALIE) { HP(1); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentRight); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        int i;

        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
        for (i = 0; i < 3; i++) {
            ONE_OF {
                MESSAGE("Snorunt fainted!");
                MESSAGE("The opposing Glalie fainted!");
                MESSAGE("The opposing Abra fainted!");
            }
            NONE_OF {
                ABILITY_POPUP(playerLeft, abilityPopUp);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Salamence's Sp. Atk rose!");
                MESSAGE("Spectrier's Sp. Atk rose!");
                MESSAGE("Calyrex's Sp. Atk rose!");
            }
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Grim Neigh does not increase damage done by the same move that causes another Pokemon to faint")
{
    s16 damage[2];
    enum Species species = SPECIES_NONE;
    enum Ability abilityPopUp = ABILITY_NONE, ability = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SPECTRIER;            ability = ABILITY_GRIM_NEIGH;          abilityPopUp = ABILITY_GRIM_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; abilityPopUp = ABILITY_GRIM_NEIGH; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_GLALIE);
        OPPONENT(SPECIES_GLALIE);
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
        MESSAGE("Abra fainted!");
        ABILITY_POPUP(playerLeft, abilityPopUp);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (species == SPECIES_SPECTRIER)
            MESSAGE("Spectrier's Sp. Atk rose!");
        else
            MESSAGE("Calyrex's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(damage[0], damage[1]);
    }
}
