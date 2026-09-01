#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Disable prevents the target from using a random move (Gen 1)");
TO_DO_BATTLE_TEST("Disable prevents the target from using the last move used (Gen 2+)");
TO_DO_BATTLE_TEST("Disable fails if one of the target's moves is already disabled");
TO_DO_BATTLE_TEST("Disable fails if the target haven't used a move yet (Gen 2+)");
TO_DO_BATTLE_TEST("Disable fails if the last move used was Struggle (Gen 2+)");
TO_DO_BATTLE_TEST("Disable fails if the last move used was a Max Move");
TO_DO_BATTLE_TEST("Disabled moves can still be used via Sleep Talk");
TO_DO_BATTLE_TEST("Disabled moves can still be used via Metronome");
TO_DO_BATTLE_TEST("Disabled moves can still be used via Mirror Move");
TO_DO_BATTLE_TEST("Disable lasts 0-7 turns (Gen 1)");
TO_DO_BATTLE_TEST("Disable lasts 2-8 turns (Gen 2)");
TO_DO_BATTLE_TEST("Disable lasts 2-5 turns (Gen 3)");
TO_DO_BATTLE_TEST("Disable lasts 4-7 turns (Gen 4)");
TO_DO_BATTLE_TEST("Disable lasts 4 turns (Gen 5+)");
TO_DO_BATTLE_TEST("Disable's timer only counts down when trying to use a move (Gen 1-2)");
TO_DO_BATTLE_TEST("Disable's timer counts down regardless of the action (Gen 3+)");
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Disable's effect");

DOUBLE_BATTLE_TEST("Disable works even if the target's last move failed")
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
            MOVE(playerLeft, MOVE_DISABLE, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentLeft);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, opponentRight);
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, playerLeft);
        MESSAGE("The opposing Wobbuffet's Sucker Punch was disabled!");
    }
}
