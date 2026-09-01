#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_RING_TARGET].holdEffect == HOLD_EFFECT_RING_TARGET);
}

SINGLE_BATTLE_TEST("Ring Target removes a holder's type immunity")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST || GetSpeciesType(SPECIES_GASTLY, 1) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY) { Item(ITEM_RING_TARGET); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Ring Target lets Ground-type moves hit Flying-type holders")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_RING_TARGET); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Ring Target does not make Flying-type holders grounded")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        ASSUME(gItemsInfo[ITEM_GRASSY_SEED].holdEffect == HOLD_EFFECT_TERRAIN_SEED);
        ASSUME(gItemsInfo[ITEM_GRASSY_SEED].holdEffectParam == HOLD_EFFECT_PARAM_GRASSY_TERRAIN);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_RING_TARGET); MaxHP(100); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        NOT HP_BAR(opponent);
    }
}
