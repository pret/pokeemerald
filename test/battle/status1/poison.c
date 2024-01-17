#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison deals 1/8th damage per turn")
{
    u32 j;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 4; j++)
            HP_BAR(player, damage: maxHP / 8);
    }
}
