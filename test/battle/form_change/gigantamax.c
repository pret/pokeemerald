#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dynamax: Pokemon with Gigantamax forms change upon Dynamaxing")
{
    enum Species species;
    bool32 gigantamaxFactor;
    PARAMETRIZE { gigantamaxFactor = FALSE; species = SPECIES_VENUSAUR; }
    PARAMETRIZE { gigantamaxFactor = TRUE; species = SPECIES_VENUSAUR_GMAX; }
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { GigantamaxFactor(gigantamaxFactor); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Pokemon with Gigantamax forms revert upon switching")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Venusaur returns its base Form upon battle end after Gigantamaxing")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Venusaur returns its base Form upon fainting end after Gigantamaxing")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { HP(1); GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR);
    }
}
