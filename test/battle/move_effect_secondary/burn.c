#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN) == TRUE);
}

SINGLE_BATTLE_TEST("Ember inflicts burn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
        STATUS_ICON(opponent, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Ember cannot burn a Fire-type Pokémon")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CHARMANDER].types[0] == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            STATUS_ICON(opponent, burn: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Lava Plume inflicts burn to all adjacent battlers")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_LAVA_PLUME, MOVE_EFFECT_BURN) == TRUE);
        ASSUME(gMovesInfo[MOVE_LAVA_PLUME].target == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LAVA_PLUME); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LAVA_PLUME, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        STATUS_ICON(opponentLeft, burn: TRUE);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, playerRight);
        STATUS_ICON(playerRight, burn: TRUE);
        HP_BAR(opponentRight);
        STATUS_ICON(opponentRight, burn: TRUE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Matcha Gotcha inflicts burn 20% of the time")
{
    PASSES_RANDOMLY(20, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_BURN) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
        STATUS_ICON(opponent, burn: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Matcha Gatcha can burn both targets")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_BURN) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        STATUS_ICON(opponentLeft, burn: TRUE);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        STATUS_ICON(opponentRight, burn: TRUE);
    }
}

#if B_STATUS_TYPE_IMMUNITY > GEN_1
SINGLE_BATTLE_TEST("Scald should burn a Water-type Pokémon")
#else
SINGLE_BATTLE_TEST("Scald shouldn't burn a Water-type Pokémon")
#endif
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SQUIRTLE].types[0] == TYPE_WATER);
        ASSUME(MoveHasAdditionalEffect(MOVE_SCALD, MOVE_EFFECT_BURN) == TRUE);
        ASSUME(gMovesInfo[MOVE_SCALD].type == TYPE_WATER);
        PLAYER(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_SQUIRTLE);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALD, player);
        HP_BAR(opponent);
        #if B_STATUS_TYPE_IMMUNITY > GEN_1
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            STATUS_ICON(opponent, burn: TRUE);
        #else
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
                STATUS_ICON(opponent, burn: TRUE);
            }
        #endif
    }
}
