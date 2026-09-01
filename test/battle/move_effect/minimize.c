#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    #if B_MINIMIZE_EVASION >= GEN_5
    ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +2);
    #else
    ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +1);
    #endif
}

SINGLE_BATTLE_TEST("Minimize increases the user's Evasion by 2 stages (Gen5+) or 1 stage (Gen1-4)")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_MINIMIZE_EVASION, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MINIMIZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MINIMIZE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        #if B_MINIMIZE_EVASION >= GEN_5
        EXPECT_EQ(player->statStages[STAT_EVASION], DEFAULT_STAT_STAGE + 2);
        #else
        EXPECT_EQ(player->statStages[STAT_EVASION], DEFAULT_STAT_STAGE + 1);
        #endif
    }
}

// Minimize's flag tests are handled in tests/battle/move_flags/minimize_double_damage.c
