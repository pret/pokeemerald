#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SAFETY_GOGGLES].holdEffect == HOLD_EFFECT_SAFETY_GOGGLES);
};

SINGLE_BATTLE_TEST("Safety Goggles block powder and spore moves")
{
    GIVEN {
        ASSUME(IsPowderMove(MOVE_STUN_SPORE));
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ABRA) { Item(ITEM_SAFETY_GOGGLES); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
        MESSAGE("The opposing Abra is not affected thanks to its Safety Goggles!");
    }
}

SINGLE_BATTLE_TEST("Safety Goggles blocks damage from Hail")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet is buffeted by the hail!");
    }
}

SINGLE_BATTLE_TEST("Safety Goggles blocks damage from Sandstorm")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet is buffeted by the sandstorm!");
    }
}

SINGLE_BATTLE_TEST("Safety Goggles blocks Effect Spore's effect")
{
    PASSES_RANDOMLY(100, 100, RNG_EFFECT_SPORE);
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
        OPPONENT(SPECIES_BRELOOM) { Ability(ABILITY_EFFECT_SPORE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_EFFECT_SPORE);

            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            MESSAGE("Wobbuffet was poisoned!");
            STATUS_ICON(player, poison: TRUE);

            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            MESSAGE("Wobbuffet is paralyzed, so it may be unable to move!");
            STATUS_ICON(player, paralysis: TRUE);

            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            MESSAGE("Wobbuffet fell asleep!");
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}
