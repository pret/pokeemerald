#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shed Skin triggers 33% of the time (Gen 3)")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    // PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }

    PASSES_RANDOMLY(33, 100, RNG_SHED_SKIN);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_3);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Status1(status); Ability(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN;
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHED_SKIN);
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("The opposing Arbok's burn was cured!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("The opposing Arbok was cured of paralysis!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("The opposing Arbok's frostbite was cured!");
                break;
            case STATUS1_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("The opposing Arbok woke up!");
                break;
        }
        STATUS_ICON(opponent, poison: FALSE);
    }
}

SINGLE_BATTLE_TEST("Shed Skin triggers 30% of the time (Gen 4)")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    // PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }

    PASSES_RANDOMLY(30, 100, RNG_SHED_SKIN);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_4);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Status1(status); Ability(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN;
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHED_SKIN);
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("The opposing Arbok's burn was cured!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("The opposing Arbok was cured of paralysis!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("The opposing Arbok's frostbite was cured!");
                break;
            case STATUS1_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("The opposing Arbok woke up!");
                break;
        }
        STATUS_ICON(opponent, poison: FALSE);
    }
}

SINGLE_BATTLE_TEST("Shed Skin triggers 33% of the time (Gen 5)")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    // PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }

    PASSES_RANDOMLY(33, 100, RNG_SHED_SKIN);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, GEN_5);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Status1(status); Ability(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN;
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHED_SKIN);
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("The opposing Arbok's burn was cured!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("The opposing Arbok was cured of paralysis!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("The opposing Arbok's frostbite was cured!");
                break;
            case STATUS1_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("The opposing Arbok was cured of its poisoning!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("The opposing Arbok woke up!");
                break;
        }
        STATUS_ICON(opponent, poison: FALSE);
    }
}
