#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
}

SINGLE_BATTLE_TEST("Toxic Spikes inflicts poison on switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes inflicts bad poison on switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes fails after 2 layers")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        MESSAGE("Wobbuffet used Toxic Spikes!");
        MESSAGE("But it failed!");
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes inflicts poison on subsequent switch ins")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN {}
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes do not poison airborne Pokemon")
{
    enum Species species = SPECIES_WOBBUFFET;
    enum Item item = ITEM_NONE;
    enum Move move1 = MOVE_CELEBRATE;
    enum Move move2 = MOVE_CELEBRATE;
    bool32 airborne;

    ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
    PARAMETRIZE { species = SPECIES_PIDGEY; airborne = TRUE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_INGRAIN; airborne = FALSE; }

    ASSUME(GetSpeciesAbility(SPECIES_UNOWN, 0) == ABILITY_LEVITATE);
    PARAMETRIZE { species = SPECIES_UNOWN; airborne = TRUE; }
    PARAMETRIZE { species = SPECIES_UNOWN; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_UNOWN; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_UNOWN; move1 = MOVE_INGRAIN; airborne = FALSE; }

    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; airborne = TRUE; }
    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; move2 = MOVE_GRAVITY; airborne = FALSE; }
    // Magnet Rise fails under Gravity.
    // Magnet Rise fails under Ingrain and vice-versa.

    PARAMETRIZE { item = ITEM_AIR_BALLOON; airborne = TRUE; }
    PARAMETRIZE { item = ITEM_AIR_BALLOON; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { item = ITEM_AIR_BALLOON; move1 = MOVE_INGRAIN; airborne = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, move1); }
        TURN { MOVE(opponent, move2); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } SCENE {
        if (airborne) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        } else {
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes do not affect Steel-types")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_STEELIX, 0) == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STEELIX);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes are removed by grounded Poison-type Pokémon on switch in")
{
    enum Species species;
    enum Item item = ITEM_NONE;
    enum Move move = MOVE_CELEBRATE;
    bool32 grounded;
    PARAMETRIZE { species = SPECIES_EKANS; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; grounded = FALSE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; item = ITEM_IRON_BALL; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; move = MOVE_GRAVITY; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; move = MOVE_INGRAIN; grounded = TRUE; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        ASSUME(GetSpeciesType(SPECIES_ZUBAT, 0) == TYPE_POISON);
        ASSUME(GetSpeciesType(SPECIES_ZUBAT, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        if (grounded) {
            NOT STATUS_ICON(opponent, poison: TRUE);
            MESSAGE("The toxic spikes disappeared from the ground around the opposing side!");
            NOT STATUS_ICON(opponent, poison: TRUE);
        } else {
            NOT STATUS_ICON(opponent, poison: TRUE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

//  Tested in Gen 7 on cartridge
SINGLE_BATTLE_TEST("Toxic Spikes are not removed by Poison-type Pokémon affected by Magnet Rise on switch in")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_EKANS, 0) == TYPE_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        NOT MESSAGE("The toxic spikes disappeared from the ground around the opposing side!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes inflicts poison on switch in after Primal Reversed mon fainted") // Oddly specific, but encountered during testing
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MEMENTO) == EFFECT_MEMENTO); // Faints the user.
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(15); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_MEMENTO); SEND_OUT(player, 2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Toxic Spikes!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        MESSAGE("Toxic spikes were scattered on the ground all around your side!");
        // Switch in
        SEND_IN_MESSAGE("Groudon");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
        // Memento
        MESSAGE("Groudon used Memento!");
        MESSAGE("Groudon fainted!");
        // 2nd switch-in
        SEND_IN_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes print normal poison for 1 layer")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wynaut was poisoned!");
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes print bad poison for 2 layers")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wynaut was badly poisoned!");
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes: Only two layers can be set up")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_TOXIC_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
        u32 toxicSpikesAmount = gSideTimers[0].toxicSpikesAmount;
        EXPECT_EQ(toxicSpikesAmount, 2);
    }
}
