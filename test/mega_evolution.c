#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Venusaur can Mega Evolve holding Venusaurite")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, megaEvolve: TRUE); }
    } SCENE {
        MESSAGE("Venusaur's Venusaurite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Venusaur has Mega Evolved into Mega Venusaur!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR_MEGA);
    }
}

SINGLE_BATTLE_TEST("Rayquaza can Mega Evolve knowing Dragon Ascent")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, megaEvolve: TRUE); }
    } SCENE {
        MESSAGE("1's fervent wish has reached Rayquaza!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Rayquaza has Mega Evolved into Mega Rayquaza!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_RAYQUAZA_MEGA);
    }
}

SINGLE_BATTLE_TEST("Mega Evolution affects turn order")
{
    GIVEN {
        ASSUME(B_MEGA_EVO_TURN_ORDER);
        PLAYER(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); Speed(105); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(106); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, megaEvolve: TRUE); }
    } SCENE {
        MESSAGE("Gardevoir used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        ASSUME(player->speed == 205);
    }
}

SINGLE_BATTLE_TEST("Abilities replaced by Mega Evolution do not affect turn order")
{
    GIVEN {
        ASSUME(B_MEGA_EVO_TURN_ORDER);
        ASSUME(gSpeciesInfo[SPECIES_SABLEYE_MEGA].abilities[0] != ABILITY_STALL
            && gSpeciesInfo[SPECIES_SABLEYE_MEGA].abilities[1] != ABILITY_STALL);
        PLAYER(SPECIES_SABLEYE) { Item(ITEM_SABLENITE); Ability(ABILITY_STALL); Speed(105); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(44); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, megaEvolve: TRUE); }
    } SCENE {
        MESSAGE("Sableye used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        ASSUME(player->speed == 45);
    }
}
