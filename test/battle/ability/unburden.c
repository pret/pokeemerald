#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Unburden doubles speed once user uses item")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_GRASSY_SEED) == HOLD_EFFECT_TERRAIN_SEED);
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_GRASSY_SEED); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
        OPPONENT(SPECIES_RILLABOOM) { Speed(7); Ability(ABILITY_GRASSY_SURGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_U_TURN); SEND_OUT(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
        ABILITY_POPUP(opponent, ABILITY_GRASSY_SURGE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Unburden doubles speed once user gets their item knocked off")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Unburden doesn't activate when item is consumed in Neutralizing Gas")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WEEZING) { Speed(7); Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { MOVE(opponent, MOVE_U_TURN); SEND_OUT(opponent, 1); }
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 2, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Unburden doubling speed effect is ignored by Neutralizing Gas")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
        OPPONENT(SPECIES_WEEZING) { Speed(7); Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { MOVE(opponent, MOVE_U_TURN); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_U_TURN); SEND_OUT(opponent, 0); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 4, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Unburden doesn't activate when item is removed in Magic Room")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_ROOM); }
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_ROOM, opponent);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Unburden doesn't activate when item is removed in Embargo")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); }
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBARGO, opponent);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Unburden speed boost is removed after regaining an item with Recycle")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
        TURN {}
        TURN { MOVE(player, MOVE_RECYCLE); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Turn 3
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, player);
        // Turn 4, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Unburden speed boost is removed after regaining an item with Trick")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { MOVE(player, MOVE_TRICK); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Unburden speed boost is removed after regaining an item with Thief")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); Speed(7); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { MOVE(player, MOVE_THIEF); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_KNOCKOFF, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THIEF, player);
        // Turn 3, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

DOUBLE_BATTLE_TEST("Unburden speed boost is removed after regaining an item with Symbiosis")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_ORAN_BERRY); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLING, target: opponentLeft); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        // Turn 2, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Unburden reactivates after consuming an item again")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_DRIFBLIM) { Ability(ABILITY_UNBURDEN); Item(ITEM_POTION); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(7); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
        TURN {}
        TURN { MOVE(player, MOVE_RECYCLE); }
        TURN {}
        TURN { MOVE(player, MOVE_FLING); }
        TURN {}
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        // Turn 2, doubled speed
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Turn 3
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, player);
        // Turn 4, no speed increase
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        // Turn 5
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        // Turn 6, doubled speed again
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
