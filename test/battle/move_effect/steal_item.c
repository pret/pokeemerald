#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
    ASSUME(GetMoveEffect(MOVE_COVET) == EFFECT_STEAL_ITEM);
}

SINGLE_BATTLE_TEST("Thief and Covet steal target's held item")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_HYPER_POTION);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet steal player's held item if opponent is a trainer")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        ASSUME(B_TRAINERS_KNOCK_OFF_ITEMS == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, player);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_HYPER_POTION);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

WILD_BATTLE_TEST("Thief and Covet don't steal player's held item if opponent is a wild mon")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        ASSUME(B_TRAINERS_KNOCK_OFF_ITEMS == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_HYPER_POTION);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet don't steal target's held item if user is holding an item")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_POTION);
        EXPECT_EQ(opponent->item, ITEM_HYPER_POTION);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet don't steal target's held item if target has no item")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    }
}

// Test can't currently verify if the item is sent to Bag
WILD_BATTLE_TEST("Thief and Covet steal target's held item and it's added to Bag in wild battles (Gen 9+)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        WITH_CONFIG(B_STEAL_WILD_ITEMS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_HYPER_POTION); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet can't steal target's held item if user faints before (Gen9)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_ROCKY_HELMET);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet can steal target's held item if user faints before (Champions)")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_ROCKY_HELMET);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet: Berries that activate on HP thresholds are stolen before they can activate")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }

    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(200); HP(101); Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    }
}

SINGLE_BATTLE_TEST("Thief and Covet: Berries that activate on a Status activate before the item can be stolen")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }

    GIVEN {
        PLAYER(SPECIES_TOXICROAK) { Ability(ABILITY_POISON_TOUCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ABILITY_POPUP(player, ABILITY_POISON_TOUCH);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ITEM_STEAL, opponent);
    }
}
