#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
    ASSUME(gBattleMoves[MOVE_ROUND].split == SPLIT_SPECIAL);
}

SINGLE_BATTLE_TEST("Quark Drive boosts the highest stat")
{
    GIVEN {
        PLAYER(SPECIES_ABRA) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Abra's Quark Drive!");
        MESSAGE("Abra's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts either Attack or Special Attack, not both")
{
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_BELLSPROUT; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_BELLSPROUT; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_ABRA; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_ABRA; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_TACKLE && species == SPECIES_BELLSPROUT) || (move == MOVE_ROUND && species == SPECIES_ABRA))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Quark Drive either boosts Defense or Special Defense, not both")
{
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_ONIX; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_ONIX; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_TACKLE && species == SPECIES_ONIX) || (move == MOVE_ROUND && species == SPECIES_BLASTOISE))
            EXPECT_MUL_EQ(damage[0], Q_4_12(0.7), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Quark Drive ability pop up activates only once during the duration of electric terrain")
{
    u16 turns;

    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); }
        for (turns = 0; turns < 4; turns++)
            TURN {}
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Bellsprout's Quark Drive!");
        MESSAGE("Bellsprout's Attack was heightened!");
        NONE_OF {
            for (turns = 0; turns < 4; turns++) {
                ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
                MESSAGE("The Electric Terrain activated Bellsprout's Quark Drive!");
                MESSAGE("Bellsprout's Attack was heightened!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Bellsprout's Quark Drive!");
        MESSAGE("Bellsprout's Attack was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive activates on switch-in")
{
    KNOWN_FAILING; // Fails because of wrong species
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_BELLSPROUT) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Bellsprout's Quark Drive!");
        MESSAGE("Bellsprout's Attack was heightened!");
    }
}
