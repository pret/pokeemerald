#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TOXIC_SPIKES].effect == EFFECT_TOXIC_SPIKES);
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
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
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
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
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
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
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
    u32 species = SPECIES_WOBBUFFET;
    u32 item = ITEM_NONE;
    u32 move1 = MOVE_CELEBRATE;
    u32 move2 = MOVE_CELEBRATE;
    bool32 airborne;

    ASSUME(gSpeciesInfo[SPECIES_PIDGEY].types[1] == TYPE_FLYING);
    PARAMETRIZE { species = SPECIES_PIDGEY; airborne = TRUE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_INGRAIN; airborne = FALSE; }

    ASSUME(gSpeciesInfo[SPECIES_UNOWN].abilities[0] == ABILITY_LEVITATE);
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
        ASSUME(gSpeciesInfo[SPECIES_STEELIX].types[0] == TYPE_STEEL);
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
    u32 species;
    u32 item = ITEM_NONE;
    u32 move = MOVE_CELEBRATE;
    bool32 grounded;
    PARAMETRIZE { species = SPECIES_EKANS; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; grounded = FALSE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; item = ITEM_IRON_BALL; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; move = MOVE_GRAVITY; grounded = TRUE; }
    PARAMETRIZE { species = SPECIES_ZUBAT; move = MOVE_INGRAIN; grounded = TRUE; }
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_EKANS].types[0] == TYPE_POISON);
        ASSUME(gSpeciesInfo[SPECIES_ZUBAT].types[0] == TYPE_POISON);
        ASSUME(gSpeciesInfo[SPECIES_ZUBAT].types[1] == TYPE_FLYING);
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
            MESSAGE("The poison spikes disappeared from around the opposing team's feet!");
            NOT STATUS_ICON(opponent, poison: TRUE);
        } else {
            NOT STATUS_ICON(opponent, poison: TRUE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

// This would test for what I believe to be a bug in the mainline games.
// A Pokémon that gets passed magnet rise should still remove the Toxic
// Spikes even though it is airborne.
// The test currently fails, because we don't incorporate this bug.
SINGLE_BATTLE_TEST("Toxic Spikes are removed by Poison-type Pokémon affected by Magnet Rise on switch in")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_EKANS].types[0] == TYPE_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        NOT STATUS_ICON(opponent, poison: TRUE);
        MESSAGE("The poison spikes disappeared from around the opposing team's feet!");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes inflicts poison on switch in after Primal Reversed mon fainted") // Oddly specific, but encountered during testing
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_MEMENTO].effect == EFFECT_MEMENTO); // Faints the user.
        PLAYER(SPECIES_WOBBUFFET) {Speed(5); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(1); }
        PLAYER(SPECIES_WYNAUT) {Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(15); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_MEMENTO); SEND_OUT(player, 2); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Toxic Spikes!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        MESSAGE("Poison Spikes were scattered all around your team's feet!");
        // Switch in
        MESSAGE("Go! Groudon!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal form!");
        // Memento
        MESSAGE("Groudon used Memento!");
        MESSAGE("Groudon fainted!");
        // 2nd switch-in
        MESSAGE("Go! Wynaut!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
    }
}
