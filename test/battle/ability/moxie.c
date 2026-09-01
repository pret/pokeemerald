#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh raises Attack by one stage after directly causing a Pokemon to faint")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE, abilityPopUp = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SALAMENCE;   ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;   ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(species) { Ability(ability); }
        PLAYER(SPECIES_SNORUNT) { HP(1); }
        OPPONENT(SPECIES_GLALIE) { HP(1); }
        OPPONENT(SPECIES_ABRA) { HP(1); }
        OPPONENT(SPECIES_ABRA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        MESSAGE("The opposing Glalie fainted!");
        MESSAGE("Snorunt fainted!");
        MESSAGE("The opposing Abra fainted!");
        ABILITY_POPUP(playerLeft, abilityPopUp);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (species == SPECIES_SALAMENCE)
            MESSAGE("Salamence's Attack rose drastically!");
        else if (species == SPECIES_GLASTRIER)
            MESSAGE("Glastrier's Attack rose drastically!");
        else
            MESSAGE("Calyrex's Attack rose drastically!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
    }
}

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh does not trigger if Pokemon faint to indirect damage or damage from other Pokemon")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE, abilityPopUp = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SALAMENCE;   ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;   ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
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
                MESSAGE("Salamence's Attack rose!");
                MESSAGE("Glastrier's Attack rose!");
                MESSAGE("Calyrex's Attack rose!");
            }
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Moxie/Chilling Neigh does not trigger when already at maximum Attack stage")
{
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE, abilityPopUp = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SALAMENCE;   ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;   ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
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
            MESSAGE("Salamence cut its own HP and maximized its Attack!");
        else if (species == SPECIES_GLASTRIER)
            MESSAGE("Glastrier cut its own HP and maximized its Attack!");
        else
            MESSAGE("Calyrex cut its own HP and maximized its Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        MESSAGE("The opposing Snorunt fainted!");
        NONE_OF {
            ABILITY_POPUP(player, abilityPopUp);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Salamence's Attack rose!");
            MESSAGE("Glastrier's Attack rose!");
            MESSAGE("Calyrex's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Moxie/Chilling Neigh does not increase damage done by the same move that causes another Pokemon to faint")
{
    s16 damage[2];
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE, abilityPopUp = ABILITY_NONE;
    PARAMETRIZE { species = SPECIES_SALAMENCE;   ability = ABILITY_MOXIE;            abilityPopUp = ABILITY_MOXIE;          }
    PARAMETRIZE { species = SPECIES_GLASTRIER;   ability = ABILITY_CHILLING_NEIGH;   abilityPopUp = ABILITY_CHILLING_NEIGH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; abilityPopUp = ABILITY_CHILLING_NEIGH; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
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
        HP_BAR(opponentRight, captureDamage: &damage[1]);
        MESSAGE("Abra fainted!");
        ABILITY_POPUP(playerLeft, abilityPopUp);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        if (species == SPECIES_SALAMENCE)
            MESSAGE("Salamence's Attack rose!");
        else if (species == SPECIES_GLASTRIER)
            MESSAGE("Glastrier's Attack rose!");
        else
            MESSAGE("Calyrex's Attack rose!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(damage[0], damage[1]);
    }
}
