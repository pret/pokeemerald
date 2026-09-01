#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Tera Shift transforms Terapagos into its Terastal form on switch in")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL) { Ability(ABILITY_TERA_SHIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
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
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TERA_SHIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Terapagos transformed!");
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_TERAPAGOS_TERASTAL);
    }
}

SINGLE_BATTLE_TEST("Tera Shift activates before Neutralizing Gas regardless of Speed")
{
    u32 speed = 0;

    PARAMETRIZE { speed = 50; }
    PARAMETRIZE { speed = 150; }

    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL) { Speed(speed); Ability(ABILITY_TERA_SHIFT); }
        OPPONENT(SPECIES_KOFFING) { Speed(100); Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TERA_SHIFT);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
    }
}
