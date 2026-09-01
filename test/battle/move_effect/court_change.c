#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_COURT_CHANGE) == EFFECT_COURT_CHANGE);
}

SINGLE_BATTLE_TEST("Court Change swaps entry hazard counts together with the hazard queues")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_COURT_CHANGE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[B_SIDE_PLAYER][0], HAZARDS_TOXIC_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[B_SIDE_OPPONENT][0], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->numHazards[B_SIDE_PLAYER], 1);
        EXPECT_EQ(gBattleStruct->numHazards[B_SIDE_OPPONENT], 0);
    }
}

DOUBLE_BATTLE_TEST("Court Change swaps entry hazards used by the opponent")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(opponentRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponentLeft, MOVE_SPIKES); MOVE(opponentRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(playerLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(playerLeft, 2); SWITCH(opponentLeft, 2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Sticky Web!");
        MESSAGE("The opposing Wobbuffet used Stealth Rock!");
        MESSAGE("The opposing Wobbuffet used Spikes!");
        MESSAGE("The opposing Wobbuffet used Toxic Spikes!");
        MESSAGE("Wynaut used Court Change!");
        MESSAGE("Wynaut swapped the battle effects affecting each side of the field!");
        SEND_IN_MESSAGE("Wynaut");
        NONE_OF {
            MESSAGE("Wynaut was caught in a sticky web!");
            MESSAGE("Pointed stones dug into Wynaut!");
            MESSAGE("Wynaut was hurt by the spikes!");
            MESSAGE("Wynaut was poisoned!");
        }
        MESSAGE("2 sent out Wobbuffet!");
        MESSAGE("The opposing Wobbuffet was caught in a sticky web!");
        MESSAGE("Pointed stones dug into the opposing Wobbuffet!");
        MESSAGE("The opposing Wobbuffet was hurt by the spikes!");
        MESSAGE("The opposing Wobbuffet was poisoned!");
    }
}

DOUBLE_BATTLE_TEST("Court Change swaps entry hazards used by the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB); MOVE(playerRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(playerLeft, MOVE_SPIKES); MOVE(playerRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(opponentLeft, 2); SWITCH(playerLeft, 2); }
    } SCENE {
        MESSAGE("Wobbuffet used Sticky Web!");
        MESSAGE("Wobbuffet used Stealth Rock!");
        MESSAGE("Wobbuffet used Spikes!");
        MESSAGE("Wobbuffet used Toxic Spikes!");
        MESSAGE("The opposing Wynaut used Court Change!");
        MESSAGE("The opposing Wynaut swapped the battle effects affecting each side of the field!");
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("Wobbuffet was caught in a sticky web!");
        MESSAGE("Pointed stones dug into Wobbuffet!");
        MESSAGE("Wobbuffet was hurt by the spikes!");
        MESSAGE("Wobbuffet was poisoned!");
        MESSAGE("2 sent out Wynaut!");
        NONE_OF {
            MESSAGE("The opposing Wynaut was caught in a sticky web!");
            MESSAGE("Pointed stones dug into the opposing Wynaut!");
            MESSAGE("The opposing Wynaut was hurt by the spikes!");
            MESSAGE("The opposing Wynaut was poisoned!");
        }
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps Mist, Safeguard, Aurora Veil, Reflect, Light Screen, Tailwind")
{
    GIVEN {
        WITH_CONFIG(B_TAILWIND_TURNS, GEN_5);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SNOWSCAPE); MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(opponentLeft, MOVE_AURORA_VEIL); MOVE(opponentRight, MOVE_REFLECT); }
        TURN { MOVE(opponentLeft, MOVE_LIGHT_SCREEN); MOVE(opponentRight, MOVE_TAILWIND); }
        TURN { MOVE(playerLeft, MOVE_COURT_CHANGE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wynaut used Snowscape!");
        MESSAGE("The opposing Wobbuffet used Mist!");
        MESSAGE("The opposing Wobbuffet used Safeguard!");
        MESSAGE("The opposing Wobbuffet used Aurora Veil!");
        MESSAGE("The opposing Wobbuffet used Reflect!");
        MESSAGE("The opposing Wobbuffet used Light Screen!");
        MESSAGE("The opposing Wobbuffet used Tailwind!");
        MESSAGE("Wynaut used Court Change!");
        MESSAGE("Wynaut swapped the battle effects affecting each side of the field!");
        // The effects now end for the player side.
        MESSAGE("Your side is no longer protected by the mystical veil!");
        MESSAGE("Your side's Mist wore off!");
        MESSAGE("Your side's Reflect wore off!");
        MESSAGE("Your side's tailwind petered out!");
        MESSAGE("Your side's Aurora Veil wore off!");
        MESSAGE("Your side's Light Screen wore off!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the opponent swaps Mist, Safeguard, Aurora Veil, Reflect, Light Screen, Tailwind")
{
    GIVEN {
        WITH_CONFIG(B_TAILWIND_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SNOWSCAPE); MOVE(playerLeft, MOVE_MIST); MOVE(playerRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, MOVE_AURORA_VEIL); MOVE(playerRight, MOVE_REFLECT); }
        TURN { MOVE(playerLeft, MOVE_LIGHT_SCREEN); MOVE(playerRight, MOVE_TAILWIND); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Mist!");
        MESSAGE("Wobbuffet used Safeguard!");
        MESSAGE("Wobbuffet used Aurora Veil!");
        MESSAGE("Wobbuffet used Reflect!");
        MESSAGE("Wobbuffet used Light Screen!");
        MESSAGE("Wobbuffet used Tailwind!");
        MESSAGE("The opposing Wynaut used Court Change!");
        MESSAGE("The opposing Wynaut swapped the battle effects affecting each side of the field!");
        // The effects now end for the player side.
        MESSAGE("The snow stopped.");
        MESSAGE("The opposing side is no longer protected by the mystical veil!");
        MESSAGE("The opposing side's Mist wore off!");
        MESSAGE("The opposing side's Reflect wore off!");
        MESSAGE("The opposing side's tailwind petered out!");
        MESSAGE("The opposing side's Aurora Veil wore off!");
        MESSAGE("The opposing side's Light Screen wore off!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps G-Max Steelsurge")
{
    GIVEN {
        PLAYER(SPECIES_COPPERAJAH) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT) { HP(999); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_IRON_HEAD, target: opponentRight, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(opponentLeft, 2); SWITCH(playerLeft, 2); }
    } SCENE {
        MESSAGE("Copperajah used G-Max Steelsurge!");
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("The sharp steel bit into Wobbuffet!");
        NOT MESSAGE("The sharp steel bit into the opposing Wynaut!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps G-Max Vine Lash, G-Max Wildfire, G-Max Cannonade")
{
    enum Species species;
    enum Move move;
    PARAMETRIZE { species = SPECIES_VENUSAUR;  move = MOVE_VINE_WHIP; }
    PARAMETRIZE { species = SPECIES_CHARIZARD; move = MOVE_EMBER; }
    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_WATER_GUN; }
    GIVEN {
        PLAYER(species) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, move, target: opponentRight, gimmick: GIMMICK_DYNAMAX);
            MOVE(opponentLeft, MOVE_COURT_CHANGE);
        }
    } SCENE {
        switch (species) {
            case SPECIES_VENUSAUR:
                MESSAGE("Venusaur used G-Max Vine Lash!");
                MESSAGE("Wobbuffet is hurt by G-Max Vine Lash's ferocious beating!");
                break;
            case SPECIES_CHARIZARD:
                MESSAGE("Charizard used G-Max Wildfire!");
                MESSAGE("Wobbuffet is burning up within G-Max Wildfire's flames!");
                break;
            case SPECIES_BLASTOISE:
                MESSAGE("Blastoise used G-Max Cannonade!");
                MESSAGE("Wobbuffet is hurt by G-Max Cannonade's vortex!");
                break;
            default:
                break;
        }
        NONE_OF {
            MESSAGE("The opposing Wynaut is hurt by G-Max Vine Lash's ferocious beating!");
            MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
            MESSAGE("The opposing Wynaut is hurt by G-Max Cannonade's vortex!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Court Change")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HEADBUTT; }
    PARAMETRIZE { move = MOVE_REFLECT; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; }
    PARAMETRIZE { move = MOVE_SAFEGUARD; }
    PARAMETRIZE { move = MOVE_SPIKES; }
    PARAMETRIZE { move = MOVE_STEALTH_ROCK; }
    PARAMETRIZE { move = MOVE_TOXIC_SPIKES; }
    PARAMETRIZE { move = MOVE_TAILWIND; }
    PARAMETRIZE { move = MOVE_STICKY_WEB; }
    PARAMETRIZE { move = MOVE_MIST; }
    PARAMETRIZE { move = MOVE_LUCKY_CHANT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(move, MOVE_CELEBRATE); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(move, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_COURT_CHANGE, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_COURT_CHANGE, MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, MOVE_HEADBUTT); }
        if (move == MOVE_HEADBUTT)
            TURN { MOVE(player, MOVE_CELEBRATE); NOT_EXPECT_MOVE(opponent, MOVE_COURT_CHANGE); }
        else
            TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_COURT_CHANGE); }
    }
}
