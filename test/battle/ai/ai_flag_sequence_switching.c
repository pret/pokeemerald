#include "global.h"
#include "test/battle.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_SEQUENCE_SWITCHING: AI will always switch after a KO in exactly party order")
{
    u32 aiSequenceSwitchingFlag = 0;

    PARAMETRIZE { aiSequenceSwitchingFlag = 0; }
    PARAMETRIZE { aiSequenceSwitchingFlag = AI_FLAG_SEQUENCE_SWITCHING; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSequenceSwitchingFlag);
        PLAYER(SPECIES_SWELLOW) { Level (50); }
        OPPONENT(SPECIES_MACHOP) { Level(5); }
        OPPONENT(SPECIES_MACHOKE) { Level(5); }
        OPPONENT(SPECIES_MACHAMP) { Level(5); }
        OPPONENT(SPECIES_MANKEY) { Level(5); }
        OPPONENT(SPECIES_PRIMEAPE) { Level(5); }
        OPPONENT(SPECIES_MAGNEZONE) { Level(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_WING_ATTACK); }
        if (aiSequenceSwitchingFlag) {
            TURN { MOVE(player, MOVE_WING_ATTACK); }
            TURN { MOVE(player, MOVE_WING_ATTACK); }
            TURN { MOVE(player, MOVE_WING_ATTACK); }
            TURN { MOVE(player, MOVE_WING_ATTACK); }
        }
    } SCENE {
        if (aiSequenceSwitchingFlag) {
            MESSAGE("{PKMN} TRAINER LEAF sent out Machoke!");
            MESSAGE("{PKMN} TRAINER LEAF sent out Machamp!");
            MESSAGE("{PKMN} TRAINER LEAF sent out Mankey!");
            MESSAGE("{PKMN} TRAINER LEAF sent out Primeape!");
            MESSAGE("{PKMN} TRAINER LEAF sent out Magnezone!");
        }
        else {
            MESSAGE("{PKMN} TRAINER LEAF sent out Magnezone!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SEQUENCE_SWITCHING: Roar and Dragon Tail still force switch to random party member")
{
    u32 move;

    PARAMETRIZE { move = MOVE_ROAR; }
    PARAMETRIZE {move = MOVE_DRAGON_TAIL; }

    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ROAR].effect == EFFECT_ROAR);
        ASSUME(gMovesInfo[MOVE_DRAGON_TAIL].effect == EFFECT_HIT_SWITCH_TARGET);
        AI_FLAGS(AI_FLAG_SEQUENCE_SWITCHING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Foe Bulbasaur was dragged out!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SEQUENCE_SWITCHING: AI will always switch into lowest party index after U-Turn, Parting Shot, Baton Pass, and Chilly Reception")
{
    u32 j, aiSequenceSwitchingFlag = 0, move = MOVE_NONE;

    static const u32 switchMoves[] = {
        MOVE_U_TURN,
        MOVE_PARTING_SHOT,
        MOVE_BATON_PASS,
        MOVE_CHILLY_RECEPTION,
    };

    for (j = 0; j < ARRAY_COUNT(switchMoves); j++)
    {
        PARAMETRIZE { aiSequenceSwitchingFlag = 0;                           move = switchMoves[j]; }
        PARAMETRIZE { aiSequenceSwitchingFlag = AI_FLAG_SEQUENCE_SWITCHING;  move = switchMoves[j]; }
    }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_U_TURN].effect == EFFECT_HIT_ESCAPE);
        ASSUME(gMovesInfo[MOVE_PARTING_SHOT].effect == EFFECT_PARTING_SHOT);
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        ASSUME(gMovesInfo[MOVE_CHILLY_RECEPTION].effect == EFFECT_CHILLY_RECEPTION);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSequenceSwitchingFlag);
        PLAYER(SPECIES_SWELLOW) { Level (50); }
        OPPONENT(SPECIES_MACHOP) { Level(1); Moves(move); }
        OPPONENT(SPECIES_MACHOP) { Level(2); Moves(move); }
        OPPONENT(SPECIES_MACHOP) { Level(3); Moves(move); }
        OPPONENT(SPECIES_MACHOP) { Level(4); Moves(move); }
        OPPONENT(SPECIES_MACHOP) { Level(5); Moves(move); }
        OPPONENT(SPECIES_MAGNEZONE) { Level(100); Moves(move); }
    } WHEN {
        if (aiSequenceSwitchingFlag) {
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 1); }
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 0); }
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 1); }
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 0); }
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 1); }
        }
        else {
            TURN { EXPECT_MOVE(opponent, move) ; EXPECT_SEND_OUT(opponent, 5); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SEQUENCE_SWITCHING: AI will not switch mid-battle")
{
    u32 aiSequenceSwitchingFlag = 0;

    PARAMETRIZE { aiSequenceSwitchingFlag = 0; }
    PARAMETRIZE { aiSequenceSwitchingFlag = AI_FLAG_SEQUENCE_SWITCHING; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSequenceSwitchingFlag);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_LICK); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_KARATE_CHOP); }
    } WHEN {
        if (aiSequenceSwitchingFlag == AI_FLAG_SEQUENCE_SWITCHING) {
            TURN { MOVE(player, MOVE_LICK) ; EXPECT_MOVE(opponent, MOVE_SHADOW_BALL); }
        }
        else {
            TURN { MOVE(player, MOVE_LICK) ; EXPECT_SWITCH(opponent, 1); }
        }
    }
}
