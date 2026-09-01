#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
}

SINGLE_BATTLE_TEST("Paralysis reduces Speed by 50% (Gen 7+) or 75% (Gen 1-6)")
{
    u32 playerSpeed, genConfig;
    bool32 playerFirst;
    PARAMETRIZE { playerSpeed = 196; playerFirst = FALSE; genConfig = GEN_6; }
    PARAMETRIZE { playerSpeed = 204; playerFirst = TRUE;  genConfig = GEN_6; }
    PARAMETRIZE { playerSpeed = 98;  playerFirst = FALSE; genConfig = GEN_7; }
    PARAMETRIZE { playerSpeed = 102; playerFirst = TRUE;  genConfig = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_PARALYSIS_SPEED, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); Speed(playerSpeed); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (playerFirst) {
            ONE_OF {
                MESSAGE("Wobbuffet used Celebrate!");
                MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
            }
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        } else {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            ONE_OF {
                MESSAGE("Wobbuffet used Celebrate!");
                MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Paralysis has a 1/4 chance of skipping the turn (Gen9-)")
{
    PASSES_RANDOMLY(1, 4, RNG_PARALYSIS);
    GIVEN {
        WITH_CONFIG(B_PARALYSIS_CHANCE, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
    }
}

SINGLE_BATTLE_TEST("Paralysis has a 1/8 chance of skipping the turn (Champions)")
{
    PASSES_RANDOMLY(1, 8, RNG_PARALYSIS);
    GIVEN {
        WITH_CONFIG(B_PARALYSIS_CHANCE, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave doesn't affect Electric types (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_PARALYZE_ELECTRIC, gen);
        ASSUME(GetSpeciesType(SPECIES_PIKACHU, 0) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Wobbuffet used Thunder Wave!");
        if (gen == GEN_6) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
                STATUS_ICON(opponent, paralysis: TRUE);
            }
            MESSAGE("It doesn't affect the opposing Pikachu…");
        } else {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Thunder Wave doesn't print an effectiveness message")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Thunder Wave!");
        NOT MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints an avoided attack message when it misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE, hit: FALSE); }
    } SCENE {
        MESSAGE("Wobbuffet used Thunder Wave!");
        MESSAGE("The opposing Wobbuffet avoided the attack!");
        NOT MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints failure when the target already has a different non-volatile status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Wobbuffet used Thunder Wave!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints already paralyzed message with the right target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Status1(STATUS1_PARALYSIS); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Wobbuffet used Thunder Wave!");
        MESSAGE("The opposing Zigzagoon is already paralyzed!");
        NOT MESSAGE("Wobbuffet is already paralyzed!");
    }
}
