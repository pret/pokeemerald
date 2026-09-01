#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
    ASSUME(I_SITRUS_BERRY_HEAL >= GEN_4);
}

SINGLE_BATTLE_TEST("Pickup grants an item used by another Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
    }
}

WILD_BATTLE_TEST("Pickup grants an item used by itself in wild battles (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_PICKUP_WILD, GEN_9);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant the user their item outside wild battles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant another Pokémon's popped Air Balloon")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Air Balloon!");
        }
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an item not used that turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an item after its holder faints")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_MEMENTO); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an used item if holder is replaced")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PARTING_SHOT) == EFFECT_PARTING_SHOT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(300); HP(151); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(300); HP(151); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an item if it destroyed the item with Incinerate")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_INCINERATE, MOVE_EFFECT_INCINERATE));
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an item if it knocked off that item")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an item if the user eats it with Bug Bite/Pluck")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BUG_BITE, MOVE_EFFECT_BUG_BITE));
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant an used item if its user already restored it")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_RECYCLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PICKUP);
            MESSAGE("Zigzagoon found one Sitrus Berry!");
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickup restores an item that has been Flinged")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Pickup restores an item that was used by Natural Gift")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, opponent);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
    }
}

DOUBLE_BATTLE_TEST("Pickup triggers based on Speed order")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); Ability(ABILITY_PICKUP); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(50); Ability(ABILITY_PICKUP); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_PICKUP);
        NOT ABILITY_POPUP(playerLeft, ABILITY_PICKUP);
    } THEN {
        EXPECT_EQ(opponentRight->item, ITEM_SITRUS_BERRY);
        EXPECT_EQ(playerLeft->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Pickup grants a random item used by another Pokémon")
{
    PASSES_RANDOMLY(1, 3, RNG_PICKUP);
    GIVEN {
        ASSUME(gItemsInfo[ITEM_WHITE_HERB].holdEffect == HOLD_EFFECT_WHITE_HERB);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BULLDOZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_PICKUP);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_SITRUS_BERRY);
    }
}

DOUBLE_BATTLE_TEST("Pickup doesn't trigger more than once per turn")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { HP(1); Ability(ABILITY_PICKUP); }
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BULLDOZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_PICKUP);
        NOT ABILITY_POPUP(playerLeft, ABILITY_PICKUP);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_NONE);
        EXPECT_GT(playerLeft->hp, 1);
        EXPECT_LT(playerLeft->hp, playerLeft->maxHP/2);
    }
}
