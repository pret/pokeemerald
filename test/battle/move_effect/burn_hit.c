#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_EMBER].effect == EFFECT_BURN_HIT);
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

#if B_STATUS_TYPE_IMMUNITY > GEN_1
SINGLE_BATTLE_TEST("Scald should burn a Water-type Pokémon")
#else
SINGLE_BATTLE_TEST("Scald shouldn't burn a Water-type Pokémon")
#endif
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SQUIRTLE].types[0] == TYPE_WATER);
        ASSUME(gBattleMoves[MOVE_SCALD].effect == EFFECT_BURN_HIT);
        ASSUME(gBattleMoves[MOVE_SCALD].type == TYPE_WATER);
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
