#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_HYPER_VOICE) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_HYPER_VOICE) > 0);
}

SINGLE_BATTLE_TEST("Liquid voice turns a sound move into a Water-type move")
{
    GIVEN {
        PLAYER(SPECIES_TYPHLOSION);
        OPPONENT(SPECIES_PRIMARINA) { Ability(ABILITY_LIQUID_VOICE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, opponent);
        MESSAGE("It's super effective!");
    }
}
