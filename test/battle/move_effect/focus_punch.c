#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_FOCUS_PUNCH].effect == EFFECT_FOCUS_PUNCH);
}

SINGLE_BATTLE_TEST("Focus Punch activates only if not damaged")
{
    u32 move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_TACKLE; activate = FALSE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; activate = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; activate = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        if (activate) {
            MESSAGE("Wobbuffet used Focus Punch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Wobbuffet lost its focus and couldn't move!");
            NONE_OF {
                MESSAGE("Wobbuffet used Focus Punch!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
                HP_BAR(opponent);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Focus Punch activation is based on Speed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOCUS_PUNCH, target: playerLeft); MOVE(playerRight, MOVE_FOCUS_PUNCH, target: opponentLeft); MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); MOVE(opponentLeft, MOVE_FOCUS_PUNCH, target: playerLeft); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, opponentRight);
        MESSAGE("Foe Wynaut is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerRight);
        MESSAGE("Wynaut is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        MESSAGE("Wobbuffet is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, opponentLeft);
        MESSAGE("Foe Wobbuffet is tightening its focus!");

        MESSAGE("Foe Wynaut used Focus Punch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, opponentRight);
        HP_BAR(playerLeft);

        MESSAGE("Wynaut used Focus Punch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerRight);
        HP_BAR(opponentLeft);

        MESSAGE("Wobbuffet lost its focus and couldn't move!");
        MESSAGE("Foe Wobbuffet lost its focus and couldn't move!");
    }
}
