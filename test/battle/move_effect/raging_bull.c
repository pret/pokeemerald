#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RAGING_BULL) == EFFECT_RAGING_BULL);
    ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
}

SINGLE_BATTLE_TEST("Move Raging Bull changes it's type depending on the Tauros Form")
{
    enum Species speciesPlayer;
    enum Species speciesOpponent;

    PARAMETRIZE { speciesPlayer = SPECIES_TAUROS_PALDEA_COMBAT; speciesOpponent = SPECIES_CHARIZARD; }
    PARAMETRIZE { speciesPlayer = SPECIES_TAUROS_PALDEA_BLAZE; speciesOpponent = SPECIES_BLASTOISE; }
    PARAMETRIZE { speciesPlayer = SPECIES_TAUROS_PALDEA_AQUA; speciesOpponent = SPECIES_VENUSAUR; }

    GIVEN {
        PLAYER(speciesPlayer);
        OPPONENT(speciesOpponent);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGING_BULL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGING_BULL, player);
        HP_BAR(opponent);
        MESSAGE("It's not very effective…");
    }
}
