#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasNoEffectOnSameType(MOVE_SHEER_COLD));
}

SINGLE_BATTLE_TEST("Sheer Cold does affect Ice-type Pokémon (Gen3-6)")
{
    GIVEN {
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_6);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT MESSAGE("It doesn't affect the opposing Glalie…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent, hp: 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Cold doesn't affect Ice-type Pokémon (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        MESSAGE("It doesn't affect the opposing Glalie…");
    }
}

