#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sticky Hold prevents item theft")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THIEF, MOVE_EFFECT_STEAL_ITEM));
        PLAYER(SPECIES_URSALUNA) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_GASTRODON) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_LIFE_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_THIEF); }
    } SCENE {
        MESSAGE("Ursaluna used Thief!");
        ABILITY_POPUP(opponent, ABILITY_STICKY_HOLD);
        MESSAGE("Foe Gastrodon's Sticky Hold made Thief ineffective!");
    }
}

