#include "global.h"
#include "test/battle.h"

WILD_BATTLE_TEST("Ball Fetch causes the Pokémon to pick up the last failed Ball at the end of the turn")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_POKE_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; }
    PARAMETRIZE { item = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_STRANGE_BALL; }
    PARAMETRIZE { item = ITEM_X_ACCURACY; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN {}
    } SCENE {
        if (item != ITEM_X_ACCURACY)
            ABILITY_POPUP(player, ABILITY_BALL_FETCH);
        else
            NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        if (item != ITEM_X_ACCURACY)
            EXPECT_EQ(player->item, item);
        else
            EXPECT_EQ(player->item, ITEM_NONE);
    }
}

WILD_BATTLE_TEST("Ball Fetch doesn't trigger if the Pokémon is already holding an item")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_NUGGET; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); Item(item); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GREAT_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        if (item == ITEM_NONE)
        {
            MESSAGE("You used Great Ball!");
            ABILITY_POPUP(player, ABILITY_BALL_FETCH);
            MESSAGE("Yamper found a Great Ball!");
        }
        else
        {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_BALL_FETCH);
                MESSAGE("Yamper found a Great Ball!");
            }
        }
    } THEN {
        if (item == ITEM_NONE)
            EXPECT_EQ(player->item, ITEM_GREAT_BALL);
        else
            EXPECT_EQ(player->item, item);
    }
}

WILD_BATTLE_TEST("Ball Fetch only picks up the first failed ball, once per battle")
{
    enum Item item = ITEM_NONE;
    enum Item item2 = ITEM_NONE;

    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_X_ACCURACY; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_FAST_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; item2 = ITEM_STRANGE_BALL; }


    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
        TURN { MOVE(player, MOVE_BESTOW); }
        TURN { USE_ITEM(player, item2, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16)); }
    } SCENE {
        MESSAGE("You used Great Ball!");
        ABILITY_POPUP(player, ABILITY_BALL_FETCH);
        MESSAGE("Yamper found a Great Ball!");
        MESSAGE("Yamper used Bestow!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BESTOW, player);
        MESSAGE("The wild Metagross received Great Ball from Yamper!");
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Ball Fetch doesn't trigger in Trainer Battles")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_POKE_BALL; }
    PARAMETRIZE { item = ITEM_GREAT_BALL; }
    PARAMETRIZE { item = ITEM_ULTRA_BALL; }
    PARAMETRIZE { item = ITEM_STRANGE_BALL; }
    PARAMETRIZE { item = ITEM_X_ACCURACY; }

    GIVEN {
        PLAYER(SPECIES_YAMPER) { Ability(ABILITY_BALL_FETCH); }
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_BALL_FETCH);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

TO_DO_BATTLE_TEST("Ball Fetch doesn't trigger in Max Raid Battles");
