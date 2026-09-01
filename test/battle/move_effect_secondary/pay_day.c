#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectWithChance(MOVE_PAY_DAY, MOVE_EFFECT_PAYDAY, 0) == TRUE);
}

SINGLE_BATTLE_TEST("Pay Day Scatters coins around after it hits - singles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PAY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PAY_DAY, player);
        HP_BAR(opponent);
        MESSAGE("Coins were scattered everywhere!");
    }
}

DOUBLE_BATTLE_TEST("Pay Day Scatters coins around after it hits - doubles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PAY_DAY, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PAY_DAY, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("Coins were scattered everywhere!");
    }
}
