#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].accuracy == 100);
    ASSUME(gMovesInfo[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
    ASSUME(B_ILLUMINATE_EFFECT >= GEN_9);
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye prevent accuracy stage reduction from moves")
{
    u16 ability;
    u32 species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        if (species == SPECIES_HITMONCHAN)
            MESSAGE("Foe Hitmonchan's Keen Eye prevents accuracy loss!");
        else if (species == SPECIES_STARYU)
            MESSAGE("Foe Staryu's Illuminate prevents accuracy loss!");
        else
            MESSAGE("Foe Ursaluna's Mind's Eye prevents accuracy loss!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye ignore target's evasion stat")
{
    u16 ability;
    u32 species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOUBLE_TEAM].effect == EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_TEAM); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_TEAM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye are ignored by Mold Breaker abilities")
{
    u16 abilityPlayer = ABILITY_NONE, abilityOpponent = ABILITY_NONE;
    u16 speciesPlayer = SPECIES_NONE, speciesOpponent = SPECIES_NONE;

    u32 j;
    static const u16 moldBreakerAbilities[][2] = {
        {SPECIES_PINSIR,   ABILITY_MOLD_BREAKER},
        {SPECIES_RESHIRAM, ABILITY_TURBOBLAZE},
        {SPECIES_ZEKROM,   ABILITY_TERAVOLT},
    };

    for (j = 0; j < ARRAY_COUNT(moldBreakerAbilities); j++) {
        speciesPlayer = moldBreakerAbilities[j][0]; abilityPlayer = moldBreakerAbilities[j][1];
        PARAMETRIZE { speciesOpponent = SPECIES_HITMONCHAN; abilityOpponent = ABILITY_KEEN_EYE; }
        PARAMETRIZE { speciesOpponent = SPECIES_STARYU; abilityOpponent = ABILITY_ILLUMINATE; }
        PARAMETRIZE { speciesOpponent = SPECIES_URSALUNA_BLOODMOON; abilityOpponent = ABILITY_MINDS_EYE; }
    }

    PASSES_RANDOMLY(gMovesInfo[MOVE_TACKLE].accuracy * 3 / 4, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(speciesPlayer) { Ability(abilityPlayer); }
        OPPONENT(speciesOpponent) { Ability(abilityOpponent); }
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, abilityPlayer);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAND_ATTACK, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye don't prevent Topsy-Turvy")
{
    u16 ability;
    u32 species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_HONE_CLAWS].effect == EFFECT_ATTACK_ACCURACY_UP);
        ASSUME(gMovesInfo[MOVE_TOPSY_TURVY].effect == EFFECT_TOPSY_TURVY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HONE_CLAWS); MOVE(player, MOVE_TOPSY_TURVY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HONE_CLAWS, opponent);
        if (species == SPECIES_HITMONCHAN) {
            MESSAGE("Foe Hitmonchan's Attack rose!");
            MESSAGE("Foe Hitmonchan's accuracy rose!");
        } else if (species == SPECIES_STARYU) {
            MESSAGE("Foe Staryu's Attack rose!");
            MESSAGE("Foe Staryu's accuracy rose!");
        } else {
            MESSAGE("Foe Ursaluna's Attack rose!");
            MESSAGE("Foe Ursaluna's accuracy rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        if (species == SPECIES_HITMONCHAN)
            MESSAGE("Foe Hitmonchan's stat changes were all reversed!");
        else if (species == SPECIES_STARYU)
            MESSAGE("Foe Staryu's stat changes were all reversed!");
        else
            MESSAGE("Foe Ursaluna's stat changes were all reversed!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye don't prevent receiving negative Attack stage changes from Baton Pass")
{
    u16 ability;
    u32 species;
    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK);
               MOVE(opponent, MOVE_BATON_PASS);
               SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAND_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        if (species == SPECIES_HITMONCHAN)
            MESSAGE("2 sent out Hitmonchan!");
        else if (species == SPECIES_STARYU)
            MESSAGE("2 sent out Staryu!");
        else
            MESSAGE("2 sent out Ursaluna!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Keen Eye & Gen9+ Illuminate don't prevent Spectral Thief from resetting positive accuracy stage changes")
{
    u16 ability;
    u32 species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_HONE_CLAWS].effect == EFFECT_ATTACK_ACCURACY_UP);
        ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_SPECTRAL_THIEF) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HONE_CLAWS); MOVE(player, MOVE_SPECTRAL_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HONE_CLAWS, opponent);
        if (species == SPECIES_HITMONCHAN)
        {
            MESSAGE("Foe Hitmonchan's Attack rose!");
            MESSAGE("Foe Hitmonchan's accuracy rose!");
        }
        else
        {
            MESSAGE("Foe Staryu's Attack rose!");
            MESSAGE("Foe Staryu's accuracy rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
        MESSAGE("Wobbuffet stole the target's boosted stats!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE);
    }
}
