#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bestow transfers its held item to the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(opponent->item == ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the user has no held item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the target already has a held item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_SITRUS_BERRY);
        EXPECT(opponent->item == ITEM_LUM_BERRY);
    }
}

#include "mail.h"
SINGLE_BATTLE_TEST("Bestow fails if the user is holding Mail")
{
    GIVEN {
        ASSUME(ItemIsMail(ITEM_ORANGE_MAIL));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ORANGE_MAIL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_ORANGE_MAIL);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the user's held item is a Mega Stone")
{
    GIVEN {
        PLAYER(SPECIES_BLAZIKEN) { Item(ITEM_BLAZIKENITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_BLAZIKENITE);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the user's held item is a Z-Crystal")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FIGHTINIUM_Z) == HOLD_EFFECT_Z_CRYSTAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FIGHTINIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_FIGHTINIUM_Z);
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Bestow doesn't fail if the user has Sticky Hold")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BESTOW, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(opponent->item == ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the target is behind a Substitute (Gen 6+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_BESTOW); }
    } SCENE {
        if (B_UPDATED_MOVE_FLAGS >= GEN_6) {
            NOT MESSAGE("But it failed!");
        } else {
            MESSAGE("But it failed!");
        }
    } THEN {
        if (B_UPDATED_MOVE_FLAGS >= GEN_6) {
            EXPECT(player->item == ITEM_NONE);
            EXPECT(opponent->item == ITEM_SITRUS_BERRY);
        } else {
            EXPECT(player->item == ITEM_SITRUS_BERRY);
            EXPECT(opponent->item == ITEM_NONE);
        }
    }
}

SINGLE_BATTLE_TEST("Bestow fails if the user's held item changes its form")
{
    GIVEN {
        PLAYER(SPECIES_GIRATINA_ORIGIN) { Item(ITEM_GRISEOUS_CORE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_GRISEOUS_CORE);
        EXPECT(opponent->item == ITEM_NONE);
    }
}
