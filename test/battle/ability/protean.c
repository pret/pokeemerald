#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(B_PROTEAN_LIBERO == GEN_9);
}

SINGLE_BATTLE_TEST("Protean changes the type of the user only once per switch in")
{
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("Foe Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PROTEAN);
            MESSAGE("Foe Kecleon transformed into the Normal type!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("Foe Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
    }
}
