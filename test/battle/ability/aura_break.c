#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Aura Break inverts Fairy Aura's effect")
{
    s16 damage[3];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_FAIRY_AURA); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZYGARDE_50) { Ability(ABILITY_AURA_BREAK); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target:opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target:opponentLeft); SWITCH(playerRight, 2); }
        TURN { MOVE(playerLeft, MOVE_PLAY_ROUGH, target:opponentLeft); SWITCH(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLAY_ROUGH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);

    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(0.75), damage[2]);
    }
}

DOUBLE_BATTLE_TEST("Aura Break inverts Dark Aura's effect")
{
    s16 damage[3];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_YVELTAL) { Ability(ABILITY_DARK_AURA); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZYGARDE_50) { Ability(ABILITY_AURA_BREAK); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BITE, target:opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_BITE, target:opponentLeft); SWITCH(playerRight, 2); }
        TURN { MOVE(playerLeft, MOVE_BITE, target:opponentLeft); SWITCH(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);

    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.33), damage[1]);
        EXPECT_MUL_EQ(damage[0], UQ_4_12(0.75), damage[2]);
    }
}
