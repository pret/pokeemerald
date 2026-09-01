#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Battle Armor and Shell Armor block critical hits")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_KINGLER; ability = ABILITY_SHELL_ARMOR; }
    PARAMETRIZE { species = SPECIES_ARMALDO; ability = ABILITY_BATTLE_ARMOR; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Mold Breaker, Teravolt and Turboblaze ignore Battle Armor and Shell Armor")
{
    u32 j;
    enum Species species1, species2;
    enum Ability ability1, ability2;
    static const u32 breakerData[][2] =
    {
        {SPECIES_PINSIR,   ABILITY_MOLD_BREAKER},
        {SPECIES_ZEKROM,   ABILITY_TERAVOLT},
        {SPECIES_RESHIRAM, ABILITY_TURBOBLAZE},
    };

    for (j = 0; j < ARRAY_COUNT(breakerData); j++)
    {
        PARAMETRIZE { species1 = breakerData[j][0]; ability1 = breakerData[j][1]; species2 = SPECIES_KINGLER; ability2 = ABILITY_SHELL_ARMOR; }
        PARAMETRIZE { species1 = breakerData[j][0]; ability1 = breakerData[j][1]; species2 = SPECIES_ARMALDO; ability2 = ABILITY_BATTLE_ARMOR; }
    }

    GIVEN {
        PLAYER(species1) { Ability(ability1); }
        OPPONENT(species2) { Ability(ability2); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}
