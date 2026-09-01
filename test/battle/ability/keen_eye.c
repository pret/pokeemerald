#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
    ASSUME_STAT_CHANGE(MOVE_SAND_ATTACK, accuracy: -1);
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye prevent accuracy stage reduction from moves")
{
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        if (species == SPECIES_HITMONCHAN)
            MESSAGE("The opposing Hitmonchan's accuracy was not lowered!");
        else if (species == SPECIES_STARYU)
            MESSAGE("The opposing Staryu's accuracy was not lowered!");
        else
            MESSAGE("The opposing Ursaluna's accuracy was not lowered!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye ignore target's evasion stat")
{
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_TEAM); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_TEAM, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye are ignored by Mold Breaker abilities")
{
    enum Ability abilityPlayer = ABILITY_NONE, abilityOpponent = ABILITY_NONE;
    enum Species speciesPlayer = SPECIES_NONE, speciesOpponent = SPECIES_NONE;

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

    PASSES_RANDOMLY(GetMoveAccuracy(MOVE_SCRATCH) * 3 / 4, 100, RNG_ACCURACY);
    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        PLAYER(speciesPlayer) { Ability(abilityPlayer); }
        OPPONENT(speciesOpponent) { Ability(abilityOpponent); }
    } WHEN {
        TURN { MOVE(player, MOVE_SAND_ATTACK); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, abilityPlayer);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAND_ATTACK, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye don't prevent Topsy-Turvy")
{
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        ASSUME_STAT_CHANGE(MOVE_HONE_CLAWS, attack: +1, accuracy: +1);
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HONE_CLAWS); MOVE(player, MOVE_TOPSY_TURVY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HONE_CLAWS, opponent);
        if (species == SPECIES_HITMONCHAN) {
            MESSAGE("The opposing Hitmonchan's Attack rose!");
            MESSAGE("The opposing Hitmonchan's accuracy rose!");
        } else if (species == SPECIES_STARYU) {
            MESSAGE("The opposing Staryu's Attack rose!");
            MESSAGE("The opposing Staryu's accuracy rose!");
        } else {
            MESSAGE("The opposing Ursaluna's Attack rose!");
            MESSAGE("The opposing Ursaluna's accuracy rose!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        if (species == SPECIES_HITMONCHAN)
            MESSAGE("All stat changes on the opposing Hitmonchan were inverted!");
        else if (species == SPECIES_STARYU)
            MESSAGE("All stat changes on the opposing Staryu were inverted!");
        else
            MESSAGE("All stat changes on the opposing Ursaluna were inverted!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Keen Eye, Gen9+ Illuminate & Minds Eye don't prevent receiving negative Attack stage changes from Baton Pass")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }
    PARAMETRIZE { species = SPECIES_URSALUNA_BLOODMOON; ability = ABILITY_MINDS_EYE; }

    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
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
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { species = SPECIES_HITMONCHAN; ability = ABILITY_KEEN_EYE; }
    PARAMETRIZE { species = SPECIES_STARYU; ability = ABILITY_ILLUMINATE; }

    GIVEN {
        WITH_CONFIG(B_ILLUMINATE_EFFECT, GEN_9);
        ASSUME_STAT_CHANGE(MOVE_HONE_CLAWS, attack: +1, accuracy: +1);
        ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_STEAL_STATS));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HONE_CLAWS); MOVE(player, MOVE_SPECTRAL_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HONE_CLAWS, opponent);
        if (species == SPECIES_HITMONCHAN)
        {
            MESSAGE("The opposing Hitmonchan's Attack rose!");
            MESSAGE("The opposing Hitmonchan's accuracy rose!");
        }
        else
        {
            MESSAGE("The opposing Staryu's Attack rose!");
            MESSAGE("The opposing Staryu's accuracy rose!");
        }
        MESSAGE("Wobbuffet stole the target's boosted stats!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ACC], DEFAULT_STAT_STAGE);
    }
}
