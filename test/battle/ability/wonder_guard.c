#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Wonder Guard activates when targeted by moves not super effective against it")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_POUND; }
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    PARAMETRIZE { move = MOVE_THUNDERSHOCK; }
    PARAMETRIZE { move = MOVE_LEAFAGE; }
    PARAMETRIZE { move = MOVE_POWDER_SNOW; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; }
    PARAMETRIZE { move = MOVE_SLUDGE; }
    PARAMETRIZE { move = MOVE_MUD_SLAP; }
    PARAMETRIZE { move = MOVE_CONFUSION; }
    PARAMETRIZE { move = MOVE_BUG_BITE; }
    PARAMETRIZE { move = MOVE_DRAGONBREATH; }
    PARAMETRIZE { move = MOVE_METAL_CLAW; }
    PARAMETRIZE { move = MOVE_FAIRY_WIND; }
    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WONDER_GUARD);
        MESSAGE("It doesn't affect Shedinja…");
    }
}

SINGLE_BATTLE_TEST("Wonder Guard does not activate when targeted by moves super effective against it")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_PECK; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; }
    PARAMETRIZE { move = MOVE_ASTONISH; }
    PARAMETRIZE { move = MOVE_PURSUIT; }
    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Shedinja fainted!");
    }
}
