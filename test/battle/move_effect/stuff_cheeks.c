#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STUFF_CHEEKS) == EFFECT_STUFF_CHEEKS);
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].pocket == POCKET_BERRIES);
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
}

SINGLE_BATTLE_TEST("Stuff Cheeks cannot be used if the user doesn't hold a berry (Gen8-9)")
{
    enum Item item = ITEM_NONE;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; }
    GIVEN {
        WITH_CONFIG(B_STUFF_CHEEKS_SELECTABLE, GEN_9);
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
        WITH_CONFIG(B_STUFF_CHEEKS_SELECTABLE, GEN_9);
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
        MESSAGE("The Liechi Berry boosted Skwovet's Attack!");
        MESSAGE("Skwovet's Defense rose sharply!");
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
        MESSAGE("The Liechi Berry boosted Skwovet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Stuff Cheeks fails if the user's berry is removed before they use the move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
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

AI_SINGLE_BATTLE_TEST("AI uses Stuff Cheeks")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STUFF_CHEEKS) == EFFECT_STUFF_CHEEKS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_HEADBUTT); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); Moves(MOVE_HEADBUTT, MOVE_STUFF_CHEEKS); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_STUFF_CHEEKS); }
    }
}
