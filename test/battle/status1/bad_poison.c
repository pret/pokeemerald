#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bad poison deals 1/16th cumulative damage per turn")
{
    u32 j;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 4; j++)
            HP_BAR(player, damage: maxHP / 16 * (j + 1));
    }
}

SINGLE_BATTLE_TEST("Bad poison cumulative damage resets on switch")
{
    u32 j;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN {}
        TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 2; j++)
            HP_BAR(player, damage: maxHP / 16 * (j + 1));
        for (j = 0; j < 2; j++)
            HP_BAR(player, damage: maxHP / 16 * (j + 1));
    }
}
