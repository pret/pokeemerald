#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_POISON_STING].effect == EFFECT_POISON_HIT);
    ASSUME(gBattleMoves[MOVE_TWINEEDLE].effect == EFFECT_POISON_HIT);
}

SINGLE_BATTLE_TEST("Poison Sting inflicts poison")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Poison cannot be inflicted on Poison and Steel-type Pokémon")
{
    u32 mon;
    PARAMETRIZE { mon = SPECIES_NIDORAN_M; }
    PARAMETRIZE { mon = SPECIES_REGISTEEL; }
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_NIDORAN_M].types[0] == TYPE_POISON);
        ASSUME(gSpeciesInfo[SPECIES_REGISTEEL].types[0] == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon);
    } WHEN {
        TURN { MOVE(player, MOVE_TWINEEDLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TWINEEDLE, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}
