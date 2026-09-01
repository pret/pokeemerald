#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
    ASSUME(GetMoveType(MOVE_CRUNCH) == TYPE_DARK);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_DOUBLE_ACE_POKEMON: U-Turn won't send out any of the Ace Mons if other options exist")
{
    u32 flag;

    PARAMETRIZE { flag = AI_FLAG_DOUBLE_ACE_POKEMON; }
    PARAMETRIZE { flag = 0; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_SMART_SWITCHING | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | flag);

        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);

        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_DUSKULL) { Moves(MOVE_U_TURN); }

        OPPONENT(SPECIES_HAUNTER) { Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_U_TURN); }

        // Aces
        // Crunch is super effective against Wobbuffet Psychic type, so normally the AI would switch them in
        OPPONENT(SPECIES_POOCHYENA) { Moves(MOVE_CRUNCH); }
        OPPONENT(SPECIES_MIGHTYENA) { Moves(MOVE_CRUNCH); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_U_TURN);
            EXPECT_MOVE(opponentRight, MOVE_U_TURN);

            if(flag == AI_FLAG_DOUBLE_ACE_POKEMON) {
                EXPECT_SEND_OUT(opponentLeft, 3);
                EXPECT_SEND_OUT(opponentRight, 2);
            } else {
                EXPECT_SEND_OUT(opponentLeft, 4);
                EXPECT_SEND_OUT(opponentRight, 5);
            }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_DOUBLE_ACE_POKEMON: U-Turn will send out an Ace Mon if no other options remain")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_SMART_SWITCHING | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_DOUBLE_ACE_POKEMON);

        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }

        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_U_TURN); Level(50); }
        OPPONENT(SPECIES_DUSKULL) { Moves(MOVE_U_TURN); Level(5); }

        // Aces
        // Should choose Poochyena as its level is higher.
        OPPONENT(SPECIES_MIGHTYENA) { Moves(MOVE_CRUNCH); Level(5); }
        OPPONENT(SPECIES_POOCHYENA) { Moves(MOVE_CRUNCH); Level(50); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_U_TURN);
            EXPECT_MOVE(opponentRight, MOVE_U_TURN);

            EXPECT_SEND_OUT(opponentLeft, 3);
            EXPECT_SEND_OUT(opponentRight, 0);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_DOUBLE_ACE_POKEMON: Ace mons won't be switched in even if they are the best candidates")
{
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        ASSUME(GetSpeciesType(SPECIES_GENGAR, 0) == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_SMART_SWITCHING | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_DOUBLE_ACE_POKEMON);

        PLAYER(SPECIES_GENGAR) { Level(10); }
        PLAYER(SPECIES_GENGAR) { Level(10); }

        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); Level(10); }
        OPPONENT(SPECIES_PSYDUCK) { Moves(MOVE_SCRATCH); Level(10); }

        OPPONENT(SPECIES_ABRA) { Moves(MOVE_ABSORB); Level(20); }

        // Aces
        OPPONENT(SPECIES_MIGHTYENA) { Moves(MOVE_CRUNCH); Level(50); }
        OPPONENT(SPECIES_POOCHYENA) { Moves(MOVE_CRUNCH); Level(50); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 2); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_DOUBLE_ACE_POKEMON: Ace mons won't be switched in even if they are the best candidates (reversed)")
{
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        ASSUME(GetSpeciesType(SPECIES_GENGAR, 0) == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_SMART_SWITCHING | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_DOUBLE_ACE_POKEMON);

        PLAYER(SPECIES_GENGAR) { Level(10); }
        PLAYER(SPECIES_GENGAR) { Level(10); }

        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); Level(10); }
        OPPONENT(SPECIES_PSYDUCK) { Moves(MOVE_SCRATCH); Level(10); }

        OPPONENT(SPECIES_ABRA) { Moves(MOVE_ABSORB); Level(20); }

        // Aces
        OPPONENT(SPECIES_MIGHTYENA) { Moves(MOVE_CRUNCH); Level(50); }
        OPPONENT(SPECIES_POOCHYENA) { Moves(MOVE_CRUNCH); Level(50); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 2); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_DOUBLE_ACE_POKEMON: sends out Ace mons when no other options remain mid-battle")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_SMART_SWITCHING | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_DOUBLE_ACE_POKEMON);

        PLAYER(SPECIES_WOBBUFFET) { Level(50); Speed(200); Moves(MOVE_THUNDERBOLT, MOVE_CELEBRATE); SpAttack(200); }
        PLAYER(SPECIES_WOBBUFFET) { Level(50); Speed(150); Moves(MOVE_THUNDERBOLT, MOVE_CELEBRATE); SpAttack(200); }

        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); HP(1); Speed(1); Moves(MOVE_SPLASH); }
        OPPONENT(SPECIES_POOCHYENA) { Level(5); HP(1); Speed(1); Moves(MOVE_SPLASH); }

        // Aces
        OPPONENT(SPECIES_MIGHTYENA) { Level(50); Speed(10); Moves(MOVE_CRUNCH); }
        OPPONENT(SPECIES_GENGAR) { Level(50); Speed(10); Moves(MOVE_SPLASH); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentLeft, MOVE_SPLASH);
            EXPECT_MOVE(opponentRight, MOVE_SPLASH);
            EXPECT_SEND_OUT(opponentLeft, 3);
        }
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_THUNDERBOLT, target: opponentRight);
            EXPECT_MOVE(opponentLeft, MOVE_SPLASH);
            EXPECT_MOVE(opponentRight, MOVE_SPLASH);
            EXPECT_SEND_OUT(opponentRight, 2);
        }
    }
}
