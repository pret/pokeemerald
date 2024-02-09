#include "global.h"
#include "test/battle.h"


ASSUMPTIONS
{
    ASSUME(MoveIsAffectedBySheerForce(MOVE_ELECTRO_SHOT) == TRUE);
}

SINGLE_BATTLE_TEST("Sheer Force boosts power, but removes secondary effects of moves", s16 damage)
{
    s32 j;
    u32 ability = 0, move = 0;

    for (j = 1; j < MOVES_COUNT; j++)
    {
        if (MoveIsAffectedBySheerForce(j)
          //&& gMovesInfo[j].effect != EFFECT_ORDER_UP
          && gMovesInfo[j].effect != EFFECT_AURA_WHEEL
          && gMovesInfo[j].effect != EFFECT_PLACEHOLDER)
        {
            PARAMETRIZE { ability = ABILITY_ANGER_POINT; move = j; }
            PARAMETRIZE { ability = ABILITY_SHEER_FORCE; move = j; }
        }
    }

    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); Status1(move == MOVE_SNORE ? STATUS1_SLEEP : STATUS1_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponent, MOVE_AGILITY); MOVE(player, move); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponent, MOVE_QUICK_ATTACK); MOVE(player, move); }
        else
            TURN { MOVE(player, move); }
        if (gMovesInfo[move].effect == EFFECT_TWO_TURNS_ATTACK || gMovesInfo[move].effect == EFFECT_SEMI_INVULNERABLE) {
                TURN { SKIP_TURN(player); }
                TURN { ; }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (ability == ABILITY_SHEER_FORCE) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                STATUS_ICON(opponent, STATUS1_FREEZE);
                STATUS_ICON(opponent, STATUS1_POISON);
                STATUS_ICON(opponent, STATUS1_BURN);
                STATUS_ICON(opponent, STATUS1_TOXIC_POISON);
                STATUS_ICON(opponent, STATUS1_PARALYSIS);
                MESSAGE("Wobbuffet is confused!");
                MESSAGE("Wobbuffet flinched!");
            }
            // Volt Tackle/Flare Blitz edge case: recoil happens, but target isn't statused
            if (gMovesInfo[move].recoil > 0)
            {
                HP_BAR(player);
                MESSAGE("Tauros is hit with recoil!");
            }
        }
    } FINALLY {
        s32 j;
        for (j = 0; j < gBattleTestRunnerState->parametersCount; j+=2)
        {
            EXPECT_GT(results[j+1].damage, results[j].damage);
        }
    }
}
