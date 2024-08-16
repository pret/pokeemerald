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
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Pickup doesn't grant the user their item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
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
    ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
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
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
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
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_MEMENTO); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
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
    ASSUME(gMovesInfo[MOVE_PARTING_SHOT].effect == EFFECT_PARTING_SHOT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(300); HP(151); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(300); HP(151); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
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
    ASSUME(MoveHasAdditionalEffect(MOVE_INCINERATE, MOVE_EFFECT_INCINERATE));
    GIVEN {
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
    ASSUME(MoveHasAdditionalEffect(MOVE_KNOCK_OFF, MOVE_EFFECT_KNOCK_OFF));
    GIVEN {
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
    ASSUME(MoveHasAdditionalEffect(MOVE_BUG_BITE, MOVE_EFFECT_BUG_BITE));
    GIVEN {
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
    ASSUME(gMovesInfo[MOVE_RECYCLE].effect == EFFECT_RECYCLE);
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(51); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_RECYCLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
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
    ASSUME(gMovesInfo[MOVE_FLING].effect == EFFECT_FLING);
    GIVEN {
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
    ASSUME(gMovesInfo[MOVE_NATURAL_GIFT].effect == EFFECT_NATURAL_GIFT);
    GIVEN {
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
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
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
    ASSUME(gItemsInfo[ITEM_WHITE_HERB].holdEffect == HOLD_EFFECT_RESTORE_STATS);
    GIVEN {
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
