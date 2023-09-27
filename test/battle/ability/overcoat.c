#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Overcoat blocks powder and spore moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_STUN_SPORE].powderMove);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PINECO) { Ability(ABILITY_OVERCOAT); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OVERCOAT);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
        MESSAGE("It doesn't affect Foe Pineco…");
    }
}

TO_DO_BATTLE_TEST("Overcoat blocks damage from hail");
TO_DO_BATTLE_TEST("Overcoat blocks damage from sandstorm");
TO_DO_BATTLE_TEST("Overcoat blocks Effect Spore's effect");
