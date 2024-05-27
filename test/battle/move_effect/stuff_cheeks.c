#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_STUFF_CHEEKS].effect == EFFECT_STUFF_CHEEKS);
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].pocket == POCKET_BERRIES);
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
}

SINGLE_BATTLE_TEST("Stuff Cheeks cannot be used if the user doesn't hold a berry")
{
    u16 item = 0;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; }
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item == ITEM_NONE)
            TURN { MOVE(player, MOVE_STUFF_CHEEKS, allowed: FALSE); MOVE(player, MOVE_CELEBRATE); }
        else
            TURN { MOVE(player, MOVE_STUFF_CHEEKS); }
    } SCENE {
        if (item == ITEM_NONE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STUFF_CHEEKS, player);
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks forces Struggle if it's the only move is blocked")
{
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Moves(MOVE_STUFF_CHEEKS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STUFF_CHEEKS, allowed: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks raises Defense by 2 stages after consuming the berry and gaining its effect")
{
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STUFF_CHEEKS); }
    } SCENE {
        MESSAGE("Skwovet used Stuff Cheeks!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUFF_CHEEKS, player);
        MESSAGE("Using Liechi Berry, the Attack of Skwovet rose!");
        MESSAGE("Skwovet's Defense sharply rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks can be used even if Unnerve is present")
{
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_UNNERVE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUFF_CHEEKS); }
    } SCENE {
        MESSAGE("Skwovet used Stuff Cheeks!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUFF_CHEEKS, player);
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks can be used even if Magic Room is active")
{
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_MAGIC_ROOM);
            MOVE(player, MOVE_STUFF_CHEEKS);
        }
    } SCENE {
        MESSAGE("Skwovet used Stuff Cheeks!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUFF_CHEEKS, player);
        MESSAGE("Using Liechi Berry, the Attack of Skwovet rose!");
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks fails if the user's berry is removed before they use the move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_KNOCK_OFF].effect == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_SKWOVET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); MOVE(player, MOVE_STUFF_CHEEKS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        MESSAGE("Skwovet used Stuff Cheeks!");
        MESSAGE("But it failed!");
    }
}
