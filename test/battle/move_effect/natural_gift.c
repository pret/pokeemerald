#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Natural Gift removes berry if move fails due to an immunity")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
        OPPONENT(SPECIES_PHANPY);
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Natural Gift does not remove berry if user is ejected out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT(player->item == ITEM_PECHA_BERRY);
    }
}

SINGLE_BATTLE_TEST("Natural Gift does not remove berry if user is unable to use a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); MOVE(player, MOVE_NATURAL_GIFT, WITH_RNG(RNG_PARALYSIS, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
    } THEN {
        EXPECT(player->item == ITEM_PECHA_BERRY);
    }
}

SINGLE_BATTLE_TEST("Natural Gift removes the berry if user missed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PECHA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAND_ATTACK); MOVE(player, MOVE_NATURAL_GIFT, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAND_ATTACK, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Natural Gift (Move Effect) test titles")
