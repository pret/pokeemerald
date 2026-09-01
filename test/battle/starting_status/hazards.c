#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("SetStartingStatus can start Spikes on the opposing side", s16 damage)
{
    u16 startingHazard;
    u32 divisor;

    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_OPPONENT_L1; divisor = 8; }
    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_OPPONENT_L2; divisor = 6; }
    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_OPPONENT_L3; divisor = 4; }

    SetStartingStatus(startingHazard);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / divisor);
        MESSAGE("The opposing Wynaut was hurt by the spikes!");
    } FINALLY {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes poison the opposing switch-in")
{
    SetStartingStatus(STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L1);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
        NOT STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes badly poison the opposing switch-in")
{
    SetStartingStatus(STARTING_STATUS_TOXIC_SPIKES_OPPONENT_L2);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was badly poisoned!");
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Sticky Web lowers Speed on entry")
{
    SetStartingStatus(STARTING_STATUS_STICKY_WEB_OPPONENT);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATICATE);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("The opposing Wynaut was caught in a sticky web!");
        MESSAGE("The opposing Wynaut's Speed fell!");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Stealth Rock damages the opposing switch-in")
{
    SetStartingStatus(STARTING_STATUS_STEALTH_ROCK_OPPONENT);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CHARIZARD].types[0] == TYPE_FIRE);
        ASSUME(gSpeciesInfo[SPECIES_CHARIZARD].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARIZARD);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Charizard!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / 2);
        MESSAGE("Pointed stones dug into the opposing Charizard!");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting sharp steel damages the opposing switch-in")
{
    SetStartingStatus(STARTING_STATUS_SHARP_STEEL_OPPONENT);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SYLVEON].types[0] == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SYLVEON);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 sent out Sylveon!");
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponent, damage: maxHP / 4);
        MESSAGE("The sharp steel bit into the opposing Sylveon!");
    } THEN {
        ResetStartingStatuses();
    }
}

// Player-side hazard tests

SINGLE_BATTLE_TEST("SetStartingStatus can start Spikes on the player side", s16 damage)
{
    u16 startingHazard;
    u32 divisor;

    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_PLAYER_L1; divisor = 8; }
    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_PLAYER_L2; divisor = 6; }
    PARAMETRIZE { startingHazard = STARTING_STATUS_SPIKES_PLAYER_L3; divisor = 4; }

    SetStartingStatus(startingHazard);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
        s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(player, damage: maxHP / divisor);
        MESSAGE("Wynaut was hurt by the spikes!");
    } FINALLY {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes poison the player's switch-in")
{
    SetStartingStatus(STARTING_STATUS_TOXIC_SPIKES_PLAYER_L1);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
        MESSAGE("Wynaut was poisoned!");
        STATUS_ICON(player, poison: TRUE);
        NOT STATUS_ICON(player, badPoison: TRUE);
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Toxic Spikes badly poison the player's switch-in")
{
    SetStartingStatus(STARTING_STATUS_TOXIC_SPIKES_PLAYER_L2);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
        MESSAGE("Wynaut was badly poisoned!");
        STATUS_ICON(player, badPoison: TRUE);
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Sticky Web lowers Speed on player's entry")
{
    SetStartingStatus(STARTING_STATUS_STICKY_WEB_PLAYER);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
        MESSAGE("Wynaut was caught in a sticky web!");
        MESSAGE("Wynaut's Speed fell!");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting Stealth Rock damages the player's switch-in")
{
    SetStartingStatus(STARTING_STATUS_STEALTH_ROCK_PLAYER);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CHARIZARD].types[0] == TYPE_FIRE);
        ASSUME(gSpeciesInfo[SPECIES_CHARIZARD].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHARIZARD);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Charizard!");
        s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(player, damage: maxHP / 2);
        MESSAGE("Pointed stones dug into Charizard!");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Starting sharp steel damages the player's switch-in")
{
    SetStartingStatus(STARTING_STATUS_SHARP_STEEL_PLAYER);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SYLVEON].types[0] == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_SYLVEON);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Go! Sylveon!");
        s32 maxHP = GetMonData(&PLAYER_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(player, damage: maxHP / 4);
        MESSAGE("The sharp steel bit into Sylveon!");
    } THEN {
        ResetStartingStatuses();
    }
}
