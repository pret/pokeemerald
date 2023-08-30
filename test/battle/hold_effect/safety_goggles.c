#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    gItems[ITEM_SAFETY_GOGGLES].holdEffect == HOLD_EFFECT_SAFETY_GOGGLES;
};

SINGLE_BATTLE_TEST("Safety Goggles block powder and spore moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_STUN_SPORE].powderMove);
        ASSUME(gItems[ITEM_SAFETY_GOGGLES].holdEffect == HOLD_EFFECT_SAFETY_GOGGLES);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ABRA) { Item(ITEM_SAFETY_GOGGLES); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
        MESSAGE("Foe Abra is not affected thanks to its SafetyGoggles!");
    }
}

TO_DO_BATTLE_TEST("Safety Goggles blocks damage from hail");
TO_DO_BATTLE_TEST("Safety Goggles blocks damage from sandstorm");
TO_DO_BATTLE_TEST("Safety Goggles blocks Effect Spore's effect");
