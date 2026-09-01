#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves.")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_QUICK_ATTACK); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- conserves Z-move if target will faint anyway.")
{
    u32 currentHP;
    PARAMETRIZE { currentHP = 1; }
    PARAMETRIZE { currentHP = 500; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { HP(currentHP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_QUICK_ATTACK); }
    } WHEN {
    if (currentHP != 1)
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_NONE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves to ensure a low-accuracy KO.")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_TORKOAL; ability = ABILITY_DROUGHT; }
    PARAMETRIZE { species = SPECIES_PELIPPER; ability = ABILITY_DRIZZLE; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(species) { Ability(ability); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ELECTRIUM_Z); Moves(MOVE_THUNDER); }
    } WHEN {
    if (ability == ABILITY_DROUGHT)
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDER, gimmick: GIMMICK_Z_MOVE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDER, gimmick: GIMMICK_NONE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Extreme Evoboost")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EEVEE) { Item(ITEM_EEVIUM_Z); Moves(MOVE_POUND, MOVE_LAST_RESORT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT, gimmick: GIMMICK_Z_MOVE); }
        TURN { EXPECT_MOVE(opponent, MOVE_POUND, gimmick: GIMMICK_NONE);
               SCORE_LT_VAL(opponent, MOVE_LAST_RESORT, AI_SCORE_DEFAULT); }
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT, gimmick: GIMMICK_NONE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves to bypass move limitations")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_POUND, MOVE_LAST_RESORT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_LAST_RESORT, gimmick: GIMMICK_Z_MOVE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- 10,000,000 Volt Thunderbolt")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU_PARTNER) { Item(ITEM_PIKASHUNIUM_Z); Moves(MOVE_THUNDERBOLT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDERBOLT, gimmick: GIMMICK_Z_MOVE); }
    }
}
AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Conversion")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_OPPORTUNIST; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_CONVERSION) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Ability(ABILITY_ADAPTABILITY); Moves(MOVE_THUNDERBOLT, MOVE_CONVERSION); }
    } WHEN {
    if (ability == ABILITY_OPPORTUNIST)
        TURN { EXPECT_MOVE(opponent, MOVE_CONVERSION, gimmick: GIMMICK_NONE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_CONVERSION, gimmick: GIMMICK_Z_MOVE); }
    }
}


AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Destiny Bond is not used in singles")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_GHOSTIUM_Z); Moves(MOVE_DESTINY_BOND); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_DESTINY_BOND, gimmick: GIMMICK_NONE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Z-Moves -- Z-Destiny Bond is used when about to die")
{
    u32 currentHP;
    PARAMETRIZE { currentHP = 1; }
    PARAMETRIZE { currentHP = 500; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_POUND); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(currentHP); Item(ITEM_GHOSTIUM_Z); Moves(MOVE_DESTINY_BOND); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
    if (currentHP == 1)
        TURN { EXPECT_MOVE(opponentLeft, MOVE_DESTINY_BOND, gimmick: GIMMICK_Z_MOVE); }
    else
        TURN { EXPECT_MOVE(opponentLeft, MOVE_DESTINY_BOND, gimmick: GIMMICK_NONE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Detect")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THUNDERBOLT; }
    PARAMETRIZE { move = MOVE_CLOSE_COMBAT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_PREDICT_MOVE );
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FIGHTINIUM_Z); Moves(MOVE_DETECT, move); }
    } WHEN {
    if (move == MOVE_CLOSE_COMBAT)
        TURN { EXPECT_MOVE(opponent, MOVE_DETECT, gimmick: GIMMICK_NONE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_DETECT, gimmick: GIMMICK_Z_MOVE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Happy Hour")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_POUND, MOVE_HAPPY_HOUR); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HAPPY_HOUR, gimmick: GIMMICK_Z_MOVE);
               SCORE_GT_VAL(opponent, MOVE_HAPPY_HOUR, AI_SCORE_DEFAULT); }
        TURN { EXPECT_MOVE(opponent, MOVE_POUND, gimmick: GIMMICK_NONE);
               SCORE_EQ_VAL(opponent, MOVE_HAPPY_HOUR, 90); }
    }
}

TO_DO_BATTLE_TEST("TODO: AI uses Z-Moves -- Z-Haze")

TO_DO_BATTLE_TEST("TODO: AI uses Z-Moves -- Z-Mirror Move")

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Nature Power")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_PREDICT_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_NATURE_POWER, MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_NATURE_POWER, gimmick: GIMMICK_Z_MOVE); }
    }
}

// Requires handling for Wish passing/Healing Wish/other ways to determine what pokemon to heal via switching into.
TO_DO_BATTLE_TEST("TODO: AI uses Z-Moves -- Z-Parting Shot")

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Splash")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_POUND, MOVE_SPLASH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SPLASH, gimmick: GIMMICK_Z_MOVE);
               SCORE_GT_VAL(opponent, MOVE_SPLASH, AI_SCORE_DEFAULT); }
        TURN { EXPECT_MOVE(opponent, MOVE_POUND, gimmick: GIMMICK_NONE);
               SCORE_EQ_VAL(opponent, MOVE_SPLASH, 90); }
    }
}

TO_DO_BATTLE_TEST("TODO: AI uses Z-Moves -- Z-Tailwind")

AI_SINGLE_BATTLE_TEST("AI uses Z-Moves -- Z-Transform")
{
    u32 currentHP, move;
    PARAMETRIZE { currentHP = 1;   move = MOVE_HEADBUTT; }
    PARAMETRIZE { currentHP = 1;   move = MOVE_THUNDERBOLT; }
    PARAMETRIZE { currentHP = 500; move = MOVE_HEADBUTT; }
    PARAMETRIZE { currentHP = 500; move = MOVE_THUNDERBOLT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { Moves(move, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(currentHP); Item(ITEM_NORMALIUM_Z); Moves(MOVE_TRANSFORM); }
    } WHEN {
    if (currentHP == 1 || move == MOVE_THUNDERBOLT)
        TURN { EXPECT_MOVE(opponent, MOVE_TRANSFORM, gimmick: GIMMICK_Z_MOVE); }
    else
        TURN { EXPECT_MOVE(opponent, MOVE_TRANSFORM, gimmick: GIMMICK_NONE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses the best Z-Moves.")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT );
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_SCRATCH, MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEADBUTT, gimmick: GIMMICK_Z_MOVE); }
    }
}

TO_DO_BATTLE_TEST("TODO: AI uses Z-Moves -- Z-Trick Room")
