#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_POLTERGEIST) == EFFECT_POLTERGEIST);
    ASSUME(MoveHasAdditionalEffect(MOVE_POLTERGEIST, MOVE_EFFECT_ITEM_MESSAGE));
}

SINGLE_BATTLE_TEST("Poltergeist fails if the target isn't holding an item")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_POTION; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_POLTERGEIST); }
    } SCENE {
        if (item == ITEM_NONE) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
            MESSAGE("But it failed!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Poltergeist reveals the target's item before dealing damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_POLTERGEIST); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is about to be attacked by its Potion!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Poltergeist doesn't reveal the target's item if user fails to use the move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_POLTERGEIST); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet is about to be attacked by its Potion!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
            HP_BAR(opponent);
        };
    }
}

SINGLE_BATTLE_TEST("Poltergeist doesn't reveal the target's item if target is immune")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_POLTERGEIST) == TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 0) == TYPE_NORMAL || GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_POLTERGEIST); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Pidgey is about to be attacked by its Potion!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
            HP_BAR(opponent);
        };
    }
}

SINGLE_BATTLE_TEST("Poltergeist doesn't reveal the target's item if it missed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_POLTERGEIST, hit: FALSE); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet is about to be attacked by its Potion!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POLTERGEIST, player);
            HP_BAR(opponent);
        };
    }
}
