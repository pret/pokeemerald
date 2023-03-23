#include "global.h"
#include "test_battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_DIRE_CLAW].effect == EFFECT_DIRE_CLAW);
}

// found by brute-force
#define RNG_SLEEP 0xcb0
#define RNG_POISON 0x2BE
#define RNG_PARALYSIS 5

SINGLE_BATTLE_TEST("Dire Claw can inflict poison, paralysis or sleep")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = RNG_POISON; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = RNG_SLEEP; }
    GIVEN {
        RNGSeed(rng);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_SLP) {
            STATUS_ICON(opponent, sleep: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze poison/electric types respectively")
{
    u8 statusAnim;
    u16 species;
    u32 rng;
    #if B_PARALYZE_ELECTRIC >= GEN_6
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; species = SPECIES_RAICHU; }
    #endif // B_PARALYZE_ELECTRIC
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = RNG_POISON; species = SPECIES_ARBOK;}
    GIVEN {
        RNGSeed(rng);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall asleep pokemon with abilities preventing respective statuses")
{
    u8 statusAnim;
    u16 species, ability;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; species = SPECIES_RAICHU; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; species = SPECIES_JOLTEON; ability = ABILITY_VOLT_ABSORB; }
    #if P_GEN_4_POKEMON == TRUE
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; species = SPECIES_ELECTIVIRE; ability = ABILITY_MOTOR_DRIVE; }
    #endif // P_GEN_4_POKEMON
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = RNG_POISON; species = SPECIES_ZANGOOSE; ability = ABILITY_IMMUNITY; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = RNG_SLEEP; species = SPECIES_VIGOROTH; ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = RNG_SLEEP; species = SPECIES_HYPNO; ability = ABILITY_INSOMNIA; }

    GIVEN {
        RNGSeed(rng);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) {Ability(ability);}
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_SLP) {
            NOT STATUS_ICON(opponent, sleep: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall asleep a mon which is already statused")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = RNG_POISON; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = RNG_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = RNG_SLEEP; }
    GIVEN {
        RNGSeed(rng);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) {Status1(STATUS1_BURN);}
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_SLP) {
            NOT STATUS_ICON(opponent, sleep: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}
