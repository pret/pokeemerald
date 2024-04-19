#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WATER_GUN].power != 0);
}

SINGLE_BATTLE_TEST("Battle Bond does not transform species other than Greninja")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BATTLE_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet fainted!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_BATTLE_BOND);
            MESSAGE("Wobbuffet became fully charged due to its bond with its trainer!");
        }
    } THEN {
        EXPECT(player->species == SPECIES_WOBBUFFET);
    }
}

// Battle Bond transforms the pokemon when fainting any battler(opposing or partner), unless it's the last pokemon and the battle ends.
SINGLE_BATTLE_TEST("Battle Bond transforms player's Greninja - Singles")
{
    u32 monsCountPlayer, monsCountOpponent;

    PARAMETRIZE {monsCountPlayer = 1; monsCountOpponent = 1; }
    PARAMETRIZE {monsCountPlayer = 1; monsCountOpponent = 2; }
    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 1; }
    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 2; }

    GIVEN {
        PLAYER(SPECIES_GRENINJA_BATTLE_BOND);
        if (monsCountPlayer == 2) {
            PLAYER(SPECIES_WOBBUFFET);
        }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        if (monsCountOpponent == 2) {
            OPPONENT(SPECIES_WOBBUFFET);
        }
    } WHEN {
        if (monsCountOpponent == 2) {
            TURN { MOVE(player, MOVE_WATER_GUN); SEND_OUT(opponent, 1); }
        } else {
            TURN { MOVE(player, MOVE_WATER_GUN); }
        }

    } SCENE {
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet fainted!");
        if (monsCountOpponent != 1) {
            ABILITY_POPUP(player, ABILITY_BATTLE_BOND);
            MESSAGE("Greninja became fully charged due to its bond with its trainer!");
            MESSAGE("Greninja became Ash-Greninja!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_BATTLE_BOND);
                MESSAGE("Greninja became fully charged due to its bond with its trainer!");
            }
        }
    } FINALLY {
        if (monsCountOpponent != 1) {
            EXPECT(player->species == SPECIES_GRENINJA_ASH);
        } else {
            EXPECT(player->species == SPECIES_GRENINJA_BATTLE_BOND);
        }
    }
}

SINGLE_BATTLE_TEST("Battle Bond transforms opponent's Greninja - Singles")
{
    u32 monsCountPlayer, monsCountOpponent;

    PARAMETRIZE {monsCountPlayer = 1; monsCountOpponent = 1; }
    PARAMETRIZE {monsCountPlayer = 1; monsCountOpponent = 2; }
    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 1; }
    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 2; }

    GIVEN {
        OPPONENT(SPECIES_GRENINJA_BATTLE_BOND);
        if (monsCountOpponent == 2) {
            OPPONENT(SPECIES_WOBBUFFET);
        }
        PLAYER(SPECIES_WOBBUFFET) {HP(1); }
        if (monsCountPlayer == 2) {
            PLAYER(SPECIES_WOBBUFFET);
        }
    } WHEN {
        if (monsCountPlayer == 2) {
            TURN { MOVE(opponent, MOVE_WATER_GUN); SEND_OUT(player, 1); }
        } else {
            TURN { MOVE(opponent, MOVE_WATER_GUN); }
        }

    } SCENE {
        HP_BAR(player);
        MESSAGE("Wobbuffet fainted!");
        if (monsCountPlayer != 1) {
            ABILITY_POPUP(opponent, ABILITY_BATTLE_BOND);
            MESSAGE("Foe Greninja became fully charged due to its bond with its trainer!");
            MESSAGE("Foe Greninja became Ash-Greninja!");
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_BATTLE_BOND);
                MESSAGE("Foe Greninja became fully charged due to its bond with its trainer!");
            }
        }
    } FINALLY {
        if (monsCountPlayer != 1) {
            EXPECT(opponent->species == SPECIES_GRENINJA_ASH);
        } else {
            EXPECT(opponent->species == SPECIES_GRENINJA_BATTLE_BOND);
        }
    }
}

DOUBLE_BATTLE_TEST("Battle Bond transforms player's Greninja when fainting its Ally")
{
    u32 monsCountPlayer, monsCountOpponent;

    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 2; }
    PARAMETRIZE {monsCountPlayer = 2; monsCountOpponent = 3; }
    PARAMETRIZE {monsCountPlayer = 3; monsCountOpponent = 2; }
    PARAMETRIZE {monsCountPlayer = 3; monsCountOpponent = 3; }

    GIVEN {
        PLAYER(SPECIES_GRENINJA_BATTLE_BOND);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        if (monsCountPlayer == 3) {
            PLAYER(SPECIES_WOBBUFFET);
        }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        if (monsCountOpponent == 3) {
            OPPONENT(SPECIES_WOBBUFFET);
        }
    } WHEN {
        if (monsCountPlayer == 3) {
            TURN { MOVE(playerLeft, MOVE_WATER_GUN, target:playerRight); SEND_OUT(playerRight, 2); }
        } else {
            TURN { MOVE(playerLeft, MOVE_WATER_GUN, target:playerRight); }
        }

    } SCENE {
        HP_BAR(playerRight);
        MESSAGE("Wobbuffet fainted!");
        ABILITY_POPUP(playerLeft, ABILITY_BATTLE_BOND);
        MESSAGE("Greninja became fully charged due to its bond with its trainer!");
        MESSAGE("Greninja became Ash-Greninja!");
    } FINALLY {
        EXPECT(playerLeft->species == SPECIES_GRENINJA_ASH);
    }
}
