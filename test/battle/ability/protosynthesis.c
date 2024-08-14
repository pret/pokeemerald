#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_ROUND].category == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Protosynthesis boosts the highest stat")
{
    GIVEN {
        PLAYER(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis boosts either Attack or Special Attack, not both")
{
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_ROARING_MOON; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_ROARING_MOON; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_WALKING_WAKE; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_WALKING_WAKE; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_TACKLE && species == SPECIES_ROARING_MOON) || (move == MOVE_ROUND && species == SPECIES_WALKING_WAKE))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis ability pop up activates only once during the duration of sunny day")
{
    u16 turns;

    GIVEN {
        PLAYER(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); };
    } WHEN {
        for (turns = 0; turns < 5; turns++)
            TURN {}
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
        NONE_OF {
            for (turns = 0; turns < 4; turns++) {
                ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
                MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
                MESSAGE("Walking Wake's Sp. Atk was heightened!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ROARING_MOON) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); };
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Roaring Moon's Protosynthesis!");
        MESSAGE("Roaring Moon's Attack was heightened!");
    }
}

TO_DO_BATTLE_TEST("Protosynthesis activates in sun before Booster Energy");
TO_DO_BATTLE_TEST("Protosynthesis activates even if the Pokémon is holding an Utility Umbrella");
TO_DO_BATTLE_TEST("Protosynthesis doesn't activate if Cloud Nine/Air Lock is on the field");
