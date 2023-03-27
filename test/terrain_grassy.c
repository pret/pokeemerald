#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Grassy Terrain recovers 1/16th HP at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        MESSAGE("Wobbuffet is healed by the grassy terrain!");
        HP_BAR(player, damage: -maxHP / 16);
    }
}

TO_DO_BATTLE_TEST("Grassy Terrain increases power of Grass-type moves by 30/50 percent")
TO_DO_BATTLE_TEST("Grassy Terrain decreases power of Earthquake, Magnitude and Bulldoze by 50 percent")
