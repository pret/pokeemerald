#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SHELL_TRAP) == EFFECT_SHELL_TRAP);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveCategory(MOVE_LEER) == DAMAGE_CATEGORY_STATUS);
}

SINGLE_BATTLE_TEST("Shell Trap activates only if hit by a physical move")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = TRUE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; activate = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; activate = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, player);
        MESSAGE("Wobbuffet set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        if (activate) {
            MESSAGE("Wobbuffet used Shell Trap!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Wobbuffet's shell trap didn't work!");
            NONE_OF {
                MESSAGE("Wobbuffet used Shell Trap!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
                HP_BAR(opponent);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Shell Trap does not activate if attacker's Sheer Force applied")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = TRUE; }
    PARAMETRIZE { move = MOVE_STOMP; activate = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, player);
        MESSAGE("Wobbuffet set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (activate) {
            MESSAGE("Wobbuffet used Shell Trap!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Wobbuffet's shell trap didn't work!");
            NONE_OF {
                MESSAGE("Wobbuffet used Shell Trap!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
                HP_BAR(opponent);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Shell Trap does not activate if battler faints before being able to activate it")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, player);
        MESSAGE("Wobbuffet set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet fainted!");
        SEND_IN_MESSAGE("Wobbuffet");
        NONE_OF {
            MESSAGE("Wobbuffet used Shell Trap!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
            HP_BAR(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates immediately after being hit on turn 1 and attacks both opponents")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SHELL_TRAP) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Wobbuffet used Shell Trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wynaut used Celebrate!");
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates immediately after being hit on turn 2 and attacks both opponents")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SHELL_TRAP) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(6); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("The opposing Wynaut used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Wobbuffet used Shell Trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Wobbuffet used Celebrate!");
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates immediately after being hit on turn 3 and attacks both opponents")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SHELL_TRAP) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(7); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(6); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wynaut used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Wobbuffet used Shell Trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Shell Trap targets correctly if one of the opponents has fainted")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SHELL_TRAP) == TARGET_BOTH);
        PLAYER(SPECIES_GRENINJA) { Speed(60); }
        PLAYER(SPECIES_TURTONATOR) { Speed(10); }
        OPPONENT(SPECIES_BLASTOISE) { Speed(120); }
        OPPONENT(SPECIES_SCIZOR) { Speed(100); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
            MOVE(playerRight, MOVE_SHELL_TRAP);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight);
            MOVE(playerRight, MOVE_SHELL_TRAP);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        MESSAGE("The opposing Scizor fainted!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Shell Trap activates if user is hit with a physical move but does no damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, MOVE_FALSE_SWIPE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Encore fails if target has active Shell Trap waiting")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Wobbuffet set a shell trap!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
        }
    }
}

SINGLE_BATTLE_TEST("Shell Trap fails if an other -3 or lower priority Move is used")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_DRAGON_TAIL) <= -3);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SHELL_TRAP);
            MOVE(opponent, MOVE_DRAGON_TAIL);
        }
    } SCENE {
        MESSAGE("Wobbuffet set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, player);
    }
}

DOUBLE_BATTLE_TEST("Shell Trap does not trigger when hit into Substitute")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DOUBLE_EDGE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SUBSTITUTE); }
        TURN {
            MOVE(playerLeft, MOVE_SHELL_TRAP);
            MOVE(opponentLeft, MOVE_DOUBLE_EDGE, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerLeft);
        MESSAGE("Wynaut set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_EDGE, opponentLeft);
        MESSAGE("Wynaut's substitute faded!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates for both opposing targets in speed order")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SHELL_TRAP);
            MOVE(playerRight, MOVE_SHELL_TRAP);
            MOVE(opponentLeft, MOVE_EARTHQUAKE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates immediately after its user is hit by a spread move")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_EARTHQUAKE);
            MOVE(playerRight, MOVE_SHELL_TRAP);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}
