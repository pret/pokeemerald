#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_SHEER_COLD].effect == EFFECT_OHKO);
}

SINGLE_BATTLE_TEST("Sheer Cold doesn't affect Ice-type Pokémon")
{
    GIVEN {
        ASSUME(B_SHEER_COLD_IMMUNITY >= GEN_7);
        ASSUME(gSpeciesInfo[SPECIES_GLALIE].types[0] == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        MESSAGE("It doesn't affect Foe Glalie…");
    }
}
TO_DO_BATTLE_TEST("Fissure faints the target, skipping regular damage calculations")
TO_DO_BATTLE_TEST("Fissure always fails if the target has a higher level than the user")
TO_DO_BATTLE_TEST("Fissure's accuracy increases by 1% for every level the user has over the target")
TO_DO_BATTLE_TEST("Fissure's ignores non-stage accuracy modifiers") // Gravity, Wide Lens, Compound Eyes
