#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_QUICK_CLAW].holdEffect == HOLD_EFFECT_QUICK_CLAW);
    ASSUME(gItemsInfo[ITEM_QUICK_CLAW].holdEffectParam == 20);
}

SINGLE_BATTLE_TEST("Quick Claw activates 20% of the time")
{
    PASSES_RANDOMLY(2, 10, RNG_QUICK_CLAW);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_QUICK_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    }
}
