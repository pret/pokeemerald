#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Soul Heart boosts Sp. Atk after opponent uses Memento")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MEMENTO) == EFFECT_MEMENTO);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGEARNA) { Ability(ABILITY_SOUL_HEART); }
    } WHEN {
        TURN { MOVE(player, MOVE_MEMENTO); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Wobbuffet fainted!");
        ABILITY_POPUP(opponent, ABILITY_SOUL_HEART);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1); // -2 from Memento, +1 from Soul Heart
    }
}

TO_DO_BATTLE_TEST("TODO: Write Soul Heart (Ability) test titles")
