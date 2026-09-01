#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ZOOM_LENS].holdEffect == HOLD_EFFECT_ZOOM_LENS);
    ASSUME(GetMoveAccuracy(MOVE_SING) == 55);
}

SINGLE_BATTLE_TEST("Zoom Lens boosts accuracy when the target has already moved this turn")
{
    PASSES_RANDOMLY(55 * (100 + gItemsInfo[ITEM_ZOOM_LENS].holdEffectParam) / 100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > GetMovePriority(MOVE_SING));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ZOOM_LENS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_QUICK_ATTACK); MOVE(player, MOVE_SING); }
    } SCENE {
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Zoom Lens does not boost accuracy against a target that switched in this turn")
{
    PASSES_RANDOMLY(55, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ZOOM_LENS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SING); }
    } SCENE {
        STATUS_ICON(opponent, sleep: TRUE);
    }
}
