#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon fainting")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_SHIELD) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GUST); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Gust!");
        MESSAGE("Aegislash fainted!");
    } THEN {
        EXPECT_EQ(GetMonData(&PLAYER_PARTY[0], MON_DATA_SPECIES), SPECIES_AEGISLASH_SHIELD);
    }
}
