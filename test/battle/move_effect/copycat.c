#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Copycat causes the user to use the last move used in battle");
TO_DO_BATTLE_TEST("Copycat can call the user's last move used if it was the last move used in battle");
TO_DO_BATTLE_TEST("Copycat fails if no move has been made");
TO_DO_BATTLE_TEST("Copycat chooses a target at random if the copied move wasn't the user's");
TO_DO_BATTLE_TEST("Copycat can copy moves regardless if they failed or not"); //Has "X used move!"
TO_DO_BATTLE_TEST("Copycat fails if the last move used is a Z-Move");

// Gen 4
TO_DO_BATTLE_TEST("Copycat can only copy charging moves after it has been executed (Gen 4)");
TO_DO_BATTLE_TEST("Copycat can only copy recharging moves after it has been executed (Gen 4)");
TO_DO_BATTLE_TEST("Copycat cannot copy Bide's final turn (Gen 4)");
TO_DO_BATTLE_TEST("Copycat copies other calling moves instead of the move they called (Gen 4)");
TO_DO_BATTLE_TEST("Copycat copies moves called by other calling moves instead of the calling move if they are executed in a second turn (Gen 5+)"); //Eg. Dig

// Gen 5+
TO_DO_BATTLE_TEST("Copycat can copy charging moves in both the charging and the executing turn (Gen 5+)");
TO_DO_BATTLE_TEST("Copycat ignores the recharging turn of recharging moves (Gen 5+)");
TO_DO_BATTLE_TEST("Copycat can copy Bide on all turns");
TO_DO_BATTLE_TEST("Copycat copies moves called by other calling moves instead of the calling move (Gen 5+)");

DOUBLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have their base moves copied by Copycat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TRICK_ROOM, gimmick: GIMMICK_DYNAMAX, target: opponentLeft); MOVE(playerRight, MOVE_COPYCAT, target: opponentLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Guard!");
        MESSAGE("Wynaut used Trick Room!");
    }
}
