#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon switching out")
{
    GIVEN {
        ASSUME(P_GEN_6_POKEMON == TRUE);
        PLAYER(SPECIES_AEGISLASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STANCE_CHANGE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Aegislash used Tackle!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_AEGISLASH);
    }
}
