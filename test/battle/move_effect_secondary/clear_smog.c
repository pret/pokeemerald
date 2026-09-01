#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Smog removes stat changes even if it did no damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_ENDURE); MOVE(opponent, MOVE_CLEAR_SMOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLEAR_SMOG, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
