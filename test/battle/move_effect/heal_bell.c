#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_HEAL_BELL].effect == EFFECT_HEAL_BELL);
    ASSUME(gMovesInfo[MOVE_AROMATHERAPY].effect == EFFECT_HEAL_BELL);
}

DOUBLE_BATTLE_TEST("Heal Bell cures the entire party")
{
    u32 move;

    PARAMETRIZE { move = MOVE_HEAL_BELL; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, move, target: playerLeft); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); }
    } SCENE {
        int i;

        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        NOT MESSAGE("Wobbuffet is hurt by poison!");
        for (i = 0; i < 6; i++)
            EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_STATUS), STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Heal Bell does not cure soundproof partners")
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SCRAPPY; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; }

    ASSUME(B_HEAL_BELL_SOUNDPROOF != GEN_5);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEAL_BELL, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, playerLeft);
        if (ability == ABILITY_SOUNDPROOF) {
            MESSAGE("Exploud is hurt by poison!");
        } else {
            NOT MESSAGE("Exploud is hurt by poison!");
        }
    }
}

SINGLE_BATTLE_TEST("Heal Bell cures inactive soundproof Pokemon")
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SCRAPPY; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; }

    ASSUME(B_HEAL_BELL_SOUNDPROOF >= GEN_5);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL, target: player); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        SEND_IN_MESSAGE("Exploud");
        NOT MESSAGE("Exploud is hurt by poison!");
    }
}


SINGLE_BATTLE_TEST("Heal Bell cures a soundproof user")
{
    ASSUME(B_HEAL_BELL_SOUNDPROOF == GEN_5 || B_HEAL_BELL_SOUNDPROOF >= GEN_8);

    GIVEN {
        PLAYER(SPECIES_EXPLOUD) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL, target: player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        NOT MESSAGE("Exploud is hurt by poison!");
    }
}
