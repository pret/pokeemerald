#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_DIRE_CLAW, MOVE_EFFECT_RANDOM_FROM_LIST) == TRUE);
}

SINGLE_BATTLE_TEST("Dire Claw can inflict poison, paralysis or sleep")
{
    u8 statusAnim;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; }
    PASSES_RANDOMLY(1, 3, RNG_RANDOM_FROM_LIST);
    GIVEN {
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
        } else if (statusAnim == B_ANIM_STATUS_SLP) {
            STATUS_ICON(opponent, sleep: TRUE);
        } else if (statusAnim == B_ANIM_STATUS_PSN) {
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze poison/electric types respectively")
{
    u8 statusAnim;
    enum Species species;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON; species = SPECIES_ARBOK; }
    GIVEN {
        WITH_CONFIG(B_PARALYZE_ELECTRIC, GEN_6);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_RANDOM_FROM_LIST, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall asleep Pokémon with abilities preventing respective statuses")
{
    u8 statusAnim;
    enum Species species;
    enum Ability ability;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_PERSIAN;  ability = ABILITY_LIMBER; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON;    species = SPECIES_ZANGOOSE; ability = ABILITY_IMMUNITY; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP;     species = SPECIES_VIGOROTH; ability = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP;     species = SPECIES_HYPNO;    ability = ABILITY_INSOMNIA; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_RANDOM_FROM_LIST, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_SLP) {
                STATUS_ICON(opponent, sleep: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall asleep a mon which is already statused")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = MOVE_EFFECT_SLEEP; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_RANDOM_FROM_LIST, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
            if (statusAnim == B_ANIM_STATUS_PRZ) {
                STATUS_ICON(opponent, paralysis: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_SLP) {
                STATUS_ICON(opponent, sleep: TRUE);
            } else if (statusAnim == B_ANIM_STATUS_PSN) {
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}
