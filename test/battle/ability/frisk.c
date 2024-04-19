#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Frisk does not trigger when pokemon hold no items")
{
    GIVEN {
        PLAYER(SPECIES_FURRET) { Ability(ABILITY_FRISK); };
        PLAYER(SPECIES_FURRET) { Ability(ABILITY_FRISK); };
        OPPONENT(SPECIES_SENTRET) { Ability(ABILITY_FRISK); };
        OPPONENT(SPECIES_SENTRET) { Ability(ABILITY_FRISK); };
    } WHEN {
        TURN { ; }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_FRISK);
            ABILITY_POPUP(playerRight, ABILITY_FRISK);
            ABILITY_POPUP(opponentLeft, ABILITY_FRISK);
            ABILITY_POPUP(opponentRight, ABILITY_FRISK);
        }
    }
}

SINGLE_BATTLE_TEST("Frisk triggers in a Single Battle")
{
    GIVEN {
        PLAYER(SPECIES_FURRET) { Ability(ABILITY_FRISK); Item(ITEM_POTION); };
        OPPONENT(SPECIES_SENTRET) { Ability(ABILITY_FRISK); Item(ITEM_POTION); };
    } WHEN {
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FRISK);
        MESSAGE("Furret frisked Foe Sentret and found its Potion!");
        ABILITY_POPUP(opponent, ABILITY_FRISK);
        MESSAGE("Foe Sentret frisked Furret and found its Potion!");
    }
}

DOUBLE_BATTLE_TEST("Frisk triggers for player in a Double Battle after switching-in after fainting")
{
    bool32 targetLeft;
    PARAMETRIZE { targetLeft = TRUE; }
    PARAMETRIZE { targetLeft = FALSE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_POUND].power != 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_FURRET) { Ability(ABILITY_FRISK); };
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_POUND, target: targetLeft ? playerLeft : playerRight); SEND_OUT(targetLeft ? playerLeft : playerRight, 2); }
    } SCENE {
        MESSAGE("Foe Wynaut used Pound!");
        MESSAGE("Wobbuffet fainted!");
        ABILITY_POPUP(targetLeft ? playerLeft : playerRight, ABILITY_FRISK);
        MESSAGE("Furret frisked Foe Wynaut and found its Potion!");
    }
}

DOUBLE_BATTLE_TEST("Frisk triggers for opponent in a Double Battle after switching-in after fainting")
{
    bool32 targetLeft;
    PARAMETRIZE { targetLeft = TRUE; }
    PARAMETRIZE { targetLeft = FALSE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_POUND].power != 0);
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_POTION); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_FURRET) { Ability(ABILITY_FRISK); };
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POUND, target: targetLeft ? opponentLeft : opponentRight); SEND_OUT(targetLeft ? opponentLeft : opponentRight, 2); }
    } SCENE {
        MESSAGE("Wynaut used Pound!");
        MESSAGE("Foe Wobbuffet fainted!");
        ABILITY_POPUP(targetLeft ? opponentLeft : opponentRight, ABILITY_FRISK);
        MESSAGE("Foe Furret frisked Wynaut and found its Potion!");
    }
}
