#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
}

SINGLE_BATTLE_TEST("Toxic inflicts bad poison")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Toxic can't bad poison a poison or steel type")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_BELDUM; }
    PARAMETRIZE { species = SPECIES_BULBASAUR; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Toxic cannot miss if used by a Poison-type (Gen6+)")
{
    enum Species species;
    u32 gen;
    bool32 hit;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; hit = FALSE; gen = GEN_5; }
    PARAMETRIZE { species = SPECIES_NIDORAN_M; hit = FALSE; gen = GEN_5; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; hit = FALSE; gen = GEN_6; }
    PARAMETRIZE { species = SPECIES_NIDORAN_M; hit = TRUE;  gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_TOXIC_NEVER_MISS, gen);
        ASSUME(GetSpeciesType(SPECIES_NIDORAN_M, 0) == TYPE_POISON);
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC, hit: FALSE); }
    } SCENE {
        if (hit) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, badPoison: TRUE);
            }
        }
    }
}
