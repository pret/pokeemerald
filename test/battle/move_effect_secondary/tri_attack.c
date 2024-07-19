#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_TRI_ATTACK, MOVE_EFFECT_TRI_ATTACK) == TRUE);
}

#if B_USE_FROSTBITE == TRUE
SINGLE_BATTLE_TEST("Tri Attack can inflict paralysis, burn or frostbite")
#else
SINGLE_BATTLE_TEST("Tri Attack can inflict paralysis, burn or freeze")
#endif
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
            FREEZE_OR_FROSTBURN_STATUS(opponent, TRUE);
        } else if (statusAnim == B_ANIM_STATUS_PRZ) {
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

#if B_USE_FROSTBITE == TRUE
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/frostbite electric/fire/ice types respectively")
#else
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze electric/fire/ice types respectively")
#endif
{
    u8 statusAnim;
    u16 species;
    u32 rng;
    #if B_PARALYZE_ELECTRIC >= GEN_6
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; }
    #endif // B_PARALYZE_ELECTRIC
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_ARCANINE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE_OR_FROSTBITE; species = SPECIES_GLALIE; }
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
                FREEZE_OR_FROSTBURN_STATUS(opponent, TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}

#if B_USE_FROSTBITE == TRUE
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/frostbite pokemon with abilities preventing respective statuses")
#else
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze pokemon with abilities preventing respective statuses")
#endif
{
    u8 statusAnim;
    u16 species, ability;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_PERSIAN; ability = ABILITY_LIMBER; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_DEWPIDER; ability = ABILITY_WATER_BUBBLE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_SEAKING; ability = ABILITY_WATER_VEIL; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE_OR_FROSTBITE; species = SPECIES_CAMERUPT; ability = ABILITY_MAGMA_ARMOR; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE_OR_FROSTBITE; species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }

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
                FREEZE_OR_FROSTBURN_STATUS(opponent, TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}

#if B_USE_FROSTBITE == TRUE
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/frostbite a mon which is already statused")
#else
SINGLE_BATTLE_TEST("Tri Attack cannot paralyze/burn/freeze a mon which is already statused")
#endif
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_BRN; rng = MOVE_EFFECT_BURN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_FRZ; rng = MOVE_EFFECT_FREEZE_OR_FROSTBITE; }
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
                FREEZE_OR_FROSTBURN_STATUS(opponent, TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        }
    }
}
