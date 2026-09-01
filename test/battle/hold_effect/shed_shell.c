#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SHED_SHELL].holdEffect == HOLD_EFFECT_SHED_SHELL);
};

SINGLE_BATTLE_TEST("Shed Shell allows switching out even when trapped by Mean Look")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHED_SHELL); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_MEAN_LOOK); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEAN_LOOK, opponent);
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Shed Shell allows switching out even when trapped by Shadow Tag")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHED_SHELL); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Shed Shell allows switching out even when trapped by Arena Trap")
{
    GIVEN {
        PLAYER(SPECIES_DIGLETT) { Item(ITEM_SHED_SHELL); } // Grounded
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Diglett");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Shed Shell does not allow Teleport when trapped")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHED_SHELL); Moves(MOVE_TELEPORT, MOVE_SPLASH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_MEAN_LOOK); }
        TURN { MOVE(player, MOVE_TELEPORT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEAN_LOOK, opponent);
        MESSAGE("Wobbuffet used Teleport!");
        MESSAGE("But it failed!");
    }
}
