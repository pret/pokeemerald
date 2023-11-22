#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_THUNDER_FANG].additionalEffects[0].moveEffect == MOVE_EFFECT_PARALYSIS);
    ASSUME(gBattleMoves[MOVE_THUNDER_FANG].additionalEffects[1].moveEffect == MOVE_EFFECT_FLINCH);
    ASSUME(gBattleMoves[MOVE_ICE_FANG].additionalEffects[0].moveEffect == MOVE_EFFECT_FREEZE);
    ASSUME(gBattleMoves[MOVE_ICE_FANG].additionalEffects[1].moveEffect == MOVE_EFFECT_FLINCH);
    ASSUME(gBattleMoves[MOVE_FIRE_FANG].additionalEffects[0].moveEffect == MOVE_EFFECT_BURN);
    ASSUME(gBattleMoves[MOVE_FIRE_FANG].additionalEffects[1].moveEffect == MOVE_EFFECT_FLINCH);
}

SINGLE_BATTLE_TEST("Thunder, Ice and Fire Fang inflict status 10% of the time")
{
    u16 move;

    PARAMETRIZE { move = MOVE_THUNDER_FANG; }
    PARAMETRIZE { move = MOVE_ICE_FANG; }
    PARAMETRIZE { move = MOVE_FIRE_FANG; }

    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_THUNDER_FANG) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        } if (move == MOVE_ICE_FANG) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, opponent);
            STATUS_ICON(opponent, freeze: TRUE);
        } if (move == MOVE_FIRE_FANG) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            STATUS_ICON(opponent, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Thunder, Ice and Fire Fang cause the opponent to flinch 10% of the time")
{
    u16 move;

    PARAMETRIZE { move = MOVE_THUNDER_FANG; }
    PARAMETRIZE { move = MOVE_ICE_FANG; }
    PARAMETRIZE { move = MOVE_FIRE_FANG; }

    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT_2);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet flinched!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
