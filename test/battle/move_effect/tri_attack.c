#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TRI_ATTACK].effect == EFFECT_TRI_ATTACK);
}

SINGLE_BATTLE_TEST("Tri Attack can inflict paralysis, burn or freeze")
{
    u8 statusAnim;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; }
    PASSES_RANDOMLY(1, 3, RNG_TRI_ATTACK);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRI_ATTACK); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_BRN) {
            STATUS_ICON(opponent, burn: TRUE);
        } else if (statusAnim == B_ANIM_STATUS_FRZ) {
            STATUS_ICON(opponent, freeze: TRUE);
        } else if (statusAnim == B_ANIM_STATUS_PRZ) {
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze electric/fire/ice types respectively")
{
    u8 statusAnim;
    u16 species;
    u32 rng;
    #if B_PARALYZE_ELECTRIC >= GEN_6
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; }
    #endif // B_PARALYZE_ELECTRIC
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_ARCANINE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE; species = SPECIES_GLALIE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TRI_ATTACK, WITH_RNG(RNG_TRI_ATTACK, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_BRN) {
                STATUS_ICON(opponent, burn: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_FRZ) {
                STATUS_ICON(opponent, freeze: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze pokemon with abilities preventing respective statuses")
{
    u8 statusAnim;
    u16 species, ability;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_JOLTEON; ability = ABILITY_VOLT_ABSORB; }
    #if P_GEN_4_POKEMON == TRUE
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_ELECTIVIRE; ability = ABILITY_MOTOR_DRIVE; }
    #endif // P_GEN_4_POKEMON
    #if P_GEN_7_POKEMON == TRUE
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_DEWPIDER; ability = ABILITY_WATER_BUBBLE; }
    #endif // P_GEN_7_POKEMON
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_SEAKING; ability = ABILITY_WATER_VEIL; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE; species = SPECIES_CAMERUPT; ability = ABILITY_MAGMA_ARMOR; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRI_ATTACK, WITH_RNG(RNG_TRI_ATTACK, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_BRN) {
                STATUS_ICON(opponent, burn: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_FRZ) {
                STATUS_ICON(opponent, freeze: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze a mon which is already statused")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRI_ATTACK, WITH_RNG(RNG_TRI_ATTACK, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_BRN) {
                STATUS_ICON(opponent, burn: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_FRZ) {
                STATUS_ICON(opponent, freeze: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}
