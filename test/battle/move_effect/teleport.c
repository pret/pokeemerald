#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
}

SINGLE_BATTLE_TEST("Teleport fails to switch out when there is no Pokémon to switch in (Gen 8+)")
{
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEPORT); }
    } SCENE {
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Teleport fails to switch out the user when there no alive Pokémon left (Gen 8+)")
{
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEPORT); }
    } SCENE {
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Teleport fails in Trainer Battles (Gen 1-7)")
{
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEPORT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teleport!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEPORT, opponent);
            MESSAGE("2 sent out Wynaut!");
        }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Teleport forces the Pokémon to switch out in Trainer Battles (Gen 8+)")
{
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEPORT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEPORT, opponent);
        MESSAGE("2 sent out Wynaut!");
    }
}

SINGLE_BATTLE_TEST("Teleport does not fail if the user is trapped")
{
    GIVEN {
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_SPIN); MOVE(opponent, MOVE_TELEPORT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_SPIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEPORT, opponent);
        MESSAGE("2 sent out Wynaut!");
    }
}
