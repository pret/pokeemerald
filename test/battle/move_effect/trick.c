#include "global.h"
#include "test/battle.h"
#include "mail.h"

SINGLE_BATTLE_TEST("Trick swaps held items")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } THEN {
        EXPECT(player->item == ITEM_LUM_BERRY);
        EXPECT(opponent->item == ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Trick succeeds if only the user has an item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(opponent->item == ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Trick succeeds if only the target has an item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } THEN {
        EXPECT(player->item == ITEM_LUM_BERRY);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Trick fails if both battlers have no held item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Trick fails if either item is Mail")
{
    enum Item atkItem = ITEM_NONE, defItem = ITEM_NONE;

    ASSUME(ItemIsMail(ITEM_ORANGE_MAIL));
    PARAMETRIZE { atkItem = ITEM_ORANGE_MAIL; defItem = ITEM_NONE; }
    PARAMETRIZE { atkItem = ITEM_ORAN_BERRY;  defItem = ITEM_ORANGE_MAIL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(atkItem); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(defItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == atkItem);
        EXPECT(opponent->item == defItem);
    }
}

SINGLE_BATTLE_TEST("Trick fails if either item is a Z-Crystal")
{
    enum Item atkItem = ITEM_NONE, defItem = ITEM_NONE;

    ASSUME(GetItemHoldEffect(ITEM_FIGHTINIUM_Z) == HOLD_EFFECT_Z_CRYSTAL);
    PARAMETRIZE { atkItem = ITEM_FIGHTINIUM_Z; defItem = ITEM_NONE; }
    PARAMETRIZE { atkItem = ITEM_SITRUS_BERRY; defItem = ITEM_FIGHTINIUM_Z; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(atkItem); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(defItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == atkItem);
        EXPECT(opponent->item == defItem);
    }
}

SINGLE_BATTLE_TEST("Trick fails if either battler holds a Mega Stone")
{
    enum Item atkItem = ITEM_NONE, defItem = ITEM_NONE;
    enum Species atkSpecies = SPECIES_WOBBUFFET, defSpecies = SPECIES_WOBBUFFET;

    PARAMETRIZE { atkSpecies = SPECIES_BLAZIKEN; atkItem = ITEM_BLAZIKENITE; defSpecies = SPECIES_WOBBUFFET; defItem = ITEM_SITRUS_BERRY; }
    PARAMETRIZE { atkSpecies = SPECIES_WOBBUFFET; atkItem = ITEM_SITRUS_BERRY; defSpecies = SPECIES_BLAZIKEN; defItem = ITEM_BLAZIKENITE; }

    GIVEN {
        PLAYER(atkSpecies) { Item(atkItem); }
        OPPONENT(defSpecies) { Item(defItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == atkItem);
        EXPECT(opponent->item == defItem);
    }
}

SINGLE_BATTLE_TEST("Trick fails if an item changes the holder's form")
{
    enum Item atkItem = ITEM_NONE, defItem = ITEM_NONE;

    PARAMETRIZE { atkItem = ITEM_GRISEOUS_CORE; defItem = ITEM_SITRUS_BERRY; }
    PARAMETRIZE { atkItem = ITEM_SITRUS_BERRY; defItem = ITEM_GRISEOUS_CORE; }

    GIVEN {
        PLAYER(SPECIES_GIRATINA_ORIGIN) { Item(atkItem); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(defItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == atkItem);
        EXPECT(opponent->item == defItem);
    }
}

SINGLE_BATTLE_TEST("Trick doesn't fail if the user has Sticky Hold")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
    } THEN {
        EXPECT(player->item == ITEM_LUM_BERRY);
        EXPECT(opponent->item == ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Trick fails against Sticky Hold")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet's item cannot be removed!");
    } THEN {
        EXPECT(player->item == ITEM_SITRUS_BERRY);
        EXPECT(opponent->item == ITEM_LUM_BERRY);
    }
}

SINGLE_BATTLE_TEST("Trick fails if the target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_TRICK); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_SITRUS_BERRY);
        EXPECT(opponent->item == ITEM_LUM_BERRY);
    }
}

SINGLE_BATTLE_TEST("Trick can be used against targets with an active form change that doesn't require items")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
    }
}

SINGLE_BATTLE_TEST("Trick does not remove the user's choice lock if both the target and use are holding choice items before Gen 5")
{
    GIVEN {
        WITH_CONFIG(B_MODERN_TRICK_CHOICE_LOCK, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); MovesWithPP({MOVE_TRICK, 1}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
        TURN { FORCED_MOVE(player); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Trick removes the user's choice lock if both the target and use are holding choice items from Gen 5 onwards")
{
    GIVEN {
        WITH_CONFIG(B_MODERN_TRICK_CHOICE_LOCK, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); MovesWithPP({MOVE_TRICK, 1}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CHOICE_SCARF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
