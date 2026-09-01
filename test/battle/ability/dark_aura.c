#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Dark Aura increases the power of all Dark-type attacks by 33%")
{
    s16 damage[8];

    GIVEN {
        PLAYER(SPECIES_YVELTAL) { Ability(ABILITY_DARK_AURA); }
        PLAYER(SPECIES_LINOONE);
        PLAYER(SPECIES_LINOONE);
        OPPONENT(SPECIES_LINOONE);
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SKILL_SWAP, target: playerLeft); }
        TURN { SWITCH(playerLeft, 2); }
        TURN {
            MOVE(playerLeft, MOVE_BITE, target:opponentLeft, secondaryEffect:FALSE);
            MOVE(playerRight, MOVE_BITE, target:opponentRight, secondaryEffect:FALSE);
            MOVE(opponentLeft, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
            MOVE(opponentRight, MOVE_BITE, target:playerRight, secondaryEffect:FALSE);
        }
        TURN { MOVE(opponentLeft, MOVE_GASTRO_ACID, target:playerRight); }
        TURN {
            MOVE(playerLeft, MOVE_BITE, target:opponentLeft, secondaryEffect:FALSE);
            MOVE(playerRight, MOVE_BITE, target:opponentRight, secondaryEffect:FALSE);
            MOVE(opponentLeft, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
            MOVE(opponentRight, MOVE_BITE, target:playerRight, secondaryEffect:FALSE);
        }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &damage[2]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentRight);
        HP_BAR(playerRight, captureDamage: &damage[3]);

        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponentLeft);

        // Turn 3
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[4]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[5]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &damage[6]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentRight);
        HP_BAR(playerRight, captureDamage: &damage[7]);
    } THEN {
        EXPECT_MUL_EQ(damage[4], UQ_4_12(1.33), damage[0]);
        EXPECT_MUL_EQ(damage[5], UQ_4_12(1.33), damage[1]);
        EXPECT_MUL_EQ(damage[6], UQ_4_12(1.33), damage[2]);
        EXPECT_MUL_EQ(damage[7], UQ_4_12(1.33), damage[3]);
    }
}

DOUBLE_BATTLE_TEST("Dark Aura's effect doesn't stack multiple times")
{
    s16 damage[6];

    GIVEN {
        PLAYER(SPECIES_YVELTAL) { Ability(ABILITY_DARK_AURA); }
        PLAYER(SPECIES_WOBBUFFET) { HP(9999); MaxHP(9999); }
        PLAYER(SPECIES_YVELTAL) { Ability(ABILITY_DARK_AURA); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9999); MaxHP(9999); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9999); MaxHP(9999); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_BITE, target:opponentLeft, secondaryEffect:FALSE);
            MOVE(opponentLeft, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
            MOVE(opponentRight, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
        }
        TURN { SWITCH(playerRight, 2); }
        TURN {
            MOVE(playerLeft, MOVE_BITE, target:opponentLeft, secondaryEffect:FALSE);
            MOVE(opponentLeft, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
            MOVE(opponentRight, MOVE_BITE, target:playerLeft, secondaryEffect:FALSE);
        }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &damage[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &damage[2]);

        // Turn 2
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Yveltal");

        // Turn 3
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[3]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &damage[4]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &damage[5]);
    } THEN {
        EXPECT_EQ(damage[3], damage[0]);
        EXPECT_EQ(damage[4], damage[1]);
        EXPECT_EQ(damage[5], damage[2]);
    }
}
