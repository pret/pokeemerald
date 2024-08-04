#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Tera Shift transforms Terapagos into its Terastal form on switch in")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL) { Ability(ABILITY_TERA_SHIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TERA_SHIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Terapagos transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_TERAPAGOS_TERASTAL);
    }
}

SINGLE_BATTLE_TEST("Tera Shift can't be suppressed by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL) { Ability(ABILITY_TERA_SHIFT); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(player, ABILITY_TERA_SHIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Terapagos transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_TERAPAGOS_TERASTAL);
    }
}
