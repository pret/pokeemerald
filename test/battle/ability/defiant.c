#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Defiant sharply raises player's Attack after Intimidate")
{
    u32 abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_DEFIANT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_DEFIANT; }

    GIVEN {
        PLAYER(SPECIES_MANKEY) { Ability(abilityLeft); }
        PLAYER(SPECIES_PRIMEAPE) { Ability(abilityRight); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target:opponentLeft); MOVE(playerRight, MOVE_TACKLE, target:opponentRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Foe Gyarados's Intimidate cuts Mankey's attack!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Mankey's Attack sharply rose!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Foe Gyarados's Intimidate cuts Primeape's attack!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Primeape's Attack sharply rose!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Foe Arbok's Intimidate cuts Mankey's attack!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Mankey's Attack sharply rose!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Foe Arbok's Intimidate cuts Primeape's attack!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Primeape's Attack sharply rose!");
        }
    } FINALLY {
        // -2 from Intimidates and +4 from Defiants gets +2 total
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], (abilityLeft == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], (abilityRight == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
    }
}

// Same as above, but for opponent.
DOUBLE_BATTLE_TEST("Defiant sharply raises opponent's Attack after Intimidate")
{
    u32 abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_DEFIANT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { abilityLeft = ABILITY_DEFIANT; abilityRight = ABILITY_DEFIANT; }

    GIVEN {
        OPPONENT(SPECIES_MANKEY) { Ability(abilityLeft); }
        OPPONENT(SPECIES_PRIMEAPE) { Ability(abilityRight); }
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target:playerLeft); MOVE(opponentRight, MOVE_TACKLE, target:playerRight); }
    } SCENE {
        //1st mon Intimidate
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Gyarados's Intimidate cuts Foe Mankey's attack!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Mankey's Attack sharply rose!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Gyarados's Intimidate cuts Foe Primeape's attack!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("Foe Primeape's Attack sharply rose!");
        }

        //2nd mon Intimidate
        ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Arbok's Intimidate cuts Foe Mankey's attack!");
        if (abilityLeft == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Mankey's Attack sharply rose!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Arbok's Intimidate cuts Foe Primeape's attack!");
        if (abilityRight == ABILITY_DEFIANT) {
            ABILITY_POPUP(opponentRight, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("Foe Primeape's Attack sharply rose!");
        }
    } FINALLY {
        // -2 from Intimidates and +4 from Defiants gets +2 total
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], (abilityLeft == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], (abilityRight == ABILITY_DEFIANT) ? DEFAULT_STAT_STAGE + 2 : DEFAULT_STAT_STAGE - 2);
    }
}
