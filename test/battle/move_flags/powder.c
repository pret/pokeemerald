#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Powder moves are blocked by Grass-type Pokémon (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, gen);
        ASSUME(IsPowderMove(MOVE_STUN_SPORE));
        ASSUME(GetSpeciesType(SPECIES_ODDISH, 0) == TYPE_GRASS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        if (gen == GEN_6) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
            MESSAGE("It doesn't affect the opposing Oddish…");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
            NOT MESSAGE("It doesn't affect the opposing Oddish…");
        }
    }
}
