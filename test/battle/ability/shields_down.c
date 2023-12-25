#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Minior Meteor transforms into Minior Core on switch-in if it has 1/2 or less health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_METEOR) { Ability(ABILITY_SHIELDS_DOWN); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_CORE);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on switch-in if it more then 1/2 health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}
