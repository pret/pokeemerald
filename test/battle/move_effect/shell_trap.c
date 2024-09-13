#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SHELL_TRAP].effect == EFFECT_SHELL_TRAP);
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_WATER_GUN].category == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(gMovesInfo[MOVE_LEER].category == DAMAGE_CATEGORY_STATUS);
}

SINGLE_BATTLE_TEST("Shell Trap activates only if hit by a physical move")
{
    u32 move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_TACKLE; activate = TRUE; }
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
    u32 move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_TACKLE; activate = TRUE; }
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
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, player);
        MESSAGE("Wobbuffet set a shell trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
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
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        MESSAGE("Wobbuffet used Shell Trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wynaut used Celebrate!");
    }
}

DOUBLE_BATTLE_TEST("Shell Trap activates immediately after being hit on turn 2 and attacks both opponents")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(6); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("Foe Wynaut used Celebrate!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
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
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(7); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(6); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        MESSAGE("Wobbuffet set a shell trap!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wynaut used Celebrate!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        MESSAGE("Wobbuffet used Shell Trap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Shell Trap targets correctly if one of the opponents has fainted")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_GRENINJA) { Speed(60); }
        PLAYER(SPECIES_TURTONATOR) { Speed(10); }
        OPPONENT(SPECIES_BLASTOISE) { Speed(120); }
        OPPONENT(SPECIES_SCIZOR) { Speed(100); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_TACKLE, target: playerRight);
            MOVE(playerRight, MOVE_SHELL_TRAP);
        }
        TURN {
            MOVE(opponentLeft, MOVE_TACKLE, target: playerRight);
            MOVE(playerRight, MOVE_SHELL_TRAP);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        MESSAGE("Foe Scizor fainted!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
    }
}
