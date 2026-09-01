#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fell Stinger raises user's Attack by 2 stages (Gen6) or 3 stages (Gen7+) if it faints target")
{
    u32 config;

    PARAMETRIZE { config = GEN_7; }
    PARAMETRIZE { config = GEN_6; }

    GIVEN {
        WITH_CONFIG(B_FELL_STINGER_STAT_RAISE, config);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_FELL_STINGER); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FELL_STINGER); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FELL_STINGER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        if (config == GEN_7)
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
        else
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Fell Stinger doesn't raise user's Attack if it doesn't faint target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_FELL_STINGER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FELL_STINGER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FELL_STINGER, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
