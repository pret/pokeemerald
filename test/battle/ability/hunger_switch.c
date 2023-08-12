#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hunger Switch switches Morpeko's forms at the end of the turn")
{
    u16 species;
    PARAMETRIZE { species = SPECIES_MORPEKO; }
    PARAMETRIZE { species = SPECIES_MORPEKO_HANGRY; }
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        PLAYER(species) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Morpeko used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        if (species == SPECIES_MORPEKO)
            EXPECT_EQ(player->species, SPECIES_MORPEKO_HANGRY);
        else
            EXPECT_EQ(player->species, SPECIES_MORPEKO);
    }
}
