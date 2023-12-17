#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
    ASSUME(gBattleMoves[MOVE_ROUND].split == SPLIT_SPECIAL);
}

SINGLE_BATTLE_TEST("Protosynthesis boosts the highest stat")
{
    GIVEN {
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Abra's Protosynthesis!");
        MESSAGE("Abra's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis boosts either Attack or Special Attack, not both")
{
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_BELLSPROUT; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_BELLSPROUT; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_ABRA; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_ABRA; move = MOVE_ROUND; }

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
        if ((move == MOVE_TACKLE && species == SPECIES_BELLSPROUT) || (move == MOVE_ROUND && species == SPECIES_ABRA))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis either boosts Defense or Special Defense, not both")
{
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_ONIX; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_ONIX; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_TACKLE && species == SPECIES_ONIX) || (move == MOVE_ROUND && species == SPECIES_BLASTOISE))
            EXPECT_MUL_EQ(damage[0], Q_4_12(0.7), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis ability pop up activates only once during the duration of sunny day")
{
    u16 turns;

    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); };
    } WHEN {
        for (turns = 0; turns < 5; turns++)
            TURN {}
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Bellsprout's Protosynthesis!");
        MESSAGE("Bellsprout's Attack was heightened!");
        NONE_OF {
            for (turns = 0; turns < 4; turns++) {
                ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
                MESSAGE("The harsh sunlight activated Bellsprout's Protosynthesis!");
                MESSAGE("Bellsprout's Attack was heightened!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Bellsprout's Protosynthesis!");
        MESSAGE("Bellsprout's Attack was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates on switch-in")
{
    KNOWN_FAILING; // Fails because of wrong species
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); };
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Bellsprout's Protosynthesis!");
        MESSAGE("Bellsprout's Attack was heightened!");
    }
}
