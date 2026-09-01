#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns: Encore used before move (Gen5+)")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 10; speedOpponent = 20; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 20; speedOpponent = 10; }
    GIVEN {
        WITH_CONFIG(B_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreUser, MOVE_CELEBRATE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreUser, MOVE_ENCORE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 4 turns: Encore used after move (Gen5+)")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 20; speedOpponent = 10; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 10; speedOpponent = 20; }
    GIVEN {
        WITH_CONFIG(B_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); MOVE(encoreUser, MOVE_ENCORE); }
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
    }
}

SINGLE_BATTLE_TEST("Encore has no effect if no previous move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Encore overrides the chosen move if it occurs first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Encore forces the last move used before the target flinched")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_3);
        ASSUME(MoveHasAdditionalEffect(MOVE_HEADBUTT, MOVE_EFFECT_FLINCH) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CELEBRATE, MOVE_HEADBUTT, MOVE_ENCORE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_GRASS_KNOT, MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_GRASS_KNOT); }
        TURN { MOVE(player, MOVE_HEADBUTT); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_ENCORE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_KNOT, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_KNOT, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_KNOT, opponent);
    }
}

SINGLE_BATTLE_TEST("Encore forces the last move used while asleep")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_CELEBRATE, MOVE_SPORE, MOVE_ENCORE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_GRASS_KNOT, MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_GRASS_KNOT); }
        TURN { MOVE(player, MOVE_ENCORE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_KNOT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_KNOT, opponent);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Encore")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Max Flare!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be encored immediately after reverting")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }; // yes, this speed is necessary
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ARM_THRUST, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("Wobbuffet used Arm Thrust!");
    }
}

DOUBLE_BATTLE_TEST("Encore works even if the target's last move failed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SUCKER_PUNCH, target: playerRight);
            MOVE(opponentRight, MOVE_SUCKER_PUNCH, target: playerLeft);
            MOVE(playerRight, MOVE_FOLLOW_ME);
            MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentLeft);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentRight);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        MESSAGE("The opposing Wobbuffet must do an encore!");
    }
}

SINGLE_BATTLE_TEST("Encore fails if target has not used any move yet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(3)); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Encore's effect ends if the encored move runs out of PP")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); MovesWithPP({MOVE_SCRATCH, 2}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("Wobbuffet ended its encore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

// NOTE: AI test is required to validate RNG range without MOVE/FORCED_MOVE invalids; there may be a better approach.
AI_SINGLE_BATTLE_TEST("Encore lasts for 2-6 turns (Gen 2-3)")
{
    u32 count, turns;

    PARAMETRIZE { turns = 2; }
    PARAMETRIZE { turns = 3; }
    PARAMETRIZE { turns = 4; }
    PARAMETRIZE { turns = 5; }
    PARAMETRIZE { turns = 6; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(B_ENCORE_TURNS, GEN_3);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ENCORE); }
        for (count = 0; count < turns - 1; ++count)
            TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        for (count = 0; count < turns - 1; ++count)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("The opposing Wobbuffet ended its encore!");
    }
}

AI_SINGLE_BATTLE_TEST("Encore lasts for 3-7 turns (Gen 4)")
{
    u32 count, turns;

    PARAMETRIZE { turns = 3; }
    PARAMETRIZE { turns = 4; }
    PARAMETRIZE { turns = 5; }
    PARAMETRIZE { turns = 6; }
    PARAMETRIZE { turns = 7; }
    PASSES_RANDOMLY(1, 5, RNG_ENCORE_TURNS);
    GIVEN {
        WITH_CONFIG(B_ENCORE_TURNS, GEN_4);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ENCORE); }
        for (count = 0; count < turns - 1; ++count)
            TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        for (count = 0; count < turns - 1; ++count)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("The opposing Wobbuffet ended its encore!");
    }
}

DOUBLE_BATTLE_TEST("Encore randomly chooses an opponent target (Gen 2-4)")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft);
        }
        TURN {
            MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft, WITH_RNG(RNG_RANDOM_TARGET, 1));
            MOVE(playerLeft, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft, target: opponentRight);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Encore allows choosing an opponent target (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_ENCORE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft);
        }
        TURN {
            MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft);
            MOVE(playerLeft, MOVE_TACKLE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft, target: opponentRight);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Encore into Fake Out/First Impression results in Struggle (Champions)")
{
    u32 move;

    PARAMETRIZE { move = MOVE_FAKE_OUT; }
    PARAMETRIZE { move = MOVE_FIRST_IMPRESSION; }

    GIVEN {
        WITH_CONFIG(B_FIRST_TURN_MOVE, GEN_CHAMPIONS);
        ASSUME(gMovesInfo[move].effect == EFFECT_FIRST_TURN_ONLY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_ENCORE); }
        TURN { FORCED_MOVE(player); };
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

DOUBLE_BATTLE_TEST("Encore uses the priority of the selected move on the turn the target is Encored (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_PRIORITY, GEN_9);
        PLAYER(SPECIES_WHIMSICOTT) { Ability(ABILITY_PRANKSTER); Speed(500); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WYNAUT) { Speed(1); };
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
        }
        TURN {
            MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft);
            MOVE(opponentLeft, MOVE_QUICK_ATTACK, target: playerRight);
        }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Encore uses the priority of the Encored move on the turn the target is Encored instead of the selected move (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_PRIORITY, GEN_CHAMPIONS);
        PLAYER(SPECIES_WHIMSICOTT) { Ability(ABILITY_PRANKSTER); Speed(500); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WYNAUT) { Speed(1); };
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
        }
        TURN {
            MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft);
            MOVE(opponentLeft, MOVE_QUICK_ATTACK, target: playerRight);
        }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}
