#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Supersweet Syrup lowers evasion once per battle by one stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DIPPLIN) { Ability(ABILITY_SUPERSWEET_SYRUP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SUPERSWEET_SYRUP);
        MESSAGE("A supersweet aroma is wafting from the syrup covering Foe Dipplin!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("2 withdrew Dipplin!");
        MESSAGE("2 withdrew Wobbuffet!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SUPERSWEET_SYRUP);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("A supersweet aroma is wafting from the syrup covering Foes Dipplin!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Supersweet Syrup lowers evasion of both opposing mon's in battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DIPPLIN) { Ability(ABILITY_SUPERSWEET_SYRUP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_SUPERSWEET_SYRUP);
        MESSAGE("A supersweet aroma is wafting from the syrup covering Foe Dipplin!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
    }
}
