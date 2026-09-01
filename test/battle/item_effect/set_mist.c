#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guard Spec. sets Mist effect on the battlers side")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_GUARD_SPEC].battleUsage == EFFECT_ITEM_SET_MIST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GUARD_SPEC, partyIndex: 0); }
        TURN { MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, player);
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
        MESSAGE("The opposing Wobbuffet used Growl!");
        MESSAGE("Wobbuffet is protected by the mist!");
    }
}
