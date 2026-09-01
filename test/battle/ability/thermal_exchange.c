#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Thermal Exchange makes Will-O-Wisp fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_BAXCALIBUR) { Ability(ABILITY_THERMAL_EXCHANGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
            STATUS_ICON(player, burn: TRUE);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Thermal Exchange prevents the user from getting burned when hitting Flame Body")
{
    GIVEN {
        PLAYER(SPECIES_BAXCALIBUR) { Ability(ABILITY_THERMAL_EXCHANGE); }
        OPPONENT(SPECIES_PONYTA) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
            STATUS_ICON(player, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Thermal Exchange cures burns when acquired")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_BAXCALIBUR) { Ability(ABILITY_THERMAL_EXCHANGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        STATUS_ICON(opponent, burn: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ABILITY_POPUP(opponent, ABILITY_THERMAL_EXCHANGE);
        STATUS_ICON(opponent, burn: FALSE);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Thermal Exchange burn prevention can be bypassed with Mold Breaker but is cured after")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_BAXCALIBUR) { Ability(ABILITY_THERMAL_EXCHANGE); }
        OPPONENT(SPECIES_RAMPARDOS) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
        STATUS_ICON(player, burn: TRUE);
        ABILITY_POPUP(player, ABILITY_THERMAL_EXCHANGE);
        STATUS_ICON(player, burn: FALSE);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Thermal Exchange boosts attack if hit by a damaging fire type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_BAXCALIBUR) { Ability(ABILITY_THERMAL_EXCHANGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
