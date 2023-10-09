#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_POISON_STING].effect == EFFECT_POISON_HIT);
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

SINGLE_BATTLE_TEST("Poison Sting cannot poison Poison-type")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_NIDORAN_M].types[0] == TYPE_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDORAN_M);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}
