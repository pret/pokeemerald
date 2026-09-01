#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Perish Song (Move Effect) test titles")

DOUBLE_BATTLE_TEST("Perish Song can be absorbed and will not affect those that absorbed it")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_LANTURN) { HP(1); Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ELECTRIFY, target: playerLeft);
            MOVE(playerLeft, MOVE_PERISH_SONG);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_VOLT_ABSORB);
        ABILITY_POPUP(opponentRight, ABILITY_SOUNDPROOF);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->hp, 0);
        EXPECT_EQ(opponentLeft->hp, 0);
        EXPECT_GT(playerRight->hp, 0);
        EXPECT_GT(opponentRight->hp, 0);
    }
}

DOUBLE_BATTLE_TEST("Perish Song ignores protect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { 
            MOVE(playerLeft, MOVE_PROTECT); 
            MOVE(opponentLeft, MOVE_PROTECT); 
            MOVE(playerRight, MOVE_PERISH_SONG); 
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Perish Song will be blocked by users Soundproof in gen3")
{
    u32 config = GEN_3;

    PARAMETRIZE { config = GEN_3; }
    PARAMETRIZE { config = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_CHECK_USER_FAILURE, config);
        PLAYER(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PERISH_SONG); }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        if (config == GEN_3) {
            ABILITY_POPUP(playerLeft, ABILITY_SOUNDPROOF);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerLeft);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerLeft);
            HP_BAR(playerLeft);
        }
    } THEN {
        if (config == GEN_3) {
            EXPECT_GT(playerLeft->hp, 0);
        } else {
            EXPECT_EQ(playerLeft->hp, 0);
        }
        EXPECT_EQ(opponentLeft->hp, 0);
        EXPECT_EQ(playerRight->hp, 0);
        EXPECT_EQ(opponentRight->hp, 0);
    }
}
