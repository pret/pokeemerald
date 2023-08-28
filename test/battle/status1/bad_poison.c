#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bad poison deals 1/16th cumulative damage per turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (i = 0; i < 4; i++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (i = 0; i < 4; i++)
            HP_BAR(player, damage: maxHP / 16 * (i + 1));
    }
}

SINGLE_BATTLE_TEST("Bad poison cumulative damage resets on switch")
{
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
        for (i = 0; i < 2; i++)
            HP_BAR(player, damage: maxHP / 16 * (i + 1));
        for (i = 0; i < 2; i++)
            HP_BAR(player, damage: maxHP / 16 * (i + 1));
    }
}
