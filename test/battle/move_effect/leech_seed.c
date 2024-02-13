#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_LEECH_SEED].effect == EFFECT_LEECH_SEED);
}

SINGLE_BATTLE_TEST("Leech Seed doesn't affect Grass-type Pokémon")
{
    PASSES_RANDOMLY(90, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_ODDISH].types[0] == TYPE_GRASS);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        MESSAGE("It doesn't affect Foe Oddish…");
    }
}
TO_DO_BATTLE_TEST("Leech Seed doesn't affect already seeded targets")
TO_DO_BATTLE_TEST("Leech Seeded targets lose 1/8 of its max HP every turn and give it to the user")
TO_DO_BATTLE_TEST("Leech Seed's effect is paused until a new battler replaces the original user's position") // Faint, can't be replaced, then revived.
TO_DO_BATTLE_TEST("Leech Seed's effect pause still prevents it from being seeded again")
