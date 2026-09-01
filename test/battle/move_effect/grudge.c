#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Grudge depletes all PP of the move that fainted the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_GRUDGE);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_EQ(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge does not deplete PP of a Z-Move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_GRUDGE);
            MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE);
            SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponent);
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge depletes all PP from a Max Move's base move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) {  Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); Item(ITEM_LAGGING_TAIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Grudge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        MESSAGE("The opposing Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet lost all of Scratch's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_EQ(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge does not activate for Struggle")
{
    GIVEN {
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_STRUGGLE, MOVE_POUND, MOVE_SURF); };
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_STRUGGLE); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Struggle's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Move")
{
    GIVEN {
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_POUND, MOVE_SURF); };
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Scratch's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Sleep")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(gMovesInfo[SanitizeMoveId(MOVE_SPORE)].argument.nonVolatileStatus == MOVE_EFFECT_SLEEP);
        PLAYER (SPECIES_WOBBUFFET) { HP(1);}
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_VITAL_THROW, MOVE_SPORE, MOVE_SURF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_VITAL_THROW); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        MESSAGE("Wobbuffet fell asleep!");
        STATUS_ICON(player, sleep: TRUE);
        MESSAGE("Wobbuffet is fast asleep.");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VITAL_THROW, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Scratch's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Paralysis")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STUN_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(gMovesInfo[SanitizeMoveId(MOVE_STUN_SPORE)].argument.nonVolatileStatus == MOVE_EFFECT_PARALYSIS);
        ASSUME(GetMovePriority(MOVE_VITAL_THROW) == -1);
        PLAYER (SPECIES_WOBBUFFET) { HP(1);}
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_VITAL_THROW, MOVE_STUN_SPORE, MOVE_SURF); };\
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_STUN_SPORE); }
        TURN { MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_PARALYSIS, TRUE)); MOVE(opponent, MOVE_VITAL_THROW); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, opponent);
        MESSAGE("Wobbuffet is paralyzed, so it may be unable to move!");
        STATUS_ICON(player, paralysis: TRUE);
        MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VITAL_THROW, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Scratch's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect disappears if the user takes a new turn - Flinching")
{
    PASSES_RANDOMLY(10, 100, RNG_HOLD_EFFECT_FLINCH);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_FALSE_SWIPE, MOVE_SURF); Item(ITEM_KINGS_ROCK); }
    }
    WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_GRUDGE); }
        TURN { MOVE(opponent, MOVE_FALSE_SWIPE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    }
    SCENE {
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        MESSAGE("Wobbuffet flinched and couldn't move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Scratch's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Sandstorm")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_SANDSTORM, MOVE_SURF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_SANDSTORM); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANDSTORM, opponent);
        MESSAGE("The sandstorm is raging.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
        MESSAGE("Wobbuffet is buffeted by the sandstorm!");
        NOT MESSAGE("The opposing Wobbuffet lost all of Sandstorm's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Leech Seed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_LEECH_SEED, MOVE_SURF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_GRUDGE); MOVE(opponent, MOVE_LEECH_SEED); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponent);
        MESSAGE("Wobbuffet was seeded!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, player);
        NOT MESSAGE("The opposing Wobbuffet lost all of Leech Seed's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

SINGLE_BATTLE_TEST("Grudge's effect doesn't trigger on indirect damage - Future Sight")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER (SPECIES_WOBBUFFET) { HP(1); }
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_FUTURE_SIGHT, MOVE_SURF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN { MOVE(player, MOVE_GRUDGE); SEND_OUT(player, 1); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, opponent);
        MESSAGE("The opposing Wobbuffet foresaw an attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRUDGE, player);
        MESSAGE("Wobbuffet took the Future Sight attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, opponent);
        NOT MESSAGE("The opposing Wobbuffet lost all of Future Sight's PP due to the grudge!");
        MESSAGE("Wobbuffet fainted!");
    }
    THEN {
        EXPECT_GT(opponent->pp[0], 0);
        EXPECT_GT(opponent->pp[1], 0);
        EXPECT_GT(opponent->pp[2], 0);
        EXPECT_GT(opponent->pp[3], 0);
    }
}

