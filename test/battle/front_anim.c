#include "global.h"
#include "test/battle.h"
#include "pokemon_animation.h"

WILD_BATTLE_TEST("Front anims work")
{
    enum Species species = SPECIES_WOBBUFFET;
    for (enum AnimFunctionIDs animId = 0; animId < ANIM_COUNT; animId++)
    {
        for (enum Species tempSpecies = SPECIES_NONE + 1; tempSpecies < NUM_SPECIES; tempSpecies++)
        {
            if (gSpeciesInfo[tempSpecies].frontAnimId == animId)
            {
                PARAMETRIZE { species = tempSpecies; }
                break;
            }
        }
    }
    GIVEN {
        FORCE_MOVE_ANIM(TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Shiny(TRUE); }
    } WHEN {
        TURN { }
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
    }
}
